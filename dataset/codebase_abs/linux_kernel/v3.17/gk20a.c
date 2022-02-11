int
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
V_11 = F_2 ( V_2 , V_3 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_11 )
return V_11 ;
V_10 = (struct V_9 * ) * V_8 ;
V_10 -> V_12 = true ;
return 0 ;
}
