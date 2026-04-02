#!/usr/bin/env bash
set -euo pipefail

# ============================================================
# QMK repo setup and syncing
# ============================================================

# Add the official QMK repo as upstream, then fetch it.
git remote add upstream https://github.com/qmk/qmk_firmware.git
git fetch upstream

# Update local master to match upstream/master.
git checkout master
git merge --ff-only upstream/master

# Make submodules match the superproject after the update.
git submodule sync --recursive
git submodule update --init --recursive

# Rebase your working branch onto the latest upstream/master.
git checkout erikdab
git fetch upstream
git rebase upstream/master
git submodule sync --recursive
git submodule update --init --recursive

# This will push your rebased branch to your fork, but only if it can be fast-forwarded.
git push --force-with-lease origin erikdab

# ============================================================
# QMK compile and flash
# ============================================================

# Compile the Helix rev3 keymap.
qmk compile -kb helix/rev3 -km erikdab

# Flash using DFU bootloader.
qmk flash -kb helix/rev3 -km erikdab -bl dfu

# ============================================================
# Convert keymap.c to JSON for diagram tooling
# ============================================================

# Generate a JSON keymap from the QMK keymap.
qmk c2json -kb helix/rev3 -km erikdab > ~/keymap.json

# Optional: verbose version if you need to debug c2json.
qmk --verbose c2json -kb helix/rev3 -km erikdab

# ============================================================
# Install keymap-drawer
# ============================================================

# Install uv with Homebrew.
brew install uv

# Install keymap-drawer in an isolated tool environment.
uv tool install keymap-drawer

# Check that the keymap CLI is available.
keymap --help

# ============================================================
# Generate cheatsheet files from the JSON keymap
# ============================================================

# Parse the QMK JSON into keymap-drawer YAML, with explicit layer names.
keymap parse -q ~/keymap.json -c 12 --layer-names GAME UTIL FUNC SWAP > ~/keymap.yaml

# Draw the SVG cheatsheet from the YAML.
keymap draw ~/keymap.yaml > ~/keymap.svg

# Open the SVG on macOS.
open ~/keymap.svg

# ============================================================
# Optional: convert SVG cheatsheet to PNG on macOS
# ============================================================

# Option A: install librsvg and convert SVG -> PNG
brew install librsvg
rsvg-convert ~/keymap.svg -o ~/keymap.png

# Option B: install CairoSVG via uv and convert SVG -> PNG
uv tool install cairosvg
cairosvg ~/keymap.svg -o ~/keymap.png

# Open the PNG on macOS.
open ~/keymap.png