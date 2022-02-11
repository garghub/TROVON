STATIC int
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
struct V_6 * V_7 )
{
int V_8 = 1 ;
struct V_9 * V_10 ;
V_10 = V_2 -> V_11 ;
if ( F_2 ( & V_10 -> V_12 ) ) {
V_8 = V_8 &&
F_3 ( & V_4 -> V_13 . V_14 . V_15 ,
& V_10 -> V_12 . V_16 ) &&
V_4 -> V_13 . V_14 . V_17 == F_4 (
V_7 ? V_7 -> V_18 : V_19 ) ;
}
V_8 = V_8 &&
F_5 ( V_4 -> V_20 ) == F_6 ( V_2 ) &&
F_7 ( V_4 -> V_21 ) == V_5 &&
F_7 ( V_4 -> V_22 ) <=
V_2 -> V_23 -> V_24 ( V_2 , V_5 ) &&
V_4 -> V_13 . V_14 . V_25 &&
( V_4 -> V_13 . V_14 . V_25 == F_4 ( V_26 ) ||
F_8 ( V_10 ,
F_9 ( V_4 -> V_13 . V_14 . V_25 ) ) ) &&
V_4 -> V_13 . V_14 . V_27 &&
( V_4 -> V_13 . V_14 . V_27 == F_4 ( V_26 ) ||
F_8 ( V_10 ,
F_9 ( V_4 -> V_13 . V_14 . V_27 ) ) ) ;
if ( F_10 ( F_11 ( ! V_8 , V_10 ,
V_28 ,
V_29 ) ) ) {
if ( V_7 )
F_12 ( V_7 , V_30 ) ;
F_13 ( V_31 , V_32 , V_10 ) ;
return - V_33 ;
}
return 0 ;
}
STATIC int
F_14 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
struct V_6 * V_7 )
{
struct V_9 * V_10 ;
struct V_6 * V_34 ;
struct V_35 * V_36 ;
T_1 V_37 ;
int V_38 = 1 ;
V_10 = V_2 -> V_11 ;
V_34 = V_2 -> V_39 . V_40 . V_34 ;
V_36 = F_15 ( V_34 ) ;
V_37 = F_5 ( V_36 -> V_41 ) ;
if ( F_2 ( & V_10 -> V_12 ) ) {
V_38 = V_38 &&
F_3 ( & V_4 -> V_13 . V_42 . V_15 ,
& V_10 -> V_12 . V_16 ) &&
V_4 -> V_13 . V_42 . V_17 == F_4 (
V_7 ? V_7 -> V_18 : V_19 ) ;
}
V_38 = V_38 &&
F_5 ( V_4 -> V_20 ) == F_6 ( V_2 ) &&
F_7 ( V_4 -> V_21 ) == V_5 &&
F_7 ( V_4 -> V_22 ) <=
V_2 -> V_23 -> V_24 ( V_2 , V_5 ) &&
( V_4 -> V_13 . V_42 . V_25 == F_16 ( V_43 ) ||
F_5 ( V_4 -> V_13 . V_42 . V_25 ) < V_37 ) &&
V_4 -> V_13 . V_42 . V_25 &&
( V_4 -> V_13 . V_42 . V_27 == F_16 ( V_43 ) ||
F_5 ( V_4 -> V_13 . V_42 . V_27 ) < V_37 ) &&
V_4 -> V_13 . V_42 . V_27 ;
if ( F_10 ( F_11 ( ! V_38 , V_10 ,
V_44 ,
V_45 ) ) ) {
if ( V_7 )
F_12 ( V_7 , V_30 ) ;
F_13 ( V_31 , V_32 , V_10 ) ;
return - V_33 ;
}
return 0 ;
}
int
F_17 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
struct V_6 * V_7 )
{
if ( V_2 -> V_46 & V_47 )
return F_1 ( V_2 , V_4 , V_5 , V_7 ) ;
else
return F_14 ( V_2 , V_4 , V_5 , V_7 ) ;
}
int
F_18 (
struct V_1 * V_2 ,
T_2 V_48 ,
int V_5 )
{
F_19 ( V_2 -> V_11 ,
V_5 > 0 &&
V_48 != V_26 &&
F_8 ( V_2 -> V_11 , V_48 ) ) ;
return 0 ;
}
STATIC int
F_20 (
struct V_1 * V_2 ,
T_1 V_48 ,
int V_5 )
{
T_1 V_49 = V_2 -> V_11 -> V_12 . V_50 ;
F_19 ( V_2 -> V_11 ,
V_5 > 0 &&
V_48 != V_43 &&
V_48 != 0 &&
V_48 < V_49 ) ;
return 0 ;
}
STATIC int
F_21 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
int V_53 ,
int V_5 )
{
if ( V_2 -> V_46 & V_47 ) {
return F_18 ( V_2 ,
F_9 ( ( & V_52 -> V_14 ) [ V_53 ] ) , V_5 ) ;
} else {
return F_20 ( V_2 ,
F_5 ( ( & V_52 -> V_42 ) [ V_53 ] ) , V_5 ) ;
}
}
void
F_22 (
struct V_6 * V_7 )
{
struct V_3 * V_4 = F_23 ( V_7 ) ;
struct V_54 * V_55 = V_7 -> V_56 ;
if ( ! F_2 ( & V_7 -> V_57 -> V_58 -> V_12 ) )
return;
if ( V_55 )
V_4 -> V_13 . V_14 . V_59 = F_4 ( V_55 -> V_60 . V_61 ) ;
F_24 ( V_7 , V_62 ) ;
}
bool
F_25 (
struct V_6 * V_7 )
{
struct V_3 * V_4 = F_23 ( V_7 ) ;
struct V_9 * V_10 = V_7 -> V_57 -> V_58 ;
if ( F_2 ( & V_10 -> V_12 ) ) {
if ( ! F_26 ( V_10 , F_9 ( V_4 -> V_13 . V_14 . V_59 ) ) )
return false ;
return F_27 ( V_7 , V_62 ) ;
}
return true ;
}
void
F_28 (
struct V_6 * V_7 )
{
struct V_3 * V_4 = F_23 ( V_7 ) ;
struct V_54 * V_55 = V_7 -> V_56 ;
if ( ! F_2 ( & V_7 -> V_57 -> V_58 -> V_12 ) )
return;
if ( V_55 )
V_4 -> V_13 . V_42 . V_59 = F_4 ( V_55 -> V_60 . V_61 ) ;
F_24 ( V_7 , V_63 ) ;
}
bool
F_29 (
struct V_6 * V_7 )
{
struct V_3 * V_4 = F_23 ( V_7 ) ;
struct V_9 * V_10 = V_7 -> V_57 -> V_58 ;
if ( F_2 ( & V_10 -> V_12 ) ) {
if ( ! F_26 ( V_10 , F_9 ( V_4 -> V_13 . V_42 . V_59 ) ) )
return false ;
return F_27 ( V_7 , V_63 ) ;
}
return true ;
}
static int
F_30 (
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int error ;
error = V_2 -> V_23 -> V_64 ( V_2 , V_7 ) ;
if ( ! error ) {
F_31 ( V_2 -> V_65 , V_7 ) ;
F_32 ( V_2 , free ) ;
}
return error ;
}
void
F_33 (
T_3 * V_2 ,
int error )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_2 -> V_67 ; V_66 ++ ) {
if ( V_2 -> V_68 [ V_66 ] )
F_34 ( V_2 -> V_65 , V_2 -> V_68 [ V_66 ] ) ;
else if ( ! error )
break;
}
ASSERT ( V_2 -> V_69 != V_70 ||
V_2 -> V_39 . V_71 . V_72 == 0 ) ;
F_35 ( V_73 , V_2 ) ;
}
int
F_36 (
T_3 * V_2 ,
T_3 * * V_74 )
{
T_4 * V_7 ;
int error ;
int V_66 ;
T_5 * V_10 ;
T_3 * V_75 ;
T_6 * V_76 ;
V_76 = V_2 -> V_65 ;
V_10 = V_2 -> V_11 ;
V_75 = V_2 -> V_23 -> V_77 ( V_2 ) ;
V_75 -> V_78 = V_2 -> V_78 ;
for ( V_66 = 0 ; V_66 < V_75 -> V_67 ; V_66 ++ ) {
V_75 -> V_79 [ V_66 ] = V_2 -> V_79 [ V_66 ] ;
V_75 -> V_80 [ V_66 ] = V_2 -> V_80 [ V_66 ] ;
V_7 = V_2 -> V_68 [ V_66 ] ;
if ( V_7 ) {
error = F_37 ( V_10 , V_76 , V_10 -> V_81 ,
F_38 ( V_7 ) , V_10 -> V_82 ,
0 , & V_7 ,
V_2 -> V_23 -> V_83 ) ;
if ( error ) {
F_33 ( V_75 , error ) ;
* V_74 = NULL ;
return error ;
}
}
V_75 -> V_68 [ V_66 ] = V_7 ;
}
* V_74 = V_75 ;
return 0 ;
}
static inline T_7 F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 & V_47 ) {
if ( V_2 -> V_46 & V_84 )
return V_85 ;
return V_86 ;
}
if ( V_2 -> V_46 & V_84 )
return V_87 ;
return V_88 ;
}
static inline T_7 F_40 ( struct V_1 * V_2 )
{
return ( V_2 -> V_46 & V_47 ) ?
sizeof( V_89 ) : sizeof( V_90 ) ;
}
STATIC T_7
F_41 (
struct V_1 * V_2 ,
int V_91 )
{
return F_39 ( V_2 ) +
( V_91 - 1 ) * V_2 -> V_23 -> V_92 ;
}
STATIC T_7
F_42 (
struct V_1 * V_2 ,
int V_91 )
{
return F_39 ( V_2 ) +
( V_91 - 1 ) * V_2 -> V_23 -> V_93 ;
}
STATIC T_7
F_43 (
struct V_1 * V_2 ,
int V_91 )
{
return F_39 ( V_2 ) +
( V_91 - 1 ) * V_2 -> V_23 -> V_93 + ( V_2 -> V_23 -> V_93 / 2 ) ;
}
STATIC T_7
F_44 (
struct V_1 * V_2 ,
int V_91 ,
int V_5 )
{
return F_39 ( V_2 ) +
V_2 -> V_23 -> V_24 ( V_2 , V_5 ) * V_2 -> V_23 -> V_93 +
( V_91 - 1 ) * F_40 ( V_2 ) ;
}
STATIC union V_94 *
F_45 (
struct V_1 * V_2 ,
int V_91 ,
struct V_3 * V_4 )
{
return (union V_94 * )
( ( char * ) V_4 + F_41 ( V_2 , V_91 ) ) ;
}
STATIC union V_95 *
F_46 (
struct V_1 * V_2 ,
int V_91 ,
struct V_3 * V_4 )
{
return (union V_95 * )
( ( char * ) V_4 + F_42 ( V_2 , V_91 ) ) ;
}
STATIC union V_95 *
F_47 (
struct V_1 * V_2 ,
int V_91 ,
struct V_3 * V_4 )
{
return (union V_95 * )
( ( char * ) V_4 + F_43 ( V_2 , V_91 ) ) ;
}
STATIC union V_51 *
F_48 (
struct V_1 * V_2 ,
int V_91 ,
struct V_3 * V_4 )
{
int V_5 = F_49 ( V_4 ) ;
ASSERT ( V_4 -> V_21 != 0 ) ;
return (union V_51 * )
( ( char * ) V_4 + F_44 ( V_2 , V_91 , V_5 ) ) ;
}
STATIC struct V_3 *
F_50 (
struct V_1 * V_2 )
{
struct V_96 * V_97 ;
V_97 = F_51 ( V_2 -> V_39 . V_71 . V_98 , V_2 -> V_39 . V_71 . V_99 ) ;
return (struct V_3 * ) V_97 -> V_100 ;
}
STATIC struct V_3 *
F_52 (
struct V_1 * V_2 ,
int V_5 ,
struct V_6 * * V_101 )
{
if ( ( V_2 -> V_46 & V_102 ) &&
( V_5 == V_2 -> V_67 - 1 ) ) {
* V_101 = NULL ;
return F_50 ( V_2 ) ;
}
* V_101 = V_2 -> V_68 [ V_5 ] ;
return F_23 ( * V_101 ) ;
}
T_4 *
F_53 (
T_5 * V_10 ,
T_6 * V_76 ,
T_2 V_103 ,
T_8 V_104 )
{
T_9 V_105 ;
ASSERT ( V_103 != V_26 ) ;
V_105 = F_54 ( V_10 , V_103 ) ;
return F_55 ( V_76 , V_10 -> V_81 , V_105 , V_10 -> V_82 , V_104 ) ;
}
T_4 *
F_56 (
T_5 * V_10 ,
T_6 * V_76 ,
T_10 V_106 ,
T_1 V_107 ,
T_8 V_104 )
{
T_9 V_105 ;
ASSERT ( V_106 != V_108 ) ;
ASSERT ( V_107 != V_43 ) ;
V_105 = F_57 ( V_10 , V_106 , V_107 ) ;
return F_55 ( V_76 , V_10 -> V_81 , V_105 , V_10 -> V_82 , V_104 ) ;
}
int
F_58 (
T_3 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
V_4 = F_52 ( V_2 , V_5 , & V_7 ) ;
F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( V_2 -> V_46 & V_47 )
return V_4 -> V_13 . V_14 . V_27 == F_4 ( V_26 ) ;
else
return V_4 -> V_13 . V_42 . V_27 == F_16 ( V_43 ) ;
}
STATIC int
F_59 (
T_3 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
V_4 = F_52 ( V_2 , V_5 , & V_7 ) ;
F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( ! V_4 -> V_22 )
return 0 ;
V_2 -> V_79 [ V_5 ] = 1 ;
return 1 ;
}
STATIC int
F_60 (
T_3 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
V_4 = F_52 ( V_2 , V_5 , & V_7 ) ;
F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( ! V_4 -> V_22 )
return 0 ;
V_2 -> V_79 [ V_5 ] = F_7 ( V_4 -> V_22 ) ;
return 1 ;
}
void
F_61 (
T_11 V_109 ,
const short * V_110 ,
int V_111 ,
int * V_112 ,
int * V_113 )
{
int V_66 ;
T_11 V_114 ;
ASSERT ( V_109 != 0 ) ;
for ( V_66 = 0 , V_114 = 1LL ; ; V_66 ++ , V_114 <<= 1 ) {
if ( V_114 & V_109 ) {
* V_112 = V_110 [ V_66 ] ;
break;
}
}
for ( V_66 = V_111 - 1 , V_114 = 1LL << V_66 ; ; V_66 -- , V_114 >>= 1 ) {
if ( V_114 & V_109 ) {
* V_113 = V_110 [ V_66 + 1 ] - 1 ;
break;
}
}
}
int
F_62 (
struct V_9 * V_10 ,
struct V_115 * V_76 ,
T_2 V_103 ,
T_8 V_104 ,
struct V_6 * * V_101 ,
int V_116 ,
const struct V_117 * V_118 )
{
struct V_6 * V_7 ;
T_9 V_105 ;
int error ;
ASSERT ( V_103 != V_26 ) ;
V_105 = F_54 ( V_10 , V_103 ) ;
error = F_37 ( V_10 , V_76 , V_10 -> V_81 , V_105 ,
V_10 -> V_82 , V_104 , & V_7 , V_118 ) ;
if ( error )
return error ;
if ( V_7 )
F_63 ( V_7 , V_116 ) ;
* V_101 = V_7 ;
return 0 ;
}
void
F_64 (
struct V_9 * V_10 ,
T_2 V_103 ,
T_12 V_119 ,
const struct V_117 * V_118 )
{
T_9 V_105 ;
ASSERT ( V_103 != V_26 ) ;
V_105 = F_54 ( V_10 , V_103 ) ;
F_65 ( V_10 -> V_81 , V_105 , V_10 -> V_82 * V_119 , V_118 ) ;
}
void
F_66 (
struct V_9 * V_10 ,
T_10 V_106 ,
T_1 V_107 ,
T_12 V_119 ,
const struct V_117 * V_118 )
{
T_9 V_105 ;
ASSERT ( V_106 != V_108 ) ;
ASSERT ( V_107 != V_43 ) ;
V_105 = F_57 ( V_10 , V_106 , V_107 ) ;
F_65 ( V_10 -> V_81 , V_105 , V_10 -> V_82 * V_119 , V_118 ) ;
}
STATIC int
F_67 (
struct V_1 * V_2 ,
int V_120 ,
struct V_3 * V_4 )
{
int V_121 = 0 ;
T_2 V_122 = F_9 ( V_4 -> V_13 . V_14 . V_25 ) ;
T_2 V_123 = F_9 ( V_4 -> V_13 . V_14 . V_27 ) ;
if ( ( V_120 & V_124 ) && V_122 != V_26 ) {
F_64 ( V_2 -> V_11 , V_122 , 1 ,
V_2 -> V_23 -> V_83 ) ;
V_121 ++ ;
}
if ( ( V_120 & V_125 ) && V_123 != V_26 ) {
F_64 ( V_2 -> V_11 , V_123 , 1 ,
V_2 -> V_23 -> V_83 ) ;
V_121 ++ ;
}
return V_121 ;
}
STATIC int
F_68 (
struct V_1 * V_2 ,
int V_120 ,
struct V_3 * V_4 )
{
int V_121 = 0 ;
T_1 V_122 = F_5 ( V_4 -> V_13 . V_42 . V_25 ) ;
T_1 V_123 = F_5 ( V_4 -> V_13 . V_42 . V_27 ) ;
if ( ( V_120 & V_124 ) && V_122 != V_43 ) {
F_66 ( V_2 -> V_11 , V_2 -> V_39 . V_40 . V_106 ,
V_122 , 1 , V_2 -> V_23 -> V_83 ) ;
V_121 ++ ;
}
if ( ( V_120 & V_125 ) && V_123 != V_43 ) {
F_66 ( V_2 -> V_11 , V_2 -> V_39 . V_40 . V_106 ,
V_123 , 1 , V_2 -> V_23 -> V_83 ) ;
V_121 ++ ;
}
return V_121 ;
}
STATIC int
F_69 (
struct V_1 * V_2 ,
int V_126 ,
int V_120 )
{
struct V_3 * V_4 ;
if ( ( V_2 -> V_46 & V_102 ) &&
( V_126 == V_2 -> V_67 - 1 ) )
return 0 ;
if ( ( V_2 -> V_80 [ V_126 ] | V_120 ) == V_2 -> V_80 [ V_126 ] )
return 0 ;
V_2 -> V_80 [ V_126 ] |= V_120 ;
V_4 = F_23 ( V_2 -> V_68 [ V_126 ] ) ;
if ( V_2 -> V_46 & V_47 )
return F_67 ( V_2 , V_120 , V_4 ) ;
return F_68 ( V_2 , V_120 , V_4 ) ;
}
STATIC T_9
F_70 (
struct V_1 * V_2 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 ) {
ASSERT ( V_52 -> V_14 != F_4 ( V_26 ) ) ;
return F_54 ( V_2 -> V_11 , F_9 ( V_52 -> V_14 ) ) ;
} else {
ASSERT ( V_2 -> V_39 . V_40 . V_106 != V_108 ) ;
ASSERT ( V_52 -> V_42 != F_16 ( V_43 ) ) ;
return F_57 ( V_2 -> V_11 , V_2 -> V_39 . V_40 . V_106 ,
F_5 ( V_52 -> V_42 ) ) ;
}
}
STATIC void
F_71 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
T_12 V_119 )
{
F_65 ( V_2 -> V_11 -> V_81 ,
F_70 ( V_2 , V_52 ) ,
V_2 -> V_11 -> V_82 * V_119 , V_2 -> V_23 -> V_83 ) ;
}
STATIC void
F_72 (
T_3 * V_2 ,
int V_126 ,
T_4 * V_7 )
{
struct V_3 * V_71 ;
if ( V_2 -> V_68 [ V_126 ] )
F_34 ( V_2 -> V_65 , V_2 -> V_68 [ V_126 ] ) ;
V_2 -> V_68 [ V_126 ] = V_7 ;
V_2 -> V_80 [ V_126 ] = 0 ;
V_71 = F_23 ( V_7 ) ;
if ( V_2 -> V_46 & V_47 ) {
if ( V_71 -> V_13 . V_14 . V_25 == F_4 ( V_26 ) )
V_2 -> V_80 [ V_126 ] |= V_124 ;
if ( V_71 -> V_13 . V_14 . V_27 == F_4 ( V_26 ) )
V_2 -> V_80 [ V_126 ] |= V_125 ;
} else {
if ( V_71 -> V_13 . V_42 . V_25 == F_16 ( V_43 ) )
V_2 -> V_80 [ V_126 ] |= V_124 ;
if ( V_71 -> V_13 . V_42 . V_27 == F_16 ( V_43 ) )
V_2 -> V_80 [ V_126 ] |= V_125 ;
}
}
STATIC int
F_73 (
struct V_1 * V_2 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 )
return V_52 -> V_14 == F_4 ( V_26 ) ;
else
return V_52 -> V_42 == F_16 ( V_43 ) ;
}
STATIC void
F_74 (
struct V_1 * V_2 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 )
V_52 -> V_14 = F_4 ( V_26 ) ;
else
V_52 -> V_42 = F_16 ( V_43 ) ;
}
STATIC void
F_75 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_51 * V_52 ,
int V_120 )
{
ASSERT ( V_120 == V_127 || V_120 == V_128 ) ;
if ( V_2 -> V_46 & V_47 ) {
if ( V_120 == V_128 )
V_52 -> V_14 = V_4 -> V_13 . V_14 . V_27 ;
else
V_52 -> V_14 = V_4 -> V_13 . V_14 . V_25 ;
} else {
if ( V_120 == V_128 )
V_52 -> V_42 = V_4 -> V_13 . V_42 . V_27 ;
else
V_52 -> V_42 = V_4 -> V_13 . V_42 . V_25 ;
}
}
STATIC void
F_76 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_51 * V_52 ,
int V_120 )
{
ASSERT ( V_120 == V_127 || V_120 == V_128 ) ;
if ( V_2 -> V_46 & V_47 ) {
if ( V_120 == V_128 )
V_4 -> V_13 . V_14 . V_27 = V_52 -> V_14 ;
else
V_4 -> V_13 . V_14 . V_25 = V_52 -> V_14 ;
} else {
if ( V_120 == V_128 )
V_4 -> V_13 . V_42 . V_27 = V_52 -> V_42 ;
else
V_4 -> V_13 . V_42 . V_25 = V_52 -> V_42 ;
}
}
void
F_77 (
struct V_9 * V_10 ,
struct V_3 * V_129 ,
T_9 V_130 ,
T_13 V_131 ,
T_14 V_5 ,
T_14 V_132 ,
T_15 V_133 ,
unsigned int V_134 )
{
V_129 -> V_20 = F_16 ( V_131 ) ;
V_129 -> V_21 = F_78 ( V_5 ) ;
V_129 -> V_22 = F_78 ( V_132 ) ;
if ( V_134 & V_47 ) {
V_129 -> V_13 . V_14 . V_25 = F_4 ( V_26 ) ;
V_129 -> V_13 . V_14 . V_27 = F_4 ( V_26 ) ;
if ( V_134 & V_84 ) {
V_129 -> V_13 . V_14 . V_17 = F_4 ( V_130 ) ;
V_129 -> V_13 . V_14 . V_135 = F_4 ( V_133 ) ;
F_79 ( & V_129 -> V_13 . V_14 . V_15 , & V_10 -> V_12 . V_16 ) ;
V_129 -> V_13 . V_14 . V_136 = 0 ;
V_129 -> V_13 . V_14 . V_59 = 0 ;
}
} else {
T_13 V_137 = ( T_13 ) V_133 ;
V_129 -> V_13 . V_42 . V_25 = F_16 ( V_43 ) ;
V_129 -> V_13 . V_42 . V_27 = F_16 ( V_43 ) ;
if ( V_134 & V_84 ) {
V_129 -> V_13 . V_42 . V_17 = F_4 ( V_130 ) ;
V_129 -> V_13 . V_42 . V_135 = F_16 ( V_137 ) ;
F_79 ( & V_129 -> V_13 . V_42 . V_15 , & V_10 -> V_12 . V_16 ) ;
V_129 -> V_13 . V_42 . V_59 = 0 ;
}
}
}
void
F_80 (
struct V_9 * V_10 ,
struct V_6 * V_7 ,
T_13 V_131 ,
T_14 V_5 ,
T_14 V_132 ,
T_15 V_133 ,
unsigned int V_134 )
{
F_77 ( V_10 , F_23 ( V_7 ) , V_7 -> V_18 ,
V_131 , V_5 , V_132 , V_133 , V_134 ) ;
}
STATIC void
F_81 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_5 ,
int V_132 )
{
T_15 V_133 ;
if ( V_2 -> V_46 & V_47 )
V_133 = V_2 -> V_39 . V_71 . V_98 -> V_138 ;
else
V_133 = V_2 -> V_39 . V_40 . V_106 ;
F_77 ( V_2 -> V_11 , F_23 ( V_7 ) , V_7 -> V_18 ,
F_6 ( V_2 ) , V_5 , V_132 ,
V_133 , V_2 -> V_46 ) ;
}
STATIC int
F_82 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
union V_51 V_52 ;
if ( V_5 > 0 )
return 0 ;
if ( ! ( V_2 -> V_46 & V_139 ) )
return 0 ;
F_75 ( V_2 , V_4 , & V_52 , V_128 ) ;
if ( ! F_73 ( V_2 , & V_52 ) )
return 0 ;
return 1 ;
}
STATIC void
F_83 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 )
V_52 -> V_14 = F_4 ( F_84 ( V_2 -> V_11 ,
F_38 ( V_7 ) ) ) ;
else {
V_52 -> V_42 = F_16 ( F_85 ( V_2 -> V_11 ,
F_38 ( V_7 ) ) ) ;
}
}
STATIC void
F_86 (
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
switch ( V_2 -> V_69 ) {
case V_140 :
case V_141 :
F_63 ( V_7 , V_142 ) ;
break;
case V_143 :
case V_144 :
F_63 ( V_7 , V_145 ) ;
break;
case V_70 :
F_63 ( V_7 , V_146 ) ;
break;
case V_147 :
F_63 ( V_7 , V_148 ) ;
break;
default:
ASSERT ( 0 ) ;
}
}
STATIC int
F_87 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
int V_134 ,
struct V_3 * * V_4 ,
struct V_6 * * V_101 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_9 V_105 ;
ASSERT ( ! ( V_134 & V_149 ) ) ;
V_105 = F_70 ( V_2 , V_52 ) ;
* V_101 = F_55 ( V_2 -> V_65 , V_10 -> V_81 , V_105 ,
V_10 -> V_82 , V_134 ) ;
if ( ! * V_101 )
return - V_150 ;
( * V_101 ) -> V_151 = V_2 -> V_23 -> V_83 ;
* V_4 = F_23 ( * V_101 ) ;
return 0 ;
}
STATIC int
F_88 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
int V_134 ,
struct V_3 * * V_4 ,
struct V_6 * * V_101 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_9 V_105 ;
int error ;
ASSERT ( ! ( V_134 & V_149 ) ) ;
V_105 = F_70 ( V_2 , V_52 ) ;
error = F_37 ( V_10 , V_2 -> V_65 , V_10 -> V_81 , V_105 ,
V_10 -> V_82 , V_134 , V_101 ,
V_2 -> V_23 -> V_83 ) ;
if ( error )
return error ;
F_86 ( V_2 , * V_101 ) ;
* V_4 = F_23 ( * V_101 ) ;
return 0 ;
}
STATIC void
F_89 (
struct V_1 * V_2 ,
union V_95 * V_152 ,
union V_95 * V_153 ,
int V_154 )
{
ASSERT ( V_154 >= 0 ) ;
memcpy ( V_152 , V_153 , V_154 * V_2 -> V_23 -> V_93 ) ;
}
STATIC void
F_90 (
struct V_1 * V_2 ,
union V_94 * V_155 ,
union V_94 * V_156 ,
int V_132 )
{
ASSERT ( V_132 >= 0 ) ;
memcpy ( V_155 , V_156 , V_132 * V_2 -> V_23 -> V_92 ) ;
}
STATIC void
F_91 (
struct V_1 * V_2 ,
union V_51 * V_157 ,
union V_51 * V_158 ,
int V_159 )
{
ASSERT ( V_159 >= 0 ) ;
memcpy ( V_157 , V_158 , V_159 * F_40 ( V_2 ) ) ;
}
STATIC void
F_92 (
struct V_1 * V_2 ,
union V_95 * V_160 ,
int V_161 ,
int V_154 )
{
char * V_152 ;
ASSERT ( V_154 >= 0 ) ;
ASSERT ( V_161 == 1 || V_161 == - 1 ) ;
V_152 = ( char * ) V_160 + ( V_161 * V_2 -> V_23 -> V_93 ) ;
memmove ( V_152 , V_160 , V_154 * V_2 -> V_23 -> V_93 ) ;
}
STATIC void
F_93 (
struct V_1 * V_2 ,
union V_94 * V_162 ,
int V_161 ,
int V_132 )
{
char * V_155 ;
ASSERT ( V_132 >= 0 ) ;
ASSERT ( V_161 == 1 || V_161 == - 1 ) ;
V_155 = ( char * ) V_162 + ( V_161 * V_2 -> V_23 -> V_92 ) ;
memmove ( V_155 , V_162 , V_132 * V_2 -> V_23 -> V_92 ) ;
}
STATIC void
F_94 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
int V_161 ,
int V_159 )
{
char * V_157 ;
ASSERT ( V_159 >= 0 ) ;
ASSERT ( V_161 == 1 || V_161 == - 1 ) ;
V_157 = ( char * ) V_52 + ( V_161 * F_40 ( V_2 ) ) ;
memmove ( V_157 , V_52 , V_159 * F_40 ( V_2 ) ) ;
}
STATIC void
F_95 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_112 ,
int V_113 )
{
F_96 ( V_2 , V_163 ) ;
F_97 ( V_2 , V_7 , V_112 , V_113 ) ;
if ( V_7 ) {
F_98 ( V_2 -> V_65 , V_7 , V_164 ) ;
F_99 ( V_2 -> V_65 , V_7 ,
F_42 ( V_2 , V_112 ) ,
F_42 ( V_2 , V_113 + 1 ) - 1 ) ;
} else {
F_100 ( V_2 -> V_65 , V_2 -> V_39 . V_71 . V_98 ,
F_101 ( V_2 -> V_39 . V_71 . V_99 ) ) ;
}
F_96 ( V_2 , V_165 ) ;
}
void
F_102 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_112 ,
int V_113 )
{
F_96 ( V_2 , V_163 ) ;
F_97 ( V_2 , V_7 , V_112 , V_113 ) ;
F_98 ( V_2 -> V_65 , V_7 , V_164 ) ;
F_99 ( V_2 -> V_65 , V_7 ,
F_41 ( V_2 , V_112 ) ,
F_41 ( V_2 , V_113 + 1 ) - 1 ) ;
F_96 ( V_2 , V_165 ) ;
}
STATIC void
F_103 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_112 ,
int V_113 )
{
F_96 ( V_2 , V_163 ) ;
F_97 ( V_2 , V_7 , V_112 , V_113 ) ;
if ( V_7 ) {
struct V_3 * V_4 = F_23 ( V_7 ) ;
int V_5 = F_49 ( V_4 ) ;
F_98 ( V_2 -> V_65 , V_7 , V_164 ) ;
F_99 ( V_2 -> V_65 , V_7 ,
F_44 ( V_2 , V_112 , V_5 ) ,
F_44 ( V_2 , V_113 + 1 , V_5 ) - 1 ) ;
} else {
F_100 ( V_2 -> V_65 , V_2 -> V_39 . V_71 . V_98 ,
F_101 ( V_2 -> V_39 . V_71 . V_99 ) ) ;
}
F_96 ( V_2 , V_165 ) ;
}
void
F_104 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_109 )
{
int V_112 ;
int V_113 ;
static const short V_166 [] = {
F_105 ( struct V_3 , V_20 ) ,
F_105 ( struct V_3 , V_21 ) ,
F_105 ( struct V_3 , V_22 ) ,
F_105 ( struct V_3 , V_13 . V_42 . V_25 ) ,
F_105 ( struct V_3 , V_13 . V_42 . V_27 ) ,
F_105 ( struct V_3 , V_13 . V_42 . V_17 ) ,
F_105 ( struct V_3 , V_13 . V_42 . V_59 ) ,
F_105 ( struct V_3 , V_13 . V_42 . V_15 ) ,
F_105 ( struct V_3 , V_13 . V_42 . V_135 ) ,
F_105 ( struct V_3 , V_13 . V_42 . V_167 ) ,
V_87
} ;
static const short V_168 [] = {
F_105 ( struct V_3 , V_20 ) ,
F_105 ( struct V_3 , V_21 ) ,
F_105 ( struct V_3 , V_22 ) ,
F_105 ( struct V_3 , V_13 . V_14 . V_25 ) ,
F_105 ( struct V_3 , V_13 . V_14 . V_27 ) ,
F_105 ( struct V_3 , V_13 . V_14 . V_17 ) ,
F_105 ( struct V_3 , V_13 . V_14 . V_59 ) ,
F_105 ( struct V_3 , V_13 . V_14 . V_15 ) ,
F_105 ( struct V_3 , V_13 . V_14 . V_135 ) ,
F_105 ( struct V_3 , V_13 . V_14 . V_167 ) ,
F_105 ( struct V_3 , V_13 . V_14 . V_136 ) ,
V_85
} ;
F_96 ( V_2 , V_163 ) ;
F_106 ( V_2 , V_7 , V_109 ) ;
if ( V_7 ) {
int V_111 ;
if ( V_2 -> V_46 & V_84 ) {
if ( V_109 == V_169 )
V_109 = V_170 ;
V_111 = V_171 ;
} else {
V_111 = V_172 ;
}
F_61 ( V_109 ,
( V_2 -> V_46 & V_47 ) ?
V_168 : V_166 ,
V_111 , & V_112 , & V_113 ) ;
F_98 ( V_2 -> V_65 , V_7 , V_164 ) ;
F_99 ( V_2 -> V_65 , V_7 , V_112 , V_113 ) ;
} else {
F_100 ( V_2 -> V_65 , V_2 -> V_39 . V_71 . V_98 ,
F_101 ( V_2 -> V_39 . V_71 . V_99 ) ) ;
}
F_96 ( V_2 , V_165 ) ;
}
int
F_107 (
struct V_1 * V_2 ,
int V_5 ,
int * V_173 )
{
struct V_3 * V_4 ;
union V_51 V_52 ;
struct V_6 * V_7 ;
int error ;
int V_126 ;
F_96 ( V_2 , V_163 ) ;
F_108 ( V_2 , V_5 ) ;
ASSERT ( V_5 < V_2 -> V_67 ) ;
F_69 ( V_2 , V_5 , V_125 ) ;
V_4 = F_52 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_174;
#endif
if ( ++ V_2 -> V_79 [ V_5 ] <= F_110 ( V_4 ) )
goto V_175;
F_75 ( V_2 , V_4 , & V_52 , V_128 ) ;
if ( F_73 ( V_2 , & V_52 ) )
goto V_176;
F_32 ( V_2 , V_177 ) ;
for ( V_126 = V_5 + 1 ; V_126 < V_2 -> V_67 ; V_126 ++ ) {
V_4 = F_52 ( V_2 , V_126 , & V_7 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_4 , V_126 , V_7 ) ;
if ( error )
goto V_174;
#endif
if ( ++ V_2 -> V_79 [ V_126 ] <= F_110 ( V_4 ) )
break;
F_69 ( V_2 , V_126 , V_125 ) ;
}
if ( V_126 == V_2 -> V_67 ) {
if ( V_2 -> V_46 & V_102 )
goto V_176;
ASSERT ( 0 ) ;
error = - V_33 ;
goto V_174;
}
ASSERT ( V_126 < V_2 -> V_67 ) ;
for ( V_4 = F_52 ( V_2 , V_126 , & V_7 ) ; V_126 > V_5 ; ) {
union V_51 * V_178 ;
V_178 = F_48 ( V_2 , V_2 -> V_79 [ V_126 ] , V_4 ) ;
-- V_126 ;
error = F_88 ( V_2 , V_178 , 0 , & V_4 , & V_7 ) ;
if ( error )
goto V_174;
F_72 ( V_2 , V_126 , V_7 ) ;
V_2 -> V_79 [ V_126 ] = 1 ;
}
V_175:
F_96 ( V_2 , V_165 ) ;
* V_173 = 1 ;
return 0 ;
V_176:
F_96 ( V_2 , V_165 ) ;
* V_173 = 0 ;
return 0 ;
V_174:
F_96 ( V_2 , V_179 ) ;
return error ;
}
int
F_111 (
struct V_1 * V_2 ,
int V_5 ,
int * V_173 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
int error ;
int V_126 ;
union V_51 V_52 ;
F_96 ( V_2 , V_163 ) ;
F_108 ( V_2 , V_5 ) ;
ASSERT ( V_5 < V_2 -> V_67 ) ;
F_69 ( V_2 , V_5 , V_124 ) ;
if ( -- V_2 -> V_79 [ V_5 ] > 0 )
goto V_175;
V_4 = F_52 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_174;
#endif
F_75 ( V_2 , V_4 , & V_52 , V_127 ) ;
if ( F_73 ( V_2 , & V_52 ) )
goto V_176;
F_32 ( V_2 , V_180 ) ;
for ( V_126 = V_5 + 1 ; V_126 < V_2 -> V_67 ; V_126 ++ ) {
if ( -- V_2 -> V_79 [ V_126 ] > 0 )
break;
F_69 ( V_2 , V_126 , V_124 ) ;
}
if ( V_126 == V_2 -> V_67 ) {
if ( V_2 -> V_46 & V_102 )
goto V_176;
ASSERT ( 0 ) ;
error = - V_33 ;
goto V_174;
}
ASSERT ( V_126 < V_2 -> V_67 ) ;
for ( V_4 = F_52 ( V_2 , V_126 , & V_7 ) ; V_126 > V_5 ; ) {
union V_51 * V_178 ;
V_178 = F_48 ( V_2 , V_2 -> V_79 [ V_126 ] , V_4 ) ;
-- V_126 ;
error = F_88 ( V_2 , V_178 , 0 , & V_4 , & V_7 ) ;
if ( error )
goto V_174;
F_72 ( V_2 , V_126 , V_7 ) ;
V_2 -> V_79 [ V_126 ] = F_110 ( V_4 ) ;
}
V_175:
F_96 ( V_2 , V_165 ) ;
* V_173 = 1 ;
return 0 ;
V_176:
F_96 ( V_2 , V_165 ) ;
* V_173 = 0 ;
return 0 ;
V_174:
F_96 ( V_2 , V_179 ) ;
return error ;
}
STATIC int
F_112 (
struct V_1 * V_2 ,
int V_5 ,
union V_51 * V_181 ,
struct V_3 * * V_182 )
{
struct V_6 * V_7 ;
int error = 0 ;
if ( ( V_2 -> V_46 & V_102 ) &&
( V_5 == V_2 -> V_67 - 1 ) ) {
* V_182 = F_50 ( V_2 ) ;
return 0 ;
}
V_7 = V_2 -> V_68 [ V_5 ] ;
if ( V_7 && F_38 ( V_7 ) == F_70 ( V_2 , V_181 ) ) {
* V_182 = F_23 ( V_7 ) ;
return 0 ;
}
error = F_88 ( V_2 , V_181 , 0 , V_182 , & V_7 ) ;
if ( error )
return error ;
F_72 ( V_2 , V_5 , V_7 ) ;
return 0 ;
}
STATIC union V_95 *
F_113 (
struct V_1 * V_2 ,
int V_5 ,
int V_183 ,
struct V_3 * V_4 ,
union V_95 * V_184 )
{
if ( V_5 == 0 ) {
V_2 -> V_23 -> V_185 ( V_184 ,
F_45 ( V_2 , V_183 , V_4 ) ) ;
return V_184 ;
}
return F_46 ( V_2 , V_183 , V_4 ) ;
}
int
F_114 (
struct V_1 * V_2 ,
T_16 V_161 ,
int * V_173 )
{
struct V_3 * V_4 ;
T_11 V_186 ;
int error ;
int V_183 ;
int V_5 ;
union V_51 * V_181 ;
union V_51 V_52 ;
F_96 ( V_2 , V_163 ) ;
F_108 ( V_2 , V_161 ) ;
F_32 ( V_2 , V_187 ) ;
if ( V_2 -> V_67 == 0 )
return - V_33 ;
V_4 = NULL ;
V_183 = 0 ;
V_2 -> V_23 -> V_188 ( V_2 , & V_52 ) ;
V_181 = & V_52 ;
for ( V_5 = V_2 -> V_67 - 1 , V_186 = 1 ; V_5 >= 0 ; V_5 -- ) {
error = F_112 ( V_2 , V_5 , V_181 , & V_4 ) ;
if ( error )
goto V_174;
if ( V_186 == 0 ) {
V_183 = 1 ;
} else {
int V_189 ;
int V_190 ;
V_190 = 1 ;
V_189 = F_110 ( V_4 ) ;
if ( ! V_189 ) {
ASSERT ( V_5 == 0 && V_2 -> V_67 == 1 ) ;
V_2 -> V_79 [ 0 ] = V_161 != V_191 ;
F_96 ( V_2 , V_165 ) ;
* V_173 = 0 ;
return 0 ;
}
while ( V_190 <= V_189 ) {
union V_95 V_160 ;
union V_95 * V_184 ;
F_32 ( V_2 , V_192 ) ;
V_183 = ( V_190 + V_189 ) >> 1 ;
V_184 = F_113 ( V_2 , V_5 ,
V_183 , V_4 , & V_160 ) ;
V_186 = V_2 -> V_23 -> V_193 ( V_2 , V_184 ) ;
if ( V_186 < 0 )
V_190 = V_183 + 1 ;
else if ( V_186 > 0 )
V_189 = V_183 - 1 ;
else
break;
}
}
if ( V_5 > 0 ) {
if ( V_186 > 0 && -- V_183 < 1 )
V_183 = 1 ;
V_181 = F_48 ( V_2 , V_183 , V_4 ) ;
#ifdef F_109
error = F_21 ( V_2 , V_181 , 0 , V_5 ) ;
if ( error )
goto V_174;
#endif
V_2 -> V_79 [ V_5 ] = V_183 ;
}
}
if ( V_161 != V_191 && V_186 < 0 ) {
V_183 ++ ;
F_75 ( V_2 , V_4 , & V_52 , V_128 ) ;
if ( V_161 == V_194 &&
V_183 > F_110 ( V_4 ) &&
! F_73 ( V_2 , & V_52 ) ) {
int V_66 ;
V_2 -> V_79 [ 0 ] = V_183 ;
error = F_107 ( V_2 , 0 , & V_66 ) ;
if ( error )
goto V_174;
F_19 ( V_2 -> V_11 , V_66 == 1 ) ;
F_96 ( V_2 , V_165 ) ;
* V_173 = 1 ;
return 0 ;
}
} else if ( V_161 == V_191 && V_186 > 0 )
V_183 -- ;
V_2 -> V_79 [ 0 ] = V_183 ;
if ( V_183 == 0 || V_183 > F_110 ( V_4 ) )
* V_173 = 0 ;
else if ( V_161 != V_195 || V_186 == 0 )
* V_173 = 1 ;
else
* V_173 = 0 ;
F_96 ( V_2 , V_165 ) ;
return 0 ;
V_174:
F_96 ( V_2 , V_179 ) ;
return error ;
}
STATIC union V_95 *
F_115 (
struct V_1 * V_2 ,
union V_95 * V_160 )
{
ASSERT ( V_2 -> V_46 & V_196 ) ;
return (union V_95 * ) ( ( char * ) V_160 +
( V_2 -> V_23 -> V_93 / 2 ) ) ;
}
STATIC void
F_116 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_95 * V_160 )
{
union V_95 V_197 ;
union V_95 V_198 ;
union V_94 * V_162 ;
union V_95 * V_189 ;
int V_91 ;
V_162 = F_45 ( V_2 , 1 , V_4 ) ;
V_2 -> V_23 -> V_185 ( V_160 , V_162 ) ;
if ( V_2 -> V_46 & V_196 ) {
V_2 -> V_23 -> V_199 ( & V_197 , V_162 ) ;
for ( V_91 = 2 ; V_91 <= F_110 ( V_4 ) ; V_91 ++ ) {
V_162 = F_45 ( V_2 , V_91 , V_4 ) ;
V_2 -> V_23 -> V_199 ( & V_198 , V_162 ) ;
if ( V_2 -> V_23 -> V_200 ( V_2 , & V_198 , & V_197 )
> 0 )
V_197 = V_198 ;
}
V_189 = F_115 ( V_2 , V_160 ) ;
memcpy ( V_189 , & V_197 , V_2 -> V_23 -> V_93 / 2 ) ;
}
}
STATIC void
F_117 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_95 * V_160 )
{
union V_95 * V_198 ;
union V_95 * V_197 ;
union V_95 * V_189 ;
int V_91 ;
if ( V_2 -> V_46 & V_196 ) {
memcpy ( V_160 , F_46 ( V_2 , 1 , V_4 ) ,
V_2 -> V_23 -> V_93 / 2 ) ;
V_197 = F_47 ( V_2 , 1 , V_4 ) ;
for ( V_91 = 2 ; V_91 <= F_110 ( V_4 ) ; V_91 ++ ) {
V_198 = F_47 ( V_2 , V_91 , V_4 ) ;
if ( V_2 -> V_23 -> V_200 ( V_2 , V_198 , V_197 ) > 0 )
V_197 = V_198 ;
}
V_189 = F_115 ( V_2 , V_160 ) ;
memcpy ( V_189 , V_197 , V_2 -> V_23 -> V_93 / 2 ) ;
} else {
memcpy ( V_160 , F_46 ( V_2 , 1 , V_4 ) ,
V_2 -> V_23 -> V_93 ) ;
}
}
STATIC void
F_118 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_95 * V_160 )
{
if ( F_7 ( V_4 -> V_21 ) == 0 )
F_116 ( V_2 , V_4 , V_160 ) ;
else
F_117 ( V_2 , V_4 , V_160 ) ;
}
static inline bool
F_119 (
struct V_1 * V_2 ,
int V_52 )
{
return ( V_2 -> V_46 & V_196 ) || V_52 == 1 ;
}
STATIC int
F_120 (
struct V_1 * V_2 ,
int V_5 ,
struct V_3 * V_4 ,
struct V_6 * V_201 ,
bool V_202 )
{
union V_203 V_160 ;
union V_95 * V_204 ;
union V_95 * V_198 ;
union V_95 * V_205 ;
union V_95 * V_206 ;
struct V_6 * V_7 ;
int V_52 ;
ASSERT ( V_2 -> V_46 & V_196 ) ;
if ( V_5 + 1 >= V_2 -> V_67 )
return 0 ;
F_121 ( V_2 , V_5 , V_201 ) ;
V_204 = (union V_95 * ) & V_160 ;
V_198 = F_115 ( V_2 , V_204 ) ;
F_118 ( V_2 , V_4 , V_204 ) ;
for ( V_5 ++ ; V_5 < V_2 -> V_67 ; V_5 ++ ) {
#ifdef F_109
int error ;
#endif
V_4 = F_52 ( V_2 , V_5 , & V_7 ) ;
F_121 ( V_2 , V_5 , V_7 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error ) {
F_96 ( V_2 , V_179 ) ;
return error ;
}
#endif
V_52 = V_2 -> V_79 [ V_5 ] ;
V_205 = F_46 ( V_2 , V_52 , V_4 ) ;
V_206 = F_47 ( V_2 , V_52 , V_4 ) ;
if ( ! V_202 &&
! ( V_2 -> V_23 -> V_200 ( V_2 , V_205 , V_204 ) != 0 ||
V_2 -> V_23 -> V_200 ( V_2 , V_206 , V_198 ) != 0 ) )
break;
F_89 ( V_2 , V_205 , V_204 , 1 ) ;
F_95 ( V_2 , V_7 , V_52 , V_52 ) ;
if ( V_5 + 1 >= V_2 -> V_67 )
break;
F_117 ( V_2 , V_4 , V_204 ) ;
}
return 0 ;
}
STATIC int
F_122 (
struct V_1 * V_2 ,
int V_5 )
{
struct V_6 * V_7 ;
struct V_3 * V_4 ;
V_4 = F_52 ( V_2 , V_5 , & V_7 ) ;
return F_120 ( V_2 , V_5 , V_4 , V_7 , true ) ;
}
STATIC int
F_123 (
struct V_1 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_95 * V_184 ;
union V_95 V_160 ;
int V_52 ;
ASSERT ( V_5 >= 0 ) ;
V_4 = F_52 ( V_2 , V_5 , & V_7 ) ;
if ( V_2 -> V_46 & V_196 )
return F_120 ( V_2 , V_5 , V_4 , V_7 , false ) ;
F_96 ( V_2 , V_163 ) ;
F_124 ( V_2 , V_5 , V_207 ) ;
F_118 ( V_2 , V_4 , & V_160 ) ;
for ( V_5 ++ , V_52 = 1 ; V_52 == 1 && V_5 < V_2 -> V_67 ; V_5 ++ ) {
#ifdef F_109
int error ;
#endif
V_4 = F_52 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error ) {
F_96 ( V_2 , V_179 ) ;
return error ;
}
#endif
V_52 = V_2 -> V_79 [ V_5 ] ;
V_184 = F_46 ( V_2 , V_52 , V_4 ) ;
F_89 ( V_2 , V_184 , & V_160 , 1 ) ;
F_95 ( V_2 , V_7 , V_52 , V_52 ) ;
}
F_96 ( V_2 , V_165 ) ;
return 0 ;
}
int
F_125 (
struct V_1 * V_2 ,
union V_94 * V_162 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int error ;
int V_52 ;
union V_94 * V_208 ;
F_96 ( V_2 , V_163 ) ;
F_126 ( V_2 , V_162 ) ;
V_4 = F_52 ( V_2 , 0 , & V_7 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_4 , 0 , V_7 ) ;
if ( error )
goto V_174;
#endif
V_52 = V_2 -> V_79 [ 0 ] ;
V_208 = F_45 ( V_2 , V_52 , V_4 ) ;
F_90 ( V_2 , V_208 , V_162 , 1 ) ;
F_102 ( V_2 , V_7 , V_52 , V_52 ) ;
if ( F_82 ( V_2 , V_4 , 0 ) ) {
V_2 -> V_23 -> V_209 ( V_2 , V_4 , V_162 ,
V_52 , V_210 ) ;
}
if ( F_119 ( V_2 , V_52 ) ) {
error = F_123 ( V_2 , 0 ) ;
if ( error )
goto V_174;
}
F_96 ( V_2 , V_165 ) ;
return 0 ;
V_174:
F_96 ( V_2 , V_179 ) ;
return error ;
}
STATIC int
F_127 (
struct V_1 * V_2 ,
int V_5 ,
int * V_173 )
{
struct V_6 * V_211 ;
struct V_3 * V_122 ;
int V_212 ;
struct V_6 * V_213 ;
struct V_3 * V_123 ;
struct V_1 * V_214 ;
int V_215 ;
union V_51 V_216 ;
union V_95 * V_217 = NULL ;
union V_51 * V_218 = NULL ;
union V_94 * V_219 = NULL ;
int error ;
int V_66 ;
F_96 ( V_2 , V_163 ) ;
F_108 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_46 & V_102 ) &&
V_5 == V_2 -> V_67 - 1 )
goto V_176;
V_123 = F_52 ( V_2 , V_5 , & V_213 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_123 , V_5 , V_213 ) ;
if ( error )
goto V_174;
#endif
F_75 ( V_2 , V_123 , & V_216 , V_127 ) ;
if ( F_73 ( V_2 , & V_216 ) )
goto V_176;
if ( V_2 -> V_79 [ V_5 ] <= 1 )
goto V_176;
error = F_88 ( V_2 , & V_216 , 0 , & V_122 , & V_211 ) ;
if ( error )
goto V_174;
V_212 = F_110 ( V_122 ) ;
if ( V_212 == V_2 -> V_23 -> V_24 ( V_2 , V_5 ) )
goto V_176;
V_215 = F_110 ( V_123 ) ;
V_212 ++ ;
V_215 -- ;
F_32 ( V_2 , V_220 ) ;
F_128 ( V_2 , V_221 , 1 ) ;
if ( V_5 > 0 ) {
union V_95 * V_222 ;
union V_51 * V_223 ;
V_222 = F_46 ( V_2 , V_212 , V_122 ) ;
V_217 = F_46 ( V_2 , 1 , V_123 ) ;
V_223 = F_48 ( V_2 , V_212 , V_122 ) ;
V_218 = F_48 ( V_2 , 1 , V_123 ) ;
#ifdef F_109
error = F_21 ( V_2 , V_218 , 0 , V_5 ) ;
if ( error )
goto V_174;
#endif
F_89 ( V_2 , V_222 , V_217 , 1 ) ;
F_91 ( V_2 , V_223 , V_218 , 1 ) ;
F_95 ( V_2 , V_211 , V_212 , V_212 ) ;
F_103 ( V_2 , V_211 , V_212 , V_212 ) ;
ASSERT ( V_2 -> V_23 -> V_224 ( V_2 ,
F_46 ( V_2 , V_212 - 1 , V_122 ) , V_222 ) ) ;
} else {
union V_94 * V_225 ;
V_225 = F_45 ( V_2 , V_212 , V_122 ) ;
V_219 = F_45 ( V_2 , 1 , V_123 ) ;
F_90 ( V_2 , V_225 , V_219 , 1 ) ;
F_102 ( V_2 , V_211 , V_212 , V_212 ) ;
ASSERT ( V_2 -> V_23 -> V_226 ( V_2 ,
F_45 ( V_2 , V_212 - 1 , V_122 ) , V_225 ) ) ;
}
F_129 ( V_122 , V_212 ) ;
F_104 ( V_2 , V_211 , V_227 ) ;
F_129 ( V_123 , V_215 ) ;
F_104 ( V_2 , V_213 , V_227 ) ;
F_128 ( V_2 , V_221 , V_215 - 1 ) ;
if ( V_5 > 0 ) {
#ifdef F_109
int V_66 ;
for ( V_66 = 0 ; V_66 < V_215 ; V_66 ++ ) {
error = F_21 ( V_2 , V_218 , V_66 + 1 , V_5 ) ;
if ( error )
goto V_174;
}
#endif
F_92 ( V_2 ,
F_46 ( V_2 , 2 , V_123 ) ,
- 1 , V_215 ) ;
F_94 ( V_2 ,
F_48 ( V_2 , 2 , V_123 ) ,
- 1 , V_215 ) ;
F_95 ( V_2 , V_213 , 1 , V_215 ) ;
F_103 ( V_2 , V_213 , 1 , V_215 ) ;
} else {
F_93 ( V_2 ,
F_45 ( V_2 , 2 , V_123 ) ,
- 1 , V_215 ) ;
F_102 ( V_2 , V_213 , 1 , V_215 ) ;
}
if ( V_2 -> V_46 & V_196 ) {
error = F_36 ( V_2 , & V_214 ) ;
if ( error )
goto V_174;
V_66 = F_59 ( V_214 , V_5 ) ;
F_130 ( V_214 -> V_11 , V_66 == 1 , V_174 ) ;
error = F_111 ( V_214 , V_5 , & V_66 ) ;
if ( error )
goto V_228;
error = F_123 ( V_214 , V_5 ) ;
if ( error )
goto V_228;
F_33 ( V_214 , V_229 ) ;
}
error = F_123 ( V_2 , V_5 ) ;
if ( error )
goto V_174;
V_2 -> V_79 [ V_5 ] -- ;
F_96 ( V_2 , V_165 ) ;
* V_173 = 1 ;
return 0 ;
V_176:
F_96 ( V_2 , V_165 ) ;
* V_173 = 0 ;
return 0 ;
V_174:
F_96 ( V_2 , V_179 ) ;
return error ;
V_228:
F_96 ( V_214 , V_179 ) ;
F_33 ( V_214 , V_230 ) ;
return error ;
}
STATIC int
F_131 (
struct V_1 * V_2 ,
int V_5 ,
int * V_173 )
{
struct V_6 * V_211 ;
struct V_3 * V_122 ;
struct V_6 * V_213 ;
struct V_3 * V_123 ;
struct V_1 * V_214 ;
union V_51 V_231 ;
union V_95 * V_217 ;
int V_215 ;
int V_212 ;
int error ;
int V_66 ;
F_96 ( V_2 , V_163 ) ;
F_108 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_46 & V_102 ) &&
( V_5 == V_2 -> V_67 - 1 ) )
goto V_176;
V_122 = F_52 ( V_2 , V_5 , & V_211 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_122 , V_5 , V_211 ) ;
if ( error )
goto V_174;
#endif
F_75 ( V_2 , V_122 , & V_231 , V_128 ) ;
if ( F_73 ( V_2 , & V_231 ) )
goto V_176;
V_212 = F_110 ( V_122 ) ;
if ( V_2 -> V_79 [ V_5 ] >= V_212 )
goto V_176;
error = F_88 ( V_2 , & V_231 , 0 , & V_123 , & V_213 ) ;
if ( error )
goto V_174;
V_215 = F_110 ( V_123 ) ;
if ( V_215 == V_2 -> V_23 -> V_24 ( V_2 , V_5 ) )
goto V_176;
F_32 ( V_2 , V_232 ) ;
F_128 ( V_2 , V_221 , V_215 ) ;
if ( V_5 > 0 ) {
union V_95 * V_222 ;
union V_51 * V_223 ;
union V_51 * V_218 ;
V_222 = F_46 ( V_2 , V_212 , V_122 ) ;
V_223 = F_48 ( V_2 , V_212 , V_122 ) ;
V_217 = F_46 ( V_2 , 1 , V_123 ) ;
V_218 = F_48 ( V_2 , 1 , V_123 ) ;
#ifdef F_109
for ( V_66 = V_215 - 1 ; V_66 >= 0 ; V_66 -- ) {
error = F_21 ( V_2 , V_218 , V_66 , V_5 ) ;
if ( error )
goto V_174;
}
#endif
F_92 ( V_2 , V_217 , 1 , V_215 ) ;
F_94 ( V_2 , V_218 , 1 , V_215 ) ;
#ifdef F_109
error = F_21 ( V_2 , V_223 , 0 , V_5 ) ;
if ( error )
goto V_174;
#endif
F_89 ( V_2 , V_217 , V_222 , 1 ) ;
F_91 ( V_2 , V_218 , V_223 , 1 ) ;
F_95 ( V_2 , V_213 , 1 , V_215 + 1 ) ;
F_103 ( V_2 , V_213 , 1 , V_215 + 1 ) ;
ASSERT ( V_2 -> V_23 -> V_224 ( V_2 , V_217 ,
F_46 ( V_2 , 2 , V_123 ) ) ) ;
} else {
union V_94 * V_225 ;
union V_94 * V_219 ;
V_225 = F_45 ( V_2 , V_212 , V_122 ) ;
V_219 = F_45 ( V_2 , 1 , V_123 ) ;
F_93 ( V_2 , V_219 , 1 , V_215 ) ;
F_90 ( V_2 , V_219 , V_225 , 1 ) ;
F_102 ( V_2 , V_213 , 1 , V_215 + 1 ) ;
}
F_129 ( V_122 , -- V_212 ) ;
F_104 ( V_2 , V_211 , V_227 ) ;
F_129 ( V_123 , ++ V_215 ) ;
F_104 ( V_2 , V_213 , V_227 ) ;
error = F_36 ( V_2 , & V_214 ) ;
if ( error )
goto V_174;
V_66 = F_60 ( V_214 , V_5 ) ;
F_130 ( V_214 -> V_11 , V_66 == 1 , V_174 ) ;
error = F_107 ( V_214 , V_5 , & V_66 ) ;
if ( error )
goto V_228;
if ( V_2 -> V_46 & V_196 ) {
error = F_123 ( V_2 , V_5 ) ;
if ( error )
goto V_228;
}
error = F_123 ( V_214 , V_5 ) ;
if ( error )
goto V_228;
F_33 ( V_214 , V_229 ) ;
F_96 ( V_2 , V_165 ) ;
* V_173 = 1 ;
return 0 ;
V_176:
F_96 ( V_2 , V_165 ) ;
* V_173 = 0 ;
return 0 ;
V_174:
F_96 ( V_2 , V_179 ) ;
return error ;
V_228:
F_96 ( V_214 , V_179 ) ;
F_33 ( V_214 , V_230 ) ;
return error ;
}
STATIC int
F_132 (
struct V_1 * V_2 ,
int V_5 ,
union V_51 * V_178 ,
union V_95 * V_160 ,
struct V_1 * * V_233 ,
int * V_173 )
{
union V_51 V_216 ;
struct V_6 * V_211 ;
struct V_3 * V_122 ;
union V_51 V_231 ;
struct V_6 * V_213 ;
struct V_3 * V_123 ;
union V_51 V_234 ;
struct V_6 * V_235 ;
struct V_3 * V_236 ;
int V_212 ;
int V_215 ;
int V_237 ;
int error ;
#ifdef F_109
int V_66 ;
#endif
F_96 ( V_2 , V_163 ) ;
F_133 ( V_2 , V_5 , * V_178 , V_160 ) ;
F_32 ( V_2 , V_238 ) ;
V_122 = F_52 ( V_2 , V_5 , & V_211 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_122 , V_5 , V_211 ) ;
if ( error )
goto V_174;
#endif
F_83 ( V_2 , V_211 , & V_216 ) ;
error = V_2 -> V_23 -> V_239 ( V_2 , & V_216 , & V_231 , V_173 ) ;
if ( error )
goto V_174;
if ( * V_173 == 0 )
goto V_176;
F_32 ( V_2 , V_240 ) ;
error = F_87 ( V_2 , & V_231 , 0 , & V_123 , & V_213 ) ;
if ( error )
goto V_174;
F_81 ( V_2 , V_213 , F_49 ( V_122 ) , 0 ) ;
V_212 = F_110 ( V_122 ) ;
V_215 = V_212 / 2 ;
if ( ( V_212 & 1 ) && V_2 -> V_79 [ V_5 ] <= V_215 + 1 )
V_215 ++ ;
V_237 = ( V_212 - V_215 + 1 ) ;
F_128 ( V_2 , V_221 , V_215 ) ;
V_212 -= V_215 ;
F_129 ( V_122 , V_212 ) ;
F_129 ( V_123 , F_110 ( V_123 ) + V_215 ) ;
if ( V_5 > 0 ) {
union V_95 * V_222 ;
union V_51 * V_223 ;
union V_95 * V_217 ;
union V_51 * V_218 ;
V_222 = F_46 ( V_2 , V_237 , V_122 ) ;
V_223 = F_48 ( V_2 , V_237 , V_122 ) ;
V_217 = F_46 ( V_2 , 1 , V_123 ) ;
V_218 = F_48 ( V_2 , 1 , V_123 ) ;
#ifdef F_109
for ( V_66 = V_237 ; V_66 < V_215 ; V_66 ++ ) {
error = F_21 ( V_2 , V_223 , V_66 , V_5 ) ;
if ( error )
goto V_174;
}
#endif
F_89 ( V_2 , V_217 , V_222 , V_215 ) ;
F_91 ( V_2 , V_218 , V_223 , V_215 ) ;
F_95 ( V_2 , V_213 , 1 , V_215 ) ;
F_103 ( V_2 , V_213 , 1 , V_215 ) ;
F_117 ( V_2 , V_123 , V_160 ) ;
} else {
union V_94 * V_225 ;
union V_94 * V_219 ;
V_225 = F_45 ( V_2 , V_237 , V_122 ) ;
V_219 = F_45 ( V_2 , 1 , V_123 ) ;
F_90 ( V_2 , V_219 , V_225 , V_215 ) ;
F_102 ( V_2 , V_213 , 1 , V_215 ) ;
F_116 ( V_2 , V_123 , V_160 ) ;
}
F_75 ( V_2 , V_122 , & V_234 , V_128 ) ;
F_76 ( V_2 , V_123 , & V_234 , V_128 ) ;
F_76 ( V_2 , V_123 , & V_216 , V_127 ) ;
F_76 ( V_2 , V_122 , & V_231 , V_128 ) ;
F_104 ( V_2 , V_213 , V_169 ) ;
F_104 ( V_2 , V_211 , V_227 | V_128 ) ;
if ( ! F_73 ( V_2 , & V_234 ) ) {
error = F_88 ( V_2 , & V_234 ,
0 , & V_236 , & V_235 ) ;
if ( error )
goto V_174;
F_76 ( V_2 , V_236 , & V_231 , V_127 ) ;
F_104 ( V_2 , V_235 , V_127 ) ;
}
if ( V_2 -> V_46 & V_196 ) {
error = F_123 ( V_2 , V_5 ) ;
if ( error )
goto V_174;
}
if ( V_2 -> V_79 [ V_5 ] > V_212 + 1 ) {
F_72 ( V_2 , V_5 , V_213 ) ;
V_2 -> V_79 [ V_5 ] -= V_212 ;
}
if ( V_5 + 1 < V_2 -> V_67 ) {
error = F_36 ( V_2 , V_233 ) ;
if ( error )
goto V_174;
( * V_233 ) -> V_79 [ V_5 + 1 ] ++ ;
}
* V_178 = V_231 ;
F_96 ( V_2 , V_165 ) ;
* V_173 = 1 ;
return 0 ;
V_176:
F_96 ( V_2 , V_165 ) ;
* V_173 = 0 ;
return 0 ;
V_174:
F_96 ( V_2 , V_179 ) ;
return error ;
}
static void
F_134 (
struct V_241 * V_242 )
{
struct V_243 * args = F_135 ( V_242 ,
struct V_243 , V_242 ) ;
unsigned long V_244 ;
unsigned long V_245 = V_246 ;
if ( args -> V_247 )
V_245 |= V_248 | V_249 | V_250 ;
F_136 ( & V_244 , V_245 ) ;
args -> V_251 = F_132 ( args -> V_2 , args -> V_5 , args -> V_178 ,
args -> V_160 , args -> V_233 , args -> V_173 ) ;
F_137 ( args -> V_252 ) ;
F_138 ( & V_244 , V_245 ) ;
}
STATIC int
F_139 (
struct V_1 * V_2 ,
int V_5 ,
union V_51 * V_178 ,
union V_95 * V_160 ,
struct V_1 * * V_233 ,
int * V_173 )
{
struct V_243 args ;
F_140 ( V_252 ) ;
if ( V_2 -> V_69 != V_70 )
return F_132 ( V_2 , V_5 , V_178 , V_160 , V_233 , V_173 ) ;
args . V_2 = V_2 ;
args . V_5 = V_5 ;
args . V_178 = V_178 ;
args . V_160 = V_160 ;
args . V_233 = V_233 ;
args . V_173 = V_173 ;
args . V_252 = & V_252 ;
args . V_247 = F_141 () ;
F_142 ( & args . V_242 , F_134 ) ;
F_143 ( V_253 , & args . V_242 ) ;
F_144 ( & V_252 ) ;
F_145 ( & args . V_242 ) ;
return args . V_251 ;
}
int
F_146 (
struct V_1 * V_2 ,
int * V_254 ,
int * V_173 )
{
struct V_6 * V_255 ;
struct V_3 * V_4 ;
struct V_3 * V_256 ;
union V_95 * V_257 ;
union V_51 * V_258 ;
union V_95 * V_184 ;
union V_51 * V_181 ;
union V_51 V_259 ;
int V_5 ;
int error ;
#ifdef F_109
int V_66 ;
#endif
F_96 ( V_2 , V_163 ) ;
F_32 ( V_2 , V_260 ) ;
ASSERT ( V_2 -> V_46 & V_102 ) ;
V_5 = V_2 -> V_67 - 1 ;
V_4 = F_50 ( V_2 ) ;
V_181 = F_48 ( V_2 , 1 , V_4 ) ;
error = V_2 -> V_23 -> V_239 ( V_2 , V_181 , & V_259 , V_173 ) ;
if ( error )
goto V_174;
if ( * V_173 == 0 ) {
F_96 ( V_2 , V_165 ) ;
return 0 ;
}
F_32 ( V_2 , V_240 ) ;
error = F_87 ( V_2 , & V_259 , 0 , & V_256 , & V_255 ) ;
if ( error )
goto V_174;
memcpy ( V_256 , V_4 , F_39 ( V_2 ) ) ;
if ( V_2 -> V_46 & V_84 ) {
if ( V_2 -> V_46 & V_47 )
V_256 -> V_13 . V_14 . V_17 = F_4 ( V_255 -> V_18 ) ;
else
V_256 -> V_13 . V_42 . V_17 = F_4 ( V_255 -> V_18 ) ;
}
F_147 ( & V_4 -> V_21 , 1 ) ;
F_129 ( V_4 , 1 ) ;
V_2 -> V_67 ++ ;
V_2 -> V_79 [ V_5 + 1 ] = 1 ;
V_184 = F_46 ( V_2 , 1 , V_4 ) ;
V_257 = F_46 ( V_2 , 1 , V_256 ) ;
F_89 ( V_2 , V_257 , V_184 , F_110 ( V_256 ) ) ;
V_258 = F_48 ( V_2 , 1 , V_256 ) ;
#ifdef F_109
for ( V_66 = 0 ; V_66 < F_7 ( V_256 -> V_22 ) ; V_66 ++ ) {
error = F_21 ( V_2 , V_181 , V_66 , V_5 ) ;
if ( error )
goto V_174;
}
#endif
F_91 ( V_2 , V_258 , V_181 , F_110 ( V_256 ) ) ;
#ifdef F_109
error = F_21 ( V_2 , & V_259 , 0 , V_5 ) ;
if ( error )
goto V_174;
#endif
F_91 ( V_2 , V_181 , & V_259 , 1 ) ;
F_148 ( V_2 -> V_39 . V_71 . V_98 ,
1 - F_110 ( V_256 ) ,
V_2 -> V_39 . V_71 . V_99 ) ;
F_72 ( V_2 , V_5 , V_255 ) ;
F_104 ( V_2 , V_255 , V_169 ) ;
F_95 ( V_2 , V_255 , 1 , F_7 ( V_256 -> V_22 ) ) ;
F_103 ( V_2 , V_255 , 1 , F_7 ( V_256 -> V_22 ) ) ;
* V_254 |=
V_261 | F_101 ( V_2 -> V_39 . V_71 . V_99 ) ;
* V_173 = 1 ;
F_96 ( V_2 , V_165 ) ;
return 0 ;
V_174:
F_96 ( V_2 , V_179 ) ;
return error ;
}
STATIC int
F_149 (
struct V_1 * V_2 ,
int * V_173 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int error ;
struct V_6 * V_211 ;
struct V_3 * V_122 ;
struct V_6 * V_262 ;
struct V_3 * V_75 ;
int V_259 ;
struct V_6 * V_213 ;
struct V_3 * V_123 ;
union V_51 V_231 ;
union V_51 V_216 ;
F_96 ( V_2 , V_163 ) ;
F_32 ( V_2 , V_260 ) ;
V_2 -> V_23 -> V_188 ( V_2 , & V_231 ) ;
error = V_2 -> V_23 -> V_239 ( V_2 , & V_231 , & V_216 , V_173 ) ;
if ( error )
goto V_174;
if ( * V_173 == 0 )
goto V_176;
F_32 ( V_2 , V_240 ) ;
error = F_87 ( V_2 , & V_216 , 0 , & V_75 , & V_262 ) ;
if ( error )
goto V_174;
V_2 -> V_23 -> V_263 ( V_2 , & V_216 , 1 ) ;
V_4 = F_52 ( V_2 , V_2 -> V_67 - 1 , & V_7 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_4 , V_2 -> V_67 - 1 , V_7 ) ;
if ( error )
goto V_174;
#endif
F_75 ( V_2 , V_4 , & V_231 , V_128 ) ;
if ( ! F_73 ( V_2 , & V_231 ) ) {
V_211 = V_7 ;
F_83 ( V_2 , V_211 , & V_216 ) ;
V_122 = V_4 ;
error = F_88 ( V_2 , & V_231 , 0 , & V_123 , & V_213 ) ;
if ( error )
goto V_174;
V_7 = V_213 ;
V_259 = 1 ;
} else {
V_213 = V_7 ;
F_83 ( V_2 , V_213 , & V_231 ) ;
V_123 = V_4 ;
F_75 ( V_2 , V_123 , & V_216 , V_127 ) ;
error = F_88 ( V_2 , & V_216 , 0 , & V_122 , & V_211 ) ;
if ( error )
goto V_174;
V_7 = V_211 ;
V_259 = 2 ;
}
F_81 ( V_2 , V_262 , V_2 -> V_67 , 2 ) ;
F_104 ( V_2 , V_262 , V_169 ) ;
ASSERT ( ! F_73 ( V_2 , & V_216 ) &&
! F_73 ( V_2 , & V_231 ) ) ;
if ( F_49 ( V_122 ) > 0 ) {
F_117 ( V_2 , V_122 ,
F_46 ( V_2 , 1 , V_75 ) ) ;
F_117 ( V_2 , V_123 ,
F_46 ( V_2 , 2 , V_75 ) ) ;
} else {
F_116 ( V_2 , V_122 ,
F_46 ( V_2 , 1 , V_75 ) ) ;
F_116 ( V_2 , V_123 ,
F_46 ( V_2 , 2 , V_75 ) ) ;
}
F_95 ( V_2 , V_262 , 1 , 2 ) ;
F_91 ( V_2 ,
F_48 ( V_2 , 1 , V_75 ) , & V_216 , 1 ) ;
F_91 ( V_2 ,
F_48 ( V_2 , 2 , V_75 ) , & V_231 , 1 ) ;
F_103 ( V_2 , V_262 , 1 , 2 ) ;
F_72 ( V_2 , V_2 -> V_67 , V_262 ) ;
V_2 -> V_79 [ V_2 -> V_67 ] = V_259 ;
V_2 -> V_67 ++ ;
F_96 ( V_2 , V_165 ) ;
* V_173 = 1 ;
return 0 ;
V_174:
F_96 ( V_2 , V_179 ) ;
return error ;
V_176:
F_96 ( V_2 , V_165 ) ;
* V_173 = 0 ;
return 0 ;
}
STATIC int
F_150 (
struct V_1 * V_2 ,
int V_5 ,
int V_132 ,
int * V_264 ,
int * V_53 ,
union V_51 * V_259 ,
struct V_1 * * V_74 ,
union V_95 * V_160 ,
int * V_173 )
{
int error = 0 ;
if ( ( V_2 -> V_46 & V_102 ) &&
V_5 == V_2 -> V_67 - 1 ) {
struct V_265 * V_98 = V_2 -> V_39 . V_71 . V_98 ;
if ( V_132 < V_2 -> V_23 -> V_266 ( V_2 , V_5 ) ) {
F_148 ( V_98 , 1 , V_2 -> V_39 . V_71 . V_99 ) ;
* V_173 = 1 ;
} else {
int V_254 = 0 ;
error = F_146 ( V_2 , & V_254 , V_173 ) ;
if ( error || * V_173 == 0 )
return error ;
F_100 ( V_2 -> V_65 , V_98 , V_254 ) ;
}
return 0 ;
}
error = F_131 ( V_2 , V_5 , V_173 ) ;
if ( error || * V_173 )
return error ;
error = F_127 ( V_2 , V_5 , V_173 ) ;
if ( error )
return error ;
if ( * V_173 ) {
* V_264 = * V_53 = V_2 -> V_79 [ V_5 ] ;
return 0 ;
}
error = F_139 ( V_2 , V_5 , V_259 , V_160 , V_74 , V_173 ) ;
if ( error || * V_173 == 0 )
return error ;
* V_53 = V_2 -> V_79 [ V_5 ] ;
return 0 ;
}
STATIC int
F_151 (
struct V_1 * V_2 ,
int V_5 ,
union V_51 * V_178 ,
union V_94 * V_162 ,
union V_95 * V_160 ,
struct V_1 * * V_233 ,
int * V_173 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_51 V_259 ;
struct V_1 * V_74 ;
union V_203 V_267 ;
union V_95 * V_204 ;
int V_268 ;
int V_52 ;
int V_132 ;
int error ;
#ifdef F_109
int V_66 ;
#endif
T_9 V_269 ;
F_96 ( V_2 , V_163 ) ;
F_152 ( V_2 , V_5 , * V_178 , & V_162 ) ;
V_74 = NULL ;
V_204 = (union V_95 * ) & V_267 ;
if ( ! ( V_2 -> V_46 & V_102 ) &&
( V_5 >= V_2 -> V_67 ) ) {
error = F_149 ( V_2 , V_173 ) ;
F_74 ( V_2 , V_178 ) ;
F_96 ( V_2 , V_165 ) ;
return error ;
}
V_52 = V_2 -> V_79 [ V_5 ] ;
if ( V_52 == 0 ) {
F_96 ( V_2 , V_165 ) ;
* V_173 = 0 ;
return 0 ;
}
V_268 = V_52 ;
F_32 ( V_2 , V_270 ) ;
V_4 = F_52 ( V_2 , V_5 , & V_7 ) ;
V_269 = V_7 ? V_7 -> V_18 : V_19 ;
V_132 = F_110 ( V_4 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_174;
if ( V_52 <= V_132 ) {
if ( V_5 == 0 ) {
ASSERT ( V_2 -> V_23 -> V_226 ( V_2 , V_162 ,
F_45 ( V_2 , V_52 , V_4 ) ) ) ;
} else {
ASSERT ( V_2 -> V_23 -> V_224 ( V_2 , V_160 ,
F_46 ( V_2 , V_52 , V_4 ) ) ) ;
}
}
#endif
F_74 ( V_2 , & V_259 ) ;
if ( V_132 == V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ) {
error = F_150 ( V_2 , V_5 , V_132 ,
& V_268 , & V_52 , & V_259 , & V_74 , V_204 , V_173 ) ;
if ( error || * V_173 == 0 )
goto V_174;
}
V_4 = F_52 ( V_2 , V_5 , & V_7 ) ;
V_132 = F_110 ( V_4 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
return error ;
#endif
F_128 ( V_2 , V_221 , V_132 - V_52 + 1 ) ;
if ( V_5 > 0 ) {
union V_95 * V_184 ;
union V_51 * V_181 ;
V_184 = F_46 ( V_2 , V_52 , V_4 ) ;
V_181 = F_48 ( V_2 , V_52 , V_4 ) ;
#ifdef F_109
for ( V_66 = V_132 - V_52 ; V_66 >= 0 ; V_66 -- ) {
error = F_21 ( V_2 , V_181 , V_66 , V_5 ) ;
if ( error )
return error ;
}
#endif
F_92 ( V_2 , V_184 , 1 , V_132 - V_52 + 1 ) ;
F_94 ( V_2 , V_181 , 1 , V_132 - V_52 + 1 ) ;
#ifdef F_109
error = F_21 ( V_2 , V_178 , 0 , V_5 ) ;
if ( error )
goto V_174;
#endif
F_89 ( V_2 , V_184 , V_160 , 1 ) ;
F_91 ( V_2 , V_181 , V_178 , 1 ) ;
V_132 ++ ;
F_129 ( V_4 , V_132 ) ;
F_103 ( V_2 , V_7 , V_52 , V_132 ) ;
F_95 ( V_2 , V_7 , V_52 , V_132 ) ;
#ifdef F_109
if ( V_52 < V_132 ) {
ASSERT ( V_2 -> V_23 -> V_224 ( V_2 , V_184 ,
F_46 ( V_2 , V_52 + 1 , V_4 ) ) ) ;
}
#endif
} else {
union V_94 * V_208 ;
V_208 = F_45 ( V_2 , V_52 , V_4 ) ;
F_93 ( V_2 , V_208 , 1 , V_132 - V_52 + 1 ) ;
F_90 ( V_2 , V_208 , V_162 , 1 ) ;
F_129 ( V_4 , ++ V_132 ) ;
F_102 ( V_2 , V_7 , V_52 , V_132 ) ;
#ifdef F_109
if ( V_52 < V_132 ) {
ASSERT ( V_2 -> V_23 -> V_226 ( V_2 , V_208 ,
F_45 ( V_2 , V_52 + 1 , V_4 ) ) ) ;
}
#endif
}
F_104 ( V_2 , V_7 , V_227 ) ;
if ( V_7 && V_7 -> V_18 != V_269 ) {
F_118 ( V_2 , V_4 , V_204 ) ;
} else if ( F_119 ( V_2 , V_268 ) ) {
error = F_123 ( V_2 , V_5 ) ;
if ( error )
goto V_174;
}
if ( F_82 ( V_2 , V_4 , V_5 ) ) {
V_2 -> V_23 -> V_209 ( V_2 , V_4 , V_162 ,
V_52 , V_271 ) ;
}
* V_178 = V_259 ;
if ( ! F_73 ( V_2 , & V_259 ) ) {
F_89 ( V_2 , V_160 , V_204 , 1 ) ;
* V_233 = V_74 ;
}
F_96 ( V_2 , V_165 ) ;
* V_173 = 1 ;
return 0 ;
V_174:
F_96 ( V_2 , V_179 ) ;
return error ;
}
int
F_153 (
struct V_1 * V_2 ,
int * V_173 )
{
int error ;
int V_66 ;
int V_5 ;
union V_51 V_259 ;
struct V_1 * V_74 ;
struct V_1 * V_272 ;
union V_203 V_273 ;
union V_95 * V_160 ;
union V_94 V_162 ;
V_5 = 0 ;
V_74 = NULL ;
V_272 = V_2 ;
V_160 = (union V_95 * ) & V_273 ;
F_74 ( V_2 , & V_259 ) ;
V_2 -> V_23 -> V_274 ( V_2 , & V_162 ) ;
V_2 -> V_23 -> V_185 ( V_160 , & V_162 ) ;
do {
error = F_151 ( V_272 , V_5 , & V_259 , & V_162 , V_160 ,
& V_74 , & V_66 ) ;
if ( error ) {
if ( V_272 != V_2 )
F_33 ( V_272 , V_230 ) ;
goto V_174;
}
F_130 ( V_2 -> V_11 , V_66 == 1 , V_174 ) ;
V_5 ++ ;
if ( V_272 != V_2 &&
( V_74 || F_73 ( V_2 , & V_259 ) ) ) {
if ( V_2 -> V_23 -> V_275 )
V_2 -> V_23 -> V_275 ( V_272 , V_2 ) ;
V_2 -> V_67 = V_272 -> V_67 ;
F_33 ( V_272 , V_229 ) ;
}
if ( V_74 ) {
V_272 = V_74 ;
V_74 = NULL ;
}
} while ( ! F_73 ( V_2 , & V_259 ) );
F_96 ( V_2 , V_165 ) ;
* V_173 = V_66 ;
return 0 ;
V_174:
F_96 ( V_2 , V_179 ) ;
return error ;
}
STATIC int
F_154 (
struct V_1 * V_2 )
{
int V_99 = V_2 -> V_39 . V_71 . V_99 ;
struct V_265 * V_98 = V_2 -> V_39 . V_71 . V_98 ;
struct V_96 * V_97 = F_51 ( V_98 , V_99 ) ;
struct V_3 * V_4 ;
struct V_3 * V_256 ;
union V_95 * V_184 ;
union V_95 * V_257 ;
union V_51 * V_181 ;
union V_51 * V_258 ;
struct V_6 * V_255 ;
int V_5 ;
int V_53 ;
int V_132 ;
int error ;
#ifdef F_109
union V_51 V_52 ;
int V_66 ;
#endif
F_96 ( V_2 , V_163 ) ;
ASSERT ( V_2 -> V_46 & V_102 ) ;
ASSERT ( V_2 -> V_67 > 1 ) ;
V_5 = V_2 -> V_67 - 1 ;
if ( V_5 == 1 )
goto V_176;
V_4 = F_50 ( V_2 ) ;
if ( F_110 ( V_4 ) != 1 )
goto V_176;
V_256 = F_52 ( V_2 , V_5 - 1 , & V_255 ) ;
V_132 = F_110 ( V_256 ) ;
if ( V_132 > V_2 -> V_23 -> V_266 ( V_2 , V_5 ) )
goto V_176;
F_32 ( V_2 , V_276 ) ;
#ifdef F_109
F_75 ( V_2 , V_4 , & V_52 , V_127 ) ;
ASSERT ( F_73 ( V_2 , & V_52 ) ) ;
F_75 ( V_2 , V_4 , & V_52 , V_128 ) ;
ASSERT ( F_73 ( V_2 , & V_52 ) ) ;
#endif
V_53 = V_132 - V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ;
if ( V_53 ) {
F_148 ( V_2 -> V_39 . V_71 . V_98 , V_53 ,
V_2 -> V_39 . V_71 . V_99 ) ;
V_4 = V_97 -> V_100 ;
}
F_147 ( & V_4 -> V_22 , V_53 ) ;
ASSERT ( V_4 -> V_22 == V_256 -> V_22 ) ;
V_184 = F_46 ( V_2 , 1 , V_4 ) ;
V_257 = F_46 ( V_2 , 1 , V_256 ) ;
F_89 ( V_2 , V_184 , V_257 , V_132 ) ;
V_181 = F_48 ( V_2 , 1 , V_4 ) ;
V_258 = F_48 ( V_2 , 1 , V_256 ) ;
#ifdef F_109
for ( V_66 = 0 ; V_66 < V_132 ; V_66 ++ ) {
error = F_21 ( V_2 , V_258 , V_66 , V_5 - 1 ) ;
if ( error ) {
F_96 ( V_2 , V_179 ) ;
return error ;
}
}
#endif
F_91 ( V_2 , V_181 , V_258 , V_132 ) ;
error = F_30 ( V_2 , V_255 ) ;
if ( error ) {
F_96 ( V_2 , V_179 ) ;
return error ;
}
V_2 -> V_68 [ V_5 - 1 ] = NULL ;
F_147 ( & V_4 -> V_21 , - 1 ) ;
F_100 ( V_2 -> V_65 , V_98 ,
V_261 | F_101 ( V_2 -> V_39 . V_71 . V_99 ) ) ;
V_2 -> V_67 -- ;
V_176:
F_96 ( V_2 , V_165 ) ;
return 0 ;
}
STATIC int
F_155 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_5 ,
union V_51 * V_260 )
{
int error ;
F_96 ( V_2 , V_163 ) ;
F_32 ( V_2 , V_276 ) ;
V_2 -> V_23 -> V_263 ( V_2 , V_260 , - 1 ) ;
error = F_30 ( V_2 , V_7 ) ;
if ( error ) {
F_96 ( V_2 , V_179 ) ;
return error ;
}
V_2 -> V_68 [ V_5 ] = NULL ;
V_2 -> V_80 [ V_5 ] = 0 ;
V_2 -> V_67 -- ;
F_96 ( V_2 , V_165 ) ;
return 0 ;
}
STATIC int
F_156 (
struct V_1 * V_2 ,
int V_5 ,
int * V_173 )
{
int error ;
int V_66 ;
if ( V_5 > 0 ) {
error = F_111 ( V_2 , V_5 , & V_66 ) ;
if ( error )
return error ;
}
F_96 ( V_2 , V_165 ) ;
* V_173 = 1 ;
return 0 ;
}
STATIC int
F_157 (
struct V_1 * V_2 ,
int V_5 ,
int * V_173 )
{
struct V_3 * V_4 ;
union V_51 V_277 ;
struct V_6 * V_7 ;
int error ;
int V_66 ;
union V_51 V_216 ;
struct V_6 * V_211 ;
struct V_3 * V_122 ;
int V_212 = 0 ;
int V_52 ;
union V_51 V_231 ;
struct V_6 * V_213 ;
struct V_3 * V_123 ;
struct V_3 * V_236 ;
struct V_6 * V_235 ;
int V_215 = 0 ;
struct V_1 * V_214 ;
int V_132 ;
F_96 ( V_2 , V_163 ) ;
F_108 ( V_2 , V_5 ) ;
V_214 = NULL ;
V_52 = V_2 -> V_79 [ V_5 ] ;
if ( V_52 == 0 ) {
F_96 ( V_2 , V_165 ) ;
* V_173 = 0 ;
return 0 ;
}
V_4 = F_52 ( V_2 , V_5 , & V_7 ) ;
V_132 = F_110 ( V_4 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_174;
#endif
if ( V_52 > V_132 ) {
F_96 ( V_2 , V_165 ) ;
* V_173 = 0 ;
return 0 ;
}
F_32 ( V_2 , V_278 ) ;
F_128 ( V_2 , V_221 , V_132 - V_52 ) ;
if ( V_5 > 0 ) {
union V_95 * V_222 ;
union V_51 * V_223 ;
V_222 = F_46 ( V_2 , V_52 + 1 , V_4 ) ;
V_223 = F_48 ( V_2 , V_52 + 1 , V_4 ) ;
#ifdef F_109
for ( V_66 = 0 ; V_66 < V_132 - V_52 ; V_66 ++ ) {
error = F_21 ( V_2 , V_223 , V_66 , V_5 ) ;
if ( error )
goto V_174;
}
#endif
if ( V_52 < V_132 ) {
F_92 ( V_2 , V_222 , - 1 , V_132 - V_52 ) ;
F_94 ( V_2 , V_223 , - 1 , V_132 - V_52 ) ;
F_95 ( V_2 , V_7 , V_52 , V_132 - 1 ) ;
F_103 ( V_2 , V_7 , V_52 , V_132 - 1 ) ;
}
} else {
if ( V_52 < V_132 ) {
F_93 ( V_2 ,
F_45 ( V_2 , V_52 + 1 , V_4 ) ,
- 1 , V_132 - V_52 ) ;
F_102 ( V_2 , V_7 , V_52 , V_132 - 1 ) ;
}
}
F_129 ( V_4 , -- V_132 ) ;
F_104 ( V_2 , V_7 , V_227 ) ;
if ( F_82 ( V_2 , V_4 , V_5 ) ) {
V_2 -> V_23 -> V_209 ( V_2 , V_4 , NULL ,
V_52 , V_279 ) ;
}
if ( V_5 == V_2 -> V_67 - 1 ) {
if ( V_2 -> V_46 & V_102 ) {
F_148 ( V_2 -> V_39 . V_71 . V_98 , - 1 ,
V_2 -> V_39 . V_71 . V_99 ) ;
error = F_154 ( V_2 ) ;
if ( error )
goto V_174;
error = F_156 ( V_2 , V_5 , V_173 ) ;
if ( error )
goto V_174;
* V_173 = 1 ;
return 0 ;
}
if ( V_132 == 1 && V_5 > 0 ) {
union V_51 * V_181 ;
V_181 = F_48 ( V_2 , 1 , V_4 ) ;
error = F_155 ( V_2 , V_7 , V_5 , V_181 ) ;
if ( error )
goto V_174;
} else if ( V_5 > 0 ) {
error = F_156 ( V_2 , V_5 , V_173 ) ;
if ( error )
goto V_174;
}
* V_173 = 1 ;
return 0 ;
}
if ( F_119 ( V_2 , V_52 ) ) {
error = F_123 ( V_2 , V_5 ) ;
if ( error )
goto V_174;
}
if ( V_132 >= V_2 -> V_23 -> V_280 ( V_2 , V_5 ) ) {
error = F_156 ( V_2 , V_5 , V_173 ) ;
if ( error )
goto V_174;
return 0 ;
}
F_75 ( V_2 , V_4 , & V_231 , V_128 ) ;
F_75 ( V_2 , V_4 , & V_216 , V_127 ) ;
if ( V_2 -> V_46 & V_102 ) {
if ( F_73 ( V_2 , & V_231 ) &&
F_73 ( V_2 , & V_216 ) &&
V_5 == V_2 -> V_67 - 2 ) {
error = F_154 ( V_2 ) ;
if ( ! error )
error = F_156 ( V_2 , V_5 , V_173 ) ;
if ( error )
goto V_174;
return 0 ;
}
}
ASSERT ( ! F_73 ( V_2 , & V_231 ) ||
! F_73 ( V_2 , & V_216 ) ) ;
error = F_36 ( V_2 , & V_214 ) ;
if ( error )
goto V_174;
if ( ! F_73 ( V_2 , & V_231 ) ) {
V_66 = F_60 ( V_214 , V_5 ) ;
F_130 ( V_2 -> V_11 , V_66 == 1 , V_174 ) ;
error = F_107 ( V_214 , V_5 , & V_66 ) ;
if ( error )
goto V_174;
F_130 ( V_2 -> V_11 , V_66 == 1 , V_174 ) ;
V_66 = F_60 ( V_214 , V_5 ) ;
F_130 ( V_2 -> V_11 , V_66 == 1 , V_174 ) ;
V_123 = F_52 ( V_214 , V_5 , & V_213 ) ;
#ifdef F_109
error = F_17 ( V_214 , V_123 , V_5 , V_213 ) ;
if ( error )
goto V_174;
#endif
F_75 ( V_214 , V_123 , & V_277 , V_127 ) ;
if ( F_110 ( V_123 ) - 1 >=
V_2 -> V_23 -> V_280 ( V_214 , V_5 ) ) {
error = F_127 ( V_214 , V_5 , & V_66 ) ;
if ( error )
goto V_174;
if ( V_66 ) {
ASSERT ( F_110 ( V_4 ) >=
V_2 -> V_23 -> V_280 ( V_214 , V_5 ) ) ;
F_33 ( V_214 , V_229 ) ;
V_214 = NULL ;
error = F_156 ( V_2 , V_5 , V_173 ) ;
if ( error )
goto V_174;
return 0 ;
}
}
V_215 = F_110 ( V_123 ) ;
if ( ! F_73 ( V_2 , & V_216 ) ) {
V_66 = F_59 ( V_214 , V_5 ) ;
F_130 ( V_2 -> V_11 , V_66 == 1 , V_174 ) ;
error = F_111 ( V_214 , V_5 , & V_66 ) ;
if ( error )
goto V_174;
F_130 ( V_2 -> V_11 , V_66 == 1 , V_174 ) ;
}
}
if ( ! F_73 ( V_2 , & V_216 ) ) {
V_66 = F_59 ( V_214 , V_5 ) ;
F_130 ( V_2 -> V_11 , V_66 == 1 , V_174 ) ;
error = F_111 ( V_214 , V_5 , & V_66 ) ;
if ( error )
goto V_174;
V_66 = F_59 ( V_214 , V_5 ) ;
F_130 ( V_2 -> V_11 , V_66 == 1 , V_174 ) ;
V_122 = F_52 ( V_214 , V_5 , & V_211 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_122 , V_5 , V_211 ) ;
if ( error )
goto V_174;
#endif
F_75 ( V_214 , V_122 , & V_277 , V_128 ) ;
if ( F_110 ( V_122 ) - 1 >=
V_2 -> V_23 -> V_280 ( V_214 , V_5 ) ) {
error = F_131 ( V_214 , V_5 , & V_66 ) ;
if ( error )
goto V_174;
if ( V_66 ) {
ASSERT ( F_110 ( V_4 ) >=
V_2 -> V_23 -> V_280 ( V_214 , V_5 ) ) ;
F_33 ( V_214 , V_229 ) ;
V_214 = NULL ;
if ( V_5 == 0 )
V_2 -> V_79 [ 0 ] ++ ;
F_96 ( V_2 , V_165 ) ;
* V_173 = 1 ;
return 0 ;
}
}
V_212 = F_110 ( V_122 ) ;
}
F_33 ( V_214 , V_229 ) ;
V_214 = NULL ;
ASSERT ( ! F_73 ( V_2 , & V_277 ) ) ;
if ( ! F_73 ( V_2 , & V_216 ) &&
V_212 + F_110 ( V_4 ) <=
V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ) {
V_231 = V_277 ;
V_123 = V_4 ;
V_213 = V_7 ;
error = F_88 ( V_2 , & V_216 , 0 , & V_122 , & V_211 ) ;
if ( error )
goto V_174;
} else if ( ! F_73 ( V_2 , & V_231 ) &&
V_215 + F_110 ( V_4 ) <=
V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ) {
V_216 = V_277 ;
V_122 = V_4 ;
V_211 = V_7 ;
error = F_88 ( V_2 , & V_231 , 0 , & V_123 , & V_213 ) ;
if ( error )
goto V_174;
} else {
error = F_156 ( V_2 , V_5 , V_173 ) ;
if ( error )
goto V_174;
return 0 ;
}
V_215 = F_110 ( V_123 ) ;
V_212 = F_110 ( V_122 ) ;
F_128 ( V_2 , V_221 , V_215 ) ;
if ( V_5 > 0 ) {
union V_95 * V_222 ;
union V_51 * V_223 ;
union V_95 * V_217 ;
union V_51 * V_218 ;
V_222 = F_46 ( V_2 , V_212 + 1 , V_122 ) ;
V_223 = F_48 ( V_2 , V_212 + 1 , V_122 ) ;
V_217 = F_46 ( V_2 , 1 , V_123 ) ;
V_218 = F_48 ( V_2 , 1 , V_123 ) ;
#ifdef F_109
for ( V_66 = 1 ; V_66 < V_215 ; V_66 ++ ) {
error = F_21 ( V_2 , V_218 , V_66 , V_5 ) ;
if ( error )
goto V_174;
}
#endif
F_89 ( V_2 , V_222 , V_217 , V_215 ) ;
F_91 ( V_2 , V_223 , V_218 , V_215 ) ;
F_95 ( V_2 , V_211 , V_212 + 1 , V_212 + V_215 ) ;
F_103 ( V_2 , V_211 , V_212 + 1 , V_212 + V_215 ) ;
} else {
union V_94 * V_225 ;
union V_94 * V_219 ;
V_225 = F_45 ( V_2 , V_212 + 1 , V_122 ) ;
V_219 = F_45 ( V_2 , 1 , V_123 ) ;
F_90 ( V_2 , V_225 , V_219 , V_215 ) ;
F_102 ( V_2 , V_211 , V_212 + 1 , V_212 + V_215 ) ;
}
F_32 ( V_2 , V_281 ) ;
F_129 ( V_122 , V_212 + V_215 ) ;
F_75 ( V_2 , V_123 , & V_277 , V_128 ) ,
F_76 ( V_2 , V_122 , & V_277 , V_128 ) ;
F_104 ( V_2 , V_211 , V_227 | V_128 ) ;
F_75 ( V_2 , V_122 , & V_277 , V_128 ) ;
if ( ! F_73 ( V_2 , & V_277 ) ) {
error = F_88 ( V_2 , & V_277 , 0 , & V_236 , & V_235 ) ;
if ( error )
goto V_174;
F_76 ( V_2 , V_236 , & V_216 , V_127 ) ;
F_104 ( V_2 , V_235 , V_127 ) ;
}
error = F_30 ( V_2 , V_213 ) ;
if ( error )
goto V_174;
if ( V_7 != V_211 ) {
V_2 -> V_68 [ V_5 ] = V_211 ;
V_2 -> V_79 [ V_5 ] += V_212 ;
V_2 -> V_80 [ V_5 ] = 0 ;
}
else if ( ( V_2 -> V_46 & V_102 ) ||
( V_5 + 1 < V_2 -> V_67 ) ) {
error = F_107 ( V_2 , V_5 + 1 , & V_66 ) ;
if ( error )
goto V_174;
}
if ( V_5 > 0 )
V_2 -> V_79 [ V_5 ] -- ;
F_96 ( V_2 , V_165 ) ;
* V_173 = 2 ;
return 0 ;
V_174:
F_96 ( V_2 , V_179 ) ;
if ( V_214 )
F_33 ( V_214 , V_230 ) ;
return error ;
}
int
F_158 (
struct V_1 * V_2 ,
int * V_173 )
{
int error ;
int V_5 ;
int V_66 ;
bool V_282 = false ;
F_96 ( V_2 , V_163 ) ;
for ( V_5 = 0 , V_66 = 2 ; V_66 == 2 ; V_5 ++ ) {
error = F_157 ( V_2 , V_5 , & V_66 ) ;
if ( error )
goto V_174;
if ( V_66 == 2 )
V_282 = true ;
}
if ( V_282 && ( V_2 -> V_46 & V_196 ) ) {
error = F_122 ( V_2 , 0 ) ;
if ( error )
goto V_174;
}
if ( V_66 == 0 ) {
for ( V_5 = 1 ; V_5 < V_2 -> V_67 ; V_5 ++ ) {
if ( V_2 -> V_79 [ V_5 ] == 0 ) {
error = F_111 ( V_2 , V_5 , & V_66 ) ;
if ( error )
goto V_174;
break;
}
}
}
F_96 ( V_2 , V_165 ) ;
* V_173 = V_66 ;
return 0 ;
V_174:
F_96 ( V_2 , V_179 ) ;
return error ;
}
int
F_159 (
struct V_1 * V_2 ,
union V_94 * * V_283 ,
int * V_173 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int V_52 ;
#ifdef F_109
int error ;
#endif
V_52 = V_2 -> V_79 [ 0 ] ;
V_4 = F_52 ( V_2 , 0 , & V_7 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_4 , 0 , V_7 ) ;
if ( error )
return error ;
#endif
if ( V_52 > F_110 ( V_4 ) || V_52 <= 0 ) {
* V_173 = 0 ;
return 0 ;
}
* V_283 = F_45 ( V_2 , V_52 , V_4 ) ;
* V_173 = 1 ;
return 0 ;
}
STATIC int
F_160 (
struct V_1 * V_2 ,
int V_5 ,
T_17 V_284 ,
void * V_285 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_51 V_231 ;
int error ;
F_69 ( V_2 , V_5 , V_125 ) ;
V_4 = F_52 ( V_2 , V_5 , & V_7 ) ;
error = V_284 ( V_2 , V_5 , V_285 ) ;
if ( error )
return error ;
F_75 ( V_2 , V_4 , & V_231 , V_128 ) ;
if ( F_73 ( V_2 , & V_231 ) )
return - V_286 ;
return F_112 ( V_2 , V_5 , & V_231 , & V_4 ) ;
}
int
F_161 (
struct V_1 * V_2 ,
T_17 V_284 ,
void * V_285 )
{
union V_51 V_216 ;
int V_5 ;
struct V_3 * V_4 = NULL ;
int error = 0 ;
V_2 -> V_23 -> V_188 ( V_2 , & V_216 ) ;
for ( V_5 = V_2 -> V_67 - 1 ; V_5 >= 0 ; V_5 -- ) {
error = F_112 ( V_2 , V_5 , & V_216 , & V_4 ) ;
if ( error )
return error ;
if ( V_5 > 0 ) {
union V_51 * V_52 ;
V_52 = F_48 ( V_2 , 1 , V_4 ) ;
F_71 ( V_2 , V_52 , 1 ) ;
V_216 = * V_52 ;
}
do {
error = F_160 ( V_2 , V_5 , V_284 , V_285 ) ;
} while ( ! error );
if ( error != - V_286 )
return error ;
}
return 0 ;
}
static int
F_162 (
struct V_1 * V_2 ,
int V_5 ,
void * V_285 )
{
struct V_287 * V_288 = V_285 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
V_4 = F_52 ( V_2 , V_5 , & V_7 ) ;
if ( V_2 -> V_46 & V_47 )
V_4 -> V_13 . V_14 . V_135 = F_4 ( V_288 -> V_289 ) ;
else
V_4 -> V_13 . V_42 . V_135 = F_16 ( V_288 -> V_289 ) ;
if ( V_7 ) {
if ( V_2 -> V_65 ) {
F_163 ( V_2 -> V_65 , V_7 ) ;
F_104 ( V_2 , V_7 , V_290 ) ;
} else {
F_164 ( V_7 , V_288 -> V_291 ) ;
}
} else {
ASSERT ( V_2 -> V_46 & V_102 ) ;
ASSERT ( V_5 == V_2 -> V_67 - 1 ) ;
}
return 0 ;
}
int
F_165 (
struct V_1 * V_2 ,
T_18 V_289 ,
struct V_292 * V_291 )
{
struct V_287 V_288 ;
V_288 . V_289 = V_289 ;
V_288 . V_291 = V_291 ;
return F_161 ( V_2 , F_162 ,
& V_288 ) ;
}
bool
F_166 (
struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_57 -> V_58 ;
struct V_3 * V_4 = F_23 ( V_7 ) ;
struct V_293 * V_294 = V_7 -> V_295 ;
if ( ! F_2 ( & V_10 -> V_12 ) )
return false ;
if ( ! F_3 ( & V_4 -> V_13 . V_42 . V_15 , & V_10 -> V_12 . V_16 ) )
return false ;
if ( V_4 -> V_13 . V_42 . V_17 != F_4 ( V_7 -> V_18 ) )
return false ;
if ( V_294 && F_5 ( V_4 -> V_13 . V_42 . V_135 ) != V_294 -> V_296 )
return false ;
return true ;
}
bool
F_167 (
struct V_6 * V_7 ,
unsigned int V_297 )
{
struct V_9 * V_10 = V_7 -> V_57 -> V_58 ;
struct V_3 * V_4 = F_23 ( V_7 ) ;
if ( F_7 ( V_4 -> V_22 ) > V_297 )
return false ;
if ( ! V_4 -> V_13 . V_42 . V_25 ||
( F_5 ( V_4 -> V_13 . V_42 . V_25 ) >= V_10 -> V_12 . V_50 &&
V_4 -> V_13 . V_42 . V_25 != F_16 ( V_43 ) ) )
return false ;
if ( ! V_4 -> V_13 . V_42 . V_27 ||
( F_5 ( V_4 -> V_13 . V_42 . V_27 ) >= V_10 -> V_12 . V_50 &&
V_4 -> V_13 . V_42 . V_27 != F_16 ( V_43 ) ) )
return false ;
return true ;
}
T_8
F_168 (
struct V_9 * V_10 ,
T_8 * V_298 ,
unsigned long V_299 )
{
T_8 V_5 ;
unsigned long V_300 ;
V_300 = ( V_299 + V_298 [ 0 ] - 1 ) / V_298 [ 0 ] ;
for ( V_5 = 1 ; V_300 > 1 ; V_5 ++ )
V_300 = ( V_300 + V_298 [ 1 ] - 1 ) / V_298 [ 1 ] ;
return V_5 ;
}
STATIC int
F_169 (
struct V_1 * V_2 ,
union V_95 * V_301 ,
union V_95 * V_302 ,
T_19 V_284 ,
void * V_303 )
{
union V_94 * V_283 ;
union V_95 V_304 ;
T_11 V_186 ;
int V_173 ;
bool V_305 = true ;
int error ;
ASSERT ( V_2 -> V_23 -> V_199 ) ;
ASSERT ( V_2 -> V_23 -> V_200 ) ;
V_173 = 0 ;
error = F_114 ( V_2 , V_191 , & V_173 ) ;
if ( error )
goto V_306;
if ( ! V_173 ) {
error = F_107 ( V_2 , 0 , & V_173 ) ;
if ( error )
goto V_306;
}
while ( V_173 ) {
error = F_159 ( V_2 , & V_283 , & V_173 ) ;
if ( error || ! V_173 )
break;
if ( V_305 ) {
V_2 -> V_23 -> V_199 ( & V_304 , V_283 ) ;
V_305 = false ;
V_186 = V_2 -> V_23 -> V_200 ( V_2 , V_301 ,
& V_304 ) ;
if ( V_186 > 0 )
goto V_307;
}
V_2 -> V_23 -> V_185 ( & V_304 , V_283 ) ;
V_186 = V_2 -> V_23 -> V_200 ( V_2 , & V_304 , V_302 ) ;
if ( V_186 > 0 )
break;
error = V_284 ( V_2 , V_283 , V_303 ) ;
if ( error < 0 || error == V_308 )
break;
V_307:
error = F_107 ( V_2 , 0 , & V_173 ) ;
if ( error )
break;
}
V_306:
return error ;
}
STATIC int
F_170 (
struct V_1 * V_2 ,
union V_95 * V_301 ,
union V_95 * V_302 ,
T_19 V_284 ,
void * V_303 )
{
union V_51 V_52 ;
union V_51 * V_181 ;
union V_95 V_304 ;
union V_95 V_309 ;
union V_95 * V_222 ;
union V_95 * V_310 ;
union V_94 * V_283 ;
struct V_3 * V_4 ;
T_11 V_311 ;
T_11 V_312 ;
int V_5 ;
struct V_6 * V_7 ;
int V_66 ;
int error ;
V_5 = V_2 -> V_67 - 1 ;
V_2 -> V_23 -> V_188 ( V_2 , & V_52 ) ;
error = F_112 ( V_2 , V_5 , & V_52 , & V_4 ) ;
if ( error )
return error ;
F_52 ( V_2 , V_5 , & V_7 ) ;
F_171 ( V_2 , V_5 , V_7 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_306;
#endif
V_2 -> V_79 [ V_5 ] = 1 ;
while ( V_5 < V_2 -> V_67 ) {
V_4 = F_52 ( V_2 , V_5 , & V_7 ) ;
if ( V_2 -> V_79 [ V_5 ] > F_7 ( V_4 -> V_22 ) ) {
V_313:
if ( V_5 < V_2 -> V_67 - 1 )
V_2 -> V_79 [ V_5 + 1 ] ++ ;
V_5 ++ ;
continue;
}
if ( V_5 == 0 ) {
V_283 = F_45 ( V_2 , V_2 -> V_79 [ 0 ] , V_4 ) ;
V_2 -> V_23 -> V_199 ( & V_309 , V_283 ) ;
V_311 = V_2 -> V_23 -> V_200 ( V_2 , & V_309 ,
V_301 ) ;
V_2 -> V_23 -> V_185 ( & V_304 , V_283 ) ;
V_312 = V_2 -> V_23 -> V_200 ( V_2 , V_302 ,
& V_304 ) ;
if ( V_311 >= 0 && V_312 >= 0 ) {
error = V_284 ( V_2 , V_283 , V_303 ) ;
if ( error < 0 ||
error == V_308 )
break;
} else if ( V_312 < 0 ) {
goto V_313;
}
V_2 -> V_79 [ V_5 ] ++ ;
continue;
}
V_222 = F_46 ( V_2 , V_2 -> V_79 [ V_5 ] , V_4 ) ;
V_310 = F_47 ( V_2 , V_2 -> V_79 [ V_5 ] , V_4 ) ;
V_181 = F_48 ( V_2 , V_2 -> V_79 [ V_5 ] , V_4 ) ;
V_311 = V_2 -> V_23 -> V_200 ( V_2 , V_310 , V_301 ) ;
V_312 = V_2 -> V_23 -> V_200 ( V_2 , V_302 , V_222 ) ;
if ( V_311 >= 0 && V_312 >= 0 ) {
V_5 -- ;
error = F_112 ( V_2 , V_5 , V_181 ,
& V_4 ) ;
if ( error )
goto V_306;
F_52 ( V_2 , V_5 , & V_7 ) ;
F_171 ( V_2 , V_5 , V_7 ) ;
#ifdef F_109
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_306;
#endif
V_2 -> V_79 [ V_5 ] = 1 ;
continue;
} else if ( V_312 < 0 ) {
goto V_313;
}
V_2 -> V_79 [ V_5 ] ++ ;
}
V_306:
if ( V_2 -> V_68 [ 0 ] == NULL ) {
for ( V_66 = 0 ; V_66 < V_2 -> V_67 ; V_66 ++ ) {
if ( V_2 -> V_68 [ V_66 ] ) {
F_34 ( V_2 -> V_65 , V_2 -> V_68 [ V_66 ] ) ;
V_2 -> V_68 [ V_66 ] = NULL ;
V_2 -> V_79 [ V_66 ] = 0 ;
V_2 -> V_80 [ V_66 ] = 0 ;
}
}
}
return error ;
}
int
F_172 (
struct V_1 * V_2 ,
union V_314 * V_315 ,
union V_314 * V_316 ,
T_19 V_284 ,
void * V_303 )
{
union V_94 V_162 ;
union V_95 V_301 ;
union V_95 V_302 ;
V_2 -> V_78 = * V_316 ;
V_2 -> V_23 -> V_274 ( V_2 , & V_162 ) ;
V_2 -> V_23 -> V_185 ( & V_302 , & V_162 ) ;
V_2 -> V_78 = * V_315 ;
V_2 -> V_23 -> V_274 ( V_2 , & V_162 ) ;
V_2 -> V_23 -> V_185 ( & V_301 , & V_162 ) ;
if ( V_2 -> V_23 -> V_200 ( V_2 , & V_301 , & V_302 ) > 0 )
return - V_317 ;
if ( ! ( V_2 -> V_46 & V_196 ) )
return F_169 ( V_2 , & V_301 ,
& V_302 , V_284 , V_303 ) ;
return F_170 ( V_2 , & V_301 , & V_302 ,
V_284 , V_303 ) ;
}
