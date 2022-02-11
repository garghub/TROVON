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
static int F_13 ( const struct V_1 * V_2 , const struct V_26 * V_27 )
{
struct V_28 V_29 ;
const struct V_28 * V_30 ;
V_30 = F_14 ( V_27 , F_15 ( V_27 ) ,
sizeof( V_29 ) , & V_29 ) ;
if ( ! V_30 )
return 1 ;
if ( V_30 -> type < 32 ) {
T_2 V_31 = F_16 ( V_2 ) -> V_32 . V_31 ;
return ( ( 1U << V_30 -> type ) & V_31 ) != 0 ;
}
return 0 ;
}
static int F_17 ( struct V_26 * V_27 , const struct V_33 * V_34 , int V_35 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_36 = 0 ;
struct V_13 * V_13 ;
F_18 ( & V_37 . V_12 ) ;
V_8 = & V_37 . V_9 [ V_35 ] ;
if ( F_19 ( V_8 ) )
goto V_38;
V_13 = F_20 ( V_27 -> V_39 ) ;
V_2 = F_10 ( V_13 , F_21 ( V_8 ) , V_34 -> V_40 ,
V_34 -> V_41 , V_34 -> V_42 ,
V_27 -> V_39 -> V_43 ) ;
while ( V_2 ) {
V_36 = 1 ;
if ( V_34 -> V_40 != V_44 || ! F_13 ( V_2 , V_27 ) ) {
struct V_26 * V_45 = F_22 ( V_27 , V_46 ) ;
if ( V_45 )
F_23 ( V_2 , V_45 ) ;
}
V_2 = F_10 ( V_13 , F_24 ( V_2 ) , V_34 -> V_40 ,
V_34 -> V_41 , V_34 -> V_42 ,
V_27 -> V_39 -> V_43 ) ;
}
V_38:
F_25 ( & V_37 . V_12 ) ;
return V_36 ;
}
int F_26 ( struct V_26 * V_27 , int V_40 )
{
int V_35 ;
struct V_1 * F_16 ;
V_35 = V_40 & ( V_11 - 1 ) ;
F_16 = F_27 ( & V_37 . V_9 [ V_35 ] ) ;
if ( F_16 && ! F_17 ( V_27 , F_28 ( V_27 ) , V_35 ) )
F_16 = NULL ;
return F_16 != NULL ;
}
static void F_29 ( struct V_1 * V_2 , struct V_26 * V_27 , T_3 V_47 )
{
struct V_20 * V_21 = F_2 ( V_2 ) ;
const int type = F_30 ( V_27 ) -> type ;
const int V_48 = F_30 ( V_27 ) -> V_48 ;
int V_49 = 0 ;
int V_50 = 0 ;
if ( type == V_51 && V_48 == V_52 )
F_31 ( V_27 , V_2 , V_47 ) ;
else if ( type == V_53 )
F_32 ( V_27 , V_2 ) ;
if ( ! V_21 -> V_54 && V_2 -> V_55 != V_56 )
return;
switch ( type ) {
default:
case V_57 :
V_49 = V_58 ;
break;
case V_59 :
return;
case V_60 :
V_49 = V_61 ;
V_50 = 1 ;
break;
case V_51 :
V_49 = V_58 ;
if ( V_48 > V_62 )
break;
V_49 = V_63 [ V_48 ] . V_64 ;
V_50 = V_63 [ V_48 ] . V_65 ;
if ( V_48 == V_52 ) {
V_50 = V_21 -> V_66 != V_67 ;
V_49 = V_68 ;
}
}
if ( V_21 -> V_54 ) {
const struct V_33 * V_34 = ( const struct V_33 * ) V_27 -> V_31 ;
T_4 * V_69 = V_27 -> V_31 + ( V_34 -> V_70 << 2 ) ;
if ( V_21 -> V_71 )
V_69 = V_27 -> V_31 ;
F_33 ( V_2 , V_27 , V_49 , 0 , V_47 , V_69 ) ;
}
if ( V_21 -> V_54 || V_50 ) {
V_2 -> V_72 = V_49 ;
V_2 -> V_73 ( V_2 ) ;
}
}
void F_34 ( struct V_26 * V_27 , int V_40 , T_3 V_47 )
{
int V_35 ;
struct V_1 * F_16 ;
const struct V_33 * V_34 ;
struct V_13 * V_13 ;
V_35 = V_40 & ( V_11 - 1 ) ;
F_18 ( & V_37 . V_12 ) ;
F_16 = F_27 ( & V_37 . V_9 [ V_35 ] ) ;
if ( F_16 != NULL ) {
V_34 = ( const struct V_33 * ) V_27 -> V_31 ;
V_13 = F_20 ( V_27 -> V_39 ) ;
while ( ( F_16 = F_10 ( V_13 , F_16 , V_40 ,
V_34 -> V_42 , V_34 -> V_41 ,
V_27 -> V_39 -> V_43 ) ) != NULL ) {
F_29 ( F_16 , V_27 , V_47 ) ;
F_16 = F_24 ( F_16 ) ;
V_34 = ( const struct V_33 * ) V_27 -> V_31 ;
}
}
F_25 ( & V_37 . V_12 ) ;
}
static int F_35 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
F_36 ( V_27 ) ;
if ( F_37 ( V_2 , V_27 ) < 0 ) {
F_38 ( V_27 ) ;
return V_74 ;
}
return V_75 ;
}
int F_23 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
if ( ! F_39 ( V_2 , V_76 , V_27 ) ) {
F_40 ( & V_2 -> V_77 ) ;
F_38 ( V_27 ) ;
return V_74 ;
}
F_41 ( V_27 ) ;
F_42 ( V_27 , V_27 -> V_31 - F_43 ( V_27 ) ) ;
F_35 ( V_2 , V_27 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_78 * V_79 ,
void * V_80 , T_5 V_81 ,
struct V_82 * * V_83 ,
unsigned int V_84 )
{
struct V_20 * V_21 = F_2 ( V_2 ) ;
struct V_13 * V_13 = F_6 ( V_2 ) ;
struct V_33 * V_34 ;
struct V_26 * V_27 ;
unsigned int V_85 ;
int V_49 ;
struct V_82 * V_86 = * V_83 ;
int V_87 , V_88 ;
if ( V_81 > V_86 -> V_89 . V_39 -> V_90 ) {
F_45 ( V_2 , V_68 , V_79 -> V_42 , V_21 -> V_91 ,
V_86 -> V_89 . V_39 -> V_90 ) ;
return - V_68 ;
}
if ( V_84 & V_92 )
goto V_38;
V_87 = F_46 ( V_86 -> V_89 . V_39 ) ;
V_88 = V_86 -> V_89 . V_39 -> V_93 ;
V_27 = F_47 ( V_2 ,
V_81 + V_87 + V_88 + 15 ,
V_84 & V_94 , & V_49 ) ;
if ( V_27 == NULL )
goto error;
F_48 ( V_27 , V_87 ) ;
V_27 -> V_95 = V_2 -> V_96 ;
V_27 -> V_97 = V_2 -> V_98 ;
F_49 ( V_27 , & V_86 -> V_89 ) ;
* V_83 = NULL ;
F_50 ( V_27 ) ;
V_34 = F_28 ( V_27 ) ;
F_51 ( V_27 , V_81 ) ;
V_27 -> V_99 = V_100 ;
V_27 -> V_101 = V_27 -> V_102 ;
V_49 = - V_103 ;
if ( F_52 ( ( void * ) V_34 , V_80 , 0 , V_81 ) )
goto V_104;
V_85 = V_34 -> V_70 * 4 ;
V_49 = - V_105 ;
if ( V_85 > V_81 )
goto V_104;
if ( V_85 >= sizeof( * V_34 ) ) {
if ( ! V_34 -> V_41 )
V_34 -> V_41 = V_79 -> V_41 ;
V_34 -> V_106 = 0 ;
V_34 -> V_107 = F_53 ( V_81 ) ;
if ( ! V_34 -> V_108 )
F_54 ( V_34 , & V_86 -> V_89 , NULL ) ;
V_34 -> V_106 = F_55 ( ( unsigned char * ) V_34 , V_34 -> V_70 ) ;
}
if ( V_34 -> V_40 == V_44 )
F_56 ( V_13 , ( (struct V_28 * )
F_57 ( V_27 ) ) -> type ) ;
V_49 = F_58 ( V_109 , V_110 , V_27 , NULL ,
V_86 -> V_89 . V_39 , V_111 ) ;
if ( V_49 > 0 )
V_49 = F_59 ( V_49 ) ;
if ( V_49 )
goto error;
V_38:
return 0 ;
V_104:
F_38 ( V_27 ) ;
error:
F_60 ( V_13 , V_112 ) ;
if ( V_49 == - V_113 && ! V_21 -> V_54 )
V_49 = 0 ;
return V_49 ;
}
static int F_61 ( struct V_78 * V_79 , struct V_114 * V_115 )
{
struct V_116 * V_117 ;
T_4 T_6 * type = NULL ;
T_4 T_6 * V_48 = NULL ;
int V_118 = 0 ;
unsigned int V_119 ;
if ( ! V_115 -> V_120 )
return 0 ;
for ( V_119 = 0 ; V_119 < V_115 -> V_121 ; V_119 ++ ) {
V_117 = & V_115 -> V_120 [ V_119 ] ;
if ( ! V_117 )
continue;
switch ( V_79 -> V_122 ) {
case V_44 :
if ( V_117 -> V_123 && V_117 -> V_124 < 1 )
break;
if ( ! type ) {
type = V_117 -> V_123 ;
if ( V_117 -> V_124 > 1 )
V_48 = type + 1 ;
} else if ( ! V_48 )
V_48 = V_117 -> V_123 ;
if ( type && V_48 ) {
if ( F_62 ( V_79 -> V_125 , type ) ||
F_62 ( V_79 -> V_126 , V_48 ) )
return - V_103 ;
V_118 = 1 ;
}
break;
default:
V_118 = 1 ;
break;
}
if ( V_118 )
break;
}
return 0 ;
}
static int F_63 ( struct V_127 * V_128 , struct V_1 * V_2 , struct V_114 * V_115 ,
T_5 V_129 )
{
struct V_20 * V_21 = F_2 ( V_2 ) ;
struct V_130 V_131 ;
struct V_82 * V_86 = NULL ;
struct V_78 V_79 ;
int free = 0 ;
T_1 V_42 ;
T_1 V_41 ;
T_4 V_132 ;
int V_49 ;
struct V_133 V_134 ;
V_49 = - V_68 ;
if ( V_129 > 0xFFFF )
goto V_38;
V_49 = - V_135 ;
if ( V_115 -> V_136 & V_137 )
goto V_38;
if ( V_115 -> V_138 ) {
struct V_139 * V_140 = (struct V_139 * ) V_115 -> V_141 ;
V_49 = - V_105 ;
if ( V_115 -> V_138 < sizeof( * V_140 ) )
goto V_38;
if ( V_140 -> V_142 != V_143 ) {
F_64 ( L_1 ,
V_144 , V_145 -> V_146 ) ;
V_49 = - V_147 ;
if ( V_140 -> V_142 )
goto V_38;
}
V_42 = V_140 -> V_148 . V_149 ;
} else {
V_49 = - V_150 ;
if ( V_2 -> V_55 != V_56 )
goto V_38;
V_42 = V_21 -> V_22 ;
}
V_131 . V_151 = V_21 -> V_152 ;
V_131 . V_153 = NULL ;
V_131 . V_154 = 0 ;
V_131 . V_155 = V_2 -> V_24 ;
if ( V_115 -> V_156 ) {
V_49 = F_65 ( F_6 ( V_2 ) , V_115 , & V_131 ) ;
if ( V_49 )
goto V_38;
if ( V_131 . V_153 )
free = 1 ;
}
V_41 = V_131 . V_151 ;
V_131 . V_151 = V_42 ;
if ( ! V_131 . V_153 ) {
struct V_157 * V_158 ;
F_66 () ;
V_158 = F_67 ( V_21 -> V_158 ) ;
if ( V_158 ) {
memcpy ( & V_134 , V_158 ,
sizeof( * V_158 ) + V_158 -> V_153 . V_159 ) ;
V_131 . V_153 = & V_134 . V_153 ;
}
F_68 () ;
}
if ( V_131 . V_153 ) {
V_49 = - V_105 ;
if ( V_21 -> V_71 )
goto V_160;
if ( V_131 . V_153 -> V_153 . V_161 ) {
if ( ! V_42 )
goto V_160;
V_42 = V_131 . V_153 -> V_153 . V_162 ;
}
}
V_132 = F_69 ( V_2 ) ;
if ( V_115 -> V_136 & V_163 )
V_132 |= V_164 ;
if ( F_70 ( V_42 ) ) {
if ( ! V_131 . V_155 )
V_131 . V_155 = V_21 -> V_165 ;
if ( ! V_41 )
V_41 = V_21 -> V_166 ;
} else if ( ! V_131 . V_155 )
V_131 . V_155 = V_21 -> V_167 ;
F_71 ( & V_79 , V_131 . V_155 , V_2 -> V_98 , V_132 ,
V_168 ,
V_21 -> V_71 ? V_169 : V_2 -> V_170 ,
F_72 ( V_2 ) | V_171 ,
V_42 , V_41 , 0 , 0 ) ;
if ( ! V_21 -> V_71 ) {
V_49 = F_61 ( & V_79 , V_115 ) ;
if ( V_49 )
goto V_160;
}
F_73 ( V_2 , F_74 ( & V_79 ) ) ;
V_86 = F_75 ( F_6 ( V_2 ) , & V_79 , V_2 ) ;
if ( F_76 ( V_86 ) ) {
V_49 = F_77 ( V_86 ) ;
V_86 = NULL ;
goto V_160;
}
V_49 = - V_172 ;
if ( V_86 -> V_173 & V_174 && ! F_78 ( V_2 , V_175 ) )
goto V_160;
if ( V_115 -> V_136 & V_176 )
goto V_177;
V_178:
if ( V_21 -> V_71 )
V_49 = F_44 ( V_2 , & V_79 , V_115 -> V_120 , V_129 ,
& V_86 , V_115 -> V_136 ) ;
else {
if ( ! V_131 . V_151 )
V_131 . V_151 = V_79 . V_42 ;
F_79 ( V_2 ) ;
V_49 = F_80 ( V_2 , & V_79 , V_179 ,
V_115 -> V_120 , V_129 , 0 ,
& V_131 , & V_86 , V_115 -> V_136 ) ;
if ( V_49 )
F_81 ( V_2 ) ;
else if ( ! ( V_115 -> V_136 & V_180 ) ) {
V_49 = F_82 ( V_2 , & V_79 ) ;
if ( V_49 == - V_113 && ! V_21 -> V_54 )
V_49 = 0 ;
}
F_83 ( V_2 ) ;
}
V_160:
if ( free )
F_84 ( V_131 . V_153 ) ;
F_85 ( V_86 ) ;
V_38:
if ( V_49 < 0 )
return V_49 ;
return V_129 ;
V_177:
F_86 ( & V_86 -> V_89 ) ;
if ( ! ( V_115 -> V_136 & V_92 ) || V_129 )
goto V_178;
V_49 = 0 ;
goto V_160;
}
static void F_87 ( struct V_1 * V_2 , long V_181 )
{
F_88 ( V_2 , 0 , NULL ) ;
F_89 ( V_2 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
F_79 ( V_2 ) ;
F_81 ( V_2 ) ;
F_83 ( V_2 ) ;
}
static int F_91 ( struct V_1 * V_2 , struct V_182 * V_183 , int V_184 )
{
struct V_20 * V_21 = F_2 ( V_2 ) ;
struct V_139 * V_151 = (struct V_139 * ) V_183 ;
int V_185 = - V_105 ;
int V_186 ;
if ( V_2 -> V_55 != V_187 || V_184 < sizeof( struct V_139 ) )
goto V_38;
V_186 = F_92 ( F_6 ( V_2 ) , V_151 -> V_148 . V_149 ) ;
V_185 = - V_188 ;
if ( V_151 -> V_148 . V_149 && V_186 != V_189 &&
V_186 != V_190 && V_186 != V_191 )
goto V_38;
V_21 -> V_23 = V_21 -> V_152 = V_151 -> V_148 . V_149 ;
if ( V_186 == V_190 || V_186 == V_191 )
V_21 -> V_152 = 0 ;
F_93 ( V_2 ) ;
V_185 = 0 ;
V_38: return V_185 ;
}
static int F_94 ( struct V_127 * V_128 , struct V_1 * V_2 , struct V_114 * V_115 ,
T_5 V_129 , int V_192 , int V_84 , int * V_184 )
{
struct V_20 * V_21 = F_2 ( V_2 ) ;
T_5 V_193 = 0 ;
int V_49 = - V_135 ;
struct V_139 * sin = (struct V_139 * ) V_115 -> V_141 ;
struct V_26 * V_27 ;
if ( V_84 & V_137 )
goto V_38;
if ( V_184 )
* V_184 = sizeof( * sin ) ;
if ( V_84 & V_194 ) {
V_49 = F_95 ( V_2 , V_115 , V_129 ) ;
goto V_38;
}
V_27 = F_96 ( V_2 , V_84 , V_192 , & V_49 ) ;
if ( ! V_27 )
goto V_38;
V_193 = V_27 -> V_129 ;
if ( V_129 < V_193 ) {
V_115 -> V_136 |= V_195 ;
V_193 = V_129 ;
}
V_49 = F_97 ( V_27 , 0 , V_115 -> V_120 , V_193 ) ;
if ( V_49 )
goto V_160;
F_98 ( V_115 , V_2 , V_27 ) ;
if ( sin ) {
sin -> V_142 = V_143 ;
sin -> V_148 . V_149 = F_28 ( V_27 ) -> V_41 ;
sin -> V_196 = 0 ;
memset ( & sin -> V_197 , 0 , sizeof( sin -> V_197 ) ) ;
}
if ( V_21 -> V_198 )
F_99 ( V_115 , V_27 ) ;
if ( V_84 & V_195 )
V_193 = V_27 -> V_129 ;
V_160:
F_100 ( V_2 , V_27 ) ;
V_38:
if ( V_49 )
return V_49 ;
return V_193 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_199 * V_200 = F_16 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_10 == V_44 )
memset ( & V_200 -> V_32 , 0 , sizeof( V_200 -> V_32 ) ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 , char T_6 * V_201 , int V_159 )
{
if ( V_159 > sizeof( struct F_13 ) )
V_159 = sizeof( struct F_13 ) ;
if ( F_103 ( & F_16 ( V_2 ) -> V_32 , V_201 , V_159 ) )
return - V_103 ;
return 0 ;
}
static int F_104 ( struct V_1 * V_2 , char T_6 * V_201 , int T_6 * V_159 )
{
int V_129 , V_185 = - V_103 ;
if ( F_62 ( V_129 , V_159 ) )
goto V_38;
V_185 = - V_105 ;
if ( V_129 < 0 )
goto V_38;
if ( V_129 > sizeof( struct F_13 ) )
V_129 = sizeof( struct F_13 ) ;
V_185 = - V_103 ;
if ( F_105 ( V_129 , V_159 ) ||
F_106 ( V_201 , & F_16 ( V_2 ) -> V_32 , V_129 ) )
goto V_38;
V_185 = 0 ;
V_38: return V_185 ;
}
static int F_107 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , unsigned int V_159 )
{
if ( V_203 == V_204 ) {
if ( F_2 ( V_2 ) -> V_10 != V_44 )
return - V_135 ;
else
return F_102 ( V_2 , V_201 , V_159 ) ;
}
return - V_205 ;
}
static int F_108 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , unsigned int V_159 )
{
if ( V_202 != V_206 )
return F_109 ( V_2 , V_202 , V_203 , V_201 , V_159 ) ;
return F_107 ( V_2 , V_202 , V_203 , V_201 , V_159 ) ;
}
static int F_110 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , unsigned int V_159 )
{
if ( V_202 != V_206 )
return F_111 ( V_2 , V_202 , V_203 , V_201 , V_159 ) ;
return F_107 ( V_2 , V_202 , V_203 , V_201 , V_159 ) ;
}
static int F_112 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , int T_6 * V_159 )
{
if ( V_203 == V_204 ) {
if ( F_2 ( V_2 ) -> V_10 != V_44 )
return - V_135 ;
else
return F_104 ( V_2 , V_201 , V_159 ) ;
}
return - V_205 ;
}
static int F_113 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , int T_6 * V_159 )
{
if ( V_202 != V_206 )
return F_114 ( V_2 , V_202 , V_203 , V_201 , V_159 ) ;
return F_112 ( V_2 , V_202 , V_203 , V_201 , V_159 ) ;
}
static int F_115 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , int T_6 * V_159 )
{
if ( V_202 != V_206 )
return F_116 ( V_2 , V_202 , V_203 , V_201 , V_159 ) ;
return F_112 ( V_2 , V_202 , V_203 , V_201 , V_159 ) ;
}
static int F_117 ( struct V_1 * V_2 , int V_207 , unsigned long V_208 )
{
switch ( V_207 ) {
case V_209 : {
int V_210 = F_118 ( V_2 ) ;
return F_105 ( V_210 , ( int T_6 * ) V_208 ) ;
}
case V_211 : {
struct V_26 * V_27 ;
int V_210 = 0 ;
F_119 ( & V_2 -> V_212 . V_12 ) ;
V_27 = F_120 ( & V_2 -> V_212 ) ;
if ( V_27 != NULL )
V_210 = V_27 -> V_129 ;
F_121 ( & V_2 -> V_212 . V_12 ) ;
return F_105 ( V_210 , ( int T_6 * ) V_208 ) ;
}
default:
#ifdef F_122
return F_123 ( V_2 , V_207 , ( void T_6 * ) V_208 ) ;
#else
return - V_213 ;
#endif
}
}
static int F_124 ( struct V_1 * V_2 , unsigned int V_207 , unsigned long V_208 )
{
switch ( V_207 ) {
case V_209 :
case V_211 :
return - V_213 ;
default:
#ifdef F_122
return F_125 ( V_2 , V_207 , F_126 ( V_208 ) ) ;
#else
return - V_213 ;
#endif
}
}
static struct V_1 * F_127 ( struct V_214 * V_215 )
{
struct V_1 * V_2 ;
struct V_216 * V_217 = F_128 ( V_215 ) ;
for ( V_217 -> V_218 = 0 ; V_217 -> V_218 < V_11 ;
++ V_217 -> V_218 ) {
struct V_18 * V_19 ;
F_129 (sk, node, &state->h->ht[state->bucket])
if ( F_6 ( V_2 ) == F_130 ( V_215 ) )
goto V_25;
}
V_2 = NULL ;
V_25:
return V_2 ;
}
static struct V_1 * F_131 ( struct V_214 * V_215 , struct V_1 * V_2 )
{
struct V_216 * V_217 = F_128 ( V_215 ) ;
do {
V_2 = F_24 ( V_2 ) ;
V_219:
;
} while ( V_2 && F_6 ( V_2 ) != F_130 ( V_215 ) );
if ( ! V_2 && ++ V_217 -> V_218 < V_11 ) {
V_2 = F_27 ( & V_217 -> V_4 -> V_9 [ V_217 -> V_218 ] ) ;
goto V_219;
}
return V_2 ;
}
static struct V_1 * F_132 ( struct V_214 * V_215 , T_7 V_220 )
{
struct V_1 * V_2 = F_127 ( V_215 ) ;
if ( V_2 )
while ( V_220 && ( V_2 = F_131 ( V_215 , V_2 ) ) != NULL )
-- V_220 ;
return V_220 ? NULL : V_2 ;
}
void * F_133 ( struct V_214 * V_215 , T_7 * V_220 )
{
struct V_216 * V_217 = F_128 ( V_215 ) ;
F_18 ( & V_217 -> V_4 -> V_12 ) ;
return * V_220 ? F_132 ( V_215 , * V_220 - 1 ) : V_221 ;
}
void * F_134 ( struct V_214 * V_215 , void * V_222 , T_7 * V_220 )
{
struct V_1 * V_2 ;
if ( V_222 == V_221 )
V_2 = F_127 ( V_215 ) ;
else
V_2 = F_131 ( V_215 , V_222 ) ;
++ * V_220 ;
return V_2 ;
}
void F_135 ( struct V_214 * V_215 , void * V_222 )
{
struct V_216 * V_217 = F_128 ( V_215 ) ;
F_25 ( & V_217 -> V_4 -> V_12 ) ;
}
static void F_136 ( struct V_214 * V_215 , struct V_1 * V_223 , int V_119 )
{
struct V_20 * V_21 = F_2 ( V_223 ) ;
T_1 V_224 = V_21 -> V_22 ,
V_225 = V_21 -> V_23 ;
T_8 V_226 = 0 ,
V_227 = V_21 -> V_10 ;
F_137 ( V_215 , L_2
L_3 ,
V_119 , V_225 , V_227 , V_224 , V_226 , V_223 -> V_55 ,
F_118 ( V_223 ) ,
F_138 ( V_223 ) ,
0 , 0L , 0 , F_139 ( V_223 ) , 0 , F_140 ( V_223 ) ,
F_141 ( & V_223 -> V_228 ) , V_223 , F_141 ( & V_223 -> V_77 ) ) ;
}
static int F_142 ( struct V_214 * V_215 , void * V_222 )
{
if ( V_222 == V_221 )
F_137 ( V_215 , L_4
L_5
L_6 ) ;
else
F_136 ( V_215 , V_222 , F_128 ( V_215 ) -> V_218 ) ;
return 0 ;
}
int F_143 ( struct V_229 * V_230 , struct V_231 * V_231 ,
struct V_3 * V_4 , const struct V_232 * V_233 )
{
int V_49 ;
struct V_216 * V_119 ;
V_49 = F_144 ( V_230 , V_231 , V_233 , sizeof( struct V_216 ) ) ;
if ( V_49 < 0 )
return V_49 ;
V_119 = F_128 ( (struct V_214 * ) V_231 -> V_234 ) ;
V_119 -> V_4 = V_4 ;
return 0 ;
}
static int F_145 ( struct V_229 * V_229 , struct V_231 * V_231 )
{
return F_143 ( V_229 , V_231 , & V_37 , & V_235 ) ;
}
static T_9 int F_146 ( struct V_13 * V_13 )
{
if ( ! F_147 ( V_13 , L_7 , V_236 , & V_237 ) )
return - V_238 ;
return 0 ;
}
static T_10 void F_148 ( struct V_13 * V_13 )
{
F_149 ( V_13 , L_7 ) ;
}
int T_11 F_150 ( void )
{
return F_151 ( & V_239 ) ;
}
void T_11 F_152 ( void )
{
F_153 ( & V_239 ) ;
}
