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
V_8 = * V_2 ;
F_5 ( & V_9 ) ;
}
void T_1 F_1 ( struct V_1 * V_2 ) {}
void T_1 F_6 ( struct V_10 * V_2 )
{
if ( F_2 () ) {
F_3 ( V_11 , V_5 ) ;
F_7 ( V_12 , V_13 |
V_14 ) ;
}
else
F_7 ( V_12 , V_13 ) ;
V_15 . V_16 . V_7 = - V_17 ;
V_15 . V_16 . V_18 = F_8 ( V_19 ) ;
memcpy ( V_15 . V_20 , V_19 , sizeof( V_19 ) ) ;
if ( V_2 && V_2 -> V_7 > 0 ) {
F_9 ( V_2 -> V_7 , 0 ) ;
F_10 ( V_2 -> V_7 , 1 ) ;
V_15 . V_16 . V_7 = V_2 -> V_7 ;
}
F_5 ( & V_21 ) ;
}
void T_1 F_6 ( struct V_10 * V_2 ) {}
void T_1 F_11 ( struct V_22 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_23 ) {
F_9 ( V_2 -> V_23 , 0 ) ;
F_10 ( V_2 -> V_23 , 1 ) ;
}
F_12 ( V_24 , 0 ) ;
F_12 ( V_25 , 0 ) ;
F_12 ( V_26 , 0 ) ;
F_12 ( V_27 , 0 ) ;
F_12 ( V_28 , 0 ) ;
F_12 ( V_29 , 0 ) ;
F_12 ( V_30 , 0 ) ;
F_12 ( V_31 , 0 ) ;
F_12 ( V_32 , 0 ) ;
F_12 ( V_33 , 0 ) ;
if ( ! V_2 -> V_34 ) {
F_13 ( V_35 , 0 ) ;
F_13 ( V_36 , 0 ) ;
F_13 ( V_37 , 0 ) ;
F_13 ( V_38 , 0 ) ;
F_13 ( V_39 , 0 ) ;
F_13 ( V_40 , 0 ) ;
F_13 ( V_41 , 0 ) ;
F_13 ( V_42 , 0 ) ;
}
V_43 = * V_2 ;
F_5 ( & V_44 ) ;
}
void T_1 F_11 ( struct V_22 * V_2 ) {}
void T_1 F_14 ( short V_45 , struct V_46 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_47 ) {
F_9 ( V_2 -> V_47 , 1 ) ;
F_10 ( V_2 -> V_47 , 1 ) ;
}
if ( V_2 -> V_48 )
F_9 ( V_2 -> V_48 , 1 ) ;
if ( V_2 -> V_49 )
F_4 ( V_2 -> V_49 , 0 ) ;
if ( V_45 == 0 ) {
F_12 ( V_50 , 0 ) ;
F_12 ( V_51 , 1 ) ;
F_12 ( V_52 , 1 ) ;
if ( V_2 -> V_53 ) {
F_12 ( V_54 , 1 ) ;
F_12 ( V_55 , 1 ) ;
F_12 ( V_56 , 1 ) ;
}
V_57 = * V_2 ;
F_5 ( & V_58 ) ;
} else {
F_12 ( V_59 , 0 ) ;
F_12 ( V_60 , 1 ) ;
F_12 ( V_61 , 1 ) ;
if ( V_2 -> V_53 ) {
F_12 ( V_62 , 1 ) ;
F_12 ( V_63 , 1 ) ;
F_12 ( V_64 , 1 ) ;
}
V_65 = * V_2 ;
F_5 ( & V_66 ) ;
}
}
void T_1 F_14 ( short V_45 , struct V_46 * V_2 ) {}
void T_1 F_15 ( struct V_67 * V_2 )
{
unsigned long V_68 ;
if ( ! V_2 )
return;
V_68 = F_16 ( V_69 ) ;
F_7 ( V_69 , V_68 | V_70 ) ;
if ( V_2 -> V_71 )
F_4 ( V_2 -> V_71 , 1 ) ;
if ( V_2 -> V_72 )
F_9 ( V_2 -> V_72 , 1 ) ;
if ( V_2 -> V_47 )
F_9 ( V_2 -> V_47 , 1 ) ;
V_73 = * V_2 ;
F_5 ( & V_74 ) ;
}
void T_1 F_15 ( struct V_67 * V_2 ) {}
void T_1 F_17 ( struct V_75 * V_76 , int V_77 )
{
F_18 ( V_78 , 1 ) ;
F_19 ( V_78 , 1 ) ;
F_18 ( V_79 , 1 ) ;
F_19 ( V_79 , 1 ) ;
F_20 ( 0 , V_76 , V_77 ) ;
F_5 ( & V_80 ) ;
}
void T_1 F_17 ( struct V_75 * V_76 , int V_77 )
{
F_13 ( V_78 , 0 ) ;
F_19 ( V_78 , 1 ) ;
F_13 ( V_79 , 0 ) ;
F_19 ( V_79 , 1 ) ;
F_20 ( 0 , V_76 , V_77 ) ;
F_5 ( & V_80 ) ;
}
void T_1 F_17 ( struct V_75 * V_76 , int V_77 ) {}
void T_1 F_21 ( struct V_81 * V_76 , int V_77 )
{
int V_3 ;
unsigned long V_82 ;
short V_83 = 0 ;
short V_84 = 0 ;
for ( V_3 = 0 ; V_3 < V_77 ; V_3 ++ ) {
if ( V_76 [ V_3 ] . V_85 )
V_82 = ( unsigned long ) V_76 [ V_3 ] . V_85 ;
else if ( V_76 [ V_3 ] . V_86 == 0 )
V_82 = V_87 [ V_76 [ V_3 ] . V_88 ] ;
else
V_82 = V_89 [ V_76 [ V_3 ] . V_88 ] ;
if ( V_76 [ V_3 ] . V_86 == 0 )
V_83 = 1 ;
else
V_84 = 1 ;
F_4 ( V_82 , 1 ) ;
V_76 [ V_3 ] . V_85 = ( void * ) V_82 ;
}
F_22 ( V_76 , V_77 ) ;
if ( V_83 ) {
F_13 ( V_52 , 0 ) ;
F_13 ( V_51 , 0 ) ;
F_13 ( V_50 , 0 ) ;
F_5 ( & V_90 ) ;
}
if ( V_84 ) {
F_12 ( V_91 , 0 ) ;
F_12 ( V_92 , 0 ) ;
F_12 ( V_93 , 0 ) ;
F_5 ( & V_94 ) ;
}
}
void T_1 F_21 ( struct V_81 * V_76 , int V_77 ) {}
static void T_1 F_23 ( void )
{
F_5 ( & V_95 ) ;
}
static void T_1 F_23 ( void ) { }
static void T_1 F_24 ( void )
{
F_5 ( & V_96 ) ;
}
static void T_1 F_25 ( void )
{
F_5 ( & V_97 ) ;
}
static void T_1 F_25 ( void ) {}
void T_1 F_26 ( T_2 V_98 )
{
if ( V_98 & ( 1 << V_99 ) )
F_12 ( V_100 , 1 ) ;
if ( V_98 & ( 1 << V_101 ) )
F_13 ( V_102 , 1 ) ;
if ( V_98 & ( 1 << V_103 ) )
F_13 ( V_104 , 1 ) ;
if ( V_98 & ( 1 << V_105 ) )
F_13 ( V_106 , 1 ) ;
V_107 = V_98 ;
F_5 ( & V_108 ) ;
}
void T_1 F_26 ( T_2 V_98 ) {}
void T_1 F_27 ( struct V_109 * V_2 )
{
if ( ! V_2 )
return;
F_12 ( V_110 , 0 ) ;
F_12 ( V_111 , 0 ) ;
F_12 ( V_112 , 0 ) ;
F_12 ( V_113 , 0 ) ;
if ( V_2 -> V_114 )
F_4 ( V_2 -> V_114 , 0 ) ;
V_115 = * V_2 ;
F_5 ( & V_116 ) ;
}
void T_1 F_27 ( struct V_109 * V_2 ) {}
void T_1 F_28 ( struct V_117 * V_2 )
{
if ( ! V_2 )
return;
if ( F_2 () )
F_3 ( V_118 , V_5 ) ;
F_12 ( V_119 , 0 ) ;
F_12 ( V_120 , 0 ) ;
F_12 ( V_121 , 0 ) ;
F_13 ( V_122 , 0 ) ;
F_12 ( V_123 , 0 ) ;
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
F_12 ( V_37 , 0 ) ;
F_12 ( V_38 , 0 ) ;
F_12 ( V_42 , 0 ) ;
F_12 ( V_35 , 0 ) ;
F_12 ( V_36 , 0 ) ;
F_12 ( V_39 , 0 ) ;
V_135 = * V_2 ;
F_5 ( & V_136 ) ;
}
void T_1 F_28 ( struct V_117 * V_2 ) {}
static inline void F_29 ( unsigned V_137 )
{
if ( V_137 & V_138 )
F_12 ( V_139 , 1 ) ;
if ( V_137 & V_140 )
F_12 ( V_141 , 1 ) ;
if ( V_137 & V_142 )
F_12 ( V_143 , 1 ) ;
if ( V_137 & V_144 )
F_12 ( V_145 , 1 ) ;
if ( V_137 & V_146 )
F_12 ( V_78 , 1 ) ;
if ( V_137 & V_147 )
F_12 ( V_79 , 1 ) ;
}
static inline void F_30 ( unsigned V_137 )
{
if ( V_137 & V_138 )
F_12 ( V_148 , 1 ) ;
if ( V_137 & V_140 )
F_12 ( V_149 , 1 ) ;
if ( V_137 & V_142 )
F_12 ( V_102 , 1 ) ;
if ( V_137 & V_144 )
F_12 ( V_122 , 1 ) ;
if ( V_137 & V_146 )
F_12 ( V_150 , 1 ) ;
if ( V_137 & V_147 )
F_12 ( V_151 , 1 ) ;
}
void T_1 F_31 ( unsigned V_152 , unsigned V_137 )
{
struct V_153 * V_154 ;
switch ( V_152 ) {
case V_155 :
V_154 = & V_156 ;
F_29 ( V_137 ) ;
break;
case V_157 :
V_154 = & V_158 ;
F_30 ( V_137 ) ;
break;
default:
return;
}
F_5 ( V_154 ) ;
}
void T_1 F_31 ( unsigned V_152 , unsigned V_137 ) {}
static inline void F_32 ( void )
{
F_12 ( V_159 , 0 ) ;
F_12 ( V_160 , 1 ) ;
}
static inline void F_33 ( unsigned V_137 )
{
F_12 ( V_161 , 1 ) ;
F_12 ( V_162 , 0 ) ;
if ( V_137 & V_163 )
F_12 ( V_164 , 0 ) ;
if ( V_137 & V_165 )
F_12 ( V_166 , 0 ) ;
}
static inline void F_34 ( unsigned V_137 )
{
F_12 ( V_167 , 1 ) ;
F_12 ( V_168 , 0 ) ;
if ( V_137 & V_163 )
F_13 ( V_169 , 0 ) ;
if ( V_137 & V_165 )
F_13 ( V_170 , 0 ) ;
}
static inline void F_35 ( unsigned V_137 )
{
F_12 ( V_171 , 1 ) ;
F_12 ( V_172 , 0 ) ;
if ( V_137 & V_163 )
F_13 ( V_173 , 0 ) ;
if ( V_137 & V_165 )
F_13 ( V_174 , 0 ) ;
}
void T_1 F_36 ( unsigned V_152 , unsigned V_175 , unsigned V_137 )
{
struct V_153 * V_154 ;
struct V_176 * V_16 ;
switch ( V_152 ) {
case 0 :
V_154 = & V_177 ;
F_32 () ;
break;
case V_178 :
V_154 = & V_179 ;
F_33 ( V_137 ) ;
break;
case V_180 :
V_154 = & V_181 ;
F_34 ( V_137 ) ;
break;
case V_182 :
V_154 = & V_183 ;
F_35 ( V_137 ) ;
break;
default:
return;
}
V_16 = V_154 -> V_184 . V_185 ;
V_16 -> V_186 = V_175 ;
if ( V_175 < V_187 )
V_188 [ V_175 ] = V_154 ;
}
void T_1 F_37 ( unsigned V_175 )
{
if ( V_175 < V_187 ) {
V_189 = V_188 [ V_175 ] ;
F_38 ( V_188 [ V_175 ] -> V_152 ) ;
}
}
void T_1 F_39 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_187 ; V_3 ++ ) {
if ( V_188 [ V_3 ] )
F_5 ( V_188 [ V_3 ] ) ;
}
if ( ! V_189 )
F_40 ( V_190 L_1 ) ;
}
void T_1 F_36 ( unsigned V_152 , unsigned V_175 , unsigned V_137 ) {}
void T_1 F_37 ( unsigned V_175 ) {}
void T_1 F_39 ( void ) {}
static int T_1 F_41 ( void )
{
F_24 () ;
F_25 () ;
F_23 () ;
return 0 ;
}
