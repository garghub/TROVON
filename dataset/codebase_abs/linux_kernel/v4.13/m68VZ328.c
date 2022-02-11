static void F_1 ( void )
{
F_2 () ;
#ifdef F_3
V_1 |= 0x20 ;
V_2 |= 0x4 ;
V_3 = 0 ;
#endif
__asm__ __volatile__(
"reset\n\t"
"moveal #0x04000000, %a0\n\t"
"moveal 0(%a0), %sp\n\t"
"moveal 4(%a0), %a0\n\t"
"jmp (%a0)"
);
}
static void T_1 F_4 ( char * V_4 , int V_5 )
{
#ifdef F_5
V_6 = 0x10 ;
#endif
V_7 = 0x4000 ;
V_8 = 0x1a1 ;
V_9 |= F_6 ( 3 ) ;
V_10 |= F_6 ( 3 ) ;
V_2 |= F_6 ( 3 ) ;
V_11 |= F_7 ( 5 ) ;
V_12 |= F_7 ( 5 ) ;
V_13 &= ~ F_7 ( 5 ) ;
V_13 |= F_7 ( 5 ) ;
{ int V_14 ; for ( V_14 = 0 ; V_14 < 32000 ; ++ V_14 ) ; }
V_13 &= ~ F_7 ( 5 ) ;
V_15 &= ~ F_8 ( 1 ) ;
V_16 &= ~ F_8 ( 1 ) ;
V_17 |= F_8 ( 1 ) ;
#ifdef F_3
V_18 = ( long ) V_19 ;
V_20 = 0x14 ;
V_21 = 0x140 ;
V_22 = 0xef ;
V_23 = 0 ;
V_24 = 3 ;
V_25 = 0x08 ;
V_26 = 0 ;
V_3 = 0x80 ;
V_27 = 0xff ;
V_28 = 0 ;
V_10 |= 0x4 ;
V_9 |= 0x4 ;
V_2 &= ~ 0x4 ;
V_29 |= 0x20 ;
V_30 |= 0x20 ;
V_1 &= ~ 0x20 ;
V_12 |= 0x1 ;
V_11 &= ~ 0x1 ;
V_31 = 0x037F ;
#endif
}
static void F_1 ( void )
{
F_2 () ;
asm volatile (
"moveal #0x10c00000, %a0;\n\t"
"moveb #0, 0xFFFFF300;\n\t"
"moveal 0(%a0), %sp;\n\t"
"moveal 4(%a0), %a0;\n\t"
"jmp (%a0);\n"
);
}
static void T_1 F_4 ( char * V_4 , int V_5 )
{
char * V_32 ;
F_9 ( L_1 , F_10 () ) ;
V_32 = V_33 = F_11 ( 0 ) ;
F_9 ( L_2 , V_32 ) ;
V_32 = F_12 ( L_3 ) ;
if ( V_32 )
strcpy ( V_32 , V_4 ) ;
else
V_4 [ 0 ] = 0 ;
}
static void F_1 ( void )
{
}
static void T_1 F_4 ( char * V_4 , int V_5 )
{
}
void T_1 F_13 ( char * V_4 , int V_5 )
{
F_9 ( L_4 ) ;
F_4 ( V_4 , V_5 ) ;
V_34 = V_35 ;
V_36 = V_37 ;
V_38 = F_1 ;
}
