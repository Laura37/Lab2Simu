#!/bin/bash
# va a preguntar como quiere que se llame el archivo

#A continuación se crean dos carpetas, el "lab2" se almacenará a extensión que ingresó la persona y el "ext" se almacenara la extensión que deseo que la persona ingrese para poder continuar con el programa.
touch lab2
touch ext


#Vamos a definir que la extensión que quiero que la persona ingrese es "c" por lo que lo imprimo en el documento ext. Luego le pregunto a la persona cómo quiere que se llame su archivo y lo almaceno en la variable "nombre"
echo c >> ext
echo ¿Hola, como quiere que se llame su archivo?
read nombre
echo usted puso $nombre

#Esto guarda la extensión que la persona ingresó en el archivo lab2
STR="$nombre"
echo ${STR##*.} > lab2

#En la línea siguiente creo un archivo que se llama "diff.txt" en la línea siguiente con el comando diff encuentra diferencias entre dos archivos. Si no hay ninguna diferencia quiere decir que la persona ingresó la extensión "c" si hay alguna diferencia quiere decir que la persona no ingresó nada o ingresó otra extensión. Dicha diferencia se almacena en el archivo "diff"
touch diff.txt
diff lab2 ext > diff.txt

#Aquí biene la condicional, si la persona ingresó una extensión distinta de "c" o no ingresó nada no va a pasar nada y aquí termina el programa. Si la persona ingresó un nombre con la extensión "c" entonces se creará un archivo en c con ese nombre y se procederá con la siguiente parte del programa.

#La condición pregunta si el contenido archivo "diff.txt" es mayor que cero bytes. Si está vacío quiere decir que no hay ninguna diferencia y que la persona ingresó bien el nombre. Si el archivo está con algo quiere decir que hay una diferencia y allí terminaría el programa.
if [[ -s "diff.txt" ]]; then
	echo "EL nombre asignado: $nombre, tiene la extensión incorrecta o no ingresó nada. Por lo tanto aquí termina."
else
	echo "¡Enhorabuena!. Ha ingresado la extensión correcta. Se creará un archivo para programar en c con ese nombre y se le pedirá que ingrese ciertos datos para el encabezado del programa. A continuación se mostrará el usuario de Linux, la fecha y la versión de gcc instalada en el sistema."
	touch $nombre
	touch base
	echo ${STR%.c} > base
	whoami > who.txt
	date > date.txt
	gcc --version > gv.txt
	whoami
	date
	head -1 gv.txt
	echo ¿Qué resumen ingresará en su codigo?
	read resumen
	echo Ingrese las entradas de su código.
	read entradas
	echo Ingrese las salidas de su código.
	read salidas
	x=$(cat who.txt)
	y=$(head -1 gv.txt)
	z=$(cat base)
	a=$(cat date.txt)
	echo "/*" >> $nombre
	echo "Autor: $x" >> $nombre
	echo "Compilador: $y" >> $nombre
	echo "Compilado: ./$z"  >> $nombre
	echo "Fecha: $a" >> $nombre
	#cat date.txt >> $nombre
	echo "librerias: stdio,..." >> $nombre
	echo "Resumen: $resumen" >> $nombre
	echo "Entrada: $entradas"  >> $nombre
	echo "Salida: $salidas"  >> $nombre
	echo "*/" >> $nombre
	echo "  " >> $nombre
	echo "//librerias" >> $nombre
	echo "#include <stdio.h>" >> $nombre
	echo "//numerar los pasos de pseudocódigo" >> $nombre
	vim $nombre
	rm $nombre base
fi

#Todo lo que quiero que pase si la persona ingresó bien la extensión debe ir dentro del else, sino haría todo eso de todas formas. 

rm lab2 ext diff.txt

#Para finalizar se eliminan los archivos creados para que cada ver que se corra este script no se vaya acumulando la misma información, sino no funcionaría correctamente.
