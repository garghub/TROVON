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
static void F_5 ( struct V_1 * V_2 ,
const struct V_8 * V_9 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_10 ;
if ( V_9 -> V_11 < 0 )
return;
V_10 = V_9 -> V_11 + 1 ;
if ( V_10 < V_3 -> V_6 )
V_3 -> V_6 = V_10 ;
V_3 -> V_5 = F_6 ( V_3 -> V_5 , V_10 ) ;
V_3 -> V_12 ++ ;
}
static void F_7 ( struct V_1 * V_2 , T_2 V_13 )
{
if ( V_13 == V_14 )
F_1 ( V_2 ) ;
else
F_3 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 , enum V_15 V_16 )
{
if ( V_16 == V_17 || V_16 == V_18 )
F_4 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_19 , T_1 V_20 )
{
struct V_21 * V_22 = F_10 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( ! V_3 -> V_4 ) {
F_11 ( V_2 , V_19 , V_20 ) ;
return;
}
if ( ! F_12 ( V_2 ) )
return;
if ( V_3 -> V_12 <= 2 ) {
F_11 ( V_2 , V_19 , V_20 ) ;
} else {
T_3 V_23 ;
T_1 V_24 ;
V_24 = V_3 -> V_5 ;
V_23 = ( T_3 ) V_22 -> V_25 * V_3 -> V_6 ;
V_23 <<= V_26 ;
F_13 ( V_23 , V_24 ) ;
V_3 -> V_27 = ( V_22 -> V_25 << V_26 ) - V_23 ;
if ( F_14 ( V_22 ) ) {
F_15 ( V_22 , V_20 ) ;
} else {
if ( V_3 -> V_27 < V_28 ) {
F_16 ( V_22 , V_22 -> V_25 , 1 ) ;
} else {
if ( V_22 -> V_29 >= V_22 -> V_25 ) {
if ( V_3 -> V_7 &&
V_22 -> V_25 < V_22 -> V_30 ) {
V_22 -> V_25 ++ ;
V_3 -> V_7 = 0 ;
} else
V_3 -> V_7 = 1 ;
V_22 -> V_29 = 0 ;
} else
V_22 -> V_29 ++ ;
}
}
if ( V_22 -> V_25 < 2 )
V_22 -> V_25 = 2 ;
else if ( V_22 -> V_25 > V_22 -> V_30 )
V_22 -> V_25 = V_22 -> V_30 ;
}
V_3 -> V_5 = 0x7fffffff ;
}
static T_1 F_17 ( struct V_1 * V_2 )
{
const struct V_21 * V_22 = F_10 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_27 < V_28 )
return F_18 ( V_22 -> V_25 * 4 / 5 , 2U ) ;
else
return F_18 ( V_22 -> V_25 >> 1U , 2U ) ;
}
static int T_4 F_19 ( void )
{
F_20 ( sizeof( struct V_3 ) > V_31 ) ;
F_21 ( & V_32 ) ;
return 0 ;
}
static void T_5 F_22 ( void )
{
F_23 ( & V_32 ) ;
}
