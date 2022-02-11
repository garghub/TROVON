static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_7 , V_3 ) ;
( void ) F_4 ( V_7 ) ;
V_5 = F_4 ( V_8 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
return V_5 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_7 , V_3 ) ;
( void ) F_4 ( V_7 ) ;
F_3 ( V_8 , V_9 ) ;
( void ) F_4 ( V_8 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_11 , ( V_3 ) ) ;
V_5 = F_4 ( V_12 ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_11 , ( V_3 ) ) ;
F_3 ( V_12 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_13 , ( V_3 ) ) ;
V_5 = F_4 ( V_14 ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
return V_5 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_13 , ( V_3 ) ) ;
F_3 ( V_14 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_15 , V_4 ) ;
F_3 ( V_16 , ( ( V_3 ) & 0x1ff ) ) ;
V_5 = F_4 ( V_17 ) ;
F_5 ( & V_2 -> V_15 , V_4 ) ;
return V_5 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_15 , V_4 ) ;
F_3 ( V_16 , ( ( V_3 ) & 0x1ff ) ) ;
F_3 ( V_17 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_15 , V_4 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_18 , V_4 ) ;
F_3 ( V_19 , ( V_3 ) ) ;
V_5 = F_4 ( V_20 ) ;
F_5 ( & V_2 -> V_18 , V_4 ) ;
return V_5 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_18 , V_4 ) ;
F_3 ( V_19 , ( V_3 ) ) ;
F_3 ( V_20 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_18 , V_4 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_21 , V_4 ) ;
F_3 ( V_22 , ( V_3 ) ) ;
V_5 = F_4 ( V_23 ) ;
F_5 ( & V_2 -> V_21 , V_4 ) ;
return V_5 ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_21 , V_4 ) ;
F_3 ( V_22 , ( V_3 ) ) ;
F_3 ( V_23 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_21 , V_4 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_24 ) ;
switch ( V_2 -> V_25 ) {
case V_26 :
F_19 ( V_2 ,
V_27 ,
( const T_1 ) F_20 ( V_27 ) ) ;
break;
case V_28 :
F_19 ( V_2 ,
V_29 ,
( const T_1 ) F_20 ( V_29 ) ) ;
break;
case V_30 :
F_19 ( V_2 ,
V_31 ,
( const T_1 ) F_20 ( V_31 ) ) ;
break;
case V_32 :
F_19 ( V_2 ,
V_33 ,
( const T_1 ) F_20 ( V_33 ) ) ;
break;
case V_34 :
F_19 ( V_2 ,
V_35 ,
( const T_1 ) F_20 ( V_35 ) ) ;
break;
case V_36 :
case V_37 :
default:
break;
}
F_21 ( & V_2 -> V_24 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
T_1 V_38 = V_2 -> clock . V_39 . V_40 ;
T_1 V_41 ;
if ( V_2 -> V_4 & V_42 )
return V_38 ;
V_41 = F_23 ( V_43 ) ;
if ( F_24 ( V_41 , V_44 , V_45 ) )
return 1000 ;
V_41 = F_23 ( V_46 ) ;
if ( F_24 ( V_41 , V_47 , V_48 ) )
return V_38 / 4 ;
return V_38 ;
}
void F_25 ( struct V_1 * V_2 ,
T_1 V_49 , T_1 V_50 , T_1 V_51 , T_1 V_52 )
{
T_1 V_53 = 0 ;
V_53 = F_26 ( V_53 , V_54 , V_55 , V_50 ) ;
V_53 = F_26 ( V_53 , V_54 , V_56 , V_49 ) ;
V_53 = F_26 ( V_53 , V_54 , V_57 , V_52 ) ;
V_53 = F_26 ( V_53 , V_54 , V_58 , V_51 ) ;
F_3 ( V_59 , V_53 ) ;
}
static void F_27 ( struct V_1 * V_2 , bool V_60 )
{
}
static bool F_28 ( struct V_1 * V_2 )
{
T_1 V_61 ;
T_1 V_62 = 0 ;
T_1 V_63 = 0 ;
T_1 V_64 = 0 ;
T_1 V_65 ;
bool V_5 ;
V_61 = F_4 ( V_66 ) ;
if ( V_2 -> V_67 . V_68 ) {
V_62 = F_4 ( V_69 ) ;
V_63 = F_4 ( V_70 ) ;
V_64 = F_4 ( V_71 ) ;
}
V_65 = F_23 ( V_72 ) ;
F_3 ( V_66 , ( V_61 & ~ V_73 ) ) ;
if ( V_2 -> V_67 . V_68 ) {
F_3 ( V_69 ,
( V_62 & ~ ( V_74 |
V_75 ) ) ) ;
F_3 ( V_70 ,
( V_63 & ~ ( V_76 |
V_77 ) ) ) ;
F_3 ( V_71 ,
( V_64 & ~ V_78 ) ) ;
}
F_29 ( V_72 , V_65 | V_79 ) ;
V_5 = F_30 ( V_2 ) ;
F_3 ( V_66 , V_61 ) ;
if ( V_2 -> V_67 . V_68 ) {
F_3 ( V_69 , V_62 ) ;
F_3 ( V_70 , V_63 ) ;
F_3 ( V_71 , V_64 ) ;
}
F_29 ( V_72 , V_65 ) ;
return V_5 ;
}
static bool F_31 ( struct V_1 * V_2 ,
T_2 * V_80 , T_1 V_81 )
{
T_1 * V_82 ;
unsigned long V_4 ;
T_1 V_83 , V_84 ;
if ( V_80 == NULL )
return false ;
if ( V_81 == 0 )
return false ;
if ( V_2 -> V_4 & V_42 )
return false ;
V_82 = ( T_1 * ) V_80 ;
V_84 = F_32 ( V_81 , 4 ) / 4 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_11 , V_85 ) ;
F_3 ( V_12 , 0 ) ;
F_3 ( V_11 , V_86 ) ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ )
V_82 [ V_83 ] = F_4 ( V_12 ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
return true ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_3 V_3 = F_4 ( V_87 ) ;
if ( V_3 & 1 )
V_2 -> V_88 . V_89 |= V_90 ;
if ( V_3 & 0x80000000 )
V_2 -> V_88 . V_89 |= V_91 ;
if ( V_3 == 0 ) {
if ( F_34 () )
V_2 -> V_88 . V_89 |= V_92 ;
}
}
static T_3 F_35 ( struct V_1 * V_2 , T_1 V_93 ,
T_1 V_94 , T_1 V_95 )
{
T_3 V_96 ;
F_18 ( & V_2 -> V_24 ) ;
if ( V_93 != 0xffffffff || V_94 != 0xffffffff )
F_36 ( V_2 , V_93 , V_94 , 0xffffffff ) ;
V_96 = F_4 ( V_95 ) ;
if ( V_93 != 0xffffffff || V_94 != 0xffffffff )
F_36 ( V_2 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_21 ( & V_2 -> V_24 ) ;
return V_96 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_93 ,
T_1 V_94 , T_1 V_95 , T_1 * V_97 )
{
const struct V_98 * V_99 = NULL ;
const struct V_98 * V_100 ;
T_3 V_101 , V_83 ;
* V_97 = 0 ;
switch ( V_2 -> V_25 ) {
case V_26 :
V_99 = V_102 ;
V_101 = F_20 ( V_102 ) ;
break;
case V_28 :
case V_30 :
case V_36 :
case V_37 :
case V_32 :
case V_34 :
V_99 = V_103 ;
V_101 = F_20 ( V_103 ) ;
break;
default:
return - V_104 ;
}
if ( V_99 ) {
for ( V_83 = 0 ; V_83 < V_101 ; V_83 ++ ) {
V_100 = V_99 + V_83 ;
if ( V_95 != V_100 -> V_95 )
continue;
if ( ! V_100 -> V_105 )
* V_97 = V_100 -> V_106 ?
F_35 ( V_2 , V_93 ,
V_94 , V_95 ) :
F_4 ( V_95 ) ;
return 0 ;
}
}
for ( V_83 = 0 ; V_83 < F_20 ( V_107 ) ; V_83 ++ ) {
if ( V_95 != V_107 [ V_83 ] . V_95 )
continue;
if ( ! V_107 [ V_83 ] . V_105 )
* V_97 = V_107 [ V_83 ] . V_106 ?
F_35 ( V_2 , V_93 ,
V_94 , V_95 ) :
F_4 ( V_95 ) ;
return 0 ;
}
return - V_104 ;
}
static int F_38 ( struct V_1 * V_2 )
{
T_1 V_83 ;
F_39 ( V_2 -> V_108 , L_1 ) ;
F_40 ( V_2 -> V_109 ) ;
F_41 ( V_2 ) ;
F_42 ( 100 ) ;
for ( V_83 = 0 ; V_83 < V_2 -> V_110 ; V_83 ++ ) {
if ( F_4 ( V_111 ) != 0xffffffff ) {
F_43 ( V_2 -> V_109 ) ;
return 0 ;
}
F_42 ( 1 ) ;
}
return - V_104 ;
}
static void F_44 ( struct V_1 * V_2 , bool V_112 )
{
T_1 V_41 = F_4 ( V_113 ) ;
if ( V_112 )
V_41 |= V_114 ;
else
V_41 &= ~ V_114 ;
F_3 ( V_113 , V_41 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_5 ;
F_44 ( V_2 , true ) ;
V_5 = F_38 ( V_2 ) ;
F_44 ( V_2 , false ) ;
return V_5 ;
}
static int F_46 ( struct V_1 * V_2 , T_1 clock ,
T_1 V_115 , T_1 V_116 )
{
int V_5 , V_83 ;
struct V_117 V_118 ;
T_3 V_41 ;
V_5 = F_47 ( V_2 ,
V_119 ,
clock , false , & V_118 ) ;
if ( V_5 )
return V_5 ;
V_41 = F_23 ( V_115 ) ;
V_41 &= ~ ( V_120 |
V_121 ) ;
V_41 |= V_118 . V_122 ;
F_29 ( V_115 , V_41 ) ;
for ( V_83 = 0 ; V_83 < 100 ; V_83 ++ ) {
if ( F_23 ( V_116 ) & V_123 )
break;
F_48 ( 10 ) ;
}
if ( V_83 == 100 )
return - V_124 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , T_1 V_125 , T_1 V_126 )
{
int V_5 ;
V_5 = F_46 ( V_2 , V_125 , V_127 , V_128 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_46 ( V_2 , V_126 , V_129 , V_130 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , T_1 V_131 , T_1 V_132 )
{
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( F_52 ( V_2 -> V_109 -> V_133 ) )
return;
if ( V_134 == 0 )
return;
if ( V_2 -> V_4 & V_42 )
return;
if ( ! ( V_2 -> V_135 . V_136 & ( V_137 |
V_138 ) ) )
return;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( V_139 == 0 )
return;
}
static void F_54 ( struct V_1 * V_2 ,
bool V_140 )
{
T_1 V_41 ;
if ( V_2 -> V_4 & V_42 )
return;
V_41 = F_4 ( V_141 ) ;
if ( V_140 )
V_41 = F_26 ( V_41 , V_142 , V_142 , 1 ) ;
else
V_41 = F_26 ( V_41 , V_142 , V_142 , 0 ) ;
F_3 ( V_141 , V_41 ) ;
}
int F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_143 ) {
switch ( V_2 -> V_25 ) {
case V_26 :
V_2 -> V_144 = V_145 ;
V_2 -> V_146 = F_20 ( V_145 ) ;
break;
case V_28 :
V_2 -> V_144 = V_147 ;
V_2 -> V_146 = F_20 ( V_147 ) ;
break;
case V_30 :
V_2 -> V_144 = V_148 ;
V_2 -> V_146 = F_20 ( V_148 ) ;
break;
case V_36 :
case V_37 :
V_2 -> V_144 = V_149 ;
V_2 -> V_146 = F_20 ( V_149 ) ;
break;
case V_32 :
case V_34 :
V_2 -> V_144 = V_150 ;
V_2 -> V_146 = F_20 ( V_150 ) ;
break;
default:
return - V_104 ;
}
} else {
switch ( V_2 -> V_25 ) {
case V_26 :
V_2 -> V_144 = V_151 ;
V_2 -> V_146 = F_20 ( V_151 ) ;
break;
case V_28 :
V_2 -> V_144 = V_152 ;
V_2 -> V_146 = F_20 ( V_152 ) ;
break;
case V_30 :
V_2 -> V_144 = V_153 ;
V_2 -> V_146 = F_20 ( V_153 ) ;
break;
case V_36 :
case V_37 :
V_2 -> V_144 = V_154 ;
V_2 -> V_146 = F_20 ( V_154 ) ;
break;
case V_32 :
case V_34 :
V_2 -> V_144 = V_155 ;
V_2 -> V_146 = F_20 ( V_155 ) ;
break;
default:
return - V_104 ;
}
}
return 0 ;
}
static T_3 F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 & V_42 )
return ( F_23 ( V_156 ) & V_157 )
>> V_158 ;
else
return ( F_4 ( V_159 ) & V_160 )
>> V_161 ;
}
static int F_57 ( void * V_162 )
{
bool V_163 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
if ( V_2 -> V_4 & V_42 ) {
V_2 -> V_164 = & F_9 ;
V_2 -> V_165 = & F_10 ;
} else {
V_2 -> V_164 = & F_7 ;
V_2 -> V_165 = & F_8 ;
}
V_2 -> V_166 = & F_1 ;
V_2 -> V_167 = & F_6 ;
V_2 -> V_168 = & F_11 ;
V_2 -> V_169 = & F_12 ;
V_2 -> V_170 = & F_13 ;
V_2 -> V_171 = & F_14 ;
V_2 -> V_172 = & F_15 ;
V_2 -> V_173 = & F_16 ;
V_2 -> V_174 = & V_175 ;
if ( F_58 ( V_2 , V_176 ) &&
( V_177 & ( 1 << V_176 ) ) )
V_163 = true ;
V_2 -> V_178 = F_56 ( V_2 ) ;
V_2 -> V_179 = 0xFF ;
switch ( V_2 -> V_25 ) {
case V_26 :
V_2 -> V_180 = 0 ;
V_2 -> V_181 = 0 ;
V_2 -> V_179 = 0x1 ;
break;
case V_28 :
V_2 -> V_180 = V_182 |
V_183 |
V_184 |
V_185 |
V_186 |
V_187 |
V_188 |
V_189 |
V_190 |
V_191 |
V_192 |
V_193 |
V_194 |
V_195 |
V_196 |
V_197 ;
V_2 -> V_181 = 0 ;
V_2 -> V_179 = V_2 -> V_178 + 0x3c ;
break;
case V_30 :
V_2 -> V_180 = V_198 ;
V_2 -> V_181 = 0 ;
V_2 -> V_179 = V_2 -> V_178 + 0x14 ;
break;
case V_36 :
V_2 -> V_180 = 0 ;
V_2 -> V_181 = 0 ;
V_2 -> V_179 = V_2 -> V_178 + 0x5A ;
break;
case V_37 :
V_2 -> V_180 = 0 ;
V_2 -> V_181 = 0 ;
V_2 -> V_179 = V_2 -> V_178 + 0x50 ;
break;
case V_32 :
V_2 -> V_180 = V_198 |
V_182 |
V_183 |
V_184 |
V_185 |
V_186 |
V_183 |
V_187 |
V_188 |
V_189 |
V_192 |
V_193 |
V_194 |
V_190 |
V_191 |
V_199 ;
V_2 -> V_181 = 0 ;
if ( V_2 -> V_178 != 0x00 ) {
V_2 -> V_181 |= V_200 |
V_201 |
V_202 |
V_203 |
V_204 ;
}
V_2 -> V_179 = V_2 -> V_178 + 0x1 ;
break;
case V_34 :
V_2 -> V_180 = V_198 |
V_182 |
V_183 |
V_184 |
V_185 |
V_186 |
V_183 |
V_187 |
V_188 |
V_189 |
V_192 |
V_193 |
V_194 |
V_190 |
V_191 |
V_199 ;
V_2 -> V_181 = V_200 |
V_201 |
V_202 |
V_203 |
V_204 ;
V_2 -> V_179 = V_2 -> V_178 + 0x61 ;
break;
default:
return - V_104 ;
}
if ( V_2 -> V_174 -> V_205 )
F_59 ( V_2 ) ;
if ( V_206 && V_163 )
V_2 -> V_207 . V_208 = true ;
F_60 ( V_2 ) ;
return 0 ;
}
static int F_61 ( void * V_162 )
{
return 0 ;
}
static int F_62 ( void * V_162 )
{
return 0 ;
}
static int F_63 ( void * V_162 )
{
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
F_17 ( V_2 ) ;
F_51 ( V_2 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 , true ) ;
return 0 ;
}
static int F_64 ( void * V_162 )
{
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
F_54 ( V_2 , false ) ;
return 0 ;
}
static int F_65 ( void * V_162 )
{
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
return F_64 ( V_2 ) ;
}
static int F_66 ( void * V_162 )
{
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
return F_63 ( V_2 ) ;
}
static bool F_67 ( void * V_162 )
{
return true ;
}
static int F_68 ( void * V_162 )
{
return 0 ;
}
static int F_69 ( void * V_162 )
{
return 0 ;
}
static void F_70 ( struct V_1 * V_2 ,
bool V_140 )
{
T_3 V_209 , V_210 ;
V_209 = V_210 = F_71 ( V_211 ) ;
if ( V_140 && ( V_2 -> V_180 & V_192 ) )
V_210 |= V_212 |
V_213 |
V_214 ;
else
V_210 &= ~ ( V_212 |
V_213 |
V_214 ) ;
if ( V_209 != V_210 )
F_72 ( V_211 , V_210 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
bool V_140 )
{
T_3 V_209 , V_210 ;
V_209 = V_210 = F_4 ( V_215 ) ;
if ( V_140 && ( V_2 -> V_180 & V_193 ) )
V_210 &= ~ V_216 ;
else
V_210 |= V_216 ;
if ( V_209 != V_210 )
F_3 ( V_215 , V_210 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
bool V_140 )
{
T_3 V_209 , V_210 ;
V_209 = V_210 = F_4 ( V_217 ) ;
if ( V_140 && ( V_2 -> V_180 & V_194 ) )
V_210 |= V_218 ;
else
V_210 &= ~ V_218 ;
if ( V_209 != V_210 )
F_3 ( V_217 , V_210 ) ;
}
static void F_75 ( struct V_1 * V_2 ,
bool V_140 )
{
T_3 V_209 , V_210 ;
V_209 = V_210 = F_23 ( V_219 ) ;
if ( V_140 && ( V_2 -> V_180 & V_195 ) )
V_210 &= ~ ( V_220 |
V_221 ) ;
else
V_210 |= V_220 |
V_221 ;
if ( V_209 != V_210 )
F_29 ( V_219 , V_210 ) ;
}
static int F_76 ( void * V_162 ,
enum V_222 V_60 )
{
T_3 V_223 , V_224 ;
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
void * V_225 = V_2 -> V_226 . V_225 ;
if ( V_60 == V_227 )
V_224 = 0 ;
else
V_224 = V_228 | V_229 ;
V_223 = F_77 ( V_230 ,
V_231 ,
V_232 | V_233 ,
V_224 ) ;
F_78 ( V_225 , V_223 ) ;
V_223 = F_77 ( V_230 ,
V_234 ,
V_232 | V_233 ,
V_224 ) ;
F_78 ( V_225 , V_223 ) ;
V_223 = F_77 ( V_230 ,
V_235 ,
V_232 | V_233 ,
V_224 ) ;
F_78 ( V_225 , V_223 ) ;
V_223 = F_77 ( V_230 ,
V_236 ,
V_233 ,
V_224 ) ;
F_78 ( V_225 , V_223 ) ;
V_223 = F_77 ( V_230 ,
V_236 ,
V_232 ,
V_224 ) ;
F_78 ( V_225 , V_223 ) ;
V_223 = F_77 ( V_230 ,
V_237 ,
V_233 ,
V_224 ) ;
F_78 ( V_225 , V_223 ) ;
V_223 = F_77 ( V_230 ,
V_238 ,
V_232 ,
V_224 ) ;
F_78 ( V_225 , V_223 ) ;
return 0 ;
}
static int F_79 ( void * V_162 ,
enum V_222 V_60 )
{
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
switch ( V_2 -> V_25 ) {
case V_28 :
F_70 ( V_2 ,
V_60 == V_239 ? true : false ) ;
F_73 ( V_2 ,
V_60 == V_239 ? true : false ) ;
F_74 ( V_2 ,
V_60 == V_239 ? true : false ) ;
F_75 ( V_2 ,
V_60 == V_239 ? true : false ) ;
break;
case V_32 :
case V_34 :
F_70 ( V_2 ,
V_60 == V_239 ? true : false ) ;
F_73 ( V_2 ,
V_60 == V_239 ? true : false ) ;
F_74 ( V_2 ,
V_60 == V_239 ? true : false ) ;
break;
case V_30 :
case V_37 :
case V_36 :
F_76 ( V_2 , V_60 ) ;
default:
break;
}
return 0 ;
}
static int F_80 ( void * V_162 ,
enum V_240 V_60 )
{
return 0 ;
}
