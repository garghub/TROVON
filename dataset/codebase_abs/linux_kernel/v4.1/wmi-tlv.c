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
static void F_75 ( const struct V_196 * V_197 ,
struct V_198 * V_199 )
{
int V_148 ;
V_199 -> V_25 = F_17 ( V_197 -> V_25 ) ;
V_199 -> V_200 = F_17 ( V_197 -> V_200 ) ;
V_199 -> V_201 = F_17 ( V_197 -> V_201 ) ;
V_199 -> V_202 = F_17 ( V_197 -> V_202 ) ;
V_199 -> V_203 = F_17 ( V_197 -> V_203 ) ;
V_199 -> V_204 = F_17 ( V_197 -> V_204 ) ;
V_199 -> V_205 = F_17 ( V_197 -> V_205 ) ;
V_199 -> V_206 = F_17 ( V_197 -> V_206 ) ;
V_199 -> V_207 = F_17 ( V_197 -> V_207 ) ;
for ( V_148 = 0 ; V_148 < F_5 ( V_197 -> V_208 ) ; V_148 ++ )
V_199 -> V_208 [ V_148 ] =
F_17 ( V_197 -> V_208 [ V_148 ] ) ;
for ( V_148 = 0 ; V_148 < F_5 ( V_197 -> V_209 ) ; V_148 ++ )
V_199 -> V_209 [ V_148 ] =
F_17 ( V_197 -> V_209 [ V_148 ] ) ;
for ( V_148 = 0 ; V_148 < F_5 ( V_197 -> V_210 ) ; V_148 ++ )
V_199 -> V_210 [ V_148 ] =
F_17 ( V_197 -> V_210 [ V_148 ] ) ;
for ( V_148 = 0 ; V_148 < F_5 ( V_197 -> V_211 ) ; V_148 ++ )
V_199 -> V_211 [ V_148 ] =
F_17 ( V_197 -> V_211 [ V_148 ] ) ;
for ( V_148 = 0 ; V_148 < F_5 ( V_197 -> V_212 ) ; V_148 ++ )
V_199 -> V_212 [ V_148 ] =
F_17 ( V_197 -> V_212 [ V_148 ] ) ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_213 * V_214 )
{
const void * * V_17 ;
const struct V_215 * V_24 ;
const void * V_6 ;
T_4 V_216 ;
T_4 V_217 ;
T_4 V_218 ;
T_4 V_219 ;
T_4 V_220 ;
T_1 V_221 ;
int V_12 ;
int V_148 ;
V_17 = F_8 ( V_2 , V_22 -> V_6 , V_22 -> V_4 , V_27 ) ;
if ( F_14 ( V_17 ) ) {
V_12 = F_15 ( V_17 ) ;
F_16 ( V_2 , L_4 , V_12 ) ;
return V_12 ;
}
V_24 = V_17 [ V_222 ] ;
V_6 = V_17 [ V_39 ] ;
if ( ! V_24 || ! V_6 ) {
F_11 ( V_17 ) ;
return - V_29 ;
}
V_221 = F_12 ( V_6 ) ;
V_216 = F_17 ( V_24 -> V_216 ) ;
V_217 = F_17 ( V_24 -> V_217 ) ;
V_218 = F_17 ( V_24 -> V_218 ) ;
V_219 = F_17 ( V_24 -> V_219 ) ;
V_220 = F_17 ( V_24 -> V_220 ) ;
F_3 ( V_2 , V_13 ,
L_13 ,
V_216 , V_217 , V_218 ,
V_219 , V_220 ) ;
for ( V_148 = 0 ; V_148 < V_216 ; V_148 ++ ) {
const struct V_223 * V_197 ;
struct V_224 * V_199 ;
V_197 = V_6 ;
if ( V_221 < sizeof( * V_197 ) )
return - V_29 ;
V_6 += sizeof( * V_197 ) ;
V_221 -= sizeof( * V_197 ) ;
V_199 = F_9 ( sizeof( * V_199 ) , V_27 ) ;
if ( ! V_199 )
continue;
F_77 ( & V_197 -> V_225 , V_199 ) ;
F_78 ( & V_197 -> V_226 , V_199 ) ;
F_79 ( & V_197 -> V_227 , V_199 ) ;
F_80 ( & V_199 -> V_228 , & V_214 -> V_229 ) ;
}
for ( V_148 = 0 ; V_148 < V_217 ; V_148 ++ ) {
const struct V_196 * V_197 ;
struct V_198 * V_199 ;
V_197 = V_6 ;
if ( V_221 < sizeof( * V_197 ) )
return - V_29 ;
V_6 += sizeof( * V_197 ) ;
V_221 -= sizeof( * V_197 ) ;
V_199 = F_9 ( sizeof( * V_199 ) , V_27 ) ;
if ( ! V_199 )
continue;
F_75 ( V_197 , V_199 ) ;
F_80 ( & V_199 -> V_228 , & V_214 -> V_230 ) ;
}
for ( V_148 = 0 ; V_148 < V_218 ; V_148 ++ ) {
const struct V_231 * V_197 ;
struct V_232 * V_199 ;
V_197 = V_6 ;
if ( V_221 < sizeof( * V_197 ) )
return - V_29 ;
V_6 += sizeof( * V_197 ) ;
V_221 -= sizeof( * V_197 ) ;
V_199 = F_9 ( sizeof( * V_199 ) , V_27 ) ;
if ( ! V_199 )
continue;
F_81 ( & V_197 -> V_233 , V_199 ) ;
V_199 -> V_234 = F_17 ( V_197 -> V_234 ) ;
F_80 ( & V_199 -> V_228 , & V_214 -> V_235 ) ;
}
F_11 ( V_17 ) ;
return 0 ;
}
static struct V_21 *
F_82 ( struct V_1 * V_2 , T_4 V_236 )
{
struct V_237 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_239 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_236 = F_85 ( V_236 ) ;
F_3 ( V_2 , V_13 , L_14 ) ;
return V_22 ;
}
static struct V_21 *
F_86 ( struct V_1 * V_2 )
{
struct V_241 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_242 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_243 = F_85 ( 0 ) ;
F_3 ( V_2 , V_13 , L_15 ) ;
return V_22 ;
}
static struct V_21 *
F_87 ( struct V_1 * V_2 ,
T_2 V_244 , T_2 V_245 , T_2 V_246 ,
T_2 V_247 , T_2 V_248 ,
enum V_249 V_250 )
{
struct V_251 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_252 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_253 = F_85 ( V_244 ) ;
V_238 -> V_254 = F_85 ( V_245 ) ;
V_238 -> V_255 = F_85 ( V_246 ) ;
V_238 -> V_256 = F_85 ( V_245 ) ;
V_238 -> V_257 = F_85 ( V_246 ) ;
F_3 ( V_2 , V_13 , L_16 ) ;
return V_22 ;
}
static struct V_21 *
F_88 ( struct V_1 * V_2 , T_4 V_258 ,
T_4 V_259 )
{
struct V_260 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_261 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_258 = F_85 ( V_258 ) ;
V_238 -> V_259 = F_85 ( V_259 ) ;
F_3 ( V_2 , V_13 , L_17 ) ;
return V_22 ;
}
static struct V_21 * F_89 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
struct V_8 * V_9 ;
struct V_262 * V_238 ;
struct V_263 * V_264 ;
struct V_265 * V_266 ;
T_1 V_4 , V_267 ;
void * V_3 ;
V_267 = V_2 -> V_268 . V_269 * sizeof( struct V_270 ) ;
V_4 = ( sizeof( * V_9 ) + sizeof( * V_238 ) ) +
( sizeof( * V_9 ) + sizeof( * V_264 ) ) +
( sizeof( * V_9 ) + V_267 ) ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_271 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_238 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_272 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_264 ) ) ;
V_264 = ( void * ) V_9 -> V_240 ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_264 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_133 ) ;
V_9 -> V_4 = F_84 ( V_267 ) ;
V_266 = ( void * ) V_9 -> V_240 ;
V_3 += sizeof( * V_9 ) ;
V_3 += V_267 ;
V_238 -> V_159 . V_160 = F_85 ( V_161 ) ;
V_238 -> V_159 . V_181 = F_85 ( V_273 ) ;
V_238 -> V_159 . V_162 = F_85 ( V_163 ) ;
V_238 -> V_159 . V_164 = F_85 ( V_165 ) ;
V_238 -> V_159 . V_166 = F_85 ( V_167 ) ;
V_238 -> V_159 . V_168 = F_85 ( V_169 ) ;
V_238 -> V_274 = F_85 ( V_2 -> V_268 . V_269 ) ;
V_264 -> V_275 = F_85 ( V_276 ) ;
V_264 -> V_277 = F_85 ( V_278 ) ;
if ( F_90 ( V_279 , V_2 -> V_268 . V_280 ) ) {
V_264 -> V_281 = F_85 ( 3 ) ;
V_264 -> V_282 = F_85 ( 3 ) ;
} else {
V_264 -> V_281 = F_85 ( 0 ) ;
V_264 -> V_282 = F_85 ( 0 ) ;
}
V_264 -> V_283 = F_85 ( 2 ) ;
V_264 -> V_284 = F_85 ( V_285 ) ;
V_264 -> V_286 = F_85 ( 0x10 ) ;
V_264 -> V_287 = F_85 ( 0x7 ) ;
V_264 -> V_288 = F_85 ( 0x7 ) ;
V_264 -> V_289 [ 0 ] = F_85 ( 0x64 ) ;
V_264 -> V_289 [ 1 ] = F_85 ( 0x64 ) ;
V_264 -> V_289 [ 2 ] = F_85 ( 0x64 ) ;
V_264 -> V_289 [ 3 ] = F_85 ( 0x28 ) ;
V_264 -> V_290 = F_85 ( 1 ) ;
V_264 -> V_291 = F_85 ( 4 ) ;
V_264 -> V_292 = F_85 ( 3 ) ;
V_264 -> V_293 = F_85 ( 3 ) ;
V_264 -> V_294 = F_85 ( 8 ) ;
V_264 -> V_295 = F_85 ( 0 ) ;
V_264 -> V_296 = F_85 ( 0 ) ;
V_264 -> V_297 = F_85 ( 0 ) ;
V_264 -> V_298 = F_85 ( 0x400 ) ;
V_264 -> V_299 = F_85 ( 0x20 ) ;
V_264 -> V_300 = F_85 ( 0 ) ;
V_264 -> V_301 = F_85 ( 0 ) ;
V_264 -> V_302 = F_85 ( 0 ) ;
V_264 -> V_303 = F_85 ( 0 ) ;
V_264 -> V_304 = F_85 ( 2 ) ;
V_264 -> V_305 = F_85 ( V_306 ) ;
V_264 -> V_307 = F_85 ( 2 ) ;
V_264 -> V_308 = F_85 ( 1 ) ;
V_264 -> V_309 = F_85 ( 0x20 ) ;
V_264 -> V_310 = F_85 ( 2 ) ;
V_264 -> V_311 = F_85 ( 5 ) ;
V_264 -> V_312 = F_85 ( 0x16 ) ;
V_264 -> V_313 = F_85 ( 6 ) ;
V_264 -> V_314 = F_85 ( 0 ) ;
V_264 -> V_315 = F_85 ( 1 ) ;
V_264 -> V_316 = F_85 ( 1 ) ;
F_91 ( V_2 , V_266 ) ;
F_3 ( V_2 , V_13 , L_18 ) ;
return V_22 ;
}
static struct V_21 *
F_92 ( struct V_1 * V_2 ,
const struct V_317 * V_84 )
{
struct V_318 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 , V_319 , V_320 , V_321 , V_322 ;
T_6 * V_323 ;
struct V_324 * V_325 ;
struct V_326 * V_327 ;
void * V_3 ;
int V_148 , V_12 ;
V_12 = F_93 ( V_84 ) ;
if ( V_12 )
return F_10 ( V_12 ) ;
V_319 = V_84 -> V_328 * sizeof( T_6 ) ;
V_320 = V_84 -> V_329 * sizeof( struct V_324 ) ;
V_321 = V_84 -> V_330 * sizeof( struct V_326 ) ;
V_322 = F_20 ( V_84 -> V_322 , 4 ) ;
V_4 = ( sizeof( * V_9 ) + sizeof( * V_238 ) ) +
( V_84 -> V_328 ? sizeof( * V_9 ) + V_319 : 0 ) +
( V_84 -> V_329 ? sizeof( * V_9 ) + V_320 : 0 ) +
( V_84 -> V_330 ? sizeof( * V_9 ) + V_321 : 0 ) +
( V_84 -> V_322 ? sizeof( * V_9 ) + V_322 : 0 ) ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_331 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
F_94 ( & V_238 -> V_332 , V_84 ) ;
V_238 -> V_333 = F_85 ( 0 ) ;
V_238 -> V_334 = F_85 ( V_84 -> V_328 ) ;
V_238 -> V_335 = F_85 ( V_84 -> V_329 ) ;
V_238 -> V_336 = F_85 ( V_84 -> V_330 ) ;
V_238 -> V_322 = F_85 ( V_84 -> V_322 ) ;
V_238 -> V_337 = F_85 ( 3 ) ;
V_238 -> V_332 . V_338 ^= F_85 ( V_339 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_238 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_158 ) ;
V_9 -> V_4 = F_84 ( V_319 ) ;
V_323 = ( void * ) V_9 -> V_240 ;
for ( V_148 = 0 ; V_148 < V_84 -> V_328 ; V_148 ++ )
V_323 [ V_148 ] = F_85 ( V_84 -> V_340 [ V_148 ] ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += V_319 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_341 ) ;
V_9 -> V_4 = F_84 ( V_320 ) ;
V_325 = ( void * ) V_9 -> V_240 ;
for ( V_148 = 0 ; V_148 < V_84 -> V_329 ; V_148 ++ ) {
V_325 [ V_148 ] . V_320 = F_85 ( V_84 -> V_325 [ V_148 ] . V_4 ) ;
memcpy ( V_325 [ V_148 ] . V_342 , V_84 -> V_325 [ V_148 ] . V_342 , V_84 -> V_325 [ V_148 ] . V_4 ) ;
}
V_3 += sizeof( * V_9 ) ;
V_3 += V_320 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_341 ) ;
V_9 -> V_4 = F_84 ( V_321 ) ;
V_327 = ( void * ) V_9 -> V_240 ;
for ( V_148 = 0 ; V_148 < V_84 -> V_330 ; V_148 ++ )
F_95 ( V_327 [ V_148 ] . V_122 , V_84 -> V_343 [ V_148 ] . V_344 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += V_321 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_39 ) ;
V_9 -> V_4 = F_84 ( V_322 ) ;
memcpy ( V_9 -> V_240 , V_84 -> V_345 , V_84 -> V_322 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += V_322 ;
F_3 ( V_2 , V_13 , L_19 ) ;
return V_22 ;
}
static struct V_21 *
F_96 ( struct V_1 * V_2 ,
const struct V_346 * V_84 )
{
struct V_347 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_4 V_91 ;
T_4 V_115 ;
if ( V_84 -> V_115 > 0xFFF )
return F_10 ( - V_14 ) ;
if ( V_84 -> V_348 == V_349 && V_84 -> V_350 . V_91 > 0xFFF )
return F_10 ( - V_14 ) ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_91 = V_84 -> V_350 . V_91 ;
V_91 |= V_351 ;
V_115 = V_84 -> V_115 ;
V_115 |= V_352 ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_353 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_348 = F_85 ( V_84 -> V_348 ) ;
V_238 -> V_25 = F_85 ( V_84 -> V_350 . V_25 ) ;
V_238 -> V_91 = F_85 ( V_91 ) ;
V_238 -> V_90 = F_85 ( V_115 ) ;
F_3 ( V_2 , V_13 , L_20 ) ;
return V_22 ;
}
static struct V_21 *
F_97 ( struct V_1 * V_2 ,
T_4 V_25 ,
enum V_354 V_355 ,
enum V_356 V_357 ,
const T_5 V_120 [ V_358 ] )
{
struct V_359 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_360 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
V_238 -> V_355 = F_85 ( V_355 ) ;
V_238 -> V_357 = F_85 ( V_357 ) ;
F_95 ( V_238 -> V_361 . V_122 , V_120 ) ;
F_3 ( V_2 , V_13 , L_21 ) ;
return V_22 ;
}
static struct V_21 *
F_98 ( struct V_1 * V_2 , T_4 V_25 )
{
struct V_362 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_363 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
F_3 ( V_2 , V_13 , L_22 ) ;
return V_22 ;
}
static struct V_21 *
F_99 ( struct V_1 * V_2 ,
const struct V_364 * V_84 ,
bool V_365 )
{
struct V_366 * V_238 ;
struct V_367 * V_368 ;
struct V_369 * V_370 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 ;
void * V_3 ;
T_4 V_371 = 0 ;
if ( F_100 ( V_84 -> V_342 && V_84 -> V_320 == 0 ) )
return F_10 ( - V_14 ) ;
if ( F_100 ( V_84 -> V_372 && ! V_84 -> V_342 ) )
return F_10 ( - V_14 ) ;
if ( F_100 ( V_84 -> V_320 > sizeof( V_238 -> V_342 . V_342 ) ) )
return F_10 ( - V_14 ) ;
V_4 = ( sizeof( * V_9 ) + sizeof( * V_238 ) ) +
( sizeof( * V_9 ) + sizeof( * V_368 ) ) +
( sizeof( * V_9 ) + 0 ) ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
if ( V_84 -> V_372 )
V_371 |= V_373 ;
if ( V_84 -> V_374 )
V_371 |= V_375 ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_376 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_84 -> V_25 ) ;
V_238 -> V_377 = F_85 ( V_84 -> V_377 ) ;
V_238 -> V_378 = F_85 ( V_84 -> V_378 ) ;
V_238 -> V_371 = F_85 ( V_371 ) ;
V_238 -> V_379 = F_85 ( V_84 -> V_379 ) ;
V_238 -> V_380 = F_85 ( V_84 -> V_380 ) ;
V_238 -> V_381 = F_85 ( V_84 -> V_381 ) ;
if ( V_84 -> V_342 ) {
V_238 -> V_342 . V_320 = F_85 ( V_84 -> V_320 ) ;
memcpy ( V_238 -> V_342 . V_342 , V_84 -> V_342 , V_84 -> V_320 ) ;
}
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_238 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_382 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_368 ) ) ;
V_368 = ( void * ) V_9 -> V_240 ;
F_101 ( V_368 , & V_84 -> V_97 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_368 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_133 ) ;
V_9 -> V_4 = 0 ;
V_370 = ( void * ) V_9 -> V_240 ;
V_3 += sizeof( * V_9 ) ;
V_3 += 0 ;
F_3 ( V_2 , V_13 , L_23 ) ;
return V_22 ;
}
static struct V_21 *
F_102 ( struct V_1 * V_2 , T_4 V_25 )
{
struct V_383 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_384 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
F_3 ( V_2 , V_13 , L_24 ) ;
return V_22 ;
}
static struct V_21 *
F_103 ( struct V_1 * V_2 , T_4 V_25 , T_4 V_385 ,
const T_5 * V_344 )
{
struct V_386 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_387 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
V_238 -> V_388 = F_85 ( V_385 ) ;
F_95 ( V_238 -> V_389 . V_122 , V_344 ) ;
F_3 ( V_2 , V_13 , L_25 ) ;
return V_22 ;
}
static struct V_21 *
F_104 ( struct V_1 * V_2 , T_4 V_25 )
{
struct V_390 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_391 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
F_3 ( V_2 , V_13 , L_26 ) ;
return V_22 ;
}
static struct V_21 *
F_105 ( struct V_1 * V_2 , T_4 V_25 ,
T_4 V_258 , T_4 V_259 )
{
struct V_392 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_393 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
V_238 -> V_258 = F_85 ( V_258 ) ;
V_238 -> V_259 = F_85 ( V_259 ) ;
F_3 ( V_2 , V_13 , L_27 ) ;
return V_22 ;
}
static struct V_21 *
F_106 ( struct V_1 * V_2 ,
const struct V_394 * V_84 )
{
struct V_395 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 ;
void * V_3 ;
if ( V_84 -> V_396 == V_397 && V_84 -> V_398 != NULL )
return F_10 ( - V_14 ) ;
if ( V_84 -> V_396 != V_397 && V_84 -> V_398 == NULL )
return F_10 ( - V_14 ) ;
V_4 = sizeof( * V_9 ) + sizeof( * V_238 ) +
sizeof( * V_9 ) + F_20 ( V_84 -> V_399 , sizeof( T_6 ) ) ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_400 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_84 -> V_25 ) ;
V_238 -> V_401 = F_85 ( V_84 -> V_401 ) ;
V_238 -> V_402 = F_85 ( V_84 -> V_402 ) ;
V_238 -> V_396 = F_85 ( V_84 -> V_396 ) ;
V_238 -> V_399 = F_85 ( V_84 -> V_399 ) ;
V_238 -> V_403 = F_85 ( V_84 -> V_403 ) ;
V_238 -> V_404 = F_85 ( V_84 -> V_404 ) ;
if ( V_84 -> V_405 )
F_95 ( V_238 -> V_121 . V_122 , V_84 -> V_405 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_238 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_39 ) ;
V_9 -> V_4 = F_84 ( F_20 ( V_84 -> V_399 , sizeof( T_6 ) ) ) ;
if ( V_84 -> V_398 )
memcpy ( V_9 -> V_240 , V_84 -> V_398 , V_84 -> V_399 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += F_20 ( V_84 -> V_399 , sizeof( T_6 ) ) ;
F_3 ( V_2 , V_13 , L_28 ) ;
return V_22 ;
}
static void * F_107 ( struct V_1 * V_2 , void * V_3 ,
const struct V_406 * V_84 )
{
struct V_407 * V_408 ;
struct V_8 * V_9 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_409 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_408 ) ) ;
V_408 = ( void * ) V_9 -> V_240 ;
V_408 -> V_410 = F_85 ( V_84 -> V_410 ) ;
V_408 -> V_411 = F_85 ( V_84 -> V_411 ) ;
V_408 -> V_412 = F_85 ( V_84 -> V_412 ) ;
V_408 -> V_413 = F_85 ( V_84 -> V_413 ) ;
V_408 -> V_414 = F_85 ( V_84 -> V_414 ) ;
F_3 ( V_2 , V_13 ,
L_29 ,
V_408 -> V_410 , V_408 -> V_411 , V_408 -> V_412 ,
V_408 -> V_413 , V_408 -> V_414 ) ;
return V_3 + sizeof( * V_9 ) + sizeof( * V_408 ) ;
}
static struct V_21 *
F_108 ( struct V_1 * V_2 , T_4 V_25 ,
const T_5 V_415 [ V_358 ] ,
const struct V_406 * args ,
T_4 V_416 )
{
struct V_417 * V_238 ;
struct V_407 * V_408 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 ;
T_1 V_418 ;
void * V_3 ;
int V_148 ;
V_418 = V_416 * ( sizeof( * V_9 ) + sizeof( * V_408 ) ) ;
V_4 = sizeof( * V_9 ) + sizeof( * V_238 ) +
sizeof( * V_9 ) + V_418 ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_419 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
V_238 -> V_416 = F_85 ( V_416 ) ;
F_95 ( V_238 -> V_121 . V_122 , V_415 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_238 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_133 ) ;
V_9 -> V_4 = F_84 ( V_418 ) ;
V_408 = ( void * ) V_9 -> V_240 ;
V_3 += sizeof( * V_9 ) ;
for ( V_148 = 0 ; V_148 < V_416 ; V_148 ++ )
V_3 = F_107 ( V_2 , V_3 , & args [ V_148 ] ) ;
F_3 ( V_2 , V_13 , L_30 ) ;
return V_22 ;
}
static void * F_109 ( void * V_3 ,
const struct V_420 * V_84 )
{
struct V_421 * V_422 ;
struct V_8 * V_9 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_423 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_422 ) ) ;
V_422 = ( void * ) V_9 -> V_240 ;
F_110 ( V_422 , V_84 ) ;
return V_3 + sizeof( * V_9 ) + sizeof( * V_422 ) ;
}
static struct V_21 *
F_111 ( struct V_1 * V_2 , T_4 V_25 ,
const struct V_424 * V_84 )
{
struct V_425 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 ;
void * V_3 ;
V_4 = sizeof( * V_9 ) + sizeof( * V_238 ) ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_426 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
F_110 ( & V_238 -> V_427 [ 0 ] . V_428 , & V_84 -> V_429 ) ;
F_110 ( & V_238 -> V_427 [ 1 ] . V_428 , & V_84 -> V_430 ) ;
F_110 ( & V_238 -> V_427 [ 2 ] . V_428 , & V_84 -> V_431 ) ;
F_110 ( & V_238 -> V_427 [ 3 ] . V_428 , & V_84 -> V_432 ) ;
F_3 ( V_2 , V_13 , L_31 ) ;
return V_22 ;
}
static struct V_21 *
F_112 ( struct V_1 * V_2 ,
const struct V_433 * V_84 )
{
struct V_434 * V_238 ;
struct V_435 * V_436 ;
struct V_21 * V_22 ;
struct V_8 * V_9 ;
void * V_3 ;
T_1 V_4 ;
V_4 = sizeof( * V_9 ) + sizeof( * V_238 ) +
sizeof( * V_9 ) + sizeof( * V_436 ) ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_437 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_84 -> V_25 ) ;
V_238 -> V_438 = F_85 ( V_84 -> V_438 ) ;
V_238 -> V_439 = F_85 ( V_84 -> V_439 ) ;
V_238 -> V_440 = F_85 ( V_84 -> V_440 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_238 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_441 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_436 ) ) ;
V_436 = ( void * ) V_9 -> V_240 ;
V_436 -> V_442 = V_84 -> V_442 ;
V_436 -> V_443 = V_84 -> V_443 ;
F_95 ( V_436 -> V_444 . V_122 , V_84 -> V_444 ) ;
F_3 ( V_2 , V_13 , L_32 ,
V_84 -> V_25 , V_84 -> V_438 , V_84 -> V_439 , V_84 -> V_440 ) ;
return V_22 ;
}
static struct V_21 *
F_113 ( struct V_1 * V_2 , T_4 V_25 ,
const T_5 V_415 [ V_358 ] )
{
struct V_445 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_446 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
V_238 -> V_447 = F_85 ( V_448 ) ;
F_95 ( V_238 -> V_415 . V_122 , V_415 ) ;
F_3 ( V_2 , V_13 , L_33 ) ;
return V_22 ;
}
static struct V_21 *
F_114 ( struct V_1 * V_2 , T_4 V_25 ,
const T_5 V_415 [ V_358 ] )
{
struct V_449 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_450 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
F_95 ( V_238 -> V_121 . V_122 , V_415 ) ;
F_3 ( V_2 , V_13 , L_34 ) ;
return V_22 ;
}
static struct V_21 *
F_115 ( struct V_1 * V_2 , T_4 V_25 ,
const T_5 V_415 [ V_358 ] , T_4 V_451 )
{
struct V_452 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_453 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
V_238 -> V_454 = F_85 ( V_451 ) ;
F_95 ( V_238 -> V_121 . V_122 , V_415 ) ;
F_3 ( V_2 , V_13 , L_35 ) ;
return V_22 ;
}
static struct V_21 *
F_116 ( struct V_1 * V_2 , T_4 V_25 ,
const T_5 * V_415 ,
enum V_455 V_258 ,
T_4 V_259 )
{
struct V_456 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_457 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
V_238 -> V_258 = F_85 ( V_258 ) ;
V_238 -> V_259 = F_85 ( V_259 ) ;
F_95 ( V_238 -> V_121 . V_122 , V_415 ) ;
F_3 ( V_2 , V_13 , L_36 ) ;
return V_22 ;
}
static struct V_21 *
F_117 ( struct V_1 * V_2 ,
const struct V_458 * V_84 )
{
struct V_459 * V_238 ;
struct V_460 * V_461 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 , V_462 , V_463 ;
void * V_3 ;
if ( V_84 -> V_464 > 16 )
return F_10 ( - V_14 ) ;
if ( V_84 -> V_465 . V_466 > V_467 )
return F_10 ( - V_14 ) ;
if ( V_84 -> V_468 . V_466 > V_467 )
return F_10 ( - V_14 ) ;
V_462 = F_20 ( V_84 -> V_465 . V_466 ,
sizeof( T_6 ) ) ;
V_463 = F_20 ( V_84 -> V_468 . V_466 , sizeof( T_6 ) ) ;
V_4 = ( sizeof( * V_9 ) + sizeof( * V_238 ) ) +
( sizeof( * V_9 ) + V_462 ) +
( sizeof( * V_9 ) + V_463 ) +
( sizeof( * V_9 ) + sizeof( * V_461 ) ) ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_469 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_84 -> V_25 ) ;
V_238 -> V_470 = F_85 ( V_84 -> V_471 ? 0 : 1 ) ;
V_238 -> V_472 = F_85 ( V_84 -> V_473 ) ;
V_238 -> V_371 = F_85 ( V_84 -> V_474 ) ;
V_238 -> V_475 = F_85 ( V_84 -> V_476 ) ;
V_238 -> V_477 = F_85 ( V_84 -> V_478 ) ;
V_238 -> V_479 = F_85 ( V_84 -> V_480 ) ;
V_238 -> V_481 = F_85 ( V_84 -> V_482 ) ;
V_238 -> V_483 = F_85 ( V_84 -> V_464 ) ;
V_238 -> V_484 = F_85 ( V_84 -> V_485 ) ;
V_238 -> V_486 = F_85 ( V_84 -> V_487 ) ;
V_238 -> V_488 = F_85 ( V_84 -> V_489 ) ;
V_238 -> V_101 = F_85 ( V_84 -> V_490 ) ;
V_238 -> V_491 = F_85 ( V_84 -> V_465 . V_466 ) ;
V_238 -> V_492 = F_85 ( V_84 -> V_468 . V_466 ) ;
F_95 ( V_238 -> V_120 . V_122 , V_84 -> V_122 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_238 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_39 ) ;
V_9 -> V_4 = F_84 ( V_462 ) ;
memcpy ( V_9 -> V_240 , V_84 -> V_465 . V_493 ,
V_84 -> V_465 . V_466 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += V_462 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_39 ) ;
V_9 -> V_4 = F_84 ( V_463 ) ;
memcpy ( V_9 -> V_240 , V_84 -> V_468 . V_493 ,
V_84 -> V_468 . V_466 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += V_463 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_494 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_461 ) ) ;
V_461 = ( void * ) V_9 -> V_240 ;
V_461 -> V_495 = F_85 ( V_84 -> V_496 . V_495 ) ;
V_461 -> V_497 = F_85 ( V_84 -> V_496 . V_497 ) ;
V_461 -> V_498 = F_85 ( V_84 -> V_496 . V_498 ) ;
V_461 -> V_499 = F_85 ( V_84 -> V_496 . V_499 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_461 ) ;
F_3 ( V_2 , V_13 , L_37 ) ;
return V_22 ;
}
static struct V_21 *
F_118 ( struct V_1 * V_2 , T_4 V_25 ,
enum V_500 V_501 )
{
struct V_502 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_503 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
V_238 -> V_504 = F_85 ( V_501 ) ;
F_3 ( V_2 , V_13 , L_38 ) ;
return V_22 ;
}
static struct V_21 *
F_119 ( struct V_1 * V_2 , T_4 V_25 ,
enum V_505 V_258 ,
T_4 V_259 )
{
struct V_506 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_507 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
V_238 -> V_258 = F_85 ( V_258 ) ;
V_238 -> V_259 = F_85 ( V_259 ) ;
F_3 ( V_2 , V_13 , L_39 ) ;
return V_22 ;
}
static struct V_21 *
F_120 ( struct V_1 * V_2 , T_4 V_25 , const T_5 * V_508 ,
enum V_509 V_258 , T_4 V_240 )
{
struct V_510 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
if ( ! V_508 )
return F_10 ( - V_14 ) ;
V_22 = F_83 ( V_2 , sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_511 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
V_238 -> V_258 = F_85 ( V_258 ) ;
V_238 -> V_259 = F_85 ( V_240 ) ;
F_95 ( V_238 -> V_121 . V_122 , V_508 ) ;
F_3 ( V_2 , V_13 , L_40 ) ;
return V_22 ;
}
static struct V_21 *
F_121 ( struct V_1 * V_2 ,
const struct V_512 * V_84 )
{
struct V_513 * V_238 ;
struct V_367 * V_514 ;
struct V_515 * V_368 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_516 , V_4 ;
int V_148 ;
void * V_3 , * V_323 ;
V_516 = V_84 -> V_328 * ( sizeof( * V_9 ) + sizeof( * V_514 ) ) ;
V_4 = ( sizeof( * V_9 ) + sizeof( * V_238 ) ) +
( sizeof( * V_9 ) + V_516 ) ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_517 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_518 = F_85 ( V_84 -> V_328 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_238 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_133 ) ;
V_9 -> V_4 = F_84 ( V_516 ) ;
V_323 = ( void * ) V_9 -> V_240 ;
for ( V_148 = 0 ; V_148 < V_84 -> V_328 ; V_148 ++ ) {
V_368 = & V_84 -> V_340 [ V_148 ] ;
V_9 = V_323 ;
V_9 -> V_5 = F_84 ( V_382 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_514 ) ) ;
V_514 = ( void * ) V_9 -> V_240 ;
F_101 ( V_514 , V_368 ) ;
V_323 += sizeof( * V_9 ) ;
V_323 += sizeof( * V_514 ) ;
}
V_3 += sizeof( * V_9 ) ;
V_3 += V_516 ;
F_3 ( V_2 , V_13 , L_41 ) ;
return V_22 ;
}
static struct V_21 *
F_122 ( struct V_1 * V_2 , T_4 V_25 ,
const void * V_519 , T_1 V_520 ,
T_4 V_521 , bool V_522 ,
bool V_523 )
{
struct V_524 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
struct V_525 * V_526 ;
T_2 V_527 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_526 = (struct V_525 * ) V_519 ;
V_527 = F_123 ( V_526 -> V_528 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_529 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
V_238 -> V_221 = F_85 ( V_520 ) ;
V_238 -> V_530 = F_85 ( V_521 ) ;
V_238 -> V_531 = 0 ;
V_238 -> V_528 = F_85 ( V_527 ) ;
V_238 -> V_371 = 0 ;
if ( V_522 )
V_238 -> V_371 |= F_85 ( V_532 ) ;
if ( V_523 )
V_238 -> V_371 |= F_85 ( V_533 ) ;
F_3 ( V_2 , V_13 , L_42 ) ;
return V_22 ;
}
static struct V_21 *
F_124 ( struct V_1 * V_2 ,
const struct V_424 * V_84 )
{
struct V_534 * V_238 ;
struct V_421 * V_422 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 ;
void * V_3 ;
V_4 = ( sizeof( * V_9 ) + sizeof( * V_238 ) ) +
( 4 * ( sizeof( * V_9 ) + sizeof( * V_422 ) ) ) ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_535 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_238 ) ;
V_3 = F_109 ( V_3 , & V_84 -> V_429 ) ;
V_3 = F_109 ( V_3 , & V_84 -> V_430 ) ;
V_3 = F_109 ( V_3 , & V_84 -> V_431 ) ;
V_3 = F_109 ( V_3 , & V_84 -> V_432 ) ;
F_3 ( V_2 , V_13 , L_43 ) ;
return V_22 ;
}
static struct V_21 *
F_125 ( struct V_1 * V_2 , T_4 V_536 )
{
struct V_537 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_538 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_539 = F_85 ( V_536 ) ;
F_3 ( V_2 , V_13 , L_44 ) ;
return V_22 ;
}
static struct V_21 *
F_126 ( struct V_1 * V_2 ,
enum V_540 type ,
T_4 V_541 )
{
struct V_542 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_22 = F_83 ( V_2 , sizeof( * V_9 ) + sizeof( * V_238 ) ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_9 = ( void * ) V_22 -> V_6 ;
V_9 -> V_5 = F_84 ( V_543 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> type = F_85 ( type ) ;
V_238 -> V_541 = F_85 ( V_541 ) ;
F_3 ( V_2 , V_13 , L_45 ) ;
return V_22 ;
}
static struct V_21 *
F_127 ( struct V_1 * V_2 , T_4 V_544 ,
T_4 V_545 ) {
struct V_546 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
T_1 V_4 , V_547 ;
T_4 V_240 ;
void * V_3 ;
if ( V_544 ) {
V_240 = F_128 (
V_544 ,
V_548 ) ;
} else {
V_240 = F_128 (
V_549 ,
V_550 ) ;
}
V_547 = 0 ;
V_4 = sizeof( * V_9 ) + sizeof( * V_238 ) + sizeof( * V_9 ) + V_547 ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_551 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_552 = F_85 ( V_553 ) ;
V_238 -> V_240 = F_85 ( V_240 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_238 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_158 ) ;
V_9 -> V_4 = F_84 ( V_547 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( V_547 ) ;
F_3 ( V_2 , V_13 , L_46 , V_240 ) ;
return V_22 ;
}
static struct V_21 *
F_129 ( struct V_1 * V_2 , T_4 V_554 )
{
struct V_555 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
void * V_3 ;
T_1 V_4 ;
V_4 = sizeof( * V_9 ) + sizeof( * V_238 ) ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_556 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_554 = F_85 ( V_554 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_238 ) ;
F_3 ( V_2 , V_13 , L_47 ,
V_554 ) ;
return V_22 ;
}
static struct V_21 *
F_130 ( struct V_1 * V_2 )
{
struct V_557 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
void * V_3 ;
T_1 V_4 ;
V_4 = sizeof( * V_9 ) + sizeof( * V_238 ) ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_558 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_238 ) ;
F_3 ( V_2 , V_13 , L_48 ) ;
return V_22 ;
}
static struct V_21 *
F_131 ( struct V_1 * V_2 , T_4 V_25 ,
T_4 V_559 , struct V_21 * V_519 ,
T_4 V_560 , T_4 V_561 , void * V_562 ,
T_1 V_563 )
{
struct V_564 * V_238 ;
struct V_565 * V_566 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
void * V_3 ;
T_1 V_4 ;
if ( F_100 ( V_563 > 0 && ! V_562 ) )
return F_10 ( - V_14 ) ;
V_4 = sizeof( * V_9 ) + sizeof( * V_238 ) +
sizeof( * V_9 ) + sizeof( * V_566 ) + V_563 +
sizeof( * V_9 ) + F_20 ( V_519 -> V_4 , 4 ) ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_567 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
V_238 -> V_559 = F_85 ( V_559 ) ;
V_238 -> V_98 = F_85 ( V_519 -> V_4 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_238 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_568 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_566 ) + V_563 ) ;
V_566 = ( void * ) V_9 -> V_240 ;
V_566 -> V_475 = F_85 ( V_560 ) ;
V_566 -> V_569 = F_85 ( V_561 ) ;
memcpy ( V_566 -> V_570 , V_562 , V_563 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_566 ) ;
V_3 += V_563 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_39 ) ;
V_9 -> V_4 = F_84 ( F_20 ( V_519 -> V_4 , 4 ) ) ;
memcpy ( V_9 -> V_240 , V_519 -> V_6 , V_519 -> V_4 ) ;
F_3 ( V_2 , V_13 , L_49 ,
V_25 ) ;
return V_22 ;
}
static struct V_21 *
F_132 ( struct V_1 * V_2 , T_4 V_25 ,
struct V_21 * V_571 )
{
struct V_572 * V_238 ;
struct V_565 * V_566 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
void * V_3 ;
T_1 V_4 ;
V_4 = sizeof( * V_9 ) + sizeof( * V_238 ) +
sizeof( * V_9 ) + sizeof( * V_566 ) +
sizeof( * V_9 ) + F_20 ( V_571 -> V_4 , 4 ) ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_573 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
V_238 -> V_98 = F_85 ( V_571 -> V_4 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_238 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_568 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_566 ) ) ;
V_566 = ( void * ) V_9 -> V_240 ;
V_566 -> V_475 = 0 ;
V_566 -> V_569 = 0 ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_566 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_39 ) ;
V_9 -> V_4 = F_84 ( F_20 ( V_571 -> V_4 , 4 ) ) ;
memcpy ( V_9 -> V_240 , V_571 -> V_6 , V_571 -> V_4 ) ;
F_3 ( V_2 , V_13 , L_50 ,
V_25 ) ;
return V_22 ;
}
static struct V_21 *
F_133 ( struct V_1 * V_2 , T_4 V_25 ,
const T_5 * V_574 )
{
struct V_575 * V_238 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
void * V_3 ;
T_1 V_4 ;
V_4 = sizeof( * V_9 ) + sizeof( * V_238 ) +
sizeof( * V_9 ) + F_20 ( V_574 [ 1 ] + 2 , 4 ) ;
V_22 = F_83 ( V_2 , V_4 ) ;
if ( ! V_22 )
return F_10 ( - V_20 ) ;
V_3 = ( void * ) V_22 -> V_6 ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_576 ) ;
V_9 -> V_4 = F_84 ( sizeof( * V_238 ) ) ;
V_238 = ( void * ) V_9 -> V_240 ;
V_238 -> V_25 = F_85 ( V_25 ) ;
V_238 -> V_322 = F_85 ( V_574 [ 1 ] + 2 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += sizeof( * V_238 ) ;
V_9 = V_3 ;
V_9 -> V_5 = F_84 ( V_39 ) ;
V_9 -> V_4 = F_84 ( F_20 ( V_574 [ 1 ] + 2 , 4 ) ) ;
memcpy ( V_9 -> V_240 , V_574 , V_574 [ 1 ] + 2 ) ;
V_3 += sizeof( * V_9 ) ;
V_3 += F_20 ( V_574 [ 1 ] + 2 , 4 ) ;
F_3 ( V_2 , V_13 , L_51 ,
V_25 ) ;
return V_22 ;
}
void F_134 ( struct V_1 * V_2 )
{
V_2 -> V_268 . V_238 = & V_577 ;
V_2 -> V_268 . V_578 = & V_579 ;
V_2 -> V_268 . V_580 = & V_581 ;
V_2 -> V_268 . V_582 = & V_583 ;
}
