#############################################################
### TITULO: myConfig
### AUTHR: dferruz
### DATE: AGO 24
#############################################################
## Terminal App
## =============
## fzf -> Find
## ncdu -> Disk used
## exa -> best ls 
## Pandoc
## cmatrix
## htop/gtop
## ranger
## nvim
## neofetch
## jp2a -> jpg 2 ascii

## alias
## filemanager
alias lf='exa -fhl --icons'
alias ld='exa -Dhl --icons'
alias la='exa -hla --icons --group-directories-first'
alias vi='nvim'
alias ..='cd ..'
alias gcfg='cd ~/.config'
alias gdoc='cd ~/Documentos'
alias gdwn='cd ~/Downloads'
alias gpic='cd ~/Picture'

## Ranger
alias rr='ranger --choosedir=$HOME/.rangerdir; LASTDIR=`cat $HOME/.rangerdir`;cd "$LASTDIR"'

## Other
alias font='fc-list | awk -F: '{print $2}' | sort |uniq '

#
# Prompt Appeariance
#

# setopt PROMPT_SUBST
## PROMPT="(%B%F{34}%n%f%b)(%B%F{8}%d%f%b)>"
## RPROMPT="(%B%F{34}%n%f%b)(%B%F{8}%d%f%b)>"

# w/starship
eval "$(starship init zsh)"
neofetch
startx

#############################################################
### REFERENCIAS
#############################################################
## Tech Craft        -  https://youtu.be/2OHrTQVlRMg
## TechHut           -  https://youtu.be/cKqsw_sAsU8
## Brodie Robertson  -  https://youtu.be/jFOso1s6PAI
##
