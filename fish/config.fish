# TITULO: Configuracion de fish
# VERSION: 02.02
# FECHA: 20 AGOSTO 2021
# AUTOR: Diego Ferruz
# DETALLE: Basado en varias configuraciones: http://github.com/linuxdabbler 
# y algunas abreviaturas de Distrotube - https://gitlab.com/dwt1/dotfiles/-/blob/master/.config/fish/config.fish
# 02. Agrego alguas abreviaciones wifistatus y programas utiles comoncdu

# Config
set fish_greeting "Bienvenido a Fish"
set -gx TERM xterm-256color
set EDITOR "nvim"

# Theme
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

# cat to bat
abbr cat 'bat'

#####################
### Abreviaciones ###
#####################

## directorios
abbr home 'cd ~dferruz'
abbr tmp 'cd ~/Z5-Temp'
abbr cfg 'cd ~/.config'
abbr doc 'cd ~/D1-Document'

## navigation
alias ..='cd ..'
alias ...='cd ../..'
alias .3='cd ../../..'
alias .4='cd ../../../..'
alias .5='cd ../../../../..'

## Listar archivos - "ls" to "exa"
abbr ls 'exa -l --icons --color=always --group-directories-first'    ## por defecto
abbr ll 'exa -l --icons --tree --level=1'                            ## formato detallado
abbr la 'exa -la --icons --tree --level=1 --group-directories-first' ## completo

# pacman update
alias pacsyu='sudo pacman -Syyu'                             ## update only standard pkgs

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

# Networking
alias wifistatus='nmcli dev wifi list'

# Used Program
# fish, neofetch, exa, cmatrix
# pandoc - converter markdown to pdf,html,etc... 
# figlet -banner en command (http://www.figlet.org/figlet-man.html)
# ncdu - programas de mayor tamaño
# tmux - multiplexer term (en Arch - yay repo)
