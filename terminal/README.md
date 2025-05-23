---
Titulo: Terminal
Version: 1.0
Fecha: 23-10-2023
Autor: Diego Ferruz
Descripcion: Implementacion de programas y configuraciones dentro de un terminal
---
<!-- Comentarios internos aca -->
# Terminal
Primero probamos conectividad y vemos hacemos un update del sistema
puede ser que tenamos que resincronizar los certificados, para lo cual haceos:  
```
pacman-key --init
pacman-key --populate
archlinux-keyring-wkd-sync
pacman -Syyu
```
Si al momento de instalar no se creo una cuenta de usario, es hora de hacerlo
```
$ useradd -m -g users -G wheel,storage,power,video,audio <your username>
$ passwd <your username> <your password>
```
Luego comentamos sudoers
si no esta instalado sudo, lo instalamos
```
pacman -S sudo
```
en Debian esto seria:
Primero necesitas entrar como root
```
apt-get install sudo
```
luego para generar el usuario y agregarlo al gurpo sudo pueder proceder de la siguiente forma:
```
$ useradd -m -g users <your username> ## no hemos agtregado grupos en este caso
$ usermod -aG sudo <your username> ## aca agregamos el nuevo usuario al grupo sudo
$ visudo ## con este comeando editamos con nano el archivo sudoer que se encuentra en /etc/sudoers
```
Luego descomentamos comentamos
%wheel ALL=(ALL) NOPASSWD: ALL  
En el archivo /etc/sudoers

Previo a cualquier proceso de implementacion, hacemos un listado de software instalados
```
sudo pacman -Qq >> Fechav1SoftwareList.md
sudo pacman -Qqe >> Fechav1ShortSoftwareList.md
```
-Qqe despliega los software independientes, es decir, no muestra los paquetes que son dependientes de otros software

Ahora partimos con Git, para bajar script y configuraciones
```
sudo pacman -S git
```
Luego generamos la configuracion de Directorios
- Documentos
  Estructura clasica de documentos.
  - A1-INTERNOS
  - B1-FINANZAS
  - C1-OPERACIONES
  - D1-COMERCIAL
  - E1-MARKETING
  - F1-PRODUCTOS
  - G1-SERVICIOS
  - M1-PROYECTOS
  - T1-INFO
  - X1-CURSOS
  - Z1-OTHR
  - Z9-TEMP
- Desarrollo
  dividido por carpetas de proyectos de desarrollo, mas que por lenguaje. En la carpeta contenedora del proyecto ira el tipo de lenguaje a utilizar.
- Plataforma
  Configuracion de Sistemas Operativos
- Respaldos
  Respaldo de informacion de otros computadores y cuentas
- SIV
  Sonido, Imagenes y Video.
  las cuales no se van a dividir en estas 3 carpetas sino que en categorias, por ejemplo, Imagenes o videos o sonidos de mi blog personal, por lo que existira una carpeta dferruz

Desde aca partimos el proceso de instalacion y configuracion Base
# Instalacion y configuracion Base
Programas Base
- git
- neovim
- neofetch
- exa
- bat
- zsh // aca van los alias
- oh-my-posh o starship ---> Pendiente: Inicia oh-my-posh, pero tengo problemas con las fuentes
- unzip // es un requerimiento para utilizar curl  
- openssh
- ranger // FileManager
- pandoc
- fzf // para buscar archivos
- ver font
- ver programas para hacer banner
- ver programas img2ascii

## Base  
```
sudo pacman -S openssh neovim neofetch exa bat zsh unzip
```
## Aur Pakage Manager
Como no todos los paquetes estan disponibles en pacman, instalamos el manejador de paquetes Aur
```
sudo pacman -S base-devel
mkdir aur
cd aur
git clone https://aur.archlinux.org/yay.git
cd yay
makepkg -si
```

## openssh
habilitamos el servicio
```
sudo systemctl start sshd.service
sudo systemctl enable sshd.enable
```

## Starship
Ver el proceso de instalacion en https://starship.rs/
```
curl -sS https://starship.rs/install.sh | sh
```

## oh-my-posh
Le pregunte a bard y me dio las siguientes instrucciones, las cuales probe y funcionó:
1. Esta instalado Git y aur, por lo que ejecutar
```
yay -S oh-my-posh-bin
```
Luego ejecutar
```
oh-my-posh prompt init bash
```
Ojo que bash depende de donde se va a ejecutar oh-my-posh, puedes ser zsh, etc.. Igual salen las instrucciones
Este comando genera un archivo que muestra en pantalla que se debe copiar y agregar al .bashrc (segun el interprete de comandos que se tenga, si es zsh, seria -zshrc)
luego reabrir el interprete de comandos, en mi caso
```
source .bashrc
```

>> NOTA: Queda Pendiente la incorporacion de las fuentes NerdFond que incluyan los iconos
>> he visto varias formas de incluir fuentes (fc-cache -vf / fc-match Meslo -a) para lo que tuve que insaltar fontconfig (sudo pacman -S fontconfig)
>> las fuentes quedan guardadas en Local: ~/.local/share/fonts o para todos /usr/share/fonts

DOC: https://ohmyposh.dev/docs/installation/linux  
```
curl -s https://ohmyposh.dev/install.sh | bash -s
```
# Bard Ai 
Instalacion de bard-cli (AI de Google)
Tal parece que se hace a traves de un repositorio aur

# Servicios
LDAP


