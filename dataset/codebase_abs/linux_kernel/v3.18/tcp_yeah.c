static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
V_5 -> V_6 = 0 ;
V_5 -> V_7 = 0 ;
V_5 -> V_8 = 2 ;
V_4 -> V_9 = F_5 ( V_10 , V_4 -> V_9 , 0xffffffff / 128 ) ;
}
static void F_6 ( struct V_1 * V_2 , V_10 V_11 , T_1 V_12 )
{
const struct V_13 * V_14 = F_7 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
if ( V_14 -> V_15 == V_16 )
V_5 -> V_11 = V_11 ;
F_8 ( V_2 , V_11 , V_12 ) ;
}
static void F_9 ( struct V_1 * V_2 , V_10 V_17 , V_10 V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
if ( ! F_10 ( V_2 ) )
return;
if ( V_4 -> V_19 <= V_4 -> V_20 )
F_11 ( V_4 , V_18 ) ;
else if ( ! V_5 -> V_6 ) {
V_4 -> V_21 += V_5 -> V_11 ;
if ( V_4 -> V_21 > F_12 ( V_4 -> V_19 , V_22 ) ) {
if ( V_4 -> V_19 < V_4 -> V_9 )
V_4 -> V_19 ++ ;
V_4 -> V_21 = 0 ;
}
V_5 -> V_11 = 1 ;
} else {
F_13 ( V_4 , V_4 -> V_19 ) ;
}
if ( F_14 ( V_17 , V_5 -> V_23 . V_24 ) ) {
if ( V_5 -> V_23 . V_25 > 2 ) {
V_10 V_26 , V_27 ;
T_2 V_28 ;
V_26 = V_5 -> V_23 . V_29 ;
V_28 = V_4 -> V_19 ;
V_28 *= V_26 - V_5 -> V_23 . V_30 ;
F_15 ( V_28 , V_26 ) ;
V_27 = V_28 ;
if ( V_27 > V_31 ||
V_26 - V_5 -> V_23 . V_30 > ( V_5 -> V_23 . V_30 / V_32 ) ) {
if ( V_27 > V_31 &&
V_4 -> V_19 > V_5 -> V_8 ) {
V_10 V_33 = F_12 ( V_27 / V_34 ,
V_4 -> V_19 >> V_35 ) ;
V_4 -> V_19 -= V_33 ;
V_4 -> V_19 = F_16 ( V_4 -> V_19 ,
V_5 -> V_8 ) ;
V_4 -> V_20 = V_4 -> V_19 ;
}
if ( V_5 -> V_8 <= 2 )
V_5 -> V_8 = F_16 ( V_4 -> V_19 >> 1 , 2U ) ;
else
V_5 -> V_8 ++ ;
V_5 -> V_6 = F_12 ( V_5 -> V_6 + 1 ,
0xffffffU ) ;
} else {
V_5 -> V_36 ++ ;
if ( V_5 -> V_36 > V_37 ) {
V_5 -> V_8 = 2 ;
V_5 -> V_36 = 0 ;
}
V_5 -> V_6 = 0 ;
}
V_5 -> V_7 = V_27 ;
}
V_5 -> V_23 . V_38 = V_5 -> V_23 . V_24 ;
V_5 -> V_23 . V_24 = V_4 -> V_39 ;
V_5 -> V_23 . V_40 = V_4 -> V_19 ;
V_5 -> V_23 . V_25 = 0 ;
V_5 -> V_23 . V_29 = 0x7fffffff ;
}
}
static V_10 F_17 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
V_10 V_33 ;
if ( V_5 -> V_6 < V_41 ) {
V_33 = V_5 -> V_7 ;
V_33 = F_12 ( V_33 , F_16 ( V_4 -> V_19 >> 1 , 2U ) ) ;
V_33 = F_16 ( V_33 , V_4 -> V_19 >> V_42 ) ;
} else
V_33 = F_16 ( V_4 -> V_19 >> 1 , 2U ) ;
V_5 -> V_36 = 0 ;
V_5 -> V_8 = F_16 ( V_5 -> V_8 >> 1 , 2U ) ;
return V_4 -> V_19 - V_33 ;
}
static int T_3 F_18 ( void )
{
F_19 ( sizeof( struct V_5 ) > V_43 ) ;
F_20 ( & V_44 ) ;
return 0 ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_44 ) ;
}
