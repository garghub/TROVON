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
V_33 ) ) ) {
if ( V_11 )
F_12 ( V_11 , V_34 ) ;
F_13 ( V_35 , V_36 , V_14 ) ;
return - V_37 ;
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
struct V_10 * V_38 ;
struct V_39 * V_40 ;
T_3 V_41 ;
int V_42 = 1 ;
T_2 V_2 = V_6 -> V_15 ;
int V_1 ;
V_14 = V_6 -> V_16 ;
V_1 = F_3 ( & V_14 -> V_17 ) ;
V_38 = V_6 -> V_43 . V_44 . V_38 ;
V_40 = F_15 ( V_38 ) ;
V_41 = F_6 ( V_40 -> V_45 ) ;
if ( V_1 ) {
V_42 = V_42 &&
F_4 ( & V_8 -> V_18 . V_46 . V_20 ,
& V_14 -> V_17 . V_21 ) &&
V_8 -> V_18 . V_46 . V_22 == F_5 (
V_11 ? V_11 -> V_23 : V_24 ) ;
}
V_42 = V_42 &&
F_6 ( V_8 -> V_25 ) == F_1 ( V_1 , V_2 ) &&
F_7 ( V_8 -> V_26 ) == V_9 &&
F_7 ( V_8 -> V_27 ) <=
V_6 -> V_28 -> V_29 ( V_6 , V_9 ) &&
( V_8 -> V_18 . V_46 . V_30 == F_16 ( V_47 ) ||
F_6 ( V_8 -> V_18 . V_46 . V_30 ) < V_41 ) &&
V_8 -> V_18 . V_46 . V_30 &&
( V_8 -> V_18 . V_46 . V_32 == F_16 ( V_47 ) ||
F_6 ( V_8 -> V_18 . V_46 . V_32 ) < V_41 ) &&
V_8 -> V_18 . V_46 . V_32 ;
if ( F_10 ( F_11 ( ! V_42 , V_14 ,
V_48 ) ) ) {
if ( V_11 )
F_12 ( V_11 , V_34 ) ;
F_13 ( V_35 , V_36 , V_14 ) ;
return - V_37 ;
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
if ( V_6 -> V_49 & V_50 )
return F_2 ( V_6 , V_8 , V_9 , V_11 ) ;
else
return F_14 ( V_6 , V_8 , V_9 , V_11 ) ;
}
int
F_18 (
struct V_5 * V_6 ,
T_4 V_51 ,
int V_9 )
{
F_19 ( V_6 -> V_16 ,
V_9 > 0 &&
V_51 != V_31 &&
F_8 ( V_6 -> V_16 , V_51 ) ) ;
return 0 ;
}
STATIC int
F_20 (
struct V_5 * V_6 ,
T_3 V_51 ,
int V_9 )
{
T_3 V_52 = V_6 -> V_16 -> V_17 . V_53 ;
F_19 ( V_6 -> V_16 ,
V_9 > 0 &&
V_51 != V_47 &&
V_51 != 0 &&
V_51 < V_52 ) ;
return 0 ;
}
STATIC int
F_21 (
struct V_5 * V_6 ,
union V_54 * V_55 ,
int V_56 ,
int V_9 )
{
if ( V_6 -> V_49 & V_50 ) {
return F_18 ( V_6 ,
F_9 ( ( & V_55 -> V_19 ) [ V_56 ] ) , V_9 ) ;
} else {
return F_20 ( V_6 ,
F_6 ( ( & V_55 -> V_46 ) [ V_56 ] ) , V_9 ) ;
}
}
void
F_22 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_23 ( V_11 ) ;
struct V_57 * V_58 = V_11 -> V_59 ;
if ( ! F_3 ( & V_11 -> V_60 -> V_61 -> V_17 ) )
return;
if ( V_58 )
V_8 -> V_18 . V_19 . V_62 = F_5 ( V_58 -> V_63 . V_64 ) ;
F_24 ( V_11 , V_65 ) ;
}
bool
F_25 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_23 ( V_11 ) ;
struct V_13 * V_14 = V_11 -> V_60 -> V_61 ;
if ( F_3 ( & V_14 -> V_17 ) ) {
if ( ! F_26 ( V_14 , F_9 ( V_8 -> V_18 . V_19 . V_62 ) ) )
return false ;
return F_27 ( V_11 , V_65 ) ;
}
return true ;
}
void
F_28 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_23 ( V_11 ) ;
struct V_57 * V_58 = V_11 -> V_59 ;
if ( ! F_3 ( & V_11 -> V_60 -> V_61 -> V_17 ) )
return;
if ( V_58 )
V_8 -> V_18 . V_46 . V_62 = F_5 ( V_58 -> V_63 . V_64 ) ;
F_24 ( V_11 , V_66 ) ;
}
bool
F_29 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_23 ( V_11 ) ;
struct V_13 * V_14 = V_11 -> V_60 -> V_61 ;
if ( F_3 ( & V_14 -> V_17 ) ) {
if ( ! F_26 ( V_14 , F_9 ( V_8 -> V_18 . V_46 . V_62 ) ) )
return false ;
return F_27 ( V_11 , V_66 ) ;
}
return true ;
}
static int
F_30 (
struct V_5 * V_6 ,
struct V_10 * V_11 )
{
int error ;
error = V_6 -> V_28 -> V_67 ( V_6 , V_11 ) ;
if ( ! error ) {
F_31 ( V_6 -> V_68 , V_11 ) ;
F_32 ( V_6 , free ) ;
}
return error ;
}
void
F_33 (
T_5 * V_6 ,
int error )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_6 -> V_70 ; V_69 ++ ) {
if ( V_6 -> V_71 [ V_69 ] )
F_34 ( V_6 -> V_68 , V_6 -> V_71 [ V_69 ] ) ;
else if ( ! error )
break;
}
ASSERT ( V_6 -> V_15 != V_72 ||
V_6 -> V_43 . V_73 . V_74 == 0 ) ;
F_35 ( V_75 , V_6 ) ;
}
int
F_36 (
T_5 * V_6 ,
T_5 * * V_76 )
{
T_6 * V_11 ;
int error ;
int V_69 ;
T_7 * V_14 ;
T_5 * V_77 ;
T_8 * V_78 ;
V_78 = V_6 -> V_68 ;
V_14 = V_6 -> V_16 ;
V_77 = V_6 -> V_28 -> V_79 ( V_6 ) ;
V_77 -> V_80 = V_6 -> V_80 ;
for ( V_69 = 0 ; V_69 < V_77 -> V_70 ; V_69 ++ ) {
V_77 -> V_81 [ V_69 ] = V_6 -> V_81 [ V_69 ] ;
V_77 -> V_82 [ V_69 ] = V_6 -> V_82 [ V_69 ] ;
V_11 = V_6 -> V_71 [ V_69 ] ;
if ( V_11 ) {
error = F_37 ( V_14 , V_78 , V_14 -> V_83 ,
F_38 ( V_11 ) , V_14 -> V_84 ,
0 , & V_11 ,
V_6 -> V_28 -> V_85 ) ;
if ( error ) {
F_33 ( V_77 , error ) ;
* V_76 = NULL ;
return error ;
}
}
V_77 -> V_71 [ V_69 ] = V_11 ;
}
* V_76 = V_77 ;
return 0 ;
}
static inline T_9 F_39 ( struct V_5 * V_6 )
{
if ( V_6 -> V_49 & V_50 ) {
if ( V_6 -> V_49 & V_86 )
return V_87 ;
return V_88 ;
}
if ( V_6 -> V_49 & V_86 )
return V_89 ;
return V_90 ;
}
static inline T_9 F_40 ( struct V_5 * V_6 )
{
return ( V_6 -> V_49 & V_50 ) ?
sizeof( V_91 ) : sizeof( V_92 ) ;
}
STATIC T_9
F_41 (
struct V_5 * V_6 ,
int V_93 )
{
return F_39 ( V_6 ) +
( V_93 - 1 ) * V_6 -> V_28 -> V_94 ;
}
STATIC T_9
F_42 (
struct V_5 * V_6 ,
int V_93 )
{
return F_39 ( V_6 ) +
( V_93 - 1 ) * V_6 -> V_28 -> V_95 ;
}
STATIC T_9
F_43 (
struct V_5 * V_6 ,
int V_93 )
{
return F_39 ( V_6 ) +
( V_93 - 1 ) * V_6 -> V_28 -> V_95 + ( V_6 -> V_28 -> V_95 / 2 ) ;
}
STATIC T_9
F_44 (
struct V_5 * V_6 ,
int V_93 ,
int V_9 )
{
return F_39 ( V_6 ) +
V_6 -> V_28 -> V_29 ( V_6 , V_9 ) * V_6 -> V_28 -> V_95 +
( V_93 - 1 ) * F_40 ( V_6 ) ;
}
union V_96 *
F_45 (
struct V_5 * V_6 ,
int V_93 ,
struct V_7 * V_8 )
{
return (union V_96 * )
( ( char * ) V_8 + F_41 ( V_6 , V_93 ) ) ;
}
union V_97 *
F_46 (
struct V_5 * V_6 ,
int V_93 ,
struct V_7 * V_8 )
{
return (union V_97 * )
( ( char * ) V_8 + F_42 ( V_6 , V_93 ) ) ;
}
union V_97 *
F_47 (
struct V_5 * V_6 ,
int V_93 ,
struct V_7 * V_8 )
{
return (union V_97 * )
( ( char * ) V_8 + F_43 ( V_6 , V_93 ) ) ;
}
union V_54 *
F_48 (
struct V_5 * V_6 ,
int V_93 ,
struct V_7 * V_8 )
{
int V_9 = F_49 ( V_8 ) ;
ASSERT ( V_8 -> V_26 != 0 ) ;
return (union V_54 * )
( ( char * ) V_8 + F_44 ( V_6 , V_93 , V_9 ) ) ;
}
STATIC struct V_7 *
F_50 (
struct V_5 * V_6 )
{
struct V_98 * V_99 ;
V_99 = F_51 ( V_6 -> V_43 . V_73 . V_100 , V_6 -> V_43 . V_73 . V_101 ) ;
return (struct V_7 * ) V_99 -> V_102 ;
}
struct V_7 *
F_52 (
struct V_5 * V_6 ,
int V_9 ,
struct V_10 * * V_103 )
{
if ( ( V_6 -> V_49 & V_104 ) &&
( V_9 == V_6 -> V_70 - 1 ) ) {
* V_103 = NULL ;
return F_50 ( V_6 ) ;
}
* V_103 = V_6 -> V_71 [ V_9 ] ;
return F_23 ( * V_103 ) ;
}
T_6 *
F_53 (
T_7 * V_14 ,
T_8 * V_78 ,
T_4 V_105 ,
T_10 V_106 )
{
T_11 V_107 ;
ASSERT ( V_105 != V_31 ) ;
V_107 = F_54 ( V_14 , V_105 ) ;
return F_55 ( V_78 , V_14 -> V_83 , V_107 , V_14 -> V_84 , V_106 ) ;
}
T_6 *
F_56 (
T_7 * V_14 ,
T_8 * V_78 ,
T_12 V_108 ,
T_3 V_109 ,
T_10 V_106 )
{
T_11 V_107 ;
ASSERT ( V_108 != V_110 ) ;
ASSERT ( V_109 != V_47 ) ;
V_107 = F_57 ( V_14 , V_108 , V_109 ) ;
return F_55 ( V_78 , V_14 -> V_83 , V_107 , V_14 -> V_84 , V_106 ) ;
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
if ( V_6 -> V_49 & V_50 )
return V_8 -> V_18 . V_19 . V_32 == F_5 ( V_31 ) ;
else
return V_8 -> V_18 . V_46 . V_32 == F_16 ( V_47 ) ;
}
STATIC int
F_59 (
T_5 * V_6 ,
int V_9 )
{
struct V_7 * V_8 ;
T_6 * V_11 ;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
if ( F_17 ( V_6 , V_8 , V_9 , V_11 ) )
return 0 ;
if ( ! V_8 -> V_27 )
return 0 ;
V_6 -> V_81 [ V_9 ] = 1 ;
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
if ( F_17 ( V_6 , V_8 , V_9 , V_11 ) )
return 0 ;
if ( ! V_8 -> V_27 )
return 0 ;
V_6 -> V_81 [ V_9 ] = F_7 ( V_8 -> V_27 ) ;
return 1 ;
}
void
F_61 (
T_13 V_111 ,
const short * V_112 ,
int V_113 ,
int * V_114 ,
int * V_115 )
{
int V_69 ;
T_13 V_116 ;
ASSERT ( V_111 != 0 ) ;
for ( V_69 = 0 , V_116 = 1LL ; ; V_69 ++ , V_116 <<= 1 ) {
if ( V_116 & V_111 ) {
* V_114 = V_112 [ V_69 ] ;
break;
}
}
for ( V_69 = V_113 - 1 , V_116 = 1LL << V_69 ; ; V_69 -- , V_116 >>= 1 ) {
if ( V_116 & V_111 ) {
* V_115 = V_112 [ V_69 + 1 ] - 1 ;
break;
}
}
}
int
F_62 (
struct V_13 * V_14 ,
struct V_117 * V_78 ,
T_4 V_105 ,
T_10 V_106 ,
struct V_10 * * V_103 ,
int V_118 ,
const struct V_119 * V_120 )
{
struct V_10 * V_11 ;
T_11 V_107 ;
int error ;
if ( ! F_8 ( V_14 , V_105 ) )
return - V_37 ;
V_107 = F_54 ( V_14 , V_105 ) ;
error = F_37 ( V_14 , V_78 , V_14 -> V_83 , V_107 ,
V_14 -> V_84 , V_106 , & V_11 , V_120 ) ;
if ( error )
return error ;
if ( V_11 )
F_63 ( V_11 , V_118 ) ;
* V_103 = V_11 ;
return 0 ;
}
void
F_64 (
struct V_13 * V_14 ,
T_4 V_105 ,
T_14 V_121 ,
const struct V_119 * V_120 )
{
T_11 V_107 ;
ASSERT ( V_105 != V_31 ) ;
V_107 = F_54 ( V_14 , V_105 ) ;
F_65 ( V_14 -> V_83 , V_107 , V_14 -> V_84 * V_121 , V_120 ) ;
}
void
F_66 (
struct V_13 * V_14 ,
T_12 V_108 ,
T_3 V_109 ,
T_14 V_121 ,
const struct V_119 * V_120 )
{
T_11 V_107 ;
ASSERT ( V_108 != V_110 ) ;
ASSERT ( V_109 != V_47 ) ;
V_107 = F_57 ( V_14 , V_108 , V_109 ) ;
F_65 ( V_14 -> V_83 , V_107 , V_14 -> V_84 * V_121 , V_120 ) ;
}
STATIC int
F_67 (
struct V_5 * V_6 ,
int V_122 ,
struct V_7 * V_8 )
{
int V_123 = 0 ;
T_4 V_124 = F_9 ( V_8 -> V_18 . V_19 . V_30 ) ;
T_4 V_125 = F_9 ( V_8 -> V_18 . V_19 . V_32 ) ;
if ( ( V_122 & V_126 ) && V_124 != V_31 ) {
F_64 ( V_6 -> V_16 , V_124 , 1 ,
V_6 -> V_28 -> V_85 ) ;
V_123 ++ ;
}
if ( ( V_122 & V_127 ) && V_125 != V_31 ) {
F_64 ( V_6 -> V_16 , V_125 , 1 ,
V_6 -> V_28 -> V_85 ) ;
V_123 ++ ;
}
return V_123 ;
}
STATIC int
F_68 (
struct V_5 * V_6 ,
int V_122 ,
struct V_7 * V_8 )
{
int V_123 = 0 ;
T_3 V_124 = F_6 ( V_8 -> V_18 . V_46 . V_30 ) ;
T_3 V_125 = F_6 ( V_8 -> V_18 . V_46 . V_32 ) ;
if ( ( V_122 & V_126 ) && V_124 != V_47 ) {
F_66 ( V_6 -> V_16 , V_6 -> V_43 . V_44 . V_108 ,
V_124 , 1 , V_6 -> V_28 -> V_85 ) ;
V_123 ++ ;
}
if ( ( V_122 & V_127 ) && V_125 != V_47 ) {
F_66 ( V_6 -> V_16 , V_6 -> V_43 . V_44 . V_108 ,
V_125 , 1 , V_6 -> V_28 -> V_85 ) ;
V_123 ++ ;
}
return V_123 ;
}
STATIC int
F_69 (
struct V_5 * V_6 ,
int V_128 ,
int V_122 )
{
struct V_7 * V_8 ;
if ( ( V_6 -> V_49 & V_104 ) &&
( V_128 == V_6 -> V_70 - 1 ) )
return 0 ;
if ( ( V_6 -> V_82 [ V_128 ] | V_122 ) == V_6 -> V_82 [ V_128 ] )
return 0 ;
V_6 -> V_82 [ V_128 ] |= V_122 ;
V_8 = F_23 ( V_6 -> V_71 [ V_128 ] ) ;
if ( V_6 -> V_49 & V_50 )
return F_67 ( V_6 , V_122 , V_8 ) ;
return F_68 ( V_6 , V_122 , V_8 ) ;
}
STATIC T_11
F_70 (
struct V_5 * V_6 ,
union V_54 * V_55 )
{
if ( V_6 -> V_49 & V_50 ) {
ASSERT ( V_55 -> V_19 != F_5 ( V_31 ) ) ;
return F_54 ( V_6 -> V_16 , F_9 ( V_55 -> V_19 ) ) ;
} else {
ASSERT ( V_6 -> V_43 . V_44 . V_108 != V_110 ) ;
ASSERT ( V_55 -> V_46 != F_16 ( V_47 ) ) ;
return F_57 ( V_6 -> V_16 , V_6 -> V_43 . V_44 . V_108 ,
F_6 ( V_55 -> V_46 ) ) ;
}
}
STATIC void
F_71 (
struct V_5 * V_6 ,
union V_54 * V_55 ,
T_14 V_121 )
{
F_65 ( V_6 -> V_16 -> V_83 ,
F_70 ( V_6 , V_55 ) ,
V_6 -> V_16 -> V_84 * V_121 , V_6 -> V_28 -> V_85 ) ;
}
STATIC void
F_72 (
T_5 * V_6 ,
int V_128 ,
T_6 * V_11 )
{
struct V_7 * V_73 ;
if ( V_6 -> V_71 [ V_128 ] )
F_34 ( V_6 -> V_68 , V_6 -> V_71 [ V_128 ] ) ;
V_6 -> V_71 [ V_128 ] = V_11 ;
V_6 -> V_82 [ V_128 ] = 0 ;
V_73 = F_23 ( V_11 ) ;
if ( V_6 -> V_49 & V_50 ) {
if ( V_73 -> V_18 . V_19 . V_30 == F_5 ( V_31 ) )
V_6 -> V_82 [ V_128 ] |= V_126 ;
if ( V_73 -> V_18 . V_19 . V_32 == F_5 ( V_31 ) )
V_6 -> V_82 [ V_128 ] |= V_127 ;
} else {
if ( V_73 -> V_18 . V_46 . V_30 == F_16 ( V_47 ) )
V_6 -> V_82 [ V_128 ] |= V_126 ;
if ( V_73 -> V_18 . V_46 . V_32 == F_16 ( V_47 ) )
V_6 -> V_82 [ V_128 ] |= V_127 ;
}
}
STATIC int
F_73 (
struct V_5 * V_6 ,
union V_54 * V_55 )
{
if ( V_6 -> V_49 & V_50 )
return V_55 -> V_19 == F_5 ( V_31 ) ;
else
return V_55 -> V_46 == F_16 ( V_47 ) ;
}
STATIC void
F_74 (
struct V_5 * V_6 ,
union V_54 * V_55 )
{
if ( V_6 -> V_49 & V_50 )
V_55 -> V_19 = F_5 ( V_31 ) ;
else
V_55 -> V_46 = F_16 ( V_47 ) ;
}
STATIC void
F_75 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
union V_54 * V_55 ,
int V_122 )
{
ASSERT ( V_122 == V_129 || V_122 == V_130 ) ;
if ( V_6 -> V_49 & V_50 ) {
if ( V_122 == V_130 )
V_55 -> V_19 = V_8 -> V_18 . V_19 . V_32 ;
else
V_55 -> V_19 = V_8 -> V_18 . V_19 . V_30 ;
} else {
if ( V_122 == V_130 )
V_55 -> V_46 = V_8 -> V_18 . V_46 . V_32 ;
else
V_55 -> V_46 = V_8 -> V_18 . V_46 . V_30 ;
}
}
STATIC void
F_76 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
union V_54 * V_55 ,
int V_122 )
{
ASSERT ( V_122 == V_129 || V_122 == V_130 ) ;
if ( V_6 -> V_49 & V_50 ) {
if ( V_122 == V_130 )
V_8 -> V_18 . V_19 . V_32 = V_55 -> V_19 ;
else
V_8 -> V_18 . V_19 . V_30 = V_55 -> V_19 ;
} else {
if ( V_122 == V_130 )
V_8 -> V_18 . V_46 . V_32 = V_55 -> V_46 ;
else
V_8 -> V_18 . V_46 . V_30 = V_55 -> V_46 ;
}
}
void
F_77 (
struct V_13 * V_14 ,
struct V_7 * V_131 ,
T_11 V_132 ,
T_2 V_2 ,
T_15 V_9 ,
T_15 V_133 ,
T_16 V_134 ,
unsigned int V_135 )
{
int V_1 = F_3 ( & V_14 -> V_17 ) ;
T_17 V_3 = F_1 ( V_1 , V_2 ) ;
V_131 -> V_25 = F_16 ( V_3 ) ;
V_131 -> V_26 = F_78 ( V_9 ) ;
V_131 -> V_27 = F_78 ( V_133 ) ;
if ( V_135 & V_50 ) {
V_131 -> V_18 . V_19 . V_30 = F_5 ( V_31 ) ;
V_131 -> V_18 . V_19 . V_32 = F_5 ( V_31 ) ;
if ( V_1 ) {
V_131 -> V_18 . V_19 . V_22 = F_5 ( V_132 ) ;
V_131 -> V_18 . V_19 . V_136 = F_5 ( V_134 ) ;
F_79 ( & V_131 -> V_18 . V_19 . V_20 , & V_14 -> V_17 . V_21 ) ;
V_131 -> V_18 . V_19 . V_137 = 0 ;
V_131 -> V_18 . V_19 . V_62 = 0 ;
}
} else {
T_17 V_138 = ( T_17 ) V_134 ;
V_131 -> V_18 . V_46 . V_30 = F_16 ( V_47 ) ;
V_131 -> V_18 . V_46 . V_32 = F_16 ( V_47 ) ;
if ( V_1 ) {
V_131 -> V_18 . V_46 . V_22 = F_5 ( V_132 ) ;
V_131 -> V_18 . V_46 . V_136 = F_16 ( V_138 ) ;
F_79 ( & V_131 -> V_18 . V_46 . V_20 , & V_14 -> V_17 . V_21 ) ;
V_131 -> V_18 . V_46 . V_62 = 0 ;
}
}
}
void
F_80 (
struct V_13 * V_14 ,
struct V_10 * V_11 ,
T_2 V_2 ,
T_15 V_9 ,
T_15 V_133 ,
T_16 V_134 ,
unsigned int V_135 )
{
F_77 ( V_14 , F_23 ( V_11 ) , V_11 -> V_23 ,
V_2 , V_9 , V_133 , V_134 , V_135 ) ;
}
STATIC void
F_81 (
struct V_5 * V_6 ,
struct V_10 * V_11 ,
int V_9 ,
int V_133 )
{
T_16 V_134 ;
if ( V_6 -> V_49 & V_50 )
V_134 = V_6 -> V_43 . V_73 . V_100 -> V_139 ;
else
V_134 = V_6 -> V_43 . V_44 . V_108 ;
F_77 ( V_6 -> V_16 , F_23 ( V_11 ) , V_11 -> V_23 ,
V_6 -> V_15 , V_9 , V_133 ,
V_134 , V_6 -> V_49 ) ;
}
STATIC int
F_82 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_9 )
{
union V_54 V_55 ;
if ( V_9 > 0 )
return 0 ;
if ( ! ( V_6 -> V_49 & V_140 ) )
return 0 ;
F_75 ( V_6 , V_8 , & V_55 , V_130 ) ;
if ( ! F_73 ( V_6 , & V_55 ) )
return 0 ;
return 1 ;
}
STATIC void
F_83 (
struct V_5 * V_6 ,
struct V_10 * V_11 ,
union V_54 * V_55 )
{
if ( V_6 -> V_49 & V_50 )
V_55 -> V_19 = F_5 ( F_84 ( V_6 -> V_16 ,
F_38 ( V_11 ) ) ) ;
else {
V_55 -> V_46 = F_16 ( F_85 ( V_6 -> V_16 ,
F_38 ( V_11 ) ) ) ;
}
}
STATIC void
F_86 (
struct V_5 * V_6 ,
struct V_10 * V_11 )
{
switch ( V_6 -> V_15 ) {
case V_141 :
case V_142 :
F_63 ( V_11 , V_143 ) ;
break;
case V_144 :
case V_145 :
F_63 ( V_11 , V_146 ) ;
break;
case V_72 :
F_63 ( V_11 , V_147 ) ;
break;
case V_148 :
F_63 ( V_11 , V_149 ) ;
break;
case V_150 :
F_63 ( V_11 , V_151 ) ;
break;
default:
ASSERT ( 0 ) ;
}
}
STATIC int
F_87 (
struct V_5 * V_6 ,
union V_54 * V_55 ,
int V_135 ,
struct V_7 * * V_8 ,
struct V_10 * * V_103 )
{
struct V_13 * V_14 = V_6 -> V_16 ;
T_11 V_107 ;
ASSERT ( ! ( V_135 & V_152 ) ) ;
V_107 = F_70 ( V_6 , V_55 ) ;
* V_103 = F_55 ( V_6 -> V_68 , V_14 -> V_83 , V_107 ,
V_14 -> V_84 , V_135 ) ;
if ( ! * V_103 )
return - V_153 ;
( * V_103 ) -> V_154 = V_6 -> V_28 -> V_85 ;
* V_8 = F_23 ( * V_103 ) ;
return 0 ;
}
STATIC int
F_88 (
struct V_5 * V_6 ,
union V_54 * V_55 ,
int V_135 ,
struct V_7 * * V_8 ,
struct V_10 * * V_103 )
{
struct V_13 * V_14 = V_6 -> V_16 ;
T_11 V_107 ;
int error ;
ASSERT ( ! ( V_135 & V_152 ) ) ;
V_107 = F_70 ( V_6 , V_55 ) ;
error = F_37 ( V_14 , V_6 -> V_68 , V_14 -> V_83 , V_107 ,
V_14 -> V_84 , V_135 , V_103 ,
V_6 -> V_28 -> V_85 ) ;
if ( error )
return error ;
F_86 ( V_6 , * V_103 ) ;
* V_8 = F_23 ( * V_103 ) ;
return 0 ;
}
STATIC void
F_89 (
struct V_5 * V_6 ,
union V_97 * V_155 ,
union V_97 * V_156 ,
int V_157 )
{
ASSERT ( V_157 >= 0 ) ;
memcpy ( V_155 , V_156 , V_157 * V_6 -> V_28 -> V_95 ) ;
}
STATIC void
F_90 (
struct V_5 * V_6 ,
union V_96 * V_158 ,
union V_96 * V_159 ,
int V_133 )
{
ASSERT ( V_133 >= 0 ) ;
memcpy ( V_158 , V_159 , V_133 * V_6 -> V_28 -> V_94 ) ;
}
STATIC void
F_91 (
struct V_5 * V_6 ,
union V_54 * V_160 ,
union V_54 * V_161 ,
int V_162 )
{
ASSERT ( V_162 >= 0 ) ;
memcpy ( V_160 , V_161 , V_162 * F_40 ( V_6 ) ) ;
}
STATIC void
F_92 (
struct V_5 * V_6 ,
union V_97 * V_163 ,
int V_164 ,
int V_157 )
{
char * V_155 ;
ASSERT ( V_157 >= 0 ) ;
ASSERT ( V_164 == 1 || V_164 == - 1 ) ;
V_155 = ( char * ) V_163 + ( V_164 * V_6 -> V_28 -> V_95 ) ;
memmove ( V_155 , V_163 , V_157 * V_6 -> V_28 -> V_95 ) ;
}
STATIC void
F_93 (
struct V_5 * V_6 ,
union V_96 * V_165 ,
int V_164 ,
int V_133 )
{
char * V_158 ;
ASSERT ( V_133 >= 0 ) ;
ASSERT ( V_164 == 1 || V_164 == - 1 ) ;
V_158 = ( char * ) V_165 + ( V_164 * V_6 -> V_28 -> V_94 ) ;
memmove ( V_158 , V_165 , V_133 * V_6 -> V_28 -> V_94 ) ;
}
STATIC void
F_94 (
struct V_5 * V_6 ,
union V_54 * V_55 ,
int V_164 ,
int V_162 )
{
char * V_160 ;
ASSERT ( V_162 >= 0 ) ;
ASSERT ( V_164 == 1 || V_164 == - 1 ) ;
V_160 = ( char * ) V_55 + ( V_164 * F_40 ( V_6 ) ) ;
memmove ( V_160 , V_55 , V_162 * F_40 ( V_6 ) ) ;
}
STATIC void
F_95 (
struct V_5 * V_6 ,
struct V_10 * V_11 ,
int V_114 ,
int V_115 )
{
F_96 ( V_6 , V_166 ) ;
F_97 ( V_6 , V_11 , V_114 , V_115 ) ;
if ( V_11 ) {
F_98 ( V_6 -> V_68 , V_11 , V_167 ) ;
F_99 ( V_6 -> V_68 , V_11 ,
F_42 ( V_6 , V_114 ) ,
F_42 ( V_6 , V_115 + 1 ) - 1 ) ;
} else {
F_100 ( V_6 -> V_68 , V_6 -> V_43 . V_73 . V_100 ,
F_101 ( V_6 -> V_43 . V_73 . V_101 ) ) ;
}
F_96 ( V_6 , V_168 ) ;
}
void
F_102 (
struct V_5 * V_6 ,
struct V_10 * V_11 ,
int V_114 ,
int V_115 )
{
F_96 ( V_6 , V_166 ) ;
F_97 ( V_6 , V_11 , V_114 , V_115 ) ;
F_98 ( V_6 -> V_68 , V_11 , V_167 ) ;
F_99 ( V_6 -> V_68 , V_11 ,
F_41 ( V_6 , V_114 ) ,
F_41 ( V_6 , V_115 + 1 ) - 1 ) ;
F_96 ( V_6 , V_168 ) ;
}
STATIC void
F_103 (
struct V_5 * V_6 ,
struct V_10 * V_11 ,
int V_114 ,
int V_115 )
{
F_96 ( V_6 , V_166 ) ;
F_97 ( V_6 , V_11 , V_114 , V_115 ) ;
if ( V_11 ) {
struct V_7 * V_8 = F_23 ( V_11 ) ;
int V_9 = F_49 ( V_8 ) ;
F_98 ( V_6 -> V_68 , V_11 , V_167 ) ;
F_99 ( V_6 -> V_68 , V_11 ,
F_44 ( V_6 , V_114 , V_9 ) ,
F_44 ( V_6 , V_115 + 1 , V_9 ) - 1 ) ;
} else {
F_100 ( V_6 -> V_68 , V_6 -> V_43 . V_73 . V_100 ,
F_101 ( V_6 -> V_43 . V_73 . V_101 ) ) ;
}
F_96 ( V_6 , V_168 ) ;
}
void
F_104 (
struct V_5 * V_6 ,
struct V_10 * V_11 ,
int V_111 )
{
int V_114 ;
int V_115 ;
static const short V_169 [] = {
F_105 ( struct V_7 , V_25 ) ,
F_105 ( struct V_7 , V_26 ) ,
F_105 ( struct V_7 , V_27 ) ,
F_105 ( struct V_7 , V_18 . V_46 . V_30 ) ,
F_105 ( struct V_7 , V_18 . V_46 . V_32 ) ,
F_105 ( struct V_7 , V_18 . V_46 . V_22 ) ,
F_105 ( struct V_7 , V_18 . V_46 . V_62 ) ,
F_105 ( struct V_7 , V_18 . V_46 . V_20 ) ,
F_105 ( struct V_7 , V_18 . V_46 . V_136 ) ,
F_105 ( struct V_7 , V_18 . V_46 . V_170 ) ,
V_89
} ;
static const short V_171 [] = {
F_105 ( struct V_7 , V_25 ) ,
F_105 ( struct V_7 , V_26 ) ,
F_105 ( struct V_7 , V_27 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_30 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_32 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_22 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_62 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_20 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_136 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_170 ) ,
F_105 ( struct V_7 , V_18 . V_19 . V_137 ) ,
V_87
} ;
F_96 ( V_6 , V_166 ) ;
F_106 ( V_6 , V_11 , V_111 ) ;
if ( V_11 ) {
int V_113 ;
if ( V_6 -> V_49 & V_86 ) {
if ( V_111 == V_172 )
V_111 = V_173 ;
V_113 = V_174 ;
} else {
V_113 = V_175 ;
}
F_61 ( V_111 ,
( V_6 -> V_49 & V_50 ) ?
V_171 : V_169 ,
V_113 , & V_114 , & V_115 ) ;
F_98 ( V_6 -> V_68 , V_11 , V_167 ) ;
F_99 ( V_6 -> V_68 , V_11 , V_114 , V_115 ) ;
} else {
F_100 ( V_6 -> V_68 , V_6 -> V_43 . V_73 . V_100 ,
F_101 ( V_6 -> V_43 . V_73 . V_101 ) ) ;
}
F_96 ( V_6 , V_168 ) ;
}
int
F_107 (
struct V_5 * V_6 ,
int V_9 ,
int * V_176 )
{
struct V_7 * V_8 ;
union V_54 V_55 ;
struct V_10 * V_11 ;
int error ;
int V_128 ;
F_96 ( V_6 , V_166 ) ;
F_108 ( V_6 , V_9 ) ;
ASSERT ( V_9 < V_6 -> V_70 ) ;
F_69 ( V_6 , V_9 , V_127 ) ;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error )
goto V_177;
#endif
if ( ++ V_6 -> V_81 [ V_9 ] <= F_110 ( V_8 ) )
goto V_178;
F_75 ( V_6 , V_8 , & V_55 , V_130 ) ;
if ( F_73 ( V_6 , & V_55 ) )
goto V_179;
F_32 ( V_6 , V_180 ) ;
for ( V_128 = V_9 + 1 ; V_128 < V_6 -> V_70 ; V_128 ++ ) {
V_8 = F_52 ( V_6 , V_128 , & V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_128 , V_11 ) ;
if ( error )
goto V_177;
#endif
if ( ++ V_6 -> V_81 [ V_128 ] <= F_110 ( V_8 ) )
break;
F_69 ( V_6 , V_128 , V_127 ) ;
}
if ( V_128 == V_6 -> V_70 ) {
if ( V_6 -> V_49 & V_104 )
goto V_179;
ASSERT ( 0 ) ;
error = - V_37 ;
goto V_177;
}
ASSERT ( V_128 < V_6 -> V_70 ) ;
for ( V_8 = F_52 ( V_6 , V_128 , & V_11 ) ; V_128 > V_9 ; ) {
union V_54 * V_181 ;
V_181 = F_48 ( V_6 , V_6 -> V_81 [ V_128 ] , V_8 ) ;
-- V_128 ;
error = F_88 ( V_6 , V_181 , 0 , & V_8 , & V_11 ) ;
if ( error )
goto V_177;
F_72 ( V_6 , V_128 , V_11 ) ;
V_6 -> V_81 [ V_128 ] = 1 ;
}
V_178:
F_96 ( V_6 , V_168 ) ;
* V_176 = 1 ;
return 0 ;
V_179:
F_96 ( V_6 , V_168 ) ;
* V_176 = 0 ;
return 0 ;
V_177:
F_96 ( V_6 , V_182 ) ;
return error ;
}
int
F_111 (
struct V_5 * V_6 ,
int V_9 ,
int * V_176 )
{
struct V_7 * V_8 ;
T_6 * V_11 ;
int error ;
int V_128 ;
union V_54 V_55 ;
F_96 ( V_6 , V_166 ) ;
F_108 ( V_6 , V_9 ) ;
ASSERT ( V_9 < V_6 -> V_70 ) ;
F_69 ( V_6 , V_9 , V_126 ) ;
if ( -- V_6 -> V_81 [ V_9 ] > 0 )
goto V_178;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error )
goto V_177;
#endif
F_75 ( V_6 , V_8 , & V_55 , V_129 ) ;
if ( F_73 ( V_6 , & V_55 ) )
goto V_179;
F_32 ( V_6 , V_183 ) ;
for ( V_128 = V_9 + 1 ; V_128 < V_6 -> V_70 ; V_128 ++ ) {
if ( -- V_6 -> V_81 [ V_128 ] > 0 )
break;
F_69 ( V_6 , V_128 , V_126 ) ;
}
if ( V_128 == V_6 -> V_70 ) {
if ( V_6 -> V_49 & V_104 )
goto V_179;
ASSERT ( 0 ) ;
error = - V_37 ;
goto V_177;
}
ASSERT ( V_128 < V_6 -> V_70 ) ;
for ( V_8 = F_52 ( V_6 , V_128 , & V_11 ) ; V_128 > V_9 ; ) {
union V_54 * V_181 ;
V_181 = F_48 ( V_6 , V_6 -> V_81 [ V_128 ] , V_8 ) ;
-- V_128 ;
error = F_88 ( V_6 , V_181 , 0 , & V_8 , & V_11 ) ;
if ( error )
goto V_177;
F_72 ( V_6 , V_128 , V_11 ) ;
V_6 -> V_81 [ V_128 ] = F_110 ( V_8 ) ;
}
V_178:
F_96 ( V_6 , V_168 ) ;
* V_176 = 1 ;
return 0 ;
V_179:
F_96 ( V_6 , V_168 ) ;
* V_176 = 0 ;
return 0 ;
V_177:
F_96 ( V_6 , V_182 ) ;
return error ;
}
int
F_112 (
struct V_5 * V_6 ,
int V_9 ,
union V_54 * V_184 ,
struct V_7 * * V_185 )
{
struct V_10 * V_11 ;
int error = 0 ;
if ( ( V_6 -> V_49 & V_104 ) &&
( V_9 == V_6 -> V_70 - 1 ) ) {
* V_185 = F_50 ( V_6 ) ;
return 0 ;
}
V_11 = V_6 -> V_71 [ V_9 ] ;
if ( V_11 && F_38 ( V_11 ) == F_70 ( V_6 , V_184 ) ) {
* V_185 = F_23 ( V_11 ) ;
return 0 ;
}
error = F_88 ( V_6 , V_184 , 0 , V_185 , & V_11 ) ;
if ( error )
return error ;
if ( F_3 ( & V_6 -> V_16 -> V_17 ) &&
( V_6 -> V_49 & V_50 ) &&
F_9 ( ( * V_185 ) -> V_18 . V_19 . V_136 ) !=
V_6 -> V_43 . V_73 . V_100 -> V_139 )
goto V_186;
if ( F_7 ( ( * V_185 ) -> V_26 ) != V_9 )
goto V_186;
if ( V_9 != 0 && F_7 ( ( * V_185 ) -> V_27 ) == 0 )
goto V_186;
F_72 ( V_6 , V_9 , V_11 ) ;
return 0 ;
V_186:
* V_185 = NULL ;
F_34 ( V_6 -> V_68 , V_11 ) ;
return - V_37 ;
}
STATIC union V_97 *
F_113 (
struct V_5 * V_6 ,
int V_9 ,
int V_187 ,
struct V_7 * V_8 ,
union V_97 * V_188 )
{
if ( V_9 == 0 ) {
V_6 -> V_28 -> V_189 ( V_188 ,
F_45 ( V_6 , V_187 , V_8 ) ) ;
return V_188 ;
}
return F_46 ( V_6 , V_187 , V_8 ) ;
}
int
F_114 (
struct V_5 * V_6 ,
T_18 V_164 ,
int * V_176 )
{
struct V_7 * V_8 ;
T_13 V_190 ;
int error ;
int V_187 ;
int V_9 ;
union V_54 * V_184 ;
union V_54 V_55 ;
F_96 ( V_6 , V_166 ) ;
F_108 ( V_6 , V_164 ) ;
F_32 ( V_6 , V_191 ) ;
if ( V_6 -> V_70 == 0 )
return - V_37 ;
V_8 = NULL ;
V_187 = 0 ;
V_6 -> V_28 -> V_192 ( V_6 , & V_55 ) ;
V_184 = & V_55 ;
for ( V_9 = V_6 -> V_70 - 1 , V_190 = 1 ; V_9 >= 0 ; V_9 -- ) {
error = F_112 ( V_6 , V_9 , V_184 , & V_8 ) ;
if ( error )
goto V_177;
if ( V_190 == 0 ) {
V_187 = 1 ;
} else {
int V_193 ;
int V_194 ;
V_194 = 1 ;
V_193 = F_110 ( V_8 ) ;
if ( ! V_193 ) {
ASSERT ( V_9 == 0 && V_6 -> V_70 == 1 ) ;
V_6 -> V_81 [ 0 ] = V_164 != V_195 ;
F_96 ( V_6 , V_168 ) ;
* V_176 = 0 ;
return 0 ;
}
while ( V_194 <= V_193 ) {
union V_97 V_163 ;
union V_97 * V_188 ;
F_32 ( V_6 , V_196 ) ;
V_187 = ( V_194 + V_193 ) >> 1 ;
V_188 = F_113 ( V_6 , V_9 ,
V_187 , V_8 , & V_163 ) ;
V_190 = V_6 -> V_28 -> V_197 ( V_6 , V_188 ) ;
if ( V_190 < 0 )
V_194 = V_187 + 1 ;
else if ( V_190 > 0 )
V_193 = V_187 - 1 ;
else
break;
}
}
if ( V_9 > 0 ) {
if ( V_190 > 0 && -- V_187 < 1 )
V_187 = 1 ;
V_184 = F_48 ( V_6 , V_187 , V_8 ) ;
#ifdef F_109
error = F_21 ( V_6 , V_184 , 0 , V_9 ) ;
if ( error )
goto V_177;
#endif
V_6 -> V_81 [ V_9 ] = V_187 ;
}
}
if ( V_164 != V_195 && V_190 < 0 ) {
V_187 ++ ;
F_75 ( V_6 , V_8 , & V_55 , V_130 ) ;
if ( V_164 == V_198 &&
V_187 > F_110 ( V_8 ) &&
! F_73 ( V_6 , & V_55 ) ) {
int V_69 ;
V_6 -> V_81 [ 0 ] = V_187 ;
error = F_107 ( V_6 , 0 , & V_69 ) ;
if ( error )
goto V_177;
F_19 ( V_6 -> V_16 , V_69 == 1 ) ;
F_96 ( V_6 , V_168 ) ;
* V_176 = 1 ;
return 0 ;
}
} else if ( V_164 == V_195 && V_190 > 0 )
V_187 -- ;
V_6 -> V_81 [ 0 ] = V_187 ;
if ( V_187 == 0 || V_187 > F_110 ( V_8 ) )
* V_176 = 0 ;
else if ( V_164 != V_199 || V_190 == 0 )
* V_176 = 1 ;
else
* V_176 = 0 ;
F_96 ( V_6 , V_168 ) ;
return 0 ;
V_177:
F_96 ( V_6 , V_182 ) ;
return error ;
}
STATIC union V_97 *
F_115 (
struct V_5 * V_6 ,
union V_97 * V_163 )
{
ASSERT ( V_6 -> V_49 & V_200 ) ;
return (union V_97 * ) ( ( char * ) V_163 +
( V_6 -> V_28 -> V_95 / 2 ) ) ;
}
STATIC void
F_116 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
union V_97 * V_163 )
{
union V_97 V_201 ;
union V_97 V_202 ;
union V_96 * V_165 ;
union V_97 * V_193 ;
int V_93 ;
V_165 = F_45 ( V_6 , 1 , V_8 ) ;
V_6 -> V_28 -> V_189 ( V_163 , V_165 ) ;
if ( V_6 -> V_49 & V_200 ) {
V_6 -> V_28 -> V_203 ( & V_201 , V_165 ) ;
for ( V_93 = 2 ; V_93 <= F_110 ( V_8 ) ; V_93 ++ ) {
V_165 = F_45 ( V_6 , V_93 , V_8 ) ;
V_6 -> V_28 -> V_203 ( & V_202 , V_165 ) ;
if ( V_6 -> V_28 -> V_204 ( V_6 , & V_202 , & V_201 )
> 0 )
V_201 = V_202 ;
}
V_193 = F_115 ( V_6 , V_163 ) ;
memcpy ( V_193 , & V_201 , V_6 -> V_28 -> V_95 / 2 ) ;
}
}
STATIC void
F_117 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
union V_97 * V_163 )
{
union V_97 * V_202 ;
union V_97 * V_201 ;
union V_97 * V_193 ;
int V_93 ;
if ( V_6 -> V_49 & V_200 ) {
memcpy ( V_163 , F_46 ( V_6 , 1 , V_8 ) ,
V_6 -> V_28 -> V_95 / 2 ) ;
V_201 = F_47 ( V_6 , 1 , V_8 ) ;
for ( V_93 = 2 ; V_93 <= F_110 ( V_8 ) ; V_93 ++ ) {
V_202 = F_47 ( V_6 , V_93 , V_8 ) ;
if ( V_6 -> V_28 -> V_204 ( V_6 , V_202 , V_201 ) > 0 )
V_201 = V_202 ;
}
V_193 = F_115 ( V_6 , V_163 ) ;
memcpy ( V_193 , V_201 , V_6 -> V_28 -> V_95 / 2 ) ;
} else {
memcpy ( V_163 , F_46 ( V_6 , 1 , V_8 ) ,
V_6 -> V_28 -> V_95 ) ;
}
}
STATIC void
F_118 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
union V_97 * V_163 )
{
if ( F_7 ( V_8 -> V_26 ) == 0 )
F_116 ( V_6 , V_8 , V_163 ) ;
else
F_117 ( V_6 , V_8 , V_163 ) ;
}
static inline bool
F_119 (
struct V_5 * V_6 ,
int V_55 )
{
return ( V_6 -> V_49 & V_200 ) || V_55 == 1 ;
}
STATIC int
F_120 (
struct V_5 * V_6 ,
int V_9 ,
struct V_7 * V_8 ,
struct V_10 * V_205 ,
bool V_206 )
{
union V_97 V_163 ;
union V_97 * V_207 ;
union V_97 * V_202 ;
union V_97 * V_208 ;
union V_97 * V_209 ;
struct V_10 * V_11 ;
int V_55 ;
ASSERT ( V_6 -> V_49 & V_200 ) ;
if ( V_9 + 1 >= V_6 -> V_70 )
return 0 ;
F_121 ( V_6 , V_9 , V_205 ) ;
V_207 = & V_163 ;
V_202 = F_115 ( V_6 , V_207 ) ;
F_118 ( V_6 , V_8 , V_207 ) ;
for ( V_9 ++ ; V_9 < V_6 -> V_70 ; V_9 ++ ) {
#ifdef F_109
int error ;
#endif
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
F_121 ( V_6 , V_9 , V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error ) {
F_96 ( V_6 , V_182 ) ;
return error ;
}
#endif
V_55 = V_6 -> V_81 [ V_9 ] ;
V_208 = F_46 ( V_6 , V_55 , V_8 ) ;
V_209 = F_47 ( V_6 , V_55 , V_8 ) ;
if ( ! V_206 &&
! ( V_6 -> V_28 -> V_204 ( V_6 , V_208 , V_207 ) != 0 ||
V_6 -> V_28 -> V_204 ( V_6 , V_209 , V_202 ) != 0 ) )
break;
F_89 ( V_6 , V_208 , V_207 , 1 ) ;
F_95 ( V_6 , V_11 , V_55 , V_55 ) ;
if ( V_9 + 1 >= V_6 -> V_70 )
break;
F_117 ( V_6 , V_8 , V_207 ) ;
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
union V_97 * V_188 ;
union V_97 V_163 ;
int V_55 ;
ASSERT ( V_9 >= 0 ) ;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
if ( V_6 -> V_49 & V_200 )
return F_120 ( V_6 , V_9 , V_8 , V_11 , false ) ;
F_96 ( V_6 , V_166 ) ;
F_124 ( V_6 , V_9 , V_210 ) ;
F_118 ( V_6 , V_8 , & V_163 ) ;
for ( V_9 ++ , V_55 = 1 ; V_55 == 1 && V_9 < V_6 -> V_70 ; V_9 ++ ) {
#ifdef F_109
int error ;
#endif
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error ) {
F_96 ( V_6 , V_182 ) ;
return error ;
}
#endif
V_55 = V_6 -> V_81 [ V_9 ] ;
V_188 = F_46 ( V_6 , V_55 , V_8 ) ;
F_89 ( V_6 , V_188 , & V_163 , 1 ) ;
F_95 ( V_6 , V_11 , V_55 , V_55 ) ;
}
F_96 ( V_6 , V_168 ) ;
return 0 ;
}
int
F_125 (
struct V_5 * V_6 ,
union V_96 * V_165 )
{
struct V_7 * V_8 ;
struct V_10 * V_11 ;
int error ;
int V_55 ;
union V_96 * V_211 ;
F_96 ( V_6 , V_166 ) ;
F_126 ( V_6 , V_165 ) ;
V_8 = F_52 ( V_6 , 0 , & V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , 0 , V_11 ) ;
if ( error )
goto V_177;
#endif
V_55 = V_6 -> V_81 [ 0 ] ;
V_211 = F_45 ( V_6 , V_55 , V_8 ) ;
F_90 ( V_6 , V_211 , V_165 , 1 ) ;
F_102 ( V_6 , V_11 , V_55 , V_55 ) ;
if ( F_82 ( V_6 , V_8 , 0 ) ) {
V_6 -> V_28 -> V_212 ( V_6 , V_8 , V_165 ,
V_55 , V_213 ) ;
}
if ( F_119 ( V_6 , V_55 ) ) {
error = F_123 ( V_6 , 0 ) ;
if ( error )
goto V_177;
}
F_96 ( V_6 , V_168 ) ;
return 0 ;
V_177:
F_96 ( V_6 , V_182 ) ;
return error ;
}
STATIC int
F_127 (
struct V_5 * V_6 ,
int V_9 ,
int * V_176 )
{
struct V_10 * V_214 ;
struct V_7 * V_124 ;
int V_215 ;
struct V_10 * V_216 ;
struct V_7 * V_125 ;
struct V_5 * V_217 ;
int V_218 ;
union V_54 V_219 ;
union V_97 * V_220 = NULL ;
union V_54 * V_221 = NULL ;
union V_96 * V_222 = NULL ;
int error ;
int V_69 ;
F_96 ( V_6 , V_166 ) ;
F_108 ( V_6 , V_9 ) ;
if ( ( V_6 -> V_49 & V_104 ) &&
V_9 == V_6 -> V_70 - 1 )
goto V_179;
V_125 = F_52 ( V_6 , V_9 , & V_216 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_125 , V_9 , V_216 ) ;
if ( error )
goto V_177;
#endif
F_75 ( V_6 , V_125 , & V_219 , V_129 ) ;
if ( F_73 ( V_6 , & V_219 ) )
goto V_179;
if ( V_6 -> V_81 [ V_9 ] <= 1 )
goto V_179;
error = F_88 ( V_6 , & V_219 , 0 , & V_124 , & V_214 ) ;
if ( error )
goto V_177;
V_215 = F_110 ( V_124 ) ;
if ( V_215 == V_6 -> V_28 -> V_29 ( V_6 , V_9 ) )
goto V_179;
V_218 = F_110 ( V_125 ) ;
V_215 ++ ;
V_218 -- ;
F_32 ( V_6 , V_223 ) ;
F_128 ( V_6 , V_224 , 1 ) ;
if ( V_9 > 0 ) {
union V_97 * V_225 ;
union V_54 * V_226 ;
V_225 = F_46 ( V_6 , V_215 , V_124 ) ;
V_220 = F_46 ( V_6 , 1 , V_125 ) ;
V_226 = F_48 ( V_6 , V_215 , V_124 ) ;
V_221 = F_48 ( V_6 , 1 , V_125 ) ;
#ifdef F_109
error = F_21 ( V_6 , V_221 , 0 , V_9 ) ;
if ( error )
goto V_177;
#endif
F_89 ( V_6 , V_225 , V_220 , 1 ) ;
F_91 ( V_6 , V_226 , V_221 , 1 ) ;
F_95 ( V_6 , V_214 , V_215 , V_215 ) ;
F_103 ( V_6 , V_214 , V_215 , V_215 ) ;
ASSERT ( V_6 -> V_28 -> V_227 ( V_6 ,
F_46 ( V_6 , V_215 - 1 , V_124 ) , V_225 ) ) ;
} else {
union V_96 * V_228 ;
V_228 = F_45 ( V_6 , V_215 , V_124 ) ;
V_222 = F_45 ( V_6 , 1 , V_125 ) ;
F_90 ( V_6 , V_228 , V_222 , 1 ) ;
F_102 ( V_6 , V_214 , V_215 , V_215 ) ;
ASSERT ( V_6 -> V_28 -> V_229 ( V_6 ,
F_45 ( V_6 , V_215 - 1 , V_124 ) , V_228 ) ) ;
}
F_129 ( V_124 , V_215 ) ;
F_104 ( V_6 , V_214 , V_230 ) ;
F_129 ( V_125 , V_218 ) ;
F_104 ( V_6 , V_216 , V_230 ) ;
F_128 ( V_6 , V_224 , V_218 - 1 ) ;
if ( V_9 > 0 ) {
#ifdef F_109
int V_69 ;
for ( V_69 = 0 ; V_69 < V_218 ; V_69 ++ ) {
error = F_21 ( V_6 , V_221 , V_69 + 1 , V_9 ) ;
if ( error )
goto V_177;
}
#endif
F_92 ( V_6 ,
F_46 ( V_6 , 2 , V_125 ) ,
- 1 , V_218 ) ;
F_94 ( V_6 ,
F_48 ( V_6 , 2 , V_125 ) ,
- 1 , V_218 ) ;
F_95 ( V_6 , V_216 , 1 , V_218 ) ;
F_103 ( V_6 , V_216 , 1 , V_218 ) ;
} else {
F_93 ( V_6 ,
F_45 ( V_6 , 2 , V_125 ) ,
- 1 , V_218 ) ;
F_102 ( V_6 , V_216 , 1 , V_218 ) ;
}
if ( V_6 -> V_49 & V_200 ) {
error = F_36 ( V_6 , & V_217 ) ;
if ( error )
goto V_177;
V_69 = F_59 ( V_217 , V_9 ) ;
F_130 ( V_217 -> V_16 , V_69 == 1 , V_177 ) ;
error = F_111 ( V_217 , V_9 , & V_69 ) ;
if ( error )
goto V_231;
error = F_123 ( V_217 , V_9 ) ;
if ( error )
goto V_231;
F_33 ( V_217 , V_232 ) ;
}
error = F_123 ( V_6 , V_9 ) ;
if ( error )
goto V_177;
V_6 -> V_81 [ V_9 ] -- ;
F_96 ( V_6 , V_168 ) ;
* V_176 = 1 ;
return 0 ;
V_179:
F_96 ( V_6 , V_168 ) ;
* V_176 = 0 ;
return 0 ;
V_177:
F_96 ( V_6 , V_182 ) ;
return error ;
V_231:
F_96 ( V_217 , V_182 ) ;
F_33 ( V_217 , V_233 ) ;
return error ;
}
STATIC int
F_131 (
struct V_5 * V_6 ,
int V_9 ,
int * V_176 )
{
struct V_10 * V_214 ;
struct V_7 * V_124 ;
struct V_10 * V_216 ;
struct V_7 * V_125 ;
struct V_5 * V_217 ;
union V_54 V_234 ;
union V_97 * V_220 ;
int V_218 ;
int V_215 ;
int error ;
int V_69 ;
F_96 ( V_6 , V_166 ) ;
F_108 ( V_6 , V_9 ) ;
if ( ( V_6 -> V_49 & V_104 ) &&
( V_9 == V_6 -> V_70 - 1 ) )
goto V_179;
V_124 = F_52 ( V_6 , V_9 , & V_214 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_124 , V_9 , V_214 ) ;
if ( error )
goto V_177;
#endif
F_75 ( V_6 , V_124 , & V_234 , V_130 ) ;
if ( F_73 ( V_6 , & V_234 ) )
goto V_179;
V_215 = F_110 ( V_124 ) ;
if ( V_6 -> V_81 [ V_9 ] >= V_215 )
goto V_179;
error = F_88 ( V_6 , & V_234 , 0 , & V_125 , & V_216 ) ;
if ( error )
goto V_177;
V_218 = F_110 ( V_125 ) ;
if ( V_218 == V_6 -> V_28 -> V_29 ( V_6 , V_9 ) )
goto V_179;
F_32 ( V_6 , V_235 ) ;
F_128 ( V_6 , V_224 , V_218 ) ;
if ( V_9 > 0 ) {
union V_97 * V_225 ;
union V_54 * V_226 ;
union V_54 * V_221 ;
V_225 = F_46 ( V_6 , V_215 , V_124 ) ;
V_226 = F_48 ( V_6 , V_215 , V_124 ) ;
V_220 = F_46 ( V_6 , 1 , V_125 ) ;
V_221 = F_48 ( V_6 , 1 , V_125 ) ;
#ifdef F_109
for ( V_69 = V_218 - 1 ; V_69 >= 0 ; V_69 -- ) {
error = F_21 ( V_6 , V_221 , V_69 , V_9 ) ;
if ( error )
goto V_177;
}
#endif
F_92 ( V_6 , V_220 , 1 , V_218 ) ;
F_94 ( V_6 , V_221 , 1 , V_218 ) ;
#ifdef F_109
error = F_21 ( V_6 , V_226 , 0 , V_9 ) ;
if ( error )
goto V_177;
#endif
F_89 ( V_6 , V_220 , V_225 , 1 ) ;
F_91 ( V_6 , V_221 , V_226 , 1 ) ;
F_95 ( V_6 , V_216 , 1 , V_218 + 1 ) ;
F_103 ( V_6 , V_216 , 1 , V_218 + 1 ) ;
ASSERT ( V_6 -> V_28 -> V_227 ( V_6 , V_220 ,
F_46 ( V_6 , 2 , V_125 ) ) ) ;
} else {
union V_96 * V_228 ;
union V_96 * V_222 ;
V_228 = F_45 ( V_6 , V_215 , V_124 ) ;
V_222 = F_45 ( V_6 , 1 , V_125 ) ;
F_93 ( V_6 , V_222 , 1 , V_218 ) ;
F_90 ( V_6 , V_222 , V_228 , 1 ) ;
F_102 ( V_6 , V_216 , 1 , V_218 + 1 ) ;
}
F_129 ( V_124 , -- V_215 ) ;
F_104 ( V_6 , V_214 , V_230 ) ;
F_129 ( V_125 , ++ V_218 ) ;
F_104 ( V_6 , V_216 , V_230 ) ;
error = F_36 ( V_6 , & V_217 ) ;
if ( error )
goto V_177;
V_69 = F_60 ( V_217 , V_9 ) ;
F_130 ( V_217 -> V_16 , V_69 == 1 , V_177 ) ;
error = F_107 ( V_217 , V_9 , & V_69 ) ;
if ( error )
goto V_231;
if ( V_6 -> V_49 & V_200 ) {
error = F_123 ( V_6 , V_9 ) ;
if ( error )
goto V_231;
}
error = F_123 ( V_217 , V_9 ) ;
if ( error )
goto V_231;
F_33 ( V_217 , V_232 ) ;
F_96 ( V_6 , V_168 ) ;
* V_176 = 1 ;
return 0 ;
V_179:
F_96 ( V_6 , V_168 ) ;
* V_176 = 0 ;
return 0 ;
V_177:
F_96 ( V_6 , V_182 ) ;
return error ;
V_231:
F_96 ( V_217 , V_182 ) ;
F_33 ( V_217 , V_233 ) ;
return error ;
}
STATIC int
F_132 (
struct V_5 * V_6 ,
int V_9 ,
union V_54 * V_181 ,
union V_97 * V_163 ,
struct V_5 * * V_236 ,
int * V_176 )
{
union V_54 V_219 ;
struct V_10 * V_214 ;
struct V_7 * V_124 ;
union V_54 V_234 ;
struct V_10 * V_216 ;
struct V_7 * V_125 ;
union V_54 V_237 ;
struct V_10 * V_238 ;
struct V_7 * V_239 ;
int V_215 ;
int V_218 ;
int V_240 ;
int error ;
#ifdef F_109
int V_69 ;
#endif
F_96 ( V_6 , V_166 ) ;
F_133 ( V_6 , V_9 , * V_181 , V_163 ) ;
F_32 ( V_6 , V_241 ) ;
V_124 = F_52 ( V_6 , V_9 , & V_214 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_124 , V_9 , V_214 ) ;
if ( error )
goto V_177;
#endif
F_83 ( V_6 , V_214 , & V_219 ) ;
error = V_6 -> V_28 -> V_242 ( V_6 , & V_219 , & V_234 , V_176 ) ;
if ( error )
goto V_177;
if ( * V_176 == 0 )
goto V_179;
F_32 ( V_6 , V_243 ) ;
error = F_87 ( V_6 , & V_234 , 0 , & V_125 , & V_216 ) ;
if ( error )
goto V_177;
F_81 ( V_6 , V_216 , F_49 ( V_124 ) , 0 ) ;
V_215 = F_110 ( V_124 ) ;
V_218 = V_215 / 2 ;
if ( ( V_215 & 1 ) && V_6 -> V_81 [ V_9 ] <= V_218 + 1 )
V_218 ++ ;
V_240 = ( V_215 - V_218 + 1 ) ;
F_128 ( V_6 , V_224 , V_218 ) ;
V_215 -= V_218 ;
F_129 ( V_124 , V_215 ) ;
F_129 ( V_125 , F_110 ( V_125 ) + V_218 ) ;
if ( V_9 > 0 ) {
union V_97 * V_225 ;
union V_54 * V_226 ;
union V_97 * V_220 ;
union V_54 * V_221 ;
V_225 = F_46 ( V_6 , V_240 , V_124 ) ;
V_226 = F_48 ( V_6 , V_240 , V_124 ) ;
V_220 = F_46 ( V_6 , 1 , V_125 ) ;
V_221 = F_48 ( V_6 , 1 , V_125 ) ;
#ifdef F_109
for ( V_69 = V_240 ; V_69 < V_218 ; V_69 ++ ) {
error = F_21 ( V_6 , V_226 , V_69 , V_9 ) ;
if ( error )
goto V_177;
}
#endif
F_89 ( V_6 , V_220 , V_225 , V_218 ) ;
F_91 ( V_6 , V_221 , V_226 , V_218 ) ;
F_95 ( V_6 , V_216 , 1 , V_218 ) ;
F_103 ( V_6 , V_216 , 1 , V_218 ) ;
F_117 ( V_6 , V_125 , V_163 ) ;
} else {
union V_96 * V_228 ;
union V_96 * V_222 ;
V_228 = F_45 ( V_6 , V_240 , V_124 ) ;
V_222 = F_45 ( V_6 , 1 , V_125 ) ;
F_90 ( V_6 , V_222 , V_228 , V_218 ) ;
F_102 ( V_6 , V_216 , 1 , V_218 ) ;
F_116 ( V_6 , V_125 , V_163 ) ;
}
F_75 ( V_6 , V_124 , & V_237 , V_130 ) ;
F_76 ( V_6 , V_125 , & V_237 , V_130 ) ;
F_76 ( V_6 , V_125 , & V_219 , V_129 ) ;
F_76 ( V_6 , V_124 , & V_234 , V_130 ) ;
F_104 ( V_6 , V_216 , V_172 ) ;
F_104 ( V_6 , V_214 , V_230 | V_130 ) ;
if ( ! F_73 ( V_6 , & V_237 ) ) {
error = F_88 ( V_6 , & V_237 ,
0 , & V_239 , & V_238 ) ;
if ( error )
goto V_177;
F_76 ( V_6 , V_239 , & V_234 , V_129 ) ;
F_104 ( V_6 , V_238 , V_129 ) ;
}
if ( V_6 -> V_49 & V_200 ) {
error = F_123 ( V_6 , V_9 ) ;
if ( error )
goto V_177;
}
if ( V_6 -> V_81 [ V_9 ] > V_215 + 1 ) {
F_72 ( V_6 , V_9 , V_216 ) ;
V_6 -> V_81 [ V_9 ] -= V_215 ;
}
if ( V_9 + 1 < V_6 -> V_70 ) {
error = F_36 ( V_6 , V_236 ) ;
if ( error )
goto V_177;
( * V_236 ) -> V_81 [ V_9 + 1 ] ++ ;
}
* V_181 = V_234 ;
F_96 ( V_6 , V_168 ) ;
* V_176 = 1 ;
return 0 ;
V_179:
F_96 ( V_6 , V_168 ) ;
* V_176 = 0 ;
return 0 ;
V_177:
F_96 ( V_6 , V_182 ) ;
return error ;
}
static void
F_134 (
struct V_244 * V_245 )
{
struct V_246 * args = F_135 ( V_245 ,
struct V_246 , V_245 ) ;
unsigned long V_247 ;
unsigned long V_248 = V_249 ;
if ( args -> V_250 )
V_248 |= V_251 | V_252 | V_253 ;
F_136 ( & V_247 , V_248 ) ;
args -> V_254 = F_132 ( args -> V_6 , args -> V_9 , args -> V_181 ,
args -> V_163 , args -> V_236 , args -> V_176 ) ;
F_137 ( args -> V_255 ) ;
F_138 ( & V_247 , V_248 ) ;
}
STATIC int
F_139 (
struct V_5 * V_6 ,
int V_9 ,
union V_54 * V_181 ,
union V_97 * V_163 ,
struct V_5 * * V_236 ,
int * V_176 )
{
struct V_246 args ;
F_140 ( V_255 ) ;
if ( V_6 -> V_15 != V_72 )
return F_132 ( V_6 , V_9 , V_181 , V_163 , V_236 , V_176 ) ;
args . V_6 = V_6 ;
args . V_9 = V_9 ;
args . V_181 = V_181 ;
args . V_163 = V_163 ;
args . V_236 = V_236 ;
args . V_176 = V_176 ;
args . V_255 = & V_255 ;
args . V_250 = F_141 () ;
F_142 ( & args . V_245 , F_134 ) ;
F_143 ( V_256 , & args . V_245 ) ;
F_144 ( & V_255 ) ;
F_145 ( & args . V_245 ) ;
return args . V_254 ;
}
int
F_146 (
struct V_5 * V_6 ,
int * V_257 ,
int * V_176 )
{
struct V_10 * V_258 ;
struct V_7 * V_8 ;
struct V_7 * V_259 ;
union V_97 * V_260 ;
union V_54 * V_261 ;
union V_97 * V_188 ;
union V_54 * V_184 ;
union V_54 V_262 ;
int V_9 ;
int error ;
#ifdef F_109
int V_69 ;
#endif
F_96 ( V_6 , V_166 ) ;
F_32 ( V_6 , V_263 ) ;
ASSERT ( V_6 -> V_49 & V_104 ) ;
V_9 = V_6 -> V_70 - 1 ;
V_8 = F_50 ( V_6 ) ;
V_184 = F_48 ( V_6 , 1 , V_8 ) ;
error = V_6 -> V_28 -> V_242 ( V_6 , V_184 , & V_262 , V_176 ) ;
if ( error )
goto V_177;
if ( * V_176 == 0 ) {
F_96 ( V_6 , V_168 ) ;
return 0 ;
}
F_32 ( V_6 , V_243 ) ;
error = F_87 ( V_6 , & V_262 , 0 , & V_259 , & V_258 ) ;
if ( error )
goto V_177;
memcpy ( V_259 , V_8 , F_39 ( V_6 ) ) ;
if ( V_6 -> V_49 & V_86 ) {
if ( V_6 -> V_49 & V_50 )
V_259 -> V_18 . V_19 . V_22 = F_5 ( V_258 -> V_23 ) ;
else
V_259 -> V_18 . V_46 . V_22 = F_5 ( V_258 -> V_23 ) ;
}
F_147 ( & V_8 -> V_26 , 1 ) ;
F_129 ( V_8 , 1 ) ;
V_6 -> V_70 ++ ;
V_6 -> V_81 [ V_9 + 1 ] = 1 ;
V_188 = F_46 ( V_6 , 1 , V_8 ) ;
V_260 = F_46 ( V_6 , 1 , V_259 ) ;
F_89 ( V_6 , V_260 , V_188 , F_110 ( V_259 ) ) ;
V_261 = F_48 ( V_6 , 1 , V_259 ) ;
#ifdef F_109
for ( V_69 = 0 ; V_69 < F_7 ( V_259 -> V_27 ) ; V_69 ++ ) {
error = F_21 ( V_6 , V_184 , V_69 , V_9 ) ;
if ( error )
goto V_177;
}
#endif
F_91 ( V_6 , V_261 , V_184 , F_110 ( V_259 ) ) ;
#ifdef F_109
error = F_21 ( V_6 , & V_262 , 0 , V_9 ) ;
if ( error )
goto V_177;
#endif
F_91 ( V_6 , V_184 , & V_262 , 1 ) ;
F_148 ( V_6 -> V_43 . V_73 . V_100 ,
1 - F_110 ( V_259 ) ,
V_6 -> V_43 . V_73 . V_101 ) ;
F_72 ( V_6 , V_9 , V_258 ) ;
F_104 ( V_6 , V_258 , V_172 ) ;
F_95 ( V_6 , V_258 , 1 , F_7 ( V_259 -> V_27 ) ) ;
F_103 ( V_6 , V_258 , 1 , F_7 ( V_259 -> V_27 ) ) ;
* V_257 |=
V_264 | F_101 ( V_6 -> V_43 . V_73 . V_101 ) ;
* V_176 = 1 ;
F_96 ( V_6 , V_168 ) ;
return 0 ;
V_177:
F_96 ( V_6 , V_182 ) ;
return error ;
}
STATIC int
F_149 (
struct V_5 * V_6 ,
int * V_176 )
{
struct V_7 * V_8 ;
struct V_10 * V_11 ;
int error ;
struct V_10 * V_214 ;
struct V_7 * V_124 ;
struct V_10 * V_265 ;
struct V_7 * V_77 ;
int V_262 ;
struct V_10 * V_216 ;
struct V_7 * V_125 ;
union V_54 V_234 ;
union V_54 V_219 ;
F_96 ( V_6 , V_166 ) ;
F_32 ( V_6 , V_263 ) ;
V_6 -> V_28 -> V_192 ( V_6 , & V_234 ) ;
error = V_6 -> V_28 -> V_242 ( V_6 , & V_234 , & V_219 , V_176 ) ;
if ( error )
goto V_177;
if ( * V_176 == 0 )
goto V_179;
F_32 ( V_6 , V_243 ) ;
error = F_87 ( V_6 , & V_219 , 0 , & V_77 , & V_265 ) ;
if ( error )
goto V_177;
V_6 -> V_28 -> V_266 ( V_6 , & V_219 , 1 ) ;
V_8 = F_52 ( V_6 , V_6 -> V_70 - 1 , & V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_6 -> V_70 - 1 , V_11 ) ;
if ( error )
goto V_177;
#endif
F_75 ( V_6 , V_8 , & V_234 , V_130 ) ;
if ( ! F_73 ( V_6 , & V_234 ) ) {
V_214 = V_11 ;
F_83 ( V_6 , V_214 , & V_219 ) ;
V_124 = V_8 ;
error = F_88 ( V_6 , & V_234 , 0 , & V_125 , & V_216 ) ;
if ( error )
goto V_177;
V_11 = V_216 ;
V_262 = 1 ;
} else {
V_216 = V_11 ;
F_83 ( V_6 , V_216 , & V_234 ) ;
V_125 = V_8 ;
F_75 ( V_6 , V_125 , & V_219 , V_129 ) ;
error = F_88 ( V_6 , & V_219 , 0 , & V_124 , & V_214 ) ;
if ( error )
goto V_177;
V_11 = V_214 ;
V_262 = 2 ;
}
F_81 ( V_6 , V_265 , V_6 -> V_70 , 2 ) ;
F_104 ( V_6 , V_265 , V_172 ) ;
ASSERT ( ! F_73 ( V_6 , & V_219 ) &&
! F_73 ( V_6 , & V_234 ) ) ;
if ( F_49 ( V_124 ) > 0 ) {
F_117 ( V_6 , V_124 ,
F_46 ( V_6 , 1 , V_77 ) ) ;
F_117 ( V_6 , V_125 ,
F_46 ( V_6 , 2 , V_77 ) ) ;
} else {
F_116 ( V_6 , V_124 ,
F_46 ( V_6 , 1 , V_77 ) ) ;
F_116 ( V_6 , V_125 ,
F_46 ( V_6 , 2 , V_77 ) ) ;
}
F_95 ( V_6 , V_265 , 1 , 2 ) ;
F_91 ( V_6 ,
F_48 ( V_6 , 1 , V_77 ) , & V_219 , 1 ) ;
F_91 ( V_6 ,
F_48 ( V_6 , 2 , V_77 ) , & V_234 , 1 ) ;
F_103 ( V_6 , V_265 , 1 , 2 ) ;
F_72 ( V_6 , V_6 -> V_70 , V_265 ) ;
V_6 -> V_81 [ V_6 -> V_70 ] = V_262 ;
V_6 -> V_70 ++ ;
F_96 ( V_6 , V_168 ) ;
* V_176 = 1 ;
return 0 ;
V_177:
F_96 ( V_6 , V_182 ) ;
return error ;
V_179:
F_96 ( V_6 , V_168 ) ;
* V_176 = 0 ;
return 0 ;
}
STATIC int
F_150 (
struct V_5 * V_6 ,
int V_9 ,
int V_133 ,
int * V_267 ,
int * V_56 ,
union V_54 * V_262 ,
struct V_5 * * V_76 ,
union V_97 * V_163 ,
int * V_176 )
{
int error = 0 ;
if ( ( V_6 -> V_49 & V_104 ) &&
V_9 == V_6 -> V_70 - 1 ) {
struct V_268 * V_100 = V_6 -> V_43 . V_73 . V_100 ;
if ( V_133 < V_6 -> V_28 -> V_269 ( V_6 , V_9 ) ) {
F_148 ( V_100 , 1 , V_6 -> V_43 . V_73 . V_101 ) ;
* V_176 = 1 ;
} else {
int V_257 = 0 ;
error = F_146 ( V_6 , & V_257 , V_176 ) ;
if ( error || * V_176 == 0 )
return error ;
F_100 ( V_6 -> V_68 , V_100 , V_257 ) ;
}
return 0 ;
}
error = F_131 ( V_6 , V_9 , V_176 ) ;
if ( error || * V_176 )
return error ;
error = F_127 ( V_6 , V_9 , V_176 ) ;
if ( error )
return error ;
if ( * V_176 ) {
* V_267 = * V_56 = V_6 -> V_81 [ V_9 ] ;
return 0 ;
}
error = F_139 ( V_6 , V_9 , V_262 , V_163 , V_76 , V_176 ) ;
if ( error || * V_176 == 0 )
return error ;
* V_56 = V_6 -> V_81 [ V_9 ] ;
return 0 ;
}
STATIC int
F_151 (
struct V_5 * V_6 ,
int V_9 ,
union V_54 * V_181 ,
union V_96 * V_165 ,
union V_97 * V_163 ,
struct V_5 * * V_236 ,
int * V_176 )
{
struct V_7 * V_8 ;
struct V_10 * V_11 ;
union V_54 V_262 ;
struct V_5 * V_76 ;
union V_97 V_270 ;
union V_97 * V_207 ;
int V_271 ;
int V_55 ;
int V_133 ;
int error ;
#ifdef F_109
int V_69 ;
#endif
T_11 V_272 ;
F_96 ( V_6 , V_166 ) ;
F_152 ( V_6 , V_9 , * V_181 , & V_165 ) ;
V_76 = NULL ;
V_207 = & V_270 ;
if ( ! ( V_6 -> V_49 & V_104 ) &&
( V_9 >= V_6 -> V_70 ) ) {
error = F_149 ( V_6 , V_176 ) ;
F_74 ( V_6 , V_181 ) ;
F_96 ( V_6 , V_168 ) ;
return error ;
}
V_55 = V_6 -> V_81 [ V_9 ] ;
if ( V_55 == 0 ) {
F_96 ( V_6 , V_168 ) ;
* V_176 = 0 ;
return 0 ;
}
V_271 = V_55 ;
F_32 ( V_6 , V_273 ) ;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
V_272 = V_11 ? V_11 -> V_23 : V_24 ;
V_133 = F_110 ( V_8 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error )
goto V_177;
if ( V_55 <= V_133 ) {
if ( V_9 == 0 ) {
ASSERT ( V_6 -> V_28 -> V_229 ( V_6 , V_165 ,
F_45 ( V_6 , V_55 , V_8 ) ) ) ;
} else {
ASSERT ( V_6 -> V_28 -> V_227 ( V_6 , V_163 ,
F_46 ( V_6 , V_55 , V_8 ) ) ) ;
}
}
#endif
F_74 ( V_6 , & V_262 ) ;
if ( V_133 == V_6 -> V_28 -> V_29 ( V_6 , V_9 ) ) {
error = F_150 ( V_6 , V_9 , V_133 ,
& V_271 , & V_55 , & V_262 , & V_76 , V_207 , V_176 ) ;
if ( error || * V_176 == 0 )
goto V_177;
}
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
V_133 = F_110 ( V_8 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error )
return error ;
#endif
F_128 ( V_6 , V_224 , V_133 - V_55 + 1 ) ;
if ( V_9 > 0 ) {
union V_97 * V_188 ;
union V_54 * V_184 ;
V_188 = F_46 ( V_6 , V_55 , V_8 ) ;
V_184 = F_48 ( V_6 , V_55 , V_8 ) ;
#ifdef F_109
for ( V_69 = V_133 - V_55 ; V_69 >= 0 ; V_69 -- ) {
error = F_21 ( V_6 , V_184 , V_69 , V_9 ) ;
if ( error )
return error ;
}
#endif
F_92 ( V_6 , V_188 , 1 , V_133 - V_55 + 1 ) ;
F_94 ( V_6 , V_184 , 1 , V_133 - V_55 + 1 ) ;
#ifdef F_109
error = F_21 ( V_6 , V_181 , 0 , V_9 ) ;
if ( error )
goto V_177;
#endif
F_89 ( V_6 , V_188 , V_163 , 1 ) ;
F_91 ( V_6 , V_184 , V_181 , 1 ) ;
V_133 ++ ;
F_129 ( V_8 , V_133 ) ;
F_103 ( V_6 , V_11 , V_55 , V_133 ) ;
F_95 ( V_6 , V_11 , V_55 , V_133 ) ;
#ifdef F_109
if ( V_55 < V_133 ) {
ASSERT ( V_6 -> V_28 -> V_227 ( V_6 , V_188 ,
F_46 ( V_6 , V_55 + 1 , V_8 ) ) ) ;
}
#endif
} else {
union V_96 * V_211 ;
V_211 = F_45 ( V_6 , V_55 , V_8 ) ;
F_93 ( V_6 , V_211 , 1 , V_133 - V_55 + 1 ) ;
F_90 ( V_6 , V_211 , V_165 , 1 ) ;
F_129 ( V_8 , ++ V_133 ) ;
F_102 ( V_6 , V_11 , V_55 , V_133 ) ;
#ifdef F_109
if ( V_55 < V_133 ) {
ASSERT ( V_6 -> V_28 -> V_229 ( V_6 , V_211 ,
F_45 ( V_6 , V_55 + 1 , V_8 ) ) ) ;
}
#endif
}
F_104 ( V_6 , V_11 , V_230 ) ;
if ( V_11 && V_11 -> V_23 != V_272 ) {
F_118 ( V_6 , V_8 , V_207 ) ;
} else if ( F_119 ( V_6 , V_271 ) ) {
error = F_123 ( V_6 , V_9 ) ;
if ( error )
goto V_177;
}
if ( F_82 ( V_6 , V_8 , V_9 ) ) {
V_6 -> V_28 -> V_212 ( V_6 , V_8 , V_165 ,
V_55 , V_274 ) ;
}
* V_181 = V_262 ;
if ( ! F_73 ( V_6 , & V_262 ) ) {
F_89 ( V_6 , V_163 , V_207 , 1 ) ;
* V_236 = V_76 ;
}
F_96 ( V_6 , V_168 ) ;
* V_176 = 1 ;
return 0 ;
V_177:
F_96 ( V_6 , V_182 ) ;
return error ;
}
int
F_153 (
struct V_5 * V_6 ,
int * V_176 )
{
int error ;
int V_69 ;
int V_9 ;
union V_54 V_262 ;
struct V_5 * V_76 ;
struct V_5 * V_275 ;
union V_97 V_276 ;
union V_97 * V_163 ;
union V_96 V_165 ;
V_9 = 0 ;
V_76 = NULL ;
V_275 = V_6 ;
V_163 = & V_276 ;
F_74 ( V_6 , & V_262 ) ;
V_6 -> V_28 -> V_277 ( V_6 , & V_165 ) ;
V_6 -> V_28 -> V_189 ( V_163 , & V_165 ) ;
do {
error = F_151 ( V_275 , V_9 , & V_262 , & V_165 , V_163 ,
& V_76 , & V_69 ) ;
if ( error ) {
if ( V_275 != V_6 )
F_33 ( V_275 , V_233 ) ;
goto V_177;
}
F_130 ( V_6 -> V_16 , V_69 == 1 , V_177 ) ;
V_9 ++ ;
if ( V_275 != V_6 &&
( V_76 || F_73 ( V_6 , & V_262 ) ) ) {
if ( V_6 -> V_28 -> V_278 )
V_6 -> V_28 -> V_278 ( V_275 , V_6 ) ;
V_6 -> V_70 = V_275 -> V_70 ;
F_33 ( V_275 , V_232 ) ;
}
if ( V_76 ) {
V_275 = V_76 ;
V_76 = NULL ;
}
} while ( ! F_73 ( V_6 , & V_262 ) );
F_96 ( V_6 , V_168 ) ;
* V_176 = V_69 ;
return 0 ;
V_177:
F_96 ( V_6 , V_182 ) ;
return error ;
}
STATIC int
F_154 (
struct V_5 * V_6 )
{
int V_101 = V_6 -> V_43 . V_73 . V_101 ;
struct V_268 * V_100 = V_6 -> V_43 . V_73 . V_100 ;
struct V_98 * V_99 = F_51 ( V_100 , V_101 ) ;
struct V_7 * V_8 ;
struct V_7 * V_259 ;
union V_97 * V_188 ;
union V_97 * V_260 ;
union V_54 * V_184 ;
union V_54 * V_261 ;
struct V_10 * V_258 ;
int V_9 ;
int V_56 ;
int V_133 ;
int error ;
#ifdef F_109
union V_54 V_55 ;
int V_69 ;
#endif
F_96 ( V_6 , V_166 ) ;
ASSERT ( V_6 -> V_49 & V_104 ) ;
ASSERT ( V_6 -> V_70 > 1 ) ;
V_9 = V_6 -> V_70 - 1 ;
if ( V_9 == 1 )
goto V_179;
V_8 = F_50 ( V_6 ) ;
if ( F_110 ( V_8 ) != 1 )
goto V_179;
V_259 = F_52 ( V_6 , V_9 - 1 , & V_258 ) ;
V_133 = F_110 ( V_259 ) ;
if ( V_133 > V_6 -> V_28 -> V_269 ( V_6 , V_9 ) )
goto V_179;
F_32 ( V_6 , V_279 ) ;
#ifdef F_109
F_75 ( V_6 , V_8 , & V_55 , V_129 ) ;
ASSERT ( F_73 ( V_6 , & V_55 ) ) ;
F_75 ( V_6 , V_8 , & V_55 , V_130 ) ;
ASSERT ( F_73 ( V_6 , & V_55 ) ) ;
#endif
V_56 = V_133 - V_6 -> V_28 -> V_29 ( V_6 , V_9 ) ;
if ( V_56 ) {
F_148 ( V_6 -> V_43 . V_73 . V_100 , V_56 ,
V_6 -> V_43 . V_73 . V_101 ) ;
V_8 = V_99 -> V_102 ;
}
F_147 ( & V_8 -> V_27 , V_56 ) ;
ASSERT ( V_8 -> V_27 == V_259 -> V_27 ) ;
V_188 = F_46 ( V_6 , 1 , V_8 ) ;
V_260 = F_46 ( V_6 , 1 , V_259 ) ;
F_89 ( V_6 , V_188 , V_260 , V_133 ) ;
V_184 = F_48 ( V_6 , 1 , V_8 ) ;
V_261 = F_48 ( V_6 , 1 , V_259 ) ;
#ifdef F_109
for ( V_69 = 0 ; V_69 < V_133 ; V_69 ++ ) {
error = F_21 ( V_6 , V_261 , V_69 , V_9 - 1 ) ;
if ( error ) {
F_96 ( V_6 , V_182 ) ;
return error ;
}
}
#endif
F_91 ( V_6 , V_184 , V_261 , V_133 ) ;
error = F_30 ( V_6 , V_258 ) ;
if ( error ) {
F_96 ( V_6 , V_182 ) ;
return error ;
}
V_6 -> V_71 [ V_9 - 1 ] = NULL ;
F_147 ( & V_8 -> V_26 , - 1 ) ;
F_100 ( V_6 -> V_68 , V_100 ,
V_264 | F_101 ( V_6 -> V_43 . V_73 . V_101 ) ) ;
V_6 -> V_70 -- ;
V_179:
F_96 ( V_6 , V_168 ) ;
return 0 ;
}
STATIC int
F_155 (
struct V_5 * V_6 ,
struct V_10 * V_11 ,
int V_9 ,
union V_54 * V_263 )
{
int error ;
F_96 ( V_6 , V_166 ) ;
F_32 ( V_6 , V_279 ) ;
V_6 -> V_28 -> V_266 ( V_6 , V_263 , - 1 ) ;
error = F_30 ( V_6 , V_11 ) ;
if ( error ) {
F_96 ( V_6 , V_182 ) ;
return error ;
}
V_6 -> V_71 [ V_9 ] = NULL ;
V_6 -> V_82 [ V_9 ] = 0 ;
V_6 -> V_70 -- ;
F_96 ( V_6 , V_168 ) ;
return 0 ;
}
STATIC int
F_156 (
struct V_5 * V_6 ,
int V_9 ,
int * V_176 )
{
int error ;
int V_69 ;
if ( V_9 > 0 ) {
error = F_111 ( V_6 , V_9 , & V_69 ) ;
if ( error )
return error ;
}
F_96 ( V_6 , V_168 ) ;
* V_176 = 1 ;
return 0 ;
}
STATIC int
F_157 (
struct V_5 * V_6 ,
int V_9 ,
int * V_176 )
{
struct V_7 * V_8 ;
union V_54 V_280 ;
struct V_10 * V_11 ;
int error ;
int V_69 ;
union V_54 V_219 ;
struct V_10 * V_214 ;
struct V_7 * V_124 ;
int V_215 = 0 ;
int V_55 ;
union V_54 V_234 ;
struct V_10 * V_216 ;
struct V_7 * V_125 ;
struct V_7 * V_239 ;
struct V_10 * V_238 ;
int V_218 = 0 ;
struct V_5 * V_217 ;
int V_133 ;
F_96 ( V_6 , V_166 ) ;
F_108 ( V_6 , V_9 ) ;
V_217 = NULL ;
V_55 = V_6 -> V_81 [ V_9 ] ;
if ( V_55 == 0 ) {
F_96 ( V_6 , V_168 ) ;
* V_176 = 0 ;
return 0 ;
}
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
V_133 = F_110 ( V_8 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error )
goto V_177;
#endif
if ( V_55 > V_133 ) {
F_96 ( V_6 , V_168 ) ;
* V_176 = 0 ;
return 0 ;
}
F_32 ( V_6 , V_281 ) ;
F_128 ( V_6 , V_224 , V_133 - V_55 ) ;
if ( V_9 > 0 ) {
union V_97 * V_225 ;
union V_54 * V_226 ;
V_225 = F_46 ( V_6 , V_55 + 1 , V_8 ) ;
V_226 = F_48 ( V_6 , V_55 + 1 , V_8 ) ;
#ifdef F_109
for ( V_69 = 0 ; V_69 < V_133 - V_55 ; V_69 ++ ) {
error = F_21 ( V_6 , V_226 , V_69 , V_9 ) ;
if ( error )
goto V_177;
}
#endif
if ( V_55 < V_133 ) {
F_92 ( V_6 , V_225 , - 1 , V_133 - V_55 ) ;
F_94 ( V_6 , V_226 , - 1 , V_133 - V_55 ) ;
F_95 ( V_6 , V_11 , V_55 , V_133 - 1 ) ;
F_103 ( V_6 , V_11 , V_55 , V_133 - 1 ) ;
}
} else {
if ( V_55 < V_133 ) {
F_93 ( V_6 ,
F_45 ( V_6 , V_55 + 1 , V_8 ) ,
- 1 , V_133 - V_55 ) ;
F_102 ( V_6 , V_11 , V_55 , V_133 - 1 ) ;
}
}
F_129 ( V_8 , -- V_133 ) ;
F_104 ( V_6 , V_11 , V_230 ) ;
if ( F_82 ( V_6 , V_8 , V_9 ) ) {
V_6 -> V_28 -> V_212 ( V_6 , V_8 , NULL ,
V_55 , V_282 ) ;
}
if ( V_9 == V_6 -> V_70 - 1 ) {
if ( V_6 -> V_49 & V_104 ) {
F_148 ( V_6 -> V_43 . V_73 . V_100 , - 1 ,
V_6 -> V_43 . V_73 . V_101 ) ;
error = F_154 ( V_6 ) ;
if ( error )
goto V_177;
error = F_156 ( V_6 , V_9 , V_176 ) ;
if ( error )
goto V_177;
* V_176 = 1 ;
return 0 ;
}
if ( V_133 == 1 && V_9 > 0 ) {
union V_54 * V_184 ;
V_184 = F_48 ( V_6 , 1 , V_8 ) ;
error = F_155 ( V_6 , V_11 , V_9 , V_184 ) ;
if ( error )
goto V_177;
} else if ( V_9 > 0 ) {
error = F_156 ( V_6 , V_9 , V_176 ) ;
if ( error )
goto V_177;
}
* V_176 = 1 ;
return 0 ;
}
if ( F_119 ( V_6 , V_55 ) ) {
error = F_123 ( V_6 , V_9 ) ;
if ( error )
goto V_177;
}
if ( V_133 >= V_6 -> V_28 -> V_283 ( V_6 , V_9 ) ) {
error = F_156 ( V_6 , V_9 , V_176 ) ;
if ( error )
goto V_177;
return 0 ;
}
F_75 ( V_6 , V_8 , & V_234 , V_130 ) ;
F_75 ( V_6 , V_8 , & V_219 , V_129 ) ;
if ( V_6 -> V_49 & V_104 ) {
if ( F_73 ( V_6 , & V_234 ) &&
F_73 ( V_6 , & V_219 ) &&
V_9 == V_6 -> V_70 - 2 ) {
error = F_154 ( V_6 ) ;
if ( ! error )
error = F_156 ( V_6 , V_9 , V_176 ) ;
if ( error )
goto V_177;
return 0 ;
}
}
ASSERT ( ! F_73 ( V_6 , & V_234 ) ||
! F_73 ( V_6 , & V_219 ) ) ;
error = F_36 ( V_6 , & V_217 ) ;
if ( error )
goto V_177;
if ( ! F_73 ( V_6 , & V_234 ) ) {
V_69 = F_60 ( V_217 , V_9 ) ;
F_130 ( V_6 -> V_16 , V_69 == 1 , V_177 ) ;
error = F_107 ( V_217 , V_9 , & V_69 ) ;
if ( error )
goto V_177;
F_130 ( V_6 -> V_16 , V_69 == 1 , V_177 ) ;
V_69 = F_60 ( V_217 , V_9 ) ;
F_130 ( V_6 -> V_16 , V_69 == 1 , V_177 ) ;
V_125 = F_52 ( V_217 , V_9 , & V_216 ) ;
#ifdef F_109
error = F_17 ( V_217 , V_125 , V_9 , V_216 ) ;
if ( error )
goto V_177;
#endif
F_75 ( V_217 , V_125 , & V_280 , V_129 ) ;
if ( F_110 ( V_125 ) - 1 >=
V_6 -> V_28 -> V_283 ( V_217 , V_9 ) ) {
error = F_127 ( V_217 , V_9 , & V_69 ) ;
if ( error )
goto V_177;
if ( V_69 ) {
ASSERT ( F_110 ( V_8 ) >=
V_6 -> V_28 -> V_283 ( V_217 , V_9 ) ) ;
F_33 ( V_217 , V_232 ) ;
V_217 = NULL ;
error = F_156 ( V_6 , V_9 , V_176 ) ;
if ( error )
goto V_177;
return 0 ;
}
}
V_218 = F_110 ( V_125 ) ;
if ( ! F_73 ( V_6 , & V_219 ) ) {
V_69 = F_59 ( V_217 , V_9 ) ;
F_130 ( V_6 -> V_16 , V_69 == 1 , V_177 ) ;
error = F_111 ( V_217 , V_9 , & V_69 ) ;
if ( error )
goto V_177;
F_130 ( V_6 -> V_16 , V_69 == 1 , V_177 ) ;
}
}
if ( ! F_73 ( V_6 , & V_219 ) ) {
V_69 = F_59 ( V_217 , V_9 ) ;
F_130 ( V_6 -> V_16 , V_69 == 1 , V_177 ) ;
error = F_111 ( V_217 , V_9 , & V_69 ) ;
if ( error )
goto V_177;
V_69 = F_59 ( V_217 , V_9 ) ;
F_130 ( V_6 -> V_16 , V_69 == 1 , V_177 ) ;
V_124 = F_52 ( V_217 , V_9 , & V_214 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_124 , V_9 , V_214 ) ;
if ( error )
goto V_177;
#endif
F_75 ( V_217 , V_124 , & V_280 , V_130 ) ;
if ( F_110 ( V_124 ) - 1 >=
V_6 -> V_28 -> V_283 ( V_217 , V_9 ) ) {
error = F_131 ( V_217 , V_9 , & V_69 ) ;
if ( error )
goto V_177;
if ( V_69 ) {
ASSERT ( F_110 ( V_8 ) >=
V_6 -> V_28 -> V_283 ( V_217 , V_9 ) ) ;
F_33 ( V_217 , V_232 ) ;
V_217 = NULL ;
if ( V_9 == 0 )
V_6 -> V_81 [ 0 ] ++ ;
F_96 ( V_6 , V_168 ) ;
* V_176 = 1 ;
return 0 ;
}
}
V_215 = F_110 ( V_124 ) ;
}
F_33 ( V_217 , V_232 ) ;
V_217 = NULL ;
ASSERT ( ! F_73 ( V_6 , & V_280 ) ) ;
if ( ! F_73 ( V_6 , & V_219 ) &&
V_215 + F_110 ( V_8 ) <=
V_6 -> V_28 -> V_29 ( V_6 , V_9 ) ) {
V_234 = V_280 ;
V_125 = V_8 ;
V_216 = V_11 ;
error = F_88 ( V_6 , & V_219 , 0 , & V_124 , & V_214 ) ;
if ( error )
goto V_177;
} else if ( ! F_73 ( V_6 , & V_234 ) &&
V_218 + F_110 ( V_8 ) <=
V_6 -> V_28 -> V_29 ( V_6 , V_9 ) ) {
V_219 = V_280 ;
V_124 = V_8 ;
V_214 = V_11 ;
error = F_88 ( V_6 , & V_234 , 0 , & V_125 , & V_216 ) ;
if ( error )
goto V_177;
} else {
error = F_156 ( V_6 , V_9 , V_176 ) ;
if ( error )
goto V_177;
return 0 ;
}
V_218 = F_110 ( V_125 ) ;
V_215 = F_110 ( V_124 ) ;
F_128 ( V_6 , V_224 , V_218 ) ;
if ( V_9 > 0 ) {
union V_97 * V_225 ;
union V_54 * V_226 ;
union V_97 * V_220 ;
union V_54 * V_221 ;
V_225 = F_46 ( V_6 , V_215 + 1 , V_124 ) ;
V_226 = F_48 ( V_6 , V_215 + 1 , V_124 ) ;
V_220 = F_46 ( V_6 , 1 , V_125 ) ;
V_221 = F_48 ( V_6 , 1 , V_125 ) ;
#ifdef F_109
for ( V_69 = 1 ; V_69 < V_218 ; V_69 ++ ) {
error = F_21 ( V_6 , V_221 , V_69 , V_9 ) ;
if ( error )
goto V_177;
}
#endif
F_89 ( V_6 , V_225 , V_220 , V_218 ) ;
F_91 ( V_6 , V_226 , V_221 , V_218 ) ;
F_95 ( V_6 , V_214 , V_215 + 1 , V_215 + V_218 ) ;
F_103 ( V_6 , V_214 , V_215 + 1 , V_215 + V_218 ) ;
} else {
union V_96 * V_228 ;
union V_96 * V_222 ;
V_228 = F_45 ( V_6 , V_215 + 1 , V_124 ) ;
V_222 = F_45 ( V_6 , 1 , V_125 ) ;
F_90 ( V_6 , V_228 , V_222 , V_218 ) ;
F_102 ( V_6 , V_214 , V_215 + 1 , V_215 + V_218 ) ;
}
F_32 ( V_6 , V_284 ) ;
F_129 ( V_124 , V_215 + V_218 ) ;
F_75 ( V_6 , V_125 , & V_280 , V_130 ) ,
F_76 ( V_6 , V_124 , & V_280 , V_130 ) ;
F_104 ( V_6 , V_214 , V_230 | V_130 ) ;
F_75 ( V_6 , V_124 , & V_280 , V_130 ) ;
if ( ! F_73 ( V_6 , & V_280 ) ) {
error = F_88 ( V_6 , & V_280 , 0 , & V_239 , & V_238 ) ;
if ( error )
goto V_177;
F_76 ( V_6 , V_239 , & V_219 , V_129 ) ;
F_104 ( V_6 , V_238 , V_129 ) ;
}
error = F_30 ( V_6 , V_216 ) ;
if ( error )
goto V_177;
if ( V_11 != V_214 ) {
V_6 -> V_71 [ V_9 ] = V_214 ;
V_6 -> V_81 [ V_9 ] += V_215 ;
V_6 -> V_82 [ V_9 ] = 0 ;
}
else if ( ( V_6 -> V_49 & V_104 ) ||
( V_9 + 1 < V_6 -> V_70 ) ) {
error = F_107 ( V_6 , V_9 + 1 , & V_69 ) ;
if ( error )
goto V_177;
}
if ( V_9 > 0 )
V_6 -> V_81 [ V_9 ] -- ;
F_96 ( V_6 , V_168 ) ;
* V_176 = 2 ;
return 0 ;
V_177:
F_96 ( V_6 , V_182 ) ;
if ( V_217 )
F_33 ( V_217 , V_233 ) ;
return error ;
}
int
F_158 (
struct V_5 * V_6 ,
int * V_176 )
{
int error ;
int V_9 ;
int V_69 ;
bool V_285 = false ;
F_96 ( V_6 , V_166 ) ;
for ( V_9 = 0 , V_69 = 2 ; V_69 == 2 ; V_9 ++ ) {
error = F_157 ( V_6 , V_9 , & V_69 ) ;
if ( error )
goto V_177;
if ( V_69 == 2 )
V_285 = true ;
}
if ( V_285 && ( V_6 -> V_49 & V_200 ) ) {
error = F_122 ( V_6 , 0 ) ;
if ( error )
goto V_177;
}
if ( V_69 == 0 ) {
for ( V_9 = 1 ; V_9 < V_6 -> V_70 ; V_9 ++ ) {
if ( V_6 -> V_81 [ V_9 ] == 0 ) {
error = F_111 ( V_6 , V_9 , & V_69 ) ;
if ( error )
goto V_177;
break;
}
}
}
F_96 ( V_6 , V_168 ) ;
* V_176 = V_69 ;
return 0 ;
V_177:
F_96 ( V_6 , V_182 ) ;
return error ;
}
int
F_159 (
struct V_5 * V_6 ,
union V_96 * * V_286 ,
int * V_176 )
{
struct V_7 * V_8 ;
struct V_10 * V_11 ;
int V_55 ;
#ifdef F_109
int error ;
#endif
V_55 = V_6 -> V_81 [ 0 ] ;
V_8 = F_52 ( V_6 , 0 , & V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , 0 , V_11 ) ;
if ( error )
return error ;
#endif
if ( V_55 > F_110 ( V_8 ) || V_55 <= 0 ) {
* V_176 = 0 ;
return 0 ;
}
* V_286 = F_45 ( V_6 , V_55 , V_8 ) ;
* V_176 = 1 ;
return 0 ;
}
STATIC int
F_160 (
struct V_5 * V_6 ,
int V_9 ,
T_19 V_287 ,
void * V_288 )
{
struct V_7 * V_8 ;
struct V_10 * V_11 ;
union V_54 V_234 ;
int error ;
F_69 ( V_6 , V_9 , V_127 ) ;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
error = V_287 ( V_6 , V_9 , V_288 ) ;
if ( error )
return error ;
F_75 ( V_6 , V_8 , & V_234 , V_130 ) ;
if ( F_73 ( V_6 , & V_234 ) )
return - V_289 ;
return F_112 ( V_6 , V_9 , & V_234 , & V_8 ) ;
}
int
F_161 (
struct V_5 * V_6 ,
T_19 V_287 ,
void * V_288 )
{
union V_54 V_219 ;
int V_9 ;
struct V_7 * V_8 = NULL ;
int error = 0 ;
V_6 -> V_28 -> V_192 ( V_6 , & V_219 ) ;
for ( V_9 = V_6 -> V_70 - 1 ; V_9 >= 0 ; V_9 -- ) {
error = F_112 ( V_6 , V_9 , & V_219 , & V_8 ) ;
if ( error )
return error ;
if ( V_9 > 0 ) {
union V_54 * V_55 ;
V_55 = F_48 ( V_6 , 1 , V_8 ) ;
F_71 ( V_6 , V_55 , 1 ) ;
F_91 ( V_6 , & V_219 , V_55 , 1 ) ;
}
do {
error = F_160 ( V_6 , V_9 , V_287 , V_288 ) ;
} while ( ! error );
if ( error != - V_289 )
return error ;
}
return 0 ;
}
static int
F_162 (
struct V_5 * V_6 ,
int V_9 ,
void * V_288 )
{
struct V_290 * V_291 = V_288 ;
struct V_7 * V_8 ;
struct V_10 * V_11 ;
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
if ( V_6 -> V_49 & V_50 )
V_8 -> V_18 . V_19 . V_136 = F_5 ( V_291 -> V_292 ) ;
else
V_8 -> V_18 . V_46 . V_136 = F_16 ( V_291 -> V_292 ) ;
if ( V_11 ) {
if ( V_6 -> V_68 ) {
F_163 ( V_6 -> V_68 , V_11 ) ;
F_104 ( V_6 , V_11 , V_293 ) ;
} else {
F_164 ( V_11 , V_291 -> V_294 ) ;
}
} else {
ASSERT ( V_6 -> V_49 & V_104 ) ;
ASSERT ( V_9 == V_6 -> V_70 - 1 ) ;
}
return 0 ;
}
int
F_165 (
struct V_5 * V_6 ,
T_20 V_292 ,
struct V_295 * V_294 )
{
struct V_290 V_291 ;
V_291 . V_292 = V_292 ;
V_291 . V_294 = V_294 ;
return F_161 ( V_6 , F_162 ,
& V_291 ) ;
}
bool
F_166 (
struct V_10 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_60 -> V_61 ;
struct V_7 * V_8 = F_23 ( V_11 ) ;
struct V_296 * V_297 = V_11 -> V_298 ;
if ( ! F_3 ( & V_14 -> V_17 ) )
return false ;
if ( ! F_4 ( & V_8 -> V_18 . V_46 . V_20 , & V_14 -> V_17 . V_21 ) )
return false ;
if ( V_8 -> V_18 . V_46 . V_22 != F_5 ( V_11 -> V_23 ) )
return false ;
if ( V_297 && F_6 ( V_8 -> V_18 . V_46 . V_136 ) != V_297 -> V_299 )
return false ;
return true ;
}
bool
F_167 (
struct V_10 * V_11 ,
unsigned int V_300 )
{
struct V_13 * V_14 = V_11 -> V_60 -> V_61 ;
struct V_7 * V_8 = F_23 ( V_11 ) ;
if ( F_7 ( V_8 -> V_27 ) > V_300 )
return false ;
if ( ! V_8 -> V_18 . V_46 . V_30 ||
( F_6 ( V_8 -> V_18 . V_46 . V_30 ) >= V_14 -> V_17 . V_53 &&
V_8 -> V_18 . V_46 . V_30 != F_16 ( V_47 ) ) )
return false ;
if ( ! V_8 -> V_18 . V_46 . V_32 ||
( F_6 ( V_8 -> V_18 . V_46 . V_32 ) >= V_14 -> V_17 . V_53 &&
V_8 -> V_18 . V_46 . V_32 != F_16 ( V_47 ) ) )
return false ;
return true ;
}
T_10
F_168 (
struct V_13 * V_14 ,
T_10 * V_301 ,
unsigned long V_302 )
{
T_10 V_9 ;
unsigned long V_303 ;
V_303 = ( V_302 + V_301 [ 0 ] - 1 ) / V_301 [ 0 ] ;
for ( V_9 = 1 ; V_303 > 1 ; V_9 ++ )
V_303 = ( V_303 + V_301 [ 1 ] - 1 ) / V_301 [ 1 ] ;
return V_9 ;
}
STATIC int
F_169 (
struct V_5 * V_6 ,
union V_97 * V_304 ,
union V_97 * V_305 ,
T_21 V_287 ,
void * V_306 )
{
union V_96 * V_286 ;
union V_97 V_307 ;
T_13 V_190 ;
int V_176 ;
bool V_308 = true ;
int error ;
ASSERT ( V_6 -> V_28 -> V_203 ) ;
ASSERT ( V_6 -> V_28 -> V_204 ) ;
V_176 = 0 ;
error = F_114 ( V_6 , V_195 , & V_176 ) ;
if ( error )
goto V_309;
if ( ! V_176 ) {
error = F_107 ( V_6 , 0 , & V_176 ) ;
if ( error )
goto V_309;
}
while ( V_176 ) {
error = F_159 ( V_6 , & V_286 , & V_176 ) ;
if ( error || ! V_176 )
break;
if ( V_308 ) {
V_6 -> V_28 -> V_203 ( & V_307 , V_286 ) ;
V_308 = false ;
V_190 = V_6 -> V_28 -> V_204 ( V_6 , V_304 ,
& V_307 ) ;
if ( V_190 > 0 )
goto V_310;
}
V_6 -> V_28 -> V_189 ( & V_307 , V_286 ) ;
V_190 = V_6 -> V_28 -> V_204 ( V_6 , & V_307 , V_305 ) ;
if ( V_190 > 0 )
break;
error = V_287 ( V_6 , V_286 , V_306 ) ;
if ( error < 0 || error == V_311 )
break;
V_310:
error = F_107 ( V_6 , 0 , & V_176 ) ;
if ( error )
break;
}
V_309:
return error ;
}
STATIC int
F_170 (
struct V_5 * V_6 ,
union V_97 * V_304 ,
union V_97 * V_305 ,
T_21 V_287 ,
void * V_306 )
{
union V_54 V_55 ;
union V_54 * V_184 ;
union V_97 V_307 ;
union V_97 V_312 ;
union V_97 * V_225 ;
union V_97 * V_313 ;
union V_96 * V_286 ;
struct V_7 * V_8 ;
T_13 V_314 ;
T_13 V_315 ;
int V_9 ;
struct V_10 * V_11 ;
int V_69 ;
int error ;
V_9 = V_6 -> V_70 - 1 ;
V_6 -> V_28 -> V_192 ( V_6 , & V_55 ) ;
error = F_112 ( V_6 , V_9 , & V_55 , & V_8 ) ;
if ( error )
return error ;
F_52 ( V_6 , V_9 , & V_11 ) ;
F_171 ( V_6 , V_9 , V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error )
goto V_309;
#endif
V_6 -> V_81 [ V_9 ] = 1 ;
while ( V_9 < V_6 -> V_70 ) {
V_8 = F_52 ( V_6 , V_9 , & V_11 ) ;
if ( V_6 -> V_81 [ V_9 ] > F_7 ( V_8 -> V_27 ) ) {
V_316:
if ( V_9 < V_6 -> V_70 - 1 )
V_6 -> V_81 [ V_9 + 1 ] ++ ;
V_9 ++ ;
continue;
}
if ( V_9 == 0 ) {
V_286 = F_45 ( V_6 , V_6 -> V_81 [ 0 ] , V_8 ) ;
V_6 -> V_28 -> V_203 ( & V_312 , V_286 ) ;
V_314 = V_6 -> V_28 -> V_204 ( V_6 , & V_312 ,
V_304 ) ;
V_6 -> V_28 -> V_189 ( & V_307 , V_286 ) ;
V_315 = V_6 -> V_28 -> V_204 ( V_6 , V_305 ,
& V_307 ) ;
if ( V_314 >= 0 && V_315 >= 0 ) {
error = V_287 ( V_6 , V_286 , V_306 ) ;
if ( error < 0 ||
error == V_311 )
break;
} else if ( V_315 < 0 ) {
goto V_316;
}
V_6 -> V_81 [ V_9 ] ++ ;
continue;
}
V_225 = F_46 ( V_6 , V_6 -> V_81 [ V_9 ] , V_8 ) ;
V_313 = F_47 ( V_6 , V_6 -> V_81 [ V_9 ] , V_8 ) ;
V_184 = F_48 ( V_6 , V_6 -> V_81 [ V_9 ] , V_8 ) ;
V_314 = V_6 -> V_28 -> V_204 ( V_6 , V_313 , V_304 ) ;
V_315 = V_6 -> V_28 -> V_204 ( V_6 , V_305 , V_225 ) ;
if ( V_314 >= 0 && V_315 >= 0 ) {
V_9 -- ;
error = F_112 ( V_6 , V_9 , V_184 ,
& V_8 ) ;
if ( error )
goto V_309;
F_52 ( V_6 , V_9 , & V_11 ) ;
F_171 ( V_6 , V_9 , V_11 ) ;
#ifdef F_109
error = F_17 ( V_6 , V_8 , V_9 , V_11 ) ;
if ( error )
goto V_309;
#endif
V_6 -> V_81 [ V_9 ] = 1 ;
continue;
} else if ( V_315 < 0 ) {
goto V_316;
}
V_6 -> V_81 [ V_9 ] ++ ;
}
V_309:
if ( V_6 -> V_71 [ 0 ] == NULL ) {
for ( V_69 = 0 ; V_69 < V_6 -> V_70 ; V_69 ++ ) {
if ( V_6 -> V_71 [ V_69 ] ) {
F_34 ( V_6 -> V_68 , V_6 -> V_71 [ V_69 ] ) ;
V_6 -> V_71 [ V_69 ] = NULL ;
V_6 -> V_81 [ V_69 ] = 0 ;
V_6 -> V_82 [ V_69 ] = 0 ;
}
}
}
return error ;
}
int
F_172 (
struct V_5 * V_6 ,
union V_317 * V_318 ,
union V_317 * V_319 ,
T_21 V_287 ,
void * V_306 )
{
union V_96 V_165 ;
union V_97 V_304 ;
union V_97 V_305 ;
V_6 -> V_80 = * V_319 ;
V_6 -> V_28 -> V_277 ( V_6 , & V_165 ) ;
V_6 -> V_28 -> V_189 ( & V_305 , & V_165 ) ;
V_6 -> V_80 = * V_318 ;
V_6 -> V_28 -> V_277 ( V_6 , & V_165 ) ;
V_6 -> V_28 -> V_189 ( & V_304 , & V_165 ) ;
if ( V_6 -> V_28 -> V_204 ( V_6 , & V_304 , & V_305 ) > 0 )
return - V_320 ;
if ( ! ( V_6 -> V_49 & V_200 ) )
return F_169 ( V_6 , & V_304 ,
& V_305 , V_287 , V_306 ) ;
return F_170 ( V_6 , & V_304 , & V_305 ,
V_287 , V_306 ) ;
}
int
F_173 (
struct V_5 * V_6 ,
T_21 V_287 ,
void * V_306 )
{
union V_97 V_304 ;
union V_97 V_305 ;
memset ( & V_6 -> V_80 , 0 , sizeof( V_6 -> V_80 ) ) ;
memset ( & V_304 , 0 , sizeof( V_304 ) ) ;
memset ( & V_305 , 0xFF , sizeof( V_305 ) ) ;
return F_169 ( V_6 , & V_304 , & V_305 , V_287 , V_306 ) ;
}
T_14
F_174 (
struct V_13 * V_14 ,
T_10 * V_301 ,
unsigned long long V_302 )
{
int V_9 ;
int V_321 ;
T_14 V_123 ;
V_321 = V_301 [ 0 ] ;
for ( V_9 = 0 , V_123 = 0 ; V_302 > 1 ; V_9 ++ ) {
V_302 += V_321 - 1 ;
F_175 ( V_302 , V_321 ) ;
V_321 = V_301 [ 1 ] ;
V_123 += V_302 ;
}
return V_123 ;
}
static int
F_176 (
struct V_5 * V_6 ,
int V_9 ,
void * V_288 )
{
T_14 * V_322 = V_288 ;
( * V_322 ) ++ ;
return 0 ;
}
int
F_177 (
struct V_5 * V_6 ,
T_14 * V_322 )
{
* V_322 = 0 ;
return F_161 ( V_6 , F_176 ,
V_322 ) ;
}
