static int F_1 ( struct V_1 * V_2 )
{
return ! F_2 ( V_3 ) ;
}
static void F_3 ( int V_4 , int V_5 )
{
if ( ! V_5 )
return;
F_4 ( F_5 ( F_6 ( 0xE68B0008 ) ) | 0x600 , F_6 ( 0xE68B0008 ) ) ;
}
static int F_7 ( struct V_1 * V_2 ,
void T_1 * V_6 ,
int V_7 )
{
struct V_8 * V_9 = F_8 ( & V_2 -> V_10 , L_1 ) ;
if ( F_9 ( V_9 ) )
return F_10 ( V_9 ) ;
if ( V_7 ) {
F_11 ( V_9 , F_12 ( V_9 , 24000000 ) ) ;
F_13 ( V_9 ) ;
} else {
F_14 ( V_9 ) ;
}
F_15 ( V_9 ) ;
return 0 ;
}
static int F_16 ( struct V_8 * V_8 , long V_11 , int V_7 )
{
int V_12 = 0 ;
if ( V_11 <= 0 )
return V_12 ;
if ( V_7 ) {
V_12 = F_11 ( V_8 , V_11 ) ;
if ( 0 == V_12 )
V_12 = F_13 ( V_8 ) ;
} else {
F_14 ( V_8 ) ;
}
return V_12 ;
}
static int F_17 ( struct V_8 * V_8 , long V_11 , int V_7 )
{
return F_16 ( V_8 , F_12 ( V_8 , V_11 ) , V_7 ) ;
}
static int F_18 ( struct V_13 * V_10 , int V_11 , int V_7 )
{
struct V_8 * V_14 ;
struct V_8 * V_15 ;
int V_12 = - V_16 ;
V_14 = F_8 ( V_10 , L_2 ) ;
if ( F_9 ( V_14 ) )
return F_10 ( V_14 ) ;
V_15 = F_19 ( V_14 ) ;
if ( ! V_15 )
goto V_17;
V_12 = F_16 ( V_15 , V_11 , V_7 ) ;
if ( V_12 < 0 )
goto V_18;
V_12 = F_17 ( V_14 , V_11 , V_7 ) ;
if ( ( V_12 < 0 ) && V_7 )
F_17 ( V_15 , V_11 , 0 ) ;
V_18:
F_15 ( V_15 ) ;
V_17:
F_15 ( V_14 ) ;
return 0 ;
}
static int F_20 ( struct V_13 * V_10 , int V_11 , int V_7 )
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
F_21 ( L_3 ) ;
return - V_27 ;
}
V_19 = F_8 ( V_10 , L_4 ) ;
if ( F_9 ( V_19 ) )
return - V_16 ;
V_12 = F_17 ( V_19 , V_22 , V_7 ) ;
if ( V_12 < 0 )
goto V_28;
V_12 = F_17 ( V_20 , V_23 , V_7 ) ;
if ( V_12 < 0 ) {
if ( V_7 )
F_17 ( V_19 , V_22 , 0 ) ;
goto V_28;
}
V_12 = V_24 ;
V_28:
F_15 ( V_19 ) ;
return V_12 ;
}
static long F_22 ( unsigned long V_29 , unsigned long * V_30 ,
unsigned long * V_31 )
{
struct V_8 * V_32 = F_8 ( & V_33 . V_10 , L_5 ) ;
long error ;
if ( F_9 ( V_32 ) ) {
int V_12 = F_10 ( V_32 ) ;
F_21 ( L_6 , V_12 ) ;
return V_12 ;
}
error = F_23 ( V_32 , V_29 , V_30 , V_31 , 1 , 64 ) ;
F_15 ( V_32 ) ;
return error ;
}
static void T_2 F_24 ( void )
{
struct V_8 * V_32 = F_8 ( & V_33 . V_10 , L_5 ) ;
int V_12 ;
long V_11 ;
if ( F_9 ( V_32 ) ) {
V_12 = F_10 ( V_32 ) ;
F_21 ( L_6 , V_12 ) ;
goto V_34;
}
V_12 = F_25 ( & V_35 , & V_36 ) ;
if ( V_12 < 0 ) {
F_21 ( L_7 , V_12 , V_35 . V_37 ) ;
goto V_34;
}
F_26 ( L_8 , F_27 ( & V_35 ) ) ;
V_11 = F_12 ( & V_35 , 594000000 ) ;
if ( V_11 < 0 ) {
F_21 ( L_9 , V_11 ) ;
V_12 = V_11 ;
goto V_34;
}
V_12 = F_11 ( & V_35 , V_11 ) ;
if ( V_12 < 0 ) {
F_21 ( L_10 , V_11 , V_12 ) ;
goto V_34;
}
F_26 ( L_11 , V_11 ) ;
V_12 = F_25 ( V_32 , & V_35 ) ;
if ( V_12 < 0 )
F_21 ( L_12 , V_12 ) ;
V_34:
if ( ! F_9 ( V_32 ) )
F_15 ( V_32 ) ;
}
static void T_2 F_28 ( void )
{
struct V_8 * V_14 ;
int V_12 ;
V_14 = F_8 ( & V_38 . V_10 , L_2 ) ;
if ( F_9 ( V_14 ) ) {
V_12 = F_10 ( V_14 ) ;
F_21 ( L_13 , V_12 ) ;
return;
}
V_12 = F_25 ( V_14 , & V_39 ) ;
if ( V_12 < 0 )
F_21 ( L_14 , V_12 ) ;
F_15 ( V_14 ) ;
}
static int F_29 ( void )
{
int V_40 ;
F_30 ( V_41 ) ;
F_31 ( V_42 , NULL ) ;
F_32 ( V_42 ) ;
V_40 = F_2 ( V_42 ) ;
F_31 ( V_41 , NULL ) ;
return ! V_40 ;
}
static int F_33 ( void )
{
F_31 ( V_41 , NULL ) ;
return 0 ;
}
static void T_2 F_34 ( void )
{
struct V_43 V_44 [] = {
{ L_15 , & V_45 , } ,
{ L_15 , & V_46 , } ,
{ L_16 , & V_38 , } ,
{ L_17 , & V_47 , } ,
{ L_17 , & V_48 , } ,
{ L_17 , & V_49 , } ,
{ L_18 , & V_50 , } ,
} ;
T_3 V_51 ;
struct V_8 * V_8 ;
F_35 ( 0 , L_19 , V_52 ,
F_36 ( V_52 ) , 1800000 ) ;
F_35 ( 1 , L_20 , V_53 ,
F_36 ( V_53 ) , 3300000 ) ;
F_37 ( 2 , V_54 , F_36 ( V_54 ) ) ;
F_11 ( & V_55 , 27000000 ) ;
F_38 () ;
F_31 ( V_56 , NULL ) ;
F_31 ( V_57 , NULL ) ;
F_31 ( V_58 , NULL ) ;
F_31 ( V_59 , NULL ) ;
F_31 ( V_60 , NULL ) ;
F_31 ( V_61 , NULL ) ;
F_31 ( V_62 , NULL ) ;
F_31 ( V_63 , NULL ) ;
F_32 ( V_60 ) ;
F_32 ( V_61 ) ;
F_32 ( V_62 ) ;
F_32 ( V_63 ) ;
F_39 ( V_60 , 0 ) ;
F_39 ( V_61 , 0 ) ;
F_39 ( V_62 , 0 ) ;
F_39 ( V_63 , 0 ) ;
F_31 ( V_64 , NULL ) ;
F_31 ( V_65 , NULL ) ;
F_31 ( V_66 , NULL ) ;
F_31 ( V_67 , NULL ) ;
F_31 ( V_68 , NULL ) ;
F_31 ( V_69 , NULL ) ;
F_31 ( V_70 , NULL ) ;
F_31 ( V_71 , NULL ) ;
F_31 ( V_72 , NULL ) ;
F_31 ( V_73 , NULL ) ;
F_31 ( V_74 , NULL ) ;
F_31 ( V_75 , NULL ) ;
F_31 ( V_76 , NULL ) ;
F_31 ( V_77 , NULL ) ;
F_31 ( V_78 , NULL ) ;
F_31 ( V_79 , NULL ) ;
F_31 ( V_80 , NULL ) ;
F_31 ( V_81 , NULL ) ;
F_31 ( V_82 , NULL ) ;
F_31 ( V_83 , NULL ) ;
F_31 ( V_84 , NULL ) ;
F_31 ( V_85 , NULL ) ;
F_31 ( V_86 , NULL ) ;
F_31 ( V_87 , NULL ) ;
F_31 ( V_88 , NULL ) ;
F_31 ( V_89 , NULL ) ;
F_31 ( V_90 , NULL ) ;
F_31 ( V_91 , NULL ) ;
F_31 ( V_92 , NULL ) ;
F_31 ( V_93 , NULL ) ;
F_4 ( 0x8a0a , F_6 ( 0xE6058130 ) ) ;
F_31 ( V_94 , NULL ) ;
F_31 ( V_95 , NULL ) ;
F_31 ( V_96 , NULL ) ;
F_31 ( V_97 , NULL ) ;
F_31 ( V_98 , NULL ) ;
F_40 ( V_98 , 0 ) ;
F_31 ( V_99 , NULL ) ;
F_31 ( V_100 , NULL ) ;
F_41 ( V_101 ) ;
F_41 ( V_102 ) ;
F_31 ( V_3 , NULL ) ;
F_32 ( V_3 ) ;
F_31 ( V_103 , NULL ) ;
F_4 ( F_5 ( V_104 ) & ~ ( 1 << 6 ) , V_104 ) ;
V_8 = F_8 ( NULL , L_21 ) ;
if ( ! F_9 ( V_8 ) ) {
F_11 ( V_8 , F_12 ( V_8 , 119600000 ) ) ;
F_15 ( V_8 ) ;
}
F_42 ( V_105 , 3 ) ;
F_43 ( 0 , V_106 ,
F_36 ( V_106 ) ) ;
F_43 ( 1 , V_107 ,
F_36 ( V_107 ) ) ;
#ifdef F_44
F_31 ( V_108 , NULL ) ;
F_31 ( V_109 , NULL ) ;
F_31 ( V_110 , NULL ) ;
F_31 ( V_111 , NULL ) ;
F_31 ( V_112 , NULL ) ;
F_31 ( V_113 , NULL ) ;
F_31 ( V_114 , NULL ) ;
F_31 ( V_115 , NULL ) ;
F_31 ( V_116 , NULL ) ;
F_31 ( V_117 , NULL ) ;
F_45 ( V_118 , V_119 ) ;
V_120 . V_121 = V_118 ;
F_43 ( 1 , & V_120 , 1 ) ;
V_122 . V_123 = V_124 ;
V_122 . V_125 [ 0 ] . V_126 = V_127 ;
V_122 . V_125 [ 0 ] . V_128 = 1 ;
V_122 . V_125 [ 0 ] . V_129 = V_130 ;
V_122 . V_125 [ 0 ] . V_131 . V_132 = 44 ;
V_122 . V_125 [ 0 ] . V_131 . V_133 = 79 ;
F_46 ( V_134 , F_36 ( V_134 ) ) ;
#else
F_31 ( V_135 , NULL ) ;
F_31 ( V_136 , NULL ) ;
F_31 ( V_137 , NULL ) ;
F_31 ( V_138 , NULL ) ;
F_31 ( V_139 , NULL ) ;
F_31 ( V_140 , NULL ) ;
F_31 ( V_141 , NULL ) ;
F_31 ( V_142 , NULL ) ;
F_31 ( V_143 , NULL ) ;
F_31 ( V_144 , NULL ) ;
F_31 ( V_145 , NULL ) ;
F_31 ( V_146 , NULL ) ;
F_31 ( V_147 , NULL ) ;
F_31 ( V_148 , NULL ) ;
F_31 ( V_149 , NULL ) ;
F_31 ( V_150 , NULL ) ;
F_31 ( V_151 , NULL ) ;
F_31 ( V_152 , NULL ) ;
F_31 ( V_153 , NULL ) ;
F_31 ( V_154 , NULL ) ;
F_31 ( V_155 , NULL ) ;
F_40 ( V_155 , 1 ) ;
F_31 ( V_156 , NULL ) ;
F_40 ( V_156 , 1 ) ;
V_122 . V_123 = V_157 ;
V_122 . V_125 [ 0 ] . V_126 = V_158 ;
V_122 . V_125 [ 0 ] . V_128 = 3 ;
V_122 . V_125 [ 0 ] . V_129 = 0 ;
V_122 . V_125 [ 0 ] . V_131 . V_132 = 152 ;
V_122 . V_125 [ 0 ] . V_131 . V_133 = 91 ;
F_45 ( V_159 , V_119 ) ;
V_120 . V_121 = V_159 ;
F_43 ( 0 , & V_120 , 1 ) ;
#endif
F_31 ( V_160 , NULL ) ;
V_8 = F_8 ( NULL , L_22 ) ;
if ( ! F_9 ( V_8 ) ) {
F_11 ( V_8 , F_12 ( V_8 , 13000000 ) ) ;
F_13 ( V_8 ) ;
F_15 ( V_8 ) ;
}
F_47 () ;
F_31 ( V_161 , NULL ) ;
F_31 ( V_162 , NULL ) ;
#define F_48 IOMEM(0xe61580bc)
V_51 = F_49 ( F_48 ) ;
F_50 ( V_51 | ( 1 << 13 ) , F_48 ) ;
F_51 ( 50 ) ;
F_50 ( V_51 & ~ ( 1 << 13 ) , F_48 ) ;
F_46 ( V_163 , F_36 ( V_163 ) ) ;
F_52 ( V_44 ,
F_36 ( V_44 ) ) ;
F_24 () ;
F_28 () ;
F_53 () ;
F_54 ( & V_38 . V_10 , L_23 ) ;
F_54 ( & V_45 . V_10 , L_24 ) ;
}
