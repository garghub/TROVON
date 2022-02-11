static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_8 = F_2 ( V_4 ) ;
if ( F_3 ( V_8 >= V_6 -> V_9 . V_10 . V_11 ) ) {
F_4 ( V_4 ) ;
return;
}
F_5 ( V_2 , V_4 , & V_6 -> V_12 [ V_8 ] ) ;
}
static int
F_6 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_15 ;
struct V_16 * V_17 = ( void * ) V_14 -> V_18 ;
F_7 ( & V_6 -> V_19 ) ;
if ( ( V_14 -> type == V_20 ||
V_14 -> type == V_21 )
&& ( V_6 -> V_22 + V_6 -> V_23 ) >= V_24 ) {
V_15 = - V_25 ;
goto V_26;
}
if ( V_6 -> V_23 ||
( V_6 -> V_27 && V_14 -> type == V_21 ) ) {
F_8 ( V_6 , L_1 ) ;
V_15 = - V_25 ;
goto V_26;
}
switch ( V_14 -> type ) {
case V_20 :
case V_28 :
case V_21 :
case V_29 :
V_17 -> V_30 = V_14 -> type ;
break;
default:
V_15 = - V_31 ;
goto V_26;
}
V_6 -> V_27 ++ ;
F_9 ( V_6 , V_32 , L_2 , V_17 -> V_30 ) ;
if ( ( V_17 -> V_30 == V_20 ) ||
( V_17 -> V_30 == V_21 ) ||
( V_17 -> V_30 == V_29 ) ) {
int V_33 ;
F_3 ( F_10 ( & V_6 -> V_34 ) ) ;
V_17 -> V_35 = F_11 ( & V_6 -> V_34 , struct V_36 ,
V_37 ) ;
F_12 ( & V_17 -> V_35 -> V_37 ) ;
V_17 -> V_38 = 0 ;
for ( V_33 = 0 ; V_33 < V_24 ; V_33 ++ ) {
if ( ! V_6 -> V_38 [ V_33 ] ) {
V_17 -> V_38 = V_33 ;
break;
}
}
F_13 ( V_6 -> V_38 [ V_17 -> V_38 ] != NULL ) ;
V_6 -> V_38 [ V_17 -> V_38 ] = V_14 ;
if ( V_17 -> V_30 == V_20 )
V_6 -> V_22 ++ ;
else if ( V_17 -> V_30 == V_21 )
V_6 -> V_23 ++ ;
else if ( V_17 -> V_30 == V_29 )
V_6 -> V_39 ++ ;
}
F_14 ( V_6 , V_14 -> V_40 ) ;
F_15 ( V_6 , V_14 ) ;
V_15 = 0 ;
V_26:
F_16 ( & V_6 -> V_19 ) ;
return V_15 ;
}
static void
F_17 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_16 * V_17 = ( void * ) V_14 -> V_18 ;
unsigned int V_41 ;
F_7 ( & V_6 -> V_19 ) ;
V_6 -> V_27 -- ;
if ( V_17 -> V_35 ) {
F_18 ( V_6 , V_17 -> V_35 ) ;
F_19 ( & V_17 -> V_35 -> V_37 , & V_6 -> V_34 ) ;
for ( V_41 = 0 ; V_41 < V_24 ; V_41 ++ ) {
if ( V_6 -> V_38 [ V_41 ] == V_14 ) {
V_6 -> V_38 [ V_41 ] = NULL ;
break;
}
}
V_17 -> V_35 = NULL ;
}
if ( V_17 -> V_30 == V_20 )
V_6 -> V_22 -- ;
else if ( V_17 -> V_30 == V_21 )
V_6 -> V_23 -- ;
else if ( V_17 -> V_30 == V_29 )
V_6 -> V_39 -- ;
F_15 ( V_6 , NULL ) ;
F_16 ( & V_6 -> V_19 ) ;
}
static int
F_20 ( struct V_1 * V_2 , T_2 V_42 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_43 * V_44 = & V_2 -> V_44 ;
int V_15 = 0 ;
int V_41 ;
F_7 ( & V_6 -> V_19 ) ;
if ( V_42 & V_45 ) {
V_15 = F_21 ( V_6 , V_44 -> V_46 ) ;
if ( V_15 < 0 )
goto V_47;
}
if ( ( V_42 & V_48 ) &&
( V_6 -> V_49 != V_44 -> V_49 ) ) {
V_6 -> V_49 = V_44 -> V_49 ;
F_22 ( V_6 , ( V_44 -> V_49 * 2 ) ) ;
}
if ( V_42 & V_50 ) {
V_6 -> V_51 = V_44 -> V_52 ;
V_6 -> V_53 = V_44 -> V_54 ;
for ( V_41 = 0 ; V_41 < V_6 -> V_9 . V_10 . V_11 ; V_41 ++ )
F_23 ( V_6 , V_41 ) ;
}
F_24 ( V_6 , V_6 -> V_55 ) ;
V_47:
F_16 ( & V_6 -> V_19 ) ;
return V_15 ;
}
static void
F_25 ( struct V_1 * V_2 , struct V_13 * V_14 ,
struct V_56 * V_57 , T_2 V_58 )
{
struct V_16 * V_17 = ( void * ) V_14 -> V_18 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_59 * V_60 = F_26 ( V_6 ) ;
F_7 ( & V_6 -> V_19 ) ;
if ( V_58 & V_61 ) {
memcpy ( V_60 -> V_62 , V_57 -> V_63 , V_64 ) ;
V_60 -> V_65 = 0 ;
F_27 ( V_6 ) ;
F_28 () ;
}
if ( V_58 & V_66 )
V_6 -> V_67 = V_57 -> V_68 ;
if ( V_58 & V_69 ) {
int V_70 ;
V_6 -> V_71 = V_57 -> V_72 ;
V_70 = F_29 ( V_6 ) +
3 * V_6 -> V_73 ;
F_30 ( V_6 , V_70 ) ;
}
if ( V_58 & V_74 ) {
V_17 -> V_75 = V_57 -> V_75 ;
if ( V_57 -> V_75 )
V_6 -> V_75 = V_57 -> V_75 ;
else
V_6 -> V_75 = F_31 ( V_6 ) ;
if ( V_6 -> V_30 == V_28 )
F_32 ( V_2 , V_6 -> V_75 ) ;
F_33 ( V_6 , V_6 -> V_75 ?
V_76 : V_77 ) ;
if ( V_57 -> V_75 ) {
F_9 ( V_6 , V_78 ,
L_3 ,
V_57 -> V_79 , V_60 -> V_62 ) ;
V_60 -> V_65 = V_57 -> V_79 ;
F_27 ( V_6 ) ;
}
}
if ( V_58 & V_80 ) {
F_34 ( & V_6 -> V_81 ) ;
F_35 ( V_2 , V_14 ) ;
F_36 ( & V_6 -> V_81 ) ;
}
if ( V_58 & V_82 )
V_6 -> V_83 = V_57 -> V_83 ;
if ( V_58 & ( V_80 | V_82 |
V_66 ) )
F_37 ( V_6 ) ;
F_16 ( & V_6 -> V_19 ) ;
}
static T_3
F_38 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
T_2 V_86 [ 2 ] , V_87 ;
T_4 V_88 ;
struct V_89 * V_90 ;
V_86 [ 0 ] = 0 ;
V_86 [ 1 ] = 1 ;
F_39 (ha, mc_list) {
V_87 = F_40 ( V_90 -> V_40 + 0 ) ;
V_88 = ( V_87 >> 18 ) ^ ( V_87 >> 12 ) ^ ( V_87 >> 6 ) ^ V_87 ;
V_87 = F_40 ( V_90 -> V_40 + 3 ) ;
V_88 ^= ( V_87 >> 18 ) ^ ( V_87 >> 12 ) ^ ( V_87 >> 6 ) ^ V_87 ;
V_88 &= 0x3f ;
V_86 [ V_88 / 32 ] |= ( 1 << ( V_88 % 32 ) ) ;
}
return ( ( T_3 ) ( V_86 [ 1 ] ) << 32 ) | V_86 [ 0 ] ;
}
static void
F_41 ( struct V_1 * V_2 , unsigned int V_91 ,
unsigned int * V_92 , T_3 V_93 )
{
#define F_42 \
(FIF_PROMISC_IN_BSS | FIF_ALLMULTI | FIF_FCSFAIL | \
FIF_PLCPFAIL | FIF_CONTROL | FIF_OTHER_BSS | \
FIF_BCN_PRBRESP_PROMISC)
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_86 [ 2 ] , V_94 ;
struct V_95 V_96 ;
F_7 ( & V_6 -> V_19 ) ;
V_86 [ 0 ] = V_93 ;
V_86 [ 1 ] = V_93 >> 32 ;
V_91 &= F_42 ;
* V_92 &= F_42 ;
V_94 = ( F_43 ( V_6 ) & ( V_97 ) ) |
( V_98 | V_99 |
V_100 ) ;
if ( V_91 & ( V_101 | V_102 ) ) {
if ( * V_92 & V_101 )
F_44 ( V_103 , V_6 -> V_104 ) ;
else
F_45 ( V_103 , V_6 -> V_104 ) ;
}
if ( F_46 ( V_103 , V_6 -> V_104 ) )
V_94 |= V_105 ;
if ( * V_92 & V_106 ) {
V_86 [ 0 ] = ~ 0 ;
V_86 [ 1 ] = ~ 0 ;
}
if ( * V_92 & ( V_107 | V_108 ) )
V_94 |= V_97 ;
if ( ( * V_92 & V_109 ) || ( V_6 -> V_27 > 1 ) )
V_94 |= V_110 ;
if ( * V_92 & V_111 )
V_94 |= V_112 ;
switch ( V_6 -> V_30 ) {
case V_29 :
V_94 |= V_112 |
V_110 |
V_113 |
V_105 ;
break;
case V_20 :
case V_21 :
V_94 |= V_113 |
V_110 ;
break;
case V_28 :
if ( V_6 -> V_75 )
V_94 |= V_110 ;
default:
break;
}
V_96 . V_114 = NULL ;
V_96 . V_115 = 0 ;
V_96 . V_116 = false ;
F_47 ( V_6 -> V_2 , V_117 ,
& V_96 ) ;
if ( V_96 . V_115 > 1 ) {
V_94 |= V_105 ;
}
F_48 ( V_6 , V_94 ) ;
F_49 ( V_6 , V_86 [ 0 ] , V_86 [ 1 ] ) ;
V_6 -> V_118 = V_94 ;
F_16 ( & V_6 -> V_19 ) ;
}
static int
F_50 ( struct V_1 * V_2 , enum V_119 V_120 ,
struct V_13 * V_14 , struct V_121 * V_122 ,
struct V_123 * V_124 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_59 * V_60 = F_26 ( V_6 ) ;
int V_15 = 0 ;
if ( V_125 )
return - V_31 ;
if ( V_14 -> type == V_21 &&
( V_124 -> V_126 == V_127 ||
V_124 -> V_126 == V_128 ) &&
! ( V_124 -> V_129 & V_130 ) ) {
return - V_31 ;
}
switch ( V_124 -> V_126 ) {
case V_131 :
case V_132 :
case V_127 :
break;
case V_128 :
if ( V_60 -> V_133 & V_134 )
break;
return - V_31 ;
default:
F_3 ( 1 ) ;
return - V_135 ;
}
F_7 ( & V_6 -> V_19 ) ;
switch ( V_120 ) {
case V_136 :
V_15 = F_51 ( V_60 , V_14 , V_122 , V_124 ) ;
if ( V_15 >= 0 ) {
V_124 -> V_137 = V_15 ;
V_124 -> V_129 |= V_138 ;
if ( V_124 -> V_126 == V_127 )
V_124 -> V_129 |= V_139 ;
if ( V_124 -> V_126 == V_128 )
V_124 -> V_129 |= V_140 ;
V_15 = 0 ;
}
break;
case V_141 :
F_52 ( V_60 , V_124 ) ;
break;
default:
V_15 = - V_135 ;
}
F_28 () ;
F_16 ( & V_6 -> V_19 ) ;
return V_15 ;
}
static void
F_53 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_75 )
F_33 ( V_6 , V_142 ) ;
}
static void
F_54 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_33 ( V_6 , V_6 -> V_75 ?
V_76 : V_77 ) ;
}
static int
F_55 ( struct V_1 * V_2 ,
struct V_143 * V_144 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_56 ( V_6 ) ;
V_144 -> V_145 = V_6 -> V_144 . V_146 ;
V_144 -> V_147 = V_6 -> V_144 . V_148 ;
V_144 -> V_149 = V_6 -> V_144 . V_150 ;
V_144 -> V_151 = V_6 -> V_144 . V_152 ;
return 0 ;
}
static int
F_57 ( struct V_1 * V_2 , struct V_13 * V_14 , T_1 V_153 ,
const struct V_154 * V_155 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_156 V_157 ;
int V_15 = 0 ;
if ( V_153 >= V_6 -> V_9 . V_10 . V_11 )
return 0 ;
F_7 ( & V_6 -> V_19 ) ;
F_58 ( V_6 , V_153 , & V_157 ) ;
V_157 . V_158 = V_155 -> V_159 ;
V_157 . V_160 = V_155 -> V_161 ;
V_157 . V_162 = V_155 -> V_163 ;
V_157 . V_164 = V_155 -> V_165 * 32 ;
F_9 ( V_6 , V_78 ,
L_4
L_5 ,
V_153 , V_155 -> V_159 , V_155 -> V_161 ,
V_155 -> V_163 , V_155 -> V_165 ) ;
if ( F_59 ( V_6 , V_153 , & V_157 ) ) {
F_8 ( V_6 ,
L_6 , V_153 ) ;
V_15 = - V_166 ;
} else
F_60 ( V_6 , V_153 ) ;
F_16 ( & V_6 -> V_19 ) ;
return V_15 ;
}
static T_3
F_61 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_62 ( V_6 ) ;
}
static void
F_63 ( struct V_1 * V_2 , struct V_13 * V_14 , T_3 V_167 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_64 ( V_6 , V_167 ) ;
}
static void
F_65 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_30 == V_21 )
F_66 ( V_6 , 0 ) ;
else
F_67 ( V_6 ) ;
}
static int
F_68 ( struct V_1 * V_2 , int V_168 , struct V_169 * V_170 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_43 * V_44 = & V_2 -> V_44 ;
struct V_59 * V_60 = F_26 ( V_6 ) ;
struct V_171 * V_172 = & V_60 -> V_173 ;
unsigned int div = V_60 -> V_174 * 1000 ;
if ( V_168 != 0 )
return - V_175 ;
F_34 ( & V_60 -> V_176 ) ;
F_69 ( V_60 ) ;
if ( V_172 -> V_177 > 0 ) {
V_6 -> V_170 . V_178 += V_172 -> V_177 / div ;
V_6 -> V_170 . V_179 += V_172 -> V_180 / div ;
V_6 -> V_170 . V_181 += V_172 -> V_182 / div ;
V_6 -> V_170 . V_183 += V_172 -> V_184 / div ;
}
memset ( V_172 , 0 , sizeof( * V_172 ) ) ;
F_36 ( & V_60 -> V_176 ) ;
memcpy ( V_170 , & V_6 -> V_170 , sizeof( * V_170 ) ) ;
V_170 -> V_46 = V_44 -> V_46 ;
V_170 -> V_185 = V_6 -> V_186 ;
V_170 -> V_187 = V_188 |
V_189 |
V_190 |
V_191 |
V_192 ;
return 0 ;
}
static void
F_70 ( struct V_1 * V_2 , T_4 V_193 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_7 ( & V_6 -> V_19 ) ;
F_71 ( V_6 , V_193 ) ;
F_16 ( & V_6 -> V_19 ) ;
}
static int
F_72 ( struct V_1 * V_2 , T_2 V_194 , T_2 V_195 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_194 == 1 && V_195 == 1 )
F_24 ( V_6 , V_196 ) ;
else if ( V_194 == 2 && V_195 == 2 )
F_24 ( V_6 , V_197 ) ;
else if ( ( V_194 & 3 ) == 3 && ( V_195 & 3 ) == 3 )
F_24 ( V_6 , V_198 ) ;
else
return - V_135 ;
return 0 ;
}
static int
F_73 ( struct V_1 * V_2 , T_2 * V_194 , T_2 * V_195 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
switch ( V_6 -> V_55 ) {
case V_196 :
* V_194 = 1 ; * V_195 = 1 ; break;
case V_197 :
* V_194 = 2 ; * V_195 = 2 ; break;
case V_198 :
* V_194 = 3 ; * V_195 = 3 ; break;
}
return 0 ;
}
static void F_74 ( struct V_1 * V_2 ,
T_2 * V_199 , T_2 * V_200 , T_2 * V_201 , T_2 * V_202 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
* V_199 = V_6 -> V_12 [ V_203 ] . V_204 ;
* V_200 = V_205 ;
* V_201 = * V_202 = V_206 ;
}
static int F_75 ( struct V_1 * V_2 , T_2 V_199 , T_2 V_201 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_8 ;
if ( V_201 != V_206 )
return - V_135 ;
if ( ! V_199 || V_199 > V_205 )
return - V_135 ;
for ( V_8 = 0 ; V_8 < F_76 ( V_6 -> V_12 ) ; V_8 ++ ) {
if ( ! V_6 -> V_12 [ V_8 ] . V_207 )
continue;
if ( V_6 -> V_12 [ V_8 ] . V_8 < V_203 ||
V_6 -> V_12 [ V_8 ] . V_8 > V_208 )
continue;
V_6 -> V_12 [ V_8 ] . V_204 = V_199 ;
if ( V_6 -> V_12 [ V_8 ] . V_209 >= V_6 -> V_12 [ V_8 ] . V_204 )
F_77 ( V_2 , V_6 -> V_12 [ V_8 ] . V_8 ) ;
}
return 0 ;
}
