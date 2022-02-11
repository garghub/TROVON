static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_5 ;
V_5 = F_2 ( V_4 -> V_6 , V_1 ) ;
if ( V_5 < 0 ) {
F_3 ( V_4 -> V_7 , L_1 , V_5 ) ;
return V_8 ;
}
F_4 ( V_4 -> V_7 , 0 ) ;
F_5 ( V_4 -> V_9 , V_10 , V_5 ) ;
F_6 ( V_4 -> V_9 ) ;
return V_8 ;
}
static int F_7 ( struct V_11 * V_12 )
{
struct V_3 * V_4 ;
int V_1 = F_8 ( V_12 , 0 ) ;
int V_13 ;
V_4 = F_9 ( & V_12 -> V_7 , sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
V_4 -> V_9 = F_10 ( & V_12 -> V_7 ) ;
if ( ! V_4 -> V_9 )
return - V_15 ;
V_4 -> V_6 = F_11 ( V_12 -> V_7 . V_16 , NULL ) ;
if ( ! V_4 -> V_6 )
return - V_17 ;
V_4 -> V_7 = & V_12 -> V_7 ;
V_4 -> V_9 -> V_18 = L_2 ;
V_4 -> V_9 -> V_19 = L_3 ;
V_4 -> V_9 -> V_7 . V_16 = V_4 -> V_7 ;
F_12 ( V_4 -> V_9 , V_20 , V_10 ) ;
V_13 = F_13 ( & V_12 -> V_7 , V_1 , NULL ,
F_1 , V_21 , L_4 , V_4 ) ;
if ( V_13 < 0 ) {
F_3 ( & V_12 -> V_7 , L_5 , V_13 ) ;
return V_13 ;
}
V_13 = F_14 ( V_4 -> V_9 ) ;
if ( V_13 ) {
F_3 ( & V_12 -> V_7 , L_6 , V_13 ) ;
return V_13 ;
}
F_15 ( & V_12 -> V_7 , true ) ;
return 0 ;
}
