void T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! V_2 )
return;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
if ( F_2 ( V_2 -> V_5 [ V_3 ] ) )
F_3 ( V_2 -> V_5 [ V_3 ] , 1 ) ;
}
V_6 = * V_2 ;
F_4 ( & V_7 ) ;
}
void T_1 F_1 ( struct V_1 * V_2 ) {}
void T_1 F_5 ( struct V_8 * V_2 )
{
if ( ! V_2 )
return;
if ( F_2 ( V_2 -> V_9 ) ) {
F_3 ( V_2 -> V_9 , 0 ) ;
F_6 ( V_2 -> V_9 , 1 ) ;
}
V_10 = * V_2 ;
F_4 ( & V_11 ) ;
}
void T_1 F_5 ( struct V_8 * V_2 ) {}
void T_1 F_7 ( struct V_12 * V_2 )
{
if ( ! V_2 )
return;
if ( F_2 ( V_2 -> V_13 ) ) {
F_3 ( V_2 -> V_13 , 0 ) ;
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
F_4 ( & V_34 ) ;
}
void T_1 F_7 ( struct V_12 * V_2 ) {}
void T_1 F_10 ( short V_35 , struct V_36 * V_2 )
{
unsigned int V_3 ;
unsigned int V_37 = 0 ;
if ( ! V_2 )
return;
for ( V_3 = 0 ; V_3 < V_38 ; V_3 ++ ) {
if ( V_2 -> V_39 [ V_3 ] . V_40 ) {
if ( F_2 ( V_2 -> V_39 [ V_3 ] . V_41 ) ) {
F_3 ( V_2 -> V_39 [ V_3 ] . V_41 , 1 ) ;
F_6 ( V_2 -> V_39 [ V_3 ] . V_41 , 1 ) ;
}
if ( F_2 ( V_2 -> V_39 [ V_3 ] . V_42 ) )
F_3 ( V_2 -> V_39 [ V_3 ] . V_42 , 1 ) ;
switch ( V_3 ) {
case 0 :
F_8 ( V_43 , 1 ) ;
F_8 ( V_44 , 1 ) ;
if ( V_2 -> V_39 [ V_3 ] . V_40 == 4 ) {
F_8 ( V_45 , 1 ) ;
F_8 ( V_46 , 1 ) ;
F_8 ( V_47 , 1 ) ;
}
V_37 ++ ;
break;
case 1 :
F_9 ( V_48 , 1 ) ;
F_9 ( V_49 , 1 ) ;
if ( V_2 -> V_39 [ V_3 ] . V_40 == 4 ) {
F_9 ( V_50 , 1 ) ;
F_9 ( V_51 , 1 ) ;
F_9 ( V_52 , 1 ) ;
}
V_37 ++ ;
break;
default:
F_11 ( V_53
L_1 , V_3 ) ;
break;
}
}
}
if ( V_37 ) {
F_8 ( V_54 , 0 ) ;
V_55 = * V_2 ;
F_4 ( & V_56 ) ;
}
}
void T_1 F_10 ( short V_35 , struct V_36 * V_2 ) {}
void T_1 F_12 ( struct V_57 * V_2 )
{
unsigned long V_58 ;
if ( ! V_2 )
return;
V_58 = F_13 ( V_59 ) ;
F_14 ( V_59 , V_58 | V_60 ) ;
if ( F_2 ( V_2 -> V_61 ) )
F_15 ( V_2 -> V_61 , 1 ) ;
if ( F_2 ( V_2 -> V_62 ) )
F_3 ( V_2 -> V_62 , 1 ) ;
if ( F_2 ( V_2 -> V_63 ) )
F_3 ( V_2 -> V_63 , 1 ) ;
V_64 = * V_2 ;
F_4 ( & V_65 ) ;
}
void T_1 F_12 ( struct V_57 * V_2 ) {}
void T_1 F_16 ( struct V_66 * V_67 , int V_68 )
{
F_17 ( V_30 , 1 ) ;
F_18 ( V_30 , 1 ) ;
F_17 ( V_31 , 1 ) ;
F_18 ( V_31 , 1 ) ;
F_19 ( 0 , V_67 , V_68 ) ;
F_4 ( & V_69 ) ;
}
void T_1 F_16 ( struct V_66 * V_67 , int V_68 )
{
if ( F_20 () ) {
V_69 . V_70 = L_2 ;
} else {
V_69 . V_70 = L_3 ;
}
F_8 ( V_30 , 0 ) ;
F_18 ( V_30 , 1 ) ;
F_8 ( V_31 , 0 ) ;
F_18 ( V_31 , 1 ) ;
F_19 ( 0 , V_67 , V_68 ) ;
F_4 ( & V_69 ) ;
}
void T_1 F_16 ( struct V_66 * V_67 , int V_68 ) {}
void T_1 F_21 ( struct V_71 * V_67 , int V_68 )
{
int V_3 ;
unsigned long V_72 ;
short V_73 = 0 ;
short V_74 = 0 ;
for ( V_3 = 0 ; V_3 < V_68 ; V_3 ++ ) {
if ( V_67 [ V_3 ] . V_75 )
V_72 = ( unsigned long ) V_67 [ V_3 ] . V_75 ;
else if ( V_67 [ V_3 ] . V_76 == 0 )
V_72 = V_77 [ V_67 [ V_3 ] . V_78 ] ;
else
V_72 = V_79 [ V_67 [ V_3 ] . V_78 ] ;
if ( ! F_2 ( V_72 ) )
continue;
if ( V_67 [ V_3 ] . V_76 == 0 )
V_73 = 1 ;
else
V_74 = 1 ;
F_15 ( V_72 , 1 ) ;
V_67 [ V_3 ] . V_75 = ( void * ) V_72 ;
}
F_22 ( V_67 , V_68 ) ;
if ( V_73 ) {
F_8 ( V_49 , 0 ) ;
F_8 ( V_48 , 0 ) ;
F_8 ( V_80 , 0 ) ;
F_4 ( & V_81 ) ;
}
if ( V_74 ) {
F_8 ( V_82 , 0 ) ;
F_8 ( V_83 , 0 ) ;
F_8 ( V_84 , 0 ) ;
F_4 ( & V_85 ) ;
}
}
void T_1 F_21 ( struct V_71 * V_67 , int V_68 ) {}
static void T_1 F_23 ( void )
{
F_4 ( & V_86 ) ;
F_4 ( & V_87 ) ;
}
static void T_1 F_23 ( void ) { }
static void T_1 F_24 ( void )
{
V_88 . V_70 = L_4 ;
V_88 . V_89 = 3 ;
V_90 [ 1 ] . V_91 = V_92 +
4 * V_93 ;
V_90 [ 1 ] . V_94 = V_90 [ 1 ] . V_91 + 3 ;
V_90 [ 2 ] . V_91 = V_95 + V_96 ;
V_90 [ 2 ] . V_94 = V_95 + V_96 ;
}
static void T_1 F_24 ( void )
{
V_88 . V_89 = 1 ;
}
static void T_1 F_25 ( void )
{
F_24 () ;
F_4 ( & V_88 ) ;
}
static void T_1 F_26 ( void )
{
F_4 ( & V_97 ) ;
}
static void T_1 F_26 ( void ) {}
static inline void F_27 ( unsigned V_98 )
{
if ( V_98 & V_99 )
F_8 ( V_100 , 1 ) ;
if ( V_98 & V_101 )
F_8 ( V_102 , 1 ) ;
if ( V_98 & V_103 )
F_8 ( V_104 , 1 ) ;
if ( V_98 & V_105 )
F_8 ( V_106 , 1 ) ;
if ( V_98 & V_107 )
F_8 ( V_108 , 1 ) ;
if ( V_98 & V_109 )
F_8 ( V_110 , 1 ) ;
}
void T_1 F_28 ( unsigned V_111 , unsigned V_98 )
{
struct V_112 * V_113 ;
switch ( V_111 ) {
case V_114 :
V_113 = & V_115 ;
F_27 ( V_98 ) ;
break;
default:
return;
}
F_4 ( V_113 ) ;
}
void T_1 F_28 ( unsigned V_111 , unsigned V_98 ) {}
static inline void F_29 ( void )
{
F_8 ( V_116 , 0 ) ;
F_8 ( V_117 , 1 ) ;
}
static inline void F_30 ( unsigned V_98 )
{
F_8 ( V_118 , 1 ) ;
F_8 ( V_119 , 0 ) ;
if ( V_98 & V_120 )
F_8 ( V_121 , 0 ) ;
if ( V_98 & V_122 )
F_8 ( V_123 , 0 ) ;
if ( V_98 & V_124 )
F_8 ( V_125 , 0 ) ;
if ( V_98 & V_126 )
F_8 ( V_127 , 0 ) ;
if ( V_98 & V_128 )
F_8 ( V_129 , 0 ) ;
if ( V_98 & V_130 )
F_8 ( V_131 , 0 ) ;
}
static inline void F_31 ( unsigned V_98 )
{
F_8 ( V_132 , 1 ) ;
F_8 ( V_133 , 0 ) ;
if ( V_98 & V_120 )
F_8 ( V_134 , 0 ) ;
if ( V_98 & V_122 )
F_8 ( V_135 , 0 ) ;
}
static inline void F_32 ( unsigned V_98 )
{
F_8 ( V_136 , 1 ) ;
F_8 ( V_137 , 0 ) ;
if ( V_98 & V_120 )
F_8 ( V_51 , 0 ) ;
if ( V_98 & V_122 )
F_8 ( V_50 , 0 ) ;
}
static inline void F_33 ( unsigned V_98 )
{
F_8 ( V_138 , 1 ) ;
F_8 ( V_139 , 0 ) ;
if ( V_98 & V_120 )
F_9 ( V_140 , 0 ) ;
if ( V_98 & V_122 )
F_9 ( V_141 , 0 ) ;
}
static inline void F_34 ( void )
{
F_9 ( V_142 , 1 ) ;
F_9 ( V_143 , 0 ) ;
}
static inline void F_35 ( void )
{
F_8 ( V_144 , 1 ) ;
F_8 ( V_145 , 0 ) ;
}
void T_1 F_36 ( unsigned V_111 , unsigned V_146 , unsigned V_98 )
{
struct V_112 * V_113 ;
struct V_147 * V_148 ;
switch ( V_111 ) {
case 0 :
V_113 = & V_149 ;
F_29 () ;
break;
case V_150 :
V_113 = & V_151 ;
F_30 ( V_98 ) ;
break;
case V_152 :
V_113 = & V_153 ;
F_31 ( V_98 ) ;
break;
case V_154 :
V_113 = & V_155 ;
F_32 ( V_98 ) ;
break;
case V_156 :
V_113 = & V_157 ;
F_33 ( V_98 ) ;
break;
case V_158 :
V_113 = & V_159 ;
F_34 () ;
break;
case V_160 :
V_113 = & V_161 ;
F_35 () ;
break;
default:
return;
}
V_148 = V_113 -> V_162 . V_163 ;
V_148 -> V_164 = V_146 ;
if ( V_146 < V_165 )
V_166 [ V_146 ] = V_113 ;
}
void T_1 F_37 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_165 ; V_3 ++ ) {
if ( V_166 [ V_3 ] )
F_4 ( V_166 [ V_3 ] ) ;
}
}
void T_1 F_36 ( unsigned V_111 , unsigned V_146 , unsigned V_98 ) {}
void T_1 F_37 ( void ) {}
void T_1 F_38 ( struct V_167 * V_2 )
{
struct V_112 * V_113 ;
unsigned long V_58 ;
if ( ! V_2 )
return;
V_58 = F_13 ( V_59 ) ;
switch ( V_2 -> V_168 ) {
case 4 :
F_18 ( V_140 , 0 ) ;
F_8 ( V_140 , 0 ) ;
V_58 |= V_169 ;
V_170 = * V_2 ;
V_113 = & V_171 ;
break;
case 5 :
F_18 ( V_172 , 0 ) ;
F_8 ( V_172 , 0 ) ;
V_58 |= V_173 ;
V_174 = * V_2 ;
V_113 = & V_175 ;
break;
default:
F_11 ( V_53 L_5 ,
V_2 -> V_168 ) ;
return;
}
F_14 ( V_59 , V_58 ) ;
if ( F_2 ( V_2 -> V_176 ) ) {
F_18 ( V_2 -> V_176 , 0 ) ;
F_15 ( V_2 -> V_176 , 1 ) ;
}
if ( F_2 ( V_2 -> V_177 ) ) {
F_3 ( V_2 -> V_177 , 0 ) ;
F_6 ( V_2 -> V_177 , 1 ) ;
}
if ( F_2 ( V_2 -> V_63 ) ) {
F_3 ( V_2 -> V_63 , 0 ) ;
F_6 ( V_2 -> V_63 , 1 ) ;
}
F_9 ( V_178 , 0 ) ;
F_9 ( V_179 , 0 ) ;
F_8 ( V_141 , 0 ) ;
F_8 ( V_180 , 1 ) ;
if ( V_2 -> V_181 & V_182 )
#if F_39 ( V_183 ) || F_39 ( V_184 )
V_113 -> V_70 = L_6 ;
#else
#warning "board requires AT91_CF_TRUE_IDE: enable pata_at91"
#endif
else
V_113 -> V_70 = L_7 ;
F_4 ( V_113 ) ;
}
void T_1 F_38 ( struct V_167 * V_2 ) {}
void T_1 F_40 ( struct V_185 * V_2 )
{
if ( ! V_2 )
return;
if ( F_41 ( 0 , & V_2 -> V_186 ) )
F_8 ( V_187 , 0 ) ;
if ( F_41 ( 1 , & V_2 -> V_186 ) )
F_8 ( V_188 , 0 ) ;
if ( F_41 ( 2 , & V_2 -> V_186 ) )
F_8 ( V_189 , 0 ) ;
if ( F_41 ( 3 , & V_2 -> V_186 ) )
F_8 ( V_190 , 0 ) ;
if ( V_2 -> V_191 )
F_8 ( V_32 , 0 ) ;
V_2 -> V_192 = 4 ;
V_2 -> V_193 = 10 ;
V_2 -> V_194 = & V_195 ;
V_2 -> V_196 = 4 ;
V_2 -> V_197 = V_198 ;
V_199 = * V_2 ;
F_4 ( & V_200 ) ;
}
void T_1 F_40 ( struct V_185 * V_2 ) {}
static int T_1 F_42 ( void )
{
if ( F_43 () )
return 0 ;
F_25 () ;
F_26 () ;
F_23 () ;
return 0 ;
}
