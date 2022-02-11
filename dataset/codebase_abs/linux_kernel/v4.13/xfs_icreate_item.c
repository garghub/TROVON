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
struct V_11 * V_12 = NULL ;
F_5 ( V_9 , & V_12 , V_13 ,
& V_10 -> V_14 ,
sizeof( struct V_7 ) ) ;
}
STATIC void
F_6 (
struct V_2 * V_3 )
{
}
STATIC void
F_7 (
struct V_2 * V_3 ,
int remove )
{
}
STATIC void
F_8 (
struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( V_10 -> V_4 . V_15 & V_16 )
F_9 ( V_17 , V_10 ) ;
return;
}
STATIC T_1
F_10 (
struct V_2 * V_3 ,
T_1 V_18 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
F_9 ( V_17 , V_10 ) ;
return ( T_1 ) - 1 ;
}
STATIC T_2
F_11 (
struct V_2 * V_3 ,
struct V_19 * V_20 )
{
ASSERT ( 0 ) ;
return V_21 ;
}
STATIC void
F_12 (
struct V_2 * V_3 ,
T_1 V_18 )
{
}
void
V_7 (
struct V_22 * V_23 ,
T_3 V_24 ,
T_4 V_25 ,
unsigned int V_26 ,
unsigned int V_27 ,
T_4 V_28 ,
unsigned int V_29 )
{
struct V_1 * V_10 ;
V_10 = F_13 ( V_17 , V_30 ) ;
F_14 ( V_23 -> V_31 , & V_10 -> V_4 , V_32 ,
& V_33 ) ;
V_10 -> V_14 . V_34 = V_32 ;
V_10 -> V_14 . V_35 = 1 ;
V_10 -> V_14 . V_36 = F_15 ( V_24 ) ;
V_10 -> V_14 . V_37 = F_15 ( V_25 ) ;
V_10 -> V_14 . V_38 = F_15 ( V_26 ) ;
V_10 -> V_14 . V_39 = F_15 ( V_27 ) ;
V_10 -> V_14 . V_40 = F_15 ( V_28 ) ;
V_10 -> V_14 . V_41 = F_15 ( V_29 ) ;
F_16 ( V_23 , & V_10 -> V_4 ) ;
V_23 -> V_42 |= V_43 ;
V_10 -> V_4 . V_44 -> V_45 |= V_46 ;
}
