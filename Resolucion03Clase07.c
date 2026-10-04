/****************************************************
 * Empresa : DATASOFT sa                            *
 * Título  : Módulo de simulación de supervivencia  *
 * Cliente : KONAMI                                 *
 * Versión : 1.0									*
 * Autor   : Comisión 302							*
 * Año     : 2026									*
 ***************************************************/

#include <stdio.h>
#define SI 1
#define NO 0


int main()
{
	int cant_Z_enc = 0;
	int cant_Z_elim = 0;
	int cant_pv = 0;
	int cant_muni = 0;
	int total_Z_enc = 0;
	int total_Z_elim = 0;
	float porc_Z_elim = 0;
	int cont_dias_S = 0;
	float porc_dias_S = 0;
	int max_Z;
	int max_dia;
	int min_muni;
	int min_dia;
	int total_muni = 0;
	int estado_critico = NO;
	int muni_completa = NO;
	
	for(int dias = 1; dias <=3 ; dias++)
	{
		printf("\n --- DIA [%d] --- ",dias);
		
		//ZOMBIES ENCONTRADOS VALIDADOS
		do
		{
			printf("\n Ingrese la cantidad de Zombies encontrados (entre 0 y 100): ");
			scanf("%d", &cant_Z_enc);
			
			if(cant_Z_enc < 0 || cant_Z_enc > 100)
			{
				printf("\n --- VALOR ERRONEO ---");
			}
			else
			{
				total_Z_enc += cant_Z_enc;
				
				// CALCULO DE MAXIMO ENCONTRADOS
				if(dias == 1)
				{
					max_Z = cant_Z_enc;
					max_dia = dias;
				}
				else
				{
					if(cant_Z_enc > max_Z)
					{
						max_Z = cant_Z_enc;
						max_dia = dias;
					}
				}
			}
		}while(cant_Z_enc < 0 || cant_Z_enc > 100);
		
		// ZOMBIES ELIMINADOS VALIDADOS
		do
		{
			printf("\n Ingrese la cantidad de Zombies eliminados (entre 0 y 100): ");
			scanf("%d", &cant_Z_elim);
			
			if(cant_Z_elim < 0 || cant_Z_elim > 100)
			{
				printf("\n --- VALOR ERRONEO ---");
			}
			else
			{
				total_Z_elim += cant_Z_elim;
			}
		} while(cant_Z_elim < 0 || cant_Z_elim > cant_Z_enc);
		
		// VIDA PERDIDA VALIDADA
		do
		{
			printf("\n Ingrese la cantidad de Vida perdida (entre 0 y 100): ");
			scanf("%d", &cant_pv);
			
			if(cant_pv < 0 || cant_pv > 100)
			{
				printf("\n --- VALOR ERRONEO ---");
			}
		} while(cant_pv < 0 || cant_pv > 100);
		
		// MUNICION UTILIZADA VALIDADA
		do
		{
			printf("\n Ingrese la cantidad de Municion Utilizada: ");
			scanf("%d", &cant_muni);
			
			if(cant_muni < 0 || cant_muni > 100)
			{
				printf("\n --- VALOR ERRONEO ---");
			}
			else
			{
				total_muni += cant_muni;
				
				if(dias == 1)
				{
					min_muni = cant_muni;
					min_dia = dias;
				}
				else
				{
					total_muni += cant_muni;
				}
				
			}
		} while(cant_muni < 0 || cant_muni > 100);
		// DETERMINAMOS PORCENTAJE DE SUPERVIVENCIA.
		porc_dias_S = (float)(cont_dias_S * 100) / (float) 3.0;
		
		// DETERMINAMOS SUPERVIVENCIA.
		if(cant_pv < 50)
		{
			cont_dias_S++;
			printf("\n DIA [%d] SOBREVIVIDO", dias);
		}
		else
		{
			estado_critico = SI;
			printf("\n DIA [%d] PERDIDO", dias);
		}
		
	}
	
	printf("\n debug ---> total_Z_enc = %d",total_Z_enc);
	
	if(total_Z_enc > 0)
	{
		porc_Z_elim = (float) (total_Z_elim * 100) / (float) total_Z_enc; // (float) LO QUE HACE ES PROMOVER LA VARIABLE, DE INT A FLOAT, PARA QUE SE PUEDA REALIZAR EL PROMEDIO.
		printf("\n debug ---> porc_Z_elim = %.2f",porc_Z_elim);
	}
	else
	{
		printf("\n No se podria calcular por 0 por lo tanto se evita");
		
	}
	if(cant_muni >= 0)
	{
		cant_muni ++;
		total_muni += cant_muni;
	}
	
	if(cant_muni == 100)
	{
		muni_completa = SI;
	}
	
	
	printf("\n DIAS SOBREVIVIDOS = [%d]", cont_dias_S);
	printf("\n PORCENTAJE DE SUPERVIVENCIA = %.2f", porc_dias_S);
	printf("\n EL MAXIMO DE ZOMBIES FUE  = %d Y FUE EN EL DIA = [%d]", max_Z, max_dia);
	printf("\n EL MINIMO DE MUNICION FUE = %d Y FUE EN EL DIA = [%d]", min_muni, min_dia);
	printf("\n MUNICION TOTAL UTILIZADA: %d", total_muni);
	printf("\n ESTUVO EN ESTADO CRITICO: %s", (estado_critico == SI) ? "SI" : "NO" );
	printf("\n LLEGO A UTILIZAR TODA LA MUNICION: %s", (muni_completa == SI) ? "SI" : "NO");
	
	
	return 0;
}
