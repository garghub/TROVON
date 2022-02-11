static void F_1 ( struct V_1 * V_2 )
{
}
static struct V_1 * F_2 ( struct V_3 * V_4 )
{
return F_3 ( & V_4 -> V_2 ) ;
}
static void F_4 ( struct V_3 * V_4 )
{
F_5 ( & V_4 -> V_2 ) ;
}
static int F_6 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_3 * V_4 = V_6 -> V_8 -> V_9 ;
F_2 ( V_4 ) ;
F_7 ( V_6 , V_4 -> V_10 ) ;
if ( ( V_7 & V_11 ) && V_4 -> V_10 )
return - V_12 ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 , T_1 V_7 )
{
struct V_3 * V_4 = V_14 -> V_9 ;
F_4 ( V_4 ) ;
return 0 ;
}
static struct V_15 * F_9 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_15 * V_20 ;
int V_21 = - V_22 ;
F_10 ( L_1 ) ;
V_20 = F_11 ( sizeof( struct V_15 ) , V_23 ) ;
if ( ! V_20 )
goto V_24;
F_12 ( & V_20 -> V_25 ) ;
F_13 ( & V_20 -> V_26 ) ;
F_14 ( & V_27 , V_28 ) ;
V_20 -> V_29 = F_15 ( V_17 , V_20 , 0 , 0 ) ;
if ( F_16 ( V_20 -> V_29 ) )
goto V_30;
V_17 = NULL ;
V_21 = F_17 ( V_20 -> V_29 ) ;
if ( V_21 < 0 )
goto V_31;
V_20 -> V_19 = V_19 ;
F_18 ( & V_32 ) ;
F_19 ( & V_20 -> V_26 , & V_33 ) ;
F_20 ( & V_32 ) ;
F_21 ( & V_27 ) ;
F_10 ( L_2 , V_20 ) ;
return V_20 ;
V_31:
F_22 ( V_20 -> V_29 ) ;
V_30:
F_21 ( & V_27 ) ;
F_23 ( V_20 ) ;
V_24:
if ( V_17 )
F_24 ( V_17 ) ;
return F_25 ( V_21 ) ;
}
static struct V_15 * F_26 ( struct V_16 * V_17 )
{
struct V_15 * V_34 ;
if ( V_17 -> V_35 & V_36 )
return NULL ;
F_27 (client_node, &rbd_client_list, node)
if ( F_28 ( V_17 , V_34 -> V_29 ) == 0 )
return V_34 ;
return NULL ;
}
static int F_29 ( char * V_37 , void * V_38 )
{
struct V_18 * V_39 = V_38 ;
T_2 V_40 [ V_41 ] ;
int V_42 , V_43 , V_21 ;
V_42 = F_30 ( V_37 , V_44 , V_40 ) ;
if ( V_42 < 0 )
return - V_45 ;
if ( V_42 < V_46 ) {
V_21 = F_31 ( & V_40 [ 0 ] , & V_43 ) ;
if ( V_21 < 0 ) {
F_32 ( L_3
L_4 , V_37 ) ;
return V_21 ;
}
F_10 ( L_5 , V_42 , V_43 ) ;
} else if ( V_42 > V_46 && V_42 < V_47 ) {
F_10 ( L_6 , V_42 ,
V_40 [ 0 ] . V_48 ) ;
} else {
F_10 ( L_7 , V_42 ) ;
}
switch ( V_42 ) {
case V_49 :
V_39 -> V_50 = V_43 ;
break;
default:
F_33 ( V_42 ) ;
}
return 0 ;
}
static struct V_15 * F_34 ( const char * V_51 ,
T_3 V_52 ,
char * V_53 )
{
struct V_15 * V_20 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
V_19 = F_35 ( sizeof( * V_19 ) , V_23 ) ;
if ( ! V_19 )
return F_25 ( - V_22 ) ;
V_19 -> V_50 = V_54 ;
V_17 = F_36 ( V_53 , V_51 ,
V_51 + V_52 ,
F_29 , V_19 ) ;
if ( F_16 ( V_17 ) ) {
F_23 ( V_19 ) ;
return F_37 ( V_17 ) ;
}
F_18 ( & V_32 ) ;
V_20 = F_26 ( V_17 ) ;
if ( V_20 ) {
F_38 ( & V_20 -> V_25 ) ;
F_20 ( & V_32 ) ;
F_24 ( V_17 ) ;
F_23 ( V_19 ) ;
return V_20 ;
}
F_20 ( & V_32 ) ;
V_20 = F_9 ( V_17 , V_19 ) ;
if ( F_16 ( V_20 ) )
F_23 ( V_19 ) ;
return V_20 ;
}
static void F_39 ( struct V_25 * V_25 )
{
struct V_15 * V_20 = F_40 ( V_25 , struct V_15 , V_25 ) ;
F_10 ( L_8 , V_20 ) ;
F_41 ( & V_20 -> V_26 ) ;
F_22 ( V_20 -> V_29 ) ;
F_23 ( V_20 -> V_19 ) ;
F_23 ( V_20 ) ;
}
static void F_42 ( struct V_3 * V_4 )
{
F_18 ( & V_32 ) ;
F_43 ( & V_4 -> V_15 -> V_25 , F_39 ) ;
F_20 ( & V_32 ) ;
V_4 -> V_15 = NULL ;
}
static void F_44 ( struct V_25 * V_25 )
{
struct V_55 * V_56 =
F_40 ( V_25 , struct V_55 , V_25 ) ;
F_10 ( L_9 , V_56 ) ;
F_23 ( V_56 ) ;
}
static int F_45 ( struct V_57 * V_58 ,
struct V_59 * V_60 ,
int V_61 ,
T_4 V_62 )
{
int V_63 ;
T_5 V_64 ;
if ( memcmp ( V_60 , V_65 , sizeof( V_65 ) ) )
return - V_66 ;
V_64 = F_46 ( V_60 -> V_64 ) ;
V_58 -> V_67 = F_11 ( sizeof( struct V_68 ) +
V_64 * sizeof ( * V_60 ) ,
V_62 ) ;
if ( ! V_58 -> V_67 )
return - V_22 ;
V_58 -> V_69 = F_47 ( V_60 -> V_69 ) ;
if ( V_64 ) {
V_58 -> V_70 = F_11 ( V_58 -> V_69 ,
V_23 ) ;
if ( ! V_58 -> V_70 )
goto V_71;
V_58 -> V_72 = F_11 ( V_64 * sizeof( V_73 ) ,
V_23 ) ;
if ( ! V_58 -> V_72 )
goto V_74;
} else {
V_58 -> V_70 = NULL ;
V_58 -> V_72 = NULL ;
}
memcpy ( V_58 -> V_75 , V_60 -> V_75 ,
sizeof( V_60 -> V_75 ) ) ;
V_58 -> V_76 = F_47 ( V_60 -> V_76 ) ;
V_58 -> V_77 = V_60 -> V_53 . V_78 ;
V_58 -> V_79 = V_60 -> V_53 . V_79 ;
V_58 -> V_80 = V_60 -> V_53 . V_80 ;
F_48 ( & V_58 -> V_67 -> V_81 , 1 ) ;
V_58 -> V_82 = F_47 ( V_60 -> V_82 ) ;
V_58 -> V_67 -> V_83 = V_64 ;
V_58 -> V_84 = V_64 ;
if ( V_64 && V_61 == V_64 ) {
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
V_58 -> V_67 -> V_85 [ V_63 ] =
F_47 ( V_60 -> V_85 [ V_63 ] . V_86 ) ;
V_58 -> V_72 [ V_63 ] =
F_47 ( V_60 -> V_85 [ V_63 ] . V_76 ) ;
}
memcpy ( V_58 -> V_70 , & V_60 -> V_85 [ V_63 ] ,
V_58 -> V_69 ) ;
}
return 0 ;
V_74:
F_23 ( V_58 -> V_70 ) ;
V_71:
F_23 ( V_58 -> V_67 ) ;
return - V_22 ;
}
static int F_49 ( struct V_57 * V_58 , int V_87 )
{
return V_58 -> V_84 - V_87 ;
}
static V_73 F_50 ( struct V_3 * V_4 )
{
struct V_57 * V_58 = & V_4 -> V_58 ;
if ( ! V_4 -> V_88 )
return 0 ;
return V_58 -> V_67 -> V_85 [ F_49 ( V_58 , V_4 -> V_88 ) ] ;
}
static int F_51 ( struct V_57 * V_58 , const char * V_89 ,
V_73 * V_90 , V_73 * V_91 )
{
int V_63 ;
char * V_92 = V_58 -> V_70 ;
for ( V_63 = 0 ; V_63 < V_58 -> V_84 ; V_63 ++ ) {
if ( ! strcmp ( V_89 , V_92 ) ) {
if ( V_90 )
* V_90 = V_58 -> V_67 -> V_85 [ V_63 ] ;
if ( V_91 )
* V_91 = V_58 -> V_72 [ V_63 ] ;
return V_63 ;
}
V_92 += strlen ( V_92 ) + 1 ;
}
return - V_93 ;
}
static int F_52 ( struct V_3 * V_2 , V_73 * V_91 )
{
struct V_57 * V_58 = & V_2 -> V_58 ;
struct V_68 * V_67 = V_58 -> V_67 ;
int V_21 = - V_93 ;
F_53 ( sizeof ( V_2 -> V_89 ) < sizeof ( V_94 ) ) ;
F_54 ( & V_2 -> V_95 ) ;
if ( ! memcmp ( V_2 -> V_89 , V_94 ,
sizeof ( V_94 ) ) ) {
if ( V_58 -> V_84 )
V_67 -> V_90 = V_58 -> V_82 ;
else
V_67 -> V_90 = 0 ;
V_2 -> V_88 = 0 ;
V_2 -> V_10 = 0 ;
if ( V_91 )
* V_91 = V_58 -> V_76 ;
} else {
V_21 = F_51 ( V_58 , V_2 -> V_89 , & V_67 -> V_90 , V_91 ) ;
if ( V_21 < 0 )
goto V_96;
V_2 -> V_88 = V_58 -> V_84 - V_21 ;
V_2 -> V_10 = 1 ;
}
V_21 = 0 ;
V_96:
F_55 ( & V_2 -> V_95 ) ;
return V_21 ;
}
static void F_56 ( struct V_57 * V_58 )
{
F_23 ( V_58 -> V_67 ) ;
F_23 ( V_58 -> V_70 ) ;
F_23 ( V_58 -> V_72 ) ;
}
static V_73 F_57 ( struct V_57 * V_58 ,
const char * V_75 ,
V_73 V_97 , V_73 V_98 ,
char * V_99 , V_73 * V_100 )
{
V_73 V_101 = V_97 >> V_58 -> V_77 ;
if ( V_99 )
snprintf ( V_99 , V_102 ,
L_10 , V_75 , V_101 ) ;
V_97 = V_97 & ( ( 1 << V_58 -> V_77 ) - 1 ) ;
V_98 = F_58 ( V_73 , V_98 , ( 1 << V_58 -> V_77 ) - V_97 ) ;
if ( V_100 )
* V_100 = V_97 ;
return V_98 ;
}
static int F_59 ( struct V_57 * V_58 ,
V_73 V_97 , V_73 V_98 )
{
V_73 V_103 = V_97 >> V_58 -> V_77 ;
V_73 V_104 = ( V_97 + V_98 - 1 ) >> V_58 -> V_77 ;
return V_104 - V_103 + 1 ;
}
static V_73 F_60 ( struct V_57 * V_58 )
{
return 1 << V_58 -> V_77 ;
}
static void F_61 ( struct V_105 * V_106 )
{
struct V_105 * V_107 ;
while ( V_106 ) {
V_107 = V_106 ;
V_106 = V_106 -> V_108 ;
F_62 ( V_107 ) ;
}
}
static void F_63 ( struct V_105 * V_106 , int V_109 )
{
struct V_110 * V_111 ;
unsigned long V_35 ;
void * V_112 ;
int V_63 ;
int V_113 = 0 ;
while ( V_106 ) {
F_64 (bv, chain, i) {
if ( V_113 + V_111 -> V_114 > V_109 ) {
int V_115 = F_65 ( V_109 - V_113 , 0 ) ;
V_112 = F_66 ( V_111 , & V_35 ) ;
memset ( V_112 + V_115 , 0 ,
V_111 -> V_114 - V_115 ) ;
F_67 ( V_112 , & V_35 ) ;
}
V_113 += V_111 -> V_114 ;
}
V_106 = V_106 -> V_108 ;
}
}
static struct V_105 * F_68 ( struct V_105 * * V_116 , struct V_105 * * V_117 ,
struct V_118 * * V_119 ,
int V_98 , T_4 V_120 )
{
struct V_105 * V_107 , * V_121 = * V_116 , * V_122 = NULL , * V_123 = NULL ;
int V_124 = 0 ;
if ( * V_119 ) {
F_69 ( * V_119 ) ;
* V_119 = NULL ;
}
while ( V_121 && ( V_124 < V_98 ) ) {
V_107 = F_70 ( V_120 , V_121 -> V_125 ) ;
if ( ! V_107 )
goto V_126;
if ( V_124 + V_121 -> V_127 > V_98 ) {
struct V_118 * V_119 ;
F_10 ( L_11
L_12 ,
( int ) V_124 , ( int ) V_98 - V_124 ,
( int ) V_121 -> V_127 ) ;
V_119 = F_71 ( V_121 , ( V_98 - V_124 ) / V_128 ) ;
if ( ! V_119 )
goto V_126;
F_72 ( V_107 , & V_119 -> V_129 ) ;
* V_117 = & V_119 -> V_130 ;
} else {
F_72 ( V_107 , V_121 ) ;
* V_117 = V_121 -> V_108 ;
}
V_107 -> V_131 = NULL ;
V_120 &= ~ V_132 ;
V_107 -> V_108 = NULL ;
if ( ! V_122 ) {
V_122 = V_123 = V_107 ;
} else {
V_123 -> V_108 = V_107 ;
V_123 = V_107 ;
}
V_121 = V_121 -> V_108 ;
V_124 += V_107 -> V_127 ;
}
F_33 ( V_124 < V_98 ) ;
if ( V_123 )
V_123 -> V_108 = NULL ;
* V_116 = V_121 ;
return V_122 ;
V_126:
F_10 ( L_13 ) ;
F_61 ( V_122 ) ;
return NULL ;
}
static int F_73 ( struct V_133 * * V_134 ,
int V_135 ,
int V_136 ,
T_5 V_137 )
{
* V_134 = F_35 ( sizeof( struct V_133 ) * ( V_135 + 1 ) ,
V_138 ) ;
if ( ! * V_134 )
return - V_22 ;
( * V_134 ) [ 0 ] . V_139 = V_136 ;
( * V_134 ) [ 0 ] . V_137 = V_137 ;
return 0 ;
}
static void F_74 ( struct V_133 * V_134 )
{
F_23 ( V_134 ) ;
}
static void F_75 ( struct V_140 * V_141 ,
struct V_55 * V_56 ,
int V_142 ,
int V_21 , V_73 V_98 )
{
struct V_143 * V_144 ;
int V_145 , F_65 , V_63 ;
F_10 ( L_14 ,
V_56 , V_142 , V_21 , V_98 ) ;
if ( ! V_141 )
return;
if ( ! V_56 ) {
F_76 ( V_141 , V_21 , V_98 ) ;
return;
}
V_144 = V_141 -> V_144 ;
F_77 ( V_144 -> V_146 ) ;
V_56 -> V_147 [ V_142 ] . V_96 = 1 ;
V_56 -> V_147 [ V_142 ] . V_148 = V_21 ;
V_56 -> V_147 [ V_142 ] . V_149 = V_98 ;
F_65 = V_145 = V_56 -> V_150 ;
while ( F_65 < V_56 -> V_124 && V_56 -> V_147 [ F_65 ] . V_96 )
F_65 ++ ;
for ( V_63 = V_145 ; V_63 < F_65 ; V_63 ++ ) {
F_78 ( V_141 , V_56 -> V_147 [ V_63 ] . V_148 ,
V_56 -> V_147 [ V_63 ] . V_149 ) ;
V_56 -> V_150 ++ ;
F_43 ( & V_56 -> V_25 , F_44 ) ;
}
F_79 ( V_144 -> V_146 ) ;
}
static void F_80 ( struct V_151 * V_152 ,
int V_21 , V_73 V_98 )
{
F_75 ( V_152 -> V_141 , V_152 -> V_56 , V_152 -> V_153 , V_21 , V_98 ) ;
}
static int F_81 ( struct V_140 * V_141 ,
struct V_3 * V_2 ,
struct V_68 * V_67 ,
V_73 V_154 ,
const char * V_155 , V_73 V_97 , V_73 V_98 ,
struct V_105 * V_105 ,
struct V_156 * * V_157 ,
int V_158 ,
int V_35 ,
struct V_133 * V_134 ,
int V_159 ,
struct V_55 * V_56 ,
int V_153 ,
void (* F_82)( struct V_160 * V_152 ,
struct V_161 * V_162 ) ,
struct V_160 * * V_163 ,
V_73 * V_164 )
{
struct V_160 * V_152 ;
struct V_165 * V_166 ;
int V_21 ;
V_73 V_167 ;
struct V_168 V_169 = V_170 ;
struct V_151 * V_171 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
V_171 = F_35 ( sizeof( * V_171 ) , V_138 ) ;
if ( ! V_171 ) {
if ( V_56 )
F_75 ( V_141 , V_56 , V_153 ,
- V_22 , V_98 ) ;
return - V_22 ;
}
if ( V_56 ) {
V_171 -> V_56 = V_56 ;
V_171 -> V_153 = V_153 ;
}
F_10 ( L_15 , V_155 , V_98 , V_97 ) ;
F_83 ( & V_2 -> V_95 ) ;
V_175 = & V_2 -> V_15 -> V_29 -> V_175 ;
V_152 = F_84 ( V_175 , V_35 , V_67 , V_134 ,
false , V_138 , V_157 , V_105 ) ;
if ( ! V_152 ) {
F_85 ( & V_2 -> V_95 ) ;
V_21 = - V_22 ;
goto V_176;
}
V_152 -> V_177 = F_82 ;
V_171 -> V_141 = V_141 ;
V_171 -> V_105 = V_105 ;
V_171 -> V_157 = V_157 ;
V_171 -> V_98 = V_98 ;
V_152 -> V_178 = V_171 ;
V_173 = V_152 -> V_179 -> V_180 . V_181 ;
V_173 -> V_154 = F_86 ( V_182 ) ;
strncpy ( V_152 -> V_183 , V_155 , sizeof( V_152 -> V_183 ) ) ;
V_152 -> V_184 = strlen ( V_152 -> V_183 ) ;
V_166 = & V_152 -> V_185 ;
memset ( V_166 , 0 , sizeof( * V_166 ) ) ;
V_166 -> V_186 = F_87 ( 1 << V_187 ) ;
V_166 -> V_188 = F_87 ( 1 ) ;
V_166 -> V_189 = F_87 ( 1 << V_187 ) ;
V_166 -> V_190 = F_87 ( - 1 ) ;
V_166 -> V_191 = F_87 ( V_2 -> V_192 ) ;
F_88 ( V_175 , V_166 , V_154 , V_97 , & V_98 , & V_167 ,
V_152 , V_134 ) ;
F_89 ( V_152 , V_97 , & V_98 ,
V_134 ,
V_67 ,
& V_169 ,
V_152 -> V_183 , V_152 -> V_184 ) ;
F_85 ( & V_2 -> V_95 ) ;
if ( V_163 ) {
F_90 ( V_175 , V_152 ) ;
* V_163 = V_152 ;
}
V_21 = F_91 ( V_175 , V_152 , false ) ;
if ( V_21 < 0 )
goto V_193;
if ( ! F_82 ) {
V_21 = F_92 ( V_175 , V_152 ) ;
if ( V_164 )
* V_164 = F_47 ( V_152 -> V_194 . V_195 ) ;
F_10 ( L_16 ,
F_47 ( V_152 -> V_194 . V_195 ) ) ;
F_93 ( V_152 ) ;
}
return V_21 ;
V_193:
F_61 ( V_171 -> V_105 ) ;
F_93 ( V_152 ) ;
V_176:
F_80 ( V_171 , V_21 , V_98 ) ;
F_23 ( V_171 ) ;
return V_21 ;
}
static void F_94 ( struct V_160 * V_152 , struct V_161 * V_162 )
{
struct V_151 * V_171 = V_152 -> V_178 ;
struct V_196 * V_197 ;
struct V_198 * V_139 ;
T_6 V_148 ;
V_73 V_149 ;
int V_199 ;
V_197 = V_162 -> V_180 . V_181 ;
F_95 ( F_46 ( V_197 -> V_135 ) == 0 ) ;
V_139 = ( void * ) ( V_197 + 1 ) ;
V_148 = F_46 ( V_197 -> V_200 ) ;
V_149 = F_47 ( V_139 -> V_201 . V_202 ) ;
V_199 = ( F_46 ( V_139 -> V_139 ) == V_203 ) ;
F_10 ( L_17 , V_149 , V_199 , V_148 ) ;
if ( V_148 == - V_93 && V_199 ) {
F_63 ( V_171 -> V_105 , 0 ) ;
V_148 = 0 ;
} else if ( V_148 == 0 && V_199 && V_149 < V_171 -> V_98 ) {
F_63 ( V_171 -> V_105 , V_149 ) ;
V_149 = V_171 -> V_98 ;
}
F_80 ( V_171 , V_148 , V_149 ) ;
if ( V_171 -> V_105 )
F_61 ( V_171 -> V_105 ) ;
F_93 ( V_152 ) ;
F_23 ( V_171 ) ;
}
static void F_96 ( struct V_160 * V_152 , struct V_161 * V_162 )
{
F_93 ( V_152 ) ;
}
static int F_97 ( struct V_3 * V_2 ,
struct V_68 * V_67 ,
V_73 V_154 ,
int V_136 ,
int V_35 ,
struct V_133 * V_204 ,
int V_159 ,
const char * V_155 ,
V_73 V_97 , V_73 V_98 ,
char * V_112 ,
struct V_160 * * V_163 ,
V_73 * V_164 )
{
int V_21 ;
struct V_156 * * V_157 ;
int V_158 ;
struct V_133 * V_134 = V_204 ;
T_5 V_137 ;
V_158 = F_98 ( V_97 , V_98 ) ;
V_157 = F_99 ( V_158 , V_23 ) ;
if ( F_16 ( V_157 ) )
return F_100 ( V_157 ) ;
if ( ! V_204 ) {
V_137 = ( V_35 & V_205 ? V_98 : 0 ) ;
V_21 = F_73 ( & V_134 , 1 , V_136 , V_137 ) ;
if ( V_21 < 0 )
goto V_96;
if ( ( V_35 & V_205 ) && V_112 ) {
V_21 = F_101 ( V_157 , V_112 , V_97 , V_98 ) ;
if ( V_21 < 0 )
goto V_206;
}
}
V_21 = F_81 ( NULL , V_2 , V_67 , V_154 ,
V_155 , V_97 , V_98 , NULL ,
V_157 , V_158 ,
V_35 ,
V_134 ,
2 ,
NULL , 0 ,
NULL ,
V_163 , V_164 ) ;
if ( V_21 < 0 )
goto V_206;
if ( ( V_35 & V_207 ) && V_112 )
V_21 = F_102 ( V_157 , V_112 , V_97 , V_21 ) ;
V_206:
if ( ! V_204 )
F_74 ( V_134 ) ;
V_96:
F_103 ( V_157 , V_158 ) ;
return V_21 ;
}
static int F_104 ( struct V_140 * V_141 ,
struct V_3 * V_4 ,
struct V_68 * V_67 ,
V_73 V_154 ,
int V_136 , int V_35 , int V_159 ,
V_73 V_97 , V_73 V_98 ,
struct V_105 * V_105 ,
struct V_55 * V_56 ,
int V_153 )
{
char * V_99 ;
V_73 V_208 ;
V_73 V_209 ;
int V_21 ;
struct V_133 * V_134 ;
T_5 V_137 ;
V_99 = F_11 ( V_102 + 1 , V_138 ) ;
if ( ! V_99 )
return - V_22 ;
V_209 = F_57 ( & V_4 -> V_58 ,
V_4 -> V_58 . V_75 ,
V_97 , V_98 ,
V_99 , & V_208 ) ;
V_137 = ( V_35 & V_205 ? V_209 : 0 ) ;
V_21 = F_73 ( & V_134 , 1 , V_136 , V_137 ) ;
if ( V_21 < 0 )
goto V_96;
F_33 ( V_209 < V_98 ) ;
V_21 = F_81 ( V_141 , V_4 , V_67 , V_154 ,
V_99 , V_208 , V_209 ,
V_105 ,
NULL , 0 ,
V_35 ,
V_134 ,
V_159 ,
V_56 , V_153 ,
F_94 , 0 , NULL ) ;
F_74 ( V_134 ) ;
V_96:
F_23 ( V_99 ) ;
return V_21 ;
}
static int F_105 ( struct V_140 * V_141 ,
struct V_3 * V_4 ,
struct V_68 * V_67 ,
V_73 V_97 , V_73 V_98 ,
struct V_105 * V_105 ,
struct V_55 * V_56 ,
int V_153 )
{
return F_104 ( V_141 , V_4 , V_67 , V_182 ,
V_210 ,
V_205 | V_211 ,
2 ,
V_97 , V_98 , V_105 , V_56 , V_153 ) ;
}
static int F_106 ( struct V_140 * V_141 ,
struct V_3 * V_4 ,
V_73 V_154 ,
V_73 V_97 , V_73 V_98 ,
struct V_105 * V_105 ,
struct V_55 * V_56 ,
int V_153 )
{
return F_104 ( V_141 , V_4 , NULL ,
( V_154 ? V_154 : V_182 ) ,
V_203 ,
V_207 ,
2 ,
V_97 , V_98 , V_105 , V_56 , V_153 ) ;
}
static int F_107 ( struct V_3 * V_2 ,
struct V_68 * V_67 ,
V_73 V_154 ,
const char * V_155 ,
V_73 V_97 , V_73 V_98 ,
char * V_112 ,
V_73 * V_164 )
{
return F_97 ( V_2 , NULL ,
( V_154 ? V_154 : V_182 ) ,
V_203 ,
V_207 ,
NULL ,
1 , V_155 , V_97 , V_98 , V_112 , NULL , V_164 ) ;
}
static int F_108 ( struct V_3 * V_2 ,
V_73 V_164 ,
V_73 V_212 ,
const char * V_155 )
{
struct V_133 * V_134 ;
struct V_156 * * V_157 = NULL ;
int V_21 ;
V_21 = F_73 ( & V_134 , 1 , V_213 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_134 [ 0 ] . V_214 . V_164 = F_86 ( V_2 -> V_58 . V_215 ) ;
V_134 [ 0 ] . V_214 . V_216 = V_212 ;
V_134 [ 0 ] . V_214 . V_217 = 0 ;
V_21 = F_81 ( NULL , V_2 , NULL , V_182 ,
V_155 , 0 , 0 , NULL ,
V_157 , 0 ,
V_207 ,
V_134 ,
1 ,
NULL , 0 ,
F_96 , 0 , NULL ) ;
F_74 ( V_134 ) ;
return V_21 ;
}
static void F_109 ( V_73 V_164 , V_73 V_212 , T_7 V_136 , void * V_218 )
{
struct V_3 * V_2 = (struct V_3 * ) V_218 ;
int V_148 ;
if ( ! V_2 )
return;
F_10 ( L_18 , V_2 -> V_219 ,
V_212 , ( int ) V_136 ) ;
F_14 ( & V_27 , V_28 ) ;
V_148 = F_110 ( V_2 ) ;
F_21 ( & V_27 ) ;
if ( V_148 )
F_111 ( V_220 L_19
L_20 , V_2 -> V_221 , V_148 ) ;
F_108 ( V_2 , V_164 , V_212 , V_2 -> V_219 ) ;
}
static int F_112 ( struct V_3 * V_2 ,
const char * V_155 ,
V_73 V_164 )
{
struct V_133 * V_134 ;
struct V_174 * V_175 = & V_2 -> V_15 -> V_29 -> V_175 ;
int V_21 = F_73 ( & V_134 , 1 , V_222 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_113 ( V_175 , F_109 , 0 ,
( void * ) V_2 , & V_2 -> V_223 ) ;
if ( V_21 < 0 )
goto V_224;
V_134 [ 0 ] . V_214 . V_164 = F_86 ( V_164 ) ;
V_134 [ 0 ] . V_214 . V_216 = F_86 ( V_2 -> V_223 -> V_216 ) ;
V_134 [ 0 ] . V_214 . V_217 = 1 ;
V_21 = F_97 ( V_2 , NULL ,
V_182 ,
0 ,
V_205 | V_211 ,
V_134 ,
1 , V_155 , 0 , 0 , NULL ,
& V_2 -> V_225 , NULL ) ;
if ( V_21 < 0 )
goto V_226;
F_74 ( V_134 ) ;
return 0 ;
V_226:
F_114 ( V_2 -> V_223 ) ;
V_2 -> V_223 = NULL ;
V_224:
F_74 ( V_134 ) ;
return V_21 ;
}
static int F_115 ( struct V_3 * V_2 ,
const char * V_155 )
{
struct V_133 * V_134 ;
int V_21 = F_73 ( & V_134 , 1 , V_222 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_134 [ 0 ] . V_214 . V_164 = 0 ;
V_134 [ 0 ] . V_214 . V_216 = F_86 ( V_2 -> V_223 -> V_216 ) ;
V_134 [ 0 ] . V_214 . V_217 = 0 ;
V_21 = F_97 ( V_2 , NULL ,
V_182 ,
0 ,
V_205 | V_211 ,
V_134 ,
1 , V_155 , 0 , 0 , NULL , NULL , NULL ) ;
F_74 ( V_134 ) ;
F_114 ( V_2 -> V_223 ) ;
V_2 -> V_223 = NULL ;
return V_21 ;
}
static void F_116 ( V_73 V_164 , V_73 V_212 , T_7 V_136 , void * V_218 )
{
struct V_3 * V_2 = (struct V_3 * ) V_218 ;
if ( ! V_2 )
return;
F_10 ( L_21 , V_2 -> V_219 ,
V_212 , ( int ) V_136 ) ;
}
static int F_117 ( struct V_3 * V_2 ,
const char * V_155 )
{
struct V_133 * V_134 ;
struct V_174 * V_175 = & V_2 -> V_15 -> V_29 -> V_175 ;
struct V_227 * V_228 ;
struct V_229 V_230 ;
int V_137 = sizeof( T_5 ) + sizeof( T_5 ) ;
int V_21 ;
V_21 = F_73 ( & V_134 , 1 , V_231 , V_137 ) ;
if ( V_21 < 0 )
return V_21 ;
V_230 . V_2 = V_2 ;
V_21 = F_113 ( V_175 , F_116 , 1 ,
( void * ) & V_230 , & V_228 ) ;
if ( V_21 < 0 )
goto V_224;
V_134 [ 0 ] . V_214 . V_164 = 1 ;
V_134 [ 0 ] . V_214 . V_217 = 1 ;
V_134 [ 0 ] . V_214 . V_216 = V_228 -> V_216 ;
V_134 [ 0 ] . V_214 . V_232 = V_233 ;
V_134 [ 0 ] . V_214 . V_234 = 12 ;
V_21 = F_97 ( V_2 , NULL ,
V_182 ,
0 ,
V_205 | V_211 ,
V_134 ,
1 , V_155 , 0 , 0 , NULL , NULL , NULL ) ;
if ( V_21 < 0 )
goto V_226;
V_21 = F_118 ( V_228 , V_235 ) ;
F_10 ( L_22 , V_21 ) ;
F_74 ( V_134 ) ;
return 0 ;
V_226:
F_114 ( V_228 ) ;
V_224:
F_74 ( V_134 ) ;
return V_21 ;
}
static int F_119 ( struct V_3 * V_2 ,
const char * V_155 ,
const char * V_236 ,
const char * V_237 ,
const char * V_218 ,
int V_98 ,
V_73 * V_164 )
{
struct V_133 * V_134 ;
int V_238 = strlen ( V_236 ) ;
int V_239 = strlen ( V_237 ) ;
int V_21 = F_73 ( & V_134 , 1 , V_240 ,
V_238 + V_239 + V_98 ) ;
if ( V_21 < 0 )
return V_21 ;
V_134 [ 0 ] . V_236 . V_241 = V_236 ;
V_134 [ 0 ] . V_236 . V_242 = ( V_243 ) V_238 ;
V_134 [ 0 ] . V_236 . V_244 = V_237 ;
V_134 [ 0 ] . V_236 . V_239 = ( V_243 ) V_239 ;
V_134 [ 0 ] . V_236 . V_245 = 0 ;
V_134 [ 0 ] . V_236 . V_246 = V_218 ;
V_134 [ 0 ] . V_236 . V_247 = V_98 ;
V_21 = F_97 ( V_2 , NULL ,
V_182 ,
0 ,
V_205 | V_211 ,
V_134 ,
1 , V_155 , 0 , 0 , NULL , NULL , V_164 ) ;
F_74 ( V_134 ) ;
F_10 ( L_23 , V_21 ) ;
return V_21 ;
}
static struct V_55 * F_120 ( int V_248 )
{
struct V_55 * V_56 =
F_35 ( sizeof( struct V_55 ) +
sizeof( struct V_249 ) * V_248 ,
V_250 ) ;
if ( ! V_56 )
return NULL ;
V_56 -> V_124 = V_248 ;
F_12 ( & V_56 -> V_25 ) ;
return V_56 ;
}
static void F_121 ( struct V_143 * V_144 )
{
struct V_3 * V_4 = V_144 -> V_251 ;
struct V_140 * V_141 ;
struct V_118 * V_119 = NULL ;
while ( ( V_141 = F_122 ( V_144 ) ) ) {
struct V_105 * V_105 ;
struct V_105 * V_252 , * V_253 = NULL ;
bool V_254 ;
int V_91 , V_255 = 0 ;
V_73 V_97 ;
int V_256 , V_257 = 0 ;
struct V_55 * V_56 ;
if ( ! V_141 )
break;
F_10 ( L_24 ) ;
if ( ( V_141 -> V_258 != V_259 ) ) {
F_123 ( V_141 , 0 ) ;
continue;
}
V_254 = ( F_124 ( V_141 ) == V_260 ) ;
V_91 = F_125 ( V_141 ) ;
V_97 = F_126 ( V_141 ) * V_128 ;
V_252 = V_141 -> V_105 ;
if ( V_254 && V_4 -> V_10 ) {
F_123 ( V_141 , - V_12 ) ;
continue;
}
F_79 ( V_144 -> V_146 ) ;
F_10 ( L_25 ,
V_254 ? L_26 : L_27 ,
V_91 , F_126 ( V_141 ) * V_128 ) ;
V_256 = F_59 ( & V_4 -> V_58 , V_97 , V_91 ) ;
V_56 = F_120 ( V_256 ) ;
if ( ! V_56 ) {
F_77 ( V_144 -> V_146 ) ;
F_123 ( V_141 , - V_22 ) ;
continue;
}
do {
F_10 ( L_28 , V_141 -> V_105 -> V_261 ) ;
V_255 = F_57 ( & V_4 -> V_58 ,
V_4 -> V_58 . V_75 ,
V_97 , V_91 ,
NULL , NULL ) ;
F_38 ( & V_56 -> V_25 ) ;
V_105 = F_68 ( & V_252 , & V_253 , & V_119 ,
V_255 , V_250 ) ;
if ( ! V_105 ) {
F_75 ( V_141 , V_56 , V_257 ,
- V_22 , V_255 ) ;
goto V_262;
}
if ( V_254 )
F_105 ( V_141 , V_4 ,
V_4 -> V_58 . V_67 ,
V_97 ,
V_255 , V_105 ,
V_56 , V_257 ) ;
else
F_106 ( V_141 , V_4 ,
F_50 ( V_4 ) ,
V_97 ,
V_255 , V_105 ,
V_56 , V_257 ) ;
V_262:
V_91 -= V_255 ;
V_97 += V_255 ;
V_257 ++ ;
V_252 = V_253 ;
} while ( V_91 > 0 );
F_43 ( & V_56 -> V_25 , F_44 ) ;
if ( V_119 )
F_69 ( V_119 ) ;
F_77 ( V_144 -> V_146 ) ;
}
}
static int F_127 ( struct V_143 * V_144 , struct V_263 * V_264 ,
struct V_110 * V_265 )
{
struct V_3 * V_4 = V_144 -> V_251 ;
unsigned int V_266 ;
T_8 V_267 ;
unsigned int V_268 ;
int F_65 ;
V_266 = 1 << ( V_4 -> V_58 . V_77 - V_269 ) ;
V_267 = V_264 -> V_270 + F_128 ( V_264 -> V_131 ) ;
V_268 = V_264 -> V_127 >> V_269 ;
F_65 = ( V_266 - ( ( V_267 & ( V_266 - 1 ) )
+ V_268 ) ) << V_269 ;
if ( F_65 < 0 )
F_65 = 0 ;
if ( F_65 <= V_265 -> V_114 && V_268 == 0 )
return V_265 -> V_114 ;
return F_65 ;
}
static void F_129 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_14 ;
if ( ! V_14 )
return;
F_56 ( & V_4 -> V_58 ) ;
if ( V_14 -> V_35 & V_271 )
F_130 ( V_14 ) ;
if ( V_14 -> V_272 )
F_131 ( V_14 -> V_272 ) ;
F_132 ( V_14 ) ;
}
static int F_133 ( struct V_3 * V_4 ,
struct V_57 * V_58 )
{
T_9 V_148 ;
struct V_59 * V_273 ;
int V_64 = 0 ;
V_73 V_164 ;
T_3 V_98 ;
V_98 = sizeof ( * V_273 ) ;
while ( 1 ) {
V_273 = F_11 ( V_98 , V_23 ) ;
if ( ! V_273 )
return - V_22 ;
V_148 = F_107 ( V_4 ,
NULL , V_182 ,
V_4 -> V_219 ,
0 , V_98 ,
( char * ) V_273 , & V_164 ) ;
if ( V_148 < 0 )
goto V_274;
V_148 = F_45 ( V_58 , V_273 , V_64 , V_23 ) ;
if ( V_148 < 0 ) {
if ( V_148 == - V_66 )
F_111 ( L_29
L_30 , V_4 -> V_155 ) ;
goto V_274;
}
if ( V_64 == V_58 -> V_84 )
break;
V_64 = V_58 -> V_84 ;
V_98 = sizeof ( * V_273 ) +
V_64 * sizeof( struct V_275 ) +
V_58 -> V_69 ;
F_56 ( V_58 ) ;
F_23 ( V_273 ) ;
}
V_58 -> V_215 = V_164 ;
V_274:
F_23 ( V_273 ) ;
return V_148 ;
}
static int F_134 ( struct V_3 * V_2 ,
const char * V_89 ,
T_4 V_62 )
{
int V_276 = strlen ( V_89 ) ;
V_73 V_277 ;
int V_21 ;
void * V_218 , * V_92 , * V_278 ;
V_73 V_164 ;
struct V_279 * V_280 ;
if ( V_2 -> V_88 )
return - V_45 ;
V_280 = & V_2 -> V_15 -> V_29 -> V_280 ;
V_21 = F_135 ( V_280 , V_2 -> V_192 , & V_277 ) ;
F_10 ( L_31 , V_277 ) ;
if ( V_21 < 0 )
return V_21 ;
V_218 = F_11 ( V_276 + 16 , V_62 ) ;
if ( ! V_218 )
return - V_22 ;
V_92 = V_218 ;
V_278 = V_218 + V_276 + 16 ;
F_136 ( & V_92 , V_278 , V_89 , V_276 , V_281 ) ;
F_137 ( & V_92 , V_278 , V_277 , V_281 ) ;
V_21 = F_119 ( V_2 , V_2 -> V_219 , L_32 , L_33 ,
V_218 , V_92 - V_218 , & V_164 ) ;
F_23 ( V_218 ) ;
if ( V_21 < 0 )
return V_21 ;
V_2 -> V_58 . V_67 -> V_90 = V_277 ;
return 0 ;
V_281:
return - V_282 ;
}
static void F_138 ( struct V_3 * V_4 )
{
struct V_283 * V_284 ;
while ( ! F_139 ( & V_4 -> V_85 ) ) {
V_284 = F_140 ( & V_4 -> V_85 , struct V_283 , V_26 ) ;
F_141 ( V_4 , V_284 ) ;
}
}
static int F_110 ( struct V_3 * V_4 )
{
int V_21 ;
struct V_57 V_285 ;
V_73 V_82 ;
int V_286 = 0 ;
V_21 = F_133 ( V_4 , & V_285 ) ;
if ( V_21 < 0 )
return V_21 ;
F_142 ( V_4 -> V_14 , V_285 . V_76 / V_128 ) ;
F_54 ( & V_4 -> V_95 ) ;
V_82 = V_4 -> V_58 . V_67 -> V_90 ;
if ( V_4 -> V_58 . V_84 &&
V_4 -> V_58 . V_67 -> V_85 [ 0 ] == V_82 )
V_286 = 1 ;
F_23 ( V_4 -> V_58 . V_67 ) ;
F_23 ( V_4 -> V_58 . V_70 ) ;
F_23 ( V_4 -> V_58 . V_72 ) ;
V_4 -> V_58 . V_84 = V_285 . V_84 ;
V_4 -> V_58 . V_67 = V_285 . V_67 ;
V_4 -> V_58 . V_70 = V_285 . V_70 ;
V_4 -> V_58 . V_69 = V_285 . V_69 ;
V_4 -> V_58 . V_72 = V_285 . V_72 ;
if ( V_286 )
V_4 -> V_58 . V_67 -> V_90 = V_4 -> V_58 . V_67 -> V_85 [ 0 ] ;
else
V_4 -> V_58 . V_67 -> V_90 = V_82 ;
V_21 = F_143 ( V_4 ) ;
F_55 ( & V_4 -> V_95 ) ;
return V_21 ;
}
static int F_144 ( struct V_3 * V_4 )
{
struct V_13 * V_14 ;
struct V_143 * V_144 ;
int V_148 ;
V_73 V_287 ;
V_73 V_288 = 0 ;
V_148 = F_133 ( V_4 , & V_4 -> V_58 ) ;
if ( V_148 )
return V_148 ;
V_148 = F_143 ( V_4 ) ;
if ( V_148 )
return V_148 ;
V_148 = F_52 ( V_4 , & V_288 ) ;
if ( V_148 )
return V_148 ;
V_148 = - V_22 ;
V_14 = F_145 ( V_289 ) ;
if ( ! V_14 )
goto V_290;
snprintf ( V_14 -> V_291 , sizeof( V_14 -> V_291 ) , V_220 L_34 ,
V_4 -> V_86 ) ;
V_14 -> V_221 = V_4 -> V_221 ;
V_14 -> V_292 = 0 ;
V_14 -> V_293 = & V_294 ;
V_14 -> V_9 = V_4 ;
V_148 = - V_22 ;
V_144 = F_146 ( F_121 , & V_4 -> V_295 ) ;
if ( ! V_144 )
goto V_296;
F_147 ( V_144 , V_128 ) ;
V_287 = F_60 ( & V_4 -> V_58 ) ;
F_148 ( V_144 , V_287 / V_128 ) ;
F_149 ( V_144 , V_287 ) ;
F_150 ( V_144 , V_287 ) ;
F_151 ( V_144 , V_287 ) ;
F_152 ( V_144 , F_127 ) ;
V_14 -> V_272 = V_144 ;
V_144 -> V_251 = V_4 ;
V_4 -> V_14 = V_14 ;
V_4 -> V_144 = V_144 ;
F_142 ( V_14 , V_288 / V_128 ) ;
F_153 ( V_14 ) ;
F_154 ( L_35 ,
V_14 -> V_291 , ( unsigned long long ) V_288 ) ;
return 0 ;
V_296:
F_132 ( V_14 ) ;
V_290:
return V_148 ;
}
static struct V_3 * F_155 ( struct V_1 * V_2 )
{
return F_40 ( V_2 , struct V_3 , V_2 ) ;
}
static T_9 F_156 ( struct V_1 * V_2 ,
struct V_297 * V_298 , char * V_112 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
return sprintf ( V_112 , L_36 , ( unsigned long long ) V_4 -> V_58 . V_76 ) ;
}
static T_9 F_157 ( struct V_1 * V_2 ,
struct V_297 * V_298 , char * V_112 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
return sprintf ( V_112 , L_37 , V_4 -> V_221 ) ;
}
static T_9 F_158 ( struct V_1 * V_2 ,
struct V_297 * V_298 , char * V_112 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
return sprintf ( V_112 , L_38 ,
F_159 ( V_4 -> V_15 -> V_29 ) ) ;
}
static T_9 F_160 ( struct V_1 * V_2 ,
struct V_297 * V_298 , char * V_112 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
return sprintf ( V_112 , L_39 , V_4 -> V_299 ) ;
}
static T_9 F_161 ( struct V_1 * V_2 ,
struct V_297 * V_298 , char * V_112 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
return sprintf ( V_112 , L_39 , V_4 -> V_155 ) ;
}
static T_9 F_162 ( struct V_1 * V_2 ,
struct V_297 * V_298 ,
char * V_112 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
return sprintf ( V_112 , L_39 , V_4 -> V_89 ) ;
}
static T_9 F_163 ( struct V_1 * V_2 ,
struct V_297 * V_298 ,
const char * V_112 ,
T_3 V_91 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
int V_148 ;
int V_21 = V_91 ;
F_14 ( & V_27 , V_28 ) ;
V_148 = F_110 ( V_4 ) ;
if ( V_148 < 0 )
V_21 = V_148 ;
F_21 ( & V_27 ) ;
return V_21 ;
}
static void F_164 ( struct V_1 * V_2 )
{
}
static T_9 F_165 ( struct V_1 * V_2 ,
struct V_297 * V_298 ,
char * V_112 )
{
struct V_283 * V_284 = F_40 ( V_2 , struct V_283 , V_2 ) ;
return sprintf ( V_112 , L_40 , V_284 -> V_91 ) ;
}
static T_9 F_166 ( struct V_1 * V_2 ,
struct V_297 * V_298 ,
char * V_112 )
{
struct V_283 * V_284 = F_40 ( V_2 , struct V_283 , V_2 ) ;
return sprintf ( V_112 , L_36 , ( unsigned long long ) V_284 -> V_86 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_283 * V_284 = F_40 ( V_2 , struct V_283 , V_2 ) ;
F_23 ( V_284 -> V_300 ) ;
F_23 ( V_284 ) ;
}
static void F_141 ( struct V_3 * V_4 ,
struct V_283 * V_284 )
{
F_41 ( & V_284 -> V_26 ) ;
F_168 ( & V_284 -> V_2 ) ;
}
static int F_169 ( struct V_3 * V_4 ,
struct V_283 * V_284 ,
struct V_1 * V_301 )
{
struct V_1 * V_2 = & V_284 -> V_2 ;
int V_21 ;
V_2 -> type = & V_302 ;
V_2 -> V_301 = V_301 ;
V_2 -> V_303 = F_167 ;
F_170 ( V_2 , L_41 , V_284 -> V_300 ) ;
V_21 = F_171 ( V_2 ) ;
return V_21 ;
}
static int F_172 ( struct V_3 * V_4 ,
int V_63 , const char * V_300 ,
struct V_283 * * V_304 )
{
int V_21 ;
struct V_283 * V_284 = F_35 ( sizeof( * V_284 ) , V_23 ) ;
if ( ! V_284 )
return - V_22 ;
V_284 -> V_300 = F_173 ( V_300 , V_23 ) ;
V_284 -> V_91 = V_4 -> V_58 . V_72 [ V_63 ] ;
V_284 -> V_86 = V_4 -> V_58 . V_67 -> V_85 [ V_63 ] ;
if ( F_174 ( & V_4 -> V_2 ) ) {
V_21 = F_169 ( V_4 , V_284 ,
& V_4 -> V_2 ) ;
if ( V_21 < 0 )
goto V_305;
}
* V_304 = V_284 ;
return 0 ;
V_305:
F_23 ( V_284 -> V_300 ) ;
F_23 ( V_284 ) ;
return V_21 ;
}
const char * F_175 ( const char * V_300 , const char * V_306 )
{
if ( V_300 < V_306 + 2 )
return NULL ;
V_300 -= 2 ;
while ( * V_300 ) {
if ( V_300 == V_306 )
return V_306 ;
V_300 -- ;
}
return V_300 + 1 ;
}
static int F_143 ( struct V_3 * V_4 )
{
const char * V_300 , * V_307 ;
int V_63 = V_4 -> V_58 . V_84 ;
struct V_283 * V_284 , * V_308 = NULL ;
int V_21 ;
struct V_309 * V_92 , * V_310 ;
V_307 = V_4 -> V_58 . V_70 ;
V_300 = V_307 + V_4 -> V_58 . V_69 ;
F_176 (p, n, &rbd_dev->snaps) {
V_73 V_311 ;
V_308 = F_177 ( V_92 , struct V_283 , V_26 ) ;
if ( V_63 )
V_311 = V_4 -> V_58 . V_67 -> V_85 [ V_63 - 1 ] ;
if ( ! V_63 || V_308 -> V_86 < V_311 ) {
F_141 ( V_4 , V_308 ) ;
continue;
}
if ( V_308 -> V_86 == V_311 ) {
V_63 -- ;
V_300 = F_175 ( V_300 , V_307 ) ;
continue;
}
for (; V_63 > 0 ;
V_63 -- , V_300 = F_175 ( V_300 , V_307 ) ) {
if ( ! V_300 ) {
F_95 ( 1 ) ;
return - V_45 ;
}
V_311 = V_4 -> V_58 . V_67 -> V_85 [ V_63 ] ;
if ( V_311 >= V_308 -> V_86 )
break;
V_21 = F_172 ( V_4 , V_63 - 1 , V_300 , & V_284 ) ;
if ( V_21 < 0 )
return V_21 ;
F_178 ( & V_284 -> V_26 , V_310 ) ;
V_92 = & V_284 -> V_26 ;
}
}
for (; V_63 > 0 ; V_63 -- ) {
V_300 = F_175 ( V_300 , V_307 ) ;
if ( ! V_300 ) {
F_95 ( 1 ) ;
return - V_45 ;
}
V_21 = F_172 ( V_4 , V_63 - 1 , V_300 , & V_284 ) ;
if ( V_21 < 0 )
return V_21 ;
F_178 ( & V_284 -> V_26 , & V_4 -> V_85 ) ;
}
return 0 ;
}
static int F_179 ( struct V_3 * V_4 )
{
int V_21 ;
struct V_1 * V_2 ;
struct V_283 * V_284 ;
F_14 ( & V_27 , V_28 ) ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_312 = & V_313 ;
V_2 -> type = & V_314 ;
V_2 -> V_301 = & V_315 ;
V_2 -> V_303 = V_316 ;
F_170 ( V_2 , L_34 , V_4 -> V_86 ) ;
V_21 = F_171 ( V_2 ) ;
if ( V_21 < 0 )
goto V_290;
F_27 (snap, &rbd_dev->snaps, node) {
V_21 = F_169 ( V_4 , V_284 ,
& V_4 -> V_2 ) ;
if ( V_21 < 0 )
break;
}
V_290:
F_21 ( & V_27 ) ;
return V_21 ;
}
static void F_180 ( struct V_3 * V_4 )
{
F_168 ( & V_4 -> V_2 ) ;
}
static int F_181 ( struct V_3 * V_4 )
{
int V_21 , V_148 ;
do {
V_21 = F_112 ( V_4 , V_4 -> V_219 ,
V_4 -> V_58 . V_215 ) ;
if ( V_21 == - V_282 ) {
F_14 ( & V_27 , V_28 ) ;
V_148 = F_110 ( V_4 ) ;
F_21 ( & V_27 ) ;
if ( V_148 < 0 )
return V_148 ;
}
} while ( V_21 == - V_282 );
return V_21 ;
}
static void F_182 ( struct V_3 * V_4 )
{
V_4 -> V_86 = F_183 ( & V_317 ) ;
F_18 ( & V_318 ) ;
F_19 ( & V_4 -> V_26 , & V_319 ) ;
F_20 ( & V_318 ) ;
}
static void F_184 ( struct V_3 * V_4 )
{
struct V_309 * V_107 ;
int V_320 = V_4 -> V_86 ;
int V_321 ;
F_33 ( V_320 < 1 ) ;
F_18 ( & V_318 ) ;
F_185 ( & V_4 -> V_26 ) ;
if ( V_320 != F_186 ( & V_317 ) ) {
F_20 ( & V_318 ) ;
return;
}
V_321 = 0 ;
F_187 (tmp, &rbd_dev_list) {
struct V_3 * V_4 ;
V_4 = F_177 ( V_107 , struct V_3 , V_26 ) ;
if ( V_320 > V_321 )
V_321 = V_320 ;
}
F_20 ( & V_318 ) ;
F_188 ( & V_317 , V_320 , V_321 ) ;
}
static inline T_3 F_189 ( const char * * V_112 )
{
const char * V_322 = L_42 ;
* V_112 += strspn ( * V_112 , V_322 ) ;
return strcspn ( * V_112 , V_322 ) ;
}
static inline T_3 F_190 ( const char * * V_112 ,
char * V_42 ,
T_3 V_323 )
{
T_3 V_98 ;
V_98 = F_189 ( V_112 ) ;
if ( V_98 < V_323 ) {
memcpy ( V_42 , * V_112 , V_98 ) ;
* ( V_42 + V_98 ) = '\0' ;
}
* V_112 += V_98 ;
return V_98 ;
}
static int F_191 ( struct V_3 * V_4 ,
const char * V_112 ,
const char * * V_324 ,
T_3 * V_325 ,
char * V_53 ,
T_3 V_326 )
{
T_3 V_98 ;
V_98 = F_189 ( & V_112 ) ;
if ( ! V_98 )
return - V_45 ;
* V_325 = V_98 + 1 ;
* V_324 = V_112 ;
V_112 += V_98 ;
V_98 = F_190 ( & V_112 , V_53 , V_326 ) ;
if ( ! V_98 || V_98 >= V_326 )
return - V_45 ;
V_98 = F_190 ( & V_112 , V_4 -> V_299 , sizeof ( V_4 -> V_299 ) ) ;
if ( ! V_98 || V_98 >= sizeof ( V_4 -> V_299 ) )
return - V_45 ;
V_98 = F_190 ( & V_112 , V_4 -> V_155 , sizeof ( V_4 -> V_155 ) ) ;
if ( ! V_98 || V_98 >= sizeof ( V_4 -> V_155 ) )
return - V_45 ;
V_4 -> V_327 = V_98 ;
F_53 ( V_328
< V_329 + sizeof ( V_330 ) ) ;
sprintf ( V_4 -> V_219 , L_43 , V_4 -> V_155 , V_330 ) ;
V_98 = F_190 ( & V_112 , V_4 -> V_89 , sizeof ( V_4 -> V_89 ) ) ;
if ( ! V_98 )
memcpy ( V_4 -> V_89 , V_94 ,
sizeof ( V_94 ) ) ;
else if ( V_98 >= sizeof ( V_4 -> V_89 ) )
return - V_45 ;
return 0 ;
}
static T_9 F_192 ( struct V_331 * V_312 ,
const char * V_112 ,
T_3 V_332 )
{
struct V_3 * V_4 ;
const char * V_324 = NULL ;
T_3 V_325 = 0 ;
char * V_53 = NULL ;
struct V_174 * V_175 ;
int V_148 = - V_22 ;
if ( ! F_193 ( V_333 ) )
return - V_334 ;
V_4 = F_35 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
goto V_335;
V_53 = F_11 ( V_332 , V_23 ) ;
if ( ! V_53 )
goto V_335;
F_194 ( & V_4 -> V_295 ) ;
F_13 ( & V_4 -> V_26 ) ;
F_13 ( & V_4 -> V_85 ) ;
F_195 ( & V_4 -> V_95 ) ;
F_195 ( & V_4 -> V_95 ) ;
F_182 ( V_4 ) ;
F_53 ( V_336
< sizeof ( V_220 ) + V_337 ) ;
sprintf ( V_4 -> V_300 , L_44 , V_220 , V_4 -> V_86 ) ;
V_148 = F_191 ( V_4 , V_112 , & V_324 , & V_325 ,
V_53 , V_332 ) ;
if ( V_148 )
goto V_338;
V_4 -> V_15 = F_34 ( V_324 , V_325 - 1 ,
V_53 ) ;
if ( F_16 ( V_4 -> V_15 ) ) {
V_148 = F_100 ( V_4 -> V_15 ) ;
goto V_338;
}
V_175 = & V_4 -> V_15 -> V_29 -> V_175 ;
V_148 = F_196 ( V_175 -> V_339 , V_4 -> V_299 ) ;
if ( V_148 < 0 )
goto V_340;
V_4 -> V_192 = V_148 ;
V_148 = F_197 ( 0 , V_4 -> V_300 ) ;
if ( V_148 < 0 )
goto V_340;
V_4 -> V_221 = V_148 ;
V_148 = F_179 ( V_4 ) ;
if ( V_148 )
goto V_341;
V_148 = F_144 ( V_4 ) ;
if ( V_148 )
goto V_342;
V_148 = F_181 ( V_4 ) ;
if ( V_148 )
goto V_342;
return V_332 ;
V_342:
F_180 ( V_4 ) ;
F_23 ( V_53 ) ;
return V_148 ;
V_341:
F_198 ( V_4 -> V_221 , V_4 -> V_300 ) ;
V_340:
F_42 ( V_4 ) ;
V_338:
F_184 ( V_4 ) ;
V_335:
F_23 ( V_53 ) ;
F_23 ( V_4 ) ;
F_10 ( L_45 , V_112 ) ;
F_199 ( V_333 ) ;
return ( T_9 ) V_148 ;
}
static struct V_3 * F_200 ( unsigned long V_86 )
{
struct V_309 * V_107 ;
struct V_3 * V_4 ;
F_18 ( & V_318 ) ;
F_201 (tmp, &rbd_dev_list) {
V_4 = F_177 ( V_107 , struct V_3 , V_26 ) ;
if ( V_4 -> V_86 == V_86 ) {
F_20 ( & V_318 ) ;
return V_4 ;
}
}
F_20 ( & V_318 ) ;
return NULL ;
}
static void V_316 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
if ( V_4 -> V_225 ) {
struct V_343 * V_29 = V_4 -> V_15 -> V_29 ;
F_202 ( & V_29 -> V_175 ,
V_4 -> V_225 ) ;
}
if ( V_4 -> V_223 )
F_115 ( V_4 , V_4 -> V_219 ) ;
F_42 ( V_4 ) ;
F_129 ( V_4 ) ;
F_198 ( V_4 -> V_221 , V_4 -> V_300 ) ;
F_184 ( V_4 ) ;
F_23 ( V_4 ) ;
F_199 ( V_333 ) ;
}
static T_9 F_203 ( struct V_331 * V_312 ,
const char * V_112 ,
T_3 V_332 )
{
struct V_3 * V_4 = NULL ;
int V_344 , V_148 ;
unsigned long V_345 ;
int V_21 = V_332 ;
V_148 = F_204 ( V_112 , 10 , & V_345 ) ;
if ( V_148 )
return V_148 ;
V_344 = ( int ) V_345 ;
if ( V_344 != V_345 )
return - V_45 ;
F_14 ( & V_27 , V_28 ) ;
V_4 = F_200 ( V_344 ) ;
if ( ! V_4 ) {
V_21 = - V_93 ;
goto V_96;
}
F_138 ( V_4 ) ;
F_180 ( V_4 ) ;
V_96:
F_21 ( & V_27 ) ;
return V_21 ;
}
static T_9 F_205 ( struct V_1 * V_2 ,
struct V_297 * V_298 ,
const char * V_112 ,
T_3 V_332 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
int V_21 ;
char * V_300 = F_11 ( V_332 + 1 , V_23 ) ;
if ( ! V_300 )
return - V_22 ;
snprintf ( V_300 , V_332 , L_46 , V_112 ) ;
F_14 ( & V_27 , V_28 ) ;
V_21 = F_134 ( V_4 ,
V_300 , V_23 ) ;
if ( V_21 < 0 )
goto V_346;
V_21 = F_110 ( V_4 ) ;
if ( V_21 < 0 )
goto V_346;
F_21 ( & V_27 ) ;
F_117 ( V_4 , V_4 -> V_219 ) ;
V_21 = V_332 ;
F_23 ( V_300 ) ;
return V_21 ;
V_346:
F_21 ( & V_27 ) ;
F_23 ( V_300 ) ;
return V_21 ;
}
static int F_206 ( void )
{
int V_21 ;
V_21 = F_171 ( & V_315 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_207 ( & V_313 ) ;
if ( V_21 < 0 )
F_168 ( & V_315 ) ;
return V_21 ;
}
static void F_208 ( void )
{
F_209 ( & V_313 ) ;
F_168 ( & V_315 ) ;
}
int T_10 F_210 ( void )
{
int V_148 ;
V_148 = F_206 () ;
if ( V_148 )
return V_148 ;
F_154 ( L_47 V_347 L_48 ) ;
return 0 ;
}
void T_11 F_211 ( void )
{
F_208 () ;
}
