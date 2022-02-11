STATIC int
F_1 (
struct V_1 * V_2 ,
int V_3 )
{
return V_2 -> V_4 -> V_5 [ V_3 != 0 ] ;
}
STATIC struct V_1 *
F_2 (
struct V_1 * V_2 )
{
return F_3 ( V_2 -> V_4 , V_2 -> V_6 ,
V_2 -> V_7 . V_8 . V_9 , V_2 -> V_7 . V_8 . V_10 ) ;
}
STATIC void
F_4 (
struct V_1 * V_2 ,
union V_11 * V_12 ,
int V_13 )
{
struct V_14 * V_9 = V_2 -> V_7 . V_8 . V_9 ;
struct V_15 * V_16 = F_5 ( V_9 ) ;
V_16 -> V_17 = V_12 -> V_18 ;
F_6 ( & V_16 -> V_19 , V_13 ) ;
F_7 ( V_2 -> V_6 , V_9 , V_20 | V_21 ) ;
}
STATIC int
F_8 (
struct V_1 * V_2 ,
union V_11 * V_22 ,
union V_11 * V_23 ,
int V_24 ,
int * V_25 )
{
T_1 args ;
int error ;
T_2 V_26 = F_9 ( V_22 -> V_18 ) ;
F_10 ( V_2 , V_27 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_28 = V_2 -> V_6 ;
args . V_29 = V_2 -> V_4 ;
args . V_30 = F_11 ( args . V_29 , V_2 -> V_7 . V_8 . V_10 , V_26 ) ;
args . V_31 = 1 ;
args . V_32 = 1 ;
args . V_33 = 1 ;
args . type = V_34 ;
error = F_12 ( & args ) ;
if ( error ) {
F_10 ( V_2 , V_35 ) ;
return error ;
}
if ( args . V_30 == V_36 ) {
F_10 ( V_2 , V_37 ) ;
* V_25 = 0 ;
return 0 ;
}
ASSERT ( args . V_38 == 1 ) ;
F_10 ( V_2 , V_37 ) ;
V_23 -> V_18 = F_13 ( F_14 ( args . V_29 , args . V_30 ) ) ;
* V_25 = 1 ;
return 0 ;
}
STATIC int
F_15 (
struct V_1 * V_2 ,
struct V_14 * V_39 )
{
T_3 V_30 ;
int error ;
V_30 = F_16 ( V_2 -> V_4 , F_17 ( V_39 ) ) ;
error = F_18 ( V_2 -> V_6 , V_30 , 1 ) ;
if ( error )
return error ;
F_19 ( V_2 -> V_6 , V_39 ) ;
return error ;
}
STATIC int
F_20 (
struct V_1 * V_2 ,
int V_3 )
{
return V_2 -> V_4 -> V_40 [ V_3 != 0 ] ;
}
STATIC void
F_21 (
union V_41 * V_42 ,
union V_43 * V_44 )
{
V_42 -> V_45 . V_46 = V_44 -> V_45 . V_46 ;
}
STATIC void
F_22 (
union V_41 * V_42 ,
union V_43 * V_44 )
{
V_44 -> V_45 . V_46 = V_42 -> V_45 . V_46 ;
}
STATIC void
F_23 (
struct V_1 * V_2 ,
union V_43 * V_44 )
{
V_44 -> V_45 . V_46 = F_13 ( V_2 -> V_47 . V_48 . V_46 ) ;
V_44 -> V_45 . V_49 = F_13 ( V_2 -> V_47 . V_48 . V_49 ) ;
V_44 -> V_45 . V_50 = F_24 ( V_2 -> V_47 . V_48 . V_50 ) ;
}
STATIC void
F_25 (
struct V_1 * V_2 ,
union V_11 * V_51 )
{
struct V_15 * V_16 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_9 ( V_16 -> V_52 ) ) ;
V_51 -> V_18 = V_16 -> V_17 ;
}
STATIC T_4
F_26 (
struct V_1 * V_2 ,
union V_41 * V_42 )
{
return ( T_4 ) F_9 ( V_42 -> V_45 . V_46 ) -
V_2 -> V_47 . V_48 . V_46 ;
}
static int
F_27 (
struct V_14 * V_39 )
{
struct V_53 * V_29 = V_39 -> V_54 -> V_55 ;
struct V_56 * V_57 = F_28 ( V_39 ) ;
struct V_58 * V_59 = V_39 -> V_60 ;
unsigned int V_3 ;
switch ( V_57 -> V_61 ) {
case F_13 ( V_62 ) :
if ( ! F_29 ( & V_29 -> V_63 ) )
return false ;
if ( ! F_30 ( & V_57 -> V_64 . V_18 . V_65 , & V_29 -> V_63 . V_66 ) )
return false ;
if ( V_57 -> V_64 . V_18 . V_67 != F_24 ( V_39 -> V_68 ) )
return false ;
if ( V_59 &&
F_9 ( V_57 -> V_64 . V_18 . V_69 ) != V_59 -> V_70 )
return false ;
case F_13 ( V_71 ) :
break;
default:
return 0 ;
}
V_3 = F_31 ( V_57 -> V_72 ) ;
if ( V_3 >= V_29 -> V_73 )
return false ;
if ( F_31 ( V_57 -> V_74 ) > V_29 -> V_40 [ V_3 != 0 ] )
return false ;
if ( ! V_57 -> V_64 . V_18 . V_75 ||
( F_9 ( V_57 -> V_64 . V_18 . V_75 ) >= V_29 -> V_63 . V_76 &&
V_57 -> V_64 . V_18 . V_75 != F_13 ( V_77 ) ) )
return false ;
if ( ! V_57 -> V_64 . V_18 . V_78 ||
( F_9 ( V_57 -> V_64 . V_18 . V_78 ) >= V_29 -> V_63 . V_76 &&
V_57 -> V_64 . V_18 . V_78 != F_13 ( V_77 ) ) )
return false ;
return true ;
}
static void
F_32 (
struct V_14 * V_39 )
{
if ( ! F_33 ( V_39 ) )
F_34 ( V_39 , V_79 ) ;
else if ( ! F_27 ( V_39 ) )
F_34 ( V_39 , V_80 ) ;
if ( V_39 -> V_81 ) {
F_35 ( V_39 , V_82 ) ;
F_36 ( V_39 ) ;
}
}
static void
F_37 (
struct V_14 * V_39 )
{
if ( ! F_27 ( V_39 ) ) {
F_35 ( V_39 , V_82 ) ;
F_34 ( V_39 , V_80 ) ;
F_36 ( V_39 ) ;
return;
}
F_38 ( V_39 ) ;
}
STATIC int
F_39 (
struct V_1 * V_2 ,
union V_41 * V_83 ,
union V_41 * V_84 )
{
return F_9 ( V_83 -> V_45 . V_46 ) <
F_9 ( V_84 -> V_45 . V_46 ) ;
}
STATIC int
F_40 (
struct V_1 * V_2 ,
union V_43 * V_85 ,
union V_43 * V_86 )
{
return F_9 ( V_85 -> V_45 . V_46 ) + V_87 <=
F_9 ( V_86 -> V_45 . V_46 ) ;
}
struct V_1 *
F_3 (
struct V_53 * V_29 ,
struct V_88 * V_28 ,
struct V_14 * V_9 ,
T_5 V_10 )
{
struct V_15 * V_16 = F_5 ( V_9 ) ;
struct V_1 * V_2 ;
V_2 = F_41 ( V_89 , V_90 ) ;
V_2 -> V_6 = V_28 ;
V_2 -> V_4 = V_29 ;
V_2 -> V_91 = F_9 ( V_16 -> V_19 ) ;
V_2 -> V_92 = V_93 ;
V_2 -> V_94 = V_29 -> V_63 . V_95 ;
V_2 -> V_96 = & V_97 ;
if ( F_29 ( & V_29 -> V_63 ) )
V_2 -> V_98 |= V_99 ;
V_2 -> V_7 . V_8 . V_9 = V_9 ;
V_2 -> V_7 . V_8 . V_10 = V_10 ;
return V_2 ;
}
int
F_42 (
struct V_53 * V_29 ,
int V_100 ,
int V_101 )
{
V_100 -= F_43 ( V_29 ) ;
if ( V_101 )
return V_100 / sizeof( V_102 ) ;
return V_100 / ( sizeof( V_103 ) + sizeof( V_104 ) ) ;
}
