static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 = V_12 | V_13 |
V_14 ;
int V_15 ;
V_15 = F_2 ( V_9 , V_11 ) ;
if ( V_15 < 0 ) {
F_3 ( V_16 L_1 ) ;
return V_15 ;
}
V_15 = F_2 ( V_10 , V_11 ) ;
if ( V_15 < 0 ) {
F_3 ( V_16 L_2 ) ;
return V_15 ;
}
V_15 = F_4 ( V_9 , 0 , 26000000 ,
V_17 ) ;
if ( V_15 < 0 ) {
F_3 ( V_16 L_3 ) ;
return V_15 ;
}
V_15 = F_4 ( V_10 , V_18 ,
256 * F_5 ( V_4 ) ,
V_17 ) ;
if ( V_15 < 0 ) {
F_3 ( V_16 L_4 ) ;
return V_15 ;
}
V_15 = F_6 ( V_10 , V_19 , 8 ) ;
if ( V_15 < 0 ) {
F_3 ( V_16 L_5 ) ;
return V_15 ;
}
return 0 ;
}
static int F_7 ( struct V_20 * V_21 ,
struct V_22 * V_23 , int V_24 )
{
if ( F_8 ( V_24 ) ) {
F_9 ( V_25 ) ;
F_10 ( 1 ) ;
F_11 ( V_26 , 1 ) ;
} else {
F_11 ( V_26 , 0 ) ;
F_10 ( 1 ) ;
F_12 ( V_25 ) ;
}
return 0 ;
}
static int F_13 ( struct V_20 * V_21 ,
struct V_22 * V_23 , int V_24 )
{
if ( F_8 ( V_24 ) )
F_11 ( V_27 , 1 ) ;
else
F_11 ( V_27 , 0 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_28 * V_29 = V_6 -> V_29 ;
struct V_30 * V_31 = & V_29 -> V_31 ;
int V_15 ;
F_15 ( V_31 , L_6 ) ;
F_15 ( V_31 , L_7 ) ;
F_15 ( V_31 , L_8 ) ;
F_15 ( V_31 , L_9 ) ;
F_15 ( V_31 , L_10 ) ;
F_15 ( V_31 , L_11 ) ;
F_15 ( V_31 , L_12 ) ;
F_15 ( V_31 , L_13 ) ;
F_15 ( V_31 , L_14 ) ;
F_15 ( V_31 , L_15 ) ;
V_15 = F_16 ( V_31 , V_32 ,
F_17 ( V_32 ) ) ;
if ( V_15 < 0 )
return V_15 ;
F_18 ( V_31 , V_33 ,
F_17 ( V_33 ) ) ;
return F_19 ( V_31 ) ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_28 * V_29 = V_6 -> V_29 ;
struct V_30 * V_31 = & V_29 -> V_31 ;
int V_15 ;
F_15 ( V_31 , L_16 ) ;
F_15 ( V_31 , L_17 ) ;
F_15 ( V_31 , L_18 ) ;
F_15 ( V_31 , L_19 ) ;
V_15 = F_16 ( V_31 , V_34 ,
F_17 ( V_34 ) ) ;
if ( V_15 < 0 )
return V_15 ;
F_18 ( V_31 , V_35 ,
F_17 ( V_35 ) ) ;
return F_19 ( V_31 ) ;
}
static int T_1 F_21 ( void )
{
int V_15 ;
if ( ! F_22 () )
return - V_36 ;
F_23 ( L_20 ) ;
V_15 = F_24 ( V_26 , L_21 ) ;
if ( V_15 ) {
F_3 ( V_16 L_22 ) ;
return V_15 ;
}
V_15 = F_25 ( V_26 , 0 ) ;
if ( V_15 ) {
F_3 ( V_16 L_23 ) ;
goto V_37;
}
V_15 = F_24 ( V_27 , L_24 ) ;
if ( V_15 ) {
F_3 ( V_16 L_25 ) ;
goto V_37;
}
V_15 = F_25 ( V_27 , 0 ) ;
if ( V_15 ) {
F_3 ( V_16 L_26 ) ;
goto V_38;
}
V_39 = F_26 ( L_27 , - 1 ) ;
if ( V_39 == NULL ) {
F_3 ( V_16 L_28 ) ;
V_15 = - V_40 ;
goto V_38;
}
F_27 ( V_39 , & V_41 ) ;
V_15 = F_28 ( V_39 ) ;
if ( V_15 ) {
F_3 ( V_16 L_29 ) ;
goto V_42;
}
V_25 = F_29 ( & V_39 -> V_43 , L_30 ) ;
if ( F_30 ( V_25 ) ) {
F_3 ( V_16 L_31 ,
F_31 ( & V_39 -> V_43 ) ,
F_32 ( V_25 ) ) ;
V_15 = F_32 ( V_25 ) ;
goto V_44;
}
return 0 ;
V_44:
F_33 ( V_39 ) ;
V_42:
F_34 ( V_39 ) ;
V_38:
F_35 ( V_27 ) ;
V_37:
F_35 ( V_26 ) ;
return V_15 ;
}
static void T_2 F_36 ( void )
{
F_37 ( V_25 ) ;
F_38 ( V_39 ) ;
F_35 ( V_27 ) ;
F_35 ( V_26 ) ;
}
