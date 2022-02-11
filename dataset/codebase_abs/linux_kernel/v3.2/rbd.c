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
V_20 -> V_27 = F_15 ( V_17 , V_20 , 0 , 0 ) ;
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
if ( memcmp ( V_58 , V_63 , sizeof( V_63 ) ) ) {
return - V_64 ;
}
F_45 ( & V_56 -> V_65 ) ;
V_56 -> V_66 = F_46 ( V_58 -> V_66 ) ;
V_56 -> V_67 = F_12 ( sizeof( struct V_68 ) +
V_62 *
sizeof( struct V_69 ) ,
V_60 ) ;
if ( ! V_56 -> V_67 )
return - V_22 ;
if ( V_62 ) {
V_56 -> V_70 = F_12 ( V_56 -> V_66 ,
V_23 ) ;
if ( ! V_56 -> V_70 )
goto V_71;
V_56 -> V_72 = F_12 ( V_62 * sizeof( V_73 ) ,
V_23 ) ;
if ( ! V_56 -> V_72 )
goto V_74;
} else {
V_56 -> V_70 = NULL ;
V_56 -> V_72 = NULL ;
}
memcpy ( V_56 -> V_75 , V_58 -> V_75 ,
sizeof( V_58 -> V_75 ) ) ;
V_56 -> V_76 = F_46 ( V_58 -> V_76 ) ;
V_56 -> V_77 = V_58 -> V_50 . V_78 ;
V_56 -> V_79 = V_58 -> V_50 . V_79 ;
V_56 -> V_80 = V_58 -> V_50 . V_80 ;
F_47 ( & V_56 -> V_67 -> V_81 , 1 ) ;
V_56 -> V_82 = F_46 ( V_58 -> V_82 ) ;
V_56 -> V_67 -> V_83 = V_62 ;
V_56 -> V_84 = V_62 ;
if ( V_62 &&
V_59 == V_62 ) {
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
V_56 -> V_67 -> V_85 [ V_61 ] =
F_46 ( V_58 -> V_85 [ V_61 ] . V_86 ) ;
V_56 -> V_72 [ V_61 ] =
F_46 ( V_58 -> V_85 [ V_61 ] . V_76 ) ;
}
memcpy ( V_56 -> V_70 , & V_58 -> V_85 [ V_61 ] ,
V_56 -> V_66 ) ;
}
return 0 ;
V_74:
F_22 ( V_56 -> V_70 ) ;
V_71:
F_22 ( V_56 -> V_67 ) ;
return V_21 ;
}
static int F_48 ( struct V_55 * V_56 , int V_87 )
{
return V_56 -> V_84 - V_87 ;
}
static V_73 F_49 ( struct V_1 * V_4 )
{
struct V_55 * V_56 = & V_4 -> V_56 ;
if ( ! V_4 -> V_88 )
return 0 ;
return V_56 -> V_67 -> V_85 [ F_48 ( V_56 , V_4 -> V_88 ) ] ;
}
static int F_50 ( struct V_55 * V_56 , const char * V_89 ,
V_73 * V_90 , V_73 * V_91 )
{
int V_61 ;
char * V_92 = V_56 -> V_70 ;
for ( V_61 = 0 ; V_61 < V_56 -> V_84 ; V_61 ++ , V_92 += strlen ( V_92 ) + 1 ) {
if ( strcmp ( V_89 , V_92 ) == 0 )
break;
}
if ( V_61 == V_56 -> V_84 )
return - V_93 ;
if ( V_90 )
* V_90 = V_56 -> V_67 -> V_85 [ V_61 ] ;
if ( V_91 )
* V_91 = V_56 -> V_72 [ V_61 ] ;
return V_61 ;
}
static int F_51 ( struct V_1 * V_3 ,
const char * V_89 ,
V_73 * V_91 )
{
struct V_55 * V_56 = & V_3 -> V_56 ;
struct V_68 * V_67 = V_56 -> V_67 ;
int V_21 = - V_93 ;
F_52 ( & V_56 -> V_65 ) ;
if ( ! V_89 ||
! * V_89 ||
strcmp ( V_89 , L_10 ) == 0 ||
strcmp ( V_89 , V_94 ) == 0 ) {
if ( V_56 -> V_84 )
V_67 -> V_90 = V_56 -> V_82 ;
else
V_67 -> V_90 = 0 ;
V_3 -> V_88 = 0 ;
V_3 -> V_12 = 0 ;
if ( V_91 )
* V_91 = V_56 -> V_76 ;
} else {
V_21 = F_50 ( V_56 , V_89 , & V_67 -> V_90 , V_91 ) ;
if ( V_21 < 0 )
goto V_95;
V_3 -> V_88 = V_56 -> V_84 - V_21 ;
V_3 -> V_12 = 1 ;
}
V_21 = 0 ;
V_95:
F_53 ( & V_56 -> V_65 ) ;
return V_21 ;
}
static void F_54 ( struct V_55 * V_56 )
{
F_22 ( V_56 -> V_67 ) ;
F_22 ( V_56 -> V_70 ) ;
F_22 ( V_56 -> V_72 ) ;
}
static V_73 F_55 ( struct V_55 * V_56 ,
const char * V_75 ,
V_73 V_96 , V_73 V_97 ,
char * V_98 , V_73 * V_99 )
{
V_73 V_100 = V_96 >> V_56 -> V_77 ;
if ( V_98 )
snprintf ( V_98 , V_101 ,
L_11 , V_75 , V_100 ) ;
V_96 = V_96 & ( ( 1 << V_56 -> V_77 ) - 1 ) ;
V_97 = F_56 ( V_73 , V_97 , ( 1 << V_56 -> V_77 ) - V_96 ) ;
if ( V_99 )
* V_99 = V_96 ;
return V_97 ;
}
static int F_57 ( struct V_55 * V_56 ,
V_73 V_96 , V_73 V_97 )
{
V_73 V_102 = V_96 >> V_56 -> V_77 ;
V_73 V_103 = ( V_96 + V_97 - 1 ) >> V_56 -> V_77 ;
return V_103 - V_102 + 1 ;
}
static V_73 F_58 ( struct V_55 * V_56 )
{
return 1 << V_56 -> V_77 ;
}
static void F_59 ( struct V_104 * V_105 )
{
struct V_104 * V_106 ;
while ( V_105 ) {
V_106 = V_105 ;
V_105 = V_105 -> V_107 ;
F_60 ( V_106 ) ;
}
}
static void F_61 ( struct V_104 * V_105 , int V_108 )
{
struct V_109 * V_110 ;
unsigned long V_33 ;
void * V_111 ;
int V_61 ;
int V_112 = 0 ;
while ( V_105 ) {
F_62 (bv, chain, i) {
if ( V_112 + V_110 -> V_113 > V_108 ) {
int V_114 = F_63 ( V_108 - V_112 , 0 ) ;
V_111 = F_64 ( V_110 , & V_33 ) ;
memset ( V_111 + V_114 , 0 ,
V_110 -> V_113 - V_114 ) ;
F_65 ( V_111 , & V_33 ) ;
}
V_112 += V_110 -> V_113 ;
}
V_105 = V_105 -> V_107 ;
}
}
static struct V_104 * F_66 ( struct V_104 * * V_115 , struct V_104 * * V_116 ,
struct V_117 * * V_118 ,
int V_97 , T_3 V_119 )
{
struct V_104 * V_106 , * V_120 = * V_115 , * V_121 = NULL , * V_122 = NULL ;
int V_123 = 0 ;
if ( * V_118 ) {
F_67 ( * V_118 ) ;
* V_118 = NULL ;
}
while ( V_120 && ( V_123 < V_97 ) ) {
V_106 = F_68 ( V_119 , V_120 -> V_124 ) ;
if ( ! V_106 )
goto V_125;
if ( V_123 + V_120 -> V_126 > V_97 ) {
struct V_117 * V_118 ;
F_11 ( L_12
L_13 ,
( int ) V_123 , ( int ) V_97 - V_123 ,
( int ) V_120 -> V_126 ) ;
V_118 = F_69 ( V_120 , ( V_97 - V_123 ) / 512ULL ) ;
if ( ! V_118 )
goto V_125;
F_70 ( V_106 , & V_118 -> V_127 ) ;
* V_116 = & V_118 -> V_128 ;
} else {
F_70 ( V_106 , V_120 ) ;
* V_116 = V_120 -> V_107 ;
}
V_106 -> V_129 = NULL ;
V_119 &= ~ V_130 ;
V_106 -> V_107 = NULL ;
if ( ! V_121 ) {
V_121 = V_122 = V_106 ;
} else {
V_122 -> V_107 = V_106 ;
V_122 = V_106 ;
}
V_120 = V_120 -> V_107 ;
V_123 += V_106 -> V_126 ;
}
F_32 ( V_123 < V_97 ) ;
if ( V_122 )
V_122 -> V_107 = NULL ;
* V_115 = V_120 ;
return V_121 ;
V_125:
F_11 ( L_14 ) ;
F_59 ( V_121 ) ;
return NULL ;
}
static int F_71 ( struct V_131 * * V_132 ,
int V_133 ,
int V_134 ,
T_4 V_135 )
{
* V_132 = F_34 ( sizeof( struct V_131 ) * ( V_133 + 1 ) ,
V_136 ) ;
if ( ! * V_132 )
return - V_22 ;
( * V_132 ) [ 0 ] . V_137 = V_134 ;
( * V_132 ) [ 0 ] . V_135 = V_135 ;
return 0 ;
}
static void F_72 ( struct V_131 * V_132 )
{
F_22 ( V_132 ) ;
}
static void F_73 ( struct V_138 * V_139 ,
struct V_53 * V_54 ,
int V_140 ,
int V_21 , V_73 V_97 )
{
struct V_141 * V_142 ;
int V_143 , F_63 , V_61 ;
F_11 ( L_15 ,
V_54 , V_140 , V_21 , V_97 ) ;
if ( ! V_139 )
return;
if ( ! V_54 ) {
F_74 ( V_139 , V_21 , V_97 ) ;
return;
}
V_142 = V_139 -> V_142 ;
F_75 ( V_142 -> V_144 ) ;
V_54 -> V_145 [ V_140 ] . V_95 = 1 ;
V_54 -> V_145 [ V_140 ] . V_146 = V_21 ;
V_54 -> V_145 [ V_140 ] . V_147 = V_97 ;
F_63 = V_143 = V_54 -> V_148 ;
while ( F_63 < V_54 -> V_123 && V_54 -> V_145 [ F_63 ] . V_95 )
F_63 ++ ;
for ( V_61 = V_143 ; V_61 < F_63 ; V_61 ++ ) {
F_76 ( V_139 , V_54 -> V_145 [ V_61 ] . V_146 ,
V_54 -> V_145 [ V_61 ] . V_147 ) ;
V_54 -> V_148 ++ ;
F_41 ( & V_54 -> V_25 , F_42 ) ;
}
F_77 ( V_142 -> V_144 ) ;
}
static void F_78 ( struct V_149 * V_150 ,
int V_21 , V_73 V_97 )
{
F_73 ( V_150 -> V_139 , V_150 -> V_54 , V_150 -> V_151 , V_21 , V_97 ) ;
}
static int F_79 ( struct V_138 * V_139 ,
struct V_1 * V_3 ,
struct V_68 * V_67 ,
V_73 V_152 ,
const char * V_153 , V_73 V_96 , V_73 V_97 ,
struct V_104 * V_104 ,
struct V_154 * * V_155 ,
int V_156 ,
int V_33 ,
struct V_131 * V_132 ,
int V_157 ,
struct V_53 * V_54 ,
int V_151 ,
void (* F_80)( struct V_158 * V_150 ,
struct V_159 * V_160 ) ,
struct V_158 * * V_161 ,
V_73 * V_162 )
{
struct V_158 * V_150 ;
struct V_163 * V_164 ;
int V_21 ;
V_73 V_165 ;
struct V_166 V_167 = V_168 ;
struct V_149 * V_169 ;
struct V_170 * V_171 ;
struct V_55 * V_56 = & V_3 -> V_56 ;
V_169 = F_34 ( sizeof( * V_169 ) , V_136 ) ;
if ( ! V_169 ) {
if ( V_54 )
F_73 ( V_139 , V_54 , V_151 ,
- V_22 , V_97 ) ;
return - V_22 ;
}
if ( V_54 ) {
V_169 -> V_54 = V_54 ;
V_169 -> V_151 = V_151 ;
}
F_11 ( L_16 , V_153 , V_97 , V_96 ) ;
F_81 ( & V_56 -> V_65 ) ;
V_150 = F_82 ( & V_3 -> V_27 -> V_172 , V_33 ,
V_67 ,
V_132 ,
false ,
V_136 , V_155 , V_104 ) ;
if ( ! V_150 ) {
F_83 ( & V_56 -> V_65 ) ;
V_21 = - V_22 ;
goto V_173;
}
V_150 -> V_174 = F_80 ;
V_169 -> V_139 = V_139 ;
V_169 -> V_104 = V_104 ;
V_169 -> V_155 = V_155 ;
V_169 -> V_97 = V_97 ;
V_150 -> V_175 = V_169 ;
V_171 = V_150 -> V_176 -> V_177 . V_178 ;
V_171 -> V_152 = F_84 ( V_179 ) ;
strncpy ( V_150 -> V_180 , V_153 , sizeof( V_150 -> V_180 ) ) ;
V_150 -> V_181 = strlen ( V_150 -> V_180 ) ;
V_164 = & V_150 -> V_182 ;
memset ( V_164 , 0 , sizeof( * V_164 ) ) ;
V_164 -> V_183 = F_85 ( 1 << V_184 ) ;
V_164 -> V_185 = F_85 ( 1 ) ;
V_164 -> V_186 = F_85 ( 1 << V_184 ) ;
V_164 -> V_187 = F_85 ( - 1 ) ;
V_164 -> V_188 = F_85 ( V_3 -> V_189 ) ;
F_86 ( & V_3 -> V_27 -> V_172 , V_164 , V_152 ,
V_96 , & V_97 , & V_165 , V_150 , V_132 ) ;
F_87 ( V_150 , V_96 , & V_97 ,
V_132 ,
V_67 ,
& V_167 ,
V_150 -> V_180 , V_150 -> V_181 ) ;
F_83 ( & V_56 -> V_65 ) ;
if ( V_161 ) {
F_88 ( & V_3 -> V_27 -> V_172 , V_150 ) ;
* V_161 = V_150 ;
}
V_21 = F_89 ( & V_3 -> V_27 -> V_172 , V_150 , false ) ;
if ( V_21 < 0 )
goto V_52;
if ( ! F_80 ) {
V_21 = F_90 ( & V_3 -> V_27 -> V_172 , V_150 ) ;
if ( V_162 )
* V_162 = F_46 ( V_150 -> V_190 . V_191 ) ;
F_11 ( L_17 ,
F_46 ( V_150 -> V_190 . V_191 ) ) ;
F_91 ( V_150 ) ;
}
return V_21 ;
V_52:
F_59 ( V_169 -> V_104 ) ;
F_91 ( V_150 ) ;
V_173:
F_78 ( V_169 , V_21 , V_97 ) ;
F_22 ( V_169 ) ;
return V_21 ;
}
static void F_92 ( struct V_158 * V_150 , struct V_159 * V_160 )
{
struct V_149 * V_169 = V_150 -> V_175 ;
struct V_192 * V_193 ;
struct V_194 * V_137 ;
T_5 V_146 ;
V_73 V_147 ;
int V_195 ;
V_193 = V_160 -> V_177 . V_178 ;
F_93 ( F_44 ( V_193 -> V_133 ) == 0 ) ;
V_137 = ( void * ) ( V_193 + 1 ) ;
V_146 = F_44 ( V_193 -> V_196 ) ;
V_147 = F_46 ( V_137 -> V_197 . V_198 ) ;
V_195 = ( F_44 ( V_137 -> V_137 ) == V_199 ) ;
F_11 ( L_18 , V_147 , V_195 , V_146 ) ;
if ( V_146 == - V_93 && V_195 ) {
F_61 ( V_169 -> V_104 , 0 ) ;
V_146 = 0 ;
} else if ( V_146 == 0 && V_195 && V_147 < V_169 -> V_97 ) {
F_61 ( V_169 -> V_104 , V_147 ) ;
V_147 = V_169 -> V_97 ;
}
F_78 ( V_169 , V_146 , V_147 ) ;
if ( V_169 -> V_104 )
F_59 ( V_169 -> V_104 ) ;
F_91 ( V_150 ) ;
F_22 ( V_169 ) ;
}
static void F_94 ( struct V_158 * V_150 , struct V_159 * V_160 )
{
F_91 ( V_150 ) ;
}
static int F_95 ( struct V_1 * V_3 ,
struct V_68 * V_67 ,
V_73 V_152 ,
int V_134 ,
int V_33 ,
struct V_131 * V_200 ,
int V_157 ,
const char * V_153 ,
V_73 V_96 , V_73 V_97 ,
char * V_111 ,
struct V_158 * * V_161 ,
V_73 * V_162 )
{
int V_21 ;
struct V_154 * * V_155 ;
int V_156 ;
struct V_131 * V_132 = V_200 ;
T_4 V_135 ;
V_156 = F_96 ( V_96 , V_97 ) ;
V_155 = F_97 ( V_156 , V_23 ) ;
if ( F_16 ( V_155 ) )
return F_37 ( V_155 ) ;
if ( ! V_200 ) {
V_135 = ( V_33 & V_201 ? V_97 : 0 ) ;
V_21 = F_71 ( & V_132 , 1 , V_134 , V_135 ) ;
if ( V_21 < 0 )
goto V_95;
if ( ( V_33 & V_201 ) && V_111 ) {
V_21 = F_98 ( V_155 , V_111 , V_96 , V_97 ) ;
if ( V_21 < 0 )
goto V_202;
}
}
V_21 = F_79 ( NULL , V_3 , V_67 , V_152 ,
V_153 , V_96 , V_97 , NULL ,
V_155 , V_156 ,
V_33 ,
V_132 ,
2 ,
NULL , 0 ,
NULL ,
V_161 , V_162 ) ;
if ( V_21 < 0 )
goto V_202;
if ( ( V_33 & V_203 ) && V_111 )
V_21 = F_99 ( V_155 , V_111 , V_96 , V_21 ) ;
V_202:
if ( ! V_200 )
F_72 ( V_132 ) ;
V_95:
F_100 ( V_155 , V_156 ) ;
return V_21 ;
}
static int F_101 ( struct V_138 * V_139 ,
struct V_1 * V_4 ,
struct V_68 * V_67 ,
V_73 V_152 ,
int V_134 , int V_33 , int V_157 ,
V_73 V_96 , V_73 V_97 ,
struct V_104 * V_104 ,
struct V_53 * V_54 ,
int V_151 )
{
char * V_98 ;
V_73 V_204 ;
V_73 V_205 ;
int V_21 ;
struct V_131 * V_132 ;
T_4 V_135 ;
V_98 = F_12 ( V_101 + 1 , V_136 ) ;
if ( ! V_98 )
return - V_22 ;
V_205 = F_55 ( & V_4 -> V_56 ,
V_4 -> V_56 . V_75 ,
V_96 , V_97 ,
V_98 , & V_204 ) ;
V_135 = ( V_33 & V_201 ? V_205 : 0 ) ;
V_21 = F_71 ( & V_132 , 1 , V_134 , V_135 ) ;
if ( V_21 < 0 )
goto V_95;
F_32 ( V_205 < V_97 ) ;
V_21 = F_79 ( V_139 , V_4 , V_67 , V_152 ,
V_98 , V_204 , V_205 ,
V_104 ,
NULL , 0 ,
V_33 ,
V_132 ,
V_157 ,
V_54 , V_151 ,
F_92 , 0 , NULL ) ;
F_72 ( V_132 ) ;
V_95:
F_22 ( V_98 ) ;
return V_21 ;
}
static int F_102 ( struct V_138 * V_139 ,
struct V_1 * V_4 ,
struct V_68 * V_67 ,
V_73 V_96 , V_73 V_97 ,
struct V_104 * V_104 ,
struct V_53 * V_54 ,
int V_151 )
{
return F_101 ( V_139 , V_4 , V_67 , V_179 ,
V_206 ,
V_201 | V_207 ,
2 ,
V_96 , V_97 , V_104 , V_54 , V_151 ) ;
}
static int F_103 ( struct V_138 * V_139 ,
struct V_1 * V_4 ,
V_73 V_152 ,
V_73 V_96 , V_73 V_97 ,
struct V_104 * V_104 ,
struct V_53 * V_54 ,
int V_151 )
{
return F_101 ( V_139 , V_4 , NULL ,
( V_152 ? V_152 : V_179 ) ,
V_199 ,
V_203 ,
2 ,
V_96 , V_97 , V_104 , V_54 , V_151 ) ;
}
static int F_104 ( struct V_1 * V_3 ,
struct V_68 * V_67 ,
V_73 V_152 ,
const char * V_153 ,
V_73 V_96 , V_73 V_97 ,
char * V_111 ,
V_73 * V_162 )
{
return F_95 ( V_3 , NULL ,
( V_152 ? V_152 : V_179 ) ,
V_199 ,
V_203 ,
NULL ,
1 , V_153 , V_96 , V_97 , V_111 , NULL , V_162 ) ;
}
static int F_105 ( struct V_1 * V_3 ,
V_73 V_162 ,
V_73 V_208 ,
const char * V_153 )
{
struct V_131 * V_132 ;
struct V_154 * * V_155 = NULL ;
int V_21 ;
V_21 = F_71 ( & V_132 , 1 , V_209 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_132 [ 0 ] . V_210 . V_162 = F_84 ( V_3 -> V_56 . V_211 ) ;
V_132 [ 0 ] . V_210 . V_212 = V_208 ;
V_132 [ 0 ] . V_210 . V_213 = 0 ;
V_21 = F_79 ( NULL , V_3 , NULL , V_179 ,
V_153 , 0 , 0 , NULL ,
V_155 , 0 ,
V_203 ,
V_132 ,
1 ,
NULL , 0 ,
F_94 , 0 , NULL ) ;
F_72 ( V_132 ) ;
return V_21 ;
}
static void F_106 ( V_73 V_162 , V_73 V_208 , T_6 V_134 , void * V_214 )
{
struct V_1 * V_3 = (struct V_1 * ) V_214 ;
int V_146 ;
if ( ! V_3 )
return;
F_11 ( L_19 , V_3 -> V_215 ,
V_208 , ( int ) V_134 ) ;
F_107 ( & V_216 , V_217 ) ;
V_146 = F_108 ( V_3 ) ;
F_109 ( & V_216 ) ;
if ( V_146 )
F_110 ( V_218 L_20
L_21 , V_3 -> V_219 , V_146 ) ;
F_105 ( V_3 , V_162 , V_208 , V_3 -> V_215 ) ;
}
static int F_111 ( struct V_1 * V_3 ,
const char * V_153 ,
V_73 V_162 )
{
struct V_131 * V_132 ;
struct V_220 * V_172 = & V_3 -> V_27 -> V_172 ;
int V_21 = F_71 ( & V_132 , 1 , V_221 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_112 ( V_172 , F_106 , 0 ,
( void * ) V_3 , & V_3 -> V_222 ) ;
if ( V_21 < 0 )
goto V_223;
V_132 [ 0 ] . V_210 . V_162 = F_84 ( V_162 ) ;
V_132 [ 0 ] . V_210 . V_212 = F_84 ( V_3 -> V_222 -> V_212 ) ;
V_132 [ 0 ] . V_210 . V_213 = 1 ;
V_21 = F_95 ( V_3 , NULL ,
V_179 ,
0 ,
V_201 | V_207 ,
V_132 ,
1 , V_153 , 0 , 0 , NULL ,
& V_3 -> V_224 , NULL ) ;
if ( V_21 < 0 )
goto V_225;
F_72 ( V_132 ) ;
return 0 ;
V_225:
F_113 ( V_3 -> V_222 ) ;
V_3 -> V_222 = NULL ;
V_223:
F_72 ( V_132 ) ;
return V_21 ;
}
static int F_114 ( struct V_1 * V_3 ,
const char * V_153 )
{
struct V_131 * V_132 ;
int V_21 = F_71 ( & V_132 , 1 , V_221 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_132 [ 0 ] . V_210 . V_162 = 0 ;
V_132 [ 0 ] . V_210 . V_212 = F_84 ( V_3 -> V_222 -> V_212 ) ;
V_132 [ 0 ] . V_210 . V_213 = 0 ;
V_21 = F_95 ( V_3 , NULL ,
V_179 ,
0 ,
V_201 | V_207 ,
V_132 ,
1 , V_153 , 0 , 0 , NULL , NULL , NULL ) ;
F_72 ( V_132 ) ;
F_113 ( V_3 -> V_222 ) ;
V_3 -> V_222 = NULL ;
return V_21 ;
}
static void F_115 ( V_73 V_162 , V_73 V_208 , T_6 V_134 , void * V_214 )
{
struct V_1 * V_3 = (struct V_1 * ) V_214 ;
if ( ! V_3 )
return;
F_11 ( L_22 , V_3 -> V_215 ,
V_208 , ( int ) V_134 ) ;
}
static int F_116 ( struct V_1 * V_3 ,
const char * V_153 )
{
struct V_131 * V_132 ;
struct V_220 * V_172 = & V_3 -> V_27 -> V_172 ;
struct V_226 * V_227 ;
struct V_228 V_229 ;
int V_135 = sizeof( T_4 ) + sizeof( T_4 ) ;
int V_21 ;
V_21 = F_71 ( & V_132 , 1 , V_230 , V_135 ) ;
if ( V_21 < 0 )
return V_21 ;
V_229 . V_3 = V_3 ;
V_21 = F_112 ( V_172 , F_115 , 1 ,
( void * ) & V_229 , & V_227 ) ;
if ( V_21 < 0 )
goto V_223;
V_132 [ 0 ] . V_210 . V_162 = 1 ;
V_132 [ 0 ] . V_210 . V_213 = 1 ;
V_132 [ 0 ] . V_210 . V_212 = V_227 -> V_212 ;
V_132 [ 0 ] . V_210 . V_231 = V_232 ;
V_132 [ 0 ] . V_210 . V_233 = 12 ;
V_21 = F_95 ( V_3 , NULL ,
V_179 ,
0 ,
V_201 | V_207 ,
V_132 ,
1 , V_153 , 0 , 0 , NULL , NULL , NULL ) ;
if ( V_21 < 0 )
goto V_225;
V_21 = F_117 ( V_227 , V_234 ) ;
F_11 ( L_23 , V_21 ) ;
F_72 ( V_132 ) ;
return 0 ;
V_225:
F_113 ( V_227 ) ;
V_223:
F_72 ( V_132 ) ;
return V_21 ;
}
static int F_118 ( struct V_1 * V_3 ,
const char * V_153 ,
const char * V_235 ,
const char * V_236 ,
const char * V_214 ,
int V_97 ,
V_73 * V_162 )
{
struct V_131 * V_132 ;
int V_237 = strlen ( V_235 ) ;
int V_238 = strlen ( V_236 ) ;
int V_21 = F_71 ( & V_132 , 1 , V_239 ,
V_237 + V_238 + V_97 ) ;
if ( V_21 < 0 )
return V_21 ;
V_132 [ 0 ] . V_235 . V_240 = V_235 ;
V_132 [ 0 ] . V_235 . V_241 = ( V_242 ) V_237 ;
V_132 [ 0 ] . V_235 . V_243 = V_236 ;
V_132 [ 0 ] . V_235 . V_238 = ( V_242 ) V_238 ;
V_132 [ 0 ] . V_235 . V_244 = 0 ;
V_132 [ 0 ] . V_235 . V_245 = V_214 ;
V_132 [ 0 ] . V_235 . V_246 = V_97 ;
V_21 = F_95 ( V_3 , NULL ,
V_179 ,
0 ,
V_201 | V_207 ,
V_132 ,
1 , V_153 , 0 , 0 , NULL , NULL , V_162 ) ;
F_72 ( V_132 ) ;
F_11 ( L_24 , V_21 ) ;
return V_21 ;
}
static struct V_53 * F_119 ( int V_247 )
{
struct V_53 * V_54 =
F_34 ( sizeof( struct V_53 ) +
sizeof( struct V_248 ) * V_247 ,
V_249 ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_123 = V_247 ;
F_13 ( & V_54 -> V_25 ) ;
return V_54 ;
}
static void F_120 ( struct V_141 * V_142 )
{
struct V_1 * V_4 = V_142 -> V_250 ;
struct V_138 * V_139 ;
struct V_117 * V_118 = NULL ;
V_139 = F_121 ( V_142 ) ;
while ( 1 ) {
struct V_104 * V_104 ;
struct V_104 * V_251 , * V_252 = NULL ;
bool V_253 ;
int V_91 , V_254 = 0 ;
V_73 V_96 ;
int V_255 , V_256 = 0 ;
struct V_53 * V_54 ;
if ( ! V_139 )
break;
F_11 ( L_25 ) ;
if ( ( V_139 -> V_257 != V_258 ) ) {
F_122 ( V_139 , 0 ) ;
goto V_116;
}
V_253 = ( F_123 ( V_139 ) == V_259 ) ;
V_91 = F_124 ( V_139 ) ;
V_96 = F_125 ( V_139 ) * 512ULL ;
V_251 = V_139 -> V_104 ;
if ( V_253 && V_4 -> V_12 ) {
F_122 ( V_139 , - V_14 ) ;
goto V_116;
}
F_77 ( V_142 -> V_144 ) ;
F_11 ( L_26 ,
V_253 ? L_27 : L_28 ,
V_91 , F_125 ( V_139 ) * 512ULL ) ;
V_255 = F_57 ( & V_4 -> V_56 , V_96 , V_91 ) ;
V_54 = F_119 ( V_255 ) ;
if ( ! V_54 ) {
F_75 ( V_142 -> V_144 ) ;
F_122 ( V_139 , - V_22 ) ;
goto V_116;
}
do {
F_11 ( L_29 , V_139 -> V_104 -> V_260 ) ;
V_254 = F_55 ( & V_4 -> V_56 ,
V_4 -> V_56 . V_75 ,
V_96 , V_91 ,
NULL , NULL ) ;
F_36 ( & V_54 -> V_25 ) ;
V_104 = F_66 ( & V_251 , & V_252 , & V_118 ,
V_254 , V_249 ) ;
if ( ! V_104 ) {
F_73 ( V_139 , V_54 , V_256 ,
- V_22 , V_254 ) ;
goto V_261;
}
if ( V_253 )
F_102 ( V_139 , V_4 ,
V_4 -> V_56 . V_67 ,
V_96 ,
V_254 , V_104 ,
V_54 , V_256 ) ;
else
F_103 ( V_139 , V_4 ,
F_49 ( V_4 ) ,
V_96 ,
V_254 , V_104 ,
V_54 , V_256 ) ;
V_261:
V_91 -= V_254 ;
V_96 += V_254 ;
V_256 ++ ;
V_251 = V_252 ;
} while ( V_91 > 0 );
F_41 ( & V_54 -> V_25 , F_42 ) ;
if ( V_118 )
F_67 ( V_118 ) ;
F_75 ( V_142 -> V_144 ) ;
V_116:
V_139 = F_121 ( V_142 ) ;
}
}
static int F_126 ( struct V_141 * V_142 , struct V_262 * V_263 ,
struct V_109 * V_264 )
{
struct V_1 * V_4 = V_142 -> V_250 ;
unsigned int V_265 = 1 << ( V_4 -> V_56 . V_77 - 9 ) ;
T_7 V_266 = V_263 -> V_267 + F_127 ( V_263 -> V_129 ) ;
unsigned int V_268 = V_263 -> V_126 >> 9 ;
int F_63 ;
F_63 = ( V_265 - ( ( V_266 & ( V_265 - 1 ) )
+ V_268 ) ) << 9 ;
if ( F_63 < 0 )
F_63 = 0 ;
if ( F_63 <= V_264 -> V_113 && V_268 == 0 )
return V_264 -> V_113 ;
return F_63 ;
}
static void F_128 ( struct V_1 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( ! V_9 )
return;
F_54 ( & V_4 -> V_56 ) ;
if ( V_9 -> V_33 & V_269 )
F_129 ( V_9 ) ;
if ( V_9 -> V_270 )
F_130 ( V_9 -> V_270 ) ;
F_131 ( V_9 ) ;
}
static int F_132 ( struct V_1 * V_4 ,
struct V_55 * V_56 )
{
T_8 V_146 ;
struct V_57 * V_271 ;
int V_62 = 0 ;
V_73 V_66 = 0 ;
V_73 V_162 ;
while ( 1 ) {
int V_97 = sizeof( * V_271 ) +
V_62 * sizeof( struct V_69 ) +
V_66 ;
V_146 = - V_22 ;
V_271 = F_12 ( V_97 , V_23 ) ;
if ( ! V_271 )
return - V_22 ;
V_146 = F_104 ( V_4 ,
NULL , V_179 ,
V_4 -> V_215 ,
0 , V_97 ,
( char * ) V_271 , & V_162 ) ;
if ( V_146 < 0 )
goto V_272;
V_146 = F_43 ( V_56 , V_271 , V_62 , V_23 ) ;
if ( V_146 < 0 ) {
if ( V_146 == - V_64 ) {
F_110 ( L_30
L_31 , V_4 -> V_153 ) ;
}
goto V_272;
}
if ( V_62 != V_56 -> V_84 ) {
V_62 = V_56 -> V_84 ;
V_66 = V_56 -> V_66 ;
F_54 ( V_56 ) ;
F_22 ( V_271 ) ;
continue;
}
break;
}
V_56 -> V_211 = V_162 ;
V_272:
F_22 ( V_271 ) ;
return V_146 ;
}
static int F_133 ( struct V_1 * V_3 ,
const char * V_89 ,
T_3 V_60 )
{
int V_273 = strlen ( V_89 ) ;
V_73 V_274 ;
int V_21 ;
void * V_214 , * V_92 , * V_275 ;
V_73 V_162 ;
if ( V_3 -> V_88 )
return - V_43 ;
V_21 = F_134 ( & V_3 -> V_27 -> V_276 , V_3 -> V_189 ,
& V_274 ) ;
F_11 ( L_32 , V_274 ) ;
if ( V_21 < 0 )
return V_21 ;
V_214 = F_12 ( V_273 + 16 , V_60 ) ;
if ( ! V_214 )
return - V_22 ;
V_92 = V_214 ;
V_275 = V_214 + V_273 + 16 ;
F_135 ( & V_92 , V_275 , V_89 , V_273 , V_277 ) ;
F_136 ( & V_92 , V_275 , V_274 , V_277 ) ;
V_21 = F_118 ( V_3 , V_3 -> V_215 , L_33 , L_34 ,
V_214 , V_92 - V_214 , & V_162 ) ;
F_22 ( V_214 ) ;
if ( V_21 < 0 )
return V_21 ;
V_3 -> V_56 . V_67 -> V_90 = V_274 ;
return 0 ;
V_277:
return - V_278 ;
}
static void F_137 ( struct V_1 * V_4 )
{
struct V_279 * V_280 ;
while ( ! F_138 ( & V_4 -> V_85 ) ) {
V_280 = F_139 ( & V_4 -> V_85 , struct V_279 , V_26 ) ;
F_140 ( V_4 , V_280 ) ;
}
}
static int F_108 ( struct V_1 * V_4 )
{
int V_21 ;
struct V_55 V_281 ;
V_73 V_82 ;
int V_282 = 0 ;
V_21 = F_132 ( V_4 , & V_281 ) ;
if ( V_21 < 0 )
return V_21 ;
F_141 ( V_4 -> V_9 , V_281 . V_76 / 512ULL ) ;
F_52 ( & V_4 -> V_56 . V_65 ) ;
V_82 = V_4 -> V_56 . V_67 -> V_90 ;
if ( V_4 -> V_56 . V_84 &&
V_4 -> V_56 . V_67 -> V_85 [ 0 ] == V_82 )
V_282 = 1 ;
F_22 ( V_4 -> V_56 . V_67 ) ;
F_22 ( V_4 -> V_56 . V_70 ) ;
F_22 ( V_4 -> V_56 . V_72 ) ;
V_4 -> V_56 . V_84 = V_281 . V_84 ;
V_4 -> V_56 . V_67 = V_281 . V_67 ;
V_4 -> V_56 . V_70 = V_281 . V_70 ;
V_4 -> V_56 . V_66 = V_281 . V_66 ;
V_4 -> V_56 . V_72 = V_281 . V_72 ;
if ( V_282 )
V_4 -> V_56 . V_67 -> V_90 = V_4 -> V_56 . V_67 -> V_85 [ 0 ] ;
else
V_4 -> V_56 . V_67 -> V_90 = V_82 ;
V_21 = F_142 ( V_4 ) ;
F_53 ( & V_4 -> V_56 . V_65 ) ;
return V_21 ;
}
static int F_143 ( struct V_1 * V_4 )
{
struct V_8 * V_9 ;
struct V_141 * V_142 ;
int V_146 ;
V_73 V_283 = 0 ;
V_146 = F_132 ( V_4 , & V_4 -> V_56 ) ;
if ( V_146 )
return V_146 ;
V_146 = F_142 ( V_4 ) ;
if ( V_146 )
return V_146 ;
V_146 = F_51 ( V_4 , V_4 -> V_89 , & V_283 ) ;
if ( V_146 )
return V_146 ;
V_146 = - V_22 ;
V_9 = F_144 ( V_284 ) ;
if ( ! V_9 )
goto V_285;
snprintf ( V_9 -> V_286 , sizeof( V_9 -> V_286 ) , V_218 L_35 ,
V_4 -> V_86 ) ;
V_9 -> V_219 = V_4 -> V_219 ;
V_9 -> V_287 = 0 ;
V_9 -> V_288 = & V_289 ;
V_9 -> V_11 = V_4 ;
V_146 = - V_22 ;
V_142 = F_145 ( F_120 , & V_4 -> V_290 ) ;
if ( ! V_142 )
goto V_291;
F_146 ( V_142 , F_58 ( & V_4 -> V_56 ) / 512ULL ) ;
F_147 ( V_142 , F_58 ( & V_4 -> V_56 ) ) ;
F_148 ( V_142 , F_58 ( & V_4 -> V_56 ) ) ;
F_149 ( V_142 , F_58 ( & V_4 -> V_56 ) ) ;
F_150 ( V_142 , F_126 ) ;
V_9 -> V_270 = V_142 ;
V_142 -> V_250 = V_4 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_142 = V_142 ;
F_141 ( V_9 , V_283 / 512ULL ) ;
F_151 ( V_9 ) ;
F_152 ( L_36 ,
V_9 -> V_286 , ( unsigned long long ) V_283 ) ;
return 0 ;
V_291:
F_131 ( V_9 ) ;
V_285:
return V_146 ;
}
static T_8 F_153 ( struct V_2 * V_3 ,
struct V_292 * V_293 , char * V_111 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_111 , L_37 , ( unsigned long long ) V_4 -> V_56 . V_76 ) ;
}
static T_8 F_154 ( struct V_2 * V_3 ,
struct V_292 * V_293 , char * V_111 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_111 , L_38 , V_4 -> V_219 ) ;
}
static T_8 F_155 ( struct V_2 * V_3 ,
struct V_292 * V_293 , char * V_111 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_111 , L_39 , F_156 ( V_4 -> V_27 ) ) ;
}
static T_8 F_157 ( struct V_2 * V_3 ,
struct V_292 * V_293 , char * V_111 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_111 , L_40 , V_4 -> V_294 ) ;
}
static T_8 F_158 ( struct V_2 * V_3 ,
struct V_292 * V_293 , char * V_111 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_111 , L_40 , V_4 -> V_153 ) ;
}
static T_8 F_159 ( struct V_2 * V_3 ,
struct V_292 * V_293 ,
char * V_111 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_111 , L_40 , V_4 -> V_89 ) ;
}
static T_8 F_160 ( struct V_2 * V_3 ,
struct V_292 * V_293 ,
const char * V_111 ,
T_9 V_91 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_146 ;
int V_21 = V_91 ;
F_107 ( & V_216 , V_217 ) ;
V_146 = F_108 ( V_4 ) ;
if ( V_146 < 0 )
V_21 = V_146 ;
F_109 ( & V_216 ) ;
return V_21 ;
}
static void F_161 ( struct V_2 * V_3 )
{
}
static T_8 F_162 ( struct V_2 * V_3 ,
struct V_292 * V_293 ,
char * V_111 )
{
struct V_279 * V_280 = F_2 ( V_3 , struct V_279 , V_3 ) ;
return sprintf ( V_111 , L_41 , ( long long ) V_280 -> V_91 ) ;
}
static T_8 F_163 ( struct V_2 * V_3 ,
struct V_292 * V_293 ,
char * V_111 )
{
struct V_279 * V_280 = F_2 ( V_3 , struct V_279 , V_3 ) ;
return sprintf ( V_111 , L_41 , ( long long ) V_280 -> V_86 ) ;
}
static void F_164 ( struct V_2 * V_3 )
{
struct V_279 * V_280 = F_2 ( V_3 , struct V_279 , V_3 ) ;
F_22 ( V_280 -> V_295 ) ;
F_22 ( V_280 ) ;
}
static void F_140 ( struct V_1 * V_4 ,
struct V_279 * V_280 )
{
F_39 ( & V_280 -> V_26 ) ;
F_165 ( & V_280 -> V_3 ) ;
}
static int F_166 ( struct V_1 * V_4 ,
struct V_279 * V_280 ,
struct V_2 * V_296 )
{
struct V_2 * V_3 = & V_280 -> V_3 ;
int V_21 ;
V_3 -> type = & V_297 ;
V_3 -> V_296 = V_296 ;
V_3 -> V_298 = F_164 ;
F_167 ( V_3 , L_42 , V_280 -> V_295 ) ;
V_21 = F_168 ( V_3 ) ;
return V_21 ;
}
static int F_169 ( struct V_1 * V_4 ,
int V_61 , const char * V_295 ,
struct V_279 * * V_299 )
{
int V_21 ;
struct V_279 * V_280 = F_34 ( sizeof( * V_280 ) , V_23 ) ;
if ( ! V_280 )
return - V_22 ;
V_280 -> V_295 = F_170 ( V_295 , V_23 ) ;
V_280 -> V_91 = V_4 -> V_56 . V_72 [ V_61 ] ;
V_280 -> V_86 = V_4 -> V_56 . V_67 -> V_85 [ V_61 ] ;
if ( F_171 ( & V_4 -> V_3 ) ) {
V_21 = F_166 ( V_4 , V_280 ,
& V_4 -> V_3 ) ;
if ( V_21 < 0 )
goto V_300;
}
* V_299 = V_280 ;
return 0 ;
V_300:
F_22 ( V_280 -> V_295 ) ;
F_22 ( V_280 ) ;
return V_21 ;
}
const char * F_172 ( const char * V_295 , const char * V_301 )
{
if ( V_295 < V_301 + 2 )
return NULL ;
V_295 -= 2 ;
while ( * V_295 ) {
if ( V_295 == V_301 )
return V_301 ;
V_295 -- ;
}
return V_295 + 1 ;
}
static int F_142 ( struct V_1 * V_4 )
{
const char * V_295 , * V_302 ;
int V_61 = V_4 -> V_56 . V_84 ;
struct V_279 * V_280 , * V_303 = NULL ;
int V_21 ;
struct V_304 * V_92 , * V_305 ;
V_302 = V_4 -> V_56 . V_70 ;
V_295 = V_302 + V_4 -> V_56 . V_66 ;
F_173 (p, n, &rbd_dev->snaps) {
V_73 V_306 ;
V_303 = F_174 ( V_92 , struct V_279 , V_26 ) ;
if ( V_61 )
V_306 = V_4 -> V_56 . V_67 -> V_85 [ V_61 - 1 ] ;
if ( ! V_61 || V_303 -> V_86 < V_306 ) {
F_140 ( V_4 , V_303 ) ;
continue;
}
if ( V_303 -> V_86 == V_306 ) {
V_61 -- ;
V_295 = F_172 ( V_295 , V_302 ) ;
continue;
}
for (; V_61 > 0 ;
V_61 -- , V_295 = F_172 ( V_295 , V_302 ) ) {
if ( ! V_295 ) {
F_93 ( 1 ) ;
return - V_43 ;
}
V_306 = V_4 -> V_56 . V_67 -> V_85 [ V_61 ] ;
if ( V_306 >= V_303 -> V_86 )
break;
V_21 = F_169 ( V_4 , V_61 - 1 , V_295 , & V_280 ) ;
if ( V_21 < 0 )
return V_21 ;
F_175 ( & V_280 -> V_26 , V_305 ) ;
V_92 = & V_280 -> V_26 ;
}
}
for (; V_61 > 0 ; V_61 -- ) {
V_295 = F_172 ( V_295 , V_302 ) ;
if ( ! V_295 ) {
F_93 ( 1 ) ;
return - V_43 ;
}
V_21 = F_169 ( V_4 , V_61 - 1 , V_295 , & V_280 ) ;
if ( V_21 < 0 )
return V_21 ;
F_175 ( & V_280 -> V_26 , & V_4 -> V_85 ) ;
}
return 0 ;
}
static void F_176 ( struct V_2 * V_3 )
{
}
static int F_177 ( struct V_1 * V_4 )
{
int V_21 = - V_22 ;
struct V_2 * V_3 ;
struct V_279 * V_280 ;
F_107 ( & V_216 , V_217 ) ;
V_3 = & V_4 -> V_3 ;
V_3 -> V_307 = & V_308 ;
V_3 -> type = & V_309 ;
V_3 -> V_296 = & V_310 ;
V_3 -> V_298 = V_311 ;
F_167 ( V_3 , L_35 , V_4 -> V_86 ) ;
V_21 = F_168 ( V_3 ) ;
if ( V_21 < 0 )
goto V_312;
F_26 (snap, &rbd_dev->snaps, node) {
V_21 = F_166 ( V_4 , V_280 ,
& V_4 -> V_3 ) ;
if ( V_21 < 0 )
break;
}
F_109 ( & V_216 ) ;
return 0 ;
V_312:
F_109 ( & V_216 ) ;
return V_21 ;
}
static void F_178 ( struct V_1 * V_4 )
{
F_165 ( & V_4 -> V_3 ) ;
}
static int F_179 ( struct V_1 * V_4 )
{
int V_21 , V_146 ;
do {
V_21 = F_111 ( V_4 , V_4 -> V_215 ,
V_4 -> V_56 . V_211 ) ;
if ( V_21 == - V_278 ) {
F_107 ( & V_216 , V_217 ) ;
V_146 = F_108 ( V_4 ) ;
F_109 ( & V_216 ) ;
if ( V_146 < 0 )
return V_146 ;
}
} while ( V_21 == - V_278 );
return V_21 ;
}
static T_8 F_180 ( struct V_313 * V_307 ,
const char * V_111 ,
T_9 V_314 )
{
struct V_220 * V_172 ;
struct V_1 * V_4 ;
T_8 V_146 = - V_22 ;
int V_315 , V_316 = 0 ;
struct V_304 * V_106 ;
char * V_317 ;
char * V_50 ;
if ( ! F_181 ( V_318 ) )
return - V_319 ;
V_317 = F_12 ( V_320 , V_23 ) ;
if ( ! V_317 )
goto V_321;
V_50 = F_12 ( V_320 , V_23 ) ;
if ( ! V_50 )
goto V_322;
V_4 = F_34 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
goto V_323;
F_182 ( & V_4 -> V_290 ) ;
F_14 ( & V_4 -> V_26 ) ;
F_14 ( & V_4 -> V_85 ) ;
F_107 ( & V_216 , V_217 ) ;
F_183 (tmp, &rbd_dev_list) {
struct V_1 * V_4 ;
V_4 = F_174 ( V_106 , struct V_1 , V_26 ) ;
if ( V_4 -> V_86 >= V_316 )
V_316 = V_4 -> V_86 + 1 ;
}
V_4 -> V_86 = V_316 ;
F_19 ( & V_4 -> V_26 , & V_324 ) ;
if ( sscanf ( V_111 , L_43 F_184 ( V_320 ) L_44
L_43 F_184 ( V_320 ) L_44
L_43 F_184 ( V_325 ) L_44
L_43 F_184 ( V_326 ) L_45
L_43 F_184 ( V_327 ) L_45 ,
V_317 , V_50 , V_4 -> V_294 ,
V_4 -> V_153 , V_4 -> V_89 ) < 4 ) {
V_146 = - V_43 ;
goto V_328;
}
if ( V_4 -> V_89 [ 0 ] == 0 )
V_4 -> V_89 [ 0 ] = '-' ;
V_4 -> V_329 = strlen ( V_4 -> V_153 ) ;
snprintf ( V_4 -> V_215 , sizeof( V_4 -> V_215 ) , L_46 ,
V_4 -> V_153 , V_330 ) ;
snprintf ( V_4 -> V_295 , V_331 , V_218 L_35 , V_4 -> V_86 ) ;
V_146 = F_33 ( V_4 , V_317 , V_50 ) ;
if ( V_146 < 0 )
goto V_328;
F_109 ( & V_216 ) ;
V_172 = & V_4 -> V_27 -> V_172 ;
V_146 = F_185 ( V_172 -> V_332 , V_4 -> V_294 ) ;
if ( V_146 < 0 )
goto V_333;
V_4 -> V_189 = V_146 ;
V_315 = F_186 ( 0 , V_4 -> V_295 ) ;
if ( V_315 < 0 ) {
V_146 = V_315 ;
goto V_333;
}
V_4 -> V_219 = V_315 ;
V_146 = F_177 ( V_4 ) ;
if ( V_146 )
goto V_334;
V_146 = F_143 ( V_4 ) ;
if ( V_146 )
goto V_335;
V_146 = F_179 ( V_4 ) ;
if ( V_146 )
goto V_335;
return V_314 ;
V_335:
F_107 ( & V_216 , V_217 ) ;
F_187 ( & V_4 -> V_26 ) ;
F_109 ( & V_216 ) ;
F_178 ( V_4 ) ;
F_22 ( V_50 ) ;
F_22 ( V_317 ) ;
return V_146 ;
V_334:
F_188 ( V_4 -> V_219 , V_4 -> V_295 ) ;
V_333:
F_40 ( V_4 ) ;
F_107 ( & V_216 , V_217 ) ;
V_328:
F_187 ( & V_4 -> V_26 ) ;
F_109 ( & V_216 ) ;
F_22 ( V_4 ) ;
V_323:
F_22 ( V_50 ) ;
V_322:
F_22 ( V_317 ) ;
V_321:
F_11 ( L_47 , V_111 ) ;
F_189 ( V_318 ) ;
return V_146 ;
}
static struct V_1 * F_190 ( unsigned long V_86 )
{
struct V_304 * V_106 ;
struct V_1 * V_4 ;
F_183 (tmp, &rbd_dev_list) {
V_4 = F_174 ( V_106 , struct V_1 , V_26 ) ;
if ( V_4 -> V_86 == V_86 )
return V_4 ;
}
return NULL ;
}
static void V_311 ( struct V_2 * V_3 )
{
struct V_1 * V_4 =
F_2 ( V_3 , struct V_1 , V_3 ) ;
if ( V_4 -> V_224 )
F_191 ( & V_4 -> V_27 -> V_172 ,
V_4 -> V_224 ) ;
if ( V_4 -> V_222 )
F_114 ( V_4 , V_4 -> V_215 ) ;
F_40 ( V_4 ) ;
F_128 ( V_4 ) ;
F_188 ( V_4 -> V_219 , V_4 -> V_295 ) ;
F_22 ( V_4 ) ;
F_189 ( V_318 ) ;
}
static T_8 F_192 ( struct V_313 * V_307 ,
const char * V_111 ,
T_9 V_314 )
{
struct V_1 * V_4 = NULL ;
int V_336 , V_146 ;
unsigned long V_337 ;
int V_21 = V_314 ;
V_146 = F_193 ( V_111 , 10 , & V_337 ) ;
if ( V_146 )
return V_146 ;
V_336 = ( int ) V_337 ;
if ( V_336 != V_337 )
return - V_43 ;
F_107 ( & V_216 , V_217 ) ;
V_4 = F_190 ( V_336 ) ;
if ( ! V_4 ) {
V_21 = - V_93 ;
goto V_95;
}
F_187 ( & V_4 -> V_26 ) ;
F_137 ( V_4 ) ;
F_178 ( V_4 ) ;
V_95:
F_109 ( & V_216 ) ;
return V_21 ;
}
static T_8 F_194 ( struct V_2 * V_3 ,
struct V_292 * V_293 ,
const char * V_111 ,
T_9 V_314 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_21 ;
char * V_295 = F_12 ( V_314 + 1 , V_23 ) ;
if ( ! V_295 )
return - V_22 ;
snprintf ( V_295 , V_314 , L_48 , V_111 ) ;
F_107 ( & V_216 , V_217 ) ;
V_21 = F_133 ( V_4 ,
V_295 , V_23 ) ;
if ( V_21 < 0 )
goto V_338;
V_21 = F_108 ( V_4 ) ;
if ( V_21 < 0 )
goto V_338;
F_109 ( & V_216 ) ;
F_116 ( V_4 , V_4 -> V_215 ) ;
V_21 = V_314 ;
F_22 ( V_295 ) ;
return V_21 ;
V_338:
F_109 ( & V_216 ) ;
F_22 ( V_295 ) ;
return V_21 ;
}
static int F_195 ( void )
{
int V_21 ;
V_308 . V_339 = V_340 ;
V_21 = F_196 ( & V_308 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_168 ( & V_310 ) ;
return V_21 ;
}
static void F_197 ( void )
{
F_165 ( & V_310 ) ;
F_198 ( & V_308 ) ;
}
int T_10 F_199 ( void )
{
int V_146 ;
V_146 = F_195 () ;
if ( V_146 )
return V_146 ;
F_182 ( & V_30 ) ;
F_152 ( L_49 V_341 L_50 ) ;
return 0 ;
}
void T_11 F_200 ( void )
{
F_197 () ;
}
