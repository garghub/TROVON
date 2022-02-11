const char * F_1 ( T_1 V_1 )
{
T_2 V_2 = V_1 ;
int V_3 ;
F_2 ( V_2 != V_1 ) ;
for ( V_3 = 0 ; V_4 [ V_3 ] . V_5 ; V_3 ++ )
if ( V_2 == V_4 [ V_3 ] . V_5 )
break;
return V_4 [ V_3 ] . V_6 ;
}
void F_3 ( int V_1 , struct V_7 * V_8 )
{
if ( V_1 & V_9 ) {
V_8 -> V_10 = 1001 ;
V_8 -> V_11 = 30000 ;
} else {
V_8 -> V_10 = 1 ;
V_8 -> V_11 = 25 ;
}
}
int F_4 ( struct V_12 * V_13 ,
int V_1 , const char * V_14 )
{
V_13 -> V_1 = V_1 ;
F_3 ( V_1 , & V_13 -> V_8 ) ;
V_13 -> V_15 = ( V_1 & V_9 ) ? 525 : 625 ;
F_5 ( V_13 -> V_14 , V_14 , sizeof( V_13 -> V_14 ) ) ;
return 0 ;
}
void F_6 ( unsigned int V_16 )
{
char * V_17 , * type ;
switch ( F_7 ( V_16 ) ) {
case 'd' :
type = L_1 ;
break;
case 'V' :
if ( F_8 ( V_16 ) >= V_18 ) {
type = L_2 ;
break;
}
F_9 ( L_3 , V_19 [ F_8 ( V_16 ) ] ) ;
return;
default:
type = L_4 ;
}
switch ( F_10 ( V_16 ) ) {
case V_20 : V_17 = L_5 ; break;
case V_21 : V_17 = L_6 ; break;
case V_22 : V_17 = L_7 ; break;
case V_21 | V_22 : V_17 = L_8 ; break;
default: V_17 = L_9 ; break;
}
F_9 ( L_10 ,
type , F_7 ( V_16 ) , V_17 , F_8 ( V_16 ) , V_16 ) ;
}
static void F_11 ( unsigned int V_16 , struct V_23 * V_24 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 = & V_26 -> V_29 ;
struct V_30 * V_31 ;
int V_3 ;
F_12 ( V_16 , L_11
L_12 ,
V_26 -> V_32 . V_33 / 3600 ,
( int ) ( V_26 -> V_32 . V_33 / 60 ) % 60 ,
( int ) ( V_26 -> V_32 . V_33 % 60 ) ,
( long ) V_26 -> V_32 . V_34 ,
V_26 -> V_35 ,
F_13 ( V_26 -> type , V_36 ) ,
V_26 -> V_37 , V_26 -> V_38 , V_26 -> V_39 ,
F_13 ( V_26 -> V_40 , V_41 ) ) ;
if ( F_14 ( V_26 -> type ) && V_26 -> V_42 . V_43 ) {
for ( V_3 = 0 ; V_3 < V_26 -> V_44 ; ++ V_3 ) {
V_31 = & V_26 -> V_42 . V_43 [ V_3 ] ;
F_15 ( L_13
L_14 ,
V_3 , V_31 -> V_45 , V_31 -> V_46 ,
V_31 -> V_42 . V_47 , V_31 -> V_44 ) ;
}
} else {
F_15 ( L_15 ,
V_26 -> V_45 , V_26 -> V_42 . V_47 , V_26 -> V_44 ) ;
}
F_15 ( L_16
L_17 ,
V_28 -> V_48 , V_28 -> V_49 , V_28 -> V_50 ,
V_28 -> type , V_28 -> V_37 , V_28 -> V_51 , * ( V_52 * ) V_28 -> V_53 ) ;
}
static inline void F_16 ( struct V_23 * V_24 , char * V_54 ,
struct V_55 * V_56 )
{
F_15 ( L_18 , V_54 , V_56 -> V_57 , V_56 -> V_58 ,
V_56 -> V_59 , V_56 -> V_60 ) ;
}
static inline void F_17 ( struct V_23 * V_24 ,
struct V_61 * V_62 )
{
F_15 ( L_19
L_20 ,
V_62 -> V_59 , V_62 -> V_60 ,
( V_62 -> V_63 & 0xff ) ,
( V_62 -> V_63 >> 8 ) & 0xff ,
( V_62 -> V_63 >> 16 ) & 0xff ,
( V_62 -> V_63 >> 24 ) & 0xff ,
F_13 ( V_62 -> V_38 , V_64 ) ,
V_62 -> V_65 , V_62 -> V_66 , V_62 -> V_67 ) ;
}
static inline void F_18 ( struct V_23 * V_24 ,
struct V_68 * V_62 )
{
int V_3 ;
F_15 ( L_19
L_21 ,
V_62 -> V_59 , V_62 -> V_60 ,
( V_62 -> V_63 & 0xff ) ,
( V_62 -> V_63 >> 8 ) & 0xff ,
( V_62 -> V_63 >> 16 ) & 0xff ,
( V_62 -> V_63 >> 24 ) & 0xff ,
F_13 ( V_62 -> V_38 , V_64 ) ,
V_62 -> V_67 , V_62 -> V_69 ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_69 ; ++ V_3 )
F_15 ( L_22 , V_3 ,
V_62 -> V_70 [ V_3 ] . V_65 ,
V_62 -> V_70 [ V_3 ] . V_66 ) ;
}
static inline void F_19 ( unsigned int V_16 ,
struct V_23 * V_24 , struct V_71 * V_72 , int V_73 )
{
V_52 V_3 ;
if ( ! ( V_24 -> V_74 & V_75 ) )
return;
F_12 ( V_16 , L_23 ) ;
F_9 ( V_76 L_24 , V_72 -> V_77 ) ;
for ( V_3 = 0 ; V_3 < V_72 -> V_78 ; V_3 ++ ) {
if ( V_73 && ! V_72 -> V_79 [ V_3 ] . V_80 )
F_9 ( V_76 L_25 ,
V_72 -> V_79 [ V_3 ] . V_1 , V_72 -> V_79 [ V_3 ] . V_81 ) ;
else
F_9 ( V_76 L_26 ,
V_72 -> V_79 [ V_3 ] . V_1 , V_72 -> V_79 [ V_3 ] . V_80 ) ;
}
F_9 ( V_76 L_27 ) ;
}
static inline int F_20 ( struct V_71 * V_72 , int V_82 )
{
V_52 V_3 ;
V_72 -> V_83 [ 0 ] = V_72 -> V_83 [ 1 ] = 0 ;
for ( V_3 = 0 ; V_3 < V_72 -> V_78 ; V_3 ++ )
V_72 -> V_79 [ V_3 ] . V_84 [ 0 ] = 0 ;
if ( ! V_82 && V_72 -> V_77 == V_85 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_72 -> V_78 ; V_3 ++ ) {
if ( F_21 ( V_72 -> V_79 [ V_3 ] . V_1 ) != V_72 -> V_77 ) {
V_72 -> V_86 = V_3 ;
return 0 ;
}
}
return 1 ;
}
static int F_22 ( const struct V_87 * V_88 , enum V_89 type )
{
if ( V_88 == NULL )
return - V_90 ;
switch ( type ) {
case V_91 :
if ( V_88 -> V_92 ||
V_88 -> V_93 )
return 0 ;
break;
case V_94 :
if ( V_88 -> V_93 )
return 0 ;
break;
case V_95 :
if ( V_88 -> V_96 )
return 0 ;
break;
case V_97 :
if ( V_88 -> V_98 ||
V_88 -> V_99 )
return 0 ;
break;
case V_100 :
if ( V_88 -> V_99 )
return 0 ;
break;
case V_101 :
if ( V_88 -> V_102 )
return 0 ;
break;
case V_103 :
if ( V_88 -> V_104 )
return 0 ;
break;
case V_105 :
if ( V_88 -> V_106 )
return 0 ;
break;
case V_107 :
if ( V_88 -> V_108 )
return 0 ;
break;
case V_109 :
if ( V_88 -> V_110 )
return 0 ;
break;
case V_111 :
if ( V_88 -> V_112 )
return 0 ;
break;
}
return - V_90 ;
}
static long F_23 ( struct V_113 * V_113 ,
unsigned int V_16 , void * V_114 )
{
struct V_23 * V_24 = F_24 ( V_113 ) ;
const struct V_87 * V_88 = V_24 -> V_115 ;
void * V_116 = V_113 -> V_117 ;
struct V_118 * V_119 = NULL ;
int V_120 = 0 ;
long V_121 = 0 ;
long V_122 = - V_123 ;
if ( V_88 == NULL ) {
F_9 ( V_124 L_28 ,
V_24 -> V_14 ) ;
return V_122 ;
}
if ( ( V_24 -> V_74 & V_125 ) &&
! ( V_24 -> V_74 & V_75 ) ) {
F_25 ( V_24 -> V_14 , V_16 ) ;
F_9 ( V_76 L_27 ) ;
}
if ( F_26 ( V_126 , & V_24 -> V_37 ) ) {
V_119 = V_113 -> V_117 ;
V_120 = F_26 ( V_127 , & V_24 -> V_37 ) ;
}
if ( V_120 )
V_121 = F_27 ( V_24 -> V_128 , V_119 -> V_128 ) ;
switch ( V_16 ) {
case V_129 :
{
struct V_130 * V_131 = (struct V_130 * ) V_114 ;
if ( ! V_88 -> V_132 )
break;
V_131 -> V_133 = V_134 ;
V_122 = V_88 -> V_132 ( V_113 , V_116 , V_131 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_29
L_30
L_31
L_32 ,
V_131 -> V_135 , V_131 -> V_136 , V_131 -> V_137 ,
V_131 -> V_133 ,
V_131 -> V_138 ,
V_131 -> V_139 ) ;
break;
}
case V_140 :
{
enum V_141 * V_26 = V_114 ;
if ( V_88 -> V_142 ) {
V_122 = V_88 -> V_142 ( V_113 , V_116 , V_26 ) ;
} else if ( V_120 ) {
* V_26 = F_28 ( & V_24 -> V_143 -> V_128 ) ;
V_122 = 0 ;
}
if ( ! V_122 )
F_12 ( V_16 , L_33 , * V_26 ) ;
break;
}
case V_144 :
{
enum V_141 * V_26 = V_114 ;
if ( ! V_88 -> V_145 && ! V_120 )
break;
F_12 ( V_16 , L_34 , * V_26 ) ;
if ( V_88 -> V_145 )
V_122 = V_88 -> V_145 ( V_113 , V_116 , * V_26 ) ;
else
V_122 = V_121 ? V_121 :
F_29 ( & V_24 -> V_143 -> V_128 ,
& V_119 -> V_128 , * V_26 ) ;
break;
}
case V_146 :
{
struct V_147 * V_148 = V_114 ;
switch ( V_148 -> type ) {
case V_91 :
if ( F_30 ( V_88 -> V_149 ) )
V_122 = V_88 -> V_149 ( V_113 , V_116 , V_148 ) ;
break;
case V_94 :
if ( F_30 ( V_88 -> V_150 ) )
V_122 = V_88 -> V_150 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_95 :
if ( F_30 ( V_88 -> V_151 ) )
V_122 = V_88 -> V_151 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_97 :
if ( F_30 ( V_88 -> V_152 ) )
V_122 = V_88 -> V_152 ( V_113 , V_116 , V_148 ) ;
break;
case V_100 :
if ( F_30 ( V_88 -> V_153 ) )
V_122 = V_88 -> V_153 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_111 :
if ( F_30 ( V_88 -> V_154 ) )
V_122 = V_88 -> V_154 ( V_113 ,
V_116 , V_148 ) ;
break;
default:
break;
}
if ( F_30 ( ! V_122 ) )
F_12 ( V_16 , L_35
L_36 ,
V_148 -> V_35 , V_148 -> type , V_148 -> V_37 ,
( V_148 -> V_63 & 0xff ) ,
( V_148 -> V_63 >> 8 ) & 0xff ,
( V_148 -> V_63 >> 16 ) & 0xff ,
( V_148 -> V_63 >> 24 ) & 0xff ,
V_148 -> V_155 ) ;
else if ( V_122 == - V_123 &&
( V_88 -> V_149 ||
V_88 -> V_152 ||
V_88 -> V_150 ||
V_88 -> V_153 ||
V_88 -> V_151 ||
V_88 -> V_154 ) )
V_122 = - V_90 ;
break;
}
case V_156 :
{
struct V_157 * V_148 = (struct V_157 * ) V_114 ;
F_12 ( V_16 , L_37 , F_13 ( V_148 -> type , V_36 ) ) ;
switch ( V_148 -> type ) {
case V_91 :
if ( V_88 -> V_92 )
V_122 = V_88 -> V_92 ( V_113 , V_116 , V_148 ) ;
if ( ! V_122 )
F_17 ( V_24 , & V_148 -> V_62 . V_158 ) ;
break;
case V_94 :
if ( V_88 -> V_93 )
V_122 = V_88 -> V_93 ( V_113 ,
V_116 , V_148 ) ;
if ( ! V_122 )
F_18 ( V_24 , & V_148 -> V_62 . V_159 ) ;
break;
case V_95 :
if ( F_30 ( V_88 -> V_96 ) )
V_122 = V_88 -> V_96 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_97 :
if ( V_88 -> V_98 )
V_122 = V_88 -> V_98 ( V_113 , V_116 , V_148 ) ;
if ( ! V_122 )
F_17 ( V_24 , & V_148 -> V_62 . V_158 ) ;
break;
case V_100 :
if ( V_88 -> V_99 )
V_122 = V_88 -> V_99 ( V_113 ,
V_116 , V_148 ) ;
if ( ! V_122 )
F_18 ( V_24 , & V_148 -> V_62 . V_159 ) ;
break;
case V_101 :
if ( F_30 ( V_88 -> V_102 ) )
V_122 = V_88 -> V_102 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_103 :
if ( F_30 ( V_88 -> V_104 ) )
V_122 = V_88 -> V_104 ( V_113 , V_116 , V_148 ) ;
break;
case V_105 :
if ( F_30 ( V_88 -> V_106 ) )
V_122 = V_88 -> V_106 ( V_113 , V_116 , V_148 ) ;
break;
case V_107 :
if ( F_30 ( V_88 -> V_108 ) )
V_122 = V_88 -> V_108 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_109 :
if ( F_30 ( V_88 -> V_110 ) )
V_122 = V_88 -> V_110 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_111 :
if ( F_30 ( V_88 -> V_112 ) )
V_122 = V_88 -> V_112 ( V_113 ,
V_116 , V_148 ) ;
break;
}
if ( F_31 ( V_122 == - V_123 && F_32 ( V_160 ) ) )
V_122 = - V_90 ;
break;
}
case V_161 :
{
struct V_157 * V_148 = (struct V_157 * ) V_114 ;
if ( ! F_32 ( V_54 ) )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
V_122 = - V_90 ;
F_12 ( V_16 , L_37 , F_13 ( V_148 -> type , V_36 ) ) ;
switch ( V_148 -> type ) {
case V_91 :
F_33 ( V_148 , V_62 . V_158 ) ;
F_17 ( V_24 , & V_148 -> V_62 . V_158 ) ;
if ( V_88 -> V_162 )
V_122 = V_88 -> V_162 ( V_113 , V_116 , V_148 ) ;
break;
case V_94 :
F_33 ( V_148 , V_62 . V_159 ) ;
F_18 ( V_24 , & V_148 -> V_62 . V_159 ) ;
if ( V_88 -> V_163 )
V_122 = V_88 -> V_163 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_95 :
F_33 ( V_148 , V_62 . V_164 ) ;
if ( V_88 -> V_165 )
V_122 = V_88 -> V_165 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_97 :
F_33 ( V_148 , V_62 . V_158 ) ;
F_17 ( V_24 , & V_148 -> V_62 . V_158 ) ;
if ( V_88 -> V_166 )
V_122 = V_88 -> V_166 ( V_113 , V_116 , V_148 ) ;
break;
case V_100 :
F_33 ( V_148 , V_62 . V_159 ) ;
F_18 ( V_24 , & V_148 -> V_62 . V_159 ) ;
if ( V_88 -> V_167 )
V_122 = V_88 -> V_167 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_101 :
F_33 ( V_148 , V_62 . V_164 ) ;
if ( V_88 -> V_168 )
V_122 = V_88 -> V_168 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_103 :
F_33 ( V_148 , V_62 . V_169 ) ;
if ( F_30 ( V_88 -> V_170 ) )
V_122 = V_88 -> V_170 ( V_113 , V_116 , V_148 ) ;
break;
case V_105 :
F_33 ( V_148 , V_62 . V_169 ) ;
if ( F_30 ( V_88 -> V_171 ) )
V_122 = V_88 -> V_171 ( V_113 , V_116 , V_148 ) ;
break;
case V_107 :
F_33 ( V_148 , V_62 . V_172 ) ;
if ( F_30 ( V_88 -> V_173 ) )
V_122 = V_88 -> V_173 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_109 :
F_33 ( V_148 , V_62 . V_172 ) ;
if ( F_30 ( V_88 -> V_174 ) )
V_122 = V_88 -> V_174 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_111 :
if ( F_30 ( V_88 -> V_175 ) )
V_122 = V_88 -> V_175 ( V_113 ,
V_116 , V_148 ) ;
break;
}
break;
}
case V_176 :
{
struct V_157 * V_148 = (struct V_157 * ) V_114 ;
F_12 ( V_16 , L_37 , F_13 ( V_148 -> type ,
V_36 ) ) ;
switch ( V_148 -> type ) {
case V_91 :
F_33 ( V_148 , V_62 . V_158 ) ;
if ( V_88 -> V_177 )
V_122 = V_88 -> V_177 ( V_113 , V_116 , V_148 ) ;
if ( ! V_122 )
F_17 ( V_24 , & V_148 -> V_62 . V_158 ) ;
break;
case V_94 :
F_33 ( V_148 , V_62 . V_159 ) ;
if ( V_88 -> V_178 )
V_122 = V_88 -> V_178 ( V_113 ,
V_116 , V_148 ) ;
if ( ! V_122 )
F_18 ( V_24 , & V_148 -> V_62 . V_159 ) ;
break;
case V_95 :
F_33 ( V_148 , V_62 . V_164 ) ;
if ( F_30 ( V_88 -> V_179 ) )
V_122 = V_88 -> V_179 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_97 :
F_33 ( V_148 , V_62 . V_158 ) ;
if ( V_88 -> V_180 )
V_122 = V_88 -> V_180 ( V_113 , V_116 , V_148 ) ;
if ( ! V_122 )
F_17 ( V_24 , & V_148 -> V_62 . V_158 ) ;
break;
case V_100 :
F_33 ( V_148 , V_62 . V_159 ) ;
if ( V_88 -> V_181 )
V_122 = V_88 -> V_181 ( V_113 ,
V_116 , V_148 ) ;
if ( ! V_122 )
F_18 ( V_24 , & V_148 -> V_62 . V_159 ) ;
break;
case V_101 :
F_33 ( V_148 , V_62 . V_164 ) ;
if ( F_30 ( V_88 -> V_182 ) )
V_122 = V_88 -> V_182 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_103 :
F_33 ( V_148 , V_62 . V_169 ) ;
if ( F_30 ( V_88 -> V_183 ) )
V_122 = V_88 -> V_183 ( V_113 , V_116 , V_148 ) ;
break;
case V_105 :
F_33 ( V_148 , V_62 . V_169 ) ;
if ( F_30 ( V_88 -> V_184 ) )
V_122 = V_88 -> V_184 ( V_113 , V_116 , V_148 ) ;
break;
case V_107 :
F_33 ( V_148 , V_62 . V_172 ) ;
if ( F_30 ( V_88 -> V_185 ) )
V_122 = V_88 -> V_185 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_109 :
F_33 ( V_148 , V_62 . V_172 ) ;
if ( F_30 ( V_88 -> V_186 ) )
V_122 = V_88 -> V_186 ( V_113 ,
V_116 , V_148 ) ;
break;
case V_111 :
if ( F_30 ( V_88 -> V_187 ) )
V_122 = V_88 -> V_187 ( V_113 ,
V_116 , V_148 ) ;
break;
}
if ( F_31 ( V_122 == - V_123 && F_32 ( V_188 ) ) )
V_122 = - V_90 ;
break;
}
case V_189 :
{
struct V_190 * V_26 = V_114 ;
if ( ! V_88 -> V_191 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
V_122 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_122 )
break;
if ( V_26 -> type < V_111 )
F_33 ( V_26 , V_40 ) ;
V_122 = V_88 -> V_191 ( V_113 , V_116 , V_26 ) ;
F_12 ( V_16 , L_38 ,
V_26 -> V_78 ,
F_13 ( V_26 -> type , V_36 ) ,
F_13 ( V_26 -> V_40 , V_41 ) ) ;
break;
}
case V_192 :
{
struct V_25 * V_26 = V_114 ;
if ( ! V_88 -> V_193 )
break;
V_122 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_122 )
break;
V_122 = V_88 -> V_193 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_11 ( V_16 , V_24 , V_26 ) ;
break;
}
case V_194 :
{
struct V_25 * V_26 = V_114 ;
if ( ! V_88 -> V_195 )
break;
V_122 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_122 )
break;
V_122 = V_88 -> V_195 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_11 ( V_16 , V_24 , V_26 ) ;
break;
}
case V_196 :
{
struct V_25 * V_26 = V_114 ;
if ( ! V_88 -> V_197 )
break;
V_122 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_122 )
break;
V_122 = V_88 -> V_197 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_11 ( V_16 , V_24 , V_26 ) ;
break;
}
case V_198 :
{
int * V_3 = V_114 ;
if ( ! V_88 -> V_199 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_39 , * V_3 ) ;
V_122 = V_88 -> V_199 ( V_113 , V_116 , * V_3 ) ;
break;
}
case V_200 :
{
struct V_201 * V_26 = V_114 ;
if ( ! V_88 -> V_202 )
break;
V_122 = V_88 -> V_202 ( V_113 , V_116 , V_114 ) ;
if ( ! V_122 ) {
F_12 ( V_16 , L_40 ,
V_26 -> V_203 , V_26 -> V_37 ,
( unsigned long ) V_26 -> V_204 ) ;
F_17 ( V_24 , & V_26 -> V_62 ) ;
}
break;
}
case V_205 :
{
struct V_201 * V_26 = V_114 ;
if ( ! V_88 -> V_206 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_40 ,
V_26 -> V_203 , V_26 -> V_37 , ( unsigned long ) V_26 -> V_204 ) ;
F_17 ( V_24 , & V_26 -> V_62 ) ;
V_122 = V_88 -> V_206 ( V_113 , V_116 , V_114 ) ;
break;
}
case V_207 :
{
enum V_89 V_3 = * ( int * ) V_114 ;
if ( ! V_88 -> V_208 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_37 , F_13 ( V_3 , V_36 ) ) ;
V_122 = V_88 -> V_208 ( V_113 , V_116 , V_3 ) ;
break;
}
case V_209 :
{
enum V_89 V_3 = * ( int * ) V_114 ;
if ( ! V_88 -> V_210 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_37 , F_13 ( V_3 , V_36 ) ) ;
V_122 = V_88 -> V_210 ( V_113 , V_116 , V_3 ) ;
break;
}
case V_211 :
{
struct V_12 * V_26 = V_114 ;
T_1 V_1 = V_24 -> V_212 , V_213 = 0 ;
unsigned int V_35 = V_26 -> V_35 , V_3 , V_214 = 0 ;
const char * V_6 = L_23 ;
if ( V_1 == 0 )
break;
V_122 = - V_90 ;
for ( V_3 = 0 ; V_3 <= V_35 && V_1 ; V_3 ++ ) {
while ( ( V_1 & V_4 [ V_214 ] . V_5 ) != V_4 [ V_214 ] . V_5 )
V_214 ++ ;
V_213 = V_4 [ V_214 ] . V_5 ;
V_6 = V_4 [ V_214 ] . V_6 ;
V_214 ++ ;
if ( V_213 == 0 )
break;
if ( V_213 != V_215 &&
V_213 != V_216 &&
V_213 != V_217 )
V_1 &= ~ V_213 ;
}
if ( V_3 <= V_35 )
break;
F_4 ( V_26 , V_213 , V_6 ) ;
F_12 ( V_16 , L_41
L_42 , V_26 -> V_35 ,
( unsigned long long ) V_26 -> V_1 , V_26 -> V_14 ,
V_26 -> V_8 . V_10 ,
V_26 -> V_8 . V_11 ,
V_26 -> V_15 ) ;
V_122 = 0 ;
break;
}
case V_218 :
{
T_1 * V_1 = V_114 ;
if ( V_88 -> V_219 )
V_122 = V_88 -> V_219 ( V_113 , V_116 , V_1 ) ;
else if ( V_24 -> V_220 ) {
V_122 = 0 ;
* V_1 = V_24 -> V_220 ;
}
if ( F_30 ( ! V_122 ) )
F_12 ( V_16 , L_43 , ( long long unsigned ) * V_1 ) ;
break;
}
case V_221 :
{
T_1 * V_1 = V_114 , V_222 ;
F_12 ( V_16 , L_44 , ( long long unsigned ) * V_1 ) ;
if ( ! V_88 -> V_223 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
V_122 = - V_90 ;
V_222 = ( * V_1 ) & V_24 -> V_212 ;
if ( V_24 -> V_212 && ! V_222 )
break;
V_122 = V_88 -> V_223 ( V_113 , V_116 , & V_222 ) ;
if ( V_122 >= 0 )
V_24 -> V_220 = V_222 ;
break;
}
case V_224 :
{
T_1 * V_26 = V_114 ;
if ( ! V_88 -> V_225 )
break;
* V_26 = V_24 -> V_212 ;
V_122 = V_88 -> V_225 ( V_113 , V_116 , V_114 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_45 ,
( unsigned long long ) * V_26 ) ;
break;
}
case V_226 :
{
struct V_227 * V_26 = V_114 ;
if ( V_88 -> V_223 )
V_26 -> V_138 |= V_228 ;
if ( V_88 -> V_229 )
V_26 -> V_138 |= V_230 ;
if ( V_88 -> V_231 )
V_26 -> V_138 |= V_232 ;
if ( ! V_88 -> V_233 )
break;
V_122 = V_88 -> V_233 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_46
L_47
L_48 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type , V_26 -> V_234 ,
V_26 -> V_235 ,
( unsigned long long ) V_26 -> V_5 ,
V_26 -> V_236 ) ;
break;
}
case V_237 :
{
unsigned int * V_3 = V_114 ;
if ( ! V_88 -> V_238 )
break;
V_122 = V_88 -> V_238 ( V_113 , V_116 , V_3 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_39 , * V_3 ) ;
break;
}
case V_239 :
{
unsigned int * V_3 = V_114 ;
if ( ! V_88 -> V_240 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_39 , * V_3 ) ;
V_122 = V_88 -> V_240 ( V_113 , V_116 , * V_3 ) ;
break;
}
case V_241 :
{
struct V_242 * V_26 = V_114 ;
if ( ! V_88 -> V_243 )
break;
if ( V_88 -> V_223 )
V_26 -> V_138 |= V_244 ;
if ( V_88 -> V_229 )
V_26 -> V_138 |= V_245 ;
if ( V_88 -> V_231 )
V_26 -> V_138 |= V_246 ;
V_122 = V_88 -> V_243 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_46
L_49
L_50 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type , V_26 -> V_234 ,
V_26 -> V_247 , ( unsigned long long ) V_26 -> V_5 ) ;
break;
}
case V_248 :
{
unsigned int * V_3 = V_114 ;
if ( ! V_88 -> V_249 )
break;
V_122 = V_88 -> V_249 ( V_113 , V_116 , V_3 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_39 , * V_3 ) ;
break;
}
case V_250 :
{
unsigned int * V_3 = V_114 ;
if ( ! V_88 -> V_251 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_39 , * V_3 ) ;
V_122 = V_88 -> V_251 ( V_113 , V_116 , * V_3 ) ;
break;
}
case V_252 :
{
struct V_253 * V_26 = V_114 ;
if ( V_119 && V_119 -> V_254 )
V_122 = V_253 ( V_119 -> V_254 , V_26 ) ;
else if ( V_24 -> V_254 )
V_122 = V_253 ( V_24 -> V_254 , V_26 ) ;
else if ( V_88 -> V_255 )
V_122 = V_88 -> V_255 ( V_113 , V_116 , V_26 ) ;
else
break;
if ( ! V_122 )
F_12 ( V_16 , L_51
L_52 ,
V_26 -> V_1 , V_26 -> type , V_26 -> V_14 ,
V_26 -> V_256 , V_26 -> V_257 ,
V_26 -> V_258 , V_26 -> V_259 , V_26 -> V_37 ) ;
else
F_12 ( V_16 , L_53 , V_26 -> V_1 ) ;
break;
}
case V_260 :
{
struct V_261 * V_26 = V_114 ;
if ( V_119 && V_119 -> V_254 )
V_122 = F_34 ( V_119 -> V_254 , V_26 ) ;
else if ( V_24 -> V_254 )
V_122 = F_34 ( V_24 -> V_254 , V_26 ) ;
else if ( V_88 -> V_262 )
V_122 = V_88 -> V_262 ( V_113 , V_116 , V_26 ) ;
else if ( V_88 -> V_263 ) {
struct V_71 V_264 ;
struct V_265 V_266 ;
V_264 . V_77 = F_21 ( V_26 -> V_1 ) ;
V_264 . V_78 = 1 ;
V_264 . V_79 = & V_266 ;
V_266 . V_1 = V_26 -> V_1 ;
V_266 . V_81 = V_26 -> V_81 ;
if ( F_20 ( & V_264 , 1 ) ) {
V_122 = V_88 -> V_263 ( V_113 , V_116 , & V_264 ) ;
if ( V_122 == 0 )
V_26 -> V_81 = V_266 . V_81 ;
}
} else
break;
if ( ! V_122 )
F_12 ( V_16 , L_54 , V_26 -> V_1 , V_26 -> V_81 ) ;
else
F_12 ( V_16 , L_53 , V_26 -> V_1 ) ;
break;
}
case V_267 :
{
struct V_261 * V_26 = V_114 ;
struct V_71 V_264 ;
struct V_265 V_266 ;
if ( ! ( V_119 && V_119 -> V_254 ) && ! V_24 -> V_254 &&
! V_88 -> V_268 && ! V_88 -> V_269 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_54 , V_26 -> V_1 , V_26 -> V_81 ) ;
if ( V_119 && V_119 -> V_254 ) {
V_122 = F_35 ( V_119 , V_119 -> V_254 , V_26 ) ;
break;
}
if ( V_24 -> V_254 ) {
V_122 = F_35 ( NULL , V_24 -> V_254 , V_26 ) ;
break;
}
if ( V_88 -> V_268 ) {
V_122 = V_88 -> V_268 ( V_113 , V_116 , V_26 ) ;
break;
}
if ( ! V_88 -> V_269 )
break;
V_264 . V_77 = F_21 ( V_26 -> V_1 ) ;
V_264 . V_78 = 1 ;
V_264 . V_79 = & V_266 ;
V_266 . V_1 = V_26 -> V_1 ;
V_266 . V_81 = V_26 -> V_81 ;
if ( F_20 ( & V_264 , 1 ) )
V_122 = V_88 -> V_269 ( V_113 , V_116 , & V_264 ) ;
else
V_122 = - V_90 ;
break;
}
case V_270 :
{
struct V_71 * V_26 = V_114 ;
V_26 -> V_86 = V_26 -> V_78 ;
if ( V_119 && V_119 -> V_254 )
V_122 = F_36 ( V_119 -> V_254 , V_26 ) ;
else if ( V_24 -> V_254 )
V_122 = F_36 ( V_24 -> V_254 , V_26 ) ;
else if ( V_88 -> V_263 )
V_122 = F_20 ( V_26 , 0 ) ?
V_88 -> V_263 ( V_113 , V_116 , V_26 ) :
- V_90 ;
else
break;
F_19 ( V_16 , V_24 , V_26 , ! V_122 ) ;
break;
}
case V_271 :
{
struct V_71 * V_26 = V_114 ;
V_26 -> V_86 = V_26 -> V_78 ;
if ( ! ( V_119 && V_119 -> V_254 ) && ! V_24 -> V_254 &&
! V_88 -> V_269 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_19 ( V_16 , V_24 , V_26 , 1 ) ;
if ( V_119 && V_119 -> V_254 )
V_122 = F_37 ( V_119 , V_119 -> V_254 , V_26 ) ;
else if ( V_24 -> V_254 )
V_122 = F_37 ( NULL , V_24 -> V_254 , V_26 ) ;
else if ( F_20 ( V_26 , 0 ) )
V_122 = V_88 -> V_269 ( V_113 , V_116 , V_26 ) ;
else
V_122 = - V_90 ;
break;
}
case V_272 :
{
struct V_71 * V_26 = V_114 ;
V_26 -> V_86 = V_26 -> V_78 ;
if ( ! ( V_119 && V_119 -> V_254 ) && ! V_24 -> V_254 &&
! V_88 -> V_273 )
break;
F_19 ( V_16 , V_24 , V_26 , 1 ) ;
if ( V_119 && V_119 -> V_254 )
V_122 = F_38 ( V_119 -> V_254 , V_26 ) ;
else if ( V_24 -> V_254 )
V_122 = F_38 ( V_24 -> V_254 , V_26 ) ;
else if ( F_20 ( V_26 , 0 ) )
V_122 = V_88 -> V_273 ( V_113 , V_116 , V_26 ) ;
else
V_122 = - V_90 ;
break;
}
case V_274 :
{
struct V_275 * V_26 = V_114 ;
if ( V_119 && V_119 -> V_254 )
V_122 = V_275 ( V_119 -> V_254 , V_26 ) ;
else if ( V_24 -> V_254 )
V_122 = V_275 ( V_24 -> V_254 , V_26 ) ;
else if ( V_88 -> V_276 )
V_122 = V_88 -> V_276 ( V_113 , V_116 , V_26 ) ;
else
break;
if ( ! V_122 )
F_12 ( V_16 , L_55 ,
V_26 -> V_1 , V_26 -> V_35 , V_26 -> V_14 ) ;
else
F_12 ( V_16 , L_56 ,
V_26 -> V_1 , V_26 -> V_35 ) ;
break;
}
case V_277 :
{
struct V_278 * V_26 = V_114 ;
if ( ! V_88 -> V_279 )
break;
V_122 = V_88 -> V_279 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_57
L_58 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_203 , V_26 -> V_280 ) ;
else
F_12 ( V_16 , L_59 , V_26 -> V_35 ) ;
break;
}
case V_281 :
{
struct V_278 * V_26 = V_114 ;
if ( ! V_88 -> V_282 )
break;
V_122 = V_88 -> V_282 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_57
L_58 , V_26 -> V_35 ,
V_26 -> V_14 , V_26 -> V_203 , V_26 -> V_280 ) ;
else
F_12 ( V_16 , L_59 , V_26 -> V_35 ) ;
break;
}
case V_283 :
{
struct V_278 * V_26 = V_114 ;
if ( ! V_88 -> V_284 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_57
L_58 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_203 , V_26 -> V_280 ) ;
V_122 = V_88 -> V_284 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_285 :
{
struct V_286 * V_26 = V_114 ;
if ( ! V_88 -> V_287 )
break;
F_12 ( V_16 , L_60 , V_26 -> V_35 ) ;
V_122 = V_88 -> V_287 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_15 ( L_61
L_62 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_203 , V_26 -> V_280 ) ;
break;
}
case V_288 :
{
struct V_286 * V_26 = V_114 ;
if ( ! V_88 -> V_289 )
break;
V_122 = V_88 -> V_289 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_15 ( L_61
L_62 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_203 , V_26 -> V_280 ) ;
break;
}
case V_290 :
{
struct V_286 * V_26 = V_114 ;
if ( ! V_88 -> V_291 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_61
L_62 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_203 , V_26 -> V_280 ) ;
V_122 = V_88 -> V_291 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_292 :
{
struct V_293 * V_26 = V_114 ;
if ( ! V_88 -> V_294 )
break;
V_122 = V_88 -> V_294 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_63
L_64
L_65 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> V_203 ,
V_26 -> V_295 , V_26 -> V_296 ,
V_26 -> V_297 ) ;
break;
}
case V_298 :
{
struct V_293 * V_26 = V_114 ;
if ( ! V_88 -> V_299 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_61
L_66 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> V_203 , V_26 -> V_295 ,
V_26 -> V_296 , V_26 -> V_297 ) ;
V_122 = V_88 -> V_299 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_300 :
{
struct V_301 * V_26 = V_114 ;
if ( ! V_88 -> V_302 && ! V_88 -> V_303 )
break;
F_12 ( V_16 , L_37 , F_13 ( V_26 -> type , V_36 ) ) ;
if ( V_88 -> V_302 ) {
V_122 = V_88 -> V_302 ( V_113 , V_116 , V_26 ) ;
} else {
struct V_304 V_54 = {
. type = V_26 -> type ,
} ;
if ( F_39 ( V_26 -> type ) )
V_54 . V_305 = V_306 ;
else
V_54 . V_305 = V_307 ;
V_122 = V_88 -> V_303 ( V_113 , V_116 , & V_54 ) ;
if ( ! V_122 )
V_26 -> V_72 = V_54 . V_56 ;
}
if ( ! V_122 )
F_16 ( V_24 , L_23 , & V_26 -> V_72 ) ;
break;
}
case V_308 :
{
struct V_301 * V_26 = V_114 ;
if ( ! V_88 -> V_309 && ! V_88 -> V_310 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_37 , F_13 ( V_26 -> type , V_36 ) ) ;
F_16 ( V_24 , L_23 , & V_26 -> V_72 ) ;
if ( V_88 -> V_309 ) {
V_122 = V_88 -> V_309 ( V_113 , V_116 , V_26 ) ;
} else {
struct V_304 V_54 = {
. type = V_26 -> type ,
. V_56 = V_26 -> V_72 ,
} ;
if ( F_39 ( V_26 -> type ) )
V_54 . V_305 = V_306 ;
else
V_54 . V_305 = V_307 ;
V_122 = V_88 -> V_310 ( V_113 , V_116 , & V_54 ) ;
}
break;
}
case V_311 :
{
struct V_304 * V_26 = V_114 ;
if ( ! V_88 -> V_303 )
break;
F_12 ( V_16 , L_37 , F_13 ( V_26 -> type , V_36 ) ) ;
V_122 = V_88 -> V_303 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_16 ( V_24 , L_23 , & V_26 -> V_56 ) ;
break;
}
case V_312 :
{
struct V_304 * V_26 = V_114 ;
if ( ! V_88 -> V_310 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_37 , F_13 ( V_26 -> type , V_36 ) ) ;
F_16 ( V_24 , L_23 , & V_26 -> V_56 ) ;
V_122 = V_88 -> V_310 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_313 :
{
struct V_314 * V_26 = V_114 ;
if ( ! V_88 -> V_315 && ! V_88 -> V_303 )
break;
F_12 ( V_16 , L_37 , F_13 ( V_26 -> type , V_36 ) ) ;
if ( V_88 -> V_315 ) {
V_122 = V_88 -> V_315 ( V_113 , V_116 , V_26 ) ;
} else {
struct V_304 V_54 = { . type = V_26 -> type } ;
if ( F_39 ( V_26 -> type ) )
V_54 . V_305 = V_316 ;
else
V_54 . V_305 = V_317 ;
V_122 = V_88 -> V_303 ( V_113 , V_116 , & V_54 ) ;
if ( V_122 )
break;
V_26 -> V_318 = V_54 . V_56 ;
if ( F_39 ( V_26 -> type ) )
V_54 . V_305 = V_319 ;
else
V_54 . V_305 = V_320 ;
V_122 = V_88 -> V_303 ( V_113 , V_116 , & V_54 ) ;
if ( V_122 )
break;
V_26 -> V_321 = V_54 . V_56 ;
V_26 -> V_322 . V_10 = 1 ;
V_26 -> V_322 . V_11 = 1 ;
}
if ( ! V_122 ) {
F_16 ( V_24 , L_67 , & V_26 -> V_318 ) ;
F_16 ( V_24 , L_68 , & V_26 -> V_321 ) ;
}
break;
}
case V_323 :
{
struct V_324 * V_26 = V_114 ;
if ( ! V_88 -> V_325 )
break;
V_122 = V_88 -> V_325 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_69
L_70
L_71 ,
V_26 -> V_326 , V_26 -> V_327 , V_26 -> V_328 ,
V_26 -> V_329 , V_26 -> V_330 ) ;
break;
}
case V_331 :
{
struct V_324 * V_26 = V_114 ;
if ( ! V_88 -> V_325 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_72
L_73 ,
V_26 -> V_326 , V_26 -> V_327 , V_26 -> V_328 ,
V_26 -> V_329 , V_26 -> V_330 ) ;
V_122 = V_88 -> V_332 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_333 :
{
struct V_334 * V_26 = V_114 ;
if ( ! V_88 -> V_335 )
break;
V_122 = V_88 -> V_335 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_74 ,
V_26 -> V_336 , V_26 -> V_337 ) ;
break;
}
case V_338 :
{
struct V_339 * V_26 = V_114 ;
if ( ! V_88 -> V_340 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
V_122 = V_88 -> V_340 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_75 , V_26 -> V_16 , V_26 -> V_37 ) ;
break;
}
case V_341 :
{
struct V_339 * V_26 = V_114 ;
if ( ! V_88 -> V_342 )
break;
V_122 = V_88 -> V_342 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_75 , V_26 -> V_16 , V_26 -> V_37 ) ;
break;
}
case V_343 :
{
struct V_344 * V_26 = V_114 ;
if ( ! V_88 -> V_345 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
V_122 = V_88 -> V_345 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_75 , V_26 -> V_16 , V_26 -> V_37 ) ;
break;
}
case V_346 :
{
struct V_344 * V_26 = V_114 ;
if ( ! V_88 -> V_347 )
break;
V_122 = V_88 -> V_347 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_75 , V_26 -> V_16 , V_26 -> V_37 ) ;
break;
}
case V_348 :
{
struct V_349 * V_26 = V_114 ;
if ( ! V_88 -> V_350 && ! V_24 -> V_220 )
break;
if ( V_88 -> V_350 ) {
V_122 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_122 )
break;
V_122 = V_88 -> V_350 ( V_113 , V_116 , V_26 ) ;
} else {
T_1 V_5 = V_24 -> V_220 ;
V_122 = - V_90 ;
if ( V_26 -> type != V_91 )
break;
V_122 = 0 ;
if ( V_88 -> V_219 )
V_122 = V_88 -> V_219 ( V_113 , V_116 , & V_5 ) ;
if ( V_122 == 0 )
F_3 ( V_5 ,
& V_26 -> V_351 . V_352 . V_353 ) ;
}
F_12 ( V_16 , L_76 , V_26 -> type ) ;
break;
}
case V_354 :
{
struct V_349 * V_26 = V_114 ;
if ( ! V_88 -> V_355 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
V_122 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_122 )
break;
F_12 ( V_16 , L_76 , V_26 -> type ) ;
V_122 = V_88 -> V_355 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_356 :
{
struct V_357 * V_26 = V_114 ;
if ( ! V_88 -> V_358 )
break;
V_26 -> type = ( V_24 -> V_359 == V_360 ) ?
V_361 : V_362 ;
V_122 = V_88 -> V_358 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_46
L_77
L_78
L_79 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type ,
V_26 -> V_203 , V_26 -> V_295 ,
V_26 -> V_296 , V_26 -> signal , V_26 -> V_363 ,
V_26 -> V_364 , V_26 -> V_365 ) ;
break;
}
case V_366 :
{
struct V_357 * V_26 = V_114 ;
if ( ! V_88 -> V_367 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
V_26 -> type = ( V_24 -> V_359 == V_360 ) ?
V_361 : V_362 ;
F_12 ( V_16 , L_46
L_77
L_78
L_79 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type ,
V_26 -> V_203 , V_26 -> V_295 ,
V_26 -> V_296 , V_26 -> signal , V_26 -> V_363 ,
V_26 -> V_364 , V_26 -> V_365 ) ;
V_122 = V_88 -> V_367 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_368 :
{
struct V_369 * V_26 = V_114 ;
if ( ! V_88 -> V_370 )
break;
V_26 -> type = ( V_24 -> V_359 == V_360 ) ?
V_361 : V_362 ;
V_122 = V_88 -> V_370 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_80 ,
V_26 -> V_235 , V_26 -> type , V_26 -> V_371 ) ;
break;
}
case V_372 :
{
struct V_369 * V_26 = V_114 ;
enum V_373 type ;
if ( ! V_88 -> V_374 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
type = ( V_24 -> V_359 == V_360 ) ?
V_361 : V_362 ;
F_12 ( V_16 , L_80 ,
V_26 -> V_235 , V_26 -> type , V_26 -> V_371 ) ;
if ( V_26 -> type != type )
V_122 = - V_90 ;
else
V_122 = V_88 -> V_374 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_375 :
{
struct V_376 * V_26 = V_114 ;
if ( ! V_88 -> V_377 )
break;
memset ( V_26 , 0 , F_40 ( struct V_376 , type ) ) ;
F_12 ( V_16 , L_37 , F_13 ( V_26 -> type , V_36 ) ) ;
V_122 = V_88 -> V_377 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_15 ( L_81 , V_26 -> V_378 ) ;
break;
}
case V_379 :
{
if ( ! V_88 -> V_380 )
break;
if ( V_24 -> V_143 )
F_41 ( L_82 ,
V_24 -> V_143 -> V_14 ) ;
V_122 = V_88 -> V_380 ( V_113 , V_116 ) ;
if ( V_24 -> V_143 )
F_41 ( L_83 ,
V_24 -> V_143 -> V_14 ) ;
break;
}
#ifdef F_42
case V_381 :
{
struct V_382 * V_26 = V_114 ;
if ( V_88 -> V_383 ) {
if ( ! F_43 ( V_384 ) )
V_122 = - V_385 ;
else
V_122 = V_88 -> V_383 ( V_113 , V_116 , V_26 ) ;
}
break;
}
case V_386 :
{
struct V_382 * V_26 = V_114 ;
if ( V_88 -> V_387 ) {
if ( ! F_43 ( V_384 ) )
V_122 = - V_385 ;
else
V_122 = V_88 -> V_387 ( V_113 , V_116 , V_26 ) ;
}
break;
}
#endif
case V_388 :
{
struct V_389 * V_26 = V_114 ;
if ( ! V_88 -> V_390 )
break;
V_26 -> V_391 = V_392 ;
V_26 -> V_393 = 0 ;
V_122 = V_88 -> V_390 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_84 , V_26 -> V_391 , V_26 -> V_393 ) ;
break;
}
case V_394 :
{
struct V_395 * V_26 = V_114 ;
enum V_373 type ;
if ( ! V_88 -> V_396 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
type = ( V_24 -> V_359 == V_360 ) ?
V_361 : V_362 ;
F_12 ( V_16 ,
L_85 ,
V_26 -> V_235 , V_26 -> type , V_26 -> V_397 , V_26 -> V_398 , V_26 -> V_399 ) ;
if ( V_26 -> type != type )
V_122 = - V_90 ;
else
V_122 = V_88 -> V_396 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_400 :
{
struct V_401 * V_26 = V_114 ;
if ( ! V_88 -> V_402 )
break;
V_122 = V_88 -> V_402 ( V_113 , V_116 , V_26 ) ;
F_12 ( V_16 ,
L_86 ,
V_26 -> V_35 ,
( V_26 -> V_403 & 0xff ) ,
( V_26 -> V_403 >> 8 ) & 0xff ,
( V_26 -> V_403 >> 16 ) & 0xff ,
( V_26 -> V_403 >> 24 ) & 0xff ,
V_26 -> type ) ;
switch ( V_26 -> type ) {
case V_404 :
F_44 ( L_87 ,
V_26 -> V_405 . V_59 , V_26 -> V_405 . V_60 ) ;
break;
case V_406 :
F_44 ( L_88 ,
V_26 -> V_407 . V_408 , V_26 -> V_407 . V_409 ,
V_26 -> V_407 . V_410 , V_26 -> V_407 . V_411 ,
V_26 -> V_407 . V_412 , V_26 -> V_407 . V_413 ) ;
break;
case V_414 :
F_44 ( L_89 ) ;
break;
default:
F_44 ( L_90 ) ;
}
break;
}
case V_415 :
{
struct V_416 * V_26 = V_114 ;
if ( ! V_88 -> V_417 )
break;
V_122 = V_88 -> V_417 ( V_113 , V_116 , V_26 ) ;
F_12 ( V_16 ,
L_91 ,
V_26 -> V_35 , V_26 -> V_403 ,
V_26 -> V_59 , V_26 -> V_60 , V_26 -> type ) ;
switch ( V_26 -> type ) {
case V_418 :
F_15 ( L_92 ,
V_26 -> V_405 . V_10 ,
V_26 -> V_405 . V_11 ) ;
break;
case V_419 :
F_15 ( L_93 ,
V_26 -> V_407 . V_420 . V_10 ,
V_26 -> V_407 . V_420 . V_11 ,
V_26 -> V_407 . V_421 . V_10 ,
V_26 -> V_407 . V_421 . V_11 ,
V_26 -> V_407 . V_258 . V_10 ,
V_26 -> V_407 . V_258 . V_11 ) ;
break;
case V_422 :
F_15 ( L_89 ) ;
break;
default:
F_15 ( L_90 ) ;
}
break;
}
case V_423 :
{
struct V_424 * V_26 = V_114 ;
if ( ! V_88 -> V_425 )
break;
V_122 = V_88 -> V_425 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 ,
L_94
L_95 ,
V_26 -> V_35 , V_26 -> V_426 , V_26 -> V_14 , V_26 -> V_59 ,
V_26 -> V_60 ) ;
break;
}
case V_427 :
{
struct V_428 * V_26 = V_114 ;
if ( ! V_88 -> V_229 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_96 , V_26 -> V_426 ) ;
V_122 = V_88 -> V_229 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_429 :
{
struct V_428 * V_26 = V_114 ;
if ( ! V_88 -> V_430 )
break;
V_122 = V_88 -> V_430 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_96 , V_26 -> V_426 ) ;
break;
}
case V_431 :
{
struct V_428 * V_26 = V_114 ;
if ( ! V_88 -> V_432 )
break;
V_122 = V_88 -> V_432 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_96 , V_26 -> V_426 ) ;
break;
}
case V_433 :
{
struct V_434 * V_26 = V_114 ;
if ( ! V_88 -> V_231 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
switch ( V_26 -> type ) {
case V_435 :
F_15 ( L_97
L_98
L_99
L_100
L_101
L_102 ,
V_26 -> V_436 . V_437 , V_26 -> V_436 . V_438 ,
V_26 -> V_436 . V_59 , V_26 -> V_436 . V_60 , V_26 -> V_436 . V_439 ,
V_26 -> V_436 . V_440 , V_26 -> V_436 . V_441 ,
V_26 -> V_436 . V_442 , V_26 -> V_436 . V_443 ,
V_26 -> V_436 . V_444 , V_26 -> V_436 . V_445 ,
V_26 -> V_436 . V_446 , V_26 -> V_436 . V_447 ,
V_26 -> V_436 . V_448 ) ;
V_122 = V_88 -> V_231 ( V_113 , V_116 , V_26 ) ;
break;
default:
F_15 ( L_103 , V_26 -> type ) ;
break;
}
break;
}
case V_449 :
{
struct V_434 * V_26 = V_114 ;
if ( ! V_88 -> V_450 )
break;
V_122 = V_88 -> V_450 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 ) {
switch ( V_26 -> type ) {
case V_435 :
F_15 ( L_104
L_105
L_98
L_106
L_107
L_108
L_101
L_102 ,
V_26 -> V_436 . V_437 , V_26 -> V_436 . V_438 ,
V_26 -> V_436 . V_59 , V_26 -> V_436 . V_60 ,
V_26 -> V_436 . V_439 , V_26 -> V_436 . V_440 ,
V_26 -> V_436 . V_441 , V_26 -> V_436 . V_442 ,
V_26 -> V_436 . V_443 , V_26 -> V_436 . V_444 ,
V_26 -> V_436 . V_445 , V_26 -> V_436 . V_446 ,
V_26 -> V_436 . V_447 , V_26 -> V_436 . V_448 ) ;
break;
default:
F_15 ( L_103 , V_26 -> type ) ;
break;
}
}
break;
}
case V_451 :
{
struct V_452 * V_453 = V_114 ;
if ( ! V_88 -> V_454 )
break;
V_122 = F_45 ( V_116 , V_453 , V_113 -> V_455 & V_456 ) ;
if ( V_122 < 0 ) {
F_12 ( V_16 , L_109 ) ;
break;
}
F_12 ( V_16 ,
L_110
L_111 ,
V_453 -> V_457 , V_453 -> type , V_453 -> V_39 ,
V_453 -> V_32 . V_33 , V_453 -> V_32 . V_458 ) ;
break;
}
case V_459 :
{
struct V_460 * V_461 = V_114 ;
if ( ! V_88 -> V_454 )
break;
V_122 = V_88 -> V_454 ( V_116 , V_461 ) ;
if ( V_122 < 0 ) {
F_12 ( V_16 , L_112 , V_122 ) ;
break;
}
F_12 ( V_16 , L_113 , V_461 -> type ) ;
break;
}
case V_462 :
{
struct V_460 * V_461 = V_114 ;
if ( ! V_88 -> V_463 )
break;
V_122 = V_88 -> V_463 ( V_116 , V_461 ) ;
if ( V_122 < 0 ) {
F_12 ( V_16 , L_112 , V_122 ) ;
break;
}
F_12 ( V_16 , L_113 , V_461 -> type ) ;
break;
}
case V_464 :
{
struct V_465 * V_466 = V_114 ;
if ( ! V_88 -> V_467 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
V_122 = F_22 ( V_88 , V_466 -> V_468 . type ) ;
if ( V_122 )
break;
V_122 = V_88 -> V_467 ( V_113 , V_116 , V_466 ) ;
F_12 ( V_16 , L_114 , V_466 -> V_78 , V_466 -> V_35 ) ;
break;
}
case V_469 :
{
struct V_25 * V_470 = V_114 ;
if ( ! V_88 -> V_471 )
break;
V_122 = F_22 ( V_88 , V_470 -> type ) ;
if ( V_122 )
break;
V_122 = V_88 -> V_471 ( V_113 , V_116 , V_470 ) ;
F_12 ( V_16 , L_115 , V_470 -> V_35 ) ;
break;
}
default:
if ( ! V_88 -> V_472 )
break;
V_122 = V_88 -> V_472 ( V_113 , V_116 , V_121 >= 0 , V_16 , V_114 ) ;
break;
}
if ( V_24 -> V_74 & V_75 ) {
if ( V_122 < 0 ) {
F_25 ( V_24 -> V_14 , V_16 ) ;
F_9 ( V_76 L_116 , V_122 ) ;
}
}
return V_122 ;
}
static unsigned long F_46 ( unsigned int V_16 )
{
#define F_47 ( V_16 , type , V_38 ) \
case VIDIOC_##cmd: \
return offsetof(struct v4l2_##type, field) + \
sizeof(((struct v4l2_##type *)0)->field);
switch ( V_16 ) {
F_47 ( V_473 , V_474 , type ) ;
F_47 ( V_475 , V_468 , type ) ;
F_47 ( V_476 , V_477 , V_44 ) ;
F_47 ( V_478 , V_479 , type ) ;
F_47 ( V_480 , V_481 , V_35 ) ;
F_47 ( V_482 , V_483 , V_35 ) ;
F_47 ( V_484 , V_485 , V_1 ) ;
F_47 ( V_486 , V_235 , V_35 ) ;
F_47 ( V_487 , V_488 , V_1 ) ;
F_47 ( V_489 , V_490 , V_35 ) ;
F_47 ( V_491 , V_492 , V_35 ) ;
F_47 ( V_493 , V_247 , V_35 ) ;
F_47 ( V_494 , V_371 , V_235 ) ;
F_47 ( V_495 , V_496 , type ) ;
F_47 ( V_497 , V_498 , type ) ;
F_47 ( V_499 , V_500 , V_35 ) ;
F_47 ( V_501 , V_502 , V_35 ) ;
F_47 ( V_503 , V_504 , V_37 ) ;
F_47 ( V_505 , V_504 , V_37 ) ;
F_47 ( V_506 , V_507 , type ) ;
F_47 ( V_508 , V_509 , V_403 ) ;
F_47 ( V_510 , V_511 , V_60 ) ;
default:
return F_48 ( V_16 ) ;
}
}
static int F_49 ( unsigned int V_16 , void * V_512 , T_3 * V_513 ,
void * T_4 * V_514 , void * * * V_515 )
{
int V_122 = 0 ;
switch ( V_16 ) {
case V_192 :
case V_194 :
case V_196 : {
struct V_25 * V_516 = V_512 ;
if ( F_14 ( V_516 -> type ) && V_516 -> V_44 > 0 ) {
if ( V_516 -> V_44 > V_517 ) {
V_122 = - V_90 ;
break;
}
* V_514 = ( void T_4 * ) V_516 -> V_42 . V_43 ;
* V_515 = ( void * ) & V_516 -> V_42 . V_43 ;
* V_513 = sizeof( struct V_30 ) * V_516 -> V_44 ;
V_122 = 1 ;
}
break;
}
case V_271 :
case V_270 :
case V_272 : {
struct V_71 * V_264 = V_512 ;
if ( V_264 -> V_78 != 0 ) {
if ( V_264 -> V_78 > V_518 ) {
V_122 = - V_90 ;
break;
}
* V_514 = ( void T_4 * ) V_264 -> V_79 ;
* V_515 = ( void * ) & V_264 -> V_79 ;
* V_513 = sizeof( struct V_265 )
* V_264 -> V_78 ;
V_122 = 1 ;
}
break;
}
}
return V_122 ;
}
long
F_50 ( struct V_113 * V_113 , unsigned int V_16 , unsigned long V_114 ,
T_5 V_519 )
{
char V_520 [ 128 ] ;
void * V_521 = NULL ;
void * V_512 = ( void * ) V_114 ;
long V_522 = - V_90 ;
bool V_523 ;
T_3 V_513 = 0 ;
void T_4 * V_514 = NULL ;
void * * V_515 = NULL ;
if ( F_10 ( V_16 ) != V_20 ) {
if ( F_48 ( V_16 ) <= sizeof( V_520 ) ) {
V_512 = V_520 ;
} else {
V_521 = F_51 ( F_48 ( V_16 ) , V_524 ) ;
if ( NULL == V_521 )
return - V_525 ;
V_512 = V_521 ;
}
V_522 = - V_526 ;
if ( F_10 ( V_16 ) & V_22 ) {
unsigned long V_527 = F_46 ( V_16 ) ;
if ( F_52 ( V_512 , ( void T_4 * ) V_114 , V_527 ) )
goto V_528;
if ( V_527 < F_48 ( V_16 ) )
memset ( ( V_529 * ) V_512 + V_527 , 0 , F_48 ( V_16 ) - V_527 ) ;
} else {
memset ( V_512 , 0 , F_48 ( V_16 ) ) ;
}
}
V_522 = F_49 ( V_16 , V_512 , & V_513 , & V_514 , & V_515 ) ;
if ( V_522 < 0 )
goto V_528;
V_523 = V_522 ;
if ( V_523 ) {
V_521 = F_51 ( V_513 , V_524 ) ;
V_522 = - V_525 ;
if ( NULL == V_521 )
goto V_530;
V_522 = - V_526 ;
if ( F_52 ( V_521 , V_514 , V_513 ) )
goto V_530;
* V_515 = V_521 ;
}
V_522 = V_519 ( V_113 , V_16 , V_512 ) ;
if ( V_522 == - V_531 )
V_522 = - V_123 ;
if ( V_523 ) {
* V_515 = V_514 ;
if ( F_53 ( V_514 , V_521 , V_513 ) )
V_522 = - V_526 ;
goto V_530;
}
if ( V_522 < 0 )
goto V_528;
V_530:
switch ( F_10 ( V_16 ) ) {
case V_21 :
case ( V_22 | V_21 ) :
if ( F_53 ( ( void T_4 * ) V_114 , V_512 , F_48 ( V_16 ) ) )
V_522 = - V_526 ;
break;
}
V_528:
F_54 ( V_521 ) ;
return V_522 ;
}
long F_55 ( struct V_113 * V_113 ,
unsigned int V_16 , unsigned long V_114 )
{
return F_50 ( V_113 , V_16 , V_114 , F_23 ) ;
}
