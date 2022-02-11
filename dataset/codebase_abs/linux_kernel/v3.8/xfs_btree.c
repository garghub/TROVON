STATIC int
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
struct V_6 * V_7 )
{
int V_8 ;
struct V_9 * V_10 ;
V_10 = V_2 -> V_11 ;
V_8 =
F_2 ( V_4 -> V_12 ) == V_13 [ V_2 -> V_14 ] &&
F_3 ( V_4 -> V_15 ) == V_5 &&
F_3 ( V_4 -> V_16 ) <=
V_2 -> V_17 -> V_18 ( V_2 , V_5 ) &&
V_4 -> V_19 . V_20 . V_21 &&
( V_4 -> V_19 . V_20 . V_21 == F_4 ( V_22 ) ||
F_5 ( V_10 ,
F_6 ( V_4 -> V_19 . V_20 . V_21 ) ) ) &&
V_4 -> V_19 . V_20 . V_23 &&
( V_4 -> V_19 . V_20 . V_23 == F_4 ( V_22 ) ||
F_5 ( V_10 ,
F_6 ( V_4 -> V_19 . V_20 . V_23 ) ) ) ;
if ( F_7 ( F_8 ( ! V_8 , V_10 ,
V_24 ,
V_25 ) ) ) {
if ( V_7 )
F_9 ( V_7 , V_26 ) ;
F_10 ( L_1 , V_27 ,
V_10 ) ;
return F_11 ( V_28 ) ;
}
return 0 ;
}
STATIC int
F_12 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
struct V_6 * V_7 )
{
struct V_6 * V_29 ;
struct V_30 * V_31 ;
T_1 V_32 ;
int V_33 ;
V_29 = V_2 -> V_34 . V_35 . V_29 ;
V_31 = F_13 ( V_29 ) ;
V_32 = F_2 ( V_31 -> V_36 ) ;
V_33 =
F_2 ( V_4 -> V_12 ) == V_13 [ V_2 -> V_14 ] &&
F_3 ( V_4 -> V_15 ) == V_5 &&
F_3 ( V_4 -> V_16 ) <=
V_2 -> V_17 -> V_18 ( V_2 , V_5 ) &&
( V_4 -> V_19 . V_37 . V_21 == F_14 ( V_38 ) ||
F_2 ( V_4 -> V_19 . V_37 . V_21 ) < V_32 ) &&
V_4 -> V_19 . V_37 . V_21 &&
( V_4 -> V_19 . V_37 . V_23 == F_14 ( V_38 ) ||
F_2 ( V_4 -> V_19 . V_37 . V_23 ) < V_32 ) &&
V_4 -> V_19 . V_37 . V_23 ;
if ( F_7 ( F_8 ( ! V_33 , V_2 -> V_11 ,
V_39 ,
V_40 ) ) ) {
if ( V_7 )
F_9 ( V_7 , V_26 ) ;
F_15 ( L_2 ,
V_27 , V_2 -> V_11 , V_4 ) ;
return F_11 ( V_28 ) ;
}
return 0 ;
}
int
F_16 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
struct V_6 * V_7 )
{
if ( V_2 -> V_41 & V_42 )
return F_1 ( V_2 , V_4 , V_5 , V_7 ) ;
else
return F_12 ( V_2 , V_4 , V_5 , V_7 ) ;
}
int
F_17 (
struct V_1 * V_2 ,
T_2 V_43 ,
int V_5 )
{
F_18 (
V_5 > 0 &&
V_43 != V_22 &&
F_5 ( V_2 -> V_11 , V_43 ) ) ;
return 0 ;
}
STATIC int
F_19 (
struct V_1 * V_2 ,
T_1 V_43 ,
int V_5 )
{
T_1 V_44 = V_2 -> V_11 -> V_45 . V_46 ;
F_18 (
V_5 > 0 &&
V_43 != V_38 &&
V_43 != 0 &&
V_43 < V_44 ) ;
return 0 ;
}
STATIC int
F_20 (
struct V_1 * V_2 ,
union V_47 * V_48 ,
int V_49 ,
int V_5 )
{
if ( V_2 -> V_41 & V_42 ) {
return F_17 ( V_2 ,
F_6 ( ( & V_48 -> V_20 ) [ V_49 ] ) , V_5 ) ;
} else {
return F_19 ( V_2 ,
F_2 ( ( & V_48 -> V_37 ) [ V_49 ] ) , V_5 ) ;
}
}
void
F_21 (
T_3 * V_2 ,
int error )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_51 ; V_50 ++ ) {
if ( V_2 -> V_52 [ V_50 ] )
F_22 ( V_2 -> V_53 , V_2 -> V_52 [ V_50 ] ) ;
else if ( ! error )
break;
}
ASSERT ( V_2 -> V_14 != V_54 ||
V_2 -> V_34 . V_55 . V_56 == 0 ) ;
F_23 ( V_57 , V_2 ) ;
}
int
F_24 (
T_3 * V_2 ,
T_3 * * V_58 )
{
T_4 * V_7 ;
int error ;
int V_50 ;
T_5 * V_10 ;
T_3 * V_59 ;
T_6 * V_60 ;
V_60 = V_2 -> V_53 ;
V_10 = V_2 -> V_11 ;
V_59 = V_2 -> V_17 -> V_61 ( V_2 ) ;
V_59 -> V_62 = V_2 -> V_62 ;
for ( V_50 = 0 ; V_50 < V_59 -> V_51 ; V_50 ++ ) {
V_59 -> V_63 [ V_50 ] = V_2 -> V_63 [ V_50 ] ;
V_59 -> V_64 [ V_50 ] = V_2 -> V_64 [ V_50 ] ;
V_7 = V_2 -> V_52 [ V_50 ] ;
if ( V_7 ) {
error = F_25 ( V_10 , V_60 , V_10 -> V_65 ,
F_26 ( V_7 ) , V_10 -> V_66 ,
0 , & V_7 ,
V_2 -> V_17 -> V_67 ) ;
if ( error ) {
F_21 ( V_59 , error ) ;
* V_58 = NULL ;
return error ;
}
V_59 -> V_52 [ V_50 ] = V_7 ;
ASSERT ( ! F_27 ( V_7 ) ) ;
} else
V_59 -> V_52 [ V_50 ] = NULL ;
}
* V_58 = V_59 ;
return 0 ;
}
static inline T_7 F_28 ( struct V_1 * V_2 )
{
return ( V_2 -> V_41 & V_42 ) ?
V_68 :
V_69 ;
}
static inline T_7 F_29 ( struct V_1 * V_2 )
{
return ( V_2 -> V_41 & V_42 ) ?
sizeof( V_70 ) : sizeof( V_71 ) ;
}
STATIC T_7
F_30 (
struct V_1 * V_2 ,
int V_72 )
{
return F_28 ( V_2 ) +
( V_72 - 1 ) * V_2 -> V_17 -> V_73 ;
}
STATIC T_7
F_31 (
struct V_1 * V_2 ,
int V_72 )
{
return F_28 ( V_2 ) +
( V_72 - 1 ) * V_2 -> V_17 -> V_74 ;
}
STATIC T_7
F_32 (
struct V_1 * V_2 ,
int V_72 ,
int V_5 )
{
return F_28 ( V_2 ) +
V_2 -> V_17 -> V_18 ( V_2 , V_5 ) * V_2 -> V_17 -> V_74 +
( V_72 - 1 ) * F_29 ( V_2 ) ;
}
STATIC union V_75 *
F_33 (
struct V_1 * V_2 ,
int V_72 ,
struct V_3 * V_4 )
{
return (union V_75 * )
( ( char * ) V_4 + F_30 ( V_2 , V_72 ) ) ;
}
STATIC union V_76 *
F_34 (
struct V_1 * V_2 ,
int V_72 ,
struct V_3 * V_4 )
{
return (union V_76 * )
( ( char * ) V_4 + F_31 ( V_2 , V_72 ) ) ;
}
STATIC union V_47 *
F_35 (
struct V_1 * V_2 ,
int V_72 ,
struct V_3 * V_4 )
{
int V_5 = F_36 ( V_4 ) ;
ASSERT ( V_4 -> V_15 != 0 ) ;
return (union V_47 * )
( ( char * ) V_4 + F_32 ( V_2 , V_72 , V_5 ) ) ;
}
STATIC struct V_3 *
F_37 (
struct V_1 * V_2 )
{
struct V_77 * V_78 ;
V_78 = F_38 ( V_2 -> V_34 . V_55 . V_79 , V_2 -> V_34 . V_55 . V_80 ) ;
return (struct V_3 * ) V_78 -> V_81 ;
}
STATIC struct V_3 *
F_39 (
struct V_1 * V_2 ,
int V_5 ,
struct V_6 * * V_82 )
{
if ( ( V_2 -> V_41 & V_83 ) &&
( V_5 == V_2 -> V_51 - 1 ) ) {
* V_82 = NULL ;
return F_37 ( V_2 ) ;
}
* V_82 = V_2 -> V_52 [ V_5 ] ;
return F_40 ( * V_82 ) ;
}
T_4 *
F_41 (
T_5 * V_10 ,
T_6 * V_60 ,
T_8 V_84 ,
T_9 V_85 )
{
T_4 * V_7 ;
T_10 V_86 ;
ASSERT ( V_84 != V_87 ) ;
V_86 = F_42 ( V_10 , V_84 ) ;
V_7 = F_43 ( V_60 , V_10 -> V_65 , V_86 , V_10 -> V_66 , V_85 ) ;
ASSERT ( ! F_27 ( V_7 ) ) ;
return V_7 ;
}
T_4 *
F_44 (
T_5 * V_10 ,
T_6 * V_60 ,
T_11 V_88 ,
T_1 V_89 ,
T_9 V_85 )
{
T_4 * V_7 ;
T_10 V_86 ;
ASSERT ( V_88 != V_90 ) ;
ASSERT ( V_89 != V_38 ) ;
V_86 = F_45 ( V_10 , V_88 , V_89 ) ;
V_7 = F_43 ( V_60 , V_10 -> V_65 , V_86 , V_10 -> V_66 , V_85 ) ;
ASSERT ( ! F_27 ( V_7 ) ) ;
return V_7 ;
}
int
F_46 (
T_3 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( V_2 -> V_41 & V_42 )
return V_4 -> V_19 . V_20 . V_23 == F_4 ( V_22 ) ;
else
return V_4 -> V_19 . V_37 . V_23 == F_14 ( V_38 ) ;
}
STATIC int
F_47 (
T_3 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( ! V_4 -> V_16 )
return 0 ;
V_2 -> V_63 [ V_5 ] = 1 ;
return 1 ;
}
STATIC int
F_48 (
T_3 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( ! V_4 -> V_16 )
return 0 ;
V_2 -> V_63 [ V_5 ] = F_3 ( V_4 -> V_16 ) ;
return 1 ;
}
void
F_49 (
T_12 V_91 ,
const short * V_92 ,
int V_93 ,
int * V_94 ,
int * V_95 )
{
int V_50 ;
T_12 V_96 ;
ASSERT ( V_91 != 0 ) ;
for ( V_50 = 0 , V_96 = 1LL ; ; V_50 ++ , V_96 <<= 1 ) {
if ( V_96 & V_91 ) {
* V_94 = V_92 [ V_50 ] ;
break;
}
}
for ( V_50 = V_93 - 1 , V_96 = 1LL << V_50 ; ; V_50 -- , V_96 >>= 1 ) {
if ( V_96 & V_91 ) {
* V_95 = V_92 [ V_50 + 1 ] - 1 ;
break;
}
}
}
int
F_50 (
struct V_9 * V_10 ,
struct V_97 * V_60 ,
T_8 V_84 ,
T_9 V_85 ,
struct V_6 * * V_82 ,
int V_98 ,
const struct V_99 * V_100 )
{
struct V_6 * V_7 ;
T_10 V_86 ;
int error ;
ASSERT ( V_84 != V_87 ) ;
V_86 = F_42 ( V_10 , V_84 ) ;
error = F_25 ( V_10 , V_60 , V_10 -> V_65 , V_86 ,
V_10 -> V_66 , V_85 , & V_7 , V_100 ) ;
if ( error )
return error ;
ASSERT ( ! F_27 ( V_7 ) ) ;
if ( V_7 )
F_51 ( V_7 , V_98 ) ;
* V_82 = V_7 ;
return 0 ;
}
void
F_52 (
struct V_9 * V_10 ,
T_8 V_84 ,
T_13 V_101 ,
const struct V_99 * V_100 )
{
T_10 V_86 ;
ASSERT ( V_84 != V_87 ) ;
V_86 = F_42 ( V_10 , V_84 ) ;
F_53 ( V_10 -> V_65 , V_86 , V_10 -> V_66 * V_101 , V_100 ) ;
}
void
F_54 (
struct V_9 * V_10 ,
T_11 V_88 ,
T_1 V_89 ,
T_13 V_101 ,
const struct V_99 * V_100 )
{
T_10 V_86 ;
ASSERT ( V_88 != V_90 ) ;
ASSERT ( V_89 != V_38 ) ;
V_86 = F_45 ( V_10 , V_88 , V_89 ) ;
F_53 ( V_10 -> V_65 , V_86 , V_10 -> V_66 * V_101 , V_100 ) ;
}
STATIC int
F_55 (
struct V_1 * V_2 ,
int V_102 ,
struct V_3 * V_4 )
{
int V_103 = 0 ;
T_2 V_104 = F_6 ( V_4 -> V_19 . V_20 . V_21 ) ;
T_2 V_105 = F_6 ( V_4 -> V_19 . V_20 . V_23 ) ;
if ( ( V_102 & V_106 ) && V_104 != V_22 ) {
F_52 ( V_2 -> V_11 , V_104 , 1 ,
V_2 -> V_17 -> V_67 ) ;
V_103 ++ ;
}
if ( ( V_102 & V_107 ) && V_105 != V_22 ) {
F_52 ( V_2 -> V_11 , V_105 , 1 ,
V_2 -> V_17 -> V_67 ) ;
V_103 ++ ;
}
return V_103 ;
}
STATIC int
F_56 (
struct V_1 * V_2 ,
int V_102 ,
struct V_3 * V_4 )
{
int V_103 = 0 ;
T_1 V_104 = F_2 ( V_4 -> V_19 . V_37 . V_21 ) ;
T_1 V_105 = F_2 ( V_4 -> V_19 . V_37 . V_23 ) ;
if ( ( V_102 & V_106 ) && V_104 != V_38 ) {
F_54 ( V_2 -> V_11 , V_2 -> V_34 . V_35 . V_88 ,
V_104 , 1 , V_2 -> V_17 -> V_67 ) ;
V_103 ++ ;
}
if ( ( V_102 & V_107 ) && V_105 != V_38 ) {
F_54 ( V_2 -> V_11 , V_2 -> V_34 . V_35 . V_88 ,
V_105 , 1 , V_2 -> V_17 -> V_67 ) ;
V_103 ++ ;
}
return V_103 ;
}
STATIC int
F_57 (
struct V_1 * V_2 ,
int V_108 ,
int V_102 )
{
struct V_3 * V_4 ;
if ( ( V_2 -> V_41 & V_83 ) &&
( V_108 == V_2 -> V_51 - 1 ) )
return 0 ;
if ( ( V_2 -> V_64 [ V_108 ] | V_102 ) == V_2 -> V_64 [ V_108 ] )
return 0 ;
V_2 -> V_64 [ V_108 ] |= V_102 ;
V_4 = F_40 ( V_2 -> V_52 [ V_108 ] ) ;
if ( V_2 -> V_41 & V_42 )
return F_55 ( V_2 , V_102 , V_4 ) ;
return F_56 ( V_2 , V_102 , V_4 ) ;
}
STATIC void
F_58 (
T_3 * V_2 ,
int V_108 ,
T_4 * V_7 )
{
struct V_3 * V_55 ;
if ( V_2 -> V_52 [ V_108 ] )
F_22 ( V_2 -> V_53 , V_2 -> V_52 [ V_108 ] ) ;
V_2 -> V_52 [ V_108 ] = V_7 ;
V_2 -> V_64 [ V_108 ] = 0 ;
V_55 = F_40 ( V_7 ) ;
if ( V_2 -> V_41 & V_42 ) {
if ( V_55 -> V_19 . V_20 . V_21 == F_4 ( V_22 ) )
V_2 -> V_64 [ V_108 ] |= V_106 ;
if ( V_55 -> V_19 . V_20 . V_23 == F_4 ( V_22 ) )
V_2 -> V_64 [ V_108 ] |= V_107 ;
} else {
if ( V_55 -> V_19 . V_37 . V_21 == F_14 ( V_38 ) )
V_2 -> V_64 [ V_108 ] |= V_106 ;
if ( V_55 -> V_19 . V_37 . V_23 == F_14 ( V_38 ) )
V_2 -> V_64 [ V_108 ] |= V_107 ;
}
}
STATIC int
F_59 (
struct V_1 * V_2 ,
union V_47 * V_48 )
{
if ( V_2 -> V_41 & V_42 )
return V_48 -> V_20 == F_4 ( V_22 ) ;
else
return V_48 -> V_37 == F_14 ( V_38 ) ;
}
STATIC void
F_60 (
struct V_1 * V_2 ,
union V_47 * V_48 )
{
if ( V_2 -> V_41 & V_42 )
V_48 -> V_20 = F_4 ( V_22 ) ;
else
V_48 -> V_37 = F_14 ( V_38 ) ;
}
STATIC void
F_61 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_47 * V_48 ,
int V_102 )
{
ASSERT ( V_102 == V_109 || V_102 == V_110 ) ;
if ( V_2 -> V_41 & V_42 ) {
if ( V_102 == V_110 )
V_48 -> V_20 = V_4 -> V_19 . V_20 . V_23 ;
else
V_48 -> V_20 = V_4 -> V_19 . V_20 . V_21 ;
} else {
if ( V_102 == V_110 )
V_48 -> V_37 = V_4 -> V_19 . V_37 . V_23 ;
else
V_48 -> V_37 = V_4 -> V_19 . V_37 . V_21 ;
}
}
STATIC void
F_62 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_47 * V_48 ,
int V_102 )
{
ASSERT ( V_102 == V_109 || V_102 == V_110 ) ;
if ( V_2 -> V_41 & V_42 ) {
if ( V_102 == V_110 )
V_4 -> V_19 . V_20 . V_23 = V_48 -> V_20 ;
else
V_4 -> V_19 . V_20 . V_21 = V_48 -> V_20 ;
} else {
if ( V_102 == V_110 )
V_4 -> V_19 . V_37 . V_23 = V_48 -> V_37 ;
else
V_4 -> V_19 . V_37 . V_21 = V_48 -> V_37 ;
}
}
void
F_63 (
struct V_9 * V_10 ,
struct V_6 * V_7 ,
T_14 V_111 ,
T_15 V_5 ,
T_15 V_112 ,
unsigned int V_113 )
{
struct V_3 * V_59 = F_40 ( V_7 ) ;
V_59 -> V_12 = F_14 ( V_111 ) ;
V_59 -> V_15 = F_64 ( V_5 ) ;
V_59 -> V_16 = F_64 ( V_112 ) ;
if ( V_113 & V_42 ) {
V_59 -> V_19 . V_20 . V_21 = F_4 ( V_22 ) ;
V_59 -> V_19 . V_20 . V_23 = F_4 ( V_22 ) ;
} else {
V_59 -> V_19 . V_37 . V_21 = F_14 ( V_38 ) ;
V_59 -> V_19 . V_37 . V_23 = F_14 ( V_38 ) ;
}
}
STATIC void
F_65 (
struct V_1 * V_2 ,
int V_5 ,
int V_112 ,
struct V_6 * V_7 )
{
F_63 ( V_2 -> V_11 , V_7 , V_13 [ V_2 -> V_14 ] ,
V_5 , V_112 , V_2 -> V_41 ) ;
}
STATIC int
F_66 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
union V_47 V_48 ;
if ( V_5 > 0 )
return 0 ;
if ( ! ( V_2 -> V_41 & V_114 ) )
return 0 ;
F_61 ( V_2 , V_4 , & V_48 , V_110 ) ;
if ( ! F_59 ( V_2 , & V_48 ) )
return 0 ;
return 1 ;
}
STATIC void
F_67 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
union V_47 * V_48 )
{
if ( V_2 -> V_41 & V_42 )
V_48 -> V_20 = F_4 ( F_68 ( V_2 -> V_11 ,
F_26 ( V_7 ) ) ) ;
else {
V_48 -> V_37 = F_14 ( F_69 ( V_2 -> V_11 ,
F_26 ( V_7 ) ) ) ;
}
}
STATIC T_10
F_70 (
struct V_1 * V_2 ,
union V_47 * V_48 )
{
if ( V_2 -> V_41 & V_42 ) {
ASSERT ( V_48 -> V_20 != F_4 ( V_22 ) ) ;
return F_42 ( V_2 -> V_11 , F_6 ( V_48 -> V_20 ) ) ;
} else {
ASSERT ( V_2 -> V_34 . V_35 . V_88 != V_90 ) ;
ASSERT ( V_48 -> V_37 != F_14 ( V_38 ) ) ;
return F_45 ( V_2 -> V_11 , V_2 -> V_34 . V_35 . V_88 ,
F_2 ( V_48 -> V_37 ) ) ;
}
}
STATIC void
F_71 (
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
switch ( V_2 -> V_14 ) {
case V_115 :
case V_116 :
F_51 ( V_7 , V_117 ) ;
break;
case V_118 :
F_51 ( V_7 , V_119 ) ;
break;
case V_54 :
F_51 ( V_7 , V_120 ) ;
break;
default:
ASSERT ( 0 ) ;
}
}
STATIC int
F_72 (
struct V_1 * V_2 ,
union V_47 * V_48 ,
int V_113 ,
struct V_3 * * V_4 ,
struct V_6 * * V_82 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_10 V_86 ;
ASSERT ( ! ( V_113 & V_121 ) ) ;
V_86 = F_70 ( V_2 , V_48 ) ;
* V_82 = F_43 ( V_2 -> V_53 , V_10 -> V_65 , V_86 ,
V_10 -> V_66 , V_113 ) ;
if ( ! * V_82 )
return V_122 ;
( * V_82 ) -> V_123 = V_2 -> V_17 -> V_67 ;
* V_4 = F_40 ( * V_82 ) ;
return 0 ;
}
STATIC int
F_73 (
struct V_1 * V_2 ,
union V_47 * V_48 ,
int V_5 ,
int V_113 ,
struct V_3 * * V_4 ,
struct V_6 * * V_82 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_10 V_86 ;
int error ;
ASSERT ( ! ( V_113 & V_121 ) ) ;
V_86 = F_70 ( V_2 , V_48 ) ;
error = F_25 ( V_10 , V_2 -> V_53 , V_10 -> V_65 , V_86 ,
V_10 -> V_66 , V_113 , V_82 ,
V_2 -> V_17 -> V_67 ) ;
if ( error )
return error ;
ASSERT ( ! F_27 ( * V_82 ) ) ;
F_71 ( V_2 , * V_82 ) ;
* V_4 = F_40 ( * V_82 ) ;
return 0 ;
}
STATIC void
F_74 (
struct V_1 * V_2 ,
union V_76 * V_124 ,
union V_76 * V_125 ,
int V_126 )
{
ASSERT ( V_126 >= 0 ) ;
memcpy ( V_124 , V_125 , V_126 * V_2 -> V_17 -> V_74 ) ;
}
STATIC void
F_75 (
struct V_1 * V_2 ,
union V_75 * V_127 ,
union V_75 * V_128 ,
int V_112 )
{
ASSERT ( V_112 >= 0 ) ;
memcpy ( V_127 , V_128 , V_112 * V_2 -> V_17 -> V_73 ) ;
}
STATIC void
F_76 (
struct V_1 * V_2 ,
union V_47 * V_129 ,
union V_47 * V_130 ,
int V_131 )
{
ASSERT ( V_131 >= 0 ) ;
memcpy ( V_129 , V_130 , V_131 * F_29 ( V_2 ) ) ;
}
STATIC void
F_77 (
struct V_1 * V_2 ,
union V_76 * V_132 ,
int V_133 ,
int V_126 )
{
char * V_124 ;
ASSERT ( V_126 >= 0 ) ;
ASSERT ( V_133 == 1 || V_133 == - 1 ) ;
V_124 = ( char * ) V_132 + ( V_133 * V_2 -> V_17 -> V_74 ) ;
memmove ( V_124 , V_132 , V_126 * V_2 -> V_17 -> V_74 ) ;
}
STATIC void
F_78 (
struct V_1 * V_2 ,
union V_75 * V_134 ,
int V_133 ,
int V_112 )
{
char * V_127 ;
ASSERT ( V_112 >= 0 ) ;
ASSERT ( V_133 == 1 || V_133 == - 1 ) ;
V_127 = ( char * ) V_134 + ( V_133 * V_2 -> V_17 -> V_73 ) ;
memmove ( V_127 , V_134 , V_112 * V_2 -> V_17 -> V_73 ) ;
}
STATIC void
F_79 (
struct V_1 * V_2 ,
union V_47 * V_48 ,
int V_133 ,
int V_131 )
{
char * V_129 ;
ASSERT ( V_131 >= 0 ) ;
ASSERT ( V_133 == 1 || V_133 == - 1 ) ;
V_129 = ( char * ) V_48 + ( V_133 * F_29 ( V_2 ) ) ;
memmove ( V_129 , V_48 , V_131 * F_29 ( V_2 ) ) ;
}
STATIC void
F_80 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_94 ,
int V_95 )
{
F_81 ( V_2 , V_135 ) ;
F_82 ( V_2 , V_7 , V_94 , V_95 ) ;
if ( V_7 ) {
F_83 ( V_2 -> V_53 , V_7 ,
F_31 ( V_2 , V_94 ) ,
F_31 ( V_2 , V_95 + 1 ) - 1 ) ;
} else {
F_84 ( V_2 -> V_53 , V_2 -> V_34 . V_55 . V_79 ,
F_85 ( V_2 -> V_34 . V_55 . V_80 ) ) ;
}
F_81 ( V_2 , V_136 ) ;
}
void
F_86 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_94 ,
int V_95 )
{
F_81 ( V_2 , V_135 ) ;
F_82 ( V_2 , V_7 , V_94 , V_95 ) ;
F_83 ( V_2 -> V_53 , V_7 ,
F_30 ( V_2 , V_94 ) ,
F_30 ( V_2 , V_95 + 1 ) - 1 ) ;
F_81 ( V_2 , V_136 ) ;
}
STATIC void
F_87 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_94 ,
int V_95 )
{
F_81 ( V_2 , V_135 ) ;
F_82 ( V_2 , V_7 , V_94 , V_95 ) ;
if ( V_7 ) {
struct V_3 * V_4 = F_40 ( V_7 ) ;
int V_5 = F_36 ( V_4 ) ;
F_83 ( V_2 -> V_53 , V_7 ,
F_32 ( V_2 , V_94 , V_5 ) ,
F_32 ( V_2 , V_95 + 1 , V_5 ) - 1 ) ;
} else {
F_84 ( V_2 -> V_53 , V_2 -> V_34 . V_55 . V_79 ,
F_85 ( V_2 -> V_34 . V_55 . V_80 ) ) ;
}
F_81 ( V_2 , V_136 ) ;
}
void
F_88 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_91 )
{
int V_94 ;
int V_95 ;
static const short V_137 [] = {
F_89 ( struct V_3 , V_12 ) ,
F_89 ( struct V_3 , V_15 ) ,
F_89 ( struct V_3 , V_16 ) ,
F_89 ( struct V_3 , V_19 . V_37 . V_21 ) ,
F_89 ( struct V_3 , V_19 . V_37 . V_23 ) ,
V_69
} ;
static const short V_138 [] = {
F_89 ( struct V_3 , V_12 ) ,
F_89 ( struct V_3 , V_15 ) ,
F_89 ( struct V_3 , V_16 ) ,
F_89 ( struct V_3 , V_19 . V_20 . V_21 ) ,
F_89 ( struct V_3 , V_19 . V_20 . V_23 ) ,
V_68
} ;
F_81 ( V_2 , V_135 ) ;
F_90 ( V_2 , V_7 , V_91 ) ;
if ( V_7 ) {
F_49 ( V_91 ,
( V_2 -> V_41 & V_42 ) ?
V_138 : V_137 ,
V_139 , & V_94 , & V_95 ) ;
F_83 ( V_2 -> V_53 , V_7 , V_94 , V_95 ) ;
} else {
F_84 ( V_2 -> V_53 , V_2 -> V_34 . V_55 . V_79 ,
F_85 ( V_2 -> V_34 . V_55 . V_80 ) ) ;
}
F_81 ( V_2 , V_136 ) ;
}
int
F_91 (
struct V_1 * V_2 ,
int V_5 ,
int * V_140 )
{
struct V_3 * V_4 ;
union V_47 V_48 ;
struct V_6 * V_7 ;
int error ;
int V_108 ;
F_81 ( V_2 , V_135 ) ;
F_92 ( V_2 , V_5 ) ;
ASSERT ( V_5 < V_2 -> V_51 ) ;
F_57 ( V_2 , V_5 , V_107 ) ;
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_93
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_141;
#endif
if ( ++ V_2 -> V_63 [ V_5 ] <= F_94 ( V_4 ) )
goto V_142;
F_61 ( V_2 , V_4 , & V_48 , V_110 ) ;
if ( F_59 ( V_2 , & V_48 ) )
goto V_143;
F_95 ( V_2 , V_144 ) ;
for ( V_108 = V_5 + 1 ; V_108 < V_2 -> V_51 ; V_108 ++ ) {
V_4 = F_39 ( V_2 , V_108 , & V_7 ) ;
#ifdef F_93
error = F_16 ( V_2 , V_4 , V_108 , V_7 ) ;
if ( error )
goto V_141;
#endif
if ( ++ V_2 -> V_63 [ V_108 ] <= F_94 ( V_4 ) )
break;
F_57 ( V_2 , V_108 , V_107 ) ;
}
if ( V_108 == V_2 -> V_51 ) {
if ( V_2 -> V_41 & V_83 )
goto V_143;
ASSERT ( 0 ) ;
error = V_28 ;
goto V_141;
}
ASSERT ( V_108 < V_2 -> V_51 ) ;
for ( V_4 = F_39 ( V_2 , V_108 , & V_7 ) ; V_108 > V_5 ; ) {
union V_47 * V_145 ;
V_145 = F_35 ( V_2 , V_2 -> V_63 [ V_108 ] , V_4 ) ;
error = F_73 ( V_2 , V_145 , -- V_108 ,
0 , & V_4 , & V_7 ) ;
if ( error )
goto V_141;
F_58 ( V_2 , V_108 , V_7 ) ;
V_2 -> V_63 [ V_108 ] = 1 ;
}
V_142:
F_81 ( V_2 , V_136 ) ;
* V_140 = 1 ;
return 0 ;
V_143:
F_81 ( V_2 , V_136 ) ;
* V_140 = 0 ;
return 0 ;
V_141:
F_81 ( V_2 , V_146 ) ;
return error ;
}
int
F_96 (
struct V_1 * V_2 ,
int V_5 ,
int * V_140 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
int error ;
int V_108 ;
union V_47 V_48 ;
F_81 ( V_2 , V_135 ) ;
F_92 ( V_2 , V_5 ) ;
ASSERT ( V_5 < V_2 -> V_51 ) ;
F_57 ( V_2 , V_5 , V_106 ) ;
if ( -- V_2 -> V_63 [ V_5 ] > 0 )
goto V_142;
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_93
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_141;
#endif
F_61 ( V_2 , V_4 , & V_48 , V_109 ) ;
if ( F_59 ( V_2 , & V_48 ) )
goto V_143;
F_95 ( V_2 , V_147 ) ;
for ( V_108 = V_5 + 1 ; V_108 < V_2 -> V_51 ; V_108 ++ ) {
if ( -- V_2 -> V_63 [ V_108 ] > 0 )
break;
F_57 ( V_2 , V_108 , V_106 ) ;
}
if ( V_108 == V_2 -> V_51 ) {
if ( V_2 -> V_41 & V_83 )
goto V_143;
ASSERT ( 0 ) ;
error = V_28 ;
goto V_141;
}
ASSERT ( V_108 < V_2 -> V_51 ) ;
for ( V_4 = F_39 ( V_2 , V_108 , & V_7 ) ; V_108 > V_5 ; ) {
union V_47 * V_145 ;
V_145 = F_35 ( V_2 , V_2 -> V_63 [ V_108 ] , V_4 ) ;
error = F_73 ( V_2 , V_145 , -- V_108 ,
0 , & V_4 , & V_7 ) ;
if ( error )
goto V_141;
F_58 ( V_2 , V_108 , V_7 ) ;
V_2 -> V_63 [ V_108 ] = F_94 ( V_4 ) ;
}
V_142:
F_81 ( V_2 , V_136 ) ;
* V_140 = 1 ;
return 0 ;
V_143:
F_81 ( V_2 , V_136 ) ;
* V_140 = 0 ;
return 0 ;
V_141:
F_81 ( V_2 , V_146 ) ;
return error ;
}
STATIC int
F_97 (
struct V_1 * V_2 ,
int V_5 ,
union V_47 * V_148 ,
struct V_3 * * V_149 )
{
struct V_6 * V_7 ;
int error = 0 ;
if ( ( V_2 -> V_41 & V_83 ) &&
( V_5 == V_2 -> V_51 - 1 ) ) {
* V_149 = F_37 ( V_2 ) ;
return 0 ;
}
V_7 = V_2 -> V_52 [ V_5 ] ;
if ( V_7 && F_26 ( V_7 ) == F_70 ( V_2 , V_148 ) ) {
* V_149 = F_40 ( V_7 ) ;
return 0 ;
}
error = F_73 ( V_2 , V_148 , V_5 , 0 , V_149 , & V_7 ) ;
if ( error )
return error ;
F_58 ( V_2 , V_5 , V_7 ) ;
return 0 ;
}
STATIC union V_76 *
F_98 (
struct V_1 * V_2 ,
int V_5 ,
int V_150 ,
struct V_3 * V_4 ,
union V_76 * V_151 )
{
if ( V_5 == 0 ) {
V_2 -> V_17 -> V_152 ( V_151 ,
F_33 ( V_2 , V_150 , V_4 ) ) ;
return V_151 ;
}
return F_34 ( V_2 , V_150 , V_4 ) ;
}
int
F_99 (
struct V_1 * V_2 ,
T_16 V_133 ,
int * V_140 )
{
struct V_3 * V_4 ;
T_12 V_153 ;
int error ;
int V_150 ;
int V_5 ;
union V_47 * V_148 ;
union V_47 V_48 ;
F_81 ( V_2 , V_135 ) ;
F_92 ( V_2 , V_133 ) ;
F_95 ( V_2 , V_154 ) ;
V_4 = NULL ;
V_150 = 0 ;
V_2 -> V_17 -> V_155 ( V_2 , & V_48 ) ;
V_148 = & V_48 ;
for ( V_5 = V_2 -> V_51 - 1 , V_153 = 1 ; V_5 >= 0 ; V_5 -- ) {
error = F_97 ( V_2 , V_5 , V_148 , & V_4 ) ;
if ( error )
goto V_141;
if ( V_153 == 0 ) {
V_150 = 1 ;
} else {
int V_156 ;
int V_157 ;
V_157 = 1 ;
V_156 = F_94 ( V_4 ) ;
if ( ! V_156 ) {
ASSERT ( V_5 == 0 && V_2 -> V_51 == 1 ) ;
V_2 -> V_63 [ 0 ] = V_133 != V_158 ;
F_81 ( V_2 , V_136 ) ;
* V_140 = 0 ;
return 0 ;
}
while ( V_157 <= V_156 ) {
union V_76 V_132 ;
union V_76 * V_151 ;
F_95 ( V_2 , V_159 ) ;
V_150 = ( V_157 + V_156 ) >> 1 ;
V_151 = F_98 ( V_2 , V_5 ,
V_150 , V_4 , & V_132 ) ;
V_153 = V_2 -> V_17 -> V_160 ( V_2 , V_151 ) ;
if ( V_153 < 0 )
V_157 = V_150 + 1 ;
else if ( V_153 > 0 )
V_156 = V_150 - 1 ;
else
break;
}
}
if ( V_5 > 0 ) {
if ( V_153 > 0 && -- V_150 < 1 )
V_150 = 1 ;
V_148 = F_35 ( V_2 , V_150 , V_4 ) ;
#ifdef F_93
error = F_20 ( V_2 , V_148 , 0 , V_5 ) ;
if ( error )
goto V_141;
#endif
V_2 -> V_63 [ V_5 ] = V_150 ;
}
}
if ( V_133 != V_158 && V_153 < 0 ) {
V_150 ++ ;
F_61 ( V_2 , V_4 , & V_48 , V_110 ) ;
if ( V_133 == V_161 &&
V_150 > F_94 ( V_4 ) &&
! F_59 ( V_2 , & V_48 ) ) {
int V_50 ;
V_2 -> V_63 [ 0 ] = V_150 ;
error = F_91 ( V_2 , 0 , & V_50 ) ;
if ( error )
goto V_141;
F_18 ( V_50 == 1 ) ;
F_81 ( V_2 , V_136 ) ;
* V_140 = 1 ;
return 0 ;
}
} else if ( V_133 == V_158 && V_153 > 0 )
V_150 -- ;
V_2 -> V_63 [ 0 ] = V_150 ;
if ( V_150 == 0 || V_150 > F_94 ( V_4 ) )
* V_140 = 0 ;
else if ( V_133 != V_162 || V_153 == 0 )
* V_140 = 1 ;
else
* V_140 = 0 ;
F_81 ( V_2 , V_136 ) ;
return 0 ;
V_141:
F_81 ( V_2 , V_146 ) ;
return error ;
}
STATIC int
F_100 (
struct V_1 * V_2 ,
union V_76 * V_163 ,
int V_5 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_76 * V_151 ;
int V_48 ;
F_81 ( V_2 , V_135 ) ;
F_101 ( V_2 , V_5 , V_163 ) ;
ASSERT ( ! ( V_2 -> V_41 & V_83 ) || V_5 >= 1 ) ;
for ( V_48 = 1 ; V_48 == 1 && V_5 < V_2 -> V_51 ; V_5 ++ ) {
#ifdef F_93
int error ;
#endif
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_93
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error ) {
F_81 ( V_2 , V_146 ) ;
return error ;
}
#endif
V_48 = V_2 -> V_63 [ V_5 ] ;
V_151 = F_34 ( V_2 , V_48 , V_4 ) ;
F_74 ( V_2 , V_151 , V_163 , 1 ) ;
F_80 ( V_2 , V_7 , V_48 , V_48 ) ;
}
F_81 ( V_2 , V_136 ) ;
return 0 ;
}
int
F_102 (
struct V_1 * V_2 ,
union V_75 * V_134 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int error ;
int V_48 ;
union V_75 * V_164 ;
F_81 ( V_2 , V_135 ) ;
F_103 ( V_2 , V_134 ) ;
V_4 = F_39 ( V_2 , 0 , & V_7 ) ;
#ifdef F_93
error = F_16 ( V_2 , V_4 , 0 , V_7 ) ;
if ( error )
goto V_141;
#endif
V_48 = V_2 -> V_63 [ 0 ] ;
V_164 = F_33 ( V_2 , V_48 , V_4 ) ;
F_75 ( V_2 , V_164 , V_134 , 1 ) ;
F_86 ( V_2 , V_7 , V_48 , V_48 ) ;
if ( F_66 ( V_2 , V_4 , 0 ) ) {
V_2 -> V_17 -> V_165 ( V_2 , V_4 , V_134 ,
V_48 , V_166 ) ;
}
if ( V_48 == 1 ) {
union V_76 V_132 ;
V_2 -> V_17 -> V_152 ( & V_132 , V_134 ) ;
error = F_100 ( V_2 , & V_132 , 1 ) ;
if ( error )
goto V_141;
}
F_81 ( V_2 , V_136 ) ;
return 0 ;
V_141:
F_81 ( V_2 , V_146 ) ;
return error ;
}
STATIC int
F_104 (
struct V_1 * V_2 ,
int V_5 ,
int * V_140 )
{
union V_76 V_132 ;
struct V_6 * V_167 ;
struct V_3 * V_104 ;
int V_168 ;
struct V_6 * V_169 ;
struct V_3 * V_105 ;
int V_170 ;
union V_47 V_171 ;
union V_76 * V_172 = NULL ;
union V_47 * V_173 = NULL ;
union V_75 * V_174 = NULL ;
int error ;
F_81 ( V_2 , V_135 ) ;
F_92 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_41 & V_83 ) &&
V_5 == V_2 -> V_51 - 1 )
goto V_143;
V_105 = F_39 ( V_2 , V_5 , & V_169 ) ;
#ifdef F_93
error = F_16 ( V_2 , V_105 , V_5 , V_169 ) ;
if ( error )
goto V_141;
#endif
F_61 ( V_2 , V_105 , & V_171 , V_109 ) ;
if ( F_59 ( V_2 , & V_171 ) )
goto V_143;
if ( V_2 -> V_63 [ V_5 ] <= 1 )
goto V_143;
error = F_73 ( V_2 , & V_171 , V_5 , 0 , & V_104 , & V_167 ) ;
if ( error )
goto V_141;
V_168 = F_94 ( V_104 ) ;
if ( V_168 == V_2 -> V_17 -> V_18 ( V_2 , V_5 ) )
goto V_143;
V_170 = F_94 ( V_105 ) ;
V_168 ++ ;
V_170 -- ;
F_95 ( V_2 , V_175 ) ;
F_105 ( V_2 , V_176 , 1 ) ;
if ( V_5 > 0 ) {
union V_76 * V_177 ;
union V_47 * V_178 ;
V_177 = F_34 ( V_2 , V_168 , V_104 ) ;
V_172 = F_34 ( V_2 , 1 , V_105 ) ;
V_178 = F_35 ( V_2 , V_168 , V_104 ) ;
V_173 = F_35 ( V_2 , 1 , V_105 ) ;
#ifdef F_93
error = F_20 ( V_2 , V_173 , 0 , V_5 ) ;
if ( error )
goto V_141;
#endif
F_74 ( V_2 , V_177 , V_172 , 1 ) ;
F_76 ( V_2 , V_178 , V_173 , 1 ) ;
F_80 ( V_2 , V_167 , V_168 , V_168 ) ;
F_87 ( V_2 , V_167 , V_168 , V_168 ) ;
ASSERT ( V_2 -> V_17 -> V_179 ( V_2 ,
F_34 ( V_2 , V_168 - 1 , V_104 ) , V_177 ) ) ;
} else {
union V_75 * V_180 ;
V_180 = F_33 ( V_2 , V_168 , V_104 ) ;
V_174 = F_33 ( V_2 , 1 , V_105 ) ;
F_75 ( V_2 , V_180 , V_174 , 1 ) ;
F_86 ( V_2 , V_167 , V_168 , V_168 ) ;
ASSERT ( V_2 -> V_17 -> V_181 ( V_2 ,
F_33 ( V_2 , V_168 - 1 , V_104 ) , V_180 ) ) ;
}
F_106 ( V_104 , V_168 ) ;
F_88 ( V_2 , V_167 , V_182 ) ;
F_106 ( V_105 , V_170 ) ;
F_88 ( V_2 , V_169 , V_182 ) ;
F_105 ( V_2 , V_176 , V_170 - 1 ) ;
if ( V_5 > 0 ) {
#ifdef F_93
int V_50 ;
for ( V_50 = 0 ; V_50 < V_170 ; V_50 ++ ) {
error = F_20 ( V_2 , V_173 , V_50 + 1 , V_5 ) ;
if ( error )
goto V_141;
}
#endif
F_77 ( V_2 ,
F_34 ( V_2 , 2 , V_105 ) ,
- 1 , V_170 ) ;
F_79 ( V_2 ,
F_35 ( V_2 , 2 , V_105 ) ,
- 1 , V_170 ) ;
F_80 ( V_2 , V_169 , 1 , V_170 ) ;
F_87 ( V_2 , V_169 , 1 , V_170 ) ;
} else {
F_78 ( V_2 ,
F_33 ( V_2 , 2 , V_105 ) ,
- 1 , V_170 ) ;
F_86 ( V_2 , V_169 , 1 , V_170 ) ;
V_2 -> V_17 -> V_152 ( & V_132 ,
F_33 ( V_2 , 1 , V_105 ) ) ;
V_172 = & V_132 ;
}
error = F_100 ( V_2 , V_172 , V_5 + 1 ) ;
if ( error )
goto V_141;
V_2 -> V_63 [ V_5 ] -- ;
F_81 ( V_2 , V_136 ) ;
* V_140 = 1 ;
return 0 ;
V_143:
F_81 ( V_2 , V_136 ) ;
* V_140 = 0 ;
return 0 ;
V_141:
F_81 ( V_2 , V_146 ) ;
return error ;
}
STATIC int
F_107 (
struct V_1 * V_2 ,
int V_5 ,
int * V_140 )
{
union V_76 V_132 ;
struct V_6 * V_167 ;
struct V_3 * V_104 ;
struct V_6 * V_169 ;
struct V_3 * V_105 ;
struct V_1 * V_183 ;
union V_47 V_184 ;
union V_76 * V_172 ;
int V_170 ;
int V_168 ;
int error ;
int V_50 ;
F_81 ( V_2 , V_135 ) ;
F_92 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_41 & V_83 ) &&
( V_5 == V_2 -> V_51 - 1 ) )
goto V_143;
V_104 = F_39 ( V_2 , V_5 , & V_167 ) ;
#ifdef F_93
error = F_16 ( V_2 , V_104 , V_5 , V_167 ) ;
if ( error )
goto V_141;
#endif
F_61 ( V_2 , V_104 , & V_184 , V_110 ) ;
if ( F_59 ( V_2 , & V_184 ) )
goto V_143;
V_168 = F_94 ( V_104 ) ;
if ( V_2 -> V_63 [ V_5 ] >= V_168 )
goto V_143;
error = F_73 ( V_2 , & V_184 , V_5 , 0 , & V_105 , & V_169 ) ;
if ( error )
goto V_141;
V_170 = F_94 ( V_105 ) ;
if ( V_170 == V_2 -> V_17 -> V_18 ( V_2 , V_5 ) )
goto V_143;
F_95 ( V_2 , V_185 ) ;
F_105 ( V_2 , V_176 , V_170 ) ;
if ( V_5 > 0 ) {
union V_76 * V_177 ;
union V_47 * V_178 ;
union V_47 * V_173 ;
V_177 = F_34 ( V_2 , V_168 , V_104 ) ;
V_178 = F_35 ( V_2 , V_168 , V_104 ) ;
V_172 = F_34 ( V_2 , 1 , V_105 ) ;
V_173 = F_35 ( V_2 , 1 , V_105 ) ;
#ifdef F_93
for ( V_50 = V_170 - 1 ; V_50 >= 0 ; V_50 -- ) {
error = F_20 ( V_2 , V_173 , V_50 , V_5 ) ;
if ( error )
goto V_141;
}
#endif
F_77 ( V_2 , V_172 , 1 , V_170 ) ;
F_79 ( V_2 , V_173 , 1 , V_170 ) ;
#ifdef F_93
error = F_20 ( V_2 , V_178 , 0 , V_5 ) ;
if ( error )
goto V_141;
#endif
F_74 ( V_2 , V_172 , V_177 , 1 ) ;
F_76 ( V_2 , V_173 , V_178 , 1 ) ;
F_80 ( V_2 , V_169 , 1 , V_170 + 1 ) ;
F_87 ( V_2 , V_169 , 1 , V_170 + 1 ) ;
ASSERT ( V_2 -> V_17 -> V_179 ( V_2 , V_172 ,
F_34 ( V_2 , 2 , V_105 ) ) ) ;
} else {
union V_75 * V_180 ;
union V_75 * V_174 ;
V_180 = F_33 ( V_2 , V_168 , V_104 ) ;
V_174 = F_33 ( V_2 , 1 , V_105 ) ;
F_78 ( V_2 , V_174 , 1 , V_170 ) ;
F_75 ( V_2 , V_174 , V_180 , 1 ) ;
F_86 ( V_2 , V_169 , 1 , V_170 + 1 ) ;
V_2 -> V_17 -> V_152 ( & V_132 , V_174 ) ;
V_172 = & V_132 ;
ASSERT ( V_2 -> V_17 -> V_181 ( V_2 , V_174 ,
F_33 ( V_2 , 2 , V_105 ) ) ) ;
}
F_106 ( V_104 , -- V_168 ) ;
F_88 ( V_2 , V_167 , V_182 ) ;
F_106 ( V_105 , ++ V_170 ) ;
F_88 ( V_2 , V_169 , V_182 ) ;
error = F_24 ( V_2 , & V_183 ) ;
if ( error )
goto V_141;
V_50 = F_48 ( V_183 , V_5 ) ;
F_108 ( V_50 == 1 , V_141 ) ;
error = F_91 ( V_183 , V_5 , & V_50 ) ;
if ( error )
goto V_186;
error = F_100 ( V_183 , V_172 , V_5 + 1 ) ;
if ( error )
goto V_186;
F_21 ( V_183 , V_187 ) ;
F_81 ( V_2 , V_136 ) ;
* V_140 = 1 ;
return 0 ;
V_143:
F_81 ( V_2 , V_136 ) ;
* V_140 = 0 ;
return 0 ;
V_141:
F_81 ( V_2 , V_146 ) ;
return error ;
V_186:
F_81 ( V_183 , V_146 ) ;
F_21 ( V_183 , V_188 ) ;
return error ;
}
STATIC int
F_109 (
struct V_1 * V_2 ,
int V_5 ,
union V_47 * V_145 ,
union V_76 * V_132 ,
struct V_1 * * V_189 ,
int * V_140 )
{
union V_47 V_171 ;
struct V_6 * V_167 ;
struct V_3 * V_104 ;
union V_47 V_184 ;
struct V_6 * V_169 ;
struct V_3 * V_105 ;
union V_47 V_190 ;
struct V_6 * V_191 ;
struct V_3 * V_192 ;
int V_168 ;
int V_170 ;
int V_193 ;
int error ;
#ifdef F_93
int V_50 ;
#endif
F_81 ( V_2 , V_135 ) ;
F_110 ( V_2 , V_5 , * V_145 , V_132 ) ;
F_95 ( V_2 , V_194 ) ;
V_104 = F_39 ( V_2 , V_5 , & V_167 ) ;
#ifdef F_93
error = F_16 ( V_2 , V_104 , V_5 , V_167 ) ;
if ( error )
goto V_141;
#endif
F_67 ( V_2 , V_167 , & V_171 ) ;
error = V_2 -> V_17 -> V_195 ( V_2 , & V_171 , & V_184 , 1 , V_140 ) ;
if ( error )
goto V_141;
if ( * V_140 == 0 )
goto V_143;
F_95 ( V_2 , V_196 ) ;
error = F_72 ( V_2 , & V_184 , 0 , & V_105 , & V_169 ) ;
if ( error )
goto V_141;
F_65 ( V_2 , F_36 ( V_104 ) , 0 , V_169 ) ;
V_168 = F_94 ( V_104 ) ;
V_170 = V_168 / 2 ;
if ( ( V_168 & 1 ) && V_2 -> V_63 [ V_5 ] <= V_170 + 1 )
V_170 ++ ;
V_193 = ( V_168 - V_170 + 1 ) ;
F_105 ( V_2 , V_176 , V_170 ) ;
if ( V_5 > 0 ) {
union V_76 * V_177 ;
union V_47 * V_178 ;
union V_76 * V_172 ;
union V_47 * V_173 ;
V_177 = F_34 ( V_2 , V_193 , V_104 ) ;
V_178 = F_35 ( V_2 , V_193 , V_104 ) ;
V_172 = F_34 ( V_2 , 1 , V_105 ) ;
V_173 = F_35 ( V_2 , 1 , V_105 ) ;
#ifdef F_93
for ( V_50 = V_193 ; V_50 < V_170 ; V_50 ++ ) {
error = F_20 ( V_2 , V_178 , V_50 , V_5 ) ;
if ( error )
goto V_141;
}
#endif
F_74 ( V_2 , V_172 , V_177 , V_170 ) ;
F_76 ( V_2 , V_173 , V_178 , V_170 ) ;
F_80 ( V_2 , V_169 , 1 , V_170 ) ;
F_87 ( V_2 , V_169 , 1 , V_170 ) ;
F_74 ( V_2 , V_132 , V_172 , 1 ) ;
} else {
union V_75 * V_180 ;
union V_75 * V_174 ;
V_180 = F_33 ( V_2 , V_193 , V_104 ) ;
V_174 = F_33 ( V_2 , 1 , V_105 ) ;
F_75 ( V_2 , V_174 , V_180 , V_170 ) ;
F_86 ( V_2 , V_169 , 1 , V_170 ) ;
V_2 -> V_17 -> V_152 ( V_132 ,
F_33 ( V_2 , 1 , V_105 ) ) ;
}
F_61 ( V_2 , V_104 , & V_190 , V_110 ) ;
F_62 ( V_2 , V_105 , & V_190 , V_110 ) ;
F_62 ( V_2 , V_105 , & V_171 , V_109 ) ;
F_62 ( V_2 , V_104 , & V_184 , V_110 ) ;
V_168 -= V_170 ;
F_106 ( V_104 , V_168 ) ;
F_106 ( V_105 , F_94 ( V_105 ) + V_170 ) ;
F_88 ( V_2 , V_169 , V_197 ) ;
F_88 ( V_2 , V_167 , V_182 | V_110 ) ;
if ( ! F_59 ( V_2 , & V_190 ) ) {
error = F_73 ( V_2 , & V_190 , V_5 ,
0 , & V_192 , & V_191 ) ;
if ( error )
goto V_141;
F_62 ( V_2 , V_192 , & V_184 , V_109 ) ;
F_88 ( V_2 , V_191 , V_109 ) ;
}
if ( V_2 -> V_63 [ V_5 ] > V_168 + 1 ) {
F_58 ( V_2 , V_5 , V_169 ) ;
V_2 -> V_63 [ V_5 ] -= V_168 ;
}
if ( V_5 + 1 < V_2 -> V_51 ) {
error = F_24 ( V_2 , V_189 ) ;
if ( error )
goto V_141;
( * V_189 ) -> V_63 [ V_5 + 1 ] ++ ;
}
* V_145 = V_184 ;
F_81 ( V_2 , V_136 ) ;
* V_140 = 1 ;
return 0 ;
V_143:
F_81 ( V_2 , V_136 ) ;
* V_140 = 0 ;
return 0 ;
V_141:
F_81 ( V_2 , V_146 ) ;
return error ;
}
int
F_111 (
struct V_1 * V_2 ,
int * V_198 ,
int * V_140 )
{
struct V_6 * V_199 ;
struct V_3 * V_4 ;
struct V_3 * V_200 ;
union V_76 * V_201 ;
union V_47 * V_202 ;
union V_76 * V_151 ;
union V_47 * V_148 ;
union V_47 V_203 ;
int V_5 ;
int error ;
#ifdef F_93
int V_50 ;
#endif
F_81 ( V_2 , V_135 ) ;
F_95 ( V_2 , V_204 ) ;
ASSERT ( V_2 -> V_41 & V_83 ) ;
V_5 = V_2 -> V_51 - 1 ;
V_4 = F_37 ( V_2 ) ;
V_148 = F_35 ( V_2 , 1 , V_4 ) ;
error = V_2 -> V_17 -> V_195 ( V_2 , V_148 , & V_203 , 1 , V_140 ) ;
if ( error )
goto V_141;
if ( * V_140 == 0 ) {
F_81 ( V_2 , V_136 ) ;
return 0 ;
}
F_95 ( V_2 , V_196 ) ;
error = F_72 ( V_2 , & V_203 , 0 , & V_200 , & V_199 ) ;
if ( error )
goto V_141;
memcpy ( V_200 , V_4 , F_28 ( V_2 ) ) ;
F_112 ( & V_4 -> V_15 , 1 ) ;
F_106 ( V_4 , 1 ) ;
V_2 -> V_51 ++ ;
V_2 -> V_63 [ V_5 + 1 ] = 1 ;
V_151 = F_34 ( V_2 , 1 , V_4 ) ;
V_201 = F_34 ( V_2 , 1 , V_200 ) ;
F_74 ( V_2 , V_201 , V_151 , F_94 ( V_200 ) ) ;
V_202 = F_35 ( V_2 , 1 , V_200 ) ;
#ifdef F_93
for ( V_50 = 0 ; V_50 < F_3 ( V_200 -> V_16 ) ; V_50 ++ ) {
error = F_20 ( V_2 , V_148 , V_50 , V_5 ) ;
if ( error )
goto V_141;
}
#endif
F_76 ( V_2 , V_202 , V_148 , F_94 ( V_200 ) ) ;
#ifdef F_93
error = F_20 ( V_2 , & V_203 , 0 , V_5 ) ;
if ( error )
goto V_141;
#endif
F_76 ( V_2 , V_148 , & V_203 , 1 ) ;
F_113 ( V_2 -> V_34 . V_55 . V_79 ,
1 - F_94 ( V_200 ) ,
V_2 -> V_34 . V_55 . V_80 ) ;
F_58 ( V_2 , V_5 , V_199 ) ;
F_88 ( V_2 , V_199 , V_197 ) ;
F_80 ( V_2 , V_199 , 1 , F_3 ( V_200 -> V_16 ) ) ;
F_87 ( V_2 , V_199 , 1 , F_3 ( V_200 -> V_16 ) ) ;
* V_198 |=
V_205 | F_85 ( V_2 -> V_34 . V_55 . V_80 ) ;
* V_140 = 1 ;
F_81 ( V_2 , V_136 ) ;
return 0 ;
V_141:
F_81 ( V_2 , V_146 ) ;
return error ;
}
STATIC int
F_114 (
struct V_1 * V_2 ,
int * V_140 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int error ;
struct V_6 * V_167 ;
struct V_3 * V_104 ;
struct V_6 * V_206 ;
struct V_3 * V_59 ;
int V_203 ;
struct V_6 * V_169 ;
struct V_3 * V_105 ;
union V_47 V_184 ;
union V_47 V_171 ;
F_81 ( V_2 , V_135 ) ;
F_95 ( V_2 , V_204 ) ;
V_2 -> V_17 -> V_155 ( V_2 , & V_184 ) ;
error = V_2 -> V_17 -> V_195 ( V_2 , & V_184 , & V_171 , 1 , V_140 ) ;
if ( error )
goto V_141;
if ( * V_140 == 0 )
goto V_143;
F_95 ( V_2 , V_196 ) ;
error = F_72 ( V_2 , & V_171 , 0 , & V_59 , & V_206 ) ;
if ( error )
goto V_141;
V_2 -> V_17 -> V_207 ( V_2 , & V_171 , 1 ) ;
V_4 = F_39 ( V_2 , V_2 -> V_51 - 1 , & V_7 ) ;
#ifdef F_93
error = F_16 ( V_2 , V_4 , V_2 -> V_51 - 1 , V_7 ) ;
if ( error )
goto V_141;
#endif
F_61 ( V_2 , V_4 , & V_184 , V_110 ) ;
if ( ! F_59 ( V_2 , & V_184 ) ) {
V_167 = V_7 ;
F_67 ( V_2 , V_167 , & V_171 ) ;
V_104 = V_4 ;
error = F_73 ( V_2 , & V_184 ,
V_2 -> V_51 - 1 , 0 , & V_105 , & V_169 ) ;
if ( error )
goto V_141;
V_7 = V_169 ;
V_203 = 1 ;
} else {
V_169 = V_7 ;
F_67 ( V_2 , V_169 , & V_184 ) ;
V_105 = V_4 ;
F_61 ( V_2 , V_105 , & V_171 , V_109 ) ;
error = F_73 ( V_2 , & V_171 ,
V_2 -> V_51 - 1 , 0 , & V_104 , & V_167 ) ;
if ( error )
goto V_141;
V_7 = V_167 ;
V_203 = 2 ;
}
F_65 ( V_2 , V_2 -> V_51 , 2 , V_206 ) ;
F_88 ( V_2 , V_206 , V_197 ) ;
ASSERT ( ! F_59 ( V_2 , & V_171 ) &&
! F_59 ( V_2 , & V_184 ) ) ;
if ( F_36 ( V_104 ) > 0 ) {
F_74 ( V_2 ,
F_34 ( V_2 , 1 , V_59 ) ,
F_34 ( V_2 , 1 , V_104 ) , 1 ) ;
F_74 ( V_2 ,
F_34 ( V_2 , 2 , V_59 ) ,
F_34 ( V_2 , 1 , V_105 ) , 1 ) ;
} else {
V_2 -> V_17 -> V_152 (
F_34 ( V_2 , 1 , V_59 ) ,
F_33 ( V_2 , 1 , V_104 ) ) ;
V_2 -> V_17 -> V_152 (
F_34 ( V_2 , 2 , V_59 ) ,
F_33 ( V_2 , 1 , V_105 ) ) ;
}
F_80 ( V_2 , V_206 , 1 , 2 ) ;
F_76 ( V_2 ,
F_35 ( V_2 , 1 , V_59 ) , & V_171 , 1 ) ;
F_76 ( V_2 ,
F_35 ( V_2 , 2 , V_59 ) , & V_184 , 1 ) ;
F_87 ( V_2 , V_206 , 1 , 2 ) ;
F_58 ( V_2 , V_2 -> V_51 , V_206 ) ;
V_2 -> V_63 [ V_2 -> V_51 ] = V_203 ;
V_2 -> V_51 ++ ;
F_81 ( V_2 , V_136 ) ;
* V_140 = 1 ;
return 0 ;
V_141:
F_81 ( V_2 , V_146 ) ;
return error ;
V_143:
F_81 ( V_2 , V_136 ) ;
* V_140 = 0 ;
return 0 ;
}
STATIC int
F_115 (
struct V_1 * V_2 ,
int V_5 ,
int V_112 ,
int * V_208 ,
int * V_49 ,
union V_47 * V_203 ,
struct V_1 * * V_58 ,
union V_75 * V_209 ,
int * V_140 )
{
union V_76 V_132 ;
int error = 0 ;
if ( ( V_2 -> V_41 & V_83 ) &&
V_5 == V_2 -> V_51 - 1 ) {
struct V_210 * V_79 = V_2 -> V_34 . V_55 . V_79 ;
if ( V_112 < V_2 -> V_17 -> V_211 ( V_2 , V_5 ) ) {
F_113 ( V_79 , 1 , V_2 -> V_34 . V_55 . V_80 ) ;
} else {
int V_198 = 0 ;
error = F_111 ( V_2 , & V_198 , V_140 ) ;
if ( error || * V_140 == 0 )
return error ;
F_84 ( V_2 -> V_53 , V_79 , V_198 ) ;
}
return 0 ;
}
error = F_107 ( V_2 , V_5 , V_140 ) ;
if ( error || * V_140 )
return error ;
error = F_104 ( V_2 , V_5 , V_140 ) ;
if ( error )
return error ;
if ( * V_140 ) {
* V_208 = * V_49 = V_2 -> V_63 [ V_5 ] ;
return 0 ;
}
error = F_109 ( V_2 , V_5 , V_203 , & V_132 , V_58 , V_140 ) ;
if ( error || * V_140 == 0 )
return error ;
* V_49 = V_2 -> V_63 [ V_5 ] ;
V_2 -> V_17 -> V_212 ( & V_132 , V_209 ) ;
return 0 ;
}
STATIC int
F_116 (
struct V_1 * V_2 ,
int V_5 ,
union V_47 * V_145 ,
union V_75 * V_213 ,
struct V_1 * * V_189 ,
int * V_140 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_76 V_132 ;
union V_47 V_203 ;
struct V_1 * V_58 ;
union V_75 V_209 ;
int V_214 ;
int V_48 ;
int V_112 ;
int error ;
#ifdef F_93
int V_50 ;
#endif
F_81 ( V_2 , V_135 ) ;
F_117 ( V_2 , V_5 , * V_145 , V_213 ) ;
V_58 = NULL ;
if ( ! ( V_2 -> V_41 & V_83 ) &&
( V_5 >= V_2 -> V_51 ) ) {
error = F_114 ( V_2 , V_140 ) ;
F_60 ( V_2 , V_145 ) ;
F_81 ( V_2 , V_136 ) ;
return error ;
}
V_48 = V_2 -> V_63 [ V_5 ] ;
if ( V_48 == 0 ) {
F_81 ( V_2 , V_136 ) ;
* V_140 = 0 ;
return 0 ;
}
V_2 -> V_17 -> V_152 ( & V_132 , V_213 ) ;
V_214 = V_48 ;
F_95 ( V_2 , V_215 ) ;
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
V_112 = F_94 ( V_4 ) ;
#ifdef F_93
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_141;
if ( V_48 <= V_112 ) {
if ( V_5 == 0 ) {
ASSERT ( V_2 -> V_17 -> V_181 ( V_2 , V_213 ,
F_33 ( V_2 , V_48 , V_4 ) ) ) ;
} else {
ASSERT ( V_2 -> V_17 -> V_179 ( V_2 , & V_132 ,
F_34 ( V_2 , V_48 , V_4 ) ) ) ;
}
}
#endif
F_60 ( V_2 , & V_203 ) ;
if ( V_112 == V_2 -> V_17 -> V_18 ( V_2 , V_5 ) ) {
error = F_115 ( V_2 , V_5 , V_112 ,
& V_214 , & V_48 , & V_203 , & V_58 , & V_209 , V_140 ) ;
if ( error || * V_140 == 0 )
goto V_141;
}
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
V_112 = F_94 ( V_4 ) ;
#ifdef F_93
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
return error ;
#endif
F_105 ( V_2 , V_176 , V_112 - V_48 + 1 ) ;
if ( V_5 > 0 ) {
union V_76 * V_151 ;
union V_47 * V_148 ;
V_151 = F_34 ( V_2 , V_48 , V_4 ) ;
V_148 = F_35 ( V_2 , V_48 , V_4 ) ;
#ifdef F_93
for ( V_50 = V_112 - V_48 ; V_50 >= 0 ; V_50 -- ) {
error = F_20 ( V_2 , V_148 , V_50 , V_5 ) ;
if ( error )
return error ;
}
#endif
F_77 ( V_2 , V_151 , 1 , V_112 - V_48 + 1 ) ;
F_79 ( V_2 , V_148 , 1 , V_112 - V_48 + 1 ) ;
#ifdef F_93
error = F_20 ( V_2 , V_145 , 0 , V_5 ) ;
if ( error )
goto V_141;
#endif
F_74 ( V_2 , V_151 , & V_132 , 1 ) ;
F_76 ( V_2 , V_148 , V_145 , 1 ) ;
V_112 ++ ;
F_106 ( V_4 , V_112 ) ;
F_87 ( V_2 , V_7 , V_48 , V_112 ) ;
F_80 ( V_2 , V_7 , V_48 , V_112 ) ;
#ifdef F_93
if ( V_48 < V_112 ) {
ASSERT ( V_2 -> V_17 -> V_179 ( V_2 , V_151 ,
F_34 ( V_2 , V_48 + 1 , V_4 ) ) ) ;
}
#endif
} else {
union V_75 * V_164 ;
V_164 = F_33 ( V_2 , V_48 , V_4 ) ;
F_78 ( V_2 , V_164 , 1 , V_112 - V_48 + 1 ) ;
F_75 ( V_2 , V_164 , V_213 , 1 ) ;
F_106 ( V_4 , ++ V_112 ) ;
F_86 ( V_2 , V_7 , V_48 , V_112 ) ;
#ifdef F_93
if ( V_48 < V_112 ) {
ASSERT ( V_2 -> V_17 -> V_181 ( V_2 , V_164 ,
F_33 ( V_2 , V_48 + 1 , V_4 ) ) ) ;
}
#endif
}
F_88 ( V_2 , V_7 , V_182 ) ;
if ( V_214 == 1 ) {
error = F_100 ( V_2 , & V_132 , V_5 + 1 ) ;
if ( error )
goto V_141;
}
if ( F_66 ( V_2 , V_4 , V_5 ) ) {
V_2 -> V_17 -> V_165 ( V_2 , V_4 , V_213 ,
V_48 , V_216 ) ;
}
* V_145 = V_203 ;
if ( ! F_59 ( V_2 , & V_203 ) ) {
* V_213 = V_209 ;
* V_189 = V_58 ;
}
F_81 ( V_2 , V_136 ) ;
* V_140 = 1 ;
return 0 ;
V_141:
F_81 ( V_2 , V_146 ) ;
return error ;
}
int
F_118 (
struct V_1 * V_2 ,
int * V_140 )
{
int error ;
int V_50 ;
int V_5 ;
union V_47 V_203 ;
struct V_1 * V_58 ;
struct V_1 * V_217 ;
union V_75 V_134 ;
V_5 = 0 ;
V_58 = NULL ;
V_217 = V_2 ;
F_60 ( V_2 , & V_203 ) ;
V_2 -> V_17 -> V_218 ( V_2 , & V_134 ) ;
do {
error = F_116 ( V_217 , V_5 , & V_203 , & V_134 , & V_58 , & V_50 ) ;
if ( error ) {
if ( V_217 != V_2 )
F_21 ( V_217 , V_188 ) ;
goto V_141;
}
F_108 ( V_50 == 1 , V_141 ) ;
V_5 ++ ;
if ( V_217 != V_2 &&
( V_58 || F_59 ( V_2 , & V_203 ) ) ) {
if ( V_2 -> V_17 -> V_219 )
V_2 -> V_17 -> V_219 ( V_217 , V_2 ) ;
V_2 -> V_51 = V_217 -> V_51 ;
F_21 ( V_217 , V_187 ) ;
}
if ( V_58 ) {
V_217 = V_58 ;
V_58 = NULL ;
}
} while ( ! F_59 ( V_2 , & V_203 ) );
F_81 ( V_2 , V_136 ) ;
* V_140 = V_50 ;
return 0 ;
V_141:
F_81 ( V_2 , V_146 ) ;
return error ;
}
STATIC int
F_119 (
struct V_1 * V_2 )
{
int V_80 = V_2 -> V_34 . V_55 . V_80 ;
struct V_210 * V_79 = V_2 -> V_34 . V_55 . V_79 ;
struct V_77 * V_78 = F_38 ( V_79 , V_80 ) ;
struct V_3 * V_4 ;
struct V_3 * V_200 ;
union V_76 * V_151 ;
union V_76 * V_201 ;
union V_47 * V_148 ;
union V_47 * V_202 ;
struct V_6 * V_199 ;
int V_5 ;
int V_49 ;
int V_112 ;
#ifdef F_93
union V_47 V_48 ;
int V_50 ;
#endif
F_81 ( V_2 , V_135 ) ;
ASSERT ( V_2 -> V_41 & V_83 ) ;
ASSERT ( V_2 -> V_51 > 1 ) ;
V_5 = V_2 -> V_51 - 1 ;
if ( V_5 == 1 )
goto V_143;
V_4 = F_37 ( V_2 ) ;
if ( F_94 ( V_4 ) != 1 )
goto V_143;
V_200 = F_39 ( V_2 , V_5 - 1 , & V_199 ) ;
V_112 = F_94 ( V_200 ) ;
if ( V_112 > V_2 -> V_17 -> V_211 ( V_2 , V_5 ) )
goto V_143;
F_95 ( V_2 , V_220 ) ;
#ifdef F_93
F_61 ( V_2 , V_4 , & V_48 , V_109 ) ;
ASSERT ( F_59 ( V_2 , & V_48 ) ) ;
F_61 ( V_2 , V_4 , & V_48 , V_110 ) ;
ASSERT ( F_59 ( V_2 , & V_48 ) ) ;
#endif
V_49 = V_112 - V_2 -> V_17 -> V_18 ( V_2 , V_5 ) ;
if ( V_49 ) {
F_113 ( V_2 -> V_34 . V_55 . V_79 , V_49 ,
V_2 -> V_34 . V_55 . V_80 ) ;
V_4 = V_78 -> V_81 ;
}
F_112 ( & V_4 -> V_16 , V_49 ) ;
ASSERT ( V_4 -> V_16 == V_200 -> V_16 ) ;
V_151 = F_34 ( V_2 , 1 , V_4 ) ;
V_201 = F_34 ( V_2 , 1 , V_200 ) ;
F_74 ( V_2 , V_151 , V_201 , V_112 ) ;
V_148 = F_35 ( V_2 , 1 , V_4 ) ;
V_202 = F_35 ( V_2 , 1 , V_200 ) ;
#ifdef F_93
for ( V_50 = 0 ; V_50 < V_112 ; V_50 ++ ) {
int error ;
error = F_20 ( V_2 , V_202 , V_50 , V_5 - 1 ) ;
if ( error ) {
F_81 ( V_2 , V_146 ) ;
return error ;
}
}
#endif
F_76 ( V_2 , V_148 , V_202 , V_112 ) ;
V_2 -> V_17 -> V_221 ( V_2 , V_199 ) ;
F_95 ( V_2 , free ) ;
V_2 -> V_52 [ V_5 - 1 ] = NULL ;
F_112 ( & V_4 -> V_15 , - 1 ) ;
F_84 ( V_2 -> V_53 , V_79 ,
V_205 | F_85 ( V_2 -> V_34 . V_55 . V_80 ) ) ;
V_2 -> V_51 -- ;
V_143:
F_81 ( V_2 , V_136 ) ;
return 0 ;
}
STATIC int
F_120 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_5 ,
union V_47 * V_204 )
{
int error ;
F_81 ( V_2 , V_135 ) ;
F_95 ( V_2 , V_220 ) ;
V_2 -> V_17 -> V_207 ( V_2 , V_204 , - 1 ) ;
error = V_2 -> V_17 -> V_221 ( V_2 , V_7 ) ;
if ( error ) {
F_81 ( V_2 , V_146 ) ;
return error ;
}
F_95 ( V_2 , free ) ;
V_2 -> V_52 [ V_5 ] = NULL ;
V_2 -> V_64 [ V_5 ] = 0 ;
V_2 -> V_51 -- ;
F_81 ( V_2 , V_136 ) ;
return 0 ;
}
STATIC int
F_121 (
struct V_1 * V_2 ,
int V_5 ,
int * V_140 )
{
int error ;
int V_50 ;
if ( V_5 > 0 ) {
error = F_96 ( V_2 , V_5 , & V_50 ) ;
if ( error )
return error ;
}
F_81 ( V_2 , V_136 ) ;
* V_140 = 1 ;
return 0 ;
}
STATIC int
F_122 (
struct V_1 * V_2 ,
int V_5 ,
int * V_140 )
{
struct V_3 * V_4 ;
union V_47 V_222 ;
struct V_6 * V_7 ;
int error ;
int V_50 ;
union V_76 V_132 ;
union V_76 * V_163 = & V_132 ;
union V_47 V_171 ;
struct V_6 * V_167 ;
struct V_3 * V_104 ;
int V_168 = 0 ;
int V_48 ;
union V_47 V_184 ;
struct V_6 * V_169 ;
struct V_3 * V_105 ;
struct V_3 * V_192 ;
struct V_6 * V_191 ;
int V_170 = 0 ;
struct V_1 * V_183 ;
int V_112 ;
F_81 ( V_2 , V_135 ) ;
F_92 ( V_2 , V_5 ) ;
V_183 = NULL ;
V_48 = V_2 -> V_63 [ V_5 ] ;
if ( V_48 == 0 ) {
F_81 ( V_2 , V_136 ) ;
* V_140 = 0 ;
return 0 ;
}
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
V_112 = F_94 ( V_4 ) ;
#ifdef F_93
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_141;
#endif
if ( V_48 > V_112 ) {
F_81 ( V_2 , V_136 ) ;
* V_140 = 0 ;
return 0 ;
}
F_95 ( V_2 , V_223 ) ;
F_105 ( V_2 , V_176 , V_112 - V_48 ) ;
if ( V_5 > 0 ) {
union V_76 * V_177 ;
union V_47 * V_178 ;
V_177 = F_34 ( V_2 , V_48 + 1 , V_4 ) ;
V_178 = F_35 ( V_2 , V_48 + 1 , V_4 ) ;
#ifdef F_93
for ( V_50 = 0 ; V_50 < V_112 - V_48 ; V_50 ++ ) {
error = F_20 ( V_2 , V_178 , V_50 , V_5 ) ;
if ( error )
goto V_141;
}
#endif
if ( V_48 < V_112 ) {
F_77 ( V_2 , V_177 , - 1 , V_112 - V_48 ) ;
F_79 ( V_2 , V_178 , - 1 , V_112 - V_48 ) ;
F_80 ( V_2 , V_7 , V_48 , V_112 - 1 ) ;
F_87 ( V_2 , V_7 , V_48 , V_112 - 1 ) ;
}
if ( V_48 == 1 )
V_163 = F_34 ( V_2 , 1 , V_4 ) ;
} else {
if ( V_48 < V_112 ) {
F_78 ( V_2 ,
F_33 ( V_2 , V_48 + 1 , V_4 ) ,
- 1 , V_112 - V_48 ) ;
F_86 ( V_2 , V_7 , V_48 , V_112 - 1 ) ;
}
if ( V_48 == 1 ) {
V_2 -> V_17 -> V_152 ( & V_132 ,
F_33 ( V_2 , 1 , V_4 ) ) ;
V_163 = & V_132 ;
}
}
F_106 ( V_4 , -- V_112 ) ;
F_88 ( V_2 , V_7 , V_182 ) ;
if ( F_66 ( V_2 , V_4 , V_5 ) ) {
V_2 -> V_17 -> V_165 ( V_2 , V_4 , NULL ,
V_48 , V_224 ) ;
}
if ( V_5 == V_2 -> V_51 - 1 ) {
if ( V_2 -> V_41 & V_83 ) {
F_113 ( V_2 -> V_34 . V_55 . V_79 , - 1 ,
V_2 -> V_34 . V_55 . V_80 ) ;
error = F_119 ( V_2 ) ;
if ( error )
goto V_141;
error = F_121 ( V_2 , V_5 , V_140 ) ;
if ( error )
goto V_141;
* V_140 = 1 ;
return 0 ;
}
if ( V_112 == 1 && V_5 > 0 ) {
union V_47 * V_148 ;
V_148 = F_35 ( V_2 , 1 , V_4 ) ;
error = F_120 ( V_2 , V_7 , V_5 , V_148 ) ;
if ( error )
goto V_141;
} else if ( V_5 > 0 ) {
error = F_121 ( V_2 , V_5 , V_140 ) ;
if ( error )
goto V_141;
}
* V_140 = 1 ;
return 0 ;
}
if ( V_48 == 1 ) {
error = F_100 ( V_2 , V_163 , V_5 + 1 ) ;
if ( error )
goto V_141;
}
if ( V_112 >= V_2 -> V_17 -> V_225 ( V_2 , V_5 ) ) {
error = F_121 ( V_2 , V_5 , V_140 ) ;
if ( error )
goto V_141;
return 0 ;
}
F_61 ( V_2 , V_4 , & V_184 , V_110 ) ;
F_61 ( V_2 , V_4 , & V_171 , V_109 ) ;
if ( V_2 -> V_41 & V_83 ) {
if ( F_59 ( V_2 , & V_184 ) &&
F_59 ( V_2 , & V_171 ) &&
V_5 == V_2 -> V_51 - 2 ) {
error = F_119 ( V_2 ) ;
if ( ! error )
error = F_121 ( V_2 , V_5 , V_140 ) ;
if ( error )
goto V_141;
return 0 ;
}
}
ASSERT ( ! F_59 ( V_2 , & V_184 ) ||
! F_59 ( V_2 , & V_171 ) ) ;
error = F_24 ( V_2 , & V_183 ) ;
if ( error )
goto V_141;
if ( ! F_59 ( V_2 , & V_184 ) ) {
V_50 = F_48 ( V_183 , V_5 ) ;
F_108 ( V_50 == 1 , V_141 ) ;
error = F_91 ( V_183 , V_5 , & V_50 ) ;
if ( error )
goto V_141;
F_108 ( V_50 == 1 , V_141 ) ;
V_50 = F_48 ( V_183 , V_5 ) ;
F_108 ( V_50 == 1 , V_141 ) ;
V_105 = F_39 ( V_183 , V_5 , & V_169 ) ;
#ifdef F_93
error = F_16 ( V_183 , V_105 , V_5 , V_169 ) ;
if ( error )
goto V_141;
#endif
F_61 ( V_183 , V_105 , & V_222 , V_109 ) ;
if ( F_94 ( V_105 ) - 1 >=
V_2 -> V_17 -> V_225 ( V_183 , V_5 ) ) {
error = F_104 ( V_183 , V_5 , & V_50 ) ;
if ( error )
goto V_141;
if ( V_50 ) {
ASSERT ( F_94 ( V_4 ) >=
V_2 -> V_17 -> V_225 ( V_183 , V_5 ) ) ;
F_21 ( V_183 , V_187 ) ;
V_183 = NULL ;
error = F_121 ( V_2 , V_5 , V_140 ) ;
if ( error )
goto V_141;
return 0 ;
}
}
V_170 = F_94 ( V_105 ) ;
if ( ! F_59 ( V_2 , & V_171 ) ) {
V_50 = F_47 ( V_183 , V_5 ) ;
F_108 ( V_50 == 1 , V_141 ) ;
error = F_96 ( V_183 , V_5 , & V_50 ) ;
if ( error )
goto V_141;
F_108 ( V_50 == 1 , V_141 ) ;
}
}
if ( ! F_59 ( V_2 , & V_171 ) ) {
V_50 = F_47 ( V_183 , V_5 ) ;
F_108 ( V_50 == 1 , V_141 ) ;
error = F_96 ( V_183 , V_5 , & V_50 ) ;
if ( error )
goto V_141;
V_50 = F_47 ( V_183 , V_5 ) ;
F_108 ( V_50 == 1 , V_141 ) ;
V_104 = F_39 ( V_183 , V_5 , & V_167 ) ;
#ifdef F_93
error = F_16 ( V_2 , V_104 , V_5 , V_167 ) ;
if ( error )
goto V_141;
#endif
F_61 ( V_183 , V_104 , & V_222 , V_110 ) ;
if ( F_94 ( V_104 ) - 1 >=
V_2 -> V_17 -> V_225 ( V_183 , V_5 ) ) {
error = F_107 ( V_183 , V_5 , & V_50 ) ;
if ( error )
goto V_141;
if ( V_50 ) {
ASSERT ( F_94 ( V_4 ) >=
V_2 -> V_17 -> V_225 ( V_183 , V_5 ) ) ;
F_21 ( V_183 , V_187 ) ;
V_183 = NULL ;
if ( V_5 == 0 )
V_2 -> V_63 [ 0 ] ++ ;
F_81 ( V_2 , V_136 ) ;
* V_140 = 1 ;
return 0 ;
}
}
V_168 = F_94 ( V_104 ) ;
}
F_21 ( V_183 , V_187 ) ;
V_183 = NULL ;
ASSERT ( ! F_59 ( V_2 , & V_222 ) ) ;
if ( ! F_59 ( V_2 , & V_171 ) &&
V_168 + F_94 ( V_4 ) <=
V_2 -> V_17 -> V_18 ( V_2 , V_5 ) ) {
V_184 = V_222 ;
V_105 = V_4 ;
V_169 = V_7 ;
error = F_73 ( V_2 , & V_171 , V_5 ,
0 , & V_104 , & V_167 ) ;
if ( error )
goto V_141;
} else if ( ! F_59 ( V_2 , & V_184 ) &&
V_170 + F_94 ( V_4 ) <=
V_2 -> V_17 -> V_18 ( V_2 , V_5 ) ) {
V_171 = V_222 ;
V_104 = V_4 ;
V_167 = V_7 ;
error = F_73 ( V_2 , & V_184 , V_5 ,
0 , & V_105 , & V_169 ) ;
if ( error )
goto V_141;
} else {
error = F_121 ( V_2 , V_5 , V_140 ) ;
if ( error )
goto V_141;
return 0 ;
}
V_170 = F_94 ( V_105 ) ;
V_168 = F_94 ( V_104 ) ;
F_105 ( V_2 , V_176 , V_170 ) ;
if ( V_5 > 0 ) {
union V_76 * V_177 ;
union V_47 * V_178 ;
union V_76 * V_172 ;
union V_47 * V_173 ;
V_177 = F_34 ( V_2 , V_168 + 1 , V_104 ) ;
V_178 = F_35 ( V_2 , V_168 + 1 , V_104 ) ;
V_172 = F_34 ( V_2 , 1 , V_105 ) ;
V_173 = F_35 ( V_2 , 1 , V_105 ) ;
#ifdef F_93
for ( V_50 = 1 ; V_50 < V_170 ; V_50 ++ ) {
error = F_20 ( V_2 , V_173 , V_50 , V_5 ) ;
if ( error )
goto V_141;
}
#endif
F_74 ( V_2 , V_177 , V_172 , V_170 ) ;
F_76 ( V_2 , V_178 , V_173 , V_170 ) ;
F_80 ( V_2 , V_167 , V_168 + 1 , V_168 + V_170 ) ;
F_87 ( V_2 , V_167 , V_168 + 1 , V_168 + V_170 ) ;
} else {
union V_75 * V_180 ;
union V_75 * V_174 ;
V_180 = F_33 ( V_2 , V_168 + 1 , V_104 ) ;
V_174 = F_33 ( V_2 , 1 , V_105 ) ;
F_75 ( V_2 , V_180 , V_174 , V_170 ) ;
F_86 ( V_2 , V_167 , V_168 + 1 , V_168 + V_170 ) ;
}
F_95 ( V_2 , V_226 ) ;
F_106 ( V_104 , V_168 + V_170 ) ;
F_61 ( V_2 , V_105 , & V_222 , V_110 ) ,
F_62 ( V_2 , V_104 , & V_222 , V_110 ) ;
F_88 ( V_2 , V_167 , V_182 | V_110 ) ;
F_61 ( V_2 , V_104 , & V_222 , V_110 ) ;
if ( ! F_59 ( V_2 , & V_222 ) ) {
error = F_73 ( V_2 , & V_222 , V_5 ,
0 , & V_192 , & V_191 ) ;
if ( error )
goto V_141;
F_62 ( V_2 , V_192 , & V_171 , V_109 ) ;
F_88 ( V_2 , V_191 , V_109 ) ;
}
error = V_2 -> V_17 -> V_221 ( V_2 , V_169 ) ;
if ( error )
goto V_141;
F_95 ( V_2 , free ) ;
if ( V_7 != V_167 ) {
V_2 -> V_52 [ V_5 ] = V_167 ;
V_2 -> V_63 [ V_5 ] += V_168 ;
V_2 -> V_64 [ V_5 ] = 0 ;
}
else if ( ( V_2 -> V_41 & V_83 ) ||
( V_5 + 1 < V_2 -> V_51 ) ) {
error = F_91 ( V_2 , V_5 + 1 , & V_50 ) ;
if ( error )
goto V_141;
}
if ( V_5 > 0 )
V_2 -> V_63 [ V_5 ] -- ;
F_81 ( V_2 , V_136 ) ;
* V_140 = 2 ;
return 0 ;
V_141:
F_81 ( V_2 , V_146 ) ;
if ( V_183 )
F_21 ( V_183 , V_188 ) ;
return error ;
}
int
F_123 (
struct V_1 * V_2 ,
int * V_140 )
{
int error ;
int V_5 ;
int V_50 ;
F_81 ( V_2 , V_135 ) ;
for ( V_5 = 0 , V_50 = 2 ; V_50 == 2 ; V_5 ++ ) {
error = F_122 ( V_2 , V_5 , & V_50 ) ;
if ( error )
goto V_141;
}
if ( V_50 == 0 ) {
for ( V_5 = 1 ; V_5 < V_2 -> V_51 ; V_5 ++ ) {
if ( V_2 -> V_63 [ V_5 ] == 0 ) {
error = F_96 ( V_2 , V_5 , & V_50 ) ;
if ( error )
goto V_141;
break;
}
}
}
F_81 ( V_2 , V_136 ) ;
* V_140 = V_50 ;
return 0 ;
V_141:
F_81 ( V_2 , V_146 ) ;
return error ;
}
int
F_124 (
struct V_1 * V_2 ,
union V_75 * * V_213 ,
int * V_140 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int V_48 ;
#ifdef F_93
int error ;
#endif
V_48 = V_2 -> V_63 [ 0 ] ;
V_4 = F_39 ( V_2 , 0 , & V_7 ) ;
#ifdef F_93
error = F_16 ( V_2 , V_4 , 0 , V_7 ) ;
if ( error )
return error ;
#endif
if ( V_48 > F_94 ( V_4 ) || V_48 <= 0 ) {
* V_140 = 0 ;
return 0 ;
}
* V_213 = F_33 ( V_2 , V_48 , V_4 ) ;
* V_140 = 1 ;
return 0 ;
}
