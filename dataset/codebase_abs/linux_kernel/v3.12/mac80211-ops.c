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
V_17 = F_21 ( V_8 , & V_46 -> V_48 ) ;
if ( V_17 < 0 )
goto V_49;
}
if ( ( V_44 & V_50 ) &&
( V_8 -> V_51 . V_52 != V_46 -> V_53 ) ) {
V_8 -> V_51 . V_52 = V_46 -> V_53 ;
F_22 ( V_8 , ( V_46 -> V_53 * 2 ) ) ;
}
if ( V_44 & V_54 ) {
V_8 -> V_55 = V_46 -> V_56 ;
V_8 -> V_57 = V_46 -> V_58 ;
for ( V_43 = 0 ; V_43 < V_8 -> V_11 . V_12 . V_13 ; V_43 ++ )
F_23 ( V_8 , V_43 ) ;
}
F_24 ( V_8 , V_8 -> V_59 ) ;
V_49:
F_16 ( & V_8 -> V_21 ) ;
return V_17 ;
}
static void
F_25 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_60 * V_61 , T_2 V_62 )
{
struct V_18 * V_19 = ( void * ) V_16 -> V_20 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_63 * V_64 = F_26 ( V_8 ) ;
F_7 ( & V_8 -> V_21 ) ;
if ( V_62 & V_65 ) {
memcpy ( V_64 -> V_66 , V_61 -> V_67 , V_68 ) ;
V_64 -> V_69 = 0 ;
F_27 ( V_8 ) ;
F_28 () ;
}
if ( V_62 & V_70 )
V_8 -> V_71 = V_61 -> V_72 ;
if ( V_62 & V_73 ) {
int V_74 ;
V_8 -> V_75 = V_61 -> V_76 ;
V_74 = F_29 ( V_8 ) +
3 * V_8 -> V_77 ;
F_30 ( V_8 , V_74 ) ;
}
if ( V_62 & V_78 ) {
V_19 -> V_79 = V_61 -> V_79 ;
if ( V_61 -> V_79 )
V_8 -> V_79 = V_61 -> V_79 ;
else
V_8 -> V_79 = F_31 ( V_8 ) ;
if ( V_8 -> V_32 == V_30 )
F_32 ( V_2 , V_8 -> V_79 ) ;
F_33 ( V_8 , V_8 -> V_79 ?
V_80 : V_81 ) ;
if ( V_61 -> V_79 ) {
F_9 ( V_8 , V_82 ,
L_3 ,
V_61 -> V_83 , V_64 -> V_66 ) ;
V_64 -> V_69 = V_61 -> V_83 ;
F_27 ( V_8 ) ;
}
}
if ( V_62 & V_84 ) {
F_34 ( & V_8 -> V_85 ) ;
F_35 ( V_2 , V_16 ) ;
F_36 ( & V_8 -> V_85 ) ;
}
if ( V_62 & V_86 )
V_8 -> V_87 = V_61 -> V_87 ;
if ( V_62 & ( V_84 | V_86 |
V_70 ) )
F_37 ( V_8 ) ;
F_16 ( & V_8 -> V_21 ) ;
}
static T_3
F_38 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
T_2 V_90 [ 2 ] , V_91 ;
T_4 V_92 ;
struct V_93 * V_94 ;
V_90 [ 0 ] = 0 ;
V_90 [ 1 ] = 0 ;
F_39 (ha, mc_list) {
V_91 = F_40 ( V_94 -> V_42 + 0 ) ;
V_92 = ( V_91 >> 18 ) ^ ( V_91 >> 12 ) ^ ( V_91 >> 6 ) ^ V_91 ;
V_91 = F_40 ( V_94 -> V_42 + 3 ) ;
V_92 ^= ( V_91 >> 18 ) ^ ( V_91 >> 12 ) ^ ( V_91 >> 6 ) ^ V_91 ;
V_92 &= 0x3f ;
V_90 [ V_92 / 32 ] |= ( 1 << ( V_92 % 32 ) ) ;
}
return ( ( T_3 ) ( V_90 [ 1 ] ) << 32 ) | V_90 [ 0 ] ;
}
static void
F_41 ( struct V_1 * V_2 , unsigned int V_95 ,
unsigned int * V_96 , T_3 V_97 )
{
#define F_42 \
(FIF_PROMISC_IN_BSS | FIF_ALLMULTI | FIF_FCSFAIL | \
FIF_PLCPFAIL | FIF_CONTROL | FIF_OTHER_BSS | \
FIF_BCN_PRBRESP_PROMISC)
struct V_7 * V_8 = V_2 -> V_9 ;
T_2 V_90 [ 2 ] , V_98 ;
struct V_99 V_100 ;
F_7 ( & V_8 -> V_21 ) ;
V_90 [ 0 ] = V_97 ;
V_90 [ 1 ] = V_97 >> 32 ;
V_95 &= F_42 ;
* V_96 &= F_42 ;
V_98 = ( F_43 ( V_8 ) & ( V_101 ) ) |
( V_102 | V_103 |
V_104 ) ;
if ( V_95 & ( V_105 | V_106 ) ) {
if ( * V_96 & V_105 )
F_44 ( V_107 , V_8 -> V_108 ) ;
else
F_45 ( V_107 , V_8 -> V_108 ) ;
}
if ( F_46 ( V_107 , V_8 -> V_108 ) )
V_98 |= V_109 ;
if ( * V_96 & V_110 ) {
V_90 [ 0 ] = ~ 0 ;
V_90 [ 1 ] = ~ 0 ;
}
if ( * V_96 & ( V_111 | V_112 ) )
V_98 |= V_101 ;
if ( ( * V_96 & V_113 ) || ( V_8 -> V_29 > 1 ) )
V_98 |= V_114 ;
if ( * V_96 & V_115 )
V_98 |= V_116 ;
switch ( V_8 -> V_32 ) {
case V_31 :
V_98 |= V_116 |
V_114 |
V_117 |
V_109 ;
break;
case V_22 :
case V_23 :
V_98 |= V_117 |
V_114 ;
break;
case V_30 :
if ( V_8 -> V_79 )
V_98 |= V_114 ;
default:
break;
}
V_100 . V_118 = NULL ;
V_100 . V_119 = 0 ;
V_100 . V_120 = false ;
F_47 (
V_8 -> V_2 , V_121 ,
V_122 , & V_100 ) ;
if ( V_100 . V_119 > 1 ) {
V_98 |= V_109 ;
}
F_48 ( V_8 , V_98 ) ;
F_49 ( V_8 , V_90 [ 0 ] , V_90 [ 1 ] ) ;
V_8 -> V_123 = V_98 ;
F_16 ( & V_8 -> V_21 ) ;
}
static int
F_50 ( struct V_1 * V_2 , enum V_124 V_125 ,
struct V_15 * V_16 , struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_63 * V_64 = F_26 ( V_8 ) ;
int V_17 = 0 ;
if ( V_130 )
return - V_33 ;
if ( V_129 -> V_131 & V_132 )
return - V_33 ;
if ( V_16 -> type == V_23 &&
( V_129 -> V_133 == V_134 ||
V_129 -> V_133 == V_135 ) &&
! ( V_129 -> V_131 & V_136 ) ) {
return - V_33 ;
}
switch ( V_129 -> V_133 ) {
case V_137 :
case V_138 :
case V_134 :
break;
case V_135 :
if ( V_64 -> V_139 & V_140 )
break;
return - V_33 ;
default:
F_3 ( 1 ) ;
return - V_141 ;
}
F_7 ( & V_8 -> V_21 ) ;
switch ( V_125 ) {
case V_142 :
V_17 = F_51 ( V_64 , V_16 , V_127 , V_129 ) ;
if ( V_17 >= 0 ) {
V_129 -> V_143 = V_17 ;
V_129 -> V_131 |= V_144 ;
if ( V_129 -> V_133 == V_134 )
V_129 -> V_131 |= V_145 ;
if ( V_129 -> V_133 == V_135 )
V_129 -> V_131 |= V_146 ;
V_17 = 0 ;
}
break;
case V_147 :
F_52 ( V_64 , V_129 ) ;
break;
default:
V_17 = - V_141 ;
}
F_28 () ;
F_16 ( & V_8 -> V_21 ) ;
return V_17 ;
}
static void
F_53 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( ! V_8 -> V_79 )
F_33 ( V_8 , V_148 ) ;
}
static void
F_54 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_33 ( V_8 , V_8 -> V_79 ?
V_80 : V_81 ) ;
}
static int
F_55 ( struct V_1 * V_2 ,
struct V_149 * V_150 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_56 ( V_8 ) ;
V_150 -> V_151 = V_8 -> V_150 . V_152 ;
V_150 -> V_153 = V_8 -> V_150 . V_154 ;
V_150 -> V_155 = V_8 -> V_150 . V_156 ;
V_150 -> V_157 = V_8 -> V_150 . V_158 ;
return 0 ;
}
static int
F_57 ( struct V_1 * V_2 , struct V_15 * V_16 , T_1 V_159 ,
const struct V_160 * V_161 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_162 V_163 ;
int V_17 = 0 ;
if ( V_159 >= V_8 -> V_11 . V_12 . V_13 )
return 0 ;
F_7 ( & V_8 -> V_21 ) ;
F_58 ( V_8 , V_159 , & V_163 ) ;
V_163 . V_164 = V_161 -> V_165 ;
V_163 . V_166 = V_161 -> V_167 ;
V_163 . V_168 = V_161 -> V_169 ;
V_163 . V_170 = V_161 -> V_171 * 32 ;
F_9 ( V_8 , V_82 ,
L_4
L_5 ,
V_159 , V_161 -> V_165 , V_161 -> V_167 ,
V_161 -> V_169 , V_161 -> V_171 ) ;
if ( F_59 ( V_8 , V_159 , & V_163 ) ) {
F_8 ( V_8 ,
L_6 , V_159 ) ;
V_17 = - V_172 ;
} else
F_60 ( V_8 , V_159 ) ;
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
F_63 ( struct V_1 * V_2 , struct V_15 * V_16 , T_3 V_173 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_64 ( V_8 , V_173 ) ;
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
F_68 ( struct V_1 * V_2 , int V_174 , struct V_175 * V_176 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_45 * V_46 = & V_2 -> V_46 ;
struct V_63 * V_64 = F_26 ( V_8 ) ;
struct V_177 * V_178 = & V_64 -> V_179 ;
unsigned int div = V_64 -> V_180 * 1000 ;
if ( V_174 != 0 )
return - V_181 ;
F_34 ( & V_64 -> V_182 ) ;
F_69 ( V_64 ) ;
if ( V_178 -> V_183 > 0 ) {
V_8 -> V_176 . V_184 += V_178 -> V_183 / div ;
V_8 -> V_176 . V_185 += V_178 -> V_186 / div ;
V_8 -> V_176 . V_187 += V_178 -> V_188 / div ;
V_8 -> V_176 . V_189 += V_178 -> V_190 / div ;
}
memset ( V_178 , 0 , sizeof( * V_178 ) ) ;
F_36 ( & V_64 -> V_182 ) ;
memcpy ( V_176 , & V_8 -> V_176 , sizeof( * V_176 ) ) ;
V_176 -> V_191 = V_46 -> V_48 . V_192 ;
V_176 -> V_193 = V_8 -> V_194 ;
V_176 -> V_195 = V_196 |
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
return - V_141 ;
return 0 ;
}
static int
F_73 ( struct V_1 * V_2 , T_2 * V_202 , T_2 * V_203 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
switch ( V_8 -> V_59 ) {
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
return - V_141 ;
if ( ! V_207 || V_207 > V_213 )
return - V_141 ;
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
