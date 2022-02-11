static bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 &= 0x7f ;
return V_3 == V_6 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_6 , V_2 -> V_4 + V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_7 , V_2 -> V_4 + V_8 ) ;
}
static int F_7 ( struct V_9 * V_10 )
{
T_1 V_11 ;
struct V_1 * V_2 = F_8 ( V_10 ) ;
if ( ! V_2 -> V_12 )
return 0 ;
F_9 ( V_2 -> V_12 , F_10 ( V_2 -> V_13 ) , & V_11 ) ;
V_11 = ( V_11 >> V_14 ) & V_15 ;
if ( V_11 < V_16 )
return 0 ;
return 1 ;
}
static void F_11 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_8 ( V_10 ) ;
T_1 V_17 , V_13 [ 2 ] ;
V_2 -> V_12 = F_12 ( V_10 -> V_18 -> V_19 ,
L_1 ) ;
if ( F_13 ( V_2 -> V_12 ) ) {
F_14 ( V_10 -> V_18 , L_2 ) ;
V_2 -> V_12 = NULL ;
return;
}
if ( F_15 ( V_10 -> V_18 -> V_19 ,
L_1 , V_13 , 2 ) ) {
V_2 -> V_12 = NULL ;
return;
}
V_2 -> V_13 = V_13 [ 1 ] ;
F_16 ( V_10 ) ;
V_17 = F_17 ( V_2 -> V_4 + V_20 ) ;
V_17 &= 0xffff ;
F_18 ( V_17 , V_2 -> V_4 + V_20 ) ;
}
static int F_19 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_8 ( V_10 ) ;
T_1 V_11 ;
V_11 = ( F_17 ( V_2 -> V_21 + V_22 ) >>
V_2 -> V_23 -> V_24 ) &
V_15 ;
if ( V_11 < V_16 )
return 0 ;
return 1 ;
}
static void F_20 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_8 ( V_10 ) ;
F_18 ( 1 , V_2 -> V_4 + V_25 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 ) ;
F_18 ( 0 , V_2 -> V_4 + V_25 ) ;
}
static int F_21 ( struct V_9 * V_10 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_28 * V_30 = V_10 -> V_18 -> V_19 ;
V_29 = F_22 ( V_30 , L_3 , 0 ) ;
if ( ! V_29 ) {
F_14 ( V_10 -> V_18 , L_4 ) ;
return - V_31 ;
}
return 0 ;
}
static int T_2 F_23 ( struct V_9 * V_10 ,
struct V_32 * V_33 )
{
int V_34 ;
struct V_1 * V_2 = F_8 ( V_10 ) ;
V_10 -> V_18 = & V_33 -> V_18 ;
V_10 -> V_35 = V_2 -> V_4 ;
V_10 -> V_36 = V_2 -> V_23 -> V_36 ;
V_34 = F_24 ( V_10 ) ;
if ( V_34 ) {
F_14 ( V_10 -> V_18 , L_5 ) ;
return V_34 ;
}
return 0 ;
}
static int T_2 F_25 ( struct V_32 * V_33 )
{
const struct V_37 * V_38 ;
struct V_1 * V_2 ;
struct V_39 * V_35 ;
int V_34 ;
V_38 = F_26 ( V_40 , & V_33 -> V_18 ) ;
if ( ! V_38 )
return - V_41 ;
V_2 = F_27 ( & V_33 -> V_18 , sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
V_35 = F_28 ( V_33 , V_44 , L_6 ) ;
V_2 -> V_4 = F_29 ( & V_33 -> V_18 , V_35 ) ;
if ( F_13 ( V_2 -> V_4 ) ) {
F_14 ( & V_33 -> V_18 , L_7 ) ;
return F_30 ( V_2 -> V_4 ) ;
}
V_2 -> V_23 = V_38 -> V_45 ;
V_2 -> V_21 = V_2 -> V_4 + V_2 -> V_23 -> V_46 ;
if ( ! F_1 ( V_2 ) )
return - V_41 ;
V_34 = F_23 ( & V_2 -> V_10 , V_33 ) ;
if ( V_34 < 0 )
return V_34 ;
F_31 ( V_33 , V_2 ) ;
return 0 ;
}
