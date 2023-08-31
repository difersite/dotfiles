---
Title: Instalacion ArchLinux
Date: 14-08-23
Author: Dferruz
---
# Arch Installation Guide
- Referencias
  1 Arfan Zubi
    - https://www.youtube.com/watch?v=cOobSmI-XgA&t=399s
		- https://github.com/3rfaan
## Prerequisitos
- **Console keyboard layout**
Definicion de teclado en español
```
$ loadkeys la-latin1
```
- **Internet**
Validar la conexion a internet, Ping (conexion a internet) y si no configurarla
Fisicamente cable o wifi.
**WIFI:**
```
ip link show
ip link set wlan0 up
iwlist wlan0 scan
wpa_passphrase <<SSID>> <<Passwd>> > /etc/wifi
wpa_supplicant -B -i wlan0 -D wext -c /etc/wifi
dhclient
```
- **Uso Horario**  
Activar NTP, timedatectl status (chek set-ntp true)
```
timedatectl status
timedatectl set-ntp true
```
## Particion 
el Particionado puede ser segun el tipo de boot del equipo ya sea UEFI o DOS
Si es UEFI usamos GPT 
```
lsblk
cfdisk 
```
**Estructura del Disco**
cfdisk - 40G
Type: DOS
sda1 - boot (200M)
sda2 - SWAP (2G)
sda3 - / (30G)
sda4 - /home (lo que queda)
**Formateo**
```
mkfs.fat -F 32 /dev/sda1
mkswap /dev/sda2
swapon /dev/sda2
mkfs.ext4 /dev/sda3
mkfs.ext4 /dev/sda4
```
/dev/sda3 (para la raiz) y /dev/sda4 (para home)
**Montamos los discos**
```
mount /dev/sda3 /mnt
mkdir /mnt/boot
mkdir /mnt/home
mount /dev/sda1 /mnt/boot
mount /dev/sda4 /mnt/home
```
## Instalcion
```
pacstrap /mnt base base-devel
```
**Editor**
```
pacstrap /mnt nano neovim
```
**Networking**
```
pacstrap /mnt dhcpcd netctl iwd net-tools dialog wireless_tools
```
<!-- $ pacstrap -K /mnt base base-devel linux linux-firmware e2fsprogs dhcpcd networkmanager sof-firmware git neovim man-db man-pages texinfo -->

## arranque (fstab)
```
cat /mnt/etc/fstab
genfstab -p /mnt >> /mnt/etc/fstab
cat /mnt/etc/fstab
```
## personalizacion
```
arch-chroot /mnt
```
```
nvim /etc/locale.gen (decomentar es_CL)
locale-gen
echo "LANG=es_CL.UTF8" > /etc/locale.conf
export LANG=es_CL.UTF8
ln -sf /usr/share/zoneinfo/Chile/Continental /etc/localtime
echo "KEYMAP=La-Latin1" > /etc/vconsole.conf
echo "Nombre" > /etc/hostname
nvim /etc/hosts
```

## Servicios y Programas
```
pacman -S networkmanager ifplugd  
pacman -S openssh
pacman -S exa bat 
pacman -S sudo 
```
```
systemctl enable dhcpcd
systemctl enable NetworkManager
systemctl enable sshd.service
```
# admin y user
```
passwd
useradd -m -g users -G wheel,storage,power -s /bin/bash dferruz
passwd dferruz
```
```
nvim /etc/sudoers (descomentar %wheel)
```
# Instalacion del Kernel
```
ls /boot
pacman -S linux linux-firmware mkinitcpio
pacman -S grub
```
```
grub-install --recheck /dev/sda
grub-mkconfig -o /boot/grub/grub.cfg
mkinitcpio -p linux
```
# salir y reboot
```
exit
umount -R /mnt
reboot
```
<!--
# Instalación Archlinux
(1) Preparación
(2) Particionado 
(3) Instalación Sistema Base 
(4) Arranque
(5) Personalización del Sistema
(6) Servicios y Programas
(7) Administrador y usuarios
(8) Instalación del Kernel
(9) Salir, desmontar y Reboot

## Preparación 
**teclado**
```
loadkey la_latin1
```

**Internet**
**hora**

## Particionado 
## Instalación Sistema Base 
## Arranque
## Personalización del Sistema
## Servicios y Programas
## Administrador y usuarios
## Instalación del Kernel
## Salir, desmontar y Reboot

# dotfiles
Configuraciones personales: 
(1) qtile. Basada en antonio Sarosi 
(2) alacritty. 
(3) neovim.
(4) Rofi.

extraidas de otros repsitorios y adaptadas segun mi gusto.

Plugin importantes de nvim
https://www.tabnine.com/blog/top-vim-plugins/?utm_term=&utm_source=google.com&utm_medium=cpc&utm_campaign=14293437790&utm_content=&gclid=EAIaIQobChMIrfq1r7uS-AIVDlKRCh3zmwp7EAAYASAAEgIZ0PD_BwE
--!>
