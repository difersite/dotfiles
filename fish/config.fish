# TITULO: Configuracion de fish
# VERSION: 02
# FECHA: 16 AGOSTO 2021
# AUTOR: Diego Ferruz
# DETALLE: Basado en varias configuraciones: http://github.com/linuxdabbler 
# y algunas abreviaturas de Distrotube - https://gitlab.com/dwt1/dotfiles/-/blob/master/.config/fish/config.fish

# Config
set fish_greeting "Bienvenido a Fish"
set -gx TERM xterm-256color
set EDITOR "nvim"

# theme
set -g theme_color_scheme terminal-dark
set -g fish_prompt_pwd_dir_length 1
set -g theme_display_user yes
set -g theme_hide_hostname no
set -g theme_hostname always

# Inicio de programas
neofetch

### funciones personalizadas ###
# Line counting
function line-count
    wc -l | string trim
end

function cnt
  seq 15
end 

#################################
### Reemplazo de Aplicaciones ###
#################################

# vim to nvim
command -qv nvim && alias vim nvim

# cat 2 bat
alias cat='bat'

#####################
### Abreviaciones ###
#####################

## directorios
abbr home 'cd ~dferruz'
abbr tmp 'cd ~/Z5-Temp'
abbr cfg 'cd ~/.config'
abbr doc 'cd ~/D1-Document'

## navigation
abbr ..='cd ..'
abbr ...='cd ../..'
abbr .3='cd ../../..'
abbr .4='cd ../../../..'
abbr .5='cd ../../../../..'

## Listar archivos - "ls" to "exa"
abbr ls='exa -al --color=always --group-directories-first'  ## por defecto
abbr ll 'exa -l --icons --tree --level=1'                   ## formato detallado
abbr la 'exa -la --icons --tree --level=1 | sort'           ## | awk '{print NR " " $0}'i

# pacman update
abbr pacsyu='sudo pacman -Syyu'                             ## update only standard pkgs

# confirm before overwriting something
alias cp="cp -i"
alias mv='mv -i'
alias rm='rm -i'

# add flags
alias df='df -h'                                            ## human-readable sizes
alias free='free -m'                                        ## show sizes in MB

## get top process eating memory
alias psmem='ps auxf | sort -nr -k 4'
alias psmem10='ps auxf | sort -nr -k 4 | head -10'

## get top process eating cpu ##
alias pscpu='ps auxf | sort -nr -k 3'
alias pscpu10='ps auxf | sort -nr -k 3 | head -10'

# git
alias addup='git add -u'
alias addall='git add .'
alias branch='git branch'
alias checkout='git checkout'
alias clone='git clone'
alias commit='git commit -m'
alias fetch='git fetch'
alias pull='git pull origin'
alias push='git push origin'
alias tag='git tag'
alias newtag='git tag -a'


####################################
## OTHER -- Configuracion de dwt1 ##
####################################

# bat
# alias cat='bat'

# pacman and yay
#alias pacsyu='sudo pacman -Syyu'                 # update only standard pkgs
#alias yaysua='yay -Sua --noconfirm'              # update only AUR pkgs (yay)
#alias yaysyu='yay -Syu --noconfirm'              # update standard pkgs and AUR pkgs (yay)
#alias parsua='paru -Sua --noconfirm'             # update only AUR pkgs (paru)
#alias parsyu='paru -Syu --noconfirm'             # update standard pkgs and AUR pkgs (paru)
#alias unlock='sudo rm /var/lib/pacman/db.lck'    # remove pacman lock
#alias cleanup='sudo pacman -Rns (pacman -Qtdq)'  # remove orphaned packages

# alias ls='exa -al --color=always --group-directories-first' # my preferred listing
# alias la='exa -a --color=always --group-directories-first'  # all files and dirs
# alias ll='exa -l --color=always --group-directories-first'  # long format
# alias lt='exa -aT --color=always --group-directories-first' # tree listing
# alias l.='exa -a | egrep "^\."'

# get fastest mirrors
# alias mirror="sudo reflector -f 30 -l 30 --number 10 --verbose --save /etc/pacman.d/mirrorlist"
# alias mirrord="sudo reflector --latest 50 --number 20 --sort delay --save /etc/pacman.d/mirrorlist"
# alias mirrors="sudo reflector --latest 50 --number 20 --sort score --save /etc/pacman.d/mirrorlist"
# alias mirrora="sudo reflector --latest 50 --number 20 --sort age --save /etc/pacman.d/mirrorlist"

# Colorize grep output (good for log files)
# alias grep='grep --color=auto'
# alias egrep='egrep --color=auto'
# alias fgrep='fgrep --color=auto'

# confirm before overwriting something
# alias cp="cp -i"
# alias mv='mv -i'
# alias rm='rm -i'

# adding flags
# alias df='df -h'                          # human-readable sizes
# alias free='free -m'                      # show sizes in MB
# alias lynx='lynx -cfg=~/.lynx/lynx.cfg -lss=~/.lynx/lynx.lss -vikeys'
# alias vifm='./.config/vifm/scripts/vifmrun'
# alias ncmpcpp='ncmpcpp ncmpcpp_directory=$HOME/.config/ncmpcpp/'
# alias mocp='mocp -M "$XDG_CONFIG_HOME"/moc -O MOCDir="$XDG_CONFIG_HOME"/moc'

## get top process eating memory
# alias psmem='ps auxf | sort -nr -k 4'
# alias psmem10='ps auxf | sort -nr -k 4 | head -10'

## get top process eating cpu ##
# alias pscpu='ps auxf | sort -nr -k 3'
# alias pscpu10='ps auxf | sort -nr -k 3 | head -10'

# Merge Xresources
# alias merge='xrdb -merge ~/.Xresources'

# git
# alias addup='git add -u'
# alias addall='git add .'
# alias branch='git branch'
# alias checkout='git checkout'
# alias clone='git clone'
# alias commit='git commit -m'
# alias fetch='git fetch'
# alias pull='git pull origin'
# alias push='git push origin'
# alias tag='git tag'
# alias newtag='git tag -a'

# get error messages from journalctl
# alias jctl="journalctl -p 3 -xb"

# gpg encryption
# verify signature for isos
# alias gpg-check="gpg2 --keyserver-options auto-key-retrieve --verify"
# receive the key of a developer
# alias gpg-retrieve="gpg2 --keyserver-options auto-key-retrieve --receive-keys"

# youtube-dl
# alias yta-aac="youtube-dl --extract-audio --audio-format aac "
# alias yta-best="youtube-dl --extract-audio --audio-format best "
# alias yta-flac="youtube-dl --extract-audio --audio-format flac "
# alias yta-m4a="youtube-dl --extract-audio --audio-format m4a "
# alias yta-mp3="youtube-dl --extract-audio --audio-format mp3 "
# alias yta-opus="youtube-dl --extract-audio --audio-format opus "
# alias yta-vorbis="youtube-dl --extract-audio --audio-format vorbis "
# alias yta-wav="youtube-dl --extract-audio --audio-format wav "
# alias ytv-best="youtube-dl -f bestvideo+bestaudio "

# switch between shells
# I do not recommend switching default SHELL from bash.
# alias tobash="sudo chsh $USER -s /bin/bash && echo 'Now log out.'"
# alias tozsh="sudo chsh $USER -s /bin/zsh && echo 'Now log out.'"
# alias tofish="sudo chsh $USER -s /bin/fish && echo 'Now log out.'"

# bare git repo alias for dotfiles
# alias config="/usr/bin/git --git-dir=$HOME/dotfiles --work-tree=$HOME"

# termbin
# alias tb="nc termbin.com 9999"

# the terminal rickroll
# alias rr='curl -s -L https://raw.githubusercontent.com/keroserene/rickrollrc/master/roll.sh | bash'

# Unlock LBRY tips
# alias tips="lbrynet txo spend --type=support --is_not_my_input --blocking"

# Thinkorswim
# alias tos="~/thinkorswim/thinkorswim"

# force all kakoune windows into one session
# alias kak="/usr/bin/kak -c mysession"
# alias kaks="/usr/bin/kak -s mysession"
# alias kakd="/usr/bin/kak -d -s mysession &"

### RANDOM COLOR SCRIPT ###
# Get this script from my GitLab: gitlab.com/dwt1/shell-color-scripts
# Or install it from the Arch User Repository: shell-color-scripts
# colorscript random

### SETTING THE STARSHIP PROMPT ###
# starship init fish | source

