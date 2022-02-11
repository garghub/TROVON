static inline int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_6 -> V_7 . V_4 ;
int V_8 ;
V_8 = F_2 ( V_4 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_3 ( V_2 ) ;
F_4 ( V_4 ) ;
return V_8 ;
}
static int F_5 ( struct V_9 * exp , struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_8 ;
V_2 = F_6 ( F_7 ( exp ) ,
& V_14 ,
V_15 , V_16 ) ;
if ( ! V_2 )
return - V_17 ;
F_8 ( V_2 , NULL , 0 , 0 , - 1 , 0 ) ;
V_2 -> V_18 = V_19 ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
goto V_20;
V_13 = F_10 ( & V_2 -> V_21 , & V_22 ) ;
if ( ! V_13 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_11 = V_13 -> V_24 ;
F_11 ( V_25 ,
L_1 V_26 L_2 ,
F_12 ( V_11 ) ,
F_13 ( V_2 -> V_27 ) ) ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_15 ( struct V_9 * exp ,
struct V_1 * V_2 )
{
struct V_28 * V_29 = & V_2 -> V_21 ;
struct V_12 * V_13 ;
void * V_30 ;
int V_8 ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 != 0 )
return V_8 ;
V_13 = F_10 ( V_29 , & V_22 ) ;
if ( ! V_13 )
return - V_23 ;
F_11 ( V_25 , L_3 , V_13 -> V_31 ) ;
F_16 ( exp , V_13 ) ;
if ( V_13 -> V_32 != 0 ) {
V_30 = F_17 ( V_29 , & V_33 ,
V_13 -> V_32 ) ;
if ( ! V_30 )
return - V_23 ;
}
return 0 ;
}
static int F_18 ( struct V_9 * exp , struct V_34 * V_35 ,
struct V_1 * * V_36 )
{
struct V_1 * V_2 ;
int V_8 ;
if ( V_35 -> V_37 & V_38 ) {
V_35 -> V_39 = 0 ;
return 0 ;
}
* V_36 = NULL ;
V_2 = F_19 ( F_7 ( exp ) , & V_40 ) ;
if ( ! V_2 )
return - V_17 ;
V_8 = F_20 ( V_2 , V_15 , V_41 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , & V_35 -> V_42 , V_35 -> V_43 ,
V_35 -> V_44 , - 1 , 0 ) ;
F_22 ( & V_2 -> V_21 , & V_33 , V_45 ,
V_35 -> V_44 ) ;
F_9 ( V_2 ) ;
V_8 = F_15 ( exp , V_2 ) ;
if ( V_8 )
F_14 ( V_2 ) ;
else
* V_36 = V_2 ;
return V_8 ;
}
static int F_23 ( struct V_9 * exp , struct V_34 * V_35 ,
struct V_1 * * V_36 )
{
struct V_1 * V_2 ;
int V_8 ;
* V_36 = NULL ;
V_2 = F_19 ( F_7 ( exp ) ,
& V_46 ) ;
if ( ! V_2 )
return - V_17 ;
F_22 ( & V_2 -> V_21 , & V_47 , V_48 ,
V_35 -> V_49 + 1 ) ;
V_8 = F_20 ( V_2 , V_15 , V_50 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , & V_35 -> V_42 , V_35 -> V_43 ,
V_35 -> V_44 , V_35 -> V_51 [ 0 ] , 0 ) ;
if ( V_35 -> V_52 ) {
char * V_53 = F_24 ( & V_2 -> V_21 , & V_47 ) ;
F_25 ( F_26 ( V_35 -> V_52 , V_35 -> V_49 ) ==
V_35 -> V_49 ) ;
memcpy ( V_53 , V_35 -> V_52 , V_35 -> V_49 ) ;
}
F_22 ( & V_2 -> V_21 , & V_33 , V_45 ,
V_35 -> V_44 ) ;
F_9 ( V_2 ) ;
V_8 = F_15 ( exp , V_2 ) ;
if ( V_8 )
F_14 ( V_2 ) ;
else
* V_36 = V_2 ;
return V_8 ;
}
static int F_27 ( struct V_9 * exp ,
const struct V_10 * V_54 ,
const struct V_10 * V_55 ,
struct V_1 * * V_36 )
{
struct V_1 * V_2 ;
int V_8 ;
* V_36 = NULL ;
V_2 = F_6 ( F_7 ( exp ) ,
& V_56 , V_15 ,
V_57 ) ;
if ( ! V_2 )
return - V_17 ;
F_28 ( V_2 , V_54 , V_55 , 0 ) ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 && V_8 != - V_58 )
F_14 ( V_2 ) ;
else
* V_36 = V_2 ;
return V_8 ;
}
static int F_29 ( struct V_9 * exp ,
const struct V_59 * V_60 ,
const struct V_10 * V_61 ,
int V_62 , T_1 V_63 ,
const char * V_64 , const char * V_65 ,
int V_66 , int V_67 , int V_68 ,
T_2 V_69 , struct V_1 * * V_36 )
{
struct V_1 * V_2 ;
int V_70 = 0 ;
char * V_71 ;
int V_8 ;
* V_36 = NULL ;
V_2 = F_19 ( F_7 ( exp ) , V_60 ) ;
if ( ! V_2 )
return - V_17 ;
if ( V_64 ) {
V_70 = strlen ( V_64 ) + 1 ;
F_22 ( & V_2 -> V_21 , & V_47 , V_48 ,
V_70 ) ;
}
if ( V_66 ) {
F_25 ( V_65 ) ;
F_22 ( & V_2 -> V_21 , & V_72 , V_48 ,
V_66 ) ;
}
if ( V_62 == V_73 && F_30 ( V_61 ) &&
exp -> V_74 . V_75 & V_76 ) {
F_31 ( V_77 ) ;
int V_78 ;
if ( V_66 == 0 )
F_22 ( & V_2 -> V_21 , & V_72 ,
V_48 , 0 ) ;
V_78 = F_32 ( exp , V_61 ,
& V_77 , V_79 ,
V_76 ) ;
V_8 = F_33 ( exp , V_2 , V_73 , & V_77 , V_78 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
} else {
V_8 = F_20 ( V_2 , V_15 , V_62 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
}
if ( V_62 == V_73 ) {
struct V_80 * V_81 ;
F_34 ( sizeof( struct V_80 ) ==
sizeof( struct V_82 ) ) ;
V_81 = F_24 ( & V_2 -> V_21 , & V_83 ) ;
V_81 -> V_84 = V_85 ;
V_81 -> V_86 = F_35 ( & V_87 , F_36 () ) ;
V_81 -> V_88 = F_37 ( & V_87 , F_38 () ) ;
V_81 -> V_89 = F_39 () ;
V_81 -> V_90 = V_69 ;
V_81 -> V_91 = - 1 ;
V_81 -> V_92 = * V_61 ;
V_81 -> V_93 = V_63 | V_94 ;
V_81 -> V_95 = F_40 () ;
V_81 -> V_96 = V_67 ;
V_81 -> V_97 = V_68 ;
} else {
F_8 ( V_2 , V_61 , V_63 , V_67 , V_69 , V_68 ) ;
}
if ( V_64 ) {
V_71 = F_24 ( & V_2 -> V_21 , & V_47 ) ;
memcpy ( V_71 , V_64 , V_70 ) ;
}
if ( V_66 ) {
V_71 = F_24 ( & V_2 -> V_21 , & V_72 ) ;
memcpy ( V_71 , V_65 , V_66 ) ;
}
if ( F_41 ( & V_2 -> V_21 , & V_72 , V_45 ) )
F_22 ( & V_2 -> V_21 , & V_72 ,
V_45 , V_67 ) ;
F_9 ( V_2 ) ;
if ( V_62 == V_73 )
F_42 ( exp -> V_98 -> V_7 . V_4 . V_99 , NULL ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_62 == V_73 )
F_43 ( exp -> V_98 -> V_7 . V_4 . V_99 , NULL ) ;
if ( V_8 )
F_14 ( V_2 ) ;
else
* V_36 = V_2 ;
return V_8 ;
}
static int F_44 ( struct V_9 * exp , const struct V_10 * V_61 ,
T_1 V_63 , const char * V_64 ,
const char * V_65 , int V_66 , int V_67 ,
int V_68 , T_2 V_69 ,
struct V_1 * * V_36 )
{
return F_29 ( exp , & V_100 ,
V_61 , V_73 , V_63 , V_64 ,
V_65 , V_66 , V_67 , V_68 ,
V_69 , V_36 ) ;
}
static int F_45 ( struct V_9 * exp , const struct V_10 * V_61 ,
T_1 V_63 , const char * V_64 ,
const char * V_65 , int V_66 , int V_67 ,
int V_68 , struct V_1 * * V_36 )
{
return F_29 ( exp , & V_101 ,
V_61 , V_102 , V_63 , V_64 ,
V_65 , V_66 , V_67 , V_68 ,
- 1 , V_36 ) ;
}
static int F_46 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
struct V_28 * V_29 = & V_2 -> V_21 ;
struct V_12 * V_13 = V_104 -> V_13 ;
struct V_105 * V_106 ;
void * V_107 ;
int V_8 ;
if ( ! V_13 -> V_108 )
return 0 ;
V_107 = F_17 ( V_29 , & V_109 , V_13 -> V_108 ) ;
if ( ! V_107 )
return - V_23 ;
V_106 = F_47 ( & V_87 , V_107 , V_13 -> V_108 ) ;
if ( ! V_106 )
return 0 ;
if ( F_48 ( V_106 ) ) {
V_8 = F_49 ( V_106 ) ;
F_50 ( L_4 , V_8 ) ;
return V_8 ;
}
V_8 = F_51 ( & V_87 , V_106 ) ;
if ( V_8 ) {
F_50 ( L_5 , V_8 ) ;
F_52 ( V_106 ) ;
return V_8 ;
}
V_104 -> V_105 = V_106 ;
return 0 ;
}
static int F_53 ( struct V_9 * exp ,
struct V_1 * V_2 ,
struct V_9 * V_110 ,
struct V_9 * V_111 ,
struct V_103 * V_104 )
{
struct V_28 * V_29 = & V_2 -> V_21 ;
int V_8 ;
F_25 ( V_104 ) ;
memset ( V_104 , 0 , sizeof( * V_104 ) ) ;
V_104 -> V_13 = F_10 ( V_29 , & V_22 ) ;
if ( V_104 -> V_13 -> V_63 & V_112 ) {
int V_113 ;
struct V_114 * V_115 ;
if ( ! F_54 ( V_104 -> V_13 -> V_31 ) ) {
F_11 ( V_116 ,
L_6 ) ;
V_8 = - V_23 ;
goto V_20;
}
if ( V_104 -> V_13 -> V_32 == 0 ) {
F_11 ( V_116 ,
L_7 ) ;
V_8 = - V_23 ;
goto V_20;
}
V_113 = V_104 -> V_13 -> V_32 ;
V_115 = F_17 ( V_29 , & V_33 , V_113 ) ;
if ( ! V_115 ) {
V_8 = - V_23 ;
goto V_20;
}
V_8 = F_55 ( V_110 , & V_104 -> V_117 , V_115 , V_113 ) ;
if ( V_8 < 0 )
goto V_20;
if ( V_8 < sizeof( * V_104 -> V_117 ) ) {
F_11 ( V_116 ,
L_8 ,
V_8 , ( int ) sizeof( * V_104 -> V_117 ) ) ;
V_8 = - V_23 ;
goto V_20;
}
} else if ( V_104 -> V_13 -> V_63 & V_118 ) {
int V_119 ;
struct V_114 * V_120 ;
if ( ! F_56 ( V_104 -> V_13 -> V_31 ) ) {
F_11 ( V_116 ,
L_9 ) ;
V_8 = - V_23 ;
goto V_20;
}
if ( V_104 -> V_13 -> V_32 == 0 ) {
F_11 ( V_116 ,
L_10 ) ;
return - V_23 ;
}
if ( V_104 -> V_13 -> V_63 & V_121 ) {
V_119 = V_104 -> V_13 -> V_32 ;
V_120 = F_17 ( V_29 , & V_33 ,
V_119 ) ;
if ( ! V_120 ) {
V_8 = - V_23 ;
goto V_20;
}
V_8 = F_55 ( V_111 , ( void * ) & V_104 -> V_122 , V_120 ,
V_119 ) ;
if ( V_8 < 0 )
goto V_20;
if ( V_8 < sizeof( * V_104 -> V_122 ) ) {
F_11 ( V_116 ,
L_11 ,
V_8 , ( int ) sizeof( * V_104 -> V_122 ) ) ;
V_8 = - V_23 ;
goto V_20;
}
}
}
V_8 = 0 ;
if ( V_104 -> V_13 -> V_63 & V_123 ) {
if ( V_104 -> V_13 -> V_108 ) {
V_8 = F_46 ( V_2 , V_104 ) ;
if ( V_8 )
goto V_20;
#ifdef F_57
} else {
V_104 -> V_105 = NULL ;
#endif
}
}
V_20:
if ( V_8 ) {
#ifdef F_57
F_52 ( V_104 -> V_105 ) ;
#endif
if ( V_104 -> V_117 )
F_58 ( V_110 , & V_104 -> V_117 ) ;
}
return V_8 ;
}
static int F_59 ( struct V_9 * exp , struct V_103 * V_104 )
{
return 0 ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_124 * V_125 = V_2 -> V_126 ;
struct V_1 * V_127 ;
struct V_128 * V_129 ;
struct V_130 V_131 ;
struct V_12 * V_13 ;
if ( ! V_125 ) {
F_61 ( V_132 , V_2 ,
L_12 ) ;
return;
}
V_13 = F_10 ( & V_2 -> V_21 , & V_22 ) ;
V_129 = V_125 -> V_133 ;
if ( V_129 ) {
struct V_130 * V_134 ;
F_25 ( V_129 -> V_135 == V_136 ) ;
V_134 = & V_129 -> V_137 ;
F_11 ( V_138 , L_13 ,
V_134 -> V_139 , V_13 -> V_140 . V_139 ) ;
V_131 = * V_134 ;
* V_134 = V_13 -> V_140 ;
}
V_127 = V_125 -> V_141 ;
if ( V_127 ) {
T_2 V_142 = F_62 ( V_127 -> V_143 ) ;
struct V_144 * V_145 ;
F_25 ( V_142 == V_146 || V_142 == V_147 ) ;
V_145 = F_24 ( & V_127 -> V_21 ,
& V_148 ) ;
F_25 ( V_145 ) ;
if ( V_129 )
F_25 ( ! memcmp ( & V_131 , & V_145 -> V_140 , sizeof( V_131 ) ) ) ;
F_61 ( V_138 , V_127 , L_14 ) ;
V_145 -> V_140 = V_13 -> V_140 ;
}
}
void F_63 ( struct V_1 * V_2 )
{
struct V_124 * V_125 = V_2 -> V_126 ;
if ( ! V_125 )
return;
F_64 ( V_2 ) ;
F_65 ( & V_2 -> V_149 ) ;
V_2 -> V_150 = 1 ;
F_66 ( & V_2 -> V_149 ) ;
V_2 -> V_126 = NULL ;
F_67 ( V_125 ) ;
}
int F_68 ( struct V_9 * exp ,
struct V_128 * V_129 ,
struct V_151 * V_152 )
{
struct V_124 * V_125 ;
struct V_153 * V_81 ;
struct V_12 * V_13 ;
struct V_1 * V_154 = V_152 -> V_155 ;
struct V_156 * V_157 = V_154 -> V_5 ;
if ( ! V_154 -> V_158 )
return 0 ;
V_81 = F_24 ( & V_154 -> V_21 , & V_83 ) ;
V_13 = F_10 ( & V_154 -> V_21 , & V_22 ) ;
F_25 ( V_81 ) ;
F_25 ( V_13 ) ;
if ( V_129 && V_157 -> V_159 ) {
V_125 = F_69 () ;
if ( ! V_125 ) {
F_61 ( V_132 , V_154 ,
L_15 ) ;
return 0 ;
}
F_70 ( V_125 ) ;
F_70 ( V_125 ) ;
F_65 ( & V_154 -> V_149 ) ;
V_129 -> V_160 = V_125 ;
V_125 -> V_133 = V_129 ;
V_125 -> V_161 = F_71 ( V_152 , V_162 ) ||
F_71 ( V_152 , V_163 ) ;
V_125 -> V_164 = V_154 ;
V_154 -> V_126 = V_125 ;
V_154 -> V_165 = F_63 ;
F_66 ( & V_154 -> V_149 ) ;
}
V_81 -> V_166 = V_13 -> V_24 ;
V_81 -> V_167 = V_13 -> V_168 ;
V_81 -> V_169 . V_139 = V_13 -> V_140 . V_139 ;
V_154 -> V_170 = F_60 ;
if ( ! F_30 ( & V_13 -> V_24 ) ) {
F_61 ( V_132 , V_154 ,
L_16 ) ;
F_72 () ;
}
F_61 ( V_171 , V_154 , L_17 ) ;
return 0 ;
}
static void F_73 ( struct V_124 * V_125 )
{
int V_172 = 0 ;
if ( V_125 -> V_161 == 0 &&
F_74 ( V_125 -> V_164 -> V_5 ) )
V_172 = 1 ;
F_25 ( V_125 -> V_164 -> V_158 == 0 ) ;
F_61 ( V_171 , V_125 -> V_164 , L_18 ) ;
F_75 ( V_125 -> V_164 , V_172 ) ;
if ( V_125 -> V_141 )
F_75 ( V_125 -> V_141 , V_172 ) ;
}
static int F_76 ( struct V_9 * exp ,
struct V_128 * V_129 )
{
struct V_124 * V_125 = V_129 -> V_160 ;
if ( ! V_125 )
return 0 ;
F_25 ( V_125 != V_173 ) ;
F_25 ( V_125 -> V_164 ) ;
F_73 ( V_125 ) ;
V_125 -> V_133 = NULL ;
V_129 -> V_160 = NULL ;
F_67 ( V_125 ) ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_34 * V_35 , int V_8 ) {
struct V_12 * V_174 ;
struct V_144 * V_145 ;
if ( V_2 && V_8 == - V_175 ) {
V_174 = F_10 ( & V_2 -> V_21 , & V_22 ) ;
V_145 = F_24 ( & V_2 -> V_21 , & V_148 ) ;
V_145 -> V_68 |= V_176 ;
if ( V_174 -> V_63 & V_177 )
V_35 -> V_37 |= V_178 ;
}
}
static int F_78 ( struct V_9 * exp , struct V_34 * V_35 ,
struct V_124 * V_125 , struct V_1 * * V_36 )
{
struct V_179 * V_180 = F_79 ( exp ) ;
struct V_1 * V_2 ;
struct V_59 * V_181 ;
int V_8 ;
int V_182 = 0 ;
V_181 = & V_183 ;
if ( V_35 -> V_184 & V_185 ) {
V_181 = & V_186 ;
V_8 = F_80 ( exp , & V_35 -> V_187 , V_35 ) ;
if ( V_8 < 0 ) {
F_50 ( L_19 V_26 L_20 ,
V_180 -> V_188 , F_12 ( & V_35 -> V_42 ) , V_8 ) ;
V_182 = V_8 ;
}
}
* V_36 = NULL ;
V_2 = F_19 ( F_7 ( exp ) , V_181 ) ;
if ( ! V_2 )
return - V_17 ;
V_8 = F_20 ( V_2 , V_15 , V_146 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
V_2 -> V_189 = V_190 ;
F_81 ( V_2 ) ;
if ( F_82 ( V_125 ) ) {
F_83 ( V_125 -> V_164 &&
V_125 -> V_164 -> V_191 != V_192 ,
L_21 , V_125 -> V_164 ) ;
V_125 -> V_141 = V_2 ;
F_61 ( V_138 , V_125 -> V_164 , L_22 ) ;
F_65 ( & V_125 -> V_164 -> V_149 ) ;
V_125 -> V_164 -> V_158 = 0 ;
F_66 ( & V_125 -> V_164 -> V_149 ) ;
} else {
F_11 ( V_138 ,
L_23 ) ;
}
F_84 ( V_2 , V_35 ) ;
F_22 ( & V_2 -> V_21 , & V_33 , V_45 ,
V_180 -> V_7 . V_4 . V_193 ) ;
F_22 ( & V_2 -> V_21 , & V_194 , V_45 ,
V_180 -> V_7 . V_4 . V_195 ) ;
F_9 ( V_2 ) ;
F_42 ( V_180 -> V_7 . V_4 . V_196 , NULL ) ;
V_8 = F_3 ( V_2 ) ;
F_43 ( V_180 -> V_7 . V_4 . V_196 , NULL ) ;
if ( ! V_2 -> V_27 ) {
F_11 ( V_171 , L_24 , V_2 ,
V_2 -> V_197 ) ;
if ( V_8 == 0 )
V_8 = V_2 -> V_197 ? : - V_198 ;
} else if ( V_8 == 0 || V_8 == - V_175 ) {
struct V_12 * V_13 ;
V_8 = F_85 ( V_2 -> V_27 ) ;
if ( F_86 ( V_2 -> V_27 ) == V_199 ) {
F_61 ( V_132 , V_2 ,
L_25 , V_8 ) ;
if ( V_8 > 0 )
V_8 = - V_8 ;
}
V_13 = F_10 ( & V_2 -> V_21 , & V_22 ) ;
if ( ! V_13 )
V_8 = - V_23 ;
} else if ( V_8 == - V_200 ) {
if ( V_125 ) {
F_61 ( V_138 , V_2 , L_26 , V_8 ) ;
if ( V_125 -> V_164 -> V_150 )
V_8 = 0 ;
}
}
if ( V_125 ) {
if ( V_8 != 0 )
V_125 -> V_141 = NULL ;
F_67 ( V_125 ) ;
}
* V_36 = V_2 ;
F_77 ( V_2 , V_35 , V_8 ) ;
return V_8 < 0 ? V_8 : V_182 ;
}
static int F_87 ( struct V_9 * exp , struct V_34 * V_35 ,
struct V_124 * V_125 )
{
struct V_179 * V_180 = F_79 ( exp ) ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_19 ( F_7 ( exp ) ,
& V_201 ) ;
if ( ! V_2 )
return - V_17 ;
V_8 = F_20 ( V_2 , V_15 , V_147 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
if ( V_125 ) {
F_83 ( V_125 -> V_164 &&
V_125 -> V_164 -> V_191 != V_192 ,
L_27 , V_125 -> V_164 ) ;
V_125 -> V_141 = V_2 ;
F_61 ( V_138 , V_125 -> V_164 , L_28 ) ;
F_65 ( & V_125 -> V_164 -> V_149 ) ;
V_125 -> V_164 -> V_158 = 0 ;
F_66 ( & V_125 -> V_164 -> V_149 ) ;
}
F_84 ( V_2 , V_35 ) ;
F_9 ( V_2 ) ;
F_42 ( V_180 -> V_7 . V_4 . V_196 , NULL ) ;
V_8 = F_3 ( V_2 ) ;
F_43 ( V_180 -> V_7 . V_4 . V_196 , NULL ) ;
if ( V_8 == - V_200 ) {
if ( V_125 ) {
if ( V_125 -> V_164 -> V_150 )
V_8 = 0 ;
}
}
if ( V_125 ) {
if ( V_8 != 0 )
V_125 -> V_141 = NULL ;
F_25 ( V_125 -> V_164 ) ;
F_73 ( V_125 ) ;
F_67 ( V_125 ) ;
}
F_77 ( V_2 , V_35 , V_8 ) ;
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_88 ( struct V_9 * exp , struct V_34 * V_35 ,
struct V_202 * * V_203 , struct V_1 * * V_36 )
{
struct V_1 * V_2 ;
struct V_204 * V_205 ;
int V_206 ;
T_3 V_207 ;
int V_208 = 0 ;
struct V_209 V_210 ;
int V_8 ;
* V_36 = NULL ;
F_89 ( & V_207 ) ;
V_211:
V_2 = F_19 ( F_7 ( exp ) , & V_212 ) ;
if ( ! V_2 )
return - V_17 ;
V_8 = F_20 ( V_2 , V_15 , V_213 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
V_2 -> V_189 = V_190 ;
F_81 ( V_2 ) ;
V_205 = F_90 ( V_2 , V_35 -> V_214 , 1 , V_215 ,
V_216 ) ;
if ( ! V_205 ) {
F_21 ( V_2 ) ;
return - V_17 ;
}
for ( V_206 = 0 ; V_206 < V_35 -> V_214 ; V_206 ++ )
F_91 ( V_205 , V_203 [ V_206 ] , 0 , V_217 ) ;
F_92 ( V_2 , V_35 -> V_218 ,
V_217 * V_35 -> V_214 ,
& V_35 -> V_42 ) ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 ) {
F_14 ( V_2 ) ;
if ( V_8 != - V_219 )
return V_8 ;
V_208 ++ ;
if ( ! F_93 ( V_208 , & exp -> V_98 -> V_7 . V_4 ) ) {
F_50 ( L_29 ) ;
return - V_198 ;
}
V_210 = F_94 ( F_95 ( V_208 ) ,
NULL , NULL , NULL ) ;
F_96 ( V_207 , 0 , & V_210 ) ;
goto V_211;
}
V_8 = F_97 ( V_2 , V_2 -> V_220 ,
V_2 -> V_220 -> V_221 ) ;
if ( V_8 < 0 ) {
F_14 ( V_2 ) ;
return V_8 ;
}
if ( V_2 -> V_220 -> V_221 & ~ V_222 ) {
F_50 ( L_30 ,
V_2 -> V_220 -> V_221 ,
V_217 * V_35 -> V_214 ) ;
F_14 ( V_2 ) ;
return - V_23 ;
}
* V_36 = V_2 ;
return 0 ;
}
static int F_98 ( const struct V_223 * V_224 ,
struct V_9 * exp , struct V_225 * V_226 ,
T_4 V_227 , T_2 V_68 )
{
struct V_179 * V_180 = F_79 ( exp ) ;
struct V_1 * V_2 ;
struct V_225 * V_228 ;
struct V_156 * V_157 = NULL ;
int V_8 ;
F_99 ( & V_180 -> V_7 . V_4 . V_229 ) ;
if ( V_180 -> V_7 . V_4 . V_230 )
V_157 = F_100 ( V_180 -> V_7 . V_4 . V_230 ) ;
F_101 ( & V_180 -> V_7 . V_4 . V_229 ) ;
if ( ! V_157 )
return - V_231 ;
V_2 = F_6 ( V_157 , & V_232 ,
V_15 , V_233 ) ;
if ( ! V_2 ) {
V_8 = - V_17 ;
goto V_234;
}
F_9 ( V_2 ) ;
if ( V_68 & V_235 ) {
V_2 -> V_236 = 1 ;
V_2 -> V_237 = 1 ;
}
V_8 = F_3 ( V_2 ) ;
if ( V_8 ) {
if ( V_157 -> V_238 )
V_8 = V_157 -> V_238 ;
goto V_20;
}
V_228 = F_10 ( & V_2 -> V_21 , & V_239 ) ;
if ( ! V_228 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_226 = * V_228 ;
V_20:
F_14 ( V_2 ) ;
V_234:
F_102 ( V_157 ) ;
return V_8 ;
}
static int F_103 ( struct V_9 * exp , struct V_240 * V_241 )
{
T_2 V_242 , V_243 ;
void * V_244 ;
int V_8 ;
if ( V_241 -> V_245 > V_246 )
return - V_247 ;
if ( V_241 -> V_245 < 2 )
return - V_248 ;
V_242 = F_104 ( sizeof( V_249 ) ) + sizeof( * V_241 ) ;
V_244 = F_105 ( V_242 , V_250 ) ;
if ( ! V_244 )
return - V_17 ;
memcpy ( V_244 , V_249 , sizeof( V_249 ) ) ;
memcpy ( V_244 + F_104 ( sizeof( V_249 ) ) , V_241 , sizeof( * V_241 ) ) ;
F_11 ( V_251 , L_31 V_26 L_32 ,
F_12 ( & V_241 -> V_252 ) , V_241 -> V_253 , V_241 -> V_254 ) ;
if ( ! F_30 ( & V_241 -> V_252 ) ) {
V_8 = - V_255 ;
goto V_20;
}
V_243 = sizeof( * V_241 ) + V_241 -> V_245 ;
V_8 = F_106 ( NULL , exp , V_242 , V_244 , & V_243 , V_241 , NULL ) ;
if ( V_8 != 0 && V_8 != - V_58 )
goto V_20;
if ( V_243 <= sizeof( * V_241 ) ) {
V_8 = - V_23 ;
goto V_20;
} else if ( V_243 > sizeof( * V_241 ) + V_241 -> V_245 ) {
V_8 = - V_248 ;
goto V_20;
}
F_11 ( V_251 , L_31 V_26 L_33 ,
F_12 ( & V_241 -> V_252 ) , V_241 -> V_253 , V_241 -> V_254 , V_241 -> V_256 ) ;
V_20:
F_107 ( V_244 ) ;
return V_8 ;
}
static int F_108 ( struct V_9 * exp ,
struct V_257 * V_258 )
{
struct V_156 * V_157 = F_7 ( exp ) ;
struct V_257 * V_259 ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_6 ( V_157 , & V_260 ,
V_15 , V_261 ) ;
if ( ! V_2 ) {
V_8 = - V_17 ;
goto V_20;
}
F_8 ( V_2 , NULL , 0 , 0 , - 1 , 0 ) ;
V_259 = F_24 ( & V_2 -> V_21 , & V_262 ) ;
if ( ! V_259 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_259 = * V_258 ;
V_259 -> V_263 = F_109 ( V_258 -> V_263 ) ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_110 ( struct V_156 * V_157 , T_2 V_264 )
{
T_2 * V_265 ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_6 ( V_157 , & V_266 ,
V_15 ,
V_267 ) ;
if ( ! V_2 ) {
V_8 = - V_17 ;
goto V_20;
}
F_8 ( V_2 , NULL , 0 , 0 , - 1 , 0 ) ;
V_265 = F_24 ( & V_2 -> V_21 ,
& V_268 ) ;
if ( ! V_265 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_265 = V_264 ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_111 ( struct V_9 * exp ,
struct V_34 * V_35 )
{
struct V_269 * V_270 = V_35 -> V_35 ;
struct V_269 * V_271 ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_19 ( F_7 ( exp ) ,
& V_272 ) ;
if ( ! V_2 )
return - V_17 ;
V_8 = F_20 ( V_2 , V_15 , V_273 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , & V_35 -> V_42 , 0 , 0 ,
V_35 -> V_51 [ 0 ] , 0 ) ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
goto V_20;
V_271 = F_10 ( & V_2 -> V_21 ,
& V_274 ) ;
if ( ! V_271 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_270 = * V_271 ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_112 ( struct V_156 * V_157 )
{
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_6 ( V_157 , & V_275 ,
V_15 ,
V_276 ) ;
if ( ! V_2 ) {
V_8 = - V_17 ;
goto V_20;
}
F_8 ( V_2 , NULL , 0 , 0 , - 1 , 0 ) ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_113 ( struct V_9 * exp ,
struct V_34 * V_35 )
{
struct V_277 * V_278 = V_35 -> V_35 ;
struct V_277 * V_279 ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_19 ( F_7 ( exp ) ,
& V_280 ) ;
if ( ! V_2 )
return - V_17 ;
V_8 = F_20 ( V_2 , V_15 , V_281 ) ;
if ( V_8 != 0 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , & V_35 -> V_42 , 0 , 0 ,
V_35 -> V_51 [ 0 ] , 0 ) ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
goto V_20;
V_279 = F_10 ( & V_2 -> V_21 , & V_282 ) ;
if ( ! V_279 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_278 = * V_279 ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_114 ( struct V_9 * exp ,
struct V_34 * V_35 )
{
struct V_283 * V_284 = V_35 -> V_35 ;
struct V_283 * V_285 ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_19 ( F_7 ( exp ) ,
& V_286 ) ;
if ( ! V_2 )
return - V_17 ;
V_8 = F_20 ( V_2 , V_15 , V_287 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , & V_35 -> V_42 , 0 , 0 ,
V_35 -> V_51 [ 0 ] , 0 ) ;
V_285 = F_24 ( & V_2 -> V_21 , & V_288 ) ;
if ( ! V_285 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_285 = * V_284 ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_115 ( struct V_9 * exp ,
struct V_289 * V_290 )
{
struct V_156 * V_157 = F_7 ( exp ) ;
struct V_1 * V_2 ;
struct V_291 * V_292 ;
struct V_293 * V_294 ;
char * V_295 ;
int V_8 ;
V_2 = F_19 ( V_157 , & V_296 ) ;
if ( ! V_2 ) {
V_8 = - V_17 ;
goto V_20;
}
F_22 ( & V_2 -> V_21 , & V_297 , V_48 ,
V_290 -> V_298 . V_299
* sizeof( struct V_293 ) ) ;
F_22 ( & V_2 -> V_21 , & V_300 , V_48 ,
V_290 -> V_298 . V_301 ) ;
V_8 = F_20 ( V_2 , V_15 , V_302 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , NULL , 0 , 0 , - 1 , 0 ) ;
V_292 = F_24 ( & V_2 -> V_21 , & V_303 ) ;
if ( ! V_292 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_292 = V_290 -> V_298 ;
V_294 = F_24 ( & V_2 -> V_21 , & V_297 ) ;
if ( ! V_294 ) {
V_8 = - V_23 ;
goto V_20;
}
memcpy ( V_294 , V_290 -> V_304 ,
V_290 -> V_298 . V_299 * sizeof( struct V_293 ) ) ;
V_295 = F_24 ( & V_2 -> V_21 , & V_300 ) ;
if ( ! V_295 ) {
V_8 = - V_23 ;
goto V_20;
}
memcpy ( V_295 , F_116 ( V_290 ) , V_290 -> V_298 . V_301 ) ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static struct V_305 * F_117 ( char * V_107 , int V_306 , int V_68 )
{
struct V_305 * V_307 = (struct V_305 * ) V_107 ;
F_25 ( V_306 <= V_308 ) ;
V_307 -> V_309 = V_310 ;
V_307 -> V_311 = V_312 ;
V_307 -> V_313 = V_68 ;
V_307 -> V_314 = V_315 ;
V_307 -> V_316 = V_306 ;
return V_307 ;
}
static int F_118 ( const struct V_223 * V_224 , struct V_317 * V_318 ,
struct V_319 * V_320 , void * V_321 )
{
struct V_322 * V_323 = V_321 ;
struct V_324 * V_81 = (struct V_324 * ) V_320 ;
struct V_305 * V_307 ;
int V_306 , V_8 ;
if ( V_81 -> V_325 . V_326 != V_327 ) {
V_8 = - V_255 ;
F_50 ( L_34 ,
V_323 -> V_328 -> V_188 , V_81 -> V_325 . V_326 ,
V_81 -> V_329 . V_330 , V_8 ) ;
return V_8 ;
}
if ( V_81 -> V_329 . V_331 < V_323 -> V_332 ) {
F_11 ( V_333 , L_35 ,
V_81 -> V_329 . V_331 , V_323 -> V_332 ) ;
return 0 ;
}
F_11 ( V_333 , L_36 V_26 L_37 V_26
L_38 , V_81 -> V_329 . V_331 , V_81 -> V_329 . V_330 ,
F_119 ( V_81 -> V_329 . V_330 ) , V_81 -> V_329 . V_334 ,
V_81 -> V_329 . V_335 & V_336 ,
F_12 ( & V_81 -> V_329 . V_337 ) , F_12 ( & V_81 -> V_329 . V_338 ) ,
V_81 -> V_329 . V_339 , F_120 ( & V_81 -> V_329 ) ) ;
V_306 = sizeof( * V_307 ) + F_121 ( & V_81 -> V_329 ) + V_81 -> V_329 . V_339 ;
V_307 = F_117 ( V_323 -> V_340 , V_306 , V_323 -> V_341 ) ;
memcpy ( V_307 + 1 , & V_81 -> V_329 , V_306 - sizeof( * V_307 ) ) ;
V_8 = F_122 ( V_323 -> V_342 , V_307 ) ;
F_11 ( V_333 , L_39 , V_323 -> V_342 , V_306 , V_8 ) ;
return V_8 ;
}
static int F_123 ( void * V_343 )
{
struct V_322 * V_323 = V_343 ;
struct V_344 * V_345 = NULL ;
struct V_317 * V_318 = NULL ;
struct V_305 * V_346 ;
int V_8 ;
F_11 ( V_333 , L_40 ,
V_323 -> V_342 , V_323 -> V_332 ) ;
V_323 -> V_340 = F_105 ( V_308 , V_250 ) ;
if ( ! V_323 -> V_340 ) {
V_8 = - V_17 ;
goto V_20;
}
V_345 = F_124 ( V_323 -> V_328 , V_347 ) ;
if ( ! V_345 ) {
V_8 = - V_348 ;
goto V_20;
}
V_8 = F_125 ( NULL , V_345 , & V_318 , NULL , V_349 ,
V_350 ) ;
if ( V_8 ) {
F_50 ( L_41 ,
V_323 -> V_328 -> V_188 , V_8 ) ;
goto V_20;
}
V_8 = F_126 ( NULL , V_318 , V_351 , NULL ) ;
if ( V_8 ) {
F_50 ( L_42 , V_8 ) ;
goto V_20;
}
V_8 = F_127 ( NULL , V_318 , F_118 , V_323 , 0 , 0 ) ;
V_346 = F_117 ( V_323 -> V_340 , sizeof( * V_346 ) , V_323 -> V_341 ) ;
if ( V_346 ) {
V_346 -> V_314 = V_352 ;
F_122 ( V_323 -> V_342 , V_346 ) ;
}
V_20:
F_128 ( V_323 -> V_342 ) ;
if ( V_318 )
F_129 ( NULL , V_318 ) ;
if ( V_345 )
F_130 ( V_345 ) ;
F_107 ( V_323 -> V_340 ) ;
F_107 ( V_323 ) ;
return V_8 ;
}
static int F_131 ( struct V_179 * V_180 ,
struct V_353 * V_354 )
{
struct V_322 * V_323 ;
struct V_355 * V_356 ;
int V_8 ;
V_323 = F_105 ( sizeof( * V_323 ) , V_250 ) ;
if ( ! V_323 )
return - V_17 ;
V_323 -> V_328 = V_180 ;
V_323 -> V_332 = V_354 -> V_357 ;
V_323 -> V_342 = F_132 ( V_354 -> V_358 ) ;
V_323 -> V_341 = V_354 -> V_359 ;
V_356 = F_133 ( F_123 , V_323 ,
L_43 ) ;
if ( F_48 ( V_356 ) ) {
V_8 = F_49 ( V_356 ) ;
F_50 ( L_44 ,
V_180 -> V_188 , V_8 ) ;
F_107 ( V_323 ) ;
} else {
V_8 = 0 ;
F_11 ( V_333 , L_45 ,
V_180 -> V_188 ) ;
}
F_50 ( L_46 , V_8 ) ;
return V_8 ;
}
static int F_134 ( struct V_179 * V_360 , struct V_9 * exp ,
struct V_361 * V_362 )
{
struct V_3 * V_4 = & exp -> V_98 -> V_7 . V_4 ;
struct V_1 * V_2 ;
struct V_361 * V_13 ;
int V_8 ;
V_2 = F_6 ( F_7 ( exp ) ,
& V_363 , V_15 ,
V_364 ) ;
if ( ! V_2 )
return - V_17 ;
V_13 = F_24 ( & V_2 -> V_21 , & V_365 ) ;
* V_13 = * V_362 ;
F_9 ( V_2 ) ;
V_4 -> V_366 = - V_367 ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
V_4 -> V_366 = V_8 ;
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_135 ( struct V_9 * exp ,
struct V_368 * V_369 )
{
struct V_3 * V_4 = & exp -> V_98 -> V_7 . V_4 ;
int V_8 ;
V_369 -> V_370 = V_4 -> V_371 ;
memcpy ( V_369 -> V_372 , V_373 , strlen ( V_373 ) ) ;
V_8 = V_4 -> V_366 ;
if ( V_8 == V_374 )
V_8 = - V_375 ;
return V_8 ;
}
static int F_136 ( struct V_179 * V_360 , struct V_9 * exp ,
struct V_361 * V_362 )
{
struct V_1 * V_2 ;
struct V_361 * V_376 ;
int V_8 ;
V_2 = F_6 ( F_7 ( exp ) ,
& V_377 , V_15 ,
V_378 ) ;
if ( ! V_2 )
return - V_17 ;
V_376 = F_24 ( & V_2 -> V_21 , & V_365 ) ;
* V_376 = * V_362 ;
F_9 ( V_2 ) ;
F_81 ( V_2 ) ;
V_2 -> V_236 = 1 ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
F_50 ( L_47 , V_8 ) ;
if ( V_2 -> V_27 ) {
V_376 = F_10 ( & V_2 -> V_21 , & V_365 ) ;
if ( V_376 ) {
* V_362 = * V_376 ;
} else if ( ! V_8 ) {
F_50 ( L_48 ) ;
V_8 = - V_23 ;
}
} else if ( ! V_8 ) {
F_50 ( L_48 ) ;
V_8 = - V_23 ;
}
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_137 ( struct V_9 * exp ,
struct V_34 * V_35 )
{
F_31 ( V_77 ) ;
struct V_1 * V_2 ;
int V_8 , V_78 ;
struct V_379 * V_380 , * V_381 ;
V_380 = V_35 -> V_35 ;
V_78 = F_32 ( exp , & V_35 -> V_42 , & V_77 ,
V_382 , V_383 ) ;
V_78 += F_32 ( exp , & V_35 -> V_187 , & V_77 ,
V_382 , V_383 ) ;
V_2 = F_19 ( F_7 ( exp ) ,
& V_384 ) ;
if ( ! V_2 ) {
F_138 ( & V_77 , V_385 , V_78 ) ;
return - V_17 ;
}
V_8 = F_33 ( exp , V_2 , V_386 , & V_77 , V_78 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_139 ( V_2 , V_35 ) ;
V_381 = F_24 ( & V_2 -> V_21 , & V_387 ) ;
F_25 ( V_381 ) ;
* V_381 = * V_380 ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_140 ( unsigned int V_388 , struct V_9 * exp , int V_306 ,
void * V_389 , void T_5 * V_390 )
{
struct V_179 * V_180 = exp -> V_98 ;
struct V_391 * V_321 = V_389 ;
struct V_156 * V_157 = V_180 -> V_7 . V_4 . V_230 ;
int V_8 ;
if ( ! F_141 ( V_392 ) ) {
F_50 ( L_49 , V_180 -> V_188 ,
F_142 ( V_392 ) ) ;
return - V_255 ;
}
switch ( V_388 ) {
case V_393 :
V_8 = F_131 ( V_180 , V_389 ) ;
goto V_20;
case V_394 : {
struct V_353 * V_354 = V_389 ;
struct V_395 V_323 = {
. V_396 = V_354 -> V_357 ,
. V_397 = V_354 -> V_358
} ;
V_8 = F_143 ( NULL , exp , strlen ( V_398 ) ,
V_398 , sizeof( V_323 ) , & V_323 ,
NULL ) ;
goto V_20;
}
case V_399 :
V_8 = F_103 ( exp , V_389 ) ;
goto V_20;
case V_400 :
V_8 = F_144 ( exp , V_389 ) ;
if ( V_8 == - V_401 )
V_8 = 0 ;
goto V_20;
case V_402 :
V_8 = F_108 ( exp , V_389 ) ;
goto V_20;
case V_403 :
V_8 = F_113 ( exp , V_389 ) ;
goto V_20;
case V_404 :
V_8 = F_114 ( exp , V_389 ) ;
goto V_20;
case V_405 :
V_8 = F_111 ( exp , V_389 ) ;
goto V_20;
case V_406 :
V_8 = F_115 ( exp , V_389 ) ;
goto V_20;
case V_407 :
V_8 = F_145 ( V_157 , V_321 -> V_408 , 0 ) ;
if ( V_8 < 0 )
goto V_20;
V_8 = 0 ;
goto V_20;
case V_409 :
V_8 = F_146 ( V_157 , V_321 -> V_410 ) ;
goto V_20;
case V_411 :
V_8 = F_135 ( exp , (struct V_368 * ) V_389 ) ;
goto V_20;
case V_412 :
V_8 = F_147 ( V_180 ) ;
goto V_20;
case V_413 : {
struct V_225 V_414 = { 0 } ;
if ( * ( ( T_2 * ) V_321 -> V_415 ) != 0 ) {
V_8 = - V_231 ;
goto V_20;
}
if ( F_148 ( V_321 -> V_416 , F_149 ( V_180 ) ,
F_150 ( V_417 , V_321 -> V_418 ,
sizeof( struct V_370 ) ) ) ) {
V_8 = - V_419 ;
goto V_20;
}
V_8 = F_98 ( NULL , V_180 -> V_420 , & V_414 ,
F_151 ( - V_421 ) ,
0 ) ;
if ( V_8 != 0 )
goto V_20;
if ( F_148 ( V_321 -> V_422 , & V_414 ,
F_150 ( V_417 , V_321 -> V_423 ,
sizeof( V_414 ) ) ) ) {
V_8 = - V_419 ;
goto V_20;
}
V_8 = 0 ;
goto V_20;
}
case V_424 : {
struct V_425 * V_426 = V_389 ;
struct V_361 * V_362 ;
V_362 = F_105 ( sizeof( * V_362 ) , V_250 ) ;
if ( ! V_362 ) {
V_8 = - V_17 ;
goto V_20;
}
F_152 ( V_362 , V_426 ) ;
V_8 = V_361 ( exp , V_362 ) ;
if ( V_8 == 0 ) {
F_152 ( V_426 , V_362 ) ;
V_426 -> V_427 = V_428 ;
V_426 -> V_370 = V_180 -> V_7 . V_4 . V_371 ;
}
F_107 ( V_362 ) ;
goto V_20;
}
case V_429 :
if ( F_148 ( V_390 , F_153 ( exp ) ,
sizeof( * F_153 ( exp ) ) ) ) {
V_8 = - V_419 ;
goto V_20;
}
V_8 = 0 ;
goto V_20;
case V_430 :
V_8 = F_137 ( exp , V_389 ) ;
goto V_20;
default:
F_50 ( L_50 , V_388 ) ;
V_8 = - V_431 ;
goto V_20;
}
V_20:
F_154 ( V_392 ) ;
return V_8 ;
}
static int F_155 ( struct V_9 * exp ,
T_6 V_242 , void * V_244 ,
int V_243 , void * V_432 )
{
struct V_156 * V_157 = F_7 ( exp ) ;
struct V_1 * V_2 ;
char * V_71 ;
int V_8 = - V_255 ;
V_2 = F_19 ( V_157 , & V_433 ) ;
if ( ! V_2 )
return - V_17 ;
F_22 ( & V_2 -> V_21 , & V_434 ,
V_48 , V_242 ) ;
F_22 ( & V_2 -> V_21 , & V_435 ,
V_48 , sizeof( T_2 ) ) ;
V_8 = F_20 ( V_2 , V_15 , V_436 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
V_71 = F_24 ( & V_2 -> V_21 , & V_434 ) ;
memcpy ( V_71 , V_244 , V_242 ) ;
V_71 = F_24 ( & V_2 -> V_21 , & V_435 ) ;
memcpy ( V_71 , & V_243 , sizeof( T_2 ) ) ;
F_22 ( & V_2 -> V_21 , & V_437 ,
V_45 , V_243 ) ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 == 0 || V_8 == - V_58 ) {
V_71 = F_10 ( & V_2 -> V_21 , & V_437 ) ;
memcpy ( V_432 , V_71 , V_243 ) ;
if ( F_156 ( V_2 ) ) {
if ( F_157 ( V_249 ) )
F_158 ( V_432 ) ;
}
}
F_14 ( V_2 ) ;
return V_8 ;
}
static void F_159 ( struct V_438 * V_439 )
{
F_160 ( & V_439 -> V_440 ) ;
F_160 ( & V_439 -> V_441 ) ;
F_161 ( & V_439 -> V_442 ) ;
F_161 ( & V_439 -> V_443 ) ;
F_162 ( & V_439 -> V_444 ) ;
F_162 ( & V_439 -> V_445 . V_446 ) ;
F_162 ( & V_439 -> V_445 . V_447 ) ;
F_162 ( & V_439 -> V_448 ) ;
}
static void F_163 ( struct V_449 * V_439 )
{
struct V_438 * V_450 ;
int V_206 ;
F_160 ( & V_439 -> V_451 ) ;
F_160 ( & V_439 -> V_452 ) ;
F_160 ( & V_439 -> V_453 ) ;
F_162 ( & V_439 -> V_454 ) ;
V_450 = F_164 ( V_439 ) ;
for ( V_206 = 0 ; V_206 < V_439 -> V_452 ; V_206 ++ , V_450 = F_165 ( V_450 ) )
F_159 ( V_450 ) ;
}
static void F_166 ( struct V_305 * V_455 )
{
F_167 ( & V_455 -> V_309 ) ;
F_167 ( & V_455 -> V_314 ) ;
F_167 ( & V_455 -> V_316 ) ;
}
static int F_144 ( struct V_9 * exp ,
struct V_456 * V_457 )
{
struct V_156 * V_157 = F_7 ( exp ) ;
T_2 V_458 = V_457 -> V_459 ;
int V_8 = 0 ;
if ( V_457 -> V_460 != V_461 ) {
F_50 ( L_51 , V_457 -> V_460 ) ;
return - V_255 ;
}
F_11 ( V_462 , L_52 , V_457 -> V_463 , V_457 -> V_464 ,
V_457 -> V_465 , V_457 -> V_460 , V_457 -> V_466 ) ;
if ( V_457 -> V_466 & V_467 ) {
V_8 = F_112 ( V_157 ) ;
} else {
V_8 = F_110 ( V_157 , V_458 ) ;
}
return V_8 ;
}
static int F_168 ( int V_306 , void * V_432 )
{
struct V_305 * V_307 = (struct V_305 * ) V_432 ;
struct V_449 * V_468 = (struct V_449 * ) ( V_307 + 1 ) ;
if ( V_306 < sizeof( * V_307 ) + sizeof( * V_468 ) ) {
F_50 ( L_53 , V_306 ,
( int ) ( sizeof( * V_307 ) + sizeof( * V_468 ) ) ) ;
return - V_23 ;
}
if ( V_307 -> V_309 == F_169 ( V_310 ) ) {
F_166 ( V_307 ) ;
F_163 ( V_468 ) ;
} else if ( V_307 -> V_309 != V_310 ) {
F_50 ( L_54 , V_307 -> V_309 , V_310 ) ;
return - V_23 ;
}
F_11 ( V_462 ,
L_55 ,
V_307 -> V_309 , V_307 -> V_311 , V_307 -> V_314 ,
V_307 -> V_316 , V_468 -> V_452 , V_468 -> V_469 ) ;
return F_170 ( V_461 , V_307 ) ;
}
static int F_171 ( void * V_321 , void * V_470 )
{
struct V_471 * V_472 = V_321 ;
struct V_156 * V_157 = (struct V_156 * ) V_470 ;
int V_8 ;
if ( ! V_472 || V_472 -> V_473 != V_474 )
return - V_23 ;
if ( ! F_172 ( & V_472 -> V_475 , & V_157 -> V_6 -> V_370 ) )
return 0 ;
F_11 ( V_138 , L_56 ,
V_157 -> V_6 -> V_188 , V_472 -> V_476 ) ;
V_8 = F_110 ( V_157 , V_472 -> V_476 ) ;
return ( V_8 == - V_401 ) ? 0 : V_8 ;
}
static int F_173 ( const struct V_223 * V_224 ,
struct V_9 * exp ,
T_6 V_242 , void * V_244 ,
T_6 V_243 , void * V_432 ,
struct V_477 * V_478 )
{
struct V_156 * V_157 = F_7 ( exp ) ;
int V_8 ;
if ( F_157 ( V_479 ) ) {
if ( V_243 != sizeof( int ) )
return - V_255 ;
F_65 ( & V_157 -> V_480 ) ;
if ( * ( ( int * ) V_432 ) ) {
V_157 -> V_481 |= V_482 ;
V_157 -> V_483 . V_484 |=
V_482 ;
} else {
V_157 -> V_481 &= ~ V_482 ;
V_157 -> V_483 . V_484 &=
~ V_482 ;
}
F_66 ( & V_157 -> V_480 ) ;
V_8 = F_174 ( V_157 , V_485 , V_15 ,
V_242 , V_244 , V_243 , V_432 , V_478 ) ;
return V_8 ;
}
if ( F_157 ( V_486 ) ) {
F_175 ( exp -> V_98 ) ;
return 0 ;
}
if ( F_157 ( V_487 ) ) {
F_176 ( V_157 ) ;
return 0 ;
}
if ( F_157 ( V_398 ) ) {
V_8 = F_174 ( V_157 , V_485 , V_15 ,
V_242 , V_244 , V_243 , V_432 , V_478 ) ;
return V_8 ;
}
if ( F_157 ( V_488 ) ) {
V_8 = F_168 ( V_243 , V_432 ) ;
return V_8 ;
}
F_50 ( L_57 , ( char * ) V_244 ) ;
return - V_255 ;
}
static int F_177 ( const struct V_223 * V_224 , struct V_9 * exp ,
T_2 V_242 , void * V_244 , T_2 * V_243 , void * V_432 ,
struct V_489 * V_117 )
{
int V_8 = - V_255 ;
if ( F_157 ( V_490 ) ) {
int V_491 , * V_492 ;
if ( * V_243 != sizeof( int ) )
return - V_255 ;
V_491 = * ( int * ) V_432 ;
if ( V_491 > exp -> V_98 -> V_7 . V_4 . V_493 )
exp -> V_98 -> V_7 . V_4 . V_493 = V_491 ;
V_492 = V_432 ;
* V_492 = exp -> V_98 -> V_7 . V_4 . V_493 ;
return 0 ;
} else if ( F_157 ( V_494 ) ) {
int * V_495 ;
if ( * V_243 != sizeof( int ) )
return - V_255 ;
V_495 = V_432 ;
* V_495 = exp -> V_98 -> V_7 . V_4 . V_193 ;
return 0 ;
} else if ( F_157 ( V_496 ) ) {
struct V_156 * V_157 = F_7 ( exp ) ;
struct V_497 * V_321 = V_432 ;
if ( * V_243 != sizeof( * V_321 ) )
return - V_255 ;
* V_321 = V_157 -> V_483 ;
return 0 ;
} else if ( F_157 ( V_498 ) ) {
* ( ( int * ) V_432 ) = 1 ;
return 0 ;
}
V_8 = F_155 ( exp , V_242 , V_244 , * V_243 , V_432 ) ;
return V_8 ;
}
static int F_178 ( struct V_9 * exp , const struct V_10 * V_61 ,
struct V_1 * * V_36 )
{
struct V_1 * V_2 ;
int V_8 ;
* V_36 = NULL ;
V_2 = F_19 ( F_7 ( exp ) , & V_499 ) ;
if ( ! V_2 )
return - V_17 ;
V_8 = F_20 ( V_2 , V_15 , V_500 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , V_61 , 0 , 0 , - 1 , 0 ) ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
F_14 ( V_2 ) ;
else
* V_36 = V_2 ;
return V_8 ;
}
static int F_179 ( struct V_179 * V_180 , struct V_156 * V_157 ,
enum V_501 V_502 )
{
int V_8 = 0 ;
F_25 ( V_157 -> V_6 == V_180 ) ;
switch ( V_502 ) {
case V_503 : {
#if 0
rc = obd_notify_observer(obd, obd, OBD_NOTIFY_DISCON, NULL);
#endif
break;
}
case V_504 : {
struct V_3 * V_4 = & V_180 -> V_7 . V_4 ;
if ( V_4 -> V_505 )
F_180 ( V_4 -> V_505 ) ;
V_8 = F_181 ( V_180 , V_180 , V_506 , NULL ) ;
break;
}
case V_507 : {
struct V_508 * V_509 = V_180 -> V_510 ;
F_182 ( V_509 , V_511 ) ;
break;
}
case V_512 :
V_8 = F_181 ( V_180 , V_180 , V_513 , NULL ) ;
if ( V_8 == 0 )
V_8 = F_183 ( V_461 ,
F_171 ,
( void * ) V_157 ) ;
break;
case V_514 :
V_8 = F_181 ( V_180 , V_180 , V_515 , NULL ) ;
break;
case V_516 :
case V_517 :
break;
default:
F_50 ( L_58 , V_502 ) ;
F_72 () ;
}
return V_8 ;
}
int F_80 ( struct V_9 * exp , struct V_10 * V_61 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = & exp -> V_98 -> V_7 . V_4 ;
struct V_518 * V_519 = V_4 -> V_505 ;
return F_184 ( NULL , V_519 , V_61 ) ;
}
static struct V_370 * F_185 ( struct V_9 * exp )
{
struct V_3 * V_4 = & exp -> V_98 -> V_7 . V_4 ;
return & V_4 -> V_371 ;
}
static int F_186 ( struct V_520 * V_521 )
{
if ( V_521 -> V_522 -> V_523 != V_524 )
return 0 ;
if ( V_521 -> V_525 . V_526 . V_527 & V_528 )
return 0 ;
return 1 ;
}
static int F_187 ( struct V_529 * V_530 )
{
if ( V_530 -> V_531 )
V_530 -> V_531 = NULL ;
return 0 ;
}
static int F_188 ( struct V_179 * V_180 )
{
struct V_532 * V_533 = & V_180 -> V_534 ;
struct V_344 * V_345 ;
int V_8 ;
V_8 = F_189 ( NULL , V_180 , V_533 , V_347 , V_180 ,
& V_535 ) ;
if ( V_8 )
return V_8 ;
V_345 = F_190 ( V_533 , V_347 ) ;
F_191 ( V_345 ) ;
F_130 ( V_345 ) ;
return 0 ;
}
static void F_192 ( struct V_179 * V_180 )
{
struct V_344 * V_345 ;
V_345 = F_124 ( V_180 , V_347 ) ;
if ( V_345 )
F_193 ( NULL , V_345 ) ;
}
static int F_194 ( struct V_179 * V_180 , struct V_536 * V_537 )
{
struct V_3 * V_4 = & V_180 -> V_7 . V_4 ;
struct V_538 V_539 = { NULL } ;
int V_8 ;
V_4 -> V_99 = F_105 ( sizeof( * V_4 -> V_99 ) , V_250 ) ;
if ( ! V_4 -> V_99 )
return - V_17 ;
F_195 ( V_4 -> V_99 ) ;
V_8 = F_196 () ;
if ( V_8 < 0 )
goto V_540;
V_4 -> V_196 = F_105 ( sizeof( * V_4 -> V_196 ) , V_250 ) ;
if ( ! V_4 -> V_196 ) {
V_8 = - V_17 ;
goto V_541;
}
F_195 ( V_4 -> V_196 ) ;
V_8 = F_197 ( V_180 , V_537 ) ;
if ( V_8 )
goto V_542;
F_198 ( & V_539 ) ;
F_199 ( V_180 , V_539 . V_543 , V_539 . V_544 ) ;
F_200 ( V_180 ) ;
F_201 ( V_180 ) ;
F_202 ( V_180 -> V_510 , F_186 ) ;
V_180 -> V_510 -> V_545 = & V_546 ;
V_8 = F_188 ( V_180 ) ;
if ( V_8 ) {
F_203 ( V_180 ) ;
F_50 ( L_59 ) ;
}
return V_8 ;
V_542:
F_107 ( V_4 -> V_196 ) ;
V_541:
F_204 () ;
V_540:
F_107 ( V_4 -> V_99 ) ;
return V_8 ;
}
static int F_205 ( struct V_9 * exp , int V_547 ,
int V_548 , int V_549 , int V_550 )
{
struct V_179 * V_180 = exp -> V_98 ;
struct V_3 * V_4 = & V_180 -> V_7 . V_4 ;
if ( V_4 -> V_493 < V_547 )
V_4 -> V_493 = V_547 ;
if ( V_4 -> V_193 < V_548 )
V_4 -> V_193 = V_548 ;
if ( V_4 -> V_551 < V_549 )
V_4 -> V_551 = V_549 ;
if ( V_4 -> V_195 < V_550 )
V_4 -> V_195 = V_550 ;
return 0 ;
}
static int F_206 ( struct V_179 * V_180 , enum V_552 V_553 )
{
switch ( V_553 ) {
case V_554 :
break;
case V_555 :
if ( V_180 -> V_372 -> V_556 <= 1 )
F_207 ( 0 , V_461 ) ;
F_208 ( V_180 ) ;
F_209 ( V_180 ) ;
F_210 ( V_180 ) ;
F_192 ( V_180 ) ;
break;
}
return 0 ;
}
static int F_203 ( struct V_179 * V_180 )
{
struct V_3 * V_4 = & V_180 -> V_7 . V_4 ;
F_107 ( V_4 -> V_99 ) ;
F_107 ( V_4 -> V_196 ) ;
F_204 () ;
return F_211 ( V_180 ) ;
}
static int F_212 ( struct V_179 * V_180 , T_6 V_306 , void * V_107 )
{
struct V_536 * V_557 = V_107 ;
struct V_538 V_539 = { NULL } ;
int V_8 = 0 ;
F_198 ( & V_539 ) ;
switch ( V_557 -> V_558 ) {
default:
V_8 = F_213 ( V_559 , V_539 . V_543 ,
V_557 , V_180 ) ;
if ( V_8 > 0 )
V_8 = 0 ;
break;
}
return V_8 ;
}
static int T_7 F_214 ( void )
{
struct V_538 V_539 = { NULL } ;
F_198 ( & V_539 ) ;
return F_215 ( & V_560 , & V_561 ,
V_562 , NULL ) ;
}
static void F_216 ( void )
{
F_217 ( V_562 ) ;
}
