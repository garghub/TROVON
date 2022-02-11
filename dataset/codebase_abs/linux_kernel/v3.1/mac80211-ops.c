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
}
memcpy ( & V_6 -> V_39 , V_14 -> V_40 , V_41 ) ;
F_14 ( V_6 , V_14 -> V_40 ) ;
memcpy ( & V_17 -> V_39 , V_14 -> V_40 , V_41 ) ;
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
unsigned int V_42 ;
F_7 ( & V_6 -> V_19 ) ;
V_6 -> V_27 -- ;
if ( V_17 -> V_35 ) {
F_18 ( V_6 , V_17 -> V_35 ) ;
F_19 ( & V_17 -> V_35 -> V_37 , & V_6 -> V_34 ) ;
for ( V_42 = 0 ; V_42 < V_24 ; V_42 ++ ) {
if ( V_6 -> V_38 [ V_42 ] == V_14 ) {
V_6 -> V_38 [ V_42 ] = NULL ;
break;
}
}
V_17 -> V_35 = NULL ;
}
if ( V_17 -> V_30 == V_20 )
V_6 -> V_22 -- ;
else if ( V_17 -> V_30 == V_21 )
V_6 -> V_23 -- ;
F_15 ( V_6 , NULL ) ;
F_16 ( & V_6 -> V_19 ) ;
}
static int
F_20 ( struct V_1 * V_2 , T_2 V_43 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_44 * V_45 = & V_2 -> V_45 ;
int V_15 = 0 ;
int V_42 ;
F_7 ( & V_6 -> V_19 ) ;
if ( V_43 & V_46 ) {
V_15 = F_21 ( V_6 , V_45 -> V_47 ) ;
if ( V_15 < 0 )
goto V_48;
}
if ( ( V_43 & V_49 ) &&
( V_6 -> V_50 != V_45 -> V_50 ) ) {
V_6 -> V_50 = V_45 -> V_50 ;
F_22 ( V_6 , ( V_45 -> V_50 * 2 ) ) ;
}
if ( V_43 & V_51 ) {
V_6 -> V_52 = V_45 -> V_53 ;
V_6 -> V_54 = V_45 -> V_55 ;
for ( V_42 = 0 ; V_42 < V_6 -> V_9 . V_10 . V_11 ; V_42 ++ )
F_23 ( V_6 , V_42 ) ;
}
F_24 ( V_6 , V_6 -> V_56 ) ;
V_48:
F_16 ( & V_6 -> V_19 ) ;
return V_15 ;
}
static void
F_25 ( struct V_1 * V_2 , struct V_13 * V_14 ,
struct V_57 * V_58 , T_2 V_59 )
{
struct V_16 * V_17 = ( void * ) V_14 -> V_18 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_60 * V_61 = F_26 ( V_6 ) ;
unsigned long V_62 ;
F_7 ( & V_6 -> V_19 ) ;
if ( V_59 & V_63 ) {
memcpy ( V_61 -> V_64 , V_58 -> V_65 , V_41 ) ;
V_61 -> V_66 = 0 ;
F_27 ( V_6 ) ;
F_28 () ;
}
if ( V_59 & V_67 )
V_6 -> V_68 = V_58 -> V_69 ;
if ( V_59 & V_70 ) {
int V_71 ;
V_6 -> V_72 = V_58 -> V_73 ;
V_71 = F_29 ( V_6 ) +
3 * V_6 -> V_74 ;
F_30 ( V_6 , V_71 ) ;
}
if ( V_59 & V_75 ) {
V_17 -> V_76 = V_58 -> V_76 ;
if ( V_58 -> V_76 )
V_6 -> V_76 = V_58 -> V_76 ;
else
V_6 -> V_76 = F_31 ( V_6 ) ;
if ( V_6 -> V_30 == V_28 )
F_32 ( V_2 , V_6 -> V_76 ) ;
F_33 ( V_6 , V_6 -> V_76 ?
V_77 : V_78 ) ;
if ( V_58 -> V_76 ) {
F_9 ( V_6 , V_79 ,
L_3 ,
V_58 -> V_80 , V_61 -> V_64 ) ;
V_61 -> V_66 = V_58 -> V_80 ;
F_27 ( V_6 ) ;
}
}
if ( V_59 & V_81 ) {
F_34 ( & V_6 -> V_82 , V_62 ) ;
F_35 ( V_2 , V_14 ) ;
F_36 ( & V_6 -> V_82 , V_62 ) ;
}
if ( V_59 & V_83 )
V_6 -> V_84 = V_58 -> V_84 ;
if ( V_59 & ( V_81 | V_83 |
V_67 ) )
F_37 ( V_6 ) ;
F_16 ( & V_6 -> V_19 ) ;
}
static T_3
F_38 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
T_2 V_87 [ 2 ] , V_88 ;
T_4 V_89 ;
struct V_90 * V_91 ;
V_87 [ 0 ] = 0 ;
V_87 [ 1 ] = 1 ;
F_39 (ha, mc_list) {
V_88 = F_40 ( V_91 -> V_40 + 0 ) ;
V_89 = ( V_88 >> 18 ) ^ ( V_88 >> 12 ) ^ ( V_88 >> 6 ) ^ V_88 ;
V_88 = F_40 ( V_91 -> V_40 + 3 ) ;
V_89 ^= ( V_88 >> 18 ) ^ ( V_88 >> 12 ) ^ ( V_88 >> 6 ) ^ V_88 ;
V_89 &= 0x3f ;
V_87 [ V_89 / 32 ] |= ( 1 << ( V_89 % 32 ) ) ;
}
return ( ( T_3 ) ( V_87 [ 1 ] ) << 32 ) | V_87 [ 0 ] ;
}
static void
F_41 ( struct V_1 * V_2 , unsigned int V_92 ,
unsigned int * V_93 , T_3 V_94 )
{
#define F_42 \
(FIF_PROMISC_IN_BSS | FIF_ALLMULTI | FIF_FCSFAIL | \
FIF_PLCPFAIL | FIF_CONTROL | FIF_OTHER_BSS | \
FIF_BCN_PRBRESP_PROMISC)
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_87 [ 2 ] , V_95 ;
struct V_96 V_97 ;
F_7 ( & V_6 -> V_19 ) ;
V_87 [ 0 ] = V_94 ;
V_87 [ 1 ] = V_94 >> 32 ;
V_92 &= F_42 ;
* V_93 &= F_42 ;
V_95 = ( F_43 ( V_6 ) & ( V_98 ) ) |
( V_99 | V_100 |
V_101 ) ;
if ( V_92 & ( V_102 | V_103 ) ) {
if ( * V_93 & V_102 )
F_44 ( V_104 , V_6 -> V_105 ) ;
else
F_45 ( V_104 , V_6 -> V_105 ) ;
}
if ( F_46 ( V_104 , V_6 -> V_105 ) )
V_95 |= V_106 ;
if ( * V_93 & V_107 ) {
V_87 [ 0 ] = ~ 0 ;
V_87 [ 1 ] = ~ 0 ;
}
if ( * V_93 & ( V_108 | V_109 ) )
V_95 |= V_98 ;
if ( ( * V_93 & V_110 ) || ( V_6 -> V_27 > 1 ) )
V_95 |= V_111 ;
if ( * V_93 & V_112 )
V_95 |= V_113 ;
switch ( V_6 -> V_30 ) {
case V_29 :
V_95 |= V_113 |
V_111 |
V_114 |
V_106 ;
break;
case V_20 :
case V_21 :
V_95 |= V_114 |
V_111 ;
break;
case V_28 :
if ( V_6 -> V_76 )
V_95 |= V_111 ;
default:
break;
}
V_97 . V_115 = NULL ;
V_97 . V_116 = 0 ;
V_97 . V_117 = false ;
F_47 ( V_6 -> V_2 , V_118 ,
& V_97 ) ;
if ( V_97 . V_116 > 1 ) {
V_95 |= V_106 ;
}
F_48 ( V_6 , V_95 ) ;
F_49 ( V_6 , V_87 [ 0 ] , V_87 [ 1 ] ) ;
V_6 -> V_119 = V_95 ;
F_16 ( & V_6 -> V_19 ) ;
}
static int
F_50 ( struct V_1 * V_2 , enum V_120 V_121 ,
struct V_13 * V_14 , struct V_122 * V_123 ,
struct V_124 * V_125 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_60 * V_61 = F_26 ( V_6 ) ;
int V_15 = 0 ;
if ( V_126 )
return - V_31 ;
switch ( V_125 -> V_127 ) {
case V_128 :
case V_129 :
case V_130 :
break;
case V_131 :
if ( V_61 -> V_132 & V_133 )
break;
return - V_31 ;
default:
F_3 ( 1 ) ;
return - V_134 ;
}
F_7 ( & V_6 -> V_19 ) ;
switch ( V_121 ) {
case V_135 :
V_15 = F_51 ( V_61 , V_14 , V_123 , V_125 ) ;
if ( V_15 >= 0 ) {
V_125 -> V_136 = V_15 ;
V_125 -> V_62 |= V_137 ;
if ( V_125 -> V_127 == V_130 )
V_125 -> V_62 |= V_138 ;
if ( V_125 -> V_127 == V_131 )
V_125 -> V_62 |= V_139 ;
V_15 = 0 ;
}
break;
case V_140 :
F_52 ( V_61 , V_125 ) ;
break;
default:
V_15 = - V_134 ;
}
F_28 () ;
F_16 ( & V_6 -> V_19 ) ;
return V_15 ;
}
static void
F_53 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_76 )
F_33 ( V_6 , V_141 ) ;
}
static void
F_54 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_33 ( V_6 , V_6 -> V_76 ?
V_77 : V_78 ) ;
}
static int
F_55 ( struct V_1 * V_2 ,
struct V_142 * V_143 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_56 ( V_6 ) ;
V_143 -> V_144 = V_6 -> V_143 . V_145 ;
V_143 -> V_146 = V_6 -> V_143 . V_147 ;
V_143 -> V_148 = V_6 -> V_143 . V_149 ;
V_143 -> V_150 = V_6 -> V_143 . V_151 ;
return 0 ;
}
static int
F_57 ( struct V_1 * V_2 , T_1 V_152 ,
const struct V_153 * V_154 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_155 V_156 ;
int V_15 = 0 ;
if ( V_152 >= V_6 -> V_9 . V_10 . V_11 )
return 0 ;
F_7 ( & V_6 -> V_19 ) ;
F_58 ( V_6 , V_152 , & V_156 ) ;
V_156 . V_157 = V_154 -> V_158 ;
V_156 . V_159 = V_154 -> V_160 ;
V_156 . V_161 = V_154 -> V_162 ;
V_156 . V_163 = V_154 -> V_164 ;
F_9 ( V_6 , V_79 ,
L_4
L_5 ,
V_152 , V_154 -> V_158 , V_154 -> V_160 ,
V_154 -> V_162 , V_154 -> V_164 ) ;
if ( F_59 ( V_6 , V_152 , & V_156 ) ) {
F_8 ( V_6 ,
L_6 , V_152 ) ;
V_15 = - V_165 ;
} else
F_60 ( V_6 , V_152 ) ;
F_16 ( & V_6 -> V_19 ) ;
return V_15 ;
}
static T_3
F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_62 ( V_6 ) ;
}
static void
F_63 ( struct V_1 * V_2 , T_3 V_166 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_64 ( V_6 , V_166 ) ;
}
static void
F_65 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_30 == V_21 )
F_66 ( V_6 , 0 ) ;
else
F_67 ( V_6 ) ;
}
static int
F_68 ( struct V_1 * V_2 , int V_167 , struct V_168 * V_169 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_44 * V_45 = & V_2 -> V_45 ;
struct V_60 * V_61 = F_26 ( V_6 ) ;
struct V_170 * V_171 = & V_61 -> V_172 ;
unsigned int div = V_61 -> V_173 * 1000 ;
if ( V_167 != 0 )
return - V_174 ;
F_69 ( & V_61 -> V_175 ) ;
F_70 ( V_61 ) ;
if ( V_171 -> V_176 > 0 ) {
V_6 -> V_169 . V_177 += V_171 -> V_176 / div ;
V_6 -> V_169 . V_178 += V_171 -> V_179 / div ;
V_6 -> V_169 . V_180 += V_171 -> V_181 / div ;
V_6 -> V_169 . V_182 += V_171 -> V_183 / div ;
}
memset ( V_171 , 0 , sizeof( * V_171 ) ) ;
F_71 ( & V_61 -> V_175 ) ;
memcpy ( V_169 , & V_6 -> V_169 , sizeof( * V_169 ) ) ;
V_169 -> V_47 = V_45 -> V_47 ;
V_169 -> V_184 = V_6 -> V_185 ;
V_169 -> V_186 = V_187 |
V_188 |
V_189 |
V_190 |
V_191 ;
return 0 ;
}
static void
F_72 ( struct V_1 * V_2 , T_4 V_192 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_7 ( & V_6 -> V_19 ) ;
F_73 ( V_6 , V_192 ) ;
F_16 ( & V_6 -> V_19 ) ;
}
static int
F_74 ( struct V_1 * V_2 , T_2 V_193 , T_2 V_194 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_193 == 1 && V_194 == 1 )
F_24 ( V_6 , V_195 ) ;
else if ( V_193 == 2 && V_194 == 2 )
F_24 ( V_6 , V_196 ) ;
else if ( ( V_193 & 3 ) == 3 && ( V_194 & 3 ) == 3 )
F_24 ( V_6 , V_197 ) ;
else
return - V_134 ;
return 0 ;
}
static int
F_75 ( struct V_1 * V_2 , T_2 * V_193 , T_2 * V_194 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
switch ( V_6 -> V_56 ) {
case V_195 :
* V_193 = 1 ; * V_194 = 1 ; break;
case V_196 :
* V_193 = 2 ; * V_194 = 2 ; break;
case V_197 :
* V_193 = 3 ; * V_194 = 3 ; break;
}
return 0 ;
}
static void F_76 ( struct V_1 * V_2 ,
T_2 * V_198 , T_2 * V_199 , T_2 * V_200 , T_2 * V_201 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
* V_198 = V_6 -> V_12 [ V_202 ] . V_203 ;
* V_199 = V_204 ;
* V_200 = * V_201 = V_205 ;
}
static int F_77 ( struct V_1 * V_2 , T_2 V_198 , T_2 V_200 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_8 ;
if ( V_200 != V_205 )
return - V_134 ;
if ( ! V_198 || V_198 > V_204 )
return - V_134 ;
for ( V_8 = 0 ; V_8 < F_78 ( V_6 -> V_12 ) ; V_8 ++ ) {
if ( ! V_6 -> V_12 [ V_8 ] . V_206 )
continue;
if ( V_6 -> V_12 [ V_8 ] . V_8 < V_202 ||
V_6 -> V_12 [ V_8 ] . V_8 > V_207 )
continue;
V_6 -> V_12 [ V_8 ] . V_203 = V_198 ;
if ( V_6 -> V_12 [ V_8 ] . V_208 >= V_6 -> V_12 [ V_8 ] . V_203 )
F_79 ( V_2 , V_6 -> V_12 [ V_8 ] . V_8 ) ;
}
return 0 ;
}
