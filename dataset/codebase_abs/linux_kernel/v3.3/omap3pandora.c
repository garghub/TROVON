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
if ( F_7 ( V_20 ) ) {
F_8 ( V_21 ) ;
F_9 ( 1 ) ;
F_10 ( V_22 , 1 ) ;
} else {
F_10 ( V_22 , 0 ) ;
F_9 ( 1 ) ;
F_11 ( V_21 ) ;
}
return 0 ;
}
static int F_12 ( struct V_16 * V_17 ,
struct V_18 * V_19 , int V_20 )
{
if ( F_7 ( V_20 ) )
F_10 ( V_23 , 1 ) ;
else
F_10 ( V_23 , 0 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 )
{
struct V_24 * V_25 = V_6 -> V_25 ;
struct V_26 * V_27 = & V_25 -> V_27 ;
int V_11 ;
F_14 ( V_27 , L_4 ) ;
F_14 ( V_27 , L_5 ) ;
F_14 ( V_27 , L_6 ) ;
F_14 ( V_27 , L_7 ) ;
F_14 ( V_27 , L_8 ) ;
F_14 ( V_27 , L_9 ) ;
F_14 ( V_27 , L_10 ) ;
F_14 ( V_27 , L_11 ) ;
F_14 ( V_27 , L_12 ) ;
F_14 ( V_27 , L_13 ) ;
V_11 = F_15 ( V_27 , V_28 ,
F_16 ( V_28 ) ) ;
if ( V_11 < 0 )
return V_11 ;
return F_17 ( V_27 , V_29 ,
F_16 ( V_29 ) ) ;
}
static int F_18 ( struct V_5 * V_6 )
{
struct V_24 * V_25 = V_6 -> V_25 ;
struct V_26 * V_27 = & V_25 -> V_27 ;
int V_11 ;
F_14 ( V_27 , L_14 ) ;
F_14 ( V_27 , L_15 ) ;
F_14 ( V_27 , L_16 ) ;
F_14 ( V_27 , L_17 ) ;
V_11 = F_15 ( V_27 , V_30 ,
F_16 ( V_30 ) ) ;
if ( V_11 < 0 )
return V_11 ;
return F_17 ( V_27 , V_31 ,
F_16 ( V_31 ) ) ;
}
static int T_1 F_19 ( void )
{
int V_11 ;
if ( ! F_20 () )
return - V_32 ;
F_21 ( L_18 ) ;
V_11 = F_22 ( V_22 , L_19 ) ;
if ( V_11 ) {
F_3 ( V_13 L_20 ) ;
return V_11 ;
}
V_11 = F_23 ( V_22 , 0 ) ;
if ( V_11 ) {
F_3 ( V_13 L_21 ) ;
goto V_33;
}
V_11 = F_22 ( V_23 , L_22 ) ;
if ( V_11 ) {
F_3 ( V_13 L_23 ) ;
goto V_33;
}
V_11 = F_23 ( V_23 , 0 ) ;
if ( V_11 ) {
F_3 ( V_13 L_24 ) ;
goto V_34;
}
V_35 = F_24 ( L_25 , - 1 ) ;
if ( V_35 == NULL ) {
F_3 ( V_13 L_26 ) ;
V_11 = - V_36 ;
goto V_34;
}
F_25 ( V_35 , & V_37 ) ;
V_11 = F_26 ( V_35 ) ;
if ( V_11 ) {
F_3 ( V_13 L_27 ) ;
goto V_38;
}
V_21 = F_27 ( & V_35 -> V_39 , L_28 ) ;
if ( F_28 ( V_21 ) ) {
F_3 ( V_13 L_29 ,
F_29 ( & V_35 -> V_39 ) ,
F_30 ( V_21 ) ) ;
V_11 = F_30 ( V_21 ) ;
goto V_40;
}
return 0 ;
V_40:
F_31 ( V_35 ) ;
V_38:
F_32 ( V_35 ) ;
V_34:
F_33 ( V_23 ) ;
V_33:
F_33 ( V_22 ) ;
return V_11 ;
}
static void T_2 F_34 ( void )
{
F_35 ( V_21 ) ;
F_36 ( V_35 ) ;
F_33 ( V_23 ) ;
F_33 ( V_22 ) ;
}
