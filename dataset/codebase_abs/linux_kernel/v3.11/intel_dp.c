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
switch ( V_10 ) {
case V_13 :
case V_14 :
break;
case V_15 :
V_10 = V_14 ;
break;
default:
F_8 ( 1 , L_1 ,
V_10 ) ;
V_10 = V_13 ;
break;
}
return V_10 ;
}
static int
F_9 ( int V_16 , int V_17 )
{
return ( V_16 * V_17 + 9 ) / 10 ;
}
static int
F_10 ( int V_18 , int V_19 )
{
return ( V_18 * V_19 * 8 ) / 10 ;
}
static int
F_11 ( struct V_8 * V_9 ,
struct V_20 * V_21 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_22 * V_22 = F_12 ( V_9 ) ;
struct V_20 * V_23 = V_22 -> V_24 . V_23 ;
int V_25 = V_21 -> clock ;
int V_26 , V_27 , V_19 , V_18 ;
if ( F_1 ( V_1 ) && V_23 ) {
if ( V_21 -> V_28 > V_23 -> V_28 )
return V_29 ;
if ( V_21 -> V_30 > V_23 -> V_30 )
return V_29 ;
V_25 = V_23 -> clock ;
}
V_18 = F_13 ( F_7 ( V_1 ) ) ;
V_19 = F_14 ( V_1 -> V_11 ) ;
V_26 = F_10 ( V_18 , V_19 ) ;
V_27 = F_9 ( V_25 , 18 ) ;
if ( V_27 > V_26 )
return V_31 ;
if ( V_21 -> clock < 10000 )
return V_32 ;
if ( V_21 -> V_33 & V_34 )
return V_35 ;
return V_36 ;
}
static T_1
F_15 ( T_2 * V_37 , int V_38 )
{
int V_39 ;
T_1 V_40 = 0 ;
if ( V_38 > 4 )
V_38 = 4 ;
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ )
V_40 |= ( ( T_1 ) V_37 [ V_39 ] ) << ( ( 3 - V_39 ) * 8 ) ;
return V_40 ;
}
static void
F_16 ( T_1 V_37 , T_2 * V_41 , int V_42 )
{
int V_39 ;
if ( V_42 > 4 )
V_42 = 4 ;
for ( V_39 = 0 ; V_39 < V_42 ; V_39 ++ )
V_41 [ V_39 ] = V_37 >> ( ( 3 - V_39 ) * 8 ) ;
}
static int
F_17 ( struct V_6 * V_7 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
T_1 V_46 ;
if ( F_18 ( V_7 ) )
return 200 ;
V_46 = F_19 ( V_47 ) ;
switch ( V_46 & V_48 ) {
case V_49 :
return 100 ;
case V_50 :
return 133 ;
case V_51 :
return 166 ;
case V_52 :
return 200 ;
case V_53 :
return 266 ;
case V_54 :
return 333 ;
case V_55 :
case V_56 :
return 400 ;
default:
return 133 ;
}
}
static bool F_20 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_57 ;
V_57 = F_18 ( V_7 ) ? V_58 : V_59 ;
return ( F_19 ( V_57 ) & V_60 ) != 0 ;
}
static bool F_21 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_61 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
return ( F_19 ( V_61 ) & V_64 ) != 0 ;
}
static void
F_22 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_57 , V_61 ;
if ( ! F_1 ( V_1 ) )
return;
V_57 = F_18 ( V_7 ) ? V_58 : V_59 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
if ( ! F_20 ( V_1 ) && ! F_21 ( V_1 ) ) {
F_8 ( 1 , L_2 ) ;
F_23 ( L_3 ,
F_19 ( V_57 ) ,
F_19 ( V_61 ) ) ;
}
}
static T_1
F_24 ( struct V_1 * V_1 , bool V_65 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_1 V_66 = V_1 -> V_67 ;
T_1 V_68 ;
bool V_69 ;
#define F_25 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_65 )
V_69 = F_26 ( V_44 -> V_70 , F_25 ,
F_27 ( 10 ) ) ;
else
V_69 = F_28 ( F_25 , 10 ) == 0 ;
if ( ! V_69 )
F_29 ( L_4 ,
V_65 ) ;
#undef F_25
return V_68 ;
}
static int
F_30 ( struct V_1 * V_1 ,
T_2 * V_71 , int V_72 ,
T_2 * V_73 , int V_74 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_1 V_66 = V_1 -> V_67 ;
T_1 V_75 = V_66 + 4 ;
int V_39 , V_76 , V_77 ;
T_1 V_68 ;
T_1 V_78 ;
int V_79 , V_80 ;
bool V_65 = F_31 ( V_7 ) -> V_81 >= 5 && ! F_18 ( V_7 ) ;
F_32 ( & V_44 -> V_82 , 0 ) ;
F_22 ( V_1 ) ;
if ( F_18 ( V_7 ) ) {
V_78 = 100 ;
} else if ( V_3 -> V_83 == V_84 ) {
if ( F_33 ( V_7 ) )
V_78 = F_34 (
F_35 ( V_44 ) , 2000 ) ;
else if ( F_36 ( V_7 ) || F_37 ( V_7 ) )
V_78 = 200 ;
else
V_78 = 225 ;
} else if ( V_44 -> V_85 == V_86 ) {
V_78 = 74 ;
} else if ( F_38 ( V_7 ) ) {
V_78 = F_39 ( F_40 ( V_7 ) , 2 ) ;
} else {
V_78 = F_17 ( V_7 ) / 2 ;
}
if ( F_36 ( V_7 ) )
V_80 = 3 ;
else
V_80 = 5 ;
for ( V_79 = 0 ; V_79 < 3 ; V_79 ++ ) {
V_68 = F_41 ( V_66 ) ;
if ( ( V_68 & V_87 ) == 0 )
break;
F_42 ( 1 ) ;
}
if ( V_79 == 3 ) {
F_8 ( 1 , L_5 ,
F_19 ( V_66 ) ) ;
V_76 = - V_88 ;
goto V_89;
}
for ( V_79 = 0 ; V_79 < 5 ; V_79 ++ ) {
for ( V_39 = 0 ; V_39 < V_72 ; V_39 += 4 )
F_43 ( V_75 + V_39 ,
F_15 ( V_71 + V_39 , V_72 - V_39 ) ) ;
F_43 ( V_66 ,
V_87 |
( V_65 ? V_90 : 0 ) |
V_91 |
( V_72 << V_92 ) |
( V_80 << V_93 ) |
( V_78 << V_94 ) |
V_95 |
V_96 |
V_97 ) ;
V_68 = F_24 ( V_1 , V_65 ) ;
F_43 ( V_66 ,
V_68 |
V_95 |
V_96 |
V_97 ) ;
if ( V_68 & ( V_96 |
V_97 ) )
continue;
if ( V_68 & V_95 )
break;
}
if ( ( V_68 & V_95 ) == 0 ) {
F_29 ( L_6 , V_68 ) ;
V_76 = - V_88 ;
goto V_89;
}
if ( V_68 & V_97 ) {
F_29 ( L_7 , V_68 ) ;
V_76 = - V_98 ;
goto V_89;
}
if ( V_68 & V_96 ) {
F_23 ( L_8 , V_68 ) ;
V_76 = - V_99 ;
goto V_89;
}
V_77 = ( ( V_68 & V_100 ) >>
V_92 ) ;
if ( V_77 > V_74 )
V_77 = V_74 ;
for ( V_39 = 0 ; V_39 < V_77 ; V_39 += 4 )
F_16 ( F_19 ( V_75 + V_39 ) ,
V_73 + V_39 , V_77 - V_39 ) ;
V_76 = V_77 ;
V_89:
F_32 ( & V_44 -> V_82 , V_101 ) ;
return V_76 ;
}
static int
F_44 ( struct V_1 * V_1 ,
T_4 V_102 , T_2 * V_71 , int V_72 )
{
int V_76 ;
T_2 V_103 [ 20 ] ;
int V_104 ;
T_2 V_105 ;
F_22 ( V_1 ) ;
if ( V_72 > 16 )
return - 1 ;
V_103 [ 0 ] = V_106 << 4 ;
V_103 [ 1 ] = V_102 >> 8 ;
V_103 [ 2 ] = V_102 & 0xff ;
V_103 [ 3 ] = V_72 - 1 ;
memcpy ( & V_103 [ 4 ] , V_71 , V_72 ) ;
V_104 = V_72 + 4 ;
for (; ; ) {
V_76 = F_30 ( V_1 , V_103 , V_104 , & V_105 , 1 ) ;
if ( V_76 < 0 )
return V_76 ;
if ( ( V_105 & V_107 ) == V_108 )
break;
else if ( ( V_105 & V_107 ) == V_109 )
F_45 ( 100 ) ;
else
return - V_98 ;
}
return V_72 ;
}
static int
F_46 ( struct V_1 * V_1 ,
T_4 V_102 , T_2 V_110 )
{
return F_44 ( V_1 , V_102 , & V_110 , 1 ) ;
}
static int
F_47 ( struct V_1 * V_1 ,
T_4 V_102 , T_2 * V_73 , int V_77 )
{
T_2 V_103 [ 4 ] ;
int V_104 ;
T_2 V_111 [ 20 ] ;
int V_112 ;
T_2 V_105 ;
int V_76 ;
F_22 ( V_1 ) ;
V_103 [ 0 ] = V_113 << 4 ;
V_103 [ 1 ] = V_102 >> 8 ;
V_103 [ 2 ] = V_102 & 0xff ;
V_103 [ 3 ] = V_77 - 1 ;
V_104 = 4 ;
V_112 = V_77 + 1 ;
for (; ; ) {
V_76 = F_30 ( V_1 , V_103 , V_104 ,
V_111 , V_112 ) ;
if ( V_76 == 0 )
return - V_114 ;
if ( V_76 < 0 )
return V_76 ;
V_105 = V_111 [ 0 ] ;
if ( ( V_105 & V_107 ) == V_108 ) {
memcpy ( V_73 , V_111 + 1 , V_76 - 1 ) ;
return V_76 - 1 ;
}
else if ( ( V_105 & V_107 ) == V_109 )
F_45 ( 100 ) ;
else
return - V_98 ;
}
}
static int
F_48 ( struct V_115 * V_116 , int V_21 ,
T_2 V_117 , T_2 * V_118 )
{
struct V_119 * V_120 = V_116 -> V_120 ;
struct V_1 * V_1 = F_49 ( V_116 ,
struct V_1 ,
V_116 ) ;
T_4 V_102 = V_120 -> V_102 ;
T_2 V_103 [ 5 ] ;
T_2 V_111 [ 2 ] ;
unsigned V_121 ;
int V_104 ;
int V_112 ;
int V_76 ;
F_22 ( V_1 ) ;
if ( V_21 & V_122 )
V_103 [ 0 ] = V_123 << 4 ;
else
V_103 [ 0 ] = V_124 << 4 ;
if ( ! ( V_21 & V_125 ) )
V_103 [ 0 ] |= V_126 << 4 ;
V_103 [ 1 ] = V_102 >> 8 ;
V_103 [ 2 ] = V_102 ;
switch ( V_21 ) {
case V_127 :
V_103 [ 3 ] = 0 ;
V_103 [ 4 ] = V_117 ;
V_104 = 5 ;
V_112 = 1 ;
break;
case V_122 :
V_103 [ 3 ] = 0 ;
V_104 = 4 ;
V_112 = 2 ;
break;
default:
V_104 = 3 ;
V_112 = 1 ;
break;
}
for ( V_121 = 0 ; V_121 < 5 ; V_121 ++ ) {
V_76 = F_30 ( V_1 ,
V_103 , V_104 ,
V_111 , V_112 ) ;
if ( V_76 < 0 ) {
F_23 ( L_9 , V_76 ) ;
return V_76 ;
}
switch ( V_111 [ 0 ] & V_107 ) {
case V_108 :
break;
case V_128 :
F_23 ( L_10 ) ;
return - V_129 ;
case V_109 :
F_45 ( 100 ) ;
continue;
default:
F_29 ( L_11 ,
V_111 [ 0 ] ) ;
return - V_129 ;
}
switch ( V_111 [ 0 ] & V_130 ) {
case V_131 :
if ( V_21 == V_122 ) {
* V_118 = V_111 [ 1 ] ;
}
return V_112 - 1 ;
case V_132 :
F_23 ( L_12 ) ;
return - V_129 ;
case V_133 :
F_23 ( L_13 ) ;
F_45 ( 100 ) ;
break;
default:
F_29 ( L_14 , V_111 [ 0 ] ) ;
return - V_129 ;
}
}
F_29 ( L_15 ) ;
return - V_129 ;
}
static int
F_50 ( struct V_1 * V_1 ,
struct V_22 * V_22 , const char * V_134 )
{
int V_76 ;
F_23 ( L_16 , V_134 ) ;
V_1 -> V_135 . V_136 = false ;
V_1 -> V_135 . V_102 = 0 ;
V_1 -> V_135 . V_137 = F_48 ;
memset ( & V_1 -> V_116 , '\0' , sizeof( V_1 -> V_116 ) ) ;
V_1 -> V_116 . V_138 = V_139 ;
V_1 -> V_116 . V_140 = V_141 ;
strncpy ( V_1 -> V_116 . V_134 , V_134 , sizeof( V_1 -> V_116 . V_134 ) - 1 ) ;
V_1 -> V_116 . V_134 [ sizeof( V_1 -> V_116 . V_134 ) - 1 ] = '\0' ;
V_1 -> V_116 . V_120 = & V_1 -> V_135 ;
V_1 -> V_116 . V_7 . V_142 = & V_22 -> V_4 . V_143 ;
F_51 ( V_1 ) ;
V_76 = F_52 ( & V_1 -> V_116 ) ;
F_53 ( V_1 , false ) ;
return V_76 ;
}
static void
F_54 ( struct V_144 * V_145 ,
struct V_146 * V_147 , int V_148 )
{
struct V_6 * V_7 = V_145 -> V_4 . V_7 ;
if ( F_55 ( V_7 ) ) {
if ( V_148 == V_13 ) {
V_147 -> V_149 . V_150 = 2 ;
V_147 -> V_149 . V_151 = 10 ;
V_147 -> V_149 . V_152 = 2 ;
V_147 -> V_149 . V_153 = 23 ;
V_147 -> V_149 . V_154 = 8 ;
} else {
V_147 -> V_149 . V_150 = 1 ;
V_147 -> V_149 . V_151 = 10 ;
V_147 -> V_149 . V_152 = 1 ;
V_147 -> V_149 . V_153 = 14 ;
V_147 -> V_149 . V_154 = 2 ;
}
V_147 -> V_155 = true ;
} else if ( F_56 ( V_7 ) ) {
} else if ( F_38 ( V_7 ) ) {
if ( V_148 == V_13 ) {
V_147 -> V_149 . V_152 = 1 ;
V_147 -> V_149 . V_150 = 2 ;
V_147 -> V_149 . V_151 = 10 ;
V_147 -> V_149 . V_153 = 12 ;
V_147 -> V_149 . V_154 = 9 ;
} else {
V_147 -> V_149 . V_152 = 2 ;
V_147 -> V_149 . V_150 = 1 ;
V_147 -> V_149 . V_151 = 10 ;
V_147 -> V_149 . V_153 = 14 ;
V_147 -> V_149 . V_154 = 8 ;
}
V_147 -> V_155 = true ;
} else if ( F_18 ( V_7 ) ) {
}
}
bool
F_57 ( struct V_144 * V_145 ,
struct V_146 * V_147 )
{
struct V_6 * V_7 = V_145 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_20 * V_156 = & V_147 -> V_156 ;
struct V_1 * V_1 = F_5 ( & V_145 -> V_4 ) ;
enum V_83 V_83 = F_2 ( V_1 ) -> V_83 ;
struct V_157 * V_157 = V_145 -> V_158 ;
struct V_22 * V_22 = V_1 -> V_159 ;
int V_160 , clock ;
int V_161 = F_14 ( V_1 -> V_11 ) ;
int V_162 = F_7 ( V_1 ) == V_14 ? 1 : 0 ;
int V_17 , V_27 ;
static int V_163 [ 2 ] = { V_13 , V_14 } ;
int V_164 , V_165 ;
if ( F_38 ( V_7 ) && ! F_33 ( V_7 ) && V_83 != V_84 )
V_147 -> V_166 = true ;
V_147 -> V_167 = true ;
if ( F_1 ( V_1 ) && V_22 -> V_24 . V_23 ) {
F_58 ( V_22 -> V_24 . V_23 ,
V_156 ) ;
if ( ! F_38 ( V_7 ) )
F_59 ( V_157 , V_147 ,
V_22 -> V_24 . V_168 ) ;
else
F_60 ( V_157 , V_147 ,
V_22 -> V_24 . V_168 ) ;
}
if ( V_156 -> V_33 & V_34 )
return false ;
F_23 ( L_17
L_18 ,
V_161 , V_163 [ V_162 ] , V_156 -> clock ) ;
V_17 = V_147 -> V_169 ;
if ( F_1 ( V_1 ) && V_44 -> V_170 . V_171 )
V_17 = F_61 ( int , V_17 , V_44 -> V_170 . V_171 ) ;
for (; V_17 >= 6 * 3 ; V_17 -= 2 * 3 ) {
V_27 = F_9 ( V_156 -> clock , V_17 ) ;
for ( clock = 0 ; clock <= V_162 ; clock ++ ) {
for ( V_160 = 1 ; V_160 <= V_161 ; V_160 <<= 1 ) {
V_165 = F_13 ( V_163 [ clock ] ) ;
V_164 = F_10 ( V_165 ,
V_160 ) ;
if ( V_27 <= V_164 ) {
goto V_172;
}
}
}
}
return false ;
V_172:
if ( V_1 -> V_173 ) {
if ( V_17 != 18 && F_62 ( V_156 ) > 1 )
V_1 -> V_174 = V_175 ;
else
V_1 -> V_174 = 0 ;
}
if ( V_1 -> V_174 )
V_147 -> V_176 = true ;
V_1 -> V_148 = V_163 [ clock ] ;
V_1 -> V_160 = V_160 ;
V_147 -> V_169 = V_17 ;
V_147 -> V_177 = F_13 ( V_1 -> V_148 ) ;
F_23 ( L_19 ,
V_1 -> V_148 , V_1 -> V_160 ,
V_147 -> V_177 , V_17 ) ;
F_23 ( L_20 ,
V_27 , V_164 ) ;
F_63 ( V_17 , V_160 ,
V_156 -> clock , V_147 -> V_177 ,
& V_147 -> V_178 ) ;
F_54 ( V_145 , V_147 , V_1 -> V_148 ) ;
return true ;
}
void F_64 ( struct V_1 * V_1 )
{
memset ( V_1 -> V_179 , 0 , V_180 ) ;
V_1 -> V_179 [ 0 ] = V_1 -> V_148 ;
V_1 -> V_179 [ 1 ] = V_1 -> V_160 ;
V_1 -> V_179 [ 8 ] = V_181 ;
if ( V_1 -> V_11 [ V_182 ] >= 0x11 &&
( V_1 -> V_11 [ V_183 ] & V_184 ) ) {
V_1 -> V_179 [ 1 ] |= V_185 ;
}
}
static void F_65 ( struct V_1 * V_1 )
{
struct V_2 * V_186 = F_2 ( V_1 ) ;
struct V_157 * V_187 = F_66 ( V_186 -> V_4 . V_4 . V_187 ) ;
struct V_6 * V_7 = V_187 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_188 ;
F_23 ( L_21 , V_187 -> V_189 . V_177 ) ;
V_188 = F_19 ( V_190 ) ;
V_188 &= ~ V_191 ;
if ( V_187 -> V_189 . V_177 == 162000 ) {
F_23 ( L_22 ) ;
V_188 |= V_192 ;
V_1 -> V_193 |= V_192 ;
} else {
V_188 |= V_194 ;
V_1 -> V_193 |= V_194 ;
}
F_43 ( V_190 , V_188 ) ;
F_67 ( V_190 ) ;
F_45 ( 500 ) ;
}
static void
F_68 ( struct V_195 * V_145 , struct V_20 * V_21 ,
struct V_20 * V_156 )
{
struct V_6 * V_7 = V_145 -> V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_1 * V_1 = F_5 ( V_145 ) ;
enum V_83 V_83 = F_2 ( V_1 ) -> V_83 ;
struct V_157 * V_187 = F_66 ( V_145 -> V_187 ) ;
V_1 -> V_193 = F_19 ( V_1 -> V_196 ) & V_197 ;
V_1 -> V_193 |= V_198 | V_199 ;
V_1 -> V_193 |= F_69 ( V_1 -> V_160 ) ;
if ( V_1 -> V_200 ) {
F_70 ( L_23 ,
F_71 ( V_187 -> V_201 ) ) ;
V_1 -> V_193 |= V_202 ;
F_72 ( V_145 , V_156 ) ;
}
F_64 ( V_1 ) ;
if ( V_83 == V_84 && F_37 ( V_7 ) && ! F_18 ( V_7 ) ) {
if ( V_156 -> V_33 & V_203 )
V_1 -> V_193 |= V_204 ;
if ( V_156 -> V_33 & V_205 )
V_1 -> V_193 |= V_206 ;
V_1 -> V_193 |= V_207 ;
if ( V_1 -> V_179 [ 1 ] & V_185 )
V_1 -> V_193 |= V_208 ;
V_1 -> V_193 |= V_187 -> V_201 << 29 ;
} else if ( ! F_73 ( V_7 ) || V_83 == V_84 ) {
if ( ! F_38 ( V_7 ) && ! F_18 ( V_7 ) )
V_1 -> V_193 |= V_1 -> V_174 ;
if ( V_156 -> V_33 & V_203 )
V_1 -> V_193 |= V_204 ;
if ( V_156 -> V_33 & V_205 )
V_1 -> V_193 |= V_206 ;
V_1 -> V_193 |= V_209 ;
if ( V_1 -> V_179 [ 1 ] & V_185 )
V_1 -> V_193 |= V_208 ;
if ( V_187 -> V_201 == 1 )
V_1 -> V_193 |= V_210 ;
} else {
V_1 -> V_193 |= V_207 ;
}
if ( V_83 == V_84 && ! F_18 ( V_7 ) )
F_65 ( V_1 ) ;
}
static void F_74 ( struct V_1 * V_1 ,
T_3 V_211 ,
T_3 V_212 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_57 , V_61 ;
V_57 = F_18 ( V_7 ) ? V_58 : V_59 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
F_23 ( L_24 ,
V_211 , V_212 ,
F_19 ( V_57 ) ,
F_19 ( V_61 ) ) ;
if ( F_75 ( ( F_19 ( V_57 ) & V_211 ) == V_212 , 5000 , 10 ) ) {
F_29 ( L_25 ,
F_19 ( V_57 ) ,
F_19 ( V_61 ) ) ;
}
}
static void F_76 ( struct V_1 * V_1 )
{
F_23 ( L_26 ) ;
F_74 ( V_1 , V_213 , V_214 ) ;
}
static void F_77 ( struct V_1 * V_1 )
{
F_23 ( L_27 ) ;
F_74 ( V_1 , V_215 , V_216 ) ;
}
static void F_78 ( struct V_1 * V_1 )
{
F_23 ( L_28 ) ;
F_74 ( V_1 , V_217 , V_218 ) ;
}
static T_3 F_79 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_219 ;
T_3 V_61 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
V_219 = F_19 ( V_61 ) ;
V_219 &= ~ V_220 ;
V_219 |= V_221 ;
return V_219 ;
}
void F_51 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_222 ;
T_3 V_57 , V_61 ;
if ( ! F_1 ( V_1 ) )
return;
F_23 ( L_29 ) ;
F_8 ( V_1 -> V_223 ,
L_30 ) ;
V_1 -> V_223 = true ;
if ( F_21 ( V_1 ) ) {
F_23 ( L_31 ) ;
return;
}
if ( ! F_20 ( V_1 ) )
F_78 ( V_1 ) ;
V_222 = F_79 ( V_1 ) ;
V_222 |= V_64 ;
V_57 = F_18 ( V_7 ) ? V_58 : V_59 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
F_43 ( V_61 , V_222 ) ;
F_67 ( V_61 ) ;
F_23 ( L_32 ,
F_19 ( V_57 ) , F_19 ( V_61 ) ) ;
if ( ! F_20 ( V_1 ) ) {
F_23 ( L_33 ) ;
F_42 ( V_1 -> V_224 ) ;
}
}
static void F_80 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_222 ;
T_3 V_57 , V_61 ;
F_81 ( ! F_82 ( & V_7 -> V_225 . V_226 ) ) ;
if ( ! V_1 -> V_223 && F_21 ( V_1 ) ) {
V_222 = F_79 ( V_1 ) ;
V_222 &= ~ V_64 ;
V_57 = F_18 ( V_7 ) ? V_58 : V_59 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
F_43 ( V_61 , V_222 ) ;
F_67 ( V_61 ) ;
F_23 ( L_32 ,
F_19 ( V_57 ) , F_19 ( V_61 ) ) ;
F_42 ( V_1 -> V_227 ) ;
}
}
static void F_83 ( struct V_228 * V_229 )
{
struct V_1 * V_1 = F_49 ( F_84 ( V_229 ) ,
struct V_1 , V_230 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
F_85 ( & V_7 -> V_225 . V_226 ) ;
F_80 ( V_1 ) ;
F_86 ( & V_7 -> V_225 . V_226 ) ;
}
void F_53 ( struct V_1 * V_1 , bool V_231 )
{
if ( ! F_1 ( V_1 ) )
return;
F_23 ( L_34 , V_1 -> V_223 ) ;
F_8 ( ! V_1 -> V_223 , L_35 ) ;
V_1 -> V_223 = false ;
if ( V_231 ) {
F_80 ( V_1 ) ;
} else {
F_87 ( & V_1 -> V_230 ,
F_88 ( V_1 -> V_232 * 5 ) ) ;
}
}
void F_89 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_222 ;
T_3 V_61 ;
if ( ! F_1 ( V_1 ) )
return;
F_23 ( L_36 ) ;
if ( F_20 ( V_1 ) ) {
F_23 ( L_37 ) ;
return;
}
F_78 ( V_1 ) ;
V_222 = F_79 ( V_1 ) ;
if ( F_90 ( V_7 ) ) {
V_222 &= ~ V_233 ;
F_43 ( V_63 , V_222 ) ;
F_67 ( V_63 ) ;
}
V_222 |= V_234 ;
if ( ! F_90 ( V_7 ) )
V_222 |= V_233 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
F_43 ( V_61 , V_222 ) ;
F_67 ( V_61 ) ;
F_76 ( V_1 ) ;
if ( F_90 ( V_7 ) ) {
V_222 |= V_233 ;
F_43 ( V_63 , V_222 ) ;
F_67 ( V_63 ) ;
}
}
void F_91 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_222 ;
T_3 V_61 ;
if ( ! F_1 ( V_1 ) )
return;
F_23 ( L_38 ) ;
F_8 ( ! V_1 -> V_223 , L_39 ) ;
V_222 = F_79 ( V_1 ) ;
V_222 &= ~ ( V_234 | V_64 | V_233 | V_235 ) ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
F_43 ( V_61 , V_222 ) ;
F_67 ( V_61 ) ;
V_1 -> V_223 = false ;
F_77 ( V_1 ) ;
}
void F_92 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
int V_201 = F_66 ( V_3 -> V_4 . V_4 . V_187 ) -> V_201 ;
T_3 V_222 ;
T_3 V_61 ;
if ( ! F_1 ( V_1 ) )
return;
F_23 ( L_40 ) ;
F_42 ( V_1 -> V_236 ) ;
V_222 = F_79 ( V_1 ) ;
V_222 |= V_235 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
F_43 ( V_61 , V_222 ) ;
F_67 ( V_61 ) ;
F_93 ( V_7 , V_201 ) ;
}
void F_94 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_222 ;
T_3 V_61 ;
if ( ! F_1 ( V_1 ) )
return;
F_95 ( V_7 ) ;
F_23 ( L_40 ) ;
V_222 = F_79 ( V_1 ) ;
V_222 &= ~ V_235 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
F_43 ( V_61 , V_222 ) ;
F_67 ( V_61 ) ;
F_42 ( V_1 -> V_237 ) ;
}
static void F_96 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_238 * V_187 = V_3 -> V_4 . V_4 . V_187 ;
struct V_6 * V_7 = V_187 -> V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_188 ;
F_97 ( V_44 ,
F_66 ( V_187 ) -> V_201 ) ;
F_23 ( L_40 ) ;
V_188 = F_19 ( V_190 ) ;
F_8 ( V_188 & V_239 , L_41 ) ;
F_8 ( V_188 & V_240 , L_42 ) ;
V_1 -> V_193 &= ~ ( V_240 | V_202 ) ;
V_1 -> V_193 |= V_239 ;
F_43 ( V_190 , V_1 -> V_193 ) ;
F_67 ( V_190 ) ;
F_45 ( 200 ) ;
}
static void F_98 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_238 * V_187 = V_3 -> V_4 . V_4 . V_187 ;
struct V_6 * V_7 = V_187 -> V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_188 ;
F_97 ( V_44 ,
F_66 ( V_187 ) -> V_201 ) ;
V_188 = F_19 ( V_190 ) ;
F_8 ( ( V_188 & V_239 ) == 0 ,
L_43 ) ;
F_8 ( V_188 & V_240 , L_42 ) ;
V_188 &= ~ V_239 ;
F_43 ( V_190 , V_188 ) ;
F_67 ( V_190 ) ;
F_45 ( 200 ) ;
}
void F_99 ( struct V_1 * V_1 , int V_21 )
{
int V_76 , V_39 ;
if ( V_1 -> V_11 [ V_182 ] < 0x11 )
return;
if ( V_21 != V_241 ) {
V_76 = F_46 ( V_1 , V_242 ,
V_243 ) ;
if ( V_76 != 1 )
F_70 ( L_44 ) ;
} else {
for ( V_39 = 0 ; V_39 < 3 ; V_39 ++ ) {
V_76 = F_46 ( V_1 ,
V_242 ,
V_244 ) ;
if ( V_76 == 1 )
break;
F_42 ( 1 ) ;
}
}
}
static bool F_100 ( struct V_144 * V_145 ,
enum V_201 * V_201 )
{
struct V_1 * V_1 = F_5 ( & V_145 -> V_4 ) ;
enum V_83 V_83 = F_2 ( V_1 ) -> V_83 ;
struct V_6 * V_7 = V_145 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_245 = F_19 ( V_1 -> V_196 ) ;
if ( ! ( V_245 & V_240 ) )
return false ;
if ( V_83 == V_84 && F_37 ( V_7 ) && ! F_18 ( V_7 ) ) {
* V_201 = F_101 ( V_245 ) ;
} else if ( ! F_73 ( V_7 ) || V_83 == V_84 ) {
* V_201 = F_102 ( V_245 ) ;
} else {
T_3 V_246 ;
T_3 V_247 ;
int V_39 ;
switch ( V_1 -> V_196 ) {
case V_248 :
V_246 = V_249 ;
break;
case V_250 :
V_246 = V_251 ;
break;
case V_252 :
V_246 = V_253 ;
break;
default:
return true ;
}
F_103 (i) {
V_247 = F_19 ( F_104 ( V_39 ) ) ;
if ( ( V_247 & V_254 ) == V_246 ) {
* V_201 = V_39 ;
return true ;
}
}
F_23 ( L_45 ,
V_1 -> V_196 ) ;
}
return true ;
}
static void F_105 ( struct V_144 * V_145 ,
struct V_146 * V_147 )
{
struct V_1 * V_1 = F_5 ( & V_145 -> V_4 ) ;
T_3 V_245 , V_33 = 0 ;
struct V_6 * V_7 = V_145 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
enum V_83 V_83 = F_2 ( V_1 ) -> V_83 ;
struct V_157 * V_187 = F_66 ( V_145 -> V_4 . V_187 ) ;
if ( ( V_83 == V_84 ) || ! F_73 ( V_7 ) ) {
V_245 = F_19 ( V_1 -> V_196 ) ;
if ( V_245 & V_204 )
V_33 |= V_203 ;
else
V_33 |= V_255 ;
if ( V_245 & V_206 )
V_33 |= V_205 ;
else
V_33 |= V_256 ;
} else {
V_245 = F_19 ( F_104 ( V_187 -> V_201 ) ) ;
if ( V_245 & V_257 )
V_33 |= V_203 ;
else
V_33 |= V_255 ;
if ( V_245 & V_258 )
V_33 |= V_205 ;
else
V_33 |= V_256 ;
}
V_147 -> V_156 . V_33 |= V_33 ;
}
static void F_106 ( struct V_144 * V_145 )
{
struct V_1 * V_1 = F_5 ( & V_145 -> V_4 ) ;
enum V_83 V_83 = F_2 ( V_1 ) -> V_83 ;
struct V_6 * V_7 = V_145 -> V_4 . V_7 ;
F_51 ( V_1 ) ;
F_94 ( V_1 ) ;
F_99 ( V_1 , V_241 ) ;
F_91 ( V_1 ) ;
if ( ! ( V_83 == V_84 || F_18 ( V_7 ) ) )
F_107 ( V_1 ) ;
}
static void F_108 ( struct V_144 * V_145 )
{
struct V_1 * V_1 = F_5 ( & V_145 -> V_4 ) ;
enum V_83 V_83 = F_2 ( V_1 ) -> V_83 ;
struct V_6 * V_7 = V_145 -> V_4 . V_7 ;
if ( V_83 == V_84 || F_18 ( V_7 ) ) {
F_107 ( V_1 ) ;
if ( ! F_18 ( V_7 ) )
F_98 ( V_1 ) ;
}
}
static void F_109 ( struct V_144 * V_145 )
{
struct V_1 * V_1 = F_5 ( & V_145 -> V_4 ) ;
struct V_6 * V_7 = V_145 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_1 V_259 = F_19 ( V_1 -> V_196 ) ;
if ( F_81 ( V_259 & V_240 ) )
return;
F_51 ( V_1 ) ;
F_99 ( V_1 , V_241 ) ;
F_110 ( V_1 ) ;
F_89 ( V_1 ) ;
F_53 ( V_1 , true ) ;
F_111 ( V_1 ) ;
F_112 ( V_1 ) ;
F_92 ( V_1 ) ;
if ( F_18 ( V_7 ) ) {
struct V_2 * V_260 =
F_113 ( & V_145 -> V_4 ) ;
int V_261 = F_114 ( V_260 ) ;
F_115 ( V_44 , V_261 ) ;
}
}
static void F_116 ( struct V_144 * V_145 )
{
struct V_1 * V_1 = F_5 ( & V_145 -> V_4 ) ;
struct V_2 * V_260 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_145 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
if ( V_260 -> V_83 == V_84 && ! F_18 ( V_7 ) )
F_96 ( V_1 ) ;
if ( F_18 ( V_7 ) ) {
struct V_157 * V_157 =
F_66 ( V_145 -> V_4 . V_187 ) ;
int V_83 = F_114 ( V_260 ) ;
int V_201 = V_157 -> V_201 ;
T_3 V_262 ;
V_262 = F_117 ( V_44 , F_118 ( V_83 ) ) ;
V_262 = 0 ;
if ( V_201 )
V_262 |= ( 1 << 21 ) ;
else
V_262 &= ~ ( 1 << 21 ) ;
V_262 |= 0x001000c4 ;
F_119 ( V_44 , F_120 ( V_83 ) , V_262 ) ;
F_119 ( V_44 , F_121 ( V_83 ) ,
0x00760018 ) ;
F_119 ( V_44 , F_122 ( V_83 ) ,
0x00400888 ) ;
}
}
static void F_123 ( struct V_144 * V_145 )
{
struct V_2 * V_260 = F_113 ( & V_145 -> V_4 ) ;
struct V_6 * V_7 = V_145 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
int V_83 = F_114 ( V_260 ) ;
if ( ! F_18 ( V_7 ) )
return;
F_119 ( V_44 , F_124 ( V_83 ) ,
V_263 |
V_264 ) ;
F_119 ( V_44 , F_125 ( V_83 ) ,
V_265 |
V_266 |
( 1 << V_267 ) |
V_268 ) ;
F_119 ( V_44 , F_126 ( V_83 ) , 0x00750f00 ) ;
F_119 ( V_44 , F_127 ( V_83 ) , 0x00001500 ) ;
F_119 ( V_44 , F_128 ( V_83 ) , 0x40400000 ) ;
}
static bool
F_129 ( struct V_1 * V_1 , T_4 V_102 ,
T_2 * V_73 , int V_77 )
{
int V_76 , V_39 ;
for ( V_39 = 0 ; V_39 < 3 ; V_39 ++ ) {
V_76 = F_47 ( V_1 , V_102 , V_73 ,
V_77 ) ;
if ( V_76 == V_77 )
return true ;
F_42 ( 1 ) ;
}
return false ;
}
static bool
F_130 ( struct V_1 * V_1 , T_2 V_269 [ V_270 ] )
{
return F_129 ( V_1 ,
V_271 ,
V_269 ,
V_270 ) ;
}
static T_2
F_131 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_83 V_83 = F_2 ( V_1 ) -> V_83 ;
if ( F_18 ( V_7 ) )
return V_272 ;
else if ( F_37 ( V_7 ) && V_83 == V_84 )
return V_273 ;
else if ( F_73 ( V_7 ) && V_83 != V_84 )
return V_272 ;
else
return V_273 ;
}
static T_2
F_132 ( struct V_1 * V_1 , T_2 V_274 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_83 V_83 = F_2 ( V_1 ) -> V_83 ;
if ( F_33 ( V_7 ) ) {
switch ( V_274 & V_275 ) {
case V_276 :
return V_277 ;
case V_278 :
return V_279 ;
case V_273 :
return V_280 ;
case V_272 :
default:
return V_281 ;
}
} else if ( F_18 ( V_7 ) ) {
switch ( V_274 & V_275 ) {
case V_276 :
return V_277 ;
case V_278 :
return V_279 ;
case V_273 :
return V_280 ;
case V_272 :
default:
return V_281 ;
}
} else if ( F_37 ( V_7 ) && V_83 == V_84 ) {
switch ( V_274 & V_275 ) {
case V_276 :
return V_279 ;
case V_278 :
case V_273 :
return V_280 ;
default:
return V_281 ;
}
} else {
switch ( V_274 & V_275 ) {
case V_276 :
return V_279 ;
case V_278 :
return V_279 ;
case V_273 :
return V_280 ;
case V_272 :
default:
return V_281 ;
}
}
}
static T_1 F_133 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_2 * V_260 = F_2 ( V_1 ) ;
unsigned long V_282 , V_283 ,
V_284 ;
T_2 V_285 = V_1 -> V_285 [ 0 ] ;
int V_83 = F_114 ( V_260 ) ;
switch ( V_285 & V_286 ) {
case V_281 :
V_283 = 0x0004000 ;
switch ( V_285 & V_275 ) {
case V_276 :
V_282 = 0x2B405555 ;
V_284 = 0x552AB83A ;
break;
case V_278 :
V_282 = 0x2B404040 ;
V_284 = 0x5548B83A ;
break;
case V_273 :
V_282 = 0x2B245555 ;
V_284 = 0x5560B83A ;
break;
case V_272 :
V_282 = 0x2B405555 ;
V_284 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_280 :
V_283 = 0x0002000 ;
switch ( V_285 & V_275 ) {
case V_276 :
V_282 = 0x2B404040 ;
V_284 = 0x5552B83A ;
break;
case V_278 :
V_282 = 0x2B404848 ;
V_284 = 0x5580B83A ;
break;
case V_273 :
V_282 = 0x2B404040 ;
V_284 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_279 :
V_283 = 0x0000000 ;
switch ( V_285 & V_275 ) {
case V_276 :
V_282 = 0x2B305555 ;
V_284 = 0x5570B83A ;
break;
case V_278 :
V_282 = 0x2B2B4040 ;
V_284 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_277 :
V_283 = 0x0006000 ;
switch ( V_285 & V_275 ) {
case V_276 :
V_282 = 0x1B405555 ;
V_284 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_119 ( V_44 , F_134 ( V_83 ) , 0x00000000 ) ;
F_119 ( V_44 , F_135 ( V_83 ) , V_282 ) ;
F_119 ( V_44 , F_136 ( V_83 ) ,
V_284 ) ;
F_119 ( V_44 , F_137 ( V_83 ) , 0x0C782040 ) ;
F_119 ( V_44 , F_138 ( V_83 ) , 0x00030000 ) ;
F_119 ( V_44 , F_139 ( V_83 ) , V_283 ) ;
F_119 ( V_44 , F_134 ( V_83 ) , 0x80000000 ) ;
return 0 ;
}
static void
F_140 ( struct V_1 * V_1 , T_2 V_269 [ V_270 ] )
{
T_2 V_40 = 0 ;
T_2 V_287 = 0 ;
int V_288 ;
T_2 V_289 ;
T_2 V_290 ;
for ( V_288 = 0 ; V_288 < V_1 -> V_160 ; V_288 ++ ) {
T_2 V_291 = F_141 ( V_269 , V_288 ) ;
T_2 V_292 = F_142 ( V_269 , V_288 ) ;
if ( V_291 > V_40 )
V_40 = V_291 ;
if ( V_292 > V_287 )
V_287 = V_292 ;
}
V_289 = F_131 ( V_1 ) ;
if ( V_40 >= V_289 )
V_40 = V_289 | V_293 ;
V_290 = F_132 ( V_1 , V_40 ) ;
if ( V_287 >= V_290 )
V_287 = V_290 | V_294 ;
for ( V_288 = 0 ; V_288 < 4 ; V_288 ++ )
V_1 -> V_285 [ V_288 ] = V_40 | V_287 ;
}
static T_1
F_143 ( T_2 V_285 )
{
T_1 V_295 = 0 ;
switch ( V_285 & V_275 ) {
case V_276 :
default:
V_295 |= V_198 ;
break;
case V_278 :
V_295 |= V_296 ;
break;
case V_273 :
V_295 |= V_297 ;
break;
case V_272 :
V_295 |= V_298 ;
break;
}
switch ( V_285 & V_286 ) {
case V_281 :
default:
V_295 |= V_199 ;
break;
case V_280 :
V_295 |= V_299 ;
break;
case V_279 :
V_295 |= V_300 ;
break;
case V_277 :
V_295 |= V_301 ;
break;
}
return V_295 ;
}
static T_1
F_144 ( T_2 V_285 )
{
int V_295 = V_285 & ( V_275 |
V_286 ) ;
switch ( V_295 ) {
case V_276 | V_281 :
case V_278 | V_281 :
return V_302 ;
case V_276 | V_280 :
return V_303 ;
case V_276 | V_279 :
case V_278 | V_279 :
return V_304 ;
case V_278 | V_280 :
case V_273 | V_280 :
return V_305 ;
case V_273 | V_281 :
case V_272 | V_281 :
return V_306 ;
default:
F_23 ( L_46
L_47 , V_295 ) ;
return V_302 ;
}
}
static T_1
F_145 ( T_2 V_285 )
{
int V_295 = V_285 & ( V_275 |
V_286 ) ;
switch ( V_295 ) {
case V_276 | V_281 :
return V_307 ;
case V_276 | V_280 :
return V_308 ;
case V_276 | V_279 :
return V_309 ;
case V_278 | V_281 :
return V_310 ;
case V_278 | V_280 :
return V_311 ;
case V_273 | V_281 :
return V_312 ;
case V_273 | V_280 :
return V_313 ;
default:
F_23 ( L_46
L_47 , V_295 ) ;
return V_314 ;
}
}
static T_1
F_146 ( T_2 V_285 )
{
int V_295 = V_285 & ( V_275 |
V_286 ) ;
switch ( V_295 ) {
case V_276 | V_281 :
return V_315 ;
case V_276 | V_280 :
return V_316 ;
case V_276 | V_279 :
return V_317 ;
case V_276 | V_277 :
return V_318 ;
case V_278 | V_281 :
return V_319 ;
case V_278 | V_280 :
return V_320 ;
case V_278 | V_279 :
return V_321 ;
case V_273 | V_281 :
return V_322 ;
case V_273 | V_280 :
return V_323 ;
default:
F_23 ( L_46
L_47 , V_295 ) ;
return V_315 ;
}
}
static void
F_147 ( struct V_1 * V_1 , T_1 * V_193 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_83 V_83 = V_3 -> V_83 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_1 V_295 , V_211 ;
T_2 V_285 = V_1 -> V_285 [ 0 ] ;
if ( F_33 ( V_7 ) ) {
V_295 = F_146 ( V_285 ) ;
V_211 = V_324 ;
} else if ( F_18 ( V_7 ) ) {
V_295 = F_133 ( V_1 ) ;
V_211 = 0 ;
} else if ( F_37 ( V_7 ) && V_83 == V_84 ) {
V_295 = F_145 ( V_285 ) ;
V_211 = V_325 ;
} else if ( F_36 ( V_7 ) && V_83 == V_84 ) {
V_295 = F_144 ( V_285 ) ;
V_211 = V_326 ;
} else {
V_295 = F_143 ( V_285 ) ;
V_211 = V_327 | V_328 ;
}
F_23 ( L_48 , V_295 ) ;
* V_193 = ( * V_193 & ~ V_211 ) | V_295 ;
}
static bool
F_148 ( struct V_1 * V_1 ,
T_1 V_329 ,
T_2 V_330 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
enum V_83 V_83 = V_3 -> V_83 ;
int V_76 ;
if ( F_33 ( V_7 ) ) {
T_1 V_331 = F_19 ( F_149 ( V_83 ) ) ;
if ( V_330 & V_332 )
V_331 |= V_333 ;
else
V_331 &= ~ V_333 ;
V_331 &= ~ V_334 ;
switch ( V_330 & V_335 ) {
case V_336 :
V_331 |= V_337 ;
break;
case V_338 :
V_331 |= V_339 ;
break;
case V_340 :
V_331 |= V_341 ;
break;
case V_342 :
V_331 |= V_343 ;
break;
}
F_43 ( F_149 ( V_83 ) , V_331 ) ;
} else if ( F_73 ( V_7 ) && ( F_37 ( V_7 ) || V_83 != V_84 ) ) {
V_329 &= ~ V_344 ;
switch ( V_330 & V_335 ) {
case V_336 :
V_329 |= V_207 ;
break;
case V_338 :
V_329 |= V_345 ;
break;
case V_340 :
V_329 |= V_346 ;
break;
case V_342 :
F_29 ( L_49 ) ;
V_329 |= V_346 ;
break;
}
} else {
V_329 &= ~ V_347 ;
switch ( V_330 & V_335 ) {
case V_336 :
V_329 |= V_209 ;
break;
case V_338 :
V_329 |= V_348 ;
break;
case V_340 :
V_329 |= V_349 ;
break;
case V_342 :
F_29 ( L_49 ) ;
V_329 |= V_349 ;
break;
}
}
F_43 ( V_1 -> V_196 , V_329 ) ;
F_67 ( V_1 -> V_196 ) ;
F_46 ( V_1 ,
V_350 ,
V_330 ) ;
if ( ( V_330 & V_335 ) !=
V_336 ) {
V_76 = F_44 ( V_1 ,
V_351 ,
V_1 -> V_285 ,
V_1 -> V_160 ) ;
if ( V_76 != V_1 -> V_160 )
return false ;
}
return true ;
}
static void F_150 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
enum V_83 V_83 = V_3 -> V_83 ;
T_1 V_262 ;
if ( ! F_33 ( V_7 ) )
return;
V_262 = F_19 ( F_149 ( V_83 ) ) ;
V_262 &= ~ V_334 ;
V_262 |= V_352 ;
F_43 ( F_149 ( V_83 ) , V_262 ) ;
if ( V_83 == V_84 )
return;
if ( F_151 ( ( F_19 ( F_152 ( V_83 ) ) & V_353 ) ,
1 ) )
F_29 ( L_50 ) ;
}
void
F_110 ( struct V_1 * V_1 )
{
struct V_195 * V_145 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_145 -> V_7 ;
int V_39 ;
T_2 V_354 ;
bool V_355 = false ;
int V_356 , V_357 ;
T_1 V_193 = V_1 -> V_193 ;
if ( F_33 ( V_7 ) )
F_153 ( V_145 ) ;
F_44 ( V_1 , V_358 ,
V_1 -> V_179 ,
V_180 ) ;
V_193 |= V_240 ;
memset ( V_1 -> V_285 , 0 , 4 ) ;
V_354 = 0xff ;
V_356 = 0 ;
V_357 = 0 ;
V_355 = false ;
for (; ; ) {
T_2 V_269 [ V_270 ] ;
F_147 ( V_1 , & V_193 ) ;
if ( ! F_148 ( V_1 , V_193 ,
V_338 |
V_332 ) )
break;
F_154 ( V_1 -> V_11 ) ;
if ( ! F_130 ( V_1 , V_269 ) ) {
F_29 ( L_51 ) ;
break;
}
if ( F_155 ( V_269 , V_1 -> V_160 ) ) {
F_23 ( L_52 ) ;
V_355 = true ;
break;
}
for ( V_39 = 0 ; V_39 < V_1 -> V_160 ; V_39 ++ )
if ( ( V_1 -> V_285 [ V_39 ] & V_293 ) == 0 )
break;
if ( V_39 == V_1 -> V_160 ) {
++ V_357 ;
if ( V_357 == 5 ) {
F_23 ( L_53 ) ;
break;
}
memset ( V_1 -> V_285 , 0 , 4 ) ;
V_356 = 0 ;
continue;
}
if ( ( V_1 -> V_285 [ 0 ] & V_275 ) == V_354 ) {
++ V_356 ;
if ( V_356 == 5 ) {
F_23 ( L_54 ) ;
break;
}
} else
V_356 = 0 ;
V_354 = V_1 -> V_285 [ 0 ] & V_275 ;
F_140 ( V_1 , V_269 ) ;
}
V_1 -> V_193 = V_193 ;
}
void
F_111 ( struct V_1 * V_1 )
{
bool V_359 = false ;
int V_360 , V_361 ;
T_1 V_193 = V_1 -> V_193 ;
V_360 = 0 ;
V_361 = 0 ;
V_359 = false ;
for (; ; ) {
T_2 V_269 [ V_270 ] ;
if ( V_361 > 5 ) {
F_29 ( L_55 ) ;
F_107 ( V_1 ) ;
break;
}
F_147 ( V_1 , & V_193 ) ;
if ( ! F_148 ( V_1 , V_193 ,
V_340 |
V_332 ) )
break;
F_156 ( V_1 -> V_11 ) ;
if ( ! F_130 ( V_1 , V_269 ) )
break;
if ( ! F_155 ( V_269 , V_1 -> V_160 ) ) {
F_110 ( V_1 ) ;
V_361 ++ ;
continue;
}
if ( F_157 ( V_269 , V_1 -> V_160 ) ) {
V_359 = true ;
break;
}
if ( V_360 > 5 ) {
F_107 ( V_1 ) ;
F_110 ( V_1 ) ;
V_360 = 0 ;
V_361 ++ ;
continue;
}
F_140 ( V_1 , V_269 ) ;
++ V_360 ;
}
F_150 ( V_1 ) ;
V_1 -> V_193 = V_193 ;
if ( V_359 )
F_23 ( L_56 ) ;
}
void F_112 ( struct V_1 * V_1 )
{
F_148 ( V_1 , V_1 -> V_193 ,
V_336 ) ;
}
static void
F_107 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_83 V_83 = V_3 -> V_83 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_157 * V_157 =
F_66 ( V_3 -> V_4 . V_4 . V_187 ) ;
T_1 V_193 = V_1 -> V_193 ;
if ( F_33 ( V_7 ) )
return;
if ( F_81 ( ( F_19 ( V_1 -> V_196 ) & V_240 ) == 0 ) )
return;
F_23 ( L_40 ) ;
if ( F_73 ( V_7 ) && ( F_37 ( V_7 ) || V_83 != V_84 ) ) {
V_193 &= ~ V_344 ;
F_43 ( V_1 -> V_196 , V_193 | V_362 ) ;
} else {
V_193 &= ~ V_347 ;
F_43 ( V_1 -> V_196 , V_193 | V_363 ) ;
}
F_67 ( V_1 -> V_196 ) ;
F_158 ( V_7 , V_157 -> V_201 ) ;
if ( F_159 ( V_7 ) &&
F_19 ( V_1 -> V_196 ) & V_210 ) {
struct V_238 * V_187 = V_3 -> V_4 . V_4 . V_187 ;
V_193 &= ~ V_210 ;
F_43 ( V_1 -> V_196 , V_193 ) ;
if ( F_81 ( V_187 == NULL ) ) {
F_67 ( V_1 -> V_196 ) ;
F_42 ( 50 ) ;
} else
F_158 ( V_7 , V_157 -> V_201 ) ;
}
V_193 &= ~ V_202 ;
F_43 ( V_1 -> V_196 , V_193 & ~ V_240 ) ;
F_67 ( V_1 -> V_196 ) ;
F_42 ( V_1 -> V_227 ) ;
}
static bool
F_160 ( struct V_1 * V_1 )
{
char V_364 [ sizeof( V_1 -> V_11 ) * 3 ] ;
if ( F_129 ( V_1 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) == 0 )
return false ;
F_161 ( V_1 -> V_11 , sizeof( V_1 -> V_11 ) ,
32 , 1 , V_364 , sizeof( V_364 ) , false ) ;
F_23 ( L_57 , V_364 ) ;
if ( V_1 -> V_11 [ V_182 ] == 0 )
return false ;
if ( ! ( V_1 -> V_11 [ V_365 ] &
V_366 ) )
return true ;
if ( V_1 -> V_11 [ V_182 ] == 0x10 )
return true ;
if ( F_129 ( V_1 , V_367 ,
V_1 -> V_368 ,
V_369 ) == 0 )
return false ;
return true ;
}
static void
F_162 ( struct V_1 * V_1 )
{
T_5 V_370 [ 3 ] ;
if ( ! ( V_1 -> V_11 [ V_371 ] & V_372 ) )
return;
F_51 ( V_1 ) ;
if ( F_129 ( V_1 , V_373 , V_370 , 3 ) )
F_23 ( L_58 ,
V_370 [ 0 ] , V_370 [ 1 ] , V_370 [ 2 ] ) ;
if ( F_129 ( V_1 , V_374 , V_370 , 3 ) )
F_23 ( L_59 ,
V_370 [ 0 ] , V_370 [ 1 ] , V_370 [ 2 ] ) ;
F_53 ( V_1 , false ) ;
}
static bool
F_163 ( struct V_1 * V_1 , T_5 * V_375 )
{
int V_76 ;
V_76 = F_129 ( V_1 ,
V_376 ,
V_375 , 1 ) ;
if ( ! V_76 )
return false ;
return true ;
}
static void
F_164 ( struct V_1 * V_1 )
{
F_46 ( V_1 , V_377 , V_378 ) ;
}
void
F_165 ( struct V_1 * V_1 )
{
struct V_144 * V_144 = & F_2 ( V_1 ) -> V_4 ;
T_5 V_375 ;
T_5 V_269 [ V_270 ] ;
if ( ! V_144 -> V_379 )
return;
if ( F_81 ( ! V_144 -> V_4 . V_187 ) )
return;
if ( ! F_130 ( V_1 , V_269 ) ) {
F_107 ( V_1 ) ;
return;
}
if ( ! F_160 ( V_1 ) ) {
F_107 ( V_1 ) ;
return;
}
if ( V_1 -> V_11 [ V_182 ] >= 0x11 &&
F_163 ( V_1 , & V_375 ) ) {
F_46 ( V_1 ,
V_376 ,
V_375 ) ;
if ( V_375 & V_380 )
F_164 ( V_1 ) ;
if ( V_375 & ( V_381 | V_382 ) )
F_70 ( L_60 ) ;
}
if ( ! F_157 ( V_269 , V_1 -> V_160 ) ) {
F_23 ( L_61 ,
F_166 ( & V_144 -> V_4 ) ) ;
F_110 ( V_1 ) ;
F_111 ( V_1 ) ;
F_112 ( V_1 ) ;
}
}
static enum V_383
F_167 ( struct V_1 * V_1 )
{
T_2 * V_11 = V_1 -> V_11 ;
bool V_384 ;
T_2 type ;
if ( ! F_160 ( V_1 ) )
return V_385 ;
if ( ! ( V_11 [ V_365 ] & V_366 ) )
return V_386 ;
V_384 = ! ! ( V_1 -> V_368 [ 0 ] & V_387 ) ;
if ( V_384 ) {
T_2 V_388 ;
if ( ! F_129 ( V_1 , V_389 ,
& V_388 , 1 ) )
return V_390 ;
return F_168 ( V_388 ) ? V_386
: V_385 ;
}
if ( F_169 ( & V_1 -> V_116 ) )
return V_386 ;
type = V_1 -> V_368 [ 0 ] & V_391 ;
if ( type == V_392 || type == V_393 )
return V_390 ;
F_23 ( L_62 ) ;
return V_385 ;
}
static enum V_383
F_170 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_383 V_68 ;
if ( F_1 ( V_1 ) ) {
V_68 = F_171 ( V_7 ) ;
if ( V_68 == V_390 )
V_68 = V_386 ;
return V_68 ;
}
if ( ! F_172 ( V_44 , V_3 ) )
return V_385 ;
return F_167 ( V_1 ) ;
}
static enum V_383
F_173 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_1 V_394 ;
if ( F_1 ( V_1 ) ) {
enum V_383 V_68 ;
V_68 = F_171 ( V_7 ) ;
if ( V_68 == V_390 )
V_68 = V_386 ;
return V_68 ;
}
switch ( V_3 -> V_83 ) {
case V_395 :
V_394 = V_396 ;
break;
case V_397 :
V_394 = V_398 ;
break;
case V_399 :
V_394 = V_400 ;
break;
default:
return V_390 ;
}
if ( ( F_19 ( V_401 ) & V_394 ) == 0 )
return V_385 ;
return F_167 ( V_1 ) ;
}
static struct V_402 *
F_174 ( struct V_8 * V_9 , struct V_115 * V_116 )
{
struct V_22 * V_22 = F_12 ( V_9 ) ;
if ( V_22 -> V_402 ) {
struct V_402 * V_402 ;
int V_403 ;
if ( F_175 ( V_22 -> V_402 ) )
return NULL ;
V_403 = ( V_22 -> V_402 -> V_404 + 1 ) * V_405 ;
V_402 = F_176 ( V_22 -> V_402 , V_403 , V_406 ) ;
if ( ! V_402 )
return NULL ;
return V_402 ;
}
return F_177 ( V_9 , V_116 ) ;
}
static int
F_178 ( struct V_8 * V_9 , struct V_115 * V_116 )
{
struct V_22 * V_22 = F_12 ( V_9 ) ;
if ( V_22 -> V_402 ) {
if ( F_175 ( V_22 -> V_402 ) )
return 0 ;
return F_179 ( V_9 ,
V_22 -> V_402 ) ;
}
return F_180 ( V_9 , V_116 ) ;
}
static enum V_383
F_181 ( struct V_8 * V_9 , bool V_407 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_144 * V_144 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_383 V_68 ;
struct V_402 * V_402 = NULL ;
V_1 -> V_200 = false ;
if ( F_38 ( V_7 ) )
V_68 = F_170 ( V_1 ) ;
else
V_68 = F_173 ( V_1 ) ;
if ( V_68 != V_386 )
return V_68 ;
F_162 ( V_1 ) ;
if ( V_1 -> V_408 != V_409 ) {
V_1 -> V_200 = ( V_1 -> V_408 == V_410 ) ;
} else {
V_402 = F_174 ( V_9 , & V_1 -> V_116 ) ;
if ( V_402 ) {
V_1 -> V_200 = F_182 ( V_402 ) ;
F_183 ( V_402 ) ;
}
}
if ( V_144 -> type != V_5 )
V_144 -> type = V_411 ;
return V_386 ;
}
static int F_184 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_22 * V_22 = F_12 ( V_9 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
int V_76 ;
V_76 = F_178 ( V_9 , & V_1 -> V_116 ) ;
if ( V_76 )
return V_76 ;
if ( F_1 ( V_1 ) && V_22 -> V_24 . V_23 ) {
struct V_20 * V_21 ;
V_21 = F_185 ( V_7 ,
V_22 -> V_24 . V_23 ) ;
if ( V_21 ) {
F_186 ( V_9 , V_21 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_187 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_402 * V_402 ;
bool V_200 = false ;
V_402 = F_174 ( V_9 , & V_1 -> V_116 ) ;
if ( V_402 ) {
V_200 = F_182 ( V_402 ) ;
F_183 ( V_402 ) ;
}
return V_200 ;
}
static int
F_188 ( struct V_8 * V_9 ,
struct V_412 * V_413 ,
T_6 V_262 )
{
struct V_43 * V_44 = V_9 -> V_7 -> V_45 ;
struct V_22 * V_22 = F_12 ( V_9 ) ;
struct V_144 * V_144 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_144 -> V_4 ) ;
int V_76 ;
V_76 = F_189 ( & V_9 -> V_4 , V_413 , V_262 ) ;
if ( V_76 )
return V_76 ;
if ( V_413 == V_44 -> V_414 ) {
int V_39 = V_262 ;
bool V_200 ;
if ( V_39 == V_1 -> V_408 )
return 0 ;
V_1 -> V_408 = V_39 ;
if ( V_39 == V_409 )
V_200 = F_187 ( V_9 ) ;
else
V_200 = ( V_39 == V_410 ) ;
if ( V_200 == V_1 -> V_200 )
return 0 ;
V_1 -> V_200 = V_200 ;
goto V_69;
}
if ( V_413 == V_44 -> V_415 ) {
bool V_416 = V_1 -> V_173 ;
T_1 V_417 = V_1 -> V_174 ;
switch ( V_262 ) {
case V_418 :
V_1 -> V_173 = true ;
break;
case V_419 :
V_1 -> V_173 = false ;
V_1 -> V_174 = 0 ;
break;
case V_420 :
V_1 -> V_173 = false ;
V_1 -> V_174 = V_175 ;
break;
default:
return - V_421 ;
}
if ( V_416 == V_1 -> V_173 &&
V_417 == V_1 -> V_174 )
return 0 ;
goto V_69;
}
if ( F_1 ( V_1 ) &&
V_413 == V_9 -> V_7 -> V_225 . V_422 ) {
if ( V_262 == V_423 ) {
F_23 ( L_63 ) ;
return - V_421 ;
}
if ( V_22 -> V_24 . V_168 == V_262 ) {
return 0 ;
}
V_22 -> V_24 . V_168 = V_262 ;
goto V_69;
}
return - V_421 ;
V_69:
if ( V_144 -> V_4 . V_187 )
F_190 ( V_144 -> V_4 . V_187 ) ;
return 0 ;
}
static void
F_191 ( struct V_8 * V_9 )
{
struct V_22 * V_22 = F_12 ( V_9 ) ;
if ( ! F_192 ( V_22 -> V_402 ) )
F_183 ( V_22 -> V_402 ) ;
if ( V_9 -> V_424 == V_425 )
F_193 ( & V_22 -> V_24 ) ;
F_194 ( V_9 ) ;
F_195 ( V_9 ) ;
F_183 ( V_9 ) ;
}
void F_196 ( struct V_195 * V_145 )
{
struct V_2 * V_3 = F_113 ( V_145 ) ;
struct V_1 * V_1 = & V_3 -> V_426 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
F_197 ( & V_1 -> V_116 ) ;
F_198 ( V_145 ) ;
if ( F_1 ( V_1 ) ) {
F_199 ( & V_1 -> V_230 ) ;
F_85 ( & V_7 -> V_225 . V_226 ) ;
F_80 ( V_1 ) ;
F_86 ( & V_7 -> V_225 . V_226 ) ;
}
F_183 ( V_3 ) ;
}
static void
F_200 ( struct V_144 * V_144 )
{
struct V_1 * V_1 = F_5 ( & V_144 -> V_4 ) ;
F_165 ( V_1 ) ;
}
int
F_201 ( struct V_238 * V_187 )
{
struct V_6 * V_7 = V_187 -> V_7 ;
struct V_144 * V_144 ;
struct V_1 * V_1 ;
F_202 (dev, crtc, intel_encoder) {
V_1 = F_5 ( & V_144 -> V_4 ) ;
if ( V_144 -> type == V_411 ||
V_144 -> type == V_5 )
return V_1 -> V_196 ;
}
return - 1 ;
}
bool F_203 ( struct V_6 * V_7 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_427 * V_428 ;
int V_39 ;
if ( ! V_44 -> V_170 . V_429 )
return false ;
for ( V_39 = 0 ; V_39 < V_44 -> V_170 . V_429 ; V_39 ++ ) {
V_428 = V_44 -> V_170 . V_430 + V_39 ;
if ( V_428 -> V_431 == V_432 &&
V_428 -> V_433 == V_434 )
return true ;
}
return false ;
}
static void
F_204 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_22 * V_22 = F_12 ( V_9 ) ;
F_205 ( V_9 ) ;
F_206 ( V_9 ) ;
V_1 -> V_173 = true ;
if ( F_1 ( V_1 ) ) {
F_207 ( V_9 -> V_7 ) ;
F_208 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_225 . V_422 ,
V_435 ) ;
V_22 -> V_24 . V_168 = V_435 ;
}
}
static void
F_209 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_436 * V_89 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_436 V_437 , V_170 , V_438 , V_439 ;
T_3 V_440 , V_441 , V_442 , V_222 ;
int V_443 , V_444 , V_445 , V_446 ;
if ( F_38 ( V_7 ) ) {
V_443 = V_63 ;
V_444 = V_447 ;
V_445 = V_448 ;
V_446 = V_449 ;
} else {
V_443 = V_62 ;
V_444 = V_450 ;
V_445 = V_451 ;
V_446 = V_452 ;
}
V_222 = F_79 ( V_1 ) ;
F_43 ( V_443 , V_222 ) ;
V_440 = F_19 ( V_444 ) ;
V_441 = F_19 ( V_445 ) ;
V_442 = F_19 ( V_446 ) ;
V_437 . V_453 = ( V_440 & V_454 ) >>
V_455 ;
V_437 . V_456 = ( V_440 & V_457 ) >>
V_458 ;
V_437 . V_459 = ( V_441 & V_460 ) >>
V_461 ;
V_437 . V_462 = ( V_441 & V_463 ) >>
V_464 ;
V_437 . V_465 = ( ( V_442 & V_466 ) >>
V_467 ) * 1000 ;
F_23 ( L_64 ,
V_437 . V_453 , V_437 . V_456 , V_437 . V_459 , V_437 . V_462 , V_437 . V_465 ) ;
V_170 = V_44 -> V_170 . V_468 ;
V_438 . V_453 = 210 * 10 ;
V_438 . V_456 = 50 * 10 ;
V_438 . V_459 = 50 * 10 ;
V_438 . V_462 = 500 * 10 ;
V_438 . V_465 = ( 510 + 100 ) * 10 ;
F_23 ( L_65 ,
V_170 . V_453 , V_170 . V_456 , V_170 . V_459 , V_170 . V_462 , V_170 . V_465 ) ;
#define F_210 ( T_7 ) final.field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_210 ( V_453 ) ;
F_210 ( V_456 ) ;
F_210 ( V_459 ) ;
F_210 ( V_462 ) ;
F_210 ( V_465 ) ;
#undef F_210
#define F_211 ( T_7 ) (DIV_ROUND_UP(final.field, 10))
V_1 -> V_224 = F_211 ( V_453 ) ;
V_1 -> V_236 = F_211 ( V_456 ) ;
V_1 -> V_237 = F_211 ( V_459 ) ;
V_1 -> V_227 = F_211 ( V_462 ) ;
V_1 -> V_232 = F_211 ( V_465 ) ;
#undef F_211
F_23 ( L_66 ,
V_1 -> V_224 , V_1 -> V_227 ,
V_1 -> V_232 ) ;
F_23 ( L_67 ,
V_1 -> V_236 , V_1 -> V_237 ) ;
if ( V_89 )
* V_89 = V_439 ;
}
static void
F_212 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_436 * V_469 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_440 , V_441 , V_442 , V_470 = 0 ;
int div = F_38 ( V_7 ) ? F_40 ( V_7 ) : F_17 ( V_7 ) ;
int V_444 , V_445 , V_446 ;
if ( F_38 ( V_7 ) ) {
V_444 = V_447 ;
V_445 = V_448 ;
V_446 = V_449 ;
} else {
V_444 = V_450 ;
V_445 = V_451 ;
V_446 = V_452 ;
}
V_440 = ( V_469 -> V_453 << V_455 ) |
( V_469 -> V_456 << V_458 ) ;
V_441 = ( V_469 -> V_459 << V_461 ) |
( V_469 -> V_462 << V_464 ) ;
V_442 = ( ( 100 * div ) / 2 - 1 ) << V_471 ;
V_442 |= ( F_39 ( V_469 -> V_465 , 1000 )
<< V_467 ) ;
if ( F_18 ( V_7 ) ) {
V_470 = F_19 ( V_444 ) & 0xc0000000 ;
} else if ( F_159 ( V_7 ) || F_73 ( V_7 ) ) {
if ( F_2 ( V_1 ) -> V_83 == V_84 )
V_470 = V_472 ;
else
V_470 = V_473 ;
}
V_440 |= V_470 ;
F_43 ( V_444 , V_440 ) ;
F_43 ( V_445 , V_441 ) ;
F_43 ( V_446 , V_442 ) ;
F_23 ( L_68 ,
F_19 ( V_444 ) ,
F_19 ( V_445 ) ,
F_19 ( V_446 ) ) ;
}
static bool F_213 ( struct V_1 * V_1 ,
struct V_22 * V_22 )
{
struct V_8 * V_9 = & V_22 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_20 * V_23 = NULL ;
struct V_436 V_474 = { 0 } ;
bool V_475 ;
struct V_20 * V_476 ;
struct V_402 * V_402 ;
if ( ! F_1 ( V_1 ) )
return true ;
F_209 ( V_7 , V_1 , & V_474 ) ;
F_51 ( V_1 ) ;
V_475 = F_160 ( V_1 ) ;
F_53 ( V_1 , false ) ;
if ( V_475 ) {
if ( V_1 -> V_11 [ V_182 ] >= 0x11 )
V_44 -> V_477 =
V_1 -> V_11 [ V_478 ] &
V_479 ;
} else {
F_214 ( L_69 ) ;
return false ;
}
F_212 ( V_7 , V_1 ,
& V_474 ) ;
F_51 ( V_1 ) ;
V_402 = F_177 ( V_9 , & V_1 -> V_116 ) ;
if ( V_402 ) {
if ( F_215 ( V_9 , V_402 ) ) {
F_216 ( V_9 ,
V_402 ) ;
F_217 ( V_9 , V_402 ) ;
} else {
F_183 ( V_402 ) ;
V_402 = F_218 ( - V_421 ) ;
}
} else {
V_402 = F_218 ( - V_480 ) ;
}
V_22 -> V_402 = V_402 ;
F_219 (scan, &connector->probed_modes, head) {
if ( ( V_476 -> type & V_481 ) ) {
V_23 = F_185 ( V_7 , V_476 ) ;
break;
}
}
if ( ! V_23 && V_44 -> V_170 . V_482 ) {
V_23 = F_185 ( V_7 ,
V_44 -> V_170 . V_482 ) ;
if ( V_23 )
V_23 -> type |= V_481 ;
}
F_53 ( V_1 , false ) ;
F_220 ( & V_22 -> V_24 , V_23 ) ;
F_221 ( V_9 ) ;
return true ;
}
bool
F_222 ( struct V_2 * V_3 ,
struct V_22 * V_22 )
{
struct V_8 * V_9 = & V_22 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_426 ;
struct V_144 * V_144 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_144 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
enum V_83 V_83 = V_3 -> V_83 ;
const char * V_134 = NULL ;
int type , error ;
V_1 -> V_193 = F_19 ( V_1 -> V_196 ) ;
V_1 -> V_159 = V_22 ;
type = V_483 ;
switch ( V_83 ) {
case V_84 :
type = V_425 ;
break;
case V_397 :
if ( F_18 ( V_7 ) )
type = V_425 ;
break;
case V_399 :
if ( F_38 ( V_7 ) && F_203 ( V_7 ) )
type = V_425 ;
break;
default:
break;
}
if ( type == V_425 )
V_144 -> type = V_5 ;
F_23 ( L_70 ,
type == V_425 ? L_71 : L_72 ,
F_223 ( V_83 ) ) ;
F_224 ( V_7 , V_9 , & V_484 , type ) ;
F_225 ( V_9 , & V_485 ) ;
V_9 -> V_486 = true ;
V_9 -> V_487 = 0 ;
F_226 ( & V_1 -> V_230 ,
F_83 ) ;
F_227 ( V_22 , V_144 ) ;
F_228 ( V_9 ) ;
if ( F_33 ( V_7 ) )
V_22 -> V_488 = V_489 ;
else
V_22 -> V_488 = V_490 ;
V_1 -> V_67 = V_1 -> V_196 + 0x10 ;
if ( F_33 ( V_7 ) ) {
switch ( V_3 -> V_83 ) {
case V_84 :
V_1 -> V_67 = V_491 ;
break;
case V_395 :
V_1 -> V_67 = V_492 ;
break;
case V_397 :
V_1 -> V_67 = V_493 ;
break;
case V_399 :
V_1 -> V_67 = V_494 ;
break;
default:
F_229 () ;
}
}
switch ( V_83 ) {
case V_84 :
V_144 -> V_495 = V_496 ;
V_134 = L_73 ;
break;
case V_395 :
V_144 -> V_495 = V_497 ;
V_134 = L_74 ;
break;
case V_397 :
V_144 -> V_495 = V_498 ;
V_134 = L_75 ;
break;
case V_399 :
V_144 -> V_495 = V_499 ;
V_134 = L_76 ;
break;
default:
F_229 () ;
}
error = F_50 ( V_1 , V_22 , V_134 ) ;
F_8 ( error , L_77 ,
error , F_223 ( V_83 ) ) ;
if ( ! F_213 ( V_1 , V_22 ) ) {
F_197 ( & V_1 -> V_116 ) ;
if ( F_1 ( V_1 ) ) {
F_199 ( & V_1 -> V_230 ) ;
F_85 ( & V_7 -> V_225 . V_226 ) ;
F_80 ( V_1 ) ;
F_86 ( & V_7 -> V_225 . V_226 ) ;
}
F_194 ( V_9 ) ;
F_195 ( V_9 ) ;
return false ;
}
F_204 ( V_1 , V_9 ) ;
if ( F_55 ( V_7 ) && ! F_230 ( V_7 ) ) {
T_3 V_331 = F_19 ( V_500 ) ;
F_43 ( V_500 , ( V_331 & ~ 0xf ) | 0xd ) ;
}
return true ;
}
void
F_231 ( struct V_6 * V_7 , int V_196 , enum V_83 V_83 )
{
struct V_2 * V_3 ;
struct V_144 * V_144 ;
struct V_195 * V_145 ;
struct V_22 * V_22 ;
V_3 = F_232 ( sizeof( struct V_2 ) , V_406 ) ;
if ( ! V_3 )
return;
V_22 = F_232 ( sizeof( struct V_22 ) , V_406 ) ;
if ( ! V_22 ) {
F_183 ( V_3 ) ;
return;
}
V_144 = & V_3 -> V_4 ;
V_145 = & V_144 -> V_4 ;
F_233 ( V_7 , & V_144 -> V_4 , & V_501 ,
V_502 ) ;
F_234 ( & V_144 -> V_4 , & V_503 ) ;
V_144 -> V_504 = F_57 ;
V_144 -> V_505 = F_109 ;
V_144 -> V_506 = F_116 ;
V_144 -> V_507 = F_106 ;
V_144 -> V_508 = F_108 ;
V_144 -> V_488 = F_100 ;
V_144 -> V_509 = F_105 ;
if ( F_18 ( V_7 ) )
V_144 -> V_510 = F_123 ;
V_3 -> V_83 = V_83 ;
V_3 -> V_426 . V_196 = V_196 ;
V_144 -> type = V_411 ;
V_144 -> V_511 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_144 -> V_512 = false ;
V_144 -> V_513 = F_200 ;
if ( ! F_222 ( V_3 , V_22 ) ) {
F_198 ( V_145 ) ;
F_183 ( V_3 ) ;
F_183 ( V_22 ) ;
}
}
