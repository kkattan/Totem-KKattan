```
                                                       ▀▀▀▀▀     ▀▀▀▀▀          ▀▀█▀▀
                                                       ▄▀▀▀▄  ▄  ▄▀▀▀▄  ▄  ▄▀▀▀▄  █  ▄▀▀▀▄
                                                       █   █  █  █   █  █  █   █  █  █   █
                                                        ▀▀▀   █   ▀▀▀   █   ▀▀▀   ▀   ▀▀▀
                                                              █      ▄▄▄█▄▄▄    █   █  
                                                              ▀      █  █  █     █▄█
                                                            ▀▀▀▀▀    █  █  █      ▀
                                                                     ▀  ▀  ▀
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
       
```
# TOTEM split keyboard

TOTEM is 38 keys column-staggered split keyboard made by @geigeigeist. It uses the Seeed XIAO RP2040.

You can use this command to compile the firmware

# QMK + Vial Setup (Windows 11, QMK MSYS)

## 🛠️ Fresh Install Steps

### 1. Install QMK Toolbox & MSYS
- Download QMK Toolbox from: [ttps://qmk.fm/toolbox](https://qmk.fm/toolbox)
- Download from: [https://github.com/qmk/qmk_distro_msys/releases](https://github.com/qmk/qmk_distro_msys/releases)
- Install with default options.

### 2. Open QMK MSYS
- Launch **QMK MSYS** from Start Menu.
- Verify it runs:
  ```bash
  # Start the MinGW 64-bit shell from the QMK MSYS Start Menu item, then:
  pacman -Syu
  # If pacman asks to close/reopen the shell, close and reopen the same "QMK MSYS MinGW 64-bit" shell.
  pacman -Su
  qmk --version
  ```

### 3. Set up QMK firmware

- Clone QMK firmware with submodules:
    
    `qmk setup`
       

### 4. Setup QMK VIAL
- Clone vial:
	```bash
	cd $HOME
	git clone https://github.com/vial-kb/vial-qmk.git
	cd vial-qmk
	```  

### 5. Install dependencies (pacman)

- MSYS2 Python is **externally managed**. Use pacman instead of pip:
    
```bash
pacman -S --needed \
    mingw-w64-x86_64-python \
    mingw-w64-x86_64-python-pip \
    mingw-w64-x86_64-python-pillow \
    mingw-w64-x86_64-python-jsonschema \
    mingw-w64-x86_64-python-setuptools \
    mingw-w64-x86_64-python-wheel \
    mingw-w64-x86_64-python-pyusb
```

Optional (only if newer python than 3.12 is installed), remove newer Python PATH:
`export PATH=$(echo "$PATH" | sed 's|:/c/Users/$USER/AppData/Local/Programs/Python/Python313/Scripts||')
`
- Setup vial:
  ```bash
	pip install --upgrade pip setuptools wheel
	pip install -r requirements.txt
  ```

- Setup vial from within virtual environment:
  ```bash
	python3 -m venv .venv
	source .venv/bin/activate
	pip install --upgrade pip setuptools wheel
	pip install -r requirements.txt
  ```

### 6. Add your keyboard (Totem + Vial fork)

- Copy the `momro-vial` keyboard directory into:
    
    `vial-qmk/keyboards/totem`
    

### 7. Enable features in `rules.mk`

Inside your keymap folder (example: `keyboards/totem/keymaps/vial/rules.mk`):

```
VIA_ENABLE = yes VIAL_ENABLE = yes 
# Remove once you're done experimenting: 
VIAL_INSECURE = yes  
CAPS_WORD_ENABLE = yes 
CHORDAL_HOLD_ENABLE = yes  
TAP_DANCE_ENABLE = yes 
COMBO_ENABLE = yes 
KEY_OVERRIDE_ENABLE = yes 
MOUSEKEY_ENABLE = yes 
BOOTMAGIC_ENABLE = yes 
LEADER_ENABLE = yes 
SPLIT_KEYBOARD = yes
```

Optional but recommended:

`NO_FLASH = yes   # Prevents auto-flash hanging, lets you copy UF2 manually`

### 8. Configure options in `config.h`

Inside `keyboards/totem/keymaps/vial/config.h`:

```
#pragma once  
// Vial UID (must be unique!) 
#define VIAL_KEYBOARD_UID { 0xCB, 0x37, 0x36, 0xFE, 0xEE, 0xED, 0xEE, 0x77 }  
// Unlock combo (required when not in insecure mode) 
#define VIAL_UNLOCK_COMBO_ROWS { 0, 4 } 
#define VIAL_UNLOCK_COMBO_COLS { 0, 0 }  
// Feature tuning #define CAPS_WORD_IDLE_TIMEOUT 3000   
// 3s #define CAPS_WORD_TOGGLE_KEY 
#define TAPPING_TERM 200 
#define ONESHOT_TIMEOUT 500
```

❌ **Do not re-define** `CHORDAL_HOLD` or `CAPS_WORD_INVERT_ON_SHIFT` in `config.h`  
✅ They are enabled via `rules.mk`

### 9. Build firmware

Compile each half separately to load later:
```bash
make totem:vial:uf2-split-right
# ctrl-c to not bootload.
mv .build/totem_vial.uf2 .build/totem_vial_right.uf2
make totem:vial:uf2-split-left
# ctrl-c to not bootload.
mv .build/totem_vial.uf2 .build/totem_vial_left.uf2
```

Compile without flashing:

`make totem:vial:all`

Find firmware outputs in:

`vial-qmk/.build/`

For Totem split:

- `totem_vial_left.uf2`
    
- `totem_vial_right.uf2`
    

### 10. Flash manually

- Put each half into bootloader mode.
    
- Copy the correct UF2 file onto the USB drive that appears.

## 🔒 Secure Mode (recommended after setup)

When you’re done testing:

1. Remove or comment out:
    
    `VIAL_INSECURE = yes`
    
    from `rules.mk`.
    
2. Recompile & flash again:
    
    `make totem:vial:all`
    

Now only your **unlock combo** will allow editing the keymap in Vial.

---

## 📝 Notes

- To leave a virtual environment:
  `deactivate`
- If you see:
    
    `#pragma message "Building Vial-enabled firmware in insecure mode."`
    
    → That’s expected when `VIAL_INSECURE = yes`.
    
- To check your environment:
    
    `qmk doctor`
    
- UF2 flashing hangs (`Waiting for drive to deploy…`) can be avoided with:
    
    `NO_FLASH = yes`
    
    in `rules.mk`.
