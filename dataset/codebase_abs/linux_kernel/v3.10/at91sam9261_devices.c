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
void T_1 F_7 ( short V_12 , struct V_13 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_14 [ 0 ] . V_15 ) {
if ( F_2 ( V_2 -> V_14 [ 0 ] . V_16 ) ) {
F_3 ( V_2 -> V_14 [ 0 ] . V_16 , 1 ) ;
F_6 ( V_2 -> V_14 [ 0 ] . V_16 , 1 ) ;
}
if ( F_2 ( V_2 -> V_14 [ 0 ] . V_17 ) )
F_3 ( V_2 -> V_14 [ 0 ] . V_17 , 1 ) ;
F_8 ( V_18 , 0 ) ;
F_8 ( V_19 , 1 ) ;
F_8 ( V_20 , 1 ) ;
if ( V_2 -> V_14 [ 0 ] . V_15 == 4 ) {
F_8 ( V_21 , 1 ) ;
F_8 ( V_22 , 1 ) ;
F_8 ( V_23 , 1 ) ;
}
V_24 = * V_2 ;
F_4 ( & V_25 ) ;
}
}
void T_1 F_7 ( short V_12 , struct V_13 * V_2 ) {}
void T_1 F_9 ( struct V_26 * V_2 )
{
unsigned long V_27 ;
if ( ! V_2 )
return;
V_27 = F_10 ( V_28 ) ;
F_11 ( V_28 , V_27 | V_29 ) ;
if ( F_2 ( V_2 -> V_30 ) )
F_12 ( V_2 -> V_30 , 1 ) ;
if ( F_2 ( V_2 -> V_31 ) )
F_3 ( V_2 -> V_31 , 1 ) ;
if ( F_2 ( V_2 -> V_32 ) )
F_3 ( V_2 -> V_32 , 1 ) ;
F_13 ( V_33 , 0 ) ;
F_13 ( V_34 , 0 ) ;
V_35 = * V_2 ;
F_4 ( & V_36 ) ;
}
void T_1 F_9 ( struct V_26 * V_2 ) {}
void T_1 F_14 ( struct V_37 * V_38 , int V_39 )
{
F_15 ( V_40 , 1 ) ;
F_16 ( V_40 , 1 ) ;
F_15 ( V_41 , 1 ) ;
F_16 ( V_41 , 1 ) ;
F_17 ( 0 , V_38 , V_39 ) ;
F_4 ( & V_42 ) ;
}
void T_1 F_14 ( struct V_37 * V_38 , int V_39 )
{
if ( F_18 () ) {
V_42 . V_43 = L_1 ;
} else {
V_42 . V_43 = L_2 ;
F_16 ( V_40 , 1 ) ;
F_16 ( V_41 , 1 ) ;
}
F_13 ( V_40 , 0 ) ;
F_13 ( V_41 , 0 ) ;
F_17 ( 0 , V_38 , V_39 ) ;
F_4 ( & V_42 ) ;
}
void T_1 F_14 ( struct V_37 * V_38 , int V_39 ) {}
void T_1 F_19 ( struct V_44 * V_38 , int V_39 )
{
int V_3 ;
unsigned long V_45 ;
short V_46 = 0 ;
short V_47 = 0 ;
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ ) {
if ( V_38 [ V_3 ] . V_48 )
V_45 = ( unsigned long ) V_38 [ V_3 ] . V_48 ;
else if ( V_38 [ V_3 ] . V_49 == 0 )
V_45 = V_50 [ V_38 [ V_3 ] . V_51 ] ;
else
V_45 = V_52 [ V_38 [ V_3 ] . V_51 ] ;
if ( ! F_2 ( V_45 ) )
continue;
if ( V_38 [ V_3 ] . V_49 == 0 )
V_46 = 1 ;
else
V_47 = 1 ;
F_12 ( V_45 , 1 ) ;
V_38 [ V_3 ] . V_48 = ( void * ) V_45 ;
}
F_20 ( V_38 , V_39 ) ;
if ( V_46 ) {
F_13 ( V_20 , 0 ) ;
F_13 ( V_19 , 0 ) ;
F_13 ( V_18 , 0 ) ;
F_4 ( & V_53 ) ;
}
if ( V_47 ) {
F_13 ( V_54 , 0 ) ;
F_13 ( V_55 , 0 ) ;
F_13 ( V_56 , 0 ) ;
F_4 ( & V_57 ) ;
}
}
void T_1 F_19 ( struct V_44 * V_38 , int V_39 ) {}
void T_1 F_21 ( struct V_58 * V_2 )
{
if ( ! V_2 ) {
return;
}
if ( F_18 () )
V_59 . V_43 = L_3 ;
else
V_59 . V_43 = L_4 ;
#if F_22 ( V_60 )
F_13 ( V_61 , 0 ) ;
F_13 ( V_62 , 0 ) ;
F_13 ( V_63 , 0 ) ;
F_13 ( V_64 , 0 ) ;
F_13 ( V_65 , 0 ) ;
F_13 ( V_66 , 0 ) ;
F_13 ( V_67 , 0 ) ;
F_13 ( V_68 , 0 ) ;
F_13 ( V_69 , 0 ) ;
#else
F_13 ( V_62 , 0 ) ;
F_13 ( V_63 , 0 ) ;
F_13 ( V_64 , 0 ) ;
F_13 ( V_65 , 0 ) ;
F_13 ( V_68 , 0 ) ;
F_13 ( V_69 , 0 ) ;
F_13 ( V_70 , 0 ) ;
F_13 ( V_71 , 0 ) ;
F_13 ( V_72 , 0 ) ;
F_13 ( V_73 , 0 ) ;
F_13 ( V_74 , 0 ) ;
F_13 ( V_75 , 0 ) ;
F_13 ( V_76 , 0 ) ;
F_13 ( V_77 , 0 ) ;
F_13 ( V_78 , 0 ) ;
F_13 ( V_79 , 0 ) ;
F_8 ( V_80 , 0 ) ;
F_8 ( V_81 , 0 ) ;
F_8 ( V_82 , 0 ) ;
F_8 ( V_83 , 0 ) ;
F_8 ( V_84 , 0 ) ;
F_8 ( V_85 , 0 ) ;
#endif
if ( F_23 ( V_86 ) > 2 ) {
void T_2 * V_87 ;
struct V_88 * V_89 = & V_86 [ 2 ] ;
T_3 V_90 = F_24 ( V_89 ) ;
V_87 = F_25 ( V_89 -> V_91 , V_90 ) ;
if ( V_87 ) {
memset ( V_87 , 0 , V_90 ) ;
F_26 ( V_87 ) ;
}
}
V_92 = * V_2 ;
F_4 ( & V_59 ) ;
}
void T_1 F_21 ( struct V_58 * V_2 ) {}
static void T_1 F_27 ( void )
{
F_4 ( & V_93 ) ;
}
static void T_1 F_27 ( void ) { }
static void T_1 F_28 ( void )
{
V_94 . V_43 = L_5 ;
V_94 . V_95 = 3 ;
V_96 [ 1 ] . V_91 = V_97 +
4 * V_98 ;
V_96 [ 1 ] . V_99 = V_96 [ 1 ] . V_91 + 3 ;
V_96 [ 2 ] . V_91 = V_100 + V_101 ;
V_96 [ 2 ] . V_99 = V_100 + V_101 ;
}
static void T_1 F_28 ( void )
{
V_94 . V_95 = 1 ;
}
static void T_1 F_29 ( void )
{
F_28 () ;
F_4 ( & V_94 ) ;
}
static void T_1 F_30 ( void )
{
F_4 ( & V_102 ) ;
}
static void T_1 F_30 ( void ) {}
static inline void F_31 ( unsigned V_103 )
{
if ( V_103 & V_104 )
F_13 ( V_105 , 1 ) ;
if ( V_103 & V_106 )
F_13 ( V_107 , 1 ) ;
if ( V_103 & V_108 )
F_13 ( V_80 , 1 ) ;
if ( V_103 & V_109 )
F_13 ( V_81 , 1 ) ;
if ( V_103 & V_110 )
F_13 ( V_82 , 1 ) ;
if ( V_103 & V_111 )
F_13 ( V_83 , 1 ) ;
}
static inline void F_32 ( unsigned V_103 )
{
if ( V_103 & V_104 )
F_8 ( V_112 , 1 ) ;
if ( V_103 & V_106 )
F_8 ( V_113 , 1 ) ;
if ( V_103 & V_108 )
F_8 ( V_114 , 1 ) ;
if ( V_103 & V_109 )
F_8 ( V_115 , 1 ) ;
if ( V_103 & V_110 )
F_8 ( V_116 , 1 ) ;
if ( V_103 & V_111 )
F_8 ( V_117 , 1 ) ;
}
static inline void F_33 ( unsigned V_103 )
{
if ( V_103 & V_104 )
F_8 ( V_118 , 1 ) ;
if ( V_103 & V_106 )
F_8 ( V_119 , 1 ) ;
if ( V_103 & V_108 )
F_8 ( V_120 , 1 ) ;
if ( V_103 & V_109 )
F_8 ( V_121 , 1 ) ;
if ( V_103 & V_110 )
F_8 ( V_122 , 1 ) ;
if ( V_103 & V_111 )
F_8 ( V_123 , 1 ) ;
}
void T_1 F_34 ( unsigned V_124 , unsigned V_103 )
{
struct V_125 * V_126 ;
switch ( V_124 ) {
case V_127 :
V_126 = & V_128 ;
F_31 ( V_103 ) ;
break;
case V_129 :
V_126 = & V_130 ;
F_32 ( V_103 ) ;
break;
case V_131 :
V_126 = & V_132 ;
F_33 ( V_103 ) ;
break;
default:
return;
}
F_4 ( V_126 ) ;
}
void T_1 F_34 ( unsigned V_124 , unsigned V_103 ) {}
static inline void F_35 ( void )
{
F_13 ( V_133 , 0 ) ;
F_13 ( V_134 , 1 ) ;
}
static inline void F_36 ( unsigned V_103 )
{
F_13 ( V_135 , 1 ) ;
F_13 ( V_136 , 0 ) ;
if ( V_103 & V_137 )
F_13 ( V_138 , 0 ) ;
if ( V_103 & V_139 )
F_13 ( V_140 , 0 ) ;
}
static inline void F_37 ( unsigned V_103 )
{
F_13 ( V_141 , 1 ) ;
F_13 ( V_142 , 0 ) ;
if ( V_103 & V_137 )
F_8 ( V_143 , 0 ) ;
if ( V_103 & V_139 )
F_8 ( V_144 , 0 ) ;
}
static inline void F_38 ( unsigned V_103 )
{
F_13 ( V_145 , 0 ) ;
F_13 ( V_146 , 1 ) ;
if ( V_103 & V_137 )
F_8 ( V_147 , 0 ) ;
if ( V_103 & V_139 )
F_8 ( V_148 , 0 ) ;
}
void T_1 F_39 ( unsigned V_124 , unsigned V_149 , unsigned V_103 )
{
struct V_125 * V_126 ;
struct V_150 * V_151 ;
switch ( V_124 ) {
case 0 :
V_126 = & V_152 ;
F_35 () ;
break;
case V_153 :
V_126 = & V_154 ;
F_36 ( V_103 ) ;
break;
case V_155 :
V_126 = & V_156 ;
F_37 ( V_103 ) ;
break;
case V_157 :
V_126 = & V_158 ;
F_38 ( V_103 ) ;
break;
default:
return;
}
V_151 = V_126 -> V_159 . V_160 ;
V_151 -> V_161 = V_149 ;
if ( V_149 < V_162 )
V_163 [ V_149 ] = V_126 ;
}
void T_1 F_40 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_162 ; V_3 ++ ) {
if ( V_163 [ V_3 ] )
F_4 ( V_163 [ V_3 ] ) ;
}
}
void T_1 F_39 ( unsigned V_124 , unsigned V_149 , unsigned V_103 ) {}
void T_1 F_40 ( void ) {}
static int T_1 F_41 ( void )
{
F_29 () ;
F_30 () ;
F_27 () ;
return 0 ;
}
