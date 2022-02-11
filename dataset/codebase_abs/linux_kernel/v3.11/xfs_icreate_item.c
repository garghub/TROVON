static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
STATIC T_1
F_3 (
struct V_2 * V_3 )
{
return 1 ;
}
STATIC void
F_4 (
struct V_2 * V_3 ,
struct V_5 * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_6 -> V_8 = ( V_9 ) & V_7 -> V_10 ;
V_6 -> V_11 = sizeof( struct V_12 ) ;
V_6 -> V_13 = V_14 ;
}
STATIC void
F_5 (
struct V_2 * V_3 )
{
}
STATIC void
F_6 (
struct V_2 * V_3 ,
int remove )
{
}
STATIC void
F_7 (
struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( V_7 -> V_4 . V_15 & V_16 )
F_8 ( V_17 , V_7 ) ;
return;
}
STATIC T_2
F_9 (
struct V_2 * V_3 ,
T_2 V_18 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_8 ( V_17 , V_7 ) ;
return ( T_2 ) - 1 ;
}
STATIC T_1
F_10 (
struct V_2 * V_3 ,
struct V_19 * V_20 )
{
ASSERT ( 0 ) ;
return V_21 ;
}
STATIC void
F_11 (
struct V_2 * V_3 ,
T_2 V_18 )
{
}
void
V_12 (
struct V_22 * V_23 ,
T_3 V_24 ,
T_4 V_25 ,
unsigned int V_26 ,
unsigned int V_27 ,
T_4 V_28 ,
unsigned int V_29 )
{
struct V_1 * V_7 ;
V_7 = F_12 ( V_17 , V_30 ) ;
F_13 ( V_23 -> V_31 , & V_7 -> V_4 , V_32 ,
& V_33 ) ;
V_7 -> V_10 . V_34 = V_32 ;
V_7 -> V_10 . V_35 = 1 ;
V_7 -> V_10 . V_36 = F_14 ( V_24 ) ;
V_7 -> V_10 . V_37 = F_14 ( V_25 ) ;
V_7 -> V_10 . V_38 = F_14 ( V_26 ) ;
V_7 -> V_10 . V_39 = F_14 ( V_27 ) ;
V_7 -> V_10 . V_40 = F_14 ( V_28 ) ;
V_7 -> V_10 . V_41 = F_14 ( V_29 ) ;
F_15 ( V_23 , & V_7 -> V_4 ) ;
V_23 -> V_42 |= V_43 ;
V_7 -> V_4 . V_44 -> V_45 |= V_46 ;
}
