static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( & V_3 -> V_4 -> V_5 , L_1 , V_6 ) ;
F_3 ( & V_3 -> V_7 ) ;
}
static int F_4 ( struct V_2 * V_3 ,
unsigned int V_8 , struct V_9 * V_10 , int V_11 ,
unsigned int V_12 , unsigned int * V_13 , int V_14 )
{
int V_15 ;
F_2 ( & V_3 -> V_4 -> V_5 , L_2 ,
V_6 , V_12 , V_11 ) ;
V_15 = F_5 ( & V_3 -> V_7 , V_3 -> V_16 , V_8 , 0 ,
V_10 , V_11 , V_12 , V_17 ) ;
if ( V_15 )
return V_15 ;
V_3 -> V_18 . V_19 = V_20 + F_6 ( V_14 ) ;
F_7 ( & V_3 -> V_18 ) ;
F_8 ( & V_3 -> V_7 ) ;
if ( ! F_9 ( & V_3 -> V_18 ) )
V_15 = - V_21 ;
else
V_15 = V_3 -> V_7 . V_22 ;
if ( V_13 )
* V_13 = V_3 -> V_7 . V_23 ;
return V_15 ;
}
int F_10 ( struct V_2 * V_3 , unsigned int V_8 ,
void * V_24 , unsigned int V_25 , int V_11 ,
unsigned int * V_13 , int V_14 )
{
if ( V_14 < 600 )
V_14 = 600 ;
if ( V_11 )
return F_4 ( V_3 , V_8 ,
(struct V_9 * ) V_24 , V_11 , V_25 , V_13 ,
V_14 ) ;
else
return F_11 ( V_3 -> V_16 , V_8 , V_24 , V_25 , V_13 ,
V_14 ) ;
}
static inline void F_12 ( struct V_2 * V_3 ,
T_1 V_26 , T_1 V_25 , T_2 V_27 )
{
F_13 ( V_3 ) ;
V_3 -> V_28 [ V_29 ] = V_27 ;
V_3 -> V_28 [ 5 ] = ( T_2 ) ( V_25 >> 8 ) ;
V_3 -> V_28 [ 6 ] = ( T_2 ) V_25 ;
V_3 -> V_28 [ 8 ] = ( T_2 ) ( V_26 >> 8 ) ;
V_3 -> V_28 [ 9 ] = ( T_2 ) V_26 ;
if ( V_27 == V_30 )
V_3 -> V_28 [ V_31 ] = 0 ;
else
V_3 -> V_28 [ V_31 ] = V_32 ;
}
static int F_14 ( struct V_2 * V_3 ,
T_1 V_26 , T_1 V_25 , T_2 * V_1 )
{
T_1 V_33 = F_15 ( V_34 + V_25 , 4 ) ;
if ( ! V_1 )
return - V_35 ;
if ( V_33 > V_36 )
return - V_35 ;
F_12 ( V_3 , V_26 , V_25 , V_30 ) ;
memcpy ( V_3 -> V_28 + V_34 , V_1 , V_25 ) ;
return F_10 ( V_3 ,
F_16 ( V_3 -> V_16 , V_37 ) ,
V_3 -> V_28 , V_33 , 0 , NULL , 100 ) ;
}
static int F_17 ( struct V_2 * V_3 ,
T_1 V_26 , T_1 V_25 , T_2 * V_1 )
{
int V_38 , V_15 ;
T_1 V_39 = F_18 ( V_25 , 4 ) ;
T_1 V_40 = V_25 - V_39 ;
if ( ! V_1 )
return - V_35 ;
if ( V_39 ) {
F_12 ( V_3 , V_26 , V_25 , V_41 ) ;
V_15 = F_10 ( V_3 ,
F_16 ( V_3 -> V_16 , V_37 ) ,
V_3 -> V_28 , 12 , 0 , NULL , 100 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_10 ( V_3 ,
F_19 ( V_3 -> V_16 , V_42 ) ,
V_1 , V_39 , 0 , NULL , 100 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_38 = 0 ; V_38 < V_40 ; V_38 ++ ) {
V_15 = F_20 ( V_3 , V_26 + V_39 + V_38 ,
V_1 + V_39 + V_38 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
int F_21 ( struct V_2 * V_3 , T_2 * V_24 , int V_43 )
{
return F_17 ( V_3 , V_44 , ( T_1 ) V_43 , V_24 ) ;
}
int F_22 ( struct V_2 * V_3 , T_2 * V_24 , int V_43 )
{
return F_14 ( V_3 , V_44 , ( T_1 ) V_43 , V_24 ) ;
}
int F_23 ( struct V_2 * V_3 , T_1 V_26 ,
T_2 V_45 , T_2 V_1 )
{
T_1 V_46 , V_47 ;
V_26 |= V_48 << V_49 ;
V_46 = F_24 ( V_26 ) ;
V_47 = V_45 | V_1 << 8 ;
return F_25 ( V_3 -> V_16 ,
F_26 ( V_3 -> V_16 , 0 ) , V_50 ,
V_51 | V_52 | V_53 ,
V_46 , V_47 , NULL , 0 , 100 ) ;
}
int F_27 ( struct V_2 * V_3 , T_1 V_26 , T_2 * V_1 )
{
T_1 V_46 ;
T_2 * V_24 ;
int V_15 ;
if ( ! V_1 )
return - V_35 ;
V_24 = F_28 ( sizeof( T_2 ) , V_54 ) ;
if ( ! V_24 )
return - V_55 ;
V_26 |= V_56 << V_49 ;
V_46 = F_24 ( V_26 ) ;
V_15 = F_25 ( V_3 -> V_16 ,
F_29 ( V_3 -> V_16 , 0 ) , V_50 ,
V_57 | V_52 | V_53 ,
V_46 , 0 , V_24 , 1 , 100 ) ;
* V_1 = * V_24 ;
F_30 ( V_24 ) ;
return V_15 ;
}
void F_31 ( struct V_2 * V_3 , T_2 V_58 , T_1 V_59 ,
T_2 V_45 , T_2 V_1 )
{
int V_38 ;
if ( V_3 -> V_60 < ( V_36 - V_61 ) / 4 ) {
V_38 = V_61 + V_3 -> V_60 * 4 ;
V_3 -> V_28 [ V_38 ++ ] = ( ( V_58 & 0x03 ) << 6 ) |
( T_2 ) ( ( V_59 >> 8 ) & 0x3F ) ;
V_3 -> V_28 [ V_38 ++ ] = ( T_2 ) V_59 ;
V_3 -> V_28 [ V_38 ++ ] = V_45 ;
V_3 -> V_28 [ V_38 ++ ] = V_1 ;
V_3 -> V_60 ++ ;
}
}
int F_32 ( struct V_2 * V_3 , T_2 V_62 , int V_14 )
{
int V_15 ;
V_3 -> V_28 [ V_63 ] = ( T_2 ) ( V_3 -> V_60 >> 8 ) ;
V_3 -> V_28 [ V_64 ] = ( T_2 ) ( V_3 -> V_60 ) ;
V_3 -> V_28 [ V_31 ] = V_62 ;
V_15 = F_10 ( V_3 ,
F_16 ( V_3 -> V_16 , V_37 ) ,
V_3 -> V_28 , V_3 -> V_60 * 4 + V_61 ,
0 , NULL , V_14 ) ;
if ( V_15 ) {
F_33 ( V_3 ) ;
return V_15 ;
}
return 0 ;
}
int F_34 ( struct V_2 * V_3 , int V_39 , int V_14 )
{
if ( V_39 <= 0 )
return - V_35 ;
V_39 = F_15 ( V_39 , 4 ) ;
return F_10 ( V_3 ,
F_19 ( V_3 -> V_16 , V_42 ) ,
V_3 -> V_65 , V_39 , 0 , NULL , V_14 ) ;
}
static int F_35 ( struct V_2 * V_3 , T_1 * V_22 )
{
int V_15 ;
F_36 ( V_3 ) ;
F_31 ( V_3 , V_66 , V_67 , 0x00 , 0x00 ) ;
F_31 ( V_3 , V_66 , V_68 , 0x00 , 0x00 ) ;
V_15 = F_32 ( V_3 , V_69 , 100 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_34 ( V_3 , 2 , 100 ) ;
if ( V_15 )
return V_15 ;
* V_22 = ( ( V_3 -> V_65 [ 0 ] >> 2 ) & 0x0f ) |
( ( V_3 -> V_65 [ 1 ] & 0x03 ) << 4 ) ;
return 0 ;
}
int F_37 ( struct V_2 * V_3 , T_1 * V_22 )
{
int V_15 ;
T_1 * V_24 ;
if ( ! V_22 )
return - V_35 ;
if ( V_70 == 0 ) {
V_24 = F_28 ( sizeof( T_1 ) , V_54 ) ;
if ( ! V_24 )
return - V_55 ;
V_15 = F_25 ( V_3 -> V_16 ,
F_29 ( V_3 -> V_16 , 0 ) ,
V_71 ,
V_57 | V_52 | V_53 ,
0 , 0 , V_24 , 2 , 100 ) ;
* V_22 = * V_24 ;
F_30 ( V_24 ) ;
} else {
V_15 = F_35 ( V_3 , V_22 ) ;
}
if ( V_15 < 0 )
return V_15 ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , T_2 V_26 , T_2 V_72 )
{
F_2 ( & V_3 -> V_4 -> V_5 , L_3 ,
V_72 , V_26 ) ;
F_36 ( V_3 ) ;
F_31 ( V_3 , V_73 , V_74 , 0xFF , V_72 ) ;
F_31 ( V_3 , V_73 , V_75 , 0xFF , V_26 & 0x0F ) ;
F_31 ( V_3 , V_73 , V_76 , 0xFF , 0x00 ) ;
F_31 ( V_3 , V_73 , V_76 , 0xFF , 0x00 ) ;
F_31 ( V_3 , V_73 , V_76 , 0xFF , 0x01 ) ;
F_31 ( V_3 , V_73 , V_75 ,
0xFF , ( V_26 >> 4 ) & 0x0F ) ;
F_31 ( V_3 , V_73 , V_76 , 0xFF , 0x00 ) ;
F_31 ( V_3 , V_73 , V_76 , 0xFF , 0x00 ) ;
F_31 ( V_3 , V_73 , V_76 , 0xFF , 0x01 ) ;
return F_32 ( V_3 , V_77 , 100 ) ;
}
int F_39 ( struct V_2 * V_3 , T_1 V_26 , T_2 V_45 , T_2 V_1 )
{
F_36 ( V_3 ) ;
F_31 ( V_3 , V_73 , V_26 , V_45 , V_1 ) ;
return F_32 ( V_3 , V_77 , 100 ) ;
}
int F_20 ( struct V_2 * V_3 , T_1 V_26 , T_2 * V_1 )
{
int V_15 ;
if ( V_1 != NULL )
* V_1 = 0 ;
F_36 ( V_3 ) ;
F_31 ( V_3 , V_66 , V_26 , 0 , 0 ) ;
V_15 = F_32 ( V_3 , V_69 , 100 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_34 ( V_3 , 1 , 100 ) ;
if ( V_15 )
return V_15 ;
if ( V_1 != NULL )
* V_1 = V_3 -> V_65 [ 0 ] ;
return 0 ;
}
static inline T_2 F_40 ( T_2 V_78 )
{
return ( V_78 > 1 ) ? ( V_78 - 1 ) : V_78 ;
}
static T_2 F_41 ( T_2 V_79 , T_2 div )
{
if ( div > V_80 ) {
if ( V_79 > div - 1 )
V_79 -= ( div - 1 ) ;
else
V_79 = V_81 ;
}
return V_79 ;
}
int F_42 ( struct V_2 * V_3 , unsigned int V_82 ,
T_2 V_79 , bool V_83 , bool V_84 , bool V_85 )
{
int V_15 ;
T_2 V_86 , V_87 , V_88 , div ;
if ( ! V_82 ) {
V_3 -> V_89 = 0 ;
return 0 ;
}
if ( V_83 ) {
V_87 = V_90 ;
V_82 = 30000000 ;
} else {
V_87 = V_91 ;
}
V_15 = F_39 ( V_3 , V_92 ,
V_93 , V_87 ) ;
if ( V_15 < 0 )
return V_15 ;
V_82 /= 1000000 ;
F_2 ( & V_3 -> V_4 -> V_5 ,
L_4 , V_82 ) ;
if ( ! V_83 && V_84 )
V_82 *= 2 ;
F_2 ( & V_3 -> V_4 -> V_5 ,
L_5 ,
V_82 , V_3 -> V_89 ) ;
if ( V_82 == V_3 -> V_89 )
return 0 ;
V_86 = V_82 - 2 ;
if ( ( V_82 <= 2 ) || ( V_86 > V_94 ) )
return - V_35 ;
V_88 = 60 / V_82 + 3 ;
if ( V_88 > 15 )
V_88 = 15 ;
div = V_80 ;
while ( V_86 < V_95 && div < V_96 ) {
V_86 = ( V_86 + 2 ) * 2 - 2 ;
div ++ ;
}
F_2 ( & V_3 -> V_4 -> V_5 , L_6 , V_86 , div ) ;
if ( V_84 )
V_79 = F_40 ( V_79 ) ;
V_79 = F_41 ( V_79 , div ) ;
F_2 ( & V_3 -> V_4 -> V_5 , L_7 , V_79 ) ;
F_36 ( V_3 ) ;
F_31 ( V_3 , V_73 , V_97 , V_98 , V_98 ) ;
F_31 ( V_3 , V_73 , V_97 ,
0x3F , ( div << 4 ) | V_88 ) ;
F_31 ( V_3 , V_73 , V_99 , V_100 , 0 ) ;
F_31 ( V_3 , V_73 , V_101 ,
V_102 , V_79 ) ;
F_31 ( V_3 , V_73 , V_103 , 0xFF , V_86 ) ;
F_31 ( V_3 , V_73 , V_99 , V_100 , V_100 ) ;
if ( V_85 ) {
F_31 ( V_3 , V_73 , V_104 ,
V_105 , 0 ) ;
F_31 ( V_3 , V_73 , V_104 ,
V_105 , V_105 ) ;
}
V_15 = F_32 ( V_3 , V_77 , 2000 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_39 ( V_3 , V_99 , 0xff ,
V_100 | V_106 | V_107 ) ;
if ( V_15 < 0 )
return V_15 ;
F_43 ( 100 , 1000 ) ;
V_15 = F_39 ( V_3 , V_97 , V_98 , 0 ) ;
if ( V_15 < 0 )
return V_15 ;
V_3 -> V_89 = V_82 ;
return 0 ;
}
int F_44 ( struct V_2 * V_3 , int V_108 )
{
int V_15 ;
T_1 V_72 ;
T_1 V_109 [] = {
[ V_110 ] = ( V_111 & ~ V_112 ) ,
[ V_113 ] = ( V_111 & ~ V_114 )
} ;
V_15 = F_37 ( V_3 , & V_72 ) ;
if ( V_15 )
return 0 ;
if ( V_72 & V_109 [ V_108 ] )
return - V_115 ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 )
{
int V_15 ;
T_2 V_72 ;
F_36 ( V_3 ) ;
if ( F_46 ( V_3 , V_116 ) ) {
F_31 ( V_3 , V_73 , V_117 ,
V_118 , V_119 ) ;
F_31 ( V_3 , V_73 , V_117 ,
V_120 , V_120 ) ;
F_31 ( V_3 , V_73 , V_121 ,
0x30 , 0x10 ) ;
F_31 ( V_3 , V_73 , V_122 ,
0x03 , 0x01 ) ;
F_31 ( V_3 , V_73 , V_123 ,
0x0C , 0x04 ) ;
}
F_31 ( V_3 , V_73 , V_124 , V_125 , V_126 ) ;
F_31 ( V_3 , V_73 , V_127 , 0xFF , 0x08 ) ;
F_31 ( V_3 , V_73 ,
V_128 , V_129 , 0x0 ) ;
F_31 ( V_3 , V_73 , V_130 ,
V_131 , V_132 ) ;
F_31 ( V_3 , V_73 ,
V_133 , V_134 , 0x0 ) ;
F_31 ( V_3 , V_73 , V_135 , 0xE0 , 0x0 ) ;
if ( V_3 -> V_136 )
F_31 ( V_3 , V_73 ,
V_122 , 0x03 , 0x01 ) ;
F_31 ( V_3 , V_73 , V_137 ,
V_138 , V_138 ) ;
F_31 ( V_3 , V_73 , V_139 ,
V_140 | V_141 | V_142 ,
V_140 | V_141 | V_142 ) ;
V_15 = F_32 ( V_3 , V_77 , 100 ) ;
if ( V_15 )
return V_15 ;
F_20 ( V_3 , V_143 , & V_72 ) ;
if ( ( V_72 & V_144 ) || ( ( V_72 & V_145 ) == V_146 ) ) {
V_15 = F_38 ( V_3 , 0xC2 , 0x7C ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_47 ( struct V_2 * V_3 )
{
int V_15 ;
T_2 V_72 ;
F_33 ( V_3 ) ;
V_15 = F_39 ( V_3 ,
V_147 , V_148 , V_149 ) ;
if ( V_15 )
return V_15 ;
F_43 ( 100 , 1000 ) ;
V_15 = F_39 ( V_3 , V_97 , V_98 , 0x00 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_20 ( V_3 , V_150 , & V_72 ) ;
if ( V_15 )
return V_15 ;
V_3 -> V_151 = V_72 & V_152 ;
V_15 = F_20 ( V_3 , V_153 , & V_72 ) ;
if ( V_15 )
return V_15 ;
if ( V_72 & V_154 ) {
V_3 -> V_155 = V_116 ;
F_2 ( & V_3 -> V_4 -> V_5 , L_8 ) ;
} else {
V_3 -> V_155 = V_156 ;
F_2 ( & V_3 -> V_4 -> V_5 , L_9 ) ;
}
F_20 ( V_3 , V_157 , & V_72 ) ;
if ( V_72 & V_158 ) {
V_3 -> V_136 = true ;
F_2 ( & V_3 -> V_4 -> V_5 , L_10 ) ;
} else {
V_3 -> V_136 = false ;
}
return F_45 ( V_3 ) ;
}
static int F_48 ( struct V_159 * V_160 ,
const struct V_161 * V_162 )
{
struct V_163 * V_164 = F_49 ( V_160 ) ;
struct V_2 * V_3 ;
int V_15 ;
F_2 ( & V_160 -> V_5 ,
L_11 ,
V_164 -> V_165 -> V_166 , V_164 -> V_167 ) ;
V_3 = F_50 ( & V_160 -> V_5 , sizeof( * V_3 ) , V_54 ) ;
if ( ! V_3 )
return - V_55 ;
V_3 -> V_16 = V_164 ;
V_3 -> V_168 = F_51 ( V_3 -> V_16 , V_36 ,
V_54 , & V_3 -> V_169 ) ;
if ( ! V_3 -> V_168 )
return - V_55 ;
F_52 ( V_160 , V_3 ) ;
V_3 -> V_170 = V_162 -> V_171 ;
V_3 -> V_172 = V_162 -> V_173 ;
V_3 -> V_28 = V_3 -> V_65 = V_3 -> V_168 ;
F_53 ( & V_3 -> V_174 ) ;
V_3 -> V_4 = V_160 ;
V_15 = F_47 ( V_3 ) ;
if ( V_15 )
goto V_175;
F_54 ( & V_3 -> V_18 , F_1 , ( unsigned long ) V_3 ) ;
V_15 = F_55 ( & V_160 -> V_5 , V_176 ,
F_56 ( V_176 ) ) ;
if ( V_15 )
goto V_175;
#ifdef F_57
V_160 -> V_177 = 1 ;
F_58 ( V_164 ) ;
#endif
return 0 ;
V_175:
F_59 ( V_3 -> V_16 , V_36 , V_3 -> V_168 ,
V_3 -> V_169 ) ;
return V_15 ;
}
static void F_60 ( struct V_159 * V_160 )
{
struct V_2 * V_3 = (struct V_2 * ) F_61 ( V_160 ) ;
F_2 ( & V_160 -> V_5 , L_12 , V_6 ) ;
F_62 ( & V_160 -> V_5 ) ;
F_52 ( V_3 -> V_4 , NULL ) ;
F_59 ( V_3 -> V_16 , V_36 , V_3 -> V_168 ,
V_3 -> V_169 ) ;
}
static int F_63 ( struct V_159 * V_160 , T_3 V_178 )
{
struct V_2 * V_3 =
(struct V_2 * ) F_61 ( V_160 ) ;
T_1 V_72 = 0 ;
F_2 ( & V_160 -> V_5 , L_13 ,
V_6 , V_178 . V_179 ) ;
if ( F_64 ( V_178 ) ) {
if ( F_65 ( & V_3 -> V_174 ) ) {
F_37 ( V_3 , & V_72 ) ;
F_66 ( & V_3 -> V_174 ) ;
if ( V_72 & ( V_112 | V_114 ) )
return - V_180 ;
} else {
return - V_180 ;
}
}
return 0 ;
}
static int F_67 ( struct V_159 * V_160 )
{
return 0 ;
}
static int F_68 ( struct V_159 * V_160 )
{
struct V_2 * V_3 =
(struct V_2 * ) F_61 ( V_160 ) ;
F_45 ( V_3 ) ;
return 0 ;
}
static int F_69 ( struct V_159 * V_160 )
{
struct V_2 * V_3 = (struct V_2 * ) F_61 ( V_160 ) ;
F_70 ( & V_3 -> V_174 ) ;
return 0 ;
}
static int F_71 ( struct V_159 * V_160 )
{
struct V_2 * V_3 = (struct V_2 * ) F_61 ( V_160 ) ;
F_66 ( & V_3 -> V_174 ) ;
return 0 ;
}
