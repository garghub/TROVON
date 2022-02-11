int F_1 ( int V_1 , const T_1 * V_2 )
{
int V_3 = F_2 ( V_1 , V_2 ) ;
if ( V_3 == V_4 )
V_3 = F_3 ( V_2 ) ;
return V_3 ;
}
int F_4 ( const T_1 * V_5 )
{
int V_6 , V_7 = V_8 ;
V_6 = F_5 ( * V_5 ) ;
if ( V_6 )
V_7 = F_6 ( V_5 -> V_9 ,
F_7 () % V_6 , V_4 ) ;
return V_7 ;
}
