static T_1 int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( ! V_7 )
goto V_8;
V_6 = F_2 ( sizeof( struct V_5 ) , V_9 ) ;
if ( ! V_6 ) {
F_3 ( V_10 L_1
L_2 ) ;
goto V_8;
}
V_6 -> V_11 = ( void V_12 * ) V_13 ;
V_6 -> clock = 40 ;
V_6 -> V_14 = 1 ;
V_6 -> V_15 = V_16 ;
V_6 -> V_17 = V_18 ;
V_6 -> V_19 = V_20 ;
V_4 = F_4 ( & V_21 , V_6 ,
& V_2 -> V_2 ) ;
if ( ! V_4 ) {
F_3 ( V_10 L_3
L_4 ) ;
goto V_22;
}
V_4 -> V_11 = V_13 ;
V_4 -> V_23 = 7 ;
V_4 -> V_24 = V_25 ;
if ( F_5 ( V_25 , V_26 , 0 , L_5 ,
V_4 ) ) {
F_3 ( V_10 L_6 ) ;
goto V_27;
}
F_6 ( V_2 , V_4 ) ;
F_7 ( V_4 ) ;
return 0 ;
V_27:
F_8 ( V_4 ) ;
V_22:
F_9 ( V_6 ) ;
V_8:
return - V_28 ;
}
static T_2 int
F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_11 ( V_2 ) ;
struct V_5 * V_6 = F_12 ( V_4 ) ;
F_13 ( V_4 ) ;
F_14 ( V_4 ) ;
F_9 ( V_6 ) ;
F_15 ( V_4 -> V_24 , V_4 ) ;
return 0 ;
}
static int T_3 F_16 ( void )
{
int V_29 ;
V_29 = F_17 ( & V_30 ) ;
if ( V_29 )
return V_29 ;
V_31 = F_18 ( L_5 ,
- 1 , NULL , 0 ) ;
if ( F_19 ( V_31 ) ) {
F_20 ( & V_30 ) ;
return F_21 ( V_31 ) ;
}
return 0 ;
}
static void T_4 F_22 ( void )
{
F_23 ( V_31 ) ;
F_20 ( & V_30 ) ;
}
