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
T_1 V_9 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_9 = F_6 ( V_4 -> V_6 + V_10 ) ;
V_9 &= 0xDFFFFFFF ;
F_7 ( V_9 , V_4 -> V_6 + V_10 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
F_9 ( V_2 -> V_4 , V_13 , V_11 ) ;
}
static int F_10 ( struct V_3 * V_4 )
{
T_1 V_14 ;
struct V_1 * V_2 = F_11 ( V_4 ) ;
if ( ! V_2 -> V_15 )
return 0 ;
F_12 ( V_2 -> V_15 , F_13 ( V_2 -> V_16 ) , & V_14 ) ;
V_14 = ( V_14 >> V_17 ) & V_18 ;
if ( V_14 < V_19 )
return 0 ;
return 1 ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
T_1 V_14 ;
V_14 = ( F_6 ( V_2 -> V_20 + V_2 -> V_21 -> V_22 ) >>
V_2 -> V_21 -> V_23 ) &
V_18 ;
if ( V_14 < V_19 )
return 0 ;
return 1 ;
}
static int F_15 ( struct V_24 * V_25 )
{
struct V_3 * V_4 = F_16 ( V_25 ) ;
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_8 ( V_2 ) ;
F_17 ( V_4 ) ;
F_3 ( V_2 ) ;
F_18 ( V_4 ) ;
F_5 ( V_2 ) ;
F_19 ( V_25 ) ;
return 0 ;
}
static int F_20 ( struct V_24 * V_25 )
{
struct V_3 * V_4 = F_16 ( V_25 ) ;
struct V_1 * V_2 = F_11 ( V_4 ) ;
struct V_26 * V_27 = V_4 -> V_27 ;
T_1 V_16 [ 2 ] ;
int V_28 ;
V_2 -> V_15 = F_21 ( V_27 -> V_29 ,
L_1 ) ;
if ( F_22 ( V_2 -> V_15 ) ) {
V_28 = F_23 ( V_2 -> V_15 ) ;
F_24 ( V_27 , L_2 ) ;
V_2 -> V_15 = NULL ;
return V_28 ;
}
if ( F_25 ( V_27 -> V_29 ,
L_1 , V_16 , 2 ) ) {
V_2 -> V_15 = NULL ;
return - V_30 ;
}
V_2 -> V_16 = V_16 [ 1 ] ;
return F_15 ( V_25 ) ;
}
static int F_26 ( struct V_24 * V_25 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_16 ( V_25 ) ;
struct V_26 * V_27 = V_4 -> V_27 ;
struct V_33 * V_34 = V_27 -> V_29 ;
struct V_33 * V_35 ;
V_35 = F_27 ( V_34 , L_3 , 0 ) ;
if ( ! V_35 ) {
F_24 ( V_27 , L_4 ) ;
return - V_30 ;
}
return 0 ;
}
static int T_2 F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_24 * V_25 = & V_4 -> V_25 ;
struct V_26 * V_27 = V_4 -> V_27 ;
int V_28 ;
V_25 -> V_36 = V_2 -> V_21 -> V_36 ;
V_28 = F_29 ( V_25 ) ;
if ( V_28 ) {
F_24 ( V_27 , L_5 ) ;
return V_28 ;
}
return 0 ;
}
static int T_2 F_30 ( struct V_37 * V_38 )
{
struct V_26 * V_27 = & V_38 -> V_27 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_39 * V_6 ;
int V_28 ;
V_2 = F_31 ( V_27 , sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return - V_41 ;
V_4 = F_31 ( V_27 , sizeof( * V_4 ) , V_40 ) ;
if ( ! V_4 )
return - V_41 ;
V_2 -> V_21 = F_32 ( V_27 ) ;
V_4 -> V_27 = V_27 ;
V_4 -> V_36 = V_2 -> V_21 -> V_42 ;
V_2 -> V_4 = V_4 ;
V_6 = F_33 ( V_38 , V_43 , L_6 ) ;
V_4 -> V_6 = F_34 ( V_27 , V_6 ) ;
if ( F_22 ( V_4 -> V_6 ) )
return F_23 ( V_4 -> V_6 ) ;
V_2 -> V_20 = V_4 -> V_6 + V_2 -> V_21 -> V_44 ;
if ( ! F_1 ( V_2 ) )
return - V_45 ;
F_35 ( V_38 , V_2 ) ;
V_28 = F_28 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
return 0 ;
}
