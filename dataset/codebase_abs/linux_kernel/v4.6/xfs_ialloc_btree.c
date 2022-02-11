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
return F_17 ( V_2 -> V_6 ,
F_18 ( V_2 -> V_4 , F_19 ( V_43 ) ) , 1 ) ;
}
STATIC int
F_20 (
struct V_1 * V_2 ,
int V_3 )
{
return V_2 -> V_4 -> V_44 [ V_3 != 0 ] ;
}
STATIC void
F_21 (
union V_45 * V_46 ,
union V_47 * V_48 )
{
V_46 -> V_49 . V_50 = V_48 -> V_49 . V_50 ;
}
STATIC void
F_22 (
union V_45 * V_46 ,
union V_47 * V_48 )
{
V_48 -> V_49 . V_50 = V_46 -> V_49 . V_50 ;
}
STATIC void
F_23 (
struct V_1 * V_2 ,
union V_47 * V_48 )
{
V_48 -> V_49 . V_50 = F_14 ( V_2 -> V_51 . V_52 . V_50 ) ;
if ( F_24 ( & V_2 -> V_4 -> V_53 ) ) {
V_48 -> V_49 . V_54 . V_55 . V_56 =
F_25 ( V_2 -> V_51 . V_52 . V_56 ) ;
V_48 -> V_49 . V_54 . V_55 . V_57 = V_2 -> V_51 . V_52 . V_57 ;
V_48 -> V_49 . V_54 . V_55 . V_58 = V_2 -> V_51 . V_52 . V_58 ;
} else {
V_48 -> V_49 . V_54 . V_59 . V_58 =
F_14 ( V_2 -> V_51 . V_52 . V_58 ) ;
}
V_48 -> V_49 . V_60 = F_26 ( V_2 -> V_51 . V_52 . V_60 ) ;
}
STATIC void
F_27 (
struct V_1 * V_2 ,
union V_12 * V_61 )
{
struct V_16 * V_17 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_10 ( V_17 -> V_62 ) ) ;
V_61 -> V_19 = V_17 -> V_18 ;
}
STATIC void
F_28 (
struct V_1 * V_2 ,
union V_12 * V_61 )
{
struct V_16 * V_17 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_10 ( V_17 -> V_62 ) ) ;
V_61 -> V_19 = V_17 -> V_23 ;
}
STATIC T_3
F_29 (
struct V_1 * V_2 ,
union V_45 * V_46 )
{
return ( T_3 ) F_10 ( V_46 -> V_49 . V_50 ) -
V_2 -> V_51 . V_52 . V_50 ;
}
static int
F_30 (
struct V_15 * V_43 )
{
struct V_63 * V_33 = V_43 -> V_64 -> V_65 ;
struct V_66 * V_67 = F_31 ( V_43 ) ;
unsigned int V_3 ;
switch ( V_67 -> V_68 ) {
case F_14 ( V_69 ) :
case F_14 ( V_70 ) :
if ( ! F_32 ( V_43 ) )
return false ;
case F_14 ( V_71 ) :
case F_14 ( V_72 ) :
break;
default:
return 0 ;
}
V_3 = F_33 ( V_67 -> V_73 ) ;
if ( V_3 >= V_33 -> V_74 )
return false ;
return F_34 ( V_43 , V_33 -> V_44 [ V_3 != 0 ] ) ;
}
static void
F_35 (
struct V_15 * V_43 )
{
if ( ! F_36 ( V_43 ) )
F_37 ( V_43 , - V_75 ) ;
else if ( ! F_30 ( V_43 ) )
F_37 ( V_43 , - V_76 ) ;
if ( V_43 -> V_77 ) {
F_38 ( V_43 , V_78 ) ;
F_39 ( V_43 ) ;
}
}
static void
F_40 (
struct V_15 * V_43 )
{
if ( ! F_30 ( V_43 ) ) {
F_38 ( V_43 , V_78 ) ;
F_37 ( V_43 , - V_76 ) ;
F_39 ( V_43 ) ;
return;
}
F_41 ( V_43 ) ;
}
STATIC int
F_42 (
struct V_1 * V_2 ,
union V_45 * V_79 ,
union V_45 * V_80 )
{
return F_10 ( V_79 -> V_49 . V_50 ) <
F_10 ( V_80 -> V_49 . V_50 ) ;
}
STATIC int
F_43 (
struct V_1 * V_2 ,
union V_47 * V_81 ,
union V_47 * V_82 )
{
return F_10 ( V_81 -> V_49 . V_50 ) + V_83 <=
F_10 ( V_82 -> V_49 . V_50 ) ;
}
struct V_1 *
F_3 (
struct V_63 * V_33 ,
struct V_84 * V_32 ,
struct V_15 * V_9 ,
T_4 V_10 ,
T_5 V_85 )
{
struct V_16 * V_17 = F_5 ( V_9 ) ;
struct V_1 * V_2 ;
V_2 = F_44 ( V_86 , V_87 ) ;
V_2 -> V_6 = V_32 ;
V_2 -> V_4 = V_33 ;
V_2 -> V_11 = V_85 ;
if ( V_85 == V_88 ) {
V_2 -> V_89 = F_10 ( V_17 -> V_20 ) ;
V_2 -> V_90 = & V_91 ;
} else {
V_2 -> V_89 = F_10 ( V_17 -> V_24 ) ;
V_2 -> V_90 = & V_92 ;
}
V_2 -> V_93 = V_33 -> V_53 . V_94 ;
if ( F_45 ( & V_33 -> V_53 ) )
V_2 -> V_95 |= V_96 ;
V_2 -> V_7 . V_8 . V_9 = V_9 ;
V_2 -> V_7 . V_8 . V_10 = V_10 ;
return V_2 ;
}
int
F_46 (
struct V_63 * V_33 ,
int V_97 ,
int V_98 )
{
V_97 -= F_47 ( V_33 ) ;
if ( V_98 )
return V_97 / sizeof( V_99 ) ;
return V_97 / ( sizeof( V_100 ) + sizeof( V_101 ) ) ;
}
T_6
F_48 (
struct V_102 * V_48 )
{
T_6 V_103 = 0 ;
T_6 V_104 ;
int V_105 ;
T_7 V_106 ;
V_104 = ( 1 << V_107 ) - 1 ;
V_106 = ~ V_48 -> V_56 & ( ( 1 << V_108 ) - 1 ) ;
V_105 = F_49 ( & V_106 , 1 , 0 ) ;
while ( V_105 != - 1 ) {
ASSERT ( V_105 < ( sizeof( V_48 -> V_56 ) * V_109 ) ) ;
V_103 |= ( V_104 <<
( V_105 * V_107 ) ) ;
V_105 = F_49 ( & V_106 , 1 , V_105 + 1 ) ;
}
return V_103 ;
}
int
F_50 (
struct V_63 * V_33 ,
struct V_102 * V_48 )
{
int V_110 = 0 ;
int V_105 = 0 ;
T_6 V_111 ;
int V_112 ;
V_112 = sizeof( V_111 ) / sizeof( unsigned int ) ;
V_111 = F_48 ( V_48 ) ;
V_105 = F_49 ( ( T_7 * ) & V_111 , V_112 , V_105 ) ;
while ( V_105 != - 1 ) {
V_110 ++ ;
V_105 = F_49 ( ( T_7 * ) & V_111 , V_112 ,
V_105 + 1 ) ;
}
if ( V_110 != V_48 -> V_57 )
return - V_76 ;
return 0 ;
}
