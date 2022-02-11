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
if ( F_8 ( V_9 ) )
return F_9 ( V_9 ) ;
if ( V_7 ) {
F_10 ( V_9 , F_11 ( V_9 , 24000000 ) ) ;
F_12 ( V_9 ) ;
} else {
F_13 ( V_9 ) ;
}
F_14 ( V_9 ) ;
return 0 ;
}
static int F_15 ( struct V_8 * V_8 , long V_11 , int V_7 )
{
int V_12 = 0 ;
if ( V_11 <= 0 )
return V_12 ;
if ( V_7 ) {
V_12 = F_10 ( V_8 , V_11 ) ;
if ( 0 == V_12 )
V_12 = F_12 ( V_8 ) ;
} else {
F_13 ( V_8 ) ;
}
return V_12 ;
}
static int F_16 ( struct V_8 * V_8 , long V_11 , int V_7 )
{
return F_15 ( V_8 , F_11 ( V_8 , V_11 ) , V_7 ) ;
}
static int F_17 ( struct V_13 * V_10 , int V_11 , int V_7 )
{
struct V_8 * V_14 ;
struct V_8 * V_15 ;
int V_12 = - V_16 ;
V_14 = F_7 ( V_10 , L_2 ) ;
if ( F_8 ( V_14 ) )
return F_9 ( V_14 ) ;
V_15 = F_18 ( V_14 ) ;
if ( ! V_15 )
goto V_17;
V_12 = F_15 ( V_15 , V_11 , V_7 ) ;
if ( V_12 < 0 )
goto V_18;
V_12 = F_16 ( V_14 , V_11 , V_7 ) ;
if ( ( V_12 < 0 ) && V_7 )
F_16 ( V_15 , V_11 , 0 ) ;
V_18:
F_14 ( V_15 ) ;
V_17:
F_14 ( V_14 ) ;
return 0 ;
}
static int F_19 ( struct V_13 * V_10 , int V_11 , int V_7 )
{
struct V_8 * V_19 ;
struct V_8 * V_20 = & V_21 ;
long V_22 = 0 ;
long V_23 = 0 ;
int V_24 ;
int V_12 ;
switch ( V_11 ) {
case 44100 :
V_22 = V_11 * 256 ;
V_24 = V_25 | V_26 ;
break;
case 48000 :
V_22 = 85428000 ;
V_23 = V_11 * 256 ;
V_24 = V_25 | V_26 ;
break;
default:
F_20 ( L_3 ) ;
return - V_27 ;
}
V_19 = F_7 ( V_10 , L_4 ) ;
if ( F_8 ( V_19 ) )
return - V_16 ;
V_12 = F_16 ( V_19 , V_22 , V_7 ) ;
if ( V_12 < 0 )
goto V_28;
V_12 = F_16 ( V_20 , V_23 , V_7 ) ;
if ( V_12 < 0 ) {
if ( V_7 )
F_16 ( V_19 , V_22 , 0 ) ;
goto V_28;
}
V_12 = V_24 ;
V_28:
F_14 ( V_19 ) ;
return V_12 ;
}
static long F_21 ( unsigned long V_29 , unsigned long * V_30 ,
unsigned long * V_31 )
{
struct V_8 * V_32 = F_7 ( & V_33 . V_10 , L_5 ) ;
long error ;
if ( F_8 ( V_32 ) ) {
int V_12 = F_9 ( V_32 ) ;
F_20 ( L_6 , V_12 ) ;
return V_12 ;
}
error = F_22 ( V_32 , V_29 , V_30 , V_31 , 1 , 64 ) ;
F_14 ( V_32 ) ;
return error ;
}
static void T_2 F_23 ( void )
{
struct V_8 * V_32 = F_7 ( & V_33 . V_10 , L_5 ) ;
int V_12 ;
long V_11 ;
if ( F_8 ( V_32 ) ) {
V_12 = F_9 ( V_32 ) ;
F_20 ( L_6 , V_12 ) ;
goto V_34;
}
V_12 = F_24 ( & V_35 , & V_36 ) ;
if ( V_12 < 0 ) {
F_20 ( L_7 , V_12 , V_35 . V_37 ) ;
goto V_34;
}
F_25 ( L_8 , F_26 ( & V_35 ) ) ;
V_11 = F_11 ( & V_35 , 594000000 ) ;
if ( V_11 < 0 ) {
F_20 ( L_9 , V_11 ) ;
V_12 = V_11 ;
goto V_34;
}
V_12 = F_10 ( & V_35 , V_11 ) ;
if ( V_12 < 0 ) {
F_20 ( L_10 , V_11 , V_12 ) ;
goto V_34;
}
F_25 ( L_11 , V_11 ) ;
V_12 = F_24 ( V_32 , & V_35 ) ;
if ( V_12 < 0 )
F_20 ( L_12 , V_12 ) ;
V_34:
if ( ! F_8 ( V_32 ) )
F_14 ( V_32 ) ;
}
static void T_2 F_27 ( void )
{
struct V_8 * V_14 ;
int V_12 ;
V_14 = F_7 ( & V_38 . V_10 , L_2 ) ;
if ( F_8 ( V_14 ) ) {
V_12 = F_9 ( V_14 ) ;
F_20 ( L_13 , V_12 ) ;
return;
}
V_12 = F_24 ( V_14 , & V_39 ) ;
if ( V_12 < 0 )
F_20 ( L_14 , V_12 ) ;
F_14 ( V_14 ) ;
}
static void T_2 F_28 ( T_3 V_40 )
{
F_29 ( 0x00 , V_40 ) ;
}
static int F_30 ( void )
{
int V_41 ;
F_31 ( V_42 ) ;
F_32 ( V_43 , NULL ) ;
F_33 ( V_43 ) ;
V_41 = F_2 ( V_43 ) ;
F_32 ( V_42 , NULL ) ;
return ! V_41 ;
}
static int F_34 ( void )
{
F_32 ( V_42 , NULL ) ;
return 0 ;
}
static void T_2 F_35 ( void )
{
T_3 V_44 ;
struct V_8 * V_8 ;
F_10 ( & V_45 , 27000000 ) ;
F_36 () ;
F_32 ( V_46 , NULL ) ;
F_32 ( V_47 , NULL ) ;
F_32 ( V_48 , NULL ) ;
F_32 ( V_49 , NULL ) ;
F_32 ( V_50 , NULL ) ;
F_32 ( V_51 , NULL ) ;
F_32 ( V_52 , NULL ) ;
F_32 ( V_53 , NULL ) ;
F_33 ( V_50 ) ;
F_33 ( V_51 ) ;
F_33 ( V_52 ) ;
F_33 ( V_53 ) ;
F_37 ( V_50 , 0 ) ;
F_37 ( V_51 , 0 ) ;
F_37 ( V_52 , 0 ) ;
F_37 ( V_53 , 0 ) ;
F_32 ( V_54 , NULL ) ;
F_32 ( V_55 , NULL ) ;
F_32 ( V_56 , NULL ) ;
F_32 ( V_57 , NULL ) ;
F_32 ( V_58 , NULL ) ;
F_32 ( V_59 , NULL ) ;
F_32 ( V_60 , NULL ) ;
F_32 ( V_61 , NULL ) ;
F_32 ( V_62 , NULL ) ;
F_32 ( V_63 , NULL ) ;
F_32 ( V_64 , NULL ) ;
F_32 ( V_65 , NULL ) ;
F_32 ( V_66 , NULL ) ;
F_32 ( V_67 , NULL ) ;
F_32 ( V_68 , NULL ) ;
F_32 ( V_69 , NULL ) ;
F_32 ( V_70 , NULL ) ;
F_32 ( V_71 , NULL ) ;
F_32 ( V_72 , NULL ) ;
F_32 ( V_73 , NULL ) ;
F_32 ( V_74 , NULL ) ;
F_32 ( V_75 , NULL ) ;
F_32 ( V_76 , NULL ) ;
F_32 ( V_77 , NULL ) ;
F_32 ( V_78 , NULL ) ;
F_32 ( V_79 , NULL ) ;
F_32 ( V_80 , NULL ) ;
F_32 ( V_81 , NULL ) ;
F_32 ( V_82 , NULL ) ;
F_32 ( V_83 , NULL ) ;
F_4 ( 0x8a0a , 0xE6058130 ) ;
F_32 ( V_84 , NULL ) ;
F_32 ( V_85 , NULL ) ;
F_32 ( V_86 , NULL ) ;
F_32 ( V_87 , NULL ) ;
F_32 ( V_88 , NULL ) ;
F_38 ( V_88 , 0 ) ;
F_32 ( V_89 , NULL ) ;
F_32 ( V_90 , NULL ) ;
F_28 ( V_91 ) ;
F_28 ( V_92 ) ;
F_32 ( V_3 , NULL ) ;
F_33 ( V_3 ) ;
F_32 ( V_93 , NULL ) ;
F_4 ( F_5 ( V_94 ) & ~ ( 1 << 6 ) , V_94 ) ;
V_8 = F_7 ( NULL , L_15 ) ;
if ( ! F_8 ( V_8 ) ) {
F_10 ( V_8 , F_11 ( V_8 , 119600000 ) ) ;
F_14 ( V_8 ) ;
}
F_39 ( V_95 , 3 ) ;
F_40 ( 0 , V_96 ,
F_41 ( V_96 ) ) ;
F_40 ( 1 , V_97 ,
F_41 ( V_97 ) ) ;
#ifdef F_42
F_32 ( V_98 , NULL ) ;
F_32 ( V_99 , NULL ) ;
F_32 ( V_100 , NULL ) ;
F_32 ( V_101 , NULL ) ;
F_32 ( V_102 , NULL ) ;
F_32 ( V_103 , NULL ) ;
F_32 ( V_104 , NULL ) ;
F_32 ( V_105 , NULL ) ;
F_32 ( V_106 , NULL ) ;
F_32 ( V_107 , NULL ) ;
F_43 ( V_108 , V_109 ) ;
V_110 . V_111 = V_108 ;
F_40 ( 1 , & V_110 , 1 ) ;
V_112 . V_113 = V_114 ;
V_112 . V_115 [ 0 ] . V_116 = V_117 ;
V_112 . V_115 [ 0 ] . V_118 = 1 ;
V_112 . V_115 [ 0 ] . V_119 = V_120 ;
V_112 . V_115 [ 0 ] . V_121 . V_122 = 44 ;
V_112 . V_115 [ 0 ] . V_121 . V_123 = 79 ;
F_44 ( V_124 , F_41 ( V_124 ) ) ;
#else
F_32 ( V_125 , NULL ) ;
F_32 ( V_126 , NULL ) ;
F_32 ( V_127 , NULL ) ;
F_32 ( V_128 , NULL ) ;
F_32 ( V_129 , NULL ) ;
F_32 ( V_130 , NULL ) ;
F_32 ( V_131 , NULL ) ;
F_32 ( V_132 , NULL ) ;
F_32 ( V_133 , NULL ) ;
F_32 ( V_134 , NULL ) ;
F_32 ( V_135 , NULL ) ;
F_32 ( V_136 , NULL ) ;
F_32 ( V_137 , NULL ) ;
F_32 ( V_138 , NULL ) ;
F_32 ( V_139 , NULL ) ;
F_32 ( V_140 , NULL ) ;
F_32 ( V_141 , NULL ) ;
F_32 ( V_142 , NULL ) ;
F_32 ( V_143 , NULL ) ;
F_32 ( V_144 , NULL ) ;
F_32 ( V_145 , NULL ) ;
F_38 ( V_145 , 1 ) ;
F_32 ( V_146 , NULL ) ;
F_38 ( V_146 , 1 ) ;
V_112 . V_113 = V_147 ;
V_112 . V_115 [ 0 ] . V_116 = V_148 ;
V_112 . V_115 [ 0 ] . V_118 = 3 ;
V_112 . V_115 [ 0 ] . V_119 = 0 ;
V_112 . V_115 [ 0 ] . V_121 . V_122 = 152 ;
V_112 . V_115 [ 0 ] . V_121 . V_123 = 91 ;
F_43 ( V_149 , V_109 ) ;
V_110 . V_111 = V_149 ;
F_40 ( 0 , & V_110 , 1 ) ;
#endif
F_32 ( V_150 , NULL ) ;
V_8 = F_7 ( NULL , L_16 ) ;
if ( ! F_8 ( V_8 ) ) {
F_10 ( V_8 , F_11 ( V_8 , 13000000 ) ) ;
F_12 ( V_8 ) ;
F_14 ( V_8 ) ;
}
F_45 () ;
F_32 ( V_151 , NULL ) ;
F_32 ( V_152 , NULL ) ;
#define F_46 0xe61580bc
V_44 = F_47 ( F_46 ) ;
F_48 ( V_44 | ( 1 << 13 ) , F_46 ) ;
F_49 ( 50 ) ;
F_48 ( V_44 & ~ ( 1 << 13 ) , F_46 ) ;
F_44 ( V_153 , F_41 ( V_153 ) ) ;
F_50 ( & V_154 , & V_155 ) ;
F_50 ( & V_154 , & V_156 ) ;
F_50 ( & V_157 , & V_38 ) ;
F_50 ( & V_158 , & V_159 ) ;
F_50 ( & V_158 , & V_160 ) ;
F_50 ( & V_158 , & V_161 ) ;
F_50 ( & V_162 , & V_163 ) ;
F_23 () ;
F_27 () ;
F_51 () ;
F_52 ( & V_38 . V_10 , L_17 ) ;
F_52 ( & V_155 . V_10 , L_18 ) ;
}
