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
if ( F_25 ( & V_2 -> V_4 -> V_53 ) ) {
V_48 -> V_49 . V_54 . V_55 . V_56 =
F_26 ( V_2 -> V_51 . V_52 . V_56 ) ;
V_48 -> V_49 . V_54 . V_55 . V_57 = V_2 -> V_51 . V_52 . V_57 ;
V_48 -> V_49 . V_54 . V_55 . V_58 = V_2 -> V_51 . V_52 . V_58 ;
} else {
V_48 -> V_49 . V_54 . V_59 . V_58 =
F_14 ( V_2 -> V_51 . V_52 . V_58 ) ;
}
V_48 -> V_49 . V_60 = F_27 ( V_2 -> V_51 . V_52 . V_60 ) ;
}
STATIC void
F_28 (
struct V_1 * V_2 ,
union V_12 * V_61 )
{
struct V_16 * V_17 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_10 ( V_17 -> V_62 ) ) ;
V_61 -> V_19 = V_17 -> V_18 ;
}
STATIC void
F_29 (
struct V_1 * V_2 ,
union V_12 * V_61 )
{
struct V_16 * V_17 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_10 ( V_17 -> V_62 ) ) ;
V_61 -> V_19 = V_17 -> V_23 ;
}
STATIC T_4
F_30 (
struct V_1 * V_2 ,
union V_45 * V_46 )
{
return ( T_4 ) F_10 ( V_46 -> V_49 . V_50 ) -
V_2 -> V_51 . V_52 . V_50 ;
}
static int
F_31 (
struct V_15 * V_43 )
{
struct V_63 * V_33 = V_43 -> V_64 -> V_65 ;
struct V_66 * V_67 = F_32 ( V_43 ) ;
struct V_68 * V_69 = V_43 -> V_70 ;
unsigned int V_3 ;
switch ( V_67 -> V_71 ) {
case F_14 ( V_72 ) :
case F_14 ( V_73 ) :
if ( ! F_33 ( & V_33 -> V_53 ) )
return false ;
if ( ! F_34 ( & V_67 -> V_74 . V_19 . V_75 , & V_33 -> V_53 . V_76 ) )
return false ;
if ( V_67 -> V_74 . V_19 . V_77 != F_27 ( V_43 -> V_78 ) )
return false ;
if ( V_69 &&
F_10 ( V_67 -> V_74 . V_19 . V_79 ) != V_69 -> V_80 )
return false ;
case F_14 ( V_81 ) :
case F_14 ( V_82 ) :
break;
default:
return 0 ;
}
V_3 = F_35 ( V_67 -> V_83 ) ;
if ( V_3 >= V_33 -> V_84 )
return false ;
if ( F_35 ( V_67 -> V_85 ) > V_33 -> V_44 [ V_3 != 0 ] )
return false ;
if ( ! V_67 -> V_74 . V_19 . V_86 ||
( F_10 ( V_67 -> V_74 . V_19 . V_86 ) >= V_33 -> V_53 . V_87 &&
V_67 -> V_74 . V_19 . V_86 != F_14 ( V_88 ) ) )
return false ;
if ( ! V_67 -> V_74 . V_19 . V_89 ||
( F_10 ( V_67 -> V_74 . V_19 . V_89 ) >= V_33 -> V_53 . V_87 &&
V_67 -> V_74 . V_19 . V_89 != F_14 ( V_88 ) ) )
return false ;
return true ;
}
static void
F_36 (
struct V_15 * V_43 )
{
if ( ! F_37 ( V_43 ) )
F_38 ( V_43 , - V_90 ) ;
else if ( ! F_31 ( V_43 ) )
F_38 ( V_43 , - V_91 ) ;
if ( V_43 -> V_92 ) {
F_39 ( V_43 , V_93 ) ;
F_40 ( V_43 ) ;
}
}
static void
F_41 (
struct V_15 * V_43 )
{
if ( ! F_31 ( V_43 ) ) {
F_39 ( V_43 , V_93 ) ;
F_38 ( V_43 , - V_91 ) ;
F_40 ( V_43 ) ;
return;
}
F_42 ( V_43 ) ;
}
STATIC int
F_43 (
struct V_1 * V_2 ,
union V_45 * V_94 ,
union V_45 * V_95 )
{
return F_10 ( V_94 -> V_49 . V_50 ) <
F_10 ( V_95 -> V_49 . V_50 ) ;
}
STATIC int
F_44 (
struct V_1 * V_2 ,
union V_47 * V_96 ,
union V_47 * V_97 )
{
return F_10 ( V_96 -> V_49 . V_50 ) + V_98 <=
F_10 ( V_97 -> V_49 . V_50 ) ;
}
struct V_1 *
F_3 (
struct V_63 * V_33 ,
struct V_99 * V_32 ,
struct V_15 * V_9 ,
T_5 V_10 ,
T_6 V_100 )
{
struct V_16 * V_17 = F_5 ( V_9 ) ;
struct V_1 * V_2 ;
V_2 = F_45 ( V_101 , V_102 ) ;
V_2 -> V_6 = V_32 ;
V_2 -> V_4 = V_33 ;
V_2 -> V_11 = V_100 ;
if ( V_100 == V_103 ) {
V_2 -> V_104 = F_10 ( V_17 -> V_20 ) ;
V_2 -> V_105 = & V_106 ;
} else {
V_2 -> V_104 = F_10 ( V_17 -> V_24 ) ;
V_2 -> V_105 = & V_107 ;
}
V_2 -> V_108 = V_33 -> V_53 . V_109 ;
if ( F_33 ( & V_33 -> V_53 ) )
V_2 -> V_110 |= V_111 ;
V_2 -> V_7 . V_8 . V_9 = V_9 ;
V_2 -> V_7 . V_8 . V_10 = V_10 ;
return V_2 ;
}
int
F_46 (
struct V_63 * V_33 ,
int V_112 ,
int V_113 )
{
V_112 -= F_47 ( V_33 ) ;
if ( V_113 )
return V_112 / sizeof( V_114 ) ;
return V_112 / ( sizeof( V_115 ) + sizeof( V_116 ) ) ;
}
T_7
F_48 (
struct V_117 * V_48 )
{
T_7 V_118 = 0 ;
T_7 V_119 ;
int V_120 ;
T_8 V_121 ;
V_119 = ( 1 << V_122 ) - 1 ;
V_121 = ~ V_48 -> V_56 & ( ( 1 << V_123 ) - 1 ) ;
V_120 = F_49 ( & V_121 , 1 , 0 ) ;
while ( V_120 != - 1 ) {
ASSERT ( V_120 < ( sizeof( V_48 -> V_56 ) * V_124 ) ) ;
V_118 |= ( V_119 <<
( V_120 * V_122 ) ) ;
V_120 = F_49 ( & V_121 , 1 , V_120 + 1 ) ;
}
return V_118 ;
}
int
F_50 (
struct V_63 * V_33 ,
struct V_117 * V_48 )
{
int V_125 = 0 ;
int V_120 = 0 ;
T_7 V_126 ;
int V_127 ;
V_127 = sizeof( V_126 ) / sizeof( unsigned int ) ;
V_126 = F_48 ( V_48 ) ;
V_120 = F_49 ( ( T_8 * ) & V_126 , V_127 , V_120 ) ;
while ( V_120 != - 1 ) {
V_125 ++ ;
V_120 = F_49 ( ( T_8 * ) & V_126 , V_127 ,
V_120 + 1 ) ;
}
if ( V_125 != V_48 -> V_57 )
return - V_91 ;
return 0 ;
}
