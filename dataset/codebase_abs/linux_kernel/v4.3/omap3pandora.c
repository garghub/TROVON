static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_9 , 0 , 26000000 ,
V_12 ) ;
if ( V_11 < 0 ) {
F_3 ( V_13 L_1 ) ;
return V_11 ;
}
V_11 = F_2 ( V_10 , V_14 ,
256 * F_4 ( V_4 ) ,
V_12 ) ;
if ( V_11 < 0 ) {
F_3 ( V_13 L_2 ) ;
return V_11 ;
}
V_11 = F_5 ( V_10 , V_15 , 8 ) ;
if ( V_11 < 0 ) {
F_3 ( V_13 L_3 ) ;
return V_11 ;
}
return 0 ;
}
static int F_6 ( struct V_16 * V_17 ,
struct V_18 * V_19 , int V_20 )
{
int V_11 ;
if ( F_7 ( V_20 ) ) {
V_11 = F_8 ( V_21 ) ;
if ( V_11 ) {
F_9 ( V_17 -> V_22 -> V_23 , L_4 , V_11 ) ;
return V_11 ;
}
F_10 ( 1 ) ;
F_11 ( V_24 , 1 ) ;
} else {
F_11 ( V_24 , 0 ) ;
F_10 ( 1 ) ;
F_12 ( V_21 ) ;
}
return 0 ;
}
static int F_13 ( struct V_16 * V_17 ,
struct V_18 * V_19 , int V_20 )
{
if ( F_7 ( V_20 ) )
F_11 ( V_25 , 1 ) ;
else
F_11 ( V_25 , 0 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_26 * V_22 = & V_6 -> V_27 -> V_22 ;
F_15 ( V_22 , L_5 ) ;
F_15 ( V_22 , L_6 ) ;
F_15 ( V_22 , L_7 ) ;
F_15 ( V_22 , L_8 ) ;
F_15 ( V_22 , L_9 ) ;
F_15 ( V_22 , L_10 ) ;
F_15 ( V_22 , L_11 ) ;
F_15 ( V_22 , L_12 ) ;
F_15 ( V_22 , L_13 ) ;
F_15 ( V_22 , L_14 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_26 * V_22 = & V_6 -> V_27 -> V_22 ;
F_15 ( V_22 , L_15 ) ;
F_15 ( V_22 , L_16 ) ;
F_15 ( V_22 , L_17 ) ;
F_15 ( V_22 , L_18 ) ;
return 0 ;
}
static int T_1 F_17 ( void )
{
int V_11 ;
if ( ! F_18 () )
return - V_28 ;
F_19 ( L_19 ) ;
V_11 = F_20 ( V_24 , L_20 ) ;
if ( V_11 ) {
F_3 ( V_13 L_21 ) ;
return V_11 ;
}
V_11 = F_21 ( V_24 , 0 ) ;
if ( V_11 ) {
F_3 ( V_13 L_22 ) ;
goto V_29;
}
V_11 = F_20 ( V_25 , L_23 ) ;
if ( V_11 ) {
F_3 ( V_13 L_24 ) ;
goto V_29;
}
V_11 = F_21 ( V_25 , 0 ) ;
if ( V_11 ) {
F_3 ( V_13 L_25 ) ;
goto V_30;
}
V_31 = F_22 ( L_26 , - 1 ) ;
if ( V_31 == NULL ) {
F_3 ( V_13 L_27 ) ;
V_11 = - V_32 ;
goto V_30;
}
F_23 ( V_31 , & V_33 ) ;
V_11 = F_24 ( V_31 ) ;
if ( V_11 ) {
F_3 ( V_13 L_28 ) ;
goto V_34;
}
V_21 = F_25 ( & V_31 -> V_23 , L_29 ) ;
if ( F_26 ( V_21 ) ) {
F_3 ( V_13 L_30 ,
F_27 ( & V_31 -> V_23 ) ,
F_28 ( V_21 ) ) ;
V_11 = F_28 ( V_21 ) ;
goto V_35;
}
return 0 ;
V_35:
F_29 ( V_31 ) ;
V_34:
F_30 ( V_31 ) ;
V_30:
F_31 ( V_25 ) ;
V_29:
F_31 ( V_24 ) ;
return V_11 ;
}
static void T_2 F_32 ( void )
{
F_33 ( V_21 ) ;
F_34 ( V_31 ) ;
F_31 ( V_25 ) ;
F_31 ( V_24 ) ;
}
