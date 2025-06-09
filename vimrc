filetype indent off
nnoremap <leader><space> :nohlsearch<CR>
syntax on

set autoindent
set confirm "Allows you to save the file on :q
set expandtab "Makes tabs equal to 4 spaces
set ignorecase "Ignore case when searching
set incsearch "Show results when searching
set hlsearch "Highlight search until new you perform a new search
set foldmethod=manual "Makes folding (zf) manual
set noshowmatch "Do not move cursor to matching ([{ when typing
set noswapfile "Prevents the creation of the .swp file
set number "Show line numbers
"set pastetoggle=<F10> "Used for accurate pasting
set showcmd "I have no idea what this does
set softtabstop=4
set spell spelllang=en_us "Spellcheck will be in US English
set tabstop=4 "Tabs are the size of 4 spaces
"set nowrap "Makes long lines one line instead of wrapping the text
set linebreak "Lines break at full words instead of the middle

let $PAGER=""

noremap <C-h> <C-w>h
noremap <C-l> <C-w>l
noremap <C-j> <C-w>j
noremap <C-k> <C-w>k
noremap > <C-w>>
noremap < <C-w><
noremap m <C-w>+
noremap M <C-w>-
noremap s 1g~<right>
noremap S viwg~
noremap W :w
noremap <C-S> :w <return>
"noremap <C-S> :%s/	/    /g<return>
noremap <C-n> :next <return>
noremap <C-p> :previous <return>
noremap <C-N> :w <return>:next <return>
noremap <C-P> :w <return>:previous <return>

noremap <F3> :w<return>:!copy-to-clipboard % <return>
noremap <F4> :!wc -w % <return>
noremap <S-F5> :w<return>:!clear && make <return>
noremap <F5> :w<return>:!clear && make -B<return>
noremap <F6> :w<return>:!clear && make -j<return>:!./main <return>
noremap <F7> :!./main<return>
noremap <S-F7> :!clear;./main<return>
noremap <F8> :w<return>:!clear; pdflatex -shell-escape %; pdflatex -shell-escape %;clean-latex<return>
"noremap <F8> :w<return>:!clear; xelatex %; xelatex %; clean-latex<return>
noremap <F9> :w<return>:!clear; octave-cli %<return>
noremap <F10> :w<return>:!clear; python3 %<return>

highlight Comment ctermfg=DarkCyan

highlight String ctermfg=DarkRed
highlight Character ctermfg=DarkRed
highlight Number ctermfg=Blue
highlight Boolean ctermfg=DarkRed
highlight Float ctermfg=DarkRed

highlight Function ctermfg=White

highlight Conditional ctermfg=Magenta
highlight Repeat ctermfg=DarkMagenta
highlight Label ctermfg=White
highlight Operator ctermfg=White
highlight Keyword ctermfg=White
highlight Extension ctermfg=White

highlight PreProc ctermfg=DarkGreen
highlight Include ctermfg=DarkGreen
highlight Define ctermfg=DarkGreen
highlight Macro ctermfg=DarkGreen
highlight PreCondit ctermfg=DarkGreen

"*Type=
highlight StorageClass ctermfg=Red
"StorageClass=
"Structure=
"Typedef=

"*Special=
highlight SpecialChar ctermfg=DarkGreen
highlight Tag ctermfg=DarkRed
highlight Delimiter ctermfg=DarkRed
"SpecialComment=
"Debug=

" Disable spellcheck
autocmd BufRead,BufNewFile *.c,*.cpp,*.cxx,*.h,*.hpp,*.html,*.js,*.py set nospell

