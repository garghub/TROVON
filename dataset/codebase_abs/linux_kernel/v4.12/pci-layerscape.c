static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 ;
V_5 = F_2 ( V_4 -> V_6 + V_7 ) ;
V_5 &= 0x7f ;
return V_5 == V_8 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_4 ( V_8 , V_4 -> V_6 + V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_6 ( V_9 , V_4 -> V_6 + V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_11 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_11 = F_8 ( V_4 -> V_6 + V_12 ) ;
V_11 &= 0xDFFFFFFF ;
F_9 ( V_11 , V_4 -> V_6 + V_12 ) ;
}
static int F_10 ( struct V_3 * V_4 )
{
T_1 V_13 ;
struct V_1 * V_2 = F_11 ( V_4 ) ;
if ( ! V_2 -> V_14 )
return 0 ;
F_12 ( V_2 -> V_14 , F_13 ( V_2 -> V_15 ) , & V_13 ) ;
V_13 = ( V_13 >> V_16 ) & V_17 ;
if ( V_13 < V_18 )
return 0 ;
return 1 ;
}
static void F_14 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_15 ( V_20 ) ;
struct V_1 * V_2 = F_11 ( V_4 ) ;
struct V_21 * V_22 = V_4 -> V_22 ;
T_1 V_15 [ 2 ] ;
V_2 -> V_14 = F_16 ( V_22 -> V_23 ,
L_1 ) ;
if ( F_17 ( V_2 -> V_14 ) ) {
F_18 ( V_22 , L_2 ) ;
V_2 -> V_14 = NULL ;
return;
}
if ( F_19 ( V_22 -> V_23 ,
L_1 , V_15 , 2 ) ) {
V_2 -> V_14 = NULL ;
return;
}
V_2 -> V_15 = V_15 [ 1 ] ;
F_20 ( V_20 ) ;
F_7 ( V_2 ) ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
T_1 V_13 ;
V_13 = ( F_8 ( V_2 -> V_24 + V_2 -> V_25 -> V_26 ) >>
V_2 -> V_25 -> V_27 ) &
V_17 ;
if ( V_13 < V_18 )
return 0 ;
return 1 ;
}
static void F_22 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_15 ( V_20 ) ;
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_9 ( 1 , V_4 -> V_6 + V_28 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 ) ;
F_7 ( V_2 ) ;
F_9 ( 0 , V_4 -> V_6 + V_28 ) ;
}
static int F_23 ( struct V_19 * V_20 ,
struct V_29 * V_30 )
{
struct V_3 * V_4 = F_15 ( V_20 ) ;
struct V_21 * V_22 = V_4 -> V_22 ;
struct V_31 * V_32 = V_22 -> V_23 ;
struct V_31 * V_33 ;
V_33 = F_24 ( V_32 , L_3 , 0 ) ;
if ( ! V_33 ) {
F_18 ( V_22 , L_4 ) ;
return - V_34 ;
}
return 0 ;
}
static int T_2 F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_19 * V_20 = & V_4 -> V_20 ;
struct V_21 * V_22 = V_4 -> V_22 ;
int V_35 ;
V_20 -> V_36 = V_2 -> V_25 -> V_36 ;
V_35 = F_26 ( V_20 ) ;
if ( V_35 ) {
F_18 ( V_22 , L_5 ) ;
return V_35 ;
}
return 0 ;
}
static int T_2 F_27 ( struct V_37 * V_38 )
{
struct V_21 * V_22 = & V_38 -> V_22 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_39 * V_6 ;
int V_35 ;
V_2 = F_28 ( V_22 , sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return - V_41 ;
V_4 = F_28 ( V_22 , sizeof( * V_4 ) , V_40 ) ;
if ( ! V_4 )
return - V_41 ;
V_2 -> V_25 = F_29 ( V_22 ) ;
V_4 -> V_22 = V_22 ;
V_4 -> V_36 = V_2 -> V_25 -> V_42 ;
V_2 -> V_4 = V_4 ;
V_6 = F_30 ( V_38 , V_43 , L_6 ) ;
V_4 -> V_6 = F_31 ( V_22 , V_6 ) ;
if ( F_17 ( V_4 -> V_6 ) )
return F_32 ( V_4 -> V_6 ) ;
V_2 -> V_24 = V_4 -> V_6 + V_2 -> V_25 -> V_44 ;
if ( ! F_1 ( V_2 ) )
return - V_45 ;
F_33 ( V_38 , V_2 ) ;
V_35 = F_25 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
return 0 ;
}
