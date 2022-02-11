static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 , ~ 0L ) ;
F_3 ( V_2 -> V_3 , V_4 , & V_2 -> V_5 ) ;
F_2 ( V_2 -> V_3 , V_4 , 0x0 ) ;
}
static int F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
void T_1 * V_12 ;
V_2 = F_5 ( V_9 , sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
V_11 = F_6 ( V_7 , V_15 , 0 ) ;
V_12 = F_7 ( V_9 , V_11 ) ;
if ( F_8 ( V_12 ) )
return F_9 ( V_12 ) ;
V_2 -> V_3 = F_10 ( V_9 , L_1 , V_12 ,
& V_16 ) ;
if ( F_8 ( V_2 -> V_3 ) )
return F_9 ( V_2 -> V_3 ) ;
V_2 -> V_17 = F_11 ( V_9 , NULL ) ;
if ( F_8 ( V_2 -> V_17 ) )
return F_9 ( V_2 -> V_17 ) ;
F_1 ( V_2 ) ;
F_12 ( V_7 , V_2 ) ;
return F_13 ( V_7 -> V_9 . V_18 , NULL , NULL , & V_7 -> V_9 ) ;
}
static int F_14 ( struct V_6 * V_7 )
{
F_15 ( & V_7 -> V_9 ) ;
return 0 ;
}
