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
if ( ! F_5 ( V_75 ) )
continue;
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
#if F_24 ( V_89 )
struct V_90 * V_91 ;
V_91 = F_25 ( NULL , V_92 ) ;
if ( V_91 ) {
F_26 ( V_91 ) ;
return;
}
#endif
F_3 ( & V_93 ) ;
F_3 ( & V_94 ) ;
}
static void T_1 F_23 ( void ) { }
static void T_1 F_27 ( void )
{
V_95 . V_96 = L_2 ;
V_95 . V_97 = 2 ;
V_98 [ 1 ] . V_99 = V_100 +
4 * V_101 ;
V_98 [ 1 ] . V_102 = V_98 [ 1 ] . V_99 + 3 ;
}
static void T_1 F_27 ( void )
{
V_95 . V_97 = 1 ;
}
static void T_1 F_28 ( void )
{
F_27 () ;
F_3 ( & V_95 ) ;
}
static void T_1 F_29 ( void )
{
F_3 ( & V_103 ) ;
}
static void T_1 F_29 ( void ) {}
static inline void F_30 ( unsigned V_104 )
{
if ( V_104 & V_105 )
F_8 ( V_106 , 1 ) ;
if ( V_104 & V_107 )
F_8 ( V_108 , 1 ) ;
if ( V_104 & V_109 )
F_8 ( V_110 , 1 ) ;
if ( V_104 & V_111 )
F_8 ( V_112 , 1 ) ;
if ( V_104 & V_113 )
F_8 ( V_114 , 1 ) ;
if ( V_104 & V_115 )
F_8 ( V_116 , 1 ) ;
}
void T_1 F_31 ( unsigned V_117 , unsigned V_104 )
{
struct V_118 * V_119 ;
switch ( V_117 ) {
case V_120 :
V_119 = & V_121 ;
F_30 ( V_104 ) ;
break;
default:
return;
}
F_3 ( V_119 ) ;
}
void T_1 F_31 ( unsigned V_117 , unsigned V_104 ) {}
static inline void F_32 ( void )
{
F_8 ( V_122 , 0 ) ;
F_8 ( V_123 , 1 ) ;
}
static inline void F_33 ( unsigned V_104 )
{
F_8 ( V_124 , 1 ) ;
F_8 ( V_125 , 0 ) ;
if ( V_104 & V_126 )
F_8 ( V_127 , 0 ) ;
if ( V_104 & V_128 )
F_8 ( V_129 , 0 ) ;
if ( V_104 & V_130 )
F_8 ( V_131 , 0 ) ;
if ( V_104 & V_132 )
F_8 ( V_133 , 0 ) ;
if ( V_104 & V_134 )
F_8 ( V_135 , 0 ) ;
if ( V_104 & V_136 )
F_8 ( V_137 , 0 ) ;
}
static inline void F_34 ( unsigned V_104 )
{
F_8 ( V_138 , 1 ) ;
F_8 ( V_139 , 0 ) ;
if ( V_104 & V_126 )
F_8 ( V_140 , 0 ) ;
if ( V_104 & V_128 )
F_8 ( V_141 , 0 ) ;
}
static inline void F_35 ( unsigned V_104 )
{
F_8 ( V_142 , 1 ) ;
F_8 ( V_143 , 0 ) ;
if ( V_104 & V_126 )
F_8 ( V_46 , 0 ) ;
if ( V_104 & V_128 )
F_8 ( V_45 , 0 ) ;
}
static inline void F_36 ( unsigned V_104 )
{
F_8 ( V_144 , 1 ) ;
F_8 ( V_145 , 0 ) ;
if ( V_104 & V_126 )
F_9 ( V_146 , 0 ) ;
if ( V_104 & V_128 )
F_9 ( V_147 , 0 ) ;
}
static inline void F_37 ( void )
{
F_9 ( V_148 , 1 ) ;
F_9 ( V_149 , 0 ) ;
}
static inline void F_38 ( void )
{
F_8 ( V_150 , 1 ) ;
F_8 ( V_151 , 0 ) ;
}
void T_1 F_39 ( unsigned V_117 , unsigned V_152 , unsigned V_104 )
{
struct V_118 * V_119 ;
struct V_153 * V_154 ;
switch ( V_117 ) {
case 0 :
V_119 = & V_155 ;
F_32 () ;
break;
case V_156 :
V_119 = & V_157 ;
F_33 ( V_104 ) ;
break;
case V_158 :
V_119 = & V_159 ;
F_34 ( V_104 ) ;
break;
case V_160 :
V_119 = & V_161 ;
F_35 ( V_104 ) ;
break;
case V_162 :
V_119 = & V_163 ;
F_36 ( V_104 ) ;
break;
case V_164 :
V_119 = & V_165 ;
F_37 () ;
break;
case V_166 :
V_119 = & V_167 ;
F_38 () ;
break;
default:
return;
}
V_154 = V_119 -> V_168 . V_169 ;
V_154 -> V_170 = V_152 ;
if ( V_152 < V_171 )
V_172 [ V_152 ] = V_119 ;
}
void T_1 F_40 ( unsigned V_152 )
{
if ( V_152 < V_171 ) {
V_173 = V_172 [ V_152 ] ;
F_41 ( V_172 [ V_152 ] -> V_117 ) ;
}
}
void T_1 F_42 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_171 ; V_3 ++ ) {
if ( V_172 [ V_3 ] )
F_3 ( V_172 [ V_3 ] ) ;
}
if ( ! V_173 )
F_13 ( V_174 L_3 ) ;
}
void T_1 F_39 ( unsigned V_117 , unsigned V_152 , unsigned V_104 ) {}
void T_1 F_40 ( unsigned V_152 ) {}
void T_1 F_42 ( void ) {}
void T_1 F_43 ( struct V_175 * V_2 )
{
struct V_118 * V_119 ;
unsigned long V_63 ;
if ( ! V_2 )
return;
V_63 = F_15 ( V_64 ) ;
switch ( V_2 -> V_176 ) {
case 4 :
F_19 ( V_146 , 0 ) ;
F_8 ( V_146 , 0 ) ;
V_63 |= V_177 ;
V_178 = * V_2 ;
V_119 = & V_179 ;
break;
case 5 :
F_19 ( V_180 , 0 ) ;
F_8 ( V_180 , 0 ) ;
V_63 |= V_181 ;
V_182 = * V_2 ;
V_119 = & V_183 ;
break;
default:
F_13 ( V_61 L_4 ,
V_2 -> V_176 ) ;
return;
}
F_16 ( V_64 , V_63 ) ;
if ( F_5 ( V_2 -> V_184 ) ) {
F_19 ( V_2 -> V_184 , 0 ) ;
F_11 ( V_2 -> V_184 , 1 ) ;
}
if ( F_5 ( V_2 -> V_185 ) ) {
F_2 ( V_2 -> V_185 , 0 ) ;
F_6 ( V_2 -> V_185 , 1 ) ;
}
if ( F_5 ( V_2 -> V_37 ) ) {
F_2 ( V_2 -> V_37 , 0 ) ;
F_6 ( V_2 -> V_37 , 1 ) ;
}
F_9 ( V_186 , 0 ) ;
F_9 ( V_187 , 0 ) ;
F_8 ( V_147 , 0 ) ;
F_8 ( V_188 , 1 ) ;
if ( V_2 -> V_189 & V_190 )
#if F_24 ( V_191 ) || F_24 ( V_192 )
V_119 -> V_96 = L_5 ;
#else
#warning "board requires AT91_CF_TRUE_IDE: enable pata_at91"
#endif
else
V_119 -> V_96 = L_6 ;
F_3 ( V_119 ) ;
}
void T_1 F_43 ( struct V_175 * V_2 ) {}
static int T_1 F_44 ( void )
{
F_28 () ;
F_29 () ;
F_23 () ;
return 0 ;
}
