"REFERENCIAS Y TIPS
"1. Configuraciones:
"	https://github.com/eduarQuintero/my_init.vim/blob/master/init.vim
"	https://github.com/3rfaan/dotfiles/blob/main/vim/init.vim
"
"2.Para poder instalar los Plugin primero seguir las instrucciones en:
"	https://github.com/junegunn/vim-plug
" En Linux
" sh -c 'curl -fLo "${XDG_DATA_HOME:-$HOME/.local/share}"/nvim/site/autoload/plug.vim --create-dirs \
"       https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'
"	En Windows para pwsh (Power shell) Copiar y ejecutar el siguiente comando:
"	iwr -useb https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim |`
"	     ni "$(@($env:XDG_DATA_HOME, $env:LOCALAPPDATA)[$null -eq $env:XDG_DATA_HOME])/nvim-data/site/autoload/plug.vim" -Force
"
" Una vez ejecurado los comandos sh o iwr segun el sistema operativo, abrir init.vim dentro del directorio de configuracion
" en windows es $HOME/AppData/Local/nvim (C:\Users\dferruzr\AppData\Local\nvim) 
" en Linux es $HOME/.conf/nvim (/home/dferruz/.config/nvim) - Ojo cambiar el directorio de la configuracion mas abajo -- call plug#begin('~/.config/nvim/plugged').
" y luego ejecutar :PlugInstall
"" ===============================================================================
" CONFIGURACIONES BASICAS
set number 				"muestra los numeros de cada linea en la parte izquierda 
set relativenumber 			"la distribucion de los numeros en lineas de manera relativa
set mouse=a 				"permite la interaccion con el mouse
set noshowmode				"me deja de mostrar el modo en el que estamos 'normal, insert, visual, etc'
syntax enable 				"activa el coloreado de sintaxis en algunos tipos de archivos como html, c, c++
set encoding=utf-8 			"permite setear la codificación de archivos para aceptar caracteres especiales
set sw=4 				"la indentación genera 4 espacios
set nowrap				"el texto en una linea no baja a la siguiente, solo continua en la misma hasta el infinito.
"set noswapfile				"para evitar el mensaje que sale al abrir algunos archivos sobre swap.
set clipboard=unnamed			"para poder utilizar el portapapeles del sistema operativo 'esto permite poder copiar y pegar desde cualquier parte a nvim y viceversa.	
set cursorline				"Highlight cursor line
set cursorcolumn			"Highlight column line


" CONFIGURACION DEL TEMA
set termguicolors
" colorscheme onedark
"===============================================================================

":::instalacion de plugins:::

call plug#begin('~/.config/nvim/plugged')	"directorio donde se van a instalar los plugins

"plugins
Plug 'joshdick/onedark.vim' 		"tema
Plug 'Yggdroot/indentLine' 		"indentacion
Plug 'mattn/emmet-vim' 			"emmet para diseño web
Plug 'vim-airline/vim-airline'		"diseño de la barra en la cual se muestran los modos, la linea, etc.
Plug 'vim-airline/vim-airline-themes'	"temas para el vim-airline
Plug 'preservim/nerdtree'		"gestor de archivos en forma de arbol.
Plug 'christoomey/vim-tmux-navigator'	"poder navegar entre archivos abiertos
Plug 'jiangmiao/auto-pairs'		"autocompletado de llaves, corchetes, etc.
Plug 'neoclide/coc.nvim', {'branch': 'release'}	"autocompletado inteligente

call plug#end() 			"cerramos el llamado de los plugins
"============================================================================

"configuracion de nerdtree
"mapeando el abrir y cerrar de nerdtree con nerdtreetoggle vemos los archivos en el arbol y podemos cerrarlo a la vez, map es la C mayuscula representa el
"control y -n la tecla n lo que indica que realizará la siguiente funcion de excribir el comando NERDTreeToggle y CR significa ENTER.
map <C-n> :NERDTreeToggle<CR>


