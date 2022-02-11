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
F_12 ( & args . V_34 , V_35 ) ;
args . V_36 = F_13 ( args . V_33 , V_2 -> V_7 . V_8 . V_10 , V_30 ) ;
args . V_37 = 1 ;
args . V_38 = 1 ;
args . V_39 = 1 ;
args . type = V_40 ;
error = F_14 ( & args ) ;
if ( error ) {
F_11 ( V_2 , V_41 ) ;
return error ;
}
if ( args . V_36 == V_42 ) {
F_11 ( V_2 , V_43 ) ;
* V_29 = 0 ;
return 0 ;
}
ASSERT ( args . V_44 == 1 ) ;
F_11 ( V_2 , V_43 ) ;
V_28 -> V_19 = F_15 ( F_16 ( args . V_33 , args . V_36 ) ) ;
* V_29 = 1 ;
return 0 ;
}
STATIC int
F_17 (
struct V_1 * V_2 ,
struct V_15 * V_45 )
{
struct V_46 V_34 ;
F_12 ( & V_34 , V_35 ) ;
return F_18 ( V_2 -> V_6 ,
F_19 ( V_2 -> V_4 , F_20 ( V_45 ) ) , 1 ,
& V_34 , V_47 ) ;
}
STATIC int
F_21 (
struct V_1 * V_2 ,
int V_3 )
{
return V_2 -> V_4 -> V_48 [ V_3 != 0 ] ;
}
STATIC void
F_22 (
union V_49 * V_50 ,
union V_51 * V_52 )
{
V_50 -> V_53 . V_54 = V_52 -> V_53 . V_54 ;
}
STATIC void
F_23 (
struct V_1 * V_2 ,
union V_51 * V_52 )
{
V_52 -> V_53 . V_54 = F_15 ( V_2 -> V_55 . V_56 . V_54 ) ;
if ( F_24 ( & V_2 -> V_4 -> V_57 ) ) {
V_52 -> V_53 . V_58 . V_59 . V_60 =
F_25 ( V_2 -> V_55 . V_56 . V_60 ) ;
V_52 -> V_53 . V_58 . V_59 . V_61 = V_2 -> V_55 . V_56 . V_61 ;
V_52 -> V_53 . V_58 . V_59 . V_62 = V_2 -> V_55 . V_56 . V_62 ;
} else {
V_52 -> V_53 . V_58 . V_63 . V_62 =
F_15 ( V_2 -> V_55 . V_56 . V_62 ) ;
}
V_52 -> V_53 . V_64 = F_26 ( V_2 -> V_55 . V_56 . V_64 ) ;
}
STATIC void
F_27 (
struct V_1 * V_2 ,
union V_12 * V_65 )
{
struct V_16 * V_17 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_10 ( V_17 -> V_66 ) ) ;
V_65 -> V_19 = V_17 -> V_18 ;
}
STATIC void
F_28 (
struct V_1 * V_2 ,
union V_12 * V_65 )
{
struct V_16 * V_17 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_10 ( V_17 -> V_66 ) ) ;
V_65 -> V_19 = V_17 -> V_23 ;
}
STATIC T_3
F_29 (
struct V_1 * V_2 ,
union V_49 * V_50 )
{
return ( T_3 ) F_10 ( V_50 -> V_53 . V_54 ) -
V_2 -> V_55 . V_56 . V_54 ;
}
static int
F_30 (
struct V_15 * V_45 )
{
struct V_67 * V_33 = V_45 -> V_68 -> V_69 ;
struct V_70 * V_71 = F_31 ( V_45 ) ;
unsigned int V_3 ;
switch ( V_71 -> V_72 ) {
case F_15 ( V_73 ) :
case F_15 ( V_74 ) :
if ( ! F_32 ( V_45 ) )
return false ;
case F_15 ( V_75 ) :
case F_15 ( V_76 ) :
break;
default:
return 0 ;
}
V_3 = F_33 ( V_71 -> V_77 ) ;
if ( V_3 >= V_33 -> V_78 )
return false ;
return F_34 ( V_45 , V_33 -> V_48 [ V_3 != 0 ] ) ;
}
static void
F_35 (
struct V_15 * V_45 )
{
if ( ! F_36 ( V_45 ) )
F_37 ( V_45 , - V_79 ) ;
else if ( ! F_30 ( V_45 ) )
F_37 ( V_45 , - V_80 ) ;
if ( V_45 -> V_81 ) {
F_38 ( V_45 , V_82 ) ;
F_39 ( V_45 ) ;
}
}
static void
F_40 (
struct V_15 * V_45 )
{
if ( ! F_30 ( V_45 ) ) {
F_38 ( V_45 , V_82 ) ;
F_37 ( V_45 , - V_80 ) ;
F_39 ( V_45 ) ;
return;
}
F_41 ( V_45 ) ;
}
STATIC int
F_42 (
struct V_1 * V_2 ,
union V_49 * V_83 ,
union V_49 * V_84 )
{
return F_10 ( V_83 -> V_53 . V_54 ) <
F_10 ( V_84 -> V_53 . V_54 ) ;
}
STATIC int
F_43 (
struct V_1 * V_2 ,
union V_51 * V_85 ,
union V_51 * V_86 )
{
return F_10 ( V_85 -> V_53 . V_54 ) + V_87 <=
F_10 ( V_86 -> V_53 . V_54 ) ;
}
struct V_1 *
F_3 (
struct V_67 * V_33 ,
struct V_88 * V_32 ,
struct V_15 * V_9 ,
T_4 V_10 ,
T_5 V_89 )
{
struct V_16 * V_17 = F_5 ( V_9 ) ;
struct V_1 * V_2 ;
V_2 = F_44 ( V_90 , V_91 ) ;
V_2 -> V_6 = V_32 ;
V_2 -> V_4 = V_33 ;
V_2 -> V_11 = V_89 ;
if ( V_89 == V_92 ) {
V_2 -> V_93 = F_10 ( V_17 -> V_20 ) ;
V_2 -> V_94 = & V_95 ;
} else {
V_2 -> V_93 = F_10 ( V_17 -> V_24 ) ;
V_2 -> V_94 = & V_96 ;
}
V_2 -> V_97 = V_33 -> V_57 . V_98 ;
if ( F_45 ( & V_33 -> V_57 ) )
V_2 -> V_99 |= V_100 ;
V_2 -> V_7 . V_8 . V_9 = V_9 ;
V_2 -> V_7 . V_8 . V_10 = V_10 ;
return V_2 ;
}
int
F_46 (
struct V_67 * V_33 ,
int V_101 ,
int V_102 )
{
V_101 -= F_47 ( V_33 ) ;
if ( V_102 )
return V_101 / sizeof( V_103 ) ;
return V_101 / ( sizeof( V_104 ) + sizeof( V_105 ) ) ;
}
T_6
F_48 (
struct V_106 * V_52 )
{
T_6 V_107 = 0 ;
T_6 V_108 ;
int V_109 ;
T_7 V_110 ;
V_108 = ( 1 << V_111 ) - 1 ;
V_110 = ~ V_52 -> V_60 & ( ( 1 << V_112 ) - 1 ) ;
V_109 = F_49 ( & V_110 , 1 , 0 ) ;
while ( V_109 != - 1 ) {
ASSERT ( V_109 < ( sizeof( V_52 -> V_60 ) * V_113 ) ) ;
V_107 |= ( V_108 <<
( V_109 * V_111 ) ) ;
V_109 = F_49 ( & V_110 , 1 , V_109 + 1 ) ;
}
return V_107 ;
}
int
F_50 (
struct V_67 * V_33 ,
struct V_106 * V_52 )
{
int V_114 = 0 ;
int V_109 = 0 ;
T_6 V_115 ;
int V_116 ;
V_116 = sizeof( V_115 ) / sizeof( unsigned int ) ;
V_115 = F_48 ( V_52 ) ;
V_109 = F_49 ( ( T_7 * ) & V_115 , V_116 , V_109 ) ;
while ( V_109 != - 1 ) {
V_114 ++ ;
V_109 = F_49 ( ( T_7 * ) & V_115 , V_116 ,
V_109 + 1 ) ;
}
if ( V_114 != V_52 -> V_61 )
return - V_80 ;
return 0 ;
}
