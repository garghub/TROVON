void F_1 ( void )
{
T_1 V_1 ;
F_2 ( V_2 , V_3 + V_4 ) ;
V_1 = F_3 ( V_3 + V_5 ) ;
F_2 ( V_1 & 0xF0FFFFFF , V_3 + V_5 ) ;
F_2 ( 1 , V_3 + V_6 ) ;
}
void F_4 ( int V_7 )
{
F_2 ( V_8 << V_7 ,
V_3 + V_9 ) ;
F_2 ( 0x0 << V_7 , V_3 + V_9 ) ;
}
void F_5 ( int V_7 )
{
F_2 ( ( V_8 | V_10 ) << V_7 ,
V_3 + V_9 ) ;
}
int T_2 F_6 ( void )
{
struct V_11 * V_12 ;
V_12 = F_7 ( NULL , NULL , L_1 ) ;
if ( ! V_12 ) {
F_8 ( L_2 , V_13 ) ;
F_9 () ;
}
V_3 = F_10 ( V_12 , 0 ) ;
if ( ! V_3 ) {
F_8 ( L_3 , V_13 ) ;
F_9 () ;
}
F_2 ( V_2 , V_3 + V_4 ) ;
F_11 ( L_4 , V_12 -> V_14 , V_3 ) ;
F_12 ( V_3 ) ;
F_13 ( V_12 ) ;
return 0 ;
}
