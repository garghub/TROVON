static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_3 >= V_7 -> V_8 . V_9 )
return - V_10 ;
V_5 -> V_11 = ( V_3 * 16 ) + 2 ;
V_5 -> V_12 = 3 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_3 >= V_7 -> V_8 . V_9 )
return - V_10 ;
V_5 -> V_11 = ( V_3 * 16 ) + 8 ;
if ( V_3 < V_7 -> V_8 . V_9 - 1 )
V_5 -> V_12 = 8 ;
else
V_5 -> V_12 = V_2 -> V_13 - V_5 -> V_11 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_3 >= V_7 -> V_8 . V_9 )
return - V_10 ;
V_5 -> V_12 = V_7 -> V_8 . V_14 ;
if ( ! V_3 && V_2 -> V_15 <= 512 )
V_5 -> V_11 = 0 ;
else
V_5 -> V_11 = ( V_3 * 16 ) + 2 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_3 >= V_7 -> V_8 . V_9 )
return - V_10 ;
V_5 -> V_11 = ( V_3 * 16 ) + 15 ;
if ( V_3 < V_7 -> V_8 . V_9 - 1 )
V_5 -> V_12 = 3 ;
else
V_5 -> V_12 = V_2 -> V_13 - V_5 -> V_11 ;
return 0 ;
}
static inline struct V_16 * F_6 ( struct V_1 * V_2 )
{
return F_7 ( F_2 ( V_2 ) , struct V_16 , V_17 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_18 , unsigned int V_19 )
{
struct V_6 * V_20 = F_2 ( V_2 ) ;
struct V_16 * V_21 = F_6 ( V_2 ) ;
void T_1 * V_22 = V_21 -> V_23 ;
unsigned int V_24 = V_21 -> V_24 ;
if ( V_19 & V_25 ) {
T_2 V_26 ;
if ( V_19 & V_27 ) {
V_20 -> V_28 = V_21 -> V_29 ;
V_20 -> V_30 = V_21 -> V_29 ;
} else if ( V_19 & V_31 ) {
V_20 -> V_28 = V_21 -> V_32 ;
V_20 -> V_30 = V_21 -> V_32 ;
} else {
V_20 -> V_28 = V_21 -> V_33 ;
V_20 -> V_30 = V_21 -> V_33 ;
}
V_26 = F_9 ( F_10 ( V_22 , V_24 , V_34 ) ) ;
if ( V_19 & V_35 )
V_26 |= V_36 ;
else
V_26 &= ~ V_36 ;
F_11 ( V_26 , F_10 ( V_22 , V_24 , V_34 ) ) ;
}
F_12 () ;
if ( V_18 != V_37 )
F_13 ( V_18 , V_20 -> V_30 ) ;
}
static void F_14 ( struct V_16 * V_21 ,
struct V_38 * V_39 )
{
T_3 V_40 = V_41 | V_36 | V_42 ;
T_3 V_43 , V_44 , V_45 , V_46 , V_47 , V_48 ;
unsigned int V_24 = V_21 -> V_24 ;
void T_1 * V_22 = V_21 -> V_23 ;
V_43 = ( V_39 -> V_43 & V_49 ) << V_50 ;
V_44 = ( V_39 -> V_44 & V_51 ) << V_52 ;
V_45 = ( V_39 -> V_45 & V_53 ) << V_54 ;
V_46 = ( V_39 -> V_46 & V_55 ) << V_56 ;
V_47 = ( V_39 -> V_47 & V_57 ) << V_58 ;
V_48 = ( V_39 -> V_48 & V_59 ) << V_60 ;
if ( V_21 -> V_17 . V_61 & V_62 )
F_11 ( V_40 | V_63 ,
F_10 ( V_22 , V_24 , V_34 ) ) ;
else
F_11 ( V_40 | V_64 ,
F_10 ( V_22 , V_24 , V_34 ) ) ;
F_11 ( F_9 ( F_10 ( V_22 , V_24 , V_34 ) ) | V_43 | V_44 ,
F_10 ( V_22 , V_24 , V_34 ) ) ;
F_11 ( V_45 | V_46 | V_47 | V_48 ,
F_10 ( V_22 , V_24 , V_65 ) ) ;
F_11 ( V_45 | V_46 | V_47 | V_48 ,
F_10 ( V_22 , V_24 , V_66 ) ) ;
}
static int F_15 ( struct V_16 * V_21 ,
const struct V_67 * V_68 ,
struct V_38 * V_39 )
{
unsigned long V_69 = F_16 ( V_21 -> V_70 ) ;
unsigned long V_71 = V_72 / V_69 ;
T_3 V_45 , V_46 , V_47 , V_48 ;
if ( V_68 -> V_73 < 30000 )
return - V_74 ;
V_39 -> V_44 = F_17 ( V_68 -> V_75 / 1000 , V_71 ) - 1 ;
if ( V_39 -> V_44 > V_51 )
V_39 -> V_44 = V_51 ;
V_39 -> V_43 = F_17 ( V_68 -> V_76 / 1000 , V_71 ) - 1 ;
if ( V_39 -> V_43 > V_49 )
V_39 -> V_43 = V_49 ;
V_45 = V_68 -> V_77 - V_68 -> V_78 ;
V_39 -> V_45 = F_17 ( V_45 / 1000 , V_71 ) ;
V_46 = V_68 -> V_79 ;
if ( V_46 < V_68 -> V_80 )
V_46 = V_68 -> V_80 ;
if ( V_46 < V_68 -> V_81 )
V_46 = V_68 -> V_81 ;
if ( V_46 < V_68 -> V_82 )
V_46 = V_68 -> V_82 ;
if ( V_46 < V_68 -> V_83 )
V_46 = V_68 -> V_83 ;
if ( V_46 < V_68 -> V_84 )
V_46 = V_68 -> V_84 ;
V_39 -> V_46 = F_17 ( V_46 / 1000 , V_71 ) ;
if ( V_39 -> V_46 == 0 )
V_39 -> V_46 = 1 ;
else if ( V_39 -> V_46 > V_55 )
V_39 -> V_46 = V_55 ;
V_47 = F_18 ( V_68 -> V_85 , V_68 -> V_78 ) ;
V_39 -> V_47 = F_17 ( V_47 / 1000 , V_71 ) - 1 ;
if ( V_39 -> V_47 == 0 )
V_39 -> V_47 = 1 ;
else if ( V_39 -> V_47 > V_57 )
V_39 -> V_47 = V_57 ;
V_48 = F_18 ( V_68 -> V_77 - V_68 -> V_78 ,
V_68 -> V_86 - V_68 -> V_87 ) ;
V_39 -> V_48 = F_17 ( V_48 / 1000 , V_71 ) - 1 ;
if ( V_39 -> V_48 == 0 )
V_39 -> V_48 = 1 ;
else if ( V_39 -> V_48 > V_59 )
V_39 -> V_48 = V_59 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_88 ,
const struct V_89 * V_90 )
{
struct V_6 * V_17 = F_2 ( V_2 ) ;
struct V_16 * V_21 = F_20 ( V_17 ) ;
struct V_38 V_39 ;
const struct V_67 * V_68 ;
int V_91 ;
V_68 = F_21 ( V_90 ) ;
if ( F_22 ( V_68 ) )
return F_23 ( V_68 ) ;
V_91 = F_15 ( V_21 , V_68 , & V_39 ) ;
if ( V_91 )
return V_91 ;
if ( V_88 == V_92 )
return 0 ;
F_14 ( V_21 , & V_39 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , int V_93 )
{
struct V_16 * V_21 = F_6 ( V_2 ) ;
void T_1 * V_22 = V_21 -> V_23 ;
T_3 V_24 = V_21 -> V_24 ;
F_11 ( F_9 ( F_10 ( V_22 , V_24 , V_34 ) ) & ~ V_94 ,
F_10 ( V_22 , V_24 , V_34 ) ) ;
F_11 ( F_9 ( F_10 ( V_22 , V_24 , V_34 ) ) & ~ V_95 ,
F_10 ( V_22 , V_24 , V_34 ) ) ;
F_11 ( F_9 ( F_10 ( V_22 , V_24 , V_34 ) ) | V_95 ,
F_10 ( V_22 , V_24 , V_34 ) ) ;
}
static int F_25 ( struct V_1 * V_2 , const T_4 * V_96 ,
T_4 * V_8 )
{
struct V_16 * V_21 = F_6 ( V_2 ) ;
void T_1 * V_22 = V_21 -> V_23 ;
T_3 V_24 = V_21 -> V_24 ;
T_3 V_97 ;
unsigned long V_98 = V_99 + V_100 ;
do {
if ( F_26 ( F_10 ( V_22 , V_24 , V_101 ) ) & V_102 )
break;
else
F_27 () ;
} while ( ! F_28 ( V_99 , V_98 ) );
if ( F_28 ( V_99 , V_98 ) ) {
F_29 ( V_21 -> V_103 , L_1 ) ;
return - V_104 ;
}
V_97 = F_26 ( F_10 ( V_22 , V_24 , V_105 ) ) ;
V_8 [ 0 ] = ( T_4 ) ( V_97 >> 0 ) ;
V_8 [ 1 ] = ( T_4 ) ( V_97 >> 8 ) ;
V_8 [ 2 ] = ( T_4 ) ( V_97 >> 16 ) ;
V_8 [ 3 ] = ( T_4 ) ( V_97 >> 24 ) ;
V_97 = F_26 ( F_10 ( V_22 , V_24 , V_106 ) ) ;
V_8 [ 4 ] = ( T_4 ) ( V_97 >> 0 ) ;
V_8 [ 5 ] = ( T_4 ) ( V_97 >> 8 ) ;
V_8 [ 6 ] = ( T_4 ) ( V_97 >> 16 ) ;
V_8 [ 7 ] = ( T_4 ) ( V_97 >> 24 ) ;
V_97 = F_26 ( F_10 ( V_22 , V_24 , V_107 ) ) ;
V_8 [ 8 ] = ( T_4 ) ( V_97 >> 0 ) ;
V_8 [ 9 ] = ( T_4 ) ( V_97 >> 8 ) ;
V_8 [ 10 ] = ( T_4 ) ( V_97 >> 16 ) ;
V_8 [ 11 ] = ( T_4 ) ( V_97 >> 24 ) ;
V_97 = F_26 ( F_10 ( V_22 , V_24 , V_101 ) ) ;
V_8 [ 12 ] = ( T_4 ) ( V_97 >> 16 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , const T_4 * V_96 ,
T_4 * V_8 )
{
struct V_16 * V_21 = F_6 ( V_2 ) ;
void T_1 * V_22 = V_21 -> V_23 ;
T_3 V_24 = V_21 -> V_24 ;
T_3 V_97 ;
V_97 = F_26 ( F_10 ( V_22 , V_24 , V_105 ) ) ;
V_8 [ 0 ] = ( T_4 ) ( V_97 >> 0 ) ;
V_8 [ 1 ] = ( T_4 ) ( V_97 >> 8 ) ;
V_8 [ 2 ] = ( T_4 ) ( V_97 >> 16 ) ;
return 0 ;
}
static int F_31 ( T_4 * V_108 , int V_109 , int V_110 )
{
int V_111 , V_112 = 0 ;
for ( V_111 = 0 ; V_111 < V_109 ; V_111 ++ ) {
V_112 += F_32 ( ~ V_108 [ V_111 ] ) ;
if ( V_112 > V_110 )
break;
}
return V_112 ;
}
static void F_33 ( void * V_113 )
{
struct V_16 * V_21 = V_113 ;
F_34 ( & V_21 -> V_114 ) ;
}
static int F_35 ( struct V_16 * V_21 , void * V_115 , int V_116 ,
enum V_117 V_118 )
{
struct V_119 * V_120 ;
struct V_121 * V_122 ;
struct V_123 * V_124 ;
T_5 V_125 , V_126 , V_127 ;
T_6 V_128 ;
unsigned long V_129 = V_130 | V_131 ;
int V_91 ;
unsigned long V_132 ;
if ( V_118 == V_133 )
V_120 = V_21 -> V_134 ;
else if ( V_118 == V_135 )
V_120 = V_21 -> V_136 ;
else
return - V_137 ;
V_122 = V_120 -> V_138 ;
V_127 = F_36 ( V_122 -> V_103 , V_115 , V_116 , V_118 ) ;
if ( V_118 == V_133 ) {
V_126 = V_127 ;
V_125 = V_21 -> V_139 ;
} else {
V_126 = V_21 -> V_139 ;
V_125 = V_127 ;
}
V_124 = V_122 -> V_140 ( V_120 , V_125 , V_126 ,
V_116 , V_129 ) ;
if ( ! V_124 ) {
F_29 ( V_21 -> V_103 , L_2 ) ;
V_91 = - V_141 ;
goto V_142;
}
V_124 -> V_143 = F_33 ;
V_124 -> V_144 = V_21 ;
V_128 = V_124 -> V_145 ( V_124 ) ;
V_91 = F_37 ( V_128 ) ;
if ( V_91 ) {
F_29 ( V_21 -> V_103 , L_3 , V_128 ) ;
goto V_142;
}
F_38 ( V_120 ) ;
V_132 =
F_39 ( & V_21 -> V_114 ,
F_40 ( 3000 ) ) ;
if ( V_132 == 0 ) {
F_41 ( V_120 ) ;
F_29 ( V_21 -> V_103 , L_4 ) ;
V_91 = - V_104 ;
goto V_142;
}
V_91 = 0 ;
V_142:
F_42 ( V_122 -> V_103 , V_127 , V_116 , V_118 ) ;
return V_91 ;
}
static void F_43 ( struct V_1 * V_2 , const T_4 * V_146 , int V_116 )
{
int V_147 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( F_44 ( ( T_3 ) V_146 , sizeof( T_3 ) ) &&
F_44 ( V_116 , sizeof( T_3 ) ) ) {
T_3 * V_148 = ( T_3 * ) V_146 ;
V_116 = V_116 >> 2 ;
for ( V_147 = 0 ; V_147 < V_116 ; V_147 ++ )
F_11 ( V_148 [ V_147 ] , V_7 -> V_30 ) ;
} else {
for ( V_147 = 0 ; V_147 < V_116 ; V_147 ++ )
F_13 ( V_146 [ V_147 ] , V_7 -> V_30 ) ;
}
}
static void F_45 ( struct V_1 * V_2 , T_4 * V_146 , int V_116 )
{
int V_147 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( F_44 ( ( T_3 ) V_146 , sizeof( T_3 ) ) &&
F_44 ( V_116 , sizeof( T_3 ) ) ) {
T_3 * V_148 = ( T_3 * ) V_146 ;
V_116 = V_116 >> 2 ;
for ( V_147 = 0 ; V_147 < V_116 ; V_147 ++ )
V_148 [ V_147 ] = F_26 ( V_7 -> V_28 ) ;
} else {
for ( V_147 = 0 ; V_147 < V_116 ; V_147 ++ )
V_146 [ V_147 ] = F_46 ( V_7 -> V_28 ) ;
}
}
static void F_47 ( struct V_1 * V_2 , T_4 * V_146 , int V_116 )
{
struct V_16 * V_21 = F_6 ( V_2 ) ;
F_35 ( V_21 , V_146 , V_116 , V_135 ) ;
}
static void F_48 ( struct V_1 * V_2 , const T_4 * V_146 ,
int V_116 )
{
struct V_16 * V_21 = F_6 ( V_2 ) ;
F_35 ( V_21 , ( void * ) V_146 , V_116 , V_133 ) ;
}
static int F_49 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_4 * V_146 , int V_149 , int V_150 )
{
int V_147 , V_151 , V_152 , V_153 , V_154 = V_7 -> V_8 . V_109 ;
int V_155 = V_7 -> V_8 . V_14 ;
int V_156 = V_7 -> V_8 . V_9 ;
T_4 * V_148 = V_146 ;
T_4 * V_157 = V_7 -> V_158 -> V_159 ;
T_4 * V_160 = V_7 -> V_158 -> V_161 ;
int V_162 , V_116 , V_163 = 0 ;
T_7 V_164 [ 7 ] ;
T_4 * V_165 = ( T_4 * ) & V_164 [ 0 ] ;
unsigned int V_166 = 0 ;
for ( V_147 = 0 , V_152 = 0 ; V_152 < V_156 ; V_152 ++ , V_147 += V_155 , V_148 += V_154 ) {
V_7 -> V_167 ( V_2 , V_168 , V_152 * V_154 , V_150 ) ;
V_7 -> V_8 . V_169 ( V_2 , V_170 ) ;
V_7 -> V_171 ( V_2 , V_148 , V_154 ) ;
for ( V_151 = 0 ; V_151 < V_155 ; ) {
struct V_4 V_5 ;
int V_91 ;
V_91 = F_50 ( V_2 , V_163 ++ , & V_5 ) ;
if ( V_91 )
return V_91 ;
V_162 = V_5 . V_11 ;
V_116 = V_5 . V_12 ;
if ( V_7 -> V_61 & V_62 )
V_116 = F_51 ( V_116 , 2 ) ;
V_7 -> V_167 ( V_2 , V_172 , V_162 , V_150 ) ;
V_7 -> V_171 ( V_2 , V_165 + V_151 , V_116 ) ;
V_151 += V_116 ;
}
memcpy ( & V_160 [ V_147 ] , V_165 , V_7 -> V_8 . V_14 ) ;
V_7 -> V_8 . V_173 ( V_2 , V_148 , & V_157 [ V_147 ] ) ;
V_153 = V_7 -> V_8 . V_174 ( V_2 , V_148 , & V_160 [ V_147 ] , & V_157 [ V_147 ] ) ;
if ( V_153 < 0 ) {
V_2 -> V_175 . V_176 ++ ;
} else {
V_2 -> V_175 . V_177 += V_153 ;
V_166 = F_52 (unsigned int, max_bitflips, stat) ;
}
}
return V_166 ;
}
static int F_53 ( struct V_1 * V_2 , T_4 * V_178 ,
T_4 * V_179 , T_4 * V_180 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_16 * V_21 = F_6 ( V_2 ) ;
void T_1 * V_22 = V_21 -> V_23 ;
unsigned int V_24 = V_21 -> V_24 ;
T_3 V_181 [ 8 ] ;
T_3 V_182 , V_147 ;
T_3 V_183 , V_184 , V_185 , V_186 ;
V_182 = ( F_26 ( F_10 ( V_22 , V_24 , V_101 ) ) >> 10 ) & 0xF ;
if ( F_54 ( V_182 == 0 ) )
return 0 ;
if ( F_55 ( V_182 > 8 ) ) {
int V_187 = F_31 ( V_179 , V_7 -> V_8 . V_14 , 8 ) ;
int V_188 = F_31 ( V_178 , V_7 -> V_8 . V_109 , 8 ) ;
if ( ( V_187 + V_188 ) <= 8 ) {
if ( V_188 )
memset ( V_178 , 0xff , V_7 -> V_8 . V_109 ) ;
return V_188 ;
}
return - V_189 ;
}
V_183 = F_26 ( F_10 ( V_22 , V_24 , V_105 ) ) ;
V_184 = F_26 ( F_10 ( V_22 , V_24 , V_106 ) ) ;
V_185 = F_26 ( F_10 ( V_22 , V_24 , V_107 ) ) ;
V_186 = F_26 ( F_10 ( V_22 , V_24 , V_101 ) ) ;
V_181 [ 0 ] = ( V_183 >> 0 ) & 0x1FFF ;
V_181 [ 1 ] = ( V_183 >> 13 ) & 0x1FFF ;
V_181 [ 2 ] = ( ( ( V_184 >> 0 ) & 0x7F ) << 6 ) | ( ( V_183 >> 26 ) & 0x3F ) ;
V_181 [ 3 ] = ( V_184 >> 7 ) & 0x1FFF ;
V_181 [ 4 ] = ( ( ( V_185 >> 0 ) & 0x1 ) << 12 ) | ( ( V_184 >> 20 ) & 0xFFF ) ;
V_181 [ 5 ] = ( V_185 >> 1 ) & 0x1FFF ;
V_181 [ 6 ] = ( V_185 >> 14 ) & 0x1FFF ;
V_181 [ 7 ] = ( ( ( V_186 >> 16 ) & 0xFF ) << 5 ) | ( ( V_185 >> 27 ) & 0x1F ) ;
V_147 = 0 ;
while ( V_182 -- ) {
F_56 ( 0 , ( unsigned long * ) & V_181 [ V_147 ] ) ;
F_56 ( 1 , ( unsigned long * ) & V_181 [ V_147 ] ) ;
if ( V_181 [ V_147 ] < V_7 -> V_8 . V_109 * 8 ) {
F_56 ( V_181 [ V_147 ] , ( unsigned long * ) V_178 ) ;
V_147 ++ ;
}
}
return V_147 ;
}
static bool F_57 ( struct V_119 * V_120 , void * V_190 )
{
V_120 -> V_191 = V_190 ;
return true ;
}
static int F_58 ( struct V_192 * V_193 ,
struct V_16 * V_21 ,
struct V_6 * V_17 )
{
struct V_194 * V_195 = V_193 -> V_103 . V_196 ;
T_2 V_197 ;
int V_91 ;
V_17 -> V_61 = 0 ;
if ( ! F_59 ( V_195 , L_5 , & V_197 ) ) {
if ( V_197 == 2 ) {
V_17 -> V_61 |= V_62 ;
} else if ( V_197 != 1 ) {
F_29 ( & V_193 -> V_103 , L_6 , V_197 ) ;
return - V_137 ;
}
}
if ( F_60 ( V_195 , L_7 , NULL ) )
V_17 -> V_61 |= V_198 ;
V_21 -> V_199 = F_61 ( & V_193 -> V_103 ,
sizeof( * V_21 -> V_199 ) , V_200 ) ;
if ( ! V_21 -> V_199 )
return - V_201 ;
V_91 = F_62 ( V_195 , L_8 , ( V_202 * ) V_21 -> V_199 ,
sizeof( * V_21 -> V_199 ) ) ;
if ( V_91 )
V_21 -> V_199 = NULL ;
V_21 -> V_24 = 0 ;
if ( ! F_59 ( V_195 , L_9 , & V_197 ) ) {
if ( V_197 > 3 ) {
F_29 ( & V_193 -> V_103 , L_10 , V_197 ) ;
return - V_137 ;
}
V_21 -> V_24 = V_197 ;
}
return 0 ;
}
static int T_8 F_63 ( struct V_192 * V_193 )
{
struct V_16 * V_21 ;
struct V_1 * V_2 ;
struct V_6 * V_17 ;
struct V_203 * V_204 ;
T_9 V_205 ;
int V_91 = 0 ;
T_2 V_206 ;
int V_147 ;
V_21 = F_61 ( & V_193 -> V_103 , sizeof( * V_21 ) , V_200 ) ;
if ( ! V_21 )
return - V_201 ;
V_17 = & V_21 -> V_17 ;
V_91 = F_58 ( V_193 , V_21 , V_17 ) ;
if ( V_91 )
return V_91 ;
V_204 = F_64 ( V_193 , V_207 , L_11 ) ;
V_21 -> V_33 = F_65 ( & V_193 -> V_103 , V_204 ) ;
if ( F_22 ( V_21 -> V_33 ) )
return F_23 ( V_21 -> V_33 ) ;
V_21 -> V_139 = ( T_5 ) V_204 -> V_208 ;
V_204 = F_64 ( V_193 , V_207 , L_12 ) ;
V_21 -> V_32 = F_65 ( & V_193 -> V_103 , V_204 ) ;
if ( F_22 ( V_21 -> V_32 ) )
return F_23 ( V_21 -> V_32 ) ;
V_204 = F_64 ( V_193 , V_207 , L_13 ) ;
V_21 -> V_29 = F_65 ( & V_193 -> V_103 , V_204 ) ;
if ( F_22 ( V_21 -> V_29 ) )
return F_23 ( V_21 -> V_29 ) ;
V_204 = F_64 ( V_193 , V_207 , L_14 ) ;
V_21 -> V_23 = F_65 ( & V_193 -> V_103 , V_204 ) ;
if ( F_22 ( V_21 -> V_23 ) )
return F_23 ( V_21 -> V_23 ) ;
V_21 -> V_70 = F_66 ( & V_193 -> V_103 , NULL ) ;
if ( F_22 ( V_21 -> V_70 ) ) {
F_29 ( & V_193 -> V_103 , L_15 ) ;
return F_23 ( V_21 -> V_70 ) ;
}
V_91 = F_67 ( V_21 -> V_70 ) ;
if ( V_91 )
return V_91 ;
for ( V_206 = 0 , V_147 = 0 ; V_147 < 4 ; V_147 ++ )
V_206 |= ( F_9 ( V_21 -> V_23 + F_68 ( V_204 ) - 0x20 + 4 * V_147 ) & 255 ) << ( V_147 * 8 ) ;
V_21 -> V_206 = V_206 ;
F_69 ( & V_193 -> V_103 , L_16
L_17 ,
F_70 ( V_206 ) , F_71 ( V_206 ) ,
F_72 ( V_206 ) , F_73 ( V_206 ) ) ;
V_21 -> V_103 = & V_193 -> V_103 ;
if ( V_21 -> V_93 == V_209 )
F_74 ( & V_21 -> V_114 ) ;
V_2 = F_75 ( & V_21 -> V_17 ) ;
F_76 ( V_17 , V_21 ) ;
F_77 ( V_17 , V_193 -> V_103 . V_196 ) ;
V_2 -> V_103 . V_210 = & V_193 -> V_103 ;
V_17 -> V_28 = V_21 -> V_33 ;
V_17 -> V_30 = V_21 -> V_33 ;
V_17 -> V_211 = F_8 ;
V_17 -> V_212 = 30 ;
V_17 -> V_8 . V_93 = V_213 ;
V_17 -> V_8 . V_169 = F_24 ;
V_17 -> V_8 . V_109 = 512 ;
V_17 -> V_214 = 7 ;
switch ( V_21 -> V_93 ) {
case V_209 :
F_78 ( V_205 ) ;
F_79 ( V_215 , V_205 ) ;
V_21 -> V_136 = F_80 ( V_205 , F_57 , NULL ) ;
if ( ! V_21 -> V_136 ) {
F_29 ( & V_193 -> V_103 , L_18 ) ;
goto V_216;
}
V_21 -> V_134 = F_80 ( V_205 , F_57 , NULL ) ;
if ( ! V_21 -> V_134 ) {
F_29 ( & V_193 -> V_103 , L_19 ) ;
goto V_217;
}
V_17 -> V_171 = F_47 ;
V_17 -> V_218 = F_48 ;
break;
default:
case V_219 :
V_17 -> V_171 = F_45 ;
V_17 -> V_218 = F_43 ;
break;
}
if ( V_21 -> V_199 )
F_14 ( V_21 , V_21 -> V_199 ) ;
else
V_17 -> V_220 = F_19 ;
if ( F_72 ( V_21 -> V_206 ) >= 8 ) {
V_17 -> V_8 . V_221 = F_49 ;
V_17 -> V_8 . V_173 = F_25 ;
V_17 -> V_8 . V_174 = F_53 ;
V_17 -> V_8 . V_14 = 13 ;
V_17 -> V_8 . V_222 = 8 ;
}
V_91 = F_81 ( V_2 , 1 , NULL ) ;
if ( V_91 ) {
F_29 ( & V_193 -> V_103 , L_20 ) ;
goto V_223;
}
if ( F_72 ( V_21 -> V_206 ) >= 8 ) {
switch ( V_2 -> V_13 ) {
case 16 :
case 64 :
case 128 :
case 224 :
case 256 :
break;
default:
F_82 ( & V_193 -> V_103 , L_21 ,
V_2 -> V_13 ) ;
V_91 = - V_137 ;
goto V_224;
}
F_83 ( V_2 , & V_225 ) ;
} else {
switch ( V_17 -> V_8 . V_93 ) {
case V_213 :
F_69 ( & V_193 -> V_103 , L_22 ) ;
V_17 -> V_8 . V_173 = F_30 ;
V_17 -> V_8 . V_174 = V_226 ;
V_17 -> V_8 . V_14 = 3 ;
V_17 -> V_8 . V_222 = 1 ;
break;
case V_227 :
if ( V_17 -> V_8 . V_228 == V_229 ) {
F_69 ( & V_193 -> V_103 , L_23 ) ;
break;
}
case V_230 :
break;
default:
F_29 ( & V_193 -> V_103 , L_24 ) ;
goto V_224;
}
if ( V_17 -> V_8 . V_93 == V_213 ) {
switch ( V_2 -> V_13 ) {
case 16 :
case 64 :
case 128 :
F_83 ( V_2 ,
& V_231 ) ;
break;
default:
F_82 ( & V_193 -> V_103 ,
L_21 ,
V_2 -> V_13 ) ;
V_91 = - V_137 ;
goto V_224;
}
}
}
V_91 = F_84 ( V_2 ) ;
if ( V_91 )
goto V_224;
V_2 -> V_232 = L_25 ;
V_91 = F_85 ( V_2 , NULL , 0 ) ;
if ( V_91 )
goto V_224;
F_86 ( V_193 , V_21 ) ;
F_69 ( & V_193 -> V_103 , L_26 ) ;
return 0 ;
V_224:
V_223:
if ( V_21 -> V_93 == V_209 )
F_87 ( V_21 -> V_134 ) ;
V_217:
if ( V_21 -> V_93 == V_209 )
F_87 ( V_21 -> V_136 ) ;
V_216:
F_88 ( V_21 -> V_70 ) ;
return V_91 ;
}
static int F_89 ( struct V_192 * V_193 )
{
struct V_16 * V_21 = F_90 ( V_193 ) ;
if ( V_21 ) {
F_91 ( F_75 ( & V_21 -> V_17 ) ) ;
if ( V_21 -> V_93 == V_209 ) {
F_87 ( V_21 -> V_134 ) ;
F_87 ( V_21 -> V_136 ) ;
}
F_88 ( V_21 -> V_70 ) ;
}
return 0 ;
}
static int F_92 ( struct V_138 * V_103 )
{
struct V_16 * V_21 = F_93 ( V_103 ) ;
if ( V_21 )
F_88 ( V_21 -> V_70 ) ;
return 0 ;
}
static int F_94 ( struct V_138 * V_103 )
{
struct V_16 * V_21 = F_93 ( V_103 ) ;
if ( V_21 ) {
F_67 ( V_21 -> V_70 ) ;
if ( V_21 -> V_199 )
F_14 ( V_21 , V_21 -> V_199 ) ;
}
return 0 ;
}
