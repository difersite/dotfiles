# Autor: Diego Ferruz
# Fecha: Agosto 24

## alias
## filemanager
alias lf='exa -fhl --icons'
alias ld='exa -Dhl --icons'
alias la='exa -hla --icons --group-directories-first'
alias vi='nvim'
alias font='fc-list' ## Lista de fuentas


alias rr='ranger --choosedir=$HOME/.rangerdir; LASTDIR=`cat $HOME/.rangerdir`;cd "$LASTDIR"'

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
