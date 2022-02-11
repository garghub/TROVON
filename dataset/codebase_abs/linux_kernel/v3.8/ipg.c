static inline void T_1 * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
unsigned int V_6 ;
T_2 V_7 ;
F_4 ( L_1 ) ;
F_5 ( V_2 , L_2 , V_4 -> V_8 ) ;
F_5 ( V_2 , L_3 , V_4 -> V_9 ) ;
F_5 ( V_2 , L_4 ,
( unsigned long ) V_4 -> V_10 ) ;
F_5 ( V_2 , L_5 ,
F_6 ( V_11 ) , F_6 ( V_12 ) ) ;
for ( V_6 = 0 ; V_6 < V_13 ; V_6 ++ ) {
V_7 = ( T_2 ) & V_4 -> V_14 [ V_6 ] . V_15 - ( T_2 ) V_4 -> V_14 ;
F_5 ( V_2 , L_6 ,
V_6 , V_7 , ( unsigned long ) V_4 -> V_14 [ V_6 ] . V_15 ) ;
V_7 = ( T_2 ) & V_4 -> V_14 [ V_6 ] . V_16 - ( T_2 ) V_4 -> V_14 ;
F_5 ( V_2 , L_7 ,
V_6 , V_7 , ( unsigned long ) V_4 -> V_14 [ V_6 ] . V_16 ) ;
V_7 = ( T_2 ) & V_4 -> V_14 [ V_6 ] . V_17 - ( T_2 ) V_4 -> V_14 ;
F_5 ( V_2 , L_8 ,
V_6 , V_7 , ( unsigned long ) V_4 -> V_14 [ V_6 ] . V_17 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
unsigned int V_6 ;
T_2 V_7 ;
F_4 ( L_9 ) ;
F_5 ( V_2 , L_10 , V_4 -> V_18 ) ;
F_5 ( V_2 , L_11 , V_4 -> V_19 ) ;
F_5 ( V_2 , L_12 ,
( unsigned long ) V_4 -> V_20 ) ;
F_5 ( V_2 , L_13 ,
F_6 ( V_21 ) , F_6 ( V_22 ) ) ;
for ( V_6 = 0 ; V_6 < V_23 ; V_6 ++ ) {
V_7 = ( T_2 ) & V_4 -> V_24 [ V_6 ] . V_15 - ( T_2 ) V_4 -> V_24 ;
F_5 ( V_2 , L_14 ,
V_6 , V_7 , ( unsigned long ) V_4 -> V_24 [ V_6 ] . V_15 ) ;
V_7 = ( T_2 ) & V_4 -> V_24 [ V_6 ] . V_25 - ( T_2 ) V_4 -> V_24 ;
F_5 ( V_2 , L_15 ,
V_6 , V_7 , ( unsigned long ) V_4 -> V_24 [ V_6 ] . V_25 ) ;
V_7 = ( T_2 ) & V_4 -> V_24 [ V_6 ] . V_17 - ( T_2 ) V_4 -> V_24 ;
F_5 ( V_2 , L_8 ,
V_6 , V_7 , ( unsigned long ) V_4 -> V_24 [ V_6 ] . V_17 ) ;
}
}
static void F_8 ( void T_1 * V_5 , T_3 V_26 )
{
F_9 ( V_27 & V_26 , V_28 ) ;
F_10 ( V_29 ) ;
}
static void F_11 ( void T_1 * V_5 , T_3 V_26 )
{
F_8 ( V_5 , V_30 | V_26 ) ;
F_8 ( V_5 , V_31 | V_26 ) ;
}
static void F_12 ( void T_1 * V_5 , T_3 V_32 )
{
V_32 |= ( V_33 & 0 ) | V_34 ;
F_11 ( V_5 , V_32 ) ;
}
static void F_13 ( void T_1 * V_5 , T_3 V_32 )
{
F_9 ( ( V_30 | ( V_33 & 0 ) | V_34 |
V_32 ) & V_27 , V_28 ) ;
}
static T_4 F_14 ( void T_1 * V_5 , T_3 V_32 )
{
T_4 V_35 ;
F_8 ( V_5 , V_30 | V_32 ) ;
V_35 = ( ( F_15 ( V_28 ) & V_33 ) >> 1 ) & 1 ;
F_8 ( V_5 , V_31 | V_32 ) ;
return V_35 ;
}
static int F_16 ( struct V_1 * V_2 , int V_36 , int V_37 )
{
void T_1 * V_5 = F_1 ( V_2 ) ;
struct {
T_2 V_38 ;
unsigned int V_39 ;
} V_40 [] = {
{ V_41 , 32 } ,
{ V_42 , 2 } ,
{ V_43 , 2 } ,
{ V_36 , 5 } ,
{ V_37 , 5 } ,
{ 0x0000 , 2 } ,
{ 0x0000 , 16 } ,
{ 0x0000 , 1 }
} ;
unsigned int V_6 , V_44 ;
T_3 V_45 , V_26 ;
V_45 = F_15 ( V_28 ) ;
V_45 &= ( V_46 | V_47 ) ;
for ( V_44 = 0 ; V_44 < 5 ; V_44 ++ ) {
for ( V_6 = 0 ; V_6 < V_40 [ V_44 ] . V_39 ; V_6 ++ ) {
V_26 = ( V_40 [ V_44 ] . V_38 >> ( V_40 [ V_44 ] . V_39 - 1 - V_6 ) ) << 1 ;
V_26 &= V_33 ;
V_26 |= V_45 | V_34 ;
F_11 ( V_5 , V_26 ) ;
}
}
F_12 ( V_5 , V_45 ) ;
F_14 ( V_5 , V_45 ) ;
for ( V_6 = 0 ; V_6 < V_40 [ 6 ] . V_39 ; V_6 ++ ) {
V_40 [ 6 ] . V_38 |=
( F_14 ( V_5 , V_45 ) << ( V_40 [ 6 ] . V_39 - 1 - V_6 ) ) ;
}
F_12 ( V_5 , V_45 ) ;
F_12 ( V_5 , V_45 ) ;
F_12 ( V_5 , V_45 ) ;
F_13 ( V_5 , V_45 ) ;
return V_40 [ 6 ] . V_38 ;
}
static void F_17 ( struct V_1 * V_2 , int V_36 , int V_37 , int V_48 )
{
void T_1 * V_5 = F_1 ( V_2 ) ;
struct {
T_2 V_38 ;
unsigned int V_39 ;
} V_40 [] = {
{ V_41 , 32 } ,
{ V_42 , 2 } ,
{ V_49 , 2 } ,
{ V_36 , 5 } ,
{ V_37 , 5 } ,
{ 0x0002 , 2 } ,
{ V_48 & 0xffff , 16 } ,
{ 0x0000 , 1 }
} ;
unsigned int V_6 , V_44 ;
T_3 V_45 , V_26 ;
V_45 = F_15 ( V_28 ) ;
V_45 &= ( V_46 | V_47 ) ;
for ( V_44 = 0 ; V_44 < 7 ; V_44 ++ ) {
for ( V_6 = 0 ; V_6 < V_40 [ V_44 ] . V_39 ; V_6 ++ ) {
V_26 = ( V_40 [ V_44 ] . V_38 >> ( V_40 [ V_44 ] . V_39 - 1 - V_6 ) ) << 1 ;
V_26 &= V_33 ;
V_26 |= V_45 | V_34 ;
F_11 ( V_5 , V_26 ) ;
}
}
F_8 ( V_5 , V_30 | V_45 ) ;
F_15 ( V_28 ) ;
F_8 ( V_5 , V_31 | V_45 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_50 ;
V_50 = F_6 ( V_51 ) ;
V_50 &= ~ ( V_52 | V_53 | V_54 ) ;
if ( ( V_4 -> V_55 & 0x03 ) > 1 )
V_50 |= V_52 ;
if ( ( V_4 -> V_55 & 0x01 ) == 1 )
V_50 |= V_53 ;
if ( ( V_4 -> V_55 & 0x08 ) == 8 )
V_50 |= V_54 ;
F_19 ( V_50 , V_51 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
int V_56 ;
V_56 = F_15 ( V_57 ) ;
V_56 &= ~ ( V_58 | V_59 | V_60 ) ;
V_56 |= ( ( V_4 -> V_55 & 0x70 ) >> 4 ) ;
F_9 ( V_56 , V_57 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_61 )
{
void T_1 * V_5 = F_1 ( V_2 ) ;
unsigned int V_62 = 0 ;
F_4 ( L_16 ) ;
F_19 ( F_6 ( V_51 ) | V_61 , V_51 ) ;
F_22 ( V_63 ) ;
while ( V_64 & F_6 ( V_51 ) ) {
F_22 ( V_63 ) ;
if ( ++ V_62 > V_65 )
return - V_66 ;
}
F_18 ( V_2 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
unsigned int V_67 , V_6 ;
for ( V_6 = 0 ; V_6 < 32 ; V_6 ++ ) {
T_2 V_68 ;
V_67 = ( V_69 + V_6 ) % 32 ;
V_68 = F_16 ( V_2 , V_67 , V_70 ) ;
if ( ( V_68 != 0xFFFF ) && ( V_68 != 0 ) )
return V_67 ;
}
return 0x1f ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
unsigned int V_71 ;
unsigned int V_72 ;
unsigned int V_73 ;
T_2 V_74 ;
T_2 V_75 ;
T_3 V_76 ;
const char * V_77 ;
const char * V_78 ;
const char * V_79 ;
const char * V_80 ;
F_4 ( L_17 ) ;
V_75 = F_6 ( V_51 ) ;
V_76 = F_15 ( V_28 ) ;
V_74 = F_6 ( V_81 ) ;
V_73 = 0 ;
V_71 = 0 ;
V_72 = 0 ;
V_4 -> V_82 = 0 ;
switch ( V_76 & V_83 ) {
case V_84 :
V_77 = L_18 ;
V_4 -> V_82 = 1 ;
break;
case V_85 :
V_77 = L_19 ;
break;
case V_86 :
V_77 = L_20 ;
break;
default:
V_77 = L_21 ;
return 0 ;
}
F_5 ( V_2 , L_22 , V_77 ) ;
if ( V_4 -> V_82 == 1 )
F_5 ( V_2 , L_23 ) ;
if ( V_76 & V_87 ) {
V_73 = 1 ;
V_71 = 1 ;
V_72 = 1 ;
}
if ( V_73 == 1 ) {
V_78 = L_24 ;
V_74 |= V_88 ;
if ( V_71 == 1 ) {
V_79 = L_25 ;
V_74 |= V_89 ;
} else {
V_79 = L_26 ;
V_74 &= ~ V_89 ;
}
if ( V_72 == 1 ) {
V_80 = L_25 ;
V_74 |= V_90 ;
} else {
V_80 = L_26 ;
V_74 &= ~ V_90 ;
}
} else {
V_78 = L_27 ;
V_79 = L_26 ;
V_80 = L_26 ;
V_74 &= ( ~ V_88 &
~ V_89 &
~ V_90 ) ;
}
F_5 ( V_2 , L_28 ,
V_78 , V_79 , V_80 ) ;
F_19 ( V_74 , V_81 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
void T_1 * V_5 = F_1 ( V_2 ) ;
struct V_91 * V_92 ;
unsigned int V_93 ;
T_2 V_94 [ 2 ] ;
T_3 V_95 ;
F_4 ( L_29 ) ;
V_95 = V_96 | V_97 ;
if ( V_2 -> V_98 & V_99 ) {
V_95 = V_100 ;
} else if ( ( V_2 -> V_98 & V_101 ) ||
( ( V_2 -> V_98 & V_102 ) &&
( F_26 ( V_2 ) > V_103 ) ) ) {
V_95 |= V_104 ;
} else if ( ( V_2 -> V_98 & V_102 ) && ! F_27 ( V_2 ) ) {
V_95 |= V_105 ;
}
V_94 [ 0 ] = 0x00000000 ;
V_94 [ 1 ] = 0x00000000 ;
F_28 (ha, dev) {
V_93 = F_29 ( 0xffffffff , V_92 -> V_106 ,
V_107 ) ;
V_93 = V_93 & 0x3F ;
F_30 ( V_93 , ( void * ) V_94 ) ;
}
F_19 ( V_94 [ 0 ] , V_108 ) ;
F_19 ( V_94 [ 1 ] , V_109 ) ;
F_9 ( V_110 & V_95 , V_111 ) ;
F_4 ( L_30 , F_15 ( V_111 ) ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = F_1 ( V_2 ) ;
T_2 V_112 ;
T_2 V_113 ;
F_4 ( L_31 ) ;
V_112 = F_6 ( V_81 ) ;
V_113 = V_112 | V_114 ;
if ( ! V_115 )
V_113 |= V_116 ;
if ( V_112 & V_117 )
V_113 |= V_118 ;
if ( V_112 & V_119 )
V_113 |= V_120 ;
F_19 ( ( V_112 & ( V_121 | V_122 ) ) &
V_123 , V_81 ) ;
F_19 ( ( V_112 & V_124 ) & V_123 , V_81 ) ;
F_25 ( V_2 ) ;
F_32 ( V_4 -> V_125 , V_126 ) ;
F_9 ( V_127 , V_128 ) ;
F_9 ( V_129 , V_130 ) ;
F_9 ( V_131 , V_132 ) ;
F_9 ( V_133 , V_134 ) ;
F_9 ( V_135 , V_136 ) ;
F_9 ( V_137 , V_138 ) ;
F_32 ( ( V_139 | V_140 |
V_141 | V_142 |
V_143 | V_144 |
V_145 | V_146 ) , V_147 ) ;
F_32 ( V_148 , V_149 ) ;
F_32 ( V_150 , V_151 ) ;
F_32 ( F_33 ( V_152 ) | 0x0200 , V_152 ) ;
F_32 ( F_33 ( V_152 ) | 0x0010 , V_152 ) ;
F_32 ( F_33 ( V_152 ) | 0x0020 , V_152 ) ;
F_19 ( V_123 & V_113 , V_81 ) ;
F_19 ( V_153 , V_154 ) ;
F_19 ( V_155 | V_156 |
V_157 | V_158 |
V_159 | V_160 |
V_161 |
V_162 | V_163 |
V_164 , V_165 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_166 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_167 * V_168 = V_4 -> V_14 + V_166 ;
struct V_169 * V_170 ;
T_5 V_171 ;
F_4 ( L_32 ) ;
V_170 = F_35 ( V_2 , V_4 -> V_172 ) ;
if ( ! V_170 ) {
V_4 -> V_173 [ V_166 ] = NULL ;
return - V_174 ;
}
V_4 -> V_173 [ V_166 ] = V_170 ;
V_168 -> V_17 = F_36 ( F_37 ( V_4 -> V_175 , V_170 -> V_26 ,
V_4 -> V_176 , V_177 ) ) ;
V_171 = V_4 -> V_178 ;
V_168 -> V_17 |= F_36 ( ( V_171 << 48 ) & V_179 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
unsigned int V_6 ;
F_4 ( L_33 ) ;
for ( V_6 = 0 ; V_6 < V_13 ; V_6 ++ ) {
struct V_167 * V_168 = V_4 -> V_14 + V_6 ;
if ( V_4 -> V_173 [ V_6 ] ) {
F_39 ( V_4 -> V_175 ,
F_40 ( V_168 -> V_17 ) & ~ V_179 ,
V_4 -> V_176 , V_177 ) ;
F_41 ( V_4 -> V_173 [ V_6 ] ) ;
V_4 -> V_173 [ V_6 ] = NULL ;
}
V_168 -> V_16 = 0x0000000000000000 ;
if ( F_34 ( V_2 , V_6 ) < 0 ) {
F_4 ( L_34 ) ;
if ( V_6 == 0 ) {
F_42 ( V_2 , L_35 ) ;
return - V_174 ;
}
}
V_168 -> V_15 = F_36 ( V_4 -> V_10 +
sizeof( struct V_167 ) * ( V_6 + 1 ) ) ;
}
V_4 -> V_14 [ V_6 - 1 ] . V_15 = F_36 ( V_4 -> V_10 ) ;
V_4 -> V_8 = 0 ;
V_4 -> V_9 = 0 ;
F_19 ( ( T_2 ) V_4 -> V_10 , V_180 ) ;
F_19 ( 0x00000000 , V_181 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
unsigned int V_6 ;
F_4 ( L_36 ) ;
for ( V_6 = 0 ; V_6 < V_23 ; V_6 ++ ) {
struct V_182 * V_183 = V_4 -> V_24 + V_6 ;
V_183 -> V_25 = F_36 ( V_184 ) ;
if ( V_4 -> V_185 [ V_6 ] ) {
F_41 ( V_4 -> V_185 [ V_6 ] ) ;
V_4 -> V_185 [ V_6 ] = NULL ;
}
V_183 -> V_15 = F_36 ( V_4 -> V_20 +
sizeof( struct V_182 ) * ( V_6 + 1 ) ) ;
}
V_4 -> V_24 [ V_6 - 1 ] . V_15 = F_36 ( V_4 -> V_20 ) ;
V_4 -> V_18 = 0 ;
V_4 -> V_19 = 0 ;
F_44 ( L_37 ,
( T_2 ) V_4 -> V_20 ) ;
F_19 ( ( T_2 ) V_4 -> V_20 , V_186 ) ;
F_19 ( 0x00000000 , V_187 ) ;
V_4 -> V_188 = 1 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_189 , V_190 , V_191 ;
F_4 ( L_38 ) ;
V_190 = V_4 -> V_18 - V_4 -> V_19 ;
V_191 = V_4 -> V_19 % V_23 ;
for ( V_189 = 0 ; V_189 < V_190 ; V_189 ++ ) {
struct V_169 * V_170 = V_4 -> V_185 [ V_191 ] ;
struct V_182 * V_183 = V_4 -> V_24 + V_191 ;
F_4 ( L_39 , ( unsigned long ) V_183 -> V_25 ) ;
if ( ! ( V_183 -> V_25 & F_36 ( V_184 ) ) )
break;
if ( V_170 ) {
F_39 ( V_4 -> V_175 ,
F_40 ( V_183 -> V_17 ) & ~ V_192 ,
V_170 -> V_39 , V_193 ) ;
F_41 ( V_170 ) ;
V_4 -> V_185 [ V_191 ] = NULL ;
}
V_191 = ( V_191 + 1 ) % V_23 ;
}
V_4 -> V_19 += V_189 ;
if ( F_46 ( V_2 ) &&
( V_4 -> V_18 != ( V_4 -> V_19 + V_23 ) ) ) {
F_47 ( V_2 ) ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
F_21 ( V_2 , V_194 | V_195 | V_196 |
V_197 ) ;
F_49 ( & V_4 -> V_198 ) ;
if ( F_31 ( V_2 ) < 0 )
F_5 ( V_2 , L_40 ) ;
F_43 ( V_2 ) ;
F_50 ( & V_4 -> V_198 ) ;
F_19 ( ( F_6 ( V_81 ) | V_118 ) & V_123 ,
V_81 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
unsigned int V_6 ;
F_4 ( L_41 ) ;
for ( V_6 = 0 ; V_6 < V_23 ; V_6 ++ ) {
T_2 V_199 = F_6 ( V_200 ) ;
F_4 ( L_42 , V_199 ) ;
if ( ! ( V_199 & V_201 ) )
break;
if ( V_4 -> V_82 ) {
F_47 ( V_2 ) ;
}
if ( V_199 & V_202 ) {
F_4 ( L_43 ) ;
V_4 -> V_203 . V_204 ++ ;
}
if ( V_199 & V_205 ) {
F_4 ( L_44 ) ;
F_19 ( ( F_6 ( V_81 ) | V_118 ) &
V_123 , V_81 ) ;
}
if ( V_199 & V_206 ) {
F_4 ( L_45 ) ;
F_19 ( ( F_6 ( V_81 ) | V_118 ) &
V_123 , V_81 ) ;
}
if ( V_199 & V_207 ) {
F_4 ( L_46 ) ;
V_4 -> V_203 . V_208 ++ ;
F_21 ( V_2 , V_194 | V_195 |
V_196 | V_197 ) ;
if ( F_31 ( V_2 ) < 0 ) {
F_5 ( V_2 , L_40 ) ;
}
F_43 ( V_2 ) ;
F_19 ( ( F_6 ( V_81 ) | V_118 ) &
V_123 , V_81 ) ;
}
}
F_45 ( V_2 ) ;
}
static struct V_209 * F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
T_4 V_210 ;
T_4 V_211 ;
F_4 ( L_47 ) ;
if ( ! F_53 ( V_212 , & V_2 -> V_213 ) )
return & V_4 -> V_203 ;
V_4 -> V_203 . V_214 += F_6 ( V_215 ) ;
V_4 -> V_203 . V_216 += F_6 ( V_217 ) ;
V_4 -> V_203 . V_218 += F_6 ( V_219 ) ;
V_4 -> V_203 . V_220 += F_6 ( V_221 ) ;
V_210 = F_33 ( V_222 ) ;
V_4 -> V_203 . V_223 += V_210 ;
V_4 -> V_203 . V_224 += V_210 ;
V_210 = F_6 ( V_225 ) + F_6 ( V_226 ) +
F_6 ( V_227 ) ;
V_211 = F_33 ( V_228 ) ;
V_4 -> V_203 . V_229 += V_210 ;
V_4 -> V_203 . V_230 += F_33 ( V_231 ) ;
V_4 -> V_203 . V_204 += F_33 ( V_232 ) +
F_6 ( V_233 ) + V_210 + V_211 ;
V_4 -> V_203 . V_234 += F_6 ( V_235 ) ;
V_4 -> V_203 . V_236 += V_211 ;
V_4 -> V_203 . V_237 += F_33 ( V_238 ) +
F_33 ( V_239 ) ;
V_4 -> V_203 . V_240 += F_33 ( V_241 ) ;
F_6 ( V_242 ) ;
return & V_4 -> V_203 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const unsigned int V_243 = V_4 -> V_8 ;
unsigned int V_191 = V_4 -> V_9 ;
F_4 ( L_48 ) ;
for ( V_191 = V_4 -> V_9 ; V_243 - V_191 > 0 ; V_191 ++ ) {
unsigned int V_166 = V_191 % V_13 ;
if ( V_4 -> V_173 [ V_166 ] )
continue;
if ( F_34 ( V_2 , V_166 ) < 0 ) {
F_4 ( L_49 ) ;
break;
}
V_4 -> V_14 [ V_166 ] . V_16 = 0x0000000000000000 ;
}
V_4 -> V_9 = V_191 ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_166 = V_4 -> V_8 % V_13 ;
if ( V_4 -> V_173 [ V_166 ] ) {
struct V_167 * V_168 = V_4 -> V_14 + V_166 ;
F_39 ( V_4 -> V_175 ,
F_40 ( V_168 -> V_17 ) & ~ V_179 ,
V_4 -> V_176 , V_177 ) ;
F_41 ( V_4 -> V_173 [ V_166 ] ) ;
V_4 -> V_173 [ V_166 ] = NULL ;
}
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_167 * V_168 = V_4 -> V_14 + ( V_4 -> V_8 % V_13 ) ;
int type = V_244 ;
if ( F_40 ( V_168 -> V_16 ) & V_245 )
type += V_246 ;
if ( F_40 ( V_168 -> V_16 ) & V_247 )
type += V_248 ;
return type ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_166 = V_4 -> V_8 % V_13 ;
struct V_167 * V_168 = V_4 -> V_14 + V_166 ;
if ( V_249 && ( F_40 ( V_168 -> V_16 ) &
( V_250 | V_251 |
V_252 | V_253 |
V_254 | V_255 ) ) ) {
F_4 ( L_50 ,
( unsigned long ) V_168 -> V_16 ) ;
V_4 -> V_203 . V_223 ++ ;
if ( F_40 ( V_168 -> V_16 ) & V_250 ) {
F_4 ( L_51 ) ;
V_4 -> V_203 . V_256 ++ ;
}
if ( F_40 ( V_168 -> V_16 ) & V_251 ) {
F_4 ( L_52 ) ;
V_4 -> V_203 . V_237 ++ ;
}
if ( F_40 ( V_168 -> V_16 ) & V_252 ) {
F_4 ( L_53 ) ;
V_4 -> V_203 . V_257 ++ ;
}
if ( V_4 -> V_173 [ V_166 ] ) {
F_39 ( V_4 -> V_175 ,
F_40 ( V_168 -> V_17 ) & ~ V_179 ,
V_4 -> V_176 , V_177 ) ;
F_41 ( V_4 -> V_173 [ V_166 ] ) ;
V_4 -> V_173 [ V_166 ] = NULL ;
}
return V_258 ;
}
return V_259 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_167 * V_168 , unsigned V_166 )
{
struct V_260 * V_261 = & V_4 -> V_261 ;
struct V_169 * V_170 ;
int V_262 ;
if ( V_261 -> V_263 ) {
F_41 ( V_261 -> V_170 ) ;
V_261 -> V_263 = 0 ;
V_261 -> V_264 = 0 ;
V_261 -> V_170 = NULL ;
}
if ( F_57 ( V_2 ) != V_259 )
return;
V_170 = V_4 -> V_173 [ V_166 ] ;
if ( ! V_170 )
return;
V_262 = F_40 ( V_168 -> V_16 ) & V_265 ;
if ( V_262 > V_4 -> V_178 )
V_262 = V_4 -> V_178 ;
F_59 ( V_170 , V_262 ) ;
V_170 -> V_266 = F_60 ( V_170 , V_2 ) ;
F_61 ( V_170 ) ;
F_62 ( V_170 ) ;
V_4 -> V_173 [ V_166 ] = NULL ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_167 * V_168 , unsigned V_166 )
{
struct V_260 * V_261 = & V_4 -> V_261 ;
struct V_267 * V_175 = V_4 -> V_175 ;
struct V_169 * V_170 ;
if ( F_57 ( V_2 ) != V_259 )
return;
V_170 = V_4 -> V_173 [ V_166 ] ;
if ( ! V_170 )
return;
if ( V_261 -> V_263 )
F_41 ( V_261 -> V_170 ) ;
F_39 ( V_175 , F_40 ( V_168 -> V_17 ) & ~ V_179 ,
V_4 -> V_176 , V_177 ) ;
F_59 ( V_170 , V_4 -> V_178 ) ;
V_261 -> V_263 = 1 ;
V_261 -> V_264 = V_4 -> V_178 ;
V_261 -> V_170 = V_170 ;
V_4 -> V_173 [ V_166 ] = NULL ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_167 * V_168 , unsigned V_166 )
{
struct V_260 * V_261 = & V_4 -> V_261 ;
if ( F_57 ( V_2 ) == V_259 ) {
struct V_169 * V_170 = V_4 -> V_173 [ V_166 ] ;
if ( ! V_170 )
return;
if ( V_261 -> V_263 ) {
int V_262 , V_268 ;
V_262 = F_40 ( V_168 -> V_16 ) & V_265 ;
V_268 = V_262 - V_261 -> V_264 ;
if ( V_262 > V_4 -> V_172 )
F_41 ( V_261 -> V_170 ) ;
else {
memcpy ( F_59 ( V_261 -> V_170 , V_268 ) ,
V_170 -> V_26 , V_268 ) ;
V_261 -> V_170 -> V_266 =
F_60 ( V_261 -> V_170 , V_2 ) ;
F_61 ( V_261 -> V_170 ) ;
F_62 ( V_261 -> V_170 ) ;
}
}
V_261 -> V_263 = 0 ;
V_261 -> V_264 = 0 ;
V_261 -> V_170 = NULL ;
F_55 ( V_2 ) ;
} else {
F_41 ( V_261 -> V_170 ) ;
V_261 -> V_263 = 0 ;
V_261 -> V_264 = 0 ;
V_261 -> V_170 = NULL ;
}
}
static void F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_167 * V_168 , unsigned V_166 )
{
struct V_260 * V_261 = & V_4 -> V_261 ;
if ( F_57 ( V_2 ) == V_259 ) {
struct V_169 * V_170 = V_4 -> V_173 [ V_166 ] ;
if ( V_170 ) {
if ( V_261 -> V_263 ) {
V_261 -> V_264 += V_4 -> V_178 ;
if ( V_261 -> V_264 <= V_4 -> V_172 ) {
memcpy ( F_59 ( V_261 -> V_170 ,
V_4 -> V_178 ) ,
V_170 -> V_26 , V_4 -> V_178 ) ;
}
}
F_55 ( V_2 ) ;
}
} else {
F_41 ( V_261 -> V_170 ) ;
V_261 -> V_263 = 0 ;
V_261 -> V_264 = 0 ;
V_261 -> V_170 = NULL ;
}
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_243 = V_4 -> V_8 ;
void T_1 * V_5 = V_4 -> V_5 ;
unsigned int V_6 ;
F_4 ( L_54 ) ;
for ( V_6 = 0 ; V_6 < V_269 ; V_6 ++ , V_243 ++ ) {
unsigned int V_166 = V_243 % V_13 ;
struct V_167 * V_168 = V_4 -> V_14 + V_166 ;
if ( ! ( V_168 -> V_16 & F_36 ( V_270 ) ) )
break;
switch ( F_56 ( V_2 ) ) {
case V_271 :
F_58 ( V_2 , V_4 , V_168 , V_166 ) ;
break;
case V_246 :
F_63 ( V_2 , V_4 , V_168 , V_166 ) ;
break;
case V_248 :
F_64 ( V_2 , V_4 , V_168 , V_166 ) ;
break;
case V_244 :
F_65 ( V_2 , V_4 , V_168 , V_166 ) ;
break;
}
}
V_4 -> V_8 = V_243 ;
if ( V_6 == V_269 ) {
F_19 ( F_6 ( V_51 ) | V_272 , V_51 ) ;
}
F_54 ( V_2 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_243 = V_4 -> V_8 ;
void T_1 * V_5 = V_4 -> V_5 ;
struct V_167 * V_168 ;
unsigned int V_6 ;
F_4 ( L_54 ) ;
#define F_68 \
cpu_to_le64(IPG_RFS_RFDDONE | IPG_RFS_FRAMESTART | IPG_RFS_FRAMEEND)
for ( V_6 = 0 ; V_6 < V_269 ; V_6 ++ , V_243 ++ ) {
unsigned int V_166 = V_243 % V_13 ;
struct V_169 * V_170 = V_4 -> V_173 [ V_166 ] ;
unsigned int V_262 ;
V_168 = V_4 -> V_14 + V_166 ;
if ( ( ( V_168 -> V_16 & F_68 ) != F_68 ) || ! V_170 )
break;
V_262 = F_40 ( V_168 -> V_16 ) & V_265 ;
if ( V_262 > V_4 -> V_178 ) {
F_4
( L_55 ) ;
V_262 = V_4 -> V_178 ;
}
if ( ( V_249 && ( F_40 ( V_168 -> V_16 ) &
( V_250 | V_251 |
V_252 | V_253 |
V_254 | V_255 ) ) ) ) {
F_4 ( L_50 ,
( unsigned long int ) V_168 -> V_16 ) ;
V_4 -> V_203 . V_223 ++ ;
if ( F_40 ( V_168 -> V_16 ) & V_250 ) {
F_4 ( L_51 ) ;
V_4 -> V_203 . V_256 ++ ;
}
if ( F_40 ( V_168 -> V_16 ) & V_251 ) {
F_4 ( L_52 ) ;
V_4 -> V_203 . V_237 ++ ;
}
if ( F_40 ( V_168 -> V_16 ) & V_254 ) ;
if ( F_40 ( V_168 -> V_16 ) & V_252 ) {
F_4 ( L_53 ) ;
V_4 -> V_203 . V_257 ++ ;
}
if ( F_40 ( V_168 -> V_16 ) & V_253 ) ;
if ( V_170 ) {
T_6 V_273 = V_168 -> V_17 ;
F_39 ( V_4 -> V_175 ,
F_40 ( V_273 ) & ~ V_179 ,
V_4 -> V_176 , V_177 ) ;
F_41 ( V_170 ) ;
}
} else {
F_59 ( V_170 , V_262 ) ;
V_170 -> V_266 = F_60 ( V_170 , V_2 ) ;
F_61 ( V_170 ) ;
F_62 ( V_170 ) ;
}
V_4 -> V_173 [ V_166 ] = NULL ;
}
if ( V_6 == V_269 )
F_19 ( F_6 ( V_51 ) | V_272 , V_51 ) ;
#ifdef F_69
if ( ! V_6 )
V_4 -> V_274 ++ ;
#endif
while ( ( F_40 ( V_168 -> V_16 ) & V_270 ) &&
! ( ( F_40 ( V_168 -> V_16 ) & V_245 ) &&
( F_40 ( V_168 -> V_16 ) & V_247 ) ) ) {
unsigned int V_166 = V_243 ++ % V_13 ;
V_168 = V_4 -> V_14 + V_166 ;
F_4 ( L_56 ) ;
if ( V_4 -> V_173 [ V_166 ] ) {
F_39 ( V_4 -> V_175 ,
F_40 ( V_168 -> V_17 ) & ~ V_179 ,
V_4 -> V_176 , V_177 ) ;
F_41 ( V_4 -> V_173 [ V_166 ] ) ;
}
V_4 -> V_173 [ V_166 ] = NULL ;
}
V_4 -> V_8 = V_243 ;
if ( ( V_243 - V_4 -> V_9 ) >= V_275 )
F_54 ( V_2 ) ;
return 0 ;
}
static void F_70 ( struct V_276 * V_277 )
{
struct V_3 * V_4 =
F_71 ( V_277 , struct V_3 , V_278 . V_277 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_21 ( V_2 , V_279 | V_280 | V_195 ) ;
F_38 ( V_2 ) ;
F_43 ( V_2 ) ;
if ( F_31 ( V_2 ) < 0 ) {
F_5 ( V_2 , L_57 ) ;
F_72 ( & V_4 -> V_278 , V_281 ) ;
}
}
static T_7 F_73 ( int V_282 , void * V_283 )
{
struct V_1 * V_2 = V_283 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
unsigned int V_284 = 0 ;
T_4 V_68 ;
F_4 ( L_58 ) ;
if ( V_4 -> V_285 )
F_54 ( V_2 ) ;
F_74 ( & V_4 -> V_198 ) ;
V_68 = F_33 ( V_286 ) ;
F_4 ( L_59 , V_68 ) ;
if ( ! ( V_68 & V_287 ) )
goto V_288;
V_284 = 1 ;
if ( F_75 ( ! F_76 ( V_2 ) ) )
goto V_289;
if ( V_68 & V_290 ) {
F_4 ( L_60 ) ;
F_54 ( V_2 ) ;
#ifdef F_69
V_4 -> V_291 ++ ;
#endif
}
if ( ( V_68 & V_292 ) ||
( V_68 & V_290 ) ||
( V_68 & V_293 ) ||
( V_68 & V_294 ) ) {
#ifdef F_69
if ( V_68 & ( ~ ( V_292 | V_290 |
V_293 | V_294 ) &
( V_295 | V_296 |
V_297 | V_298 |
V_299 ) ) )
V_4 -> V_300 ++ ;
#endif
if ( V_4 -> V_285 )
F_66 ( V_2 ) ;
else
F_67 ( V_2 ) ;
}
if ( V_68 & V_296 )
F_45 ( V_2 ) ;
if ( V_68 & V_298 )
F_51 ( V_2 ) ;
if ( V_68 & V_299 )
F_52 ( V_2 ) ;
if ( V_68 & V_295 ) {
F_44 ( L_61 ) ;
F_72 ( & V_4 -> V_278 , 0 ) ;
}
if ( V_68 & V_297 ) {
if ( F_24 ( V_2 ) < 0 )
F_5 ( V_2 , L_62 ) ;
}
if ( V_68 & V_301 )
F_4 ( L_63 ) ;
if ( V_68 & V_302 )
F_4 ( L_64 ) ;
if ( V_68 & V_303 )
F_4 ( L_65 ) ;
V_288:
F_32 ( V_140 | V_145 |
V_139 | V_142 | V_141 |
V_144 | V_143 , V_147 ) ;
V_289:
F_77 ( & V_4 -> V_198 ) ;
return F_78 ( V_284 ) ;
}
static void F_79 ( struct V_3 * V_4 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_13 ; V_6 ++ ) {
if ( V_4 -> V_173 [ V_6 ] ) {
struct V_167 * V_168 = V_4 -> V_14 + V_6 ;
F_41 ( V_4 -> V_173 [ V_6 ] ) ;
V_4 -> V_173 [ V_6 ] = NULL ;
F_39 ( V_4 -> V_175 ,
F_40 ( V_168 -> V_17 ) & ~ V_179 ,
V_4 -> V_176 , V_177 ) ;
}
}
}
static void F_80 ( struct V_3 * V_4 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_23 ; V_6 ++ ) {
if ( V_4 -> V_185 [ V_6 ] ) {
struct V_182 * V_183 = V_4 -> V_24 + V_6 ;
F_39 ( V_4 -> V_175 ,
F_40 ( V_183 -> V_17 ) & ~ V_192 ,
V_4 -> V_185 [ V_6 ] -> V_39 , V_193 ) ;
F_41 ( V_4 -> V_185 [ V_6 ] ) ;
V_4 -> V_185 [ V_6 ] = NULL ;
}
}
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
struct V_267 * V_175 = V_4 -> V_175 ;
int V_304 ;
F_4 ( L_66 ) ;
V_4 -> V_176 = V_4 -> V_172 ;
F_32 ( 0x0000 , V_147 ) ;
V_304 = F_82 ( V_175 -> V_282 , F_73 , V_305 ,
V_2 -> V_306 , V_2 ) ;
if ( V_304 < 0 ) {
F_5 ( V_2 , L_67 ) ;
goto V_307;
}
V_2 -> V_282 = V_175 -> V_282 ;
V_304 = - V_174 ;
V_4 -> V_14 = F_83 ( & V_175 -> V_2 , V_308 ,
& V_4 -> V_10 , V_309 ) ;
if ( ! V_4 -> V_14 )
goto V_310;
V_4 -> V_24 = F_83 ( & V_175 -> V_2 , V_311 ,
& V_4 -> V_20 , V_309 ) ;
if ( ! V_4 -> V_24 )
goto V_312;
V_304 = F_38 ( V_2 ) ;
if ( V_304 < 0 ) {
F_5 ( V_2 , L_68 ) ;
goto V_313;
}
F_43 ( V_2 ) ;
V_304 = F_31 ( V_2 ) ;
if ( V_304 < 0 ) {
F_5 ( V_2 , L_68 ) ;
goto V_314;
}
if ( F_24 ( V_2 ) < 0 )
F_5 ( V_2 , L_62 ) ;
V_4 -> V_261 . V_263 = 0 ;
V_4 -> V_261 . V_264 = 0 ;
V_4 -> V_261 . V_170 = NULL ;
F_19 ( ( F_6 ( V_81 ) | V_120 | V_118 ) &
V_123 , V_81 ) ;
F_84 ( V_2 ) ;
V_307:
return V_304 ;
V_314:
F_80 ( V_4 ) ;
F_79 ( V_4 ) ;
V_313:
F_85 ( & V_175 -> V_2 , V_311 , V_4 -> V_24 , V_4 -> V_20 ) ;
V_312:
F_85 ( & V_175 -> V_2 , V_308 , V_4 -> V_14 , V_4 -> V_10 ) ;
V_310:
F_86 ( V_175 -> V_282 , V_2 ) ;
goto V_307;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
struct V_267 * V_175 = V_4 -> V_175 ;
F_4 ( L_69 ) ;
F_88 ( V_2 ) ;
F_89 ( V_2 ) ;
do {
( void ) F_33 ( V_286 ) ;
F_21 ( V_2 , V_279 | V_280 | V_195 ) ;
F_90 ( V_175 -> V_282 ) ;
} while ( F_33 ( V_147 ) & V_315 );
F_79 ( V_4 ) ;
F_80 ( V_4 ) ;
F_91 ( V_175 , V_308 , V_4 -> V_14 , V_4 -> V_10 ) ;
F_91 ( V_175 , V_311 , V_4 -> V_24 , V_4 -> V_20 ) ;
F_86 ( V_175 -> V_282 , V_2 ) ;
return 0 ;
}
static T_8 F_92 ( struct V_169 * V_170 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
unsigned int V_166 = V_4 -> V_18 % V_23 ;
unsigned long V_98 ;
struct V_182 * V_183 ;
F_44 ( L_70 ) ;
if ( V_4 -> V_82 )
F_88 ( V_2 ) ;
if ( V_4 -> V_188 ) {
V_4 -> V_188 = 0 ;
V_166 = 0 ;
}
V_183 = V_4 -> V_24 + V_166 ;
V_4 -> V_185 [ V_166 ] = V_170 ;
V_183 -> V_25 = F_36 ( V_184 ) ;
V_183 -> V_25 |= F_36 ( V_316 |
( V_317 & V_4 -> V_18 ) |
( V_318 & ( 1 << 24 ) ) ) ;
if ( V_4 -> V_82 )
V_183 -> V_25 |= F_36 ( V_319 ) ;
V_183 -> V_25 |= F_36 ( V_320 ) ;
if ( ! ( V_321 ) )
V_183 -> V_25 |= F_36 ( V_322 ) ;
if ( V_323 )
V_183 -> V_25 |= F_36 ( V_324 ) ;
if ( V_325 )
V_183 -> V_25 |= F_36 ( V_326 ) ;
if ( V_327 )
V_183 -> V_25 |= F_36 ( V_328 ) ;
if ( V_329 ) {
V_183 -> V_25 |= F_36 ( V_330 |
( ( T_5 ) V_331 << 32 ) |
( ( T_5 ) V_332 << 44 ) |
( ( T_5 ) V_333 << 45 ) ) ;
}
V_183 -> V_17 = F_36 ( F_37 ( V_4 -> V_175 , V_170 -> V_26 ,
V_170 -> V_39 , V_193 ) ) ;
V_183 -> V_17 |= F_36 ( V_192 &
( ( T_5 ) ( V_170 -> V_39 & 0xffff ) << 48 ) ) ;
V_183 -> V_25 &= F_36 ( ~ V_184 ) ;
F_93 ( & V_4 -> V_198 , V_98 ) ;
V_4 -> V_18 ++ ;
F_94 () ;
F_19 ( V_334 , V_335 ) ;
if ( V_4 -> V_18 == ( V_4 -> V_19 + V_23 ) )
F_88 ( V_2 ) ;
F_95 ( & V_4 -> V_198 , V_98 ) ;
return V_336 ;
}
static void F_96 ( unsigned char V_337 ,
struct V_1 * V_2 , int V_338 )
{
unsigned short V_339 ;
unsigned char V_340 ;
const unsigned short * V_341 ;
unsigned short V_342 , V_343 ;
V_341 = & V_344 [ 0 ] ;
V_339 = * V_341 & 0x00FF ;
V_340 = ( unsigned char ) ( ( * V_341 ) >> 8 ) ;
V_341 ++ ;
while ( V_339 != 0 ) {
if ( V_337 == V_340 ) {
while ( V_339 > 1 ) {
V_342 = * V_341 ;
V_343 = * ( V_341 + 1 ) ;
V_341 += 2 ;
F_17 ( V_2 , V_338 , V_342 , V_343 ) ;
V_339 -= 4 ;
}
break;
} else {
V_341 += V_339 / 2 ;
V_339 = * V_341 & 0x00FF ;
V_340 = ( unsigned char ) ( ( * V_341 ) >> 8 ) ;
V_341 ++ ;
}
}
}
static int F_97 ( struct V_1 * V_2 , int V_345 )
{
void T_1 * V_5 = F_1 ( V_2 ) ;
unsigned int V_6 ;
int V_346 = 0 ;
T_4 V_343 ;
V_343 = V_347 | ( V_345 & 0xff ) ;
F_32 ( V_343 , V_348 ) ;
for ( V_6 = 0 ; V_6 < 1000 ; V_6 ++ ) {
T_4 V_26 ;
F_22 ( 10 ) ;
V_26 = F_33 ( V_348 ) ;
if ( ! ( V_26 & V_349 ) ) {
V_346 = F_33 ( V_350 ) ;
break;
}
}
return V_346 ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_351 * V_352 = & V_4 -> V_352 ;
int V_67 ;
V_352 -> V_2 = V_2 ;
V_352 -> F_16 = F_16 ;
V_352 -> F_17 = F_17 ;
V_352 -> V_353 = 0x1f ;
V_352 -> V_354 = 0x1f ;
V_352 -> V_36 = V_67 = F_23 ( V_2 ) ;
if ( V_67 != 0x1f ) {
T_4 V_355 , V_356 ;
V_356 = F_16 ( V_2 , V_67 , V_357 ) ;
V_356 |= V_358 | V_359 |
V_360 ;
F_17 ( V_2 , V_67 , V_357 , V_356 ) ;
V_355 = F_16 ( V_2 , V_67 , V_361 ) ;
F_96 ( V_4 -> V_175 -> V_340 , V_2 , V_67 ) ;
V_355 |= V_362 | V_363 ;
F_17 ( V_2 , V_67 , V_361 , V_355 ) ;
}
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
unsigned int V_6 ;
int V_304 ;
V_4 -> V_55 = F_97 ( V_2 , 6 ) ;
V_304 = F_21 ( V_2 , V_364 ) ;
if ( V_304 < 0 )
goto V_307;
F_98 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ )
V_4 -> V_365 [ V_6 ] = F_97 ( V_2 , 16 + V_6 ) ;
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ )
F_32 ( V_4 -> V_365 [ V_6 ] , V_366 + 2 * V_6 ) ;
V_2 -> V_367 [ 0 ] = F_33 ( V_366 ) & 0x00ff ;
V_2 -> V_367 [ 1 ] = ( F_33 ( V_366 ) & 0xff00 ) >> 8 ;
V_2 -> V_367 [ 2 ] = F_33 ( V_368 ) & 0x00ff ;
V_2 -> V_367 [ 3 ] = ( F_33 ( V_368 ) & 0xff00 ) >> 8 ;
V_2 -> V_367 [ 4 ] = F_33 ( V_369 ) & 0x00ff ;
V_2 -> V_367 [ 5 ] = ( F_33 ( V_369 ) & 0xff00 ) >> 8 ;
V_307:
return V_304 ;
}
static int F_100 ( struct V_1 * V_2 , struct V_370 * V_371 , int V_372 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_304 ;
F_101 ( & V_4 -> V_373 ) ;
V_304 = F_102 ( & V_4 -> V_352 , F_103 ( V_371 ) , V_372 , NULL ) ;
F_104 ( & V_4 -> V_373 ) ;
return V_304 ;
}
static int F_105 ( struct V_1 * V_2 , int V_374 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_375 ;
F_4 ( L_71 ) ;
if ( V_374 < 68 || V_374 > 10240 )
return - V_376 ;
V_375 = F_87 ( V_2 ) ;
if ( V_375 )
return V_375 ;
V_2 -> V_377 = V_374 ;
V_4 -> V_125 = V_374 ;
V_4 -> V_178 = V_374 ;
if ( V_4 -> V_178 > 4088 )
V_4 -> V_178 = 4088 ;
V_4 -> V_172 = V_4 -> V_125 ;
if ( V_374 > 0x0600 )
V_4 -> V_285 = true ;
else
V_4 -> V_285 = false ;
return F_81 ( V_2 ) ;
}
static int F_106 ( struct V_1 * V_2 , struct V_378 * V_372 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_304 ;
F_101 ( & V_4 -> V_373 ) ;
V_304 = F_107 ( & V_4 -> V_352 , V_372 ) ;
F_104 ( & V_4 -> V_373 ) ;
return V_304 ;
}
static int F_108 ( struct V_1 * V_2 , struct V_378 * V_372 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_304 ;
F_101 ( & V_4 -> V_373 ) ;
V_304 = F_109 ( & V_4 -> V_352 , V_372 ) ;
F_104 ( & V_4 -> V_373 ) ;
return V_304 ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_304 ;
F_101 ( & V_4 -> V_373 ) ;
V_304 = F_111 ( & V_4 -> V_352 ) ;
F_104 ( & V_4 -> V_373 ) ;
return V_304 ;
}
static void F_112 ( struct V_267 * V_175 )
{
struct V_1 * V_2 = F_113 ( V_175 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_4 ( L_72 ) ;
F_114 ( V_2 ) ;
F_115 ( V_175 , V_4 -> V_5 ) ;
F_116 ( V_175 ) ;
F_117 ( V_2 ) ;
F_118 ( V_175 ) ;
F_119 ( V_175 , NULL ) ;
}
static int F_120 ( struct V_267 * V_175 , const struct V_379 * V_380 )
{
unsigned int V_6 = V_380 -> V_381 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
void T_1 * V_5 ;
int V_304 ;
V_304 = F_121 ( V_175 ) ;
if ( V_304 < 0 )
goto V_307;
F_122 ( L_73 , F_123 ( V_175 ) , V_382 [ V_6 ] ) ;
F_124 ( V_175 ) ;
V_304 = F_125 ( V_175 , F_126 ( 40 ) ) ;
if ( V_304 < 0 ) {
V_304 = F_125 ( V_175 , F_126 ( 32 ) ) ;
if ( V_304 < 0 ) {
F_127 ( L_74 , F_123 ( V_175 ) ) ;
goto V_383;
}
}
V_2 = F_128 ( sizeof( struct V_3 ) ) ;
if ( ! V_2 ) {
V_304 = - V_174 ;
goto V_383;
}
V_4 = F_2 ( V_2 ) ;
F_129 ( & V_4 -> V_198 ) ;
F_130 ( & V_4 -> V_373 ) ;
V_4 -> V_285 = V_384 ;
V_4 -> V_178 = V_385 ;
V_4 -> V_172 = V_386 ;
V_4 -> V_125 = V_387 ;
V_2 -> V_388 = & V_389 ;
F_131 ( V_2 , & V_175 -> V_2 ) ;
F_132 ( V_2 , & V_390 ) ;
V_304 = F_133 ( V_175 , V_391 ) ;
if ( V_304 )
goto V_392;
V_5 = F_134 ( V_175 , 1 , F_135 ( V_175 , 1 ) ) ;
if ( ! V_5 ) {
F_127 ( L_75 , F_123 ( V_175 ) ) ;
V_304 = - V_393 ;
goto V_394;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_175 = V_175 ;
V_4 -> V_2 = V_2 ;
F_136 ( & V_4 -> V_278 , F_70 ) ;
F_119 ( V_175 , V_2 ) ;
V_304 = F_99 ( V_2 ) ;
if ( V_304 < 0 )
goto V_395;
V_304 = F_137 ( V_2 ) ;
if ( V_304 < 0 )
goto V_395;
F_5 ( V_2 , L_76 ) ;
V_307:
return V_304 ;
V_395:
F_115 ( V_175 , V_5 ) ;
V_394:
F_116 ( V_175 ) ;
V_392:
F_117 ( V_2 ) ;
V_383:
F_118 ( V_175 ) ;
goto V_307;
}
static int T_9 F_138 ( void )
{
return F_139 ( & V_396 ) ;
}
static void T_10 F_140 ( void )
{
F_141 ( & V_396 ) ;
}
