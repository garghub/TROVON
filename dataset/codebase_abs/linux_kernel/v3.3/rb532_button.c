static bool F_1 ( void )
{
int V_1 ;
F_2 ( 0 , V_2 ) ;
F_3 ( V_3 ) ;
V_1 = F_4 ( V_3 ) ;
F_5 ( V_3 ) ;
F_2 ( V_2 , 0 ) ;
return ! V_1 ;
}
static void F_6 ( struct V_4 * V_5 )
{
F_7 ( V_5 -> V_6 , V_7 ,
F_1 () ) ;
F_8 ( V_5 -> V_6 ) ;
}
static int T_1 F_9 ( struct V_8 * V_9 )
{
struct V_4 * V_5 ;
int error ;
V_5 = F_10 () ;
if ( ! V_5 )
return - V_10 ;
V_5 -> V_11 = F_6 ;
V_5 -> V_12 = V_13 ;
V_5 -> V_6 -> V_14 = L_1 ;
V_5 -> V_6 -> V_15 = L_2 ;
V_5 -> V_6 -> V_16 . V_17 = V_18 ;
V_5 -> V_6 -> V_19 . V_20 = & V_9 -> V_19 ;
F_11 ( & V_9 -> V_19 , V_5 ) ;
F_12 ( V_5 -> V_6 , V_21 , V_7 ) ;
error = F_13 ( V_5 ) ;
if ( error ) {
F_14 ( V_5 ) ;
return error ;
}
return 0 ;
}
static int T_2 F_15 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = F_16 ( & V_9 -> V_19 ) ;
F_17 ( V_5 ) ;
F_14 ( V_5 ) ;
F_11 ( & V_9 -> V_19 , NULL ) ;
return 0 ;
}
