static int F_1 ( const T_1 * const * V_1 ,
const T_1 * const * V_2 )
{
return ( ( * V_1 ) -> V_3 - ( * V_2 ) -> V_3 ) ;
}
int F_2 ( T_2 * V_4 , T_1 * V_5 )
{
T_3 * V_6 ;
V_6 = V_4 -> V_4 ;
if( ! V_6 -> V_7 )
V_6 -> V_7 = F_3 ( V_8 ) ;
if( ! V_6 -> V_7 || ! F_4 ( V_6 -> V_7 , V_5 ) ) {
F_5 ( V_9 , V_10 ) ;
return 0 ;
}
return 1 ;
}
