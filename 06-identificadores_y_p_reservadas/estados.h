#ifndef _ESTADOS_H_
#define _ESTADOS_H_

#define E_ERROR     0xFFFF

// Estados iniciales y para números
#define E_INICIAL   0
#define E_SIGNO     1
#define E_ENTERO    2
#define E_FLOTANTE  3
#define E_NOTA_CIEN 4
#define E_EXP_SIGNO 5
#define E_EXP_NUM   6
#define E_IDENT     7    // Identificador
#define E_RESERVADA 8    // Palabra reservada del lenguaje C
#define E_OPERADOR  9    // Operadores aritméticos + - * /

#endif
