static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
switch ( V_3 ) {
case - 1 :
V_5 -> V_9 ( V_2 , V_10 , 0 | V_11 ) ;
break;
case 0 :
case 1 :
case 2 :
case 3 :
if ( V_8 -> V_12 )
V_8 -> V_12 ( V_3 ,
V_5 -> V_13 & V_14 ) ;
break;
default:
F_3 () ;
}
}
static void F_4 ( struct V_1 * V_2 , int V_15 , unsigned int V_16 )
{
struct V_4 * V_17 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 , V_2 ) ;
void T_1 * V_18 = V_8 -> V_19 ;
unsigned int V_20 = V_8 -> V_20 ;
if ( V_16 & V_11 ) {
T_2 V_21 ;
if ( V_16 & V_22 ) {
V_17 -> V_23 = V_8 -> V_24 ;
V_17 -> V_25 = V_8 -> V_24 ;
} else if ( V_16 & V_26 ) {
V_17 -> V_23 = V_8 -> V_27 ;
V_17 -> V_25 = V_8 -> V_27 ;
} else {
V_17 -> V_23 = V_8 -> V_28 ;
V_17 -> V_25 = V_8 -> V_28 ;
}
V_21 = F_5 ( F_6 ( V_18 , V_20 , V_29 ) ) ;
if ( V_16 & V_30 )
V_21 |= V_31 ;
else
V_21 &= ~ V_31 ;
F_7 ( V_21 , F_6 ( V_18 , V_20 , V_29 ) ) ;
}
F_8 () ;
if ( V_15 != V_10 )
F_9 ( V_15 , V_17 -> V_25 ) ;
}
static void F_10 ( void T_1 * V_18 , T_3 V_20 ,
T_3 V_32 , struct V_33 * V_34 )
{
T_3 V_35 = V_36 | V_31 | V_37 ;
T_3 V_38 , V_39 , V_40 , V_41 , V_42 , V_43 ;
struct V_33 * V_44 ;
struct V_33 V_45 = {
. V_38 = V_46 ,
. V_39 = V_47 ,
. V_40 = V_48 ,
. V_41 = V_49 ,
. V_42 = V_50 ,
. V_43 = V_51 ,
} ;
if ( V_34 )
V_44 = V_34 ;
else
V_44 = & V_45 ;
V_38 = ( V_44 -> V_38 & V_52 ) << V_53 ;
V_39 = ( V_44 -> V_39 & V_54 ) << V_55 ;
V_40 = ( V_44 -> V_40 & V_56 ) << V_57 ;
V_41 = ( V_44 -> V_41 & V_58 ) << V_59 ;
V_42 = ( V_44 -> V_42 & V_60 ) << V_61 ;
V_43 = ( V_44 -> V_43 & V_62 ) << V_63 ;
if ( V_32 )
F_7 ( V_35 | V_64 ,
F_6 ( V_18 , V_20 , V_29 ) ) ;
else
F_7 ( V_35 | V_65 ,
F_6 ( V_18 , V_20 , V_29 ) ) ;
F_7 ( F_5 ( F_6 ( V_18 , V_20 , V_29 ) ) | V_38 | V_39 ,
F_6 ( V_18 , V_20 , V_29 ) ) ;
F_7 ( V_40 | V_41 | V_42 | V_43 ,
F_6 ( V_18 , V_20 , V_66 ) ) ;
F_7 ( V_40 | V_41 | V_42 | V_43 ,
F_6 ( V_18 , V_20 , V_67 ) ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_68 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 , V_2 ) ;
void T_1 * V_18 = V_8 -> V_19 ;
T_3 V_20 = V_8 -> V_20 ;
F_7 ( F_5 ( F_6 ( V_18 , V_20 , V_29 ) ) & ~ V_69 ,
F_6 ( V_18 , V_20 , V_29 ) ) ;
F_7 ( F_5 ( F_6 ( V_18 , V_20 , V_29 ) ) & ~ V_70 ,
F_6 ( V_18 , V_20 , V_29 ) ) ;
F_7 ( F_5 ( F_6 ( V_18 , V_20 , V_29 ) ) | V_70 ,
F_6 ( V_18 , V_20 , V_29 ) ) ;
}
static int F_12 ( struct V_1 * V_2 , const T_4 * V_71 ,
T_4 * V_72 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 , V_2 ) ;
void T_1 * V_18 = V_8 -> V_19 ;
T_3 V_20 = V_8 -> V_20 ;
T_3 V_73 ;
unsigned long V_74 = V_75 + V_76 ;
do {
if ( F_13 ( F_6 ( V_18 , V_20 , V_77 ) ) & V_78 )
break;
else
F_14 () ;
} while ( ! F_15 ( V_75 , V_74 ) );
if ( F_15 ( V_75 , V_74 ) ) {
F_16 ( V_8 -> V_79 , L_1 ) ;
return - V_80 ;
}
V_73 = F_13 ( F_6 ( V_18 , V_20 , V_81 ) ) ;
V_72 [ 0 ] = ( T_4 ) ( V_73 >> 0 ) ;
V_72 [ 1 ] = ( T_4 ) ( V_73 >> 8 ) ;
V_72 [ 2 ] = ( T_4 ) ( V_73 >> 16 ) ;
V_72 [ 3 ] = ( T_4 ) ( V_73 >> 24 ) ;
V_73 = F_13 ( F_6 ( V_18 , V_20 , V_82 ) ) ;
V_72 [ 4 ] = ( T_4 ) ( V_73 >> 0 ) ;
V_72 [ 5 ] = ( T_4 ) ( V_73 >> 8 ) ;
V_72 [ 6 ] = ( T_4 ) ( V_73 >> 16 ) ;
V_72 [ 7 ] = ( T_4 ) ( V_73 >> 24 ) ;
V_73 = F_13 ( F_6 ( V_18 , V_20 , V_83 ) ) ;
V_72 [ 8 ] = ( T_4 ) ( V_73 >> 0 ) ;
V_72 [ 9 ] = ( T_4 ) ( V_73 >> 8 ) ;
V_72 [ 10 ] = ( T_4 ) ( V_73 >> 16 ) ;
V_72 [ 11 ] = ( T_4 ) ( V_73 >> 24 ) ;
V_73 = F_13 ( F_6 ( V_18 , V_20 , V_77 ) ) ;
V_72 [ 12 ] = ( T_4 ) ( V_73 >> 16 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , const T_4 * V_71 ,
T_4 * V_72 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 , V_2 ) ;
void T_1 * V_18 = V_8 -> V_19 ;
T_3 V_20 = V_8 -> V_20 ;
T_3 V_73 ;
V_73 = F_13 ( F_6 ( V_18 , V_20 , V_81 ) ) ;
V_72 [ 0 ] = ( T_4 ) ( V_73 >> 0 ) ;
V_72 [ 1 ] = ( T_4 ) ( V_73 >> 8 ) ;
V_72 [ 2 ] = ( T_4 ) ( V_73 >> 16 ) ;
return 0 ;
}
static int F_18 ( T_4 * V_84 , int V_85 , int V_86 )
{
int V_87 , V_88 = 0 ;
for ( V_87 = 0 ; V_87 < V_85 ; V_87 ++ ) {
V_88 += F_19 ( ~ V_84 [ V_87 ] ) ;
if ( V_88 > V_86 )
break;
}
return V_88 ;
}
static void F_20 ( void * V_89 )
{
struct V_7 * V_8 = V_89 ;
F_21 ( & V_8 -> V_90 ) ;
}
static int F_22 ( struct V_7 * V_8 , void * V_91 , int V_92 ,
enum V_93 V_94 )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
T_5 V_101 , V_102 , V_103 ;
T_6 V_104 ;
unsigned long V_105 = V_106 | V_107 ;
int V_108 ;
unsigned long V_109 ;
if ( V_94 == V_110 )
V_96 = V_8 -> V_111 ;
else if ( V_94 == V_112 )
V_96 = V_8 -> V_113 ;
else
return - V_114 ;
V_98 = V_96 -> V_115 ;
V_103 = F_23 ( V_98 -> V_79 , V_91 , V_92 , V_94 ) ;
if ( V_94 == V_110 ) {
V_102 = V_103 ;
V_101 = V_8 -> V_116 ;
} else {
V_102 = V_8 -> V_116 ;
V_101 = V_103 ;
}
V_100 = V_98 -> V_117 ( V_96 , V_101 , V_102 ,
V_92 , V_105 ) ;
if ( ! V_100 ) {
F_16 ( V_8 -> V_79 , L_2 ) ;
V_108 = - V_118 ;
goto V_119;
}
V_100 -> V_120 = F_20 ;
V_100 -> V_121 = V_8 ;
V_104 = V_100 -> V_122 ( V_100 ) ;
V_108 = F_24 ( V_104 ) ;
if ( V_108 ) {
F_16 ( V_8 -> V_79 , L_3 , V_104 ) ;
goto V_119;
}
F_25 ( V_96 ) ;
V_109 =
F_26 ( & V_8 -> V_90 ,
F_27 ( 3000 ) ) ;
if ( V_109 == 0 ) {
F_28 ( V_96 ) ;
F_16 ( V_8 -> V_79 , L_4 ) ;
V_108 = - V_80 ;
goto V_119;
}
V_108 = 0 ;
V_119:
F_29 ( V_98 -> V_79 , V_103 , V_92 , V_94 ) ;
return V_108 ;
}
static void F_30 ( struct V_1 * V_2 , const T_4 * V_123 , int V_92 )
{
int V_124 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_31 ( ( T_3 ) V_123 , sizeof( T_3 ) ) &&
F_31 ( V_92 , sizeof( T_3 ) ) ) {
T_3 * V_125 = ( T_3 * ) V_123 ;
V_92 = V_92 >> 2 ;
for ( V_124 = 0 ; V_124 < V_92 ; V_124 ++ )
F_7 ( V_125 [ V_124 ] , V_5 -> V_25 ) ;
} else {
for ( V_124 = 0 ; V_124 < V_92 ; V_124 ++ )
F_9 ( V_123 [ V_124 ] , V_5 -> V_25 ) ;
}
}
static void F_32 ( struct V_1 * V_2 , T_4 * V_123 , int V_92 )
{
int V_124 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_31 ( ( T_3 ) V_123 , sizeof( T_3 ) ) &&
F_31 ( V_92 , sizeof( T_3 ) ) ) {
T_3 * V_125 = ( T_3 * ) V_123 ;
V_92 = V_92 >> 2 ;
for ( V_124 = 0 ; V_124 < V_92 ; V_124 ++ )
V_125 [ V_124 ] = F_13 ( V_5 -> V_23 ) ;
} else {
for ( V_124 = 0 ; V_124 < V_92 ; V_124 ++ )
V_123 [ V_124 ] = F_33 ( V_5 -> V_23 ) ;
}
}
static void F_34 ( struct V_1 * V_2 , T_4 * V_123 , int V_92 )
{
struct V_7 * V_8 ;
V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
F_22 ( V_8 , V_123 , V_92 , V_112 ) ;
}
static void F_35 ( struct V_1 * V_2 , const T_4 * V_123 ,
int V_92 )
{
struct V_7 * V_8 ;
V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
F_22 ( V_8 , ( void * ) V_123 , V_92 , V_110 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_4 * V_5 ,
T_4 * V_123 , int V_126 , int V_127 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 , V_2 ) ;
struct V_128 * V_129 = V_8 -> V_129 ;
int V_124 , V_130 , V_131 , V_132 , V_133 = V_5 -> V_72 . V_85 ;
int V_134 = V_5 -> V_72 . V_135 ;
int V_136 = V_5 -> V_72 . V_137 ;
T_4 * V_125 = V_123 ;
T_4 * V_138 = V_5 -> V_139 -> V_140 ;
T_4 * V_141 = V_5 -> V_139 -> V_142 ;
int V_143 , V_92 , V_144 = 0 ;
T_7 V_145 [ 7 ] ;
T_4 * V_146 = ( T_4 * ) & V_145 [ 0 ] ;
unsigned int V_147 = 0 ;
for ( V_124 = 0 , V_131 = 0 ; V_131 < V_136 ; V_131 ++ , V_124 += V_134 , V_125 += V_133 ) {
V_5 -> V_148 ( V_2 , V_149 , V_131 * V_133 , V_127 ) ;
V_5 -> V_72 . V_150 ( V_2 , V_151 ) ;
V_5 -> V_152 ( V_2 , V_125 , V_133 ) ;
for ( V_130 = 0 ; V_130 < V_134 ; ) {
V_143 = V_129 -> V_153 [ V_144 ] . V_154 ;
V_92 = V_129 -> V_153 [ V_144 ] . V_155 ;
V_144 ++ ;
if ( V_5 -> V_13 & V_14 )
V_92 = F_37 ( V_92 , 2 ) ;
V_5 -> V_148 ( V_2 , V_156 , V_143 , V_127 ) ;
V_5 -> V_152 ( V_2 , V_146 + V_130 , V_92 ) ;
V_130 += V_92 ;
}
memcpy ( & V_141 [ V_124 ] , V_146 , V_5 -> V_72 . V_135 ) ;
V_5 -> V_72 . V_157 ( V_2 , V_125 , & V_138 [ V_124 ] ) ;
V_132 = V_5 -> V_72 . V_158 ( V_2 , V_125 , & V_141 [ V_124 ] , & V_138 [ V_124 ] ) ;
if ( V_132 < 0 ) {
V_2 -> V_159 . V_160 ++ ;
} else {
V_2 -> V_159 . V_161 += V_132 ;
V_147 = F_38 (unsigned int, max_bitflips, stat) ;
}
}
return V_147 ;
}
static int F_39 ( struct V_1 * V_2 , T_4 * V_162 ,
T_4 * V_163 , T_4 * V_164 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 , V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
void T_1 * V_18 = V_8 -> V_19 ;
unsigned int V_20 = V_8 -> V_20 ;
T_3 V_165 [ 8 ] ;
T_3 V_166 , V_124 ;
T_3 V_167 , V_168 , V_169 , V_170 ;
V_166 = ( F_13 ( F_6 ( V_18 , V_20 , V_77 ) ) >> 10 ) & 0xF ;
if ( F_40 ( V_166 == 0 ) )
return 0 ;
if ( F_41 ( V_166 > 8 ) ) {
int V_171 = F_18 ( V_163 , V_5 -> V_72 . V_135 , 8 ) ;
int V_172 = F_18 ( V_162 , V_5 -> V_72 . V_85 , 8 ) ;
if ( ( V_171 + V_172 ) <= 8 ) {
if ( V_172 )
memset ( V_162 , 0xff , V_5 -> V_72 . V_85 ) ;
return V_172 ;
}
return - V_173 ;
}
V_167 = F_13 ( F_6 ( V_18 , V_20 , V_81 ) ) ;
V_168 = F_13 ( F_6 ( V_18 , V_20 , V_82 ) ) ;
V_169 = F_13 ( F_6 ( V_18 , V_20 , V_83 ) ) ;
V_170 = F_13 ( F_6 ( V_18 , V_20 , V_77 ) ) ;
V_165 [ 0 ] = ( V_167 >> 0 ) & 0x1FFF ;
V_165 [ 1 ] = ( V_167 >> 13 ) & 0x1FFF ;
V_165 [ 2 ] = ( ( ( V_168 >> 0 ) & 0x7F ) << 6 ) | ( ( V_167 >> 26 ) & 0x3F ) ;
V_165 [ 3 ] = ( V_168 >> 7 ) & 0x1FFF ;
V_165 [ 4 ] = ( ( ( V_169 >> 0 ) & 0x1 ) << 12 ) | ( ( V_168 >> 20 ) & 0xFFF ) ;
V_165 [ 5 ] = ( V_169 >> 1 ) & 0x1FFF ;
V_165 [ 6 ] = ( V_169 >> 14 ) & 0x1FFF ;
V_165 [ 7 ] = ( ( ( V_170 >> 16 ) & 0xFF ) << 5 ) | ( ( V_169 >> 27 ) & 0x1F ) ;
V_124 = 0 ;
while ( V_166 -- ) {
F_42 ( 0 , ( unsigned long * ) & V_165 [ V_124 ] ) ;
F_42 ( 1 , ( unsigned long * ) & V_165 [ V_124 ] ) ;
if ( V_165 [ V_124 ] < V_5 -> V_72 . V_85 * 8 ) {
F_42 ( V_165 [ V_124 ] , ( unsigned long * ) V_162 ) ;
V_124 ++ ;
}
}
return V_124 ;
}
static bool F_43 ( struct V_95 * V_96 , void * V_174 )
{
V_96 -> V_175 = V_174 ;
return true ;
}
static int F_44 ( struct V_176 * V_177 ,
struct V_178 * V_179 )
{
struct V_180 * V_181 = F_45 ( & V_177 -> V_79 ) ;
T_2 V_182 ;
int V_108 ;
V_181 -> V_183 = 8 ;
if ( ! F_46 ( V_179 , L_5 , & V_182 ) ) {
if ( V_182 == 2 ) {
V_181 -> V_183 = 16 ;
} else if ( V_182 != 1 ) {
F_16 ( & V_177 -> V_79 , L_6 , V_182 ) ;
return - V_114 ;
}
}
if ( F_47 ( V_179 , L_7 , NULL ) )
V_181 -> V_13 = V_184 ;
V_181 -> V_185 = F_48 ( & V_177 -> V_79 ,
sizeof( * V_181 -> V_185 ) , V_186 ) ;
if ( ! V_181 -> V_185 )
return - V_187 ;
V_108 = F_49 ( V_179 , L_8 , ( V_188 * ) V_181 -> V_185 ,
sizeof( * V_181 -> V_185 ) ) ;
if ( V_108 ) {
F_50 ( & V_177 -> V_79 , L_9 ) ;
V_181 -> V_185 = NULL ;
}
V_181 -> V_20 = 0 ;
if ( ! F_46 ( V_179 , L_10 , & V_182 ) ) {
if ( V_182 > 3 ) {
F_16 ( & V_177 -> V_79 , L_11 , V_182 ) ;
return - V_114 ;
}
V_181 -> V_20 = V_182 ;
}
return 0 ;
}
static int F_44 ( struct V_176 * V_177 ,
struct V_178 * V_179 )
{
return - V_189 ;
}
static int T_8 F_51 ( struct V_176 * V_177 )
{
struct V_180 * V_181 = F_45 ( & V_177 -> V_79 ) ;
struct V_178 T_9 * V_179 = V_177 -> V_79 . V_190 ;
struct V_191 V_192 = {} ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_4 * V_193 ;
struct V_194 * V_195 ;
T_10 V_196 ;
int V_108 = 0 ;
T_2 V_197 ;
int V_124 ;
if ( V_179 ) {
V_181 = F_48 ( & V_177 -> V_79 , sizeof( * V_181 ) , V_186 ) ;
V_177 -> V_79 . V_198 = V_181 ;
V_108 = F_44 ( V_177 , V_179 ) ;
if ( V_108 ) {
F_16 ( & V_177 -> V_79 , L_12 ) ;
return - V_199 ;
}
}
if ( ! V_181 ) {
F_16 ( & V_177 -> V_79 , L_13 ) ;
return - V_114 ;
}
V_8 = F_48 ( & V_177 -> V_79 , sizeof( * V_8 ) , V_186 ) ;
if ( ! V_8 )
return - V_187 ;
V_195 = F_52 ( V_177 , V_200 , L_14 ) ;
V_8 -> V_28 = F_53 ( & V_177 -> V_79 , V_195 ) ;
if ( F_54 ( V_8 -> V_28 ) )
return F_55 ( V_8 -> V_28 ) ;
V_8 -> V_116 = ( T_5 ) V_195 -> V_201 ;
V_195 = F_52 ( V_177 , V_200 , L_15 ) ;
V_8 -> V_27 = F_53 ( & V_177 -> V_79 , V_195 ) ;
if ( F_54 ( V_8 -> V_27 ) )
return F_55 ( V_8 -> V_27 ) ;
V_195 = F_52 ( V_177 , V_200 , L_16 ) ;
V_8 -> V_24 = F_53 ( & V_177 -> V_79 , V_195 ) ;
if ( F_54 ( V_8 -> V_24 ) )
return F_55 ( V_8 -> V_24 ) ;
V_195 = F_52 ( V_177 , V_200 , L_17 ) ;
V_8 -> V_19 = F_53 ( & V_177 -> V_79 , V_195 ) ;
if ( F_54 ( V_8 -> V_19 ) )
return F_55 ( V_8 -> V_19 ) ;
V_8 -> V_202 = F_56 ( & V_177 -> V_79 , NULL ) ;
if ( F_54 ( V_8 -> V_202 ) ) {
F_16 ( & V_177 -> V_79 , L_18 ) ;
return F_55 ( V_8 -> V_202 ) ;
}
V_108 = F_57 ( V_8 -> V_202 ) ;
if ( V_108 )
goto V_203;
for ( V_197 = 0 , V_124 = 0 ; V_124 < 4 ; V_124 ++ )
V_197 |= ( F_5 ( V_8 -> V_19 + F_58 ( V_195 ) - 0x20 + 4 * V_124 ) & 255 ) << ( V_124 * 8 ) ;
V_8 -> V_197 = V_197 ;
F_50 ( & V_177 -> V_79 , L_19
L_20 ,
F_59 ( V_197 ) , F_60 ( V_197 ) ,
F_61 ( V_197 ) , F_62 ( V_197 ) ) ;
V_8 -> V_20 = V_181 -> V_20 ;
V_8 -> V_12 = V_181 -> V_204 ;
V_8 -> V_205 = V_181 -> V_205 ;
V_8 -> V_206 = V_181 -> V_206 ;
V_8 -> V_79 = & V_177 -> V_79 ;
V_8 -> V_207 = V_181 -> V_185 ;
V_8 -> V_68 = V_181 -> V_68 ;
if ( V_8 -> V_68 == V_208 )
F_63 ( & V_8 -> V_90 ) ;
V_2 = & V_8 -> V_2 ;
V_193 = & V_8 -> V_193 ;
V_2 -> V_6 = V_193 ;
V_193 -> V_6 = V_8 ;
V_8 -> V_2 . V_209 = V_210 ;
V_193 -> V_23 = V_8 -> V_28 ;
V_193 -> V_25 = V_8 -> V_28 ;
V_193 -> V_9 = F_4 ;
V_193 -> V_211 = 30 ;
V_193 -> V_72 . V_68 = V_212 ;
V_193 -> V_72 . V_150 = F_11 ;
V_193 -> V_72 . V_85 = 512 ;
V_193 -> V_13 = V_181 -> V_13 ;
V_193 -> V_12 = F_1 ;
V_193 -> V_213 = 7 ;
if ( V_181 -> V_183 == V_214 )
V_193 -> V_13 |= V_14 ;
switch ( V_8 -> V_68 ) {
case V_208 :
F_64 ( V_196 ) ;
F_65 ( V_215 , V_196 ) ;
V_8 -> V_113 = F_66 ( V_196 , F_43 ,
V_181 -> V_216 ) ;
if ( ! V_8 -> V_113 ) {
F_16 ( & V_177 -> V_79 , L_21 ) ;
goto V_217;
}
V_8 -> V_111 = F_66 ( V_196 , F_43 ,
V_181 -> V_218 ) ;
if ( ! V_8 -> V_111 ) {
F_16 ( & V_177 -> V_79 , L_22 ) ;
goto V_219;
}
V_193 -> V_152 = F_34 ;
V_193 -> V_220 = F_35 ;
break;
default:
case V_221 :
V_193 -> V_152 = F_32 ;
V_193 -> V_220 = F_30 ;
break;
}
F_10 ( V_8 -> V_19 , V_8 -> V_20 ,
V_193 -> V_13 & V_14 ,
V_8 -> V_207 ) ;
if ( F_61 ( V_8 -> V_197 ) >= 8 ) {
V_193 -> V_72 . V_222 = F_36 ;
V_193 -> V_72 . V_157 = F_12 ;
V_193 -> V_72 . V_158 = F_39 ;
V_193 -> V_72 . V_135 = 13 ;
V_193 -> V_72 . V_223 = 8 ;
} else {
V_193 -> V_72 . V_157 = F_17 ;
V_193 -> V_72 . V_158 = V_224 ;
V_193 -> V_72 . V_135 = 3 ;
V_193 -> V_72 . V_223 = 1 ;
}
if ( F_67 ( & V_8 -> V_2 , 1 , NULL ) ) {
V_108 = - V_225 ;
F_16 ( & V_177 -> V_79 , L_23 ) ;
goto V_226;
}
if ( F_61 ( V_8 -> V_197 ) >= 8 ) {
switch ( V_8 -> V_2 . V_227 ) {
case 16 :
V_193 -> V_72 . V_228 = & V_229 ;
V_8 -> V_129 = & V_230 ;
break;
case 64 :
V_193 -> V_72 . V_228 = & V_231 ;
V_8 -> V_129 = & V_232 ;
break;
case 128 :
V_193 -> V_72 . V_228 = & V_233 ;
V_8 -> V_129 = & V_232 ;
break;
case 224 :
V_193 -> V_72 . V_228 = & V_234 ;
V_8 -> V_129 = & V_232 ;
break;
case 256 :
V_193 -> V_72 . V_228 = & V_235 ;
V_8 -> V_129 = & V_232 ;
break;
default:
F_68 ( & V_177 -> V_79 , L_24 ,
V_2 -> V_227 ) ;
F_3 () ;
}
} else {
switch ( V_8 -> V_2 . V_227 ) {
case 16 :
V_193 -> V_72 . V_228 = & V_236 ;
break;
case 64 :
V_193 -> V_72 . V_228 = & V_237 ;
break;
case 128 :
V_193 -> V_72 . V_228 = & V_238 ;
break;
default:
F_68 ( & V_177 -> V_79 , L_24 ,
V_2 -> V_227 ) ;
F_3 () ;
}
}
if ( F_69 ( & V_8 -> V_2 ) ) {
V_108 = - V_225 ;
goto V_239;
}
V_8 -> V_2 . V_240 = L_25 ;
V_192 . V_190 = V_179 ;
V_108 = F_70 ( & V_8 -> V_2 , NULL , & V_192 ,
V_8 -> V_205 , V_8 -> V_206 ) ;
if ( V_108 )
goto V_239;
F_71 ( V_177 , V_8 ) ;
F_50 ( & V_177 -> V_79 , L_26 ) ;
return 0 ;
V_239:
V_226:
if ( V_8 -> V_68 == V_208 )
F_72 ( V_8 -> V_111 ) ;
V_219:
if ( V_8 -> V_68 == V_208 )
F_72 ( V_8 -> V_113 ) ;
V_217:
F_73 ( V_8 -> V_202 ) ;
V_203:
F_74 ( V_8 -> V_202 ) ;
return V_108 ;
}
static int F_75 ( struct V_176 * V_177 )
{
struct V_7 * V_8 = F_76 ( V_177 ) ;
if ( V_8 ) {
F_77 ( & V_8 -> V_2 ) ;
if ( V_8 -> V_68 == V_208 ) {
F_72 ( V_8 -> V_111 ) ;
F_72 ( V_8 -> V_113 ) ;
}
F_73 ( V_8 -> V_202 ) ;
F_74 ( V_8 -> V_202 ) ;
}
return 0 ;
}
static int F_78 ( struct V_115 * V_79 )
{
struct V_7 * V_8 = F_79 ( V_79 ) ;
if ( V_8 )
F_73 ( V_8 -> V_202 ) ;
return 0 ;
}
static int F_80 ( struct V_115 * V_79 )
{
struct V_7 * V_8 = F_79 ( V_79 ) ;
if ( V_8 ) {
F_57 ( V_8 -> V_202 ) ;
F_10 ( V_8 -> V_19 , V_8 -> V_20 ,
V_8 -> V_193 . V_13 & V_14 ,
V_8 -> V_207 ) ;
}
return 0 ;
}
