static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_6 )
return - V_7 ;
return F_3 ( V_2 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_6 )
return - V_7 ;
return F_5 ( V_2 ) ;
}
static int F_6 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_12 * V_15 ;
struct V_16 * V_17 ;
struct V_1 * V_18 ;
struct V_4 * V_19 ;
struct V_20 * V_21 ;
struct V_22 V_23 = { } ;
int V_24 = 0 ;
V_21 = F_7 ( V_11 , V_13 ) ;
V_19 = F_8 ( V_11 , sizeof( * V_19 ) , V_25 ) ;
if ( ! V_19 )
return - V_26 ;
V_19 -> V_21 = V_21 ;
V_19 -> V_27 = F_9 ( F_10 ( V_13 , L_1 , NULL ) ,
V_25 ) ;
V_17 = & V_19 -> V_17 ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
V_17 -> V_27 = V_19 -> V_27 ;
V_17 -> V_28 = & V_29 ;
V_17 -> type = V_30 ;
V_17 -> V_31 = V_32 ;
V_15 = F_11 ( V_13 ) ;
if ( ! V_15 )
return - V_33 ;
V_19 -> V_34 = F_12 ( V_15 ) ;
F_13 ( V_15 ) ;
if ( F_14 ( V_19 -> V_34 ) )
return F_15 ( V_19 -> V_34 ) ;
V_24 = F_16 ( V_13 , L_2 ,
& V_19 -> V_6 ) ;
if ( V_24 ) {
F_17 ( V_11 , L_3 ) ;
goto V_35;
}
V_24 = F_16 ( V_13 , L_4 ,
& V_19 -> V_36 ) ;
if ( V_24 ) {
F_17 ( V_11 , L_5 ) ;
goto V_35;
}
V_24 = F_16 ( V_13 , L_6 ,
& V_19 -> V_37 ) ;
if ( V_24 ) {
F_17 ( V_11 , L_7 ) ;
goto V_35;
}
V_24 = F_16 ( V_13 , L_8 ,
& V_19 -> V_38 ) ;
if ( V_24 ) {
F_17 ( V_11 , L_9 ) ;
goto V_35;
}
V_24 = F_16 ( V_13 , L_10 ,
& V_19 -> V_39 ) ;
if ( V_24 ) {
F_17 ( V_11 , L_11 ) ;
goto V_35;
}
V_24 = F_16 ( V_13 , L_12 ,
& V_19 -> V_40 ) ;
if ( V_24 ) {
F_17 ( V_11 , L_13 ) ;
goto V_35;
}
V_17 -> V_41 = ( V_19 -> V_40 - V_19 -> V_39 ) / 25000 + 1
+ V_19 -> V_38 ;
V_17 -> V_42 = V_19 -> V_39 ;
V_17 -> V_43 = 25000 ;
V_17 -> V_44 = V_19 -> V_38 ;
V_17 -> V_45 = V_19 -> V_6 ;
V_17 -> V_46 = ( ( 1 << V_19 -> V_36 ) - 1 ) <<
V_19 -> V_37 ;
V_23 . V_11 = & V_9 -> V_11 ;
V_23 . V_47 = V_21 ;
V_23 . V_48 = V_19 ;
V_23 . V_14 = V_9 -> V_11 . V_14 ;
V_23 . V_49 = V_19 -> V_34 ;
V_18 = F_18 ( V_17 , & V_23 ) ;
if ( F_14 ( V_18 ) ) {
F_17 ( V_11 , L_14 ,
V_17 -> V_27 ) ;
V_24 = F_15 ( V_18 ) ;
goto V_35;
}
F_19 ( V_9 , V_18 ) ;
V_35:
if ( V_24 )
F_20 ( V_19 -> V_27 ) ;
return V_24 ;
}
static int F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_18 = F_22 ( V_9 ) ;
struct V_4 * V_19 = F_2 ( V_18 ) ;
const char * V_27 = V_19 -> V_27 ;
F_23 ( V_18 ) ;
F_20 ( V_27 ) ;
return 0 ;
}
static int T_1 F_24 ( void )
{
return F_25 ( & V_50 ) ;
}
static void T_2 F_26 ( void )
{
F_27 ( & V_50 ) ;
}
