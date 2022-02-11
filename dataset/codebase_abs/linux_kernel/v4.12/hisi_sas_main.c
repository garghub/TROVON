static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 -> V_6 ;
}
struct V_7 * F_2 ( struct V_8 * V_9 )
{
return F_3 ( V_9 , struct V_7 , V_9 ) ;
}
static void F_4 ( struct V_1 * V_1 , int V_10 )
{
void * V_11 = V_1 -> V_12 ;
F_5 ( V_10 , V_11 ) ;
}
static void F_6 ( struct V_1 * V_1 , int V_10 )
{
F_4 ( V_1 , V_10 ) ;
}
static void F_7 ( struct V_1 * V_1 , int V_10 )
{
void * V_11 = V_1 -> V_12 ;
F_8 ( V_10 , V_11 ) ;
}
static int F_9 ( struct V_1 * V_1 , int * V_10 )
{
unsigned int V_13 ;
void * V_11 = V_1 -> V_12 ;
V_13 = F_10 ( V_11 , V_1 -> V_14 ) ;
if ( V_13 >= V_1 -> V_14 )
return - V_15 ;
F_7 ( V_1 , V_13 ) ;
* V_10 = V_13 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_1 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_14 ; ++ V_16 )
F_4 ( V_1 , V_16 ) ;
}
void F_12 ( struct V_1 * V_1 , struct V_17 * V_18 ,
struct V_19 * V_20 )
{
if ( V_18 ) {
struct V_3 * V_21 = & V_1 -> V_22 -> V_21 ;
struct V_2 * V_3 = V_18 -> V_21 ;
struct V_23 * V_24 = V_3 -> V_25 ;
if ( ! F_13 ( V_18 -> V_26 ) )
if ( V_20 -> V_27 )
F_14 ( V_21 , V_18 -> V_28 , V_20 -> V_27 ,
V_18 -> V_29 ) ;
V_18 -> V_30 = NULL ;
if ( V_24 )
F_15 ( & V_24 -> V_31 ) ;
}
if ( V_20 -> V_32 )
F_16 ( V_1 -> V_33 ,
V_20 -> V_32 , V_20 -> V_34 ) ;
if ( V_20 -> V_35 )
F_16 ( V_1 -> V_36 ,
V_20 -> V_35 , V_20 -> V_37 ) ;
if ( V_20 -> V_38 )
F_16 ( V_1 -> V_39 , V_20 -> V_38 ,
V_20 -> V_40 ) ;
F_17 ( & V_20 -> V_41 ) ;
V_20 -> V_18 = NULL ;
V_20 -> V_4 = NULL ;
F_6 ( V_1 , V_20 -> V_42 ) ;
}
static int F_18 ( struct V_1 * V_1 ,
struct V_19 * V_20 )
{
return V_1 -> V_43 -> V_44 ( V_1 , V_20 ) ;
}
static int F_19 ( struct V_1 * V_1 ,
struct V_19 * V_20 , int V_45 ,
struct V_46 * V_47 )
{
return V_1 -> V_43 -> V_48 ( V_1 , V_20 , V_45 , V_47 ) ;
}
static int F_20 ( struct V_1 * V_1 ,
struct V_19 * V_20 )
{
return V_1 -> V_43 -> V_49 ( V_1 , V_20 ) ;
}
static int F_21 ( struct V_1 * V_1 ,
struct V_19 * V_20 ,
int V_50 , int V_51 , int V_52 )
{
return V_1 -> V_43 -> V_53 ( V_1 , V_20 ,
V_50 , V_51 , V_52 ) ;
}
static void F_22 ( struct V_54 * V_55 )
{
struct V_19 * V_56 =
F_3 ( V_55 , struct V_19 , V_56 ) ;
struct V_17 * V_18 = V_56 -> V_18 ;
struct V_1 * V_1 = F_1 ( V_18 -> V_21 ) ;
struct V_57 * V_58 = V_18 -> V_59 ;
struct V_46 V_60 ;
struct V_61 V_62 ;
struct V_3 * V_21 = & V_1 -> V_22 -> V_21 ;
int V_63 = V_56 -> V_42 ;
unsigned long V_64 ;
if ( ! ( V_18 -> V_26 & V_65 ) ) {
F_23 ( V_21 , L_1 ) ;
goto V_66;
}
F_24 ( V_58 -> V_3 -> V_62 , & V_62 ) ;
V_60 . V_47 = V_67 ;
V_60 . V_68 = F_25 ( V_63 ) ;
F_26 ( V_18 -> V_21 , V_62 . V_61 , & V_60 ) ;
V_66:
F_27 ( & V_1 -> V_69 , V_64 ) ;
F_12 ( V_1 , V_18 , V_56 ) ;
F_28 ( & V_1 -> V_69 , V_64 ) ;
if ( V_18 -> V_70 )
V_18 -> V_70 ( V_18 ) ;
}
static int F_29 ( struct V_17 * V_18 , struct V_1 * V_1 ,
int V_45 , struct V_46 * V_47 ,
int * V_71 )
{
struct V_2 * V_3 = V_18 -> V_21 ;
struct V_23 * V_24 = V_3 -> V_25 ;
struct V_7 * V_4 ;
struct V_19 * V_20 ;
struct V_72 * V_73 ;
struct V_8 * V_9 = V_3 -> V_4 ;
struct V_3 * V_21 = & V_1 -> V_22 -> V_21 ;
int V_74 , V_75 , V_27 = 0 , V_76 , V_10 ;
unsigned long V_64 ;
if ( ! V_9 ) {
struct V_77 * V_78 = & V_18 -> V_79 ;
V_78 -> V_80 = V_81 ;
V_78 -> V_82 = V_83 ;
if ( V_3 -> V_84 != V_85 )
V_18 -> V_70 ( V_18 ) ;
return V_83 ;
}
if ( F_30 ( V_24 ) ) {
if ( V_24 )
F_31 ( V_21 , L_2 ,
V_24 -> V_50 ) ;
else
F_31 ( V_21 , L_3 ,
F_32 ( V_3 -> V_86 ) ) ;
return V_83 ;
}
V_4 = F_2 ( V_9 ) ;
if ( V_4 && ! V_4 -> V_87 ) {
F_31 ( V_21 , L_4 ,
( F_33 ( V_3 ) ) ?
L_5 : L_6 ,
V_3 -> V_4 -> V_88 ) ;
return V_83 ;
}
if ( ! F_13 ( V_18 -> V_26 ) ) {
if ( V_18 -> V_89 ) {
V_27 = F_34 ( V_21 , V_18 -> V_28 ,
V_18 -> V_89 , V_18 -> V_29 ) ;
if ( ! V_27 ) {
V_76 = - V_90 ;
goto V_91;
}
}
} else
V_27 = V_18 -> V_89 ;
if ( V_1 -> V_43 -> V_92 )
V_76 = V_1 -> V_43 -> V_92 ( V_1 , & V_10 ,
V_3 ) ;
else
V_76 = F_9 ( V_1 , & V_10 ) ;
if ( V_76 )
goto V_93;
V_76 = V_1 -> V_43 -> V_94 ( V_1 , V_24 -> V_50 ,
& V_75 , & V_74 ) ;
if ( V_76 )
goto V_95;
V_20 = & V_1 -> V_96 [ V_10 ] ;
memset ( V_20 , 0 , sizeof( struct V_19 ) ) ;
V_20 -> V_42 = V_10 ;
V_20 -> V_27 = V_27 ;
V_20 -> V_75 = V_75 ;
V_20 -> V_74 = V_74 ;
V_73 = V_1 -> V_97 [ V_75 ] ;
V_20 -> V_97 = & V_73 [ V_74 ] ;
V_20 -> V_18 = V_18 ;
V_20 -> V_4 = V_4 ;
V_18 -> V_30 = V_20 ;
F_35 ( & V_20 -> V_56 , F_22 ) ;
V_20 -> V_35 = F_36 ( V_1 -> V_36 ,
V_98 ,
& V_20 -> V_37 ) ;
if ( ! V_20 -> V_35 ) {
V_76 = - V_90 ;
goto V_99;
}
memset ( V_20 -> V_35 , 0 , V_100 ) ;
V_20 -> V_32 = F_36 ( V_1 -> V_33 ,
V_98 ,
& V_20 -> V_34 ) ;
if ( ! V_20 -> V_32 ) {
V_76 = - V_90 ;
goto V_101;
}
memset ( V_20 -> V_32 , 0 , V_102 ) ;
memset ( V_20 -> V_97 , 0 , sizeof( struct V_72 ) ) ;
switch ( V_18 -> V_26 ) {
case V_103 :
V_76 = F_18 ( V_1 , V_20 ) ;
break;
case V_65 :
V_76 = F_19 ( V_1 , V_20 , V_45 , V_47 ) ;
break;
case V_104 :
case V_105 :
case V_104 | V_105 :
V_76 = F_20 ( V_1 , V_20 ) ;
break;
default:
F_23 ( V_21 , L_7 ,
V_18 -> V_26 ) ;
V_76 = - V_106 ;
break;
}
if ( V_76 ) {
F_23 ( V_21 , L_8 , V_76 ) ;
if ( V_20 -> V_38 )
goto V_107;
goto V_108;
}
F_37 ( & V_20 -> V_41 , & V_24 -> V_109 ) ;
F_27 ( & V_18 -> V_110 , V_64 ) ;
V_18 -> V_111 |= V_112 ;
F_28 ( & V_18 -> V_110 , V_64 ) ;
V_1 -> V_113 = V_20 ;
F_38 ( & V_24 -> V_31 ) ;
++ ( * V_71 ) ;
return 0 ;
V_107:
F_16 ( V_1 -> V_39 , V_20 -> V_38 ,
V_20 -> V_40 ) ;
V_108:
F_16 ( V_1 -> V_33 , V_20 -> V_32 ,
V_20 -> V_34 ) ;
V_101:
F_16 ( V_1 -> V_36 , V_20 -> V_35 ,
V_20 -> V_37 ) ;
V_99:
V_95:
F_6 ( V_1 , V_10 ) ;
V_93:
F_23 ( V_21 , L_9 , V_76 ) ;
if ( ! F_13 ( V_18 -> V_26 ) )
if ( V_27 )
F_14 ( V_21 , V_18 -> V_28 , V_27 ,
V_18 -> V_29 ) ;
V_91:
return V_76 ;
}
static int F_39 ( struct V_17 * V_18 , T_1 V_114 ,
int V_45 , struct V_46 * V_47 )
{
T_2 V_76 ;
T_2 V_71 = 0 ;
unsigned long V_64 ;
struct V_1 * V_1 = F_1 ( V_18 -> V_21 ) ;
struct V_3 * V_21 = & V_1 -> V_22 -> V_21 ;
if ( F_40 ( F_41 ( V_115 , & V_1 -> V_64 ) ) )
return - V_106 ;
F_27 ( & V_1 -> V_69 , V_64 ) ;
V_76 = F_29 ( V_18 , V_1 , V_45 , V_47 , & V_71 ) ;
if ( V_76 )
F_23 ( V_21 , L_10 , V_76 ) ;
if ( F_42 ( V_71 ) )
V_1 -> V_43 -> V_116 ( V_1 ) ;
F_28 ( & V_1 -> V_69 , V_64 ) ;
return V_76 ;
}
static void F_43 ( struct V_1 * V_1 , int V_117 )
{
struct V_118 * V_119 = & V_1 -> V_119 [ V_117 ] ;
struct V_120 * V_121 = & V_119 -> V_121 ;
struct V_122 * V_123 ;
if ( ! V_119 -> V_124 )
return;
V_123 = & V_1 -> V_125 ;
V_123 -> V_126 ( V_121 , V_127 ) ;
if ( V_121 -> V_119 ) {
struct V_121 * V_128 = V_121 -> V_119 ;
V_128 -> V_129 = V_121 -> V_130 ;
V_128 -> V_131 = V_132 ;
V_128 -> V_133 =
V_1 -> V_43 -> V_134 () ;
if ( V_128 -> V_135 == V_136 )
V_128 -> V_135 = V_119 -> V_135 ;
if ( V_128 -> V_137 == V_136 )
V_128 -> V_137 = V_119 -> V_137 ;
}
if ( V_119 -> V_138 & V_139 ) {
struct V_140 * V_88 ;
V_88 = (struct V_140 * ) V_119 -> V_141 ;
V_88 -> V_84 = V_119 -> V_142 . V_143 ;
V_88 -> V_144 = V_145 ;
V_88 -> V_146 = V_119 -> V_142 . V_147 ;
} else if ( V_119 -> V_138 & V_148 ) {
}
V_121 -> V_149 = V_119 -> V_149 ;
V_123 -> V_150 ( V_121 , V_151 ) ;
}
static struct V_23 * F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_23 * V_24 = NULL ;
int V_16 ;
F_45 ( & V_1 -> V_69 ) ;
for ( V_16 = 0 ; V_16 < V_152 ; V_16 ++ ) {
if ( V_1 -> V_153 [ V_16 ] . V_84 == V_154 ) {
V_1 -> V_153 [ V_16 ] . V_50 = V_16 ;
V_24 = & V_1 -> V_153 [ V_16 ] ;
V_24 -> V_155 = V_156 ;
V_24 -> V_84 = V_3 -> V_84 ;
V_24 -> V_1 = V_1 ;
V_24 -> V_157 = V_3 ;
F_46 ( & V_1 -> V_153 [ V_16 ] . V_109 ) ;
break;
}
}
F_47 ( & V_1 -> V_69 ) ;
return V_24 ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_2 * V_158 = V_3 -> V_159 ;
struct V_23 * V_24 ;
struct V_3 * V_21 = & V_1 -> V_22 -> V_21 ;
if ( V_1 -> V_43 -> V_160 )
V_24 = V_1 -> V_43 -> V_160 ( V_3 ) ;
else
V_24 = F_44 ( V_3 ) ;
if ( ! V_24 ) {
F_23 ( V_21 , L_11 ,
V_152 ) ;
return - V_106 ;
}
V_3 -> V_25 = V_24 ;
V_1 -> V_43 -> V_161 ( V_1 , V_24 ) ;
if ( V_158 && F_49 ( V_158 -> V_84 ) ) {
int V_117 ;
T_3 V_162 = V_158 -> V_163 . V_164 ;
struct V_165 * V_119 ;
for ( V_117 = 0 ; V_117 < V_162 ; V_117 ++ ) {
V_119 = & V_158 -> V_163 . V_165 [ V_117 ] ;
if ( F_32 ( V_119 -> V_166 ) ==
F_32 ( V_3 -> V_86 ) ) {
V_24 -> V_167 = V_117 ;
break;
}
}
if ( V_117 == V_162 ) {
F_31 ( V_21 , L_12
L_13 ,
F_32 ( V_3 -> V_86 ) ,
F_32 ( V_158 -> V_86 ) ) ;
return - V_106 ;
}
}
return 0 ;
}
static int F_50 ( struct V_168 * V_169 )
{
struct V_2 * V_21 = F_51 ( V_169 ) ;
int V_170 = F_52 ( V_169 ) ;
if ( V_170 )
return V_170 ;
if ( ! F_33 ( V_21 ) )
F_53 ( V_169 , 64 ) ;
return 0 ;
}
static void F_54 ( struct V_171 * V_172 )
{
struct V_1 * V_1 = F_55 ( V_172 ) ;
V_1 -> V_43 -> V_173 ( V_1 ) ;
}
static int F_56 ( struct V_171 * V_172 , unsigned long time )
{
struct V_1 * V_1 = F_55 ( V_172 ) ;
struct V_122 * V_125 = & V_1 -> V_125 ;
if ( time < V_174 )
return 0 ;
F_57 ( V_125 ) ;
return 1 ;
}
static void F_58 ( struct V_54 * V_55 )
{
struct V_118 * V_119 =
F_3 ( V_55 , struct V_118 , V_175 ) ;
struct V_1 * V_1 = V_119 -> V_1 ;
struct V_120 * V_121 = & V_119 -> V_121 ;
int V_117 = V_121 -> V_88 ;
V_1 -> V_43 -> V_176 ( V_1 , V_117 ) ;
F_43 ( V_1 , V_117 ) ;
}
static void F_59 ( struct V_1 * V_1 , int V_117 )
{
struct V_118 * V_119 = & V_1 -> V_119 [ V_117 ] ;
struct V_120 * V_121 = & V_119 -> V_121 ;
V_119 -> V_1 = V_1 ;
V_119 -> V_4 = NULL ;
F_60 ( & V_119 -> V_177 ) ;
V_121 -> V_178 = ( V_117 < V_1 -> V_179 ) ? 1 : 0 ;
V_121 -> V_180 = V_181 ;
V_121 -> V_182 = V_145 ;
V_121 -> V_183 = 0 ;
V_121 -> type = V_184 ;
V_121 -> V_185 = V_186 ;
V_121 -> V_187 = V_188 ;
V_121 -> V_130 = V_136 ;
V_121 -> V_88 = V_117 ;
V_121 -> V_86 = & V_1 -> V_86 [ 0 ] ;
V_121 -> V_141 = & V_119 -> V_141 [ 0 ] ;
V_121 -> V_5 = (struct V_122 * ) V_1 -> V_172 -> V_189 ;
V_121 -> V_190 = V_119 ;
F_35 ( & V_119 -> V_175 , F_58 ) ;
}
static void F_61 ( struct V_120 * V_121 )
{
struct V_122 * V_123 = V_121 -> V_5 ;
struct V_1 * V_1 = V_123 -> V_6 ;
struct V_118 * V_119 = V_121 -> V_190 ;
struct V_8 * V_9 = V_121 -> V_4 ;
struct V_7 * V_4 = F_2 ( V_9 ) ;
unsigned long V_64 ;
if ( ! V_9 )
return;
F_27 ( & V_1 -> V_69 , V_64 ) ;
V_4 -> V_87 = 1 ;
V_4 -> V_88 = V_119 -> V_191 ;
V_119 -> V_4 = V_4 ;
V_9 -> V_192 = V_4 ;
F_28 ( & V_1 -> V_69 , V_64 ) ;
}
static void F_62 ( struct V_1 * V_1 , struct V_17 * V_18 ,
struct V_19 * V_20 )
{
if ( V_18 ) {
unsigned long V_64 ;
struct V_77 * V_78 ;
V_78 = & V_18 -> V_79 ;
V_78 -> V_80 = V_193 ;
V_78 -> V_82 = V_194 ;
F_27 ( & V_18 -> V_110 , V_64 ) ;
V_18 -> V_111 &=
~ ( V_195 | V_112 ) ;
V_18 -> V_111 |= V_196 ;
F_28 ( & V_18 -> V_110 , V_64 ) ;
}
F_12 ( V_1 , V_18 , V_20 ) ;
}
static void F_63 ( struct V_1 * V_1 ,
struct V_2 * V_3 )
{
struct V_19 * V_20 , * V_197 ;
struct V_23 * V_24 = V_3 -> V_25 ;
F_64 (slot, slot2, &sas_dev->list, entry)
F_62 ( V_1 , V_20 -> V_18 , V_20 ) ;
}
static void F_65 ( struct V_1 * V_1 )
{
struct V_23 * V_24 ;
struct V_2 * V_3 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_152 ; V_16 ++ ) {
V_24 = & V_1 -> V_153 [ V_16 ] ;
V_3 = V_24 -> V_157 ;
if ( ( V_24 -> V_84 == V_154 ) ||
! V_3 )
continue;
F_63 ( V_1 , V_3 ) ;
}
}
static void F_66 ( struct V_2 * V_3 )
{
struct V_23 * V_24 = V_3 -> V_25 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_3 * V_21 = & V_1 -> V_22 -> V_21 ;
T_4 V_198 = V_24 -> V_50 ;
F_31 ( V_21 , L_14 ,
V_24 -> V_50 , V_24 -> V_84 ) ;
F_67 ( V_1 , V_3 ,
V_199 , 0 ) ;
V_1 -> V_43 -> V_200 ( V_1 , V_24 ) ;
V_3 -> V_25 = NULL ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_24 -> V_50 = V_198 ;
V_24 -> V_84 = V_154 ;
V_24 -> V_155 = V_156 ;
}
static int F_68 ( struct V_17 * V_18 , T_1 V_114 )
{
return F_39 ( V_18 , V_114 , 0 , NULL ) ;
}
static int F_69 ( struct V_120 * V_121 , enum V_201 V_202 ,
void * V_203 )
{
struct V_122 * V_123 = V_121 -> V_5 ;
struct V_1 * V_1 = V_123 -> V_6 ;
int V_117 = V_121 -> V_88 ;
switch ( V_202 ) {
case V_204 :
V_1 -> V_43 -> V_205 ( V_1 , V_117 ) ;
break;
case V_206 :
V_1 -> V_43 -> V_207 ( V_1 , V_117 ) ;
F_70 ( 100 ) ;
V_1 -> V_43 -> V_208 ( V_1 , V_117 ) ;
break;
case V_209 :
V_1 -> V_43 -> V_207 ( V_1 , V_117 ) ;
break;
case V_210 :
V_1 -> V_43 -> V_211 ( V_1 , V_117 , V_203 ) ;
break;
case V_212 :
default:
return - V_213 ;
}
return 0 ;
}
static void F_71 ( struct V_17 * V_18 )
{
if ( ! F_72 ( & V_18 -> V_214 -> V_177 ) )
return;
F_73 ( & V_18 -> V_214 -> V_215 ) ;
}
static void F_74 ( unsigned long V_216 )
{
struct V_17 * V_18 = (struct V_17 * ) V_216 ;
V_18 -> V_111 |= V_217 ;
F_73 ( & V_18 -> V_214 -> V_215 ) ;
}
static int F_75 ( struct V_2 * V_3 ,
void * V_218 , T_2 V_219 ,
struct V_46 * V_47 )
{
struct V_23 * V_24 = V_3 -> V_25 ;
struct V_1 * V_1 = V_24 -> V_1 ;
struct V_3 * V_21 = & V_1 -> V_22 -> V_21 ;
struct V_17 * V_18 ;
int V_220 , V_221 ;
for ( V_221 = 0 ; V_221 < V_222 ; V_221 ++ ) {
V_18 = F_76 ( V_223 ) ;
if ( ! V_18 )
return - V_90 ;
V_18 -> V_21 = V_3 ;
V_18 -> V_26 = V_3 -> V_183 ;
if ( F_33 ( V_3 ) ) {
V_18 -> V_224 . V_225 = 1 ;
memcpy ( & V_18 -> V_224 . V_226 , V_218 , V_219 ) ;
} else {
memcpy ( & V_18 -> V_227 , V_218 , V_219 ) ;
}
V_18 -> V_70 = F_71 ;
V_18 -> V_214 -> V_177 . V_216 = ( unsigned long ) V_18 ;
V_18 -> V_214 -> V_177 . V_228 = F_74 ;
V_18 -> V_214 -> V_177 . V_229 = V_230 + V_231 * V_174 ;
F_77 ( & V_18 -> V_214 -> V_177 ) ;
V_220 = F_39 ( V_18 , V_223 , 1 , V_47 ) ;
if ( V_220 ) {
F_72 ( & V_18 -> V_214 -> V_177 ) ;
F_23 ( V_21 , L_15 ,
V_220 ) ;
goto V_232;
}
F_78 ( & V_18 -> V_214 -> V_215 ) ;
V_220 = V_233 ;
if ( ( V_18 -> V_111 & V_217 ) ) {
if ( ! ( V_18 -> V_111 & V_196 ) ) {
struct V_19 * V_20 = V_18 -> V_30 ;
F_23 ( V_21 , L_16 ) ;
if ( V_20 )
V_20 -> V_18 = NULL ;
goto V_232;
}
}
if ( V_18 -> V_79 . V_80 == V_193 &&
V_18 -> V_79 . V_82 == V_234 ) {
V_220 = V_234 ;
break;
}
if ( V_18 -> V_79 . V_80 == V_193 &&
V_18 -> V_79 . V_82 == V_235 ) {
V_220 = V_235 ;
break;
}
if ( V_18 -> V_79 . V_80 == V_193 &&
V_18 -> V_79 . V_82 == V_236 ) {
F_79 ( V_21 , L_17
L_18 ,
F_32 ( V_3 -> V_86 ) ,
V_18 -> V_79 . V_80 ,
V_18 -> V_79 . V_82 ) ;
V_220 = V_18 -> V_79 . V_237 ;
break;
}
if ( V_18 -> V_79 . V_80 == V_193 &&
V_18 -> V_79 . V_82 == V_238 ) {
F_79 ( V_21 , L_19 ) ;
V_220 = - V_239 ;
break;
}
F_79 ( V_21 , L_20
L_21 ,
F_32 ( V_3 -> V_86 ) , V_18 -> V_79 . V_80 ,
V_18 -> V_79 . V_82 ) ;
F_80 ( V_18 ) ;
V_18 = NULL ;
}
V_232:
if ( V_221 == V_222 )
F_79 ( V_21 , L_22 ) ;
F_80 ( V_18 ) ;
return V_220 ;
}
static void F_81 ( struct V_240 * V_21 ,
bool V_241 , int V_242 , T_3 * V_226 )
{
struct V_243 V_244 ;
F_82 ( V_21 , & V_244 ) ;
if ( V_241 )
V_244 . V_245 |= V_246 ;
else
V_244 . V_245 &= ~ V_246 ;
V_244 . V_247 = V_248 ;
F_83 ( & V_244 , V_242 , 0 , V_226 ) ;
}
static int F_84 ( struct V_2 * V_3 )
{
T_3 V_226 [ 20 ] = { 0 } ;
struct V_249 * V_250 = V_3 -> V_251 . V_250 ;
struct V_252 * V_253 ;
int V_76 = V_233 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_3 * V_21 = & V_1 -> V_22 -> V_21 ;
int V_254 = sizeof( struct V_255 ) ;
unsigned long V_64 ;
F_85 (link, ap, EDGE) {
int V_242 = F_86 ( V_253 ) ;
F_81 ( V_253 -> V_3 , 1 , V_242 , V_226 ) ;
V_76 = F_75 ( V_3 , V_226 , V_254 , NULL ) ;
if ( V_76 != V_234 )
break;
}
if ( V_76 == V_234 ) {
F_85 (link, ap, EDGE) {
int V_242 = F_86 ( V_253 ) ;
F_81 ( V_253 -> V_3 , 0 , V_242 , V_226 ) ;
V_76 = F_75 ( V_3 , V_226 ,
V_254 , NULL ) ;
if ( V_76 != V_234 )
F_23 ( V_21 , L_23 ) ;
}
} else {
F_23 ( V_21 , L_24 ) ;
}
if ( V_76 == V_234 ) {
F_27 ( & V_1 -> V_69 , V_64 ) ;
F_63 ( V_1 , V_3 ) ;
F_28 ( & V_1 -> V_69 , V_64 ) ;
}
return V_76 ;
}
static int F_26 ( struct V_2 * V_3 ,
T_3 * V_62 , struct V_46 * V_47 )
{
struct V_256 V_227 ;
if ( ! ( V_3 -> V_183 & V_65 ) )
return V_257 ;
memcpy ( V_227 . V_258 , V_62 , 8 ) ;
return F_75 ( V_3 , & V_227 ,
sizeof( V_227 ) , V_47 ) ;
}
static int F_87 ( struct V_1 * V_1 )
{
int V_76 ;
if ( ! V_1 -> V_43 -> V_259 )
return - 1 ;
if ( ! F_88 ( V_115 , & V_1 -> V_64 ) ) {
struct V_3 * V_21 = & V_1 -> V_22 -> V_21 ;
struct V_122 * V_123 = & V_1 -> V_125 ;
unsigned long V_64 ;
F_89 ( V_21 , L_25 ) ;
F_90 ( V_1 -> V_172 ) ;
V_76 = V_1 -> V_43 -> V_259 ( V_1 ) ;
if ( V_76 ) {
F_79 ( V_21 , L_26 , V_76 ) ;
goto V_66;
}
F_27 ( & V_1 -> V_69 , V_64 ) ;
F_65 ( V_1 ) ;
F_28 ( & V_1 -> V_69 , V_64 ) ;
V_123 -> V_260 ( V_123 , V_261 ) ;
F_89 ( V_21 , L_27 ) ;
} else
return - 1 ;
V_66:
F_91 ( V_1 -> V_172 ) ;
F_5 ( V_115 , & V_1 -> V_64 ) ;
return V_76 ;
}
static int F_92 ( struct V_17 * V_18 )
{
struct V_61 V_62 ;
struct V_46 V_60 ;
struct V_2 * V_3 = V_18 -> V_21 ;
struct V_23 * V_24 = V_3 -> V_25 ;
struct V_1 * V_1 = F_1 ( V_18 -> V_21 ) ;
struct V_3 * V_21 = & V_1 -> V_22 -> V_21 ;
int V_76 = V_233 ;
unsigned long V_64 ;
if ( ! V_24 ) {
F_79 ( V_21 , L_28 ) ;
return V_233 ;
}
if ( V_18 -> V_111 & V_196 ) {
V_76 = V_234 ;
goto V_66;
}
V_24 -> V_155 = V_262 ;
if ( V_18 -> V_30 && V_18 -> V_26 & V_65 ) {
struct V_57 * V_58 = V_18 -> V_59 ;
struct V_19 * V_20 = V_18 -> V_30 ;
T_2 V_63 = V_20 -> V_42 ;
int V_263 ;
F_24 ( V_58 -> V_3 -> V_62 , & V_62 ) ;
V_60 . V_47 = V_67 ;
V_60 . V_68 = F_25 ( V_63 ) ;
V_76 = F_26 ( V_18 -> V_21 , V_62 . V_61 ,
& V_60 ) ;
V_263 = F_67 ( V_1 , V_3 ,
V_264 , V_63 ) ;
if ( V_76 == V_234 && V_263 != V_235 ) {
if ( V_18 -> V_30 ) {
F_27 ( & V_1 -> V_69 , V_64 ) ;
F_62 ( V_1 , V_18 , V_20 ) ;
F_28 ( & V_1 -> V_69 , V_64 ) ;
}
}
} else if ( V_18 -> V_26 & V_104 ||
V_18 -> V_26 & V_105 ) {
if ( V_18 -> V_21 -> V_84 == V_85 ) {
F_67 ( V_1 , V_3 ,
V_199 , 0 ) ;
V_76 = F_84 ( V_3 ) ;
}
} else if ( V_18 -> V_26 & V_103 ) {
struct V_19 * V_20 = V_18 -> V_30 ;
T_2 V_63 = V_20 -> V_42 ;
V_76 = F_67 ( V_1 , V_3 ,
V_264 , V_63 ) ;
if ( V_76 == V_233 ) {
F_27 ( & V_1 -> V_69 , V_64 ) ;
F_62 ( V_1 , V_18 , V_20 ) ;
F_28 ( & V_1 -> V_69 , V_64 ) ;
}
}
V_66:
if ( V_76 != V_234 )
F_93 ( V_21 , L_29 , V_76 ) ;
return V_76 ;
}
static int F_94 ( struct V_2 * V_3 , T_3 * V_62 )
{
struct V_46 V_60 ;
int V_76 = V_233 ;
V_60 . V_47 = V_265 ;
V_76 = F_26 ( V_3 , V_62 , & V_60 ) ;
return V_76 ;
}
static int F_95 ( struct V_2 * V_3 , T_3 * V_62 )
{
int V_76 = V_233 ;
struct V_46 V_60 ;
V_60 . V_47 = V_266 ;
V_76 = F_26 ( V_3 , V_62 , & V_60 ) ;
return V_76 ;
}
static int F_96 ( struct V_2 * V_3 )
{
struct V_121 * V_119 = F_97 ( V_3 ) ;
int V_76 , V_267 = ( V_3 -> V_84 == V_85 ||
( V_3 -> V_183 & V_105 ) ) ? 0 : 1 ;
V_76 = F_98 ( V_119 , V_267 ) ;
F_99 ( V_119 ) ;
F_70 ( 2000 ) ;
return V_76 ;
}
static int F_100 ( struct V_2 * V_3 )
{
struct V_23 * V_24 = V_3 -> V_25 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_64 ;
int V_76 = V_233 ;
if ( V_24 -> V_155 != V_262 )
return V_233 ;
V_24 -> V_155 = V_156 ;
V_76 = F_96 ( V_3 ) ;
if ( V_76 == V_234 ) {
F_27 ( & V_1 -> V_69 , V_64 ) ;
F_63 ( V_1 , V_3 ) ;
F_28 ( & V_1 -> V_69 , V_64 ) ;
}
return V_76 ;
}
static int F_101 ( struct V_2 * V_3 , T_3 * V_62 )
{
struct V_23 * V_24 = V_3 -> V_25 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_3 * V_21 = & V_1 -> V_22 -> V_21 ;
unsigned long V_64 ;
int V_76 = V_233 ;
V_24 -> V_155 = V_262 ;
if ( F_33 ( V_3 ) ) {
struct V_121 * V_119 ;
V_76 = F_67 ( V_1 , V_3 ,
V_199 , 0 ) ;
if ( V_76 == V_233 )
goto V_66;
V_119 = F_97 ( V_3 ) ;
V_76 = F_98 ( V_119 , 1 ) ;
if ( V_76 == 0 ) {
F_27 ( & V_1 -> V_69 , V_64 ) ;
F_63 ( V_1 , V_3 ) ;
F_28 ( & V_1 -> V_69 , V_64 ) ;
}
F_99 ( V_119 ) ;
} else {
struct V_46 V_60 = { . V_47 = V_268 } ;
V_76 = F_26 ( V_3 , V_62 , & V_60 ) ;
if ( V_76 == V_234 ) {
F_27 ( & V_1 -> V_69 , V_64 ) ;
F_63 ( V_1 , V_3 ) ;
F_28 ( & V_1 -> V_69 , V_64 ) ;
}
}
V_66:
if ( V_76 != V_234 )
F_23 ( V_21 , L_30 ,
V_24 -> V_50 , V_76 ) ;
return V_76 ;
}
static int F_102 ( struct V_122 * V_123 )
{
struct V_1 * V_1 = V_123 -> V_6 ;
return F_87 ( V_1 ) ;
}
static int F_103 ( struct V_17 * V_18 )
{
struct V_61 V_62 ;
struct V_46 V_60 ;
int V_76 = V_233 ;
if ( V_18 -> V_30 && V_18 -> V_26 & V_65 ) {
struct V_57 * V_58 = V_18 -> V_59 ;
struct V_2 * V_3 = V_18 -> V_21 ;
struct V_19 * V_20 = V_18 -> V_30 ;
T_2 V_63 = V_20 -> V_42 ;
F_24 ( V_58 -> V_3 -> V_62 , & V_62 ) ;
V_60 . V_47 = V_269 ;
V_60 . V_68 = F_25 ( V_63 ) ;
V_76 = F_26 ( V_3 ,
V_62 . V_61 ,
& V_60 ) ;
switch ( V_76 ) {
case V_235 :
case V_233 :
case V_234 :
break;
default:
V_76 = V_233 ;
break;
}
}
return V_76 ;
}
static int
F_104 ( struct V_1 * V_1 , T_4 V_50 ,
struct V_17 * V_18 , int V_51 ,
int V_270 )
{
struct V_2 * V_3 = V_18 -> V_21 ;
struct V_23 * V_24 = V_3 -> V_25 ;
struct V_3 * V_21 = & V_1 -> V_22 -> V_21 ;
struct V_7 * V_4 ;
struct V_19 * V_20 ;
struct V_8 * V_9 = V_3 -> V_4 ;
struct V_72 * V_73 ;
int V_74 , V_75 , V_27 = 0 , V_76 , V_10 ;
unsigned long V_64 ;
if ( F_40 ( F_41 ( V_115 , & V_1 -> V_64 ) ) )
return - V_106 ;
if ( ! V_3 -> V_4 )
return - 1 ;
V_4 = F_2 ( V_9 ) ;
V_76 = F_9 ( V_1 , & V_10 ) ;
if ( V_76 )
goto V_93;
V_76 = V_1 -> V_43 -> V_94 ( V_1 , V_24 -> V_50 ,
& V_75 , & V_74 ) ;
if ( V_76 )
goto V_95;
V_20 = & V_1 -> V_96 [ V_10 ] ;
memset ( V_20 , 0 , sizeof( struct V_19 ) ) ;
V_20 -> V_42 = V_10 ;
V_20 -> V_27 = V_27 ;
V_20 -> V_75 = V_75 ;
V_20 -> V_74 = V_74 ;
V_73 = V_1 -> V_97 [ V_75 ] ;
V_20 -> V_97 = & V_73 [ V_74 ] ;
V_20 -> V_18 = V_18 ;
V_20 -> V_4 = V_4 ;
V_18 -> V_30 = V_20 ;
memset ( V_20 -> V_97 , 0 , sizeof( struct V_72 ) ) ;
V_76 = F_21 ( V_1 , V_20 , V_50 ,
V_51 , V_270 ) ;
if ( V_76 )
goto V_95;
F_37 ( & V_20 -> V_41 , & V_24 -> V_109 ) ;
F_27 ( & V_18 -> V_110 , V_64 ) ;
V_18 -> V_111 |= V_112 ;
F_28 ( & V_18 -> V_110 , V_64 ) ;
V_1 -> V_113 = V_20 ;
F_38 ( & V_24 -> V_31 ) ;
V_1 -> V_43 -> V_116 ( V_1 ) ;
return 0 ;
V_95:
F_6 ( V_1 , V_10 ) ;
V_93:
F_23 ( V_21 , L_31 , V_76 ) ;
return V_76 ;
}
static int
F_67 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
int V_51 , int V_63 )
{
struct V_17 * V_18 ;
struct V_23 * V_24 = V_3 -> V_25 ;
struct V_3 * V_21 = & V_1 -> V_22 -> V_21 ;
int V_220 ;
unsigned long V_64 ;
if ( ! V_1 -> V_43 -> V_53 )
return - V_213 ;
V_18 = F_76 ( V_223 ) ;
if ( ! V_18 )
return - V_90 ;
V_18 -> V_21 = V_3 ;
V_18 -> V_26 = V_3 -> V_183 ;
V_18 -> V_70 = F_71 ;
V_18 -> V_214 -> V_177 . V_216 = ( unsigned long ) V_18 ;
V_18 -> V_214 -> V_177 . V_228 = F_74 ;
V_18 -> V_214 -> V_177 . V_229 = V_230 + F_105 ( 110 ) ;
F_77 ( & V_18 -> V_214 -> V_177 ) ;
F_27 ( & V_1 -> V_69 , V_64 ) ;
V_220 = F_104 ( V_1 , V_24 -> V_50 ,
V_18 , V_51 , V_63 ) ;
F_28 ( & V_1 -> V_69 , V_64 ) ;
if ( V_220 ) {
F_72 ( & V_18 -> V_214 -> V_177 ) ;
F_23 ( V_21 , L_32 ,
V_220 ) ;
goto exit;
}
F_78 ( & V_18 -> V_214 -> V_215 ) ;
V_220 = V_233 ;
if ( V_18 -> V_79 . V_80 == V_193 &&
V_18 -> V_79 . V_82 == V_234 ) {
V_220 = V_234 ;
goto exit;
}
if ( V_18 -> V_79 . V_80 == V_193 &&
V_18 -> V_79 . V_82 == V_235 ) {
V_220 = V_235 ;
goto exit;
}
if ( ( V_18 -> V_111 & V_217 ) ) {
if ( ! ( V_18 -> V_111 & V_196 ) ) {
F_23 ( V_21 , L_33 ) ;
}
}
exit:
F_89 ( V_21 , L_34
L_35 ,
F_32 ( V_3 -> V_86 ) ,
V_18 ,
V_18 -> V_79 . V_80 ,
V_18 -> V_79 . V_82 ) ;
F_80 ( V_18 ) ;
return V_220 ;
}
static void F_106 ( struct V_120 * V_121 )
{
F_61 ( V_121 ) ;
}
static void F_107 ( struct V_118 * V_119 )
{
V_119 -> V_124 = 0 ;
V_119 -> V_138 = 0 ;
V_119 -> V_4 = NULL ;
}
void F_108 ( struct V_1 * V_1 , int V_117 , int V_271 )
{
struct V_118 * V_119 = & V_1 -> V_119 [ V_117 ] ;
struct V_120 * V_121 = & V_119 -> V_121 ;
struct V_122 * V_123 = & V_1 -> V_125 ;
if ( V_271 ) {
F_43 ( V_1 , V_117 ) ;
F_61 ( V_121 ) ;
} else {
struct V_7 * V_4 = V_119 -> V_4 ;
V_123 -> V_126 ( V_121 , V_272 ) ;
F_109 ( V_121 ) ;
if ( V_4 ) {
if ( V_119 -> V_138 & V_139 ) {
int V_191 = V_4 -> V_88 ;
if ( ! V_1 -> V_43 -> V_273 ( V_1 ,
V_191 ) )
V_4 -> V_87 = 0 ;
} else if ( V_119 -> V_138 & V_148 )
V_4 -> V_87 = 0 ;
}
F_107 ( V_119 ) ;
}
}
void F_110 ( struct V_1 * V_1 , T_2 V_274 ,
T_2 V_275 )
{
struct V_122 * V_123 = & V_1 -> V_125 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_1 -> V_179 ; V_117 ++ ) {
struct V_118 * V_119 = & V_1 -> V_119 [ V_117 ] ;
struct V_120 * V_121 = & V_119 -> V_121 ;
struct V_8 * V_9 = V_121 -> V_4 ;
struct V_2 * V_21 ;
if ( V_121 -> V_178 ) {
if ( V_275 & ( 1 << V_117 ) )
continue;
if ( V_274 & ( 1 << V_117 ) )
F_108 ( V_1 , V_117 , 0 ) ;
}
if ( ! V_9 )
continue;
V_21 = V_9 -> V_276 ;
if ( F_49 ( V_21 -> V_84 ) )
V_123 -> V_126 ( V_121 , V_277 ) ;
}
}
void F_111 ( struct V_1 * V_1 )
{
int V_16 , V_254 , V_278 = V_1 -> V_43 -> V_278 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_279 ; V_16 ++ ) {
struct V_280 * V_281 = & V_1 -> V_281 [ V_16 ] ;
struct V_282 * V_283 = & V_1 -> V_283 [ V_16 ] ;
V_254 = sizeof( struct V_72 ) * V_284 ;
memset ( V_1 -> V_97 [ V_16 ] , 0 , V_254 ) ;
V_283 -> V_285 = 0 ;
V_254 = V_1 -> V_43 -> V_286 * V_284 ;
memset ( V_1 -> V_287 [ V_16 ] , 0 , V_254 ) ;
V_281 -> V_288 = 0 ;
}
V_254 = sizeof( struct V_289 ) * V_1 -> V_179 ;
memset ( V_1 -> V_290 , 0 , V_254 ) ;
V_254 = V_278 * sizeof( struct V_291 ) ;
memset ( V_1 -> V_292 , 0 , V_254 ) ;
V_254 = V_278 * sizeof( struct V_293 ) ;
memset ( V_1 -> V_294 , 0 , V_254 ) ;
V_254 = V_278 * sizeof( struct V_293 ) * 2 ;
memset ( V_1 -> V_295 , 0 , V_254 ) ;
}
static int F_112 ( struct V_1 * V_1 , struct V_171 * V_172 )
{
struct V_296 * V_22 = V_1 -> V_22 ;
struct V_3 * V_21 = & V_22 -> V_21 ;
int V_16 , V_254 , V_278 = V_1 -> V_43 -> V_278 ;
F_113 ( & V_1 -> V_69 ) ;
for ( V_16 = 0 ; V_16 < V_1 -> V_179 ; V_16 ++ ) {
F_59 ( V_1 , V_16 ) ;
V_1 -> V_4 [ V_16 ] . V_87 = 0 ;
V_1 -> V_4 [ V_16 ] . V_88 = - 1 ;
}
for ( V_16 = 0 ; V_16 < V_152 ; V_16 ++ ) {
V_1 -> V_153 [ V_16 ] . V_84 = V_154 ;
V_1 -> V_153 [ V_16 ] . V_50 = V_16 ;
V_1 -> V_153 [ V_16 ] . V_155 = V_156 ;
}
for ( V_16 = 0 ; V_16 < V_1 -> V_279 ; V_16 ++ ) {
struct V_280 * V_281 = & V_1 -> V_281 [ V_16 ] ;
struct V_282 * V_283 = & V_1 -> V_283 [ V_16 ] ;
V_281 -> V_88 = V_16 ;
V_281 -> V_1 = V_1 ;
V_283 -> V_88 = V_16 ;
V_283 -> V_1 = V_1 ;
V_254 = sizeof( struct V_72 ) * V_284 ;
V_1 -> V_97 [ V_16 ] = F_114 ( V_21 , V_254 ,
& V_1 -> V_297 [ V_16 ] , V_223 ) ;
if ( ! V_1 -> V_97 [ V_16 ] )
goto V_93;
V_254 = V_1 -> V_43 -> V_286 * V_284 ;
V_1 -> V_287 [ V_16 ] = F_114 ( V_21 , V_254 ,
& V_1 -> V_298 [ V_16 ] , V_223 ) ;
if ( ! V_1 -> V_287 [ V_16 ] )
goto V_93;
}
V_254 = V_100 ;
V_1 -> V_36 = F_115 ( L_36 ,
V_21 , V_254 , 16 , 0 ) ;
if ( ! V_1 -> V_36 )
goto V_93;
V_254 = V_102 ;
V_1 -> V_33 = F_115 ( L_37 ,
V_21 , V_254 , 16 , 0 ) ;
if ( ! V_1 -> V_33 )
goto V_93;
V_254 = V_299 * sizeof( struct V_300 ) ;
V_1 -> V_301 = F_114 ( V_21 , V_254 , & V_1 -> V_302 ,
V_223 ) ;
if ( ! V_1 -> V_301 )
goto V_93;
memset ( V_1 -> V_301 , 0 , V_254 ) ;
V_1 -> V_96 = F_116 ( V_21 , V_278 ,
sizeof( struct V_19 ) ,
V_223 ) ;
if ( ! V_1 -> V_96 )
goto V_93;
V_254 = V_278 * sizeof( struct V_291 ) ;
V_1 -> V_292 = F_114 ( V_21 , V_254 , & V_1 -> V_303 ,
V_223 ) ;
if ( ! V_1 -> V_292 )
goto V_93;
V_254 = V_278 * sizeof( struct V_293 ) ;
V_1 -> V_294 = F_114 ( V_21 , V_254 ,
& V_1 -> V_304 , V_223 ) ;
if ( ! V_1 -> V_294 )
goto V_93;
V_1 -> V_14 = V_278 ;
V_254 = V_1 -> V_14 / V_305 ;
V_1 -> V_12 = F_117 ( V_21 , V_254 , V_223 ) ;
if ( ! V_1 -> V_12 )
goto V_93;
V_1 -> V_39 = F_115 ( L_38 , V_21 ,
sizeof( struct V_306 ) , 16 , 0 ) ;
if ( ! V_1 -> V_39 )
goto V_93;
V_254 = sizeof( struct V_289 ) * V_307 ;
V_1 -> V_290 = F_114 ( V_21 , V_254 ,
& V_1 -> V_308 , V_223 ) ;
if ( ! V_1 -> V_290 )
goto V_93;
V_254 = V_278 * sizeof( struct V_293 ) * 2 ;
V_1 -> V_295 = F_114 ( V_21 , V_254 ,
& V_1 -> V_309 , V_223 ) ;
if ( ! V_1 -> V_295 )
goto V_93;
F_111 ( V_1 ) ;
F_11 ( V_1 ) ;
V_1 -> V_310 = F_118 ( F_119 ( V_21 ) ) ;
if ( ! V_1 -> V_310 ) {
F_23 ( V_21 , L_39 ) ;
goto V_93;
}
return 0 ;
V_93:
return - V_90 ;
}
static void F_120 ( struct V_1 * V_1 )
{
struct V_3 * V_21 = & V_1 -> V_22 -> V_21 ;
int V_16 , V_254 , V_278 = V_1 -> V_43 -> V_278 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_279 ; V_16 ++ ) {
V_254 = sizeof( struct V_72 ) * V_284 ;
if ( V_1 -> V_97 [ V_16 ] )
F_121 ( V_21 , V_254 ,
V_1 -> V_97 [ V_16 ] ,
V_1 -> V_297 [ V_16 ] ) ;
V_254 = V_1 -> V_43 -> V_286 * V_284 ;
if ( V_1 -> V_287 [ V_16 ] )
F_121 ( V_21 , V_254 ,
V_1 -> V_287 [ V_16 ] ,
V_1 -> V_298 [ V_16 ] ) ;
}
F_122 ( V_1 -> V_36 ) ;
F_122 ( V_1 -> V_33 ) ;
F_122 ( V_1 -> V_39 ) ;
V_254 = V_299 * sizeof( struct V_300 ) ;
if ( V_1 -> V_301 )
F_121 ( V_21 , V_254 ,
V_1 -> V_301 , V_1 -> V_302 ) ;
V_254 = V_278 * sizeof( struct V_291 ) ;
if ( V_1 -> V_292 )
F_121 ( V_21 , V_254 ,
V_1 -> V_292 , V_1 -> V_303 ) ;
V_254 = V_278 * sizeof( struct V_293 ) ;
if ( V_1 -> V_294 )
F_121 ( V_21 , V_254 ,
V_1 -> V_294 ,
V_1 -> V_304 ) ;
V_254 = sizeof( struct V_289 ) * V_307 ;
if ( V_1 -> V_290 )
F_121 ( V_21 , V_254 ,
V_1 -> V_290 ,
V_1 -> V_308 ) ;
V_254 = V_278 * sizeof( struct V_293 ) * 2 ;
if ( V_1 -> V_295 )
F_121 ( V_21 , V_254 ,
V_1 -> V_295 ,
V_1 -> V_309 ) ;
if ( V_1 -> V_310 )
F_123 ( V_1 -> V_310 ) ;
}
static void F_124 ( struct V_54 * V_55 )
{
struct V_1 * V_1 =
F_3 ( V_55 , struct V_1 , V_311 ) ;
F_87 ( V_1 ) ;
}
static struct V_171 * F_125 ( struct V_296 * V_22 ,
const struct V_312 * V_43 )
{
struct V_313 * V_220 ;
struct V_171 * V_172 ;
struct V_1 * V_1 ;
struct V_3 * V_21 = & V_22 -> V_21 ;
struct V_314 * V_315 = V_22 -> V_21 . V_316 ;
struct V_317 * V_318 ;
V_172 = F_126 ( & V_319 , sizeof( * V_1 ) ) ;
if ( ! V_172 ) {
F_23 ( V_21 , L_40 ) ;
return NULL ;
}
V_1 = F_55 ( V_172 ) ;
F_35 ( & V_1 -> V_311 , F_124 ) ;
V_1 -> V_43 = V_43 ;
V_1 -> V_22 = V_22 ;
V_1 -> V_172 = V_172 ;
F_127 ( V_172 ) = & V_1 -> V_125 ;
F_60 ( & V_1 -> V_177 ) ;
if ( F_128 ( V_21 , L_41 , V_1 -> V_86 ,
V_320 ) )
goto V_93;
if ( V_315 ) {
V_1 -> V_321 = F_129 ( V_315 ,
L_42 ) ;
if ( F_130 ( V_1 -> V_321 ) )
goto V_93;
if ( F_131 ( V_21 , L_43 ,
& V_1 -> V_322 ) )
goto V_93;
if ( F_131 ( V_21 , L_44 ,
& V_1 -> V_323 ) )
goto V_93;
if ( F_131 ( V_21 , L_45 ,
& V_1 -> V_324 ) )
goto V_93;
}
V_318 = F_132 ( & V_22 -> V_21 , NULL ) ;
if ( F_130 ( V_318 ) )
F_89 ( V_21 , L_46 ) ;
else
V_1 -> V_325 = F_133 ( V_318 ) / 1000000 ;
if ( F_131 ( V_21 , L_47 , & V_1 -> V_179 ) )
goto V_93;
if ( F_131 ( V_21 , L_48 ,
& V_1 -> V_279 ) )
goto V_93;
if ( F_134 ( V_21 , F_135 ( 64 ) ) &&
F_134 ( V_21 , F_135 ( 32 ) ) ) {
F_23 ( V_21 , L_49 ) ;
goto V_93;
}
V_220 = F_136 ( V_22 , V_326 , 0 ) ;
V_1 -> V_327 = F_137 ( V_21 , V_220 ) ;
if ( F_130 ( V_1 -> V_327 ) )
goto V_93;
if ( F_112 ( V_1 , V_172 ) ) {
F_120 ( V_1 ) ;
goto V_93;
}
return V_172 ;
V_93:
F_138 ( V_172 ) ;
F_23 ( V_21 , L_50 ) ;
return NULL ;
}
static void F_139 ( struct V_1 * V_1 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_179 ; V_16 ++ )
memcpy ( & V_1 -> V_119 [ V_16 ] . V_328 ,
V_1 -> V_86 ,
V_320 ) ;
}
int F_140 ( struct V_296 * V_22 ,
const struct V_312 * V_43 )
{
struct V_171 * V_172 ;
struct V_1 * V_1 ;
struct V_3 * V_21 = & V_22 -> V_21 ;
struct V_120 * * V_329 ;
struct V_8 * * V_330 ;
struct V_122 * V_125 ;
int V_76 , V_331 , V_332 , V_16 ;
V_172 = F_125 ( V_22 , V_43 ) ;
if ( ! V_172 )
return - V_90 ;
V_125 = F_127 ( V_172 ) ;
V_1 = F_55 ( V_172 ) ;
F_141 ( V_22 , V_125 ) ;
V_331 = V_332 = V_1 -> V_179 ;
V_329 = F_116 ( V_21 , V_331 , sizeof( void * ) , V_223 ) ;
V_330 = F_116 ( V_21 , V_332 , sizeof( void * ) , V_223 ) ;
if ( ! V_329 || ! V_330 ) {
V_76 = - V_90 ;
goto V_333;
}
V_125 -> V_121 = V_329 ;
V_125 -> V_9 = V_330 ;
V_125 -> V_6 = V_1 ;
V_172 -> V_334 = V_335 ;
V_172 -> V_336 = V_152 ;
V_172 -> V_337 = ~ 0 ;
V_172 -> V_338 = 1 ;
V_172 -> V_339 = 16 ;
V_172 -> V_340 = F_142 ( V_341 , V_342 , V_343 ) ;
V_172 -> V_344 = V_1 -> V_43 -> V_278 ;
V_172 -> V_345 = V_1 -> V_43 -> V_278 ;
V_125 -> V_346 = V_347 ;
V_125 -> V_21 = & V_1 -> V_22 -> V_21 ;
V_125 -> V_348 = V_349 ;
V_125 -> V_86 = & V_1 -> V_86 [ 0 ] ;
V_125 -> V_164 = V_1 -> V_179 ;
V_125 -> V_350 . V_172 = V_1 -> V_172 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_179 ; V_16 ++ ) {
V_125 -> V_121 [ V_16 ] = & V_1 -> V_119 [ V_16 ] . V_121 ;
V_125 -> V_9 [ V_16 ] = & V_1 -> V_4 [ V_16 ] . V_9 ;
}
F_139 ( V_1 ) ;
V_76 = F_143 ( V_172 , & V_22 -> V_21 ) ;
if ( V_76 )
goto V_333;
V_76 = F_144 ( V_125 ) ;
if ( V_76 )
goto V_351;
V_76 = V_1 -> V_43 -> V_352 ( V_1 ) ;
if ( V_76 )
goto V_351;
F_145 ( V_172 ) ;
return 0 ;
V_351:
F_146 ( V_172 ) ;
V_333:
F_120 ( V_1 ) ;
F_138 ( V_172 ) ;
return V_76 ;
}
int F_147 ( struct V_296 * V_22 )
{
struct V_122 * V_125 = F_148 ( V_22 ) ;
struct V_1 * V_1 = V_125 -> V_6 ;
struct V_171 * V_172 = V_125 -> V_350 . V_172 ;
F_149 ( V_125 ) ;
F_150 ( V_125 -> V_350 . V_172 ) ;
F_120 ( V_1 ) ;
F_138 ( V_172 ) ;
return 0 ;
}
static T_5 int F_151 ( void )
{
F_152 ( L_51 , V_353 ) ;
V_335 = F_153 ( & V_354 ) ;
if ( ! V_335 )
return - V_90 ;
return 0 ;
}
static T_6 void F_154 ( void )
{
F_155 ( V_335 ) ;
}
