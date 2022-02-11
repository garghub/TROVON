static inline unsigned int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 + V_5 + V_6 + V_7 ;
}
static unsigned int F_2 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
unsigned long V_9 ;
unsigned int V_10 ;
F_3 ( L_1 ) ;
V_9 = V_2 -> V_11 ;
V_10 = ( V_8 * ( V_9 / 1000000 ) ) / 256 ;
F_3 ( L_2 ) ;
return V_10 ;
}
static unsigned int F_4 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
unsigned long V_9 ;
unsigned int V_10 ;
F_3 ( L_3 ) ;
V_9 = V_2 -> V_11 ;
V_10 = ( V_12 * 256 ) / ( V_9 / 1000000 ) ;
F_3 ( L_4 ) ;
return V_10 ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned int V_13 , V_14 ;
unsigned int V_15 ;
V_13 = V_16 ;
V_14 = V_2 -> V_14 ;
if ( V_2 -> V_14 > 32 ) {
V_13 = V_17 ;
V_14 >>= 3 ;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_18 ; V_15 ++ ) {
F_6 ( V_2 -> V_19 [ V_15 ] , V_20 , V_21 ,
V_13 ) ;
if ( V_2 -> V_19 [ V_15 ] -> V_22 )
F_6 ( V_2 -> V_19 [ V_15 ] , V_23 ,
V_24 , V_14 ) ;
if ( V_2 -> V_19 [ V_15 ] -> V_25 )
F_6 ( V_2 -> V_19 [ V_15 ] , V_26 ,
V_24 , V_14 ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_18 ; V_15 ++ ) {
if ( ! V_2 -> V_19 [ V_15 ] -> V_22 )
break;
F_6 ( V_2 -> V_19 [ V_15 ] , V_23 , V_27 ,
V_2 -> V_28 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_29 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_30 ; V_15 ++ )
F_9 ( V_2 , V_15 , V_31 , V_32 , V_29 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_29 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_33 ; V_15 ++ )
F_9 ( V_2 , V_15 , V_34 , V_35 , V_29 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_29 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_30 ; V_15 ++ )
F_9 ( V_2 , V_15 , V_31 , V_36 , V_29 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_29 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_33 ; V_15 ++ )
F_9 ( V_2 , V_15 , V_34 , V_37 , V_29 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_18 ; V_15 ++ ) {
if ( ! V_2 -> V_19 [ V_15 ] -> V_25 )
break;
F_6 ( V_2 -> V_19 [ V_15 ] , V_38 , V_39 ,
V_2 -> V_40 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_18 ; V_15 ++ ) {
if ( ! V_2 -> V_19 [ V_15 ] -> V_25 )
break;
F_6 ( V_2 -> V_19 [ V_15 ] , V_26 , V_41 ,
V_2 -> V_42 ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_18 ; V_15 ++ ) {
if ( ! V_2 -> V_19 [ V_15 ] -> V_22 )
break;
F_6 ( V_2 -> V_19 [ V_15 ] , V_23 , V_43 , 1 ) ;
}
}
static void F_17 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_18 ; V_15 ++ ) {
if ( ! V_2 -> V_19 [ V_15 ] -> V_25 )
break;
F_6 ( V_2 -> V_19 [ V_15 ] , V_20 , V_44 , 1 ) ;
}
F_18 ( V_2 , V_45 , V_46 , V_47 ) ;
}
static int F_19 ( struct V_1 * V_2 , unsigned int type ,
unsigned int V_48 , unsigned int V_29 )
{
unsigned int V_49 ;
int V_10 = 0 ;
F_20 ( & V_2 -> V_50 ) ;
if ( F_21 ( V_2 , V_51 , V_52 ) ) {
V_10 = - V_53 ;
goto V_54;
}
F_22 ( V_2 , V_55 , V_29 ) ;
F_18 ( V_2 , V_51 , V_56 , V_48 ) ;
F_18 ( V_2 , V_51 , V_57 , type ) ;
F_18 ( V_2 , V_51 , V_58 , 0 ) ;
F_18 ( V_2 , V_51 , V_52 , 1 ) ;
V_49 = 1000 ;
while ( V_49 -- ) {
if ( ! F_21 ( V_2 , V_51 , V_52 ) )
goto V_54;
F_23 ( 1000 , 1500 ) ;
}
V_10 = - V_53 ;
V_54:
F_24 ( & V_2 -> V_50 ) ;
return V_10 ;
}
static int F_25 ( struct V_1 * V_2 )
{
unsigned int V_59 = sizeof( V_2 -> V_60 ) / sizeof( V_61 ) ;
unsigned int * V_62 = ( unsigned int * ) & V_2 -> V_60 ;
int V_10 ;
while ( V_59 -- ) {
V_10 = F_19 ( V_2 , V_63 ,
V_59 , * V_62 ++ ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
int V_10 ;
for ( V_15 = 0 ; V_15 < F_27 ( V_2 -> V_64 ) ; V_15 ++ ) {
V_10 = F_19 ( V_2 ,
V_65 , V_15 ,
V_2 -> V_64 [ V_15 ] ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , const T_1 * V_62 )
{
memcpy ( V_2 -> V_60 , V_62 , sizeof( V_2 -> V_60 ) ) ;
return F_25 ( V_2 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
const V_61 * V_66 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < F_27 ( V_2 -> V_64 ) ; V_15 ++ )
F_30 ( V_2 -> V_64 [ V_15 ] , V_55 , V_67 , V_66 [ V_15 ] ) ;
return F_26 ( V_2 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_10 ;
if ( ! V_2 -> V_68 . V_69 )
return - V_70 ;
V_10 = F_25 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_26 ( V_2 ) ;
if ( V_10 )
return V_10 ;
F_22 ( V_2 , V_71 , V_2 -> V_72 ) ;
F_18 ( V_2 , V_71 , V_73 , 1 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_68 . V_69 )
return - V_70 ;
F_18 ( V_2 , V_71 , V_73 , 0 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
int V_10 ;
if ( ! V_2 -> V_68 . V_69 )
return;
if ( V_2 -> V_3 -> V_74 & V_75 )
V_10 = F_31 ( V_2 ) ;
else
V_10 = F_32 ( V_2 ) ;
if ( V_10 )
F_34 ( V_2 -> V_3 ,
L_5 ) ;
}
static bool F_35 ( struct V_1 * V_2 ,
unsigned int V_76 )
{
unsigned int V_77 , V_78 ;
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ ) {
if ( V_2 -> V_80 [ V_77 ] != V_76 )
continue;
V_78 = V_2 -> V_81 -> V_82 [ V_77 ] ;
if ( V_2 -> V_83 -> V_84 & ( 1 << V_78 ) )
return true ;
}
return false ;
}
static int F_36 ( struct V_1 * V_2 )
{
unsigned int V_85 , V_86 ;
unsigned int V_87 , V_88 ;
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_30 ; V_15 ++ )
F_9 ( V_2 , V_15 , V_31 , V_89 , 0 ) ;
V_85 = V_90 ;
V_86 = F_37 (unsigned int, pdata->tx_q_count, max_q_count) ;
V_87 = V_91 ;
for ( V_15 = 0 ; V_15 < V_86 ; V_15 ++ ) {
V_88 = F_38 ( V_2 , V_87 ) ;
F_30 ( V_88 , V_91 , V_92 , 0 ) ;
F_22 ( V_2 , V_87 , V_88 ) ;
V_87 += V_93 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_94 * V_83 = V_2 -> V_83 ;
struct V_95 * V_81 = V_2 -> V_81 ;
unsigned int V_85 , V_86 ;
unsigned int V_87 , V_88 ;
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_30 ; V_15 ++ ) {
unsigned int V_96 = 0 ;
if ( V_2 -> V_97 [ V_15 ] ) {
if ( V_83 && V_81 ) {
if ( F_35 ( V_2 , V_15 ) )
V_96 = 1 ;
} else {
V_96 = 1 ;
}
}
F_9 ( V_2 , V_15 , V_31 , V_89 , V_96 ) ;
F_40 ( V_2 , V_98 , V_2 -> V_3 ,
L_6 ,
V_96 ? L_7 : L_8 , V_15 ) ;
}
V_85 = V_90 ;
V_86 = F_37 (unsigned int, pdata->tx_q_count, max_q_count) ;
V_87 = V_91 ;
for ( V_15 = 0 ; V_15 < V_86 ; V_15 ++ ) {
V_88 = F_38 ( V_2 , V_87 ) ;
F_30 ( V_88 , V_91 , V_92 , 1 ) ;
F_30 ( V_88 , V_91 , V_99 , 0xffff ) ;
F_22 ( V_2 , V_87 , V_88 ) ;
V_87 += V_93 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_100 , V_101 , 0 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_100 , V_101 , 1 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_94 * V_83 = V_2 -> V_83 ;
if ( V_2 -> V_102 || ( V_83 && V_83 -> V_84 ) )
F_39 ( V_2 ) ;
else
F_36 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_94 * V_83 = V_2 -> V_83 ;
if ( V_2 -> V_103 || ( V_83 && V_83 -> V_84 ) )
F_42 ( V_2 ) ;
else
F_41 ( V_2 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_94 * V_83 = V_2 -> V_83 ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
F_18 ( V_2 , V_100 , V_104 ,
( V_83 && V_83 -> V_84 ) ? 1 : 0 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_105 * V_19 ;
unsigned int V_106 , V_107 ;
unsigned int V_15 ;
if ( V_2 -> V_108 )
F_18 ( V_2 , V_109 , V_110 ,
V_2 -> V_108 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_18 ; V_15 ++ ) {
V_19 = V_2 -> V_19 [ V_15 ] ;
V_106 = F_47 ( V_19 , V_111 ) ;
F_48 ( V_19 , V_111 , V_106 ) ;
V_107 = 0 ;
F_30 ( V_107 , V_112 , V_113 , 1 ) ;
F_30 ( V_107 , V_112 , V_114 , 1 ) ;
F_30 ( V_107 , V_112 , V_115 , 1 ) ;
if ( V_19 -> V_22 ) {
if ( ! V_2 -> V_116 || V_2 -> V_108 )
F_30 ( V_107 , V_112 , V_117 , 1 ) ;
}
if ( V_19 -> V_25 ) {
F_30 ( V_107 , V_112 , V_118 , 1 ) ;
if ( ! V_2 -> V_116 || V_2 -> V_108 )
F_30 ( V_107 , V_112 , V_119 , 1 ) ;
}
F_48 ( V_19 , V_112 , V_107 ) ;
}
}
static void F_49 ( struct V_1 * V_2 )
{
unsigned int V_120 ;
unsigned int V_86 , V_15 ;
V_86 = F_50 ( V_2 -> V_68 . V_121 , V_2 -> V_68 . V_122 ) ;
for ( V_15 = 0 ; V_15 < V_86 ; V_15 ++ ) {
V_120 = F_51 ( V_2 , V_15 , V_123 ) ;
F_52 ( V_2 , V_15 , V_123 , V_120 ) ;
F_52 ( V_2 , V_15 , V_124 , 0 ) ;
}
}
static void F_53 ( struct V_1 * V_2 )
{
unsigned int V_125 = 0 ;
F_30 ( V_125 , V_126 , V_127 , 1 ) ;
F_22 ( V_2 , V_126 , V_125 ) ;
F_18 ( V_2 , V_128 , V_129 , 0xffffffff ) ;
F_18 ( V_2 , V_130 , V_129 , 0xffffffff ) ;
F_18 ( V_2 , V_131 , V_132 , 1 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned int V_133 , V_134 = 0 ;
if ( ! V_2 -> V_135 -> V_136 )
return;
V_133 = F_55 ( V_2 , V_137 ) ;
F_56 ( V_2 , V_137 , V_133 ) ;
F_57 ( V_134 , V_138 , V_139 , 1 ) ;
F_57 ( V_134 , V_138 , V_140 , 1 ) ;
F_57 ( V_134 , V_138 , V_141 , 1 ) ;
F_57 ( V_134 , V_138 , V_142 , 1 ) ;
F_57 ( V_134 , V_138 , V_143 , 1 ) ;
F_57 ( V_134 , V_138 , V_144 , 1 ) ;
F_56 ( V_2 , V_138 , V_134 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
unsigned int V_134 ;
V_134 = F_55 ( V_2 , V_138 ) ;
F_57 ( V_134 , V_138 , V_139 , 0 ) ;
F_57 ( V_134 , V_138 , V_141 , 0 ) ;
F_57 ( V_134 , V_138 , V_143 , 0 ) ;
F_56 ( V_2 , V_138 , V_134 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
enum V_145 V_146 )
{
unsigned int V_134 ;
V_134 = F_55 ( V_2 , V_138 ) ;
switch ( V_146 ) {
case V_147 :
F_57 ( V_134 , V_138 , V_140 , 0 ) ;
break;
case V_148 :
F_57 ( V_134 , V_138 , V_142 , 0 ) ;
break;
case V_149 :
F_57 ( V_134 , V_138 , V_144 , 0 ) ;
break;
}
F_56 ( V_2 , V_138 , V_134 ) ;
}
static int F_60 ( struct V_1 * V_2 , int V_150 )
{
unsigned int V_151 ;
switch ( V_150 ) {
case V_152 :
V_151 = 0x03 ;
break;
case V_153 :
V_151 = 0x02 ;
break;
case V_154 :
V_151 = 0x00 ;
break;
default:
return - V_155 ;
}
if ( F_21 ( V_2 , V_156 , V_157 ) != V_151 )
F_18 ( V_2 , V_156 , V_157 , V_151 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_158 , V_159 , 1 ) ;
F_18 ( V_2 , V_158 , V_160 , 1 ) ;
F_18 ( V_2 , V_158 , V_161 , 0 ) ;
F_18 ( V_2 , V_158 , V_162 , 0 ) ;
F_18 ( V_2 , V_158 , V_163 , 0x3 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_158 , V_163 , 0 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_164 , V_165 , 1 ) ;
F_18 ( V_2 , V_158 , V_166 , 1 ) ;
F_18 ( V_2 , V_158 , V_167 , 0 ) ;
F_18 ( V_2 , V_158 , V_168 , 1 ) ;
F_18 ( V_2 , V_158 , V_169 , 1 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_164 , V_165 , 0 ) ;
return 0 ;
}
static V_61 F_65 ( T_2 V_170 )
{
V_61 V_171 = 0xedb88320 ;
V_61 V_172 = ~ 0 ;
V_61 V_173 = 0 ;
unsigned char * V_174 = ( unsigned char * ) & V_170 ;
unsigned char V_175 = 0 ;
int V_15 , V_176 ;
V_176 = F_66 ( V_177 ) ;
for ( V_15 = 0 ; V_15 < V_176 ; V_15 ++ ) {
if ( ( V_15 % 8 ) == 0 )
V_175 = V_174 [ V_15 / 8 ] ;
V_173 = ( ( V_172 & 1 ) ^ V_175 ) & 1 ;
V_172 >>= 1 ;
V_175 >>= 1 ;
if ( V_173 )
V_172 ^= V_171 ;
}
return V_172 ;
}
static int F_67 ( struct V_1 * V_2 )
{
V_61 V_172 ;
T_3 V_178 ;
T_2 V_170 ;
T_3 V_179 = 0 ;
F_68 (vid, pdata->active_vlans, VLAN_N_VID) {
V_170 = F_69 ( V_178 ) ;
V_172 = F_70 ( ~ F_65 ( V_170 ) ) >> 28 ;
V_179 |= ( 1 << V_172 ) ;
}
F_18 ( V_2 , V_180 , V_181 , V_179 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
unsigned int V_182 )
{
unsigned int V_29 = V_182 ? 1 : 0 ;
if ( F_21 ( V_2 , V_164 , V_183 ) == V_29 )
return 0 ;
F_40 ( V_2 , V_98 , V_2 -> V_3 , L_9 ,
V_182 ? L_10 : L_11 ) ;
F_18 ( V_2 , V_164 , V_183 , V_29 ) ;
if ( V_182 ) {
F_64 ( V_2 ) ;
} else {
if ( V_2 -> V_3 -> V_74 & V_184 )
F_63 ( V_2 ) ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
unsigned int V_182 )
{
unsigned int V_29 = V_182 ? 1 : 0 ;
if ( F_21 ( V_2 , V_164 , V_185 ) == V_29 )
return 0 ;
F_40 ( V_2 , V_98 , V_2 -> V_3 , L_12 ,
V_182 ? L_10 : L_11 ) ;
F_18 ( V_2 , V_164 , V_185 , V_29 ) ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_186 * V_187 , unsigned int * V_188 )
{
unsigned int V_189 , V_190 ;
T_1 * V_191 ;
V_190 = 0 ;
V_189 = 0 ;
if ( V_187 ) {
V_191 = ( T_1 * ) & V_190 ;
V_191 [ 0 ] = V_187 -> V_192 [ 0 ] ;
V_191 [ 1 ] = V_187 -> V_192 [ 1 ] ;
V_191 [ 2 ] = V_187 -> V_192 [ 2 ] ;
V_191 [ 3 ] = V_187 -> V_192 [ 3 ] ;
V_191 = ( T_1 * ) & V_189 ;
V_191 [ 0 ] = V_187 -> V_192 [ 4 ] ;
V_191 [ 1 ] = V_187 -> V_192 [ 5 ] ;
F_40 ( V_2 , V_98 , V_2 -> V_3 ,
L_13 ,
V_187 -> V_192 , * V_188 ) ;
F_30 ( V_189 , V_193 , V_194 , 1 ) ;
}
F_22 ( V_2 , * V_188 , V_189 ) ;
* V_188 += V_195 ;
F_22 ( V_2 , * V_188 , V_190 ) ;
* V_188 += V_195 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_196 * V_3 = V_2 -> V_3 ;
struct V_186 * V_187 ;
unsigned int V_188 ;
unsigned int V_197 ;
V_188 = V_193 ;
V_197 = V_2 -> V_68 . V_198 ;
if ( F_75 ( V_3 ) > V_197 ) {
F_71 ( V_2 , 1 ) ;
} else {
F_76 (ha, netdev) {
F_73 ( V_2 , V_187 , & V_188 ) ;
V_197 -- ;
}
if ( F_77 ( V_3 ) > V_197 ) {
F_72 ( V_2 , 1 ) ;
} else {
F_78 (ha, netdev) {
F_73 ( V_2 , V_187 , & V_188 ) ;
V_197 -- ;
}
}
}
while ( V_197 -- )
F_73 ( V_2 , NULL , & V_188 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_196 * V_3 = V_2 -> V_3 ;
struct V_186 * V_187 ;
unsigned int V_199 ;
unsigned int V_200 , V_201 ;
V_61 V_202 [ V_203 ] ;
V_61 V_172 ;
unsigned int V_15 ;
V_200 = 26 - ( V_2 -> V_68 . V_204 >> 7 ) ;
V_201 = V_2 -> V_68 . V_204 / 32 ;
memset ( V_202 , 0 , sizeof( V_202 ) ) ;
F_76 (ha, netdev) {
V_172 = F_70 ( ~ F_80 ( ~ 0 , V_187 -> V_192 , V_205 ) ) ;
V_172 >>= V_200 ;
V_202 [ V_172 >> 5 ] |= ( 1 << ( V_172 & 0x1f ) ) ;
}
F_78 (ha, netdev) {
V_172 = F_70 ( ~ F_80 ( ~ 0 , V_187 -> V_192 , V_205 ) ) ;
V_172 >>= V_200 ;
V_202 [ V_172 >> 5 ] |= ( 1 << ( V_172 & 0x1f ) ) ;
}
V_199 = V_206 ;
for ( V_15 = 0 ; V_15 < V_201 ; V_15 ++ ) {
F_22 ( V_2 , V_199 , V_202 [ V_15 ] ) ;
V_199 += V_207 ;
}
}
static int F_81 ( struct V_1 * V_2 )
{
if ( V_2 -> V_68 . V_204 )
F_79 ( V_2 ) ;
else
F_74 ( V_2 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , T_1 * V_192 )
{
unsigned int V_189 , V_190 ;
V_189 = ( V_192 [ 5 ] << 8 ) | ( V_192 [ 4 ] << 0 ) ;
V_190 = ( V_192 [ 3 ] << 24 ) | ( V_192 [ 2 ] << 16 ) |
( V_192 [ 1 ] << 8 ) | ( V_192 [ 0 ] << 0 ) ;
F_22 ( V_2 , V_208 , V_189 ) ;
F_22 ( V_2 , V_209 , V_190 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_196 * V_3 = V_2 -> V_3 ;
unsigned int V_210 , V_211 ;
V_210 = ( ( V_3 -> V_212 & V_213 ) != 0 ) ;
V_211 = ( ( V_3 -> V_212 & V_214 ) != 0 ) ;
F_71 ( V_2 , V_210 ) ;
F_72 ( V_2 , V_211 ) ;
F_81 ( V_2 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , unsigned int V_215 )
{
unsigned int V_87 ;
if ( V_215 > 15 )
return - V_155 ;
V_87 = F_38 ( V_2 , V_216 ) ;
V_87 &= ~ ( 1 << ( V_215 + 16 ) ) ;
F_22 ( V_2 , V_216 , V_87 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 , unsigned int V_215 )
{
unsigned int V_87 ;
if ( V_215 > 15 )
return - V_155 ;
V_87 = F_38 ( V_2 , V_216 ) ;
V_87 |= ( 1 << ( V_215 + 16 ) ) ;
F_22 ( V_2 , V_216 , V_87 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 , int V_217 ,
int V_218 )
{
unsigned long V_212 ;
unsigned int V_219 , V_48 , V_220 ;
int V_221 ;
if ( V_218 & V_222 )
V_219 = V_218 & ~ V_222 ;
else
V_219 = ( V_2 -> V_223 << 16 ) | ( V_218 & 0xffff ) ;
V_219 <<= 1 ;
V_48 = V_219 & ~ V_2 -> V_224 ;
V_220 = V_2 -> V_225 + ( V_219 & V_2 -> V_224 ) ;
F_87 ( & V_2 -> V_226 , V_212 ) ;
F_88 ( V_2 , V_2 -> V_227 , V_48 ) ;
V_221 = F_89 ( V_2 , V_220 ) ;
F_90 ( & V_2 -> V_226 , V_212 ) ;
return V_221 ;
}
static void F_91 ( struct V_1 * V_2 , int V_217 ,
int V_218 , int V_221 )
{
unsigned long V_212 ;
unsigned int V_219 , V_48 , V_220 ;
if ( V_218 & V_222 )
V_219 = V_218 & ~ V_222 ;
else
V_219 = ( V_2 -> V_223 << 16 ) | ( V_218 & 0xffff ) ;
V_219 <<= 1 ;
V_48 = V_219 & ~ V_2 -> V_224 ;
V_220 = V_2 -> V_225 + ( V_219 & V_2 -> V_224 ) ;
F_87 ( & V_2 -> V_226 , V_212 ) ;
F_88 ( V_2 , V_2 -> V_227 , V_48 ) ;
F_92 ( V_2 , V_220 , V_221 ) ;
F_90 ( & V_2 -> V_226 , V_212 ) ;
}
static int F_93 ( struct V_1 * V_2 , int V_217 ,
int V_218 )
{
unsigned long V_212 ;
unsigned int V_219 ;
int V_221 ;
if ( V_218 & V_222 )
V_219 = V_218 & ~ V_222 ;
else
V_219 = ( V_2 -> V_223 << 16 ) | ( V_218 & 0xffff ) ;
F_87 ( & V_2 -> V_226 , V_212 ) ;
F_88 ( V_2 , V_228 , V_219 >> 8 ) ;
V_221 = F_94 ( V_2 , ( V_219 & 0xff ) << 2 ) ;
F_90 ( & V_2 -> V_226 , V_212 ) ;
return V_221 ;
}
static void F_95 ( struct V_1 * V_2 , int V_217 ,
int V_218 , int V_221 )
{
unsigned int V_219 ;
unsigned long V_212 ;
if ( V_218 & V_222 )
V_219 = V_218 & ~ V_222 ;
else
V_219 = ( V_2 -> V_223 << 16 ) | ( V_218 & 0xffff ) ;
F_87 ( & V_2 -> V_226 , V_212 ) ;
F_88 ( V_2 , V_228 , V_219 >> 8 ) ;
F_88 ( V_2 , ( V_219 & 0xff ) << 2 , V_221 ) ;
F_90 ( & V_2 -> V_226 , V_212 ) ;
}
static int F_96 ( struct V_1 * V_2 , int V_217 ,
int V_218 )
{
switch ( V_2 -> V_135 -> V_229 ) {
case V_230 :
return F_93 ( V_2 , V_217 , V_218 ) ;
case V_231 :
default:
return F_86 ( V_2 , V_217 , V_218 ) ;
}
}
static void F_97 ( struct V_1 * V_2 , int V_217 ,
int V_218 , int V_221 )
{
switch ( V_2 -> V_135 -> V_229 ) {
case V_230 :
return F_95 ( V_2 , V_217 , V_218 , V_221 ) ;
case V_231 :
default:
return F_91 ( V_2 , V_217 , V_218 , V_221 ) ;
}
}
static int F_98 ( struct V_1 * V_2 , int V_192 ,
int V_87 , T_3 V_29 )
{
unsigned int V_232 , V_233 ;
F_99 ( & V_2 -> V_234 ) ;
V_232 = 0 ;
F_30 ( V_232 , V_235 , V_236 , V_87 ) ;
F_30 ( V_232 , V_235 , V_237 , V_192 ) ;
F_22 ( V_2 , V_235 , V_232 ) ;
V_233 = 0 ;
F_30 ( V_233 , V_238 , V_239 , V_29 ) ;
F_30 ( V_233 , V_238 , V_240 , 1 ) ;
F_30 ( V_233 , V_238 , V_241 , 1 ) ;
F_22 ( V_2 , V_238 , V_233 ) ;
if ( ! F_100 ( & V_2 -> V_234 , V_242 ) ) {
F_34 ( V_2 -> V_3 , L_14 ) ;
return - V_243 ;
}
return 0 ;
}
static int F_101 ( struct V_1 * V_2 , int V_192 ,
int V_87 )
{
unsigned int V_232 , V_233 ;
F_99 ( & V_2 -> V_234 ) ;
V_232 = 0 ;
F_30 ( V_232 , V_235 , V_236 , V_87 ) ;
F_30 ( V_232 , V_235 , V_237 , V_192 ) ;
F_22 ( V_2 , V_235 , V_232 ) ;
V_233 = 0 ;
F_30 ( V_233 , V_238 , V_240 , 3 ) ;
F_30 ( V_233 , V_238 , V_241 , 1 ) ;
F_22 ( V_2 , V_238 , V_233 ) ;
if ( ! F_100 ( & V_2 -> V_234 , V_242 ) ) {
F_34 ( V_2 -> V_3 , L_15 ) ;
return - V_243 ;
}
return F_21 ( V_2 , V_238 , V_239 ) ;
}
static int F_102 ( struct V_1 * V_2 , unsigned int V_244 ,
enum V_245 V_246 )
{
unsigned int V_88 = F_38 ( V_2 , V_247 ) ;
switch ( V_246 ) {
case V_248 :
if ( V_244 > V_249 )
return - V_155 ;
V_88 |= ( 1 << V_244 ) ;
break;
case V_250 :
break;
default:
return - V_155 ;
}
F_22 ( V_2 , V_247 , V_88 ) ;
return 0 ;
}
static int F_103 ( struct V_251 * V_252 )
{
return ! F_104 ( V_252 -> V_253 , V_254 , V_255 ) ;
}
static int F_105 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_45 , V_256 , 0 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_45 , V_256 , 1 ) ;
return 0 ;
}
static void F_107 ( struct V_257 * V_258 )
{
struct V_251 * V_252 = V_258 -> V_252 ;
V_252 -> V_259 = 0 ;
V_252 -> V_260 = 0 ;
V_252 -> V_261 = 0 ;
V_252 -> V_253 = 0 ;
F_108 () ;
}
static void F_109 ( struct V_105 * V_19 )
{
struct V_262 * V_263 = V_19 -> V_22 ;
struct V_257 * V_258 ;
int V_15 ;
int V_264 = V_263 -> V_265 ;
F_3 ( L_16 ) ;
for ( V_15 = 0 ; V_15 < V_263 -> V_266 ; V_15 ++ ) {
V_258 = F_110 ( V_263 , V_15 ) ;
F_107 ( V_258 ) ;
}
F_48 ( V_19 , V_267 , V_263 -> V_266 - 1 ) ;
V_258 = F_110 ( V_263 , V_264 ) ;
F_48 ( V_19 , V_268 ,
F_111 ( V_258 -> V_269 ) ) ;
F_48 ( V_19 , V_270 ,
F_112 ( V_258 -> V_269 ) ) ;
F_3 ( L_17 ) ;
}
static void F_113 ( struct V_1 * V_2 ,
struct V_257 * V_258 , unsigned int V_48 )
{
struct V_251 * V_252 = V_258 -> V_252 ;
unsigned int V_271 = V_2 -> V_271 ;
unsigned int V_272 = V_2 -> V_272 ;
unsigned int V_273 ;
T_4 V_274 , V_275 ;
if ( ! V_271 && ! V_272 ) {
V_273 = 1 ;
} else {
if ( V_272 && ! ( ( V_48 + 1 ) % V_272 ) )
V_273 = 1 ;
else
V_273 = 0 ;
}
V_274 = V_258 -> V_276 . V_277 . V_278 + V_258 -> V_276 . V_277 . V_279 ;
V_275 = V_258 -> V_276 . V_280 . V_278 + V_258 -> V_276 . V_280 . V_279 ;
V_252 -> V_259 = F_114 ( F_112 ( V_274 ) ) ;
V_252 -> V_260 = F_114 ( F_111 ( V_274 ) ) ;
V_252 -> V_261 = F_114 ( F_112 ( V_275 ) ) ;
V_252 -> V_253 = F_114 ( F_111 ( V_275 ) ) ;
F_115 ( V_252 -> V_253 , V_281 , V_282 , V_273 ) ;
F_108 () ;
F_115 ( V_252 -> V_253 , V_281 , V_255 , 1 ) ;
F_108 () ;
}
static void F_116 ( struct V_105 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_262 * V_263 = V_19 -> V_25 ;
struct V_257 * V_258 ;
unsigned int V_264 = V_263 -> V_265 ;
unsigned int V_15 ;
F_3 ( L_18 ) ;
for ( V_15 = 0 ; V_15 < V_263 -> V_266 ; V_15 ++ ) {
V_258 = F_110 ( V_263 , V_15 ) ;
F_113 ( V_2 , V_258 , V_15 ) ;
}
F_48 ( V_19 , V_283 , V_263 -> V_266 - 1 ) ;
V_258 = F_110 ( V_263 , V_264 ) ;
F_48 ( V_19 , V_284 ,
F_111 ( V_258 -> V_269 ) ) ;
F_48 ( V_19 , V_285 ,
F_112 ( V_258 -> V_269 ) ) ;
V_258 = F_110 ( V_263 , V_264 + V_263 -> V_266 - 1 ) ;
F_48 ( V_19 , V_286 ,
F_112 ( V_258 -> V_269 ) ) ;
F_3 ( L_19 ) ;
}
static void F_117 ( struct V_1 * V_2 ,
unsigned int V_287 )
{
unsigned int V_288 = 10000 ;
F_22 ( V_2 , V_289 , V_287 ) ;
F_18 ( V_2 , V_290 , V_291 , 1 ) ;
while ( -- V_288 && F_21 ( V_2 , V_290 , V_291 ) )
F_118 ( 5 ) ;
if ( ! V_288 )
F_34 ( V_2 -> V_3 ,
L_20 ) ;
}
static void F_119 ( struct V_1 * V_2 , unsigned int V_146 ,
unsigned int V_292 )
{
unsigned int V_288 = 10000 ;
F_22 ( V_2 , V_293 , V_146 ) ;
F_22 ( V_2 , V_294 , V_292 ) ;
F_18 ( V_2 , V_290 , V_295 , 1 ) ;
while ( -- V_288 && F_21 ( V_2 , V_290 , V_295 ) )
F_118 ( 5 ) ;
if ( ! V_288 )
F_34 ( V_2 -> V_3 , L_21 ) ;
}
static T_5 F_120 ( struct V_1 * V_2 )
{
T_5 V_292 ;
V_292 = F_38 ( V_2 , V_296 ) ;
V_292 *= V_297 ;
V_292 += F_38 ( V_2 , V_298 ) ;
return V_292 ;
}
static T_5 F_121 ( struct V_1 * V_2 )
{
unsigned int V_299 , V_300 ;
T_5 V_292 ;
if ( V_2 -> V_135 -> V_301 ) {
V_299 = F_38 ( V_2 , V_302 ) ;
V_300 = F_38 ( V_2 , V_303 ) ;
} else {
V_300 = F_38 ( V_2 , V_303 ) ;
V_299 = F_38 ( V_2 , V_302 ) ;
}
if ( F_122 ( V_299 , V_302 , V_304 ) )
return 0 ;
V_292 = V_300 ;
V_292 *= V_297 ;
V_292 += V_299 ;
return V_292 ;
}
static void F_123 ( struct V_305 * V_306 ,
struct V_251 * V_252 )
{
T_5 V_292 ;
if ( F_104 ( V_252 -> V_253 , V_307 , V_308 ) &&
! F_104 ( V_252 -> V_253 , V_307 , V_309 ) ) {
V_292 = F_124 ( V_252 -> V_260 ) ;
V_292 <<= 32 ;
V_292 |= F_124 ( V_252 -> V_259 ) ;
if ( V_292 != 0xffffffffffffffffULL ) {
V_306 -> V_310 = V_292 ;
F_30 ( V_306 -> V_311 , V_312 ,
V_313 , 1 ) ;
}
}
}
static int F_125 ( struct V_1 * V_2 ,
unsigned int V_314 )
{
F_30 ( V_314 , V_290 , V_315 , 1 ) ;
F_30 ( V_314 , V_290 , V_316 , 1 ) ;
F_30 ( V_314 , V_290 , V_317 , 1 ) ;
F_22 ( V_2 , V_290 , V_314 ) ;
if ( ! F_122 ( V_314 , V_290 , V_318 ) )
return 0 ;
F_18 ( V_2 , V_319 , V_320 , V_321 ) ;
F_18 ( V_2 , V_319 , V_322 , V_323 ) ;
F_117 ( V_2 , V_2 -> V_324 ) ;
F_119 ( V_2 , 0 , 0 ) ;
F_126 ( & V_2 -> V_325 , & V_2 -> V_326 ,
F_127 ( F_128 () ) ) ;
return 0 ;
}
static void F_129 ( struct V_105 * V_19 ,
struct V_262 * V_263 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_257 * V_258 ;
F_130 () ;
V_258 = F_110 ( V_263 , V_263 -> V_265 ) ;
F_48 ( V_19 , V_327 ,
F_112 ( V_258 -> V_269 ) ) ;
if ( V_2 -> V_328 && ! V_19 -> V_329 ) {
V_19 -> V_329 = 1 ;
F_131 ( & V_19 -> V_330 ,
V_331 + F_132 ( V_2 -> V_328 ) ) ;
}
V_263 -> V_332 . V_333 = 0 ;
}
static void F_133 ( struct V_105 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_262 * V_263 = V_19 -> V_22 ;
struct V_257 * V_258 ;
struct V_251 * V_252 ;
struct V_305 * V_306 = & V_263 -> V_334 ;
unsigned int V_335 , V_336 , V_337 ;
unsigned int V_338 , V_339 ;
unsigned int V_340 ;
int V_264 = V_263 -> V_265 ;
int V_341 = V_263 -> V_265 ;
int V_15 ;
F_3 ( L_22 ) ;
V_335 = F_122 ( V_306 -> V_311 , V_342 ,
V_343 ) ;
V_336 = F_122 ( V_306 -> V_311 , V_342 ,
V_344 ) ;
V_337 = F_122 ( V_306 -> V_311 , V_342 ,
V_345 ) ;
if ( V_336 && ( V_306 -> V_346 != V_263 -> V_332 . V_347 ) )
V_338 = 1 ;
else
V_338 = 0 ;
if ( V_337 && ( V_306 -> V_348 != V_263 -> V_332 . V_349 ) )
V_339 = 1 ;
else
V_339 = 0 ;
V_263 -> V_350 += V_306 -> V_351 ;
if ( ! V_2 -> V_352 )
V_340 = 0 ;
else if ( V_306 -> V_351 > V_2 -> V_352 )
V_340 = 1 ;
else if ( ( V_263 -> V_350 % V_2 -> V_352 ) <
V_306 -> V_351 )
V_340 = 1 ;
else
V_340 = 0 ;
V_258 = F_110 ( V_263 , V_341 ) ;
V_252 = V_258 -> V_252 ;
if ( V_338 || V_339 ) {
if ( V_338 ) {
F_40 ( V_2 , V_353 , V_2 -> V_3 ,
L_23 ,
V_306 -> V_346 ) ;
F_115 ( V_252 -> V_261 , V_354 ,
V_355 , V_306 -> V_346 ) ;
F_115 ( V_252 -> V_253 , V_356 ,
V_357 , 1 ) ;
F_115 ( V_252 -> V_253 , V_356 ,
V_358 , 1 ) ;
V_263 -> V_332 . V_347 = V_306 -> V_346 ;
}
if ( V_339 ) {
F_40 ( V_2 , V_353 , V_2 -> V_3 ,
L_24 ,
V_306 -> V_348 ) ;
F_115 ( V_252 -> V_253 , V_356 ,
V_357 , 1 ) ;
F_115 ( V_252 -> V_253 , V_356 ,
V_359 , V_306 -> V_348 ) ;
F_115 ( V_252 -> V_253 , V_356 ,
V_360 , 1 ) ;
V_263 -> V_332 . V_349 = V_306 -> V_348 ;
}
V_341 ++ ;
V_258 = F_110 ( V_263 , V_341 ) ;
V_252 = V_258 -> V_252 ;
}
V_252 -> V_259 = F_114 ( F_112 ( V_258 -> V_361 ) ) ;
V_252 -> V_260 = F_114 ( F_111 ( V_258 -> V_361 ) ) ;
F_115 ( V_252 -> V_261 , V_362 , V_363 ,
V_258 -> V_364 ) ;
if ( V_337 )
F_115 ( V_252 -> V_261 , V_362 , V_365 ,
V_366 ) ;
if ( F_122 ( V_306 -> V_311 , V_342 , V_367 ) )
F_115 ( V_252 -> V_261 , V_362 , V_368 , 1 ) ;
F_115 ( V_252 -> V_253 , V_254 , V_369 , 1 ) ;
F_115 ( V_252 -> V_253 , V_254 , V_357 , 0 ) ;
if ( V_341 != V_264 )
F_115 ( V_252 -> V_253 , V_254 , V_255 , 1 ) ;
if ( V_336 ) {
F_115 ( V_252 -> V_253 , V_254 , V_43 , 1 ) ;
F_115 ( V_252 -> V_253 , V_254 , V_370 ,
V_306 -> V_371 ) ;
F_115 ( V_252 -> V_253 , V_254 , V_372 ,
V_306 -> V_373 / 4 ) ;
V_2 -> V_374 . V_375 ++ ;
} else {
F_115 ( V_252 -> V_253 , V_254 , V_376 , 0 ) ;
if ( V_335 )
F_115 ( V_252 -> V_253 , V_254 ,
V_377 , 0x3 ) ;
F_115 ( V_252 -> V_253 , V_254 , V_378 ,
V_306 -> V_379 ) ;
}
for ( V_15 = V_341 - V_264 + 1 ; V_15 < V_306 -> V_266 ; V_15 ++ ) {
V_341 ++ ;
V_258 = F_110 ( V_263 , V_341 ) ;
V_252 = V_258 -> V_252 ;
V_252 -> V_259 = F_114 ( F_112 ( V_258 -> V_361 ) ) ;
V_252 -> V_260 = F_114 ( F_111 ( V_258 -> V_361 ) ) ;
F_115 ( V_252 -> V_261 , V_362 , V_363 ,
V_258 -> V_364 ) ;
F_115 ( V_252 -> V_253 , V_254 , V_255 , 1 ) ;
F_115 ( V_252 -> V_253 , V_254 , V_357 , 0 ) ;
if ( V_335 )
F_115 ( V_252 -> V_253 , V_254 ,
V_377 , 0x3 ) ;
}
F_115 ( V_252 -> V_253 , V_254 , V_380 , 1 ) ;
if ( V_340 )
F_115 ( V_252 -> V_261 , V_362 , V_381 , 1 ) ;
V_258 -> V_332 . V_382 = V_306 -> V_351 ;
V_258 -> V_332 . V_383 = V_306 -> V_384 ;
F_108 () ;
V_258 = F_110 ( V_263 , V_264 ) ;
V_252 = V_258 -> V_252 ;
F_115 ( V_252 -> V_253 , V_254 , V_255 , 1 ) ;
if ( F_134 ( V_2 ) )
F_135 ( V_2 , V_263 , V_264 ,
V_306 -> V_266 , 1 ) ;
F_136 () ;
V_263 -> V_265 = V_341 + 1 ;
if ( ! V_306 -> V_385 -> V_333 ||
F_137 ( F_138 ( V_2 -> V_3 ,
V_19 -> V_386 ) ) )
F_129 ( V_19 , V_263 ) ;
else
V_263 -> V_332 . V_333 = 1 ;
F_3 ( L_25 ,
V_19 -> V_387 , V_264 & ( V_263 -> V_266 - 1 ) ,
( V_263 -> V_265 - 1 ) & ( V_263 -> V_266 - 1 ) ) ;
F_3 ( L_26 ) ;
}
static int F_139 ( struct V_105 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_262 * V_263 = V_19 -> V_25 ;
struct V_257 * V_258 ;
struct V_251 * V_252 ;
struct V_305 * V_306 = & V_263 -> V_334 ;
struct V_196 * V_3 = V_2 -> V_3 ;
unsigned int V_388 , V_389 , V_390 ;
F_3 ( L_27 , V_263 -> V_265 ) ;
V_258 = F_110 ( V_263 , V_263 -> V_265 ) ;
V_252 = V_258 -> V_252 ;
if ( F_104 ( V_252 -> V_253 , V_281 , V_255 ) )
return 1 ;
F_140 () ;
if ( F_141 ( V_2 ) )
F_142 ( V_2 , V_263 , V_263 -> V_265 ) ;
if ( F_104 ( V_252 -> V_253 , V_281 , V_357 ) ) {
F_123 ( V_306 , V_252 ) ;
F_30 ( V_306 -> V_311 , V_312 ,
V_391 , 1 ) ;
F_30 ( V_306 -> V_311 , V_312 ,
V_392 , 0 ) ;
return 0 ;
}
F_30 ( V_306 -> V_311 , V_312 , V_391 , 0 ) ;
if ( F_104 ( V_252 -> V_253 , V_281 , V_393 ) )
F_30 ( V_306 -> V_311 , V_312 ,
V_392 , 1 ) ;
if ( F_104 ( V_252 -> V_253 , V_281 , V_369 ) ) {
F_30 ( V_306 -> V_311 , V_312 ,
V_394 , 1 ) ;
V_258 -> V_276 . V_395 = F_104 ( V_252 -> V_261 ,
V_396 , V_397 ) ;
if ( V_258 -> V_276 . V_395 )
V_2 -> V_374 . V_398 ++ ;
} else {
F_30 ( V_306 -> V_311 , V_312 ,
V_394 , 0 ) ;
}
if ( F_104 ( V_252 -> V_253 , V_281 , V_399 ) ) {
F_30 ( V_306 -> V_311 , V_312 ,
V_400 , 1 ) ;
V_306 -> V_401 = F_124 ( V_252 -> V_260 ) ;
V_390 = F_104 ( V_252 -> V_253 , V_281 , V_402 ) ;
switch ( V_390 ) {
case V_403 :
case V_404 :
case V_405 :
case V_406 :
V_306 -> V_407 = V_408 ;
break;
default:
V_306 -> V_407 = V_409 ;
}
}
if ( ! F_104 ( V_252 -> V_253 , V_281 , V_380 ) )
return 0 ;
F_30 ( V_306 -> V_311 , V_312 ,
V_410 , 1 ) ;
V_258 -> V_276 . V_411 = F_104 ( V_252 -> V_253 , V_281 , V_412 ) ;
if ( V_3 -> V_74 & V_413 )
F_30 ( V_306 -> V_311 , V_312 ,
V_414 , 1 ) ;
V_388 = F_104 ( V_252 -> V_253 , V_281 , V_415 ) ;
V_389 = F_104 ( V_252 -> V_253 , V_281 , V_416 ) ;
F_40 ( V_2 , V_417 , V_3 , L_28 , V_388 , V_389 ) ;
if ( ! V_388 || ! V_389 ) {
if ( ( V_389 == 0x09 ) &&
( V_3 -> V_74 & V_418 ) ) {
F_30 ( V_306 -> V_311 , V_312 ,
V_345 , 1 ) ;
V_306 -> V_348 = F_104 ( V_252 -> V_259 ,
V_419 ,
V_420 ) ;
F_40 ( V_2 , V_417 , V_3 , L_29 ,
V_306 -> V_348 ) ;
}
} else {
if ( ( V_389 == 0x05 ) || ( V_389 == 0x06 ) )
F_30 ( V_306 -> V_311 , V_312 ,
V_414 , 0 ) ;
else
F_30 ( V_306 -> V_421 , V_422 ,
V_423 , 1 ) ;
}
F_3 ( L_30 , V_19 -> V_387 ,
V_263 -> V_265 & ( V_263 -> V_266 - 1 ) , V_263 -> V_265 ) ;
return 0 ;
}
static int F_143 ( struct V_251 * V_252 )
{
return F_104 ( V_252 -> V_253 , V_254 , V_357 ) ;
}
static int F_144 ( struct V_251 * V_252 )
{
return F_104 ( V_252 -> V_253 , V_254 , V_380 ) ;
}
static int F_145 ( struct V_105 * V_19 ,
enum V_424 V_425 )
{
unsigned int V_107 ;
V_107 = F_47 ( V_19 , V_112 ) ;
switch ( V_425 ) {
case V_426 :
F_30 ( V_107 , V_112 , V_117 , 1 ) ;
break;
case V_427 :
F_30 ( V_107 , V_112 , V_428 , 1 ) ;
break;
case V_429 :
F_30 ( V_107 , V_112 , V_430 , 1 ) ;
break;
case V_431 :
F_30 ( V_107 , V_112 , V_119 , 1 ) ;
break;
case V_432 :
F_30 ( V_107 , V_112 , V_118 , 1 ) ;
break;
case V_433 :
F_30 ( V_107 , V_112 , V_434 , 1 ) ;
break;
case V_435 :
F_30 ( V_107 , V_112 , V_117 , 1 ) ;
F_30 ( V_107 , V_112 , V_119 , 1 ) ;
break;
case V_436 :
F_30 ( V_107 , V_112 , V_115 , 1 ) ;
break;
case V_437 :
V_107 |= V_19 -> V_438 ;
break;
default:
return - 1 ;
}
F_48 ( V_19 , V_112 , V_107 ) ;
return 0 ;
}
static int F_146 ( struct V_105 * V_19 ,
enum V_424 V_425 )
{
unsigned int V_107 ;
V_107 = F_47 ( V_19 , V_112 ) ;
switch ( V_425 ) {
case V_426 :
F_30 ( V_107 , V_112 , V_117 , 0 ) ;
break;
case V_427 :
F_30 ( V_107 , V_112 , V_428 , 0 ) ;
break;
case V_429 :
F_30 ( V_107 , V_112 , V_430 , 0 ) ;
break;
case V_431 :
F_30 ( V_107 , V_112 , V_119 , 0 ) ;
break;
case V_432 :
F_30 ( V_107 , V_112 , V_118 , 0 ) ;
break;
case V_433 :
F_30 ( V_107 , V_112 , V_434 , 0 ) ;
break;
case V_435 :
F_30 ( V_107 , V_112 , V_117 , 0 ) ;
F_30 ( V_107 , V_112 , V_119 , 0 ) ;
break;
case V_436 :
F_30 ( V_107 , V_112 , V_115 , 0 ) ;
break;
case V_437 :
V_19 -> V_438 = V_107 & V_439 ;
V_107 &= ~ V_439 ;
break;
default:
return - 1 ;
}
F_48 ( V_19 , V_112 , V_107 ) ;
return 0 ;
}
static int F_147 ( struct V_1 * V_2 )
{
unsigned int V_288 = 2000 ;
F_3 ( L_31 ) ;
F_18 ( V_2 , V_109 , V_440 , 1 ) ;
F_23 ( 10 , 15 ) ;
while ( -- V_288 && F_21 ( V_2 , V_109 , V_440 ) )
F_23 ( 500 , 600 ) ;
if ( ! V_288 )
return - V_53 ;
F_3 ( L_32 ) ;
return 0 ;
}
static int F_148 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_147 ( V_2 ) ;
if ( V_10 )
return V_10 ;
return F_147 ( V_2 ) ;
}
static int F_149 ( struct V_1 * V_2 )
{
unsigned int V_15 , V_288 ;
if ( F_122 ( V_2 -> V_68 . V_441 , V_442 , V_443 ) < 0x21 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_33 ; V_15 ++ )
F_9 ( V_2 , V_15 , V_34 , V_444 , 1 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_33 ; V_15 ++ ) {
V_288 = 2000 ;
while ( -- V_288 && F_150 ( V_2 , V_15 ,
V_34 , V_444 ) )
F_23 ( 500 , 600 ) ;
if ( ! V_288 )
return - V_53 ;
}
return 0 ;
}
static void F_151 ( struct V_1 * V_2 )
{
unsigned int V_445 ;
V_445 = F_38 ( V_2 , V_446 ) ;
F_30 ( V_445 , V_446 , V_447 , 1 ) ;
F_30 ( V_445 , V_446 , UNDEF , 1 ) ;
F_30 ( V_445 , V_446 , V_448 , V_2 -> V_449 >> 2 ) ;
F_30 ( V_445 , V_446 , V_450 , V_2 -> V_451 ) ;
F_30 ( V_445 , V_446 , V_452 , V_2 -> V_453 - 1 ) ;
F_30 ( V_445 , V_446 , V_454 , V_2 -> V_455 - 1 ) ;
F_22 ( V_2 , V_446 , V_445 ) ;
if ( V_2 -> V_135 -> V_456 )
F_18 ( V_2 , V_457 , V_458 ,
V_2 -> V_135 -> V_456 ) ;
if ( V_2 -> V_135 -> V_459 )
F_18 ( V_2 , V_460 , V_461 ,
V_2 -> V_135 -> V_459 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_462 , V_2 -> V_463 ) ;
F_22 ( V_2 , V_464 , V_2 -> V_465 ) ;
if ( V_2 -> V_466 )
F_22 ( V_2 , V_467 , V_2 -> V_466 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
F_18 ( V_2 , V_468 , V_469 , V_470 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_68 . V_471 ; V_15 ++ ) {
F_9 ( V_2 , V_15 , V_472 , V_308 ,
V_473 ) ;
F_9 ( V_2 , V_15 , V_474 , V_475 , 1 ) ;
}
F_18 ( V_2 , V_468 , V_476 , V_477 ) ;
}
static void F_154 ( struct V_1 * V_2 ,
unsigned int V_76 ,
unsigned int V_478 )
{
unsigned int V_479 ;
unsigned int V_480 , V_481 ;
V_479 = F_155 ( F_1 ( V_2 ) ) ;
if ( V_2 -> V_482 [ V_76 ] && ( V_478 > V_2 -> V_483 ) ) {
V_480 = V_2 -> V_483 ;
V_481 = V_480 + V_479 ;
if ( V_481 > V_484 )
V_481 = V_484 ;
if ( V_480 >= V_484 )
V_480 = V_484 - V_485 ;
} else {
if ( V_478 <= 2048 ) {
V_2 -> V_486 [ V_76 ] = 0 ;
V_2 -> V_97 [ V_76 ] = 0 ;
return;
}
if ( V_478 <= 4096 ) {
V_2 -> V_486 [ V_76 ] = 0 ;
V_2 -> V_97 [ V_76 ] = 1 ;
return;
}
if ( V_478 <= V_479 ) {
V_2 -> V_486 [ V_76 ] = 2 ;
V_2 -> V_97 [ V_76 ] = 5 ;
return;
}
if ( V_478 <= ( V_479 * 3 ) ) {
V_480 = V_478 - V_479 ;
V_481 = V_480 + ( V_479 / 2 ) ;
} else {
V_480 = V_479 * 2 ;
V_480 += V_485 ;
V_481 = V_480 + V_479 ;
}
}
V_2 -> V_486 [ V_76 ] = F_156 ( V_480 ) ;
V_2 -> V_97 [ V_76 ] = F_156 ( V_481 ) ;
}
static void F_157 ( struct V_1 * V_2 ,
unsigned int * V_487 )
{
unsigned int V_478 ;
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_30 ; V_15 ++ ) {
V_478 = ( V_487 [ V_15 ] + 1 ) * V_488 ;
F_154 ( V_2 , V_15 , V_478 ) ;
}
}
static void F_158 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_30 ; V_15 ++ ) {
F_9 ( V_2 , V_15 , V_489 , V_490 ,
V_2 -> V_486 [ V_15 ] ) ;
F_9 ( V_2 , V_15 , V_489 , V_491 ,
V_2 -> V_97 [ V_15 ] ) ;
}
}
static unsigned int F_159 ( struct V_1 * V_2 )
{
return F_37 (unsigned int, pdata->tx_max_fifo_size,
pdata->hw_feat.tx_fifo_size) ;
}
static unsigned int F_160 ( struct V_1 * V_2 )
{
return F_37 (unsigned int, pdata->rx_max_fifo_size,
pdata->hw_feat.rx_fifo_size) ;
}
static void F_161 ( unsigned int V_492 ,
unsigned int V_493 ,
unsigned int * V_487 )
{
unsigned int V_478 ;
unsigned int V_494 ;
unsigned int V_15 ;
V_478 = V_492 / V_493 ;
V_494 = V_478 / V_488 ;
if ( V_494 )
V_494 -- ;
for ( V_15 = 0 ; V_15 < V_493 ; V_15 ++ )
V_487 [ V_15 ] = V_494 ;
}
static unsigned int F_162 ( unsigned int V_492 ,
unsigned int V_493 ,
unsigned int * V_487 )
{
unsigned int V_15 ;
F_163 ( V_495 ) ;
if ( V_493 <= V_79 )
return V_492 ;
for ( V_15 = V_79 ; V_15 < V_493 ; V_15 ++ ) {
V_487 [ V_15 ] = ( V_495 / V_488 ) - 1 ;
V_492 -= V_495 ;
}
return V_492 ;
}
static unsigned int F_164 ( struct V_1 * V_2 )
{
unsigned int V_496 ;
if ( V_2 -> V_83 -> V_496 )
return V_2 -> V_83 -> V_496 / 8 ;
V_496 = F_1 ( V_2 ) ;
V_496 += V_497 ;
V_496 *= 2 ;
V_496 += V_498 ;
V_496 += V_5 + V_6 ;
V_496 += V_497 ;
V_496 += V_499 ;
return V_496 ;
}
static unsigned int F_165 ( struct V_1 * V_2 )
{
unsigned int V_288 , V_500 ;
unsigned int V_15 ;
if ( ! V_2 -> V_83 -> V_84 )
return 0 ;
V_288 = 0 ;
V_500 = F_166 ( V_2 -> V_30 ) ;
for ( V_15 = 0 ; V_15 < V_500 ; V_15 ++ ) {
if ( ! F_35 ( V_2 , V_15 ) )
continue;
V_2 -> V_482 [ V_15 ] = 1 ;
V_288 ++ ;
}
return V_288 ;
}
static void F_167 ( struct V_1 * V_2 ,
unsigned int V_492 ,
unsigned int * V_487 )
{
unsigned int V_478 , V_501 , V_502 ;
unsigned int V_500 ;
unsigned int V_503 ;
unsigned int V_15 ;
V_478 = F_168 ( F_1 ( V_2 ) ) ;
V_500 = F_166 ( V_2 -> V_30 ) ;
V_503 = F_165 ( V_2 ) ;
if ( ! V_503 || ( ( V_478 * V_500 ) > V_492 ) ) {
F_161 ( V_492 , V_500 , V_487 ) ;
return;
}
V_501 = V_492 - ( V_478 * V_500 ) ;
V_2 -> V_483 = F_164 ( V_2 ) ;
V_2 -> V_483 = F_155 ( V_2 -> V_483 ) ;
if ( V_2 -> V_483 > V_478 ) {
V_502 = V_2 -> V_483 - V_478 ;
V_502 = F_168 ( V_502 ) ;
} else {
V_502 = 0 ;
}
V_15 = V_500 ;
while ( V_15 > 0 ) {
V_15 -- ;
V_487 [ V_15 ] = ( V_478 / V_488 ) - 1 ;
if ( ! V_2 -> V_482 [ V_15 ] || ! V_502 )
continue;
if ( V_502 > V_501 ) {
F_169 ( V_2 -> V_3 ,
L_33 , V_15 ) ;
if ( ! V_501 )
continue;
V_502 = V_501 ;
}
V_487 [ V_15 ] += ( V_502 / V_488 ) ;
V_501 -= V_502 ;
}
if ( V_501 ) {
unsigned int V_504 = V_501 / V_500 ;
for ( V_15 = 0 ; V_15 < V_500 ; V_15 ++ )
V_487 [ V_15 ] += ( V_504 / V_488 ) ;
}
}
static void F_170 ( struct V_1 * V_2 )
{
unsigned int V_492 ;
unsigned int V_487 [ V_505 ] ;
unsigned int V_15 ;
V_492 = F_159 ( V_2 ) ;
F_161 ( V_492 , V_2 -> V_33 , V_487 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_33 ; V_15 ++ )
F_9 ( V_2 , V_15 , V_34 , V_506 , V_487 [ V_15 ] ) ;
F_171 ( V_2 , V_98 , V_2 -> V_3 ,
L_34 ,
V_2 -> V_33 , ( ( V_487 [ 0 ] + 1 ) * V_488 ) ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
unsigned int V_492 ;
unsigned int V_487 [ V_505 ] ;
unsigned int V_500 ;
unsigned int V_15 ;
memset ( V_2 -> V_482 , 0 , sizeof( V_2 -> V_482 ) ) ;
V_2 -> V_483 = 0 ;
V_492 = F_160 ( V_2 ) ;
V_500 = F_166 ( V_2 -> V_30 ) ;
V_492 = F_162 ( V_492 , V_2 -> V_30 , V_487 ) ;
if ( V_2 -> V_83 && V_2 -> V_81 )
F_167 ( V_2 , V_492 , V_487 ) ;
else
F_161 ( V_492 , V_500 , V_487 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_30 ; V_15 ++ )
F_9 ( V_2 , V_15 , V_31 , V_507 , V_487 [ V_15 ] ) ;
F_157 ( V_2 , V_487 ) ;
F_158 ( V_2 ) ;
if ( V_2 -> V_83 && V_2 -> V_81 && V_2 -> V_83 -> V_84 ) {
F_171 ( V_2 , V_98 , V_2 -> V_3 ,
L_35 , V_2 -> V_30 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_30 ; V_15 ++ )
F_171 ( V_2 , V_98 , V_2 -> V_3 ,
L_36 , V_15 ,
( ( V_487 [ V_15 ] + 1 ) * V_488 ) ) ;
} else {
F_171 ( V_2 , V_98 , V_2 -> V_3 ,
L_37 ,
V_2 -> V_30 ,
( ( V_487 [ 0 ] + 1 ) * V_488 ) ) ;
}
}
static void F_173 ( struct V_1 * V_2 )
{
unsigned int V_508 , V_509 , V_76 ;
unsigned int V_500 ;
unsigned int V_510 , V_511 , V_77 ;
unsigned int V_512 ;
unsigned int V_15 , V_513 , V_87 , V_88 ;
V_508 = V_2 -> V_33 / V_2 -> V_68 . V_471 ;
V_509 = V_2 -> V_33 % V_2 -> V_68 . V_471 ;
for ( V_15 = 0 , V_76 = 0 ; V_15 < V_2 -> V_68 . V_471 ; V_15 ++ ) {
for ( V_513 = 0 ; V_513 < V_508 ; V_513 ++ ) {
F_40 ( V_2 , V_98 , V_2 -> V_3 ,
L_38 , V_76 , V_15 ) ;
F_9 ( V_2 , V_76 , V_34 ,
V_514 , V_15 ) ;
V_2 -> V_515 [ V_76 ++ ] = V_15 ;
}
if ( V_15 < V_509 ) {
F_40 ( V_2 , V_98 , V_2 -> V_3 ,
L_38 , V_76 , V_15 ) ;
F_9 ( V_2 , V_76 , V_34 ,
V_514 , V_15 ) ;
V_2 -> V_515 [ V_76 ++ ] = V_15 ;
}
}
V_500 = F_166 ( V_2 -> V_30 ) ;
V_510 = V_79 / V_500 ;
V_511 = V_79 % V_500 ;
V_87 = V_516 ;
V_88 = 0 ;
for ( V_15 = 0 , V_77 = 0 ; V_15 < V_500 ; ) {
V_512 = 0 ;
for ( V_513 = 0 ; V_513 < V_510 ; V_513 ++ ) {
F_40 ( V_2 , V_98 , V_2 -> V_3 ,
L_39 , V_77 , V_15 ) ;
V_512 |= ( 1 << V_77 ) ;
V_2 -> V_80 [ V_77 ++ ] = V_15 ;
}
if ( V_15 < V_511 ) {
F_40 ( V_2 , V_98 , V_2 -> V_3 ,
L_39 , V_77 , V_15 ) ;
V_512 |= ( 1 << V_77 ) ;
V_2 -> V_80 [ V_77 ++ ] = V_15 ;
}
V_88 |= ( V_512 << ( ( V_15 ++ % V_517 ) << 3 ) ) ;
if ( ( V_15 % V_517 ) && ( V_15 != V_500 ) )
continue;
F_22 ( V_2 , V_87 , V_88 ) ;
V_87 += V_518 ;
V_88 = 0 ;
}
V_87 = V_519 ;
V_88 = 0 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_30 ; ) {
V_88 |= ( 0x80 << ( ( V_15 ++ % V_520 ) << 3 ) ) ;
if ( ( V_15 % V_520 ) && ( V_15 != V_2 -> V_30 ) )
continue;
F_22 ( V_2 , V_87 , V_88 ) ;
V_87 += V_521 ;
V_88 = 0 ;
}
}
static void F_174 ( struct V_1 * V_2 )
{
unsigned int V_220 , V_76 , V_77 ;
T_1 V_15 ;
F_175 ( V_2 -> V_3 ) ;
if ( ! V_2 -> V_522 )
return;
F_176 ( V_2 -> V_3 , V_2 -> V_522 ) ;
for ( V_15 = 0 , V_76 = 0 , V_220 = 0 ; V_15 < V_2 -> V_522 ; V_15 ++ ) {
while ( ( V_76 < V_2 -> V_33 ) &&
( V_2 -> V_515 [ V_76 ] == V_15 ) )
V_76 ++ ;
F_40 ( V_2 , V_98 , V_2 -> V_3 , L_40 ,
V_15 , V_220 , V_76 - 1 ) ;
F_177 ( V_2 -> V_3 , V_15 , V_76 - V_220 , V_220 ) ;
V_220 = V_76 ;
}
if ( ! V_2 -> V_81 )
return;
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ )
F_178 ( V_2 -> V_3 , V_77 ,
V_2 -> V_81 -> V_82 [ V_77 ] ) ;
}
static void F_179 ( struct V_1 * V_2 )
{
struct V_95 * V_81 = V_2 -> V_81 ;
unsigned int V_523 , V_524 , V_525 ;
unsigned int V_512 , V_87 , V_88 ;
unsigned int V_15 , V_77 ;
if ( ! V_81 )
return;
F_18 ( V_2 , V_468 , V_469 , V_526 ) ;
V_523 = V_2 -> V_3 -> V_4 * V_2 -> V_68 . V_471 ;
V_524 = V_523 / 100 ;
if ( ! V_524 )
V_524 = 1 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_68 . V_471 ; V_15 ++ ) {
V_512 = 0 ;
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ ) {
if ( V_81 -> V_82 [ V_77 ] == V_15 )
V_512 |= ( 1 << V_77 ) ;
}
V_512 &= 0xff ;
F_40 ( V_2 , V_98 , V_2 -> V_3 , L_41 ,
V_15 , V_512 ) ;
V_87 = V_527 + ( V_528 * ( V_15 / V_529 ) ) ;
V_88 = F_38 ( V_2 , V_87 ) ;
V_88 &= ~ ( 0xff << ( ( V_15 % V_529 ) << 3 ) ) ;
V_88 |= ( V_512 << ( ( V_15 % V_529 ) << 3 ) ) ;
F_22 ( V_2 , V_87 , V_88 ) ;
switch ( V_81 -> V_530 [ V_15 ] ) {
case V_531 :
F_40 ( V_2 , V_98 , V_2 -> V_3 ,
L_42 , V_15 ) ;
F_9 ( V_2 , V_15 , V_472 , V_308 ,
V_532 ) ;
break;
case V_533 :
V_525 = V_523 * V_81 -> V_534 [ V_15 ] / 100 ;
V_525 = F_180 ( V_525 , V_524 , V_523 ) ;
F_40 ( V_2 , V_98 , V_2 -> V_3 ,
L_43 , V_15 , V_525 ) ;
F_9 ( V_2 , V_15 , V_472 , V_308 ,
V_473 ) ;
F_9 ( V_2 , V_15 , V_474 , V_475 ,
V_525 ) ;
break;
}
}
F_174 ( V_2 ) ;
}
static void F_181 ( struct V_1 * V_2 )
{
if ( ! F_182 ( V_535 , & V_2 -> V_536 ) ) {
F_183 ( V_2 -> V_3 ) ;
V_2 -> V_537 . V_538 ( V_2 ) ;
}
F_172 ( V_2 ) ;
F_45 ( V_2 ) ;
if ( ! F_182 ( V_535 , & V_2 -> V_536 ) ) {
V_2 -> V_537 . V_539 ( V_2 ) ;
F_184 ( V_2 -> V_3 ) ;
}
}
static void F_185 ( struct V_1 * V_2 )
{
F_82 ( V_2 , V_2 -> V_3 -> V_540 ) ;
if ( V_2 -> V_68 . V_204 ) {
F_18 ( V_2 , V_164 , V_541 , 1 ) ;
F_18 ( V_2 , V_164 , V_542 , 1 ) ;
F_18 ( V_2 , V_164 , V_543 , 1 ) ;
}
}
static void F_186 ( struct V_1 * V_2 )
{
unsigned int V_29 ;
V_29 = ( V_2 -> V_3 -> V_4 > V_544 ) ? 1 : 0 ;
F_18 ( V_2 , V_45 , V_545 , V_29 ) ;
}
static void F_187 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_2 -> V_546 ) ;
}
static void F_188 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_74 & V_413 )
F_106 ( V_2 ) ;
else
F_105 ( V_2 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_547 , V_548 , 0 ) ;
F_18 ( V_2 , V_547 , V_549 , 1 ) ;
F_67 ( V_2 ) ;
if ( V_2 -> V_3 -> V_74 & V_184 )
F_63 ( V_2 ) ;
else
F_64 ( V_2 ) ;
if ( V_2 -> V_3 -> V_74 & V_418 )
F_61 ( V_2 ) ;
else
F_62 ( V_2 ) ;
}
static T_5 F_190 ( struct V_1 * V_2 , unsigned int V_550 )
{
bool V_551 ;
T_5 V_29 ;
if ( V_2 -> V_135 -> V_552 ) {
switch ( V_550 ) {
case V_553 :
case V_554 :
case V_555 :
case V_556 :
case V_557 :
V_551 = false ;
break;
default:
V_551 = true ;
}
} else {
switch ( V_550 ) {
case V_558 :
case V_559 :
case V_560 :
case V_561 :
V_551 = true ;
break;
default:
V_551 = false ;
}
}
V_29 = F_38 ( V_2 , V_550 ) ;
if ( V_551 )
V_29 |= ( ( T_5 ) F_38 ( V_2 , V_550 + 4 ) << 32 ) ;
return V_29 ;
}
static void F_191 ( struct V_1 * V_2 )
{
struct V_562 * V_563 = & V_2 -> V_564 ;
unsigned int V_565 = F_38 ( V_2 , V_566 ) ;
if ( F_122 ( V_565 , V_566 , V_567 ) )
V_563 -> V_568 +=
F_190 ( V_2 , V_558 ) ;
if ( F_122 ( V_565 , V_566 , V_569 ) )
V_563 -> V_570 +=
F_190 ( V_2 , V_571 ) ;
if ( F_122 ( V_565 , V_566 , V_572 ) )
V_563 -> V_573 +=
F_190 ( V_2 , V_574 ) ;
if ( F_122 ( V_565 , V_566 , V_575 ) )
V_563 -> V_576 +=
F_190 ( V_2 , V_577 ) ;
if ( F_122 ( V_565 , V_566 , V_578 ) )
V_563 -> V_579 +=
F_190 ( V_2 , V_580 ) ;
if ( F_122 ( V_565 , V_566 , V_581 ) )
V_563 -> V_582 +=
F_190 ( V_2 , V_583 ) ;
if ( F_122 ( V_565 , V_566 , V_584 ) )
V_563 -> V_585 +=
F_190 ( V_2 , V_586 ) ;
if ( F_122 ( V_565 , V_566 , V_587 ) )
V_563 -> V_588 +=
F_190 ( V_2 , V_589 ) ;
if ( F_122 ( V_565 , V_566 , V_590 ) )
V_563 -> V_591 +=
F_190 ( V_2 , V_592 ) ;
if ( F_122 ( V_565 , V_566 , V_593 ) )
V_563 -> V_594 +=
F_190 ( V_2 , V_595 ) ;
if ( F_122 ( V_565 , V_566 , V_596 ) )
V_563 -> V_597 +=
F_190 ( V_2 , V_598 ) ;
if ( F_122 ( V_565 , V_566 , V_599 ) )
V_563 -> V_600 +=
F_190 ( V_2 , V_601 ) ;
if ( F_122 ( V_565 , V_566 , V_602 ) )
V_563 -> V_573 +=
F_190 ( V_2 , V_603 ) ;
if ( F_122 ( V_565 , V_566 , V_604 ) )
V_563 -> V_605 +=
F_190 ( V_2 , V_606 ) ;
if ( F_122 ( V_565 , V_566 , V_607 ) )
V_563 -> V_608 +=
F_190 ( V_2 , V_559 ) ;
if ( F_122 ( V_565 , V_566 , V_609 ) )
V_563 -> V_610 +=
F_190 ( V_2 , V_611 ) ;
if ( F_122 ( V_565 , V_566 , V_612 ) )
V_563 -> V_613 +=
F_190 ( V_2 , V_614 ) ;
if ( F_122 ( V_565 , V_566 , V_615 ) )
V_563 -> V_616 +=
F_190 ( V_2 , V_617 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
struct V_562 * V_563 = & V_2 -> V_564 ;
unsigned int V_565 = F_38 ( V_2 , V_618 ) ;
if ( F_122 ( V_565 , V_618 , V_619 ) )
V_563 -> V_620 +=
F_190 ( V_2 , V_621 ) ;
if ( F_122 ( V_565 , V_618 , V_622 ) )
V_563 -> V_623 +=
F_190 ( V_2 , V_560 ) ;
if ( F_122 ( V_565 , V_618 , V_624 ) )
V_563 -> V_625 +=
F_190 ( V_2 , V_561 ) ;
if ( F_122 ( V_565 , V_618 , V_626 ) )
V_563 -> V_627 +=
F_190 ( V_2 , V_628 ) ;
if ( F_122 ( V_565 , V_618 , V_629 ) )
V_563 -> V_630 +=
F_190 ( V_2 , V_631 ) ;
if ( F_122 ( V_565 , V_618 , V_632 ) )
V_563 -> V_633 +=
F_190 ( V_2 , V_634 ) ;
if ( F_122 ( V_565 , V_618 , V_635 ) )
V_563 -> V_636 +=
F_190 ( V_2 , V_553 ) ;
if ( F_122 ( V_565 , V_618 , V_637 ) )
V_563 -> V_638 +=
F_190 ( V_2 , V_554 ) ;
if ( F_122 ( V_565 , V_618 , V_639 ) )
V_563 -> V_640 +=
F_190 ( V_2 , V_555 ) ;
if ( F_122 ( V_565 , V_618 , V_641 ) )
V_563 -> V_642 +=
F_190 ( V_2 , V_556 ) ;
if ( F_122 ( V_565 , V_618 , V_643 ) )
V_563 -> V_644 +=
F_190 ( V_2 , V_645 ) ;
if ( F_122 ( V_565 , V_618 , V_646 ) )
V_563 -> V_647 +=
F_190 ( V_2 , V_648 ) ;
if ( F_122 ( V_565 , V_618 , V_649 ) )
V_563 -> V_650 +=
F_190 ( V_2 , V_651 ) ;
if ( F_122 ( V_565 , V_618 , V_652 ) )
V_563 -> V_653 +=
F_190 ( V_2 , V_654 ) ;
if ( F_122 ( V_565 , V_618 , V_655 ) )
V_563 -> V_656 +=
F_190 ( V_2 , V_657 ) ;
if ( F_122 ( V_565 , V_618 , V_658 ) )
V_563 -> V_659 +=
F_190 ( V_2 , V_660 ) ;
if ( F_122 ( V_565 , V_618 , V_661 ) )
V_563 -> V_662 +=
F_190 ( V_2 , V_663 ) ;
if ( F_122 ( V_565 , V_618 , V_664 ) )
V_563 -> V_665 +=
F_190 ( V_2 , V_666 ) ;
if ( F_122 ( V_565 , V_618 , V_667 ) )
V_563 -> V_668 +=
F_190 ( V_2 , V_669 ) ;
if ( F_122 ( V_565 , V_618 , V_670 ) )
V_563 -> V_671 +=
F_190 ( V_2 , V_672 ) ;
if ( F_122 ( V_565 , V_618 , V_673 ) )
V_563 -> V_674 +=
F_190 ( V_2 , V_675 ) ;
if ( F_122 ( V_565 , V_618 , V_676 ) )
V_563 -> V_677 +=
F_190 ( V_2 , V_678 ) ;
if ( F_122 ( V_565 , V_618 , V_679 ) )
V_563 -> V_680 +=
F_190 ( V_2 , V_557 ) ;
}
static void F_193 ( struct V_1 * V_2 )
{
struct V_562 * V_563 = & V_2 -> V_564 ;
F_18 ( V_2 , V_681 , V_682 , 1 ) ;
V_563 -> V_568 +=
F_190 ( V_2 , V_558 ) ;
V_563 -> V_570 +=
F_190 ( V_2 , V_571 ) ;
V_563 -> V_573 +=
F_190 ( V_2 , V_574 ) ;
V_563 -> V_576 +=
F_190 ( V_2 , V_577 ) ;
V_563 -> V_579 +=
F_190 ( V_2 , V_580 ) ;
V_563 -> V_582 +=
F_190 ( V_2 , V_583 ) ;
V_563 -> V_585 +=
F_190 ( V_2 , V_586 ) ;
V_563 -> V_588 +=
F_190 ( V_2 , V_589 ) ;
V_563 -> V_591 +=
F_190 ( V_2 , V_592 ) ;
V_563 -> V_594 +=
F_190 ( V_2 , V_595 ) ;
V_563 -> V_597 +=
F_190 ( V_2 , V_598 ) ;
V_563 -> V_600 +=
F_190 ( V_2 , V_601 ) ;
V_563 -> V_573 +=
F_190 ( V_2 , V_603 ) ;
V_563 -> V_605 +=
F_190 ( V_2 , V_606 ) ;
V_563 -> V_608 +=
F_190 ( V_2 , V_559 ) ;
V_563 -> V_610 +=
F_190 ( V_2 , V_611 ) ;
V_563 -> V_613 +=
F_190 ( V_2 , V_614 ) ;
V_563 -> V_616 +=
F_190 ( V_2 , V_617 ) ;
V_563 -> V_620 +=
F_190 ( V_2 , V_621 ) ;
V_563 -> V_623 +=
F_190 ( V_2 , V_560 ) ;
V_563 -> V_625 +=
F_190 ( V_2 , V_561 ) ;
V_563 -> V_627 +=
F_190 ( V_2 , V_628 ) ;
V_563 -> V_630 +=
F_190 ( V_2 , V_631 ) ;
V_563 -> V_633 +=
F_190 ( V_2 , V_634 ) ;
V_563 -> V_636 +=
F_190 ( V_2 , V_553 ) ;
V_563 -> V_638 +=
F_190 ( V_2 , V_554 ) ;
V_563 -> V_640 +=
F_190 ( V_2 , V_555 ) ;
V_563 -> V_642 +=
F_190 ( V_2 , V_556 ) ;
V_563 -> V_644 +=
F_190 ( V_2 , V_645 ) ;
V_563 -> V_647 +=
F_190 ( V_2 , V_648 ) ;
V_563 -> V_650 +=
F_190 ( V_2 , V_651 ) ;
V_563 -> V_653 +=
F_190 ( V_2 , V_654 ) ;
V_563 -> V_656 +=
F_190 ( V_2 , V_657 ) ;
V_563 -> V_659 +=
F_190 ( V_2 , V_660 ) ;
V_563 -> V_662 +=
F_190 ( V_2 , V_663 ) ;
V_563 -> V_665 +=
F_190 ( V_2 , V_666 ) ;
V_563 -> V_668 +=
F_190 ( V_2 , V_669 ) ;
V_563 -> V_671 +=
F_190 ( V_2 , V_672 ) ;
V_563 -> V_674 +=
F_190 ( V_2 , V_675 ) ;
V_563 -> V_677 +=
F_190 ( V_2 , V_678 ) ;
V_563 -> V_680 +=
F_190 ( V_2 , V_557 ) ;
F_18 ( V_2 , V_681 , V_682 , 0 ) ;
}
static void F_194 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_681 , V_683 , 1 ) ;
F_18 ( V_2 , V_681 , V_684 , 1 ) ;
}
static void F_195 ( struct V_1 * V_2 ,
unsigned int V_76 )
{
unsigned int V_685 ;
unsigned long V_686 ;
V_686 = V_331 + ( V_687 * V_242 ) ;
while ( F_196 ( V_331 , V_686 ) ) {
V_685 = F_51 ( V_2 , V_76 , V_688 ) ;
if ( ( F_122 ( V_685 , V_688 , V_689 ) != 1 ) &&
( F_122 ( V_685 , V_688 , V_690 ) == 0 ) )
break;
F_23 ( 500 , 1000 ) ;
}
if ( ! F_196 ( V_331 , V_686 ) )
F_197 ( V_2 -> V_3 ,
L_44 ,
V_76 ) ;
}
static void F_198 ( struct V_1 * V_2 ,
unsigned int V_76 )
{
unsigned int V_691 , V_692 , V_693 ;
unsigned int V_685 ;
unsigned long V_686 ;
if ( F_122 ( V_2 -> V_68 . V_441 , V_442 , V_443 ) > 0x20 )
return F_195 ( V_2 , V_76 ) ;
if ( V_76 < V_694 ) {
V_691 = V_695 ;
V_692 = ( V_76 * V_696 ) + V_697 ;
} else {
V_693 = V_76 - V_694 ;
V_691 = V_698 + ( ( V_693 / V_699 ) * V_700 ) ;
V_692 = ( ( V_693 % V_699 ) * V_696 ) +
V_701 ;
}
V_686 = V_331 + ( V_687 * V_242 ) ;
while ( F_196 ( V_331 , V_686 ) ) {
V_685 = F_38 ( V_2 , V_691 ) ;
V_685 = F_199 ( V_685 , V_692 , V_702 ) ;
if ( ( V_685 == V_703 ) ||
( V_685 == V_704 ) )
break;
F_23 ( 500 , 1000 ) ;
}
if ( ! F_196 ( V_331 , V_686 ) )
F_197 ( V_2 -> V_3 ,
L_45 ,
V_76 ) ;
}
static void F_200 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_18 ; V_15 ++ ) {
if ( ! V_2 -> V_19 [ V_15 ] -> V_22 )
break;
F_6 ( V_2 -> V_19 [ V_15 ] , V_23 , V_705 , 1 ) ;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_33 ; V_15 ++ )
F_9 ( V_2 , V_15 , V_34 , V_706 ,
V_707 ) ;
F_18 ( V_2 , V_156 , V_708 , 1 ) ;
}
static void F_201 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_33 ; V_15 ++ )
F_198 ( V_2 , V_15 ) ;
F_18 ( V_2 , V_156 , V_708 , 0 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_33 ; V_15 ++ )
F_9 ( V_2 , V_15 , V_34 , V_706 , 0 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_18 ; V_15 ++ ) {
if ( ! V_2 -> V_19 [ V_15 ] -> V_22 )
break;
F_6 ( V_2 -> V_19 [ V_15 ] , V_23 , V_705 , 0 ) ;
}
}
static void F_202 ( struct V_1 * V_2 ,
unsigned int V_76 )
{
unsigned int V_417 ;
unsigned long V_709 ;
V_709 = V_331 + ( V_687 * V_242 ) ;
while ( F_196 ( V_331 , V_709 ) ) {
V_417 = F_51 ( V_2 , V_76 , V_710 ) ;
if ( ( F_122 ( V_417 , V_710 , V_711 ) == 0 ) &&
( F_122 ( V_417 , V_710 , V_712 ) == 0 ) )
break;
F_23 ( 500 , 1000 ) ;
}
if ( ! F_196 ( V_331 , V_709 ) )
F_197 ( V_2 -> V_3 ,
L_46 ,
V_76 ) ;
}
static void F_203 ( struct V_1 * V_2 )
{
unsigned int V_88 , V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_18 ; V_15 ++ ) {
if ( ! V_2 -> V_19 [ V_15 ] -> V_25 )
break;
F_6 ( V_2 -> V_19 [ V_15 ] , V_26 , V_713 , 1 ) ;
}
V_88 = 0 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_30 ; V_15 ++ )
V_88 |= ( 0x02 << ( V_15 << 1 ) ) ;
F_22 ( V_2 , V_714 , V_88 ) ;
F_18 ( V_2 , V_45 , V_715 , 1 ) ;
F_18 ( V_2 , V_45 , V_716 , 1 ) ;
F_18 ( V_2 , V_45 , V_717 , 1 ) ;
F_18 ( V_2 , V_45 , V_718 , 1 ) ;
}
static void F_204 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
F_18 ( V_2 , V_45 , V_715 , 0 ) ;
F_18 ( V_2 , V_45 , V_716 , 0 ) ;
F_18 ( V_2 , V_45 , V_717 , 0 ) ;
F_18 ( V_2 , V_45 , V_718 , 0 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_30 ; V_15 ++ )
F_202 ( V_2 , V_15 ) ;
F_22 ( V_2 , V_714 , 0 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_18 ; V_15 ++ ) {
if ( ! V_2 -> V_19 [ V_15 ] -> V_25 )
break;
F_6 ( V_2 -> V_19 [ V_15 ] , V_26 , V_713 , 0 ) ;
}
}
static void F_205 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_18 ; V_15 ++ ) {
if ( ! V_2 -> V_19 [ V_15 ] -> V_22 )
break;
F_6 ( V_2 -> V_19 [ V_15 ] , V_23 , V_705 , 1 ) ;
}
F_18 ( V_2 , V_156 , V_708 , 1 ) ;
}
static void F_206 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_33 ; V_15 ++ )
F_198 ( V_2 , V_15 ) ;
F_18 ( V_2 , V_156 , V_708 , 0 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_18 ; V_15 ++ ) {
if ( ! V_2 -> V_19 [ V_15 ] -> V_22 )
break;
F_6 ( V_2 -> V_19 [ V_15 ] , V_23 , V_705 , 0 ) ;
}
}
static void F_207 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_18 ; V_15 ++ ) {
if ( ! V_2 -> V_19 [ V_15 ] -> V_25 )
break;
F_6 ( V_2 -> V_19 [ V_15 ] , V_26 , V_713 , 1 ) ;
}
}
static void F_208 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_18 ; V_15 ++ ) {
if ( ! V_2 -> V_19 [ V_15 ] -> V_25 )
break;
F_6 ( V_2 -> V_19 [ V_15 ] , V_26 , V_713 , 0 ) ;
}
}
static int F_209 ( struct V_1 * V_2 )
{
struct V_719 * V_720 = & V_2 -> V_720 ;
int V_10 ;
F_3 ( L_47 ) ;
V_10 = F_149 ( V_2 ) ;
if ( V_10 ) {
F_34 ( V_2 -> V_3 , L_48 ) ;
return V_10 ;
}
F_151 ( V_2 ) ;
F_152 ( V_2 ) ;
F_7 ( V_2 ) ;
F_5 ( V_2 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
F_33 ( V_2 ) ;
V_720 -> V_721 ( V_2 ) ;
V_720 -> V_722 ( V_2 ) ;
F_46 ( V_2 ) ;
F_153 ( V_2 ) ;
F_173 ( V_2 ) ;
F_10 ( V_2 , V_2 -> V_723 ) ;
F_8 ( V_2 , V_2 -> V_724 ) ;
F_12 ( V_2 , V_2 -> V_725 ) ;
F_11 ( V_2 , V_2 -> V_726 ) ;
F_170 ( V_2 ) ;
F_172 ( V_2 ) ;
F_179 ( V_2 ) ;
F_49 ( V_2 ) ;
F_185 ( V_2 ) ;
F_83 ( V_2 ) ;
F_186 ( V_2 ) ;
F_45 ( V_2 ) ;
F_187 ( V_2 ) ;
F_188 ( V_2 ) ;
F_189 ( V_2 ) ;
F_194 ( V_2 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
F_3 ( L_49 ) ;
return 0 ;
}
void F_210 ( struct V_727 * V_537 )
{
F_3 ( L_50 ) ;
V_537 -> V_728 = F_103 ;
V_537 -> V_729 = F_82 ;
V_537 -> V_730 = F_83 ;
V_537 -> V_731 = F_106 ;
V_537 -> V_732 = F_105 ;
V_537 -> V_733 = F_61 ;
V_537 -> V_734 = F_62 ;
V_537 -> V_735 = F_63 ;
V_537 -> V_736 = F_64 ;
V_537 -> V_737 = F_67 ;
V_537 -> V_738 = F_96 ;
V_537 -> V_739 = F_97 ;
V_537 -> V_740 = F_60 ;
V_537 -> V_741 = F_102 ;
V_537 -> V_742 = F_101 ;
V_537 -> V_743 = F_98 ;
V_537 -> V_744 = F_85 ;
V_537 -> V_745 = F_84 ;
V_537 -> V_746 = F_200 ;
V_537 -> V_747 = F_201 ;
V_537 -> V_539 = F_203 ;
V_537 -> V_538 = F_204 ;
V_537 -> V_748 = F_205 ;
V_537 -> V_749 = F_206 ;
V_537 -> V_750 = F_207 ;
V_537 -> V_751 = F_208 ;
V_537 -> V_752 = F_133 ;
V_537 -> V_753 = F_139 ;
V_537 -> V_754 = F_145 ;
V_537 -> V_755 = F_146 ;
V_537 -> V_756 = F_209 ;
V_537 -> exit = F_148 ;
V_537 -> V_757 = F_109 ;
V_537 -> V_758 = F_116 ;
V_537 -> V_759 = F_107 ;
V_537 -> V_760 = F_113 ;
V_537 -> V_761 = F_144 ;
V_537 -> V_762 = F_143 ;
V_537 -> V_763 = F_129 ;
V_537 -> V_764 = F_43 ;
V_537 -> V_765 = F_44 ;
V_537 -> V_766 = F_13 ;
V_537 -> V_767 = F_14 ;
V_537 -> V_768 = F_2 ;
V_537 -> V_769 = F_4 ;
V_537 -> V_770 = F_11 ;
V_537 -> V_771 = F_12 ;
V_537 -> V_772 = F_8 ;
V_537 -> V_773 = F_10 ;
V_537 -> V_774 = F_7 ;
V_537 -> V_775 = F_191 ;
V_537 -> V_776 = F_192 ;
V_537 -> V_777 = F_193 ;
V_537 -> V_778 = F_125 ;
V_537 -> V_779 = F_117 ;
V_537 -> V_780 = F_119 ;
V_537 -> V_781 = F_120 ;
V_537 -> V_782 = F_121 ;
V_537 -> V_783 = F_174 ;
V_537 -> V_784 = F_179 ;
V_537 -> V_785 = F_181 ;
V_537 -> V_786 = F_31 ;
V_537 -> V_787 = F_32 ;
V_537 -> V_788 = F_28 ;
V_537 -> V_789 = F_29 ;
V_537 -> V_790 = F_58 ;
V_537 -> V_791 = F_59 ;
F_3 ( L_51 ) ;
}
