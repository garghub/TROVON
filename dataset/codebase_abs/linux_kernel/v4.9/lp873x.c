static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
unsigned int V_8 ;
V_6 = F_2 ( & V_2 -> V_9 , sizeof( * V_6 ) , V_10 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_9 = & V_2 -> V_9 ;
V_6 -> V_12 = F_3 ( V_2 , & V_13 ) ;
if ( F_4 ( V_6 -> V_12 ) ) {
V_7 = F_5 ( V_6 -> V_12 ) ;
F_6 ( V_6 -> V_9 ,
L_1 , V_7 ) ;
return V_7 ;
}
V_7 = F_7 ( V_6 -> V_12 , V_14 , & V_8 ) ;
if ( V_7 ) {
F_6 ( V_6 -> V_9 , L_2 ) ;
return V_7 ;
}
V_6 -> V_15 = V_8 & V_16 ;
F_8 ( V_2 , V_6 ) ;
V_7 = F_9 ( V_6 -> V_9 , V_17 , V_18 ,
F_10 ( V_18 ) , NULL , 0 , NULL ) ;
return V_7 ;
}
