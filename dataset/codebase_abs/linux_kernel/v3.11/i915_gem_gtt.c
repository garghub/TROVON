static T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 ,
enum V_4 V_5 )
{
T_1 V_6 = V_7 ;
V_6 |= F_2 ( V_3 ) ;
switch ( V_5 ) {
case V_8 :
V_6 |= V_9 ;
break;
case V_10 :
V_6 |= V_11 ;
break;
case V_12 :
V_6 |= V_13 ;
break;
default:
F_3 () ;
}
return V_6 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
T_2 V_3 ,
enum V_4 V_5 )
{
T_1 V_6 = V_7 ;
V_6 |= F_2 ( V_3 ) ;
V_6 |= V_14 ;
if ( V_5 != V_12 )
V_6 |= V_15 ;
return V_6 ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
T_2 V_3 ,
enum V_4 V_5 )
{
T_1 V_6 = V_7 ;
V_6 |= F_2 ( V_3 ) ;
if ( V_5 != V_12 )
V_6 |= V_11 ;
return V_6 ;
}
static void F_6 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_2 -> V_20 ;
T_1 T_3 * V_21 ;
T_4 V_22 ;
int V_23 ;
F_7 ( V_17 -> V_24 & 0x3f ) ;
V_21 = ( T_1 T_3 * ) V_19 -> V_25 . V_26 +
V_17 -> V_24 / sizeof( T_1 ) ;
for ( V_23 = 0 ; V_23 < V_17 -> V_27 ; V_23 ++ ) {
T_2 V_28 ;
V_28 = V_17 -> V_29 [ V_23 ] ;
V_22 = F_8 ( V_28 ) ;
V_22 |= V_30 ;
F_9 ( V_22 , V_21 + V_23 ) ;
}
F_10 ( V_21 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_5 * V_19 = V_2 -> V_20 ;
T_4 V_24 ;
struct V_31 * V_32 ;
struct V_16 * V_17 = V_19 -> V_33 . V_34 ;
int V_23 ;
F_12 ( V_17 -> V_24 & 0x3f ) ;
F_6 ( V_17 ) ;
V_24 = V_17 -> V_24 ;
V_24 /= 64 ;
V_24 <<= 16 ;
if ( F_13 ( V_2 ) -> V_35 == 6 ) {
T_4 V_36 , V_37 , V_38 ;
V_38 = F_14 ( V_39 ) ;
F_15 ( V_39 , V_38 | V_40 |
V_41 ) ;
V_37 = F_14 ( V_42 ) ;
F_15 ( V_42 , V_37 | V_43 ) ;
V_36 = F_14 ( V_44 ) ;
F_15 ( V_44 , V_36 | V_45 |
V_46 ) ;
F_15 ( V_47 , F_16 ( V_48 ) ) ;
} else if ( F_13 ( V_2 ) -> V_35 >= 7 ) {
T_4 V_36 , V_38 ;
V_38 = F_14 ( V_39 ) ;
F_15 ( V_39 , V_38 | V_41 ) ;
V_36 = F_14 ( V_44 ) ;
if ( F_17 ( V_2 ) ) {
V_36 |= V_49 ;
} else {
V_36 |= V_50 ;
V_36 &= ~ V_51 ;
}
F_15 ( V_44 , V_36 ) ;
}
F_18 (ring, dev_priv, i) {
if ( F_13 ( V_2 ) -> V_35 >= 7 )
F_15 ( F_19 ( V_32 ) ,
F_16 ( V_48 ) ) ;
F_15 ( F_20 ( V_32 ) , V_52 ) ;
F_15 ( F_21 ( V_32 ) , V_24 ) ;
}
return 0 ;
}
static void F_22 ( struct V_16 * V_17 ,
unsigned V_53 ,
unsigned V_54 )
{
T_1 * V_55 , V_56 ;
unsigned V_57 = V_53 / V_58 ;
unsigned V_59 = V_53 % V_58 ;
unsigned V_60 , V_23 ;
V_56 = V_17 -> V_61 ( V_17 -> V_2 ,
V_17 -> V_62 ,
V_10 ) ;
while ( V_54 ) {
V_60 = V_59 + V_54 ;
if ( V_60 > V_58 )
V_60 = V_58 ;
V_55 = F_23 ( V_17 -> V_63 [ V_57 ] ) ;
for ( V_23 = V_59 ; V_23 < V_60 ; V_23 ++ )
V_55 [ V_23 ] = V_56 ;
F_24 ( V_55 ) ;
V_54 -= V_60 - V_59 ;
V_59 = 0 ;
V_57 ++ ;
}
}
static void F_25 ( struct V_16 * V_17 ,
struct V_64 * V_65 ,
unsigned V_53 ,
enum V_4 V_66 )
{
T_1 * V_55 ;
unsigned V_57 = V_53 / V_58 ;
unsigned V_67 = V_53 % V_58 ;
struct V_68 V_69 ;
V_55 = F_23 ( V_17 -> V_63 [ V_57 ] ) ;
F_26 (pages->sgl, &sg_iter, pages->nents, 0 ) {
T_2 V_70 ;
V_70 = F_27 ( & V_69 ) ;
V_55 [ V_67 ] = V_17 -> V_61 ( V_17 -> V_2 , V_70 ,
V_66 ) ;
if ( ++ V_67 == V_58 ) {
F_24 ( V_55 ) ;
V_57 ++ ;
V_55 = F_23 ( V_17 -> V_63 [ V_57 ] ) ;
V_67 = 0 ;
}
}
F_24 ( V_55 ) ;
}
static void F_28 ( struct V_16 * V_17 )
{
int V_23 ;
if ( V_17 -> V_29 ) {
for ( V_23 = 0 ; V_23 < V_17 -> V_27 ; V_23 ++ )
F_29 ( V_17 -> V_2 -> V_71 ,
V_17 -> V_29 [ V_23 ] ,
4096 , V_72 ) ;
}
F_30 ( V_17 -> V_29 ) ;
for ( V_23 = 0 ; V_23 < V_17 -> V_27 ; V_23 ++ )
F_31 ( V_17 -> V_63 [ V_23 ] ) ;
F_30 ( V_17 -> V_63 ) ;
F_30 ( V_17 ) ;
}
static int F_32 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned V_73 ;
int V_23 ;
int V_74 = - V_75 ;
V_73 = F_33 ( V_19 -> V_25 ) ;
if ( F_17 ( V_2 ) ) {
V_17 -> V_61 = F_5 ;
} else if ( F_34 ( V_2 ) ) {
V_17 -> V_61 = F_4 ;
} else {
V_17 -> V_61 = F_1 ;
}
V_17 -> V_27 = V_76 ;
V_17 -> V_77 = F_11 ;
V_17 -> V_78 = F_22 ;
V_17 -> V_79 = F_25 ;
V_17 -> V_80 = F_28 ;
V_17 -> V_63 = F_35 ( sizeof( struct V_81 * ) * V_17 -> V_27 ,
V_82 ) ;
if ( ! V_17 -> V_63 )
return - V_75 ;
for ( V_23 = 0 ; V_23 < V_17 -> V_27 ; V_23 ++ ) {
V_17 -> V_63 [ V_23 ] = F_36 ( V_82 ) ;
if ( ! V_17 -> V_63 [ V_23 ] )
goto V_83;
}
V_17 -> V_29 = F_35 ( sizeof( T_2 ) * V_17 -> V_27 ,
V_82 ) ;
if ( ! V_17 -> V_29 )
goto V_83;
for ( V_23 = 0 ; V_23 < V_17 -> V_27 ; V_23 ++ ) {
T_2 V_28 ;
V_28 = F_37 ( V_2 -> V_71 , V_17 -> V_63 [ V_23 ] , 0 , 4096 ,
V_72 ) ;
if ( F_38 ( V_2 -> V_71 , V_28 ) ) {
V_74 = - V_84 ;
goto V_85;
}
V_17 -> V_29 [ V_23 ] = V_28 ;
}
V_17 -> V_78 ( V_17 , 0 ,
V_17 -> V_27 * V_58 ) ;
V_17 -> V_24 = V_73 * sizeof( T_1 ) ;
return 0 ;
V_85:
if ( V_17 -> V_29 ) {
for ( V_23 -- ; V_23 >= 0 ; V_23 -- )
F_29 ( V_2 -> V_71 , V_17 -> V_29 [ V_23 ] ,
4096 , V_72 ) ;
}
V_83:
F_30 ( V_17 -> V_29 ) ;
for ( V_23 = 0 ; V_23 < V_17 -> V_27 ; V_23 ++ ) {
if ( V_17 -> V_63 [ V_23 ] )
F_31 ( V_17 -> V_63 [ V_23 ] ) ;
}
F_30 ( V_17 -> V_63 ) ;
return V_74 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
struct V_16 * V_17 ;
int V_74 ;
V_17 = F_35 ( sizeof( * V_17 ) , V_82 ) ;
if ( ! V_17 )
return - V_75 ;
V_17 -> V_2 = V_2 ;
V_17 -> V_62 = V_19 -> V_25 . V_86 ;
if ( F_13 ( V_2 ) -> V_35 < 8 )
V_74 = F_32 ( V_17 ) ;
else
F_3 () ;
if ( V_74 )
F_30 ( V_17 ) ;
else
V_19 -> V_33 . V_34 = V_17 ;
return V_74 ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
struct V_16 * V_17 = V_19 -> V_33 . V_34 ;
if ( ! V_17 )
return;
V_17 -> V_80 ( V_17 ) ;
V_19 -> V_33 . V_34 = NULL ;
}
void F_41 ( struct V_16 * V_17 ,
struct V_87 * V_88 ,
enum V_4 V_66 )
{
V_17 -> V_79 ( V_17 , V_88 -> V_65 ,
V_88 -> V_89 -> V_90 >> V_91 ,
V_66 ) ;
}
void F_42 ( struct V_16 * V_17 ,
struct V_87 * V_88 )
{
V_17 -> V_78 ( V_17 ,
V_88 -> V_89 -> V_90 >> V_91 ,
V_88 -> V_92 . V_93 >> V_91 ) ;
}
static inline bool F_43 ( struct V_1 * V_2 )
{
#ifdef F_44
if ( F_45 ( V_2 ) && F_46 ( V_2 ) && V_94 )
return true ;
#endif
return false ;
}
static bool F_47 ( struct V_18 * V_19 )
{
bool V_74 = V_19 -> V_33 . V_95 ;
if ( F_48 ( V_19 -> V_25 . V_96 ) ) {
V_19 -> V_33 . V_95 = false ;
if ( F_49 ( V_19 -> V_2 ) ) {
F_50 ( L_1 ) ;
F_51 ( 10 ) ;
}
}
return V_74 ;
}
static void F_52 ( struct V_18 * V_19 , bool V_95 )
{
if ( F_48 ( V_19 -> V_25 . V_96 ) )
V_19 -> V_33 . V_95 = V_95 ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
struct V_87 * V_88 ;
V_19 -> V_25 . V_97 ( V_2 , V_19 -> V_25 . V_90 / V_98 ,
V_19 -> V_25 . V_99 / V_98 ) ;
F_54 (obj, &dev_priv->mm.bound_list, global_list) {
F_55 ( V_88 ) ;
F_56 ( V_88 , V_88 -> V_66 ) ;
}
F_57 ( V_2 ) ;
}
int F_58 ( struct V_87 * V_88 )
{
if ( V_88 -> V_100 )
return 0 ;
if ( ! F_59 ( & V_88 -> V_92 . V_2 -> V_71 -> V_2 ,
V_88 -> V_65 -> V_101 , V_88 -> V_65 -> V_102 ,
V_72 ) )
return - V_103 ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_64 * V_104 ,
unsigned int V_53 ,
enum V_4 V_5 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
T_1 T_3 * V_105 =
( T_1 T_3 * ) V_19 -> V_25 . V_26 + V_53 ;
int V_23 = 0 ;
struct V_68 V_69 ;
T_2 V_3 ;
F_26 (st->sgl, &sg_iter, st->nents, 0 ) {
V_3 = F_27 ( & V_69 ) ;
F_61 ( V_19 -> V_25 . V_61 ( V_2 , V_3 , V_5 ) ,
& V_105 [ V_23 ] ) ;
V_23 ++ ;
}
if ( V_23 != 0 )
F_7 ( F_10 ( & V_105 [ V_23 - 1 ] )
!= V_19 -> V_25 . V_61 ( V_2 , V_3 , V_5 ) ) ;
F_15 ( V_106 , V_107 ) ;
F_62 ( V_106 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
unsigned int V_53 ,
unsigned int V_54 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
T_1 V_56 , T_3 * V_108 =
( T_1 T_3 * ) V_19 -> V_25 . V_26 + V_53 ;
const int V_109 = F_33 ( V_19 -> V_25 ) - V_53 ;
int V_23 ;
if ( F_64 ( V_54 > V_109 ,
L_2 ,
V_53 , V_54 , V_109 ) )
V_54 = V_109 ;
V_56 = V_19 -> V_25 . V_61 ( V_2 ,
V_19 -> V_25 . V_86 ,
V_10 ) ;
for ( V_23 = 0 ; V_23 < V_54 ; V_23 ++ )
F_61 ( V_56 , & V_108 [ V_23 ] ) ;
F_10 ( V_108 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_64 * V_104 ,
unsigned int V_110 ,
enum V_4 V_66 )
{
unsigned int V_111 = ( V_66 == V_12 ) ?
V_112 : V_113 ;
F_66 ( V_104 , V_110 , V_111 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
unsigned int V_53 ,
unsigned int V_54 )
{
F_68 ( V_53 , V_54 ) ;
}
void F_56 ( struct V_87 * V_88 ,
enum V_4 V_66 )
{
struct V_1 * V_2 = V_88 -> V_92 . V_2 ;
struct V_18 * V_19 = V_2 -> V_20 ;
V_19 -> V_25 . V_114 ( V_2 , V_88 -> V_65 ,
V_88 -> V_89 -> V_90 >> V_91 ,
V_66 ) ;
V_88 -> V_115 = 1 ;
}
void F_69 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_92 . V_2 ;
struct V_18 * V_19 = V_2 -> V_20 ;
V_19 -> V_25 . V_97 ( V_88 -> V_92 . V_2 ,
V_88 -> V_89 -> V_90 >> V_91 ,
V_88 -> V_92 . V_93 >> V_91 ) ;
V_88 -> V_115 = 0 ;
}
void F_70 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_92 . V_2 ;
struct V_18 * V_19 = V_2 -> V_20 ;
bool V_95 ;
V_95 = F_47 ( V_19 ) ;
if ( ! V_88 -> V_100 )
F_71 ( & V_2 -> V_71 -> V_2 ,
V_88 -> V_65 -> V_101 , V_88 -> V_65 -> V_102 ,
V_72 ) ;
F_52 ( V_19 , V_95 ) ;
}
static void F_72 ( struct V_116 * V_117 ,
unsigned long V_118 ,
unsigned long * V_90 ,
unsigned long * V_119 )
{
if ( V_117 -> V_118 != V_118 )
* V_90 += 4096 ;
if ( ! F_73 ( & V_117 -> V_120 ) ) {
V_117 = F_74 ( V_117 -> V_120 . V_121 ,
struct V_116 ,
V_120 ) ;
if ( V_117 -> V_122 && V_117 -> V_118 != V_118 )
* V_119 -= 4096 ;
}
}
void F_75 ( struct V_1 * V_2 ,
unsigned long V_90 ,
unsigned long V_123 ,
unsigned long V_119 )
{
T_5 * V_19 = V_2 -> V_20 ;
struct V_116 * V_124 ;
struct V_87 * V_88 ;
unsigned long V_125 , V_126 ;
F_12 ( V_123 > V_119 ) ;
F_76 ( & V_19 -> V_33 . V_89 , V_90 , V_119 - V_90 - V_98 ) ;
if ( ! F_77 ( V_2 ) )
V_19 -> V_33 . V_89 . V_127 = F_72 ;
F_54 (obj, &dev_priv->mm.bound_list, global_list) {
F_78 ( L_3 ,
V_88 -> V_128 , V_88 -> V_92 . V_93 ) ;
F_12 ( V_88 -> V_89 != V_129 ) ;
V_88 -> V_89 = F_79 ( & V_19 -> V_33 . V_89 ,
V_88 -> V_128 ,
V_88 -> V_92 . V_93 ,
false ) ;
V_88 -> V_115 = 1 ;
}
V_19 -> V_25 . V_90 = V_90 ;
V_19 -> V_25 . V_99 = V_119 - V_90 ;
F_80 (entry, &dev_priv->mm.gtt_space,
hole_start, hole_end) {
F_78 ( L_4 ,
V_125 , V_126 ) ;
V_19 -> V_25 . V_97 ( V_2 , V_125 / V_98 ,
( V_126 - V_125 ) / V_98 ) ;
}
V_19 -> V_25 . V_97 ( V_2 , V_119 / V_98 - 1 , 1 ) ;
}
static bool
F_81 ( struct V_1 * V_2 )
{
if ( V_130 >= 0 )
return V_130 ;
#ifdef F_44
if ( F_13 ( V_2 ) -> V_35 == 6 && V_94 )
return false ;
#endif
return true ;
}
void F_82 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned long V_131 , V_132 ;
V_131 = V_19 -> V_25 . V_99 ;
V_132 = V_19 -> V_25 . V_123 ;
if ( F_81 ( V_2 ) && F_83 ( V_2 ) ) {
int V_74 ;
if ( F_13 ( V_2 ) -> V_35 <= 7 ) {
V_131 -= V_76 * V_98 ;
}
F_75 ( V_2 , 0 , V_132 , V_131 ) ;
V_74 = F_39 ( V_2 ) ;
if ( ! V_74 )
return;
F_50 ( L_5 , V_74 ) ;
F_84 ( & V_19 -> V_33 . V_89 ) ;
V_131 += V_76 * V_98 ;
}
F_75 ( V_2 , 0 , V_132 , V_131 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
struct V_81 * V_81 ;
T_2 V_133 ;
V_81 = F_36 ( V_82 | V_134 | V_135 ) ;
if ( V_81 == NULL )
return - V_75 ;
F_86 ( V_81 ) ;
F_87 ( V_81 , 1 ) ;
#ifdef F_44
V_133 = F_37 ( V_2 -> V_71 , V_81 , 0 , V_98 ,
V_72 ) ;
if ( F_38 ( V_2 -> V_71 , V_133 ) )
return - V_136 ;
#else
V_133 = F_88 ( V_81 ) ;
#endif
V_19 -> V_25 . V_137 = V_81 ;
V_19 -> V_25 . V_86 = V_133 ;
return 0 ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
F_90 ( V_19 -> V_25 . V_137 , 1 ) ;
F_29 ( V_2 -> V_71 , V_19 -> V_25 . V_86 ,
V_98 , V_72 ) ;
F_91 ( V_19 -> V_25 . V_137 ) ;
F_31 ( V_19 -> V_25 . V_137 ) ;
}
static inline unsigned int F_92 ( T_6 V_138 )
{
V_138 >>= V_139 ;
V_138 &= V_140 ;
return V_138 << 20 ;
}
static inline T_7 F_93 ( T_6 V_138 )
{
V_138 >>= V_141 ;
V_138 &= V_142 ;
return V_138 << 25 ;
}
static int F_94 ( struct V_1 * V_2 ,
T_7 * V_143 ,
T_7 * V_144 ,
T_8 * V_145 ,
unsigned long * V_123 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
T_8 V_146 ;
unsigned int V_131 ;
T_6 V_138 ;
int V_74 ;
* V_145 = F_95 ( V_2 -> V_71 , 2 ) ;
* V_123 = F_96 ( V_2 -> V_71 , 2 ) ;
if ( ( * V_123 < ( 64 << 20 ) || ( * V_123 > ( 512 << 20 ) ) ) ) {
F_50 ( L_6 ,
V_19 -> V_25 . V_123 ) ;
return - V_147 ;
}
if ( ! F_97 ( V_2 -> V_71 , F_98 ( 40 ) ) )
F_99 ( V_2 -> V_71 , F_98 ( 40 ) ) ;
F_100 ( V_2 -> V_71 , V_148 , & V_138 ) ;
V_131 = F_92 ( V_138 ) ;
* V_144 = F_93 ( V_138 ) ;
* V_143 = ( V_131 / sizeof( T_1 ) ) << V_91 ;
V_146 = F_95 ( V_2 -> V_71 , 0 ) +
( F_96 ( V_2 -> V_71 , 0 ) / 2 ) ;
V_19 -> V_25 . V_26 = F_101 ( V_146 , V_131 ) ;
if ( ! V_19 -> V_25 . V_26 ) {
F_50 ( L_7 ) ;
return - V_75 ;
}
V_74 = F_85 ( V_2 ) ;
if ( V_74 )
F_50 ( L_8 ) ;
V_19 -> V_25 . V_97 = F_63 ;
V_19 -> V_25 . V_114 = F_60 ;
return V_74 ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
F_103 ( V_19 -> V_25 . V_26 ) ;
F_89 ( V_19 -> V_2 ) ;
}
static int F_104 ( struct V_1 * V_2 ,
T_7 * V_143 ,
T_7 * V_144 ,
T_8 * V_145 ,
unsigned long * V_123 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
int V_74 ;
V_74 = F_105 ( V_19 -> V_149 , V_19 -> V_2 -> V_71 , NULL ) ;
if ( ! V_74 ) {
F_50 ( L_9 ) ;
return - V_84 ;
}
F_106 ( V_143 , V_144 , V_145 , V_123 ) ;
V_19 -> V_25 . V_96 = F_43 ( V_19 -> V_2 ) ;
V_19 -> V_25 . V_97 = F_67 ;
V_19 -> V_25 . V_114 = F_65 ;
return 0 ;
}
static void F_107 ( struct V_1 * V_2 )
{
F_108 () ;
}
int F_109 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
struct V_150 * V_25 = & V_19 -> V_25 ;
int V_74 ;
if ( F_13 ( V_2 ) -> V_35 <= 5 ) {
V_19 -> V_25 . V_151 = F_104 ;
V_19 -> V_25 . V_152 = F_107 ;
} else {
V_19 -> V_25 . V_151 = F_94 ;
V_19 -> V_25 . V_152 = F_102 ;
if ( F_17 ( V_2 ) ) {
V_19 -> V_25 . V_61 = F_5 ;
} else if ( F_34 ( V_2 ) ) {
V_19 -> V_25 . V_61 = F_4 ;
} else {
V_19 -> V_25 . V_61 = F_1 ;
}
}
V_74 = V_19 -> V_25 . V_151 ( V_2 , & V_19 -> V_25 . V_99 ,
& V_19 -> V_25 . V_153 ,
& V_25 -> V_145 ,
& V_25 -> V_123 ) ;
if ( V_74 )
return V_74 ;
F_110 ( L_10 ,
V_19 -> V_25 . V_99 >> 20 ) ;
F_111 ( L_11 ,
V_19 -> V_25 . V_123 >> 20 ) ;
F_111 ( L_12 ,
V_19 -> V_25 . V_153 >> 20 ) ;
return 0 ;
}
