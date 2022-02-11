static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 ,
V_2 . V_2 ) ;
struct V_4 * V_4 = V_3 -> V_4 ;
int V_5 , V_6 ;
V_6 = F_3 ( V_4 , V_7 ) ;
if ( V_6 >= 0 ) {
V_5 = ! ( V_6 & V_8 ) ;
F_4 ( V_3 -> V_9 , V_10 , V_5 ) ;
F_5 ( V_3 -> V_9 ) ;
} else {
F_6 ( V_4 -> V_9 , L_1 , V_6 ) ;
V_5 = 1 ;
}
if ( V_5 )
F_7 ( & V_3 -> V_2 , 100 ) ;
}
static T_1 F_8 ( int V_11 , void * V_12 )
{
struct V_3 * V_3 = V_12 ;
F_7 ( & V_3 -> V_2 , 0 ) ;
return V_13 ;
}
static int T_2 F_9 ( struct V_14 * V_15 )
{
struct V_4 * V_4 = F_10 ( V_15 -> V_9 . V_16 ) ;
struct V_3 * V_3 ;
int V_11 = F_11 ( V_15 , 0 ) ;
int V_6 ;
V_3 = F_12 ( sizeof( struct V_3 ) , V_17 ) ;
if ( ! V_3 ) {
F_6 ( & V_15 -> V_9 , L_2 ) ;
return - V_18 ;
}
V_3 -> V_4 = V_4 ;
F_13 ( & V_3 -> V_2 , F_1 ) ;
V_3 -> V_9 = F_14 () ;
if ( ! V_3 -> V_9 ) {
F_6 ( & V_15 -> V_9 , L_3 ) ;
V_6 = - V_18 ;
goto V_19;
}
V_3 -> V_9 -> V_20 [ 0 ] = F_15 ( V_21 ) ;
V_3 -> V_9 -> V_22 [ F_16 ( V_10 ) ] = F_15 ( V_10 ) ;
V_3 -> V_9 -> V_23 = L_4 ;
V_3 -> V_9 -> V_24 = L_5 ;
V_3 -> V_9 -> V_9 . V_16 = & V_15 -> V_9 ;
V_6 = F_17 ( V_11 , NULL , F_8 ,
V_25 , L_4 ,
V_3 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_15 -> V_9 , L_6 , V_6 ) ;
goto V_26;
}
V_6 = F_18 ( V_3 -> V_9 ) ;
if ( V_6 ) {
F_19 ( & V_15 -> V_9 , L_7 , V_6 ) ;
goto V_27;
}
F_20 ( V_15 , V_3 ) ;
return 0 ;
V_27:
F_21 ( V_11 , V_3 ) ;
V_26:
F_22 ( V_3 -> V_9 ) ;
V_19:
F_23 ( V_3 ) ;
return V_6 ;
}
static int T_3 F_24 ( struct V_14 * V_15 )
{
struct V_3 * V_3 = F_25 ( V_15 ) ;
int V_11 = F_11 ( V_15 , 0 ) ;
F_21 ( V_11 , V_3 ) ;
F_26 ( & V_3 -> V_2 ) ;
F_27 ( V_3 -> V_9 ) ;
F_23 ( V_3 ) ;
return 0 ;
}
static int T_4 F_28 ( void )
{
return F_29 ( & V_28 ) ;
}
static void T_5 F_30 ( void )
{
F_31 ( & V_28 ) ;
}
