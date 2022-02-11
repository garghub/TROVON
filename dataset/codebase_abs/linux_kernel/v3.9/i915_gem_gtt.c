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
static void F_5 ( struct V_15 * V_16 ,
unsigned V_17 ,
unsigned V_18 )
{
T_1 * V_19 ;
T_1 V_20 ;
unsigned V_21 = V_17 / V_22 ;
unsigned V_23 = V_17 % V_22 ;
unsigned V_24 , V_25 ;
V_20 = F_1 ( V_16 -> V_2 ,
V_16 -> V_26 ,
V_11 ) ;
while ( V_18 ) {
V_24 = V_23 + V_18 ;
if ( V_24 > V_22 )
V_24 = V_22 ;
V_19 = F_6 ( V_16 -> V_27 [ V_21 ] ) ;
for ( V_25 = V_23 ; V_25 < V_24 ; V_25 ++ )
V_19 [ V_25 ] = V_20 ;
F_7 ( V_19 ) ;
V_18 -= V_24 - V_23 ;
V_23 = 0 ;
V_21 ++ ;
}
}
static void F_8 ( struct V_15 * V_16 ,
struct V_28 * V_29 ,
unsigned V_17 ,
enum V_4 V_30 )
{
T_1 * V_19 ;
unsigned V_21 = V_17 / V_22 ;
unsigned V_23 = V_17 % V_22 ;
unsigned V_25 , V_31 , V_32 , V_33 ;
T_2 V_34 ;
struct V_35 * V_36 ;
V_36 = V_29 -> V_37 ;
V_25 = 0 ;
V_33 = F_9 ( V_36 ) >> V_38 ;
V_32 = 0 ;
while ( V_25 < V_29 -> V_39 ) {
V_19 = F_6 ( V_16 -> V_27 [ V_21 ] ) ;
for ( V_31 = V_23 ; V_31 < V_22 ; V_31 ++ ) {
V_34 = F_10 ( V_36 ) + ( V_32 << V_38 ) ;
V_19 [ V_31 ] = F_1 ( V_16 -> V_2 , V_34 ,
V_30 ) ;
if ( ++ V_32 == V_33 ) {
if ( ++ V_25 == V_29 -> V_39 )
break;
V_36 = F_11 ( V_36 ) ;
V_33 = F_9 ( V_36 ) >> V_38 ;
V_32 = 0 ;
}
}
F_7 ( V_19 ) ;
V_23 = 0 ;
V_21 ++ ;
}
}
static void F_12 ( struct V_15 * V_16 )
{
int V_25 ;
if ( V_16 -> V_40 ) {
for ( V_25 = 0 ; V_25 < V_16 -> V_41 ; V_25 ++ )
F_13 ( V_16 -> V_2 -> V_42 ,
V_16 -> V_40 [ V_25 ] ,
4096 , V_43 ) ;
}
F_14 ( V_16 -> V_40 ) ;
for ( V_25 = 0 ; V_25 < V_16 -> V_41 ; V_25 ++ )
F_15 ( V_16 -> V_27 [ V_25 ] ) ;
F_14 ( V_16 -> V_27 ) ;
F_14 ( V_16 ) ;
}
static int F_16 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_44 * V_45 = V_2 -> V_46 ;
unsigned V_47 ;
int V_25 ;
int V_48 = - V_49 ;
V_47 =
F_17 ( V_45 -> V_50 ) - V_51 ;
V_16 -> V_41 = V_51 ;
V_16 -> V_52 = F_5 ;
V_16 -> V_53 = F_8 ;
V_16 -> V_54 = F_12 ;
V_16 -> V_27 = F_18 ( sizeof( struct V_55 * ) * V_16 -> V_41 ,
V_56 ) ;
if ( ! V_16 -> V_27 )
return - V_49 ;
for ( V_25 = 0 ; V_25 < V_16 -> V_41 ; V_25 ++ ) {
V_16 -> V_27 [ V_25 ] = F_19 ( V_56 ) ;
if ( ! V_16 -> V_27 [ V_25 ] )
goto V_57;
}
V_16 -> V_40 = F_18 ( sizeof( T_2 ) * V_16 -> V_41 ,
V_56 ) ;
if ( ! V_16 -> V_40 )
goto V_57;
for ( V_25 = 0 ; V_25 < V_16 -> V_41 ; V_25 ++ ) {
T_2 V_58 ;
V_58 = F_20 ( V_2 -> V_42 , V_16 -> V_27 [ V_25 ] , 0 , 4096 ,
V_43 ) ;
if ( F_21 ( V_2 -> V_42 , V_58 ) ) {
V_48 = - V_59 ;
goto V_60;
}
V_16 -> V_40 [ V_25 ] = V_58 ;
}
V_16 -> V_26 = V_45 -> V_50 . V_61 ;
V_16 -> V_52 ( V_16 , 0 ,
V_16 -> V_41 * V_22 ) ;
V_16 -> V_62 = ( V_47 ) * sizeof( T_1 ) ;
return 0 ;
V_60:
if ( V_16 -> V_40 ) {
for ( V_25 -- ; V_25 >= 0 ; V_25 -- )
F_13 ( V_2 -> V_42 , V_16 -> V_40 [ V_25 ] ,
4096 , V_43 ) ;
}
V_57:
F_14 ( V_16 -> V_40 ) ;
for ( V_25 = 0 ; V_25 < V_16 -> V_41 ; V_25 ++ ) {
if ( V_16 -> V_27 [ V_25 ] )
F_15 ( V_16 -> V_27 [ V_25 ] ) ;
}
F_14 ( V_16 -> V_27 ) ;
return V_48 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_15 * V_16 ;
int V_48 ;
V_16 = F_18 ( sizeof( * V_16 ) , V_56 ) ;
if ( ! V_16 )
return - V_49 ;
V_16 -> V_2 = V_2 ;
V_48 = F_16 ( V_16 ) ;
if ( V_48 )
F_14 ( V_16 ) ;
else
V_45 -> V_63 . V_64 = V_16 ;
return V_48 ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_15 * V_16 = V_45 -> V_63 . V_64 ;
if ( ! V_16 )
return;
V_16 -> V_54 ( V_16 ) ;
}
void F_24 ( struct V_15 * V_16 ,
struct V_65 * V_66 ,
enum V_4 V_30 )
{
V_16 -> V_53 ( V_16 , V_66 -> V_29 ,
V_66 -> V_67 -> V_68 >> V_38 ,
V_30 ) ;
}
void F_25 ( struct V_15 * V_16 ,
struct V_65 * V_66 )
{
V_16 -> V_52 ( V_16 ,
V_66 -> V_67 -> V_68 >> V_38 ,
V_66 -> V_69 . V_70 >> V_38 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
T_3 * V_45 = V_2 -> V_46 ;
T_4 V_62 ;
struct V_71 * V_72 ;
struct V_15 * V_16 = V_45 -> V_63 . V_64 ;
T_1 T_5 * V_73 ;
T_4 V_74 ;
int V_25 ;
if ( ! V_45 -> V_63 . V_64 )
return;
V_73 = ( T_1 T_5 * ) V_45 -> V_50 . V_75 + V_16 -> V_62 / sizeof( T_1 ) ;
for ( V_25 = 0 ; V_25 < V_16 -> V_41 ; V_25 ++ ) {
T_2 V_58 ;
V_58 = V_16 -> V_40 [ V_25 ] ;
V_74 = F_27 ( V_58 ) ;
V_74 |= V_76 ;
F_28 ( V_74 , V_73 + V_25 ) ;
}
F_29 ( V_73 ) ;
V_62 = V_16 -> V_62 ;
V_62 /= 64 ;
V_62 <<= 16 ;
if ( F_30 ( V_2 ) -> V_77 == 6 ) {
T_4 V_78 , V_79 , V_80 ;
V_80 = F_31 ( V_81 ) ;
F_32 ( V_81 , V_80 | V_82 ) ;
V_79 = F_31 ( V_83 ) ;
F_32 ( V_83 , V_79 | V_84 ) ;
V_78 = F_31 ( V_85 ) ;
F_32 ( V_85 , V_78 | V_86 |
V_87 ) ;
F_32 ( V_88 , F_33 ( V_89 ) ) ;
} else if ( F_30 ( V_2 ) -> V_77 >= 7 ) {
F_32 ( V_85 , V_87 ) ;
}
F_34 (ring, dev_priv, i) {
if ( F_30 ( V_2 ) -> V_77 >= 7 )
F_32 ( F_35 ( V_72 ) ,
F_33 ( V_89 ) ) ;
F_32 ( F_36 ( V_72 ) , V_90 ) ;
F_32 ( F_37 ( V_72 ) , V_62 ) ;
}
}
static inline bool F_38 ( struct V_1 * V_2 )
{
#ifdef F_39
if ( F_40 ( V_2 ) && F_41 ( V_2 ) && V_91 )
return true ;
#endif
return false ;
}
static bool F_42 ( struct V_44 * V_45 )
{
bool V_48 = V_45 -> V_63 . V_92 ;
if ( F_43 ( V_45 -> V_50 . V_93 ) ) {
V_45 -> V_63 . V_92 = false ;
if ( F_44 ( V_45 -> V_2 ) ) {
F_45 ( L_1 ) ;
F_46 ( 10 ) ;
}
}
return V_48 ;
}
static void F_47 ( struct V_44 * V_45 , bool V_92 )
{
if ( F_43 ( V_45 -> V_50 . V_93 ) )
V_45 -> V_63 . V_92 = V_92 ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_65 * V_66 ;
V_45 -> V_50 . V_94 ( V_2 , V_45 -> V_50 . V_68 / V_95 ,
V_45 -> V_50 . V_96 / V_95 ) ;
F_49 (obj, &dev_priv->mm.bound_list, gtt_list) {
F_50 ( V_66 ) ;
F_51 ( V_66 , V_66 -> V_30 ) ;
}
F_52 ( V_2 ) ;
}
int F_53 ( struct V_65 * V_66 )
{
if ( V_66 -> V_97 )
return 0 ;
if ( ! F_54 ( & V_66 -> V_69 . V_2 -> V_42 -> V_2 ,
V_66 -> V_29 -> V_37 , V_66 -> V_29 -> V_39 ,
V_43 ) )
return - V_98 ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_28 * V_99 ,
unsigned int V_17 ,
enum V_4 V_5 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_35 * V_36 = V_99 -> V_37 ;
T_1 T_5 * V_100 =
( T_1 T_5 * ) V_45 -> V_50 . V_75 + V_17 ;
int V_101 , V_25 = 0 ;
unsigned int V_102 , V_32 = 0 ;
T_2 V_3 ;
F_56 (st->sgl, sg, st->nents, unused) {
V_102 = F_9 ( V_36 ) >> V_38 ;
for ( V_32 = 0 ; V_32 < V_102 ; V_32 ++ ) {
V_3 = F_10 ( V_36 ) + ( V_32 << V_38 ) ;
F_57 ( F_1 ( V_2 , V_3 , V_5 ) ,
& V_100 [ V_25 ] ) ;
V_25 ++ ;
}
}
if ( V_25 != 0 )
F_58 ( F_29 ( & V_100 [ V_25 - 1 ] )
!= F_1 ( V_2 , V_3 , V_5 ) ) ;
F_32 ( V_103 , V_104 ) ;
F_59 ( V_103 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
unsigned int V_17 ,
unsigned int V_18 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
T_1 V_20 ;
T_1 T_5 * V_105 = ( T_1 T_5 * ) V_45 -> V_50 . V_75 + V_17 ;
const int V_106 = F_17 ( V_45 -> V_50 ) - V_17 ;
int V_25 ;
if ( F_61 ( V_18 > V_106 ,
L_2 ,
V_17 , V_18 , V_106 ) )
V_18 = V_106 ;
V_20 = F_1 ( V_2 , V_45 -> V_50 . V_61 ,
V_11 ) ;
for ( V_25 = 0 ; V_25 < V_18 ; V_25 ++ )
F_57 ( V_20 , & V_105 [ V_25 ] ) ;
F_29 ( V_105 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_28 * V_99 ,
unsigned int V_107 ,
enum V_4 V_30 )
{
unsigned int V_108 = ( V_30 == V_12 ) ?
V_109 : V_110 ;
F_63 ( V_99 , V_107 , V_108 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
unsigned int V_17 ,
unsigned int V_18 )
{
F_65 ( V_17 , V_18 ) ;
}
void F_51 ( struct V_65 * V_66 ,
enum V_4 V_30 )
{
struct V_1 * V_2 = V_66 -> V_69 . V_2 ;
struct V_44 * V_45 = V_2 -> V_46 ;
V_45 -> V_50 . V_111 ( V_2 , V_66 -> V_29 ,
V_66 -> V_67 -> V_68 >> V_38 ,
V_30 ) ;
V_66 -> V_112 = 1 ;
}
void F_66 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_69 . V_2 ;
struct V_44 * V_45 = V_2 -> V_46 ;
V_45 -> V_50 . V_94 ( V_66 -> V_69 . V_2 ,
V_66 -> V_67 -> V_68 >> V_38 ,
V_66 -> V_69 . V_70 >> V_38 ) ;
V_66 -> V_112 = 0 ;
}
void F_67 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_69 . V_2 ;
struct V_44 * V_45 = V_2 -> V_46 ;
bool V_92 ;
V_92 = F_42 ( V_45 ) ;
if ( ! V_66 -> V_97 )
F_68 ( & V_2 -> V_42 -> V_2 ,
V_66 -> V_29 -> V_37 , V_66 -> V_29 -> V_39 ,
V_43 ) ;
F_47 ( V_45 , V_92 ) ;
}
static void F_69 ( struct V_113 * V_114 ,
unsigned long V_115 ,
unsigned long * V_68 ,
unsigned long * V_116 )
{
if ( V_114 -> V_115 != V_115 )
* V_68 += 4096 ;
if ( ! F_70 ( & V_114 -> V_117 ) ) {
V_114 = F_71 ( V_114 -> V_117 . V_118 ,
struct V_113 ,
V_117 ) ;
if ( V_114 -> V_119 && V_114 -> V_115 != V_115 )
* V_116 -= 4096 ;
}
}
void F_72 ( struct V_1 * V_2 ,
unsigned long V_68 ,
unsigned long V_120 ,
unsigned long V_116 )
{
T_3 * V_45 = V_2 -> V_46 ;
struct V_113 * V_121 ;
struct V_65 * V_66 ;
unsigned long V_122 , V_123 ;
F_73 ( V_120 > V_116 ) ;
F_74 ( & V_45 -> V_63 . V_67 , V_68 , V_116 - V_68 - V_95 ) ;
if ( ! F_75 ( V_2 ) )
V_45 -> V_63 . V_67 . V_124 = F_69 ;
F_49 (obj, &dev_priv->mm.bound_list, gtt_list) {
F_76 ( L_3 ,
V_66 -> V_125 , V_66 -> V_69 . V_70 ) ;
F_73 ( V_66 -> V_67 != V_126 ) ;
V_66 -> V_67 = F_77 ( & V_45 -> V_63 . V_67 ,
V_66 -> V_125 ,
V_66 -> V_69 . V_70 ,
false ) ;
V_66 -> V_112 = 1 ;
}
V_45 -> V_50 . V_68 = V_68 ;
V_45 -> V_50 . V_96 = V_116 - V_68 ;
F_78 (entry, &dev_priv->mm.gtt_space,
hole_start, hole_end) {
F_76 ( L_4 ,
V_122 , V_123 ) ;
V_45 -> V_50 . V_94 ( V_2 , V_122 / V_95 ,
( V_123 - V_122 ) / V_95 ) ;
}
V_45 -> V_50 . V_94 ( V_2 , V_116 / V_95 - 1 , 1 ) ;
}
static bool
F_79 ( struct V_1 * V_2 )
{
if ( V_127 >= 0 )
return V_127 ;
#ifdef F_39
if ( F_30 ( V_2 ) -> V_77 == 6 && V_91 )
return false ;
#endif
return true ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
unsigned long V_128 , V_129 ;
V_128 = V_45 -> V_50 . V_96 ;
V_129 = V_45 -> V_50 . V_120 ;
if ( F_79 ( V_2 ) && F_81 ( V_2 ) ) {
int V_48 ;
V_128 -= V_51 * V_95 ;
F_72 ( V_2 , 0 , V_129 , V_128 ) ;
V_48 = F_22 ( V_2 ) ;
if ( ! V_48 )
return;
F_45 ( L_5 , V_48 ) ;
F_82 ( & V_45 -> V_63 . V_67 ) ;
V_128 += V_51 * V_95 ;
}
F_72 ( V_2 , 0 , V_129 , V_128 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_55 * V_55 ;
T_2 V_130 ;
V_55 = F_19 ( V_56 | V_131 | V_132 ) ;
if ( V_55 == NULL )
return - V_49 ;
F_84 ( V_55 ) ;
F_85 ( V_55 , 1 ) ;
#ifdef F_39
V_130 = F_20 ( V_2 -> V_42 , V_55 , 0 , V_95 ,
V_43 ) ;
if ( F_21 ( V_2 -> V_42 , V_130 ) )
return - V_133 ;
#else
V_130 = F_86 ( V_55 ) ;
#endif
V_45 -> V_50 . V_134 = V_55 ;
V_45 -> V_50 . V_61 = V_130 ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
F_88 ( V_45 -> V_50 . V_134 , 1 ) ;
F_13 ( V_2 -> V_42 , V_45 -> V_50 . V_61 ,
V_95 , V_43 ) ;
F_89 ( V_45 -> V_50 . V_134 ) ;
F_15 ( V_45 -> V_50 . V_134 ) ;
}
static inline unsigned int F_90 ( T_6 V_135 )
{
V_135 >>= V_136 ;
V_135 &= V_137 ;
return V_135 << 20 ;
}
static inline T_7 F_91 ( T_6 V_135 )
{
V_135 >>= V_138 ;
V_135 &= V_139 ;
return V_135 << 25 ;
}
static inline T_7 F_92 ( T_6 V_135 )
{
static const int V_140 [] = {
0 , 0 , 0 , 0 , 0 , 32 , 48 , 64 , 128 , 256 , 96 , 160 , 224 , 352 } ;
V_135 >>= V_141 ;
V_135 &= V_142 ;
return V_140 [ V_135 ] << 20 ;
}
static int F_93 ( struct V_1 * V_2 ,
T_7 * V_143 ,
T_7 * V_144 ,
T_8 * V_145 ,
unsigned long * V_120 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
T_8 V_146 ;
unsigned int V_128 ;
T_6 V_135 ;
int V_48 ;
* V_145 = F_94 ( V_2 -> V_42 , 2 ) ;
* V_120 = F_95 ( V_2 -> V_42 , 2 ) ;
if ( ( * V_120 < ( 64 << 20 ) || ( * V_120 > ( 512 << 20 ) ) ) ) {
F_45 ( L_6 ,
V_45 -> V_50 . V_120 ) ;
return - V_147 ;
}
if ( ! F_96 ( V_2 -> V_42 , F_97 ( 40 ) ) )
F_98 ( V_2 -> V_42 , F_97 ( 40 ) ) ;
F_99 ( V_2 -> V_42 , V_148 , & V_135 ) ;
V_128 = F_90 ( V_135 ) ;
if ( F_100 ( V_2 ) )
* V_144 = F_92 ( V_135 ) ;
else
* V_144 = F_91 ( V_135 ) ;
* V_143 = ( V_128 / sizeof( T_1 ) ) << V_38 ;
V_146 = F_94 ( V_2 -> V_42 , 0 ) + ( 2 << 20 ) ;
V_45 -> V_50 . V_75 = F_101 ( V_146 , V_128 ) ;
if ( ! V_45 -> V_50 . V_75 ) {
F_45 ( L_7 ) ;
return - V_49 ;
}
V_48 = F_83 ( V_2 ) ;
if ( V_48 )
F_45 ( L_8 ) ;
V_45 -> V_50 . V_94 = F_60 ;
V_45 -> V_50 . V_111 = F_55 ;
return V_48 ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
F_103 ( V_45 -> V_50 . V_75 ) ;
F_87 ( V_45 -> V_2 ) ;
}
static int F_104 ( struct V_1 * V_2 ,
T_7 * V_143 ,
T_7 * V_144 ,
T_8 * V_145 ,
unsigned long * V_120 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
int V_48 ;
V_48 = F_105 ( V_45 -> V_149 , V_45 -> V_2 -> V_42 , NULL ) ;
if ( ! V_48 ) {
F_45 ( L_9 ) ;
return - V_59 ;
}
F_106 ( V_143 , V_144 , V_145 , V_120 ) ;
V_45 -> V_50 . V_93 = F_38 ( V_45 -> V_2 ) ;
V_45 -> V_50 . V_94 = F_64 ;
V_45 -> V_50 . V_111 = F_62 ;
return 0 ;
}
static void F_107 ( struct V_1 * V_2 )
{
F_108 () ;
}
int F_109 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_150 * V_50 = & V_45 -> V_50 ;
unsigned long V_128 ;
int V_48 ;
if ( F_30 ( V_2 ) -> V_77 <= 5 ) {
V_45 -> V_50 . V_151 = F_104 ;
V_45 -> V_50 . V_152 = F_107 ;
} else {
V_45 -> V_50 . V_151 = F_93 ;
V_45 -> V_50 . V_152 = F_102 ;
}
V_48 = V_45 -> V_50 . V_151 ( V_2 , & V_45 -> V_50 . V_96 ,
& V_45 -> V_50 . V_153 ,
& V_50 -> V_145 ,
& V_50 -> V_120 ) ;
if ( V_48 )
return V_48 ;
V_128 = ( V_45 -> V_50 . V_96 >> V_38 ) * sizeof( T_1 ) ;
F_110 ( L_10 ,
V_45 -> V_50 . V_96 >> 20 ) ;
F_111 ( L_11 ,
V_45 -> V_50 . V_120 >> 20 ) ;
F_111 ( L_12 ,
V_45 -> V_50 . V_153 >> 20 ) ;
return 0 ;
}
