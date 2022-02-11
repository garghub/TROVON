void T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! V_2 )
return;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
if ( V_2 -> V_5 [ V_3 ] )
F_2 ( V_2 -> V_5 [ V_3 ] , 1 ) ;
}
V_6 = * V_2 ;
F_3 ( & V_7 ) ;
}
void T_1 F_1 ( struct V_1 * V_2 ) {}
void T_1 F_4 ( struct V_8 * V_2 )
{
if ( ! V_2 )
return;
if ( F_5 ( V_2 -> V_9 ) ) {
F_2 ( V_2 -> V_9 , 0 ) ;
F_6 ( V_2 -> V_9 , 1 ) ;
}
V_10 = * V_2 ;
F_3 ( & V_11 ) ;
}
void T_1 F_4 ( struct V_8 * V_2 ) {}
void T_1 F_7 ( struct V_12 * V_2 )
{
if ( ! V_2 )
return;
if ( F_5 ( V_2 -> V_13 ) ) {
F_2 ( V_2 -> V_13 , 0 ) ;
F_6 ( V_2 -> V_13 , 1 ) ;
}
F_8 ( V_14 , 0 ) ;
F_8 ( V_15 , 0 ) ;
F_8 ( V_16 , 0 ) ;
F_8 ( V_17 , 0 ) ;
F_8 ( V_18 , 0 ) ;
F_8 ( V_19 , 0 ) ;
F_8 ( V_20 , 0 ) ;
F_8 ( V_21 , 0 ) ;
F_8 ( V_22 , 0 ) ;
F_8 ( V_23 , 0 ) ;
if ( ! V_2 -> V_24 ) {
F_9 ( V_25 , 0 ) ;
F_9 ( V_26 , 0 ) ;
F_9 ( V_27 , 0 ) ;
F_9 ( V_28 , 0 ) ;
F_9 ( V_29 , 0 ) ;
F_9 ( V_30 , 0 ) ;
F_9 ( V_31 , 0 ) ;
F_9 ( V_32 , 0 ) ;
}
V_33 = * V_2 ;
F_3 ( & V_34 ) ;
}
void T_1 F_7 ( struct V_12 * V_2 ) {}
void T_1 F_10 ( short V_35 , struct V_36 * V_2 )
{
if ( ! V_2 )
return;
if ( F_5 ( V_2 -> V_37 ) ) {
F_2 ( V_2 -> V_37 , 1 ) ;
F_6 ( V_2 -> V_37 , 1 ) ;
}
if ( F_5 ( V_2 -> V_38 ) )
F_2 ( V_2 -> V_38 , 1 ) ;
if ( F_5 ( V_2 -> V_39 ) )
F_11 ( V_2 -> V_39 , 0 ) ;
F_8 ( V_40 , 0 ) ;
if ( V_2 -> V_41 ) {
F_9 ( V_42 , 1 ) ;
F_9 ( V_43 , 1 ) ;
if ( V_2 -> V_44 ) {
F_9 ( V_45 , 1 ) ;
F_9 ( V_46 , 1 ) ;
F_9 ( V_47 , 1 ) ;
}
} else {
F_8 ( V_48 , 1 ) ;
F_8 ( V_49 , 1 ) ;
if ( V_2 -> V_44 ) {
F_8 ( V_50 , 1 ) ;
F_8 ( V_51 , 1 ) ;
F_8 ( V_52 , 1 ) ;
}
}
V_53 = * V_2 ;
F_3 ( & V_54 ) ;
}
void T_1 F_10 ( short V_35 , struct V_36 * V_2 ) {}
void T_1 F_12 ( short V_35 , struct V_55 * V_2 )
{
unsigned int V_3 ;
unsigned int V_56 = 0 ;
if ( ! V_2 )
return;
for ( V_3 = 0 ; V_3 < V_57 ; V_3 ++ ) {
if ( V_2 -> V_58 [ V_3 ] . V_59 ) {
if ( F_5 ( V_2 -> V_58 [ V_3 ] . V_60 ) ) {
F_2 ( V_2 -> V_58 [ V_3 ] . V_60 , 1 ) ;
F_6 ( V_2 -> V_58 [ V_3 ] . V_60 , 1 ) ;
}
if ( F_5 ( V_2 -> V_58 [ V_3 ] . V_38 ) )
F_2 ( V_2 -> V_58 [ V_3 ] . V_38 , 1 ) ;
switch ( V_3 ) {
case 0 :
F_8 ( V_48 , 1 ) ;
F_8 ( V_49 , 1 ) ;
if ( V_2 -> V_58 [ V_3 ] . V_59 == 4 ) {
F_8 ( V_50 , 1 ) ;
F_8 ( V_51 , 1 ) ;
F_8 ( V_52 , 1 ) ;
}
V_56 ++ ;
break;
case 1 :
F_9 ( V_42 , 1 ) ;
F_9 ( V_43 , 1 ) ;
if ( V_2 -> V_58 [ V_3 ] . V_59 == 4 ) {
F_9 ( V_45 , 1 ) ;
F_9 ( V_46 , 1 ) ;
F_9 ( V_47 , 1 ) ;
}
V_56 ++ ;
break;
default:
F_13 ( V_61
L_1 , V_3 ) ;
break;
}
}
}
if ( V_56 ) {
F_8 ( V_40 , 0 ) ;
V_53 = * V_2 ;
F_3 ( & V_54 ) ;
}
}
void T_1 F_12 ( short V_35 , struct V_55 * V_2 ) {}
void T_1 F_14 ( struct V_62 * V_2 )
{
unsigned long V_63 ;
if ( ! V_2 )
return;
V_63 = F_15 ( V_64 ) ;
F_16 ( V_64 , V_63 | V_65 ) ;
if ( F_5 ( V_2 -> V_66 ) )
F_11 ( V_2 -> V_66 , 1 ) ;
if ( F_5 ( V_2 -> V_67 ) )
F_2 ( V_2 -> V_67 , 1 ) ;
if ( F_5 ( V_2 -> V_37 ) )
F_2 ( V_2 -> V_37 , 1 ) ;
V_68 = * V_2 ;
F_3 ( & V_69 ) ;
}
void T_1 F_14 ( struct V_62 * V_2 ) {}
void T_1 F_17 ( struct V_70 * V_71 , int V_72 )
{
F_18 ( V_30 , 1 ) ;
F_19 ( V_30 , 1 ) ;
F_18 ( V_31 , 1 ) ;
F_19 ( V_31 , 1 ) ;
F_20 ( 0 , V_71 , V_72 ) ;
F_3 ( & V_73 ) ;
}
void T_1 F_17 ( struct V_70 * V_71 , int V_72 )
{
F_8 ( V_30 , 0 ) ;
F_19 ( V_30 , 1 ) ;
F_8 ( V_31 , 0 ) ;
F_19 ( V_31 , 1 ) ;
F_20 ( 0 , V_71 , V_72 ) ;
F_3 ( & V_73 ) ;
}
void T_1 F_17 ( struct V_70 * V_71 , int V_72 ) {}
void T_1 F_21 ( struct V_74 * V_71 , int V_72 )
{
int V_3 ;
unsigned long V_75 ;
short V_76 = 0 ;
short V_77 = 0 ;
for ( V_3 = 0 ; V_3 < V_72 ; V_3 ++ ) {
if ( V_71 [ V_3 ] . V_78 )
V_75 = ( unsigned long ) V_71 [ V_3 ] . V_78 ;
else if ( V_71 [ V_3 ] . V_79 == 0 )
V_75 = V_80 [ V_71 [ V_3 ] . V_81 ] ;
else
V_75 = V_82 [ V_71 [ V_3 ] . V_81 ] ;
if ( V_71 [ V_3 ] . V_79 == 0 )
V_76 = 1 ;
else
V_77 = 1 ;
F_11 ( V_75 , 1 ) ;
V_71 [ V_3 ] . V_78 = ( void * ) V_75 ;
}
F_22 ( V_71 , V_72 ) ;
if ( V_76 ) {
F_8 ( V_43 , 0 ) ;
F_8 ( V_42 , 0 ) ;
F_8 ( V_83 , 0 ) ;
F_3 ( & V_84 ) ;
}
if ( V_77 ) {
F_8 ( V_85 , 0 ) ;
F_8 ( V_86 , 0 ) ;
F_8 ( V_87 , 0 ) ;
F_3 ( & V_88 ) ;
}
}
void T_1 F_21 ( struct V_74 * V_71 , int V_72 ) {}
static void T_1 F_23 ( void )
{
F_3 ( & V_89 ) ;
F_3 ( & V_90 ) ;
}
static void T_1 F_23 ( void ) { }
static void T_1 F_24 ( void )
{
F_3 ( & V_91 ) ;
}
static void T_1 F_25 ( void )
{
F_3 ( & V_92 ) ;
}
static void T_1 F_25 ( void ) {}
static inline void F_26 ( unsigned V_93 )
{
if ( V_93 & V_94 )
F_8 ( V_95 , 1 ) ;
if ( V_93 & V_96 )
F_8 ( V_97 , 1 ) ;
if ( V_93 & V_98 )
F_8 ( V_99 , 1 ) ;
if ( V_93 & V_100 )
F_8 ( V_101 , 1 ) ;
if ( V_93 & V_102 )
F_8 ( V_103 , 1 ) ;
if ( V_93 & V_104 )
F_8 ( V_105 , 1 ) ;
}
void T_1 F_27 ( unsigned V_106 , unsigned V_93 )
{
struct V_107 * V_108 ;
switch ( V_106 ) {
case V_109 :
V_108 = & V_110 ;
F_26 ( V_93 ) ;
break;
default:
return;
}
F_3 ( V_108 ) ;
}
void T_1 F_27 ( unsigned V_106 , unsigned V_93 ) {}
static inline void F_28 ( void )
{
F_8 ( V_111 , 0 ) ;
F_8 ( V_112 , 1 ) ;
}
static inline void F_29 ( unsigned V_93 )
{
F_8 ( V_113 , 1 ) ;
F_8 ( V_114 , 0 ) ;
if ( V_93 & V_115 )
F_8 ( V_116 , 0 ) ;
if ( V_93 & V_117 )
F_8 ( V_118 , 0 ) ;
if ( V_93 & V_119 )
F_8 ( V_120 , 0 ) ;
if ( V_93 & V_121 )
F_8 ( V_122 , 0 ) ;
if ( V_93 & V_123 )
F_8 ( V_124 , 0 ) ;
if ( V_93 & V_125 )
F_8 ( V_126 , 0 ) ;
}
static inline void F_30 ( unsigned V_93 )
{
F_8 ( V_127 , 1 ) ;
F_8 ( V_128 , 0 ) ;
if ( V_93 & V_115 )
F_8 ( V_129 , 0 ) ;
if ( V_93 & V_117 )
F_8 ( V_130 , 0 ) ;
}
static inline void F_31 ( unsigned V_93 )
{
F_8 ( V_131 , 1 ) ;
F_8 ( V_132 , 0 ) ;
if ( V_93 & V_115 )
F_8 ( V_46 , 0 ) ;
if ( V_93 & V_117 )
F_8 ( V_45 , 0 ) ;
}
static inline void F_32 ( unsigned V_93 )
{
F_8 ( V_133 , 1 ) ;
F_8 ( V_134 , 0 ) ;
if ( V_93 & V_115 )
F_9 ( V_135 , 0 ) ;
if ( V_93 & V_117 )
F_9 ( V_136 , 0 ) ;
}
static inline void F_33 ( void )
{
F_9 ( V_137 , 1 ) ;
F_9 ( V_138 , 0 ) ;
}
static inline void F_34 ( void )
{
F_8 ( V_139 , 1 ) ;
F_8 ( V_140 , 0 ) ;
}
void T_1 F_35 ( unsigned V_106 , unsigned V_141 , unsigned V_93 )
{
struct V_107 * V_108 ;
struct V_142 * V_143 ;
switch ( V_106 ) {
case 0 :
V_108 = & V_144 ;
F_28 () ;
break;
case V_145 :
V_108 = & V_146 ;
F_29 ( V_93 ) ;
break;
case V_147 :
V_108 = & V_148 ;
F_30 ( V_93 ) ;
break;
case V_149 :
V_108 = & V_150 ;
F_31 ( V_93 ) ;
break;
case V_151 :
V_108 = & V_152 ;
F_32 ( V_93 ) ;
break;
case V_153 :
V_108 = & V_154 ;
F_33 () ;
break;
case V_155 :
V_108 = & V_156 ;
F_34 () ;
break;
default:
return;
}
V_143 = V_108 -> V_157 . V_158 ;
V_143 -> V_159 = V_141 ;
if ( V_141 < V_160 )
V_161 [ V_141 ] = V_108 ;
}
void T_1 F_36 ( unsigned V_141 )
{
if ( V_141 < V_160 ) {
V_162 = V_161 [ V_141 ] ;
F_37 ( V_161 [ V_141 ] -> V_106 ) ;
}
}
void T_1 F_38 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_160 ; V_3 ++ ) {
if ( V_161 [ V_3 ] )
F_3 ( V_161 [ V_3 ] ) ;
}
if ( ! V_162 )
F_13 ( V_163 L_2 ) ;
}
void T_1 F_35 ( unsigned V_106 , unsigned V_141 , unsigned V_93 ) {}
void T_1 F_36 ( unsigned V_141 ) {}
void T_1 F_38 ( void ) {}
void T_1 F_39 ( struct V_164 * V_2 )
{
struct V_107 * V_108 ;
unsigned long V_63 ;
if ( ! V_2 )
return;
V_63 = F_15 ( V_64 ) ;
switch ( V_2 -> V_165 ) {
case 4 :
F_19 ( V_135 , 0 ) ;
F_8 ( V_135 , 0 ) ;
V_63 |= V_166 ;
V_167 = * V_2 ;
V_108 = & V_168 ;
break;
case 5 :
F_19 ( V_169 , 0 ) ;
F_8 ( V_169 , 0 ) ;
V_63 |= V_170 ;
V_171 = * V_2 ;
V_108 = & V_172 ;
break;
default:
F_13 ( V_61 L_3 ,
V_2 -> V_165 ) ;
return;
}
F_16 ( V_64 , V_63 ) ;
if ( F_5 ( V_2 -> V_173 ) ) {
F_19 ( V_2 -> V_173 , 0 ) ;
F_11 ( V_2 -> V_173 , 1 ) ;
}
if ( F_5 ( V_2 -> V_174 ) ) {
F_2 ( V_2 -> V_174 , 0 ) ;
F_6 ( V_2 -> V_174 , 1 ) ;
}
if ( F_5 ( V_2 -> V_37 ) ) {
F_2 ( V_2 -> V_37 , 0 ) ;
F_6 ( V_2 -> V_37 , 1 ) ;
}
F_9 ( V_175 , 0 ) ;
F_9 ( V_176 , 0 ) ;
F_8 ( V_136 , 0 ) ;
F_8 ( V_177 , 1 ) ;
if ( V_2 -> V_178 & V_179 )
#if F_40 ( V_180 ) || F_40 ( V_181 )
V_108 -> V_182 = L_4 ;
#else
#warning "board requires AT91_CF_TRUE_IDE: enable pata_at91"
#endif
else
V_108 -> V_182 = L_5 ;
F_3 ( V_108 ) ;
}
void T_1 F_39 ( struct V_164 * V_2 ) {}
static int T_1 F_41 ( void )
{
F_24 () ;
F_25 () ;
F_23 () ;
return 0 ;
}
