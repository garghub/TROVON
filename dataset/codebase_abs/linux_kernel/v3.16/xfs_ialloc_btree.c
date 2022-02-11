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
V_2 -> V_7 . V_8 . V_9 , V_2 -> V_7 . V_8 . V_10 ,
V_2 -> V_11 ) ;
}
STATIC void
F_4 (
struct V_1 * V_2 ,
union V_12 * V_13 ,
int V_14 )
{
struct V_15 * V_9 = V_2 -> V_7 . V_8 . V_9 ;
struct V_16 * V_17 = F_5 ( V_9 ) ;
V_17 -> V_18 = V_13 -> V_19 ;
F_6 ( & V_17 -> V_20 , V_14 ) ;
F_7 ( V_2 -> V_6 , V_9 , V_21 | V_22 ) ;
}
STATIC void
F_8 (
struct V_1 * V_2 ,
union V_12 * V_13 ,
int V_14 )
{
struct V_15 * V_9 = V_2 -> V_7 . V_8 . V_9 ;
struct V_16 * V_17 = F_5 ( V_9 ) ;
V_17 -> V_23 = V_13 -> V_19 ;
F_6 ( & V_17 -> V_24 , V_14 ) ;
F_7 ( V_2 -> V_6 , V_9 ,
V_25 | V_26 ) ;
}
STATIC int
F_9 (
struct V_1 * V_2 ,
union V_12 * V_27 ,
union V_12 * V_28 ,
int * V_29 )
{
T_1 args ;
int error ;
T_2 V_30 = F_10 ( V_27 -> V_19 ) ;
F_11 ( V_2 , V_31 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_32 = V_2 -> V_6 ;
args . V_33 = V_2 -> V_4 ;
args . V_34 = F_12 ( args . V_33 , V_2 -> V_7 . V_8 . V_10 , V_30 ) ;
args . V_35 = 1 ;
args . V_36 = 1 ;
args . V_37 = 1 ;
args . type = V_38 ;
error = F_13 ( & args ) ;
if ( error ) {
F_11 ( V_2 , V_39 ) ;
return error ;
}
if ( args . V_34 == V_40 ) {
F_11 ( V_2 , V_41 ) ;
* V_29 = 0 ;
return 0 ;
}
ASSERT ( args . V_42 == 1 ) ;
F_11 ( V_2 , V_41 ) ;
V_28 -> V_19 = F_14 ( F_15 ( args . V_33 , args . V_34 ) ) ;
* V_29 = 1 ;
return 0 ;
}
STATIC int
F_16 (
struct V_1 * V_2 ,
struct V_15 * V_43 )
{
T_3 V_34 ;
int error ;
V_34 = F_17 ( V_2 -> V_4 , F_18 ( V_43 ) ) ;
error = F_19 ( V_2 -> V_6 , V_34 , 1 ) ;
if ( error )
return error ;
F_20 ( V_2 -> V_6 , V_43 ) ;
return error ;
}
STATIC int
F_21 (
struct V_1 * V_2 ,
int V_3 )
{
return V_2 -> V_4 -> V_44 [ V_3 != 0 ] ;
}
STATIC void
F_22 (
union V_45 * V_46 ,
union V_47 * V_48 )
{
V_46 -> V_49 . V_50 = V_48 -> V_49 . V_50 ;
}
STATIC void
F_23 (
union V_45 * V_46 ,
union V_47 * V_48 )
{
V_48 -> V_49 . V_50 = V_46 -> V_49 . V_50 ;
}
STATIC void
F_24 (
struct V_1 * V_2 ,
union V_47 * V_48 )
{
V_48 -> V_49 . V_50 = F_14 ( V_2 -> V_51 . V_52 . V_50 ) ;
V_48 -> V_49 . V_53 = F_14 ( V_2 -> V_51 . V_52 . V_53 ) ;
V_48 -> V_49 . V_54 = F_25 ( V_2 -> V_51 . V_52 . V_54 ) ;
}
STATIC void
F_26 (
struct V_1 * V_2 ,
union V_12 * V_55 )
{
struct V_16 * V_17 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_10 ( V_17 -> V_56 ) ) ;
V_55 -> V_19 = V_17 -> V_18 ;
}
STATIC void
F_27 (
struct V_1 * V_2 ,
union V_12 * V_55 )
{
struct V_16 * V_17 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_10 ( V_17 -> V_56 ) ) ;
V_55 -> V_19 = V_17 -> V_23 ;
}
STATIC T_4
F_28 (
struct V_1 * V_2 ,
union V_45 * V_46 )
{
return ( T_4 ) F_10 ( V_46 -> V_49 . V_50 ) -
V_2 -> V_51 . V_52 . V_50 ;
}
static int
F_29 (
struct V_15 * V_43 )
{
struct V_57 * V_33 = V_43 -> V_58 -> V_59 ;
struct V_60 * V_61 = F_30 ( V_43 ) ;
struct V_62 * V_63 = V_43 -> V_64 ;
unsigned int V_3 ;
switch ( V_61 -> V_65 ) {
case F_14 ( V_66 ) :
case F_14 ( V_67 ) :
if ( ! F_31 ( & V_33 -> V_68 ) )
return false ;
if ( ! F_32 ( & V_61 -> V_69 . V_19 . V_70 , & V_33 -> V_68 . V_71 ) )
return false ;
if ( V_61 -> V_69 . V_19 . V_72 != F_25 ( V_43 -> V_73 ) )
return false ;
if ( V_63 &&
F_10 ( V_61 -> V_69 . V_19 . V_74 ) != V_63 -> V_75 )
return false ;
case F_14 ( V_76 ) :
case F_14 ( V_77 ) :
break;
default:
return 0 ;
}
V_3 = F_33 ( V_61 -> V_78 ) ;
if ( V_3 >= V_33 -> V_79 )
return false ;
if ( F_33 ( V_61 -> V_80 ) > V_33 -> V_44 [ V_3 != 0 ] )
return false ;
if ( ! V_61 -> V_69 . V_19 . V_81 ||
( F_10 ( V_61 -> V_69 . V_19 . V_81 ) >= V_33 -> V_68 . V_82 &&
V_61 -> V_69 . V_19 . V_81 != F_14 ( V_83 ) ) )
return false ;
if ( ! V_61 -> V_69 . V_19 . V_84 ||
( F_10 ( V_61 -> V_69 . V_19 . V_84 ) >= V_33 -> V_68 . V_82 &&
V_61 -> V_69 . V_19 . V_84 != F_14 ( V_83 ) ) )
return false ;
return true ;
}
static void
F_34 (
struct V_15 * V_43 )
{
if ( ! F_35 ( V_43 ) )
F_36 ( V_43 , V_85 ) ;
else if ( ! F_29 ( V_43 ) )
F_36 ( V_43 , V_86 ) ;
if ( V_43 -> V_87 ) {
F_37 ( V_43 , V_88 ) ;
F_38 ( V_43 ) ;
}
}
static void
F_39 (
struct V_15 * V_43 )
{
if ( ! F_29 ( V_43 ) ) {
F_37 ( V_43 , V_88 ) ;
F_36 ( V_43 , V_86 ) ;
F_38 ( V_43 ) ;
return;
}
F_40 ( V_43 ) ;
}
STATIC int
F_41 (
struct V_1 * V_2 ,
union V_45 * V_89 ,
union V_45 * V_90 )
{
return F_10 ( V_89 -> V_49 . V_50 ) <
F_10 ( V_90 -> V_49 . V_50 ) ;
}
STATIC int
F_42 (
struct V_1 * V_2 ,
union V_47 * V_91 ,
union V_47 * V_92 )
{
return F_10 ( V_91 -> V_49 . V_50 ) + V_93 <=
F_10 ( V_92 -> V_49 . V_50 ) ;
}
struct V_1 *
F_3 (
struct V_57 * V_33 ,
struct V_94 * V_32 ,
struct V_15 * V_9 ,
T_5 V_10 ,
T_6 V_95 )
{
struct V_16 * V_17 = F_5 ( V_9 ) ;
struct V_1 * V_2 ;
V_2 = F_43 ( V_96 , V_97 ) ;
V_2 -> V_6 = V_32 ;
V_2 -> V_4 = V_33 ;
V_2 -> V_11 = V_95 ;
if ( V_95 == V_98 ) {
V_2 -> V_99 = F_10 ( V_17 -> V_20 ) ;
V_2 -> V_100 = & V_101 ;
} else {
V_2 -> V_99 = F_10 ( V_17 -> V_24 ) ;
V_2 -> V_100 = & V_102 ;
}
V_2 -> V_103 = V_33 -> V_68 . V_104 ;
if ( F_31 ( & V_33 -> V_68 ) )
V_2 -> V_105 |= V_106 ;
V_2 -> V_7 . V_8 . V_9 = V_9 ;
V_2 -> V_7 . V_8 . V_10 = V_10 ;
return V_2 ;
}
int
F_44 (
struct V_57 * V_33 ,
int V_107 ,
int V_108 )
{
V_107 -= F_45 ( V_33 ) ;
if ( V_108 )
return V_107 / sizeof( V_109 ) ;
return V_107 / ( sizeof( V_110 ) + sizeof( V_111 ) ) ;
}
