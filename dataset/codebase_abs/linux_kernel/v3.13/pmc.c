int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 = (struct V_6 * ) V_4 -> V_8 ;
V_5 = F_2 ( V_2 , V_4 ) ;
if ( ! V_5 ) {
F_3 ( V_9 , L_1 ) ;
V_7 -> V_10 = V_11 ;
} else {
F_4 ( L_2 ) ;
}
return V_5 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = (struct V_6 * ) V_4 -> V_8 ;
if ( V_11 != V_7 -> V_10 ) {
F_4 ( L_3 ) ;
return - V_12 ;
}
F_6 ( V_2 , V_4 ) ;
V_7 -> V_10 = V_13 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_3 ( V_9 , L_4 , V_14 ) ;
return F_8 ( V_2 , V_4 ,
V_15 ) ;
}
