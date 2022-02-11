static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 , V_7 ;
if ( ! V_5 -> V_8 )
return - V_9 ;
V_6 = V_5 -> V_10 + V_3 ;
F_3 ( & V_2 -> V_11 , L_1 , V_12 , V_6 ) ;
V_7 = ( ( 1 << V_5 -> V_13 ) - 1 ) <<
V_5 -> V_14 ;
V_6 <<= V_5 -> V_14 ;
F_4 ( V_5 -> V_15 , V_5 -> V_8 , V_6 , V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 , V_7 ;
if ( ! V_5 -> V_8 )
return - V_9 ;
V_6 = F_6 ( V_5 -> V_15 , V_5 -> V_8 ) ;
V_7 = ( ( 1 << V_5 -> V_13 ) - 1 ) <<
V_5 -> V_14 ;
V_6 = ( V_6 & V_7 ) >> V_5 -> V_14 ;
return V_6 - V_5 -> V_10 ;
}
static int T_2 F_7 ( struct V_16 * V_17 )
{
struct V_18 * V_11 = & V_17 -> V_11 ;
struct V_19 * V_20 = V_11 -> V_21 ;
struct V_22 * V_23 ;
struct V_1 * V_24 ;
struct V_4 * V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 = F_8 ( V_17 -> V_11 . V_30 ) ;
struct V_31 V_32 = { } ;
int V_33 = 0 ;
V_27 = F_9 ( V_11 , V_20 ) ;
V_25 = F_10 ( V_11 , sizeof( * V_25 ) , V_34 ) ;
if ( ! V_25 )
return - V_35 ;
V_25 -> V_27 = V_27 ;
V_25 -> V_36 = F_11 ( F_12 ( V_20 , L_2 , NULL ) ,
V_34 ) ;
V_23 = & V_25 -> V_23 ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_36 = V_25 -> V_36 ;
V_23 -> V_37 = & V_38 ;
V_23 -> type = V_39 ;
V_23 -> V_40 = V_41 ;
V_25 -> V_15 = V_29 ;
V_33 = F_13 ( V_20 , L_3 ,
& V_25 -> V_8 ) ;
if ( V_33 ) {
F_14 ( V_11 , L_4 ) ;
goto V_42;
}
V_33 = F_13 ( V_20 , L_5 ,
& V_25 -> V_13 ) ;
if ( V_33 ) {
F_14 ( V_11 , L_6 ) ;
goto V_42;
}
V_33 = F_13 ( V_20 , L_7 ,
& V_25 -> V_14 ) ;
if ( V_33 ) {
F_14 ( V_11 , L_8 ) ;
goto V_42;
}
V_33 = F_13 ( V_20 , L_9 ,
& V_25 -> V_10 ) ;
if ( V_33 ) {
F_14 ( V_11 , L_10 ) ;
goto V_42;
}
V_33 = F_13 ( V_20 , L_11 ,
& V_25 -> V_43 ) ;
if ( V_33 ) {
F_14 ( V_11 , L_12 ) ;
goto V_42;
}
V_33 = F_13 ( V_20 , L_13 ,
& V_25 -> V_44 ) ;
if ( V_33 ) {
F_14 ( V_11 , L_14 ) ;
goto V_42;
}
V_23 -> V_45 = ( V_25 -> V_44 - V_25 -> V_43 )
/ 25000 + 1 ;
V_23 -> V_46 = V_25 -> V_43 ;
V_23 -> V_47 = 25000 ;
V_32 . V_11 = & V_17 -> V_11 ;
V_32 . V_48 = V_27 ;
V_32 . V_49 = V_25 ;
V_32 . V_21 = V_17 -> V_11 . V_21 ;
V_24 = F_15 ( V_23 , & V_32 ) ;
if ( F_16 ( V_24 ) ) {
F_14 ( V_11 , L_15 ,
V_23 -> V_36 ) ;
V_33 = F_17 ( V_24 ) ;
goto V_42;
}
F_18 ( V_17 , V_24 ) ;
V_42:
if ( V_33 )
F_19 ( V_25 -> V_36 ) ;
return V_33 ;
}
static int T_3 F_20 ( struct V_16 * V_17 )
{
struct V_1 * V_24 = F_21 ( V_17 ) ;
struct V_4 * V_25 = F_2 ( V_24 ) ;
const char * V_36 = V_25 -> V_36 ;
F_22 ( V_24 ) ;
F_19 ( V_36 ) ;
return 0 ;
}
static int T_4 F_23 ( void )
{
return F_24 ( & V_50 ) ;
}
static void T_5 F_25 ( void )
{
F_26 ( & V_50 ) ;
}
