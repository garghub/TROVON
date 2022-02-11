void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 . V_6 ;
struct V_7 * V_8 ;
V_8 = & V_4 -> V_9 [ F_2 ( V_2 ) -> V_10 & ( V_11 - 1 ) ] ;
F_3 ( & V_4 -> V_12 ) ;
F_4 ( V_2 , V_8 ) ;
F_5 ( F_6 ( V_2 ) , V_2 -> V_5 , 1 ) ;
F_7 ( & V_4 -> V_12 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 . V_6 ;
F_3 ( & V_4 -> V_12 ) ;
if ( F_9 ( V_2 ) )
F_5 ( F_6 ( V_2 ) , V_2 -> V_5 , - 1 ) ;
F_7 ( & V_4 -> V_12 ) ;
}
static struct V_1 * F_10 ( struct V_13 * V_13 , struct V_1 * V_2 ,
unsigned short V_14 , T_1 V_15 , T_1 V_16 , int V_17 )
{
struct V_18 * V_19 ;
F_11 (sk, node) {
struct V_20 * V_21 = F_2 ( V_2 ) ;
if ( F_12 ( F_6 ( V_2 ) , V_13 ) && V_21 -> V_10 == V_14 &&
! ( V_21 -> V_22 && V_21 -> V_22 != V_15 ) &&
! ( V_21 -> V_23 && V_21 -> V_23 != V_16 ) &&
! ( V_2 -> V_24 && V_2 -> V_24 != V_17 ) )
goto V_25;
}
V_2 = NULL ;
V_25:
return V_2 ;
}
static T_2 int F_13 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
int type ;
if ( ! F_14 ( V_27 , sizeof( struct V_28 ) ) )
return 1 ;
type = F_15 ( V_27 ) -> type ;
if ( type < 32 ) {
T_3 V_29 = F_16 ( V_2 ) -> V_30 . V_29 ;
return ( ( 1 << type ) & V_29 ) != 0 ;
}
return 0 ;
}
static int F_17 ( struct V_26 * V_27 , const struct V_31 * V_32 , int V_33 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_34 = 0 ;
struct V_13 * V_13 ;
F_18 ( & V_35 . V_12 ) ;
V_8 = & V_35 . V_9 [ V_33 ] ;
if ( F_19 ( V_8 ) )
goto V_36;
V_13 = F_20 ( V_27 -> V_37 ) ;
V_2 = F_10 ( V_13 , F_21 ( V_8 ) , V_32 -> V_38 ,
V_32 -> V_39 , V_32 -> V_40 ,
V_27 -> V_37 -> V_41 ) ;
while ( V_2 ) {
V_34 = 1 ;
if ( V_32 -> V_38 != V_42 || ! F_13 ( V_2 , V_27 ) ) {
struct V_26 * V_43 = F_22 ( V_27 , V_44 ) ;
if ( V_43 )
F_23 ( V_2 , V_43 ) ;
}
V_2 = F_10 ( V_13 , F_24 ( V_2 ) , V_32 -> V_38 ,
V_32 -> V_39 , V_32 -> V_40 ,
V_27 -> V_37 -> V_41 ) ;
}
V_36:
F_25 ( & V_35 . V_12 ) ;
return V_34 ;
}
int F_26 ( struct V_26 * V_27 , int V_38 )
{
int V_33 ;
struct V_1 * F_16 ;
V_33 = V_38 & ( V_11 - 1 ) ;
F_16 = F_27 ( & V_35 . V_9 [ V_33 ] ) ;
if ( F_16 && ! F_17 ( V_27 , F_28 ( V_27 ) , V_33 ) )
F_16 = NULL ;
return F_16 != NULL ;
}
static void F_29 ( struct V_1 * V_2 , struct V_26 * V_27 , T_4 V_45 )
{
struct V_20 * V_21 = F_2 ( V_2 ) ;
const int type = F_15 ( V_27 ) -> type ;
const int V_46 = F_15 ( V_27 ) -> V_46 ;
int V_47 = 0 ;
int V_48 = 0 ;
if ( ! V_21 -> V_49 && V_2 -> V_50 != V_51 )
return;
switch ( type ) {
default:
case V_52 :
V_47 = V_53 ;
break;
case V_54 :
return;
case V_55 :
V_47 = V_56 ;
V_48 = 1 ;
break;
case V_57 :
V_47 = V_53 ;
if ( V_46 > V_58 )
break;
V_47 = V_59 [ V_46 ] . V_60 ;
V_48 = V_59 [ V_46 ] . V_61 ;
if ( V_46 == V_62 ) {
V_48 = V_21 -> V_63 != V_64 ;
V_47 = V_65 ;
}
}
if ( V_21 -> V_49 ) {
const struct V_31 * V_32 = ( const struct V_31 * ) V_27 -> V_29 ;
T_5 * V_66 = V_27 -> V_29 + ( V_32 -> V_67 << 2 ) ;
if ( V_21 -> V_68 )
V_66 = V_27 -> V_29 ;
F_30 ( V_2 , V_27 , V_47 , 0 , V_45 , V_66 ) ;
}
if ( V_21 -> V_49 || V_48 ) {
V_2 -> V_69 = V_47 ;
V_2 -> V_70 ( V_2 ) ;
}
}
void F_31 ( struct V_26 * V_27 , int V_38 , T_4 V_45 )
{
int V_33 ;
struct V_1 * F_16 ;
const struct V_31 * V_32 ;
struct V_13 * V_13 ;
V_33 = V_38 & ( V_11 - 1 ) ;
F_18 ( & V_35 . V_12 ) ;
F_16 = F_27 ( & V_35 . V_9 [ V_33 ] ) ;
if ( F_16 != NULL ) {
V_32 = ( const struct V_31 * ) V_27 -> V_29 ;
V_13 = F_20 ( V_27 -> V_37 ) ;
while ( ( F_16 = F_10 ( V_13 , F_16 , V_38 ,
V_32 -> V_40 , V_32 -> V_39 ,
V_27 -> V_37 -> V_41 ) ) != NULL ) {
F_29 ( F_16 , V_27 , V_45 ) ;
F_16 = F_24 ( F_16 ) ;
V_32 = ( const struct V_31 * ) V_27 -> V_29 ;
}
}
F_25 ( & V_35 . V_12 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
F_33 ( V_27 ) ;
if ( F_34 ( V_2 , V_27 ) < 0 ) {
F_35 ( V_27 ) ;
return V_71 ;
}
return V_72 ;
}
int F_23 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
if ( ! F_36 ( V_2 , V_73 , V_27 ) ) {
F_37 ( & V_2 -> V_74 ) ;
F_35 ( V_27 ) ;
return V_71 ;
}
F_38 ( V_27 ) ;
F_39 ( V_27 , V_27 -> V_29 - F_40 ( V_27 ) ) ;
F_32 ( V_2 , V_27 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_75 * V_76 ,
void * V_77 , T_6 V_78 ,
struct V_79 * * V_80 ,
unsigned int V_81 )
{
struct V_20 * V_21 = F_2 ( V_2 ) ;
struct V_13 * V_13 = F_6 ( V_2 ) ;
struct V_31 * V_32 ;
struct V_26 * V_27 ;
unsigned int V_82 ;
int V_47 ;
struct V_79 * V_83 = * V_80 ;
int V_84 , V_85 ;
if ( V_78 > V_83 -> V_86 . V_37 -> V_87 ) {
F_42 ( V_2 , V_65 , V_76 -> V_40 , V_21 -> V_88 ,
V_83 -> V_86 . V_37 -> V_87 ) ;
return - V_65 ;
}
if ( V_81 & V_89 )
goto V_36;
V_84 = F_43 ( V_83 -> V_86 . V_37 ) ;
V_85 = V_83 -> V_86 . V_37 -> V_90 ;
V_27 = F_44 ( V_2 ,
V_78 + V_84 + V_85 + 15 ,
V_81 & V_91 , & V_47 ) ;
if ( V_27 == NULL )
goto error;
F_45 ( V_27 , V_84 ) ;
V_27 -> V_92 = V_2 -> V_93 ;
V_27 -> V_94 = V_2 -> V_95 ;
F_46 ( V_27 , & V_83 -> V_86 ) ;
* V_80 = NULL ;
F_47 ( V_27 ) ;
V_32 = F_28 ( V_27 ) ;
F_48 ( V_27 , V_78 ) ;
V_27 -> V_96 = V_97 ;
V_27 -> V_98 = V_27 -> V_99 ;
V_47 = - V_100 ;
if ( F_49 ( ( void * ) V_32 , V_77 , 0 , V_78 ) )
goto V_101;
V_82 = V_32 -> V_67 * 4 ;
V_47 = - V_102 ;
if ( V_82 > V_78 )
goto V_101;
if ( V_82 >= sizeof( * V_32 ) ) {
if ( ! V_32 -> V_39 )
V_32 -> V_39 = V_76 -> V_39 ;
V_32 -> V_103 = 0 ;
V_32 -> V_104 = F_50 ( V_78 ) ;
if ( ! V_32 -> V_105 )
F_51 ( V_32 , & V_83 -> V_86 , NULL ) ;
V_32 -> V_103 = F_52 ( ( unsigned char * ) V_32 , V_32 -> V_67 ) ;
}
if ( V_32 -> V_38 == V_42 )
F_53 ( V_13 , ( (struct V_28 * )
F_54 ( V_27 ) ) -> type ) ;
V_47 = F_55 ( V_106 , V_107 , V_27 , NULL ,
V_83 -> V_86 . V_37 , V_108 ) ;
if ( V_47 > 0 )
V_47 = F_56 ( V_47 ) ;
if ( V_47 )
goto error;
V_36:
return 0 ;
V_101:
F_35 ( V_27 ) ;
error:
F_57 ( V_13 , V_109 ) ;
if ( V_47 == - V_110 && ! V_21 -> V_49 )
V_47 = 0 ;
return V_47 ;
}
static int F_58 ( struct V_75 * V_76 , struct V_111 * V_112 )
{
struct V_113 * V_114 ;
T_5 T_7 * type = NULL ;
T_5 T_7 * V_46 = NULL ;
int V_115 = 0 ;
unsigned int V_116 ;
if ( ! V_112 -> V_117 )
return 0 ;
for ( V_116 = 0 ; V_116 < V_112 -> V_118 ; V_116 ++ ) {
V_114 = & V_112 -> V_117 [ V_116 ] ;
if ( ! V_114 )
continue;
switch ( V_76 -> V_119 ) {
case V_42 :
if ( V_114 -> V_120 && V_114 -> V_121 < 1 )
break;
if ( ! type ) {
type = V_114 -> V_120 ;
if ( V_114 -> V_121 > 1 )
V_46 = type + 1 ;
} else if ( ! V_46 )
V_46 = V_114 -> V_120 ;
if ( type && V_46 ) {
if ( F_59 ( V_76 -> V_122 , type ) ||
F_59 ( V_76 -> V_123 , V_46 ) )
return - V_100 ;
V_115 = 1 ;
}
break;
default:
V_115 = 1 ;
break;
}
if ( V_115 )
break;
}
return 0 ;
}
static int F_60 ( struct V_124 * V_125 , struct V_1 * V_2 , struct V_111 * V_112 ,
T_6 V_126 )
{
struct V_20 * V_21 = F_2 ( V_2 ) ;
struct V_127 V_128 ;
struct V_79 * V_83 = NULL ;
struct V_75 V_76 ;
int free = 0 ;
T_1 V_40 ;
T_1 V_39 ;
T_5 V_129 ;
int V_47 ;
struct V_130 V_131 ;
V_47 = - V_65 ;
if ( V_126 > 0xFFFF )
goto V_36;
V_47 = - V_132 ;
if ( V_112 -> V_133 & V_134 )
goto V_36;
if ( V_112 -> V_135 ) {
struct V_136 * V_137 = (struct V_136 * ) V_112 -> V_138 ;
V_47 = - V_102 ;
if ( V_112 -> V_135 < sizeof( * V_137 ) )
goto V_36;
if ( V_137 -> V_139 != V_140 ) {
F_61 ( L_1 ,
V_141 , V_142 -> V_143 ) ;
V_47 = - V_144 ;
if ( V_137 -> V_139 )
goto V_36;
}
V_40 = V_137 -> V_145 . V_146 ;
} else {
V_47 = - V_147 ;
if ( V_2 -> V_50 != V_51 )
goto V_36;
V_40 = V_21 -> V_22 ;
}
V_128 . V_148 = V_21 -> V_149 ;
V_128 . V_150 = NULL ;
V_128 . V_151 = 0 ;
V_128 . V_152 = V_2 -> V_24 ;
if ( V_112 -> V_153 ) {
V_47 = F_62 ( F_6 ( V_2 ) , V_112 , & V_128 ) ;
if ( V_47 )
goto V_36;
if ( V_128 . V_150 )
free = 1 ;
}
V_39 = V_128 . V_148 ;
V_128 . V_148 = V_40 ;
if ( ! V_128 . V_150 ) {
struct V_154 * V_155 ;
F_63 () ;
V_155 = F_64 ( V_21 -> V_155 ) ;
if ( V_155 ) {
memcpy ( & V_131 , V_155 ,
sizeof( * V_155 ) + V_155 -> V_150 . V_156 ) ;
V_128 . V_150 = & V_131 . V_150 ;
}
F_65 () ;
}
if ( V_128 . V_150 ) {
V_47 = - V_102 ;
if ( V_21 -> V_68 )
goto V_157;
if ( V_128 . V_150 -> V_150 . V_158 ) {
if ( ! V_40 )
goto V_157;
V_40 = V_128 . V_150 -> V_150 . V_159 ;
}
}
V_129 = F_66 ( V_2 ) ;
if ( V_112 -> V_133 & V_160 )
V_129 |= V_161 ;
if ( F_67 ( V_40 ) ) {
if ( ! V_128 . V_152 )
V_128 . V_152 = V_21 -> V_162 ;
if ( ! V_39 )
V_39 = V_21 -> V_163 ;
} else if ( ! V_128 . V_152 )
V_128 . V_152 = V_21 -> V_164 ;
F_68 ( & V_76 , V_128 . V_152 , V_2 -> V_95 , V_129 ,
V_165 ,
V_21 -> V_68 ? V_166 : V_2 -> V_167 ,
F_69 ( V_2 ) | V_168 ,
V_40 , V_39 , 0 , 0 ) ;
if ( ! V_21 -> V_68 ) {
V_47 = F_58 ( & V_76 , V_112 ) ;
if ( V_47 )
goto V_157;
}
F_70 ( V_2 , F_71 ( & V_76 ) ) ;
V_83 = F_72 ( F_6 ( V_2 ) , & V_76 , V_2 ) ;
if ( F_73 ( V_83 ) ) {
V_47 = F_74 ( V_83 ) ;
V_83 = NULL ;
goto V_157;
}
V_47 = - V_169 ;
if ( V_83 -> V_170 & V_171 && ! F_75 ( V_2 , V_172 ) )
goto V_157;
if ( V_112 -> V_133 & V_173 )
goto V_174;
V_175:
if ( V_21 -> V_68 )
V_47 = F_41 ( V_2 , & V_76 , V_112 -> V_117 , V_126 ,
& V_83 , V_112 -> V_133 ) ;
else {
if ( ! V_128 . V_148 )
V_128 . V_148 = V_76 . V_40 ;
F_76 ( V_2 ) ;
V_47 = F_77 ( V_2 , & V_76 , V_176 ,
V_112 -> V_117 , V_126 , 0 ,
& V_128 , & V_83 , V_112 -> V_133 ) ;
if ( V_47 )
F_78 ( V_2 ) ;
else if ( ! ( V_112 -> V_133 & V_177 ) ) {
V_47 = F_79 ( V_2 , & V_76 ) ;
if ( V_47 == - V_110 && ! V_21 -> V_49 )
V_47 = 0 ;
}
F_80 ( V_2 ) ;
}
V_157:
if ( free )
F_81 ( V_128 . V_150 ) ;
F_82 ( V_83 ) ;
V_36:
if ( V_47 < 0 )
return V_47 ;
return V_126 ;
V_174:
F_83 ( & V_83 -> V_86 ) ;
if ( ! ( V_112 -> V_133 & V_89 ) || V_126 )
goto V_175;
V_47 = 0 ;
goto V_157;
}
static void F_84 ( struct V_1 * V_2 , long V_178 )
{
F_85 ( V_2 , 0 , NULL ) ;
F_86 ( V_2 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_76 ( V_2 ) ;
F_78 ( V_2 ) ;
F_80 ( V_2 ) ;
}
static int F_88 ( struct V_1 * V_2 , struct V_179 * V_180 , int V_181 )
{
struct V_20 * V_21 = F_2 ( V_2 ) ;
struct V_136 * V_148 = (struct V_136 * ) V_180 ;
int V_182 = - V_102 ;
int V_183 ;
if ( V_2 -> V_50 != V_184 || V_181 < sizeof( struct V_136 ) )
goto V_36;
V_183 = F_89 ( F_6 ( V_2 ) , V_148 -> V_145 . V_146 ) ;
V_182 = - V_185 ;
if ( V_148 -> V_145 . V_146 && V_183 != V_186 &&
V_183 != V_187 && V_183 != V_188 )
goto V_36;
V_21 -> V_23 = V_21 -> V_149 = V_148 -> V_145 . V_146 ;
if ( V_183 == V_187 || V_183 == V_188 )
V_21 -> V_149 = 0 ;
F_90 ( V_2 ) ;
V_182 = 0 ;
V_36: return V_182 ;
}
static int F_91 ( struct V_124 * V_125 , struct V_1 * V_2 , struct V_111 * V_112 ,
T_6 V_126 , int V_189 , int V_81 , int * V_181 )
{
struct V_20 * V_21 = F_2 ( V_2 ) ;
T_6 V_190 = 0 ;
int V_47 = - V_132 ;
struct V_136 * sin = (struct V_136 * ) V_112 -> V_138 ;
struct V_26 * V_27 ;
if ( V_81 & V_134 )
goto V_36;
if ( V_181 )
* V_181 = sizeof( * sin ) ;
if ( V_81 & V_191 ) {
V_47 = F_92 ( V_2 , V_112 , V_126 ) ;
goto V_36;
}
V_27 = F_93 ( V_2 , V_81 , V_189 , & V_47 ) ;
if ( ! V_27 )
goto V_36;
V_190 = V_27 -> V_126 ;
if ( V_126 < V_190 ) {
V_112 -> V_133 |= V_192 ;
V_190 = V_126 ;
}
V_47 = F_94 ( V_27 , 0 , V_112 -> V_117 , V_190 ) ;
if ( V_47 )
goto V_157;
F_95 ( V_112 , V_2 , V_27 ) ;
if ( sin ) {
sin -> V_139 = V_140 ;
sin -> V_145 . V_146 = F_28 ( V_27 ) -> V_39 ;
sin -> V_193 = 0 ;
memset ( & sin -> V_194 , 0 , sizeof( sin -> V_194 ) ) ;
}
if ( V_21 -> V_195 )
F_96 ( V_112 , V_27 ) ;
if ( V_81 & V_192 )
V_190 = V_27 -> V_126 ;
V_157:
F_97 ( V_2 , V_27 ) ;
V_36:
if ( V_47 )
return V_47 ;
return V_190 ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_196 * V_197 = F_16 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_10 == V_42 )
memset ( & V_197 -> V_30 , 0 , sizeof( V_197 -> V_30 ) ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 , char T_7 * V_198 , int V_156 )
{
if ( V_156 > sizeof( struct F_13 ) )
V_156 = sizeof( struct F_13 ) ;
if ( F_100 ( & F_16 ( V_2 ) -> V_30 , V_198 , V_156 ) )
return - V_100 ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 , char T_7 * V_198 , int T_7 * V_156 )
{
int V_126 , V_182 = - V_100 ;
if ( F_59 ( V_126 , V_156 ) )
goto V_36;
V_182 = - V_102 ;
if ( V_126 < 0 )
goto V_36;
if ( V_126 > sizeof( struct F_13 ) )
V_126 = sizeof( struct F_13 ) ;
V_182 = - V_100 ;
if ( F_102 ( V_126 , V_156 ) ||
F_103 ( V_198 , & F_16 ( V_2 ) -> V_30 , V_126 ) )
goto V_36;
V_182 = 0 ;
V_36: return V_182 ;
}
static int F_104 ( struct V_1 * V_2 , int V_199 , int V_200 ,
char T_7 * V_198 , unsigned int V_156 )
{
if ( V_200 == V_201 ) {
if ( F_2 ( V_2 ) -> V_10 != V_42 )
return - V_132 ;
else
return F_99 ( V_2 , V_198 , V_156 ) ;
}
return - V_202 ;
}
static int F_105 ( struct V_1 * V_2 , int V_199 , int V_200 ,
char T_7 * V_198 , unsigned int V_156 )
{
if ( V_199 != V_203 )
return F_106 ( V_2 , V_199 , V_200 , V_198 , V_156 ) ;
return F_104 ( V_2 , V_199 , V_200 , V_198 , V_156 ) ;
}
static int F_107 ( struct V_1 * V_2 , int V_199 , int V_200 ,
char T_7 * V_198 , unsigned int V_156 )
{
if ( V_199 != V_203 )
return F_108 ( V_2 , V_199 , V_200 , V_198 , V_156 ) ;
return F_104 ( V_2 , V_199 , V_200 , V_198 , V_156 ) ;
}
static int F_109 ( struct V_1 * V_2 , int V_199 , int V_200 ,
char T_7 * V_198 , int T_7 * V_156 )
{
if ( V_200 == V_201 ) {
if ( F_2 ( V_2 ) -> V_10 != V_42 )
return - V_132 ;
else
return F_101 ( V_2 , V_198 , V_156 ) ;
}
return - V_202 ;
}
static int F_110 ( struct V_1 * V_2 , int V_199 , int V_200 ,
char T_7 * V_198 , int T_7 * V_156 )
{
if ( V_199 != V_203 )
return F_111 ( V_2 , V_199 , V_200 , V_198 , V_156 ) ;
return F_109 ( V_2 , V_199 , V_200 , V_198 , V_156 ) ;
}
static int F_112 ( struct V_1 * V_2 , int V_199 , int V_200 ,
char T_7 * V_198 , int T_7 * V_156 )
{
if ( V_199 != V_203 )
return F_113 ( V_2 , V_199 , V_200 , V_198 , V_156 ) ;
return F_109 ( V_2 , V_199 , V_200 , V_198 , V_156 ) ;
}
static int F_114 ( struct V_1 * V_2 , int V_204 , unsigned long V_205 )
{
switch ( V_204 ) {
case V_206 : {
int V_207 = F_115 ( V_2 ) ;
return F_102 ( V_207 , ( int T_7 * ) V_205 ) ;
}
case V_208 : {
struct V_26 * V_27 ;
int V_207 = 0 ;
F_116 ( & V_2 -> V_209 . V_12 ) ;
V_27 = F_117 ( & V_2 -> V_209 ) ;
if ( V_27 != NULL )
V_207 = V_27 -> V_126 ;
F_118 ( & V_2 -> V_209 . V_12 ) ;
return F_102 ( V_207 , ( int T_7 * ) V_205 ) ;
}
default:
#ifdef F_119
return F_120 ( V_2 , V_204 , ( void T_7 * ) V_205 ) ;
#else
return - V_210 ;
#endif
}
}
static int F_121 ( struct V_1 * V_2 , unsigned int V_204 , unsigned long V_205 )
{
switch ( V_204 ) {
case V_206 :
case V_208 :
return - V_210 ;
default:
#ifdef F_119
return F_122 ( V_2 , V_204 , F_123 ( V_205 ) ) ;
#else
return - V_210 ;
#endif
}
}
static struct V_1 * F_124 ( struct V_211 * V_212 )
{
struct V_1 * V_2 ;
struct V_213 * V_214 = F_125 ( V_212 ) ;
for ( V_214 -> V_215 = 0 ; V_214 -> V_215 < V_11 ;
++ V_214 -> V_215 ) {
struct V_18 * V_19 ;
F_126 (sk, node, &state->h->ht[state->bucket])
if ( F_6 ( V_2 ) == F_127 ( V_212 ) )
goto V_25;
}
V_2 = NULL ;
V_25:
return V_2 ;
}
static struct V_1 * F_128 ( struct V_211 * V_212 , struct V_1 * V_2 )
{
struct V_213 * V_214 = F_125 ( V_212 ) ;
do {
V_2 = F_24 ( V_2 ) ;
V_216:
;
} while ( V_2 && F_6 ( V_2 ) != F_127 ( V_212 ) );
if ( ! V_2 && ++ V_214 -> V_215 < V_11 ) {
V_2 = F_27 ( & V_214 -> V_4 -> V_9 [ V_214 -> V_215 ] ) ;
goto V_216;
}
return V_2 ;
}
static struct V_1 * F_129 ( struct V_211 * V_212 , T_8 V_217 )
{
struct V_1 * V_2 = F_124 ( V_212 ) ;
if ( V_2 )
while ( V_217 && ( V_2 = F_128 ( V_212 , V_2 ) ) != NULL )
-- V_217 ;
return V_217 ? NULL : V_2 ;
}
void * F_130 ( struct V_211 * V_212 , T_8 * V_217 )
{
struct V_213 * V_214 = F_125 ( V_212 ) ;
F_18 ( & V_214 -> V_4 -> V_12 ) ;
return * V_217 ? F_129 ( V_212 , * V_217 - 1 ) : V_218 ;
}
void * F_131 ( struct V_211 * V_212 , void * V_219 , T_8 * V_217 )
{
struct V_1 * V_2 ;
if ( V_219 == V_218 )
V_2 = F_124 ( V_212 ) ;
else
V_2 = F_128 ( V_212 , V_219 ) ;
++ * V_217 ;
return V_2 ;
}
void F_132 ( struct V_211 * V_212 , void * V_219 )
{
struct V_213 * V_214 = F_125 ( V_212 ) ;
F_25 ( & V_214 -> V_4 -> V_12 ) ;
}
static void F_133 ( struct V_211 * V_212 , struct V_1 * V_220 , int V_116 )
{
struct V_20 * V_21 = F_2 ( V_220 ) ;
T_1 V_221 = V_21 -> V_22 ,
V_222 = V_21 -> V_23 ;
T_9 V_223 = 0 ,
V_224 = V_21 -> V_10 ;
F_134 ( V_212 , L_2
L_3 ,
V_116 , V_222 , V_224 , V_221 , V_223 , V_220 -> V_50 ,
F_115 ( V_220 ) ,
F_135 ( V_220 ) ,
0 , 0L , 0 , F_136 ( V_220 ) , 0 , F_137 ( V_220 ) ,
F_138 ( & V_220 -> V_225 ) , V_220 , F_138 ( & V_220 -> V_74 ) ) ;
}
static int F_139 ( struct V_211 * V_212 , void * V_219 )
{
if ( V_219 == V_218 )
F_134 ( V_212 , L_4
L_5
L_6 ) ;
else
F_133 ( V_212 , V_219 , F_125 ( V_212 ) -> V_215 ) ;
return 0 ;
}
int F_140 ( struct V_226 * V_227 , struct V_228 * V_228 ,
struct V_3 * V_4 , const struct V_229 * V_230 )
{
int V_47 ;
struct V_213 * V_116 ;
V_47 = F_141 ( V_227 , V_228 , V_230 , sizeof( struct V_213 ) ) ;
if ( V_47 < 0 )
return V_47 ;
V_116 = F_125 ( (struct V_211 * ) V_228 -> V_231 ) ;
V_116 -> V_4 = V_4 ;
return 0 ;
}
static int F_142 ( struct V_226 * V_226 , struct V_228 * V_228 )
{
return F_140 ( V_226 , V_228 , & V_35 , & V_232 ) ;
}
static T_10 int F_143 ( struct V_13 * V_13 )
{
if ( ! F_144 ( V_13 , L_7 , V_233 , & V_234 ) )
return - V_235 ;
return 0 ;
}
static T_11 void F_145 ( struct V_13 * V_13 )
{
F_146 ( V_13 , L_7 ) ;
}
int T_12 F_147 ( void )
{
return F_148 ( & V_236 ) ;
}
void T_12 F_149 ( void )
{
F_150 ( & V_236 ) ;
}
