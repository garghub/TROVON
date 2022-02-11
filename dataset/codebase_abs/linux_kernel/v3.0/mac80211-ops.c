static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_8 = F_2 ( V_4 ) ;
if ( F_3 ( V_8 >= V_6 -> V_9 -> V_10 . V_11 . V_12 ) ) {
F_4 ( V_4 ) ;
return;
}
F_5 ( V_2 , V_4 , & V_6 -> V_13 [ V_8 ] ) ;
}
static int
F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 -> V_7 ) ;
}
static void
F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_7 ) ;
}
static int
F_10 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_16 ;
struct V_17 * V_18 = ( void * ) V_15 -> V_19 ;
F_11 ( & V_6 -> V_20 ) ;
if ( ( V_15 -> type == V_21 ||
V_15 -> type == V_22 )
&& ( V_6 -> V_23 + V_6 -> V_24 ) >= V_25 ) {
V_16 = - V_26 ;
goto V_27;
}
if ( V_6 -> V_24 ||
( V_6 -> V_28 && V_15 -> type == V_22 ) ) {
F_12 ( V_6 , L_1 ) ;
V_16 = - V_26 ;
goto V_27;
}
switch ( V_15 -> type ) {
case V_21 :
case V_29 :
case V_22 :
case V_30 :
V_18 -> V_31 = V_15 -> type ;
break;
default:
V_16 = - V_32 ;
goto V_27;
}
V_6 -> V_28 ++ ;
F_13 ( V_6 , V_33 , L_2 , V_18 -> V_31 ) ;
if ( ( V_18 -> V_31 == V_21 ) ||
( V_18 -> V_31 == V_22 ) ||
( V_18 -> V_31 == V_30 ) ) {
int V_34 ;
F_3 ( F_14 ( & V_6 -> V_35 ) ) ;
V_18 -> V_36 = F_15 ( & V_6 -> V_35 , struct V_37 ,
V_38 ) ;
F_16 ( & V_18 -> V_36 -> V_38 ) ;
V_18 -> V_39 = 0 ;
for ( V_34 = 0 ; V_34 < V_25 ; V_34 ++ ) {
if ( ! V_6 -> V_39 [ V_34 ] ) {
V_18 -> V_39 = V_34 ;
break;
}
}
F_17 ( V_6 -> V_39 [ V_18 -> V_39 ] != NULL ) ;
V_6 -> V_39 [ V_18 -> V_39 ] = V_15 ;
if ( V_18 -> V_31 == V_21 )
V_6 -> V_23 ++ ;
else if ( V_18 -> V_31 == V_22 )
V_6 -> V_24 ++ ;
}
memcpy ( & V_6 -> V_40 , V_15 -> V_41 , V_42 ) ;
F_18 ( V_6 -> V_9 , V_15 -> V_41 ) ;
memcpy ( & V_18 -> V_40 , V_15 -> V_41 , V_42 ) ;
F_19 ( V_6 , V_15 ) ;
V_16 = 0 ;
V_27:
F_20 ( & V_6 -> V_20 ) ;
return V_16 ;
}
static void
F_21 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_18 = ( void * ) V_15 -> V_19 ;
unsigned int V_43 ;
F_11 ( & V_6 -> V_20 ) ;
V_6 -> V_28 -- ;
if ( V_18 -> V_36 ) {
F_22 ( V_6 , V_18 -> V_36 ) ;
F_23 ( & V_18 -> V_36 -> V_38 , & V_6 -> V_35 ) ;
for ( V_43 = 0 ; V_43 < V_25 ; V_43 ++ ) {
if ( V_6 -> V_39 [ V_43 ] == V_15 ) {
V_6 -> V_39 [ V_43 ] = NULL ;
break;
}
}
V_18 -> V_36 = NULL ;
}
if ( V_18 -> V_31 == V_21 )
V_6 -> V_23 -- ;
else if ( V_18 -> V_31 == V_22 )
V_6 -> V_24 -- ;
F_19 ( V_6 , NULL ) ;
F_20 ( & V_6 -> V_20 ) ;
}
static int
F_24 ( struct V_1 * V_2 , T_2 V_44 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_45 * V_9 = V_6 -> V_9 ;
struct V_46 * V_47 = & V_2 -> V_47 ;
int V_16 = 0 ;
int V_43 ;
F_11 ( & V_6 -> V_20 ) ;
if ( V_44 & V_48 ) {
V_16 = F_25 ( V_6 , V_47 -> V_49 ) ;
if ( V_16 < 0 )
goto V_50;
}
if ( ( V_44 & V_51 ) &&
( V_6 -> V_52 != V_47 -> V_52 ) ) {
V_6 -> V_52 = V_47 -> V_52 ;
F_26 ( V_9 , ( V_47 -> V_52 * 2 ) ) ;
}
if ( V_44 & V_53 ) {
V_9 -> V_54 = V_47 -> V_55 ;
V_9 -> V_56 = V_47 -> V_57 ;
for ( V_43 = 0 ; V_43 < V_9 -> V_10 . V_11 . V_12 ; V_43 ++ )
F_27 ( V_9 , V_43 ) ;
}
F_28 ( V_9 , V_9 -> V_58 ) ;
V_50:
F_20 ( & V_6 -> V_20 ) ;
return V_16 ;
}
static void
F_29 ( struct V_1 * V_2 , struct V_14 * V_15 ,
struct V_59 * V_60 , T_2 V_61 )
{
struct V_17 * V_18 = ( void * ) V_15 -> V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_45 * V_9 = V_6 -> V_9 ;
struct V_62 * V_63 = F_30 ( V_9 ) ;
unsigned long V_64 ;
F_11 ( & V_6 -> V_20 ) ;
if ( V_61 & V_65 ) {
memcpy ( V_63 -> V_66 , V_60 -> V_67 , V_42 ) ;
V_63 -> V_68 = 0 ;
F_31 ( V_9 ) ;
F_32 () ;
}
if ( V_61 & V_69 )
V_6 -> V_70 = V_60 -> V_71 ;
if ( V_61 & V_72 ) {
int V_73 ;
V_9 -> V_74 = V_60 -> V_75 ;
V_73 = F_33 ( V_9 ) +
3 * V_9 -> V_76 ;
F_34 ( V_9 , V_73 ) ;
}
if ( V_61 & V_77 ) {
V_18 -> V_78 = V_60 -> V_78 ;
if ( V_60 -> V_78 )
V_6 -> V_78 = V_60 -> V_78 ;
else
V_6 -> V_78 = F_35 ( V_6 ) ;
if ( V_6 -> V_31 == V_29 )
F_36 ( V_2 , V_6 -> V_78 ) ;
F_37 ( V_6 -> V_9 , V_6 -> V_78 ?
V_79 : V_80 ) ;
if ( V_60 -> V_78 ) {
F_13 ( V_6 , V_81 ,
L_3 ,
V_60 -> V_82 , V_63 -> V_66 ) ;
V_63 -> V_68 = V_60 -> V_82 ;
F_31 ( V_9 ) ;
}
}
if ( V_61 & V_83 ) {
F_38 ( & V_6 -> V_84 , V_64 ) ;
F_39 ( V_2 , V_15 ) ;
F_40 ( & V_6 -> V_84 , V_64 ) ;
}
if ( V_61 & V_85 )
V_6 -> V_86 = V_60 -> V_86 ;
if ( V_61 & ( V_83 | V_85 |
V_69 ) )
F_41 ( V_6 ) ;
F_20 ( & V_6 -> V_20 ) ;
}
static T_3
F_42 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
T_2 V_89 [ 2 ] , V_90 ;
T_4 V_91 ;
struct V_92 * V_93 ;
V_89 [ 0 ] = 0 ;
V_89 [ 1 ] = 1 ;
F_43 (ha, mc_list) {
V_90 = F_44 ( V_93 -> V_41 + 0 ) ;
V_91 = ( V_90 >> 18 ) ^ ( V_90 >> 12 ) ^ ( V_90 >> 6 ) ^ V_90 ;
V_90 = F_44 ( V_93 -> V_41 + 3 ) ;
V_91 ^= ( V_90 >> 18 ) ^ ( V_90 >> 12 ) ^ ( V_90 >> 6 ) ^ V_90 ;
V_91 &= 0x3f ;
V_89 [ V_91 / 32 ] |= ( 1 << ( V_91 % 32 ) ) ;
}
return ( ( T_3 ) ( V_89 [ 1 ] ) << 32 ) | V_89 [ 0 ] ;
}
static void
F_45 ( struct V_1 * V_2 , unsigned int V_94 ,
unsigned int * V_95 , T_3 V_96 )
{
#define F_46 \
(FIF_PROMISC_IN_BSS | FIF_ALLMULTI | FIF_FCSFAIL | \
FIF_PLCPFAIL | FIF_CONTROL | FIF_OTHER_BSS | \
FIF_BCN_PRBRESP_PROMISC)
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_45 * V_9 = V_6 -> V_9 ;
T_2 V_89 [ 2 ] , V_97 ;
struct V_98 V_99 ;
F_11 ( & V_6 -> V_20 ) ;
V_89 [ 0 ] = V_96 ;
V_89 [ 1 ] = V_96 >> 32 ;
V_94 &= F_46 ;
* V_95 &= F_46 ;
V_97 = ( F_47 ( V_9 ) & ( V_100 ) ) |
( V_101 | V_102 |
V_103 ) ;
if ( V_94 & ( V_104 | V_105 ) ) {
if ( * V_95 & V_104 )
F_48 ( V_106 , V_6 -> V_107 ) ;
else
F_49 ( V_106 , V_6 -> V_107 ) ;
}
if ( F_50 ( V_106 , V_6 -> V_107 ) )
V_97 |= V_108 ;
if ( * V_95 & V_109 ) {
V_89 [ 0 ] = ~ 0 ;
V_89 [ 1 ] = ~ 0 ;
}
if ( * V_95 & ( V_110 | V_111 ) )
V_97 |= V_100 ;
if ( ( * V_95 & V_112 ) || ( V_6 -> V_28 > 1 ) )
V_97 |= V_113 ;
if ( * V_95 & V_114 )
V_97 |= V_115 ;
switch ( V_6 -> V_31 ) {
case V_30 :
V_97 |= V_115 |
V_113 |
V_116 |
V_108 ;
break;
case V_21 :
case V_22 :
V_97 |= V_116 |
V_113 ;
break;
case V_29 :
if ( V_6 -> V_78 )
V_97 |= V_113 ;
default:
break;
}
V_99 . V_117 = NULL ;
V_99 . V_118 = 0 ;
V_99 . V_119 = false ;
F_51 ( V_6 -> V_2 , V_120 ,
& V_99 ) ;
if ( V_99 . V_118 > 1 ) {
V_97 |= V_108 ;
}
F_52 ( V_9 , V_97 ) ;
F_53 ( V_9 , V_89 [ 0 ] , V_89 [ 1 ] ) ;
V_6 -> V_121 = V_97 ;
F_20 ( & V_6 -> V_20 ) ;
}
static int
F_54 ( struct V_1 * V_2 , enum V_122 V_123 ,
struct V_14 * V_15 , struct V_124 * V_125 ,
struct V_126 * V_127 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_45 * V_9 = V_6 -> V_9 ;
struct V_62 * V_63 = F_30 ( V_9 ) ;
int V_16 = 0 ;
if ( V_128 )
return - V_32 ;
switch ( V_127 -> V_129 ) {
case V_130 :
case V_131 :
case V_132 :
break;
case V_133 :
if ( V_63 -> V_134 & V_135 )
break;
return - V_32 ;
default:
F_3 ( 1 ) ;
return - V_136 ;
}
F_11 ( & V_6 -> V_20 ) ;
switch ( V_123 ) {
case V_137 :
V_16 = F_55 ( V_63 , V_15 , V_125 , V_127 ) ;
if ( V_16 >= 0 ) {
V_127 -> V_138 = V_16 ;
V_127 -> V_64 |= V_139 ;
if ( V_127 -> V_129 == V_132 )
V_127 -> V_64 |= V_140 ;
if ( V_127 -> V_129 == V_133 )
V_127 -> V_64 |= V_141 ;
V_16 = 0 ;
}
break;
case V_142 :
F_56 ( V_63 , V_127 ) ;
break;
default:
V_16 = - V_136 ;
}
F_32 () ;
F_20 ( & V_6 -> V_20 ) ;
return V_16 ;
}
static void
F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_78 )
F_37 ( V_6 -> V_9 , V_143 ) ;
}
static void
F_58 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_37 ( V_6 -> V_9 , V_6 -> V_78 ?
V_79 : V_80 ) ;
}
static int
F_59 ( struct V_1 * V_2 ,
struct V_144 * V_145 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_60 ( V_6 -> V_9 ) ;
V_145 -> V_146 = V_6 -> V_145 . V_147 ;
V_145 -> V_148 = V_6 -> V_145 . V_149 ;
V_145 -> V_150 = V_6 -> V_145 . V_151 ;
V_145 -> V_152 = V_6 -> V_145 . V_153 ;
return 0 ;
}
static int
F_61 ( struct V_1 * V_2 , T_1 V_154 ,
const struct V_155 * V_156 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_45 * V_9 = V_6 -> V_9 ;
struct V_157 V_158 ;
int V_16 = 0 ;
if ( V_154 >= V_9 -> V_10 . V_11 . V_12 )
return 0 ;
F_11 ( & V_6 -> V_20 ) ;
F_62 ( V_9 , V_154 , & V_158 ) ;
V_158 . V_159 = V_156 -> V_160 ;
V_158 . V_161 = V_156 -> V_162 ;
V_158 . V_163 = V_156 -> V_164 ;
V_158 . V_165 = V_156 -> V_166 ;
F_13 ( V_6 , V_81 ,
L_4
L_5 ,
V_154 , V_156 -> V_160 , V_156 -> V_162 ,
V_156 -> V_164 , V_156 -> V_166 ) ;
if ( F_63 ( V_9 , V_154 , & V_158 ) ) {
F_12 ( V_6 ,
L_6 , V_154 ) ;
V_16 = - V_167 ;
} else
F_64 ( V_9 , V_154 ) ;
F_20 ( & V_6 -> V_20 ) ;
return V_16 ;
}
static T_3
F_65 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_66 ( V_6 -> V_9 ) ;
}
static void
F_67 ( struct V_1 * V_2 , T_3 V_168 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_68 ( V_6 -> V_9 , V_168 ) ;
}
static void
F_69 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_31 == V_22 )
F_70 ( V_6 , 0 ) ;
else
F_71 ( V_6 -> V_9 ) ;
}
static int
F_72 ( struct V_1 * V_2 , int V_169 , struct V_170 * V_171 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_46 * V_47 = & V_2 -> V_47 ;
struct V_62 * V_63 = F_30 ( V_6 -> V_9 ) ;
struct V_172 * V_173 = & V_63 -> V_174 ;
unsigned int div = V_63 -> V_175 * 1000 ;
if ( V_169 != 0 )
return - V_176 ;
F_73 ( & V_63 -> V_177 ) ;
F_74 ( V_63 ) ;
if ( V_173 -> V_178 > 0 ) {
V_6 -> V_171 . V_179 += V_173 -> V_178 / div ;
V_6 -> V_171 . V_180 += V_173 -> V_181 / div ;
V_6 -> V_171 . V_182 += V_173 -> V_183 / div ;
V_6 -> V_171 . V_184 += V_173 -> V_185 / div ;
}
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
F_75 ( & V_63 -> V_177 ) ;
memcpy ( V_171 , & V_6 -> V_171 , sizeof( * V_171 ) ) ;
V_171 -> V_49 = V_47 -> V_49 ;
V_171 -> V_186 = V_6 -> V_9 -> V_187 ;
V_171 -> V_188 = V_189 |
V_190 |
V_191 |
V_192 |
V_193 ;
return 0 ;
}
static void
F_76 ( struct V_1 * V_2 , T_4 V_194 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_11 ( & V_6 -> V_20 ) ;
F_77 ( V_6 -> V_9 , V_194 ) ;
F_20 ( & V_6 -> V_20 ) ;
}
static int
F_78 ( struct V_1 * V_2 , T_2 V_195 , T_2 V_196 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_195 == 1 && V_196 == 1 )
F_28 ( V_6 -> V_9 , V_197 ) ;
else if ( V_195 == 2 && V_196 == 2 )
F_28 ( V_6 -> V_9 , V_198 ) ;
else if ( ( V_195 & 3 ) == 3 && ( V_196 & 3 ) == 3 )
F_28 ( V_6 -> V_9 , V_199 ) ;
else
return - V_136 ;
return 0 ;
}
static int
F_79 ( struct V_1 * V_2 , T_2 * V_195 , T_2 * V_196 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
switch ( V_6 -> V_9 -> V_58 ) {
case V_197 :
* V_195 = 1 ; * V_196 = 1 ; break;
case V_198 :
* V_195 = 2 ; * V_196 = 2 ; break;
case V_199 :
* V_195 = 3 ; * V_196 = 3 ; break;
}
return 0 ;
}
static void F_80 ( struct V_1 * V_2 ,
T_2 * V_200 , T_2 * V_201 , T_2 * V_202 , T_2 * V_203 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
* V_200 = V_6 -> V_13 [ V_204 ] . V_205 ;
* V_201 = V_206 ;
* V_202 = * V_203 = V_207 ;
}
static int F_81 ( struct V_1 * V_2 , T_2 V_200 , T_2 V_202 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_8 ;
if ( V_202 != V_207 )
return - V_136 ;
if ( ! V_200 || V_200 > V_206 )
return - V_136 ;
for ( V_8 = 0 ; V_8 < F_82 ( V_6 -> V_13 ) ; V_8 ++ ) {
if ( ! V_6 -> V_13 [ V_8 ] . V_208 )
continue;
if ( V_6 -> V_13 [ V_8 ] . V_8 < V_204 ||
V_6 -> V_13 [ V_8 ] . V_8 > V_209 )
continue;
V_6 -> V_13 [ V_8 ] . V_205 = V_200 ;
if ( V_6 -> V_13 [ V_8 ] . V_210 >= V_6 -> V_13 [ V_8 ] . V_205 )
F_83 ( V_2 , V_6 -> V_13 [ V_8 ] . V_8 ) ;
}
return 0 ;
}
