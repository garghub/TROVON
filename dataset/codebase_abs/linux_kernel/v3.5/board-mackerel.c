static void T_1 F_1 ( T_2 V_1 )
{
F_2 ( 0x00 , V_1 ) ;
}
static void T_1 F_3 ( T_2 V_1 )
{
T_3 V_2 = F_4 ( V_1 ) ;
V_2 &= 0x0F ;
V_2 |= 0xA0 ;
F_2 ( V_2 , V_1 ) ;
}
static int F_5 ( int V_3 )
{
F_6 ( V_4 , V_3 ) ;
return 0 ;
}
static int F_7 ( void )
{
return F_8 ( V_4 ) ;
}
static void T_1 F_9 ( void )
{
struct V_5 * V_6 = F_10 ( & V_7 . V_8 , L_1 ) ;
int V_9 ;
long V_10 ;
if ( F_11 ( V_6 ) ) {
V_9 = F_12 ( V_6 ) ;
F_13 ( L_2 , V_9 ) ;
goto V_11;
}
V_9 = F_14 ( & V_12 , & V_13 ) ;
if ( V_9 < 0 ) {
F_13 ( L_3 ,
V_9 , V_12 . V_14 ) ;
goto V_11;
}
F_15 ( L_4 ,
F_16 ( & V_12 ) ) ;
V_10 = F_17 ( & V_12 , 594000000 ) ;
if ( V_10 < 0 ) {
F_13 ( L_5 , V_10 ) ;
V_9 = V_10 ;
goto V_11;
}
V_9 = F_18 ( & V_12 , V_10 ) ;
if ( V_9 < 0 ) {
F_13 ( L_6 , V_10 , V_9 ) ;
goto V_11;
}
F_15 ( L_7 , V_10 ) ;
V_9 = F_14 ( V_6 , & V_12 ) ;
if ( V_9 < 0 )
F_13 ( L_8 , V_9 ) ;
V_11:
if ( ! F_11 ( V_6 ) )
F_19 ( V_6 ) ;
}
static int F_20 ( struct V_15 * V_16 )
{
return F_21 ( F_22 ( V_16 ) ) ;
}
static void F_23 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_22 ( V_16 ) ;
F_24 ( 0x8a0a , V_18 -> V_19 ) ;
}
static int F_25 ( struct V_15 * V_16 )
{
return V_20 ;
}
static void F_26 ( struct V_21 * V_22 )
{
struct V_17 * V_18 = F_27 ( V_22 , struct V_17 ,
V_22 . V_22 ) ;
F_28 ( V_18 -> V_16 ) ;
F_29 ( & V_18 -> V_22 , V_23 ) ;
}
static int F_30 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_22 ( V_16 ) ;
V_18 -> V_16 = V_16 ;
F_31 ( & V_18 -> V_22 , F_26 ) ;
F_29 ( & V_18 -> V_22 , V_23 ) ;
return 0 ;
}
static void F_32 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_22 ( V_16 ) ;
F_33 ( & V_18 -> V_22 ) ;
}
static T_4 F_34 ( int V_24 , void * V_2 )
{
struct V_15 * V_16 = V_2 ;
struct V_17 * V_18 = F_22 ( V_16 ) ;
F_35 ( & V_16 -> V_8 , L_9 , V_25 ) ;
F_28 ( V_16 ) ;
F_24 ( F_36 ( V_18 -> V_26 ) | V_27 ,
V_18 -> V_26 ) ;
return V_28 ;
}
static int F_37 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_22 ( V_16 ) ;
int V_9 ;
F_24 ( V_29 | V_27 , V_18 -> V_26 ) ;
V_9 = F_38 ( V_30 , F_34 , V_31 ,
F_39 ( & V_16 -> V_8 ) , V_16 ) ;
if ( V_9 ) {
F_40 ( & V_16 -> V_8 , L_10 ) ;
return V_9 ;
}
F_24 ( V_29 | V_32 , V_18 -> V_26 ) ;
return 0 ;
}
static void F_41 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_22 ( V_16 ) ;
F_24 ( V_29 | V_27 , V_18 -> V_26 ) ;
F_42 ( V_30 , V_16 ) ;
}
static int F_43 ( struct V_15 * V_16 )
{
return V_33 ;
}
static int F_44 ( struct V_5 * V_5 , long V_10 , int V_34 )
{
int V_9 ;
if ( V_10 <= 0 )
return 0 ;
if ( ! V_34 ) {
F_45 ( V_5 ) ;
return 0 ;
}
V_9 = F_18 ( V_5 , F_17 ( V_5 , V_10 ) ) ;
if ( V_9 < 0 )
return V_9 ;
return F_46 ( V_5 ) ;
}
static int F_47 ( struct V_35 * V_8 , int V_10 , int V_34 )
{
struct V_5 * V_36 ;
struct V_5 * V_37 = & V_38 ;
long V_39 = 0 ;
long V_40 = 0 ;
int V_41 ;
int V_9 ;
switch ( V_10 ) {
case 44100 :
V_39 = V_10 * 256 ;
V_41 = V_42 | V_43 ;
break;
case 48000 :
V_39 = 85428000 ;
V_40 = V_10 * 256 ;
V_41 = V_42 | V_43 ;
break;
default:
F_13 ( L_11 ) ;
return - V_44 ;
}
V_36 = F_10 ( V_8 , L_12 ) ;
if ( F_11 ( V_36 ) )
return - V_45 ;
V_9 = F_44 ( V_36 , V_39 , V_34 ) ;
if ( V_9 < 0 )
goto V_46;
V_9 = F_44 ( V_37 , V_40 , V_34 ) ;
if ( V_9 < 0 ) {
if ( V_34 )
F_44 ( V_36 , V_39 , 0 ) ;
goto V_46;
}
V_9 = V_41 ;
V_46:
F_19 ( V_36 ) ;
return V_9 ;
}
static int F_48 ( struct V_15 * V_16 )
{
return ! F_8 ( V_47 ) ;
}
static int F_49 ( struct V_15 * V_16 )
{
return ! F_8 ( V_48 ) ;
}
static int F_50 ( struct V_49 * V_50 ,
int V_34 )
{
return 0 ;
}
static void F_51 ( struct V_35 * V_8 )
{
F_52 ( & V_51 ) ;
}
static int F_53 ( struct V_52 * V_53 )
{
return F_54 ( V_53 , & V_51 , & V_54 ,
F_51 , 0 ) ;
}
static void F_55 ( struct V_52 * V_53 )
{
F_56 ( V_53 , V_51 , & V_54 ) ;
}
static void T_1 F_57 ( void )
{
T_2 V_55 ;
struct V_5 * V_5 ;
F_18 ( & V_56 , 27000000 ) ;
F_58 () ;
F_59 ( V_57 , NULL ) ;
F_59 ( V_58 , NULL ) ;
F_59 ( V_59 , NULL ) ;
F_59 ( V_60 , NULL ) ;
F_59 ( V_61 , NULL ) ;
F_59 ( V_62 , NULL ) ;
F_59 ( V_63 , NULL ) ;
F_59 ( V_64 , NULL ) ;
F_59 ( V_65 , NULL ) ;
F_59 ( V_66 , NULL ) ;
F_59 ( V_67 , NULL ) ;
F_59 ( V_68 , NULL ) ;
F_59 ( V_69 , NULL ) ;
F_59 ( V_70 , NULL ) ;
F_59 ( V_71 , NULL ) ;
F_59 ( V_72 , NULL ) ;
F_59 ( V_73 , NULL ) ;
F_59 ( V_74 , NULL ) ;
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
F_59 ( V_4 , NULL ) ;
F_60 ( V_4 , 0 ) ;
F_59 ( V_87 , NULL ) ;
F_60 ( V_87 , 1 ) ;
F_59 ( V_88 , NULL ) ;
F_3 ( V_89 ) ;
F_59 ( V_90 , NULL ) ;
F_3 ( V_91 ) ;
F_59 ( V_92 , NULL ) ;
F_59 ( V_93 , NULL ) ;
F_59 ( V_94 , NULL ) ;
F_59 ( V_95 , NULL ) ;
F_59 ( V_96 , NULL ) ;
F_59 ( V_97 , NULL ) ;
F_60 ( V_97 , 0 ) ;
F_59 ( V_98 , NULL ) ;
F_59 ( V_99 , NULL ) ;
F_1 ( V_100 ) ;
F_1 ( V_101 ) ;
F_61 ( V_102 , 3 ) ;
F_59 ( V_103 , NULL ) ;
F_24 ( F_36 ( V_104 ) & ~ ( 1 << 6 ) , V_104 ) ;
V_5 = F_10 ( NULL , L_13 ) ;
if ( ! F_11 ( V_5 ) ) {
F_18 ( V_5 , F_17 ( V_5 , 119600000 ) ) ;
F_19 ( V_5 ) ;
}
F_59 ( V_105 , NULL ) ;
F_62 ( V_106 , V_107 ) ;
F_59 ( V_108 , NULL ) ;
F_62 ( V_109 , V_110 ) ;
F_59 ( V_111 , NULL ) ;
F_62 ( V_112 , V_107 ) ;
F_59 ( V_113 , NULL ) ;
F_59 ( V_114 , NULL ) ;
F_59 ( V_115 , NULL ) ;
F_59 ( V_116 , NULL ) ;
F_59 ( V_117 , NULL ) ;
F_59 ( V_118 , NULL ) ;
F_59 ( V_119 , NULL ) ;
F_59 ( V_120 , NULL ) ;
#if ! F_63 ( V_121 ) && ! F_63 ( V_122 )
F_59 ( V_123 , NULL ) ;
F_59 ( V_124 , NULL ) ;
F_59 ( V_125 , NULL ) ;
F_59 ( V_126 , NULL ) ;
F_59 ( V_127 , NULL ) ;
F_59 ( V_128 , NULL ) ;
#endif
F_59 ( V_47 , NULL ) ;
F_64 ( V_47 ) ;
F_59 ( V_129 , NULL ) ;
F_59 ( V_130 , NULL ) ;
F_59 ( V_131 , NULL ) ;
F_59 ( V_132 , NULL ) ;
F_59 ( V_133 , NULL ) ;
F_59 ( V_134 , NULL ) ;
F_59 ( V_48 , NULL ) ;
F_64 ( V_48 ) ;
F_59 ( V_135 , NULL ) ;
F_59 ( V_136 , NULL ) ;
F_59 ( V_137 , NULL ) ;
F_59 ( V_138 , NULL ) ;
F_59 ( V_139 , NULL ) ;
F_59 ( V_140 , NULL ) ;
F_59 ( V_141 , NULL ) ;
F_59 ( V_142 , NULL ) ;
F_59 ( V_143 , NULL ) ;
F_59 ( V_144 , NULL ) ;
F_59 ( V_145 , NULL ) ;
F_59 ( V_146 , NULL ) ;
F_59 ( V_147 , NULL ) ;
F_59 ( V_148 , NULL ) ;
F_59 ( V_149 , NULL ) ;
F_59 ( V_150 , NULL ) ;
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
V_55 = F_65 ( V_184 ) ;
F_66 ( V_55 | ( 1 << 13 ) , V_184 ) ;
F_67 ( 50 ) ;
F_66 ( V_55 & ~ ( 1 << 13 ) , V_184 ) ;
F_68 ( 0 , V_185 ,
F_69 ( V_185 ) ) ;
F_68 ( 1 , V_186 ,
F_69 ( V_186 ) ) ;
F_70 () ;
F_71 ( V_187 , F_69 ( V_187 ) ) ;
F_72 ( & V_188 , & V_189 ) ;
F_72 ( & V_188 , & V_190 ) ;
F_72 ( & V_188 , & V_191 ) ;
F_72 ( & V_192 , & V_193 ) ;
F_72 ( & V_194 , & V_195 ) ;
F_72 ( & V_194 , & V_196 ) ;
F_72 ( & V_194 , & V_197 ) ;
F_72 ( & V_194 , & V_198 ) ;
F_72 ( & V_194 , & V_199 ) ;
#if ! F_63 ( V_121 ) && ! F_63 ( V_122 )
F_72 ( & V_194 , & V_200 ) ;
#endif
F_72 ( & V_194 , & V_201 ) ;
F_72 ( & V_202 , & V_203 ) ;
F_9 () ;
F_73 () ;
F_74 ( & V_193 . V_8 , L_14 ) ;
F_74 ( & V_190 . V_8 , L_15 ) ;
}
