#!/bin/bash
# se requiere el aplicativo acpi (sudo pacman -S acpi)

get_battery_status() {
    battery="/sys/class/power_supply/BAT0"
    if [ ! -d "$battery" ]; then
        echo "No battery found"
        return
    fi

    capacity=$(cat "$battery/capacity")
    status=$(cat "$battery/status")

    if [ "$status" = "Charging" ]; then
        icon=" "
    elif [ "$capacity" -gt 80 ]; then
        icon=" "
    elif [ "$capacity" -gt 60 ]; then
        icon=" "
    elif [ "$capacity" -gt 40 ]; then
        icon=" "
    elif [ "$capacity" -gt 20 ]; then
        icon=" "
    else
        # Batería baja - mostrar tiempo restante y color rojo
        time_left=$(acpi -b | grep "remaining" | awk '{print $5}')
        echo "%{F#A54242}$icon $capacity% ($time_left)%{F-}"
        return
    fi

    echo "$icon $capacity%"
}

get_battery_status
