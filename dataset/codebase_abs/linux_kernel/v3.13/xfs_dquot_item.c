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
V_10 -> V_12 = & V_11 -> V_13 ;
V_10 -> V_14 = sizeof( V_15 ) ;
V_10 -> V_16 = V_17 ;
V_10 ++ ;
V_10 -> V_12 = & V_11 -> V_18 -> V_19 ;
V_10 -> V_14 = sizeof( V_20 ) ;
V_10 -> V_16 = V_21 ;
V_11 -> V_13 . V_22 = 2 ;
}
STATIC void
F_5 (
struct V_2 * V_3 )
{
struct V_23 * V_24 = F_1 ( V_3 ) -> V_18 ;
ASSERT ( F_6 ( V_24 ) ) ;
F_7 ( & V_24 -> V_25 ) ;
}
STATIC void
F_8 (
struct V_2 * V_3 ,
int remove )
{
struct V_23 * V_24 = F_1 ( V_3 ) -> V_18 ;
ASSERT ( F_9 ( & V_24 -> V_25 ) > 0 ) ;
if ( F_10 ( & V_24 -> V_25 ) )
F_11 ( & V_24 -> V_26 ) ;
}
STATIC T_1
F_12 (
struct V_2 * V_3 ,
T_1 V_27 )
{
return V_27 ;
}
void
F_13 (
struct V_23 * V_24 )
{
ASSERT ( F_6 ( V_24 ) ) ;
if ( F_9 ( & V_24 -> V_25 ) == 0 )
return;
F_14 ( V_24 -> V_28 , 0 ) ;
F_15 ( V_24 -> V_26 , ( F_9 ( & V_24 -> V_25 ) == 0 ) ) ;
}
STATIC T_2
F_16 (
struct V_2 * V_3 ,
struct V_29 * V_30 ) __releases( &lip->li_ailp->xa_lock
STATIC void
F_17 (
struct V_2 * V_3 )
{
struct V_23 * V_24 = F_1 ( V_3 ) -> V_18 ;
ASSERT ( F_6 ( V_24 ) ) ;
V_24 -> V_31 = NULL ;
F_18 ( V_24 ) ;
}
STATIC void
F_19 (
struct V_2 * V_3 ,
T_1 V_27 )
{
}
void
F_20 (
struct V_23 * V_24 )
{
struct V_1 * V_32 = & V_24 -> V_33 ;
F_21 ( V_24 -> V_28 , & V_32 -> V_4 , V_34 ,
& V_35 ) ;
V_32 -> V_18 = V_24 ;
V_32 -> V_13 . V_36 = V_34 ;
V_32 -> V_13 . V_37 = F_22 ( V_24 -> V_19 . V_38 ) ;
V_32 -> V_13 . V_39 = V_24 -> V_40 ;
V_32 -> V_13 . V_41 = 1 ;
V_32 -> V_13 . V_42 = ( V_43 ) V_24 -> V_44 ;
}
static inline struct V_45 * F_23 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_45 , V_46 ) ;
}
STATIC void
F_24 (
struct V_2 * V_3 ,
int * V_5 ,
int * V_6 )
{
* V_5 += 1 ;
* V_6 += sizeof( struct V_45 ) ;
}
STATIC void
F_25 (
struct V_2 * V_3 ,
struct V_9 * V_47 )
{
struct V_45 * V_48 = F_23 ( V_3 ) ;
ASSERT ( V_48 -> V_49 . V_50 == V_51 ) ;
V_47 -> V_12 = & V_48 -> V_49 ;
V_47 -> V_14 = sizeof( V_52 ) ;
V_47 -> V_16 = V_53 ;
V_48 -> V_49 . V_54 = 1 ;
}
STATIC void
F_26 (
struct V_2 * V_3 )
{
}
STATIC void
F_27 (
struct V_2 * V_3 ,
int remove )
{
}
STATIC T_2
F_28 (
struct V_2 * V_3 ,
struct V_29 * V_30 )
{
return V_55 ;
}
STATIC void
F_29 (
struct V_2 * V_3 )
{
}
STATIC T_1
F_30 (
struct V_2 * V_3 ,
T_1 V_27 )
{
return V_27 ;
}
STATIC T_1
F_31 (
struct V_2 * V_3 ,
T_1 V_27 )
{
struct V_45 * V_56 = F_23 ( V_3 ) ;
struct V_45 * V_57 = V_56 -> V_58 ;
struct V_59 * V_60 = V_57 -> V_46 . V_61 ;
F_32 ( & V_60 -> V_62 ) ;
F_33 ( V_60 , & V_57 -> V_46 , V_63 ) ;
F_34 ( V_57 ) ;
F_34 ( V_56 ) ;
return ( T_1 ) - 1 ;
}
STATIC void
F_35 (
struct V_2 * V_3 ,
T_1 V_64 )
{
}
struct V_45 *
F_36 (
struct V_65 * V_66 ,
struct V_45 * V_67 ,
T_2 V_68 )
{
struct V_45 * V_69 ;
V_69 = F_37 ( sizeof( struct V_45 ) , V_70 ) ;
F_21 ( V_66 , & V_69 -> V_46 , V_51 , V_67 ?
& V_71 : & V_72 ) ;
V_69 -> V_46 . V_73 = V_66 ;
V_69 -> V_49 . V_50 = V_51 ;
V_69 -> V_49 . V_74 = V_68 ;
V_69 -> V_58 = V_67 ;
return V_69 ;
}
