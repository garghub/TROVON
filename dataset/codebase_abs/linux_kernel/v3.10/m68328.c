void F_1 ( void )
{
F_2 () ;
asm volatile ("moveal #0x10c00000, %a0;\n\t"
"moveb #0, 0xFFFFF300;\n\t"
"moveal 0(%a0), %sp;\n\t"
"moveal 4(%a0), %a0;\n\t"
"jmp (%a0);");
}
void F_3 ( char * V_1 , int V_2 )
{
F_4 ( V_3 L_1 ) ;
F_4 ( V_3 L_2 ) ;
F_4 ( V_3 L_3 ) ;
V_4 = V_5 ;
V_6 = F_1 ;
}
