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
V_29 -> V_36 = F_11 ( V_23 , L_1 , NULL ) ;
V_27 = & V_29 -> V_27 ;
V_27 -> V_36 = V_29 -> V_36 ;
V_27 -> V_37 = & V_38 ;
V_27 -> type = V_39 ;
V_27 -> V_40 = V_41 ;
V_25 = F_12 ( V_23 ) ;
if ( ! V_25 )
return - V_42 ;
V_29 -> V_13 = F_13 ( V_25 ) ;
F_14 ( V_25 ) ;
if ( F_15 ( V_29 -> V_13 ) )
return F_16 ( V_29 -> V_13 ) ;
V_11 = F_17 ( V_23 , L_2 ,
& V_29 -> V_6 ) ;
if ( V_11 ) {
F_18 ( V_21 , L_3 ) ;
return V_11 ;
}
V_11 = F_17 ( V_23 , L_4 ,
& V_29 -> V_43 ) ;
if ( V_11 ) {
F_18 ( V_21 , L_5 ) ;
return V_11 ;
}
V_11 = F_17 ( V_23 , L_6 ,
& V_29 -> V_44 ) ;
if ( V_11 ) {
F_18 ( V_21 , L_7 ) ;
return V_11 ;
}
V_11 = F_17 ( V_23 , L_8 ,
& V_29 -> V_45 ) ;
if ( V_11 ) {
F_18 ( V_21 , L_9 ) ;
return V_11 ;
}
V_11 = F_17 ( V_23 , L_10 ,
& V_29 -> V_46 ) ;
if ( V_11 ) {
F_18 ( V_21 , L_11 ) ;
return V_11 ;
}
V_11 = F_17 ( V_23 , L_12 ,
& V_29 -> V_47 ) ;
if ( V_11 ) {
F_18 ( V_21 , L_13 ) ;
return V_11 ;
}
F_17 ( V_23 , L_14 ,
& V_29 -> V_14 ) ;
F_17 ( V_23 , L_15 ,
& V_29 -> V_12 ) ;
F_17 ( V_23 , L_16 ,
& V_29 -> V_15 ) ;
V_27 -> V_48 = ( V_29 -> V_47 - V_29 -> V_46 ) / 25000 + 1
+ V_29 -> V_45 ;
V_27 -> V_49 = V_29 -> V_46 ;
V_27 -> V_50 = 25000 ;
V_27 -> V_51 = V_29 -> V_45 ;
V_27 -> V_52 = V_29 -> V_6 ;
V_27 -> V_53 = ( ( 1 << V_29 -> V_43 ) - 1 ) <<
V_29 -> V_44 ;
V_33 . V_21 = & V_19 -> V_21 ;
V_33 . V_54 = V_31 ;
V_33 . V_55 = V_29 ;
V_33 . V_24 = V_19 -> V_21 . V_24 ;
V_33 . V_56 = V_29 -> V_13 ;
V_28 = F_19 ( V_21 , V_27 , & V_33 ) ;
if ( F_15 ( V_28 ) ) {
F_18 ( V_21 , L_17 ,
V_27 -> V_36 ) ;
return F_16 ( V_28 ) ;
}
F_20 ( V_19 , V_28 ) ;
return 0 ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_57 ) ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_57 ) ;
}
