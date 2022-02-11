static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
const struct V_6 * V_7 ;
int V_8 ;
unsigned int V_9 ;
V_5 = F_2 ( & V_2 -> V_10 , sizeof( * V_5 ) , V_11 ) ;
if ( ! V_5 )
return - V_12 ;
V_5 -> V_10 = & V_2 -> V_10 ;
V_5 -> V_13 = F_3 ( V_2 , & V_14 ) ;
if ( F_4 ( V_5 -> V_13 ) ) {
V_8 = F_5 ( V_5 -> V_13 ) ;
F_6 ( V_5 -> V_10 ,
L_1 , V_8 ) ;
return V_8 ;
}
V_8 = F_7 ( V_5 -> V_13 , V_15 , & V_9 ) ;
if ( V_8 ) {
F_6 ( V_5 -> V_10 , L_2 ) ;
return V_8 ;
}
V_5 -> V_16 = V_9 & V_17 ;
V_7 = F_8 ( V_18 , & V_2 -> V_10 ) ;
if ( V_7 )
V_5 -> V_19 = (enum V_20 ) V_7 -> V_21 ;
F_9 ( V_2 , V_5 ) ;
V_8 = F_10 ( V_5 -> V_10 , V_22 , V_23 ,
F_11 ( V_23 ) , NULL , 0 , NULL ) ;
return V_8 ;
}
