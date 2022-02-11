STATIC struct V_1 *
F_1 (
struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_2 -> V_4 ,
V_2 -> V_5 . V_6 . V_7 , V_2 -> V_5 . V_6 . V_8 ,
V_2 -> V_9 ) ;
}
STATIC void
F_3 (
struct V_1 * V_2 ,
union V_10 * V_11 ,
int V_12 )
{
struct V_13 * V_7 = V_2 -> V_5 . V_6 . V_7 ;
struct V_14 * V_15 = F_4 ( V_7 ) ;
T_1 V_16 = F_5 ( V_15 -> V_17 ) ;
int V_18 = V_2 -> V_9 ;
struct V_19 * V_20 = F_6 ( V_2 -> V_3 , V_16 ) ;
ASSERT ( V_11 -> V_21 != 0 ) ;
V_15 -> V_22 [ V_18 ] = V_11 -> V_21 ;
F_7 ( & V_15 -> V_23 [ V_18 ] , V_12 ) ;
V_20 -> V_24 [ V_18 ] += V_12 ;
F_8 ( V_20 ) ;
F_9 ( V_2 -> V_4 , V_7 , V_25 | V_26 ) ;
}
STATIC int
F_10 (
struct V_1 * V_2 ,
union V_10 * V_27 ,
union V_10 * V_28 ,
int * V_29 )
{
int error ;
T_2 V_30 ;
F_11 ( V_2 , V_31 ) ;
error = F_12 ( V_2 -> V_4 , V_2 -> V_5 . V_6 . V_7 ,
& V_30 , 1 ) ;
if ( error ) {
F_11 ( V_2 , V_32 ) ;
return error ;
}
if ( V_30 == V_33 ) {
F_11 ( V_2 , V_34 ) ;
* V_29 = 0 ;
return 0 ;
}
F_13 ( V_2 -> V_3 , V_2 -> V_5 . V_6 . V_8 , V_30 , 1 , false ) ;
F_14 ( V_2 -> V_4 , 1 ) ;
V_28 -> V_21 = F_15 ( V_30 ) ;
F_11 ( V_2 , V_34 ) ;
* V_29 = 1 ;
return 0 ;
}
STATIC int
F_16 (
struct V_1 * V_2 ,
struct V_13 * V_35 )
{
struct V_13 * V_7 = V_2 -> V_5 . V_6 . V_7 ;
struct V_14 * V_15 = F_4 ( V_7 ) ;
T_2 V_30 ;
int error ;
V_30 = F_17 ( V_2 -> V_3 , F_18 ( V_35 ) ) ;
error = F_19 ( V_2 -> V_4 , V_7 , NULL , V_30 , 1 ) ;
if ( error )
return error ;
F_20 ( V_2 -> V_4 , F_5 ( V_15 -> V_17 ) , V_30 , 1 ,
V_36 ) ;
F_14 ( V_2 -> V_4 , - 1 ) ;
return 0 ;
}
STATIC void
F_21 (
struct V_1 * V_2 ,
struct V_37 * V_38 ,
union V_39 * V_40 ,
int V_11 ,
int V_41 )
{
struct V_14 * V_15 = F_4 ( V_2 -> V_5 . V_6 . V_7 ) ;
T_1 V_16 = F_5 ( V_15 -> V_17 ) ;
struct V_19 * V_20 ;
T_3 V_42 ;
int V_43 ;
ASSERT ( V_2 -> V_9 == V_44 ) ;
switch ( V_41 ) {
case V_45 :
if ( V_11 != F_22 ( V_38 ) )
return;
V_42 = V_40 -> V_46 . V_47 ;
break;
case V_48 :
if ( F_5 ( V_40 -> V_46 . V_47 ) <=
F_5 ( V_15 -> V_49 ) )
return;
V_42 = V_40 -> V_46 . V_47 ;
break;
case V_50 :
V_43 = F_22 ( V_38 ) ;
if ( V_11 <= V_43 )
return;
ASSERT ( V_11 == V_43 + 1 ) ;
if ( V_43 ) {
T_4 * V_51 ;
V_51 = F_23 ( V_2 -> V_3 , V_38 , V_43 ) ;
V_42 = V_51 -> V_47 ;
} else {
V_42 = 0 ;
}
break;
default:
ASSERT ( 0 ) ;
return;
}
V_15 -> V_49 = V_42 ;
V_20 = F_6 ( V_2 -> V_3 , V_16 ) ;
V_20 -> V_52 = F_5 ( V_42 ) ;
F_8 ( V_20 ) ;
F_9 ( V_2 -> V_4 , V_2 -> V_5 . V_6 . V_7 , V_53 ) ;
}
STATIC int
F_24 (
struct V_1 * V_2 ,
int V_54 )
{
return V_2 -> V_3 -> V_55 [ V_54 != 0 ] ;
}
STATIC int
F_25 (
struct V_1 * V_2 ,
int V_54 )
{
return V_2 -> V_3 -> V_56 [ V_54 != 0 ] ;
}
STATIC void
F_26 (
union V_57 * V_58 ,
union V_39 * V_40 )
{
V_58 -> V_46 . V_59 = V_40 -> V_46 . V_59 ;
V_58 -> V_46 . V_47 = V_40 -> V_46 . V_47 ;
}
STATIC void
F_27 (
union V_57 * V_58 ,
union V_39 * V_40 )
{
T_5 V_60 ;
V_60 = F_5 ( V_40 -> V_46 . V_59 ) ;
V_60 += F_5 ( V_40 -> V_46 . V_47 ) - 1 ;
V_58 -> V_46 . V_59 = F_15 ( V_60 ) ;
V_58 -> V_46 . V_47 = 0 ;
}
STATIC void
F_28 (
union V_57 * V_58 ,
union V_39 * V_40 )
{
V_58 -> V_46 . V_47 = V_40 -> V_46 . V_47 ;
V_58 -> V_46 . V_59 = 0 ;
}
STATIC void
F_29 (
struct V_1 * V_2 ,
union V_39 * V_40 )
{
V_40 -> V_46 . V_59 = F_15 ( V_2 -> V_61 . V_6 . V_59 ) ;
V_40 -> V_46 . V_47 = F_15 ( V_2 -> V_61 . V_6 . V_47 ) ;
}
STATIC void
F_30 (
struct V_1 * V_2 ,
union V_10 * V_11 )
{
struct V_14 * V_15 = F_4 ( V_2 -> V_5 . V_6 . V_7 ) ;
ASSERT ( V_2 -> V_5 . V_6 . V_8 == F_5 ( V_15 -> V_17 ) ) ;
ASSERT ( V_15 -> V_22 [ V_2 -> V_9 ] != 0 ) ;
V_11 -> V_21 = V_15 -> V_22 [ V_2 -> V_9 ] ;
}
STATIC T_6
F_31 (
struct V_1 * V_2 ,
union V_57 * V_58 )
{
T_7 * V_40 = & V_2 -> V_61 . V_6 ;
T_8 * V_62 = & V_58 -> V_46 ;
return ( T_6 ) F_5 ( V_62 -> V_59 ) - V_40 -> V_59 ;
}
STATIC T_6
F_32 (
struct V_1 * V_2 ,
union V_57 * V_58 )
{
T_7 * V_40 = & V_2 -> V_61 . V_6 ;
T_8 * V_62 = & V_58 -> V_46 ;
T_6 V_63 ;
V_63 = ( T_6 ) F_5 ( V_62 -> V_47 ) - V_40 -> V_47 ;
if ( V_63 )
return V_63 ;
return ( T_6 ) F_5 ( V_62 -> V_59 ) - V_40 -> V_59 ;
}
STATIC T_6
F_33 (
struct V_1 * V_2 ,
union V_57 * V_64 ,
union V_57 * V_65 )
{
return ( T_6 ) F_5 ( V_64 -> V_46 . V_59 ) -
F_5 ( V_65 -> V_46 . V_59 ) ;
}
STATIC T_6
F_34 (
struct V_1 * V_2 ,
union V_57 * V_64 ,
union V_57 * V_65 )
{
T_6 V_63 ;
V_63 = F_5 ( V_64 -> V_46 . V_47 ) -
F_5 ( V_65 -> V_46 . V_47 ) ;
if ( V_63 )
return V_63 ;
return F_5 ( V_64 -> V_46 . V_59 ) -
F_5 ( V_65 -> V_46 . V_59 ) ;
}
static bool
F_35 (
struct V_13 * V_35 )
{
struct V_66 * V_67 = V_35 -> V_68 -> V_69 ;
struct V_37 * V_38 = F_36 ( V_35 ) ;
struct V_19 * V_20 = V_35 -> V_70 ;
unsigned int V_54 ;
V_54 = F_37 ( V_38 -> V_71 ) ;
switch ( V_38 -> V_72 ) {
case F_15 ( V_73 ) :
if ( ! F_38 ( V_35 ) )
return false ;
case F_15 ( V_74 ) :
if ( V_20 && V_20 -> V_75 ) {
if ( V_54 >= V_20 -> V_24 [ V_76 ] )
return false ;
} else if ( V_54 >= V_67 -> V_77 )
return false ;
break;
case F_15 ( V_78 ) :
if ( ! F_38 ( V_35 ) )
return false ;
case F_15 ( V_79 ) :
if ( V_20 && V_20 -> V_75 ) {
if ( V_54 >= V_20 -> V_24 [ V_80 ] )
return false ;
} else if ( V_54 >= V_67 -> V_77 )
return false ;
break;
default:
return false ;
}
return F_39 ( V_35 , V_67 -> V_56 [ V_54 != 0 ] ) ;
}
static void
F_40 (
struct V_13 * V_35 )
{
if ( ! F_41 ( V_35 ) )
F_42 ( V_35 , - V_81 ) ;
else if ( ! F_35 ( V_35 ) )
F_42 ( V_35 , - V_82 ) ;
if ( V_35 -> V_83 ) {
F_43 ( V_35 , V_84 ) ;
F_44 ( V_35 ) ;
}
}
static void
F_45 (
struct V_13 * V_35 )
{
if ( ! F_35 ( V_35 ) ) {
F_43 ( V_35 , V_84 ) ;
F_42 ( V_35 , - V_82 ) ;
F_44 ( V_35 ) ;
return;
}
F_46 ( V_35 ) ;
}
STATIC int
F_47 (
struct V_1 * V_2 ,
union V_57 * V_64 ,
union V_57 * V_65 )
{
return F_5 ( V_64 -> V_46 . V_59 ) <
F_5 ( V_65 -> V_46 . V_59 ) ;
}
STATIC int
F_48 (
struct V_1 * V_2 ,
union V_39 * V_85 ,
union V_39 * V_86 )
{
return F_5 ( V_85 -> V_46 . V_59 ) +
F_5 ( V_85 -> V_46 . V_47 ) <=
F_5 ( V_86 -> V_46 . V_59 ) ;
}
STATIC int
F_49 (
struct V_1 * V_2 ,
union V_57 * V_64 ,
union V_57 * V_65 )
{
return F_5 ( V_64 -> V_46 . V_47 ) <
F_5 ( V_65 -> V_46 . V_47 ) ||
( V_64 -> V_46 . V_47 == V_65 -> V_46 . V_47 &&
F_5 ( V_64 -> V_46 . V_59 ) <
F_5 ( V_65 -> V_46 . V_59 ) ) ;
}
STATIC int
F_50 (
struct V_1 * V_2 ,
union V_39 * V_85 ,
union V_39 * V_86 )
{
return F_5 ( V_85 -> V_46 . V_47 ) <
F_5 ( V_86 -> V_46 . V_47 ) ||
( V_85 -> V_46 . V_47 == V_86 -> V_46 . V_47 &&
F_5 ( V_85 -> V_46 . V_59 ) <
F_5 ( V_86 -> V_46 . V_59 ) ) ;
}
struct V_1 *
F_2 (
struct V_66 * V_67 ,
struct V_87 * V_88 ,
struct V_13 * V_7 ,
T_1 V_8 ,
T_9 V_18 )
{
struct V_14 * V_15 = F_4 ( V_7 ) ;
struct V_1 * V_2 ;
ASSERT ( V_18 == V_89 || V_18 == V_44 ) ;
V_2 = F_51 ( V_90 , V_91 ) ;
V_2 -> V_4 = V_88 ;
V_2 -> V_3 = V_67 ;
V_2 -> V_9 = V_18 ;
V_2 -> V_92 = V_67 -> V_93 . V_94 ;
if ( V_18 == V_44 ) {
V_2 -> V_95 = F_52 ( V_96 ) ;
V_2 -> V_97 = & V_98 ;
V_2 -> V_99 = F_5 ( V_15 -> V_23 [ V_44 ] ) ;
V_2 -> V_100 = V_101 ;
} else {
V_2 -> V_95 = F_52 ( V_102 ) ;
V_2 -> V_97 = & V_103 ;
V_2 -> V_99 = F_5 ( V_15 -> V_23 [ V_89 ] ) ;
}
V_2 -> V_5 . V_6 . V_7 = V_7 ;
V_2 -> V_5 . V_6 . V_8 = V_8 ;
if ( F_53 ( & V_67 -> V_93 ) )
V_2 -> V_100 |= V_104 ;
return V_2 ;
}
int
F_54 (
struct V_66 * V_67 ,
int V_105 ,
int V_106 )
{
V_105 -= F_55 ( V_67 ) ;
if ( V_106 )
return V_105 / sizeof( T_4 ) ;
return V_105 / ( sizeof( T_8 ) + sizeof( V_107 ) ) ;
}
