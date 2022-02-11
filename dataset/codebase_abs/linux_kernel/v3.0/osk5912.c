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
struct V_9 * V_11 = V_7 -> V_11 ;
int V_12 ;
V_12 = F_6 ( V_10 ,
V_13 |
V_14 |
V_15 ) ;
if ( V_12 < 0 ) {
F_7 ( V_16 L_1 ) ;
return V_12 ;
}
V_12 = F_6 ( V_11 ,
V_13 |
V_14 |
V_15 ) ;
if ( V_12 < 0 ) {
F_7 ( V_16 L_2 ) ;
return V_12 ;
}
V_12 =
F_8 ( V_10 , 0 , V_17 , V_18 ) ;
if ( V_12 < 0 ) {
F_7 ( V_16 L_3 ) ;
return V_12 ;
}
return V_12 ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_19 * V_20 = V_7 -> V_20 ;
struct V_21 * V_22 = & V_20 -> V_22 ;
F_10 ( V_22 , V_23 ,
F_11 ( V_23 ) ) ;
F_12 ( V_22 , V_24 , F_11 ( V_24 ) ) ;
F_13 ( V_22 , L_4 ) ;
F_13 ( V_22 , L_5 ) ;
F_13 ( V_22 , L_6 ) ;
F_14 ( V_22 ) ;
return 0 ;
}
static int T_1 F_15 ( void )
{
int V_12 ;
T_2 V_25 ;
struct V_26 * V_27 ;
if ( ! ( F_16 () ) )
return - V_28 ;
V_29 = F_17 ( L_7 , - 1 ) ;
if ( ! V_29 )
return - V_30 ;
F_18 ( V_29 , & V_31 ) ;
V_12 = F_19 ( V_29 ) ;
if ( V_12 )
goto V_32;
V_27 = & V_29 -> V_27 ;
V_3 = F_20 ( V_27 , L_8 ) ;
if ( F_21 ( V_3 ) ) {
F_7 ( V_16 L_9 ) ;
V_12 = F_22 ( V_3 ) ;
goto V_33;
}
V_25 = ( V_34 ) F_23 ( V_3 ) ;
if ( V_25 != V_17 ) {
if ( F_24 ( V_3 , V_17 ) ) {
F_7 ( V_16 L_10 ) ;
V_12 = - V_35 ;
goto V_36;
}
}
F_7 ( V_37 L_11 ,
( V_34 ) F_23 ( V_3 ) , V_17 ) ;
return 0 ;
V_36:
F_25 ( V_3 ) ;
V_33:
F_26 ( V_29 ) ;
V_32:
F_27 ( V_29 ) ;
return V_12 ;
}
static void T_3 F_28 ( void )
{
F_25 ( V_3 ) ;
F_29 ( V_29 ) ;
}
