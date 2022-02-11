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
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_21 ) ;
switch ( V_2 -> V_22 ) {
case V_23 :
F_17 ( V_2 ,
V_24 ,
( const T_1 ) F_18 ( V_24 ) ) ;
break;
case V_25 :
F_17 ( V_2 ,
V_26 ,
( const T_1 ) F_18 ( V_26 ) ) ;
break;
case V_27 :
F_17 ( V_2 ,
V_28 ,
( const T_1 ) F_18 ( V_28 ) ) ;
break;
case V_29 :
F_17 ( V_2 ,
V_30 ,
( const T_1 ) F_18 ( V_30 ) ) ;
break;
case V_31 :
F_17 ( V_2 ,
V_32 ,
( const T_1 ) F_18 ( V_32 ) ) ;
break;
case V_33 :
case V_34 :
default:
break;
}
F_19 ( & V_2 -> V_21 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 )
{
T_1 V_35 = V_2 -> clock . V_36 . V_37 ;
T_1 V_38 ;
if ( V_2 -> V_4 & V_39 )
return V_35 ;
V_38 = F_21 ( V_40 ) ;
if ( F_22 ( V_38 , V_41 , V_42 ) )
return 1000 ;
V_38 = F_21 ( V_43 ) ;
if ( F_22 ( V_38 , V_44 , V_45 ) )
return V_35 / 4 ;
return V_35 ;
}
void F_23 ( struct V_1 * V_2 ,
T_1 V_46 , T_1 V_47 , T_1 V_48 , T_1 V_49 )
{
T_1 V_50 = 0 ;
V_50 = F_24 ( V_50 , V_51 , V_52 , V_47 ) ;
V_50 = F_24 ( V_50 , V_51 , V_53 , V_46 ) ;
V_50 = F_24 ( V_50 , V_51 , V_54 , V_49 ) ;
V_50 = F_24 ( V_50 , V_51 , V_55 , V_48 ) ;
F_3 ( V_56 , V_50 ) ;
}
static void F_25 ( struct V_1 * V_2 , bool V_57 )
{
}
static bool F_26 ( struct V_1 * V_2 )
{
T_1 V_58 ;
T_1 V_59 = 0 ;
T_1 V_60 = 0 ;
T_1 V_61 = 0 ;
T_1 V_62 ;
bool V_5 ;
V_58 = F_4 ( V_63 ) ;
if ( V_2 -> V_64 . V_65 ) {
V_59 = F_4 ( V_66 ) ;
V_60 = F_4 ( V_67 ) ;
V_61 = F_4 ( V_68 ) ;
}
V_62 = F_21 ( V_69 ) ;
F_3 ( V_63 , ( V_58 & ~ V_70 ) ) ;
if ( V_2 -> V_64 . V_65 ) {
F_3 ( V_66 ,
( V_59 & ~ ( V_71 |
V_72 ) ) ) ;
F_3 ( V_67 ,
( V_60 & ~ ( V_73 |
V_74 ) ) ) ;
F_3 ( V_68 ,
( V_61 & ~ V_75 ) ) ;
}
F_27 ( V_69 , V_62 | V_76 ) ;
V_5 = F_28 ( V_2 ) ;
F_3 ( V_63 , V_58 ) ;
if ( V_2 -> V_64 . V_65 ) {
F_3 ( V_66 , V_59 ) ;
F_3 ( V_67 , V_60 ) ;
F_3 ( V_68 , V_61 ) ;
}
F_27 ( V_69 , V_62 ) ;
return V_5 ;
}
static bool F_29 ( struct V_1 * V_2 ,
T_2 * V_77 , T_1 V_78 )
{
T_1 * V_79 ;
unsigned long V_4 ;
T_1 V_80 , V_81 ;
if ( V_77 == NULL )
return false ;
if ( V_78 == 0 )
return false ;
if ( V_2 -> V_4 & V_39 )
return false ;
V_79 = ( T_1 * ) V_77 ;
V_81 = F_30 ( V_78 , 4 ) / 4 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_11 , V_82 ) ;
F_3 ( V_12 , 0 ) ;
F_3 ( V_11 , V_83 ) ;
for ( V_80 = 0 ; V_80 < V_81 ; V_80 ++ )
V_79 [ V_80 ] = F_4 ( V_12 ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
return true ;
}
static T_1 F_31 ( struct V_1 * V_2 )
{
T_1 V_84 = 0 ;
T_1 V_3 = F_4 ( V_85 ) ;
if ( F_22 ( V_3 , V_86 , V_87 ) )
V_84 |= V_88 ;
if ( F_22 ( V_3 , V_86 , V_89 ) )
V_84 |= V_90 ;
return V_84 ;
}
static T_3 F_32 ( struct V_1 * V_2 , T_1 V_91 ,
T_1 V_92 , T_1 V_93 )
{
T_3 V_94 ;
F_16 ( & V_2 -> V_21 ) ;
if ( V_91 != 0xffffffff || V_92 != 0xffffffff )
F_33 ( V_2 , V_91 , V_92 ) ;
V_94 = F_4 ( V_93 ) ;
if ( V_91 != 0xffffffff || V_92 != 0xffffffff )
F_33 ( V_2 , 0xffffffff , 0xffffffff ) ;
F_19 ( & V_2 -> V_21 ) ;
return V_94 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_91 ,
T_1 V_92 , T_1 V_93 , T_1 * V_95 )
{
const struct V_96 * V_97 = NULL ;
const struct V_96 * V_98 ;
T_3 V_99 , V_80 ;
* V_95 = 0 ;
switch ( V_2 -> V_22 ) {
case V_23 :
V_97 = V_100 ;
V_99 = F_18 ( V_100 ) ;
break;
case V_25 :
case V_27 :
case V_33 :
case V_34 :
case V_29 :
case V_31 :
V_97 = V_101 ;
V_99 = F_18 ( V_101 ) ;
break;
default:
return - V_102 ;
}
if ( V_97 ) {
for ( V_80 = 0 ; V_80 < V_99 ; V_80 ++ ) {
V_98 = V_97 + V_80 ;
if ( V_93 != V_98 -> V_93 )
continue;
if ( ! V_98 -> V_103 )
* V_95 = V_98 -> V_104 ?
F_32 ( V_2 , V_91 ,
V_92 , V_93 ) :
F_4 ( V_93 ) ;
return 0 ;
}
}
for ( V_80 = 0 ; V_80 < F_18 ( V_105 ) ; V_80 ++ ) {
if ( V_93 != V_105 [ V_80 ] . V_93 )
continue;
if ( ! V_105 [ V_80 ] . V_103 )
* V_95 = V_105 [ V_80 ] . V_104 ?
F_32 ( V_2 , V_91 ,
V_92 , V_93 ) :
F_4 ( V_93 ) ;
return 0 ;
}
return - V_102 ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_80 ;
F_36 ( V_2 -> V_106 , L_1 ) ;
F_37 ( V_2 -> V_107 ) ;
F_38 ( V_2 ) ;
F_39 ( 100 ) ;
for ( V_80 = 0 ; V_80 < V_2 -> V_108 ; V_80 ++ ) {
if ( F_4 ( V_109 ) != 0xffffffff )
break;
F_39 ( 1 ) ;
}
}
static void F_40 ( struct V_1 * V_2 , bool V_110 )
{
T_1 V_38 = F_4 ( V_111 ) ;
if ( V_110 )
V_38 |= V_112 ;
else
V_38 &= ~ V_112 ;
F_3 ( V_111 , V_38 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
F_40 ( V_2 , true ) ;
F_35 ( V_2 ) ;
F_40 ( V_2 , false ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 clock ,
T_1 V_113 , T_1 V_114 )
{
int V_5 , V_80 ;
struct V_115 V_116 ;
T_3 V_38 ;
V_5 = F_43 ( V_2 ,
V_117 ,
clock , false , & V_116 ) ;
if ( V_5 )
return V_5 ;
V_38 = F_21 ( V_113 ) ;
V_38 &= ~ ( V_118 |
V_119 ) ;
V_38 |= V_116 . V_120 ;
F_27 ( V_113 , V_38 ) ;
for ( V_80 = 0 ; V_80 < 100 ; V_80 ++ ) {
if ( F_21 ( V_114 ) & V_121 )
break;
F_44 ( 10 ) ;
}
if ( V_80 == 100 )
return - V_122 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , T_1 V_123 , T_1 V_124 )
{
int V_5 ;
V_5 = F_42 ( V_2 , V_123 , V_125 , V_126 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_42 ( V_2 , V_124 , V_127 , V_128 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , T_1 V_129 , T_1 V_130 )
{
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( F_48 ( V_2 -> V_107 -> V_131 ) )
return;
if ( V_132 == 0 )
return;
if ( V_2 -> V_4 & V_39 )
return;
if ( ! ( V_2 -> V_133 . V_134 & ( V_135 |
V_136 ) ) )
return;
}
static void F_49 ( struct V_1 * V_2 )
{
if ( V_137 == 0 )
return;
}
static void F_50 ( struct V_1 * V_2 ,
bool V_138 )
{
T_1 V_38 ;
if ( V_2 -> V_4 & V_39 )
return;
V_38 = F_4 ( V_139 ) ;
if ( V_138 )
V_38 = F_24 ( V_38 , V_140 , V_140 , 1 ) ;
else
V_38 = F_24 ( V_38 , V_140 , V_140 , 0 ) ;
F_3 ( V_139 , V_38 ) ;
}
int F_51 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_22 ) {
case V_23 :
V_2 -> V_141 = V_142 ;
V_2 -> V_143 = F_18 ( V_142 ) ;
break;
case V_25 :
V_2 -> V_141 = V_144 ;
V_2 -> V_143 = F_18 ( V_144 ) ;
break;
case V_27 :
V_2 -> V_141 = V_145 ;
V_2 -> V_143 = F_18 ( V_145 ) ;
break;
case V_33 :
case V_34 :
V_2 -> V_141 = V_146 ;
V_2 -> V_143 = F_18 ( V_146 ) ;
break;
case V_29 :
case V_31 :
V_2 -> V_141 = V_147 ;
V_2 -> V_143 = F_18 ( V_147 ) ;
break;
default:
return - V_102 ;
}
return 0 ;
}
static T_3 F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 & V_39 )
return ( F_21 ( V_148 ) & V_149 )
>> V_150 ;
else
return ( F_4 ( V_151 ) & V_152 )
>> V_153 ;
}
static int F_53 ( void * V_154 )
{
bool V_155 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
if ( V_2 -> V_4 & V_39 ) {
V_2 -> V_156 = & F_9 ;
V_2 -> V_157 = & F_10 ;
} else {
V_2 -> V_156 = & F_7 ;
V_2 -> V_157 = & F_8 ;
}
V_2 -> V_158 = & F_1 ;
V_2 -> V_159 = & F_6 ;
V_2 -> V_160 = & F_11 ;
V_2 -> V_161 = & F_12 ;
V_2 -> V_162 = & F_13 ;
V_2 -> V_163 = & F_14 ;
V_2 -> V_164 = & V_165 ;
if ( F_54 ( V_2 , V_166 ) &&
( V_167 & ( 1 << V_166 ) ) )
V_155 = true ;
V_2 -> V_168 = F_52 ( V_2 ) ;
V_2 -> V_169 = 0xFF ;
switch ( V_2 -> V_22 ) {
case V_23 :
V_2 -> V_170 = 0 ;
V_2 -> V_171 = 0 ;
V_2 -> V_169 = 0x1 ;
break;
case V_25 :
V_2 -> V_170 = V_172 |
V_173 |
V_174 |
V_175 |
V_176 |
V_177 |
V_178 |
V_179 |
V_180 |
V_181 |
V_182 |
V_183 |
V_184 |
V_185 |
V_186 |
V_187 ;
V_2 -> V_171 = 0 ;
V_2 -> V_169 = V_2 -> V_168 + 0x3c ;
break;
case V_27 :
V_2 -> V_170 = V_188 ;
V_2 -> V_171 = 0 ;
V_2 -> V_169 = V_2 -> V_168 + 0x14 ;
break;
case V_33 :
V_2 -> V_170 = 0 ;
V_2 -> V_171 = 0 ;
V_2 -> V_169 = V_2 -> V_168 + 0x5A ;
break;
case V_34 :
V_2 -> V_170 = 0 ;
V_2 -> V_171 = 0 ;
V_2 -> V_169 = V_2 -> V_168 + 0x50 ;
break;
case V_29 :
V_2 -> V_170 = V_188 |
V_172 |
V_173 |
V_174 |
V_175 |
V_176 |
V_173 |
V_177 |
V_178 |
V_179 |
V_182 |
V_183 |
V_184 |
V_180 |
V_181 ;
V_2 -> V_171 = 0 ;
V_2 -> V_169 = V_2 -> V_168 + 0x1 ;
break;
case V_31 :
V_2 -> V_170 = V_188 |
V_172 |
V_173 |
V_182 |
V_183 |
V_184 |
V_180 |
V_181 ;
V_2 -> V_171 = 0 ;
V_2 -> V_169 = V_2 -> V_168 + 0x1 ;
break;
default:
return - V_102 ;
}
if ( V_189 && V_155 )
V_2 -> V_190 . V_191 = true ;
F_55 ( V_2 ) ;
return 0 ;
}
static int F_56 ( void * V_154 )
{
return 0 ;
}
static int F_57 ( void * V_154 )
{
return 0 ;
}
static int F_58 ( void * V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
F_15 ( V_2 ) ;
F_47 ( V_2 ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 , true ) ;
return 0 ;
}
static int F_59 ( void * V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
F_50 ( V_2 , false ) ;
return 0 ;
}
static int F_60 ( void * V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
return F_59 ( V_2 ) ;
}
static int F_61 ( void * V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
return F_58 ( V_2 ) ;
}
static bool F_62 ( void * V_154 )
{
return true ;
}
static int F_63 ( void * V_154 )
{
return 0 ;
}
static int F_64 ( void * V_154 )
{
return 0 ;
}
static void F_65 ( struct V_1 * V_2 ,
bool V_138 )
{
T_3 V_192 , V_193 ;
V_192 = V_193 = F_66 ( V_194 ) ;
if ( V_138 && ( V_2 -> V_170 & V_182 ) )
V_193 |= V_195 |
V_196 |
V_197 ;
else
V_193 &= ~ ( V_195 |
V_196 |
V_197 ) ;
if ( V_192 != V_193 )
F_67 ( V_194 , V_193 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
bool V_138 )
{
T_3 V_192 , V_193 ;
V_192 = V_193 = F_4 ( V_198 ) ;
if ( V_138 && ( V_2 -> V_170 & V_183 ) )
V_193 &= ~ V_199 ;
else
V_193 |= V_199 ;
if ( V_192 != V_193 )
F_3 ( V_198 , V_193 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
bool V_138 )
{
T_3 V_192 , V_193 ;
V_192 = V_193 = F_4 ( V_200 ) ;
if ( V_138 && ( V_2 -> V_170 & V_184 ) )
V_193 |= V_201 ;
else
V_193 &= ~ V_201 ;
if ( V_192 != V_193 )
F_3 ( V_200 , V_193 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
bool V_138 )
{
T_3 V_192 , V_193 ;
V_192 = V_193 = F_21 ( V_202 ) ;
if ( V_138 && ( V_2 -> V_170 & V_185 ) )
V_193 &= ~ ( V_203 |
V_204 ) ;
else
V_193 |= V_203 |
V_204 ;
if ( V_192 != V_193 )
F_27 ( V_202 , V_193 ) ;
}
static int F_71 ( void * V_154 ,
enum V_205 V_57 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
switch ( V_2 -> V_22 ) {
case V_25 :
F_65 ( V_2 ,
V_57 == V_206 ? true : false ) ;
F_68 ( V_2 ,
V_57 == V_206 ? true : false ) ;
F_69 ( V_2 ,
V_57 == V_206 ? true : false ) ;
F_70 ( V_2 ,
V_57 == V_206 ? true : false ) ;
break;
case V_29 :
case V_31 :
F_65 ( V_2 ,
V_57 == V_206 ? true : false ) ;
F_68 ( V_2 ,
V_57 == V_206 ? true : false ) ;
F_69 ( V_2 ,
V_57 == V_206 ? true : false ) ;
break;
default:
break;
}
return 0 ;
}
static int F_72 ( void * V_154 ,
enum V_207 V_57 )
{
return 0 ;
}
