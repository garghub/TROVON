static void F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
V_5 -> V_6 = 1 ;
V_5 -> V_7 = V_4 -> V_8 ;
V_5 -> V_9 = 0 ;
V_5 -> V_10 = 0x7fffffff ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
V_5 -> V_6 = 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
V_5 -> V_11 = 0x7fffffff ;
F_1 ( V_2 ) ;
}
void F_6 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_13 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_14 ;
if ( V_13 < 0 )
return;
V_14 = V_13 + 1 ;
if ( V_14 < V_5 -> V_11 )
V_5 -> V_11 = V_14 ;
V_5 -> V_10 = F_7 ( V_5 -> V_10 , V_14 ) ;
V_5 -> V_9 ++ ;
}
void F_8 ( struct V_1 * V_2 , T_3 V_15 )
{
if ( V_15 == V_16 )
F_1 ( V_2 ) ;
else
F_4 ( V_2 ) ;
}
void F_9 ( struct V_1 * V_2 , enum V_17 V_18 )
{
if ( V_18 == V_19 ||
V_18 == V_20 )
F_5 ( V_2 ) ;
}
static inline T_1 F_10 ( struct V_3 * V_4 )
{
return F_7 ( V_4 -> V_21 , V_4 -> V_22 - 1 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_23 , T_1 V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
if ( ! V_5 -> V_6 ) {
F_12 ( V_2 , V_23 , V_24 ) ;
return;
}
if ( F_13 ( V_23 , V_5 -> V_7 ) ) {
V_5 -> V_7 = V_4 -> V_8 ;
if ( V_5 -> V_9 <= 2 ) {
F_12 ( V_2 , V_23 , V_24 ) ;
} else {
T_1 V_25 , V_26 ;
T_4 V_27 ;
V_25 = V_5 -> V_10 ;
V_27 = ( T_4 ) V_4 -> V_22 * V_5 -> V_11 ;
F_14 ( V_27 , V_25 ) ;
V_26 = V_4 -> V_22 * ( V_25 - V_5 -> V_11 ) / V_5 -> V_11 ;
if ( V_26 > gamma && F_15 ( V_4 ) ) {
V_4 -> V_22 = F_7 ( V_4 -> V_22 , ( T_1 ) V_27 + 1 ) ;
V_4 -> V_21 = F_10 ( V_4 ) ;
} else if ( F_15 ( V_4 ) ) {
F_16 ( V_4 , V_24 ) ;
} else {
if ( V_26 > V_28 ) {
V_4 -> V_22 -- ;
V_4 -> V_21
= F_10 ( V_4 ) ;
} else if ( V_26 < V_29 ) {
V_4 -> V_22 ++ ;
} else {
}
}
if ( V_4 -> V_22 < 2 )
V_4 -> V_22 = 2 ;
else if ( V_4 -> V_22 > V_4 -> V_30 )
V_4 -> V_22 = V_4 -> V_30 ;
V_4 -> V_21 = F_17 ( V_2 ) ;
}
V_5 -> V_9 = 0 ;
V_5 -> V_10 = 0x7fffffff ;
}
else if ( F_15 ( V_4 ) )
F_16 ( V_4 , V_24 ) ;
}
T_5 F_18 ( struct V_1 * V_2 , T_1 V_31 , int * V_32 ,
union V_33 * V_34 )
{
const struct V_5 * V_35 = F_3 ( V_2 ) ;
if ( V_31 & ( 1 << ( V_36 - 1 ) ) ) {
V_34 -> V_5 . V_37 = V_35 -> V_6 ,
V_34 -> V_5 . V_38 = V_35 -> V_9 ,
V_34 -> V_5 . V_39 = V_35 -> V_11 ,
V_34 -> V_5 . V_40 = V_35 -> V_10 ,
* V_32 = V_36 ;
return sizeof( struct V_41 ) ;
}
return 0 ;
}
static int T_6 F_19 ( void )
{
F_20 ( sizeof( struct V_5 ) > V_42 ) ;
F_21 ( & V_43 ) ;
return 0 ;
}
static void T_7 F_22 ( void )
{
F_23 ( & V_43 ) ;
}
