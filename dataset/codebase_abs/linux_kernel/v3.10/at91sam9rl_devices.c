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
if ( V_3 -> V_14 [ 0 ] . V_15 ) {
if ( F_5 ( V_3 -> V_14 [ 0 ] . V_16 ) ) {
F_6 ( V_3 -> V_14 [ 0 ] . V_16 , 1 ) ;
F_7 ( V_3 -> V_14 [ 0 ] . V_16 , 1 ) ;
}
if ( F_5 ( V_3 -> V_14 [ 0 ] . V_17 ) )
F_6 ( V_3 -> V_14 [ 0 ] . V_17 , 1 ) ;
F_9 ( V_18 , 0 ) ;
F_9 ( V_19 , 1 ) ;
F_9 ( V_20 , 1 ) ;
if ( V_3 -> V_14 [ 0 ] . V_15 == 4 ) {
F_9 ( V_21 , 1 ) ;
F_9 ( V_22 , 1 ) ;
F_9 ( V_23 , 1 ) ;
}
V_24 = * V_3 ;
F_2 ( & V_25 ) ;
}
}
void T_1 F_8 ( short V_12 , struct V_13 * V_3 ) {}
void T_1 F_10 ( struct V_26 * V_3 )
{
unsigned long V_27 ;
if ( ! V_3 )
return;
V_27 = F_11 ( V_28 ) ;
F_12 ( V_28 , V_27 | V_29 ) ;
if ( F_5 ( V_3 -> V_30 ) )
F_13 ( V_3 -> V_30 , 1 ) ;
if ( F_5 ( V_3 -> V_31 ) )
F_6 ( V_3 -> V_31 , 1 ) ;
if ( F_5 ( V_3 -> V_32 ) )
F_6 ( V_3 -> V_32 , 1 ) ;
F_9 ( V_33 , 0 ) ;
F_9 ( V_34 , 0 ) ;
V_35 = * V_3 ;
F_2 ( & V_36 ) ;
}
void T_1 F_10 ( struct V_26 * V_3 ) {}
void T_1 F_14 ( struct V_37 * V_38 , int V_39 )
{
F_15 ( V_40 , 1 ) ;
F_16 ( V_40 , 1 ) ;
F_15 ( V_41 , 1 ) ;
F_16 ( V_41 , 1 ) ;
F_17 ( 0 , V_38 , V_39 ) ;
F_2 ( & V_42 ) ;
}
void T_1 F_14 ( struct V_37 * V_38 , int V_39 )
{
F_9 ( V_40 , 0 ) ;
F_16 ( V_40 , 1 ) ;
F_9 ( V_41 , 0 ) ;
F_16 ( V_41 , 1 ) ;
F_17 ( 0 , V_38 , V_39 ) ;
F_2 ( & V_42 ) ;
}
void T_1 F_14 ( struct V_37 * V_38 , int V_39 ) {}
void T_1 F_18 ( struct V_43 * V_38 , int V_39 )
{
int V_44 ;
unsigned long V_45 ;
F_9 ( V_46 , 0 ) ;
F_9 ( V_47 , 0 ) ;
F_9 ( V_48 , 0 ) ;
for ( V_44 = 0 ; V_44 < V_39 ; V_44 ++ ) {
if ( V_38 [ V_44 ] . V_49 )
V_45 = ( unsigned long ) V_38 [ V_44 ] . V_49 ;
else
V_45 = V_50 [ V_38 [ V_44 ] . V_51 ] ;
if ( ! F_5 ( V_45 ) )
continue;
F_13 ( V_45 , 1 ) ;
V_38 [ V_44 ] . V_49 = ( void * ) V_45 ;
}
F_19 ( V_38 , V_39 ) ;
F_2 ( & V_52 ) ;
}
void T_1 F_18 ( struct V_43 * V_38 , int V_39 ) {}
void T_1 F_20 ( struct V_53 * V_3 )
{
if ( ! V_3 )
return;
F_9 ( V_54 , 0 ) ;
F_9 ( V_55 , 0 ) ;
F_9 ( V_56 , 0 ) ;
F_9 ( V_57 , 0 ) ;
if ( F_5 ( V_3 -> V_58 ) )
F_13 ( V_3 -> V_58 , 0 ) ;
V_59 = * V_3 ;
F_2 ( & V_60 ) ;
}
void T_1 F_20 ( struct V_53 * V_3 ) {}
void T_1 F_21 ( struct V_61 * V_3 )
{
if ( ! V_3 ) {
return;
}
F_22 ( V_62 , 0 ) ;
F_9 ( V_63 , 0 ) ;
F_9 ( V_64 , 0 ) ;
F_9 ( V_65 , 0 ) ;
F_9 ( V_66 , 0 ) ;
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
F_22 ( V_82 , 0 ) ;
V_83 = * V_3 ;
F_2 ( & V_84 ) ;
}
void T_1 F_21 ( struct V_61 * V_3 ) {}
static void T_1 F_23 ( void )
{
F_2 ( & V_85 ) ;
}
static void T_1 F_23 ( void ) { }
void T_1 F_24 ( struct V_86 * V_3 )
{
if ( ! V_3 )
return;
F_9 ( V_87 , 0 ) ;
F_9 ( V_88 , 0 ) ;
F_9 ( V_89 , 0 ) ;
F_9 ( V_90 , 0 ) ;
V_91 = * V_3 ;
F_2 ( & V_92 ) ;
}
void T_1 F_24 ( struct V_86 * V_3 ) {}
static void T_1 F_25 ( void )
{
F_2 ( & V_93 ) ;
}
static void T_1 F_25 ( void ) {}
static void T_1 F_26 ( void )
{
V_94 . V_95 = L_1 ;
V_94 . V_96 = 3 ;
V_97 [ 1 ] . V_98 = V_99 +
4 * V_100 ;
V_97 [ 1 ] . V_101 = V_97 [ 1 ] . V_98 + 3 ;
V_97 [ 2 ] . V_98 = V_102 + V_103 ;
V_97 [ 2 ] . V_101 = V_102 + V_103 ;
}
static void T_1 F_26 ( void )
{
V_94 . V_96 = 1 ;
}
static void T_1 F_27 ( void )
{
F_26 () ;
F_2 ( & V_94 ) ;
}
static void T_1 F_28 ( void )
{
F_2 ( & V_104 ) ;
}
static void T_1 F_28 ( void ) {}
void T_1 F_29 ( T_2 V_105 )
{
if ( V_105 & ( 1 << V_106 ) )
F_22 ( V_107 , 1 ) ;
if ( V_105 & ( 1 << V_108 ) )
F_22 ( V_109 , 1 ) ;
if ( V_105 & ( 1 << V_110 ) )
F_22 ( V_111 , 1 ) ;
if ( V_105 & ( 1 << V_112 ) )
F_22 ( V_113 , 1 ) ;
V_114 = V_105 ;
F_2 ( & V_115 ) ;
}
void T_1 F_29 ( T_2 V_105 ) {}
static inline void F_30 ( unsigned V_116 )
{
if ( V_116 & V_117 )
F_9 ( V_118 , 1 ) ;
if ( V_116 & V_119 )
F_9 ( V_62 , 1 ) ;
if ( V_116 & V_120 )
F_9 ( V_121 , 1 ) ;
if ( V_116 & V_122 )
F_9 ( V_123 , 1 ) ;
if ( V_116 & V_124 )
F_22 ( V_125 , 1 ) ;
if ( V_116 & V_126 )
F_22 ( V_127 , 1 ) ;
}
static inline void F_31 ( unsigned V_116 )
{
if ( V_116 & V_117 )
F_22 ( V_128 , 1 ) ;
if ( V_116 & V_119 )
F_22 ( V_129 , 1 ) ;
if ( V_116 & V_120 )
F_22 ( V_130 , 1 ) ;
if ( V_116 & V_122 )
F_22 ( V_131 , 1 ) ;
if ( V_116 & V_124 )
F_22 ( V_132 , 1 ) ;
if ( V_116 & V_126 )
F_22 ( V_133 , 1 ) ;
}
void T_1 F_32 ( unsigned V_134 , unsigned V_116 )
{
struct V_135 * V_136 ;
switch ( V_134 ) {
case V_137 :
V_136 = & V_138 ;
F_30 ( V_116 ) ;
break;
case V_139 :
V_136 = & V_140 ;
F_31 ( V_116 ) ;
break;
default:
return;
}
F_2 ( V_136 ) ;
}
void T_1 F_32 ( unsigned V_134 , unsigned V_116 ) {}
static inline void F_33 ( void )
{
F_9 ( V_141 , 0 ) ;
F_9 ( V_127 , 1 ) ;
}
static inline void F_34 ( unsigned V_116 )
{
F_9 ( V_142 , 1 ) ;
F_9 ( V_143 , 0 ) ;
if ( V_116 & V_144 )
F_9 ( V_132 , 0 ) ;
if ( V_116 & V_145 )
F_9 ( V_125 , 0 ) ;
if ( V_116 & V_146 )
F_9 ( V_147 , 0 ) ;
if ( V_116 & V_148 )
F_9 ( V_149 , 0 ) ;
if ( V_116 & V_150 )
F_9 ( V_151 , 0 ) ;
if ( V_116 & V_152 )
F_9 ( V_153 , 0 ) ;
}
static inline void F_35 ( unsigned V_116 )
{
F_9 ( V_154 , 1 ) ;
F_9 ( V_155 , 0 ) ;
if ( V_116 & V_144 )
F_22 ( V_88 , 0 ) ;
if ( V_116 & V_145 )
F_22 ( V_89 , 0 ) ;
}
static inline void F_36 ( unsigned V_116 )
{
F_9 ( V_130 , 1 ) ;
F_9 ( V_131 , 0 ) ;
if ( V_116 & V_144 )
F_9 ( V_128 , 0 ) ;
if ( V_116 & V_145 )
F_9 ( V_129 , 0 ) ;
}
static inline void F_37 ( unsigned V_116 )
{
F_9 ( V_156 , 1 ) ;
F_9 ( V_157 , 0 ) ;
if ( V_116 & V_144 )
F_22 ( V_57 , 0 ) ;
if ( V_116 & V_145 )
F_22 ( V_56 , 0 ) ;
}
void T_1 F_38 ( unsigned V_134 , unsigned V_158 , unsigned V_116 )
{
struct V_135 * V_136 ;
struct V_159 * V_5 ;
switch ( V_134 ) {
case 0 :
V_136 = & V_160 ;
F_33 () ;
break;
case V_161 :
V_136 = & V_162 ;
F_34 ( V_116 ) ;
break;
case V_163 :
V_136 = & V_164 ;
F_35 ( V_116 ) ;
break;
case V_165 :
V_136 = & V_166 ;
F_36 ( V_116 ) ;
break;
case V_167 :
V_136 = & V_168 ;
F_37 ( V_116 ) ;
break;
default:
return;
}
V_5 = V_136 -> V_169 . V_170 ;
V_5 -> V_171 = V_158 ;
if ( V_158 < V_172 )
V_173 [ V_158 ] = V_136 ;
}
void T_1 F_39 ( void )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_172 ; V_44 ++ ) {
if ( V_173 [ V_44 ] )
F_2 ( V_173 [ V_44 ] ) ;
}
}
void T_1 F_38 ( unsigned V_134 , unsigned V_158 , unsigned V_116 ) {}
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
