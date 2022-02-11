static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_7 ;
int V_8 ;
V_6 = F_2 ( & V_2 -> V_9 , sizeof( * V_6 ) , V_10 ) ;
if ( ! V_6 )
return - V_11 ;
F_3 ( V_2 , V_6 ) ;
V_6 -> V_9 = & V_2 -> V_9 ;
V_6 -> V_12 = V_2 -> V_12 ;
V_6 -> V_13 = true ;
V_6 -> V_14 = F_4 ( V_2 , & V_15 ) ;
if ( F_5 ( V_6 -> V_14 ) ) {
F_6 ( & V_2 -> V_9 , L_1 ) ;
return F_7 ( V_6 -> V_14 ) ;
}
V_8 = F_8 ( V_6 -> V_14 , V_16 , & V_7 ) ;
if ( V_8 ) {
F_6 ( & V_2 -> V_9 , L_2 ) ;
return - V_17 ;
}
F_9 ( & V_2 -> V_9 , L_3 , V_7 ) ;
V_8 = F_10 ( V_6 -> V_14 , V_6 -> V_12 ,
V_18 | V_19 ,
0 , & V_20 , & V_6 -> V_21 ) ;
if ( V_8 ) {
F_6 ( & V_2 -> V_9 , L_4 ,
V_6 -> V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_11 ( V_6 -> V_9 , - 1 , V_22 ,
F_12 ( V_22 ) , NULL , 0 ,
F_13 ( V_6 -> V_21 ) ) ;
if ( V_8 < 0 ) {
F_6 ( & V_2 -> V_9 , L_5 ) ;
return V_8 ;
}
F_14 ( V_6 -> V_9 , V_6 -> V_13 ) ;
return 0 ;
}
