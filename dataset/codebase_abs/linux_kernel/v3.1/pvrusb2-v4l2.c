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
int V_44 = 0 ;
V_16 = F_13 (
F_14 ( V_13 , V_45 ) , & V_44 ) ;
* ( V_46 * ) V_3 = V_44 ;
break;
}
case V_23 :
{
V_16 = F_15 (
F_14 ( V_13 , V_45 ) ,
* ( V_46 * ) V_3 ) ;
break;
}
case V_47 :
{
struct V_48 * V_49 ;
struct V_50 * V_51 = (struct V_50 * ) V_3 ;
struct V_50 V_52 ;
unsigned int V_53 ;
int V_44 ;
V_49 = F_14 ( V_13 , V_54 ) ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_42 = V_51 -> V_42 ;
V_16 = 0 ;
if ( V_51 -> V_42 >= V_5 -> V_55 ) {
V_16 = - V_17 ;
break;
}
V_44 = V_5 -> V_56 [ V_51 -> V_42 ] ;
switch ( V_44 ) {
case V_57 :
case V_58 :
case V_59 :
V_52 . type = V_60 ;
break;
case V_61 :
case V_62 :
V_52 . type = V_63 ;
break;
default:
V_16 = - V_17 ;
break;
}
if ( V_16 < 0 ) break;
V_53 = 0 ;
F_16 ( V_49 , V_44 ,
V_52 . V_64 , sizeof( V_52 . V_64 ) - 1 , & V_53 ) ;
V_52 . V_64 [ V_53 ] = 0 ;
memcpy ( V_51 , & V_52 , sizeof( V_52 ) ) ;
V_16 = 0 ;
break;
}
case V_65 :
{
unsigned int V_41 ;
struct V_48 * V_49 ;
struct V_50 * V_51 = (struct V_50 * ) V_3 ;
int V_44 ;
V_49 = F_14 ( V_13 , V_54 ) ;
V_44 = 0 ;
V_16 = F_13 ( V_49 , & V_44 ) ;
V_51 -> V_42 = 0 ;
for ( V_41 = 0 ; V_41 < V_5 -> V_55 ; V_41 ++ ) {
if ( V_5 -> V_56 [ V_41 ] == V_44 ) {
V_51 -> V_42 = V_41 ;
break;
}
}
break;
}
case V_24 :
{
struct V_50 * V_51 = (struct V_50 * ) V_3 ;
if ( V_51 -> V_42 >= V_5 -> V_55 ) {
V_16 = - V_66 ;
break;
}
V_16 = F_15 (
F_14 ( V_13 , V_54 ) ,
V_5 -> V_56 [ V_51 -> V_42 ] ) ;
break;
}
case V_67 :
{
struct V_68 * V_69 = V_3 ;
V_16 = - V_17 ;
if ( V_69 -> V_42 > 0 ) break;
strncpy ( V_69 -> V_64 , L_2 , 14 ) ;
V_69 -> V_70 = V_71 ;
V_16 = 0 ;
break;
break;
}
case V_72 :
{
struct V_68 * V_69 = V_3 ;
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
V_69 -> V_42 = 0 ;
strncpy ( V_69 -> V_64 , L_2 , 14 ) ;
V_69 -> V_70 = V_71 ;
V_16 = 0 ;
break;
}
case V_73 :
{
struct V_74 * V_75 = (struct V_74 * ) V_3 ;
if ( V_75 -> V_42 != 0 ) break;
F_17 ( V_13 ) ;
V_16 = F_18 ( V_13 , V_75 ) ;
break;
}
case V_25 :
{
struct V_74 * V_75 = (struct V_74 * ) V_3 ;
if ( V_75 -> V_42 != 0 )
break;
V_16 = F_15 (
F_14 ( V_13 , V_76 ) ,
V_75 -> V_77 ) ;
break;
}
case V_26 :
{
const struct V_78 * V_79 = (struct V_78 * ) V_3 ;
unsigned long V_80 ;
struct V_74 V_75 ;
int V_81 ;
struct V_48 * V_82 ;
V_16 = F_18 ( V_13 , & V_75 ) ;
if ( V_16 != 0 ) break;
V_82 = F_14 ( V_13 , V_54 ) ;
V_16 = F_13 ( V_82 , & V_81 ) ;
if ( V_16 != 0 ) break;
if ( V_79 -> type == V_83 ) {
if ( V_81 != V_59 ) {
F_15 ( V_82 ,
V_59 ) ;
}
} else {
if ( V_81 == V_59 ) {
F_15 ( V_82 ,
V_57 ) ;
}
}
V_80 = V_79 -> V_84 ;
if ( V_75 . V_70 & V_85 ) {
V_80 = ( V_80 * 125 ) / 2 ;
} else {
V_80 = V_80 * 62500 ;
}
V_16 = F_15 (
F_14 ( V_13 , V_86 ) , V_80 ) ;
break;
}
case V_87 :
{
struct V_78 * V_79 = (struct V_78 * ) V_3 ;
int V_44 = 0 ;
int V_81 ;
struct V_74 V_75 ;
V_16 = F_18 ( V_13 , & V_75 ) ;
if ( V_16 != 0 ) break;
V_16 = F_13 (
F_14 ( V_13 , V_86 ) ,
& V_44 ) ;
if ( V_16 != 0 ) break;
F_13 (
F_14 ( V_13 , V_54 ) ,
& V_81 ) ;
if ( V_81 == V_59 ) {
V_79 -> type = V_83 ;
} else {
V_79 -> type = V_88 ;
}
if ( V_75 . V_70 & V_85 ) {
V_44 = ( V_44 * 2 ) / 125 ;
} else {
V_44 /= 62500 ;
}
V_79 -> V_84 = V_44 ;
break;
}
case V_89 :
{
struct V_90 * V_91 = (struct V_90 * ) V_3 ;
if ( V_91 -> V_42 != 0 )
break;
memcpy ( V_91 , V_92 , sizeof( struct V_90 ) ) ;
V_16 = 0 ;
break;
}
case V_93 :
{
struct V_94 * V_79 = (struct V_94 * ) V_3 ;
int V_44 ;
switch( V_79 -> type ) {
case V_95 :
memcpy ( V_79 , & V_96 [ V_97 ] ,
sizeof( struct V_94 ) ) ;
V_44 = 0 ;
F_13 (
F_14 ( V_13 , V_98 ) ,
& V_44 ) ;
V_79 -> V_99 . V_100 . V_101 = V_44 ;
V_44 = 0 ;
F_13 (
F_14 ( V_13 , V_102 ) ,
& V_44 ) ;
V_79 -> V_99 . V_100 . V_103 = V_44 ;
V_16 = 0 ;
break;
case V_104 :
V_16 = - V_17 ;
break;
default:
V_16 = - V_17 ;
break;
}
break;
}
case V_105 :
case V_106 :
{
struct V_94 * V_79 = (struct V_94 * ) V_3 ;
V_16 = 0 ;
switch( V_79 -> type ) {
case V_95 : {
int V_107 , V_108 , V_109 ;
struct V_48 * V_110 , * V_111 ;
int V_112 = V_79 -> V_99 . V_100 . V_103 ;
int V_113 = V_79 -> V_99 . V_100 . V_101 ;
V_110 = F_14 ( V_13 , V_98 ) ;
V_111 = F_14 ( V_13 , V_102 ) ;
V_107 = F_19 ( V_110 ) ;
V_108 = F_20 ( V_110 ) ;
F_21 ( V_110 , & V_109 ) ;
if ( V_113 == - 1 ) {
V_113 = V_109 ;
} else if ( V_113 < V_107 ) {
V_113 = V_107 ;
} else if ( V_113 > V_108 ) {
V_113 = V_108 ;
}
V_107 = F_19 ( V_111 ) ;
V_108 = F_20 ( V_111 ) ;
F_21 ( V_111 , & V_109 ) ;
if ( V_112 == - 1 ) {
V_112 = V_109 ;
} else if ( V_112 < V_107 ) {
V_112 = V_107 ;
} else if ( V_112 > V_108 ) {
V_112 = V_108 ;
}
memcpy ( V_79 , & V_96 [ V_97 ] ,
sizeof( struct V_94 ) ) ;
V_79 -> V_99 . V_100 . V_101 = V_113 ;
V_79 -> V_99 . V_100 . V_103 = V_112 ;
if ( V_2 == V_106 ) {
F_15 ( V_110 , V_79 -> V_99 . V_100 . V_101 ) ;
F_15 ( V_111 , V_79 -> V_99 . V_100 . V_103 ) ;
}
} break;
case V_104 :
V_16 = - V_17 ;
break;
default:
V_16 = - V_17 ;
break;
}
break;
}
case V_114 :
{
if ( ! V_5 -> V_11 -> V_115 ) {
V_16 = - V_116 ;
break;
}
V_16 = F_22 ( V_13 , V_11 -> V_117 ) ;
if ( V_16 < 0 ) return V_16 ;
V_16 = F_23 ( V_13 , ! 0 ) ;
break;
}
case V_118 :
{
if ( ! V_5 -> V_11 -> V_115 ) {
V_16 = - V_116 ;
break;
}
V_16 = F_23 ( V_13 , 0 ) ;
break;
}
case V_119 :
{
struct V_48 * V_49 ;
int V_44 ;
struct V_120 * V_121 = (struct V_120 * ) V_3 ;
V_16 = 0 ;
if ( V_121 -> V_122 & V_123 ) {
V_49 = F_24 (
V_13 , ( V_121 -> V_122 & ~ V_123 ) ) ;
if ( V_49 ) V_121 -> V_122 = F_25 ( V_49 ) ;
} else {
V_49 = F_26 ( V_13 , V_121 -> V_122 ) ;
}
if ( ! V_49 ) {
F_5 ( V_19 ,
L_3 ,
V_121 -> V_122 ) ;
V_16 = - V_17 ;
break;
}
F_5 ( V_19 ,
L_4 ,
V_121 -> V_122 , F_27 ( V_49 ) ,
F_28 ( V_49 ) ) ;
F_7 ( V_121 -> V_64 , F_28 ( V_49 ) , sizeof( V_121 -> V_64 ) ) ;
V_121 -> V_124 = F_29 ( V_49 ) ;
F_21 ( V_49 , & V_44 ) ;
V_121 -> V_125 = V_44 ;
switch ( F_30 ( V_49 ) ) {
case V_126 :
V_121 -> type = V_127 ;
V_121 -> V_128 = 0 ;
V_121 -> V_129 = F_31 ( V_49 ) - 1 ;
V_121 -> V_130 = 1 ;
break;
case V_131 :
V_121 -> type = V_132 ;
V_121 -> V_128 = 0 ;
V_121 -> V_129 = 1 ;
V_121 -> V_130 = 1 ;
break;
case V_133 :
V_121 -> type = V_134 ;
V_121 -> V_128 = F_19 ( V_49 ) ;
V_121 -> V_129 = F_20 ( V_49 ) ;
V_121 -> V_130 = 1 ;
break;
default:
F_5 ( V_19 ,
L_5 ,
V_121 -> V_122 , F_27 ( V_49 ) ) ;
V_16 = - V_17 ;
break;
}
break;
}
case V_135 :
{
struct V_136 * V_137 = (struct V_136 * ) V_3 ;
unsigned int V_53 = 0 ;
V_16 = F_16 ( F_26 ( V_13 , V_137 -> V_122 ) ,
V_137 -> V_42 ,
V_137 -> V_64 , sizeof( V_137 -> V_64 ) - 1 ,
& V_53 ) ;
V_137 -> V_64 [ V_53 ] = 0 ;
break;
}
case V_138 :
{
struct V_139 * V_121 = (struct V_139 * ) V_3 ;
int V_44 = 0 ;
V_16 = F_13 ( F_26 ( V_13 , V_121 -> V_122 ) ,
& V_44 ) ;
V_121 -> V_140 = V_44 ;
break;
}
case V_22 :
{
struct V_139 * V_121 = (struct V_139 * ) V_3 ;
V_16 = F_15 ( F_26 ( V_13 , V_121 -> V_122 ) ,
V_121 -> V_140 ) ;
break;
}
case V_141 :
{
struct V_142 * V_143 =
(struct V_142 * ) V_3 ;
struct V_144 * V_145 ;
unsigned int V_41 ;
int V_44 ;
V_16 = 0 ;
for ( V_41 = 0 ; V_41 < V_143 -> V_146 ; V_41 ++ ) {
V_145 = V_143 -> V_147 + V_41 ;
V_16 = F_13 (
F_26 ( V_13 , V_145 -> V_122 ) , & V_44 ) ;
if ( V_16 ) {
V_143 -> V_148 = V_41 ;
break;
}
V_145 -> V_149 = 0 ;
V_145 -> V_140 = V_44 ;
}
break;
}
case V_150 :
{
struct V_142 * V_143 =
(struct V_142 * ) V_3 ;
struct V_144 * V_145 ;
unsigned int V_41 ;
V_16 = 0 ;
for ( V_41 = 0 ; V_41 < V_143 -> V_146 ; V_41 ++ ) {
V_145 = V_143 -> V_147 + V_41 ;
V_16 = F_15 (
F_26 ( V_13 , V_145 -> V_122 ) ,
V_145 -> V_140 ) ;
if ( V_16 ) {
V_143 -> V_148 = V_41 ;
break;
}
}
break;
}
case V_151 :
{
struct V_142 * V_143 =
(struct V_142 * ) V_3 ;
struct V_144 * V_145 ;
struct V_48 * V_152 ;
unsigned int V_41 ;
V_16 = 0 ;
for ( V_41 = 0 ; V_41 < V_143 -> V_146 ; V_41 ++ ) {
V_145 = V_143 -> V_147 + V_41 ;
V_152 = F_26 ( V_13 , V_145 -> V_122 ) ;
if ( ! V_152 ) {
V_16 = - V_17 ;
V_143 -> V_148 = V_41 ;
break;
}
}
break;
}
case V_153 :
{
struct V_154 * V_30 = (struct V_154 * ) V_3 ;
if ( V_30 -> type != V_95 ) {
V_16 = - V_17 ;
break;
}
V_16 = F_32 ( V_13 , V_30 ) ;
V_30 -> type = V_95 ;
break;
}
case V_155 :
{
struct V_156 * V_157 = (struct V_156 * ) V_3 ;
int V_44 = 0 ;
if ( V_157 -> type != V_95 ) {
V_16 = - V_17 ;
break;
}
V_16 = F_13 (
F_14 ( V_13 , V_158 ) , & V_44 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
V_157 -> V_159 . V_160 = V_44 ;
V_16 = F_13 (
F_14 ( V_13 , V_161 ) , & V_44 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
V_157 -> V_159 . V_162 = V_44 ;
V_16 = F_13 (
F_14 ( V_13 , V_163 ) , & V_44 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
V_157 -> V_159 . V_101 = V_44 ;
V_16 = F_13 (
F_14 ( V_13 , V_164 ) , & V_44 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
V_157 -> V_159 . V_103 = V_44 ;
}
case V_165 :
{
struct V_156 * V_157 = (struct V_156 * ) V_3 ;
if ( V_157 -> type != V_95 ) {
V_16 = - V_17 ;
break;
}
V_16 = F_15 (
F_14 ( V_13 , V_158 ) ,
V_157 -> V_159 . V_160 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
V_16 = F_15 (
F_14 ( V_13 , V_161 ) ,
V_157 -> V_159 . V_162 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
V_16 = F_15 (
F_14 ( V_13 , V_163 ) ,
V_157 -> V_159 . V_101 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
V_16 = F_15 (
F_14 ( V_13 , V_164 ) ,
V_157 -> V_159 . V_103 ) ;
if ( V_16 != 0 ) {
V_16 = - V_17 ;
break;
}
}
case V_166 :
{
F_33 ( V_13 ) ;
V_16 = 0 ;
break;
}
#ifdef F_34
case V_167 :
case V_168 :
{
T_1 V_44 ;
struct V_169 * V_170 = (struct V_169 * ) V_3 ;
if ( V_2 == V_167 ) V_44 = V_170 -> V_44 ;
V_16 = F_35 (
V_13 , & V_170 -> V_171 , V_170 -> V_172 ,
V_2 == V_167 , & V_44 ) ;
if ( V_2 == V_168 ) V_170 -> V_44 = V_44 ;
break;
}
#endif
default :
V_16 = - V_173 ;
break;
}
F_36 ( V_13 ) ;
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
static void F_37 ( struct V_10 * V_174 )
{
struct V_12 * V_13 = V_174 -> V_175 -> V_14 . V_15 -> V_13 ;
enum V_176 V_177 = V_174 -> V_117 ;
char V_178 [ 80 ] ;
unsigned int V_179 ;
V_179 = F_38 ( V_178 , sizeof( V_178 ) - 1 ,
L_9 ,
F_39 ( & V_174 -> V_180 ) ,
F_40 ( V_177 ) ) ;
V_178 [ V_179 ] = 0 ;
F_41 ( V_13 , V_174 -> V_181 , - 1 ) ;
V_174 -> V_175 = NULL ;
V_174 -> V_115 = NULL ;
F_42 ( & V_174 -> V_180 ) ;
F_43 ( V_182 L_10 , V_178 ) ;
}
static void F_44 ( struct V_10 * V_174 )
{
if ( ! V_174 ) return;
if ( ! V_174 -> V_180 . V_183 ) return;
V_174 -> V_180 . V_183 = NULL ;
F_45 ( & V_174 -> V_180 . V_184 , NULL , V_185 ) ;
}
static void F_46 ( struct V_7 * V_8 )
{
if ( V_8 -> V_186 ) {
F_37 ( V_8 -> V_186 ) ;
V_8 -> V_186 = NULL ;
}
if ( V_8 -> V_187 ) {
F_37 ( V_8 -> V_187 ) ;
V_8 -> V_187 = NULL ;
}
F_5 ( V_188 , L_11 , V_8 ) ;
F_47 ( & V_8 -> V_14 ) ;
F_48 ( V_8 ) ;
}
static void F_49 ( struct V_189 * V_190 )
{
struct V_10 * V_184 ;
V_184 = F_50 ( V_190 , struct V_10 , V_180 ) ;
F_48 ( V_184 ) ;
}
static void F_51 ( struct V_191 * V_192 )
{
struct V_7 * V_8 ;
V_8 = F_50 ( V_192 , struct V_7 , V_14 ) ;
if ( ! V_8 -> V_14 . V_15 -> V_193 ) return;
F_44 ( V_8 -> V_186 ) ;
F_44 ( V_8 -> V_187 ) ;
if ( V_8 -> V_194 ) return;
F_46 ( V_8 ) ;
}
static long F_52 ( struct V_1 * V_1 ,
unsigned int V_2 , unsigned long V_3 )
{
return F_53 ( V_1 , V_2 , V_3 , F_1 ) ;
}
static int F_54 ( struct V_1 * V_1 )
{
struct V_4 * V_195 = V_1 -> V_6 ;
struct V_7 * V_8 = V_195 -> V_9 ;
struct V_12 * V_13 = V_195 -> V_14 . V_15 -> V_13 ;
F_5 ( V_196 , L_12 ) ;
if ( V_195 -> V_197 ) {
struct V_198 * V_199 ;
F_23 ( V_13 , 0 ) ;
V_199 = F_55 ( V_195 -> V_197 ) ;
if ( V_199 ) F_56 ( V_199 , NULL , NULL ) ;
F_57 ( V_195 -> V_197 ) ;
V_195 -> V_197 = NULL ;
}
F_58 ( & V_8 -> V_27 , V_195 -> V_27 ) ;
V_1 -> V_6 = NULL ;
if ( V_195 -> V_200 ) {
V_195 -> V_200 -> V_201 = V_195 -> V_201 ;
} else {
V_8 -> V_202 = V_195 -> V_201 ;
}
if ( V_195 -> V_201 ) {
V_195 -> V_201 -> V_200 = V_195 -> V_200 ;
} else {
V_8 -> V_194 = V_195 -> V_200 ;
}
V_195 -> V_200 = NULL ;
V_195 -> V_201 = NULL ;
V_195 -> V_9 = NULL ;
F_47 ( & V_195 -> V_14 ) ;
F_5 ( V_188 ,
L_13 , V_195 ) ;
if ( V_195 -> V_56 ) {
F_48 ( V_195 -> V_56 ) ;
V_195 -> V_56 = NULL ;
}
F_48 ( V_195 ) ;
if ( V_8 -> V_14 . V_15 -> V_193 && ! V_8 -> V_194 ) {
F_46 ( V_8 ) ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_1 )
{
struct V_10 * V_174 ;
struct V_4 * V_195 ;
struct V_7 * V_8 ;
struct V_12 * V_13 ;
unsigned int V_203 = 0 ;
unsigned int V_55 , V_41 ;
int V_16 = 0 ;
V_174 = F_50 ( F_60 ( V_1 ) , struct V_10 , V_180 ) ;
V_8 = V_174 -> V_175 ;
V_13 = V_8 -> V_14 . V_13 ;
F_5 ( V_196 , L_14 ) ;
if ( ! F_4 ( V_13 ) ) {
F_5 ( V_196 ,
L_15 ) ;
return - V_204 ;
}
V_195 = F_61 ( sizeof( * V_195 ) , V_205 ) ;
if ( ! V_195 ) {
return - V_206 ;
}
F_62 ( & V_195 -> V_207 ) ;
V_195 -> V_11 = V_174 ;
F_5 ( V_188 , L_16 , V_195 ) ;
F_63 ( & V_195 -> V_14 , V_8 -> V_14 . V_15 ) ;
if ( V_174 -> V_208 == V_209 ) {
V_203 = ( 1 << V_59 ) ;
} else {
V_203 = ( ( 1 << V_59 ) |
( 1 << V_57 ) |
( 1 << V_62 ) |
( 1 << V_61 ) ) ;
}
V_16 = F_64 ( & V_195 -> V_14 , V_203 ) ;
if ( V_16 ) {
F_47 ( & V_195 -> V_14 ) ;
F_5 ( V_188 ,
L_17 ,
V_195 ) ;
F_48 ( V_195 ) ;
return V_16 ;
}
V_203 &= F_65 ( V_13 ) ;
V_55 = 0 ;
for ( V_41 = 0 ; V_41 < ( sizeof( V_203 ) << 3 ) ; V_41 ++ ) {
if ( V_203 & ( 1 << V_41 ) ) V_55 ++ ;
}
V_195 -> V_55 = V_55 ;
V_195 -> V_56 = F_61 ( V_55 , V_205 ) ;
if ( ! V_195 -> V_56 ) {
F_47 ( & V_195 -> V_14 ) ;
F_5 ( V_188 ,
L_18 ,
V_195 ) ;
F_48 ( V_195 ) ;
return - V_206 ;
}
V_55 = 0 ;
for ( V_41 = 0 ; V_41 < ( sizeof( V_203 ) << 3 ) ; V_41 ++ ) {
if ( ! ( V_203 & ( 1 << V_41 ) ) ) continue;
V_195 -> V_56 [ V_55 ++ ] = V_41 ;
}
V_195 -> V_200 = NULL ;
V_195 -> V_201 = V_8 -> V_202 ;
if ( V_8 -> V_202 ) {
V_8 -> V_202 -> V_200 = V_195 ;
} else {
V_8 -> V_194 = V_195 ;
}
V_8 -> V_202 = V_195 ;
V_195 -> V_9 = V_8 ;
V_195 -> V_1 = V_1 ;
V_1 -> V_6 = V_195 ;
F_66 ( & V_8 -> V_27 , & V_195 -> V_27 ) ;
V_195 -> V_210 = F_67 ( V_13 ) ;
return 0 ;
}
static void F_68 ( struct V_4 * V_195 )
{
F_69 ( & V_195 -> V_207 ) ;
}
static int F_70 ( struct V_4 * V_5 )
{
int V_16 ;
struct V_198 * V_199 ;
struct V_12 * V_13 ;
if ( V_5 -> V_197 ) return 0 ;
if ( ! V_5 -> V_11 -> V_115 ) {
return - V_116 ;
}
if ( ( V_16 = F_71 ( & V_5 -> V_14 ,
V_5 -> V_11 -> V_115 ) ) != 0 ) {
return V_16 ;
}
V_5 -> V_197 = F_72 ( V_5 -> V_11 -> V_115 ) ;
if ( ! V_5 -> V_197 ) {
F_71 ( & V_5 -> V_14 , NULL ) ;
return - V_206 ;
}
V_13 = V_5 -> V_14 . V_15 -> V_13 ;
V_199 = V_5 -> V_11 -> V_115 -> V_115 ;
F_56 ( V_199 , ( V_211 ) F_68 , V_5 ) ;
F_22 ( V_13 , V_5 -> V_11 -> V_117 ) ;
if ( ( V_16 = F_23 ( V_13 , ! 0 ) ) < 0 ) return V_16 ;
return F_73 ( V_5 -> V_197 , ! 0 ) ;
}
static T_2 F_74 ( struct V_1 * V_1 ,
char T_3 * V_212 , T_4 V_146 , T_5 * V_213 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
int V_16 ;
if ( V_5 -> V_210 ) {
struct V_12 * V_13 = V_5 -> V_14 . V_15 -> V_13 ;
char * V_214 ;
int V_215 , V_216 ;
int V_217 = 0 ;
unsigned int V_218 = * V_213 ;
V_214 = F_75 ( V_219 , V_205 ) ;
if ( ! V_214 ) return - V_206 ;
while ( V_146 ) {
V_215 = V_146 ;
if ( V_215 > V_219 ) V_215 = V_219 ;
V_216 = F_76 ( V_13 , V_218 , V_214 , V_215 ) ;
if ( V_216 < 0 ) {
V_217 = V_216 ;
break;
}
if ( ! V_216 ) break;
if ( F_77 ( V_212 , V_214 , V_216 ) ) {
V_217 = - V_21 ;
break;
}
V_218 += V_216 ;
V_217 += V_216 ;
V_212 += V_216 ;
V_146 -= V_216 ;
* V_213 += V_216 ;
}
F_48 ( V_214 ) ;
return V_217 ;
}
if ( ! V_5 -> V_197 ) {
V_16 = F_70 ( V_5 ) ;
if ( V_16 ) {
return V_16 ;
}
}
for (; ; ) {
V_16 = F_78 ( V_5 -> V_197 , V_212 , V_146 ) ;
if ( V_16 >= 0 ) break;
if ( V_16 != - V_220 ) break;
if ( V_1 -> V_221 & V_222 ) break;
V_16 = F_79 (
V_5 -> V_207 ,
F_80 ( V_5 -> V_197 ) >= 0 ) ;
if ( V_16 < 0 ) break;
}
return V_16 ;
}
static unsigned int F_81 ( struct V_1 * V_1 , T_6 * V_223 )
{
unsigned int V_224 = 0 ;
struct V_4 * V_5 = V_1 -> V_6 ;
int V_16 ;
if ( V_5 -> V_210 ) {
V_224 |= V_225 | V_226 ;
return V_224 ;
}
if ( ! V_5 -> V_197 ) {
V_16 = F_70 ( V_5 ) ;
if ( V_16 ) return V_227 ;
}
F_82 ( V_1 , & V_5 -> V_207 , V_223 ) ;
if ( F_80 ( V_5 -> V_197 ) >= 0 ) {
V_224 |= V_225 | V_226 ;
}
return V_224 ;
}
static void F_83 ( struct V_10 * V_174 ,
struct V_7 * V_8 ,
int V_208 )
{
struct V_228 * V_229 ;
int V_230 ;
int V_231 ;
int * V_232 = NULL ;
V_174 -> V_175 = V_8 ;
V_229 = F_84 ( V_8 -> V_14 . V_15 -> V_13 ) ;
V_174 -> V_208 = V_208 ;
switch ( V_208 ) {
case V_233 :
V_174 -> V_115 = & V_8 -> V_14 . V_15 -> V_234 ;
V_174 -> V_117 = V_235 ;
V_174 -> V_181 = V_236 ;
V_232 = V_237 ;
if ( ! V_174 -> V_115 ) {
F_85 ( V_238
L_19
L_20 ) ;
return;
}
break;
case V_239 :
V_174 -> V_117 = V_240 ;
V_174 -> V_181 = V_241 ;
V_232 = V_242 ;
break;
case V_209 :
V_174 -> V_115 = & V_8 -> V_14 . V_15 -> V_234 ;
V_174 -> V_117 = V_235 ;
V_174 -> V_181 = V_243 ;
V_232 = V_244 ;
break;
default:
F_85 ( V_238 L_21
L_22 ) ;
return;
}
memcpy ( & V_174 -> V_180 , & V_245 , sizeof( V_245 ) ) ;
V_174 -> V_180 . V_246 = F_49 ;
V_230 = - 1 ;
V_231 = F_86 ( V_8 -> V_14 . V_15 -> V_13 ) ;
if ( V_232 && ( V_231 >= 0 ) && ( V_231 < V_247 ) ) {
V_230 = V_232 [ V_231 ] ;
}
V_174 -> V_180 . V_183 = & V_229 -> V_184 ;
if ( ( F_87 ( & V_174 -> V_180 ,
V_174 -> V_208 , V_230 ) < 0 ) &&
( F_87 ( & V_174 -> V_180 ,
V_174 -> V_208 , - 1 ) < 0 ) ) {
F_85 ( V_238
L_23 ) ;
}
F_43 ( V_182 L_24 ,
F_39 ( & V_174 -> V_180 ) ,
F_40 ( V_174 -> V_117 ) ) ;
F_41 ( V_8 -> V_14 . V_15 -> V_13 ,
V_174 -> V_181 , V_174 -> V_180 . V_248 ) ;
}
struct V_7 * F_88 ( struct V_249 * V_250 )
{
struct V_7 * V_8 ;
V_8 = F_61 ( sizeof( * V_8 ) , V_205 ) ;
if ( ! V_8 ) return V_8 ;
F_63 ( & V_8 -> V_14 , V_250 ) ;
F_5 ( V_188 , L_25 , V_8 ) ;
V_8 -> V_14 . V_251 = F_51 ;
V_8 -> V_186 = F_61 ( sizeof( * V_8 -> V_186 ) , V_205 ) ;
if ( ! V_8 -> V_186 ) goto V_252;
F_83 ( V_8 -> V_186 , V_8 , V_233 ) ;
if ( F_65 ( V_8 -> V_14 . V_15 -> V_13 ) &
( 1 << V_59 ) ) {
V_8 -> V_187 = F_61 ( sizeof( * V_8 -> V_187 ) , V_205 ) ;
if ( ! V_8 -> V_187 ) goto V_252;
F_83 ( V_8 -> V_187 , V_8 , V_209 ) ;
}
return V_8 ;
V_252:
F_5 ( V_188 , L_26 , V_8 ) ;
F_46 ( V_8 ) ;
return NULL ;
}
