static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = ( void * ) V_1 ;
unsigned long V_4 ;
F_2 ( & V_3 -> V_5 , V_4 ) ;
if ( ! ( V_3 -> V_6 & V_7 ) )
V_3 -> V_6 |= V_8 ;
F_3 ( & V_3 -> V_5 , V_4 ) ;
F_4 ( & V_3 -> V_9 -> V_10 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
if ( ! F_6 ( & V_3 -> V_9 -> V_11 ) )
return;
F_4 ( & V_3 -> V_9 -> V_10 ) ;
}
static int F_7 ( struct V_12 * V_13 ,
struct V_14 * V_15 , struct V_14 * V_16 )
{
int V_17 , V_18 ;
struct V_2 * V_3 = NULL ;
struct V_19 * V_20 =
F_8 ( V_13 -> V_21 -> V_22 -> V_23 . V_24 -> V_25 ) ;
F_9 ( & V_13 -> V_26 . V_27 ) ;
for ( V_18 = 0 ; V_18 < 3 ; V_18 ++ ) {
if ( F_10 ( V_28 , & V_13 -> V_29 ) ) {
V_17 = - V_30 ;
break;
}
V_3 = F_11 ( V_31 ) ;
if ( ! V_3 ) {
V_17 = - V_32 ;
break;
}
V_3 -> V_13 = V_13 ;
V_3 -> V_33 = V_13 -> V_34 ;
V_3 -> V_35 . V_36 = * V_15 ;
V_3 -> V_35 . V_37 = * V_16 ;
V_3 -> V_38 = F_5 ;
V_3 -> V_9 -> V_11 . V_39 = ( unsigned long ) V_3 ;
V_3 -> V_9 -> V_11 . V_40 = F_1 ;
V_3 -> V_9 -> V_11 . V_41 = V_42 + V_43 * V_44 ;
F_12 ( & V_3 -> V_9 -> V_11 ) ;
V_17 = V_20 -> V_45 -> V_46 ( V_3 , V_31 ) ;
if ( V_17 ) {
F_6 ( & V_3 -> V_9 -> V_11 ) ;
F_13 ( L_1 , V_17 ) ;
break;
}
F_14 ( & V_3 -> V_9 -> V_10 ) ;
V_17 = - V_30 ;
if ( ( V_3 -> V_6 & V_8 ) ) {
F_13 ( L_2 ) ;
V_20 -> V_45 -> V_47 ( V_3 ) ;
if ( ! ( V_3 -> V_6 & V_7 ) ) {
F_13 ( L_3 ) ;
break;
}
}
if ( V_3 -> V_48 . V_16 == V_49 &&
V_3 -> V_48 . V_50 == V_51 ) {
V_17 = 0 ;
break;
}
if ( V_3 -> V_48 . V_16 == V_49 &&
V_3 -> V_48 . V_50 == V_52 ) {
V_17 = V_3 -> V_48 . V_53 ;
break;
}
if ( V_3 -> V_48 . V_16 == V_49 &&
V_3 -> V_48 . V_50 == V_54 ) {
V_17 = - V_55 ;
break;
}
if ( V_3 -> V_48 . V_16 == V_56 &&
V_3 -> V_48 . V_50 == V_57 )
break;
else {
F_13 ( L_4
L_5 , V_58 ,
F_15 ( V_13 -> V_59 ) ,
V_3 -> V_48 . V_16 ,
V_3 -> V_48 . V_50 ) ;
F_16 ( V_3 ) ;
V_3 = NULL ;
}
}
F_17 ( & V_13 -> V_26 . V_27 ) ;
F_18 ( V_18 == 3 && V_3 != NULL ) ;
F_16 ( V_3 ) ;
return V_17 ;
}
static int F_19 ( struct V_12 * V_13 , void * V_15 , int V_60 ,
void * V_16 , int V_61 )
{
struct V_14 V_62 ;
struct V_14 V_63 ;
F_20 ( & V_62 , V_15 , V_60 ) ;
F_20 ( & V_63 , V_16 , V_61 ) ;
return F_7 ( V_13 , & V_62 , & V_63 ) ;
}
static inline void * F_21 ( int V_64 )
{
T_1 * V_65 = F_22 ( V_64 , V_31 ) ;
if ( V_65 )
V_65 [ 0 ] = V_66 ;
return V_65 ;
}
static inline void * F_23 ( int V_64 )
{
return F_22 ( V_64 , V_31 ) ;
}
static char F_24 ( struct V_12 * V_13 , struct V_67 * V_68 )
{
switch ( V_68 -> V_69 ) {
case V_70 :
if ( V_13 -> V_26 . V_71 )
return 'U' ;
else
return 'T' ;
case V_72 :
return 'D' ;
case V_73 :
return 'S' ;
default:
return '?' ;
}
}
static enum V_74 F_25 ( struct V_75 * V_76 )
{
if ( V_76 -> V_77 == V_78 && V_76 -> V_79 &&
V_76 -> V_80 >= V_81 )
return V_82 ;
else
return V_76 -> V_77 ;
}
static void F_26 ( struct V_12 * V_13 , int V_83 , void * V_84 )
{
enum V_74 V_85 ;
enum V_86 V_80 ;
T_1 V_59 [ V_87 ] ;
struct V_37 * V_16 = V_84 ;
struct V_75 * V_76 = & V_16 -> V_88 ;
struct V_89 * V_22 = V_13 -> V_21 -> V_22 ;
struct V_90 * V_91 = & V_13 -> V_26 ;
struct V_67 * V_68 = & V_91 -> V_67 [ V_83 ] ;
struct V_92 * V_93 = V_13 -> V_93 ;
bool V_94 = ! V_68 -> V_68 ;
char * type ;
if ( V_94 ) {
if ( F_27 ( F_10 ( V_95 , & V_22 -> V_29 ) ) )
return;
V_68 -> V_68 = F_28 ( & V_93 -> V_13 , V_83 ) ;
F_18 ( ! V_68 -> V_68 ) ;
}
switch ( V_16 -> V_96 ) {
case V_97 :
V_68 -> V_98 = V_99 ;
break;
default:
V_68 -> V_98 = V_100 ;
break;
case V_101 :
V_68 -> V_98 = V_102 ;
break;
}
V_85 = V_68 -> V_77 ;
V_80 = V_68 -> V_80 ;
memcpy ( V_59 , V_68 -> V_103 , V_87 ) ;
if ( V_68 -> V_98 == V_99 ) {
memset ( V_68 -> V_103 , 0 , V_87 ) ;
V_68 -> V_77 = V_78 ;
if ( ! F_10 ( V_95 , & V_22 -> V_29 ) ) {
V_68 -> V_83 = V_83 ;
goto V_104;
} else
goto V_105;
}
V_68 -> V_77 = F_25 ( V_76 ) ;
if ( F_10 ( V_95 , & V_22 -> V_29 ) )
goto V_105;
V_68 -> V_83 = V_83 ;
V_68 -> V_80 = V_76 -> V_80 ;
V_68 -> V_106 = V_76 -> V_106 ;
V_68 -> V_79 = V_76 -> V_79 ;
V_68 -> V_107 = V_76 -> V_107 ;
V_68 -> V_108 = V_76 -> V_109 << 1 ;
V_68 -> V_110 = V_76 -> V_34 << 1 ;
if ( V_68 -> V_77 == V_78 ||
V_68 -> V_80 < V_81 )
memset ( V_68 -> V_103 , 0 , V_87 ) ;
else
memcpy ( V_68 -> V_103 , V_76 -> V_103 , V_87 ) ;
V_68 -> V_111 = V_76 -> V_111 ;
V_68 -> V_112 = V_76 -> V_113 ;
V_68 -> V_69 = V_76 -> V_69 ;
V_68 -> V_114 = V_76 -> V_114 ;
V_68 -> V_115 = - 1 ;
V_68 -> V_68 -> V_116 . V_117 = F_15 ( V_68 -> V_103 ) ;
V_68 -> V_68 -> V_116 . V_118 = V_76 -> V_77 ;
V_68 -> V_68 -> V_116 . V_119 = V_68 -> V_108 ;
V_68 -> V_68 -> V_116 . V_120 = V_68 -> V_110 ;
if ( ! V_68 -> V_110 && V_76 -> V_79 )
V_68 -> V_68 -> V_116 . V_120 = V_121 ;
V_68 -> V_68 -> V_116 . V_122 = V_83 ;
V_68 -> V_68 -> V_123 = V_76 -> V_124 ;
V_68 -> V_68 -> V_125 = V_76 -> V_126 ;
V_68 -> V_68 -> V_127 = V_76 -> V_128 ;
V_68 -> V_68 -> V_129 = V_76 -> V_130 ;
V_68 -> V_68 -> V_131 = V_68 -> V_80 ;
V_104:
if ( V_94 )
if ( F_29 ( V_68 -> V_68 ) ) {
F_30 ( V_68 -> V_68 ) ;
return;
}
V_105:
switch ( V_68 -> V_77 ) {
case V_82 :
type = L_6 ;
break;
case V_78 :
type = L_7 ;
break;
case V_132 :
if ( V_68 -> V_108 ) {
if ( V_68 -> V_110 )
type = L_8 ;
else
type = L_9 ;
} else {
if ( V_76 -> V_79 )
type = L_10 ;
else
type = L_11 ;
}
break;
case V_133 :
case V_134 :
type = L_12 ;
break;
default:
type = L_13 ;
}
if ( V_94 || V_68 -> V_77 != V_85 ||
V_68 -> V_80 != V_80 ||
F_15 ( V_68 -> V_103 ) != F_15 ( V_59 ) )
;
else
return;
if ( F_10 ( V_95 , & V_22 -> V_29 ) )
F_31 ( V_135 , & V_13 -> V_21 -> V_88 . V_136 ) ;
F_13 ( L_14 ,
F_10 ( V_95 , & V_22 -> V_29 ) ? L_15 : L_16 ,
F_15 ( V_13 -> V_59 ) , V_68 -> V_83 ,
F_24 ( V_13 , V_68 ) , V_68 -> V_80 ,
F_15 ( V_68 -> V_103 ) , type ) ;
}
struct V_12 * F_32 ( struct V_12 * V_26 , int V_83 )
{
struct V_67 * V_67 = & V_26 -> V_26 . V_67 [ V_83 ] ;
struct V_12 * V_13 ;
struct V_92 * V_93 ;
if ( ! V_67 -> V_21 )
return NULL ;
V_93 = V_67 -> V_21 -> V_93 ;
if ( ! V_93 )
return NULL ;
V_13 = F_33 ( V_93 ) ;
if ( V_13 && F_34 ( V_13 ) )
return V_13 ;
return NULL ;
}
static int F_35 ( struct V_12 * V_13 , T_1 * V_137 ,
T_1 * V_138 , int V_139 )
{
struct V_75 * V_76 ;
int V_17 ;
V_137 [ 9 ] = V_139 ;
V_17 = F_19 ( V_13 , V_137 , V_140 ,
V_138 , V_141 ) ;
if ( V_17 )
return V_17 ;
V_76 = & ( (struct V_37 * ) V_138 ) -> V_88 ;
if ( memcmp ( V_13 -> V_59 , V_76 -> V_103 , V_87 ) == 0 ) {
F_36 ( L_17 ) ;
return 0 ;
}
F_26 ( V_13 , V_139 , V_138 ) ;
return 0 ;
}
int F_37 ( struct V_12 * V_13 , int V_139 )
{
struct V_90 * V_91 = & V_13 -> V_26 ;
int V_17 = 0 ;
T_1 * V_137 ;
T_1 * V_138 ;
V_137 = F_21 ( V_140 ) ;
if ( ! V_137 )
return - V_32 ;
V_138 = F_23 ( V_141 ) ;
if ( ! V_138 ) {
F_38 ( V_137 ) ;
return - V_32 ;
}
V_137 [ 1 ] = V_142 ;
if ( 0 <= V_139 && V_139 < V_91 -> V_143 ) {
V_17 = F_35 ( V_13 , V_137 , V_138 , V_139 ) ;
} else {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_91 -> V_143 ; V_20 ++ ) {
V_17 = F_35 ( V_13 , V_137 ,
V_138 , V_20 ) ;
if ( V_17 )
goto V_144;
}
}
V_144:
F_38 ( V_138 ) ;
F_38 ( V_137 ) ;
return V_17 ;
}
static int F_39 ( struct V_12 * V_13 )
{
struct V_90 * V_91 = & V_13 -> V_26 ;
int V_17 = - V_32 ;
V_91 -> V_67 = F_22 ( sizeof( * V_91 -> V_67 ) * V_91 -> V_143 , V_31 ) ;
if ( ! V_91 -> V_67 )
return - V_32 ;
V_17 = F_37 ( V_13 , - 1 ) ;
if ( V_17 )
goto V_144;
return 0 ;
V_144:
F_38 ( V_91 -> V_67 ) ;
V_91 -> V_67 = NULL ;
return V_17 ;
}
static void F_40 ( struct V_12 * V_13 ,
struct V_37 * V_16 )
{
struct V_145 * V_146 = & V_16 -> V_146 ;
V_13 -> V_26 . V_147 = F_41 ( V_146 -> V_113 ) ;
V_13 -> V_26 . V_148 = F_41 ( V_146 -> V_149 ) ;
V_13 -> V_26 . V_143 = F_42 ( V_146 -> V_143 , ( T_1 ) V_150 ) ;
V_13 -> V_26 . V_71 = V_146 -> V_71 ;
V_13 -> V_26 . V_151 = V_146 -> V_151 ;
V_13 -> V_26 . V_152 = V_146 -> V_152 ;
memcpy ( V_13 -> V_26 . V_153 , V_146 -> V_153 , 8 ) ;
}
static int F_43 ( struct V_12 * V_13 )
{
T_1 * V_154 ;
struct V_37 * V_155 ;
int V_17 ;
int V_20 ;
V_154 = F_21 ( V_156 ) ;
if ( ! V_154 )
return - V_32 ;
V_155 = F_23 ( V_157 ) ;
if ( ! V_155 ) {
F_38 ( V_154 ) ;
return - V_32 ;
}
V_154 [ 1 ] = V_158 ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ ) {
V_17 = F_19 ( V_13 , V_154 , V_156 , V_155 ,
V_157 ) ;
if ( V_17 ) {
F_13 ( L_18 ,
F_15 ( V_13 -> V_59 ) , V_17 ) ;
goto V_105;
} else if ( V_155 -> V_96 != V_101 ) {
F_13 ( L_19 ,
F_15 ( V_13 -> V_59 ) , V_155 -> V_96 ) ;
V_17 = V_155 -> V_96 ;
goto V_105;
}
F_40 ( V_13 , V_155 ) ;
if ( V_13 -> V_26 . V_152 ) {
F_13 ( L_20 ,
F_15 ( V_13 -> V_59 ) ) ;
F_44 ( 5 * V_44 ) ;
} else
break;
}
V_105:
F_38 ( V_154 ) ;
F_38 ( V_155 ) ;
return V_17 ;
}
static void F_45 ( struct V_12 * V_13 , void
* V_159 )
{
T_1 * V_160 = V_159 ;
struct V_92 * V_93 = V_13 -> V_93 ;
struct V_161 * V_162 = F_46 ( V_93 ) ;
memcpy ( V_162 -> V_163 , V_160 + 12 , V_164 ) ;
memcpy ( V_162 -> V_165 , V_160 + 20 , V_166 ) ;
memcpy ( V_162 -> V_167 , V_160 + 36 ,
V_168 ) ;
if ( V_160 [ 8 ] & 1 ) {
memcpy ( V_162 -> V_169 , V_160 + 40 ,
V_170 ) ;
V_162 -> V_171 = V_160 [ 48 ] << 8 | V_160 [ 49 ] ;
V_162 -> V_172 = V_160 [ 50 ] ;
}
}
static int F_47 ( struct V_12 * V_13 )
{
T_1 * V_173 ;
T_1 * V_160 ;
int V_17 ;
V_173 = F_21 ( V_174 ) ;
if ( ! V_173 )
return - V_32 ;
V_160 = F_23 ( V_175 ) ;
if ( ! V_160 ) {
F_38 ( V_173 ) ;
return - V_32 ;
}
V_173 [ 1 ] = V_176 ;
V_17 = F_19 ( V_13 , V_173 , V_174 , V_160 , V_175 ) ;
if ( V_17 ) {
F_13 ( L_21 ,
F_15 ( V_13 -> V_59 ) , V_17 ) ;
goto V_105;
} else if ( V_160 [ 2 ] != V_101 ) {
F_13 ( L_22 ,
F_15 ( V_13 -> V_59 ) , V_160 [ 2 ] ) ;
goto V_105;
}
F_45 ( V_13 , V_160 ) ;
V_105:
F_38 ( V_173 ) ;
F_38 ( V_160 ) ;
return V_17 ;
}
int F_48 ( struct V_12 * V_13 , int V_83 ,
enum V_177 V_177 ,
struct V_178 * V_179 )
{
T_1 * V_180 ;
T_1 * V_181 ;
int V_17 ;
V_180 = F_21 ( V_182 ) ;
if ( ! V_180 )
return - V_32 ;
V_181 = F_23 ( V_183 ) ;
if ( ! V_181 ) {
F_38 ( V_180 ) ;
return - V_32 ;
}
V_180 [ 1 ] = V_184 ;
V_180 [ 9 ] = V_83 ;
V_180 [ 10 ] = V_177 ;
if ( V_179 ) {
V_180 [ 32 ] = V_179 -> V_127 << 4 ;
V_180 [ 33 ] = V_179 -> V_129 << 4 ;
}
V_17 = F_19 ( V_13 , V_180 , V_182 , V_181 , V_183 ) ;
F_38 ( V_181 ) ;
F_38 ( V_180 ) ;
return V_17 ;
}
static void F_49 ( struct V_12 * V_13 , int V_83 )
{
struct V_90 * V_91 = & V_13 -> V_26 ;
struct V_67 * V_68 = & V_91 -> V_67 [ V_83 ] ;
F_48 ( V_13 , V_83 , V_185 , NULL ) ;
V_68 -> V_80 = V_186 ;
}
static void F_50 ( struct V_12 * V_13 , T_1 * V_59 )
{
struct V_90 * V_91 = & V_13 -> V_26 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_91 -> V_143 ; V_20 ++ ) {
struct V_67 * V_68 = & V_91 -> V_67 [ V_20 ] ;
if ( V_68 -> V_98 == V_99 ||
V_68 -> V_98 == V_100 )
continue;
if ( F_15 ( V_68 -> V_103 ) == F_15 ( V_59 ) )
F_49 ( V_13 , V_20 ) ;
}
}
static int F_51 ( struct V_187 * V_21 ,
T_1 * V_59 )
{
struct V_12 * V_13 ;
if ( F_15 ( V_21 -> V_59 ) == F_15 ( V_59 ) )
return 1 ;
F_52 (dev, &port->dev_list, dev_list_node) {
if ( F_15 ( V_13 -> V_59 ) == F_15 ( V_59 ) )
return 1 ;
}
return 0 ;
}
int F_53 ( struct V_188 * V_68 )
{
int V_17 ;
T_1 * V_15 ;
T_1 * V_16 ;
struct V_92 * V_93 = F_54 ( V_68 -> V_13 . V_189 ) ;
struct V_12 * V_13 = F_33 ( V_93 ) ;
V_15 = F_21 ( V_190 ) ;
if ( ! V_15 )
return - V_32 ;
V_16 = F_23 ( V_191 ) ;
if ( ! V_16 ) {
F_38 ( V_15 ) ;
return - V_32 ;
}
V_15 [ 1 ] = V_192 ;
V_15 [ 9 ] = V_68 -> V_193 ;
V_17 = F_19 ( V_13 , V_15 , V_190 ,
V_16 , V_191 ) ;
if ( ! V_17 )
goto V_105;
V_68 -> V_194 = F_55 ( & V_16 [ 12 ] ) ;
V_68 -> V_195 = F_55 ( & V_16 [ 16 ] ) ;
V_68 -> V_196 = F_55 ( & V_16 [ 20 ] ) ;
V_68 -> V_197 = F_55 ( & V_16 [ 24 ] ) ;
V_105:
F_38 ( V_16 ) ;
return V_17 ;
}
int F_56 ( struct V_12 * V_13 , int V_83 ,
struct V_37 * V_198 )
{
int V_17 ;
T_1 * V_199 = F_21 ( V_200 ) ;
T_1 * V_16 = ( T_1 * ) V_198 ;
if ( ! V_199 )
return - V_32 ;
V_199 [ 1 ] = V_201 ;
V_199 [ 9 ] = V_83 ;
V_17 = F_19 ( V_13 , V_199 , V_200 ,
V_198 , V_202 ) ;
if ( ! V_17 && V_16 [ 27 ] == 0x34 && V_16 [ 24 ] != 0x34 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ ) {
int V_203 = 24 + ( V_20 * 4 ) ;
T_1 V_204 , V_205 ;
V_204 = V_16 [ V_203 + 0 ] ;
V_205 = V_16 [ V_203 + 1 ] ;
V_16 [ V_203 + 0 ] = V_16 [ V_203 + 3 ] ;
V_16 [ V_203 + 1 ] = V_16 [ V_203 + 2 ] ;
V_16 [ V_203 + 2 ] = V_205 ;
V_16 [ V_203 + 3 ] = V_204 ;
}
}
F_38 ( V_199 ) ;
return V_17 ;
}
static void F_57 ( struct V_12 * V_189 ,
struct V_12 * V_206 ,
struct V_67 * V_207 )
{
struct V_90 * V_208 = & V_189 -> V_26 ;
struct V_209 * V_21 ;
int V_20 ;
V_206 -> V_210 = 0 ;
V_21 = V_207 -> V_21 ;
for ( V_20 = 0 ; V_20 < V_208 -> V_143 ; V_20 ++ ) {
struct V_67 * V_68 = & V_208 -> V_67 [ V_20 ] ;
if ( V_68 -> V_98 == V_99 ||
V_68 -> V_98 == V_100 )
continue;
if ( F_15 ( V_68 -> V_103 ) ==
F_15 ( V_206 -> V_59 ) ) {
V_206 -> V_211 = F_42 ( V_189 -> V_211 ,
V_68 -> V_80 ) ;
V_206 -> V_212 = F_58 ( V_189 -> V_212 ,
V_68 -> V_80 ) ;
V_206 -> V_210 ++ ;
F_59 ( V_21 , V_68 -> V_68 ) ;
}
}
V_206 -> V_80 = F_42 ( V_207 -> V_80 , V_206 -> V_212 ) ;
V_206 -> V_210 = F_42 ( V_206 -> V_210 , V_189 -> V_210 ) ;
}
static struct V_12 * F_60 (
struct V_12 * V_189 , int V_83 )
{
struct V_90 * V_208 = & V_189 -> V_26 ;
struct V_67 * V_68 = & V_208 -> V_67 [ V_83 ] ;
struct V_12 * V_206 = NULL ;
struct V_92 * V_93 ;
int V_17 ;
if ( V_68 -> V_106 || V_68 -> V_107 )
return NULL ;
V_206 = F_61 () ;
if ( ! V_206 )
return NULL ;
F_62 ( & V_189 -> V_213 ) ;
V_206 -> V_189 = V_189 ;
V_206 -> V_21 = V_189 -> V_21 ;
V_206 -> V_109 = V_68 -> V_108 ;
memcpy ( V_206 -> V_59 , V_68 -> V_103 , V_87 ) ;
F_63 ( V_206 -> V_214 , V_206 -> V_59 ) ;
if ( ! V_68 -> V_21 ) {
V_68 -> V_21 = F_64 ( & V_189 -> V_93 -> V_13 , V_83 ) ;
if ( F_65 ( ! V_68 -> V_21 ) )
goto V_144;
if ( F_65 ( F_66 ( V_68 -> V_21 ) != 0 ) ) {
F_67 ( V_68 -> V_21 ) ;
goto V_144;
}
}
F_57 ( V_189 , V_206 , V_68 ) ;
F_68 ( V_206 , V_68 -> V_21 ) ;
#ifdef F_69
if ( ( V_68 -> V_110 & V_215 ) || V_68 -> V_79 ) {
V_17 = F_70 ( V_206 , V_68 ) ;
if ( V_17 )
goto V_216;
F_71 ( V_206 ) ;
V_17 = F_72 ( V_206 ) ;
if ( V_17 )
goto V_216;
V_93 = F_73 ( V_68 -> V_21 ) ;
if ( ! V_93 )
goto V_216;
V_206 -> V_93 = V_93 ;
F_74 ( & V_93 -> V_13 ) ;
F_75 ( & V_206 -> V_217 , & V_189 -> V_21 -> V_218 ) ;
V_17 = F_76 ( V_206 ) ;
if ( V_17 ) {
F_13 ( L_23
L_24 ,
F_15 ( V_206 -> V_59 ) ,
F_15 ( V_189 -> V_59 ) , V_83 , V_17 ) ;
goto V_219;
}
} else
#endif
if ( V_68 -> V_110 & V_220 ) {
V_206 -> V_85 = V_132 ;
V_93 = F_73 ( V_68 -> V_21 ) ;
if ( F_65 ( ! V_93 ) )
goto V_216;
V_206 -> V_34 = V_68 -> V_110 ;
F_71 ( V_206 ) ;
V_206 -> V_93 = V_93 ;
F_74 ( & V_93 -> V_13 ) ;
F_77 ( V_206 , V_93 ) ;
F_75 ( & V_206 -> V_217 , & V_189 -> V_21 -> V_218 ) ;
V_17 = F_78 ( V_206 ) ;
if ( V_17 ) {
F_13 ( L_25
L_26 ,
F_15 ( V_206 -> V_59 ) ,
F_15 ( V_189 -> V_59 ) , V_83 , V_17 ) ;
goto V_219;
}
} else {
F_13 ( L_27 ,
V_68 -> V_110 , F_15 ( V_189 -> V_59 ) ,
V_83 ) ;
goto V_216;
}
F_75 ( & V_206 -> V_221 , & V_208 -> V_222 ) ;
return V_206 ;
V_219:
F_79 ( V_206 -> V_93 ) ;
F_80 ( & V_206 -> V_217 ) ;
F_81 ( & V_189 -> V_21 -> V_223 ) ;
F_80 ( & V_206 -> V_224 ) ;
F_82 ( & V_189 -> V_21 -> V_223 ) ;
V_216:
F_83 ( V_68 -> V_21 ) ;
V_144:
V_68 -> V_21 = NULL ;
F_84 ( V_206 ) ;
return NULL ;
}
static bool F_85 ( struct V_12 * V_189 , int V_83 )
{
struct V_67 * V_68 = & V_189 -> V_26 . V_67 [ V_83 ] ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_189 -> V_26 . V_143 ; V_20 ++ ) {
struct V_67 * V_225 = & V_189 -> V_26 . V_67 [ V_20 ] ;
if ( V_225 == V_68 )
continue;
if ( ! memcmp ( V_68 -> V_103 , V_225 -> V_103 ,
V_87 ) && V_225 -> V_21 ) {
F_59 ( V_225 -> V_21 , V_68 -> V_68 ) ;
V_68 -> V_21 = V_225 -> V_21 ;
V_68 -> V_98 = V_226 ;
return true ;
}
}
return false ;
}
static struct V_12 * F_86 (
struct V_12 * V_189 , int V_83 )
{
struct V_161 * V_208 = F_46 ( V_189 -> V_93 ) ;
struct V_67 * V_68 = & V_189 -> V_26 . V_67 [ V_83 ] ;
struct V_12 * V_206 = NULL ;
struct V_92 * V_93 ;
struct V_161 * V_162 ;
struct V_187 * V_21 ;
int V_17 ;
if ( V_68 -> V_69 == V_72 ) {
F_13 ( L_28
L_29 ,
F_15 ( V_189 -> V_59 ) , V_83 ,
F_15 ( V_68 -> V_103 ) ,
V_68 -> V_111 ) ;
return NULL ;
}
V_206 = F_61 () ;
if ( ! V_206 )
return NULL ;
V_68 -> V_21 = F_64 ( & V_189 -> V_93 -> V_13 , V_83 ) ;
F_18 ( F_66 ( V_68 -> V_21 ) != 0 ) ;
switch ( V_68 -> V_77 ) {
case V_133 :
V_93 = F_87 ( V_68 -> V_21 ,
V_133 ) ;
break;
case V_134 :
V_93 = F_87 ( V_68 -> V_21 ,
V_134 ) ;
break;
default:
V_93 = NULL ;
F_88 () ;
}
V_21 = V_189 -> V_21 ;
V_206 -> V_93 = V_93 ;
F_74 ( & V_93 -> V_13 ) ;
V_162 = F_46 ( V_93 ) ;
V_206 -> V_85 = V_68 -> V_77 ;
F_62 ( & V_189 -> V_213 ) ;
V_206 -> V_189 = V_189 ;
V_206 -> V_21 = V_21 ;
V_206 -> V_109 = V_68 -> V_108 ;
V_206 -> V_34 = V_68 -> V_110 ;
memcpy ( V_206 -> V_59 , V_68 -> V_103 , V_87 ) ;
F_63 ( V_206 -> V_214 , V_206 -> V_59 ) ;
F_57 ( V_189 , V_206 , V_68 ) ;
V_162 -> V_227 = V_208 -> V_227 + 1 ;
V_189 -> V_21 -> V_88 . V_228 = F_58 ( V_189 -> V_21 -> V_88 . V_228 ,
V_162 -> V_227 ) ;
F_71 ( V_206 ) ;
F_77 ( V_206 , V_93 ) ;
F_89 ( V_93 ) ;
F_81 ( & V_189 -> V_21 -> V_223 ) ;
F_75 ( & V_206 -> V_224 , & V_189 -> V_21 -> V_229 ) ;
F_82 ( & V_189 -> V_21 -> V_223 ) ;
V_17 = F_90 ( V_206 ) ;
if ( V_17 ) {
F_91 ( V_93 ) ;
F_81 ( & V_189 -> V_21 -> V_223 ) ;
F_80 ( & V_206 -> V_224 ) ;
F_82 ( & V_189 -> V_21 -> V_223 ) ;
F_84 ( V_206 ) ;
return NULL ;
}
F_75 ( & V_206 -> V_221 , & V_189 -> V_26 . V_222 ) ;
return V_206 ;
}
static int F_92 ( struct V_12 * V_13 , int V_83 )
{
struct V_90 * V_91 = & V_13 -> V_26 ;
struct V_67 * V_67 = & V_91 -> V_67 [ V_83 ] ;
struct V_12 * V_206 = NULL ;
int V_17 = 0 ;
if ( V_67 -> V_80 == V_230 ) {
if ( ! F_48 ( V_13 , V_83 , V_231 , NULL ) )
V_17 = F_37 ( V_13 , V_83 ) ;
if ( V_17 )
return V_17 ;
}
if ( ! V_13 -> V_189 && ( F_15 ( V_67 -> V_103 ) ==
F_15 ( V_13 -> V_21 -> V_59 ) ) ) {
F_93 ( V_13 , V_83 ) ;
return 0 ;
}
if ( V_13 -> V_189 && ( F_15 ( V_67 -> V_103 ) ==
F_15 ( V_13 -> V_189 -> V_59 ) ) ) {
F_93 ( V_13 , V_83 ) ;
if ( V_67 -> V_69 == V_70 )
F_94 ( V_13 , V_83 , V_13 -> V_21 -> V_59 , 1 ) ;
return 0 ;
}
if ( F_51 ( V_13 -> V_21 , V_67 -> V_103 ) )
F_50 ( V_13 , V_67 -> V_103 ) ;
if ( V_67 -> V_77 == V_78 ) {
if ( V_67 -> V_69 == V_72 ) {
memset ( V_67 -> V_103 , 0 , V_87 ) ;
F_95 ( V_13 , V_67 -> V_103 ) ;
}
return 0 ;
} else if ( V_67 -> V_80 == V_232 )
return 0 ;
if ( V_67 -> V_77 != V_132 &&
V_67 -> V_77 != V_134 &&
V_67 -> V_77 != V_133 &&
V_67 -> V_77 != V_82 ) {
F_13 ( L_30
L_31 , V_67 -> V_77 ,
F_15 ( V_13 -> V_59 ) ,
V_83 ) ;
return 0 ;
}
V_17 = F_95 ( V_13 , V_67 -> V_103 ) ;
if ( V_17 ) {
F_13 ( L_32
L_33 ,
F_15 ( V_67 -> V_103 ) , V_17 ) ;
F_96 ( V_13 , V_67 -> V_103 ) ;
return V_17 ;
}
if ( F_85 ( V_13 , V_83 ) ) {
F_13 ( L_34 ,
V_83 , F_15 ( V_67 -> V_103 ) ) ;
return V_17 ;
}
switch ( V_67 -> V_77 ) {
case V_132 :
case V_82 :
V_206 = F_60 ( V_13 , V_83 ) ;
break;
case V_134 :
if ( F_15 ( V_13 -> V_21 -> V_88 . V_233 ) ) {
F_13 ( L_35
L_36 ,
F_15 ( V_67 -> V_103 ) ,
V_67 -> V_111 ,
F_15 ( V_13 -> V_59 ) ,
V_83 ) ;
F_49 ( V_13 , V_83 ) ;
break;
} else
memcpy ( V_13 -> V_21 -> V_88 . V_233 ,
V_67 -> V_103 , V_87 ) ;
case V_133 :
V_206 = F_86 ( V_13 , V_83 ) ;
break;
default:
break;
}
if ( V_206 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_91 -> V_143 ; V_20 ++ ) {
if ( V_91 -> V_67 [ V_20 ] . V_98 == V_99 ||
V_91 -> V_67 [ V_20 ] . V_98 == V_100 )
continue;
if ( F_15 ( V_91 -> V_67 [ V_20 ] . V_103 ) ==
F_15 ( V_206 -> V_59 ) ) {
V_91 -> V_67 [ V_20 ] . V_98 = V_226 ;
if ( F_85 ( V_13 , V_20 ) )
F_13 ( L_34 ,
V_20 , F_15 ( V_91 -> V_67 [ V_20 ] . V_103 ) ) ;
}
}
}
return V_17 ;
}
static int F_97 ( struct V_12 * V_13 , T_1 * V_234 )
{
struct V_90 * V_91 = & V_13 -> V_26 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_91 -> V_143 ; V_20 ++ ) {
struct V_67 * V_68 = & V_91 -> V_67 [ V_20 ] ;
if ( V_68 -> V_98 == V_99 ||
V_68 -> V_98 == V_100 )
continue;
if ( ( V_68 -> V_77 == V_133 ||
V_68 -> V_77 == V_134 ) &&
V_68 -> V_69 == V_73 ) {
memcpy ( V_234 , V_68 -> V_103 , V_87 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_98 ( struct V_12 * V_13 )
{
struct V_90 * V_91 = & V_13 -> V_26 ;
struct V_12 * V_206 ;
T_1 V_234 [ 8 ] = { 0 , } ;
F_52 (child, &ex->children, siblings) {
if ( V_206 -> V_85 != V_133 &&
V_206 -> V_85 != V_134 )
continue;
if ( V_234 [ 0 ] == 0 ) {
F_97 ( V_206 , V_234 ) ;
continue;
} else {
T_1 V_235 [ 8 ] ;
if ( F_97 ( V_206 , V_235 ) &&
( F_15 ( V_234 ) != F_15 ( V_235 ) ) ) {
F_13 ( L_37
L_38
L_39 ,
F_15 ( V_13 -> V_59 ) ,
F_15 ( V_206 -> V_59 ) ,
F_15 ( V_235 ) ,
F_15 ( V_234 ) ) ;
F_50 ( V_206 , V_235 ) ;
}
}
}
return 0 ;
}
static int F_99 ( struct V_12 * V_13 , int V_139 )
{
struct V_90 * V_91 = & V_13 -> V_26 ;
int V_20 = 0 , V_236 = V_91 -> V_143 ;
int V_17 = 0 ;
if ( 0 <= V_139 && V_139 < V_236 ) {
V_20 = V_139 ;
V_236 = V_20 + 1 ;
}
for ( ; V_20 < V_236 ; V_20 ++ ) {
struct V_67 * V_67 = & V_91 -> V_67 [ V_20 ] ;
if ( V_67 -> V_98 == V_99 ||
V_67 -> V_98 == V_100 ||
V_67 -> V_98 == V_226 )
continue;
switch ( V_67 -> V_80 ) {
case V_186 :
case V_237 :
case V_238 :
continue;
default:
V_17 = F_92 ( V_13 , V_20 ) ;
if ( V_17 )
break;
continue;
}
}
if ( ! V_17 )
F_98 ( V_13 ) ;
return V_17 ;
}
static int F_100 ( struct V_12 * V_13 )
{
struct V_90 * V_91 = & V_13 -> V_26 ;
int V_20 ;
T_1 * V_239 = NULL ;
if ( V_13 -> V_85 != V_133 )
return 0 ;
for ( V_20 = 0 ; V_20 < V_91 -> V_143 ; V_20 ++ ) {
struct V_67 * V_68 = & V_91 -> V_67 [ V_20 ] ;
if ( V_68 -> V_98 == V_99 ||
V_68 -> V_98 == V_100 )
continue;
if ( ( V_68 -> V_77 == V_134 ||
V_68 -> V_77 == V_133 ) &&
V_68 -> V_69 == V_73 ) {
if ( ! V_239 )
V_239 = & V_68 -> V_103 [ 0 ] ;
else if ( F_15 ( V_239 ) !=
F_15 ( V_68 -> V_103 ) ) {
F_13 ( L_40
L_41
L_42 ,
F_15 ( V_13 -> V_59 ) , V_20 ,
F_15 ( V_68 -> V_103 ) ,
F_15 ( V_239 ) ) ;
F_49 ( V_13 , V_20 ) ;
}
}
}
return 0 ;
}
static void F_101 ( struct V_12 * V_206 ,
struct V_67 * V_207 ,
struct V_67 * V_240 )
{
static const char * V_241 [] = {
[ V_133 ] = L_43 ,
[ V_134 ] = L_44 ,
} ;
struct V_12 * V_189 = V_206 -> V_189 ;
F_36 ( L_45
L_46 ,
V_241 [ V_189 -> V_85 ] ,
F_15 ( V_189 -> V_59 ) ,
V_207 -> V_83 ,
V_241 [ V_206 -> V_85 ] ,
F_15 ( V_206 -> V_59 ) ,
V_240 -> V_83 ,
F_24 ( V_189 , V_207 ) ,
F_24 ( V_206 , V_240 ) ) ;
}
static int F_102 ( struct V_12 * V_206 ,
struct V_67 * V_207 ,
struct V_67 * V_240 )
{
int V_17 = 0 ;
struct V_12 * V_189 = V_206 -> V_189 ;
if ( F_15 ( V_189 -> V_21 -> V_88 . V_233 ) != 0 ) {
V_17 = - V_242 ;
F_13 ( L_47
L_48 ,
F_15 ( V_189 -> V_59 ) ,
V_207 -> V_83 ,
F_15 ( V_206 -> V_59 ) ,
V_240 -> V_83 ,
F_15 ( V_189 -> V_21 -> V_88 . V_233 ) ) ;
} else if ( F_15 ( V_189 -> V_21 -> V_88 . V_243 ) == 0 ) {
memcpy ( V_189 -> V_21 -> V_88 . V_243 , V_189 -> V_59 ,
V_87 ) ;
memcpy ( V_189 -> V_21 -> V_88 . V_244 , V_206 -> V_59 ,
V_87 ) ;
} else if ( ( ( F_15 ( V_189 -> V_21 -> V_88 . V_243 ) ==
F_15 ( V_189 -> V_59 ) ) ||
( F_15 ( V_189 -> V_21 -> V_88 . V_243 ) ==
F_15 ( V_206 -> V_59 ) ) )
&&
( ( F_15 ( V_189 -> V_21 -> V_88 . V_244 ) ==
F_15 ( V_189 -> V_59 ) ) ||
( F_15 ( V_189 -> V_21 -> V_88 . V_244 ) ==
F_15 ( V_206 -> V_59 ) ) ) )
;
else {
V_17 = - V_242 ;
F_13 ( L_49
L_50 ,
F_15 ( V_189 -> V_59 ) ,
V_207 -> V_83 ,
F_15 ( V_206 -> V_59 ) ,
V_240 -> V_83 ) ;
}
return V_17 ;
}
static int F_103 ( struct V_12 * V_206 )
{
struct V_90 * V_245 = & V_206 -> V_26 ;
struct V_90 * V_208 ;
int V_20 ;
int V_17 = 0 ;
if ( ! V_206 -> V_189 )
return 0 ;
if ( V_206 -> V_189 -> V_85 != V_133 &&
V_206 -> V_189 -> V_85 != V_134 )
return 0 ;
V_208 = & V_206 -> V_189 -> V_26 ;
for ( V_20 = 0 ; V_20 < V_208 -> V_143 ; V_20 ++ ) {
struct V_67 * V_207 = & V_208 -> V_67 [ V_20 ] ;
struct V_67 * V_240 ;
if ( V_207 -> V_98 == V_99 ||
V_207 -> V_98 == V_100 )
continue;
if ( F_15 ( V_207 -> V_103 ) != F_15 ( V_206 -> V_59 ) )
continue;
V_240 = & V_245 -> V_67 [ V_207 -> V_111 ] ;
switch ( V_206 -> V_189 -> V_85 ) {
case V_133 :
if ( V_206 -> V_85 == V_134 ) {
if ( V_207 -> V_69 != V_73 ||
V_240 -> V_69 != V_70 ) {
F_101 ( V_206 , V_207 , V_240 ) ;
V_17 = - V_242 ;
}
} else if ( V_207 -> V_69 == V_73 ) {
if ( V_240 -> V_69 == V_73 ) {
V_17 = F_102 ( V_206 , V_207 , V_240 ) ;
} else if ( V_240 -> V_69 != V_70 ) {
F_101 ( V_206 , V_207 , V_240 ) ;
V_17 = - V_242 ;
}
} else if ( V_207 -> V_69 == V_70 ) {
if ( V_240 -> V_69 == V_73 ||
( V_240 -> V_69 == V_70 &&
V_245 -> V_71 && V_208 -> V_71 ) ) {
;
} else {
F_101 ( V_206 , V_207 , V_240 ) ;
V_17 = - V_242 ;
}
}
break;
case V_134 :
if ( V_207 -> V_69 != V_70 ||
V_240 -> V_69 != V_73 ) {
F_101 ( V_206 , V_207 , V_240 ) ;
V_17 = - V_242 ;
}
break;
default:
break;
}
}
return V_17 ;
}
static int F_104 ( struct V_12 * V_13 , int V_83 ,
T_1 * V_59 , int * V_246 , int * V_247 )
{
int V_20 , V_17 = 0 ;
struct V_90 * V_91 = & V_13 -> V_26 ;
struct V_67 * V_68 = & V_91 -> V_67 [ V_83 ] ;
T_1 * V_248 ;
T_1 * V_249 ;
* V_247 = 0 ;
* V_246 = 0 ;
V_248 = F_21 ( V_250 ) ;
if ( ! V_248 )
return - V_32 ;
V_249 = F_23 ( V_251 ) ;
if ( ! V_249 ) {
F_38 ( V_248 ) ;
return - V_32 ;
}
V_248 [ 1 ] = V_252 ;
V_248 [ 9 ] = V_83 ;
for ( V_20 = 0 ; V_20 < V_91 -> V_148 ; V_20 ++ ) {
* ( V_253 * ) ( V_248 + 6 ) = F_105 ( V_20 ) ;
V_17 = F_19 ( V_13 , V_248 , V_250 , V_249 ,
V_251 ) ;
if ( V_17 )
goto V_105;
V_17 = V_249 [ 2 ] ;
if ( V_17 == V_254 ) {
F_13 ( L_51
L_52 ,
F_15 ( V_13 -> V_59 ) , V_83 , V_20 ) ;
goto V_105;
} else if ( V_17 != V_101 ) {
F_13 ( L_53
L_54 , V_58 ,
F_15 ( V_13 -> V_59 ) , V_83 , V_20 , V_17 ) ;
goto V_105;
}
if ( F_15 ( V_59 ) != 0 ) {
if ( F_15 ( V_249 + 16 ) == F_15 ( V_59 ) ) {
* V_246 = V_20 ;
if ( ( V_249 [ 12 ] & 0x80 ) == 0x80 )
* V_247 = 0 ;
else
* V_247 = 1 ;
goto V_105;
} else if ( F_15 ( V_249 + 16 ) == 0 ) {
* V_246 = V_20 ;
* V_247 = 0 ;
goto V_105;
}
} else if ( F_15 ( V_249 + 16 ) == 0 &&
V_68 -> V_115 < V_20 ) {
V_68 -> V_115 = V_20 ;
* V_246 = V_20 ;
* V_247 = 0 ;
goto V_105;
}
}
V_17 = - 1 ;
V_105:
F_38 ( V_248 ) ;
F_38 ( V_249 ) ;
return V_17 ;
}
static int F_106 ( struct V_12 * V_13 , int V_83 ,
T_1 * V_59 , int V_246 , int include )
{
int V_17 ;
T_1 * V_255 ;
T_1 * V_256 ;
V_255 = F_21 ( V_257 ) ;
if ( ! V_255 )
return - V_32 ;
V_256 = F_23 ( V_258 ) ;
if ( ! V_256 ) {
F_38 ( V_255 ) ;
return - V_32 ;
}
V_255 [ 1 ] = V_259 ;
* ( V_253 * ) ( V_255 + 6 ) = F_105 ( V_246 ) ;
V_255 [ 9 ] = V_83 ;
if ( F_15 ( V_59 ) == 0 || ! include )
V_255 [ 12 ] |= 0x80 ;
memcpy ( V_255 + 16 , V_59 , V_87 ) ;
V_17 = F_19 ( V_13 , V_255 , V_257 , V_256 ,
V_258 ) ;
if ( V_17 )
goto V_105;
V_17 = V_256 [ 2 ] ;
if ( V_17 == V_254 ) {
F_13 ( L_55
L_56 ,
F_15 ( V_13 -> V_59 ) , V_83 , V_246 ) ;
}
V_105:
F_38 ( V_255 ) ;
F_38 ( V_256 ) ;
return V_17 ;
}
static int F_94 ( struct V_12 * V_13 , int V_83 ,
T_1 * V_59 , int include )
{
int V_246 ;
int V_247 ;
int V_17 ;
V_17 = F_104 ( V_13 , V_83 , V_59 , & V_246 , & V_247 ) ;
if ( V_17 )
return V_17 ;
if ( include ^ V_247 )
return F_106 ( V_13 , V_83 , V_59 , V_246 , include ) ;
return V_17 ;
}
static int F_107 ( struct V_12 * V_189 ,
struct V_12 * V_206 ,
T_1 * V_59 , int include )
{
struct V_90 * V_260 = & V_189 -> V_26 ;
int V_17 = 0 ;
int V_20 ;
if ( V_189 -> V_189 ) {
V_17 = F_107 ( V_189 -> V_189 , V_189 , V_59 ,
include ) ;
if ( V_17 )
return V_17 ;
}
if ( V_260 -> V_151 == 0 ) {
F_13 ( L_57 ,
F_15 ( V_189 -> V_59 ) ) ;
return 0 ;
}
for ( V_20 = 0 ; V_20 < V_260 -> V_143 ; V_20 ++ ) {
struct V_67 * V_68 = & V_260 -> V_67 [ V_20 ] ;
if ( ( V_68 -> V_69 == V_70 ) &&
( F_15 ( V_68 -> V_103 ) ==
F_15 ( V_206 -> V_59 ) ) ) {
V_17 = F_94 ( V_189 , V_20 , V_59 , include ) ;
if ( V_17 )
return V_17 ;
}
}
return V_17 ;
}
static int F_95 ( struct V_12 * V_13 , T_1 * V_59 )
{
if ( V_13 -> V_189 )
return F_107 ( V_13 -> V_189 , V_13 , V_59 , 1 ) ;
return 0 ;
}
static int F_96 ( struct V_12 * V_13 , T_1 * V_59 )
{
if ( V_13 -> V_189 )
return F_107 ( V_13 -> V_189 , V_13 , V_59 , 0 ) ;
return 0 ;
}
static int F_90 ( struct V_12 * V_13 )
{
int V_17 ;
V_17 = F_108 ( V_13 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_43 ( V_13 ) ;
if ( V_17 )
goto V_144;
V_17 = F_47 ( V_13 ) ;
if ( V_17 )
goto V_144;
V_17 = F_39 ( V_13 ) ;
if ( V_17 ) {
F_13 ( L_58 ,
F_15 ( V_13 -> V_59 ) , V_17 ) ;
goto V_144;
}
F_100 ( V_13 ) ;
V_17 = F_103 ( V_13 ) ;
if ( V_17 )
goto V_144;
return 0 ;
V_144:
F_109 ( V_13 ) ;
return V_17 ;
}
static int F_110 ( struct V_187 * V_21 , const int V_227 )
{
int V_17 = 0 ;
struct V_12 * V_13 ;
F_52 (dev, &port->dev_list, dev_list_node) {
if ( V_13 -> V_85 == V_133 ||
V_13 -> V_85 == V_134 ) {
struct V_161 * V_91 =
F_46 ( V_13 -> V_93 ) ;
if ( V_227 == V_91 -> V_227 )
V_17 = F_99 ( V_13 , - 1 ) ;
else if ( V_227 > 0 )
V_17 = F_99 ( V_21 -> V_261 , - 1 ) ;
}
}
return V_17 ;
}
static int F_111 ( struct V_187 * V_21 )
{
int V_17 ;
int V_227 ;
do {
V_227 = V_21 -> V_88 . V_228 ;
V_17 = F_110 ( V_21 , V_227 ) ;
F_112 () ;
} while ( V_227 < V_21 -> V_88 . V_228 );
return V_17 ;
}
int F_113 ( struct V_12 * V_13 )
{
int V_17 ;
struct V_161 * V_91 = F_46 ( V_13 -> V_93 ) ;
V_17 = F_89 ( V_13 -> V_93 ) ;
if ( V_17 )
goto V_144;
V_91 -> V_227 = V_13 -> V_21 -> V_88 . V_228 ;
V_17 = F_90 ( V_13 ) ;
if ( V_17 )
goto V_262;
F_111 ( V_13 -> V_21 ) ;
return V_17 ;
V_262:
F_114 ( V_13 -> V_93 ) ;
V_144:
return V_17 ;
}
static int F_115 ( struct V_12 * V_13 ,
int V_83 , struct V_37 * V_138 )
{
int V_17 ;
T_1 * V_137 ;
V_137 = F_21 ( V_140 ) ;
if ( ! V_137 )
return - V_32 ;
V_137 [ 1 ] = V_142 ;
V_137 [ 9 ] = V_83 ;
V_17 = F_19 ( V_13 , V_137 , V_140 ,
V_138 , V_141 ) ;
if ( V_17 )
goto V_105;
else if ( V_138 -> V_96 != V_101 ) {
V_17 = V_138 -> V_96 ;
goto V_105;
}
V_105:
F_38 ( V_137 ) ;
return V_17 ;
}
static int F_116 ( struct V_12 * V_13 ,
int V_83 , int * V_263 )
{
int V_17 ;
struct V_37 * V_138 ;
V_138 = F_23 ( V_141 ) ;
if ( ! V_138 )
return - V_32 ;
V_17 = F_115 ( V_13 , V_83 , V_138 ) ;
if ( ! V_17 )
* V_263 = V_138 -> V_88 . V_113 ;
F_38 ( V_138 ) ;
return V_17 ;
}
static int F_117 ( struct V_12 * V_13 , int V_83 ,
T_1 * V_59 , enum V_74 * type )
{
int V_17 ;
struct V_37 * V_138 ;
struct V_75 * V_76 ;
V_138 = F_23 ( V_141 ) ;
if ( ! V_138 )
return - V_32 ;
V_76 = & V_138 -> V_88 ;
V_17 = F_115 ( V_13 , V_83 , V_138 ) ;
if ( V_17 == 0 ) {
memcpy ( V_59 , V_138 -> V_88 . V_103 , 8 ) ;
* type = F_25 ( V_76 ) ;
if ( * type == 0 )
memset ( V_59 , 0 , 8 ) ;
}
F_38 ( V_138 ) ;
return V_17 ;
}
static int F_118 ( struct V_12 * V_13 , int * V_83 ,
int V_264 , bool V_265 )
{
struct V_90 * V_91 = & V_13 -> V_26 ;
int V_17 = 0 ;
int V_20 ;
for ( V_20 = V_264 ; V_20 < V_91 -> V_143 ; V_20 ++ ) {
int V_112 = 0 ;
V_17 = F_116 ( V_13 , V_20 , & V_112 ) ;
switch ( V_17 ) {
case V_97 :
case V_266 :
continue;
case V_101 :
break;
default:
return V_17 ;
}
if ( V_112 != V_91 -> V_67 [ V_20 ] . V_112 ) {
if ( V_265 )
V_91 -> V_67 [ V_20 ] . V_112 =
V_112 ;
* V_83 = V_20 ;
return 0 ;
}
}
return 0 ;
}
static int F_119 ( struct V_12 * V_13 , int * V_267 )
{
int V_17 ;
T_1 * V_154 ;
struct V_37 * V_155 ;
V_154 = F_21 ( V_156 ) ;
if ( ! V_154 )
return - V_32 ;
V_155 = F_23 ( V_157 ) ;
if ( ! V_155 ) {
F_38 ( V_154 ) ;
return - V_32 ;
}
V_154 [ 1 ] = V_158 ;
V_17 = F_19 ( V_13 , V_154 , V_156 , V_155 ,
V_157 ) ;
if ( V_17 )
goto V_105;
if ( V_155 -> V_96 != V_101 ) {
V_17 = V_155 -> V_96 ;
goto V_105;
}
* V_267 = F_41 ( V_155 -> V_146 . V_113 ) ;
V_105:
F_38 ( V_155 ) ;
F_38 ( V_154 ) ;
return V_17 ;
}
static int F_120 ( struct V_12 * V_13 ,
struct V_12 * * V_268 )
{
struct V_90 * V_91 = & V_13 -> V_26 ;
int V_147 = - 1 ;
int V_83 = - 1 ;
int V_17 ;
struct V_12 * V_269 ;
V_17 = F_119 ( V_13 , & V_147 ) ;
if ( V_17 )
goto V_105;
if ( V_147 != - 1 && V_147 != V_91 -> V_147 ) {
V_17 = F_118 ( V_13 , & V_83 , 0 , false ) ;
if ( V_83 != - 1 ) {
* V_268 = V_13 ;
V_91 -> V_147 = V_147 ;
F_13 ( L_59 ) ;
return V_17 ;
} else
F_13 ( L_60 ) ;
}
F_52 (ch, &ex->children, siblings) {
if ( V_269 -> V_85 == V_133 || V_269 -> V_85 == V_134 ) {
V_17 = F_120 ( V_269 , V_268 ) ;
if ( * V_268 )
return V_17 ;
}
}
V_105:
return V_17 ;
}
static void F_121 ( struct V_187 * V_21 , struct V_12 * V_13 )
{
struct V_90 * V_91 = & V_13 -> V_26 ;
struct V_12 * V_206 , * V_270 ;
F_122 (child, n, &ex->children, siblings) {
F_31 ( V_28 , & V_206 -> V_29 ) ;
if ( V_206 -> V_85 == V_133 ||
V_206 -> V_85 == V_134 )
F_121 ( V_21 , V_206 ) ;
else
F_123 ( V_21 , V_206 ) ;
}
F_123 ( V_21 , V_13 ) ;
}
static void F_124 ( struct V_12 * V_189 ,
int V_83 , bool V_271 )
{
struct V_90 * V_26 = & V_189 -> V_26 ;
struct V_67 * V_68 = & V_26 -> V_67 [ V_83 ] ;
struct V_12 * V_206 , * V_270 , * V_272 = NULL ;
if ( V_271 ) {
F_122 (child, n,
&ex_dev->children, siblings) {
if ( F_15 ( V_206 -> V_59 ) ==
F_15 ( V_68 -> V_103 ) ) {
F_31 ( V_28 , & V_206 -> V_29 ) ;
if ( V_206 -> V_85 == V_133 ||
V_206 -> V_85 == V_134 )
F_121 ( V_189 -> V_21 , V_206 ) ;
else
F_123 ( V_189 -> V_21 , V_206 ) ;
V_272 = V_206 ;
break;
}
}
F_96 ( V_189 , V_68 -> V_103 ) ;
}
memset ( V_68 -> V_103 , 0 , V_87 ) ;
if ( V_68 -> V_21 ) {
F_125 ( V_68 -> V_21 , V_68 -> V_68 ) ;
F_68 ( V_272 , V_68 -> V_21 ) ;
if ( V_68 -> V_21 -> V_143 == 0 )
F_83 ( V_68 -> V_21 ) ;
V_68 -> V_21 = NULL ;
}
}
static int F_126 ( struct V_12 * V_273 ,
const int V_227 )
{
struct V_90 * V_274 = & V_273 -> V_26 ;
struct V_12 * V_206 ;
int V_17 = 0 ;
F_52 (child, &ex_root->children, siblings) {
if ( V_206 -> V_85 == V_133 ||
V_206 -> V_85 == V_134 ) {
struct V_161 * V_91 =
F_46 ( V_206 -> V_93 ) ;
if ( V_227 > V_91 -> V_227 )
V_17 = F_126 ( V_206 ,
V_227 ) ;
else if ( V_227 == V_91 -> V_227 )
V_17 = F_99 ( V_206 , - 1 ) ;
}
}
return V_17 ;
}
static int F_127 ( struct V_12 * V_13 )
{
int V_17 ;
struct V_161 * V_91 = F_46 ( V_13 -> V_93 ) ;
int V_227 = V_91 -> V_227 + 1 ;
V_17 = F_99 ( V_13 , - 1 ) ;
if ( V_17 )
goto V_105;
do {
V_17 = F_126 ( V_13 , V_227 ) ;
F_112 () ;
V_227 += 1 ;
} while ( V_227 <= V_13 -> V_21 -> V_88 . V_228 );
V_105:
return V_17 ;
}
static int F_128 ( struct V_12 * V_13 , int V_83 )
{
struct V_67 * V_67 = & V_13 -> V_26 . V_67 [ V_83 ] ;
struct V_12 * V_206 ;
int V_17 ;
F_13 ( L_61 ,
F_15 ( V_13 -> V_59 ) , V_83 ) ;
V_17 = F_37 ( V_13 , V_83 ) ;
if ( V_17 )
return V_17 ;
if ( F_85 ( V_13 , V_83 ) )
return 0 ;
V_17 = F_99 ( V_13 , V_83 ) ;
if ( V_17 )
return V_17 ;
F_52 (child, &dev->ex_dev.children, siblings) {
if ( F_15 ( V_206 -> V_59 ) ==
F_15 ( V_67 -> V_103 ) ) {
if ( V_206 -> V_85 == V_133 ||
V_206 -> V_85 == V_134 )
V_17 = F_127 ( V_206 ) ;
break;
}
}
return V_17 ;
}
static bool F_129 ( enum V_74 V_275 , enum V_74 V_276 )
{
if ( V_276 == V_275 )
return true ;
if ( ( V_276 == V_82 && V_275 == V_132 ) ||
( V_276 == V_132 && V_275 == V_82 ) )
return true ;
return false ;
}
static int F_130 ( struct V_12 * V_13 , int V_83 , bool V_271 )
{
struct V_90 * V_91 = & V_13 -> V_26 ;
struct V_67 * V_68 = & V_91 -> V_67 [ V_83 ] ;
enum V_74 type = V_78 ;
T_1 V_59 [ 8 ] ;
int V_17 ;
memset ( V_59 , 0 , 8 ) ;
V_17 = F_117 ( V_13 , V_83 , V_59 , & type ) ;
switch ( V_17 ) {
case V_266 :
V_68 -> V_98 = V_100 ;
F_124 ( V_13 , V_83 , V_271 ) ;
return V_17 ;
case V_97 :
V_68 -> V_98 = V_99 ;
F_124 ( V_13 , V_83 , V_271 ) ;
return V_17 ;
case V_101 :
break;
case - V_30 :
break;
default:
return V_17 ;
}
if ( ( F_15 ( V_59 ) == 0 ) || ( V_17 == - V_30 ) ) {
V_68 -> V_98 = V_102 ;
F_124 ( V_13 , V_83 , V_271 ) ;
return V_17 ;
} else if ( F_15 ( V_59 ) == F_15 ( V_68 -> V_103 ) &&
F_129 ( type , V_68 -> V_77 ) ) {
struct V_12 * V_277 = F_32 ( V_13 , V_83 ) ;
char * V_278 = L_16 ;
F_37 ( V_13 , V_83 ) ;
if ( V_277 && V_68 -> V_77 == V_82 )
V_278 = L_62 ;
F_13 ( L_63 ,
F_15 ( V_13 -> V_59 ) , V_83 , V_278 ) ;
return V_17 ;
}
if ( F_15 ( V_68 -> V_103 ) &&
F_15 ( V_59 ) != F_15 ( V_68 -> V_103 ) ) {
F_13 ( L_64 ,
F_15 ( V_13 -> V_59 ) , V_83 ,
F_15 ( V_68 -> V_103 ) ) ;
F_124 ( V_13 , V_83 , V_271 ) ;
}
return F_128 ( V_13 , V_83 ) ;
}
static int F_131 ( struct V_12 * V_13 , const int V_83 )
{
struct V_90 * V_91 = & V_13 -> V_26 ;
struct V_67 * V_279 = & V_91 -> V_67 [ V_83 ] ;
int V_17 = 0 ;
int V_20 ;
bool V_271 = true ;
F_13 ( L_65 ,
F_15 ( V_13 -> V_59 ) , V_83 ) ;
if ( F_15 ( V_279 -> V_103 ) != 0 ) {
for ( V_20 = 0 ; V_20 < V_91 -> V_143 ; V_20 ++ ) {
struct V_67 * V_68 = & V_91 -> V_67 [ V_20 ] ;
if ( V_20 == V_83 )
continue;
if ( F_15 ( V_68 -> V_103 ) ==
F_15 ( V_279 -> V_103 ) ) {
F_13 ( L_66
L_67 , V_83 , V_20 ) ;
V_271 = false ;
break;
}
}
V_17 = F_130 ( V_13 , V_83 , V_271 ) ;
} else
V_17 = F_128 ( V_13 , V_83 ) ;
return V_17 ;
}
int F_132 ( struct V_12 * V_261 )
{
int V_17 ;
struct V_12 * V_13 = NULL ;
V_17 = F_120 ( V_261 , & V_13 ) ;
while ( V_17 == 0 && V_13 ) {
struct V_90 * V_91 = & V_13 -> V_26 ;
int V_20 = 0 , V_83 ;
do {
V_83 = - 1 ;
V_17 = F_118 ( V_13 , & V_83 , V_20 , true ) ;
if ( V_83 == - 1 )
break;
V_17 = F_131 ( V_13 , V_83 ) ;
V_20 = V_83 + 1 ;
} while ( V_20 < V_91 -> V_143 );
V_13 = NULL ;
V_17 = F_120 ( V_261 , & V_13 ) ;
}
return V_17 ;
}
void F_133 ( struct V_280 * V_281 , struct V_282 * V_24 ,
struct V_92 * V_93 )
{
struct V_12 * V_13 ;
unsigned int V_283 = 0 ;
int V_284 = - V_285 ;
if ( ! V_93 )
return F_134 ( V_281 , V_24 ) ;
switch ( V_93 -> V_116 . V_118 ) {
case V_133 :
case V_134 :
break;
default:
F_135 ( L_68 ,
V_58 ) ;
goto V_105;
}
V_13 = F_33 ( V_93 ) ;
if ( ! V_13 ) {
F_135 ( L_69 , V_58 ) ;
goto V_105;
}
if ( V_281 -> V_286 . V_287 > 1 ||
V_281 -> V_288 . V_287 > 1 ) {
F_135 ( L_70 ,
V_58 , V_281 -> V_286 . V_289 ,
V_281 -> V_288 . V_289 ) ;
goto V_105;
}
V_284 = F_7 ( V_13 , V_281 -> V_286 . V_290 ,
V_281 -> V_288 . V_290 ) ;
if ( V_284 > 0 ) {
V_283 = V_284 ;
V_284 = 0 ;
}
V_105:
F_136 ( V_281 , V_284 , V_283 ) ;
}
