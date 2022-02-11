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
int * V_29 ,
enum V_30 V_31 )
{
T_1 args ;
int error ;
T_2 V_32 = F_10 ( V_27 -> V_19 ) ;
F_11 ( V_2 , V_33 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_34 = V_2 -> V_6 ;
args . V_35 = V_2 -> V_4 ;
F_12 ( & args . V_36 , V_37 ) ;
args . V_38 = F_13 ( args . V_35 , V_2 -> V_7 . V_8 . V_10 , V_32 ) ;
args . V_39 = 1 ;
args . V_40 = 1 ;
args . V_41 = 1 ;
args . type = V_42 ;
args . V_31 = V_31 ;
error = F_14 ( & args ) ;
if ( error ) {
F_11 ( V_2 , V_43 ) ;
return error ;
}
if ( args . V_38 == V_44 ) {
F_11 ( V_2 , V_45 ) ;
* V_29 = 0 ;
return 0 ;
}
ASSERT ( args . V_46 == 1 ) ;
F_11 ( V_2 , V_45 ) ;
V_28 -> V_19 = F_15 ( F_16 ( args . V_35 , args . V_38 ) ) ;
* V_29 = 1 ;
return 0 ;
}
STATIC int
F_17 (
struct V_1 * V_2 ,
union V_12 * V_27 ,
union V_12 * V_28 ,
int * V_29 )
{
return F_9 ( V_2 , V_27 , V_28 , V_29 , V_47 ) ;
}
STATIC int
F_18 (
struct V_1 * V_2 ,
union V_12 * V_27 ,
union V_12 * V_28 ,
int * V_29 )
{
return F_9 ( V_2 , V_27 , V_28 , V_29 ,
V_48 ) ;
}
STATIC int
F_19 (
struct V_1 * V_2 ,
struct V_15 * V_49 )
{
struct V_50 V_36 ;
F_12 ( & V_36 , V_37 ) ;
return F_20 ( V_2 -> V_6 ,
F_21 ( V_2 -> V_4 , F_22 ( V_49 ) ) , 1 ,
& V_36 , V_47 ) ;
}
STATIC int
F_23 (
struct V_1 * V_2 ,
int V_3 )
{
return V_2 -> V_4 -> V_51 [ V_3 != 0 ] ;
}
STATIC void
F_24 (
union V_52 * V_53 ,
union V_54 * V_55 )
{
V_53 -> V_56 . V_57 = V_55 -> V_56 . V_57 ;
}
STATIC void
F_25 (
union V_52 * V_53 ,
union V_54 * V_55 )
{
T_3 V_58 ;
V_58 = F_10 ( V_55 -> V_56 . V_57 ) ;
V_58 += V_59 - 1 ;
V_53 -> V_56 . V_57 = F_15 ( V_58 ) ;
}
STATIC void
F_26 (
struct V_1 * V_2 ,
union V_54 * V_55 )
{
V_55 -> V_56 . V_57 = F_15 ( V_2 -> V_60 . V_61 . V_57 ) ;
if ( F_27 ( & V_2 -> V_4 -> V_62 ) ) {
V_55 -> V_56 . V_63 . V_64 . V_65 =
F_28 ( V_2 -> V_60 . V_61 . V_65 ) ;
V_55 -> V_56 . V_63 . V_64 . V_66 = V_2 -> V_60 . V_61 . V_66 ;
V_55 -> V_56 . V_63 . V_64 . V_67 = V_2 -> V_60 . V_61 . V_67 ;
} else {
V_55 -> V_56 . V_63 . V_68 . V_67 =
F_15 ( V_2 -> V_60 . V_61 . V_67 ) ;
}
V_55 -> V_56 . V_69 = F_29 ( V_2 -> V_60 . V_61 . V_69 ) ;
}
STATIC void
F_30 (
struct V_1 * V_2 ,
union V_12 * V_70 )
{
struct V_16 * V_17 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_10 ( V_17 -> V_71 ) ) ;
V_70 -> V_19 = V_17 -> V_18 ;
}
STATIC void
F_31 (
struct V_1 * V_2 ,
union V_12 * V_70 )
{
struct V_16 * V_17 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_10 ( V_17 -> V_71 ) ) ;
V_70 -> V_19 = V_17 -> V_23 ;
}
STATIC T_4
F_32 (
struct V_1 * V_2 ,
union V_52 * V_53 )
{
return ( T_4 ) F_10 ( V_53 -> V_56 . V_57 ) -
V_2 -> V_60 . V_61 . V_57 ;
}
STATIC T_4
F_33 (
struct V_1 * V_2 ,
union V_52 * V_72 ,
union V_52 * V_73 )
{
return ( T_4 ) F_10 ( V_72 -> V_56 . V_57 ) -
F_10 ( V_73 -> V_56 . V_57 ) ;
}
static int
F_34 (
struct V_15 * V_49 )
{
struct V_74 * V_35 = V_49 -> V_75 -> V_76 ;
struct V_77 * V_78 = F_35 ( V_49 ) ;
unsigned int V_3 ;
switch ( V_78 -> V_79 ) {
case F_15 ( V_80 ) :
case F_15 ( V_81 ) :
if ( ! F_36 ( V_49 ) )
return false ;
case F_15 ( V_82 ) :
case F_15 ( V_83 ) :
break;
default:
return 0 ;
}
V_3 = F_37 ( V_78 -> V_84 ) ;
if ( V_3 >= V_35 -> V_85 )
return false ;
return F_38 ( V_49 , V_35 -> V_51 [ V_3 != 0 ] ) ;
}
static void
F_39 (
struct V_15 * V_49 )
{
if ( ! F_40 ( V_49 ) )
F_41 ( V_49 , - V_86 ) ;
else if ( ! F_34 ( V_49 ) )
F_41 ( V_49 , - V_87 ) ;
if ( V_49 -> V_88 ) {
F_42 ( V_49 , V_89 ) ;
F_43 ( V_49 ) ;
}
}
static void
F_44 (
struct V_15 * V_49 )
{
if ( ! F_34 ( V_49 ) ) {
F_42 ( V_49 , V_89 ) ;
F_41 ( V_49 , - V_87 ) ;
F_43 ( V_49 ) ;
return;
}
F_45 ( V_49 ) ;
}
STATIC int
F_46 (
struct V_1 * V_2 ,
union V_52 * V_72 ,
union V_52 * V_73 )
{
return F_10 ( V_72 -> V_56 . V_57 ) <
F_10 ( V_73 -> V_56 . V_57 ) ;
}
STATIC int
F_47 (
struct V_1 * V_2 ,
union V_54 * V_90 ,
union V_54 * V_91 )
{
return F_10 ( V_90 -> V_56 . V_57 ) + V_59 <=
F_10 ( V_91 -> V_56 . V_57 ) ;
}
struct V_1 *
F_3 (
struct V_74 * V_35 ,
struct V_92 * V_34 ,
struct V_15 * V_9 ,
T_5 V_10 ,
T_6 V_93 )
{
struct V_16 * V_17 = F_5 ( V_9 ) ;
struct V_1 * V_2 ;
V_2 = F_48 ( V_94 , V_95 ) ;
V_2 -> V_6 = V_34 ;
V_2 -> V_4 = V_35 ;
V_2 -> V_11 = V_93 ;
if ( V_93 == V_96 ) {
V_2 -> V_97 = F_10 ( V_17 -> V_20 ) ;
V_2 -> V_98 = & V_99 ;
V_2 -> V_100 = F_49 ( V_101 ) ;
} else {
V_2 -> V_97 = F_10 ( V_17 -> V_24 ) ;
V_2 -> V_98 = & V_102 ;
V_2 -> V_100 = F_49 ( V_103 ) ;
}
V_2 -> V_104 = V_35 -> V_62 . V_105 ;
if ( F_50 ( & V_35 -> V_62 ) )
V_2 -> V_106 |= V_107 ;
V_2 -> V_7 . V_8 . V_9 = V_9 ;
V_2 -> V_7 . V_8 . V_10 = V_10 ;
return V_2 ;
}
int
F_51 (
struct V_74 * V_35 ,
int V_108 ,
int V_109 )
{
V_108 -= F_52 ( V_35 ) ;
if ( V_109 )
return V_108 / sizeof( V_110 ) ;
return V_108 / ( sizeof( V_111 ) + sizeof( V_112 ) ) ;
}
T_7
F_53 (
struct V_113 * V_55 )
{
T_7 V_114 = 0 ;
T_7 V_115 ;
int V_116 ;
T_8 V_117 ;
V_115 = ( 1 << V_118 ) - 1 ;
V_117 = ~ V_55 -> V_65 & ( ( 1 << V_119 ) - 1 ) ;
V_116 = F_54 ( & V_117 , 1 , 0 ) ;
while ( V_116 != - 1 ) {
ASSERT ( V_116 < ( sizeof( V_55 -> V_65 ) * V_120 ) ) ;
V_114 |= ( V_115 <<
( V_116 * V_118 ) ) ;
V_116 = F_54 ( & V_117 , 1 , V_116 + 1 ) ;
}
return V_114 ;
}
int
F_55 (
struct V_74 * V_35 ,
struct V_113 * V_55 )
{
int V_121 = 0 ;
int V_116 = 0 ;
T_7 V_122 ;
int V_123 ;
V_123 = sizeof( V_122 ) / sizeof( unsigned int ) ;
V_122 = F_53 ( V_55 ) ;
V_116 = F_54 ( ( T_8 * ) & V_122 , V_123 , V_116 ) ;
while ( V_116 != - 1 ) {
V_121 ++ ;
V_116 = F_54 ( ( T_8 * ) & V_122 , V_123 ,
V_116 + 1 ) ;
}
if ( V_121 != V_55 -> V_66 )
return - V_87 ;
return 0 ;
}
static T_9
F_56 (
struct V_74 * V_35 )
{
if ( V_35 -> V_51 [ 0 ] == 0 )
return 0 ;
return F_57 ( V_35 , V_35 -> V_5 ,
( T_7 ) V_35 -> V_62 . V_124 * V_35 -> V_62 . V_125 /
V_59 ) ;
}
static int
F_58 (
struct V_74 * V_35 ,
T_5 V_10 ,
T_6 V_93 ,
T_9 * V_126 )
{
struct V_15 * V_9 ;
struct V_1 * V_2 ;
int error ;
error = F_59 ( V_35 , NULL , V_10 , & V_9 ) ;
if ( error )
return error ;
V_2 = F_3 ( V_35 , NULL , V_9 , V_10 , V_93 ) ;
error = F_60 ( V_2 , V_126 ) ;
F_61 ( V_2 , error ? V_127 : V_128 ) ;
F_62 ( V_9 ) ;
return error ;
}
int
F_63 (
struct V_74 * V_35 ,
T_5 V_10 ,
T_9 * V_129 ,
T_9 * V_130 )
{
T_9 V_131 = 0 ;
int error ;
if ( ! F_64 ( & V_35 -> V_62 ) )
return 0 ;
error = F_58 ( V_35 , V_10 , V_132 , & V_131 ) ;
if ( error )
return error ;
* V_129 += F_56 ( V_35 ) ;
* V_130 += V_131 ;
return 0 ;
}
