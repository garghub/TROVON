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
static int
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
F_80 ( & V_32 -> V_4 . V_169 -> V_170 ,
V_1 -> V_142 . V_171 . V_7 . V_170 . V_162 ) ;
F_81 ( V_32 ) ;
}
static void
F_82 ( struct V_94 * V_172 ,
struct V_173 * V_174 , int V_175 )
{
struct V_6 * V_7 = V_172 -> V_4 . V_7 ;
const struct V_176 * V_177 = NULL ;
int V_49 , V_178 = 0 ;
if ( F_83 ( V_7 ) ) {
V_177 = V_179 ;
V_178 = F_84 ( V_179 ) ;
} else if ( F_8 ( V_7 ) ) {
} else if ( F_30 ( V_7 ) ) {
V_177 = V_180 ;
V_178 = F_84 ( V_180 ) ;
} else if ( F_85 ( V_7 ) ) {
V_177 = V_181 ;
V_178 = F_84 ( V_181 ) ;
} else if ( F_24 ( V_7 ) ) {
V_177 = V_182 ;
V_178 = F_84 ( V_182 ) ;
}
if ( V_177 && V_178 ) {
for ( V_49 = 0 ; V_49 < V_178 ; V_49 ++ ) {
if ( V_175 == V_177 [ V_49 ] . V_175 ) {
V_174 -> V_183 = V_177 [ V_49 ] . V_183 ;
V_174 -> V_184 = true ;
break;
}
}
}
}
static void
F_86 ( struct V_185 * V_69 , struct V_186 * V_187 )
{
struct V_6 * V_7 = V_69 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_188 V_188 = V_69 -> V_189 . V_190 ;
F_38 ( F_87 ( V_188 ) ,
F_88 ( V_187 -> V_191 ) | V_187 -> V_192 ) ;
F_38 ( F_89 ( V_188 ) , V_187 -> V_193 ) ;
F_38 ( F_90 ( V_188 ) , V_187 -> V_194 ) ;
F_38 ( F_91 ( V_188 ) , V_187 -> V_195 ) ;
}
bool
F_92 ( struct V_94 * V_172 ,
struct V_173 * V_174 )
{
struct V_6 * V_7 = V_172 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_30 * V_196 = & V_174 -> V_196 ;
struct V_1 * V_1 = F_5 ( & V_172 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_185 * V_185 = V_172 -> V_197 ;
struct V_32 * V_32 = V_1 -> V_13 ;
int V_198 , clock ;
int V_199 = 1 ;
int V_200 = F_12 ( V_1 ) ;
int V_201 = 0 ;
int V_202 = F_7 ( V_1 ) >> 3 ;
int V_26 , V_37 ;
static int V_203 [] = { V_14 , V_15 , V_16 } ;
int V_204 , V_205 ;
if ( F_30 ( V_7 ) && ! F_13 ( V_7 ) && V_21 != V_22 )
V_174 -> V_206 = true ;
V_174 -> V_207 = true ;
V_174 -> V_208 = V_1 -> V_208 ;
if ( F_1 ( V_1 ) && V_32 -> V_34 . V_33 ) {
F_93 ( V_32 -> V_34 . V_33 ,
V_196 ) ;
if ( ! F_30 ( V_7 ) )
F_94 ( V_185 , V_174 ,
V_32 -> V_34 . V_209 ) ;
else
F_95 ( V_185 , V_174 ,
V_32 -> V_34 . V_209 ) ;
}
if ( V_196 -> V_43 & V_44 )
return false ;
F_45 ( L_16
L_17 ,
V_200 , V_203 [ V_202 ] ,
V_196 -> V_210 ) ;
V_26 = V_174 -> V_211 ;
if ( F_1 ( V_1 ) ) {
if ( V_54 -> V_212 . V_213 && V_54 -> V_212 . V_213 < V_26 ) {
F_45 ( L_18 ,
V_54 -> V_212 . V_213 ) ;
V_26 = V_54 -> V_212 . V_213 ;
}
if ( F_63 ( V_7 ) ) {
V_199 = V_200 ;
F_45 ( L_19 ,
V_199 ) ;
} else if ( V_54 -> V_212 . V_214 ) {
V_199 = F_15 ( V_54 -> V_212 . V_214 ,
V_200 ) ;
F_45 ( L_20 ,
V_199 ) ;
}
if ( V_54 -> V_212 . V_215 ) {
V_201 = F_15 ( V_54 -> V_212 . V_215 >> 3 , V_202 ) ;
F_45 ( L_21 ,
V_203 [ V_201 ] ) ;
}
}
for (; V_26 >= 6 * 3 ; V_26 -= 2 * 3 ) {
V_37 = F_16 ( V_196 -> V_210 ,
V_26 ) ;
for ( clock = V_201 ; clock <= V_202 ; clock ++ ) {
for ( V_198 = V_199 ; V_198 <= V_200 ; V_198 <<= 1 ) {
V_205 = F_20 ( V_203 [ clock ] ) ;
V_204 = F_17 ( V_205 ,
V_198 ) ;
if ( V_37 <= V_204 ) {
goto V_216;
}
}
}
}
return false ;
V_216:
if ( V_1 -> V_217 ) {
if ( V_26 != 18 && F_96 ( V_196 ) > 1 )
V_1 -> V_218 = V_219 ;
else
V_1 -> V_218 = 0 ;
}
if ( V_1 -> V_218 )
V_174 -> V_220 = true ;
V_1 -> V_175 = V_203 [ clock ] ;
V_1 -> V_198 = V_198 ;
V_174 -> V_211 = V_26 ;
V_174 -> V_221 = F_20 ( V_1 -> V_175 ) ;
F_45 ( L_22 ,
V_1 -> V_175 , V_1 -> V_198 ,
V_174 -> V_221 , V_26 ) ;
F_45 ( L_23 ,
V_37 , V_204 ) ;
F_97 ( V_26 , V_198 ,
V_196 -> V_210 ,
V_174 -> V_221 ,
& V_174 -> V_222 ) ;
if ( V_32 -> V_34 . V_223 != NULL &&
V_1 -> V_224 . type == V_225 ) {
F_97 ( V_26 , V_198 ,
V_32 -> V_34 . V_223 -> clock ,
V_174 -> V_221 ,
& V_174 -> V_226 ) ;
}
F_82 ( V_172 , V_174 , V_1 -> V_175 ) ;
return true ;
}
static void F_98 ( struct V_1 * V_1 )
{
struct V_2 * V_227 = F_2 ( V_1 ) ;
struct V_185 * V_69 = F_27 ( V_227 -> V_4 . V_4 . V_69 ) ;
struct V_6 * V_7 = V_69 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_228 ;
F_45 ( L_24 , V_69 -> V_189 . V_221 ) ;
V_228 = F_25 ( V_229 ) ;
V_228 &= ~ V_230 ;
if ( V_69 -> V_189 . V_221 == 162000 ) {
F_45 ( L_25 ) ;
V_228 |= V_231 ;
V_1 -> V_232 |= V_231 ;
} else {
V_228 |= V_233 ;
V_1 -> V_232 |= V_233 ;
}
F_38 ( V_229 , V_228 ) ;
F_99 ( V_229 ) ;
F_100 ( 500 ) ;
}
static void F_101 ( struct V_94 * V_172 )
{
struct V_6 * V_7 = V_172 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_1 * V_1 = F_5 ( & V_172 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_185 * V_69 = F_27 ( V_172 -> V_4 . V_69 ) ;
struct V_30 * V_196 = & V_69 -> V_189 . V_196 ;
V_1 -> V_232 = F_25 ( V_1 -> V_167 ) & V_234 ;
V_1 -> V_232 |= V_235 | V_236 ;
V_1 -> V_232 |= F_102 ( V_1 -> V_198 ) ;
if ( V_69 -> V_189 . V_208 ) {
F_103 ( L_26 ,
F_104 ( V_69 -> V_67 ) ) ;
V_1 -> V_232 |= V_237 ;
F_105 ( & V_172 -> V_4 , V_196 ) ;
}
if ( V_21 == V_22 && F_55 ( V_7 ) && ! F_24 ( V_7 ) ) {
if ( V_196 -> V_43 & V_238 )
V_1 -> V_232 |= V_239 ;
if ( V_196 -> V_43 & V_240 )
V_1 -> V_232 |= V_241 ;
V_1 -> V_232 |= V_242 ;
if ( F_106 ( V_1 -> V_11 ) )
V_1 -> V_232 |= V_243 ;
V_1 -> V_232 |= V_69 -> V_67 << 29 ;
} else if ( ! F_107 ( V_7 ) || V_21 == V_22 ) {
if ( ! F_30 ( V_7 ) && ! F_24 ( V_7 ) )
V_1 -> V_232 |= V_1 -> V_218 ;
if ( V_196 -> V_43 & V_238 )
V_1 -> V_232 |= V_239 ;
if ( V_196 -> V_43 & V_240 )
V_1 -> V_232 |= V_241 ;
V_1 -> V_232 |= V_244 ;
if ( F_106 ( V_1 -> V_11 ) )
V_1 -> V_232 |= V_243 ;
if ( ! F_85 ( V_7 ) ) {
if ( V_69 -> V_67 == 1 )
V_1 -> V_232 |= V_245 ;
} else {
V_1 -> V_232 |= F_108 ( V_69 -> V_67 ) ;
}
} else {
V_1 -> V_232 |= V_242 ;
}
}
static void F_109 ( struct V_1 * V_1 ,
T_4 V_246 ,
T_4 V_247 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_248 , V_86 ;
V_248 = F_32 ( V_1 ) ;
V_86 = F_29 ( V_1 ) ;
F_45 ( L_27 ,
V_246 , V_247 ,
F_25 ( V_248 ) ,
F_25 ( V_86 ) ) ;
if ( F_110 ( ( F_25 ( V_248 ) & V_246 ) == V_247 , 5000 , 10 ) ) {
F_51 ( L_28 ,
F_25 ( V_248 ) ,
F_25 ( V_86 ) ) ;
}
F_45 ( L_29 ) ;
}
static void F_111 ( struct V_1 * V_1 )
{
F_45 ( L_30 ) ;
F_109 ( V_1 , V_249 , V_250 ) ;
}
static void F_112 ( struct V_1 * V_1 )
{
F_45 ( L_31 ) ;
F_109 ( V_1 , V_251 , V_252 ) ;
}
static void F_113 ( struct V_1 * V_1 )
{
F_45 ( L_32 ) ;
F_114 ( V_1 -> V_253 ,
V_1 -> V_92 ) ;
F_109 ( V_1 , V_254 , V_255 ) ;
}
static void F_115 ( struct V_1 * V_1 )
{
F_114 ( V_1 -> V_256 ,
V_1 -> V_257 ) ;
}
static void F_116 ( struct V_1 * V_1 )
{
F_114 ( V_1 -> V_258 ,
V_1 -> V_259 ) ;
}
static T_4 F_117 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_260 ;
V_260 = F_25 ( F_29 ( V_1 ) ) ;
V_260 &= ~ V_261 ;
V_260 |= V_90 ;
return V_260 ;
}
static bool F_66 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_94 * V_94 = & V_3 -> V_4 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_95 V_96 ;
T_4 V_262 ;
T_4 V_248 , V_86 ;
bool V_263 = ! V_1 -> V_264 ;
if ( ! F_1 ( V_1 ) )
return false ;
V_1 -> V_264 = true ;
if ( F_41 ( V_1 ) )
return V_263 ;
V_96 = F_42 ( V_94 ) ;
F_118 ( V_54 , V_96 ) ;
F_45 ( L_33 ) ;
if ( ! F_40 ( V_1 ) )
F_113 ( V_1 ) ;
V_262 = F_117 ( V_1 ) ;
V_262 |= V_97 ;
V_248 = F_32 ( V_1 ) ;
V_86 = F_29 ( V_1 ) ;
F_38 ( V_86 , V_262 ) ;
F_99 ( V_86 ) ;
F_45 ( L_34 ,
F_25 ( V_248 ) , F_25 ( V_86 ) ) ;
if ( ! F_40 ( V_1 ) ) {
F_45 ( L_35 ) ;
F_39 ( V_1 -> V_265 ) ;
}
return V_263 ;
}
void F_119 ( struct V_1 * V_1 )
{
if ( F_1 ( V_1 ) ) {
bool V_129 = F_66 ( V_1 ) ;
F_11 ( ! V_129 , L_36 ) ;
}
}
static void F_120 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_262 ;
T_4 V_248 , V_86 ;
F_70 ( ! F_121 ( & V_7 -> V_266 . V_267 ) ) ;
if ( ! V_1 -> V_264 && F_41 ( V_1 ) ) {
struct V_2 * V_3 =
F_2 ( V_1 ) ;
struct V_94 * V_94 = & V_3 -> V_4 ;
enum V_95 V_96 ;
F_45 ( L_37 ) ;
V_262 = F_117 ( V_1 ) ;
V_262 &= ~ V_97 ;
V_86 = F_29 ( V_1 ) ;
V_248 = F_32 ( V_1 ) ;
F_38 ( V_86 , V_262 ) ;
F_99 ( V_86 ) ;
F_45 ( L_34 ,
F_25 ( V_248 ) , F_25 ( V_86 ) ) ;
if ( ( V_262 & V_268 ) == 0 )
V_1 -> V_253 = V_269 ;
V_96 = F_42 ( V_94 ) ;
F_122 ( V_54 , V_96 ) ;
}
}
static void F_123 ( struct V_270 * V_271 )
{
struct V_1 * V_1 = F_35 ( F_124 ( V_271 ) ,
struct V_1 , V_272 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
F_125 ( & V_7 -> V_266 . V_267 , NULL ) ;
F_120 ( V_1 ) ;
F_126 ( & V_7 -> V_266 . V_267 ) ;
}
static void F_72 ( struct V_1 * V_1 , bool V_273 )
{
if ( ! F_1 ( V_1 ) )
return;
F_11 ( ! V_1 -> V_264 , L_38 ) ;
V_1 -> V_264 = false ;
if ( V_273 ) {
F_120 ( V_1 ) ;
} else {
F_127 ( & V_1 -> V_272 ,
F_128 ( V_1 -> V_92 * 5 ) ) ;
}
}
void F_129 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_262 ;
T_4 V_86 ;
if ( ! F_1 ( V_1 ) )
return;
F_45 ( L_39 ) ;
if ( F_40 ( V_1 ) ) {
F_45 ( L_40 ) ;
return;
}
F_113 ( V_1 ) ;
V_86 = F_29 ( V_1 ) ;
V_262 = F_117 ( V_1 ) ;
if ( F_130 ( V_7 ) ) {
V_262 &= ~ V_274 ;
F_38 ( V_86 , V_262 ) ;
F_99 ( V_86 ) ;
}
V_262 |= V_268 ;
if ( ! F_130 ( V_7 ) )
V_262 |= V_274 ;
F_38 ( V_86 , V_262 ) ;
F_99 ( V_86 ) ;
F_111 ( V_1 ) ;
V_1 -> V_256 = V_269 ;
if ( F_130 ( V_7 ) ) {
V_262 |= V_274 ;
F_38 ( V_86 , V_262 ) ;
F_99 ( V_86 ) ;
}
}
void F_131 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_94 * V_94 = & V_3 -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_95 V_96 ;
T_4 V_262 ;
T_4 V_86 ;
if ( ! F_1 ( V_1 ) )
return;
F_45 ( L_41 ) ;
F_116 ( V_1 ) ;
F_11 ( ! V_1 -> V_264 , L_42 ) ;
V_262 = F_117 ( V_1 ) ;
V_262 &= ~ ( V_268 | V_274 | V_97 |
V_275 ) ;
V_86 = F_29 ( V_1 ) ;
V_1 -> V_264 = false ;
F_38 ( V_86 , V_262 ) ;
F_99 ( V_86 ) ;
V_1 -> V_253 = V_269 ;
F_112 ( V_1 ) ;
V_96 = F_42 ( V_94 ) ;
F_122 ( V_54 , V_96 ) ;
}
void F_132 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_262 ;
T_4 V_86 ;
if ( ! F_1 ( V_1 ) )
return;
F_45 ( L_43 ) ;
F_115 ( V_1 ) ;
V_262 = F_117 ( V_1 ) ;
V_262 |= V_275 ;
V_86 = F_29 ( V_1 ) ;
F_38 ( V_86 , V_262 ) ;
F_99 ( V_86 ) ;
F_133 ( V_1 -> V_13 ) ;
}
void F_134 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_262 ;
T_4 V_86 ;
if ( ! F_1 ( V_1 ) )
return;
F_135 ( V_1 -> V_13 ) ;
F_45 ( L_43 ) ;
V_262 = F_117 ( V_1 ) ;
V_262 &= ~ V_275 ;
V_86 = F_29 ( V_1 ) ;
F_38 ( V_86 , V_262 ) ;
F_99 ( V_86 ) ;
V_1 -> V_258 = V_269 ;
}
static void F_136 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_68 * V_69 = V_3 -> V_4 . V_4 . V_69 ;
struct V_6 * V_7 = V_69 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_228 ;
F_137 ( V_54 ,
F_27 ( V_69 ) -> V_67 ) ;
F_45 ( L_43 ) ;
V_228 = F_25 ( V_229 ) ;
F_11 ( V_228 & V_276 , L_44 ) ;
F_11 ( V_228 & V_277 , L_45 ) ;
V_1 -> V_232 &= ~ ( V_277 | V_237 ) ;
V_1 -> V_232 |= V_276 ;
F_38 ( V_229 , V_1 -> V_232 ) ;
F_99 ( V_229 ) ;
F_100 ( 200 ) ;
}
static void F_138 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_68 * V_69 = V_3 -> V_4 . V_4 . V_69 ;
struct V_6 * V_7 = V_69 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_228 ;
F_137 ( V_54 ,
F_27 ( V_69 ) -> V_67 ) ;
V_228 = F_25 ( V_229 ) ;
F_11 ( ( V_228 & V_276 ) == 0 ,
L_46 ) ;
F_11 ( V_228 & V_277 , L_45 ) ;
V_228 &= ~ V_276 ;
F_38 ( V_229 , V_228 ) ;
F_99 ( V_229 ) ;
F_100 ( 200 ) ;
}
void F_139 ( struct V_1 * V_1 , int V_31 )
{
int V_126 , V_49 ;
if ( V_1 -> V_11 [ V_18 ] < 0x11 )
return;
if ( V_31 != V_278 ) {
V_126 = F_140 ( & V_1 -> V_142 , V_279 ,
V_280 ) ;
if ( V_126 != 1 )
F_103 ( L_47 ) ;
} else {
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
V_126 = F_140 ( & V_1 -> V_142 , V_279 ,
V_281 ) ;
if ( V_126 == 1 )
break;
F_39 ( 1 ) ;
}
}
}
static bool F_141 ( struct V_94 * V_172 ,
enum V_67 * V_67 )
{
struct V_1 * V_1 = F_5 ( & V_172 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_6 * V_7 = V_172 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_95 V_96 ;
T_4 V_282 ;
V_96 = F_42 ( V_172 ) ;
if ( ! F_43 ( V_54 , V_96 ) )
return false ;
V_282 = F_25 ( V_1 -> V_167 ) ;
if ( ! ( V_282 & V_277 ) )
return false ;
if ( V_21 == V_22 && F_55 ( V_7 ) && ! F_24 ( V_7 ) ) {
* V_67 = F_142 ( V_282 ) ;
} else if ( F_85 ( V_7 ) ) {
* V_67 = F_143 ( V_282 ) ;
} else if ( ! F_107 ( V_7 ) || V_21 == V_22 ) {
* V_67 = F_144 ( V_282 ) ;
} else {
T_4 V_283 ;
T_4 V_284 ;
int V_49 ;
switch ( V_1 -> V_167 ) {
case V_285 :
V_283 = V_286 ;
break;
case V_287 :
V_283 = V_288 ;
break;
case V_289 :
V_283 = V_290 ;
break;
default:
return true ;
}
F_145 (i) {
V_284 = F_25 ( F_146 ( V_49 ) ) ;
if ( ( V_284 & V_291 ) == V_283 ) {
* V_67 = V_49 ;
return true ;
}
}
F_45 ( L_48 ,
V_1 -> V_167 ) ;
}
return true ;
}
static void F_147 ( struct V_94 * V_172 ,
struct V_173 * V_174 )
{
struct V_1 * V_1 = F_5 ( & V_172 -> V_4 ) ;
T_4 V_282 , V_43 = 0 ;
struct V_6 * V_7 = V_172 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_185 * V_69 = F_27 ( V_172 -> V_4 . V_69 ) ;
int V_292 ;
V_282 = F_25 ( V_1 -> V_167 ) ;
if ( V_282 & V_237 )
V_174 -> V_208 = true ;
if ( ( V_21 == V_22 ) || ! F_107 ( V_7 ) ) {
if ( V_282 & V_239 )
V_43 |= V_238 ;
else
V_43 |= V_293 ;
if ( V_282 & V_241 )
V_43 |= V_240 ;
else
V_43 |= V_294 ;
} else {
V_282 = F_25 ( F_146 ( V_69 -> V_67 ) ) ;
if ( V_282 & V_295 )
V_43 |= V_238 ;
else
V_43 |= V_293 ;
if ( V_282 & V_296 )
V_43 |= V_240 ;
else
V_43 |= V_294 ;
}
V_174 -> V_196 . V_43 |= V_43 ;
V_174 -> V_207 = true ;
F_148 ( V_69 , V_174 ) ;
if ( V_21 == V_22 ) {
if ( ( F_25 ( V_229 ) & V_230 ) == V_231 )
V_174 -> V_221 = 162000 ;
else
V_174 -> V_221 = 270000 ;
}
V_292 = F_149 ( V_174 -> V_221 ,
& V_174 -> V_222 ) ;
if ( F_30 ( V_54 -> V_7 ) && V_21 != V_22 )
F_150 ( V_174 , V_292 ) ;
V_174 -> V_196 . V_210 = V_292 ;
if ( F_1 ( V_1 ) && V_54 -> V_212 . V_213 &&
V_174 -> V_211 > V_54 -> V_212 . V_213 ) {
F_45 ( L_49 ,
V_174 -> V_211 , V_54 -> V_212 . V_213 ) ;
V_54 -> V_212 . V_213 = V_174 -> V_211 ;
}
}
static bool F_151 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
return V_54 -> V_297 . V_298 ;
}
static bool F_152 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
if ( ! F_153 ( V_7 ) )
return false ;
return F_25 ( F_154 ( V_7 ) ) & V_299 ;
}
static void F_155 ( struct V_1 * V_1 ,
struct V_300 * V_301 )
{
struct V_2 * V_227 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_227 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_185 * V_69 = F_27 ( V_227 -> V_4 . V_4 . V_69 ) ;
T_4 V_302 = F_156 ( V_69 -> V_189 . V_190 ) ;
T_4 V_303 = F_157 ( V_69 -> V_189 . V_190 ) ;
T_2 * V_304 = ( T_2 * ) V_301 ;
unsigned int V_49 ;
F_38 ( V_302 , 0 ) ;
F_99 ( V_302 ) ;
for ( V_49 = 0 ; V_49 < V_305 ; V_49 += 4 ) {
if ( V_49 < sizeof( struct V_300 ) )
F_38 ( V_303 + V_49 , * V_304 ++ ) ;
else
F_38 ( V_303 + V_49 , 0 ) ;
}
F_38 ( V_302 , V_306 ) ;
F_99 ( V_302 ) ;
}
static void F_158 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_300 V_307 ;
if ( V_1 -> V_308 )
return;
memset ( & V_307 , 0 , sizeof( V_307 ) ) ;
V_307 . V_309 . V_310 = 0 ;
V_307 . V_309 . V_311 = 0x7 ;
V_307 . V_309 . V_312 = 0x2 ;
V_307 . V_309 . V_313 = 0x8 ;
F_155 ( V_1 , & V_307 ) ;
F_38 ( F_159 ( V_7 ) , V_314 |
V_315 | V_316 ) ;
V_1 -> V_308 = true ;
}
static void F_160 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_108 ;
int V_109 = 0x3 ;
int V_317 = 5 ;
V_108 = V_1 -> V_134 ( V_1 , 0 ) ;
if ( V_1 -> V_318 [ 1 ] & V_319 )
F_140 ( & V_1 -> V_142 , V_320 ,
V_321 & ~ V_322 ) ;
else
F_140 ( & V_1 -> V_142 , V_320 ,
V_321 | V_322 ) ;
F_38 ( F_161 ( V_7 ) , V_323 ) ;
F_38 ( F_162 ( V_7 ) , V_324 ) ;
F_38 ( F_163 ( V_7 ) ,
V_113 |
( V_317 << V_119 ) |
( V_109 << V_120 ) |
( V_108 << V_121 ) ) ;
}
static void F_164 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_325 = 0x1f ;
T_2 V_326 = 1 ;
T_2 V_327 = 0x0 ;
const T_2 V_328 = V_329 ;
if ( V_1 -> V_318 [ 1 ] & V_319 ) {
V_327 |= V_330 ;
V_327 |= V_331 ;
V_327 |= V_332 ;
V_327 |= V_333 ;
} else
V_327 |= V_334 ;
F_38 ( F_154 ( V_7 ) , V_327 |
( F_63 ( V_7 ) ? 0 : V_328 ) |
V_325 << V_335 |
V_326 << V_336 |
V_299 ) ;
}
static bool F_165 ( struct V_1 * V_1 )
{
struct V_2 * V_227 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_227 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_68 * V_69 = V_227 -> V_4 . V_4 . V_69 ;
struct V_185 * V_185 = F_27 ( V_69 ) ;
struct V_337 * V_338 = F_166 ( V_69 -> V_339 -> V_340 ) -> V_338 ;
struct V_94 * V_94 = & F_2 ( V_1 ) -> V_4 ;
V_54 -> V_297 . V_341 = false ;
if ( ! F_153 ( V_7 ) ) {
F_45 ( L_50 ) ;
return false ;
}
if ( ( V_94 -> type != V_5 ) ||
( V_227 -> V_21 != V_22 ) ) {
F_45 ( L_51 ) ;
return false ;
}
if ( ! V_342 . V_343 ) {
F_45 ( L_52 ) ;
return false ;
}
V_69 = V_227 -> V_4 . V_4 . V_69 ;
if ( V_69 == NULL ) {
F_45 ( L_53 ) ;
return false ;
}
V_185 = F_27 ( V_69 ) ;
if ( ! F_167 ( V_69 ) ) {
F_45 ( L_53 ) ;
return false ;
}
V_338 = F_166 ( V_69 -> V_339 -> V_340 ) -> V_338 ;
if ( V_338 -> V_344 != V_345 ||
V_338 -> V_346 == V_347 ) {
F_45 ( L_54 ) ;
return false ;
}
if ( F_25 ( F_168 ( V_185 -> V_67 ) ) & V_348 ) {
F_45 ( L_55 ) ;
return false ;
}
if ( F_25 ( F_169 ( V_185 -> V_189 . V_190 ) ) &
V_349 ) {
F_45 ( L_56 ) ;
return false ;
}
if ( V_185 -> V_189 . V_196 . V_43 & V_350 ) {
F_45 ( L_57 ) ;
return false ;
}
V_54 -> V_297 . V_341 = true ;
return true ;
}
static void F_170 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( ! F_165 ( V_1 ) ||
F_152 ( V_7 ) )
return;
F_158 ( V_1 ) ;
F_160 ( V_1 ) ;
F_164 ( V_1 ) ;
}
void F_171 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_165 ( V_1 ) &&
! F_152 ( V_7 ) )
F_170 ( V_1 ) ;
}
void F_172 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( ! F_152 ( V_7 ) )
return;
F_38 ( F_154 ( V_7 ) ,
F_25 ( F_154 ( V_7 ) ) & ~ V_299 ) ;
if ( F_110 ( ( F_25 ( F_173 ( V_7 ) ) &
V_351 ) == 0 , 2000 , 10 ) )
F_51 ( L_58 ) ;
}
void F_174 ( struct V_6 * V_7 )
{
struct V_94 * V_172 ;
struct V_1 * V_1 = NULL ;
F_175 (encoder, &dev->mode_config.encoder_list, base.head)
if ( V_172 -> type == V_5 ) {
V_1 = F_5 ( & V_172 -> V_4 ) ;
if ( ! F_151 ( V_7 ) )
return;
if ( ! F_165 ( V_1 ) )
F_172 ( V_1 ) ;
else
if ( ! F_152 ( V_7 ) )
F_170 ( V_1 ) ;
}
}
static void F_176 ( struct V_94 * V_172 )
{
struct V_1 * V_1 = F_5 ( & V_172 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_6 * V_7 = V_172 -> V_4 . V_7 ;
F_119 ( V_1 ) ;
F_134 ( V_1 ) ;
F_139 ( V_1 , V_352 ) ;
F_131 ( V_1 ) ;
if ( ! ( V_21 == V_22 || F_24 ( V_7 ) ) )
F_177 ( V_1 ) ;
}
static void F_178 ( struct V_94 * V_172 )
{
struct V_1 * V_1 = F_5 ( & V_172 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
if ( V_21 != V_22 )
return;
F_177 ( V_1 ) ;
F_138 ( V_1 ) ;
}
static void F_179 ( struct V_94 * V_172 )
{
struct V_1 * V_1 = F_5 ( & V_172 -> V_4 ) ;
F_177 ( V_1 ) ;
}
static void F_180 ( struct V_94 * V_172 )
{
struct V_1 * V_1 = F_5 ( & V_172 -> V_4 ) ;
struct V_2 * V_353 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_172 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_185 * V_185 =
F_27 ( V_172 -> V_4 . V_69 ) ;
enum V_354 V_355 = F_181 ( V_353 ) ;
enum V_67 V_67 = V_185 -> V_67 ;
T_4 V_327 ;
F_177 ( V_1 ) ;
F_182 ( & V_54 -> V_356 ) ;
V_327 = F_183 ( V_54 , V_67 , F_184 ( V_355 ) ) ;
V_327 |= V_357 ;
F_185 ( V_54 , V_67 , F_184 ( V_355 ) , V_327 ) ;
V_327 = F_183 ( V_54 , V_67 , F_186 ( V_355 ) ) ;
V_327 |= V_357 ;
F_185 ( V_54 , V_67 , F_186 ( V_355 ) , V_327 ) ;
V_327 = F_183 ( V_54 , V_67 , F_187 ( V_355 ) ) ;
V_327 &= ~ ( V_358 | V_359 ) ;
F_185 ( V_54 , V_67 , F_187 ( V_355 ) , V_327 ) ;
V_327 = F_183 ( V_54 , V_67 , F_188 ( V_355 ) ) ;
V_327 &= ~ ( V_358 | V_359 ) ;
F_185 ( V_54 , V_67 , F_188 ( V_355 ) , V_327 ) ;
F_189 ( & V_54 -> V_356 ) ;
}
static void F_190 ( struct V_94 * V_172 )
{
struct V_1 * V_1 = F_5 ( & V_172 -> V_4 ) ;
struct V_6 * V_7 = V_172 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_360 = F_25 ( V_1 -> V_167 ) ;
if ( F_70 ( V_360 & V_277 ) )
return;
F_119 ( V_1 ) ;
F_139 ( V_1 , V_278 ) ;
F_191 ( V_1 ) ;
F_129 ( V_1 ) ;
F_72 ( V_1 , true ) ;
F_192 ( V_1 ) ;
F_193 ( V_1 ) ;
}
static void F_194 ( struct V_94 * V_172 )
{
struct V_1 * V_1 = F_5 ( & V_172 -> V_4 ) ;
F_190 ( V_172 ) ;
F_132 ( V_1 ) ;
}
static void F_195 ( struct V_94 * V_172 )
{
struct V_1 * V_1 = F_5 ( & V_172 -> V_4 ) ;
F_132 ( V_1 ) ;
}
static void F_196 ( struct V_94 * V_172 )
{
struct V_1 * V_1 = F_5 ( & V_172 -> V_4 ) ;
struct V_2 * V_353 = F_2 ( V_1 ) ;
F_101 ( V_172 ) ;
if ( V_353 -> V_21 == V_22 ) {
F_98 ( V_1 ) ;
F_136 ( V_1 ) ;
}
}
static void F_197 ( struct V_94 * V_172 )
{
struct V_1 * V_1 = F_5 ( & V_172 -> V_4 ) ;
struct V_2 * V_353 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_172 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_185 * V_185 = F_27 ( V_172 -> V_4 . V_69 ) ;
enum V_354 V_21 = F_181 ( V_353 ) ;
int V_67 = V_185 -> V_67 ;
struct V_361 V_362 ;
T_4 V_327 ;
F_182 ( & V_54 -> V_356 ) ;
V_327 = F_183 ( V_54 , V_67 , F_198 ( V_21 ) ) ;
V_327 = 0 ;
if ( V_67 )
V_327 |= ( 1 << 21 ) ;
else
V_327 &= ~ ( 1 << 21 ) ;
V_327 |= 0x001000c4 ;
F_185 ( V_54 , V_67 , F_199 ( V_21 ) , V_327 ) ;
F_185 ( V_54 , V_67 , F_200 ( V_21 ) , 0x00760018 ) ;
F_185 ( V_54 , V_67 , F_201 ( V_21 ) , 0x00400888 ) ;
F_189 ( & V_54 -> V_356 ) ;
if ( F_1 ( V_1 ) ) {
F_202 ( V_7 , V_1 , & V_362 ) ;
F_203 ( V_7 , V_1 ,
& V_362 ) ;
}
F_190 ( V_172 ) ;
F_204 ( V_54 , V_353 ) ;
}
static void F_205 ( struct V_94 * V_172 )
{
struct V_2 * V_353 = F_206 ( & V_172 -> V_4 ) ;
struct V_6 * V_7 = V_172 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_185 * V_185 =
F_27 ( V_172 -> V_4 . V_69 ) ;
enum V_354 V_21 = F_181 ( V_353 ) ;
int V_67 = V_185 -> V_67 ;
F_101 ( V_172 ) ;
F_182 ( & V_54 -> V_356 ) ;
F_185 ( V_54 , V_67 , F_207 ( V_21 ) ,
V_358 |
V_359 ) ;
F_185 ( V_54 , V_67 , F_208 ( V_21 ) ,
V_363 |
V_364 |
( 1 << V_365 ) |
V_366 ) ;
F_185 ( V_54 , V_67 , F_209 ( V_21 ) , 0x00750f00 ) ;
F_185 ( V_54 , V_67 , F_210 ( V_21 ) , 0x00001500 ) ;
F_185 ( V_54 , V_67 , F_211 ( V_21 ) , 0x40400000 ) ;
F_189 ( & V_54 -> V_356 ) ;
}
static void F_212 ( struct V_94 * V_172 )
{
struct V_1 * V_1 = F_5 ( & V_172 -> V_4 ) ;
struct V_2 * V_353 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_172 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_361 V_362 ;
struct V_185 * V_185 =
F_27 ( V_172 -> V_4 . V_69 ) ;
enum V_354 V_355 = F_181 ( V_353 ) ;
int V_67 = V_185 -> V_67 ;
int V_304 , V_49 ;
T_4 V_327 ;
F_182 ( & V_54 -> V_356 ) ;
V_327 = F_183 ( V_54 , V_67 , F_184 ( V_355 ) ) ;
V_327 |= V_357 ;
F_185 ( V_54 , V_67 , F_184 ( V_355 ) , V_327 ) ;
V_327 = F_183 ( V_54 , V_67 , F_186 ( V_355 ) ) ;
V_327 |= V_357 ;
F_185 ( V_54 , V_67 , F_186 ( V_355 ) , V_327 ) ;
V_327 = F_183 ( V_54 , V_67 , F_187 ( V_355 ) ) ;
V_327 |= ( V_358 | V_359 ) ;
F_185 ( V_54 , V_67 , F_187 ( V_355 ) , V_327 ) ;
V_327 = F_183 ( V_54 , V_67 , F_188 ( V_355 ) ) ;
V_327 |= ( V_358 | V_359 ) ;
F_185 ( V_54 , V_67 , F_188 ( V_355 ) , V_327 ) ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_304 = ( V_49 == 1 ) ? 0x0 : 0x6 ;
F_185 ( V_54 , V_67 , F_213 ( V_355 , V_49 ) ,
V_304 << V_367 ) ;
V_304 = ( V_49 == 1 ) ? 0x0 : 0x1 ;
F_185 ( V_54 , V_67 , F_214 ( V_355 , V_49 ) ,
V_304 << V_368 ) ;
}
F_189 ( & V_54 -> V_356 ) ;
if ( F_1 ( V_1 ) ) {
F_202 ( V_7 , V_1 , & V_362 ) ;
F_203 ( V_7 , V_1 ,
& V_362 ) ;
}
F_190 ( V_172 ) ;
F_204 ( V_54 , V_353 ) ;
}
static T_5
F_215 ( struct V_141 * V_142 , unsigned int V_369 ,
void * V_157 , T_6 V_151 )
{
T_5 V_126 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
V_126 = F_216 ( V_142 , V_369 , V_157 , V_151 ) ;
if ( V_126 == V_151 )
return V_126 ;
F_39 ( 1 ) ;
}
return V_126 ;
}
static bool
F_217 ( struct V_1 * V_1 , T_3 V_370 [ V_371 ] )
{
return F_215 ( & V_1 -> V_142 ,
V_372 ,
V_370 ,
V_371 ) == V_371 ;
}
static T_3
F_218 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
if ( F_24 ( V_7 ) || F_63 ( V_7 ) )
return V_373 ;
else if ( F_55 ( V_7 ) && V_21 == V_22 )
return V_374 ;
else if ( F_107 ( V_7 ) && V_21 != V_22 )
return V_373 ;
else
return V_374 ;
}
static T_3
F_219 ( struct V_1 * V_1 , T_3 V_375 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
if ( F_63 ( V_7 ) ) {
switch ( V_375 & V_376 ) {
case V_377 :
case V_378 :
return V_379 ;
case V_374 :
return V_380 ;
case V_373 :
default:
return V_381 ;
}
} else if ( F_8 ( V_7 ) ) {
switch ( V_375 & V_376 ) {
case V_377 :
return V_382 ;
case V_378 :
return V_379 ;
case V_374 :
return V_380 ;
case V_373 :
default:
return V_381 ;
}
} else if ( F_24 ( V_7 ) ) {
switch ( V_375 & V_376 ) {
case V_377 :
return V_382 ;
case V_378 :
return V_379 ;
case V_374 :
return V_380 ;
case V_373 :
default:
return V_381 ;
}
} else if ( F_55 ( V_7 ) && V_21 == V_22 ) {
switch ( V_375 & V_376 ) {
case V_377 :
return V_379 ;
case V_378 :
case V_374 :
return V_380 ;
default:
return V_381 ;
}
} else {
switch ( V_375 & V_376 ) {
case V_377 :
return V_379 ;
case V_378 :
return V_379 ;
case V_374 :
return V_380 ;
case V_373 :
default:
return V_381 ;
}
}
}
static T_2 F_220 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_353 = F_2 ( V_1 ) ;
struct V_185 * V_185 =
F_27 ( V_353 -> V_4 . V_4 . V_69 ) ;
unsigned long V_383 , V_384 ,
V_385 ;
T_3 V_386 = V_1 -> V_386 [ 0 ] ;
enum V_354 V_21 = F_181 ( V_353 ) ;
int V_67 = V_185 -> V_67 ;
switch ( V_386 & V_387 ) {
case V_381 :
V_384 = 0x0004000 ;
switch ( V_386 & V_376 ) {
case V_377 :
V_383 = 0x2B405555 ;
V_385 = 0x552AB83A ;
break;
case V_378 :
V_383 = 0x2B404040 ;
V_385 = 0x5548B83A ;
break;
case V_374 :
V_383 = 0x2B245555 ;
V_385 = 0x5560B83A ;
break;
case V_373 :
V_383 = 0x2B405555 ;
V_385 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_380 :
V_384 = 0x0002000 ;
switch ( V_386 & V_376 ) {
case V_377 :
V_383 = 0x2B404040 ;
V_385 = 0x5552B83A ;
break;
case V_378 :
V_383 = 0x2B404848 ;
V_385 = 0x5580B83A ;
break;
case V_374 :
V_383 = 0x2B404040 ;
V_385 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_379 :
V_384 = 0x0000000 ;
switch ( V_386 & V_376 ) {
case V_377 :
V_383 = 0x2B305555 ;
V_385 = 0x5570B83A ;
break;
case V_378 :
V_383 = 0x2B2B4040 ;
V_385 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_382 :
V_384 = 0x0006000 ;
switch ( V_386 & V_376 ) {
case V_377 :
V_383 = 0x1B405555 ;
V_385 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_182 ( & V_54 -> V_356 ) ;
F_185 ( V_54 , V_67 , F_221 ( V_21 ) , 0x00000000 ) ;
F_185 ( V_54 , V_67 , F_222 ( V_21 ) , V_383 ) ;
F_185 ( V_54 , V_67 , F_223 ( V_21 ) ,
V_385 ) ;
F_185 ( V_54 , V_67 , F_224 ( V_21 ) , 0x0C782040 ) ;
F_185 ( V_54 , V_67 , F_225 ( V_21 ) , 0x00030000 ) ;
F_185 ( V_54 , V_67 , F_226 ( V_21 ) , V_384 ) ;
F_185 ( V_54 , V_67 , F_221 ( V_21 ) , 0x80000000 ) ;
F_189 ( & V_54 -> V_356 ) ;
return 0 ;
}
static T_2 F_227 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_353 = F_2 ( V_1 ) ;
struct V_185 * V_185 = F_27 ( V_353 -> V_4 . V_4 . V_69 ) ;
T_4 V_388 , V_389 , V_327 ;
T_3 V_386 = V_1 -> V_386 [ 0 ] ;
enum V_354 V_355 = F_181 ( V_353 ) ;
enum V_67 V_67 = V_185 -> V_67 ;
int V_49 ;
switch ( V_386 & V_387 ) {
case V_381 :
switch ( V_386 & V_376 ) {
case V_377 :
V_388 = 128 ;
V_389 = 52 ;
break;
case V_378 :
V_388 = 128 ;
V_389 = 77 ;
break;
case V_374 :
V_388 = 128 ;
V_389 = 102 ;
break;
case V_373 :
V_388 = 128 ;
V_389 = 154 ;
break;
default:
return 0 ;
}
break;
case V_380 :
switch ( V_386 & V_376 ) {
case V_377 :
V_388 = 85 ;
V_389 = 78 ;
break;
case V_378 :
V_388 = 85 ;
V_389 = 116 ;
break;
case V_374 :
V_388 = 85 ;
V_389 = 154 ;
break;
default:
return 0 ;
}
break;
case V_379 :
switch ( V_386 & V_376 ) {
case V_377 :
V_388 = 64 ;
V_389 = 104 ;
break;
case V_378 :
V_388 = 64 ;
V_389 = 154 ;
break;
default:
return 0 ;
}
break;
case V_382 :
switch ( V_386 & V_376 ) {
case V_377 :
V_388 = 43 ;
V_389 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_182 ( & V_54 -> V_356 ) ;
V_327 = F_183 ( V_54 , V_67 , F_228 ( V_355 ) ) ;
V_327 &= ~ ( V_390 | V_391 ) ;
F_185 ( V_54 , V_67 , F_228 ( V_355 ) , V_327 ) ;
V_327 = F_183 ( V_54 , V_67 , F_229 ( V_355 ) ) ;
V_327 &= ~ ( V_390 | V_391 ) ;
F_185 ( V_54 , V_67 , F_229 ( V_355 ) , V_327 ) ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_327 = F_183 ( V_54 , V_67 , F_230 ( V_355 , V_49 ) ) ;
V_327 &= ~ V_392 ;
V_327 |= V_388 << V_393 ;
F_185 ( V_54 , V_67 , F_230 ( V_355 , V_49 ) , V_327 ) ;
}
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_327 = F_183 ( V_54 , V_67 , F_231 ( V_355 , V_49 ) ) ;
V_327 &= ~ V_394 ;
V_327 |= V_389 << V_395 ;
F_185 ( V_54 , V_67 , F_231 ( V_355 , V_49 ) , V_327 ) ;
}
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_327 = F_183 ( V_54 , V_67 , F_232 ( V_355 , V_49 ) ) ;
V_327 &= ~ V_396 ;
F_185 ( V_54 , V_67 , F_232 ( V_355 , V_49 ) , V_327 ) ;
}
if ( ( ( V_386 & V_387 )
== V_381 ) &&
( ( V_386 & V_376 )
== V_373 ) ) {
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_327 = F_183 ( V_54 , V_67 , F_232 ( V_355 , V_49 ) ) ;
V_327 |= V_396 ;
F_185 ( V_54 , V_67 , F_232 ( V_355 , V_49 ) , V_327 ) ;
}
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_327 = F_183 ( V_54 , V_67 , F_231 ( V_355 , V_49 ) ) ;
V_327 &= ~ ( 0xff << V_397 ) ;
V_327 |= ( 0x9a << V_397 ) ;
F_185 ( V_54 , V_67 , F_231 ( V_355 , V_49 ) , V_327 ) ;
}
}
V_327 = F_183 ( V_54 , V_67 , F_228 ( V_355 ) ) ;
V_327 |= V_390 | V_391 ;
F_185 ( V_54 , V_67 , F_228 ( V_355 ) , V_327 ) ;
V_327 = F_183 ( V_54 , V_67 , F_229 ( V_355 ) ) ;
V_327 |= V_390 | V_391 ;
F_185 ( V_54 , V_67 , F_229 ( V_355 ) , V_327 ) ;
V_327 = F_183 ( V_54 , V_67 , V_398 ) ;
V_327 |= V_399 ;
F_185 ( V_54 , V_67 , V_398 , V_327 ) ;
F_189 ( & V_54 -> V_356 ) ;
return 0 ;
}
static void
F_233 ( struct V_1 * V_1 ,
const T_3 V_370 [ V_371 ] )
{
T_3 V_50 = 0 ;
T_3 V_400 = 0 ;
int V_401 ;
T_3 V_402 ;
T_3 V_403 ;
for ( V_401 = 0 ; V_401 < V_1 -> V_198 ; V_401 ++ ) {
T_3 V_404 = F_234 ( V_370 , V_401 ) ;
T_3 V_405 = F_235 ( V_370 , V_401 ) ;
if ( V_404 > V_50 )
V_50 = V_404 ;
if ( V_405 > V_400 )
V_400 = V_405 ;
}
V_402 = F_218 ( V_1 ) ;
if ( V_50 >= V_402 )
V_50 = V_402 | V_406 ;
V_403 = F_219 ( V_1 , V_50 ) ;
if ( V_400 >= V_403 )
V_400 = V_403 | V_407 ;
for ( V_401 = 0 ; V_401 < 4 ; V_401 ++ )
V_1 -> V_386 [ V_401 ] = V_50 | V_400 ;
}
static T_2
F_236 ( T_3 V_386 )
{
T_2 V_408 = 0 ;
switch ( V_386 & V_376 ) {
case V_377 :
default:
V_408 |= V_235 ;
break;
case V_378 :
V_408 |= V_409 ;
break;
case V_374 :
V_408 |= V_410 ;
break;
case V_373 :
V_408 |= V_411 ;
break;
}
switch ( V_386 & V_387 ) {
case V_381 :
default:
V_408 |= V_236 ;
break;
case V_380 :
V_408 |= V_412 ;
break;
case V_379 :
V_408 |= V_413 ;
break;
case V_382 :
V_408 |= V_414 ;
break;
}
return V_408 ;
}
static T_2
F_237 ( T_3 V_386 )
{
int V_408 = V_386 & ( V_376 |
V_387 ) ;
switch ( V_408 ) {
case V_377 | V_381 :
case V_378 | V_381 :
return V_415 ;
case V_377 | V_380 :
return V_416 ;
case V_377 | V_379 :
case V_378 | V_379 :
return V_417 ;
case V_378 | V_380 :
case V_374 | V_380 :
return V_418 ;
case V_374 | V_381 :
case V_373 | V_381 :
return V_419 ;
default:
F_45 ( L_59
L_60 , V_408 ) ;
return V_415 ;
}
}
static T_2
F_238 ( T_3 V_386 )
{
int V_408 = V_386 & ( V_376 |
V_387 ) ;
switch ( V_408 ) {
case V_377 | V_381 :
return V_420 ;
case V_377 | V_380 :
return V_421 ;
case V_377 | V_379 :
return V_422 ;
case V_378 | V_381 :
return V_423 ;
case V_378 | V_380 :
return V_424 ;
case V_374 | V_381 :
return V_425 ;
case V_374 | V_380 :
return V_426 ;
default:
F_45 ( L_59
L_60 , V_408 ) ;
return V_427 ;
}
}
static T_2
F_239 ( T_3 V_386 )
{
int V_408 = V_386 & ( V_376 |
V_387 ) ;
switch ( V_408 ) {
case V_377 | V_381 :
return V_428 ;
case V_377 | V_380 :
return V_429 ;
case V_377 | V_379 :
return V_430 ;
case V_377 | V_382 :
return V_431 ;
case V_378 | V_381 :
return V_432 ;
case V_378 | V_380 :
return V_433 ;
case V_378 | V_379 :
return V_434 ;
case V_374 | V_381 :
return V_435 ;
case V_374 | V_380 :
return V_436 ;
default:
F_45 ( L_59
L_60 , V_408 ) ;
return V_428 ;
}
}
static T_2
F_240 ( T_3 V_386 )
{
int V_408 = V_386 & ( V_376 |
V_387 ) ;
switch ( V_408 ) {
case V_377 | V_381 :
return V_437 ;
case V_377 | V_380 :
return V_438 ;
case V_377 | V_379 :
return V_439 ;
case V_378 | V_381 :
return V_440 ;
case V_378 | V_380 :
return V_441 ;
case V_378 | V_379 :
return V_442 ;
case V_374 | V_381 :
return V_443 ;
case V_374 | V_380 :
return V_444 ;
case V_373 | V_381 :
return V_445 ;
default:
F_45 ( L_59
L_60 , V_408 ) ;
return V_437 ;
}
}
static void
F_241 ( struct V_1 * V_1 , T_2 * V_232 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_21 V_21 = V_3 -> V_21 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_408 , V_246 ;
T_3 V_386 = V_1 -> V_386 [ 0 ] ;
if ( F_63 ( V_7 ) ) {
V_408 = F_240 ( V_386 ) ;
V_246 = V_446 ;
} else if ( F_8 ( V_7 ) ) {
V_408 = F_239 ( V_386 ) ;
V_246 = V_446 ;
} else if ( F_85 ( V_7 ) ) {
V_408 = F_227 ( V_1 ) ;
V_246 = 0 ;
} else if ( F_24 ( V_7 ) ) {
V_408 = F_220 ( V_1 ) ;
V_246 = 0 ;
} else if ( F_55 ( V_7 ) && V_21 == V_22 ) {
V_408 = F_238 ( V_386 ) ;
V_246 = V_447 ;
} else if ( F_54 ( V_7 ) && V_21 == V_22 ) {
V_408 = F_237 ( V_386 ) ;
V_246 = V_448 ;
} else {
V_408 = F_236 ( V_386 ) ;
V_246 = V_449 | V_450 ;
}
F_45 ( L_61 , V_408 ) ;
* V_232 = ( * V_232 & ~ V_246 ) | V_408 ;
}
static bool
F_242 ( struct V_1 * V_1 ,
T_2 * V_232 ,
T_3 V_451 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
T_3 V_452 [ sizeof( V_1 -> V_386 ) + 1 ] ;
int V_126 , V_453 ;
if ( F_13 ( V_7 ) ) {
T_2 V_454 = F_25 ( F_243 ( V_21 ) ) ;
if ( V_451 & V_455 )
V_454 |= V_456 ;
else
V_454 &= ~ V_456 ;
V_454 &= ~ V_457 ;
switch ( V_451 & V_458 ) {
case V_459 :
V_454 |= V_460 ;
break;
case V_461 :
V_454 |= V_462 ;
break;
case V_463 :
V_454 |= V_464 ;
break;
case V_465 :
V_454 |= V_466 ;
break;
}
F_38 ( F_243 ( V_21 ) , V_454 ) ;
} else if ( F_107 ( V_7 ) && ( F_55 ( V_7 ) || V_21 != V_22 ) ) {
* V_232 &= ~ V_467 ;
switch ( V_451 & V_458 ) {
case V_459 :
* V_232 |= V_242 ;
break;
case V_461 :
* V_232 |= V_468 ;
break;
case V_463 :
* V_232 |= V_469 ;
break;
case V_465 :
F_51 ( L_62 ) ;
* V_232 |= V_469 ;
break;
}
} else {
* V_232 &= ~ V_470 ;
switch ( V_451 & V_458 ) {
case V_459 :
* V_232 |= V_244 ;
break;
case V_461 :
* V_232 |= V_471 ;
break;
case V_463 :
* V_232 |= V_472 ;
break;
case V_465 :
F_51 ( L_62 ) ;
* V_232 |= V_472 ;
break;
}
}
F_38 ( V_1 -> V_167 , * V_232 ) ;
F_99 ( V_1 -> V_167 ) ;
V_452 [ 0 ] = V_451 ;
if ( ( V_451 & V_458 ) ==
V_459 ) {
V_453 = 1 ;
} else {
memcpy ( V_452 + 1 , V_1 -> V_386 , V_1 -> V_198 ) ;
V_453 = V_1 -> V_198 + 1 ;
}
V_126 = F_244 ( & V_1 -> V_142 , V_473 ,
V_452 , V_453 ) ;
return V_126 == V_453 ;
}
static bool
F_245 ( struct V_1 * V_1 , T_2 * V_232 ,
T_3 V_451 )
{
memset ( V_1 -> V_386 , 0 , sizeof( V_1 -> V_386 ) ) ;
F_241 ( V_1 , V_232 ) ;
return F_242 ( V_1 , V_232 , V_451 ) ;
}
static bool
F_246 ( struct V_1 * V_1 , T_2 * V_232 ,
const T_3 V_370 [ V_371 ] )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
int V_126 ;
F_233 ( V_1 , V_370 ) ;
F_241 ( V_1 , V_232 ) ;
F_38 ( V_1 -> V_167 , * V_232 ) ;
F_99 ( V_1 -> V_167 ) ;
V_126 = F_244 ( & V_1 -> V_142 , V_474 ,
V_1 -> V_386 , V_1 -> V_198 ) ;
return V_126 == V_1 -> V_198 ;
}
static void F_247 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
T_2 V_327 ;
if ( ! F_13 ( V_7 ) )
return;
V_327 = F_25 ( F_243 ( V_21 ) ) ;
V_327 &= ~ V_457 ;
V_327 |= V_475 ;
F_38 ( F_243 ( V_21 ) , V_327 ) ;
if ( V_21 == V_22 )
return;
if ( F_248 ( ( F_25 ( F_249 ( V_21 ) ) & V_476 ) ,
1 ) )
F_51 ( L_63 ) ;
}
void
F_191 ( struct V_1 * V_1 )
{
struct V_477 * V_172 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_172 -> V_7 ;
int V_49 ;
T_3 V_478 ;
int V_479 , V_480 ;
T_2 V_232 = V_1 -> V_232 ;
T_3 V_481 [ 2 ] ;
if ( F_13 ( V_7 ) )
F_250 ( V_172 ) ;
V_481 [ 0 ] = V_1 -> V_175 ;
V_481 [ 1 ] = V_1 -> V_198 ;
if ( F_106 ( V_1 -> V_11 ) )
V_481 [ 1 ] |= V_482 ;
F_244 ( & V_1 -> V_142 , V_483 , V_481 , 2 ) ;
V_481 [ 0 ] = 0 ;
V_481 [ 1 ] = V_484 ;
F_244 ( & V_1 -> V_142 , V_485 , V_481 , 2 ) ;
V_232 |= V_277 ;
if ( ! F_245 ( V_1 , & V_232 ,
V_461 |
V_455 ) ) {
F_51 ( L_64 ) ;
return;
}
V_478 = 0xff ;
V_479 = 0 ;
V_480 = 0 ;
for (; ; ) {
T_3 V_370 [ V_371 ] ;
F_251 ( V_1 -> V_11 ) ;
if ( ! F_217 ( V_1 , V_370 ) ) {
F_51 ( L_65 ) ;
break;
}
if ( F_252 ( V_370 , V_1 -> V_198 ) ) {
F_45 ( L_66 ) ;
break;
}
for ( V_49 = 0 ; V_49 < V_1 -> V_198 ; V_49 ++ )
if ( ( V_1 -> V_386 [ V_49 ] & V_406 ) == 0 )
break;
if ( V_49 == V_1 -> V_198 ) {
++ V_480 ;
if ( V_480 == 5 ) {
F_51 ( L_67 ) ;
break;
}
F_245 ( V_1 , & V_232 ,
V_461 |
V_455 ) ;
V_479 = 0 ;
continue;
}
if ( ( V_1 -> V_386 [ 0 ] & V_376 ) == V_478 ) {
++ V_479 ;
if ( V_479 == 5 ) {
F_51 ( L_68 ) ;
break;
}
} else
V_479 = 0 ;
V_478 = V_1 -> V_386 [ 0 ] & V_376 ;
if ( ! F_246 ( V_1 , & V_232 , V_370 ) ) {
F_51 ( L_69 ) ;
break;
}
}
V_1 -> V_232 = V_232 ;
}
void
F_192 ( struct V_1 * V_1 )
{
bool V_486 = false ;
int V_487 , V_488 ;
T_2 V_232 = V_1 -> V_232 ;
T_2 V_489 = V_463 ;
if ( V_1 -> V_175 == V_16 || V_1 -> V_490 )
V_489 = V_465 ;
if ( ! F_242 ( V_1 , & V_232 ,
V_489 |
V_455 ) ) {
F_51 ( L_70 ) ;
return;
}
V_487 = 0 ;
V_488 = 0 ;
V_486 = false ;
for (; ; ) {
T_3 V_370 [ V_371 ] ;
if ( V_488 > 5 ) {
F_51 ( L_71 ) ;
break;
}
F_253 ( V_1 -> V_11 ) ;
if ( ! F_217 ( V_1 , V_370 ) ) {
F_51 ( L_65 ) ;
break;
}
if ( ! F_252 ( V_370 , V_1 -> V_198 ) ) {
F_191 ( V_1 ) ;
F_242 ( V_1 , & V_232 ,
V_489 |
V_455 ) ;
V_488 ++ ;
continue;
}
if ( F_254 ( V_370 , V_1 -> V_198 ) ) {
V_486 = true ;
break;
}
if ( V_487 > 5 ) {
F_177 ( V_1 ) ;
F_191 ( V_1 ) ;
F_242 ( V_1 , & V_232 ,
V_489 |
V_455 ) ;
V_487 = 0 ;
V_488 ++ ;
continue;
}
if ( ! F_246 ( V_1 , & V_232 , V_370 ) ) {
F_51 ( L_69 ) ;
break;
}
++ V_487 ;
}
F_247 ( V_1 ) ;
V_1 -> V_232 = V_232 ;
if ( V_486 )
F_45 ( L_72 ) ;
}
void F_193 ( struct V_1 * V_1 )
{
F_242 ( V_1 , & V_1 -> V_232 ,
V_459 ) ;
}
static void
F_177 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_21 V_21 = V_3 -> V_21 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_185 * V_185 =
F_27 ( V_3 -> V_4 . V_4 . V_69 ) ;
T_2 V_232 = V_1 -> V_232 ;
if ( F_70 ( F_13 ( V_7 ) ) )
return;
if ( F_70 ( ( F_25 ( V_1 -> V_167 ) & V_277 ) == 0 ) )
return;
F_45 ( L_43 ) ;
if ( F_107 ( V_7 ) && ( F_55 ( V_7 ) || V_21 != V_22 ) ) {
V_232 &= ~ V_467 ;
F_38 ( V_1 -> V_167 , V_232 | V_491 ) ;
} else {
V_232 &= ~ V_470 ;
F_38 ( V_1 -> V_167 , V_232 | V_492 ) ;
}
F_99 ( V_1 -> V_167 ) ;
if ( F_255 ( V_7 ) &&
F_25 ( V_1 -> V_167 ) & V_245 ) {
struct V_68 * V_69 = V_3 -> V_4 . V_4 . V_69 ;
V_232 &= ~ V_245 ;
F_38 ( V_1 -> V_167 , V_232 ) ;
if ( F_70 ( V_69 == NULL ) ) {
F_99 ( V_1 -> V_167 ) ;
F_39 ( 50 ) ;
} else
F_256 ( V_7 , V_185 -> V_67 ) ;
}
V_232 &= ~ V_237 ;
F_38 ( V_1 -> V_167 , V_232 & ~ V_277 ) ;
F_99 ( V_1 -> V_167 ) ;
F_39 ( V_1 -> V_493 ) ;
}
static bool
F_257 ( struct V_1 * V_1 )
{
struct V_2 * V_227 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_227 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
char V_494 [ sizeof( V_1 -> V_11 ) * 3 ] ;
if ( F_215 ( & V_1 -> V_142 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) < 0 )
return false ;
F_258 ( V_1 -> V_11 , sizeof( V_1 -> V_11 ) ,
32 , 1 , V_494 , sizeof( V_494 ) , false ) ;
F_45 ( L_73 , V_494 ) ;
if ( V_1 -> V_11 [ V_18 ] == 0 )
return false ;
memset ( V_1 -> V_318 , 0 , sizeof( V_1 -> V_318 ) ) ;
if ( F_1 ( V_1 ) ) {
F_215 ( & V_1 -> V_142 , V_495 ,
V_1 -> V_318 ,
sizeof( V_1 -> V_318 ) ) ;
if ( V_1 -> V_318 [ 0 ] & V_496 ) {
V_54 -> V_297 . V_298 = true ;
F_45 ( L_74 ) ;
}
}
if ( V_1 -> V_11 [ V_18 ] >= 0x12 &&
V_1 -> V_11 [ V_497 ] & V_498 ) {
V_1 -> V_490 = true ;
F_45 ( L_75 ) ;
} else
V_1 -> V_490 = false ;
if ( ! ( V_1 -> V_11 [ V_499 ] &
V_500 ) )
return true ;
if ( V_1 -> V_11 [ V_18 ] == 0x10 )
return true ;
if ( F_215 ( & V_1 -> V_142 , V_501 ,
V_1 -> V_502 ,
V_503 ) < 0 )
return false ;
return true ;
}
static void
F_259 ( struct V_1 * V_1 )
{
T_1 V_452 [ 3 ] ;
if ( ! ( V_1 -> V_11 [ V_504 ] & V_505 ) )
return;
F_119 ( V_1 ) ;
if ( F_215 ( & V_1 -> V_142 , V_506 , V_452 , 3 ) == 3 )
F_45 ( L_76 ,
V_452 [ 0 ] , V_452 [ 1 ] , V_452 [ 2 ] ) ;
if ( F_215 ( & V_1 -> V_142 , V_507 , V_452 , 3 ) == 3 )
F_45 ( L_77 ,
V_452 [ 0 ] , V_452 [ 1 ] , V_452 [ 2 ] ) ;
F_72 ( V_1 , false ) ;
}
int F_260 ( struct V_1 * V_1 , T_1 * V_508 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_185 * V_185 =
F_27 ( V_3 -> V_4 . V_4 . V_69 ) ;
T_1 V_452 [ 1 ] ;
if ( F_261 ( & V_1 -> V_142 , V_509 , V_452 ) < 0 )
return - V_510 ;
if ( ! ( V_452 [ 0 ] & V_511 ) )
return - V_512 ;
if ( F_140 ( & V_1 -> V_142 , V_513 ,
V_514 ) < 0 )
return - V_510 ;
F_256 ( V_7 , V_185 -> V_67 ) ;
F_256 ( V_7 , V_185 -> V_67 ) ;
if ( F_216 ( & V_1 -> V_142 , V_515 , V_508 , 6 ) < 0 )
return - V_510 ;
F_140 ( & V_1 -> V_142 , V_513 , 0 ) ;
return 0 ;
}
static bool
F_262 ( struct V_1 * V_1 , T_1 * V_516 )
{
return F_215 ( & V_1 -> V_142 ,
V_517 ,
V_516 , 1 ) == 1 ;
}
static void
F_263 ( struct V_1 * V_1 )
{
F_140 ( & V_1 -> V_142 , V_518 , V_519 ) ;
}
void
F_264 ( struct V_1 * V_1 )
{
struct V_94 * V_94 = & F_2 ( V_1 ) -> V_4 ;
T_1 V_516 ;
T_1 V_370 [ V_371 ] ;
if ( ! V_94 -> V_520 )
return;
if ( F_70 ( ! V_94 -> V_4 . V_69 ) )
return;
if ( ! F_217 ( V_1 , V_370 ) ) {
return;
}
if ( ! F_257 ( V_1 ) ) {
return;
}
if ( V_1 -> V_11 [ V_18 ] >= 0x11 &&
F_262 ( V_1 , & V_516 ) ) {
F_140 ( & V_1 -> V_142 ,
V_517 ,
V_516 ) ;
if ( V_516 & V_521 )
F_263 ( V_1 ) ;
if ( V_516 & ( V_522 | V_523 ) )
F_103 ( L_78 ) ;
}
if ( ! F_254 ( V_370 , V_1 -> V_198 ) ) {
F_45 ( L_79 ,
V_94 -> V_4 . V_162 ) ;
F_191 ( V_1 ) ;
F_192 ( V_1 ) ;
F_193 ( V_1 ) ;
}
}
static enum V_524
F_265 ( struct V_1 * V_1 )
{
T_3 * V_11 = V_1 -> V_11 ;
T_3 type ;
if ( ! F_257 ( V_1 ) )
return V_525 ;
if ( ! ( V_11 [ V_499 ] & V_500 ) )
return V_526 ;
if ( V_1 -> V_11 [ V_18 ] >= 0x11 &&
V_1 -> V_502 [ 0 ] & V_527 ) {
T_3 V_528 ;
if ( F_215 ( & V_1 -> V_142 , V_529 ,
& V_528 , 1 ) < 0 )
return V_530 ;
return F_266 ( V_528 ) ? V_526
: V_525 ;
}
if ( F_267 ( & V_1 -> V_142 . V_171 ) )
return V_526 ;
if ( V_1 -> V_11 [ V_18 ] >= 0x11 ) {
type = V_1 -> V_502 [ 0 ] & V_531 ;
if ( type == V_532 ||
type == V_533 )
return V_530 ;
} else {
type = V_1 -> V_11 [ V_499 ] &
V_534 ;
if ( type == V_535 ||
type == V_536 )
return V_530 ;
}
F_45 ( L_80 ) ;
return V_525 ;
}
static enum V_524
F_268 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_524 V_101 ;
if ( F_1 ( V_1 ) ) {
V_101 = F_269 ( V_7 ) ;
if ( V_101 == V_530 )
V_101 = V_526 ;
return V_101 ;
}
if ( ! F_270 ( V_54 , V_3 ) )
return V_525 ;
return F_265 ( V_1 ) ;
}
static enum V_524
F_271 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_2 V_537 ;
if ( F_1 ( V_1 ) ) {
enum V_524 V_101 ;
V_101 = F_269 ( V_7 ) ;
if ( V_101 == V_530 )
V_101 = V_526 ;
return V_101 ;
}
if ( F_24 ( V_7 ) ) {
switch ( V_3 -> V_21 ) {
case V_75 :
V_537 = V_538 ;
break;
case V_77 :
V_537 = V_539 ;
break;
case V_165 :
V_537 = V_540 ;
break;
default:
return V_530 ;
}
} else {
switch ( V_3 -> V_21 ) {
case V_75 :
V_537 = V_541 ;
break;
case V_77 :
V_537 = V_542 ;
break;
case V_165 :
V_537 = V_543 ;
break;
default:
return V_530 ;
}
}
if ( ( F_25 ( V_544 ) & V_537 ) == 0 )
return V_525 ;
return F_265 ( V_1 ) ;
}
static struct V_545 *
F_272 ( struct V_8 * V_9 , struct V_546 * V_547 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
if ( V_32 -> V_545 ) {
if ( F_273 ( V_32 -> V_545 ) )
return NULL ;
return F_274 ( V_32 -> V_545 ) ;
}
return F_275 ( V_9 , V_547 ) ;
}
static int
F_276 ( struct V_8 * V_9 , struct V_546 * V_547 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
if ( V_32 -> V_545 ) {
if ( F_273 ( V_32 -> V_545 ) )
return 0 ;
return F_277 ( V_9 ,
V_32 -> V_545 ) ;
}
return F_278 ( V_9 , V_547 ) ;
}
static enum V_524
F_279 ( struct V_8 * V_9 , bool V_548 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_94 * V_94 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_524 V_101 ;
enum V_95 V_96 ;
struct V_545 * V_545 = NULL ;
F_280 ( V_54 ) ;
V_96 = F_42 ( V_94 ) ;
F_118 ( V_54 , V_96 ) ;
F_45 ( L_81 ,
V_9 -> V_4 . V_549 , V_9 -> V_162 ) ;
V_1 -> V_208 = false ;
if ( F_30 ( V_7 ) )
V_101 = F_268 ( V_1 ) ;
else
V_101 = F_271 ( V_1 ) ;
if ( V_101 != V_526 )
goto V_132;
F_259 ( V_1 ) ;
if ( V_1 -> V_550 != V_551 ) {
V_1 -> V_208 = ( V_1 -> V_550 == V_552 ) ;
} else {
V_545 = F_272 ( V_9 , & V_1 -> V_142 . V_171 ) ;
if ( V_545 ) {
V_1 -> V_208 = F_281 ( V_545 ) ;
F_282 ( V_545 ) ;
}
}
if ( V_94 -> type != V_5 )
V_94 -> type = V_553 ;
V_101 = V_526 ;
V_132:
F_122 ( V_54 , V_96 ) ;
F_283 ( V_54 ) ;
return V_101 ;
}
static int F_284 ( struct V_8 * V_9 )
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
F_118 ( V_54 , V_96 ) ;
V_126 = F_276 ( V_9 , & V_1 -> V_142 . V_171 ) ;
F_122 ( V_54 , V_96 ) ;
if ( V_126 )
return V_126 ;
if ( F_1 ( V_1 ) && V_32 -> V_34 . V_33 ) {
struct V_30 * V_31 ;
V_31 = F_285 ( V_7 ,
V_32 -> V_34 . V_33 ) ;
if ( V_31 ) {
F_286 ( V_9 , V_31 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_287 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_94 * V_94 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_95 V_96 ;
struct V_545 * V_545 ;
bool V_208 = false ;
V_96 = F_42 ( V_94 ) ;
F_118 ( V_54 , V_96 ) ;
V_545 = F_272 ( V_9 , & V_1 -> V_142 . V_171 ) ;
if ( V_545 ) {
V_208 = F_281 ( V_545 ) ;
F_282 ( V_545 ) ;
}
F_122 ( V_54 , V_96 ) ;
return V_208 ;
}
static int
F_288 ( struct V_8 * V_9 ,
struct V_554 * V_555 ,
T_7 V_327 )
{
struct V_53 * V_54 = V_9 -> V_7 -> V_55 ;
struct V_32 * V_32 = F_19 ( V_9 ) ;
struct V_94 * V_94 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_94 -> V_4 ) ;
int V_126 ;
V_126 = F_289 ( & V_9 -> V_4 , V_555 , V_327 ) ;
if ( V_126 )
return V_126 ;
if ( V_555 == V_54 -> V_556 ) {
int V_49 = V_327 ;
bool V_208 ;
if ( V_49 == V_1 -> V_550 )
return 0 ;
V_1 -> V_550 = V_49 ;
if ( V_49 == V_551 )
V_208 = F_287 ( V_9 ) ;
else
V_208 = ( V_49 == V_552 ) ;
if ( V_208 == V_1 -> V_208 )
return 0 ;
V_1 -> V_208 = V_208 ;
goto V_102;
}
if ( V_555 == V_54 -> V_557 ) {
bool V_558 = V_1 -> V_217 ;
T_2 V_559 = V_1 -> V_218 ;
switch ( V_327 ) {
case V_560 :
V_1 -> V_217 = true ;
break;
case V_561 :
V_1 -> V_217 = false ;
V_1 -> V_218 = 0 ;
break;
case V_562 :
V_1 -> V_217 = false ;
V_1 -> V_218 = V_219 ;
break;
default:
return - V_161 ;
}
if ( V_558 == V_1 -> V_217 &&
V_559 == V_1 -> V_218 )
return 0 ;
goto V_102;
}
if ( F_1 ( V_1 ) &&
V_555 == V_9 -> V_7 -> V_266 . V_563 ) {
if ( V_327 == V_564 ) {
F_45 ( L_82 ) ;
return - V_161 ;
}
if ( V_32 -> V_34 . V_209 == V_327 ) {
return 0 ;
}
V_32 -> V_34 . V_209 = V_327 ;
goto V_102;
}
return - V_161 ;
V_102:
if ( V_94 -> V_4 . V_69 )
F_290 ( V_94 -> V_4 . V_69 ) ;
return 0 ;
}
static void
F_291 ( struct V_8 * V_9 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
if ( ! F_292 ( V_32 -> V_545 ) )
F_282 ( V_32 -> V_545 ) ;
if ( V_9 -> V_565 == V_566 )
F_293 ( & V_32 -> V_34 ) ;
F_294 ( V_9 ) ;
F_282 ( V_9 ) ;
}
void F_295 ( struct V_477 * V_172 )
{
struct V_2 * V_3 = F_206 ( V_172 ) ;
struct V_1 * V_1 = & V_3 -> V_567 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
F_78 ( & V_1 -> V_142 ) ;
F_296 ( V_172 ) ;
if ( F_1 ( V_1 ) ) {
F_297 ( & V_1 -> V_272 ) ;
F_125 ( & V_7 -> V_266 . V_267 , NULL ) ;
F_120 ( V_1 ) ;
F_126 ( & V_7 -> V_266 . V_267 ) ;
if ( V_1 -> V_84 . V_568 ) {
F_298 ( & V_1 -> V_84 ) ;
V_1 -> V_84 . V_568 = NULL ;
}
}
F_282 ( V_3 ) ;
}
static void
F_299 ( struct V_94 * V_94 )
{
struct V_1 * V_1 = F_5 ( & V_94 -> V_4 ) ;
F_264 ( V_1 ) ;
}
int
F_300 ( struct V_68 * V_69 )
{
struct V_6 * V_7 = V_69 -> V_7 ;
struct V_94 * V_94 ;
struct V_1 * V_1 ;
F_301 (dev, crtc, intel_encoder) {
V_1 = F_5 ( & V_94 -> V_4 ) ;
if ( V_94 -> type == V_553 ||
V_94 -> type == V_5 )
return V_1 -> V_167 ;
}
return - 1 ;
}
bool F_302 ( struct V_6 * V_7 , enum V_21 V_21 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
union V_569 * V_570 ;
int V_49 ;
static const short V_571 [] = {
[ V_75 ] = V_572 ,
[ V_77 ] = V_573 ,
[ V_165 ] = V_574 ,
} ;
if ( V_21 == V_22 )
return true ;
if ( ! V_54 -> V_212 . V_575 )
return false ;
for ( V_49 = 0 ; V_49 < V_54 -> V_212 . V_575 ; V_49 ++ ) {
V_570 = V_54 -> V_212 . V_576 + V_49 ;
if ( V_570 -> V_577 . V_578 == V_571 [ V_21 ] &&
( V_570 -> V_577 . V_579 & V_580 ) ==
( V_581 & V_580 ) )
return true ;
}
return false ;
}
static void
F_303 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
F_304 ( V_9 ) ;
F_305 ( V_9 ) ;
V_1 -> V_217 = true ;
if ( F_1 ( V_1 ) ) {
F_306 ( V_9 -> V_7 ) ;
F_307 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_266 . V_563 ,
V_582 ) ;
V_32 -> V_34 . V_209 = V_582 ;
}
}
static void F_308 ( struct V_1 * V_1 )
{
V_1 -> V_253 = V_269 ;
V_1 -> V_256 = V_269 ;
V_1 -> V_258 = V_269 ;
}
static void
F_202 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_361 * V_132 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_361 V_583 , V_212 , V_584 , V_585 ;
T_4 V_586 , V_587 , V_85 , V_262 ;
int V_86 , V_588 , V_589 , V_87 ;
if ( F_30 ( V_7 ) ) {
V_86 = V_78 ;
V_588 = V_590 ;
V_589 = V_591 ;
V_87 = V_592 ;
} else {
enum V_67 V_67 = F_26 ( V_1 ) ;
V_86 = F_31 ( V_67 ) ;
V_588 = F_28 ( V_67 ) ;
V_589 = F_309 ( V_67 ) ;
V_87 = F_37 ( V_67 ) ;
}
V_262 = F_117 ( V_1 ) ;
F_38 ( V_86 , V_262 ) ;
V_586 = F_25 ( V_588 ) ;
V_587 = F_25 ( V_589 ) ;
V_85 = F_25 ( V_87 ) ;
V_583 . V_593 = ( V_586 & V_594 ) >>
V_595 ;
V_583 . V_596 = ( V_586 & V_597 ) >>
V_598 ;
V_583 . V_599 = ( V_587 & V_600 ) >>
V_601 ;
V_583 . V_602 = ( V_587 & V_603 ) >>
V_604 ;
V_583 . V_605 = ( ( V_85 & V_606 ) >>
V_607 ) * 1000 ;
F_45 ( L_83 ,
V_583 . V_593 , V_583 . V_596 , V_583 . V_599 , V_583 . V_602 , V_583 . V_605 ) ;
V_212 = V_54 -> V_212 . V_608 ;
V_584 . V_593 = 210 * 10 ;
V_584 . V_596 = 50 * 10 ;
V_584 . V_599 = 50 * 10 ;
V_584 . V_602 = 500 * 10 ;
V_584 . V_605 = ( 510 + 100 ) * 10 ;
F_45 ( L_84 ,
V_212 . V_593 , V_212 . V_596 , V_212 . V_599 , V_212 . V_602 , V_212 . V_605 ) ;
#define F_310 ( T_8 ) final.field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_310 ( V_593 ) ;
F_310 ( V_596 ) ;
F_310 ( V_599 ) ;
F_310 ( V_602 ) ;
F_310 ( V_605 ) ;
#undef F_310
#define F_311 ( T_8 ) (DIV_ROUND_UP(final.field, 10))
V_1 -> V_265 = F_311 ( V_593 ) ;
V_1 -> V_257 = F_311 ( V_596 ) ;
V_1 -> V_259 = F_311 ( V_599 ) ;
V_1 -> V_493 = F_311 ( V_602 ) ;
V_1 -> V_92 = F_311 ( V_605 ) ;
#undef F_311
F_45 ( L_85 ,
V_1 -> V_265 , V_1 -> V_493 ,
V_1 -> V_92 ) ;
F_45 ( L_86 ,
V_1 -> V_257 , V_1 -> V_259 ) ;
if ( V_132 )
* V_132 = V_585 ;
}
static void
F_203 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_361 * V_609 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_586 , V_587 , V_85 , V_72 = 0 ;
int div = F_30 ( V_7 ) ? F_57 ( V_7 ) : F_23 ( V_7 ) ;
int V_588 , V_589 , V_87 ;
if ( F_30 ( V_7 ) ) {
V_588 = V_590 ;
V_589 = V_591 ;
V_87 = V_592 ;
} else {
enum V_67 V_67 = F_26 ( V_1 ) ;
V_588 = F_28 ( V_67 ) ;
V_589 = F_309 ( V_67 ) ;
V_87 = F_37 ( V_67 ) ;
}
V_586 = ( V_609 -> V_593 << V_595 ) |
( 1 << V_598 ) ;
V_587 = ( 1 << V_601 ) |
( V_609 -> V_602 << V_604 ) ;
V_85 = ( ( 100 * div ) / 2 - 1 ) << V_610 ;
V_85 |= ( F_56 ( V_609 -> V_605 , 1000 )
<< V_607 ) ;
if ( F_24 ( V_7 ) ) {
if ( F_2 ( V_1 ) -> V_21 == V_75 )
V_72 = V_74 ;
else
V_72 = V_76 ;
} else if ( F_255 ( V_7 ) || F_107 ( V_7 ) ) {
if ( F_2 ( V_1 ) -> V_21 == V_22 )
V_72 = V_611 ;
else
V_72 = V_612 ;
}
V_586 |= V_72 ;
F_38 ( V_588 , V_586 ) ;
F_38 ( V_589 , V_587 ) ;
F_38 ( V_87 , V_85 ) ;
F_45 ( L_87 ,
F_25 ( V_588 ) ,
F_25 ( V_589 ) ,
F_25 ( V_87 ) ) ;
}
void F_312 ( struct V_6 * V_7 , int V_613 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_94 * V_172 ;
struct V_1 * V_1 = NULL ;
struct V_173 * V_189 = NULL ;
struct V_185 * V_185 = NULL ;
struct V_32 * V_32 = V_54 -> V_614 . V_9 ;
T_4 V_528 , V_327 ;
enum V_615 V_104 = V_616 ;
if ( V_613 <= 0 ) {
F_45 ( L_88 ) ;
return;
}
if ( V_32 == NULL ) {
F_45 ( L_89 ) ;
return;
}
if ( F_10 ( V_7 ) -> V_17 < 8 && F_152 ( V_7 ) ) {
F_45 ( L_90 ) ;
return;
}
V_172 = F_6 ( & V_32 -> V_4 ) ;
V_1 = F_5 ( & V_172 -> V_4 ) ;
V_185 = V_172 -> V_197 ;
if ( ! V_185 ) {
F_45 ( L_91 ) ;
return;
}
V_189 = & V_185 -> V_189 ;
if ( V_1 -> V_224 . type < V_225 ) {
F_45 ( L_92 ) ;
return;
}
if ( V_32 -> V_34 . V_223 -> V_617 == V_613 )
V_104 = V_618 ;
if ( V_104 == V_1 -> V_224 . V_619 ) {
F_45 (
L_93 ) ;
return;
}
if ( ! V_185 -> V_620 ) {
F_45 ( L_94 ) ;
return;
}
if ( F_10 ( V_7 ) -> V_17 > 6 && F_10 ( V_7 ) -> V_17 < 8 ) {
V_528 = F_313 ( V_185 -> V_189 . V_190 ) ;
V_327 = F_25 ( V_528 ) ;
if ( V_104 > V_616 ) {
V_327 |= V_621 ;
F_86 ( V_185 , & V_189 -> V_226 ) ;
} else {
V_327 &= ~ V_621 ;
}
F_38 ( V_528 , V_327 ) ;
}
F_182 ( & V_1 -> V_224 . V_622 ) ;
V_1 -> V_224 . V_619 = V_104 ;
F_189 ( & V_1 -> V_224 . V_622 ) ;
F_45 ( L_95 , V_613 ) ;
}
static struct V_30 *
F_314 ( struct V_2 * V_3 ,
struct V_32 * V_32 ,
struct V_30 * V_33 )
{
struct V_8 * V_9 = & V_32 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_567 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_30 * V_223 = NULL ;
if ( F_10 ( V_7 ) -> V_17 <= 6 ) {
F_45 ( L_96 ) ;
return NULL ;
}
if ( V_54 -> V_212 . V_623 != V_225 ) {
F_315 ( L_97 ) ;
return NULL ;
}
V_223 = F_316
( V_7 , V_33 , V_9 ) ;
if ( ! V_223 ) {
F_315 ( L_98 ) ;
return NULL ;
}
V_54 -> V_614 . V_9 = V_32 ;
F_317 ( & V_1 -> V_224 . V_622 ) ;
V_1 -> V_224 . type = V_54 -> V_212 . V_623 ;
V_1 -> V_224 . V_619 = V_616 ;
F_315 ( L_99 ) ;
return V_223 ;
}
static bool F_318 ( struct V_1 * V_1 ,
struct V_32 * V_32 ,
struct V_361 * V_362 )
{
struct V_8 * V_9 = & V_32 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_94 * V_94 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_94 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_30 * V_33 = NULL ;
struct V_30 * V_223 = NULL ;
bool V_624 ;
struct V_30 * V_625 ;
struct V_545 * V_545 ;
V_1 -> V_224 . type = V_626 ;
if ( ! F_1 ( V_1 ) )
return true ;
if ( F_41 ( V_1 ) ) {
enum V_95 V_96 ;
V_96 = F_42 ( V_94 ) ;
F_118 ( V_54 , V_96 ) ;
}
F_119 ( V_1 ) ;
V_624 = F_257 ( V_1 ) ;
F_72 ( V_1 , false ) ;
if ( V_624 ) {
if ( V_1 -> V_11 [ V_18 ] >= 0x11 )
V_54 -> V_627 =
V_1 -> V_11 [ V_628 ] &
V_629 ;
} else {
F_315 ( L_100 ) ;
return false ;
}
F_203 ( V_7 , V_1 , V_362 ) ;
F_182 ( & V_7 -> V_266 . V_622 ) ;
V_545 = F_275 ( V_9 , & V_1 -> V_142 . V_171 ) ;
if ( V_545 ) {
if ( F_319 ( V_9 , V_545 ) ) {
F_320 ( V_9 ,
V_545 ) ;
F_321 ( V_9 , V_545 ) ;
} else {
F_282 ( V_545 ) ;
V_545 = F_322 ( - V_161 ) ;
}
} else {
V_545 = F_322 ( - V_630 ) ;
}
V_32 -> V_545 = V_545 ;
F_175 (scan, &connector->probed_modes, head) {
if ( ( V_625 -> type & V_631 ) ) {
V_33 = F_285 ( V_7 , V_625 ) ;
V_223 = F_314 (
V_3 ,
V_32 , V_33 ) ;
break;
}
}
if ( ! V_33 && V_54 -> V_212 . V_632 ) {
V_33 = F_285 ( V_7 ,
V_54 -> V_212 . V_632 ) ;
if ( V_33 )
V_33 -> type |= V_631 ;
}
F_189 ( & V_7 -> V_266 . V_622 ) ;
if ( F_24 ( V_7 ) ) {
V_1 -> V_84 . V_568 = F_34 ;
F_323 ( & V_1 -> V_84 ) ;
}
F_324 ( & V_32 -> V_34 , V_33 , V_223 ) ;
F_325 ( V_9 ) ;
return true ;
}
bool
F_326 ( struct V_2 * V_3 ,
struct V_32 * V_32 )
{
struct V_8 * V_9 = & V_32 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_567 ;
struct V_94 * V_94 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_94 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
struct V_361 V_362 = { 0 } ;
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
V_1 -> V_232 = F_25 ( V_1 -> V_167 ) ;
V_1 -> V_13 = V_32 ;
if ( F_302 ( V_7 , V_21 ) )
type = V_566 ;
else
type = V_633 ;
if ( type == V_566 )
V_94 -> type = V_5 ;
F_45 ( L_101 ,
type == V_566 ? L_102 : L_103 ,
F_327 ( V_21 ) ) ;
F_328 ( V_7 , V_9 , & V_634 , type ) ;
F_329 ( V_9 , & V_635 ) ;
V_9 -> V_636 = true ;
V_9 -> V_637 = 0 ;
F_330 ( & V_1 -> V_272 ,
F_123 ) ;
F_331 ( V_32 , V_94 ) ;
F_332 ( V_9 ) ;
if ( F_13 ( V_7 ) )
V_32 -> V_638 = V_639 ;
else
V_32 -> V_638 = V_640 ;
V_32 -> V_641 = F_79 ;
switch ( V_21 ) {
case V_22 :
V_94 -> V_642 = V_643 ;
break;
case V_75 :
V_94 -> V_642 = V_644 ;
break;
case V_77 :
V_94 -> V_642 = V_645 ;
break;
case V_165 :
V_94 -> V_642 = V_646 ;
break;
default:
F_75 () ;
}
if ( F_1 ( V_1 ) ) {
F_308 ( V_1 ) ;
F_202 ( V_7 , V_1 , & V_362 ) ;
}
F_74 ( V_1 , V_32 ) ;
V_1 -> V_308 = false ;
if ( ! F_318 ( V_1 , V_32 , & V_362 ) ) {
F_78 ( & V_1 -> V_142 ) ;
if ( F_1 ( V_1 ) ) {
F_297 ( & V_1 -> V_272 ) ;
F_125 ( & V_7 -> V_266 . V_267 , NULL ) ;
F_120 ( V_1 ) ;
F_126 ( & V_7 -> V_266 . V_267 ) ;
}
F_333 ( V_9 ) ;
F_294 ( V_9 ) ;
return false ;
}
F_303 ( V_1 , V_9 ) ;
if ( F_83 ( V_7 ) && ! F_334 ( V_7 ) ) {
T_4 V_454 = F_25 ( V_647 ) ;
F_38 ( V_647 , ( V_454 & ~ 0xf ) | 0xd ) ;
}
return true ;
}
void
F_335 ( struct V_6 * V_7 , int V_167 , enum V_21 V_21 )
{
struct V_2 * V_3 ;
struct V_94 * V_94 ;
struct V_477 * V_172 ;
struct V_32 * V_32 ;
V_3 = F_336 ( sizeof( * V_3 ) , V_648 ) ;
if ( ! V_3 )
return;
V_32 = F_336 ( sizeof( * V_32 ) , V_648 ) ;
if ( ! V_32 ) {
F_282 ( V_3 ) ;
return;
}
V_94 = & V_3 -> V_4 ;
V_172 = & V_94 -> V_4 ;
F_337 ( V_7 , & V_94 -> V_4 , & V_649 ,
V_650 ) ;
V_94 -> V_651 = F_92 ;
V_94 -> V_652 = F_176 ;
V_94 -> V_638 = F_141 ;
V_94 -> V_653 = F_147 ;
if ( F_85 ( V_7 ) ) {
V_94 -> V_654 = F_212 ;
V_94 -> V_655 = F_195 ;
V_94 -> V_656 = F_180 ;
} else if ( F_24 ( V_7 ) ) {
V_94 -> V_657 = F_205 ;
V_94 -> V_654 = F_197 ;
V_94 -> V_655 = F_195 ;
V_94 -> V_656 = F_179 ;
} else {
V_94 -> V_654 = F_196 ;
V_94 -> V_655 = F_194 ;
V_94 -> V_656 = F_178 ;
}
V_3 -> V_21 = V_21 ;
V_3 -> V_567 . V_167 = V_167 ;
V_94 -> type = V_553 ;
if ( F_85 ( V_7 ) ) {
if ( V_21 == V_165 )
V_94 -> V_658 = 1 << 2 ;
else
V_94 -> V_658 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_94 -> V_658 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_94 -> V_659 = 0 ;
V_94 -> V_660 = F_299 ;
if ( ! F_326 ( V_3 , V_32 ) ) {
F_296 ( V_172 ) ;
F_282 ( V_3 ) ;
F_282 ( V_32 ) ;
}
}
