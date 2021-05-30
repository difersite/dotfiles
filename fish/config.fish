#
# Configuracion de fish
#

# Config
set EDITOR "nvim"

# Inicio de programas
neofetch

### funciones personalizadas ###
# Line counting
function line-count
    wc -l | string trim
end


### Abreviaciones ###
abbr df 'df -h'
abbr .. 'cd ..'
abbr home 'cd ~'
