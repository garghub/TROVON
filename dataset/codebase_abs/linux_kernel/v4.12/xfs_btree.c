T_1
F_1 (
int V_1 ,
T_2 V_2 )
{
T_1 V_3 = V_4 [ V_1 ] [ V_2 ] ;
ASSERT ( V_3 != 0 ) ;
return V_3 ;
}
STATIC int
F_2 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_9 ,
struct V_10 * V_11 )
{
int V_12 = 1 ;
struct V_13 * V_14 ;
T_2 V_2 = V_6 -> V_15 ;
int V_1 ;
V_14 = V_6 -> V_16 ;
V_1 = F_3 ( & V_14 -> V_17 ) ;
if ( V_1 ) {
V_12 = V_12 &&
F_4 ( & V_8 -> V_18 . V_19 . V_20 ,
& V_14 -> V_17 . V_21 ) &&
V_8 -> V_18 . V_19 . V_22 == F_5 (
V_11 ? V_11 -> V_23 : V_24 ) ;
}
V_12 = V_12 &&
F_6 ( V_8 -> V_25 ) == F_1 ( V_1 , V_2 ) &&
F_7 ( V_8 -> V_26 ) == V_9 &&
F_7 ( V_8 -> V_27 ) <=
V_6 -> V_28 -> V_29 ( V_6 , V_9 ) &&
V_8 -> V_18 . V_19 . V_30 &&
( V_8 -> V_18 . V_19 . V_30 == F_5 ( V_31 ) ||
F_8 ( V_14 ,
F_9 ( V_8 -> V_18 . V_19 . V_30 ) ) ) &&
V_8 -> V_18 . V_19 . V_32 &&
( V_8 -> V_18 . V_19 . V_32 == F_5 ( V_31 ) ||
F_8 ( V_14 ,
F_9 ( V_8 -> V_18 . V_19 . V_32 ) ) ) ;
if ( F_10 ( F_11 ( ! V_12 , V_14 ,
V_33 ,
V_34 ) ) ) {
if ( V_11 )
F_12 ( V_11 , V_35 ) ;
F_13 ( V_36 , V_37 , V_14 ) ;
return - V_38 ;
}
return 0 ;
}
STATIC int
F_14 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_9 ,
struct V_10 * V_11 )
{
struct V_13 * V_14 ;
struct V_10 * V_39 ;
struct V_40 * V_41 ;
T_3 V_42 ;
int V_43 = 1 ;
T_2 V_2 = V_6 -> V_15 ;
int V_1 ;
V_14 = V_6 -> V_16 ;
V_1 = F_3 ( & V_14 -> V_17 ) ;
V_39 = V_6 -> V_44 . V_45 . V_39 ;
V_41 = F_15 ( V_39 ) ;
V_42 = F_6 ( V_41 -> V_46 ) ;
if ( V_1 ) {
V_43 = V_43 &&
F_4 ( & V_8 -> V_18 . V_47 . V_20 ,
& V_14 -> V_17 . V_21 ) &&
V_8 -> V_18 . V_47 . V_22 == F_5 (
V_11 ? V_11 -> V_23 : V_24 ) ;
}
V_43 = V_43 &&
F_6 ( V_8 -> V_25 ) == F_1 ( V_1 , V_2 ) &&
F_7 ( V_8 -> V_26 ) == V_9 &&
F_7 ( V_8 -> V_27 ) <=
V_6 -> V_28 -> V_29 ( V_6 , V_9 ) &&
( V_8 -> V_18 . V_47 . V_30 == F_16 ( V_48 ) ||
F_6 ( V_8 -> V_18 . V_47 . V_30 ) < V_42 ) &&
V_8 -> V_18 . V_47 . V_30 &&
( V_8 -> V_18 . V_47 . V_32 == F_16 ( V_48 ) ||
F_6 ( V_8 -> V_18 . V_47 . V_32 ) < V_42 ) &&
V_8 -> V_18 . V_47 . V_32 ;
if ( F_10 ( F_11 ( ! V_43 , V_14 ,
V_49 ,
V_50 ) ) ) {
if ( V_11 )
F_12 ( V_11 , V_35 ) ;
F_13 ( V_36 , V_37 , V_14 ) ;
return - V_38 ;
}
return 0 ;
}
int
F_17 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_9 ,
struct V_10 * V_11 )
{
if ( V_6 -> V_51 & V_52 )
return F_2 ( V_6 , V_8 , V_9 , V_11 ) ;
else
return F_14 ( V_6 , V_8 , V_9 , V_11 ) ;
}
int
F_18 (
struct V_5 * V_6 ,
T_4 V_53 ,
int V_9 )
{
F_19 ( V_6 -> V_16 ,
V_9 > 0 &&
V_53 != V_31 &&
F_8 ( V_6 -> V_16 , V_53 ) ) ;
return 0 ;
}
STATIC int
F_20 (
struct V_5 * V_6 ,
T_3 V_53 ,
int V_9 )
{
T_3 V_54 = V_6 -> V_16 -> V_17 . V_55 ;
F_19 ( V_6 -> V_16 ,
V_9 > 0 &&
V_53 != V_48 &&
V_53 != 0 &&
V_53 < V_54 ) ;
return 0 ;
}
STATIC int
F_21 (
struct V_5 * V_6 ,
union V_56 * V_57 ,
int V_58 ,
int V_9 )
{
if ( V_6 -> V_51 & V_52 ) {
return F_18 ( V_6 ,
F_9 ( ( & V_57 -> V_19 ) [ V_58 ] ) , V_9 ) ;
} else {
return F_20 ( V_6 ,
F_6 ( ( & V_57 -> V_47 ) [ V_58 ] ) , V_9 ) ;
}
}
void
F_22 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_23 ( V_11 ) ;
struct V_59 * V_60 = V_11 -> V_61 ;
if ( ! F_3 ( & V_11 -> V_62 -> V_63 -> V_17 ) )
return;
if ( V_60 )
V_8 -> V_18 . V_19 . V_64 = F_5 ( V_60 -> V_65 . V_66 ) ;
F_24 ( V_11 , V_67 ) ;
}
bool
F_25 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_23 ( V_11 ) ;
struct V_13 * V_14 = V_11 -> V_62 -> V_63 ;
if ( F_3 ( & V_14 -> V_17 ) ) {
if ( ! F_26 ( V_14 , F_9 ( V_8 -> V_18 . V_19 . V_64 ) ) )
return false ;
return F_27 ( V_11 , V_67 ) ;
}
return true ;
}
void
F_28 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_23 ( V_11 ) ;
struct V_59 * V_60 = V_11 -> V_61 ;
if ( ! F_3 ( & V_11 -> V_62 -> V_63 -> V_17 ) )
return;
if ( V_60 )
V_8 -> V_18 . V_47 . V_64 = F_5 ( V_60 -> V_65 . V_66 ) ;
F_24 ( V_11 , V_68 ) ;
}
bool
F_29 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_23 ( V_11 ) ;
struct V_13 * V_14 = V_11 -> V_62 -> V_63 ;
if ( F_3 ( & V_14 -> V_17 ) ) {
if ( ! F_26 ( V_14 , F_9 ( V_8 -> V_18 . V_47 . V_64 ) ) )
return false ;
return F_27 ( V_11 , V_68 ) ;
}
return true ;
}
static int
F_30 (
struct V_5 * V_6 ,
struct V_10 * V_11 )
{
int error ;
error = V_6 -> V_28 -> V_69 ( V_6 , V_11 ) ;
if ( ! error ) {
F_31 ( V_6 -> V_70 , V_11 ) ;
F_32 ( V_6 , free ) ;
}
return error ;
}
void
F_33 (
T_5 * V_6 ,
int error )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_6 -> V_72 ; V_71 ++ ) {
if ( V_6 -> V_73 [ V_71 ] )
F_34 ( V_6 -> V_70 , V_6 -> V_73 [ V_71 ] ) ;
else if ( ! error )
break;
}
ASSERT ( V_6 -> V_15 != V_74 ||
V_6 -> V_44 . V_75 . V_76 == 0 ) ;
F_35 ( V_77 , V_6 ) ;
}
int
F_36 (
T_5 * V_6 ,
T_5 * * V_78 )
{
T_6 * V_11 ;
int error ;
int V_71 ;
T_7 * V_14 ;
T_5 * V_79 ;
T_8 * V_80 ;
V_80 = V_6 -> V_70 ;
V_14 = V_6 -> V_16 ;
V_79 = V_6 -> V_28 -> V_81 ( V_6 ) ;
V_79 -> V_82 = V_6 -> V_82 ;
for ( V_71 = 0 ; V_71 < V_79 -> V_72 ; V_71 ++ ) {
V_79 -> V_83 [ V_71 ] = V_6 -> V_83 [ V_71 ] ;
V_79 -> V_84 [ V_71 ] = V_6 -> V_84 [ V_71 ] ;
V_11 = V_6 -> V_73 [ V_71 ] ;
if ( V_11 ) {
error = F_37 ( V_14 , V_80 , V_14 -> V_85 ,
F_38 ( V_11 ) , V_14 -> V_86 ,
0 , & V_11 ,
V_6 -> V_28 -> V_87 ) ;
if ( error ) {
F_33 ( V_79 , error ) ;
* V_78 = NULL ;
return error ;
}
}
V_79 -> V_73 [ V_71 ] = V_11 ;
}
* V_78 = V_79 ;
return 0 ;
}
static inline T_9 F_39 ( struct V_5 * V_6 )
{
if ( V_6 -> V_51 & V_52 ) {
if ( V_6 -> V_51 & V_88 )
return V_89 ;
return V_90 ;
}
if ( V_6 -> V_51 & V_88 )
return V_91 ;
return V_92 ;
}
static inline T_9 F_40 ( struct V_5 * V_6 )
{
return ( V_6 -> V_51 & V_52 ) ?
sizeof( V_93 ) : sizeof( V_94 ) ;
}
STATIC T_9
F_41 (
struct V_5 * V_6 ,
int V_95 )
{
return F_39 ( V_6 ) +
( V_95 - 1 ) * V_6 -> V_28 -> V_96 ;
}
STATIC T_9
F_42 (
struct V_5 * V_6 ,
int V_95 )
{
return F_39 ( V_6 ) +
( V_95 - 1 ) * V_6 -> V_28 -> V_97 ;
}
STATIC T_9
F_43 (
struct V_5 * V_6 ,
int V_95 )
{
return F_39 ( V_6 ) +
( V_95 - 1 ) * V_6 -> V_28 -> V_97 + ( V_6 -> V_28 -> V_97 / 2 ) ;
}
STATIC T_9
F_44 (
struct V_5 * V_6 ,
int V_95 ,
int V_9 )
{
return F_39 ( V_6 ) +
V_6 -> V_28 -> V_29 ( V_6 , V_9 ) * V_6 -> V_28 -> V_97 +
( V_95 - 1 ) * F_40 ( V_6 ) ;
}
STATIC union V_98 *
F_45 (
struct V_5 * V_6 ,
int V_95 ,
struct V_7 * V_8 )
{
return (union V_98 * )
( ( char * ) V_8 + F_41 ( V_6 , V_95 ) ) ;
}
STATIC union V_99 *
F_46 (
struct V_5 * V_6 ,
int V_95 ,
struct V_7 * V_8 )
{
return (union V_99 * )
( ( char * ) V_8 + F_42 ( V_6 , V_95 ) ) ;
}
STATIC union V_99 *
F_47 (
struct V_5 * V_6 ,
int V_95 ,
struct V_7 * V_8 )
{
return (union V_99 * )
( ( char * ) V_8 + F_43 ( V_6 , V_95 ) ) ;
}
STATIC union V_56 *
F_48 (
struct V_5 * V_6 ,
int V_95 ,
struct V_7 * V_8 )
{
int V_9 = F_49 ( V_8 ) ;
ASSERT ( V_8 -> V_26 != 0 ) ;
return (union V_56 * )
( ( char * ) V_8 + F_44 ( V_6 , V_95 , V_9 ) ) ;
}
STATIC struct V_7 *
F_50 (
struct V_5 * V_6 )
{
struct V_100 * V_101 ;
V_101 = F_51 ( V_6 -> V_44 . V_75 . V_102 , V_6 -> V_44 . V_75 . V_103 ) ;
return (struct V_7 * ) V_101 -> V_104 ;
}
STATIC struct V_7 *
F_52 (
struct V_5 * V_6 ,
int V_9 ,
struct V_10 * * V_105 )
{
if ( ( V_6 -> V_51 & V_106 ) &&
( V_9 == V_6 -> V_72 - 1 ) ) {
* V_105 = NULL ;
return F_50 ( V_6 ) ;
}
* V_105 = V_6 -> V_73 [ V_9 ] ;
return F_23 ( * V_105 ) ;
}
T_6 *
F_53 (
T_7 * V_14 ,
T_8 * V_80 ,
T_4 V_107 ,
T_10 V_108 )
{
T_11 V_109 ;
ASSERT ( V_107 != V_31 ) ;
V_109 = F_54 ( V_14 , V_107 ) ;
return F_55 ( V_80 , V_14 -> V_85 , V_109 , V_14 -> V_86 , V_108 ) ;
}
T_6 *
F_56 (
T_7 * V_14 ,
T_8 * V_80 ,
T_12 V_110 ,
T_3 V_111 ,
T_10 V_108 )
{
T_11 V_109 ;
ASSERT ( V_110 != V_112 ) ;
ASSERT ( V_111 != V_48 ) ;
V_109 = F_57 ( V_14 , V_110 , V_111 ) ;
return F_55 ( V_80 , V_14 -> V_85 , V_109 , V_14 -> V_86 , V_108 ) ;
}
int
F_58 (
T_5 * V_6 ,
int V_9 )
{
struct V_7 * V_8 ;
T_6 * V_11 ;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( V_6 -> V_51 & V_52 )
return V_8 -> V_18 . V_19 . V_32 == F_5 ( V_31 ) ;
else
return V_8 -> V_18 . V_47 . V_32 == F_16 ( V_48 ) ;
}
STATIC int
F_59 (
T_5 * V_6 ,
int V_9 )
{
struct V_7 * V_8 ;
T_6 * V_11 ;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( ! V_8 -> V_27 )
return 0 ;
V_6 -> V_83 [ V_9 ] = 1 ;
return 1 ;
}
STATIC int
F_60 (
T_5 * V_6 ,
int V_9 )
{
struct V_7 * V_8 ;
T_6 * V_11 ;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( ! V_8 -> V_27 )
return 0 ;
V_6 -> V_83 [ V_9 ] = F_7 ( V_8 -> V_27 ) ;
return 1 ;
}
void
F_61 (
T_13 V_113 ,
const short * V_114 ,
int V_115 ,
int * V_116 ,
int * V_117 )
{
int V_71 ;
T_13 V_118 ;
ASSERT ( V_113 != 0 ) ;
for ( V_71 = 0 , V_118 = 1LL ; ; V_71 ++ , V_118 <<= 1 ) {
if ( V_118 & V_113 ) {
* V_116 = V_114 [ V_71 ] ;
break;
}
}
for ( V_71 = V_115 - 1 , V_118 = 1LL << V_71 ; ; V_71 -- , V_118 >>= 1 ) {
if ( V_118 & V_113 ) {
* V_117 = V_114 [ V_71 + 1 ] - 1 ;
break;
}
}
}
int
F_62 (
struct V_13 * V_14 ,
struct V_119 * V_80 ,
T_4 V_107 ,
T_10 V_108 ,
struct V_10 * * V_105 ,
int V_120 ,
const struct V_121 * V_122 )
{
struct V_10 * V_11 ;
T_11 V_109 ;
int error ;
if ( ! F_8 ( V_14 , V_107 ) )
return - V_38 ;
V_109 = F_54 ( V_14 , V_107 ) ;
error = F_37 ( V_14 , V_80 , V_14 -> V_85 , V_109 ,
V_14 -> V_86 , V_108 , & V_11 , V_122 ) ;
if ( error )
return error ;
if ( V_11 )
F_63 ( V_11 , V_120 ) ;
* V_105 = V_11 ;
return 0 ;
}
void
F_64 (
struct V_13 * V_14 ,
T_4 V_107 ,
T_14 V_123 ,
const struct V_121 * V_122 )
{
T_11 V_109 ;
ASSERT ( V_107 != V_31 ) ;
V_109 = F_54 ( V_14 , V_107 ) ;
F_65 ( V_14 -> V_85 , V_109 , V_14 -> V_86 * V_123 , V_122 ) ;
}
void
F_66 (
struct V_13 * V_14 ,
T_12 V_110 ,
T_3 V_111 ,
T_14 V_123 ,
const struct V_121 * V_122 )
{
T_11 V_109 ;
ASSERT ( V_110 != V_112 ) ;
ASSERT ( V_111 != V_48 ) ;
V_109 = F_57 ( V_14 , V_110 , V_111 ) ;
F_65 ( V_14 -> V_85 , V_109 , V_14 -> V_86 * V_123 , V_122 ) ;
}
STATIC int
F_67 (
struct V_5 * V_6 ,
int V_124 ,
struct V_7 * V_8 )
{
int V_125 = 0 ;
T_4 V_126 = F_9 ( V_8 -> V_18 . V_19 . V_30 ) ;
T_4 V_127 = F_9 ( V_8 -> V_18 . V_19 . V_32 ) ;
if ( ( V_124 & V_128 ) && V_126 != V_31 ) {
F_64 ( V_6 -> V_16 , V_126 , 1 ,
V_6 -> V_28 -> V_87 ) ;
V_125 ++ ;
}
if ( ( V_124 & V_129 ) && V_127 != V_31 ) {
F_64 ( V_6 -> V_16 , V_127 , 1 ,
V_6 -> V_28 -> V_87 ) ;
V_125 ++ ;
}
return V_125 ;
}
STATIC int
F_68 (
struct V_5 * V_6 ,
int V_124 ,
struct V_7 * V_8 )
{
int V_125 = 0 ;
T_3 V_126 = F_6 ( V_8 -> V_18 . V_47 . V_30 ) ;
T_3 V_127 = F_6 ( V_8 -> V_18 . V_47 . V_32 ) ;
if ( ( V_124 & V_128 ) && V_126 != V_48 ) {
F_66 ( V_6 -> V_16 , V_6 -> V_44 . V_45 . V_110 ,
V_126 , 1 , V_6 -> V_28 -> V_87 ) ;
V_125 ++ ;
}
if ( ( V_124 & V_129 ) && V_127 != V_48 ) {
F_66 ( V_6 -> V_16 , V_6 -> V_44 . V_45 . V_110 ,
V_127 , 1 , V_6 -> V_28 -> V_87 ) ;
V_125 ++ ;
}
return V_125 ;
}
STATIC int
F_69 (
struct V_5 * V_6 ,
int V_130 ,
int V_124 )
{
struct V_7 * V_8 ;
if ( ( V_6 -> V_51 & V_106 ) &&
( V_130 == V_6 -> V_72 - 1 ) )
return 0 ;
if ( ( V_6 -> V_84 [ V_130 ] | V_124 ) == V_6 -> V_84 [ V_130 ] )
return 0 ;
V_6 -> V_84 [ V_130 ] |= V_124 ;
V_8 = F_23 ( V_6 -> V_73 [ V_130 ] ) ;
if ( V_6 -> V_51 & V_52 )
return F_67 ( V_6 , V_124 , V_8 ) ;
return F_68 ( V_6 , V_124 , V_8 ) ;
}
STATIC T_11
F_70 (
struct V_5 * V_6 ,
union V_56 * V_57 )
{
if ( V_6 -> V_51 & V_52 ) {
ASSERT ( V_57 -> V_19 != F_5 ( V_31 ) ) ;
return F_54 ( V_6 -> V_16 , F_9 ( V_57 -> V_19 ) ) ;
} else {
ASSERT ( V_6 -> V_44 . V_45 . V_110 != V_112 ) ;
ASSERT ( V_57 -> V_47 != F_16 ( V_48 ) ) ;
return F_57 ( V_6 -> V_16 , V_6 -> V_44 . V_45 . V_110 ,
F_6 ( V_57 -> V_47 ) ) ;
}
}
STATIC void
F_71 (
struct V_5 * V_6 ,
union V_56 * V_57 ,
T_14 V_123 )
{
F_65 ( V_6 -> V_16 -> V_85 ,
F_70 ( V_6 , V_57 ) ,
V_6 -> V_16 -> V_86 * V_123 , V_6 -> V_28 -> V_87 ) ;
}
STATIC void
F_72 (
T_5 * V_6 ,
int V_130 ,
T_6 * V_11 )
{
struct V_7 * V_75 ;
if ( V_6 -> V_73 [ V_130 ] )
F_34 ( V_6 -> V_70 , V_6 -> V_73 [ V_130 ] ) ;
V_6 -> V_73 [ V_130 ] = V_11 ;
V_6 -> V_84 [ V_130 ] = 0 ;
V_75 = F_23 ( V_11 ) ;
if ( V_6 -> V_51 & V_52 ) {
if ( V_75 -> V_18 . V_19 . V_30 == F_5 ( V_31 ) )
V_6 -> V_84 [ V_130 ] |= V_128 ;
if ( V_75 -> V_18 . V_19 . V_32 == F_5 ( V_31 ) )
V_6 -> V_84 [ V_130 ] |= V_129 ;
} else {
if ( V_75 -> V_18 . V_47 . V_30 == F_16 ( V_48 ) )
V_6 -> V_84 [ V_130 ] |= V_128 ;
if ( V_75 -> V_18 . V_47 . V_32 == F_16 ( V_48 ) )
V_6 -> V_84 [ V_130 ] |= V_129 ;
}
}
STATIC int
F_73 (
struct V_5 * V_6 ,
union V_56 * V_57 )
{
if ( V_6 -> V_51 & V_52 )
return V_57 -> V_19 == F_5 ( V_31 ) ;
else
return V_57 -> V_47 == F_16 ( V_48 ) ;
}
STATIC void
F_74 (
struct V_5 * V_6 ,
union V_56 * V_57 )
{
if ( V_6 -> V_51 & V_52 )
V_57 -> V_19 = F_5 ( V_31 ) ;
else
V_57 -> V_47 = F_16 ( V_48 ) ;
}
STATIC void
F_75 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
union V_56 * V_57 ,
int V_124 )
{
ASSERT ( V_124 == V_131 || V_124 == V_132 ) ;
if ( V_6 -> V_51 & V_52 ) {
if ( V_124 == V_132 )
V_57 -> V_19 = V_8 -> V_18 . V_19 . V_32 ;
else
V_57 -> V_19 = V_8 -> V_18 . V_19 . V_30 ;
} else {
if ( V_124 == V_132 )
V_57 -> V_47 = V_8 -> V_18 . V_47 . V_32 ;
else
V_57 -> V_47 = V_8 -> V_18 . V_47 . V_30 ;
}
}
STATIC void
F_76 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
union V_56 * V_57 ,
int V_124 )
{
ASSERT ( V_124 == V_131 || V_124 == V_132 ) ;
if ( V_6 -> V_51 & V_52 ) {
if ( V_124 == V_132 )
V_8 -> V_18 . V_19 . V_32 = V_57 -> V_19 ;
else
V_8 -> V_18 . V_19 . V_30 = V_57 -> V_19 ;
} else {
if ( V_124 == V_132 )
V_8 -> V_18 . V_47 . V_32 = V_57 -> V_47 ;
else
V_8 -> V_18 . V_47 . V_30 = V_57 -> V_47 ;
}
}
void
F_77 (
struct V_13 * V_14 ,
struct V_7 * V_133 ,
T_11 V_134 ,
T_2 V_2 ,
T_15 V_9 ,
T_15 V_135 ,
T_16 V_136 ,
unsigned int V_137 )
{
int V_1 = F_3 ( & V_14 -> V_17 ) ;
T_17 V_3 = F_1 ( V_1 , V_2 ) ;
V_133 -> V_25 = F_16 ( V_3 ) ;
V_133 -> V_26 = F_78 ( V_9 ) ;
V_133 -> V_27 = F_78 ( V_135 ) ;
if ( V_137 & V_52 ) {
V_133 -> V_18 . V_19 . V_30 = F_5 ( V_31 ) ;
V_133 -> V_18 . V_19 . V_32 = F_5 ( V_31 ) ;
if ( V_1 ) {
V_133 -> V_18 . V_19 . V_22 = F_5 ( V_134 ) ;
V_133 -> V_18 . V_19 . V_138 = F_5 ( V_136 ) ;
F_79 ( & V_133 -> V_18 . V_19 . V_20 , & V_14 -> V_17 . V_21 ) ;
V_133 -> V_18 . V_19 . V_139 = 0 ;
V_133 -> V_18 . V_19 . V_64 = 0 ;
}
} else {
T_17 V_140 = ( T_17 ) V_136 ;
V_133 -> V_18 . V_47 . V_30 = F_16 ( V_48 ) ;
V_133 -> V_18 . V_47 . V_32 = F_16 ( V_48 ) ;
if ( V_1 ) {
V_133 -> V_18 . V_47 . V_22 = F_5 ( V_134 ) ;
V_133 -> V_18 . V_47 . V_138 = F_16 ( V_140 ) ;
F_79 ( & V_133 -> V_18 . V_47 . V_20 , & V_14 -> V_17 . V_21 ) ;
V_133 -> V_18 . V_47 . V_64 = 0 ;
}
}
}
void
F_80 (
struct V_13 * V_14 ,
struct V_10 * V_11 ,
T_2 V_2 ,
T_15 V_9 ,
T_15 V_135 ,
T_16 V_136 ,
unsigned int V_137 )
{
F_77 ( V_14 , F_23 ( V_11 ) , V_11 -> V_23 ,
V_2 , V_9 , V_135 , V_136 , V_137 ) ;
}
STATIC void
F_81 (
struct V_5 * V_6 ,
struct V_10 * V_11 ,
int V_9 ,
int V_135 )
{
T_16 V_136 ;
if ( V_6 -> V_51 & V_52 )
V_136 = V_6 -> V_44 . V_75 . V_102 -> V_141 ;
else
V_136 = V_6 -> V_44 . V_45 . V_110 ;
F_77 ( V_6 -> V_16 , F_23 ( V_11 ) , V_11 -> V_23 ,
V_6 -> V_15 , V_9 , V_135 ,
V_136 , V_6 -> V_51 ) ;
}
STATIC int
F_82 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_9 )
{
union V_56 V_57 ;
if ( V_9 > 0 )
return 0 ;
if ( ! ( V_6 -> V_51 & V_142 ) )
return 0 ;
F_75 ( V_6 , V_8 , & V_57 , V_132 ) ;
if ( ! F_73 ( V_6 , & V_57 ) )
return 0 ;
return 1 ;
}
STATIC void
F_83 (
struct V_5 * V_6 ,
struct V_10 * V_11 ,
union V_56 * V_57 )
{
if ( V_6 -> V_51 & V_52 )
V_57 -> V_19 = F_5 ( F_84 ( V_6 -> V_16 ,
F_38 ( V_11 ) ) ) ;
else {
V_57 -> V_47 = F_16 ( F_85 ( V_6 -> V_16 ,
F_38 ( V_11 ) ) ) ;
}
}
STATIC void
F_86 (
struct V_5 * V_6 ,
struct V_10 * V_11 )
{
switch ( V_6 -> V_15 ) {
case V_143 :
case V_144 :
F_63 ( V_11 , V_145 ) ;
break;
case V_146 :
case V_147 :
F_63 ( V_11 , V_148 ) ;
break;
case V_74 :
F_63 ( V_11 , V_149 ) ;
break;
case V_150 :
F_63 ( V_11 , V_151 ) ;
break;
case V_152 :
F_63 ( V_11 , V_153 ) ;
break;
default:
ASSERT ( 0 ) ;
}
}
STATIC int
F_87 (
struct V_5 * V_6 ,
union V_56 * V_57 ,
int V_137 ,
struct V_7 * * V_8 ,
struct V_10 * * V_105 )
{
struct V_13 * V_14 = V_6 -> V_16 ;
T_11 V_109 ;
ASSERT ( ! ( V_137 & V_154 ) ) ;
V_109 = F_70 ( V_6 , V_57 ) ;
* V_105 = F_55 ( V_6 -> V_70 , V_14 -> V_85 , V_109 ,
V_14 -> V_86 , V_137 ) ;
if ( ! * V_105 )
return - V_155 ;
( * V_105 ) -> V_156 = V_6 -> V_28 -> V_87 ;
* V_8 = F_23 ( * V_105 ) ;
return 0 ;
}
STATIC int
F_88 (
struct V_5 * V_6 ,
union V_56 * V_57 ,
int V_137 ,
struct V_7 * * V_8 ,
struct V_10 * * V_105 )
{
struct V_13 * V_14 = V_6 -> V_16 ;
T_11 V_109 ;
int error ;
ASSERT ( ! ( V_137 & V_154 ) ) ;
V_109 = F_70 ( V_6 , V_57 ) ;
error = F_37 ( V_14 , V_6 -> V_70 , V_14 -> V_85 , V_109 ,
V_14 -> V_86 , V_137 , V_105 ,
V_6 -> V_28 -> V_87 ) ;
if ( error )
return error ;
F_86 ( V_6 , * V_105 ) ;
* V_8 = F_23 ( * V_105 ) ;
return 0 ;
}
STATIC void
F_89 (
struct V_5 * V_6 ,
union V_99 * V_157 ,
union V_99 * V_158 ,
int V_159 )
{
ASSERT ( V_159 >= 0 ) ;
memcpy ( V_157 , V_158 , V_159 * V_6 -> V_28 -> V_97 ) ;
}
STATIC void
F_90 (
struct V_5 * V_6 ,
union V_98 * V_160 ,
union V_98 * V_161 ,
int V_135 )
{
ASSERT ( V_135 >= 0 ) ;
memcpy ( V_160 , V_161 , V_135 * V_6 -> V_28 -> V_96 ) ;
}
STATIC void
F_91 (
struct V_5 * V_6 ,
union V_56 * V_162 ,
union V_56 * V_163 ,
int V_164 )
{
ASSERT ( V_164 >= 0 ) ;
memcpy ( V_162 , V_163 , V_164 * F_40 ( V_6 ) ) ;
}
STATIC void
F_92 (
struct V_5 * V_6 ,
union V_99 * V_165 ,
int V_166 ,
int V_159 )
{
char * V_157 ;
ASSERT ( V_159 >= 0 ) ;
ASSERT ( V_166 == 1 || V_166 == - 1 ) ;
V_157 = ( char * ) V_165 + ( V_166 * V_6 -> V_28 -> V_97 ) ;
memmove ( V_157 , V_165 , V_159 * V_6 -> V_28 -> V_97 ) ;
}
STATIC void
F_93 (
struct V_5 * V_6 ,
union V_98 * V_167 ,
int V_166 ,
int V_135 )
{
char * V_160 ;
ASSERT ( V_135 >= 0 ) ;
ASSERT ( V_166 == 1 || V_166 == - 1 ) ;
V_160 = ( char * ) V_167 + ( V_166 * V_6 -> V_28 -> V_96 ) ;
memmove ( V_160 , V_167 , V_135 * V_6 -> V_28 -> V_96 ) ;
}
STATIC void
F_94 (
struct V_5 * V_6 ,
union V_56 * V_57 ,
int V_166 ,
int V_164 )
{
char * V_162 ;
ASSERT ( V_164 >= 0 ) ;
ASSERT ( V_166 == 1 || V_166 == - 1 ) ;
V_162 = ( char * ) V_57 + ( V_166 * F_40 ( V_6 ) ) ;
memmove ( V_162 , V_57 , V_164 * F_40 ( V_6 ) ) ;
}
STATIC void
F_95 (
struct V_5 * V_6 ,
struct V_10 * V_11 ,
int V_116 ,
int V_117 )
{
F_96 ( V_6 , V_168 ) ;
F_97 ( V_6 , V_11 , V_116 , V_117 ) ;
if ( V_11 ) {
F_98 ( V_6 -> V_70 , V_11 , V_169 ) ;
F_99 ( V_6 -> V_70 , V_11 ,
F_42 ( V_6 , V_116 ) ,
F_42 ( V_6 , V_117 + 1 ) - 1 ) ;
} else {
F_100 ( V_6 -> V_70 , V_6 -> V_44 . V_75 . V_102 ,
F_101 ( V_6 -> V_44 . V_75 . V_103 ) ) ;
}
F_96 ( V_6 , V_170 ) ;
}
void
F_102 (
struct V_5 * V_6 ,
struct V_10 * V_11 ,
int V_116 ,
int V_117 )
{
F_96 ( V_6 , V_168 ) ;
F_97 ( V_6 , V_11 , V_116 , V_117 ) ;
F_98 ( V_6 -> V_70 , V_11 , V_169 ) ;
F_99 ( V_6 -> V_70 , V_11 ,
F_41 ( V_6 , V_116 ) ,
F_41 ( V_6 , V_117 + 1 ) - 1 ) ;
F_96 ( V_6 , V_170 ) ;
}
STATIC void
F_103 (
struct V_5 * V_6 ,
struct V_10 * V_11 ,
int V_116 ,
int V_117 )
{
F_96 ( V_6 , V_168 ) ;
F_97 ( V_6 , V_11 , V_116 , V_117 ) ;
if ( V_11 ) {
struct V_7 * V_8 = F_23 ( V_11 ) ;
int V_9 = F_49 ( V_8 ) ;
F_98 ( V_6 -> V_70 , V_11 , V_169 ) ;
F_99 ( V_6 -> V_70 , V_11 ,
F_44 ( V_6 , V_116 , V_9 ) ,
F_44 ( V_6 , V_117 + 1 , V_9 ) - 1 ) ;
} else {
F_100 ( V_6 -> V_70 , V_6 -> V_44 . V_75 . V_102 ,
F_101 ( V_6 -> V_44 . V_75 . V_103 ) ) ;
}
F_96 ( V_6 , V_170 ) ;
}
void
F_104 (
struct V_5 * V_6 ,
struct V_10 * V_11 ,
int V_113 )
{
int V_116 ;
int V_117 ;
static const short V_171 [] = {
F_105 ( struct V_7 , V_25 ) ,
F_105 ( struct V_7 , V_26 ) ,
F_105 ( struct V_7 , V_27 ) ,
F_105 ( struct V_7 , V_18 . V_47 . V_30 ) ,
F_105 ( struct V_7 , V_18 . V_47 . V_32 ) ,
F_105 ( struct V_7 , V_18 . V_47 . V_22 ) ,
F_105 ( struct V_7 , V_18 . V_47 . V_64 ) ,
F_105 ( struct V_7 , V_18 . V_47 . V_20 ) ,
F_105 ( struct V_7 , V_18 . V_47 . V_138 ) ,
F_105 ( struct V_7 , V_18 . V_47 . V_172 ) ,
V_91
} ;
static const short V_173 [] = {
F_105 ( struct V_7 , V_25 ) ,
F_105 ( struct V_7 , V_26 ) ,
F_105 ( struct V_7 , V_27 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_30 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_32 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_22 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_64 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_20 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_138 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_172 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_139 ) ,
V_89
} ;
F_96 ( V_6 , V_168 ) ;
F_106 ( V_6 , V_11 , V_113 ) ;
if ( V_11 ) {
int V_115 ;
if ( V_6 -> V_51 & V_88 ) {
if ( V_113 == V_174 )
V_113 = V_175 ;
V_115 = V_176 ;
} else {
V_115 = V_177 ;
}
F_61 ( V_113 ,
( V_6 -> V_51 & V_52 ) ?
V_173 : V_171 ,
V_115 , & V_116 , & V_117 ) ;
F_98 ( V_6 -> V_70 , V_11 , V_169 ) ;
F_99 ( V_6 -> V_70 , V_11 , V_116 , V_117 ) ;
} else {
F_100 ( V_6 -> V_70 , V_6 -> V_44 . V_75 . V_102 ,
F_101 ( V_6 -> V_44 . V_75 . V_103 ) ) ;
}
F_96 ( V_6 , V_170 ) ;
}
int
F_107 (
struct V_5 * V_6 ,
int V_9 ,
int * V_178 )
{
struct V_7 * V_8 ;
union V_56 V_57 ;
struct V_10 * V_11 ;
int error ;
int V_130 ;
F_96 ( V_6 , V_168 ) ;
F_108 ( V_6 , V_9 ) ;
ASSERT ( V_9 < V_6 -> V_72 ) ;
F_69 ( V_6 , V_9 , V_129 ) ;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error )
goto V_179;
#endif
if ( ++ V_6 -> V_83 [ V_9 ] <= F_110 ( V_8 ) )
goto V_180;
F_75 ( V_6 , V_8 , & V_57 , V_132 ) ;
if ( F_73 ( V_6 , & V_57 ) )
goto V_181;
F_32 ( V_6 , V_182 ) ;
for ( V_130 = V_9 + 1 ; V_130 < V_6 -> V_72 ; V_130 ++ ) {
V_8 = F_52 ( V_6 , V_130 , & V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_130 , V_11 ) ;
if ( error )
goto V_179;
#endif
if ( ++ V_6 -> V_83 [ V_130 ] <= F_110 ( V_8 ) )
break;
F_69 ( V_6 , V_130 , V_129 ) ;
}
if ( V_130 == V_6 -> V_72 ) {
if ( V_6 -> V_51 & V_106 )
goto V_181;
ASSERT ( 0 ) ;
error = - V_38 ;
goto V_179;
}
ASSERT ( V_130 < V_6 -> V_72 ) ;
for ( V_8 = F_52 ( V_6 , V_130 , & V_11 ) ; V_130 > V_9 ; ) {
union V_56 * V_183 ;
V_183 = F_48 ( V_6 , V_6 -> V_83 [ V_130 ] , V_8 ) ;
-- V_130 ;
error = F_88 ( V_6 , V_183 , 0 , & V_8 , & V_11 ) ;
if ( error )
goto V_179;
F_72 ( V_6 , V_130 , V_11 ) ;
V_6 -> V_83 [ V_130 ] = 1 ;
}
V_180:
F_96 ( V_6 , V_170 ) ;
* V_178 = 1 ;
return 0 ;
V_181:
F_96 ( V_6 , V_170 ) ;
* V_178 = 0 ;
return 0 ;
V_179:
F_96 ( V_6 , V_184 ) ;
return error ;
}
int
F_111 (
struct V_5 * V_6 ,
int V_9 ,
int * V_178 )
{
struct V_7 * V_8 ;
T_6 * V_11 ;
int error ;
int V_130 ;
union V_56 V_57 ;
F_96 ( V_6 , V_168 ) ;
F_108 ( V_6 , V_9 ) ;
ASSERT ( V_9 < V_6 -> V_72 ) ;
F_69 ( V_6 , V_9 , V_128 ) ;
if ( -- V_6 -> V_83 [ V_9 ] > 0 )
goto V_180;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error )
goto V_179;
#endif
F_75 ( V_6 , V_8 , & V_57 , V_131 ) ;
if ( F_73 ( V_6 , & V_57 ) )
goto V_181;
F_32 ( V_6 , V_185 ) ;
for ( V_130 = V_9 + 1 ; V_130 < V_6 -> V_72 ; V_130 ++ ) {
if ( -- V_6 -> V_83 [ V_130 ] > 0 )
break;
F_69 ( V_6 , V_130 , V_128 ) ;
}
if ( V_130 == V_6 -> V_72 ) {
if ( V_6 -> V_51 & V_106 )
goto V_181;
ASSERT ( 0 ) ;
error = - V_38 ;
goto V_179;
}
ASSERT ( V_130 < V_6 -> V_72 ) ;
for ( V_8 = F_52 ( V_6 , V_130 , & V_11 ) ; V_130 > V_9 ; ) {
union V_56 * V_183 ;
V_183 = F_48 ( V_6 , V_6 -> V_83 [ V_130 ] , V_8 ) ;
-- V_130 ;
error = F_88 ( V_6 , V_183 , 0 , & V_8 , & V_11 ) ;
if ( error )
goto V_179;
F_72 ( V_6 , V_130 , V_11 ) ;
V_6 -> V_83 [ V_130 ] = F_110 ( V_8 ) ;
}
V_180:
F_96 ( V_6 , V_170 ) ;
* V_178 = 1 ;
return 0 ;
V_181:
F_96 ( V_6 , V_170 ) ;
* V_178 = 0 ;
return 0 ;
V_179:
F_96 ( V_6 , V_184 ) ;
return error ;
}
STATIC int
F_112 (
struct V_5 * V_6 ,
int V_9 ,
union V_56 * V_186 ,
struct V_7 * * V_187 )
{
struct V_10 * V_11 ;
int error = 0 ;
if ( ( V_6 -> V_51 & V_106 ) &&
( V_9 == V_6 -> V_72 - 1 ) ) {
* V_187 = F_50 ( V_6 ) ;
return 0 ;
}
V_11 = V_6 -> V_73 [ V_9 ] ;
if ( V_11 && F_38 ( V_11 ) == F_70 ( V_6 , V_186 ) ) {
* V_187 = F_23 ( V_11 ) ;
return 0 ;
}
error = F_88 ( V_6 , V_186 , 0 , V_187 , & V_11 ) ;
if ( error )
return error ;
if ( F_3 ( & V_6 -> V_16 -> V_17 ) &&
( V_6 -> V_51 & V_52 ) &&
F_9 ( ( * V_187 ) -> V_18 . V_19 . V_138 ) !=
V_6 -> V_44 . V_75 . V_102 -> V_141 )
goto V_188;
if ( F_7 ( ( * V_187 ) -> V_26 ) != V_9 )
goto V_188;
if ( V_9 != 0 && F_7 ( ( * V_187 ) -> V_27 ) == 0 )
goto V_188;
F_72 ( V_6 , V_9 , V_11 ) ;
return 0 ;
V_188:
* V_187 = NULL ;
F_34 ( V_6 -> V_70 , V_11 ) ;
return - V_38 ;
}
STATIC union V_99 *
F_113 (
struct V_5 * V_6 ,
int V_9 ,
int V_189 ,
struct V_7 * V_8 ,
union V_99 * V_190 )
{
if ( V_9 == 0 ) {
V_6 -> V_28 -> V_191 ( V_190 ,
F_45 ( V_6 , V_189 , V_8 ) ) ;
return V_190 ;
}
return F_46 ( V_6 , V_189 , V_8 ) ;
}
int
F_114 (
struct V_5 * V_6 ,
T_18 V_166 ,
int * V_178 )
{
struct V_7 * V_8 ;
T_13 V_192 ;
int error ;
int V_189 ;
int V_9 ;
union V_56 * V_186 ;
union V_56 V_57 ;
F_96 ( V_6 , V_168 ) ;
F_108 ( V_6 , V_166 ) ;
F_32 ( V_6 , V_193 ) ;
if ( V_6 -> V_72 == 0 )
return - V_38 ;
V_8 = NULL ;
V_189 = 0 ;
V_6 -> V_28 -> V_194 ( V_6 , & V_57 ) ;
V_186 = & V_57 ;
for ( V_9 = V_6 -> V_72 - 1 , V_192 = 1 ; V_9 >= 0 ; V_9 -- ) {
error = F_112 ( V_6 , V_9 , V_186 , & V_8 ) ;
if ( error )
goto V_179;
if ( V_192 == 0 ) {
V_189 = 1 ;
} else {
int V_195 ;
int V_196 ;
V_196 = 1 ;
V_195 = F_110 ( V_8 ) ;
if ( ! V_195 ) {
ASSERT ( V_9 == 0 && V_6 -> V_72 == 1 ) ;
V_6 -> V_83 [ 0 ] = V_166 != V_197 ;
F_96 ( V_6 , V_170 ) ;
* V_178 = 0 ;
return 0 ;
}
while ( V_196 <= V_195 ) {
union V_99 V_165 ;
union V_99 * V_190 ;
F_32 ( V_6 , V_198 ) ;
V_189 = ( V_196 + V_195 ) >> 1 ;
V_190 = F_113 ( V_6 , V_9 ,
V_189 , V_8 , & V_165 ) ;
V_192 = V_6 -> V_28 -> V_199 ( V_6 , V_190 ) ;
if ( V_192 < 0 )
V_196 = V_189 + 1 ;
else if ( V_192 > 0 )
V_195 = V_189 - 1 ;
else
break;
}
}
if ( V_9 > 0 ) {
if ( V_192 > 0 && -- V_189 < 1 )
V_189 = 1 ;
V_186 = F_48 ( V_6 , V_189 , V_8 ) ;
#ifdef F_109
error = F_21 ( V_6 , V_186 , 0 , V_9 ) ;
if ( error )
goto V_179;
#endif
V_6 -> V_83 [ V_9 ] = V_189 ;
}
}
if ( V_166 != V_197 && V_192 < 0 ) {
V_189 ++ ;
F_75 ( V_6 , V_8 , & V_57 , V_132 ) ;
if ( V_166 == V_200 &&
V_189 > F_110 ( V_8 ) &&
! F_73 ( V_6 , & V_57 ) ) {
int V_71 ;
V_6 -> V_83 [ 0 ] = V_189 ;
error = F_107 ( V_6 , 0 , & V_71 ) ;
if ( error )
goto V_179;
F_19 ( V_6 -> V_16 , V_71 == 1 ) ;
F_96 ( V_6 , V_170 ) ;
* V_178 = 1 ;
return 0 ;
}
} else if ( V_166 == V_197 && V_192 > 0 )
V_189 -- ;
V_6 -> V_83 [ 0 ] = V_189 ;
if ( V_189 == 0 || V_189 > F_110 ( V_8 ) )
* V_178 = 0 ;
else if ( V_166 != V_201 || V_192 == 0 )
* V_178 = 1 ;
else
* V_178 = 0 ;
F_96 ( V_6 , V_170 ) ;
return 0 ;
V_179:
F_96 ( V_6 , V_184 ) ;
return error ;
}
STATIC union V_99 *
F_115 (
struct V_5 * V_6 ,
union V_99 * V_165 )
{
ASSERT ( V_6 -> V_51 & V_202 ) ;
return (union V_99 * ) ( ( char * ) V_165 +
( V_6 -> V_28 -> V_97 / 2 ) ) ;
}
STATIC void
F_116 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
union V_99 * V_165 )
{
union V_99 V_203 ;
union V_99 V_204 ;
union V_98 * V_167 ;
union V_99 * V_195 ;
int V_95 ;
V_167 = F_45 ( V_6 , 1 , V_8 ) ;
V_6 -> V_28 -> V_191 ( V_165 , V_167 ) ;
if ( V_6 -> V_51 & V_202 ) {
V_6 -> V_28 -> V_205 ( & V_203 , V_167 ) ;
for ( V_95 = 2 ; V_95 <= F_110 ( V_8 ) ; V_95 ++ ) {
V_167 = F_45 ( V_6 , V_95 , V_8 ) ;
V_6 -> V_28 -> V_205 ( & V_204 , V_167 ) ;
if ( V_6 -> V_28 -> V_206 ( V_6 , & V_204 , & V_203 )
> 0 )
V_203 = V_204 ;
}
V_195 = F_115 ( V_6 , V_165 ) ;
memcpy ( V_195 , & V_203 , V_6 -> V_28 -> V_97 / 2 ) ;
}
}
STATIC void
F_117 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
union V_99 * V_165 )
{
union V_99 * V_204 ;
union V_99 * V_203 ;
union V_99 * V_195 ;
int V_95 ;
if ( V_6 -> V_51 & V_202 ) {
memcpy ( V_165 , F_46 ( V_6 , 1 , V_8 ) ,
V_6 -> V_28 -> V_97 / 2 ) ;
V_203 = F_47 ( V_6 , 1 , V_8 ) ;
for ( V_95 = 2 ; V_95 <= F_110 ( V_8 ) ; V_95 ++ ) {
V_204 = F_47 ( V_6 , V_95 , V_8 ) ;
if ( V_6 -> V_28 -> V_206 ( V_6 , V_204 , V_203 ) > 0 )
V_203 = V_204 ;
}
V_195 = F_115 ( V_6 , V_165 ) ;
memcpy ( V_195 , V_203 , V_6 -> V_28 -> V_97 / 2 ) ;
} else {
memcpy ( V_165 , F_46 ( V_6 , 1 , V_8 ) ,
V_6 -> V_28 -> V_97 ) ;
}
}
STATIC void
F_118 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
union V_99 * V_165 )
{
if ( F_7 ( V_8 -> V_26 ) == 0 )
F_116 ( V_6 , V_8 , V_165 ) ;
else
F_117 ( V_6 , V_8 , V_165 ) ;
}
static inline bool
F_119 (
struct V_5 * V_6 ,
int V_57 )
{
return ( V_6 -> V_51 & V_202 ) || V_57 == 1 ;
}
STATIC int
F_120 (
struct V_5 * V_6 ,
int V_9 ,
struct V_7 * V_8 ,
struct V_10 * V_207 ,
bool V_208 )
{
union V_99 V_165 ;
union V_99 * V_209 ;
union V_99 * V_204 ;
union V_99 * V_210 ;
union V_99 * V_211 ;
struct V_10 * V_11 ;
int V_57 ;
ASSERT ( V_6 -> V_51 & V_202 ) ;
if ( V_9 + 1 >= V_6 -> V_72 )
return 0 ;
F_121 ( V_6 , V_9 , V_207 ) ;
V_209 = & V_165 ;
V_204 = F_115 ( V_6 , V_209 ) ;
F_118 ( V_6 , V_8 , V_209 ) ;
for ( V_9 ++ ; V_9 < V_6 -> V_72 ; V_9 ++ ) {
#ifdef F_109
int error ;
#endif
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
F_121 ( V_6 , V_9 , V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error ) {
F_96 ( V_6 , V_184 ) ;
return error ;
}
#endif
V_57 = V_6 -> V_83 [ V_9 ] ;
V_210 = F_46 ( V_6 , V_57 , V_8 ) ;
V_211 = F_47 ( V_6 , V_57 , V_8 ) ;
if ( ! V_208 &&
! ( V_6 -> V_28 -> V_206 ( V_6 , V_210 , V_209 ) != 0 ||
V_6 -> V_28 -> V_206 ( V_6 , V_211 , V_204 ) != 0 ) )
break;
F_89 ( V_6 , V_210 , V_209 , 1 ) ;
F_95 ( V_6 , V_11 , V_57 , V_57 ) ;
if ( V_9 + 1 >= V_6 -> V_72 )
break;
F_117 ( V_6 , V_8 , V_209 ) ;
}
return 0 ;
}
STATIC int
F_122 (
struct V_5 * V_6 ,
int V_9 )
{
struct V_10 * V_11 ;
struct V_7 * V_8 ;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
return F_120 ( V_6 , V_9 , V_8 , V_11 , true ) ;
}
STATIC int
F_123 (
struct V_5 * V_6 ,
int V_9 )
{
struct V_7 * V_8 ;
struct V_10 * V_11 ;
union V_99 * V_190 ;
union V_99 V_165 ;
int V_57 ;
ASSERT ( V_9 >= 0 ) ;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
if ( V_6 -> V_51 & V_202 )
return F_120 ( V_6 , V_9 , V_8 , V_11 , false ) ;
F_96 ( V_6 , V_168 ) ;
F_124 ( V_6 , V_9 , V_212 ) ;
F_118 ( V_6 , V_8 , & V_165 ) ;
for ( V_9 ++ , V_57 = 1 ; V_57 == 1 && V_9 < V_6 -> V_72 ; V_9 ++ ) {
#ifdef F_109
int error ;
#endif
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error ) {
F_96 ( V_6 , V_184 ) ;
return error ;
}
#endif
V_57 = V_6 -> V_83 [ V_9 ] ;
V_190 = F_46 ( V_6 , V_57 , V_8 ) ;
F_89 ( V_6 , V_190 , & V_165 , 1 ) ;
F_95 ( V_6 , V_11 , V_57 , V_57 ) ;
}
F_96 ( V_6 , V_170 ) ;
return 0 ;
}
int
F_125 (
struct V_5 * V_6 ,
union V_98 * V_167 )
{
struct V_7 * V_8 ;
struct V_10 * V_11 ;
int error ;
int V_57 ;
union V_98 * V_213 ;
F_96 ( V_6 , V_168 ) ;
F_126 ( V_6 , V_167 ) ;
V_8 = F_52 ( V_6 , 0 , & V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , 0 , V_11 ) ;
if ( error )
goto V_179;
#endif
V_57 = V_6 -> V_83 [ 0 ] ;
V_213 = F_45 ( V_6 , V_57 , V_8 ) ;
F_90 ( V_6 , V_213 , V_167 , 1 ) ;
F_102 ( V_6 , V_11 , V_57 , V_57 ) ;
if ( F_82 ( V_6 , V_8 , 0 ) ) {
V_6 -> V_28 -> V_214 ( V_6 , V_8 , V_167 ,
V_57 , V_215 ) ;
}
if ( F_119 ( V_6 , V_57 ) ) {
error = F_123 ( V_6 , 0 ) ;
if ( error )
goto V_179;
}
F_96 ( V_6 , V_170 ) ;
return 0 ;
V_179:
F_96 ( V_6 , V_184 ) ;
return error ;
}
STATIC int
F_127 (
struct V_5 * V_6 ,
int V_9 ,
int * V_178 )
{
struct V_10 * V_216 ;
struct V_7 * V_126 ;
int V_217 ;
struct V_10 * V_218 ;
struct V_7 * V_127 ;
struct V_5 * V_219 ;
int V_220 ;
union V_56 V_221 ;
union V_99 * V_222 = NULL ;
union V_56 * V_223 = NULL ;
union V_98 * V_224 = NULL ;
int error ;
int V_71 ;
F_96 ( V_6 , V_168 ) ;
F_108 ( V_6 , V_9 ) ;
if ( ( V_6 -> V_51 & V_106 ) &&
V_9 == V_6 -> V_72 - 1 )
goto V_181;
V_127 = F_52 ( V_6 , V_9 , & V_218 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_127 , V_9 , V_218 ) ;
if ( error )
goto V_179;
#endif
F_75 ( V_6 , V_127 , & V_221 , V_131 ) ;
if ( F_73 ( V_6 , & V_221 ) )
goto V_181;
if ( V_6 -> V_83 [ V_9 ] <= 1 )
goto V_181;
error = F_88 ( V_6 , & V_221 , 0 , & V_126 , & V_216 ) ;
if ( error )
goto V_179;
V_217 = F_110 ( V_126 ) ;
if ( V_217 == V_6 -> V_28 -> V_29 ( V_6 , V_9 ) )
goto V_181;
V_220 = F_110 ( V_127 ) ;
V_217 ++ ;
V_220 -- ;
F_32 ( V_6 , V_225 ) ;
F_128 ( V_6 , V_226 , 1 ) ;
if ( V_9 > 0 ) {
union V_99 * V_227 ;
union V_56 * V_228 ;
V_227 = F_46 ( V_6 , V_217 , V_126 ) ;
V_222 = F_46 ( V_6 , 1 , V_127 ) ;
V_228 = F_48 ( V_6 , V_217 , V_126 ) ;
V_223 = F_48 ( V_6 , 1 , V_127 ) ;
#ifdef F_109
error = F_21 ( V_6 , V_223 , 0 , V_9 ) ;
if ( error )
goto V_179;
#endif
F_89 ( V_6 , V_227 , V_222 , 1 ) ;
F_91 ( V_6 , V_228 , V_223 , 1 ) ;
F_95 ( V_6 , V_216 , V_217 , V_217 ) ;
F_103 ( V_6 , V_216 , V_217 , V_217 ) ;
ASSERT ( V_6 -> V_28 -> V_229 ( V_6 ,
F_46 ( V_6 , V_217 - 1 , V_126 ) , V_227 ) ) ;
} else {
union V_98 * V_230 ;
V_230 = F_45 ( V_6 , V_217 , V_126 ) ;
V_224 = F_45 ( V_6 , 1 , V_127 ) ;
F_90 ( V_6 , V_230 , V_224 , 1 ) ;
F_102 ( V_6 , V_216 , V_217 , V_217 ) ;
ASSERT ( V_6 -> V_28 -> V_231 ( V_6 ,
F_45 ( V_6 , V_217 - 1 , V_126 ) , V_230 ) ) ;
}
F_129 ( V_126 , V_217 ) ;
F_104 ( V_6 , V_216 , V_232 ) ;
F_129 ( V_127 , V_220 ) ;
F_104 ( V_6 , V_218 , V_232 ) ;
F_128 ( V_6 , V_226 , V_220 - 1 ) ;
if ( V_9 > 0 ) {
#ifdef F_109
int V_71 ;
for ( V_71 = 0 ; V_71 < V_220 ; V_71 ++ ) {
error = F_21 ( V_6 , V_223 , V_71 + 1 , V_9 ) ;
if ( error )
goto V_179;
}
#endif
F_92 ( V_6 ,
F_46 ( V_6 , 2 , V_127 ) ,
- 1 , V_220 ) ;
F_94 ( V_6 ,
F_48 ( V_6 , 2 , V_127 ) ,
- 1 , V_220 ) ;
F_95 ( V_6 , V_218 , 1 , V_220 ) ;
F_103 ( V_6 , V_218 , 1 , V_220 ) ;
} else {
F_93 ( V_6 ,
F_45 ( V_6 , 2 , V_127 ) ,
- 1 , V_220 ) ;
F_102 ( V_6 , V_218 , 1 , V_220 ) ;
}
if ( V_6 -> V_51 & V_202 ) {
error = F_36 ( V_6 , & V_219 ) ;
if ( error )
goto V_179;
V_71 = F_59 ( V_219 , V_9 ) ;
F_130 ( V_219 -> V_16 , V_71 == 1 , V_179 ) ;
error = F_111 ( V_219 , V_9 , & V_71 ) ;
if ( error )
goto V_233;
error = F_123 ( V_219 , V_9 ) ;
if ( error )
goto V_233;
F_33 ( V_219 , V_234 ) ;
}
error = F_123 ( V_6 , V_9 ) ;
if ( error )
goto V_179;
V_6 -> V_83 [ V_9 ] -- ;
F_96 ( V_6 , V_170 ) ;
* V_178 = 1 ;
return 0 ;
V_181:
F_96 ( V_6 , V_170 ) ;
* V_178 = 0 ;
return 0 ;
V_179:
F_96 ( V_6 , V_184 ) ;
return error ;
V_233:
F_96 ( V_219 , V_184 ) ;
F_33 ( V_219 , V_235 ) ;
return error ;
}
STATIC int
F_131 (
struct V_5 * V_6 ,
int V_9 ,
int * V_178 )
{
struct V_10 * V_216 ;
struct V_7 * V_126 ;
struct V_10 * V_218 ;
struct V_7 * V_127 ;
struct V_5 * V_219 ;
union V_56 V_236 ;
union V_99 * V_222 ;
int V_220 ;
int V_217 ;
int error ;
int V_71 ;
F_96 ( V_6 , V_168 ) ;
F_108 ( V_6 , V_9 ) ;
if ( ( V_6 -> V_51 & V_106 ) &&
( V_9 == V_6 -> V_72 - 1 ) )
goto V_181;
V_126 = F_52 ( V_6 , V_9 , & V_216 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_126 , V_9 , V_216 ) ;
if ( error )
goto V_179;
#endif
F_75 ( V_6 , V_126 , & V_236 , V_132 ) ;
if ( F_73 ( V_6 , & V_236 ) )
goto V_181;
V_217 = F_110 ( V_126 ) ;
if ( V_6 -> V_83 [ V_9 ] >= V_217 )
goto V_181;
error = F_88 ( V_6 , & V_236 , 0 , & V_127 , & V_218 ) ;
if ( error )
goto V_179;
V_220 = F_110 ( V_127 ) ;
if ( V_220 == V_6 -> V_28 -> V_29 ( V_6 , V_9 ) )
goto V_181;
F_32 ( V_6 , V_237 ) ;
F_128 ( V_6 , V_226 , V_220 ) ;
if ( V_9 > 0 ) {
union V_99 * V_227 ;
union V_56 * V_228 ;
union V_56 * V_223 ;
V_227 = F_46 ( V_6 , V_217 , V_126 ) ;
V_228 = F_48 ( V_6 , V_217 , V_126 ) ;
V_222 = F_46 ( V_6 , 1 , V_127 ) ;
V_223 = F_48 ( V_6 , 1 , V_127 ) ;
#ifdef F_109
for ( V_71 = V_220 - 1 ; V_71 >= 0 ; V_71 -- ) {
error = F_21 ( V_6 , V_223 , V_71 , V_9 ) ;
if ( error )
goto V_179;
}
#endif
F_92 ( V_6 , V_222 , 1 , V_220 ) ;
F_94 ( V_6 , V_223 , 1 , V_220 ) ;
#ifdef F_109
error = F_21 ( V_6 , V_228 , 0 , V_9 ) ;
if ( error )
goto V_179;
#endif
F_89 ( V_6 , V_222 , V_227 , 1 ) ;
F_91 ( V_6 , V_223 , V_228 , 1 ) ;
F_95 ( V_6 , V_218 , 1 , V_220 + 1 ) ;
F_103 ( V_6 , V_218 , 1 , V_220 + 1 ) ;
ASSERT ( V_6 -> V_28 -> V_229 ( V_6 , V_222 ,
F_46 ( V_6 , 2 , V_127 ) ) ) ;
} else {
union V_98 * V_230 ;
union V_98 * V_224 ;
V_230 = F_45 ( V_6 , V_217 , V_126 ) ;
V_224 = F_45 ( V_6 , 1 , V_127 ) ;
F_93 ( V_6 , V_224 , 1 , V_220 ) ;
F_90 ( V_6 , V_224 , V_230 , 1 ) ;
F_102 ( V_6 , V_218 , 1 , V_220 + 1 ) ;
}
F_129 ( V_126 , -- V_217 ) ;
F_104 ( V_6 , V_216 , V_232 ) ;
F_129 ( V_127 , ++ V_220 ) ;
F_104 ( V_6 , V_218 , V_232 ) ;
error = F_36 ( V_6 , & V_219 ) ;
if ( error )
goto V_179;
V_71 = F_60 ( V_219 , V_9 ) ;
F_130 ( V_219 -> V_16 , V_71 == 1 , V_179 ) ;
error = F_107 ( V_219 , V_9 , & V_71 ) ;
if ( error )
goto V_233;
if ( V_6 -> V_51 & V_202 ) {
error = F_123 ( V_6 , V_9 ) ;
if ( error )
goto V_233;
}
error = F_123 ( V_219 , V_9 ) ;
if ( error )
goto V_233;
F_33 ( V_219 , V_234 ) ;
F_96 ( V_6 , V_170 ) ;
* V_178 = 1 ;
return 0 ;
V_181:
F_96 ( V_6 , V_170 ) ;
* V_178 = 0 ;
return 0 ;
V_179:
F_96 ( V_6 , V_184 ) ;
return error ;
V_233:
F_96 ( V_219 , V_184 ) ;
F_33 ( V_219 , V_235 ) ;
return error ;
}
STATIC int
F_132 (
struct V_5 * V_6 ,
int V_9 ,
union V_56 * V_183 ,
union V_99 * V_165 ,
struct V_5 * * V_238 ,
int * V_178 )
{
union V_56 V_221 ;
struct V_10 * V_216 ;
struct V_7 * V_126 ;
union V_56 V_236 ;
struct V_10 * V_218 ;
struct V_7 * V_127 ;
union V_56 V_239 ;
struct V_10 * V_240 ;
struct V_7 * V_241 ;
int V_217 ;
int V_220 ;
int V_242 ;
int error ;
#ifdef F_109
int V_71 ;
#endif
F_96 ( V_6 , V_168 ) ;
F_133 ( V_6 , V_9 , * V_183 , V_165 ) ;
F_32 ( V_6 , V_243 ) ;
V_126 = F_52 ( V_6 , V_9 , & V_216 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_126 , V_9 , V_216 ) ;
if ( error )
goto V_179;
#endif
F_83 ( V_6 , V_216 , & V_221 ) ;
error = V_6 -> V_28 -> V_244 ( V_6 , & V_221 , & V_236 , V_178 ) ;
if ( error )
goto V_179;
if ( * V_178 == 0 )
goto V_181;
F_32 ( V_6 , V_245 ) ;
error = F_87 ( V_6 , & V_236 , 0 , & V_127 , & V_218 ) ;
if ( error )
goto V_179;
F_81 ( V_6 , V_218 , F_49 ( V_126 ) , 0 ) ;
V_217 = F_110 ( V_126 ) ;
V_220 = V_217 / 2 ;
if ( ( V_217 & 1 ) && V_6 -> V_83 [ V_9 ] <= V_220 + 1 )
V_220 ++ ;
V_242 = ( V_217 - V_220 + 1 ) ;
F_128 ( V_6 , V_226 , V_220 ) ;
V_217 -= V_220 ;
F_129 ( V_126 , V_217 ) ;
F_129 ( V_127 , F_110 ( V_127 ) + V_220 ) ;
if ( V_9 > 0 ) {
union V_99 * V_227 ;
union V_56 * V_228 ;
union V_99 * V_222 ;
union V_56 * V_223 ;
V_227 = F_46 ( V_6 , V_242 , V_126 ) ;
V_228 = F_48 ( V_6 , V_242 , V_126 ) ;
V_222 = F_46 ( V_6 , 1 , V_127 ) ;
V_223 = F_48 ( V_6 , 1 , V_127 ) ;
#ifdef F_109
for ( V_71 = V_242 ; V_71 < V_220 ; V_71 ++ ) {
error = F_21 ( V_6 , V_228 , V_71 , V_9 ) ;
if ( error )
goto V_179;
}
#endif
F_89 ( V_6 , V_222 , V_227 , V_220 ) ;
F_91 ( V_6 , V_223 , V_228 , V_220 ) ;
F_95 ( V_6 , V_218 , 1 , V_220 ) ;
F_103 ( V_6 , V_218 , 1 , V_220 ) ;
F_117 ( V_6 , V_127 , V_165 ) ;
} else {
union V_98 * V_230 ;
union V_98 * V_224 ;
V_230 = F_45 ( V_6 , V_242 , V_126 ) ;
V_224 = F_45 ( V_6 , 1 , V_127 ) ;
F_90 ( V_6 , V_224 , V_230 , V_220 ) ;
F_102 ( V_6 , V_218 , 1 , V_220 ) ;
F_116 ( V_6 , V_127 , V_165 ) ;
}
F_75 ( V_6 , V_126 , & V_239 , V_132 ) ;
F_76 ( V_6 , V_127 , & V_239 , V_132 ) ;
F_76 ( V_6 , V_127 , & V_221 , V_131 ) ;
F_76 ( V_6 , V_126 , & V_236 , V_132 ) ;
F_104 ( V_6 , V_218 , V_174 ) ;
F_104 ( V_6 , V_216 , V_232 | V_132 ) ;
if ( ! F_73 ( V_6 , & V_239 ) ) {
error = F_88 ( V_6 , & V_239 ,
0 , & V_241 , & V_240 ) ;
if ( error )
goto V_179;
F_76 ( V_6 , V_241 , & V_236 , V_131 ) ;
F_104 ( V_6 , V_240 , V_131 ) ;
}
if ( V_6 -> V_51 & V_202 ) {
error = F_123 ( V_6 , V_9 ) ;
if ( error )
goto V_179;
}
if ( V_6 -> V_83 [ V_9 ] > V_217 + 1 ) {
F_72 ( V_6 , V_9 , V_218 ) ;
V_6 -> V_83 [ V_9 ] -= V_217 ;
}
if ( V_9 + 1 < V_6 -> V_72 ) {
error = F_36 ( V_6 , V_238 ) ;
if ( error )
goto V_179;
( * V_238 ) -> V_83 [ V_9 + 1 ] ++ ;
}
* V_183 = V_236 ;
F_96 ( V_6 , V_170 ) ;
* V_178 = 1 ;
return 0 ;
V_181:
F_96 ( V_6 , V_170 ) ;
* V_178 = 0 ;
return 0 ;
V_179:
F_96 ( V_6 , V_184 ) ;
return error ;
}
static void
F_134 (
struct V_246 * V_247 )
{
struct V_248 * args = F_135 ( V_247 ,
struct V_248 , V_247 ) ;
unsigned long V_249 ;
unsigned long V_250 = V_251 ;
if ( args -> V_252 )
V_250 |= V_253 | V_254 | V_255 ;
F_136 ( & V_249 , V_250 ) ;
args -> V_256 = F_132 ( args -> V_6 , args -> V_9 , args -> V_183 ,
args -> V_165 , args -> V_238 , args -> V_178 ) ;
F_137 ( args -> V_257 ) ;
F_138 ( & V_249 , V_250 ) ;
}
STATIC int
F_139 (
struct V_5 * V_6 ,
int V_9 ,
union V_56 * V_183 ,
union V_99 * V_165 ,
struct V_5 * * V_238 ,
int * V_178 )
{
struct V_248 args ;
F_140 ( V_257 ) ;
if ( V_6 -> V_15 != V_74 )
return F_132 ( V_6 , V_9 , V_183 , V_165 , V_238 , V_178 ) ;
args . V_6 = V_6 ;
args . V_9 = V_9 ;
args . V_183 = V_183 ;
args . V_165 = V_165 ;
args . V_238 = V_238 ;
args . V_178 = V_178 ;
args . V_257 = & V_257 ;
args . V_252 = F_141 () ;
F_142 ( & args . V_247 , F_134 ) ;
F_143 ( V_258 , & args . V_247 ) ;
F_144 ( & V_257 ) ;
F_145 ( & args . V_247 ) ;
return args . V_256 ;
}
int
F_146 (
struct V_5 * V_6 ,
int * V_259 ,
int * V_178 )
{
struct V_10 * V_260 ;
struct V_7 * V_8 ;
struct V_7 * V_261 ;
union V_99 * V_262 ;
union V_56 * V_263 ;
union V_99 * V_190 ;
union V_56 * V_186 ;
union V_56 V_264 ;
int V_9 ;
int error ;
#ifdef F_109
int V_71 ;
#endif
F_96 ( V_6 , V_168 ) ;
F_32 ( V_6 , V_265 ) ;
ASSERT ( V_6 -> V_51 & V_106 ) ;
V_9 = V_6 -> V_72 - 1 ;
V_8 = F_50 ( V_6 ) ;
V_186 = F_48 ( V_6 , 1 , V_8 ) ;
error = V_6 -> V_28 -> V_244 ( V_6 , V_186 , & V_264 , V_178 ) ;
if ( error )
goto V_179;
if ( * V_178 == 0 ) {
F_96 ( V_6 , V_170 ) ;
return 0 ;
}
F_32 ( V_6 , V_245 ) ;
error = F_87 ( V_6 , & V_264 , 0 , & V_261 , & V_260 ) ;
if ( error )
goto V_179;
memcpy ( V_261 , V_8 , F_39 ( V_6 ) ) ;
if ( V_6 -> V_51 & V_88 ) {
if ( V_6 -> V_51 & V_52 )
V_261 -> V_18 . V_19 . V_22 = F_5 ( V_260 -> V_23 ) ;
else
V_261 -> V_18 . V_47 . V_22 = F_5 ( V_260 -> V_23 ) ;
}
F_147 ( & V_8 -> V_26 , 1 ) ;
F_129 ( V_8 , 1 ) ;
V_6 -> V_72 ++ ;
V_6 -> V_83 [ V_9 + 1 ] = 1 ;
V_190 = F_46 ( V_6 , 1 , V_8 ) ;
V_262 = F_46 ( V_6 , 1 , V_261 ) ;
F_89 ( V_6 , V_262 , V_190 , F_110 ( V_261 ) ) ;
V_263 = F_48 ( V_6 , 1 , V_261 ) ;
#ifdef F_109
for ( V_71 = 0 ; V_71 < F_7 ( V_261 -> V_27 ) ; V_71 ++ ) {
error = F_21 ( V_6 , V_186 , V_71 , V_9 ) ;
if ( error )
goto V_179;
}
#endif
F_91 ( V_6 , V_263 , V_186 , F_110 ( V_261 ) ) ;
#ifdef F_109
error = F_21 ( V_6 , & V_264 , 0 , V_9 ) ;
if ( error )
goto V_179;
#endif
F_91 ( V_6 , V_186 , & V_264 , 1 ) ;
F_148 ( V_6 -> V_44 . V_75 . V_102 ,
1 - F_110 ( V_261 ) ,
V_6 -> V_44 . V_75 . V_103 ) ;
F_72 ( V_6 , V_9 , V_260 ) ;
F_104 ( V_6 , V_260 , V_174 ) ;
F_95 ( V_6 , V_260 , 1 , F_7 ( V_261 -> V_27 ) ) ;
F_103 ( V_6 , V_260 , 1 , F_7 ( V_261 -> V_27 ) ) ;
* V_259 |=
V_266 | F_101 ( V_6 -> V_44 . V_75 . V_103 ) ;
* V_178 = 1 ;
F_96 ( V_6 , V_170 ) ;
return 0 ;
V_179:
F_96 ( V_6 , V_184 ) ;
return error ;
}
STATIC int
F_149 (
struct V_5 * V_6 ,
int * V_178 )
{
struct V_7 * V_8 ;
struct V_10 * V_11 ;
int error ;
struct V_10 * V_216 ;
struct V_7 * V_126 ;
struct V_10 * V_267 ;
struct V_7 * V_79 ;
int V_264 ;
struct V_10 * V_218 ;
struct V_7 * V_127 ;
union V_56 V_236 ;
union V_56 V_221 ;
F_96 ( V_6 , V_168 ) ;
F_32 ( V_6 , V_265 ) ;
V_6 -> V_28 -> V_194 ( V_6 , & V_236 ) ;
error = V_6 -> V_28 -> V_244 ( V_6 , & V_236 , & V_221 , V_178 ) ;
if ( error )
goto V_179;
if ( * V_178 == 0 )
goto V_181;
F_32 ( V_6 , V_245 ) ;
error = F_87 ( V_6 , & V_221 , 0 , & V_79 , & V_267 ) ;
if ( error )
goto V_179;
V_6 -> V_28 -> V_268 ( V_6 , & V_221 , 1 ) ;
V_8 = F_52 ( V_6 , V_6 -> V_72 - 1 , & V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_6 -> V_72 - 1 , V_11 ) ;
if ( error )
goto V_179;
#endif
F_75 ( V_6 , V_8 , & V_236 , V_132 ) ;
if ( ! F_73 ( V_6 , & V_236 ) ) {
V_216 = V_11 ;
F_83 ( V_6 , V_216 , & V_221 ) ;
V_126 = V_8 ;
error = F_88 ( V_6 , & V_236 , 0 , & V_127 , & V_218 ) ;
if ( error )
goto V_179;
V_11 = V_218 ;
V_264 = 1 ;
} else {
V_218 = V_11 ;
F_83 ( V_6 , V_218 , & V_236 ) ;
V_127 = V_8 ;
F_75 ( V_6 , V_127 , & V_221 , V_131 ) ;
error = F_88 ( V_6 , & V_221 , 0 , & V_126 , & V_216 ) ;
if ( error )
goto V_179;
V_11 = V_216 ;
V_264 = 2 ;
}
F_81 ( V_6 , V_267 , V_6 -> V_72 , 2 ) ;
F_104 ( V_6 , V_267 , V_174 ) ;
ASSERT ( ! F_73 ( V_6 , & V_221 ) &&
! F_73 ( V_6 , & V_236 ) ) ;
if ( F_49 ( V_126 ) > 0 ) {
F_117 ( V_6 , V_126 ,
F_46 ( V_6 , 1 , V_79 ) ) ;
F_117 ( V_6 , V_127 ,
F_46 ( V_6 , 2 , V_79 ) ) ;
} else {
F_116 ( V_6 , V_126 ,
F_46 ( V_6 , 1 , V_79 ) ) ;
F_116 ( V_6 , V_127 ,
F_46 ( V_6 , 2 , V_79 ) ) ;
}
F_95 ( V_6 , V_267 , 1 , 2 ) ;
F_91 ( V_6 ,
F_48 ( V_6 , 1 , V_79 ) , & V_221 , 1 ) ;
F_91 ( V_6 ,
F_48 ( V_6 , 2 , V_79 ) , & V_236 , 1 ) ;
F_103 ( V_6 , V_267 , 1 , 2 ) ;
F_72 ( V_6 , V_6 -> V_72 , V_267 ) ;
V_6 -> V_83 [ V_6 -> V_72 ] = V_264 ;
V_6 -> V_72 ++ ;
F_96 ( V_6 , V_170 ) ;
* V_178 = 1 ;
return 0 ;
V_179:
F_96 ( V_6 , V_184 ) ;
return error ;
V_181:
F_96 ( V_6 , V_170 ) ;
* V_178 = 0 ;
return 0 ;
}
STATIC int
F_150 (
struct V_5 * V_6 ,
int V_9 ,
int V_135 ,
int * V_269 ,
int * V_58 ,
union V_56 * V_264 ,
struct V_5 * * V_78 ,
union V_99 * V_165 ,
int * V_178 )
{
int error = 0 ;
if ( ( V_6 -> V_51 & V_106 ) &&
V_9 == V_6 -> V_72 - 1 ) {
struct V_270 * V_102 = V_6 -> V_44 . V_75 . V_102 ;
if ( V_135 < V_6 -> V_28 -> V_271 ( V_6 , V_9 ) ) {
F_148 ( V_102 , 1 , V_6 -> V_44 . V_75 . V_103 ) ;
* V_178 = 1 ;
} else {
int V_259 = 0 ;
error = F_146 ( V_6 , & V_259 , V_178 ) ;
if ( error || * V_178 == 0 )
return error ;
F_100 ( V_6 -> V_70 , V_102 , V_259 ) ;
}
return 0 ;
}
error = F_131 ( V_6 , V_9 , V_178 ) ;
if ( error || * V_178 )
return error ;
error = F_127 ( V_6 , V_9 , V_178 ) ;
if ( error )
return error ;
if ( * V_178 ) {
* V_269 = * V_58 = V_6 -> V_83 [ V_9 ] ;
return 0 ;
}
error = F_139 ( V_6 , V_9 , V_264 , V_165 , V_78 , V_178 ) ;
if ( error || * V_178 == 0 )
return error ;
* V_58 = V_6 -> V_83 [ V_9 ] ;
return 0 ;
}
STATIC int
F_151 (
struct V_5 * V_6 ,
int V_9 ,
union V_56 * V_183 ,
union V_98 * V_167 ,
union V_99 * V_165 ,
struct V_5 * * V_238 ,
int * V_178 )
{
struct V_7 * V_8 ;
struct V_10 * V_11 ;
union V_56 V_264 ;
struct V_5 * V_78 ;
union V_99 V_272 ;
union V_99 * V_209 ;
int V_273 ;
int V_57 ;
int V_135 ;
int error ;
#ifdef F_109
int V_71 ;
#endif
T_11 V_274 ;
F_96 ( V_6 , V_168 ) ;
F_152 ( V_6 , V_9 , * V_183 , & V_167 ) ;
V_78 = NULL ;
V_209 = & V_272 ;
if ( ! ( V_6 -> V_51 & V_106 ) &&
( V_9 >= V_6 -> V_72 ) ) {
error = F_149 ( V_6 , V_178 ) ;
F_74 ( V_6 , V_183 ) ;
F_96 ( V_6 , V_170 ) ;
return error ;
}
V_57 = V_6 -> V_83 [ V_9 ] ;
if ( V_57 == 0 ) {
F_96 ( V_6 , V_170 ) ;
* V_178 = 0 ;
return 0 ;
}
V_273 = V_57 ;
F_32 ( V_6 , V_275 ) ;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
V_274 = V_11 ? V_11 -> V_23 : V_24 ;
V_135 = F_110 ( V_8 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error )
goto V_179;
if ( V_57 <= V_135 ) {
if ( V_9 == 0 ) {
ASSERT ( V_6 -> V_28 -> V_231 ( V_6 , V_167 ,
F_45 ( V_6 , V_57 , V_8 ) ) ) ;
} else {
ASSERT ( V_6 -> V_28 -> V_229 ( V_6 , V_165 ,
F_46 ( V_6 , V_57 , V_8 ) ) ) ;
}
}
#endif
F_74 ( V_6 , & V_264 ) ;
if ( V_135 == V_6 -> V_28 -> V_29 ( V_6 , V_9 ) ) {
error = F_150 ( V_6 , V_9 , V_135 ,
& V_273 , & V_57 , & V_264 , & V_78 , V_209 , V_178 ) ;
if ( error || * V_178 == 0 )
goto V_179;
}
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
V_135 = F_110 ( V_8 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error )
return error ;
#endif
F_128 ( V_6 , V_226 , V_135 - V_57 + 1 ) ;
if ( V_9 > 0 ) {
union V_99 * V_190 ;
union V_56 * V_186 ;
V_190 = F_46 ( V_6 , V_57 , V_8 ) ;
V_186 = F_48 ( V_6 , V_57 , V_8 ) ;
#ifdef F_109
for ( V_71 = V_135 - V_57 ; V_71 >= 0 ; V_71 -- ) {
error = F_21 ( V_6 , V_186 , V_71 , V_9 ) ;
if ( error )
return error ;
}
#endif
F_92 ( V_6 , V_190 , 1 , V_135 - V_57 + 1 ) ;
F_94 ( V_6 , V_186 , 1 , V_135 - V_57 + 1 ) ;
#ifdef F_109
error = F_21 ( V_6 , V_183 , 0 , V_9 ) ;
if ( error )
goto V_179;
#endif
F_89 ( V_6 , V_190 , V_165 , 1 ) ;
F_91 ( V_6 , V_186 , V_183 , 1 ) ;
V_135 ++ ;
F_129 ( V_8 , V_135 ) ;
F_103 ( V_6 , V_11 , V_57 , V_135 ) ;
F_95 ( V_6 , V_11 , V_57 , V_135 ) ;
#ifdef F_109
if ( V_57 < V_135 ) {
ASSERT ( V_6 -> V_28 -> V_229 ( V_6 , V_190 ,
F_46 ( V_6 , V_57 + 1 , V_8 ) ) ) ;
}
#endif
} else {
union V_98 * V_213 ;
V_213 = F_45 ( V_6 , V_57 , V_8 ) ;
F_93 ( V_6 , V_213 , 1 , V_135 - V_57 + 1 ) ;
F_90 ( V_6 , V_213 , V_167 , 1 ) ;
F_129 ( V_8 , ++ V_135 ) ;
F_102 ( V_6 , V_11 , V_57 , V_135 ) ;
#ifdef F_109
if ( V_57 < V_135 ) {
ASSERT ( V_6 -> V_28 -> V_231 ( V_6 , V_213 ,
F_45 ( V_6 , V_57 + 1 , V_8 ) ) ) ;
}
#endif
}
F_104 ( V_6 , V_11 , V_232 ) ;
if ( V_11 && V_11 -> V_23 != V_274 ) {
F_118 ( V_6 , V_8 , V_209 ) ;
} else if ( F_119 ( V_6 , V_273 ) ) {
error = F_123 ( V_6 , V_9 ) ;
if ( error )
goto V_179;
}
if ( F_82 ( V_6 , V_8 , V_9 ) ) {
V_6 -> V_28 -> V_214 ( V_6 , V_8 , V_167 ,
V_57 , V_276 ) ;
}
* V_183 = V_264 ;
if ( ! F_73 ( V_6 , & V_264 ) ) {
F_89 ( V_6 , V_165 , V_209 , 1 ) ;
* V_238 = V_78 ;
}
F_96 ( V_6 , V_170 ) ;
* V_178 = 1 ;
return 0 ;
V_179:
F_96 ( V_6 , V_184 ) ;
return error ;
}
int
F_153 (
struct V_5 * V_6 ,
int * V_178 )
{
int error ;
int V_71 ;
int V_9 ;
union V_56 V_264 ;
struct V_5 * V_78 ;
struct V_5 * V_277 ;
union V_99 V_278 ;
union V_99 * V_165 ;
union V_98 V_167 ;
V_9 = 0 ;
V_78 = NULL ;
V_277 = V_6 ;
V_165 = & V_278 ;
F_74 ( V_6 , & V_264 ) ;
V_6 -> V_28 -> V_279 ( V_6 , & V_167 ) ;
V_6 -> V_28 -> V_191 ( V_165 , & V_167 ) ;
do {
error = F_151 ( V_277 , V_9 , & V_264 , & V_167 , V_165 ,
& V_78 , & V_71 ) ;
if ( error ) {
if ( V_277 != V_6 )
F_33 ( V_277 , V_235 ) ;
goto V_179;
}
F_130 ( V_6 -> V_16 , V_71 == 1 , V_179 ) ;
V_9 ++ ;
if ( V_277 != V_6 &&
( V_78 || F_73 ( V_6 , & V_264 ) ) ) {
if ( V_6 -> V_28 -> V_280 )
V_6 -> V_28 -> V_280 ( V_277 , V_6 ) ;
V_6 -> V_72 = V_277 -> V_72 ;
F_33 ( V_277 , V_234 ) ;
}
if ( V_78 ) {
V_277 = V_78 ;
V_78 = NULL ;
}
} while ( ! F_73 ( V_6 , & V_264 ) );
F_96 ( V_6 , V_170 ) ;
* V_178 = V_71 ;
return 0 ;
V_179:
F_96 ( V_6 , V_184 ) ;
return error ;
}
STATIC int
F_154 (
struct V_5 * V_6 )
{
int V_103 = V_6 -> V_44 . V_75 . V_103 ;
struct V_270 * V_102 = V_6 -> V_44 . V_75 . V_102 ;
struct V_100 * V_101 = F_51 ( V_102 , V_103 ) ;
struct V_7 * V_8 ;
struct V_7 * V_261 ;
union V_99 * V_190 ;
union V_99 * V_262 ;
union V_56 * V_186 ;
union V_56 * V_263 ;
struct V_10 * V_260 ;
int V_9 ;
int V_58 ;
int V_135 ;
int error ;
#ifdef F_109
union V_56 V_57 ;
int V_71 ;
#endif
F_96 ( V_6 , V_168 ) ;
ASSERT ( V_6 -> V_51 & V_106 ) ;
ASSERT ( V_6 -> V_72 > 1 ) ;
V_9 = V_6 -> V_72 - 1 ;
if ( V_9 == 1 )
goto V_181;
V_8 = F_50 ( V_6 ) ;
if ( F_110 ( V_8 ) != 1 )
goto V_181;
V_261 = F_52 ( V_6 , V_9 - 1 , & V_260 ) ;
V_135 = F_110 ( V_261 ) ;
if ( V_135 > V_6 -> V_28 -> V_271 ( V_6 , V_9 ) )
goto V_181;
F_32 ( V_6 , V_281 ) ;
#ifdef F_109
F_75 ( V_6 , V_8 , & V_57 , V_131 ) ;
ASSERT ( F_73 ( V_6 , & V_57 ) ) ;
F_75 ( V_6 , V_8 , & V_57 , V_132 ) ;
ASSERT ( F_73 ( V_6 , & V_57 ) ) ;
#endif
V_58 = V_135 - V_6 -> V_28 -> V_29 ( V_6 , V_9 ) ;
if ( V_58 ) {
F_148 ( V_6 -> V_44 . V_75 . V_102 , V_58 ,
V_6 -> V_44 . V_75 . V_103 ) ;
V_8 = V_101 -> V_104 ;
}
F_147 ( & V_8 -> V_27 , V_58 ) ;
ASSERT ( V_8 -> V_27 == V_261 -> V_27 ) ;
V_190 = F_46 ( V_6 , 1 , V_8 ) ;
V_262 = F_46 ( V_6 , 1 , V_261 ) ;
F_89 ( V_6 , V_190 , V_262 , V_135 ) ;
V_186 = F_48 ( V_6 , 1 , V_8 ) ;
V_263 = F_48 ( V_6 , 1 , V_261 ) ;
#ifdef F_109
for ( V_71 = 0 ; V_71 < V_135 ; V_71 ++ ) {
error = F_21 ( V_6 , V_263 , V_71 , V_9 - 1 ) ;
if ( error ) {
F_96 ( V_6 , V_184 ) ;
return error ;
}
}
#endif
F_91 ( V_6 , V_186 , V_263 , V_135 ) ;
error = F_30 ( V_6 , V_260 ) ;
if ( error ) {
F_96 ( V_6 , V_184 ) ;
return error ;
}
V_6 -> V_73 [ V_9 - 1 ] = NULL ;
F_147 ( & V_8 -> V_26 , - 1 ) ;
F_100 ( V_6 -> V_70 , V_102 ,
V_266 | F_101 ( V_6 -> V_44 . V_75 . V_103 ) ) ;
V_6 -> V_72 -- ;
V_181:
F_96 ( V_6 , V_170 ) ;
return 0 ;
}
STATIC int
F_155 (
struct V_5 * V_6 ,
struct V_10 * V_11 ,
int V_9 ,
union V_56 * V_265 )
{
int error ;
F_96 ( V_6 , V_168 ) ;
F_32 ( V_6 , V_281 ) ;
V_6 -> V_28 -> V_268 ( V_6 , V_265 , - 1 ) ;
error = F_30 ( V_6 , V_11 ) ;
if ( error ) {
F_96 ( V_6 , V_184 ) ;
return error ;
}
V_6 -> V_73 [ V_9 ] = NULL ;
V_6 -> V_84 [ V_9 ] = 0 ;
V_6 -> V_72 -- ;
F_96 ( V_6 , V_170 ) ;
return 0 ;
}
STATIC int
F_156 (
struct V_5 * V_6 ,
int V_9 ,
int * V_178 )
{
int error ;
int V_71 ;
if ( V_9 > 0 ) {
error = F_111 ( V_6 , V_9 , & V_71 ) ;
if ( error )
return error ;
}
F_96 ( V_6 , V_170 ) ;
* V_178 = 1 ;
return 0 ;
}
STATIC int
F_157 (
struct V_5 * V_6 ,
int V_9 ,
int * V_178 )
{
struct V_7 * V_8 ;
union V_56 V_282 ;
struct V_10 * V_11 ;
int error ;
int V_71 ;
union V_56 V_221 ;
struct V_10 * V_216 ;
struct V_7 * V_126 ;
int V_217 = 0 ;
int V_57 ;
union V_56 V_236 ;
struct V_10 * V_218 ;
struct V_7 * V_127 ;
struct V_7 * V_241 ;
struct V_10 * V_240 ;
int V_220 = 0 ;
struct V_5 * V_219 ;
int V_135 ;
F_96 ( V_6 , V_168 ) ;
F_108 ( V_6 , V_9 ) ;
V_219 = NULL ;
V_57 = V_6 -> V_83 [ V_9 ] ;
if ( V_57 == 0 ) {
F_96 ( V_6 , V_170 ) ;
* V_178 = 0 ;
return 0 ;
}
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
V_135 = F_110 ( V_8 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error )
goto V_179;
#endif
if ( V_57 > V_135 ) {
F_96 ( V_6 , V_170 ) ;
* V_178 = 0 ;
return 0 ;
}
F_32 ( V_6 , V_283 ) ;
F_128 ( V_6 , V_226 , V_135 - V_57 ) ;
if ( V_9 > 0 ) {
union V_99 * V_227 ;
union V_56 * V_228 ;
V_227 = F_46 ( V_6 , V_57 + 1 , V_8 ) ;
V_228 = F_48 ( V_6 , V_57 + 1 , V_8 ) ;
#ifdef F_109
for ( V_71 = 0 ; V_71 < V_135 - V_57 ; V_71 ++ ) {
error = F_21 ( V_6 , V_228 , V_71 , V_9 ) ;
if ( error )
goto V_179;
}
#endif
if ( V_57 < V_135 ) {
F_92 ( V_6 , V_227 , - 1 , V_135 - V_57 ) ;
F_94 ( V_6 , V_228 , - 1 , V_135 - V_57 ) ;
F_95 ( V_6 , V_11 , V_57 , V_135 - 1 ) ;
F_103 ( V_6 , V_11 , V_57 , V_135 - 1 ) ;
}
} else {
if ( V_57 < V_135 ) {
F_93 ( V_6 ,
F_45 ( V_6 , V_57 + 1 , V_8 ) ,
- 1 , V_135 - V_57 ) ;
F_102 ( V_6 , V_11 , V_57 , V_135 - 1 ) ;
}
}
F_129 ( V_8 , -- V_135 ) ;
F_104 ( V_6 , V_11 , V_232 ) ;
if ( F_82 ( V_6 , V_8 , V_9 ) ) {
V_6 -> V_28 -> V_214 ( V_6 , V_8 , NULL ,
V_57 , V_284 ) ;
}
if ( V_9 == V_6 -> V_72 - 1 ) {
if ( V_6 -> V_51 & V_106 ) {
F_148 ( V_6 -> V_44 . V_75 . V_102 , - 1 ,
V_6 -> V_44 . V_75 . V_103 ) ;
error = F_154 ( V_6 ) ;
if ( error )
goto V_179;
error = F_156 ( V_6 , V_9 , V_178 ) ;
if ( error )
goto V_179;
* V_178 = 1 ;
return 0 ;
}
if ( V_135 == 1 && V_9 > 0 ) {
union V_56 * V_186 ;
V_186 = F_48 ( V_6 , 1 , V_8 ) ;
error = F_155 ( V_6 , V_11 , V_9 , V_186 ) ;
if ( error )
goto V_179;
} else if ( V_9 > 0 ) {
error = F_156 ( V_6 , V_9 , V_178 ) ;
if ( error )
goto V_179;
}
* V_178 = 1 ;
return 0 ;
}
if ( F_119 ( V_6 , V_57 ) ) {
error = F_123 ( V_6 , V_9 ) ;
if ( error )
goto V_179;
}
if ( V_135 >= V_6 -> V_28 -> V_285 ( V_6 , V_9 ) ) {
error = F_156 ( V_6 , V_9 , V_178 ) ;
if ( error )
goto V_179;
return 0 ;
}
F_75 ( V_6 , V_8 , & V_236 , V_132 ) ;
F_75 ( V_6 , V_8 , & V_221 , V_131 ) ;
if ( V_6 -> V_51 & V_106 ) {
if ( F_73 ( V_6 , & V_236 ) &&
F_73 ( V_6 , & V_221 ) &&
V_9 == V_6 -> V_72 - 2 ) {
error = F_154 ( V_6 ) ;
if ( ! error )
error = F_156 ( V_6 , V_9 , V_178 ) ;
if ( error )
goto V_179;
return 0 ;
}
}
ASSERT ( ! F_73 ( V_6 , & V_236 ) ||
! F_73 ( V_6 , & V_221 ) ) ;
error = F_36 ( V_6 , & V_219 ) ;
if ( error )
goto V_179;
if ( ! F_73 ( V_6 , & V_236 ) ) {
V_71 = F_60 ( V_219 , V_9 ) ;
F_130 ( V_6 -> V_16 , V_71 == 1 , V_179 ) ;
error = F_107 ( V_219 , V_9 , & V_71 ) ;
if ( error )
goto V_179;
F_130 ( V_6 -> V_16 , V_71 == 1 , V_179 ) ;
V_71 = F_60 ( V_219 , V_9 ) ;
F_130 ( V_6 -> V_16 , V_71 == 1 , V_179 ) ;
V_127 = F_52 ( V_219 , V_9 , & V_218 ) ;
#ifdef F_109
error = F_17 ( V_219 , V_127 , V_9 , V_218 ) ;
if ( error )
goto V_179;
#endif
F_75 ( V_219 , V_127 , & V_282 , V_131 ) ;
if ( F_110 ( V_127 ) - 1 >=
V_6 -> V_28 -> V_285 ( V_219 , V_9 ) ) {
error = F_127 ( V_219 , V_9 , & V_71 ) ;
if ( error )
goto V_179;
if ( V_71 ) {
ASSERT ( F_110 ( V_8 ) >=
V_6 -> V_28 -> V_285 ( V_219 , V_9 ) ) ;
F_33 ( V_219 , V_234 ) ;
V_219 = NULL ;
error = F_156 ( V_6 , V_9 , V_178 ) ;
if ( error )
goto V_179;
return 0 ;
}
}
V_220 = F_110 ( V_127 ) ;
if ( ! F_73 ( V_6 , & V_221 ) ) {
V_71 = F_59 ( V_219 , V_9 ) ;
F_130 ( V_6 -> V_16 , V_71 == 1 , V_179 ) ;
error = F_111 ( V_219 , V_9 , & V_71 ) ;
if ( error )
goto V_179;
F_130 ( V_6 -> V_16 , V_71 == 1 , V_179 ) ;
}
}
if ( ! F_73 ( V_6 , & V_221 ) ) {
V_71 = F_59 ( V_219 , V_9 ) ;
F_130 ( V_6 -> V_16 , V_71 == 1 , V_179 ) ;
error = F_111 ( V_219 , V_9 , & V_71 ) ;
if ( error )
goto V_179;
V_71 = F_59 ( V_219 , V_9 ) ;
F_130 ( V_6 -> V_16 , V_71 == 1 , V_179 ) ;
V_126 = F_52 ( V_219 , V_9 , & V_216 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_126 , V_9 , V_216 ) ;
if ( error )
goto V_179;
#endif
F_75 ( V_219 , V_126 , & V_282 , V_132 ) ;
if ( F_110 ( V_126 ) - 1 >=
V_6 -> V_28 -> V_285 ( V_219 , V_9 ) ) {
error = F_131 ( V_219 , V_9 , & V_71 ) ;
if ( error )
goto V_179;
if ( V_71 ) {
ASSERT ( F_110 ( V_8 ) >=
V_6 -> V_28 -> V_285 ( V_219 , V_9 ) ) ;
F_33 ( V_219 , V_234 ) ;
V_219 = NULL ;
if ( V_9 == 0 )
V_6 -> V_83 [ 0 ] ++ ;
F_96 ( V_6 , V_170 ) ;
* V_178 = 1 ;
return 0 ;
}
}
V_217 = F_110 ( V_126 ) ;
}
F_33 ( V_219 , V_234 ) ;
V_219 = NULL ;
ASSERT ( ! F_73 ( V_6 , & V_282 ) ) ;
if ( ! F_73 ( V_6 , & V_221 ) &&
V_217 + F_110 ( V_8 ) <=
V_6 -> V_28 -> V_29 ( V_6 , V_9 ) ) {
V_236 = V_282 ;
V_127 = V_8 ;
V_218 = V_11 ;
error = F_88 ( V_6 , & V_221 , 0 , & V_126 , & V_216 ) ;
if ( error )
goto V_179;
} else if ( ! F_73 ( V_6 , & V_236 ) &&
V_220 + F_110 ( V_8 ) <=
V_6 -> V_28 -> V_29 ( V_6 , V_9 ) ) {
V_221 = V_282 ;
V_126 = V_8 ;
V_216 = V_11 ;
error = F_88 ( V_6 , & V_236 , 0 , & V_127 , & V_218 ) ;
if ( error )
goto V_179;
} else {
error = F_156 ( V_6 , V_9 , V_178 ) ;
if ( error )
goto V_179;
return 0 ;
}
V_220 = F_110 ( V_127 ) ;
V_217 = F_110 ( V_126 ) ;
F_128 ( V_6 , V_226 , V_220 ) ;
if ( V_9 > 0 ) {
union V_99 * V_227 ;
union V_56 * V_228 ;
union V_99 * V_222 ;
union V_56 * V_223 ;
V_227 = F_46 ( V_6 , V_217 + 1 , V_126 ) ;
V_228 = F_48 ( V_6 , V_217 + 1 , V_126 ) ;
V_222 = F_46 ( V_6 , 1 , V_127 ) ;
V_223 = F_48 ( V_6 , 1 , V_127 ) ;
#ifdef F_109
for ( V_71 = 1 ; V_71 < V_220 ; V_71 ++ ) {
error = F_21 ( V_6 , V_223 , V_71 , V_9 ) ;
if ( error )
goto V_179;
}
#endif
F_89 ( V_6 , V_227 , V_222 , V_220 ) ;
F_91 ( V_6 , V_228 , V_223 , V_220 ) ;
F_95 ( V_6 , V_216 , V_217 + 1 , V_217 + V_220 ) ;
F_103 ( V_6 , V_216 , V_217 + 1 , V_217 + V_220 ) ;
} else {
union V_98 * V_230 ;
union V_98 * V_224 ;
V_230 = F_45 ( V_6 , V_217 + 1 , V_126 ) ;
V_224 = F_45 ( V_6 , 1 , V_127 ) ;
F_90 ( V_6 , V_230 , V_224 , V_220 ) ;
F_102 ( V_6 , V_216 , V_217 + 1 , V_217 + V_220 ) ;
}
F_32 ( V_6 , V_286 ) ;
F_129 ( V_126 , V_217 + V_220 ) ;
F_75 ( V_6 , V_127 , & V_282 , V_132 ) ,
F_76 ( V_6 , V_126 , & V_282 , V_132 ) ;
F_104 ( V_6 , V_216 , V_232 | V_132 ) ;
F_75 ( V_6 , V_126 , & V_282 , V_132 ) ;
if ( ! F_73 ( V_6 , & V_282 ) ) {
error = F_88 ( V_6 , & V_282 , 0 , & V_241 , & V_240 ) ;
if ( error )
goto V_179;
F_76 ( V_6 , V_241 , & V_221 , V_131 ) ;
F_104 ( V_6 , V_240 , V_131 ) ;
}
error = F_30 ( V_6 , V_218 ) ;
if ( error )
goto V_179;
if ( V_11 != V_216 ) {
V_6 -> V_73 [ V_9 ] = V_216 ;
V_6 -> V_83 [ V_9 ] += V_217 ;
V_6 -> V_84 [ V_9 ] = 0 ;
}
else if ( ( V_6 -> V_51 & V_106 ) ||
( V_9 + 1 < V_6 -> V_72 ) ) {
error = F_107 ( V_6 , V_9 + 1 , & V_71 ) ;
if ( error )
goto V_179;
}
if ( V_9 > 0 )
V_6 -> V_83 [ V_9 ] -- ;
F_96 ( V_6 , V_170 ) ;
* V_178 = 2 ;
return 0 ;
V_179:
F_96 ( V_6 , V_184 ) ;
if ( V_219 )
F_33 ( V_219 , V_235 ) ;
return error ;
}
int
F_158 (
struct V_5 * V_6 ,
int * V_178 )
{
int error ;
int V_9 ;
int V_71 ;
bool V_287 = false ;
F_96 ( V_6 , V_168 ) ;
for ( V_9 = 0 , V_71 = 2 ; V_71 == 2 ; V_9 ++ ) {
error = F_157 ( V_6 , V_9 , & V_71 ) ;
if ( error )
goto V_179;
if ( V_71 == 2 )
V_287 = true ;
}
if ( V_287 && ( V_6 -> V_51 & V_202 ) ) {
error = F_122 ( V_6 , 0 ) ;
if ( error )
goto V_179;
}
if ( V_71 == 0 ) {
for ( V_9 = 1 ; V_9 < V_6 -> V_72 ; V_9 ++ ) {
if ( V_6 -> V_83 [ V_9 ] == 0 ) {
error = F_111 ( V_6 , V_9 , & V_71 ) ;
if ( error )
goto V_179;
break;
}
}
}
F_96 ( V_6 , V_170 ) ;
* V_178 = V_71 ;
return 0 ;
V_179:
F_96 ( V_6 , V_184 ) ;
return error ;
}
int
F_159 (
struct V_5 * V_6 ,
union V_98 * * V_288 ,
int * V_178 )
{
struct V_7 * V_8 ;
struct V_10 * V_11 ;
int V_57 ;
#ifdef F_109
int error ;
#endif
V_57 = V_6 -> V_83 [ 0 ] ;
V_8 = F_52 ( V_6 , 0 , & V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , 0 , V_11 ) ;
if ( error )
return error ;
#endif
if ( V_57 > F_110 ( V_8 ) || V_57 <= 0 ) {
* V_178 = 0 ;
return 0 ;
}
* V_288 = F_45 ( V_6 , V_57 , V_8 ) ;
* V_178 = 1 ;
return 0 ;
}
STATIC int
F_160 (
struct V_5 * V_6 ,
int V_9 ,
T_19 V_289 ,
void * V_290 )
{
struct V_7 * V_8 ;
struct V_10 * V_11 ;
union V_56 V_236 ;
int error ;
F_69 ( V_6 , V_9 , V_129 ) ;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
error = V_289 ( V_6 , V_9 , V_290 ) ;
if ( error )
return error ;
F_75 ( V_6 , V_8 , & V_236 , V_132 ) ;
if ( F_73 ( V_6 , & V_236 ) )
return - V_291 ;
return F_112 ( V_6 , V_9 , & V_236 , & V_8 ) ;
}
int
F_161 (
struct V_5 * V_6 ,
T_19 V_289 ,
void * V_290 )
{
union V_56 V_221 ;
int V_9 ;
struct V_7 * V_8 = NULL ;
int error = 0 ;
V_6 -> V_28 -> V_194 ( V_6 , & V_221 ) ;
for ( V_9 = V_6 -> V_72 - 1 ; V_9 >= 0 ; V_9 -- ) {
error = F_112 ( V_6 , V_9 , & V_221 , & V_8 ) ;
if ( error )
return error ;
if ( V_9 > 0 ) {
union V_56 * V_57 ;
V_57 = F_48 ( V_6 , 1 , V_8 ) ;
F_71 ( V_6 , V_57 , 1 ) ;
F_91 ( V_6 , & V_221 , V_57 , 1 ) ;
}
do {
error = F_160 ( V_6 , V_9 , V_289 , V_290 ) ;
} while ( ! error );
if ( error != - V_291 )
return error ;
}
return 0 ;
}
static int
F_162 (
struct V_5 * V_6 ,
int V_9 ,
void * V_290 )
{
struct V_292 * V_293 = V_290 ;
struct V_7 * V_8 ;
struct V_10 * V_11 ;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
if ( V_6 -> V_51 & V_52 )
V_8 -> V_18 . V_19 . V_138 = F_5 ( V_293 -> V_294 ) ;
else
V_8 -> V_18 . V_47 . V_138 = F_16 ( V_293 -> V_294 ) ;
if ( V_11 ) {
if ( V_6 -> V_70 ) {
F_163 ( V_6 -> V_70 , V_11 ) ;
F_104 ( V_6 , V_11 , V_295 ) ;
} else {
F_164 ( V_11 , V_293 -> V_296 ) ;
}
} else {
ASSERT ( V_6 -> V_51 & V_106 ) ;
ASSERT ( V_9 == V_6 -> V_72 - 1 ) ;
}
return 0 ;
}
int
F_165 (
struct V_5 * V_6 ,
T_20 V_294 ,
struct V_297 * V_296 )
{
struct V_292 V_293 ;
V_293 . V_294 = V_294 ;
V_293 . V_296 = V_296 ;
return F_161 ( V_6 , F_162 ,
& V_293 ) ;
}
bool
F_166 (
struct V_10 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_62 -> V_63 ;
struct V_7 * V_8 = F_23 ( V_11 ) ;
struct V_298 * V_299 = V_11 -> V_300 ;
if ( ! F_3 ( & V_14 -> V_17 ) )
return false ;
if ( ! F_4 ( & V_8 -> V_18 . V_47 . V_20 , & V_14 -> V_17 . V_21 ) )
return false ;
if ( V_8 -> V_18 . V_47 . V_22 != F_5 ( V_11 -> V_23 ) )
return false ;
if ( V_299 && F_6 ( V_8 -> V_18 . V_47 . V_138 ) != V_299 -> V_301 )
return false ;
return true ;
}
bool
F_167 (
struct V_10 * V_11 ,
unsigned int V_302 )
{
struct V_13 * V_14 = V_11 -> V_62 -> V_63 ;
struct V_7 * V_8 = F_23 ( V_11 ) ;
if ( F_7 ( V_8 -> V_27 ) > V_302 )
return false ;
if ( ! V_8 -> V_18 . V_47 . V_30 ||
( F_6 ( V_8 -> V_18 . V_47 . V_30 ) >= V_14 -> V_17 . V_55 &&
V_8 -> V_18 . V_47 . V_30 != F_16 ( V_48 ) ) )
return false ;
if ( ! V_8 -> V_18 . V_47 . V_32 ||
( F_6 ( V_8 -> V_18 . V_47 . V_32 ) >= V_14 -> V_17 . V_55 &&
V_8 -> V_18 . V_47 . V_32 != F_16 ( V_48 ) ) )
return false ;
return true ;
}
T_10
F_168 (
struct V_13 * V_14 ,
T_10 * V_303 ,
unsigned long V_304 )
{
T_10 V_9 ;
unsigned long V_305 ;
V_305 = ( V_304 + V_303 [ 0 ] - 1 ) / V_303 [ 0 ] ;
for ( V_9 = 1 ; V_305 > 1 ; V_9 ++ )
V_305 = ( V_305 + V_303 [ 1 ] - 1 ) / V_303 [ 1 ] ;
return V_9 ;
}
STATIC int
F_169 (
struct V_5 * V_6 ,
union V_99 * V_306 ,
union V_99 * V_307 ,
T_21 V_289 ,
void * V_308 )
{
union V_98 * V_288 ;
union V_99 V_309 ;
T_13 V_192 ;
int V_178 ;
bool V_310 = true ;
int error ;
ASSERT ( V_6 -> V_28 -> V_205 ) ;
ASSERT ( V_6 -> V_28 -> V_206 ) ;
V_178 = 0 ;
error = F_114 ( V_6 , V_197 , & V_178 ) ;
if ( error )
goto V_311;
if ( ! V_178 ) {
error = F_107 ( V_6 , 0 , & V_178 ) ;
if ( error )
goto V_311;
}
while ( V_178 ) {
error = F_159 ( V_6 , & V_288 , & V_178 ) ;
if ( error || ! V_178 )
break;
if ( V_310 ) {
V_6 -> V_28 -> V_205 ( & V_309 , V_288 ) ;
V_310 = false ;
V_192 = V_6 -> V_28 -> V_206 ( V_6 , V_306 ,
& V_309 ) ;
if ( V_192 > 0 )
goto V_312;
}
V_6 -> V_28 -> V_191 ( & V_309 , V_288 ) ;
V_192 = V_6 -> V_28 -> V_206 ( V_6 , & V_309 , V_307 ) ;
if ( V_192 > 0 )
break;
error = V_289 ( V_6 , V_288 , V_308 ) ;
if ( error < 0 || error == V_313 )
break;
V_312:
error = F_107 ( V_6 , 0 , & V_178 ) ;
if ( error )
break;
}
V_311:
return error ;
}
STATIC int
F_170 (
struct V_5 * V_6 ,
union V_99 * V_306 ,
union V_99 * V_307 ,
T_21 V_289 ,
void * V_308 )
{
union V_56 V_57 ;
union V_56 * V_186 ;
union V_99 V_309 ;
union V_99 V_314 ;
union V_99 * V_227 ;
union V_99 * V_315 ;
union V_98 * V_288 ;
struct V_7 * V_8 ;
T_13 V_316 ;
T_13 V_317 ;
int V_9 ;
struct V_10 * V_11 ;
int V_71 ;
int error ;
V_9 = V_6 -> V_72 - 1 ;
V_6 -> V_28 -> V_194 ( V_6 , & V_57 ) ;
error = F_112 ( V_6 , V_9 , & V_57 , & V_8 ) ;
if ( error )
return error ;
F_52 ( V_6 , V_9 , & V_11 ) ;
F_171 ( V_6 , V_9 , V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error )
goto V_311;
#endif
V_6 -> V_83 [ V_9 ] = 1 ;
while ( V_9 < V_6 -> V_72 ) {
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
if ( V_6 -> V_83 [ V_9 ] > F_7 ( V_8 -> V_27 ) ) {
V_318:
if ( V_9 < V_6 -> V_72 - 1 )
V_6 -> V_83 [ V_9 + 1 ] ++ ;
V_9 ++ ;
continue;
}
if ( V_9 == 0 ) {
V_288 = F_45 ( V_6 , V_6 -> V_83 [ 0 ] , V_8 ) ;
V_6 -> V_28 -> V_205 ( & V_314 , V_288 ) ;
V_316 = V_6 -> V_28 -> V_206 ( V_6 , & V_314 ,
V_306 ) ;
V_6 -> V_28 -> V_191 ( & V_309 , V_288 ) ;
V_317 = V_6 -> V_28 -> V_206 ( V_6 , V_307 ,
& V_309 ) ;
if ( V_316 >= 0 && V_317 >= 0 ) {
error = V_289 ( V_6 , V_288 , V_308 ) ;
if ( error < 0 ||
error == V_313 )
break;
} else if ( V_317 < 0 ) {
goto V_318;
}
V_6 -> V_83 [ V_9 ] ++ ;
continue;
}
V_227 = F_46 ( V_6 , V_6 -> V_83 [ V_9 ] , V_8 ) ;
V_315 = F_47 ( V_6 , V_6 -> V_83 [ V_9 ] , V_8 ) ;
V_186 = F_48 ( V_6 , V_6 -> V_83 [ V_9 ] , V_8 ) ;
V_316 = V_6 -> V_28 -> V_206 ( V_6 , V_315 , V_306 ) ;
V_317 = V_6 -> V_28 -> V_206 ( V_6 , V_307 , V_227 ) ;
if ( V_316 >= 0 && V_317 >= 0 ) {
V_9 -- ;
error = F_112 ( V_6 , V_9 , V_186 ,
& V_8 ) ;
if ( error )
goto V_311;
F_52 ( V_6 , V_9 , & V_11 ) ;
F_171 ( V_6 , V_9 , V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error )
goto V_311;
#endif
V_6 -> V_83 [ V_9 ] = 1 ;
continue;
} else if ( V_317 < 0 ) {
goto V_318;
}
V_6 -> V_83 [ V_9 ] ++ ;
}
V_311:
if ( V_6 -> V_73 [ 0 ] == NULL ) {
for ( V_71 = 0 ; V_71 < V_6 -> V_72 ; V_71 ++ ) {
if ( V_6 -> V_73 [ V_71 ] ) {
F_34 ( V_6 -> V_70 , V_6 -> V_73 [ V_71 ] ) ;
V_6 -> V_73 [ V_71 ] = NULL ;
V_6 -> V_83 [ V_71 ] = 0 ;
V_6 -> V_84 [ V_71 ] = 0 ;
}
}
}
return error ;
}
int
F_172 (
struct V_5 * V_6 ,
union V_319 * V_320 ,
union V_319 * V_321 ,
T_21 V_289 ,
void * V_308 )
{
union V_98 V_167 ;
union V_99 V_306 ;
union V_99 V_307 ;
V_6 -> V_82 = * V_321 ;
V_6 -> V_28 -> V_279 ( V_6 , & V_167 ) ;
V_6 -> V_28 -> V_191 ( & V_307 , & V_167 ) ;
V_6 -> V_82 = * V_320 ;
V_6 -> V_28 -> V_279 ( V_6 , & V_167 ) ;
V_6 -> V_28 -> V_191 ( & V_306 , & V_167 ) ;
if ( V_6 -> V_28 -> V_206 ( V_6 , & V_306 , & V_307 ) > 0 )
return - V_322 ;
if ( ! ( V_6 -> V_51 & V_202 ) )
return F_169 ( V_6 , & V_306 ,
& V_307 , V_289 , V_308 ) ;
return F_170 ( V_6 , & V_306 , & V_307 ,
V_289 , V_308 ) ;
}
int
F_173 (
struct V_5 * V_6 ,
T_21 V_289 ,
void * V_308 )
{
union V_319 V_320 ;
union V_319 V_321 ;
memset ( & V_320 , 0 , sizeof( V_320 ) ) ;
memset ( & V_321 , 0xFF , sizeof( V_321 ) ) ;
return F_172 ( V_6 , & V_320 , & V_321 , V_289 , V_308 ) ;
}
T_14
F_174 (
struct V_13 * V_14 ,
T_10 * V_303 ,
unsigned long long V_304 )
{
int V_9 ;
int V_323 ;
T_14 V_125 ;
V_323 = V_303 [ 0 ] ;
for ( V_9 = 0 , V_125 = 0 ; V_304 > 1 ; V_9 ++ ) {
V_304 += V_323 - 1 ;
F_175 ( V_304 , V_323 ) ;
V_323 = V_303 [ 1 ] ;
V_125 += V_304 ;
}
return V_125 ;
}
static int
F_176 (
struct V_5 * V_6 ,
int V_9 ,
void * V_290 )
{
T_14 * V_324 = V_290 ;
( * V_324 ) ++ ;
return 0 ;
}
int
F_177 (
struct V_5 * V_6 ,
T_14 * V_324 )
{
* V_324 = 0 ;
return F_161 ( V_6 , F_176 ,
V_324 ) ;
}
