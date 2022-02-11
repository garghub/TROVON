static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_2 ( V_2 -> V_6 , sizeof( * V_4 ) , V_7 ) ;
if ( ! V_4 ) {
F_3 ( V_2 -> V_6 , L_1 ) ;
return - V_8 ;
}
for ( V_5 = 0 ; V_5 < F_4 ( V_9 ) ; V_5 ++ ) {
if ( F_5 ( V_2 -> V_6 -> V_10 ,
V_9 [ V_5 ] . V_11 ) )
V_4 -> V_12 = V_9 [ V_5 ] . V_12 ;
}
V_2 -> V_4 = V_4 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_12 == V_13 ||
V_4 -> V_12 == V_14 )
V_2 -> V_15 /= ( V_4 -> V_16 + 1 ) ;
else if ( V_4 -> V_12 == V_17 )
V_2 -> V_15 /= V_18 ;
else if ( V_4 -> V_12 == V_19 )
V_2 -> V_15 /= V_20 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 * V_21 )
{
if ( F_8 ( F_9 ( V_2 , V_22 ) ) )
* V_21 |= V_23 ;
}
static void F_10 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_25 -> V_26 == V_27 )
F_11 ( V_2 , V_22 , V_4 -> V_28 ) ;
else
F_11 ( V_2 , V_22 , V_4 -> V_29 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_30 * V_31 = V_2 -> V_6 -> V_10 ;
T_1 V_26 [ 2 ] ;
T_1 div = 0 ;
int V_32 ;
F_13 ( V_31 , L_2 , & div ) ;
V_4 -> V_16 = div ;
V_32 = F_14 ( V_31 ,
L_3 , V_26 , 2 ) ;
if ( V_32 )
return V_32 ;
V_4 -> V_29 = F_15 ( V_26 [ 0 ] , V_26 [ 1 ] , div ) ;
V_32 = F_14 ( V_31 ,
L_4 , V_26 , 2 ) ;
if ( V_32 )
return V_32 ;
V_4 -> V_28 = F_15 ( V_26 [ 0 ] , V_26 [ 1 ] , div ) ;
return 0 ;
}
static int F_16 ( struct V_33 * V_34 )
{
const struct V_35 * V_36 ;
const struct V_37 * V_38 ;
V_38 = F_17 ( V_39 , V_34 -> V_6 . V_10 ) ;
V_36 = V_38 -> V_40 ;
return F_18 ( V_34 , V_36 ) ;
}
