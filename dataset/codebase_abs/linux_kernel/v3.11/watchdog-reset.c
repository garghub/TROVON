void F_1 ( void )
{
if ( ! V_1 ) {
F_2 ( L_1 , V_2 ) ;
F_3 ( 50 ) ;
return;
}
if ( ! F_4 ( V_3 ) )
F_5 ( V_3 ) ;
F_6 ( 0 , V_1 + V_4 ) ;
F_6 ( 0x80 , V_1 + V_5 ) ;
F_6 ( 0x80 , V_1 + V_6 ) ;
F_6 ( V_7 | V_8 |
V_9 | F_7 ( 0x20 ) ,
V_1 + V_4 ) ;
F_3 ( 500 ) ;
F_2 ( L_2 ) ;
F_3 ( 50 ) ;
}
void T_1 F_8 ( void )
{
struct V_10 * V_11 ;
V_11 = F_9 ( NULL , V_12 ) ;
if ( ! V_11 ) {
F_2 ( L_3 , V_2 ) ;
return;
}
V_1 = F_10 ( V_11 , 0 ) ;
if ( ! V_1 ) {
F_2 ( L_4 , V_2 ) ;
return;
}
V_3 = F_11 ( V_11 , 0 ) ;
}
void T_1 F_12 ( void T_2 * V_13 )
{
V_1 = V_13 ;
V_3 = F_13 ( NULL , L_5 ) ;
}
