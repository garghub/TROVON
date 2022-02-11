static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
T_1 V_10 = F_2 ( V_6 ) ;
if ( F_3 ( V_10 >= V_8 -> V_11 . V_12 . V_13 ) ) {
F_4 ( V_2 , V_6 ) ;
return;
}
F_5 ( V_2 , V_6 , & V_8 -> V_14 [ V_10 ] , V_4 ) ;
}
static int
F_6 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_17 ;
struct V_18 * V_19 = ( void * ) V_16 -> V_20 ;
F_7 ( & V_8 -> V_21 ) ;
if ( ( V_16 -> type == V_22 ||
V_16 -> type == V_23 )
&& ( V_8 -> V_24 + V_8 -> V_25 ) >= V_26 ) {
V_17 = - V_27 ;
goto V_28;
}
if ( V_8 -> V_25 ||
( V_8 -> V_29 && V_16 -> type == V_23 ) ) {
F_8 ( V_8 , L_1 ) ;
V_17 = - V_27 ;
goto V_28;
}
switch ( V_16 -> type ) {
case V_22 :
case V_30 :
case V_23 :
case V_31 :
V_19 -> V_32 = V_16 -> type ;
break;
default:
V_17 = - V_33 ;
goto V_28;
}
V_8 -> V_29 ++ ;
F_9 ( V_8 , V_34 , L_2 , V_19 -> V_32 ) ;
if ( ( V_19 -> V_32 == V_22 ) ||
( V_19 -> V_32 == V_23 ) ||
( V_19 -> V_32 == V_31 ) ) {
int V_35 ;
F_3 ( F_10 ( & V_8 -> V_36 ) ) ;
V_19 -> V_37 = F_11 ( & V_8 -> V_36 , struct V_38 ,
V_39 ) ;
F_12 ( & V_19 -> V_37 -> V_39 ) ;
V_19 -> V_40 = 0 ;
for ( V_35 = 0 ; V_35 < V_26 ; V_35 ++ ) {
if ( ! V_8 -> V_40 [ V_35 ] ) {
V_19 -> V_40 = V_35 ;
break;
}
}
F_13 ( V_8 -> V_40 [ V_19 -> V_40 ] != NULL ) ;
V_8 -> V_40 [ V_19 -> V_40 ] = V_16 ;
if ( V_19 -> V_32 == V_22 )
V_8 -> V_24 ++ ;
else if ( V_19 -> V_32 == V_23 )
V_8 -> V_25 ++ ;
else if ( V_19 -> V_32 == V_31 )
V_8 -> V_41 ++ ;
}
F_14 ( V_8 , V_16 -> V_42 ) ;
F_15 ( V_8 , V_16 ) ;
V_17 = 0 ;
V_28:
F_16 ( & V_8 -> V_21 ) ;
return V_17 ;
}
static void
F_17 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_18 * V_19 = ( void * ) V_16 -> V_20 ;
unsigned int V_43 ;
F_7 ( & V_8 -> V_21 ) ;
V_8 -> V_29 -- ;
if ( V_19 -> V_37 ) {
F_18 ( V_8 , V_19 -> V_37 ) ;
F_19 ( & V_19 -> V_37 -> V_39 , & V_8 -> V_36 ) ;
for ( V_43 = 0 ; V_43 < V_26 ; V_43 ++ ) {
if ( V_8 -> V_40 [ V_43 ] == V_16 ) {
V_8 -> V_40 [ V_43 ] = NULL ;
break;
}
}
V_19 -> V_37 = NULL ;
}
if ( V_19 -> V_32 == V_22 )
V_8 -> V_24 -- ;
else if ( V_19 -> V_32 == V_23 )
V_8 -> V_25 -- ;
else if ( V_19 -> V_32 == V_31 )
V_8 -> V_41 -- ;
F_15 ( V_8 , NULL ) ;
F_16 ( & V_8 -> V_21 ) ;
}
static int
F_20 ( struct V_1 * V_2 , T_2 V_44 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_45 * V_46 = & V_2 -> V_46 ;
int V_17 = 0 ;
int V_43 ;
F_7 ( & V_8 -> V_21 ) ;
if ( V_44 & V_47 ) {
V_17 = F_21 ( V_8 , V_46 -> V_48 . V_49 ) ;
if ( V_17 < 0 )
goto V_50;
}
if ( ( V_44 & V_51 ) &&
( V_8 -> V_52 . V_53 != V_46 -> V_54 ) ) {
V_8 -> V_52 . V_53 = V_46 -> V_54 ;
F_22 ( V_8 , ( V_46 -> V_54 * 2 ) ) ;
}
if ( V_44 & V_55 ) {
V_8 -> V_56 = V_46 -> V_57 ;
V_8 -> V_58 = V_46 -> V_59 ;
for ( V_43 = 0 ; V_43 < V_8 -> V_11 . V_12 . V_13 ; V_43 ++ )
F_23 ( V_8 , V_43 ) ;
}
F_24 ( V_8 , V_8 -> V_60 ) ;
V_50:
F_16 ( & V_8 -> V_21 ) ;
return V_17 ;
}
static void
F_25 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_61 * V_62 , T_2 V_63 )
{
struct V_18 * V_19 = ( void * ) V_16 -> V_20 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_64 * V_65 = F_26 ( V_8 ) ;
F_7 ( & V_8 -> V_21 ) ;
if ( V_63 & V_66 ) {
memcpy ( V_65 -> V_67 , V_62 -> V_68 , V_69 ) ;
V_65 -> V_70 = 0 ;
F_27 ( V_8 ) ;
F_28 () ;
}
if ( V_63 & V_71 )
V_8 -> V_72 = V_62 -> V_73 ;
if ( V_63 & V_74 ) {
int V_75 ;
V_8 -> V_76 = V_62 -> V_77 ;
V_75 = F_29 ( V_8 ) +
3 * V_8 -> V_78 ;
F_30 ( V_8 , V_75 ) ;
}
if ( V_63 & V_79 ) {
V_19 -> V_80 = V_62 -> V_80 ;
if ( V_62 -> V_80 )
V_8 -> V_80 = V_62 -> V_80 ;
else
V_8 -> V_80 = F_31 ( V_8 ) ;
if ( V_8 -> V_32 == V_30 )
F_32 ( V_2 , V_8 -> V_80 ) ;
F_33 ( V_8 , V_8 -> V_80 ?
V_81 : V_82 ) ;
if ( V_62 -> V_80 ) {
F_9 ( V_8 , V_83 ,
L_3 ,
V_62 -> V_84 , V_65 -> V_67 ) ;
V_65 -> V_70 = V_62 -> V_84 ;
F_27 ( V_8 ) ;
}
}
if ( V_63 & V_85 ) {
F_34 ( & V_8 -> V_86 ) ;
F_35 ( V_2 , V_16 ) ;
F_36 ( & V_8 -> V_86 ) ;
}
if ( V_63 & V_87 )
V_8 -> V_88 = V_62 -> V_88 ;
if ( V_63 & ( V_85 | V_87 |
V_71 ) )
F_37 ( V_8 ) ;
F_16 ( & V_8 -> V_21 ) ;
}
static T_3
F_38 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
T_2 V_91 [ 2 ] , V_92 ;
T_4 V_93 ;
struct V_94 * V_95 ;
V_91 [ 0 ] = 0 ;
V_91 [ 1 ] = 0 ;
F_39 (ha, mc_list) {
V_92 = F_40 ( V_95 -> V_42 + 0 ) ;
V_93 = ( V_92 >> 18 ) ^ ( V_92 >> 12 ) ^ ( V_92 >> 6 ) ^ V_92 ;
V_92 = F_40 ( V_95 -> V_42 + 3 ) ;
V_93 ^= ( V_92 >> 18 ) ^ ( V_92 >> 12 ) ^ ( V_92 >> 6 ) ^ V_92 ;
V_93 &= 0x3f ;
V_91 [ V_93 / 32 ] |= ( 1 << ( V_93 % 32 ) ) ;
}
return ( ( T_3 ) ( V_91 [ 1 ] ) << 32 ) | V_91 [ 0 ] ;
}
static void
F_41 ( struct V_1 * V_2 , unsigned int V_96 ,
unsigned int * V_97 , T_3 V_98 )
{
#define F_42 \
(FIF_PROMISC_IN_BSS | FIF_ALLMULTI | FIF_FCSFAIL | \
FIF_PLCPFAIL | FIF_CONTROL | FIF_OTHER_BSS | \
FIF_BCN_PRBRESP_PROMISC)
struct V_7 * V_8 = V_2 -> V_9 ;
T_2 V_91 [ 2 ] , V_99 ;
struct V_100 V_101 ;
F_7 ( & V_8 -> V_21 ) ;
V_91 [ 0 ] = V_98 ;
V_91 [ 1 ] = V_98 >> 32 ;
V_96 &= F_42 ;
* V_97 &= F_42 ;
V_99 = ( F_43 ( V_8 ) & ( V_102 ) ) |
( V_103 | V_104 |
V_105 ) ;
if ( V_96 & ( V_106 | V_107 ) ) {
if ( * V_97 & V_106 )
F_44 ( V_108 , V_8 -> V_109 ) ;
else
F_45 ( V_108 , V_8 -> V_109 ) ;
}
if ( F_46 ( V_108 , V_8 -> V_109 ) )
V_99 |= V_110 ;
if ( * V_97 & V_111 ) {
V_91 [ 0 ] = ~ 0 ;
V_91 [ 1 ] = ~ 0 ;
}
if ( * V_97 & ( V_112 | V_113 ) )
V_99 |= V_102 ;
if ( ( * V_97 & V_114 ) || ( V_8 -> V_29 > 1 ) )
V_99 |= V_115 ;
if ( * V_97 & V_116 )
V_99 |= V_117 ;
switch ( V_8 -> V_32 ) {
case V_31 :
V_99 |= V_117 |
V_115 |
V_118 |
V_110 ;
break;
case V_22 :
case V_23 :
V_99 |= V_118 |
V_115 ;
break;
case V_30 :
if ( V_8 -> V_80 )
V_99 |= V_115 ;
default:
break;
}
V_101 . V_119 = NULL ;
V_101 . V_120 = 0 ;
V_101 . V_121 = false ;
F_47 (
V_8 -> V_2 , V_122 ,
V_123 , & V_101 ) ;
if ( V_101 . V_120 > 1 ) {
V_99 |= V_110 ;
}
F_48 ( V_8 , V_99 ) ;
F_49 ( V_8 , V_91 [ 0 ] , V_91 [ 1 ] ) ;
V_8 -> V_124 = V_99 ;
F_16 ( & V_8 -> V_21 ) ;
}
static int
F_50 ( struct V_1 * V_2 , enum V_125 V_126 ,
struct V_15 * V_16 , struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_64 * V_65 = F_26 ( V_8 ) ;
int V_17 = 0 ;
if ( V_131 )
return - V_33 ;
if ( V_130 -> V_132 & V_133 )
return - V_33 ;
if ( V_16 -> type == V_23 &&
( V_130 -> V_134 == V_135 ||
V_130 -> V_134 == V_136 ) &&
! ( V_130 -> V_132 & V_137 ) ) {
return - V_33 ;
}
switch ( V_130 -> V_134 ) {
case V_138 :
case V_139 :
case V_135 :
break;
case V_136 :
if ( V_65 -> V_140 & V_141 )
break;
return - V_33 ;
default:
F_3 ( 1 ) ;
return - V_142 ;
}
F_7 ( & V_8 -> V_21 ) ;
switch ( V_126 ) {
case V_143 :
V_17 = F_51 ( V_65 , V_16 , V_128 , V_130 ) ;
if ( V_17 >= 0 ) {
V_130 -> V_144 = V_17 ;
V_130 -> V_132 |= V_145 ;
if ( V_130 -> V_134 == V_135 )
V_130 -> V_132 |= V_146 ;
if ( V_130 -> V_134 == V_136 )
V_130 -> V_132 |= V_147 ;
V_17 = 0 ;
}
break;
case V_148 :
F_52 ( V_65 , V_130 ) ;
break;
default:
V_17 = - V_142 ;
}
F_28 () ;
F_16 ( & V_8 -> V_21 ) ;
return V_17 ;
}
static void
F_53 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( ! V_8 -> V_80 )
F_33 ( V_8 , V_149 ) ;
}
static void
F_54 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_33 ( V_8 , V_8 -> V_80 ?
V_81 : V_82 ) ;
}
static int
F_55 ( struct V_1 * V_2 ,
struct V_150 * V_151 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_56 ( V_8 ) ;
V_151 -> V_152 = V_8 -> V_151 . V_153 ;
V_151 -> V_154 = V_8 -> V_151 . V_155 ;
V_151 -> V_156 = V_8 -> V_151 . V_157 ;
V_151 -> V_158 = V_8 -> V_151 . V_159 ;
return 0 ;
}
static int
F_57 ( struct V_1 * V_2 , struct V_15 * V_16 , T_1 V_160 ,
const struct V_161 * V_162 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_163 V_164 ;
int V_17 = 0 ;
if ( V_160 >= V_8 -> V_11 . V_12 . V_13 )
return 0 ;
F_7 ( & V_8 -> V_21 ) ;
F_58 ( V_8 , V_160 , & V_164 ) ;
V_164 . V_165 = V_162 -> V_166 ;
V_164 . V_167 = V_162 -> V_168 ;
V_164 . V_169 = V_162 -> V_170 ;
V_164 . V_171 = V_162 -> V_172 * 32 ;
F_9 ( V_8 , V_83 ,
L_4
L_5 ,
V_160 , V_162 -> V_166 , V_162 -> V_168 ,
V_162 -> V_170 , V_162 -> V_172 ) ;
if ( F_59 ( V_8 , V_160 , & V_164 ) ) {
F_8 ( V_8 ,
L_6 , V_160 ) ;
V_17 = - V_173 ;
} else
F_60 ( V_8 , V_160 ) ;
F_16 ( & V_8 -> V_21 ) ;
return V_17 ;
}
static T_3
F_61 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
return F_62 ( V_8 ) ;
}
static void
F_63 ( struct V_1 * V_2 , struct V_15 * V_16 , T_3 V_174 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_64 ( V_8 , V_174 ) ;
}
static void
F_65 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_8 -> V_32 == V_23 )
F_66 ( V_8 , 0 ) ;
else
F_67 ( V_8 ) ;
}
static int
F_68 ( struct V_1 * V_2 , int V_175 , struct V_176 * V_177 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_45 * V_46 = & V_2 -> V_46 ;
struct V_64 * V_65 = F_26 ( V_8 ) ;
struct V_178 * V_179 = & V_65 -> V_180 ;
unsigned int div = V_65 -> V_181 * 1000 ;
if ( V_175 != 0 )
return - V_182 ;
F_34 ( & V_65 -> V_183 ) ;
F_69 ( V_65 ) ;
if ( V_179 -> V_184 > 0 ) {
V_8 -> V_177 . V_185 += V_179 -> V_184 / div ;
V_8 -> V_177 . V_186 += V_179 -> V_187 / div ;
V_8 -> V_177 . V_188 += V_179 -> V_189 / div ;
V_8 -> V_177 . V_190 += V_179 -> V_191 / div ;
}
memset ( V_179 , 0 , sizeof( * V_179 ) ) ;
F_36 ( & V_65 -> V_183 ) ;
memcpy ( V_177 , & V_8 -> V_177 , sizeof( * V_177 ) ) ;
V_177 -> V_192 = V_46 -> V_48 . V_49 ;
V_177 -> V_193 = V_8 -> V_194 ;
V_177 -> V_195 = V_196 |
V_197 |
V_198 |
V_199 |
V_200 ;
return 0 ;
}
static void
F_70 ( struct V_1 * V_2 , T_4 V_201 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_7 ( & V_8 -> V_21 ) ;
F_71 ( V_8 , V_201 ) ;
F_16 ( & V_8 -> V_21 ) ;
}
static int
F_72 ( struct V_1 * V_2 , T_2 V_202 , T_2 V_203 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_202 == 1 && V_203 == 1 )
F_24 ( V_8 , V_204 ) ;
else if ( V_202 == 2 && V_203 == 2 )
F_24 ( V_8 , V_205 ) ;
else if ( ( V_202 & 3 ) == 3 && ( V_203 & 3 ) == 3 )
F_24 ( V_8 , V_206 ) ;
else
return - V_142 ;
return 0 ;
}
static int
F_73 ( struct V_1 * V_2 , T_2 * V_202 , T_2 * V_203 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
switch ( V_8 -> V_60 ) {
case V_204 :
* V_202 = 1 ; * V_203 = 1 ; break;
case V_205 :
* V_202 = 2 ; * V_203 = 2 ; break;
case V_206 :
* V_202 = 3 ; * V_203 = 3 ; break;
}
return 0 ;
}
static void F_74 ( struct V_1 * V_2 ,
T_2 * V_207 , T_2 * V_208 , T_2 * V_209 , T_2 * V_210 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
* V_207 = V_8 -> V_14 [ V_211 ] . V_212 ;
* V_208 = V_213 ;
* V_209 = * V_210 = V_214 ;
}
static int F_75 ( struct V_1 * V_2 , T_2 V_207 , T_2 V_209 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
T_1 V_10 ;
if ( V_209 != V_214 )
return - V_142 ;
if ( ! V_207 || V_207 > V_213 )
return - V_142 ;
for ( V_10 = 0 ; V_10 < F_76 ( V_8 -> V_14 ) ; V_10 ++ ) {
if ( ! V_8 -> V_14 [ V_10 ] . V_215 )
continue;
if ( V_8 -> V_14 [ V_10 ] . V_10 < V_211 ||
V_8 -> V_14 [ V_10 ] . V_10 > V_216 )
continue;
V_8 -> V_14 [ V_10 ] . V_212 = V_207 ;
if ( V_8 -> V_14 [ V_10 ] . V_217 >= V_8 -> V_14 [ V_10 ] . V_212 )
F_77 ( V_2 , V_8 -> V_14 [ V_10 ] . V_10 ) ;
}
return 0 ;
}
