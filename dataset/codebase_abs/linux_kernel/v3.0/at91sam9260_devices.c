void T_1 F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
V_3 = * V_2 ;
F_2 ( & V_4 ) ;
}
void T_1 F_1 ( struct V_1 * V_2 ) {}
void T_1 F_3 ( struct V_5 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_6 ) {
F_4 ( V_2 -> V_6 , 0 ) ;
F_5 ( V_2 -> V_6 , 1 ) ;
}
V_7 = * V_2 ;
F_2 ( & V_8 ) ;
}
void T_1 F_3 ( struct V_5 * V_2 ) {}
void T_1 F_6 ( struct V_9 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_10 ) {
F_4 ( V_2 -> V_10 , 0 ) ;
F_5 ( V_2 -> V_10 , 1 ) ;
}
F_7 ( V_11 , 0 ) ;
F_7 ( V_12 , 0 ) ;
F_7 ( V_13 , 0 ) ;
F_7 ( V_14 , 0 ) ;
F_7 ( V_15 , 0 ) ;
F_7 ( V_16 , 0 ) ;
F_7 ( V_17 , 0 ) ;
F_7 ( V_18 , 0 ) ;
F_7 ( V_19 , 0 ) ;
F_7 ( V_20 , 0 ) ;
if ( ! V_2 -> V_21 ) {
F_8 ( V_22 , 0 ) ;
F_8 ( V_23 , 0 ) ;
F_8 ( V_24 , 0 ) ;
F_8 ( V_25 , 0 ) ;
F_8 ( V_26 , 0 ) ;
F_8 ( V_27 , 0 ) ;
F_8 ( V_28 , 0 ) ;
F_8 ( V_29 , 0 ) ;
}
V_30 = * V_2 ;
F_2 ( & V_31 ) ;
}
void T_1 F_6 ( struct V_9 * V_2 ) {}
void T_1 F_9 ( short V_32 , struct V_33 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_34 ) {
F_4 ( V_2 -> V_34 , 1 ) ;
F_5 ( V_2 -> V_34 , 1 ) ;
}
if ( V_2 -> V_35 )
F_4 ( V_2 -> V_35 , 1 ) ;
if ( V_2 -> V_36 )
F_10 ( V_2 -> V_36 , 0 ) ;
F_7 ( V_37 , 0 ) ;
if ( V_2 -> V_38 ) {
F_8 ( V_39 , 1 ) ;
F_8 ( V_40 , 1 ) ;
if ( V_2 -> V_41 ) {
F_8 ( V_42 , 1 ) ;
F_8 ( V_43 , 1 ) ;
F_8 ( V_44 , 1 ) ;
}
} else {
F_7 ( V_45 , 1 ) ;
F_7 ( V_46 , 1 ) ;
if ( V_2 -> V_41 ) {
F_7 ( V_47 , 1 ) ;
F_7 ( V_48 , 1 ) ;
F_7 ( V_49 , 1 ) ;
}
}
V_50 = * V_2 ;
F_2 ( & V_51 ) ;
}
void T_1 F_9 ( short V_32 , struct V_33 * V_2 ) {}
void T_1 F_11 ( short V_32 , struct V_52 * V_2 )
{
unsigned int V_53 ;
unsigned int V_54 = 0 ;
if ( ! V_2 )
return;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
if ( V_2 -> V_56 [ V_53 ] . V_57 ) {
if ( V_2 -> V_56 [ V_53 ] . V_58 ) {
F_4 ( V_2 -> V_56 [ V_53 ] . V_58 , 1 ) ;
F_5 ( V_2 -> V_56 [ V_53 ] . V_58 , 1 ) ;
}
if ( V_2 -> V_56 [ V_53 ] . V_35 )
F_4 ( V_2 -> V_56 [ V_53 ] . V_35 , 1 ) ;
switch ( V_53 ) {
case 0 :
F_7 ( V_45 , 1 ) ;
F_7 ( V_46 , 1 ) ;
if ( V_2 -> V_56 [ V_53 ] . V_57 == 4 ) {
F_7 ( V_47 , 1 ) ;
F_7 ( V_48 , 1 ) ;
F_7 ( V_49 , 1 ) ;
}
V_54 ++ ;
break;
case 1 :
F_8 ( V_39 , 1 ) ;
F_8 ( V_40 , 1 ) ;
if ( V_2 -> V_56 [ V_53 ] . V_57 == 4 ) {
F_8 ( V_42 , 1 ) ;
F_8 ( V_43 , 1 ) ;
F_8 ( V_44 , 1 ) ;
}
V_54 ++ ;
break;
default:
F_12 ( V_59
L_1 , V_53 ) ;
break;
}
}
}
if ( V_54 ) {
F_7 ( V_37 , 0 ) ;
V_50 = * V_2 ;
F_2 ( & V_51 ) ;
}
}
void T_1 F_11 ( short V_32 , struct V_52 * V_2 ) {}
void T_1 F_13 ( struct V_60 * V_2 )
{
unsigned long V_61 ;
if ( ! V_2 )
return;
V_61 = F_14 ( V_62 ) ;
F_15 ( V_62 , V_61 | V_63 ) ;
if ( V_2 -> V_64 )
F_10 ( V_2 -> V_64 , 1 ) ;
if ( V_2 -> V_65 )
F_4 ( V_2 -> V_65 , 1 ) ;
if ( V_2 -> V_34 )
F_4 ( V_2 -> V_34 , 1 ) ;
V_66 = * V_2 ;
F_2 ( & V_67 ) ;
}
void T_1 F_13 ( struct V_60 * V_2 ) {}
void T_1 F_16 ( struct V_68 * V_69 , int V_70 )
{
F_17 ( V_27 , 1 ) ;
F_18 ( V_27 , 1 ) ;
F_17 ( V_28 , 1 ) ;
F_18 ( V_28 , 1 ) ;
F_19 ( 0 , V_69 , V_70 ) ;
F_2 ( & V_71 ) ;
}
void T_1 F_16 ( struct V_68 * V_69 , int V_70 )
{
F_7 ( V_27 , 0 ) ;
F_18 ( V_27 , 1 ) ;
F_7 ( V_28 , 0 ) ;
F_18 ( V_28 , 1 ) ;
F_19 ( 0 , V_69 , V_70 ) ;
F_2 ( & V_71 ) ;
}
void T_1 F_16 ( struct V_68 * V_69 , int V_70 ) {}
void T_1 F_20 ( struct V_72 * V_69 , int V_70 )
{
int V_53 ;
unsigned long V_73 ;
short V_74 = 0 ;
short V_75 = 0 ;
for ( V_53 = 0 ; V_53 < V_70 ; V_53 ++ ) {
if ( V_69 [ V_53 ] . V_76 )
V_73 = ( unsigned long ) V_69 [ V_53 ] . V_76 ;
else if ( V_69 [ V_53 ] . V_77 == 0 )
V_73 = V_78 [ V_69 [ V_53 ] . V_79 ] ;
else
V_73 = V_80 [ V_69 [ V_53 ] . V_79 ] ;
if ( V_69 [ V_53 ] . V_77 == 0 )
V_74 = 1 ;
else
V_75 = 1 ;
F_10 ( V_73 , 1 ) ;
V_69 [ V_53 ] . V_76 = ( void * ) V_73 ;
}
F_21 ( V_69 , V_70 ) ;
if ( V_74 ) {
F_7 ( V_40 , 0 ) ;
F_7 ( V_39 , 0 ) ;
F_7 ( V_81 , 0 ) ;
F_2 ( & V_82 ) ;
}
if ( V_75 ) {
F_7 ( V_83 , 0 ) ;
F_7 ( V_84 , 0 ) ;
F_7 ( V_85 , 0 ) ;
F_2 ( & V_86 ) ;
}
}
void T_1 F_20 ( struct V_72 * V_69 , int V_70 ) {}
static void T_1 F_22 ( void )
{
F_2 ( & V_87 ) ;
F_2 ( & V_88 ) ;
}
static void T_1 F_22 ( void ) { }
static void T_1 F_23 ( void )
{
F_2 ( & V_89 ) ;
}
static void T_1 F_24 ( void )
{
F_2 ( & V_90 ) ;
}
static void T_1 F_24 ( void ) {}
static inline void F_25 ( unsigned V_91 )
{
if ( V_91 & V_92 )
F_7 ( V_93 , 1 ) ;
if ( V_91 & V_94 )
F_7 ( V_95 , 1 ) ;
if ( V_91 & V_96 )
F_7 ( V_97 , 1 ) ;
if ( V_91 & V_98 )
F_7 ( V_99 , 1 ) ;
if ( V_91 & V_100 )
F_7 ( V_101 , 1 ) ;
if ( V_91 & V_102 )
F_7 ( V_103 , 1 ) ;
}
void T_1 F_26 ( unsigned V_104 , unsigned V_91 )
{
struct V_105 * V_106 ;
switch ( V_104 ) {
case V_107 :
V_106 = & V_108 ;
F_25 ( V_91 ) ;
break;
default:
return;
}
F_2 ( V_106 ) ;
}
void T_1 F_26 ( unsigned V_104 , unsigned V_91 ) {}
static inline void F_27 ( void )
{
F_7 ( V_109 , 0 ) ;
F_7 ( V_110 , 1 ) ;
}
static inline void F_28 ( unsigned V_91 )
{
F_7 ( V_111 , 1 ) ;
F_7 ( V_112 , 0 ) ;
if ( V_91 & V_113 )
F_7 ( V_114 , 0 ) ;
if ( V_91 & V_115 )
F_7 ( V_116 , 0 ) ;
if ( V_91 & V_117 )
F_7 ( V_118 , 0 ) ;
if ( V_91 & V_119 )
F_7 ( V_120 , 0 ) ;
if ( V_91 & V_121 )
F_7 ( V_122 , 0 ) ;
if ( V_91 & V_123 )
F_7 ( V_124 , 0 ) ;
}
static inline void F_29 ( unsigned V_91 )
{
F_7 ( V_125 , 1 ) ;
F_7 ( V_126 , 0 ) ;
if ( V_91 & V_113 )
F_7 ( V_127 , 0 ) ;
if ( V_91 & V_115 )
F_7 ( V_128 , 0 ) ;
}
static inline void F_30 ( unsigned V_91 )
{
F_7 ( V_129 , 1 ) ;
F_7 ( V_130 , 0 ) ;
if ( V_91 & V_113 )
F_7 ( V_43 , 0 ) ;
if ( V_91 & V_115 )
F_7 ( V_42 , 0 ) ;
}
static inline void F_31 ( unsigned V_91 )
{
F_7 ( V_131 , 1 ) ;
F_7 ( V_132 , 0 ) ;
if ( V_91 & V_113 )
F_8 ( V_133 , 0 ) ;
if ( V_91 & V_115 )
F_8 ( V_134 , 0 ) ;
}
static inline void F_32 ( void )
{
F_8 ( V_135 , 1 ) ;
F_8 ( V_136 , 0 ) ;
}
static inline void F_33 ( void )
{
F_7 ( V_137 , 1 ) ;
F_7 ( V_138 , 0 ) ;
}
void T_1 F_34 ( unsigned V_104 , unsigned V_139 , unsigned V_91 )
{
struct V_105 * V_106 ;
struct V_140 * V_141 ;
switch ( V_104 ) {
case 0 :
V_106 = & V_142 ;
F_27 () ;
break;
case V_143 :
V_106 = & V_144 ;
F_28 ( V_91 ) ;
break;
case V_145 :
V_106 = & V_146 ;
F_29 ( V_91 ) ;
break;
case V_147 :
V_106 = & V_148 ;
F_30 ( V_91 ) ;
break;
case V_149 :
V_106 = & V_150 ;
F_31 ( V_91 ) ;
break;
case V_151 :
V_106 = & V_152 ;
F_32 () ;
break;
case V_153 :
V_106 = & V_154 ;
F_33 () ;
break;
default:
return;
}
V_141 = V_106 -> V_155 . V_156 ;
V_141 -> V_157 = V_139 ;
if ( V_139 < V_158 )
V_159 [ V_139 ] = V_106 ;
}
void T_1 F_35 ( unsigned V_139 )
{
if ( V_139 < V_158 ) {
V_160 = V_159 [ V_139 ] ;
F_36 ( V_159 [ V_139 ] -> V_104 ) ;
}
}
void T_1 F_37 ( void )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_158 ; V_53 ++ ) {
if ( V_159 [ V_53 ] )
F_2 ( V_159 [ V_53 ] ) ;
}
if ( ! V_160 )
F_12 ( V_161 L_2 ) ;
}
void T_1 F_34 ( unsigned V_104 , unsigned V_139 , unsigned V_91 ) {}
void T_1 F_35 ( unsigned V_139 ) {}
void T_1 F_37 ( void ) {}
void T_1 F_38 ( struct V_162 * V_2 )
{
struct V_105 * V_106 ;
unsigned long V_61 ;
if ( ! V_2 )
return;
V_61 = F_14 ( V_62 ) ;
switch ( V_2 -> V_163 ) {
case 4 :
F_18 ( V_133 , 0 ) ;
F_7 ( V_133 , 0 ) ;
V_61 |= V_164 ;
V_165 = * V_2 ;
V_106 = & V_166 ;
break;
case 5 :
F_18 ( V_167 , 0 ) ;
F_7 ( V_167 , 0 ) ;
V_61 |= V_168 ;
V_169 = * V_2 ;
V_106 = & V_170 ;
break;
default:
F_12 ( V_59 L_3 ,
V_2 -> V_163 ) ;
return;
}
F_15 ( V_62 , V_61 ) ;
if ( V_2 -> V_171 ) {
F_18 ( V_2 -> V_171 , 0 ) ;
F_10 ( V_2 -> V_171 , 1 ) ;
}
if ( V_2 -> V_172 ) {
F_4 ( V_2 -> V_172 , 0 ) ;
F_5 ( V_2 -> V_172 , 1 ) ;
}
if ( V_2 -> V_34 ) {
F_4 ( V_2 -> V_34 , 0 ) ;
F_5 ( V_2 -> V_34 , 1 ) ;
}
F_8 ( V_173 , 0 ) ;
F_8 ( V_174 , 0 ) ;
F_7 ( V_134 , 0 ) ;
F_7 ( V_175 , 1 ) ;
if ( V_2 -> V_176 & V_177 )
#if F_39 ( V_178 ) || F_39 ( V_179 )
V_106 -> V_180 = L_4 ;
#elif F_39 ( V_181 ) || F_39 ( V_182 )
V_106 -> V_180 = L_5 ;
#else
#warning "board requires AT91_CF_TRUE_IDE: enable either at91_ide or pata_at91"
#endif
else
V_106 -> V_180 = L_6 ;
F_2 ( V_106 ) ;
}
void T_1 F_38 ( struct V_162 * V_2 ) {}
static int T_1 F_40 ( void )
{
F_23 () ;
F_24 () ;
F_22 () ;
return 0 ;
}
