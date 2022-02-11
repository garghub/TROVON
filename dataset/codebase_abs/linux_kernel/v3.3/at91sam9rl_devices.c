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
F_2 ( & V_93 ) ;
}
static void T_1 F_27 ( void )
{
F_2 ( & V_94 ) ;
}
static void T_1 F_27 ( void ) {}
void T_1 F_28 ( T_2 V_95 )
{
if ( V_95 & ( 1 << V_96 ) )
F_22 ( V_97 , 1 ) ;
if ( V_95 & ( 1 << V_98 ) )
F_22 ( V_99 , 1 ) ;
if ( V_95 & ( 1 << V_100 ) )
F_22 ( V_101 , 1 ) ;
if ( V_95 & ( 1 << V_102 ) )
F_22 ( V_103 , 1 ) ;
V_104 = V_95 ;
F_2 ( & V_105 ) ;
}
void T_1 F_28 ( T_2 V_95 ) {}
static inline void F_29 ( unsigned V_106 )
{
if ( V_106 & V_107 )
F_10 ( V_108 , 1 ) ;
if ( V_106 & V_109 )
F_10 ( V_61 , 1 ) ;
if ( V_106 & V_110 )
F_10 ( V_111 , 1 ) ;
if ( V_106 & V_112 )
F_10 ( V_113 , 1 ) ;
if ( V_106 & V_114 )
F_22 ( V_115 , 1 ) ;
if ( V_106 & V_116 )
F_22 ( V_117 , 1 ) ;
}
static inline void F_30 ( unsigned V_106 )
{
if ( V_106 & V_107 )
F_22 ( V_118 , 1 ) ;
if ( V_106 & V_109 )
F_22 ( V_119 , 1 ) ;
if ( V_106 & V_110 )
F_22 ( V_120 , 1 ) ;
if ( V_106 & V_112 )
F_22 ( V_121 , 1 ) ;
if ( V_106 & V_114 )
F_22 ( V_122 , 1 ) ;
if ( V_106 & V_116 )
F_22 ( V_123 , 1 ) ;
}
void T_1 F_31 ( unsigned V_124 , unsigned V_106 )
{
struct V_125 * V_126 ;
switch ( V_124 ) {
case V_127 :
V_126 = & V_128 ;
F_29 ( V_106 ) ;
break;
case V_129 :
V_126 = & V_130 ;
F_30 ( V_106 ) ;
break;
default:
return;
}
F_2 ( V_126 ) ;
}
void T_1 F_31 ( unsigned V_124 , unsigned V_106 ) {}
static inline void F_32 ( void )
{
F_10 ( V_131 , 0 ) ;
F_10 ( V_117 , 1 ) ;
}
static inline void F_33 ( unsigned V_106 )
{
F_10 ( V_132 , 1 ) ;
F_10 ( V_133 , 0 ) ;
if ( V_106 & V_134 )
F_10 ( V_122 , 0 ) ;
if ( V_106 & V_135 )
F_10 ( V_115 , 0 ) ;
if ( V_106 & V_136 )
F_10 ( V_137 , 0 ) ;
if ( V_106 & V_138 )
F_10 ( V_139 , 0 ) ;
if ( V_106 & V_140 )
F_10 ( V_141 , 0 ) ;
if ( V_106 & V_142 )
F_10 ( V_143 , 0 ) ;
}
static inline void F_34 ( unsigned V_106 )
{
F_10 ( V_144 , 1 ) ;
F_10 ( V_145 , 0 ) ;
if ( V_106 & V_134 )
F_22 ( V_87 , 0 ) ;
if ( V_106 & V_135 )
F_22 ( V_88 , 0 ) ;
}
static inline void F_35 ( unsigned V_106 )
{
F_10 ( V_120 , 1 ) ;
F_10 ( V_121 , 0 ) ;
if ( V_106 & V_134 )
F_10 ( V_118 , 0 ) ;
if ( V_106 & V_135 )
F_10 ( V_119 , 0 ) ;
}
static inline void F_36 ( unsigned V_106 )
{
F_10 ( V_146 , 1 ) ;
F_10 ( V_147 , 0 ) ;
if ( V_106 & V_134 )
F_22 ( V_56 , 0 ) ;
if ( V_106 & V_135 )
F_22 ( V_55 , 0 ) ;
}
void T_1 F_37 ( unsigned V_124 , unsigned V_148 , unsigned V_106 )
{
struct V_125 * V_126 ;
struct V_149 * V_5 ;
switch ( V_124 ) {
case 0 :
V_126 = & V_150 ;
F_32 () ;
break;
case V_151 :
V_126 = & V_152 ;
F_33 ( V_106 ) ;
break;
case V_153 :
V_126 = & V_154 ;
F_34 ( V_106 ) ;
break;
case V_155 :
V_126 = & V_156 ;
F_35 ( V_106 ) ;
break;
case V_157 :
V_126 = & V_158 ;
F_36 ( V_106 ) ;
break;
default:
return;
}
V_5 = V_126 -> V_159 . V_160 ;
V_5 -> V_161 = V_148 ;
if ( V_148 < V_162 )
V_163 [ V_148 ] = V_126 ;
}
void T_1 F_38 ( unsigned V_148 )
{
if ( V_148 < V_162 ) {
V_164 = V_163 [ V_148 ] ;
F_39 ( V_163 [ V_148 ] -> V_124 ) ;
}
}
void T_1 F_40 ( void )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_162 ; V_43 ++ ) {
if ( V_163 [ V_43 ] )
F_2 ( V_163 [ V_43 ] ) ;
}
if ( ! V_164 )
F_41 ( V_165 L_1 ) ;
}
void T_1 F_37 ( unsigned V_124 , unsigned V_148 , unsigned V_106 ) {}
void T_1 F_38 ( unsigned V_148 ) {}
void T_1 F_40 ( void ) {}
static int T_1 F_42 ( void )
{
F_1 () ;
F_25 () ;
F_26 () ;
F_27 () ;
F_23 () ;
return 0 ;
}
