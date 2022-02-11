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
static int F_23 ( const struct V_113 * V_114 ,
struct V_113 * V_115 )
{
struct V_68 * V_116 = & V_115 -> V_62 . V_116 ;
const struct V_61 * V_117 = & V_114 -> V_62 . V_117 ;
if ( V_114 -> type == V_91 )
V_115 -> type = V_94 ;
else if ( V_114 -> type == V_97 )
V_115 -> type = V_100 ;
else
return - V_90 ;
V_116 -> V_59 = V_117 -> V_59 ;
V_116 -> V_60 = V_117 -> V_60 ;
V_116 -> V_63 = V_117 -> V_63 ;
V_116 -> V_38 = V_117 -> V_38 ;
V_116 -> V_67 = V_117 -> V_67 ;
V_116 -> V_69 = 1 ;
V_116 -> V_70 [ 0 ] . V_66 = V_117 -> V_66 ;
V_116 -> V_70 [ 0 ] . V_65 = V_117 -> V_65 ;
return 0 ;
}
static int F_24 ( const struct V_113 * V_115 ,
struct V_113 * V_114 )
{
const struct V_68 * V_116 = & V_115 -> V_62 . V_116 ;
struct V_61 * V_117 = & V_114 -> V_62 . V_117 ;
if ( V_115 -> type == V_94 )
V_114 -> type = V_91 ;
else if ( V_115 -> type == V_100 )
V_114 -> type = V_97 ;
else
return - V_90 ;
V_117 -> V_59 = V_116 -> V_59 ;
V_117 -> V_60 = V_116 -> V_60 ;
V_117 -> V_63 = V_116 -> V_63 ;
V_117 -> V_38 = V_116 -> V_38 ;
V_117 -> V_67 = V_116 -> V_67 ;
V_117 -> V_66 = V_116 -> V_70 [ 0 ] . V_66 ;
V_117 -> V_65 = V_116 -> V_70 [ 0 ] . V_65 ;
return 0 ;
}
static long F_25 ( struct V_118 * V_118 ,
unsigned int V_16 , void * V_119 )
{
struct V_23 * V_24 = F_26 ( V_118 ) ;
const struct V_87 * V_88 = V_24 -> V_120 ;
void * V_121 = V_118 -> V_122 ;
struct V_123 * V_124 = NULL ;
struct V_113 V_125 ;
int V_126 = 0 ;
long V_127 = - V_90 ;
if ( V_88 == NULL ) {
F_9 ( V_128 L_28 ,
V_24 -> V_14 ) ;
return - V_90 ;
}
if ( ( V_24 -> V_74 & V_129 ) &&
! ( V_24 -> V_74 & V_75 ) ) {
F_27 ( V_24 -> V_14 , V_16 ) ;
F_9 ( V_76 L_27 ) ;
}
if ( F_28 ( V_130 , & V_24 -> V_37 ) ) {
V_124 = V_118 -> V_122 ;
V_126 = F_28 ( V_131 , & V_24 -> V_37 ) ;
}
if ( V_126 ) {
switch ( V_16 ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
V_127 = F_29 ( V_24 -> V_156 , V_124 -> V_156 ) ;
if ( V_127 )
goto V_157;
V_127 = - V_90 ;
break;
}
}
switch ( V_16 ) {
case V_158 :
{
struct V_159 * V_160 = (struct V_159 * ) V_119 ;
if ( ! V_88 -> V_161 )
break;
V_127 = V_88 -> V_161 ( V_118 , V_121 , V_160 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_29
L_30
L_31 ,
V_160 -> V_162 , V_160 -> V_163 , V_160 -> V_164 ,
V_160 -> V_165 ,
V_160 -> V_166 ) ;
break;
}
case V_167 :
{
enum V_168 * V_26 = V_119 ;
if ( V_88 -> V_169 ) {
V_127 = V_88 -> V_169 ( V_118 , V_121 , V_26 ) ;
} else if ( V_126 ) {
* V_26 = F_30 ( & V_24 -> V_170 -> V_156 ) ;
V_127 = 0 ;
}
if ( ! V_127 )
F_12 ( V_16 , L_32 , * V_26 ) ;
break;
}
case V_144 :
{
enum V_168 * V_26 = V_119 ;
if ( ! V_88 -> V_171 && ! V_126 )
break;
F_12 ( V_16 , L_33 , * V_26 ) ;
if ( V_88 -> V_171 )
V_127 = V_88 -> V_171 ( V_118 , V_121 , * V_26 ) ;
else
V_127 = F_31 ( & V_24 -> V_170 -> V_156 , & V_124 -> V_156 , * V_26 ) ;
break;
}
case V_172 :
{
struct V_173 * V_174 = V_119 ;
switch ( V_174 -> type ) {
case V_91 :
if ( V_88 -> V_175 )
V_127 = V_88 -> V_175 ( V_118 , V_121 , V_174 ) ;
break;
case V_94 :
if ( V_88 -> V_176 )
V_127 = V_88 -> V_176 ( V_118 ,
V_121 , V_174 ) ;
break;
case V_95 :
if ( V_88 -> V_177 )
V_127 = V_88 -> V_177 ( V_118 ,
V_121 , V_174 ) ;
break;
case V_97 :
if ( V_88 -> V_178 )
V_127 = V_88 -> V_178 ( V_118 , V_121 , V_174 ) ;
break;
case V_100 :
if ( V_88 -> V_179 )
V_127 = V_88 -> V_179 ( V_118 ,
V_121 , V_174 ) ;
break;
case V_111 :
if ( V_88 -> V_180 )
V_127 = V_88 -> V_180 ( V_118 ,
V_121 , V_174 ) ;
break;
default:
break;
}
if ( ! V_127 )
F_12 ( V_16 , L_34
L_35 ,
V_174 -> V_35 , V_174 -> type , V_174 -> V_37 ,
( V_174 -> V_63 & 0xff ) ,
( V_174 -> V_63 >> 8 ) & 0xff ,
( V_174 -> V_63 >> 16 ) & 0xff ,
( V_174 -> V_63 >> 24 ) & 0xff ,
V_174 -> V_181 ) ;
break;
}
case V_182 :
{
struct V_113 * V_174 = (struct V_113 * ) V_119 ;
F_12 ( V_16 , L_36 , F_13 ( V_174 -> type , V_36 ) ) ;
switch ( V_174 -> type ) {
case V_91 :
if ( V_88 -> V_92 ) {
V_127 = V_88 -> V_92 ( V_118 , V_121 , V_174 ) ;
} else if ( V_88 -> V_93 ) {
if ( F_23 ( V_174 , & V_125 ) )
break;
V_127 = V_88 -> V_93 ( V_118 , V_121 ,
& V_125 ) ;
if ( V_127 )
break;
if ( V_125 . V_62 . V_116 . V_69 > 1 ) {
V_127 = - V_183 ;
break;
}
V_127 = F_24 ( & V_125 , V_174 ) ;
}
if ( ! V_127 )
F_17 ( V_24 , & V_174 -> V_62 . V_117 ) ;
break;
case V_94 :
if ( V_88 -> V_93 ) {
V_127 = V_88 -> V_93 ( V_118 ,
V_121 , V_174 ) ;
} else if ( V_88 -> V_92 ) {
if ( F_24 ( V_174 , & V_125 ) )
break;
V_127 = V_88 -> V_92 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
V_127 = F_23 ( & V_125 , V_174 ) ;
}
if ( ! V_127 )
F_18 ( V_24 , & V_174 -> V_62 . V_116 ) ;
break;
case V_95 :
if ( V_88 -> V_96 )
V_127 = V_88 -> V_96 ( V_118 ,
V_121 , V_174 ) ;
break;
case V_97 :
if ( V_88 -> V_98 ) {
V_127 = V_88 -> V_98 ( V_118 , V_121 , V_174 ) ;
} else if ( V_88 -> V_99 ) {
if ( F_23 ( V_174 , & V_125 ) )
break;
V_127 = V_88 -> V_99 ( V_118 , V_121 ,
& V_125 ) ;
if ( V_127 )
break;
if ( V_125 . V_62 . V_116 . V_69 > 1 ) {
V_127 = - V_183 ;
break;
}
V_127 = F_24 ( & V_125 , V_174 ) ;
}
if ( ! V_127 )
F_17 ( V_24 , & V_174 -> V_62 . V_117 ) ;
break;
case V_100 :
if ( V_88 -> V_99 ) {
V_127 = V_88 -> V_99 ( V_118 ,
V_121 , V_174 ) ;
} else if ( V_88 -> V_98 ) {
if ( F_24 ( V_174 , & V_125 ) )
break;
V_127 = V_88 -> V_98 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
V_127 = F_23 ( & V_125 , V_174 ) ;
}
if ( ! V_127 )
F_18 ( V_24 , & V_174 -> V_62 . V_116 ) ;
break;
case V_101 :
if ( V_88 -> V_102 )
V_127 = V_88 -> V_102 ( V_118 ,
V_121 , V_174 ) ;
break;
case V_103 :
if ( V_88 -> V_104 )
V_127 = V_88 -> V_104 ( V_118 , V_121 , V_174 ) ;
break;
case V_105 :
if ( V_88 -> V_106 )
V_127 = V_88 -> V_106 ( V_118 , V_121 , V_174 ) ;
break;
case V_107 :
if ( V_88 -> V_108 )
V_127 = V_88 -> V_108 ( V_118 ,
V_121 , V_174 ) ;
break;
case V_109 :
if ( V_88 -> V_110 )
V_127 = V_88 -> V_110 ( V_118 ,
V_121 , V_174 ) ;
break;
case V_111 :
if ( V_88 -> V_112 )
V_127 = V_88 -> V_112 ( V_118 ,
V_121 , V_174 ) ;
break;
}
break;
}
case V_138 :
{
struct V_113 * V_174 = (struct V_113 * ) V_119 ;
F_12 ( V_16 , L_36 , F_13 ( V_174 -> type , V_36 ) ) ;
switch ( V_174 -> type ) {
case V_91 :
F_32 ( V_174 , V_62 . V_117 ) ;
F_17 ( V_24 , & V_174 -> V_62 . V_117 ) ;
if ( V_88 -> V_184 ) {
V_127 = V_88 -> V_184 ( V_118 , V_121 , V_174 ) ;
} else if ( V_88 -> V_185 ) {
if ( F_23 ( V_174 , & V_125 ) )
break;
V_127 = V_88 -> V_185 ( V_118 , V_121 ,
& V_125 ) ;
if ( V_127 )
break;
if ( V_125 . V_62 . V_116 . V_69 > 1 ) {
V_127 = - V_183 ;
F_33 ( 1 ) ;
break;
}
V_127 = F_24 ( & V_125 , V_174 ) ;
}
break;
case V_94 :
F_32 ( V_174 , V_62 . V_116 ) ;
F_18 ( V_24 , & V_174 -> V_62 . V_116 ) ;
if ( V_88 -> V_185 ) {
V_127 = V_88 -> V_185 ( V_118 ,
V_121 , V_174 ) ;
} else if ( V_88 -> V_184 &&
V_174 -> V_62 . V_116 . V_69 == 1 ) {
if ( F_24 ( V_174 , & V_125 ) )
break;
V_127 = V_88 -> V_184 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
V_127 = F_23 ( & V_125 , V_174 ) ;
}
break;
case V_95 :
F_32 ( V_174 , V_62 . V_186 ) ;
if ( V_88 -> V_187 )
V_127 = V_88 -> V_187 ( V_118 ,
V_121 , V_174 ) ;
break;
case V_97 :
F_32 ( V_174 , V_62 . V_117 ) ;
F_17 ( V_24 , & V_174 -> V_62 . V_117 ) ;
if ( V_88 -> V_188 ) {
V_127 = V_88 -> V_188 ( V_118 , V_121 , V_174 ) ;
} else if ( V_88 -> V_189 ) {
if ( F_23 ( V_174 , & V_125 ) )
break;
V_127 = V_88 -> V_189 ( V_118 , V_121 ,
& V_125 ) ;
if ( V_127 )
break;
if ( V_125 . V_62 . V_116 . V_69 > 1 ) {
V_127 = - V_183 ;
F_33 ( 1 ) ;
break;
}
V_127 = F_24 ( & V_125 , V_174 ) ;
}
break;
case V_100 :
F_32 ( V_174 , V_62 . V_116 ) ;
F_18 ( V_24 , & V_174 -> V_62 . V_116 ) ;
if ( V_88 -> V_189 ) {
V_127 = V_88 -> V_189 ( V_118 ,
V_121 , V_174 ) ;
} else if ( V_88 -> V_188 &&
V_174 -> V_62 . V_116 . V_69 == 1 ) {
if ( F_24 ( V_174 , & V_125 ) )
break;
V_127 = V_88 -> V_188 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
V_127 = F_24 ( & V_125 , V_174 ) ;
}
break;
case V_101 :
F_32 ( V_174 , V_62 . V_186 ) ;
if ( V_88 -> V_190 )
V_127 = V_88 -> V_190 ( V_118 ,
V_121 , V_174 ) ;
break;
case V_103 :
F_32 ( V_174 , V_62 . V_191 ) ;
if ( V_88 -> V_192 )
V_127 = V_88 -> V_192 ( V_118 , V_121 , V_174 ) ;
break;
case V_105 :
F_32 ( V_174 , V_62 . V_191 ) ;
if ( V_88 -> V_193 )
V_127 = V_88 -> V_193 ( V_118 , V_121 , V_174 ) ;
break;
case V_107 :
F_32 ( V_174 , V_62 . V_194 ) ;
if ( V_88 -> V_195 )
V_127 = V_88 -> V_195 ( V_118 ,
V_121 , V_174 ) ;
break;
case V_109 :
F_32 ( V_174 , V_62 . V_194 ) ;
if ( V_88 -> V_196 )
V_127 = V_88 -> V_196 ( V_118 ,
V_121 , V_174 ) ;
break;
case V_111 :
if ( V_88 -> V_197 )
V_127 = V_88 -> V_197 ( V_118 ,
V_121 , V_174 ) ;
break;
}
break;
}
case V_198 :
{
struct V_113 * V_174 = (struct V_113 * ) V_119 ;
F_12 ( V_16 , L_36 , F_13 ( V_174 -> type ,
V_36 ) ) ;
switch ( V_174 -> type ) {
case V_91 :
F_32 ( V_174 , V_62 . V_117 ) ;
if ( V_88 -> V_199 ) {
V_127 = V_88 -> V_199 ( V_118 , V_121 , V_174 ) ;
} else if ( V_88 -> V_200 ) {
if ( F_23 ( V_174 , & V_125 ) )
break;
V_127 = V_88 -> V_200 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
if ( V_125 . V_62 . V_116 . V_69 > 1 ) {
V_127 = - V_183 ;
F_33 ( 1 ) ;
break;
}
V_127 = F_24 ( & V_125 , V_174 ) ;
}
if ( ! V_127 )
F_17 ( V_24 , & V_174 -> V_62 . V_117 ) ;
break;
case V_94 :
F_32 ( V_174 , V_62 . V_116 ) ;
if ( V_88 -> V_200 ) {
V_127 = V_88 -> V_200 ( V_118 ,
V_121 , V_174 ) ;
} else if ( V_88 -> V_199 &&
V_174 -> V_62 . V_116 . V_69 == 1 ) {
if ( F_24 ( V_174 , & V_125 ) )
break;
V_127 = V_88 -> V_199 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
V_127 = F_23 ( & V_125 , V_174 ) ;
}
if ( ! V_127 )
F_18 ( V_24 , & V_174 -> V_62 . V_116 ) ;
break;
case V_95 :
F_32 ( V_174 , V_62 . V_186 ) ;
if ( V_88 -> V_201 )
V_127 = V_88 -> V_201 ( V_118 ,
V_121 , V_174 ) ;
break;
case V_97 :
F_32 ( V_174 , V_62 . V_117 ) ;
if ( V_88 -> V_202 ) {
V_127 = V_88 -> V_202 ( V_118 , V_121 , V_174 ) ;
} else if ( V_88 -> V_203 ) {
if ( F_23 ( V_174 , & V_125 ) )
break;
V_127 = V_88 -> V_203 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
if ( V_125 . V_62 . V_116 . V_69 > 1 ) {
V_127 = - V_183 ;
F_33 ( 1 ) ;
break;
}
V_127 = F_24 ( & V_125 , V_174 ) ;
}
if ( ! V_127 )
F_17 ( V_24 , & V_174 -> V_62 . V_117 ) ;
break;
case V_100 :
F_32 ( V_174 , V_62 . V_116 ) ;
if ( V_88 -> V_203 ) {
V_127 = V_88 -> V_203 ( V_118 ,
V_121 , V_174 ) ;
} else if ( V_88 -> V_202 &&
V_174 -> V_62 . V_116 . V_69 == 1 ) {
if ( F_24 ( V_174 , & V_125 ) )
break;
V_127 = V_88 -> V_202 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
V_127 = F_23 ( & V_125 , V_174 ) ;
}
if ( ! V_127 )
F_18 ( V_24 , & V_174 -> V_62 . V_116 ) ;
break;
case V_101 :
F_32 ( V_174 , V_62 . V_186 ) ;
if ( V_88 -> V_204 )
V_127 = V_88 -> V_204 ( V_118 ,
V_121 , V_174 ) ;
break;
case V_103 :
F_32 ( V_174 , V_62 . V_191 ) ;
if ( V_88 -> V_205 )
V_127 = V_88 -> V_205 ( V_118 , V_121 , V_174 ) ;
break;
case V_105 :
F_32 ( V_174 , V_62 . V_191 ) ;
if ( V_88 -> V_206 )
V_127 = V_88 -> V_206 ( V_118 , V_121 , V_174 ) ;
break;
case V_107 :
F_32 ( V_174 , V_62 . V_194 ) ;
if ( V_88 -> V_207 )
V_127 = V_88 -> V_207 ( V_118 ,
V_121 , V_174 ) ;
break;
case V_109 :
F_32 ( V_174 , V_62 . V_194 ) ;
if ( V_88 -> V_208 )
V_127 = V_88 -> V_208 ( V_118 ,
V_121 , V_174 ) ;
break;
case V_111 :
if ( V_88 -> V_209 )
V_127 = V_88 -> V_209 ( V_118 ,
V_121 , V_174 ) ;
break;
}
break;
}
case V_153 :
{
struct V_210 * V_26 = V_119 ;
if ( ! V_88 -> V_211 )
break;
V_127 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_127 )
break;
if ( V_26 -> type < V_111 )
F_32 ( V_26 , V_40 ) ;
V_127 = V_88 -> V_211 ( V_118 , V_121 , V_26 ) ;
F_12 ( V_16 , L_37 ,
V_26 -> V_78 ,
F_13 ( V_26 -> type , V_36 ) ,
F_13 ( V_26 -> V_40 , V_41 ) ) ;
break;
}
case V_212 :
{
struct V_25 * V_26 = V_119 ;
if ( ! V_88 -> V_213 )
break;
V_127 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_127 )
break;
V_127 = V_88 -> V_213 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_11 ( V_16 , V_24 , V_26 ) ;
break;
}
case V_214 :
{
struct V_25 * V_26 = V_119 ;
if ( ! V_88 -> V_215 )
break;
V_127 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_127 )
break;
V_127 = V_88 -> V_215 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_11 ( V_16 , V_24 , V_26 ) ;
break;
}
case V_216 :
{
struct V_25 * V_26 = V_119 ;
if ( ! V_88 -> V_217 )
break;
V_127 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_127 )
break;
V_127 = V_88 -> V_217 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_11 ( V_16 , V_24 , V_26 ) ;
break;
}
case V_152 :
{
int * V_3 = V_119 ;
if ( ! V_88 -> V_218 )
break;
F_12 ( V_16 , L_38 , * V_3 ) ;
V_127 = V_88 -> V_218 ( V_118 , V_121 , * V_3 ) ;
break;
}
case V_219 :
{
struct V_220 * V_26 = V_119 ;
if ( ! V_88 -> V_221 )
break;
V_127 = V_88 -> V_221 ( V_118 , V_121 , V_119 ) ;
if ( ! V_127 ) {
F_12 ( V_16 , L_39 ,
V_26 -> V_222 , V_26 -> V_37 ,
( unsigned long ) V_26 -> V_223 ) ;
F_17 ( V_24 , & V_26 -> V_62 ) ;
}
break;
}
case V_143 :
{
struct V_220 * V_26 = V_119 ;
if ( ! V_88 -> V_224 )
break;
F_12 ( V_16 , L_39 ,
V_26 -> V_222 , V_26 -> V_37 , ( unsigned long ) V_26 -> V_223 ) ;
F_17 ( V_24 , & V_26 -> V_62 ) ;
V_127 = V_88 -> V_224 ( V_118 , V_121 , V_119 ) ;
break;
}
case V_154 :
{
enum V_89 V_3 = * ( int * ) V_119 ;
if ( ! V_88 -> V_225 )
break;
F_12 ( V_16 , L_36 , F_13 ( V_3 , V_36 ) ) ;
V_127 = V_88 -> V_225 ( V_118 , V_121 , V_3 ) ;
break;
}
case V_155 :
{
enum V_89 V_3 = * ( int * ) V_119 ;
if ( ! V_88 -> V_226 )
break;
F_12 ( V_16 , L_36 , F_13 ( V_3 , V_36 ) ) ;
V_127 = V_88 -> V_226 ( V_118 , V_121 , V_3 ) ;
break;
}
case V_227 :
{
struct V_12 * V_26 = V_119 ;
T_1 V_1 = V_24 -> V_228 , V_229 = 0 ;
unsigned int V_35 = V_26 -> V_35 , V_3 , V_230 = 0 ;
const char * V_6 = L_23 ;
for ( V_3 = 0 ; V_3 <= V_35 && V_1 ; V_3 ++ ) {
while ( ( V_1 & V_4 [ V_230 ] . V_5 ) != V_4 [ V_230 ] . V_5 )
V_230 ++ ;
V_229 = V_4 [ V_230 ] . V_5 ;
V_6 = V_4 [ V_230 ] . V_6 ;
V_230 ++ ;
if ( V_229 == 0 )
break;
if ( V_229 != V_231 &&
V_229 != V_232 &&
V_229 != V_233 )
V_1 &= ~ V_229 ;
}
if ( V_3 <= V_35 )
break;
F_4 ( V_26 , V_229 , V_6 ) ;
F_12 ( V_16 , L_40
L_41 , V_26 -> V_35 ,
( unsigned long long ) V_26 -> V_1 , V_26 -> V_14 ,
V_26 -> V_8 . V_10 ,
V_26 -> V_8 . V_11 ,
V_26 -> V_15 ) ;
V_127 = 0 ;
break;
}
case V_234 :
{
T_1 * V_1 = V_119 ;
V_127 = 0 ;
if ( V_88 -> V_235 )
V_127 = V_88 -> V_235 ( V_118 , V_121 , V_1 ) ;
else if ( V_24 -> V_236 )
* V_1 = V_24 -> V_236 ;
else
V_127 = - V_90 ;
if ( ! V_127 )
F_12 ( V_16 , L_42 , ( long long unsigned ) * V_1 ) ;
break;
}
case V_133 :
{
T_1 * V_1 = V_119 , V_237 ;
F_12 ( V_16 , L_43 , ( long long unsigned ) * V_1 ) ;
V_237 = ( * V_1 ) & V_24 -> V_228 ;
if ( V_24 -> V_228 && ! V_237 )
break;
if ( V_88 -> V_238 )
V_127 = V_88 -> V_238 ( V_118 , V_121 , & V_237 ) ;
else
V_127 = - V_90 ;
if ( V_127 >= 0 )
V_24 -> V_236 = V_237 ;
break;
}
case V_239 :
{
T_1 * V_26 = V_119 ;
if ( ! V_88 -> V_240 )
break;
V_127 = V_88 -> V_240 ( V_118 , V_121 , V_119 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_44 ,
( unsigned long long ) * V_26 ) ;
break;
}
case V_241 :
{
struct V_242 * V_26 = V_119 ;
if ( V_88 -> V_238 )
V_26 -> V_166 |= V_243 ;
if ( V_88 -> V_244 )
V_26 -> V_166 |= V_245 ;
if ( V_88 -> V_246 )
V_26 -> V_166 |= V_247 ;
if ( ! V_88 -> V_248 )
break;
V_127 = V_88 -> V_248 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_45
L_46
L_47 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type , V_26 -> V_249 ,
V_26 -> V_250 ,
( unsigned long long ) V_26 -> V_5 ,
V_26 -> V_251 ) ;
break;
}
case V_252 :
{
unsigned int * V_3 = V_119 ;
if ( ! V_88 -> V_253 )
break;
V_127 = V_88 -> V_253 ( V_118 , V_121 , V_3 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_38 , * V_3 ) ;
break;
}
case V_134 :
{
unsigned int * V_3 = V_119 ;
if ( ! V_88 -> V_254 )
break;
F_12 ( V_16 , L_38 , * V_3 ) ;
V_127 = V_88 -> V_254 ( V_118 , V_121 , * V_3 ) ;
break;
}
case V_255 :
{
struct V_256 * V_26 = V_119 ;
if ( ! V_88 -> V_257 )
break;
if ( V_88 -> V_238 )
V_26 -> V_166 |= V_258 ;
if ( V_88 -> V_244 )
V_26 -> V_166 |= V_259 ;
if ( V_88 -> V_246 )
V_26 -> V_166 |= V_260 ;
V_127 = V_88 -> V_257 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_45
L_48
L_49 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type , V_26 -> V_249 ,
V_26 -> V_261 , ( unsigned long long ) V_26 -> V_5 ) ;
break;
}
case V_262 :
{
unsigned int * V_3 = V_119 ;
if ( ! V_88 -> V_263 )
break;
V_127 = V_88 -> V_263 ( V_118 , V_121 , V_3 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_38 , * V_3 ) ;
break;
}
case V_135 :
{
unsigned int * V_3 = V_119 ;
if ( ! V_88 -> V_264 )
break;
F_12 ( V_16 , L_38 , * V_3 ) ;
V_127 = V_88 -> V_264 ( V_118 , V_121 , * V_3 ) ;
break;
}
case V_265 :
{
struct V_266 * V_26 = V_119 ;
if ( V_24 -> V_267 )
V_127 = V_266 ( V_24 -> V_267 , V_26 ) ;
else if ( V_88 -> V_268 )
V_127 = V_88 -> V_268 ( V_118 , V_121 , V_26 ) ;
else
break;
if ( ! V_127 )
F_12 ( V_16 , L_50
L_51 ,
V_26 -> V_1 , V_26 -> type , V_26 -> V_14 ,
V_26 -> V_269 , V_26 -> V_270 ,
V_26 -> V_271 , V_26 -> V_272 , V_26 -> V_37 ) ;
else
F_12 ( V_16 , L_52 , V_26 -> V_1 ) ;
break;
}
case V_273 :
{
struct V_274 * V_26 = V_119 ;
if ( V_24 -> V_267 )
V_127 = F_34 ( V_24 -> V_267 , V_26 ) ;
else if ( V_88 -> V_275 )
V_127 = V_88 -> V_275 ( V_118 , V_121 , V_26 ) ;
else if ( V_88 -> V_276 ) {
struct V_71 V_277 ;
struct V_278 V_279 ;
V_277 . V_77 = F_21 ( V_26 -> V_1 ) ;
V_277 . V_78 = 1 ;
V_277 . V_79 = & V_279 ;
V_279 . V_1 = V_26 -> V_1 ;
V_279 . V_81 = V_26 -> V_81 ;
if ( F_20 ( & V_277 , 1 ) ) {
V_127 = V_88 -> V_276 ( V_118 , V_121 , & V_277 ) ;
if ( V_127 == 0 )
V_26 -> V_81 = V_279 . V_81 ;
}
} else
break;
if ( ! V_127 )
F_12 ( V_16 , L_53 , V_26 -> V_1 , V_26 -> V_81 ) ;
else
F_12 ( V_16 , L_52 , V_26 -> V_1 ) ;
break;
}
case V_132 :
{
struct V_274 * V_26 = V_119 ;
struct V_71 V_277 ;
struct V_278 V_279 ;
if ( ! V_24 -> V_267 &&
! V_88 -> V_280 && ! V_88 -> V_281 )
break;
F_12 ( V_16 , L_53 , V_26 -> V_1 , V_26 -> V_81 ) ;
if ( V_24 -> V_267 ) {
V_127 = F_35 ( V_24 -> V_267 , V_26 ) ;
break;
}
if ( V_88 -> V_280 ) {
V_127 = V_88 -> V_280 ( V_118 , V_121 , V_26 ) ;
break;
}
if ( ! V_88 -> V_281 )
break;
V_277 . V_77 = F_21 ( V_26 -> V_1 ) ;
V_277 . V_78 = 1 ;
V_277 . V_79 = & V_279 ;
V_279 . V_1 = V_26 -> V_1 ;
V_279 . V_81 = V_26 -> V_81 ;
if ( F_20 ( & V_277 , 1 ) )
V_127 = V_88 -> V_281 ( V_118 , V_121 , & V_277 ) ;
break;
}
case V_282 :
{
struct V_71 * V_26 = V_119 ;
V_26 -> V_86 = V_26 -> V_78 ;
if ( V_24 -> V_267 )
V_127 = F_36 ( V_24 -> V_267 , V_26 ) ;
else if ( V_88 -> V_276 && F_20 ( V_26 , 0 ) )
V_127 = V_88 -> V_276 ( V_118 , V_121 , V_26 ) ;
else
break;
F_19 ( V_16 , V_24 , V_26 , ! V_127 ) ;
break;
}
case V_142 :
{
struct V_71 * V_26 = V_119 ;
V_26 -> V_86 = V_26 -> V_78 ;
if ( ! V_24 -> V_267 && ! V_88 -> V_281 )
break;
F_19 ( V_16 , V_24 , V_26 , 1 ) ;
if ( V_24 -> V_267 )
V_127 = F_37 ( V_24 -> V_267 , V_26 ) ;
else if ( F_20 ( V_26 , 0 ) )
V_127 = V_88 -> V_281 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_283 :
{
struct V_71 * V_26 = V_119 ;
V_26 -> V_86 = V_26 -> V_78 ;
if ( ! V_24 -> V_267 && ! V_88 -> V_284 )
break;
F_19 ( V_16 , V_24 , V_26 , 1 ) ;
if ( V_24 -> V_267 )
V_127 = F_38 ( V_24 -> V_267 , V_26 ) ;
else if ( F_20 ( V_26 , 0 ) )
V_127 = V_88 -> V_284 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_285 :
{
struct V_286 * V_26 = V_119 ;
if ( V_24 -> V_267 )
V_127 = V_286 ( V_24 -> V_267 , V_26 ) ;
else if ( V_88 -> V_287 )
V_127 = V_88 -> V_287 ( V_118 , V_121 , V_26 ) ;
else
break;
if ( ! V_127 )
F_12 ( V_16 , L_54 ,
V_26 -> V_1 , V_26 -> V_35 , V_26 -> V_14 ) ;
else
F_12 ( V_16 , L_55 ,
V_26 -> V_1 , V_26 -> V_35 ) ;
break;
}
case V_288 :
{
struct V_289 * V_26 = V_119 ;
if ( ! V_88 -> V_290 )
break;
V_127 = V_88 -> V_290 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_56
L_57 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_222 , V_26 -> V_291 ) ;
else
F_12 ( V_16 , L_58 , V_26 -> V_35 ) ;
break;
}
case V_292 :
{
struct V_289 * V_26 = V_119 ;
if ( ! V_88 -> V_293 )
break;
V_127 = V_88 -> V_293 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_56
L_57 , V_26 -> V_35 ,
V_26 -> V_14 , V_26 -> V_222 , V_26 -> V_291 ) ;
else
F_12 ( V_16 , L_58 , V_26 -> V_35 ) ;
break;
}
case V_140 :
{
struct V_289 * V_26 = V_119 ;
if ( ! V_88 -> V_294 )
break;
F_12 ( V_16 , L_56
L_57 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_222 , V_26 -> V_291 ) ;
V_127 = V_88 -> V_294 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_295 :
{
struct V_296 * V_26 = V_119 ;
if ( ! V_88 -> V_297 )
break;
F_12 ( V_16 , L_59 , V_26 -> V_35 ) ;
V_127 = V_88 -> V_297 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_15 ( L_60
L_61 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_222 , V_26 -> V_291 ) ;
break;
}
case V_298 :
{
struct V_296 * V_26 = V_119 ;
if ( ! V_88 -> V_299 )
break;
V_127 = V_88 -> V_299 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_15 ( L_60
L_61 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_222 , V_26 -> V_291 ) ;
break;
}
case V_141 :
{
struct V_296 * V_26 = V_119 ;
if ( ! V_88 -> V_300 )
break;
F_12 ( V_16 , L_60
L_61 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_222 , V_26 -> V_291 ) ;
V_127 = V_88 -> V_300 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_301 :
{
struct V_302 * V_26 = V_119 ;
if ( ! V_88 -> V_303 )
break;
V_127 = V_88 -> V_303 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_62
L_63
L_64 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> V_222 ,
V_26 -> V_304 , V_26 -> V_305 ,
V_26 -> V_306 ) ;
break;
}
case V_148 :
{
struct V_302 * V_26 = V_119 ;
if ( ! V_88 -> V_307 )
break;
F_12 ( V_16 , L_60
L_65 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> V_222 , V_26 -> V_304 ,
V_26 -> V_305 , V_26 -> V_306 ) ;
V_127 = V_88 -> V_307 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_308 :
{
struct V_309 * V_26 = V_119 ;
if ( ! V_88 -> V_310 )
break;
F_12 ( V_16 , L_36 , F_13 ( V_26 -> type , V_36 ) ) ;
V_127 = V_88 -> V_310 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_16 ( V_24 , L_23 , & V_26 -> V_72 ) ;
break;
}
case V_139 :
{
struct V_309 * V_26 = V_119 ;
if ( ! V_88 -> V_311 )
break;
F_12 ( V_16 , L_36 , F_13 ( V_26 -> type , V_36 ) ) ;
F_16 ( V_24 , L_23 , & V_26 -> V_72 ) ;
V_127 = V_88 -> V_311 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_312 :
{
struct V_313 * V_26 = V_119 ;
if ( ! V_88 -> V_314 )
break;
F_12 ( V_16 , L_36 , F_13 ( V_26 -> type , V_36 ) ) ;
V_127 = V_88 -> V_314 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 ) {
F_16 ( V_24 , L_66 , & V_26 -> V_315 ) ;
F_16 ( V_24 , L_67 , & V_26 -> V_316 ) ;
}
break;
}
case V_317 :
{
struct V_318 * V_26 = V_119 ;
if ( ! V_88 -> V_319 )
break;
V_127 = V_88 -> V_319 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_68
L_69
L_70 ,
V_26 -> V_320 , V_26 -> V_321 , V_26 -> V_322 ,
V_26 -> V_323 , V_26 -> V_324 ) ;
break;
}
case V_147 :
{
struct V_318 * V_26 = V_119 ;
if ( ! V_88 -> V_319 )
break;
F_12 ( V_16 , L_71
L_72 ,
V_26 -> V_320 , V_26 -> V_321 , V_26 -> V_322 ,
V_26 -> V_323 , V_26 -> V_324 ) ;
V_127 = V_88 -> V_325 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_326 :
{
struct V_327 * V_26 = V_119 ;
if ( ! V_88 -> V_328 )
break;
V_127 = V_88 -> V_328 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_73 ,
V_26 -> V_329 , V_26 -> V_330 ) ;
break;
}
case V_151 :
{
struct V_331 * V_26 = V_119 ;
if ( ! V_88 -> V_332 )
break;
V_127 = V_88 -> V_332 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_74 , V_26 -> V_16 , V_26 -> V_37 ) ;
break;
}
case V_333 :
{
struct V_331 * V_26 = V_119 ;
if ( ! V_88 -> V_334 )
break;
V_127 = V_88 -> V_334 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_74 , V_26 -> V_16 , V_26 -> V_37 ) ;
break;
}
case V_335 :
{
struct V_336 * V_26 = V_119 ;
if ( V_88 -> V_337 ) {
V_127 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_127 )
break;
V_127 = V_88 -> V_337 ( V_118 , V_121 , V_26 ) ;
} else {
T_1 V_5 = V_24 -> V_236 ;
if ( V_26 -> type != V_91 )
break;
V_127 = 0 ;
if ( V_88 -> V_235 )
V_127 = V_88 -> V_235 ( V_118 , V_121 , & V_5 ) ;
else if ( V_5 == 0 )
V_127 = - V_90 ;
if ( V_127 == 0 )
F_3 ( V_5 ,
& V_26 -> V_338 . V_339 . V_340 ) ;
}
F_12 ( V_16 , L_75 , V_26 -> type ) ;
break;
}
case V_149 :
{
struct V_336 * V_26 = V_119 ;
if ( ! V_88 -> V_341 )
break;
V_127 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_127 )
break;
F_12 ( V_16 , L_75 , V_26 -> type ) ;
V_127 = V_88 -> V_341 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_342 :
{
struct V_343 * V_26 = V_119 ;
if ( ! V_88 -> V_344 )
break;
V_26 -> type = ( V_24 -> V_345 == V_346 ) ?
V_347 : V_348 ;
V_127 = V_88 -> V_344 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_45
L_76
L_77
L_78 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type ,
V_26 -> V_222 , V_26 -> V_304 ,
V_26 -> V_305 , V_26 -> signal , V_26 -> V_349 ,
V_26 -> V_350 , V_26 -> V_351 ) ;
break;
}
case V_136 :
{
struct V_343 * V_26 = V_119 ;
if ( ! V_88 -> V_352 )
break;
V_26 -> type = ( V_24 -> V_345 == V_346 ) ?
V_347 : V_348 ;
F_12 ( V_16 , L_45
L_76
L_77
L_78 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type ,
V_26 -> V_222 , V_26 -> V_304 ,
V_26 -> V_305 , V_26 -> signal , V_26 -> V_349 ,
V_26 -> V_350 , V_26 -> V_351 ) ;
V_127 = V_88 -> V_352 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_353 :
{
struct V_354 * V_26 = V_119 ;
if ( ! V_88 -> V_355 )
break;
V_26 -> type = ( V_24 -> V_345 == V_346 ) ?
V_347 : V_348 ;
V_127 = V_88 -> V_355 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_79 ,
V_26 -> V_250 , V_26 -> type , V_26 -> V_356 ) ;
break;
}
case V_137 :
{
struct V_354 * V_26 = V_119 ;
if ( ! V_88 -> V_357 )
break;
F_12 ( V_16 , L_79 ,
V_26 -> V_250 , V_26 -> type , V_26 -> V_356 ) ;
V_127 = V_88 -> V_357 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_358 :
{
struct V_359 * V_26 = V_119 ;
if ( ! V_88 -> V_360 )
break;
memset ( V_26 , 0 , F_39 ( struct V_359 , type ) ) ;
F_12 ( V_16 , L_36 , F_13 ( V_26 -> type , V_36 ) ) ;
V_127 = V_88 -> V_360 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_15 ( L_80 , V_26 -> V_361 ) ;
break;
}
case V_362 :
{
if ( ! V_88 -> V_363 )
break;
V_127 = V_88 -> V_363 ( V_118 , V_121 ) ;
break;
}
#ifdef F_40
case V_364 :
{
struct V_365 * V_26 = V_119 ;
if ( V_88 -> V_366 ) {
if ( ! F_41 ( V_367 ) )
V_127 = - V_368 ;
else
V_127 = V_88 -> V_366 ( V_118 , V_121 , V_26 ) ;
}
break;
}
case V_369 :
{
struct V_365 * V_26 = V_119 ;
if ( V_88 -> V_370 ) {
if ( ! F_41 ( V_367 ) )
V_127 = - V_368 ;
else
V_127 = V_88 -> V_370 ( V_118 , V_121 , V_26 ) ;
}
break;
}
#endif
case V_371 :
{
struct V_372 * V_26 = V_119 ;
if ( ! V_88 -> V_373 )
break;
V_26 -> V_374 = V_375 ;
V_26 -> V_376 = 0 ;
V_127 = V_88 -> V_373 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_81 , V_26 -> V_374 , V_26 -> V_376 ) ;
break;
}
case V_150 :
{
struct V_377 * V_26 = V_119 ;
enum V_378 type ;
if ( ! V_88 -> V_379 )
break;
type = ( V_24 -> V_345 == V_346 ) ?
V_347 : V_348 ;
F_12 ( V_16 ,
L_82 ,
V_26 -> V_250 , V_26 -> type , V_26 -> V_380 , V_26 -> V_381 , V_26 -> V_382 ) ;
if ( V_26 -> type != type )
V_127 = - V_90 ;
else
V_127 = V_88 -> V_379 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_383 :
{
struct V_384 * V_26 = V_119 ;
if ( ! V_88 -> V_385 )
break;
V_127 = V_88 -> V_385 ( V_118 , V_121 , V_26 ) ;
F_12 ( V_16 ,
L_83 ,
V_26 -> V_35 ,
( V_26 -> V_386 & 0xff ) ,
( V_26 -> V_386 >> 8 ) & 0xff ,
( V_26 -> V_386 >> 16 ) & 0xff ,
( V_26 -> V_386 >> 24 ) & 0xff ,
V_26 -> type ) ;
switch ( V_26 -> type ) {
case V_387 :
F_42 ( L_84 ,
V_26 -> V_388 . V_59 , V_26 -> V_388 . V_60 ) ;
break;
case V_389 :
F_42 ( L_85 ,
V_26 -> V_390 . V_391 , V_26 -> V_390 . V_392 ,
V_26 -> V_390 . V_393 , V_26 -> V_390 . V_394 ,
V_26 -> V_390 . V_395 , V_26 -> V_390 . V_396 ) ;
break;
case V_397 :
F_42 ( L_86 ) ;
break;
default:
F_42 ( L_87 ) ;
}
break;
}
case V_398 :
{
struct V_399 * V_26 = V_119 ;
if ( ! V_88 -> V_400 )
break;
V_127 = V_88 -> V_400 ( V_118 , V_121 , V_26 ) ;
F_12 ( V_16 ,
L_88 ,
V_26 -> V_35 , V_26 -> V_386 ,
V_26 -> V_59 , V_26 -> V_60 , V_26 -> type ) ;
switch ( V_26 -> type ) {
case V_401 :
F_15 ( L_89 ,
V_26 -> V_388 . V_10 ,
V_26 -> V_388 . V_11 ) ;
break;
case V_402 :
F_15 ( L_90 ,
V_26 -> V_390 . V_403 . V_10 ,
V_26 -> V_390 . V_403 . V_11 ,
V_26 -> V_390 . V_404 . V_10 ,
V_26 -> V_390 . V_404 . V_11 ,
V_26 -> V_390 . V_271 . V_10 ,
V_26 -> V_390 . V_271 . V_11 ) ;
break;
case V_405 :
F_15 ( L_86 ) ;
break;
default:
F_15 ( L_87 ) ;
}
break;
}
case V_406 :
{
struct V_407 * V_26 = V_119 ;
if ( ! V_88 -> V_408 )
break;
V_127 = V_88 -> V_408 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 ,
L_91
L_92 ,
V_26 -> V_35 , V_26 -> V_409 , V_26 -> V_14 , V_26 -> V_59 ,
V_26 -> V_60 ) ;
break;
}
case V_145 :
{
struct V_410 * V_26 = V_119 ;
if ( ! V_88 -> V_244 )
break;
F_12 ( V_16 , L_93 , V_26 -> V_409 ) ;
V_127 = V_88 -> V_244 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_411 :
{
struct V_410 * V_26 = V_119 ;
if ( ! V_88 -> V_412 )
break;
V_127 = V_88 -> V_412 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_93 , V_26 -> V_409 ) ;
break;
}
case V_413 :
{
struct V_410 * V_26 = V_119 ;
if ( ! V_88 -> V_414 )
break;
V_127 = V_88 -> V_414 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_93 , V_26 -> V_409 ) ;
break;
}
case V_146 :
{
struct V_415 * V_26 = V_119 ;
if ( ! V_88 -> V_246 )
break;
switch ( V_26 -> type ) {
case V_416 :
F_15 ( L_94
L_95
L_96
L_97
L_98
L_99 ,
V_26 -> V_417 . V_418 , V_26 -> V_417 . V_419 ,
V_26 -> V_417 . V_59 , V_26 -> V_417 . V_60 , V_26 -> V_417 . V_420 ,
V_26 -> V_417 . V_421 , V_26 -> V_417 . V_422 ,
V_26 -> V_417 . V_423 , V_26 -> V_417 . V_424 ,
V_26 -> V_417 . V_425 , V_26 -> V_417 . V_426 ,
V_26 -> V_417 . V_427 , V_26 -> V_417 . V_428 ,
V_26 -> V_417 . V_429 ) ;
V_127 = V_88 -> V_246 ( V_118 , V_121 , V_26 ) ;
break;
default:
F_15 ( L_100 , V_26 -> type ) ;
break;
}
break;
}
case V_430 :
{
struct V_415 * V_26 = V_119 ;
if ( ! V_88 -> V_431 )
break;
V_127 = V_88 -> V_431 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 ) {
switch ( V_26 -> type ) {
case V_416 :
F_15 ( L_101
L_102
L_95
L_103
L_104
L_105
L_98
L_99 ,
V_26 -> V_417 . V_418 , V_26 -> V_417 . V_419 ,
V_26 -> V_417 . V_59 , V_26 -> V_417 . V_60 ,
V_26 -> V_417 . V_420 , V_26 -> V_417 . V_421 ,
V_26 -> V_417 . V_422 , V_26 -> V_417 . V_423 ,
V_26 -> V_417 . V_424 , V_26 -> V_417 . V_425 ,
V_26 -> V_417 . V_426 , V_26 -> V_417 . V_427 ,
V_26 -> V_417 . V_428 , V_26 -> V_417 . V_429 ) ;
break;
default:
F_15 ( L_100 , V_26 -> type ) ;
break;
}
}
break;
}
case V_432 :
{
struct V_433 * V_434 = V_119 ;
if ( ! V_88 -> V_435 )
break;
V_127 = F_43 ( V_121 , V_434 , V_118 -> V_436 & V_437 ) ;
if ( V_127 < 0 ) {
F_12 ( V_16 , L_106 ) ;
break;
}
F_12 ( V_16 ,
L_107
L_108 ,
V_434 -> V_438 , V_434 -> type , V_434 -> V_39 ,
V_434 -> V_32 . V_33 , V_434 -> V_32 . V_439 ) ;
break;
}
case V_440 :
{
struct V_441 * V_442 = V_119 ;
if ( ! V_88 -> V_435 )
break;
V_127 = V_88 -> V_435 ( V_121 , V_442 ) ;
if ( V_127 < 0 ) {
F_12 ( V_16 , L_109 , V_127 ) ;
break;
}
F_12 ( V_16 , L_110 , V_442 -> type ) ;
break;
}
case V_443 :
{
struct V_441 * V_442 = V_119 ;
if ( ! V_88 -> V_444 )
break;
V_127 = V_88 -> V_444 ( V_121 , V_442 ) ;
if ( V_127 < 0 ) {
F_12 ( V_16 , L_109 , V_127 ) ;
break;
}
F_12 ( V_16 , L_110 , V_442 -> type ) ;
break;
}
default:
{
bool V_445 = true ;
if ( ! V_88 -> V_446 )
break;
if ( V_126 )
V_445 = F_29 ( V_24 -> V_156 , V_124 -> V_156 ) >= 0 ;
V_127 = V_88 -> V_446 ( V_118 , V_121 , V_445 , V_16 , V_119 ) ;
break;
}
}
V_157:
if ( V_24 -> V_74 & V_75 ) {
if ( V_127 < 0 ) {
F_27 ( V_24 -> V_14 , V_16 ) ;
F_9 ( V_76 L_111 , V_127 ) ;
}
}
return V_127 ;
}
static unsigned long F_44 ( unsigned int V_16 )
{
#define F_45 ( V_16 , type , V_38 ) \
case VIDIOC_##cmd: \
return offsetof(struct v4l2_##type, field) + \
sizeof(((struct v4l2_##type *)0)->field);
switch ( V_16 ) {
F_45 ( V_447 , V_448 , type ) ;
F_45 ( V_449 , V_450 , type ) ;
F_45 ( V_451 , V_452 , V_44 ) ;
F_45 ( V_453 , V_454 , type ) ;
F_45 ( V_455 , V_456 , V_35 ) ;
F_45 ( V_457 , V_458 , V_35 ) ;
F_45 ( V_459 , V_460 , V_1 ) ;
F_45 ( V_461 , V_250 , V_35 ) ;
F_45 ( V_462 , V_463 , V_1 ) ;
F_45 ( V_464 , V_465 , V_35 ) ;
F_45 ( V_466 , V_467 , V_35 ) ;
F_45 ( V_468 , V_261 , V_35 ) ;
F_45 ( V_469 , V_356 , V_250 ) ;
F_45 ( V_470 , V_471 , type ) ;
F_45 ( V_472 , V_473 , type ) ;
F_45 ( V_474 , V_475 , V_35 ) ;
F_45 ( V_476 , V_477 , V_35 ) ;
F_45 ( V_478 , V_479 , V_37 ) ;
F_45 ( V_480 , V_479 , V_37 ) ;
F_45 ( V_481 , V_482 , type ) ;
F_45 ( V_483 , V_484 , V_386 ) ;
F_45 ( V_485 , V_486 , V_60 ) ;
default:
return F_46 ( V_16 ) ;
}
}
static int F_47 ( unsigned int V_16 , void * V_487 , T_3 * V_488 ,
void * T_4 * V_489 , void * * * V_490 )
{
int V_127 = 0 ;
switch ( V_16 ) {
case V_212 :
case V_214 :
case V_216 : {
struct V_25 * V_491 = V_487 ;
if ( F_14 ( V_491 -> type ) && V_491 -> V_44 > 0 ) {
if ( V_491 -> V_44 > V_492 ) {
V_127 = - V_90 ;
break;
}
* V_489 = ( void T_4 * ) V_491 -> V_42 . V_43 ;
* V_490 = ( void * * ) & V_491 -> V_42 . V_43 ;
* V_488 = sizeof( struct V_30 ) * V_491 -> V_44 ;
V_127 = 1 ;
}
break;
}
case V_142 :
case V_282 :
case V_283 : {
struct V_71 * V_277 = V_487 ;
if ( V_277 -> V_78 != 0 ) {
* V_489 = ( void T_4 * ) V_277 -> V_79 ;
* V_490 = ( void * * ) & V_277 -> V_79 ;
* V_488 = sizeof( struct V_278 )
* V_277 -> V_78 ;
V_127 = 1 ;
}
break;
}
}
return V_127 ;
}
long
F_48 ( struct V_118 * V_118 , unsigned int V_16 , unsigned long V_119 ,
T_5 V_493 )
{
char V_494 [ 128 ] ;
void * V_495 = NULL ;
void * V_487 = ( void * ) V_119 ;
long V_496 = - V_90 ;
bool V_497 ;
T_3 V_488 = 0 ;
void T_4 * V_489 = NULL ;
void * * V_490 = NULL ;
if ( F_10 ( V_16 ) != V_20 ) {
if ( F_46 ( V_16 ) <= sizeof( V_494 ) ) {
V_487 = V_494 ;
} else {
V_495 = F_49 ( F_46 ( V_16 ) , V_498 ) ;
if ( NULL == V_495 )
return - V_499 ;
V_487 = V_495 ;
}
V_496 = - V_500 ;
if ( F_10 ( V_16 ) & V_22 ) {
unsigned long V_501 = F_44 ( V_16 ) ;
if ( F_50 ( V_487 , ( void T_4 * ) V_119 , V_501 ) )
goto V_502;
if ( V_501 < F_46 ( V_16 ) )
memset ( ( V_503 * ) V_487 + V_501 , 0 , F_46 ( V_16 ) - V_501 ) ;
} else {
memset ( V_487 , 0 , F_46 ( V_16 ) ) ;
}
}
V_496 = F_47 ( V_16 , V_487 , & V_488 , & V_489 , & V_490 ) ;
if ( V_496 < 0 )
goto V_502;
V_497 = V_496 ;
if ( V_497 ) {
V_495 = F_49 ( V_488 , V_498 ) ;
V_496 = - V_499 ;
if ( NULL == V_495 )
goto V_504;
V_496 = - V_500 ;
if ( F_50 ( V_495 , V_489 , V_488 ) )
goto V_504;
* V_490 = V_495 ;
}
V_496 = V_493 ( V_118 , V_16 , V_487 ) ;
if ( V_496 == - V_505 )
V_496 = - V_90 ;
if ( V_497 ) {
* V_490 = V_489 ;
if ( F_51 ( V_489 , V_495 , V_488 ) )
V_496 = - V_500 ;
goto V_504;
}
if ( V_496 < 0 )
goto V_502;
V_504:
switch ( F_10 ( V_16 ) ) {
case V_21 :
case ( V_22 | V_21 ) :
if ( F_51 ( ( void T_4 * ) V_119 , V_487 , F_46 ( V_16 ) ) )
V_496 = - V_500 ;
break;
}
V_502:
F_52 ( V_495 ) ;
return V_496 ;
}
long F_53 ( struct V_118 * V_118 ,
unsigned int V_16 , unsigned long V_119 )
{
return F_48 ( V_118 , V_16 , V_119 , F_25 ) ;
}
