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
F_3 ( & V_89 ) ;
F_3 ( & V_90 ) ;
}
static void T_1 F_23 ( void ) { }
static void T_1 F_24 ( void )
{
V_91 . V_92 = L_2 ;
V_91 . V_93 = 2 ;
V_94 [ 1 ] . V_95 = V_96 +
4 * V_97 ;
V_94 [ 1 ] . V_98 = V_94 [ 1 ] . V_95 + 3 ;
}
static void T_1 F_24 ( void )
{
V_91 . V_93 = 1 ;
}
static void T_1 F_25 ( void )
{
F_24 () ;
F_3 ( & V_91 ) ;
}
static void T_1 F_26 ( void )
{
F_3 ( & V_99 ) ;
}
static void T_1 F_26 ( void ) {}
static inline void F_27 ( unsigned V_100 )
{
if ( V_100 & V_101 )
F_8 ( V_102 , 1 ) ;
if ( V_100 & V_103 )
F_8 ( V_104 , 1 ) ;
if ( V_100 & V_105 )
F_8 ( V_106 , 1 ) ;
if ( V_100 & V_107 )
F_8 ( V_108 , 1 ) ;
if ( V_100 & V_109 )
F_8 ( V_110 , 1 ) ;
if ( V_100 & V_111 )
F_8 ( V_112 , 1 ) ;
}
void T_1 F_28 ( unsigned V_113 , unsigned V_100 )
{
struct V_114 * V_115 ;
switch ( V_113 ) {
case V_116 :
V_115 = & V_117 ;
F_27 ( V_100 ) ;
break;
default:
return;
}
F_3 ( V_115 ) ;
}
void T_1 F_28 ( unsigned V_113 , unsigned V_100 ) {}
static inline void F_29 ( void )
{
F_8 ( V_118 , 0 ) ;
F_8 ( V_119 , 1 ) ;
}
static inline void F_30 ( unsigned V_100 )
{
F_8 ( V_120 , 1 ) ;
F_8 ( V_121 , 0 ) ;
if ( V_100 & V_122 )
F_8 ( V_123 , 0 ) ;
if ( V_100 & V_124 )
F_8 ( V_125 , 0 ) ;
if ( V_100 & V_126 )
F_8 ( V_127 , 0 ) ;
if ( V_100 & V_128 )
F_8 ( V_129 , 0 ) ;
if ( V_100 & V_130 )
F_8 ( V_131 , 0 ) ;
if ( V_100 & V_132 )
F_8 ( V_133 , 0 ) ;
}
static inline void F_31 ( unsigned V_100 )
{
F_8 ( V_134 , 1 ) ;
F_8 ( V_135 , 0 ) ;
if ( V_100 & V_122 )
F_8 ( V_136 , 0 ) ;
if ( V_100 & V_124 )
F_8 ( V_137 , 0 ) ;
}
static inline void F_32 ( unsigned V_100 )
{
F_8 ( V_138 , 1 ) ;
F_8 ( V_139 , 0 ) ;
if ( V_100 & V_122 )
F_8 ( V_46 , 0 ) ;
if ( V_100 & V_124 )
F_8 ( V_45 , 0 ) ;
}
static inline void F_33 ( unsigned V_100 )
{
F_8 ( V_140 , 1 ) ;
F_8 ( V_141 , 0 ) ;
if ( V_100 & V_122 )
F_9 ( V_142 , 0 ) ;
if ( V_100 & V_124 )
F_9 ( V_143 , 0 ) ;
}
static inline void F_34 ( void )
{
F_9 ( V_144 , 1 ) ;
F_9 ( V_145 , 0 ) ;
}
static inline void F_35 ( void )
{
F_8 ( V_146 , 1 ) ;
F_8 ( V_147 , 0 ) ;
}
void T_1 F_36 ( unsigned V_113 , unsigned V_148 , unsigned V_100 )
{
struct V_114 * V_115 ;
struct V_149 * V_150 ;
switch ( V_113 ) {
case 0 :
V_115 = & V_151 ;
F_29 () ;
break;
case V_152 :
V_115 = & V_153 ;
F_30 ( V_100 ) ;
break;
case V_154 :
V_115 = & V_155 ;
F_31 ( V_100 ) ;
break;
case V_156 :
V_115 = & V_157 ;
F_32 ( V_100 ) ;
break;
case V_158 :
V_115 = & V_159 ;
F_33 ( V_100 ) ;
break;
case V_160 :
V_115 = & V_161 ;
F_34 () ;
break;
case V_162 :
V_115 = & V_163 ;
F_35 () ;
break;
default:
return;
}
V_150 = V_115 -> V_164 . V_165 ;
V_150 -> V_166 = V_148 ;
if ( V_148 < V_167 )
V_168 [ V_148 ] = V_115 ;
}
void T_1 F_37 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_167 ; V_3 ++ ) {
if ( V_168 [ V_3 ] )
F_3 ( V_168 [ V_3 ] ) ;
}
}
void T_1 F_36 ( unsigned V_113 , unsigned V_148 , unsigned V_100 ) {}
void T_1 F_37 ( void ) {}
void T_1 F_38 ( struct V_169 * V_2 )
{
struct V_114 * V_115 ;
unsigned long V_63 ;
if ( ! V_2 )
return;
V_63 = F_15 ( V_64 ) ;
switch ( V_2 -> V_170 ) {
case 4 :
F_19 ( V_142 , 0 ) ;
F_8 ( V_142 , 0 ) ;
V_63 |= V_171 ;
V_172 = * V_2 ;
V_115 = & V_173 ;
break;
case 5 :
F_19 ( V_174 , 0 ) ;
F_8 ( V_174 , 0 ) ;
V_63 |= V_175 ;
V_176 = * V_2 ;
V_115 = & V_177 ;
break;
default:
F_13 ( V_61 L_3 ,
V_2 -> V_170 ) ;
return;
}
F_16 ( V_64 , V_63 ) ;
if ( F_5 ( V_2 -> V_178 ) ) {
F_19 ( V_2 -> V_178 , 0 ) ;
F_11 ( V_2 -> V_178 , 1 ) ;
}
if ( F_5 ( V_2 -> V_179 ) ) {
F_2 ( V_2 -> V_179 , 0 ) ;
F_6 ( V_2 -> V_179 , 1 ) ;
}
if ( F_5 ( V_2 -> V_37 ) ) {
F_2 ( V_2 -> V_37 , 0 ) ;
F_6 ( V_2 -> V_37 , 1 ) ;
}
F_9 ( V_180 , 0 ) ;
F_9 ( V_181 , 0 ) ;
F_8 ( V_143 , 0 ) ;
F_8 ( V_182 , 1 ) ;
if ( V_2 -> V_183 & V_184 )
#if F_39 ( V_185 ) || F_39 ( V_186 )
V_115 -> V_92 = L_4 ;
#else
#warning "board requires AT91_CF_TRUE_IDE: enable pata_at91"
#endif
else
V_115 -> V_92 = L_5 ;
F_3 ( V_115 ) ;
}
void T_1 F_38 ( struct V_169 * V_2 ) {}
void T_1 F_40 ( struct V_187 * V_2 )
{
if ( ! V_2 )
return;
if ( F_41 ( 0 , & V_2 -> V_188 ) )
F_8 ( V_189 , 0 ) ;
if ( F_41 ( 1 , & V_2 -> V_188 ) )
F_8 ( V_190 , 0 ) ;
if ( F_41 ( 2 , & V_2 -> V_188 ) )
F_8 ( V_191 , 0 ) ;
if ( F_41 ( 3 , & V_2 -> V_188 ) )
F_8 ( V_192 , 0 ) ;
if ( V_2 -> V_193 )
F_8 ( V_32 , 0 ) ;
V_2 -> V_194 = 4 ;
V_2 -> V_195 = 10 ;
V_2 -> V_196 = & V_197 ;
V_2 -> V_198 = 4 ;
V_2 -> V_199 = V_200 ;
V_201 = * V_2 ;
F_3 ( & V_202 ) ;
}
void T_1 F_40 ( struct V_187 * V_2 ) {}
static int T_1 F_42 ( void )
{
if ( F_43 () )
return 0 ;
F_25 () ;
F_26 () ;
F_23 () ;
return 0 ;
}
