static void
F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = V_2 ;
V_5 = F_2 ( V_4 -> V_6 , V_7 )
& V_8 ;
if ( V_1 == V_9 && ! V_5 )
F_3 ( V_4 -> V_10 , V_11 , 1 ) ;
else if ( V_1 == V_12 && V_5 )
F_3 ( V_4 -> V_10 , V_11 , 0 ) ;
F_4 ( V_4 -> V_10 ) ;
}
static int T_1 F_5 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
struct V_10 * V_10 ;
int V_15 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_16 ) ;
if ( ! V_4 )
return - V_17 ;
V_10 = F_7 () ;
if ( ! V_10 ) {
F_8 ( V_4 ) ;
return - V_17 ;
}
F_9 ( V_14 , V_4 ) ;
V_4 -> V_6 = F_10 ( V_14 -> V_18 . V_19 ) ;
V_4 -> V_10 = V_10 ;
V_10 -> V_20 = L_1 ;
V_10 -> V_21 . V_22 = V_23 ;
V_10 -> V_24 [ 0 ] = F_11 ( V_25 ) | F_11 ( V_26 ) ;
F_12 ( V_11 , V_10 -> V_27 ) ;
V_15 = F_13 ( V_10 ) ;
if ( V_15 ) {
F_14 ( V_10 ) ;
F_8 ( V_4 ) ;
return V_15 ;
}
F_15 ( V_4 -> V_6 , V_12 ,
F_1 , V_4 ) ;
F_15 ( V_4 -> V_6 , V_9 ,
F_1 , V_4 ) ;
return 0 ;
}
static int T_2 F_16 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = F_17 ( V_14 ) ;
F_18 ( V_4 -> V_6 , V_12 ) ;
F_18 ( V_4 -> V_6 , V_9 ) ;
F_19 ( V_4 -> V_10 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
static int T_3 F_20 ( void )
{
return F_21 ( & V_28 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_28 ) ;
}
