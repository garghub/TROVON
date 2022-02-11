static int F_1 ( struct V_1 * V_2 )
{
return ! F_2 ( V_3 ) ;
}
static void F_3 ( int V_4 , int V_5 )
{
if ( ! V_5 )
return;
F_4 ( F_5 ( 0xE68B0008 ) | 0x600 , 0xE68B0008 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
void T_1 * V_6 ,
int V_7 )
{
struct V_8 * V_9 = F_7 ( & V_2 -> V_10 , L_1 ) ;
void T_1 * V_11 = V_6 + V_12 ;
if ( F_8 ( V_9 ) )
return F_9 ( V_9 ) ;
if ( V_7 ) {
F_10 ( V_9 , F_11 ( V_9 , 24000000 ) ) ;
F_12 ( F_13 ( V_11 ) | ( 0xb << 8 ) , V_11 ) ;
F_14 ( V_9 ) ;
} else {
F_15 ( V_9 ) ;
}
F_16 ( V_9 ) ;
return 0 ;
}
static int F_17 ( struct V_8 * V_8 , long V_13 , int V_7 )
{
int V_14 = 0 ;
if ( V_13 <= 0 )
return V_14 ;
if ( V_7 ) {
V_14 = F_10 ( V_8 , V_13 ) ;
if ( 0 == V_14 )
V_14 = F_14 ( V_8 ) ;
} else {
F_15 ( V_8 ) ;
}
return V_14 ;
}
static int F_18 ( struct V_8 * V_8 , long V_13 , int V_7 )
{
return F_17 ( V_8 , F_11 ( V_8 , V_13 ) , V_7 ) ;
}
static int F_19 ( struct V_15 * V_10 , int V_13 , int V_7 )
{
struct V_8 * V_16 ;
struct V_8 * V_17 ;
int V_14 = - V_18 ;
V_16 = F_7 ( V_10 , L_2 ) ;
if ( F_8 ( V_16 ) )
return F_9 ( V_16 ) ;
V_17 = F_20 ( V_16 ) ;
if ( ! V_17 )
goto V_19;
V_14 = F_17 ( V_17 , V_13 , V_7 ) ;
if ( V_14 < 0 )
goto V_20;
V_14 = F_18 ( V_16 , V_13 , V_7 ) ;
if ( ( V_14 < 0 ) && V_7 )
F_18 ( V_17 , V_13 , 0 ) ;
V_20:
F_16 ( V_17 ) ;
V_19:
F_16 ( V_16 ) ;
return 0 ;
}
static int F_21 ( struct V_15 * V_10 , int V_13 , int V_7 )
{
struct V_8 * V_21 ;
struct V_8 * V_22 = & V_23 ;
long V_24 = 0 ;
long V_25 = 0 ;
int V_26 ;
int V_14 ;
switch ( V_13 ) {
case 44100 :
V_24 = V_13 * 256 ;
V_26 = V_27 | V_28 ;
break;
case 48000 :
V_24 = 85428000 ;
V_25 = V_13 * 256 ;
V_26 = V_27 | V_28 ;
break;
default:
F_22 ( L_3 ) ;
return - V_29 ;
}
V_21 = F_7 ( V_10 , L_4 ) ;
if ( F_8 ( V_21 ) )
return - V_18 ;
V_14 = F_18 ( V_21 , V_24 , V_7 ) ;
if ( V_14 < 0 )
goto V_30;
V_14 = F_18 ( V_22 , V_25 , V_7 ) ;
if ( V_14 < 0 ) {
if ( V_7 )
F_18 ( V_21 , V_24 , 0 ) ;
goto V_30;
}
V_14 = V_26 ;
V_30:
F_16 ( V_21 ) ;
return V_14 ;
}
static int F_23 ( struct V_15 * V_10 , int V_31 , int V_13 , int V_7 )
{
int V_14 ;
if ( V_31 )
V_14 = F_19 ( V_10 , V_13 , V_7 ) ;
else
V_14 = F_21 ( V_10 , V_13 , V_7 ) ;
return V_14 ;
}
static long F_24 ( unsigned long V_32 , unsigned long * V_33 ,
unsigned long * V_34 )
{
struct V_8 * V_35 = F_7 ( & V_36 . V_10 , L_5 ) ;
long error ;
if ( F_8 ( V_35 ) ) {
int V_14 = F_9 ( V_35 ) ;
F_22 ( L_6 , V_14 ) ;
return V_14 ;
}
error = F_25 ( V_35 , V_32 , V_33 , V_34 , 1 , 64 ) ;
F_16 ( V_35 ) ;
return error ;
}
static void T_2 F_26 ( void )
{
struct V_8 * V_35 = F_7 ( & V_36 . V_10 , L_5 ) ;
int V_14 ;
long V_13 ;
if ( F_8 ( V_35 ) ) {
V_14 = F_9 ( V_35 ) ;
F_22 ( L_6 , V_14 ) ;
goto V_37;
}
V_14 = F_27 ( & V_38 , & V_39 ) ;
if ( V_14 < 0 ) {
F_22 ( L_7 , V_14 , V_38 . V_40 ) ;
goto V_37;
}
F_28 ( L_8 , F_29 ( & V_38 ) ) ;
V_13 = F_11 ( & V_38 , 594000000 ) ;
if ( V_13 < 0 ) {
F_22 ( L_9 , V_13 ) ;
V_14 = V_13 ;
goto V_37;
}
V_14 = F_10 ( & V_38 , V_13 ) ;
if ( V_14 < 0 ) {
F_22 ( L_10 , V_13 , V_14 ) ;
goto V_37;
}
F_28 ( L_11 , V_13 ) ;
V_14 = F_27 ( V_35 , & V_38 ) ;
if ( V_14 < 0 )
F_22 ( L_12 , V_14 ) ;
V_37:
if ( ! F_8 ( V_35 ) )
F_16 ( V_35 ) ;
}
static void T_2 F_30 ( void )
{
struct V_8 * V_16 ;
int V_14 ;
V_16 = F_7 ( & V_41 . V_10 , L_2 ) ;
if ( F_8 ( V_16 ) ) {
V_14 = F_9 ( V_16 ) ;
F_22 ( L_13 , V_14 ) ;
return;
}
V_14 = F_27 ( V_16 , & V_42 ) ;
if ( V_14 < 0 )
F_22 ( L_14 , V_14 ) ;
F_16 ( V_16 ) ;
}
static void T_2 F_31 ( T_3 V_43 )
{
F_32 ( 0x00 , V_43 ) ;
}
static int F_33 ( void )
{
int V_44 ;
F_34 ( V_45 ) ;
F_35 ( V_46 , NULL ) ;
F_36 ( V_46 ) ;
V_44 = F_2 ( V_46 ) ;
F_35 ( V_45 , NULL ) ;
return ! V_44 ;
}
static int F_37 ( void )
{
F_35 ( V_45 , NULL ) ;
return 0 ;
}
static void T_2 F_38 ( void )
{
F_39 ( V_47 , F_40 ( V_47 ) ) ;
F_41 () ;
F_42 () ;
}
static void T_2 F_43 ( void )
{
T_3 V_48 ;
struct V_8 * V_8 ;
F_44 () ;
F_35 ( V_49 , NULL ) ;
F_35 ( V_50 , NULL ) ;
F_35 ( V_51 , NULL ) ;
F_35 ( V_52 , NULL ) ;
F_35 ( V_53 , NULL ) ;
F_35 ( V_54 , NULL ) ;
F_35 ( V_55 , NULL ) ;
F_35 ( V_56 , NULL ) ;
F_36 ( V_53 ) ;
F_36 ( V_54 ) ;
F_36 ( V_55 ) ;
F_36 ( V_56 ) ;
F_45 ( V_53 , 0 ) ;
F_45 ( V_54 , 0 ) ;
F_45 ( V_55 , 0 ) ;
F_45 ( V_56 , 0 ) ;
F_35 ( V_57 , NULL ) ;
F_35 ( V_58 , NULL ) ;
F_35 ( V_59 , NULL ) ;
F_35 ( V_60 , NULL ) ;
F_35 ( V_61 , NULL ) ;
F_35 ( V_62 , NULL ) ;
F_35 ( V_63 , NULL ) ;
F_35 ( V_64 , NULL ) ;
F_35 ( V_65 , NULL ) ;
F_35 ( V_66 , NULL ) ;
F_35 ( V_67 , NULL ) ;
F_35 ( V_68 , NULL ) ;
F_35 ( V_69 , NULL ) ;
F_35 ( V_70 , NULL ) ;
F_35 ( V_71 , NULL ) ;
F_35 ( V_72 , NULL ) ;
F_35 ( V_73 , NULL ) ;
F_35 ( V_74 , NULL ) ;
F_35 ( V_75 , NULL ) ;
F_35 ( V_76 , NULL ) ;
F_35 ( V_77 , NULL ) ;
F_35 ( V_78 , NULL ) ;
F_35 ( V_79 , NULL ) ;
F_35 ( V_80 , NULL ) ;
F_35 ( V_81 , NULL ) ;
F_35 ( V_82 , NULL ) ;
F_35 ( V_83 , NULL ) ;
F_35 ( V_84 , NULL ) ;
F_35 ( V_85 , NULL ) ;
F_35 ( V_86 , NULL ) ;
F_4 ( 0x8a0a , 0xE6058130 ) ;
F_35 ( V_87 , NULL ) ;
F_35 ( V_88 , NULL ) ;
F_35 ( V_89 , NULL ) ;
F_35 ( V_90 , NULL ) ;
F_35 ( V_91 , NULL ) ;
F_46 ( V_91 , 0 ) ;
F_35 ( V_92 , NULL ) ;
F_35 ( V_93 , NULL ) ;
F_31 ( V_94 ) ;
F_31 ( V_95 ) ;
F_35 ( V_3 , NULL ) ;
F_36 ( V_3 ) ;
F_35 ( V_96 , NULL ) ;
F_4 ( F_5 ( V_97 ) & ~ ( 1 << 6 ) , V_97 ) ;
V_8 = F_7 ( NULL , L_15 ) ;
if ( ! F_8 ( V_8 ) ) {
F_10 ( V_8 , F_11 ( V_8 , 119600000 ) ) ;
F_16 ( V_8 ) ;
}
F_47 ( V_98 , 3 ) ;
F_48 ( 0 , V_99 ,
F_40 ( V_99 ) ) ;
F_48 ( 1 , V_100 ,
F_40 ( V_100 ) ) ;
#ifdef F_49
F_35 ( V_101 , NULL ) ;
F_35 ( V_102 , NULL ) ;
F_35 ( V_103 , NULL ) ;
F_35 ( V_104 , NULL ) ;
F_35 ( V_105 , NULL ) ;
F_35 ( V_106 , NULL ) ;
F_35 ( V_107 , NULL ) ;
F_35 ( V_108 , NULL ) ;
F_35 ( V_109 , NULL ) ;
F_35 ( V_110 , NULL ) ;
F_50 ( V_111 , V_112 ) ;
V_113 . V_114 = V_111 ;
F_48 ( 1 , & V_113 , 1 ) ;
V_115 . V_116 = V_117 ;
V_115 . V_118 [ 0 ] . V_119 = V_120 ;
V_115 . V_118 [ 0 ] . V_121 = 1 ;
V_115 . V_118 [ 0 ] . V_122 = V_123 ;
V_115 . V_118 [ 0 ] . V_124 . V_125 = 44 ;
V_115 . V_118 [ 0 ] . V_124 . V_126 = 79 ;
F_51 ( V_127 , F_40 ( V_127 ) ) ;
#else
F_35 ( V_128 , NULL ) ;
F_35 ( V_129 , NULL ) ;
F_35 ( V_130 , NULL ) ;
F_35 ( V_131 , NULL ) ;
F_35 ( V_132 , NULL ) ;
F_35 ( V_133 , NULL ) ;
F_35 ( V_134 , NULL ) ;
F_35 ( V_135 , NULL ) ;
F_35 ( V_136 , NULL ) ;
F_35 ( V_137 , NULL ) ;
F_35 ( V_138 , NULL ) ;
F_35 ( V_139 , NULL ) ;
F_35 ( V_140 , NULL ) ;
F_35 ( V_141 , NULL ) ;
F_35 ( V_142 , NULL ) ;
F_35 ( V_143 , NULL ) ;
F_35 ( V_144 , NULL ) ;
F_35 ( V_145 , NULL ) ;
F_35 ( V_146 , NULL ) ;
F_35 ( V_147 , NULL ) ;
F_35 ( V_148 , NULL ) ;
F_46 ( V_148 , 1 ) ;
F_35 ( V_149 , NULL ) ;
F_46 ( V_149 , 1 ) ;
V_115 . V_116 = V_150 ;
V_115 . V_118 [ 0 ] . V_119 = V_151 ;
V_115 . V_118 [ 0 ] . V_121 = 3 ;
V_115 . V_118 [ 0 ] . V_122 = 0 ;
V_115 . V_118 [ 0 ] . V_124 . V_125 = 152 ;
V_115 . V_118 [ 0 ] . V_124 . V_126 = 91 ;
F_50 ( V_152 , V_112 ) ;
V_113 . V_114 = V_152 ;
F_48 ( 0 , & V_113 , 1 ) ;
#endif
F_35 ( V_153 , NULL ) ;
V_8 = F_7 ( NULL , L_16 ) ;
if ( ! F_8 ( V_8 ) ) {
F_10 ( V_8 , F_11 ( V_8 , 13000000 ) ) ;
F_14 ( V_8 ) ;
F_16 ( V_8 ) ;
}
F_52 () ;
F_35 ( V_154 , NULL ) ;
F_35 ( V_155 , NULL ) ;
#define F_53 0xe61580bc
V_48 = F_54 ( F_53 ) ;
F_55 ( V_48 | ( 1 << 13 ) , F_53 ) ;
F_56 ( 50 ) ;
F_55 ( V_48 & ~ ( 1 << 13 ) , F_53 ) ;
F_51 ( V_156 , F_40 ( V_156 ) ) ;
F_57 ( & V_157 , & V_158 ) ;
F_57 ( & V_157 , & V_159 ) ;
F_57 ( & V_160 , & V_41 ) ;
F_57 ( & V_161 , & V_162 ) ;
F_57 ( & V_161 , & V_163 ) ;
F_57 ( & V_161 , & V_164 ) ;
F_57 ( & V_165 , & V_166 ) ;
F_26 () ;
F_30 () ;
F_58 () ;
F_59 ( & V_41 . V_10 , L_17 ) ;
F_59 ( & V_158 . V_10 , L_18 ) ;
}
static void T_2 F_60 ( void )
{
F_61 () ;
V_167 . V_168 () ;
F_10 ( & V_169 , 27000000 ) ;
}
