static inline T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 ,
enum V_4 V_5 )
{
T_1 V_6 = V_7 ;
V_6 |= F_2 ( V_3 ) ;
switch ( V_5 ) {
case V_8 :
if ( F_3 ( V_2 ) )
V_6 |= V_9 ;
else
V_6 |= V_10 ;
break;
case V_11 :
V_6 |= V_9 ;
break;
case V_12 :
if ( F_3 ( V_2 ) )
V_6 |= V_13 ;
else
V_6 |= V_14 ;
break;
default:
F_4 () ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_3 * V_15 = V_2 -> V_16 ;
T_4 V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 = V_15 -> V_22 . V_23 ;
T_1 T_5 * V_24 ;
T_4 V_25 ;
int V_26 ;
V_24 = ( T_1 T_5 * ) V_15 -> V_27 . V_28 +
V_21 -> V_17 / sizeof( T_1 ) ;
for ( V_26 = 0 ; V_26 < V_21 -> V_29 ; V_26 ++ ) {
T_2 V_30 ;
V_30 = V_21 -> V_31 [ V_26 ] ;
V_25 = F_6 ( V_30 ) ;
V_25 |= V_32 ;
F_7 ( V_25 , V_24 + V_26 ) ;
}
F_8 ( V_24 ) ;
V_17 = V_21 -> V_17 ;
V_17 /= 64 ;
V_17 <<= 16 ;
if ( F_9 ( V_2 ) -> V_33 == 6 ) {
T_4 V_34 , V_35 , V_36 ;
V_36 = F_10 ( V_37 ) ;
F_11 ( V_37 , V_36 | V_38 |
V_39 ) ;
V_35 = F_10 ( V_40 ) ;
F_11 ( V_40 , V_35 | V_41 ) ;
V_34 = F_10 ( V_42 ) ;
F_11 ( V_42 , V_34 | V_43 |
V_44 ) ;
F_11 ( V_45 , F_12 ( V_46 ) ) ;
} else if ( F_9 ( V_2 ) -> V_33 >= 7 ) {
T_4 V_34 , V_36 ;
V_36 = F_10 ( V_37 ) ;
F_11 ( V_37 , V_36 | V_39 ) ;
V_34 = F_10 ( V_42 ) ;
if ( F_3 ( V_2 ) ) {
V_34 |= V_47 ;
} else {
V_34 |= V_48 ;
V_34 &= ~ V_49 ;
}
F_11 ( V_42 , V_34 ) ;
}
F_13 (ring, dev_priv, i) {
if ( F_9 ( V_2 ) -> V_33 >= 7 )
F_11 ( F_14 ( V_19 ) ,
F_12 ( V_46 ) ) ;
F_11 ( F_15 ( V_19 ) , V_50 ) ;
F_11 ( F_16 ( V_19 ) , V_17 ) ;
}
return 0 ;
}
static void F_17 ( struct V_20 * V_21 ,
unsigned V_51 ,
unsigned V_52 )
{
T_1 * V_53 , V_54 ;
unsigned V_55 = V_51 / V_56 ;
unsigned V_57 = V_51 % V_56 ;
unsigned V_58 , V_26 ;
V_54 = F_1 ( V_21 -> V_2 ,
V_21 -> V_59 ,
V_11 ) ;
while ( V_52 ) {
V_58 = V_57 + V_52 ;
if ( V_58 > V_56 )
V_58 = V_56 ;
V_53 = F_18 ( V_21 -> V_60 [ V_55 ] ) ;
for ( V_26 = V_57 ; V_26 < V_58 ; V_26 ++ )
V_53 [ V_26 ] = V_54 ;
F_19 ( V_53 ) ;
V_52 -= V_58 - V_57 ;
V_57 = 0 ;
V_55 ++ ;
}
}
static void F_20 ( struct V_20 * V_21 ,
struct V_61 * V_62 ,
unsigned V_51 ,
enum V_4 V_63 )
{
T_1 * V_53 ;
unsigned V_55 = V_51 / V_56 ;
unsigned V_64 = V_51 % V_56 ;
struct V_65 V_66 ;
V_53 = F_18 ( V_21 -> V_60 [ V_55 ] ) ;
F_21 (pages->sgl, &sg_iter, pages->nents, 0 ) {
T_2 V_67 ;
V_67 = F_22 ( & V_66 ) ;
V_53 [ V_64 ] = F_1 ( V_21 -> V_2 , V_67 ,
V_63 ) ;
if ( ++ V_64 == V_56 ) {
F_19 ( V_53 ) ;
V_55 ++ ;
V_53 = F_18 ( V_21 -> V_60 [ V_55 ] ) ;
V_64 = 0 ;
}
}
F_19 ( V_53 ) ;
}
static void F_23 ( struct V_20 * V_21 )
{
int V_26 ;
if ( V_21 -> V_31 ) {
for ( V_26 = 0 ; V_26 < V_21 -> V_29 ; V_26 ++ )
F_24 ( V_21 -> V_2 -> V_68 ,
V_21 -> V_31 [ V_26 ] ,
4096 , V_69 ) ;
}
F_25 ( V_21 -> V_31 ) ;
for ( V_26 = 0 ; V_26 < V_21 -> V_29 ; V_26 ++ )
F_26 ( V_21 -> V_60 [ V_26 ] ) ;
F_25 ( V_21 -> V_60 ) ;
F_25 ( V_21 ) ;
}
static int F_27 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_70 * V_15 = V_2 -> V_16 ;
unsigned V_71 ;
int V_26 ;
int V_72 = - V_73 ;
V_71 = F_28 ( V_15 -> V_27 ) ;
V_21 -> V_29 = V_74 ;
V_21 -> V_75 = F_5 ;
V_21 -> V_76 = F_17 ;
V_21 -> V_77 = F_20 ;
V_21 -> V_78 = F_23 ;
V_21 -> V_60 = F_29 ( sizeof( struct V_79 * ) * V_21 -> V_29 ,
V_80 ) ;
if ( ! V_21 -> V_60 )
return - V_73 ;
for ( V_26 = 0 ; V_26 < V_21 -> V_29 ; V_26 ++ ) {
V_21 -> V_60 [ V_26 ] = F_30 ( V_80 ) ;
if ( ! V_21 -> V_60 [ V_26 ] )
goto V_81;
}
V_21 -> V_31 = F_29 ( sizeof( T_2 ) * V_21 -> V_29 ,
V_80 ) ;
if ( ! V_21 -> V_31 )
goto V_81;
for ( V_26 = 0 ; V_26 < V_21 -> V_29 ; V_26 ++ ) {
T_2 V_30 ;
V_30 = F_31 ( V_2 -> V_68 , V_21 -> V_60 [ V_26 ] , 0 , 4096 ,
V_69 ) ;
if ( F_32 ( V_2 -> V_68 , V_30 ) ) {
V_72 = - V_82 ;
goto V_83;
}
V_21 -> V_31 [ V_26 ] = V_30 ;
}
V_21 -> V_76 ( V_21 , 0 ,
V_21 -> V_29 * V_56 ) ;
V_21 -> V_17 = V_71 * sizeof( T_1 ) ;
return 0 ;
V_83:
if ( V_21 -> V_31 ) {
for ( V_26 -- ; V_26 >= 0 ; V_26 -- )
F_24 ( V_2 -> V_68 , V_21 -> V_31 [ V_26 ] ,
4096 , V_69 ) ;
}
V_81:
F_25 ( V_21 -> V_31 ) ;
for ( V_26 = 0 ; V_26 < V_21 -> V_29 ; V_26 ++ ) {
if ( V_21 -> V_60 [ V_26 ] )
F_26 ( V_21 -> V_60 [ V_26 ] ) ;
}
F_25 ( V_21 -> V_60 ) ;
return V_72 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_70 * V_15 = V_2 -> V_16 ;
struct V_20 * V_21 ;
int V_72 ;
V_21 = F_29 ( sizeof( * V_21 ) , V_80 ) ;
if ( ! V_21 )
return - V_73 ;
V_21 -> V_2 = V_2 ;
V_21 -> V_59 = V_15 -> V_27 . V_84 ;
if ( F_9 ( V_2 ) -> V_33 < 8 )
V_72 = F_27 ( V_21 ) ;
else
F_4 () ;
if ( V_72 )
F_25 ( V_21 ) ;
else
V_15 -> V_22 . V_23 = V_21 ;
return V_72 ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_70 * V_15 = V_2 -> V_16 ;
struct V_20 * V_21 = V_15 -> V_22 . V_23 ;
if ( ! V_21 )
return;
V_21 -> V_78 ( V_21 ) ;
V_15 -> V_22 . V_23 = NULL ;
}
void F_35 ( struct V_20 * V_21 ,
struct V_85 * V_86 ,
enum V_4 V_63 )
{
V_21 -> V_77 ( V_21 , V_86 -> V_62 ,
V_86 -> V_87 -> V_88 >> V_89 ,
V_63 ) ;
}
void F_36 ( struct V_20 * V_21 ,
struct V_85 * V_86 )
{
V_21 -> V_76 ( V_21 ,
V_86 -> V_87 -> V_88 >> V_89 ,
V_86 -> V_90 . V_91 >> V_89 ) ;
}
static inline bool F_37 ( struct V_1 * V_2 )
{
#ifdef F_38
if ( F_39 ( V_2 ) && F_40 ( V_2 ) && V_92 )
return true ;
#endif
return false ;
}
static bool F_41 ( struct V_70 * V_15 )
{
bool V_72 = V_15 -> V_22 . V_93 ;
if ( F_42 ( V_15 -> V_27 . V_94 ) ) {
V_15 -> V_22 . V_93 = false ;
if ( F_43 ( V_15 -> V_2 ) ) {
F_44 ( L_1 ) ;
F_45 ( 10 ) ;
}
}
return V_72 ;
}
static void F_46 ( struct V_70 * V_15 , bool V_93 )
{
if ( F_42 ( V_15 -> V_27 . V_94 ) )
V_15 -> V_22 . V_93 = V_93 ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_70 * V_15 = V_2 -> V_16 ;
struct V_85 * V_86 ;
V_15 -> V_27 . V_95 ( V_2 , V_15 -> V_27 . V_88 / V_96 ,
V_15 -> V_27 . V_97 / V_96 ) ;
F_48 (obj, &dev_priv->mm.bound_list, gtt_list) {
F_49 ( V_86 ) ;
F_50 ( V_86 , V_86 -> V_63 ) ;
}
F_51 ( V_2 ) ;
}
int F_52 ( struct V_85 * V_86 )
{
if ( V_86 -> V_98 )
return 0 ;
if ( ! F_53 ( & V_86 -> V_90 . V_2 -> V_68 -> V_2 ,
V_86 -> V_62 -> V_99 , V_86 -> V_62 -> V_100 ,
V_69 ) )
return - V_101 ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_61 * V_102 ,
unsigned int V_51 ,
enum V_4 V_5 )
{
struct V_70 * V_15 = V_2 -> V_16 ;
T_1 T_5 * V_103 =
( T_1 T_5 * ) V_15 -> V_27 . V_28 + V_51 ;
int V_26 = 0 ;
struct V_65 V_66 ;
T_2 V_3 ;
F_21 (st->sgl, &sg_iter, st->nents, 0 ) {
V_3 = F_22 ( & V_66 ) ;
F_55 ( F_1 ( V_2 , V_3 , V_5 ) , & V_103 [ V_26 ] ) ;
V_26 ++ ;
}
if ( V_26 != 0 )
F_56 ( F_8 ( & V_103 [ V_26 - 1 ] )
!= F_1 ( V_2 , V_3 , V_5 ) ) ;
F_11 ( V_104 , V_105 ) ;
F_57 ( V_104 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
unsigned int V_51 ,
unsigned int V_52 )
{
struct V_70 * V_15 = V_2 -> V_16 ;
T_1 V_54 , T_5 * V_106 =
( T_1 T_5 * ) V_15 -> V_27 . V_28 + V_51 ;
const int V_107 = F_28 ( V_15 -> V_27 ) - V_51 ;
int V_26 ;
if ( F_59 ( V_52 > V_107 ,
L_2 ,
V_51 , V_52 , V_107 ) )
V_52 = V_107 ;
V_54 = F_1 ( V_2 , V_15 -> V_27 . V_84 ,
V_11 ) ;
for ( V_26 = 0 ; V_26 < V_52 ; V_26 ++ )
F_55 ( V_54 , & V_106 [ V_26 ] ) ;
F_8 ( V_106 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_61 * V_102 ,
unsigned int V_108 ,
enum V_4 V_63 )
{
unsigned int V_109 = ( V_63 == V_12 ) ?
V_110 : V_111 ;
F_61 ( V_102 , V_108 , V_109 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
unsigned int V_51 ,
unsigned int V_52 )
{
F_63 ( V_51 , V_52 ) ;
}
void F_50 ( struct V_85 * V_86 ,
enum V_4 V_63 )
{
struct V_1 * V_2 = V_86 -> V_90 . V_2 ;
struct V_70 * V_15 = V_2 -> V_16 ;
V_15 -> V_27 . V_112 ( V_2 , V_86 -> V_62 ,
V_86 -> V_87 -> V_88 >> V_89 ,
V_63 ) ;
V_86 -> V_113 = 1 ;
}
void F_64 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = V_86 -> V_90 . V_2 ;
struct V_70 * V_15 = V_2 -> V_16 ;
V_15 -> V_27 . V_95 ( V_86 -> V_90 . V_2 ,
V_86 -> V_87 -> V_88 >> V_89 ,
V_86 -> V_90 . V_91 >> V_89 ) ;
V_86 -> V_113 = 0 ;
}
void F_65 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = V_86 -> V_90 . V_2 ;
struct V_70 * V_15 = V_2 -> V_16 ;
bool V_93 ;
V_93 = F_41 ( V_15 ) ;
if ( ! V_86 -> V_98 )
F_66 ( & V_2 -> V_68 -> V_2 ,
V_86 -> V_62 -> V_99 , V_86 -> V_62 -> V_100 ,
V_69 ) ;
F_46 ( V_15 , V_93 ) ;
}
static void F_67 ( struct V_114 * V_115 ,
unsigned long V_116 ,
unsigned long * V_88 ,
unsigned long * V_117 )
{
if ( V_115 -> V_116 != V_116 )
* V_88 += 4096 ;
if ( ! F_68 ( & V_115 -> V_118 ) ) {
V_115 = F_69 ( V_115 -> V_118 . V_119 ,
struct V_114 ,
V_118 ) ;
if ( V_115 -> V_120 && V_115 -> V_116 != V_116 )
* V_117 -= 4096 ;
}
}
void F_70 ( struct V_1 * V_2 ,
unsigned long V_88 ,
unsigned long V_121 ,
unsigned long V_117 )
{
T_3 * V_15 = V_2 -> V_16 ;
struct V_114 * V_122 ;
struct V_85 * V_86 ;
unsigned long V_123 , V_124 ;
F_71 ( V_121 > V_117 ) ;
F_72 ( & V_15 -> V_22 . V_87 , V_88 , V_117 - V_88 - V_96 ) ;
if ( ! F_73 ( V_2 ) )
V_15 -> V_22 . V_87 . V_125 = F_67 ;
F_48 (obj, &dev_priv->mm.bound_list, gtt_list) {
F_74 ( L_3 ,
V_86 -> V_126 , V_86 -> V_90 . V_91 ) ;
F_71 ( V_86 -> V_87 != V_127 ) ;
V_86 -> V_87 = F_75 ( & V_15 -> V_22 . V_87 ,
V_86 -> V_126 ,
V_86 -> V_90 . V_91 ,
false ) ;
V_86 -> V_113 = 1 ;
}
V_15 -> V_27 . V_88 = V_88 ;
V_15 -> V_27 . V_97 = V_117 - V_88 ;
F_76 (entry, &dev_priv->mm.gtt_space,
hole_start, hole_end) {
F_74 ( L_4 ,
V_123 , V_124 ) ;
V_15 -> V_27 . V_95 ( V_2 , V_123 / V_96 ,
( V_124 - V_123 ) / V_96 ) ;
}
V_15 -> V_27 . V_95 ( V_2 , V_117 / V_96 - 1 , 1 ) ;
}
static bool
F_77 ( struct V_1 * V_2 )
{
if ( V_128 >= 0 )
return V_128 ;
#ifdef F_38
if ( F_9 ( V_2 ) -> V_33 == 6 && V_92 )
return false ;
#endif
return true ;
}
void F_78 ( struct V_1 * V_2 )
{
struct V_70 * V_15 = V_2 -> V_16 ;
unsigned long V_129 , V_130 ;
V_129 = V_15 -> V_27 . V_97 ;
V_130 = V_15 -> V_27 . V_121 ;
if ( F_77 ( V_2 ) && F_79 ( V_2 ) ) {
int V_72 ;
if ( F_9 ( V_2 ) -> V_33 <= 7 ) {
V_129 -= V_74 * V_96 ;
}
F_70 ( V_2 , 0 , V_130 , V_129 ) ;
V_72 = F_33 ( V_2 ) ;
if ( ! V_72 )
return;
F_44 ( L_5 , V_72 ) ;
F_80 ( & V_15 -> V_22 . V_87 ) ;
V_129 += V_74 * V_96 ;
}
F_70 ( V_2 , 0 , V_130 , V_129 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_70 * V_15 = V_2 -> V_16 ;
struct V_79 * V_79 ;
T_2 V_131 ;
V_79 = F_30 ( V_80 | V_132 | V_133 ) ;
if ( V_79 == NULL )
return - V_73 ;
F_82 ( V_79 ) ;
F_83 ( V_79 , 1 ) ;
#ifdef F_38
V_131 = F_31 ( V_2 -> V_68 , V_79 , 0 , V_96 ,
V_69 ) ;
if ( F_32 ( V_2 -> V_68 , V_131 ) )
return - V_134 ;
#else
V_131 = F_84 ( V_79 ) ;
#endif
V_15 -> V_27 . V_135 = V_79 ;
V_15 -> V_27 . V_84 = V_131 ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_70 * V_15 = V_2 -> V_16 ;
F_86 ( V_15 -> V_27 . V_135 , 1 ) ;
F_24 ( V_2 -> V_68 , V_15 -> V_27 . V_84 ,
V_96 , V_69 ) ;
F_87 ( V_15 -> V_27 . V_135 ) ;
F_26 ( V_15 -> V_27 . V_135 ) ;
}
static inline unsigned int F_88 ( T_6 V_136 )
{
V_136 >>= V_137 ;
V_136 &= V_138 ;
return V_136 << 20 ;
}
static inline T_7 F_89 ( T_6 V_136 )
{
V_136 >>= V_139 ;
V_136 &= V_140 ;
return V_136 << 25 ;
}
static int F_90 ( struct V_1 * V_2 ,
T_7 * V_141 ,
T_7 * V_142 ,
T_8 * V_143 ,
unsigned long * V_121 )
{
struct V_70 * V_15 = V_2 -> V_16 ;
T_8 V_144 ;
unsigned int V_129 ;
T_6 V_136 ;
int V_72 ;
* V_143 = F_91 ( V_2 -> V_68 , 2 ) ;
* V_121 = F_92 ( V_2 -> V_68 , 2 ) ;
if ( ( * V_121 < ( 64 << 20 ) || ( * V_121 > ( 512 << 20 ) ) ) ) {
F_44 ( L_6 ,
V_15 -> V_27 . V_121 ) ;
return - V_145 ;
}
if ( ! F_93 ( V_2 -> V_68 , F_94 ( 40 ) ) )
F_95 ( V_2 -> V_68 , F_94 ( 40 ) ) ;
F_96 ( V_2 -> V_68 , V_146 , & V_136 ) ;
V_129 = F_88 ( V_136 ) ;
* V_142 = F_89 ( V_136 ) ;
* V_141 = ( V_129 / sizeof( T_1 ) ) << V_89 ;
V_144 = F_91 ( V_2 -> V_68 , 0 ) +
( F_92 ( V_2 -> V_68 , 0 ) / 2 ) ;
V_15 -> V_27 . V_28 = F_97 ( V_144 , V_129 ) ;
if ( ! V_15 -> V_27 . V_28 ) {
F_44 ( L_7 ) ;
return - V_73 ;
}
V_72 = F_81 ( V_2 ) ;
if ( V_72 )
F_44 ( L_8 ) ;
V_15 -> V_27 . V_95 = F_58 ;
V_15 -> V_27 . V_112 = F_54 ;
return V_72 ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_70 * V_15 = V_2 -> V_16 ;
F_99 ( V_15 -> V_27 . V_28 ) ;
F_85 ( V_15 -> V_2 ) ;
}
static int F_100 ( struct V_1 * V_2 ,
T_7 * V_141 ,
T_7 * V_142 ,
T_8 * V_143 ,
unsigned long * V_121 )
{
struct V_70 * V_15 = V_2 -> V_16 ;
int V_72 ;
V_72 = F_101 ( V_15 -> V_147 , V_15 -> V_2 -> V_68 , NULL ) ;
if ( ! V_72 ) {
F_44 ( L_9 ) ;
return - V_82 ;
}
F_102 ( V_141 , V_142 , V_143 , V_121 ) ;
V_15 -> V_27 . V_94 = F_37 ( V_15 -> V_2 ) ;
V_15 -> V_27 . V_95 = F_62 ;
V_15 -> V_27 . V_112 = F_60 ;
return 0 ;
}
static void F_103 ( struct V_1 * V_2 )
{
F_104 () ;
}
int F_105 ( struct V_1 * V_2 )
{
struct V_70 * V_15 = V_2 -> V_16 ;
struct V_148 * V_27 = & V_15 -> V_27 ;
int V_72 ;
if ( F_9 ( V_2 ) -> V_33 <= 5 ) {
V_15 -> V_27 . V_149 = F_100 ;
V_15 -> V_27 . V_150 = F_103 ;
} else {
V_15 -> V_27 . V_149 = F_90 ;
V_15 -> V_27 . V_150 = F_98 ;
}
V_72 = V_15 -> V_27 . V_149 ( V_2 , & V_15 -> V_27 . V_97 ,
& V_15 -> V_27 . V_151 ,
& V_27 -> V_143 ,
& V_27 -> V_121 ) ;
if ( V_72 )
return V_72 ;
F_106 ( L_10 ,
V_15 -> V_27 . V_97 >> 20 ) ;
F_107 ( L_11 ,
V_15 -> V_27 . V_121 >> 20 ) ;
F_107 ( L_12 ,
V_15 -> V_27 . V_151 >> 20 ) ;
return 0 ;
}
