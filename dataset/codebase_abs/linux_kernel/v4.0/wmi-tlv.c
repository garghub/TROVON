static int
F_1 ( struct V_1 * V_2 , const void * V_3 , T_1 V_4 ,
int (* F_2)( struct V_1 * V_2 , T_2 V_5 , T_2 V_4 ,
const void * V_3 , void * V_6 ) ,
void * V_6 )
{
const void * V_7 = V_3 ;
const struct V_8 * V_9 ;
T_2 V_10 , V_11 ;
int V_12 ;
while ( V_4 > 0 ) {
if ( V_4 < sizeof( * V_9 ) ) {
F_3 ( V_2 , V_13 ,
L_1 ,
V_3 - V_7 , V_4 , sizeof( * V_9 ) ) ;
return - V_14 ;
}
V_9 = V_3 ;
V_10 = F_4 ( V_9 -> V_5 ) ;
V_11 = F_4 ( V_9 -> V_4 ) ;
V_3 += sizeof( * V_9 ) ;
V_4 -= sizeof( * V_9 ) ;
if ( V_11 > V_4 ) {
F_3 ( V_2 , V_13 ,
L_2 ,
V_10 , V_3 - V_7 , V_4 , V_11 ) ;
return - V_14 ;
}
if ( V_10 < F_5 ( V_15 ) &&
V_15 [ V_10 ] . V_16 &&
V_15 [ V_10 ] . V_16 > V_11 ) {
F_3 ( V_2 , V_13 ,
L_3 ,
V_10 , V_3 - V_7 , V_11 ,
V_15 [ V_10 ] . V_16 ) ;
return - V_14 ;
}
V_12 = F_2 ( V_2 , V_10 , V_11 , V_3 , V_6 ) ;
if ( V_12 )
return V_12 ;
V_3 += V_11 ;
V_4 -= V_11 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_5 , T_2 V_4 ,
const void * V_3 , void * V_6 )
{
const void * * V_17 = V_6 ;
if ( V_5 < V_18 )
V_17 [ V_5 ] = V_3 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , const void * * V_17 ,
const void * V_3 , T_1 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_6 ,
( void * ) V_17 ) ;
}
static const void * *
F_8 ( struct V_1 * V_2 , const void * V_3 ,
T_1 V_4 , T_3 V_19 )
{
const void * * V_17 ;
int V_12 ;
V_17 = F_9 ( sizeof( * V_17 ) * V_18 , V_19 ) ;
if ( ! V_17 )
return F_10 ( - V_20 ) ;
V_12 = F_7 ( V_2 , V_17 , V_3 , V_4 ) ;
if ( V_12 ) {
F_11 ( V_17 ) ;
return F_10 ( V_12 ) ;
}
return V_17 ;
}
static T_2 F_12 ( const void * V_3 )
{
return F_4 ( ( ( ( const struct V_8 * ) V_3 ) - 1 ) -> V_4 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
const void * * V_17 ;
const struct V_23 * V_24 ;
T_4 V_25 , V_26 ;
int V_12 ;
V_17 = F_8 ( V_2 , V_22 -> V_6 , V_22 -> V_4 , V_27 ) ;
if ( F_14 ( V_17 ) ) {
V_12 = F_15 ( V_17 ) ;
F_16 ( V_2 , L_4 , V_12 ) ;
return V_12 ;
}
V_24 = V_17 [ V_28 ] ;
if ( ! V_24 ) {
F_11 ( V_17 ) ;
return - V_29 ;
}
V_26 = F_17 ( V_24 -> V_26 ) ;
V_25 = F_17 ( V_24 -> V_25 ) ;
switch ( V_26 ) {
case V_30 :
break;
case V_31 :
case V_32 :
case V_33 :
F_16 ( V_2 , L_5 ,
V_25 , V_26 ) ;
break;
}
F_11 ( V_17 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
const void * * V_17 ;
const struct V_34 * V_24 ;
const struct V_35 * V_36 ;
const void * V_6 ;
int V_12 , V_37 , V_4 ;
V_17 = F_8 ( V_2 , V_22 -> V_6 , V_22 -> V_4 , V_27 ) ;
if ( F_14 ( V_17 ) ) {
V_12 = F_15 ( V_17 ) ;
F_16 ( V_2 , L_4 , V_12 ) ;
return V_12 ;
}
V_24 = V_17 [ V_38 ] ;
V_6 = V_17 [ V_39 ] ;
if ( ! V_24 || ! V_6 ) {
F_11 ( V_17 ) ;
return - V_29 ;
}
V_37 = F_17 ( V_24 -> V_37 ) ;
V_4 = F_12 ( V_6 ) ;
while ( V_37 -- ) {
if ( V_4 == 0 )
break;
if ( V_4 < sizeof( * V_36 ) ) {
F_16 ( V_2 , L_6 ) ;
break;
}
V_36 = V_6 ;
if ( V_4 < sizeof( * V_36 ) + F_4 ( V_36 -> V_4 ) ) {
F_16 ( V_2 , L_7 ) ;
break;
}
F_19 ( V_2 ,
V_36 -> type ,
F_17 ( V_36 -> V_40 ) ,
F_17 ( V_36 -> V_41 ) ,
F_4 ( V_36 -> V_4 ) ,
V_36 -> V_42 ) ;
V_4 -= sizeof( * V_36 ) ;
V_4 -= F_20 ( F_4 ( V_36 -> V_4 ) , 4 ) ;
V_6 += sizeof( * V_36 ) ;
V_6 += F_20 ( F_4 ( V_36 -> V_4 ) , 4 ) ;
}
if ( V_37 != - 1 || V_4 != 0 )
F_16 ( V_2 , L_8 ,
V_37 , V_4 ) ;
F_11 ( V_17 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
const void * * V_17 ;
const void * V_6 ;
int V_12 , V_4 ;
V_17 = F_8 ( V_2 , V_22 -> V_6 , V_22 -> V_4 , V_27 ) ;
if ( F_14 ( V_17 ) ) {
V_12 = F_15 ( V_17 ) ;
F_16 ( V_2 , L_4 , V_12 ) ;
return V_12 ;
}
V_6 = V_17 [ V_39 ] ;
if ( ! V_6 ) {
F_11 ( V_17 ) ;
return - V_29 ;
}
V_4 = F_12 ( V_6 ) ;
F_3 ( V_2 , V_13 , L_9 , V_4 ) ;
F_22 ( V_2 , V_6 , V_4 ) ;
F_11 ( V_17 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_43 * V_44 ;
enum V_45 V_46 ;
V_44 = (struct V_43 * ) V_22 -> V_6 ;
V_46 = F_24 ( F_17 ( V_44 -> V_47 ) , V_48 ) ;
if ( F_25 ( V_22 , sizeof( struct V_43 ) ) == NULL )
return;
F_26 ( V_2 , V_46 , V_22 -> V_6 , V_22 -> V_4 ) ;
switch ( V_46 ) {
case V_49 :
F_27 ( V_2 , V_22 ) ;
return;
case V_50 :
F_28 ( V_2 , V_22 ) ;
break;
case V_51 :
F_29 ( V_2 , V_22 ) ;
break;
case V_52 :
F_30 ( V_2 , V_22 ) ;
break;
case V_53 :
F_31 ( V_2 , V_22 ) ;
break;
case V_54 :
F_32 ( V_2 , V_22 ) ;
break;
case V_55 :
F_33 ( V_2 , V_22 ) ;
break;
case V_56 :
F_34 ( V_2 , V_22 ) ;
break;
case V_57 :
F_35 ( V_2 , V_22 ) ;
break;
case V_58 :
F_36 ( V_2 , V_22 ) ;
break;
case V_59 :
F_37 ( V_2 , V_22 ) ;
break;
case V_60 :
F_38 ( V_2 , V_22 ) ;
break;
case V_61 :
F_39 ( V_2 , V_22 ) ;
break;
case V_62 :
F_40 ( V_2 , V_22 ) ;
break;
case V_63 :
F_41 ( V_2 , V_22 ) ;
break;
case V_64 :
F_42 ( V_2 , V_22 ) ;
break;
case V_65 :
F_43 ( V_2 , V_22 ) ;
break;
case V_66 :
F_44 ( V_2 , V_22 ) ;
break;
case V_67 :
F_45 ( V_2 , V_22 ) ;
break;
case V_68 :
F_46 ( V_2 , V_22 ) ;
break;
case V_69 :
F_47 ( V_2 , V_22 ) ;
break;
case V_70 :
F_48 ( V_2 , V_22 ) ;
break;
case V_71 :
F_49 ( V_2 , V_22 ) ;
break;
case V_72 :
F_50 ( V_2 , V_22 ) ;
break;
case V_73 :
F_51 ( V_2 , V_22 ) ;
break;
case V_74 :
F_52 ( V_2 , V_22 ) ;
break;
case V_75 :
F_53 ( V_2 , V_22 ) ;
break;
case V_76 :
F_54 ( V_2 , V_22 ) ;
break;
case V_77 :
F_55 ( V_2 , V_22 ) ;
break;
case V_78 :
F_56 ( V_2 , V_22 ) ;
break;
case V_79 :
F_57 ( V_2 , V_22 ) ;
break;
case V_80 :
F_13 ( V_2 , V_22 ) ;
break;
case V_81 :
F_18 ( V_2 , V_22 ) ;
break;
case V_82 :
F_21 ( V_2 , V_22 ) ;
break;
default:
F_16 ( V_2 , L_10 , V_46 ) ;
break;
}
F_58 ( V_22 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_83 * V_84 )
{
const void * * V_17 ;
const struct V_85 * V_24 ;
int V_12 ;
V_17 = F_8 ( V_2 , V_22 -> V_6 , V_22 -> V_4 , V_27 ) ;
if ( F_14 ( V_17 ) ) {
V_12 = F_15 ( V_17 ) ;
F_16 ( V_2 , L_4 , V_12 ) ;
return V_12 ;
}
V_24 = V_17 [ V_86 ] ;
if ( ! V_24 ) {
F_11 ( V_17 ) ;
return - V_29 ;
}
V_84 -> V_87 = V_24 -> V_87 ;
V_84 -> V_88 = V_24 -> V_88 ;
V_84 -> V_89 = V_24 -> V_89 ;
V_84 -> V_90 = V_24 -> V_90 ;
V_84 -> V_91 = V_24 -> V_91 ;
V_84 -> V_25 = V_24 -> V_25 ;
F_11 ( V_17 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_92 * V_84 )
{
const void * * V_17 ;
const struct V_93 * V_24 ;
const T_5 * V_94 ;
T_4 V_95 ;
int V_12 ;
V_17 = F_8 ( V_2 , V_22 -> V_6 , V_22 -> V_4 , V_27 ) ;
if ( F_14 ( V_17 ) ) {
V_12 = F_15 ( V_17 ) ;
F_16 ( V_2 , L_4 , V_12 ) ;
return V_12 ;
}
V_24 = V_17 [ V_96 ] ;
V_94 = V_17 [ V_39 ] ;
if ( ! V_24 || ! V_94 ) {
F_11 ( V_17 ) ;
return - V_29 ;
}
V_84 -> V_97 = V_24 -> V_97 ;
V_84 -> V_98 = V_24 -> V_98 ;
V_84 -> V_99 = V_24 -> V_99 ;
V_84 -> V_100 = V_24 -> V_100 ;
V_84 -> V_101 = V_24 -> V_101 ;
V_84 -> V_102 = V_24 -> V_102 ;
V_95 = F_17 ( V_84 -> V_98 ) ;
if ( V_22 -> V_4 < ( V_94 - V_22 -> V_6 ) + V_95 ) {
F_11 ( V_17 ) ;
return - V_29 ;
}
F_61 ( V_22 , 0 ) ;
F_62 ( V_22 , V_94 - V_22 -> V_6 ) ;
F_25 ( V_22 , V_94 - V_22 -> V_6 ) ;
F_62 ( V_22 , V_95 ) ;
F_11 ( V_17 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_103 * V_84 )
{
const void * * V_17 ;
const struct V_104 * V_24 ;
int V_12 ;
V_17 = F_8 ( V_2 , V_22 -> V_6 , V_22 -> V_4 , V_27 ) ;
if ( F_14 ( V_17 ) ) {
V_12 = F_15 ( V_17 ) ;
F_16 ( V_2 , L_4 , V_12 ) ;
return V_12 ;
}
V_24 = V_17 [ V_105 ] ;
if ( ! V_24 ) {
F_11 ( V_17 ) ;
return - V_29 ;
}
V_84 -> V_106 = V_24 -> V_106 ;
V_84 -> V_107 = V_24 -> V_107 ;
V_84 -> V_108 = V_24 -> V_108 ;
V_84 -> V_109 = V_24 -> V_109 ;
V_84 -> V_110 = V_24 -> V_110 ;
V_84 -> V_111 = V_24 -> V_111 ;
F_11 ( V_17 ) ;
return 0 ;
}
static int
F_64 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_112 * V_84 )
{
const void * * V_17 ;
const struct V_113 * V_24 ;
int V_12 ;
V_17 = F_8 ( V_2 , V_22 -> V_6 , V_22 -> V_4 , V_27 ) ;
if ( F_14 ( V_17 ) ) {
V_12 = F_15 ( V_17 ) ;
F_16 ( V_2 , L_4 , V_12 ) ;
return V_12 ;
}
V_24 = V_17 [ V_114 ] ;
if ( ! V_24 ) {
F_11 ( V_17 ) ;
return - V_29 ;
}
F_25 ( V_22 , sizeof( * V_24 ) ) ;
V_84 -> V_25 = V_24 -> V_25 ;
V_84 -> V_115 = V_24 -> V_115 ;
V_84 -> V_116 = V_24 -> V_116 ;
V_84 -> V_99 = V_24 -> V_99 ;
F_11 ( V_17 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_117 * V_84 )
{
const void * * V_17 ;
const struct V_118 * V_24 ;
int V_12 ;
V_17 = F_8 ( V_2 , V_22 -> V_6 , V_22 -> V_4 , V_27 ) ;
if ( F_14 ( V_17 ) ) {
V_12 = F_15 ( V_17 ) ;
F_16 ( V_2 , L_4 , V_12 ) ;
return V_12 ;
}
V_24 = V_17 [ V_119 ] ;
if ( ! V_24 ) {
F_11 ( V_17 ) ;
return - V_29 ;
}
V_84 -> V_120 = V_24 -> V_121 . V_122 ;
F_11 ( V_17 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , T_2 V_5 , T_2 V_4 ,
const void * V_3 , void * V_6 )
{
struct V_123 * V_124 = V_6 ;
if ( V_5 != V_125 )
return - V_29 ;
if ( V_124 -> V_126 >= F_5 ( V_124 -> V_84 -> V_127 ) )
return - V_128 ;
V_124 -> V_84 -> V_127 [ V_124 -> V_126 ++ ] = V_3 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , T_2 V_5 , T_2 V_4 ,
const void * V_3 , void * V_6 )
{
struct V_123 * V_124 = V_6 ;
if ( V_5 != V_129 )
return - V_29 ;
if ( V_124 -> V_130 >= F_5 ( V_124 -> V_84 -> V_131 ) )
return - V_128 ;
V_124 -> V_84 -> V_131 [ V_124 -> V_130 ++ ] = V_3 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , T_2 V_5 , T_2 V_4 ,
const void * V_3 , void * V_6 )
{
struct V_123 * V_124 = V_6 ;
int V_12 ;
switch ( V_5 ) {
case V_132 :
V_124 -> V_24 = V_3 ;
break;
case V_133 :
if ( ! V_124 -> V_134 ) {
V_124 -> V_134 = true ;
V_12 = F_1 ( V_2 , V_3 , V_4 ,
F_66 ,
V_124 ) ;
if ( V_12 )
return V_12 ;
} else if ( ! V_124 -> V_135 ) {
V_124 -> V_135 = true ;
V_12 = F_1 ( V_2 , V_3 , V_4 ,
F_67 ,
V_124 ) ;
if ( V_12 )
return V_12 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_136 * V_84 )
{
struct V_123 V_124 = { . V_84 = V_84 } ;
T_4 V_137 ;
T_1 V_138 ;
int V_12 ;
V_12 = F_1 ( V_2 , V_22 -> V_6 , V_22 -> V_4 ,
F_68 , & V_124 ) ;
if ( V_12 ) {
F_16 ( V_2 , L_4 , V_12 ) ;
return V_12 ;
}
if ( ! V_124 . V_24 )
return - V_29 ;
V_84 -> V_139 = V_124 . V_24 -> V_139 ;
for ( V_137 = F_17 ( V_84 -> V_139 ) , V_138 = 0 ; V_137 ; V_137 >>= 1 )
if ( V_137 & F_70 ( 0 ) )
V_138 ++ ;
if ( V_138 != V_124 . V_126 ||
V_138 != V_124 . V_130 )
return - V_29 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_140 * V_84 )
{
const void * * V_17 ;
const struct V_141 * V_24 ;
const void * V_142 ;
int V_12 ;
V_17 = F_8 ( V_2 , V_22 -> V_6 , V_22 -> V_4 , V_27 ) ;
if ( F_14 ( V_17 ) ) {
V_12 = F_15 ( V_17 ) ;
F_16 ( V_2 , L_4 , V_12 ) ;
return V_12 ;
}
V_24 = V_17 [ V_143 ] ;
V_142 = V_17 [ V_39 ] ;
if ( ! V_24 || ! V_142 ) {
F_11 ( V_17 ) ;
return - V_29 ;
}
V_84 -> V_144 = V_24 -> V_144 ;
V_84 -> V_145 = V_24 -> V_145 ;
V_84 -> V_146 = V_24 -> V_146 ;
V_84 -> V_98 = V_24 -> V_98 ;
V_84 -> V_142 = V_142 ;
F_11 ( V_17 ) ;
return 0 ;
}
static int
F_72 ( struct V_1 * V_2 , T_2 V_5 , T_2 V_4 ,
const void * V_3 , void * V_6 )
{
struct V_147 * V_84 = V_6 ;
int V_148 ;
if ( V_5 != V_149 )
return - V_29 ;
for ( V_148 = 0 ; V_148 < F_5 ( V_84 -> V_150 ) ; V_148 ++ ) {
if ( ! V_84 -> V_150 [ V_148 ] ) {
V_84 -> V_150 [ V_148 ] = V_3 ;
return 0 ;
}
}
return - V_20 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_147 * V_84 )
{
const void * * V_17 ;
const struct V_151 * V_152 ;
const struct V_153 * V_24 ;
const T_6 * V_154 ;
const struct V_155 * V_150 ;
int V_12 ;
V_17 = F_8 ( V_2 , V_22 -> V_6 , V_22 -> V_4 , V_27 ) ;
if ( F_14 ( V_17 ) ) {
V_12 = F_15 ( V_17 ) ;
F_16 ( V_2 , L_4 , V_12 ) ;
return V_12 ;
}
V_24 = V_17 [ V_156 ] ;
V_152 = V_17 [ V_157 ] ;
V_154 = V_17 [ V_158 ] ;
V_150 = V_17 [ V_133 ] ;
if ( ! V_24 || ! V_152 || ! V_154 || ! V_150 ) {
F_11 ( V_17 ) ;
return - V_29 ;
}
F_3 ( V_2 , V_13 ,
L_11 ,
F_17 ( V_24 -> V_159 . V_160 ) , V_161 ,
F_17 ( V_24 -> V_159 . V_162 ) , V_163 ,
F_17 ( V_24 -> V_159 . V_164 ) , V_165 ,
F_17 ( V_24 -> V_159 . V_166 ) , V_167 ,
F_17 ( V_24 -> V_159 . V_168 ) , V_169 ) ;
if ( F_17 ( V_24 -> V_159 . V_160 ) != V_161 ||
F_17 ( V_24 -> V_159 . V_162 ) != V_163 ||
F_17 ( V_24 -> V_159 . V_164 ) != V_165 ||
F_17 ( V_24 -> V_159 . V_166 ) != V_167 ||
F_17 ( V_24 -> V_159 . V_168 ) != V_169 ) {
F_11 ( V_17 ) ;
return - V_170 ;
}
V_84 -> V_171 = V_24 -> V_172 ;
V_84 -> V_173 = V_24 -> V_174 ;
V_84 -> V_175 = V_24 -> V_176 ;
V_84 -> V_177 = V_24 -> V_178 ;
V_84 -> V_179 = V_24 -> V_159 . V_160 ;
V_84 -> V_180 = V_24 -> V_159 . V_181 ;
V_84 -> V_182 = V_24 -> V_183 ;
V_84 -> V_184 = V_24 -> V_185 ;
V_84 -> V_186 = V_24 -> V_186 ;
V_84 -> V_187 = V_152 -> V_187 ;
V_84 -> V_188 = V_24 -> V_188 ;
V_84 -> V_189 = V_154 ;
V_84 -> V_190 = F_12 ( V_154 ) ;
V_12 = F_1 ( V_2 , V_150 , F_12 ( V_150 ) ,
F_72 , V_84 ) ;
if ( V_12 ) {
F_11 ( V_17 ) ;
F_16 ( V_2 , L_12 , V_12 ) ;
return V_12 ;
}
F_11 ( V_17 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_191 * V_84 )
{
const void * * V_17 ;
const struct V_192 * V_24 ;
int V_12 ;
V_17 = F_8 ( V_2 , V_22 -> V_6 , V_22 -> V_4 , V_27 ) ;
if ( F_14 ( V_17 ) ) {
V_12 = F_15 ( V_17 ) ;
F_16 ( V_2 , L_4 , V_12 ) ;
return V_12 ;
}
V_24 = V_17 [ V_193 ] ;
if ( ! V_24 ) {
F_11 ( V_17 ) ;
return - V_29 ;
}
V_84 -> V_194 = V_24 -> V_159 . V_160 ;
V_84 -> V_195 = V_24 -> V_159 . V_181 ;
V_84 -> V_99 = V_24 -> V_99 ;
V_84 -> V_120 = V_24 -> V_120 . V_122 ;
F_11 ( V_17 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_196 * V_197 )
{
const void * * V_17 ;
const struct V_198 * V_24 ;
const void * V_6 ;
T_4 V_199 , V_200 , V_201 ;
T_1 V_202 ;
int V_12 ;
V_17 = F_8 ( V_2 , V_22 -> V_6 , V_22 -> V_4 , V_27 ) ;
if ( F_14 ( V_17 ) ) {
V_12 = F_15 ( V_17 ) ;
F_16 ( V_2 , L_4 , V_12 ) ;
return V_12 ;
}
V_24 = V_17 [ V_203 ] ;
V_6 = V_17 [ V_39 ] ;
if ( ! V_24 || ! V_6 ) {
F_11 ( V_17 ) ;
return - V_29 ;
}
V_202 = F_12 ( V_6 ) ;
V_199 = F_17 ( V_24 -> V_199 ) ;
V_200 = F_17 ( V_24 -> V_200 ) ;
V_201 = F_17 ( V_24 -> V_201 ) ;
F_76 ( 1 ) ;
F_11 ( V_17 ) ;
return 0 ;
}
static struct V_21 *
F_77 ( struct V_1 * V_2 , T_4 V_204 )
{
struct V_205 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_207 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_204 = F_80 ( V_204 ) ;
F_3 ( V_2 , V_13 , L_13 ) ;
return V_22 ;
}
static struct V_21 *
F_81 ( struct V_1 * V_2 )
{
struct V_209 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_210 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_211 = F_80 ( 0 ) ;
F_3 ( V_2 , V_13 , L_14 ) ;
return V_22 ;
}
static struct V_21 *
F_82 ( struct V_1 * V_2 ,
T_2 V_212 , T_2 V_213 , T_2 V_214 ,
T_2 V_215 , T_2 V_216 ,
enum V_217 V_218 )
{
struct V_219 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_220 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_221 = F_80 ( V_212 ) ;
V_206 -> V_222 = F_80 ( V_213 ) ;
V_206 -> V_223 = F_80 ( V_214 ) ;
V_206 -> V_224 = F_80 ( V_213 ) ;
V_206 -> V_225 = F_80 ( V_214 ) ;
F_3 ( V_2 , V_13 , L_15 ) ;
return V_22 ;
}
static struct V_21 *
F_83 ( struct V_1 * V_2 , T_4 V_226 ,
T_4 V_227 )
{
struct V_228 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_229 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_226 = F_80 ( V_226 ) ;
V_206 -> V_227 = F_80 ( V_227 ) ;
F_3 ( V_2 , V_13 , L_16 ) ;
return V_22 ;
}
static struct V_21 * F_84 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
struct V_8 * V_9 ;
struct V_230 * V_206 ;
struct V_231 * V_232 ;
struct V_233 * V_234 ;
T_1 V_4 , V_235 ;
void * V_3 ;
V_235 = V_2 -> V_236 . V_237 * sizeof( struct V_238 ) ;
V_4 = ( sizeof( * V_9 ) + sizeof( * V_206 ) ) +
( sizeof( * V_9 ) + sizeof( * V_232 ) ) +
( sizeof( * V_9 ) + V_235 ) ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_239 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_240 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_232 ) ) ;
V_232 = ( void * ) V_9 -> V_208 ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_232 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_133 ) ;
V_9 -> V_4 = F_79 ( V_235 ) ;
V_234 = ( void * ) V_9 -> V_208 ;
V_3 += sizeof( * V_9 ) ;
V_3 += V_235 ;
V_206 -> V_159 . V_160 = F_80 ( V_161 ) ;
V_206 -> V_159 . V_181 = F_80 ( V_241 ) ;
V_206 -> V_159 . V_162 = F_80 ( V_163 ) ;
V_206 -> V_159 . V_164 = F_80 ( V_165 ) ;
V_206 -> V_159 . V_166 = F_80 ( V_167 ) ;
V_206 -> V_159 . V_168 = F_80 ( V_169 ) ;
V_206 -> V_242 = F_80 ( V_2 -> V_236 . V_237 ) ;
V_232 -> V_243 = F_80 ( V_244 ) ;
V_232 -> V_245 = F_80 ( V_246 ) ;
if ( F_85 ( V_247 , V_2 -> V_236 . V_248 ) ) {
V_232 -> V_249 = F_80 ( 3 ) ;
V_232 -> V_250 = F_80 ( 3 ) ;
} else {
V_232 -> V_249 = F_80 ( 0 ) ;
V_232 -> V_250 = F_80 ( 0 ) ;
}
V_232 -> V_251 = F_80 ( 2 ) ;
V_232 -> V_252 = F_80 ( V_253 ) ;
V_232 -> V_254 = F_80 ( 0x10 ) ;
V_232 -> V_255 = F_80 ( 0x7 ) ;
V_232 -> V_256 = F_80 ( 0x7 ) ;
V_232 -> V_257 [ 0 ] = F_80 ( 0x64 ) ;
V_232 -> V_257 [ 1 ] = F_80 ( 0x64 ) ;
V_232 -> V_257 [ 2 ] = F_80 ( 0x64 ) ;
V_232 -> V_257 [ 3 ] = F_80 ( 0x28 ) ;
V_232 -> V_258 = F_80 ( 1 ) ;
V_232 -> V_259 = F_80 ( 4 ) ;
V_232 -> V_260 = F_80 ( 3 ) ;
V_232 -> V_261 = F_80 ( 3 ) ;
V_232 -> V_262 = F_80 ( 8 ) ;
V_232 -> V_263 = F_80 ( 0 ) ;
V_232 -> V_264 = F_80 ( 0 ) ;
V_232 -> V_265 = F_80 ( 0 ) ;
V_232 -> V_266 = F_80 ( 0x400 ) ;
V_232 -> V_267 = F_80 ( 0x20 ) ;
V_232 -> V_268 = F_80 ( 0 ) ;
V_232 -> V_269 = F_80 ( 0 ) ;
V_232 -> V_270 = F_80 ( 0 ) ;
V_232 -> V_271 = F_80 ( 0 ) ;
V_232 -> V_272 = F_80 ( 2 ) ;
V_232 -> V_273 = F_80 ( V_274 ) ;
V_232 -> V_275 = F_80 ( 2 ) ;
V_232 -> V_276 = F_80 ( 1 ) ;
V_232 -> V_277 = F_80 ( 0x20 ) ;
V_232 -> V_278 = F_80 ( 2 ) ;
V_232 -> V_279 = F_80 ( 5 ) ;
V_232 -> V_280 = F_80 ( 0x16 ) ;
V_232 -> V_281 = F_80 ( 6 ) ;
V_232 -> V_282 = F_80 ( 0 ) ;
V_232 -> V_283 = F_80 ( 1 ) ;
V_232 -> V_284 = F_80 ( 1 ) ;
F_86 ( V_2 , V_234 ) ;
F_3 ( V_2 , V_13 , L_17 ) ;
return V_22 ;
}
static struct V_21 *
F_87 ( struct V_1 * V_2 ,
const struct V_285 * V_84 )
{
struct V_286 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 , V_287 , V_288 , V_289 , V_290 ;
T_6 * V_291 ;
struct V_292 * V_293 ;
struct V_294 * V_295 ;
void * V_3 ;
int V_148 , V_12 ;
V_12 = F_88 ( V_84 ) ;
if ( V_12 )
return F_10 ( V_12 ) ;
V_287 = V_84 -> V_296 * sizeof( T_6 ) ;
V_288 = V_84 -> V_297 * sizeof( struct V_292 ) ;
V_289 = V_84 -> V_298 * sizeof( struct V_294 ) ;
V_290 = F_20 ( V_84 -> V_290 , 4 ) ;
V_4 = ( sizeof( * V_9 ) + sizeof( * V_206 ) ) +
( V_84 -> V_296 ? sizeof( * V_9 ) + V_287 : 0 ) +
( V_84 -> V_297 ? sizeof( * V_9 ) + V_288 : 0 ) +
( V_84 -> V_298 ? sizeof( * V_9 ) + V_289 : 0 ) +
( V_84 -> V_290 ? sizeof( * V_9 ) + V_290 : 0 ) ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_299 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
F_89 ( & V_206 -> V_300 , V_84 ) ;
V_206 -> V_301 = F_80 ( 0 ) ;
V_206 -> V_302 = F_80 ( V_84 -> V_296 ) ;
V_206 -> V_303 = F_80 ( V_84 -> V_297 ) ;
V_206 -> V_304 = F_80 ( V_84 -> V_298 ) ;
V_206 -> V_290 = F_80 ( V_84 -> V_290 ) ;
V_206 -> V_305 = F_80 ( 3 ) ;
V_206 -> V_300 . V_306 ^= F_80 ( V_307 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_158 ) ;
V_9 -> V_4 = F_79 ( V_287 ) ;
V_291 = ( void * ) V_9 -> V_208 ;
for ( V_148 = 0 ; V_148 < V_84 -> V_296 ; V_148 ++ )
V_291 [ V_148 ] = F_80 ( V_84 -> V_308 [ V_148 ] ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += V_287 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_309 ) ;
V_9 -> V_4 = F_79 ( V_288 ) ;
V_293 = ( void * ) V_9 -> V_208 ;
for ( V_148 = 0 ; V_148 < V_84 -> V_297 ; V_148 ++ ) {
V_293 [ V_148 ] . V_288 = F_80 ( V_84 -> V_293 [ V_148 ] . V_4 ) ;
memcpy ( V_293 [ V_148 ] . V_310 , V_84 -> V_293 [ V_148 ] . V_310 , V_84 -> V_293 [ V_148 ] . V_4 ) ;
}
V_3 += sizeof( * V_9 ) ;
V_3 += V_288 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_309 ) ;
V_9 -> V_4 = F_79 ( V_289 ) ;
V_295 = ( void * ) V_9 -> V_208 ;
for ( V_148 = 0 ; V_148 < V_84 -> V_298 ; V_148 ++ )
F_90 ( V_295 [ V_148 ] . V_122 , V_84 -> V_311 [ V_148 ] . V_312 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += V_289 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_39 ) ;
V_9 -> V_4 = F_79 ( V_290 ) ;
memcpy ( V_9 -> V_208 , V_84 -> V_313 , V_84 -> V_290 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += V_290 ;
F_3 ( V_2 , V_13 , L_18 ) ;
return V_22 ;
}
static struct V_21 *
F_91 ( struct V_1 * V_2 ,
const struct V_314 * V_84 )
{
struct V_315 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_4 V_91 ;
T_4 V_115 ;
if ( V_84 -> V_115 > 0xFFF )
return F_10 ( - V_14 ) ;
if ( V_84 -> V_316 == V_317 && V_84 -> V_318 . V_91 > 0xFFF )
return F_10 ( - V_14 ) ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_91 = V_84 -> V_318 . V_91 ;
V_91 |= V_319 ;
V_115 = V_84 -> V_115 ;
V_115 |= V_320 ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_321 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_316 = F_80 ( V_84 -> V_316 ) ;
V_206 -> V_25 = F_80 ( V_84 -> V_318 . V_25 ) ;
V_206 -> V_91 = F_80 ( V_91 ) ;
V_206 -> V_90 = F_80 ( V_115 ) ;
F_3 ( V_2 , V_13 , L_19 ) ;
return V_22 ;
}
static struct V_21 *
F_92 ( struct V_1 * V_2 ,
T_4 V_25 ,
enum V_322 V_323 ,
enum V_324 V_325 ,
const T_5 V_120 [ V_326 ] )
{
struct V_327 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_328 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
V_206 -> V_323 = F_80 ( V_323 ) ;
V_206 -> V_325 = F_80 ( V_325 ) ;
F_90 ( V_206 -> V_329 . V_122 , V_120 ) ;
F_3 ( V_2 , V_13 , L_20 ) ;
return V_22 ;
}
static struct V_21 *
F_93 ( struct V_1 * V_2 , T_4 V_25 )
{
struct V_330 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_331 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
F_3 ( V_2 , V_13 , L_21 ) ;
return V_22 ;
}
static struct V_21 *
F_94 ( struct V_1 * V_2 ,
const struct V_332 * V_84 ,
bool V_333 )
{
struct V_334 * V_206 ;
struct V_335 * V_336 ;
struct V_337 * V_338 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 ;
void * V_3 ;
T_4 V_339 = 0 ;
if ( F_76 ( V_84 -> V_310 && V_84 -> V_288 == 0 ) )
return F_10 ( - V_14 ) ;
if ( F_76 ( V_84 -> V_340 && ! V_84 -> V_310 ) )
return F_10 ( - V_14 ) ;
if ( F_76 ( V_84 -> V_288 > sizeof( V_206 -> V_310 . V_310 ) ) )
return F_10 ( - V_14 ) ;
V_4 = ( sizeof( * V_9 ) + sizeof( * V_206 ) ) +
( sizeof( * V_9 ) + sizeof( * V_336 ) ) +
( sizeof( * V_9 ) + 0 ) ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
if ( V_84 -> V_340 )
V_339 |= V_341 ;
if ( V_84 -> V_342 )
V_339 |= V_343 ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_344 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_84 -> V_25 ) ;
V_206 -> V_345 = F_80 ( V_84 -> V_345 ) ;
V_206 -> V_346 = F_80 ( V_84 -> V_346 ) ;
V_206 -> V_339 = F_80 ( V_339 ) ;
V_206 -> V_347 = F_80 ( V_84 -> V_347 ) ;
V_206 -> V_348 = F_80 ( V_84 -> V_348 ) ;
V_206 -> V_349 = F_80 ( V_84 -> V_349 ) ;
if ( V_84 -> V_310 ) {
V_206 -> V_310 . V_288 = F_80 ( V_84 -> V_288 ) ;
memcpy ( V_206 -> V_310 . V_310 , V_84 -> V_310 , V_84 -> V_288 ) ;
}
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_350 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_336 ) ) ;
V_336 = ( void * ) V_9 -> V_208 ;
F_95 ( V_336 , & V_84 -> V_97 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_336 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_133 ) ;
V_9 -> V_4 = 0 ;
V_338 = ( void * ) V_9 -> V_208 ;
V_3 += sizeof( * V_9 ) ;
V_3 += 0 ;
F_3 ( V_2 , V_13 , L_22 ) ;
return V_22 ;
}
static struct V_21 *
F_96 ( struct V_1 * V_2 , T_4 V_25 )
{
struct V_351 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_352 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
F_3 ( V_2 , V_13 , L_23 ) ;
return V_22 ;
}
static struct V_21 *
F_97 ( struct V_1 * V_2 , T_4 V_25 , T_4 V_353 ,
const T_5 * V_312 )
{
struct V_354 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_355 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
V_206 -> V_356 = F_80 ( V_353 ) ;
F_90 ( V_206 -> V_357 . V_122 , V_312 ) ;
F_3 ( V_2 , V_13 , L_24 ) ;
return V_22 ;
}
static struct V_21 *
F_98 ( struct V_1 * V_2 , T_4 V_25 )
{
struct V_358 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_359 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
F_3 ( V_2 , V_13 , L_25 ) ;
return V_22 ;
}
static struct V_21 *
F_99 ( struct V_1 * V_2 , T_4 V_25 ,
T_4 V_226 , T_4 V_227 )
{
struct V_360 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_361 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
V_206 -> V_226 = F_80 ( V_226 ) ;
V_206 -> V_227 = F_80 ( V_227 ) ;
F_3 ( V_2 , V_13 , L_26 ) ;
return V_22 ;
}
static struct V_21 *
F_100 ( struct V_1 * V_2 ,
const struct V_362 * V_84 )
{
struct V_363 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 ;
void * V_3 ;
if ( V_84 -> V_364 == V_365 && V_84 -> V_366 != NULL )
return F_10 ( - V_14 ) ;
if ( V_84 -> V_364 != V_365 && V_84 -> V_366 == NULL )
return F_10 ( - V_14 ) ;
V_4 = sizeof( * V_9 ) + sizeof( * V_206 ) +
sizeof( * V_9 ) + F_20 ( V_84 -> V_367 , sizeof( T_6 ) ) ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_368 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_84 -> V_25 ) ;
V_206 -> V_369 = F_80 ( V_84 -> V_369 ) ;
V_206 -> V_370 = F_80 ( V_84 -> V_370 ) ;
V_206 -> V_364 = F_80 ( V_84 -> V_364 ) ;
V_206 -> V_367 = F_80 ( V_84 -> V_367 ) ;
V_206 -> V_371 = F_80 ( V_84 -> V_371 ) ;
V_206 -> V_372 = F_80 ( V_84 -> V_372 ) ;
if ( V_84 -> V_373 )
F_90 ( V_206 -> V_121 . V_122 , V_84 -> V_373 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_39 ) ;
V_9 -> V_4 = F_79 ( F_20 ( V_84 -> V_367 , sizeof( T_6 ) ) ) ;
if ( V_84 -> V_366 )
memcpy ( V_9 -> V_208 , V_84 -> V_366 , V_84 -> V_367 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += F_20 ( V_84 -> V_367 , sizeof( T_6 ) ) ;
F_3 ( V_2 , V_13 , L_27 ) ;
return V_22 ;
}
static void * F_101 ( struct V_1 * V_2 , void * V_3 ,
const struct V_374 * V_84 )
{
struct V_375 * V_376 ;
struct V_8 * V_9 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_377 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_376 ) ) ;
V_376 = ( void * ) V_9 -> V_208 ;
V_376 -> V_378 = F_80 ( V_84 -> V_378 ) ;
V_376 -> V_379 = F_80 ( V_84 -> V_379 ) ;
V_376 -> V_380 = F_80 ( V_84 -> V_380 ) ;
V_376 -> V_381 = F_80 ( V_84 -> V_381 ) ;
V_376 -> V_382 = F_80 ( V_84 -> V_382 ) ;
F_3 ( V_2 , V_13 ,
L_28 ,
V_376 -> V_378 , V_376 -> V_379 , V_376 -> V_380 ,
V_376 -> V_381 , V_376 -> V_382 ) ;
return V_3 + sizeof( * V_9 ) + sizeof( * V_376 ) ;
}
static struct V_21 *
F_102 ( struct V_1 * V_2 , T_4 V_25 ,
const T_5 V_383 [ V_326 ] ,
const struct V_374 * args ,
T_4 V_384 )
{
struct V_385 * V_206 ;
struct V_375 * V_376 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 ;
T_1 V_386 ;
void * V_3 ;
int V_148 ;
V_386 = V_384 * ( sizeof( * V_9 ) + sizeof( * V_376 ) ) ;
V_4 = sizeof( * V_9 ) + sizeof( * V_206 ) +
sizeof( * V_9 ) + V_386 ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_387 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
V_206 -> V_384 = F_80 ( V_384 ) ;
F_90 ( V_206 -> V_121 . V_122 , V_383 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_133 ) ;
V_9 -> V_4 = F_79 ( V_386 ) ;
V_376 = ( void * ) V_9 -> V_208 ;
V_3 += sizeof( * V_9 ) ;
for ( V_148 = 0 ; V_148 < V_384 ; V_148 ++ )
V_3 = F_101 ( V_2 , V_3 , & args [ V_148 ] ) ;
F_3 ( V_2 , V_13 , L_29 ) ;
return V_22 ;
}
static void * F_103 ( void * V_3 ,
const struct V_388 * V_84 )
{
struct V_389 * V_390 ;
struct V_8 * V_9 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_391 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_390 ) ) ;
V_390 = ( void * ) V_9 -> V_208 ;
F_104 ( V_390 , V_84 ) ;
return V_3 + sizeof( * V_9 ) + sizeof( * V_390 ) ;
}
static struct V_21 *
F_105 ( struct V_1 * V_2 , T_4 V_25 ,
const struct V_392 * V_84 )
{
struct V_393 * V_206 ;
struct V_389 * V_390 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 ;
void * V_3 ;
V_4 = ( sizeof( * V_9 ) + sizeof( * V_206 ) ) +
( 4 * ( sizeof( * V_9 ) + sizeof( * V_390 ) ) ) ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_394 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
V_3 = F_103 ( V_3 , & V_84 -> V_395 ) ;
V_3 = F_103 ( V_3 , & V_84 -> V_396 ) ;
V_3 = F_103 ( V_3 , & V_84 -> V_397 ) ;
V_3 = F_103 ( V_3 , & V_84 -> V_398 ) ;
F_3 ( V_2 , V_13 , L_30 ) ;
return V_22 ;
}
static struct V_21 *
F_106 ( struct V_1 * V_2 ,
const struct V_399 * V_84 )
{
struct V_400 * V_206 ;
struct V_401 * V_402 ;
struct V_21 * V_22 ;
struct V_8 * V_9 ;
void * V_3 ;
T_1 V_4 ;
V_4 = sizeof( * V_9 ) + sizeof( * V_206 ) +
sizeof( * V_9 ) + sizeof( * V_402 ) ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_403 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_84 -> V_25 ) ;
V_206 -> V_404 = F_80 ( V_84 -> V_404 ) ;
V_206 -> V_405 = F_80 ( V_84 -> V_405 ) ;
V_206 -> V_406 = F_80 ( V_84 -> V_406 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_407 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_402 ) ) ;
V_402 = ( void * ) V_9 -> V_208 ;
V_402 -> V_408 = V_84 -> V_408 ;
V_402 -> V_409 = V_84 -> V_409 ;
F_90 ( V_402 -> V_410 . V_122 , V_84 -> V_410 ) ;
F_3 ( V_2 , V_13 , L_31 ,
V_84 -> V_25 , V_84 -> V_404 , V_84 -> V_405 , V_84 -> V_406 ) ;
return V_22 ;
}
static struct V_21 *
F_107 ( struct V_1 * V_2 , T_4 V_25 ,
const T_5 V_383 [ V_326 ] )
{
struct V_411 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_412 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
V_206 -> V_413 = F_80 ( V_414 ) ;
F_90 ( V_206 -> V_383 . V_122 , V_383 ) ;
F_3 ( V_2 , V_13 , L_32 ) ;
return V_22 ;
}
static struct V_21 *
F_108 ( struct V_1 * V_2 , T_4 V_25 ,
const T_5 V_383 [ V_326 ] )
{
struct V_415 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_416 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
F_90 ( V_206 -> V_121 . V_122 , V_383 ) ;
F_3 ( V_2 , V_13 , L_33 ) ;
return V_22 ;
}
static struct V_21 *
F_109 ( struct V_1 * V_2 , T_4 V_25 ,
const T_5 V_383 [ V_326 ] , T_4 V_417 )
{
struct V_418 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_419 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
V_206 -> V_420 = F_80 ( V_417 ) ;
F_90 ( V_206 -> V_121 . V_122 , V_383 ) ;
F_3 ( V_2 , V_13 , L_34 ) ;
return V_22 ;
}
static struct V_21 *
F_110 ( struct V_1 * V_2 , T_4 V_25 ,
const T_5 * V_383 ,
enum V_421 V_226 ,
T_4 V_227 )
{
struct V_422 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_423 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
V_206 -> V_226 = F_80 ( V_226 ) ;
V_206 -> V_227 = F_80 ( V_227 ) ;
F_90 ( V_206 -> V_121 . V_122 , V_383 ) ;
F_3 ( V_2 , V_13 , L_35 ) ;
return V_22 ;
}
static struct V_21 *
F_111 ( struct V_1 * V_2 ,
const struct V_424 * V_84 )
{
struct V_425 * V_206 ;
struct V_426 * V_427 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 , V_428 , V_429 ;
void * V_3 ;
if ( V_84 -> V_430 > 16 )
return F_10 ( - V_14 ) ;
if ( V_84 -> V_431 . V_432 > V_433 )
return F_10 ( - V_14 ) ;
if ( V_84 -> V_434 . V_432 > V_433 )
return F_10 ( - V_14 ) ;
V_428 = F_20 ( V_84 -> V_431 . V_432 ,
sizeof( T_6 ) ) ;
V_429 = F_20 ( V_84 -> V_434 . V_432 , sizeof( T_6 ) ) ;
V_4 = ( sizeof( * V_9 ) + sizeof( * V_206 ) ) +
( sizeof( * V_9 ) + V_428 ) +
( sizeof( * V_9 ) + V_429 ) +
( sizeof( * V_9 ) + sizeof( * V_427 ) ) ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_435 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_84 -> V_25 ) ;
V_206 -> V_436 = F_80 ( V_84 -> V_437 ? 0 : 1 ) ;
V_206 -> V_438 = F_80 ( V_84 -> V_439 ) ;
V_206 -> V_339 = F_80 ( V_84 -> V_440 ) ;
V_206 -> V_441 = F_80 ( V_84 -> V_442 ) ;
V_206 -> V_443 = F_80 ( V_84 -> V_444 ) ;
V_206 -> V_445 = F_80 ( V_84 -> V_446 ) ;
V_206 -> V_447 = F_80 ( V_84 -> V_448 ) ;
V_206 -> V_449 = F_80 ( V_84 -> V_430 ) ;
V_206 -> V_450 = F_80 ( V_84 -> V_451 ) ;
V_206 -> V_452 = F_80 ( V_84 -> V_453 ) ;
V_206 -> V_454 = F_80 ( V_84 -> V_455 ) ;
V_206 -> V_101 = F_80 ( V_84 -> V_456 ) ;
V_206 -> V_457 = F_80 ( V_84 -> V_431 . V_432 ) ;
V_206 -> V_458 = F_80 ( V_84 -> V_434 . V_432 ) ;
F_90 ( V_206 -> V_120 . V_122 , V_84 -> V_122 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_39 ) ;
V_9 -> V_4 = F_79 ( V_428 ) ;
memcpy ( V_9 -> V_208 , V_84 -> V_431 . V_459 ,
V_84 -> V_431 . V_432 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += V_428 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_39 ) ;
V_9 -> V_4 = F_79 ( V_429 ) ;
memcpy ( V_9 -> V_208 , V_84 -> V_434 . V_459 ,
V_84 -> V_434 . V_432 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += V_429 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_460 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_427 ) ) ;
V_427 = ( void * ) V_9 -> V_208 ;
V_427 -> V_461 = F_80 ( V_84 -> V_462 . V_461 ) ;
V_427 -> V_463 = F_80 ( V_84 -> V_462 . V_463 ) ;
V_427 -> V_464 = F_80 ( V_84 -> V_462 . V_464 ) ;
V_427 -> V_465 = F_80 ( V_84 -> V_462 . V_465 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_427 ) ;
F_3 ( V_2 , V_13 , L_36 ) ;
return V_22 ;
}
static struct V_21 *
F_112 ( struct V_1 * V_2 , T_4 V_25 ,
enum V_466 V_467 )
{
struct V_468 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_469 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
V_206 -> V_470 = F_80 ( V_467 ) ;
F_3 ( V_2 , V_13 , L_37 ) ;
return V_22 ;
}
static struct V_21 *
F_113 ( struct V_1 * V_2 , T_4 V_25 ,
enum V_471 V_226 ,
T_4 V_227 )
{
struct V_472 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_473 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
V_206 -> V_226 = F_80 ( V_226 ) ;
V_206 -> V_227 = F_80 ( V_227 ) ;
F_3 ( V_2 , V_13 , L_38 ) ;
return V_22 ;
}
static struct V_21 *
F_114 ( struct V_1 * V_2 , T_4 V_25 , const T_5 * V_474 ,
enum V_475 V_226 , T_4 V_208 )
{
struct V_476 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
if ( ! V_474 )
return F_10 ( - V_14 ) ;
V_22 = F_78 ( V_2 , sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_477 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
V_206 -> V_226 = F_80 ( V_226 ) ;
V_206 -> V_227 = F_80 ( V_208 ) ;
F_90 ( V_206 -> V_121 . V_122 , V_474 ) ;
F_3 ( V_2 , V_13 , L_39 ) ;
return V_22 ;
}
static struct V_21 *
F_115 ( struct V_1 * V_2 ,
const struct V_478 * V_84 )
{
struct V_479 * V_206 ;
struct V_335 * V_480 ;
struct V_481 * V_336 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_482 , V_4 ;
int V_148 ;
void * V_3 , * V_291 ;
V_482 = V_84 -> V_296 * ( sizeof( * V_9 ) + sizeof( * V_480 ) ) ;
V_4 = ( sizeof( * V_9 ) + sizeof( * V_206 ) ) +
( sizeof( * V_9 ) + V_482 ) ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_483 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_484 = F_80 ( V_84 -> V_296 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_133 ) ;
V_9 -> V_4 = F_79 ( V_482 ) ;
V_291 = ( void * ) V_9 -> V_208 ;
for ( V_148 = 0 ; V_148 < V_84 -> V_296 ; V_148 ++ ) {
V_336 = & V_84 -> V_308 [ V_148 ] ;
V_9 = V_291 ;
V_9 -> V_5 = F_79 ( V_350 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_480 ) ) ;
V_480 = ( void * ) V_9 -> V_208 ;
F_95 ( V_480 , V_336 ) ;
V_291 += sizeof( * V_9 ) ;
V_291 += sizeof( * V_480 ) ;
}
V_3 += sizeof( * V_9 ) ;
V_3 += V_482 ;
F_3 ( V_2 , V_13 , L_40 ) ;
return V_22 ;
}
static struct V_21 *
F_116 ( struct V_1 * V_2 , T_4 V_25 ,
const void * V_485 , T_1 V_486 ,
T_4 V_487 , bool V_488 ,
bool V_489 )
{
struct V_490 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
struct V_491 * V_492 ;
T_2 V_493 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_492 = (struct V_491 * ) V_485 ;
V_493 = F_117 ( V_492 -> V_494 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_495 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
V_206 -> V_202 = F_80 ( V_486 ) ;
V_206 -> V_496 = F_80 ( V_487 ) ;
V_206 -> V_497 = 0 ;
V_206 -> V_494 = F_80 ( V_493 ) ;
V_206 -> V_339 = 0 ;
if ( V_488 )
V_206 -> V_339 |= F_80 ( V_498 ) ;
if ( V_489 )
V_206 -> V_339 |= F_80 ( V_499 ) ;
F_3 ( V_2 , V_13 , L_41 ) ;
return V_22 ;
}
static struct V_21 *
F_118 ( struct V_1 * V_2 ,
const struct V_392 * V_84 )
{
struct V_500 * V_206 ;
struct V_389 * V_390 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 ;
void * V_3 ;
V_4 = ( sizeof( * V_9 ) + sizeof( * V_206 ) ) +
( 4 * ( sizeof( * V_9 ) + sizeof( * V_390 ) ) ) ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_501 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
V_3 = F_103 ( V_3 , & V_84 -> V_395 ) ;
V_3 = F_103 ( V_3 , & V_84 -> V_396 ) ;
V_3 = F_103 ( V_3 , & V_84 -> V_397 ) ;
V_3 = F_103 ( V_3 , & V_84 -> V_398 ) ;
F_3 ( V_2 , V_13 , L_42 ) ;
return V_22 ;
}
static struct V_21 *
F_119 ( struct V_1 * V_2 ,
enum V_502 V_503 )
{
struct V_504 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_505 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_503 = F_80 ( V_503 ) ;
F_3 ( V_2 , V_13 , L_43 ) ;
return V_22 ;
}
static struct V_21 *
F_120 ( struct V_1 * V_2 ,
enum V_506 type ,
T_4 V_507 )
{
struct V_508 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_78 ( V_2 , sizeof( * V_9 ) + sizeof( * V_206 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_79 ( V_509 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> type = F_80 ( type ) ;
V_206 -> V_507 = F_80 ( V_507 ) ;
F_3 ( V_2 , V_13 , L_44 ) ;
return V_22 ;
}
static struct V_21 *
F_121 ( struct V_1 * V_2 , T_4 V_510 ,
T_4 V_511 ) {
struct V_512 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 , V_513 ;
T_4 V_208 ;
void * V_3 ;
if ( V_510 ) {
V_208 = F_122 (
V_510 ,
V_514 ) ;
} else {
V_208 = F_122 (
V_515 ,
V_516 ) ;
}
V_513 = 0 ;
V_4 = sizeof( * V_9 ) + sizeof( * V_206 ) + sizeof( * V_9 ) + V_513 ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_517 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_518 = F_80 ( V_519 ) ;
V_206 -> V_208 = F_80 ( V_208 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_158 ) ;
V_9 -> V_4 = F_79 ( V_513 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( V_513 ) ;
F_3 ( V_2 , V_13 , L_45 , V_208 ) ;
return V_22 ;
}
static struct V_21 *
F_123 ( struct V_1 * V_2 , T_4 V_520 )
{
struct V_521 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
void * V_3 ;
T_1 V_4 ;
V_4 = sizeof( * V_9 ) + sizeof( * V_206 ) ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_522 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_520 = F_80 ( V_520 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
F_3 ( V_2 , V_13 , L_46 ,
V_520 ) ;
return V_22 ;
}
static struct V_21 *
F_124 ( struct V_1 * V_2 )
{
struct V_523 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
void * V_3 ;
T_1 V_4 ;
V_4 = sizeof( * V_9 ) + sizeof( * V_206 ) ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_524 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
F_3 ( V_2 , V_13 , L_47 ) ;
return V_22 ;
}
static struct V_21 *
F_125 ( struct V_1 * V_2 , T_4 V_25 ,
T_4 V_525 , struct V_21 * V_485 ,
T_4 V_526 , T_4 V_527 , void * V_528 ,
T_1 V_529 )
{
struct V_530 * V_206 ;
struct V_531 * V_532 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
void * V_3 ;
T_1 V_4 ;
if ( F_76 ( V_529 > 0 && ! V_528 ) )
return F_10 ( - V_14 ) ;
V_4 = sizeof( * V_9 ) + sizeof( * V_206 ) +
sizeof( * V_9 ) + sizeof( * V_532 ) + V_529 +
sizeof( * V_9 ) + F_20 ( V_485 -> V_4 , 4 ) ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_533 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
V_206 -> V_525 = F_80 ( V_525 ) ;
V_206 -> V_98 = F_80 ( V_485 -> V_4 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_534 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_532 ) + V_529 ) ;
V_532 = ( void * ) V_9 -> V_208 ;
V_532 -> V_441 = F_80 ( V_526 ) ;
V_532 -> V_535 = F_80 ( V_527 ) ;
memcpy ( V_532 -> V_536 , V_528 , V_529 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_532 ) ;
V_3 += V_529 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_39 ) ;
V_9 -> V_4 = F_79 ( F_20 ( V_485 -> V_4 , 4 ) ) ;
memcpy ( V_9 -> V_208 , V_485 -> V_6 , V_485 -> V_4 ) ;
F_3 ( V_2 , V_13 , L_48 ,
V_25 ) ;
return V_22 ;
}
static struct V_21 *
F_126 ( struct V_1 * V_2 , T_4 V_25 ,
struct V_21 * V_537 )
{
struct V_538 * V_206 ;
struct V_531 * V_532 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
void * V_3 ;
T_1 V_4 ;
V_4 = sizeof( * V_9 ) + sizeof( * V_206 ) +
sizeof( * V_9 ) + sizeof( * V_532 ) +
sizeof( * V_9 ) + F_20 ( V_537 -> V_4 , 4 ) ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_539 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
V_206 -> V_98 = F_80 ( V_537 -> V_4 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_534 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_532 ) ) ;
V_532 = ( void * ) V_9 -> V_208 ;
V_532 -> V_441 = 0 ;
V_532 -> V_535 = 0 ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_532 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_39 ) ;
V_9 -> V_4 = F_79 ( F_20 ( V_537 -> V_4 , 4 ) ) ;
memcpy ( V_9 -> V_208 , V_537 -> V_6 , V_537 -> V_4 ) ;
F_3 ( V_2 , V_13 , L_49 ,
V_25 ) ;
return V_22 ;
}
static struct V_21 *
F_127 ( struct V_1 * V_2 , T_4 V_25 ,
const T_5 * V_540 )
{
struct V_541 * V_206 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
void * V_3 ;
T_1 V_4 ;
V_4 = sizeof( * V_9 ) + sizeof( * V_206 ) +
sizeof( * V_9 ) + F_20 ( V_540 [ 1 ] + 2 , 4 ) ;
V_22 = F_78 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_542 ) ;
V_9 -> V_4 = F_79 ( sizeof( * V_206 ) ) ;
V_206 = ( void * ) V_9 -> V_208 ;
V_206 -> V_25 = F_80 ( V_25 ) ;
V_206 -> V_290 = F_80 ( V_540 [ 1 ] + 2 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_206 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_79 ( V_39 ) ;
V_9 -> V_4 = F_79 ( F_20 ( V_540 [ 1 ] + 2 , 4 ) ) ;
memcpy ( V_9 -> V_208 , V_540 , V_540 [ 1 ] + 2 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += F_20 ( V_540 [ 1 ] + 2 , 4 ) ;
F_3 ( V_2 , V_13 , L_50 ,
V_25 ) ;
return V_22 ;
}
void F_128 ( struct V_1 * V_2 )
{
V_2 -> V_236 . V_206 = & V_543 ;
V_2 -> V_236 . V_544 = & V_545 ;
V_2 -> V_236 . V_546 = & V_547 ;
V_2 -> V_236 . V_548 = & V_549 ;
}
