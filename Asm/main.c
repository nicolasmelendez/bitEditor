/*
	FUNDAMENTOS DE INFRAESTRUCTURA TECNOL�GICA
	Ramón Aljandro Arias Rivera - 20171814
	Nicolás Meléndez
	Albert Adolfo Molano Cubillos - 201713848
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)                                                   \
	(byte & 0x80 ? '1' : '0'), (byte & 0x40 ? '1' : '0'),                      \
		(byte & 0x20 ? '1' : '0'), (byte & 0x10 ? '1' : '0'),                  \
		(byte & 0x08 ? '1' : '0'), (byte & 0x04 ? '1' : '0'),                  \
		(byte & 0x02 ? '1' : '0'), (byte & 0x01 ? '1' : '0')

void escribir(unsigned char *V, unsigned char *s, int p);
void leer(unsigned char *V, unsigned char *s, int p, int l);
unsigned char calcularMascara(int p);
int main(int argc, char *argv[]) {
	// Variables
	int op;
	int l, p;
	unsigned char *V;
	unsigned char *s;
	unsigned char *a;

	// Inicialización
	V = (unsigned char *)calloc(100, sizeof(char));
	s = (unsigned char *)calloc(17, sizeof(char));
	a = (unsigned char *)calloc(7, sizeof(char));
	// Mensaje inicial
	printf("PROYECTO 1 - INFRATEC.");

	// Loop hasta terminar
	op = 3;
	while (op != 0) {
		// Se pregunta al usuario cual opcion desea realizar
		printf(
			"\n\n* Indique la modalidad\n\t0: Terminar\n\t1: Escribir\n\t2: "
			"Leer\n\n");
		printf("Modalidad: ");
		scanf("%d", &op);

		// Escribir
		if (op == 1) {
			printf("Acci? %d: Escribir\n\n", op);

			// Se reciben los valores de s y p
			printf("Escriba s: ");
			scanf("%s", s);

			printf("Se leyeron los siguientes bits: %s\n", s);
			printf("Escriba p: ");
			scanf("%d", &p);

			// Se escribe s desde el bit p de V
			escribir(V, s, p);
			unsigned char *a;

			printf("\nSe escribia s desde el bit p de V.\n");
			//			printf("Se leyeron los siguientes bits: %s\n", V);
		}
		// Leer
		else if (op == 2) {
			printf("Acci? %d: Leer\n\n", op);

			// Se reciben los valores de l y p
			printf("Escriba l: ");
			scanf("%d", &l);
			printf("Escriba p: ");
			scanf("%d", &p);

			// Se leen l bits de V desde la posición p y se escriben como chars
			// en s
			s = (unsigned char *)calloc(17, sizeof(char));
			leer(V, s, p, l);
			printf("Se leyeron los siguientes bits: %s\n", s);

		}
		// Invalido
		else if (op != 0) {
			printf("Opci? invalida.\n");
		}
	}

	// Terminar
	printf("\nPrograma terminado.\n");
	return 0;
}
/*
	Procedimiento que escribe s empezando en el bit p de V
*/
void escribir(unsigned char *V, unsigned char *s, int p) {
		_asm
	{

	}
}

/*
	Procedimiento que lee l bits de V desde la posición p y los escribe
	como chars en s
*/
void leer(unsigned char *V, unsigned char *s, int p, int l) {

	_asm
	{

	mov	BYTE PTR _mask$[ebp], 128	
	mov	BYTE PTR _primera$[ebp], 1
	mov	eax, DWORD PTR _p$[ebp]
	cdq
	and	edx, 7
	add	eax, edx
	sar	eax, 3
	mov	DWORD PTR _pos2$[ebp], eax
	mov	DWORD PTR _pos$[ebp], 0
	mov	eax, DWORD PTR _p$[ebp]
	cdq
	and	edx, 7
	add	eax, edx
	sar	eax, 3
	mov	DWORD PTR _j$2[ebp], eax
	mov	DWORD PTR _k$3[ebp], 0
	jmp	SHORT $LN4@leer
$LN2@leer:
	mov	eax, DWORD PTR _j$2[ebp]
	add	eax, 1
	mov	DWORD PTR _j$2[ebp], eax
	mov	ecx, DWORD PTR _k$3[ebp]
	add	ecx, 1
	mov	DWORD PTR _k$3[ebp], ecx
$LN4@leer:
	cmp	DWORD PTR _k$3[ebp], 4
	jge	$LN1@leer
	mov	BYTE PTR _mask$[ebp], 128	
	movsx	edx, BYTE PTR _primera$[ebp]
	cmp	edx, 1
	jne	SHORT $LN8@leer
	mov	eax, DWORD PTR _p$[ebp]
	and	eax, -2147483641			
	jns	SHORT $LN14@leer
	dec	eax
	or	eax, -8				H
	inc	eax
$LN14@leer:
	mov	DWORD PTR _cap$1[ebp], eax
	jmp	SHORT $LN9@leer
$LN8@leer:
	mov	DWORD PTR _cap$1[ebp], 0
$LN9@leer:
	mov	ecx, DWORD PTR _cap$1[ebp]
	mov	DWORD PTR _i$4[ebp], ecx
	jmp	SHORT $LN7@leer
$LN5@leer:
	mov	edx, DWORD PTR _i$4[ebp]
	add	edx, 1
	mov	DWORD PTR _i$4[ebp], edx
$LN7@leer:
	cmp	DWORD PTR _i$4[ebp], 8
	jge	SHORT $LN6@leer
	mov	eax, DWORD PTR _pos$[ebp]
	cmp	eax, DWORD PTR _l$[ebp]
	jne	SHORT $LN10@leer
	jmp	SHORT $LN6@leer
$LN10@leer:
	movzx	edx, BYTE PTR _mask$[ebp]
	mov	ecx, DWORD PTR _i$4[ebp]
	sar	edx, cl
	mov	BYTE PTR _tMask$5[ebp], dl
	mov	eax, DWORD PTR _V$[ebp]
	add	eax, DWORD PTR _pos2$[ebp]
	movzx	ecx, BYTE PTR [eax]
	movsx	edx, BYTE PTR _tMask$5[ebp]
	and	ecx, edx
	je	SHORT $LN12@leer
	mov	DWORD PTR tv86[ebp], 49			
	jmp	SHORT $LN13@leer
$LN12@leer:
	mov	DWORD PTR tv86[ebp], 48			
$LN13@leer:
	mov	eax, DWORD PTR _s$[ebp]
	add	eax, DWORD PTR _pos$[ebp]
	mov	cl, BYTE PTR tv86[ebp]
	mov	BYTE PTR [eax], cl
	mov	BYTE PTR _primera$[ebp], 0
	mov	edx, DWORD PTR _pos$[ebp]
	add	edx, 1
	mov	DWORD PTR _pos$[ebp], edx
	jmp	SHORT $LN5@leer
$LN6@leer:
	mov	eax, DWORD PTR _pos2$[ebp]
	add	eax, 1
	mov	DWORD PTR _pos2$[ebp], eax
	jmp	$LN2@leer
$LN1@leer:
	mov	esp, ebp
	pop	ebp
	ret	0
_leer	ENDP


	}
}