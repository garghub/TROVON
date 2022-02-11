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
F_3 ( & V_4 -> V_13 . V_14 . V_15 , & V_10 -> V_12 . V_16 ) &&
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
return F_14 ( V_33 ) ;
}
return 0 ;
}
STATIC int
F_15 (
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
V_36 = F_16 ( V_34 ) ;
V_37 = F_5 ( V_36 -> V_41 ) ;
if ( F_2 ( & V_10 -> V_12 ) ) {
V_38 = V_38 &&
F_3 ( & V_4 -> V_13 . V_42 . V_15 , & V_10 -> V_12 . V_16 ) &&
V_4 -> V_13 . V_42 . V_17 == F_4 (
V_7 ? V_7 -> V_18 : V_19 ) ;
}
V_38 = V_38 &&
F_5 ( V_4 -> V_20 ) == F_6 ( V_2 ) &&
F_7 ( V_4 -> V_21 ) == V_5 &&
F_7 ( V_4 -> V_22 ) <=
V_2 -> V_23 -> V_24 ( V_2 , V_5 ) &&
( V_4 -> V_13 . V_42 . V_25 == F_17 ( V_43 ) ||
F_5 ( V_4 -> V_13 . V_42 . V_25 ) < V_37 ) &&
V_4 -> V_13 . V_42 . V_25 &&
( V_4 -> V_13 . V_42 . V_27 == F_17 ( V_43 ) ||
F_5 ( V_4 -> V_13 . V_42 . V_27 ) < V_37 ) &&
V_4 -> V_13 . V_42 . V_27 ;
if ( F_10 ( F_11 ( ! V_38 , V_10 ,
V_44 ,
V_45 ) ) ) {
if ( V_7 )
F_12 ( V_7 , V_30 ) ;
F_13 ( V_31 , V_32 , V_10 ) ;
return F_14 ( V_33 ) ;
}
return 0 ;
}
int
F_18 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
struct V_6 * V_7 )
{
if ( V_2 -> V_46 & V_47 )
return F_1 ( V_2 , V_4 , V_5 , V_7 ) ;
else
return F_15 ( V_2 , V_4 , V_5 , V_7 ) ;
}
int
F_19 (
struct V_1 * V_2 ,
T_2 V_48 ,
int V_5 )
{
F_20 (
V_5 > 0 &&
V_48 != V_26 &&
F_8 ( V_2 -> V_11 , V_48 ) ) ;
return 0 ;
}
STATIC int
F_21 (
struct V_1 * V_2 ,
T_1 V_48 ,
int V_5 )
{
T_1 V_49 = V_2 -> V_11 -> V_12 . V_50 ;
F_20 (
V_5 > 0 &&
V_48 != V_43 &&
V_48 != 0 &&
V_48 < V_49 ) ;
return 0 ;
}
STATIC int
F_22 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
int V_53 ,
int V_5 )
{
if ( V_2 -> V_46 & V_47 ) {
return F_19 ( V_2 ,
F_9 ( ( & V_52 -> V_14 ) [ V_53 ] ) , V_5 ) ;
} else {
return F_21 ( V_2 ,
F_5 ( ( & V_52 -> V_42 ) [ V_53 ] ) , V_5 ) ;
}
}
void
F_23 (
struct V_6 * V_7 )
{
struct V_3 * V_4 = F_24 ( V_7 ) ;
struct V_54 * V_55 = V_7 -> V_56 ;
if ( ! F_2 ( & V_7 -> V_57 -> V_58 -> V_12 ) )
return;
if ( V_55 )
V_4 -> V_13 . V_14 . V_59 = F_4 ( V_55 -> V_60 . V_61 ) ;
F_25 ( V_7 -> V_62 , F_26 ( V_7 -> V_63 ) ,
V_64 ) ;
}
bool
F_27 (
struct V_6 * V_7 )
{
if ( F_2 ( & V_7 -> V_57 -> V_58 -> V_12 ) )
return F_28 ( V_7 -> V_62 , F_26 ( V_7 -> V_63 ) ,
V_64 ) ;
return true ;
}
void
F_29 (
struct V_6 * V_7 )
{
struct V_3 * V_4 = F_24 ( V_7 ) ;
struct V_54 * V_55 = V_7 -> V_56 ;
if ( ! F_2 ( & V_7 -> V_57 -> V_58 -> V_12 ) )
return;
if ( V_55 )
V_4 -> V_13 . V_42 . V_59 = F_4 ( V_55 -> V_60 . V_61 ) ;
F_25 ( V_7 -> V_62 , F_26 ( V_7 -> V_63 ) ,
V_65 ) ;
}
bool
F_30 (
struct V_6 * V_7 )
{
if ( F_2 ( & V_7 -> V_57 -> V_58 -> V_12 ) )
return F_28 ( V_7 -> V_62 , F_26 ( V_7 -> V_63 ) ,
V_65 ) ;
return true ;
}
void
F_31 (
T_3 * V_2 ,
int error )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_2 -> V_67 ; V_66 ++ ) {
if ( V_2 -> V_68 [ V_66 ] )
F_32 ( V_2 -> V_69 , V_2 -> V_68 [ V_66 ] ) ;
else if ( ! error )
break;
}
ASSERT ( V_2 -> V_70 != V_71 ||
V_2 -> V_39 . V_72 . V_73 == 0 ) ;
F_33 ( V_74 , V_2 ) ;
}
int
F_34 (
T_3 * V_2 ,
T_3 * * V_75 )
{
T_4 * V_7 ;
int error ;
int V_66 ;
T_5 * V_10 ;
T_3 * V_76 ;
T_6 * V_77 ;
V_77 = V_2 -> V_69 ;
V_10 = V_2 -> V_11 ;
V_76 = V_2 -> V_23 -> V_78 ( V_2 ) ;
V_76 -> V_79 = V_2 -> V_79 ;
for ( V_66 = 0 ; V_66 < V_76 -> V_67 ; V_66 ++ ) {
V_76 -> V_80 [ V_66 ] = V_2 -> V_80 [ V_66 ] ;
V_76 -> V_81 [ V_66 ] = V_2 -> V_81 [ V_66 ] ;
V_7 = V_2 -> V_68 [ V_66 ] ;
if ( V_7 ) {
error = F_35 ( V_10 , V_77 , V_10 -> V_82 ,
F_36 ( V_7 ) , V_10 -> V_83 ,
0 , & V_7 ,
V_2 -> V_23 -> V_84 ) ;
if ( error ) {
F_31 ( V_76 , error ) ;
* V_75 = NULL ;
return error ;
}
}
V_76 -> V_68 [ V_66 ] = V_7 ;
}
* V_75 = V_76 ;
return 0 ;
}
static inline T_7 F_37 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 & V_47 ) {
if ( V_2 -> V_46 & V_85 )
return V_86 ;
return V_87 ;
}
if ( V_2 -> V_46 & V_85 )
return V_88 ;
return V_89 ;
}
static inline T_7 F_38 ( struct V_1 * V_2 )
{
return ( V_2 -> V_46 & V_47 ) ?
sizeof( V_90 ) : sizeof( V_91 ) ;
}
STATIC T_7
F_39 (
struct V_1 * V_2 ,
int V_92 )
{
return F_37 ( V_2 ) +
( V_92 - 1 ) * V_2 -> V_23 -> V_93 ;
}
STATIC T_7
F_40 (
struct V_1 * V_2 ,
int V_92 )
{
return F_37 ( V_2 ) +
( V_92 - 1 ) * V_2 -> V_23 -> V_94 ;
}
STATIC T_7
F_41 (
struct V_1 * V_2 ,
int V_92 ,
int V_5 )
{
return F_37 ( V_2 ) +
V_2 -> V_23 -> V_24 ( V_2 , V_5 ) * V_2 -> V_23 -> V_94 +
( V_92 - 1 ) * F_38 ( V_2 ) ;
}
STATIC union V_95 *
F_42 (
struct V_1 * V_2 ,
int V_92 ,
struct V_3 * V_4 )
{
return (union V_95 * )
( ( char * ) V_4 + F_39 ( V_2 , V_92 ) ) ;
}
STATIC union V_96 *
F_43 (
struct V_1 * V_2 ,
int V_92 ,
struct V_3 * V_4 )
{
return (union V_96 * )
( ( char * ) V_4 + F_40 ( V_2 , V_92 ) ) ;
}
STATIC union V_51 *
F_44 (
struct V_1 * V_2 ,
int V_92 ,
struct V_3 * V_4 )
{
int V_5 = F_45 ( V_4 ) ;
ASSERT ( V_4 -> V_21 != 0 ) ;
return (union V_51 * )
( ( char * ) V_4 + F_41 ( V_2 , V_92 , V_5 ) ) ;
}
STATIC struct V_3 *
F_46 (
struct V_1 * V_2 )
{
struct V_97 * V_98 ;
V_98 = F_47 ( V_2 -> V_39 . V_72 . V_99 , V_2 -> V_39 . V_72 . V_100 ) ;
return (struct V_3 * ) V_98 -> V_101 ;
}
STATIC struct V_3 *
F_48 (
struct V_1 * V_2 ,
int V_5 ,
struct V_6 * * V_102 )
{
if ( ( V_2 -> V_46 & V_103 ) &&
( V_5 == V_2 -> V_67 - 1 ) ) {
* V_102 = NULL ;
return F_46 ( V_2 ) ;
}
* V_102 = V_2 -> V_68 [ V_5 ] ;
return F_24 ( * V_102 ) ;
}
T_4 *
F_49 (
T_5 * V_10 ,
T_6 * V_77 ,
T_8 V_104 ,
T_9 V_105 )
{
T_4 * V_7 ;
T_10 V_106 ;
ASSERT ( V_104 != V_107 ) ;
V_106 = F_50 ( V_10 , V_104 ) ;
V_7 = F_51 ( V_77 , V_10 -> V_82 , V_106 , V_10 -> V_83 , V_105 ) ;
ASSERT ( ! F_52 ( V_7 ) ) ;
return V_7 ;
}
T_4 *
F_53 (
T_5 * V_10 ,
T_6 * V_77 ,
T_11 V_108 ,
T_1 V_109 ,
T_9 V_105 )
{
T_4 * V_7 ;
T_10 V_106 ;
ASSERT ( V_108 != V_110 ) ;
ASSERT ( V_109 != V_43 ) ;
V_106 = F_54 ( V_10 , V_108 , V_109 ) ;
V_7 = F_51 ( V_77 , V_10 -> V_82 , V_106 , V_10 -> V_83 , V_105 ) ;
ASSERT ( ! F_52 ( V_7 ) ) ;
return V_7 ;
}
int
F_55 (
T_3 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
V_4 = F_48 ( V_2 , V_5 , & V_7 ) ;
F_18 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( V_2 -> V_46 & V_47 )
return V_4 -> V_13 . V_14 . V_27 == F_4 ( V_26 ) ;
else
return V_4 -> V_13 . V_42 . V_27 == F_17 ( V_43 ) ;
}
STATIC int
F_56 (
T_3 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
V_4 = F_48 ( V_2 , V_5 , & V_7 ) ;
F_18 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( ! V_4 -> V_22 )
return 0 ;
V_2 -> V_80 [ V_5 ] = 1 ;
return 1 ;
}
STATIC int
F_57 (
T_3 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
V_4 = F_48 ( V_2 , V_5 , & V_7 ) ;
F_18 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( ! V_4 -> V_22 )
return 0 ;
V_2 -> V_80 [ V_5 ] = F_7 ( V_4 -> V_22 ) ;
return 1 ;
}
void
F_58 (
T_12 V_111 ,
const short * V_112 ,
int V_113 ,
int * V_114 ,
int * V_115 )
{
int V_66 ;
T_12 V_116 ;
ASSERT ( V_111 != 0 ) ;
for ( V_66 = 0 , V_116 = 1LL ; ; V_66 ++ , V_116 <<= 1 ) {
if ( V_116 & V_111 ) {
* V_114 = V_112 [ V_66 ] ;
break;
}
}
for ( V_66 = V_113 - 1 , V_116 = 1LL << V_66 ; ; V_66 -- , V_116 >>= 1 ) {
if ( V_116 & V_111 ) {
* V_115 = V_112 [ V_66 + 1 ] - 1 ;
break;
}
}
}
int
F_59 (
struct V_9 * V_10 ,
struct V_117 * V_77 ,
T_8 V_104 ,
T_9 V_105 ,
struct V_6 * * V_102 ,
int V_118 ,
const struct V_119 * V_120 )
{
struct V_6 * V_7 ;
T_10 V_106 ;
int error ;
ASSERT ( V_104 != V_107 ) ;
V_106 = F_50 ( V_10 , V_104 ) ;
error = F_35 ( V_10 , V_77 , V_10 -> V_82 , V_106 ,
V_10 -> V_83 , V_105 , & V_7 , V_120 ) ;
if ( error )
return error ;
ASSERT ( ! F_52 ( V_7 ) ) ;
if ( V_7 )
F_60 ( V_7 , V_118 ) ;
* V_102 = V_7 ;
return 0 ;
}
void
F_61 (
struct V_9 * V_10 ,
T_8 V_104 ,
T_13 V_121 ,
const struct V_119 * V_120 )
{
T_10 V_106 ;
ASSERT ( V_104 != V_107 ) ;
V_106 = F_50 ( V_10 , V_104 ) ;
F_62 ( V_10 -> V_82 , V_106 , V_10 -> V_83 * V_121 , V_120 ) ;
}
void
F_63 (
struct V_9 * V_10 ,
T_11 V_108 ,
T_1 V_109 ,
T_13 V_121 ,
const struct V_119 * V_120 )
{
T_10 V_106 ;
ASSERT ( V_108 != V_110 ) ;
ASSERT ( V_109 != V_43 ) ;
V_106 = F_54 ( V_10 , V_108 , V_109 ) ;
F_62 ( V_10 -> V_82 , V_106 , V_10 -> V_83 * V_121 , V_120 ) ;
}
STATIC int
F_64 (
struct V_1 * V_2 ,
int V_122 ,
struct V_3 * V_4 )
{
int V_123 = 0 ;
T_2 V_124 = F_9 ( V_4 -> V_13 . V_14 . V_25 ) ;
T_2 V_125 = F_9 ( V_4 -> V_13 . V_14 . V_27 ) ;
if ( ( V_122 & V_126 ) && V_124 != V_26 ) {
F_61 ( V_2 -> V_11 , V_124 , 1 ,
V_2 -> V_23 -> V_84 ) ;
V_123 ++ ;
}
if ( ( V_122 & V_127 ) && V_125 != V_26 ) {
F_61 ( V_2 -> V_11 , V_125 , 1 ,
V_2 -> V_23 -> V_84 ) ;
V_123 ++ ;
}
return V_123 ;
}
STATIC int
F_65 (
struct V_1 * V_2 ,
int V_122 ,
struct V_3 * V_4 )
{
int V_123 = 0 ;
T_1 V_124 = F_5 ( V_4 -> V_13 . V_42 . V_25 ) ;
T_1 V_125 = F_5 ( V_4 -> V_13 . V_42 . V_27 ) ;
if ( ( V_122 & V_126 ) && V_124 != V_43 ) {
F_63 ( V_2 -> V_11 , V_2 -> V_39 . V_40 . V_108 ,
V_124 , 1 , V_2 -> V_23 -> V_84 ) ;
V_123 ++ ;
}
if ( ( V_122 & V_127 ) && V_125 != V_43 ) {
F_63 ( V_2 -> V_11 , V_2 -> V_39 . V_40 . V_108 ,
V_125 , 1 , V_2 -> V_23 -> V_84 ) ;
V_123 ++ ;
}
return V_123 ;
}
STATIC int
F_66 (
struct V_1 * V_2 ,
int V_128 ,
int V_122 )
{
struct V_3 * V_4 ;
if ( ( V_2 -> V_46 & V_103 ) &&
( V_128 == V_2 -> V_67 - 1 ) )
return 0 ;
if ( ( V_2 -> V_81 [ V_128 ] | V_122 ) == V_2 -> V_81 [ V_128 ] )
return 0 ;
V_2 -> V_81 [ V_128 ] |= V_122 ;
V_4 = F_24 ( V_2 -> V_68 [ V_128 ] ) ;
if ( V_2 -> V_46 & V_47 )
return F_64 ( V_2 , V_122 , V_4 ) ;
return F_65 ( V_2 , V_122 , V_4 ) ;
}
STATIC void
F_67 (
T_3 * V_2 ,
int V_128 ,
T_4 * V_7 )
{
struct V_3 * V_72 ;
if ( V_2 -> V_68 [ V_128 ] )
F_32 ( V_2 -> V_69 , V_2 -> V_68 [ V_128 ] ) ;
V_2 -> V_68 [ V_128 ] = V_7 ;
V_2 -> V_81 [ V_128 ] = 0 ;
V_72 = F_24 ( V_7 ) ;
if ( V_2 -> V_46 & V_47 ) {
if ( V_72 -> V_13 . V_14 . V_25 == F_4 ( V_26 ) )
V_2 -> V_81 [ V_128 ] |= V_126 ;
if ( V_72 -> V_13 . V_14 . V_27 == F_4 ( V_26 ) )
V_2 -> V_81 [ V_128 ] |= V_127 ;
} else {
if ( V_72 -> V_13 . V_42 . V_25 == F_17 ( V_43 ) )
V_2 -> V_81 [ V_128 ] |= V_126 ;
if ( V_72 -> V_13 . V_42 . V_27 == F_17 ( V_43 ) )
V_2 -> V_81 [ V_128 ] |= V_127 ;
}
}
STATIC int
F_68 (
struct V_1 * V_2 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 )
return V_52 -> V_14 == F_4 ( V_26 ) ;
else
return V_52 -> V_42 == F_17 ( V_43 ) ;
}
STATIC void
F_69 (
struct V_1 * V_2 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 )
V_52 -> V_14 = F_4 ( V_26 ) ;
else
V_52 -> V_42 = F_17 ( V_43 ) ;
}
STATIC void
F_70 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_51 * V_52 ,
int V_122 )
{
ASSERT ( V_122 == V_129 || V_122 == V_130 ) ;
if ( V_2 -> V_46 & V_47 ) {
if ( V_122 == V_130 )
V_52 -> V_14 = V_4 -> V_13 . V_14 . V_27 ;
else
V_52 -> V_14 = V_4 -> V_13 . V_14 . V_25 ;
} else {
if ( V_122 == V_130 )
V_52 -> V_42 = V_4 -> V_13 . V_42 . V_27 ;
else
V_52 -> V_42 = V_4 -> V_13 . V_42 . V_25 ;
}
}
STATIC void
F_71 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_51 * V_52 ,
int V_122 )
{
ASSERT ( V_122 == V_129 || V_122 == V_130 ) ;
if ( V_2 -> V_46 & V_47 ) {
if ( V_122 == V_130 )
V_4 -> V_13 . V_14 . V_27 = V_52 -> V_14 ;
else
V_4 -> V_13 . V_14 . V_25 = V_52 -> V_14 ;
} else {
if ( V_122 == V_130 )
V_4 -> V_13 . V_42 . V_27 = V_52 -> V_42 ;
else
V_4 -> V_13 . V_42 . V_25 = V_52 -> V_42 ;
}
}
void
F_72 (
struct V_9 * V_10 ,
struct V_3 * V_131 ,
T_10 V_132 ,
T_14 V_133 ,
T_15 V_5 ,
T_15 V_134 ,
T_16 V_135 ,
unsigned int V_136 )
{
V_131 -> V_20 = F_17 ( V_133 ) ;
V_131 -> V_21 = F_73 ( V_5 ) ;
V_131 -> V_22 = F_73 ( V_134 ) ;
if ( V_136 & V_47 ) {
V_131 -> V_13 . V_14 . V_25 = F_4 ( V_26 ) ;
V_131 -> V_13 . V_14 . V_27 = F_4 ( V_26 ) ;
if ( V_136 & V_85 ) {
V_131 -> V_13 . V_14 . V_17 = F_4 ( V_132 ) ;
V_131 -> V_13 . V_14 . V_137 = F_4 ( V_135 ) ;
F_74 ( & V_131 -> V_13 . V_14 . V_15 , & V_10 -> V_12 . V_16 ) ;
V_131 -> V_13 . V_14 . V_138 = 0 ;
}
} else {
T_14 V_139 = ( T_14 ) V_135 ;
V_131 -> V_13 . V_42 . V_25 = F_17 ( V_43 ) ;
V_131 -> V_13 . V_42 . V_27 = F_17 ( V_43 ) ;
if ( V_136 & V_85 ) {
V_131 -> V_13 . V_42 . V_17 = F_4 ( V_132 ) ;
V_131 -> V_13 . V_42 . V_137 = F_17 ( V_139 ) ;
F_74 ( & V_131 -> V_13 . V_42 . V_15 , & V_10 -> V_12 . V_16 ) ;
}
}
}
void
F_75 (
struct V_9 * V_10 ,
struct V_6 * V_7 ,
T_14 V_133 ,
T_15 V_5 ,
T_15 V_134 ,
T_16 V_135 ,
unsigned int V_136 )
{
F_72 ( V_10 , F_24 ( V_7 ) , V_7 -> V_18 ,
V_133 , V_5 , V_134 , V_135 , V_136 ) ;
}
STATIC void
F_76 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_5 ,
int V_134 )
{
T_16 V_135 ;
if ( V_2 -> V_46 & V_47 )
V_135 = V_2 -> V_39 . V_72 . V_99 -> V_140 ;
else
V_135 = V_2 -> V_39 . V_40 . V_108 ;
F_72 ( V_2 -> V_11 , F_24 ( V_7 ) , V_7 -> V_18 ,
F_6 ( V_2 ) , V_5 , V_134 ,
V_135 , V_2 -> V_46 ) ;
}
STATIC int
F_77 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
union V_51 V_52 ;
if ( V_5 > 0 )
return 0 ;
if ( ! ( V_2 -> V_46 & V_141 ) )
return 0 ;
F_70 ( V_2 , V_4 , & V_52 , V_130 ) ;
if ( ! F_68 ( V_2 , & V_52 ) )
return 0 ;
return 1 ;
}
STATIC void
F_78 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 )
V_52 -> V_14 = F_4 ( F_79 ( V_2 -> V_11 ,
F_36 ( V_7 ) ) ) ;
else {
V_52 -> V_42 = F_17 ( F_80 ( V_2 -> V_11 ,
F_36 ( V_7 ) ) ) ;
}
}
STATIC T_10
F_81 (
struct V_1 * V_2 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 ) {
ASSERT ( V_52 -> V_14 != F_4 ( V_26 ) ) ;
return F_50 ( V_2 -> V_11 , F_9 ( V_52 -> V_14 ) ) ;
} else {
ASSERT ( V_2 -> V_39 . V_40 . V_108 != V_110 ) ;
ASSERT ( V_52 -> V_42 != F_17 ( V_43 ) ) ;
return F_54 ( V_2 -> V_11 , V_2 -> V_39 . V_40 . V_108 ,
F_5 ( V_52 -> V_42 ) ) ;
}
}
STATIC void
F_82 (
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
switch ( V_2 -> V_70 ) {
case V_142 :
case V_143 :
F_60 ( V_7 , V_144 ) ;
break;
case V_145 :
F_60 ( V_7 , V_146 ) ;
break;
case V_71 :
F_60 ( V_7 , V_147 ) ;
break;
default:
ASSERT ( 0 ) ;
}
}
STATIC int
F_83 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
int V_136 ,
struct V_3 * * V_4 ,
struct V_6 * * V_102 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_10 V_106 ;
ASSERT ( ! ( V_136 & V_148 ) ) ;
V_106 = F_81 ( V_2 , V_52 ) ;
* V_102 = F_51 ( V_2 -> V_69 , V_10 -> V_82 , V_106 ,
V_10 -> V_83 , V_136 ) ;
if ( ! * V_102 )
return V_149 ;
( * V_102 ) -> V_150 = V_2 -> V_23 -> V_84 ;
* V_4 = F_24 ( * V_102 ) ;
return 0 ;
}
STATIC int
F_84 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
int V_5 ,
int V_136 ,
struct V_3 * * V_4 ,
struct V_6 * * V_102 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_10 V_106 ;
int error ;
ASSERT ( ! ( V_136 & V_148 ) ) ;
V_106 = F_81 ( V_2 , V_52 ) ;
error = F_35 ( V_10 , V_2 -> V_69 , V_10 -> V_82 , V_106 ,
V_10 -> V_83 , V_136 , V_102 ,
V_2 -> V_23 -> V_84 ) ;
if ( error )
return error ;
ASSERT ( ! F_52 ( * V_102 ) ) ;
F_82 ( V_2 , * V_102 ) ;
* V_4 = F_24 ( * V_102 ) ;
return 0 ;
}
STATIC void
F_85 (
struct V_1 * V_2 ,
union V_96 * V_151 ,
union V_96 * V_152 ,
int V_153 )
{
ASSERT ( V_153 >= 0 ) ;
memcpy ( V_151 , V_152 , V_153 * V_2 -> V_23 -> V_94 ) ;
}
STATIC void
F_86 (
struct V_1 * V_2 ,
union V_95 * V_154 ,
union V_95 * V_155 ,
int V_134 )
{
ASSERT ( V_134 >= 0 ) ;
memcpy ( V_154 , V_155 , V_134 * V_2 -> V_23 -> V_93 ) ;
}
STATIC void
F_87 (
struct V_1 * V_2 ,
union V_51 * V_156 ,
union V_51 * V_157 ,
int V_158 )
{
ASSERT ( V_158 >= 0 ) ;
memcpy ( V_156 , V_157 , V_158 * F_38 ( V_2 ) ) ;
}
STATIC void
F_88 (
struct V_1 * V_2 ,
union V_96 * V_159 ,
int V_160 ,
int V_153 )
{
char * V_151 ;
ASSERT ( V_153 >= 0 ) ;
ASSERT ( V_160 == 1 || V_160 == - 1 ) ;
V_151 = ( char * ) V_159 + ( V_160 * V_2 -> V_23 -> V_94 ) ;
memmove ( V_151 , V_159 , V_153 * V_2 -> V_23 -> V_94 ) ;
}
STATIC void
F_89 (
struct V_1 * V_2 ,
union V_95 * V_161 ,
int V_160 ,
int V_134 )
{
char * V_154 ;
ASSERT ( V_134 >= 0 ) ;
ASSERT ( V_160 == 1 || V_160 == - 1 ) ;
V_154 = ( char * ) V_161 + ( V_160 * V_2 -> V_23 -> V_93 ) ;
memmove ( V_154 , V_161 , V_134 * V_2 -> V_23 -> V_93 ) ;
}
STATIC void
F_90 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
int V_160 ,
int V_158 )
{
char * V_156 ;
ASSERT ( V_158 >= 0 ) ;
ASSERT ( V_160 == 1 || V_160 == - 1 ) ;
V_156 = ( char * ) V_52 + ( V_160 * F_38 ( V_2 ) ) ;
memmove ( V_156 , V_52 , V_158 * F_38 ( V_2 ) ) ;
}
STATIC void
F_91 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_114 ,
int V_115 )
{
F_92 ( V_2 , V_162 ) ;
F_93 ( V_2 , V_7 , V_114 , V_115 ) ;
if ( V_7 ) {
F_94 ( V_2 -> V_69 , V_7 , V_163 ) ;
F_95 ( V_2 -> V_69 , V_7 ,
F_40 ( V_2 , V_114 ) ,
F_40 ( V_2 , V_115 + 1 ) - 1 ) ;
} else {
F_96 ( V_2 -> V_69 , V_2 -> V_39 . V_72 . V_99 ,
F_97 ( V_2 -> V_39 . V_72 . V_100 ) ) ;
}
F_92 ( V_2 , V_164 ) ;
}
void
F_98 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_114 ,
int V_115 )
{
F_92 ( V_2 , V_162 ) ;
F_93 ( V_2 , V_7 , V_114 , V_115 ) ;
F_94 ( V_2 -> V_69 , V_7 , V_163 ) ;
F_95 ( V_2 -> V_69 , V_7 ,
F_39 ( V_2 , V_114 ) ,
F_39 ( V_2 , V_115 + 1 ) - 1 ) ;
F_92 ( V_2 , V_164 ) ;
}
STATIC void
F_99 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_114 ,
int V_115 )
{
F_92 ( V_2 , V_162 ) ;
F_93 ( V_2 , V_7 , V_114 , V_115 ) ;
if ( V_7 ) {
struct V_3 * V_4 = F_24 ( V_7 ) ;
int V_5 = F_45 ( V_4 ) ;
F_94 ( V_2 -> V_69 , V_7 , V_163 ) ;
F_95 ( V_2 -> V_69 , V_7 ,
F_41 ( V_2 , V_114 , V_5 ) ,
F_41 ( V_2 , V_115 + 1 , V_5 ) - 1 ) ;
} else {
F_96 ( V_2 -> V_69 , V_2 -> V_39 . V_72 . V_99 ,
F_97 ( V_2 -> V_39 . V_72 . V_100 ) ) ;
}
F_92 ( V_2 , V_164 ) ;
}
void
F_100 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_111 )
{
int V_114 ;
int V_115 ;
static const short V_165 [] = {
F_101 ( struct V_3 , V_20 ) ,
F_101 ( struct V_3 , V_21 ) ,
F_101 ( struct V_3 , V_22 ) ,
F_101 ( struct V_3 , V_13 . V_42 . V_25 ) ,
F_101 ( struct V_3 , V_13 . V_42 . V_27 ) ,
F_101 ( struct V_3 , V_13 . V_42 . V_17 ) ,
F_101 ( struct V_3 , V_13 . V_42 . V_59 ) ,
F_101 ( struct V_3 , V_13 . V_42 . V_15 ) ,
F_101 ( struct V_3 , V_13 . V_42 . V_137 ) ,
F_101 ( struct V_3 , V_13 . V_42 . V_166 ) ,
V_88
} ;
static const short V_167 [] = {
F_101 ( struct V_3 , V_20 ) ,
F_101 ( struct V_3 , V_21 ) ,
F_101 ( struct V_3 , V_22 ) ,
F_101 ( struct V_3 , V_13 . V_14 . V_25 ) ,
F_101 ( struct V_3 , V_13 . V_14 . V_27 ) ,
F_101 ( struct V_3 , V_13 . V_14 . V_17 ) ,
F_101 ( struct V_3 , V_13 . V_14 . V_59 ) ,
F_101 ( struct V_3 , V_13 . V_14 . V_15 ) ,
F_101 ( struct V_3 , V_13 . V_14 . V_137 ) ,
F_101 ( struct V_3 , V_13 . V_14 . V_166 ) ,
F_101 ( struct V_3 , V_13 . V_14 . V_138 ) ,
V_86
} ;
F_92 ( V_2 , V_162 ) ;
F_102 ( V_2 , V_7 , V_111 ) ;
if ( V_7 ) {
int V_113 ;
if ( V_2 -> V_46 & V_85 ) {
if ( V_111 == V_168 )
V_111 = V_169 ;
V_113 = V_170 ;
} else {
V_113 = V_171 ;
}
F_58 ( V_111 ,
( V_2 -> V_46 & V_47 ) ?
V_167 : V_165 ,
V_113 , & V_114 , & V_115 ) ;
F_94 ( V_2 -> V_69 , V_7 , V_163 ) ;
F_95 ( V_2 -> V_69 , V_7 , V_114 , V_115 ) ;
} else {
F_96 ( V_2 -> V_69 , V_2 -> V_39 . V_72 . V_99 ,
F_97 ( V_2 -> V_39 . V_72 . V_100 ) ) ;
}
F_92 ( V_2 , V_164 ) ;
}
int
F_103 (
struct V_1 * V_2 ,
int V_5 ,
int * V_172 )
{
struct V_3 * V_4 ;
union V_51 V_52 ;
struct V_6 * V_7 ;
int error ;
int V_128 ;
F_92 ( V_2 , V_162 ) ;
F_104 ( V_2 , V_5 ) ;
ASSERT ( V_5 < V_2 -> V_67 ) ;
F_66 ( V_2 , V_5 , V_127 ) ;
V_4 = F_48 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_105
error = F_18 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_173;
#endif
if ( ++ V_2 -> V_80 [ V_5 ] <= F_106 ( V_4 ) )
goto V_174;
F_70 ( V_2 , V_4 , & V_52 , V_130 ) ;
if ( F_68 ( V_2 , & V_52 ) )
goto V_175;
F_107 ( V_2 , V_176 ) ;
for ( V_128 = V_5 + 1 ; V_128 < V_2 -> V_67 ; V_128 ++ ) {
V_4 = F_48 ( V_2 , V_128 , & V_7 ) ;
#ifdef F_105
error = F_18 ( V_2 , V_4 , V_128 , V_7 ) ;
if ( error )
goto V_173;
#endif
if ( ++ V_2 -> V_80 [ V_128 ] <= F_106 ( V_4 ) )
break;
F_66 ( V_2 , V_128 , V_127 ) ;
}
if ( V_128 == V_2 -> V_67 ) {
if ( V_2 -> V_46 & V_103 )
goto V_175;
ASSERT ( 0 ) ;
error = V_33 ;
goto V_173;
}
ASSERT ( V_128 < V_2 -> V_67 ) ;
for ( V_4 = F_48 ( V_2 , V_128 , & V_7 ) ; V_128 > V_5 ; ) {
union V_51 * V_177 ;
V_177 = F_44 ( V_2 , V_2 -> V_80 [ V_128 ] , V_4 ) ;
error = F_84 ( V_2 , V_177 , -- V_128 ,
0 , & V_4 , & V_7 ) ;
if ( error )
goto V_173;
F_67 ( V_2 , V_128 , V_7 ) ;
V_2 -> V_80 [ V_128 ] = 1 ;
}
V_174:
F_92 ( V_2 , V_164 ) ;
* V_172 = 1 ;
return 0 ;
V_175:
F_92 ( V_2 , V_164 ) ;
* V_172 = 0 ;
return 0 ;
V_173:
F_92 ( V_2 , V_178 ) ;
return error ;
}
int
F_108 (
struct V_1 * V_2 ,
int V_5 ,
int * V_172 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
int error ;
int V_128 ;
union V_51 V_52 ;
F_92 ( V_2 , V_162 ) ;
F_104 ( V_2 , V_5 ) ;
ASSERT ( V_5 < V_2 -> V_67 ) ;
F_66 ( V_2 , V_5 , V_126 ) ;
if ( -- V_2 -> V_80 [ V_5 ] > 0 )
goto V_174;
V_4 = F_48 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_105
error = F_18 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_173;
#endif
F_70 ( V_2 , V_4 , & V_52 , V_129 ) ;
if ( F_68 ( V_2 , & V_52 ) )
goto V_175;
F_107 ( V_2 , V_179 ) ;
for ( V_128 = V_5 + 1 ; V_128 < V_2 -> V_67 ; V_128 ++ ) {
if ( -- V_2 -> V_80 [ V_128 ] > 0 )
break;
F_66 ( V_2 , V_128 , V_126 ) ;
}
if ( V_128 == V_2 -> V_67 ) {
if ( V_2 -> V_46 & V_103 )
goto V_175;
ASSERT ( 0 ) ;
error = V_33 ;
goto V_173;
}
ASSERT ( V_128 < V_2 -> V_67 ) ;
for ( V_4 = F_48 ( V_2 , V_128 , & V_7 ) ; V_128 > V_5 ; ) {
union V_51 * V_177 ;
V_177 = F_44 ( V_2 , V_2 -> V_80 [ V_128 ] , V_4 ) ;
error = F_84 ( V_2 , V_177 , -- V_128 ,
0 , & V_4 , & V_7 ) ;
if ( error )
goto V_173;
F_67 ( V_2 , V_128 , V_7 ) ;
V_2 -> V_80 [ V_128 ] = F_106 ( V_4 ) ;
}
V_174:
F_92 ( V_2 , V_164 ) ;
* V_172 = 1 ;
return 0 ;
V_175:
F_92 ( V_2 , V_164 ) ;
* V_172 = 0 ;
return 0 ;
V_173:
F_92 ( V_2 , V_178 ) ;
return error ;
}
STATIC int
F_109 (
struct V_1 * V_2 ,
int V_5 ,
union V_51 * V_180 ,
struct V_3 * * V_181 )
{
struct V_6 * V_7 ;
int error = 0 ;
if ( ( V_2 -> V_46 & V_103 ) &&
( V_5 == V_2 -> V_67 - 1 ) ) {
* V_181 = F_46 ( V_2 ) ;
return 0 ;
}
V_7 = V_2 -> V_68 [ V_5 ] ;
if ( V_7 && F_36 ( V_7 ) == F_81 ( V_2 , V_180 ) ) {
* V_181 = F_24 ( V_7 ) ;
return 0 ;
}
error = F_84 ( V_2 , V_180 , V_5 , 0 , V_181 , & V_7 ) ;
if ( error )
return error ;
F_67 ( V_2 , V_5 , V_7 ) ;
return 0 ;
}
STATIC union V_96 *
F_110 (
struct V_1 * V_2 ,
int V_5 ,
int V_182 ,
struct V_3 * V_4 ,
union V_96 * V_183 )
{
if ( V_5 == 0 ) {
V_2 -> V_23 -> V_184 ( V_183 ,
F_42 ( V_2 , V_182 , V_4 ) ) ;
return V_183 ;
}
return F_43 ( V_2 , V_182 , V_4 ) ;
}
int
F_111 (
struct V_1 * V_2 ,
T_17 V_160 ,
int * V_172 )
{
struct V_3 * V_4 ;
T_12 V_185 ;
int error ;
int V_182 ;
int V_5 ;
union V_51 * V_180 ;
union V_51 V_52 ;
F_92 ( V_2 , V_162 ) ;
F_104 ( V_2 , V_160 ) ;
F_107 ( V_2 , V_186 ) ;
V_4 = NULL ;
V_182 = 0 ;
V_2 -> V_23 -> V_187 ( V_2 , & V_52 ) ;
V_180 = & V_52 ;
for ( V_5 = V_2 -> V_67 - 1 , V_185 = 1 ; V_5 >= 0 ; V_5 -- ) {
error = F_109 ( V_2 , V_5 , V_180 , & V_4 ) ;
if ( error )
goto V_173;
if ( V_185 == 0 ) {
V_182 = 1 ;
} else {
int V_188 ;
int V_189 ;
V_189 = 1 ;
V_188 = F_106 ( V_4 ) ;
if ( ! V_188 ) {
ASSERT ( V_5 == 0 && V_2 -> V_67 == 1 ) ;
V_2 -> V_80 [ 0 ] = V_160 != V_190 ;
F_92 ( V_2 , V_164 ) ;
* V_172 = 0 ;
return 0 ;
}
while ( V_189 <= V_188 ) {
union V_96 V_159 ;
union V_96 * V_183 ;
F_107 ( V_2 , V_191 ) ;
V_182 = ( V_189 + V_188 ) >> 1 ;
V_183 = F_110 ( V_2 , V_5 ,
V_182 , V_4 , & V_159 ) ;
V_185 = V_2 -> V_23 -> V_192 ( V_2 , V_183 ) ;
if ( V_185 < 0 )
V_189 = V_182 + 1 ;
else if ( V_185 > 0 )
V_188 = V_182 - 1 ;
else
break;
}
}
if ( V_5 > 0 ) {
if ( V_185 > 0 && -- V_182 < 1 )
V_182 = 1 ;
V_180 = F_44 ( V_2 , V_182 , V_4 ) ;
#ifdef F_105
error = F_22 ( V_2 , V_180 , 0 , V_5 ) ;
if ( error )
goto V_173;
#endif
V_2 -> V_80 [ V_5 ] = V_182 ;
}
}
if ( V_160 != V_190 && V_185 < 0 ) {
V_182 ++ ;
F_70 ( V_2 , V_4 , & V_52 , V_130 ) ;
if ( V_160 == V_193 &&
V_182 > F_106 ( V_4 ) &&
! F_68 ( V_2 , & V_52 ) ) {
int V_66 ;
V_2 -> V_80 [ 0 ] = V_182 ;
error = F_103 ( V_2 , 0 , & V_66 ) ;
if ( error )
goto V_173;
F_20 ( V_66 == 1 ) ;
F_92 ( V_2 , V_164 ) ;
* V_172 = 1 ;
return 0 ;
}
} else if ( V_160 == V_190 && V_185 > 0 )
V_182 -- ;
V_2 -> V_80 [ 0 ] = V_182 ;
if ( V_182 == 0 || V_182 > F_106 ( V_4 ) )
* V_172 = 0 ;
else if ( V_160 != V_194 || V_185 == 0 )
* V_172 = 1 ;
else
* V_172 = 0 ;
F_92 ( V_2 , V_164 ) ;
return 0 ;
V_173:
F_92 ( V_2 , V_178 ) ;
return error ;
}
STATIC int
F_112 (
struct V_1 * V_2 ,
union V_96 * V_195 ,
int V_5 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_96 * V_183 ;
int V_52 ;
F_92 ( V_2 , V_162 ) ;
F_113 ( V_2 , V_5 , V_195 ) ;
ASSERT ( ! ( V_2 -> V_46 & V_103 ) || V_5 >= 1 ) ;
for ( V_52 = 1 ; V_52 == 1 && V_5 < V_2 -> V_67 ; V_5 ++ ) {
#ifdef F_105
int error ;
#endif
V_4 = F_48 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_105
error = F_18 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error ) {
F_92 ( V_2 , V_178 ) ;
return error ;
}
#endif
V_52 = V_2 -> V_80 [ V_5 ] ;
V_183 = F_43 ( V_2 , V_52 , V_4 ) ;
F_85 ( V_2 , V_183 , V_195 , 1 ) ;
F_91 ( V_2 , V_7 , V_52 , V_52 ) ;
}
F_92 ( V_2 , V_164 ) ;
return 0 ;
}
int
F_114 (
struct V_1 * V_2 ,
union V_95 * V_161 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int error ;
int V_52 ;
union V_95 * V_196 ;
F_92 ( V_2 , V_162 ) ;
F_115 ( V_2 , V_161 ) ;
V_4 = F_48 ( V_2 , 0 , & V_7 ) ;
#ifdef F_105
error = F_18 ( V_2 , V_4 , 0 , V_7 ) ;
if ( error )
goto V_173;
#endif
V_52 = V_2 -> V_80 [ 0 ] ;
V_196 = F_42 ( V_2 , V_52 , V_4 ) ;
F_86 ( V_2 , V_196 , V_161 , 1 ) ;
F_98 ( V_2 , V_7 , V_52 , V_52 ) ;
if ( F_77 ( V_2 , V_4 , 0 ) ) {
V_2 -> V_23 -> V_197 ( V_2 , V_4 , V_161 ,
V_52 , V_198 ) ;
}
if ( V_52 == 1 ) {
union V_96 V_159 ;
V_2 -> V_23 -> V_184 ( & V_159 , V_161 ) ;
error = F_112 ( V_2 , & V_159 , 1 ) ;
if ( error )
goto V_173;
}
F_92 ( V_2 , V_164 ) ;
return 0 ;
V_173:
F_92 ( V_2 , V_178 ) ;
return error ;
}
STATIC int
F_116 (
struct V_1 * V_2 ,
int V_5 ,
int * V_172 )
{
union V_96 V_159 ;
struct V_6 * V_199 ;
struct V_3 * V_124 ;
int V_200 ;
struct V_6 * V_201 ;
struct V_3 * V_125 ;
int V_202 ;
union V_51 V_203 ;
union V_96 * V_204 = NULL ;
union V_51 * V_205 = NULL ;
union V_95 * V_206 = NULL ;
int error ;
F_92 ( V_2 , V_162 ) ;
F_104 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_46 & V_103 ) &&
V_5 == V_2 -> V_67 - 1 )
goto V_175;
V_125 = F_48 ( V_2 , V_5 , & V_201 ) ;
#ifdef F_105
error = F_18 ( V_2 , V_125 , V_5 , V_201 ) ;
if ( error )
goto V_173;
#endif
F_70 ( V_2 , V_125 , & V_203 , V_129 ) ;
if ( F_68 ( V_2 , & V_203 ) )
goto V_175;
if ( V_2 -> V_80 [ V_5 ] <= 1 )
goto V_175;
error = F_84 ( V_2 , & V_203 , V_5 , 0 , & V_124 , & V_199 ) ;
if ( error )
goto V_173;
V_200 = F_106 ( V_124 ) ;
if ( V_200 == V_2 -> V_23 -> V_24 ( V_2 , V_5 ) )
goto V_175;
V_202 = F_106 ( V_125 ) ;
V_200 ++ ;
V_202 -- ;
F_107 ( V_2 , V_207 ) ;
F_117 ( V_2 , V_208 , 1 ) ;
if ( V_5 > 0 ) {
union V_96 * V_209 ;
union V_51 * V_210 ;
V_209 = F_43 ( V_2 , V_200 , V_124 ) ;
V_204 = F_43 ( V_2 , 1 , V_125 ) ;
V_210 = F_44 ( V_2 , V_200 , V_124 ) ;
V_205 = F_44 ( V_2 , 1 , V_125 ) ;
#ifdef F_105
error = F_22 ( V_2 , V_205 , 0 , V_5 ) ;
if ( error )
goto V_173;
#endif
F_85 ( V_2 , V_209 , V_204 , 1 ) ;
F_87 ( V_2 , V_210 , V_205 , 1 ) ;
F_91 ( V_2 , V_199 , V_200 , V_200 ) ;
F_99 ( V_2 , V_199 , V_200 , V_200 ) ;
ASSERT ( V_2 -> V_23 -> V_211 ( V_2 ,
F_43 ( V_2 , V_200 - 1 , V_124 ) , V_209 ) ) ;
} else {
union V_95 * V_212 ;
V_212 = F_42 ( V_2 , V_200 , V_124 ) ;
V_206 = F_42 ( V_2 , 1 , V_125 ) ;
F_86 ( V_2 , V_212 , V_206 , 1 ) ;
F_98 ( V_2 , V_199 , V_200 , V_200 ) ;
ASSERT ( V_2 -> V_23 -> V_213 ( V_2 ,
F_42 ( V_2 , V_200 - 1 , V_124 ) , V_212 ) ) ;
}
F_118 ( V_124 , V_200 ) ;
F_100 ( V_2 , V_199 , V_214 ) ;
F_118 ( V_125 , V_202 ) ;
F_100 ( V_2 , V_201 , V_214 ) ;
F_117 ( V_2 , V_208 , V_202 - 1 ) ;
if ( V_5 > 0 ) {
#ifdef F_105
int V_66 ;
for ( V_66 = 0 ; V_66 < V_202 ; V_66 ++ ) {
error = F_22 ( V_2 , V_205 , V_66 + 1 , V_5 ) ;
if ( error )
goto V_173;
}
#endif
F_88 ( V_2 ,
F_43 ( V_2 , 2 , V_125 ) ,
- 1 , V_202 ) ;
F_90 ( V_2 ,
F_44 ( V_2 , 2 , V_125 ) ,
- 1 , V_202 ) ;
F_91 ( V_2 , V_201 , 1 , V_202 ) ;
F_99 ( V_2 , V_201 , 1 , V_202 ) ;
} else {
F_89 ( V_2 ,
F_42 ( V_2 , 2 , V_125 ) ,
- 1 , V_202 ) ;
F_98 ( V_2 , V_201 , 1 , V_202 ) ;
V_2 -> V_23 -> V_184 ( & V_159 ,
F_42 ( V_2 , 1 , V_125 ) ) ;
V_204 = & V_159 ;
}
error = F_112 ( V_2 , V_204 , V_5 + 1 ) ;
if ( error )
goto V_173;
V_2 -> V_80 [ V_5 ] -- ;
F_92 ( V_2 , V_164 ) ;
* V_172 = 1 ;
return 0 ;
V_175:
F_92 ( V_2 , V_164 ) ;
* V_172 = 0 ;
return 0 ;
V_173:
F_92 ( V_2 , V_178 ) ;
return error ;
}
STATIC int
F_119 (
struct V_1 * V_2 ,
int V_5 ,
int * V_172 )
{
union V_96 V_159 ;
struct V_6 * V_199 ;
struct V_3 * V_124 ;
struct V_6 * V_201 ;
struct V_3 * V_125 ;
struct V_1 * V_215 ;
union V_51 V_216 ;
union V_96 * V_204 ;
int V_202 ;
int V_200 ;
int error ;
int V_66 ;
F_92 ( V_2 , V_162 ) ;
F_104 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_46 & V_103 ) &&
( V_5 == V_2 -> V_67 - 1 ) )
goto V_175;
V_124 = F_48 ( V_2 , V_5 , & V_199 ) ;
#ifdef F_105
error = F_18 ( V_2 , V_124 , V_5 , V_199 ) ;
if ( error )
goto V_173;
#endif
F_70 ( V_2 , V_124 , & V_216 , V_130 ) ;
if ( F_68 ( V_2 , & V_216 ) )
goto V_175;
V_200 = F_106 ( V_124 ) ;
if ( V_2 -> V_80 [ V_5 ] >= V_200 )
goto V_175;
error = F_84 ( V_2 , & V_216 , V_5 , 0 , & V_125 , & V_201 ) ;
if ( error )
goto V_173;
V_202 = F_106 ( V_125 ) ;
if ( V_202 == V_2 -> V_23 -> V_24 ( V_2 , V_5 ) )
goto V_175;
F_107 ( V_2 , V_217 ) ;
F_117 ( V_2 , V_208 , V_202 ) ;
if ( V_5 > 0 ) {
union V_96 * V_209 ;
union V_51 * V_210 ;
union V_51 * V_205 ;
V_209 = F_43 ( V_2 , V_200 , V_124 ) ;
V_210 = F_44 ( V_2 , V_200 , V_124 ) ;
V_204 = F_43 ( V_2 , 1 , V_125 ) ;
V_205 = F_44 ( V_2 , 1 , V_125 ) ;
#ifdef F_105
for ( V_66 = V_202 - 1 ; V_66 >= 0 ; V_66 -- ) {
error = F_22 ( V_2 , V_205 , V_66 , V_5 ) ;
if ( error )
goto V_173;
}
#endif
F_88 ( V_2 , V_204 , 1 , V_202 ) ;
F_90 ( V_2 , V_205 , 1 , V_202 ) ;
#ifdef F_105
error = F_22 ( V_2 , V_210 , 0 , V_5 ) ;
if ( error )
goto V_173;
#endif
F_85 ( V_2 , V_204 , V_209 , 1 ) ;
F_87 ( V_2 , V_205 , V_210 , 1 ) ;
F_91 ( V_2 , V_201 , 1 , V_202 + 1 ) ;
F_99 ( V_2 , V_201 , 1 , V_202 + 1 ) ;
ASSERT ( V_2 -> V_23 -> V_211 ( V_2 , V_204 ,
F_43 ( V_2 , 2 , V_125 ) ) ) ;
} else {
union V_95 * V_212 ;
union V_95 * V_206 ;
V_212 = F_42 ( V_2 , V_200 , V_124 ) ;
V_206 = F_42 ( V_2 , 1 , V_125 ) ;
F_89 ( V_2 , V_206 , 1 , V_202 ) ;
F_86 ( V_2 , V_206 , V_212 , 1 ) ;
F_98 ( V_2 , V_201 , 1 , V_202 + 1 ) ;
V_2 -> V_23 -> V_184 ( & V_159 , V_206 ) ;
V_204 = & V_159 ;
ASSERT ( V_2 -> V_23 -> V_213 ( V_2 , V_206 ,
F_42 ( V_2 , 2 , V_125 ) ) ) ;
}
F_118 ( V_124 , -- V_200 ) ;
F_100 ( V_2 , V_199 , V_214 ) ;
F_118 ( V_125 , ++ V_202 ) ;
F_100 ( V_2 , V_201 , V_214 ) ;
error = F_34 ( V_2 , & V_215 ) ;
if ( error )
goto V_173;
V_66 = F_57 ( V_215 , V_5 ) ;
F_120 ( V_66 == 1 , V_173 ) ;
error = F_103 ( V_215 , V_5 , & V_66 ) ;
if ( error )
goto V_218;
error = F_112 ( V_215 , V_204 , V_5 + 1 ) ;
if ( error )
goto V_218;
F_31 ( V_215 , V_219 ) ;
F_92 ( V_2 , V_164 ) ;
* V_172 = 1 ;
return 0 ;
V_175:
F_92 ( V_2 , V_164 ) ;
* V_172 = 0 ;
return 0 ;
V_173:
F_92 ( V_2 , V_178 ) ;
return error ;
V_218:
F_92 ( V_215 , V_178 ) ;
F_31 ( V_215 , V_220 ) ;
return error ;
}
STATIC int
F_121 (
struct V_1 * V_2 ,
int V_5 ,
union V_51 * V_177 ,
union V_96 * V_159 ,
struct V_1 * * V_221 ,
int * V_172 )
{
union V_51 V_203 ;
struct V_6 * V_199 ;
struct V_3 * V_124 ;
union V_51 V_216 ;
struct V_6 * V_201 ;
struct V_3 * V_125 ;
union V_51 V_222 ;
struct V_6 * V_223 ;
struct V_3 * V_224 ;
int V_200 ;
int V_202 ;
int V_225 ;
int error ;
#ifdef F_105
int V_66 ;
#endif
F_92 ( V_2 , V_162 ) ;
F_122 ( V_2 , V_5 , * V_177 , V_159 ) ;
F_107 ( V_2 , V_226 ) ;
V_124 = F_48 ( V_2 , V_5 , & V_199 ) ;
#ifdef F_105
error = F_18 ( V_2 , V_124 , V_5 , V_199 ) ;
if ( error )
goto V_173;
#endif
F_78 ( V_2 , V_199 , & V_203 ) ;
error = V_2 -> V_23 -> V_227 ( V_2 , & V_203 , & V_216 , 1 , V_172 ) ;
if ( error )
goto V_173;
if ( * V_172 == 0 )
goto V_175;
F_107 ( V_2 , V_228 ) ;
error = F_83 ( V_2 , & V_216 , 0 , & V_125 , & V_201 ) ;
if ( error )
goto V_173;
F_76 ( V_2 , V_201 , F_45 ( V_124 ) , 0 ) ;
V_200 = F_106 ( V_124 ) ;
V_202 = V_200 / 2 ;
if ( ( V_200 & 1 ) && V_2 -> V_80 [ V_5 ] <= V_202 + 1 )
V_202 ++ ;
V_225 = ( V_200 - V_202 + 1 ) ;
F_117 ( V_2 , V_208 , V_202 ) ;
if ( V_5 > 0 ) {
union V_96 * V_209 ;
union V_51 * V_210 ;
union V_96 * V_204 ;
union V_51 * V_205 ;
V_209 = F_43 ( V_2 , V_225 , V_124 ) ;
V_210 = F_44 ( V_2 , V_225 , V_124 ) ;
V_204 = F_43 ( V_2 , 1 , V_125 ) ;
V_205 = F_44 ( V_2 , 1 , V_125 ) ;
#ifdef F_105
for ( V_66 = V_225 ; V_66 < V_202 ; V_66 ++ ) {
error = F_22 ( V_2 , V_210 , V_66 , V_5 ) ;
if ( error )
goto V_173;
}
#endif
F_85 ( V_2 , V_204 , V_209 , V_202 ) ;
F_87 ( V_2 , V_205 , V_210 , V_202 ) ;
F_91 ( V_2 , V_201 , 1 , V_202 ) ;
F_99 ( V_2 , V_201 , 1 , V_202 ) ;
F_85 ( V_2 , V_159 , V_204 , 1 ) ;
} else {
union V_95 * V_212 ;
union V_95 * V_206 ;
V_212 = F_42 ( V_2 , V_225 , V_124 ) ;
V_206 = F_42 ( V_2 , 1 , V_125 ) ;
F_86 ( V_2 , V_206 , V_212 , V_202 ) ;
F_98 ( V_2 , V_201 , 1 , V_202 ) ;
V_2 -> V_23 -> V_184 ( V_159 ,
F_42 ( V_2 , 1 , V_125 ) ) ;
}
F_70 ( V_2 , V_124 , & V_222 , V_130 ) ;
F_71 ( V_2 , V_125 , & V_222 , V_130 ) ;
F_71 ( V_2 , V_125 , & V_203 , V_129 ) ;
F_71 ( V_2 , V_124 , & V_216 , V_130 ) ;
V_200 -= V_202 ;
F_118 ( V_124 , V_200 ) ;
F_118 ( V_125 , F_106 ( V_125 ) + V_202 ) ;
F_100 ( V_2 , V_201 , V_168 ) ;
F_100 ( V_2 , V_199 , V_214 | V_130 ) ;
if ( ! F_68 ( V_2 , & V_222 ) ) {
error = F_84 ( V_2 , & V_222 , V_5 ,
0 , & V_224 , & V_223 ) ;
if ( error )
goto V_173;
F_71 ( V_2 , V_224 , & V_216 , V_129 ) ;
F_100 ( V_2 , V_223 , V_129 ) ;
}
if ( V_2 -> V_80 [ V_5 ] > V_200 + 1 ) {
F_67 ( V_2 , V_5 , V_201 ) ;
V_2 -> V_80 [ V_5 ] -= V_200 ;
}
if ( V_5 + 1 < V_2 -> V_67 ) {
error = F_34 ( V_2 , V_221 ) ;
if ( error )
goto V_173;
( * V_221 ) -> V_80 [ V_5 + 1 ] ++ ;
}
* V_177 = V_216 ;
F_92 ( V_2 , V_164 ) ;
* V_172 = 1 ;
return 0 ;
V_175:
F_92 ( V_2 , V_164 ) ;
* V_172 = 0 ;
return 0 ;
V_173:
F_92 ( V_2 , V_178 ) ;
return error ;
}
int
F_123 (
struct V_1 * V_2 ,
int * V_229 ,
int * V_172 )
{
struct V_6 * V_230 ;
struct V_3 * V_4 ;
struct V_3 * V_231 ;
union V_96 * V_232 ;
union V_51 * V_233 ;
union V_96 * V_183 ;
union V_51 * V_180 ;
union V_51 V_234 ;
int V_5 ;
int error ;
#ifdef F_105
int V_66 ;
#endif
F_92 ( V_2 , V_162 ) ;
F_107 ( V_2 , V_235 ) ;
ASSERT ( V_2 -> V_46 & V_103 ) ;
V_5 = V_2 -> V_67 - 1 ;
V_4 = F_46 ( V_2 ) ;
V_180 = F_44 ( V_2 , 1 , V_4 ) ;
error = V_2 -> V_23 -> V_227 ( V_2 , V_180 , & V_234 , 1 , V_172 ) ;
if ( error )
goto V_173;
if ( * V_172 == 0 ) {
F_92 ( V_2 , V_164 ) ;
return 0 ;
}
F_107 ( V_2 , V_228 ) ;
error = F_83 ( V_2 , & V_234 , 0 , & V_231 , & V_230 ) ;
if ( error )
goto V_173;
memcpy ( V_231 , V_4 , F_37 ( V_2 ) ) ;
if ( V_2 -> V_46 & V_85 ) {
if ( V_2 -> V_46 & V_47 )
V_231 -> V_13 . V_14 . V_17 = F_4 ( V_230 -> V_18 ) ;
else
V_231 -> V_13 . V_42 . V_17 = F_4 ( V_230 -> V_18 ) ;
}
F_124 ( & V_4 -> V_21 , 1 ) ;
F_118 ( V_4 , 1 ) ;
V_2 -> V_67 ++ ;
V_2 -> V_80 [ V_5 + 1 ] = 1 ;
V_183 = F_43 ( V_2 , 1 , V_4 ) ;
V_232 = F_43 ( V_2 , 1 , V_231 ) ;
F_85 ( V_2 , V_232 , V_183 , F_106 ( V_231 ) ) ;
V_233 = F_44 ( V_2 , 1 , V_231 ) ;
#ifdef F_105
for ( V_66 = 0 ; V_66 < F_7 ( V_231 -> V_22 ) ; V_66 ++ ) {
error = F_22 ( V_2 , V_180 , V_66 , V_5 ) ;
if ( error )
goto V_173;
}
#endif
F_87 ( V_2 , V_233 , V_180 , F_106 ( V_231 ) ) ;
#ifdef F_105
error = F_22 ( V_2 , & V_234 , 0 , V_5 ) ;
if ( error )
goto V_173;
#endif
F_87 ( V_2 , V_180 , & V_234 , 1 ) ;
F_125 ( V_2 -> V_39 . V_72 . V_99 ,
1 - F_106 ( V_231 ) ,
V_2 -> V_39 . V_72 . V_100 ) ;
F_67 ( V_2 , V_5 , V_230 ) ;
F_100 ( V_2 , V_230 , V_168 ) ;
F_91 ( V_2 , V_230 , 1 , F_7 ( V_231 -> V_22 ) ) ;
F_99 ( V_2 , V_230 , 1 , F_7 ( V_231 -> V_22 ) ) ;
* V_229 |=
V_236 | F_97 ( V_2 -> V_39 . V_72 . V_100 ) ;
* V_172 = 1 ;
F_92 ( V_2 , V_164 ) ;
return 0 ;
V_173:
F_92 ( V_2 , V_178 ) ;
return error ;
}
STATIC int
F_126 (
struct V_1 * V_2 ,
int * V_172 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int error ;
struct V_6 * V_199 ;
struct V_3 * V_124 ;
struct V_6 * V_237 ;
struct V_3 * V_76 ;
int V_234 ;
struct V_6 * V_201 ;
struct V_3 * V_125 ;
union V_51 V_216 ;
union V_51 V_203 ;
F_92 ( V_2 , V_162 ) ;
F_107 ( V_2 , V_235 ) ;
V_2 -> V_23 -> V_187 ( V_2 , & V_216 ) ;
error = V_2 -> V_23 -> V_227 ( V_2 , & V_216 , & V_203 , 1 , V_172 ) ;
if ( error )
goto V_173;
if ( * V_172 == 0 )
goto V_175;
F_107 ( V_2 , V_228 ) ;
error = F_83 ( V_2 , & V_203 , 0 , & V_76 , & V_237 ) ;
if ( error )
goto V_173;
V_2 -> V_23 -> V_238 ( V_2 , & V_203 , 1 ) ;
V_4 = F_48 ( V_2 , V_2 -> V_67 - 1 , & V_7 ) ;
#ifdef F_105
error = F_18 ( V_2 , V_4 , V_2 -> V_67 - 1 , V_7 ) ;
if ( error )
goto V_173;
#endif
F_70 ( V_2 , V_4 , & V_216 , V_130 ) ;
if ( ! F_68 ( V_2 , & V_216 ) ) {
V_199 = V_7 ;
F_78 ( V_2 , V_199 , & V_203 ) ;
V_124 = V_4 ;
error = F_84 ( V_2 , & V_216 ,
V_2 -> V_67 - 1 , 0 , & V_125 , & V_201 ) ;
if ( error )
goto V_173;
V_7 = V_201 ;
V_234 = 1 ;
} else {
V_201 = V_7 ;
F_78 ( V_2 , V_201 , & V_216 ) ;
V_125 = V_4 ;
F_70 ( V_2 , V_125 , & V_203 , V_129 ) ;
error = F_84 ( V_2 , & V_203 ,
V_2 -> V_67 - 1 , 0 , & V_124 , & V_199 ) ;
if ( error )
goto V_173;
V_7 = V_199 ;
V_234 = 2 ;
}
F_76 ( V_2 , V_237 , V_2 -> V_67 , 2 ) ;
F_100 ( V_2 , V_237 , V_168 ) ;
ASSERT ( ! F_68 ( V_2 , & V_203 ) &&
! F_68 ( V_2 , & V_216 ) ) ;
if ( F_45 ( V_124 ) > 0 ) {
F_85 ( V_2 ,
F_43 ( V_2 , 1 , V_76 ) ,
F_43 ( V_2 , 1 , V_124 ) , 1 ) ;
F_85 ( V_2 ,
F_43 ( V_2 , 2 , V_76 ) ,
F_43 ( V_2 , 1 , V_125 ) , 1 ) ;
} else {
V_2 -> V_23 -> V_184 (
F_43 ( V_2 , 1 , V_76 ) ,
F_42 ( V_2 , 1 , V_124 ) ) ;
V_2 -> V_23 -> V_184 (
F_43 ( V_2 , 2 , V_76 ) ,
F_42 ( V_2 , 1 , V_125 ) ) ;
}
F_91 ( V_2 , V_237 , 1 , 2 ) ;
F_87 ( V_2 ,
F_44 ( V_2 , 1 , V_76 ) , & V_203 , 1 ) ;
F_87 ( V_2 ,
F_44 ( V_2 , 2 , V_76 ) , & V_216 , 1 ) ;
F_99 ( V_2 , V_237 , 1 , 2 ) ;
F_67 ( V_2 , V_2 -> V_67 , V_237 ) ;
V_2 -> V_80 [ V_2 -> V_67 ] = V_234 ;
V_2 -> V_67 ++ ;
F_92 ( V_2 , V_164 ) ;
* V_172 = 1 ;
return 0 ;
V_173:
F_92 ( V_2 , V_178 ) ;
return error ;
V_175:
F_92 ( V_2 , V_164 ) ;
* V_172 = 0 ;
return 0 ;
}
STATIC int
F_127 (
struct V_1 * V_2 ,
int V_5 ,
int V_134 ,
int * V_239 ,
int * V_53 ,
union V_51 * V_234 ,
struct V_1 * * V_75 ,
union V_95 * V_240 ,
int * V_172 )
{
union V_96 V_159 ;
int error = 0 ;
if ( ( V_2 -> V_46 & V_103 ) &&
V_5 == V_2 -> V_67 - 1 ) {
struct V_241 * V_99 = V_2 -> V_39 . V_72 . V_99 ;
if ( V_134 < V_2 -> V_23 -> V_242 ( V_2 , V_5 ) ) {
F_125 ( V_99 , 1 , V_2 -> V_39 . V_72 . V_100 ) ;
} else {
int V_229 = 0 ;
error = F_123 ( V_2 , & V_229 , V_172 ) ;
if ( error || * V_172 == 0 )
return error ;
F_96 ( V_2 -> V_69 , V_99 , V_229 ) ;
}
return 0 ;
}
error = F_119 ( V_2 , V_5 , V_172 ) ;
if ( error || * V_172 )
return error ;
error = F_116 ( V_2 , V_5 , V_172 ) ;
if ( error )
return error ;
if ( * V_172 ) {
* V_239 = * V_53 = V_2 -> V_80 [ V_5 ] ;
return 0 ;
}
error = F_121 ( V_2 , V_5 , V_234 , & V_159 , V_75 , V_172 ) ;
if ( error || * V_172 == 0 )
return error ;
* V_53 = V_2 -> V_80 [ V_5 ] ;
V_2 -> V_23 -> V_243 ( & V_159 , V_240 ) ;
return 0 ;
}
STATIC int
F_128 (
struct V_1 * V_2 ,
int V_5 ,
union V_51 * V_177 ,
union V_95 * V_244 ,
struct V_1 * * V_221 ,
int * V_172 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_96 V_159 ;
union V_51 V_234 ;
struct V_1 * V_75 ;
union V_95 V_240 ;
int V_245 ;
int V_52 ;
int V_134 ;
int error ;
#ifdef F_105
int V_66 ;
#endif
F_92 ( V_2 , V_162 ) ;
F_129 ( V_2 , V_5 , * V_177 , V_244 ) ;
V_75 = NULL ;
if ( ! ( V_2 -> V_46 & V_103 ) &&
( V_5 >= V_2 -> V_67 ) ) {
error = F_126 ( V_2 , V_172 ) ;
F_69 ( V_2 , V_177 ) ;
F_92 ( V_2 , V_164 ) ;
return error ;
}
V_52 = V_2 -> V_80 [ V_5 ] ;
if ( V_52 == 0 ) {
F_92 ( V_2 , V_164 ) ;
* V_172 = 0 ;
return 0 ;
}
V_2 -> V_23 -> V_184 ( & V_159 , V_244 ) ;
V_245 = V_52 ;
F_107 ( V_2 , V_246 ) ;
V_4 = F_48 ( V_2 , V_5 , & V_7 ) ;
V_134 = F_106 ( V_4 ) ;
#ifdef F_105
error = F_18 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_173;
if ( V_52 <= V_134 ) {
if ( V_5 == 0 ) {
ASSERT ( V_2 -> V_23 -> V_213 ( V_2 , V_244 ,
F_42 ( V_2 , V_52 , V_4 ) ) ) ;
} else {
ASSERT ( V_2 -> V_23 -> V_211 ( V_2 , & V_159 ,
F_43 ( V_2 , V_52 , V_4 ) ) ) ;
}
}
#endif
F_69 ( V_2 , & V_234 ) ;
if ( V_134 == V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ) {
error = F_127 ( V_2 , V_5 , V_134 ,
& V_245 , & V_52 , & V_234 , & V_75 , & V_240 , V_172 ) ;
if ( error || * V_172 == 0 )
goto V_173;
}
V_4 = F_48 ( V_2 , V_5 , & V_7 ) ;
V_134 = F_106 ( V_4 ) ;
#ifdef F_105
error = F_18 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
return error ;
#endif
F_117 ( V_2 , V_208 , V_134 - V_52 + 1 ) ;
if ( V_5 > 0 ) {
union V_96 * V_183 ;
union V_51 * V_180 ;
V_183 = F_43 ( V_2 , V_52 , V_4 ) ;
V_180 = F_44 ( V_2 , V_52 , V_4 ) ;
#ifdef F_105
for ( V_66 = V_134 - V_52 ; V_66 >= 0 ; V_66 -- ) {
error = F_22 ( V_2 , V_180 , V_66 , V_5 ) ;
if ( error )
return error ;
}
#endif
F_88 ( V_2 , V_183 , 1 , V_134 - V_52 + 1 ) ;
F_90 ( V_2 , V_180 , 1 , V_134 - V_52 + 1 ) ;
#ifdef F_105
error = F_22 ( V_2 , V_177 , 0 , V_5 ) ;
if ( error )
goto V_173;
#endif
F_85 ( V_2 , V_183 , & V_159 , 1 ) ;
F_87 ( V_2 , V_180 , V_177 , 1 ) ;
V_134 ++ ;
F_118 ( V_4 , V_134 ) ;
F_99 ( V_2 , V_7 , V_52 , V_134 ) ;
F_91 ( V_2 , V_7 , V_52 , V_134 ) ;
#ifdef F_105
if ( V_52 < V_134 ) {
ASSERT ( V_2 -> V_23 -> V_211 ( V_2 , V_183 ,
F_43 ( V_2 , V_52 + 1 , V_4 ) ) ) ;
}
#endif
} else {
union V_95 * V_196 ;
V_196 = F_42 ( V_2 , V_52 , V_4 ) ;
F_89 ( V_2 , V_196 , 1 , V_134 - V_52 + 1 ) ;
F_86 ( V_2 , V_196 , V_244 , 1 ) ;
F_118 ( V_4 , ++ V_134 ) ;
F_98 ( V_2 , V_7 , V_52 , V_134 ) ;
#ifdef F_105
if ( V_52 < V_134 ) {
ASSERT ( V_2 -> V_23 -> V_213 ( V_2 , V_196 ,
F_42 ( V_2 , V_52 + 1 , V_4 ) ) ) ;
}
#endif
}
F_100 ( V_2 , V_7 , V_214 ) ;
if ( V_245 == 1 ) {
error = F_112 ( V_2 , & V_159 , V_5 + 1 ) ;
if ( error )
goto V_173;
}
if ( F_77 ( V_2 , V_4 , V_5 ) ) {
V_2 -> V_23 -> V_197 ( V_2 , V_4 , V_244 ,
V_52 , V_247 ) ;
}
* V_177 = V_234 ;
if ( ! F_68 ( V_2 , & V_234 ) ) {
* V_244 = V_240 ;
* V_221 = V_75 ;
}
F_92 ( V_2 , V_164 ) ;
* V_172 = 1 ;
return 0 ;
V_173:
F_92 ( V_2 , V_178 ) ;
return error ;
}
int
F_130 (
struct V_1 * V_2 ,
int * V_172 )
{
int error ;
int V_66 ;
int V_5 ;
union V_51 V_234 ;
struct V_1 * V_75 ;
struct V_1 * V_248 ;
union V_95 V_161 ;
V_5 = 0 ;
V_75 = NULL ;
V_248 = V_2 ;
F_69 ( V_2 , & V_234 ) ;
V_2 -> V_23 -> V_249 ( V_2 , & V_161 ) ;
do {
error = F_128 ( V_248 , V_5 , & V_234 , & V_161 , & V_75 , & V_66 ) ;
if ( error ) {
if ( V_248 != V_2 )
F_31 ( V_248 , V_220 ) ;
goto V_173;
}
F_120 ( V_66 == 1 , V_173 ) ;
V_5 ++ ;
if ( V_248 != V_2 &&
( V_75 || F_68 ( V_2 , & V_234 ) ) ) {
if ( V_2 -> V_23 -> V_250 )
V_2 -> V_23 -> V_250 ( V_248 , V_2 ) ;
V_2 -> V_67 = V_248 -> V_67 ;
F_31 ( V_248 , V_219 ) ;
}
if ( V_75 ) {
V_248 = V_75 ;
V_75 = NULL ;
}
} while ( ! F_68 ( V_2 , & V_234 ) );
F_92 ( V_2 , V_164 ) ;
* V_172 = V_66 ;
return 0 ;
V_173:
F_92 ( V_2 , V_178 ) ;
return error ;
}
STATIC int
F_131 (
struct V_1 * V_2 )
{
int V_100 = V_2 -> V_39 . V_72 . V_100 ;
struct V_241 * V_99 = V_2 -> V_39 . V_72 . V_99 ;
struct V_97 * V_98 = F_47 ( V_99 , V_100 ) ;
struct V_3 * V_4 ;
struct V_3 * V_231 ;
union V_96 * V_183 ;
union V_96 * V_232 ;
union V_51 * V_180 ;
union V_51 * V_233 ;
struct V_6 * V_230 ;
int V_5 ;
int V_53 ;
int V_134 ;
#ifdef F_105
union V_51 V_52 ;
int V_66 ;
#endif
F_92 ( V_2 , V_162 ) ;
ASSERT ( V_2 -> V_46 & V_103 ) ;
ASSERT ( V_2 -> V_67 > 1 ) ;
V_5 = V_2 -> V_67 - 1 ;
if ( V_5 == 1 )
goto V_175;
V_4 = F_46 ( V_2 ) ;
if ( F_106 ( V_4 ) != 1 )
goto V_175;
V_231 = F_48 ( V_2 , V_5 - 1 , & V_230 ) ;
V_134 = F_106 ( V_231 ) ;
if ( V_134 > V_2 -> V_23 -> V_242 ( V_2 , V_5 ) )
goto V_175;
F_107 ( V_2 , V_251 ) ;
#ifdef F_105
F_70 ( V_2 , V_4 , & V_52 , V_129 ) ;
ASSERT ( F_68 ( V_2 , & V_52 ) ) ;
F_70 ( V_2 , V_4 , & V_52 , V_130 ) ;
ASSERT ( F_68 ( V_2 , & V_52 ) ) ;
#endif
V_53 = V_134 - V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ;
if ( V_53 ) {
F_125 ( V_2 -> V_39 . V_72 . V_99 , V_53 ,
V_2 -> V_39 . V_72 . V_100 ) ;
V_4 = V_98 -> V_101 ;
}
F_124 ( & V_4 -> V_22 , V_53 ) ;
ASSERT ( V_4 -> V_22 == V_231 -> V_22 ) ;
V_183 = F_43 ( V_2 , 1 , V_4 ) ;
V_232 = F_43 ( V_2 , 1 , V_231 ) ;
F_85 ( V_2 , V_183 , V_232 , V_134 ) ;
V_180 = F_44 ( V_2 , 1 , V_4 ) ;
V_233 = F_44 ( V_2 , 1 , V_231 ) ;
#ifdef F_105
for ( V_66 = 0 ; V_66 < V_134 ; V_66 ++ ) {
int error ;
error = F_22 ( V_2 , V_233 , V_66 , V_5 - 1 ) ;
if ( error ) {
F_92 ( V_2 , V_178 ) ;
return error ;
}
}
#endif
F_87 ( V_2 , V_180 , V_233 , V_134 ) ;
V_2 -> V_23 -> V_252 ( V_2 , V_230 ) ;
F_107 ( V_2 , free ) ;
V_2 -> V_68 [ V_5 - 1 ] = NULL ;
F_124 ( & V_4 -> V_21 , - 1 ) ;
F_96 ( V_2 -> V_69 , V_99 ,
V_236 | F_97 ( V_2 -> V_39 . V_72 . V_100 ) ) ;
V_2 -> V_67 -- ;
V_175:
F_92 ( V_2 , V_164 ) ;
return 0 ;
}
STATIC int
F_132 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_5 ,
union V_51 * V_235 )
{
int error ;
F_92 ( V_2 , V_162 ) ;
F_107 ( V_2 , V_251 ) ;
V_2 -> V_23 -> V_238 ( V_2 , V_235 , - 1 ) ;
error = V_2 -> V_23 -> V_252 ( V_2 , V_7 ) ;
if ( error ) {
F_92 ( V_2 , V_178 ) ;
return error ;
}
F_107 ( V_2 , free ) ;
V_2 -> V_68 [ V_5 ] = NULL ;
V_2 -> V_81 [ V_5 ] = 0 ;
V_2 -> V_67 -- ;
F_92 ( V_2 , V_164 ) ;
return 0 ;
}
STATIC int
F_133 (
struct V_1 * V_2 ,
int V_5 ,
int * V_172 )
{
int error ;
int V_66 ;
if ( V_5 > 0 ) {
error = F_108 ( V_2 , V_5 , & V_66 ) ;
if ( error )
return error ;
}
F_92 ( V_2 , V_164 ) ;
* V_172 = 1 ;
return 0 ;
}
STATIC int
F_134 (
struct V_1 * V_2 ,
int V_5 ,
int * V_172 )
{
struct V_3 * V_4 ;
union V_51 V_253 ;
struct V_6 * V_7 ;
int error ;
int V_66 ;
union V_96 V_159 ;
union V_96 * V_195 = & V_159 ;
union V_51 V_203 ;
struct V_6 * V_199 ;
struct V_3 * V_124 ;
int V_200 = 0 ;
int V_52 ;
union V_51 V_216 ;
struct V_6 * V_201 ;
struct V_3 * V_125 ;
struct V_3 * V_224 ;
struct V_6 * V_223 ;
int V_202 = 0 ;
struct V_1 * V_215 ;
int V_134 ;
F_92 ( V_2 , V_162 ) ;
F_104 ( V_2 , V_5 ) ;
V_215 = NULL ;
V_52 = V_2 -> V_80 [ V_5 ] ;
if ( V_52 == 0 ) {
F_92 ( V_2 , V_164 ) ;
* V_172 = 0 ;
return 0 ;
}
V_4 = F_48 ( V_2 , V_5 , & V_7 ) ;
V_134 = F_106 ( V_4 ) ;
#ifdef F_105
error = F_18 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_173;
#endif
if ( V_52 > V_134 ) {
F_92 ( V_2 , V_164 ) ;
* V_172 = 0 ;
return 0 ;
}
F_107 ( V_2 , V_254 ) ;
F_117 ( V_2 , V_208 , V_134 - V_52 ) ;
if ( V_5 > 0 ) {
union V_96 * V_209 ;
union V_51 * V_210 ;
V_209 = F_43 ( V_2 , V_52 + 1 , V_4 ) ;
V_210 = F_44 ( V_2 , V_52 + 1 , V_4 ) ;
#ifdef F_105
for ( V_66 = 0 ; V_66 < V_134 - V_52 ; V_66 ++ ) {
error = F_22 ( V_2 , V_210 , V_66 , V_5 ) ;
if ( error )
goto V_173;
}
#endif
if ( V_52 < V_134 ) {
F_88 ( V_2 , V_209 , - 1 , V_134 - V_52 ) ;
F_90 ( V_2 , V_210 , - 1 , V_134 - V_52 ) ;
F_91 ( V_2 , V_7 , V_52 , V_134 - 1 ) ;
F_99 ( V_2 , V_7 , V_52 , V_134 - 1 ) ;
}
if ( V_52 == 1 )
V_195 = F_43 ( V_2 , 1 , V_4 ) ;
} else {
if ( V_52 < V_134 ) {
F_89 ( V_2 ,
F_42 ( V_2 , V_52 + 1 , V_4 ) ,
- 1 , V_134 - V_52 ) ;
F_98 ( V_2 , V_7 , V_52 , V_134 - 1 ) ;
}
if ( V_52 == 1 ) {
V_2 -> V_23 -> V_184 ( & V_159 ,
F_42 ( V_2 , 1 , V_4 ) ) ;
V_195 = & V_159 ;
}
}
F_118 ( V_4 , -- V_134 ) ;
F_100 ( V_2 , V_7 , V_214 ) ;
if ( F_77 ( V_2 , V_4 , V_5 ) ) {
V_2 -> V_23 -> V_197 ( V_2 , V_4 , NULL ,
V_52 , V_255 ) ;
}
if ( V_5 == V_2 -> V_67 - 1 ) {
if ( V_2 -> V_46 & V_103 ) {
F_125 ( V_2 -> V_39 . V_72 . V_99 , - 1 ,
V_2 -> V_39 . V_72 . V_100 ) ;
error = F_131 ( V_2 ) ;
if ( error )
goto V_173;
error = F_133 ( V_2 , V_5 , V_172 ) ;
if ( error )
goto V_173;
* V_172 = 1 ;
return 0 ;
}
if ( V_134 == 1 && V_5 > 0 ) {
union V_51 * V_180 ;
V_180 = F_44 ( V_2 , 1 , V_4 ) ;
error = F_132 ( V_2 , V_7 , V_5 , V_180 ) ;
if ( error )
goto V_173;
} else if ( V_5 > 0 ) {
error = F_133 ( V_2 , V_5 , V_172 ) ;
if ( error )
goto V_173;
}
* V_172 = 1 ;
return 0 ;
}
if ( V_52 == 1 ) {
error = F_112 ( V_2 , V_195 , V_5 + 1 ) ;
if ( error )
goto V_173;
}
if ( V_134 >= V_2 -> V_23 -> V_256 ( V_2 , V_5 ) ) {
error = F_133 ( V_2 , V_5 , V_172 ) ;
if ( error )
goto V_173;
return 0 ;
}
F_70 ( V_2 , V_4 , & V_216 , V_130 ) ;
F_70 ( V_2 , V_4 , & V_203 , V_129 ) ;
if ( V_2 -> V_46 & V_103 ) {
if ( F_68 ( V_2 , & V_216 ) &&
F_68 ( V_2 , & V_203 ) &&
V_5 == V_2 -> V_67 - 2 ) {
error = F_131 ( V_2 ) ;
if ( ! error )
error = F_133 ( V_2 , V_5 , V_172 ) ;
if ( error )
goto V_173;
return 0 ;
}
}
ASSERT ( ! F_68 ( V_2 , & V_216 ) ||
! F_68 ( V_2 , & V_203 ) ) ;
error = F_34 ( V_2 , & V_215 ) ;
if ( error )
goto V_173;
if ( ! F_68 ( V_2 , & V_216 ) ) {
V_66 = F_57 ( V_215 , V_5 ) ;
F_120 ( V_66 == 1 , V_173 ) ;
error = F_103 ( V_215 , V_5 , & V_66 ) ;
if ( error )
goto V_173;
F_120 ( V_66 == 1 , V_173 ) ;
V_66 = F_57 ( V_215 , V_5 ) ;
F_120 ( V_66 == 1 , V_173 ) ;
V_125 = F_48 ( V_215 , V_5 , & V_201 ) ;
#ifdef F_105
error = F_18 ( V_215 , V_125 , V_5 , V_201 ) ;
if ( error )
goto V_173;
#endif
F_70 ( V_215 , V_125 , & V_253 , V_129 ) ;
if ( F_106 ( V_125 ) - 1 >=
V_2 -> V_23 -> V_256 ( V_215 , V_5 ) ) {
error = F_116 ( V_215 , V_5 , & V_66 ) ;
if ( error )
goto V_173;
if ( V_66 ) {
ASSERT ( F_106 ( V_4 ) >=
V_2 -> V_23 -> V_256 ( V_215 , V_5 ) ) ;
F_31 ( V_215 , V_219 ) ;
V_215 = NULL ;
error = F_133 ( V_2 , V_5 , V_172 ) ;
if ( error )
goto V_173;
return 0 ;
}
}
V_202 = F_106 ( V_125 ) ;
if ( ! F_68 ( V_2 , & V_203 ) ) {
V_66 = F_56 ( V_215 , V_5 ) ;
F_120 ( V_66 == 1 , V_173 ) ;
error = F_108 ( V_215 , V_5 , & V_66 ) ;
if ( error )
goto V_173;
F_120 ( V_66 == 1 , V_173 ) ;
}
}
if ( ! F_68 ( V_2 , & V_203 ) ) {
V_66 = F_56 ( V_215 , V_5 ) ;
F_120 ( V_66 == 1 , V_173 ) ;
error = F_108 ( V_215 , V_5 , & V_66 ) ;
if ( error )
goto V_173;
V_66 = F_56 ( V_215 , V_5 ) ;
F_120 ( V_66 == 1 , V_173 ) ;
V_124 = F_48 ( V_215 , V_5 , & V_199 ) ;
#ifdef F_105
error = F_18 ( V_2 , V_124 , V_5 , V_199 ) ;
if ( error )
goto V_173;
#endif
F_70 ( V_215 , V_124 , & V_253 , V_130 ) ;
if ( F_106 ( V_124 ) - 1 >=
V_2 -> V_23 -> V_256 ( V_215 , V_5 ) ) {
error = F_119 ( V_215 , V_5 , & V_66 ) ;
if ( error )
goto V_173;
if ( V_66 ) {
ASSERT ( F_106 ( V_4 ) >=
V_2 -> V_23 -> V_256 ( V_215 , V_5 ) ) ;
F_31 ( V_215 , V_219 ) ;
V_215 = NULL ;
if ( V_5 == 0 )
V_2 -> V_80 [ 0 ] ++ ;
F_92 ( V_2 , V_164 ) ;
* V_172 = 1 ;
return 0 ;
}
}
V_200 = F_106 ( V_124 ) ;
}
F_31 ( V_215 , V_219 ) ;
V_215 = NULL ;
ASSERT ( ! F_68 ( V_2 , & V_253 ) ) ;
if ( ! F_68 ( V_2 , & V_203 ) &&
V_200 + F_106 ( V_4 ) <=
V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ) {
V_216 = V_253 ;
V_125 = V_4 ;
V_201 = V_7 ;
error = F_84 ( V_2 , & V_203 , V_5 ,
0 , & V_124 , & V_199 ) ;
if ( error )
goto V_173;
} else if ( ! F_68 ( V_2 , & V_216 ) &&
V_202 + F_106 ( V_4 ) <=
V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ) {
V_203 = V_253 ;
V_124 = V_4 ;
V_199 = V_7 ;
error = F_84 ( V_2 , & V_216 , V_5 ,
0 , & V_125 , & V_201 ) ;
if ( error )
goto V_173;
} else {
error = F_133 ( V_2 , V_5 , V_172 ) ;
if ( error )
goto V_173;
return 0 ;
}
V_202 = F_106 ( V_125 ) ;
V_200 = F_106 ( V_124 ) ;
F_117 ( V_2 , V_208 , V_202 ) ;
if ( V_5 > 0 ) {
union V_96 * V_209 ;
union V_51 * V_210 ;
union V_96 * V_204 ;
union V_51 * V_205 ;
V_209 = F_43 ( V_2 , V_200 + 1 , V_124 ) ;
V_210 = F_44 ( V_2 , V_200 + 1 , V_124 ) ;
V_204 = F_43 ( V_2 , 1 , V_125 ) ;
V_205 = F_44 ( V_2 , 1 , V_125 ) ;
#ifdef F_105
for ( V_66 = 1 ; V_66 < V_202 ; V_66 ++ ) {
error = F_22 ( V_2 , V_205 , V_66 , V_5 ) ;
if ( error )
goto V_173;
}
#endif
F_85 ( V_2 , V_209 , V_204 , V_202 ) ;
F_87 ( V_2 , V_210 , V_205 , V_202 ) ;
F_91 ( V_2 , V_199 , V_200 + 1 , V_200 + V_202 ) ;
F_99 ( V_2 , V_199 , V_200 + 1 , V_200 + V_202 ) ;
} else {
union V_95 * V_212 ;
union V_95 * V_206 ;
V_212 = F_42 ( V_2 , V_200 + 1 , V_124 ) ;
V_206 = F_42 ( V_2 , 1 , V_125 ) ;
F_86 ( V_2 , V_212 , V_206 , V_202 ) ;
F_98 ( V_2 , V_199 , V_200 + 1 , V_200 + V_202 ) ;
}
F_107 ( V_2 , V_257 ) ;
F_118 ( V_124 , V_200 + V_202 ) ;
F_70 ( V_2 , V_125 , & V_253 , V_130 ) ,
F_71 ( V_2 , V_124 , & V_253 , V_130 ) ;
F_100 ( V_2 , V_199 , V_214 | V_130 ) ;
F_70 ( V_2 , V_124 , & V_253 , V_130 ) ;
if ( ! F_68 ( V_2 , & V_253 ) ) {
error = F_84 ( V_2 , & V_253 , V_5 ,
0 , & V_224 , & V_223 ) ;
if ( error )
goto V_173;
F_71 ( V_2 , V_224 , & V_203 , V_129 ) ;
F_100 ( V_2 , V_223 , V_129 ) ;
}
error = V_2 -> V_23 -> V_252 ( V_2 , V_201 ) ;
if ( error )
goto V_173;
F_107 ( V_2 , free ) ;
if ( V_7 != V_199 ) {
V_2 -> V_68 [ V_5 ] = V_199 ;
V_2 -> V_80 [ V_5 ] += V_200 ;
V_2 -> V_81 [ V_5 ] = 0 ;
}
else if ( ( V_2 -> V_46 & V_103 ) ||
( V_5 + 1 < V_2 -> V_67 ) ) {
error = F_103 ( V_2 , V_5 + 1 , & V_66 ) ;
if ( error )
goto V_173;
}
if ( V_5 > 0 )
V_2 -> V_80 [ V_5 ] -- ;
F_92 ( V_2 , V_164 ) ;
* V_172 = 2 ;
return 0 ;
V_173:
F_92 ( V_2 , V_178 ) ;
if ( V_215 )
F_31 ( V_215 , V_220 ) ;
return error ;
}
int
F_135 (
struct V_1 * V_2 ,
int * V_172 )
{
int error ;
int V_5 ;
int V_66 ;
F_92 ( V_2 , V_162 ) ;
for ( V_5 = 0 , V_66 = 2 ; V_66 == 2 ; V_5 ++ ) {
error = F_134 ( V_2 , V_5 , & V_66 ) ;
if ( error )
goto V_173;
}
if ( V_66 == 0 ) {
for ( V_5 = 1 ; V_5 < V_2 -> V_67 ; V_5 ++ ) {
if ( V_2 -> V_80 [ V_5 ] == 0 ) {
error = F_108 ( V_2 , V_5 , & V_66 ) ;
if ( error )
goto V_173;
break;
}
}
}
F_92 ( V_2 , V_164 ) ;
* V_172 = V_66 ;
return 0 ;
V_173:
F_92 ( V_2 , V_178 ) ;
return error ;
}
int
F_136 (
struct V_1 * V_2 ,
union V_95 * * V_244 ,
int * V_172 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int V_52 ;
#ifdef F_105
int error ;
#endif
V_52 = V_2 -> V_80 [ 0 ] ;
V_4 = F_48 ( V_2 , 0 , & V_7 ) ;
#ifdef F_105
error = F_18 ( V_2 , V_4 , 0 , V_7 ) ;
if ( error )
return error ;
#endif
if ( V_52 > F_106 ( V_4 ) || V_52 <= 0 ) {
* V_172 = 0 ;
return 0 ;
}
* V_244 = F_42 ( V_2 , V_52 , V_4 ) ;
* V_172 = 1 ;
return 0 ;
}
