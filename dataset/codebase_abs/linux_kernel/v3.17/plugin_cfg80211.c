static unsigned long long
F_1 ( struct V_1 * V_2 , unsigned long long * args )
{
T_1 * V_3 = ( T_1 * ) ( unsigned long ) args [ 0 ] ;
return V_3 ? ( long long ) F_2 ( * V_3 ) : 0 ;
}
int F_3 ( struct V_4 * V_4 )
{
F_4 ( V_4 ,
F_1 ,
V_5 ,
L_1 ,
V_6 ,
V_7 ) ;
return 0 ;
}
void F_5 ( struct V_4 * V_4 )
{
F_6 ( V_4 , F_1 ,
L_1 ) ;
}
