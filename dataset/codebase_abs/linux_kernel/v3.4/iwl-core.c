static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
T_1 V_7 = 0 ;
T_2 V_8 = F_2 ( V_2 ) . V_8 ;
T_2 V_9 = F_2 ( V_2 ) . V_9 ;
V_4 -> V_10 = 0 ;
memset ( & V_4 -> V_11 , 0 , sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_12 = true ;
if ( F_3 ( V_2 ) -> V_13 &&
F_3 ( V_2 ) -> V_13 -> V_14 )
V_4 -> V_10 |= V_15 ;
V_4 -> V_10 |= V_16 ;
V_7 = V_17 ;
if ( F_2 ( V_2 ) . V_18 & F_4 ( V_6 ) ) {
V_4 -> V_10 |= V_19 ;
V_4 -> V_10 |= V_20 ;
V_4 -> V_11 . V_21 [ 4 ] = 0x01 ;
V_7 = V_22 ;
}
if ( V_23 . V_24 )
V_4 -> V_10 |= V_25 ;
V_4 -> V_26 = V_27 ;
V_4 -> V_28 = V_29 ;
V_4 -> V_11 . V_21 [ 0 ] = 0xFF ;
if ( V_8 >= 2 )
V_4 -> V_11 . V_21 [ 1 ] = 0xFF ;
if ( V_8 >= 3 )
V_4 -> V_11 . V_21 [ 2 ] = 0xFF ;
V_7 *= V_8 ;
F_5 ( V_7 & ~ V_30 ) ;
V_4 -> V_11 . V_31 = F_6 ( V_7 ) ;
V_4 -> V_11 . V_32 = V_33 ;
if ( V_9 != V_8 ) {
V_4 -> V_11 . V_32 |= V_34 ;
V_4 -> V_11 . V_32 |= ( ( V_9 - 1 ) <<
V_35 ) ;
}
}
int F_7 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_40 * V_42 ;
struct V_43 * V_44 ;
int V_45 = 0 ;
T_3 V_46 = V_47 ;
if ( V_2 -> V_48 [ V_49 ] . V_50 ||
V_2 -> V_48 [ V_51 ] . V_50 ) {
F_8 ( V_2 , L_1 ) ;
F_9 ( V_52 , & V_2 -> V_53 ) ;
return 0 ;
}
V_41 = F_10 ( V_2 -> V_54 ,
sizeof( struct V_40 ) , V_55 ) ;
if ( ! V_41 )
return - V_56 ;
V_44 = F_10 ( V_57 , sizeof( struct V_43 ) ,
V_55 ) ;
if ( ! V_44 ) {
F_11 ( V_41 ) ;
return - V_56 ;
}
V_39 = & V_2 -> V_48 [ V_51 ] ;
V_39 -> V_41 = & V_41 [ F_12 ( V_58 ) ] ;
V_39 -> V_59 = & V_44 [ V_60 ] ;
V_39 -> V_50 = V_57 - V_60 ;
if ( F_2 ( V_2 ) . V_61 & V_62 )
F_1 ( V_2 , & V_39 -> V_63 ,
V_51 ) ;
V_39 = & V_2 -> V_48 [ V_49 ] ;
V_39 -> V_41 = V_41 ;
V_39 -> V_59 = V_44 ;
V_39 -> V_50 = V_57 ;
if ( F_2 ( V_2 ) . V_61 & V_62 )
F_1 ( V_2 , & V_39 -> V_63 ,
V_49 ) ;
V_2 -> V_64 = V_41 ;
V_2 -> V_65 = V_44 ;
for ( V_45 = 0 ; V_45 < V_2 -> V_54 ; V_45 ++ ) {
V_37 = & V_2 -> V_66 [ V_45 ] ;
if ( ! F_13 ( V_37 ) )
continue;
V_39 = & V_2 -> V_48 [ V_37 -> V_6 ] ;
V_42 = & V_39 -> V_41 [ V_39 -> V_67 ++ ] ;
V_42 -> V_68 =
F_14 ( V_37 -> V_69 , V_37 -> V_6 ) ;
V_42 -> V_70 = V_37 -> V_71 ;
V_42 -> V_72 = 0xff ;
V_42 -> V_73 = V_37 -> V_69 ;
if ( F_13 ( V_37 ) ) {
if ( ! ( V_37 -> V_74 & V_75 ) )
V_42 -> V_74 |= V_76 ;
if ( ! ( V_37 -> V_74 & V_77 ) )
V_42 -> V_74 |= V_78 ;
if ( V_37 -> V_74 & V_79 )
V_42 -> V_74 |= V_80 ;
V_42 -> V_74 |= V_37 -> V_81 ;
if ( V_37 -> V_71 > V_46 )
V_46 = V_37 -> V_71 ;
} else {
V_42 -> V_74 |= V_82 ;
}
F_8 ( V_2 , L_2 ,
V_37 -> V_69 , V_42 -> V_68 ,
F_15 ( V_37 ) ? L_3 : L_4 ,
V_42 -> V_74 & V_82 ?
L_5 : L_6 ,
V_42 -> V_74 ) ;
}
V_2 -> V_83 = V_46 ;
V_2 -> V_84 = V_46 ;
V_2 -> V_85 = V_46 ;
if ( ( V_2 -> V_48 [ V_51 ] . V_67 == 0 ) &&
F_2 ( V_2 ) . V_61 & V_86 ) {
F_16 ( V_2 , L_7
L_8 ,
F_17 ( V_2 ) -> V_87 ) ;
F_2 ( V_2 ) . V_61 &= ~ V_86 ;
}
F_16 ( V_2 , L_9 ,
V_2 -> V_48 [ V_49 ] . V_67 ,
V_2 -> V_48 [ V_51 ] . V_67 ) ;
F_9 ( V_52 , & V_2 -> V_53 ) ;
return 0 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_64 ) ;
F_11 ( V_2 -> V_65 ) ;
F_19 ( V_52 , & V_2 -> V_53 ) ;
}
static bool F_20 ( struct V_1 * V_2 ,
enum V_5 V_6 ,
T_1 V_69 , T_2 V_88 )
{
const struct V_36 * V_89 ;
V_89 = F_21 ( V_2 , V_6 , V_69 ) ;
if ( ! F_13 ( V_89 ) )
return false ;
if ( V_88 == V_90 )
return ! ( V_89 -> V_81 &
V_91 ) ;
else if ( V_88 == V_92 )
return ! ( V_89 -> V_81 &
V_93 ) ;
return false ;
}
bool F_22 ( struct V_1 * V_2 ,
struct V_94 * V_95 ,
struct V_3 * V_63 )
{
if ( ! V_95 -> V_96 . V_97 || ! V_95 -> V_96 . V_98 )
return false ;
if ( V_63 && ! V_63 -> V_12 )
return false ;
#ifdef F_23
if ( V_2 -> V_99 )
return false ;
#endif
return F_20 ( V_2 , V_2 -> V_6 ,
F_24 ( V_95 -> V_100 . V_69 ) ,
V_95 -> V_96 . V_88 ) ;
}
static T_1 F_25 ( T_1 V_101 , T_1 V_102 )
{
T_1 V_103 ;
T_1 V_104 ;
if ( ! V_101 )
return V_105 ;
V_104 = ( V_101 + V_102 ) / V_102 ;
V_103 = V_101 / V_104 ;
if ( ! V_103 )
V_103 = V_102 ;
return V_103 ;
}
int F_26 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
T_4 V_106 ;
T_5 V_107 , V_108 ;
struct V_109 * V_110 = NULL ;
T_1 V_111 ;
struct V_112 * V_113 = V_95 -> V_113 ;
V_110 = & V_2 -> V_114 -> V_110 ;
F_27 ( & V_2 -> V_115 ) ;
memset ( & V_95 -> V_116 , 0 , sizeof( struct V_117 ) ) ;
V_95 -> V_116 . V_118 = F_28 ( V_2 -> V_118 ) ;
V_95 -> V_116 . V_119 = F_6 ( V_110 -> V_119 ) ;
V_111 = V_113 ? V_113 -> V_120 . V_111 : 0 ;
V_95 -> V_116 . V_121 = 0 ;
if ( V_95 -> V_122 == V_123 &&
( ! V_95 -> V_113 || V_95 -> V_113 -> type != V_124 ) &&
F_29 ( V_2 , V_125 ) &&
V_2 -> V_126 [ V_125 ] . V_113 &&
V_2 -> V_126 [ V_125 ] . V_113 -> V_120 . V_111 ) {
V_95 -> V_116 . V_127 =
V_2 -> V_126 [ V_125 ] . V_116 . V_127 ;
V_111 = F_24 ( V_95 -> V_116 . V_127 ) ;
} else if ( V_95 -> V_122 == V_125 &&
F_29 ( V_2 , V_123 ) &&
V_2 -> V_126 [ V_123 ] . V_113 &&
V_2 -> V_126 [ V_123 ] . V_113 -> V_120 . V_111 &&
( ! F_30 ( V_95 ) || ! V_95 -> V_113 ||
! V_95 -> V_113 -> V_120 . V_111 ) ) {
V_95 -> V_116 . V_127 =
V_2 -> V_126 [ V_123 ] . V_116 . V_127 ;
V_111 = F_24 ( V_95 -> V_116 . V_127 ) ;
} else {
V_111 = F_25 ( V_111 ,
V_128 * V_129 ) ;
V_95 -> V_116 . V_127 = F_6 ( V_111 ) ;
}
V_95 -> V_111 = V_111 ;
V_106 = V_2 -> V_118 ;
V_107 = V_111 * V_129 ;
V_108 = F_31 ( V_106 , V_107 ) ;
V_95 -> V_116 . V_130 = F_32 ( V_107 - V_108 ) ;
V_95 -> V_116 . V_131 = V_113 ? ( V_113 -> V_120 . V_131 ? : 1 ) : 1 ;
F_33 ( V_2 ,
L_10 ,
F_24 ( V_95 -> V_116 . V_127 ) ,
F_34 ( V_95 -> V_116 . V_130 ) ,
F_24 ( V_95 -> V_116 . V_121 ) ) ;
return F_35 ( V_2 , V_95 -> V_132 ,
V_133 , sizeof( V_95 -> V_116 ) , & V_95 -> V_116 ) ;
}
void F_36 ( struct V_1 * V_2 , struct V_94 * V_95 ,
int V_134 )
{
struct V_135 * V_136 = & V_95 -> V_100 ;
if ( V_134 )
V_136 -> V_137 &= ~ V_138 ;
else
V_136 -> V_137 |= V_138 ;
}
int F_37 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
struct V_135 * V_136 = & V_95 -> V_100 ;
T_6 V_139 = 0 ;
if ( V_136 -> V_74 & V_140 ) {
if ( V_136 -> V_74 & V_141 ) {
F_38 ( V_2 , L_11 ) ;
V_139 |= F_4 ( 0 ) ;
}
if ( V_136 -> V_74 & V_142 ) {
F_38 ( V_2 , L_12 ) ;
V_139 |= F_4 ( 1 ) ;
}
} else {
if ( ! ( V_136 -> V_74 & V_143 ) ) {
F_38 ( V_2 , L_13 ) ;
V_139 |= F_4 ( 2 ) ;
}
if ( V_136 -> V_74 & V_144 ) {
F_38 ( V_2 , L_14 ) ;
V_139 |= F_4 ( 3 ) ;
}
}
if ( ( V_136 -> V_145 [ 0 ] | V_136 -> V_146 [ 0 ] ) & 0x1 ) {
F_38 ( V_2 , L_15 ) ;
V_139 |= F_4 ( 4 ) ;
}
if ( ( V_136 -> V_147 & V_148 ) == 0 &&
( V_136 -> V_149 & V_150 ) == 0 ) {
F_38 ( V_2 , L_16 ) ;
V_139 |= F_4 ( 5 ) ;
}
if ( F_24 ( V_136 -> V_151 ) > 2007 ) {
F_38 ( V_2 , L_17 ) ;
V_139 |= F_4 ( 6 ) ;
}
if ( ( V_136 -> V_74 & ( V_144 | V_143 ) )
== ( V_144 | V_143 ) ) {
F_38 ( V_2 , L_18 ) ;
V_139 |= F_4 ( 7 ) ;
}
if ( ( V_136 -> V_74 & ( V_144 | V_152 ) )
== ( V_144 | V_152 ) ) {
F_38 ( V_2 , L_19 ) ;
V_139 |= F_4 ( 8 ) ;
}
if ( ( V_136 -> V_74 & ( V_152 |
V_153 ) ) ==
V_153 ) {
F_38 ( V_2 , L_20 ) ;
V_139 |= F_4 ( 9 ) ;
}
if ( V_136 -> V_69 == 0 ) {
F_38 ( V_2 , L_21 ) ;
V_139 |= F_4 ( 10 ) ;
}
F_39 ( V_139 , L_22 ,
V_139 , F_24 ( V_136 -> V_69 ) ) ;
return V_139 ? - V_154 : 0 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
const struct V_135 * V_100 = & V_95 -> V_100 ;
const struct V_135 * V_155 = & V_95 -> V_155 ;
#define F_41 ( T_7 ) \
if ((cond)) { \
IWL_DEBUG_INFO(priv, "need full RXON - " #cond "\n"); \
return 1; \
}
#define F_42 ( T_8 , T_9 ) \
if ((c1) != (c2)) { \
IWL_DEBUG_INFO(priv, "need full RXON - " \
#c1 " != " #c2 " - %d != %d\n", \
(c1), (c2)); \
return 1; \
}
F_41 ( ! F_30 ( V_95 ) ) ;
F_41 ( F_43 ( V_100 -> V_146 , V_155 -> V_146 ) ) ;
F_41 ( F_43 ( V_100 -> V_145 , V_155 -> V_145 ) ) ;
F_41 ( F_43 ( V_100 -> V_156 ,
V_155 -> V_156 ) ) ;
F_42 ( V_100 -> V_157 , V_155 -> V_157 ) ;
F_42 ( V_100 -> V_69 , V_155 -> V_69 ) ;
F_42 ( V_100 -> V_158 , V_155 -> V_158 ) ;
F_42 ( V_100 -> V_159 ,
V_155 -> V_159 ) ;
F_42 ( V_100 -> V_160 ,
V_155 -> V_160 ) ;
F_42 ( V_100 -> V_161 ,
V_155 -> V_161 ) ;
F_42 ( V_100 -> V_151 , V_155 -> V_151 ) ;
F_42 ( V_100 -> V_74 & V_140 ,
V_155 -> V_74 & V_140 ) ;
F_42 ( V_100 -> V_137 & V_162 ,
V_155 -> V_137 & V_162 ) ;
#undef F_41
#undef F_42
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_163 * V_164 ,
struct V_94 * V_95 )
{
struct V_135 * V_136 = & V_95 -> V_100 ;
if ( ! V_95 -> V_96 . V_97 ) {
V_136 -> V_74 &= ~ ( V_165 |
V_166 |
V_167 |
V_168 ) ;
return;
}
V_136 -> V_74 |= F_32 ( V_95 -> V_96 . V_169 << V_170 ) ;
V_136 -> V_74 &= ~ ( V_165 |
V_166 ) ;
if ( F_22 ( V_2 , V_95 , NULL ) ) {
if ( V_95 -> V_96 . V_169 == V_171 ) {
V_136 -> V_74 |= V_172 ;
switch ( V_95 -> V_96 . V_88 ) {
case V_90 :
V_136 -> V_74 &= ~ V_166 ;
break;
case V_92 :
V_136 -> V_74 |= V_166 ;
break;
}
} else {
switch ( V_95 -> V_96 . V_88 ) {
case V_90 :
V_136 -> V_74 &= ~ ( V_166 ) ;
V_136 -> V_74 |= V_173 ;
break;
case V_92 :
V_136 -> V_74 |= V_166 ;
V_136 -> V_74 |= V_173 ;
break;
case V_174 :
default:
F_45 ( V_2 , L_23 ) ;
break;
}
}
} else {
V_136 -> V_74 |= V_175 ;
}
F_46 ( V_2 , V_95 ) ;
F_33 ( V_2 , L_24
L_25 ,
F_34 ( V_136 -> V_74 ) , V_95 -> V_96 . V_169 ,
V_95 -> V_96 . V_88 ) ;
}
void F_47 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
struct V_94 * V_95 ;
F_48 (priv, ctx)
F_44 ( V_2 , V_164 , V_95 ) ;
}
T_2 F_49 ( struct V_1 * V_2 ,
enum V_5 V_6 )
{
const struct V_36 * V_89 ;
int V_45 ;
T_2 V_69 = 0 ;
T_2 V_176 , V_177 ;
struct V_94 * V_95 ;
if ( V_6 == V_51 ) {
V_176 = 14 ;
V_177 = V_2 -> V_54 ;
} else {
V_176 = 0 ;
V_177 = 14 ;
}
for ( V_45 = V_176 ; V_45 < V_177 ; V_45 ++ ) {
bool V_178 = false ;
F_48 (priv, ctx) {
V_178 = V_2 -> V_66 [ V_45 ] . V_69 ==
F_24 ( V_95 -> V_100 . V_69 ) ;
if ( V_178 )
break;
}
if ( V_178 )
continue;
V_69 = V_2 -> V_66 [ V_45 ] . V_69 ;
V_89 = F_21 ( V_2 , V_6 , V_69 ) ;
if ( F_13 ( V_89 ) )
break;
}
return V_69 ;
}
void F_50 ( struct V_1 * V_2 , struct V_40 * V_37 ,
struct V_94 * V_95 )
{
enum V_5 V_6 = V_37 -> V_6 ;
T_1 V_69 = V_37 -> V_73 ;
if ( ( F_24 ( V_95 -> V_100 . V_69 ) == V_69 ) &&
( V_2 -> V_6 == V_6 ) )
return;
V_95 -> V_100 . V_69 = F_6 ( V_69 ) ;
if ( V_6 == V_51 )
V_95 -> V_100 . V_74 &= ~ V_140 ;
else
V_95 -> V_100 . V_74 |= V_140 ;
V_2 -> V_6 = V_6 ;
F_8 ( V_2 , L_26 , V_69 , V_6 ) ;
}
void F_51 ( struct V_1 * V_2 ,
struct V_94 * V_95 ,
enum V_5 V_6 ,
struct V_112 * V_113 )
{
if ( V_6 == V_51 ) {
V_95 -> V_100 . V_74 &=
~ ( V_140 | V_152
| V_144 ) ;
V_95 -> V_100 . V_74 |= V_143 ;
} else {
if ( V_113 && V_113 -> V_120 . V_179 )
V_95 -> V_100 . V_74 |= V_143 ;
else
V_95 -> V_100 . V_74 &= ~ V_143 ;
V_95 -> V_100 . V_74 |= V_140 ;
V_95 -> V_100 . V_74 |= V_152 ;
V_95 -> V_100 . V_74 &= ~ V_144 ;
}
}
void F_52 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
const struct V_36 * V_89 ;
memset ( & V_95 -> V_100 , 0 , sizeof( V_95 -> V_100 ) ) ;
if ( ! V_95 -> V_113 ) {
V_95 -> V_100 . V_157 = V_95 -> V_180 ;
} else switch ( V_95 -> V_113 -> type ) {
case V_181 :
V_95 -> V_100 . V_157 = V_95 -> V_182 ;
break;
case V_124 :
V_95 -> V_100 . V_157 = V_95 -> V_183 ;
V_95 -> V_100 . V_137 = V_184 ;
break;
case V_185 :
V_95 -> V_100 . V_157 = V_95 -> V_186 ;
V_95 -> V_100 . V_74 = V_187 ;
V_95 -> V_100 . V_137 = V_188 |
V_184 ;
break;
default:
F_45 ( V_2 , L_27 ,
V_95 -> V_113 -> type ) ;
break;
}
#if 0
if (!hw_to_local(priv->hw)->short_preamble)
ctx->staging.flags &= ~RXON_FLG_SHORT_PREAMBLE_MSK;
else
ctx->staging.flags |= RXON_FLG_SHORT_PREAMBLE_MSK;
#endif
V_89 = F_21 ( V_2 , V_2 -> V_6 ,
F_24 ( V_95 -> V_155 . V_69 ) ) ;
if ( ! V_89 )
V_89 = & V_2 -> V_66 [ 0 ] ;
V_95 -> V_100 . V_69 = F_6 ( V_89 -> V_69 ) ;
V_2 -> V_6 = V_89 -> V_6 ;
F_51 ( V_2 , V_95 , V_2 -> V_6 , V_95 -> V_113 ) ;
V_95 -> V_100 . V_147 =
( V_189 >> V_60 ) & 0xFF ;
V_95 -> V_100 . V_149 =
( V_190 >> V_191 ) & 0xF ;
V_95 -> V_100 . V_74 &= ~ ( V_173 |
V_172 ) ;
if ( V_95 -> V_113 )
memcpy ( V_95 -> V_100 . V_145 , V_95 -> V_113 -> V_192 , V_193 ) ;
V_95 -> V_100 . V_159 = 0xff ;
V_95 -> V_100 . V_160 = 0xff ;
V_95 -> V_100 . V_161 = 0xff ;
}
void F_53 ( struct V_1 * V_2 )
{
const struct V_38 * V_114 = NULL ;
struct V_43 * V_194 ;
struct V_94 * V_95 ;
int V_45 ;
V_114 = F_54 ( V_2 , V_2 -> V_6 ) ;
if ( ! V_114 ) {
F_45 ( V_2 , L_28 ) ;
return;
}
V_2 -> V_195 = 0 ;
for ( V_45 = 0 ; V_45 < V_114 -> V_50 ; V_45 ++ ) {
V_194 = & ( V_114 -> V_59 [ V_45 ] ) ;
if ( V_194 -> V_73 < V_57 )
V_2 -> V_195 |= ( 1 << V_194 -> V_73 ) ;
}
F_55 ( V_2 , L_29 , V_2 -> V_195 ) ;
F_48 (priv, ctx) {
V_95 -> V_100 . V_149 =
( V_196 >> V_191 ) & 0xF ;
V_95 -> V_100 . V_147 =
( V_197 >> V_60 ) & 0xFF ;
}
}
void F_56 ( struct V_1 * V_2 , bool V_198 )
{
struct V_94 * V_95 = & V_2 -> V_126 [ V_125 ] ;
if ( F_57 ( V_199 , & V_2 -> V_53 ) )
return;
if ( F_58 ( V_200 , & V_2 -> V_53 ) )
F_59 ( V_95 -> V_113 , V_198 ) ;
}
void F_60 ( struct V_1 * V_2 ,
enum V_201 V_122 )
{
struct V_94 * V_95 = & V_2 -> V_126 [ V_122 ] ;
struct V_135 * V_136 = & V_95 -> V_100 ;
F_61 ( V_2 , L_30 ) ;
F_62 ( V_2 , V_202 , ( T_2 * ) V_136 , sizeof( * V_136 ) ) ;
F_61 ( V_2 , L_31 , F_24 ( V_136 -> V_69 ) ) ;
F_61 ( V_2 , L_32 , F_34 ( V_136 -> V_74 ) ) ;
F_61 ( V_2 , L_33 ,
F_34 ( V_136 -> V_137 ) ) ;
F_61 ( V_2 , L_34 , V_136 -> V_157 ) ;
F_61 ( V_2 , L_35 ,
V_136 -> V_147 ) ;
F_61 ( V_2 , L_36 , V_136 -> V_149 ) ;
F_61 ( V_2 , L_37 , V_136 -> V_145 ) ;
F_61 ( V_2 , L_38 , V_136 -> V_146 ) ;
F_61 ( V_2 , L_39 , F_24 ( V_136 -> V_151 ) ) ;
}
static void F_63 ( struct V_1 * V_2 , bool V_203 )
{
unsigned int V_204 ;
unsigned long V_205 ;
#ifdef F_64
if ( F_65 ( V_206 ) )
F_60 ( V_2 , V_125 ) ;
#endif
V_2 -> V_207 = false ;
F_9 ( V_208 , & V_2 -> V_209 -> V_53 ) ;
F_19 ( V_210 , & V_2 -> V_209 -> V_53 ) ;
F_66 ( & V_2 -> V_211 ) ;
F_19 ( V_212 , & V_2 -> V_53 ) ;
F_67 ( & F_17 ( V_2 ) -> V_213 ) ;
if ( ! V_203 ) {
V_205 = V_214 ;
V_204 = F_68 ( ( long ) V_205 -
( long ) V_2 -> V_205 ) ;
V_2 -> V_205 = V_205 ;
if ( V_204 <= V_215 ) {
V_2 -> V_216 ++ ;
if ( V_2 -> V_216 >= V_217 ) {
F_45 ( V_2 , L_40 ) ;
return;
}
} else
V_2 -> V_216 = 0 ;
}
if ( ! F_57 ( V_199 , & V_2 -> V_53 ) ) {
if ( V_23 . V_218 ) {
F_69 ( V_2 ,
L_41 ) ;
F_70 ( V_2 -> V_219 , & V_2 -> V_220 ) ;
} else
F_69 ( V_2 ,
L_42 ) ;
}
}
int F_71 ( struct V_1 * V_2 , T_3 V_221 , bool V_222 )
{
int V_223 ;
T_3 V_224 ;
bool V_225 ;
struct V_94 * V_95 = & V_2 -> V_126 [ V_125 ] ;
F_27 ( & V_2 -> V_115 ) ;
if ( V_2 -> V_84 == V_221 && ! V_222 )
return 0 ;
if ( V_221 < V_47 ) {
F_38 ( V_2 ,
L_43 ,
V_221 ,
V_47 ) ;
return - V_154 ;
}
if ( V_221 > V_2 -> V_83 ) {
F_38 ( V_2 ,
L_44 ,
V_221 , V_2 -> V_83 ) ;
return - V_154 ;
}
if ( ! F_72 ( V_2 ) )
return - V_226 ;
V_2 -> V_85 = V_221 ;
V_225 = F_57 ( V_227 , & V_2 -> V_53 ) ||
memcmp ( & V_95 -> V_155 , & V_95 -> V_100 , sizeof( V_95 -> V_100 ) ) ;
if ( V_225 && ! V_222 ) {
F_8 ( V_2 , L_45 ) ;
return 0 ;
}
V_224 = V_2 -> V_84 ;
V_2 -> V_84 = V_221 ;
V_223 = F_73 ( V_2 ) ;
if ( V_223 ) {
V_2 -> V_84 = V_224 ;
V_2 -> V_85 = V_224 ;
}
return V_223 ;
}
void F_74 ( struct V_1 * V_2 )
{
struct V_228 V_229 = {
. V_230 = V_231 ,
. V_232 = V_233 ,
. V_234 = 0 ,
. V_235 = 0 ,
} ;
if ( ! V_23 . V_236 )
V_229 . V_74 = V_237 ;
else
V_229 . V_74 = V_238 ;
V_2 -> V_239 = V_229 . V_74 ;
F_8 ( V_2 , L_46 ,
( V_229 . V_74 == V_237 ) ? L_47 : L_48 ) ;
if ( F_35 ( V_2 , V_240 ,
V_133 , sizeof( struct V_228 ) , & V_229 ) )
F_45 ( V_2 , L_49 ) ;
}
int F_75 ( struct V_1 * V_2 , T_2 V_74 , bool V_241 )
{
struct V_242 V_243 = {
. V_244 =
V_241 ? V_245 : 0 ,
} ;
if ( V_74 & V_246 )
return F_35 ( V_2 , V_247 ,
V_246 ,
sizeof( struct V_242 ) ,
& V_243 ) ;
else
return F_35 ( V_2 , V_247 ,
V_133 ,
sizeof( struct V_242 ) ,
& V_243 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
V_2 -> V_248 = 0 ;
V_2 -> V_249 = 0 ;
if ( V_2 -> V_250 )
memset ( V_2 -> V_250 , 0 , V_251 ) ;
if ( V_2 -> V_252 )
memset ( V_2 -> V_252 , 0 , V_251 ) ;
}
int F_77 ( struct V_1 * V_2 )
{
T_6 V_253 = V_251 ;
if ( F_65 ( V_254 ) ) {
if ( ! V_2 -> V_250 ) {
V_2 -> V_250 =
F_78 ( V_253 , V_55 ) ;
if ( ! V_2 -> V_250 )
return - V_56 ;
}
}
if ( F_65 ( V_255 ) ) {
if ( ! V_2 -> V_252 ) {
V_2 -> V_252 =
F_78 ( V_253 , V_55 ) ;
if ( ! V_2 -> V_252 )
return - V_56 ;
}
}
F_76 ( V_2 ) ;
return 0 ;
}
void F_79 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_250 ) ;
V_2 -> V_250 = NULL ;
F_11 ( V_2 -> V_252 ) ;
V_2 -> V_252 = NULL ;
}
void F_80 ( struct V_1 * V_2 ,
T_1 V_256 , struct V_257 * V_258 )
{
T_10 V_259 ;
T_1 V_260 ;
if ( F_81 ( ! F_65 ( V_254 ) ) )
return;
if ( ! V_2 -> V_250 )
return;
V_259 = V_258 -> V_261 ;
if ( F_82 ( V_259 ) ) {
V_260 = ( V_256 > V_262 )
? V_262 : V_256 ;
memcpy ( ( V_2 -> V_250 +
( V_2 -> V_248 * V_262 ) ) ,
V_258 , V_260 ) ;
V_2 -> V_248 =
( V_2 -> V_248 + 1 ) % V_263 ;
}
}
void F_83 ( struct V_1 * V_2 ,
T_1 V_256 , struct V_257 * V_258 )
{
T_10 V_259 ;
T_1 V_260 ;
if ( F_81 ( ! F_65 ( V_255 ) ) )
return;
if ( ! V_2 -> V_252 )
return;
V_259 = V_258 -> V_261 ;
if ( F_82 ( V_259 ) ) {
V_260 = ( V_256 > V_262 )
? V_262 : V_256 ;
memcpy ( ( V_2 -> V_252 +
( V_2 -> V_249 * V_262 ) ) ,
V_258 , V_260 ) ;
V_2 -> V_249 =
( V_2 -> V_249 + 1 ) % V_263 ;
}
}
const char * F_84 ( int V_264 )
{
switch ( V_264 ) {
F_85 ( V_265 ) ;
F_85 ( V_266 ) ;
F_85 ( V_267 ) ;
F_85 ( V_268 ) ;
F_85 ( V_269 ) ;
F_85 ( V_270 ) ;
F_85 ( V_271 ) ;
F_85 ( V_272 ) ;
F_85 ( V_273 ) ;
F_85 ( V_274 ) ;
F_85 ( V_275 ) ;
F_85 ( V_276 ) ;
default:
return L_50 ;
}
}
const char * F_86 ( int V_264 )
{
switch ( V_264 ) {
F_85 ( V_277 ) ;
F_85 ( V_278 ) ;
F_85 ( V_279 ) ;
F_85 ( V_280 ) ;
F_85 ( V_281 ) ;
F_85 ( V_282 ) ;
F_85 ( V_283 ) ;
F_85 ( V_284 ) ;
default:
return L_50 ;
}
}
void F_87 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_285 , 0 , sizeof( struct V_286 ) ) ;
memset ( & V_2 -> V_287 , 0 , sizeof( struct V_286 ) ) ;
}
void F_88 ( struct V_1 * V_2 , bool V_288 , T_10 V_259 , T_1 V_260 )
{
struct V_286 * V_289 ;
if ( V_288 )
V_289 = & V_2 -> V_285 ;
else
V_289 = & V_2 -> V_287 ;
if ( F_89 ( V_259 ) ) {
switch ( V_259 & F_6 ( V_290 ) ) {
case F_6 ( V_291 ) :
V_289 -> V_292 [ V_265 ] ++ ;
break;
case F_6 ( V_293 ) :
V_289 -> V_292 [ V_266 ] ++ ;
break;
case F_6 ( V_294 ) :
V_289 -> V_292 [ V_267 ] ++ ;
break;
case F_6 ( V_295 ) :
V_289 -> V_292 [ V_268 ] ++ ;
break;
case F_6 ( V_296 ) :
V_289 -> V_292 [ V_269 ] ++ ;
break;
case F_6 ( V_297 ) :
V_289 -> V_292 [ V_270 ] ++ ;
break;
case F_6 ( V_298 ) :
V_289 -> V_292 [ V_271 ] ++ ;
break;
case F_6 ( V_299 ) :
V_289 -> V_292 [ V_272 ] ++ ;
break;
case F_6 ( V_300 ) :
V_289 -> V_292 [ V_273 ] ++ ;
break;
case F_6 ( V_301 ) :
V_289 -> V_292 [ V_274 ] ++ ;
break;
case F_6 ( V_302 ) :
V_289 -> V_292 [ V_275 ] ++ ;
break;
case F_6 ( V_303 ) :
V_289 -> V_292 [ V_276 ] ++ ;
break;
}
} else if ( F_90 ( V_259 ) ) {
switch ( V_259 & F_6 ( V_290 ) ) {
case F_6 ( V_304 ) :
V_289 -> V_305 [ V_277 ] ++ ;
break;
case F_6 ( V_306 ) :
V_289 -> V_305 [ V_278 ] ++ ;
break;
case F_6 ( V_307 ) :
V_289 -> V_305 [ V_279 ] ++ ;
break;
case F_6 ( V_308 ) :
V_289 -> V_305 [ V_280 ] ++ ;
break;
case F_6 ( V_309 ) :
V_289 -> V_305 [ V_281 ] ++ ;
break;
case F_6 ( V_310 ) :
V_289 -> V_305 [ V_282 ] ++ ;
break;
case F_6 ( V_311 ) :
V_289 -> V_305 [ V_283 ] ++ ;
break;
case F_6 ( V_312 ) :
V_289 -> V_305 [ V_284 ] ++ ;
break;
}
} else {
V_289 -> V_313 ++ ;
V_289 -> V_314 += V_260 ;
}
}
static void F_91 ( struct V_1 * V_2 )
{
if ( F_57 ( V_199 , & V_2 -> V_53 ) )
return;
if ( ! F_92 ( V_2 ) ) {
F_93 ( V_2 , L_51 ) ;
return;
}
F_8 ( V_2 , L_52 ) ;
F_94 ( V_2 ) ;
}
int F_95 ( struct V_1 * V_2 , int V_315 , bool V_316 )
{
struct F_95 * V_317 ;
if ( F_57 ( V_199 , & V_2 -> V_53 ) )
return - V_154 ;
if ( V_315 >= V_318 ) {
F_8 ( V_2 , L_53 ) ;
return - V_154 ;
}
V_317 = & V_2 -> V_317 [ V_315 ] ;
V_317 -> V_319 ++ ;
if ( ! V_316 ) {
if ( V_317 -> V_320 &&
F_96 ( V_317 -> V_320 +
V_317 -> V_321 , V_214 ) ) {
F_8 ( V_2 , L_54 ) ;
V_317 -> V_322 ++ ;
return - V_323 ;
}
}
V_317 -> V_324 ++ ;
V_317 -> V_320 = V_214 ;
F_8 ( V_2 , L_55 , V_315 ) ;
switch ( V_315 ) {
case V_325 :
F_91 ( V_2 ) ;
break;
case V_326 :
if ( ! V_316 && ! V_23 . V_218 ) {
F_8 ( V_2 , L_56
L_57 ) ;
break;
}
F_45 ( V_2 , L_58 ) ;
F_63 ( V_2 , true ) ;
break;
}
return 0 ;
}
int F_97 ( struct V_1 * V_2 )
{
int V_223 ;
struct V_327 V_264 = {
. V_328 = V_329 ,
. V_260 = { 0 } ,
. V_74 = V_133 ,
} ;
V_223 = F_98 ( V_2 , & V_264 ) ;
if ( V_223 )
F_45 ( V_2 , L_59 , V_223 ) ;
else
F_8 ( V_2 , L_60 ) ;
return V_223 ;
}
static inline int F_99 ( struct V_1 * V_2 , int V_330 )
{
if ( F_100 ( F_17 ( V_2 ) , V_330 ) ) {
int V_223 ;
V_223 = F_95 ( V_2 , V_326 , false ) ;
return ( V_223 == - V_323 ) ? 0 : 1 ;
}
return 0 ;
}
void F_101 ( unsigned long V_331 )
{
struct V_1 * V_2 = (struct V_1 * ) V_331 ;
int V_332 ;
unsigned long V_333 ;
if ( F_57 ( V_199 , & V_2 -> V_53 ) )
return;
if ( F_102 ( V_2 ) )
return;
V_333 = F_2 ( V_2 ) . V_334 ;
if ( V_333 == 0 )
return;
for ( V_332 = 0 ; V_332 < F_3 ( V_2 ) -> V_335 -> V_336 ; V_332 ++ )
if ( F_99 ( V_2 , V_332 ) )
return;
F_103 ( & V_2 -> V_337 , V_214 +
F_104 ( F_105 ( V_333 ) ) ) ;
}
void F_106 ( struct V_1 * V_2 )
{
unsigned int V_333 = F_2 ( V_2 ) . V_334 ;
if ( ! V_23 . V_338 ) {
if ( V_333 && ! F_3 ( V_2 ) -> V_335 -> V_338 )
F_103 ( & V_2 -> V_337 ,
V_214 +
F_104 ( F_105 ( V_333 ) ) ) ;
else
F_107 ( & V_2 -> V_337 ) ;
} else {
if ( V_333 && V_23 . V_338 == 2 )
F_103 ( & V_2 -> V_337 ,
V_214 +
F_104 ( F_105 ( V_333 ) ) ) ;
else
F_107 ( & V_2 -> V_337 ) ;
}
}
static inline T_6 F_108 ( struct V_1 * V_2 ,
T_1 V_339 )
{
return ( 1 << V_339 ) - 1 ;
}
static inline T_6 F_109 ( struct V_1 * V_2 ,
T_1 V_339 )
{
return ( ( 1 << ( 32 - V_339 ) ) - 1 ) << V_339 ;
}
T_6 F_110 ( struct V_1 * V_2 , T_6 V_340 , T_6 V_127 )
{
T_6 V_341 ;
T_6 V_108 ;
T_6 V_342 = V_127 * V_129 ;
if ( ! V_342 || ! V_340 )
return 0 ;
V_341 = ( V_340 / V_342 ) &
( F_109 ( V_2 , V_343 ) >>
V_343 ) ;
V_108 = ( V_340 % V_342 ) & F_108 ( V_2 ,
V_343 ) ;
return ( V_341 << V_343 ) + V_108 ;
}
T_11 F_111 ( struct V_1 * V_2 , T_6 V_344 ,
T_6 V_345 , T_6 V_127 )
{
T_6 V_346 = V_344 & F_108 ( V_2 ,
V_343 ) ;
T_6 V_347 = V_345 & F_108 ( V_2 ,
V_343 ) ;
T_6 V_342 = V_127 * V_129 ;
T_6 V_348 = ( V_344 & F_109 ( V_2 ,
V_343 ) ) +
( V_345 & F_109 ( V_2 ,
V_343 ) ) ;
if ( V_346 > V_347 )
V_348 += V_346 - V_347 ;
else if ( V_346 < V_347 ) {
V_348 += V_342 + V_346 - V_347 ;
V_348 += ( 1 << V_343 ) ;
} else
V_348 += ( 1 << V_343 ) ;
return F_32 ( V_348 ) ;
}
void F_112 ( struct V_349 * V_350 )
{
struct V_1 * V_2 = F_113 ( V_350 ) ;
F_63 ( V_2 , false ) ;
}
void F_114 ( struct V_349 * V_350 , bool V_351 )
{
struct V_1 * V_2 = F_113 ( V_350 ) ;
if ( V_351 )
F_9 ( V_352 , & V_2 -> V_53 ) ;
else
F_19 ( V_352 , & V_2 -> V_53 ) ;
F_115 ( V_2 -> V_114 -> V_353 , V_351 ) ;
}
void F_116 ( struct V_349 * V_350 , struct V_354 * V_355 )
{
struct V_356 * V_357 ;
V_357 = F_117 ( V_355 ) ;
F_118 ( V_358 , ( V_357 -> V_359 [ 1 ] ) ) ;
F_119 ( V_355 ) ;
}
