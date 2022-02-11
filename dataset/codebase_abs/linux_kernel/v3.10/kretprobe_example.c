static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( ! V_7 -> V_8 )
return 1 ;
V_6 = (struct V_5 * ) V_2 -> V_6 ;
V_6 -> V_9 = F_2 () ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_10 = F_4 ( V_4 ) ;
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_6 ;
T_1 V_11 ;
T_2 V_12 ;
V_12 = F_2 () ;
V_11 = F_5 ( F_6 ( V_12 , V_6 -> V_9 ) ) ;
F_7 ( V_13 L_1 ,
V_14 , V_10 , ( long long ) V_11 ) ;
return 0 ;
}
static int T_3 F_8 ( void )
{
int V_15 ;
V_16 . V_17 . V_18 = V_14 ;
V_15 = F_9 ( & V_16 ) ;
if ( V_15 < 0 ) {
F_7 ( V_13 L_2 ,
V_15 ) ;
return - 1 ;
}
F_7 ( V_13 L_3 ,
V_16 . V_17 . V_18 , V_16 . V_17 . V_19 ) ;
return 0 ;
}
static void T_4 F_10 ( void )
{
F_11 ( & V_16 ) ;
F_7 ( V_13 L_4 ,
V_16 . V_17 . V_19 ) ;
F_7 ( V_13 L_5 ,
V_16 . V_20 , V_16 . V_17 . V_18 ) ;
}
