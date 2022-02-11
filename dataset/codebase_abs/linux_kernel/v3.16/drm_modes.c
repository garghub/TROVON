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
struct V_1 * F_3 ( struct V_16 * V_17 )
{
struct V_1 * V_18 ;
V_18 = F_4 ( sizeof( struct V_1 ) , V_19 ) ;
if ( ! V_18 )
return NULL ;
if ( F_5 ( V_17 , & V_18 -> V_3 , V_20 ) ) {
F_6 ( V_18 ) ;
return NULL ;
}
return V_18 ;
}
void F_7 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_8 ( V_17 , & V_2 -> V_3 ) ;
F_6 ( V_2 ) ;
}
void F_9 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
F_10 ( ! F_11 ( & V_22 -> V_17 -> V_23 . V_24 ) ) ;
F_12 ( & V_2 -> V_25 , & V_22 -> V_26 ) ;
}
struct V_1 * F_13 ( struct V_16 * V_17 , int V_7 ,
int V_11 , int V_6 ,
bool V_27 , bool V_28 , bool V_29 )
{
#define F_14 1000
#define F_15 18
#define F_16 8
#define F_17 3
#define F_18 6
#define F_19 250
struct V_1 * V_30 ;
unsigned int V_31 , V_32 ;
int V_33 , V_34 , V_35 , V_36 , V_37 ;
int V_38 ;
V_30 = F_3 ( V_17 ) ;
if ( ! V_30 )
return NULL ;
if ( ! V_6 )
V_6 = 60 ;
if ( V_28 )
V_31 = V_6 * 2 ;
else
V_31 = V_6 ;
V_33 = V_7 - ( V_7 % F_16 ) ;
V_34 = 0 ;
if ( V_29 ) {
V_34 = V_33 * F_15 / 1000 ;
V_34 -= V_34 % F_16 ;
}
V_30 -> V_7 = V_33 + 2 * V_34 ;
if ( V_28 )
V_35 = V_11 / 2 ;
else
V_35 = V_11 ;
V_36 = 0 ;
if ( V_29 )
V_36 = V_35 * F_15 / 1000 ;
V_30 -> V_11 = V_11 + 2 * V_36 ;
if ( V_28 )
V_38 = 1 ;
else
V_38 = 0 ;
if ( ! ( V_11 % 3 ) && ( ( V_11 * 4 / 3 ) == V_7 ) )
V_37 = 4 ;
else if ( ! ( V_11 % 9 ) && ( ( V_11 * 16 / 9 ) == V_7 ) )
V_37 = 5 ;
else if ( ! ( V_11 % 10 ) && ( ( V_11 * 16 / 10 ) == V_7 ) )
V_37 = 6 ;
else if ( ! ( V_11 % 4 ) && ( ( V_11 * 5 / 4 ) == V_7 ) )
V_37 = 7 ;
else if ( ! ( V_11 % 9 ) && ( ( V_11 * 15 / 9 ) == V_7 ) )
V_37 = 7 ;
else
V_37 = 10 ;
if ( ! V_27 ) {
int V_39 , V_40 ;
#define F_20 550
#define F_21 8
unsigned int V_41 ;
int V_42 , V_43 , V_44 ;
V_39 = F_14 * 1000000 -
F_20 * F_14 * V_31 ;
V_40 = ( V_35 + 2 * V_36 + F_17 ) * 2 +
V_38 ;
V_32 = V_39 * 2 / ( V_40 * V_31 ) ;
V_39 = F_20 * F_14 / V_32 + 1 ;
if ( V_39 < ( V_37 + F_17 ) )
V_42 = V_37 + F_17 ;
else
V_42 = V_39 ;
V_43 = V_42 - V_37 ;
V_30 -> V_14 = V_35 + 2 * V_36 +
V_42 + F_17 ;
#define F_22 600
#define F_23 40
#define F_24 128
#define F_25 20
#define F_26 (CVT_M_FACTOR * CVT_K_FACTOR / 256)
#define F_27 ((CVT_C_FACTOR - CVT_J_FACTOR) * CVT_K_FACTOR / 256 + \
CVT_J_FACTOR)
V_41 = F_27 * F_14 - F_26 *
V_32 / 1000 ;
if ( V_41 < 20 * F_14 )
V_41 = 20 * F_14 ;
V_44 = V_30 -> V_7 * V_41 /
( 100 * F_14 - V_41 ) ;
V_44 -= V_44 % ( 2 * F_16 ) ;
V_30 -> V_10 = V_30 -> V_7 + V_44 ;
V_30 -> V_9 = V_30 -> V_7 + V_44 / 2 ;
V_30 -> V_8 = V_30 -> V_9 -
( V_30 -> V_10 * F_21 ) / 100 ;
V_30 -> V_8 += F_16 -
V_30 -> V_8 % F_16 ;
V_30 -> V_12 = V_30 -> V_11 + F_17 ;
V_30 -> V_13 = V_30 -> V_12 + V_37 ;
} else {
#define F_28 460
#define F_29 32
#define F_30 160
#define F_31 3
int V_45 ;
int V_39 , V_40 ;
V_39 = F_14 * 1000000 -
F_28 * F_14 * V_31 ;
V_40 = V_35 + 2 * V_36 ;
V_32 = V_39 / ( V_40 * V_31 ) ;
V_45 = F_28 * F_14 / V_32 + 1 ;
if ( V_45 < ( F_31 + V_37 + F_18 ) )
V_45 = F_31 + V_37 + F_18 ;
V_30 -> V_14 = V_35 + 2 * V_36 + V_45 ;
V_30 -> V_10 = V_30 -> V_7 + F_30 ;
V_30 -> V_9 = V_30 -> V_7 + F_30 / 2 ;
V_30 -> V_8 = V_30 -> V_9 - F_29 ;
V_30 -> V_12 = V_30 -> V_11 + F_31 ;
V_30 -> V_13 = V_30 -> V_12 + V_37 ;
}
V_30 -> clock = V_30 -> V_10 * F_14 * 1000 / V_32 ;
V_30 -> clock -= V_30 -> clock % F_19 ;
if ( V_28 ) {
V_30 -> V_14 *= 2 ;
V_30 -> V_15 |= V_46 ;
}
F_32 ( V_30 ) ;
if ( V_27 )
V_30 -> V_15 |= ( V_47 |
V_48 ) ;
else
V_30 -> V_15 |= ( V_49 |
V_50 ) ;
return V_30 ;
}
struct V_1 *
F_33 ( struct V_16 * V_17 , int V_7 , int V_11 ,
int V_6 , bool V_28 , int V_29 ,
int V_51 , int V_52 , int V_53 , int V_54 )
{
#define F_34 18
#define F_35 8
#define F_36 1
#define F_37 3
#define F_38 8
#define F_39 550
#define F_40 ((((GTF_2C - GTF_2J) * GTF_K / 256) + GTF_2J) / 2)
#define F_41 (GTF_K * GTF_M / 256)
struct V_1 * V_30 ;
unsigned int V_33 , V_35 , V_55 ;
int V_56 , V_57 ;
int V_38 ;
unsigned int V_58 ;
int V_59 , V_43 ;
unsigned int V_60 , V_61 , V_32 ;
unsigned int V_62 , V_63 ;
int V_64 , V_65 ;
unsigned int V_66 , V_67 ;
unsigned int V_44 , V_68 , V_69 ;
int V_70 , V_71 , V_72 ;
unsigned int V_39 , V_40 ;
V_30 = F_3 ( V_17 ) ;
if ( ! V_30 )
return NULL ;
V_33 = ( V_7 + F_35 / 2 ) / F_35 ;
V_33 = V_33 * F_35 ;
if ( V_28 )
V_35 = V_11 / 2 ;
else
V_35 = V_11 ;
if ( V_28 )
V_55 = V_6 * 2 ;
else
V_55 = V_6 ;
V_56 = 0 ;
if ( V_29 )
V_56 = ( V_35 * F_34 + 500 ) /
1000 ;
V_57 = V_56 ;
if ( V_28 )
V_38 = 1 ;
else
V_38 = 0 ;
{
V_39 = ( 1000000 - F_39 * V_55 ) / 500 ;
V_40 = ( V_35 + 2 * V_56 + F_36 ) *
2 + V_38 ;
V_58 = ( V_40 * 1000 * V_55 ) / V_39 ;
}
V_59 = F_39 * V_58 / 1000 ;
V_59 = ( V_59 + 500 ) / 1000 ;
V_43 = V_59 - F_37 ;
V_60 = V_35 + V_56 + V_57 +
V_59 + F_36 ;
V_61 = V_58 / V_60 ;
V_32 = 1000000 / ( V_55 * V_60 ) ;
V_62 = V_58 / V_60 ;
if ( V_28 )
V_63 = V_62 / 2 ;
else
V_63 = V_62 ;
if ( V_29 )
V_64 = ( V_33 * F_34 + 500 ) /
1000 ;
else
V_64 = 0 ;
V_65 = V_64 ;
V_66 = V_33 + V_64 + V_65 ;
V_67 = F_40 * 1000 -
( F_41 * 1000000 / V_58 ) ;
V_44 = V_66 * V_67 /
( 100000 - V_67 ) ;
V_44 = ( V_44 + F_35 ) / ( 2 * F_35 ) ;
V_44 = V_44 * 2 * F_35 ;
V_68 = V_66 + V_44 ;
V_69 = V_68 * V_58 / 1000 ;
V_70 = F_38 * V_68 / 100 ;
V_70 = ( V_70 + F_35 / 2 ) / F_35 ;
V_70 = V_70 * F_35 ;
V_71 = V_44 / 2 - V_70 ;
V_72 = F_36 ;
V_30 -> V_7 = V_33 ;
V_30 -> V_8 = V_33 + V_71 ;
V_30 -> V_9 = V_30 -> V_8 + V_70 ;
V_30 -> V_10 = V_68 ;
V_30 -> V_11 = V_35 ;
V_30 -> V_12 = V_35 + V_72 ;
V_30 -> V_13 = V_30 -> V_12 + F_37 ;
V_30 -> V_14 = V_60 ;
V_30 -> clock = V_69 ;
if ( V_28 ) {
V_30 -> V_14 *= 2 ;
V_30 -> V_15 |= V_46 ;
}
F_32 ( V_30 ) ;
if ( V_51 == 600 && V_52 == 80 && V_53 == 128 && V_54 == 40 )
V_30 -> V_15 = V_50 | V_49 ;
else
V_30 -> V_15 = V_47 | V_48 ;
return V_30 ;
}
struct V_1 *
F_42 ( struct V_16 * V_17 , int V_7 , int V_11 , int V_6 ,
bool V_28 , int V_29 )
{
return F_33 ( V_17 , V_7 , V_11 , V_6 ,
V_28 , V_29 ,
600 , 40 * 2 , 128 , 20 * 2 ) ;
}
void F_43 ( const struct V_73 * V_74 ,
struct V_1 * V_75 )
{
V_75 -> V_7 = V_74 -> V_76 ;
V_75 -> V_8 = V_75 -> V_7 + V_74 -> V_71 ;
V_75 -> V_9 = V_75 -> V_8 + V_74 -> V_77 ;
V_75 -> V_10 = V_75 -> V_9 + V_74 -> V_78 ;
V_75 -> V_11 = V_74 -> V_79 ;
V_75 -> V_12 = V_75 -> V_11 + V_74 -> V_80 ;
V_75 -> V_13 = V_75 -> V_12 + V_74 -> V_81 ;
V_75 -> V_14 = V_75 -> V_13 + V_74 -> V_43 ;
V_75 -> clock = V_74 -> V_82 / 1000 ;
V_75 -> V_15 = 0 ;
if ( V_74 -> V_15 & V_83 )
V_75 -> V_15 |= V_47 ;
else if ( V_74 -> V_15 & V_84 )
V_75 -> V_15 |= V_50 ;
if ( V_74 -> V_15 & V_85 )
V_75 -> V_15 |= V_49 ;
else if ( V_74 -> V_15 & V_86 )
V_75 -> V_15 |= V_48 ;
if ( V_74 -> V_15 & V_87 )
V_75 -> V_15 |= V_46 ;
if ( V_74 -> V_15 & V_88 )
V_75 -> V_15 |= V_89 ;
if ( V_74 -> V_15 & V_90 )
V_75 -> V_15 |= V_91 ;
F_32 ( V_75 ) ;
}
int F_44 ( struct V_92 * V_93 ,
struct V_1 * V_75 , int V_94 )
{
struct V_73 V_74 ;
int V_95 ;
V_95 = F_45 ( V_93 , & V_74 , V_94 ) ;
if ( V_95 )
return V_95 ;
F_43 ( & V_74 , V_75 ) ;
F_46 ( L_3 ,
F_47 ( V_93 ) , V_74 . V_76 , V_74 . V_79 , V_93 -> V_5 ) ;
F_1 ( V_75 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
bool V_28 = ! ! ( V_2 -> V_15 & V_46 ) ;
snprintf ( V_2 -> V_5 , V_96 , L_4 ,
V_2 -> V_7 , V_2 -> V_11 ,
V_28 ? L_5 : L_6 ) ;
}
int F_48 ( const struct V_1 * V_2 )
{
unsigned int V_97 ;
if ( V_2 -> V_70 )
return V_2 -> V_70 ;
if ( V_2 -> V_10 < 0 )
return 0 ;
V_97 = ( V_2 -> clock * 1000 ) / V_2 -> V_10 ;
V_97 += 500 ;
V_97 /= 1000 ;
return V_97 ;
}
int F_49 ( const struct V_1 * V_2 )
{
int V_98 = 0 ;
unsigned int V_97 ;
if ( V_2 -> V_6 > 0 )
V_98 = V_2 -> V_6 ;
else if ( V_2 -> V_10 > 0 && V_2 -> V_14 > 0 ) {
int V_14 ;
V_14 = V_2 -> V_14 ;
V_97 = ( V_2 -> clock * 1000 ) ;
V_97 /= V_2 -> V_10 ;
V_98 = ( V_97 + V_14 / 2 ) / V_14 ;
if ( V_2 -> V_15 & V_46 )
V_98 *= 2 ;
if ( V_2 -> V_15 & V_89 )
V_98 /= 2 ;
if ( V_2 -> V_99 > 1 )
V_98 /= V_2 -> V_99 ;
}
return V_98 ;
}
void F_50 ( struct V_1 * V_100 , int V_101 )
{
if ( ( V_100 == NULL ) || ( ( V_100 -> type & V_102 ) == V_103 ) )
return;
V_100 -> V_104 = V_100 -> clock ;
V_100 -> V_105 = V_100 -> V_7 ;
V_100 -> V_106 = V_100 -> V_8 ;
V_100 -> V_107 = V_100 -> V_9 ;
V_100 -> V_108 = V_100 -> V_10 ;
V_100 -> V_109 = V_100 -> V_110 ;
V_100 -> V_111 = V_100 -> V_11 ;
V_100 -> V_112 = V_100 -> V_12 ;
V_100 -> V_113 = V_100 -> V_13 ;
V_100 -> V_114 = V_100 -> V_14 ;
if ( V_100 -> V_15 & V_46 ) {
if ( V_101 & V_115 ) {
V_100 -> V_111 /= 2 ;
V_100 -> V_112 /= 2 ;
V_100 -> V_113 /= 2 ;
V_100 -> V_114 /= 2 ;
}
}
if ( V_100 -> V_15 & V_89 ) {
V_100 -> V_111 *= 2 ;
V_100 -> V_112 *= 2 ;
V_100 -> V_113 *= 2 ;
V_100 -> V_114 *= 2 ;
}
if ( V_100 -> V_99 > 1 ) {
V_100 -> V_111 *= V_100 -> V_99 ;
V_100 -> V_112 *= V_100 -> V_99 ;
V_100 -> V_113 *= V_100 -> V_99 ;
V_100 -> V_114 *= V_100 -> V_99 ;
}
if ( V_101 & V_116 ) {
unsigned int V_117 = V_100 -> V_15 & V_118 ;
switch ( V_117 ) {
case V_119 :
V_100 -> V_104 *= 2 ;
V_100 -> V_111 += V_100 -> V_114 ;
V_100 -> V_112 += V_100 -> V_114 ;
V_100 -> V_113 += V_100 -> V_114 ;
V_100 -> V_114 += V_100 -> V_114 ;
break;
}
}
V_100 -> V_120 = F_51 ( V_100 -> V_112 , V_100 -> V_111 ) ;
V_100 -> V_121 = F_52 ( V_100 -> V_113 , V_100 -> V_114 ) ;
V_100 -> V_122 = F_51 ( V_100 -> V_106 , V_100 -> V_105 ) ;
V_100 -> V_123 = F_52 ( V_100 -> V_107 , V_100 -> V_108 ) ;
}
void F_53 ( struct V_1 * V_124 , const struct V_1 * V_125 )
{
int V_4 = V_124 -> V_3 . V_4 ;
struct V_126 V_25 = V_124 -> V_25 ;
* V_124 = * V_125 ;
V_124 -> V_3 . V_4 = V_4 ;
V_124 -> V_25 = V_25 ;
}
struct V_1 * F_54 ( struct V_16 * V_17 ,
const struct V_1 * V_2 )
{
struct V_1 * V_18 ;
V_18 = F_3 ( V_17 ) ;
if ( ! V_18 )
return NULL ;
F_53 ( V_18 , V_2 ) ;
return V_18 ;
}
bool F_55 ( const struct V_1 * V_127 , const struct V_1 * V_128 )
{
if ( V_127 -> clock && V_128 -> clock ) {
if ( F_56 ( V_127 -> clock ) != F_56 ( V_128 -> clock ) )
return false ;
} else if ( V_127 -> clock != V_128 -> clock )
return false ;
if ( ( V_127 -> V_15 & V_118 ) !=
( V_128 -> V_15 & V_118 ) )
return false ;
return F_57 ( V_127 , V_128 ) ;
}
bool F_57 ( const struct V_1 * V_127 ,
const struct V_1 * V_128 )
{
if ( V_127 -> V_7 == V_128 -> V_7 &&
V_127 -> V_8 == V_128 -> V_8 &&
V_127 -> V_9 == V_128 -> V_9 &&
V_127 -> V_10 == V_128 -> V_10 &&
V_127 -> V_110 == V_128 -> V_110 &&
V_127 -> V_11 == V_128 -> V_11 &&
V_127 -> V_12 == V_128 -> V_12 &&
V_127 -> V_13 == V_128 -> V_13 &&
V_127 -> V_14 == V_128 -> V_14 &&
V_127 -> V_99 == V_128 -> V_99 &&
( V_127 -> V_15 & ~ V_118 ) ==
( V_128 -> V_15 & ~ V_118 ) )
return true ;
return false ;
}
void F_58 ( struct V_16 * V_17 ,
struct V_126 * V_129 ,
int V_130 , int V_131 )
{
struct V_1 * V_2 ;
F_59 (mode, mode_list, head) {
if ( V_130 > 0 && V_2 -> V_7 > V_130 )
V_2 -> V_132 = V_133 ;
if ( V_131 > 0 && V_2 -> V_11 > V_131 )
V_2 -> V_132 = V_134 ;
}
}
void F_60 ( struct V_16 * V_17 ,
struct V_126 * V_129 , bool V_135 )
{
struct V_1 * V_2 , * V_136 ;
F_61 (mode, t, mode_list, head) {
if ( V_2 -> V_132 != V_137 ) {
F_62 ( & V_2 -> V_25 ) ;
if ( V_135 ) {
F_1 ( V_2 ) ;
F_2 ( L_7 ,
V_2 -> V_5 , V_2 -> V_132 ) ;
}
F_7 ( V_17 , V_2 ) ;
}
}
}
static int F_63 ( void * V_138 , struct V_126 * V_139 , struct V_126 * V_140 )
{
struct V_1 * V_141 = F_64 ( V_139 , struct V_1 , V_25 ) ;
struct V_1 * V_142 = F_64 ( V_140 , struct V_1 , V_25 ) ;
int V_143 ;
V_143 = ( ( V_142 -> type & V_144 ) != 0 ) -
( ( V_141 -> type & V_144 ) != 0 ) ;
if ( V_143 )
return V_143 ;
V_143 = V_142 -> V_7 * V_142 -> V_11 - V_141 -> V_7 * V_141 -> V_11 ;
if ( V_143 )
return V_143 ;
V_143 = V_142 -> V_6 - V_141 -> V_6 ;
if ( V_143 )
return V_143 ;
V_143 = V_142 -> clock - V_141 -> clock ;
return V_143 ;
}
void F_65 ( struct V_126 * V_129 )
{
F_66 ( NULL , V_129 , F_63 ) ;
}
void F_67 ( struct V_21 * V_22 ,
bool V_145 )
{
struct V_1 * V_2 ;
struct V_1 * V_146 , * V_147 ;
int V_148 ;
F_10 ( ! F_11 ( & V_22 -> V_17 -> V_23 . V_24 ) ) ;
F_61 (pmode, pt, &connector->probed_modes,
head) {
V_148 = 0 ;
F_59 (mode, &connector->modes, head) {
if ( F_55 ( V_146 , V_2 ) ) {
V_148 = 1 ;
V_2 -> V_132 = V_146 -> V_132 ;
if ( V_145 )
V_2 -> type |= V_146 -> type ;
else
V_2 -> type = V_146 -> type ;
F_62 ( & V_146 -> V_25 ) ;
F_7 ( V_22 -> V_17 , V_146 ) ;
break;
}
}
if ( ! V_148 ) {
F_68 ( & V_146 -> V_25 , & V_22 -> V_149 ) ;
}
}
}
bool F_69 ( const char * V_150 ,
struct V_21 * V_22 ,
struct V_151 * V_2 )
{
const char * V_5 ;
unsigned int V_152 ;
bool V_153 = false , V_154 = false , V_155 = false ;
unsigned int V_156 = 0 , V_157 = 0 , V_158 = 32 , V_98 = 0 ;
bool V_159 = false , V_160 = false , V_161 = false ;
bool V_38 = false , V_29 = false , V_162 = false ;
int V_163 ;
enum V_164 V_165 = V_166 ;
#ifdef F_70
if ( ! V_150 )
V_150 = V_167 ;
#endif
if ( ! V_150 ) {
V_2 -> V_168 = false ;
return false ;
}
V_5 = V_150 ;
V_152 = strlen ( V_5 ) ;
for ( V_163 = V_152 - 1 ; V_163 >= 0 ; V_163 -- ) {
switch ( V_5 [ V_163 ] ) {
case '@' :
if ( ! V_155 && ! V_154 &&
! V_159 && ! V_160 && ! V_161 && V_162 ) {
V_98 = F_71 ( & V_5 [ V_163 + 1 ] , NULL , 10 ) ;
V_155 = true ;
V_162 = false ;
} else
goto V_169;
break;
case '-' :
if ( ! V_154 && ! V_159 && ! V_160 &&
! V_161 && V_162 ) {
V_158 = F_71 ( & V_5 [ V_163 + 1 ] , NULL , 10 ) ;
V_154 = true ;
V_162 = false ;
} else
goto V_169;
break;
case 'x' :
if ( ! V_159 && V_162 ) {
V_157 = F_71 ( & V_5 [ V_163 + 1 ] , NULL , 10 ) ;
V_159 = true ;
V_162 = false ;
} else
goto V_169;
break;
case '0' ... '9' :
V_162 = true ;
break;
case 'M' :
if ( V_159 || V_160 || V_162 )
goto V_169;
V_160 = true ;
break;
case 'R' :
if ( V_159 || V_160 || V_161 || V_162 )
goto V_169;
V_161 = true ;
break;
case 'm' :
if ( V_160 || V_159 || V_162 )
goto V_169;
V_29 = true ;
break;
case 'i' :
if ( V_160 || V_159 || V_162 )
goto V_169;
V_38 = true ;
break;
case 'e' :
if ( V_159 || V_154 || V_155 ||
V_162 || ( V_165 != V_166 ) )
goto V_169;
V_165 = V_170 ;
break;
case 'D' :
if ( V_159 || V_154 || V_155 ||
V_162 || ( V_165 != V_166 ) )
goto V_169;
if ( ( V_22 -> V_171 != V_172 ) &&
( V_22 -> V_171 != V_173 ) )
V_165 = V_170 ;
else
V_165 = V_174 ;
break;
case 'd' :
if ( V_159 || V_154 || V_155 ||
V_162 || ( V_165 != V_166 ) )
goto V_169;
V_165 = V_175 ;
break;
default:
goto V_169;
}
}
if ( V_163 < 0 && V_159 ) {
char * V_176 ;
V_156 = F_71 ( V_5 , & V_176 , 10 ) ;
if ( ( V_176 != NULL ) && ( * V_176 == 'x' ) )
V_153 = true ;
else
V_163 = V_176 - V_5 ;
} else if ( ! V_159 && V_162 ) {
V_163 = 0 ;
}
V_169:
if ( V_163 >= 0 ) {
F_72 ( V_177
L_8 ,
V_163 , V_5 ) ;
V_2 -> V_168 = false ;
return false ;
}
if ( V_153 ) {
V_2 -> V_168 = true ;
V_2 -> V_156 = V_156 ;
V_2 -> V_157 = V_157 ;
}
if ( V_155 ) {
V_2 -> V_155 = true ;
V_2 -> V_98 = V_98 ;
}
if ( V_154 ) {
V_2 -> V_154 = true ;
V_2 -> V_158 = V_158 ;
}
V_2 -> V_161 = V_161 ;
V_2 -> V_160 = V_160 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_165 = V_165 ;
return true ;
}
struct V_1 *
F_73 ( struct V_16 * V_17 ,
struct V_151 * V_178 )
{
struct V_1 * V_2 ;
if ( V_178 -> V_160 )
V_2 = F_13 ( V_17 ,
V_178 -> V_156 , V_178 -> V_157 ,
V_178 -> V_155 ? V_178 -> V_98 : 60 ,
V_178 -> V_161 , V_178 -> V_38 ,
V_178 -> V_29 ) ;
else
V_2 = F_42 ( V_17 ,
V_178 -> V_156 , V_178 -> V_157 ,
V_178 -> V_155 ? V_178 -> V_98 : 60 ,
V_178 -> V_38 ,
V_178 -> V_29 ) ;
if ( ! V_2 )
return NULL ;
F_50 ( V_2 , V_115 ) ;
return V_2 ;
}
