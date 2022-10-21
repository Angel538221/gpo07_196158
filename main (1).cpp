#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>


using namespace std;

struct empresa
{

	int idcontrato, numoc;
	string proveedor, year;
	float subtotal, iva, total;
};


int main()
{
	empresa compras[3];
	int opcion, busqueda;

	do
	{
		printf("\t **MENU OPCIONES** \n");
		printf(" 1.-Alta \n 2.-Lista \n 3.-Eliminar \n 4.-Limpiar \n 5.-Salir \n");
		scanf("%d", &opcion);

		switch (opcion)
		{
		case 1:
			for (int i = 0; i < 3; i++)
			{
				compras[i].idcontrato = 20220000 + i;
				printf("ID CONTRATO: %d \n", compras[i].idcontrato);
				int salida=1;
				do
				{
					printf("ingrese el num oc \n");
					scanf("%d", &compras[i].numoc);
					if (compras[i].numoc == compras[i - 1].numoc || compras[i].numoc == compras[i - 2].numoc)
					{
						printf("el num oc ya existe \n");

					}
					else
					{
						salida = 2;
					}
				} while (salida == 1);
					
				printf("ingrese el proveedor \n");
				cin.ignore();
				getline(cin, compras[i].proveedor);
				printf("ingrese el año \n");
				cin.ignore();
				getline(cin, compras[i].year);
				printf("ingrese el subtotal \n");
				scanf("%f", &compras[i].subtotal);
				compras[i].iva = compras[i].subtotal * 1.16;
				compras[i].total = compras[i].subtotal + compras[i].iva;
			}
			break;

		case 2: 
			int opc2;
			printf("1.- num OC \n 2.-Listas Vigentes ");
			scanf("%d", &opc2);
			if (opc2 == 1)
			{
				printf("ingrese el num oc");
				scanf("%d", &busqueda);

				for (int i = 0; i < 3; i++)
				{
					if (busqueda == compras[i].numoc)
					{
						printf("ID CONTRATO: %d \n", compras[i].idcontrato);
						printf("num OC: %d \n", compras[i].numoc);
						printf("proveedor %s", compras[i].proveedor.c_str());
						printf("año %s", compras[i].year.c_str());
						printf("subtotal: %f \n", compras[i].subtotal);
						printf("iva: %f \n", compras[i].iva);
						printf("total: %f \n", compras[i].total);
					}
				}
			}
			else
			{
				for (int i = 0; i < 3; i++)
				{
					if (compras[i].numoc !=0)
					{
						printf("ID CONTRATO: %d \n", compras[i].idcontrato);
						printf("num OC: %d \n", compras[i].numoc);
						printf("proveedor %s", compras[i].proveedor.c_str());
						printf("año %s", compras[i].year.c_str());
						printf("subtotal: %f \n", compras[i].subtotal);
						printf("iva: %f \n", compras[i].iva);
						printf("total: %f \n", compras[i].total);
					}
				}
			}
			break;

		case 3:
			printf("ingrese el num oc");
			scanf("%d", &busqueda);

			for (int i = 0; i < 3; i++)
			{
				if (busqueda == compras[i].numoc)
				{
					compras[i].numoc = 0;
				}
			}
			break;

		case 4:
			system("cls");
			break;
		case 5:
			printf("saliendo... \n");
			break;
		default:
			printf("intente denuevo... \n");
			break;
		}
	} while (opcion != 5);
	system("pause");
}