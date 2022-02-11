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
void F_6 ( struct V_1 * V_2 , const struct V_12 * V_13 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_14 ;
if ( V_13 -> V_15 < 0 )
return;
V_14 = V_13 -> V_15 + 1 ;
if ( V_14 < V_5 -> V_11 )
V_5 -> V_11 = V_14 ;
V_5 -> V_10 = F_7 ( V_5 -> V_10 , V_14 ) ;
V_5 -> V_9 ++ ;
}
void F_8 ( struct V_1 * V_2 , T_2 V_16 )
{
if ( V_16 == V_17 )
F_1 ( V_2 ) ;
else
F_4 ( V_2 ) ;
}
void F_9 ( struct V_1 * V_2 , enum V_18 V_19 )
{
if ( V_19 == V_20 ||
V_19 == V_21 )
F_5 ( V_2 ) ;
}
static inline T_1 F_10 ( struct V_3 * V_4 )
{
return F_7 ( V_4 -> V_22 , V_4 -> V_23 - 1 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_24 , T_1 V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
if ( ! V_5 -> V_6 ) {
F_12 ( V_2 , V_24 , V_25 ) ;
return;
}
if ( F_13 ( V_24 , V_5 -> V_7 ) ) {
V_5 -> V_7 = V_4 -> V_8 ;
if ( V_5 -> V_9 <= 2 ) {
F_12 ( V_2 , V_24 , V_25 ) ;
} else {
T_1 V_26 , V_27 ;
T_3 V_28 ;
V_26 = V_5 -> V_10 ;
V_28 = ( T_3 ) V_4 -> V_23 * V_5 -> V_11 ;
F_14 ( V_28 , V_26 ) ;
V_27 = V_4 -> V_23 * ( V_26 - V_5 -> V_11 ) / V_5 -> V_11 ;
if ( V_27 > gamma && F_15 ( V_4 ) ) {
V_4 -> V_23 = F_7 ( V_4 -> V_23 , ( T_1 ) V_28 + 1 ) ;
V_4 -> V_22 = F_10 ( V_4 ) ;
} else if ( F_15 ( V_4 ) ) {
F_16 ( V_4 , V_25 ) ;
} else {
if ( V_27 > V_29 ) {
V_4 -> V_23 -- ;
V_4 -> V_22
= F_10 ( V_4 ) ;
} else if ( V_27 < V_30 ) {
V_4 -> V_23 ++ ;
} else {
}
}
if ( V_4 -> V_23 < 2 )
V_4 -> V_23 = 2 ;
else if ( V_4 -> V_23 > V_4 -> V_31 )
V_4 -> V_23 = V_4 -> V_31 ;
V_4 -> V_22 = F_17 ( V_2 ) ;
}
V_5 -> V_9 = 0 ;
V_5 -> V_10 = 0x7fffffff ;
}
else if ( F_15 ( V_4 ) )
F_16 ( V_4 , V_25 ) ;
}
T_4 F_18 ( struct V_1 * V_2 , T_1 V_32 , int * V_33 ,
union V_34 * V_35 )
{
const struct V_5 * V_36 = F_3 ( V_2 ) ;
if ( V_32 & ( 1 << ( V_37 - 1 ) ) ) {
V_35 -> V_5 . V_38 = V_36 -> V_6 ,
V_35 -> V_5 . V_39 = V_36 -> V_9 ,
V_35 -> V_5 . V_40 = V_36 -> V_11 ,
V_35 -> V_5 . V_41 = V_36 -> V_10 ,
* V_33 = V_37 ;
return sizeof( struct V_42 ) ;
}
return 0 ;
}
static int T_5 F_19 ( void )
{
F_20 ( sizeof( struct V_5 ) > V_43 ) ;
F_21 ( & V_44 ) ;
return 0 ;
}
static void T_6 F_22 ( void )
{
F_23 ( & V_44 ) ;
}
