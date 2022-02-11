static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 , unsigned * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 , V_9 , V_10 ;
int V_11 ;
V_11 = V_3 ;
F_3 ( & V_2 -> V_12 , L_1 , V_13 ,
V_11 , V_7 -> V_14 ,
V_7 -> V_15 ) ;
if ( V_11 < V_7 -> V_14 ) {
if ( V_4 > V_7 -> V_14 )
V_11 = V_7 -> V_14 ;
else
return - V_16 ;
}
if ( ! V_7 -> V_17 )
return - V_18 ;
V_9 = F_4 ( V_11 - V_7 -> V_14 , 25000 ) ;
if ( V_9 * 25000 + V_7 -> V_14 > V_7 -> V_15 )
return - V_16 ;
V_8 = V_7 -> V_19 + V_9 ;
* V_5 = V_9 ;
F_3 ( & V_2 -> V_12 , L_2 , V_13 , V_8 ) ;
V_10 = ( ( 1 << V_7 -> V_20 ) - 1 ) <<
V_7 -> V_21 ;
V_8 <<= V_7 -> V_21 ;
F_5 ( V_7 -> V_22 , V_7 -> V_17 , V_8 , V_10 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 ;
if ( ! V_7 -> V_17 )
return - V_18 ;
V_8 = F_7 ( V_7 -> V_22 , V_7 -> V_17 ) ;
V_8 = ( V_8 & ( ( 1 << V_7 -> V_20 ) - 1 ) ) >>
V_7 -> V_21 ;
return V_8 - V_7 -> V_19 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_11 ;
V_11 = V_7 -> V_14 + V_5 * 25000 ;
F_3 ( & V_2 -> V_12 , L_3 , V_11 , V_5 ) ;
return V_11 ;
}
static int T_2 F_9 ( struct V_23 * V_24 )
{
struct V_25 * V_12 = & V_24 -> V_12 ;
struct V_26 * V_27 = V_12 -> V_28 ;
struct V_29 * V_30 ;
struct V_1 * V_31 ;
struct V_6 * V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 = F_10 ( V_24 -> V_12 . V_37 ) ;
struct V_38 V_39 = { } ;
int V_40 = 0 ;
V_34 = F_11 ( V_12 , V_27 ) ;
V_32 = F_12 ( V_12 , sizeof( * V_32 ) , V_41 ) ;
if ( ! V_32 )
return - V_42 ;
V_32 -> V_34 = V_34 ;
V_32 -> V_43 = F_13 ( F_14 ( V_27 , L_4 , NULL ) ,
V_41 ) ;
V_30 = & V_32 -> V_30 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_43 = V_32 -> V_43 ;
V_30 -> V_44 = & V_45 ;
V_30 -> type = V_46 ;
V_30 -> V_47 = V_48 ;
V_32 -> V_22 = V_36 ;
V_40 = F_15 ( V_27 , L_5 ,
& V_32 -> V_17 ) ;
if ( V_40 ) {
F_16 ( V_12 , L_6 ) ;
goto V_49;
}
V_40 = F_15 ( V_27 , L_7 ,
& V_32 -> V_20 ) ;
if ( V_40 ) {
F_16 ( V_12 , L_8 ) ;
goto V_49;
}
V_40 = F_15 ( V_27 , L_9 ,
& V_32 -> V_21 ) ;
if ( V_40 ) {
F_16 ( V_12 , L_10 ) ;
goto V_49;
}
V_40 = F_15 ( V_27 , L_11 ,
& V_32 -> V_19 ) ;
if ( V_40 ) {
F_16 ( V_12 , L_12 ) ;
goto V_49;
}
V_40 = F_15 ( V_27 , L_13 ,
& V_32 -> V_14 ) ;
if ( V_40 ) {
F_16 ( V_12 , L_14 ) ;
goto V_49;
}
V_40 = F_15 ( V_27 , L_15 ,
& V_32 -> V_15 ) ;
if ( V_40 ) {
F_16 ( V_12 , L_16 ) ;
goto V_49;
}
V_30 -> V_50 = ( V_32 -> V_15 - V_32 -> V_14 )
/ 25000 + 1 ;
V_39 . V_12 = & V_24 -> V_12 ;
V_39 . V_51 = V_34 ;
V_39 . V_52 = V_32 ;
V_39 . V_28 = V_24 -> V_12 . V_28 ;
V_31 = F_17 ( V_30 , & V_39 ) ;
if ( F_18 ( V_31 ) ) {
F_16 ( V_12 , L_17 ,
V_30 -> V_43 ) ;
V_40 = F_19 ( V_31 ) ;
goto V_49;
}
F_20 ( V_24 , V_31 ) ;
V_49:
if ( V_40 )
F_21 ( V_32 -> V_43 ) ;
return V_40 ;
}
static int T_3 F_22 ( struct V_23 * V_24 )
{
struct V_1 * V_31 = F_23 ( V_24 ) ;
struct V_6 * V_32 = F_2 ( V_31 ) ;
const char * V_43 = V_32 -> V_43 ;
F_24 ( V_31 ) ;
F_21 ( V_43 ) ;
return 0 ;
}
static int T_4 F_25 ( void )
{
return F_26 ( & V_53 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_53 ) ;
}
