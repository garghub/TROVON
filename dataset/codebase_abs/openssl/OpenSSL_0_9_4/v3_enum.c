static T_1 * F_1 ( void )
{
return F_2 () ;
}
char * F_3 ( T_2 * V_1 ,
T_1 * V_2 )
{
T_3 * V_3 ;
long V_4 ;
V_4 = F_4 ( V_2 ) ;
for( V_3 = V_1 -> V_5 ; V_3 -> V_6 ; V_3 ++ ) {
if( V_4 == V_3 -> V_7 ) return F_5 ( V_3 -> V_6 ) ;
}
return F_6 ( V_1 , V_2 ) ;
}
