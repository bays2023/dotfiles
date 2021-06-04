syntax on
set tabstop=4
set number
set showcmd
filetype indent on
set showmatch
nnoremap <leader><space> :nohlsearch<CR>
set spell spelllang=en_us
set nosm
set incsearch
set ignorecase
set pastetoggle=<F10>

ab vect std::vector<int>
ab itn int
ab jstick sf::Joystick

call plug#begin('~/.vim/plugged')

Plug 'https://github.com/junegunn/vim-github-dashboard.git'
Plug 'https://github.com/frazrepo/vim-rainbow.git'
"Plug 'git@github.com:Valloric/YouCompleteMe.git'

call plug#end()

au FileType c,cpp,objc,objcpp,java,py,js,html,css call rainbow#load()

