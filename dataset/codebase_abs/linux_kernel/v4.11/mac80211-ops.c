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
(FIF_ALLMULTI | FIF_FCSFAIL | \
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
if ( * V_96 & V_105 ) {
V_90 [ 0 ] = ~ 0 ;
V_90 [ 1 ] = ~ 0 ;
}
if ( * V_96 & ( V_106 | V_107 ) )
V_98 |= V_101 ;
if ( ( * V_96 & V_108 ) || ( V_8 -> V_29 > 1 ) )
V_98 |= V_109 ;
if ( * V_96 & V_110 )
V_98 |= V_111 ;
switch ( V_8 -> V_32 ) {
case V_31 :
V_98 |= V_111 |
V_109 |
V_112 |
V_113 ;
break;
case V_22 :
case V_23 :
V_98 |= V_112 |
V_109 ;
break;
case V_30 :
if ( V_8 -> V_79 )
V_98 |= V_109 ;
default:
break;
}
V_100 . V_114 = NULL ;
V_100 . V_115 = 0 ;
V_100 . V_116 = false ;
F_44 (
V_8 -> V_2 , V_117 ,
V_118 , & V_100 ) ;
if ( V_100 . V_115 > 1 ) {
V_98 |= V_113 ;
}
F_45 ( V_8 , V_98 ) ;
F_46 ( V_8 , V_90 [ 0 ] , V_90 [ 1 ] ) ;
V_8 -> V_119 = V_98 ;
V_8 -> V_120 = * V_96 ;
F_16 ( & V_8 -> V_21 ) ;
}
static int
F_47 ( struct V_1 * V_2 , enum V_121 V_122 ,
struct V_15 * V_16 , struct V_123 * V_124 ,
struct V_125 * V_126 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_63 * V_64 = F_26 ( V_8 ) ;
int V_17 = 0 ;
if ( V_127 )
return - V_33 ;
if ( V_126 -> V_128 & V_129 )
return - V_33 ;
if ( V_16 -> type == V_23 &&
( V_126 -> V_130 == V_131 ||
V_126 -> V_130 == V_132 ) &&
! ( V_126 -> V_128 & V_133 ) ) {
return - V_33 ;
}
switch ( V_126 -> V_130 ) {
case V_134 :
case V_135 :
case V_131 :
break;
case V_132 :
if ( V_64 -> V_136 & V_137 )
break;
return - V_33 ;
default:
return - V_33 ;
}
F_7 ( & V_8 -> V_21 ) ;
switch ( V_122 ) {
case V_138 :
V_17 = F_48 ( V_64 , V_16 , V_124 , V_126 ) ;
if ( V_17 >= 0 ) {
V_126 -> V_139 = V_17 ;
V_126 -> V_128 |= V_140 ;
if ( V_126 -> V_130 == V_131 )
V_126 -> V_128 |= V_141 ;
if ( V_126 -> V_130 == V_132 )
V_126 -> V_128 |= V_142 ;
V_17 = 0 ;
}
break;
case V_143 :
F_49 ( V_64 , V_126 ) ;
break;
default:
V_17 = - V_144 ;
}
F_28 () ;
F_16 ( & V_8 -> V_21 ) ;
return V_17 ;
}
static void
F_50 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const T_4 * V_145 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( ! V_8 -> V_79 )
F_33 ( V_8 , V_146 ) ;
}
static void
F_51 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_33 ( V_8 , V_8 -> V_79 ?
V_80 : V_81 ) ;
}
static int
F_52 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_53 ( V_8 ) ;
V_148 -> V_149 = V_8 -> V_148 . V_150 ;
V_148 -> V_151 = V_8 -> V_148 . V_152 ;
V_148 -> V_153 = V_8 -> V_148 . V_154 ;
V_148 -> V_155 = V_8 -> V_148 . V_156 ;
return 0 ;
}
static int
F_54 ( struct V_1 * V_2 , struct V_15 * V_16 , T_1 V_157 ,
const struct V_158 * V_159 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_160 V_161 ;
int V_17 = 0 ;
if ( V_157 >= V_8 -> V_11 . V_12 . V_13 )
return 0 ;
F_7 ( & V_8 -> V_21 ) ;
F_55 ( V_8 , V_157 , & V_161 ) ;
V_161 . V_162 = V_159 -> V_163 ;
V_161 . V_164 = V_159 -> V_165 ;
V_161 . V_166 = V_159 -> V_167 ;
V_161 . V_168 = V_159 -> V_169 * 32 ;
F_9 ( V_8 , V_82 ,
L_4
L_5 ,
V_157 , V_159 -> V_163 , V_159 -> V_165 ,
V_159 -> V_167 , V_159 -> V_169 ) ;
if ( F_56 ( V_8 , V_157 , & V_161 ) ) {
F_8 ( V_8 ,
L_6 , V_157 ) ;
V_17 = - V_170 ;
} else
F_57 ( V_8 , V_157 ) ;
F_16 ( & V_8 -> V_21 ) ;
return V_17 ;
}
static T_3
F_58 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
return F_59 ( V_8 ) ;
}
static void
F_60 ( struct V_1 * V_2 , struct V_15 * V_16 , T_3 V_171 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_61 ( V_8 , V_171 ) ;
}
static void
F_62 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_8 -> V_32 == V_23 )
F_63 ( V_8 , 0 ) ;
else
F_64 ( V_8 ) ;
}
static int
F_65 ( struct V_1 * V_2 , int V_172 , struct V_173 * V_174 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_45 * V_46 = & V_2 -> V_46 ;
struct V_63 * V_64 = F_26 ( V_8 ) ;
struct V_175 * V_176 = & V_64 -> V_177 ;
unsigned int div = V_64 -> V_178 * 1000 ;
if ( V_172 != 0 )
return - V_179 ;
F_34 ( & V_64 -> V_180 ) ;
F_66 ( V_64 ) ;
if ( V_176 -> V_181 > 0 ) {
V_8 -> V_174 . time += V_176 -> V_181 / div ;
V_8 -> V_174 . V_182 += V_176 -> V_183 / div ;
V_8 -> V_174 . V_184 += V_176 -> V_185 / div ;
V_8 -> V_174 . V_186 += V_176 -> V_187 / div ;
}
memset ( V_176 , 0 , sizeof( * V_176 ) ) ;
F_36 ( & V_64 -> V_180 ) ;
memcpy ( V_174 , & V_8 -> V_174 , sizeof( * V_174 ) ) ;
V_174 -> V_188 = V_46 -> V_48 . V_189 ;
V_174 -> V_190 = V_8 -> V_191 ;
V_174 -> V_192 = V_193 |
V_194 |
V_195 |
V_196 |
V_197 |
V_198 ;
return 0 ;
}
static void
F_67 ( struct V_1 * V_2 , T_5 V_199 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_7 ( & V_8 -> V_21 ) ;
F_68 ( V_8 , V_199 ) ;
F_16 ( & V_8 -> V_21 ) ;
}
static int
F_69 ( struct V_1 * V_2 , T_2 V_200 , T_2 V_201 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_200 == 1 && V_201 == 1 )
F_24 ( V_8 , V_202 ) ;
else if ( V_200 == 2 && V_201 == 2 )
F_24 ( V_8 , V_203 ) ;
else if ( ( V_200 & 3 ) == 3 && ( V_201 & 3 ) == 3 )
F_24 ( V_8 , V_204 ) ;
else
return - V_144 ;
return 0 ;
}
static int
F_70 ( struct V_1 * V_2 , T_2 * V_200 , T_2 * V_201 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
switch ( V_8 -> V_59 ) {
case V_202 :
* V_200 = 1 ; * V_201 = 1 ; break;
case V_203 :
* V_200 = 2 ; * V_201 = 2 ; break;
case V_204 :
* V_200 = 3 ; * V_201 = 3 ; break;
}
return 0 ;
}
static void F_71 ( struct V_1 * V_2 ,
T_2 * V_205 , T_2 * V_206 , T_2 * V_207 , T_2 * V_208 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
* V_205 = V_8 -> V_14 [ V_209 ] . V_210 ;
* V_206 = V_211 ;
* V_207 = * V_208 = V_212 ;
}
static int F_72 ( struct V_1 * V_2 , T_2 V_205 , T_2 V_207 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
T_1 V_10 ;
if ( V_207 != V_212 )
return - V_144 ;
if ( ! V_205 || V_205 > V_211 )
return - V_144 ;
for ( V_10 = 0 ; V_10 < F_73 ( V_8 -> V_14 ) ; V_10 ++ ) {
if ( ! V_8 -> V_14 [ V_10 ] . V_213 )
continue;
if ( V_8 -> V_14 [ V_10 ] . V_10 < V_209 ||
V_8 -> V_14 [ V_10 ] . V_10 > V_214 )
continue;
V_8 -> V_14 [ V_10 ] . V_210 = V_205 ;
if ( V_8 -> V_14 [ V_10 ] . V_215 >= V_8 -> V_14 [ V_10 ] . V_210 )
F_74 ( V_2 , V_8 -> V_14 [ V_10 ] . V_10 ) ;
}
return 0 ;
}
