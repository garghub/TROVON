static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( & V_3 -> V_4 -> V_5 , L_1 , V_6 ) ;
F_3 ( & V_3 -> V_7 ) ;
V_3 -> V_7 . V_8 = - V_9 ;
}
static int F_4 ( struct V_2 * V_3 ,
unsigned int V_10 , struct V_11 * V_12 , int V_13 ,
unsigned int V_14 , unsigned int * V_15 , int V_16 )
{
int V_17 ;
F_2 ( & V_3 -> V_4 -> V_5 , L_2 ,
V_6 , V_14 , V_13 ) ;
V_17 = F_5 ( & V_3 -> V_7 , V_3 -> V_18 , V_10 , 0 ,
V_12 , V_13 , V_14 , V_19 ) ;
if ( V_17 )
return V_17 ;
V_3 -> V_20 . V_21 = V_22 + F_6 ( V_16 ) ;
F_7 ( & V_3 -> V_20 ) ;
F_8 ( & V_3 -> V_7 ) ;
F_9 ( & V_3 -> V_20 ) ;
if ( V_15 )
* V_15 = V_3 -> V_7 . V_23 ;
return V_3 -> V_7 . V_8 ;
}
int F_10 ( struct V_2 * V_3 , unsigned int V_10 ,
void * V_24 , unsigned int V_25 , int V_13 ,
unsigned int * V_15 , int V_16 )
{
if ( V_16 < 600 )
V_16 = 600 ;
if ( V_13 )
return F_4 ( V_3 , V_10 ,
(struct V_11 * ) V_24 , V_13 , V_25 , V_15 ,
V_16 ) ;
else
return F_11 ( V_3 -> V_18 , V_10 , V_24 , V_25 , V_15 ,
V_16 ) ;
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
F_16 ( V_3 -> V_18 , V_37 ) ,
V_3 -> V_28 , V_33 , 0 , NULL , 100 ) ;
}
static int F_17 ( struct V_2 * V_3 ,
T_1 V_26 , T_1 V_25 , T_2 * V_1 )
{
int V_38 , V_17 ;
T_1 V_39 = F_18 ( V_25 , 4 ) ;
T_1 V_40 = V_25 - V_39 ;
if ( ! V_1 )
return - V_35 ;
if ( V_39 ) {
F_12 ( V_3 , V_26 , V_25 , V_41 ) ;
V_17 = F_10 ( V_3 ,
F_16 ( V_3 -> V_18 , V_37 ) ,
V_3 -> V_28 , 12 , 0 , NULL , 100 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_10 ( V_3 ,
F_19 ( V_3 -> V_18 , V_42 ) ,
V_1 , V_39 , 0 , NULL , 100 ) ;
if ( V_17 )
return V_17 ;
}
for ( V_38 = 0 ; V_38 < V_40 ; V_38 ++ ) {
V_17 = F_20 ( V_3 , V_26 + V_39 + V_38 ,
V_1 + V_39 + V_38 ) ;
if ( V_17 )
return V_17 ;
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
return F_25 ( V_3 -> V_18 ,
F_26 ( V_3 -> V_18 , 0 ) , V_50 ,
V_51 | V_52 | V_53 ,
V_46 , V_47 , NULL , 0 , 100 ) ;
}
int F_27 ( struct V_2 * V_3 , T_1 V_26 , T_2 * V_1 )
{
T_1 V_46 ;
if ( ! V_1 )
return - V_35 ;
* V_1 = 0 ;
V_26 |= V_54 << V_49 ;
V_46 = F_24 ( V_26 ) ;
return F_25 ( V_3 -> V_18 ,
F_28 ( V_3 -> V_18 , 0 ) , V_50 ,
V_55 | V_52 | V_53 ,
V_46 , 0 , V_1 , 1 , 100 ) ;
}
void F_29 ( struct V_2 * V_3 , T_2 V_56 , T_1 V_57 ,
T_2 V_45 , T_2 V_1 )
{
int V_38 ;
if ( V_3 -> V_58 < ( V_36 - V_59 ) / 4 ) {
V_38 = V_59 + V_3 -> V_58 * 4 ;
V_3 -> V_28 [ V_38 ++ ] = ( ( V_56 & 0x03 ) << 6 ) |
( T_2 ) ( ( V_57 >> 8 ) & 0x3F ) ;
V_3 -> V_28 [ V_38 ++ ] = ( T_2 ) V_57 ;
V_3 -> V_28 [ V_38 ++ ] = V_45 ;
V_3 -> V_28 [ V_38 ++ ] = V_1 ;
V_3 -> V_58 ++ ;
}
}
int F_30 ( struct V_2 * V_3 , T_2 V_60 , int V_16 )
{
int V_17 ;
V_3 -> V_28 [ V_61 ] = ( T_2 ) ( V_3 -> V_58 >> 8 ) ;
V_3 -> V_28 [ V_62 ] = ( T_2 ) ( V_3 -> V_58 ) ;
V_3 -> V_28 [ V_31 ] = V_60 ;
V_17 = F_10 ( V_3 ,
F_16 ( V_3 -> V_18 , V_37 ) ,
V_3 -> V_28 , V_3 -> V_58 * 4 + V_59 ,
0 , NULL , V_16 ) ;
if ( V_17 ) {
F_31 ( V_3 ) ;
return V_17 ;
}
return 0 ;
}
int F_32 ( struct V_2 * V_3 , int V_39 , int V_16 )
{
if ( V_39 <= 0 )
return - V_35 ;
V_39 = F_15 ( V_39 , 4 ) ;
return F_10 ( V_3 ,
F_19 ( V_3 -> V_18 , V_42 ) ,
V_3 -> V_63 , V_39 , 0 , NULL , V_16 ) ;
}
static int F_33 ( struct V_2 * V_3 , T_1 * V_8 )
{
int V_17 ;
F_34 ( V_3 ) ;
F_29 ( V_3 , V_64 , V_65 , 0x00 , 0x00 ) ;
F_29 ( V_3 , V_64 , V_66 , 0x00 , 0x00 ) ;
V_17 = F_30 ( V_3 , V_67 , 100 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_32 ( V_3 , 2 , 100 ) ;
if ( V_17 )
return V_17 ;
* V_8 = ( ( V_3 -> V_63 [ 0 ] >> 2 ) & 0x0f ) |
( ( V_3 -> V_63 [ 1 ] & 0x03 ) << 4 ) ;
return 0 ;
}
int F_35 ( struct V_2 * V_3 , T_1 * V_8 )
{
int V_17 ;
if ( ! V_8 )
return - V_35 ;
if ( V_68 == 0 )
V_17 = F_25 ( V_3 -> V_18 ,
F_28 ( V_3 -> V_18 , 0 ) ,
V_69 ,
V_55 | V_52 | V_53 ,
0 , 0 , V_8 , 2 , 100 ) ;
else
V_17 = F_33 ( V_3 , V_8 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , T_2 V_26 , T_2 V_70 )
{
F_2 ( & V_3 -> V_4 -> V_5 , L_3 ,
V_70 , V_26 ) ;
F_34 ( V_3 ) ;
F_29 ( V_3 , V_71 , V_72 , 0xFF , V_70 ) ;
F_29 ( V_3 , V_71 , V_73 , 0xFF , V_26 & 0x0F ) ;
F_29 ( V_3 , V_71 , V_74 , 0xFF , 0x00 ) ;
F_29 ( V_3 , V_71 , V_74 , 0xFF , 0x00 ) ;
F_29 ( V_3 , V_71 , V_74 , 0xFF , 0x01 ) ;
F_29 ( V_3 , V_71 , V_73 ,
0xFF , ( V_26 >> 4 ) & 0x0F ) ;
F_29 ( V_3 , V_71 , V_74 , 0xFF , 0x00 ) ;
F_29 ( V_3 , V_71 , V_74 , 0xFF , 0x00 ) ;
F_29 ( V_3 , V_71 , V_74 , 0xFF , 0x01 ) ;
return F_30 ( V_3 , V_75 , 100 ) ;
}
int F_37 ( struct V_2 * V_3 , T_1 V_26 , T_2 V_45 , T_2 V_1 )
{
F_34 ( V_3 ) ;
F_29 ( V_3 , V_71 , V_26 , V_45 , V_1 ) ;
return F_30 ( V_3 , V_75 , 100 ) ;
}
int F_20 ( struct V_2 * V_3 , T_1 V_26 , T_2 * V_1 )
{
int V_17 ;
if ( V_1 != NULL )
* V_1 = 0 ;
F_34 ( V_3 ) ;
F_29 ( V_3 , V_64 , V_26 , 0 , 0 ) ;
V_17 = F_30 ( V_3 , V_67 , 100 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_32 ( V_3 , 1 , 100 ) ;
if ( V_17 )
return V_17 ;
if ( V_1 != NULL )
* V_1 = V_3 -> V_63 [ 0 ] ;
return 0 ;
}
static inline T_2 F_38 ( T_2 V_76 )
{
return ( V_76 > 1 ) ? ( V_76 - 1 ) : V_76 ;
}
static T_2 F_39 ( T_2 V_77 , T_2 div )
{
if ( div > V_78 ) {
if ( V_77 > div - 1 )
V_77 -= ( div - 1 ) ;
else
V_77 = V_79 ;
}
return V_77 ;
}
int F_40 ( struct V_2 * V_3 , unsigned int V_80 ,
T_2 V_77 , bool V_81 , bool V_82 , bool V_83 )
{
int V_17 ;
T_2 V_84 , V_85 , V_86 , div ;
if ( ! V_80 ) {
V_3 -> V_87 = 0 ;
return 0 ;
}
if ( V_81 ) {
V_85 = V_88 ;
V_80 = 30000000 ;
} else {
V_85 = V_89 ;
}
V_17 = F_37 ( V_3 , V_90 ,
V_91 , V_85 ) ;
if ( V_17 < 0 )
return V_17 ;
V_80 /= 1000000 ;
F_2 ( & V_3 -> V_4 -> V_5 ,
L_4 , V_80 ) ;
if ( ! V_81 && V_82 )
V_80 *= 2 ;
F_2 ( & V_3 -> V_4 -> V_5 ,
L_5 ,
V_80 , V_3 -> V_87 ) ;
if ( V_80 == V_3 -> V_87 )
return 0 ;
V_84 = V_80 - 2 ;
if ( ( V_80 <= 2 ) || ( V_84 > V_92 ) )
return - V_35 ;
V_86 = 60 / V_80 + 3 ;
if ( V_86 > 15 )
V_86 = 15 ;
div = V_78 ;
while ( V_84 < V_93 && div < V_94 ) {
V_84 = ( V_84 + 2 ) * 2 - 2 ;
div ++ ;
}
F_2 ( & V_3 -> V_4 -> V_5 , L_6 , V_84 , div ) ;
if ( V_82 )
V_77 = F_38 ( V_77 ) ;
V_77 = F_39 ( V_77 , div ) ;
F_2 ( & V_3 -> V_4 -> V_5 , L_7 , V_77 ) ;
F_34 ( V_3 ) ;
F_29 ( V_3 , V_71 , V_95 , V_96 , V_96 ) ;
F_29 ( V_3 , V_71 , V_95 ,
0x3F , ( div << 4 ) | V_86 ) ;
F_29 ( V_3 , V_71 , V_97 , V_98 , 0 ) ;
F_29 ( V_3 , V_71 , V_99 ,
V_100 , V_77 ) ;
F_29 ( V_3 , V_71 , V_101 , 0xFF , V_84 ) ;
F_29 ( V_3 , V_71 , V_97 , V_98 , V_98 ) ;
if ( V_83 ) {
F_29 ( V_3 , V_71 , V_102 ,
V_103 , 0 ) ;
F_29 ( V_3 , V_71 , V_102 ,
V_103 , V_103 ) ;
}
V_17 = F_30 ( V_3 , V_75 , 2000 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_37 ( V_3 , V_97 , 0xff ,
V_98 | V_104 | V_105 ) ;
if ( V_17 < 0 )
return V_17 ;
F_41 ( 100 , 1000 ) ;
V_17 = F_37 ( V_3 , V_95 , V_96 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_3 -> V_87 = V_80 ;
return 0 ;
}
int F_42 ( struct V_2 * V_3 , int V_106 )
{
int V_17 ;
T_1 V_70 ;
T_1 V_107 [] = {
[ V_108 ] = ( V_109 & ~ V_110 ) ,
[ V_111 ] = ( V_109 & ~ V_112 )
} ;
V_17 = F_35 ( V_3 , & V_70 ) ;
if ( V_17 )
return 0 ;
if ( V_70 & V_107 [ V_106 ] )
return - V_113 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 )
{
int V_17 ;
T_2 V_70 ;
F_34 ( V_3 ) ;
if ( F_44 ( V_3 , V_114 ) ) {
F_29 ( V_3 , V_71 , V_115 ,
V_116 , V_117 ) ;
F_29 ( V_3 , V_71 , V_115 ,
V_118 , V_118 ) ;
F_29 ( V_3 , V_71 , V_119 ,
0x30 , 0x10 ) ;
F_29 ( V_3 , V_71 , V_120 ,
0x03 , 0x01 ) ;
F_29 ( V_3 , V_71 , V_121 ,
0x0C , 0x04 ) ;
}
F_29 ( V_3 , V_71 , V_122 , V_123 , V_124 ) ;
F_29 ( V_3 , V_71 , V_125 , 0xFF , 0x08 ) ;
F_29 ( V_3 , V_71 ,
V_126 , V_127 , 0x0 ) ;
F_29 ( V_3 , V_71 , V_128 ,
V_129 , V_130 ) ;
F_29 ( V_3 , V_71 ,
V_131 , V_132 , 0x0 ) ;
F_29 ( V_3 , V_71 , V_133 , 0xE0 , 0x0 ) ;
if ( V_3 -> V_134 )
F_29 ( V_3 , V_71 ,
V_120 , 0x03 , 0x01 ) ;
F_29 ( V_3 , V_71 , V_135 ,
V_136 , V_136 ) ;
F_29 ( V_3 , V_71 , V_137 ,
V_138 | V_139 | V_140 ,
V_138 | V_139 | V_140 ) ;
V_17 = F_30 ( V_3 , V_75 , 100 ) ;
if ( V_17 )
return V_17 ;
F_20 ( V_3 , V_141 , & V_70 ) ;
if ( ( V_70 & V_142 ) || ( ( V_70 & V_143 ) == V_144 ) ) {
V_17 = F_36 ( V_3 , 0xC2 , 0x7C ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_45 ( struct V_2 * V_3 )
{
int V_17 ;
T_2 V_70 ;
F_31 ( V_3 ) ;
V_17 = F_37 ( V_3 ,
V_145 , V_146 , V_147 ) ;
if ( V_17 )
return V_17 ;
F_41 ( 100 , 1000 ) ;
V_17 = F_37 ( V_3 , V_95 , V_96 , 0x00 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_20 ( V_3 , V_148 , & V_70 ) ;
if ( V_17 )
return V_17 ;
V_3 -> V_149 = V_70 & V_150 ;
V_17 = F_20 ( V_3 , V_151 , & V_70 ) ;
if ( V_17 )
return V_17 ;
if ( V_70 & V_152 ) {
V_3 -> V_153 = V_114 ;
F_2 ( & V_3 -> V_4 -> V_5 , L_8 ) ;
} else {
V_3 -> V_153 = V_154 ;
F_2 ( & V_3 -> V_4 -> V_5 , L_9 ) ;
}
F_20 ( V_3 , V_155 , & V_70 ) ;
if ( V_70 & V_156 ) {
V_3 -> V_134 = true ;
F_2 ( & V_3 -> V_4 -> V_5 , L_10 ) ;
} else {
V_3 -> V_134 = false ;
}
return F_43 ( V_3 ) ;
}
static int F_46 ( struct V_157 * V_158 ,
const struct V_159 * V_160 )
{
struct V_161 * V_162 = F_47 ( V_158 ) ;
struct V_2 * V_3 ;
int V_17 ;
F_2 ( & V_158 -> V_5 ,
L_11 ,
V_162 -> V_163 -> V_164 , V_162 -> V_165 ) ;
V_3 = F_48 ( & V_158 -> V_5 , sizeof( * V_3 ) , V_166 ) ;
if ( ! V_3 )
return - V_167 ;
V_3 -> V_18 = V_162 ;
V_3 -> V_168 = F_49 ( V_3 -> V_18 , V_36 ,
V_166 , & V_3 -> V_169 ) ;
if ( ! V_3 -> V_168 )
return - V_167 ;
F_50 ( V_158 , V_3 ) ;
V_3 -> V_170 = V_160 -> V_171 ;
V_3 -> V_172 = V_160 -> V_173 ;
V_3 -> V_28 = V_3 -> V_63 = V_3 -> V_168 ;
F_51 ( & V_3 -> V_174 ) ;
V_3 -> V_4 = V_158 ;
V_17 = F_45 ( V_3 ) ;
if ( V_17 )
goto V_175;
F_52 ( & V_3 -> V_20 , F_1 , ( unsigned long ) V_3 ) ;
V_17 = F_53 ( & V_158 -> V_5 , V_162 -> V_165 , V_176 ,
F_54 ( V_176 ) , NULL , 0 , NULL ) ;
if ( V_17 )
goto V_175;
#ifdef F_55
V_158 -> V_177 = 1 ;
F_56 ( V_162 ) ;
#endif
return 0 ;
V_175:
F_57 ( V_3 -> V_18 , V_36 , V_3 -> V_168 ,
V_3 -> V_169 ) ;
return V_17 ;
}
static void F_58 ( struct V_157 * V_158 )
{
struct V_2 * V_3 = (struct V_2 * ) F_59 ( V_158 ) ;
F_2 ( & V_158 -> V_5 , L_12 , V_6 ) ;
F_60 ( & V_158 -> V_5 ) ;
F_50 ( V_3 -> V_4 , NULL ) ;
F_57 ( V_3 -> V_18 , V_36 , V_3 -> V_168 ,
V_3 -> V_169 ) ;
}
static int F_61 ( struct V_157 * V_158 , T_3 V_178 )
{
struct V_2 * V_3 =
(struct V_2 * ) F_59 ( V_158 ) ;
F_2 ( & V_158 -> V_5 , L_13 ,
V_6 , V_178 . V_179 ) ;
F_62 ( & V_3 -> V_174 ) ;
F_63 ( V_3 ) ;
F_64 ( & V_3 -> V_174 ) ;
return 0 ;
}
static int F_65 ( struct V_157 * V_158 )
{
return 0 ;
}
static int F_66 ( struct V_157 * V_158 )
{
struct V_2 * V_3 =
(struct V_2 * ) F_59 ( V_158 ) ;
F_43 ( V_3 ) ;
return 0 ;
}
static int F_67 ( struct V_157 * V_158 )
{
struct V_2 * V_3 = (struct V_2 * ) F_59 ( V_158 ) ;
F_62 ( & V_3 -> V_174 ) ;
return 0 ;
}
static int F_68 ( struct V_157 * V_158 )
{
struct V_2 * V_3 = (struct V_2 * ) F_59 ( V_158 ) ;
F_64 ( & V_3 -> V_174 ) ;
return 0 ;
}
