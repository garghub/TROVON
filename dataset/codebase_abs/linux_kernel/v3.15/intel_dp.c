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
static bool F_34 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
return ( F_25 ( F_32 ( V_1 ) ) & V_80 ) != 0 ;
}
static bool F_35 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
return ! V_54 -> V_81 . V_82 &&
( F_25 ( F_29 ( V_1 ) ) & V_83 ) != 0 ;
}
static void
F_36 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_34 ( V_1 ) && ! F_35 ( V_1 ) ) {
F_11 ( 1 , L_2 ) ;
F_37 ( L_3 ,
F_25 ( F_32 ( V_1 ) ) ,
F_25 ( F_29 ( V_1 ) ) ) ;
}
}
static T_2
F_38 ( struct V_1 * V_1 , bool V_84 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_85 = V_1 -> V_86 ;
T_2 V_87 ;
bool V_88 ;
#define F_39 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_84 )
V_88 = F_40 ( V_54 -> V_89 , F_39 ,
F_41 ( 10 ) ) ;
else
V_88 = F_42 ( F_39 , 10 ) == 0 ;
if ( ! V_88 )
F_43 ( L_4 ,
V_84 ) ;
#undef F_39
return V_87 ;
}
static T_2 F_44 ( struct V_1 * V_1 , int V_90 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
return V_90 ? 0 : F_23 ( V_7 ) / 2 ;
}
static T_2 F_45 ( struct V_1 * V_1 , int V_90 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
if ( V_90 )
return 0 ;
if ( V_3 -> V_21 == V_22 ) {
if ( F_46 ( V_7 ) || F_47 ( V_7 ) )
return 200 ;
else
return 225 ;
} else {
return F_48 ( F_49 ( V_7 ) , 2 ) ;
}
}
static T_2 F_50 ( struct V_1 * V_1 , int V_90 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( V_3 -> V_21 == V_22 ) {
if ( V_90 )
return 0 ;
return F_51 ( F_52 ( V_54 ) , 2000 ) ;
} else if ( V_54 -> V_91 == V_92 ) {
switch ( V_90 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
} else {
return V_90 ? 0 : F_48 ( F_49 ( V_7 ) , 2 ) ;
}
}
static T_2 F_53 ( struct V_1 * V_1 , int V_90 )
{
return V_90 ? 0 : 100 ;
}
static T_2 F_54 ( struct V_1 * V_1 ,
bool V_84 ,
int V_93 ,
T_2 V_94 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_95 , V_96 ;
if ( F_46 ( V_7 ) )
V_95 = 3 ;
else
V_95 = 5 ;
if ( F_55 ( V_7 ) && V_1 -> V_86 == V_97 )
V_96 = V_98 ;
else
V_96 = V_99 ;
return V_100 |
V_101 |
( V_84 ? V_102 : 0 ) |
V_103 |
V_96 |
V_104 |
( V_93 << V_105 ) |
( V_95 << V_106 ) |
( V_94 << V_107 ) ;
}
static int
F_56 ( struct V_1 * V_1 ,
T_3 * V_108 , int V_93 ,
T_3 * V_109 , int V_110 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_85 = V_1 -> V_86 ;
T_2 V_111 = V_85 + 4 ;
T_2 V_94 ;
int V_49 , V_112 , V_113 ;
T_2 V_87 ;
int V_114 , clock = 0 ;
bool V_84 = F_57 ( V_7 ) ;
bool V_115 ;
V_115 = F_58 ( V_1 ) ;
F_59 ( & V_54 -> V_116 , 0 ) ;
F_36 ( V_1 ) ;
F_60 ( V_54 ) ;
for ( V_114 = 0 ; V_114 < 3 ; V_114 ++ ) {
V_87 = F_61 ( V_85 ) ;
if ( ( V_87 & V_100 ) == 0 )
break;
F_62 ( 1 ) ;
}
if ( V_114 == 3 ) {
F_11 ( 1 , L_5 ,
F_25 ( V_85 ) ) ;
V_112 = - V_117 ;
goto V_118;
}
if ( F_63 ( V_93 > 20 || V_110 > 20 ) ) {
V_112 = - V_119 ;
goto V_118;
}
while ( ( V_94 = V_1 -> V_120 ( V_1 , clock ++ ) ) ) {
T_4 V_121 = V_1 -> V_122 ( V_1 ,
V_84 ,
V_93 ,
V_94 ) ;
for ( V_114 = 0 ; V_114 < 5 ; V_114 ++ ) {
for ( V_49 = 0 ; V_49 < V_93 ; V_49 += 4 )
F_64 ( V_111 + V_49 ,
F_21 ( V_108 + V_49 , V_93 - V_49 ) ) ;
F_64 ( V_85 , V_121 ) ;
V_87 = F_38 ( V_1 , V_84 ) ;
F_64 ( V_85 ,
V_87 |
V_101 |
V_103 |
V_104 ) ;
if ( V_87 & ( V_103 |
V_104 ) )
continue;
if ( V_87 & V_101 )
break;
}
if ( V_87 & V_101 )
break;
}
if ( ( V_87 & V_101 ) == 0 ) {
F_43 ( L_6 , V_87 ) ;
V_112 = - V_117 ;
goto V_118;
}
if ( V_87 & V_104 ) {
F_43 ( L_7 , V_87 ) ;
V_112 = - V_123 ;
goto V_118;
}
if ( V_87 & V_103 ) {
F_37 ( L_8 , V_87 ) ;
V_112 = - V_124 ;
goto V_118;
}
V_113 = ( ( V_87 & V_125 ) >>
V_105 ) ;
if ( V_113 > V_110 )
V_113 = V_110 ;
for ( V_49 = 0 ; V_49 < V_113 ; V_49 += 4 )
F_22 ( F_25 ( V_111 + V_49 ) ,
V_109 + V_49 , V_113 - V_49 ) ;
V_112 = V_113 ;
V_118:
F_59 ( & V_54 -> V_116 , V_126 ) ;
F_65 ( V_54 ) ;
if ( V_115 )
F_66 ( V_1 , false ) ;
return V_112 ;
}
static T_5
F_67 ( struct V_127 * V_128 , struct V_129 * V_130 )
{
struct V_1 * V_1 = F_68 ( V_128 , struct V_1 , V_128 ) ;
T_3 V_131 [ 20 ] , V_132 [ 20 ] ;
T_6 V_133 , V_134 ;
int V_112 ;
V_131 [ 0 ] = V_130 -> V_135 << 4 ;
V_131 [ 1 ] = V_130 -> V_136 >> 8 ;
V_131 [ 2 ] = V_130 -> V_136 & 0xff ;
V_131 [ 3 ] = V_130 -> V_137 - 1 ;
switch ( V_130 -> V_135 & ~ V_138 ) {
case V_139 :
case V_140 :
V_133 = V_130 -> V_137 ? V_141 + V_130 -> V_137 : V_142 ;
V_134 = 1 ;
if ( F_63 ( V_133 > 20 ) )
return - V_119 ;
memcpy ( V_131 + V_141 , V_130 -> V_143 , V_130 -> V_137 ) ;
V_112 = F_56 ( V_1 , V_131 , V_133 , V_132 , V_134 ) ;
if ( V_112 > 0 ) {
V_130 -> V_144 = V_132 [ 0 ] >> 4 ;
V_112 = V_130 -> V_137 ;
}
break;
case V_145 :
case V_146 :
V_133 = V_130 -> V_137 ? V_141 : V_142 ;
V_134 = V_130 -> V_137 + 1 ;
if ( F_63 ( V_134 > 20 ) )
return - V_119 ;
V_112 = F_56 ( V_1 , V_131 , V_133 , V_132 , V_134 ) ;
if ( V_112 > 0 ) {
V_130 -> V_144 = V_132 [ 0 ] >> 4 ;
V_112 -- ;
memcpy ( V_130 -> V_143 , V_132 + 1 , V_112 ) ;
}
break;
default:
V_112 = - V_147 ;
break;
}
return V_112 ;
}
static void
F_69 ( struct V_1 * V_1 , struct V_32 * V_9 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_21 V_21 = V_3 -> V_21 ;
const char * V_148 = NULL ;
int V_112 ;
switch ( V_21 ) {
case V_22 :
V_1 -> V_86 = V_97 ;
V_148 = L_9 ;
break;
case V_75 :
V_1 -> V_86 = V_149 ;
V_148 = L_10 ;
break;
case V_77 :
V_1 -> V_86 = V_150 ;
V_148 = L_11 ;
break;
case V_151 :
V_1 -> V_86 = V_152 ;
V_148 = L_12 ;
break;
default:
F_70 () ;
}
if ( ! F_13 ( V_7 ) )
V_1 -> V_86 = V_1 -> V_153 + 0x10 ;
V_1 -> V_128 . V_148 = V_148 ;
V_1 -> V_128 . V_7 = V_7 -> V_7 ;
V_1 -> V_128 . V_154 = F_67 ;
F_37 ( L_13 , V_148 ,
V_9 -> V_4 . V_155 -> V_156 . V_148 ) ;
V_112 = F_71 ( & V_1 -> V_128 ) ;
if ( V_112 < 0 ) {
F_43 ( L_14 ,
V_148 , V_112 ) ;
return;
}
V_112 = F_72 ( & V_9 -> V_4 . V_155 -> V_156 ,
& V_1 -> V_128 . V_157 . V_7 . V_156 ,
V_1 -> V_128 . V_157 . V_7 . V_156 . V_148 ) ;
if ( V_112 < 0 ) {
F_43 ( L_15 , V_148 , V_112 ) ;
F_73 ( & V_1 -> V_128 ) ;
}
}
static void
F_74 ( struct V_32 * V_32 )
{
struct V_1 * V_1 = F_4 ( & V_32 -> V_4 ) ;
F_75 ( & V_32 -> V_4 . V_155 -> V_156 ,
V_1 -> V_128 . V_157 . V_7 . V_156 . V_148 ) ;
F_76 ( V_32 ) ;
}
static void
F_77 ( struct V_158 * V_159 ,
struct V_160 * V_161 , int V_162 )
{
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
const struct V_163 * V_164 = NULL ;
int V_49 , V_165 = 0 ;
if ( F_78 ( V_7 ) ) {
V_164 = V_166 ;
V_165 = F_79 ( V_166 ) ;
} else if ( F_8 ( V_7 ) ) {
} else if ( F_30 ( V_7 ) ) {
V_164 = V_167 ;
V_165 = F_79 ( V_167 ) ;
} else if ( F_24 ( V_7 ) ) {
V_164 = V_168 ;
V_165 = F_79 ( V_168 ) ;
}
if ( V_164 && V_165 ) {
for ( V_49 = 0 ; V_49 < V_165 ; V_49 ++ ) {
if ( V_162 == V_164 [ V_49 ] . V_162 ) {
V_161 -> V_169 = V_164 [ V_49 ] . V_169 ;
V_161 -> V_170 = true ;
break;
}
}
}
}
bool
F_80 ( struct V_158 * V_159 ,
struct V_160 * V_161 )
{
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_30 * V_171 = & V_161 -> V_171 ;
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_172 * V_172 = V_159 -> V_173 ;
struct V_32 * V_32 = V_1 -> V_13 ;
int V_174 , clock ;
int V_175 = 1 ;
int V_176 = F_12 ( V_1 ) ;
int V_177 = 0 ;
int V_178 = F_7 ( V_1 ) >> 3 ;
int V_26 , V_37 ;
static int V_179 [] = { V_14 , V_15 , V_16 } ;
int V_180 , V_181 ;
if ( F_30 ( V_7 ) && ! F_13 ( V_7 ) && V_21 != V_22 )
V_161 -> V_182 = true ;
V_161 -> V_183 = true ;
if ( F_1 ( V_1 ) && V_32 -> V_34 . V_33 ) {
F_81 ( V_32 -> V_34 . V_33 ,
V_171 ) ;
if ( ! F_30 ( V_7 ) )
F_82 ( V_172 , V_161 ,
V_32 -> V_34 . V_184 ) ;
else
F_83 ( V_172 , V_161 ,
V_32 -> V_34 . V_184 ) ;
}
if ( V_171 -> V_43 & V_44 )
return false ;
F_37 ( L_16
L_17 ,
V_176 , V_179 [ V_178 ] ,
V_171 -> V_185 ) ;
V_26 = V_161 -> V_186 ;
if ( F_1 ( V_1 ) ) {
if ( V_54 -> V_187 . V_188 && V_54 -> V_187 . V_188 < V_26 ) {
F_37 ( L_18 ,
V_54 -> V_187 . V_188 ) ;
V_26 = V_54 -> V_187 . V_188 ;
}
if ( F_55 ( V_7 ) ) {
V_175 = V_176 ;
F_37 ( L_19 ,
V_175 ) ;
} else if ( V_54 -> V_187 . V_189 ) {
V_175 = F_15 ( V_54 -> V_187 . V_189 ,
V_176 ) ;
F_37 ( L_20 ,
V_175 ) ;
}
if ( V_54 -> V_187 . V_190 ) {
V_177 = F_15 ( V_54 -> V_187 . V_190 >> 3 , V_178 ) ;
F_37 ( L_21 ,
V_179 [ V_177 ] ) ;
}
}
for (; V_26 >= 6 * 3 ; V_26 -= 2 * 3 ) {
V_37 = F_16 ( V_171 -> V_185 ,
V_26 ) ;
for ( V_174 = V_175 ; V_174 <= V_176 ; V_174 <<= 1 ) {
for ( clock = V_177 ; clock <= V_178 ; clock ++ ) {
V_181 = F_20 ( V_179 [ clock ] ) ;
V_180 = F_17 ( V_181 ,
V_174 ) ;
if ( V_37 <= V_180 ) {
goto V_191;
}
}
}
}
return false ;
V_191:
if ( V_1 -> V_192 ) {
if ( V_26 != 18 && F_84 ( V_171 ) > 1 )
V_1 -> V_193 = V_194 ;
else
V_1 -> V_193 = 0 ;
}
if ( V_1 -> V_193 )
V_161 -> V_195 = true ;
V_1 -> V_162 = V_179 [ clock ] ;
V_1 -> V_174 = V_174 ;
V_161 -> V_186 = V_26 ;
V_161 -> V_196 = F_20 ( V_1 -> V_162 ) ;
F_37 ( L_22 ,
V_1 -> V_162 , V_1 -> V_174 ,
V_161 -> V_196 , V_26 ) ;
F_37 ( L_23 ,
V_37 , V_180 ) ;
F_85 ( V_26 , V_174 ,
V_171 -> V_185 ,
V_161 -> V_196 ,
& V_161 -> V_197 ) ;
F_77 ( V_159 , V_161 , V_1 -> V_162 ) ;
return true ;
}
static void F_86 ( struct V_1 * V_1 )
{
struct V_2 * V_198 = F_2 ( V_1 ) ;
struct V_172 * V_69 = F_27 ( V_198 -> V_4 . V_4 . V_69 ) ;
struct V_6 * V_7 = V_69 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_199 ;
F_37 ( L_24 , V_69 -> V_200 . V_196 ) ;
V_199 = F_25 ( V_201 ) ;
V_199 &= ~ V_202 ;
if ( V_69 -> V_200 . V_196 == 162000 ) {
F_37 ( L_25 ) ;
V_199 |= V_203 ;
V_1 -> V_204 |= V_203 ;
} else {
V_199 |= V_205 ;
V_1 -> V_204 |= V_205 ;
}
F_64 ( V_201 , V_199 ) ;
F_87 ( V_201 ) ;
F_88 ( 500 ) ;
}
static void F_89 ( struct V_158 * V_159 )
{
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_172 * V_69 = F_27 ( V_159 -> V_4 . V_69 ) ;
struct V_30 * V_171 = & V_69 -> V_200 . V_171 ;
V_1 -> V_204 = F_25 ( V_1 -> V_153 ) & V_206 ;
V_1 -> V_204 |= V_207 | V_208 ;
V_1 -> V_204 |= F_90 ( V_1 -> V_174 ) ;
if ( V_1 -> V_209 ) {
F_91 ( L_26 ,
F_92 ( V_69 -> V_67 ) ) ;
V_1 -> V_204 |= V_210 ;
F_93 ( & V_159 -> V_4 , V_171 ) ;
}
if ( V_21 == V_22 && F_47 ( V_7 ) && ! F_24 ( V_7 ) ) {
if ( V_171 -> V_43 & V_211 )
V_1 -> V_204 |= V_212 ;
if ( V_171 -> V_43 & V_213 )
V_1 -> V_204 |= V_214 ;
V_1 -> V_204 |= V_215 ;
if ( F_94 ( V_1 -> V_11 ) )
V_1 -> V_204 |= V_216 ;
V_1 -> V_204 |= V_69 -> V_67 << 29 ;
} else if ( ! F_95 ( V_7 ) || V_21 == V_22 ) {
if ( ! F_30 ( V_7 ) && ! F_24 ( V_7 ) )
V_1 -> V_204 |= V_1 -> V_193 ;
if ( V_171 -> V_43 & V_211 )
V_1 -> V_204 |= V_212 ;
if ( V_171 -> V_43 & V_213 )
V_1 -> V_204 |= V_214 ;
V_1 -> V_204 |= V_217 ;
if ( F_94 ( V_1 -> V_11 ) )
V_1 -> V_204 |= V_216 ;
if ( V_69 -> V_67 == 1 )
V_1 -> V_204 |= V_218 ;
} else {
V_1 -> V_204 |= V_215 ;
}
if ( V_21 == V_22 && ! F_24 ( V_7 ) )
F_86 ( V_1 ) ;
}
static void F_96 ( struct V_1 * V_1 ,
T_4 V_219 ,
T_4 V_220 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_221 , V_222 ;
V_221 = F_32 ( V_1 ) ;
V_222 = F_29 ( V_1 ) ;
F_37 ( L_27 ,
V_219 , V_220 ,
F_25 ( V_221 ) ,
F_25 ( V_222 ) ) ;
if ( F_97 ( ( F_25 ( V_221 ) & V_219 ) == V_220 , 5000 , 10 ) ) {
F_43 ( L_28 ,
F_25 ( V_221 ) ,
F_25 ( V_222 ) ) ;
}
F_37 ( L_29 ) ;
}
static void F_98 ( struct V_1 * V_1 )
{
F_37 ( L_30 ) ;
F_96 ( V_1 , V_223 , V_224 ) ;
}
static void F_99 ( struct V_1 * V_1 )
{
F_37 ( L_31 ) ;
F_96 ( V_1 , V_225 , V_226 ) ;
}
static void F_100 ( struct V_1 * V_1 )
{
F_37 ( L_32 ) ;
F_101 ( V_1 -> V_227 ,
V_1 -> V_228 ) ;
F_96 ( V_1 , V_229 , V_230 ) ;
}
static void F_102 ( struct V_1 * V_1 )
{
F_101 ( V_1 -> V_231 ,
V_1 -> V_232 ) ;
}
static void F_103 ( struct V_1 * V_1 )
{
F_101 ( V_1 -> V_233 ,
V_1 -> V_234 ) ;
}
static T_4 F_104 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_235 ;
V_235 = F_25 ( F_29 ( V_1 ) ) ;
V_235 &= ~ V_236 ;
V_235 |= V_237 ;
return V_235 ;
}
static bool F_58 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_238 ;
T_4 V_221 , V_222 ;
bool V_239 = ! V_1 -> V_240 ;
if ( ! F_1 ( V_1 ) )
return false ;
V_1 -> V_240 = true ;
if ( F_35 ( V_1 ) )
return V_239 ;
F_105 ( V_54 ) ;
F_37 ( L_33 ) ;
if ( ! F_34 ( V_1 ) )
F_100 ( V_1 ) ;
V_238 = F_104 ( V_1 ) ;
V_238 |= V_83 ;
V_221 = F_32 ( V_1 ) ;
V_222 = F_29 ( V_1 ) ;
F_64 ( V_222 , V_238 ) ;
F_87 ( V_222 ) ;
F_37 ( L_34 ,
F_25 ( V_221 ) , F_25 ( V_222 ) ) ;
if ( ! F_34 ( V_1 ) ) {
F_37 ( L_35 ) ;
F_62 ( V_1 -> V_241 ) ;
}
return V_239 ;
}
void F_106 ( struct V_1 * V_1 )
{
if ( F_1 ( V_1 ) ) {
bool V_115 = F_58 ( V_1 ) ;
F_11 ( ! V_115 , L_36 ) ;
}
}
static void F_107 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_238 ;
T_4 V_221 , V_222 ;
F_63 ( ! F_108 ( & V_7 -> V_242 . V_243 ) ) ;
if ( ! V_1 -> V_240 && F_35 ( V_1 ) ) {
F_37 ( L_37 ) ;
V_238 = F_104 ( V_1 ) ;
V_238 &= ~ V_83 ;
V_222 = F_29 ( V_1 ) ;
V_221 = F_32 ( V_1 ) ;
F_64 ( V_222 , V_238 ) ;
F_87 ( V_222 ) ;
F_37 ( L_34 ,
F_25 ( V_221 ) , F_25 ( V_222 ) ) ;
if ( ( V_238 & V_244 ) == 0 )
V_1 -> V_227 = V_245 ;
F_109 ( V_54 ) ;
}
}
static void F_110 ( struct V_246 * V_247 )
{
struct V_1 * V_1 = F_68 ( F_111 ( V_247 ) ,
struct V_1 , V_248 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
F_112 ( & V_7 -> V_242 . V_243 ) ;
F_107 ( V_1 ) ;
F_113 ( & V_7 -> V_242 . V_243 ) ;
}
static void F_66 ( struct V_1 * V_1 , bool V_249 )
{
if ( ! F_1 ( V_1 ) )
return;
F_11 ( ! V_1 -> V_240 , L_38 ) ;
V_1 -> V_240 = false ;
if ( V_249 ) {
F_107 ( V_1 ) ;
} else {
F_114 ( & V_1 -> V_248 ,
F_115 ( V_1 -> V_228 * 5 ) ) ;
}
}
void F_116 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_238 ;
T_4 V_222 ;
if ( ! F_1 ( V_1 ) )
return;
F_37 ( L_39 ) ;
if ( F_34 ( V_1 ) ) {
F_37 ( L_40 ) ;
return;
}
F_100 ( V_1 ) ;
V_222 = F_29 ( V_1 ) ;
V_238 = F_104 ( V_1 ) ;
if ( F_117 ( V_7 ) ) {
V_238 &= ~ V_250 ;
F_64 ( V_222 , V_238 ) ;
F_87 ( V_222 ) ;
}
V_238 |= V_244 ;
if ( ! F_117 ( V_7 ) )
V_238 |= V_250 ;
F_64 ( V_222 , V_238 ) ;
F_87 ( V_222 ) ;
F_98 ( V_1 ) ;
V_1 -> V_231 = V_245 ;
if ( F_117 ( V_7 ) ) {
V_238 |= V_250 ;
F_64 ( V_222 , V_238 ) ;
F_87 ( V_222 ) ;
}
}
void F_118 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_238 ;
T_4 V_222 ;
if ( ! F_1 ( V_1 ) )
return;
F_37 ( L_41 ) ;
F_103 ( V_1 ) ;
F_11 ( ! V_1 -> V_240 , L_42 ) ;
V_238 = F_104 ( V_1 ) ;
V_238 &= ~ ( V_244 | V_250 | V_83 |
V_251 ) ;
V_222 = F_29 ( V_1 ) ;
V_1 -> V_240 = false ;
F_64 ( V_222 , V_238 ) ;
F_87 ( V_222 ) ;
V_1 -> V_227 = V_245 ;
F_99 ( V_1 ) ;
F_109 ( V_54 ) ;
}
void F_119 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_238 ;
T_4 V_222 ;
if ( ! F_1 ( V_1 ) )
return;
F_37 ( L_43 ) ;
F_102 ( V_1 ) ;
V_238 = F_104 ( V_1 ) ;
V_238 |= V_251 ;
V_222 = F_29 ( V_1 ) ;
F_64 ( V_222 , V_238 ) ;
F_87 ( V_222 ) ;
F_120 ( V_1 -> V_13 ) ;
}
void F_121 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_238 ;
T_4 V_222 ;
if ( ! F_1 ( V_1 ) )
return;
F_122 ( V_1 -> V_13 ) ;
F_37 ( L_43 ) ;
V_238 = F_104 ( V_1 ) ;
V_238 &= ~ V_251 ;
V_222 = F_29 ( V_1 ) ;
F_64 ( V_222 , V_238 ) ;
F_87 ( V_222 ) ;
V_1 -> V_233 = V_245 ;
}
static void F_123 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_68 * V_69 = V_3 -> V_4 . V_4 . V_69 ;
struct V_6 * V_7 = V_69 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_199 ;
F_124 ( V_54 ,
F_27 ( V_69 ) -> V_67 ) ;
F_37 ( L_43 ) ;
V_199 = F_25 ( V_201 ) ;
F_11 ( V_199 & V_252 , L_44 ) ;
F_11 ( V_199 & V_253 , L_45 ) ;
V_1 -> V_204 &= ~ ( V_253 | V_210 ) ;
V_1 -> V_204 |= V_252 ;
F_64 ( V_201 , V_1 -> V_204 ) ;
F_87 ( V_201 ) ;
F_88 ( 200 ) ;
}
static void F_125 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_68 * V_69 = V_3 -> V_4 . V_4 . V_69 ;
struct V_6 * V_7 = V_69 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_199 ;
F_124 ( V_54 ,
F_27 ( V_69 ) -> V_67 ) ;
V_199 = F_25 ( V_201 ) ;
F_11 ( ( V_199 & V_252 ) == 0 ,
L_46 ) ;
F_11 ( V_199 & V_253 , L_45 ) ;
V_199 &= ~ V_252 ;
F_64 ( V_201 , V_199 ) ;
F_87 ( V_201 ) ;
F_88 ( 200 ) ;
}
void F_126 ( struct V_1 * V_1 , int V_31 )
{
int V_112 , V_49 ;
if ( V_1 -> V_11 [ V_18 ] < 0x11 )
return;
if ( V_31 != V_254 ) {
V_112 = F_127 ( & V_1 -> V_128 , V_255 ,
V_256 ) ;
if ( V_112 != 1 )
F_91 ( L_47 ) ;
} else {
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
V_112 = F_127 ( & V_1 -> V_128 , V_255 ,
V_257 ) ;
if ( V_112 == 1 )
break;
F_62 ( 1 ) ;
}
}
}
static bool F_128 ( struct V_158 * V_159 ,
enum V_67 * V_67 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_258 V_259 ;
T_4 V_260 ;
V_259 = F_129 ( V_159 ) ;
if ( ! F_130 ( V_54 , V_259 ) )
return false ;
V_260 = F_25 ( V_1 -> V_153 ) ;
if ( ! ( V_260 & V_253 ) )
return false ;
if ( V_21 == V_22 && F_47 ( V_7 ) && ! F_24 ( V_7 ) ) {
* V_67 = F_131 ( V_260 ) ;
} else if ( ! F_95 ( V_7 ) || V_21 == V_22 ) {
* V_67 = F_132 ( V_260 ) ;
} else {
T_4 V_261 ;
T_4 V_262 ;
int V_49 ;
switch ( V_1 -> V_153 ) {
case V_263 :
V_261 = V_264 ;
break;
case V_265 :
V_261 = V_266 ;
break;
case V_267 :
V_261 = V_268 ;
break;
default:
return true ;
}
F_133 (i) {
V_262 = F_25 ( F_134 ( V_49 ) ) ;
if ( ( V_262 & V_269 ) == V_261 ) {
* V_67 = V_49 ;
return true ;
}
}
F_37 ( L_48 ,
V_1 -> V_153 ) ;
}
return true ;
}
static void F_135 ( struct V_158 * V_159 ,
struct V_160 * V_161 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
T_4 V_260 , V_43 = 0 ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_172 * V_69 = F_27 ( V_159 -> V_4 . V_69 ) ;
int V_270 ;
if ( ( V_21 == V_22 ) || ! F_95 ( V_7 ) ) {
V_260 = F_25 ( V_1 -> V_153 ) ;
if ( V_260 & V_212 )
V_43 |= V_211 ;
else
V_43 |= V_271 ;
if ( V_260 & V_214 )
V_43 |= V_213 ;
else
V_43 |= V_272 ;
} else {
V_260 = F_25 ( F_134 ( V_69 -> V_67 ) ) ;
if ( V_260 & V_273 )
V_43 |= V_211 ;
else
V_43 |= V_271 ;
if ( V_260 & V_274 )
V_43 |= V_213 ;
else
V_43 |= V_272 ;
}
V_161 -> V_171 . V_43 |= V_43 ;
V_161 -> V_183 = true ;
F_136 ( V_69 , V_161 ) ;
if ( V_21 == V_22 ) {
if ( ( F_25 ( V_201 ) & V_202 ) == V_203 )
V_161 -> V_196 = 162000 ;
else
V_161 -> V_196 = 270000 ;
}
V_270 = F_137 ( V_161 -> V_196 ,
& V_161 -> V_197 ) ;
if ( F_30 ( V_54 -> V_7 ) && V_21 != V_22 )
F_138 ( V_161 , V_270 ) ;
V_161 -> V_171 . V_185 = V_270 ;
if ( F_1 ( V_1 ) && V_54 -> V_187 . V_188 &&
V_161 -> V_186 > V_54 -> V_187 . V_188 ) {
F_37 ( L_49 ,
V_161 -> V_186 , V_54 -> V_187 . V_188 ) ;
V_54 -> V_187 . V_188 = V_161 -> V_186 ;
}
}
static bool F_139 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
return V_54 -> V_275 . V_276 ;
}
static bool F_140 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
if ( ! F_141 ( V_7 ) )
return false ;
return F_25 ( F_142 ( V_7 ) ) & V_277 ;
}
static void F_143 ( struct V_1 * V_1 ,
struct V_278 * V_279 )
{
struct V_2 * V_198 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_198 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_172 * V_69 = F_27 ( V_198 -> V_4 . V_4 . V_69 ) ;
T_4 V_280 = F_144 ( V_69 -> V_200 . V_281 ) ;
T_4 V_282 = F_145 ( V_69 -> V_200 . V_281 ) ;
T_2 * V_283 = ( T_2 * ) V_279 ;
unsigned int V_49 ;
F_64 ( V_280 , 0 ) ;
F_87 ( V_280 ) ;
for ( V_49 = 0 ; V_49 < V_284 ; V_49 += 4 ) {
if ( V_49 < sizeof( struct V_278 ) )
F_64 ( V_282 + V_49 , * V_283 ++ ) ;
else
F_64 ( V_282 + V_49 , 0 ) ;
}
F_64 ( V_280 , V_285 ) ;
F_87 ( V_280 ) ;
}
static void F_146 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_278 V_286 ;
if ( V_1 -> V_287 )
return;
memset ( & V_286 , 0 , sizeof( V_286 ) ) ;
V_286 . V_288 . V_289 = 0 ;
V_286 . V_288 . V_290 = 0x7 ;
V_286 . V_288 . V_291 = 0x2 ;
V_286 . V_288 . V_292 = 0x8 ;
F_143 ( V_1 , & V_286 ) ;
F_64 ( F_147 ( V_7 ) , V_293 |
V_294 | V_295 ) ;
V_1 -> V_287 = true ;
}
static void F_148 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_94 ;
int V_95 = 0x3 ;
int V_296 = 5 ;
V_94 = V_1 -> V_120 ( V_1 , 0 ) ;
if ( V_1 -> V_297 [ 1 ] & V_298 )
F_127 ( & V_1 -> V_128 , V_299 ,
V_300 & ~ V_301 ) ;
else
F_127 ( & V_1 -> V_128 , V_299 ,
V_300 | V_301 ) ;
F_64 ( F_149 ( V_7 ) , V_302 ) ;
F_64 ( F_150 ( V_7 ) , V_303 ) ;
F_64 ( F_151 ( V_7 ) ,
V_99 |
( V_296 << V_105 ) |
( V_95 << V_106 ) |
( V_94 << V_107 ) ) ;
}
static void F_152 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_304 = 0x1f ;
T_2 V_305 = 1 ;
T_2 V_306 = 0x0 ;
const T_2 V_307 = V_308 ;
if ( V_1 -> V_297 [ 1 ] & V_298 ) {
V_306 |= V_309 ;
V_306 |= V_310 ;
V_306 |= V_311 ;
V_306 |= V_312 ;
} else
V_306 |= V_313 ;
F_64 ( F_142 ( V_7 ) , V_306 |
( F_55 ( V_7 ) ? 0 : V_307 ) |
V_304 << V_314 |
V_305 << V_315 |
V_277 ) ;
}
static bool F_153 ( struct V_1 * V_1 )
{
struct V_2 * V_198 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_198 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_68 * V_69 = V_198 -> V_4 . V_4 . V_69 ;
struct V_172 * V_172 = F_27 ( V_69 ) ;
struct V_316 * V_317 = F_154 ( V_69 -> V_318 -> V_319 ) -> V_317 ;
struct V_158 * V_158 = & F_2 ( V_1 ) -> V_4 ;
V_54 -> V_275 . V_320 = false ;
if ( ! F_141 ( V_7 ) ) {
F_37 ( L_50 ) ;
return false ;
}
if ( ( V_158 -> type != V_5 ) ||
( V_198 -> V_21 != V_22 ) ) {
F_37 ( L_51 ) ;
return false ;
}
if ( ! V_321 . V_322 ) {
F_37 ( L_52 ) ;
return false ;
}
V_69 = V_198 -> V_4 . V_4 . V_69 ;
if ( V_69 == NULL ) {
F_37 ( L_53 ) ;
return false ;
}
V_172 = F_27 ( V_69 ) ;
if ( ! F_155 ( V_69 ) ) {
F_37 ( L_53 ) ;
return false ;
}
V_317 = F_154 ( V_69 -> V_318 -> V_319 ) -> V_317 ;
if ( V_317 -> V_323 != V_324 ||
V_317 -> V_325 == V_326 ) {
F_37 ( L_54 ) ;
return false ;
}
if ( F_25 ( F_156 ( V_172 -> V_67 ) ) & V_327 ) {
F_37 ( L_55 ) ;
return false ;
}
if ( F_25 ( F_157 ( V_172 -> V_200 . V_281 ) ) &
V_328 ) {
F_37 ( L_56 ) ;
return false ;
}
if ( V_172 -> V_200 . V_171 . V_43 & V_329 ) {
F_37 ( L_57 ) ;
return false ;
}
V_54 -> V_275 . V_320 = true ;
return true ;
}
static void F_158 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( ! F_153 ( V_1 ) ||
F_140 ( V_7 ) )
return;
F_146 ( V_1 ) ;
F_148 ( V_1 ) ;
F_152 ( V_1 ) ;
}
void F_159 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_153 ( V_1 ) &&
! F_140 ( V_7 ) )
F_158 ( V_1 ) ;
}
void F_160 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( ! F_140 ( V_7 ) )
return;
F_64 ( F_142 ( V_7 ) ,
F_25 ( F_142 ( V_7 ) ) & ~ V_277 ) ;
if ( F_97 ( ( F_25 ( F_161 ( V_7 ) ) &
V_330 ) == 0 , 2000 , 10 ) )
F_43 ( L_58 ) ;
}
void F_162 ( struct V_6 * V_7 )
{
struct V_158 * V_159 ;
struct V_1 * V_1 = NULL ;
F_163 (encoder, &dev->mode_config.encoder_list, base.head)
if ( V_159 -> type == V_5 ) {
V_1 = F_5 ( & V_159 -> V_4 ) ;
if ( ! F_139 ( V_7 ) )
return;
if ( ! F_153 ( V_1 ) )
F_160 ( V_1 ) ;
else
if ( ! F_140 ( V_7 ) )
F_158 ( V_1 ) ;
}
}
static void F_164 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
F_106 ( V_1 ) ;
F_121 ( V_1 ) ;
F_126 ( V_1 , V_331 ) ;
F_118 ( V_1 ) ;
if ( ! ( V_21 == V_22 || F_24 ( V_7 ) ) )
F_165 ( V_1 ) ;
}
static void F_166 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
if ( V_21 == V_22 || F_24 ( V_7 ) ) {
F_165 ( V_1 ) ;
if ( ! F_24 ( V_7 ) )
F_125 ( V_1 ) ;
}
}
static void F_167 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_332 = F_25 ( V_1 -> V_153 ) ;
if ( F_63 ( V_332 & V_253 ) )
return;
F_106 ( V_1 ) ;
F_126 ( V_1 , V_254 ) ;
F_168 ( V_1 ) ;
F_116 ( V_1 ) ;
F_66 ( V_1 , true ) ;
F_169 ( V_1 ) ;
F_170 ( V_1 ) ;
}
static void F_171 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
F_167 ( V_159 ) ;
F_119 ( V_1 ) ;
}
static void F_172 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
F_119 ( V_1 ) ;
}
static void F_173 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
struct V_2 * V_333 = F_2 ( V_1 ) ;
if ( V_333 -> V_21 == V_22 )
F_123 ( V_1 ) ;
}
static void F_174 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
struct V_2 * V_333 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_172 * V_172 = F_27 ( V_159 -> V_4 . V_69 ) ;
enum V_334 V_21 = F_175 ( V_333 ) ;
int V_67 = V_172 -> V_67 ;
struct V_335 V_336 ;
T_4 V_306 ;
F_112 ( & V_54 -> V_337 ) ;
V_306 = F_176 ( V_54 , V_67 , F_177 ( V_21 ) ) ;
V_306 = 0 ;
if ( V_67 )
V_306 |= ( 1 << 21 ) ;
else
V_306 &= ~ ( 1 << 21 ) ;
V_306 |= 0x001000c4 ;
F_178 ( V_54 , V_67 , F_179 ( V_21 ) , V_306 ) ;
F_178 ( V_54 , V_67 , F_180 ( V_21 ) , 0x00760018 ) ;
F_178 ( V_54 , V_67 , F_181 ( V_21 ) , 0x00400888 ) ;
F_113 ( & V_54 -> V_337 ) ;
if ( F_1 ( V_1 ) ) {
F_182 ( V_7 , V_1 , & V_336 ) ;
F_183 ( V_7 , V_1 ,
& V_336 ) ;
}
F_167 ( V_159 ) ;
F_184 ( V_54 , V_333 ) ;
}
static void F_185 ( struct V_158 * V_159 )
{
struct V_2 * V_333 = F_186 ( & V_159 -> V_4 ) ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_172 * V_172 =
F_27 ( V_159 -> V_4 . V_69 ) ;
enum V_334 V_21 = F_175 ( V_333 ) ;
int V_67 = V_172 -> V_67 ;
F_112 ( & V_54 -> V_337 ) ;
F_178 ( V_54 , V_67 , F_187 ( V_21 ) ,
V_338 |
V_339 ) ;
F_178 ( V_54 , V_67 , F_188 ( V_21 ) ,
V_340 |
V_341 |
( 1 << V_342 ) |
V_343 ) ;
F_178 ( V_54 , V_67 , F_189 ( V_21 ) , 0x00750f00 ) ;
F_178 ( V_54 , V_67 , F_190 ( V_21 ) , 0x00001500 ) ;
F_178 ( V_54 , V_67 , F_191 ( V_21 ) , 0x40400000 ) ;
F_113 ( & V_54 -> V_337 ) ;
}
static T_5
F_192 ( struct V_127 * V_128 , unsigned int V_344 ,
void * V_143 , T_6 V_137 )
{
T_5 V_112 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
V_112 = F_193 ( V_128 , V_344 , V_143 , V_137 ) ;
if ( V_112 == V_137 )
return V_112 ;
F_62 ( 1 ) ;
}
return V_112 ;
}
static bool
F_194 ( struct V_1 * V_1 , T_3 V_345 [ V_346 ] )
{
return F_192 ( & V_1 -> V_128 ,
V_347 ,
V_345 ,
V_346 ) == V_346 ;
}
static T_3
F_195 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
if ( F_24 ( V_7 ) || F_55 ( V_7 ) )
return V_348 ;
else if ( F_47 ( V_7 ) && V_21 == V_22 )
return V_349 ;
else if ( F_95 ( V_7 ) && V_21 != V_22 )
return V_348 ;
else
return V_349 ;
}
static T_3
F_196 ( struct V_1 * V_1 , T_3 V_350 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
if ( F_55 ( V_7 ) ) {
switch ( V_350 & V_351 ) {
case V_352 :
case V_353 :
return V_354 ;
case V_349 :
return V_355 ;
case V_348 :
default:
return V_356 ;
}
} else if ( F_8 ( V_7 ) ) {
switch ( V_350 & V_351 ) {
case V_352 :
return V_357 ;
case V_353 :
return V_354 ;
case V_349 :
return V_355 ;
case V_348 :
default:
return V_356 ;
}
} else if ( F_24 ( V_7 ) ) {
switch ( V_350 & V_351 ) {
case V_352 :
return V_357 ;
case V_353 :
return V_354 ;
case V_349 :
return V_355 ;
case V_348 :
default:
return V_356 ;
}
} else if ( F_47 ( V_7 ) && V_21 == V_22 ) {
switch ( V_350 & V_351 ) {
case V_352 :
return V_354 ;
case V_353 :
case V_349 :
return V_355 ;
default:
return V_356 ;
}
} else {
switch ( V_350 & V_351 ) {
case V_352 :
return V_354 ;
case V_353 :
return V_354 ;
case V_349 :
return V_355 ;
case V_348 :
default:
return V_356 ;
}
}
}
static T_2 F_197 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_333 = F_2 ( V_1 ) ;
struct V_172 * V_172 =
F_27 ( V_333 -> V_4 . V_4 . V_69 ) ;
unsigned long V_358 , V_359 ,
V_360 ;
T_3 V_361 = V_1 -> V_361 [ 0 ] ;
enum V_334 V_21 = F_175 ( V_333 ) ;
int V_67 = V_172 -> V_67 ;
switch ( V_361 & V_362 ) {
case V_356 :
V_359 = 0x0004000 ;
switch ( V_361 & V_351 ) {
case V_352 :
V_358 = 0x2B405555 ;
V_360 = 0x552AB83A ;
break;
case V_353 :
V_358 = 0x2B404040 ;
V_360 = 0x5548B83A ;
break;
case V_349 :
V_358 = 0x2B245555 ;
V_360 = 0x5560B83A ;
break;
case V_348 :
V_358 = 0x2B405555 ;
V_360 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_355 :
V_359 = 0x0002000 ;
switch ( V_361 & V_351 ) {
case V_352 :
V_358 = 0x2B404040 ;
V_360 = 0x5552B83A ;
break;
case V_353 :
V_358 = 0x2B404848 ;
V_360 = 0x5580B83A ;
break;
case V_349 :
V_358 = 0x2B404040 ;
V_360 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_354 :
V_359 = 0x0000000 ;
switch ( V_361 & V_351 ) {
case V_352 :
V_358 = 0x2B305555 ;
V_360 = 0x5570B83A ;
break;
case V_353 :
V_358 = 0x2B2B4040 ;
V_360 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_357 :
V_359 = 0x0006000 ;
switch ( V_361 & V_351 ) {
case V_352 :
V_358 = 0x1B405555 ;
V_360 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_112 ( & V_54 -> V_337 ) ;
F_178 ( V_54 , V_67 , F_198 ( V_21 ) , 0x00000000 ) ;
F_178 ( V_54 , V_67 , F_199 ( V_21 ) , V_358 ) ;
F_178 ( V_54 , V_67 , F_200 ( V_21 ) ,
V_360 ) ;
F_178 ( V_54 , V_67 , F_201 ( V_21 ) , 0x0C782040 ) ;
F_178 ( V_54 , V_67 , F_202 ( V_21 ) , 0x00030000 ) ;
F_178 ( V_54 , V_67 , F_203 ( V_21 ) , V_359 ) ;
F_178 ( V_54 , V_67 , F_198 ( V_21 ) , 0x80000000 ) ;
F_113 ( & V_54 -> V_337 ) ;
return 0 ;
}
static void
F_204 ( struct V_1 * V_1 ,
const T_3 V_345 [ V_346 ] )
{
T_3 V_50 = 0 ;
T_3 V_363 = 0 ;
int V_364 ;
T_3 V_365 ;
T_3 V_366 ;
for ( V_364 = 0 ; V_364 < V_1 -> V_174 ; V_364 ++ ) {
T_3 V_367 = F_205 ( V_345 , V_364 ) ;
T_3 V_368 = F_206 ( V_345 , V_364 ) ;
if ( V_367 > V_50 )
V_50 = V_367 ;
if ( V_368 > V_363 )
V_363 = V_368 ;
}
V_365 = F_195 ( V_1 ) ;
if ( V_50 >= V_365 )
V_50 = V_365 | V_369 ;
V_366 = F_196 ( V_1 , V_50 ) ;
if ( V_363 >= V_366 )
V_363 = V_366 | V_370 ;
for ( V_364 = 0 ; V_364 < 4 ; V_364 ++ )
V_1 -> V_361 [ V_364 ] = V_50 | V_363 ;
}
static T_2
F_207 ( T_3 V_361 )
{
T_2 V_371 = 0 ;
switch ( V_361 & V_351 ) {
case V_352 :
default:
V_371 |= V_207 ;
break;
case V_353 :
V_371 |= V_372 ;
break;
case V_349 :
V_371 |= V_373 ;
break;
case V_348 :
V_371 |= V_374 ;
break;
}
switch ( V_361 & V_362 ) {
case V_356 :
default:
V_371 |= V_208 ;
break;
case V_355 :
V_371 |= V_375 ;
break;
case V_354 :
V_371 |= V_376 ;
break;
case V_357 :
V_371 |= V_377 ;
break;
}
return V_371 ;
}
static T_2
F_208 ( T_3 V_361 )
{
int V_371 = V_361 & ( V_351 |
V_362 ) ;
switch ( V_371 ) {
case V_352 | V_356 :
case V_353 | V_356 :
return V_378 ;
case V_352 | V_355 :
return V_379 ;
case V_352 | V_354 :
case V_353 | V_354 :
return V_380 ;
case V_353 | V_355 :
case V_349 | V_355 :
return V_381 ;
case V_349 | V_356 :
case V_348 | V_356 :
return V_382 ;
default:
F_37 ( L_59
L_60 , V_371 ) ;
return V_378 ;
}
}
static T_2
F_209 ( T_3 V_361 )
{
int V_371 = V_361 & ( V_351 |
V_362 ) ;
switch ( V_371 ) {
case V_352 | V_356 :
return V_383 ;
case V_352 | V_355 :
return V_384 ;
case V_352 | V_354 :
return V_385 ;
case V_353 | V_356 :
return V_386 ;
case V_353 | V_355 :
return V_387 ;
case V_349 | V_356 :
return V_388 ;
case V_349 | V_355 :
return V_389 ;
default:
F_37 ( L_59
L_60 , V_371 ) ;
return V_390 ;
}
}
static T_2
F_210 ( T_3 V_361 )
{
int V_371 = V_361 & ( V_351 |
V_362 ) ;
switch ( V_371 ) {
case V_352 | V_356 :
return V_391 ;
case V_352 | V_355 :
return V_392 ;
case V_352 | V_354 :
return V_393 ;
case V_352 | V_357 :
return V_394 ;
case V_353 | V_356 :
return V_395 ;
case V_353 | V_355 :
return V_396 ;
case V_353 | V_354 :
return V_397 ;
case V_349 | V_356 :
return V_398 ;
case V_349 | V_355 :
return V_399 ;
default:
F_37 ( L_59
L_60 , V_371 ) ;
return V_391 ;
}
}
static T_2
F_211 ( T_3 V_361 )
{
int V_371 = V_361 & ( V_351 |
V_362 ) ;
switch ( V_371 ) {
case V_352 | V_356 :
return V_400 ;
case V_352 | V_355 :
return V_401 ;
case V_352 | V_354 :
return V_402 ;
case V_353 | V_356 :
return V_403 ;
case V_353 | V_355 :
return V_404 ;
case V_353 | V_354 :
return V_405 ;
case V_349 | V_356 :
return V_406 ;
case V_349 | V_355 :
return V_407 ;
case V_348 | V_356 :
return V_408 ;
default:
F_37 ( L_59
L_60 , V_371 ) ;
return V_400 ;
}
}
static void
F_212 ( struct V_1 * V_1 , T_2 * V_204 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_21 V_21 = V_3 -> V_21 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_371 , V_219 ;
T_3 V_361 = V_1 -> V_361 [ 0 ] ;
if ( F_55 ( V_7 ) ) {
V_371 = F_211 ( V_361 ) ;
V_219 = V_409 ;
} else if ( F_8 ( V_7 ) ) {
V_371 = F_210 ( V_361 ) ;
V_219 = V_409 ;
} else if ( F_24 ( V_7 ) ) {
V_371 = F_197 ( V_1 ) ;
V_219 = 0 ;
} else if ( F_47 ( V_7 ) && V_21 == V_22 ) {
V_371 = F_209 ( V_361 ) ;
V_219 = V_410 ;
} else if ( F_46 ( V_7 ) && V_21 == V_22 ) {
V_371 = F_208 ( V_361 ) ;
V_219 = V_411 ;
} else {
V_371 = F_207 ( V_361 ) ;
V_219 = V_412 | V_413 ;
}
F_37 ( L_61 , V_371 ) ;
* V_204 = ( * V_204 & ~ V_219 ) | V_371 ;
}
static bool
F_213 ( struct V_1 * V_1 ,
T_2 * V_204 ,
T_3 V_414 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
T_3 V_415 [ sizeof( V_1 -> V_361 ) + 1 ] ;
int V_112 , V_416 ;
if ( F_13 ( V_7 ) ) {
T_2 V_417 = F_25 ( F_214 ( V_21 ) ) ;
if ( V_414 & V_418 )
V_417 |= V_419 ;
else
V_417 &= ~ V_419 ;
V_417 &= ~ V_420 ;
switch ( V_414 & V_421 ) {
case V_422 :
V_417 |= V_423 ;
break;
case V_424 :
V_417 |= V_425 ;
break;
case V_426 :
V_417 |= V_427 ;
break;
case V_428 :
V_417 |= V_429 ;
break;
}
F_64 ( F_214 ( V_21 ) , V_417 ) ;
} else if ( F_95 ( V_7 ) && ( F_47 ( V_7 ) || V_21 != V_22 ) ) {
* V_204 &= ~ V_430 ;
switch ( V_414 & V_421 ) {
case V_422 :
* V_204 |= V_215 ;
break;
case V_424 :
* V_204 |= V_431 ;
break;
case V_426 :
* V_204 |= V_432 ;
break;
case V_428 :
F_43 ( L_62 ) ;
* V_204 |= V_432 ;
break;
}
} else {
* V_204 &= ~ V_433 ;
switch ( V_414 & V_421 ) {
case V_422 :
* V_204 |= V_217 ;
break;
case V_424 :
* V_204 |= V_434 ;
break;
case V_426 :
* V_204 |= V_435 ;
break;
case V_428 :
F_43 ( L_62 ) ;
* V_204 |= V_435 ;
break;
}
}
F_64 ( V_1 -> V_153 , * V_204 ) ;
F_87 ( V_1 -> V_153 ) ;
V_415 [ 0 ] = V_414 ;
if ( ( V_414 & V_421 ) ==
V_422 ) {
V_416 = 1 ;
} else {
memcpy ( V_415 + 1 , V_1 -> V_361 , V_1 -> V_174 ) ;
V_416 = V_1 -> V_174 + 1 ;
}
V_112 = F_215 ( & V_1 -> V_128 , V_436 ,
V_415 , V_416 ) ;
return V_112 == V_416 ;
}
static bool
F_216 ( struct V_1 * V_1 , T_2 * V_204 ,
T_3 V_414 )
{
memset ( V_1 -> V_361 , 0 , sizeof( V_1 -> V_361 ) ) ;
F_212 ( V_1 , V_204 ) ;
return F_213 ( V_1 , V_204 , V_414 ) ;
}
static bool
F_217 ( struct V_1 * V_1 , T_2 * V_204 ,
const T_3 V_345 [ V_346 ] )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
int V_112 ;
F_204 ( V_1 , V_345 ) ;
F_212 ( V_1 , V_204 ) ;
F_64 ( V_1 -> V_153 , * V_204 ) ;
F_87 ( V_1 -> V_153 ) ;
V_112 = F_215 ( & V_1 -> V_128 , V_437 ,
V_1 -> V_361 , V_1 -> V_174 ) ;
return V_112 == V_1 -> V_174 ;
}
static void F_218 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
T_2 V_306 ;
if ( ! F_13 ( V_7 ) )
return;
V_306 = F_25 ( F_214 ( V_21 ) ) ;
V_306 &= ~ V_420 ;
V_306 |= V_438 ;
F_64 ( F_214 ( V_21 ) , V_306 ) ;
if ( V_21 == V_22 )
return;
if ( F_219 ( ( F_25 ( F_220 ( V_21 ) ) & V_439 ) ,
1 ) )
F_43 ( L_63 ) ;
}
void
F_168 ( struct V_1 * V_1 )
{
struct V_440 * V_159 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_159 -> V_7 ;
int V_49 ;
T_3 V_441 ;
int V_442 , V_443 ;
T_2 V_204 = V_1 -> V_204 ;
T_3 V_444 [ 2 ] ;
if ( F_13 ( V_7 ) )
F_221 ( V_159 ) ;
V_444 [ 0 ] = V_1 -> V_162 ;
V_444 [ 1 ] = V_1 -> V_174 ;
if ( F_94 ( V_1 -> V_11 ) )
V_444 [ 1 ] |= V_445 ;
F_215 ( & V_1 -> V_128 , V_446 , V_444 , 2 ) ;
V_444 [ 0 ] = 0 ;
V_444 [ 1 ] = V_447 ;
F_215 ( & V_1 -> V_128 , V_448 , V_444 , 2 ) ;
V_204 |= V_253 ;
if ( ! F_216 ( V_1 , & V_204 ,
V_424 |
V_418 ) ) {
F_43 ( L_64 ) ;
return;
}
V_441 = 0xff ;
V_442 = 0 ;
V_443 = 0 ;
for (; ; ) {
T_3 V_345 [ V_346 ] ;
F_222 ( V_1 -> V_11 ) ;
if ( ! F_194 ( V_1 , V_345 ) ) {
F_43 ( L_65 ) ;
break;
}
if ( F_223 ( V_345 , V_1 -> V_174 ) ) {
F_37 ( L_66 ) ;
break;
}
for ( V_49 = 0 ; V_49 < V_1 -> V_174 ; V_49 ++ )
if ( ( V_1 -> V_361 [ V_49 ] & V_369 ) == 0 )
break;
if ( V_49 == V_1 -> V_174 ) {
++ V_443 ;
if ( V_443 == 5 ) {
F_43 ( L_67 ) ;
break;
}
F_216 ( V_1 , & V_204 ,
V_424 |
V_418 ) ;
V_442 = 0 ;
continue;
}
if ( ( V_1 -> V_361 [ 0 ] & V_351 ) == V_441 ) {
++ V_442 ;
if ( V_442 == 5 ) {
F_43 ( L_68 ) ;
break;
}
} else
V_442 = 0 ;
V_441 = V_1 -> V_361 [ 0 ] & V_351 ;
if ( ! F_217 ( V_1 , & V_204 , V_345 ) ) {
F_43 ( L_69 ) ;
break;
}
}
V_1 -> V_204 = V_204 ;
}
void
F_169 ( struct V_1 * V_1 )
{
bool V_449 = false ;
int V_450 , V_451 ;
T_2 V_204 = V_1 -> V_204 ;
T_2 V_452 = V_426 ;
if ( V_1 -> V_162 == V_16 || V_1 -> V_453 )
V_452 = V_428 ;
if ( ! F_213 ( V_1 , & V_204 ,
V_452 |
V_418 ) ) {
F_43 ( L_70 ) ;
return;
}
V_450 = 0 ;
V_451 = 0 ;
V_449 = false ;
for (; ; ) {
T_3 V_345 [ V_346 ] ;
if ( V_451 > 5 ) {
F_43 ( L_71 ) ;
break;
}
F_224 ( V_1 -> V_11 ) ;
if ( ! F_194 ( V_1 , V_345 ) ) {
F_43 ( L_65 ) ;
break;
}
if ( ! F_223 ( V_345 , V_1 -> V_174 ) ) {
F_168 ( V_1 ) ;
F_213 ( V_1 , & V_204 ,
V_452 |
V_418 ) ;
V_451 ++ ;
continue;
}
if ( F_225 ( V_345 , V_1 -> V_174 ) ) {
V_449 = true ;
break;
}
if ( V_450 > 5 ) {
F_165 ( V_1 ) ;
F_168 ( V_1 ) ;
F_213 ( V_1 , & V_204 ,
V_452 |
V_418 ) ;
V_450 = 0 ;
V_451 ++ ;
continue;
}
if ( ! F_217 ( V_1 , & V_204 , V_345 ) ) {
F_43 ( L_69 ) ;
break;
}
++ V_450 ;
}
F_218 ( V_1 ) ;
V_1 -> V_204 = V_204 ;
if ( V_449 )
F_37 ( L_72 ) ;
}
void F_170 ( struct V_1 * V_1 )
{
F_213 ( V_1 , & V_1 -> V_204 ,
V_422 ) ;
}
static void
F_165 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_21 V_21 = V_3 -> V_21 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_172 * V_172 =
F_27 ( V_3 -> V_4 . V_4 . V_69 ) ;
T_2 V_204 = V_1 -> V_204 ;
if ( F_13 ( V_7 ) )
return;
if ( F_63 ( ( F_25 ( V_1 -> V_153 ) & V_253 ) == 0 ) )
return;
F_37 ( L_43 ) ;
if ( F_95 ( V_7 ) && ( F_47 ( V_7 ) || V_21 != V_22 ) ) {
V_204 &= ~ V_430 ;
F_64 ( V_1 -> V_153 , V_204 | V_454 ) ;
} else {
V_204 &= ~ V_433 ;
F_64 ( V_1 -> V_153 , V_204 | V_455 ) ;
}
F_87 ( V_1 -> V_153 ) ;
F_226 ( V_7 , V_172 -> V_67 ) ;
if ( F_227 ( V_7 ) &&
F_25 ( V_1 -> V_153 ) & V_218 ) {
struct V_68 * V_69 = V_3 -> V_4 . V_4 . V_69 ;
V_204 &= ~ V_218 ;
F_64 ( V_1 -> V_153 , V_204 ) ;
if ( F_63 ( V_69 == NULL ) ) {
F_87 ( V_1 -> V_153 ) ;
F_62 ( 50 ) ;
} else
F_226 ( V_7 , V_172 -> V_67 ) ;
}
V_204 &= ~ V_210 ;
F_64 ( V_1 -> V_153 , V_204 & ~ V_253 ) ;
F_87 ( V_1 -> V_153 ) ;
F_62 ( V_1 -> V_456 ) ;
}
static bool
F_228 ( struct V_1 * V_1 )
{
struct V_2 * V_198 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_198 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
char V_457 [ sizeof( V_1 -> V_11 ) * 3 ] ;
if ( F_192 ( & V_1 -> V_128 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) < 0 )
return false ;
F_229 ( V_1 -> V_11 , sizeof( V_1 -> V_11 ) ,
32 , 1 , V_457 , sizeof( V_457 ) , false ) ;
F_37 ( L_73 , V_457 ) ;
if ( V_1 -> V_11 [ V_18 ] == 0 )
return false ;
memset ( V_1 -> V_297 , 0 , sizeof( V_1 -> V_297 ) ) ;
if ( F_1 ( V_1 ) ) {
F_192 ( & V_1 -> V_128 , V_458 ,
V_1 -> V_297 ,
sizeof( V_1 -> V_297 ) ) ;
if ( V_1 -> V_297 [ 0 ] & V_459 ) {
V_54 -> V_275 . V_276 = true ;
F_37 ( L_74 ) ;
}
}
if ( V_1 -> V_11 [ V_18 ] >= 0x12 &&
V_1 -> V_11 [ V_460 ] & V_461 ) {
V_1 -> V_453 = true ;
F_37 ( L_75 ) ;
} else
V_1 -> V_453 = false ;
if ( ! ( V_1 -> V_11 [ V_462 ] &
V_463 ) )
return true ;
if ( V_1 -> V_11 [ V_18 ] == 0x10 )
return true ;
if ( F_192 ( & V_1 -> V_128 , V_464 ,
V_1 -> V_465 ,
V_466 ) < 0 )
return false ;
return true ;
}
static void
F_230 ( struct V_1 * V_1 )
{
T_1 V_415 [ 3 ] ;
if ( ! ( V_1 -> V_11 [ V_467 ] & V_468 ) )
return;
F_106 ( V_1 ) ;
if ( F_192 ( & V_1 -> V_128 , V_469 , V_415 , 3 ) == 3 )
F_37 ( L_76 ,
V_415 [ 0 ] , V_415 [ 1 ] , V_415 [ 2 ] ) ;
if ( F_192 ( & V_1 -> V_128 , V_470 , V_415 , 3 ) == 3 )
F_37 ( L_77 ,
V_415 [ 0 ] , V_415 [ 1 ] , V_415 [ 2 ] ) ;
F_66 ( V_1 , false ) ;
}
int F_231 ( struct V_1 * V_1 , T_1 * V_471 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_172 * V_172 =
F_27 ( V_3 -> V_4 . V_4 . V_69 ) ;
T_1 V_415 [ 1 ] ;
if ( F_232 ( & V_1 -> V_128 , V_472 , V_415 ) < 0 )
return - V_473 ;
if ( ! ( V_415 [ 0 ] & V_474 ) )
return - V_475 ;
if ( F_127 ( & V_1 -> V_128 , V_476 ,
V_477 ) < 0 )
return - V_473 ;
F_226 ( V_7 , V_172 -> V_67 ) ;
F_226 ( V_7 , V_172 -> V_67 ) ;
if ( F_193 ( & V_1 -> V_128 , V_478 , V_471 , 6 ) < 0 )
return - V_473 ;
F_127 ( & V_1 -> V_128 , V_476 , 0 ) ;
return 0 ;
}
static bool
F_233 ( struct V_1 * V_1 , T_1 * V_479 )
{
return F_192 ( & V_1 -> V_128 ,
V_480 ,
V_479 , 1 ) == 1 ;
}
static void
F_234 ( struct V_1 * V_1 )
{
F_127 ( & V_1 -> V_128 , V_481 , V_482 ) ;
}
void
F_235 ( struct V_1 * V_1 )
{
struct V_158 * V_158 = & F_2 ( V_1 ) -> V_4 ;
T_1 V_479 ;
T_1 V_345 [ V_346 ] ;
if ( ! V_158 -> V_483 )
return;
if ( F_63 ( ! V_158 -> V_4 . V_69 ) )
return;
if ( ! F_194 ( V_1 , V_345 ) ) {
return;
}
if ( ! F_228 ( V_1 ) ) {
return;
}
if ( V_1 -> V_11 [ V_18 ] >= 0x11 &&
F_233 ( V_1 , & V_479 ) ) {
F_127 ( & V_1 -> V_128 ,
V_480 ,
V_479 ) ;
if ( V_479 & V_484 )
F_234 ( V_1 ) ;
if ( V_479 & ( V_485 | V_486 ) )
F_91 ( L_78 ) ;
}
if ( ! F_225 ( V_345 , V_1 -> V_174 ) ) {
F_37 ( L_79 ,
F_236 ( & V_158 -> V_4 ) ) ;
F_168 ( V_1 ) ;
F_169 ( V_1 ) ;
F_170 ( V_1 ) ;
}
}
static enum V_487
F_237 ( struct V_1 * V_1 )
{
T_3 * V_11 = V_1 -> V_11 ;
T_3 type ;
if ( ! F_228 ( V_1 ) )
return V_488 ;
if ( ! ( V_11 [ V_462 ] & V_463 ) )
return V_489 ;
if ( V_1 -> V_11 [ V_18 ] >= 0x11 &&
V_1 -> V_465 [ 0 ] & V_490 ) {
T_3 V_491 ;
if ( F_192 ( & V_1 -> V_128 , V_492 ,
& V_491 , 1 ) < 0 )
return V_493 ;
return F_238 ( V_491 ) ? V_489
: V_488 ;
}
if ( F_239 ( & V_1 -> V_128 . V_157 ) )
return V_489 ;
if ( V_1 -> V_11 [ V_18 ] >= 0x11 ) {
type = V_1 -> V_465 [ 0 ] & V_494 ;
if ( type == V_495 ||
type == V_496 )
return V_493 ;
} else {
type = V_1 -> V_11 [ V_462 ] &
V_497 ;
if ( type == V_498 ||
type == V_499 )
return V_493 ;
}
F_37 ( L_80 ) ;
return V_488 ;
}
static enum V_487
F_240 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_487 V_87 ;
if ( F_1 ( V_1 ) ) {
V_87 = F_241 ( V_7 ) ;
if ( V_87 == V_493 )
V_87 = V_489 ;
return V_87 ;
}
if ( ! F_242 ( V_54 , V_3 ) )
return V_488 ;
return F_237 ( V_1 ) ;
}
static enum V_487
F_243 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_2 V_500 ;
if ( F_1 ( V_1 ) ) {
enum V_487 V_87 ;
V_87 = F_241 ( V_7 ) ;
if ( V_87 == V_493 )
V_87 = V_489 ;
return V_87 ;
}
if ( F_24 ( V_7 ) ) {
switch ( V_3 -> V_21 ) {
case V_75 :
V_500 = V_501 ;
break;
case V_77 :
V_500 = V_502 ;
break;
case V_151 :
V_500 = V_503 ;
break;
default:
return V_493 ;
}
} else {
switch ( V_3 -> V_21 ) {
case V_75 :
V_500 = V_504 ;
break;
case V_77 :
V_500 = V_505 ;
break;
case V_151 :
V_500 = V_506 ;
break;
default:
return V_493 ;
}
}
if ( ( F_25 ( V_507 ) & V_500 ) == 0 )
return V_488 ;
return F_237 ( V_1 ) ;
}
static struct V_508 *
F_244 ( struct V_8 * V_9 , struct V_509 * V_510 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
if ( V_32 -> V_508 ) {
if ( F_245 ( V_32 -> V_508 ) )
return NULL ;
return F_246 ( V_32 -> V_508 ) ;
}
return F_247 ( V_9 , V_510 ) ;
}
static int
F_248 ( struct V_8 * V_9 , struct V_509 * V_510 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
if ( V_32 -> V_508 ) {
if ( F_245 ( V_32 -> V_508 ) )
return 0 ;
return F_249 ( V_9 ,
V_32 -> V_508 ) ;
}
return F_250 ( V_9 , V_510 ) ;
}
static enum V_487
F_251 ( struct V_8 * V_9 , bool V_511 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_158 * V_158 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_487 V_87 ;
enum V_258 V_259 ;
struct V_508 * V_508 = NULL ;
F_105 ( V_54 ) ;
V_259 = F_129 ( V_158 ) ;
F_252 ( V_54 , V_259 ) ;
F_37 ( L_81 ,
V_9 -> V_4 . V_512 , F_253 ( V_9 ) ) ;
V_1 -> V_209 = false ;
if ( F_30 ( V_7 ) )
V_87 = F_240 ( V_1 ) ;
else
V_87 = F_243 ( V_1 ) ;
if ( V_87 != V_489 )
goto V_118;
F_230 ( V_1 ) ;
if ( V_1 -> V_513 != V_514 ) {
V_1 -> V_209 = ( V_1 -> V_513 == V_515 ) ;
} else {
V_508 = F_244 ( V_9 , & V_1 -> V_128 . V_157 ) ;
if ( V_508 ) {
V_1 -> V_209 = F_254 ( V_508 ) ;
F_255 ( V_508 ) ;
}
}
if ( V_158 -> type != V_5 )
V_158 -> type = V_516 ;
V_87 = V_489 ;
V_118:
F_256 ( V_54 , V_259 ) ;
F_109 ( V_54 ) ;
return V_87 ;
}
static int F_257 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_158 * V_158 = & V_3 -> V_4 ;
struct V_32 * V_32 = F_19 ( V_9 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_258 V_259 ;
int V_112 ;
V_259 = F_129 ( V_158 ) ;
F_252 ( V_54 , V_259 ) ;
V_112 = F_248 ( V_9 , & V_1 -> V_128 . V_157 ) ;
F_256 ( V_54 , V_259 ) ;
if ( V_112 )
return V_112 ;
if ( F_1 ( V_1 ) && V_32 -> V_34 . V_33 ) {
struct V_30 * V_31 ;
V_31 = F_258 ( V_7 ,
V_32 -> V_34 . V_33 ) ;
if ( V_31 ) {
F_259 ( V_9 , V_31 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_260 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_158 * V_158 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_258 V_259 ;
struct V_508 * V_508 ;
bool V_209 = false ;
V_259 = F_129 ( V_158 ) ;
F_252 ( V_54 , V_259 ) ;
V_508 = F_244 ( V_9 , & V_1 -> V_128 . V_157 ) ;
if ( V_508 ) {
V_209 = F_254 ( V_508 ) ;
F_255 ( V_508 ) ;
}
F_256 ( V_54 , V_259 ) ;
return V_209 ;
}
static int
F_261 ( struct V_8 * V_9 ,
struct V_517 * V_518 ,
T_7 V_306 )
{
struct V_53 * V_54 = V_9 -> V_7 -> V_55 ;
struct V_32 * V_32 = F_19 ( V_9 ) ;
struct V_158 * V_158 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_158 -> V_4 ) ;
int V_112 ;
V_112 = F_262 ( & V_9 -> V_4 , V_518 , V_306 ) ;
if ( V_112 )
return V_112 ;
if ( V_518 == V_54 -> V_519 ) {
int V_49 = V_306 ;
bool V_209 ;
if ( V_49 == V_1 -> V_513 )
return 0 ;
V_1 -> V_513 = V_49 ;
if ( V_49 == V_514 )
V_209 = F_260 ( V_9 ) ;
else
V_209 = ( V_49 == V_515 ) ;
if ( V_209 == V_1 -> V_209 )
return 0 ;
V_1 -> V_209 = V_209 ;
goto V_88;
}
if ( V_518 == V_54 -> V_520 ) {
bool V_521 = V_1 -> V_192 ;
T_2 V_522 = V_1 -> V_193 ;
switch ( V_306 ) {
case V_523 :
V_1 -> V_192 = true ;
break;
case V_524 :
V_1 -> V_192 = false ;
V_1 -> V_193 = 0 ;
break;
case V_525 :
V_1 -> V_192 = false ;
V_1 -> V_193 = V_194 ;
break;
default:
return - V_147 ;
}
if ( V_521 == V_1 -> V_192 &&
V_522 == V_1 -> V_193 )
return 0 ;
goto V_88;
}
if ( F_1 ( V_1 ) &&
V_518 == V_9 -> V_7 -> V_242 . V_526 ) {
if ( V_306 == V_527 ) {
F_37 ( L_82 ) ;
return - V_147 ;
}
if ( V_32 -> V_34 . V_184 == V_306 ) {
return 0 ;
}
V_32 -> V_34 . V_184 = V_306 ;
goto V_88;
}
return - V_147 ;
V_88:
if ( V_158 -> V_4 . V_69 )
F_263 ( V_158 -> V_4 . V_69 ) ;
return 0 ;
}
static void
F_264 ( struct V_8 * V_9 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
if ( ! F_265 ( V_32 -> V_508 ) )
F_255 ( V_32 -> V_508 ) ;
if ( V_9 -> V_528 == V_529 )
F_266 ( & V_32 -> V_34 ) ;
F_267 ( V_9 ) ;
F_255 ( V_9 ) ;
}
void F_268 ( struct V_440 * V_159 )
{
struct V_2 * V_3 = F_186 ( V_159 ) ;
struct V_1 * V_1 = & V_3 -> V_530 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
F_73 ( & V_1 -> V_128 ) ;
F_269 ( V_159 ) ;
if ( F_1 ( V_1 ) ) {
F_270 ( & V_1 -> V_248 ) ;
F_112 ( & V_7 -> V_242 . V_243 ) ;
F_107 ( V_1 ) ;
F_113 ( & V_7 -> V_242 . V_243 ) ;
}
F_255 ( V_3 ) ;
}
static void
F_271 ( struct V_158 * V_158 )
{
struct V_1 * V_1 = F_5 ( & V_158 -> V_4 ) ;
F_235 ( V_1 ) ;
}
int
F_272 ( struct V_68 * V_69 )
{
struct V_6 * V_7 = V_69 -> V_7 ;
struct V_158 * V_158 ;
struct V_1 * V_1 ;
F_273 (dev, crtc, intel_encoder) {
V_1 = F_5 ( & V_158 -> V_4 ) ;
if ( V_158 -> type == V_516 ||
V_158 -> type == V_5 )
return V_1 -> V_153 ;
}
return - 1 ;
}
bool F_274 ( struct V_6 * V_7 , enum V_21 V_21 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
union V_531 * V_532 ;
int V_49 ;
static const short V_533 [] = {
[ V_75 ] = V_534 ,
[ V_77 ] = V_535 ,
[ V_151 ] = V_536 ,
} ;
if ( V_21 == V_22 )
return true ;
if ( ! V_54 -> V_187 . V_537 )
return false ;
for ( V_49 = 0 ; V_49 < V_54 -> V_187 . V_537 ; V_49 ++ ) {
V_532 = V_54 -> V_187 . V_538 + V_49 ;
if ( V_532 -> V_539 . V_540 == V_533 [ V_21 ] &&
( V_532 -> V_539 . V_541 & V_542 ) ==
( V_543 & V_542 ) )
return true ;
}
return false ;
}
static void
F_275 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
F_276 ( V_9 ) ;
F_277 ( V_9 ) ;
V_1 -> V_192 = true ;
if ( F_1 ( V_1 ) ) {
F_278 ( V_9 -> V_7 ) ;
F_279 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_242 . V_526 ,
V_544 ) ;
V_32 -> V_34 . V_184 = V_544 ;
}
}
static void F_280 ( struct V_1 * V_1 )
{
V_1 -> V_227 = V_245 ;
V_1 -> V_231 = V_245 ;
V_1 -> V_233 = V_245 ;
}
static void
F_182 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_335 * V_118 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_335 V_545 , V_187 , V_546 , V_547 ;
T_4 V_548 , V_549 , V_550 , V_238 ;
int V_222 , V_551 , V_552 , V_553 ;
if ( F_30 ( V_7 ) ) {
V_222 = V_78 ;
V_551 = V_554 ;
V_552 = V_555 ;
V_553 = V_556 ;
} else {
enum V_67 V_67 = F_26 ( V_1 ) ;
V_222 = F_31 ( V_67 ) ;
V_551 = F_28 ( V_67 ) ;
V_552 = F_281 ( V_67 ) ;
V_553 = F_282 ( V_67 ) ;
}
V_238 = F_104 ( V_1 ) ;
F_64 ( V_222 , V_238 ) ;
V_548 = F_25 ( V_551 ) ;
V_549 = F_25 ( V_552 ) ;
V_550 = F_25 ( V_553 ) ;
V_545 . V_557 = ( V_548 & V_558 ) >>
V_559 ;
V_545 . V_560 = ( V_548 & V_561 ) >>
V_562 ;
V_545 . V_563 = ( V_549 & V_564 ) >>
V_565 ;
V_545 . V_566 = ( V_549 & V_567 ) >>
V_568 ;
V_545 . V_569 = ( ( V_550 & V_570 ) >>
V_571 ) * 1000 ;
F_37 ( L_83 ,
V_545 . V_557 , V_545 . V_560 , V_545 . V_563 , V_545 . V_566 , V_545 . V_569 ) ;
V_187 = V_54 -> V_187 . V_572 ;
V_546 . V_557 = 210 * 10 ;
V_546 . V_560 = 50 * 10 ;
V_546 . V_563 = 50 * 10 ;
V_546 . V_566 = 500 * 10 ;
V_546 . V_569 = ( 510 + 100 ) * 10 ;
F_37 ( L_84 ,
V_187 . V_557 , V_187 . V_560 , V_187 . V_563 , V_187 . V_566 , V_187 . V_569 ) ;
#define F_283 ( T_8 ) final.field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_283 ( V_557 ) ;
F_283 ( V_560 ) ;
F_283 ( V_563 ) ;
F_283 ( V_566 ) ;
F_283 ( V_569 ) ;
#undef F_283
#define F_284 ( T_8 ) (DIV_ROUND_UP(final.field, 10))
V_1 -> V_241 = F_284 ( V_557 ) ;
V_1 -> V_232 = F_284 ( V_560 ) ;
V_1 -> V_234 = F_284 ( V_563 ) ;
V_1 -> V_456 = F_284 ( V_566 ) ;
V_1 -> V_228 = F_284 ( V_569 ) ;
#undef F_284
F_37 ( L_85 ,
V_1 -> V_241 , V_1 -> V_456 ,
V_1 -> V_228 ) ;
F_37 ( L_86 ,
V_1 -> V_232 , V_1 -> V_234 ) ;
if ( V_118 )
* V_118 = V_547 ;
}
static void
F_183 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_335 * V_573 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
T_4 V_548 , V_549 , V_550 , V_72 = 0 ;
int div = F_30 ( V_7 ) ? F_49 ( V_7 ) : F_23 ( V_7 ) ;
int V_551 , V_552 , V_553 ;
if ( F_30 ( V_7 ) ) {
V_551 = V_554 ;
V_552 = V_555 ;
V_553 = V_556 ;
} else {
enum V_67 V_67 = F_26 ( V_1 ) ;
V_551 = F_28 ( V_67 ) ;
V_552 = F_281 ( V_67 ) ;
V_553 = F_282 ( V_67 ) ;
}
V_548 = ( V_573 -> V_557 << V_559 ) |
( 1 << V_562 ) ;
V_549 = ( 1 << V_565 ) |
( V_573 -> V_566 << V_568 ) ;
V_550 = ( ( 100 * div ) / 2 - 1 ) << V_574 ;
V_550 |= ( F_48 ( V_573 -> V_569 , 1000 )
<< V_571 ) ;
if ( F_24 ( V_7 ) ) {
if ( F_2 ( V_1 ) -> V_21 == V_75 )
V_72 = V_74 ;
else
V_72 = V_76 ;
} else if ( F_227 ( V_7 ) || F_95 ( V_7 ) ) {
if ( F_2 ( V_1 ) -> V_21 == V_22 )
V_72 = V_575 ;
else
V_72 = V_576 ;
}
V_548 |= V_72 ;
F_64 ( V_551 , V_548 ) ;
F_64 ( V_552 , V_549 ) ;
F_64 ( V_553 , V_550 ) ;
F_37 ( L_87 ,
F_25 ( V_551 ) ,
F_25 ( V_552 ) ,
F_25 ( V_553 ) ) ;
}
static bool F_285 ( struct V_1 * V_1 ,
struct V_32 * V_32 ,
struct V_335 * V_336 )
{
struct V_8 * V_9 = & V_32 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_158 * V_158 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_158 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_30 * V_33 = NULL ;
bool V_577 ;
struct V_30 * V_578 ;
struct V_508 * V_508 ;
if ( ! F_1 ( V_1 ) )
return true ;
if ( F_35 ( V_1 ) ) {
enum V_258 V_259 ;
V_259 = F_129 ( V_158 ) ;
F_252 ( V_54 , V_259 ) ;
}
F_106 ( V_1 ) ;
V_577 = F_228 ( V_1 ) ;
F_66 ( V_1 , false ) ;
if ( V_577 ) {
if ( V_1 -> V_11 [ V_18 ] >= 0x11 )
V_54 -> V_579 =
V_1 -> V_11 [ V_580 ] &
V_581 ;
} else {
F_286 ( L_88 ) ;
return false ;
}
F_183 ( V_7 , V_1 , V_336 ) ;
F_112 ( & V_7 -> V_242 . V_243 ) ;
V_508 = F_247 ( V_9 , & V_1 -> V_128 . V_157 ) ;
if ( V_508 ) {
if ( F_287 ( V_9 , V_508 ) ) {
F_288 ( V_9 ,
V_508 ) ;
F_289 ( V_9 , V_508 ) ;
} else {
F_255 ( V_508 ) ;
V_508 = F_290 ( - V_147 ) ;
}
} else {
V_508 = F_290 ( - V_582 ) ;
}
V_32 -> V_508 = V_508 ;
F_163 (scan, &connector->probed_modes, head) {
if ( ( V_578 -> type & V_583 ) ) {
V_33 = F_258 ( V_7 , V_578 ) ;
break;
}
}
if ( ! V_33 && V_54 -> V_187 . V_584 ) {
V_33 = F_258 ( V_7 ,
V_54 -> V_187 . V_584 ) ;
if ( V_33 )
V_33 -> type |= V_583 ;
}
F_113 ( & V_7 -> V_242 . V_243 ) ;
F_291 ( & V_32 -> V_34 , V_33 , NULL ) ;
F_292 ( V_9 ) ;
return true ;
}
bool
F_293 ( struct V_2 * V_3 ,
struct V_32 * V_32 )
{
struct V_8 * V_9 = & V_32 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_530 ;
struct V_158 * V_158 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_158 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
struct V_335 V_336 = { 0 } ;
int type ;
if ( F_24 ( V_7 ) )
V_1 -> V_120 = F_53 ;
else if ( F_8 ( V_7 ) || F_55 ( V_7 ) )
V_1 -> V_120 = F_50 ;
else if ( F_30 ( V_7 ) )
V_1 -> V_120 = F_45 ;
else
V_1 -> V_120 = F_44 ;
V_1 -> V_122 = F_54 ;
V_1 -> V_204 = F_25 ( V_1 -> V_153 ) ;
V_1 -> V_13 = V_32 ;
if ( F_274 ( V_7 , V_21 ) )
type = V_529 ;
else
type = V_585 ;
if ( type == V_529 )
V_158 -> type = V_5 ;
F_37 ( L_89 ,
type == V_529 ? L_90 : L_91 ,
F_294 ( V_21 ) ) ;
F_295 ( V_7 , V_9 , & V_586 , type ) ;
F_296 ( V_9 , & V_587 ) ;
V_9 -> V_588 = true ;
V_9 -> V_589 = 0 ;
F_297 ( & V_1 -> V_248 ,
F_110 ) ;
F_298 ( V_32 , V_158 ) ;
F_299 ( V_9 ) ;
if ( F_13 ( V_7 ) )
V_32 -> V_590 = V_591 ;
else
V_32 -> V_590 = V_592 ;
V_32 -> V_593 = F_74 ;
switch ( V_21 ) {
case V_22 :
V_158 -> V_594 = V_595 ;
break;
case V_75 :
V_158 -> V_594 = V_596 ;
break;
case V_77 :
V_158 -> V_594 = V_597 ;
break;
case V_151 :
V_158 -> V_594 = V_598 ;
break;
default:
F_70 () ;
}
if ( F_1 ( V_1 ) ) {
F_280 ( V_1 ) ;
F_182 ( V_7 , V_1 , & V_336 ) ;
}
F_69 ( V_1 , V_32 ) ;
V_1 -> V_287 = false ;
if ( ! F_285 ( V_1 , V_32 , & V_336 ) ) {
F_73 ( & V_1 -> V_128 ) ;
if ( F_1 ( V_1 ) ) {
F_270 ( & V_1 -> V_248 ) ;
F_112 ( & V_7 -> V_242 . V_243 ) ;
F_107 ( V_1 ) ;
F_113 ( & V_7 -> V_242 . V_243 ) ;
}
F_300 ( V_9 ) ;
F_267 ( V_9 ) ;
return false ;
}
F_275 ( V_1 , V_9 ) ;
if ( F_78 ( V_7 ) && ! F_301 ( V_7 ) ) {
T_4 V_417 = F_25 ( V_599 ) ;
F_64 ( V_599 , ( V_417 & ~ 0xf ) | 0xd ) ;
}
return true ;
}
void
F_302 ( struct V_6 * V_7 , int V_153 , enum V_21 V_21 )
{
struct V_2 * V_3 ;
struct V_158 * V_158 ;
struct V_440 * V_159 ;
struct V_32 * V_32 ;
V_3 = F_303 ( sizeof( * V_3 ) , V_600 ) ;
if ( ! V_3 )
return;
V_32 = F_303 ( sizeof( * V_32 ) , V_600 ) ;
if ( ! V_32 ) {
F_255 ( V_3 ) ;
return;
}
V_158 = & V_3 -> V_4 ;
V_159 = & V_158 -> V_4 ;
F_304 ( V_7 , & V_158 -> V_4 , & V_601 ,
V_602 ) ;
V_158 -> V_603 = F_80 ;
V_158 -> V_604 = F_89 ;
V_158 -> V_605 = F_164 ;
V_158 -> V_606 = F_166 ;
V_158 -> V_590 = F_128 ;
V_158 -> V_607 = F_135 ;
if ( F_24 ( V_7 ) ) {
V_158 -> V_608 = F_185 ;
V_158 -> V_609 = F_174 ;
V_158 -> V_610 = F_172 ;
} else {
V_158 -> V_609 = F_173 ;
V_158 -> V_610 = F_171 ;
}
V_3 -> V_21 = V_21 ;
V_3 -> V_530 . V_153 = V_153 ;
V_158 -> type = V_516 ;
V_158 -> V_611 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_158 -> V_612 = 0 ;
V_158 -> V_613 = F_271 ;
if ( ! F_293 ( V_3 , V_32 ) ) {
F_269 ( V_159 ) ;
F_255 ( V_3 ) ;
F_255 ( V_32 ) ;
}
}
