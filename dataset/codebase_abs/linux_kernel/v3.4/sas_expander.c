static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = ( void * ) V_1 ;
unsigned long V_4 ;
F_2 ( & V_3 -> V_5 , V_4 ) ;
if ( ! ( V_3 -> V_6 & V_7 ) )
V_3 -> V_6 |= V_8 ;
F_3 ( & V_3 -> V_5 , V_4 ) ;
F_4 ( & V_3 -> V_9 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
if ( ! F_6 ( & V_3 -> V_10 ) )
return;
F_4 ( & V_3 -> V_9 ) ;
}
static int F_7 ( struct V_11 * V_12 , void * V_13 , int V_14 ,
void * V_15 , int V_16 )
{
int V_17 , V_18 ;
struct V_2 * V_3 = NULL ;
struct V_19 * V_20 =
F_8 ( V_12 -> V_21 -> V_22 -> V_23 . V_24 -> V_25 ) ;
F_9 ( & V_12 -> V_26 . V_27 ) ;
for ( V_18 = 0 ; V_18 < 3 ; V_18 ++ ) {
if ( F_10 ( V_28 , & V_12 -> V_29 ) ) {
V_17 = - V_30 ;
break;
}
V_3 = F_11 ( V_31 ) ;
if ( ! V_3 ) {
V_17 = - V_32 ;
break;
}
V_3 -> V_12 = V_12 ;
V_3 -> V_33 = V_12 -> V_34 ;
F_12 ( & V_3 -> V_35 . V_36 , V_13 , V_14 ) ;
F_12 ( & V_3 -> V_35 . V_37 , V_15 , V_16 ) ;
V_3 -> V_38 = F_5 ;
V_3 -> V_10 . V_39 = ( unsigned long ) V_3 ;
V_3 -> V_10 . V_40 = F_1 ;
V_3 -> V_10 . V_41 = V_42 + V_43 * V_44 ;
F_13 ( & V_3 -> V_10 ) ;
V_17 = V_20 -> V_45 -> V_46 ( V_3 , 1 , V_31 ) ;
if ( V_17 ) {
F_6 ( & V_3 -> V_10 ) ;
F_14 ( L_1 , V_17 ) ;
break;
}
F_15 ( & V_3 -> V_9 ) ;
V_17 = - V_30 ;
if ( ( V_3 -> V_6 & V_8 ) ) {
F_14 ( L_2 ) ;
V_20 -> V_45 -> V_47 ( V_3 ) ;
if ( ! ( V_3 -> V_6 & V_7 ) ) {
F_14 ( L_3 ) ;
break;
}
}
if ( V_3 -> V_48 . V_15 == V_49 &&
V_3 -> V_48 . V_50 == V_51 ) {
V_17 = 0 ;
break;
}
if ( V_3 -> V_48 . V_15 == V_49 &&
V_3 -> V_48 . V_50 == V_52 ) {
V_17 = V_3 -> V_48 . V_53 ;
break;
}
if ( V_3 -> V_48 . V_15 == V_49 &&
V_3 -> V_48 . V_50 == V_54 ) {
V_17 = - V_55 ;
break;
}
if ( V_3 -> V_48 . V_15 == V_56 &&
V_3 -> V_48 . V_50 == V_57 )
break;
else {
F_14 ( L_4
L_5 , V_58 ,
F_16 ( V_12 -> V_59 ) ,
V_3 -> V_48 . V_15 ,
V_3 -> V_48 . V_50 ) ;
F_17 ( V_3 ) ;
V_3 = NULL ;
}
}
F_18 ( & V_12 -> V_26 . V_27 ) ;
F_19 ( V_18 == 3 && V_3 != NULL ) ;
F_17 ( V_3 ) ;
return V_17 ;
}
static inline void * F_20 ( int V_60 )
{
T_1 * V_61 = F_21 ( V_60 , V_31 ) ;
if ( V_61 )
V_61 [ 0 ] = V_62 ;
return V_61 ;
}
static inline void * F_22 ( int V_60 )
{
return F_21 ( V_60 , V_31 ) ;
}
static char F_23 ( struct V_11 * V_12 , struct V_63 * V_64 )
{
switch ( V_64 -> V_65 ) {
case V_66 :
if ( V_12 -> V_26 . V_67 )
return 'U' ;
else
return 'T' ;
case V_68 :
return 'D' ;
case V_69 :
return 'S' ;
default:
return '?' ;
}
}
static enum V_70 F_24 ( struct V_71 * V_72 )
{
if ( V_72 -> V_73 == V_74 && V_72 -> V_75 &&
V_72 -> V_76 >= V_77 )
return V_78 ;
else
return V_72 -> V_73 ;
}
static void F_25 ( struct V_11 * V_12 , int V_79 , void * V_80 )
{
enum V_70 V_81 ;
enum V_82 V_76 ;
T_1 V_59 [ V_83 ] ;
struct V_37 * V_15 = V_80 ;
struct V_71 * V_72 = & V_15 -> V_84 ;
struct V_85 * V_22 = V_12 -> V_21 -> V_22 ;
struct V_86 * V_87 = & V_12 -> V_26 ;
struct V_63 * V_64 = & V_87 -> V_63 [ V_79 ] ;
struct V_88 * V_89 = V_12 -> V_89 ;
bool V_90 = ! V_64 -> V_64 ;
char * type ;
if ( V_90 ) {
if ( F_26 ( F_10 ( V_91 , & V_22 -> V_29 ) ) )
return;
V_64 -> V_64 = F_27 ( & V_89 -> V_12 , V_79 ) ;
F_19 ( ! V_64 -> V_64 ) ;
}
switch ( V_15 -> V_92 ) {
case V_93 :
V_64 -> V_94 = V_95 ;
break;
default:
V_64 -> V_94 = V_96 ;
break;
case V_97 :
V_64 -> V_94 = V_98 ;
break;
}
V_81 = V_64 -> V_73 ;
V_76 = V_64 -> V_76 ;
memcpy ( V_59 , V_64 -> V_99 , V_83 ) ;
V_64 -> V_73 = F_24 ( V_72 ) ;
if ( F_10 ( V_91 , & V_22 -> V_29 ) )
goto V_100;
V_64 -> V_79 = V_79 ;
V_64 -> V_76 = V_72 -> V_76 ;
V_64 -> V_101 = V_72 -> V_101 ;
V_64 -> V_75 = V_72 -> V_75 ;
V_64 -> V_102 = V_72 -> V_102 ;
V_64 -> V_103 = V_72 -> V_104 << 1 ;
V_64 -> V_105 = V_72 -> V_34 << 1 ;
if ( V_64 -> V_73 == V_74 ||
V_64 -> V_76 < V_77 )
memset ( V_64 -> V_99 , 0 , V_83 ) ;
else
memcpy ( V_64 -> V_99 , V_72 -> V_99 , V_83 ) ;
V_64 -> V_106 = V_72 -> V_106 ;
V_64 -> V_107 = V_72 -> V_108 ;
V_64 -> V_65 = V_72 -> V_65 ;
V_64 -> V_109 = V_72 -> V_109 ;
V_64 -> V_110 = - 1 ;
V_64 -> V_64 -> V_111 . V_112 = F_16 ( V_64 -> V_99 ) ;
V_64 -> V_64 -> V_111 . V_113 = V_72 -> V_73 ;
V_64 -> V_64 -> V_111 . V_114 = V_64 -> V_103 ;
V_64 -> V_64 -> V_111 . V_115 = V_64 -> V_105 ;
if ( ! V_64 -> V_105 && V_72 -> V_75 )
V_64 -> V_64 -> V_111 . V_115 = V_116 ;
V_64 -> V_64 -> V_111 . V_117 = V_79 ;
V_64 -> V_64 -> V_118 = V_72 -> V_119 ;
V_64 -> V_64 -> V_120 = V_72 -> V_121 ;
V_64 -> V_64 -> V_122 = V_72 -> V_123 ;
V_64 -> V_64 -> V_124 = V_72 -> V_125 ;
V_64 -> V_64 -> V_126 = V_64 -> V_76 ;
if ( V_90 )
if ( F_28 ( V_64 -> V_64 ) ) {
F_29 ( V_64 -> V_64 ) ;
return;
}
V_100:
switch ( V_64 -> V_73 ) {
case V_78 :
type = L_6 ;
break;
case V_74 :
type = L_7 ;
break;
case V_127 :
if ( V_64 -> V_103 ) {
if ( V_64 -> V_105 )
type = L_8 ;
else
type = L_9 ;
} else {
if ( V_72 -> V_75 )
type = L_10 ;
else
type = L_11 ;
}
break;
case V_128 :
case V_129 :
type = L_12 ;
break;
default:
type = L_13 ;
}
if ( V_90 || V_64 -> V_73 != V_81 ||
V_64 -> V_76 != V_76 ||
F_16 ( V_64 -> V_99 ) != F_16 ( V_59 ) )
;
else
return;
if ( F_10 ( V_91 , & V_22 -> V_29 ) )
F_30 ( V_130 , & V_12 -> V_21 -> V_84 . V_131 ) ;
F_14 ( L_14 ,
F_10 ( V_91 , & V_22 -> V_29 ) ? L_15 : L_16 ,
F_16 ( V_12 -> V_59 ) , V_64 -> V_79 ,
F_23 ( V_12 , V_64 ) , V_64 -> V_76 ,
F_16 ( V_64 -> V_99 ) , type ) ;
}
struct V_11 * F_31 ( struct V_11 * V_26 , int V_79 )
{
struct V_63 * V_63 = & V_26 -> V_26 . V_63 [ V_79 ] ;
struct V_11 * V_12 ;
struct V_88 * V_89 ;
if ( ! V_63 -> V_21 )
return NULL ;
V_89 = V_63 -> V_21 -> V_89 ;
if ( ! V_89 )
return NULL ;
V_12 = F_32 ( V_89 ) ;
if ( V_12 && F_33 ( V_12 ) )
return V_12 ;
return NULL ;
}
static int F_34 ( struct V_11 * V_12 , T_1 * V_132 ,
T_1 * V_133 , int V_134 )
{
struct V_71 * V_72 ;
int V_17 ;
V_132 [ 9 ] = V_134 ;
V_17 = F_7 ( V_12 , V_132 , V_135 ,
V_133 , V_136 ) ;
if ( V_17 )
return V_17 ;
V_72 = & ( (struct V_37 * ) V_133 ) -> V_84 ;
if ( memcmp ( V_12 -> V_59 , V_72 -> V_99 , V_83 ) == 0 ) {
F_35 ( L_17 ) ;
return 0 ;
}
F_25 ( V_12 , V_134 , V_133 ) ;
return 0 ;
}
int F_36 ( struct V_11 * V_12 , int V_134 )
{
struct V_86 * V_87 = & V_12 -> V_26 ;
int V_17 = 0 ;
T_1 * V_132 ;
T_1 * V_133 ;
V_132 = F_20 ( V_135 ) ;
if ( ! V_132 )
return - V_32 ;
V_133 = F_20 ( V_136 ) ;
if ( ! V_133 ) {
F_37 ( V_132 ) ;
return - V_32 ;
}
V_132 [ 1 ] = V_137 ;
if ( 0 <= V_134 && V_134 < V_87 -> V_138 ) {
V_17 = F_34 ( V_12 , V_132 , V_133 , V_134 ) ;
} else {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_87 -> V_138 ; V_20 ++ ) {
V_17 = F_34 ( V_12 , V_132 ,
V_133 , V_20 ) ;
if ( V_17 )
goto V_139;
}
}
V_139:
F_37 ( V_133 ) ;
F_37 ( V_132 ) ;
return V_17 ;
}
static int F_38 ( struct V_11 * V_12 )
{
struct V_86 * V_87 = & V_12 -> V_26 ;
int V_17 = - V_32 ;
V_87 -> V_63 = F_21 ( sizeof( * V_87 -> V_63 ) * V_87 -> V_138 , V_31 ) ;
if ( ! V_87 -> V_63 )
return - V_32 ;
V_17 = F_36 ( V_12 , - 1 ) ;
if ( V_17 )
goto V_139;
return 0 ;
V_139:
F_37 ( V_87 -> V_63 ) ;
V_87 -> V_63 = NULL ;
return V_17 ;
}
static void F_39 ( struct V_11 * V_12 ,
struct V_37 * V_15 )
{
struct V_140 * V_141 = & V_15 -> V_141 ;
V_12 -> V_26 . V_142 = F_40 ( V_141 -> V_108 ) ;
V_12 -> V_26 . V_143 = F_40 ( V_141 -> V_144 ) ;
V_12 -> V_26 . V_138 = F_41 ( V_141 -> V_138 , ( T_1 ) V_145 ) ;
V_12 -> V_26 . V_67 = V_141 -> V_67 ;
V_12 -> V_26 . V_146 = V_141 -> V_146 ;
V_12 -> V_26 . V_147 = V_141 -> V_147 ;
memcpy ( V_12 -> V_26 . V_148 , V_141 -> V_148 , 8 ) ;
}
static int F_42 ( struct V_11 * V_12 )
{
T_1 * V_149 ;
struct V_37 * V_150 ;
int V_17 ;
int V_20 ;
V_149 = F_20 ( V_151 ) ;
if ( ! V_149 )
return - V_32 ;
V_150 = F_22 ( V_152 ) ;
if ( ! V_150 ) {
F_37 ( V_149 ) ;
return - V_32 ;
}
V_149 [ 1 ] = V_153 ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ ) {
V_17 = F_7 ( V_12 , V_149 , V_151 , V_150 ,
V_152 ) ;
if ( V_17 ) {
F_14 ( L_18 ,
F_16 ( V_12 -> V_59 ) , V_17 ) ;
goto V_100;
} else if ( V_150 -> V_92 != V_97 ) {
F_14 ( L_19 ,
F_16 ( V_12 -> V_59 ) , V_150 -> V_92 ) ;
V_17 = V_150 -> V_92 ;
goto V_100;
}
F_39 ( V_12 , V_150 ) ;
if ( V_12 -> V_26 . V_147 ) {
F_14 ( L_20 ,
F_16 ( V_12 -> V_59 ) ) ;
F_43 ( 5 * V_44 ) ;
} else
break;
}
V_100:
F_37 ( V_149 ) ;
F_37 ( V_150 ) ;
return V_17 ;
}
static void F_44 ( struct V_11 * V_12 , void
* V_154 )
{
T_1 * V_155 = V_154 ;
struct V_88 * V_89 = V_12 -> V_89 ;
struct V_156 * V_157 = F_45 ( V_89 ) ;
memcpy ( V_157 -> V_158 , V_155 + 12 , V_159 ) ;
memcpy ( V_157 -> V_160 , V_155 + 20 , V_161 ) ;
memcpy ( V_157 -> V_162 , V_155 + 36 ,
V_163 ) ;
if ( V_155 [ 8 ] & 1 ) {
memcpy ( V_157 -> V_164 , V_155 + 40 ,
V_165 ) ;
V_157 -> V_166 = V_155 [ 48 ] << 8 | V_155 [ 49 ] ;
V_157 -> V_167 = V_155 [ 50 ] ;
}
}
static int F_46 ( struct V_11 * V_12 )
{
T_1 * V_168 ;
T_1 * V_155 ;
int V_17 ;
V_168 = F_20 ( V_169 ) ;
if ( ! V_168 )
return - V_32 ;
V_155 = F_22 ( V_170 ) ;
if ( ! V_155 ) {
F_37 ( V_168 ) ;
return - V_32 ;
}
V_168 [ 1 ] = V_171 ;
V_17 = F_7 ( V_12 , V_168 , V_169 , V_155 , V_170 ) ;
if ( V_17 ) {
F_14 ( L_21 ,
F_16 ( V_12 -> V_59 ) , V_17 ) ;
goto V_100;
} else if ( V_155 [ 2 ] != V_97 ) {
F_14 ( L_22 ,
F_16 ( V_12 -> V_59 ) , V_155 [ 2 ] ) ;
goto V_100;
}
F_44 ( V_12 , V_155 ) ;
V_100:
F_37 ( V_168 ) ;
F_37 ( V_155 ) ;
return V_17 ;
}
int F_47 ( struct V_11 * V_12 , int V_79 ,
enum V_172 V_172 ,
struct V_173 * V_174 )
{
T_1 * V_175 ;
T_1 * V_176 ;
int V_17 ;
V_175 = F_20 ( V_177 ) ;
if ( ! V_175 )
return - V_32 ;
V_176 = F_22 ( V_178 ) ;
if ( ! V_176 ) {
F_37 ( V_175 ) ;
return - V_32 ;
}
V_175 [ 1 ] = V_179 ;
V_175 [ 9 ] = V_79 ;
V_175 [ 10 ] = V_172 ;
if ( V_174 ) {
V_175 [ 32 ] = V_174 -> V_122 << 4 ;
V_175 [ 33 ] = V_174 -> V_124 << 4 ;
}
V_17 = F_7 ( V_12 , V_175 , V_177 , V_176 , V_178 ) ;
F_37 ( V_176 ) ;
F_37 ( V_175 ) ;
return V_17 ;
}
static void F_48 ( struct V_11 * V_12 , int V_79 )
{
struct V_86 * V_87 = & V_12 -> V_26 ;
struct V_63 * V_64 = & V_87 -> V_63 [ V_79 ] ;
F_47 ( V_12 , V_79 , V_180 , NULL ) ;
V_64 -> V_76 = V_181 ;
}
static void F_49 ( struct V_11 * V_12 , T_1 * V_59 )
{
struct V_86 * V_87 = & V_12 -> V_26 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_87 -> V_138 ; V_20 ++ ) {
struct V_63 * V_64 = & V_87 -> V_63 [ V_20 ] ;
if ( V_64 -> V_94 == V_95 ||
V_64 -> V_94 == V_96 )
continue;
if ( F_16 ( V_64 -> V_99 ) == F_16 ( V_59 ) )
F_48 ( V_12 , V_20 ) ;
}
}
static int F_50 ( struct V_182 * V_21 ,
T_1 * V_59 )
{
struct V_11 * V_12 ;
if ( F_16 ( V_21 -> V_59 ) == F_16 ( V_59 ) )
return 1 ;
F_51 (dev, &port->dev_list, dev_list_node) {
if ( F_16 ( V_12 -> V_59 ) == F_16 ( V_59 ) )
return 1 ;
}
return 0 ;
}
int F_52 ( struct V_183 * V_64 )
{
int V_17 ;
T_1 * V_13 ;
T_1 * V_15 ;
struct V_88 * V_89 = F_53 ( V_64 -> V_12 . V_184 ) ;
struct V_11 * V_12 = F_32 ( V_89 ) ;
V_13 = F_20 ( V_185 ) ;
if ( ! V_13 )
return - V_32 ;
V_15 = F_22 ( V_186 ) ;
if ( ! V_15 ) {
F_37 ( V_13 ) ;
return - V_32 ;
}
V_13 [ 1 ] = V_187 ;
V_13 [ 9 ] = V_64 -> V_188 ;
V_17 = F_7 ( V_12 , V_13 , V_185 ,
V_15 , V_186 ) ;
if ( ! V_17 )
goto V_100;
V_64 -> V_189 = F_54 ( & V_15 [ 12 ] ) ;
V_64 -> V_190 = F_54 ( & V_15 [ 16 ] ) ;
V_64 -> V_191 = F_54 ( & V_15 [ 20 ] ) ;
V_64 -> V_192 = F_54 ( & V_15 [ 24 ] ) ;
V_100:
F_37 ( V_15 ) ;
return V_17 ;
}
int F_55 ( struct V_11 * V_12 , int V_79 ,
struct V_37 * V_193 )
{
int V_17 ;
T_1 * V_194 = F_20 ( V_195 ) ;
T_1 * V_15 = ( T_1 * ) V_193 ;
if ( ! V_194 )
return - V_32 ;
V_194 [ 1 ] = V_196 ;
V_194 [ 9 ] = V_79 ;
V_17 = F_7 ( V_12 , V_194 , V_195 ,
V_193 , V_197 ) ;
if ( ! V_17 && V_15 [ 27 ] == 0x34 && V_15 [ 24 ] != 0x34 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ ) {
int V_198 = 24 + ( V_20 * 4 ) ;
T_1 V_199 , V_200 ;
V_199 = V_15 [ V_198 + 0 ] ;
V_200 = V_15 [ V_198 + 1 ] ;
V_15 [ V_198 + 0 ] = V_15 [ V_198 + 3 ] ;
V_15 [ V_198 + 1 ] = V_15 [ V_198 + 2 ] ;
V_15 [ V_198 + 2 ] = V_200 ;
V_15 [ V_198 + 3 ] = V_199 ;
}
}
F_37 ( V_194 ) ;
return V_17 ;
}
static void F_56 ( struct V_11 * V_184 ,
struct V_11 * V_201 ,
struct V_63 * V_202 )
{
struct V_86 * V_203 = & V_184 -> V_26 ;
struct V_204 * V_21 ;
int V_20 ;
V_201 -> V_205 = 0 ;
V_21 = V_202 -> V_21 ;
for ( V_20 = 0 ; V_20 < V_203 -> V_138 ; V_20 ++ ) {
struct V_63 * V_64 = & V_203 -> V_63 [ V_20 ] ;
if ( V_64 -> V_94 == V_95 ||
V_64 -> V_94 == V_96 )
continue;
if ( F_16 ( V_64 -> V_99 ) ==
F_16 ( V_201 -> V_59 ) ) {
V_201 -> V_206 = F_41 ( V_184 -> V_206 ,
V_64 -> V_76 ) ;
V_201 -> V_207 = F_57 ( V_184 -> V_207 ,
V_64 -> V_76 ) ;
V_201 -> V_205 ++ ;
F_58 ( V_21 , V_64 -> V_64 ) ;
}
}
V_201 -> V_76 = F_41 ( V_202 -> V_76 , V_201 -> V_207 ) ;
V_201 -> V_205 = F_41 ( V_201 -> V_205 , V_184 -> V_205 ) ;
}
static struct V_11 * F_59 (
struct V_11 * V_184 , int V_79 )
{
struct V_86 * V_203 = & V_184 -> V_26 ;
struct V_63 * V_64 = & V_203 -> V_63 [ V_79 ] ;
struct V_11 * V_201 = NULL ;
struct V_88 * V_89 ;
int V_17 ;
if ( V_64 -> V_101 || V_64 -> V_102 )
return NULL ;
V_201 = F_60 () ;
if ( ! V_201 )
return NULL ;
F_61 ( & V_184 -> V_208 ) ;
V_201 -> V_184 = V_184 ;
V_201 -> V_21 = V_184 -> V_21 ;
V_201 -> V_104 = V_64 -> V_103 ;
memcpy ( V_201 -> V_59 , V_64 -> V_99 , V_83 ) ;
F_62 ( V_201 -> V_209 , V_201 -> V_59 ) ;
if ( ! V_64 -> V_21 ) {
V_64 -> V_21 = F_63 ( & V_184 -> V_89 -> V_12 , V_79 ) ;
if ( F_64 ( ! V_64 -> V_21 ) )
goto V_139;
if ( F_64 ( F_65 ( V_64 -> V_21 ) != 0 ) ) {
F_66 ( V_64 -> V_21 ) ;
goto V_139;
}
}
F_56 ( V_184 , V_201 , V_64 ) ;
F_67 ( V_201 , V_64 -> V_21 ) ;
#ifdef F_68
if ( ( V_64 -> V_105 & V_210 ) || V_64 -> V_75 ) {
V_17 = F_69 ( V_201 , V_64 ) ;
if ( V_17 )
goto V_211;
F_70 ( V_201 ) ;
V_17 = F_71 ( V_201 ) ;
if ( V_17 )
goto V_211;
V_89 = F_72 ( V_64 -> V_21 ) ;
if ( ! V_89 )
goto V_211;
V_201 -> V_89 = V_89 ;
F_73 ( & V_89 -> V_12 ) ;
F_74 ( & V_201 -> V_212 , & V_184 -> V_21 -> V_213 ) ;
V_17 = F_75 ( V_201 ) ;
if ( V_17 ) {
F_14 ( L_23
L_24 ,
F_16 ( V_201 -> V_59 ) ,
F_16 ( V_184 -> V_59 ) , V_79 , V_17 ) ;
goto V_214;
}
} else
#endif
if ( V_64 -> V_105 & V_215 ) {
V_201 -> V_81 = V_127 ;
V_89 = F_72 ( V_64 -> V_21 ) ;
if ( F_64 ( ! V_89 ) )
goto V_211;
V_201 -> V_34 = V_64 -> V_105 ;
F_70 ( V_201 ) ;
V_201 -> V_89 = V_89 ;
F_73 ( & V_89 -> V_12 ) ;
F_76 ( V_201 , V_89 ) ;
F_74 ( & V_201 -> V_212 , & V_184 -> V_21 -> V_213 ) ;
V_17 = F_77 ( V_201 ) ;
if ( V_17 ) {
F_14 ( L_25
L_26 ,
F_16 ( V_201 -> V_59 ) ,
F_16 ( V_184 -> V_59 ) , V_79 , V_17 ) ;
goto V_214;
}
} else {
F_14 ( L_27 ,
V_64 -> V_105 , F_16 ( V_184 -> V_59 ) ,
V_79 ) ;
goto V_211;
}
F_74 ( & V_201 -> V_216 , & V_203 -> V_217 ) ;
return V_201 ;
V_214:
F_78 ( V_201 -> V_89 ) ;
F_79 ( & V_201 -> V_212 ) ;
F_80 ( & V_184 -> V_21 -> V_218 ) ;
F_79 ( & V_201 -> V_219 ) ;
F_81 ( & V_184 -> V_21 -> V_218 ) ;
V_211:
F_82 ( V_64 -> V_21 ) ;
V_139:
V_64 -> V_21 = NULL ;
F_83 ( V_201 ) ;
return NULL ;
}
static int F_84 ( struct V_11 * V_184 , int V_79 )
{
struct V_63 * V_64 = & V_184 -> V_26 . V_63 [ V_79 ] ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_184 -> V_26 . V_138 ; V_20 ++ ) {
struct V_63 * V_220 = & V_184 -> V_26 . V_63 [ V_20 ] ;
if ( V_220 == V_64 )
continue;
if ( ! memcmp ( V_64 -> V_99 , V_220 -> V_99 ,
V_83 ) && V_220 -> V_21 ) {
F_58 ( V_220 -> V_21 , V_64 -> V_64 ) ;
V_64 -> V_21 = V_220 -> V_21 ;
V_64 -> V_94 = V_221 ;
return 0 ;
}
}
return - V_222 ;
}
static struct V_11 * F_85 (
struct V_11 * V_184 , int V_79 )
{
struct V_156 * V_203 = F_45 ( V_184 -> V_89 ) ;
struct V_63 * V_64 = & V_184 -> V_26 . V_63 [ V_79 ] ;
struct V_11 * V_201 = NULL ;
struct V_88 * V_89 ;
struct V_156 * V_157 ;
struct V_182 * V_21 ;
int V_17 ;
if ( V_64 -> V_65 == V_68 ) {
F_14 ( L_28
L_29 ,
F_16 ( V_184 -> V_59 ) , V_79 ,
F_16 ( V_64 -> V_99 ) ,
V_64 -> V_106 ) ;
return NULL ;
}
V_201 = F_60 () ;
if ( ! V_201 )
return NULL ;
V_64 -> V_21 = F_63 ( & V_184 -> V_89 -> V_12 , V_79 ) ;
F_19 ( F_65 ( V_64 -> V_21 ) != 0 ) ;
switch ( V_64 -> V_73 ) {
case V_128 :
V_89 = F_86 ( V_64 -> V_21 ,
V_223 ) ;
break;
case V_129 :
V_89 = F_86 ( V_64 -> V_21 ,
V_224 ) ;
break;
default:
V_89 = NULL ;
F_87 () ;
}
V_21 = V_184 -> V_21 ;
V_201 -> V_89 = V_89 ;
F_73 ( & V_89 -> V_12 ) ;
V_157 = F_45 ( V_89 ) ;
V_201 -> V_81 = V_64 -> V_73 ;
F_61 ( & V_184 -> V_208 ) ;
V_201 -> V_184 = V_184 ;
V_201 -> V_21 = V_21 ;
V_201 -> V_104 = V_64 -> V_103 ;
V_201 -> V_34 = V_64 -> V_105 ;
memcpy ( V_201 -> V_59 , V_64 -> V_99 , V_83 ) ;
F_62 ( V_201 -> V_209 , V_201 -> V_59 ) ;
F_56 ( V_184 , V_201 , V_64 ) ;
V_157 -> V_225 = V_203 -> V_225 + 1 ;
V_184 -> V_21 -> V_84 . V_226 = F_57 ( V_184 -> V_21 -> V_84 . V_226 ,
V_157 -> V_225 ) ;
F_70 ( V_201 ) ;
F_76 ( V_201 , V_89 ) ;
F_88 ( V_89 ) ;
F_80 ( & V_184 -> V_21 -> V_218 ) ;
F_74 ( & V_201 -> V_219 , & V_184 -> V_21 -> V_227 ) ;
F_81 ( & V_184 -> V_21 -> V_218 ) ;
V_17 = F_89 ( V_201 ) ;
if ( V_17 ) {
F_90 ( V_89 ) ;
F_80 ( & V_184 -> V_21 -> V_218 ) ;
F_79 ( & V_201 -> V_219 ) ;
F_81 ( & V_184 -> V_21 -> V_218 ) ;
F_83 ( V_201 ) ;
return NULL ;
}
F_74 ( & V_201 -> V_216 , & V_184 -> V_26 . V_217 ) ;
return V_201 ;
}
static int F_91 ( struct V_11 * V_12 , int V_79 )
{
struct V_86 * V_87 = & V_12 -> V_26 ;
struct V_63 * V_63 = & V_87 -> V_63 [ V_79 ] ;
struct V_11 * V_201 = NULL ;
int V_17 = 0 ;
if ( V_63 -> V_76 == V_228 ) {
if ( ! F_47 ( V_12 , V_79 , V_229 , NULL ) )
V_17 = F_36 ( V_12 , V_79 ) ;
if ( V_17 )
return V_17 ;
}
if ( ! V_12 -> V_184 && ( F_16 ( V_63 -> V_99 ) ==
F_16 ( V_12 -> V_21 -> V_59 ) ) ) {
F_92 ( V_12 , V_79 ) ;
return 0 ;
}
if ( V_12 -> V_184 && ( F_16 ( V_63 -> V_99 ) ==
F_16 ( V_12 -> V_184 -> V_59 ) ) ) {
F_92 ( V_12 , V_79 ) ;
if ( V_63 -> V_65 == V_66 )
F_93 ( V_12 , V_79 , V_12 -> V_21 -> V_59 , 1 ) ;
return 0 ;
}
if ( F_50 ( V_12 -> V_21 , V_63 -> V_99 ) )
F_49 ( V_12 , V_63 -> V_99 ) ;
if ( V_63 -> V_73 == V_74 ) {
if ( V_63 -> V_65 == V_68 ) {
memset ( V_63 -> V_99 , 0 , V_83 ) ;
F_94 ( V_12 , V_63 -> V_99 ) ;
}
return 0 ;
} else if ( V_63 -> V_76 == V_230 )
return 0 ;
if ( V_63 -> V_73 != V_127 &&
V_63 -> V_73 != V_129 &&
V_63 -> V_73 != V_128 &&
V_63 -> V_73 != V_78 ) {
F_14 ( L_30
L_31 , V_63 -> V_73 ,
F_16 ( V_12 -> V_59 ) ,
V_79 ) ;
return 0 ;
}
V_17 = F_94 ( V_12 , V_63 -> V_99 ) ;
if ( V_17 ) {
F_14 ( L_32
L_33 ,
F_16 ( V_63 -> V_99 ) , V_17 ) ;
F_95 ( V_12 , V_63 -> V_99 ) ;
return V_17 ;
}
V_17 = F_84 ( V_12 , V_79 ) ;
if ( ! V_17 ) {
F_14 ( L_34 ,
V_79 , F_16 ( V_63 -> V_99 ) ) ;
return V_17 ;
}
switch ( V_63 -> V_73 ) {
case V_127 :
case V_78 :
V_201 = F_59 ( V_12 , V_79 ) ;
break;
case V_129 :
if ( F_16 ( V_12 -> V_21 -> V_84 . V_231 ) ) {
F_14 ( L_35
L_36 ,
F_16 ( V_63 -> V_99 ) ,
V_63 -> V_106 ,
F_16 ( V_12 -> V_59 ) ,
V_79 ) ;
F_48 ( V_12 , V_79 ) ;
break;
} else
memcpy ( V_12 -> V_21 -> V_84 . V_231 ,
V_63 -> V_99 , V_83 ) ;
case V_128 :
V_201 = F_85 ( V_12 , V_79 ) ;
break;
default:
break;
}
if ( V_201 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_87 -> V_138 ; V_20 ++ ) {
if ( V_87 -> V_63 [ V_20 ] . V_94 == V_95 ||
V_87 -> V_63 [ V_20 ] . V_94 == V_96 )
continue;
if ( F_16 ( V_87 -> V_63 [ V_20 ] . V_99 ) ==
F_16 ( V_201 -> V_59 ) ) {
V_87 -> V_63 [ V_20 ] . V_94 = V_221 ;
V_17 = F_84 ( V_12 , V_20 ) ;
if ( ! V_17 )
F_14 ( L_34 ,
V_20 , F_16 ( V_87 -> V_63 [ V_20 ] . V_99 ) ) ;
}
}
}
return V_17 ;
}
static int F_96 ( struct V_11 * V_12 , T_1 * V_232 )
{
struct V_86 * V_87 = & V_12 -> V_26 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_87 -> V_138 ; V_20 ++ ) {
struct V_63 * V_64 = & V_87 -> V_63 [ V_20 ] ;
if ( V_64 -> V_94 == V_95 ||
V_64 -> V_94 == V_96 )
continue;
if ( ( V_64 -> V_73 == V_128 ||
V_64 -> V_73 == V_129 ) &&
V_64 -> V_65 == V_69 ) {
memcpy ( V_232 , V_64 -> V_99 , V_83 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_97 ( struct V_11 * V_12 )
{
struct V_86 * V_87 = & V_12 -> V_26 ;
struct V_11 * V_201 ;
T_1 V_232 [ 8 ] = { 0 , } ;
F_51 (child, &ex->children, siblings) {
if ( V_201 -> V_81 != V_128 &&
V_201 -> V_81 != V_129 )
continue;
if ( V_232 [ 0 ] == 0 ) {
F_96 ( V_201 , V_232 ) ;
continue;
} else {
T_1 V_233 [ 8 ] ;
if ( F_96 ( V_201 , V_233 ) &&
( F_16 ( V_232 ) != F_16 ( V_233 ) ) ) {
F_14 ( L_37
L_38
L_39 ,
F_16 ( V_12 -> V_59 ) ,
F_16 ( V_201 -> V_59 ) ,
F_16 ( V_233 ) ,
F_16 ( V_232 ) ) ;
F_49 ( V_201 , V_233 ) ;
}
}
}
return 0 ;
}
static int F_98 ( struct V_11 * V_12 , int V_134 )
{
struct V_86 * V_87 = & V_12 -> V_26 ;
int V_20 = 0 , V_234 = V_87 -> V_138 ;
int V_17 = 0 ;
if ( 0 <= V_134 && V_134 < V_234 ) {
V_20 = V_134 ;
V_234 = V_20 + 1 ;
}
for ( ; V_20 < V_234 ; V_20 ++ ) {
struct V_63 * V_63 = & V_87 -> V_63 [ V_20 ] ;
if ( V_63 -> V_94 == V_95 ||
V_63 -> V_94 == V_96 ||
V_63 -> V_94 == V_221 )
continue;
switch ( V_63 -> V_76 ) {
case V_181 :
case V_235 :
case V_236 :
continue;
default:
V_17 = F_91 ( V_12 , V_20 ) ;
if ( V_17 )
break;
continue;
}
}
if ( ! V_17 )
F_97 ( V_12 ) ;
return V_17 ;
}
static int F_99 ( struct V_11 * V_12 )
{
struct V_86 * V_87 = & V_12 -> V_26 ;
int V_20 ;
T_1 * V_237 = NULL ;
if ( V_12 -> V_81 != V_128 )
return 0 ;
for ( V_20 = 0 ; V_20 < V_87 -> V_138 ; V_20 ++ ) {
struct V_63 * V_64 = & V_87 -> V_63 [ V_20 ] ;
if ( V_64 -> V_94 == V_95 ||
V_64 -> V_94 == V_96 )
continue;
if ( ( V_64 -> V_73 == V_129 ||
V_64 -> V_73 == V_128 ) &&
V_64 -> V_65 == V_69 ) {
if ( ! V_237 )
V_237 = & V_64 -> V_99 [ 0 ] ;
else if ( F_16 ( V_237 ) !=
F_16 ( V_64 -> V_99 ) ) {
F_14 ( L_40
L_41
L_42 ,
F_16 ( V_12 -> V_59 ) , V_20 ,
F_16 ( V_64 -> V_99 ) ,
F_16 ( V_237 ) ) ;
F_48 ( V_12 , V_20 ) ;
}
}
}
return 0 ;
}
static void F_100 ( struct V_11 * V_201 ,
struct V_63 * V_202 ,
struct V_63 * V_238 )
{
static const char * V_239 [] = {
[ V_128 ] = L_43 ,
[ V_129 ] = L_44 ,
} ;
struct V_11 * V_184 = V_201 -> V_184 ;
F_35 ( L_45
L_46 ,
V_239 [ V_184 -> V_81 ] ,
F_16 ( V_184 -> V_59 ) ,
V_202 -> V_79 ,
V_239 [ V_201 -> V_81 ] ,
F_16 ( V_201 -> V_59 ) ,
V_238 -> V_79 ,
F_23 ( V_184 , V_202 ) ,
F_23 ( V_201 , V_238 ) ) ;
}
static int F_101 ( struct V_11 * V_201 ,
struct V_63 * V_202 ,
struct V_63 * V_238 )
{
int V_17 = 0 ;
struct V_11 * V_184 = V_201 -> V_184 ;
if ( F_16 ( V_184 -> V_21 -> V_84 . V_231 ) != 0 ) {
V_17 = - V_222 ;
F_14 ( L_47
L_48 ,
F_16 ( V_184 -> V_59 ) ,
V_202 -> V_79 ,
F_16 ( V_201 -> V_59 ) ,
V_238 -> V_79 ,
F_16 ( V_184 -> V_21 -> V_84 . V_231 ) ) ;
} else if ( F_16 ( V_184 -> V_21 -> V_84 . V_240 ) == 0 ) {
memcpy ( V_184 -> V_21 -> V_84 . V_240 , V_184 -> V_59 ,
V_83 ) ;
memcpy ( V_184 -> V_21 -> V_84 . V_241 , V_201 -> V_59 ,
V_83 ) ;
} else if ( ( ( F_16 ( V_184 -> V_21 -> V_84 . V_240 ) ==
F_16 ( V_184 -> V_59 ) ) ||
( F_16 ( V_184 -> V_21 -> V_84 . V_240 ) ==
F_16 ( V_201 -> V_59 ) ) )
&&
( ( F_16 ( V_184 -> V_21 -> V_84 . V_241 ) ==
F_16 ( V_184 -> V_59 ) ) ||
( F_16 ( V_184 -> V_21 -> V_84 . V_241 ) ==
F_16 ( V_201 -> V_59 ) ) ) )
;
else {
V_17 = - V_222 ;
F_14 ( L_49
L_50 ,
F_16 ( V_184 -> V_59 ) ,
V_202 -> V_79 ,
F_16 ( V_201 -> V_59 ) ,
V_238 -> V_79 ) ;
}
return V_17 ;
}
static int F_102 ( struct V_11 * V_201 )
{
struct V_86 * V_242 = & V_201 -> V_26 ;
struct V_86 * V_203 ;
int V_20 ;
int V_17 = 0 ;
if ( ! V_201 -> V_184 )
return 0 ;
if ( V_201 -> V_184 -> V_81 != V_128 &&
V_201 -> V_184 -> V_81 != V_129 )
return 0 ;
V_203 = & V_201 -> V_184 -> V_26 ;
for ( V_20 = 0 ; V_20 < V_203 -> V_138 ; V_20 ++ ) {
struct V_63 * V_202 = & V_203 -> V_63 [ V_20 ] ;
struct V_63 * V_238 ;
if ( V_202 -> V_94 == V_95 ||
V_202 -> V_94 == V_96 )
continue;
if ( F_16 ( V_202 -> V_99 ) != F_16 ( V_201 -> V_59 ) )
continue;
V_238 = & V_242 -> V_63 [ V_202 -> V_106 ] ;
switch ( V_201 -> V_184 -> V_81 ) {
case V_128 :
if ( V_201 -> V_81 == V_129 ) {
if ( V_202 -> V_65 != V_69 ||
V_238 -> V_65 != V_66 ) {
F_100 ( V_201 , V_202 , V_238 ) ;
V_17 = - V_222 ;
}
} else if ( V_202 -> V_65 == V_69 ) {
if ( V_238 -> V_65 == V_69 ) {
V_17 = F_101 ( V_201 , V_202 , V_238 ) ;
} else if ( V_238 -> V_65 != V_66 ) {
F_100 ( V_201 , V_202 , V_238 ) ;
V_17 = - V_222 ;
}
} else if ( V_202 -> V_65 == V_66 ) {
if ( V_238 -> V_65 == V_69 ||
( V_238 -> V_65 == V_66 &&
V_242 -> V_67 && V_203 -> V_67 ) ) {
;
} else {
F_100 ( V_201 , V_202 , V_238 ) ;
V_17 = - V_222 ;
}
}
break;
case V_129 :
if ( V_202 -> V_65 != V_66 ||
V_238 -> V_65 != V_69 ) {
F_100 ( V_201 , V_202 , V_238 ) ;
V_17 = - V_222 ;
}
break;
default:
break;
}
}
return V_17 ;
}
static int F_103 ( struct V_11 * V_12 , int V_79 ,
T_1 * V_59 , int * V_243 , int * V_244 )
{
int V_20 , V_17 = 0 ;
struct V_86 * V_87 = & V_12 -> V_26 ;
struct V_63 * V_64 = & V_87 -> V_63 [ V_79 ] ;
T_1 * V_245 ;
T_1 * V_246 ;
* V_244 = 0 ;
* V_243 = 0 ;
V_245 = F_20 ( V_247 ) ;
if ( ! V_245 )
return - V_32 ;
V_246 = F_22 ( V_248 ) ;
if ( ! V_246 ) {
F_37 ( V_245 ) ;
return - V_32 ;
}
V_245 [ 1 ] = V_249 ;
V_245 [ 9 ] = V_79 ;
for ( V_20 = 0 ; V_20 < V_87 -> V_143 ; V_20 ++ ) {
* ( V_250 * ) ( V_245 + 6 ) = F_104 ( V_20 ) ;
V_17 = F_7 ( V_12 , V_245 , V_247 , V_246 ,
V_248 ) ;
if ( V_17 )
goto V_100;
V_17 = V_246 [ 2 ] ;
if ( V_17 == V_251 ) {
F_14 ( L_51
L_52 ,
F_16 ( V_12 -> V_59 ) , V_79 , V_20 ) ;
goto V_100;
} else if ( V_17 != V_97 ) {
F_14 ( L_53
L_54 , V_58 ,
F_16 ( V_12 -> V_59 ) , V_79 , V_20 , V_17 ) ;
goto V_100;
}
if ( F_16 ( V_59 ) != 0 ) {
if ( F_16 ( V_246 + 16 ) == F_16 ( V_59 ) ) {
* V_243 = V_20 ;
if ( ( V_246 [ 12 ] & 0x80 ) == 0x80 )
* V_244 = 0 ;
else
* V_244 = 1 ;
goto V_100;
} else if ( F_16 ( V_246 + 16 ) == 0 ) {
* V_243 = V_20 ;
* V_244 = 0 ;
goto V_100;
}
} else if ( F_16 ( V_246 + 16 ) == 0 &&
V_64 -> V_110 < V_20 ) {
V_64 -> V_110 = V_20 ;
* V_243 = V_20 ;
* V_244 = 0 ;
goto V_100;
}
}
V_17 = - 1 ;
V_100:
F_37 ( V_245 ) ;
F_37 ( V_246 ) ;
return V_17 ;
}
static int F_105 ( struct V_11 * V_12 , int V_79 ,
T_1 * V_59 , int V_243 , int include )
{
int V_17 ;
T_1 * V_252 ;
T_1 * V_253 ;
V_252 = F_20 ( V_254 ) ;
if ( ! V_252 )
return - V_32 ;
V_253 = F_22 ( V_255 ) ;
if ( ! V_253 ) {
F_37 ( V_252 ) ;
return - V_32 ;
}
V_252 [ 1 ] = V_256 ;
* ( V_250 * ) ( V_252 + 6 ) = F_104 ( V_243 ) ;
V_252 [ 9 ] = V_79 ;
if ( F_16 ( V_59 ) == 0 || ! include )
V_252 [ 12 ] |= 0x80 ;
memcpy ( V_252 + 16 , V_59 , V_83 ) ;
V_17 = F_7 ( V_12 , V_252 , V_254 , V_253 ,
V_255 ) ;
if ( V_17 )
goto V_100;
V_17 = V_253 [ 2 ] ;
if ( V_17 == V_251 ) {
F_14 ( L_55
L_56 ,
F_16 ( V_12 -> V_59 ) , V_79 , V_243 ) ;
}
V_100:
F_37 ( V_252 ) ;
F_37 ( V_253 ) ;
return V_17 ;
}
static int F_93 ( struct V_11 * V_12 , int V_79 ,
T_1 * V_59 , int include )
{
int V_243 ;
int V_244 ;
int V_17 ;
V_17 = F_103 ( V_12 , V_79 , V_59 , & V_243 , & V_244 ) ;
if ( V_17 )
return V_17 ;
if ( include ^ V_244 )
return F_105 ( V_12 , V_79 , V_59 , V_243 , include ) ;
return V_17 ;
}
static int F_106 ( struct V_11 * V_184 ,
struct V_11 * V_201 ,
T_1 * V_59 , int include )
{
struct V_86 * V_257 = & V_184 -> V_26 ;
int V_17 = 0 ;
int V_20 ;
if ( V_184 -> V_184 ) {
V_17 = F_106 ( V_184 -> V_184 , V_184 , V_59 ,
include ) ;
if ( V_17 )
return V_17 ;
}
if ( V_257 -> V_146 == 0 ) {
F_14 ( L_57 ,
F_16 ( V_184 -> V_59 ) ) ;
return 0 ;
}
for ( V_20 = 0 ; V_20 < V_257 -> V_138 ; V_20 ++ ) {
struct V_63 * V_64 = & V_257 -> V_63 [ V_20 ] ;
if ( ( V_64 -> V_65 == V_66 ) &&
( F_16 ( V_64 -> V_99 ) ==
F_16 ( V_201 -> V_59 ) ) ) {
V_17 = F_93 ( V_184 , V_20 , V_59 , include ) ;
if ( V_17 )
return V_17 ;
}
}
return V_17 ;
}
static int F_94 ( struct V_11 * V_12 , T_1 * V_59 )
{
if ( V_12 -> V_184 )
return F_106 ( V_12 -> V_184 , V_12 , V_59 , 1 ) ;
return 0 ;
}
static int F_95 ( struct V_11 * V_12 , T_1 * V_59 )
{
if ( V_12 -> V_184 )
return F_106 ( V_12 -> V_184 , V_12 , V_59 , 0 ) ;
return 0 ;
}
static int F_89 ( struct V_11 * V_12 )
{
int V_17 ;
V_17 = F_107 ( V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_42 ( V_12 ) ;
if ( V_17 )
goto V_139;
V_17 = F_46 ( V_12 ) ;
if ( V_17 )
goto V_139;
V_17 = F_38 ( V_12 ) ;
if ( V_17 ) {
F_14 ( L_58 ,
F_16 ( V_12 -> V_59 ) , V_17 ) ;
goto V_139;
}
F_99 ( V_12 ) ;
V_17 = F_102 ( V_12 ) ;
if ( V_17 )
goto V_139;
return 0 ;
V_139:
F_108 ( V_12 ) ;
return V_17 ;
}
static int F_109 ( struct V_182 * V_21 , const int V_225 )
{
int V_17 = 0 ;
struct V_11 * V_12 ;
F_51 (dev, &port->dev_list, dev_list_node) {
if ( V_12 -> V_81 == V_128 ||
V_12 -> V_81 == V_129 ) {
struct V_156 * V_87 =
F_45 ( V_12 -> V_89 ) ;
if ( V_225 == V_87 -> V_225 )
V_17 = F_98 ( V_12 , - 1 ) ;
else if ( V_225 > 0 )
V_17 = F_98 ( V_21 -> V_258 , - 1 ) ;
}
}
return V_17 ;
}
static int F_110 ( struct V_182 * V_21 )
{
int V_17 ;
int V_225 ;
do {
V_225 = V_21 -> V_84 . V_226 ;
V_17 = F_109 ( V_21 , V_225 ) ;
F_111 () ;
} while ( V_225 < V_21 -> V_84 . V_226 );
return V_17 ;
}
int F_112 ( struct V_11 * V_12 )
{
int V_17 ;
struct V_156 * V_87 = F_45 ( V_12 -> V_89 ) ;
V_17 = F_88 ( V_12 -> V_89 ) ;
if ( V_17 )
goto V_139;
V_87 -> V_225 = V_12 -> V_21 -> V_84 . V_226 ;
V_17 = F_89 ( V_12 ) ;
if ( V_17 )
goto V_259;
F_110 ( V_12 -> V_21 ) ;
return V_17 ;
V_259:
F_113 ( V_12 -> V_89 ) ;
V_139:
return V_17 ;
}
static int F_114 ( struct V_11 * V_12 ,
int V_79 , struct V_37 * V_133 )
{
int V_17 ;
T_1 * V_132 ;
V_132 = F_20 ( V_135 ) ;
if ( ! V_132 )
return - V_32 ;
V_132 [ 1 ] = V_137 ;
V_132 [ 9 ] = V_79 ;
V_17 = F_7 ( V_12 , V_132 , V_135 ,
V_133 , V_136 ) ;
if ( V_17 )
goto V_100;
else if ( V_133 -> V_92 != V_97 ) {
V_17 = V_133 -> V_92 ;
goto V_100;
}
V_100:
F_37 ( V_132 ) ;
return V_17 ;
}
static int F_115 ( struct V_11 * V_12 ,
int V_79 , int * V_260 )
{
int V_17 ;
struct V_37 * V_133 ;
V_133 = F_22 ( V_136 ) ;
if ( ! V_133 )
return - V_32 ;
V_17 = F_114 ( V_12 , V_79 , V_133 ) ;
if ( ! V_17 )
* V_260 = V_133 -> V_84 . V_108 ;
F_37 ( V_133 ) ;
return V_17 ;
}
static int F_116 ( struct V_11 * V_12 , int V_79 ,
T_1 * V_59 , enum V_70 * type )
{
int V_17 ;
struct V_37 * V_133 ;
struct V_71 * V_72 ;
V_133 = F_22 ( V_136 ) ;
if ( ! V_133 )
return - V_32 ;
V_72 = & V_133 -> V_84 ;
V_17 = F_114 ( V_12 , V_79 , V_133 ) ;
if ( V_17 == 0 ) {
memcpy ( V_59 , V_133 -> V_84 . V_99 , 8 ) ;
* type = F_24 ( V_72 ) ;
if ( * type == 0 )
memset ( V_59 , 0 , 8 ) ;
}
F_37 ( V_133 ) ;
return V_17 ;
}
static int F_117 ( struct V_11 * V_12 , int * V_79 ,
int V_261 , bool V_262 )
{
struct V_86 * V_87 = & V_12 -> V_26 ;
int V_17 = 0 ;
int V_20 ;
for ( V_20 = V_261 ; V_20 < V_87 -> V_138 ; V_20 ++ ) {
int V_107 = 0 ;
V_17 = F_115 ( V_12 , V_20 , & V_107 ) ;
switch ( V_17 ) {
case V_93 :
case V_263 :
continue;
case V_97 :
break;
default:
return V_17 ;
}
if ( V_107 != V_87 -> V_63 [ V_20 ] . V_107 ) {
if ( V_262 )
V_87 -> V_63 [ V_20 ] . V_107 =
V_107 ;
* V_79 = V_20 ;
return 0 ;
}
}
return 0 ;
}
static int F_118 ( struct V_11 * V_12 , int * V_264 )
{
int V_17 ;
T_1 * V_149 ;
struct V_37 * V_150 ;
V_149 = F_20 ( V_151 ) ;
if ( ! V_149 )
return - V_32 ;
V_150 = F_22 ( V_152 ) ;
if ( ! V_150 ) {
F_37 ( V_149 ) ;
return - V_32 ;
}
V_149 [ 1 ] = V_153 ;
V_17 = F_7 ( V_12 , V_149 , V_151 , V_150 ,
V_152 ) ;
if ( V_17 )
goto V_100;
if ( V_150 -> V_92 != V_97 ) {
V_17 = V_150 -> V_92 ;
goto V_100;
}
* V_264 = F_40 ( V_150 -> V_141 . V_108 ) ;
V_100:
F_37 ( V_150 ) ;
F_37 ( V_149 ) ;
return V_17 ;
}
static int F_119 ( struct V_11 * V_12 ,
struct V_11 * * V_265 )
{
struct V_86 * V_87 = & V_12 -> V_26 ;
int V_142 = - 1 ;
int V_79 = - 1 ;
int V_17 ;
struct V_11 * V_266 ;
V_17 = F_118 ( V_12 , & V_142 ) ;
if ( V_17 )
goto V_100;
if ( V_142 != - 1 && V_142 != V_87 -> V_142 ) {
V_17 = F_117 ( V_12 , & V_79 , 0 , false ) ;
if ( V_79 != - 1 ) {
* V_265 = V_12 ;
V_87 -> V_142 = V_142 ;
F_14 ( L_59 ) ;
return V_17 ;
} else
F_14 ( L_60 ) ;
}
F_51 (ch, &ex->children, siblings) {
if ( V_266 -> V_81 == V_128 || V_266 -> V_81 == V_129 ) {
V_17 = F_119 ( V_266 , V_265 ) ;
if ( * V_265 )
return V_17 ;
}
}
V_100:
return V_17 ;
}
static void F_120 ( struct V_182 * V_21 , struct V_11 * V_12 )
{
struct V_86 * V_87 = & V_12 -> V_26 ;
struct V_11 * V_201 , * V_267 ;
F_121 (child, n, &ex->children, siblings) {
F_30 ( V_28 , & V_201 -> V_29 ) ;
if ( V_201 -> V_81 == V_128 ||
V_201 -> V_81 == V_129 )
F_120 ( V_21 , V_201 ) ;
else
F_122 ( V_21 , V_201 ) ;
}
F_122 ( V_21 , V_12 ) ;
}
static void F_123 ( struct V_11 * V_184 ,
int V_79 , bool V_268 )
{
struct V_86 * V_26 = & V_184 -> V_26 ;
struct V_63 * V_64 = & V_26 -> V_63 [ V_79 ] ;
struct V_11 * V_201 , * V_267 , * V_269 = NULL ;
if ( V_268 ) {
F_121 (child, n,
&ex_dev->children, siblings) {
if ( F_16 ( V_201 -> V_59 ) ==
F_16 ( V_64 -> V_99 ) ) {
F_30 ( V_28 , & V_201 -> V_29 ) ;
if ( V_201 -> V_81 == V_128 ||
V_201 -> V_81 == V_129 )
F_120 ( V_184 -> V_21 , V_201 ) ;
else
F_122 ( V_184 -> V_21 , V_201 ) ;
V_269 = V_201 ;
break;
}
}
F_95 ( V_184 , V_64 -> V_99 ) ;
}
memset ( V_64 -> V_99 , 0 , V_83 ) ;
if ( V_64 -> V_21 ) {
F_124 ( V_64 -> V_21 , V_64 -> V_64 ) ;
F_67 ( V_269 , V_64 -> V_21 ) ;
if ( V_64 -> V_21 -> V_138 == 0 )
F_82 ( V_64 -> V_21 ) ;
V_64 -> V_21 = NULL ;
}
}
static int F_125 ( struct V_11 * V_270 ,
const int V_225 )
{
struct V_86 * V_271 = & V_270 -> V_26 ;
struct V_11 * V_201 ;
int V_17 = 0 ;
F_51 (child, &ex_root->children, siblings) {
if ( V_201 -> V_81 == V_128 ||
V_201 -> V_81 == V_129 ) {
struct V_156 * V_87 =
F_45 ( V_201 -> V_89 ) ;
if ( V_225 > V_87 -> V_225 )
V_17 = F_125 ( V_201 ,
V_225 ) ;
else if ( V_225 == V_87 -> V_225 )
V_17 = F_98 ( V_201 , - 1 ) ;
}
}
return V_17 ;
}
static int F_126 ( struct V_11 * V_12 )
{
int V_17 ;
struct V_156 * V_87 = F_45 ( V_12 -> V_89 ) ;
int V_225 = V_87 -> V_225 + 1 ;
V_17 = F_98 ( V_12 , - 1 ) ;
if ( V_17 )
goto V_100;
do {
V_17 = F_125 ( V_12 , V_225 ) ;
F_111 () ;
V_225 += 1 ;
} while ( V_225 <= V_12 -> V_21 -> V_84 . V_226 );
V_100:
return V_17 ;
}
static int F_127 ( struct V_11 * V_12 , int V_79 )
{
struct V_63 * V_63 = & V_12 -> V_26 . V_63 [ V_79 ] ;
struct V_11 * V_201 ;
bool V_269 = false ;
int V_17 , V_20 ;
F_14 ( L_61 ,
F_16 ( V_12 -> V_59 ) , V_79 ) ;
V_17 = F_36 ( V_12 , V_79 ) ;
if ( V_17 )
goto V_100;
for ( V_20 = 0 ; V_20 < V_12 -> V_26 . V_138 ; V_20 ++ ) {
struct V_63 * V_272 = & V_12 -> V_26 . V_63 [ V_20 ] ;
if ( V_20 == V_79 )
continue;
if ( F_16 ( V_272 -> V_99 ) ==
F_16 ( V_63 -> V_99 ) ) {
V_269 = true ;
break;
}
}
if ( V_269 ) {
F_84 ( V_12 , V_79 ) ;
return 0 ;
}
V_17 = F_98 ( V_12 , V_79 ) ;
if ( ! V_17 )
goto V_100;
F_51 (child, &dev->ex_dev.children, siblings) {
if ( F_16 ( V_201 -> V_59 ) ==
F_16 ( V_63 -> V_99 ) ) {
if ( V_201 -> V_81 == V_128 ||
V_201 -> V_81 == V_129 )
V_17 = F_126 ( V_201 ) ;
break;
}
}
V_100:
return V_17 ;
}
static bool F_128 ( enum V_70 V_273 , enum V_70 V_274 )
{
if ( V_274 == V_273 )
return true ;
if ( ( V_274 == V_78 && V_273 == V_127 ) ||
( V_274 == V_127 && V_273 == V_78 ) )
return true ;
return false ;
}
static int F_129 ( struct V_11 * V_12 , int V_79 , bool V_268 )
{
struct V_86 * V_87 = & V_12 -> V_26 ;
struct V_63 * V_64 = & V_87 -> V_63 [ V_79 ] ;
enum V_70 type = V_74 ;
T_1 V_59 [ 8 ] ;
int V_17 ;
V_17 = F_116 ( V_12 , V_79 , V_59 , & type ) ;
switch ( V_17 ) {
case V_263 :
V_64 -> V_94 = V_96 ;
F_123 ( V_12 , V_79 , V_268 ) ;
return V_17 ;
case V_93 :
V_64 -> V_94 = V_95 ;
F_123 ( V_12 , V_79 , V_268 ) ;
return V_17 ;
case V_97 :
break;
}
if ( F_16 ( V_59 ) == 0 ) {
V_64 -> V_94 = V_98 ;
F_123 ( V_12 , V_79 , V_268 ) ;
return V_17 ;
} else if ( F_16 ( V_59 ) == F_16 ( V_64 -> V_99 ) &&
F_128 ( type , V_64 -> V_73 ) ) {
struct V_11 * V_275 = F_31 ( V_12 , V_79 ) ;
char * V_276 = L_16 ;
F_36 ( V_12 , V_79 ) ;
if ( V_275 && V_64 -> V_73 == V_78 )
V_276 = L_62 ;
F_14 ( L_63 ,
F_16 ( V_12 -> V_59 ) , V_79 , V_276 ) ;
return V_17 ;
}
if ( F_16 ( V_64 -> V_99 ) &&
F_16 ( V_59 ) != F_16 ( V_64 -> V_99 ) ) {
F_14 ( L_64 ,
F_16 ( V_12 -> V_59 ) , V_79 ,
F_16 ( V_64 -> V_99 ) ) ;
F_123 ( V_12 , V_79 , V_268 ) ;
}
return F_127 ( V_12 , V_79 ) ;
}
static int F_130 ( struct V_11 * V_12 , const int V_79 )
{
struct V_86 * V_87 = & V_12 -> V_26 ;
struct V_63 * V_277 = & V_87 -> V_63 [ V_79 ] ;
int V_17 = 0 ;
int V_20 ;
bool V_268 = true ;
F_14 ( L_65 ,
F_16 ( V_12 -> V_59 ) , V_79 ) ;
if ( F_16 ( V_277 -> V_99 ) != 0 ) {
for ( V_20 = 0 ; V_20 < V_87 -> V_138 ; V_20 ++ ) {
struct V_63 * V_64 = & V_87 -> V_63 [ V_20 ] ;
if ( V_20 == V_79 )
continue;
if ( F_16 ( V_64 -> V_99 ) ==
F_16 ( V_277 -> V_99 ) ) {
F_14 ( L_66
L_67 , V_79 , V_20 ) ;
V_268 = false ;
break;
}
}
V_17 = F_129 ( V_12 , V_79 , V_268 ) ;
} else
V_17 = F_127 ( V_12 , V_79 ) ;
return V_17 ;
}
int F_131 ( struct V_11 * V_258 )
{
int V_17 ;
struct V_11 * V_12 = NULL ;
V_17 = F_119 ( V_258 , & V_12 ) ;
if ( V_17 )
goto V_100;
if ( V_12 ) {
struct V_86 * V_87 = & V_12 -> V_26 ;
int V_20 = 0 , V_79 ;
do {
V_79 = - 1 ;
V_17 = F_117 ( V_12 , & V_79 , V_20 , true ) ;
if ( V_79 == - 1 )
break;
V_17 = F_130 ( V_12 , V_79 ) ;
V_20 = V_79 + 1 ;
} while ( V_20 < V_87 -> V_138 );
}
V_100:
return V_17 ;
}
int F_132 ( struct V_278 * V_24 , struct V_88 * V_89 ,
struct V_279 * V_13 )
{
struct V_11 * V_12 ;
int V_280 , type ;
struct V_279 * V_80 = V_13 -> V_281 ;
if ( ! V_80 ) {
F_133 ( L_68 ,
V_58 ) ;
return - V_282 ;
}
if ( ! V_89 )
return F_134 ( V_24 , V_13 , V_80 ) ;
type = V_89 -> V_111 . V_113 ;
if ( type != V_223 &&
type != V_224 ) {
F_133 ( L_69 ,
V_58 ) ;
return - V_282 ;
}
V_12 = F_32 ( V_89 ) ;
if ( ! V_12 ) {
F_133 ( L_70 , V_58 ) ;
return - V_282 ;
}
if ( V_13 -> V_283 -> V_284 > 1 || V_80 -> V_283 -> V_284 > 1 ) {
F_133 ( L_71 ,
V_58 , V_13 -> V_283 -> V_284 , F_135 ( V_13 ) ,
V_80 -> V_283 -> V_284 , F_135 ( V_80 ) ) ;
return - V_282 ;
}
V_280 = F_7 ( V_12 , F_136 ( V_13 -> V_283 ) , F_135 ( V_13 ) ,
F_136 ( V_80 -> V_283 ) , F_135 ( V_80 ) ) ;
if ( V_280 > 0 ) {
V_80 -> V_285 = V_280 ;
V_13 -> V_285 = 0 ;
V_280 = 0 ;
} else if ( V_280 == 0 ) {
V_80 -> V_285 = 0 ;
V_13 -> V_285 = 0 ;
}
return V_280 ;
}
