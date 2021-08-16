#
# Configuracion de fish
#

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

### Abreviaciones ###
abbr df 'df -h'
abbr .. 'cd ..'
abbr home 'cd ~dferruz'
abbr tmp 'cd ~/Z5-Temp'
abbr cfg 'cd ~/.config'
abbr doc 'cd ~/D1-Document'
abbr ll 'exa -l --icons --tree --level=1'
abbr la 'exa -la --icons --tree --level=1 | sort' ## | awk '{print NR " " $0}'i
command -qv nvim && alias vim nvim
