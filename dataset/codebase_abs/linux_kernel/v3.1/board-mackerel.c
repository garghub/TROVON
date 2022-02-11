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
static int F_5 ( void * V_3 , int V_4 )
{
F_6 ( V_5 , V_4 ) ;
return 0 ;
}
static int F_7 ( void * V_3 )
{
return F_8 ( V_5 ) ;
}
static void T_1 F_9 ( void )
{
struct V_6 * V_7 = F_10 ( & V_8 . V_9 , L_1 ) ;
int V_10 ;
long V_11 ;
if ( F_11 ( V_7 ) ) {
V_10 = F_12 ( V_7 ) ;
F_13 ( L_2 , V_10 ) ;
goto V_12;
}
V_10 = F_14 ( & V_13 , & V_14 ) ;
if ( V_10 < 0 ) {
F_13 ( L_3 ,
V_10 , V_13 . V_15 ) ;
goto V_12;
}
F_15 ( L_4 ,
F_16 ( & V_13 ) ) ;
V_11 = F_17 ( & V_13 , 594000000 ) ;
if ( V_11 < 0 ) {
F_13 ( L_5 , V_11 ) ;
V_10 = V_11 ;
goto V_12;
}
V_10 = F_18 ( & V_13 , V_11 ) ;
if ( V_10 < 0 ) {
F_13 ( L_6 , V_11 , V_10 ) ;
goto V_12;
}
F_15 ( L_7 , V_11 ) ;
V_10 = F_14 ( V_7 , & V_13 ) ;
if ( V_10 < 0 )
F_13 ( L_8 , V_10 ) ;
V_12:
if ( ! F_11 ( V_7 ) )
F_19 ( V_7 ) ;
}
static int F_20 ( struct V_16 * V_17 )
{
return F_21 ( F_22 ( V_17 ) ) ;
}
static void F_23 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_22 ( V_17 ) ;
F_24 ( 0x8a0a , V_19 -> V_20 ) ;
}
static int F_25 ( struct V_16 * V_17 )
{
return V_21 ;
}
static void F_26 ( struct V_22 * V_23 )
{
struct V_18 * V_19 = F_27 ( V_23 , struct V_18 ,
V_23 . V_23 ) ;
F_28 ( V_19 -> V_17 ) ;
F_29 ( & V_19 -> V_23 , V_24 ) ;
}
static int F_30 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_22 ( V_17 ) ;
V_19 -> V_17 = V_17 ;
F_31 ( & V_19 -> V_23 , F_26 ) ;
F_29 ( & V_19 -> V_23 , V_24 ) ;
return 0 ;
}
static void F_32 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_22 ( V_17 ) ;
F_33 ( & V_19 -> V_23 ) ;
}
static void F_34 ( int V_25 , int V_26 )
{
if ( ! V_26 )
return;
F_24 ( F_35 ( 0xE68B0008 ) | 0x600 , 0xE68B0008 ) ;
}
static T_4 F_36 ( int V_27 , void * V_2 )
{
struct V_16 * V_17 = V_2 ;
struct V_18 * V_19 = F_22 ( V_17 ) ;
F_37 ( & V_17 -> V_9 , L_9 , V_28 ) ;
F_28 ( V_17 ) ;
F_24 ( F_35 ( V_19 -> V_29 ) | V_30 ,
V_19 -> V_29 ) ;
return V_31 ;
}
static int F_38 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_22 ( V_17 ) ;
int V_10 ;
F_24 ( V_32 | V_30 , V_19 -> V_29 ) ;
V_10 = F_39 ( V_33 , F_36 , V_34 ,
F_40 ( & V_17 -> V_9 ) , V_17 ) ;
if ( V_10 ) {
F_41 ( & V_17 -> V_9 , L_10 ) ;
return V_10 ;
}
F_24 ( V_32 | V_35 , V_19 -> V_29 ) ;
return 0 ;
}
static void F_42 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_22 ( V_17 ) ;
F_24 ( V_32 | V_30 , V_19 -> V_29 ) ;
F_43 ( V_33 , V_17 ) ;
}
static int F_44 ( struct V_16 * V_17 )
{
return V_21 ;
}
static int F_45 ( struct V_6 * V_6 , long V_11 , int V_36 )
{
int V_10 ;
if ( V_11 <= 0 )
return 0 ;
if ( ! V_36 ) {
F_46 ( V_6 ) ;
return 0 ;
}
V_10 = F_18 ( V_6 , F_17 ( V_6 , V_11 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return F_47 ( V_6 ) ;
}
static int F_48 ( struct V_37 * V_9 , int V_38 , int V_11 , int V_36 )
{
struct V_6 * V_39 ;
struct V_6 * V_40 = & V_41 ;
long V_42 = 0 ;
long V_43 = 0 ;
int V_44 ;
int V_10 ;
if ( V_38 )
return 0 ;
switch ( V_11 ) {
case 44100 :
V_42 = V_11 * 256 ;
V_44 = V_45 | V_46 ;
break;
case 48000 :
V_42 = 85428000 ;
V_43 = V_11 * 256 ;
V_44 = V_45 | V_46 ;
break;
default:
F_13 ( L_11 ) ;
return - V_47 ;
}
V_39 = F_10 ( V_9 , L_12 ) ;
if ( F_11 ( V_39 ) )
return - V_48 ;
V_10 = F_45 ( V_39 , V_42 , V_36 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_45 ( V_40 , V_43 , V_36 ) ;
if ( V_10 < 0 ) {
if ( V_36 )
F_45 ( V_39 , V_42 , 0 ) ;
goto V_49;
}
V_10 = V_44 ;
V_49:
F_19 ( V_39 ) ;
return V_10 ;
}
static int F_49 ( struct V_16 * V_17 )
{
return ! F_8 ( V_50 ) ;
}
static T_4 F_50 ( int V_27 , void * V_51 )
{
struct V_37 * V_9 = V_51 ;
struct V_52 * V_53 = V_9 -> V_54 ;
struct V_55 * V_56 = V_53 -> V_56 ;
F_51 ( V_56 ) ;
return V_31 ;
}
static int F_52 ( struct V_16 * V_17 )
{
return ! F_8 ( V_57 ) ;
}
static int F_53 ( struct V_58 * V_53 ,
int V_36 )
{
return 0 ;
}
static void F_54 ( struct V_37 * V_9 )
{
F_55 ( & V_59 ) ;
}
static int F_56 ( struct V_60 * V_61 )
{
return F_57 ( V_61 , & V_59 , & V_62 ,
F_54 , 0 ) ;
}
static void F_58 ( struct V_60 * V_61 )
{
F_59 ( V_61 , V_59 , & V_62 ) ;
}
static void T_1 F_60 ( void )
{
F_61 ( V_63 , F_62 ( V_63 ) ) ;
F_63 () ;
F_64 () ;
}
static void T_1 F_65 ( void )
{
T_2 V_64 ;
struct V_6 * V_6 ;
int V_10 ;
F_66 () ;
F_67 ( V_65 , NULL ) ;
F_67 ( V_66 , NULL ) ;
F_67 ( V_67 , NULL ) ;
F_67 ( V_68 , NULL ) ;
F_67 ( V_69 , NULL ) ;
F_67 ( V_70 , NULL ) ;
F_67 ( V_71 , NULL ) ;
F_67 ( V_72 , NULL ) ;
F_67 ( V_73 , NULL ) ;
F_67 ( V_74 , NULL ) ;
F_67 ( V_75 , NULL ) ;
F_67 ( V_76 , NULL ) ;
F_67 ( V_77 , NULL ) ;
F_67 ( V_78 , NULL ) ;
F_67 ( V_79 , NULL ) ;
F_67 ( V_80 , NULL ) ;
F_67 ( V_81 , NULL ) ;
F_67 ( V_82 , NULL ) ;
F_67 ( V_83 , NULL ) ;
F_67 ( V_84 , NULL ) ;
F_67 ( V_85 , NULL ) ;
F_67 ( V_86 , NULL ) ;
F_67 ( V_87 , NULL ) ;
F_67 ( V_88 , NULL ) ;
F_67 ( V_89 , NULL ) ;
F_67 ( V_90 , NULL ) ;
F_67 ( V_91 , NULL ) ;
F_67 ( V_92 , NULL ) ;
F_67 ( V_93 , NULL ) ;
F_67 ( V_94 , NULL ) ;
F_67 ( V_5 , NULL ) ;
F_68 ( V_5 , 0 ) ;
F_67 ( V_95 , NULL ) ;
F_68 ( V_95 , 1 ) ;
F_67 ( V_96 , NULL ) ;
F_3 ( V_97 ) ;
F_67 ( V_98 , NULL ) ;
F_3 ( V_99 ) ;
F_67 ( V_100 , NULL ) ;
F_24 ( 0x8a0a , 0xe6058130 ) ;
F_67 ( V_101 , NULL ) ;
F_67 ( V_102 , NULL ) ;
F_67 ( V_103 , NULL ) ;
F_67 ( V_104 , NULL ) ;
F_67 ( V_105 , NULL ) ;
F_68 ( V_105 , 0 ) ;
F_67 ( V_106 , NULL ) ;
F_67 ( V_107 , NULL ) ;
F_1 ( V_108 ) ;
F_1 ( V_109 ) ;
F_69 ( V_110 , 3 ) ;
F_67 ( V_111 , NULL ) ;
F_24 ( F_35 ( V_112 ) & ~ ( 1 << 6 ) , V_112 ) ;
V_6 = F_10 ( NULL , L_13 ) ;
if ( ! F_11 ( V_6 ) ) {
F_18 ( V_6 , F_17 ( V_6 , 119600000 ) ) ;
F_19 ( V_6 ) ;
}
F_67 ( V_113 , NULL ) ;
F_70 ( V_114 , V_115 ) ;
F_67 ( V_116 , NULL ) ;
F_70 ( V_117 , V_118 ) ;
F_67 ( V_119 , NULL ) ;
F_70 ( V_120 , V_115 ) ;
F_67 ( V_121 , NULL ) ;
F_67 ( V_122 , NULL ) ;
F_67 ( V_123 , NULL ) ;
F_67 ( V_124 , NULL ) ;
F_67 ( V_125 , NULL ) ;
F_67 ( V_126 , NULL ) ;
F_67 ( V_127 , NULL ) ;
F_67 ( V_128 , NULL ) ;
V_10 = F_39 ( F_71 ( 0x3340 ) , F_50 ,
V_129 , L_14 , & V_130 . V_9 ) ;
if ( ! V_10 )
V_131 . V_132 |= V_133 ;
else
F_13 ( L_15 , F_71 ( 0x3340 ) , V_10 ) ;
#if ! F_72 ( V_134 ) && ! F_72 ( V_135 )
F_67 ( V_136 , NULL ) ;
F_67 ( V_137 , NULL ) ;
F_67 ( V_138 , NULL ) ;
F_67 ( V_139 , NULL ) ;
F_67 ( V_140 , NULL ) ;
F_67 ( V_141 , NULL ) ;
#endif
F_67 ( V_50 , NULL ) ;
F_73 ( V_50 ) ;
F_67 ( V_142 , NULL ) ;
F_67 ( V_143 , NULL ) ;
F_67 ( V_144 , NULL ) ;
F_67 ( V_145 , NULL ) ;
F_67 ( V_146 , NULL ) ;
F_67 ( V_147 , NULL ) ;
F_67 ( V_57 , NULL ) ;
F_73 ( V_57 ) ;
F_67 ( V_148 , NULL ) ;
F_67 ( V_149 , NULL ) ;
F_67 ( V_150 , NULL ) ;
F_67 ( V_151 , NULL ) ;
F_67 ( V_152 , NULL ) ;
F_67 ( V_153 , NULL ) ;
F_67 ( V_154 , NULL ) ;
F_67 ( V_155 , NULL ) ;
F_67 ( V_156 , NULL ) ;
F_67 ( V_157 , NULL ) ;
F_67 ( V_158 , NULL ) ;
F_67 ( V_159 , NULL ) ;
F_67 ( V_160 , NULL ) ;
F_67 ( V_161 , NULL ) ;
F_67 ( V_162 , NULL ) ;
F_67 ( V_163 , NULL ) ;
F_67 ( V_164 , NULL ) ;
F_67 ( V_165 , NULL ) ;
F_67 ( V_166 , NULL ) ;
F_67 ( V_167 , NULL ) ;
F_67 ( V_168 , NULL ) ;
F_67 ( V_169 , NULL ) ;
F_67 ( V_170 , NULL ) ;
F_67 ( V_171 , NULL ) ;
F_67 ( V_172 , NULL ) ;
F_67 ( V_173 , NULL ) ;
F_67 ( V_174 , NULL ) ;
V_64 = F_74 ( V_175 ) ;
F_75 ( V_64 | ( 1 << 13 ) , V_175 ) ;
F_76 ( 50 ) ;
F_75 ( V_64 & ~ ( 1 << 13 ) , V_175 ) ;
F_77 ( 0 , V_176 ,
F_62 ( V_176 ) ) ;
F_77 ( 1 , V_177 ,
F_62 ( V_177 ) ) ;
F_78 () ;
F_79 ( V_178 , F_62 ( V_178 ) ) ;
F_80 ( & V_179 , & V_180 ) ;
F_80 ( & V_179 , & V_181 ) ;
F_80 ( & V_182 , & V_183 ) ;
F_9 () ;
F_81 () ;
F_82 ( & V_183 . V_9 , L_16 ) ;
F_82 ( & V_181 . V_9 , L_17 ) ;
}
static void T_1 F_83 ( void )
{
F_84 () ;
V_184 . V_185 () ;
F_18 ( & V_186 , 27000000 ) ;
}
