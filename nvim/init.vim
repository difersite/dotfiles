" TITULO: init.vim
" VERSION: 02
" FECHA: 05 jun 2022
" AUTOR: DIEGO FERRUZ
" DETALLES: nueva configuracion basada en el curso de nvim de Astrodev - https://www.youtube.com/watch?v=nC6I4XbvK3g
" Se agregan plugins basado en recomendaciones de hola mundo https://www.youtube.com/watch?v=XgQFzi3VkC8
" ____________________________________________________________________
"
" Fundamentals
" ---------------------------------------------------------------------

syntax on

set number                      " Muestra numeros
set numberwidth=1               " espaciados entre los numeros y el texto
set rnu                         " Numeros relativos
set sw=2                        " tabulador de dos espacios
set nowrap                      " no wrap
set smartindent                 " indentacion automatica
set expandtab
set cursorline                  " destaca donde esta el cursor
set ignorecase                  " para las busquedas da lo mismo si es mayuscula o minuscula
set showmatch

set mouse=a                     " activa el mouse - importante para copy y paste
set clipboard=unnamedplus       " activa la copia al portapapeles
set termguicolors               " aplica colores

set colorcolumn=120             " Inculye una linea 
highlight ColoColumn ctermbg=0 guibg=lightgrey

" Pluggins
" ---------------------------------------------------------------------

call plug#begin('~/.local/share/nvim/plugged')

  " themes
  Plug 'morhetz/gruvbox'
  Plug 'ayu-theme/ayu-vim'
  Plug 'joshdick/onedark.vim'
  "Plug 'shinchu/lightline-gruvbox.vim'

  "status bar
  Plug 'maximbaz/lightline-ale'
  Plug 'itchyny/lightline.vim'

  "nerd tree
  Plug 'scrooloose/nerdtree'

  "typing
  Plug 'jiangmiao/auto-pairs'
  Plug 'alvan/vim-closetag'
  Plug 'tpope/vim-surround'

  "autocomplete
  "Plug 'sirver/ultisnips'
  Plug 'neoclide/coc.nvim',{'branch': 'release'}

call plug#end()


" Themes
" ---------------------------------------------------------------------

set background=dark
let ayucolor="dark"
let g:gruvbox_cotrast_dark="hard" 

colorscheme gruvbox 

" MAPs Teclas
" ---------------------------------------------------------------------

nnoremap <Leader>nt :NERDTree<CR>
