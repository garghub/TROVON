void T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! V_2 )
return;
if ( F_2 () )
F_3 ( V_4 , V_5 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_6 ; V_3 ++ ) {
if ( V_2 -> V_7 [ V_3 ] )
F_4 ( V_2 -> V_7 [ V_3 ] , 0 ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_6 ; V_3 ++ ) {
if ( V_2 -> V_8 [ V_3 ] )
F_5 ( V_2 -> V_8 [ V_3 ] , 1 ) ;
}
V_9 = * V_2 ;
F_6 ( & V_10 ) ;
}
void T_1 F_1 ( struct V_1 * V_2 ) {}
void T_1 F_7 ( struct V_11 * V_2 )
{
if ( F_2 () ) {
F_3 ( V_12 , V_5 ) ;
F_8 ( V_13 , V_14 |
V_15 ) ;
}
else
F_8 ( V_13 , V_14 ) ;
V_16 . V_17 . V_7 = - V_18 ;
V_16 . V_17 . V_19 = F_9 ( V_20 ) ;
memcpy ( V_16 . V_21 , V_20 , sizeof( V_20 ) ) ;
if ( V_2 && V_2 -> V_7 > 0 ) {
F_5 ( V_2 -> V_7 , 0 ) ;
F_10 ( V_2 -> V_7 , 1 ) ;
V_16 . V_17 . V_7 = V_2 -> V_7 ;
}
F_6 ( & V_22 ) ;
}
void T_1 F_7 ( struct V_11 * V_2 ) {}
void T_1 F_11 ( struct V_23 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_24 ) {
F_5 ( V_2 -> V_24 , 0 ) ;
F_10 ( V_2 -> V_24 , 1 ) ;
}
F_12 ( V_25 , 0 ) ;
F_12 ( V_26 , 0 ) ;
F_12 ( V_27 , 0 ) ;
F_12 ( V_28 , 0 ) ;
F_12 ( V_29 , 0 ) ;
F_12 ( V_30 , 0 ) ;
F_12 ( V_31 , 0 ) ;
F_12 ( V_32 , 0 ) ;
F_12 ( V_33 , 0 ) ;
F_12 ( V_34 , 0 ) ;
if ( ! V_2 -> V_35 ) {
F_13 ( V_36 , 0 ) ;
F_13 ( V_37 , 0 ) ;
F_13 ( V_38 , 0 ) ;
F_13 ( V_39 , 0 ) ;
F_13 ( V_40 , 0 ) ;
F_13 ( V_41 , 0 ) ;
F_13 ( V_42 , 0 ) ;
F_13 ( V_43 , 0 ) ;
}
V_44 = * V_2 ;
F_6 ( & V_45 ) ;
}
void T_1 F_11 ( struct V_23 * V_2 ) {}
void T_1 F_14 ( short V_46 , struct V_47 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_48 ) {
F_5 ( V_2 -> V_48 , 1 ) ;
F_10 ( V_2 -> V_48 , 1 ) ;
}
if ( V_2 -> V_49 )
F_5 ( V_2 -> V_49 , 1 ) ;
if ( V_2 -> V_50 )
F_4 ( V_2 -> V_50 , 0 ) ;
if ( V_46 == 0 ) {
F_12 ( V_51 , 0 ) ;
F_12 ( V_52 , 1 ) ;
F_12 ( V_53 , 1 ) ;
if ( V_2 -> V_54 ) {
F_12 ( V_55 , 1 ) ;
F_12 ( V_56 , 1 ) ;
F_12 ( V_57 , 1 ) ;
}
V_58 = * V_2 ;
F_6 ( & V_59 ) ;
} else {
F_12 ( V_60 , 0 ) ;
F_12 ( V_61 , 1 ) ;
F_12 ( V_62 , 1 ) ;
if ( V_2 -> V_54 ) {
F_12 ( V_63 , 1 ) ;
F_12 ( V_64 , 1 ) ;
F_12 ( V_65 , 1 ) ;
}
V_66 = * V_2 ;
F_6 ( & V_67 ) ;
}
}
void T_1 F_14 ( short V_46 , struct V_47 * V_2 ) {}
void T_1 F_15 ( struct V_68 * V_2 )
{
unsigned long V_69 ;
if ( ! V_2 )
return;
V_69 = F_16 ( V_70 ) ;
F_8 ( V_70 , V_69 | V_71 ) ;
if ( V_2 -> V_72 )
F_4 ( V_2 -> V_72 , 1 ) ;
if ( V_2 -> V_73 )
F_5 ( V_2 -> V_73 , 1 ) ;
if ( V_2 -> V_48 )
F_5 ( V_2 -> V_48 , 1 ) ;
V_74 = * V_2 ;
F_6 ( & V_75 ) ;
}
void T_1 F_15 ( struct V_68 * V_2 ) {}
void T_1 F_17 ( struct V_76 * V_77 , int V_78 )
{
F_18 ( V_79 , 1 ) ;
F_19 ( V_79 , 1 ) ;
F_18 ( V_80 , 1 ) ;
F_19 ( V_80 , 1 ) ;
F_20 ( 0 , V_77 , V_78 ) ;
F_6 ( & V_81 ) ;
}
void T_1 F_17 ( struct V_76 * V_77 , int V_78 )
{
F_13 ( V_79 , 0 ) ;
F_19 ( V_79 , 1 ) ;
F_13 ( V_80 , 0 ) ;
F_19 ( V_80 , 1 ) ;
F_20 ( 0 , V_77 , V_78 ) ;
F_6 ( & V_81 ) ;
}
void T_1 F_17 ( struct V_76 * V_77 , int V_78 ) {}
void T_1 F_21 ( struct V_82 * V_77 , int V_78 )
{
int V_3 ;
unsigned long V_83 ;
short V_84 = 0 ;
short V_85 = 0 ;
for ( V_3 = 0 ; V_3 < V_78 ; V_3 ++ ) {
if ( V_77 [ V_3 ] . V_86 )
V_83 = ( unsigned long ) V_77 [ V_3 ] . V_86 ;
else if ( V_77 [ V_3 ] . V_87 == 0 )
V_83 = V_88 [ V_77 [ V_3 ] . V_89 ] ;
else
V_83 = V_90 [ V_77 [ V_3 ] . V_89 ] ;
if ( V_77 [ V_3 ] . V_87 == 0 )
V_84 = 1 ;
else
V_85 = 1 ;
F_4 ( V_83 , 1 ) ;
V_77 [ V_3 ] . V_86 = ( void * ) V_83 ;
}
F_22 ( V_77 , V_78 ) ;
if ( V_84 ) {
F_13 ( V_53 , 0 ) ;
F_13 ( V_52 , 0 ) ;
F_13 ( V_51 , 0 ) ;
F_6 ( & V_91 ) ;
}
if ( V_85 ) {
F_12 ( V_92 , 0 ) ;
F_12 ( V_93 , 0 ) ;
F_12 ( V_94 , 0 ) ;
F_6 ( & V_95 ) ;
}
}
void T_1 F_21 ( struct V_82 * V_77 , int V_78 ) {}
static void T_1 F_23 ( void )
{
F_6 ( & V_96 ) ;
}
static void T_1 F_23 ( void ) { }
static void T_1 F_24 ( void )
{
F_6 ( & V_97 ) ;
}
static void T_1 F_25 ( void )
{
F_6 ( & V_98 ) ;
}
static void T_1 F_25 ( void ) {}
void T_1 F_26 ( T_2 V_99 )
{
if ( V_99 & ( 1 << V_100 ) )
F_12 ( V_101 , 1 ) ;
if ( V_99 & ( 1 << V_102 ) )
F_13 ( V_103 , 1 ) ;
if ( V_99 & ( 1 << V_104 ) )
F_13 ( V_105 , 1 ) ;
if ( V_99 & ( 1 << V_106 ) )
F_13 ( V_107 , 1 ) ;
V_108 = V_99 ;
F_6 ( & V_109 ) ;
}
void T_1 F_26 ( T_2 V_99 ) {}
void T_1 F_27 ( struct V_110 * V_2 )
{
if ( ! V_2 )
return;
F_12 ( V_111 , 0 ) ;
F_12 ( V_112 , 0 ) ;
F_12 ( V_113 , 0 ) ;
F_12 ( V_114 , 0 ) ;
if ( V_2 -> V_115 )
F_4 ( V_2 -> V_115 , 0 ) ;
V_116 = * V_2 ;
F_6 ( & V_117 ) ;
}
void T_1 F_27 ( struct V_110 * V_2 ) {}
void T_1 F_28 ( struct V_118 * V_2 )
{
if ( ! V_2 )
return;
if ( F_2 () )
F_3 ( V_119 , V_5 ) ;
F_12 ( V_120 , 0 ) ;
F_12 ( V_121 , 0 ) ;
F_12 ( V_122 , 0 ) ;
F_13 ( V_123 , 0 ) ;
F_12 ( V_124 , 0 ) ;
F_12 ( V_125 , 0 ) ;
F_12 ( V_126 , 0 ) ;
F_12 ( V_127 , 0 ) ;
F_12 ( V_128 , 0 ) ;
F_12 ( V_129 , 0 ) ;
F_12 ( V_130 , 0 ) ;
F_12 ( V_131 , 0 ) ;
F_12 ( V_132 , 0 ) ;
F_12 ( V_133 , 0 ) ;
F_12 ( V_134 , 0 ) ;
F_12 ( V_135 , 0 ) ;
F_12 ( V_38 , 0 ) ;
F_12 ( V_39 , 0 ) ;
F_12 ( V_43 , 0 ) ;
F_12 ( V_36 , 0 ) ;
F_12 ( V_37 , 0 ) ;
F_12 ( V_40 , 0 ) ;
V_136 = * V_2 ;
F_6 ( & V_137 ) ;
}
void T_1 F_28 ( struct V_118 * V_2 ) {}
static inline void F_29 ( unsigned V_138 )
{
if ( V_138 & V_139 )
F_12 ( V_140 , 1 ) ;
if ( V_138 & V_141 )
F_12 ( V_142 , 1 ) ;
if ( V_138 & V_143 )
F_12 ( V_144 , 1 ) ;
if ( V_138 & V_145 )
F_12 ( V_146 , 1 ) ;
if ( V_138 & V_147 )
F_12 ( V_79 , 1 ) ;
if ( V_138 & V_148 )
F_12 ( V_80 , 1 ) ;
}
static inline void F_30 ( unsigned V_138 )
{
if ( V_138 & V_139 )
F_12 ( V_149 , 1 ) ;
if ( V_138 & V_141 )
F_12 ( V_150 , 1 ) ;
if ( V_138 & V_143 )
F_12 ( V_103 , 1 ) ;
if ( V_138 & V_145 )
F_12 ( V_123 , 1 ) ;
if ( V_138 & V_147 )
F_12 ( V_151 , 1 ) ;
if ( V_138 & V_148 )
F_12 ( V_152 , 1 ) ;
}
void T_1 F_31 ( unsigned V_153 , unsigned V_138 )
{
struct V_154 * V_155 ;
switch ( V_153 ) {
case V_156 :
V_155 = & V_157 ;
F_29 ( V_138 ) ;
break;
case V_158 :
V_155 = & V_159 ;
F_30 ( V_138 ) ;
break;
default:
return;
}
F_6 ( V_155 ) ;
}
void T_1 F_31 ( unsigned V_153 , unsigned V_138 ) {}
static inline void F_32 ( void )
{
F_12 ( V_160 , 0 ) ;
F_12 ( V_161 , 1 ) ;
}
static inline void F_33 ( unsigned V_138 )
{
F_12 ( V_162 , 1 ) ;
F_12 ( V_163 , 0 ) ;
if ( V_138 & V_164 )
F_12 ( V_165 , 0 ) ;
if ( V_138 & V_166 )
F_12 ( V_167 , 0 ) ;
}
static inline void F_34 ( unsigned V_138 )
{
F_12 ( V_168 , 1 ) ;
F_12 ( V_169 , 0 ) ;
if ( V_138 & V_164 )
F_13 ( V_170 , 0 ) ;
if ( V_138 & V_166 )
F_13 ( V_171 , 0 ) ;
}
static inline void F_35 ( unsigned V_138 )
{
F_12 ( V_172 , 1 ) ;
F_12 ( V_173 , 0 ) ;
if ( V_138 & V_164 )
F_13 ( V_174 , 0 ) ;
if ( V_138 & V_166 )
F_13 ( V_175 , 0 ) ;
}
void T_1 F_36 ( unsigned V_153 , unsigned V_176 , unsigned V_138 )
{
struct V_154 * V_155 ;
struct V_177 * V_17 ;
switch ( V_153 ) {
case 0 :
V_155 = & V_178 ;
F_32 () ;
break;
case V_179 :
V_155 = & V_180 ;
F_33 ( V_138 ) ;
break;
case V_181 :
V_155 = & V_182 ;
F_34 ( V_138 ) ;
break;
case V_183 :
V_155 = & V_184 ;
F_35 ( V_138 ) ;
break;
default:
return;
}
V_17 = V_155 -> V_185 . V_186 ;
V_17 -> V_187 = V_176 ;
if ( V_176 < V_188 )
V_189 [ V_176 ] = V_155 ;
}
void T_1 F_37 ( unsigned V_176 )
{
if ( V_176 < V_188 ) {
V_190 = V_189 [ V_176 ] ;
F_38 ( V_189 [ V_176 ] -> V_153 ) ;
}
}
void T_1 F_39 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_188 ; V_3 ++ ) {
if ( V_189 [ V_3 ] )
F_6 ( V_189 [ V_3 ] ) ;
}
if ( ! V_190 )
F_40 ( V_191 L_1 ) ;
}
void T_1 F_36 ( unsigned V_153 , unsigned V_176 , unsigned V_138 ) {}
void T_1 F_37 ( unsigned V_176 ) {}
void T_1 F_39 ( void ) {}
static int T_1 F_41 ( void )
{
F_24 () ;
F_25 () ;
F_23 () ;
return 0 ;
}
