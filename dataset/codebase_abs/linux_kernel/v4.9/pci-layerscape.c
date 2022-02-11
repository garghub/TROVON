static bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 . V_5 + V_6 ) ;
V_3 &= 0x7f ;
return V_3 == V_7 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_7 , V_2 -> V_4 . V_5 + V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_8 , V_2 -> V_4 . V_5 + V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_10 ;
V_10 = F_8 ( V_2 -> V_4 . V_5 + V_11 ) ;
V_10 &= 0xDFFFFFFF ;
F_9 ( V_10 , V_2 -> V_4 . V_5 + V_11 ) ;
}
static int F_10 ( struct V_12 * V_4 )
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
static void F_14 ( struct V_12 * V_4 )
{
struct V_19 * V_20 = V_4 -> V_20 ;
struct V_1 * V_2 = F_11 ( V_4 ) ;
T_1 V_15 [ 2 ] ;
V_2 -> V_14 = F_15 ( V_20 -> V_21 ,
L_1 ) ;
if ( F_16 ( V_2 -> V_14 ) ) {
F_17 ( V_20 , L_2 ) ;
V_2 -> V_14 = NULL ;
return;
}
if ( F_18 ( V_20 -> V_21 ,
L_1 , V_15 , 2 ) ) {
V_2 -> V_14 = NULL ;
return;
}
V_2 -> V_15 = V_15 [ 1 ] ;
F_19 ( V_4 ) ;
F_7 ( V_2 ) ;
}
static int F_20 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
T_1 V_13 ;
V_13 = ( F_8 ( V_2 -> V_22 + V_23 ) >>
V_2 -> V_24 -> V_25 ) &
V_17 ;
if ( V_13 < V_18 )
return 0 ;
return 1 ;
}
static void F_21 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_9 ( 1 , V_2 -> V_4 . V_5 + V_26 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 ) ;
F_7 ( V_2 ) ;
F_9 ( 0 , V_2 -> V_4 . V_5 + V_26 ) ;
}
static int F_22 ( struct V_12 * V_4 ,
struct V_27 * V_28 )
{
struct V_19 * V_20 = V_4 -> V_20 ;
struct V_29 * V_30 = V_20 -> V_21 ;
struct V_29 * V_31 ;
V_31 = F_23 ( V_30 , L_3 , 0 ) ;
if ( ! V_31 ) {
F_17 ( V_20 , L_4 ) ;
return - V_32 ;
}
return 0 ;
}
static int T_2 F_24 ( struct V_1 * V_2 )
{
struct V_12 * V_4 = & V_2 -> V_4 ;
struct V_19 * V_20 = V_4 -> V_20 ;
int V_33 ;
V_33 = F_25 ( V_4 ) ;
if ( V_33 ) {
F_17 ( V_20 , L_5 ) ;
return V_33 ;
}
return 0 ;
}
static int T_2 F_26 ( struct V_34 * V_35 )
{
struct V_19 * V_20 = & V_35 -> V_20 ;
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
struct V_12 * V_4 ;
struct V_38 * V_5 ;
int V_33 ;
V_37 = F_27 ( V_39 , V_20 ) ;
if ( ! V_37 )
return - V_40 ;
V_2 = F_28 ( V_20 , sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
V_4 = & V_2 -> V_4 ;
V_4 -> V_20 = V_20 ;
V_2 -> V_24 = V_37 -> V_43 ;
V_4 -> V_44 = V_2 -> V_24 -> V_44 ;
V_5 = F_29 ( V_35 , V_45 , L_6 ) ;
V_2 -> V_4 . V_5 = F_30 ( V_20 , V_5 ) ;
if ( F_16 ( V_2 -> V_4 . V_5 ) ) {
F_17 ( V_20 , L_7 ) ;
return F_31 ( V_2 -> V_4 . V_5 ) ;
}
V_2 -> V_22 = V_2 -> V_4 . V_5 + V_2 -> V_24 -> V_46 ;
if ( ! F_1 ( V_2 ) )
return - V_40 ;
V_33 = F_24 ( V_2 ) ;
if ( V_33 < 0 )
return V_33 ;
return 0 ;
}
