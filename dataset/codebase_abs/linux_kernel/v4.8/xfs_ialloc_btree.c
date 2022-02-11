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
& V_34 ) ;
}
STATIC int
F_21 (
struct V_1 * V_2 ,
int V_3 )
{
return V_2 -> V_4 -> V_47 [ V_3 != 0 ] ;
}
STATIC void
F_22 (
union V_48 * V_49 ,
union V_50 * V_51 )
{
V_49 -> V_52 . V_53 = V_51 -> V_52 . V_53 ;
}
STATIC void
F_23 (
struct V_1 * V_2 ,
union V_50 * V_51 )
{
V_51 -> V_52 . V_53 = F_15 ( V_2 -> V_54 . V_55 . V_53 ) ;
if ( F_24 ( & V_2 -> V_4 -> V_56 ) ) {
V_51 -> V_52 . V_57 . V_58 . V_59 =
F_25 ( V_2 -> V_54 . V_55 . V_59 ) ;
V_51 -> V_52 . V_57 . V_58 . V_60 = V_2 -> V_54 . V_55 . V_60 ;
V_51 -> V_52 . V_57 . V_58 . V_61 = V_2 -> V_54 . V_55 . V_61 ;
} else {
V_51 -> V_52 . V_57 . V_62 . V_61 =
F_15 ( V_2 -> V_54 . V_55 . V_61 ) ;
}
V_51 -> V_52 . V_63 = F_26 ( V_2 -> V_54 . V_55 . V_63 ) ;
}
STATIC void
F_27 (
struct V_1 * V_2 ,
union V_12 * V_64 )
{
struct V_16 * V_17 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_10 ( V_17 -> V_65 ) ) ;
V_64 -> V_19 = V_17 -> V_18 ;
}
STATIC void
F_28 (
struct V_1 * V_2 ,
union V_12 * V_64 )
{
struct V_16 * V_17 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_10 ( V_17 -> V_65 ) ) ;
V_64 -> V_19 = V_17 -> V_23 ;
}
STATIC T_3
F_29 (
struct V_1 * V_2 ,
union V_48 * V_49 )
{
return ( T_3 ) F_10 ( V_49 -> V_52 . V_53 ) -
V_2 -> V_54 . V_55 . V_53 ;
}
static int
F_30 (
struct V_15 * V_45 )
{
struct V_66 * V_33 = V_45 -> V_67 -> V_68 ;
struct V_69 * V_70 = F_31 ( V_45 ) ;
unsigned int V_3 ;
switch ( V_70 -> V_71 ) {
case F_15 ( V_72 ) :
case F_15 ( V_73 ) :
if ( ! F_32 ( V_45 ) )
return false ;
case F_15 ( V_74 ) :
case F_15 ( V_75 ) :
break;
default:
return 0 ;
}
V_3 = F_33 ( V_70 -> V_76 ) ;
if ( V_3 >= V_33 -> V_77 )
return false ;
return F_34 ( V_45 , V_33 -> V_47 [ V_3 != 0 ] ) ;
}
static void
F_35 (
struct V_15 * V_45 )
{
if ( ! F_36 ( V_45 ) )
F_37 ( V_45 , - V_78 ) ;
else if ( ! F_30 ( V_45 ) )
F_37 ( V_45 , - V_79 ) ;
if ( V_45 -> V_80 ) {
F_38 ( V_45 , V_81 ) ;
F_39 ( V_45 ) ;
}
}
static void
F_40 (
struct V_15 * V_45 )
{
if ( ! F_30 ( V_45 ) ) {
F_38 ( V_45 , V_81 ) ;
F_37 ( V_45 , - V_79 ) ;
F_39 ( V_45 ) ;
return;
}
F_41 ( V_45 ) ;
}
STATIC int
F_42 (
struct V_1 * V_2 ,
union V_48 * V_82 ,
union V_48 * V_83 )
{
return F_10 ( V_82 -> V_52 . V_53 ) <
F_10 ( V_83 -> V_52 . V_53 ) ;
}
STATIC int
F_43 (
struct V_1 * V_2 ,
union V_50 * V_84 ,
union V_50 * V_85 )
{
return F_10 ( V_84 -> V_52 . V_53 ) + V_86 <=
F_10 ( V_85 -> V_52 . V_53 ) ;
}
struct V_1 *
F_3 (
struct V_66 * V_33 ,
struct V_87 * V_32 ,
struct V_15 * V_9 ,
T_4 V_10 ,
T_5 V_88 )
{
struct V_16 * V_17 = F_5 ( V_9 ) ;
struct V_1 * V_2 ;
V_2 = F_44 ( V_89 , V_90 ) ;
V_2 -> V_6 = V_32 ;
V_2 -> V_4 = V_33 ;
V_2 -> V_11 = V_88 ;
if ( V_88 == V_91 ) {
V_2 -> V_92 = F_10 ( V_17 -> V_20 ) ;
V_2 -> V_93 = & V_94 ;
} else {
V_2 -> V_92 = F_10 ( V_17 -> V_24 ) ;
V_2 -> V_93 = & V_95 ;
}
V_2 -> V_96 = V_33 -> V_56 . V_97 ;
if ( F_45 ( & V_33 -> V_56 ) )
V_2 -> V_98 |= V_99 ;
V_2 -> V_7 . V_8 . V_9 = V_9 ;
V_2 -> V_7 . V_8 . V_10 = V_10 ;
return V_2 ;
}
int
F_46 (
struct V_66 * V_33 ,
int V_100 ,
int V_101 )
{
V_100 -= F_47 ( V_33 ) ;
if ( V_101 )
return V_100 / sizeof( V_102 ) ;
return V_100 / ( sizeof( V_103 ) + sizeof( V_104 ) ) ;
}
T_6
F_48 (
struct V_105 * V_51 )
{
T_6 V_106 = 0 ;
T_6 V_107 ;
int V_108 ;
T_7 V_109 ;
V_107 = ( 1 << V_110 ) - 1 ;
V_109 = ~ V_51 -> V_59 & ( ( 1 << V_111 ) - 1 ) ;
V_108 = F_49 ( & V_109 , 1 , 0 ) ;
while ( V_108 != - 1 ) {
ASSERT ( V_108 < ( sizeof( V_51 -> V_59 ) * V_112 ) ) ;
V_106 |= ( V_107 <<
( V_108 * V_110 ) ) ;
V_108 = F_49 ( & V_109 , 1 , V_108 + 1 ) ;
}
return V_106 ;
}
int
F_50 (
struct V_66 * V_33 ,
struct V_105 * V_51 )
{
int V_113 = 0 ;
int V_108 = 0 ;
T_6 V_114 ;
int V_115 ;
V_115 = sizeof( V_114 ) / sizeof( unsigned int ) ;
V_114 = F_48 ( V_51 ) ;
V_108 = F_49 ( ( T_7 * ) & V_114 , V_115 , V_108 ) ;
while ( V_108 != - 1 ) {
V_113 ++ ;
V_108 = F_49 ( ( T_7 * ) & V_114 , V_115 ,
V_108 + 1 ) ;
}
if ( V_113 != V_51 -> V_60 )
return - V_79 ;
return 0 ;
}
