int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_9 ;
if ( ! V_5 || ! V_4 )
return - V_10 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_11 ) ; V_9 ++ )
V_4 -> V_12 [ V_9 ] = V_8 -> V_13 [ V_9 ] ;
return F_3 ( V_11 ) ;
}
struct V_3 * F_4 ( struct V_1 * V_2 ,
T_1 V_14 )
{
F_5 ( F_3 ( V_11 ) != V_15 ) ;
if ( ! V_14 )
return NULL ;
return F_6 ( V_11 ,
F_3 ( V_11 ) ,
V_16 ) ;
}
