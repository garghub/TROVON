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
static T_1 F_33 ( struct V_1 * V_2 )
{
T_1 V_87 = 0 ;
T_1 V_3 = F_4 ( V_88 ) ;
if ( F_24 ( V_3 , V_89 , V_90 ) )
V_87 |= V_91 ;
if ( F_24 ( V_3 , V_89 , V_92 ) )
V_87 |= V_93 ;
return V_87 ;
}
static T_3 F_34 ( struct V_1 * V_2 , T_1 V_94 ,
T_1 V_95 , T_1 V_96 )
{
T_3 V_97 ;
F_18 ( & V_2 -> V_24 ) ;
if ( V_94 != 0xffffffff || V_95 != 0xffffffff )
F_35 ( V_2 , V_94 , V_95 , 0xffffffff ) ;
V_97 = F_4 ( V_96 ) ;
if ( V_94 != 0xffffffff || V_95 != 0xffffffff )
F_35 ( V_2 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_21 ( & V_2 -> V_24 ) ;
return V_97 ;
}
static int F_36 ( struct V_1 * V_2 , T_1 V_94 ,
T_1 V_95 , T_1 V_96 , T_1 * V_98 )
{
const struct V_99 * V_100 = NULL ;
const struct V_99 * V_101 ;
T_3 V_102 , V_83 ;
* V_98 = 0 ;
switch ( V_2 -> V_25 ) {
case V_26 :
V_100 = V_103 ;
V_102 = F_20 ( V_103 ) ;
break;
case V_28 :
case V_30 :
case V_36 :
case V_37 :
case V_32 :
case V_34 :
V_100 = V_104 ;
V_102 = F_20 ( V_104 ) ;
break;
default:
return - V_105 ;
}
if ( V_100 ) {
for ( V_83 = 0 ; V_83 < V_102 ; V_83 ++ ) {
V_101 = V_100 + V_83 ;
if ( V_96 != V_101 -> V_96 )
continue;
if ( ! V_101 -> V_106 )
* V_98 = V_101 -> V_107 ?
F_34 ( V_2 , V_94 ,
V_95 , V_96 ) :
F_4 ( V_96 ) ;
return 0 ;
}
}
for ( V_83 = 0 ; V_83 < F_20 ( V_108 ) ; V_83 ++ ) {
if ( V_96 != V_108 [ V_83 ] . V_96 )
continue;
if ( ! V_108 [ V_83 ] . V_106 )
* V_98 = V_108 [ V_83 ] . V_107 ?
F_34 ( V_2 , V_94 ,
V_95 , V_96 ) :
F_4 ( V_96 ) ;
return 0 ;
}
return - V_105 ;
}
static int F_37 ( struct V_1 * V_2 )
{
T_1 V_83 ;
F_38 ( V_2 -> V_109 , L_1 ) ;
F_39 ( V_2 -> V_110 ) ;
F_40 ( V_2 ) ;
F_41 ( 100 ) ;
for ( V_83 = 0 ; V_83 < V_2 -> V_111 ; V_83 ++ ) {
if ( F_4 ( V_112 ) != 0xffffffff ) {
F_42 ( V_2 -> V_110 ) ;
return 0 ;
}
F_41 ( 1 ) ;
}
return - V_105 ;
}
static void F_43 ( struct V_1 * V_2 , bool V_113 )
{
T_1 V_41 = F_4 ( V_114 ) ;
if ( V_113 )
V_41 |= V_115 ;
else
V_41 &= ~ V_115 ;
F_3 ( V_114 , V_41 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_5 ;
F_43 ( V_2 , true ) ;
V_5 = F_37 ( V_2 ) ;
F_43 ( V_2 , false ) ;
return V_5 ;
}
static int F_45 ( struct V_1 * V_2 , T_1 clock ,
T_1 V_116 , T_1 V_117 )
{
int V_5 , V_83 ;
struct V_118 V_119 ;
T_3 V_41 ;
V_5 = F_46 ( V_2 ,
V_120 ,
clock , false , & V_119 ) ;
if ( V_5 )
return V_5 ;
V_41 = F_23 ( V_116 ) ;
V_41 &= ~ ( V_121 |
V_122 ) ;
V_41 |= V_119 . V_123 ;
F_29 ( V_116 , V_41 ) ;
for ( V_83 = 0 ; V_83 < 100 ; V_83 ++ ) {
if ( F_23 ( V_117 ) & V_124 )
break;
F_47 ( 10 ) ;
}
if ( V_83 == 100 )
return - V_125 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , T_1 V_126 , T_1 V_127 )
{
int V_5 ;
V_5 = F_45 ( V_2 , V_126 , V_128 , V_129 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_45 ( V_2 , V_127 , V_130 , V_131 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , T_1 V_132 , T_1 V_133 )
{
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
if ( F_51 ( V_2 -> V_110 -> V_134 ) )
return;
if ( V_135 == 0 )
return;
if ( V_2 -> V_4 & V_42 )
return;
if ( ! ( V_2 -> V_136 . V_137 & ( V_138 |
V_139 ) ) )
return;
}
static void F_52 ( struct V_1 * V_2 )
{
if ( V_140 == 0 )
return;
}
static void F_53 ( struct V_1 * V_2 ,
bool V_141 )
{
T_1 V_41 ;
if ( V_2 -> V_4 & V_42 )
return;
V_41 = F_4 ( V_142 ) ;
if ( V_141 )
V_41 = F_26 ( V_41 , V_143 , V_143 , 1 ) ;
else
V_41 = F_26 ( V_41 , V_143 , V_143 , 0 ) ;
F_3 ( V_142 , V_41 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
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
return - V_105 ;
}
return 0 ;
}
static T_3 F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 & V_42 )
return ( F_23 ( V_151 ) & V_152 )
>> V_153 ;
else
return ( F_4 ( V_154 ) & V_155 )
>> V_156 ;
}
static int F_56 ( void * V_157 )
{
bool V_158 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_157 ;
if ( V_2 -> V_4 & V_42 ) {
V_2 -> V_159 = & F_9 ;
V_2 -> V_160 = & F_10 ;
} else {
V_2 -> V_159 = & F_7 ;
V_2 -> V_160 = & F_8 ;
}
V_2 -> V_161 = & F_1 ;
V_2 -> V_162 = & F_6 ;
V_2 -> V_163 = & F_11 ;
V_2 -> V_164 = & F_12 ;
V_2 -> V_165 = & F_13 ;
V_2 -> V_166 = & F_14 ;
V_2 -> V_167 = & F_15 ;
V_2 -> V_168 = & F_16 ;
V_2 -> V_169 = & V_170 ;
if ( F_57 ( V_2 , V_171 ) &&
( V_172 & ( 1 << V_171 ) ) )
V_158 = true ;
V_2 -> V_173 = F_55 ( V_2 ) ;
V_2 -> V_174 = 0xFF ;
switch ( V_2 -> V_25 ) {
case V_26 :
V_2 -> V_175 = 0 ;
V_2 -> V_176 = 0 ;
V_2 -> V_174 = 0x1 ;
break;
case V_28 :
V_2 -> V_175 = V_177 |
V_178 |
V_179 |
V_180 |
V_181 |
V_182 |
V_183 |
V_184 |
V_185 |
V_186 |
V_187 |
V_188 |
V_189 |
V_190 |
V_191 |
V_192 ;
V_2 -> V_176 = 0 ;
V_2 -> V_174 = V_2 -> V_173 + 0x3c ;
break;
case V_30 :
V_2 -> V_175 = V_193 ;
V_2 -> V_176 = 0 ;
V_2 -> V_174 = V_2 -> V_173 + 0x14 ;
break;
case V_36 :
V_2 -> V_175 = 0 ;
V_2 -> V_176 = 0 ;
V_2 -> V_174 = V_2 -> V_173 + 0x5A ;
break;
case V_37 :
V_2 -> V_175 = 0 ;
V_2 -> V_176 = 0 ;
V_2 -> V_174 = V_2 -> V_173 + 0x50 ;
break;
case V_32 :
V_2 -> V_175 = V_193 |
V_177 |
V_178 |
V_179 |
V_180 |
V_181 |
V_178 |
V_182 |
V_183 |
V_184 |
V_187 |
V_188 |
V_189 |
V_185 |
V_186 ;
V_2 -> V_176 = 0 ;
V_2 -> V_174 = V_2 -> V_173 + 0x1 ;
break;
case V_34 :
V_2 -> V_175 = V_193 |
V_177 |
V_178 |
V_179 |
V_180 |
V_181 |
V_178 |
V_182 |
V_183 |
V_184 |
V_187 |
V_188 |
V_189 |
V_185 |
V_186 ;
V_2 -> V_174 = V_2 -> V_173 + 0x1 ;
break;
default:
return - V_105 ;
}
if ( V_194 && V_158 )
V_2 -> V_195 . V_196 = true ;
F_58 ( V_2 ) ;
return 0 ;
}
static int F_59 ( void * V_157 )
{
return 0 ;
}
static int F_60 ( void * V_157 )
{
return 0 ;
}
static int F_61 ( void * V_157 )
{
struct V_1 * V_2 = (struct V_1 * ) V_157 ;
F_17 ( V_2 ) ;
F_50 ( V_2 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 , true ) ;
return 0 ;
}
static int F_62 ( void * V_157 )
{
struct V_1 * V_2 = (struct V_1 * ) V_157 ;
F_53 ( V_2 , false ) ;
return 0 ;
}
static int F_63 ( void * V_157 )
{
struct V_1 * V_2 = (struct V_1 * ) V_157 ;
return F_62 ( V_2 ) ;
}
static int F_64 ( void * V_157 )
{
struct V_1 * V_2 = (struct V_1 * ) V_157 ;
return F_61 ( V_2 ) ;
}
static bool F_65 ( void * V_157 )
{
return true ;
}
static int F_66 ( void * V_157 )
{
return 0 ;
}
static int F_67 ( void * V_157 )
{
return 0 ;
}
static void F_68 ( struct V_1 * V_2 ,
bool V_141 )
{
T_3 V_197 , V_198 ;
V_197 = V_198 = F_69 ( V_199 ) ;
if ( V_141 && ( V_2 -> V_175 & V_187 ) )
V_198 |= V_200 |
V_201 |
V_202 ;
else
V_198 &= ~ ( V_200 |
V_201 |
V_202 ) ;
if ( V_197 != V_198 )
F_70 ( V_199 , V_198 ) ;
}
static void F_71 ( struct V_1 * V_2 ,
bool V_141 )
{
T_3 V_197 , V_198 ;
V_197 = V_198 = F_4 ( V_203 ) ;
if ( V_141 && ( V_2 -> V_175 & V_188 ) )
V_198 &= ~ V_204 ;
else
V_198 |= V_204 ;
if ( V_197 != V_198 )
F_3 ( V_203 , V_198 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
bool V_141 )
{
T_3 V_197 , V_198 ;
V_197 = V_198 = F_4 ( V_205 ) ;
if ( V_141 && ( V_2 -> V_175 & V_189 ) )
V_198 |= V_206 ;
else
V_198 &= ~ V_206 ;
if ( V_197 != V_198 )
F_3 ( V_205 , V_198 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
bool V_141 )
{
T_3 V_197 , V_198 ;
V_197 = V_198 = F_23 ( V_207 ) ;
if ( V_141 && ( V_2 -> V_175 & V_190 ) )
V_198 &= ~ ( V_208 |
V_209 ) ;
else
V_198 |= V_208 |
V_209 ;
if ( V_197 != V_198 )
F_29 ( V_207 , V_198 ) ;
}
static int F_74 ( void * V_157 ,
enum V_210 V_60 )
{
struct V_1 * V_2 = (struct V_1 * ) V_157 ;
switch ( V_2 -> V_25 ) {
case V_28 :
F_68 ( V_2 ,
V_60 == V_211 ? true : false ) ;
F_71 ( V_2 ,
V_60 == V_211 ? true : false ) ;
F_72 ( V_2 ,
V_60 == V_211 ? true : false ) ;
F_73 ( V_2 ,
V_60 == V_211 ? true : false ) ;
break;
case V_32 :
case V_34 :
F_68 ( V_2 ,
V_60 == V_211 ? true : false ) ;
F_71 ( V_2 ,
V_60 == V_211 ? true : false ) ;
F_72 ( V_2 ,
V_60 == V_211 ? true : false ) ;
break;
default:
break;
}
return 0 ;
}
static int F_75 ( void * V_157 ,
enum V_212 V_60 )
{
return 0 ;
}
