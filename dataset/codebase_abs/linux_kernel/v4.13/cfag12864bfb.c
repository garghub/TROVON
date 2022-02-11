static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_2 ( V_4 , V_4 -> V_5 ,
F_3 ( V_6 ) ) ;
}
static int F_4 ( struct V_7 * V_8 )
{
int V_9 = - V_10 ;
struct V_1 * V_2 = F_5 ( 0 , & V_8 -> V_11 ) ;
if ( ! V_2 )
goto V_12;
V_2 -> V_13 = ( char V_14 * ) V_6 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = & V_18 ;
V_2 -> V_19 = V_20 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = NULL ;
V_2 -> V_24 = NULL ;
V_2 -> V_25 = V_26 ;
if ( F_6 ( V_2 ) < 0 )
goto V_27;
F_7 ( V_8 , V_2 ) ;
V_1 ( V_2 , L_1 , V_2 -> V_19 . V_28 ) ;
return 0 ;
V_27:
F_8 ( V_2 ) ;
V_12:
return V_9 ;
}
static int F_9 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_10 ( V_8 ) ;
if ( V_2 ) {
F_11 ( V_2 ) ;
F_8 ( V_2 ) ;
}
return 0 ;
}
static int T_1 F_12 ( void )
{
int V_9 = - V_10 ;
if ( ! F_13 () ) {
F_14 (KERN_ERR CFAG12864BFB_NAME L_2
L_3 ) ;
goto V_12;
}
if ( F_15 () ) {
F_14 (KERN_ERR CFAG12864BFB_NAME L_2
L_4 ) ;
return - V_29 ;
}
V_9 = F_16 ( & V_30 ) ;
if ( ! V_9 ) {
V_31 =
F_17 ( V_32 , 0 ) ;
if ( V_31 )
V_9 = F_18 ( V_31 ) ;
else
V_9 = - V_33 ;
if ( V_9 ) {
F_19 ( V_31 ) ;
F_20 ( & V_30 ) ;
}
}
V_12:
return V_9 ;
}
static void T_2 F_21 ( void )
{
F_22 ( V_31 ) ;
F_20 ( & V_30 ) ;
F_23 () ;
}
