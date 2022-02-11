void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void T_1 F_1 ( void ) {}
void T_1 F_3 ( struct V_2 * V_3 )
{
V_4 . V_5 . V_6 = - V_7 ;
V_4 . V_5 . V_8 = F_4 ( V_9 ) ;
memcpy ( V_4 . V_10 , V_9 , sizeof( V_9 ) ) ;
if ( V_3 && F_5 ( V_3 -> V_6 ) ) {
F_6 ( V_3 -> V_6 , 0 ) ;
F_7 ( V_3 -> V_6 , 1 ) ;
V_4 . V_5 . V_6 = V_3 -> V_6 ;
}
F_2 ( & V_11 ) ;
}
void T_1 F_3 ( struct V_2 * V_3 ) {}
void T_1 F_8 ( short V_12 , struct V_13 * V_3 )
{
if ( ! V_3 )
return;
if ( F_5 ( V_3 -> V_14 ) ) {
F_6 ( V_3 -> V_14 , 1 ) ;
F_7 ( V_3 -> V_14 , 1 ) ;
}
if ( F_5 ( V_3 -> V_15 ) )
F_6 ( V_3 -> V_15 , 1 ) ;
if ( F_5 ( V_3 -> V_16 ) )
F_9 ( V_3 -> V_16 , 0 ) ;
F_10 ( V_17 , 0 ) ;
F_10 ( V_18 , 1 ) ;
F_10 ( V_19 , 1 ) ;
if ( V_3 -> V_20 ) {
F_10 ( V_21 , 1 ) ;
F_10 ( V_22 , 1 ) ;
F_10 ( V_23 , 1 ) ;
}
V_24 = * V_3 ;
F_2 ( & V_25 ) ;
}
void T_1 F_8 ( short V_12 , struct V_13 * V_3 ) {}
void T_1 F_11 ( struct V_26 * V_3 )
{
unsigned long V_27 ;
if ( ! V_3 )
return;
V_27 = F_12 ( V_28 ) ;
F_13 ( V_28 , V_27 | V_29 ) ;
if ( F_5 ( V_3 -> V_30 ) )
F_9 ( V_3 -> V_30 , 1 ) ;
if ( F_5 ( V_3 -> V_31 ) )
F_6 ( V_3 -> V_31 , 1 ) ;
if ( F_5 ( V_3 -> V_14 ) )
F_6 ( V_3 -> V_14 , 1 ) ;
F_10 ( V_32 , 0 ) ;
F_10 ( V_33 , 0 ) ;
V_34 = * V_3 ;
F_2 ( & V_35 ) ;
}
void T_1 F_11 ( struct V_26 * V_3 ) {}
void T_1 F_14 ( struct V_36 * V_37 , int V_38 )
{
F_15 ( V_39 , 1 ) ;
F_16 ( V_39 , 1 ) ;
F_15 ( V_40 , 1 ) ;
F_16 ( V_40 , 1 ) ;
F_17 ( 0 , V_37 , V_38 ) ;
F_2 ( & V_41 ) ;
}
void T_1 F_14 ( struct V_36 * V_37 , int V_38 )
{
F_10 ( V_39 , 0 ) ;
F_16 ( V_39 , 1 ) ;
F_10 ( V_40 , 0 ) ;
F_16 ( V_40 , 1 ) ;
F_17 ( 0 , V_37 , V_38 ) ;
F_2 ( & V_41 ) ;
}
void T_1 F_14 ( struct V_36 * V_37 , int V_38 ) {}
void T_1 F_18 ( struct V_42 * V_37 , int V_38 )
{
int V_43 ;
unsigned long V_44 ;
F_10 ( V_45 , 0 ) ;
F_10 ( V_46 , 0 ) ;
F_10 ( V_47 , 0 ) ;
for ( V_43 = 0 ; V_43 < V_38 ; V_43 ++ ) {
if ( V_37 [ V_43 ] . V_48 )
V_44 = ( unsigned long ) V_37 [ V_43 ] . V_48 ;
else
V_44 = V_49 [ V_37 [ V_43 ] . V_50 ] ;
if ( ! F_5 ( V_44 ) )
continue;
F_9 ( V_44 , 1 ) ;
V_37 [ V_43 ] . V_48 = ( void * ) V_44 ;
}
F_19 ( V_37 , V_38 ) ;
F_2 ( & V_51 ) ;
}
void T_1 F_18 ( struct V_42 * V_37 , int V_38 ) {}
void T_1 F_20 ( struct V_52 * V_3 )
{
if ( ! V_3 )
return;
F_10 ( V_53 , 0 ) ;
F_10 ( V_54 , 0 ) ;
F_10 ( V_55 , 0 ) ;
F_10 ( V_56 , 0 ) ;
if ( F_5 ( V_3 -> V_57 ) )
F_9 ( V_3 -> V_57 , 0 ) ;
V_58 = * V_3 ;
F_2 ( & V_59 ) ;
}
void T_1 F_20 ( struct V_52 * V_3 ) {}
void T_1 F_21 ( struct V_60 * V_3 )
{
if ( ! V_3 ) {
return;
}
F_22 ( V_61 , 0 ) ;
F_10 ( V_62 , 0 ) ;
F_10 ( V_63 , 0 ) ;
F_10 ( V_64 , 0 ) ;
F_10 ( V_65 , 0 ) ;
F_22 ( V_66 , 0 ) ;
F_22 ( V_67 , 0 ) ;
F_22 ( V_68 , 0 ) ;
F_22 ( V_69 , 0 ) ;
F_22 ( V_70 , 0 ) ;
F_22 ( V_71 , 0 ) ;
F_22 ( V_72 , 0 ) ;
F_22 ( V_73 , 0 ) ;
F_22 ( V_74 , 0 ) ;
F_22 ( V_75 , 0 ) ;
F_22 ( V_76 , 0 ) ;
F_22 ( V_77 , 0 ) ;
F_22 ( V_78 , 0 ) ;
F_22 ( V_79 , 0 ) ;
F_22 ( V_80 , 0 ) ;
F_22 ( V_81 , 0 ) ;
V_82 = * V_3 ;
F_2 ( & V_83 ) ;
}
void T_1 F_21 ( struct V_60 * V_3 ) {}
static void T_1 F_23 ( void )
{
F_2 ( & V_84 ) ;
}
static void T_1 F_23 ( void ) { }
void T_1 F_24 ( struct V_85 * V_3 )
{
if ( ! V_3 )
return;
F_10 ( V_86 , 0 ) ;
F_10 ( V_87 , 0 ) ;
F_10 ( V_88 , 0 ) ;
F_10 ( V_89 , 0 ) ;
V_90 = * V_3 ;
F_2 ( & V_91 ) ;
}
void T_1 F_24 ( struct V_85 * V_3 ) {}
static void T_1 F_25 ( void )
{
F_2 ( & V_92 ) ;
}
static void T_1 F_25 ( void ) {}
static void T_1 F_26 ( void )
{
V_93 . V_94 = L_1 ;
V_93 . V_95 = 3 ;
V_96 [ 1 ] . V_97 = V_98 +
4 * V_99 ;
V_96 [ 1 ] . V_100 = V_96 [ 1 ] . V_97 + 3 ;
V_96 [ 2 ] . V_97 = V_101 + V_102 ;
V_96 [ 2 ] . V_100 = V_101 + V_102 ;
}
static void T_1 F_26 ( void )
{
V_93 . V_95 = 1 ;
}
static void T_1 F_27 ( void )
{
F_26 () ;
F_2 ( & V_93 ) ;
}
static void T_1 F_28 ( void )
{
F_2 ( & V_103 ) ;
}
static void T_1 F_28 ( void ) {}
void T_1 F_29 ( T_2 V_104 )
{
if ( V_104 & ( 1 << V_105 ) )
F_22 ( V_106 , 1 ) ;
if ( V_104 & ( 1 << V_107 ) )
F_22 ( V_108 , 1 ) ;
if ( V_104 & ( 1 << V_109 ) )
F_22 ( V_110 , 1 ) ;
if ( V_104 & ( 1 << V_111 ) )
F_22 ( V_112 , 1 ) ;
V_113 = V_104 ;
F_2 ( & V_114 ) ;
}
void T_1 F_29 ( T_2 V_104 ) {}
static inline void F_30 ( unsigned V_115 )
{
if ( V_115 & V_116 )
F_10 ( V_117 , 1 ) ;
if ( V_115 & V_118 )
F_10 ( V_61 , 1 ) ;
if ( V_115 & V_119 )
F_10 ( V_120 , 1 ) ;
if ( V_115 & V_121 )
F_10 ( V_122 , 1 ) ;
if ( V_115 & V_123 )
F_22 ( V_124 , 1 ) ;
if ( V_115 & V_125 )
F_22 ( V_126 , 1 ) ;
}
static inline void F_31 ( unsigned V_115 )
{
if ( V_115 & V_116 )
F_22 ( V_127 , 1 ) ;
if ( V_115 & V_118 )
F_22 ( V_128 , 1 ) ;
if ( V_115 & V_119 )
F_22 ( V_129 , 1 ) ;
if ( V_115 & V_121 )
F_22 ( V_130 , 1 ) ;
if ( V_115 & V_123 )
F_22 ( V_131 , 1 ) ;
if ( V_115 & V_125 )
F_22 ( V_132 , 1 ) ;
}
void T_1 F_32 ( unsigned V_133 , unsigned V_115 )
{
struct V_134 * V_135 ;
switch ( V_133 ) {
case V_136 :
V_135 = & V_137 ;
F_30 ( V_115 ) ;
break;
case V_138 :
V_135 = & V_139 ;
F_31 ( V_115 ) ;
break;
default:
return;
}
F_2 ( V_135 ) ;
}
void T_1 F_32 ( unsigned V_133 , unsigned V_115 ) {}
static inline void F_33 ( void )
{
F_10 ( V_140 , 0 ) ;
F_10 ( V_126 , 1 ) ;
}
static inline void F_34 ( unsigned V_115 )
{
F_10 ( V_141 , 1 ) ;
F_10 ( V_142 , 0 ) ;
if ( V_115 & V_143 )
F_10 ( V_131 , 0 ) ;
if ( V_115 & V_144 )
F_10 ( V_124 , 0 ) ;
if ( V_115 & V_145 )
F_10 ( V_146 , 0 ) ;
if ( V_115 & V_147 )
F_10 ( V_148 , 0 ) ;
if ( V_115 & V_149 )
F_10 ( V_150 , 0 ) ;
if ( V_115 & V_151 )
F_10 ( V_152 , 0 ) ;
}
static inline void F_35 ( unsigned V_115 )
{
F_10 ( V_153 , 1 ) ;
F_10 ( V_154 , 0 ) ;
if ( V_115 & V_143 )
F_22 ( V_87 , 0 ) ;
if ( V_115 & V_144 )
F_22 ( V_88 , 0 ) ;
}
static inline void F_36 ( unsigned V_115 )
{
F_10 ( V_129 , 1 ) ;
F_10 ( V_130 , 0 ) ;
if ( V_115 & V_143 )
F_10 ( V_127 , 0 ) ;
if ( V_115 & V_144 )
F_10 ( V_128 , 0 ) ;
}
static inline void F_37 ( unsigned V_115 )
{
F_10 ( V_155 , 1 ) ;
F_10 ( V_156 , 0 ) ;
if ( V_115 & V_143 )
F_22 ( V_56 , 0 ) ;
if ( V_115 & V_144 )
F_22 ( V_55 , 0 ) ;
}
void T_1 F_38 ( unsigned V_133 , unsigned V_157 , unsigned V_115 )
{
struct V_134 * V_135 ;
struct V_158 * V_5 ;
switch ( V_133 ) {
case 0 :
V_135 = & V_159 ;
F_33 () ;
break;
case V_160 :
V_135 = & V_161 ;
F_34 ( V_115 ) ;
break;
case V_162 :
V_135 = & V_163 ;
F_35 ( V_115 ) ;
break;
case V_164 :
V_135 = & V_165 ;
F_36 ( V_115 ) ;
break;
case V_166 :
V_135 = & V_167 ;
F_37 ( V_115 ) ;
break;
default:
return;
}
V_5 = V_135 -> V_168 . V_169 ;
V_5 -> V_170 = V_157 ;
if ( V_157 < V_171 )
V_172 [ V_157 ] = V_135 ;
}
void T_1 F_39 ( void )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_171 ; V_43 ++ ) {
if ( V_172 [ V_43 ] )
F_2 ( V_172 [ V_43 ] ) ;
}
}
void T_1 F_38 ( unsigned V_133 , unsigned V_157 , unsigned V_115 ) {}
void T_1 F_39 ( void ) {}
static int T_1 F_40 ( void )
{
F_1 () ;
F_25 () ;
F_27 () ;
F_28 () ;
F_23 () ;
return 0 ;
}
