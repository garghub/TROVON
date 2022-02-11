static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
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
F_4 ( V_5 -> V_15 , V_5 -> V_8 ,
V_7 , V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 , V_7 ;
if ( ! V_5 -> V_8 )
return - V_9 ;
F_6 ( V_5 -> V_15 , V_5 -> V_8 , & V_6 ) ;
V_7 = ( ( 1 << V_5 -> V_13 ) - 1 ) <<
V_5 -> V_14 ;
V_6 = ( V_6 & V_7 ) >> V_5 -> V_14 ;
return V_6 - V_5 -> V_10 ;
}
static int T_2 F_7 ( struct V_16 * V_17 )
{
struct V_18 * V_11 = & V_17 -> V_11 ;
struct V_19 * V_20 = V_11 -> V_21 ;
struct V_19 * V_22 ;
struct V_23 * V_24 ;
struct V_1 * V_25 ;
struct V_4 * V_26 ;
struct V_27 * V_28 ;
struct V_29 V_30 = { } ;
int V_31 = 0 ;
V_28 = F_8 ( V_11 , V_20 ) ;
V_26 = F_9 ( V_11 , sizeof( * V_26 ) , V_32 ) ;
if ( ! V_26 )
return - V_33 ;
V_26 -> V_28 = V_28 ;
V_26 -> V_34 = F_10 ( F_11 ( V_20 , L_2 , NULL ) ,
V_32 ) ;
V_24 = & V_26 -> V_24 ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_24 -> V_34 = V_26 -> V_34 ;
V_24 -> V_35 = & V_36 ;
V_24 -> type = V_37 ;
V_24 -> V_38 = V_39 ;
V_22 = F_12 ( V_20 ) ;
if ( ! V_22 )
return - V_40 ;
V_26 -> V_15 = F_13 ( V_22 ) ;
F_14 ( V_22 ) ;
if ( F_15 ( V_26 -> V_15 ) )
return F_16 ( V_26 -> V_15 ) ;
V_31 = F_17 ( V_20 , L_3 ,
& V_26 -> V_8 ) ;
if ( V_31 ) {
F_18 ( V_11 , L_4 ) ;
goto V_41;
}
V_31 = F_17 ( V_20 , L_5 ,
& V_26 -> V_13 ) ;
if ( V_31 ) {
F_18 ( V_11 , L_6 ) ;
goto V_41;
}
V_31 = F_17 ( V_20 , L_7 ,
& V_26 -> V_14 ) ;
if ( V_31 ) {
F_18 ( V_11 , L_8 ) ;
goto V_41;
}
V_31 = F_17 ( V_20 , L_9 ,
& V_26 -> V_10 ) ;
if ( V_31 ) {
F_18 ( V_11 , L_10 ) ;
goto V_41;
}
V_31 = F_17 ( V_20 , L_11 ,
& V_26 -> V_42 ) ;
if ( V_31 ) {
F_18 ( V_11 , L_12 ) ;
goto V_41;
}
V_31 = F_17 ( V_20 , L_13 ,
& V_26 -> V_43 ) ;
if ( V_31 ) {
F_18 ( V_11 , L_14 ) ;
goto V_41;
}
V_24 -> V_44 = ( V_26 -> V_43 - V_26 -> V_42 )
/ 25000 + 1 ;
V_24 -> V_45 = V_26 -> V_42 ;
V_24 -> V_46 = 25000 ;
V_30 . V_11 = & V_17 -> V_11 ;
V_30 . V_47 = V_28 ;
V_30 . V_48 = V_26 ;
V_30 . V_21 = V_17 -> V_11 . V_21 ;
V_25 = F_19 ( V_24 , & V_30 ) ;
if ( F_15 ( V_25 ) ) {
F_18 ( V_11 , L_15 ,
V_24 -> V_34 ) ;
V_31 = F_16 ( V_25 ) ;
goto V_41;
}
F_20 ( V_17 , V_25 ) ;
V_41:
if ( V_31 )
F_21 ( V_26 -> V_34 ) ;
return V_31 ;
}
static int T_3 F_22 ( struct V_16 * V_17 )
{
struct V_1 * V_25 = F_23 ( V_17 ) ;
struct V_4 * V_26 = F_2 ( V_25 ) ;
const char * V_34 = V_26 -> V_34 ;
F_24 ( V_25 ) ;
F_21 ( V_34 ) ;
return 0 ;
}
static int T_4 F_25 ( void )
{
return F_26 ( & V_49 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_49 ) ;
}
