static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
STATIC void
F_3 (
struct V_2 * V_3 ,
int * V_5 ,
int * V_6 )
{
* V_5 += 1 ;
* V_6 += sizeof( struct V_7 ) ;
}
STATIC void
F_4 (
struct V_2 * V_3 ,
struct V_8 * V_9 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
V_9 -> V_11 = ( V_12 ) & V_10 -> V_13 ;
V_9 -> V_14 = sizeof( struct V_7 ) ;
V_9 -> V_15 = V_16 ;
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
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( V_10 -> V_4 . V_17 & V_18 )
F_8 ( V_19 , V_10 ) ;
return;
}
STATIC T_1
F_9 (
struct V_2 * V_3 ,
T_1 V_20 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
F_8 ( V_19 , V_10 ) ;
return ( T_1 ) - 1 ;
}
STATIC T_2
F_10 (
struct V_2 * V_3 ,
struct V_21 * V_22 )
{
ASSERT ( 0 ) ;
return V_23 ;
}
STATIC void
F_11 (
struct V_2 * V_3 ,
T_1 V_20 )
{
}
void
V_7 (
struct V_24 * V_25 ,
T_3 V_26 ,
T_4 V_27 ,
unsigned int V_28 ,
unsigned int V_29 ,
T_4 V_30 ,
unsigned int V_31 )
{
struct V_1 * V_10 ;
V_10 = F_12 ( V_19 , V_32 ) ;
F_13 ( V_25 -> V_33 , & V_10 -> V_4 , V_34 ,
& V_35 ) ;
V_10 -> V_13 . V_36 = V_34 ;
V_10 -> V_13 . V_37 = 1 ;
V_10 -> V_13 . V_38 = F_14 ( V_26 ) ;
V_10 -> V_13 . V_39 = F_14 ( V_27 ) ;
V_10 -> V_13 . V_40 = F_14 ( V_28 ) ;
V_10 -> V_13 . V_41 = F_14 ( V_29 ) ;
V_10 -> V_13 . V_42 = F_14 ( V_30 ) ;
V_10 -> V_13 . V_43 = F_14 ( V_31 ) ;
F_15 ( V_25 , & V_10 -> V_4 ) ;
V_25 -> V_44 |= V_45 ;
V_10 -> V_4 . V_46 -> V_47 |= V_48 ;
}
