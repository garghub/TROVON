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
struct V_1 * V_2 ,
union V_54 * V_55 )
{
V_55 -> V_56 . V_57 = F_15 ( V_2 -> V_58 . V_59 . V_57 ) ;
if ( F_26 ( & V_2 -> V_4 -> V_60 ) ) {
V_55 -> V_56 . V_61 . V_62 . V_63 =
F_27 ( V_2 -> V_58 . V_59 . V_63 ) ;
V_55 -> V_56 . V_61 . V_62 . V_64 = V_2 -> V_58 . V_59 . V_64 ;
V_55 -> V_56 . V_61 . V_62 . V_65 = V_2 -> V_58 . V_59 . V_65 ;
} else {
V_55 -> V_56 . V_61 . V_66 . V_65 =
F_15 ( V_2 -> V_58 . V_59 . V_65 ) ;
}
V_55 -> V_56 . V_67 = F_28 ( V_2 -> V_58 . V_59 . V_67 ) ;
}
STATIC void
F_29 (
struct V_1 * V_2 ,
union V_12 * V_68 )
{
struct V_16 * V_17 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_10 ( V_17 -> V_69 ) ) ;
V_68 -> V_19 = V_17 -> V_18 ;
}
STATIC void
F_30 (
struct V_1 * V_2 ,
union V_12 * V_68 )
{
struct V_16 * V_17 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_10 ( V_17 -> V_69 ) ) ;
V_68 -> V_19 = V_17 -> V_23 ;
}
STATIC T_3
F_31 (
struct V_1 * V_2 ,
union V_52 * V_53 )
{
return ( T_3 ) F_10 ( V_53 -> V_56 . V_57 ) -
V_2 -> V_58 . V_59 . V_57 ;
}
static int
F_32 (
struct V_15 * V_49 )
{
struct V_70 * V_35 = V_49 -> V_71 -> V_72 ;
struct V_73 * V_74 = F_33 ( V_49 ) ;
unsigned int V_3 ;
switch ( V_74 -> V_75 ) {
case F_15 ( V_76 ) :
case F_15 ( V_77 ) :
if ( ! F_34 ( V_49 ) )
return false ;
case F_15 ( V_78 ) :
case F_15 ( V_79 ) :
break;
default:
return 0 ;
}
V_3 = F_35 ( V_74 -> V_80 ) ;
if ( V_3 >= V_35 -> V_81 )
return false ;
return F_36 ( V_49 , V_35 -> V_51 [ V_3 != 0 ] ) ;
}
static void
F_37 (
struct V_15 * V_49 )
{
if ( ! F_38 ( V_49 ) )
F_39 ( V_49 , - V_82 ) ;
else if ( ! F_32 ( V_49 ) )
F_39 ( V_49 , - V_83 ) ;
if ( V_49 -> V_84 ) {
F_40 ( V_49 , V_85 ) ;
F_41 ( V_49 ) ;
}
}
static void
F_42 (
struct V_15 * V_49 )
{
if ( ! F_32 ( V_49 ) ) {
F_40 ( V_49 , V_85 ) ;
F_39 ( V_49 , - V_83 ) ;
F_41 ( V_49 ) ;
return;
}
F_43 ( V_49 ) ;
}
STATIC int
F_44 (
struct V_1 * V_2 ,
union V_52 * V_86 ,
union V_52 * V_87 )
{
return F_10 ( V_86 -> V_56 . V_57 ) <
F_10 ( V_87 -> V_56 . V_57 ) ;
}
STATIC int
F_45 (
struct V_1 * V_2 ,
union V_54 * V_88 ,
union V_54 * V_89 )
{
return F_10 ( V_88 -> V_56 . V_57 ) + V_90 <=
F_10 ( V_89 -> V_56 . V_57 ) ;
}
struct V_1 *
F_3 (
struct V_70 * V_35 ,
struct V_91 * V_34 ,
struct V_15 * V_9 ,
T_4 V_10 ,
T_5 V_92 )
{
struct V_16 * V_17 = F_5 ( V_9 ) ;
struct V_1 * V_2 ;
V_2 = F_46 ( V_93 , V_94 ) ;
V_2 -> V_6 = V_34 ;
V_2 -> V_4 = V_35 ;
V_2 -> V_11 = V_92 ;
if ( V_92 == V_95 ) {
V_2 -> V_96 = F_10 ( V_17 -> V_20 ) ;
V_2 -> V_97 = & V_98 ;
V_2 -> V_99 = F_47 ( V_100 ) ;
} else {
V_2 -> V_96 = F_10 ( V_17 -> V_24 ) ;
V_2 -> V_97 = & V_101 ;
V_2 -> V_99 = F_47 ( V_102 ) ;
}
V_2 -> V_103 = V_35 -> V_60 . V_104 ;
if ( F_48 ( & V_35 -> V_60 ) )
V_2 -> V_105 |= V_106 ;
V_2 -> V_7 . V_8 . V_9 = V_9 ;
V_2 -> V_7 . V_8 . V_10 = V_10 ;
return V_2 ;
}
int
F_49 (
struct V_70 * V_35 ,
int V_107 ,
int V_108 )
{
V_107 -= F_50 ( V_35 ) ;
if ( V_108 )
return V_107 / sizeof( V_109 ) ;
return V_107 / ( sizeof( V_110 ) + sizeof( V_111 ) ) ;
}
T_6
F_51 (
struct V_112 * V_55 )
{
T_6 V_113 = 0 ;
T_6 V_114 ;
int V_115 ;
T_7 V_116 ;
V_114 = ( 1 << V_117 ) - 1 ;
V_116 = ~ V_55 -> V_63 & ( ( 1 << V_118 ) - 1 ) ;
V_115 = F_52 ( & V_116 , 1 , 0 ) ;
while ( V_115 != - 1 ) {
ASSERT ( V_115 < ( sizeof( V_55 -> V_63 ) * V_119 ) ) ;
V_113 |= ( V_114 <<
( V_115 * V_117 ) ) ;
V_115 = F_52 ( & V_116 , 1 , V_115 + 1 ) ;
}
return V_113 ;
}
int
F_53 (
struct V_70 * V_35 ,
struct V_112 * V_55 )
{
int V_120 = 0 ;
int V_115 = 0 ;
T_6 V_121 ;
int V_122 ;
V_122 = sizeof( V_121 ) / sizeof( unsigned int ) ;
V_121 = F_51 ( V_55 ) ;
V_115 = F_52 ( ( T_7 * ) & V_121 , V_122 , V_115 ) ;
while ( V_115 != - 1 ) {
V_120 ++ ;
V_115 = F_52 ( ( T_7 * ) & V_121 , V_122 ,
V_115 + 1 ) ;
}
if ( V_120 != V_55 -> V_64 )
return - V_83 ;
return 0 ;
}
static T_8
F_54 (
struct V_70 * V_35 )
{
if ( V_35 -> V_51 [ 0 ] == 0 )
return 0 ;
return F_55 ( V_35 , V_35 -> V_5 ,
( T_6 ) V_35 -> V_60 . V_123 * V_35 -> V_60 . V_124 /
V_90 ) ;
}
static int
F_56 (
struct V_70 * V_35 ,
T_4 V_10 ,
T_5 V_92 ,
T_8 * V_125 )
{
struct V_15 * V_9 ;
struct V_1 * V_2 ;
int error ;
error = F_57 ( V_35 , NULL , V_10 , & V_9 ) ;
if ( error )
return error ;
V_2 = F_3 ( V_35 , NULL , V_9 , V_10 , V_92 ) ;
error = F_58 ( V_2 , V_125 ) ;
F_59 ( V_2 , error ? V_126 : V_127 ) ;
F_60 ( V_9 ) ;
return error ;
}
int
F_61 (
struct V_70 * V_35 ,
T_4 V_10 ,
T_8 * V_128 ,
T_8 * V_129 )
{
T_8 V_130 = 0 ;
int error ;
if ( ! F_62 ( & V_35 -> V_60 ) )
return 0 ;
error = F_56 ( V_35 , V_10 , V_131 , & V_130 ) ;
if ( error )
return error ;
* V_128 += F_54 ( V_35 ) ;
* V_129 += V_130 ;
return 0 ;
}
