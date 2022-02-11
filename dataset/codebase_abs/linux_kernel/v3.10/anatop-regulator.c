static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_6 )
return - V_7 ;
return F_3 ( V_2 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_8 ,
unsigned int V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_10 ;
int V_11 = 0 ;
if ( V_5 -> V_12 && V_9 > V_8 ) {
F_5 ( V_5 -> V_13 , V_5 -> V_14 , & V_10 ) ;
V_10 = ( V_10 >> V_5 -> V_15 ) &
( ( 1 << V_5 -> V_12 ) - 1 ) ;
V_11 = ( V_9 - V_8 ) * ( V_16 <<
V_10 ) / V_17 + 1 ;
}
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_6 )
return - V_7 ;
return F_7 ( V_2 ) ;
}
static int F_8 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = & V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_22 * V_25 ;
struct V_26 * V_27 ;
struct V_1 * V_28 ;
struct V_4 * V_29 ;
struct V_30 * V_31 ;
struct V_32 V_33 = { } ;
int V_11 = 0 ;
V_31 = F_9 ( V_21 , V_23 ) ;
V_29 = F_10 ( V_21 , sizeof( * V_29 ) , V_34 ) ;
if ( ! V_29 )
return - V_35 ;
V_29 -> V_31 = V_31 ;
V_29 -> V_36 = F_11 ( F_12 ( V_23 , L_1 , NULL ) ,
V_34 ) ;
V_27 = & V_29 -> V_27 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_36 = V_29 -> V_36 ;
V_27 -> V_37 = & V_38 ;
V_27 -> type = V_39 ;
V_27 -> V_40 = V_41 ;
V_25 = F_13 ( V_23 ) ;
if ( ! V_25 )
return - V_42 ;
V_29 -> V_13 = F_14 ( V_25 ) ;
F_15 ( V_25 ) ;
if ( F_16 ( V_29 -> V_13 ) )
return F_17 ( V_29 -> V_13 ) ;
V_11 = F_18 ( V_23 , L_2 ,
& V_29 -> V_6 ) ;
if ( V_11 ) {
F_19 ( V_21 , L_3 ) ;
goto V_43;
}
V_11 = F_18 ( V_23 , L_4 ,
& V_29 -> V_44 ) ;
if ( V_11 ) {
F_19 ( V_21 , L_5 ) ;
goto V_43;
}
V_11 = F_18 ( V_23 , L_6 ,
& V_29 -> V_45 ) ;
if ( V_11 ) {
F_19 ( V_21 , L_7 ) ;
goto V_43;
}
V_11 = F_18 ( V_23 , L_8 ,
& V_29 -> V_46 ) ;
if ( V_11 ) {
F_19 ( V_21 , L_9 ) ;
goto V_43;
}
V_11 = F_18 ( V_23 , L_10 ,
& V_29 -> V_47 ) ;
if ( V_11 ) {
F_19 ( V_21 , L_11 ) ;
goto V_43;
}
V_11 = F_18 ( V_23 , L_12 ,
& V_29 -> V_48 ) ;
if ( V_11 ) {
F_19 ( V_21 , L_13 ) ;
goto V_43;
}
F_18 ( V_23 , L_14 ,
& V_29 -> V_14 ) ;
F_18 ( V_23 , L_15 ,
& V_29 -> V_12 ) ;
F_18 ( V_23 , L_16 ,
& V_29 -> V_15 ) ;
V_27 -> V_49 = ( V_29 -> V_48 - V_29 -> V_47 ) / 25000 + 1
+ V_29 -> V_46 ;
V_27 -> V_50 = V_29 -> V_47 ;
V_27 -> V_51 = 25000 ;
V_27 -> V_52 = V_29 -> V_46 ;
V_27 -> V_53 = V_29 -> V_6 ;
V_27 -> V_54 = ( ( 1 << V_29 -> V_44 ) - 1 ) <<
V_29 -> V_45 ;
V_33 . V_21 = & V_19 -> V_21 ;
V_33 . V_55 = V_31 ;
V_33 . V_56 = V_29 ;
V_33 . V_24 = V_19 -> V_21 . V_24 ;
V_33 . V_57 = V_29 -> V_13 ;
V_28 = F_20 ( V_27 , & V_33 ) ;
if ( F_16 ( V_28 ) ) {
F_19 ( V_21 , L_17 ,
V_27 -> V_36 ) ;
V_11 = F_17 ( V_28 ) ;
goto V_43;
}
F_21 ( V_19 , V_28 ) ;
V_43:
if ( V_11 )
F_22 ( V_29 -> V_36 ) ;
return V_11 ;
}
static int F_23 ( struct V_18 * V_19 )
{
struct V_1 * V_28 = F_24 ( V_19 ) ;
struct V_4 * V_29 = F_2 ( V_28 ) ;
const char * V_36 = V_29 -> V_36 ;
F_25 ( V_28 ) ;
F_22 ( V_36 ) ;
return 0 ;
}
static int T_2 F_26 ( void )
{
return F_27 ( & V_58 ) ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_58 ) ;
}
