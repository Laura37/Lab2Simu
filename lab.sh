#!/bin/bash
touch lab.txt #creo esta carpeta en donde almacenaré información
curl wttr.in > lab.txt #envío el resultado del comando "curl wttr.in al archivo lab.txt
head -7  lab.txt #Eso es para mostrar las primeras 7 líneas del documento.
rm lab.txt #Esto elimina el archivo lab.txt

