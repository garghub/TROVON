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
F_18 ( & V_32 ) ;
F_41 ( & V_20 -> V_26 ) ;
F_20 ( & V_32 ) ;
F_22 ( V_20 -> V_29 ) ;
F_23 ( V_20 -> V_19 ) ;
F_23 ( V_20 ) ;
}
static void F_42 ( struct V_3 * V_4 )
{
F_43 ( & V_4 -> V_15 -> V_25 , F_39 ) ;
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
T_4 V_61 ,
T_5 V_62 )
{
T_4 V_63 , V_64 ;
if ( memcmp ( V_60 , V_65 , sizeof( V_65 ) ) )
return - V_66 ;
V_64 = F_46 ( V_60 -> V_64 ) ;
if ( V_64 > ( V_67 - sizeof( struct V_68 ) )
/ sizeof ( * V_60 ) )
return - V_45 ;
V_58 -> V_69 = F_11 ( sizeof( struct V_68 ) +
V_64 * sizeof( V_70 ) ,
V_62 ) ;
if ( ! V_58 -> V_69 )
return - V_22 ;
V_58 -> V_71 = F_47 ( V_60 -> V_71 ) ;
if ( V_64 ) {
V_58 -> V_72 = F_11 ( V_58 -> V_71 ,
V_62 ) ;
if ( ! V_58 -> V_72 )
goto V_73;
V_58 -> V_74 = F_11 ( V_64 * sizeof( V_70 ) ,
V_62 ) ;
if ( ! V_58 -> V_74 )
goto V_75;
} else {
V_58 -> V_72 = NULL ;
V_58 -> V_74 = NULL ;
}
memcpy ( V_58 -> V_76 , V_60 -> V_76 ,
sizeof( V_60 -> V_76 ) ) ;
V_58 -> V_77 = F_47 ( V_60 -> V_77 ) ;
V_58 -> V_78 = V_60 -> V_53 . V_79 ;
V_58 -> V_80 = V_60 -> V_53 . V_80 ;
V_58 -> V_81 = V_60 -> V_53 . V_81 ;
F_48 ( & V_58 -> V_69 -> V_82 , 1 ) ;
V_58 -> V_83 = F_47 ( V_60 -> V_83 ) ;
V_58 -> V_69 -> V_84 = V_64 ;
V_58 -> V_85 = V_64 ;
if ( V_64 && V_61 == V_64 ) {
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
V_58 -> V_69 -> V_86 [ V_63 ] =
F_47 ( V_60 -> V_86 [ V_63 ] . V_87 ) ;
V_58 -> V_74 [ V_63 ] =
F_47 ( V_60 -> V_86 [ V_63 ] . V_77 ) ;
}
memcpy ( V_58 -> V_72 , & V_60 -> V_86 [ V_63 ] ,
V_58 -> V_71 ) ;
}
return 0 ;
V_75:
F_23 ( V_58 -> V_72 ) ;
V_73:
F_23 ( V_58 -> V_69 ) ;
return - V_22 ;
}
static int F_49 ( struct V_57 * V_58 , const char * V_88 ,
V_70 * V_89 , V_70 * V_90 )
{
int V_63 ;
char * V_91 = V_58 -> V_72 ;
for ( V_63 = 0 ; V_63 < V_58 -> V_85 ; V_63 ++ ) {
if ( ! strcmp ( V_88 , V_91 ) ) {
if ( V_89 )
* V_89 = V_58 -> V_69 -> V_86 [ V_63 ] ;
if ( V_90 )
* V_90 = V_58 -> V_74 [ V_63 ] ;
return V_63 ;
}
V_91 += strlen ( V_91 ) + 1 ;
}
return - V_92 ;
}
static int F_50 ( struct V_3 * V_2 , V_70 * V_90 )
{
struct V_57 * V_58 = & V_2 -> V_58 ;
struct V_68 * V_69 = V_58 -> V_69 ;
int V_21 = - V_92 ;
F_51 ( sizeof ( V_2 -> V_88 ) < sizeof ( V_93 ) ) ;
F_52 ( & V_2 -> V_94 ) ;
if ( ! memcmp ( V_2 -> V_88 , V_93 ,
sizeof ( V_93 ) ) ) {
if ( V_58 -> V_85 )
V_69 -> V_89 = V_58 -> V_83 ;
else
V_69 -> V_89 = 0 ;
V_2 -> V_95 = V_96 ;
V_2 -> V_10 = 0 ;
if ( V_90 )
* V_90 = V_58 -> V_77 ;
} else {
V_21 = F_49 ( V_58 , V_2 -> V_88 , & V_69 -> V_89 , V_90 ) ;
if ( V_21 < 0 )
goto V_97;
V_2 -> V_95 = V_69 -> V_89 ;
V_2 -> V_10 = 1 ;
}
V_21 = 0 ;
V_97:
F_53 ( & V_2 -> V_94 ) ;
return V_21 ;
}
static void F_54 ( struct V_57 * V_58 )
{
F_23 ( V_58 -> V_69 ) ;
F_23 ( V_58 -> V_72 ) ;
F_23 ( V_58 -> V_74 ) ;
}
static V_70 F_55 ( struct V_57 * V_58 ,
const char * V_76 ,
V_70 V_98 , V_70 V_99 ,
char * V_100 , V_70 * V_101 )
{
V_70 V_102 = V_98 >> V_58 -> V_78 ;
if ( V_100 )
snprintf ( V_100 , V_103 ,
L_10 , V_76 , V_102 ) ;
V_98 = V_98 & ( ( 1 << V_58 -> V_78 ) - 1 ) ;
V_99 = F_56 ( V_70 , V_99 , ( 1 << V_58 -> V_78 ) - V_98 ) ;
if ( V_101 )
* V_101 = V_98 ;
return V_99 ;
}
static int F_57 ( struct V_57 * V_58 ,
V_70 V_98 , V_70 V_99 )
{
V_70 V_104 = V_98 >> V_58 -> V_78 ;
V_70 V_105 = ( V_98 + V_99 - 1 ) >> V_58 -> V_78 ;
return V_105 - V_104 + 1 ;
}
static V_70 F_58 ( struct V_57 * V_58 )
{
return 1 << V_58 -> V_78 ;
}
static void F_59 ( struct V_106 * V_107 )
{
struct V_106 * V_108 ;
while ( V_107 ) {
V_108 = V_107 ;
V_107 = V_107 -> V_109 ;
F_60 ( V_108 ) ;
}
}
static void F_61 ( struct V_106 * V_107 , int V_110 )
{
struct V_111 * V_112 ;
unsigned long V_35 ;
void * V_113 ;
int V_63 ;
int V_114 = 0 ;
while ( V_107 ) {
F_62 (bv, chain, i) {
if ( V_114 + V_112 -> V_115 > V_110 ) {
int V_116 = F_63 ( V_110 - V_114 , 0 ) ;
V_113 = F_64 ( V_112 , & V_35 ) ;
memset ( V_113 + V_116 , 0 ,
V_112 -> V_115 - V_116 ) ;
F_65 ( V_113 , & V_35 ) ;
}
V_114 += V_112 -> V_115 ;
}
V_107 = V_107 -> V_109 ;
}
}
static struct V_106 * F_66 ( struct V_106 * * V_117 , struct V_106 * * V_118 ,
struct V_119 * * V_120 ,
int V_99 , T_5 V_121 )
{
struct V_106 * V_108 , * V_122 = * V_117 , * V_123 = NULL , * V_124 = NULL ;
int V_125 = 0 ;
if ( * V_120 ) {
F_67 ( * V_120 ) ;
* V_120 = NULL ;
}
while ( V_122 && ( V_125 < V_99 ) ) {
V_108 = F_68 ( V_121 , V_122 -> V_126 ) ;
if ( ! V_108 )
goto V_127;
if ( V_125 + V_122 -> V_128 > V_99 ) {
struct V_119 * V_120 ;
F_10 ( L_11
L_12 ,
( int ) V_125 , ( int ) V_99 - V_125 ,
( int ) V_122 -> V_128 ) ;
V_120 = F_69 ( V_122 , ( V_99 - V_125 ) / V_129 ) ;
if ( ! V_120 )
goto V_127;
F_70 ( V_108 , & V_120 -> V_130 ) ;
* V_118 = & V_120 -> V_131 ;
} else {
F_70 ( V_108 , V_122 ) ;
* V_118 = V_122 -> V_109 ;
}
V_108 -> V_132 = NULL ;
V_121 &= ~ V_133 ;
V_108 -> V_109 = NULL ;
if ( ! V_123 ) {
V_123 = V_124 = V_108 ;
} else {
V_124 -> V_109 = V_108 ;
V_124 = V_108 ;
}
V_122 = V_122 -> V_109 ;
V_125 += V_108 -> V_128 ;
}
F_33 ( V_125 < V_99 ) ;
if ( V_124 )
V_124 -> V_109 = NULL ;
* V_117 = V_122 ;
return V_123 ;
V_127:
F_10 ( L_13 ) ;
F_59 ( V_123 ) ;
return NULL ;
}
static int F_71 ( struct V_134 * * V_135 ,
int V_136 ,
int V_137 ,
T_4 V_138 )
{
* V_135 = F_35 ( sizeof( struct V_134 ) * ( V_136 + 1 ) ,
V_139 ) ;
if ( ! * V_135 )
return - V_22 ;
( * V_135 ) [ 0 ] . V_140 = V_137 ;
( * V_135 ) [ 0 ] . V_138 = V_138 ;
return 0 ;
}
static void F_72 ( struct V_134 * V_135 )
{
F_23 ( V_135 ) ;
}
static void F_73 ( struct V_141 * V_142 ,
struct V_55 * V_56 ,
int V_143 ,
int V_21 , V_70 V_99 )
{
struct V_144 * V_145 ;
int V_146 , F_63 , V_63 ;
F_10 ( L_14 ,
V_56 , V_143 , V_21 , V_99 ) ;
if ( ! V_142 )
return;
if ( ! V_56 ) {
F_74 ( V_142 , V_21 , V_99 ) ;
return;
}
V_145 = V_142 -> V_145 ;
F_75 ( V_145 -> V_147 ) ;
V_56 -> V_148 [ V_143 ] . V_97 = 1 ;
V_56 -> V_148 [ V_143 ] . V_149 = V_21 ;
V_56 -> V_148 [ V_143 ] . V_150 = V_99 ;
F_63 = V_146 = V_56 -> V_151 ;
while ( F_63 < V_56 -> V_125 && V_56 -> V_148 [ F_63 ] . V_97 )
F_63 ++ ;
for ( V_63 = V_146 ; V_63 < F_63 ; V_63 ++ ) {
F_76 ( V_142 , V_56 -> V_148 [ V_63 ] . V_149 ,
V_56 -> V_148 [ V_63 ] . V_150 ) ;
V_56 -> V_151 ++ ;
F_43 ( & V_56 -> V_25 , F_44 ) ;
}
F_77 ( V_145 -> V_147 ) ;
}
static void F_78 ( struct V_152 * V_153 ,
int V_21 , V_70 V_99 )
{
F_73 ( V_153 -> V_142 , V_153 -> V_56 , V_153 -> V_154 , V_21 , V_99 ) ;
}
static int F_79 ( struct V_141 * V_142 ,
struct V_3 * V_2 ,
struct V_68 * V_69 ,
V_70 V_155 ,
const char * V_156 , V_70 V_98 , V_70 V_99 ,
struct V_106 * V_106 ,
struct V_157 * * V_158 ,
int V_159 ,
int V_35 ,
struct V_134 * V_135 ,
int V_160 ,
struct V_55 * V_56 ,
int V_154 ,
void (* F_80)( struct V_161 * V_153 ,
struct V_162 * V_163 ) ,
struct V_161 * * V_164 ,
V_70 * V_165 )
{
struct V_161 * V_153 ;
struct V_166 * V_167 ;
int V_21 ;
V_70 V_168 ;
struct V_169 V_170 = V_171 ;
struct V_152 * V_172 ;
struct V_173 * V_174 ;
struct V_175 * V_176 ;
V_172 = F_35 ( sizeof( * V_172 ) , V_139 ) ;
if ( ! V_172 ) {
if ( V_56 )
F_73 ( V_142 , V_56 , V_154 ,
- V_22 , V_99 ) ;
return - V_22 ;
}
if ( V_56 ) {
V_172 -> V_56 = V_56 ;
V_172 -> V_154 = V_154 ;
}
F_10 ( L_15 , V_156 , V_99 , V_98 ) ;
F_81 ( & V_2 -> V_94 ) ;
V_176 = & V_2 -> V_15 -> V_29 -> V_176 ;
V_153 = F_82 ( V_176 , V_35 , V_69 , V_135 ,
false , V_139 , V_158 , V_106 ) ;
if ( ! V_153 ) {
F_83 ( & V_2 -> V_94 ) ;
V_21 = - V_22 ;
goto V_177;
}
V_153 -> V_178 = F_80 ;
V_172 -> V_142 = V_142 ;
V_172 -> V_106 = V_106 ;
V_172 -> V_158 = V_158 ;
V_172 -> V_99 = V_99 ;
V_153 -> V_179 = V_172 ;
V_174 = V_153 -> V_180 -> V_181 . V_182 ;
V_174 -> V_155 = F_84 ( V_96 ) ;
strncpy ( V_153 -> V_183 , V_156 , sizeof( V_153 -> V_183 ) ) ;
V_153 -> V_184 = strlen ( V_153 -> V_183 ) ;
V_167 = & V_153 -> V_185 ;
memset ( V_167 , 0 , sizeof( * V_167 ) ) ;
V_167 -> V_186 = F_85 ( 1 << V_187 ) ;
V_167 -> V_188 = F_85 ( 1 ) ;
V_167 -> V_189 = F_85 ( 1 << V_187 ) ;
V_167 -> V_190 = F_85 ( V_2 -> V_191 ) ;
F_86 ( V_176 , V_167 , V_155 , V_98 , & V_99 , & V_168 ,
V_153 , V_135 ) ;
F_87 ( V_153 , V_98 , & V_99 ,
V_135 ,
V_69 ,
& V_170 ,
V_153 -> V_183 , V_153 -> V_184 ) ;
F_83 ( & V_2 -> V_94 ) ;
if ( V_164 ) {
F_88 ( V_176 , V_153 ) ;
* V_164 = V_153 ;
}
V_21 = F_89 ( V_176 , V_153 , false ) ;
if ( V_21 < 0 )
goto V_192;
if ( ! F_80 ) {
V_21 = F_90 ( V_176 , V_153 ) ;
if ( V_165 )
* V_165 = F_47 ( V_153 -> V_193 . V_194 ) ;
F_10 ( L_16 ,
F_47 ( V_153 -> V_193 . V_194 ) ) ;
F_91 ( V_153 ) ;
}
return V_21 ;
V_192:
F_59 ( V_172 -> V_106 ) ;
F_91 ( V_153 ) ;
V_177:
F_78 ( V_172 , V_21 , V_99 ) ;
F_23 ( V_172 ) ;
return V_21 ;
}
static void F_92 ( struct V_161 * V_153 , struct V_162 * V_163 )
{
struct V_152 * V_172 = V_153 -> V_179 ;
struct V_195 * V_196 ;
struct V_197 * V_140 ;
T_6 V_149 ;
V_70 V_150 ;
int V_198 ;
V_196 = V_163 -> V_181 . V_182 ;
F_93 ( F_46 ( V_196 -> V_136 ) == 0 ) ;
V_140 = ( void * ) ( V_196 + 1 ) ;
V_149 = F_46 ( V_196 -> V_199 ) ;
V_150 = F_47 ( V_140 -> V_200 . V_201 ) ;
V_198 = ( F_94 ( V_140 -> V_140 ) == V_202 ) ;
F_10 ( L_17 , V_150 , V_198 , V_149 ) ;
if ( V_149 == - V_92 && V_198 ) {
F_61 ( V_172 -> V_106 , 0 ) ;
V_149 = 0 ;
} else if ( V_149 == 0 && V_198 && V_150 < V_172 -> V_99 ) {
F_61 ( V_172 -> V_106 , V_150 ) ;
V_150 = V_172 -> V_99 ;
}
F_78 ( V_172 , V_149 , V_150 ) ;
if ( V_172 -> V_106 )
F_59 ( V_172 -> V_106 ) ;
F_91 ( V_153 ) ;
F_23 ( V_172 ) ;
}
static void F_95 ( struct V_161 * V_153 , struct V_162 * V_163 )
{
F_91 ( V_153 ) ;
}
static int F_96 ( struct V_3 * V_2 ,
struct V_68 * V_69 ,
V_70 V_155 ,
int V_137 ,
int V_35 ,
struct V_134 * V_203 ,
int V_160 ,
const char * V_156 ,
V_70 V_98 , V_70 V_99 ,
char * V_113 ,
struct V_161 * * V_164 ,
V_70 * V_165 )
{
int V_21 ;
struct V_157 * * V_158 ;
int V_159 ;
struct V_134 * V_135 = V_203 ;
T_4 V_138 ;
V_159 = F_97 ( V_98 , V_99 ) ;
V_158 = F_98 ( V_159 , V_23 ) ;
if ( F_16 ( V_158 ) )
return F_99 ( V_158 ) ;
if ( ! V_203 ) {
V_138 = ( V_35 & V_204 ? V_99 : 0 ) ;
V_21 = F_71 ( & V_135 , 1 , V_137 , V_138 ) ;
if ( V_21 < 0 )
goto V_97;
if ( ( V_35 & V_204 ) && V_113 ) {
V_21 = F_100 ( V_158 , V_113 , V_98 , V_99 ) ;
if ( V_21 < 0 )
goto V_205;
}
}
V_21 = F_79 ( NULL , V_2 , V_69 , V_155 ,
V_156 , V_98 , V_99 , NULL ,
V_158 , V_159 ,
V_35 ,
V_135 ,
2 ,
NULL , 0 ,
NULL ,
V_164 , V_165 ) ;
if ( V_21 < 0 )
goto V_205;
if ( ( V_35 & V_206 ) && V_113 )
V_21 = F_101 ( V_158 , V_113 , V_98 , V_21 ) ;
V_205:
if ( ! V_203 )
F_72 ( V_135 ) ;
V_97:
F_102 ( V_158 , V_159 ) ;
return V_21 ;
}
static int F_103 ( struct V_141 * V_142 ,
struct V_3 * V_4 ,
struct V_68 * V_69 ,
V_70 V_155 ,
int V_137 , int V_35 , int V_160 ,
V_70 V_98 , V_70 V_99 ,
struct V_106 * V_106 ,
struct V_55 * V_56 ,
int V_154 )
{
char * V_100 ;
V_70 V_207 ;
V_70 V_208 ;
int V_21 ;
struct V_134 * V_135 ;
T_4 V_138 ;
V_100 = F_11 ( V_103 + 1 , V_139 ) ;
if ( ! V_100 )
return - V_22 ;
V_208 = F_55 ( & V_4 -> V_58 ,
V_4 -> V_58 . V_76 ,
V_98 , V_99 ,
V_100 , & V_207 ) ;
V_138 = ( V_35 & V_204 ? V_208 : 0 ) ;
V_21 = F_71 ( & V_135 , 1 , V_137 , V_138 ) ;
if ( V_21 < 0 )
goto V_97;
F_33 ( V_208 < V_99 ) ;
V_21 = F_79 ( V_142 , V_4 , V_69 , V_155 ,
V_100 , V_207 , V_208 ,
V_106 ,
NULL , 0 ,
V_35 ,
V_135 ,
V_160 ,
V_56 , V_154 ,
F_92 , 0 , NULL ) ;
F_72 ( V_135 ) ;
V_97:
F_23 ( V_100 ) ;
return V_21 ;
}
static int F_104 ( struct V_141 * V_142 ,
struct V_3 * V_4 ,
struct V_68 * V_69 ,
V_70 V_98 , V_70 V_99 ,
struct V_106 * V_106 ,
struct V_55 * V_56 ,
int V_154 )
{
return F_103 ( V_142 , V_4 , V_69 , V_96 ,
V_209 ,
V_204 | V_210 ,
2 ,
V_98 , V_99 , V_106 , V_56 , V_154 ) ;
}
static int F_105 ( struct V_141 * V_142 ,
struct V_3 * V_4 ,
V_70 V_155 ,
V_70 V_98 , V_70 V_99 ,
struct V_106 * V_106 ,
struct V_55 * V_56 ,
int V_154 )
{
return F_103 ( V_142 , V_4 , NULL ,
V_155 ,
V_202 ,
V_206 ,
2 ,
V_98 , V_99 , V_106 , V_56 , V_154 ) ;
}
static int F_106 ( struct V_3 * V_2 ,
struct V_68 * V_69 ,
V_70 V_155 ,
const char * V_156 ,
V_70 V_98 , V_70 V_99 ,
char * V_113 ,
V_70 * V_165 )
{
return F_96 ( V_2 , NULL ,
V_155 ,
V_202 ,
V_206 ,
NULL ,
1 , V_156 , V_98 , V_99 , V_113 , NULL , V_165 ) ;
}
static int F_107 ( struct V_3 * V_2 ,
V_70 V_165 ,
V_70 V_211 ,
const char * V_156 )
{
struct V_134 * V_135 ;
struct V_157 * * V_158 = NULL ;
int V_21 ;
V_21 = F_71 ( & V_135 , 1 , V_212 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_135 [ 0 ] . V_213 . V_165 = F_84 ( V_2 -> V_58 . V_214 ) ;
V_135 [ 0 ] . V_213 . V_215 = V_211 ;
V_135 [ 0 ] . V_213 . V_216 = 0 ;
V_21 = F_79 ( NULL , V_2 , NULL , V_96 ,
V_156 , 0 , 0 , NULL ,
V_158 , 0 ,
V_206 ,
V_135 ,
1 ,
NULL , 0 ,
F_95 , 0 , NULL ) ;
F_72 ( V_135 ) ;
return V_21 ;
}
static void F_108 ( V_70 V_165 , V_70 V_211 , T_7 V_137 , void * V_217 )
{
struct V_3 * V_2 = (struct V_3 * ) V_217 ;
int V_149 ;
if ( ! V_2 )
return;
F_10 ( L_18 , V_2 -> V_218 ,
V_211 , ( int ) V_137 ) ;
F_14 ( & V_27 , V_28 ) ;
V_149 = F_109 ( V_2 ) ;
F_21 ( & V_27 ) ;
if ( V_149 )
F_110 ( V_219 L_19
L_20 , V_2 -> V_220 , V_149 ) ;
F_107 ( V_2 , V_165 , V_211 , V_2 -> V_218 ) ;
}
static int F_111 ( struct V_3 * V_2 ,
const char * V_156 ,
V_70 V_165 )
{
struct V_134 * V_135 ;
struct V_175 * V_176 = & V_2 -> V_15 -> V_29 -> V_176 ;
int V_21 = F_71 ( & V_135 , 1 , V_221 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_112 ( V_176 , F_108 , 0 ,
( void * ) V_2 , & V_2 -> V_222 ) ;
if ( V_21 < 0 )
goto V_223;
V_135 [ 0 ] . V_213 . V_165 = F_84 ( V_165 ) ;
V_135 [ 0 ] . V_213 . V_215 = F_84 ( V_2 -> V_222 -> V_215 ) ;
V_135 [ 0 ] . V_213 . V_216 = 1 ;
V_21 = F_96 ( V_2 , NULL ,
V_96 ,
0 ,
V_204 | V_210 ,
V_135 ,
1 , V_156 , 0 , 0 , NULL ,
& V_2 -> V_224 , NULL ) ;
if ( V_21 < 0 )
goto V_225;
F_72 ( V_135 ) ;
return 0 ;
V_225:
F_113 ( V_2 -> V_222 ) ;
V_2 -> V_222 = NULL ;
V_223:
F_72 ( V_135 ) ;
return V_21 ;
}
static int F_114 ( struct V_3 * V_2 ,
const char * V_156 )
{
struct V_134 * V_135 ;
int V_21 = F_71 ( & V_135 , 1 , V_221 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_135 [ 0 ] . V_213 . V_165 = 0 ;
V_135 [ 0 ] . V_213 . V_215 = F_84 ( V_2 -> V_222 -> V_215 ) ;
V_135 [ 0 ] . V_213 . V_216 = 0 ;
V_21 = F_96 ( V_2 , NULL ,
V_96 ,
0 ,
V_204 | V_210 ,
V_135 ,
1 , V_156 , 0 , 0 , NULL , NULL , NULL ) ;
F_72 ( V_135 ) ;
F_113 ( V_2 -> V_222 ) ;
V_2 -> V_222 = NULL ;
return V_21 ;
}
static void F_115 ( V_70 V_165 , V_70 V_211 , T_7 V_137 , void * V_217 )
{
struct V_3 * V_2 = (struct V_3 * ) V_217 ;
if ( ! V_2 )
return;
F_10 ( L_21 , V_2 -> V_218 ,
V_211 , ( int ) V_137 ) ;
}
static int F_116 ( struct V_3 * V_2 ,
const char * V_156 )
{
struct V_134 * V_135 ;
struct V_175 * V_176 = & V_2 -> V_15 -> V_29 -> V_176 ;
struct V_226 * V_227 ;
struct V_228 V_229 ;
int V_138 = sizeof( T_4 ) + sizeof( T_4 ) ;
int V_21 ;
V_21 = F_71 ( & V_135 , 1 , V_230 , V_138 ) ;
if ( V_21 < 0 )
return V_21 ;
V_229 . V_2 = V_2 ;
V_21 = F_112 ( V_176 , F_115 , 1 ,
( void * ) & V_229 , & V_227 ) ;
if ( V_21 < 0 )
goto V_223;
V_135 [ 0 ] . V_213 . V_165 = 1 ;
V_135 [ 0 ] . V_213 . V_216 = 1 ;
V_135 [ 0 ] . V_213 . V_215 = V_227 -> V_215 ;
V_135 [ 0 ] . V_213 . V_231 = V_232 ;
V_135 [ 0 ] . V_213 . V_233 = 12 ;
V_21 = F_96 ( V_2 , NULL ,
V_96 ,
0 ,
V_204 | V_210 ,
V_135 ,
1 , V_156 , 0 , 0 , NULL , NULL , NULL ) ;
if ( V_21 < 0 )
goto V_225;
V_21 = F_117 ( V_227 , V_234 ) ;
F_10 ( L_22 , V_21 ) ;
F_72 ( V_135 ) ;
return 0 ;
V_225:
F_113 ( V_227 ) ;
V_223:
F_72 ( V_135 ) ;
return V_21 ;
}
static int F_118 ( struct V_3 * V_2 ,
const char * V_156 ,
const char * V_235 ,
const char * V_236 ,
const char * V_217 ,
int V_99 ,
V_70 * V_165 )
{
struct V_134 * V_135 ;
int V_237 = strlen ( V_235 ) ;
int V_238 = strlen ( V_236 ) ;
int V_21 = F_71 ( & V_135 , 1 , V_239 ,
V_237 + V_238 + V_99 ) ;
if ( V_21 < 0 )
return V_21 ;
V_135 [ 0 ] . V_235 . V_240 = V_235 ;
V_135 [ 0 ] . V_235 . V_241 = ( V_242 ) V_237 ;
V_135 [ 0 ] . V_235 . V_243 = V_236 ;
V_135 [ 0 ] . V_235 . V_238 = ( V_242 ) V_238 ;
V_135 [ 0 ] . V_235 . V_244 = 0 ;
V_135 [ 0 ] . V_235 . V_245 = V_217 ;
V_135 [ 0 ] . V_235 . V_246 = V_99 ;
V_21 = F_96 ( V_2 , NULL ,
V_96 ,
0 ,
V_204 | V_210 ,
V_135 ,
1 , V_156 , 0 , 0 , NULL , NULL , V_165 ) ;
F_72 ( V_135 ) ;
F_10 ( L_23 , V_21 ) ;
return V_21 ;
}
static struct V_55 * F_119 ( int V_247 )
{
struct V_55 * V_56 =
F_35 ( sizeof( struct V_55 ) +
sizeof( struct V_248 ) * V_247 ,
V_249 ) ;
if ( ! V_56 )
return NULL ;
V_56 -> V_125 = V_247 ;
F_12 ( & V_56 -> V_25 ) ;
return V_56 ;
}
static void F_120 ( struct V_144 * V_145 )
{
struct V_3 * V_4 = V_145 -> V_250 ;
struct V_141 * V_142 ;
struct V_119 * V_120 = NULL ;
while ( ( V_142 = F_121 ( V_145 ) ) ) {
struct V_106 * V_106 ;
struct V_106 * V_251 , * V_252 = NULL ;
bool V_253 ;
int V_90 , V_254 = 0 ;
V_70 V_98 ;
int V_255 , V_256 = 0 ;
struct V_55 * V_56 ;
if ( ! V_142 )
break;
F_10 ( L_24 ) ;
if ( ( V_142 -> V_257 != V_258 ) ) {
F_122 ( V_142 , 0 ) ;
continue;
}
V_253 = ( F_123 ( V_142 ) == V_259 ) ;
V_90 = F_124 ( V_142 ) ;
V_98 = F_125 ( V_142 ) * V_129 ;
V_251 = V_142 -> V_106 ;
if ( V_253 && V_4 -> V_10 ) {
F_122 ( V_142 , - V_12 ) ;
continue;
}
F_77 ( V_145 -> V_147 ) ;
F_10 ( L_25 ,
V_253 ? L_26 : L_27 ,
V_90 , F_125 ( V_142 ) * V_129 ) ;
V_255 = F_57 ( & V_4 -> V_58 , V_98 , V_90 ) ;
V_56 = F_119 ( V_255 ) ;
if ( ! V_56 ) {
F_75 ( V_145 -> V_147 ) ;
F_122 ( V_142 , - V_22 ) ;
continue;
}
do {
F_10 ( L_28 , V_142 -> V_106 -> V_260 ) ;
V_254 = F_55 ( & V_4 -> V_58 ,
V_4 -> V_58 . V_76 ,
V_98 , V_90 ,
NULL , NULL ) ;
F_38 ( & V_56 -> V_25 ) ;
V_106 = F_66 ( & V_251 , & V_252 , & V_120 ,
V_254 , V_249 ) ;
if ( ! V_106 ) {
F_73 ( V_142 , V_56 , V_256 ,
- V_22 , V_254 ) ;
goto V_261;
}
if ( V_253 )
F_104 ( V_142 , V_4 ,
V_4 -> V_58 . V_69 ,
V_98 ,
V_254 , V_106 ,
V_56 , V_256 ) ;
else
F_105 ( V_142 , V_4 ,
V_4 -> V_95 ,
V_98 ,
V_254 , V_106 ,
V_56 , V_256 ) ;
V_261:
V_90 -= V_254 ;
V_98 += V_254 ;
V_256 ++ ;
V_251 = V_252 ;
} while ( V_90 > 0 );
F_43 ( & V_56 -> V_25 , F_44 ) ;
if ( V_120 )
F_67 ( V_120 ) ;
F_75 ( V_145 -> V_147 ) ;
}
}
static int F_126 ( struct V_144 * V_145 , struct V_262 * V_263 ,
struct V_111 * V_264 )
{
struct V_3 * V_4 = V_145 -> V_250 ;
unsigned int V_265 ;
T_8 V_266 ;
unsigned int V_267 ;
int F_63 ;
V_265 = 1 << ( V_4 -> V_58 . V_78 - V_268 ) ;
V_266 = V_263 -> V_269 + F_127 ( V_263 -> V_132 ) ;
V_267 = V_263 -> V_128 >> V_268 ;
F_63 = ( V_265 - ( ( V_266 & ( V_265 - 1 ) )
+ V_267 ) ) << V_268 ;
if ( F_63 < 0 )
F_63 = 0 ;
if ( F_63 <= V_264 -> V_115 && V_267 == 0 )
return V_264 -> V_115 ;
return F_63 ;
}
static void F_128 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_14 ;
if ( ! V_14 )
return;
F_54 ( & V_4 -> V_58 ) ;
if ( V_14 -> V_35 & V_270 )
F_129 ( V_14 ) ;
if ( V_14 -> V_271 )
F_130 ( V_14 -> V_271 ) ;
F_131 ( V_14 ) ;
}
static int F_132 ( struct V_3 * V_4 ,
struct V_57 * V_58 )
{
T_9 V_149 ;
struct V_59 * V_272 ;
T_4 V_64 = 0 ;
V_70 V_165 ;
T_3 V_99 ;
V_99 = sizeof ( * V_272 ) ;
while ( 1 ) {
V_272 = F_11 ( V_99 , V_23 ) ;
if ( ! V_272 )
return - V_22 ;
V_149 = F_106 ( V_4 ,
NULL , V_96 ,
V_4 -> V_218 ,
0 , V_99 ,
( char * ) V_272 , & V_165 ) ;
if ( V_149 < 0 )
goto V_273;
V_149 = F_45 ( V_58 , V_272 , V_64 , V_23 ) ;
if ( V_149 < 0 ) {
if ( V_149 == - V_66 )
F_110 ( L_29
L_30 , V_4 -> V_156 ) ;
goto V_273;
}
if ( V_64 == V_58 -> V_85 )
break;
V_64 = V_58 -> V_85 ;
V_99 = sizeof ( * V_272 ) +
V_64 * sizeof( struct V_274 ) +
V_58 -> V_71 ;
F_54 ( V_58 ) ;
F_23 ( V_272 ) ;
}
V_58 -> V_214 = V_165 ;
V_273:
F_23 ( V_272 ) ;
return V_149 ;
}
static int F_133 ( struct V_3 * V_2 ,
const char * V_88 ,
T_5 V_62 )
{
int V_275 = strlen ( V_88 ) ;
V_70 V_276 ;
int V_21 ;
void * V_217 , * V_91 , * V_277 ;
V_70 V_165 ;
struct V_278 * V_279 ;
if ( V_2 -> V_95 != V_96 )
return - V_45 ;
V_279 = & V_2 -> V_15 -> V_29 -> V_279 ;
V_21 = F_134 ( V_279 , V_2 -> V_191 , & V_276 ) ;
F_10 ( L_31 , V_276 ) ;
if ( V_21 < 0 )
return V_21 ;
V_217 = F_11 ( V_275 + 16 , V_62 ) ;
if ( ! V_217 )
return - V_22 ;
V_91 = V_217 ;
V_277 = V_217 + V_275 + 16 ;
F_135 ( & V_91 , V_277 , V_88 , V_275 , V_280 ) ;
F_136 ( & V_91 , V_277 , V_276 , V_280 ) ;
V_21 = F_118 ( V_2 , V_2 -> V_218 , L_32 , L_33 ,
V_217 , V_91 - V_217 , & V_165 ) ;
F_23 ( V_217 ) ;
if ( V_21 < 0 )
return V_21 ;
F_52 ( & V_2 -> V_94 ) ;
V_2 -> V_58 . V_69 -> V_89 = V_276 ;
F_53 ( & V_2 -> V_94 ) ;
return 0 ;
V_280:
return - V_281 ;
}
static void F_137 ( struct V_3 * V_4 )
{
struct V_282 * V_283 ;
while ( ! F_138 ( & V_4 -> V_86 ) ) {
V_283 = F_139 ( & V_4 -> V_86 , struct V_282 , V_26 ) ;
F_140 ( V_4 , V_283 ) ;
}
}
static int F_109 ( struct V_3 * V_4 )
{
int V_21 ;
struct V_57 V_284 ;
V_70 V_83 ;
int V_285 = 0 ;
V_21 = F_132 ( V_4 , & V_284 ) ;
if ( V_21 < 0 )
return V_21 ;
F_141 ( V_4 -> V_14 , V_284 . V_77 / V_129 ) ;
F_52 ( & V_4 -> V_94 ) ;
V_83 = V_4 -> V_58 . V_69 -> V_89 ;
if ( V_4 -> V_58 . V_85 &&
V_4 -> V_58 . V_69 -> V_86 [ 0 ] == V_83 )
V_285 = 1 ;
F_23 ( V_4 -> V_58 . V_69 ) ;
F_23 ( V_4 -> V_58 . V_72 ) ;
F_23 ( V_4 -> V_58 . V_74 ) ;
V_4 -> V_58 . V_85 = V_284 . V_85 ;
V_4 -> V_58 . V_69 = V_284 . V_69 ;
V_4 -> V_58 . V_72 = V_284 . V_72 ;
V_4 -> V_58 . V_71 = V_284 . V_71 ;
V_4 -> V_58 . V_74 = V_284 . V_74 ;
if ( V_285 )
V_4 -> V_58 . V_69 -> V_89 = V_4 -> V_58 . V_69 -> V_86 [ 0 ] ;
else
V_4 -> V_58 . V_69 -> V_89 = V_83 ;
V_21 = F_142 ( V_4 ) ;
F_53 ( & V_4 -> V_94 ) ;
return V_21 ;
}
static int F_143 ( struct V_3 * V_4 )
{
struct V_13 * V_14 ;
struct V_144 * V_145 ;
int V_149 ;
V_70 V_286 ;
V_70 V_287 = 0 ;
V_149 = F_132 ( V_4 , & V_4 -> V_58 ) ;
if ( V_149 )
return V_149 ;
V_149 = F_142 ( V_4 ) ;
if ( V_149 )
return V_149 ;
V_149 = F_50 ( V_4 , & V_287 ) ;
if ( V_149 )
return V_149 ;
V_149 = - V_22 ;
V_14 = F_144 ( V_288 ) ;
if ( ! V_14 )
goto V_289;
snprintf ( V_14 -> V_290 , sizeof( V_14 -> V_290 ) , V_219 L_34 ,
V_4 -> V_87 ) ;
V_14 -> V_220 = V_4 -> V_220 ;
V_14 -> V_291 = 0 ;
V_14 -> V_292 = & V_293 ;
V_14 -> V_9 = V_4 ;
V_149 = - V_22 ;
V_145 = F_145 ( F_120 , & V_4 -> V_294 ) ;
if ( ! V_145 )
goto V_295;
F_146 ( V_145 , V_129 ) ;
V_286 = F_58 ( & V_4 -> V_58 ) ;
F_147 ( V_145 , V_286 / V_129 ) ;
F_148 ( V_145 , V_286 ) ;
F_149 ( V_145 , V_286 ) ;
F_150 ( V_145 , V_286 ) ;
F_151 ( V_145 , F_126 ) ;
V_14 -> V_271 = V_145 ;
V_145 -> V_250 = V_4 ;
V_4 -> V_14 = V_14 ;
V_4 -> V_145 = V_145 ;
F_141 ( V_14 , V_287 / V_129 ) ;
F_152 ( V_14 ) ;
F_153 ( L_35 ,
V_14 -> V_290 , ( unsigned long long ) V_287 ) ;
return 0 ;
V_295:
F_131 ( V_14 ) ;
V_289:
return V_149 ;
}
static struct V_3 * F_154 ( struct V_1 * V_2 )
{
return F_40 ( V_2 , struct V_3 , V_2 ) ;
}
static T_9 F_155 ( struct V_1 * V_2 ,
struct V_296 * V_297 , char * V_113 )
{
struct V_3 * V_4 = F_154 ( V_2 ) ;
return sprintf ( V_113 , L_36 , ( unsigned long long ) V_4 -> V_58 . V_77 ) ;
}
static T_9 F_156 ( struct V_1 * V_2 ,
struct V_296 * V_297 , char * V_113 )
{
struct V_3 * V_4 = F_154 ( V_2 ) ;
return sprintf ( V_113 , L_37 , V_4 -> V_220 ) ;
}
static T_9 F_157 ( struct V_1 * V_2 ,
struct V_296 * V_297 , char * V_113 )
{
struct V_3 * V_4 = F_154 ( V_2 ) ;
return sprintf ( V_113 , L_38 ,
F_158 ( V_4 -> V_15 -> V_29 ) ) ;
}
static T_9 F_159 ( struct V_1 * V_2 ,
struct V_296 * V_297 , char * V_113 )
{
struct V_3 * V_4 = F_154 ( V_2 ) ;
return sprintf ( V_113 , L_39 , V_4 -> V_298 ) ;
}
static T_9 F_160 ( struct V_1 * V_2 ,
struct V_296 * V_297 , char * V_113 )
{
struct V_3 * V_4 = F_154 ( V_2 ) ;
return sprintf ( V_113 , L_39 , V_4 -> V_156 ) ;
}
static T_9 F_161 ( struct V_1 * V_2 ,
struct V_296 * V_297 ,
char * V_113 )
{
struct V_3 * V_4 = F_154 ( V_2 ) ;
return sprintf ( V_113 , L_39 , V_4 -> V_88 ) ;
}
static T_9 F_162 ( struct V_1 * V_2 ,
struct V_296 * V_297 ,
const char * V_113 ,
T_3 V_90 )
{
struct V_3 * V_4 = F_154 ( V_2 ) ;
int V_149 ;
int V_21 = V_90 ;
F_14 ( & V_27 , V_28 ) ;
V_149 = F_109 ( V_4 ) ;
if ( V_149 < 0 )
V_21 = V_149 ;
F_21 ( & V_27 ) ;
return V_21 ;
}
static void F_163 ( struct V_1 * V_2 )
{
}
static T_9 F_164 ( struct V_1 * V_2 ,
struct V_296 * V_297 ,
char * V_113 )
{
struct V_282 * V_283 = F_40 ( V_2 , struct V_282 , V_2 ) ;
return sprintf ( V_113 , L_36 , ( unsigned long long ) V_283 -> V_90 ) ;
}
static T_9 F_165 ( struct V_1 * V_2 ,
struct V_296 * V_297 ,
char * V_113 )
{
struct V_282 * V_283 = F_40 ( V_2 , struct V_282 , V_2 ) ;
return sprintf ( V_113 , L_36 , ( unsigned long long ) V_283 -> V_87 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_282 * V_283 = F_40 ( V_2 , struct V_282 , V_2 ) ;
F_23 ( V_283 -> V_299 ) ;
F_23 ( V_283 ) ;
}
static void F_140 ( struct V_3 * V_4 ,
struct V_282 * V_283 )
{
F_41 ( & V_283 -> V_26 ) ;
F_167 ( & V_283 -> V_2 ) ;
}
static int F_168 ( struct V_3 * V_4 ,
struct V_282 * V_283 ,
struct V_1 * V_300 )
{
struct V_1 * V_2 = & V_283 -> V_2 ;
int V_21 ;
V_2 -> type = & V_301 ;
V_2 -> V_300 = V_300 ;
V_2 -> V_302 = F_166 ;
F_169 ( V_2 , L_40 , V_283 -> V_299 ) ;
V_21 = F_170 ( V_2 ) ;
return V_21 ;
}
static int F_171 ( struct V_3 * V_4 ,
int V_63 , const char * V_299 ,
struct V_282 * * V_303 )
{
int V_21 ;
struct V_282 * V_283 = F_35 ( sizeof( * V_283 ) , V_23 ) ;
if ( ! V_283 )
return - V_22 ;
V_283 -> V_299 = F_172 ( V_299 , V_23 ) ;
V_283 -> V_90 = V_4 -> V_58 . V_74 [ V_63 ] ;
V_283 -> V_87 = V_4 -> V_58 . V_69 -> V_86 [ V_63 ] ;
if ( F_173 ( & V_4 -> V_2 ) ) {
V_21 = F_168 ( V_4 , V_283 ,
& V_4 -> V_2 ) ;
if ( V_21 < 0 )
goto V_304;
}
* V_303 = V_283 ;
return 0 ;
V_304:
F_23 ( V_283 -> V_299 ) ;
F_23 ( V_283 ) ;
return V_21 ;
}
const char * F_174 ( const char * V_299 , const char * V_305 )
{
if ( V_299 < V_305 + 2 )
return NULL ;
V_299 -= 2 ;
while ( * V_299 ) {
if ( V_299 == V_305 )
return V_305 ;
V_299 -- ;
}
return V_299 + 1 ;
}
static int F_142 ( struct V_3 * V_4 )
{
const char * V_299 , * V_306 ;
int V_63 = V_4 -> V_58 . V_85 ;
struct V_282 * V_283 , * V_307 = NULL ;
int V_21 ;
struct V_308 * V_91 , * V_309 ;
V_306 = V_4 -> V_58 . V_72 ;
V_299 = V_306 + V_4 -> V_58 . V_71 ;
F_175 (p, n, &rbd_dev->snaps) {
V_70 V_310 ;
V_307 = F_176 ( V_91 , struct V_282 , V_26 ) ;
if ( V_63 )
V_310 = V_4 -> V_58 . V_69 -> V_86 [ V_63 - 1 ] ;
if ( ! V_63 || V_307 -> V_87 < V_310 ) {
F_140 ( V_4 , V_307 ) ;
continue;
}
if ( V_307 -> V_87 == V_310 ) {
V_63 -- ;
V_299 = F_174 ( V_299 , V_306 ) ;
continue;
}
for (; V_63 > 0 ;
V_63 -- , V_299 = F_174 ( V_299 , V_306 ) ) {
if ( ! V_299 ) {
F_93 ( 1 ) ;
return - V_45 ;
}
V_310 = V_4 -> V_58 . V_69 -> V_86 [ V_63 ] ;
if ( V_310 >= V_307 -> V_87 )
break;
V_21 = F_171 ( V_4 , V_63 - 1 , V_299 , & V_283 ) ;
if ( V_21 < 0 )
return V_21 ;
F_177 ( & V_283 -> V_26 , V_309 ) ;
V_91 = & V_283 -> V_26 ;
}
}
for (; V_63 > 0 ; V_63 -- ) {
V_299 = F_174 ( V_299 , V_306 ) ;
if ( ! V_299 ) {
F_93 ( 1 ) ;
return - V_45 ;
}
V_21 = F_171 ( V_4 , V_63 - 1 , V_299 , & V_283 ) ;
if ( V_21 < 0 )
return V_21 ;
F_177 ( & V_283 -> V_26 , & V_4 -> V_86 ) ;
}
return 0 ;
}
static int F_178 ( struct V_3 * V_4 )
{
int V_21 ;
struct V_1 * V_2 ;
struct V_282 * V_283 ;
F_14 ( & V_27 , V_28 ) ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_311 = & V_312 ;
V_2 -> type = & V_313 ;
V_2 -> V_300 = & V_314 ;
V_2 -> V_302 = V_315 ;
F_169 ( V_2 , L_34 , V_4 -> V_87 ) ;
V_21 = F_170 ( V_2 ) ;
if ( V_21 < 0 )
goto V_289;
F_27 (snap, &rbd_dev->snaps, node) {
V_21 = F_168 ( V_4 , V_283 ,
& V_4 -> V_2 ) ;
if ( V_21 < 0 )
break;
}
V_289:
F_21 ( & V_27 ) ;
return V_21 ;
}
static void F_179 ( struct V_3 * V_4 )
{
F_167 ( & V_4 -> V_2 ) ;
}
static int F_180 ( struct V_3 * V_4 )
{
int V_21 , V_149 ;
do {
V_21 = F_111 ( V_4 , V_4 -> V_218 ,
V_4 -> V_58 . V_214 ) ;
if ( V_21 == - V_281 ) {
F_14 ( & V_27 , V_28 ) ;
V_149 = F_109 ( V_4 ) ;
F_21 ( & V_27 ) ;
if ( V_149 < 0 )
return V_149 ;
}
} while ( V_21 == - V_281 );
return V_21 ;
}
static void F_181 ( struct V_3 * V_4 )
{
V_4 -> V_87 = F_182 ( & V_316 ) ;
F_18 ( & V_317 ) ;
F_19 ( & V_4 -> V_26 , & V_318 ) ;
F_20 ( & V_317 ) ;
}
static void F_183 ( struct V_3 * V_4 )
{
struct V_308 * V_108 ;
int V_319 = V_4 -> V_87 ;
int V_320 ;
F_33 ( V_319 < 1 ) ;
F_18 ( & V_317 ) ;
F_184 ( & V_4 -> V_26 ) ;
if ( V_319 != F_185 ( & V_316 ) ) {
F_20 ( & V_317 ) ;
return;
}
V_320 = 0 ;
F_186 (tmp, &rbd_dev_list) {
struct V_3 * V_4 ;
V_4 = F_176 ( V_108 , struct V_3 , V_26 ) ;
if ( V_319 > V_320 )
V_320 = V_319 ;
}
F_20 ( & V_317 ) ;
F_187 ( & V_316 , V_319 , V_320 ) ;
}
static inline T_3 F_188 ( const char * * V_113 )
{
const char * V_321 = L_41 ;
* V_113 += strspn ( * V_113 , V_321 ) ;
return strcspn ( * V_113 , V_321 ) ;
}
static inline T_3 F_189 ( const char * * V_113 ,
char * V_42 ,
T_3 V_322 )
{
T_3 V_99 ;
V_99 = F_188 ( V_113 ) ;
if ( V_99 < V_322 ) {
memcpy ( V_42 , * V_113 , V_99 ) ;
* ( V_42 + V_99 ) = '\0' ;
}
* V_113 += V_99 ;
return V_99 ;
}
static int F_190 ( struct V_3 * V_4 ,
const char * V_113 ,
const char * * V_323 ,
T_3 * V_324 ,
char * V_53 ,
T_3 V_325 )
{
T_3 V_99 ;
V_99 = F_188 ( & V_113 ) ;
if ( ! V_99 )
return - V_45 ;
* V_324 = V_99 + 1 ;
* V_323 = V_113 ;
V_113 += V_99 ;
V_99 = F_189 ( & V_113 , V_53 , V_325 ) ;
if ( ! V_99 || V_99 >= V_325 )
return - V_45 ;
V_99 = F_189 ( & V_113 , V_4 -> V_298 , sizeof ( V_4 -> V_298 ) ) ;
if ( ! V_99 || V_99 >= sizeof ( V_4 -> V_298 ) )
return - V_45 ;
V_99 = F_189 ( & V_113 , V_4 -> V_156 , sizeof ( V_4 -> V_156 ) ) ;
if ( ! V_99 || V_99 >= sizeof ( V_4 -> V_156 ) )
return - V_45 ;
V_4 -> V_326 = V_99 ;
F_51 ( V_327
< V_328 + sizeof ( V_329 ) ) ;
sprintf ( V_4 -> V_218 , L_42 , V_4 -> V_156 , V_329 ) ;
V_99 = F_189 ( & V_113 , V_4 -> V_88 , sizeof ( V_4 -> V_88 ) ) ;
if ( ! V_99 )
memcpy ( V_4 -> V_88 , V_93 ,
sizeof ( V_93 ) ) ;
else if ( V_99 >= sizeof ( V_4 -> V_88 ) )
return - V_45 ;
return 0 ;
}
static T_9 F_191 ( struct V_330 * V_311 ,
const char * V_113 ,
T_3 V_331 )
{
struct V_3 * V_4 ;
const char * V_323 = NULL ;
T_3 V_324 = 0 ;
char * V_53 = NULL ;
struct V_175 * V_176 ;
int V_149 = - V_22 ;
if ( ! F_192 ( V_332 ) )
return - V_333 ;
V_4 = F_35 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
goto V_334;
V_53 = F_11 ( V_331 , V_23 ) ;
if ( ! V_53 )
goto V_334;
F_193 ( & V_4 -> V_294 ) ;
F_13 ( & V_4 -> V_26 ) ;
F_13 ( & V_4 -> V_86 ) ;
F_194 ( & V_4 -> V_94 ) ;
F_194 ( & V_4 -> V_94 ) ;
F_181 ( V_4 ) ;
F_51 ( V_335
< sizeof ( V_219 ) + V_336 ) ;
sprintf ( V_4 -> V_299 , L_43 , V_219 , V_4 -> V_87 ) ;
V_149 = F_190 ( V_4 , V_113 , & V_323 , & V_324 ,
V_53 , V_331 ) ;
if ( V_149 )
goto V_337;
V_4 -> V_15 = F_34 ( V_323 , V_324 - 1 ,
V_53 ) ;
if ( F_16 ( V_4 -> V_15 ) ) {
V_149 = F_99 ( V_4 -> V_15 ) ;
goto V_337;
}
V_176 = & V_4 -> V_15 -> V_29 -> V_176 ;
V_149 = F_195 ( V_176 -> V_338 , V_4 -> V_298 ) ;
if ( V_149 < 0 )
goto V_339;
V_4 -> V_191 = V_149 ;
V_149 = F_196 ( 0 , V_4 -> V_299 ) ;
if ( V_149 < 0 )
goto V_339;
V_4 -> V_220 = V_149 ;
V_149 = F_178 ( V_4 ) ;
if ( V_149 )
goto V_340;
V_149 = F_143 ( V_4 ) ;
if ( V_149 )
goto V_341;
V_149 = F_180 ( V_4 ) ;
if ( V_149 )
goto V_341;
return V_331 ;
V_341:
F_179 ( V_4 ) ;
F_23 ( V_53 ) ;
return V_149 ;
V_340:
F_197 ( V_4 -> V_220 , V_4 -> V_299 ) ;
V_339:
F_42 ( V_4 ) ;
V_337:
F_183 ( V_4 ) ;
V_334:
F_23 ( V_53 ) ;
F_23 ( V_4 ) ;
F_10 ( L_44 , V_113 ) ;
F_198 ( V_332 ) ;
return ( T_9 ) V_149 ;
}
static struct V_3 * F_199 ( unsigned long V_87 )
{
struct V_308 * V_108 ;
struct V_3 * V_4 ;
F_18 ( & V_317 ) ;
F_200 (tmp, &rbd_dev_list) {
V_4 = F_176 ( V_108 , struct V_3 , V_26 ) ;
if ( V_4 -> V_87 == V_87 ) {
F_20 ( & V_317 ) ;
return V_4 ;
}
}
F_20 ( & V_317 ) ;
return NULL ;
}
static void V_315 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_154 ( V_2 ) ;
if ( V_4 -> V_224 ) {
struct V_342 * V_29 = V_4 -> V_15 -> V_29 ;
F_201 ( & V_29 -> V_176 ,
V_4 -> V_224 ) ;
}
if ( V_4 -> V_222 )
F_114 ( V_4 , V_4 -> V_218 ) ;
F_42 ( V_4 ) ;
F_128 ( V_4 ) ;
F_197 ( V_4 -> V_220 , V_4 -> V_299 ) ;
F_183 ( V_4 ) ;
F_23 ( V_4 ) ;
F_198 ( V_332 ) ;
}
static T_9 F_202 ( struct V_330 * V_311 ,
const char * V_113 ,
T_3 V_331 )
{
struct V_3 * V_4 = NULL ;
int V_343 , V_149 ;
unsigned long V_344 ;
int V_21 = V_331 ;
V_149 = F_203 ( V_113 , 10 , & V_344 ) ;
if ( V_149 )
return V_149 ;
V_343 = ( int ) V_344 ;
if ( V_343 != V_344 )
return - V_45 ;
F_14 ( & V_27 , V_28 ) ;
V_4 = F_199 ( V_343 ) ;
if ( ! V_4 ) {
V_21 = - V_92 ;
goto V_97;
}
F_137 ( V_4 ) ;
F_179 ( V_4 ) ;
V_97:
F_21 ( & V_27 ) ;
return V_21 ;
}
static T_9 F_204 ( struct V_1 * V_2 ,
struct V_296 * V_297 ,
const char * V_113 ,
T_3 V_331 )
{
struct V_3 * V_4 = F_154 ( V_2 ) ;
int V_21 ;
char * V_299 = F_11 ( V_331 + 1 , V_23 ) ;
if ( ! V_299 )
return - V_22 ;
snprintf ( V_299 , V_331 , L_45 , V_113 ) ;
F_14 ( & V_27 , V_28 ) ;
V_21 = F_133 ( V_4 ,
V_299 , V_23 ) ;
if ( V_21 < 0 )
goto V_345;
V_21 = F_109 ( V_4 ) ;
if ( V_21 < 0 )
goto V_345;
F_21 ( & V_27 ) ;
F_116 ( V_4 , V_4 -> V_218 ) ;
V_21 = V_331 ;
F_23 ( V_299 ) ;
return V_21 ;
V_345:
F_21 ( & V_27 ) ;
F_23 ( V_299 ) ;
return V_21 ;
}
static int F_205 ( void )
{
int V_21 ;
V_21 = F_170 ( & V_314 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_206 ( & V_312 ) ;
if ( V_21 < 0 )
F_167 ( & V_314 ) ;
return V_21 ;
}
static void F_207 ( void )
{
F_208 ( & V_312 ) ;
F_167 ( & V_314 ) ;
}
int T_10 F_209 ( void )
{
int V_149 ;
V_149 = F_205 () ;
if ( V_149 )
return V_149 ;
F_153 ( L_46 V_346 L_47 ) ;
return 0 ;
}
void T_11 F_210 ( void )
{
F_207 () ;
}
