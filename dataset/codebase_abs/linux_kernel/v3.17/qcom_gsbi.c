static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
void T_1 * V_9 ;
struct V_10 * V_11 ;
V_11 = F_2 ( & V_2 -> V_5 , sizeof( * V_11 ) , V_12 ) ;
if ( ! V_11 )
return - V_13 ;
V_8 = F_3 ( V_2 , V_14 , 0 ) ;
V_9 = F_4 ( & V_2 -> V_5 , V_8 ) ;
if ( F_5 ( V_9 ) )
return F_6 ( V_9 ) ;
if ( F_7 ( V_4 , L_1 , & V_11 -> V_15 ) ) {
F_8 ( & V_2 -> V_5 , L_2 ) ;
return - V_16 ;
}
F_7 ( V_4 , L_3 , & V_11 -> V_17 ) ;
F_9 ( & V_2 -> V_5 , L_4 ,
V_11 -> V_15 , V_11 -> V_17 ) ;
V_11 -> V_18 = F_10 ( & V_2 -> V_5 , L_5 ) ;
if ( F_5 ( V_11 -> V_18 ) )
return F_6 ( V_11 -> V_18 ) ;
F_11 ( V_11 -> V_18 ) ;
F_12 ( ( V_11 -> V_15 << V_19 ) | V_11 -> V_17 ,
V_9 + V_20 ) ;
F_13 () ;
F_14 ( V_2 , V_11 ) ;
return F_15 ( V_4 , NULL , NULL , & V_2 -> V_5 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_17 ( V_2 ) ;
F_18 ( V_11 -> V_18 ) ;
return 0 ;
}
