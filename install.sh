#!/bin/bash

normal=$(tput sgr0)
bold=$(tput bold)

red=$(tput setaf 1)
grn=$(tput setaf 2)
ylw=$(tput setaf 3)
gry=$(tput setaf 8)

CONFIG_DIR=$HOME/.config
DOWNLOAD_DIR=$HOME/Downloads

printf "${gry}%s${normal}\n${bold}${grn}%s${normal}\n${ylw}%s${normal}\n${gry}%s${normal}\n\n" "

███████╗██╗   ██╗███████╗██████╗ ███████╗ ██████╗ ██████╗ ███████╗███████╗████████╗
██╔════╝██║   ██║██╔════╝██╔══██╗██╔════╝██╔═══██╗██╔══██╗██╔════╝██╔════╝╚══██╔══╝
█████╗  ██║   ██║█████╗  ██████╔╝█████╗  ██║   ██║██████╔╝█████╗  ███████╗   ██║   
██╔══╝  ╚██╗ ██╔╝██╔══╝  ██╔══██╗██╔══╝  ██║   ██║██╔══██╗██╔══╝  ╚════██║   ██║   
███████╗ ╚████╔╝ ███████╗██║  ██║██║     ╚██████╔╝██║  ██║███████╗███████║   ██║   
╚══════╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝   ╚═╝   

" \
	"EVERFOREST THEME FOR ARCH LINUX Version 1.0" \
	"Author: Arfan Zubi" \
	"License: 2023 GNU General Public License"

# Installer
function install() {
	# Checking if ~/.config already exists and wipe it if it does
	if [[ -d "$CONFIG_DIR" ]]; then
		echo "${ylw}$CONFIG_DIR does already exist, deleting all files...${normal}"
		rm -rfv "$CONFIG_DIR"
	fi

	# Creating new empty ~/.config
	echo "${ylw}Creating new $CONFIG_DIR directory...${normal}"
	mkdir -p "$CONFIG_DIR" || {
		echo "${bold}${red}Failed creating ${CONFIG_DIR}, exiting...${normal}"
		exit 1
	}
	echo "${ylw}Done!${normal}"

	# Refreshing XDG user directories
	echo "${ylw}Creating XDG user directories...${normal}"
	xdg-user-dirs-update || {
		echo "${bold}${red}Failed creating XDG user directories, exiting...${normal}"
		exit 1
	}
	echo "${ylw}Done!${normal}"

	# Checking if dotfiles are in Downloads directory
	if [[ -d $DOWNLOAD_DIR/dotfiles ]]; then

		# Removing .git directory so it won't get copied unnecessary
		echo "${ylw}Removing .git directory...${normal}"
		rm -rf .git || {
			echo "${bold}${red}Failed removing .git directory, exiting...${normal}"
			exit 1
		}
		echo "${ylw}Done!${normal}"

		# Copying dotfiles from Downloads folder to ~/.config
		echo "${ylw}Copying files from ${DOWNLOAD_DIR} to ${CONFIG_DIR}...${normal}"
		cp -Rfv "$DOWNLOAD_DIR/dotfiles/." "$CONFIG_DIR" || {
			echo "${bold}${red}Failed copying files from ${DOWNLOAD_DIR} to ${CONFIG_DIR}, exiting...${normal}"
			exit 1
		}
		echo "${ylw}Done!${normal}"

		# Copying files which target destinations are not in ~/.config
		echo "${ylw}Copying files to other directories${normal}"
		sudo cp -Rfv "$DOWNLOAD_DIR/dotfiles/Xorg/." "/etc/X11/xorg.conf.d"
		if [[ ! -d "$HOME/.local/share/rofi" ]]; then
			mkdir -p "$HOME/.local/share/rofi/themes"
			cp -Rfv "$DOWNLOAD_DIR/dotfiles/rofi/squared-everforest.rasi" "$HOME/.local/share/rofi/themes/squared-everforest.rasi"
		fi
		cp -Rfv "$DOWNLOAD_DIR/dotfiles/Xorg/.xinitrc" "$HOME/.xinitrc"
		cp -Rfv "$DOWNLOAD_DIR/dotfiles/zsh/.zshrc" "$HOME/.zshrc"
		echo "${ylw}Done!${normal}"

		cd "$CONFIG_DIR" || exit 1
		echo "${ylw}Changed directory to $(pwd)${normal}"

		echo "${ylw}Removing some unnecessary files...${normal}"
		rm -rfv asus Xorg urxvt lf i3/i3status screenshot-20221230-145517Z-all.png nvim/init.vim nvim/coc-settings.json install.sh zsh || {
			echo "${bold}${red}Failed removing directories not needed for the configuration, exiting..."
			exit 1
		}
		echo "${ylw}Done!${normal}"

		echo "${ylw}Installing shell tools${normal}"
		git clone --depth 1 https://github.com/wbthomason/packer.nvim "$HOME/.local/share/nvim/site/pack/packer/start/packer.nvim"
		git clone https://github.com/zsh-users/zsh-autosuggestions "$HOME/.zsh/zsh-autosuggestions"
		git clone https://github.com/zsh-users/zsh-syntax-highlighting.git "$HOME/.zsh/zsh-syntax-highlighting"
		git clone https://github.com/alexanderjeurissen/ranger_devicons "$CONFIG_DIR/ranger/plugins/ranger_devicons"

		sudo git clone https://github.com/sebastiencs/icons-in-terminal.git "/usr/share/icons-in-terminal"

		if [[ -d /usr/share/icons-in-terminal ]]; then
			cd "/usr/share/icons-in-terminal" || {
				echo "${bold}${red}Could not find icons-in-terminal directory inside /usr/share directory${normal}"
			}
			/usr/share/icons-in-terminal/install.sh
		fi
		echo "${ylw}Done!${normal}"

	else
		echo "${bold}${red}Make sure you cloned (https://github.com/3rfaan/dotfiles.git) into your ~/Downloads folder!${normal}"
		exit 1
	fi
}

# Removing install files after moving them to .config
function rm_install_file() {
	if [[ -d $DOWNLOAD_DIR/dotfiles ]]; then
		echo "${ylw}Removing installation files...${normal}"
		rm -rf "$DOWNLOAD_DIR/dotfiles"
	fi
}

while true; do
	echo -e "${bold}${red}===> This installer will delete ALL files in your ~/.config directory.${normal}"
	read -r -p "${ylw}Do you want to proceed? [y/N] ${normal}" yn

	case $yn in
	[Yy]*)
		install
		rm_install_file

		echo "${bold}${grn}Installation succeeded! Exiting...${normal}"
		exit 0
		;;
	[Nn]* | "")
		echo "${bold}${red}Aborting installation...${normal}"
		exit 1
		;;
	*) echo "Please enter [y]es or [n]o!" ;;
	esac
done
