static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
if ( V_2 -> V_4 )
return F_2 ( V_2 -> V_5 + V_3 ) ;
else
return F_3 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_6 )
{
if ( V_2 -> V_4 )
F_5 ( V_6 , V_2 -> V_5 + V_3 ) ;
else
F_6 ( V_6 , V_2 -> V_5 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , int V_7 ,
struct V_8 * V_9 )
{
T_2 V_3 = V_10 + ( V_7 * sizeof( struct V_8 ) ) ;
V_9 -> V_11 = F_1 ( V_2 , V_3 + 0 ) ;
V_9 -> V_12 = F_1 ( V_2 , V_3 + 4 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , int V_7 ,
const struct V_8 * V_9 )
{
T_2 V_3 = V_10 + ( V_7 * sizeof( struct V_8 ) ) ;
F_4 ( V_2 , V_3 + 0 , V_9 -> V_11 ) ;
F_4 ( V_2 , V_3 + 4 , V_9 -> V_12 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_13 )
{
T_1 V_14 = F_1 ( V_2 , V_15 ) ;
V_14 |= V_13 ;
F_4 ( V_2 , V_15 , V_14 ) ;
}
static inline void F_10 ( struct V_1 * V_2 , T_1 V_13 )
{
T_1 V_14 = F_1 ( V_2 , V_15 ) ;
V_14 &= ~ V_13 ;
F_4 ( V_2 , V_15 , V_14 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , T_1 V_13 )
{
F_4 ( V_2 , V_16 , V_13 ) ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
T_1 V_17 = F_1 ( V_2 , V_18 ) ;
V_17 |= V_19 | V_20 ;
F_4 ( V_2 , V_18 , V_17 ) ;
}
static inline void F_13 ( struct V_1 * V_2 )
{
T_1 V_17 = F_1 ( V_2 , V_18 ) ;
V_17 &= ~ ( V_19 | V_20 ) ;
F_4 ( V_2 , V_18 , V_17 ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned long V_21 )
{
struct V_8 V_9 ;
int V_22 ;
void * V_23 ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 0 ;
V_2 -> V_26 = 0 ;
F_4 ( V_2 , V_27 , V_2 -> V_28 ) ;
V_9 . V_12 = V_21 ;
V_9 . V_11 = V_29 | V_30 ;
V_23 = V_2 -> V_31 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_28 ; V_22 ++ ) {
if ( V_22 == V_2 -> V_28 - 1 )
V_9 . V_11 |= V_32 ;
F_8 ( V_2 , V_22 , & V_9 ) ;
V_9 . V_12 += V_33 ;
V_2 -> V_23 [ V_22 ] = V_23 ;
V_23 += V_33 ;
}
V_9 . V_11 = V_34 | V_35 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_36 ; V_22 ++ ) {
if ( V_22 == V_2 -> V_36 - 1 )
V_9 . V_11 |= V_37 ;
F_8 ( V_2 , V_2 -> V_28 + V_22 , & V_9 ) ;
V_9 . V_12 += V_33 ;
V_2 -> V_23 [ V_2 -> V_28 + V_22 ] = V_23 ;
V_23 += V_33 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_17 ;
F_13 ( V_2 ) ;
V_17 = F_1 ( V_2 , V_18 ) ;
V_17 |= V_38 | V_39 ;
F_4 ( V_2 , V_18 , V_17 ) ;
V_17 = F_1 ( V_2 , V_18 ) ;
V_17 |= V_40 ;
F_4 ( V_2 , V_18 , V_17 ) ;
F_4 ( V_2 , V_41 , 0x15 ) ;
F_11 ( V_2 , V_42 ) ;
F_9 ( V_2 , V_42 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static unsigned int F_16 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
unsigned int V_45 = 0 ;
if ( V_9 -> V_11 & V_46 ) {
F_17 ( & V_44 -> V_2 , L_1 ) ;
V_44 -> V_47 . V_48 ++ ;
V_45 ++ ;
}
if ( V_9 -> V_11 & V_49 ) {
F_17 ( & V_44 -> V_2 , L_2 ) ;
V_44 -> V_47 . V_48 ++ ;
V_45 ++ ;
}
if ( V_9 -> V_11 & V_50 ) {
F_17 ( & V_44 -> V_2 , L_3 ) ;
V_44 -> V_47 . V_51 ++ ;
}
if ( V_9 -> V_11 & V_52 ) {
F_17 ( & V_44 -> V_2 , L_4 ) ;
V_44 -> V_47 . V_53 ++ ;
V_45 ++ ;
}
if ( V_9 -> V_11 & V_54 ) {
F_17 ( & V_44 -> V_2 , L_5 ) ;
V_44 -> V_47 . V_55 ++ ;
V_45 ++ ;
}
if ( V_9 -> V_11 & V_56 )
V_44 -> V_47 . V_57 ++ ;
if ( V_9 -> V_11 & V_58 ) {
F_17 ( & V_44 -> V_2 , L_6 ) ;
V_44 -> V_47 . V_59 ++ ;
V_45 ++ ;
}
return V_45 ;
}
static int F_18 ( struct V_43 * V_2 , int V_60 )
{
struct V_1 * V_61 = F_19 ( V_2 ) ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_60 ; ++ V_62 ) {
unsigned int V_63 ;
struct V_8 V_9 ;
V_63 = V_61 -> V_28 + V_61 -> V_26 ;
F_7 ( V_61 , V_63 , & V_9 ) ;
if ( V_9 . V_11 & V_34 ) {
F_11 ( V_61 , V_64 ) ;
F_7 ( V_61 , V_63 , & V_9 ) ;
if ( V_9 . V_11 & V_34 )
break;
}
if ( F_16 ( V_61 , & V_9 ) == 0 ) {
int V_65 = V_9 . V_11 >> 16 ;
struct V_66 * V_67 ;
V_65 -= 4 ;
V_67 = F_20 ( V_2 , V_65 ) ;
if ( F_21 ( V_67 ) ) {
void * V_68 = V_61 -> V_23 [ V_63 ] ;
F_22 ( F_23 ( V_67 , V_65 ) , V_68 , V_65 ) ;
V_67 -> V_69 = F_24 ( V_67 , V_2 ) ;
V_2 -> V_47 . V_70 ++ ;
V_2 -> V_47 . V_71 += V_65 ;
F_25 ( V_67 ) ;
} else {
if ( F_26 () )
F_27 ( & V_2 -> V_2 ,
L_7 ) ;
V_2 -> V_47 . V_72 ++ ;
break;
}
}
V_9 . V_11 &= ~ V_73 ;
V_9 . V_11 |= V_34 ;
F_8 ( V_61 , V_63 , & V_9 ) ;
if ( ++ V_61 -> V_26 == V_61 -> V_36 )
V_61 -> V_26 = 0 ;
}
return V_62 ;
}
static void F_28 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
if ( V_9 -> V_11 & V_74 ) {
F_17 ( & V_44 -> V_2 , L_8 ) ;
V_44 -> V_47 . V_75 ++ ;
}
if ( V_9 -> V_11 & V_76 ) {
F_17 ( & V_44 -> V_2 , L_9 ) ;
V_44 -> V_47 . V_77 ++ ;
}
if ( V_9 -> V_11 & V_78 ) {
F_17 ( & V_44 -> V_2 , L_10 ) ;
V_44 -> V_47 . V_79 ++ ;
}
if ( V_9 -> V_11 & V_80 ) {
F_17 ( & V_44 -> V_2 , L_11 ) ;
V_44 -> V_47 . V_81 ++ ;
}
if ( V_9 -> V_11 & V_82 )
V_44 -> V_47 . V_83 ++ ;
V_44 -> V_47 . V_59 += ( V_9 -> V_11 >> 4 ) & 0xf ;
V_44 -> V_47 . V_84 += V_9 -> V_11 >> 16 ;
V_44 -> V_47 . V_85 ++ ;
}
static int F_29 ( struct V_43 * V_2 , int V_60 )
{
struct V_1 * V_61 = F_19 ( V_2 ) ;
int V_62 ;
struct V_8 V_9 ;
for ( V_62 = 0 ; V_62 < V_60 ; ++ V_62 ) {
unsigned int V_63 ;
V_63 = V_61 -> V_25 & ( V_61 -> V_28 - 1 ) ;
F_7 ( V_61 , V_63 , & V_9 ) ;
if ( V_9 . V_11 & V_86 || ( V_61 -> V_25 == V_61 -> V_24 ) ) {
F_11 ( V_61 , V_87 ) ;
F_7 ( V_61 , V_63 , & V_9 ) ;
if ( V_9 . V_11 & V_86 ||
( V_61 -> V_25 == V_61 -> V_24 ) )
break;
}
F_28 ( V_61 , & V_9 ) ;
V_61 -> V_25 ++ ;
}
if ( ( V_61 -> V_24 - V_61 -> V_25 ) <= ( V_61 -> V_28 / 2 ) )
F_30 ( V_2 ) ;
return V_62 ;
}
static T_3 F_31 ( int V_88 , void * V_89 )
{
struct V_43 * V_2 = V_89 ;
struct V_1 * V_61 = F_19 ( V_2 ) ;
T_1 V_90 ;
T_1 V_13 ;
V_13 = F_1 ( V_61 , V_15 ) ;
V_90 = F_1 ( V_61 , V_16 ) ;
V_90 &= V_13 ;
if ( F_32 ( V_90 == 0 ) )
return V_91 ;
F_11 ( V_61 , V_90 ) ;
if ( V_90 & V_92 ) {
F_33 ( & V_2 -> V_2 , L_12 ) ;
V_2 -> V_47 . V_72 ++ ;
}
if ( V_90 & ( V_87 | V_64 ) ) {
F_10 ( V_61 , V_87 | V_64 ) ;
F_34 ( & V_61 -> V_93 ) ;
}
return V_94 ;
}
static int F_35 ( struct V_43 * V_2 , void * V_12 )
{
struct V_1 * V_61 = F_19 ( V_2 ) ;
T_4 * V_95 = ( T_4 * ) V_12 ;
T_1 V_96 ;
V_96 = F_1 ( V_61 , V_97 ) ;
V_95 [ 2 ] = ( V_96 >> 24 ) & 0xff ;
V_95 [ 3 ] = ( V_96 >> 16 ) & 0xff ;
V_95 [ 4 ] = ( V_96 >> 8 ) & 0xff ;
V_95 [ 5 ] = ( V_96 >> 0 ) & 0xff ;
V_96 = F_1 ( V_61 , V_98 ) ;
V_95 [ 0 ] = ( V_96 >> 8 ) & 0xff ;
V_95 [ 1 ] = ( V_96 >> 0 ) & 0xff ;
return 0 ;
}
static int F_36 ( struct V_99 * V_93 , int V_100 )
{
struct V_1 * V_61 = F_37 ( V_93 , struct V_1 , V_93 ) ;
int V_101 = 0 ;
int V_102 = 0 ;
V_101 = F_18 ( V_61 -> V_44 , V_100 ) ;
V_102 = F_29 ( V_61 -> V_44 , V_100 ) ;
if ( V_101 < V_100 && V_102 < V_100 ) {
F_38 ( V_93 ) ;
F_9 ( V_61 , V_87 | V_64 ) ;
}
return V_101 ;
}
static int F_39 ( struct V_103 * V_104 , int V_105 , int V_96 )
{
struct V_1 * V_61 = V_104 -> V_61 ;
int V_22 ;
F_4 ( V_61 , V_106 , F_40 ( V_105 , V_96 ) ) ;
F_4 ( V_61 , V_107 , V_108 ) ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ ) {
T_1 V_109 = F_1 ( V_61 , V_110 ) ;
if ( ! ( V_109 & V_111 ) ) {
T_1 V_6 = F_1 ( V_61 , V_112 ) ;
F_4 ( V_61 , V_107 , 0 ) ;
return V_6 ;
}
F_41 ( 100 , 200 ) ;
}
return - V_113 ;
}
static int F_42 ( struct V_103 * V_104 , int V_105 , int V_96 , T_5 V_114 )
{
struct V_1 * V_61 = V_104 -> V_61 ;
int V_22 ;
F_4 ( V_61 , V_106 , F_40 ( V_105 , V_96 ) ) ;
F_4 ( V_61 , V_115 , V_114 ) ;
F_4 ( V_61 , V_107 , V_116 ) ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ ) {
T_1 V_11 = F_1 ( V_61 , V_110 ) ;
if ( ! ( V_11 & V_111 ) ) {
F_4 ( V_61 , V_107 , 0 ) ;
return 0 ;
}
F_41 ( 100 , 200 ) ;
}
return - V_113 ;
}
static void F_43 ( struct V_43 * V_2 )
{
struct V_1 * V_61 = F_19 ( V_2 ) ;
struct V_117 * V_118 = V_2 -> V_118 ;
bool V_119 = false ;
T_1 V_17 ;
if ( V_61 -> V_120 != V_118 -> V_121 ) {
V_119 = true ;
V_61 -> V_120 = V_118 -> V_121 ;
}
if ( V_61 -> V_122 != V_118 -> V_123 ) {
V_119 = true ;
V_61 -> V_122 = V_118 -> V_123 ;
}
if ( ! V_119 )
return;
V_17 = F_1 ( V_61 , V_18 ) ;
if ( V_118 -> V_123 == V_124 )
V_17 |= V_40 ;
else
V_17 &= ~ V_40 ;
F_4 ( V_61 , V_18 , V_17 ) ;
F_44 ( V_118 ) ;
}
static int F_45 ( struct V_43 * V_2 )
{
struct V_1 * V_61 = F_19 ( V_2 ) ;
struct V_117 * V_105 ;
int V_125 ;
if ( V_61 -> V_126 != - 1 )
V_105 = F_46 ( V_61 -> V_127 , V_61 -> V_126 ) ;
else
V_105 = F_47 ( V_61 -> V_127 ) ;
if ( ! V_105 ) {
F_17 ( & V_2 -> V_2 , L_13 ) ;
return - V_128 ;
}
V_61 -> V_122 = - 1 ;
V_61 -> V_120 = - 1 ;
V_125 = F_48 ( V_2 , V_105 , F_43 ,
V_129 ) ;
if ( V_125 ) {
F_17 ( & V_2 -> V_2 , L_14 ) ;
return V_125 ;
}
V_105 -> V_130 &= ~ ( V_131 |
V_132 ) ;
V_105 -> V_133 &= ~ ( V_134 |
V_135 ) ;
return 0 ;
}
static int F_49 ( struct V_43 * V_2 )
{
struct V_1 * V_61 = F_19 ( V_2 ) ;
int V_45 ;
V_45 = F_50 ( V_2 -> V_88 , F_31 , V_136 ,
V_2 -> V_137 , V_2 ) ;
if ( V_45 )
return V_45 ;
F_14 ( V_61 , V_2 -> V_21 ) ;
F_15 ( V_61 ) ;
if ( F_51 ( V_2 ) ) {
F_33 ( & V_2 -> V_2 , L_15 ) ;
F_30 ( V_2 ) ;
} else {
F_33 ( & V_2 -> V_2 , L_16 ) ;
F_52 ( V_2 ) ;
}
V_61 -> V_120 = - 1 ;
V_61 -> V_122 = - 1 ;
F_53 ( V_2 -> V_118 ) ;
F_54 ( & V_61 -> V_93 ) ;
if ( F_55 ( V_61 ) ) {
F_56 ( & V_2 -> V_2 , L_17 ,
V_2 -> V_138 , V_2 -> V_21 , V_2 -> V_139 ) ;
}
return 0 ;
}
static int F_57 ( struct V_43 * V_2 )
{
struct V_1 * V_61 = F_19 ( V_2 ) ;
F_58 ( & V_61 -> V_93 ) ;
if ( V_2 -> V_118 )
F_59 ( V_2 -> V_118 ) ;
F_13 ( V_61 ) ;
F_60 ( V_2 -> V_88 , V_2 ) ;
if ( ! F_51 ( V_2 ) )
F_61 ( V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_43 * V_2 , struct V_140 * V_141 , int V_142 )
{
struct V_1 * V_61 = F_19 ( V_2 ) ;
struct V_143 * V_127 = F_63 ( V_141 ) ;
struct V_117 * V_105 = NULL ;
if ( ! F_64 ( V_2 ) )
return - V_144 ;
if ( V_142 != V_145 ) {
if ( V_127 -> V_126 >= V_146 )
return - V_147 ;
V_105 = F_46 ( V_61 -> V_127 , V_127 -> V_126 ) ;
if ( ! V_105 )
return - V_148 ;
} else {
V_105 = V_2 -> V_118 ;
}
return F_65 ( V_105 , V_141 , V_142 ) ;
}
static void F_66 ( struct V_43 * V_2 )
{
struct V_1 * V_61 = F_19 ( V_2 ) ;
unsigned char * V_95 = V_2 -> V_149 ;
F_4 ( V_61 , V_97 , ( V_95 [ 2 ] << 24 ) | ( V_95 [ 3 ] << 16 ) |
( V_95 [ 4 ] << 8 ) | ( V_95 [ 5 ] << 0 ) ) ;
F_4 ( V_61 , V_98 , ( V_95 [ 0 ] << 8 ) | ( V_95 [ 1 ] << 0 ) ) ;
}
static int F_67 ( struct V_43 * V_2 , void * V_150 )
{
const struct V_151 * V_12 = V_150 ;
if ( ! F_68 ( V_12 -> V_152 ) )
return - V_153 ;
memcpy ( V_2 -> V_149 , V_12 -> V_152 , V_154 ) ;
F_66 ( V_2 ) ;
return 0 ;
}
static void F_69 ( struct V_43 * V_2 )
{
struct V_1 * V_61 = F_19 ( V_2 ) ;
T_1 V_17 = F_1 ( V_61 , V_18 ) ;
struct V_155 * V_156 ;
T_1 V_157 [ 2 ] = { 0 , 0 } ;
if ( V_2 -> V_158 & V_159 )
V_17 |= V_160 ;
else
V_17 &= ~ V_160 ;
if ( V_2 -> V_158 & V_161 )
V_17 &= ~ V_162 ;
else
V_17 |= V_162 ;
if ( V_2 -> V_158 & V_163 )
V_17 |= V_164 ;
else
V_17 &= ~ V_164 ;
F_4 ( V_61 , V_18 , V_17 ) ;
if ( V_2 -> V_158 & V_165 ) {
V_157 [ 0 ] = 0xffffffff ;
V_157 [ 1 ] = 0xffffffff ;
} else {
F_70 (ha, dev) {
T_1 V_166 = F_71 ( V_154 , V_156 -> V_12 ) ;
int V_167 = ( V_166 >> 26 ) & 0x3f ;
V_157 [ V_167 >> 5 ] |= 1 << ( V_167 & 0x1f ) ;
}
}
F_4 ( V_61 , V_168 , V_157 [ 0 ] ) ;
F_4 ( V_61 , V_169 , V_157 [ 1 ] ) ;
}
static int F_72 ( struct V_43 * V_2 , int V_170 )
{
return - V_171 ;
}
static void F_73 ( struct V_43 * V_2 )
{
struct V_1 * V_61 = F_19 ( V_2 ) ;
T_1 V_90 = F_1 ( V_61 , V_16 ) ;
if ( F_21 ( V_90 ) )
F_31 ( V_2 -> V_88 , V_2 ) ;
}
static T_6 F_74 ( struct V_66 * V_67 , struct V_43 * V_2 )
{
struct V_1 * V_61 = F_19 ( V_2 ) ;
struct V_8 V_9 ;
unsigned int V_63 ;
void * V_172 ;
if ( F_75 ( V_67 , V_173 ) ) {
V_2 -> V_47 . V_83 ++ ;
goto V_174;
}
if ( F_32 ( V_67 -> V_175 > V_33 ) ) {
V_2 -> V_47 . V_83 ++ ;
goto V_176;
}
V_63 = V_61 -> V_24 % V_61 -> V_28 ;
F_76 ( & V_61 -> V_177 ) ;
V_61 -> V_24 ++ ;
F_7 ( V_61 , V_63 , & V_9 ) ;
if ( F_32 ( V_67 -> V_175 < V_173 ) )
V_9 . V_11 |= V_178 ;
else
V_9 . V_11 &= ~ V_178 ;
V_172 = V_61 -> V_23 [ V_63 ] ;
F_77 ( V_172 , V_67 -> V_6 , V_67 -> V_175 ) ;
V_9 . V_11 &= ~ ( V_82 | V_179 ) ;
V_9 . V_11 |= F_78 ( V_67 -> V_175 ) ;
F_8 ( V_61 , V_63 , & V_9 ) ;
V_9 . V_11 |= V_86 ;
F_8 ( V_61 , V_63 , & V_9 ) ;
if ( V_61 -> V_24 == ( V_61 -> V_25 + V_61 -> V_28 ) ) {
F_33 ( & V_2 -> V_2 , L_18 ) ;
F_61 ( V_2 ) ;
}
F_79 ( & V_61 -> V_177 ) ;
F_80 ( V_67 ) ;
V_176:
F_81 ( V_67 ) ;
V_174:
return V_180 ;
}
static int F_82 ( struct V_43 * V_44 )
{
return V_181 ;
}
static void F_83 ( struct V_43 * V_2 , struct V_182 * V_183 ,
void * V_150 )
{
struct V_1 * V_61 = F_19 ( V_2 ) ;
T_1 * V_184 = V_150 ;
unsigned V_22 ;
V_183 -> V_185 = 0 ;
for ( V_22 = 0 ; V_22 < V_181 / sizeof( T_1 ) ; ++ V_22 )
V_184 [ V_22 ] = F_1 ( V_61 , V_22 * sizeof( T_1 ) ) ;
}
static void F_84 ( struct V_43 * V_2 ,
struct V_186 * V_187 )
{
struct V_1 * V_61 = F_19 ( V_2 ) ;
V_187 -> V_188 = V_61 -> V_189 - 1 ;
V_187 -> V_190 = 0 ;
V_187 -> V_191 = 0 ;
V_187 -> V_192 = V_61 -> V_189 - 1 ;
V_187 -> V_193 = V_61 -> V_36 ;
V_187 -> V_194 = 0 ;
V_187 -> V_195 = 0 ;
V_187 -> V_196 = V_61 -> V_28 ;
}
static int F_85 ( struct V_43 * V_2 ,
struct V_186 * V_187 )
{
struct V_1 * V_61 = F_19 ( V_2 ) ;
if ( V_187 -> V_196 < 1 || V_187 -> V_193 < 1 ||
V_187 -> V_196 + V_187 -> V_193 > V_61 -> V_189 )
return - V_144 ;
if ( V_187 -> V_194 || V_187 -> V_195 )
return - V_144 ;
if ( F_64 ( V_2 ) ) {
F_86 ( V_2 ) ;
F_13 ( V_61 ) ;
F_10 ( V_61 , V_87 | V_64 ) ;
F_87 ( V_2 -> V_88 ) ;
}
V_61 -> V_28 = F_88 ( V_187 -> V_196 ) ;
V_61 -> V_36 = V_187 -> V_193 ;
F_14 ( V_61 , V_2 -> V_21 ) ;
if ( F_64 ( V_2 ) ) {
F_9 ( V_61 , V_87 | V_64 ) ;
F_12 ( V_61 ) ;
F_30 ( V_2 ) ;
}
return 0 ;
}
static int F_89 ( struct V_197 * V_198 )
{
struct V_43 * V_44 = NULL ;
struct V_199 * V_200 = NULL ;
struct V_199 * V_201 = NULL ;
struct V_199 * V_202 = NULL ;
struct V_1 * V_61 = NULL ;
int V_189 ;
int V_45 = 0 ;
bool V_203 = false ;
struct V_204 * V_205 = F_90 ( & V_198 -> V_2 ) ;
T_1 V_206 = V_205 ? V_205 -> V_206 : 0 ;
V_44 = F_91 ( sizeof( struct V_1 ) ) ;
if ( ! V_44 ) {
V_45 = - V_207 ;
goto V_176;
}
F_92 ( V_44 , & V_198 -> V_2 ) ;
F_93 ( V_198 , V_44 ) ;
V_200 = F_94 ( V_198 , V_208 , 0 ) ;
if ( ! V_200 ) {
F_17 ( & V_198 -> V_2 , L_19 ) ;
V_45 = - V_128 ;
goto free;
}
V_201 = F_95 ( & V_198 -> V_2 , V_200 -> V_209 ,
F_96 ( V_200 ) , V_200 -> V_137 ) ;
if ( ! V_201 ) {
F_17 ( & V_198 -> V_2 , L_20 ) ;
V_45 = - V_128 ;
goto free;
}
V_44 -> V_138 = V_201 -> V_209 ;
V_200 = F_94 ( V_198 , V_208 , 1 ) ;
if ( V_200 ) {
V_202 = F_95 ( & V_198 -> V_2 , V_200 -> V_209 ,
F_96 ( V_200 ) , V_200 -> V_137 ) ;
if ( ! V_202 ) {
F_17 ( & V_198 -> V_2 , L_21 ) ;
V_45 = - V_128 ;
goto free;
}
V_44 -> V_21 = V_202 -> V_209 ;
V_44 -> V_139 = V_202 -> V_210 ;
}
V_200 = F_94 ( V_198 , V_211 , 0 ) ;
if ( ! V_200 ) {
F_17 ( & V_198 -> V_2 , L_22 ) ;
V_45 = - V_128 ;
goto free;
}
V_44 -> V_88 = V_200 -> V_209 ;
V_61 = F_19 ( V_44 ) ;
V_61 -> V_44 = V_44 ;
V_61 -> V_212 = 0 ;
V_61 -> V_213 = F_96 ( V_201 ) ;
V_61 -> V_5 = F_97 ( & V_198 -> V_2 , V_44 -> V_138 ,
F_96 ( V_201 ) ) ;
if ( ! V_61 -> V_5 ) {
F_17 ( & V_198 -> V_2 , L_23 ) ;
V_45 = - V_128 ;
goto free;
}
if ( V_44 -> V_139 ) {
V_61 -> V_31 = F_97 ( & V_198 -> V_2 ,
V_44 -> V_21 , F_96 ( V_202 ) ) ;
if ( ! V_61 -> V_31 ) {
F_17 ( & V_198 -> V_2 , L_24 ) ;
V_45 = - V_128 ;
goto free;
}
} else {
V_61 -> V_31 = F_98 ( & V_198 -> V_2 ,
V_214 , ( void * ) & V_44 -> V_21 ,
V_215 ) ;
if ( ! V_61 -> V_31 ) {
F_17 ( & V_198 -> V_2 , L_25 ,
V_214 ) ;
V_45 = - V_207 ;
goto free;
}
V_44 -> V_139 = V_44 -> V_21 + V_214 ;
V_61 -> V_212 = V_214 ;
}
V_61 -> V_4 = V_205 ? V_205 -> V_4 :
F_99 ( V_198 -> V_2 . V_216 ) ;
V_189 = F_100 (unsigned int,
128 , (netdev->mem_end - netdev->mem_start + 1) / ETHOC_BUFSIZ) ;
if ( V_189 < 4 ) {
V_45 = - V_148 ;
goto free;
}
V_61 -> V_189 = V_189 ;
V_61 -> V_28 = F_88 ( V_189 >> 1 ) ;
V_61 -> V_36 = V_189 - V_61 -> V_28 ;
F_33 ( & V_198 -> V_2 , L_26 ,
V_61 -> V_28 , V_61 -> V_36 ) ;
V_61 -> V_23 = F_101 ( & V_198 -> V_2 , V_189 * sizeof( void * ) , V_215 ) ;
if ( ! V_61 -> V_23 ) {
V_45 = - V_207 ;
goto free;
}
if ( V_205 ) {
memcpy ( V_44 -> V_149 , V_205 -> V_217 , V_218 ) ;
V_61 -> V_126 = V_205 -> V_126 ;
} else {
const void * V_95 ;
V_95 = F_102 ( V_198 -> V_2 . V_216 ) ;
if ( V_95 )
memcpy ( V_44 -> V_149 , V_95 , V_218 ) ;
V_61 -> V_126 = - 1 ;
}
if ( ! F_68 ( V_44 -> V_149 ) )
F_35 ( V_44 , V_44 -> V_149 ) ;
if ( ! F_68 ( V_44 -> V_149 ) ) {
F_103 ( V_44 -> V_149 ) ;
V_203 = true ;
}
F_66 ( V_44 ) ;
if ( V_203 )
V_44 -> V_219 = V_220 ;
if ( ! V_206 ) {
struct V_221 * V_221 = F_104 ( & V_198 -> V_2 , NULL ) ;
if ( ! F_105 ( V_221 ) ) {
V_61 -> V_221 = V_221 ;
F_106 ( V_221 ) ;
V_206 = F_107 ( V_221 ) ;
}
}
if ( V_206 ) {
T_1 V_222 = F_108 ( V_206 / 2500000 + 1 ) ;
if ( ! V_222 )
V_222 = 2 ;
F_33 ( & V_198 -> V_2 , L_27 , V_222 ) ;
F_4 ( V_61 , V_223 ,
( F_1 ( V_61 , V_223 ) & V_224 ) |
V_222 ) ;
}
V_61 -> V_127 = F_109 () ;
if ( ! V_61 -> V_127 ) {
V_45 = - V_207 ;
goto V_225;
}
V_61 -> V_127 -> V_137 = L_28 ;
snprintf ( V_61 -> V_127 -> V_226 , V_227 , L_29 ,
V_61 -> V_127 -> V_137 , V_198 -> V_226 ) ;
V_61 -> V_127 -> V_228 = F_39 ;
V_61 -> V_127 -> V_229 = F_42 ;
V_61 -> V_127 -> V_61 = V_61 ;
V_45 = F_110 ( V_61 -> V_127 ) ;
if ( V_45 ) {
F_17 ( & V_44 -> V_2 , L_30 ) ;
goto V_225;
}
V_45 = F_45 ( V_44 ) ;
if ( V_45 ) {
F_17 ( & V_44 -> V_2 , L_31 ) ;
goto error;
}
V_44 -> V_230 = & V_231 ;
V_44 -> V_232 = V_233 ;
V_44 -> V_234 |= 0 ;
V_44 -> V_235 = & V_236 ;
F_111 ( V_44 , & V_61 -> V_93 , F_36 , 64 ) ;
F_112 ( & V_61 -> V_177 ) ;
V_45 = F_113 ( V_44 ) ;
if ( V_45 < 0 ) {
F_17 ( & V_44 -> V_2 , L_32 ) ;
goto V_237;
}
goto V_176;
V_237:
F_114 ( & V_61 -> V_93 ) ;
error:
F_115 ( V_61 -> V_127 ) ;
F_116 ( V_61 -> V_127 ) ;
V_225:
if ( V_61 -> V_221 )
F_117 ( V_61 -> V_221 ) ;
free:
F_118 ( V_44 ) ;
V_176:
return V_45 ;
}
static int F_119 ( struct V_197 * V_198 )
{
struct V_43 * V_44 = F_120 ( V_198 ) ;
struct V_1 * V_61 = F_19 ( V_44 ) ;
if ( V_44 ) {
F_114 ( & V_61 -> V_93 ) ;
F_121 ( V_44 -> V_118 ) ;
if ( V_61 -> V_127 ) {
F_115 ( V_61 -> V_127 ) ;
F_116 ( V_61 -> V_127 ) ;
}
if ( V_61 -> V_221 )
F_117 ( V_61 -> V_221 ) ;
F_122 ( V_44 ) ;
F_118 ( V_44 ) ;
}
return 0 ;
}
static int F_123 ( struct V_197 * V_198 , T_7 V_238 )
{
return - V_171 ;
}
static int F_124 ( struct V_197 * V_198 )
{
return - V_171 ;
}
