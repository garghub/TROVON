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
int V_91 ,
int V_5 )
{
return F_39 ( V_2 ) +
V_2 -> V_23 -> V_24 ( V_2 , V_5 ) * V_2 -> V_23 -> V_93 +
( V_91 - 1 ) * F_40 ( V_2 ) ;
}
STATIC union V_94 *
F_44 (
struct V_1 * V_2 ,
int V_91 ,
struct V_3 * V_4 )
{
return (union V_94 * )
( ( char * ) V_4 + F_41 ( V_2 , V_91 ) ) ;
}
STATIC union V_95 *
F_45 (
struct V_1 * V_2 ,
int V_91 ,
struct V_3 * V_4 )
{
return (union V_95 * )
( ( char * ) V_4 + F_42 ( V_2 , V_91 ) ) ;
}
STATIC union V_51 *
F_46 (
struct V_1 * V_2 ,
int V_91 ,
struct V_3 * V_4 )
{
int V_5 = F_47 ( V_4 ) ;
ASSERT ( V_4 -> V_21 != 0 ) ;
return (union V_51 * )
( ( char * ) V_4 + F_43 ( V_2 , V_91 , V_5 ) ) ;
}
STATIC struct V_3 *
F_48 (
struct V_1 * V_2 )
{
struct V_96 * V_97 ;
V_97 = F_49 ( V_2 -> V_39 . V_71 . V_98 , V_2 -> V_39 . V_71 . V_99 ) ;
return (struct V_3 * ) V_97 -> V_100 ;
}
STATIC struct V_3 *
F_50 (
struct V_1 * V_2 ,
int V_5 ,
struct V_6 * * V_101 )
{
if ( ( V_2 -> V_46 & V_102 ) &&
( V_5 == V_2 -> V_67 - 1 ) ) {
* V_101 = NULL ;
return F_48 ( V_2 ) ;
}
* V_101 = V_2 -> V_68 [ V_5 ] ;
return F_23 ( * V_101 ) ;
}
T_4 *
F_51 (
T_5 * V_10 ,
T_6 * V_76 ,
T_2 V_103 ,
T_8 V_104 )
{
T_9 V_105 ;
ASSERT ( V_103 != V_26 ) ;
V_105 = F_52 ( V_10 , V_103 ) ;
return F_53 ( V_76 , V_10 -> V_81 , V_105 , V_10 -> V_82 , V_104 ) ;
}
T_4 *
F_54 (
T_5 * V_10 ,
T_6 * V_76 ,
T_10 V_106 ,
T_1 V_107 ,
T_8 V_104 )
{
T_9 V_105 ;
ASSERT ( V_106 != V_108 ) ;
ASSERT ( V_107 != V_43 ) ;
V_105 = F_55 ( V_10 , V_106 , V_107 ) ;
return F_53 ( V_76 , V_10 -> V_81 , V_105 , V_10 -> V_82 , V_104 ) ;
}
int
F_56 (
T_3 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
V_4 = F_50 ( V_2 , V_5 , & V_7 ) ;
F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( V_2 -> V_46 & V_47 )
return V_4 -> V_13 . V_14 . V_27 == F_4 ( V_26 ) ;
else
return V_4 -> V_13 . V_42 . V_27 == F_16 ( V_43 ) ;
}
STATIC int
F_57 (
T_3 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
V_4 = F_50 ( V_2 , V_5 , & V_7 ) ;
F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( ! V_4 -> V_22 )
return 0 ;
V_2 -> V_79 [ V_5 ] = 1 ;
return 1 ;
}
STATIC int
F_58 (
T_3 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
V_4 = F_50 ( V_2 , V_5 , & V_7 ) ;
F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( ! V_4 -> V_22 )
return 0 ;
V_2 -> V_79 [ V_5 ] = F_7 ( V_4 -> V_22 ) ;
return 1 ;
}
void
F_59 (
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
F_60 (
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
V_105 = F_52 ( V_10 , V_103 ) ;
error = F_37 ( V_10 , V_76 , V_10 -> V_81 , V_105 ,
V_10 -> V_82 , V_104 , & V_7 , V_118 ) ;
if ( error )
return error ;
if ( V_7 )
F_61 ( V_7 , V_116 ) ;
* V_101 = V_7 ;
return 0 ;
}
void
F_62 (
struct V_9 * V_10 ,
T_2 V_103 ,
T_12 V_119 ,
const struct V_117 * V_118 )
{
T_9 V_105 ;
ASSERT ( V_103 != V_26 ) ;
V_105 = F_52 ( V_10 , V_103 ) ;
F_63 ( V_10 -> V_81 , V_105 , V_10 -> V_82 * V_119 , V_118 ) ;
}
void
F_64 (
struct V_9 * V_10 ,
T_10 V_106 ,
T_1 V_107 ,
T_12 V_119 ,
const struct V_117 * V_118 )
{
T_9 V_105 ;
ASSERT ( V_106 != V_108 ) ;
ASSERT ( V_107 != V_43 ) ;
V_105 = F_55 ( V_10 , V_106 , V_107 ) ;
F_63 ( V_10 -> V_81 , V_105 , V_10 -> V_82 * V_119 , V_118 ) ;
}
STATIC int
F_65 (
struct V_1 * V_2 ,
int V_120 ,
struct V_3 * V_4 )
{
int V_121 = 0 ;
T_2 V_122 = F_9 ( V_4 -> V_13 . V_14 . V_25 ) ;
T_2 V_123 = F_9 ( V_4 -> V_13 . V_14 . V_27 ) ;
if ( ( V_120 & V_124 ) && V_122 != V_26 ) {
F_62 ( V_2 -> V_11 , V_122 , 1 ,
V_2 -> V_23 -> V_83 ) ;
V_121 ++ ;
}
if ( ( V_120 & V_125 ) && V_123 != V_26 ) {
F_62 ( V_2 -> V_11 , V_123 , 1 ,
V_2 -> V_23 -> V_83 ) ;
V_121 ++ ;
}
return V_121 ;
}
STATIC int
F_66 (
struct V_1 * V_2 ,
int V_120 ,
struct V_3 * V_4 )
{
int V_121 = 0 ;
T_1 V_122 = F_5 ( V_4 -> V_13 . V_42 . V_25 ) ;
T_1 V_123 = F_5 ( V_4 -> V_13 . V_42 . V_27 ) ;
if ( ( V_120 & V_124 ) && V_122 != V_43 ) {
F_64 ( V_2 -> V_11 , V_2 -> V_39 . V_40 . V_106 ,
V_122 , 1 , V_2 -> V_23 -> V_83 ) ;
V_121 ++ ;
}
if ( ( V_120 & V_125 ) && V_123 != V_43 ) {
F_64 ( V_2 -> V_11 , V_2 -> V_39 . V_40 . V_106 ,
V_123 , 1 , V_2 -> V_23 -> V_83 ) ;
V_121 ++ ;
}
return V_121 ;
}
STATIC int
F_67 (
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
return F_65 ( V_2 , V_120 , V_4 ) ;
return F_66 ( V_2 , V_120 , V_4 ) ;
}
STATIC T_9
F_68 (
struct V_1 * V_2 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 ) {
ASSERT ( V_52 -> V_14 != F_4 ( V_26 ) ) ;
return F_52 ( V_2 -> V_11 , F_9 ( V_52 -> V_14 ) ) ;
} else {
ASSERT ( V_2 -> V_39 . V_40 . V_106 != V_108 ) ;
ASSERT ( V_52 -> V_42 != F_16 ( V_43 ) ) ;
return F_55 ( V_2 -> V_11 , V_2 -> V_39 . V_40 . V_106 ,
F_5 ( V_52 -> V_42 ) ) ;
}
}
STATIC void
F_69 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
T_12 V_119 )
{
F_63 ( V_2 -> V_11 -> V_81 ,
F_68 ( V_2 , V_52 ) ,
V_2 -> V_11 -> V_82 * V_119 , V_2 -> V_23 -> V_83 ) ;
}
STATIC void
F_70 (
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
F_71 (
struct V_1 * V_2 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 )
return V_52 -> V_14 == F_4 ( V_26 ) ;
else
return V_52 -> V_42 == F_16 ( V_43 ) ;
}
STATIC void
F_72 (
struct V_1 * V_2 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 )
V_52 -> V_14 = F_4 ( V_26 ) ;
else
V_52 -> V_42 = F_16 ( V_43 ) ;
}
STATIC void
F_73 (
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
F_74 (
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
F_75 (
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
V_129 -> V_21 = F_76 ( V_5 ) ;
V_129 -> V_22 = F_76 ( V_132 ) ;
if ( V_134 & V_47 ) {
V_129 -> V_13 . V_14 . V_25 = F_4 ( V_26 ) ;
V_129 -> V_13 . V_14 . V_27 = F_4 ( V_26 ) ;
if ( V_134 & V_84 ) {
V_129 -> V_13 . V_14 . V_17 = F_4 ( V_130 ) ;
V_129 -> V_13 . V_14 . V_135 = F_4 ( V_133 ) ;
F_77 ( & V_129 -> V_13 . V_14 . V_15 , & V_10 -> V_12 . V_16 ) ;
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
F_77 ( & V_129 -> V_13 . V_42 . V_15 , & V_10 -> V_12 . V_16 ) ;
V_129 -> V_13 . V_42 . V_59 = 0 ;
}
}
}
void
F_78 (
struct V_9 * V_10 ,
struct V_6 * V_7 ,
T_13 V_131 ,
T_14 V_5 ,
T_14 V_132 ,
T_15 V_133 ,
unsigned int V_134 )
{
F_75 ( V_10 , F_23 ( V_7 ) , V_7 -> V_18 ,
V_131 , V_5 , V_132 , V_133 , V_134 ) ;
}
STATIC void
F_79 (
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
F_75 ( V_2 -> V_11 , F_23 ( V_7 ) , V_7 -> V_18 ,
F_6 ( V_2 ) , V_5 , V_132 ,
V_133 , V_2 -> V_46 ) ;
}
STATIC int
F_80 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
union V_51 V_52 ;
if ( V_5 > 0 )
return 0 ;
if ( ! ( V_2 -> V_46 & V_139 ) )
return 0 ;
F_73 ( V_2 , V_4 , & V_52 , V_128 ) ;
if ( ! F_71 ( V_2 , & V_52 ) )
return 0 ;
return 1 ;
}
STATIC void
F_81 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 )
V_52 -> V_14 = F_4 ( F_82 ( V_2 -> V_11 ,
F_38 ( V_7 ) ) ) ;
else {
V_52 -> V_42 = F_16 ( F_83 ( V_2 -> V_11 ,
F_38 ( V_7 ) ) ) ;
}
}
STATIC void
F_84 (
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
switch ( V_2 -> V_69 ) {
case V_140 :
case V_141 :
F_61 ( V_7 , V_142 ) ;
break;
case V_143 :
case V_144 :
F_61 ( V_7 , V_145 ) ;
break;
case V_70 :
F_61 ( V_7 , V_146 ) ;
break;
default:
ASSERT ( 0 ) ;
}
}
STATIC int
F_85 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
int V_134 ,
struct V_3 * * V_4 ,
struct V_6 * * V_101 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_9 V_105 ;
ASSERT ( ! ( V_134 & V_147 ) ) ;
V_105 = F_68 ( V_2 , V_52 ) ;
* V_101 = F_53 ( V_2 -> V_65 , V_10 -> V_81 , V_105 ,
V_10 -> V_82 , V_134 ) ;
if ( ! * V_101 )
return - V_148 ;
( * V_101 ) -> V_149 = V_2 -> V_23 -> V_83 ;
* V_4 = F_23 ( * V_101 ) ;
return 0 ;
}
STATIC int
F_86 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
int V_134 ,
struct V_3 * * V_4 ,
struct V_6 * * V_101 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_9 V_105 ;
int error ;
ASSERT ( ! ( V_134 & V_147 ) ) ;
V_105 = F_68 ( V_2 , V_52 ) ;
error = F_37 ( V_10 , V_2 -> V_65 , V_10 -> V_81 , V_105 ,
V_10 -> V_82 , V_134 , V_101 ,
V_2 -> V_23 -> V_83 ) ;
if ( error )
return error ;
F_84 ( V_2 , * V_101 ) ;
* V_4 = F_23 ( * V_101 ) ;
return 0 ;
}
STATIC void
F_87 (
struct V_1 * V_2 ,
union V_95 * V_150 ,
union V_95 * V_151 ,
int V_152 )
{
ASSERT ( V_152 >= 0 ) ;
memcpy ( V_150 , V_151 , V_152 * V_2 -> V_23 -> V_93 ) ;
}
STATIC void
F_88 (
struct V_1 * V_2 ,
union V_94 * V_153 ,
union V_94 * V_154 ,
int V_132 )
{
ASSERT ( V_132 >= 0 ) ;
memcpy ( V_153 , V_154 , V_132 * V_2 -> V_23 -> V_92 ) ;
}
STATIC void
F_89 (
struct V_1 * V_2 ,
union V_51 * V_155 ,
union V_51 * V_156 ,
int V_157 )
{
ASSERT ( V_157 >= 0 ) ;
memcpy ( V_155 , V_156 , V_157 * F_40 ( V_2 ) ) ;
}
STATIC void
F_90 (
struct V_1 * V_2 ,
union V_95 * V_158 ,
int V_159 ,
int V_152 )
{
char * V_150 ;
ASSERT ( V_152 >= 0 ) ;
ASSERT ( V_159 == 1 || V_159 == - 1 ) ;
V_150 = ( char * ) V_158 + ( V_159 * V_2 -> V_23 -> V_93 ) ;
memmove ( V_150 , V_158 , V_152 * V_2 -> V_23 -> V_93 ) ;
}
STATIC void
F_91 (
struct V_1 * V_2 ,
union V_94 * V_160 ,
int V_159 ,
int V_132 )
{
char * V_153 ;
ASSERT ( V_132 >= 0 ) ;
ASSERT ( V_159 == 1 || V_159 == - 1 ) ;
V_153 = ( char * ) V_160 + ( V_159 * V_2 -> V_23 -> V_92 ) ;
memmove ( V_153 , V_160 , V_132 * V_2 -> V_23 -> V_92 ) ;
}
STATIC void
F_92 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
int V_159 ,
int V_157 )
{
char * V_155 ;
ASSERT ( V_157 >= 0 ) ;
ASSERT ( V_159 == 1 || V_159 == - 1 ) ;
V_155 = ( char * ) V_52 + ( V_159 * F_40 ( V_2 ) ) ;
memmove ( V_155 , V_52 , V_157 * F_40 ( V_2 ) ) ;
}
STATIC void
F_93 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_112 ,
int V_113 )
{
F_94 ( V_2 , V_161 ) ;
F_95 ( V_2 , V_7 , V_112 , V_113 ) ;
if ( V_7 ) {
F_96 ( V_2 -> V_65 , V_7 , V_162 ) ;
F_97 ( V_2 -> V_65 , V_7 ,
F_42 ( V_2 , V_112 ) ,
F_42 ( V_2 , V_113 + 1 ) - 1 ) ;
} else {
F_98 ( V_2 -> V_65 , V_2 -> V_39 . V_71 . V_98 ,
F_99 ( V_2 -> V_39 . V_71 . V_99 ) ) ;
}
F_94 ( V_2 , V_163 ) ;
}
void
F_100 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_112 ,
int V_113 )
{
F_94 ( V_2 , V_161 ) ;
F_95 ( V_2 , V_7 , V_112 , V_113 ) ;
F_96 ( V_2 -> V_65 , V_7 , V_162 ) ;
F_97 ( V_2 -> V_65 , V_7 ,
F_41 ( V_2 , V_112 ) ,
F_41 ( V_2 , V_113 + 1 ) - 1 ) ;
F_94 ( V_2 , V_163 ) ;
}
STATIC void
F_101 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_112 ,
int V_113 )
{
F_94 ( V_2 , V_161 ) ;
F_95 ( V_2 , V_7 , V_112 , V_113 ) ;
if ( V_7 ) {
struct V_3 * V_4 = F_23 ( V_7 ) ;
int V_5 = F_47 ( V_4 ) ;
F_96 ( V_2 -> V_65 , V_7 , V_162 ) ;
F_97 ( V_2 -> V_65 , V_7 ,
F_43 ( V_2 , V_112 , V_5 ) ,
F_43 ( V_2 , V_113 + 1 , V_5 ) - 1 ) ;
} else {
F_98 ( V_2 -> V_65 , V_2 -> V_39 . V_71 . V_98 ,
F_99 ( V_2 -> V_39 . V_71 . V_99 ) ) ;
}
F_94 ( V_2 , V_163 ) ;
}
void
F_102 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_109 )
{
int V_112 ;
int V_113 ;
static const short V_164 [] = {
F_103 ( struct V_3 , V_20 ) ,
F_103 ( struct V_3 , V_21 ) ,
F_103 ( struct V_3 , V_22 ) ,
F_103 ( struct V_3 , V_13 . V_42 . V_25 ) ,
F_103 ( struct V_3 , V_13 . V_42 . V_27 ) ,
F_103 ( struct V_3 , V_13 . V_42 . V_17 ) ,
F_103 ( struct V_3 , V_13 . V_42 . V_59 ) ,
F_103 ( struct V_3 , V_13 . V_42 . V_15 ) ,
F_103 ( struct V_3 , V_13 . V_42 . V_135 ) ,
F_103 ( struct V_3 , V_13 . V_42 . V_165 ) ,
V_87
} ;
static const short V_166 [] = {
F_103 ( struct V_3 , V_20 ) ,
F_103 ( struct V_3 , V_21 ) ,
F_103 ( struct V_3 , V_22 ) ,
F_103 ( struct V_3 , V_13 . V_14 . V_25 ) ,
F_103 ( struct V_3 , V_13 . V_14 . V_27 ) ,
F_103 ( struct V_3 , V_13 . V_14 . V_17 ) ,
F_103 ( struct V_3 , V_13 . V_14 . V_59 ) ,
F_103 ( struct V_3 , V_13 . V_14 . V_15 ) ,
F_103 ( struct V_3 , V_13 . V_14 . V_135 ) ,
F_103 ( struct V_3 , V_13 . V_14 . V_165 ) ,
F_103 ( struct V_3 , V_13 . V_14 . V_136 ) ,
V_85
} ;
F_94 ( V_2 , V_161 ) ;
F_104 ( V_2 , V_7 , V_109 ) ;
if ( V_7 ) {
int V_111 ;
if ( V_2 -> V_46 & V_84 ) {
if ( V_109 == V_167 )
V_109 = V_168 ;
V_111 = V_169 ;
} else {
V_111 = V_170 ;
}
F_59 ( V_109 ,
( V_2 -> V_46 & V_47 ) ?
V_166 : V_164 ,
V_111 , & V_112 , & V_113 ) ;
F_96 ( V_2 -> V_65 , V_7 , V_162 ) ;
F_97 ( V_2 -> V_65 , V_7 , V_112 , V_113 ) ;
} else {
F_98 ( V_2 -> V_65 , V_2 -> V_39 . V_71 . V_98 ,
F_99 ( V_2 -> V_39 . V_71 . V_99 ) ) ;
}
F_94 ( V_2 , V_163 ) ;
}
int
F_105 (
struct V_1 * V_2 ,
int V_5 ,
int * V_171 )
{
struct V_3 * V_4 ;
union V_51 V_52 ;
struct V_6 * V_7 ;
int error ;
int V_126 ;
F_94 ( V_2 , V_161 ) ;
F_106 ( V_2 , V_5 ) ;
ASSERT ( V_5 < V_2 -> V_67 ) ;
F_67 ( V_2 , V_5 , V_125 ) ;
V_4 = F_50 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_107
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_172;
#endif
if ( ++ V_2 -> V_79 [ V_5 ] <= F_108 ( V_4 ) )
goto V_173;
F_73 ( V_2 , V_4 , & V_52 , V_128 ) ;
if ( F_71 ( V_2 , & V_52 ) )
goto V_174;
F_32 ( V_2 , V_175 ) ;
for ( V_126 = V_5 + 1 ; V_126 < V_2 -> V_67 ; V_126 ++ ) {
V_4 = F_50 ( V_2 , V_126 , & V_7 ) ;
#ifdef F_107
error = F_17 ( V_2 , V_4 , V_126 , V_7 ) ;
if ( error )
goto V_172;
#endif
if ( ++ V_2 -> V_79 [ V_126 ] <= F_108 ( V_4 ) )
break;
F_67 ( V_2 , V_126 , V_125 ) ;
}
if ( V_126 == V_2 -> V_67 ) {
if ( V_2 -> V_46 & V_102 )
goto V_174;
ASSERT ( 0 ) ;
error = - V_33 ;
goto V_172;
}
ASSERT ( V_126 < V_2 -> V_67 ) ;
for ( V_4 = F_50 ( V_2 , V_126 , & V_7 ) ; V_126 > V_5 ; ) {
union V_51 * V_176 ;
V_176 = F_46 ( V_2 , V_2 -> V_79 [ V_126 ] , V_4 ) ;
-- V_126 ;
error = F_86 ( V_2 , V_176 , 0 , & V_4 , & V_7 ) ;
if ( error )
goto V_172;
F_70 ( V_2 , V_126 , V_7 ) ;
V_2 -> V_79 [ V_126 ] = 1 ;
}
V_173:
F_94 ( V_2 , V_163 ) ;
* V_171 = 1 ;
return 0 ;
V_174:
F_94 ( V_2 , V_163 ) ;
* V_171 = 0 ;
return 0 ;
V_172:
F_94 ( V_2 , V_177 ) ;
return error ;
}
int
F_109 (
struct V_1 * V_2 ,
int V_5 ,
int * V_171 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
int error ;
int V_126 ;
union V_51 V_52 ;
F_94 ( V_2 , V_161 ) ;
F_106 ( V_2 , V_5 ) ;
ASSERT ( V_5 < V_2 -> V_67 ) ;
F_67 ( V_2 , V_5 , V_124 ) ;
if ( -- V_2 -> V_79 [ V_5 ] > 0 )
goto V_173;
V_4 = F_50 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_107
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_172;
#endif
F_73 ( V_2 , V_4 , & V_52 , V_127 ) ;
if ( F_71 ( V_2 , & V_52 ) )
goto V_174;
F_32 ( V_2 , V_178 ) ;
for ( V_126 = V_5 + 1 ; V_126 < V_2 -> V_67 ; V_126 ++ ) {
if ( -- V_2 -> V_79 [ V_126 ] > 0 )
break;
F_67 ( V_2 , V_126 , V_124 ) ;
}
if ( V_126 == V_2 -> V_67 ) {
if ( V_2 -> V_46 & V_102 )
goto V_174;
ASSERT ( 0 ) ;
error = - V_33 ;
goto V_172;
}
ASSERT ( V_126 < V_2 -> V_67 ) ;
for ( V_4 = F_50 ( V_2 , V_126 , & V_7 ) ; V_126 > V_5 ; ) {
union V_51 * V_176 ;
V_176 = F_46 ( V_2 , V_2 -> V_79 [ V_126 ] , V_4 ) ;
-- V_126 ;
error = F_86 ( V_2 , V_176 , 0 , & V_4 , & V_7 ) ;
if ( error )
goto V_172;
F_70 ( V_2 , V_126 , V_7 ) ;
V_2 -> V_79 [ V_126 ] = F_108 ( V_4 ) ;
}
V_173:
F_94 ( V_2 , V_163 ) ;
* V_171 = 1 ;
return 0 ;
V_174:
F_94 ( V_2 , V_163 ) ;
* V_171 = 0 ;
return 0 ;
V_172:
F_94 ( V_2 , V_177 ) ;
return error ;
}
STATIC int
F_110 (
struct V_1 * V_2 ,
int V_5 ,
union V_51 * V_179 ,
struct V_3 * * V_180 )
{
struct V_6 * V_7 ;
int error = 0 ;
if ( ( V_2 -> V_46 & V_102 ) &&
( V_5 == V_2 -> V_67 - 1 ) ) {
* V_180 = F_48 ( V_2 ) ;
return 0 ;
}
V_7 = V_2 -> V_68 [ V_5 ] ;
if ( V_7 && F_38 ( V_7 ) == F_68 ( V_2 , V_179 ) ) {
* V_180 = F_23 ( V_7 ) ;
return 0 ;
}
error = F_86 ( V_2 , V_179 , 0 , V_180 , & V_7 ) ;
if ( error )
return error ;
F_70 ( V_2 , V_5 , V_7 ) ;
return 0 ;
}
STATIC union V_95 *
F_111 (
struct V_1 * V_2 ,
int V_5 ,
int V_181 ,
struct V_3 * V_4 ,
union V_95 * V_182 )
{
if ( V_5 == 0 ) {
V_2 -> V_23 -> V_183 ( V_182 ,
F_44 ( V_2 , V_181 , V_4 ) ) ;
return V_182 ;
}
return F_45 ( V_2 , V_181 , V_4 ) ;
}
int
F_112 (
struct V_1 * V_2 ,
T_16 V_159 ,
int * V_171 )
{
struct V_3 * V_4 ;
T_11 V_184 ;
int error ;
int V_181 ;
int V_5 ;
union V_51 * V_179 ;
union V_51 V_52 ;
F_94 ( V_2 , V_161 ) ;
F_106 ( V_2 , V_159 ) ;
F_32 ( V_2 , V_185 ) ;
V_4 = NULL ;
V_181 = 0 ;
V_2 -> V_23 -> V_186 ( V_2 , & V_52 ) ;
V_179 = & V_52 ;
for ( V_5 = V_2 -> V_67 - 1 , V_184 = 1 ; V_5 >= 0 ; V_5 -- ) {
error = F_110 ( V_2 , V_5 , V_179 , & V_4 ) ;
if ( error )
goto V_172;
if ( V_184 == 0 ) {
V_181 = 1 ;
} else {
int V_187 ;
int V_188 ;
V_188 = 1 ;
V_187 = F_108 ( V_4 ) ;
if ( ! V_187 ) {
ASSERT ( V_5 == 0 && V_2 -> V_67 == 1 ) ;
V_2 -> V_79 [ 0 ] = V_159 != V_189 ;
F_94 ( V_2 , V_163 ) ;
* V_171 = 0 ;
return 0 ;
}
while ( V_188 <= V_187 ) {
union V_95 V_158 ;
union V_95 * V_182 ;
F_32 ( V_2 , V_190 ) ;
V_181 = ( V_188 + V_187 ) >> 1 ;
V_182 = F_111 ( V_2 , V_5 ,
V_181 , V_4 , & V_158 ) ;
V_184 = V_2 -> V_23 -> V_191 ( V_2 , V_182 ) ;
if ( V_184 < 0 )
V_188 = V_181 + 1 ;
else if ( V_184 > 0 )
V_187 = V_181 - 1 ;
else
break;
}
}
if ( V_5 > 0 ) {
if ( V_184 > 0 && -- V_181 < 1 )
V_181 = 1 ;
V_179 = F_46 ( V_2 , V_181 , V_4 ) ;
#ifdef F_107
error = F_21 ( V_2 , V_179 , 0 , V_5 ) ;
if ( error )
goto V_172;
#endif
V_2 -> V_79 [ V_5 ] = V_181 ;
}
}
if ( V_159 != V_189 && V_184 < 0 ) {
V_181 ++ ;
F_73 ( V_2 , V_4 , & V_52 , V_128 ) ;
if ( V_159 == V_192 &&
V_181 > F_108 ( V_4 ) &&
! F_71 ( V_2 , & V_52 ) ) {
int V_66 ;
V_2 -> V_79 [ 0 ] = V_181 ;
error = F_105 ( V_2 , 0 , & V_66 ) ;
if ( error )
goto V_172;
F_19 ( V_2 -> V_11 , V_66 == 1 ) ;
F_94 ( V_2 , V_163 ) ;
* V_171 = 1 ;
return 0 ;
}
} else if ( V_159 == V_189 && V_184 > 0 )
V_181 -- ;
V_2 -> V_79 [ 0 ] = V_181 ;
if ( V_181 == 0 || V_181 > F_108 ( V_4 ) )
* V_171 = 0 ;
else if ( V_159 != V_193 || V_184 == 0 )
* V_171 = 1 ;
else
* V_171 = 0 ;
F_94 ( V_2 , V_163 ) ;
return 0 ;
V_172:
F_94 ( V_2 , V_177 ) ;
return error ;
}
STATIC int
F_113 (
struct V_1 * V_2 ,
union V_95 * V_194 ,
int V_5 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_95 * V_182 ;
int V_52 ;
F_94 ( V_2 , V_161 ) ;
F_114 ( V_2 , V_5 , V_194 ) ;
ASSERT ( ! ( V_2 -> V_46 & V_102 ) || V_5 >= 1 ) ;
for ( V_52 = 1 ; V_52 == 1 && V_5 < V_2 -> V_67 ; V_5 ++ ) {
#ifdef F_107
int error ;
#endif
V_4 = F_50 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_107
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error ) {
F_94 ( V_2 , V_177 ) ;
return error ;
}
#endif
V_52 = V_2 -> V_79 [ V_5 ] ;
V_182 = F_45 ( V_2 , V_52 , V_4 ) ;
F_87 ( V_2 , V_182 , V_194 , 1 ) ;
F_93 ( V_2 , V_7 , V_52 , V_52 ) ;
}
F_94 ( V_2 , V_163 ) ;
return 0 ;
}
int
F_115 (
struct V_1 * V_2 ,
union V_94 * V_160 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int error ;
int V_52 ;
union V_94 * V_195 ;
F_94 ( V_2 , V_161 ) ;
F_116 ( V_2 , V_160 ) ;
V_4 = F_50 ( V_2 , 0 , & V_7 ) ;
#ifdef F_107
error = F_17 ( V_2 , V_4 , 0 , V_7 ) ;
if ( error )
goto V_172;
#endif
V_52 = V_2 -> V_79 [ 0 ] ;
V_195 = F_44 ( V_2 , V_52 , V_4 ) ;
F_88 ( V_2 , V_195 , V_160 , 1 ) ;
F_100 ( V_2 , V_7 , V_52 , V_52 ) ;
if ( F_80 ( V_2 , V_4 , 0 ) ) {
V_2 -> V_23 -> V_196 ( V_2 , V_4 , V_160 ,
V_52 , V_197 ) ;
}
if ( V_52 == 1 ) {
union V_95 V_158 ;
V_2 -> V_23 -> V_183 ( & V_158 , V_160 ) ;
error = F_113 ( V_2 , & V_158 , 1 ) ;
if ( error )
goto V_172;
}
F_94 ( V_2 , V_163 ) ;
return 0 ;
V_172:
F_94 ( V_2 , V_177 ) ;
return error ;
}
STATIC int
F_117 (
struct V_1 * V_2 ,
int V_5 ,
int * V_171 )
{
union V_95 V_158 ;
struct V_6 * V_198 ;
struct V_3 * V_122 ;
int V_199 ;
struct V_6 * V_200 ;
struct V_3 * V_123 ;
int V_201 ;
union V_51 V_202 ;
union V_95 * V_203 = NULL ;
union V_51 * V_204 = NULL ;
union V_94 * V_205 = NULL ;
int error ;
F_94 ( V_2 , V_161 ) ;
F_106 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_46 & V_102 ) &&
V_5 == V_2 -> V_67 - 1 )
goto V_174;
V_123 = F_50 ( V_2 , V_5 , & V_200 ) ;
#ifdef F_107
error = F_17 ( V_2 , V_123 , V_5 , V_200 ) ;
if ( error )
goto V_172;
#endif
F_73 ( V_2 , V_123 , & V_202 , V_127 ) ;
if ( F_71 ( V_2 , & V_202 ) )
goto V_174;
if ( V_2 -> V_79 [ V_5 ] <= 1 )
goto V_174;
error = F_86 ( V_2 , & V_202 , 0 , & V_122 , & V_198 ) ;
if ( error )
goto V_172;
V_199 = F_108 ( V_122 ) ;
if ( V_199 == V_2 -> V_23 -> V_24 ( V_2 , V_5 ) )
goto V_174;
V_201 = F_108 ( V_123 ) ;
V_199 ++ ;
V_201 -- ;
F_32 ( V_2 , V_206 ) ;
F_118 ( V_2 , V_207 , 1 ) ;
if ( V_5 > 0 ) {
union V_95 * V_208 ;
union V_51 * V_209 ;
V_208 = F_45 ( V_2 , V_199 , V_122 ) ;
V_203 = F_45 ( V_2 , 1 , V_123 ) ;
V_209 = F_46 ( V_2 , V_199 , V_122 ) ;
V_204 = F_46 ( V_2 , 1 , V_123 ) ;
#ifdef F_107
error = F_21 ( V_2 , V_204 , 0 , V_5 ) ;
if ( error )
goto V_172;
#endif
F_87 ( V_2 , V_208 , V_203 , 1 ) ;
F_89 ( V_2 , V_209 , V_204 , 1 ) ;
F_93 ( V_2 , V_198 , V_199 , V_199 ) ;
F_101 ( V_2 , V_198 , V_199 , V_199 ) ;
ASSERT ( V_2 -> V_23 -> V_210 ( V_2 ,
F_45 ( V_2 , V_199 - 1 , V_122 ) , V_208 ) ) ;
} else {
union V_94 * V_211 ;
V_211 = F_44 ( V_2 , V_199 , V_122 ) ;
V_205 = F_44 ( V_2 , 1 , V_123 ) ;
F_88 ( V_2 , V_211 , V_205 , 1 ) ;
F_100 ( V_2 , V_198 , V_199 , V_199 ) ;
ASSERT ( V_2 -> V_23 -> V_212 ( V_2 ,
F_44 ( V_2 , V_199 - 1 , V_122 ) , V_211 ) ) ;
}
F_119 ( V_122 , V_199 ) ;
F_102 ( V_2 , V_198 , V_213 ) ;
F_119 ( V_123 , V_201 ) ;
F_102 ( V_2 , V_200 , V_213 ) ;
F_118 ( V_2 , V_207 , V_201 - 1 ) ;
if ( V_5 > 0 ) {
#ifdef F_107
int V_66 ;
for ( V_66 = 0 ; V_66 < V_201 ; V_66 ++ ) {
error = F_21 ( V_2 , V_204 , V_66 + 1 , V_5 ) ;
if ( error )
goto V_172;
}
#endif
F_90 ( V_2 ,
F_45 ( V_2 , 2 , V_123 ) ,
- 1 , V_201 ) ;
F_92 ( V_2 ,
F_46 ( V_2 , 2 , V_123 ) ,
- 1 , V_201 ) ;
F_93 ( V_2 , V_200 , 1 , V_201 ) ;
F_101 ( V_2 , V_200 , 1 , V_201 ) ;
} else {
F_91 ( V_2 ,
F_44 ( V_2 , 2 , V_123 ) ,
- 1 , V_201 ) ;
F_100 ( V_2 , V_200 , 1 , V_201 ) ;
V_2 -> V_23 -> V_183 ( & V_158 ,
F_44 ( V_2 , 1 , V_123 ) ) ;
V_203 = & V_158 ;
}
error = F_113 ( V_2 , V_203 , V_5 + 1 ) ;
if ( error )
goto V_172;
V_2 -> V_79 [ V_5 ] -- ;
F_94 ( V_2 , V_163 ) ;
* V_171 = 1 ;
return 0 ;
V_174:
F_94 ( V_2 , V_163 ) ;
* V_171 = 0 ;
return 0 ;
V_172:
F_94 ( V_2 , V_177 ) ;
return error ;
}
STATIC int
F_120 (
struct V_1 * V_2 ,
int V_5 ,
int * V_171 )
{
union V_95 V_158 ;
struct V_6 * V_198 ;
struct V_3 * V_122 ;
struct V_6 * V_200 ;
struct V_3 * V_123 ;
struct V_1 * V_214 ;
union V_51 V_215 ;
union V_95 * V_203 ;
int V_201 ;
int V_199 ;
int error ;
int V_66 ;
F_94 ( V_2 , V_161 ) ;
F_106 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_46 & V_102 ) &&
( V_5 == V_2 -> V_67 - 1 ) )
goto V_174;
V_122 = F_50 ( V_2 , V_5 , & V_198 ) ;
#ifdef F_107
error = F_17 ( V_2 , V_122 , V_5 , V_198 ) ;
if ( error )
goto V_172;
#endif
F_73 ( V_2 , V_122 , & V_215 , V_128 ) ;
if ( F_71 ( V_2 , & V_215 ) )
goto V_174;
V_199 = F_108 ( V_122 ) ;
if ( V_2 -> V_79 [ V_5 ] >= V_199 )
goto V_174;
error = F_86 ( V_2 , & V_215 , 0 , & V_123 , & V_200 ) ;
if ( error )
goto V_172;
V_201 = F_108 ( V_123 ) ;
if ( V_201 == V_2 -> V_23 -> V_24 ( V_2 , V_5 ) )
goto V_174;
F_32 ( V_2 , V_216 ) ;
F_118 ( V_2 , V_207 , V_201 ) ;
if ( V_5 > 0 ) {
union V_95 * V_208 ;
union V_51 * V_209 ;
union V_51 * V_204 ;
V_208 = F_45 ( V_2 , V_199 , V_122 ) ;
V_209 = F_46 ( V_2 , V_199 , V_122 ) ;
V_203 = F_45 ( V_2 , 1 , V_123 ) ;
V_204 = F_46 ( V_2 , 1 , V_123 ) ;
#ifdef F_107
for ( V_66 = V_201 - 1 ; V_66 >= 0 ; V_66 -- ) {
error = F_21 ( V_2 , V_204 , V_66 , V_5 ) ;
if ( error )
goto V_172;
}
#endif
F_90 ( V_2 , V_203 , 1 , V_201 ) ;
F_92 ( V_2 , V_204 , 1 , V_201 ) ;
#ifdef F_107
error = F_21 ( V_2 , V_209 , 0 , V_5 ) ;
if ( error )
goto V_172;
#endif
F_87 ( V_2 , V_203 , V_208 , 1 ) ;
F_89 ( V_2 , V_204 , V_209 , 1 ) ;
F_93 ( V_2 , V_200 , 1 , V_201 + 1 ) ;
F_101 ( V_2 , V_200 , 1 , V_201 + 1 ) ;
ASSERT ( V_2 -> V_23 -> V_210 ( V_2 , V_203 ,
F_45 ( V_2 , 2 , V_123 ) ) ) ;
} else {
union V_94 * V_211 ;
union V_94 * V_205 ;
V_211 = F_44 ( V_2 , V_199 , V_122 ) ;
V_205 = F_44 ( V_2 , 1 , V_123 ) ;
F_91 ( V_2 , V_205 , 1 , V_201 ) ;
F_88 ( V_2 , V_205 , V_211 , 1 ) ;
F_100 ( V_2 , V_200 , 1 , V_201 + 1 ) ;
V_2 -> V_23 -> V_183 ( & V_158 , V_205 ) ;
V_203 = & V_158 ;
ASSERT ( V_2 -> V_23 -> V_212 ( V_2 , V_205 ,
F_44 ( V_2 , 2 , V_123 ) ) ) ;
}
F_119 ( V_122 , -- V_199 ) ;
F_102 ( V_2 , V_198 , V_213 ) ;
F_119 ( V_123 , ++ V_201 ) ;
F_102 ( V_2 , V_200 , V_213 ) ;
error = F_36 ( V_2 , & V_214 ) ;
if ( error )
goto V_172;
V_66 = F_58 ( V_214 , V_5 ) ;
F_121 ( V_2 -> V_11 , V_66 == 1 , V_172 ) ;
error = F_105 ( V_214 , V_5 , & V_66 ) ;
if ( error )
goto V_217;
error = F_113 ( V_214 , V_203 , V_5 + 1 ) ;
if ( error )
goto V_217;
F_33 ( V_214 , V_218 ) ;
F_94 ( V_2 , V_163 ) ;
* V_171 = 1 ;
return 0 ;
V_174:
F_94 ( V_2 , V_163 ) ;
* V_171 = 0 ;
return 0 ;
V_172:
F_94 ( V_2 , V_177 ) ;
return error ;
V_217:
F_94 ( V_214 , V_177 ) ;
F_33 ( V_214 , V_219 ) ;
return error ;
}
STATIC int
F_122 (
struct V_1 * V_2 ,
int V_5 ,
union V_51 * V_176 ,
union V_95 * V_158 ,
struct V_1 * * V_220 ,
int * V_171 )
{
union V_51 V_202 ;
struct V_6 * V_198 ;
struct V_3 * V_122 ;
union V_51 V_215 ;
struct V_6 * V_200 ;
struct V_3 * V_123 ;
union V_51 V_221 ;
struct V_6 * V_222 ;
struct V_3 * V_223 ;
int V_199 ;
int V_201 ;
int V_224 ;
int error ;
#ifdef F_107
int V_66 ;
#endif
F_94 ( V_2 , V_161 ) ;
F_123 ( V_2 , V_5 , * V_176 , V_158 ) ;
F_32 ( V_2 , V_225 ) ;
V_122 = F_50 ( V_2 , V_5 , & V_198 ) ;
#ifdef F_107
error = F_17 ( V_2 , V_122 , V_5 , V_198 ) ;
if ( error )
goto V_172;
#endif
F_81 ( V_2 , V_198 , & V_202 ) ;
error = V_2 -> V_23 -> V_226 ( V_2 , & V_202 , & V_215 , V_171 ) ;
if ( error )
goto V_172;
if ( * V_171 == 0 )
goto V_174;
F_32 ( V_2 , V_227 ) ;
error = F_85 ( V_2 , & V_215 , 0 , & V_123 , & V_200 ) ;
if ( error )
goto V_172;
F_79 ( V_2 , V_200 , F_47 ( V_122 ) , 0 ) ;
V_199 = F_108 ( V_122 ) ;
V_201 = V_199 / 2 ;
if ( ( V_199 & 1 ) && V_2 -> V_79 [ V_5 ] <= V_201 + 1 )
V_201 ++ ;
V_224 = ( V_199 - V_201 + 1 ) ;
F_118 ( V_2 , V_207 , V_201 ) ;
if ( V_5 > 0 ) {
union V_95 * V_208 ;
union V_51 * V_209 ;
union V_95 * V_203 ;
union V_51 * V_204 ;
V_208 = F_45 ( V_2 , V_224 , V_122 ) ;
V_209 = F_46 ( V_2 , V_224 , V_122 ) ;
V_203 = F_45 ( V_2 , 1 , V_123 ) ;
V_204 = F_46 ( V_2 , 1 , V_123 ) ;
#ifdef F_107
for ( V_66 = V_224 ; V_66 < V_201 ; V_66 ++ ) {
error = F_21 ( V_2 , V_209 , V_66 , V_5 ) ;
if ( error )
goto V_172;
}
#endif
F_87 ( V_2 , V_203 , V_208 , V_201 ) ;
F_89 ( V_2 , V_204 , V_209 , V_201 ) ;
F_93 ( V_2 , V_200 , 1 , V_201 ) ;
F_101 ( V_2 , V_200 , 1 , V_201 ) ;
F_87 ( V_2 , V_158 , V_203 , 1 ) ;
} else {
union V_94 * V_211 ;
union V_94 * V_205 ;
V_211 = F_44 ( V_2 , V_224 , V_122 ) ;
V_205 = F_44 ( V_2 , 1 , V_123 ) ;
F_88 ( V_2 , V_205 , V_211 , V_201 ) ;
F_100 ( V_2 , V_200 , 1 , V_201 ) ;
V_2 -> V_23 -> V_183 ( V_158 ,
F_44 ( V_2 , 1 , V_123 ) ) ;
}
F_73 ( V_2 , V_122 , & V_221 , V_128 ) ;
F_74 ( V_2 , V_123 , & V_221 , V_128 ) ;
F_74 ( V_2 , V_123 , & V_202 , V_127 ) ;
F_74 ( V_2 , V_122 , & V_215 , V_128 ) ;
V_199 -= V_201 ;
F_119 ( V_122 , V_199 ) ;
F_119 ( V_123 , F_108 ( V_123 ) + V_201 ) ;
F_102 ( V_2 , V_200 , V_167 ) ;
F_102 ( V_2 , V_198 , V_213 | V_128 ) ;
if ( ! F_71 ( V_2 , & V_221 ) ) {
error = F_86 ( V_2 , & V_221 ,
0 , & V_223 , & V_222 ) ;
if ( error )
goto V_172;
F_74 ( V_2 , V_223 , & V_215 , V_127 ) ;
F_102 ( V_2 , V_222 , V_127 ) ;
}
if ( V_2 -> V_79 [ V_5 ] > V_199 + 1 ) {
F_70 ( V_2 , V_5 , V_200 ) ;
V_2 -> V_79 [ V_5 ] -= V_199 ;
}
if ( V_5 + 1 < V_2 -> V_67 ) {
error = F_36 ( V_2 , V_220 ) ;
if ( error )
goto V_172;
( * V_220 ) -> V_79 [ V_5 + 1 ] ++ ;
}
* V_176 = V_215 ;
F_94 ( V_2 , V_163 ) ;
* V_171 = 1 ;
return 0 ;
V_174:
F_94 ( V_2 , V_163 ) ;
* V_171 = 0 ;
return 0 ;
V_172:
F_94 ( V_2 , V_177 ) ;
return error ;
}
static void
F_124 (
struct V_228 * V_229 )
{
struct V_230 * args = F_125 ( V_229 ,
struct V_230 , V_229 ) ;
unsigned long V_231 ;
unsigned long V_232 = V_233 ;
if ( args -> V_234 )
V_232 |= V_235 | V_236 | V_237 ;
F_126 ( & V_231 , V_232 ) ;
args -> V_238 = F_122 ( args -> V_2 , args -> V_5 , args -> V_176 ,
args -> V_158 , args -> V_220 , args -> V_171 ) ;
F_127 ( args -> V_239 ) ;
F_128 ( & V_231 , V_232 ) ;
}
STATIC int
F_129 (
struct V_1 * V_2 ,
int V_5 ,
union V_51 * V_176 ,
union V_95 * V_158 ,
struct V_1 * * V_220 ,
int * V_171 )
{
struct V_230 args ;
F_130 ( V_239 ) ;
if ( V_2 -> V_69 != V_70 )
return F_122 ( V_2 , V_5 , V_176 , V_158 , V_220 , V_171 ) ;
args . V_2 = V_2 ;
args . V_5 = V_5 ;
args . V_176 = V_176 ;
args . V_158 = V_158 ;
args . V_220 = V_220 ;
args . V_171 = V_171 ;
args . V_239 = & V_239 ;
args . V_234 = F_131 () ;
F_132 ( & args . V_229 , F_124 ) ;
F_133 ( V_240 , & args . V_229 ) ;
F_134 ( & V_239 ) ;
F_135 ( & args . V_229 ) ;
return args . V_238 ;
}
int
F_136 (
struct V_1 * V_2 ,
int * V_241 ,
int * V_171 )
{
struct V_6 * V_242 ;
struct V_3 * V_4 ;
struct V_3 * V_243 ;
union V_95 * V_244 ;
union V_51 * V_245 ;
union V_95 * V_182 ;
union V_51 * V_179 ;
union V_51 V_246 ;
int V_5 ;
int error ;
#ifdef F_107
int V_66 ;
#endif
F_94 ( V_2 , V_161 ) ;
F_32 ( V_2 , V_247 ) ;
ASSERT ( V_2 -> V_46 & V_102 ) ;
V_5 = V_2 -> V_67 - 1 ;
V_4 = F_48 ( V_2 ) ;
V_179 = F_46 ( V_2 , 1 , V_4 ) ;
error = V_2 -> V_23 -> V_226 ( V_2 , V_179 , & V_246 , V_171 ) ;
if ( error )
goto V_172;
if ( * V_171 == 0 ) {
F_94 ( V_2 , V_163 ) ;
return 0 ;
}
F_32 ( V_2 , V_227 ) ;
error = F_85 ( V_2 , & V_246 , 0 , & V_243 , & V_242 ) ;
if ( error )
goto V_172;
memcpy ( V_243 , V_4 , F_39 ( V_2 ) ) ;
if ( V_2 -> V_46 & V_84 ) {
if ( V_2 -> V_46 & V_47 )
V_243 -> V_13 . V_14 . V_17 = F_4 ( V_242 -> V_18 ) ;
else
V_243 -> V_13 . V_42 . V_17 = F_4 ( V_242 -> V_18 ) ;
}
F_137 ( & V_4 -> V_21 , 1 ) ;
F_119 ( V_4 , 1 ) ;
V_2 -> V_67 ++ ;
V_2 -> V_79 [ V_5 + 1 ] = 1 ;
V_182 = F_45 ( V_2 , 1 , V_4 ) ;
V_244 = F_45 ( V_2 , 1 , V_243 ) ;
F_87 ( V_2 , V_244 , V_182 , F_108 ( V_243 ) ) ;
V_245 = F_46 ( V_2 , 1 , V_243 ) ;
#ifdef F_107
for ( V_66 = 0 ; V_66 < F_7 ( V_243 -> V_22 ) ; V_66 ++ ) {
error = F_21 ( V_2 , V_179 , V_66 , V_5 ) ;
if ( error )
goto V_172;
}
#endif
F_89 ( V_2 , V_245 , V_179 , F_108 ( V_243 ) ) ;
#ifdef F_107
error = F_21 ( V_2 , & V_246 , 0 , V_5 ) ;
if ( error )
goto V_172;
#endif
F_89 ( V_2 , V_179 , & V_246 , 1 ) ;
F_138 ( V_2 -> V_39 . V_71 . V_98 ,
1 - F_108 ( V_243 ) ,
V_2 -> V_39 . V_71 . V_99 ) ;
F_70 ( V_2 , V_5 , V_242 ) ;
F_102 ( V_2 , V_242 , V_167 ) ;
F_93 ( V_2 , V_242 , 1 , F_7 ( V_243 -> V_22 ) ) ;
F_101 ( V_2 , V_242 , 1 , F_7 ( V_243 -> V_22 ) ) ;
* V_241 |=
V_248 | F_99 ( V_2 -> V_39 . V_71 . V_99 ) ;
* V_171 = 1 ;
F_94 ( V_2 , V_163 ) ;
return 0 ;
V_172:
F_94 ( V_2 , V_177 ) ;
return error ;
}
STATIC int
F_139 (
struct V_1 * V_2 ,
int * V_171 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int error ;
struct V_6 * V_198 ;
struct V_3 * V_122 ;
struct V_6 * V_249 ;
struct V_3 * V_75 ;
int V_246 ;
struct V_6 * V_200 ;
struct V_3 * V_123 ;
union V_51 V_215 ;
union V_51 V_202 ;
F_94 ( V_2 , V_161 ) ;
F_32 ( V_2 , V_247 ) ;
V_2 -> V_23 -> V_186 ( V_2 , & V_215 ) ;
error = V_2 -> V_23 -> V_226 ( V_2 , & V_215 , & V_202 , V_171 ) ;
if ( error )
goto V_172;
if ( * V_171 == 0 )
goto V_174;
F_32 ( V_2 , V_227 ) ;
error = F_85 ( V_2 , & V_202 , 0 , & V_75 , & V_249 ) ;
if ( error )
goto V_172;
V_2 -> V_23 -> V_250 ( V_2 , & V_202 , 1 ) ;
V_4 = F_50 ( V_2 , V_2 -> V_67 - 1 , & V_7 ) ;
#ifdef F_107
error = F_17 ( V_2 , V_4 , V_2 -> V_67 - 1 , V_7 ) ;
if ( error )
goto V_172;
#endif
F_73 ( V_2 , V_4 , & V_215 , V_128 ) ;
if ( ! F_71 ( V_2 , & V_215 ) ) {
V_198 = V_7 ;
F_81 ( V_2 , V_198 , & V_202 ) ;
V_122 = V_4 ;
error = F_86 ( V_2 , & V_215 , 0 , & V_123 , & V_200 ) ;
if ( error )
goto V_172;
V_7 = V_200 ;
V_246 = 1 ;
} else {
V_200 = V_7 ;
F_81 ( V_2 , V_200 , & V_215 ) ;
V_123 = V_4 ;
F_73 ( V_2 , V_123 , & V_202 , V_127 ) ;
error = F_86 ( V_2 , & V_202 , 0 , & V_122 , & V_198 ) ;
if ( error )
goto V_172;
V_7 = V_198 ;
V_246 = 2 ;
}
F_79 ( V_2 , V_249 , V_2 -> V_67 , 2 ) ;
F_102 ( V_2 , V_249 , V_167 ) ;
ASSERT ( ! F_71 ( V_2 , & V_202 ) &&
! F_71 ( V_2 , & V_215 ) ) ;
if ( F_47 ( V_122 ) > 0 ) {
F_87 ( V_2 ,
F_45 ( V_2 , 1 , V_75 ) ,
F_45 ( V_2 , 1 , V_122 ) , 1 ) ;
F_87 ( V_2 ,
F_45 ( V_2 , 2 , V_75 ) ,
F_45 ( V_2 , 1 , V_123 ) , 1 ) ;
} else {
V_2 -> V_23 -> V_183 (
F_45 ( V_2 , 1 , V_75 ) ,
F_44 ( V_2 , 1 , V_122 ) ) ;
V_2 -> V_23 -> V_183 (
F_45 ( V_2 , 2 , V_75 ) ,
F_44 ( V_2 , 1 , V_123 ) ) ;
}
F_93 ( V_2 , V_249 , 1 , 2 ) ;
F_89 ( V_2 ,
F_46 ( V_2 , 1 , V_75 ) , & V_202 , 1 ) ;
F_89 ( V_2 ,
F_46 ( V_2 , 2 , V_75 ) , & V_215 , 1 ) ;
F_101 ( V_2 , V_249 , 1 , 2 ) ;
F_70 ( V_2 , V_2 -> V_67 , V_249 ) ;
V_2 -> V_79 [ V_2 -> V_67 ] = V_246 ;
V_2 -> V_67 ++ ;
F_94 ( V_2 , V_163 ) ;
* V_171 = 1 ;
return 0 ;
V_172:
F_94 ( V_2 , V_177 ) ;
return error ;
V_174:
F_94 ( V_2 , V_163 ) ;
* V_171 = 0 ;
return 0 ;
}
STATIC int
F_140 (
struct V_1 * V_2 ,
int V_5 ,
int V_132 ,
int * V_251 ,
int * V_53 ,
union V_51 * V_246 ,
struct V_1 * * V_74 ,
union V_94 * V_252 ,
int * V_171 )
{
union V_95 V_158 ;
int error = 0 ;
if ( ( V_2 -> V_46 & V_102 ) &&
V_5 == V_2 -> V_67 - 1 ) {
struct V_253 * V_98 = V_2 -> V_39 . V_71 . V_98 ;
if ( V_132 < V_2 -> V_23 -> V_254 ( V_2 , V_5 ) ) {
F_138 ( V_98 , 1 , V_2 -> V_39 . V_71 . V_99 ) ;
} else {
int V_241 = 0 ;
error = F_136 ( V_2 , & V_241 , V_171 ) ;
if ( error || * V_171 == 0 )
return error ;
F_98 ( V_2 -> V_65 , V_98 , V_241 ) ;
}
return 0 ;
}
error = F_120 ( V_2 , V_5 , V_171 ) ;
if ( error || * V_171 )
return error ;
error = F_117 ( V_2 , V_5 , V_171 ) ;
if ( error )
return error ;
if ( * V_171 ) {
* V_251 = * V_53 = V_2 -> V_79 [ V_5 ] ;
return 0 ;
}
error = F_129 ( V_2 , V_5 , V_246 , & V_158 , V_74 , V_171 ) ;
if ( error || * V_171 == 0 )
return error ;
* V_53 = V_2 -> V_79 [ V_5 ] ;
V_2 -> V_23 -> V_255 ( & V_158 , V_252 ) ;
return 0 ;
}
STATIC int
F_141 (
struct V_1 * V_2 ,
int V_5 ,
union V_51 * V_176 ,
union V_94 * V_256 ,
struct V_1 * * V_220 ,
int * V_171 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_95 V_158 ;
union V_51 V_246 ;
struct V_1 * V_74 ;
union V_94 V_252 ;
int V_257 ;
int V_52 ;
int V_132 ;
int error ;
#ifdef F_107
int V_66 ;
#endif
F_94 ( V_2 , V_161 ) ;
F_142 ( V_2 , V_5 , * V_176 , V_256 ) ;
V_74 = NULL ;
if ( ! ( V_2 -> V_46 & V_102 ) &&
( V_5 >= V_2 -> V_67 ) ) {
error = F_139 ( V_2 , V_171 ) ;
F_72 ( V_2 , V_176 ) ;
F_94 ( V_2 , V_163 ) ;
return error ;
}
V_52 = V_2 -> V_79 [ V_5 ] ;
if ( V_52 == 0 ) {
F_94 ( V_2 , V_163 ) ;
* V_171 = 0 ;
return 0 ;
}
V_2 -> V_23 -> V_183 ( & V_158 , V_256 ) ;
V_257 = V_52 ;
F_32 ( V_2 , V_258 ) ;
V_4 = F_50 ( V_2 , V_5 , & V_7 ) ;
V_132 = F_108 ( V_4 ) ;
#ifdef F_107
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_172;
if ( V_52 <= V_132 ) {
if ( V_5 == 0 ) {
ASSERT ( V_2 -> V_23 -> V_212 ( V_2 , V_256 ,
F_44 ( V_2 , V_52 , V_4 ) ) ) ;
} else {
ASSERT ( V_2 -> V_23 -> V_210 ( V_2 , & V_158 ,
F_45 ( V_2 , V_52 , V_4 ) ) ) ;
}
}
#endif
F_72 ( V_2 , & V_246 ) ;
if ( V_132 == V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ) {
error = F_140 ( V_2 , V_5 , V_132 ,
& V_257 , & V_52 , & V_246 , & V_74 , & V_252 , V_171 ) ;
if ( error || * V_171 == 0 )
goto V_172;
}
V_4 = F_50 ( V_2 , V_5 , & V_7 ) ;
V_132 = F_108 ( V_4 ) ;
#ifdef F_107
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
return error ;
#endif
F_118 ( V_2 , V_207 , V_132 - V_52 + 1 ) ;
if ( V_5 > 0 ) {
union V_95 * V_182 ;
union V_51 * V_179 ;
V_182 = F_45 ( V_2 , V_52 , V_4 ) ;
V_179 = F_46 ( V_2 , V_52 , V_4 ) ;
#ifdef F_107
for ( V_66 = V_132 - V_52 ; V_66 >= 0 ; V_66 -- ) {
error = F_21 ( V_2 , V_179 , V_66 , V_5 ) ;
if ( error )
return error ;
}
#endif
F_90 ( V_2 , V_182 , 1 , V_132 - V_52 + 1 ) ;
F_92 ( V_2 , V_179 , 1 , V_132 - V_52 + 1 ) ;
#ifdef F_107
error = F_21 ( V_2 , V_176 , 0 , V_5 ) ;
if ( error )
goto V_172;
#endif
F_87 ( V_2 , V_182 , & V_158 , 1 ) ;
F_89 ( V_2 , V_179 , V_176 , 1 ) ;
V_132 ++ ;
F_119 ( V_4 , V_132 ) ;
F_101 ( V_2 , V_7 , V_52 , V_132 ) ;
F_93 ( V_2 , V_7 , V_52 , V_132 ) ;
#ifdef F_107
if ( V_52 < V_132 ) {
ASSERT ( V_2 -> V_23 -> V_210 ( V_2 , V_182 ,
F_45 ( V_2 , V_52 + 1 , V_4 ) ) ) ;
}
#endif
} else {
union V_94 * V_195 ;
V_195 = F_44 ( V_2 , V_52 , V_4 ) ;
F_91 ( V_2 , V_195 , 1 , V_132 - V_52 + 1 ) ;
F_88 ( V_2 , V_195 , V_256 , 1 ) ;
F_119 ( V_4 , ++ V_132 ) ;
F_100 ( V_2 , V_7 , V_52 , V_132 ) ;
#ifdef F_107
if ( V_52 < V_132 ) {
ASSERT ( V_2 -> V_23 -> V_212 ( V_2 , V_195 ,
F_44 ( V_2 , V_52 + 1 , V_4 ) ) ) ;
}
#endif
}
F_102 ( V_2 , V_7 , V_213 ) ;
if ( V_257 == 1 ) {
error = F_113 ( V_2 , & V_158 , V_5 + 1 ) ;
if ( error )
goto V_172;
}
if ( F_80 ( V_2 , V_4 , V_5 ) ) {
V_2 -> V_23 -> V_196 ( V_2 , V_4 , V_256 ,
V_52 , V_259 ) ;
}
* V_176 = V_246 ;
if ( ! F_71 ( V_2 , & V_246 ) ) {
* V_256 = V_252 ;
* V_220 = V_74 ;
}
F_94 ( V_2 , V_163 ) ;
* V_171 = 1 ;
return 0 ;
V_172:
F_94 ( V_2 , V_177 ) ;
return error ;
}
int
F_143 (
struct V_1 * V_2 ,
int * V_171 )
{
int error ;
int V_66 ;
int V_5 ;
union V_51 V_246 ;
struct V_1 * V_74 ;
struct V_1 * V_260 ;
union V_94 V_160 ;
V_5 = 0 ;
V_74 = NULL ;
V_260 = V_2 ;
F_72 ( V_2 , & V_246 ) ;
V_2 -> V_23 -> V_261 ( V_2 , & V_160 ) ;
do {
error = F_141 ( V_260 , V_5 , & V_246 , & V_160 , & V_74 , & V_66 ) ;
if ( error ) {
if ( V_260 != V_2 )
F_33 ( V_260 , V_219 ) ;
goto V_172;
}
F_121 ( V_2 -> V_11 , V_66 == 1 , V_172 ) ;
V_5 ++ ;
if ( V_260 != V_2 &&
( V_74 || F_71 ( V_2 , & V_246 ) ) ) {
if ( V_2 -> V_23 -> V_262 )
V_2 -> V_23 -> V_262 ( V_260 , V_2 ) ;
V_2 -> V_67 = V_260 -> V_67 ;
F_33 ( V_260 , V_218 ) ;
}
if ( V_74 ) {
V_260 = V_74 ;
V_74 = NULL ;
}
} while ( ! F_71 ( V_2 , & V_246 ) );
F_94 ( V_2 , V_163 ) ;
* V_171 = V_66 ;
return 0 ;
V_172:
F_94 ( V_2 , V_177 ) ;
return error ;
}
STATIC int
F_144 (
struct V_1 * V_2 )
{
int V_99 = V_2 -> V_39 . V_71 . V_99 ;
struct V_253 * V_98 = V_2 -> V_39 . V_71 . V_98 ;
struct V_96 * V_97 = F_49 ( V_98 , V_99 ) ;
struct V_3 * V_4 ;
struct V_3 * V_243 ;
union V_95 * V_182 ;
union V_95 * V_244 ;
union V_51 * V_179 ;
union V_51 * V_245 ;
struct V_6 * V_242 ;
int V_5 ;
int V_53 ;
int V_132 ;
int error ;
#ifdef F_107
union V_51 V_52 ;
int V_66 ;
#endif
F_94 ( V_2 , V_161 ) ;
ASSERT ( V_2 -> V_46 & V_102 ) ;
ASSERT ( V_2 -> V_67 > 1 ) ;
V_5 = V_2 -> V_67 - 1 ;
if ( V_5 == 1 )
goto V_174;
V_4 = F_48 ( V_2 ) ;
if ( F_108 ( V_4 ) != 1 )
goto V_174;
V_243 = F_50 ( V_2 , V_5 - 1 , & V_242 ) ;
V_132 = F_108 ( V_243 ) ;
if ( V_132 > V_2 -> V_23 -> V_254 ( V_2 , V_5 ) )
goto V_174;
F_32 ( V_2 , V_263 ) ;
#ifdef F_107
F_73 ( V_2 , V_4 , & V_52 , V_127 ) ;
ASSERT ( F_71 ( V_2 , & V_52 ) ) ;
F_73 ( V_2 , V_4 , & V_52 , V_128 ) ;
ASSERT ( F_71 ( V_2 , & V_52 ) ) ;
#endif
V_53 = V_132 - V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ;
if ( V_53 ) {
F_138 ( V_2 -> V_39 . V_71 . V_98 , V_53 ,
V_2 -> V_39 . V_71 . V_99 ) ;
V_4 = V_97 -> V_100 ;
}
F_137 ( & V_4 -> V_22 , V_53 ) ;
ASSERT ( V_4 -> V_22 == V_243 -> V_22 ) ;
V_182 = F_45 ( V_2 , 1 , V_4 ) ;
V_244 = F_45 ( V_2 , 1 , V_243 ) ;
F_87 ( V_2 , V_182 , V_244 , V_132 ) ;
V_179 = F_46 ( V_2 , 1 , V_4 ) ;
V_245 = F_46 ( V_2 , 1 , V_243 ) ;
#ifdef F_107
for ( V_66 = 0 ; V_66 < V_132 ; V_66 ++ ) {
error = F_21 ( V_2 , V_245 , V_66 , V_5 - 1 ) ;
if ( error ) {
F_94 ( V_2 , V_177 ) ;
return error ;
}
}
#endif
F_89 ( V_2 , V_179 , V_245 , V_132 ) ;
error = F_30 ( V_2 , V_242 ) ;
if ( error ) {
F_94 ( V_2 , V_177 ) ;
return error ;
}
V_2 -> V_68 [ V_5 - 1 ] = NULL ;
F_137 ( & V_4 -> V_21 , - 1 ) ;
F_98 ( V_2 -> V_65 , V_98 ,
V_248 | F_99 ( V_2 -> V_39 . V_71 . V_99 ) ) ;
V_2 -> V_67 -- ;
V_174:
F_94 ( V_2 , V_163 ) ;
return 0 ;
}
STATIC int
F_145 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_5 ,
union V_51 * V_247 )
{
int error ;
F_94 ( V_2 , V_161 ) ;
F_32 ( V_2 , V_263 ) ;
V_2 -> V_23 -> V_250 ( V_2 , V_247 , - 1 ) ;
error = F_30 ( V_2 , V_7 ) ;
if ( error ) {
F_94 ( V_2 , V_177 ) ;
return error ;
}
V_2 -> V_68 [ V_5 ] = NULL ;
V_2 -> V_80 [ V_5 ] = 0 ;
V_2 -> V_67 -- ;
F_94 ( V_2 , V_163 ) ;
return 0 ;
}
STATIC int
F_146 (
struct V_1 * V_2 ,
int V_5 ,
int * V_171 )
{
int error ;
int V_66 ;
if ( V_5 > 0 ) {
error = F_109 ( V_2 , V_5 , & V_66 ) ;
if ( error )
return error ;
}
F_94 ( V_2 , V_163 ) ;
* V_171 = 1 ;
return 0 ;
}
STATIC int
F_147 (
struct V_1 * V_2 ,
int V_5 ,
int * V_171 )
{
struct V_3 * V_4 ;
union V_51 V_264 ;
struct V_6 * V_7 ;
int error ;
int V_66 ;
union V_95 V_158 ;
union V_95 * V_194 = & V_158 ;
union V_51 V_202 ;
struct V_6 * V_198 ;
struct V_3 * V_122 ;
int V_199 = 0 ;
int V_52 ;
union V_51 V_215 ;
struct V_6 * V_200 ;
struct V_3 * V_123 ;
struct V_3 * V_223 ;
struct V_6 * V_222 ;
int V_201 = 0 ;
struct V_1 * V_214 ;
int V_132 ;
F_94 ( V_2 , V_161 ) ;
F_106 ( V_2 , V_5 ) ;
V_214 = NULL ;
V_52 = V_2 -> V_79 [ V_5 ] ;
if ( V_52 == 0 ) {
F_94 ( V_2 , V_163 ) ;
* V_171 = 0 ;
return 0 ;
}
V_4 = F_50 ( V_2 , V_5 , & V_7 ) ;
V_132 = F_108 ( V_4 ) ;
#ifdef F_107
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_172;
#endif
if ( V_52 > V_132 ) {
F_94 ( V_2 , V_163 ) ;
* V_171 = 0 ;
return 0 ;
}
F_32 ( V_2 , V_265 ) ;
F_118 ( V_2 , V_207 , V_132 - V_52 ) ;
if ( V_5 > 0 ) {
union V_95 * V_208 ;
union V_51 * V_209 ;
V_208 = F_45 ( V_2 , V_52 + 1 , V_4 ) ;
V_209 = F_46 ( V_2 , V_52 + 1 , V_4 ) ;
#ifdef F_107
for ( V_66 = 0 ; V_66 < V_132 - V_52 ; V_66 ++ ) {
error = F_21 ( V_2 , V_209 , V_66 , V_5 ) ;
if ( error )
goto V_172;
}
#endif
if ( V_52 < V_132 ) {
F_90 ( V_2 , V_208 , - 1 , V_132 - V_52 ) ;
F_92 ( V_2 , V_209 , - 1 , V_132 - V_52 ) ;
F_93 ( V_2 , V_7 , V_52 , V_132 - 1 ) ;
F_101 ( V_2 , V_7 , V_52 , V_132 - 1 ) ;
}
if ( V_52 == 1 )
V_194 = F_45 ( V_2 , 1 , V_4 ) ;
} else {
if ( V_52 < V_132 ) {
F_91 ( V_2 ,
F_44 ( V_2 , V_52 + 1 , V_4 ) ,
- 1 , V_132 - V_52 ) ;
F_100 ( V_2 , V_7 , V_52 , V_132 - 1 ) ;
}
if ( V_52 == 1 ) {
V_2 -> V_23 -> V_183 ( & V_158 ,
F_44 ( V_2 , 1 , V_4 ) ) ;
V_194 = & V_158 ;
}
}
F_119 ( V_4 , -- V_132 ) ;
F_102 ( V_2 , V_7 , V_213 ) ;
if ( F_80 ( V_2 , V_4 , V_5 ) ) {
V_2 -> V_23 -> V_196 ( V_2 , V_4 , NULL ,
V_52 , V_266 ) ;
}
if ( V_5 == V_2 -> V_67 - 1 ) {
if ( V_2 -> V_46 & V_102 ) {
F_138 ( V_2 -> V_39 . V_71 . V_98 , - 1 ,
V_2 -> V_39 . V_71 . V_99 ) ;
error = F_144 ( V_2 ) ;
if ( error )
goto V_172;
error = F_146 ( V_2 , V_5 , V_171 ) ;
if ( error )
goto V_172;
* V_171 = 1 ;
return 0 ;
}
if ( V_132 == 1 && V_5 > 0 ) {
union V_51 * V_179 ;
V_179 = F_46 ( V_2 , 1 , V_4 ) ;
error = F_145 ( V_2 , V_7 , V_5 , V_179 ) ;
if ( error )
goto V_172;
} else if ( V_5 > 0 ) {
error = F_146 ( V_2 , V_5 , V_171 ) ;
if ( error )
goto V_172;
}
* V_171 = 1 ;
return 0 ;
}
if ( V_52 == 1 ) {
error = F_113 ( V_2 , V_194 , V_5 + 1 ) ;
if ( error )
goto V_172;
}
if ( V_132 >= V_2 -> V_23 -> V_267 ( V_2 , V_5 ) ) {
error = F_146 ( V_2 , V_5 , V_171 ) ;
if ( error )
goto V_172;
return 0 ;
}
F_73 ( V_2 , V_4 , & V_215 , V_128 ) ;
F_73 ( V_2 , V_4 , & V_202 , V_127 ) ;
if ( V_2 -> V_46 & V_102 ) {
if ( F_71 ( V_2 , & V_215 ) &&
F_71 ( V_2 , & V_202 ) &&
V_5 == V_2 -> V_67 - 2 ) {
error = F_144 ( V_2 ) ;
if ( ! error )
error = F_146 ( V_2 , V_5 , V_171 ) ;
if ( error )
goto V_172;
return 0 ;
}
}
ASSERT ( ! F_71 ( V_2 , & V_215 ) ||
! F_71 ( V_2 , & V_202 ) ) ;
error = F_36 ( V_2 , & V_214 ) ;
if ( error )
goto V_172;
if ( ! F_71 ( V_2 , & V_215 ) ) {
V_66 = F_58 ( V_214 , V_5 ) ;
F_121 ( V_2 -> V_11 , V_66 == 1 , V_172 ) ;
error = F_105 ( V_214 , V_5 , & V_66 ) ;
if ( error )
goto V_172;
F_121 ( V_2 -> V_11 , V_66 == 1 , V_172 ) ;
V_66 = F_58 ( V_214 , V_5 ) ;
F_121 ( V_2 -> V_11 , V_66 == 1 , V_172 ) ;
V_123 = F_50 ( V_214 , V_5 , & V_200 ) ;
#ifdef F_107
error = F_17 ( V_214 , V_123 , V_5 , V_200 ) ;
if ( error )
goto V_172;
#endif
F_73 ( V_214 , V_123 , & V_264 , V_127 ) ;
if ( F_108 ( V_123 ) - 1 >=
V_2 -> V_23 -> V_267 ( V_214 , V_5 ) ) {
error = F_117 ( V_214 , V_5 , & V_66 ) ;
if ( error )
goto V_172;
if ( V_66 ) {
ASSERT ( F_108 ( V_4 ) >=
V_2 -> V_23 -> V_267 ( V_214 , V_5 ) ) ;
F_33 ( V_214 , V_218 ) ;
V_214 = NULL ;
error = F_146 ( V_2 , V_5 , V_171 ) ;
if ( error )
goto V_172;
return 0 ;
}
}
V_201 = F_108 ( V_123 ) ;
if ( ! F_71 ( V_2 , & V_202 ) ) {
V_66 = F_57 ( V_214 , V_5 ) ;
F_121 ( V_2 -> V_11 , V_66 == 1 , V_172 ) ;
error = F_109 ( V_214 , V_5 , & V_66 ) ;
if ( error )
goto V_172;
F_121 ( V_2 -> V_11 , V_66 == 1 , V_172 ) ;
}
}
if ( ! F_71 ( V_2 , & V_202 ) ) {
V_66 = F_57 ( V_214 , V_5 ) ;
F_121 ( V_2 -> V_11 , V_66 == 1 , V_172 ) ;
error = F_109 ( V_214 , V_5 , & V_66 ) ;
if ( error )
goto V_172;
V_66 = F_57 ( V_214 , V_5 ) ;
F_121 ( V_2 -> V_11 , V_66 == 1 , V_172 ) ;
V_122 = F_50 ( V_214 , V_5 , & V_198 ) ;
#ifdef F_107
error = F_17 ( V_2 , V_122 , V_5 , V_198 ) ;
if ( error )
goto V_172;
#endif
F_73 ( V_214 , V_122 , & V_264 , V_128 ) ;
if ( F_108 ( V_122 ) - 1 >=
V_2 -> V_23 -> V_267 ( V_214 , V_5 ) ) {
error = F_120 ( V_214 , V_5 , & V_66 ) ;
if ( error )
goto V_172;
if ( V_66 ) {
ASSERT ( F_108 ( V_4 ) >=
V_2 -> V_23 -> V_267 ( V_214 , V_5 ) ) ;
F_33 ( V_214 , V_218 ) ;
V_214 = NULL ;
if ( V_5 == 0 )
V_2 -> V_79 [ 0 ] ++ ;
F_94 ( V_2 , V_163 ) ;
* V_171 = 1 ;
return 0 ;
}
}
V_199 = F_108 ( V_122 ) ;
}
F_33 ( V_214 , V_218 ) ;
V_214 = NULL ;
ASSERT ( ! F_71 ( V_2 , & V_264 ) ) ;
if ( ! F_71 ( V_2 , & V_202 ) &&
V_199 + F_108 ( V_4 ) <=
V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ) {
V_215 = V_264 ;
V_123 = V_4 ;
V_200 = V_7 ;
error = F_86 ( V_2 , & V_202 , 0 , & V_122 , & V_198 ) ;
if ( error )
goto V_172;
} else if ( ! F_71 ( V_2 , & V_215 ) &&
V_201 + F_108 ( V_4 ) <=
V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ) {
V_202 = V_264 ;
V_122 = V_4 ;
V_198 = V_7 ;
error = F_86 ( V_2 , & V_215 , 0 , & V_123 , & V_200 ) ;
if ( error )
goto V_172;
} else {
error = F_146 ( V_2 , V_5 , V_171 ) ;
if ( error )
goto V_172;
return 0 ;
}
V_201 = F_108 ( V_123 ) ;
V_199 = F_108 ( V_122 ) ;
F_118 ( V_2 , V_207 , V_201 ) ;
if ( V_5 > 0 ) {
union V_95 * V_208 ;
union V_51 * V_209 ;
union V_95 * V_203 ;
union V_51 * V_204 ;
V_208 = F_45 ( V_2 , V_199 + 1 , V_122 ) ;
V_209 = F_46 ( V_2 , V_199 + 1 , V_122 ) ;
V_203 = F_45 ( V_2 , 1 , V_123 ) ;
V_204 = F_46 ( V_2 , 1 , V_123 ) ;
#ifdef F_107
for ( V_66 = 1 ; V_66 < V_201 ; V_66 ++ ) {
error = F_21 ( V_2 , V_204 , V_66 , V_5 ) ;
if ( error )
goto V_172;
}
#endif
F_87 ( V_2 , V_208 , V_203 , V_201 ) ;
F_89 ( V_2 , V_209 , V_204 , V_201 ) ;
F_93 ( V_2 , V_198 , V_199 + 1 , V_199 + V_201 ) ;
F_101 ( V_2 , V_198 , V_199 + 1 , V_199 + V_201 ) ;
} else {
union V_94 * V_211 ;
union V_94 * V_205 ;
V_211 = F_44 ( V_2 , V_199 + 1 , V_122 ) ;
V_205 = F_44 ( V_2 , 1 , V_123 ) ;
F_88 ( V_2 , V_211 , V_205 , V_201 ) ;
F_100 ( V_2 , V_198 , V_199 + 1 , V_199 + V_201 ) ;
}
F_32 ( V_2 , V_268 ) ;
F_119 ( V_122 , V_199 + V_201 ) ;
F_73 ( V_2 , V_123 , & V_264 , V_128 ) ,
F_74 ( V_2 , V_122 , & V_264 , V_128 ) ;
F_102 ( V_2 , V_198 , V_213 | V_128 ) ;
F_73 ( V_2 , V_122 , & V_264 , V_128 ) ;
if ( ! F_71 ( V_2 , & V_264 ) ) {
error = F_86 ( V_2 , & V_264 , 0 , & V_223 , & V_222 ) ;
if ( error )
goto V_172;
F_74 ( V_2 , V_223 , & V_202 , V_127 ) ;
F_102 ( V_2 , V_222 , V_127 ) ;
}
error = F_30 ( V_2 , V_200 ) ;
if ( error )
goto V_172;
if ( V_7 != V_198 ) {
V_2 -> V_68 [ V_5 ] = V_198 ;
V_2 -> V_79 [ V_5 ] += V_199 ;
V_2 -> V_80 [ V_5 ] = 0 ;
}
else if ( ( V_2 -> V_46 & V_102 ) ||
( V_5 + 1 < V_2 -> V_67 ) ) {
error = F_105 ( V_2 , V_5 + 1 , & V_66 ) ;
if ( error )
goto V_172;
}
if ( V_5 > 0 )
V_2 -> V_79 [ V_5 ] -- ;
F_94 ( V_2 , V_163 ) ;
* V_171 = 2 ;
return 0 ;
V_172:
F_94 ( V_2 , V_177 ) ;
if ( V_214 )
F_33 ( V_214 , V_219 ) ;
return error ;
}
int
F_148 (
struct V_1 * V_2 ,
int * V_171 )
{
int error ;
int V_5 ;
int V_66 ;
F_94 ( V_2 , V_161 ) ;
for ( V_5 = 0 , V_66 = 2 ; V_66 == 2 ; V_5 ++ ) {
error = F_147 ( V_2 , V_5 , & V_66 ) ;
if ( error )
goto V_172;
}
if ( V_66 == 0 ) {
for ( V_5 = 1 ; V_5 < V_2 -> V_67 ; V_5 ++ ) {
if ( V_2 -> V_79 [ V_5 ] == 0 ) {
error = F_109 ( V_2 , V_5 , & V_66 ) ;
if ( error )
goto V_172;
break;
}
}
}
F_94 ( V_2 , V_163 ) ;
* V_171 = V_66 ;
return 0 ;
V_172:
F_94 ( V_2 , V_177 ) ;
return error ;
}
int
F_149 (
struct V_1 * V_2 ,
union V_94 * * V_256 ,
int * V_171 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int V_52 ;
#ifdef F_107
int error ;
#endif
V_52 = V_2 -> V_79 [ 0 ] ;
V_4 = F_50 ( V_2 , 0 , & V_7 ) ;
#ifdef F_107
error = F_17 ( V_2 , V_4 , 0 , V_7 ) ;
if ( error )
return error ;
#endif
if ( V_52 > F_108 ( V_4 ) || V_52 <= 0 ) {
* V_171 = 0 ;
return 0 ;
}
* V_256 = F_44 ( V_2 , V_52 , V_4 ) ;
* V_171 = 1 ;
return 0 ;
}
static int
F_150 (
struct V_1 * V_2 ,
int V_5 ,
T_17 V_269 ,
struct V_270 * V_271 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_51 V_215 ;
F_67 ( V_2 , V_5 , V_125 ) ;
V_4 = F_50 ( V_2 , V_5 , & V_7 ) ;
if ( V_2 -> V_46 & V_47 )
V_4 -> V_13 . V_14 . V_135 = F_4 ( V_269 ) ;
else
V_4 -> V_13 . V_42 . V_135 = F_16 ( V_269 ) ;
if ( V_7 ) {
if ( V_2 -> V_65 ) {
F_151 ( V_2 -> V_65 , V_7 ) ;
F_102 ( V_2 , V_7 , V_272 ) ;
} else {
F_152 ( V_7 , V_271 ) ;
}
} else {
ASSERT ( V_2 -> V_46 & V_102 ) ;
ASSERT ( V_5 == V_2 -> V_67 - 1 ) ;
}
F_73 ( V_2 , V_4 , & V_215 , V_128 ) ;
if ( F_71 ( V_2 , & V_215 ) )
return - V_273 ;
return F_110 ( V_2 , V_5 , & V_215 , & V_4 ) ;
}
int
F_153 (
struct V_1 * V_2 ,
T_17 V_269 ,
struct V_270 * V_271 )
{
union V_51 V_202 ;
int V_5 ;
struct V_3 * V_4 = NULL ;
int error = 0 ;
V_2 -> V_23 -> V_186 ( V_2 , & V_202 ) ;
for ( V_5 = V_2 -> V_67 - 1 ; V_5 >= 0 ; V_5 -- ) {
error = F_110 ( V_2 , V_5 , & V_202 , & V_4 ) ;
if ( error )
return error ;
if ( V_5 > 0 ) {
union V_51 * V_52 ;
V_52 = F_46 ( V_2 , 1 , V_4 ) ;
F_69 ( V_2 , V_52 , 1 ) ;
V_202 = * V_52 ;
}
do {
error = F_150 ( V_2 , V_5 ,
V_269 ,
V_271 ) ;
} while ( ! error );
if ( error != - V_273 )
return error ;
}
return 0 ;
}
bool
F_154 (
struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_57 -> V_58 ;
struct V_3 * V_4 = F_23 ( V_7 ) ;
struct V_274 * V_275 = V_7 -> V_276 ;
if ( ! F_2 ( & V_10 -> V_12 ) )
return false ;
if ( ! F_3 ( & V_4 -> V_13 . V_42 . V_15 , & V_10 -> V_12 . V_16 ) )
return false ;
if ( V_4 -> V_13 . V_42 . V_17 != F_4 ( V_7 -> V_18 ) )
return false ;
if ( V_275 && F_5 ( V_4 -> V_13 . V_42 . V_135 ) != V_275 -> V_277 )
return false ;
return true ;
}
bool
F_155 (
struct V_6 * V_7 ,
unsigned int V_278 )
{
struct V_9 * V_10 = V_7 -> V_57 -> V_58 ;
struct V_3 * V_4 = F_23 ( V_7 ) ;
if ( F_7 ( V_4 -> V_22 ) > V_278 )
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
