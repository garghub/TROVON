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
static int F_7 ( struct V_12 * V_13 , void * V_14 , int V_15 ,
void * V_16 , int V_17 )
{
int V_18 , V_19 ;
struct V_2 * V_3 = NULL ;
struct V_20 * V_21 =
F_8 ( V_13 -> V_22 -> V_23 -> V_24 . V_25 -> V_26 ) ;
F_9 ( & V_13 -> V_27 . V_28 ) ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ ) {
if ( F_10 ( V_29 , & V_13 -> V_30 ) ) {
V_18 = - V_31 ;
break;
}
V_3 = F_11 ( V_32 ) ;
if ( ! V_3 ) {
V_18 = - V_33 ;
break;
}
V_3 -> V_13 = V_13 ;
V_3 -> V_34 = V_13 -> V_35 ;
F_12 ( & V_3 -> V_36 . V_37 , V_14 , V_15 ) ;
F_12 ( & V_3 -> V_36 . V_38 , V_16 , V_17 ) ;
V_3 -> V_39 = F_5 ;
V_3 -> V_9 -> V_11 . V_40 = ( unsigned long ) V_3 ;
V_3 -> V_9 -> V_11 . V_41 = F_1 ;
V_3 -> V_9 -> V_11 . V_42 = V_43 + V_44 * V_45 ;
F_13 ( & V_3 -> V_9 -> V_11 ) ;
V_18 = V_21 -> V_46 -> V_47 ( V_3 , 1 , V_32 ) ;
if ( V_18 ) {
F_6 ( & V_3 -> V_9 -> V_11 ) ;
F_14 ( L_1 , V_18 ) ;
break;
}
F_15 ( & V_3 -> V_9 -> V_10 ) ;
V_18 = - V_31 ;
if ( ( V_3 -> V_6 & V_8 ) ) {
F_14 ( L_2 ) ;
V_21 -> V_46 -> V_48 ( V_3 ) ;
if ( ! ( V_3 -> V_6 & V_7 ) ) {
F_14 ( L_3 ) ;
break;
}
}
if ( V_3 -> V_49 . V_16 == V_50 &&
V_3 -> V_49 . V_51 == V_52 ) {
V_18 = 0 ;
break;
}
if ( V_3 -> V_49 . V_16 == V_50 &&
V_3 -> V_49 . V_51 == V_53 ) {
V_18 = V_3 -> V_49 . V_54 ;
break;
}
if ( V_3 -> V_49 . V_16 == V_50 &&
V_3 -> V_49 . V_51 == V_55 ) {
V_18 = - V_56 ;
break;
}
if ( V_3 -> V_49 . V_16 == V_57 &&
V_3 -> V_49 . V_51 == V_58 )
break;
else {
F_14 ( L_4
L_5 , V_59 ,
F_16 ( V_13 -> V_60 ) ,
V_3 -> V_49 . V_16 ,
V_3 -> V_49 . V_51 ) ;
F_17 ( V_3 ) ;
V_3 = NULL ;
}
}
F_18 ( & V_13 -> V_27 . V_28 ) ;
F_19 ( V_19 == 3 && V_3 != NULL ) ;
F_17 ( V_3 ) ;
return V_18 ;
}
static inline void * F_20 ( int V_61 )
{
T_1 * V_62 = F_21 ( V_61 , V_32 ) ;
if ( V_62 )
V_62 [ 0 ] = V_63 ;
return V_62 ;
}
static inline void * F_22 ( int V_61 )
{
return F_21 ( V_61 , V_32 ) ;
}
static char F_23 ( struct V_12 * V_13 , struct V_64 * V_65 )
{
switch ( V_65 -> V_66 ) {
case V_67 :
if ( V_13 -> V_27 . V_68 )
return 'U' ;
else
return 'T' ;
case V_69 :
return 'D' ;
case V_70 :
return 'S' ;
default:
return '?' ;
}
}
static enum V_71 F_24 ( struct V_72 * V_73 )
{
if ( V_73 -> V_74 == V_75 && V_73 -> V_76 &&
V_73 -> V_77 >= V_78 )
return V_79 ;
else
return V_73 -> V_74 ;
}
static void F_25 ( struct V_12 * V_13 , int V_80 , void * V_81 )
{
enum V_71 V_82 ;
enum V_83 V_77 ;
T_1 V_60 [ V_84 ] ;
struct V_38 * V_16 = V_81 ;
struct V_72 * V_73 = & V_16 -> V_85 ;
struct V_86 * V_23 = V_13 -> V_22 -> V_23 ;
struct V_87 * V_88 = & V_13 -> V_27 ;
struct V_64 * V_65 = & V_88 -> V_64 [ V_80 ] ;
struct V_89 * V_90 = V_13 -> V_90 ;
bool V_91 = ! V_65 -> V_65 ;
char * type ;
if ( V_91 ) {
if ( F_26 ( F_10 ( V_92 , & V_23 -> V_30 ) ) )
return;
V_65 -> V_65 = F_27 ( & V_90 -> V_13 , V_80 ) ;
F_19 ( ! V_65 -> V_65 ) ;
}
switch ( V_16 -> V_93 ) {
case V_94 :
V_65 -> V_95 = V_96 ;
break;
default:
V_65 -> V_95 = V_97 ;
break;
case V_98 :
V_65 -> V_95 = V_99 ;
break;
}
V_82 = V_65 -> V_74 ;
V_77 = V_65 -> V_77 ;
memcpy ( V_60 , V_65 -> V_100 , V_84 ) ;
if ( V_65 -> V_95 == V_96 ) {
memset ( V_65 -> V_100 , 0 , V_84 ) ;
V_65 -> V_74 = V_75 ;
if ( ! F_10 ( V_92 , & V_23 -> V_30 ) ) {
V_65 -> V_80 = V_80 ;
goto V_101;
} else
goto V_102;
}
V_65 -> V_74 = F_24 ( V_73 ) ;
if ( F_10 ( V_92 , & V_23 -> V_30 ) )
goto V_102;
V_65 -> V_80 = V_80 ;
V_65 -> V_77 = V_73 -> V_77 ;
V_65 -> V_103 = V_73 -> V_103 ;
V_65 -> V_76 = V_73 -> V_76 ;
V_65 -> V_104 = V_73 -> V_104 ;
V_65 -> V_105 = V_73 -> V_106 << 1 ;
V_65 -> V_107 = V_73 -> V_35 << 1 ;
if ( V_65 -> V_74 == V_75 ||
V_65 -> V_77 < V_78 )
memset ( V_65 -> V_100 , 0 , V_84 ) ;
else
memcpy ( V_65 -> V_100 , V_73 -> V_100 , V_84 ) ;
V_65 -> V_108 = V_73 -> V_108 ;
V_65 -> V_109 = V_73 -> V_110 ;
V_65 -> V_66 = V_73 -> V_66 ;
V_65 -> V_111 = V_73 -> V_111 ;
V_65 -> V_112 = - 1 ;
V_65 -> V_65 -> V_113 . V_114 = F_16 ( V_65 -> V_100 ) ;
V_65 -> V_65 -> V_113 . V_115 = V_73 -> V_74 ;
V_65 -> V_65 -> V_113 . V_116 = V_65 -> V_105 ;
V_65 -> V_65 -> V_113 . V_117 = V_65 -> V_107 ;
if ( ! V_65 -> V_107 && V_73 -> V_76 )
V_65 -> V_65 -> V_113 . V_117 = V_118 ;
V_65 -> V_65 -> V_113 . V_119 = V_80 ;
V_65 -> V_65 -> V_120 = V_73 -> V_121 ;
V_65 -> V_65 -> V_122 = V_73 -> V_123 ;
V_65 -> V_65 -> V_124 = V_73 -> V_125 ;
V_65 -> V_65 -> V_126 = V_73 -> V_127 ;
V_65 -> V_65 -> V_128 = V_65 -> V_77 ;
V_101:
if ( V_91 )
if ( F_28 ( V_65 -> V_65 ) ) {
F_29 ( V_65 -> V_65 ) ;
return;
}
V_102:
switch ( V_65 -> V_74 ) {
case V_79 :
type = L_6 ;
break;
case V_75 :
type = L_7 ;
break;
case V_129 :
if ( V_65 -> V_105 ) {
if ( V_65 -> V_107 )
type = L_8 ;
else
type = L_9 ;
} else {
if ( V_73 -> V_76 )
type = L_10 ;
else
type = L_11 ;
}
break;
case V_130 :
case V_131 :
type = L_12 ;
break;
default:
type = L_13 ;
}
if ( V_91 || V_65 -> V_74 != V_82 ||
V_65 -> V_77 != V_77 ||
F_16 ( V_65 -> V_100 ) != F_16 ( V_60 ) )
;
else
return;
if ( F_10 ( V_92 , & V_23 -> V_30 ) )
F_30 ( V_132 , & V_13 -> V_22 -> V_85 . V_133 ) ;
F_14 ( L_14 ,
F_10 ( V_92 , & V_23 -> V_30 ) ? L_15 : L_16 ,
F_16 ( V_13 -> V_60 ) , V_65 -> V_80 ,
F_23 ( V_13 , V_65 ) , V_65 -> V_77 ,
F_16 ( V_65 -> V_100 ) , type ) ;
}
struct V_12 * F_31 ( struct V_12 * V_27 , int V_80 )
{
struct V_64 * V_64 = & V_27 -> V_27 . V_64 [ V_80 ] ;
struct V_12 * V_13 ;
struct V_89 * V_90 ;
if ( ! V_64 -> V_22 )
return NULL ;
V_90 = V_64 -> V_22 -> V_90 ;
if ( ! V_90 )
return NULL ;
V_13 = F_32 ( V_90 ) ;
if ( V_13 && F_33 ( V_13 ) )
return V_13 ;
return NULL ;
}
static int F_34 ( struct V_12 * V_13 , T_1 * V_134 ,
T_1 * V_135 , int V_136 )
{
struct V_72 * V_73 ;
int V_18 ;
V_134 [ 9 ] = V_136 ;
V_18 = F_7 ( V_13 , V_134 , V_137 ,
V_135 , V_138 ) ;
if ( V_18 )
return V_18 ;
V_73 = & ( (struct V_38 * ) V_135 ) -> V_85 ;
if ( memcmp ( V_13 -> V_60 , V_73 -> V_100 , V_84 ) == 0 ) {
F_35 ( L_17 ) ;
return 0 ;
}
F_25 ( V_13 , V_136 , V_135 ) ;
return 0 ;
}
int F_36 ( struct V_12 * V_13 , int V_136 )
{
struct V_87 * V_88 = & V_13 -> V_27 ;
int V_18 = 0 ;
T_1 * V_134 ;
T_1 * V_135 ;
V_134 = F_20 ( V_137 ) ;
if ( ! V_134 )
return - V_33 ;
V_135 = F_22 ( V_138 ) ;
if ( ! V_135 ) {
F_37 ( V_134 ) ;
return - V_33 ;
}
V_134 [ 1 ] = V_139 ;
if ( 0 <= V_136 && V_136 < V_88 -> V_140 ) {
V_18 = F_34 ( V_13 , V_134 , V_135 , V_136 ) ;
} else {
int V_21 ;
for ( V_21 = 0 ; V_21 < V_88 -> V_140 ; V_21 ++ ) {
V_18 = F_34 ( V_13 , V_134 ,
V_135 , V_21 ) ;
if ( V_18 )
goto V_141;
}
}
V_141:
F_37 ( V_135 ) ;
F_37 ( V_134 ) ;
return V_18 ;
}
static int F_38 ( struct V_12 * V_13 )
{
struct V_87 * V_88 = & V_13 -> V_27 ;
int V_18 = - V_33 ;
V_88 -> V_64 = F_21 ( sizeof( * V_88 -> V_64 ) * V_88 -> V_140 , V_32 ) ;
if ( ! V_88 -> V_64 )
return - V_33 ;
V_18 = F_36 ( V_13 , - 1 ) ;
if ( V_18 )
goto V_141;
return 0 ;
V_141:
F_37 ( V_88 -> V_64 ) ;
V_88 -> V_64 = NULL ;
return V_18 ;
}
static void F_39 ( struct V_12 * V_13 ,
struct V_38 * V_16 )
{
struct V_142 * V_143 = & V_16 -> V_143 ;
V_13 -> V_27 . V_144 = F_40 ( V_143 -> V_110 ) ;
V_13 -> V_27 . V_145 = F_40 ( V_143 -> V_146 ) ;
V_13 -> V_27 . V_140 = F_41 ( V_143 -> V_140 , ( T_1 ) V_147 ) ;
V_13 -> V_27 . V_68 = V_143 -> V_68 ;
V_13 -> V_27 . V_148 = V_143 -> V_148 ;
V_13 -> V_27 . V_149 = V_143 -> V_149 ;
memcpy ( V_13 -> V_27 . V_150 , V_143 -> V_150 , 8 ) ;
}
static int F_42 ( struct V_12 * V_13 )
{
T_1 * V_151 ;
struct V_38 * V_152 ;
int V_18 ;
int V_21 ;
V_151 = F_20 ( V_153 ) ;
if ( ! V_151 )
return - V_33 ;
V_152 = F_22 ( V_154 ) ;
if ( ! V_152 ) {
F_37 ( V_151 ) ;
return - V_33 ;
}
V_151 [ 1 ] = V_155 ;
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ ) {
V_18 = F_7 ( V_13 , V_151 , V_153 , V_152 ,
V_154 ) ;
if ( V_18 ) {
F_14 ( L_18 ,
F_16 ( V_13 -> V_60 ) , V_18 ) ;
goto V_102;
} else if ( V_152 -> V_93 != V_98 ) {
F_14 ( L_19 ,
F_16 ( V_13 -> V_60 ) , V_152 -> V_93 ) ;
V_18 = V_152 -> V_93 ;
goto V_102;
}
F_39 ( V_13 , V_152 ) ;
if ( V_13 -> V_27 . V_149 ) {
F_14 ( L_20 ,
F_16 ( V_13 -> V_60 ) ) ;
F_43 ( 5 * V_45 ) ;
} else
break;
}
V_102:
F_37 ( V_151 ) ;
F_37 ( V_152 ) ;
return V_18 ;
}
static void F_44 ( struct V_12 * V_13 , void
* V_156 )
{
T_1 * V_157 = V_156 ;
struct V_89 * V_90 = V_13 -> V_90 ;
struct V_158 * V_159 = F_45 ( V_90 ) ;
memcpy ( V_159 -> V_160 , V_157 + 12 , V_161 ) ;
memcpy ( V_159 -> V_162 , V_157 + 20 , V_163 ) ;
memcpy ( V_159 -> V_164 , V_157 + 36 ,
V_165 ) ;
if ( V_157 [ 8 ] & 1 ) {
memcpy ( V_159 -> V_166 , V_157 + 40 ,
V_167 ) ;
V_159 -> V_168 = V_157 [ 48 ] << 8 | V_157 [ 49 ] ;
V_159 -> V_169 = V_157 [ 50 ] ;
}
}
static int F_46 ( struct V_12 * V_13 )
{
T_1 * V_170 ;
T_1 * V_157 ;
int V_18 ;
V_170 = F_20 ( V_171 ) ;
if ( ! V_170 )
return - V_33 ;
V_157 = F_22 ( V_172 ) ;
if ( ! V_157 ) {
F_37 ( V_170 ) ;
return - V_33 ;
}
V_170 [ 1 ] = V_173 ;
V_18 = F_7 ( V_13 , V_170 , V_171 , V_157 , V_172 ) ;
if ( V_18 ) {
F_14 ( L_21 ,
F_16 ( V_13 -> V_60 ) , V_18 ) ;
goto V_102;
} else if ( V_157 [ 2 ] != V_98 ) {
F_14 ( L_22 ,
F_16 ( V_13 -> V_60 ) , V_157 [ 2 ] ) ;
goto V_102;
}
F_44 ( V_13 , V_157 ) ;
V_102:
F_37 ( V_170 ) ;
F_37 ( V_157 ) ;
return V_18 ;
}
int F_47 ( struct V_12 * V_13 , int V_80 ,
enum V_174 V_174 ,
struct V_175 * V_176 )
{
T_1 * V_177 ;
T_1 * V_178 ;
int V_18 ;
V_177 = F_20 ( V_179 ) ;
if ( ! V_177 )
return - V_33 ;
V_178 = F_22 ( V_180 ) ;
if ( ! V_178 ) {
F_37 ( V_177 ) ;
return - V_33 ;
}
V_177 [ 1 ] = V_181 ;
V_177 [ 9 ] = V_80 ;
V_177 [ 10 ] = V_174 ;
if ( V_176 ) {
V_177 [ 32 ] = V_176 -> V_124 << 4 ;
V_177 [ 33 ] = V_176 -> V_126 << 4 ;
}
V_18 = F_7 ( V_13 , V_177 , V_179 , V_178 , V_180 ) ;
F_37 ( V_178 ) ;
F_37 ( V_177 ) ;
return V_18 ;
}
static void F_48 ( struct V_12 * V_13 , int V_80 )
{
struct V_87 * V_88 = & V_13 -> V_27 ;
struct V_64 * V_65 = & V_88 -> V_64 [ V_80 ] ;
F_47 ( V_13 , V_80 , V_182 , NULL ) ;
V_65 -> V_77 = V_183 ;
}
static void F_49 ( struct V_12 * V_13 , T_1 * V_60 )
{
struct V_87 * V_88 = & V_13 -> V_27 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_88 -> V_140 ; V_21 ++ ) {
struct V_64 * V_65 = & V_88 -> V_64 [ V_21 ] ;
if ( V_65 -> V_95 == V_96 ||
V_65 -> V_95 == V_97 )
continue;
if ( F_16 ( V_65 -> V_100 ) == F_16 ( V_60 ) )
F_48 ( V_13 , V_21 ) ;
}
}
static int F_50 ( struct V_184 * V_22 ,
T_1 * V_60 )
{
struct V_12 * V_13 ;
if ( F_16 ( V_22 -> V_60 ) == F_16 ( V_60 ) )
return 1 ;
F_51 (dev, &port->dev_list, dev_list_node) {
if ( F_16 ( V_13 -> V_60 ) == F_16 ( V_60 ) )
return 1 ;
}
return 0 ;
}
int F_52 ( struct V_185 * V_65 )
{
int V_18 ;
T_1 * V_14 ;
T_1 * V_16 ;
struct V_89 * V_90 = F_53 ( V_65 -> V_13 . V_186 ) ;
struct V_12 * V_13 = F_32 ( V_90 ) ;
V_14 = F_20 ( V_187 ) ;
if ( ! V_14 )
return - V_33 ;
V_16 = F_22 ( V_188 ) ;
if ( ! V_16 ) {
F_37 ( V_14 ) ;
return - V_33 ;
}
V_14 [ 1 ] = V_189 ;
V_14 [ 9 ] = V_65 -> V_190 ;
V_18 = F_7 ( V_13 , V_14 , V_187 ,
V_16 , V_188 ) ;
if ( ! V_18 )
goto V_102;
V_65 -> V_191 = F_54 ( & V_16 [ 12 ] ) ;
V_65 -> V_192 = F_54 ( & V_16 [ 16 ] ) ;
V_65 -> V_193 = F_54 ( & V_16 [ 20 ] ) ;
V_65 -> V_194 = F_54 ( & V_16 [ 24 ] ) ;
V_102:
F_37 ( V_16 ) ;
return V_18 ;
}
int F_55 ( struct V_12 * V_13 , int V_80 ,
struct V_38 * V_195 )
{
int V_18 ;
T_1 * V_196 = F_20 ( V_197 ) ;
T_1 * V_16 = ( T_1 * ) V_195 ;
if ( ! V_196 )
return - V_33 ;
V_196 [ 1 ] = V_198 ;
V_196 [ 9 ] = V_80 ;
V_18 = F_7 ( V_13 , V_196 , V_197 ,
V_195 , V_199 ) ;
if ( ! V_18 && V_16 [ 27 ] == 0x34 && V_16 [ 24 ] != 0x34 ) {
int V_21 ;
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ ) {
int V_200 = 24 + ( V_21 * 4 ) ;
T_1 V_201 , V_202 ;
V_201 = V_16 [ V_200 + 0 ] ;
V_202 = V_16 [ V_200 + 1 ] ;
V_16 [ V_200 + 0 ] = V_16 [ V_200 + 3 ] ;
V_16 [ V_200 + 1 ] = V_16 [ V_200 + 2 ] ;
V_16 [ V_200 + 2 ] = V_202 ;
V_16 [ V_200 + 3 ] = V_201 ;
}
}
F_37 ( V_196 ) ;
return V_18 ;
}
static void F_56 ( struct V_12 * V_186 ,
struct V_12 * V_203 ,
struct V_64 * V_204 )
{
struct V_87 * V_205 = & V_186 -> V_27 ;
struct V_206 * V_22 ;
int V_21 ;
V_203 -> V_207 = 0 ;
V_22 = V_204 -> V_22 ;
for ( V_21 = 0 ; V_21 < V_205 -> V_140 ; V_21 ++ ) {
struct V_64 * V_65 = & V_205 -> V_64 [ V_21 ] ;
if ( V_65 -> V_95 == V_96 ||
V_65 -> V_95 == V_97 )
continue;
if ( F_16 ( V_65 -> V_100 ) ==
F_16 ( V_203 -> V_60 ) ) {
V_203 -> V_208 = F_41 ( V_186 -> V_208 ,
V_65 -> V_77 ) ;
V_203 -> V_209 = F_57 ( V_186 -> V_209 ,
V_65 -> V_77 ) ;
V_203 -> V_207 ++ ;
F_58 ( V_22 , V_65 -> V_65 ) ;
}
}
V_203 -> V_77 = F_41 ( V_204 -> V_77 , V_203 -> V_209 ) ;
V_203 -> V_207 = F_41 ( V_203 -> V_207 , V_186 -> V_207 ) ;
}
static struct V_12 * F_59 (
struct V_12 * V_186 , int V_80 )
{
struct V_87 * V_205 = & V_186 -> V_27 ;
struct V_64 * V_65 = & V_205 -> V_64 [ V_80 ] ;
struct V_12 * V_203 = NULL ;
struct V_89 * V_90 ;
int V_18 ;
if ( V_65 -> V_103 || V_65 -> V_104 )
return NULL ;
V_203 = F_60 () ;
if ( ! V_203 )
return NULL ;
F_61 ( & V_186 -> V_210 ) ;
V_203 -> V_186 = V_186 ;
V_203 -> V_22 = V_186 -> V_22 ;
V_203 -> V_106 = V_65 -> V_105 ;
memcpy ( V_203 -> V_60 , V_65 -> V_100 , V_84 ) ;
F_62 ( V_203 -> V_211 , V_203 -> V_60 ) ;
if ( ! V_65 -> V_22 ) {
V_65 -> V_22 = F_63 ( & V_186 -> V_90 -> V_13 , V_80 ) ;
if ( F_64 ( ! V_65 -> V_22 ) )
goto V_141;
if ( F_64 ( F_65 ( V_65 -> V_22 ) != 0 ) ) {
F_66 ( V_65 -> V_22 ) ;
goto V_141;
}
}
F_56 ( V_186 , V_203 , V_65 ) ;
F_67 ( V_203 , V_65 -> V_22 ) ;
#ifdef F_68
if ( ( V_65 -> V_107 & V_212 ) || V_65 -> V_76 ) {
V_18 = F_69 ( V_203 , V_65 ) ;
if ( V_18 )
goto V_213;
F_70 ( V_203 ) ;
V_18 = F_71 ( V_203 ) ;
if ( V_18 )
goto V_213;
V_90 = F_72 ( V_65 -> V_22 ) ;
if ( ! V_90 )
goto V_213;
V_203 -> V_90 = V_90 ;
F_73 ( & V_90 -> V_13 ) ;
F_74 ( & V_203 -> V_214 , & V_186 -> V_22 -> V_215 ) ;
V_18 = F_75 ( V_203 ) ;
if ( V_18 ) {
F_14 ( L_23
L_24 ,
F_16 ( V_203 -> V_60 ) ,
F_16 ( V_186 -> V_60 ) , V_80 , V_18 ) ;
goto V_216;
}
} else
#endif
if ( V_65 -> V_107 & V_217 ) {
V_203 -> V_82 = V_129 ;
V_90 = F_72 ( V_65 -> V_22 ) ;
if ( F_64 ( ! V_90 ) )
goto V_213;
V_203 -> V_35 = V_65 -> V_107 ;
F_70 ( V_203 ) ;
V_203 -> V_90 = V_90 ;
F_73 ( & V_90 -> V_13 ) ;
F_76 ( V_203 , V_90 ) ;
F_74 ( & V_203 -> V_214 , & V_186 -> V_22 -> V_215 ) ;
V_18 = F_77 ( V_203 ) ;
if ( V_18 ) {
F_14 ( L_25
L_26 ,
F_16 ( V_203 -> V_60 ) ,
F_16 ( V_186 -> V_60 ) , V_80 , V_18 ) ;
goto V_216;
}
} else {
F_14 ( L_27 ,
V_65 -> V_107 , F_16 ( V_186 -> V_60 ) ,
V_80 ) ;
goto V_213;
}
F_74 ( & V_203 -> V_218 , & V_205 -> V_219 ) ;
return V_203 ;
V_216:
F_78 ( V_203 -> V_90 ) ;
F_79 ( & V_203 -> V_214 ) ;
F_80 ( & V_186 -> V_22 -> V_220 ) ;
F_79 ( & V_203 -> V_221 ) ;
F_81 ( & V_186 -> V_22 -> V_220 ) ;
V_213:
F_82 ( V_65 -> V_22 ) ;
V_141:
V_65 -> V_22 = NULL ;
F_83 ( V_203 ) ;
return NULL ;
}
static bool F_84 ( struct V_12 * V_186 , int V_80 )
{
struct V_64 * V_65 = & V_186 -> V_27 . V_64 [ V_80 ] ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_186 -> V_27 . V_140 ; V_21 ++ ) {
struct V_64 * V_222 = & V_186 -> V_27 . V_64 [ V_21 ] ;
if ( V_222 == V_65 )
continue;
if ( ! memcmp ( V_65 -> V_100 , V_222 -> V_100 ,
V_84 ) && V_222 -> V_22 ) {
F_58 ( V_222 -> V_22 , V_65 -> V_65 ) ;
V_65 -> V_22 = V_222 -> V_22 ;
V_65 -> V_95 = V_223 ;
return true ;
}
}
return false ;
}
static struct V_12 * F_85 (
struct V_12 * V_186 , int V_80 )
{
struct V_158 * V_205 = F_45 ( V_186 -> V_90 ) ;
struct V_64 * V_65 = & V_186 -> V_27 . V_64 [ V_80 ] ;
struct V_12 * V_203 = NULL ;
struct V_89 * V_90 ;
struct V_158 * V_159 ;
struct V_184 * V_22 ;
int V_18 ;
if ( V_65 -> V_66 == V_69 ) {
F_14 ( L_28
L_29 ,
F_16 ( V_186 -> V_60 ) , V_80 ,
F_16 ( V_65 -> V_100 ) ,
V_65 -> V_108 ) ;
return NULL ;
}
V_203 = F_60 () ;
if ( ! V_203 )
return NULL ;
V_65 -> V_22 = F_63 ( & V_186 -> V_90 -> V_13 , V_80 ) ;
F_19 ( F_65 ( V_65 -> V_22 ) != 0 ) ;
switch ( V_65 -> V_74 ) {
case V_130 :
V_90 = F_86 ( V_65 -> V_22 ,
V_224 ) ;
break;
case V_131 :
V_90 = F_86 ( V_65 -> V_22 ,
V_225 ) ;
break;
default:
V_90 = NULL ;
F_87 () ;
}
V_22 = V_186 -> V_22 ;
V_203 -> V_90 = V_90 ;
F_73 ( & V_90 -> V_13 ) ;
V_159 = F_45 ( V_90 ) ;
V_203 -> V_82 = V_65 -> V_74 ;
F_61 ( & V_186 -> V_210 ) ;
V_203 -> V_186 = V_186 ;
V_203 -> V_22 = V_22 ;
V_203 -> V_106 = V_65 -> V_105 ;
V_203 -> V_35 = V_65 -> V_107 ;
memcpy ( V_203 -> V_60 , V_65 -> V_100 , V_84 ) ;
F_62 ( V_203 -> V_211 , V_203 -> V_60 ) ;
F_56 ( V_186 , V_203 , V_65 ) ;
V_159 -> V_226 = V_205 -> V_226 + 1 ;
V_186 -> V_22 -> V_85 . V_227 = F_57 ( V_186 -> V_22 -> V_85 . V_227 ,
V_159 -> V_226 ) ;
F_70 ( V_203 ) ;
F_76 ( V_203 , V_90 ) ;
F_88 ( V_90 ) ;
F_80 ( & V_186 -> V_22 -> V_220 ) ;
F_74 ( & V_203 -> V_221 , & V_186 -> V_22 -> V_228 ) ;
F_81 ( & V_186 -> V_22 -> V_220 ) ;
V_18 = F_89 ( V_203 ) ;
if ( V_18 ) {
F_90 ( V_90 ) ;
F_80 ( & V_186 -> V_22 -> V_220 ) ;
F_79 ( & V_203 -> V_221 ) ;
F_81 ( & V_186 -> V_22 -> V_220 ) ;
F_83 ( V_203 ) ;
return NULL ;
}
F_74 ( & V_203 -> V_218 , & V_186 -> V_27 . V_219 ) ;
return V_203 ;
}
static int F_91 ( struct V_12 * V_13 , int V_80 )
{
struct V_87 * V_88 = & V_13 -> V_27 ;
struct V_64 * V_64 = & V_88 -> V_64 [ V_80 ] ;
struct V_12 * V_203 = NULL ;
int V_18 = 0 ;
if ( V_64 -> V_77 == V_229 ) {
if ( ! F_47 ( V_13 , V_80 , V_230 , NULL ) )
V_18 = F_36 ( V_13 , V_80 ) ;
if ( V_18 )
return V_18 ;
}
if ( ! V_13 -> V_186 && ( F_16 ( V_64 -> V_100 ) ==
F_16 ( V_13 -> V_22 -> V_60 ) ) ) {
F_92 ( V_13 , V_80 ) ;
return 0 ;
}
if ( V_13 -> V_186 && ( F_16 ( V_64 -> V_100 ) ==
F_16 ( V_13 -> V_186 -> V_60 ) ) ) {
F_92 ( V_13 , V_80 ) ;
if ( V_64 -> V_66 == V_67 )
F_93 ( V_13 , V_80 , V_13 -> V_22 -> V_60 , 1 ) ;
return 0 ;
}
if ( F_50 ( V_13 -> V_22 , V_64 -> V_100 ) )
F_49 ( V_13 , V_64 -> V_100 ) ;
if ( V_64 -> V_74 == V_75 ) {
if ( V_64 -> V_66 == V_69 ) {
memset ( V_64 -> V_100 , 0 , V_84 ) ;
F_94 ( V_13 , V_64 -> V_100 ) ;
}
return 0 ;
} else if ( V_64 -> V_77 == V_231 )
return 0 ;
if ( V_64 -> V_74 != V_129 &&
V_64 -> V_74 != V_131 &&
V_64 -> V_74 != V_130 &&
V_64 -> V_74 != V_79 ) {
F_14 ( L_30
L_31 , V_64 -> V_74 ,
F_16 ( V_13 -> V_60 ) ,
V_80 ) ;
return 0 ;
}
V_18 = F_94 ( V_13 , V_64 -> V_100 ) ;
if ( V_18 ) {
F_14 ( L_32
L_33 ,
F_16 ( V_64 -> V_100 ) , V_18 ) ;
F_95 ( V_13 , V_64 -> V_100 ) ;
return V_18 ;
}
if ( F_84 ( V_13 , V_80 ) ) {
F_14 ( L_34 ,
V_80 , F_16 ( V_64 -> V_100 ) ) ;
return V_18 ;
}
switch ( V_64 -> V_74 ) {
case V_129 :
case V_79 :
V_203 = F_59 ( V_13 , V_80 ) ;
break;
case V_131 :
if ( F_16 ( V_13 -> V_22 -> V_85 . V_232 ) ) {
F_14 ( L_35
L_36 ,
F_16 ( V_64 -> V_100 ) ,
V_64 -> V_108 ,
F_16 ( V_13 -> V_60 ) ,
V_80 ) ;
F_48 ( V_13 , V_80 ) ;
break;
} else
memcpy ( V_13 -> V_22 -> V_85 . V_232 ,
V_64 -> V_100 , V_84 ) ;
case V_130 :
V_203 = F_85 ( V_13 , V_80 ) ;
break;
default:
break;
}
if ( V_203 ) {
int V_21 ;
for ( V_21 = 0 ; V_21 < V_88 -> V_140 ; V_21 ++ ) {
if ( V_88 -> V_64 [ V_21 ] . V_95 == V_96 ||
V_88 -> V_64 [ V_21 ] . V_95 == V_97 )
continue;
if ( F_16 ( V_88 -> V_64 [ V_21 ] . V_100 ) ==
F_16 ( V_203 -> V_60 ) ) {
V_88 -> V_64 [ V_21 ] . V_95 = V_223 ;
if ( F_84 ( V_13 , V_21 ) )
F_14 ( L_34 ,
V_21 , F_16 ( V_88 -> V_64 [ V_21 ] . V_100 ) ) ;
}
}
}
return V_18 ;
}
static int F_96 ( struct V_12 * V_13 , T_1 * V_233 )
{
struct V_87 * V_88 = & V_13 -> V_27 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_88 -> V_140 ; V_21 ++ ) {
struct V_64 * V_65 = & V_88 -> V_64 [ V_21 ] ;
if ( V_65 -> V_95 == V_96 ||
V_65 -> V_95 == V_97 )
continue;
if ( ( V_65 -> V_74 == V_130 ||
V_65 -> V_74 == V_131 ) &&
V_65 -> V_66 == V_70 ) {
memcpy ( V_233 , V_65 -> V_100 , V_84 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_97 ( struct V_12 * V_13 )
{
struct V_87 * V_88 = & V_13 -> V_27 ;
struct V_12 * V_203 ;
T_1 V_233 [ 8 ] = { 0 , } ;
F_51 (child, &ex->children, siblings) {
if ( V_203 -> V_82 != V_130 &&
V_203 -> V_82 != V_131 )
continue;
if ( V_233 [ 0 ] == 0 ) {
F_96 ( V_203 , V_233 ) ;
continue;
} else {
T_1 V_234 [ 8 ] ;
if ( F_96 ( V_203 , V_234 ) &&
( F_16 ( V_233 ) != F_16 ( V_234 ) ) ) {
F_14 ( L_37
L_38
L_39 ,
F_16 ( V_13 -> V_60 ) ,
F_16 ( V_203 -> V_60 ) ,
F_16 ( V_234 ) ,
F_16 ( V_233 ) ) ;
F_49 ( V_203 , V_234 ) ;
}
}
}
return 0 ;
}
static int F_98 ( struct V_12 * V_13 , int V_136 )
{
struct V_87 * V_88 = & V_13 -> V_27 ;
int V_21 = 0 , V_235 = V_88 -> V_140 ;
int V_18 = 0 ;
if ( 0 <= V_136 && V_136 < V_235 ) {
V_21 = V_136 ;
V_235 = V_21 + 1 ;
}
for ( ; V_21 < V_235 ; V_21 ++ ) {
struct V_64 * V_64 = & V_88 -> V_64 [ V_21 ] ;
if ( V_64 -> V_95 == V_96 ||
V_64 -> V_95 == V_97 ||
V_64 -> V_95 == V_223 )
continue;
switch ( V_64 -> V_77 ) {
case V_183 :
case V_236 :
case V_237 :
continue;
default:
V_18 = F_91 ( V_13 , V_21 ) ;
if ( V_18 )
break;
continue;
}
}
if ( ! V_18 )
F_97 ( V_13 ) ;
return V_18 ;
}
static int F_99 ( struct V_12 * V_13 )
{
struct V_87 * V_88 = & V_13 -> V_27 ;
int V_21 ;
T_1 * V_238 = NULL ;
if ( V_13 -> V_82 != V_130 )
return 0 ;
for ( V_21 = 0 ; V_21 < V_88 -> V_140 ; V_21 ++ ) {
struct V_64 * V_65 = & V_88 -> V_64 [ V_21 ] ;
if ( V_65 -> V_95 == V_96 ||
V_65 -> V_95 == V_97 )
continue;
if ( ( V_65 -> V_74 == V_131 ||
V_65 -> V_74 == V_130 ) &&
V_65 -> V_66 == V_70 ) {
if ( ! V_238 )
V_238 = & V_65 -> V_100 [ 0 ] ;
else if ( F_16 ( V_238 ) !=
F_16 ( V_65 -> V_100 ) ) {
F_14 ( L_40
L_41
L_42 ,
F_16 ( V_13 -> V_60 ) , V_21 ,
F_16 ( V_65 -> V_100 ) ,
F_16 ( V_238 ) ) ;
F_48 ( V_13 , V_21 ) ;
}
}
}
return 0 ;
}
static void F_100 ( struct V_12 * V_203 ,
struct V_64 * V_204 ,
struct V_64 * V_239 )
{
static const char * V_240 [] = {
[ V_130 ] = L_43 ,
[ V_131 ] = L_44 ,
} ;
struct V_12 * V_186 = V_203 -> V_186 ;
F_35 ( L_45
L_46 ,
V_240 [ V_186 -> V_82 ] ,
F_16 ( V_186 -> V_60 ) ,
V_204 -> V_80 ,
V_240 [ V_203 -> V_82 ] ,
F_16 ( V_203 -> V_60 ) ,
V_239 -> V_80 ,
F_23 ( V_186 , V_204 ) ,
F_23 ( V_203 , V_239 ) ) ;
}
static int F_101 ( struct V_12 * V_203 ,
struct V_64 * V_204 ,
struct V_64 * V_239 )
{
int V_18 = 0 ;
struct V_12 * V_186 = V_203 -> V_186 ;
if ( F_16 ( V_186 -> V_22 -> V_85 . V_232 ) != 0 ) {
V_18 = - V_241 ;
F_14 ( L_47
L_48 ,
F_16 ( V_186 -> V_60 ) ,
V_204 -> V_80 ,
F_16 ( V_203 -> V_60 ) ,
V_239 -> V_80 ,
F_16 ( V_186 -> V_22 -> V_85 . V_232 ) ) ;
} else if ( F_16 ( V_186 -> V_22 -> V_85 . V_242 ) == 0 ) {
memcpy ( V_186 -> V_22 -> V_85 . V_242 , V_186 -> V_60 ,
V_84 ) ;
memcpy ( V_186 -> V_22 -> V_85 . V_243 , V_203 -> V_60 ,
V_84 ) ;
} else if ( ( ( F_16 ( V_186 -> V_22 -> V_85 . V_242 ) ==
F_16 ( V_186 -> V_60 ) ) ||
( F_16 ( V_186 -> V_22 -> V_85 . V_242 ) ==
F_16 ( V_203 -> V_60 ) ) )
&&
( ( F_16 ( V_186 -> V_22 -> V_85 . V_243 ) ==
F_16 ( V_186 -> V_60 ) ) ||
( F_16 ( V_186 -> V_22 -> V_85 . V_243 ) ==
F_16 ( V_203 -> V_60 ) ) ) )
;
else {
V_18 = - V_241 ;
F_14 ( L_49
L_50 ,
F_16 ( V_186 -> V_60 ) ,
V_204 -> V_80 ,
F_16 ( V_203 -> V_60 ) ,
V_239 -> V_80 ) ;
}
return V_18 ;
}
static int F_102 ( struct V_12 * V_203 )
{
struct V_87 * V_244 = & V_203 -> V_27 ;
struct V_87 * V_205 ;
int V_21 ;
int V_18 = 0 ;
if ( ! V_203 -> V_186 )
return 0 ;
if ( V_203 -> V_186 -> V_82 != V_130 &&
V_203 -> V_186 -> V_82 != V_131 )
return 0 ;
V_205 = & V_203 -> V_186 -> V_27 ;
for ( V_21 = 0 ; V_21 < V_205 -> V_140 ; V_21 ++ ) {
struct V_64 * V_204 = & V_205 -> V_64 [ V_21 ] ;
struct V_64 * V_239 ;
if ( V_204 -> V_95 == V_96 ||
V_204 -> V_95 == V_97 )
continue;
if ( F_16 ( V_204 -> V_100 ) != F_16 ( V_203 -> V_60 ) )
continue;
V_239 = & V_244 -> V_64 [ V_204 -> V_108 ] ;
switch ( V_203 -> V_186 -> V_82 ) {
case V_130 :
if ( V_203 -> V_82 == V_131 ) {
if ( V_204 -> V_66 != V_70 ||
V_239 -> V_66 != V_67 ) {
F_100 ( V_203 , V_204 , V_239 ) ;
V_18 = - V_241 ;
}
} else if ( V_204 -> V_66 == V_70 ) {
if ( V_239 -> V_66 == V_70 ) {
V_18 = F_101 ( V_203 , V_204 , V_239 ) ;
} else if ( V_239 -> V_66 != V_67 ) {
F_100 ( V_203 , V_204 , V_239 ) ;
V_18 = - V_241 ;
}
} else if ( V_204 -> V_66 == V_67 ) {
if ( V_239 -> V_66 == V_70 ||
( V_239 -> V_66 == V_67 &&
V_244 -> V_68 && V_205 -> V_68 ) ) {
;
} else {
F_100 ( V_203 , V_204 , V_239 ) ;
V_18 = - V_241 ;
}
}
break;
case V_131 :
if ( V_204 -> V_66 != V_67 ||
V_239 -> V_66 != V_70 ) {
F_100 ( V_203 , V_204 , V_239 ) ;
V_18 = - V_241 ;
}
break;
default:
break;
}
}
return V_18 ;
}
static int F_103 ( struct V_12 * V_13 , int V_80 ,
T_1 * V_60 , int * V_245 , int * V_246 )
{
int V_21 , V_18 = 0 ;
struct V_87 * V_88 = & V_13 -> V_27 ;
struct V_64 * V_65 = & V_88 -> V_64 [ V_80 ] ;
T_1 * V_247 ;
T_1 * V_248 ;
* V_246 = 0 ;
* V_245 = 0 ;
V_247 = F_20 ( V_249 ) ;
if ( ! V_247 )
return - V_33 ;
V_248 = F_22 ( V_250 ) ;
if ( ! V_248 ) {
F_37 ( V_247 ) ;
return - V_33 ;
}
V_247 [ 1 ] = V_251 ;
V_247 [ 9 ] = V_80 ;
for ( V_21 = 0 ; V_21 < V_88 -> V_145 ; V_21 ++ ) {
* ( V_252 * ) ( V_247 + 6 ) = F_104 ( V_21 ) ;
V_18 = F_7 ( V_13 , V_247 , V_249 , V_248 ,
V_250 ) ;
if ( V_18 )
goto V_102;
V_18 = V_248 [ 2 ] ;
if ( V_18 == V_253 ) {
F_14 ( L_51
L_52 ,
F_16 ( V_13 -> V_60 ) , V_80 , V_21 ) ;
goto V_102;
} else if ( V_18 != V_98 ) {
F_14 ( L_53
L_54 , V_59 ,
F_16 ( V_13 -> V_60 ) , V_80 , V_21 , V_18 ) ;
goto V_102;
}
if ( F_16 ( V_60 ) != 0 ) {
if ( F_16 ( V_248 + 16 ) == F_16 ( V_60 ) ) {
* V_245 = V_21 ;
if ( ( V_248 [ 12 ] & 0x80 ) == 0x80 )
* V_246 = 0 ;
else
* V_246 = 1 ;
goto V_102;
} else if ( F_16 ( V_248 + 16 ) == 0 ) {
* V_245 = V_21 ;
* V_246 = 0 ;
goto V_102;
}
} else if ( F_16 ( V_248 + 16 ) == 0 &&
V_65 -> V_112 < V_21 ) {
V_65 -> V_112 = V_21 ;
* V_245 = V_21 ;
* V_246 = 0 ;
goto V_102;
}
}
V_18 = - 1 ;
V_102:
F_37 ( V_247 ) ;
F_37 ( V_248 ) ;
return V_18 ;
}
static int F_105 ( struct V_12 * V_13 , int V_80 ,
T_1 * V_60 , int V_245 , int include )
{
int V_18 ;
T_1 * V_254 ;
T_1 * V_255 ;
V_254 = F_20 ( V_256 ) ;
if ( ! V_254 )
return - V_33 ;
V_255 = F_22 ( V_257 ) ;
if ( ! V_255 ) {
F_37 ( V_254 ) ;
return - V_33 ;
}
V_254 [ 1 ] = V_258 ;
* ( V_252 * ) ( V_254 + 6 ) = F_104 ( V_245 ) ;
V_254 [ 9 ] = V_80 ;
if ( F_16 ( V_60 ) == 0 || ! include )
V_254 [ 12 ] |= 0x80 ;
memcpy ( V_254 + 16 , V_60 , V_84 ) ;
V_18 = F_7 ( V_13 , V_254 , V_256 , V_255 ,
V_257 ) ;
if ( V_18 )
goto V_102;
V_18 = V_255 [ 2 ] ;
if ( V_18 == V_253 ) {
F_14 ( L_55
L_56 ,
F_16 ( V_13 -> V_60 ) , V_80 , V_245 ) ;
}
V_102:
F_37 ( V_254 ) ;
F_37 ( V_255 ) ;
return V_18 ;
}
static int F_93 ( struct V_12 * V_13 , int V_80 ,
T_1 * V_60 , int include )
{
int V_245 ;
int V_246 ;
int V_18 ;
V_18 = F_103 ( V_13 , V_80 , V_60 , & V_245 , & V_246 ) ;
if ( V_18 )
return V_18 ;
if ( include ^ V_246 )
return F_105 ( V_13 , V_80 , V_60 , V_245 , include ) ;
return V_18 ;
}
static int F_106 ( struct V_12 * V_186 ,
struct V_12 * V_203 ,
T_1 * V_60 , int include )
{
struct V_87 * V_259 = & V_186 -> V_27 ;
int V_18 = 0 ;
int V_21 ;
if ( V_186 -> V_186 ) {
V_18 = F_106 ( V_186 -> V_186 , V_186 , V_60 ,
include ) ;
if ( V_18 )
return V_18 ;
}
if ( V_259 -> V_148 == 0 ) {
F_14 ( L_57 ,
F_16 ( V_186 -> V_60 ) ) ;
return 0 ;
}
for ( V_21 = 0 ; V_21 < V_259 -> V_140 ; V_21 ++ ) {
struct V_64 * V_65 = & V_259 -> V_64 [ V_21 ] ;
if ( ( V_65 -> V_66 == V_67 ) &&
( F_16 ( V_65 -> V_100 ) ==
F_16 ( V_203 -> V_60 ) ) ) {
V_18 = F_93 ( V_186 , V_21 , V_60 , include ) ;
if ( V_18 )
return V_18 ;
}
}
return V_18 ;
}
static int F_94 ( struct V_12 * V_13 , T_1 * V_60 )
{
if ( V_13 -> V_186 )
return F_106 ( V_13 -> V_186 , V_13 , V_60 , 1 ) ;
return 0 ;
}
static int F_95 ( struct V_12 * V_13 , T_1 * V_60 )
{
if ( V_13 -> V_186 )
return F_106 ( V_13 -> V_186 , V_13 , V_60 , 0 ) ;
return 0 ;
}
static int F_89 ( struct V_12 * V_13 )
{
int V_18 ;
V_18 = F_107 ( V_13 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_42 ( V_13 ) ;
if ( V_18 )
goto V_141;
V_18 = F_46 ( V_13 ) ;
if ( V_18 )
goto V_141;
V_18 = F_38 ( V_13 ) ;
if ( V_18 ) {
F_14 ( L_58 ,
F_16 ( V_13 -> V_60 ) , V_18 ) ;
goto V_141;
}
F_99 ( V_13 ) ;
V_18 = F_102 ( V_13 ) ;
if ( V_18 )
goto V_141;
return 0 ;
V_141:
F_108 ( V_13 ) ;
return V_18 ;
}
static int F_109 ( struct V_184 * V_22 , const int V_226 )
{
int V_18 = 0 ;
struct V_12 * V_13 ;
F_51 (dev, &port->dev_list, dev_list_node) {
if ( V_13 -> V_82 == V_130 ||
V_13 -> V_82 == V_131 ) {
struct V_158 * V_88 =
F_45 ( V_13 -> V_90 ) ;
if ( V_226 == V_88 -> V_226 )
V_18 = F_98 ( V_13 , - 1 ) ;
else if ( V_226 > 0 )
V_18 = F_98 ( V_22 -> V_260 , - 1 ) ;
}
}
return V_18 ;
}
static int F_110 ( struct V_184 * V_22 )
{
int V_18 ;
int V_226 ;
do {
V_226 = V_22 -> V_85 . V_227 ;
V_18 = F_109 ( V_22 , V_226 ) ;
F_111 () ;
} while ( V_226 < V_22 -> V_85 . V_227 );
return V_18 ;
}
int F_112 ( struct V_12 * V_13 )
{
int V_18 ;
struct V_158 * V_88 = F_45 ( V_13 -> V_90 ) ;
V_18 = F_88 ( V_13 -> V_90 ) ;
if ( V_18 )
goto V_141;
V_88 -> V_226 = V_13 -> V_22 -> V_85 . V_227 ;
V_18 = F_89 ( V_13 ) ;
if ( V_18 )
goto V_261;
F_110 ( V_13 -> V_22 ) ;
return V_18 ;
V_261:
F_113 ( V_13 -> V_90 ) ;
V_141:
return V_18 ;
}
static int F_114 ( struct V_12 * V_13 ,
int V_80 , struct V_38 * V_135 )
{
int V_18 ;
T_1 * V_134 ;
V_134 = F_20 ( V_137 ) ;
if ( ! V_134 )
return - V_33 ;
V_134 [ 1 ] = V_139 ;
V_134 [ 9 ] = V_80 ;
V_18 = F_7 ( V_13 , V_134 , V_137 ,
V_135 , V_138 ) ;
if ( V_18 )
goto V_102;
else if ( V_135 -> V_93 != V_98 ) {
V_18 = V_135 -> V_93 ;
goto V_102;
}
V_102:
F_37 ( V_134 ) ;
return V_18 ;
}
static int F_115 ( struct V_12 * V_13 ,
int V_80 , int * V_262 )
{
int V_18 ;
struct V_38 * V_135 ;
V_135 = F_22 ( V_138 ) ;
if ( ! V_135 )
return - V_33 ;
V_18 = F_114 ( V_13 , V_80 , V_135 ) ;
if ( ! V_18 )
* V_262 = V_135 -> V_85 . V_110 ;
F_37 ( V_135 ) ;
return V_18 ;
}
static int F_116 ( struct V_12 * V_13 , int V_80 ,
T_1 * V_60 , enum V_71 * type )
{
int V_18 ;
struct V_38 * V_135 ;
struct V_72 * V_73 ;
V_135 = F_22 ( V_138 ) ;
if ( ! V_135 )
return - V_33 ;
V_73 = & V_135 -> V_85 ;
V_18 = F_114 ( V_13 , V_80 , V_135 ) ;
if ( V_18 == 0 ) {
memcpy ( V_60 , V_135 -> V_85 . V_100 , 8 ) ;
* type = F_24 ( V_73 ) ;
if ( * type == 0 )
memset ( V_60 , 0 , 8 ) ;
}
F_37 ( V_135 ) ;
return V_18 ;
}
static int F_117 ( struct V_12 * V_13 , int * V_80 ,
int V_263 , bool V_264 )
{
struct V_87 * V_88 = & V_13 -> V_27 ;
int V_18 = 0 ;
int V_21 ;
for ( V_21 = V_263 ; V_21 < V_88 -> V_140 ; V_21 ++ ) {
int V_109 = 0 ;
V_18 = F_115 ( V_13 , V_21 , & V_109 ) ;
switch ( V_18 ) {
case V_94 :
case V_265 :
continue;
case V_98 :
break;
default:
return V_18 ;
}
if ( V_109 != V_88 -> V_64 [ V_21 ] . V_109 ) {
if ( V_264 )
V_88 -> V_64 [ V_21 ] . V_109 =
V_109 ;
* V_80 = V_21 ;
return 0 ;
}
}
return 0 ;
}
static int F_118 ( struct V_12 * V_13 , int * V_266 )
{
int V_18 ;
T_1 * V_151 ;
struct V_38 * V_152 ;
V_151 = F_20 ( V_153 ) ;
if ( ! V_151 )
return - V_33 ;
V_152 = F_22 ( V_154 ) ;
if ( ! V_152 ) {
F_37 ( V_151 ) ;
return - V_33 ;
}
V_151 [ 1 ] = V_155 ;
V_18 = F_7 ( V_13 , V_151 , V_153 , V_152 ,
V_154 ) ;
if ( V_18 )
goto V_102;
if ( V_152 -> V_93 != V_98 ) {
V_18 = V_152 -> V_93 ;
goto V_102;
}
* V_266 = F_40 ( V_152 -> V_143 . V_110 ) ;
V_102:
F_37 ( V_152 ) ;
F_37 ( V_151 ) ;
return V_18 ;
}
static int F_119 ( struct V_12 * V_13 ,
struct V_12 * * V_267 )
{
struct V_87 * V_88 = & V_13 -> V_27 ;
int V_144 = - 1 ;
int V_80 = - 1 ;
int V_18 ;
struct V_12 * V_268 ;
V_18 = F_118 ( V_13 , & V_144 ) ;
if ( V_18 )
goto V_102;
if ( V_144 != - 1 && V_144 != V_88 -> V_144 ) {
V_18 = F_117 ( V_13 , & V_80 , 0 , false ) ;
if ( V_80 != - 1 ) {
* V_267 = V_13 ;
V_88 -> V_144 = V_144 ;
F_14 ( L_59 ) ;
return V_18 ;
} else
F_14 ( L_60 ) ;
}
F_51 (ch, &ex->children, siblings) {
if ( V_268 -> V_82 == V_130 || V_268 -> V_82 == V_131 ) {
V_18 = F_119 ( V_268 , V_267 ) ;
if ( * V_267 )
return V_18 ;
}
}
V_102:
return V_18 ;
}
static void F_120 ( struct V_184 * V_22 , struct V_12 * V_13 )
{
struct V_87 * V_88 = & V_13 -> V_27 ;
struct V_12 * V_203 , * V_269 ;
F_121 (child, n, &ex->children, siblings) {
F_30 ( V_29 , & V_203 -> V_30 ) ;
if ( V_203 -> V_82 == V_130 ||
V_203 -> V_82 == V_131 )
F_120 ( V_22 , V_203 ) ;
else
F_122 ( V_22 , V_203 ) ;
}
F_122 ( V_22 , V_13 ) ;
}
static void F_123 ( struct V_12 * V_186 ,
int V_80 , bool V_270 )
{
struct V_87 * V_27 = & V_186 -> V_27 ;
struct V_64 * V_65 = & V_27 -> V_64 [ V_80 ] ;
struct V_12 * V_203 , * V_269 , * V_271 = NULL ;
if ( V_270 ) {
F_121 (child, n,
&ex_dev->children, siblings) {
if ( F_16 ( V_203 -> V_60 ) ==
F_16 ( V_65 -> V_100 ) ) {
F_30 ( V_29 , & V_203 -> V_30 ) ;
if ( V_203 -> V_82 == V_130 ||
V_203 -> V_82 == V_131 )
F_120 ( V_186 -> V_22 , V_203 ) ;
else
F_122 ( V_186 -> V_22 , V_203 ) ;
V_271 = V_203 ;
break;
}
}
F_95 ( V_186 , V_65 -> V_100 ) ;
}
memset ( V_65 -> V_100 , 0 , V_84 ) ;
if ( V_65 -> V_22 ) {
F_124 ( V_65 -> V_22 , V_65 -> V_65 ) ;
F_67 ( V_271 , V_65 -> V_22 ) ;
if ( V_65 -> V_22 -> V_140 == 0 )
F_82 ( V_65 -> V_22 ) ;
V_65 -> V_22 = NULL ;
}
}
static int F_125 ( struct V_12 * V_272 ,
const int V_226 )
{
struct V_87 * V_273 = & V_272 -> V_27 ;
struct V_12 * V_203 ;
int V_18 = 0 ;
F_51 (child, &ex_root->children, siblings) {
if ( V_203 -> V_82 == V_130 ||
V_203 -> V_82 == V_131 ) {
struct V_158 * V_88 =
F_45 ( V_203 -> V_90 ) ;
if ( V_226 > V_88 -> V_226 )
V_18 = F_125 ( V_203 ,
V_226 ) ;
else if ( V_226 == V_88 -> V_226 )
V_18 = F_98 ( V_203 , - 1 ) ;
}
}
return V_18 ;
}
static int F_126 ( struct V_12 * V_13 )
{
int V_18 ;
struct V_158 * V_88 = F_45 ( V_13 -> V_90 ) ;
int V_226 = V_88 -> V_226 + 1 ;
V_18 = F_98 ( V_13 , - 1 ) ;
if ( V_18 )
goto V_102;
do {
V_18 = F_125 ( V_13 , V_226 ) ;
F_111 () ;
V_226 += 1 ;
} while ( V_226 <= V_13 -> V_22 -> V_85 . V_227 );
V_102:
return V_18 ;
}
static int F_127 ( struct V_12 * V_13 , int V_80 )
{
struct V_64 * V_64 = & V_13 -> V_27 . V_64 [ V_80 ] ;
struct V_12 * V_203 ;
int V_18 ;
F_14 ( L_61 ,
F_16 ( V_13 -> V_60 ) , V_80 ) ;
V_18 = F_36 ( V_13 , V_80 ) ;
if ( V_18 )
return V_18 ;
if ( F_84 ( V_13 , V_80 ) )
return 0 ;
V_18 = F_98 ( V_13 , V_80 ) ;
if ( V_18 )
return V_18 ;
F_51 (child, &dev->ex_dev.children, siblings) {
if ( F_16 ( V_203 -> V_60 ) ==
F_16 ( V_64 -> V_100 ) ) {
if ( V_203 -> V_82 == V_130 ||
V_203 -> V_82 == V_131 )
V_18 = F_126 ( V_203 ) ;
break;
}
}
return V_18 ;
}
static bool F_128 ( enum V_71 V_274 , enum V_71 V_275 )
{
if ( V_275 == V_274 )
return true ;
if ( ( V_275 == V_79 && V_274 == V_129 ) ||
( V_275 == V_129 && V_274 == V_79 ) )
return true ;
return false ;
}
static int F_129 ( struct V_12 * V_13 , int V_80 , bool V_270 )
{
struct V_87 * V_88 = & V_13 -> V_27 ;
struct V_64 * V_65 = & V_88 -> V_64 [ V_80 ] ;
enum V_71 type = V_75 ;
T_1 V_60 [ 8 ] ;
int V_18 ;
memset ( V_60 , 0 , 8 ) ;
V_18 = F_116 ( V_13 , V_80 , V_60 , & type ) ;
switch ( V_18 ) {
case V_265 :
V_65 -> V_95 = V_97 ;
F_123 ( V_13 , V_80 , V_270 ) ;
return V_18 ;
case V_94 :
V_65 -> V_95 = V_96 ;
F_123 ( V_13 , V_80 , V_270 ) ;
return V_18 ;
case V_98 :
break;
case - V_31 :
break;
default:
return V_18 ;
}
if ( ( F_16 ( V_60 ) == 0 ) || ( V_18 == - V_31 ) ) {
V_65 -> V_95 = V_99 ;
F_123 ( V_13 , V_80 , V_270 ) ;
return V_18 ;
} else if ( F_16 ( V_60 ) == F_16 ( V_65 -> V_100 ) &&
F_128 ( type , V_65 -> V_74 ) ) {
struct V_12 * V_276 = F_31 ( V_13 , V_80 ) ;
char * V_277 = L_16 ;
F_36 ( V_13 , V_80 ) ;
if ( V_276 && V_65 -> V_74 == V_79 )
V_277 = L_62 ;
F_14 ( L_63 ,
F_16 ( V_13 -> V_60 ) , V_80 , V_277 ) ;
return V_18 ;
}
if ( F_16 ( V_65 -> V_100 ) &&
F_16 ( V_60 ) != F_16 ( V_65 -> V_100 ) ) {
F_14 ( L_64 ,
F_16 ( V_13 -> V_60 ) , V_80 ,
F_16 ( V_65 -> V_100 ) ) ;
F_123 ( V_13 , V_80 , V_270 ) ;
}
return F_127 ( V_13 , V_80 ) ;
}
static int F_130 ( struct V_12 * V_13 , const int V_80 )
{
struct V_87 * V_88 = & V_13 -> V_27 ;
struct V_64 * V_278 = & V_88 -> V_64 [ V_80 ] ;
int V_18 = 0 ;
int V_21 ;
bool V_270 = true ;
F_14 ( L_65 ,
F_16 ( V_13 -> V_60 ) , V_80 ) ;
if ( F_16 ( V_278 -> V_100 ) != 0 ) {
for ( V_21 = 0 ; V_21 < V_88 -> V_140 ; V_21 ++ ) {
struct V_64 * V_65 = & V_88 -> V_64 [ V_21 ] ;
if ( V_21 == V_80 )
continue;
if ( F_16 ( V_65 -> V_100 ) ==
F_16 ( V_278 -> V_100 ) ) {
F_14 ( L_66
L_67 , V_80 , V_21 ) ;
V_270 = false ;
break;
}
}
V_18 = F_129 ( V_13 , V_80 , V_270 ) ;
} else
V_18 = F_127 ( V_13 , V_80 ) ;
return V_18 ;
}
int F_131 ( struct V_12 * V_260 )
{
int V_18 ;
struct V_12 * V_13 = NULL ;
V_18 = F_119 ( V_260 , & V_13 ) ;
while ( V_18 == 0 && V_13 ) {
struct V_87 * V_88 = & V_13 -> V_27 ;
int V_21 = 0 , V_80 ;
do {
V_80 = - 1 ;
V_18 = F_117 ( V_13 , & V_80 , V_21 , true ) ;
if ( V_80 == - 1 )
break;
V_18 = F_130 ( V_13 , V_80 ) ;
V_21 = V_80 + 1 ;
} while ( V_21 < V_88 -> V_140 );
V_13 = NULL ;
V_18 = F_119 ( V_260 , & V_13 ) ;
}
return V_18 ;
}
int F_132 ( struct V_279 * V_25 , struct V_89 * V_90 ,
struct V_280 * V_14 )
{
struct V_12 * V_13 ;
int V_281 , type ;
struct V_280 * V_81 = V_14 -> V_282 ;
if ( ! V_81 ) {
F_133 ( L_68 ,
V_59 ) ;
return - V_283 ;
}
if ( ! V_90 )
return F_134 ( V_25 , V_14 , V_81 ) ;
type = V_90 -> V_113 . V_115 ;
if ( type != V_224 &&
type != V_225 ) {
F_133 ( L_69 ,
V_59 ) ;
return - V_283 ;
}
V_13 = F_32 ( V_90 ) ;
if ( ! V_13 ) {
F_133 ( L_70 , V_59 ) ;
return - V_283 ;
}
if ( V_14 -> V_284 -> V_285 > 1 || V_81 -> V_284 -> V_285 > 1 ) {
F_133 ( L_71 ,
V_59 , V_14 -> V_284 -> V_285 , F_135 ( V_14 ) ,
V_81 -> V_284 -> V_285 , F_135 ( V_81 ) ) ;
return - V_283 ;
}
V_281 = F_7 ( V_13 , F_136 ( V_14 -> V_284 ) , F_135 ( V_14 ) ,
F_136 ( V_81 -> V_284 ) , F_135 ( V_81 ) ) ;
if ( V_281 > 0 ) {
V_81 -> V_286 = V_281 ;
V_14 -> V_286 = 0 ;
V_281 = 0 ;
} else if ( V_281 == 0 ) {
V_81 -> V_286 = 0 ;
V_14 -> V_286 = 0 ;
}
return V_281 ;
}
