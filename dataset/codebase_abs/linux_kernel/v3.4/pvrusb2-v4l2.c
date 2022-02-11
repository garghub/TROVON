static long F_1 ( struct V_1 * V_1 , unsigned int V_2 , void * V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_10 * V_11 = V_5 -> V_11 ;
struct V_12 * V_13 = V_5 -> V_14 . V_15 -> V_13 ;
long V_16 = - V_17 ;
if ( V_18 & V_19 ) {
F_2 ( F_3 ( V_13 ) , V_2 ) ;
}
if ( ! F_4 ( V_13 ) ) {
F_5 ( V_20 ,
L_1 ) ;
return - V_21 ;
}
switch ( V_2 ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
V_16 = F_6 ( & V_8 -> V_27 , V_5 -> V_27 ) ;
if ( V_16 )
return V_16 ;
}
switch ( V_2 ) {
case V_28 :
{
struct V_29 * V_30 = V_3 ;
memcpy ( V_30 , & V_31 , sizeof( struct V_29 ) ) ;
F_7 ( V_30 -> V_32 , F_8 ( V_13 ) ,
sizeof( V_30 -> V_32 ) ) ;
F_7 ( V_30 -> V_33 , F_9 ( V_13 ) , sizeof( V_30 -> V_33 ) ) ;
V_16 = 0 ;
break;
}
case V_34 :
{
enum V_35 * V_36 = V_3 ;
* V_36 = F_10 ( & V_8 -> V_27 ) ;
V_16 = 0 ;
break;
}
case V_37 :
{
enum V_35 * V_27 = V_3 ;
V_16 = F_11 ( & V_8 -> V_27 , & V_5 -> V_27 , * V_27 ) ;
break;
}
case V_38 :
{
struct V_39 * V_40 = (struct V_39 * ) V_3 ;
int V_41 = V_40 -> V_42 ;
V_16 = F_12 ( V_13 , V_40 , V_41 + 1 ) ;
break;
}
case V_43 :
{
T_1 * V_44 = V_3 ;
* V_44 = V_45 ;
V_16 = F_13 ( V_13 , V_44 ) ;
break;
}
case V_46 :
{
int V_47 = 0 ;
V_16 = F_14 (
F_15 ( V_13 , V_48 ) , & V_47 ) ;
* ( T_1 * ) V_3 = V_47 ;
break;
}
case V_23 :
{
V_16 = F_16 (
F_15 ( V_13 , V_48 ) ,
* ( T_1 * ) V_3 ) ;
break;
}
case V_49 :
{
struct V_50 * V_51 ;
struct V_52 * V_53 = (struct V_52 * ) V_3 ;
struct V_52 V_54 ;
unsigned int V_55 ;
int V_47 ;
V_51 = F_15 ( V_13 , V_56 ) ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_42 = V_53 -> V_42 ;
V_16 = 0 ;
if ( V_53 -> V_42 >= V_5 -> V_57 ) {
V_16 = - V_17 ;
break;
}
V_47 = V_5 -> V_58 [ V_53 -> V_42 ] ;
switch ( V_47 ) {
case V_59 :
case V_60 :
case V_61 :
V_54 . type = V_62 ;
break;
case V_63 :
case V_64 :
V_54 . type = V_65 ;
break;
default:
V_16 = - V_17 ;
break;
}
if ( V_16 < 0 ) break;
V_55 = 0 ;
F_17 ( V_51 , V_47 ,
V_54 . V_66 , sizeof( V_54 . V_66 ) - 1 , & V_55 ) ;
V_54 . V_66 [ V_55 ] = 0 ;
memcpy ( V_53 , & V_54 , sizeof( V_54 ) ) ;
V_16 = 0 ;
break;
}
case V_67 :
{
unsigned int V_41 ;
struct V_50 * V_51 ;
struct V_52 * V_53 = (struct V_52 * ) V_3 ;
int V_47 ;
V_51 = F_15 ( V_13 , V_56 ) ;
V_47 = 0 ;
V_16 = F_14 ( V_51 , & V_47 ) ;
V_53 -> V_42 = 0 ;
for ( V_41 = 0 ; V_41 < V_5 -> V_57 ; V_41 ++ ) {
if ( V_5 -> V_58 [ V_41 ] == V_47 ) {
V_53 -> V_42 = V_41 ;
break;
}
}
break;
}
case V_24 :
{
struct V_52 * V_53 = (struct V_52 * ) V_3 ;
if ( V_53 -> V_42 >= V_5 -> V_57 ) {
V_16 = - V_68 ;
break;
}
V_16 = F_16 (
F_15 ( V_13 , V_56 ) ,
V_5 -> V_58 [ V_53 -> V_42 ] ) ;
break;
}
case V_69 :
{
struct V_70 * V_71 = V_3 ;
V_16 = - V_17 ;
if ( V_71 -> V_42 > 0 ) break;
strncpy ( V_71 -> V_66 , L_2 , 14 ) ;
V_71 -> V_72 = V_73 ;
V_16 = 0 ;
break;
break;
}
case V_74 :
{
struct V_70 * V_71 = V_3 ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
V_71 -> V_42 = 0 ;
strncpy ( V_71 -> V_66 , L_2 , 14 ) ;
V_71 -> V_72 = V_73 ;
V_16 = 0 ;
break;
}
case V_75 :
{
struct V_76 * V_77 = (struct V_76 * ) V_3 ;
if ( V_77 -> V_42 != 0 ) break;
F_18 ( V_13 ) ;
V_16 = F_19 ( V_13 , V_77 ) ;
break;
}
case V_25 :
{
struct V_76 * V_77 = (struct V_76 * ) V_3 ;
if ( V_77 -> V_42 != 0 )
break;
V_16 = F_16 (
F_15 ( V_13 , V_78 ) ,
V_77 -> V_79 ) ;
break;
}
case V_26 :
{
const struct V_80 * V_81 = (struct V_80 * ) V_3 ;
unsigned long V_82 ;
struct V_76 V_77 ;
int V_83 ;
struct V_50 * V_84 ;
V_16 = F_19 ( V_13 , & V_77 ) ;
if ( V_16 != 0 ) break;
V_84 = F_15 ( V_13 , V_56 ) ;
V_16 = F_14 ( V_84 , & V_83 ) ;
if ( V_16 != 0 ) break;
if ( V_81 -> type == V_85 ) {
if ( V_83 != V_61 ) {
F_16 ( V_84 ,
V_61 ) ;
}
} else {
if ( V_83 == V_61 ) {
F_16 ( V_84 ,
V_59 ) ;
}
}
V_82 = V_81 -> V_86 ;
if ( V_77 . V_72 & V_87 ) {
V_82 = ( V_82 * 125 ) / 2 ;
} else {
V_82 = V_82 * 62500 ;
}
V_16 = F_16 (
F_15 ( V_13 , V_88 ) , V_82 ) ;
break;
}
case V_89 :
{
struct V_80 * V_81 = (struct V_80 * ) V_3 ;
int V_47 = 0 ;
int V_83 ;
struct V_76 V_77 ;
V_16 = F_19 ( V_13 , & V_77 ) ;
if ( V_16 != 0 ) break;
V_16 = F_14 (
F_15 ( V_13 , V_88 ) ,
& V_47 ) ;
if ( V_16 != 0 ) break;
F_14 (
F_15 ( V_13 , V_56 ) ,
& V_83 ) ;
if ( V_83 == V_61 ) {
V_81 -> type = V_85 ;
} else {
V_81 -> type = V_90 ;
}
if ( V_77 . V_72 & V_87 ) {
V_47 = ( V_47 * 2 ) / 125 ;
} else {
V_47 /= 62500 ;
}
V_81 -> V_86 = V_47 ;
break;
}
case V_91 :
{
struct V_92 * V_93 = (struct V_92 * ) V_3 ;
if ( V_93 -> V_42 != 0 )
break;
memcpy ( V_93 , V_94 , sizeof( struct V_92 ) ) ;
V_16 = 0 ;
break;
}
case V_95 :
{
struct V_96 * V_81 = (struct V_96 * ) V_3 ;
int V_47 ;
switch( V_81 -> type ) {
case V_97 :
memcpy ( V_81 , & V_98 [ V_99 ] ,
sizeof( struct V_96 ) ) ;
V_47 = 0 ;
F_14 (
F_15 ( V_13 , V_100 ) ,
& V_47 ) ;
V_81 -> V_101 . V_102 . V_103 = V_47 ;
V_47 = 0 ;
F_14 (
F_15 ( V_13 , V_104 ) ,
& V_47 ) ;
V_81 -> V_101 . V_102 . V_105 = V_47 ;
V_16 = 0 ;
break;
case V_106 :
V_16 = - V_17 ;
break;
default:
V_16 = - V_17 ;
break;
}
break;
}
case V_107 :
case V_108 :
{
struct V_96 * V_81 = (struct V_96 * ) V_3 ;
V_16 = 0 ;
switch( V_81 -> type ) {
case V_97 : {
int V_109 , V_110 , V_111 ;
struct V_50 * V_112 , * V_113 ;
int V_114 = V_81 -> V_101 . V_102 . V_105 ;
int V_115 = V_81 -> V_101 . V_102 . V_103 ;
V_112 = F_15 ( V_13 , V_100 ) ;
V_113 = F_15 ( V_13 , V_104 ) ;
V_109 = F_20 ( V_112 ) ;
V_110 = F_21 ( V_112 ) ;
F_22 ( V_112 , & V_111 ) ;
if ( V_115 == - 1 ) {
V_115 = V_111 ;
} else if ( V_115 < V_109 ) {
V_115 = V_109 ;
} else if ( V_115 > V_110 ) {
V_115 = V_110 ;
}
V_109 = F_20 ( V_113 ) ;
V_110 = F_21 ( V_113 ) ;
F_22 ( V_113 , & V_111 ) ;
if ( V_114 == - 1 ) {
V_114 = V_111 ;
} else if ( V_114 < V_109 ) {
V_114 = V_109 ;
} else if ( V_114 > V_110 ) {
V_114 = V_110 ;
}
memcpy ( V_81 , & V_98 [ V_99 ] ,
sizeof( struct V_96 ) ) ;
V_81 -> V_101 . V_102 . V_103 = V_115 ;
V_81 -> V_101 . V_102 . V_105 = V_114 ;
if ( V_2 == V_108 ) {
F_16 ( V_112 , V_81 -> V_101 . V_102 . V_103 ) ;
F_16 ( V_113 , V_81 -> V_101 . V_102 . V_105 ) ;
}
} break;
case V_106 :
V_16 = - V_17 ;
break;
default:
V_16 = - V_17 ;
break;
}
break;
}
case V_116 :
{
if ( ! V_5 -> V_11 -> V_117 ) {
V_16 = - V_118 ;
break;
}
V_16 = F_23 ( V_13 , V_11 -> V_119 ) ;
if ( V_16 < 0 ) return V_16 ;
V_16 = F_24 ( V_13 , ! 0 ) ;
break;
}
case V_120 :
{
if ( ! V_5 -> V_11 -> V_117 ) {
V_16 = - V_118 ;
break;
}
V_16 = F_24 ( V_13 , 0 ) ;
break;
}
case V_121 :
{
struct V_50 * V_51 ;
int V_47 ;
struct V_122 * V_123 = (struct V_122 * ) V_3 ;
V_16 = 0 ;
if ( V_123 -> V_124 & V_125 ) {
V_51 = F_25 (
V_13 , ( V_123 -> V_124 & ~ V_125 ) ) ;
if ( V_51 ) V_123 -> V_124 = F_26 ( V_51 ) ;
} else {
V_51 = F_27 ( V_13 , V_123 -> V_124 ) ;
}
if ( ! V_51 ) {
F_5 ( V_19 ,
L_3 ,
V_123 -> V_124 ) ;
V_16 = - V_17 ;
break;
}
F_5 ( V_19 ,
L_4 ,
V_123 -> V_124 , F_28 ( V_51 ) ,
F_29 ( V_51 ) ) ;
F_7 ( V_123 -> V_66 , F_29 ( V_51 ) , sizeof( V_123 -> V_66 ) ) ;
V_123 -> V_126 = F_30 ( V_51 ) ;
F_22 ( V_51 , & V_47 ) ;
V_123 -> V_127 = V_47 ;
switch ( F_31 ( V_51 ) ) {
case V_128 :
V_123 -> type = V_129 ;
V_123 -> V_130 = 0 ;
V_123 -> V_131 = F_32 ( V_51 ) - 1 ;
V_123 -> V_132 = 1 ;
break;
case V_133 :
V_123 -> type = V_134 ;
V_123 -> V_130 = 0 ;
V_123 -> V_131 = 1 ;
V_123 -> V_132 = 1 ;
break;
case V_135 :
V_123 -> type = V_136 ;
V_123 -> V_130 = F_20 ( V_51 ) ;
V_123 -> V_131 = F_21 ( V_51 ) ;
V_123 -> V_132 = 1 ;
break;
default:
F_5 ( V_19 ,
L_5 ,
V_123 -> V_124 , F_28 ( V_51 ) ) ;
V_16 = - V_17 ;
break;
}
break;
}
case V_137 :
{
struct V_138 * V_139 = (struct V_138 * ) V_3 ;
unsigned int V_55 = 0 ;
V_16 = F_17 ( F_27 ( V_13 , V_139 -> V_124 ) ,
V_139 -> V_42 ,
V_139 -> V_66 , sizeof( V_139 -> V_66 ) - 1 ,
& V_55 ) ;
V_139 -> V_66 [ V_55 ] = 0 ;
break;
}
case V_140 :
{
struct V_141 * V_123 = (struct V_141 * ) V_3 ;
int V_47 = 0 ;
V_16 = F_14 ( F_27 ( V_13 , V_123 -> V_124 ) ,
& V_47 ) ;
V_123 -> V_142 = V_47 ;
break;
}
case V_22 :
{
struct V_141 * V_123 = (struct V_141 * ) V_3 ;
V_16 = F_16 ( F_27 ( V_13 , V_123 -> V_124 ) ,
V_123 -> V_142 ) ;
break;
}
case V_143 :
{
struct V_144 * V_145 =
(struct V_144 * ) V_3 ;
struct V_146 * V_147 ;
unsigned int V_41 ;
int V_47 ;
V_16 = 0 ;
for ( V_41 = 0 ; V_41 < V_145 -> V_148 ; V_41 ++ ) {
V_147 = V_145 -> V_149 + V_41 ;
V_16 = F_14 (
F_27 ( V_13 , V_147 -> V_124 ) , & V_47 ) ;
if ( V_16 ) {
V_145 -> V_150 = V_41 ;
break;
}
V_147 -> V_151 = 0 ;
V_147 -> V_142 = V_47 ;
}
break;
}
case V_152 :
{
struct V_144 * V_145 =
(struct V_144 * ) V_3 ;
struct V_146 * V_147 ;
unsigned int V_41 ;
V_16 = 0 ;
for ( V_41 = 0 ; V_41 < V_145 -> V_148 ; V_41 ++ ) {
V_147 = V_145 -> V_149 + V_41 ;
V_16 = F_16 (
F_27 ( V_13 , V_147 -> V_124 ) ,
V_147 -> V_142 ) ;
if ( V_16 ) {
V_145 -> V_150 = V_41 ;
break;
}
}
break;
}
case V_153 :
{
struct V_144 * V_145 =
(struct V_144 * ) V_3 ;
struct V_146 * V_147 ;
struct V_50 * V_154 ;
unsigned int V_41 ;
V_16 = 0 ;
for ( V_41 = 0 ; V_41 < V_145 -> V_148 ; V_41 ++ ) {
V_147 = V_145 -> V_149 + V_41 ;
V_154 = F_27 ( V_13 , V_147 -> V_124 ) ;
if ( ! V_154 ) {
V_16 = - V_17 ;
V_145 -> V_150 = V_41 ;
break;
}
}
break;
}
case V_155 :
{
struct V_156 * V_30 = (struct V_156 * ) V_3 ;
if ( V_30 -> type != V_97 ) {
V_16 = - V_17 ;
break;
}
V_16 = F_33 ( V_13 , V_30 ) ;
V_30 -> type = V_97 ;
break;
}
case V_157 :
{
struct V_158 * V_159 = (struct V_158 * ) V_3 ;
int V_47 = 0 ;
if ( V_159 -> type != V_97 ) {
V_16 = - V_17 ;
break;
}
V_16 = F_14 (
F_15 ( V_13 , V_160 ) , & V_47 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
V_159 -> V_161 . V_162 = V_47 ;
V_16 = F_14 (
F_15 ( V_13 , V_163 ) , & V_47 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
V_159 -> V_161 . V_164 = V_47 ;
V_16 = F_14 (
F_15 ( V_13 , V_165 ) , & V_47 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
V_159 -> V_161 . V_103 = V_47 ;
V_16 = F_14 (
F_15 ( V_13 , V_166 ) , & V_47 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
V_159 -> V_161 . V_105 = V_47 ;
}
case V_167 :
{
struct V_158 * V_159 = (struct V_158 * ) V_3 ;
if ( V_159 -> type != V_97 ) {
V_16 = - V_17 ;
break;
}
V_16 = F_16 (
F_15 ( V_13 , V_160 ) ,
V_159 -> V_161 . V_162 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
V_16 = F_16 (
F_15 ( V_13 , V_163 ) ,
V_159 -> V_161 . V_164 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
V_16 = F_16 (
F_15 ( V_13 , V_165 ) ,
V_159 -> V_161 . V_103 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
V_16 = F_16 (
F_15 ( V_13 , V_166 ) ,
V_159 -> V_161 . V_105 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
}
case V_168 :
{
F_34 ( V_13 ) ;
V_16 = 0 ;
break;
}
#ifdef F_35
case V_169 :
case V_170 :
{
T_2 V_47 ;
struct V_171 * V_172 = (struct V_171 * ) V_3 ;
if ( V_2 == V_169 ) V_47 = V_172 -> V_47 ;
V_16 = F_36 (
V_13 , & V_172 -> V_173 , V_172 -> V_174 ,
V_2 == V_169 , & V_47 ) ;
if ( V_2 == V_170 ) V_172 -> V_47 = V_47 ;
break;
}
#endif
default :
V_16 = - V_175 ;
break;
}
F_37 ( V_13 ) ;
if ( V_16 < 0 ) {
if ( V_18 & V_19 ) {
F_5 ( V_19 ,
L_6 , V_16 ) ;
} else {
if ( V_18 & V_19 ) {
F_5 ( V_19 ,
L_6
L_7 , V_16 ) ;
F_2 ( F_3 ( V_13 ) ,
V_2 ) ;
}
}
} else {
F_5 ( V_19 ,
L_8 ,
V_16 , V_16 ) ;
}
return V_16 ;
}
static void F_38 ( struct V_10 * V_176 )
{
struct V_12 * V_13 = V_176 -> V_177 -> V_14 . V_15 -> V_13 ;
enum V_178 V_179 = V_176 -> V_119 ;
char V_180 [ 80 ] ;
unsigned int V_181 ;
V_181 = F_39 ( V_180 , sizeof( V_180 ) - 1 ,
L_9 ,
F_40 ( & V_176 -> V_182 ) ,
F_41 ( V_179 ) ) ;
V_180 [ V_181 ] = 0 ;
F_42 ( V_13 , V_176 -> V_183 , - 1 ) ;
V_176 -> V_177 = NULL ;
V_176 -> V_117 = NULL ;
F_43 ( & V_176 -> V_182 ) ;
F_44 ( V_184 L_10 , V_180 ) ;
}
static void F_45 ( struct V_10 * V_176 )
{
if ( ! V_176 ) return;
if ( ! V_176 -> V_182 . V_185 ) return;
V_176 -> V_182 . V_185 = NULL ;
F_46 ( & V_176 -> V_182 . V_186 , NULL , V_187 ) ;
}
static void F_47 ( struct V_7 * V_8 )
{
if ( V_8 -> V_188 ) {
F_38 ( V_8 -> V_188 ) ;
V_8 -> V_188 = NULL ;
}
if ( V_8 -> V_189 ) {
F_38 ( V_8 -> V_189 ) ;
V_8 -> V_189 = NULL ;
}
F_5 ( V_190 , L_11 , V_8 ) ;
F_48 ( & V_8 -> V_14 ) ;
F_49 ( V_8 ) ;
}
static void F_50 ( struct V_191 * V_192 )
{
struct V_10 * V_186 ;
V_186 = F_51 ( V_192 , struct V_10 , V_182 ) ;
F_49 ( V_186 ) ;
}
static void F_52 ( struct V_193 * V_194 )
{
struct V_7 * V_8 ;
V_8 = F_51 ( V_194 , struct V_7 , V_14 ) ;
if ( ! V_8 -> V_14 . V_15 -> V_195 ) return;
F_45 ( V_8 -> V_188 ) ;
F_45 ( V_8 -> V_189 ) ;
if ( V_8 -> V_196 ) return;
F_47 ( V_8 ) ;
}
static long F_53 ( struct V_1 * V_1 ,
unsigned int V_2 , unsigned long V_3 )
{
return F_54 ( V_1 , V_2 , V_3 , F_1 ) ;
}
static int F_55 ( struct V_1 * V_1 )
{
struct V_4 * V_197 = V_1 -> V_6 ;
struct V_7 * V_8 = V_197 -> V_9 ;
struct V_12 * V_13 = V_197 -> V_14 . V_15 -> V_13 ;
F_5 ( V_198 , L_12 ) ;
if ( V_197 -> V_199 ) {
struct V_200 * V_201 ;
F_24 ( V_13 , 0 ) ;
V_201 = F_56 ( V_197 -> V_199 ) ;
if ( V_201 ) F_57 ( V_201 , NULL , NULL ) ;
F_58 ( V_197 -> V_199 ) ;
V_197 -> V_199 = NULL ;
}
F_59 ( & V_8 -> V_27 , V_197 -> V_27 ) ;
V_1 -> V_6 = NULL ;
if ( V_197 -> V_202 ) {
V_197 -> V_202 -> V_203 = V_197 -> V_203 ;
} else {
V_8 -> V_204 = V_197 -> V_203 ;
}
if ( V_197 -> V_203 ) {
V_197 -> V_203 -> V_202 = V_197 -> V_202 ;
} else {
V_8 -> V_196 = V_197 -> V_202 ;
}
V_197 -> V_202 = NULL ;
V_197 -> V_203 = NULL ;
V_197 -> V_9 = NULL ;
F_48 ( & V_197 -> V_14 ) ;
F_5 ( V_190 ,
L_13 , V_197 ) ;
if ( V_197 -> V_58 ) {
F_49 ( V_197 -> V_58 ) ;
V_197 -> V_58 = NULL ;
}
F_49 ( V_197 ) ;
if ( V_8 -> V_14 . V_15 -> V_195 && ! V_8 -> V_196 ) {
F_47 ( V_8 ) ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_1 )
{
struct V_10 * V_176 ;
struct V_4 * V_197 ;
struct V_7 * V_8 ;
struct V_12 * V_13 ;
unsigned int V_205 = 0 ;
unsigned int V_57 , V_41 ;
int V_16 = 0 ;
V_176 = F_51 ( F_61 ( V_1 ) , struct V_10 , V_182 ) ;
V_8 = V_176 -> V_177 ;
V_13 = V_8 -> V_14 . V_13 ;
F_5 ( V_198 , L_14 ) ;
if ( ! F_4 ( V_13 ) ) {
F_5 ( V_198 ,
L_15 ) ;
return - V_206 ;
}
V_197 = F_62 ( sizeof( * V_197 ) , V_207 ) ;
if ( ! V_197 ) {
return - V_208 ;
}
F_63 ( & V_197 -> V_209 ) ;
V_197 -> V_11 = V_176 ;
F_5 ( V_190 , L_16 , V_197 ) ;
F_64 ( & V_197 -> V_14 , V_8 -> V_14 . V_15 ) ;
if ( V_176 -> V_210 == V_211 ) {
V_205 = ( 1 << V_61 ) ;
} else {
V_205 = ( ( 1 << V_61 ) |
( 1 << V_59 ) |
( 1 << V_64 ) |
( 1 << V_63 ) ) ;
}
V_16 = F_65 ( & V_197 -> V_14 , V_205 ) ;
if ( V_16 ) {
F_48 ( & V_197 -> V_14 ) ;
F_5 ( V_190 ,
L_17 ,
V_197 ) ;
F_49 ( V_197 ) ;
return V_16 ;
}
V_205 &= F_66 ( V_13 ) ;
V_57 = 0 ;
for ( V_41 = 0 ; V_41 < ( sizeof( V_205 ) << 3 ) ; V_41 ++ ) {
if ( V_205 & ( 1 << V_41 ) ) V_57 ++ ;
}
V_197 -> V_57 = V_57 ;
V_197 -> V_58 = F_62 ( V_57 , V_207 ) ;
if ( ! V_197 -> V_58 ) {
F_48 ( & V_197 -> V_14 ) ;
F_5 ( V_190 ,
L_18 ,
V_197 ) ;
F_49 ( V_197 ) ;
return - V_208 ;
}
V_57 = 0 ;
for ( V_41 = 0 ; V_41 < ( sizeof( V_205 ) << 3 ) ; V_41 ++ ) {
if ( ! ( V_205 & ( 1 << V_41 ) ) ) continue;
V_197 -> V_58 [ V_57 ++ ] = V_41 ;
}
V_197 -> V_202 = NULL ;
V_197 -> V_203 = V_8 -> V_204 ;
if ( V_8 -> V_204 ) {
V_8 -> V_204 -> V_202 = V_197 ;
} else {
V_8 -> V_196 = V_197 ;
}
V_8 -> V_204 = V_197 ;
V_197 -> V_9 = V_8 ;
V_197 -> V_1 = V_1 ;
V_1 -> V_6 = V_197 ;
F_67 ( & V_8 -> V_27 , & V_197 -> V_27 ) ;
V_197 -> V_212 = F_68 ( V_13 ) ;
return 0 ;
}
static void F_69 ( struct V_4 * V_197 )
{
F_70 ( & V_197 -> V_209 ) ;
}
static int F_71 ( struct V_4 * V_5 )
{
int V_16 ;
struct V_200 * V_201 ;
struct V_12 * V_13 ;
if ( V_5 -> V_199 ) return 0 ;
if ( ! V_5 -> V_11 -> V_117 ) {
return - V_118 ;
}
if ( ( V_16 = F_72 ( & V_5 -> V_14 ,
V_5 -> V_11 -> V_117 ) ) != 0 ) {
return V_16 ;
}
V_5 -> V_199 = F_73 ( V_5 -> V_11 -> V_117 ) ;
if ( ! V_5 -> V_199 ) {
F_72 ( & V_5 -> V_14 , NULL ) ;
return - V_208 ;
}
V_13 = V_5 -> V_14 . V_15 -> V_13 ;
V_201 = V_5 -> V_11 -> V_117 -> V_117 ;
F_57 ( V_201 , ( V_213 ) F_69 , V_5 ) ;
F_23 ( V_13 , V_5 -> V_11 -> V_119 ) ;
if ( ( V_16 = F_24 ( V_13 , ! 0 ) ) < 0 ) return V_16 ;
return F_74 ( V_5 -> V_199 , ! 0 ) ;
}
static T_3 F_75 ( struct V_1 * V_1 ,
char T_4 * V_214 , T_5 V_148 , T_6 * V_215 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
int V_16 ;
if ( V_5 -> V_212 ) {
struct V_12 * V_13 = V_5 -> V_14 . V_15 -> V_13 ;
char * V_216 ;
int V_217 , V_218 ;
int V_219 = 0 ;
unsigned int V_220 = * V_215 ;
V_216 = F_76 ( V_221 , V_207 ) ;
if ( ! V_216 ) return - V_208 ;
while ( V_148 ) {
V_217 = V_148 ;
if ( V_217 > V_221 ) V_217 = V_221 ;
V_218 = F_77 ( V_13 , V_220 , V_216 , V_217 ) ;
if ( V_218 < 0 ) {
V_219 = V_218 ;
break;
}
if ( ! V_218 ) break;
if ( F_78 ( V_214 , V_216 , V_218 ) ) {
V_219 = - V_21 ;
break;
}
V_220 += V_218 ;
V_219 += V_218 ;
V_214 += V_218 ;
V_148 -= V_218 ;
* V_215 += V_218 ;
}
F_49 ( V_216 ) ;
return V_219 ;
}
if ( ! V_5 -> V_199 ) {
V_16 = F_71 ( V_5 ) ;
if ( V_16 ) {
return V_16 ;
}
}
for (; ; ) {
V_16 = F_79 ( V_5 -> V_199 , V_214 , V_148 ) ;
if ( V_16 >= 0 ) break;
if ( V_16 != - V_222 ) break;
if ( V_1 -> V_223 & V_224 ) break;
V_16 = F_80 (
V_5 -> V_209 ,
F_81 ( V_5 -> V_199 ) >= 0 ) ;
if ( V_16 < 0 ) break;
}
return V_16 ;
}
static unsigned int F_82 ( struct V_1 * V_1 , T_7 * V_225 )
{
unsigned int V_226 = 0 ;
struct V_4 * V_5 = V_1 -> V_6 ;
int V_16 ;
if ( V_5 -> V_212 ) {
V_226 |= V_227 | V_228 ;
return V_226 ;
}
if ( ! V_5 -> V_199 ) {
V_16 = F_71 ( V_5 ) ;
if ( V_16 ) return V_229 ;
}
F_83 ( V_1 , & V_5 -> V_209 , V_225 ) ;
if ( F_81 ( V_5 -> V_199 ) >= 0 ) {
V_226 |= V_227 | V_228 ;
}
return V_226 ;
}
static void F_84 ( struct V_10 * V_176 ,
struct V_7 * V_8 ,
int V_210 )
{
struct V_230 * V_231 ;
int V_232 ;
int V_233 ;
int * V_234 = NULL ;
V_176 -> V_177 = V_8 ;
V_231 = F_85 ( V_8 -> V_14 . V_15 -> V_13 ) ;
V_176 -> V_210 = V_210 ;
switch ( V_210 ) {
case V_235 :
V_176 -> V_117 = & V_8 -> V_14 . V_15 -> V_236 ;
V_176 -> V_119 = V_237 ;
V_176 -> V_183 = V_238 ;
V_234 = V_239 ;
if ( ! V_176 -> V_117 ) {
F_86 ( V_240
L_19
L_20 ) ;
return;
}
break;
case V_241 :
V_176 -> V_119 = V_242 ;
V_176 -> V_183 = V_243 ;
V_234 = V_244 ;
break;
case V_211 :
V_176 -> V_117 = & V_8 -> V_14 . V_15 -> V_236 ;
V_176 -> V_119 = V_237 ;
V_176 -> V_183 = V_245 ;
V_234 = V_246 ;
break;
default:
F_86 ( V_240 L_21
L_22 ) ;
return;
}
memcpy ( & V_176 -> V_182 , & V_247 , sizeof( V_247 ) ) ;
V_176 -> V_182 . V_248 = F_50 ;
V_232 = - 1 ;
V_233 = F_87 ( V_8 -> V_14 . V_15 -> V_13 ) ;
if ( V_234 && ( V_233 >= 0 ) && ( V_233 < V_249 ) ) {
V_232 = V_234 [ V_233 ] ;
}
V_176 -> V_182 . V_185 = & V_231 -> V_186 ;
if ( ( F_88 ( & V_176 -> V_182 ,
V_176 -> V_210 , V_232 ) < 0 ) &&
( F_88 ( & V_176 -> V_182 ,
V_176 -> V_210 , - 1 ) < 0 ) ) {
F_86 ( V_240
L_23 ) ;
}
F_44 ( V_184 L_24 ,
F_40 ( & V_176 -> V_182 ) ,
F_41 ( V_176 -> V_119 ) ) ;
F_42 ( V_8 -> V_14 . V_15 -> V_13 ,
V_176 -> V_183 , V_176 -> V_182 . V_250 ) ;
}
struct V_7 * F_89 ( struct V_251 * V_252 )
{
struct V_7 * V_8 ;
V_8 = F_62 ( sizeof( * V_8 ) , V_207 ) ;
if ( ! V_8 ) return V_8 ;
F_64 ( & V_8 -> V_14 , V_252 ) ;
F_5 ( V_190 , L_25 , V_8 ) ;
V_8 -> V_14 . V_253 = F_52 ;
V_8 -> V_188 = F_62 ( sizeof( * V_8 -> V_188 ) , V_207 ) ;
if ( ! V_8 -> V_188 ) goto V_254;
F_84 ( V_8 -> V_188 , V_8 , V_235 ) ;
if ( F_66 ( V_8 -> V_14 . V_15 -> V_13 ) &
( 1 << V_61 ) ) {
V_8 -> V_189 = F_62 ( sizeof( * V_8 -> V_189 ) , V_207 ) ;
if ( ! V_8 -> V_189 ) goto V_254;
F_84 ( V_8 -> V_189 , V_8 , V_211 ) ;
}
return V_8 ;
V_254:
F_5 ( V_190 , L_26 , V_8 ) ;
F_47 ( V_8 ) ;
return NULL ;
}
