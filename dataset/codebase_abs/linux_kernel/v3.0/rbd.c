static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_2 * F_3 ( struct V_1 * V_4 )
{
return F_4 ( & V_4 -> V_3 ) ;
}
static void F_5 ( struct V_1 * V_4 )
{
F_6 ( & V_4 -> V_3 ) ;
}
static int F_7 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_4 = V_9 -> V_11 ;
F_3 ( V_4 ) ;
F_8 ( V_6 , V_4 -> V_12 ) ;
if ( ( V_7 & V_13 ) && V_4 -> V_12 )
return - V_14 ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 , T_1 V_7 )
{
struct V_1 * V_4 = V_9 -> V_11 ;
F_5 ( V_4 ) ;
return 0 ;
}
static struct V_15 * F_10 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_15 * V_20 ;
int V_21 = - V_22 ;
F_11 ( L_1 ) ;
V_20 = F_12 ( sizeof( struct V_15 ) , V_23 ) ;
if ( ! V_20 )
goto V_24;
F_13 ( & V_20 -> V_25 ) ;
F_14 ( & V_20 -> V_26 ) ;
V_20 -> V_27 = F_15 ( V_17 , V_20 ) ;
if ( F_16 ( V_20 -> V_27 ) )
goto V_28;
V_17 = NULL ;
V_21 = F_17 ( V_20 -> V_27 ) ;
if ( V_21 < 0 )
goto V_29;
V_20 -> V_19 = V_19 ;
F_18 ( & V_30 ) ;
F_19 ( & V_20 -> V_26 , & V_31 ) ;
F_20 ( & V_30 ) ;
F_11 ( L_2 , V_20 ) ;
return V_20 ;
V_29:
F_21 ( V_20 -> V_27 ) ;
V_28:
F_22 ( V_20 ) ;
V_24:
if ( V_17 )
F_23 ( V_17 ) ;
return F_24 ( V_21 ) ;
}
static struct V_15 * F_25 ( struct V_16 * V_17 )
{
struct V_15 * V_32 ;
if ( V_17 -> V_33 & V_34 )
return NULL ;
F_26 (client_node, &rbd_client_list, node)
if ( F_27 ( V_17 , V_32 -> V_27 ) == 0 )
return V_32 ;
return NULL ;
}
static int F_28 ( char * V_35 , void * V_36 )
{
struct V_18 * V_37 = V_36 ;
T_2 V_38 [ V_39 ] ;
int V_40 , V_41 , V_21 ;
V_40 = F_29 ( ( char * ) V_35 , V_42 , V_38 ) ;
if ( V_40 < 0 )
return - V_43 ;
if ( V_40 < V_44 ) {
V_21 = F_30 ( & V_38 [ 0 ] , & V_41 ) ;
if ( V_21 < 0 ) {
F_31 ( L_3
L_4 , V_35 ) ;
return V_21 ;
}
F_11 ( L_5 , V_40 , V_41 ) ;
} else if ( V_40 > V_44 && V_40 < V_45 ) {
F_11 ( L_6 , V_40 ,
V_38 [ 0 ] . V_46 ) ;
} else {
F_11 ( L_7 , V_40 ) ;
}
switch ( V_40 ) {
case V_47 :
V_37 -> V_48 = V_41 ;
break;
default:
F_32 ( V_40 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_4 , const char * V_49 ,
char * V_50 )
{
struct V_15 * V_20 ;
struct V_16 * V_17 ;
int V_21 ;
struct V_18 * V_19 ;
V_19 = F_34 ( sizeof( * V_19 ) , V_23 ) ;
if ( ! V_19 )
return - V_22 ;
V_19 -> V_48 = V_51 ;
V_21 = F_35 ( & V_17 , V_50 , V_49 ,
V_49 + strlen ( V_49 ) , F_28 , V_19 ) ;
if ( V_21 < 0 )
goto V_52;
F_18 ( & V_30 ) ;
V_20 = F_25 ( V_17 ) ;
if ( V_20 ) {
F_23 ( V_17 ) ;
F_36 ( & V_20 -> V_25 ) ;
V_4 -> V_15 = V_20 ;
V_4 -> V_27 = V_20 -> V_27 ;
F_20 ( & V_30 ) ;
return 0 ;
}
F_20 ( & V_30 ) ;
V_20 = F_10 ( V_17 , V_19 ) ;
if ( F_16 ( V_20 ) ) {
V_21 = F_37 ( V_20 ) ;
goto V_52;
}
V_4 -> V_15 = V_20 ;
V_4 -> V_27 = V_20 -> V_27 ;
return 0 ;
V_52:
F_22 ( V_19 ) ;
return V_21 ;
}
static void F_38 ( struct V_25 * V_25 )
{
struct V_15 * V_20 = F_2 ( V_25 , struct V_15 , V_25 ) ;
F_11 ( L_8 , V_20 ) ;
F_18 ( & V_30 ) ;
F_39 ( & V_20 -> V_26 ) ;
F_20 ( & V_30 ) ;
F_21 ( V_20 -> V_27 ) ;
F_22 ( V_20 -> V_19 ) ;
F_22 ( V_20 ) ;
}
static void F_40 ( struct V_1 * V_4 )
{
F_41 ( & V_4 -> V_15 -> V_25 , F_38 ) ;
V_4 -> V_15 = NULL ;
V_4 -> V_27 = NULL ;
}
static void F_42 ( struct V_25 * V_25 )
{
struct V_53 * V_54 =
F_2 ( V_25 , struct V_53 , V_25 ) ;
F_11 ( L_9 , V_54 ) ;
F_22 ( V_54 ) ;
}
static int F_43 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
int V_59 ,
T_3 V_60 )
{
int V_61 ;
T_4 V_62 = F_44 ( V_58 -> V_62 ) ;
int V_21 = - V_22 ;
F_45 ( & V_56 -> V_63 ) ;
V_56 -> V_64 = F_46 ( V_58 -> V_64 ) ;
V_56 -> V_65 = F_12 ( sizeof( struct V_66 ) +
V_62 *
sizeof( struct V_67 ) ,
V_60 ) ;
if ( ! V_56 -> V_65 )
return - V_22 ;
if ( V_62 ) {
V_56 -> V_68 = F_12 ( V_56 -> V_64 ,
V_23 ) ;
if ( ! V_56 -> V_68 )
goto V_69;
V_56 -> V_70 = F_12 ( V_62 * sizeof( V_71 ) ,
V_23 ) ;
if ( ! V_56 -> V_70 )
goto V_72;
} else {
V_56 -> V_68 = NULL ;
V_56 -> V_70 = NULL ;
}
memcpy ( V_56 -> V_73 , V_58 -> V_73 ,
sizeof( V_58 -> V_73 ) ) ;
V_56 -> V_74 = F_46 ( V_58 -> V_74 ) ;
V_56 -> V_75 = V_58 -> V_50 . V_76 ;
V_56 -> V_77 = V_58 -> V_50 . V_77 ;
V_56 -> V_78 = V_58 -> V_50 . V_78 ;
F_47 ( & V_56 -> V_65 -> V_79 , 1 ) ;
V_56 -> V_80 = F_46 ( V_58 -> V_80 ) ;
V_56 -> V_65 -> V_81 = V_62 ;
V_56 -> V_82 = V_62 ;
if ( V_62 &&
V_59 == V_62 ) {
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
V_56 -> V_65 -> V_83 [ V_61 ] =
F_46 ( V_58 -> V_83 [ V_61 ] . V_84 ) ;
V_56 -> V_70 [ V_61 ] =
F_46 ( V_58 -> V_83 [ V_61 ] . V_74 ) ;
}
memcpy ( V_56 -> V_68 , & V_58 -> V_83 [ V_61 ] ,
V_56 -> V_64 ) ;
}
return 0 ;
V_72:
F_22 ( V_56 -> V_68 ) ;
V_69:
F_22 ( V_56 -> V_65 ) ;
return V_21 ;
}
static int F_48 ( struct V_55 * V_56 , int V_85 )
{
return V_56 -> V_82 - V_85 ;
}
static V_71 F_49 ( struct V_1 * V_4 )
{
struct V_55 * V_56 = & V_4 -> V_56 ;
if ( ! V_4 -> V_86 )
return 0 ;
return V_56 -> V_65 -> V_83 [ F_48 ( V_56 , V_4 -> V_86 ) ] ;
}
static int F_50 ( struct V_55 * V_56 , const char * V_87 ,
V_71 * V_88 , V_71 * V_89 )
{
int V_61 ;
char * V_90 = V_56 -> V_68 ;
for ( V_61 = 0 ; V_61 < V_56 -> V_82 ; V_61 ++ , V_90 += strlen ( V_90 ) + 1 ) {
if ( strcmp ( V_87 , V_90 ) == 0 )
break;
}
if ( V_61 == V_56 -> V_82 )
return - V_91 ;
if ( V_88 )
* V_88 = V_56 -> V_65 -> V_83 [ V_61 ] ;
if ( V_89 )
* V_89 = V_56 -> V_70 [ V_61 ] ;
return V_61 ;
}
static int F_51 ( struct V_1 * V_3 ,
const char * V_87 ,
V_71 * V_89 )
{
struct V_55 * V_56 = & V_3 -> V_56 ;
struct V_66 * V_65 = V_56 -> V_65 ;
int V_21 = - V_91 ;
F_52 ( & V_56 -> V_63 ) ;
if ( ! V_87 ||
! * V_87 ||
strcmp ( V_87 , L_10 ) == 0 ||
strcmp ( V_87 , V_92 ) == 0 ) {
if ( V_56 -> V_82 )
V_65 -> V_88 = V_56 -> V_80 ;
else
V_65 -> V_88 = 0 ;
V_3 -> V_86 = 0 ;
V_3 -> V_12 = 0 ;
if ( V_89 )
* V_89 = V_56 -> V_74 ;
} else {
V_21 = F_50 ( V_56 , V_87 , & V_65 -> V_88 , V_89 ) ;
if ( V_21 < 0 )
goto V_93;
V_3 -> V_86 = V_56 -> V_82 - V_21 ;
V_3 -> V_12 = 1 ;
}
V_21 = 0 ;
V_93:
F_53 ( & V_56 -> V_63 ) ;
return V_21 ;
}
static void F_54 ( struct V_55 * V_56 )
{
F_22 ( V_56 -> V_65 ) ;
F_22 ( V_56 -> V_68 ) ;
F_22 ( V_56 -> V_70 ) ;
}
static V_71 F_55 ( struct V_55 * V_56 ,
const char * V_73 ,
V_71 V_94 , V_71 V_95 ,
char * V_96 , V_71 * V_97 )
{
V_71 V_98 = V_94 >> V_56 -> V_75 ;
if ( V_96 )
snprintf ( V_96 , V_99 ,
L_11 , V_73 , V_98 ) ;
V_94 = V_94 & ( ( 1 << V_56 -> V_75 ) - 1 ) ;
V_95 = F_56 ( V_71 , V_95 , ( 1 << V_56 -> V_75 ) - V_94 ) ;
if ( V_97 )
* V_97 = V_94 ;
return V_95 ;
}
static int F_57 ( struct V_55 * V_56 ,
V_71 V_94 , V_71 V_95 )
{
V_71 V_100 = V_94 >> V_56 -> V_75 ;
V_71 V_101 = ( V_94 + V_95 - 1 ) >> V_56 -> V_75 ;
return V_101 - V_100 + 1 ;
}
static void F_58 ( struct V_102 * V_103 )
{
struct V_102 * V_104 ;
while ( V_103 ) {
V_104 = V_103 ;
V_103 = V_103 -> V_105 ;
F_59 ( V_104 ) ;
}
}
static void F_60 ( struct V_102 * V_103 , int V_106 )
{
struct V_107 * V_108 ;
unsigned long V_33 ;
void * V_109 ;
int V_61 ;
int V_110 = 0 ;
while ( V_103 ) {
F_61 (bv, chain, i) {
if ( V_110 + V_108 -> V_111 > V_106 ) {
int V_112 = F_62 ( V_106 - V_110 , 0 ) ;
V_109 = F_63 ( V_108 , & V_33 ) ;
memset ( V_109 + V_112 , 0 ,
V_108 -> V_111 - V_112 ) ;
F_64 ( V_109 , & V_33 ) ;
}
V_110 += V_108 -> V_111 ;
}
V_103 = V_103 -> V_105 ;
}
}
static struct V_102 * F_65 ( struct V_102 * * V_113 , struct V_102 * * V_114 ,
struct V_115 * * V_116 ,
int V_95 , T_3 V_117 )
{
struct V_102 * V_104 , * V_118 = * V_113 , * V_119 = NULL , * V_120 = NULL ;
int V_121 = 0 ;
if ( * V_116 ) {
F_66 ( * V_116 ) ;
* V_116 = NULL ;
}
while ( V_118 && ( V_121 < V_95 ) ) {
V_104 = F_67 ( V_117 , V_118 -> V_122 ) ;
if ( ! V_104 )
goto V_123;
if ( V_121 + V_118 -> V_124 > V_95 ) {
struct V_115 * V_116 ;
F_11 ( L_12
L_13 ,
( int ) V_121 , ( int ) V_95 - V_121 ,
( int ) V_118 -> V_124 ) ;
V_116 = F_68 ( V_118 , ( V_95 - V_121 ) / 512ULL ) ;
if ( ! V_116 )
goto V_123;
F_69 ( V_104 , & V_116 -> V_125 ) ;
* V_114 = & V_116 -> V_126 ;
} else {
F_69 ( V_104 , V_118 ) ;
* V_114 = V_118 -> V_105 ;
}
V_104 -> V_127 = NULL ;
V_117 &= ~ V_128 ;
V_104 -> V_105 = NULL ;
if ( ! V_119 ) {
V_119 = V_120 = V_104 ;
} else {
V_120 -> V_105 = V_104 ;
V_120 = V_104 ;
}
V_118 = V_118 -> V_105 ;
V_121 += V_104 -> V_124 ;
}
F_32 ( V_121 < V_95 ) ;
if ( V_120 )
V_120 -> V_105 = NULL ;
* V_113 = V_118 ;
return V_119 ;
V_123:
F_11 ( L_14 ) ;
F_58 ( V_119 ) ;
return NULL ;
}
static int F_70 ( struct V_129 * * V_130 ,
int V_131 ,
int V_132 ,
T_4 V_133 )
{
* V_130 = F_34 ( sizeof( struct V_129 ) * ( V_131 + 1 ) ,
V_134 ) ;
if ( ! * V_130 )
return - V_22 ;
( * V_130 ) [ 0 ] . V_135 = V_132 ;
( * V_130 ) [ 0 ] . V_133 = V_133 ;
return 0 ;
}
static void F_71 ( struct V_129 * V_130 )
{
F_22 ( V_130 ) ;
}
static void F_72 ( struct V_136 * V_137 ,
struct V_53 * V_54 ,
int V_138 ,
int V_21 , V_71 V_95 )
{
struct V_139 * V_140 ;
int V_141 , F_62 , V_61 ;
F_11 ( L_15 ,
V_54 , V_138 , V_21 , V_95 ) ;
if ( ! V_137 )
return;
if ( ! V_54 ) {
F_73 ( V_137 , V_21 , V_95 ) ;
return;
}
V_140 = V_137 -> V_140 ;
F_74 ( V_140 -> V_142 ) ;
V_54 -> V_143 [ V_138 ] . V_93 = 1 ;
V_54 -> V_143 [ V_138 ] . V_144 = V_21 ;
V_54 -> V_143 [ V_138 ] . V_145 = V_95 ;
F_62 = V_141 = V_54 -> V_146 ;
while ( F_62 < V_54 -> V_121 && V_54 -> V_143 [ F_62 ] . V_93 )
F_62 ++ ;
for ( V_61 = V_141 ; V_61 < F_62 ; V_61 ++ ) {
F_75 ( V_137 , V_54 -> V_143 [ V_61 ] . V_144 ,
V_54 -> V_143 [ V_61 ] . V_145 ) ;
V_54 -> V_146 ++ ;
F_41 ( & V_54 -> V_25 , F_42 ) ;
}
F_76 ( V_140 -> V_142 ) ;
}
static void F_77 ( struct V_147 * V_148 ,
int V_21 , V_71 V_95 )
{
F_72 ( V_148 -> V_137 , V_148 -> V_54 , V_148 -> V_149 , V_21 , V_95 ) ;
}
static int F_78 ( struct V_136 * V_137 ,
struct V_1 * V_3 ,
struct V_66 * V_65 ,
V_71 V_150 ,
const char * V_151 , V_71 V_94 , V_71 V_95 ,
struct V_102 * V_102 ,
struct V_152 * * V_153 ,
int V_154 ,
int V_33 ,
struct V_129 * V_130 ,
int V_155 ,
struct V_53 * V_54 ,
int V_149 ,
void (* F_79)( struct V_156 * V_148 ,
struct V_157 * V_158 ) ,
struct V_156 * * V_159 ,
V_71 * V_160 )
{
struct V_156 * V_148 ;
struct V_161 * V_162 ;
int V_21 ;
V_71 V_163 ;
struct V_164 V_165 = V_166 ;
struct V_147 * V_167 ;
struct V_168 * V_169 ;
struct V_55 * V_56 = & V_3 -> V_56 ;
V_167 = F_34 ( sizeof( * V_167 ) , V_134 ) ;
if ( ! V_167 ) {
if ( V_54 )
F_72 ( V_137 , V_54 , V_149 ,
- V_22 , V_95 ) ;
return - V_22 ;
}
if ( V_54 ) {
V_167 -> V_54 = V_54 ;
V_167 -> V_149 = V_149 ;
}
F_11 ( L_16 , V_151 , V_95 , V_94 ) ;
F_80 ( & V_56 -> V_63 ) ;
V_148 = F_81 ( & V_3 -> V_27 -> V_170 , V_33 ,
V_65 ,
V_130 ,
false ,
V_134 , V_153 , V_102 ) ;
if ( ! V_148 ) {
F_82 ( & V_56 -> V_63 ) ;
V_21 = - V_22 ;
goto V_171;
}
V_148 -> V_172 = F_79 ;
V_167 -> V_137 = V_137 ;
V_167 -> V_102 = V_102 ;
V_167 -> V_153 = V_153 ;
V_167 -> V_95 = V_95 ;
V_148 -> V_173 = V_167 ;
V_169 = V_148 -> V_174 -> V_175 . V_176 ;
V_169 -> V_150 = F_83 ( V_177 ) ;
strncpy ( V_148 -> V_178 , V_151 , sizeof( V_148 -> V_178 ) ) ;
V_148 -> V_179 = strlen ( V_148 -> V_178 ) ;
V_162 = & V_148 -> V_180 ;
memset ( V_162 , 0 , sizeof( * V_162 ) ) ;
V_162 -> V_181 = F_84 ( 1 << V_182 ) ;
V_162 -> V_183 = F_84 ( 1 ) ;
V_162 -> V_184 = F_84 ( 1 << V_182 ) ;
V_162 -> V_185 = F_84 ( - 1 ) ;
V_162 -> V_186 = F_84 ( V_3 -> V_187 ) ;
F_85 ( & V_3 -> V_27 -> V_170 , V_162 , V_150 ,
V_94 , & V_95 , & V_163 , V_148 , V_130 ) ;
F_86 ( V_148 , V_94 , & V_95 ,
V_130 ,
V_65 ,
& V_165 ,
V_148 -> V_178 , V_148 -> V_179 ) ;
F_82 ( & V_56 -> V_63 ) ;
if ( V_159 ) {
F_87 ( & V_3 -> V_27 -> V_170 , V_148 ) ;
* V_159 = V_148 ;
}
V_21 = F_88 ( & V_3 -> V_27 -> V_170 , V_148 , false ) ;
if ( V_21 < 0 )
goto V_52;
if ( ! F_79 ) {
V_21 = F_89 ( & V_3 -> V_27 -> V_170 , V_148 ) ;
if ( V_160 )
* V_160 = F_46 ( V_148 -> V_188 . V_189 ) ;
F_11 ( L_17 ,
F_46 ( V_148 -> V_188 . V_189 ) ) ;
F_90 ( V_148 ) ;
}
return V_21 ;
V_52:
F_58 ( V_167 -> V_102 ) ;
F_90 ( V_148 ) ;
V_171:
F_77 ( V_167 , V_21 , V_95 ) ;
F_22 ( V_167 ) ;
return V_21 ;
}
static void F_91 ( struct V_156 * V_148 , struct V_157 * V_158 )
{
struct V_147 * V_167 = V_148 -> V_173 ;
struct V_190 * V_191 ;
struct V_192 * V_135 ;
T_5 V_144 ;
V_71 V_145 ;
int V_193 ;
V_191 = V_158 -> V_175 . V_176 ;
F_92 ( F_44 ( V_191 -> V_131 ) == 0 ) ;
V_135 = ( void * ) ( V_191 + 1 ) ;
V_144 = F_44 ( V_191 -> V_194 ) ;
V_145 = F_46 ( V_135 -> V_195 . V_196 ) ;
V_193 = ( F_44 ( V_135 -> V_135 ) == V_197 ) ;
F_11 ( L_18 , V_145 , V_193 , V_144 ) ;
if ( V_144 == - V_91 && V_193 ) {
F_60 ( V_167 -> V_102 , 0 ) ;
V_144 = 0 ;
} else if ( V_144 == 0 && V_193 && V_145 < V_167 -> V_95 ) {
F_60 ( V_167 -> V_102 , V_145 ) ;
V_145 = V_167 -> V_95 ;
}
F_77 ( V_167 , V_144 , V_145 ) ;
if ( V_167 -> V_102 )
F_58 ( V_167 -> V_102 ) ;
F_90 ( V_148 ) ;
F_22 ( V_167 ) ;
}
static void F_93 ( struct V_156 * V_148 , struct V_157 * V_158 )
{
F_90 ( V_148 ) ;
}
static int F_94 ( struct V_1 * V_3 ,
struct V_66 * V_65 ,
V_71 V_150 ,
int V_132 ,
int V_33 ,
struct V_129 * V_198 ,
int V_155 ,
const char * V_151 ,
V_71 V_94 , V_71 V_95 ,
char * V_109 ,
struct V_156 * * V_159 ,
V_71 * V_160 )
{
int V_21 ;
struct V_152 * * V_153 ;
int V_154 ;
struct V_129 * V_130 = V_198 ;
T_4 V_133 ;
V_154 = F_95 ( V_94 , V_95 ) ;
V_153 = F_96 ( V_154 , V_23 ) ;
if ( F_16 ( V_153 ) )
return F_37 ( V_153 ) ;
if ( ! V_198 ) {
V_133 = ( V_33 & V_199 ? V_95 : 0 ) ;
V_21 = F_70 ( & V_130 , 1 , V_132 , V_133 ) ;
if ( V_21 < 0 )
goto V_93;
if ( ( V_33 & V_199 ) && V_109 ) {
V_21 = F_97 ( V_153 , V_109 , V_94 , V_95 ) ;
if ( V_21 < 0 )
goto V_200;
}
}
V_21 = F_78 ( NULL , V_3 , V_65 , V_150 ,
V_151 , V_94 , V_95 , NULL ,
V_153 , V_154 ,
V_33 ,
V_130 ,
2 ,
NULL , 0 ,
NULL ,
V_159 , V_160 ) ;
if ( V_21 < 0 )
goto V_200;
if ( ( V_33 & V_201 ) && V_109 )
V_21 = F_98 ( V_153 , V_109 , V_94 , V_21 ) ;
V_200:
if ( ! V_198 )
F_71 ( V_130 ) ;
V_93:
F_99 ( V_153 , V_154 ) ;
return V_21 ;
}
static int F_100 ( struct V_136 * V_137 ,
struct V_1 * V_4 ,
struct V_66 * V_65 ,
V_71 V_150 ,
int V_132 , int V_33 , int V_155 ,
V_71 V_94 , V_71 V_95 ,
struct V_102 * V_102 ,
struct V_53 * V_54 ,
int V_149 )
{
char * V_96 ;
V_71 V_202 ;
V_71 V_203 ;
int V_21 ;
struct V_129 * V_130 ;
T_4 V_133 ;
V_96 = F_12 ( V_99 + 1 , V_134 ) ;
if ( ! V_96 )
return - V_22 ;
V_203 = F_55 ( & V_4 -> V_56 ,
V_4 -> V_56 . V_73 ,
V_94 , V_95 ,
V_96 , & V_202 ) ;
V_133 = ( V_33 & V_199 ? V_203 : 0 ) ;
V_21 = F_70 ( & V_130 , 1 , V_132 , V_133 ) ;
if ( V_21 < 0 )
goto V_93;
F_32 ( V_203 < V_95 ) ;
V_21 = F_78 ( V_137 , V_4 , V_65 , V_150 ,
V_96 , V_202 , V_203 ,
V_102 ,
NULL , 0 ,
V_33 ,
V_130 ,
V_155 ,
V_54 , V_149 ,
F_91 , 0 , NULL ) ;
F_71 ( V_130 ) ;
V_93:
F_22 ( V_96 ) ;
return V_21 ;
}
static int F_101 ( struct V_136 * V_137 ,
struct V_1 * V_4 ,
struct V_66 * V_65 ,
V_71 V_94 , V_71 V_95 ,
struct V_102 * V_102 ,
struct V_53 * V_54 ,
int V_149 )
{
return F_100 ( V_137 , V_4 , V_65 , V_177 ,
V_204 ,
V_199 | V_205 ,
2 ,
V_94 , V_95 , V_102 , V_54 , V_149 ) ;
}
static int F_102 ( struct V_136 * V_137 ,
struct V_1 * V_4 ,
V_71 V_150 ,
V_71 V_94 , V_71 V_95 ,
struct V_102 * V_102 ,
struct V_53 * V_54 ,
int V_149 )
{
return F_100 ( V_137 , V_4 , NULL ,
( V_150 ? V_150 : V_177 ) ,
V_197 ,
V_201 ,
2 ,
V_94 , V_95 , V_102 , V_54 , V_149 ) ;
}
static int F_103 ( struct V_1 * V_3 ,
struct V_66 * V_65 ,
V_71 V_150 ,
const char * V_151 ,
V_71 V_94 , V_71 V_95 ,
char * V_109 ,
V_71 * V_160 )
{
return F_94 ( V_3 , NULL ,
( V_150 ? V_150 : V_177 ) ,
V_197 ,
V_201 ,
NULL ,
1 , V_151 , V_94 , V_95 , V_109 , NULL , V_160 ) ;
}
static int F_104 ( struct V_1 * V_3 ,
V_71 V_160 ,
V_71 V_206 ,
const char * V_151 )
{
struct V_129 * V_130 ;
struct V_152 * * V_153 = NULL ;
int V_21 ;
V_21 = F_70 ( & V_130 , 1 , V_207 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_130 [ 0 ] . V_208 . V_160 = F_83 ( V_3 -> V_56 . V_209 ) ;
V_130 [ 0 ] . V_208 . V_210 = V_206 ;
V_130 [ 0 ] . V_208 . V_211 = 0 ;
V_21 = F_78 ( NULL , V_3 , NULL , V_177 ,
V_151 , 0 , 0 , NULL ,
V_153 , 0 ,
V_201 ,
V_130 ,
1 ,
NULL , 0 ,
F_93 , 0 , NULL ) ;
F_71 ( V_130 ) ;
return V_21 ;
}
static void F_105 ( V_71 V_160 , V_71 V_206 , T_6 V_132 , void * V_212 )
{
struct V_1 * V_3 = (struct V_1 * ) V_212 ;
int V_144 ;
if ( ! V_3 )
return;
F_11 ( L_19 , V_3 -> V_213 ,
V_206 , ( int ) V_132 ) ;
F_106 ( & V_214 , V_215 ) ;
V_144 = F_107 ( V_3 ) ;
F_108 ( & V_214 ) ;
if ( V_144 )
F_109 ( V_216 L_20
L_21 , V_3 -> V_217 , V_144 ) ;
F_104 ( V_3 , V_160 , V_206 , V_3 -> V_213 ) ;
}
static int F_110 ( struct V_1 * V_3 ,
const char * V_151 ,
V_71 V_160 )
{
struct V_129 * V_130 ;
struct V_218 * V_170 = & V_3 -> V_27 -> V_170 ;
int V_21 = F_70 ( & V_130 , 1 , V_219 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_111 ( V_170 , F_105 , 0 ,
( void * ) V_3 , & V_3 -> V_220 ) ;
if ( V_21 < 0 )
goto V_221;
V_130 [ 0 ] . V_208 . V_160 = F_83 ( V_160 ) ;
V_130 [ 0 ] . V_208 . V_210 = F_83 ( V_3 -> V_220 -> V_210 ) ;
V_130 [ 0 ] . V_208 . V_211 = 1 ;
V_21 = F_94 ( V_3 , NULL ,
V_177 ,
0 ,
V_199 | V_205 ,
V_130 ,
1 , V_151 , 0 , 0 , NULL ,
& V_3 -> V_222 , NULL ) ;
if ( V_21 < 0 )
goto V_223;
F_71 ( V_130 ) ;
return 0 ;
V_223:
F_112 ( V_3 -> V_220 ) ;
V_3 -> V_220 = NULL ;
V_221:
F_71 ( V_130 ) ;
return V_21 ;
}
static void F_113 ( V_71 V_160 , V_71 V_206 , T_6 V_132 , void * V_212 )
{
struct V_1 * V_3 = (struct V_1 * ) V_212 ;
if ( ! V_3 )
return;
F_11 ( L_22 , V_3 -> V_213 ,
V_206 , ( int ) V_132 ) ;
}
static int F_114 ( struct V_1 * V_3 ,
const char * V_151 )
{
struct V_129 * V_130 ;
struct V_218 * V_170 = & V_3 -> V_27 -> V_170 ;
struct V_224 * V_225 ;
struct V_226 V_227 ;
int V_133 = sizeof( T_4 ) + sizeof( T_4 ) ;
int V_21 ;
V_21 = F_70 ( & V_130 , 1 , V_228 , V_133 ) ;
if ( V_21 < 0 )
return V_21 ;
V_227 . V_3 = V_3 ;
V_21 = F_111 ( V_170 , F_113 , 1 ,
( void * ) & V_227 , & V_225 ) ;
if ( V_21 < 0 )
goto V_221;
V_130 [ 0 ] . V_208 . V_160 = 1 ;
V_130 [ 0 ] . V_208 . V_211 = 1 ;
V_130 [ 0 ] . V_208 . V_210 = V_225 -> V_210 ;
V_130 [ 0 ] . V_208 . V_229 = V_230 ;
V_130 [ 0 ] . V_208 . V_231 = 12 ;
V_21 = F_94 ( V_3 , NULL ,
V_177 ,
0 ,
V_199 | V_205 ,
V_130 ,
1 , V_151 , 0 , 0 , NULL , NULL , NULL ) ;
if ( V_21 < 0 )
goto V_223;
V_21 = F_115 ( V_225 , V_232 ) ;
F_11 ( L_23 , V_21 ) ;
F_71 ( V_130 ) ;
return 0 ;
V_223:
F_112 ( V_225 ) ;
V_221:
F_71 ( V_130 ) ;
return V_21 ;
}
static int F_116 ( struct V_1 * V_3 ,
V_71 V_150 ,
const char * V_151 )
{
struct V_129 * V_130 ;
int V_21 = F_70 ( & V_130 , 1 , V_233 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_130 [ 0 ] . V_234 . V_150 = V_150 ;
V_21 = F_94 ( V_3 , NULL ,
V_177 ,
0 ,
V_199 | V_205 ,
V_130 ,
1 , V_151 , 0 , 0 , NULL , NULL , NULL ) ;
F_71 ( V_130 ) ;
return V_21 ;
}
static int F_117 ( struct V_1 * V_3 ,
const char * V_151 ,
const char * V_235 ,
const char * V_236 ,
const char * V_212 ,
int V_95 ,
V_71 * V_160 )
{
struct V_129 * V_130 ;
int V_237 = strlen ( V_235 ) ;
int V_238 = strlen ( V_236 ) ;
int V_21 = F_70 ( & V_130 , 1 , V_239 ,
V_237 + V_238 + V_95 ) ;
if ( V_21 < 0 )
return V_21 ;
V_130 [ 0 ] . V_235 . V_240 = V_235 ;
V_130 [ 0 ] . V_235 . V_241 = ( V_242 ) V_237 ;
V_130 [ 0 ] . V_235 . V_243 = V_236 ;
V_130 [ 0 ] . V_235 . V_238 = ( V_242 ) V_238 ;
V_130 [ 0 ] . V_235 . V_244 = 0 ;
V_130 [ 0 ] . V_235 . V_245 = V_212 ;
V_130 [ 0 ] . V_235 . V_246 = V_95 ;
V_21 = F_94 ( V_3 , NULL ,
V_177 ,
0 ,
V_199 | V_205 ,
V_130 ,
1 , V_151 , 0 , 0 , NULL , NULL , V_160 ) ;
F_71 ( V_130 ) ;
F_11 ( L_24 , V_21 ) ;
return V_21 ;
}
static struct V_53 * F_118 ( int V_247 )
{
struct V_53 * V_54 =
F_34 ( sizeof( struct V_53 ) +
sizeof( struct V_248 ) * V_247 ,
V_249 ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_121 = V_247 ;
F_13 ( & V_54 -> V_25 ) ;
return V_54 ;
}
static void F_119 ( struct V_139 * V_140 )
{
struct V_1 * V_4 = V_140 -> V_250 ;
struct V_136 * V_137 ;
struct V_115 * V_116 = NULL ;
V_137 = F_120 ( V_140 ) ;
while ( 1 ) {
struct V_102 * V_102 ;
struct V_102 * V_251 , * V_252 = NULL ;
bool V_253 ;
int V_89 , V_254 = 0 ;
V_71 V_94 ;
int V_255 , V_256 = 0 ;
struct V_53 * V_54 ;
if ( ! V_137 )
break;
F_11 ( L_25 ) ;
if ( ( V_137 -> V_257 != V_258 ) ) {
F_121 ( V_137 , 0 ) ;
goto V_114;
}
V_253 = ( F_122 ( V_137 ) == V_259 ) ;
V_89 = F_123 ( V_137 ) ;
V_94 = F_124 ( V_137 ) * 512ULL ;
V_251 = V_137 -> V_102 ;
if ( V_253 && V_4 -> V_12 ) {
F_121 ( V_137 , - V_14 ) ;
goto V_114;
}
F_76 ( V_140 -> V_142 ) ;
F_11 ( L_26 ,
V_253 ? L_27 : L_28 ,
V_89 , F_124 ( V_137 ) * 512ULL ) ;
V_255 = F_57 ( & V_4 -> V_56 , V_94 , V_89 ) ;
V_54 = F_118 ( V_255 ) ;
if ( ! V_54 ) {
F_74 ( V_140 -> V_142 ) ;
F_121 ( V_137 , - V_22 ) ;
goto V_114;
}
do {
F_11 ( L_29 , V_137 -> V_102 -> V_260 ) ;
V_254 = F_55 ( & V_4 -> V_56 ,
V_4 -> V_56 . V_73 ,
V_94 , V_89 ,
NULL , NULL ) ;
F_36 ( & V_54 -> V_25 ) ;
V_102 = F_65 ( & V_251 , & V_252 , & V_116 ,
V_254 , V_249 ) ;
if ( ! V_102 ) {
F_72 ( V_137 , V_54 , V_256 ,
- V_22 , V_254 ) ;
goto V_261;
}
if ( V_253 )
F_101 ( V_137 , V_4 ,
V_4 -> V_56 . V_65 ,
V_94 ,
V_254 , V_102 ,
V_54 , V_256 ) ;
else
F_102 ( V_137 , V_4 ,
F_49 ( V_4 ) ,
V_94 ,
V_254 , V_102 ,
V_54 , V_256 ) ;
V_261:
V_89 -= V_254 ;
V_94 += V_254 ;
V_256 ++ ;
V_251 = V_252 ;
} while ( V_89 > 0 );
F_41 ( & V_54 -> V_25 , F_42 ) ;
if ( V_116 )
F_66 ( V_116 ) ;
F_74 ( V_140 -> V_142 ) ;
V_114:
V_137 = F_120 ( V_140 ) ;
}
}
static int F_125 ( struct V_139 * V_140 , struct V_262 * V_263 ,
struct V_107 * V_264 )
{
struct V_1 * V_4 = V_140 -> V_250 ;
unsigned int V_265 = 1 << ( V_4 -> V_56 . V_75 - 9 ) ;
T_7 V_266 = V_263 -> V_267 + F_126 ( V_263 -> V_127 ) ;
unsigned int V_268 = V_263 -> V_124 >> 9 ;
int F_62 ;
F_62 = ( V_265 - ( ( V_266 & ( V_265 - 1 ) )
+ V_268 ) ) << 9 ;
if ( F_62 < 0 )
F_62 = 0 ;
if ( F_62 <= V_264 -> V_111 && V_268 == 0 )
return V_264 -> V_111 ;
return F_62 ;
}
static void F_127 ( struct V_1 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( ! V_9 )
return;
F_54 ( & V_4 -> V_56 ) ;
if ( V_9 -> V_33 & V_269 )
F_128 ( V_9 ) ;
if ( V_9 -> V_270 )
F_129 ( V_9 -> V_270 ) ;
F_130 ( V_9 ) ;
}
static int F_131 ( struct V_1 * V_4 ,
struct V_55 * V_56 )
{
T_8 V_144 ;
struct V_57 * V_271 ;
int V_62 = 0 ;
V_71 V_64 = 0 ;
V_71 V_160 ;
while ( 1 ) {
int V_95 = sizeof( * V_271 ) +
V_62 * sizeof( struct V_67 ) +
V_64 ;
V_144 = - V_22 ;
V_271 = F_12 ( V_95 , V_23 ) ;
if ( ! V_271 )
return - V_22 ;
V_144 = F_103 ( V_4 ,
NULL , V_177 ,
V_4 -> V_213 ,
0 , V_95 ,
( char * ) V_271 , & V_160 ) ;
if ( V_144 < 0 )
goto V_272;
V_144 = F_43 ( V_56 , V_271 , V_62 , V_23 ) ;
if ( V_144 < 0 )
goto V_272;
if ( V_62 != V_56 -> V_82 ) {
V_62 = V_56 -> V_82 ;
V_64 = V_56 -> V_64 ;
F_54 ( V_56 ) ;
F_22 ( V_271 ) ;
continue;
}
break;
}
V_56 -> V_209 = V_160 ;
V_272:
F_22 ( V_271 ) ;
return V_144 ;
}
static int F_132 ( struct V_1 * V_3 ,
const char * V_87 ,
T_3 V_60 )
{
int V_273 = strlen ( V_87 ) ;
V_71 V_274 ;
int V_21 ;
void * V_212 , * V_90 , * V_275 ;
V_71 V_160 ;
if ( V_3 -> V_86 )
return - V_43 ;
V_21 = F_133 ( & V_3 -> V_27 -> V_276 , V_3 -> V_187 ,
& V_274 ) ;
F_11 ( L_30 , V_274 ) ;
if ( V_21 < 0 )
return V_21 ;
V_212 = F_12 ( V_273 + 16 , V_60 ) ;
if ( ! V_212 )
return - V_22 ;
V_90 = V_212 ;
V_275 = V_212 + V_273 + 16 ;
F_134 ( & V_90 , V_275 , V_87 , V_273 , V_277 ) ;
F_135 ( & V_90 , V_275 , V_274 , V_277 ) ;
V_21 = F_117 ( V_3 , V_3 -> V_213 , L_31 , L_32 ,
V_212 , V_90 - V_212 , & V_160 ) ;
F_22 ( V_212 ) ;
if ( V_21 < 0 )
return V_21 ;
V_3 -> V_56 . V_65 -> V_88 = V_274 ;
return 0 ;
V_277:
return - V_278 ;
}
static void F_136 ( struct V_1 * V_4 )
{
struct V_279 * V_234 ;
while ( ! F_137 ( & V_4 -> V_83 ) ) {
V_234 = F_138 ( & V_4 -> V_83 , struct V_279 , V_26 ) ;
F_139 ( V_4 , V_234 ) ;
}
}
static int F_107 ( struct V_1 * V_4 )
{
int V_21 ;
struct V_55 V_280 ;
V_71 V_80 ;
int V_281 = 0 ;
V_21 = F_131 ( V_4 , & V_280 ) ;
if ( V_21 < 0 )
return V_21 ;
F_140 ( V_4 -> V_9 , V_280 . V_74 / 512ULL ) ;
F_52 ( & V_4 -> V_56 . V_63 ) ;
V_80 = V_4 -> V_56 . V_65 -> V_88 ;
if ( V_4 -> V_56 . V_82 &&
V_4 -> V_56 . V_65 -> V_83 [ 0 ] == V_80 )
V_281 = 1 ;
F_22 ( V_4 -> V_56 . V_65 ) ;
F_22 ( V_4 -> V_56 . V_68 ) ;
F_22 ( V_4 -> V_56 . V_70 ) ;
V_4 -> V_56 . V_82 = V_280 . V_82 ;
V_4 -> V_56 . V_65 = V_280 . V_65 ;
V_4 -> V_56 . V_68 = V_280 . V_68 ;
V_4 -> V_56 . V_64 = V_280 . V_64 ;
V_4 -> V_56 . V_70 = V_280 . V_70 ;
if ( V_281 )
V_4 -> V_56 . V_65 -> V_88 = V_4 -> V_56 . V_65 -> V_83 [ 0 ] ;
else
V_4 -> V_56 . V_65 -> V_88 = V_80 ;
V_21 = F_141 ( V_4 ) ;
F_53 ( & V_4 -> V_56 . V_63 ) ;
return V_21 ;
}
static int F_142 ( struct V_1 * V_4 )
{
struct V_8 * V_9 ;
struct V_139 * V_140 ;
int V_144 ;
V_71 V_282 = 0 ;
V_144 = F_131 ( V_4 , & V_4 -> V_56 ) ;
if ( V_144 )
return V_144 ;
V_144 = F_141 ( V_4 ) ;
if ( V_144 )
return V_144 ;
V_144 = F_51 ( V_4 , V_4 -> V_87 , & V_282 ) ;
if ( V_144 )
return V_144 ;
V_144 = - V_22 ;
V_9 = F_143 ( V_283 ) ;
if ( ! V_9 )
goto V_284;
snprintf ( V_9 -> V_285 , sizeof( V_9 -> V_285 ) , V_216 L_33 ,
V_4 -> V_84 ) ;
V_9 -> V_217 = V_4 -> V_217 ;
V_9 -> V_286 = 0 ;
V_9 -> V_287 = & V_288 ;
V_9 -> V_11 = V_4 ;
V_144 = - V_22 ;
V_140 = F_144 ( F_119 , & V_4 -> V_289 ) ;
if ( ! V_140 )
goto V_290;
F_145 ( V_140 , F_125 ) ;
V_9 -> V_270 = V_140 ;
V_140 -> V_250 = V_4 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_140 = V_140 ;
F_140 ( V_9 , V_282 / 512ULL ) ;
F_146 ( V_9 ) ;
F_147 ( L_34 ,
V_9 -> V_285 , ( unsigned long long ) V_282 ) ;
return 0 ;
V_290:
F_130 ( V_9 ) ;
V_284:
return V_144 ;
}
static T_8 F_148 ( struct V_2 * V_3 ,
struct V_291 * V_292 , char * V_109 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_109 , L_35 , ( unsigned long long ) V_4 -> V_56 . V_74 ) ;
}
static T_8 F_149 ( struct V_2 * V_3 ,
struct V_291 * V_292 , char * V_109 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_109 , L_36 , V_4 -> V_217 ) ;
}
static T_8 F_150 ( struct V_2 * V_3 ,
struct V_291 * V_292 , char * V_109 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_109 , L_37 , F_151 ( V_4 -> V_27 ) ) ;
}
static T_8 F_152 ( struct V_2 * V_3 ,
struct V_291 * V_292 , char * V_109 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_109 , L_38 , V_4 -> V_293 ) ;
}
static T_8 F_153 ( struct V_2 * V_3 ,
struct V_291 * V_292 , char * V_109 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_109 , L_38 , V_4 -> V_151 ) ;
}
static T_8 F_154 ( struct V_2 * V_3 ,
struct V_291 * V_292 ,
char * V_109 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_109 , L_38 , V_4 -> V_87 ) ;
}
static T_8 F_155 ( struct V_2 * V_3 ,
struct V_291 * V_292 ,
const char * V_109 ,
T_9 V_89 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_144 ;
int V_21 = V_89 ;
F_106 ( & V_214 , V_215 ) ;
V_144 = F_107 ( V_4 ) ;
if ( V_144 < 0 )
V_21 = V_144 ;
F_108 ( & V_214 ) ;
return V_21 ;
}
static void F_156 ( struct V_2 * V_3 )
{
}
static T_8 F_157 ( struct V_2 * V_3 ,
struct V_291 * V_292 ,
char * V_109 )
{
struct V_279 * V_234 = F_2 ( V_3 , struct V_279 , V_3 ) ;
return sprintf ( V_109 , L_39 , ( long long ) V_234 -> V_89 ) ;
}
static T_8 F_158 ( struct V_2 * V_3 ,
struct V_291 * V_292 ,
char * V_109 )
{
struct V_279 * V_234 = F_2 ( V_3 , struct V_279 , V_3 ) ;
return sprintf ( V_109 , L_39 , ( long long ) V_234 -> V_84 ) ;
}
static void F_159 ( struct V_2 * V_3 )
{
struct V_279 * V_234 = F_2 ( V_3 , struct V_279 , V_3 ) ;
F_22 ( V_234 -> V_294 ) ;
F_22 ( V_234 ) ;
}
static void F_139 ( struct V_1 * V_4 ,
struct V_279 * V_234 )
{
F_39 ( & V_234 -> V_26 ) ;
F_160 ( & V_234 -> V_3 ) ;
}
static int F_161 ( struct V_1 * V_4 ,
struct V_279 * V_234 ,
struct V_2 * V_295 )
{
struct V_2 * V_3 = & V_234 -> V_3 ;
int V_21 ;
V_3 -> type = & V_296 ;
V_3 -> V_295 = V_295 ;
V_3 -> V_297 = F_159 ;
F_162 ( V_3 , L_40 , V_234 -> V_294 ) ;
V_21 = F_163 ( V_3 ) ;
return V_21 ;
}
static int F_164 ( struct V_1 * V_4 ,
int V_61 , const char * V_294 ,
struct V_279 * * V_298 )
{
int V_21 ;
struct V_279 * V_234 = F_34 ( sizeof( * V_234 ) , V_23 ) ;
if ( ! V_234 )
return - V_22 ;
V_234 -> V_294 = F_165 ( V_294 , V_23 ) ;
V_234 -> V_89 = V_4 -> V_56 . V_70 [ V_61 ] ;
V_234 -> V_84 = V_4 -> V_56 . V_65 -> V_83 [ V_61 ] ;
if ( F_166 ( & V_4 -> V_3 ) ) {
V_21 = F_161 ( V_4 , V_234 ,
& V_4 -> V_3 ) ;
if ( V_21 < 0 )
goto V_299;
}
* V_298 = V_234 ;
return 0 ;
V_299:
F_22 ( V_234 -> V_294 ) ;
F_22 ( V_234 ) ;
return V_21 ;
}
const char * F_167 ( const char * V_294 , const char * V_300 )
{
if ( V_294 < V_300 + 2 )
return NULL ;
V_294 -= 2 ;
while ( * V_294 ) {
if ( V_294 == V_300 )
return V_300 ;
V_294 -- ;
}
return V_294 + 1 ;
}
static int F_141 ( struct V_1 * V_4 )
{
const char * V_294 , * V_301 ;
int V_61 = V_4 -> V_56 . V_82 ;
struct V_279 * V_234 , * V_302 = NULL ;
int V_21 ;
struct V_303 * V_90 , * V_304 ;
V_301 = V_4 -> V_56 . V_68 ;
V_294 = V_301 + V_4 -> V_56 . V_64 ;
F_168 (p, n, &rbd_dev->snaps) {
V_71 V_305 ;
V_302 = F_169 ( V_90 , struct V_279 , V_26 ) ;
if ( V_61 )
V_305 = V_4 -> V_56 . V_65 -> V_83 [ V_61 - 1 ] ;
if ( ! V_61 || V_302 -> V_84 < V_305 ) {
F_139 ( V_4 , V_302 ) ;
continue;
}
if ( V_302 -> V_84 == V_305 ) {
V_61 -- ;
V_294 = F_167 ( V_294 , V_301 ) ;
continue;
}
for (; V_61 > 0 ;
V_61 -- , V_294 = F_167 ( V_294 , V_301 ) ) {
if ( ! V_294 ) {
F_92 ( 1 ) ;
return - V_43 ;
}
V_305 = V_4 -> V_56 . V_65 -> V_83 [ V_61 ] ;
if ( V_305 >= V_302 -> V_84 )
break;
V_21 = F_164 ( V_4 , V_61 - 1 , V_294 , & V_234 ) ;
if ( V_21 < 0 )
return V_21 ;
F_170 ( & V_234 -> V_26 , V_304 ) ;
V_90 = & V_234 -> V_26 ;
}
}
for (; V_61 > 0 ; V_61 -- ) {
V_294 = F_167 ( V_294 , V_301 ) ;
if ( ! V_294 ) {
F_92 ( 1 ) ;
return - V_43 ;
}
V_21 = F_164 ( V_4 , V_61 - 1 , V_294 , & V_234 ) ;
if ( V_21 < 0 )
return V_21 ;
F_170 ( & V_234 -> V_26 , & V_4 -> V_83 ) ;
}
return 0 ;
}
static void F_171 ( struct V_2 * V_3 )
{
}
static int F_172 ( struct V_1 * V_4 )
{
int V_21 = - V_22 ;
struct V_2 * V_3 ;
struct V_279 * V_234 ;
F_106 ( & V_214 , V_215 ) ;
V_3 = & V_4 -> V_3 ;
V_3 -> V_306 = & V_307 ;
V_3 -> type = & V_308 ;
V_3 -> V_295 = & V_309 ;
V_3 -> V_297 = V_310 ;
F_162 ( V_3 , L_33 , V_4 -> V_84 ) ;
V_21 = F_163 ( V_3 ) ;
if ( V_21 < 0 )
goto V_311;
F_26 (snap, &rbd_dev->snaps, node) {
V_21 = F_161 ( V_4 , V_234 ,
& V_4 -> V_3 ) ;
if ( V_21 < 0 )
break;
}
F_108 ( & V_214 ) ;
return 0 ;
V_311:
F_108 ( & V_214 ) ;
return V_21 ;
}
static void F_173 ( struct V_1 * V_4 )
{
F_160 ( & V_4 -> V_3 ) ;
}
static int F_174 ( struct V_1 * V_4 )
{
int V_21 , V_144 ;
do {
V_21 = F_110 ( V_4 , V_4 -> V_213 ,
V_4 -> V_56 . V_209 ) ;
if ( V_21 == - V_278 ) {
F_106 ( & V_214 , V_215 ) ;
V_144 = F_107 ( V_4 ) ;
F_108 ( & V_214 ) ;
if ( V_144 < 0 )
return V_144 ;
}
} while ( V_21 == - V_278 );
return V_21 ;
}
static T_8 F_175 ( struct V_312 * V_306 ,
const char * V_109 ,
T_9 V_313 )
{
struct V_218 * V_170 ;
struct V_1 * V_4 ;
T_8 V_144 = - V_22 ;
int V_314 , V_315 = 0 ;
struct V_303 * V_104 ;
char * V_316 ;
char * V_50 ;
if ( ! F_176 ( V_317 ) )
return - V_318 ;
V_316 = F_12 ( V_319 , V_23 ) ;
if ( ! V_316 )
goto V_320;
V_50 = F_12 ( V_319 , V_23 ) ;
if ( ! V_50 )
goto V_321;
V_4 = F_34 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
goto V_322;
F_177 ( & V_4 -> V_289 ) ;
F_14 ( & V_4 -> V_26 ) ;
F_14 ( & V_4 -> V_83 ) ;
F_106 ( & V_214 , V_215 ) ;
F_178 (tmp, &rbd_dev_list) {
struct V_1 * V_4 ;
V_4 = F_169 ( V_104 , struct V_1 , V_26 ) ;
if ( V_4 -> V_84 >= V_315 )
V_315 = V_4 -> V_84 + 1 ;
}
V_4 -> V_84 = V_315 ;
F_19 ( & V_4 -> V_26 , & V_323 ) ;
if ( sscanf ( V_109 , L_41 F_179 ( V_319 ) L_42
L_41 F_179 ( V_319 ) L_42
L_41 F_179 ( V_324 ) L_42
L_41 F_179 ( V_325 ) L_43
L_41 F_179 ( V_326 ) L_43 ,
V_316 , V_50 , V_4 -> V_293 ,
V_4 -> V_151 , V_4 -> V_87 ) < 4 ) {
V_144 = - V_43 ;
goto V_327;
}
if ( V_4 -> V_87 [ 0 ] == 0 )
V_4 -> V_87 [ 0 ] = '-' ;
V_4 -> V_328 = strlen ( V_4 -> V_151 ) ;
snprintf ( V_4 -> V_213 , sizeof( V_4 -> V_213 ) , L_44 ,
V_4 -> V_151 , V_329 ) ;
snprintf ( V_4 -> V_294 , V_330 , V_216 L_33 , V_4 -> V_84 ) ;
V_144 = F_33 ( V_4 , V_316 , V_50 ) ;
if ( V_144 < 0 )
goto V_327;
F_108 ( & V_214 ) ;
V_170 = & V_4 -> V_27 -> V_170 ;
V_144 = F_180 ( V_170 -> V_331 , V_4 -> V_293 ) ;
if ( V_144 < 0 )
goto V_332;
V_4 -> V_187 = V_144 ;
V_314 = F_181 ( 0 , V_4 -> V_294 ) ;
if ( V_314 < 0 ) {
V_144 = V_314 ;
goto V_332;
}
V_4 -> V_217 = V_314 ;
V_144 = F_172 ( V_4 ) ;
if ( V_144 )
goto V_333;
V_144 = F_142 ( V_4 ) ;
if ( V_144 )
goto V_334;
V_144 = F_174 ( V_4 ) ;
if ( V_144 )
goto V_334;
return V_313 ;
V_334:
F_106 ( & V_214 , V_215 ) ;
F_182 ( & V_4 -> V_26 ) ;
F_108 ( & V_214 ) ;
F_173 ( V_4 ) ;
F_22 ( V_50 ) ;
F_22 ( V_316 ) ;
return V_144 ;
V_333:
F_183 ( V_4 -> V_217 , V_4 -> V_294 ) ;
V_332:
F_40 ( V_4 ) ;
F_106 ( & V_214 , V_215 ) ;
V_327:
F_182 ( & V_4 -> V_26 ) ;
F_108 ( & V_214 ) ;
F_22 ( V_4 ) ;
V_322:
F_22 ( V_50 ) ;
V_321:
F_22 ( V_316 ) ;
V_320:
F_11 ( L_45 , V_109 ) ;
F_184 ( V_317 ) ;
return V_144 ;
}
static struct V_1 * F_185 ( unsigned long V_84 )
{
struct V_303 * V_104 ;
struct V_1 * V_4 ;
F_178 (tmp, &rbd_dev_list) {
V_4 = F_169 ( V_104 , struct V_1 , V_26 ) ;
if ( V_4 -> V_84 == V_84 )
return V_4 ;
}
return NULL ;
}
static void V_310 ( struct V_2 * V_3 )
{
struct V_1 * V_4 =
F_2 ( V_3 , struct V_1 , V_3 ) ;
if ( V_4 -> V_222 )
F_186 ( & V_4 -> V_27 -> V_170 ,
V_4 -> V_222 ) ;
if ( V_4 -> V_220 )
F_112 ( V_4 -> V_220 ) ;
F_40 ( V_4 ) ;
F_127 ( V_4 ) ;
F_183 ( V_4 -> V_217 , V_4 -> V_294 ) ;
F_22 ( V_4 ) ;
F_184 ( V_317 ) ;
}
static T_8 F_187 ( struct V_312 * V_306 ,
const char * V_109 ,
T_9 V_313 )
{
struct V_1 * V_4 = NULL ;
int V_335 , V_144 ;
unsigned long V_336 ;
int V_21 = V_313 ;
V_144 = F_188 ( V_109 , 10 , & V_336 ) ;
if ( V_144 )
return V_144 ;
V_335 = ( int ) V_336 ;
if ( V_335 != V_336 )
return - V_43 ;
F_106 ( & V_214 , V_215 ) ;
V_4 = F_185 ( V_335 ) ;
if ( ! V_4 ) {
V_21 = - V_91 ;
goto V_93;
}
F_182 ( & V_4 -> V_26 ) ;
F_136 ( V_4 ) ;
F_173 ( V_4 ) ;
V_93:
F_108 ( & V_214 ) ;
return V_21 ;
}
static T_8 F_189 ( struct V_2 * V_3 ,
struct V_291 * V_292 ,
const char * V_109 ,
T_9 V_313 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_21 ;
char * V_294 = F_12 ( V_313 + 1 , V_23 ) ;
if ( ! V_294 )
return - V_22 ;
snprintf ( V_294 , V_313 , L_46 , V_109 ) ;
F_106 ( & V_214 , V_215 ) ;
V_21 = F_132 ( V_4 ,
V_294 , V_23 ) ;
if ( V_21 < 0 )
goto V_337;
V_21 = F_107 ( V_4 ) ;
if ( V_21 < 0 )
goto V_337;
F_108 ( & V_214 ) ;
F_114 ( V_4 , V_4 -> V_213 ) ;
V_21 = V_313 ;
F_22 ( V_294 ) ;
return V_21 ;
V_337:
F_108 ( & V_214 ) ;
F_22 ( V_294 ) ;
return V_21 ;
}
static T_8 F_190 ( struct V_2 * V_3 ,
struct V_291 * V_292 ,
const char * V_109 ,
T_9 V_313 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_21 ;
V_71 V_150 ;
V_71 V_338 ;
char * V_96 = NULL ;
char * V_87 = F_12 ( V_313 + 1 , V_23 ) ;
V_21 = - V_22 ;
if ( ! V_87 )
return V_21 ;
snprintf ( V_87 , V_313 , L_46 , V_109 ) ;
V_96 = F_12 ( V_99 + 1 , V_134 ) ;
if ( ! V_96 )
goto V_93;
F_106 ( & V_214 , V_215 ) ;
V_21 = F_50 ( & V_4 -> V_56 , V_87 , & V_150 , NULL ) ;
if ( V_21 < 0 )
goto V_339;
F_11 ( L_47 , V_150 ) ;
V_338 = 0 ;
while ( V_338 < V_4 -> V_56 . V_74 ) {
V_338 += F_55 ( & V_4 -> V_56 ,
V_4 -> V_151 ,
V_338 , ( V_71 ) - 1 ,
V_96 , NULL ) ;
F_11 ( L_48 , V_96 ) ;
V_21 = F_116 ( V_4 , V_150 , V_96 ) ;
if ( V_21 < 0 )
F_109 ( L_49 ,
V_96 , V_21 ) ;
}
V_21 = F_107 ( V_4 ) ;
if ( V_21 < 0 )
goto V_339;
V_21 = V_313 ;
V_339:
F_108 ( & V_214 ) ;
V_93:
F_22 ( V_96 ) ;
F_22 ( V_87 ) ;
return V_21 ;
}
static int F_191 ( void )
{
int V_21 ;
V_307 . V_340 = V_341 ;
V_21 = F_192 ( & V_307 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_163 ( & V_309 ) ;
return V_21 ;
}
static void F_193 ( void )
{
F_160 ( & V_309 ) ;
F_194 ( & V_307 ) ;
}
int T_10 F_195 ( void )
{
int V_144 ;
V_144 = F_191 () ;
if ( V_144 )
return V_144 ;
F_177 ( & V_30 ) ;
F_147 ( L_50 V_342 L_51 ) ;
return 0 ;
}
void T_11 F_196 ( void )
{
F_193 () ;
}
