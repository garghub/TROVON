static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 ,
V_7 ) ;
F_3 ( V_6 -> V_8 , V_6 -> V_9 ) ;
F_4 ( 1000 ) ;
F_5 ( V_6 -> V_10 , L_1 ) ;
return V_11 ;
}
static int F_6 ( struct V_12 * V_13 )
{
struct V_5 * V_6 ;
struct V_14 * V_10 = & V_13 -> V_10 ;
int V_15 ;
V_6 = F_7 ( V_10 , sizeof( * V_6 ) , V_16 ) ;
if ( ! V_6 )
return - V_17 ;
V_6 -> V_9 = F_8 ( V_10 -> V_18 , 0 ) ;
if ( ! V_6 -> V_9 ) {
F_9 ( V_10 , L_2 ) ;
return - V_19 ;
}
if ( F_10 ( V_10 -> V_18 , L_3 , & V_6 -> V_8 ) )
V_6 -> V_8 = 0xFFFFFFFF ;
V_6 -> V_10 = V_10 ;
V_6 -> V_7 . V_20 = F_1 ;
V_6 -> V_7 . V_21 = 128 ;
V_15 = F_11 ( & V_6 -> V_7 ) ;
if ( V_15 ) {
F_12 ( V_6 -> V_9 ) ;
F_9 ( V_10 , L_4 , V_15 ) ;
}
return V_15 ;
}
static int T_1 F_13 ( void )
{
return F_14 ( & V_22 ) ;
}
