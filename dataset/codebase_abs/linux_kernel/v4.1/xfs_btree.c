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
F_3 ( & V_4 -> V_13 . V_42 . V_15 , & V_10 -> V_12 . V_16 ) &&
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
if ( F_2 ( & V_7 -> V_57 -> V_58 -> V_12 ) )
return F_26 ( V_7 , V_62 ) ;
return true ;
}
void
F_27 (
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
F_28 (
struct V_6 * V_7 )
{
if ( F_2 ( & V_7 -> V_57 -> V_58 -> V_12 ) )
return F_26 ( V_7 , V_63 ) ;
return true ;
}
void
F_29 (
T_3 * V_2 ,
int error )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_2 -> V_65 ; V_64 ++ ) {
if ( V_2 -> V_66 [ V_64 ] )
F_30 ( V_2 -> V_67 , V_2 -> V_66 [ V_64 ] ) ;
else if ( ! error )
break;
}
ASSERT ( V_2 -> V_68 != V_69 ||
V_2 -> V_39 . V_70 . V_71 == 0 ) ;
F_31 ( V_72 , V_2 ) ;
}
int
F_32 (
T_3 * V_2 ,
T_3 * * V_73 )
{
T_4 * V_7 ;
int error ;
int V_64 ;
T_5 * V_10 ;
T_3 * V_74 ;
T_6 * V_75 ;
V_75 = V_2 -> V_67 ;
V_10 = V_2 -> V_11 ;
V_74 = V_2 -> V_23 -> V_76 ( V_2 ) ;
V_74 -> V_77 = V_2 -> V_77 ;
for ( V_64 = 0 ; V_64 < V_74 -> V_65 ; V_64 ++ ) {
V_74 -> V_78 [ V_64 ] = V_2 -> V_78 [ V_64 ] ;
V_74 -> V_79 [ V_64 ] = V_2 -> V_79 [ V_64 ] ;
V_7 = V_2 -> V_66 [ V_64 ] ;
if ( V_7 ) {
error = F_33 ( V_10 , V_75 , V_10 -> V_80 ,
F_34 ( V_7 ) , V_10 -> V_81 ,
0 , & V_7 ,
V_2 -> V_23 -> V_82 ) ;
if ( error ) {
F_29 ( V_74 , error ) ;
* V_73 = NULL ;
return error ;
}
}
V_74 -> V_66 [ V_64 ] = V_7 ;
}
* V_73 = V_74 ;
return 0 ;
}
static inline T_7 F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 & V_47 ) {
if ( V_2 -> V_46 & V_83 )
return V_84 ;
return V_85 ;
}
if ( V_2 -> V_46 & V_83 )
return V_86 ;
return V_87 ;
}
static inline T_7 F_36 ( struct V_1 * V_2 )
{
return ( V_2 -> V_46 & V_47 ) ?
sizeof( V_88 ) : sizeof( V_89 ) ;
}
STATIC T_7
F_37 (
struct V_1 * V_2 ,
int V_90 )
{
return F_35 ( V_2 ) +
( V_90 - 1 ) * V_2 -> V_23 -> V_91 ;
}
STATIC T_7
F_38 (
struct V_1 * V_2 ,
int V_90 )
{
return F_35 ( V_2 ) +
( V_90 - 1 ) * V_2 -> V_23 -> V_92 ;
}
STATIC T_7
F_39 (
struct V_1 * V_2 ,
int V_90 ,
int V_5 )
{
return F_35 ( V_2 ) +
V_2 -> V_23 -> V_24 ( V_2 , V_5 ) * V_2 -> V_23 -> V_92 +
( V_90 - 1 ) * F_36 ( V_2 ) ;
}
STATIC union V_93 *
F_40 (
struct V_1 * V_2 ,
int V_90 ,
struct V_3 * V_4 )
{
return (union V_93 * )
( ( char * ) V_4 + F_37 ( V_2 , V_90 ) ) ;
}
STATIC union V_94 *
F_41 (
struct V_1 * V_2 ,
int V_90 ,
struct V_3 * V_4 )
{
return (union V_94 * )
( ( char * ) V_4 + F_38 ( V_2 , V_90 ) ) ;
}
STATIC union V_51 *
F_42 (
struct V_1 * V_2 ,
int V_90 ,
struct V_3 * V_4 )
{
int V_5 = F_43 ( V_4 ) ;
ASSERT ( V_4 -> V_21 != 0 ) ;
return (union V_51 * )
( ( char * ) V_4 + F_39 ( V_2 , V_90 , V_5 ) ) ;
}
STATIC struct V_3 *
F_44 (
struct V_1 * V_2 )
{
struct V_95 * V_96 ;
V_96 = F_45 ( V_2 -> V_39 . V_70 . V_97 , V_2 -> V_39 . V_70 . V_98 ) ;
return (struct V_3 * ) V_96 -> V_99 ;
}
STATIC struct V_3 *
F_46 (
struct V_1 * V_2 ,
int V_5 ,
struct V_6 * * V_100 )
{
if ( ( V_2 -> V_46 & V_101 ) &&
( V_5 == V_2 -> V_65 - 1 ) ) {
* V_100 = NULL ;
return F_44 ( V_2 ) ;
}
* V_100 = V_2 -> V_66 [ V_5 ] ;
return F_23 ( * V_100 ) ;
}
T_4 *
F_47 (
T_5 * V_10 ,
T_6 * V_75 ,
T_2 V_102 ,
T_8 V_103 )
{
T_9 V_104 ;
ASSERT ( V_102 != V_26 ) ;
V_104 = F_48 ( V_10 , V_102 ) ;
return F_49 ( V_75 , V_10 -> V_80 , V_104 , V_10 -> V_81 , V_103 ) ;
}
T_4 *
F_50 (
T_5 * V_10 ,
T_6 * V_75 ,
T_10 V_105 ,
T_1 V_106 ,
T_8 V_103 )
{
T_9 V_104 ;
ASSERT ( V_105 != V_107 ) ;
ASSERT ( V_106 != V_43 ) ;
V_104 = F_51 ( V_10 , V_105 , V_106 ) ;
return F_49 ( V_75 , V_10 -> V_80 , V_104 , V_10 -> V_81 , V_103 ) ;
}
int
F_52 (
T_3 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
V_4 = F_46 ( V_2 , V_5 , & V_7 ) ;
F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( V_2 -> V_46 & V_47 )
return V_4 -> V_13 . V_14 . V_27 == F_4 ( V_26 ) ;
else
return V_4 -> V_13 . V_42 . V_27 == F_16 ( V_43 ) ;
}
STATIC int
F_53 (
T_3 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
V_4 = F_46 ( V_2 , V_5 , & V_7 ) ;
F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( ! V_4 -> V_22 )
return 0 ;
V_2 -> V_78 [ V_5 ] = 1 ;
return 1 ;
}
STATIC int
F_54 (
T_3 * V_2 ,
int V_5 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
V_4 = F_46 ( V_2 , V_5 , & V_7 ) ;
F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( ! V_4 -> V_22 )
return 0 ;
V_2 -> V_78 [ V_5 ] = F_7 ( V_4 -> V_22 ) ;
return 1 ;
}
void
F_55 (
T_11 V_108 ,
const short * V_109 ,
int V_110 ,
int * V_111 ,
int * V_112 )
{
int V_64 ;
T_11 V_113 ;
ASSERT ( V_108 != 0 ) ;
for ( V_64 = 0 , V_113 = 1LL ; ; V_64 ++ , V_113 <<= 1 ) {
if ( V_113 & V_108 ) {
* V_111 = V_109 [ V_64 ] ;
break;
}
}
for ( V_64 = V_110 - 1 , V_113 = 1LL << V_64 ; ; V_64 -- , V_113 >>= 1 ) {
if ( V_113 & V_108 ) {
* V_112 = V_109 [ V_64 + 1 ] - 1 ;
break;
}
}
}
int
F_56 (
struct V_9 * V_10 ,
struct V_114 * V_75 ,
T_2 V_102 ,
T_8 V_103 ,
struct V_6 * * V_100 ,
int V_115 ,
const struct V_116 * V_117 )
{
struct V_6 * V_7 ;
T_9 V_104 ;
int error ;
ASSERT ( V_102 != V_26 ) ;
V_104 = F_48 ( V_10 , V_102 ) ;
error = F_33 ( V_10 , V_75 , V_10 -> V_80 , V_104 ,
V_10 -> V_81 , V_103 , & V_7 , V_117 ) ;
if ( error )
return error ;
if ( V_7 )
F_57 ( V_7 , V_115 ) ;
* V_100 = V_7 ;
return 0 ;
}
void
F_58 (
struct V_9 * V_10 ,
T_2 V_102 ,
T_12 V_118 ,
const struct V_116 * V_117 )
{
T_9 V_104 ;
ASSERT ( V_102 != V_26 ) ;
V_104 = F_48 ( V_10 , V_102 ) ;
F_59 ( V_10 -> V_80 , V_104 , V_10 -> V_81 * V_118 , V_117 ) ;
}
void
F_60 (
struct V_9 * V_10 ,
T_10 V_105 ,
T_1 V_106 ,
T_12 V_118 ,
const struct V_116 * V_117 )
{
T_9 V_104 ;
ASSERT ( V_105 != V_107 ) ;
ASSERT ( V_106 != V_43 ) ;
V_104 = F_51 ( V_10 , V_105 , V_106 ) ;
F_59 ( V_10 -> V_80 , V_104 , V_10 -> V_81 * V_118 , V_117 ) ;
}
STATIC int
F_61 (
struct V_1 * V_2 ,
int V_119 ,
struct V_3 * V_4 )
{
int V_120 = 0 ;
T_2 V_121 = F_9 ( V_4 -> V_13 . V_14 . V_25 ) ;
T_2 V_122 = F_9 ( V_4 -> V_13 . V_14 . V_27 ) ;
if ( ( V_119 & V_123 ) && V_121 != V_26 ) {
F_58 ( V_2 -> V_11 , V_121 , 1 ,
V_2 -> V_23 -> V_82 ) ;
V_120 ++ ;
}
if ( ( V_119 & V_124 ) && V_122 != V_26 ) {
F_58 ( V_2 -> V_11 , V_122 , 1 ,
V_2 -> V_23 -> V_82 ) ;
V_120 ++ ;
}
return V_120 ;
}
STATIC int
F_62 (
struct V_1 * V_2 ,
int V_119 ,
struct V_3 * V_4 )
{
int V_120 = 0 ;
T_1 V_121 = F_5 ( V_4 -> V_13 . V_42 . V_25 ) ;
T_1 V_122 = F_5 ( V_4 -> V_13 . V_42 . V_27 ) ;
if ( ( V_119 & V_123 ) && V_121 != V_43 ) {
F_60 ( V_2 -> V_11 , V_2 -> V_39 . V_40 . V_105 ,
V_121 , 1 , V_2 -> V_23 -> V_82 ) ;
V_120 ++ ;
}
if ( ( V_119 & V_124 ) && V_122 != V_43 ) {
F_60 ( V_2 -> V_11 , V_2 -> V_39 . V_40 . V_105 ,
V_122 , 1 , V_2 -> V_23 -> V_82 ) ;
V_120 ++ ;
}
return V_120 ;
}
STATIC int
F_63 (
struct V_1 * V_2 ,
int V_125 ,
int V_119 )
{
struct V_3 * V_4 ;
if ( ( V_2 -> V_46 & V_101 ) &&
( V_125 == V_2 -> V_65 - 1 ) )
return 0 ;
if ( ( V_2 -> V_79 [ V_125 ] | V_119 ) == V_2 -> V_79 [ V_125 ] )
return 0 ;
V_2 -> V_79 [ V_125 ] |= V_119 ;
V_4 = F_23 ( V_2 -> V_66 [ V_125 ] ) ;
if ( V_2 -> V_46 & V_47 )
return F_61 ( V_2 , V_119 , V_4 ) ;
return F_62 ( V_2 , V_119 , V_4 ) ;
}
STATIC T_9
F_64 (
struct V_1 * V_2 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 ) {
ASSERT ( V_52 -> V_14 != F_4 ( V_26 ) ) ;
return F_48 ( V_2 -> V_11 , F_9 ( V_52 -> V_14 ) ) ;
} else {
ASSERT ( V_2 -> V_39 . V_40 . V_105 != V_107 ) ;
ASSERT ( V_52 -> V_42 != F_16 ( V_43 ) ) ;
return F_51 ( V_2 -> V_11 , V_2 -> V_39 . V_40 . V_105 ,
F_5 ( V_52 -> V_42 ) ) ;
}
}
STATIC void
F_65 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
T_12 V_118 )
{
F_59 ( V_2 -> V_11 -> V_80 ,
F_64 ( V_2 , V_52 ) ,
V_2 -> V_11 -> V_81 * V_118 , V_2 -> V_23 -> V_82 ) ;
}
STATIC void
F_66 (
T_3 * V_2 ,
int V_125 ,
T_4 * V_7 )
{
struct V_3 * V_70 ;
if ( V_2 -> V_66 [ V_125 ] )
F_30 ( V_2 -> V_67 , V_2 -> V_66 [ V_125 ] ) ;
V_2 -> V_66 [ V_125 ] = V_7 ;
V_2 -> V_79 [ V_125 ] = 0 ;
V_70 = F_23 ( V_7 ) ;
if ( V_2 -> V_46 & V_47 ) {
if ( V_70 -> V_13 . V_14 . V_25 == F_4 ( V_26 ) )
V_2 -> V_79 [ V_125 ] |= V_123 ;
if ( V_70 -> V_13 . V_14 . V_27 == F_4 ( V_26 ) )
V_2 -> V_79 [ V_125 ] |= V_124 ;
} else {
if ( V_70 -> V_13 . V_42 . V_25 == F_16 ( V_43 ) )
V_2 -> V_79 [ V_125 ] |= V_123 ;
if ( V_70 -> V_13 . V_42 . V_27 == F_16 ( V_43 ) )
V_2 -> V_79 [ V_125 ] |= V_124 ;
}
}
STATIC int
F_67 (
struct V_1 * V_2 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 )
return V_52 -> V_14 == F_4 ( V_26 ) ;
else
return V_52 -> V_42 == F_16 ( V_43 ) ;
}
STATIC void
F_68 (
struct V_1 * V_2 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 )
V_52 -> V_14 = F_4 ( V_26 ) ;
else
V_52 -> V_42 = F_16 ( V_43 ) ;
}
STATIC void
F_69 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_51 * V_52 ,
int V_119 )
{
ASSERT ( V_119 == V_126 || V_119 == V_127 ) ;
if ( V_2 -> V_46 & V_47 ) {
if ( V_119 == V_127 )
V_52 -> V_14 = V_4 -> V_13 . V_14 . V_27 ;
else
V_52 -> V_14 = V_4 -> V_13 . V_14 . V_25 ;
} else {
if ( V_119 == V_127 )
V_52 -> V_42 = V_4 -> V_13 . V_42 . V_27 ;
else
V_52 -> V_42 = V_4 -> V_13 . V_42 . V_25 ;
}
}
STATIC void
F_70 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_51 * V_52 ,
int V_119 )
{
ASSERT ( V_119 == V_126 || V_119 == V_127 ) ;
if ( V_2 -> V_46 & V_47 ) {
if ( V_119 == V_127 )
V_4 -> V_13 . V_14 . V_27 = V_52 -> V_14 ;
else
V_4 -> V_13 . V_14 . V_25 = V_52 -> V_14 ;
} else {
if ( V_119 == V_127 )
V_4 -> V_13 . V_42 . V_27 = V_52 -> V_42 ;
else
V_4 -> V_13 . V_42 . V_25 = V_52 -> V_42 ;
}
}
void
F_71 (
struct V_9 * V_10 ,
struct V_3 * V_128 ,
T_9 V_129 ,
T_13 V_130 ,
T_14 V_5 ,
T_14 V_131 ,
T_15 V_132 ,
unsigned int V_133 )
{
V_128 -> V_20 = F_16 ( V_130 ) ;
V_128 -> V_21 = F_72 ( V_5 ) ;
V_128 -> V_22 = F_72 ( V_131 ) ;
if ( V_133 & V_47 ) {
V_128 -> V_13 . V_14 . V_25 = F_4 ( V_26 ) ;
V_128 -> V_13 . V_14 . V_27 = F_4 ( V_26 ) ;
if ( V_133 & V_83 ) {
V_128 -> V_13 . V_14 . V_17 = F_4 ( V_129 ) ;
V_128 -> V_13 . V_14 . V_134 = F_4 ( V_132 ) ;
F_73 ( & V_128 -> V_13 . V_14 . V_15 , & V_10 -> V_12 . V_16 ) ;
V_128 -> V_13 . V_14 . V_135 = 0 ;
V_128 -> V_13 . V_14 . V_59 = 0 ;
}
} else {
T_13 V_136 = ( T_13 ) V_132 ;
V_128 -> V_13 . V_42 . V_25 = F_16 ( V_43 ) ;
V_128 -> V_13 . V_42 . V_27 = F_16 ( V_43 ) ;
if ( V_133 & V_83 ) {
V_128 -> V_13 . V_42 . V_17 = F_4 ( V_129 ) ;
V_128 -> V_13 . V_42 . V_134 = F_16 ( V_136 ) ;
F_73 ( & V_128 -> V_13 . V_42 . V_15 , & V_10 -> V_12 . V_16 ) ;
V_128 -> V_13 . V_42 . V_59 = 0 ;
}
}
}
void
F_74 (
struct V_9 * V_10 ,
struct V_6 * V_7 ,
T_13 V_130 ,
T_14 V_5 ,
T_14 V_131 ,
T_15 V_132 ,
unsigned int V_133 )
{
F_71 ( V_10 , F_23 ( V_7 ) , V_7 -> V_18 ,
V_130 , V_5 , V_131 , V_132 , V_133 ) ;
}
STATIC void
F_75 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_5 ,
int V_131 )
{
T_15 V_132 ;
if ( V_2 -> V_46 & V_47 )
V_132 = V_2 -> V_39 . V_70 . V_97 -> V_137 ;
else
V_132 = V_2 -> V_39 . V_40 . V_105 ;
F_71 ( V_2 -> V_11 , F_23 ( V_7 ) , V_7 -> V_18 ,
F_6 ( V_2 ) , V_5 , V_131 ,
V_132 , V_2 -> V_46 ) ;
}
STATIC int
F_76 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
union V_51 V_52 ;
if ( V_5 > 0 )
return 0 ;
if ( ! ( V_2 -> V_46 & V_138 ) )
return 0 ;
F_69 ( V_2 , V_4 , & V_52 , V_127 ) ;
if ( ! F_67 ( V_2 , & V_52 ) )
return 0 ;
return 1 ;
}
STATIC void
F_77 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
union V_51 * V_52 )
{
if ( V_2 -> V_46 & V_47 )
V_52 -> V_14 = F_4 ( F_78 ( V_2 -> V_11 ,
F_34 ( V_7 ) ) ) ;
else {
V_52 -> V_42 = F_16 ( F_79 ( V_2 -> V_11 ,
F_34 ( V_7 ) ) ) ;
}
}
STATIC void
F_80 (
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
switch ( V_2 -> V_68 ) {
case V_139 :
case V_140 :
F_57 ( V_7 , V_141 ) ;
break;
case V_142 :
case V_143 :
F_57 ( V_7 , V_144 ) ;
break;
case V_69 :
F_57 ( V_7 , V_145 ) ;
break;
default:
ASSERT ( 0 ) ;
}
}
STATIC int
F_81 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
int V_133 ,
struct V_3 * * V_4 ,
struct V_6 * * V_100 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_9 V_104 ;
ASSERT ( ! ( V_133 & V_146 ) ) ;
V_104 = F_64 ( V_2 , V_52 ) ;
* V_100 = F_49 ( V_2 -> V_67 , V_10 -> V_80 , V_104 ,
V_10 -> V_81 , V_133 ) ;
if ( ! * V_100 )
return - V_147 ;
( * V_100 ) -> V_148 = V_2 -> V_23 -> V_82 ;
* V_4 = F_23 ( * V_100 ) ;
return 0 ;
}
STATIC int
F_82 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
int V_133 ,
struct V_3 * * V_4 ,
struct V_6 * * V_100 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_9 V_104 ;
int error ;
ASSERT ( ! ( V_133 & V_146 ) ) ;
V_104 = F_64 ( V_2 , V_52 ) ;
error = F_33 ( V_10 , V_2 -> V_67 , V_10 -> V_80 , V_104 ,
V_10 -> V_81 , V_133 , V_100 ,
V_2 -> V_23 -> V_82 ) ;
if ( error )
return error ;
F_80 ( V_2 , * V_100 ) ;
* V_4 = F_23 ( * V_100 ) ;
return 0 ;
}
STATIC void
F_83 (
struct V_1 * V_2 ,
union V_94 * V_149 ,
union V_94 * V_150 ,
int V_151 )
{
ASSERT ( V_151 >= 0 ) ;
memcpy ( V_149 , V_150 , V_151 * V_2 -> V_23 -> V_92 ) ;
}
STATIC void
F_84 (
struct V_1 * V_2 ,
union V_93 * V_152 ,
union V_93 * V_153 ,
int V_131 )
{
ASSERT ( V_131 >= 0 ) ;
memcpy ( V_152 , V_153 , V_131 * V_2 -> V_23 -> V_91 ) ;
}
STATIC void
F_85 (
struct V_1 * V_2 ,
union V_51 * V_154 ,
union V_51 * V_155 ,
int V_156 )
{
ASSERT ( V_156 >= 0 ) ;
memcpy ( V_154 , V_155 , V_156 * F_36 ( V_2 ) ) ;
}
STATIC void
F_86 (
struct V_1 * V_2 ,
union V_94 * V_157 ,
int V_158 ,
int V_151 )
{
char * V_149 ;
ASSERT ( V_151 >= 0 ) ;
ASSERT ( V_158 == 1 || V_158 == - 1 ) ;
V_149 = ( char * ) V_157 + ( V_158 * V_2 -> V_23 -> V_92 ) ;
memmove ( V_149 , V_157 , V_151 * V_2 -> V_23 -> V_92 ) ;
}
STATIC void
F_87 (
struct V_1 * V_2 ,
union V_93 * V_159 ,
int V_158 ,
int V_131 )
{
char * V_152 ;
ASSERT ( V_131 >= 0 ) ;
ASSERT ( V_158 == 1 || V_158 == - 1 ) ;
V_152 = ( char * ) V_159 + ( V_158 * V_2 -> V_23 -> V_91 ) ;
memmove ( V_152 , V_159 , V_131 * V_2 -> V_23 -> V_91 ) ;
}
STATIC void
F_88 (
struct V_1 * V_2 ,
union V_51 * V_52 ,
int V_158 ,
int V_156 )
{
char * V_154 ;
ASSERT ( V_156 >= 0 ) ;
ASSERT ( V_158 == 1 || V_158 == - 1 ) ;
V_154 = ( char * ) V_52 + ( V_158 * F_36 ( V_2 ) ) ;
memmove ( V_154 , V_52 , V_156 * F_36 ( V_2 ) ) ;
}
STATIC void
F_89 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_111 ,
int V_112 )
{
F_90 ( V_2 , V_160 ) ;
F_91 ( V_2 , V_7 , V_111 , V_112 ) ;
if ( V_7 ) {
F_92 ( V_2 -> V_67 , V_7 , V_161 ) ;
F_93 ( V_2 -> V_67 , V_7 ,
F_38 ( V_2 , V_111 ) ,
F_38 ( V_2 , V_112 + 1 ) - 1 ) ;
} else {
F_94 ( V_2 -> V_67 , V_2 -> V_39 . V_70 . V_97 ,
F_95 ( V_2 -> V_39 . V_70 . V_98 ) ) ;
}
F_90 ( V_2 , V_162 ) ;
}
void
F_96 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_111 ,
int V_112 )
{
F_90 ( V_2 , V_160 ) ;
F_91 ( V_2 , V_7 , V_111 , V_112 ) ;
F_92 ( V_2 -> V_67 , V_7 , V_161 ) ;
F_93 ( V_2 -> V_67 , V_7 ,
F_37 ( V_2 , V_111 ) ,
F_37 ( V_2 , V_112 + 1 ) - 1 ) ;
F_90 ( V_2 , V_162 ) ;
}
STATIC void
F_97 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_111 ,
int V_112 )
{
F_90 ( V_2 , V_160 ) ;
F_91 ( V_2 , V_7 , V_111 , V_112 ) ;
if ( V_7 ) {
struct V_3 * V_4 = F_23 ( V_7 ) ;
int V_5 = F_43 ( V_4 ) ;
F_92 ( V_2 -> V_67 , V_7 , V_161 ) ;
F_93 ( V_2 -> V_67 , V_7 ,
F_39 ( V_2 , V_111 , V_5 ) ,
F_39 ( V_2 , V_112 + 1 , V_5 ) - 1 ) ;
} else {
F_94 ( V_2 -> V_67 , V_2 -> V_39 . V_70 . V_97 ,
F_95 ( V_2 -> V_39 . V_70 . V_98 ) ) ;
}
F_90 ( V_2 , V_162 ) ;
}
void
F_98 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_108 )
{
int V_111 ;
int V_112 ;
static const short V_163 [] = {
F_99 ( struct V_3 , V_20 ) ,
F_99 ( struct V_3 , V_21 ) ,
F_99 ( struct V_3 , V_22 ) ,
F_99 ( struct V_3 , V_13 . V_42 . V_25 ) ,
F_99 ( struct V_3 , V_13 . V_42 . V_27 ) ,
F_99 ( struct V_3 , V_13 . V_42 . V_17 ) ,
F_99 ( struct V_3 , V_13 . V_42 . V_59 ) ,
F_99 ( struct V_3 , V_13 . V_42 . V_15 ) ,
F_99 ( struct V_3 , V_13 . V_42 . V_134 ) ,
F_99 ( struct V_3 , V_13 . V_42 . V_164 ) ,
V_86
} ;
static const short V_165 [] = {
F_99 ( struct V_3 , V_20 ) ,
F_99 ( struct V_3 , V_21 ) ,
F_99 ( struct V_3 , V_22 ) ,
F_99 ( struct V_3 , V_13 . V_14 . V_25 ) ,
F_99 ( struct V_3 , V_13 . V_14 . V_27 ) ,
F_99 ( struct V_3 , V_13 . V_14 . V_17 ) ,
F_99 ( struct V_3 , V_13 . V_14 . V_59 ) ,
F_99 ( struct V_3 , V_13 . V_14 . V_15 ) ,
F_99 ( struct V_3 , V_13 . V_14 . V_134 ) ,
F_99 ( struct V_3 , V_13 . V_14 . V_164 ) ,
F_99 ( struct V_3 , V_13 . V_14 . V_135 ) ,
V_84
} ;
F_90 ( V_2 , V_160 ) ;
F_100 ( V_2 , V_7 , V_108 ) ;
if ( V_7 ) {
int V_110 ;
if ( V_2 -> V_46 & V_83 ) {
if ( V_108 == V_166 )
V_108 = V_167 ;
V_110 = V_168 ;
} else {
V_110 = V_169 ;
}
F_55 ( V_108 ,
( V_2 -> V_46 & V_47 ) ?
V_165 : V_163 ,
V_110 , & V_111 , & V_112 ) ;
F_92 ( V_2 -> V_67 , V_7 , V_161 ) ;
F_93 ( V_2 -> V_67 , V_7 , V_111 , V_112 ) ;
} else {
F_94 ( V_2 -> V_67 , V_2 -> V_39 . V_70 . V_97 ,
F_95 ( V_2 -> V_39 . V_70 . V_98 ) ) ;
}
F_90 ( V_2 , V_162 ) ;
}
int
F_101 (
struct V_1 * V_2 ,
int V_5 ,
int * V_170 )
{
struct V_3 * V_4 ;
union V_51 V_52 ;
struct V_6 * V_7 ;
int error ;
int V_125 ;
F_90 ( V_2 , V_160 ) ;
F_102 ( V_2 , V_5 ) ;
ASSERT ( V_5 < V_2 -> V_65 ) ;
F_63 ( V_2 , V_5 , V_124 ) ;
V_4 = F_46 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_103
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_171;
#endif
if ( ++ V_2 -> V_78 [ V_5 ] <= F_104 ( V_4 ) )
goto V_172;
F_69 ( V_2 , V_4 , & V_52 , V_127 ) ;
if ( F_67 ( V_2 , & V_52 ) )
goto V_173;
F_105 ( V_2 , V_174 ) ;
for ( V_125 = V_5 + 1 ; V_125 < V_2 -> V_65 ; V_125 ++ ) {
V_4 = F_46 ( V_2 , V_125 , & V_7 ) ;
#ifdef F_103
error = F_17 ( V_2 , V_4 , V_125 , V_7 ) ;
if ( error )
goto V_171;
#endif
if ( ++ V_2 -> V_78 [ V_125 ] <= F_104 ( V_4 ) )
break;
F_63 ( V_2 , V_125 , V_124 ) ;
}
if ( V_125 == V_2 -> V_65 ) {
if ( V_2 -> V_46 & V_101 )
goto V_173;
ASSERT ( 0 ) ;
error = - V_33 ;
goto V_171;
}
ASSERT ( V_125 < V_2 -> V_65 ) ;
for ( V_4 = F_46 ( V_2 , V_125 , & V_7 ) ; V_125 > V_5 ; ) {
union V_51 * V_175 ;
V_175 = F_42 ( V_2 , V_2 -> V_78 [ V_125 ] , V_4 ) ;
-- V_125 ;
error = F_82 ( V_2 , V_175 , 0 , & V_4 , & V_7 ) ;
if ( error )
goto V_171;
F_66 ( V_2 , V_125 , V_7 ) ;
V_2 -> V_78 [ V_125 ] = 1 ;
}
V_172:
F_90 ( V_2 , V_162 ) ;
* V_170 = 1 ;
return 0 ;
V_173:
F_90 ( V_2 , V_162 ) ;
* V_170 = 0 ;
return 0 ;
V_171:
F_90 ( V_2 , V_176 ) ;
return error ;
}
int
F_106 (
struct V_1 * V_2 ,
int V_5 ,
int * V_170 )
{
struct V_3 * V_4 ;
T_4 * V_7 ;
int error ;
int V_125 ;
union V_51 V_52 ;
F_90 ( V_2 , V_160 ) ;
F_102 ( V_2 , V_5 ) ;
ASSERT ( V_5 < V_2 -> V_65 ) ;
F_63 ( V_2 , V_5 , V_123 ) ;
if ( -- V_2 -> V_78 [ V_5 ] > 0 )
goto V_172;
V_4 = F_46 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_103
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_171;
#endif
F_69 ( V_2 , V_4 , & V_52 , V_126 ) ;
if ( F_67 ( V_2 , & V_52 ) )
goto V_173;
F_105 ( V_2 , V_177 ) ;
for ( V_125 = V_5 + 1 ; V_125 < V_2 -> V_65 ; V_125 ++ ) {
if ( -- V_2 -> V_78 [ V_125 ] > 0 )
break;
F_63 ( V_2 , V_125 , V_123 ) ;
}
if ( V_125 == V_2 -> V_65 ) {
if ( V_2 -> V_46 & V_101 )
goto V_173;
ASSERT ( 0 ) ;
error = - V_33 ;
goto V_171;
}
ASSERT ( V_125 < V_2 -> V_65 ) ;
for ( V_4 = F_46 ( V_2 , V_125 , & V_7 ) ; V_125 > V_5 ; ) {
union V_51 * V_175 ;
V_175 = F_42 ( V_2 , V_2 -> V_78 [ V_125 ] , V_4 ) ;
-- V_125 ;
error = F_82 ( V_2 , V_175 , 0 , & V_4 , & V_7 ) ;
if ( error )
goto V_171;
F_66 ( V_2 , V_125 , V_7 ) ;
V_2 -> V_78 [ V_125 ] = F_104 ( V_4 ) ;
}
V_172:
F_90 ( V_2 , V_162 ) ;
* V_170 = 1 ;
return 0 ;
V_173:
F_90 ( V_2 , V_162 ) ;
* V_170 = 0 ;
return 0 ;
V_171:
F_90 ( V_2 , V_176 ) ;
return error ;
}
STATIC int
F_107 (
struct V_1 * V_2 ,
int V_5 ,
union V_51 * V_178 ,
struct V_3 * * V_179 )
{
struct V_6 * V_7 ;
int error = 0 ;
if ( ( V_2 -> V_46 & V_101 ) &&
( V_5 == V_2 -> V_65 - 1 ) ) {
* V_179 = F_44 ( V_2 ) ;
return 0 ;
}
V_7 = V_2 -> V_66 [ V_5 ] ;
if ( V_7 && F_34 ( V_7 ) == F_64 ( V_2 , V_178 ) ) {
* V_179 = F_23 ( V_7 ) ;
return 0 ;
}
error = F_82 ( V_2 , V_178 , 0 , V_179 , & V_7 ) ;
if ( error )
return error ;
F_66 ( V_2 , V_5 , V_7 ) ;
return 0 ;
}
STATIC union V_94 *
F_108 (
struct V_1 * V_2 ,
int V_5 ,
int V_180 ,
struct V_3 * V_4 ,
union V_94 * V_181 )
{
if ( V_5 == 0 ) {
V_2 -> V_23 -> V_182 ( V_181 ,
F_40 ( V_2 , V_180 , V_4 ) ) ;
return V_181 ;
}
return F_41 ( V_2 , V_180 , V_4 ) ;
}
int
F_109 (
struct V_1 * V_2 ,
T_16 V_158 ,
int * V_170 )
{
struct V_3 * V_4 ;
T_11 V_183 ;
int error ;
int V_180 ;
int V_5 ;
union V_51 * V_178 ;
union V_51 V_52 ;
F_90 ( V_2 , V_160 ) ;
F_102 ( V_2 , V_158 ) ;
F_105 ( V_2 , V_184 ) ;
V_4 = NULL ;
V_180 = 0 ;
V_2 -> V_23 -> V_185 ( V_2 , & V_52 ) ;
V_178 = & V_52 ;
for ( V_5 = V_2 -> V_65 - 1 , V_183 = 1 ; V_5 >= 0 ; V_5 -- ) {
error = F_107 ( V_2 , V_5 , V_178 , & V_4 ) ;
if ( error )
goto V_171;
if ( V_183 == 0 ) {
V_180 = 1 ;
} else {
int V_186 ;
int V_187 ;
V_187 = 1 ;
V_186 = F_104 ( V_4 ) ;
if ( ! V_186 ) {
ASSERT ( V_5 == 0 && V_2 -> V_65 == 1 ) ;
V_2 -> V_78 [ 0 ] = V_158 != V_188 ;
F_90 ( V_2 , V_162 ) ;
* V_170 = 0 ;
return 0 ;
}
while ( V_187 <= V_186 ) {
union V_94 V_157 ;
union V_94 * V_181 ;
F_105 ( V_2 , V_189 ) ;
V_180 = ( V_187 + V_186 ) >> 1 ;
V_181 = F_108 ( V_2 , V_5 ,
V_180 , V_4 , & V_157 ) ;
V_183 = V_2 -> V_23 -> V_190 ( V_2 , V_181 ) ;
if ( V_183 < 0 )
V_187 = V_180 + 1 ;
else if ( V_183 > 0 )
V_186 = V_180 - 1 ;
else
break;
}
}
if ( V_5 > 0 ) {
if ( V_183 > 0 && -- V_180 < 1 )
V_180 = 1 ;
V_178 = F_42 ( V_2 , V_180 , V_4 ) ;
#ifdef F_103
error = F_21 ( V_2 , V_178 , 0 , V_5 ) ;
if ( error )
goto V_171;
#endif
V_2 -> V_78 [ V_5 ] = V_180 ;
}
}
if ( V_158 != V_188 && V_183 < 0 ) {
V_180 ++ ;
F_69 ( V_2 , V_4 , & V_52 , V_127 ) ;
if ( V_158 == V_191 &&
V_180 > F_104 ( V_4 ) &&
! F_67 ( V_2 , & V_52 ) ) {
int V_64 ;
V_2 -> V_78 [ 0 ] = V_180 ;
error = F_101 ( V_2 , 0 , & V_64 ) ;
if ( error )
goto V_171;
F_19 ( V_2 -> V_11 , V_64 == 1 ) ;
F_90 ( V_2 , V_162 ) ;
* V_170 = 1 ;
return 0 ;
}
} else if ( V_158 == V_188 && V_183 > 0 )
V_180 -- ;
V_2 -> V_78 [ 0 ] = V_180 ;
if ( V_180 == 0 || V_180 > F_104 ( V_4 ) )
* V_170 = 0 ;
else if ( V_158 != V_192 || V_183 == 0 )
* V_170 = 1 ;
else
* V_170 = 0 ;
F_90 ( V_2 , V_162 ) ;
return 0 ;
V_171:
F_90 ( V_2 , V_176 ) ;
return error ;
}
STATIC int
F_110 (
struct V_1 * V_2 ,
union V_94 * V_193 ,
int V_5 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_94 * V_181 ;
int V_52 ;
F_90 ( V_2 , V_160 ) ;
F_111 ( V_2 , V_5 , V_193 ) ;
ASSERT ( ! ( V_2 -> V_46 & V_101 ) || V_5 >= 1 ) ;
for ( V_52 = 1 ; V_52 == 1 && V_5 < V_2 -> V_65 ; V_5 ++ ) {
#ifdef F_103
int error ;
#endif
V_4 = F_46 ( V_2 , V_5 , & V_7 ) ;
#ifdef F_103
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error ) {
F_90 ( V_2 , V_176 ) ;
return error ;
}
#endif
V_52 = V_2 -> V_78 [ V_5 ] ;
V_181 = F_41 ( V_2 , V_52 , V_4 ) ;
F_83 ( V_2 , V_181 , V_193 , 1 ) ;
F_89 ( V_2 , V_7 , V_52 , V_52 ) ;
}
F_90 ( V_2 , V_162 ) ;
return 0 ;
}
int
F_112 (
struct V_1 * V_2 ,
union V_93 * V_159 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int error ;
int V_52 ;
union V_93 * V_194 ;
F_90 ( V_2 , V_160 ) ;
F_113 ( V_2 , V_159 ) ;
V_4 = F_46 ( V_2 , 0 , & V_7 ) ;
#ifdef F_103
error = F_17 ( V_2 , V_4 , 0 , V_7 ) ;
if ( error )
goto V_171;
#endif
V_52 = V_2 -> V_78 [ 0 ] ;
V_194 = F_40 ( V_2 , V_52 , V_4 ) ;
F_84 ( V_2 , V_194 , V_159 , 1 ) ;
F_96 ( V_2 , V_7 , V_52 , V_52 ) ;
if ( F_76 ( V_2 , V_4 , 0 ) ) {
V_2 -> V_23 -> V_195 ( V_2 , V_4 , V_159 ,
V_52 , V_196 ) ;
}
if ( V_52 == 1 ) {
union V_94 V_157 ;
V_2 -> V_23 -> V_182 ( & V_157 , V_159 ) ;
error = F_110 ( V_2 , & V_157 , 1 ) ;
if ( error )
goto V_171;
}
F_90 ( V_2 , V_162 ) ;
return 0 ;
V_171:
F_90 ( V_2 , V_176 ) ;
return error ;
}
STATIC int
F_114 (
struct V_1 * V_2 ,
int V_5 ,
int * V_170 )
{
union V_94 V_157 ;
struct V_6 * V_197 ;
struct V_3 * V_121 ;
int V_198 ;
struct V_6 * V_199 ;
struct V_3 * V_122 ;
int V_200 ;
union V_51 V_201 ;
union V_94 * V_202 = NULL ;
union V_51 * V_203 = NULL ;
union V_93 * V_204 = NULL ;
int error ;
F_90 ( V_2 , V_160 ) ;
F_102 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_46 & V_101 ) &&
V_5 == V_2 -> V_65 - 1 )
goto V_173;
V_122 = F_46 ( V_2 , V_5 , & V_199 ) ;
#ifdef F_103
error = F_17 ( V_2 , V_122 , V_5 , V_199 ) ;
if ( error )
goto V_171;
#endif
F_69 ( V_2 , V_122 , & V_201 , V_126 ) ;
if ( F_67 ( V_2 , & V_201 ) )
goto V_173;
if ( V_2 -> V_78 [ V_5 ] <= 1 )
goto V_173;
error = F_82 ( V_2 , & V_201 , 0 , & V_121 , & V_197 ) ;
if ( error )
goto V_171;
V_198 = F_104 ( V_121 ) ;
if ( V_198 == V_2 -> V_23 -> V_24 ( V_2 , V_5 ) )
goto V_173;
V_200 = F_104 ( V_122 ) ;
V_198 ++ ;
V_200 -- ;
F_105 ( V_2 , V_205 ) ;
F_115 ( V_2 , V_206 , 1 ) ;
if ( V_5 > 0 ) {
union V_94 * V_207 ;
union V_51 * V_208 ;
V_207 = F_41 ( V_2 , V_198 , V_121 ) ;
V_202 = F_41 ( V_2 , 1 , V_122 ) ;
V_208 = F_42 ( V_2 , V_198 , V_121 ) ;
V_203 = F_42 ( V_2 , 1 , V_122 ) ;
#ifdef F_103
error = F_21 ( V_2 , V_203 , 0 , V_5 ) ;
if ( error )
goto V_171;
#endif
F_83 ( V_2 , V_207 , V_202 , 1 ) ;
F_85 ( V_2 , V_208 , V_203 , 1 ) ;
F_89 ( V_2 , V_197 , V_198 , V_198 ) ;
F_97 ( V_2 , V_197 , V_198 , V_198 ) ;
ASSERT ( V_2 -> V_23 -> V_209 ( V_2 ,
F_41 ( V_2 , V_198 - 1 , V_121 ) , V_207 ) ) ;
} else {
union V_93 * V_210 ;
V_210 = F_40 ( V_2 , V_198 , V_121 ) ;
V_204 = F_40 ( V_2 , 1 , V_122 ) ;
F_84 ( V_2 , V_210 , V_204 , 1 ) ;
F_96 ( V_2 , V_197 , V_198 , V_198 ) ;
ASSERT ( V_2 -> V_23 -> V_211 ( V_2 ,
F_40 ( V_2 , V_198 - 1 , V_121 ) , V_210 ) ) ;
}
F_116 ( V_121 , V_198 ) ;
F_98 ( V_2 , V_197 , V_212 ) ;
F_116 ( V_122 , V_200 ) ;
F_98 ( V_2 , V_199 , V_212 ) ;
F_115 ( V_2 , V_206 , V_200 - 1 ) ;
if ( V_5 > 0 ) {
#ifdef F_103
int V_64 ;
for ( V_64 = 0 ; V_64 < V_200 ; V_64 ++ ) {
error = F_21 ( V_2 , V_203 , V_64 + 1 , V_5 ) ;
if ( error )
goto V_171;
}
#endif
F_86 ( V_2 ,
F_41 ( V_2 , 2 , V_122 ) ,
- 1 , V_200 ) ;
F_88 ( V_2 ,
F_42 ( V_2 , 2 , V_122 ) ,
- 1 , V_200 ) ;
F_89 ( V_2 , V_199 , 1 , V_200 ) ;
F_97 ( V_2 , V_199 , 1 , V_200 ) ;
} else {
F_87 ( V_2 ,
F_40 ( V_2 , 2 , V_122 ) ,
- 1 , V_200 ) ;
F_96 ( V_2 , V_199 , 1 , V_200 ) ;
V_2 -> V_23 -> V_182 ( & V_157 ,
F_40 ( V_2 , 1 , V_122 ) ) ;
V_202 = & V_157 ;
}
error = F_110 ( V_2 , V_202 , V_5 + 1 ) ;
if ( error )
goto V_171;
V_2 -> V_78 [ V_5 ] -- ;
F_90 ( V_2 , V_162 ) ;
* V_170 = 1 ;
return 0 ;
V_173:
F_90 ( V_2 , V_162 ) ;
* V_170 = 0 ;
return 0 ;
V_171:
F_90 ( V_2 , V_176 ) ;
return error ;
}
STATIC int
F_117 (
struct V_1 * V_2 ,
int V_5 ,
int * V_170 )
{
union V_94 V_157 ;
struct V_6 * V_197 ;
struct V_3 * V_121 ;
struct V_6 * V_199 ;
struct V_3 * V_122 ;
struct V_1 * V_213 ;
union V_51 V_214 ;
union V_94 * V_202 ;
int V_200 ;
int V_198 ;
int error ;
int V_64 ;
F_90 ( V_2 , V_160 ) ;
F_102 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_46 & V_101 ) &&
( V_5 == V_2 -> V_65 - 1 ) )
goto V_173;
V_121 = F_46 ( V_2 , V_5 , & V_197 ) ;
#ifdef F_103
error = F_17 ( V_2 , V_121 , V_5 , V_197 ) ;
if ( error )
goto V_171;
#endif
F_69 ( V_2 , V_121 , & V_214 , V_127 ) ;
if ( F_67 ( V_2 , & V_214 ) )
goto V_173;
V_198 = F_104 ( V_121 ) ;
if ( V_2 -> V_78 [ V_5 ] >= V_198 )
goto V_173;
error = F_82 ( V_2 , & V_214 , 0 , & V_122 , & V_199 ) ;
if ( error )
goto V_171;
V_200 = F_104 ( V_122 ) ;
if ( V_200 == V_2 -> V_23 -> V_24 ( V_2 , V_5 ) )
goto V_173;
F_105 ( V_2 , V_215 ) ;
F_115 ( V_2 , V_206 , V_200 ) ;
if ( V_5 > 0 ) {
union V_94 * V_207 ;
union V_51 * V_208 ;
union V_51 * V_203 ;
V_207 = F_41 ( V_2 , V_198 , V_121 ) ;
V_208 = F_42 ( V_2 , V_198 , V_121 ) ;
V_202 = F_41 ( V_2 , 1 , V_122 ) ;
V_203 = F_42 ( V_2 , 1 , V_122 ) ;
#ifdef F_103
for ( V_64 = V_200 - 1 ; V_64 >= 0 ; V_64 -- ) {
error = F_21 ( V_2 , V_203 , V_64 , V_5 ) ;
if ( error )
goto V_171;
}
#endif
F_86 ( V_2 , V_202 , 1 , V_200 ) ;
F_88 ( V_2 , V_203 , 1 , V_200 ) ;
#ifdef F_103
error = F_21 ( V_2 , V_208 , 0 , V_5 ) ;
if ( error )
goto V_171;
#endif
F_83 ( V_2 , V_202 , V_207 , 1 ) ;
F_85 ( V_2 , V_203 , V_208 , 1 ) ;
F_89 ( V_2 , V_199 , 1 , V_200 + 1 ) ;
F_97 ( V_2 , V_199 , 1 , V_200 + 1 ) ;
ASSERT ( V_2 -> V_23 -> V_209 ( V_2 , V_202 ,
F_41 ( V_2 , 2 , V_122 ) ) ) ;
} else {
union V_93 * V_210 ;
union V_93 * V_204 ;
V_210 = F_40 ( V_2 , V_198 , V_121 ) ;
V_204 = F_40 ( V_2 , 1 , V_122 ) ;
F_87 ( V_2 , V_204 , 1 , V_200 ) ;
F_84 ( V_2 , V_204 , V_210 , 1 ) ;
F_96 ( V_2 , V_199 , 1 , V_200 + 1 ) ;
V_2 -> V_23 -> V_182 ( & V_157 , V_204 ) ;
V_202 = & V_157 ;
ASSERT ( V_2 -> V_23 -> V_211 ( V_2 , V_204 ,
F_40 ( V_2 , 2 , V_122 ) ) ) ;
}
F_116 ( V_121 , -- V_198 ) ;
F_98 ( V_2 , V_197 , V_212 ) ;
F_116 ( V_122 , ++ V_200 ) ;
F_98 ( V_2 , V_199 , V_212 ) ;
error = F_32 ( V_2 , & V_213 ) ;
if ( error )
goto V_171;
V_64 = F_54 ( V_213 , V_5 ) ;
F_118 ( V_2 -> V_11 , V_64 == 1 , V_171 ) ;
error = F_101 ( V_213 , V_5 , & V_64 ) ;
if ( error )
goto V_216;
error = F_110 ( V_213 , V_202 , V_5 + 1 ) ;
if ( error )
goto V_216;
F_29 ( V_213 , V_217 ) ;
F_90 ( V_2 , V_162 ) ;
* V_170 = 1 ;
return 0 ;
V_173:
F_90 ( V_2 , V_162 ) ;
* V_170 = 0 ;
return 0 ;
V_171:
F_90 ( V_2 , V_176 ) ;
return error ;
V_216:
F_90 ( V_213 , V_176 ) ;
F_29 ( V_213 , V_218 ) ;
return error ;
}
STATIC int
F_119 (
struct V_1 * V_2 ,
int V_5 ,
union V_51 * V_175 ,
union V_94 * V_157 ,
struct V_1 * * V_219 ,
int * V_170 )
{
union V_51 V_201 ;
struct V_6 * V_197 ;
struct V_3 * V_121 ;
union V_51 V_214 ;
struct V_6 * V_199 ;
struct V_3 * V_122 ;
union V_51 V_220 ;
struct V_6 * V_221 ;
struct V_3 * V_222 ;
int V_198 ;
int V_200 ;
int V_223 ;
int error ;
#ifdef F_103
int V_64 ;
#endif
F_90 ( V_2 , V_160 ) ;
F_120 ( V_2 , V_5 , * V_175 , V_157 ) ;
F_105 ( V_2 , V_224 ) ;
V_121 = F_46 ( V_2 , V_5 , & V_197 ) ;
#ifdef F_103
error = F_17 ( V_2 , V_121 , V_5 , V_197 ) ;
if ( error )
goto V_171;
#endif
F_77 ( V_2 , V_197 , & V_201 ) ;
error = V_2 -> V_23 -> V_225 ( V_2 , & V_201 , & V_214 , V_170 ) ;
if ( error )
goto V_171;
if ( * V_170 == 0 )
goto V_173;
F_105 ( V_2 , V_226 ) ;
error = F_81 ( V_2 , & V_214 , 0 , & V_122 , & V_199 ) ;
if ( error )
goto V_171;
F_75 ( V_2 , V_199 , F_43 ( V_121 ) , 0 ) ;
V_198 = F_104 ( V_121 ) ;
V_200 = V_198 / 2 ;
if ( ( V_198 & 1 ) && V_2 -> V_78 [ V_5 ] <= V_200 + 1 )
V_200 ++ ;
V_223 = ( V_198 - V_200 + 1 ) ;
F_115 ( V_2 , V_206 , V_200 ) ;
if ( V_5 > 0 ) {
union V_94 * V_207 ;
union V_51 * V_208 ;
union V_94 * V_202 ;
union V_51 * V_203 ;
V_207 = F_41 ( V_2 , V_223 , V_121 ) ;
V_208 = F_42 ( V_2 , V_223 , V_121 ) ;
V_202 = F_41 ( V_2 , 1 , V_122 ) ;
V_203 = F_42 ( V_2 , 1 , V_122 ) ;
#ifdef F_103
for ( V_64 = V_223 ; V_64 < V_200 ; V_64 ++ ) {
error = F_21 ( V_2 , V_208 , V_64 , V_5 ) ;
if ( error )
goto V_171;
}
#endif
F_83 ( V_2 , V_202 , V_207 , V_200 ) ;
F_85 ( V_2 , V_203 , V_208 , V_200 ) ;
F_89 ( V_2 , V_199 , 1 , V_200 ) ;
F_97 ( V_2 , V_199 , 1 , V_200 ) ;
F_83 ( V_2 , V_157 , V_202 , 1 ) ;
} else {
union V_93 * V_210 ;
union V_93 * V_204 ;
V_210 = F_40 ( V_2 , V_223 , V_121 ) ;
V_204 = F_40 ( V_2 , 1 , V_122 ) ;
F_84 ( V_2 , V_204 , V_210 , V_200 ) ;
F_96 ( V_2 , V_199 , 1 , V_200 ) ;
V_2 -> V_23 -> V_182 ( V_157 ,
F_40 ( V_2 , 1 , V_122 ) ) ;
}
F_69 ( V_2 , V_121 , & V_220 , V_127 ) ;
F_70 ( V_2 , V_122 , & V_220 , V_127 ) ;
F_70 ( V_2 , V_122 , & V_201 , V_126 ) ;
F_70 ( V_2 , V_121 , & V_214 , V_127 ) ;
V_198 -= V_200 ;
F_116 ( V_121 , V_198 ) ;
F_116 ( V_122 , F_104 ( V_122 ) + V_200 ) ;
F_98 ( V_2 , V_199 , V_166 ) ;
F_98 ( V_2 , V_197 , V_212 | V_127 ) ;
if ( ! F_67 ( V_2 , & V_220 ) ) {
error = F_82 ( V_2 , & V_220 ,
0 , & V_222 , & V_221 ) ;
if ( error )
goto V_171;
F_70 ( V_2 , V_222 , & V_214 , V_126 ) ;
F_98 ( V_2 , V_221 , V_126 ) ;
}
if ( V_2 -> V_78 [ V_5 ] > V_198 + 1 ) {
F_66 ( V_2 , V_5 , V_199 ) ;
V_2 -> V_78 [ V_5 ] -= V_198 ;
}
if ( V_5 + 1 < V_2 -> V_65 ) {
error = F_32 ( V_2 , V_219 ) ;
if ( error )
goto V_171;
( * V_219 ) -> V_78 [ V_5 + 1 ] ++ ;
}
* V_175 = V_214 ;
F_90 ( V_2 , V_162 ) ;
* V_170 = 1 ;
return 0 ;
V_173:
F_90 ( V_2 , V_162 ) ;
* V_170 = 0 ;
return 0 ;
V_171:
F_90 ( V_2 , V_176 ) ;
return error ;
}
static void
F_121 (
struct V_227 * V_228 )
{
struct V_229 * args = F_122 ( V_228 ,
struct V_229 , V_228 ) ;
unsigned long V_230 ;
unsigned long V_231 = V_232 ;
if ( args -> V_233 )
V_231 |= V_234 | V_235 | V_236 ;
F_123 ( & V_230 , V_231 ) ;
args -> V_237 = F_119 ( args -> V_2 , args -> V_5 , args -> V_175 ,
args -> V_157 , args -> V_219 , args -> V_170 ) ;
F_124 ( args -> V_238 ) ;
F_125 ( & V_230 , V_231 ) ;
}
STATIC int
F_126 (
struct V_1 * V_2 ,
int V_5 ,
union V_51 * V_175 ,
union V_94 * V_157 ,
struct V_1 * * V_219 ,
int * V_170 )
{
struct V_229 args ;
F_127 ( V_238 ) ;
if ( V_2 -> V_68 != V_69 )
return F_119 ( V_2 , V_5 , V_175 , V_157 , V_219 , V_170 ) ;
args . V_2 = V_2 ;
args . V_5 = V_5 ;
args . V_175 = V_175 ;
args . V_157 = V_157 ;
args . V_219 = V_219 ;
args . V_170 = V_170 ;
args . V_238 = & V_238 ;
args . V_233 = F_128 () ;
F_129 ( & args . V_228 , F_121 ) ;
F_130 ( V_239 , & args . V_228 ) ;
F_131 ( & V_238 ) ;
F_132 ( & args . V_228 ) ;
return args . V_237 ;
}
int
F_133 (
struct V_1 * V_2 ,
int * V_240 ,
int * V_170 )
{
struct V_6 * V_241 ;
struct V_3 * V_4 ;
struct V_3 * V_242 ;
union V_94 * V_243 ;
union V_51 * V_244 ;
union V_94 * V_181 ;
union V_51 * V_178 ;
union V_51 V_245 ;
int V_5 ;
int error ;
#ifdef F_103
int V_64 ;
#endif
F_90 ( V_2 , V_160 ) ;
F_105 ( V_2 , V_246 ) ;
ASSERT ( V_2 -> V_46 & V_101 ) ;
V_5 = V_2 -> V_65 - 1 ;
V_4 = F_44 ( V_2 ) ;
V_178 = F_42 ( V_2 , 1 , V_4 ) ;
error = V_2 -> V_23 -> V_225 ( V_2 , V_178 , & V_245 , V_170 ) ;
if ( error )
goto V_171;
if ( * V_170 == 0 ) {
F_90 ( V_2 , V_162 ) ;
return 0 ;
}
F_105 ( V_2 , V_226 ) ;
error = F_81 ( V_2 , & V_245 , 0 , & V_242 , & V_241 ) ;
if ( error )
goto V_171;
memcpy ( V_242 , V_4 , F_35 ( V_2 ) ) ;
if ( V_2 -> V_46 & V_83 ) {
if ( V_2 -> V_46 & V_47 )
V_242 -> V_13 . V_14 . V_17 = F_4 ( V_241 -> V_18 ) ;
else
V_242 -> V_13 . V_42 . V_17 = F_4 ( V_241 -> V_18 ) ;
}
F_134 ( & V_4 -> V_21 , 1 ) ;
F_116 ( V_4 , 1 ) ;
V_2 -> V_65 ++ ;
V_2 -> V_78 [ V_5 + 1 ] = 1 ;
V_181 = F_41 ( V_2 , 1 , V_4 ) ;
V_243 = F_41 ( V_2 , 1 , V_242 ) ;
F_83 ( V_2 , V_243 , V_181 , F_104 ( V_242 ) ) ;
V_244 = F_42 ( V_2 , 1 , V_242 ) ;
#ifdef F_103
for ( V_64 = 0 ; V_64 < F_7 ( V_242 -> V_22 ) ; V_64 ++ ) {
error = F_21 ( V_2 , V_178 , V_64 , V_5 ) ;
if ( error )
goto V_171;
}
#endif
F_85 ( V_2 , V_244 , V_178 , F_104 ( V_242 ) ) ;
#ifdef F_103
error = F_21 ( V_2 , & V_245 , 0 , V_5 ) ;
if ( error )
goto V_171;
#endif
F_85 ( V_2 , V_178 , & V_245 , 1 ) ;
F_135 ( V_2 -> V_39 . V_70 . V_97 ,
1 - F_104 ( V_242 ) ,
V_2 -> V_39 . V_70 . V_98 ) ;
F_66 ( V_2 , V_5 , V_241 ) ;
F_98 ( V_2 , V_241 , V_166 ) ;
F_89 ( V_2 , V_241 , 1 , F_7 ( V_242 -> V_22 ) ) ;
F_97 ( V_2 , V_241 , 1 , F_7 ( V_242 -> V_22 ) ) ;
* V_240 |=
V_247 | F_95 ( V_2 -> V_39 . V_70 . V_98 ) ;
* V_170 = 1 ;
F_90 ( V_2 , V_162 ) ;
return 0 ;
V_171:
F_90 ( V_2 , V_176 ) ;
return error ;
}
STATIC int
F_136 (
struct V_1 * V_2 ,
int * V_170 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int error ;
struct V_6 * V_197 ;
struct V_3 * V_121 ;
struct V_6 * V_248 ;
struct V_3 * V_74 ;
int V_245 ;
struct V_6 * V_199 ;
struct V_3 * V_122 ;
union V_51 V_214 ;
union V_51 V_201 ;
F_90 ( V_2 , V_160 ) ;
F_105 ( V_2 , V_246 ) ;
V_2 -> V_23 -> V_185 ( V_2 , & V_214 ) ;
error = V_2 -> V_23 -> V_225 ( V_2 , & V_214 , & V_201 , V_170 ) ;
if ( error )
goto V_171;
if ( * V_170 == 0 )
goto V_173;
F_105 ( V_2 , V_226 ) ;
error = F_81 ( V_2 , & V_201 , 0 , & V_74 , & V_248 ) ;
if ( error )
goto V_171;
V_2 -> V_23 -> V_249 ( V_2 , & V_201 , 1 ) ;
V_4 = F_46 ( V_2 , V_2 -> V_65 - 1 , & V_7 ) ;
#ifdef F_103
error = F_17 ( V_2 , V_4 , V_2 -> V_65 - 1 , V_7 ) ;
if ( error )
goto V_171;
#endif
F_69 ( V_2 , V_4 , & V_214 , V_127 ) ;
if ( ! F_67 ( V_2 , & V_214 ) ) {
V_197 = V_7 ;
F_77 ( V_2 , V_197 , & V_201 ) ;
V_121 = V_4 ;
error = F_82 ( V_2 , & V_214 , 0 , & V_122 , & V_199 ) ;
if ( error )
goto V_171;
V_7 = V_199 ;
V_245 = 1 ;
} else {
V_199 = V_7 ;
F_77 ( V_2 , V_199 , & V_214 ) ;
V_122 = V_4 ;
F_69 ( V_2 , V_122 , & V_201 , V_126 ) ;
error = F_82 ( V_2 , & V_201 , 0 , & V_121 , & V_197 ) ;
if ( error )
goto V_171;
V_7 = V_197 ;
V_245 = 2 ;
}
F_75 ( V_2 , V_248 , V_2 -> V_65 , 2 ) ;
F_98 ( V_2 , V_248 , V_166 ) ;
ASSERT ( ! F_67 ( V_2 , & V_201 ) &&
! F_67 ( V_2 , & V_214 ) ) ;
if ( F_43 ( V_121 ) > 0 ) {
F_83 ( V_2 ,
F_41 ( V_2 , 1 , V_74 ) ,
F_41 ( V_2 , 1 , V_121 ) , 1 ) ;
F_83 ( V_2 ,
F_41 ( V_2 , 2 , V_74 ) ,
F_41 ( V_2 , 1 , V_122 ) , 1 ) ;
} else {
V_2 -> V_23 -> V_182 (
F_41 ( V_2 , 1 , V_74 ) ,
F_40 ( V_2 , 1 , V_121 ) ) ;
V_2 -> V_23 -> V_182 (
F_41 ( V_2 , 2 , V_74 ) ,
F_40 ( V_2 , 1 , V_122 ) ) ;
}
F_89 ( V_2 , V_248 , 1 , 2 ) ;
F_85 ( V_2 ,
F_42 ( V_2 , 1 , V_74 ) , & V_201 , 1 ) ;
F_85 ( V_2 ,
F_42 ( V_2 , 2 , V_74 ) , & V_214 , 1 ) ;
F_97 ( V_2 , V_248 , 1 , 2 ) ;
F_66 ( V_2 , V_2 -> V_65 , V_248 ) ;
V_2 -> V_78 [ V_2 -> V_65 ] = V_245 ;
V_2 -> V_65 ++ ;
F_90 ( V_2 , V_162 ) ;
* V_170 = 1 ;
return 0 ;
V_171:
F_90 ( V_2 , V_176 ) ;
return error ;
V_173:
F_90 ( V_2 , V_162 ) ;
* V_170 = 0 ;
return 0 ;
}
STATIC int
F_137 (
struct V_1 * V_2 ,
int V_5 ,
int V_131 ,
int * V_250 ,
int * V_53 ,
union V_51 * V_245 ,
struct V_1 * * V_73 ,
union V_93 * V_251 ,
int * V_170 )
{
union V_94 V_157 ;
int error = 0 ;
if ( ( V_2 -> V_46 & V_101 ) &&
V_5 == V_2 -> V_65 - 1 ) {
struct V_252 * V_97 = V_2 -> V_39 . V_70 . V_97 ;
if ( V_131 < V_2 -> V_23 -> V_253 ( V_2 , V_5 ) ) {
F_135 ( V_97 , 1 , V_2 -> V_39 . V_70 . V_98 ) ;
} else {
int V_240 = 0 ;
error = F_133 ( V_2 , & V_240 , V_170 ) ;
if ( error || * V_170 == 0 )
return error ;
F_94 ( V_2 -> V_67 , V_97 , V_240 ) ;
}
return 0 ;
}
error = F_117 ( V_2 , V_5 , V_170 ) ;
if ( error || * V_170 )
return error ;
error = F_114 ( V_2 , V_5 , V_170 ) ;
if ( error )
return error ;
if ( * V_170 ) {
* V_250 = * V_53 = V_2 -> V_78 [ V_5 ] ;
return 0 ;
}
error = F_126 ( V_2 , V_5 , V_245 , & V_157 , V_73 , V_170 ) ;
if ( error || * V_170 == 0 )
return error ;
* V_53 = V_2 -> V_78 [ V_5 ] ;
V_2 -> V_23 -> V_254 ( & V_157 , V_251 ) ;
return 0 ;
}
STATIC int
F_138 (
struct V_1 * V_2 ,
int V_5 ,
union V_51 * V_175 ,
union V_93 * V_255 ,
struct V_1 * * V_219 ,
int * V_170 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_94 V_157 ;
union V_51 V_245 ;
struct V_1 * V_73 ;
union V_93 V_251 ;
int V_256 ;
int V_52 ;
int V_131 ;
int error ;
#ifdef F_103
int V_64 ;
#endif
F_90 ( V_2 , V_160 ) ;
F_139 ( V_2 , V_5 , * V_175 , V_255 ) ;
V_73 = NULL ;
if ( ! ( V_2 -> V_46 & V_101 ) &&
( V_5 >= V_2 -> V_65 ) ) {
error = F_136 ( V_2 , V_170 ) ;
F_68 ( V_2 , V_175 ) ;
F_90 ( V_2 , V_162 ) ;
return error ;
}
V_52 = V_2 -> V_78 [ V_5 ] ;
if ( V_52 == 0 ) {
F_90 ( V_2 , V_162 ) ;
* V_170 = 0 ;
return 0 ;
}
V_2 -> V_23 -> V_182 ( & V_157 , V_255 ) ;
V_256 = V_52 ;
F_105 ( V_2 , V_257 ) ;
V_4 = F_46 ( V_2 , V_5 , & V_7 ) ;
V_131 = F_104 ( V_4 ) ;
#ifdef F_103
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_171;
if ( V_52 <= V_131 ) {
if ( V_5 == 0 ) {
ASSERT ( V_2 -> V_23 -> V_211 ( V_2 , V_255 ,
F_40 ( V_2 , V_52 , V_4 ) ) ) ;
} else {
ASSERT ( V_2 -> V_23 -> V_209 ( V_2 , & V_157 ,
F_41 ( V_2 , V_52 , V_4 ) ) ) ;
}
}
#endif
F_68 ( V_2 , & V_245 ) ;
if ( V_131 == V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ) {
error = F_137 ( V_2 , V_5 , V_131 ,
& V_256 , & V_52 , & V_245 , & V_73 , & V_251 , V_170 ) ;
if ( error || * V_170 == 0 )
goto V_171;
}
V_4 = F_46 ( V_2 , V_5 , & V_7 ) ;
V_131 = F_104 ( V_4 ) ;
#ifdef F_103
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
return error ;
#endif
F_115 ( V_2 , V_206 , V_131 - V_52 + 1 ) ;
if ( V_5 > 0 ) {
union V_94 * V_181 ;
union V_51 * V_178 ;
V_181 = F_41 ( V_2 , V_52 , V_4 ) ;
V_178 = F_42 ( V_2 , V_52 , V_4 ) ;
#ifdef F_103
for ( V_64 = V_131 - V_52 ; V_64 >= 0 ; V_64 -- ) {
error = F_21 ( V_2 , V_178 , V_64 , V_5 ) ;
if ( error )
return error ;
}
#endif
F_86 ( V_2 , V_181 , 1 , V_131 - V_52 + 1 ) ;
F_88 ( V_2 , V_178 , 1 , V_131 - V_52 + 1 ) ;
#ifdef F_103
error = F_21 ( V_2 , V_175 , 0 , V_5 ) ;
if ( error )
goto V_171;
#endif
F_83 ( V_2 , V_181 , & V_157 , 1 ) ;
F_85 ( V_2 , V_178 , V_175 , 1 ) ;
V_131 ++ ;
F_116 ( V_4 , V_131 ) ;
F_97 ( V_2 , V_7 , V_52 , V_131 ) ;
F_89 ( V_2 , V_7 , V_52 , V_131 ) ;
#ifdef F_103
if ( V_52 < V_131 ) {
ASSERT ( V_2 -> V_23 -> V_209 ( V_2 , V_181 ,
F_41 ( V_2 , V_52 + 1 , V_4 ) ) ) ;
}
#endif
} else {
union V_93 * V_194 ;
V_194 = F_40 ( V_2 , V_52 , V_4 ) ;
F_87 ( V_2 , V_194 , 1 , V_131 - V_52 + 1 ) ;
F_84 ( V_2 , V_194 , V_255 , 1 ) ;
F_116 ( V_4 , ++ V_131 ) ;
F_96 ( V_2 , V_7 , V_52 , V_131 ) ;
#ifdef F_103
if ( V_52 < V_131 ) {
ASSERT ( V_2 -> V_23 -> V_211 ( V_2 , V_194 ,
F_40 ( V_2 , V_52 + 1 , V_4 ) ) ) ;
}
#endif
}
F_98 ( V_2 , V_7 , V_212 ) ;
if ( V_256 == 1 ) {
error = F_110 ( V_2 , & V_157 , V_5 + 1 ) ;
if ( error )
goto V_171;
}
if ( F_76 ( V_2 , V_4 , V_5 ) ) {
V_2 -> V_23 -> V_195 ( V_2 , V_4 , V_255 ,
V_52 , V_258 ) ;
}
* V_175 = V_245 ;
if ( ! F_67 ( V_2 , & V_245 ) ) {
* V_255 = V_251 ;
* V_219 = V_73 ;
}
F_90 ( V_2 , V_162 ) ;
* V_170 = 1 ;
return 0 ;
V_171:
F_90 ( V_2 , V_176 ) ;
return error ;
}
int
F_140 (
struct V_1 * V_2 ,
int * V_170 )
{
int error ;
int V_64 ;
int V_5 ;
union V_51 V_245 ;
struct V_1 * V_73 ;
struct V_1 * V_259 ;
union V_93 V_159 ;
V_5 = 0 ;
V_73 = NULL ;
V_259 = V_2 ;
F_68 ( V_2 , & V_245 ) ;
V_2 -> V_23 -> V_260 ( V_2 , & V_159 ) ;
do {
error = F_138 ( V_259 , V_5 , & V_245 , & V_159 , & V_73 , & V_64 ) ;
if ( error ) {
if ( V_259 != V_2 )
F_29 ( V_259 , V_218 ) ;
goto V_171;
}
F_118 ( V_2 -> V_11 , V_64 == 1 , V_171 ) ;
V_5 ++ ;
if ( V_259 != V_2 &&
( V_73 || F_67 ( V_2 , & V_245 ) ) ) {
if ( V_2 -> V_23 -> V_261 )
V_2 -> V_23 -> V_261 ( V_259 , V_2 ) ;
V_2 -> V_65 = V_259 -> V_65 ;
F_29 ( V_259 , V_217 ) ;
}
if ( V_73 ) {
V_259 = V_73 ;
V_73 = NULL ;
}
} while ( ! F_67 ( V_2 , & V_245 ) );
F_90 ( V_2 , V_162 ) ;
* V_170 = V_64 ;
return 0 ;
V_171:
F_90 ( V_2 , V_176 ) ;
return error ;
}
STATIC int
F_141 (
struct V_1 * V_2 )
{
int V_98 = V_2 -> V_39 . V_70 . V_98 ;
struct V_252 * V_97 = V_2 -> V_39 . V_70 . V_97 ;
struct V_95 * V_96 = F_45 ( V_97 , V_98 ) ;
struct V_3 * V_4 ;
struct V_3 * V_242 ;
union V_94 * V_181 ;
union V_94 * V_243 ;
union V_51 * V_178 ;
union V_51 * V_244 ;
struct V_6 * V_241 ;
int V_5 ;
int V_53 ;
int V_131 ;
#ifdef F_103
union V_51 V_52 ;
int V_64 ;
#endif
F_90 ( V_2 , V_160 ) ;
ASSERT ( V_2 -> V_46 & V_101 ) ;
ASSERT ( V_2 -> V_65 > 1 ) ;
V_5 = V_2 -> V_65 - 1 ;
if ( V_5 == 1 )
goto V_173;
V_4 = F_44 ( V_2 ) ;
if ( F_104 ( V_4 ) != 1 )
goto V_173;
V_242 = F_46 ( V_2 , V_5 - 1 , & V_241 ) ;
V_131 = F_104 ( V_242 ) ;
if ( V_131 > V_2 -> V_23 -> V_253 ( V_2 , V_5 ) )
goto V_173;
F_105 ( V_2 , V_262 ) ;
#ifdef F_103
F_69 ( V_2 , V_4 , & V_52 , V_126 ) ;
ASSERT ( F_67 ( V_2 , & V_52 ) ) ;
F_69 ( V_2 , V_4 , & V_52 , V_127 ) ;
ASSERT ( F_67 ( V_2 , & V_52 ) ) ;
#endif
V_53 = V_131 - V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ;
if ( V_53 ) {
F_135 ( V_2 -> V_39 . V_70 . V_97 , V_53 ,
V_2 -> V_39 . V_70 . V_98 ) ;
V_4 = V_96 -> V_99 ;
}
F_134 ( & V_4 -> V_22 , V_53 ) ;
ASSERT ( V_4 -> V_22 == V_242 -> V_22 ) ;
V_181 = F_41 ( V_2 , 1 , V_4 ) ;
V_243 = F_41 ( V_2 , 1 , V_242 ) ;
F_83 ( V_2 , V_181 , V_243 , V_131 ) ;
V_178 = F_42 ( V_2 , 1 , V_4 ) ;
V_244 = F_42 ( V_2 , 1 , V_242 ) ;
#ifdef F_103
for ( V_64 = 0 ; V_64 < V_131 ; V_64 ++ ) {
int error ;
error = F_21 ( V_2 , V_244 , V_64 , V_5 - 1 ) ;
if ( error ) {
F_90 ( V_2 , V_176 ) ;
return error ;
}
}
#endif
F_85 ( V_2 , V_178 , V_244 , V_131 ) ;
V_2 -> V_23 -> V_263 ( V_2 , V_241 ) ;
F_105 ( V_2 , free ) ;
V_2 -> V_66 [ V_5 - 1 ] = NULL ;
F_134 ( & V_4 -> V_21 , - 1 ) ;
F_94 ( V_2 -> V_67 , V_97 ,
V_247 | F_95 ( V_2 -> V_39 . V_70 . V_98 ) ) ;
V_2 -> V_65 -- ;
V_173:
F_90 ( V_2 , V_162 ) ;
return 0 ;
}
STATIC int
F_142 (
struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_5 ,
union V_51 * V_246 )
{
int error ;
F_90 ( V_2 , V_160 ) ;
F_105 ( V_2 , V_262 ) ;
V_2 -> V_23 -> V_249 ( V_2 , V_246 , - 1 ) ;
error = V_2 -> V_23 -> V_263 ( V_2 , V_7 ) ;
if ( error ) {
F_90 ( V_2 , V_176 ) ;
return error ;
}
F_105 ( V_2 , free ) ;
V_2 -> V_66 [ V_5 ] = NULL ;
V_2 -> V_79 [ V_5 ] = 0 ;
V_2 -> V_65 -- ;
F_90 ( V_2 , V_162 ) ;
return 0 ;
}
STATIC int
F_143 (
struct V_1 * V_2 ,
int V_5 ,
int * V_170 )
{
int error ;
int V_64 ;
if ( V_5 > 0 ) {
error = F_106 ( V_2 , V_5 , & V_64 ) ;
if ( error )
return error ;
}
F_90 ( V_2 , V_162 ) ;
* V_170 = 1 ;
return 0 ;
}
STATIC int
F_144 (
struct V_1 * V_2 ,
int V_5 ,
int * V_170 )
{
struct V_3 * V_4 ;
union V_51 V_264 ;
struct V_6 * V_7 ;
int error ;
int V_64 ;
union V_94 V_157 ;
union V_94 * V_193 = & V_157 ;
union V_51 V_201 ;
struct V_6 * V_197 ;
struct V_3 * V_121 ;
int V_198 = 0 ;
int V_52 ;
union V_51 V_214 ;
struct V_6 * V_199 ;
struct V_3 * V_122 ;
struct V_3 * V_222 ;
struct V_6 * V_221 ;
int V_200 = 0 ;
struct V_1 * V_213 ;
int V_131 ;
F_90 ( V_2 , V_160 ) ;
F_102 ( V_2 , V_5 ) ;
V_213 = NULL ;
V_52 = V_2 -> V_78 [ V_5 ] ;
if ( V_52 == 0 ) {
F_90 ( V_2 , V_162 ) ;
* V_170 = 0 ;
return 0 ;
}
V_4 = F_46 ( V_2 , V_5 , & V_7 ) ;
V_131 = F_104 ( V_4 ) ;
#ifdef F_103
error = F_17 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( error )
goto V_171;
#endif
if ( V_52 > V_131 ) {
F_90 ( V_2 , V_162 ) ;
* V_170 = 0 ;
return 0 ;
}
F_105 ( V_2 , V_265 ) ;
F_115 ( V_2 , V_206 , V_131 - V_52 ) ;
if ( V_5 > 0 ) {
union V_94 * V_207 ;
union V_51 * V_208 ;
V_207 = F_41 ( V_2 , V_52 + 1 , V_4 ) ;
V_208 = F_42 ( V_2 , V_52 + 1 , V_4 ) ;
#ifdef F_103
for ( V_64 = 0 ; V_64 < V_131 - V_52 ; V_64 ++ ) {
error = F_21 ( V_2 , V_208 , V_64 , V_5 ) ;
if ( error )
goto V_171;
}
#endif
if ( V_52 < V_131 ) {
F_86 ( V_2 , V_207 , - 1 , V_131 - V_52 ) ;
F_88 ( V_2 , V_208 , - 1 , V_131 - V_52 ) ;
F_89 ( V_2 , V_7 , V_52 , V_131 - 1 ) ;
F_97 ( V_2 , V_7 , V_52 , V_131 - 1 ) ;
}
if ( V_52 == 1 )
V_193 = F_41 ( V_2 , 1 , V_4 ) ;
} else {
if ( V_52 < V_131 ) {
F_87 ( V_2 ,
F_40 ( V_2 , V_52 + 1 , V_4 ) ,
- 1 , V_131 - V_52 ) ;
F_96 ( V_2 , V_7 , V_52 , V_131 - 1 ) ;
}
if ( V_52 == 1 ) {
V_2 -> V_23 -> V_182 ( & V_157 ,
F_40 ( V_2 , 1 , V_4 ) ) ;
V_193 = & V_157 ;
}
}
F_116 ( V_4 , -- V_131 ) ;
F_98 ( V_2 , V_7 , V_212 ) ;
if ( F_76 ( V_2 , V_4 , V_5 ) ) {
V_2 -> V_23 -> V_195 ( V_2 , V_4 , NULL ,
V_52 , V_266 ) ;
}
if ( V_5 == V_2 -> V_65 - 1 ) {
if ( V_2 -> V_46 & V_101 ) {
F_135 ( V_2 -> V_39 . V_70 . V_97 , - 1 ,
V_2 -> V_39 . V_70 . V_98 ) ;
error = F_141 ( V_2 ) ;
if ( error )
goto V_171;
error = F_143 ( V_2 , V_5 , V_170 ) ;
if ( error )
goto V_171;
* V_170 = 1 ;
return 0 ;
}
if ( V_131 == 1 && V_5 > 0 ) {
union V_51 * V_178 ;
V_178 = F_42 ( V_2 , 1 , V_4 ) ;
error = F_142 ( V_2 , V_7 , V_5 , V_178 ) ;
if ( error )
goto V_171;
} else if ( V_5 > 0 ) {
error = F_143 ( V_2 , V_5 , V_170 ) ;
if ( error )
goto V_171;
}
* V_170 = 1 ;
return 0 ;
}
if ( V_52 == 1 ) {
error = F_110 ( V_2 , V_193 , V_5 + 1 ) ;
if ( error )
goto V_171;
}
if ( V_131 >= V_2 -> V_23 -> V_267 ( V_2 , V_5 ) ) {
error = F_143 ( V_2 , V_5 , V_170 ) ;
if ( error )
goto V_171;
return 0 ;
}
F_69 ( V_2 , V_4 , & V_214 , V_127 ) ;
F_69 ( V_2 , V_4 , & V_201 , V_126 ) ;
if ( V_2 -> V_46 & V_101 ) {
if ( F_67 ( V_2 , & V_214 ) &&
F_67 ( V_2 , & V_201 ) &&
V_5 == V_2 -> V_65 - 2 ) {
error = F_141 ( V_2 ) ;
if ( ! error )
error = F_143 ( V_2 , V_5 , V_170 ) ;
if ( error )
goto V_171;
return 0 ;
}
}
ASSERT ( ! F_67 ( V_2 , & V_214 ) ||
! F_67 ( V_2 , & V_201 ) ) ;
error = F_32 ( V_2 , & V_213 ) ;
if ( error )
goto V_171;
if ( ! F_67 ( V_2 , & V_214 ) ) {
V_64 = F_54 ( V_213 , V_5 ) ;
F_118 ( V_2 -> V_11 , V_64 == 1 , V_171 ) ;
error = F_101 ( V_213 , V_5 , & V_64 ) ;
if ( error )
goto V_171;
F_118 ( V_2 -> V_11 , V_64 == 1 , V_171 ) ;
V_64 = F_54 ( V_213 , V_5 ) ;
F_118 ( V_2 -> V_11 , V_64 == 1 , V_171 ) ;
V_122 = F_46 ( V_213 , V_5 , & V_199 ) ;
#ifdef F_103
error = F_17 ( V_213 , V_122 , V_5 , V_199 ) ;
if ( error )
goto V_171;
#endif
F_69 ( V_213 , V_122 , & V_264 , V_126 ) ;
if ( F_104 ( V_122 ) - 1 >=
V_2 -> V_23 -> V_267 ( V_213 , V_5 ) ) {
error = F_114 ( V_213 , V_5 , & V_64 ) ;
if ( error )
goto V_171;
if ( V_64 ) {
ASSERT ( F_104 ( V_4 ) >=
V_2 -> V_23 -> V_267 ( V_213 , V_5 ) ) ;
F_29 ( V_213 , V_217 ) ;
V_213 = NULL ;
error = F_143 ( V_2 , V_5 , V_170 ) ;
if ( error )
goto V_171;
return 0 ;
}
}
V_200 = F_104 ( V_122 ) ;
if ( ! F_67 ( V_2 , & V_201 ) ) {
V_64 = F_53 ( V_213 , V_5 ) ;
F_118 ( V_2 -> V_11 , V_64 == 1 , V_171 ) ;
error = F_106 ( V_213 , V_5 , & V_64 ) ;
if ( error )
goto V_171;
F_118 ( V_2 -> V_11 , V_64 == 1 , V_171 ) ;
}
}
if ( ! F_67 ( V_2 , & V_201 ) ) {
V_64 = F_53 ( V_213 , V_5 ) ;
F_118 ( V_2 -> V_11 , V_64 == 1 , V_171 ) ;
error = F_106 ( V_213 , V_5 , & V_64 ) ;
if ( error )
goto V_171;
V_64 = F_53 ( V_213 , V_5 ) ;
F_118 ( V_2 -> V_11 , V_64 == 1 , V_171 ) ;
V_121 = F_46 ( V_213 , V_5 , & V_197 ) ;
#ifdef F_103
error = F_17 ( V_2 , V_121 , V_5 , V_197 ) ;
if ( error )
goto V_171;
#endif
F_69 ( V_213 , V_121 , & V_264 , V_127 ) ;
if ( F_104 ( V_121 ) - 1 >=
V_2 -> V_23 -> V_267 ( V_213 , V_5 ) ) {
error = F_117 ( V_213 , V_5 , & V_64 ) ;
if ( error )
goto V_171;
if ( V_64 ) {
ASSERT ( F_104 ( V_4 ) >=
V_2 -> V_23 -> V_267 ( V_213 , V_5 ) ) ;
F_29 ( V_213 , V_217 ) ;
V_213 = NULL ;
if ( V_5 == 0 )
V_2 -> V_78 [ 0 ] ++ ;
F_90 ( V_2 , V_162 ) ;
* V_170 = 1 ;
return 0 ;
}
}
V_198 = F_104 ( V_121 ) ;
}
F_29 ( V_213 , V_217 ) ;
V_213 = NULL ;
ASSERT ( ! F_67 ( V_2 , & V_264 ) ) ;
if ( ! F_67 ( V_2 , & V_201 ) &&
V_198 + F_104 ( V_4 ) <=
V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ) {
V_214 = V_264 ;
V_122 = V_4 ;
V_199 = V_7 ;
error = F_82 ( V_2 , & V_201 , 0 , & V_121 , & V_197 ) ;
if ( error )
goto V_171;
} else if ( ! F_67 ( V_2 , & V_214 ) &&
V_200 + F_104 ( V_4 ) <=
V_2 -> V_23 -> V_24 ( V_2 , V_5 ) ) {
V_201 = V_264 ;
V_121 = V_4 ;
V_197 = V_7 ;
error = F_82 ( V_2 , & V_214 , 0 , & V_122 , & V_199 ) ;
if ( error )
goto V_171;
} else {
error = F_143 ( V_2 , V_5 , V_170 ) ;
if ( error )
goto V_171;
return 0 ;
}
V_200 = F_104 ( V_122 ) ;
V_198 = F_104 ( V_121 ) ;
F_115 ( V_2 , V_206 , V_200 ) ;
if ( V_5 > 0 ) {
union V_94 * V_207 ;
union V_51 * V_208 ;
union V_94 * V_202 ;
union V_51 * V_203 ;
V_207 = F_41 ( V_2 , V_198 + 1 , V_121 ) ;
V_208 = F_42 ( V_2 , V_198 + 1 , V_121 ) ;
V_202 = F_41 ( V_2 , 1 , V_122 ) ;
V_203 = F_42 ( V_2 , 1 , V_122 ) ;
#ifdef F_103
for ( V_64 = 1 ; V_64 < V_200 ; V_64 ++ ) {
error = F_21 ( V_2 , V_203 , V_64 , V_5 ) ;
if ( error )
goto V_171;
}
#endif
F_83 ( V_2 , V_207 , V_202 , V_200 ) ;
F_85 ( V_2 , V_208 , V_203 , V_200 ) ;
F_89 ( V_2 , V_197 , V_198 + 1 , V_198 + V_200 ) ;
F_97 ( V_2 , V_197 , V_198 + 1 , V_198 + V_200 ) ;
} else {
union V_93 * V_210 ;
union V_93 * V_204 ;
V_210 = F_40 ( V_2 , V_198 + 1 , V_121 ) ;
V_204 = F_40 ( V_2 , 1 , V_122 ) ;
F_84 ( V_2 , V_210 , V_204 , V_200 ) ;
F_96 ( V_2 , V_197 , V_198 + 1 , V_198 + V_200 ) ;
}
F_105 ( V_2 , V_268 ) ;
F_116 ( V_121 , V_198 + V_200 ) ;
F_69 ( V_2 , V_122 , & V_264 , V_127 ) ,
F_70 ( V_2 , V_121 , & V_264 , V_127 ) ;
F_98 ( V_2 , V_197 , V_212 | V_127 ) ;
F_69 ( V_2 , V_121 , & V_264 , V_127 ) ;
if ( ! F_67 ( V_2 , & V_264 ) ) {
error = F_82 ( V_2 , & V_264 , 0 , & V_222 , & V_221 ) ;
if ( error )
goto V_171;
F_70 ( V_2 , V_222 , & V_201 , V_126 ) ;
F_98 ( V_2 , V_221 , V_126 ) ;
}
error = V_2 -> V_23 -> V_263 ( V_2 , V_199 ) ;
if ( error )
goto V_171;
F_105 ( V_2 , free ) ;
if ( V_7 != V_197 ) {
V_2 -> V_66 [ V_5 ] = V_197 ;
V_2 -> V_78 [ V_5 ] += V_198 ;
V_2 -> V_79 [ V_5 ] = 0 ;
}
else if ( ( V_2 -> V_46 & V_101 ) ||
( V_5 + 1 < V_2 -> V_65 ) ) {
error = F_101 ( V_2 , V_5 + 1 , & V_64 ) ;
if ( error )
goto V_171;
}
if ( V_5 > 0 )
V_2 -> V_78 [ V_5 ] -- ;
F_90 ( V_2 , V_162 ) ;
* V_170 = 2 ;
return 0 ;
V_171:
F_90 ( V_2 , V_176 ) ;
if ( V_213 )
F_29 ( V_213 , V_218 ) ;
return error ;
}
int
F_145 (
struct V_1 * V_2 ,
int * V_170 )
{
int error ;
int V_5 ;
int V_64 ;
F_90 ( V_2 , V_160 ) ;
for ( V_5 = 0 , V_64 = 2 ; V_64 == 2 ; V_5 ++ ) {
error = F_144 ( V_2 , V_5 , & V_64 ) ;
if ( error )
goto V_171;
}
if ( V_64 == 0 ) {
for ( V_5 = 1 ; V_5 < V_2 -> V_65 ; V_5 ++ ) {
if ( V_2 -> V_78 [ V_5 ] == 0 ) {
error = F_106 ( V_2 , V_5 , & V_64 ) ;
if ( error )
goto V_171;
break;
}
}
}
F_90 ( V_2 , V_162 ) ;
* V_170 = V_64 ;
return 0 ;
V_171:
F_90 ( V_2 , V_176 ) ;
return error ;
}
int
F_146 (
struct V_1 * V_2 ,
union V_93 * * V_255 ,
int * V_170 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int V_52 ;
#ifdef F_103
int error ;
#endif
V_52 = V_2 -> V_78 [ 0 ] ;
V_4 = F_46 ( V_2 , 0 , & V_7 ) ;
#ifdef F_103
error = F_17 ( V_2 , V_4 , 0 , V_7 ) ;
if ( error )
return error ;
#endif
if ( V_52 > F_104 ( V_4 ) || V_52 <= 0 ) {
* V_170 = 0 ;
return 0 ;
}
* V_255 = F_40 ( V_2 , V_52 , V_4 ) ;
* V_170 = 1 ;
return 0 ;
}
static int
F_147 (
struct V_1 * V_2 ,
int V_5 ,
T_17 V_269 ,
struct V_270 * V_271 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
union V_51 V_214 ;
F_63 ( V_2 , V_5 , V_124 ) ;
V_4 = F_46 ( V_2 , V_5 , & V_7 ) ;
if ( V_2 -> V_46 & V_47 )
V_4 -> V_13 . V_14 . V_134 = F_4 ( V_269 ) ;
else
V_4 -> V_13 . V_42 . V_134 = F_16 ( V_269 ) ;
if ( V_7 ) {
if ( V_2 -> V_67 ) {
F_148 ( V_2 -> V_67 , V_7 ) ;
F_98 ( V_2 , V_7 , V_272 ) ;
} else {
F_149 ( V_7 , V_271 ) ;
}
} else {
ASSERT ( V_2 -> V_46 & V_101 ) ;
ASSERT ( V_5 == V_2 -> V_65 - 1 ) ;
}
F_69 ( V_2 , V_4 , & V_214 , V_127 ) ;
if ( F_67 ( V_2 , & V_214 ) )
return - V_273 ;
return F_107 ( V_2 , V_5 , & V_214 , & V_4 ) ;
}
int
F_150 (
struct V_1 * V_2 ,
T_17 V_269 ,
struct V_270 * V_271 )
{
union V_51 V_201 ;
int V_5 ;
struct V_3 * V_4 = NULL ;
int error = 0 ;
V_2 -> V_23 -> V_185 ( V_2 , & V_201 ) ;
for ( V_5 = V_2 -> V_65 - 1 ; V_5 >= 0 ; V_5 -- ) {
error = F_107 ( V_2 , V_5 , & V_201 , & V_4 ) ;
if ( error )
return error ;
if ( V_5 > 0 ) {
union V_51 * V_52 ;
V_52 = F_42 ( V_2 , 1 , V_4 ) ;
F_65 ( V_2 , V_52 , 1 ) ;
V_201 = * V_52 ;
}
do {
error = F_147 ( V_2 , V_5 ,
V_269 ,
V_271 ) ;
} while ( ! error );
if ( error != - V_273 )
return error ;
}
return 0 ;
}
