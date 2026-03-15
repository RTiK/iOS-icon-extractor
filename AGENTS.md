# Extract iOS Icons

Guide the user through extracting icons from their iPhone home screen screenshots. Follow each step in order, waiting for user confirmation before proceeding.

> **Device compatibility**: Icon positions are currently calibrated for **iPhone 16 Pro running iOS 26** only. If the user has a different device or OS version, the tool will likely extract the wrong pixels. Warn the user of this at the start.

## Step 1 — Prepare the iPhone

Tell the user to do the following on their iPhone **before** taking any screenshots:

1. **Disable Parallax**: Go to `Settings > Accessibility > Motion > Reduce Motion` and enable it. This prevents icons from shifting position.
2. **Clear all notification badges**: Make sure no icon has a red notification bubble — it will appear on the extracted icon.

Ask the user to confirm they have completed both steps before continuing.

## Step 2 — Take screenshots and transfer them to the computer

Tell the user to:
1. Take a screenshot of **each home screen page** they want to extract icons from.
2. When the screenshot thumbnail appears in the corner, tap it and choose **Save to Files** — this ensures the file is saved in the expected PNG format.
3. Transfer all screenshots to this computer (via AirDrop, cable, iCloud, etc.).

Ask the user to provide the paths to the screenshot files once they are on the computer.

## Step 3 — Extract icons from each page

For **each screenshot file** the user provided, do the following in order:

1. Ask: "How many icons are on page N (not counting the dock)?"
2. Ask: "Where should the extracted icons be saved? (e.g. `icons/page_N/`)"
3. Run the extraction tool from the `build/` directory, passing `-d 0` to skip dock icons for now:
   ```sh
   ./iOS-icon-extractor -n <num_icons> -d 0 -o <output_dir> <path/to/screenshot.png>
   ```
4. Tell the user where the icons were saved and confirm they look correct before moving to the next page.

## Step 4 — Extract dock icons (optional)

Ask the user: "Would you like to extract the dock icons as well?"

If yes:
1. Ask: "How many icons are in your dock?" (1–4; their positions shift based on count, so this must be accurate)
2. Ask: "Which screenshot should be used? (any page works since the dock appears on all of them)"
3. Ask: "Where should the extracted dock icons be saved? (e.g. `icons/dock/`)"
4. Run, passing `-n 0` to skip page icons:
   ```sh
   ./iOS-icon-extractor -n 0 -d <num_dock> -o <output_dir> <path/to/screenshot.png>
   ```

## Step 5 — Done

Tell the user where all the extracted icon files are saved and confirm the process is complete.
