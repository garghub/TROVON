void F_1 ( const struct V_1 * V_2 )
{
F_2 ( L_1
L_2 ,
V_2 -> V_3 . V_4 , V_2 -> V_5 , V_2 -> V_6 , V_2 -> clock ,
V_2 -> V_7 , V_2 -> V_8 ,
V_2 -> V_9 , V_2 -> V_10 ,
V_2 -> V_11 , V_2 -> V_12 ,
V_2 -> V_13 , V_2 -> V_14 , V_2 -> type , V_2 -> V_15 ) ;
}
struct V_1 * F_3 ( struct V_16 * V_17 , int V_7 ,
int V_11 , int V_6 ,
bool V_18 , bool V_19 , bool V_20 )
{
#define F_4 18
#define F_5 8
#define F_6 3
#define F_7 6
#define F_8 250
struct V_1 * V_21 ;
unsigned int V_22 , V_23 ;
int V_24 , V_25 , V_26 , V_27 , V_28 ;
int V_29 ;
V_21 = F_9 ( V_17 ) ;
if ( ! V_21 )
return NULL ;
if ( ! V_6 )
V_6 = 60 ;
if ( V_19 )
V_22 = V_6 * 2 ;
else
V_22 = V_6 ;
V_24 = V_7 - ( V_7 % F_5 ) ;
V_25 = 0 ;
if ( V_20 ) {
V_25 = V_24 * F_4 / 1000 ;
V_25 -= V_25 % F_5 ;
}
V_21 -> V_7 = V_24 + 2 * V_25 ;
if ( V_19 )
V_26 = V_11 / 2 ;
else
V_26 = V_11 ;
V_27 = 0 ;
if ( V_20 )
V_27 = V_26 * F_4 / 1000 ;
V_21 -> V_11 = V_11 + 2 * V_27 ;
if ( V_19 )
V_29 = 1 ;
else
V_29 = 0 ;
if ( ! ( V_11 % 3 ) && ( ( V_11 * 4 / 3 ) == V_7 ) )
V_28 = 4 ;
else if ( ! ( V_11 % 9 ) && ( ( V_11 * 16 / 9 ) == V_7 ) )
V_28 = 5 ;
else if ( ! ( V_11 % 10 ) && ( ( V_11 * 16 / 10 ) == V_7 ) )
V_28 = 6 ;
else if ( ! ( V_11 % 4 ) && ( ( V_11 * 5 / 4 ) == V_7 ) )
V_28 = 7 ;
else if ( ! ( V_11 % 9 ) && ( ( V_11 * 15 / 9 ) == V_7 ) )
V_28 = 7 ;
else
V_28 = 10 ;
if ( ! V_18 ) {
int V_30 , V_31 ;
#define F_10 550
#define F_11 8
unsigned int V_32 ;
int V_33 , V_34 , V_35 ;
V_30 = V_36 * 1000000 -
F_10 * V_36 * V_22 ;
V_31 = ( V_26 + 2 * V_27 + F_6 ) * 2 +
V_29 ;
V_23 = V_30 * 2 / ( V_31 * V_22 ) ;
V_30 = F_10 * V_36 / V_23 + 1 ;
if ( V_30 < ( V_28 + F_6 ) )
V_33 = V_28 + F_6 ;
else
V_33 = V_30 ;
V_34 = V_33 - V_28 ;
V_21 -> V_14 = V_26 + 2 * V_27 +
V_33 + F_6 ;
#define F_12 600
#define F_13 40
#define F_14 128
#define F_15 20
#define F_16 (CVT_M_FACTOR * CVT_K_FACTOR / 256)
#define F_17 ((CVT_C_FACTOR - CVT_J_FACTOR) * CVT_K_FACTOR / 256 + \
CVT_J_FACTOR)
V_32 = F_17 * V_36 - F_16 *
V_23 / 1000 ;
if ( V_32 < 20 * V_36 )
V_32 = 20 * V_36 ;
V_35 = V_21 -> V_7 * V_32 /
( 100 * V_36 - V_32 ) ;
V_35 -= V_35 % ( 2 * F_5 ) ;
V_21 -> V_10 = V_21 -> V_7 + V_35 ;
V_21 -> V_9 = V_21 -> V_7 + V_35 / 2 ;
V_21 -> V_8 = V_21 -> V_9 -
( V_21 -> V_10 * F_11 ) / 100 ;
V_21 -> V_8 += F_5 -
V_21 -> V_8 % F_5 ;
V_21 -> V_12 = V_21 -> V_11 + F_6 ;
V_21 -> V_13 = V_21 -> V_12 + V_28 ;
} else {
#define F_18 460
#define F_19 32
#define F_20 160
#define F_21 3
int V_37 ;
int V_30 , V_31 ;
V_30 = V_36 * 1000000 -
F_18 * V_36 * V_22 ;
V_31 = V_26 + 2 * V_27 ;
V_23 = V_30 / ( V_31 * V_22 ) ;
V_37 = F_18 * V_36 / V_23 + 1 ;
if ( V_37 < ( F_21 + V_28 + F_7 ) )
V_37 = F_21 + V_28 + F_7 ;
V_21 -> V_14 = V_26 + 2 * V_27 + V_37 ;
V_21 -> V_10 = V_21 -> V_7 + F_20 ;
V_21 -> V_9 = V_21 -> V_7 + F_20 / 2 ;
V_21 -> V_8 = V_21 -> V_9 - F_19 ;
V_21 -> V_12 = V_21 -> V_11 + F_21 ;
V_21 -> V_13 = V_21 -> V_12 + V_28 ;
}
V_21 -> clock = V_21 -> V_10 * V_36 * 1000 / V_23 ;
V_21 -> clock -= V_21 -> clock % F_8 ;
if ( V_19 ) {
V_21 -> V_14 *= 2 ;
V_21 -> V_15 |= V_38 ;
}
F_22 ( V_21 ) ;
if ( V_18 )
V_21 -> V_15 |= ( V_39 |
V_40 ) ;
else
V_21 -> V_15 |= ( V_41 |
V_42 ) ;
return V_21 ;
}
struct V_1 *
F_23 ( struct V_16 * V_17 , int V_7 , int V_11 ,
int V_6 , bool V_19 , int V_20 ,
int V_43 , int V_44 , int V_45 , int V_46 )
{
#define F_24 18
#define F_25 8
#define F_26 1
#define F_27 3
#define F_28 8
#define F_29 550
#define F_30 ((((GTF_2C - GTF_2J) * GTF_K / 256) + GTF_2J) / 2)
#define F_31 (GTF_K * GTF_M / 256)
struct V_1 * V_21 ;
unsigned int V_24 , V_26 , V_47 ;
int V_48 , V_49 ;
int V_29 ;
unsigned int V_50 ;
int V_51 , V_34 ;
unsigned int V_52 , V_53 , V_23 ;
unsigned int V_54 , V_55 ;
int V_56 , V_57 ;
unsigned int V_58 , V_59 ;
unsigned int V_35 , V_60 , V_61 ;
int V_62 , V_63 , V_64 ;
unsigned int V_30 , V_31 ;
V_21 = F_9 ( V_17 ) ;
if ( ! V_21 )
return NULL ;
V_24 = ( V_7 + F_25 / 2 ) / F_25 ;
V_24 = V_24 * F_25 ;
if ( V_19 )
V_26 = V_11 / 2 ;
else
V_26 = V_11 ;
if ( V_19 )
V_47 = V_6 * 2 ;
else
V_47 = V_6 ;
V_48 = 0 ;
if ( V_20 )
V_48 = ( V_26 * F_24 + 500 ) /
1000 ;
V_49 = V_48 ;
if ( V_19 )
V_29 = 1 ;
else
V_29 = 0 ;
{
V_30 = ( 1000000 - F_29 * V_47 ) / 500 ;
V_31 = ( V_26 + 2 * V_48 + F_26 ) *
2 + V_29 ;
V_50 = ( V_31 * 1000 * V_47 ) / V_30 ;
}
V_51 = F_29 * V_50 / 1000 ;
V_51 = ( V_51 + 500 ) / 1000 ;
V_34 = V_51 - F_27 ;
V_52 = V_26 + V_48 + V_49 +
V_51 + F_26 ;
V_53 = V_50 / V_52 ;
V_23 = 1000000 / ( V_47 * V_52 ) ;
V_54 = V_50 / V_52 ;
if ( V_19 )
V_55 = V_54 / 2 ;
else
V_55 = V_54 ;
if ( V_20 )
V_56 = ( V_24 * F_24 + 500 ) /
1000 ;
else
V_56 = 0 ;
V_57 = V_56 ;
V_58 = V_24 + V_56 + V_57 ;
V_59 = F_30 * 1000 -
( F_31 * 1000000 / V_50 ) ;
V_35 = V_58 * V_59 /
( 100000 - V_59 ) ;
V_35 = ( V_35 + F_25 ) / ( 2 * F_25 ) ;
V_35 = V_35 * 2 * F_25 ;
V_60 = V_58 + V_35 ;
V_61 = V_60 * V_50 / 1000 ;
V_62 = F_28 * V_60 / 100 ;
V_62 = ( V_62 + F_25 / 2 ) / F_25 ;
V_62 = V_62 * F_25 ;
V_63 = V_35 / 2 - V_62 ;
V_64 = F_26 ;
V_21 -> V_7 = V_24 ;
V_21 -> V_8 = V_24 + V_63 ;
V_21 -> V_9 = V_21 -> V_8 + V_62 ;
V_21 -> V_10 = V_60 ;
V_21 -> V_11 = V_26 ;
V_21 -> V_12 = V_26 + V_64 ;
V_21 -> V_13 = V_21 -> V_12 + F_27 ;
V_21 -> V_14 = V_52 ;
V_21 -> clock = V_61 ;
if ( V_19 ) {
V_21 -> V_14 *= 2 ;
V_21 -> V_15 |= V_38 ;
}
F_22 ( V_21 ) ;
if ( V_43 == 600 && V_44 == 80 && V_45 == 128 && V_46 == 40 )
V_21 -> V_15 = V_42 | V_41 ;
else
V_21 -> V_15 = V_39 | V_40 ;
return V_21 ;
}
struct V_1 *
F_32 ( struct V_16 * V_17 , int V_7 , int V_11 , int V_6 ,
bool V_65 , int V_20 )
{
return F_23 ( V_17 , V_7 , V_11 , V_6 , V_65 ,
V_20 , 600 , 40 * 2 , 128 , 20 * 2 ) ;
}
int F_33 ( const struct V_66 * V_67 ,
struct V_1 * V_68 )
{
V_68 -> V_7 = V_67 -> V_69 ;
V_68 -> V_8 = V_68 -> V_7 + V_67 -> V_63 ;
V_68 -> V_9 = V_68 -> V_8 + V_67 -> V_70 ;
V_68 -> V_10 = V_68 -> V_9 + V_67 -> V_71 ;
V_68 -> V_11 = V_67 -> V_72 ;
V_68 -> V_12 = V_68 -> V_11 + V_67 -> V_73 ;
V_68 -> V_13 = V_68 -> V_12 + V_67 -> V_74 ;
V_68 -> V_14 = V_68 -> V_13 + V_67 -> V_34 ;
V_68 -> clock = V_67 -> V_75 / 1000 ;
V_68 -> V_15 = 0 ;
if ( V_67 -> V_15 & V_76 )
V_68 -> V_15 |= V_39 ;
else if ( V_67 -> V_15 & V_77 )
V_68 -> V_15 |= V_42 ;
if ( V_67 -> V_15 & V_78 )
V_68 -> V_15 |= V_41 ;
else if ( V_67 -> V_15 & V_79 )
V_68 -> V_15 |= V_40 ;
if ( V_67 -> V_15 & V_80 )
V_68 -> V_15 |= V_38 ;
if ( V_67 -> V_15 & V_81 )
V_68 -> V_15 |= V_82 ;
if ( V_67 -> V_15 & V_83 )
V_68 -> V_15 |= V_84 ;
F_22 ( V_68 ) ;
return 0 ;
}
int F_34 ( struct V_85 * V_86 ,
struct V_1 * V_68 , int V_87 )
{
struct V_66 V_67 ;
int V_88 ;
V_88 = F_35 ( V_86 , & V_67 , V_87 ) ;
if ( V_88 )
return V_88 ;
F_33 ( & V_67 , V_68 ) ;
F_36 ( L_3 ,
F_37 ( V_86 ) , V_67 . V_69 , V_67 . V_72 , V_86 -> V_5 ) ;
F_1 ( V_68 ) ;
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
bool V_19 = ! ! ( V_2 -> V_15 & V_38 ) ;
snprintf ( V_2 -> V_5 , V_89 , L_4 ,
V_2 -> V_7 , V_2 -> V_11 ,
V_19 ? L_5 : L_6 ) ;
}
void F_38 ( struct V_90 * V_91 , struct V_90 * V_92 )
{
struct V_90 * V_93 , * V_94 ;
F_39 (entry, tmp, head) {
F_40 ( V_93 , V_92 ) ;
}
}
int F_41 ( const struct V_1 * V_2 )
{
return V_2 -> V_7 ;
}
int F_42 ( const struct V_1 * V_2 )
{
return V_2 -> V_11 ;
}
int F_43 ( const struct V_1 * V_2 )
{
unsigned int V_95 ;
if ( V_2 -> V_62 )
return V_2 -> V_62 ;
if ( V_2 -> V_10 < 0 )
return 0 ;
V_95 = ( V_2 -> clock * 1000 ) / V_2 -> V_10 ;
V_95 += 500 ;
V_95 /= 1000 ;
return V_95 ;
}
int F_44 ( const struct V_1 * V_2 )
{
int V_96 = 0 ;
unsigned int V_95 ;
if ( V_2 -> V_6 > 0 )
V_96 = V_2 -> V_6 ;
else if ( V_2 -> V_10 > 0 && V_2 -> V_14 > 0 ) {
int V_14 ;
V_14 = V_2 -> V_14 ;
V_95 = ( V_2 -> clock * 1000 ) ;
V_95 /= V_2 -> V_10 ;
V_96 = ( V_95 + V_14 / 2 ) / V_14 ;
if ( V_2 -> V_15 & V_38 )
V_96 *= 2 ;
if ( V_2 -> V_15 & V_82 )
V_96 /= 2 ;
if ( V_2 -> V_97 > 1 )
V_96 /= V_2 -> V_97 ;
}
return V_96 ;
}
void F_45 ( struct V_1 * V_98 , int V_99 )
{
if ( ( V_98 == NULL ) || ( ( V_98 -> type & V_100 ) == V_101 ) )
return;
V_98 -> V_102 = V_98 -> V_7 ;
V_98 -> V_103 = V_98 -> V_8 ;
V_98 -> V_104 = V_98 -> V_9 ;
V_98 -> V_105 = V_98 -> V_10 ;
V_98 -> V_106 = V_98 -> V_107 ;
V_98 -> V_108 = V_98 -> V_11 ;
V_98 -> V_109 = V_98 -> V_12 ;
V_98 -> V_110 = V_98 -> V_13 ;
V_98 -> V_111 = V_98 -> V_14 ;
if ( V_98 -> V_15 & V_38 ) {
if ( V_99 & V_112 ) {
V_98 -> V_108 /= 2 ;
V_98 -> V_109 /= 2 ;
V_98 -> V_110 /= 2 ;
V_98 -> V_111 /= 2 ;
}
}
if ( V_98 -> V_15 & V_82 ) {
V_98 -> V_108 *= 2 ;
V_98 -> V_109 *= 2 ;
V_98 -> V_110 *= 2 ;
V_98 -> V_111 *= 2 ;
}
if ( V_98 -> V_97 > 1 ) {
V_98 -> V_108 *= V_98 -> V_97 ;
V_98 -> V_109 *= V_98 -> V_97 ;
V_98 -> V_110 *= V_98 -> V_97 ;
V_98 -> V_111 *= V_98 -> V_97 ;
}
V_98 -> V_113 = F_46 ( V_98 -> V_109 , V_98 -> V_108 ) ;
V_98 -> V_114 = F_47 ( V_98 -> V_110 , V_98 -> V_111 ) ;
V_98 -> V_115 = F_46 ( V_98 -> V_103 , V_98 -> V_102 ) ;
V_98 -> V_116 = F_47 ( V_98 -> V_104 , V_98 -> V_105 ) ;
}
void F_48 ( struct V_1 * V_117 , const struct V_1 * V_118 )
{
int V_4 = V_117 -> V_3 . V_4 ;
struct V_90 V_91 = V_117 -> V_91 ;
* V_117 = * V_118 ;
V_117 -> V_3 . V_4 = V_4 ;
V_117 -> V_91 = V_91 ;
}
struct V_1 * F_49 ( struct V_16 * V_17 ,
const struct V_1 * V_2 )
{
struct V_1 * V_119 ;
V_119 = F_9 ( V_17 ) ;
if ( ! V_119 )
return NULL ;
F_48 ( V_119 , V_2 ) ;
return V_119 ;
}
bool F_50 ( const struct V_1 * V_120 , const struct V_1 * V_121 )
{
if ( V_120 -> clock && V_121 -> clock ) {
if ( F_51 ( V_120 -> clock ) != F_51 ( V_121 -> clock ) )
return false ;
} else if ( V_120 -> clock != V_121 -> clock )
return false ;
return F_52 ( V_120 , V_121 ) ;
}
bool F_52 ( const struct V_1 * V_120 , const struct V_1 * V_121 )
{
if ( V_120 -> V_7 == V_121 -> V_7 &&
V_120 -> V_8 == V_121 -> V_8 &&
V_120 -> V_9 == V_121 -> V_9 &&
V_120 -> V_10 == V_121 -> V_10 &&
V_120 -> V_107 == V_121 -> V_107 &&
V_120 -> V_11 == V_121 -> V_11 &&
V_120 -> V_12 == V_121 -> V_12 &&
V_120 -> V_13 == V_121 -> V_13 &&
V_120 -> V_14 == V_121 -> V_14 &&
V_120 -> V_97 == V_121 -> V_97 &&
V_120 -> V_15 == V_121 -> V_15 )
return true ;
return false ;
}
void F_53 ( struct V_16 * V_17 ,
struct V_90 * V_122 ,
int V_123 , int V_124 , int V_125 )
{
struct V_1 * V_2 ;
F_54 (mode, mode_list, head) {
if ( V_125 > 0 && V_2 -> V_7 > V_125 )
V_2 -> V_126 = V_127 ;
if ( V_123 > 0 && V_2 -> V_7 > V_123 )
V_2 -> V_126 = V_128 ;
if ( V_124 > 0 && V_2 -> V_11 > V_124 )
V_2 -> V_126 = V_129 ;
}
}
void F_55 ( struct V_16 * V_17 ,
struct V_90 * V_122 ,
int * F_46 , int * F_47 , int V_130 )
{
struct V_1 * V_2 ;
int V_131 ;
F_54 (mode, mode_list, head) {
bool V_132 = false ;
for ( V_131 = 0 ; V_131 < V_130 ; V_131 ++ ) {
if ( V_2 -> clock >= F_46 [ V_131 ] && V_2 -> clock <= F_47 [ V_131 ] ) {
V_132 = true ;
break;
}
}
if ( ! V_132 )
V_2 -> V_126 = V_133 ;
}
}
void F_56 ( struct V_16 * V_17 ,
struct V_90 * V_122 , bool V_134 )
{
struct V_1 * V_2 , * V_135 ;
F_57 (mode, t, mode_list, head) {
if ( V_2 -> V_126 != V_136 ) {
F_58 ( & V_2 -> V_91 ) ;
if ( V_134 ) {
F_1 ( V_2 ) ;
F_2 ( L_7 ,
V_2 -> V_5 , V_2 -> V_126 ) ;
}
F_59 ( V_17 , V_2 ) ;
}
}
}
static int F_60 ( void * V_137 , struct V_90 * V_138 , struct V_90 * V_139 )
{
struct V_1 * V_140 = F_61 ( V_138 , struct V_1 , V_91 ) ;
struct V_1 * V_141 = F_61 ( V_139 , struct V_1 , V_91 ) ;
int V_142 ;
V_142 = ( ( V_141 -> type & V_143 ) != 0 ) -
( ( V_140 -> type & V_143 ) != 0 ) ;
if ( V_142 )
return V_142 ;
V_142 = V_141 -> V_7 * V_141 -> V_11 - V_140 -> V_7 * V_140 -> V_11 ;
if ( V_142 )
return V_142 ;
V_142 = V_141 -> V_6 - V_140 -> V_6 ;
if ( V_142 )
return V_142 ;
V_142 = V_141 -> clock - V_140 -> clock ;
return V_142 ;
}
void F_62 ( struct V_90 * V_122 )
{
F_63 ( NULL , V_122 , F_60 ) ;
}
void F_64 ( struct V_144 * V_145 )
{
struct V_1 * V_2 ;
struct V_1 * V_146 , * V_147 ;
int V_148 ;
F_57 (pmode, pt, &connector->probed_modes,
head) {
V_148 = 0 ;
F_54 (mode, &connector->modes, head) {
if ( F_50 ( V_146 , V_2 ) ) {
V_148 = 1 ;
V_2 -> V_126 = V_146 -> V_126 ;
V_2 -> type |= V_146 -> type ;
F_58 ( & V_146 -> V_91 ) ;
F_59 ( V_145 -> V_17 , V_146 ) ;
break;
}
}
if ( ! V_148 ) {
F_40 ( & V_146 -> V_91 , & V_145 -> V_149 ) ;
}
}
}
bool F_65 ( const char * V_150 ,
struct V_144 * V_145 ,
struct V_151 * V_2 )
{
const char * V_5 ;
unsigned int V_152 ;
bool V_153 = false , V_154 = false , V_155 = false ;
unsigned int V_156 = 0 , V_157 = 0 , V_158 = 32 , V_96 = 0 ;
bool V_159 = false , V_160 = false , V_161 = false ;
bool V_29 = false , V_20 = false , V_162 = false ;
int V_131 ;
enum V_163 V_164 = V_165 ;
#ifdef F_66
if ( ! V_150 )
V_150 = V_166 ;
#endif
if ( ! V_150 ) {
V_2 -> V_167 = false ;
return false ;
}
V_5 = V_150 ;
V_152 = strlen ( V_5 ) ;
for ( V_131 = V_152 - 1 ; V_131 >= 0 ; V_131 -- ) {
switch ( V_5 [ V_131 ] ) {
case '@' :
if ( ! V_155 && ! V_154 &&
! V_159 && ! V_160 && ! V_161 && V_162 ) {
V_96 = F_67 ( & V_5 [ V_131 + 1 ] , NULL , 10 ) ;
V_155 = true ;
V_162 = false ;
} else
goto V_168;
break;
case '-' :
if ( ! V_154 && ! V_159 && ! V_160 &&
! V_161 && V_162 ) {
V_158 = F_67 ( & V_5 [ V_131 + 1 ] , NULL , 10 ) ;
V_154 = true ;
V_162 = false ;
} else
goto V_168;
break;
case 'x' :
if ( ! V_159 && V_162 ) {
V_157 = F_67 ( & V_5 [ V_131 + 1 ] , NULL , 10 ) ;
V_159 = true ;
V_162 = false ;
} else
goto V_168;
break;
case '0' ... '9' :
V_162 = true ;
break;
case 'M' :
if ( V_159 || V_160 || V_162 )
goto V_168;
V_160 = true ;
break;
case 'R' :
if ( V_159 || V_160 || V_161 || V_162 )
goto V_168;
V_161 = true ;
break;
case 'm' :
if ( V_160 || V_159 || V_162 )
goto V_168;
V_20 = true ;
break;
case 'i' :
if ( V_160 || V_159 || V_162 )
goto V_168;
V_29 = true ;
break;
case 'e' :
if ( V_159 || V_154 || V_155 ||
V_162 || ( V_164 != V_165 ) )
goto V_168;
V_164 = V_169 ;
break;
case 'D' :
if ( V_159 || V_154 || V_155 ||
V_162 || ( V_164 != V_165 ) )
goto V_168;
if ( ( V_145 -> V_170 != V_171 ) &&
( V_145 -> V_170 != V_172 ) )
V_164 = V_169 ;
else
V_164 = V_173 ;
break;
case 'd' :
if ( V_159 || V_154 || V_155 ||
V_162 || ( V_164 != V_165 ) )
goto V_168;
V_164 = V_174 ;
break;
default:
goto V_168;
}
}
if ( V_131 < 0 && V_159 ) {
char * V_175 ;
V_156 = F_67 ( V_5 , & V_175 , 10 ) ;
if ( ( V_175 != NULL ) && ( * V_175 == 'x' ) )
V_153 = true ;
else
V_131 = V_175 - V_5 ;
} else if ( ! V_159 && V_162 ) {
V_131 = 0 ;
}
V_168:
if ( V_131 >= 0 ) {
F_68 ( V_176
L_8 ,
V_131 , V_5 ) ;
V_2 -> V_167 = false ;
return false ;
}
if ( V_153 ) {
V_2 -> V_167 = true ;
V_2 -> V_156 = V_156 ;
V_2 -> V_157 = V_157 ;
}
if ( V_155 ) {
V_2 -> V_155 = true ;
V_2 -> V_96 = V_96 ;
}
if ( V_154 ) {
V_2 -> V_154 = true ;
V_2 -> V_158 = V_158 ;
}
V_2 -> V_161 = V_161 ;
V_2 -> V_160 = V_160 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_164 = V_164 ;
return true ;
}
struct V_1 *
F_69 ( struct V_16 * V_17 ,
struct V_151 * V_177 )
{
struct V_1 * V_2 ;
if ( V_177 -> V_160 )
V_2 = F_3 ( V_17 ,
V_177 -> V_156 , V_177 -> V_157 ,
V_177 -> V_155 ? V_177 -> V_96 : 60 ,
V_177 -> V_161 , V_177 -> V_29 ,
V_177 -> V_20 ) ;
else
V_2 = F_32 ( V_17 ,
V_177 -> V_156 , V_177 -> V_157 ,
V_177 -> V_155 ? V_177 -> V_96 : 60 ,
V_177 -> V_29 ,
V_177 -> V_20 ) ;
if ( ! V_2 )
return NULL ;
F_45 ( V_2 , V_112 ) ;
return V_2 ;
}
