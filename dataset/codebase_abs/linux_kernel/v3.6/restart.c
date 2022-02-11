void F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( V_2 ) {
V_3 = F_3 ( V_2 , 0 ) ;
if ( ! V_3 )
F_4 ( L_2 , V_4 ) ;
F_5 ( V_2 ) ;
} else {
V_3 = F_6 ( V_5 , 0x1000 ) ;
if ( ! V_3 ) {
F_4 ( L_3 , V_4 ) ;
return;
}
}
}
void F_7 ( char V_6 , const char * V_7 )
{
if ( V_3 )
F_8 ( 1 , V_3 + V_8 ) ;
}
