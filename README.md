<!--
Title: Instalacion ArchLinux
Date: 14-08-23
Author: Dferruz
Ref: (1) Arfan Zubi 	
- https://www.youtube.com/watch?v=cOobSmI-XgA&t=399s
- https://github.com/3rfaan
-->

# Arch Installation Guide

## Prerequisitos
*Console keyboard layout*
Definicion de teclado en español
```
$ loadkeys la-latin1
```
*Internet*
Validar la conexion a internet, Ping (conexion a internet) y si no configurarla
Fisicamente cable o wifi.
*WIFI:*
```
ip link show
ip link set wlan0 up
iwlist wlan0 scan
wpa_passphrase <<SSID>> <<Passwd>> > /etc/wifi
wpa_supplicant -B -i wlan0 -D wext -c /etc/wifi
dhclient
```

*Uso Horario* 
Activar NTP, timedatectl status (chek set-ntp true)
```
timedatectl status
timedatectl set-ntp true
```
## Particion

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
