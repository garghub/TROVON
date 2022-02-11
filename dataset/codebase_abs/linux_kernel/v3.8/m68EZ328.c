void F_1 ( void )
{
F_2 () ;
asm volatile (
"moveal #0x10c00000, %a0;\n"
"moveb #0, 0xFFFFF300;\n"
"moveal 0(%a0), %sp;\n"
"moveal 4(%a0), %a0;\n"
"jmp (%a0);\n"
);
}
void F_3 ( char * V_1 , int V_2 )
{
unsigned char * V_3 ;
F_4 ( V_4 L_1 ) ;
#ifdef F_5
F_4 ( V_4 L_2 , F_6 () ) ;
V_3 = V_5 = F_7 ( 0 ) ;
F_4 ( V_4 L_3 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] , V_3 [ 4 ] , V_3 [ 5 ] ) ;
V_3 = F_8 ( L_4 ) ;
if ( V_3 ) strcpy ( V_3 , V_1 ) ;
else V_1 [ 0 ] = 0 ;
#endif
V_6 = V_7 ;
V_8 = F_1 ;
}
