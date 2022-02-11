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
* V_5 += 2 ;
* V_6 += sizeof( struct V_7 ) +
sizeof( struct V_8 ) ;
}
STATIC void
F_4 (
struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_12 * V_13 = NULL ;
struct V_7 * V_14 ;
V_14 = F_5 ( V_10 , & V_13 , V_15 ) ;
V_14 -> V_16 = V_17 ;
V_14 -> V_18 = 2 ;
V_14 -> V_19 = F_6 ( V_11 -> V_20 -> V_21 . V_22 ) ;
V_14 -> V_23 = V_11 -> V_20 -> V_24 ;
V_14 -> V_25 = 1 ;
V_14 -> V_26 = V_11 -> V_20 -> V_27 ;
F_7 ( V_10 , V_13 , sizeof( struct V_7 ) ) ;
F_8 ( V_10 , & V_13 , V_28 ,
& V_11 -> V_20 -> V_21 ,
sizeof( struct V_8 ) ) ;
}
STATIC void
F_9 (
struct V_2 * V_3 )
{
struct V_29 * V_30 = F_1 ( V_3 ) -> V_20 ;
ASSERT ( F_10 ( V_30 ) ) ;
F_11 ( & V_30 -> V_31 ) ;
}
STATIC void
F_12 (
struct V_2 * V_3 ,
int remove )
{
struct V_29 * V_30 = F_1 ( V_3 ) -> V_20 ;
ASSERT ( F_13 ( & V_30 -> V_31 ) > 0 ) ;
if ( F_14 ( & V_30 -> V_31 ) )
F_15 ( & V_30 -> V_32 ) ;
}
STATIC T_1
F_16 (
struct V_2 * V_3 ,
T_1 V_33 )
{
return V_33 ;
}
void
F_17 (
struct V_29 * V_30 )
{
ASSERT ( F_10 ( V_30 ) ) ;
if ( F_13 ( & V_30 -> V_31 ) == 0 )
return;
F_18 ( V_30 -> V_34 , 0 ) ;
F_19 ( V_30 -> V_32 , ( F_13 ( & V_30 -> V_31 ) == 0 ) ) ;
}
STATIC T_2
F_20 (
struct V_2 * V_3 ,
struct V_35 * V_36 ) __releases( &lip->li_ailp->xa_lock
STATIC void
F_21 (
struct V_2 * V_3 )
{
struct V_29 * V_30 = F_1 ( V_3 ) -> V_20 ;
ASSERT ( F_10 ( V_30 ) ) ;
V_30 -> V_37 = NULL ;
F_22 ( V_30 ) ;
}
STATIC void
F_23 (
struct V_2 * V_3 ,
T_1 V_33 )
{
}
void
F_24 (
struct V_29 * V_30 )
{
struct V_1 * V_38 = & V_30 -> V_39 ;
F_25 ( V_30 -> V_34 , & V_38 -> V_4 , V_17 ,
& V_40 ) ;
V_38 -> V_20 = V_30 ;
}
static inline struct V_41 * F_26 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_41 , V_42 ) ;
}
STATIC void
F_27 (
struct V_2 * V_3 ,
int * V_5 ,
int * V_6 )
{
* V_5 += 1 ;
* V_6 += sizeof( struct V_41 ) ;
}
STATIC void
F_28 (
struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_41 * V_43 = F_26 ( V_3 ) ;
struct V_12 * V_13 = NULL ;
struct V_44 * V_14 ;
V_14 = F_5 ( V_10 , & V_13 , V_45 ) ;
V_14 -> V_46 = V_47 ;
V_14 -> V_48 = 1 ;
V_14 -> V_49 = V_43 -> V_50 ;
F_7 ( V_10 , V_13 , sizeof( struct V_41 ) ) ;
}
STATIC void
F_29 (
struct V_2 * V_3 )
{
}
STATIC void
F_30 (
struct V_2 * V_3 ,
int remove )
{
}
STATIC T_2
F_31 (
struct V_2 * V_3 ,
struct V_35 * V_36 )
{
return V_51 ;
}
STATIC void
F_32 (
struct V_2 * V_3 )
{
}
STATIC T_1
F_33 (
struct V_2 * V_3 ,
T_1 V_33 )
{
return V_33 ;
}
STATIC T_1
F_34 (
struct V_2 * V_3 ,
T_1 V_33 )
{
struct V_41 * V_52 = F_26 ( V_3 ) ;
struct V_41 * V_53 = V_52 -> V_54 ;
struct V_55 * V_56 = V_53 -> V_42 . V_57 ;
F_35 ( & V_56 -> V_58 ) ;
F_36 ( V_56 , & V_53 -> V_42 , V_59 ) ;
F_37 ( V_53 ) ;
F_37 ( V_52 ) ;
return ( T_1 ) - 1 ;
}
STATIC void
F_38 (
struct V_2 * V_3 ,
T_1 V_60 )
{
}
struct V_41 *
F_39 (
struct V_61 * V_62 ,
struct V_41 * V_63 ,
T_2 V_64 )
{
struct V_41 * V_65 ;
V_65 = F_40 ( sizeof( struct V_41 ) , V_66 ) ;
F_25 ( V_62 , & V_65 -> V_42 , V_47 , V_63 ?
& V_67 : & V_68 ) ;
V_65 -> V_42 . V_69 = V_62 ;
V_65 -> V_54 = V_63 ;
V_65 -> V_50 = V_64 ;
return V_65 ;
}
