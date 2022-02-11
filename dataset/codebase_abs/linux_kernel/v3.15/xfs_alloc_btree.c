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
int V_29 ,
int * V_30 )
{
int error ;
T_2 V_31 ;
F_11 ( V_2 , V_32 ) ;
error = F_12 ( V_2 -> V_4 , V_2 -> V_5 . V_6 . V_7 ,
& V_31 , 1 ) ;
if ( error ) {
F_11 ( V_2 , V_33 ) ;
return error ;
}
if ( V_31 == V_34 ) {
F_11 ( V_2 , V_35 ) ;
* V_30 = 0 ;
return 0 ;
}
F_13 ( V_2 -> V_3 , V_2 -> V_5 . V_6 . V_8 , V_31 , 1 , false ) ;
F_14 ( V_2 -> V_4 , 1 ) ;
V_28 -> V_21 = F_15 ( V_31 ) ;
F_11 ( V_2 , V_35 ) ;
* V_30 = 1 ;
return 0 ;
}
STATIC int
F_16 (
struct V_1 * V_2 ,
struct V_13 * V_36 )
{
struct V_13 * V_7 = V_2 -> V_5 . V_6 . V_7 ;
struct V_14 * V_15 = F_4 ( V_7 ) ;
T_2 V_31 ;
int error ;
V_31 = F_17 ( V_2 -> V_3 , F_18 ( V_36 ) ) ;
error = F_19 ( V_2 -> V_4 , V_7 , NULL , V_31 , 1 ) ;
if ( error )
return error ;
F_20 ( V_2 -> V_4 , F_5 ( V_15 -> V_17 ) , V_31 , 1 ,
V_37 ) ;
F_14 ( V_2 -> V_4 , - 1 ) ;
F_21 ( V_2 -> V_4 , V_36 ) ;
return 0 ;
}
STATIC void
F_22 (
struct V_1 * V_2 ,
struct V_38 * V_39 ,
union V_40 * V_41 ,
int V_11 ,
int V_42 )
{
struct V_14 * V_15 = F_4 ( V_2 -> V_5 . V_6 . V_7 ) ;
T_1 V_16 = F_5 ( V_15 -> V_17 ) ;
struct V_19 * V_20 ;
T_3 V_43 ;
int V_44 ;
ASSERT ( V_2 -> V_9 == V_45 ) ;
switch ( V_42 ) {
case V_46 :
if ( V_11 != F_23 ( V_39 ) )
return;
V_43 = V_41 -> V_47 . V_48 ;
break;
case V_49 :
if ( F_5 ( V_41 -> V_47 . V_48 ) <=
F_5 ( V_15 -> V_50 ) )
return;
V_43 = V_41 -> V_47 . V_48 ;
break;
case V_51 :
V_44 = F_23 ( V_39 ) ;
if ( V_11 <= V_44 )
return;
ASSERT ( V_11 == V_44 + 1 ) ;
if ( V_44 ) {
T_4 * V_52 ;
V_52 = F_24 ( V_2 -> V_3 , V_39 , V_44 ) ;
V_43 = V_52 -> V_48 ;
} else {
V_43 = 0 ;
}
break;
default:
ASSERT ( 0 ) ;
return;
}
V_15 -> V_50 = V_43 ;
V_20 = F_6 ( V_2 -> V_3 , V_16 ) ;
V_20 -> V_53 = F_5 ( V_43 ) ;
F_8 ( V_20 ) ;
F_9 ( V_2 -> V_4 , V_2 -> V_5 . V_6 . V_7 , V_54 ) ;
}
STATIC int
F_25 (
struct V_1 * V_2 ,
int V_55 )
{
return V_2 -> V_3 -> V_56 [ V_55 != 0 ] ;
}
STATIC int
F_26 (
struct V_1 * V_2 ,
int V_55 )
{
return V_2 -> V_3 -> V_57 [ V_55 != 0 ] ;
}
STATIC void
F_27 (
union V_58 * V_59 ,
union V_40 * V_41 )
{
ASSERT ( V_41 -> V_47 . V_60 != 0 ) ;
V_59 -> V_47 . V_60 = V_41 -> V_47 . V_60 ;
V_59 -> V_47 . V_48 = V_41 -> V_47 . V_48 ;
}
STATIC void
F_28 (
union V_58 * V_59 ,
union V_40 * V_41 )
{
ASSERT ( V_59 -> V_47 . V_60 != 0 ) ;
V_41 -> V_47 . V_60 = V_59 -> V_47 . V_60 ;
V_41 -> V_47 . V_48 = V_59 -> V_47 . V_48 ;
}
STATIC void
F_29 (
struct V_1 * V_2 ,
union V_40 * V_41 )
{
ASSERT ( V_2 -> V_61 . V_6 . V_60 != 0 ) ;
V_41 -> V_47 . V_60 = F_15 ( V_2 -> V_61 . V_6 . V_60 ) ;
V_41 -> V_47 . V_48 = F_15 ( V_2 -> V_61 . V_6 . V_48 ) ;
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
union V_58 * V_59 )
{
T_6 * V_41 = & V_2 -> V_61 . V_6 ;
T_7 * V_62 = & V_59 -> V_47 ;
T_5 V_63 ;
if ( V_2 -> V_9 == V_64 ) {
return ( T_5 ) F_5 ( V_62 -> V_60 ) -
V_41 -> V_60 ;
}
V_63 = ( T_5 ) F_5 ( V_62 -> V_48 ) - V_41 -> V_48 ;
if ( V_63 )
return V_63 ;
return ( T_5 ) F_5 ( V_62 -> V_60 ) - V_41 -> V_60 ;
}
static bool
F_32 (
struct V_13 * V_36 )
{
struct V_65 * V_66 = V_36 -> V_67 -> V_68 ;
struct V_38 * V_39 = F_33 ( V_36 ) ;
struct V_19 * V_20 = V_36 -> V_69 ;
unsigned int V_55 ;
V_55 = F_34 ( V_39 -> V_70 ) ;
switch ( V_39 -> V_71 ) {
case F_15 ( V_72 ) :
if ( ! F_35 ( & V_66 -> V_73 ) )
return false ;
if ( ! F_36 ( & V_39 -> V_74 . V_21 . V_75 , & V_66 -> V_73 . V_76 ) )
return false ;
if ( V_39 -> V_74 . V_21 . V_77 != F_37 ( V_36 -> V_78 ) )
return false ;
if ( V_20 &&
F_5 ( V_39 -> V_74 . V_21 . V_79 ) != V_20 -> V_80 )
return false ;
case F_15 ( V_81 ) :
if ( V_20 && V_20 -> V_82 ) {
if ( V_55 >= V_20 -> V_24 [ V_83 ] )
return false ;
} else if ( V_55 >= V_66 -> V_84 )
return false ;
break;
case F_15 ( V_85 ) :
if ( ! F_35 ( & V_66 -> V_73 ) )
return false ;
if ( ! F_36 ( & V_39 -> V_74 . V_21 . V_75 , & V_66 -> V_73 . V_76 ) )
return false ;
if ( V_39 -> V_74 . V_21 . V_77 != F_37 ( V_36 -> V_78 ) )
return false ;
if ( V_20 &&
F_5 ( V_39 -> V_74 . V_21 . V_79 ) != V_20 -> V_80 )
return false ;
case F_15 ( V_86 ) :
if ( V_20 && V_20 -> V_82 ) {
if ( V_55 >= V_20 -> V_24 [ V_87 ] )
return false ;
} else if ( V_55 >= V_66 -> V_84 )
return false ;
break;
default:
return false ;
}
if ( F_34 ( V_39 -> V_88 ) > V_66 -> V_57 [ V_55 != 0 ] )
return false ;
if ( ! V_39 -> V_74 . V_21 . V_89 ||
( F_5 ( V_39 -> V_74 . V_21 . V_89 ) >= V_66 -> V_73 . V_90 &&
V_39 -> V_74 . V_21 . V_89 != F_15 ( V_34 ) ) )
return false ;
if ( ! V_39 -> V_74 . V_21 . V_91 ||
( F_5 ( V_39 -> V_74 . V_21 . V_91 ) >= V_66 -> V_73 . V_90 &&
V_39 -> V_74 . V_21 . V_91 != F_15 ( V_34 ) ) )
return false ;
return true ;
}
static void
F_38 (
struct V_13 * V_36 )
{
if ( ! F_39 ( V_36 ) )
F_40 ( V_36 , V_92 ) ;
else if ( ! F_32 ( V_36 ) )
F_40 ( V_36 , V_93 ) ;
if ( V_36 -> V_94 ) {
F_41 ( V_36 , V_95 ) ;
F_42 ( V_36 ) ;
}
}
static void
F_43 (
struct V_13 * V_36 )
{
if ( ! F_32 ( V_36 ) ) {
F_41 ( V_36 , V_95 ) ;
F_40 ( V_36 , V_93 ) ;
F_42 ( V_36 ) ;
return;
}
F_44 ( V_36 ) ;
}
STATIC int
F_45 (
struct V_1 * V_2 ,
union V_58 * V_96 ,
union V_58 * V_97 )
{
if ( V_2 -> V_9 == V_64 ) {
return F_5 ( V_96 -> V_47 . V_60 ) <
F_5 ( V_97 -> V_47 . V_60 ) ;
} else {
return F_5 ( V_96 -> V_47 . V_48 ) <
F_5 ( V_97 -> V_47 . V_48 ) ||
( V_96 -> V_47 . V_48 == V_97 -> V_47 . V_48 &&
F_5 ( V_96 -> V_47 . V_60 ) <
F_5 ( V_97 -> V_47 . V_60 ) ) ;
}
}
STATIC int
F_46 (
struct V_1 * V_2 ,
union V_40 * V_98 ,
union V_40 * V_99 )
{
if ( V_2 -> V_9 == V_64 ) {
return F_5 ( V_98 -> V_47 . V_60 ) +
F_5 ( V_98 -> V_47 . V_48 ) <=
F_5 ( V_99 -> V_47 . V_60 ) ;
} else {
return F_5 ( V_98 -> V_47 . V_48 ) <
F_5 ( V_99 -> V_47 . V_48 ) ||
( V_98 -> V_47 . V_48 == V_99 -> V_47 . V_48 &&
F_5 ( V_98 -> V_47 . V_60 ) <
F_5 ( V_99 -> V_47 . V_60 ) ) ;
}
}
struct V_1 *
F_2 (
struct V_65 * V_66 ,
struct V_100 * V_101 ,
struct V_13 * V_7 ,
T_1 V_8 ,
T_8 V_18 )
{
struct V_14 * V_15 = F_4 ( V_7 ) ;
struct V_1 * V_2 ;
ASSERT ( V_18 == V_64 || V_18 == V_45 ) ;
V_2 = F_47 ( V_102 , V_103 ) ;
V_2 -> V_4 = V_101 ;
V_2 -> V_3 = V_66 ;
V_2 -> V_9 = V_18 ;
V_2 -> V_104 = V_66 -> V_73 . V_105 ;
V_2 -> V_106 = & V_107 ;
if ( V_18 == V_45 ) {
V_2 -> V_108 = F_5 ( V_15 -> V_23 [ V_45 ] ) ;
V_2 -> V_109 = V_110 ;
} else {
V_2 -> V_108 = F_5 ( V_15 -> V_23 [ V_64 ] ) ;
}
V_2 -> V_5 . V_6 . V_7 = V_7 ;
V_2 -> V_5 . V_6 . V_8 = V_8 ;
if ( F_35 ( & V_66 -> V_73 ) )
V_2 -> V_109 |= V_111 ;
return V_2 ;
}
int
F_48 (
struct V_65 * V_66 ,
int V_112 ,
int V_113 )
{
V_112 -= F_49 ( V_66 ) ;
if ( V_113 )
return V_112 / sizeof( T_4 ) ;
return V_112 / ( sizeof( T_7 ) + sizeof( V_114 ) ) ;
}
