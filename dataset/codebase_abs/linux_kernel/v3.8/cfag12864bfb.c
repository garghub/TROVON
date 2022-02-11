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
F_8 ( V_28 L_1 , V_2 -> V_29 ,
V_2 -> V_19 . V_30 ) ;
return 0 ;
V_27:
F_9 ( V_2 ) ;
V_12:
return V_9 ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_11 ( V_8 ) ;
if ( V_2 ) {
F_12 ( V_2 ) ;
F_9 ( V_2 ) ;
}
return 0 ;
}
static int T_1 F_13 ( void )
{
int V_9 = - V_10 ;
if ( ! F_14 () ) {
F_8 (KERN_ERR CFAG12864BFB_NAME L_2
L_3 ) ;
goto V_12;
}
if ( F_15 () ) {
F_8 (KERN_ERR CFAG12864BFB_NAME L_2
L_4 ) ;
return - V_31 ;
}
V_9 = F_16 ( & V_32 ) ;
if ( ! V_9 ) {
V_33 =
F_17 ( V_34 , 0 ) ;
if ( V_33 )
V_9 = F_18 ( V_33 ) ;
else
V_9 = - V_35 ;
if ( V_9 ) {
F_19 ( V_33 ) ;
F_20 ( & V_32 ) ;
}
}
V_12:
return V_9 ;
}
static void T_2 F_21 ( void )
{
F_22 ( V_33 ) ;
F_20 ( & V_32 ) ;
F_23 () ;
}
