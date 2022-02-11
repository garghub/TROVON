static int F_1 ( struct V_1 * V_2 , void * V_3 , int V_4 ,
void * V_5 , T_1 V_6 )
{
int V_7 ;
struct V_8 * V_9 = F_2 ( & V_2 -> V_10 ) ;
F_3 ( & V_2 -> V_10 , L_1 ,
++ V_9 -> V_11 , V_6 ) ;
F_4 ( V_12 , V_13 , V_14 , 16 , 1 ,
V_3 , V_4 , true ) ;
if ( V_9 -> V_11 >= V_15 ) {
F_3 ( & V_2 -> V_10 , L_2 ) ;
return 0 ;
}
V_7 = F_5 ( V_2 -> V_16 , V_17 , strlen ( V_17 ) ) ;
if ( V_7 )
F_6 ( & V_2 -> V_10 , L_3 , V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_7 ;
struct V_8 * V_9 ;
F_3 ( & V_2 -> V_10 , L_4 ,
V_2 -> V_6 , V_2 -> V_18 ) ;
V_9 = F_8 ( & V_2 -> V_10 , sizeof( * V_9 ) , V_19 ) ;
if ( ! V_9 )
return - V_20 ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
V_7 = F_5 ( V_2 -> V_16 , V_17 , strlen ( V_17 ) ) ;
if ( V_7 ) {
F_6 ( & V_2 -> V_10 , L_3 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_10 , L_5 ) ;
}
