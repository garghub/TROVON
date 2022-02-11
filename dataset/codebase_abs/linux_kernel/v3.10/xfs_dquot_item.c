static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
STATIC T_1
F_3 (
struct V_2 * V_3 )
{
return 2 ;
}
STATIC void
F_4 (
struct V_2 * V_3 ,
struct V_5 * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_6 -> V_8 = & V_7 -> V_9 ;
V_6 -> V_10 = sizeof( V_11 ) ;
V_6 -> V_12 = V_13 ;
V_6 ++ ;
V_6 -> V_8 = & V_7 -> V_14 -> V_15 ;
V_6 -> V_10 = sizeof( V_16 ) ;
V_6 -> V_12 = V_17 ;
V_7 -> V_9 . V_18 = 2 ;
}
STATIC void
F_5 (
struct V_2 * V_3 )
{
struct V_19 * V_20 = F_1 ( V_3 ) -> V_14 ;
ASSERT ( F_6 ( V_20 ) ) ;
F_7 ( & V_20 -> V_21 ) ;
}
STATIC void
F_8 (
struct V_2 * V_3 ,
int remove )
{
struct V_19 * V_20 = F_1 ( V_3 ) -> V_14 ;
ASSERT ( F_9 ( & V_20 -> V_21 ) > 0 ) ;
if ( F_10 ( & V_20 -> V_21 ) )
F_11 ( & V_20 -> V_22 ) ;
}
STATIC T_2
F_12 (
struct V_2 * V_3 ,
T_2 V_23 )
{
return V_23 ;
}
void
F_13 (
struct V_19 * V_20 )
{
ASSERT ( F_6 ( V_20 ) ) ;
if ( F_9 ( & V_20 -> V_21 ) == 0 )
return;
F_14 ( V_20 -> V_24 , 0 ) ;
F_15 ( V_20 -> V_22 , ( F_9 ( & V_20 -> V_21 ) == 0 ) ) ;
}
STATIC T_1
F_16 (
struct V_2 * V_3 ,
struct V_25 * V_26 )
{
struct V_19 * V_20 = F_1 ( V_3 ) -> V_14 ;
struct V_27 * V_28 = NULL ;
T_1 V_29 = V_30 ;
int error ;
if ( F_9 ( & V_20 -> V_21 ) > 0 )
return V_31 ;
if ( ! F_17 ( V_20 ) )
return V_32 ;
if ( F_9 ( & V_20 -> V_21 ) > 0 ) {
V_29 = V_31 ;
goto V_33;
}
if ( ! F_18 ( V_20 ) ) {
V_29 = V_34 ;
goto V_33;
}
F_19 ( & V_3 -> V_35 -> V_36 ) ;
error = F_20 ( V_20 , & V_28 ) ;
if ( error ) {
F_21 ( V_20 -> V_24 , L_1 ,
V_37 , error , V_20 ) ;
} else {
if ( ! F_22 ( V_28 , V_26 ) )
V_29 = V_34 ;
F_23 ( V_28 ) ;
}
F_24 ( & V_3 -> V_35 -> V_36 ) ;
V_33:
F_25 ( V_20 ) ;
return V_29 ;
}
STATIC void
F_26 (
struct V_2 * V_3 )
{
struct V_19 * V_20 = F_1 ( V_3 ) -> V_14 ;
ASSERT ( F_6 ( V_20 ) ) ;
V_20 -> V_38 = NULL ;
F_25 ( V_20 ) ;
}
STATIC void
F_27 (
struct V_2 * V_3 ,
T_2 V_23 )
{
}
void
F_28 (
struct V_19 * V_20 )
{
struct V_1 * V_39 = & V_20 -> V_40 ;
F_29 ( V_20 -> V_24 , & V_39 -> V_4 , V_41 ,
& V_42 ) ;
V_39 -> V_14 = V_20 ;
V_39 -> V_9 . V_43 = V_41 ;
V_39 -> V_9 . V_44 = F_30 ( V_20 -> V_15 . V_45 ) ;
V_39 -> V_9 . V_46 = V_20 -> V_47 ;
V_39 -> V_9 . V_48 = 1 ;
V_39 -> V_9 . V_49 = ( V_50 ) V_20 -> V_51 ;
}
static inline struct V_52 * F_31 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_52 , V_53 ) ;
}
STATIC T_1
F_32 (
struct V_2 * V_3 )
{
return 1 ;
}
STATIC void
F_33 (
struct V_2 * V_3 ,
struct V_5 * V_54 )
{
struct V_52 * V_55 = F_31 ( V_3 ) ;
ASSERT ( V_55 -> V_56 . V_57 == V_58 ) ;
V_54 -> V_8 = & V_55 -> V_56 ;
V_54 -> V_10 = sizeof( V_59 ) ;
V_54 -> V_12 = V_60 ;
V_55 -> V_56 . V_61 = 1 ;
}
STATIC void
F_34 (
struct V_2 * V_3 )
{
}
STATIC void
F_35 (
struct V_2 * V_3 ,
int remove )
{
}
STATIC T_1
F_36 (
struct V_2 * V_3 ,
struct V_25 * V_26 )
{
return V_32 ;
}
STATIC void
F_37 (
struct V_2 * V_3 )
{
}
STATIC T_2
F_38 (
struct V_2 * V_3 ,
T_2 V_23 )
{
return V_23 ;
}
STATIC T_2
F_39 (
struct V_2 * V_3 ,
T_2 V_23 )
{
struct V_52 * V_62 = F_31 ( V_3 ) ;
struct V_52 * V_63 = V_62 -> V_64 ;
struct V_65 * V_66 = V_63 -> V_53 . V_35 ;
F_24 ( & V_66 -> V_36 ) ;
F_40 ( V_66 , & V_63 -> V_53 , V_67 ) ;
F_41 ( V_63 ) ;
F_41 ( V_62 ) ;
return ( T_2 ) - 1 ;
}
STATIC void
F_42 (
struct V_2 * V_3 ,
T_2 V_68 )
{
}
struct V_52 *
F_43 (
struct V_69 * V_70 ,
struct V_52 * V_71 ,
T_1 V_72 )
{
struct V_52 * V_73 ;
V_73 = F_44 ( sizeof( struct V_52 ) , V_74 ) ;
F_29 ( V_70 , & V_73 -> V_53 , V_58 , V_71 ?
& V_75 : & V_76 ) ;
V_73 -> V_53 . V_77 = V_70 ;
V_73 -> V_56 . V_57 = V_58 ;
V_73 -> V_56 . V_78 = V_72 ;
V_73 -> V_64 = V_71 ;
return V_73 ;
}
