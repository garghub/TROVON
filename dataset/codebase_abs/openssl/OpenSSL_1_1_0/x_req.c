static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 ,
void * V_4 )
{
T_3 * V_5 = ( T_3 * ) * V_2 ;
if ( V_1 == V_6 ) {
V_5 -> V_7 = F_2 () ;
if ( ! V_5 -> V_7 )
return 0 ;
}
return 1 ;
}
