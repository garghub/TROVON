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
static int F_6 ( struct V_6 * V_6 , long V_7 , int V_8 )
{
int V_9 = 0 ;
if ( V_7 <= 0 )
return V_9 ;
if ( V_8 ) {
V_9 = F_7 ( V_6 , V_7 ) ;
if ( 0 == V_9 )
V_9 = F_8 ( V_6 ) ;
} else {
F_9 ( V_6 ) ;
}
return V_9 ;
}
static int F_10 ( struct V_6 * V_6 , long V_7 , int V_8 )
{
return F_6 ( V_6 , F_11 ( V_6 , V_7 ) , V_8 ) ;
}
static int F_12 ( struct V_10 * V_11 , int V_7 , int V_8 )
{
struct V_6 * V_12 ;
struct V_6 * V_13 ;
int V_9 = - V_14 ;
V_12 = F_13 ( V_11 , L_1 ) ;
if ( F_14 ( V_12 ) )
return F_15 ( V_12 ) ;
V_13 = F_16 ( V_12 ) ;
if ( ! V_13 )
goto V_15;
V_9 = F_6 ( V_13 , V_7 , V_8 ) ;
if ( V_9 < 0 )
goto V_16;
V_9 = F_10 ( V_12 , V_7 , V_8 ) ;
if ( ( V_9 < 0 ) && V_8 )
F_10 ( V_13 , V_7 , 0 ) ;
V_16:
F_17 ( V_13 ) ;
V_15:
F_17 ( V_12 ) ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 , int V_7 , int V_8 )
{
struct V_6 * V_17 ;
struct V_6 * V_18 = & V_19 ;
long V_20 = 0 ;
long V_21 = 0 ;
int V_22 ;
int V_9 ;
switch ( V_7 ) {
case 44100 :
V_20 = V_7 * 256 ;
V_22 = V_23 | V_24 ;
break;
case 48000 :
V_20 = 85428000 ;
V_21 = V_7 * 256 ;
V_22 = V_23 | V_24 ;
break;
default:
F_19 ( L_2 ) ;
return - V_25 ;
}
V_17 = F_13 ( V_11 , L_3 ) ;
if ( F_14 ( V_17 ) )
return - V_14 ;
V_9 = F_10 ( V_17 , V_20 , V_8 ) ;
if ( V_9 < 0 )
goto V_26;
V_9 = F_10 ( V_18 , V_21 , V_8 ) ;
if ( V_9 < 0 ) {
if ( V_8 )
F_10 ( V_17 , V_20 , 0 ) ;
goto V_26;
}
V_9 = V_22 ;
V_26:
F_17 ( V_17 ) ;
return V_9 ;
}
static int F_20 ( struct V_10 * V_11 , int V_27 , int V_7 , int V_8 )
{
int V_9 ;
if ( V_27 )
V_9 = F_12 ( V_11 , V_7 , V_8 ) ;
else
V_9 = F_18 ( V_11 , V_7 , V_8 ) ;
return V_9 ;
}
static long F_21 ( unsigned long V_28 , unsigned long * V_29 ,
unsigned long * V_30 )
{
struct V_6 * V_31 = F_13 ( & V_32 . V_11 , L_4 ) ;
long error ;
if ( F_14 ( V_31 ) ) {
int V_9 = F_15 ( V_31 ) ;
F_19 ( L_5 , V_9 ) ;
return V_9 ;
}
error = F_22 ( V_31 , V_28 , V_29 , V_30 , 1 , 64 ) ;
F_17 ( V_31 ) ;
return error ;
}
static void T_1 F_23 ( void )
{
struct V_6 * V_31 = F_13 ( & V_32 . V_11 , L_4 ) ;
int V_9 ;
long V_7 ;
if ( F_14 ( V_31 ) ) {
V_9 = F_15 ( V_31 ) ;
F_19 ( L_5 , V_9 ) ;
goto V_33;
}
V_9 = F_24 ( & V_34 , & V_35 ) ;
if ( V_9 < 0 ) {
F_19 ( L_6 , V_9 , V_34 . V_36 ) ;
goto V_33;
}
F_25 ( L_7 , F_26 ( & V_34 ) ) ;
V_7 = F_11 ( & V_34 , 594000000 ) ;
if ( V_7 < 0 ) {
F_19 ( L_8 , V_7 ) ;
V_9 = V_7 ;
goto V_33;
}
V_9 = F_7 ( & V_34 , V_7 ) ;
if ( V_9 < 0 ) {
F_19 ( L_9 , V_7 , V_9 ) ;
goto V_33;
}
F_25 ( L_10 , V_7 ) ;
V_9 = F_24 ( V_31 , & V_34 ) ;
if ( V_9 < 0 )
F_19 ( L_11 , V_9 ) ;
V_33:
if ( ! F_14 ( V_31 ) )
F_17 ( V_31 ) ;
}
static void T_1 F_27 ( void )
{
struct V_6 * V_12 ;
int V_9 ;
V_12 = F_13 ( & V_37 . V_11 , L_1 ) ;
if ( F_14 ( V_12 ) ) {
V_9 = F_15 ( V_12 ) ;
F_19 ( L_12 , V_9 ) ;
return;
}
V_9 = F_24 ( V_12 , & V_38 ) ;
if ( V_9 < 0 )
F_19 ( L_13 , V_9 ) ;
F_17 ( V_12 ) ;
}
static void T_1 F_28 ( T_2 V_39 )
{
F_29 ( 0x00 , V_39 ) ;
}
static int F_30 ( void )
{
int V_40 ;
F_31 ( V_41 ) ;
F_32 ( V_42 , NULL ) ;
F_33 ( V_42 ) ;
V_40 = F_2 ( V_42 ) ;
F_32 ( V_41 , NULL ) ;
return ! V_40 ;
}
static int F_34 ( void )
{
F_32 ( V_41 , NULL ) ;
return 0 ;
}
static void T_1 F_35 ( void )
{
F_36 ( V_43 , F_37 ( V_43 ) ) ;
F_38 () ;
F_39 () ;
}
static void T_1 F_40 ( void )
{
T_2 V_44 ;
struct V_6 * V_6 ;
F_41 () ;
F_32 ( V_45 , NULL ) ;
F_32 ( V_46 , NULL ) ;
F_32 ( V_47 , NULL ) ;
F_32 ( V_48 , NULL ) ;
F_32 ( V_49 , NULL ) ;
F_32 ( V_50 , NULL ) ;
F_32 ( V_51 , NULL ) ;
F_32 ( V_52 , NULL ) ;
F_33 ( V_49 ) ;
F_33 ( V_50 ) ;
F_33 ( V_51 ) ;
F_33 ( V_52 ) ;
F_42 ( V_49 , 0 ) ;
F_42 ( V_50 , 0 ) ;
F_42 ( V_51 , 0 ) ;
F_42 ( V_52 , 0 ) ;
F_32 ( V_53 , NULL ) ;
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
F_4 ( 0x8a0a , 0xE6058130 ) ;
F_32 ( V_83 , NULL ) ;
F_32 ( V_84 , NULL ) ;
F_32 ( V_85 , NULL ) ;
F_32 ( V_86 , NULL ) ;
F_32 ( V_87 , NULL ) ;
F_43 ( V_87 , 0 ) ;
F_32 ( V_88 , NULL ) ;
F_32 ( V_89 , NULL ) ;
F_28 ( V_90 ) ;
F_28 ( V_91 ) ;
F_32 ( V_3 , NULL ) ;
F_33 ( V_3 ) ;
F_32 ( V_92 , NULL ) ;
F_4 ( F_5 ( V_93 ) & ~ ( 1 << 6 ) , V_93 ) ;
V_6 = F_13 ( NULL , L_14 ) ;
if ( ! F_14 ( V_6 ) ) {
F_7 ( V_6 , F_11 ( V_6 , 119600000 ) ) ;
F_17 ( V_6 ) ;
}
F_44 ( V_94 , 3 ) ;
F_45 ( 0 , V_95 ,
F_37 ( V_95 ) ) ;
F_45 ( 1 , V_96 ,
F_37 ( V_96 ) ) ;
#ifdef F_46
F_32 ( V_97 , NULL ) ;
F_32 ( V_98 , NULL ) ;
F_32 ( V_99 , NULL ) ;
F_32 ( V_100 , NULL ) ;
F_32 ( V_101 , NULL ) ;
F_32 ( V_102 , NULL ) ;
F_32 ( V_103 , NULL ) ;
F_32 ( V_104 , NULL ) ;
F_32 ( V_105 , NULL ) ;
F_32 ( V_106 , NULL ) ;
F_47 ( V_107 , V_108 ) ;
V_109 . V_110 = V_107 ;
F_45 ( 1 , & V_109 , 1 ) ;
V_111 . V_112 = V_113 ;
V_111 . V_114 [ 0 ] . V_115 = V_116 ;
V_111 . V_114 [ 0 ] . V_117 = 1 ;
V_111 . V_114 [ 0 ] . V_118 = V_119 ;
V_111 . V_114 [ 0 ] . V_120 . V_121 = 44 ;
V_111 . V_114 [ 0 ] . V_120 . V_122 = 79 ;
F_48 ( V_123 , F_37 ( V_123 ) ) ;
#else
F_32 ( V_124 , NULL ) ;
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
F_43 ( V_144 , 1 ) ;
F_32 ( V_145 , NULL ) ;
F_43 ( V_145 , 1 ) ;
V_111 . V_112 = V_146 ;
V_111 . V_114 [ 0 ] . V_115 = V_147 ;
V_111 . V_114 [ 0 ] . V_117 = 3 ;
V_111 . V_114 [ 0 ] . V_118 = 0 ;
V_111 . V_114 [ 0 ] . V_120 . V_121 = 152 ;
V_111 . V_114 [ 0 ] . V_120 . V_122 = 91 ;
F_47 ( V_148 , V_108 ) ;
V_109 . V_110 = V_148 ;
F_45 ( 0 , & V_109 , 1 ) ;
#endif
F_32 ( V_149 , NULL ) ;
V_6 = F_13 ( NULL , L_15 ) ;
if ( ! F_14 ( V_6 ) ) {
F_7 ( V_6 , F_11 ( V_6 , 13000000 ) ) ;
F_8 ( V_6 ) ;
F_17 ( V_6 ) ;
}
F_49 () ;
F_32 ( V_150 , NULL ) ;
F_32 ( V_151 , NULL ) ;
#define F_50 0xe61580bc
V_44 = F_51 ( F_50 ) ;
F_52 ( V_44 | ( 1 << 13 ) , F_50 ) ;
F_53 ( 50 ) ;
F_52 ( V_44 & ~ ( 1 << 13 ) , F_50 ) ;
F_48 ( V_152 , F_37 ( V_152 ) ) ;
F_54 ( & V_153 , & V_154 ) ;
F_54 ( & V_153 , & V_155 ) ;
F_54 ( & V_156 , & V_37 ) ;
F_23 () ;
F_27 () ;
F_55 () ;
F_56 ( & V_37 . V_11 , L_16 ) ;
F_56 ( & V_154 . V_11 , L_17 ) ;
}
static void T_1 F_57 ( void )
{
F_58 () ;
V_157 . V_158 () ;
F_7 ( & V_159 , 27000000 ) ;
}
