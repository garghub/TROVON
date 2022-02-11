static int F_1 ( int V_1 )
{
F_2 ( V_2 , V_1 ) ;
return 0 ;
}
static int F_3 ( void )
{
return F_4 ( V_2 ) ;
}
static void T_1 F_5 ( void )
{
struct V_3 * V_4 = F_6 ( & V_5 . V_6 , L_1 ) ;
int V_7 ;
long V_8 ;
if ( F_7 ( V_4 ) ) {
V_7 = F_8 ( V_4 ) ;
F_9 ( L_2 , V_7 ) ;
goto V_9;
}
V_7 = F_10 ( & V_10 , & V_11 ) ;
if ( V_7 < 0 ) {
F_9 ( L_3 ,
V_7 , V_10 . V_12 ) ;
goto V_9;
}
F_11 ( L_4 ,
F_12 ( & V_10 ) ) ;
V_8 = F_13 ( & V_10 , 594000000 ) ;
if ( V_8 < 0 ) {
F_9 ( L_5 , V_8 ) ;
V_7 = V_8 ;
goto V_9;
}
V_7 = F_14 ( & V_10 , V_8 ) ;
if ( V_7 < 0 ) {
F_9 ( L_6 , V_8 , V_7 ) ;
goto V_9;
}
F_11 ( L_7 , V_8 ) ;
V_7 = F_10 ( V_4 , & V_10 ) ;
if ( V_7 < 0 )
F_9 ( L_8 , V_7 ) ;
V_9:
if ( ! F_7 ( V_4 ) )
F_15 ( V_4 ) ;
}
static int F_16 ( struct V_13 * V_14 )
{
return F_17 ( F_18 ( V_14 ) ) ;
}
static void F_19 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_18 ( V_14 ) ;
F_20 ( 0x8a0a , V_16 -> V_17 ) ;
}
static int F_21 ( struct V_13 * V_14 )
{
return V_18 ;
}
static void F_22 ( struct V_19 * V_20 )
{
struct V_15 * V_16 = F_23 ( V_20 , struct V_15 ,
V_20 . V_20 ) ;
F_24 ( V_16 -> V_14 ) ;
F_25 ( & V_16 -> V_20 , V_21 ) ;
}
static int F_26 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_18 ( V_14 ) ;
V_16 -> V_14 = V_14 ;
F_27 ( & V_16 -> V_20 , F_22 ) ;
F_25 ( & V_16 -> V_20 , V_21 ) ;
return 0 ;
}
static void F_28 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_18 ( V_14 ) ;
F_29 ( & V_16 -> V_20 ) ;
}
static T_2 F_30 ( int V_22 , void * V_23 )
{
struct V_13 * V_14 = V_23 ;
struct V_15 * V_16 = F_18 ( V_14 ) ;
F_31 ( & V_14 -> V_6 , L_9 , V_24 ) ;
F_24 ( V_14 ) ;
F_20 ( F_32 ( V_16 -> V_25 ) | V_26 ,
V_16 -> V_25 ) ;
return V_27 ;
}
static int F_33 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_18 ( V_14 ) ;
int V_7 ;
F_20 ( V_28 | V_26 , V_16 -> V_25 ) ;
V_7 = F_34 ( V_29 , F_30 , V_30 ,
F_35 ( & V_14 -> V_6 ) , V_14 ) ;
if ( V_7 ) {
F_36 ( & V_14 -> V_6 , L_10 ) ;
return V_7 ;
}
F_20 ( V_28 | V_31 , V_16 -> V_25 ) ;
return 0 ;
}
static void F_37 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_18 ( V_14 ) ;
F_20 ( V_28 | V_26 , V_16 -> V_25 ) ;
F_38 ( V_29 , V_14 ) ;
}
static int F_39 ( struct V_13 * V_14 )
{
return V_32 ;
}
static int F_40 ( struct V_3 * V_3 , long V_8 , int V_33 )
{
int V_7 ;
if ( V_8 <= 0 )
return 0 ;
if ( ! V_33 ) {
F_41 ( V_3 ) ;
return 0 ;
}
V_7 = F_14 ( V_3 , F_13 ( V_3 , V_8 ) ) ;
if ( V_7 < 0 )
return V_7 ;
return F_42 ( V_3 ) ;
}
static int F_43 ( struct V_34 * V_6 , int V_8 , int V_33 )
{
struct V_3 * V_35 ;
struct V_3 * V_36 = & V_37 ;
long V_38 = 0 ;
long V_39 = 0 ;
int V_40 ;
int V_7 ;
switch ( V_8 ) {
case 44100 :
V_38 = V_8 * 256 ;
V_40 = V_41 | V_42 ;
break;
case 48000 :
V_38 = 85428000 ;
V_39 = V_8 * 256 ;
V_40 = V_41 | V_42 ;
break;
default:
F_9 ( L_11 ) ;
return - V_43 ;
}
V_35 = F_6 ( V_6 , L_12 ) ;
if ( F_7 ( V_35 ) )
return - V_44 ;
V_7 = F_40 ( V_35 , V_38 , V_33 ) ;
if ( V_7 < 0 )
goto V_45;
V_7 = F_40 ( V_36 , V_39 , V_33 ) ;
if ( V_7 < 0 ) {
if ( V_33 )
F_40 ( V_35 , V_38 , 0 ) ;
goto V_45;
}
V_7 = V_40 ;
V_45:
F_15 ( V_35 ) ;
return V_7 ;
}
static int F_44 ( struct V_13 * V_14 )
{
return ! F_4 ( V_46 ) ;
}
static int F_45 ( struct V_13 * V_14 )
{
return ! F_4 ( V_47 ) ;
}
static int F_46 ( struct V_48 * V_49 ,
int V_33 )
{
return 0 ;
}
static void F_47 ( struct V_34 * V_6 )
{
F_48 ( & V_50 ) ;
}
static int F_49 ( struct V_51 * V_52 )
{
return F_50 ( V_52 , & V_50 , & V_53 ,
F_47 , 0 ) ;
}
static void F_51 ( struct V_51 * V_52 )
{
F_52 ( V_52 , V_50 , & V_53 ) ;
}
static void T_1 F_53 ( void )
{
T_3 V_54 ;
struct V_3 * V_3 ;
F_54 ( 0 , L_13 , V_55 ,
F_55 ( V_55 ) , 1800000 ) ;
F_54 ( 1 , L_14 , V_56 ,
F_55 ( V_56 ) , 3300000 ) ;
F_56 ( 2 , V_57 , F_55 ( V_57 ) ) ;
F_14 ( & V_58 , 27000000 ) ;
F_57 () ;
F_58 ( V_59 , NULL ) ;
F_58 ( V_60 , NULL ) ;
F_58 ( V_61 , NULL ) ;
F_58 ( V_62 , NULL ) ;
F_58 ( V_63 , NULL ) ;
F_58 ( V_64 , NULL ) ;
F_58 ( V_65 , NULL ) ;
F_58 ( V_66 , NULL ) ;
F_58 ( V_67 , NULL ) ;
F_58 ( V_68 , NULL ) ;
F_58 ( V_69 , NULL ) ;
F_58 ( V_70 , NULL ) ;
F_58 ( V_71 , NULL ) ;
F_58 ( V_72 , NULL ) ;
F_58 ( V_73 , NULL ) ;
F_58 ( V_74 , NULL ) ;
F_58 ( V_75 , NULL ) ;
F_58 ( V_76 , NULL ) ;
F_58 ( V_77 , NULL ) ;
F_58 ( V_78 , NULL ) ;
F_58 ( V_79 , NULL ) ;
F_58 ( V_80 , NULL ) ;
F_58 ( V_81 , NULL ) ;
F_58 ( V_82 , NULL ) ;
F_58 ( V_83 , NULL ) ;
F_58 ( V_84 , NULL ) ;
F_58 ( V_85 , NULL ) ;
F_58 ( V_86 , NULL ) ;
F_58 ( V_87 , NULL ) ;
F_58 ( V_88 , NULL ) ;
F_58 ( V_2 , NULL ) ;
F_59 ( V_2 , 0 ) ;
F_58 ( V_89 , NULL ) ;
F_59 ( V_89 , 1 ) ;
F_58 ( V_90 , NULL ) ;
F_60 ( V_91 ) ;
F_58 ( V_92 , NULL ) ;
F_60 ( V_93 ) ;
F_58 ( V_94 , NULL ) ;
F_58 ( V_95 , NULL ) ;
F_58 ( V_96 , NULL ) ;
F_58 ( V_97 , NULL ) ;
F_58 ( V_98 , NULL ) ;
F_58 ( V_99 , NULL ) ;
F_59 ( V_99 , 0 ) ;
F_58 ( V_100 , NULL ) ;
F_58 ( V_101 , NULL ) ;
F_61 ( V_102 ) ;
F_61 ( V_103 ) ;
F_62 ( V_104 , 3 ) ;
F_58 ( V_105 , NULL ) ;
F_20 ( F_32 ( V_106 ) & ~ ( 1 << 6 ) , V_106 ) ;
V_3 = F_6 ( NULL , L_15 ) ;
if ( ! F_7 ( V_3 ) ) {
F_14 ( V_3 , F_13 ( V_3 , 119600000 ) ) ;
F_15 ( V_3 ) ;
}
F_58 ( V_107 , NULL ) ;
F_63 ( V_108 , V_109 ) ;
F_58 ( V_110 , NULL ) ;
F_63 ( V_111 , V_112 ) ;
F_58 ( V_113 , NULL ) ;
F_63 ( V_114 , V_109 ) ;
F_58 ( V_115 , NULL ) ;
F_58 ( V_116 , NULL ) ;
F_58 ( V_117 , NULL ) ;
F_58 ( V_118 , NULL ) ;
F_58 ( V_119 , NULL ) ;
F_58 ( V_120 , NULL ) ;
F_58 ( V_121 , NULL ) ;
F_58 ( V_122 , NULL ) ;
#if ! F_64 ( V_123 ) && ! F_64 ( V_124 )
F_58 ( V_125 , NULL ) ;
F_58 ( V_126 , NULL ) ;
F_58 ( V_127 , NULL ) ;
F_58 ( V_128 , NULL ) ;
F_58 ( V_129 , NULL ) ;
F_58 ( V_130 , NULL ) ;
#endif
F_58 ( V_46 , NULL ) ;
F_65 ( V_46 ) ;
F_58 ( V_131 , NULL ) ;
F_58 ( V_132 , NULL ) ;
F_58 ( V_133 , NULL ) ;
F_58 ( V_134 , NULL ) ;
F_58 ( V_135 , NULL ) ;
F_58 ( V_136 , NULL ) ;
F_58 ( V_47 , NULL ) ;
F_65 ( V_47 ) ;
F_58 ( V_137 , NULL ) ;
F_58 ( V_138 , NULL ) ;
F_58 ( V_139 , NULL ) ;
F_58 ( V_140 , NULL ) ;
F_58 ( V_141 , NULL ) ;
F_58 ( V_142 , NULL ) ;
F_58 ( V_143 , NULL ) ;
F_58 ( V_144 , NULL ) ;
F_58 ( V_145 , NULL ) ;
F_58 ( V_146 , NULL ) ;
F_58 ( V_147 , NULL ) ;
F_58 ( V_148 , NULL ) ;
F_58 ( V_149 , NULL ) ;
F_58 ( V_150 , NULL ) ;
F_58 ( V_151 , NULL ) ;
F_58 ( V_152 , NULL ) ;
F_58 ( V_153 , NULL ) ;
F_58 ( V_154 , NULL ) ;
F_58 ( V_155 , NULL ) ;
F_58 ( V_156 , NULL ) ;
F_58 ( V_157 , NULL ) ;
F_58 ( V_158 , NULL ) ;
F_58 ( V_159 , NULL ) ;
F_58 ( V_160 , NULL ) ;
F_58 ( V_161 , NULL ) ;
F_58 ( V_162 , NULL ) ;
F_58 ( V_163 , NULL ) ;
F_58 ( V_164 , NULL ) ;
F_58 ( V_165 , NULL ) ;
F_58 ( V_166 , NULL ) ;
F_58 ( V_167 , NULL ) ;
F_58 ( V_168 , NULL ) ;
F_58 ( V_169 , NULL ) ;
F_58 ( V_170 , NULL ) ;
F_58 ( V_171 , NULL ) ;
F_58 ( V_172 , NULL ) ;
F_58 ( V_173 , NULL ) ;
F_58 ( V_174 , NULL ) ;
F_58 ( V_175 , NULL ) ;
F_58 ( V_176 , NULL ) ;
F_58 ( V_177 , NULL ) ;
F_58 ( V_178 , NULL ) ;
F_58 ( V_179 , NULL ) ;
F_58 ( V_180 , NULL ) ;
F_58 ( V_181 , NULL ) ;
F_58 ( V_182 , NULL ) ;
F_58 ( V_183 , NULL ) ;
F_58 ( V_184 , NULL ) ;
F_58 ( V_185 , NULL ) ;
V_54 = F_66 ( V_186 ) ;
F_67 ( V_54 | ( 1 << 13 ) , V_186 ) ;
F_68 ( 50 ) ;
F_67 ( V_54 & ~ ( 1 << 13 ) , V_186 ) ;
F_69 ( 0 , V_187 ,
F_55 ( V_187 ) ) ;
F_69 ( 1 , V_188 ,
F_55 ( V_188 ) ) ;
F_70 () ;
F_71 ( V_189 , F_55 ( V_189 ) ) ;
F_72 ( & V_190 , & V_191 ) ;
F_72 ( & V_190 , & V_192 ) ;
F_72 ( & V_190 , & V_193 ) ;
F_72 ( & V_194 , & V_195 ) ;
F_72 ( & V_196 , & V_197 ) ;
F_72 ( & V_196 , & V_198 ) ;
F_72 ( & V_196 , & V_199 ) ;
F_72 ( & V_196 , & V_200 ) ;
F_72 ( & V_196 , & V_201 ) ;
#if ! F_64 ( V_123 ) && ! F_64 ( V_124 )
F_72 ( & V_196 , & V_202 ) ;
#endif
F_72 ( & V_196 , & V_203 ) ;
F_72 ( & V_204 , & V_205 ) ;
F_5 () ;
F_73 () ;
F_74 ( & V_195 . V_6 , L_16 ) ;
F_74 ( & V_192 . V_6 , L_17 ) ;
}
