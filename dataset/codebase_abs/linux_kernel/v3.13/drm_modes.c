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
int F_38 ( const struct V_1 * V_2 )
{
return V_2 -> V_7 ;
}
int F_39 ( const struct V_1 * V_2 )
{
return V_2 -> V_11 ;
}
int F_40 ( const struct V_1 * V_2 )
{
unsigned int V_90 ;
if ( V_2 -> V_62 )
return V_2 -> V_62 ;
if ( V_2 -> V_10 < 0 )
return 0 ;
V_90 = ( V_2 -> clock * 1000 ) / V_2 -> V_10 ;
V_90 += 500 ;
V_90 /= 1000 ;
return V_90 ;
}
int F_41 ( const struct V_1 * V_2 )
{
int V_91 = 0 ;
unsigned int V_90 ;
if ( V_2 -> V_6 > 0 )
V_91 = V_2 -> V_6 ;
else if ( V_2 -> V_10 > 0 && V_2 -> V_14 > 0 ) {
int V_14 ;
V_14 = V_2 -> V_14 ;
V_90 = ( V_2 -> clock * 1000 ) ;
V_90 /= V_2 -> V_10 ;
V_91 = ( V_90 + V_14 / 2 ) / V_14 ;
if ( V_2 -> V_15 & V_38 )
V_91 *= 2 ;
if ( V_2 -> V_15 & V_82 )
V_91 /= 2 ;
if ( V_2 -> V_92 > 1 )
V_91 /= V_2 -> V_92 ;
}
return V_91 ;
}
void F_42 ( struct V_1 * V_93 , int V_94 )
{
if ( ( V_93 == NULL ) || ( ( V_93 -> type & V_95 ) == V_96 ) )
return;
V_93 -> V_97 = V_93 -> clock ;
V_93 -> V_98 = V_93 -> V_7 ;
V_93 -> V_99 = V_93 -> V_8 ;
V_93 -> V_100 = V_93 -> V_9 ;
V_93 -> V_101 = V_93 -> V_10 ;
V_93 -> V_102 = V_93 -> V_103 ;
V_93 -> V_104 = V_93 -> V_11 ;
V_93 -> V_105 = V_93 -> V_12 ;
V_93 -> V_106 = V_93 -> V_13 ;
V_93 -> V_107 = V_93 -> V_14 ;
if ( V_93 -> V_15 & V_38 ) {
if ( V_94 & V_108 ) {
V_93 -> V_104 /= 2 ;
V_93 -> V_105 /= 2 ;
V_93 -> V_106 /= 2 ;
V_93 -> V_107 /= 2 ;
}
}
if ( V_93 -> V_15 & V_82 ) {
V_93 -> V_104 *= 2 ;
V_93 -> V_105 *= 2 ;
V_93 -> V_106 *= 2 ;
V_93 -> V_107 *= 2 ;
}
if ( V_93 -> V_92 > 1 ) {
V_93 -> V_104 *= V_93 -> V_92 ;
V_93 -> V_105 *= V_93 -> V_92 ;
V_93 -> V_106 *= V_93 -> V_92 ;
V_93 -> V_107 *= V_93 -> V_92 ;
}
if ( V_94 & V_109 ) {
unsigned int V_110 = V_93 -> V_15 & V_111 ;
switch ( V_110 ) {
case V_112 :
V_93 -> V_97 *= 2 ;
V_93 -> V_104 += V_93 -> V_107 ;
V_93 -> V_105 += V_93 -> V_107 ;
V_93 -> V_106 += V_93 -> V_107 ;
V_93 -> V_107 += V_93 -> V_107 ;
break;
}
}
V_93 -> V_113 = F_43 ( V_93 -> V_105 , V_93 -> V_104 ) ;
V_93 -> V_114 = F_44 ( V_93 -> V_106 , V_93 -> V_107 ) ;
V_93 -> V_115 = F_43 ( V_93 -> V_99 , V_93 -> V_98 ) ;
V_93 -> V_116 = F_44 ( V_93 -> V_100 , V_93 -> V_101 ) ;
}
void F_45 ( struct V_1 * V_117 , const struct V_1 * V_118 )
{
int V_4 = V_117 -> V_3 . V_4 ;
struct V_119 V_120 = V_117 -> V_120 ;
* V_117 = * V_118 ;
V_117 -> V_3 . V_4 = V_4 ;
V_117 -> V_120 = V_120 ;
}
struct V_1 * F_46 ( struct V_16 * V_17 ,
const struct V_1 * V_2 )
{
struct V_1 * V_121 ;
V_121 = F_9 ( V_17 ) ;
if ( ! V_121 )
return NULL ;
F_45 ( V_121 , V_2 ) ;
return V_121 ;
}
bool F_47 ( const struct V_1 * V_122 , const struct V_1 * V_123 )
{
if ( V_122 -> clock && V_123 -> clock ) {
if ( F_48 ( V_122 -> clock ) != F_48 ( V_123 -> clock ) )
return false ;
} else if ( V_122 -> clock != V_123 -> clock )
return false ;
if ( ( V_122 -> V_15 & V_111 ) !=
( V_123 -> V_15 & V_111 ) )
return false ;
return F_49 ( V_122 , V_123 ) ;
}
bool F_49 ( const struct V_1 * V_122 ,
const struct V_1 * V_123 )
{
if ( V_122 -> V_7 == V_123 -> V_7 &&
V_122 -> V_8 == V_123 -> V_8 &&
V_122 -> V_9 == V_123 -> V_9 &&
V_122 -> V_10 == V_123 -> V_10 &&
V_122 -> V_103 == V_123 -> V_103 &&
V_122 -> V_11 == V_123 -> V_11 &&
V_122 -> V_12 == V_123 -> V_12 &&
V_122 -> V_13 == V_123 -> V_13 &&
V_122 -> V_14 == V_123 -> V_14 &&
V_122 -> V_92 == V_123 -> V_92 &&
( V_122 -> V_15 & ~ V_111 ) ==
( V_123 -> V_15 & ~ V_111 ) )
return true ;
return false ;
}
void F_50 ( struct V_16 * V_17 ,
struct V_119 * V_124 ,
int V_125 , int V_126 , int V_127 )
{
struct V_1 * V_2 ;
F_51 (mode, mode_list, head) {
if ( V_127 > 0 && V_2 -> V_7 > V_127 )
V_2 -> V_128 = V_129 ;
if ( V_125 > 0 && V_2 -> V_7 > V_125 )
V_2 -> V_128 = V_130 ;
if ( V_126 > 0 && V_2 -> V_11 > V_126 )
V_2 -> V_128 = V_131 ;
}
}
void F_52 ( struct V_16 * V_17 ,
struct V_119 * V_124 , bool V_132 )
{
struct V_1 * V_2 , * V_133 ;
F_53 (mode, t, mode_list, head) {
if ( V_2 -> V_128 != V_134 ) {
F_54 ( & V_2 -> V_120 ) ;
if ( V_132 ) {
F_1 ( V_2 ) ;
F_2 ( L_7 ,
V_2 -> V_5 , V_2 -> V_128 ) ;
}
F_55 ( V_17 , V_2 ) ;
}
}
}
static int F_56 ( void * V_135 , struct V_119 * V_136 , struct V_119 * V_137 )
{
struct V_1 * V_138 = F_57 ( V_136 , struct V_1 , V_120 ) ;
struct V_1 * V_139 = F_57 ( V_137 , struct V_1 , V_120 ) ;
int V_140 ;
V_140 = ( ( V_139 -> type & V_141 ) != 0 ) -
( ( V_138 -> type & V_141 ) != 0 ) ;
if ( V_140 )
return V_140 ;
V_140 = V_139 -> V_7 * V_139 -> V_11 - V_138 -> V_7 * V_138 -> V_11 ;
if ( V_140 )
return V_140 ;
V_140 = V_139 -> V_6 - V_138 -> V_6 ;
if ( V_140 )
return V_140 ;
V_140 = V_139 -> clock - V_138 -> clock ;
return V_140 ;
}
void F_58 ( struct V_119 * V_124 )
{
F_59 ( NULL , V_124 , F_56 ) ;
}
void F_60 ( struct V_142 * V_143 )
{
struct V_1 * V_2 ;
struct V_1 * V_144 , * V_145 ;
int V_146 ;
F_53 (pmode, pt, &connector->probed_modes,
head) {
V_146 = 0 ;
F_51 (mode, &connector->modes, head) {
if ( F_47 ( V_144 , V_2 ) ) {
V_146 = 1 ;
V_2 -> V_128 = V_144 -> V_128 ;
V_2 -> type |= V_144 -> type ;
F_54 ( & V_144 -> V_120 ) ;
F_55 ( V_143 -> V_17 , V_144 ) ;
break;
}
}
if ( ! V_146 ) {
F_61 ( & V_144 -> V_120 , & V_143 -> V_147 ) ;
}
}
}
bool F_62 ( const char * V_148 ,
struct V_142 * V_143 ,
struct V_149 * V_2 )
{
const char * V_5 ;
unsigned int V_150 ;
bool V_151 = false , V_152 = false , V_153 = false ;
unsigned int V_154 = 0 , V_155 = 0 , V_156 = 32 , V_91 = 0 ;
bool V_157 = false , V_158 = false , V_159 = false ;
bool V_29 = false , V_20 = false , V_160 = false ;
int V_161 ;
enum V_162 V_163 = V_164 ;
#ifdef F_63
if ( ! V_148 )
V_148 = V_165 ;
#endif
if ( ! V_148 ) {
V_2 -> V_166 = false ;
return false ;
}
V_5 = V_148 ;
V_150 = strlen ( V_5 ) ;
for ( V_161 = V_150 - 1 ; V_161 >= 0 ; V_161 -- ) {
switch ( V_5 [ V_161 ] ) {
case '@' :
if ( ! V_153 && ! V_152 &&
! V_157 && ! V_158 && ! V_159 && V_160 ) {
V_91 = F_64 ( & V_5 [ V_161 + 1 ] , NULL , 10 ) ;
V_153 = true ;
V_160 = false ;
} else
goto V_167;
break;
case '-' :
if ( ! V_152 && ! V_157 && ! V_158 &&
! V_159 && V_160 ) {
V_156 = F_64 ( & V_5 [ V_161 + 1 ] , NULL , 10 ) ;
V_152 = true ;
V_160 = false ;
} else
goto V_167;
break;
case 'x' :
if ( ! V_157 && V_160 ) {
V_155 = F_64 ( & V_5 [ V_161 + 1 ] , NULL , 10 ) ;
V_157 = true ;
V_160 = false ;
} else
goto V_167;
break;
case '0' ... '9' :
V_160 = true ;
break;
case 'M' :
if ( V_157 || V_158 || V_160 )
goto V_167;
V_158 = true ;
break;
case 'R' :
if ( V_157 || V_158 || V_159 || V_160 )
goto V_167;
V_159 = true ;
break;
case 'm' :
if ( V_158 || V_157 || V_160 )
goto V_167;
V_20 = true ;
break;
case 'i' :
if ( V_158 || V_157 || V_160 )
goto V_167;
V_29 = true ;
break;
case 'e' :
if ( V_157 || V_152 || V_153 ||
V_160 || ( V_163 != V_164 ) )
goto V_167;
V_163 = V_168 ;
break;
case 'D' :
if ( V_157 || V_152 || V_153 ||
V_160 || ( V_163 != V_164 ) )
goto V_167;
if ( ( V_143 -> V_169 != V_170 ) &&
( V_143 -> V_169 != V_171 ) )
V_163 = V_168 ;
else
V_163 = V_172 ;
break;
case 'd' :
if ( V_157 || V_152 || V_153 ||
V_160 || ( V_163 != V_164 ) )
goto V_167;
V_163 = V_173 ;
break;
default:
goto V_167;
}
}
if ( V_161 < 0 && V_157 ) {
char * V_174 ;
V_154 = F_64 ( V_5 , & V_174 , 10 ) ;
if ( ( V_174 != NULL ) && ( * V_174 == 'x' ) )
V_151 = true ;
else
V_161 = V_174 - V_5 ;
} else if ( ! V_157 && V_160 ) {
V_161 = 0 ;
}
V_167:
if ( V_161 >= 0 ) {
F_65 ( V_175
L_8 ,
V_161 , V_5 ) ;
V_2 -> V_166 = false ;
return false ;
}
if ( V_151 ) {
V_2 -> V_166 = true ;
V_2 -> V_154 = V_154 ;
V_2 -> V_155 = V_155 ;
}
if ( V_153 ) {
V_2 -> V_153 = true ;
V_2 -> V_91 = V_91 ;
}
if ( V_152 ) {
V_2 -> V_152 = true ;
V_2 -> V_156 = V_156 ;
}
V_2 -> V_159 = V_159 ;
V_2 -> V_158 = V_158 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_163 = V_163 ;
return true ;
}
struct V_1 *
F_66 ( struct V_16 * V_17 ,
struct V_149 * V_176 )
{
struct V_1 * V_2 ;
if ( V_176 -> V_158 )
V_2 = F_3 ( V_17 ,
V_176 -> V_154 , V_176 -> V_155 ,
V_176 -> V_153 ? V_176 -> V_91 : 60 ,
V_176 -> V_159 , V_176 -> V_29 ,
V_176 -> V_20 ) ;
else
V_2 = F_32 ( V_17 ,
V_176 -> V_154 , V_176 -> V_155 ,
V_176 -> V_153 ? V_176 -> V_91 : 60 ,
V_176 -> V_29 ,
V_176 -> V_20 ) ;
if ( ! V_2 )
return NULL ;
F_42 ( V_2 , V_108 ) ;
return V_2 ;
}
