void F_1 ( char * V_1 )
{
F_2 ( L_1 ) ;
F_2 ( V_1 ) ;
F_2 ( L_1 ) ;
}
void error ( char * V_1 )
{
F_1 ( V_1 ) ;
F_2 ( L_2 ) ;
while ( 1 )
asm("hlt");
}
