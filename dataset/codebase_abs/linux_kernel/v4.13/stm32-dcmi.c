static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline T_1 F_3 ( void T_2 * V_5 , T_1 V_6 )
{
return F_4 ( V_5 + V_6 ) ;
}
static inline void F_5 ( void T_2 * V_5 , T_1 V_6 , T_1 V_7 )
{
F_6 ( V_7 , V_5 + V_6 ) ;
}
static inline void F_7 ( void T_2 * V_5 , T_1 V_6 , T_1 V_8 )
{
F_5 ( V_5 , V_6 , F_3 ( V_5 , V_6 ) | V_8 ) ;
}
static inline void F_8 ( void T_2 * V_5 , T_1 V_6 , T_1 V_8 )
{
F_5 ( V_5 , V_6 , F_3 ( V_5 , V_6 ) & ~ V_8 ) ;
}
static void F_9 ( void * V_9 )
{
struct V_1 * V_10 = (struct V_1 * ) V_9 ;
struct V_11 * V_12 = V_10 -> V_11 ;
struct V_13 V_14 ;
enum V_15 V_16 ;
F_10 ( & V_10 -> V_17 ) ;
V_16 = F_11 ( V_12 , V_10 -> V_18 , & V_14 ) ;
switch ( V_16 ) {
case V_19 :
F_12 ( V_10 -> V_20 , L_1 , V_21 ) ;
break;
case V_22 :
F_13 ( V_10 -> V_20 , L_2 , V_21 ) ;
break;
case V_23 :
F_13 ( V_10 -> V_20 , L_3 , V_21 ) ;
break;
case V_24 :
F_12 ( V_10 -> V_20 , L_4 , V_21 ) ;
if ( V_10 -> V_25 ) {
struct V_26 * V_27 = V_10 -> V_25 ;
struct V_28 * V_29 = & V_10 -> V_25 -> V_30 ;
V_29 -> V_31 = V_10 -> V_31 ++ ;
V_29 -> V_32 = V_33 ;
V_29 -> V_34 . V_35 = F_14 () ;
F_15 ( & V_29 -> V_34 , 0 , V_27 -> V_36 ) ;
F_16 ( & V_29 -> V_34 , V_37 ) ;
F_12 ( V_10 -> V_20 , L_5 ,
V_29 -> V_34 . V_38 , V_29 -> V_31 ) ;
V_10 -> V_39 ++ ;
V_10 -> V_25 = NULL ;
}
if ( V_10 -> V_14 == V_40 ) {
if ( F_17 ( & V_10 -> V_41 ) ) {
F_13 ( V_10 -> V_20 , L_6 ,
V_21 ) ;
V_10 -> V_42 ++ ;
V_10 -> V_25 = NULL ;
F_18 ( & V_10 -> V_17 ) ;
return;
}
V_10 -> V_25 = F_19 ( V_10 -> V_41 . V_43 ,
struct V_26 , V_44 ) ;
F_20 ( & V_10 -> V_25 -> V_44 ) ;
if ( F_21 ( V_10 ) ) {
F_13 ( V_10 -> V_20 , L_7 ,
V_21 ) ;
F_18 ( & V_10 -> V_17 ) ;
return;
}
F_7 ( V_10 -> V_45 , V_46 , V_47 ) ;
}
break;
default:
F_13 ( V_10 -> V_20 , L_8 , V_21 ) ;
break;
}
F_18 ( & V_10 -> V_17 ) ;
}
static int F_22 ( struct V_1 * V_10 ,
struct V_26 * V_27 )
{
struct V_48 * V_49 = NULL ;
struct V_50 V_51 ;
int V_52 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_53 = ( V_54 ) V_10 -> V_55 -> V_56 + V_57 ;
V_51 . V_58 = V_59 ;
V_51 . V_60 = V_59 ;
V_51 . V_61 = 4 ;
V_52 = F_23 ( V_10 -> V_11 , & V_51 ) ;
if ( V_52 < 0 ) {
F_13 ( V_10 -> V_20 , L_9 ,
V_21 , V_52 ) ;
return V_52 ;
}
V_49 = F_24 ( V_10 -> V_11 , V_27 -> V_62 ,
V_27 -> V_36 ,
V_63 , V_64 ) ;
if ( ! V_49 ) {
F_13 ( V_10 -> V_20 , L_10 ,
V_21 , V_27 -> V_36 ) ;
return - V_65 ;
}
V_49 -> V_66 = F_9 ;
V_49 -> V_67 = V_10 ;
V_10 -> V_18 = F_25 ( V_49 ) ;
F_26 ( V_10 -> V_11 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_10 )
{
int V_52 ;
struct V_26 * V_27 = V_10 -> V_25 ;
if ( ! V_27 )
return - V_65 ;
V_52 = F_22 ( V_10 , V_27 ) ;
if ( V_52 ) {
V_10 -> V_42 ++ ;
return V_52 ;
}
F_7 ( V_10 -> V_45 , V_46 , V_47 ) ;
return 0 ;
}
static T_3 F_27 ( int V_68 , void * V_69 )
{
struct V_1 * V_10 = V_69 ;
F_10 ( & V_10 -> V_17 ) ;
if ( V_10 -> V_14 == V_70 ) {
F_8 ( V_10 -> V_45 , V_71 , V_72 | V_73 | V_74 ) ;
V_10 -> V_14 = V_75 ;
F_28 ( & V_10 -> F_28 ) ;
F_18 ( & V_10 -> V_17 ) ;
return V_76 ;
}
if ( ( V_10 -> V_77 & V_73 ) || ( V_10 -> V_77 & V_74 ) ) {
F_29 ( V_10 -> V_20 , L_11 ,
V_21 ) ;
V_10 -> V_42 ++ ;
F_30 ( V_10 -> V_11 ) ;
F_7 ( V_10 -> V_45 , V_78 , V_72 | V_73 | V_74 ) ;
F_12 ( V_10 -> V_20 , L_12 ) ;
if ( F_21 ( V_10 ) ) {
F_13 ( V_10 -> V_20 , L_13 ,
V_21 ) ;
F_18 ( & V_10 -> V_17 ) ;
return V_76 ;
}
}
F_18 ( & V_10 -> V_17 ) ;
return V_76 ;
}
static T_3 F_31 ( int V_68 , void * V_69 )
{
struct V_1 * V_10 = V_69 ;
F_10 ( & V_10 -> V_17 ) ;
V_10 -> V_77 = F_3 ( V_10 -> V_45 , V_79 ) ;
F_7 ( V_10 -> V_45 , V_78 , V_72 | V_73 | V_74 ) ;
F_18 ( & V_10 -> V_17 ) ;
return V_80 ;
}
static int F_32 ( struct V_81 * V_82 ,
unsigned int * V_83 ,
unsigned int * V_84 ,
unsigned int V_85 [] ,
struct V_86 * V_87 [] )
{
struct V_1 * V_10 = F_33 ( V_82 ) ;
unsigned int V_36 ;
V_36 = V_10 -> V_88 . V_88 . V_89 . V_90 ;
if ( * V_84 )
return V_85 [ 0 ] < V_36 ? - V_65 : 0 ;
* V_84 = 1 ;
V_85 [ 0 ] = V_36 ;
V_10 -> V_25 = NULL ;
F_12 ( V_10 -> V_20 , L_14 ,
* V_83 , V_36 ) ;
return 0 ;
}
static int F_34 ( struct V_91 * V_30 )
{
struct V_28 * V_29 = F_35 ( V_30 ) ;
struct V_26 * V_27 = F_2 ( V_29 , struct V_26 , V_30 ) ;
F_36 ( & V_27 -> V_44 ) ;
return 0 ;
}
static int F_37 ( struct V_91 * V_30 )
{
struct V_1 * V_10 = F_33 ( V_30 -> V_81 ) ;
struct V_28 * V_29 = F_35 ( V_30 ) ;
struct V_26 * V_27 = F_2 ( V_29 , struct V_26 , V_30 ) ;
unsigned long V_36 ;
V_36 = V_10 -> V_88 . V_88 . V_89 . V_90 ;
if ( F_38 ( V_30 , 0 ) < V_36 ) {
F_13 ( V_10 -> V_20 , L_15 ,
V_21 , F_38 ( V_30 , 0 ) , V_36 ) ;
return - V_65 ;
}
F_15 ( V_30 , 0 , V_36 ) ;
if ( ! V_27 -> V_92 ) {
V_27 -> V_62 =
F_39 ( & V_27 -> V_30 . V_34 , 0 ) ;
V_27 -> V_36 = F_38 ( & V_27 -> V_30 . V_34 , 0 ) ;
V_27 -> V_92 = true ;
F_15 ( & V_27 -> V_30 . V_34 , 0 , V_27 -> V_36 ) ;
F_12 ( V_10 -> V_20 , L_16 ,
V_30 -> V_38 , & V_27 -> V_62 , V_27 -> V_36 ) ;
}
return 0 ;
}
static void F_40 ( struct V_91 * V_30 )
{
struct V_1 * V_10 = F_33 ( V_30 -> V_81 ) ;
struct V_28 * V_29 = F_35 ( V_30 ) ;
struct V_26 * V_27 = F_2 ( V_29 , struct V_26 , V_30 ) ;
unsigned long V_93 = 0 ;
F_41 ( & V_10 -> V_17 , V_93 ) ;
if ( ( V_10 -> V_14 == V_40 ) && ( ! V_10 -> V_25 ) ) {
V_10 -> V_25 = V_27 ;
F_12 ( V_10 -> V_20 , L_17 ,
V_27 -> V_30 . V_34 . V_38 ) ;
if ( F_21 ( V_10 ) ) {
F_13 ( V_10 -> V_20 , L_13 ,
V_21 ) ;
F_42 ( & V_10 -> V_17 , V_93 ) ;
return;
}
} else {
F_43 ( & V_27 -> V_44 , & V_10 -> V_41 ) ;
}
F_42 ( & V_10 -> V_17 , V_93 ) ;
}
static int F_44 ( struct V_81 * V_82 , unsigned int V_94 )
{
struct V_1 * V_10 = F_33 ( V_82 ) ;
struct V_26 * V_27 , * V_95 ;
T_1 V_7 ;
int V_52 ;
V_52 = F_45 ( V_10 -> V_96 ) ;
if ( V_52 ) {
F_13 ( V_10 -> V_20 , L_18 ,
V_21 ) ;
goto V_97;
}
V_52 = F_46 ( V_10 -> V_98 . V_99 , V_100 , V_101 , 1 ) ;
if ( V_52 && V_52 != - V_102 ) {
F_13 ( V_10 -> V_20 , L_19 ,
V_21 ) ;
goto V_103;
}
F_47 ( & V_10 -> V_17 ) ;
V_7 = F_3 ( V_10 -> V_45 , V_46 ) ;
V_7 &= ~ ( V_104 | V_105 | V_106 |
V_107 | V_108 | V_109 |
V_110 | V_111 | V_112 ) ;
switch ( V_10 -> V_113 . V_114 ) {
case 14 :
V_7 &= V_107 + V_108 ;
break;
case 12 :
V_7 &= V_108 ;
break;
case 10 :
V_7 &= V_107 ;
break;
default:
break;
}
if ( V_10 -> V_113 . V_93 & V_115 )
V_7 |= V_106 ;
if ( V_10 -> V_113 . V_93 & V_116 )
V_7 |= V_105 ;
if ( V_10 -> V_113 . V_93 & V_117 )
V_7 |= V_104 ;
F_5 ( V_10 -> V_45 , V_46 , V_7 ) ;
F_7 ( V_10 -> V_45 , V_46 , V_118 ) ;
V_10 -> V_14 = V_40 ;
V_10 -> V_31 = 0 ;
V_10 -> V_42 = 0 ;
V_10 -> V_39 = 0 ;
V_10 -> V_25 = NULL ;
if ( F_17 ( & V_10 -> V_41 ) ) {
F_12 ( V_10 -> V_20 , L_20 ) ;
F_48 ( & V_10 -> V_17 ) ;
return 0 ;
}
V_10 -> V_25 = F_19 ( V_10 -> V_41 . V_43 , struct V_26 , V_44 ) ;
F_20 ( & V_10 -> V_25 -> V_44 ) ;
F_12 ( V_10 -> V_20 , L_21 ) ;
V_52 = F_21 ( V_10 ) ;
if ( V_52 ) {
F_13 ( V_10 -> V_20 , L_22 ,
V_21 ) ;
F_48 ( & V_10 -> V_17 ) ;
goto V_119;
}
F_7 ( V_10 -> V_45 , V_71 , V_72 | V_73 | V_74 ) ;
F_48 ( & V_10 -> V_17 ) ;
return 0 ;
V_119:
F_46 ( V_10 -> V_98 . V_99 , V_100 , V_101 , 0 ) ;
V_103:
F_49 ( V_10 -> V_96 ) ;
V_97:
F_47 ( & V_10 -> V_17 ) ;
if ( V_10 -> V_25 ) {
V_27 = V_10 -> V_25 ;
F_16 ( & V_27 -> V_30 . V_34 , V_120 ) ;
V_10 -> V_25 = NULL ;
}
F_50 (buf, node, &dcmi->buffers, list) {
F_20 ( & V_27 -> V_44 ) ;
F_16 ( & V_27 -> V_30 . V_34 , V_120 ) ;
}
F_48 ( & V_10 -> V_17 ) ;
return V_52 ;
}
static void F_51 ( struct V_81 * V_82 )
{
struct V_1 * V_10 = F_33 ( V_82 ) ;
struct V_26 * V_27 , * V_95 ;
unsigned long V_121 = F_52 ( V_122 ) ;
long V_123 ;
int V_52 ;
V_52 = F_46 ( V_10 -> V_98 . V_99 , V_100 , V_101 , 0 ) ;
if ( V_52 && V_52 != - V_102 )
F_13 ( V_10 -> V_20 , L_23 ) ;
V_10 -> V_14 = V_70 ;
V_123 = F_53 ( & V_10 -> F_28 ,
V_121 ) ;
F_47 ( & V_10 -> V_17 ) ;
F_8 ( V_10 -> V_45 , V_71 , V_72 | V_73 | V_74 ) ;
F_8 ( V_10 -> V_45 , V_46 , V_118 ) ;
if ( ! V_123 ) {
F_13 ( V_10 -> V_20 , L_24 ) ;
V_10 -> V_14 = V_75 ;
}
if ( V_10 -> V_25 ) {
V_27 = V_10 -> V_25 ;
F_16 ( & V_27 -> V_30 . V_34 , V_124 ) ;
V_10 -> V_25 = NULL ;
}
F_50 (buf, node, &dcmi->buffers, list) {
F_20 ( & V_27 -> V_44 ) ;
F_16 ( & V_27 -> V_30 . V_34 , V_124 ) ;
}
F_48 ( & V_10 -> V_17 ) ;
F_30 ( V_10 -> V_11 ) ;
F_49 ( V_10 -> V_96 ) ;
F_12 ( V_10 -> V_20 , L_25 ,
V_10 -> V_42 , V_10 -> V_39 ) ;
}
static int F_54 ( struct V_125 * V_125 , void * V_126 ,
struct V_127 * V_88 )
{
struct V_1 * V_10 = F_55 ( V_125 ) ;
* V_88 = V_10 -> V_88 ;
return 0 ;
}
static const struct V_128 * F_56 ( struct V_1 * V_10 ,
unsigned int V_129 )
{
unsigned int V_130 = V_10 -> V_131 ;
const struct V_128 * V_88 ;
unsigned int V_132 ;
for ( V_132 = 0 ; V_132 < V_130 ; V_132 ++ ) {
V_88 = V_10 -> V_133 [ V_132 ] ;
if ( V_88 -> V_129 == V_129 )
return V_88 ;
}
return NULL ;
}
static int F_57 ( struct V_1 * V_10 , struct V_127 * V_134 ,
const struct V_128 * * V_135 )
{
const struct V_128 * V_136 ;
struct V_137 * V_138 = & V_134 -> V_88 . V_89 ;
struct V_139 V_140 ;
struct V_141 V_142 = {
. V_143 = V_144 ,
} ;
int V_52 ;
V_136 = F_56 ( V_10 , V_138 -> V_145 ) ;
if ( ! V_136 ) {
V_136 = V_10 -> V_133 [ V_10 -> V_131 - 1 ] ;
V_138 -> V_145 = V_136 -> V_129 ;
}
V_138 -> V_146 = F_58 ( V_138 -> V_146 , V_147 , V_148 ) ;
V_138 -> V_149 = F_58 ( V_138 -> V_149 , V_150 , V_151 ) ;
F_59 ( & V_142 . V_142 , V_138 , V_136 -> V_152 ) ;
V_52 = F_46 ( V_10 -> V_98 . V_99 , V_153 , V_154 ,
& V_140 , & V_142 ) ;
if ( V_52 < 0 )
return V_52 ;
F_60 ( V_138 , & V_142 . V_142 ) ;
V_138 -> V_32 = V_33 ;
V_138 -> V_155 = V_138 -> V_146 * V_136 -> V_156 ;
V_138 -> V_90 = V_138 -> V_155 * V_138 -> V_149 ;
if ( V_135 )
* V_135 = V_136 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_10 , struct V_127 * V_134 )
{
struct V_141 V_142 = {
. V_143 = V_157 ,
} ;
const struct V_128 * V_135 ;
int V_52 ;
V_52 = F_57 ( V_10 , V_134 , & V_135 ) ;
if ( V_52 )
return V_52 ;
F_59 ( & V_142 . V_142 , & V_134 -> V_88 . V_89 ,
V_135 -> V_152 ) ;
V_52 = F_46 ( V_10 -> V_98 . V_99 , V_153 ,
V_154 , NULL , & V_142 ) ;
if ( V_52 < 0 )
return V_52 ;
V_10 -> V_88 = * V_134 ;
V_10 -> V_135 = V_135 ;
return 0 ;
}
static int F_62 ( struct V_125 * V_125 , void * V_126 ,
struct V_127 * V_134 )
{
struct V_1 * V_10 = F_55 ( V_125 ) ;
if ( F_63 ( & V_10 -> V_158 ) )
return - V_159 ;
return F_61 ( V_10 , V_134 ) ;
}
static int F_64 ( struct V_125 * V_125 , void * V_126 ,
struct V_127 * V_134 )
{
struct V_1 * V_10 = F_55 ( V_125 ) ;
return F_57 ( V_10 , V_134 , NULL ) ;
}
static int F_65 ( struct V_125 * V_125 , void * V_126 ,
struct V_160 * V_134 )
{
struct V_1 * V_10 = F_55 ( V_125 ) ;
if ( V_134 -> V_38 >= V_10 -> V_131 )
return - V_65 ;
V_134 -> V_145 = V_10 -> V_133 [ V_134 -> V_38 ] -> V_129 ;
return 0 ;
}
static int F_66 ( struct V_125 * V_125 , void * V_126 ,
struct V_161 * V_162 )
{
F_67 ( V_162 -> V_163 , V_164 , sizeof( V_162 -> V_163 ) ) ;
F_67 ( V_162 -> V_165 , L_26 ,
sizeof( V_162 -> V_165 ) ) ;
F_67 ( V_162 -> V_166 , L_27 , sizeof( V_162 -> V_166 ) ) ;
return 0 ;
}
static int F_68 ( struct V_125 * V_125 , void * V_126 ,
struct V_167 * V_132 )
{
if ( V_132 -> V_38 != 0 )
return - V_65 ;
V_132 -> type = V_168 ;
F_67 ( V_132 -> V_169 , L_28 , sizeof( V_132 -> V_169 ) ) ;
return 0 ;
}
static int F_69 ( struct V_125 * V_125 , void * V_126 , unsigned int * V_132 )
{
* V_132 = 0 ;
return 0 ;
}
static int F_70 ( struct V_125 * V_125 , void * V_126 , unsigned int V_132 )
{
if ( V_132 > 0 )
return - V_65 ;
return 0 ;
}
static int F_71 ( struct V_125 * V_125 , void * V_170 ,
struct V_171 * V_172 )
{
struct V_1 * V_10 = F_55 ( V_125 ) ;
const struct V_128 * V_136 ;
struct V_173 V_174 = {
. V_38 = V_172 -> V_38 ,
. V_143 = V_157 ,
} ;
int V_52 ;
V_136 = F_56 ( V_10 , V_172 -> V_175 ) ;
if ( ! V_136 )
return - V_65 ;
V_174 . V_176 = V_136 -> V_152 ;
V_52 = F_46 ( V_10 -> V_98 . V_99 , V_153 , V_177 ,
NULL , & V_174 ) ;
if ( V_52 )
return V_52 ;
V_172 -> type = V_178 ;
V_172 -> V_179 . V_146 = V_174 . V_180 ;
V_172 -> V_179 . V_149 = V_174 . V_181 ;
return 0 ;
}
static int F_72 ( struct V_125 * V_125 , void * V_170 ,
struct V_182 * V_183 )
{
struct V_1 * V_10 = F_55 ( V_125 ) ;
const struct V_128 * V_136 ;
struct V_184 V_185 = {
. V_38 = V_183 -> V_38 ,
. V_146 = V_183 -> V_146 ,
. V_149 = V_183 -> V_149 ,
. V_143 = V_157 ,
} ;
int V_52 ;
V_136 = F_56 ( V_10 , V_183 -> V_175 ) ;
if ( ! V_136 )
return - V_65 ;
V_185 . V_176 = V_136 -> V_152 ;
V_52 = F_46 ( V_10 -> V_98 . V_99 , V_153 ,
V_186 , NULL , & V_185 ) ;
if ( V_52 )
return V_52 ;
V_183 -> type = V_187 ;
V_183 -> V_179 = V_185 . V_188 ;
return 0 ;
}
static int F_73 ( struct V_125 * V_125 )
{
struct V_1 * V_10 = F_55 ( V_125 ) ;
struct V_189 * V_190 = V_10 -> V_98 . V_99 ;
int V_52 ;
if ( F_74 ( & V_10 -> V_191 ) )
return - V_192 ;
V_52 = F_75 ( V_125 ) ;
if ( V_52 < 0 )
goto V_193;
if ( ! F_76 ( V_125 ) )
goto V_194;
V_52 = F_46 ( V_190 , V_195 , V_196 , 1 ) ;
if ( V_52 < 0 && V_52 != - V_102 )
goto V_194;
V_52 = F_61 ( V_10 , & V_10 -> V_88 ) ;
if ( V_52 )
F_46 ( V_190 , V_195 , V_196 , 0 ) ;
V_194:
if ( V_52 )
F_77 ( V_125 ) ;
V_193:
F_78 ( & V_10 -> V_191 ) ;
return V_52 ;
}
static int F_79 ( struct V_125 * V_125 )
{
struct V_1 * V_10 = F_55 ( V_125 ) ;
struct V_189 * V_190 = V_10 -> V_98 . V_99 ;
bool V_197 ;
int V_52 ;
F_80 ( & V_10 -> V_191 ) ;
V_197 = F_76 ( V_125 ) ;
V_52 = F_81 ( V_125 , NULL ) ;
if ( V_197 )
F_46 ( V_190 , V_195 , V_196 , 0 ) ;
F_78 ( & V_10 -> V_191 ) ;
return V_52 ;
}
static int F_82 ( struct V_1 * V_10 )
{
struct V_127 V_134 = {
. type = V_198 ,
. V_88 . V_89 = {
. V_146 = V_199 ,
. V_149 = V_200 ,
. V_32 = V_33 ,
. V_145 = V_10 -> V_133 [ 0 ] -> V_129 ,
} ,
} ;
int V_52 ;
V_52 = F_57 ( V_10 , & V_134 , NULL ) ;
if ( V_52 )
return V_52 ;
V_10 -> V_135 = V_10 -> V_133 [ 0 ] ;
V_10 -> V_88 = V_134 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_10 )
{
const struct V_128 * V_201 [ F_84 ( V_202 ) ] ;
unsigned int V_203 = 0 , V_132 , V_204 ;
struct V_189 * V_99 = V_10 -> V_98 . V_99 ;
struct V_205 V_152 = {
. V_143 = V_157 ,
} ;
while ( ! F_46 ( V_99 , V_153 , V_206 ,
NULL , & V_152 ) ) {
for ( V_132 = 0 ; V_132 < F_84 ( V_202 ) ; V_132 ++ ) {
if ( V_202 [ V_132 ] . V_152 != V_152 . V_176 )
continue;
for ( V_204 = 0 ; V_204 < V_203 ; V_204 ++ )
if ( V_201 [ V_204 ] -> V_129 ==
V_202 [ V_132 ] . V_129 )
break;
if ( V_204 == V_203 )
V_201 [ V_203 ++ ] = V_202 + V_132 ;
}
V_152 . V_38 ++ ;
}
if ( ! V_203 )
return - V_207 ;
V_10 -> V_131 = V_203 ;
V_10 -> V_133 = F_85 ( V_10 -> V_20 ,
V_203 , sizeof( struct V_128 * ) ,
V_208 ) ;
if ( ! V_10 -> V_133 ) {
F_13 ( V_10 -> V_20 , L_29 ) ;
return - V_209 ;
}
memcpy ( V_10 -> V_133 , V_201 ,
V_203 * sizeof( struct V_128 * ) ) ;
V_10 -> V_135 = V_10 -> V_133 [ 0 ] ;
return 0 ;
}
static int F_86 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_52 ;
V_10 -> V_210 -> V_211 = V_10 -> V_98 . V_99 -> V_211 ;
V_52 = F_83 ( V_10 ) ;
if ( V_52 ) {
F_13 ( V_10 -> V_20 , L_30 ) ;
return V_52 ;
}
V_52 = F_82 ( V_10 ) ;
if ( V_52 ) {
F_13 ( V_10 -> V_20 , L_31 ) ;
return V_52 ;
}
V_52 = F_87 ( V_10 -> V_210 , V_212 , - 1 ) ;
if ( V_52 ) {
F_13 ( V_10 -> V_20 , L_32 ) ;
return V_52 ;
}
F_12 ( V_10 -> V_20 , L_33 ,
F_88 ( V_10 -> V_210 ) ) ;
return 0 ;
}
static void F_89 ( struct V_2 * V_4 ,
struct V_189 * V_190 ,
struct V_213 * V_214 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_12 ( V_10 -> V_20 , L_34 , F_88 ( V_10 -> V_210 ) ) ;
F_90 ( V_10 -> V_210 ) ;
}
static int F_91 ( struct V_2 * V_4 ,
struct V_189 * V_99 ,
struct V_213 * V_214 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_12 ( V_10 -> V_20 , L_35 , V_99 -> V_169 ) ;
V_10 -> V_98 . V_99 = V_99 ;
return 0 ;
}
static int F_92 ( struct V_1 * V_10 , struct V_215 * V_95 )
{
struct V_215 * V_216 = NULL ;
struct V_215 * V_217 ;
while ( 1 ) {
V_216 = F_93 ( V_95 , V_216 ) ;
if ( ! V_216 )
return - V_65 ;
V_217 = F_94 ( V_216 ) ;
if ( ! V_217 ) {
F_95 ( V_216 ) ;
return - V_65 ;
}
V_10 -> V_98 . V_95 = V_217 ;
V_10 -> V_98 . V_214 . V_218 = V_219 ;
V_10 -> V_98 . V_214 . V_220 . V_221 . V_221 = F_96 ( V_217 ) ;
return 0 ;
}
}
static int F_97 ( struct V_1 * V_10 )
{
struct V_213 * * V_222 = NULL ;
int V_52 ;
V_52 = F_92 ( V_10 , V_10 -> V_20 -> V_223 ) ;
if ( V_52 < 0 ) {
F_13 ( V_10 -> V_20 , L_36 ) ;
return V_52 ;
}
V_222 = F_98 ( V_10 -> V_20 , sizeof( * V_222 ) , V_208 ) ;
if ( ! V_222 ) {
F_95 ( V_10 -> V_98 . V_95 ) ;
return - V_209 ;
}
V_222 [ 0 ] = & V_10 -> V_98 . V_214 ;
V_10 -> V_4 . V_222 = V_222 ;
V_10 -> V_4 . V_224 = 1 ;
V_10 -> V_4 . V_225 = F_91 ;
V_10 -> V_4 . V_226 = F_89 ;
V_10 -> V_4 . F_28 = F_86 ;
V_52 = F_99 ( & V_10 -> V_227 , & V_10 -> V_4 ) ;
if ( V_52 < 0 ) {
F_13 ( V_10 -> V_20 , L_37 ) ;
F_95 ( V_10 -> V_98 . V_95 ) ;
return V_52 ;
}
return 0 ;
}
static int F_100 ( struct V_228 * V_229 )
{
struct V_215 * V_230 = V_229 -> V_20 . V_223 ;
const struct V_231 * V_220 = NULL ;
struct V_232 V_216 ;
struct V_1 * V_10 ;
struct V_81 * V_233 ;
struct V_11 * V_12 ;
struct V_234 * V_96 ;
int V_68 ;
int V_52 = 0 ;
V_220 = F_101 ( F_102 ( V_235 ) , & V_229 -> V_20 ) ;
if ( ! V_220 ) {
F_13 ( & V_229 -> V_20 , L_38 ) ;
return - V_236 ;
}
V_10 = F_98 ( & V_229 -> V_20 , sizeof( struct V_1 ) , V_208 ) ;
if ( ! V_10 )
return - V_209 ;
V_10 -> V_237 = F_103 ( & V_229 -> V_20 , NULL ) ;
if ( F_104 ( V_10 -> V_237 ) ) {
F_13 ( & V_229 -> V_20 , L_39 ) ;
return - V_236 ;
}
V_230 = F_93 ( V_230 , NULL ) ;
if ( ! V_230 ) {
F_13 ( & V_229 -> V_20 , L_40 ) ;
F_95 ( V_230 ) ;
return - V_236 ;
}
V_52 = F_105 ( F_96 ( V_230 ) , & V_216 ) ;
if ( V_52 ) {
F_13 ( & V_229 -> V_20 , L_41 ) ;
F_95 ( V_230 ) ;
return - V_236 ;
}
if ( V_216 . V_238 == V_239 ) {
F_13 ( & V_229 -> V_20 , L_42 ) ;
F_95 ( V_230 ) ;
return - V_236 ;
}
V_10 -> V_113 . V_93 = V_216 . V_113 . V_240 . V_93 ;
V_10 -> V_113 . V_114 = V_216 . V_113 . V_240 . V_114 ;
V_10 -> V_113 . V_241 = V_216 . V_113 . V_240 . V_241 ;
F_95 ( V_230 ) ;
V_68 = F_106 ( V_229 , 0 ) ;
if ( V_68 <= 0 ) {
F_13 ( & V_229 -> V_20 , L_43 ) ;
return - V_236 ;
}
V_10 -> V_55 = F_107 ( V_229 , V_242 , 0 ) ;
if ( ! V_10 -> V_55 ) {
F_13 ( & V_229 -> V_20 , L_44 ) ;
return - V_236 ;
}
V_10 -> V_45 = F_108 ( & V_229 -> V_20 , V_10 -> V_55 ) ;
if ( F_104 ( V_10 -> V_45 ) ) {
F_13 ( & V_229 -> V_20 , L_45 ) ;
return F_109 ( V_10 -> V_45 ) ;
}
V_52 = F_110 ( & V_229 -> V_20 , V_68 , F_31 ,
F_27 , V_243 ,
F_111 ( & V_229 -> V_20 ) , V_10 ) ;
if ( V_52 ) {
F_13 ( & V_229 -> V_20 , L_46 , V_68 ) ;
return - V_236 ;
}
V_96 = F_112 ( & V_229 -> V_20 , L_47 ) ;
if ( F_104 ( V_96 ) ) {
F_13 ( & V_229 -> V_20 , L_48 ) ;
return F_109 ( V_96 ) ;
}
V_12 = F_113 ( & V_229 -> V_20 , L_49 ) ;
if ( ! V_12 ) {
F_114 ( & V_229 -> V_20 , L_50 ) ;
return - V_244 ;
}
V_52 = F_115 ( V_96 ) ;
if ( V_52 ) {
F_13 ( & V_229 -> V_20 , L_51 , V_96 ) ;
goto V_245;
}
F_116 ( & V_10 -> V_17 ) ;
F_117 ( & V_10 -> V_191 ) ;
F_118 ( & V_10 -> F_28 ) ;
F_36 ( & V_10 -> V_41 ) ;
V_10 -> V_20 = & V_229 -> V_20 ;
V_10 -> V_96 = V_96 ;
V_10 -> V_14 = V_75 ;
V_10 -> V_11 = V_12 ;
V_233 = & V_10 -> V_158 ;
V_52 = F_119 ( & V_229 -> V_20 , & V_10 -> V_227 ) ;
if ( V_52 )
goto V_246;
V_10 -> V_210 = F_120 () ;
if ( ! V_10 -> V_210 ) {
V_52 = - V_209 ;
goto V_247;
}
V_10 -> V_210 -> V_248 = & V_249 ;
V_10 -> V_210 -> V_227 = & V_10 -> V_227 ;
V_10 -> V_210 -> V_158 = & V_10 -> V_158 ;
F_67 ( V_10 -> V_210 -> V_169 , V_250 , sizeof( V_10 -> V_210 -> V_169 ) ) ;
V_10 -> V_210 -> V_251 = V_252 ;
V_10 -> V_210 -> V_253 = & V_254 ;
V_10 -> V_210 -> V_191 = & V_10 -> V_191 ;
V_10 -> V_210 -> V_255 = V_256 | V_257 |
V_258 ;
F_121 ( V_10 -> V_210 , V_10 ) ;
V_233 -> type = V_198 ;
V_233 -> V_259 = V_260 | V_261 | V_262 ;
V_233 -> V_191 = & V_10 -> V_191 ;
V_233 -> V_263 = V_10 ;
V_233 -> V_264 = sizeof( struct V_26 ) ;
V_233 -> V_265 = & V_266 ;
V_233 -> V_267 = & V_268 ;
V_233 -> V_269 = V_270 ;
V_233 -> V_271 = 2 ;
V_233 -> V_20 = & V_229 -> V_20 ;
V_52 = F_122 ( V_233 ) ;
if ( V_52 < 0 ) {
F_13 ( & V_229 -> V_20 , L_52 ) ;
goto V_272;
}
V_52 = F_97 ( V_10 ) ;
if ( V_52 < 0 )
goto V_272;
V_52 = F_123 ( V_10 -> V_237 ) ;
if ( V_52 ) {
F_13 ( & V_229 -> V_20 , L_53 ) ;
goto V_272;
}
F_124 ( 3000 , 5000 ) ;
V_52 = F_125 ( V_10 -> V_237 ) ;
if ( V_52 ) {
F_13 ( & V_229 -> V_20 , L_54 ) ;
goto V_272;
}
F_114 ( & V_229 -> V_20 , L_55 ) ;
F_126 ( V_229 , V_10 ) ;
return 0 ;
V_272:
V_252 ( V_10 -> V_210 ) ;
V_247:
F_127 ( & V_10 -> V_227 ) ;
V_246:
F_128 ( V_10 -> V_96 ) ;
V_245:
F_129 ( V_10 -> V_11 ) ;
return V_52 ;
}
static int F_130 ( struct V_228 * V_229 )
{
struct V_1 * V_10 = F_131 ( V_229 ) ;
F_132 ( & V_10 -> V_4 ) ;
F_127 ( & V_10 -> V_227 ) ;
F_128 ( V_10 -> V_96 ) ;
F_129 ( V_10 -> V_11 ) ;
return 0 ;
}
