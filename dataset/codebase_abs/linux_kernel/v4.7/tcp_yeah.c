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
static void F_6 ( struct V_1 * V_2 ,
const struct V_11 * V_12 )
{
const struct V_13 * V_14 = F_7 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
if ( V_14 -> V_15 == V_16 )
V_5 -> V_17 = V_12 -> V_17 ;
F_8 ( V_2 , V_12 ) ;
}
static void F_9 ( struct V_1 * V_2 , V_10 V_18 , V_10 V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
if ( ! F_10 ( V_2 ) )
return;
if ( V_4 -> V_20 <= V_4 -> V_21 )
F_11 ( V_4 , V_19 ) ;
else if ( ! V_5 -> V_6 ) {
V_4 -> V_22 += V_5 -> V_17 ;
if ( V_4 -> V_22 > F_12 ( V_4 -> V_20 , V_23 ) ) {
if ( V_4 -> V_20 < V_4 -> V_9 )
V_4 -> V_20 ++ ;
V_4 -> V_22 = 0 ;
}
V_5 -> V_17 = 1 ;
} else {
F_13 ( V_4 , V_4 -> V_20 , 1 ) ;
}
if ( F_14 ( V_18 , V_5 -> V_24 . V_25 ) ) {
if ( V_5 -> V_24 . V_26 > 2 ) {
V_10 V_27 , V_28 ;
T_1 V_29 ;
V_27 = V_5 -> V_24 . V_30 ;
V_29 = V_4 -> V_20 ;
V_29 *= V_27 - V_5 -> V_24 . V_31 ;
F_15 ( V_29 , V_27 ) ;
V_28 = V_29 ;
if ( V_28 > V_32 ||
V_27 - V_5 -> V_24 . V_31 > ( V_5 -> V_24 . V_31 / V_33 ) ) {
if ( V_28 > V_32 &&
V_4 -> V_20 > V_5 -> V_8 ) {
V_10 V_34 = F_12 ( V_28 / V_35 ,
V_4 -> V_20 >> V_36 ) ;
V_4 -> V_20 -= V_34 ;
V_4 -> V_20 = F_16 ( V_4 -> V_20 ,
V_5 -> V_8 ) ;
V_4 -> V_21 = V_4 -> V_20 ;
}
if ( V_5 -> V_8 <= 2 )
V_5 -> V_8 = F_16 ( V_4 -> V_20 >> 1 , 2U ) ;
else
V_5 -> V_8 ++ ;
V_5 -> V_6 = F_12 ( V_5 -> V_6 + 1 ,
0xffffffU ) ;
} else {
V_5 -> V_37 ++ ;
if ( V_5 -> V_37 > V_38 ) {
V_5 -> V_8 = 2 ;
V_5 -> V_37 = 0 ;
}
V_5 -> V_6 = 0 ;
}
V_5 -> V_7 = V_28 ;
}
V_5 -> V_24 . V_39 = V_5 -> V_24 . V_25 ;
V_5 -> V_24 . V_25 = V_4 -> V_40 ;
V_5 -> V_24 . V_41 = V_4 -> V_20 ;
V_5 -> V_24 . V_26 = 0 ;
V_5 -> V_24 . V_30 = 0x7fffffff ;
}
}
static V_10 F_17 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
V_10 V_34 ;
if ( V_5 -> V_6 < V_42 ) {
V_34 = V_5 -> V_7 ;
V_34 = F_12 ( V_34 , F_16 ( V_4 -> V_20 >> 1 , 2U ) ) ;
V_34 = F_16 ( V_34 , V_4 -> V_20 >> V_43 ) ;
} else
V_34 = F_16 ( V_4 -> V_20 >> 1 , 2U ) ;
V_5 -> V_37 = 0 ;
V_5 -> V_8 = F_16 ( V_5 -> V_8 >> 1 , 2U ) ;
return F_18 ( int , V_4 -> V_20 - V_34 , 2 ) ;
}
static int T_2 F_19 ( void )
{
F_20 ( sizeof( struct V_5 ) > V_44 ) ;
F_21 ( & V_45 ) ;
return 0 ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_45 ) ;
}
