static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
int V_11 ;
V_11 =
F_6 ( V_10 , 0 , V_12 , V_13 ) ;
if ( V_11 < 0 ) {
F_7 ( V_14 L_1 ) ;
return V_11 ;
}
return V_11 ;
}
static int T_1 F_8 ( void )
{
int V_11 ;
T_2 V_15 ;
struct V_16 * V_17 ;
if ( ! ( F_9 () ) )
return - V_18 ;
V_19 = F_10 ( L_2 , - 1 ) ;
if ( ! V_19 )
return - V_20 ;
F_11 ( V_19 , & V_21 ) ;
V_11 = F_12 ( V_19 ) ;
if ( V_11 )
goto V_22;
V_17 = & V_19 -> V_17 ;
V_3 = F_13 ( V_17 , L_3 ) ;
if ( F_14 ( V_3 ) ) {
F_7 ( V_14 L_4 ) ;
V_11 = F_15 ( V_3 ) ;
goto V_23;
}
V_15 = ( V_24 ) F_16 ( V_3 ) ;
if ( V_15 != V_12 ) {
if ( F_17 ( V_3 , V_12 ) ) {
F_7 ( V_14 L_5 ) ;
V_11 = - V_25 ;
goto V_26;
}
}
F_7 ( V_27 L_6 ,
( V_24 ) F_16 ( V_3 ) , V_12 ) ;
return 0 ;
V_26:
F_18 ( V_3 ) ;
V_23:
F_19 ( V_19 ) ;
V_22:
F_20 ( V_19 ) ;
return V_11 ;
}
static void T_3 F_21 ( void )
{
F_18 ( V_3 ) ;
F_22 ( V_19 ) ;
}
