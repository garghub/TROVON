static bool F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
return V_3 -> V_4 . type == V_5 ;
}
static struct V_6 * F_3 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
return V_3 -> V_4 . V_4 . V_7 ;
}
static struct V_1 * F_4 ( struct V_8 * V_9 )
{
return F_5 ( & F_6 ( V_9 ) -> V_4 ) ;
}
int
F_7 ( struct V_1 * V_1 )
{
int V_10 = V_1 -> V_11 [ V_12 ] ;
struct V_6 * V_7 = V_1 -> V_13 -> V_4 . V_7 ;
switch ( V_10 ) {
case V_14 :
case V_15 :
break;
case V_16 :
if ( ( ( F_8 ( V_7 ) && ! F_9 ( V_7 ) ) ||
F_10 ( V_7 ) -> V_17 >= 8 ) &&
V_1 -> V_11 [ V_18 ] >= 0x12 )
V_10 = V_16 ;
else
V_10 = V_15 ;
break;
default:
F_11 ( 1 , L_1 ,
V_10 ) ;
V_10 = V_14 ;
break;
}
return V_10 ;
}
static T_1 F_12 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_1 V_19 , V_20 ;
V_19 = 4 ;
if ( F_13 ( V_7 ) && V_3 -> V_21 == V_22 &&
( V_3 -> V_23 & V_24 ) == 0 )
V_19 = 2 ;
V_20 = F_14 ( V_1 -> V_11 ) ;
return F_15 ( V_19 , V_20 ) ;
}
static int
F_16 ( int V_25 , int V_26 )
{
return ( V_25 * V_26 + 9 ) / 10 ;
}
static int
F_17 ( int V_27 , int V_28 )
{
return ( V_27 * V_28 * 8 ) / 10 ;
}
static enum V_29
F_18 ( struct V_8 * V_9 ,
struct V_30 * V_31 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_32 * V_32 = F_19 ( V_9 ) ;
struct V_30 * V_33 = V_32 -> V_34 . V_33 ;
int V_35 = V_31 -> clock ;
int V_36 , V_37 , V_28 , V_27 ;
if ( F_1 ( V_1 ) && V_33 ) {
if ( V_31 -> V_38 > V_33 -> V_38 )
return V_39 ;
if ( V_31 -> V_40 > V_33 -> V_40 )
return V_39 ;
V_35 = V_33 -> clock ;
}
V_27 = F_20 ( F_7 ( V_1 ) ) ;
V_28 = F_12 ( V_1 ) ;
V_36 = F_17 ( V_27 , V_28 ) ;
V_37 = F_16 ( V_35 , 18 ) ;
if ( V_37 > V_36 )
return V_41 ;
if ( V_31 -> clock < 10000 )
return V_42 ;
if ( V_31 -> V_43 & V_44 )
return V_45 ;
return V_46 ;
}
static T_2
F_21 ( T_3 * V_47 , int V_48 )
{
int V_49 ;
T_2 V_50 = 0 ;
if ( V_48 > 4 )
V_48 = 4 ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ )
V_50 |= ( ( T_2 ) V_47 [ V_49 ] ) << ( ( 3 - V_49 ) * 8 ) ;
return V_50 ;
}
static void
F_22 ( T_2 V_47 , T_3 * V_51 , int V_52 )
{
int V_49 ;
if ( V_52 > 4 )
V_52 = 4 ;
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ )
V_51 [ V_49 ] = V_47 >> ( ( 3 - V_49 ) * 8 ) ;
}
static int
F_23 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_56 ;
if ( F_24 ( V_7 ) )
return 200 ;
V_56 = F_25 ( V_57 ) ;
switch ( V_56 & V_58 ) {
case V_59 :
return 100 ;
case V_60 :
return 133 ;
case V_61 :
return 166 ;
case V_62 :
return 200 ;
case V_63 :
return 266 ;
case V_64 :
return 333 ;
case V_65 :
case V_66 :
return 400 ;
default:
return 133 ;
}
}
static enum V_67
F_26 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_68 * V_69 = V_3 -> V_4 . V_4 . V_69 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
enum V_67 V_67 ;
if ( V_69 )
return F_27 ( V_69 ) -> V_67 ;
for ( V_67 = V_70 ; V_67 <= V_71 ; V_67 ++ ) {
T_4 V_72 = F_25 ( F_28 ( V_67 ) ) &
V_73 ;
if ( V_72 == V_74 && V_21 == V_75 )
return V_67 ;
if ( V_72 == V_76 && V_21 == V_77 )
return V_67 ;
}
return V_70 ;
}
static T_4 F_29 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_30 ( V_7 ) )
return V_78 ;
else
return F_31 ( F_26 ( V_1 ) ) ;
}
static T_4 F_32 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_30 ( V_7 ) )
return V_79 ;
else
return F_33 ( F_26 ( V_1 ) ) ;
}
static int F_34 ( struct V_80 * V_81 , unsigned long V_82 ,
void * V_83 )
{
struct V_1 * V_1 = F_35 ( V_81 , F_36 ( * V_1 ) ,
V_84 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_85 ;
T_4 V_86 , V_87 ;
enum V_67 V_67 = F_26 ( V_1 ) ;
if ( ! F_1 ( V_1 ) || V_82 != V_88 )
return 0 ;
if ( F_24 ( V_7 ) ) {
V_86 = F_31 ( V_67 ) ;
V_87 = F_37 ( V_67 ) ;
V_85 = F_25 ( V_87 ) ;
V_85 &= V_89 ;
F_38 ( V_87 , V_85 | 0x1F ) ;
F_38 ( V_86 , V_90 | V_91 ) ;
F_39 ( V_1 -> V_92 ) ;
}
return 0 ;
}
static bool F_40 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
return ( F_25 ( F_32 ( V_1 ) ) & V_93 ) != 0 ;
}
static bool F_41 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_94 * V_94 = & V_3 -> V_4 ;
enum V_95 V_96 ;
V_96 = F_42 ( V_94 ) ;
return F_43 ( V_54 , V_96 ) &&
( F_25 ( F_29 ( V_1 ) ) & V_97 ) != 0 ;
}
static void
F_44 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_40 ( V_1 ) && ! F_41 ( V_1 ) ) {
F_11 ( 1 , L_2 ) ;
F_45 ( L_3 ,
F_25 ( F_32 ( V_1 ) ) ,
F_25 ( F_29 ( V_1 ) ) ) ;
}
}
static T_2
F_46 ( struct V_1 * V_1 , bool V_98 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_99 = V_1 -> V_100 ;
T_2 V_101 ;
bool V_102 ;
#define F_47 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_98 )
V_102 = F_48 ( V_54 -> V_103 , F_47 ,
F_49 ( 10 ) ) ;
else
V_102 = F_50 ( F_47 , 10 ) == 0 ;
if ( ! V_102 )
F_51 ( L_4 ,
V_98 ) ;
#undef F_47
return V_101 ;
}
static T_2 F_52 ( struct V_1 * V_1 , int V_104 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
return V_104 ? 0 : F_23 ( V_7 ) / 2 ;
}
static T_2 F_53 ( struct V_1 * V_1 , int V_104 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
if ( V_104 )
return 0 ;
if ( V_3 -> V_21 == V_22 ) {
if ( F_54 ( V_7 ) || F_55 ( V_7 ) )
return 200 ;
else
return 225 ;
} else {
return F_56 ( F_57 ( V_7 ) , 2 ) ;
}
}
static T_2 F_58 ( struct V_1 * V_1 , int V_104 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( V_3 -> V_21 == V_22 ) {
if ( V_104 )
return 0 ;
return F_59 ( F_60 ( V_54 ) , 2000 ) ;
} else if ( V_54 -> V_105 == V_106 ) {
switch ( V_104 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
} else {
return V_104 ? 0 : F_56 ( F_57 ( V_7 ) , 2 ) ;
}
}
static T_2 F_61 ( struct V_1 * V_1 , int V_104 )
{
return V_104 ? 0 : 100 ;
}
static T_2 F_62 ( struct V_1 * V_1 ,
bool V_98 ,
int V_107 ,
T_2 V_108 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_109 , V_110 ;
if ( F_54 ( V_7 ) )
V_109 = 3 ;
else
V_109 = 5 ;
if ( F_63 ( V_7 ) && V_1 -> V_100 == V_111 )
V_110 = V_112 ;
else
V_110 = V_113 ;
return V_114 |
V_115 |
( V_98 ? V_116 : 0 ) |
V_117 |
V_110 |
V_118 |
( V_107 << V_119 ) |
( V_109 << V_120 ) |
( V_108 << V_121 ) ;
}
static int
F_64 ( struct V_1 * V_1 ,
T_3 * V_122 , int V_107 ,
T_3 * V_123 , int V_124 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_99 = V_1 -> V_100 ;
T_2 V_125 = V_99 + 4 ;
T_2 V_108 ;
int V_49 , V_126 , V_127 ;
T_2 V_101 ;
int V_128 , clock = 0 ;
bool V_98 = F_65 ( V_7 ) ;
bool V_129 ;
V_129 = F_66 ( V_1 ) ;
F_67 ( & V_54 -> V_130 , 0 ) ;
F_44 ( V_1 ) ;
F_68 ( V_54 ) ;
for ( V_128 = 0 ; V_128 < 3 ; V_128 ++ ) {
V_101 = F_69 ( V_99 ) ;
if ( ( V_101 & V_114 ) == 0 )
break;
F_39 ( 1 ) ;
}
if ( V_128 == 3 ) {
F_11 ( 1 , L_5 ,
F_25 ( V_99 ) ) ;
V_126 = - V_131 ;
goto V_132;
}
if ( F_70 ( V_107 > 20 || V_124 > 20 ) ) {
V_126 = - V_133 ;
goto V_132;
}
while ( ( V_108 = V_1 -> V_134 ( V_1 , clock ++ ) ) ) {
T_4 V_135 = V_1 -> V_136 ( V_1 ,
V_98 ,
V_107 ,
V_108 ) ;
for ( V_128 = 0 ; V_128 < 5 ; V_128 ++ ) {
for ( V_49 = 0 ; V_49 < V_107 ; V_49 += 4 )
F_38 ( V_125 + V_49 ,
F_21 ( V_122 + V_49 , V_107 - V_49 ) ) ;
F_38 ( V_99 , V_135 ) ;
V_101 = F_46 ( V_1 , V_98 ) ;
F_38 ( V_99 ,
V_101 |
V_115 |
V_117 |
V_118 ) ;
if ( V_101 & ( V_117 |
V_118 ) )
continue;
if ( V_101 & V_115 )
break;
}
if ( V_101 & V_115 )
break;
}
if ( ( V_101 & V_115 ) == 0 ) {
F_51 ( L_6 , V_101 ) ;
V_126 = - V_131 ;
goto V_132;
}
if ( V_101 & V_118 ) {
F_51 ( L_7 , V_101 ) ;
V_126 = - V_137 ;
goto V_132;
}
if ( V_101 & V_117 ) {
F_45 ( L_8 , V_101 ) ;
V_126 = - V_138 ;
goto V_132;
}
V_127 = ( ( V_101 & V_139 ) >>
V_119 ) ;
if ( V_127 > V_124 )
V_127 = V_124 ;
for ( V_49 = 0 ; V_49 < V_127 ; V_49 += 4 )
F_22 ( F_25 ( V_125 + V_49 ) ,
V_123 + V_49 , V_127 - V_49 ) ;
V_126 = V_127 ;
V_132:
F_67 ( & V_54 -> V_130 , V_140 ) ;
F_71 ( V_54 ) ;
if ( V_129 )
F_72 ( V_1 , false ) ;
return V_126 ;
}
static T_5
F_73 ( struct V_141 * V_142 , struct V_143 * V_144 )
{
struct V_1 * V_1 = F_35 ( V_142 , struct V_1 , V_142 ) ;
T_3 V_145 [ 20 ] , V_146 [ 20 ] ;
T_6 V_147 , V_148 ;
int V_126 ;
V_145 [ 0 ] = V_144 -> V_149 << 4 ;
V_145 [ 1 ] = V_144 -> V_150 >> 8 ;
V_145 [ 2 ] = V_144 -> V_150 & 0xff ;
V_145 [ 3 ] = V_144 -> V_151 - 1 ;
switch ( V_144 -> V_149 & ~ V_152 ) {
case V_153 :
case V_154 :
V_147 = V_144 -> V_151 ? V_155 + V_144 -> V_151 : V_156 ;
V_148 = 1 ;
if ( F_70 ( V_147 > 20 ) )
return - V_133 ;
memcpy ( V_145 + V_155 , V_144 -> V_157 , V_144 -> V_151 ) ;
V_126 = F_64 ( V_1 , V_145 , V_147 , V_146 , V_148 ) ;
if ( V_126 > 0 ) {
V_144 -> V_158 = V_146 [ 0 ] >> 4 ;
V_126 = V_144 -> V_151 ;
}
break;
case V_159 :
case V_160 :
V_147 = V_144 -> V_151 ? V_155 : V_156 ;
V_148 = V_144 -> V_151 + 1 ;
if ( F_70 ( V_148 > 20 ) )
return - V_133 ;
V_126 = F_64 ( V_1 , V_145 , V_147 , V_146 , V_148 ) ;
if ( V_126 > 0 ) {
V_144 -> V_158 = V_146 [ 0 ] >> 4 ;
V_126 -- ;
memcpy ( V_144 -> V_157 , V_146 + 1 , V_126 ) ;
}
break;
default:
V_126 = - V_161 ;
break;
}
return V_126 ;
}
static void
F_74 ( struct V_1 * V_1 , struct V_32 * V_9 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_21 V_21 = V_3 -> V_21 ;
const char * V_162 = NULL ;
int V_126 ;
switch ( V_21 ) {
case V_22 :
V_1 -> V_100 = V_111 ;
V_162 = L_9 ;
break;
case V_75 :
V_1 -> V_100 = V_163 ;
V_162 = L_10 ;
break;
case V_77 :
V_1 -> V_100 = V_164 ;
V_162 = L_11 ;
break;
case V_165 :
V_1 -> V_100 = V_166 ;
V_162 = L_12 ;
break;
default:
F_75 () ;
}
if ( ! F_13 ( V_7 ) )
V_1 -> V_100 = V_1 -> V_167 + 0x10 ;
V_1 -> V_142 . V_162 = V_162 ;
V_1 -> V_142 . V_7 = V_7 -> V_7 ;
V_1 -> V_142 . V_168 = F_73 ;
F_45 ( L_13 , V_162 ,
V_9 -> V_4 . V_169 -> V_170 . V_162 ) ;
V_126 = F_76 ( & V_1 -> V_142 ) ;
if ( V_126 < 0 ) {
F_51 ( L_14 ,
V_162 , V_126 ) ;
return;
}
V_126 = F_77 ( & V_9 -> V_4 . V_169 -> V_170 ,
& V_1 -> V_142 . V_171 . V_7 . V_170 ,
V_1 -> V_142 . V_171 . V_7 . V_170 . V_162 ) ;
if ( V_126 < 0 ) {
F_51 ( L_15 , V_162 , V_126 ) ;
F_78 ( & V_1 -> V_142 ) ;
}
}
static void
F_79 ( struct V_32 * V_32 )
{
struct V_1 * V_1 = F_4 ( & V_32 -> V_4 ) ;
if ( ! V_32 -> V_172 )
F_80 ( & V_32 -> V_4 . V_169 -> V_170 ,
V_1 -> V_142 . V_171 . V_7 . V_170 . V_162 ) ;
F_81 ( V_32 ) ;
}
static void
F_82 ( struct V_173 * V_174 , int V_175 )
{
switch ( V_175 ) {
case V_14 :
V_174 -> V_176 = V_177 ;
break;
case V_15 :
V_174 -> V_176 = V_178 ;
break;
case V_16 :
V_174 -> V_176 = V_179 ;
break;
}
}
static void
F_83 ( struct V_94 * V_180 ,
struct V_173 * V_174 , int V_175 )
{
struct V_6 * V_7 = V_180 -> V_4 . V_7 ;
const struct V_181 * V_182 = NULL ;
int V_49 , V_183 = 0 ;
if ( F_84 ( V_7 ) ) {
V_182 = V_184 ;
V_183 = F_85 ( V_184 ) ;
} else if ( F_30 ( V_7 ) ) {
V_182 = V_185 ;
V_183 = F_85 ( V_185 ) ;
} else if ( F_86 ( V_7 ) ) {
V_182 = V_186 ;
V_183 = F_85 ( V_186 ) ;
} else if ( F_24 ( V_7 ) ) {
V_182 = V_187 ;
V_183 = F_85 ( V_187 ) ;
}
if ( V_182 && V_183 ) {
for ( V_49 = 0 ; V_49 < V_183 ; V_49 ++ ) {
if ( V_175 == V_182 [ V_49 ] . V_175 ) {
V_174 -> V_188 = V_182 [ V_49 ] . V_188 ;
V_174 -> V_189 = true ;
break;
}
}
}
}
static void
F_87 ( struct V_190 * V_69 , struct V_191 * V_192 )
{
struct V_6 * V_7 = V_69 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_193 V_193 = V_69 -> V_194 . V_195 ;
F_38 ( F_88 ( V_193 ) ,
F_89 ( V_192 -> V_196 ) | V_192 -> V_197 ) ;
F_38 ( F_90 ( V_193 ) , V_192 -> V_198 ) ;
F_38 ( F_91 ( V_193 ) , V_192 -> V_199 ) ;
F_38 ( F_92 ( V_193 ) , V_192 -> V_200 ) ;
}
bool
F_93 ( struct V_94 * V_180 ,
struct V_173 * V_174 )
{
struct V_6 * V_7 = V_180 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_30 * V_201 = & V_174 -> V_201 ;
struct V_1 * V_1 = F_5 ( & V_180 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_190 * V_190 = V_180 -> V_202 ;
struct V_32 * V_32 = V_1 -> V_13 ;
int V_203 , clock ;
int V_204 = 1 ;
int V_205 = F_12 ( V_1 ) ;
int V_206 = 0 ;
int V_207 = F_7 ( V_1 ) >> 3 ;
int V_26 , V_37 ;
static int V_208 [] = { V_14 , V_15 , V_16 } ;
int V_209 , V_210 ;
if ( F_30 ( V_7 ) && ! F_13 ( V_7 ) && V_21 != V_22 )
V_174 -> V_211 = true ;
V_174 -> V_212 = true ;
V_174 -> V_213 = V_1 -> V_213 ;
if ( F_1 ( V_1 ) && V_32 -> V_34 . V_33 ) {
F_94 ( V_32 -> V_34 . V_33 ,
V_201 ) ;
if ( ! F_30 ( V_7 ) )
F_95 ( V_190 , V_174 ,
V_32 -> V_34 . V_214 ) ;
else
F_96 ( V_190 , V_174 ,
V_32 -> V_34 . V_214 ) ;
}
if ( V_201 -> V_43 & V_44 )
return false ;
F_45 ( L_16
L_17 ,
V_205 , V_208 [ V_207 ] ,
V_201 -> V_215 ) ;
V_26 = V_174 -> V_216 ;
if ( F_1 ( V_1 ) ) {
if ( V_54 -> V_217 . V_218 && V_54 -> V_217 . V_218 < V_26 ) {
F_45 ( L_18 ,
V_54 -> V_217 . V_218 ) ;
V_26 = V_54 -> V_217 . V_218 ;
}
if ( F_63 ( V_7 ) ) {
V_204 = V_205 ;
F_45 ( L_19 ,
V_204 ) ;
} else if ( V_54 -> V_217 . V_219 ) {
V_204 = F_15 ( V_54 -> V_217 . V_219 ,
V_205 ) ;
F_45 ( L_20 ,
V_204 ) ;
}
if ( V_54 -> V_217 . V_220 ) {
V_206 = F_15 ( V_54 -> V_217 . V_220 >> 3 , V_207 ) ;
F_45 ( L_21 ,
V_208 [ V_206 ] ) ;
}
}
for (; V_26 >= 6 * 3 ; V_26 -= 2 * 3 ) {
V_37 = F_16 ( V_201 -> V_215 ,
V_26 ) ;
for ( clock = V_206 ; clock <= V_207 ; clock ++ ) {
for ( V_203 = V_204 ; V_203 <= V_205 ; V_203 <<= 1 ) {
V_210 = F_20 ( V_208 [ clock ] ) ;
V_209 = F_17 ( V_210 ,
V_203 ) ;
if ( V_37 <= V_209 ) {
goto V_221;
}
}
}
}
return false ;
V_221:
if ( V_1 -> V_222 ) {
if ( V_26 != 18 && F_97 ( V_201 ) > 1 )
V_1 -> V_223 = V_224 ;
else
V_1 -> V_223 = 0 ;
}
if ( V_1 -> V_223 )
V_174 -> V_225 = true ;
V_1 -> V_175 = V_208 [ clock ] ;
V_1 -> V_203 = V_203 ;
V_174 -> V_216 = V_26 ;
V_174 -> V_226 = F_20 ( V_1 -> V_175 ) ;
F_45 ( L_22 ,
V_1 -> V_175 , V_1 -> V_203 ,
V_174 -> V_226 , V_26 ) ;
F_45 ( L_23 ,
V_37 , V_209 ) ;
F_98 ( V_26 , V_203 ,
V_201 -> V_215 ,
V_174 -> V_226 ,
& V_174 -> V_227 ) ;
if ( V_32 -> V_34 . V_228 != NULL &&
V_1 -> V_229 . type == V_230 ) {
F_98 ( V_26 , V_203 ,
V_32 -> V_34 . V_228 -> clock ,
V_174 -> V_226 ,
& V_174 -> V_231 ) ;
}
if ( F_13 ( V_7 ) )
F_82 ( V_174 , V_1 -> V_175 ) ;
else
F_83 ( V_180 , V_174 , V_1 -> V_175 ) ;
return true ;
}
static void F_99 ( struct V_1 * V_1 )
{
struct V_2 * V_232 = F_2 ( V_1 ) ;
struct V_190 * V_69 = F_27 ( V_232 -> V_4 . V_4 . V_69 ) ;
struct V_6 * V_7 = V_69 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_233 ;
F_45 ( L_24 , V_69 -> V_194 . V_226 ) ;
V_233 = F_25 ( V_234 ) ;
V_233 &= ~ V_235 ;
if ( V_69 -> V_194 . V_226 == 162000 ) {
F_45 ( L_25 ) ;
V_233 |= V_236 ;
V_1 -> V_237 |= V_236 ;
} else {
V_233 |= V_238 ;
V_1 -> V_237 |= V_238 ;
}
F_38 ( V_234 , V_233 ) ;
F_100 ( V_234 ) ;
F_101 ( 500 ) ;
}
static void F_102 ( struct V_94 * V_180 )
{
struct V_6 * V_7 = V_180 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_1 * V_1 = F_5 ( & V_180 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_190 * V_69 = F_27 ( V_180 -> V_4 . V_69 ) ;
struct V_30 * V_201 = & V_69 -> V_194 . V_201 ;
V_1 -> V_237 = F_25 ( V_1 -> V_167 ) & V_239 ;
V_1 -> V_237 |= V_240 | V_241 ;
V_1 -> V_237 |= F_103 ( V_1 -> V_203 ) ;
if ( V_69 -> V_194 . V_213 ) {
F_104 ( L_26 ,
F_105 ( V_69 -> V_67 ) ) ;
V_1 -> V_237 |= V_242 ;
F_106 ( & V_180 -> V_4 , V_201 ) ;
}
if ( V_21 == V_22 && F_55 ( V_7 ) && ! F_24 ( V_7 ) ) {
if ( V_201 -> V_43 & V_243 )
V_1 -> V_237 |= V_244 ;
if ( V_201 -> V_43 & V_245 )
V_1 -> V_237 |= V_246 ;
V_1 -> V_237 |= V_247 ;
if ( F_107 ( V_1 -> V_11 ) )
V_1 -> V_237 |= V_248 ;
V_1 -> V_237 |= V_69 -> V_67 << 29 ;
} else if ( ! F_108 ( V_7 ) || V_21 == V_22 ) {
if ( ! F_30 ( V_7 ) && ! F_24 ( V_7 ) )
V_1 -> V_237 |= V_1 -> V_223 ;
if ( V_201 -> V_43 & V_243 )
V_1 -> V_237 |= V_244 ;
if ( V_201 -> V_43 & V_245 )
V_1 -> V_237 |= V_246 ;
V_1 -> V_237 |= V_249 ;
if ( F_107 ( V_1 -> V_11 ) )
V_1 -> V_237 |= V_248 ;
if ( ! F_86 ( V_7 ) ) {
if ( V_69 -> V_67 == 1 )
V_1 -> V_237 |= V_250 ;
} else {
V_1 -> V_237 |= F_109 ( V_69 -> V_67 ) ;
}
} else {
V_1 -> V_237 |= V_247 ;
}
}
static void F_110 ( struct V_1 * V_1 ,
T_4 V_251 ,
T_4 V_252 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_253 , V_86 ;
V_253 = F_32 ( V_1 ) ;
V_86 = F_29 ( V_1 ) ;
F_45 ( L_27 ,
V_251 , V_252 ,
F_25 ( V_253 ) ,
F_25 ( V_86 ) ) ;
if ( F_111 ( ( F_25 ( V_253 ) & V_251 ) == V_252 , 5000 , 10 ) ) {
F_51 ( L_28 ,
F_25 ( V_253 ) ,
F_25 ( V_86 ) ) ;
}
F_45 ( L_29 ) ;
}
static void F_112 ( struct V_1 * V_1 )
{
F_45 ( L_30 ) ;
F_110 ( V_1 , V_254 , V_255 ) ;
}
static void F_113 ( struct V_1 * V_1 )
{
F_45 ( L_31 ) ;
F_110 ( V_1 , V_256 , V_257 ) ;
}
static void F_114 ( struct V_1 * V_1 )
{
F_45 ( L_32 ) ;
F_115 ( V_1 -> V_258 ,
V_1 -> V_92 ) ;
F_110 ( V_1 , V_259 , V_260 ) ;
}
static void F_116 ( struct V_1 * V_1 )
{
F_115 ( V_1 -> V_261 ,
V_1 -> V_262 ) ;
}
static void F_117 ( struct V_1 * V_1 )
{
F_115 ( V_1 -> V_263 ,
V_1 -> V_264 ) ;
}
static T_4 F_118 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_265 ;
V_265 = F_25 ( F_29 ( V_1 ) ) ;
V_265 &= ~ V_266 ;
V_265 |= V_90 ;
return V_265 ;
}
static bool F_66 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_94 * V_94 = & V_3 -> V_4 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_95 V_96 ;
T_4 V_267 ;
T_4 V_253 , V_86 ;
bool V_268 = ! V_1 -> V_269 ;
if ( ! F_1 ( V_1 ) )
return false ;
V_1 -> V_269 = true ;
if ( F_41 ( V_1 ) )
return V_268 ;
V_96 = F_42 ( V_94 ) ;
F_119 ( V_54 , V_96 ) ;
F_45 ( L_33 ) ;
if ( ! F_40 ( V_1 ) )
F_114 ( V_1 ) ;
V_267 = F_118 ( V_1 ) ;
V_267 |= V_97 ;
V_253 = F_32 ( V_1 ) ;
V_86 = F_29 ( V_1 ) ;
F_38 ( V_86 , V_267 ) ;
F_100 ( V_86 ) ;
F_45 ( L_34 ,
F_25 ( V_253 ) , F_25 ( V_86 ) ) ;
if ( ! F_40 ( V_1 ) ) {
F_45 ( L_35 ) ;
F_39 ( V_1 -> V_270 ) ;
}
return V_268 ;
}
void F_120 ( struct V_1 * V_1 )
{
if ( F_1 ( V_1 ) ) {
bool V_129 = F_66 ( V_1 ) ;
F_11 ( ! V_129 , L_36 ) ;
}
}
static void F_121 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_267 ;
T_4 V_253 , V_86 ;
F_70 ( ! F_122 ( & V_7 -> V_271 . V_272 ) ) ;
if ( ! V_1 -> V_269 && F_41 ( V_1 ) ) {
struct V_2 * V_3 =
F_2 ( V_1 ) ;
struct V_94 * V_94 = & V_3 -> V_4 ;
enum V_95 V_96 ;
F_45 ( L_37 ) ;
V_267 = F_118 ( V_1 ) ;
V_267 &= ~ V_97 ;
V_86 = F_29 ( V_1 ) ;
V_253 = F_32 ( V_1 ) ;
F_38 ( V_86 , V_267 ) ;
F_100 ( V_86 ) ;
F_45 ( L_34 ,
F_25 ( V_253 ) , F_25 ( V_86 ) ) ;
if ( ( V_267 & V_273 ) == 0 )
V_1 -> V_258 = V_274 ;
V_96 = F_42 ( V_94 ) ;
F_123 ( V_54 , V_96 ) ;
}
}
static void F_124 ( struct V_275 * V_276 )
{
struct V_1 * V_1 = F_35 ( F_125 ( V_276 ) ,
struct V_1 , V_277 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
F_126 ( & V_7 -> V_271 . V_272 , NULL ) ;
F_121 ( V_1 ) ;
F_127 ( & V_7 -> V_271 . V_272 ) ;
}
static void F_128 ( struct V_1 * V_1 )
{
unsigned long V_278 ;
V_278 = F_129 ( V_1 -> V_92 * 5 ) ;
F_130 ( & V_1 -> V_277 , V_278 ) ;
}
static void F_72 ( struct V_1 * V_1 , bool V_279 )
{
if ( ! F_1 ( V_1 ) )
return;
F_11 ( ! V_1 -> V_269 , L_38 ) ;
V_1 -> V_269 = false ;
if ( V_279 )
F_121 ( V_1 ) ;
else
F_128 ( V_1 ) ;
}
void F_131 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_267 ;
T_4 V_86 ;
if ( ! F_1 ( V_1 ) )
return;
F_45 ( L_39 ) ;
if ( F_40 ( V_1 ) ) {
F_45 ( L_40 ) ;
return;
}
F_114 ( V_1 ) ;
V_86 = F_29 ( V_1 ) ;
V_267 = F_118 ( V_1 ) ;
if ( F_132 ( V_7 ) ) {
V_267 &= ~ V_280 ;
F_38 ( V_86 , V_267 ) ;
F_100 ( V_86 ) ;
}
V_267 |= V_273 ;
if ( ! F_132 ( V_7 ) )
V_267 |= V_280 ;
F_38 ( V_86 , V_267 ) ;
F_100 ( V_86 ) ;
F_112 ( V_1 ) ;
V_1 -> V_261 = V_274 ;
if ( F_132 ( V_7 ) ) {
V_267 |= V_280 ;
F_38 ( V_86 , V_267 ) ;
F_100 ( V_86 ) ;
}
}
void F_133 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_94 * V_94 = & V_3 -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_95 V_96 ;
T_4 V_267 ;
T_4 V_86 ;
if ( ! F_1 ( V_1 ) )
return;
F_45 ( L_41 ) ;
F_11 ( ! V_1 -> V_269 , L_42 ) ;
V_267 = F_118 ( V_1 ) ;
V_267 &= ~ ( V_273 | V_280 | V_97 |
V_281 ) ;
V_86 = F_29 ( V_1 ) ;
V_1 -> V_269 = false ;
F_38 ( V_86 , V_267 ) ;
F_100 ( V_86 ) ;
V_1 -> V_258 = V_274 ;
F_113 ( V_1 ) ;
V_96 = F_42 ( V_94 ) ;
F_123 ( V_54 , V_96 ) ;
}
void F_134 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_267 ;
T_4 V_86 ;
if ( ! F_1 ( V_1 ) )
return;
F_45 ( L_43 ) ;
F_135 ( V_1 -> V_13 ) ;
F_116 ( V_1 ) ;
V_267 = F_118 ( V_1 ) ;
V_267 |= V_281 ;
V_86 = F_29 ( V_1 ) ;
F_38 ( V_86 , V_267 ) ;
F_100 ( V_86 ) ;
}
void F_136 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_267 ;
T_4 V_86 ;
if ( ! F_1 ( V_1 ) )
return;
F_45 ( L_43 ) ;
V_267 = F_118 ( V_1 ) ;
V_267 &= ~ V_281 ;
V_86 = F_29 ( V_1 ) ;
F_38 ( V_86 , V_267 ) ;
F_100 ( V_86 ) ;
V_1 -> V_263 = V_274 ;
F_117 ( V_1 ) ;
F_137 ( V_1 -> V_13 ) ;
}
static void F_138 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_68 * V_69 = V_3 -> V_4 . V_4 . V_69 ;
struct V_6 * V_7 = V_69 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_233 ;
F_139 ( V_54 ,
F_27 ( V_69 ) -> V_67 ) ;
F_45 ( L_43 ) ;
V_233 = F_25 ( V_234 ) ;
F_11 ( V_233 & V_282 , L_44 ) ;
F_11 ( V_233 & V_283 , L_45 ) ;
V_1 -> V_237 &= ~ ( V_283 | V_242 ) ;
V_1 -> V_237 |= V_282 ;
F_38 ( V_234 , V_1 -> V_237 ) ;
F_100 ( V_234 ) ;
F_101 ( 200 ) ;
}
static void F_140 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_68 * V_69 = V_3 -> V_4 . V_4 . V_69 ;
struct V_6 * V_7 = V_69 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_233 ;
F_139 ( V_54 ,
F_27 ( V_69 ) -> V_67 ) ;
V_233 = F_25 ( V_234 ) ;
F_11 ( ( V_233 & V_282 ) == 0 ,
L_46 ) ;
F_11 ( V_233 & V_283 , L_45 ) ;
V_233 &= ~ V_282 ;
F_38 ( V_234 , V_233 ) ;
F_100 ( V_234 ) ;
F_101 ( 200 ) ;
}
void F_141 ( struct V_1 * V_1 , int V_31 )
{
int V_126 , V_49 ;
if ( V_1 -> V_11 [ V_18 ] < 0x11 )
return;
if ( V_31 != V_284 ) {
V_126 = F_142 ( & V_1 -> V_142 , V_285 ,
V_286 ) ;
if ( V_126 != 1 )
F_104 ( L_47 ) ;
} else {
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
V_126 = F_142 ( & V_1 -> V_142 , V_285 ,
V_287 ) ;
if ( V_126 == 1 )
break;
F_39 ( 1 ) ;
}
}
}
static bool F_143 ( struct V_94 * V_180 ,
enum V_67 * V_67 )
{
struct V_1 * V_1 = F_5 ( & V_180 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_6 * V_7 = V_180 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_95 V_96 ;
T_4 V_288 ;
V_96 = F_42 ( V_180 ) ;
if ( ! F_43 ( V_54 , V_96 ) )
return false ;
V_288 = F_25 ( V_1 -> V_167 ) ;
if ( ! ( V_288 & V_283 ) )
return false ;
if ( V_21 == V_22 && F_55 ( V_7 ) && ! F_24 ( V_7 ) ) {
* V_67 = F_144 ( V_288 ) ;
} else if ( F_86 ( V_7 ) ) {
* V_67 = F_145 ( V_288 ) ;
} else if ( ! F_108 ( V_7 ) || V_21 == V_22 ) {
* V_67 = F_146 ( V_288 ) ;
} else {
T_4 V_289 ;
T_4 V_290 ;
int V_49 ;
switch ( V_1 -> V_167 ) {
case V_291 :
V_289 = V_292 ;
break;
case V_293 :
V_289 = V_294 ;
break;
case V_295 :
V_289 = V_296 ;
break;
default:
return true ;
}
F_147 (i) {
V_290 = F_25 ( F_148 ( V_49 ) ) ;
if ( ( V_290 & V_297 ) == V_289 ) {
* V_67 = V_49 ;
return true ;
}
}
F_45 ( L_48 ,
V_1 -> V_167 ) ;
}
return true ;
}
static void F_149 ( struct V_94 * V_180 ,
struct V_173 * V_174 )
{
struct V_1 * V_1 = F_5 ( & V_180 -> V_4 ) ;
T_4 V_288 , V_43 = 0 ;
struct V_6 * V_7 = V_180 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_190 * V_69 = F_27 ( V_180 -> V_4 . V_69 ) ;
int V_298 ;
V_288 = F_25 ( V_1 -> V_167 ) ;
if ( V_288 & V_242 )
V_174 -> V_213 = true ;
if ( ( V_21 == V_22 ) || ! F_108 ( V_7 ) ) {
if ( V_288 & V_244 )
V_43 |= V_243 ;
else
V_43 |= V_299 ;
if ( V_288 & V_246 )
V_43 |= V_245 ;
else
V_43 |= V_300 ;
} else {
V_288 = F_25 ( F_148 ( V_69 -> V_67 ) ) ;
if ( V_288 & V_301 )
V_43 |= V_243 ;
else
V_43 |= V_299 ;
if ( V_288 & V_302 )
V_43 |= V_245 ;
else
V_43 |= V_300 ;
}
V_174 -> V_201 . V_43 |= V_43 ;
if ( ! F_30 ( V_7 ) && ! F_24 ( V_7 ) &&
V_288 & V_224 )
V_174 -> V_225 = true ;
V_174 -> V_212 = true ;
F_150 ( V_69 , V_174 ) ;
if ( V_21 == V_22 ) {
if ( ( F_25 ( V_234 ) & V_235 ) == V_236 )
V_174 -> V_226 = 162000 ;
else
V_174 -> V_226 = 270000 ;
}
V_298 = F_151 ( V_174 -> V_226 ,
& V_174 -> V_227 ) ;
if ( F_30 ( V_54 -> V_7 ) && V_21 != V_22 )
F_152 ( V_174 , V_298 ) ;
V_174 -> V_201 . V_215 = V_298 ;
if ( F_1 ( V_1 ) && V_54 -> V_217 . V_218 &&
V_174 -> V_216 > V_54 -> V_217 . V_218 ) {
F_45 ( L_49 ,
V_174 -> V_216 , V_54 -> V_217 . V_218 ) ;
V_54 -> V_217 . V_218 = V_174 -> V_216 ;
}
}
static bool F_153 ( struct V_1 * V_1 )
{
return V_1 -> V_303 [ 0 ] & V_304 ;
}
static bool F_154 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
if ( ! F_155 ( V_7 ) )
return false ;
return F_25 ( F_156 ( V_7 ) ) & V_305 ;
}
static void F_157 ( struct V_1 * V_1 ,
struct V_306 * V_307 )
{
struct V_2 * V_232 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_232 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_190 * V_69 = F_27 ( V_232 -> V_4 . V_4 . V_69 ) ;
T_4 V_308 = F_158 ( V_69 -> V_194 . V_195 ) ;
T_4 V_309 = F_159 ( V_69 -> V_194 . V_195 ) ;
T_2 * V_310 = ( T_2 * ) V_307 ;
unsigned int V_49 ;
F_38 ( V_308 , 0 ) ;
F_100 ( V_308 ) ;
for ( V_49 = 0 ; V_49 < V_311 ; V_49 += 4 ) {
if ( V_49 < sizeof( struct V_306 ) )
F_38 ( V_309 + V_49 , * V_310 ++ ) ;
else
F_38 ( V_309 + V_49 , 0 ) ;
}
F_38 ( V_308 , V_312 ) ;
F_100 ( V_308 ) ;
}
static void F_160 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_306 V_313 ;
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
V_313 . V_314 . V_315 = 0 ;
V_313 . V_314 . V_316 = 0x7 ;
V_313 . V_314 . V_317 = 0x2 ;
V_313 . V_314 . V_318 = 0x8 ;
F_157 ( V_1 , & V_313 ) ;
F_38 ( F_161 ( V_7 ) , V_319 |
V_320 | V_321 ) ;
}
static void F_162 ( struct V_1 * V_1 )
{
struct V_2 * V_232 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_232 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_108 ;
int V_109 = 0x3 ;
int V_322 = 5 ;
bool V_323 = false ;
V_108 = V_1 -> V_134 ( V_1 , 0 ) ;
if ( F_63 ( V_7 ) && V_232 -> V_21 != V_22 )
V_323 = true ;
if ( V_1 -> V_303 [ 1 ] & V_324 || V_323 )
F_142 ( & V_1 -> V_142 , V_325 ,
V_326 & ~ V_327 ) ;
else
F_142 ( & V_1 -> V_142 , V_325 ,
V_326 | V_327 ) ;
F_38 ( F_163 ( V_7 ) , V_328 ) ;
F_38 ( F_164 ( V_7 ) , V_329 ) ;
F_38 ( F_165 ( V_7 ) ,
V_113 |
( V_322 << V_119 ) |
( V_109 << V_120 ) |
( V_108 << V_121 ) ) ;
}
static void F_166 ( struct V_1 * V_1 )
{
struct V_2 * V_232 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_232 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_330 = 0x1f ;
T_2 V_331 = 1 ;
T_2 V_332 = 0x0 ;
const T_2 V_333 = V_334 ;
bool V_323 = false ;
if ( F_63 ( V_7 ) && V_232 -> V_21 != V_22 )
V_323 = true ;
if ( V_1 -> V_303 [ 1 ] & V_324 || V_323 ) {
V_332 |= V_335 ;
V_332 |= V_336 ;
V_332 |= V_337 ;
V_332 |= V_338 ;
V_332 |= F_63 ( V_7 ) ? V_339 : 0 ;
} else
V_332 |= V_340 ;
F_38 ( F_156 ( V_7 ) , V_332 |
( F_63 ( V_7 ) ? 0 : V_333 ) |
V_330 << V_341 |
V_331 << V_342 |
V_305 ) ;
}
static bool F_167 ( struct V_1 * V_1 )
{
struct V_2 * V_232 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_232 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_68 * V_69 = V_232 -> V_4 . V_4 . V_69 ;
struct V_190 * V_190 = F_27 ( V_69 ) ;
F_168 ( & V_54 -> V_343 . V_344 ) ;
F_70 ( ! F_122 ( & V_7 -> V_271 . V_272 ) ) ;
F_70 ( ! F_122 ( & V_69 -> V_345 ) ) ;
V_54 -> V_343 . V_346 = false ;
if ( F_8 ( V_7 ) && V_232 -> V_21 != V_22 ) {
F_45 ( L_50 ) ;
return false ;
}
if ( ! V_347 . V_348 ) {
F_45 ( L_51 ) ;
return false ;
}
if ( F_63 ( V_7 ) )
goto V_132;
if ( F_25 ( F_169 ( V_190 -> V_194 . V_195 ) ) &
V_349 ) {
F_45 ( L_52 ) ;
return false ;
}
if ( V_190 -> V_194 . V_201 . V_43 & V_350 ) {
F_45 ( L_53 ) ;
return false ;
}
V_132:
V_54 -> V_343 . V_346 = true ;
return true ;
}
static void F_170 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
F_70 ( F_25 ( F_156 ( V_7 ) ) & V_305 ) ;
F_70 ( V_54 -> V_343 . V_351 ) ;
F_168 ( & V_54 -> V_343 . V_344 ) ;
F_162 ( V_1 ) ;
F_166 ( V_1 ) ;
V_54 -> V_343 . V_351 = true ;
}
void F_171 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( ! F_155 ( V_7 ) ) {
F_45 ( L_54 ) ;
return;
}
if ( ! F_153 ( V_1 ) ) {
F_45 ( L_55 ) ;
return;
}
F_172 ( & V_54 -> V_343 . V_344 ) ;
if ( V_54 -> V_343 . V_352 ) {
F_45 ( L_56 ) ;
F_173 ( & V_54 -> V_343 . V_344 ) ;
return;
}
V_54 -> V_343 . V_353 = 0 ;
F_160 ( V_1 ) ;
if ( F_167 ( V_1 ) )
V_54 -> V_343 . V_352 = V_1 ;
F_173 ( & V_54 -> V_343 . V_344 ) ;
}
void F_174 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
F_172 ( & V_54 -> V_343 . V_344 ) ;
if ( ! V_54 -> V_343 . V_352 ) {
F_173 ( & V_54 -> V_343 . V_344 ) ;
return;
}
if ( V_54 -> V_343 . V_351 ) {
F_38 ( F_156 ( V_7 ) ,
F_25 ( F_156 ( V_7 ) ) & ~ V_305 ) ;
if ( F_111 ( ( F_25 ( F_175 ( V_7 ) ) &
V_354 ) == 0 , 2000 , 10 ) )
F_51 ( L_57 ) ;
V_54 -> V_343 . V_351 = false ;
} else {
F_70 ( F_25 ( F_156 ( V_7 ) ) & V_305 ) ;
}
V_54 -> V_343 . V_352 = NULL ;
F_173 ( & V_54 -> V_343 . V_344 ) ;
F_176 ( & V_54 -> V_343 . V_355 ) ;
}
static void F_177 ( struct V_275 * V_355 )
{
struct V_53 * V_54 =
F_35 ( V_355 , F_36 ( * V_54 ) , V_343 . V_355 . V_355 ) ;
struct V_1 * V_1 = V_54 -> V_343 . V_352 ;
F_172 ( & V_54 -> V_343 . V_344 ) ;
V_1 = V_54 -> V_343 . V_352 ;
if ( ! V_1 )
goto V_356;
if ( V_54 -> V_343 . V_353 )
goto V_356;
F_170 ( V_1 ) ;
V_356:
F_173 ( & V_54 -> V_343 . V_344 ) ;
}
static void F_178 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
if ( V_54 -> V_343 . V_351 ) {
T_4 V_332 = F_25 ( F_156 ( V_7 ) ) ;
F_70 ( ! ( V_332 & V_305 ) ) ;
F_38 ( F_156 ( V_7 ) , V_332 & ~ V_305 ) ;
V_54 -> V_343 . V_351 = false ;
}
}
void F_179 ( struct V_6 * V_7 ,
unsigned V_357 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_68 * V_69 ;
enum V_67 V_67 ;
F_172 ( & V_54 -> V_343 . V_344 ) ;
if ( ! V_54 -> V_343 . V_352 ) {
F_173 ( & V_54 -> V_343 . V_344 ) ;
return;
}
V_69 = F_2 ( V_54 -> V_343 . V_352 ) -> V_4 . V_4 . V_69 ;
V_67 = F_27 ( V_69 ) -> V_67 ;
F_178 ( V_7 ) ;
V_357 &= F_180 ( V_67 ) ;
V_54 -> V_343 . V_353 |= V_357 ;
F_173 ( & V_54 -> V_343 . V_344 ) ;
}
void F_181 ( struct V_6 * V_7 ,
unsigned V_357 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_68 * V_69 ;
enum V_67 V_67 ;
F_172 ( & V_54 -> V_343 . V_344 ) ;
if ( ! V_54 -> V_343 . V_352 ) {
F_173 ( & V_54 -> V_343 . V_344 ) ;
return;
}
V_69 = F_2 ( V_54 -> V_343 . V_352 ) -> V_4 . V_4 . V_69 ;
V_67 = F_27 ( V_69 ) -> V_67 ;
V_54 -> V_343 . V_353 &= ~ V_357 ;
if ( F_8 ( V_7 ) &&
( V_357 & F_182 ( V_67 ) ) )
F_178 ( V_7 ) ;
if ( ! V_54 -> V_343 . V_351 && ! V_54 -> V_343 . V_353 )
F_130 ( & V_54 -> V_343 . V_355 ,
F_129 ( 100 ) ) ;
F_173 ( & V_54 -> V_343 . V_344 ) ;
}
void F_183 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
F_184 ( & V_54 -> V_343 . V_355 , F_177 ) ;
F_185 ( & V_54 -> V_343 . V_344 ) ;
}
static void F_186 ( struct V_94 * V_180 )
{
struct V_1 * V_1 = F_5 ( & V_180 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_6 * V_7 = V_180 -> V_4 . V_7 ;
F_120 ( V_1 ) ;
F_136 ( V_1 ) ;
F_141 ( V_1 , V_358 ) ;
F_133 ( V_1 ) ;
if ( ! ( V_21 == V_22 || F_24 ( V_7 ) ) )
F_187 ( V_1 ) ;
}
static void F_188 ( struct V_94 * V_180 )
{
struct V_1 * V_1 = F_5 ( & V_180 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
if ( V_21 != V_22 )
return;
F_187 ( V_1 ) ;
F_140 ( V_1 ) ;
}
static void F_189 ( struct V_94 * V_180 )
{
struct V_1 * V_1 = F_5 ( & V_180 -> V_4 ) ;
F_187 ( V_1 ) ;
}
static void F_190 ( struct V_94 * V_180 )
{
struct V_1 * V_1 = F_5 ( & V_180 -> V_4 ) ;
struct V_2 * V_359 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_180 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_190 * V_190 =
F_27 ( V_180 -> V_4 . V_69 ) ;
enum V_360 V_361 = F_191 ( V_359 ) ;
enum V_67 V_67 = V_190 -> V_67 ;
T_4 V_332 ;
F_187 ( V_1 ) ;
F_172 ( & V_54 -> V_362 ) ;
V_332 = F_192 ( V_54 , V_67 , F_193 ( V_361 ) ) ;
V_332 |= V_363 ;
F_194 ( V_54 , V_67 , F_193 ( V_361 ) , V_332 ) ;
V_332 = F_192 ( V_54 , V_67 , F_195 ( V_361 ) ) ;
V_332 |= V_363 ;
F_194 ( V_54 , V_67 , F_195 ( V_361 ) , V_332 ) ;
V_332 = F_192 ( V_54 , V_67 , F_196 ( V_361 ) ) ;
V_332 &= ~ ( V_364 | V_365 ) ;
F_194 ( V_54 , V_67 , F_196 ( V_361 ) , V_332 ) ;
V_332 = F_192 ( V_54 , V_67 , F_197 ( V_361 ) ) ;
V_332 &= ~ ( V_364 | V_365 ) ;
F_194 ( V_54 , V_67 , F_197 ( V_361 ) , V_332 ) ;
F_173 ( & V_54 -> V_362 ) ;
}
static void F_198 ( struct V_94 * V_180 )
{
struct V_1 * V_1 = F_5 ( & V_180 -> V_4 ) ;
struct V_6 * V_7 = V_180 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_366 = F_25 ( V_1 -> V_167 ) ;
if ( F_70 ( V_366 & V_283 ) )
return;
F_120 ( V_1 ) ;
F_141 ( V_1 , V_284 ) ;
F_199 ( V_1 ) ;
F_131 ( V_1 ) ;
F_72 ( V_1 , true ) ;
F_200 ( V_1 ) ;
F_201 ( V_1 ) ;
}
static void F_202 ( struct V_94 * V_180 )
{
struct V_1 * V_1 = F_5 ( & V_180 -> V_4 ) ;
F_198 ( V_180 ) ;
F_134 ( V_1 ) ;
}
static void F_203 ( struct V_94 * V_180 )
{
struct V_1 * V_1 = F_5 ( & V_180 -> V_4 ) ;
F_134 ( V_1 ) ;
}
static void F_204 ( struct V_94 * V_180 )
{
struct V_1 * V_1 = F_5 ( & V_180 -> V_4 ) ;
struct V_2 * V_359 = F_2 ( V_1 ) ;
F_102 ( V_180 ) ;
if ( V_359 -> V_21 == V_22 ) {
F_99 ( V_1 ) ;
F_138 ( V_1 ) ;
}
}
static void F_205 ( struct V_94 * V_180 )
{
struct V_1 * V_1 = F_5 ( & V_180 -> V_4 ) ;
struct V_2 * V_359 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_180 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_190 * V_190 = F_27 ( V_180 -> V_4 . V_69 ) ;
enum V_360 V_21 = F_191 ( V_359 ) ;
int V_67 = V_190 -> V_67 ;
struct V_367 V_368 ;
T_4 V_332 ;
F_172 ( & V_54 -> V_362 ) ;
V_332 = F_192 ( V_54 , V_67 , F_206 ( V_21 ) ) ;
V_332 = 0 ;
if ( V_67 )
V_332 |= ( 1 << 21 ) ;
else
V_332 &= ~ ( 1 << 21 ) ;
V_332 |= 0x001000c4 ;
F_194 ( V_54 , V_67 , F_207 ( V_21 ) , V_332 ) ;
F_194 ( V_54 , V_67 , F_208 ( V_21 ) , 0x00760018 ) ;
F_194 ( V_54 , V_67 , F_209 ( V_21 ) , 0x00400888 ) ;
F_173 ( & V_54 -> V_362 ) ;
if ( F_1 ( V_1 ) ) {
F_210 ( V_7 , V_1 , & V_368 ) ;
F_211 ( V_7 , V_1 ,
& V_368 ) ;
}
F_198 ( V_180 ) ;
F_212 ( V_54 , V_359 ) ;
}
static void F_213 ( struct V_94 * V_180 )
{
struct V_2 * V_359 = F_214 ( & V_180 -> V_4 ) ;
struct V_6 * V_7 = V_180 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_190 * V_190 =
F_27 ( V_180 -> V_4 . V_69 ) ;
enum V_360 V_21 = F_191 ( V_359 ) ;
int V_67 = V_190 -> V_67 ;
F_102 ( V_180 ) ;
F_172 ( & V_54 -> V_362 ) ;
F_194 ( V_54 , V_67 , F_215 ( V_21 ) ,
V_364 |
V_365 ) ;
F_194 ( V_54 , V_67 , F_216 ( V_21 ) ,
V_369 |
V_370 |
( 1 << V_371 ) |
V_372 ) ;
F_194 ( V_54 , V_67 , F_217 ( V_21 ) , 0x00750f00 ) ;
F_194 ( V_54 , V_67 , F_218 ( V_21 ) , 0x00001500 ) ;
F_194 ( V_54 , V_67 , F_219 ( V_21 ) , 0x40400000 ) ;
F_173 ( & V_54 -> V_362 ) ;
}
static void F_220 ( struct V_94 * V_180 )
{
struct V_1 * V_1 = F_5 ( & V_180 -> V_4 ) ;
struct V_2 * V_359 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_180 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_367 V_368 ;
struct V_190 * V_190 =
F_27 ( V_180 -> V_4 . V_69 ) ;
enum V_360 V_361 = F_191 ( V_359 ) ;
int V_67 = V_190 -> V_67 ;
int V_310 , V_49 ;
T_4 V_332 ;
F_172 ( & V_54 -> V_362 ) ;
V_332 = F_192 ( V_54 , V_67 , F_193 ( V_361 ) ) ;
V_332 |= V_363 ;
F_194 ( V_54 , V_67 , F_193 ( V_361 ) , V_332 ) ;
V_332 = F_192 ( V_54 , V_67 , F_195 ( V_361 ) ) ;
V_332 |= V_363 ;
F_194 ( V_54 , V_67 , F_195 ( V_361 ) , V_332 ) ;
V_332 = F_192 ( V_54 , V_67 , F_196 ( V_361 ) ) ;
V_332 |= ( V_364 | V_365 ) ;
F_194 ( V_54 , V_67 , F_196 ( V_361 ) , V_332 ) ;
V_332 = F_192 ( V_54 , V_67 , F_197 ( V_361 ) ) ;
V_332 |= ( V_364 | V_365 ) ;
F_194 ( V_54 , V_67 , F_197 ( V_361 ) , V_332 ) ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_310 = ( V_49 == 1 ) ? 0x0 : 0x6 ;
F_194 ( V_54 , V_67 , F_221 ( V_361 , V_49 ) ,
V_310 << V_373 ) ;
V_310 = ( V_49 == 1 ) ? 0x0 : 0x1 ;
F_194 ( V_54 , V_67 , F_222 ( V_361 , V_49 ) ,
V_310 << V_374 ) ;
}
F_173 ( & V_54 -> V_362 ) ;
if ( F_1 ( V_1 ) ) {
F_210 ( V_7 , V_1 , & V_368 ) ;
F_211 ( V_7 , V_1 ,
& V_368 ) ;
}
F_198 ( V_180 ) ;
F_212 ( V_54 , V_359 ) ;
}
static void F_223 ( struct V_94 * V_180 )
{
struct V_2 * V_359 = F_214 ( & V_180 -> V_4 ) ;
struct V_6 * V_7 = V_180 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_190 * V_190 =
F_27 ( V_180 -> V_4 . V_69 ) ;
enum V_360 V_361 = F_191 ( V_359 ) ;
enum V_67 V_67 = V_190 -> V_67 ;
T_4 V_332 ;
F_172 ( & V_54 -> V_362 ) ;
if ( V_67 != V_71 ) {
V_332 = F_192 ( V_54 , V_67 , V_375 ) ;
V_332 &= ~ ( V_376 | V_377 ) ;
if ( V_361 == V_378 )
V_332 |= V_379 ;
if ( V_361 == V_380 )
V_332 |= V_381 ;
F_194 ( V_54 , V_67 , V_375 , V_332 ) ;
} else {
V_332 = F_192 ( V_54 , V_67 , V_382 ) ;
V_332 &= ~ ( V_383 | V_384 ) ;
if ( V_361 == V_378 )
V_332 |= V_385 ;
if ( V_361 == V_380 )
V_332 |= V_386 ;
F_194 ( V_54 , V_67 , V_382 , V_332 ) ;
}
V_332 = F_192 ( V_54 , V_67 , F_206 ( V_361 ) ) ;
V_332 |= V_387 ;
if ( V_67 != V_71 )
V_332 &= ~ V_388 ;
else
V_332 |= V_388 ;
F_194 ( V_54 , V_67 , F_206 ( V_361 ) , V_332 ) ;
V_332 = F_192 ( V_54 , V_67 , F_224 ( V_361 ) ) ;
V_332 |= V_387 ;
if ( V_67 != V_71 )
V_332 &= ~ V_388 ;
else
V_332 |= V_388 ;
F_194 ( V_54 , V_67 , F_224 ( V_361 ) , V_332 ) ;
V_332 = F_192 ( V_54 , V_67 , F_225 ( V_361 ) ) ;
if ( V_67 != V_71 )
V_332 &= ~ V_389 ;
else
V_332 |= V_389 ;
F_194 ( V_54 , V_67 , F_225 ( V_361 ) , V_332 ) ;
F_173 ( & V_54 -> V_362 ) ;
}
static T_5
F_226 ( struct V_141 * V_142 , unsigned int V_390 ,
void * V_157 , T_6 V_151 )
{
T_5 V_126 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
V_126 = F_227 ( V_142 , V_390 , V_157 , V_151 ) ;
if ( V_126 == V_151 )
return V_126 ;
F_39 ( 1 ) ;
}
return V_126 ;
}
static bool
F_228 ( struct V_1 * V_1 , T_3 V_391 [ V_392 ] )
{
return F_226 ( & V_1 -> V_142 ,
V_393 ,
V_391 ,
V_392 ) == V_392 ;
}
static T_3
F_229 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
if ( F_24 ( V_7 ) )
return V_394 ;
else if ( F_55 ( V_7 ) && V_21 == V_22 )
return V_395 ;
else if ( F_108 ( V_7 ) && V_21 != V_22 )
return V_394 ;
else
return V_395 ;
}
static T_3
F_230 ( struct V_1 * V_1 , T_3 V_396 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
if ( F_8 ( V_7 ) || F_63 ( V_7 ) ) {
switch ( V_396 & V_397 ) {
case V_398 :
return V_399 ;
case V_400 :
return V_401 ;
case V_395 :
return V_402 ;
case V_394 :
default:
return V_403 ;
}
} else if ( F_24 ( V_7 ) ) {
switch ( V_396 & V_397 ) {
case V_398 :
return V_399 ;
case V_400 :
return V_401 ;
case V_395 :
return V_402 ;
case V_394 :
default:
return V_403 ;
}
} else if ( F_55 ( V_7 ) && V_21 == V_22 ) {
switch ( V_396 & V_397 ) {
case V_398 :
return V_401 ;
case V_400 :
case V_395 :
return V_402 ;
default:
return V_403 ;
}
} else {
switch ( V_396 & V_397 ) {
case V_398 :
return V_401 ;
case V_400 :
return V_401 ;
case V_395 :
return V_402 ;
case V_394 :
default:
return V_403 ;
}
}
}
static T_2 F_231 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_359 = F_2 ( V_1 ) ;
struct V_190 * V_190 =
F_27 ( V_359 -> V_4 . V_4 . V_69 ) ;
unsigned long V_404 , V_405 ,
V_406 ;
T_3 V_407 = V_1 -> V_407 [ 0 ] ;
enum V_360 V_21 = F_191 ( V_359 ) ;
int V_67 = V_190 -> V_67 ;
switch ( V_407 & V_408 ) {
case V_403 :
V_405 = 0x0004000 ;
switch ( V_407 & V_397 ) {
case V_398 :
V_404 = 0x2B405555 ;
V_406 = 0x552AB83A ;
break;
case V_400 :
V_404 = 0x2B404040 ;
V_406 = 0x5548B83A ;
break;
case V_395 :
V_404 = 0x2B245555 ;
V_406 = 0x5560B83A ;
break;
case V_394 :
V_404 = 0x2B405555 ;
V_406 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_402 :
V_405 = 0x0002000 ;
switch ( V_407 & V_397 ) {
case V_398 :
V_404 = 0x2B404040 ;
V_406 = 0x5552B83A ;
break;
case V_400 :
V_404 = 0x2B404848 ;
V_406 = 0x5580B83A ;
break;
case V_395 :
V_404 = 0x2B404040 ;
V_406 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_401 :
V_405 = 0x0000000 ;
switch ( V_407 & V_397 ) {
case V_398 :
V_404 = 0x2B305555 ;
V_406 = 0x5570B83A ;
break;
case V_400 :
V_404 = 0x2B2B4040 ;
V_406 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_399 :
V_405 = 0x0006000 ;
switch ( V_407 & V_397 ) {
case V_398 :
V_404 = 0x1B405555 ;
V_406 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_172 ( & V_54 -> V_362 ) ;
F_194 ( V_54 , V_67 , F_232 ( V_21 ) , 0x00000000 ) ;
F_194 ( V_54 , V_67 , F_233 ( V_21 ) , V_404 ) ;
F_194 ( V_54 , V_67 , F_234 ( V_21 ) ,
V_406 ) ;
F_194 ( V_54 , V_67 , F_235 ( V_21 ) , 0x0C782040 ) ;
F_194 ( V_54 , V_67 , F_236 ( V_21 ) , 0x00030000 ) ;
F_194 ( V_54 , V_67 , F_237 ( V_21 ) , V_405 ) ;
F_194 ( V_54 , V_67 , F_232 ( V_21 ) , 0x80000000 ) ;
F_173 ( & V_54 -> V_362 ) ;
return 0 ;
}
static T_2 F_238 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_359 = F_2 ( V_1 ) ;
struct V_190 * V_190 = F_27 ( V_359 -> V_4 . V_4 . V_69 ) ;
T_4 V_409 , V_410 , V_332 ;
T_3 V_407 = V_1 -> V_407 [ 0 ] ;
enum V_360 V_361 = F_191 ( V_359 ) ;
enum V_67 V_67 = V_190 -> V_67 ;
int V_49 ;
switch ( V_407 & V_408 ) {
case V_403 :
switch ( V_407 & V_397 ) {
case V_398 :
V_409 = 128 ;
V_410 = 52 ;
break;
case V_400 :
V_409 = 128 ;
V_410 = 77 ;
break;
case V_395 :
V_409 = 128 ;
V_410 = 102 ;
break;
case V_394 :
V_409 = 128 ;
V_410 = 154 ;
break;
default:
return 0 ;
}
break;
case V_402 :
switch ( V_407 & V_397 ) {
case V_398 :
V_409 = 85 ;
V_410 = 78 ;
break;
case V_400 :
V_409 = 85 ;
V_410 = 116 ;
break;
case V_395 :
V_409 = 85 ;
V_410 = 154 ;
break;
default:
return 0 ;
}
break;
case V_401 :
switch ( V_407 & V_397 ) {
case V_398 :
V_409 = 64 ;
V_410 = 104 ;
break;
case V_400 :
V_409 = 64 ;
V_410 = 154 ;
break;
default:
return 0 ;
}
break;
case V_399 :
switch ( V_407 & V_397 ) {
case V_398 :
V_409 = 43 ;
V_410 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_172 ( & V_54 -> V_362 ) ;
V_332 = F_192 ( V_54 , V_67 , F_239 ( V_361 ) ) ;
V_332 &= ~ ( V_411 | V_412 ) ;
F_194 ( V_54 , V_67 , F_239 ( V_361 ) , V_332 ) ;
V_332 = F_192 ( V_54 , V_67 , F_240 ( V_361 ) ) ;
V_332 &= ~ ( V_411 | V_412 ) ;
F_194 ( V_54 , V_67 , F_240 ( V_361 ) , V_332 ) ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_332 = F_192 ( V_54 , V_67 , F_241 ( V_361 , V_49 ) ) ;
V_332 &= ~ V_413 ;
V_332 |= V_409 << V_414 ;
F_194 ( V_54 , V_67 , F_241 ( V_361 , V_49 ) , V_332 ) ;
}
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_332 = F_192 ( V_54 , V_67 , F_242 ( V_361 , V_49 ) ) ;
V_332 &= ~ V_415 ;
V_332 |= V_410 << V_416 ;
F_194 ( V_54 , V_67 , F_242 ( V_361 , V_49 ) , V_332 ) ;
}
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_332 = F_192 ( V_54 , V_67 , F_243 ( V_361 , V_49 ) ) ;
V_332 &= ~ V_417 ;
F_194 ( V_54 , V_67 , F_243 ( V_361 , V_49 ) , V_332 ) ;
}
if ( ( ( V_407 & V_408 )
== V_403 ) &&
( ( V_407 & V_397 )
== V_394 ) ) {
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_332 = F_192 ( V_54 , V_67 , F_243 ( V_361 , V_49 ) ) ;
V_332 |= V_417 ;
F_194 ( V_54 , V_67 , F_243 ( V_361 , V_49 ) , V_332 ) ;
}
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_332 = F_192 ( V_54 , V_67 , F_242 ( V_361 , V_49 ) ) ;
V_332 &= ~ ( 0xff << V_418 ) ;
V_332 |= ( 0x9a << V_418 ) ;
F_194 ( V_54 , V_67 , F_242 ( V_361 , V_49 ) , V_332 ) ;
}
}
V_332 = F_192 ( V_54 , V_67 , F_239 ( V_361 ) ) ;
V_332 |= V_411 | V_412 ;
F_194 ( V_54 , V_67 , F_239 ( V_361 ) , V_332 ) ;
V_332 = F_192 ( V_54 , V_67 , F_240 ( V_361 ) ) ;
V_332 |= V_411 | V_412 ;
F_194 ( V_54 , V_67 , F_240 ( V_361 ) , V_332 ) ;
V_332 = F_192 ( V_54 , V_67 , V_419 ) ;
V_332 |= V_420 ;
F_194 ( V_54 , V_67 , V_419 , V_332 ) ;
F_173 ( & V_54 -> V_362 ) ;
return 0 ;
}
static void
F_244 ( struct V_1 * V_1 ,
const T_3 V_391 [ V_392 ] )
{
T_3 V_50 = 0 ;
T_3 V_421 = 0 ;
int V_422 ;
T_3 V_423 ;
T_3 V_424 ;
for ( V_422 = 0 ; V_422 < V_1 -> V_203 ; V_422 ++ ) {
T_3 V_425 = F_245 ( V_391 , V_422 ) ;
T_3 V_426 = F_246 ( V_391 , V_422 ) ;
if ( V_425 > V_50 )
V_50 = V_425 ;
if ( V_426 > V_421 )
V_421 = V_426 ;
}
V_423 = F_229 ( V_1 ) ;
if ( V_50 >= V_423 )
V_50 = V_423 | V_427 ;
V_424 = F_230 ( V_1 , V_50 ) ;
if ( V_421 >= V_424 )
V_421 = V_424 | V_428 ;
for ( V_422 = 0 ; V_422 < 4 ; V_422 ++ )
V_1 -> V_407 [ V_422 ] = V_50 | V_421 ;
}
static T_2
F_247 ( T_3 V_407 )
{
T_2 V_429 = 0 ;
switch ( V_407 & V_397 ) {
case V_398 :
default:
V_429 |= V_240 ;
break;
case V_400 :
V_429 |= V_430 ;
break;
case V_395 :
V_429 |= V_431 ;
break;
case V_394 :
V_429 |= V_432 ;
break;
}
switch ( V_407 & V_408 ) {
case V_403 :
default:
V_429 |= V_241 ;
break;
case V_402 :
V_429 |= V_433 ;
break;
case V_401 :
V_429 |= V_434 ;
break;
case V_399 :
V_429 |= V_435 ;
break;
}
return V_429 ;
}
static T_2
F_248 ( T_3 V_407 )
{
int V_429 = V_407 & ( V_397 |
V_408 ) ;
switch ( V_429 ) {
case V_398 | V_403 :
case V_400 | V_403 :
return V_436 ;
case V_398 | V_402 :
return V_437 ;
case V_398 | V_401 :
case V_400 | V_401 :
return V_438 ;
case V_400 | V_402 :
case V_395 | V_402 :
return V_439 ;
case V_395 | V_403 :
case V_394 | V_403 :
return V_440 ;
default:
F_45 ( L_58
L_59 , V_429 ) ;
return V_436 ;
}
}
static T_2
F_249 ( T_3 V_407 )
{
int V_429 = V_407 & ( V_397 |
V_408 ) ;
switch ( V_429 ) {
case V_398 | V_403 :
return V_441 ;
case V_398 | V_402 :
return V_442 ;
case V_398 | V_401 :
return V_443 ;
case V_400 | V_403 :
return V_444 ;
case V_400 | V_402 :
return V_445 ;
case V_395 | V_403 :
return V_446 ;
case V_395 | V_402 :
return V_447 ;
default:
F_45 ( L_58
L_59 , V_429 ) ;
return V_448 ;
}
}
static T_2
F_250 ( T_3 V_407 )
{
int V_429 = V_407 & ( V_397 |
V_408 ) ;
switch ( V_429 ) {
case V_398 | V_403 :
return V_449 ;
case V_398 | V_402 :
return V_450 ;
case V_398 | V_401 :
return V_451 ;
case V_398 | V_399 :
return V_452 ;
case V_400 | V_403 :
return V_453 ;
case V_400 | V_402 :
return V_454 ;
case V_400 | V_401 :
return V_455 ;
case V_395 | V_403 :
return V_456 ;
case V_395 | V_402 :
return V_457 ;
default:
F_45 ( L_58
L_59 , V_429 ) ;
return V_449 ;
}
}
static void
F_251 ( struct V_1 * V_1 , T_2 * V_237 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_21 V_21 = V_3 -> V_21 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_429 , V_251 ;
T_3 V_407 = V_1 -> V_407 [ 0 ] ;
if ( F_8 ( V_7 ) || F_63 ( V_7 ) ) {
V_429 = F_250 ( V_407 ) ;
V_251 = V_458 ;
} else if ( F_86 ( V_7 ) ) {
V_429 = F_238 ( V_1 ) ;
V_251 = 0 ;
} else if ( F_24 ( V_7 ) ) {
V_429 = F_231 ( V_1 ) ;
V_251 = 0 ;
} else if ( F_55 ( V_7 ) && V_21 == V_22 ) {
V_429 = F_249 ( V_407 ) ;
V_251 = V_459 ;
} else if ( F_54 ( V_7 ) && V_21 == V_22 ) {
V_429 = F_248 ( V_407 ) ;
V_251 = V_460 ;
} else {
V_429 = F_247 ( V_407 ) ;
V_251 = V_461 | V_462 ;
}
F_45 ( L_60 , V_429 ) ;
* V_237 = ( * V_237 & ~ V_251 ) | V_429 ;
}
static bool
F_252 ( struct V_1 * V_1 ,
T_2 * V_237 ,
T_3 V_463 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
T_3 V_464 [ sizeof( V_1 -> V_407 ) + 1 ] ;
int V_126 , V_465 ;
if ( F_13 ( V_7 ) ) {
T_2 V_466 = F_25 ( F_253 ( V_21 ) ) ;
if ( V_463 & V_467 )
V_466 |= V_468 ;
else
V_466 &= ~ V_468 ;
V_466 &= ~ V_469 ;
switch ( V_463 & V_470 ) {
case V_471 :
V_466 |= V_472 ;
break;
case V_473 :
V_466 |= V_474 ;
break;
case V_475 :
V_466 |= V_476 ;
break;
case V_477 :
V_466 |= V_478 ;
break;
}
F_38 ( F_253 ( V_21 ) , V_466 ) ;
} else if ( F_108 ( V_7 ) && ( F_55 ( V_7 ) || V_21 != V_22 ) ) {
* V_237 &= ~ V_479 ;
switch ( V_463 & V_470 ) {
case V_471 :
* V_237 |= V_247 ;
break;
case V_473 :
* V_237 |= V_480 ;
break;
case V_475 :
* V_237 |= V_481 ;
break;
case V_477 :
F_51 ( L_61 ) ;
* V_237 |= V_481 ;
break;
}
} else {
* V_237 &= ~ V_482 ;
switch ( V_463 & V_470 ) {
case V_471 :
* V_237 |= V_249 ;
break;
case V_473 :
* V_237 |= V_483 ;
break;
case V_475 :
* V_237 |= V_484 ;
break;
case V_477 :
F_51 ( L_61 ) ;
* V_237 |= V_484 ;
break;
}
}
F_38 ( V_1 -> V_167 , * V_237 ) ;
F_100 ( V_1 -> V_167 ) ;
V_464 [ 0 ] = V_463 ;
if ( ( V_463 & V_470 ) ==
V_471 ) {
V_465 = 1 ;
} else {
memcpy ( V_464 + 1 , V_1 -> V_407 , V_1 -> V_203 ) ;
V_465 = V_1 -> V_203 + 1 ;
}
V_126 = F_254 ( & V_1 -> V_142 , V_485 ,
V_464 , V_465 ) ;
return V_126 == V_465 ;
}
static bool
F_255 ( struct V_1 * V_1 , T_2 * V_237 ,
T_3 V_463 )
{
memset ( V_1 -> V_407 , 0 , sizeof( V_1 -> V_407 ) ) ;
F_251 ( V_1 , V_237 ) ;
return F_252 ( V_1 , V_237 , V_463 ) ;
}
static bool
F_256 ( struct V_1 * V_1 , T_2 * V_237 ,
const T_3 V_391 [ V_392 ] )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
int V_126 ;
F_244 ( V_1 , V_391 ) ;
F_251 ( V_1 , V_237 ) ;
F_38 ( V_1 -> V_167 , * V_237 ) ;
F_100 ( V_1 -> V_167 ) ;
V_126 = F_254 ( & V_1 -> V_142 , V_486 ,
V_1 -> V_407 , V_1 -> V_203 ) ;
return V_126 == V_1 -> V_203 ;
}
static void F_257 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
T_2 V_332 ;
if ( ! F_13 ( V_7 ) )
return;
V_332 = F_25 ( F_253 ( V_21 ) ) ;
V_332 &= ~ V_469 ;
V_332 |= V_487 ;
F_38 ( F_253 ( V_21 ) , V_332 ) ;
if ( V_21 == V_22 )
return;
if ( F_258 ( ( F_25 ( F_259 ( V_21 ) ) & V_488 ) ,
1 ) )
F_51 ( L_62 ) ;
}
void
F_199 ( struct V_1 * V_1 )
{
struct V_489 * V_180 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_180 -> V_7 ;
int V_49 ;
T_3 V_490 ;
int V_491 , V_492 ;
T_2 V_237 = V_1 -> V_237 ;
T_3 V_493 [ 2 ] ;
if ( F_13 ( V_7 ) )
F_260 ( V_180 ) ;
V_493 [ 0 ] = V_1 -> V_175 ;
V_493 [ 1 ] = V_1 -> V_203 ;
if ( F_107 ( V_1 -> V_11 ) )
V_493 [ 1 ] |= V_494 ;
F_254 ( & V_1 -> V_142 , V_495 , V_493 , 2 ) ;
V_493 [ 0 ] = 0 ;
V_493 [ 1 ] = V_496 ;
F_254 ( & V_1 -> V_142 , V_497 , V_493 , 2 ) ;
V_237 |= V_283 ;
if ( ! F_255 ( V_1 , & V_237 ,
V_473 |
V_467 ) ) {
F_51 ( L_63 ) ;
return;
}
V_490 = 0xff ;
V_491 = 0 ;
V_492 = 0 ;
for (; ; ) {
T_3 V_391 [ V_392 ] ;
F_261 ( V_1 -> V_11 ) ;
if ( ! F_228 ( V_1 , V_391 ) ) {
F_51 ( L_64 ) ;
break;
}
if ( F_262 ( V_391 , V_1 -> V_203 ) ) {
F_45 ( L_65 ) ;
break;
}
for ( V_49 = 0 ; V_49 < V_1 -> V_203 ; V_49 ++ )
if ( ( V_1 -> V_407 [ V_49 ] & V_427 ) == 0 )
break;
if ( V_49 == V_1 -> V_203 ) {
++ V_492 ;
if ( V_492 == 5 ) {
F_51 ( L_66 ) ;
break;
}
F_255 ( V_1 , & V_237 ,
V_473 |
V_467 ) ;
V_491 = 0 ;
continue;
}
if ( ( V_1 -> V_407 [ 0 ] & V_397 ) == V_490 ) {
++ V_491 ;
if ( V_491 == 5 ) {
F_51 ( L_67 ) ;
break;
}
} else
V_491 = 0 ;
V_490 = V_1 -> V_407 [ 0 ] & V_397 ;
if ( ! F_256 ( V_1 , & V_237 , V_391 ) ) {
F_51 ( L_68 ) ;
break;
}
}
V_1 -> V_237 = V_237 ;
}
void
F_200 ( struct V_1 * V_1 )
{
bool V_498 = false ;
int V_499 , V_500 ;
T_2 V_237 = V_1 -> V_237 ;
T_2 V_501 = V_475 ;
if ( V_1 -> V_175 == V_16 || V_1 -> V_502 )
V_501 = V_477 ;
if ( ! F_252 ( V_1 , & V_237 ,
V_501 |
V_467 ) ) {
F_51 ( L_69 ) ;
return;
}
V_499 = 0 ;
V_500 = 0 ;
V_498 = false ;
for (; ; ) {
T_3 V_391 [ V_392 ] ;
if ( V_500 > 5 ) {
F_51 ( L_70 ) ;
break;
}
F_263 ( V_1 -> V_11 ) ;
if ( ! F_228 ( V_1 , V_391 ) ) {
F_51 ( L_64 ) ;
break;
}
if ( ! F_262 ( V_391 , V_1 -> V_203 ) ) {
F_199 ( V_1 ) ;
F_252 ( V_1 , & V_237 ,
V_501 |
V_467 ) ;
V_500 ++ ;
continue;
}
if ( F_264 ( V_391 , V_1 -> V_203 ) ) {
V_498 = true ;
break;
}
if ( V_499 > 5 ) {
F_187 ( V_1 ) ;
F_199 ( V_1 ) ;
F_252 ( V_1 , & V_237 ,
V_501 |
V_467 ) ;
V_499 = 0 ;
V_500 ++ ;
continue;
}
if ( ! F_256 ( V_1 , & V_237 , V_391 ) ) {
F_51 ( L_68 ) ;
break;
}
++ V_499 ;
}
F_257 ( V_1 ) ;
V_1 -> V_237 = V_237 ;
if ( V_498 )
F_45 ( L_71 ) ;
}
void F_201 ( struct V_1 * V_1 )
{
F_252 ( V_1 , & V_1 -> V_237 ,
V_471 ) ;
}
static void
F_187 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_21 V_21 = V_3 -> V_21 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_190 * V_190 =
F_27 ( V_3 -> V_4 . V_4 . V_69 ) ;
T_2 V_237 = V_1 -> V_237 ;
if ( F_70 ( F_13 ( V_7 ) ) )
return;
if ( F_70 ( ( F_25 ( V_1 -> V_167 ) & V_283 ) == 0 ) )
return;
F_45 ( L_43 ) ;
if ( F_108 ( V_7 ) && ( F_55 ( V_7 ) || V_21 != V_22 ) ) {
V_237 &= ~ V_479 ;
F_38 ( V_1 -> V_167 , V_237 | V_503 ) ;
} else {
V_237 &= ~ V_482 ;
F_38 ( V_1 -> V_167 , V_237 | V_504 ) ;
}
F_100 ( V_1 -> V_167 ) ;
if ( F_265 ( V_7 ) &&
F_25 ( V_1 -> V_167 ) & V_250 ) {
struct V_68 * V_69 = V_3 -> V_4 . V_4 . V_69 ;
V_237 &= ~ V_250 ;
F_38 ( V_1 -> V_167 , V_237 ) ;
if ( F_70 ( V_69 == NULL ) ) {
F_100 ( V_1 -> V_167 ) ;
F_39 ( 50 ) ;
} else
F_266 ( V_7 , V_190 -> V_67 ) ;
}
V_237 &= ~ V_242 ;
F_38 ( V_1 -> V_167 , V_237 & ~ V_283 ) ;
F_100 ( V_1 -> V_167 ) ;
F_39 ( V_1 -> V_505 ) ;
}
static bool
F_267 ( struct V_1 * V_1 )
{
struct V_2 * V_232 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_232 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
char V_506 [ sizeof( V_1 -> V_11 ) * 3 ] ;
if ( F_226 ( & V_1 -> V_142 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) < 0 )
return false ;
F_268 ( V_1 -> V_11 , sizeof( V_1 -> V_11 ) ,
32 , 1 , V_506 , sizeof( V_506 ) , false ) ;
F_45 ( L_72 , V_506 ) ;
if ( V_1 -> V_11 [ V_18 ] == 0 )
return false ;
memset ( V_1 -> V_303 , 0 , sizeof( V_1 -> V_303 ) ) ;
if ( F_1 ( V_1 ) ) {
F_226 ( & V_1 -> V_142 , V_507 ,
V_1 -> V_303 ,
sizeof( V_1 -> V_303 ) ) ;
if ( V_1 -> V_303 [ 0 ] & V_304 ) {
V_54 -> V_343 . V_508 = true ;
F_45 ( L_73 ) ;
}
}
if ( V_1 -> V_11 [ V_18 ] >= 0x12 &&
V_1 -> V_11 [ V_509 ] & V_510 ) {
V_1 -> V_502 = true ;
F_45 ( L_74 ) ;
} else
V_1 -> V_502 = false ;
if ( ! ( V_1 -> V_11 [ V_511 ] &
V_512 ) )
return true ;
if ( V_1 -> V_11 [ V_18 ] == 0x10 )
return true ;
if ( F_226 ( & V_1 -> V_142 , V_513 ,
V_1 -> V_514 ,
V_515 ) < 0 )
return false ;
return true ;
}
static void
F_269 ( struct V_1 * V_1 )
{
T_1 V_464 [ 3 ] ;
if ( ! ( V_1 -> V_11 [ V_516 ] & V_517 ) )
return;
F_120 ( V_1 ) ;
if ( F_226 ( & V_1 -> V_142 , V_518 , V_464 , 3 ) == 3 )
F_45 ( L_75 ,
V_464 [ 0 ] , V_464 [ 1 ] , V_464 [ 2 ] ) ;
if ( F_226 ( & V_1 -> V_142 , V_519 , V_464 , 3 ) == 3 )
F_45 ( L_76 ,
V_464 [ 0 ] , V_464 [ 1 ] , V_464 [ 2 ] ) ;
F_72 ( V_1 , false ) ;
}
static bool
F_270 ( struct V_1 * V_1 )
{
T_1 V_464 [ 1 ] ;
if ( ! V_1 -> V_520 )
return false ;
if ( V_1 -> V_11 [ V_18 ] < 0x12 )
return false ;
F_66 ( V_1 ) ;
if ( F_226 ( & V_1 -> V_142 , V_521 , V_464 , 1 ) ) {
if ( V_464 [ 0 ] & V_522 ) {
F_45 ( L_77 ) ;
V_1 -> V_523 = true ;
} else {
F_45 ( L_78 ) ;
V_1 -> V_523 = false ;
}
}
F_72 ( V_1 , false ) ;
F_271 ( & V_1 -> V_524 , V_1 -> V_523 ) ;
return V_1 -> V_523 ;
}
int F_272 ( struct V_1 * V_1 , T_1 * V_525 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_190 * V_190 =
F_27 ( V_3 -> V_4 . V_4 . V_69 ) ;
T_1 V_464 [ 1 ] ;
if ( F_273 ( & V_1 -> V_142 , V_526 , V_464 ) < 0 )
return - V_527 ;
if ( ! ( V_464 [ 0 ] & V_528 ) )
return - V_529 ;
if ( F_142 ( & V_1 -> V_142 , V_530 ,
V_531 ) < 0 )
return - V_527 ;
F_266 ( V_7 , V_190 -> V_67 ) ;
F_266 ( V_7 , V_190 -> V_67 ) ;
if ( F_227 ( & V_1 -> V_142 , V_532 , V_525 , 6 ) < 0 )
return - V_527 ;
F_142 ( & V_1 -> V_142 , V_530 , 0 ) ;
return 0 ;
}
static bool
F_274 ( struct V_1 * V_1 , T_1 * V_533 )
{
return F_226 ( & V_1 -> V_142 ,
V_534 ,
V_533 , 1 ) == 1 ;
}
static bool
F_275 ( struct V_1 * V_1 , T_1 * V_533 )
{
int V_126 ;
V_126 = F_226 ( & V_1 -> V_142 ,
V_535 ,
V_533 , 14 ) ;
if ( V_126 != 14 )
return false ;
return true ;
}
static void
F_276 ( struct V_1 * V_1 )
{
F_142 ( & V_1 -> V_142 , V_536 , V_537 ) ;
}
static int
F_277 ( struct V_1 * V_1 )
{
bool V_538 ;
if ( V_1 -> V_523 ) {
T_1 V_539 [ 16 ] = { 0 } ;
int V_126 = 0 ;
int V_540 ;
bool V_541 ;
V_538 = F_275 ( V_1 , V_539 ) ;
V_542:
if ( V_538 == true ) {
if ( V_1 -> V_543 && ! F_264 ( & V_539 [ 10 ] , V_1 -> V_203 ) ) {
F_45 ( L_79 ) ;
F_199 ( V_1 ) ;
F_200 ( V_1 ) ;
F_201 ( V_1 ) ;
}
F_45 ( L_80 , V_539 [ 0 ] , V_539 [ 1 ] , V_539 [ 2 ] ) ;
V_126 = F_278 ( & V_1 -> V_524 , V_539 , & V_541 ) ;
if ( V_541 ) {
for ( V_540 = 0 ; V_540 < 3 ; V_540 ++ ) {
int V_544 ;
V_544 = F_254 ( & V_1 -> V_142 ,
V_535 + 1 ,
& V_539 [ 1 ] , 3 ) ;
if ( V_544 == 3 ) {
break;
}
}
V_538 = F_275 ( V_1 , V_539 ) ;
if ( V_538 == true ) {
F_45 ( L_81 , V_539 [ 0 ] , V_539 [ 1 ] , V_539 [ 2 ] ) ;
goto V_542;
}
} else
V_126 = 0 ;
return V_126 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_45 ( L_82 ) ;
V_1 -> V_523 = false ;
F_271 ( & V_1 -> V_524 , V_1 -> V_523 ) ;
F_279 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_161 ;
}
void
F_280 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_94 * V_94 = & F_2 ( V_1 ) -> V_4 ;
T_1 V_533 ;
T_1 V_391 [ V_392 ] ;
F_70 ( ! F_122 ( & V_7 -> V_271 . V_272 ) ) ;
if ( ! V_94 -> V_545 )
return;
if ( F_70 ( ! V_94 -> V_4 . V_69 ) )
return;
if ( ! F_27 ( V_94 -> V_4 . V_69 ) -> V_351 )
return;
if ( ! F_228 ( V_1 , V_391 ) ) {
return;
}
if ( ! F_267 ( V_1 ) ) {
return;
}
if ( V_1 -> V_11 [ V_18 ] >= 0x11 &&
F_274 ( V_1 , & V_533 ) ) {
F_142 ( & V_1 -> V_142 ,
V_534 ,
V_533 ) ;
if ( V_533 & V_546 )
F_276 ( V_1 ) ;
if ( V_533 & ( V_547 | V_548 ) )
F_104 ( L_83 ) ;
}
if ( ! F_264 ( V_391 , V_1 -> V_203 ) ) {
F_45 ( L_84 ,
V_94 -> V_4 . V_162 ) ;
F_199 ( V_1 ) ;
F_200 ( V_1 ) ;
F_201 ( V_1 ) ;
}
}
static enum V_549
F_281 ( struct V_1 * V_1 )
{
T_3 * V_11 = V_1 -> V_11 ;
T_3 type ;
if ( ! F_267 ( V_1 ) )
return V_550 ;
if ( ! ( V_11 [ V_511 ] & V_512 ) )
return V_551 ;
if ( V_1 -> V_11 [ V_18 ] >= 0x11 &&
V_1 -> V_514 [ 0 ] & V_552 ) {
T_3 V_553 ;
if ( F_226 ( & V_1 -> V_142 , V_554 ,
& V_553 , 1 ) < 0 )
return V_555 ;
return F_282 ( V_553 ) ? V_551
: V_550 ;
}
if ( F_283 ( & V_1 -> V_142 . V_171 ) )
return V_551 ;
if ( V_1 -> V_11 [ V_18 ] >= 0x11 ) {
type = V_1 -> V_514 [ 0 ] & V_556 ;
if ( type == V_557 ||
type == V_558 )
return V_555 ;
} else {
type = V_1 -> V_11 [ V_511 ] &
V_559 ;
if ( type == V_560 ||
type == V_561 )
return V_555 ;
}
F_45 ( L_85 ) ;
return V_550 ;
}
static enum V_549
F_284 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_549 V_101 ;
if ( F_1 ( V_1 ) ) {
V_101 = F_285 ( V_7 ) ;
if ( V_101 == V_555 )
V_101 = V_551 ;
return V_101 ;
}
if ( ! F_286 ( V_54 , V_3 ) )
return V_550 ;
return F_281 ( V_1 ) ;
}
static int F_287 ( struct V_6 * V_7 ,
struct V_2 * V_3 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_562 ;
if ( F_24 ( V_7 ) ) {
switch ( V_3 -> V_21 ) {
case V_75 :
V_562 = V_563 ;
break;
case V_77 :
V_562 = V_564 ;
break;
case V_165 :
V_562 = V_565 ;
break;
default:
return - V_161 ;
}
} else {
switch ( V_3 -> V_21 ) {
case V_75 :
V_562 = V_566 ;
break;
case V_77 :
V_562 = V_567 ;
break;
case V_165 :
V_562 = V_568 ;
break;
default:
return - V_161 ;
}
}
if ( ( F_25 ( V_569 ) & V_562 ) == 0 )
return 0 ;
return 1 ;
}
static enum V_549
F_288 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_126 ;
if ( F_1 ( V_1 ) ) {
enum V_549 V_101 ;
V_101 = F_285 ( V_7 ) ;
if ( V_101 == V_555 )
V_101 = V_551 ;
return V_101 ;
}
V_126 = F_287 ( V_7 , V_3 ) ;
if ( V_126 == - V_161 )
return V_555 ;
else if ( V_126 == 0 )
return V_550 ;
return F_281 ( V_1 ) ;
}
static struct V_570 *
F_289 ( struct V_8 * V_9 , struct V_571 * V_572 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
if ( V_32 -> V_570 ) {
if ( F_290 ( V_32 -> V_570 ) )
return NULL ;
return F_291 ( V_32 -> V_570 ) ;
}
return F_292 ( V_9 , V_572 ) ;
}
static int
F_293 ( struct V_8 * V_9 , struct V_571 * V_572 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
if ( V_32 -> V_570 ) {
if ( F_290 ( V_32 -> V_570 ) )
return 0 ;
return F_294 ( V_9 ,
V_32 -> V_570 ) ;
}
return F_295 ( V_9 , V_572 ) ;
}
static enum V_549
F_296 ( struct V_8 * V_9 , bool V_573 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_94 * V_94 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_549 V_101 ;
enum V_95 V_96 ;
struct V_570 * V_570 = NULL ;
bool V_126 ;
V_96 = F_42 ( V_94 ) ;
F_119 ( V_54 , V_96 ) ;
F_45 ( L_86 ,
V_9 -> V_4 . V_574 , V_9 -> V_162 ) ;
if ( V_1 -> V_523 ) {
if ( V_94 -> type != V_5 )
V_94 -> type = V_575 ;
V_101 = V_550 ;
goto V_132;
}
V_1 -> V_213 = false ;
if ( F_30 ( V_7 ) )
V_101 = F_284 ( V_1 ) ;
else
V_101 = F_288 ( V_1 ) ;
if ( V_101 != V_551 )
goto V_132;
F_269 ( V_1 ) ;
V_126 = F_270 ( V_1 ) ;
if ( V_126 ) {
if ( V_94 -> type != V_5 )
V_94 -> type = V_575 ;
V_101 = V_550 ;
goto V_132;
}
if ( V_1 -> V_576 != V_577 ) {
V_1 -> V_213 = ( V_1 -> V_576 == V_578 ) ;
} else {
V_570 = F_289 ( V_9 , & V_1 -> V_142 . V_171 ) ;
if ( V_570 ) {
V_1 -> V_213 = F_297 ( V_570 ) ;
F_298 ( V_570 ) ;
}
}
if ( V_94 -> type != V_5 )
V_94 -> type = V_575 ;
V_101 = V_551 ;
V_132:
F_123 ( V_54 , V_96 ) ;
return V_101 ;
}
static int F_299 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_94 * V_94 = & V_3 -> V_4 ;
struct V_32 * V_32 = F_19 ( V_9 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_95 V_96 ;
int V_126 ;
V_96 = F_42 ( V_94 ) ;
F_119 ( V_54 , V_96 ) ;
V_126 = F_293 ( V_9 , & V_1 -> V_142 . V_171 ) ;
F_123 ( V_54 , V_96 ) ;
if ( V_126 )
return V_126 ;
if ( F_1 ( V_1 ) && V_32 -> V_34 . V_33 ) {
struct V_30 * V_31 ;
V_31 = F_300 ( V_7 ,
V_32 -> V_34 . V_33 ) ;
if ( V_31 ) {
F_301 ( V_9 , V_31 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_302 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_94 * V_94 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_95 V_96 ;
struct V_570 * V_570 ;
bool V_213 = false ;
V_96 = F_42 ( V_94 ) ;
F_119 ( V_54 , V_96 ) ;
V_570 = F_289 ( V_9 , & V_1 -> V_142 . V_171 ) ;
if ( V_570 ) {
V_213 = F_297 ( V_570 ) ;
F_298 ( V_570 ) ;
}
F_123 ( V_54 , V_96 ) ;
return V_213 ;
}
static int
F_303 ( struct V_8 * V_9 ,
struct V_579 * V_580 ,
T_7 V_332 )
{
struct V_53 * V_54 = V_9 -> V_7 -> V_55 ;
struct V_32 * V_32 = F_19 ( V_9 ) ;
struct V_94 * V_94 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_94 -> V_4 ) ;
int V_126 ;
V_126 = F_304 ( & V_9 -> V_4 , V_580 , V_332 ) ;
if ( V_126 )
return V_126 ;
if ( V_580 == V_54 -> V_581 ) {
int V_49 = V_332 ;
bool V_213 ;
if ( V_49 == V_1 -> V_576 )
return 0 ;
V_1 -> V_576 = V_49 ;
if ( V_49 == V_577 )
V_213 = F_302 ( V_9 ) ;
else
V_213 = ( V_49 == V_578 ) ;
if ( V_213 == V_1 -> V_213 )
return 0 ;
V_1 -> V_213 = V_213 ;
goto V_102;
}
if ( V_580 == V_54 -> V_582 ) {
bool V_583 = V_1 -> V_222 ;
T_2 V_584 = V_1 -> V_223 ;
switch ( V_332 ) {
case V_585 :
V_1 -> V_222 = true ;
break;
case V_586 :
V_1 -> V_222 = false ;
V_1 -> V_223 = 0 ;
break;
case V_587 :
V_1 -> V_222 = false ;
V_1 -> V_223 = V_224 ;
break;
default:
return - V_161 ;
}
if ( V_583 == V_1 -> V_222 &&
V_584 == V_1 -> V_223 )
return 0 ;
goto V_102;
}
if ( F_1 ( V_1 ) &&
V_580 == V_9 -> V_7 -> V_271 . V_588 ) {
if ( V_332 == V_589 ) {
F_45 ( L_87 ) ;
return - V_161 ;
}
if ( V_32 -> V_34 . V_214 == V_332 ) {
return 0 ;
}
V_32 -> V_34 . V_214 = V_332 ;
goto V_102;
}
return - V_161 ;
V_102:
if ( V_94 -> V_4 . V_69 )
F_305 ( V_94 -> V_4 . V_69 ) ;
return 0 ;
}
static void
F_306 ( struct V_8 * V_9 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
if ( ! F_307 ( V_32 -> V_570 ) )
F_298 ( V_32 -> V_570 ) ;
if ( V_9 -> V_590 == V_591 )
F_308 ( & V_32 -> V_34 ) ;
F_309 ( V_9 ) ;
F_298 ( V_9 ) ;
}
void F_310 ( struct V_489 * V_180 )
{
struct V_2 * V_3 = F_214 ( V_180 ) ;
struct V_1 * V_1 = & V_3 -> V_592 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
F_78 ( & V_1 -> V_142 ) ;
F_311 ( V_3 ) ;
F_312 ( V_180 ) ;
if ( F_1 ( V_1 ) ) {
F_176 ( & V_1 -> V_277 ) ;
F_126 ( & V_7 -> V_271 . V_272 , NULL ) ;
F_121 ( V_1 ) ;
F_127 ( & V_7 -> V_271 . V_272 ) ;
if ( V_1 -> V_84 . V_593 ) {
F_313 ( & V_1 -> V_84 ) ;
V_1 -> V_84 . V_593 = NULL ;
}
}
F_298 ( V_3 ) ;
}
static void F_314 ( struct V_94 * V_94 )
{
struct V_1 * V_1 = F_5 ( & V_94 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_121 ( V_1 ) ;
}
static void F_315 ( struct V_489 * V_180 )
{
F_316 ( F_317 ( V_180 ) ) ;
}
void
F_318 ( struct V_94 * V_94 )
{
return;
}
bool
F_319 ( struct V_2 * V_3 , bool V_594 )
{
struct V_1 * V_1 = & V_3 -> V_592 ;
struct V_94 * V_94 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_95 V_96 ;
bool V_126 = true ;
if ( V_3 -> V_4 . type != V_5 )
V_3 -> V_4 . type = V_575 ;
F_45 ( L_88 , V_3 -> V_21 ,
V_594 ? L_89 : L_90 ) ;
V_96 = F_42 ( V_94 ) ;
F_119 ( V_54 , V_96 ) ;
if ( V_594 ) {
if ( F_30 ( V_7 ) ) {
if ( ! F_286 ( V_54 , V_3 ) )
goto V_595;
} else {
if ( F_287 ( V_7 , V_3 ) != 1 )
goto V_595;
}
if ( ! F_267 ( V_1 ) ) {
goto V_595;
}
F_269 ( V_1 ) ;
if ( ! F_270 ( V_1 ) )
goto V_595;
} else {
if ( V_1 -> V_523 ) {
if ( F_277 ( V_1 ) == - V_161 )
goto V_595;
}
if ( ! V_1 -> V_523 ) {
F_126 ( & V_7 -> V_271 . V_272 , NULL ) ;
F_280 ( V_1 ) ;
F_127 ( & V_7 -> V_271 . V_272 ) ;
}
}
V_126 = false ;
goto V_596;
V_595:
if ( V_1 -> V_523 ) {
F_45 ( L_91 , V_1 -> V_523 , V_1 -> V_524 . V_597 ) ;
V_1 -> V_523 = false ;
F_271 ( & V_1 -> V_524 , V_1 -> V_523 ) ;
}
V_596:
F_123 ( V_54 , V_96 ) ;
return V_126 ;
}
int
F_320 ( struct V_68 * V_69 )
{
struct V_6 * V_7 = V_69 -> V_7 ;
struct V_94 * V_94 ;
struct V_1 * V_1 ;
F_321 (dev, crtc, intel_encoder) {
V_1 = F_5 ( & V_94 -> V_4 ) ;
if ( V_94 -> type == V_575 ||
V_94 -> type == V_5 )
return V_1 -> V_167 ;
}
return - 1 ;
}
bool F_322 ( struct V_6 * V_7 , enum V_21 V_21 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
union V_598 * V_599 ;
int V_49 ;
static const short V_600 [] = {
[ V_75 ] = V_601 ,
[ V_77 ] = V_602 ,
[ V_165 ] = V_603 ,
} ;
if ( V_21 == V_22 )
return true ;
if ( ! V_54 -> V_217 . V_604 )
return false ;
for ( V_49 = 0 ; V_49 < V_54 -> V_217 . V_604 ; V_49 ++ ) {
V_599 = V_54 -> V_217 . V_605 + V_49 ;
if ( V_599 -> V_606 . V_607 == V_600 [ V_21 ] &&
( V_599 -> V_606 . V_608 & V_609 ) ==
( V_610 & V_609 ) )
return true ;
}
return false ;
}
void
F_323 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
F_324 ( V_9 ) ;
F_325 ( V_9 ) ;
V_1 -> V_222 = true ;
if ( F_1 ( V_1 ) ) {
F_326 ( V_9 -> V_7 ) ;
F_327 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_271 . V_588 ,
V_611 ) ;
V_32 -> V_34 . V_214 = V_611 ;
}
}
static void F_328 ( struct V_1 * V_1 )
{
V_1 -> V_258 = V_274 ;
V_1 -> V_261 = V_274 ;
V_1 -> V_263 = V_274 ;
}
static void
F_210 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_367 * V_132 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_367 V_612 , V_217 , V_613 , V_614 ;
T_4 V_615 , V_616 , V_85 , V_267 ;
int V_86 , V_617 , V_618 , V_87 ;
if ( F_30 ( V_7 ) ) {
V_86 = V_78 ;
V_617 = V_619 ;
V_618 = V_620 ;
V_87 = V_621 ;
} else {
enum V_67 V_67 = F_26 ( V_1 ) ;
V_86 = F_31 ( V_67 ) ;
V_617 = F_28 ( V_67 ) ;
V_618 = F_329 ( V_67 ) ;
V_87 = F_37 ( V_67 ) ;
}
V_267 = F_118 ( V_1 ) ;
F_38 ( V_86 , V_267 ) ;
V_615 = F_25 ( V_617 ) ;
V_616 = F_25 ( V_618 ) ;
V_85 = F_25 ( V_87 ) ;
V_612 . V_622 = ( V_615 & V_623 ) >>
V_624 ;
V_612 . V_625 = ( V_615 & V_626 ) >>
V_627 ;
V_612 . V_628 = ( V_616 & V_629 ) >>
V_630 ;
V_612 . V_631 = ( V_616 & V_632 ) >>
V_633 ;
V_612 . V_634 = ( ( V_85 & V_635 ) >>
V_636 ) * 1000 ;
F_45 ( L_92 ,
V_612 . V_622 , V_612 . V_625 , V_612 . V_628 , V_612 . V_631 , V_612 . V_634 ) ;
V_217 = V_54 -> V_217 . V_637 ;
V_613 . V_622 = 210 * 10 ;
V_613 . V_625 = 50 * 10 ;
V_613 . V_628 = 50 * 10 ;
V_613 . V_631 = 500 * 10 ;
V_613 . V_634 = ( 510 + 100 ) * 10 ;
F_45 ( L_93 ,
V_217 . V_622 , V_217 . V_625 , V_217 . V_628 , V_217 . V_631 , V_217 . V_634 ) ;
#define F_330 ( T_8 ) final.field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_330 ( V_622 ) ;
F_330 ( V_625 ) ;
F_330 ( V_628 ) ;
F_330 ( V_631 ) ;
F_330 ( V_634 ) ;
#undef F_330
#define F_331 ( T_8 ) (DIV_ROUND_UP(final.field, 10))
V_1 -> V_270 = F_331 ( V_622 ) ;
V_1 -> V_262 = F_331 ( V_625 ) ;
V_1 -> V_264 = F_331 ( V_628 ) ;
V_1 -> V_505 = F_331 ( V_631 ) ;
V_1 -> V_92 = F_331 ( V_634 ) ;
#undef F_331
F_45 ( L_94 ,
V_1 -> V_270 , V_1 -> V_505 ,
V_1 -> V_92 ) ;
F_45 ( L_95 ,
V_1 -> V_262 , V_1 -> V_264 ) ;
if ( V_132 )
* V_132 = V_614 ;
}
static void
F_211 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_367 * V_638 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_615 , V_616 , V_85 , V_72 = 0 ;
int div = F_30 ( V_7 ) ? F_57 ( V_7 ) : F_23 ( V_7 ) ;
int V_617 , V_618 , V_87 ;
if ( F_30 ( V_7 ) ) {
V_617 = V_619 ;
V_618 = V_620 ;
V_87 = V_621 ;
} else {
enum V_67 V_67 = F_26 ( V_1 ) ;
V_617 = F_28 ( V_67 ) ;
V_618 = F_329 ( V_67 ) ;
V_87 = F_37 ( V_67 ) ;
}
V_615 = ( V_638 -> V_622 << V_624 ) |
( 1 << V_627 ) ;
V_616 = ( 1 << V_630 ) |
( V_638 -> V_631 << V_633 ) ;
V_85 = ( ( 100 * div ) / 2 - 1 ) << V_639 ;
V_85 |= ( F_56 ( V_638 -> V_634 , 1000 )
<< V_636 ) ;
if ( F_24 ( V_7 ) ) {
if ( F_2 ( V_1 ) -> V_21 == V_75 )
V_72 = V_74 ;
else
V_72 = V_76 ;
} else if ( F_265 ( V_7 ) || F_108 ( V_7 ) ) {
if ( F_2 ( V_1 ) -> V_21 == V_22 )
V_72 = V_640 ;
else
V_72 = V_641 ;
}
V_615 |= V_72 ;
F_38 ( V_617 , V_615 ) ;
F_38 ( V_618 , V_616 ) ;
F_38 ( V_87 , V_85 ) ;
F_45 ( L_96 ,
F_25 ( V_617 ) ,
F_25 ( V_618 ) ,
F_25 ( V_87 ) ) ;
}
void F_332 ( struct V_6 * V_7 , int V_642 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_94 * V_180 ;
struct V_1 * V_1 = NULL ;
struct V_173 * V_194 = NULL ;
struct V_190 * V_190 = NULL ;
struct V_32 * V_32 = V_54 -> V_643 . V_9 ;
T_4 V_553 , V_332 ;
enum V_644 V_104 = V_645 ;
if ( V_642 <= 0 ) {
F_45 ( L_97 ) ;
return;
}
if ( V_32 == NULL ) {
F_45 ( L_98 ) ;
return;
}
if ( F_10 ( V_7 ) -> V_17 < 8 && F_154 ( V_7 ) ) {
F_45 ( L_99 ) ;
return;
}
V_180 = F_6 ( & V_32 -> V_4 ) ;
V_1 = F_5 ( & V_180 -> V_4 ) ;
V_190 = V_180 -> V_202 ;
if ( ! V_190 ) {
F_45 ( L_100 ) ;
return;
}
V_194 = & V_190 -> V_194 ;
if ( V_1 -> V_229 . type < V_230 ) {
F_45 ( L_101 ) ;
return;
}
if ( V_32 -> V_34 . V_228 -> V_646 == V_642 )
V_104 = V_647 ;
if ( V_104 == V_1 -> V_229 . V_648 ) {
F_45 (
L_102 ) ;
return;
}
if ( ! V_190 -> V_351 ) {
F_45 ( L_103 ) ;
return;
}
if ( F_10 ( V_7 ) -> V_17 > 6 && F_10 ( V_7 ) -> V_17 < 8 ) {
V_553 = F_333 ( V_190 -> V_194 . V_195 ) ;
V_332 = F_25 ( V_553 ) ;
if ( V_104 > V_645 ) {
V_332 |= V_649 ;
F_87 ( V_190 , & V_194 -> V_231 ) ;
} else {
V_332 &= ~ V_649 ;
}
F_38 ( V_553 , V_332 ) ;
}
F_172 ( & V_1 -> V_229 . V_345 ) ;
V_1 -> V_229 . V_648 = V_104 ;
F_173 ( & V_1 -> V_229 . V_345 ) ;
F_45 ( L_104 , V_642 ) ;
}
static struct V_30 *
F_334 ( struct V_2 * V_3 ,
struct V_32 * V_32 ,
struct V_30 * V_33 )
{
struct V_8 * V_9 = & V_32 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_592 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_30 * V_228 = NULL ;
if ( F_10 ( V_7 ) -> V_17 <= 6 ) {
F_45 ( L_105 ) ;
return NULL ;
}
if ( V_54 -> V_217 . V_650 != V_230 ) {
F_335 ( L_106 ) ;
return NULL ;
}
V_228 = F_336
( V_7 , V_33 , V_9 ) ;
if ( ! V_228 ) {
F_335 ( L_107 ) ;
return NULL ;
}
V_54 -> V_643 . V_9 = V_32 ;
F_185 ( & V_1 -> V_229 . V_345 ) ;
V_1 -> V_229 . type = V_54 -> V_217 . V_650 ;
V_1 -> V_229 . V_648 = V_645 ;
F_335 ( L_108 ) ;
return V_228 ;
}
void F_316 ( struct V_94 * V_94 )
{
struct V_6 * V_7 = V_94 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_1 * V_1 ;
enum V_95 V_96 ;
if ( V_94 -> type != V_5 )
return;
V_1 = F_5 ( & V_94 -> V_4 ) ;
if ( ! F_41 ( V_1 ) )
return;
F_45 ( L_109 ) ;
V_96 = F_42 ( V_94 ) ;
F_119 ( V_54 , V_96 ) ;
F_128 ( V_1 ) ;
}
static bool F_337 ( struct V_1 * V_1 ,
struct V_32 * V_32 ,
struct V_367 * V_368 )
{
struct V_8 * V_9 = & V_32 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_94 * V_94 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_94 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_30 * V_33 = NULL ;
struct V_30 * V_228 = NULL ;
bool V_651 ;
struct V_30 * V_652 ;
struct V_570 * V_570 ;
V_1 -> V_229 . type = V_653 ;
if ( ! F_1 ( V_1 ) )
return true ;
F_316 ( V_94 ) ;
F_120 ( V_1 ) ;
V_651 = F_267 ( V_1 ) ;
F_72 ( V_1 , false ) ;
if ( V_651 ) {
if ( V_1 -> V_11 [ V_18 ] >= 0x11 )
V_54 -> V_654 =
V_1 -> V_11 [ V_655 ] &
V_656 ;
} else {
F_335 ( L_110 ) ;
return false ;
}
F_211 ( V_7 , V_1 , V_368 ) ;
F_172 ( & V_7 -> V_271 . V_345 ) ;
V_570 = F_292 ( V_9 , & V_1 -> V_142 . V_171 ) ;
if ( V_570 ) {
if ( F_338 ( V_9 , V_570 ) ) {
F_339 ( V_9 ,
V_570 ) ;
F_340 ( V_9 , V_570 ) ;
} else {
F_298 ( V_570 ) ;
V_570 = F_341 ( - V_161 ) ;
}
} else {
V_570 = F_341 ( - V_657 ) ;
}
V_32 -> V_570 = V_570 ;
F_342 (scan, &connector->probed_modes, head) {
if ( ( V_652 -> type & V_658 ) ) {
V_33 = F_300 ( V_7 , V_652 ) ;
V_228 = F_334 (
V_3 ,
V_32 , V_33 ) ;
break;
}
}
if ( ! V_33 && V_54 -> V_217 . V_659 ) {
V_33 = F_300 ( V_7 ,
V_54 -> V_217 . V_659 ) ;
if ( V_33 )
V_33 -> type |= V_658 ;
}
F_173 ( & V_7 -> V_271 . V_345 ) ;
if ( F_24 ( V_7 ) ) {
V_1 -> V_84 . V_593 = F_34 ;
F_343 ( & V_1 -> V_84 ) ;
}
F_344 ( & V_32 -> V_34 , V_33 , V_228 ) ;
F_345 ( V_9 ) ;
return true ;
}
bool
F_346 ( struct V_2 * V_3 ,
struct V_32 * V_32 )
{
struct V_8 * V_9 = & V_32 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_592 ;
struct V_94 * V_94 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_94 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
struct V_367 V_368 = { 0 } ;
int type ;
if ( F_24 ( V_7 ) )
V_1 -> V_134 = F_61 ;
else if ( F_8 ( V_7 ) || F_63 ( V_7 ) )
V_1 -> V_134 = F_58 ;
else if ( F_30 ( V_7 ) )
V_1 -> V_134 = F_53 ;
else
V_1 -> V_134 = F_52 ;
V_1 -> V_136 = F_62 ;
V_1 -> V_237 = F_25 ( V_1 -> V_167 ) ;
V_1 -> V_13 = V_32 ;
if ( F_322 ( V_7 , V_21 ) )
type = V_591 ;
else
type = V_660 ;
if ( type == V_591 )
V_94 -> type = V_5 ;
F_45 ( L_111 ,
type == V_591 ? L_112 : L_113 ,
F_347 ( V_21 ) ) ;
F_348 ( V_7 , V_9 , & V_661 , type ) ;
F_349 ( V_9 , & V_662 ) ;
V_9 -> V_663 = true ;
V_9 -> V_664 = 0 ;
F_184 ( & V_1 -> V_277 ,
F_124 ) ;
F_350 ( V_32 , V_94 ) ;
F_351 ( V_9 ) ;
if ( F_13 ( V_7 ) )
V_32 -> V_665 = V_666 ;
else
V_32 -> V_665 = V_667 ;
V_32 -> V_668 = F_79 ;
switch ( V_21 ) {
case V_22 :
V_94 -> V_669 = V_670 ;
break;
case V_75 :
V_94 -> V_669 = V_671 ;
break;
case V_77 :
V_94 -> V_669 = V_672 ;
break;
case V_165 :
V_94 -> V_669 = V_673 ;
break;
default:
F_75 () ;
}
if ( F_1 ( V_1 ) ) {
F_328 ( V_1 ) ;
F_210 ( V_7 , V_1 , & V_368 ) ;
}
F_74 ( V_1 , V_32 ) ;
if ( F_8 ( V_7 ) || F_63 ( V_7 ) ) {
if ( V_21 == V_75 || V_21 == V_77 || V_21 == V_165 ) {
F_352 ( V_3 , V_32 -> V_4 . V_4 . V_574 ) ;
}
}
if ( ! F_337 ( V_1 , V_32 , & V_368 ) ) {
F_78 ( & V_1 -> V_142 ) ;
if ( F_1 ( V_1 ) ) {
F_176 ( & V_1 -> V_277 ) ;
F_126 ( & V_7 -> V_271 . V_272 , NULL ) ;
F_121 ( V_1 ) ;
F_127 ( & V_7 -> V_271 . V_272 ) ;
}
F_353 ( V_9 ) ;
F_309 ( V_9 ) ;
return false ;
}
F_323 ( V_1 , V_9 ) ;
if ( F_84 ( V_7 ) && ! F_354 ( V_7 ) ) {
T_4 V_466 = F_25 ( V_674 ) ;
F_38 ( V_674 , ( V_466 & ~ 0xf ) | 0xd ) ;
}
return true ;
}
void
F_355 ( struct V_6 * V_7 , int V_167 , enum V_21 V_21 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 ;
struct V_94 * V_94 ;
struct V_489 * V_180 ;
struct V_32 * V_32 ;
V_3 = F_356 ( sizeof( * V_3 ) , V_675 ) ;
if ( ! V_3 )
return;
V_32 = F_356 ( sizeof( * V_32 ) , V_675 ) ;
if ( ! V_32 ) {
F_298 ( V_3 ) ;
return;
}
V_94 = & V_3 -> V_4 ;
V_180 = & V_94 -> V_4 ;
F_357 ( V_7 , & V_94 -> V_4 , & V_676 ,
V_677 ) ;
V_94 -> V_678 = F_93 ;
V_94 -> V_679 = F_186 ;
V_94 -> V_665 = F_143 ;
V_94 -> V_680 = F_149 ;
V_94 -> V_681 = F_314 ;
if ( F_86 ( V_7 ) ) {
V_94 -> V_682 = F_223 ;
V_94 -> V_683 = F_220 ;
V_94 -> V_684 = F_203 ;
V_94 -> V_685 = F_190 ;
} else if ( F_24 ( V_7 ) ) {
V_94 -> V_682 = F_213 ;
V_94 -> V_683 = F_205 ;
V_94 -> V_684 = F_203 ;
V_94 -> V_685 = F_189 ;
} else {
V_94 -> V_683 = F_204 ;
V_94 -> V_684 = F_202 ;
V_94 -> V_685 = F_188 ;
}
V_3 -> V_21 = V_21 ;
V_3 -> V_592 . V_167 = V_167 ;
V_94 -> type = V_575 ;
if ( F_86 ( V_7 ) ) {
if ( V_21 == V_165 )
V_94 -> V_686 = 1 << 2 ;
else
V_94 -> V_686 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_94 -> V_686 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_94 -> V_687 = 0 ;
V_94 -> V_688 = F_318 ;
V_3 -> V_689 = F_319 ;
V_54 -> V_690 [ V_21 ] = V_3 ;
if ( ! F_346 ( V_3 , V_32 ) ) {
F_312 ( V_180 ) ;
F_298 ( V_3 ) ;
F_298 ( V_32 ) ;
}
}
void F_358 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_691 ; V_49 ++ ) {
struct V_2 * V_3 = V_54 -> V_690 [ V_49 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_575 ) {
if ( ! V_3 -> V_592 . V_520 )
continue;
if ( V_3 -> V_592 . V_523 )
F_359 ( & V_3 -> V_592 . V_524 ) ;
}
}
}
void F_360 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_691 ; V_49 ++ ) {
struct V_2 * V_3 = V_54 -> V_690 [ V_49 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_575 ) {
int V_126 ;
if ( ! V_3 -> V_592 . V_520 )
continue;
V_126 = F_361 ( & V_3 -> V_592 . V_524 ) ;
if ( V_126 != 0 ) {
F_277 ( & V_3 -> V_592 ) ;
}
}
}
}
