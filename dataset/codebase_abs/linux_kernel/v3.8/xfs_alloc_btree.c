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
static void
F_32 (
struct V_13 * V_36 )
{
struct V_65 * V_66 = V_36 -> V_67 -> V_68 ;
struct V_38 * V_39 = F_33 ( V_36 ) ;
struct V_19 * V_20 = V_36 -> V_69 ;
unsigned int V_55 ;
int V_70 ;
V_55 = F_34 ( V_39 -> V_71 ) ;
switch ( V_39 -> V_72 ) {
case F_15 ( V_73 ) :
if ( V_20 )
V_70 = V_55 < V_20 -> V_24 [ V_74 ] ;
else
V_70 = V_55 < V_66 -> V_75 ;
break;
case F_15 ( V_76 ) :
if ( V_20 )
V_70 = V_55 < V_20 -> V_24 [ V_77 ] ;
else
V_70 = V_55 < V_66 -> V_75 ;
break;
default:
V_70 = 0 ;
break;
}
V_70 = V_70 &&
F_34 ( V_39 -> V_78 ) <= V_66 -> V_57 [ V_55 != 0 ] ;
V_70 = V_70 &&
( V_39 -> V_79 . V_21 . V_80 == F_15 ( V_34 ) ||
F_5 ( V_39 -> V_79 . V_21 . V_80 ) < V_66 -> V_81 . V_82 ) &&
V_39 -> V_79 . V_21 . V_80 &&
( V_39 -> V_79 . V_21 . V_83 == F_15 ( V_34 ) ||
F_5 ( V_39 -> V_79 . V_21 . V_83 ) < V_66 -> V_81 . V_82 ) &&
V_39 -> V_79 . V_21 . V_83 ;
if ( ! V_70 ) {
F_35 ( V_36 , V_84 ) ;
F_36 ( V_85 , V_86 , V_66 , V_39 ) ;
F_37 ( V_36 , V_87 ) ;
}
}
static void
F_38 (
struct V_13 * V_36 )
{
F_32 ( V_36 ) ;
}
static void
F_39 (
struct V_13 * V_36 )
{
F_32 ( V_36 ) ;
}
STATIC int
F_40 (
struct V_1 * V_2 ,
union V_58 * V_88 ,
union V_58 * V_89 )
{
if ( V_2 -> V_9 == V_64 ) {
return F_5 ( V_88 -> V_47 . V_60 ) <
F_5 ( V_89 -> V_47 . V_60 ) ;
} else {
return F_5 ( V_88 -> V_47 . V_48 ) <
F_5 ( V_89 -> V_47 . V_48 ) ||
( V_88 -> V_47 . V_48 == V_89 -> V_47 . V_48 &&
F_5 ( V_88 -> V_47 . V_60 ) <
F_5 ( V_89 -> V_47 . V_60 ) ) ;
}
}
STATIC int
F_41 (
struct V_1 * V_2 ,
union V_40 * V_90 ,
union V_40 * V_91 )
{
if ( V_2 -> V_9 == V_64 ) {
return F_5 ( V_90 -> V_47 . V_60 ) +
F_5 ( V_90 -> V_47 . V_48 ) <=
F_5 ( V_91 -> V_47 . V_60 ) ;
} else {
return F_5 ( V_90 -> V_47 . V_48 ) <
F_5 ( V_91 -> V_47 . V_48 ) ||
( V_90 -> V_47 . V_48 == V_91 -> V_47 . V_48 &&
F_5 ( V_90 -> V_47 . V_60 ) <
F_5 ( V_91 -> V_47 . V_60 ) ) ;
}
}
struct V_1 *
F_2 (
struct V_65 * V_66 ,
struct V_92 * V_93 ,
struct V_13 * V_7 ,
T_1 V_8 ,
T_8 V_18 )
{
struct V_14 * V_15 = F_4 ( V_7 ) ;
struct V_1 * V_2 ;
ASSERT ( V_18 == V_64 || V_18 == V_45 ) ;
V_2 = F_42 ( V_94 , V_95 ) ;
V_2 -> V_4 = V_93 ;
V_2 -> V_3 = V_66 ;
V_2 -> V_9 = V_18 ;
V_2 -> V_96 = V_66 -> V_81 . V_97 ;
V_2 -> V_98 = & V_99 ;
if ( V_18 == V_45 ) {
V_2 -> V_100 = F_5 ( V_15 -> V_23 [ V_45 ] ) ;
V_2 -> V_101 = V_102 ;
} else {
V_2 -> V_100 = F_5 ( V_15 -> V_23 [ V_64 ] ) ;
}
V_2 -> V_5 . V_6 . V_7 = V_7 ;
V_2 -> V_5 . V_6 . V_8 = V_8 ;
return V_2 ;
}
int
F_43 (
struct V_65 * V_66 ,
int V_103 ,
int V_104 )
{
V_103 -= F_44 ( V_66 ) ;
if ( V_104 )
return V_103 / sizeof( T_4 ) ;
return V_103 / ( sizeof( T_7 ) + sizeof( V_105 ) ) ;
}
