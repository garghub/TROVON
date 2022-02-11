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
F_51 ( V_7 , V_96 ) ;
* V_81 = V_7 ;
return 0 ;
}
void
F_52 (
T_5 * V_10 ,
T_8 V_83 ,
T_13 V_97 )
{
T_10 V_85 ;
ASSERT ( V_83 != V_86 ) ;
V_85 = F_42 ( V_10 , V_83 ) ;
F_53 ( V_10 -> V_65 , V_85 , V_10 -> V_66 * V_97 ) ;
}
void
F_54 (
T_5 * V_10 ,
T_11 V_87 ,
T_1 V_88 ,
T_13 V_97 )
{
T_10 V_85 ;
ASSERT ( V_87 != V_89 ) ;
ASSERT ( V_88 != V_38 ) ;
V_85 = F_45 ( V_10 , V_87 , V_88 ) ;
F_53 ( V_10 -> V_65 , V_85 , V_10 -> V_66 * V_97 ) ;
}
STATIC int
F_55 (
struct V_1 * V_2 ,
int V_98 ,
struct V_3 * V_4 )
{
int V_99 = 0 ;
T_2 V_100 = F_6 ( V_4 -> V_19 . V_20 . V_21 ) ;
T_2 V_101 = F_6 ( V_4 -> V_19 . V_20 . V_23 ) ;
if ( ( V_98 & V_102 ) && V_100 != V_22 ) {
F_52 ( V_2 -> V_11 , V_100 , 1 ) ;
V_99 ++ ;
}
if ( ( V_98 & V_103 ) && V_101 != V_22 ) {
F_52 ( V_2 -> V_11 , V_101 , 1 ) ;
V_99 ++ ;
}
return V_99 ;
}
STATIC int
F_56 (
struct V_1 * V_2 ,
int V_98 ,
struct V_3 * V_4 )
{
int V_99 = 0 ;
T_1 V_100 = F_2 ( V_4 -> V_19 . V_37 . V_21 ) ;
T_1 V_101 = F_2 ( V_4 -> V_19 . V_37 . V_23 ) ;
if ( ( V_98 & V_102 ) && V_100 != V_38 ) {
F_54 ( V_2 -> V_11 , V_2 -> V_34 . V_35 . V_87 ,
V_100 , 1 ) ;
V_99 ++ ;
}
if ( ( V_98 & V_103 ) && V_101 != V_38 ) {
F_54 ( V_2 -> V_11 , V_2 -> V_34 . V_35 . V_87 ,
V_101 , 1 ) ;
V_99 ++ ;
}
return V_99 ;
}
STATIC int
F_57 (
struct V_1 * V_2 ,
int V_104 ,
int V_98 )
{
struct V_3 * V_4 ;
if ( ( V_2 -> V_41 & V_82 ) &&
( V_104 == V_2 -> V_51 - 1 ) )
return 0 ;
if ( ( V_2 -> V_64 [ V_104 ] | V_98 ) == V_2 -> V_64 [ V_104 ] )
return 0 ;
V_2 -> V_64 [ V_104 ] |= V_98 ;
V_4 = F_40 ( V_2 -> V_52 [ V_104 ] ) ;
if ( V_2 -> V_41 & V_42 )
return F_55 ( V_2 , V_98 , V_4 ) ;
return F_56 ( V_2 , V_98 , V_4 ) ;
}
STATIC void
F_58 (
T_3 * V_2 ,
int V_104 ,
T_4 * V_7 )
{
struct V_3 * V_55 ;
if ( V_2 -> V_52 [ V_104 ] )
F_22 ( V_2 -> V_53 , V_2 -> V_52 [ V_104 ] ) ;
V_2 -> V_52 [ V_104 ] = V_7 ;
V_2 -> V_64 [ V_104 ] = 0 ;
V_55 = F_40 ( V_7 ) ;
if ( V_2 -> V_41 & V_42 ) {
if ( V_55 -> V_19 . V_20 . V_21 == F_4 ( V_22 ) )
V_2 -> V_64 [ V_104 ] |= V_102 ;
if ( V_55 -> V_19 . V_20 . V_23 == F_4 ( V_22 ) )
V_2 -> V_64 [ V_104 ] |= V_103 ;
} else {
if ( V_55 -> V_19 . V_37 . V_21 == F_14 ( V_38 ) )
V_2 -> V_64 [ V_104 ] |= V_102 ;
if ( V_55 -> V_19 . V_37 . V_23 == F_14 ( V_38 ) )
V_2 -> V_64 [ V_104 ] |= V_103 ;
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
int V_98 )
{
ASSERT ( V_98 == V_105 || V_98 == V_106 ) ;
if ( V_2 -> V_41 & V_42 ) {
if ( V_98 == V_106 )
V_48 -> V_20 = V_4 -> V_19 . V_20 . V_23 ;
else
V_48 -> V_20 = V_4 -> V_19 . V_20 . V_21 ;
} else {
if ( V_98 == V_106 )
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
int V_98 )
{
ASSERT ( V_98 == V_105 || V_98 == V_106 ) ;
if ( V_2 -> V_41 & V_42 ) {
if ( V_98 == V_106 )
V_4 -> V_19 . V_20 . V_23 = V_48 -> V_20 ;
else
V_4 -> V_19 . V_20 . V_21 = V_48 -> V_20 ;
} else {
if ( V_98 == V_106 )
V_4 -> V_19 . V_37 . V_23 = V_48 -> V_37 ;
else
V_4 -> V_19 . V_37 . V_21 = V_48 -> V_37 ;
}
}
STATIC void
F_63 (
struct V_1 * V_2 ,
int V_5 ,
int V_107 ,
struct V_3 * V_59 )
{
V_59 -> V_12 = F_14 ( V_13 [ V_2 -> V_14 ] ) ;
V_59 -> V_15 = F_64 ( V_5 ) ;
V_59 -> V_16 = F_64 ( V_107 ) ;
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
if ( ! ( V_2 -> V_41 & V_108 ) )
return 0 ;
F_61 ( V_2 , V_4 , & V_48 , V_106 ) ;
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
case V_109 :
case V_110 :
F_51 ( V_7 , V_111 ) ;
break;
case V_112 :
F_51 ( V_7 , V_113 ) ;
break;
case V_54 :
F_51 ( V_7 , V_114 ) ;
break;
default:
ASSERT ( 0 ) ;
}
}
STATIC int
F_71 (
struct V_1 * V_2 ,
union V_47 * V_48 ,
int V_115 ,
struct V_3 * * V_4 ,
struct V_6 * * V_81 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_10 V_85 ;
ASSERT ( ! ( V_115 & V_116 ) ) ;
V_85 = F_69 ( V_2 , V_48 ) ;
* V_81 = F_43 ( V_2 -> V_53 , V_10 -> V_65 , V_85 ,
V_10 -> V_66 , V_115 ) ;
if ( ! * V_81 )
return V_117 ;
* V_4 = F_40 ( * V_81 ) ;
return 0 ;
}
STATIC int
F_72 (
struct V_1 * V_2 ,
union V_47 * V_48 ,
int V_5 ,
int V_115 ,
struct V_3 * * V_4 ,
struct V_6 * * V_81 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_10 V_85 ;
int error ;
ASSERT ( ! ( V_115 & V_116 ) ) ;
V_85 = F_69 ( V_2 , V_48 ) ;
error = F_25 ( V_10 , V_2 -> V_53 , V_10 -> V_65 , V_85 ,
V_10 -> V_66 , V_115 , V_81 ) ;
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
union V_75 * V_118 ,
union V_75 * V_119 ,
int V_120 )
{
ASSERT ( V_120 >= 0 ) ;
memcpy ( V_118 , V_119 , V_120 * V_2 -> V_17 -> V_73 ) ;
}
STATIC void
F_74 (
struct V_1 * V_2 ,
union V_74 * V_121 ,
union V_74 * V_122 ,
int V_107 )
{
ASSERT ( V_107 >= 0 ) ;
memcpy ( V_121 , V_122 , V_107 * V_2 -> V_17 -> V_72 ) ;
}
STATIC void
F_75 (
struct V_1 * V_2 ,
union V_47 * V_123 ,
union V_47 * V_124 ,
int V_125 )
{
ASSERT ( V_125 >= 0 ) ;
memcpy ( V_123 , V_124 , V_125 * F_29 ( V_2 ) ) ;
}
STATIC void
F_76 (
struct V_1 * V_2 ,
union V_75 * V_126 ,
int V_127 ,
int V_120 )
{
char * V_118 ;
ASSERT ( V_120 >= 0 ) ;
ASSERT ( V_127 == 1 || V_127 == - 1 ) ;
V_118 = ( char * ) V_126 + ( V_127 * V_2 -> V_17 -> V_73 ) ;
memmove ( V_118 , V_126 , V_120 * V_2 -> V_17 -> V_73 ) ;
}
STATIC void
F_77 (
struct V_1 * V_2 ,
union V_74 * V_128 ,
int V_127 ,
int V_107 )
{
char * V_121 ;
ASSERT ( V_107 >= 0 ) ;
ASSERT ( V_127 == 1 || V_127 == - 1 ) ;
V_121 = ( char * ) V_128 + ( V_127 * V_2 -> V_17 -> V_72 ) ;
memmove ( V_121 , V_128 , V_107 * V_2 -> V_17 -> V_72 ) ;
}
STATIC void
F_78 (
struct V_1 * V_2 ,
union V_47 * V_48 ,
int V_127 ,
int V_125 )
{
char * V_123 ;
ASSERT ( V_125 >= 0 ) ;
ASSERT ( V_127 == 1 || V_127 == - 1 ) ;
V_123 = ( char * ) V_48 + ( V_127 * F_29 ( V_2 ) ) ;
memmove ( V_123 , V_48 , V_125 * F_29 ( V_2 ) ) ;
}
STATIC void
F_79 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_93 ,
int V_94 )
{
F_80 ( V_2 , V_129 ) ;
F_81 ( V_2 , V_7 , V_93 , V_94 ) ;
if ( V_7 ) {
F_82 ( V_2 -> V_53 , V_7 ,
F_31 ( V_2 , V_93 ) ,
F_31 ( V_2 , V_94 + 1 ) - 1 ) ;
} else {
F_83 ( V_2 -> V_53 , V_2 -> V_34 . V_55 . V_78 ,
F_84 ( V_2 -> V_34 . V_55 . V_79 ) ) ;
}
F_80 ( V_2 , V_130 ) ;
}
void
F_85 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_93 ,
int V_94 )
{
F_80 ( V_2 , V_129 ) ;
F_81 ( V_2 , V_7 , V_93 , V_94 ) ;
F_82 ( V_2 -> V_53 , V_7 ,
F_30 ( V_2 , V_93 ) ,
F_30 ( V_2 , V_94 + 1 ) - 1 ) ;
F_80 ( V_2 , V_130 ) ;
}
STATIC void
F_86 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_93 ,
int V_94 )
{
F_80 ( V_2 , V_129 ) ;
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
F_80 ( V_2 , V_130 ) ;
}
void
F_87 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_90 )
{
int V_93 ;
int V_94 ;
static const short V_131 [] = {
F_88 ( struct V_3 , V_12 ) ,
F_88 ( struct V_3 , V_15 ) ,
F_88 ( struct V_3 , V_16 ) ,
F_88 ( struct V_3 , V_19 . V_37 . V_21 ) ,
F_88 ( struct V_3 , V_19 . V_37 . V_23 ) ,
V_68
} ;
static const short V_132 [] = {
F_88 ( struct V_3 , V_12 ) ,
F_88 ( struct V_3 , V_15 ) ,
F_88 ( struct V_3 , V_16 ) ,
F_88 ( struct V_3 , V_19 . V_20 . V_21 ) ,
F_88 ( struct V_3 , V_19 . V_20 . V_23 ) ,
V_67
} ;
F_80 ( V_2 , V_129 ) ;
F_89 ( V_2 , V_7 , V_90 ) ;
if ( V_7 ) {
F_49 ( V_90 ,
( V_2 -> V_41 & V_42 ) ?
V_132 : V_131 ,
V_133 , & V_93 , & V_94 ) ;
F_82 ( V_2 -> V_53 , V_7 , V_93 , V_94 ) ;
} else {
F_83 ( V_2 -> V_53 , V_2 -> V_34 . V_55 . V_78 ,
F_84 ( V_2 -> V_34 . V_55 . V_79 ) ) ;
}
F_80 ( V_2 , V_130 ) ;
}
int
F_90 (
struct V_1 * V_2 ,
int V_5 ,
int * V_134 )
{
struct V_3 * V_4 ;
union V_47 V_48 ;
struct V_6 * V_7 ;
int error ;
int V_104 ;
F_80 ( V_2 , V_129 ) ;
F_91 ( V_2 , V_5 ) ;
ASSERT ( V_5 < V_2 -> V_51 ) ;
F_57 ( V_2 , V_5 , V_103 ) ;
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_135;
#endif
if ( ++ V_2 -> V_63 [ V_5 ] <= F_93 ( V_4 ) )
goto V_136;
F_61 ( V_2 , V_4 , & V_48 , V_106 ) ;
if ( F_59 ( V_2 , & V_48 ) )
goto V_137;
F_94 ( V_2 , V_138 ) ;
for ( V_104 = V_5 + 1 ; V_104 < V_2 -> V_51 ; V_104 ++ ) {
V_4 = F_39 ( V_2 , V_104 , & V_7 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_104 , V_7 ) ;
if ( error )
goto V_135;
#endif
if ( ++ V_2 -> V_63 [ V_104 ] <= F_93 ( V_4 ) )
break;
F_57 ( V_2 , V_104 , V_103 ) ;
}
if ( V_104 == V_2 -> V_51 ) {
if ( V_2 -> V_41 & V_82 )
goto V_137;
ASSERT ( 0 ) ;
error = V_28 ;
goto V_135;
}
ASSERT ( V_104 < V_2 -> V_51 ) ;
for ( V_4 = F_39 ( V_2 , V_104 , & V_7 ) ; V_104 > V_5 ; ) {
union V_47 * V_139 ;
V_139 = F_35 ( V_2 , V_2 -> V_63 [ V_104 ] , V_4 ) ;
error = F_72 ( V_2 , V_139 , -- V_104 ,
0 , & V_4 , & V_7 ) ;
if ( error )
goto V_135;
F_58 ( V_2 , V_104 , V_7 ) ;
V_2 -> V_63 [ V_104 ] = 1 ;
}
V_136:
F_80 ( V_2 , V_130 ) ;
* V_134 = 1 ;
return 0 ;
V_137:
F_80 ( V_2 , V_130 ) ;
* V_134 = 0 ;
return 0 ;
V_135:
F_80 ( V_2 , V_140 ) ;
return error ;
}
int
F_95 (
struct V_1 * V_2 ,
int V_5 ,
int * V_134 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
int error ;
int V_104 ;
union V_47 V_48 ;
F_80 ( V_2 , V_129 ) ;
F_91 ( V_2 , V_5 ) ;
ASSERT ( V_5 < V_2 -> V_51 ) ;
F_57 ( V_2 , V_5 , V_102 ) ;
if ( -- V_2 -> V_63 [ V_5 ] > 0 )
goto V_136;
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_135;
#endif
F_61 ( V_2 , V_4 , & V_48 , V_105 ) ;
if ( F_59 ( V_2 , & V_48 ) )
goto V_137;
F_94 ( V_2 , V_141 ) ;
for ( V_104 = V_5 + 1 ; V_104 < V_2 -> V_51 ; V_104 ++ ) {
if ( -- V_2 -> V_63 [ V_104 ] > 0 )
break;
F_57 ( V_2 , V_104 , V_102 ) ;
}
if ( V_104 == V_2 -> V_51 ) {
if ( V_2 -> V_41 & V_82 )
goto V_137;
ASSERT ( 0 ) ;
error = V_28 ;
goto V_135;
}
ASSERT ( V_104 < V_2 -> V_51 ) ;
for ( V_4 = F_39 ( V_2 , V_104 , & V_7 ) ; V_104 > V_5 ; ) {
union V_47 * V_139 ;
V_139 = F_35 ( V_2 , V_2 -> V_63 [ V_104 ] , V_4 ) ;
error = F_72 ( V_2 , V_139 , -- V_104 ,
0 , & V_4 , & V_7 ) ;
if ( error )
goto V_135;
F_58 ( V_2 , V_104 , V_7 ) ;
V_2 -> V_63 [ V_104 ] = F_93 ( V_4 ) ;
}
V_136:
F_80 ( V_2 , V_130 ) ;
* V_134 = 1 ;
return 0 ;
V_137:
F_80 ( V_2 , V_130 ) ;
* V_134 = 0 ;
return 0 ;
V_135:
F_80 ( V_2 , V_140 ) ;
return error ;
}
STATIC int
F_96 (
struct V_1 * V_2 ,
int V_5 ,
union V_47 * V_142 ,
struct V_3 * * V_143 )
{
struct V_6 * V_7 ;
int error = 0 ;
if ( ( V_2 -> V_41 & V_82 ) &&
( V_5 == V_2 -> V_51 - 1 ) ) {
* V_143 = F_37 ( V_2 ) ;
return 0 ;
}
V_7 = V_2 -> V_52 [ V_5 ] ;
if ( V_7 && F_26 ( V_7 ) == F_69 ( V_2 , V_142 ) ) {
* V_143 = F_40 ( V_7 ) ;
return 0 ;
}
error = F_72 ( V_2 , V_142 , V_5 , 0 , V_143 , & V_7 ) ;
if ( error )
return error ;
F_58 ( V_2 , V_5 , V_7 ) ;
return 0 ;
}
STATIC union V_75 *
F_97 (
struct V_1 * V_2 ,
int V_5 ,
int V_144 ,
struct V_3 * V_4 ,
union V_75 * V_145 )
{
if ( V_5 == 0 ) {
V_2 -> V_17 -> V_146 ( V_145 ,
F_33 ( V_2 , V_144 , V_4 ) ) ;
return V_145 ;
}
return F_34 ( V_2 , V_144 , V_4 ) ;
}
int
F_98 (
struct V_1 * V_2 ,
T_14 V_127 ,
int * V_134 )
{
struct V_3 * V_4 ;
T_12 V_147 ;
int error ;
int V_144 ;
int V_5 ;
union V_47 * V_142 ;
union V_47 V_48 ;
F_80 ( V_2 , V_129 ) ;
F_91 ( V_2 , V_127 ) ;
F_94 ( V_2 , V_148 ) ;
V_4 = NULL ;
V_144 = 0 ;
V_2 -> V_17 -> V_149 ( V_2 , & V_48 ) ;
V_142 = & V_48 ;
for ( V_5 = V_2 -> V_51 - 1 , V_147 = 1 ; V_5 >= 0 ; V_5 -- ) {
error = F_96 ( V_2 , V_5 , V_142 , & V_4 ) ;
if ( error )
goto V_135;
if ( V_147 == 0 ) {
V_144 = 1 ;
} else {
int V_150 ;
int V_151 ;
V_151 = 1 ;
V_150 = F_93 ( V_4 ) ;
if ( ! V_150 ) {
ASSERT ( V_5 == 0 && V_2 -> V_51 == 1 ) ;
V_2 -> V_63 [ 0 ] = V_127 != V_152 ;
F_80 ( V_2 , V_130 ) ;
* V_134 = 0 ;
return 0 ;
}
while ( V_151 <= V_150 ) {
union V_75 V_126 ;
union V_75 * V_145 ;
F_94 ( V_2 , V_153 ) ;
V_144 = ( V_151 + V_150 ) >> 1 ;
V_145 = F_97 ( V_2 , V_5 ,
V_144 , V_4 , & V_126 ) ;
V_147 = V_2 -> V_17 -> V_154 ( V_2 , V_145 ) ;
if ( V_147 < 0 )
V_151 = V_144 + 1 ;
else if ( V_147 > 0 )
V_150 = V_144 - 1 ;
else
break;
}
}
if ( V_5 > 0 ) {
if ( V_147 > 0 && -- V_144 < 1 )
V_144 = 1 ;
V_142 = F_35 ( V_2 , V_144 , V_4 ) ;
#ifdef F_92
error = F_20 ( V_2 , V_142 , 0 , V_5 ) ;
if ( error )
goto V_135;
#endif
V_2 -> V_63 [ V_5 ] = V_144 ;
}
}
if ( V_127 != V_152 && V_147 < 0 ) {
V_144 ++ ;
F_61 ( V_2 , V_4 , & V_48 , V_106 ) ;
if ( V_127 == V_155 &&
V_144 > F_93 ( V_4 ) &&
! F_59 ( V_2 , & V_48 ) ) {
int V_50 ;
V_2 -> V_63 [ 0 ] = V_144 ;
error = F_90 ( V_2 , 0 , & V_50 ) ;
if ( error )
goto V_135;
F_18 ( V_50 == 1 ) ;
F_80 ( V_2 , V_130 ) ;
* V_134 = 1 ;
return 0 ;
}
} else if ( V_127 == V_152 && V_147 > 0 )
V_144 -- ;
V_2 -> V_63 [ 0 ] = V_144 ;
if ( V_144 == 0 || V_144 > F_93 ( V_4 ) )
* V_134 = 0 ;
else if ( V_127 != V_156 || V_147 == 0 )
* V_134 = 1 ;
else
* V_134 = 0 ;
F_80 ( V_2 , V_130 ) ;
return 0 ;
V_135:
F_80 ( V_2 , V_140 ) ;
return error ;
}
STATIC int
F_99 (
struct V_1 * V_2 ,
union V_75 * V_157 ,
int V_5 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_75 * V_145 ;
int V_48 ;
F_80 ( V_2 , V_129 ) ;
F_100 ( V_2 , V_5 , V_157 ) ;
ASSERT ( ! ( V_2 -> V_41 & V_82 ) || V_5 >= 1 ) ;
for ( V_48 = 1 ; V_48 == 1 && V_5 < V_2 -> V_51 ; V_5 ++ ) {
#ifdef F_92
int error ;
#endif
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error ) {
F_80 ( V_2 , V_140 ) ;
return error ;
}
#endif
V_48 = V_2 -> V_63 [ V_5 ] ;
V_145 = F_34 ( V_2 , V_48 , V_4 ) ;
F_73 ( V_2 , V_145 , V_157 , 1 ) ;
F_79 ( V_2 , V_7 , V_48 , V_48 ) ;
}
F_80 ( V_2 , V_130 ) ;
return 0 ;
}
int
F_101 (
struct V_1 * V_2 ,
union V_74 * V_128 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int error ;
int V_48 ;
union V_74 * V_158 ;
F_80 ( V_2 , V_129 ) ;
F_102 ( V_2 , V_128 ) ;
V_4 = F_39 ( V_2 , 0 , & V_7 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , 0 , V_7 ) ;
if ( error )
goto V_135;
#endif
V_48 = V_2 -> V_63 [ 0 ] ;
V_158 = F_33 ( V_2 , V_48 , V_4 ) ;
F_74 ( V_2 , V_158 , V_128 , 1 ) ;
F_85 ( V_2 , V_7 , V_48 , V_48 ) ;
if ( F_65 ( V_2 , V_4 , 0 ) ) {
V_2 -> V_17 -> V_159 ( V_2 , V_4 , V_128 ,
V_48 , V_160 ) ;
}
if ( V_48 == 1 ) {
union V_75 V_126 ;
V_2 -> V_17 -> V_146 ( & V_126 , V_128 ) ;
error = F_99 ( V_2 , & V_126 , 1 ) ;
if ( error )
goto V_135;
}
F_80 ( V_2 , V_130 ) ;
return 0 ;
V_135:
F_80 ( V_2 , V_140 ) ;
return error ;
}
STATIC int
F_103 (
struct V_1 * V_2 ,
int V_5 ,
int * V_134 )
{
union V_75 V_126 ;
struct V_6 * V_161 ;
struct V_3 * V_100 ;
int V_162 ;
struct V_6 * V_163 ;
struct V_3 * V_101 ;
int V_164 ;
union V_47 V_165 ;
union V_75 * V_166 = NULL ;
union V_47 * V_167 = NULL ;
union V_74 * V_168 = NULL ;
int error ;
F_80 ( V_2 , V_129 ) ;
F_91 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_41 & V_82 ) &&
V_5 == V_2 -> V_51 - 1 )
goto V_137;
V_101 = F_39 ( V_2 , V_5 , & V_163 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_101 , V_5 , V_163 ) ;
if ( error )
goto V_135;
#endif
F_61 ( V_2 , V_101 , & V_165 , V_105 ) ;
if ( F_59 ( V_2 , & V_165 ) )
goto V_137;
if ( V_2 -> V_63 [ V_5 ] <= 1 )
goto V_137;
error = F_72 ( V_2 , & V_165 , V_5 , 0 , & V_100 , & V_161 ) ;
if ( error )
goto V_135;
V_162 = F_93 ( V_100 ) ;
if ( V_162 == V_2 -> V_17 -> V_18 ( V_2 , V_5 ) )
goto V_137;
V_164 = F_93 ( V_101 ) ;
V_162 ++ ;
V_164 -- ;
F_94 ( V_2 , V_169 ) ;
F_104 ( V_2 , V_170 , 1 ) ;
if ( V_5 > 0 ) {
union V_75 * V_171 ;
union V_47 * V_172 ;
V_171 = F_34 ( V_2 , V_162 , V_100 ) ;
V_166 = F_34 ( V_2 , 1 , V_101 ) ;
V_172 = F_35 ( V_2 , V_162 , V_100 ) ;
V_167 = F_35 ( V_2 , 1 , V_101 ) ;
#ifdef F_92
error = F_20 ( V_2 , V_167 , 0 , V_5 ) ;
if ( error )
goto V_135;
#endif
F_73 ( V_2 , V_171 , V_166 , 1 ) ;
F_75 ( V_2 , V_172 , V_167 , 1 ) ;
F_79 ( V_2 , V_161 , V_162 , V_162 ) ;
F_86 ( V_2 , V_161 , V_162 , V_162 ) ;
ASSERT ( V_2 -> V_17 -> V_173 ( V_2 ,
F_34 ( V_2 , V_162 - 1 , V_100 ) , V_171 ) ) ;
} else {
union V_74 * V_174 ;
V_174 = F_33 ( V_2 , V_162 , V_100 ) ;
V_168 = F_33 ( V_2 , 1 , V_101 ) ;
F_74 ( V_2 , V_174 , V_168 , 1 ) ;
F_85 ( V_2 , V_161 , V_162 , V_162 ) ;
ASSERT ( V_2 -> V_17 -> V_175 ( V_2 ,
F_33 ( V_2 , V_162 - 1 , V_100 ) , V_174 ) ) ;
}
F_105 ( V_100 , V_162 ) ;
F_87 ( V_2 , V_161 , V_176 ) ;
F_105 ( V_101 , V_164 ) ;
F_87 ( V_2 , V_163 , V_176 ) ;
F_104 ( V_2 , V_170 , V_164 - 1 ) ;
if ( V_5 > 0 ) {
#ifdef F_92
int V_50 ;
for ( V_50 = 0 ; V_50 < V_164 ; V_50 ++ ) {
error = F_20 ( V_2 , V_167 , V_50 + 1 , V_5 ) ;
if ( error )
goto V_135;
}
#endif
F_76 ( V_2 ,
F_34 ( V_2 , 2 , V_101 ) ,
- 1 , V_164 ) ;
F_78 ( V_2 ,
F_35 ( V_2 , 2 , V_101 ) ,
- 1 , V_164 ) ;
F_79 ( V_2 , V_163 , 1 , V_164 ) ;
F_86 ( V_2 , V_163 , 1 , V_164 ) ;
} else {
F_77 ( V_2 ,
F_33 ( V_2 , 2 , V_101 ) ,
- 1 , V_164 ) ;
F_85 ( V_2 , V_163 , 1 , V_164 ) ;
V_2 -> V_17 -> V_146 ( & V_126 ,
F_33 ( V_2 , 1 , V_101 ) ) ;
V_166 = & V_126 ;
}
error = F_99 ( V_2 , V_166 , V_5 + 1 ) ;
if ( error )
goto V_135;
V_2 -> V_63 [ V_5 ] -- ;
F_80 ( V_2 , V_130 ) ;
* V_134 = 1 ;
return 0 ;
V_137:
F_80 ( V_2 , V_130 ) ;
* V_134 = 0 ;
return 0 ;
V_135:
F_80 ( V_2 , V_140 ) ;
return error ;
}
STATIC int
F_106 (
struct V_1 * V_2 ,
int V_5 ,
int * V_134 )
{
union V_75 V_126 ;
struct V_6 * V_161 ;
struct V_3 * V_100 ;
struct V_6 * V_163 ;
struct V_3 * V_101 ;
struct V_1 * V_177 ;
union V_47 V_178 ;
union V_75 * V_166 ;
int V_164 ;
int V_162 ;
int error ;
int V_50 ;
F_80 ( V_2 , V_129 ) ;
F_91 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_41 & V_82 ) &&
( V_5 == V_2 -> V_51 - 1 ) )
goto V_137;
V_100 = F_39 ( V_2 , V_5 , & V_161 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_100 , V_5 , V_161 ) ;
if ( error )
goto V_135;
#endif
F_61 ( V_2 , V_100 , & V_178 , V_106 ) ;
if ( F_59 ( V_2 , & V_178 ) )
goto V_137;
V_162 = F_93 ( V_100 ) ;
if ( V_2 -> V_63 [ V_5 ] >= V_162 )
goto V_137;
error = F_72 ( V_2 , & V_178 , V_5 , 0 , & V_101 , & V_163 ) ;
if ( error )
goto V_135;
V_164 = F_93 ( V_101 ) ;
if ( V_164 == V_2 -> V_17 -> V_18 ( V_2 , V_5 ) )
goto V_137;
F_94 ( V_2 , V_179 ) ;
F_104 ( V_2 , V_170 , V_164 ) ;
if ( V_5 > 0 ) {
union V_75 * V_171 ;
union V_47 * V_172 ;
union V_47 * V_167 ;
V_171 = F_34 ( V_2 , V_162 , V_100 ) ;
V_172 = F_35 ( V_2 , V_162 , V_100 ) ;
V_166 = F_34 ( V_2 , 1 , V_101 ) ;
V_167 = F_35 ( V_2 , 1 , V_101 ) ;
#ifdef F_92
for ( V_50 = V_164 - 1 ; V_50 >= 0 ; V_50 -- ) {
error = F_20 ( V_2 , V_167 , V_50 , V_5 ) ;
if ( error )
goto V_135;
}
#endif
F_76 ( V_2 , V_166 , 1 , V_164 ) ;
F_78 ( V_2 , V_167 , 1 , V_164 ) ;
#ifdef F_92
error = F_20 ( V_2 , V_172 , 0 , V_5 ) ;
if ( error )
goto V_135;
#endif
F_73 ( V_2 , V_166 , V_171 , 1 ) ;
F_75 ( V_2 , V_167 , V_172 , 1 ) ;
F_79 ( V_2 , V_163 , 1 , V_164 + 1 ) ;
F_86 ( V_2 , V_163 , 1 , V_164 + 1 ) ;
ASSERT ( V_2 -> V_17 -> V_173 ( V_2 , V_166 ,
F_34 ( V_2 , 2 , V_101 ) ) ) ;
} else {
union V_74 * V_174 ;
union V_74 * V_168 ;
V_174 = F_33 ( V_2 , V_162 , V_100 ) ;
V_168 = F_33 ( V_2 , 1 , V_101 ) ;
F_77 ( V_2 , V_168 , 1 , V_164 ) ;
F_74 ( V_2 , V_168 , V_174 , 1 ) ;
F_85 ( V_2 , V_163 , 1 , V_164 + 1 ) ;
V_2 -> V_17 -> V_146 ( & V_126 , V_168 ) ;
V_166 = & V_126 ;
ASSERT ( V_2 -> V_17 -> V_175 ( V_2 , V_168 ,
F_33 ( V_2 , 2 , V_101 ) ) ) ;
}
F_105 ( V_100 , -- V_162 ) ;
F_87 ( V_2 , V_161 , V_176 ) ;
F_105 ( V_101 , ++ V_164 ) ;
F_87 ( V_2 , V_163 , V_176 ) ;
error = F_24 ( V_2 , & V_177 ) ;
if ( error )
goto V_135;
V_50 = F_48 ( V_177 , V_5 ) ;
F_107 ( V_50 == 1 , V_135 ) ;
error = F_90 ( V_177 , V_5 , & V_50 ) ;
if ( error )
goto V_180;
error = F_99 ( V_177 , V_166 , V_5 + 1 ) ;
if ( error )
goto V_180;
F_21 ( V_177 , V_181 ) ;
F_80 ( V_2 , V_130 ) ;
* V_134 = 1 ;
return 0 ;
V_137:
F_80 ( V_2 , V_130 ) ;
* V_134 = 0 ;
return 0 ;
V_135:
F_80 ( V_2 , V_140 ) ;
return error ;
V_180:
F_80 ( V_177 , V_140 ) ;
F_21 ( V_177 , V_182 ) ;
return error ;
}
STATIC int
F_108 (
struct V_1 * V_2 ,
int V_5 ,
union V_47 * V_139 ,
union V_75 * V_126 ,
struct V_1 * * V_183 ,
int * V_134 )
{
union V_47 V_165 ;
struct V_6 * V_161 ;
struct V_3 * V_100 ;
union V_47 V_178 ;
struct V_6 * V_163 ;
struct V_3 * V_101 ;
union V_47 V_184 ;
struct V_6 * V_185 ;
struct V_3 * V_186 ;
int V_162 ;
int V_164 ;
int V_187 ;
int error ;
#ifdef F_92
int V_50 ;
#endif
F_80 ( V_2 , V_129 ) ;
F_109 ( V_2 , V_5 , * V_139 , V_126 ) ;
F_94 ( V_2 , V_188 ) ;
V_100 = F_39 ( V_2 , V_5 , & V_161 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_100 , V_5 , V_161 ) ;
if ( error )
goto V_135;
#endif
F_66 ( V_2 , V_161 , & V_165 ) ;
error = V_2 -> V_17 -> V_189 ( V_2 , & V_165 , & V_178 , 1 , V_134 ) ;
if ( error )
goto V_135;
if ( * V_134 == 0 )
goto V_137;
F_94 ( V_2 , V_190 ) ;
error = F_71 ( V_2 , & V_178 , 0 , & V_101 , & V_163 ) ;
if ( error )
goto V_135;
F_63 ( V_2 , F_36 ( V_100 ) , 0 , V_101 ) ;
V_162 = F_93 ( V_100 ) ;
V_164 = V_162 / 2 ;
if ( ( V_162 & 1 ) && V_2 -> V_63 [ V_5 ] <= V_164 + 1 )
V_164 ++ ;
V_187 = ( V_162 - V_164 + 1 ) ;
F_104 ( V_2 , V_170 , V_164 ) ;
if ( V_5 > 0 ) {
union V_75 * V_171 ;
union V_47 * V_172 ;
union V_75 * V_166 ;
union V_47 * V_167 ;
V_171 = F_34 ( V_2 , V_187 , V_100 ) ;
V_172 = F_35 ( V_2 , V_187 , V_100 ) ;
V_166 = F_34 ( V_2 , 1 , V_101 ) ;
V_167 = F_35 ( V_2 , 1 , V_101 ) ;
#ifdef F_92
for ( V_50 = V_187 ; V_50 < V_164 ; V_50 ++ ) {
error = F_20 ( V_2 , V_172 , V_50 , V_5 ) ;
if ( error )
goto V_135;
}
#endif
F_73 ( V_2 , V_166 , V_171 , V_164 ) ;
F_75 ( V_2 , V_167 , V_172 , V_164 ) ;
F_79 ( V_2 , V_163 , 1 , V_164 ) ;
F_86 ( V_2 , V_163 , 1 , V_164 ) ;
F_73 ( V_2 , V_126 , V_166 , 1 ) ;
} else {
union V_74 * V_174 ;
union V_74 * V_168 ;
V_174 = F_33 ( V_2 , V_187 , V_100 ) ;
V_168 = F_33 ( V_2 , 1 , V_101 ) ;
F_74 ( V_2 , V_168 , V_174 , V_164 ) ;
F_85 ( V_2 , V_163 , 1 , V_164 ) ;
V_2 -> V_17 -> V_146 ( V_126 ,
F_33 ( V_2 , 1 , V_101 ) ) ;
}
F_61 ( V_2 , V_100 , & V_184 , V_106 ) ;
F_62 ( V_2 , V_101 , & V_184 , V_106 ) ;
F_62 ( V_2 , V_101 , & V_165 , V_105 ) ;
F_62 ( V_2 , V_100 , & V_178 , V_106 ) ;
V_162 -= V_164 ;
F_105 ( V_100 , V_162 ) ;
F_105 ( V_101 , F_93 ( V_101 ) + V_164 ) ;
F_87 ( V_2 , V_163 , V_191 ) ;
F_87 ( V_2 , V_161 , V_176 | V_106 ) ;
if ( ! F_59 ( V_2 , & V_184 ) ) {
error = F_72 ( V_2 , & V_184 , V_5 ,
0 , & V_186 , & V_185 ) ;
if ( error )
goto V_135;
F_62 ( V_2 , V_186 , & V_178 , V_105 ) ;
F_87 ( V_2 , V_185 , V_105 ) ;
}
if ( V_2 -> V_63 [ V_5 ] > V_162 + 1 ) {
F_58 ( V_2 , V_5 , V_163 ) ;
V_2 -> V_63 [ V_5 ] -= V_162 ;
}
if ( V_5 + 1 < V_2 -> V_51 ) {
error = F_24 ( V_2 , V_183 ) ;
if ( error )
goto V_135;
( * V_183 ) -> V_63 [ V_5 + 1 ] ++ ;
}
* V_139 = V_178 ;
F_80 ( V_2 , V_130 ) ;
* V_134 = 1 ;
return 0 ;
V_137:
F_80 ( V_2 , V_130 ) ;
* V_134 = 0 ;
return 0 ;
V_135:
F_80 ( V_2 , V_140 ) ;
return error ;
}
int
F_110 (
struct V_1 * V_2 ,
int * V_192 ,
int * V_134 )
{
struct V_6 * V_193 ;
struct V_3 * V_4 ;
struct V_3 * V_194 ;
union V_75 * V_195 ;
union V_47 * V_196 ;
union V_75 * V_145 ;
union V_47 * V_142 ;
union V_47 V_197 ;
int V_5 ;
int error ;
#ifdef F_92
int V_50 ;
#endif
F_80 ( V_2 , V_129 ) ;
F_94 ( V_2 , V_198 ) ;
ASSERT ( V_2 -> V_41 & V_82 ) ;
V_5 = V_2 -> V_51 - 1 ;
V_4 = F_37 ( V_2 ) ;
V_142 = F_35 ( V_2 , 1 , V_4 ) ;
error = V_2 -> V_17 -> V_189 ( V_2 , V_142 , & V_197 , 1 , V_134 ) ;
if ( error )
goto V_135;
if ( * V_134 == 0 ) {
F_80 ( V_2 , V_130 ) ;
return 0 ;
}
F_94 ( V_2 , V_190 ) ;
error = F_71 ( V_2 , & V_197 , 0 , & V_194 , & V_193 ) ;
if ( error )
goto V_135;
memcpy ( V_194 , V_4 , F_28 ( V_2 ) ) ;
F_111 ( & V_4 -> V_15 , 1 ) ;
F_105 ( V_4 , 1 ) ;
V_2 -> V_51 ++ ;
V_2 -> V_63 [ V_5 + 1 ] = 1 ;
V_145 = F_34 ( V_2 , 1 , V_4 ) ;
V_195 = F_34 ( V_2 , 1 , V_194 ) ;
F_73 ( V_2 , V_195 , V_145 , F_93 ( V_194 ) ) ;
V_196 = F_35 ( V_2 , 1 , V_194 ) ;
#ifdef F_92
for ( V_50 = 0 ; V_50 < F_3 ( V_194 -> V_16 ) ; V_50 ++ ) {
error = F_20 ( V_2 , V_142 , V_50 , V_5 ) ;
if ( error )
goto V_135;
}
#endif
F_75 ( V_2 , V_196 , V_142 , F_93 ( V_194 ) ) ;
#ifdef F_92
error = F_20 ( V_2 , & V_197 , 0 , V_5 ) ;
if ( error )
goto V_135;
#endif
F_75 ( V_2 , V_142 , & V_197 , 1 ) ;
F_112 ( V_2 -> V_34 . V_55 . V_78 ,
1 - F_93 ( V_194 ) ,
V_2 -> V_34 . V_55 . V_79 ) ;
F_58 ( V_2 , V_5 , V_193 ) ;
F_87 ( V_2 , V_193 , V_191 ) ;
F_79 ( V_2 , V_193 , 1 , F_3 ( V_194 -> V_16 ) ) ;
F_86 ( V_2 , V_193 , 1 , F_3 ( V_194 -> V_16 ) ) ;
* V_192 |=
V_199 | F_84 ( V_2 -> V_34 . V_55 . V_79 ) ;
* V_134 = 1 ;
F_80 ( V_2 , V_130 ) ;
return 0 ;
V_135:
F_80 ( V_2 , V_140 ) ;
return error ;
}
STATIC int
F_113 (
struct V_1 * V_2 ,
int * V_134 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int error ;
struct V_6 * V_161 ;
struct V_3 * V_100 ;
struct V_6 * V_200 ;
struct V_3 * V_59 ;
int V_197 ;
struct V_6 * V_163 ;
struct V_3 * V_101 ;
union V_47 V_178 ;
union V_47 V_165 ;
F_80 ( V_2 , V_129 ) ;
F_94 ( V_2 , V_198 ) ;
V_2 -> V_17 -> V_149 ( V_2 , & V_178 ) ;
error = V_2 -> V_17 -> V_189 ( V_2 , & V_178 , & V_165 , 1 , V_134 ) ;
if ( error )
goto V_135;
if ( * V_134 == 0 )
goto V_137;
F_94 ( V_2 , V_190 ) ;
error = F_71 ( V_2 , & V_165 , 0 , & V_59 , & V_200 ) ;
if ( error )
goto V_135;
V_2 -> V_17 -> V_201 ( V_2 , & V_165 , 1 ) ;
V_4 = F_39 ( V_2 , V_2 -> V_51 - 1 , & V_7 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_2 -> V_51 - 1 , V_7 ) ;
if ( error )
goto V_135;
#endif
F_61 ( V_2 , V_4 , & V_178 , V_106 ) ;
if ( ! F_59 ( V_2 , & V_178 ) ) {
V_161 = V_7 ;
F_66 ( V_2 , V_161 , & V_165 ) ;
V_100 = V_4 ;
error = F_72 ( V_2 , & V_178 ,
V_2 -> V_51 - 1 , 0 , & V_101 , & V_163 ) ;
if ( error )
goto V_135;
V_7 = V_163 ;
V_197 = 1 ;
} else {
V_163 = V_7 ;
F_66 ( V_2 , V_163 , & V_178 ) ;
V_101 = V_4 ;
F_61 ( V_2 , V_101 , & V_165 , V_105 ) ;
error = F_72 ( V_2 , & V_165 ,
V_2 -> V_51 - 1 , 0 , & V_100 , & V_161 ) ;
if ( error )
goto V_135;
V_7 = V_161 ;
V_197 = 2 ;
}
F_63 ( V_2 , V_2 -> V_51 , 2 , V_59 ) ;
F_87 ( V_2 , V_200 , V_191 ) ;
ASSERT ( ! F_59 ( V_2 , & V_165 ) &&
! F_59 ( V_2 , & V_178 ) ) ;
if ( F_36 ( V_100 ) > 0 ) {
F_73 ( V_2 ,
F_34 ( V_2 , 1 , V_59 ) ,
F_34 ( V_2 , 1 , V_100 ) , 1 ) ;
F_73 ( V_2 ,
F_34 ( V_2 , 2 , V_59 ) ,
F_34 ( V_2 , 1 , V_101 ) , 1 ) ;
} else {
V_2 -> V_17 -> V_146 (
F_34 ( V_2 , 1 , V_59 ) ,
F_33 ( V_2 , 1 , V_100 ) ) ;
V_2 -> V_17 -> V_146 (
F_34 ( V_2 , 2 , V_59 ) ,
F_33 ( V_2 , 1 , V_101 ) ) ;
}
F_79 ( V_2 , V_200 , 1 , 2 ) ;
F_75 ( V_2 ,
F_35 ( V_2 , 1 , V_59 ) , & V_165 , 1 ) ;
F_75 ( V_2 ,
F_35 ( V_2 , 2 , V_59 ) , & V_178 , 1 ) ;
F_86 ( V_2 , V_200 , 1 , 2 ) ;
F_58 ( V_2 , V_2 -> V_51 , V_200 ) ;
V_2 -> V_63 [ V_2 -> V_51 ] = V_197 ;
V_2 -> V_51 ++ ;
F_80 ( V_2 , V_130 ) ;
* V_134 = 1 ;
return 0 ;
V_135:
F_80 ( V_2 , V_140 ) ;
return error ;
V_137:
F_80 ( V_2 , V_130 ) ;
* V_134 = 0 ;
return 0 ;
}
STATIC int
F_114 (
struct V_1 * V_2 ,
int V_5 ,
int V_107 ,
int * V_202 ,
int * V_49 ,
union V_47 * V_197 ,
struct V_1 * * V_58 ,
union V_74 * V_203 ,
int * V_134 )
{
union V_75 V_126 ;
int error = 0 ;
if ( ( V_2 -> V_41 & V_82 ) &&
V_5 == V_2 -> V_51 - 1 ) {
struct V_204 * V_78 = V_2 -> V_34 . V_55 . V_78 ;
if ( V_107 < V_2 -> V_17 -> V_205 ( V_2 , V_5 ) ) {
F_112 ( V_78 , 1 , V_2 -> V_34 . V_55 . V_79 ) ;
} else {
int V_192 = 0 ;
error = F_110 ( V_2 , & V_192 , V_134 ) ;
if ( error || * V_134 == 0 )
return error ;
F_83 ( V_2 -> V_53 , V_78 , V_192 ) ;
}
return 0 ;
}
error = F_106 ( V_2 , V_5 , V_134 ) ;
if ( error || * V_134 )
return error ;
error = F_103 ( V_2 , V_5 , V_134 ) ;
if ( error )
return error ;
if ( * V_134 ) {
* V_202 = * V_49 = V_2 -> V_63 [ V_5 ] ;
return 0 ;
}
error = F_108 ( V_2 , V_5 , V_197 , & V_126 , V_58 , V_134 ) ;
if ( error || * V_134 == 0 )
return error ;
* V_49 = V_2 -> V_63 [ V_5 ] ;
V_2 -> V_17 -> V_206 ( & V_126 , V_203 ) ;
return 0 ;
}
STATIC int
F_115 (
struct V_1 * V_2 ,
int V_5 ,
union V_47 * V_139 ,
union V_74 * V_207 ,
struct V_1 * * V_183 ,
int * V_134 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_75 V_126 ;
union V_47 V_197 ;
struct V_1 * V_58 ;
union V_74 V_203 ;
int V_208 ;
int V_48 ;
int V_107 ;
int error ;
#ifdef F_92
int V_50 ;
#endif
F_80 ( V_2 , V_129 ) ;
F_116 ( V_2 , V_5 , * V_139 , V_207 ) ;
V_58 = NULL ;
if ( ! ( V_2 -> V_41 & V_82 ) &&
( V_5 >= V_2 -> V_51 ) ) {
error = F_113 ( V_2 , V_134 ) ;
F_60 ( V_2 , V_139 ) ;
F_80 ( V_2 , V_130 ) ;
return error ;
}
V_48 = V_2 -> V_63 [ V_5 ] ;
if ( V_48 == 0 ) {
F_80 ( V_2 , V_130 ) ;
* V_134 = 0 ;
return 0 ;
}
V_2 -> V_17 -> V_146 ( & V_126 , V_207 ) ;
V_208 = V_48 ;
F_94 ( V_2 , V_209 ) ;
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
V_107 = F_93 ( V_4 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_135;
if ( V_48 <= V_107 ) {
if ( V_5 == 0 ) {
ASSERT ( V_2 -> V_17 -> V_175 ( V_2 , V_207 ,
F_33 ( V_2 , V_48 , V_4 ) ) ) ;
} else {
ASSERT ( V_2 -> V_17 -> V_173 ( V_2 , & V_126 ,
F_34 ( V_2 , V_48 , V_4 ) ) ) ;
}
}
#endif
F_60 ( V_2 , & V_197 ) ;
if ( V_107 == V_2 -> V_17 -> V_18 ( V_2 , V_5 ) ) {
error = F_114 ( V_2 , V_5 , V_107 ,
& V_208 , & V_48 , & V_197 , & V_58 , & V_203 , V_134 ) ;
if ( error || * V_134 == 0 )
goto V_135;
}
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
V_107 = F_93 ( V_4 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
return error ;
#endif
F_104 ( V_2 , V_170 , V_107 - V_48 + 1 ) ;
if ( V_5 > 0 ) {
union V_75 * V_145 ;
union V_47 * V_142 ;
V_145 = F_34 ( V_2 , V_48 , V_4 ) ;
V_142 = F_35 ( V_2 , V_48 , V_4 ) ;
#ifdef F_92
for ( V_50 = V_107 - V_48 ; V_50 >= 0 ; V_50 -- ) {
error = F_20 ( V_2 , V_142 , V_50 , V_5 ) ;
if ( error )
return error ;
}
#endif
F_76 ( V_2 , V_145 , 1 , V_107 - V_48 + 1 ) ;
F_78 ( V_2 , V_142 , 1 , V_107 - V_48 + 1 ) ;
#ifdef F_92
error = F_20 ( V_2 , V_139 , 0 , V_5 ) ;
if ( error )
goto V_135;
#endif
F_73 ( V_2 , V_145 , & V_126 , 1 ) ;
F_75 ( V_2 , V_142 , V_139 , 1 ) ;
V_107 ++ ;
F_105 ( V_4 , V_107 ) ;
F_86 ( V_2 , V_7 , V_48 , V_107 ) ;
F_79 ( V_2 , V_7 , V_48 , V_107 ) ;
#ifdef F_92
if ( V_48 < V_107 ) {
ASSERT ( V_2 -> V_17 -> V_173 ( V_2 , V_145 ,
F_34 ( V_2 , V_48 + 1 , V_4 ) ) ) ;
}
#endif
} else {
union V_74 * V_158 ;
V_158 = F_33 ( V_2 , V_48 , V_4 ) ;
F_77 ( V_2 , V_158 , 1 , V_107 - V_48 + 1 ) ;
F_74 ( V_2 , V_158 , V_207 , 1 ) ;
F_105 ( V_4 , ++ V_107 ) ;
F_85 ( V_2 , V_7 , V_48 , V_107 ) ;
#ifdef F_92
if ( V_48 < V_107 ) {
ASSERT ( V_2 -> V_17 -> V_175 ( V_2 , V_158 ,
F_33 ( V_2 , V_48 + 1 , V_4 ) ) ) ;
}
#endif
}
F_87 ( V_2 , V_7 , V_176 ) ;
if ( V_208 == 1 ) {
error = F_99 ( V_2 , & V_126 , V_5 + 1 ) ;
if ( error )
goto V_135;
}
if ( F_65 ( V_2 , V_4 , V_5 ) ) {
V_2 -> V_17 -> V_159 ( V_2 , V_4 , V_207 ,
V_48 , V_210 ) ;
}
* V_139 = V_197 ;
if ( ! F_59 ( V_2 , & V_197 ) ) {
* V_207 = V_203 ;
* V_183 = V_58 ;
}
F_80 ( V_2 , V_130 ) ;
* V_134 = 1 ;
return 0 ;
V_135:
F_80 ( V_2 , V_140 ) ;
return error ;
}
int
F_117 (
struct V_1 * V_2 ,
int * V_134 )
{
int error ;
int V_50 ;
int V_5 ;
union V_47 V_197 ;
struct V_1 * V_58 ;
struct V_1 * V_211 ;
union V_74 V_128 ;
V_5 = 0 ;
V_58 = NULL ;
V_211 = V_2 ;
F_60 ( V_2 , & V_197 ) ;
V_2 -> V_17 -> V_212 ( V_2 , & V_128 ) ;
do {
error = F_115 ( V_211 , V_5 , & V_197 , & V_128 , & V_58 , & V_50 ) ;
if ( error ) {
if ( V_211 != V_2 )
F_21 ( V_211 , V_182 ) ;
goto V_135;
}
F_107 ( V_50 == 1 , V_135 ) ;
V_5 ++ ;
if ( V_211 != V_2 &&
( V_58 || F_59 ( V_2 , & V_197 ) ) ) {
if ( V_2 -> V_17 -> V_213 )
V_2 -> V_17 -> V_213 ( V_211 , V_2 ) ;
V_2 -> V_51 = V_211 -> V_51 ;
F_21 ( V_211 , V_181 ) ;
}
if ( V_58 ) {
V_211 = V_58 ;
V_58 = NULL ;
}
} while ( ! F_59 ( V_2 , & V_197 ) );
F_80 ( V_2 , V_130 ) ;
* V_134 = V_50 ;
return 0 ;
V_135:
F_80 ( V_2 , V_140 ) ;
return error ;
}
STATIC int
F_118 (
struct V_1 * V_2 )
{
int V_79 = V_2 -> V_34 . V_55 . V_79 ;
struct V_204 * V_78 = V_2 -> V_34 . V_55 . V_78 ;
struct V_76 * V_77 = F_38 ( V_78 , V_79 ) ;
struct V_3 * V_4 ;
struct V_3 * V_194 ;
union V_75 * V_145 ;
union V_75 * V_195 ;
union V_47 * V_142 ;
union V_47 * V_196 ;
struct V_6 * V_193 ;
int V_5 ;
int V_49 ;
int V_107 ;
#ifdef F_92
union V_47 V_48 ;
int V_50 ;
#endif
F_80 ( V_2 , V_129 ) ;
ASSERT ( V_2 -> V_41 & V_82 ) ;
ASSERT ( V_2 -> V_51 > 1 ) ;
V_5 = V_2 -> V_51 - 1 ;
if ( V_5 == 1 )
goto V_137;
V_4 = F_37 ( V_2 ) ;
if ( F_93 ( V_4 ) != 1 )
goto V_137;
V_194 = F_39 ( V_2 , V_5 - 1 , & V_193 ) ;
V_107 = F_93 ( V_194 ) ;
if ( V_107 > V_2 -> V_17 -> V_205 ( V_2 , V_5 ) )
goto V_137;
F_94 ( V_2 , V_214 ) ;
#ifdef F_92
F_61 ( V_2 , V_4 , & V_48 , V_105 ) ;
ASSERT ( F_59 ( V_2 , & V_48 ) ) ;
F_61 ( V_2 , V_4 , & V_48 , V_106 ) ;
ASSERT ( F_59 ( V_2 , & V_48 ) ) ;
#endif
V_49 = V_107 - V_2 -> V_17 -> V_18 ( V_2 , V_5 ) ;
if ( V_49 ) {
F_112 ( V_2 -> V_34 . V_55 . V_78 , V_49 ,
V_2 -> V_34 . V_55 . V_79 ) ;
V_4 = V_77 -> V_80 ;
}
F_111 ( & V_4 -> V_16 , V_49 ) ;
ASSERT ( V_4 -> V_16 == V_194 -> V_16 ) ;
V_145 = F_34 ( V_2 , 1 , V_4 ) ;
V_195 = F_34 ( V_2 , 1 , V_194 ) ;
F_73 ( V_2 , V_145 , V_195 , V_107 ) ;
V_142 = F_35 ( V_2 , 1 , V_4 ) ;
V_196 = F_35 ( V_2 , 1 , V_194 ) ;
#ifdef F_92
for ( V_50 = 0 ; V_50 < V_107 ; V_50 ++ ) {
int error ;
error = F_20 ( V_2 , V_196 , V_50 , V_5 - 1 ) ;
if ( error ) {
F_80 ( V_2 , V_140 ) ;
return error ;
}
}
#endif
F_75 ( V_2 , V_142 , V_196 , V_107 ) ;
V_2 -> V_17 -> V_215 ( V_2 , V_193 ) ;
F_94 ( V_2 , free ) ;
V_2 -> V_52 [ V_5 - 1 ] = NULL ;
F_111 ( & V_4 -> V_15 , - 1 ) ;
F_83 ( V_2 -> V_53 , V_78 ,
V_199 | F_84 ( V_2 -> V_34 . V_55 . V_79 ) ) ;
V_2 -> V_51 -- ;
V_137:
F_80 ( V_2 , V_130 ) ;
return 0 ;
}
STATIC int
F_119 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_5 ,
union V_47 * V_198 )
{
int error ;
F_80 ( V_2 , V_129 ) ;
F_94 ( V_2 , V_214 ) ;
V_2 -> V_17 -> V_201 ( V_2 , V_198 , - 1 ) ;
error = V_2 -> V_17 -> V_215 ( V_2 , V_7 ) ;
if ( error ) {
F_80 ( V_2 , V_140 ) ;
return error ;
}
F_94 ( V_2 , free ) ;
V_2 -> V_52 [ V_5 ] = NULL ;
V_2 -> V_64 [ V_5 ] = 0 ;
V_2 -> V_51 -- ;
F_80 ( V_2 , V_130 ) ;
return 0 ;
}
STATIC int
F_120 (
struct V_1 * V_2 ,
int V_5 ,
int * V_134 )
{
int error ;
int V_50 ;
if ( V_5 > 0 ) {
error = F_95 ( V_2 , V_5 , & V_50 ) ;
if ( error )
return error ;
}
F_80 ( V_2 , V_130 ) ;
* V_134 = 1 ;
return 0 ;
}
STATIC int
F_121 (
struct V_1 * V_2 ,
int V_5 ,
int * V_134 )
{
struct V_3 * V_4 ;
union V_47 V_216 ;
struct V_6 * V_7 ;
int error ;
int V_50 ;
union V_75 V_126 ;
union V_75 * V_157 = & V_126 ;
union V_47 V_165 ;
struct V_6 * V_161 ;
struct V_3 * V_100 ;
int V_162 = 0 ;
int V_48 ;
union V_47 V_178 ;
struct V_6 * V_163 ;
struct V_3 * V_101 ;
struct V_3 * V_186 ;
struct V_6 * V_185 ;
int V_164 = 0 ;
struct V_1 * V_177 ;
int V_107 ;
F_80 ( V_2 , V_129 ) ;
F_91 ( V_2 , V_5 ) ;
V_177 = NULL ;
V_48 = V_2 -> V_63 [ V_5 ] ;
if ( V_48 == 0 ) {
F_80 ( V_2 , V_130 ) ;
* V_134 = 0 ;
return 0 ;
}
V_4 = F_39 ( V_2 , V_5 , & V_7 ) ;
V_107 = F_93 ( V_4 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_135;
#endif
if ( V_48 > V_107 ) {
F_80 ( V_2 , V_130 ) ;
* V_134 = 0 ;
return 0 ;
}
F_94 ( V_2 , V_217 ) ;
F_104 ( V_2 , V_170 , V_107 - V_48 ) ;
if ( V_5 > 0 ) {
union V_75 * V_171 ;
union V_47 * V_172 ;
V_171 = F_34 ( V_2 , V_48 + 1 , V_4 ) ;
V_172 = F_35 ( V_2 , V_48 + 1 , V_4 ) ;
#ifdef F_92
for ( V_50 = 0 ; V_50 < V_107 - V_48 ; V_50 ++ ) {
error = F_20 ( V_2 , V_172 , V_50 , V_5 ) ;
if ( error )
goto V_135;
}
#endif
if ( V_48 < V_107 ) {
F_76 ( V_2 , V_171 , - 1 , V_107 - V_48 ) ;
F_78 ( V_2 , V_172 , - 1 , V_107 - V_48 ) ;
F_79 ( V_2 , V_7 , V_48 , V_107 - 1 ) ;
F_86 ( V_2 , V_7 , V_48 , V_107 - 1 ) ;
}
if ( V_48 == 1 )
V_157 = F_34 ( V_2 , 1 , V_4 ) ;
} else {
if ( V_48 < V_107 ) {
F_77 ( V_2 ,
F_33 ( V_2 , V_48 + 1 , V_4 ) ,
- 1 , V_107 - V_48 ) ;
F_85 ( V_2 , V_7 , V_48 , V_107 - 1 ) ;
}
if ( V_48 == 1 ) {
V_2 -> V_17 -> V_146 ( & V_126 ,
F_33 ( V_2 , 1 , V_4 ) ) ;
V_157 = & V_126 ;
}
}
F_105 ( V_4 , -- V_107 ) ;
F_87 ( V_2 , V_7 , V_176 ) ;
if ( F_65 ( V_2 , V_4 , V_5 ) ) {
V_2 -> V_17 -> V_159 ( V_2 , V_4 , NULL ,
V_48 , V_218 ) ;
}
if ( V_5 == V_2 -> V_51 - 1 ) {
if ( V_2 -> V_41 & V_82 ) {
F_112 ( V_2 -> V_34 . V_55 . V_78 , - 1 ,
V_2 -> V_34 . V_55 . V_79 ) ;
error = F_118 ( V_2 ) ;
if ( error )
goto V_135;
error = F_120 ( V_2 , V_5 , V_134 ) ;
if ( error )
goto V_135;
* V_134 = 1 ;
return 0 ;
}
if ( V_107 == 1 && V_5 > 0 ) {
union V_47 * V_142 ;
V_142 = F_35 ( V_2 , 1 , V_4 ) ;
error = F_119 ( V_2 , V_7 , V_5 , V_142 ) ;
if ( error )
goto V_135;
} else if ( V_5 > 0 ) {
error = F_120 ( V_2 , V_5 , V_134 ) ;
if ( error )
goto V_135;
}
* V_134 = 1 ;
return 0 ;
}
if ( V_48 == 1 ) {
error = F_99 ( V_2 , V_157 , V_5 + 1 ) ;
if ( error )
goto V_135;
}
if ( V_107 >= V_2 -> V_17 -> V_219 ( V_2 , V_5 ) ) {
error = F_120 ( V_2 , V_5 , V_134 ) ;
if ( error )
goto V_135;
return 0 ;
}
F_61 ( V_2 , V_4 , & V_178 , V_106 ) ;
F_61 ( V_2 , V_4 , & V_165 , V_105 ) ;
if ( V_2 -> V_41 & V_82 ) {
if ( F_59 ( V_2 , & V_178 ) &&
F_59 ( V_2 , & V_165 ) &&
V_5 == V_2 -> V_51 - 2 ) {
error = F_118 ( V_2 ) ;
if ( ! error )
error = F_120 ( V_2 , V_5 , V_134 ) ;
if ( error )
goto V_135;
return 0 ;
}
}
ASSERT ( ! F_59 ( V_2 , & V_178 ) ||
! F_59 ( V_2 , & V_165 ) ) ;
error = F_24 ( V_2 , & V_177 ) ;
if ( error )
goto V_135;
if ( ! F_59 ( V_2 , & V_178 ) ) {
V_50 = F_48 ( V_177 , V_5 ) ;
F_107 ( V_50 == 1 , V_135 ) ;
error = F_90 ( V_177 , V_5 , & V_50 ) ;
if ( error )
goto V_135;
F_107 ( V_50 == 1 , V_135 ) ;
V_50 = F_48 ( V_177 , V_5 ) ;
F_107 ( V_50 == 1 , V_135 ) ;
V_101 = F_39 ( V_177 , V_5 , & V_163 ) ;
#ifdef F_92
error = F_16 ( V_177 , V_101 , V_5 , V_163 ) ;
if ( error )
goto V_135;
#endif
F_61 ( V_177 , V_101 , & V_216 , V_105 ) ;
if ( F_93 ( V_101 ) - 1 >=
V_2 -> V_17 -> V_219 ( V_177 , V_5 ) ) {
error = F_103 ( V_177 , V_5 , & V_50 ) ;
if ( error )
goto V_135;
if ( V_50 ) {
ASSERT ( F_93 ( V_4 ) >=
V_2 -> V_17 -> V_219 ( V_177 , V_5 ) ) ;
F_21 ( V_177 , V_181 ) ;
V_177 = NULL ;
error = F_120 ( V_2 , V_5 , V_134 ) ;
if ( error )
goto V_135;
return 0 ;
}
}
V_164 = F_93 ( V_101 ) ;
if ( ! F_59 ( V_2 , & V_165 ) ) {
V_50 = F_47 ( V_177 , V_5 ) ;
F_107 ( V_50 == 1 , V_135 ) ;
error = F_95 ( V_177 , V_5 , & V_50 ) ;
if ( error )
goto V_135;
F_107 ( V_50 == 1 , V_135 ) ;
}
}
if ( ! F_59 ( V_2 , & V_165 ) ) {
V_50 = F_47 ( V_177 , V_5 ) ;
F_107 ( V_50 == 1 , V_135 ) ;
error = F_95 ( V_177 , V_5 , & V_50 ) ;
if ( error )
goto V_135;
V_50 = F_47 ( V_177 , V_5 ) ;
F_107 ( V_50 == 1 , V_135 ) ;
V_100 = F_39 ( V_177 , V_5 , & V_161 ) ;
#ifdef F_92
error = F_16 ( V_2 , V_100 , V_5 , V_161 ) ;
if ( error )
goto V_135;
#endif
F_61 ( V_177 , V_100 , & V_216 , V_106 ) ;
if ( F_93 ( V_100 ) - 1 >=
V_2 -> V_17 -> V_219 ( V_177 , V_5 ) ) {
error = F_106 ( V_177 , V_5 , & V_50 ) ;
if ( error )
goto V_135;
if ( V_50 ) {
ASSERT ( F_93 ( V_4 ) >=
V_2 -> V_17 -> V_219 ( V_177 , V_5 ) ) ;
F_21 ( V_177 , V_181 ) ;
V_177 = NULL ;
if ( V_5 == 0 )
V_2 -> V_63 [ 0 ] ++ ;
F_80 ( V_2 , V_130 ) ;
* V_134 = 1 ;
return 0 ;
}
}
V_162 = F_93 ( V_100 ) ;
}
F_21 ( V_177 , V_181 ) ;
V_177 = NULL ;
ASSERT ( ! F_59 ( V_2 , & V_216 ) ) ;
if ( ! F_59 ( V_2 , & V_165 ) &&
V_162 + F_93 ( V_4 ) <=
V_2 -> V_17 -> V_18 ( V_2 , V_5 ) ) {
V_178 = V_216 ;
V_101 = V_4 ;
V_163 = V_7 ;
error = F_72 ( V_2 , & V_165 , V_5 ,
0 , & V_100 , & V_161 ) ;
if ( error )
goto V_135;
} else if ( ! F_59 ( V_2 , & V_178 ) &&
V_164 + F_93 ( V_4 ) <=
V_2 -> V_17 -> V_18 ( V_2 , V_5 ) ) {
V_165 = V_216 ;
V_100 = V_4 ;
V_161 = V_7 ;
error = F_72 ( V_2 , & V_178 , V_5 ,
0 , & V_101 , & V_163 ) ;
if ( error )
goto V_135;
} else {
error = F_120 ( V_2 , V_5 , V_134 ) ;
if ( error )
goto V_135;
return 0 ;
}
V_164 = F_93 ( V_101 ) ;
V_162 = F_93 ( V_100 ) ;
F_104 ( V_2 , V_170 , V_164 ) ;
if ( V_5 > 0 ) {
union V_75 * V_171 ;
union V_47 * V_172 ;
union V_75 * V_166 ;
union V_47 * V_167 ;
V_171 = F_34 ( V_2 , V_162 + 1 , V_100 ) ;
V_172 = F_35 ( V_2 , V_162 + 1 , V_100 ) ;
V_166 = F_34 ( V_2 , 1 , V_101 ) ;
V_167 = F_35 ( V_2 , 1 , V_101 ) ;
#ifdef F_92
for ( V_50 = 1 ; V_50 < V_164 ; V_50 ++ ) {
error = F_20 ( V_2 , V_167 , V_50 , V_5 ) ;
if ( error )
goto V_135;
}
#endif
F_73 ( V_2 , V_171 , V_166 , V_164 ) ;
F_75 ( V_2 , V_172 , V_167 , V_164 ) ;
F_79 ( V_2 , V_161 , V_162 + 1 , V_162 + V_164 ) ;
F_86 ( V_2 , V_161 , V_162 + 1 , V_162 + V_164 ) ;
} else {
union V_74 * V_174 ;
union V_74 * V_168 ;
V_174 = F_33 ( V_2 , V_162 + 1 , V_100 ) ;
V_168 = F_33 ( V_2 , 1 , V_101 ) ;
F_74 ( V_2 , V_174 , V_168 , V_164 ) ;
F_85 ( V_2 , V_161 , V_162 + 1 , V_162 + V_164 ) ;
}
F_94 ( V_2 , V_220 ) ;
F_105 ( V_100 , V_162 + V_164 ) ;
F_61 ( V_2 , V_101 , & V_216 , V_106 ) ,
F_62 ( V_2 , V_100 , & V_216 , V_106 ) ;
F_87 ( V_2 , V_161 , V_176 | V_106 ) ;
F_61 ( V_2 , V_100 , & V_216 , V_106 ) ;
if ( ! F_59 ( V_2 , & V_216 ) ) {
error = F_72 ( V_2 , & V_216 , V_5 ,
0 , & V_186 , & V_185 ) ;
if ( error )
goto V_135;
F_62 ( V_2 , V_186 , & V_165 , V_105 ) ;
F_87 ( V_2 , V_185 , V_105 ) ;
}
error = V_2 -> V_17 -> V_215 ( V_2 , V_163 ) ;
if ( error )
goto V_135;
F_94 ( V_2 , free ) ;
if ( V_7 != V_161 ) {
V_2 -> V_52 [ V_5 ] = V_161 ;
V_2 -> V_63 [ V_5 ] += V_162 ;
V_2 -> V_64 [ V_5 ] = 0 ;
}
else if ( ( V_2 -> V_41 & V_82 ) ||
( V_5 + 1 < V_2 -> V_51 ) ) {
error = F_90 ( V_2 , V_5 + 1 , & V_50 ) ;
if ( error )
goto V_135;
}
if ( V_5 > 0 )
V_2 -> V_63 [ V_5 ] -- ;
F_80 ( V_2 , V_130 ) ;
* V_134 = 2 ;
return 0 ;
V_135:
F_80 ( V_2 , V_140 ) ;
if ( V_177 )
F_21 ( V_177 , V_182 ) ;
return error ;
}
int
F_122 (
struct V_1 * V_2 ,
int * V_134 )
{
int error ;
int V_5 ;
int V_50 ;
F_80 ( V_2 , V_129 ) ;
for ( V_5 = 0 , V_50 = 2 ; V_50 == 2 ; V_5 ++ ) {
error = F_121 ( V_2 , V_5 , & V_50 ) ;
if ( error )
goto V_135;
}
if ( V_50 == 0 ) {
for ( V_5 = 1 ; V_5 < V_2 -> V_51 ; V_5 ++ ) {
if ( V_2 -> V_63 [ V_5 ] == 0 ) {
error = F_95 ( V_2 , V_5 , & V_50 ) ;
if ( error )
goto V_135;
break;
}
}
}
F_80 ( V_2 , V_130 ) ;
* V_134 = V_50 ;
return 0 ;
V_135:
F_80 ( V_2 , V_140 ) ;
return error ;
}
int
F_123 (
struct V_1 * V_2 ,
union V_74 * * V_207 ,
int * V_134 )
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
* V_134 = 0 ;
return 0 ;
}
* V_207 = F_33 ( V_2 , V_48 , V_4 ) ;
* V_134 = 1 ;
return 0 ;
}
