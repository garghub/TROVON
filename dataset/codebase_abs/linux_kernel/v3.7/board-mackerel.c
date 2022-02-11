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
struct V_54 V_55 [] = {
{ L_13 , & V_56 , } ,
{ L_13 , & V_57 , } ,
{ L_13 , & V_58 , } ,
{ L_14 , & V_59 , } ,
{ L_15 , & V_60 , } ,
{ L_15 , & V_61 , } ,
{ L_15 , & V_62 , } ,
{ L_15 , & V_63 , } ,
{ L_15 , & V_64 , } ,
#if ! F_54 ( V_65 ) && ! F_54 ( V_66 )
{ L_15 , & V_67 , } ,
#endif
{ L_15 , & V_68 , } ,
{ L_16 , & V_69 , } ,
} ;
T_3 V_70 ;
struct V_3 * V_3 ;
F_55 ( 0 , L_17 , V_71 ,
F_56 ( V_71 ) , 1800000 ) ;
F_55 ( 1 , L_18 , V_72 ,
F_56 ( V_72 ) , 3300000 ) ;
F_57 ( 2 , V_73 , F_56 ( V_73 ) ) ;
F_14 ( & V_74 , 27000000 ) ;
F_58 () ;
F_59 ( V_75 , NULL ) ;
F_59 ( V_76 , NULL ) ;
F_59 ( V_77 , NULL ) ;
F_59 ( V_78 , NULL ) ;
F_59 ( V_79 , NULL ) ;
F_59 ( V_80 , NULL ) ;
F_59 ( V_81 , NULL ) ;
F_59 ( V_82 , NULL ) ;
F_59 ( V_83 , NULL ) ;
F_59 ( V_84 , NULL ) ;
F_59 ( V_85 , NULL ) ;
F_59 ( V_86 , NULL ) ;
F_59 ( V_87 , NULL ) ;
F_59 ( V_88 , NULL ) ;
F_59 ( V_89 , NULL ) ;
F_59 ( V_90 , NULL ) ;
F_59 ( V_91 , NULL ) ;
F_59 ( V_92 , NULL ) ;
F_59 ( V_93 , NULL ) ;
F_59 ( V_94 , NULL ) ;
F_59 ( V_95 , NULL ) ;
F_59 ( V_96 , NULL ) ;
F_59 ( V_97 , NULL ) ;
F_59 ( V_98 , NULL ) ;
F_59 ( V_99 , NULL ) ;
F_59 ( V_100 , NULL ) ;
F_59 ( V_101 , NULL ) ;
F_59 ( V_102 , NULL ) ;
F_59 ( V_103 , NULL ) ;
F_59 ( V_104 , NULL ) ;
F_59 ( V_2 , NULL ) ;
F_60 ( V_2 , 0 ) ;
F_59 ( V_105 , NULL ) ;
F_60 ( V_105 , 1 ) ;
F_59 ( V_106 , NULL ) ;
F_61 ( V_107 ) ;
F_59 ( V_108 , NULL ) ;
F_61 ( V_109 ) ;
F_59 ( V_110 , NULL ) ;
F_59 ( V_111 , NULL ) ;
F_59 ( V_112 , NULL ) ;
F_59 ( V_113 , NULL ) ;
F_59 ( V_114 , NULL ) ;
F_59 ( V_115 , NULL ) ;
F_60 ( V_115 , 0 ) ;
F_59 ( V_116 , NULL ) ;
F_59 ( V_117 , NULL ) ;
F_62 ( V_118 ) ;
F_62 ( V_119 ) ;
F_63 ( V_120 , 3 ) ;
F_59 ( V_121 , NULL ) ;
F_20 ( F_32 ( V_122 ) & ~ ( 1 << 6 ) , V_122 ) ;
V_3 = F_6 ( NULL , L_19 ) ;
if ( ! F_7 ( V_3 ) ) {
F_14 ( V_3 , F_13 ( V_3 , 119600000 ) ) ;
F_15 ( V_3 ) ;
}
F_59 ( V_123 , NULL ) ;
F_64 ( V_124 , V_125 ) ;
F_59 ( V_126 , NULL ) ;
F_64 ( V_127 , V_128 ) ;
F_59 ( V_129 , NULL ) ;
F_64 ( V_130 , V_125 ) ;
F_59 ( V_131 , NULL ) ;
F_59 ( V_132 , NULL ) ;
F_59 ( V_133 , NULL ) ;
F_59 ( V_134 , NULL ) ;
F_59 ( V_135 , NULL ) ;
F_59 ( V_136 , NULL ) ;
F_59 ( V_137 , NULL ) ;
F_59 ( V_138 , NULL ) ;
#if ! F_54 ( V_65 ) && ! F_54 ( V_66 )
F_59 ( V_139 , NULL ) ;
F_59 ( V_140 , NULL ) ;
F_59 ( V_141 , NULL ) ;
F_59 ( V_142 , NULL ) ;
F_59 ( V_143 , NULL ) ;
F_59 ( V_144 , NULL ) ;
#endif
F_59 ( V_46 , NULL ) ;
F_65 ( V_46 ) ;
F_59 ( V_145 , NULL ) ;
F_59 ( V_146 , NULL ) ;
F_59 ( V_147 , NULL ) ;
F_59 ( V_148 , NULL ) ;
F_59 ( V_149 , NULL ) ;
F_59 ( V_150 , NULL ) ;
F_59 ( V_47 , NULL ) ;
F_65 ( V_47 ) ;
F_59 ( V_151 , NULL ) ;
F_59 ( V_152 , NULL ) ;
F_59 ( V_153 , NULL ) ;
F_59 ( V_154 , NULL ) ;
F_59 ( V_155 , NULL ) ;
F_59 ( V_156 , NULL ) ;
F_59 ( V_157 , NULL ) ;
F_59 ( V_158 , NULL ) ;
F_59 ( V_159 , NULL ) ;
F_59 ( V_160 , NULL ) ;
F_59 ( V_161 , NULL ) ;
F_59 ( V_162 , NULL ) ;
F_59 ( V_163 , NULL ) ;
F_59 ( V_164 , NULL ) ;
F_59 ( V_165 , NULL ) ;
F_59 ( V_166 , NULL ) ;
F_59 ( V_167 , NULL ) ;
F_59 ( V_168 , NULL ) ;
F_59 ( V_169 , NULL ) ;
F_59 ( V_170 , NULL ) ;
F_59 ( V_171 , NULL ) ;
F_59 ( V_172 , NULL ) ;
F_59 ( V_173 , NULL ) ;
F_59 ( V_174 , NULL ) ;
F_59 ( V_175 , NULL ) ;
F_59 ( V_176 , NULL ) ;
F_59 ( V_177 , NULL ) ;
F_59 ( V_178 , NULL ) ;
F_59 ( V_179 , NULL ) ;
F_59 ( V_180 , NULL ) ;
F_59 ( V_181 , NULL ) ;
F_59 ( V_182 , NULL ) ;
F_59 ( V_183 , NULL ) ;
F_59 ( V_184 , NULL ) ;
F_59 ( V_185 , NULL ) ;
F_59 ( V_186 , NULL ) ;
F_59 ( V_187 , NULL ) ;
F_59 ( V_188 , NULL ) ;
F_59 ( V_189 , NULL ) ;
F_59 ( V_190 , NULL ) ;
F_59 ( V_191 , NULL ) ;
F_59 ( V_192 , NULL ) ;
F_59 ( V_193 , NULL ) ;
F_59 ( V_194 , NULL ) ;
F_59 ( V_195 , NULL ) ;
F_59 ( V_196 , NULL ) ;
F_59 ( V_197 , NULL ) ;
F_59 ( V_198 , NULL ) ;
F_59 ( V_199 , NULL ) ;
V_70 = F_66 ( V_200 ) ;
F_67 ( V_70 | ( 1 << 13 ) , V_200 ) ;
F_68 ( 50 ) ;
F_67 ( V_70 & ~ ( 1 << 13 ) , V_200 ) ;
F_69 ( 0 , V_201 ,
F_56 ( V_201 ) ) ;
F_69 ( 1 , V_202 ,
F_56 ( V_202 ) ) ;
F_70 () ;
F_71 ( V_203 , F_56 ( V_203 ) ) ;
F_72 ( V_55 ,
F_56 ( V_55 ) ) ;
F_5 () ;
F_73 () ;
F_74 ( & V_59 . V_6 , L_20 ) ;
F_74 ( & V_57 . V_6 , L_21 ) ;
}
