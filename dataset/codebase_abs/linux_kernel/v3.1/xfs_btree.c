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
if ( ( V_7 = V_2 -> V_52 [ V_50 ] ) ) {
if ( ( error = F_25 ( V_10 , V_60 , V_10 -> V_65 ,
F_26 ( V_7 ) , V_10 -> V_66 , 0 , & V_7 ) ) ) {
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
V_67 :
V_68 ;
}
static inline T_7 F_29 ( struct V_1 * V_2 )
{
return ( V_2 -> V_41 & V_42 ) ?
sizeof( V_69 ) : sizeof( V_70 ) ;
}
STATIC T_7
F_30 (
struct V_1 * V_2 ,
int V_71 )
{
return F_28 ( V_2 ) +
( V_71 - 1 ) * V_2 -> V_17 -> V_72 ;
}
STATIC T_7
F_31 (
struct V_1 * V_2 ,
int V_71 )
{
return F_28 ( V_2 ) +
( V_71 - 1 ) * V_2 -> V_17 -> V_73 ;
}
STATIC T_7
F_32 (
struct V_1 * V_2 ,
int V_71 ,
int V_5 )
{
return F_28 ( V_2 ) +
V_2 -> V_17 -> V_18 ( V_2 , V_5 ) * V_2 -> V_17 -> V_73 +
( V_71 - 1 ) * F_29 ( V_2 ) ;
}
STATIC union V_74 *
F_33 (
struct V_1 * V_2 ,
int V_71 ,
struct V_3 * V_4 )
{
return (union V_74 * )
( ( char * ) V_4 + F_30 ( V_2 , V_71 ) ) ;
}
STATIC union V_75 *
F_34 (
struct V_1 * V_2 ,
int V_71 ,
struct V_3 * V_4 )
{
return (union V_75 * )
( ( char * ) V_4 + F_31 ( V_2 , V_71 ) ) ;
}
STATIC union V_47 *
F_35 (
struct V_1 * V_2 ,
int V_71 ,
struct V_3 * V_4 )
{
int V_5 = F_36 ( V_4 ) ;
ASSERT ( V_4 -> V_15 != 0 ) ;
return (union V_47 * )
( ( char * ) V_4 + F_32 ( V_2 , V_71 , V_5 ) ) ;
}
STATIC struct V_3 *
F_37 (
struct V_1 * V_2 )
{
struct V_76 * V_77 ;
V_77 = F_38 ( V_2 -> V_34 . V_55 . V_78 , V_2 -> V_34 . V_55 . V_79 ) ;
return (struct V_3 * ) V_77 -> V_80 ;
}
STATIC struct V_3 *
F_39 (
struct V_1 * V_2 ,
int V_5 ,
struct V_6 * * V_81 )
{
if ( ( V_2 -> V_41 & V_82 ) &&
( V_5 == V_2 -> V_51 - 1 ) ) {
* V_81 = NULL ;
return F_37 ( V_2 ) ;
}
* V_81 = V_2 -> V_52 [ V_5 ] ;
return F_40 ( * V_81 ) ;
}
T_4 *
F_41 (
T_5 * V_10 ,
T_6 * V_60 ,
T_8 V_83 ,
T_9 V_84 )
{
T_4 * V_7 ;
T_10 V_85 ;
ASSERT ( V_83 != V_86 ) ;
V_85 = F_42 ( V_10 , V_83 ) ;
V_7 = F_43 ( V_60 , V_10 -> V_65 , V_85 , V_10 -> V_66 , V_84 ) ;
ASSERT ( ! F_27 ( V_7 ) ) ;
return V_7 ;
}
T_4 *
F_44 (
T_5 * V_10 ,
T_6 * V_60 ,
T_11 V_87 ,
T_1 V_88 ,
T_9 V_84 )
{
T_4 * V_7 ;
T_10 V_85 ;
ASSERT ( V_87 != V_89 ) ;
ASSERT ( V_88 != V_38 ) ;
V_85 = F_45 ( V_10 , V_87 , V_88 ) ;
V_7 = F_43 ( V_60 , V_10 -> V_65 , V_85 , V_10 -> V_66 , V_84 ) ;
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
T_12 V_90 ,
const short * V_91 ,
int V_92 ,
int * V_93 ,
int * V_94 )
{
int V_50 ;
T_12 V_95 ;
ASSERT ( V_90 != 0 ) ;
for ( V_50 = 0 , V_95 = 1LL ; ; V_50 ++ , V_95 <<= 1 ) {
if ( V_95 & V_90 ) {
* V_93 = V_91 [ V_50 ] ;
break;
}
}
for ( V_50 = V_92 - 1 , V_95 = 1LL << V_50 ; ; V_50 -- , V_95 >>= 1 ) {
if ( V_95 & V_90 ) {
* V_94 = V_91 [ V_50 + 1 ] - 1 ;
break;
}
}
}
int
F_50 (
T_5 * V_10 ,
T_6 * V_60 ,
T_8 V_83 ,
T_9 V_84 ,
T_4 * * V_81 ,
int V_96 )
{
T_4 * V_7 ;
T_10 V_85 ;
int error ;
ASSERT ( V_83 != V_86 ) ;
V_85 = F_42 ( V_10 , V_83 ) ;
if ( ( error = F_25 ( V_10 , V_60 , V_10 -> V_65 , V_85 ,
V_10 -> V_66 , V_84 , & V_7 ) ) ) {
return error ;
}
ASSERT ( ! F_27 ( V_7 ) ) ;
if ( V_7 )
F_51 ( V_7 , V_97 , V_96 ) ;
* V_81 = V_7 ;
return 0 ;
}
void
F_52 (
T_5 * V_10 ,
T_8 V_83 ,
T_13 V_98 )
{
T_10 V_85 ;
ASSERT ( V_83 != V_86 ) ;
V_85 = F_42 ( V_10 , V_83 ) ;
F_53 ( V_10 -> V_65 , V_85 , V_10 -> V_66 * V_98 ) ;
}
void
F_54 (
T_5 * V_10 ,
T_11 V_87 ,
T_1 V_88 ,
T_13 V_98 )
{
T_10 V_85 ;
ASSERT ( V_87 != V_89 ) ;
ASSERT ( V_88 != V_38 ) ;
V_85 = F_45 ( V_10 , V_87 , V_88 ) ;
F_53 ( V_10 -> V_65 , V_85 , V_10 -> V_66 * V_98 ) ;
}
STATIC int
F_55 (
struct V_1 * V_2 ,
int V_99 ,
struct V_3 * V_4 )
{
int V_100 = 0 ;
T_2 V_101 = F_6 ( V_4 -> V_19 . V_20 . V_21 ) ;
T_2 V_102 = F_6 ( V_4 -> V_19 . V_20 . V_23 ) ;
if ( ( V_99 & V_103 ) && V_101 != V_22 ) {
F_52 ( V_2 -> V_11 , V_101 , 1 ) ;
V_100 ++ ;
}
if ( ( V_99 & V_104 ) && V_102 != V_22 ) {
F_52 ( V_2 -> V_11 , V_102 , 1 ) ;
V_100 ++ ;
}
return V_100 ;
}
STATIC int
F_56 (
struct V_1 * V_2 ,
int V_99 ,
struct V_3 * V_4 )
{
int V_100 = 0 ;
T_1 V_101 = F_2 ( V_4 -> V_19 . V_37 . V_21 ) ;
T_1 V_102 = F_2 ( V_4 -> V_19 . V_37 . V_23 ) ;
if ( ( V_99 & V_103 ) && V_101 != V_38 ) {
F_54 ( V_2 -> V_11 , V_2 -> V_34 . V_35 . V_87 ,
V_101 , 1 ) ;
V_100 ++ ;
}
if ( ( V_99 & V_104 ) && V_102 != V_38 ) {
F_54 ( V_2 -> V_11 , V_2 -> V_34 . V_35 . V_87 ,
V_102 , 1 ) ;
V_100 ++ ;
}
return V_100 ;
}
STATIC int
F_57 (
struct V_1 * V_2 ,
int V_105 ,
int V_99 )
{
struct V_3 * V_4 ;
if ( ( V_2 -> V_41 & V_82 ) &&
( V_105 == V_2 -> V_51 - 1 ) )
return 0 ;
if ( ( V_2 -> V_64 [ V_105 ] | V_99 ) == V_2 -> V_64 [ V_105 ] )
return 0 ;
V_2 -> V_64 [ V_105 ] |= V_99 ;
V_4 = F_40 ( V_2 -> V_52 [ V_105 ] ) ;
if ( V_2 -> V_41 & V_42 )
return F_55 ( V_2 , V_99 , V_4 ) ;
return F_56 ( V_2 , V_99 , V_4 ) ;
}
STATIC void
F_58 (
T_3 * V_2 ,
int V_105 ,
T_4 * V_7 )
{
struct V_3 * V_55 ;
if ( V_2 -> V_52 [ V_105 ] )
F_22 ( V_2 -> V_53 , V_2 -> V_52 [ V_105 ] ) ;
V_2 -> V_52 [ V_105 ] = V_7 ;
V_2 -> V_64 [ V_105 ] = 0 ;
V_55 = F_40 ( V_7 ) ;
if ( V_2 -> V_41 & V_42 ) {
if ( V_55 -> V_19 . V_20 . V_21 == F_4 ( V_22 ) )
V_2 -> V_64 [ V_105 ] |= V_103 ;
if ( V_55 -> V_19 . V_20 . V_23 == F_4 ( V_22 ) )
V_2 -> V_64 [ V_105 ] |= V_104 ;
} else {
if ( V_55 -> V_19 . V_37 . V_21 == F_14 ( V_38 ) )
V_2 -> V_64 [ V_105 ] |= V_103 ;
if ( V_55 -> V_19 . V_37 . V_23 == F_14 ( V_38 ) )
V_2 -> V_64 [ V_105 ] |= V_104 ;
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
int V_99 )
{
ASSERT ( V_99 == V_106 || V_99 == V_107 ) ;
if ( V_2 -> V_41 & V_42 ) {
if ( V_99 == V_107 )
V_48 -> V_20 = V_4 -> V_19 . V_20 . V_23 ;
else
V_48 -> V_20 = V_4 -> V_19 . V_20 . V_21 ;
} else {
if ( V_99 == V_107 )
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
int V_99 )
{
ASSERT ( V_99 == V_106 || V_99 == V_107 ) ;
if ( V_2 -> V_41 & V_42 ) {
if ( V_99 == V_107 )
V_4 -> V_19 . V_20 . V_23 = V_48 -> V_20 ;
else
V_4 -> V_19 . V_20 . V_21 = V_48 -> V_20 ;
} else {
if ( V_99 == V_107 )
V_4 -> V_19 . V_37 . V_23 = V_48 -> V_37 ;
else
V_4 -> V_19 . V_37 . V_21 = V_48 -> V_37 ;
}
}
STATIC void
F_63 (
struct V_1 * V_2 ,
int V_5 ,
int V_108 ,
struct V_3 * V_59 )
{
V_59 -> V_12 = F_14 ( V_13 [ V_2 -> V_14 ] ) ;
V_59 -> V_15 = F_64 ( V_5 ) ;
V_59 -> V_16 = F_64 ( V_108 ) ;
if ( V_2 -> V_41 & V_42 ) {
V_59 -> V_19 . V_20 . V_21 = F_4 ( V_22 ) ;
V_59 -> V_19 . V_20 . V_23 = F_4 ( V_22 ) ;
} else {
V_59 -> V_19 . V_37 . V_21 = F_14 ( V_38 ) ;
V_59 -> V_19 . V_37 . V_23 = F_14 ( V_38 ) ;
}
}
STATIC int
F_65 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
union V_47 V_48 ;
if ( V_5 > 0 )
return 0 ;
if ( ! ( V_2 -> V_41 & V_109 ) )
return 0 ;
F_61 ( V_2 , V_4 , & V_48 , V_107 ) ;
if ( ! F_59 ( V_2 , & V_48 ) )
return 0 ;
return 1 ;
}
STATIC void
F_66 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
union V_47 * V_48 )
{
if ( V_2 -> V_41 & V_42 )
V_48 -> V_20 = F_4 ( F_67 ( V_2 -> V_11 ,
F_26 ( V_7 ) ) ) ;
else {
V_48 -> V_37 = F_14 ( F_68 ( V_2 -> V_11 ,
F_26 ( V_7 ) ) ) ;
}
}
STATIC T_10
F_69 (
struct V_1 * V_2 ,
union V_47 * V_48 )
{
if ( V_2 -> V_41 & V_42 ) {
ASSERT ( V_48 -> V_20 != F_4 ( V_22 ) ) ;
return F_42 ( V_2 -> V_11 , F_6 ( V_48 -> V_20 ) ) ;
} else {
ASSERT ( V_2 -> V_34 . V_35 . V_87 != V_89 ) ;
ASSERT ( V_48 -> V_37 != F_14 ( V_38 ) ) ;
return F_45 ( V_2 -> V_11 , V_2 -> V_34 . V_35 . V_87 ,
F_2 ( V_48 -> V_37 ) ) ;
}
}
STATIC void
F_70 (
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
switch ( V_2 -> V_14 ) {
case V_110 :
case V_111 :
F_51 ( V_7 , V_97 , V_112 ) ;
break;
case V_113 :
F_51 ( V_7 , V_114 , V_115 ) ;
break;
case V_54 :
F_51 ( V_7 , V_97 , V_116 ) ;
break;
default:
ASSERT ( 0 ) ;
}
}
STATIC int
F_71 (
struct V_1 * V_2 ,
union V_47 * V_48 ,
int V_117 ,
struct V_3 * * V_4 ,
struct V_6 * * V_81 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_10 V_85 ;
ASSERT ( ! ( V_117 & V_118 ) ) ;
V_85 = F_69 ( V_2 , V_48 ) ;
* V_81 = F_43 ( V_2 -> V_53 , V_10 -> V_65 , V_85 ,
V_10 -> V_66 , V_117 ) ;
ASSERT ( ! F_27 ( * V_81 ) ) ;
* V_4 = F_40 ( * V_81 ) ;
return 0 ;
}
STATIC int
F_72 (
struct V_1 * V_2 ,
union V_47 * V_48 ,
int V_5 ,
int V_117 ,
struct V_3 * * V_4 ,
struct V_6 * * V_81 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_10 V_85 ;
int error ;
ASSERT ( ! ( V_117 & V_118 ) ) ;
V_85 = F_69 ( V_2 , V_48 ) ;
error = F_25 ( V_10 , V_2 -> V_53 , V_10 -> V_65 , V_85 ,
V_10 -> V_66 , V_117 , V_81 ) ;
if ( error )
return error ;
ASSERT ( ! F_27 ( * V_81 ) ) ;
F_70 ( V_2 , * V_81 ) ;
* V_4 = F_40 ( * V_81 ) ;
error = F_16 ( V_2 , * V_4 , V_5 , * V_81 ) ;
if ( error )
F_22 ( V_2 -> V_53 , * V_81 ) ;
return error ;
}
STATIC void
F_73 (
struct V_1 * V_2 ,
union V_75 * V_119 ,
union V_75 * V_120 ,
int V_121 )
{
ASSERT ( V_121 >= 0 ) ;
memcpy ( V_119 , V_120 , V_121 * V_2 -> V_17 -> V_73 ) ;
}
STATIC void
F_74 (
struct V_1 * V_2 ,
union V_74 * V_122 ,
union V_74 * V_123 ,
int V_108 )
{
ASSERT ( V_108 >= 0 ) ;
memcpy ( V_122 , V_123 , V_108 * V_2 -> V_17 -> V_72 ) ;
}
STATIC void
F_75 (
struct V_1 * V_2 ,
union V_47 * V_124 ,
union V_47 * V_125 ,
int V_126 )
{
ASSERT ( V_126 >= 0 ) ;
memcpy ( V_124 , V_125 , V_126 * F_29 ( V_2 ) ) ;
}
STATIC void
F_76 (
struct V_1 * V_2 ,
union V_75 * V_127 ,
int V_128 ,
int V_121 )
{
char * V_119 ;
ASSERT ( V_121 >= 0 ) ;
ASSERT ( V_128 == 1 || V_128 == - 1 ) ;
V_119 = ( char * ) V_127 + ( V_128 * V_2 -> V_17 -> V_73 ) ;
memmove ( V_119 , V_127 , V_121 * V_2 -> V_17 -> V_73 ) ;
}
STATIC void
F_77 (
struct V_1 * V_2 ,
union V_74 * V_129 ,
int V_128 ,
int V_108 )
{
char * V_122 ;
ASSERT ( V_108 >= 0 ) ;
ASSERT ( V_128 == 1 || V_128 == - 1 ) ;
V_122 = ( char * ) V_129 + ( V_128 * V_2 -> V_17 -> V_72 ) ;
memmove ( V_122 , V_129 , V_108 * V_2 -> V_17 -> V_72 ) ;
}
STATIC void
F_78 (
struct V_1 * V_2 ,
union V_47 * V_48 ,
int V_128 ,
int V_126 )
{
char * V_124 ;
ASSERT ( V_126 >= 0 ) ;
ASSERT ( V_128 == 1 || V_128 == - 1 ) ;
V_124 = ( char * ) V_48 + ( V_128 * F_29 ( V_2 ) ) ;
memmove ( V_124 , V_48 , V_126 * F_29 ( V_2 ) ) ;
}
STATIC void
F_79 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_93 ,
int V_94 )
{
F_80 ( V_2 , V_130 ) ;
F_81 ( V_2 , V_7 , V_93 , V_94 ) ;
if ( V_7 ) {
F_82 ( V_2 -> V_53 , V_7 ,
F_31 ( V_2 , V_93 ) ,
F_31 ( V_2 , V_94 + 1 ) - 1 ) ;
} else {
F_83 ( V_2 -> V_53 , V_2 -> V_34 . V_55 . V_78 ,
F_84 ( V_2 -> V_34 . V_55 . V_79 ) ) ;
}
F_80 ( V_2 , V_131 ) ;
}
void
F_85 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_93 ,
int V_94 )
{
F_80 ( V_2 , V_130 ) ;
F_81 ( V_2 , V_7 , V_93 , V_94 ) ;
F_82 ( V_2 -> V_53 , V_7 ,
F_30 ( V_2 , V_93 ) ,
F_30 ( V_2 , V_94 + 1 ) - 1 ) ;
F_80 ( V_2 , V_131 ) ;
}
STATIC void
F_86 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_93 ,
int V_94 )
{
F_80 ( V_2 , V_130 ) ;
F_81 ( V_2 , V_7 , V_93 , V_94 ) ;
if ( V_7 ) {
struct V_3 * V_4 = F_40 ( V_7 ) ;
int V_5 = F_36 ( V_4 ) ;
F_82 ( V_2 -> V_53 , V_7 ,
F_32 ( V_2 , V_93 , V_5 ) ,
F_32 ( V_2 , V_94 + 1 , V_5 ) - 1 ) ;
} else {
F_83 ( V_2 -> V_53 , V_2 -> V_34 . V_55 . V_78 ,
F_84 ( V_2 -> V_34 . V_55 . V_79 ) ) ;
}
F_80 ( V_2 , V_131 ) ;
}
void
F_87 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_90 )
{
int V_93 ;
int V_94 ;
static const short V_132 [] = {
F_88 ( struct V_3 , V_12 ) ,
F_88 ( struct V_3 , V_15 ) ,
F_88 ( struct V_3 , V_16 ) ,
F_88 ( struct V_3 , V_19 . V_37 . V_21 ) ,
F_88 ( struct V_3 , V_19 . V_37 . V_23 ) ,
V_68
} ;
static const short V_133 [] = {
F_88 ( struct V_3 , V_12 ) ,
F_88 ( struct V_3 , V_15 ) ,
F_88 ( struct V_3 , V_16 ) ,
F_88 ( struct V_3 , V_19 . V_20 . V_21 ) ,
F_88 ( struct V_3 , V_19 . V_20 . V_23 ) ,
V_67
} ;
F_80 ( V_2 , V_130 ) ;
F_89 ( V_2 , V_7 , V_90 ) ;
if ( V_7 ) {
F_49 ( V_90 ,
( V_2 -> V_41 & V_42 ) ?
V_133 : V_132 ,
V_134 , & V_93 , & V_94 ) ;
F_82 ( V_2 -> V_53 , V_7 , V_93 , V_94 ) ;
} else {
F_83 ( V_2 -> V_53 , V_2 -> V_34 . V_55 . V_78 ,
F_84 ( V_2 -> V_34 . V_55 . V_79 ) ) ;
}
F_80 ( V_2 , V_131 ) ;
}
int
F_90 (
struct V_1 * V_2 ,
int V_5 ,
int * V_135 )
{
struct V_3 * V_4 ;
union V_47 V_48 ;
struct V_6 * V_7 ;
int error ;
int V_105 ;
F_80 ( V_2 , V_130 ) ;
F_91 ( V_2 , V_5 ) ;
ASSERT ( V_5 < V_2 -> V_51 ) ;
F_57 ( V_2 , V_5 , V_104 ) ;
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_136;
#endif
if ( ++ V_2 -> V_63 [ V_5 ] <= F_93 ( V_4 ) )
goto V_137;
F_61 ( V_2 , V_4 , & V_48 , V_107 ) ;
if ( F_59 ( V_2 , & V_48 ) )
goto V_138;
F_94 ( V_2 , V_139 ) ;
for ( V_105 = V_5 + 1 ; V_105 < V_2 -> V_51 ; V_105 ++ ) {
V_4 = F_39 ( V_2 , V_105 , & V_7 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_105 , V_7 ) ;
if ( error )
goto V_136;
#endif
if ( ++ V_2 -> V_63 [ V_105 ] <= F_93 ( V_4 ) )
break;
F_57 ( V_2 , V_105 , V_104 ) ;
}
if ( V_105 == V_2 -> V_51 ) {
if ( V_2 -> V_41 & V_82 )
goto V_138;
ASSERT ( 0 ) ;
error = V_28 ;
goto V_136;
}
ASSERT ( V_105 < V_2 -> V_51 ) ;
for ( V_4 = F_39 ( V_2 , V_105 , & V_7 ) ; V_105 > V_5 ; ) {
union V_47 * V_140 ;
V_140 = F_35 ( V_2 , V_2 -> V_63 [ V_105 ] , V_4 ) ;
error = F_72 ( V_2 , V_140 , -- V_105 ,
0 , & V_4 , & V_7 ) ;
if ( error )
goto V_136;
F_58 ( V_2 , V_105 , V_7 ) ;
V_2 -> V_63 [ V_105 ] = 1 ;
}
V_137:
F_80 ( V_2 , V_131 ) ;
* V_135 = 1 ;
return 0 ;
V_138:
F_80 ( V_2 , V_131 ) ;
* V_135 = 0 ;
return 0 ;
V_136:
F_80 ( V_2 , V_141 ) ;
return error ;
}
int
F_95 (
struct V_1 * V_2 ,
int V_5 ,
int * V_135 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
int error ;
int V_105 ;
union V_47 V_48 ;
F_80 ( V_2 , V_130 ) ;
F_91 ( V_2 , V_5 ) ;
ASSERT ( V_5 < V_2 -> V_51 ) ;
F_57 ( V_2 , V_5 , V_103 ) ;
if ( -- V_2 -> V_63 [ V_5 ] > 0 )
goto V_137;
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_136;
#endif
F_61 ( V_2 , V_4 , & V_48 , V_106 ) ;
if ( F_59 ( V_2 , & V_48 ) )
goto V_138;
F_94 ( V_2 , V_142 ) ;
for ( V_105 = V_5 + 1 ; V_105 < V_2 -> V_51 ; V_105 ++ ) {
if ( -- V_2 -> V_63 [ V_105 ] > 0 )
break;
F_57 ( V_2 , V_105 , V_103 ) ;
}
if ( V_105 == V_2 -> V_51 ) {
if ( V_2 -> V_41 & V_82 )
goto V_138;
ASSERT ( 0 ) ;
error = V_28 ;
goto V_136;
}
ASSERT ( V_105 < V_2 -> V_51 ) ;
for ( V_4 = F_39 ( V_2 , V_105 , & V_7 ) ; V_105 > V_5 ; ) {
union V_47 * V_140 ;
V_140 = F_35 ( V_2 , V_2 -> V_63 [ V_105 ] , V_4 ) ;
error = F_72 ( V_2 , V_140 , -- V_105 ,
0 , & V_4 , & V_7 ) ;
if ( error )
goto V_136;
F_58 ( V_2 , V_105 , V_7 ) ;
V_2 -> V_63 [ V_105 ] = F_93 ( V_4 ) ;
}
V_137:
F_80 ( V_2 , V_131 ) ;
* V_135 = 1 ;
return 0 ;
V_138:
F_80 ( V_2 , V_131 ) ;
* V_135 = 0 ;
return 0 ;
V_136:
F_80 ( V_2 , V_141 ) ;
return error ;
}
STATIC int
F_96 (
struct V_1 * V_2 ,
int V_5 ,
union V_47 * V_143 ,
struct V_3 * * V_144 )
{
struct V_6 * V_7 ;
int error = 0 ;
if ( ( V_2 -> V_41 & V_82 ) &&
( V_5 == V_2 -> V_51 - 1 ) ) {
* V_144 = F_37 ( V_2 ) ;
return 0 ;
}
V_7 = V_2 -> V_52 [ V_5 ] ;
if ( V_7 && F_26 ( V_7 ) == F_69 ( V_2 , V_143 ) ) {
* V_144 = F_40 ( V_7 ) ;
return 0 ;
}
error = F_72 ( V_2 , V_143 , V_5 , 0 , V_144 , & V_7 ) ;
if ( error )
return error ;
F_58 ( V_2 , V_5 , V_7 ) ;
return 0 ;
}
STATIC union V_75 *
F_97 (
struct V_1 * V_2 ,
int V_5 ,
int V_145 ,
struct V_3 * V_4 ,
union V_75 * V_146 )
{
if ( V_5 == 0 ) {
V_2 -> V_17 -> V_147 ( V_146 ,
F_33 ( V_2 , V_145 , V_4 ) ) ;
return V_146 ;
}
return F_34 ( V_2 , V_145 , V_4 ) ;
}
int
F_98 (
struct V_1 * V_2 ,
T_14 V_128 ,
int * V_135 )
{
struct V_3 * V_4 ;
T_12 V_148 ;
int error ;
int V_145 ;
int V_5 ;
union V_47 * V_143 ;
union V_47 V_48 ;
F_80 ( V_2 , V_130 ) ;
F_91 ( V_2 , V_128 ) ;
F_94 ( V_2 , V_149 ) ;
V_4 = NULL ;
V_145 = 0 ;
V_2 -> V_17 -> V_150 ( V_2 , & V_48 ) ;
V_143 = & V_48 ;
for ( V_5 = V_2 -> V_51 - 1 , V_148 = 1 ; V_5 >= 0 ; V_5 -- ) {
error = F_96 ( V_2 , V_5 , V_143 , & V_4 ) ;
if ( error )
goto V_136;
if ( V_148 == 0 ) {
V_145 = 1 ;
} else {
int V_151 ;
int V_152 ;
V_152 = 1 ;
V_151 = F_93 ( V_4 ) ;
if ( ! V_151 ) {
ASSERT ( V_5 == 0 && V_2 -> V_51 == 1 ) ;
V_2 -> V_63 [ 0 ] = V_128 != V_153 ;
F_80 ( V_2 , V_131 ) ;
* V_135 = 0 ;
return 0 ;
}
while ( V_152 <= V_151 ) {
union V_75 V_127 ;
union V_75 * V_146 ;
F_94 ( V_2 , V_154 ) ;
V_145 = ( V_152 + V_151 ) >> 1 ;
V_146 = F_97 ( V_2 , V_5 ,
V_145 , V_4 , & V_127 ) ;
V_148 = V_2 -> V_17 -> V_155 ( V_2 , V_146 ) ;
if ( V_148 < 0 )
V_152 = V_145 + 1 ;
else if ( V_148 > 0 )
V_151 = V_145 - 1 ;
else
break;
}
}
if ( V_5 > 0 ) {
if ( V_148 > 0 && -- V_145 < 1 )
V_145 = 1 ;
V_143 = F_35 ( V_2 , V_145 , V_4 ) ;
#ifdef F_92
error = F_20 ( V_2 , V_143 , 0 , V_5 ) ;
if ( error )
goto V_136;
#endif
V_2 -> V_63 [ V_5 ] = V_145 ;
}
}
if ( V_128 != V_153 && V_148 < 0 ) {
V_145 ++ ;
F_61 ( V_2 , V_4 , & V_48 , V_107 ) ;
if ( V_128 == V_156 &&
V_145 > F_93 ( V_4 ) &&
! F_59 ( V_2 , & V_48 ) ) {
int V_50 ;
V_2 -> V_63 [ 0 ] = V_145 ;
error = F_90 ( V_2 , 0 , & V_50 ) ;
if ( error )
goto V_136;
F_18 ( V_50 == 1 ) ;
F_80 ( V_2 , V_131 ) ;
* V_135 = 1 ;
return 0 ;
}
} else if ( V_128 == V_153 && V_148 > 0 )
V_145 -- ;
V_2 -> V_63 [ 0 ] = V_145 ;
if ( V_145 == 0 || V_145 > F_93 ( V_4 ) )
* V_135 = 0 ;
else if ( V_128 != V_157 || V_148 == 0 )
* V_135 = 1 ;
else
* V_135 = 0 ;
F_80 ( V_2 , V_131 ) ;
return 0 ;
V_136:
F_80 ( V_2 , V_141 ) ;
return error ;
}
STATIC int
F_99 (
struct V_1 * V_2 ,
union V_75 * V_158 ,
int V_5 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_75 * V_146 ;
int V_48 ;
F_80 ( V_2 , V_130 ) ;
F_100 ( V_2 , V_5 , V_158 ) ;
ASSERT ( ! ( V_2 -> V_41 & V_82 ) || V_5 >= 1 ) ;
for ( V_48 = 1 ; V_48 == 1 && V_5 < V_2 -> V_51 ; V_5 ++ ) {
#ifdef F_92
int error ;
#endif
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error ) {
F_80 ( V_2 , V_141 ) ;
return error ;
}
#endif
V_48 = V_2 -> V_63 [ V_5 ] ;
V_146 = F_34 ( V_2 , V_48 , V_4 ) ;
F_73 ( V_2 , V_146 , V_158 , 1 ) ;
F_79 ( V_2 , V_7 , V_48 , V_48 ) ;
}
F_80 ( V_2 , V_131 ) ;
return 0 ;
}
int
F_101 (
struct V_1 * V_2 ,
union V_74 * V_129 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int error ;
int V_48 ;
union V_74 * V_159 ;
F_80 ( V_2 , V_130 ) ;
F_102 ( V_2 , V_129 ) ;
V_4 = F_39 ( V_2 , 0 , & V_7 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , 0 , V_7 ) ;
if ( error )
goto V_136;
#endif
V_48 = V_2 -> V_63 [ 0 ] ;
V_159 = F_33 ( V_2 , V_48 , V_4 ) ;
F_74 ( V_2 , V_159 , V_129 , 1 ) ;
F_85 ( V_2 , V_7 , V_48 , V_48 ) ;
if ( F_65 ( V_2 , V_4 , 0 ) ) {
V_2 -> V_17 -> V_160 ( V_2 , V_4 , V_129 ,
V_48 , V_161 ) ;
}
if ( V_48 == 1 ) {
union V_75 V_127 ;
V_2 -> V_17 -> V_147 ( & V_127 , V_129 ) ;
error = F_99 ( V_2 , & V_127 , 1 ) ;
if ( error )
goto V_136;
}
F_80 ( V_2 , V_131 ) ;
return 0 ;
V_136:
F_80 ( V_2 , V_141 ) ;
return error ;
}
STATIC int
F_103 (
struct V_1 * V_2 ,
int V_5 ,
int * V_135 )
{
union V_75 V_127 ;
struct V_6 * V_162 ;
struct V_3 * V_101 ;
int V_163 ;
struct V_6 * V_164 ;
struct V_3 * V_102 ;
int V_165 ;
union V_47 V_166 ;
union V_75 * V_167 = NULL ;
union V_47 * V_168 = NULL ;
union V_74 * V_169 = NULL ;
int error ;
F_80 ( V_2 , V_130 ) ;
F_91 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_41 & V_82 ) &&
V_5 == V_2 -> V_51 - 1 )
goto V_138;
V_102 = F_39 ( V_2 , V_5 , & V_164 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_102 , V_5 , V_164 ) ;
if ( error )
goto V_136;
#endif
F_61 ( V_2 , V_102 , & V_166 , V_106 ) ;
if ( F_59 ( V_2 , & V_166 ) )
goto V_138;
if ( V_2 -> V_63 [ V_5 ] <= 1 )
goto V_138;
error = F_72 ( V_2 , & V_166 , V_5 , 0 , & V_101 , & V_162 ) ;
if ( error )
goto V_136;
V_163 = F_93 ( V_101 ) ;
if ( V_163 == V_2 -> V_17 -> V_18 ( V_2 , V_5 ) )
goto V_138;
V_165 = F_93 ( V_102 ) ;
V_163 ++ ;
V_165 -- ;
F_94 ( V_2 , V_170 ) ;
F_104 ( V_2 , V_171 , 1 ) ;
if ( V_5 > 0 ) {
union V_75 * V_172 ;
union V_47 * V_173 ;
V_172 = F_34 ( V_2 , V_163 , V_101 ) ;
V_167 = F_34 ( V_2 , 1 , V_102 ) ;
V_173 = F_35 ( V_2 , V_163 , V_101 ) ;
V_168 = F_35 ( V_2 , 1 , V_102 ) ;
#ifdef F_92
error = F_20 ( V_2 , V_168 , 0 , V_5 ) ;
if ( error )
goto V_136;
#endif
F_73 ( V_2 , V_172 , V_167 , 1 ) ;
F_75 ( V_2 , V_173 , V_168 , 1 ) ;
F_79 ( V_2 , V_162 , V_163 , V_163 ) ;
F_86 ( V_2 , V_162 , V_163 , V_163 ) ;
ASSERT ( V_2 -> V_17 -> V_174 ( V_2 ,
F_34 ( V_2 , V_163 - 1 , V_101 ) , V_172 ) ) ;
} else {
union V_74 * V_175 ;
V_175 = F_33 ( V_2 , V_163 , V_101 ) ;
V_169 = F_33 ( V_2 , 1 , V_102 ) ;
F_74 ( V_2 , V_175 , V_169 , 1 ) ;
F_85 ( V_2 , V_162 , V_163 , V_163 ) ;
ASSERT ( V_2 -> V_17 -> V_176 ( V_2 ,
F_33 ( V_2 , V_163 - 1 , V_101 ) , V_175 ) ) ;
}
F_105 ( V_101 , V_163 ) ;
F_87 ( V_2 , V_162 , V_177 ) ;
F_105 ( V_102 , V_165 ) ;
F_87 ( V_2 , V_164 , V_177 ) ;
F_104 ( V_2 , V_171 , V_165 - 1 ) ;
if ( V_5 > 0 ) {
#ifdef F_92
int V_50 ;
for ( V_50 = 0 ; V_50 < V_165 ; V_50 ++ ) {
error = F_20 ( V_2 , V_168 , V_50 + 1 , V_5 ) ;
if ( error )
goto V_136;
}
#endif
F_76 ( V_2 ,
F_34 ( V_2 , 2 , V_102 ) ,
- 1 , V_165 ) ;
F_78 ( V_2 ,
F_35 ( V_2 , 2 , V_102 ) ,
- 1 , V_165 ) ;
F_79 ( V_2 , V_164 , 1 , V_165 ) ;
F_86 ( V_2 , V_164 , 1 , V_165 ) ;
} else {
F_77 ( V_2 ,
F_33 ( V_2 , 2 , V_102 ) ,
- 1 , V_165 ) ;
F_85 ( V_2 , V_164 , 1 , V_165 ) ;
V_2 -> V_17 -> V_147 ( & V_127 ,
F_33 ( V_2 , 1 , V_102 ) ) ;
V_167 = & V_127 ;
}
error = F_99 ( V_2 , V_167 , V_5 + 1 ) ;
if ( error )
goto V_136;
V_2 -> V_63 [ V_5 ] -- ;
F_80 ( V_2 , V_131 ) ;
* V_135 = 1 ;
return 0 ;
V_138:
F_80 ( V_2 , V_131 ) ;
* V_135 = 0 ;
return 0 ;
V_136:
F_80 ( V_2 , V_141 ) ;
return error ;
}
STATIC int
F_106 (
struct V_1 * V_2 ,
int V_5 ,
int * V_135 )
{
union V_75 V_127 ;
struct V_6 * V_162 ;
struct V_3 * V_101 ;
struct V_6 * V_164 ;
struct V_3 * V_102 ;
struct V_1 * V_178 ;
union V_47 V_179 ;
union V_75 * V_167 ;
int V_165 ;
int V_163 ;
int error ;
int V_50 ;
F_80 ( V_2 , V_130 ) ;
F_91 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_41 & V_82 ) &&
( V_5 == V_2 -> V_51 - 1 ) )
goto V_138;
V_101 = F_39 ( V_2 , V_5 , & V_162 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_101 , V_5 , V_162 ) ;
if ( error )
goto V_136;
#endif
F_61 ( V_2 , V_101 , & V_179 , V_107 ) ;
if ( F_59 ( V_2 , & V_179 ) )
goto V_138;
V_163 = F_93 ( V_101 ) ;
if ( V_2 -> V_63 [ V_5 ] >= V_163 )
goto V_138;
error = F_72 ( V_2 , & V_179 , V_5 , 0 , & V_102 , & V_164 ) ;
if ( error )
goto V_136;
V_165 = F_93 ( V_102 ) ;
if ( V_165 == V_2 -> V_17 -> V_18 ( V_2 , V_5 ) )
goto V_138;
F_94 ( V_2 , V_180 ) ;
F_104 ( V_2 , V_171 , V_165 ) ;
if ( V_5 > 0 ) {
union V_75 * V_172 ;
union V_47 * V_173 ;
union V_47 * V_168 ;
V_172 = F_34 ( V_2 , V_163 , V_101 ) ;
V_173 = F_35 ( V_2 , V_163 , V_101 ) ;
V_167 = F_34 ( V_2 , 1 , V_102 ) ;
V_168 = F_35 ( V_2 , 1 , V_102 ) ;
#ifdef F_92
for ( V_50 = V_165 - 1 ; V_50 >= 0 ; V_50 -- ) {
error = F_20 ( V_2 , V_168 , V_50 , V_5 ) ;
if ( error )
goto V_136;
}
#endif
F_76 ( V_2 , V_167 , 1 , V_165 ) ;
F_78 ( V_2 , V_168 , 1 , V_165 ) ;
#ifdef F_92
error = F_20 ( V_2 , V_173 , 0 , V_5 ) ;
if ( error )
goto V_136;
#endif
F_73 ( V_2 , V_167 , V_172 , 1 ) ;
F_75 ( V_2 , V_168 , V_173 , 1 ) ;
F_79 ( V_2 , V_164 , 1 , V_165 + 1 ) ;
F_86 ( V_2 , V_164 , 1 , V_165 + 1 ) ;
ASSERT ( V_2 -> V_17 -> V_174 ( V_2 , V_167 ,
F_34 ( V_2 , 2 , V_102 ) ) ) ;
} else {
union V_74 * V_175 ;
union V_74 * V_169 ;
V_175 = F_33 ( V_2 , V_163 , V_101 ) ;
V_169 = F_33 ( V_2 , 1 , V_102 ) ;
F_77 ( V_2 , V_169 , 1 , V_165 ) ;
F_74 ( V_2 , V_169 , V_175 , 1 ) ;
F_85 ( V_2 , V_164 , 1 , V_165 + 1 ) ;
V_2 -> V_17 -> V_147 ( & V_127 , V_169 ) ;
V_167 = & V_127 ;
ASSERT ( V_2 -> V_17 -> V_176 ( V_2 , V_169 ,
F_33 ( V_2 , 2 , V_102 ) ) ) ;
}
F_105 ( V_101 , -- V_163 ) ;
F_87 ( V_2 , V_162 , V_177 ) ;
F_105 ( V_102 , ++ V_165 ) ;
F_87 ( V_2 , V_164 , V_177 ) ;
error = F_24 ( V_2 , & V_178 ) ;
if ( error )
goto V_136;
V_50 = F_48 ( V_178 , V_5 ) ;
F_107 ( V_50 == 1 , V_136 ) ;
error = F_90 ( V_178 , V_5 , & V_50 ) ;
if ( error )
goto V_181;
error = F_99 ( V_178 , V_167 , V_5 + 1 ) ;
if ( error )
goto V_181;
F_21 ( V_178 , V_182 ) ;
F_80 ( V_2 , V_131 ) ;
* V_135 = 1 ;
return 0 ;
V_138:
F_80 ( V_2 , V_131 ) ;
* V_135 = 0 ;
return 0 ;
V_136:
F_80 ( V_2 , V_141 ) ;
return error ;
V_181:
F_80 ( V_178 , V_141 ) ;
F_21 ( V_178 , V_183 ) ;
return error ;
}
STATIC int
F_108 (
struct V_1 * V_2 ,
int V_5 ,
union V_47 * V_140 ,
union V_75 * V_127 ,
struct V_1 * * V_184 ,
int * V_135 )
{
union V_47 V_166 ;
struct V_6 * V_162 ;
struct V_3 * V_101 ;
union V_47 V_179 ;
struct V_6 * V_164 ;
struct V_3 * V_102 ;
union V_47 V_185 ;
struct V_6 * V_186 ;
struct V_3 * V_187 ;
int V_163 ;
int V_165 ;
int V_188 ;
int error ;
#ifdef F_92
int V_50 ;
#endif
F_80 ( V_2 , V_130 ) ;
F_109 ( V_2 , V_5 , * V_140 , V_127 ) ;
F_94 ( V_2 , V_189 ) ;
V_101 = F_39 ( V_2 , V_5 , & V_162 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_101 , V_5 , V_162 ) ;
if ( error )
goto V_136;
#endif
F_66 ( V_2 , V_162 , & V_166 ) ;
error = V_2 -> V_17 -> V_190 ( V_2 , & V_166 , & V_179 , 1 , V_135 ) ;
if ( error )
goto V_136;
if ( * V_135 == 0 )
goto V_138;
F_94 ( V_2 , V_191 ) ;
error = F_71 ( V_2 , & V_179 , 0 , & V_102 , & V_164 ) ;
if ( error )
goto V_136;
F_63 ( V_2 , F_36 ( V_101 ) , 0 , V_102 ) ;
V_163 = F_93 ( V_101 ) ;
V_165 = V_163 / 2 ;
if ( ( V_163 & 1 ) && V_2 -> V_63 [ V_5 ] <= V_165 + 1 )
V_165 ++ ;
V_188 = ( V_163 - V_165 + 1 ) ;
F_104 ( V_2 , V_171 , V_165 ) ;
if ( V_5 > 0 ) {
union V_75 * V_172 ;
union V_47 * V_173 ;
union V_75 * V_167 ;
union V_47 * V_168 ;
V_172 = F_34 ( V_2 , V_188 , V_101 ) ;
V_173 = F_35 ( V_2 , V_188 , V_101 ) ;
V_167 = F_34 ( V_2 , 1 , V_102 ) ;
V_168 = F_35 ( V_2 , 1 , V_102 ) ;
#ifdef F_92
for ( V_50 = V_188 ; V_50 < V_165 ; V_50 ++ ) {
error = F_20 ( V_2 , V_173 , V_50 , V_5 ) ;
if ( error )
goto V_136;
}
#endif
F_73 ( V_2 , V_167 , V_172 , V_165 ) ;
F_75 ( V_2 , V_168 , V_173 , V_165 ) ;
F_79 ( V_2 , V_164 , 1 , V_165 ) ;
F_86 ( V_2 , V_164 , 1 , V_165 ) ;
F_73 ( V_2 , V_127 , V_167 , 1 ) ;
} else {
union V_74 * V_175 ;
union V_74 * V_169 ;
V_175 = F_33 ( V_2 , V_188 , V_101 ) ;
V_169 = F_33 ( V_2 , 1 , V_102 ) ;
F_74 ( V_2 , V_169 , V_175 , V_165 ) ;
F_85 ( V_2 , V_164 , 1 , V_165 ) ;
V_2 -> V_17 -> V_147 ( V_127 ,
F_33 ( V_2 , 1 , V_102 ) ) ;
}
F_61 ( V_2 , V_101 , & V_185 , V_107 ) ;
F_62 ( V_2 , V_102 , & V_185 , V_107 ) ;
F_62 ( V_2 , V_102 , & V_166 , V_106 ) ;
F_62 ( V_2 , V_101 , & V_179 , V_107 ) ;
V_163 -= V_165 ;
F_105 ( V_101 , V_163 ) ;
F_105 ( V_102 , F_93 ( V_102 ) + V_165 ) ;
F_87 ( V_2 , V_164 , V_192 ) ;
F_87 ( V_2 , V_162 , V_177 | V_107 ) ;
if ( ! F_59 ( V_2 , & V_185 ) ) {
error = F_72 ( V_2 , & V_185 , V_5 ,
0 , & V_187 , & V_186 ) ;
if ( error )
goto V_136;
F_62 ( V_2 , V_187 , & V_179 , V_106 ) ;
F_87 ( V_2 , V_186 , V_106 ) ;
}
if ( V_2 -> V_63 [ V_5 ] > V_163 + 1 ) {
F_58 ( V_2 , V_5 , V_164 ) ;
V_2 -> V_63 [ V_5 ] -= V_163 ;
}
if ( V_5 + 1 < V_2 -> V_51 ) {
error = F_24 ( V_2 , V_184 ) ;
if ( error )
goto V_136;
( * V_184 ) -> V_63 [ V_5 + 1 ] ++ ;
}
* V_140 = V_179 ;
F_80 ( V_2 , V_131 ) ;
* V_135 = 1 ;
return 0 ;
V_138:
F_80 ( V_2 , V_131 ) ;
* V_135 = 0 ;
return 0 ;
V_136:
F_80 ( V_2 , V_141 ) ;
return error ;
}
int
F_110 (
struct V_1 * V_2 ,
int * V_193 ,
int * V_135 )
{
struct V_6 * V_194 ;
struct V_3 * V_4 ;
struct V_3 * V_195 ;
union V_75 * V_196 ;
union V_47 * V_197 ;
union V_75 * V_146 ;
union V_47 * V_143 ;
union V_47 V_198 ;
int V_5 ;
int error ;
#ifdef F_92
int V_50 ;
#endif
F_80 ( V_2 , V_130 ) ;
F_94 ( V_2 , V_199 ) ;
ASSERT ( V_2 -> V_41 & V_82 ) ;
V_5 = V_2 -> V_51 - 1 ;
V_4 = F_37 ( V_2 ) ;
V_143 = F_35 ( V_2 , 1 , V_4 ) ;
error = V_2 -> V_17 -> V_190 ( V_2 , V_143 , & V_198 , 1 , V_135 ) ;
if ( error )
goto V_136;
if ( * V_135 == 0 ) {
F_80 ( V_2 , V_131 ) ;
return 0 ;
}
F_94 ( V_2 , V_191 ) ;
error = F_71 ( V_2 , & V_198 , 0 , & V_195 , & V_194 ) ;
if ( error )
goto V_136;
memcpy ( V_195 , V_4 , F_28 ( V_2 ) ) ;
F_111 ( & V_4 -> V_15 , 1 ) ;
F_105 ( V_4 , 1 ) ;
V_2 -> V_51 ++ ;
V_2 -> V_63 [ V_5 + 1 ] = 1 ;
V_146 = F_34 ( V_2 , 1 , V_4 ) ;
V_196 = F_34 ( V_2 , 1 , V_195 ) ;
F_73 ( V_2 , V_196 , V_146 , F_93 ( V_195 ) ) ;
V_197 = F_35 ( V_2 , 1 , V_195 ) ;
#ifdef F_92
for ( V_50 = 0 ; V_50 < F_3 ( V_195 -> V_16 ) ; V_50 ++ ) {
error = F_20 ( V_2 , V_143 , V_50 , V_5 ) ;
if ( error )
goto V_136;
}
#endif
F_75 ( V_2 , V_197 , V_143 , F_93 ( V_195 ) ) ;
#ifdef F_92
error = F_20 ( V_2 , & V_198 , 0 , V_5 ) ;
if ( error )
goto V_136;
#endif
F_75 ( V_2 , V_143 , & V_198 , 1 ) ;
F_112 ( V_2 -> V_34 . V_55 . V_78 ,
1 - F_93 ( V_195 ) ,
V_2 -> V_34 . V_55 . V_79 ) ;
F_58 ( V_2 , V_5 , V_194 ) ;
F_87 ( V_2 , V_194 , V_192 ) ;
F_79 ( V_2 , V_194 , 1 , F_3 ( V_195 -> V_16 ) ) ;
F_86 ( V_2 , V_194 , 1 , F_3 ( V_195 -> V_16 ) ) ;
* V_193 |=
V_200 | F_84 ( V_2 -> V_34 . V_55 . V_79 ) ;
* V_135 = 1 ;
F_80 ( V_2 , V_131 ) ;
return 0 ;
V_136:
F_80 ( V_2 , V_141 ) ;
return error ;
}
STATIC int
F_113 (
struct V_1 * V_2 ,
int * V_135 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int error ;
struct V_6 * V_162 ;
struct V_3 * V_101 ;
struct V_6 * V_201 ;
struct V_3 * V_59 ;
int V_198 ;
struct V_6 * V_164 ;
struct V_3 * V_102 ;
union V_47 V_179 ;
union V_47 V_166 ;
F_80 ( V_2 , V_130 ) ;
F_94 ( V_2 , V_199 ) ;
V_2 -> V_17 -> V_150 ( V_2 , & V_179 ) ;
error = V_2 -> V_17 -> V_190 ( V_2 , & V_179 , & V_166 , 1 , V_135 ) ;
if ( error )
goto V_136;
if ( * V_135 == 0 )
goto V_138;
F_94 ( V_2 , V_191 ) ;
error = F_71 ( V_2 , & V_166 , 0 , & V_59 , & V_201 ) ;
if ( error )
goto V_136;
V_2 -> V_17 -> V_202 ( V_2 , & V_166 , 1 ) ;
V_4 = F_39 ( V_2 , V_2 -> V_51 - 1 , & V_7 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_2 -> V_51 - 1 , V_7 ) ;
if ( error )
goto V_136;
#endif
F_61 ( V_2 , V_4 , & V_179 , V_107 ) ;
if ( ! F_59 ( V_2 , & V_179 ) ) {
V_162 = V_7 ;
F_66 ( V_2 , V_162 , & V_166 ) ;
V_101 = V_4 ;
error = F_72 ( V_2 , & V_179 ,
V_2 -> V_51 - 1 , 0 , & V_102 , & V_164 ) ;
if ( error )
goto V_136;
V_7 = V_164 ;
V_198 = 1 ;
} else {
V_164 = V_7 ;
F_66 ( V_2 , V_164 , & V_179 ) ;
V_102 = V_4 ;
F_61 ( V_2 , V_102 , & V_166 , V_106 ) ;
error = F_72 ( V_2 , & V_166 ,
V_2 -> V_51 - 1 , 0 , & V_101 , & V_162 ) ;
if ( error )
goto V_136;
V_7 = V_162 ;
V_198 = 2 ;
}
F_63 ( V_2 , V_2 -> V_51 , 2 , V_59 ) ;
F_87 ( V_2 , V_201 , V_192 ) ;
ASSERT ( ! F_59 ( V_2 , & V_166 ) &&
! F_59 ( V_2 , & V_179 ) ) ;
if ( F_36 ( V_101 ) > 0 ) {
F_73 ( V_2 ,
F_34 ( V_2 , 1 , V_59 ) ,
F_34 ( V_2 , 1 , V_101 ) , 1 ) ;
F_73 ( V_2 ,
F_34 ( V_2 , 2 , V_59 ) ,
F_34 ( V_2 , 1 , V_102 ) , 1 ) ;
} else {
V_2 -> V_17 -> V_147 (
F_34 ( V_2 , 1 , V_59 ) ,
F_33 ( V_2 , 1 , V_101 ) ) ;
V_2 -> V_17 -> V_147 (
F_34 ( V_2 , 2 , V_59 ) ,
F_33 ( V_2 , 1 , V_102 ) ) ;
}
F_79 ( V_2 , V_201 , 1 , 2 ) ;
F_75 ( V_2 ,
F_35 ( V_2 , 1 , V_59 ) , & V_166 , 1 ) ;
F_75 ( V_2 ,
F_35 ( V_2 , 2 , V_59 ) , & V_179 , 1 ) ;
F_86 ( V_2 , V_201 , 1 , 2 ) ;
F_58 ( V_2 , V_2 -> V_51 , V_201 ) ;
V_2 -> V_63 [ V_2 -> V_51 ] = V_198 ;
V_2 -> V_51 ++ ;
F_80 ( V_2 , V_131 ) ;
* V_135 = 1 ;
return 0 ;
V_136:
F_80 ( V_2 , V_141 ) ;
return error ;
V_138:
F_80 ( V_2 , V_131 ) ;
* V_135 = 0 ;
return 0 ;
}
STATIC int
F_114 (
struct V_1 * V_2 ,
int V_5 ,
int V_108 ,
int * V_203 ,
int * V_49 ,
union V_47 * V_198 ,
struct V_1 * * V_58 ,
union V_74 * V_204 ,
int * V_135 )
{
union V_75 V_127 ;
int error = 0 ;
if ( ( V_2 -> V_41 & V_82 ) &&
V_5 == V_2 -> V_51 - 1 ) {
struct V_205 * V_78 = V_2 -> V_34 . V_55 . V_78 ;
if ( V_108 < V_2 -> V_17 -> V_206 ( V_2 , V_5 ) ) {
F_112 ( V_78 , 1 , V_2 -> V_34 . V_55 . V_79 ) ;
} else {
int V_193 = 0 ;
error = F_110 ( V_2 , & V_193 , V_135 ) ;
if ( error || * V_135 == 0 )
return error ;
F_83 ( V_2 -> V_53 , V_78 , V_193 ) ;
}
return 0 ;
}
error = F_106 ( V_2 , V_5 , V_135 ) ;
if ( error || * V_135 )
return error ;
error = F_103 ( V_2 , V_5 , V_135 ) ;
if ( error )
return error ;
if ( * V_135 ) {
* V_203 = * V_49 = V_2 -> V_63 [ V_5 ] ;
return 0 ;
}
error = F_108 ( V_2 , V_5 , V_198 , & V_127 , V_58 , V_135 ) ;
if ( error || * V_135 == 0 )
return error ;
* V_49 = V_2 -> V_63 [ V_5 ] ;
V_2 -> V_17 -> V_207 ( & V_127 , V_204 ) ;
return 0 ;
}
STATIC int
F_115 (
struct V_1 * V_2 ,
int V_5 ,
union V_47 * V_140 ,
union V_74 * V_208 ,
struct V_1 * * V_184 ,
int * V_135 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_75 V_127 ;
union V_47 V_198 ;
struct V_1 * V_58 ;
union V_74 V_204 ;
int V_209 ;
int V_48 ;
int V_108 ;
int error ;
#ifdef F_92
int V_50 ;
#endif
F_80 ( V_2 , V_130 ) ;
F_116 ( V_2 , V_5 , * V_140 , V_208 ) ;
V_58 = NULL ;
if ( ! ( V_2 -> V_41 & V_82 ) &&
( V_5 >= V_2 -> V_51 ) ) {
error = F_113 ( V_2 , V_135 ) ;
F_60 ( V_2 , V_140 ) ;
F_80 ( V_2 , V_131 ) ;
return error ;
}
V_48 = V_2 -> V_63 [ V_5 ] ;
if ( V_48 == 0 ) {
F_80 ( V_2 , V_131 ) ;
* V_135 = 0 ;
return 0 ;
}
V_2 -> V_17 -> V_147 ( & V_127 , V_208 ) ;
V_209 = V_48 ;
F_94 ( V_2 , V_210 ) ;
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
V_108 = F_93 ( V_4 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_136;
if ( V_48 <= V_108 ) {
if ( V_5 == 0 ) {
ASSERT ( V_2 -> V_17 -> V_176 ( V_2 , V_208 ,
F_33 ( V_2 , V_48 , V_4 ) ) ) ;
} else {
ASSERT ( V_2 -> V_17 -> V_174 ( V_2 , & V_127 ,
F_34 ( V_2 , V_48 , V_4 ) ) ) ;
}
}
#endif
F_60 ( V_2 , & V_198 ) ;
if ( V_108 == V_2 -> V_17 -> V_18 ( V_2 , V_5 ) ) {
error = F_114 ( V_2 , V_5 , V_108 ,
& V_209 , & V_48 , & V_198 , & V_58 , & V_204 , V_135 ) ;
if ( error || * V_135 == 0 )
goto V_136;
}
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
V_108 = F_93 ( V_4 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
return error ;
#endif
F_104 ( V_2 , V_171 , V_108 - V_48 + 1 ) ;
if ( V_5 > 0 ) {
union V_75 * V_146 ;
union V_47 * V_143 ;
V_146 = F_34 ( V_2 , V_48 , V_4 ) ;
V_143 = F_35 ( V_2 , V_48 , V_4 ) ;
#ifdef F_92
for ( V_50 = V_108 - V_48 ; V_50 >= 0 ; V_50 -- ) {
error = F_20 ( V_2 , V_143 , V_50 , V_5 ) ;
if ( error )
return error ;
}
#endif
F_76 ( V_2 , V_146 , 1 , V_108 - V_48 + 1 ) ;
F_78 ( V_2 , V_143 , 1 , V_108 - V_48 + 1 ) ;
#ifdef F_92
error = F_20 ( V_2 , V_140 , 0 , V_5 ) ;
if ( error )
goto V_136;
#endif
F_73 ( V_2 , V_146 , & V_127 , 1 ) ;
F_75 ( V_2 , V_143 , V_140 , 1 ) ;
V_108 ++ ;
F_105 ( V_4 , V_108 ) ;
F_86 ( V_2 , V_7 , V_48 , V_108 ) ;
F_79 ( V_2 , V_7 , V_48 , V_108 ) ;
#ifdef F_92
if ( V_48 < V_108 ) {
ASSERT ( V_2 -> V_17 -> V_174 ( V_2 , V_146 ,
F_34 ( V_2 , V_48 + 1 , V_4 ) ) ) ;
}
#endif
} else {
union V_74 * V_159 ;
V_159 = F_33 ( V_2 , V_48 , V_4 ) ;
F_77 ( V_2 , V_159 , 1 , V_108 - V_48 + 1 ) ;
F_74 ( V_2 , V_159 , V_208 , 1 ) ;
F_105 ( V_4 , ++ V_108 ) ;
F_85 ( V_2 , V_7 , V_48 , V_108 ) ;
#ifdef F_92
if ( V_48 < V_108 ) {
ASSERT ( V_2 -> V_17 -> V_176 ( V_2 , V_159 ,
F_33 ( V_2 , V_48 + 1 , V_4 ) ) ) ;
}
#endif
}
F_87 ( V_2 , V_7 , V_177 ) ;
if ( V_209 == 1 ) {
error = F_99 ( V_2 , & V_127 , V_5 + 1 ) ;
if ( error )
goto V_136;
}
if ( F_65 ( V_2 , V_4 , V_5 ) ) {
V_2 -> V_17 -> V_160 ( V_2 , V_4 , V_208 ,
V_48 , V_211 ) ;
}
* V_140 = V_198 ;
if ( ! F_59 ( V_2 , & V_198 ) ) {
* V_208 = V_204 ;
* V_184 = V_58 ;
}
F_80 ( V_2 , V_131 ) ;
* V_135 = 1 ;
return 0 ;
V_136:
F_80 ( V_2 , V_141 ) ;
return error ;
}
int
F_117 (
struct V_1 * V_2 ,
int * V_135 )
{
int error ;
int V_50 ;
int V_5 ;
union V_47 V_198 ;
struct V_1 * V_58 ;
struct V_1 * V_212 ;
union V_74 V_129 ;
V_5 = 0 ;
V_58 = NULL ;
V_212 = V_2 ;
F_60 ( V_2 , & V_198 ) ;
V_2 -> V_17 -> V_213 ( V_2 , & V_129 ) ;
do {
error = F_115 ( V_212 , V_5 , & V_198 , & V_129 , & V_58 , & V_50 ) ;
if ( error ) {
if ( V_212 != V_2 )
F_21 ( V_212 , V_183 ) ;
goto V_136;
}
F_107 ( V_50 == 1 , V_136 ) ;
V_5 ++ ;
if ( V_212 != V_2 &&
( V_58 || F_59 ( V_2 , & V_198 ) ) ) {
if ( V_2 -> V_17 -> V_214 )
V_2 -> V_17 -> V_214 ( V_212 , V_2 ) ;
V_2 -> V_51 = V_212 -> V_51 ;
F_21 ( V_212 , V_182 ) ;
}
if ( V_58 ) {
V_212 = V_58 ;
V_58 = NULL ;
}
} while ( ! F_59 ( V_2 , & V_198 ) );
F_80 ( V_2 , V_131 ) ;
* V_135 = V_50 ;
return 0 ;
V_136:
F_80 ( V_2 , V_141 ) ;
return error ;
}
STATIC int
F_118 (
struct V_1 * V_2 )
{
int V_79 = V_2 -> V_34 . V_55 . V_79 ;
struct V_205 * V_78 = V_2 -> V_34 . V_55 . V_78 ;
struct V_76 * V_77 = F_38 ( V_78 , V_79 ) ;
struct V_3 * V_4 ;
struct V_3 * V_195 ;
union V_75 * V_146 ;
union V_75 * V_196 ;
union V_47 * V_143 ;
union V_47 * V_197 ;
struct V_6 * V_194 ;
int V_5 ;
int V_49 ;
int V_108 ;
#ifdef F_92
union V_47 V_48 ;
int V_50 ;
#endif
F_80 ( V_2 , V_130 ) ;
ASSERT ( V_2 -> V_41 & V_82 ) ;
ASSERT ( V_2 -> V_51 > 1 ) ;
V_5 = V_2 -> V_51 - 1 ;
if ( V_5 == 1 )
goto V_138;
V_4 = F_37 ( V_2 ) ;
if ( F_93 ( V_4 ) != 1 )
goto V_138;
V_195 = F_39 ( V_2 , V_5 - 1 , & V_194 ) ;
V_108 = F_93 ( V_195 ) ;
if ( V_108 > V_2 -> V_17 -> V_206 ( V_2 , V_5 ) )
goto V_138;
F_94 ( V_2 , V_215 ) ;
#ifdef F_92
F_61 ( V_2 , V_4 , & V_48 , V_106 ) ;
ASSERT ( F_59 ( V_2 , & V_48 ) ) ;
F_61 ( V_2 , V_4 , & V_48 , V_107 ) ;
ASSERT ( F_59 ( V_2 , & V_48 ) ) ;
#endif
V_49 = V_108 - V_2 -> V_17 -> V_18 ( V_2 , V_5 ) ;
if ( V_49 ) {
F_112 ( V_2 -> V_34 . V_55 . V_78 , V_49 ,
V_2 -> V_34 . V_55 . V_79 ) ;
V_4 = V_77 -> V_80 ;
}
F_111 ( & V_4 -> V_16 , V_49 ) ;
ASSERT ( V_4 -> V_16 == V_195 -> V_16 ) ;
V_146 = F_34 ( V_2 , 1 , V_4 ) ;
V_196 = F_34 ( V_2 , 1 , V_195 ) ;
F_73 ( V_2 , V_146 , V_196 , V_108 ) ;
V_143 = F_35 ( V_2 , 1 , V_4 ) ;
V_197 = F_35 ( V_2 , 1 , V_195 ) ;
#ifdef F_92
for ( V_50 = 0 ; V_50 < V_108 ; V_50 ++ ) {
int error ;
error = F_20 ( V_2 , V_197 , V_50 , V_5 - 1 ) ;
if ( error ) {
F_80 ( V_2 , V_141 ) ;
return error ;
}
}
#endif
F_75 ( V_2 , V_143 , V_197 , V_108 ) ;
V_2 -> V_17 -> V_216 ( V_2 , V_194 ) ;
F_94 ( V_2 , free ) ;
V_2 -> V_52 [ V_5 - 1 ] = NULL ;
F_111 ( & V_4 -> V_15 , - 1 ) ;
F_83 ( V_2 -> V_53 , V_78 ,
V_200 | F_84 ( V_2 -> V_34 . V_55 . V_79 ) ) ;
V_2 -> V_51 -- ;
V_138:
F_80 ( V_2 , V_131 ) ;
return 0 ;
}
STATIC int
F_119 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_5 ,
union V_47 * V_199 )
{
int error ;
F_80 ( V_2 , V_130 ) ;
F_94 ( V_2 , V_215 ) ;
V_2 -> V_17 -> V_202 ( V_2 , V_199 , - 1 ) ;
error = V_2 -> V_17 -> V_216 ( V_2 , V_7 ) ;
if ( error ) {
F_80 ( V_2 , V_141 ) ;
return error ;
}
F_94 ( V_2 , free ) ;
V_2 -> V_52 [ V_5 ] = NULL ;
V_2 -> V_64 [ V_5 ] = 0 ;
V_2 -> V_51 -- ;
F_80 ( V_2 , V_131 ) ;
return 0 ;
}
STATIC int
F_120 (
struct V_1 * V_2 ,
int V_5 ,
int * V_135 )
{
int error ;
int V_50 ;
if ( V_5 > 0 ) {
error = F_95 ( V_2 , V_5 , & V_50 ) ;
if ( error )
return error ;
}
F_80 ( V_2 , V_131 ) ;
* V_135 = 1 ;
return 0 ;
}
STATIC int
F_121 (
struct V_1 * V_2 ,
int V_5 ,
int * V_135 )
{
struct V_3 * V_4 ;
union V_47 V_217 ;
struct V_6 * V_7 ;
int error ;
int V_50 ;
union V_75 V_127 ;
union V_75 * V_158 = & V_127 ;
union V_47 V_166 ;
struct V_6 * V_162 ;
struct V_3 * V_101 ;
int V_163 = 0 ;
int V_48 ;
union V_47 V_179 ;
struct V_6 * V_164 ;
struct V_3 * V_102 ;
struct V_3 * V_187 ;
struct V_6 * V_186 ;
int V_165 = 0 ;
struct V_1 * V_178 ;
int V_108 ;
F_80 ( V_2 , V_130 ) ;
F_91 ( V_2 , V_5 ) ;
V_178 = NULL ;
V_48 = V_2 -> V_63 [ V_5 ] ;
if ( V_48 == 0 ) {
F_80 ( V_2 , V_131 ) ;
* V_135 = 0 ;
return 0 ;
}
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
V_108 = F_93 ( V_4 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_136;
#endif
if ( V_48 > V_108 ) {
F_80 ( V_2 , V_131 ) ;
* V_135 = 0 ;
return 0 ;
}
F_94 ( V_2 , V_218 ) ;
F_104 ( V_2 , V_171 , V_108 - V_48 ) ;
if ( V_5 > 0 ) {
union V_75 * V_172 ;
union V_47 * V_173 ;
V_172 = F_34 ( V_2 , V_48 + 1 , V_4 ) ;
V_173 = F_35 ( V_2 , V_48 + 1 , V_4 ) ;
#ifdef F_92
for ( V_50 = 0 ; V_50 < V_108 - V_48 ; V_50 ++ ) {
error = F_20 ( V_2 , V_173 , V_50 , V_5 ) ;
if ( error )
goto V_136;
}
#endif
if ( V_48 < V_108 ) {
F_76 ( V_2 , V_172 , - 1 , V_108 - V_48 ) ;
F_78 ( V_2 , V_173 , - 1 , V_108 - V_48 ) ;
F_79 ( V_2 , V_7 , V_48 , V_108 - 1 ) ;
F_86 ( V_2 , V_7 , V_48 , V_108 - 1 ) ;
}
if ( V_48 == 1 )
V_158 = F_34 ( V_2 , 1 , V_4 ) ;
} else {
if ( V_48 < V_108 ) {
F_77 ( V_2 ,
F_33 ( V_2 , V_48 + 1 , V_4 ) ,
- 1 , V_108 - V_48 ) ;
F_85 ( V_2 , V_7 , V_48 , V_108 - 1 ) ;
}
if ( V_48 == 1 ) {
V_2 -> V_17 -> V_147 ( & V_127 ,
F_33 ( V_2 , 1 , V_4 ) ) ;
V_158 = & V_127 ;
}
}
F_105 ( V_4 , -- V_108 ) ;
F_87 ( V_2 , V_7 , V_177 ) ;
if ( F_65 ( V_2 , V_4 , V_5 ) ) {
V_2 -> V_17 -> V_160 ( V_2 , V_4 , NULL ,
V_48 , V_219 ) ;
}
if ( V_5 == V_2 -> V_51 - 1 ) {
if ( V_2 -> V_41 & V_82 ) {
F_112 ( V_2 -> V_34 . V_55 . V_78 , - 1 ,
V_2 -> V_34 . V_55 . V_79 ) ;
error = F_118 ( V_2 ) ;
if ( error )
goto V_136;
error = F_120 ( V_2 , V_5 , V_135 ) ;
if ( error )
goto V_136;
* V_135 = 1 ;
return 0 ;
}
if ( V_108 == 1 && V_5 > 0 ) {
union V_47 * V_143 ;
V_143 = F_35 ( V_2 , 1 , V_4 ) ;
error = F_119 ( V_2 , V_7 , V_5 , V_143 ) ;
if ( error )
goto V_136;
} else if ( V_5 > 0 ) {
error = F_120 ( V_2 , V_5 , V_135 ) ;
if ( error )
goto V_136;
}
* V_135 = 1 ;
return 0 ;
}
if ( V_48 == 1 ) {
error = F_99 ( V_2 , V_158 , V_5 + 1 ) ;
if ( error )
goto V_136;
}
if ( V_108 >= V_2 -> V_17 -> V_220 ( V_2 , V_5 ) ) {
error = F_120 ( V_2 , V_5 , V_135 ) ;
if ( error )
goto V_136;
return 0 ;
}
F_61 ( V_2 , V_4 , & V_179 , V_107 ) ;
F_61 ( V_2 , V_4 , & V_166 , V_106 ) ;
if ( V_2 -> V_41 & V_82 ) {
if ( F_59 ( V_2 , & V_179 ) &&
F_59 ( V_2 , & V_166 ) &&
V_5 == V_2 -> V_51 - 2 ) {
error = F_118 ( V_2 ) ;
if ( ! error )
error = F_120 ( V_2 , V_5 , V_135 ) ;
if ( error )
goto V_136;
return 0 ;
}
}
ASSERT ( ! F_59 ( V_2 , & V_179 ) ||
! F_59 ( V_2 , & V_166 ) ) ;
error = F_24 ( V_2 , & V_178 ) ;
if ( error )
goto V_136;
if ( ! F_59 ( V_2 , & V_179 ) ) {
V_50 = F_48 ( V_178 , V_5 ) ;
F_107 ( V_50 == 1 , V_136 ) ;
error = F_90 ( V_178 , V_5 , & V_50 ) ;
if ( error )
goto V_136;
F_107 ( V_50 == 1 , V_136 ) ;
V_50 = F_48 ( V_178 , V_5 ) ;
F_107 ( V_50 == 1 , V_136 ) ;
V_102 = F_39 ( V_178 , V_5 , & V_164 ) ;
#ifdef F_92
error = F_16 ( V_178 , V_102 , V_5 , V_164 ) ;
if ( error )
goto V_136;
#endif
F_61 ( V_178 , V_102 , & V_217 , V_106 ) ;
if ( F_93 ( V_102 ) - 1 >=
V_2 -> V_17 -> V_220 ( V_178 , V_5 ) ) {
error = F_103 ( V_178 , V_5 , & V_50 ) ;
if ( error )
goto V_136;
if ( V_50 ) {
ASSERT ( F_93 ( V_4 ) >=
V_2 -> V_17 -> V_220 ( V_178 , V_5 ) ) ;
F_21 ( V_178 , V_182 ) ;
V_178 = NULL ;
error = F_120 ( V_2 , V_5 , V_135 ) ;
if ( error )
goto V_136;
return 0 ;
}
}
V_165 = F_93 ( V_102 ) ;
if ( ! F_59 ( V_2 , & V_166 ) ) {
V_50 = F_47 ( V_178 , V_5 ) ;
F_107 ( V_50 == 1 , V_136 ) ;
error = F_95 ( V_178 , V_5 , & V_50 ) ;
if ( error )
goto V_136;
F_107 ( V_50 == 1 , V_136 ) ;
}
}
if ( ! F_59 ( V_2 , & V_166 ) ) {
V_50 = F_47 ( V_178 , V_5 ) ;
F_107 ( V_50 == 1 , V_136 ) ;
error = F_95 ( V_178 , V_5 , & V_50 ) ;
if ( error )
goto V_136;
V_50 = F_47 ( V_178 , V_5 ) ;
F_107 ( V_50 == 1 , V_136 ) ;
V_101 = F_39 ( V_178 , V_5 , & V_162 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_101 , V_5 , V_162 ) ;
if ( error )
goto V_136;
#endif
F_61 ( V_178 , V_101 , & V_217 , V_107 ) ;
if ( F_93 ( V_101 ) - 1 >=
V_2 -> V_17 -> V_220 ( V_178 , V_5 ) ) {
error = F_106 ( V_178 , V_5 , & V_50 ) ;
if ( error )
goto V_136;
if ( V_50 ) {
ASSERT ( F_93 ( V_4 ) >=
V_2 -> V_17 -> V_220 ( V_178 , V_5 ) ) ;
F_21 ( V_178 , V_182 ) ;
V_178 = NULL ;
if ( V_5 == 0 )
V_2 -> V_63 [ 0 ] ++ ;
F_80 ( V_2 , V_131 ) ;
* V_135 = 1 ;
return 0 ;
}
}
V_163 = F_93 ( V_101 ) ;
}
F_21 ( V_178 , V_182 ) ;
V_178 = NULL ;
ASSERT ( ! F_59 ( V_2 , & V_217 ) ) ;
if ( ! F_59 ( V_2 , & V_166 ) &&
V_163 + F_93 ( V_4 ) <=
V_2 -> V_17 -> V_18 ( V_2 , V_5 ) ) {
V_179 = V_217 ;
V_102 = V_4 ;
V_164 = V_7 ;
error = F_72 ( V_2 , & V_166 , V_5 ,
0 , & V_101 , & V_162 ) ;
if ( error )
goto V_136;
} else if ( ! F_59 ( V_2 , & V_179 ) &&
V_165 + F_93 ( V_4 ) <=
V_2 -> V_17 -> V_18 ( V_2 , V_5 ) ) {
V_166 = V_217 ;
V_101 = V_4 ;
V_162 = V_7 ;
error = F_72 ( V_2 , & V_179 , V_5 ,
0 , & V_102 , & V_164 ) ;
if ( error )
goto V_136;
} else {
error = F_120 ( V_2 , V_5 , V_135 ) ;
if ( error )
goto V_136;
return 0 ;
}
V_165 = F_93 ( V_102 ) ;
V_163 = F_93 ( V_101 ) ;
F_104 ( V_2 , V_171 , V_165 ) ;
if ( V_5 > 0 ) {
union V_75 * V_172 ;
union V_47 * V_173 ;
union V_75 * V_167 ;
union V_47 * V_168 ;
V_172 = F_34 ( V_2 , V_163 + 1 , V_101 ) ;
V_173 = F_35 ( V_2 , V_163 + 1 , V_101 ) ;
V_167 = F_34 ( V_2 , 1 , V_102 ) ;
V_168 = F_35 ( V_2 , 1 , V_102 ) ;
#ifdef F_92
for ( V_50 = 1 ; V_50 < V_165 ; V_50 ++ ) {
error = F_20 ( V_2 , V_168 , V_50 , V_5 ) ;
if ( error )
goto V_136;
}
#endif
F_73 ( V_2 , V_172 , V_167 , V_165 ) ;
F_75 ( V_2 , V_173 , V_168 , V_165 ) ;
F_79 ( V_2 , V_162 , V_163 + 1 , V_163 + V_165 ) ;
F_86 ( V_2 , V_162 , V_163 + 1 , V_163 + V_165 ) ;
} else {
union V_74 * V_175 ;
union V_74 * V_169 ;
V_175 = F_33 ( V_2 , V_163 + 1 , V_101 ) ;
V_169 = F_33 ( V_2 , 1 , V_102 ) ;
F_74 ( V_2 , V_175 , V_169 , V_165 ) ;
F_85 ( V_2 , V_162 , V_163 + 1 , V_163 + V_165 ) ;
}
F_94 ( V_2 , V_221 ) ;
F_105 ( V_101 , V_163 + V_165 ) ;
F_61 ( V_2 , V_102 , & V_217 , V_107 ) ,
F_62 ( V_2 , V_101 , & V_217 , V_107 ) ;
F_87 ( V_2 , V_162 , V_177 | V_107 ) ;
F_61 ( V_2 , V_101 , & V_217 , V_107 ) ;
if ( ! F_59 ( V_2 , & V_217 ) ) {
error = F_72 ( V_2 , & V_217 , V_5 ,
0 , & V_187 , & V_186 ) ;
if ( error )
goto V_136;
F_62 ( V_2 , V_187 , & V_166 , V_106 ) ;
F_87 ( V_2 , V_186 , V_106 ) ;
}
error = V_2 -> V_17 -> V_216 ( V_2 , V_164 ) ;
if ( error )
goto V_136;
F_94 ( V_2 , free ) ;
if ( V_7 != V_162 ) {
V_2 -> V_52 [ V_5 ] = V_162 ;
V_2 -> V_63 [ V_5 ] += V_163 ;
V_2 -> V_64 [ V_5 ] = 0 ;
}
else if ( ( V_2 -> V_41 & V_82 ) ||
( V_5 + 1 < V_2 -> V_51 ) ) {
error = F_90 ( V_2 , V_5 + 1 , & V_50 ) ;
if ( error )
goto V_136;
}
if ( V_5 > 0 )
V_2 -> V_63 [ V_5 ] -- ;
F_80 ( V_2 , V_131 ) ;
* V_135 = 2 ;
return 0 ;
V_136:
F_80 ( V_2 , V_141 ) ;
if ( V_178 )
F_21 ( V_178 , V_183 ) ;
return error ;
}
int
F_122 (
struct V_1 * V_2 ,
int * V_135 )
{
int error ;
int V_5 ;
int V_50 ;
F_80 ( V_2 , V_130 ) ;
for ( V_5 = 0 , V_50 = 2 ; V_50 == 2 ; V_5 ++ ) {
error = F_121 ( V_2 , V_5 , & V_50 ) ;
if ( error )
goto V_136;
}
if ( V_50 == 0 ) {
for ( V_5 = 1 ; V_5 < V_2 -> V_51 ; V_5 ++ ) {
if ( V_2 -> V_63 [ V_5 ] == 0 ) {
error = F_95 ( V_2 , V_5 , & V_50 ) ;
if ( error )
goto V_136;
break;
}
}
}
F_80 ( V_2 , V_131 ) ;
* V_135 = V_50 ;
return 0 ;
V_136:
F_80 ( V_2 , V_141 ) ;
return error ;
}
int
F_123 (
struct V_1 * V_2 ,
union V_74 * * V_208 ,
int * V_135 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int V_48 ;
#ifdef F_92
int error ;
#endif
V_48 = V_2 -> V_63 [ 0 ] ;
V_4 = F_39 ( V_2 , 0 , & V_7 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , 0 , V_7 ) ;
if ( error )
return error ;
#endif
if ( V_48 > F_93 ( V_4 ) || V_48 <= 0 ) {
* V_135 = 0 ;
return 0 ;
}
* V_208 = F_33 ( V_2 , V_48 , V_4 ) ;
* V_135 = 1 ;
return 0 ;
}
