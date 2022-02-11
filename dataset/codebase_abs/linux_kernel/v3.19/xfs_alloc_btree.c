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
F_21 ( V_2 -> V_4 , V_35 ) ;
return 0 ;
}
STATIC void
F_22 (
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
if ( V_11 != F_23 ( V_38 ) )
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
V_43 = F_23 ( V_38 ) ;
if ( V_11 <= V_43 )
return;
ASSERT ( V_11 == V_43 + 1 ) ;
if ( V_43 ) {
T_4 * V_51 ;
V_51 = F_24 ( V_2 -> V_3 , V_38 , V_43 ) ;
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
F_25 (
struct V_1 * V_2 ,
int V_54 )
{
return V_2 -> V_3 -> V_55 [ V_54 != 0 ] ;
}
STATIC int
F_26 (
struct V_1 * V_2 ,
int V_54 )
{
return V_2 -> V_3 -> V_56 [ V_54 != 0 ] ;
}
STATIC void
F_27 (
union V_57 * V_58 ,
union V_39 * V_40 )
{
ASSERT ( V_40 -> V_46 . V_59 != 0 ) ;
V_58 -> V_46 . V_59 = V_40 -> V_46 . V_59 ;
V_58 -> V_46 . V_47 = V_40 -> V_46 . V_47 ;
}
STATIC void
F_28 (
union V_57 * V_58 ,
union V_39 * V_40 )
{
ASSERT ( V_58 -> V_46 . V_59 != 0 ) ;
V_40 -> V_46 . V_59 = V_58 -> V_46 . V_59 ;
V_40 -> V_46 . V_47 = V_58 -> V_46 . V_47 ;
}
STATIC void
F_29 (
struct V_1 * V_2 ,
union V_39 * V_40 )
{
ASSERT ( V_2 -> V_60 . V_6 . V_59 != 0 ) ;
V_40 -> V_46 . V_59 = F_15 ( V_2 -> V_60 . V_6 . V_59 ) ;
V_40 -> V_46 . V_47 = F_15 ( V_2 -> V_60 . V_6 . V_47 ) ;
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
STATIC T_5
F_31 (
struct V_1 * V_2 ,
union V_57 * V_58 )
{
T_6 * V_40 = & V_2 -> V_60 . V_6 ;
T_7 * V_61 = & V_58 -> V_46 ;
T_5 V_62 ;
if ( V_2 -> V_9 == V_63 ) {
return ( T_5 ) F_5 ( V_61 -> V_59 ) -
V_40 -> V_59 ;
}
V_62 = ( T_5 ) F_5 ( V_61 -> V_47 ) - V_40 -> V_47 ;
if ( V_62 )
return V_62 ;
return ( T_5 ) F_5 ( V_61 -> V_59 ) - V_40 -> V_59 ;
}
static bool
F_32 (
struct V_13 * V_35 )
{
struct V_64 * V_65 = V_35 -> V_66 -> V_67 ;
struct V_37 * V_38 = F_33 ( V_35 ) ;
struct V_19 * V_20 = V_35 -> V_68 ;
unsigned int V_54 ;
V_54 = F_34 ( V_38 -> V_69 ) ;
switch ( V_38 -> V_70 ) {
case F_15 ( V_71 ) :
if ( ! F_35 ( & V_65 -> V_72 ) )
return false ;
if ( ! F_36 ( & V_38 -> V_73 . V_21 . V_74 , & V_65 -> V_72 . V_75 ) )
return false ;
if ( V_38 -> V_73 . V_21 . V_76 != F_37 ( V_35 -> V_77 ) )
return false ;
if ( V_20 &&
F_5 ( V_38 -> V_73 . V_21 . V_78 ) != V_20 -> V_79 )
return false ;
case F_15 ( V_80 ) :
if ( V_20 && V_20 -> V_81 ) {
if ( V_54 >= V_20 -> V_24 [ V_82 ] )
return false ;
} else if ( V_54 >= V_65 -> V_83 )
return false ;
break;
case F_15 ( V_84 ) :
if ( ! F_35 ( & V_65 -> V_72 ) )
return false ;
if ( ! F_36 ( & V_38 -> V_73 . V_21 . V_74 , & V_65 -> V_72 . V_75 ) )
return false ;
if ( V_38 -> V_73 . V_21 . V_76 != F_37 ( V_35 -> V_77 ) )
return false ;
if ( V_20 &&
F_5 ( V_38 -> V_73 . V_21 . V_78 ) != V_20 -> V_79 )
return false ;
case F_15 ( V_85 ) :
if ( V_20 && V_20 -> V_81 ) {
if ( V_54 >= V_20 -> V_24 [ V_86 ] )
return false ;
} else if ( V_54 >= V_65 -> V_83 )
return false ;
break;
default:
return false ;
}
if ( F_34 ( V_38 -> V_87 ) > V_65 -> V_56 [ V_54 != 0 ] )
return false ;
if ( ! V_38 -> V_73 . V_21 . V_88 ||
( F_5 ( V_38 -> V_73 . V_21 . V_88 ) >= V_65 -> V_72 . V_89 &&
V_38 -> V_73 . V_21 . V_88 != F_15 ( V_33 ) ) )
return false ;
if ( ! V_38 -> V_73 . V_21 . V_90 ||
( F_5 ( V_38 -> V_73 . V_21 . V_90 ) >= V_65 -> V_72 . V_89 &&
V_38 -> V_73 . V_21 . V_90 != F_15 ( V_33 ) ) )
return false ;
return true ;
}
static void
F_38 (
struct V_13 * V_35 )
{
if ( ! F_39 ( V_35 ) )
F_40 ( V_35 , - V_91 ) ;
else if ( ! F_32 ( V_35 ) )
F_40 ( V_35 , - V_92 ) ;
if ( V_35 -> V_93 ) {
F_41 ( V_35 , V_94 ) ;
F_42 ( V_35 ) ;
}
}
static void
F_43 (
struct V_13 * V_35 )
{
if ( ! F_32 ( V_35 ) ) {
F_41 ( V_35 , V_94 ) ;
F_40 ( V_35 , - V_92 ) ;
F_42 ( V_35 ) ;
return;
}
F_44 ( V_35 ) ;
}
STATIC int
F_45 (
struct V_1 * V_2 ,
union V_57 * V_95 ,
union V_57 * V_96 )
{
if ( V_2 -> V_9 == V_63 ) {
return F_5 ( V_95 -> V_46 . V_59 ) <
F_5 ( V_96 -> V_46 . V_59 ) ;
} else {
return F_5 ( V_95 -> V_46 . V_47 ) <
F_5 ( V_96 -> V_46 . V_47 ) ||
( V_95 -> V_46 . V_47 == V_96 -> V_46 . V_47 &&
F_5 ( V_95 -> V_46 . V_59 ) <
F_5 ( V_96 -> V_46 . V_59 ) ) ;
}
}
STATIC int
F_46 (
struct V_1 * V_2 ,
union V_39 * V_97 ,
union V_39 * V_98 )
{
if ( V_2 -> V_9 == V_63 ) {
return F_5 ( V_97 -> V_46 . V_59 ) +
F_5 ( V_97 -> V_46 . V_47 ) <=
F_5 ( V_98 -> V_46 . V_59 ) ;
} else {
return F_5 ( V_97 -> V_46 . V_47 ) <
F_5 ( V_98 -> V_46 . V_47 ) ||
( V_97 -> V_46 . V_47 == V_98 -> V_46 . V_47 &&
F_5 ( V_97 -> V_46 . V_59 ) <
F_5 ( V_98 -> V_46 . V_59 ) ) ;
}
}
struct V_1 *
F_2 (
struct V_64 * V_65 ,
struct V_99 * V_100 ,
struct V_13 * V_7 ,
T_1 V_8 ,
T_8 V_18 )
{
struct V_14 * V_15 = F_4 ( V_7 ) ;
struct V_1 * V_2 ;
ASSERT ( V_18 == V_63 || V_18 == V_44 ) ;
V_2 = F_47 ( V_101 , V_102 ) ;
V_2 -> V_4 = V_100 ;
V_2 -> V_3 = V_65 ;
V_2 -> V_9 = V_18 ;
V_2 -> V_103 = V_65 -> V_72 . V_104 ;
V_2 -> V_105 = & V_106 ;
if ( V_18 == V_44 ) {
V_2 -> V_107 = F_5 ( V_15 -> V_23 [ V_44 ] ) ;
V_2 -> V_108 = V_109 ;
} else {
V_2 -> V_107 = F_5 ( V_15 -> V_23 [ V_63 ] ) ;
}
V_2 -> V_5 . V_6 . V_7 = V_7 ;
V_2 -> V_5 . V_6 . V_8 = V_8 ;
if ( F_35 ( & V_65 -> V_72 ) )
V_2 -> V_108 |= V_110 ;
return V_2 ;
}
int
F_48 (
struct V_64 * V_65 ,
int V_111 ,
int V_112 )
{
V_111 -= F_49 ( V_65 ) ;
if ( V_112 )
return V_111 / sizeof( T_4 ) ;
return V_111 / ( sizeof( T_7 ) + sizeof( V_113 ) ) ;
}
