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
static int F_28 ( void )
{
int V_40 ;
F_29 ( V_41 ) ;
F_30 ( V_42 , NULL ) ;
F_31 ( V_42 ) ;
V_40 = F_2 ( V_42 ) ;
F_30 ( V_41 , NULL ) ;
return ! V_40 ;
}
static int F_32 ( void )
{
F_30 ( V_41 , NULL ) ;
return 0 ;
}
static void T_2 F_33 ( void )
{
T_3 V_43 ;
struct V_8 * V_8 ;
F_34 ( 0 , L_15 , V_44 ,
F_35 ( V_44 ) , 1800000 ) ;
F_34 ( 1 , L_16 , V_45 ,
F_35 ( V_45 ) , 3300000 ) ;
F_36 ( 2 , V_46 , F_35 ( V_46 ) ) ;
F_10 ( & V_47 , 27000000 ) ;
F_37 () ;
F_30 ( V_48 , NULL ) ;
F_30 ( V_49 , NULL ) ;
F_30 ( V_50 , NULL ) ;
F_30 ( V_51 , NULL ) ;
F_30 ( V_52 , NULL ) ;
F_30 ( V_53 , NULL ) ;
F_30 ( V_54 , NULL ) ;
F_30 ( V_55 , NULL ) ;
F_31 ( V_52 ) ;
F_31 ( V_53 ) ;
F_31 ( V_54 ) ;
F_31 ( V_55 ) ;
F_38 ( V_52 , 0 ) ;
F_38 ( V_53 , 0 ) ;
F_38 ( V_54 , 0 ) ;
F_38 ( V_55 , 0 ) ;
F_30 ( V_56 , NULL ) ;
F_30 ( V_57 , NULL ) ;
F_30 ( V_58 , NULL ) ;
F_30 ( V_59 , NULL ) ;
F_30 ( V_60 , NULL ) ;
F_30 ( V_61 , NULL ) ;
F_30 ( V_62 , NULL ) ;
F_30 ( V_63 , NULL ) ;
F_30 ( V_64 , NULL ) ;
F_30 ( V_65 , NULL ) ;
F_30 ( V_66 , NULL ) ;
F_30 ( V_67 , NULL ) ;
F_30 ( V_68 , NULL ) ;
F_30 ( V_69 , NULL ) ;
F_30 ( V_70 , NULL ) ;
F_30 ( V_71 , NULL ) ;
F_30 ( V_72 , NULL ) ;
F_30 ( V_73 , NULL ) ;
F_30 ( V_74 , NULL ) ;
F_30 ( V_75 , NULL ) ;
F_30 ( V_76 , NULL ) ;
F_30 ( V_77 , NULL ) ;
F_30 ( V_78 , NULL ) ;
F_30 ( V_79 , NULL ) ;
F_30 ( V_80 , NULL ) ;
F_30 ( V_81 , NULL ) ;
F_30 ( V_82 , NULL ) ;
F_30 ( V_83 , NULL ) ;
F_30 ( V_84 , NULL ) ;
F_30 ( V_85 , NULL ) ;
F_4 ( 0x8a0a , 0xE6058130 ) ;
F_30 ( V_86 , NULL ) ;
F_30 ( V_87 , NULL ) ;
F_30 ( V_88 , NULL ) ;
F_30 ( V_89 , NULL ) ;
F_30 ( V_90 , NULL ) ;
F_39 ( V_90 , 0 ) ;
F_30 ( V_91 , NULL ) ;
F_30 ( V_92 , NULL ) ;
F_40 ( V_93 ) ;
F_40 ( V_94 ) ;
F_30 ( V_3 , NULL ) ;
F_31 ( V_3 ) ;
F_30 ( V_95 , NULL ) ;
F_4 ( F_5 ( V_96 ) & ~ ( 1 << 6 ) , V_96 ) ;
V_8 = F_7 ( NULL , L_17 ) ;
if ( ! F_8 ( V_8 ) ) {
F_10 ( V_8 , F_11 ( V_8 , 119600000 ) ) ;
F_14 ( V_8 ) ;
}
F_41 ( V_97 , 3 ) ;
F_42 ( 0 , V_98 ,
F_35 ( V_98 ) ) ;
F_42 ( 1 , V_99 ,
F_35 ( V_99 ) ) ;
#ifdef F_43
F_30 ( V_100 , NULL ) ;
F_30 ( V_101 , NULL ) ;
F_30 ( V_102 , NULL ) ;
F_30 ( V_103 , NULL ) ;
F_30 ( V_104 , NULL ) ;
F_30 ( V_105 , NULL ) ;
F_30 ( V_106 , NULL ) ;
F_30 ( V_107 , NULL ) ;
F_30 ( V_108 , NULL ) ;
F_30 ( V_109 , NULL ) ;
F_44 ( V_110 , V_111 ) ;
V_112 . V_113 = V_110 ;
F_42 ( 1 , & V_112 , 1 ) ;
V_114 . V_115 = V_116 ;
V_114 . V_117 [ 0 ] . V_118 = V_119 ;
V_114 . V_117 [ 0 ] . V_120 = 1 ;
V_114 . V_117 [ 0 ] . V_121 = V_122 ;
V_114 . V_117 [ 0 ] . V_123 . V_124 = 44 ;
V_114 . V_117 [ 0 ] . V_123 . V_125 = 79 ;
F_45 ( V_126 , F_35 ( V_126 ) ) ;
#else
F_30 ( V_127 , NULL ) ;
F_30 ( V_128 , NULL ) ;
F_30 ( V_129 , NULL ) ;
F_30 ( V_130 , NULL ) ;
F_30 ( V_131 , NULL ) ;
F_30 ( V_132 , NULL ) ;
F_30 ( V_133 , NULL ) ;
F_30 ( V_134 , NULL ) ;
F_30 ( V_135 , NULL ) ;
F_30 ( V_136 , NULL ) ;
F_30 ( V_137 , NULL ) ;
F_30 ( V_138 , NULL ) ;
F_30 ( V_139 , NULL ) ;
F_30 ( V_140 , NULL ) ;
F_30 ( V_141 , NULL ) ;
F_30 ( V_142 , NULL ) ;
F_30 ( V_143 , NULL ) ;
F_30 ( V_144 , NULL ) ;
F_30 ( V_145 , NULL ) ;
F_30 ( V_146 , NULL ) ;
F_30 ( V_147 , NULL ) ;
F_39 ( V_147 , 1 ) ;
F_30 ( V_148 , NULL ) ;
F_39 ( V_148 , 1 ) ;
V_114 . V_115 = V_149 ;
V_114 . V_117 [ 0 ] . V_118 = V_150 ;
V_114 . V_117 [ 0 ] . V_120 = 3 ;
V_114 . V_117 [ 0 ] . V_121 = 0 ;
V_114 . V_117 [ 0 ] . V_123 . V_124 = 152 ;
V_114 . V_117 [ 0 ] . V_123 . V_125 = 91 ;
F_44 ( V_151 , V_111 ) ;
V_112 . V_113 = V_151 ;
F_42 ( 0 , & V_112 , 1 ) ;
#endif
F_30 ( V_152 , NULL ) ;
V_8 = F_7 ( NULL , L_18 ) ;
if ( ! F_8 ( V_8 ) ) {
F_10 ( V_8 , F_11 ( V_8 , 13000000 ) ) ;
F_12 ( V_8 ) ;
F_14 ( V_8 ) ;
}
F_46 () ;
F_30 ( V_153 , NULL ) ;
F_30 ( V_154 , NULL ) ;
#define F_47 0xe61580bc
V_43 = F_48 ( F_47 ) ;
F_49 ( V_43 | ( 1 << 13 ) , F_47 ) ;
F_50 ( 50 ) ;
F_49 ( V_43 & ~ ( 1 << 13 ) , F_47 ) ;
F_45 ( V_155 , F_35 ( V_155 ) ) ;
F_51 ( & V_156 , & V_157 ) ;
F_51 ( & V_156 , & V_158 ) ;
F_51 ( & V_159 , & V_38 ) ;
F_51 ( & V_160 , & V_161 ) ;
F_51 ( & V_160 , & V_162 ) ;
F_51 ( & V_160 , & V_163 ) ;
F_51 ( & V_164 , & V_165 ) ;
F_23 () ;
F_27 () ;
F_52 () ;
F_53 ( & V_38 . V_10 , L_19 ) ;
F_53 ( & V_157 . V_10 , L_20 ) ;
}
