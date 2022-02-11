static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_4 = 1 ;
V_3 -> V_5 = 0x7fffffff ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_4 = 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_6 = 0x7fffffff ;
V_3 -> V_7 = 1 ;
F_1 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_8 , T_2 V_9 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_10 ;
if ( V_9 < 0 )
return;
V_10 = V_9 + 1 ;
if ( V_10 < V_3 -> V_6 )
V_3 -> V_6 = V_10 ;
V_3 -> V_5 = F_6 ( V_3 -> V_5 , V_10 ) ;
V_3 -> V_11 ++ ;
}
static void F_7 ( struct V_1 * V_2 , T_3 V_12 )
{
if ( V_12 == V_13 )
F_1 ( V_2 ) ;
else
F_3 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 , enum V_14 V_15 )
{
if ( V_15 == V_16 || V_15 == V_17 )
F_4 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_18 , T_1 V_19 )
{
struct V_20 * V_21 = F_10 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( ! V_3 -> V_4 ) {
F_11 ( V_2 , V_18 , V_19 ) ;
return;
}
if ( ! F_12 ( V_2 , V_19 ) )
return;
if ( V_3 -> V_11 <= 2 ) {
F_11 ( V_2 , V_18 , V_19 ) ;
} else {
T_4 V_22 ;
T_1 V_23 ;
V_23 = V_3 -> V_5 ;
V_22 = ( V_21 -> V_24 * V_3 -> V_6 ) ;
V_22 <<= V_25 ;
F_13 ( V_22 , V_23 ) ;
V_3 -> V_26 = ( V_21 -> V_24 << V_25 ) - V_22 ;
if ( V_21 -> V_24 <= V_21 -> V_27 ) {
F_14 ( V_21 ) ;
} else {
if ( V_3 -> V_26 < V_28 ) {
F_15 ( V_21 , V_21 -> V_24 ) ;
} else {
if ( V_21 -> V_29 >= V_21 -> V_24 ) {
if ( V_3 -> V_7 &&
V_21 -> V_24 < V_21 -> V_30 ) {
V_21 -> V_24 ++ ;
V_3 -> V_7 = 0 ;
} else
V_3 -> V_7 = 1 ;
V_21 -> V_29 = 0 ;
} else
V_21 -> V_29 ++ ;
}
}
if ( V_21 -> V_24 < 2 )
V_21 -> V_24 = 2 ;
else if ( V_21 -> V_24 > V_21 -> V_30 )
V_21 -> V_24 = V_21 -> V_30 ;
}
V_3 -> V_5 = 0x7fffffff ;
}
static T_1 F_16 ( struct V_1 * V_2 )
{
const struct V_20 * V_21 = F_10 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_26 < V_28 )
return F_17 ( V_21 -> V_24 * 4 / 5 , 2U ) ;
else
return F_17 ( V_21 -> V_24 >> 1U , 2U ) ;
}
static int T_5 F_18 ( void )
{
F_19 ( sizeof( struct V_3 ) > V_31 ) ;
F_20 ( & V_32 ) ;
return 0 ;
}
static void T_6 F_21 ( void )
{
F_22 ( & V_32 ) ;
}
