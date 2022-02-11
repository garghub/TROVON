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
void T_1 F_7 ( short V_12 , struct V_13 * V_2 )
{
if ( ! V_2 )
return;
if ( F_5 ( V_2 -> V_14 ) ) {
F_2 ( V_2 -> V_14 , 1 ) ;
F_6 ( V_2 -> V_14 , 1 ) ;
}
if ( F_5 ( V_2 -> V_15 ) )
F_2 ( V_2 -> V_15 , 1 ) ;
if ( F_5 ( V_2 -> V_16 ) )
F_8 ( V_2 -> V_16 , 0 ) ;
F_9 ( V_17 , 0 ) ;
F_9 ( V_18 , 1 ) ;
F_9 ( V_19 , 1 ) ;
if ( V_2 -> V_20 ) {
F_9 ( V_21 , 1 ) ;
F_9 ( V_22 , 1 ) ;
F_9 ( V_23 , 1 ) ;
}
V_24 = * V_2 ;
F_3 ( & V_25 ) ;
}
void T_1 F_7 ( short V_12 , struct V_13 * V_2 ) {}
void T_1 F_10 ( struct V_26 * V_2 )
{
unsigned long V_27 ;
if ( ! V_2 )
return;
V_27 = F_11 ( V_28 ) ;
F_12 ( V_28 , V_27 | V_29 ) ;
if ( F_5 ( V_2 -> V_30 ) )
F_8 ( V_2 -> V_30 , 1 ) ;
if ( F_5 ( V_2 -> V_31 ) )
F_2 ( V_2 -> V_31 , 1 ) ;
if ( F_5 ( V_2 -> V_14 ) )
F_2 ( V_2 -> V_14 , 1 ) ;
F_13 ( V_32 , 0 ) ;
F_13 ( V_33 , 0 ) ;
V_34 = * V_2 ;
F_3 ( & V_35 ) ;
}
void T_1 F_10 ( struct V_26 * V_2 ) {}
void T_1 F_14 ( struct V_36 * V_37 , int V_38 )
{
F_15 ( V_39 , 1 ) ;
F_16 ( V_39 , 1 ) ;
F_15 ( V_40 , 1 ) ;
F_16 ( V_40 , 1 ) ;
F_17 ( 0 , V_37 , V_38 ) ;
F_3 ( & V_41 ) ;
}
void T_1 F_14 ( struct V_36 * V_37 , int V_38 )
{
F_13 ( V_39 , 0 ) ;
F_16 ( V_39 , 1 ) ;
F_13 ( V_40 , 0 ) ;
F_16 ( V_40 , 1 ) ;
F_17 ( 0 , V_37 , V_38 ) ;
F_3 ( & V_41 ) ;
}
void T_1 F_14 ( struct V_36 * V_37 , int V_38 ) {}
void T_1 F_18 ( struct V_42 * V_37 , int V_38 )
{
int V_3 ;
unsigned long V_43 ;
short V_44 = 0 ;
short V_45 = 0 ;
for ( V_3 = 0 ; V_3 < V_38 ; V_3 ++ ) {
if ( V_37 [ V_3 ] . V_46 )
V_43 = ( unsigned long ) V_37 [ V_3 ] . V_46 ;
else if ( V_37 [ V_3 ] . V_47 == 0 )
V_43 = V_48 [ V_37 [ V_3 ] . V_49 ] ;
else
V_43 = V_50 [ V_37 [ V_3 ] . V_49 ] ;
if ( ! F_5 ( V_43 ) )
continue;
if ( V_37 [ V_3 ] . V_47 == 0 )
V_44 = 1 ;
else
V_45 = 1 ;
F_8 ( V_43 , 1 ) ;
V_37 [ V_3 ] . V_46 = ( void * ) V_43 ;
}
F_19 ( V_37 , V_38 ) ;
if ( V_44 ) {
F_13 ( V_19 , 0 ) ;
F_13 ( V_18 , 0 ) ;
F_13 ( V_17 , 0 ) ;
F_3 ( & V_51 ) ;
}
if ( V_45 ) {
F_13 ( V_52 , 0 ) ;
F_13 ( V_53 , 0 ) ;
F_13 ( V_54 , 0 ) ;
F_3 ( & V_55 ) ;
}
}
void T_1 F_18 ( struct V_42 * V_37 , int V_38 ) {}
void T_1 F_20 ( struct V_56 * V_2 )
{
if ( ! V_2 ) {
return;
}
#if F_21 ( V_57 )
F_13 ( V_58 , 0 ) ;
F_13 ( V_59 , 0 ) ;
F_13 ( V_60 , 0 ) ;
F_13 ( V_61 , 0 ) ;
F_13 ( V_62 , 0 ) ;
F_13 ( V_63 , 0 ) ;
F_13 ( V_64 , 0 ) ;
F_13 ( V_65 , 0 ) ;
F_13 ( V_66 , 0 ) ;
#else
F_13 ( V_59 , 0 ) ;
F_13 ( V_60 , 0 ) ;
F_13 ( V_61 , 0 ) ;
F_13 ( V_62 , 0 ) ;
F_13 ( V_65 , 0 ) ;
F_13 ( V_66 , 0 ) ;
F_13 ( V_67 , 0 ) ;
F_13 ( V_68 , 0 ) ;
F_13 ( V_69 , 0 ) ;
F_13 ( V_70 , 0 ) ;
F_13 ( V_71 , 0 ) ;
F_13 ( V_72 , 0 ) ;
F_13 ( V_73 , 0 ) ;
F_13 ( V_74 , 0 ) ;
F_13 ( V_75 , 0 ) ;
F_13 ( V_76 , 0 ) ;
F_9 ( V_77 , 0 ) ;
F_9 ( V_78 , 0 ) ;
F_9 ( V_79 , 0 ) ;
F_9 ( V_80 , 0 ) ;
F_9 ( V_81 , 0 ) ;
F_9 ( V_82 , 0 ) ;
#endif
if ( F_22 ( V_83 ) > 2 ) {
void T_2 * V_84 ;
struct V_85 * V_86 = & V_83 [ 2 ] ;
T_3 V_87 = F_23 ( V_86 ) ;
V_84 = F_24 ( V_86 -> V_88 , V_87 ) ;
if ( V_84 ) {
memset ( V_84 , 0 , V_87 ) ;
F_25 ( V_84 ) ;
}
}
V_89 = * V_2 ;
F_3 ( & V_90 ) ;
}
void T_1 F_20 ( struct V_56 * V_2 ) {}
static void T_1 F_26 ( void )
{
F_3 ( & V_91 ) ;
}
static void T_1 F_26 ( void ) { }
static void T_1 F_27 ( void )
{
V_92 . V_93 = L_1 ;
V_92 . V_94 = 3 ;
V_95 [ 1 ] . V_88 = V_96 +
4 * V_97 ;
V_95 [ 1 ] . V_98 = V_95 [ 1 ] . V_88 + 3 ;
V_95 [ 2 ] . V_88 = V_99 + V_100 ;
V_95 [ 2 ] . V_98 = V_99 + V_100 ;
}
static void T_1 F_27 ( void )
{
V_92 . V_94 = 1 ;
}
static void T_1 F_28 ( void )
{
F_27 () ;
F_3 ( & V_92 ) ;
}
static void T_1 F_29 ( void )
{
F_3 ( & V_101 ) ;
}
static void T_1 F_29 ( void ) {}
static inline void F_30 ( unsigned V_102 )
{
if ( V_102 & V_103 )
F_13 ( V_104 , 1 ) ;
if ( V_102 & V_105 )
F_13 ( V_106 , 1 ) ;
if ( V_102 & V_107 )
F_13 ( V_77 , 1 ) ;
if ( V_102 & V_108 )
F_13 ( V_78 , 1 ) ;
if ( V_102 & V_109 )
F_13 ( V_79 , 1 ) ;
if ( V_102 & V_110 )
F_13 ( V_80 , 1 ) ;
}
static inline void F_31 ( unsigned V_102 )
{
if ( V_102 & V_103 )
F_9 ( V_111 , 1 ) ;
if ( V_102 & V_105 )
F_9 ( V_112 , 1 ) ;
if ( V_102 & V_107 )
F_9 ( V_113 , 1 ) ;
if ( V_102 & V_108 )
F_9 ( V_114 , 1 ) ;
if ( V_102 & V_109 )
F_9 ( V_115 , 1 ) ;
if ( V_102 & V_110 )
F_9 ( V_116 , 1 ) ;
}
static inline void F_32 ( unsigned V_102 )
{
if ( V_102 & V_103 )
F_9 ( V_117 , 1 ) ;
if ( V_102 & V_105 )
F_9 ( V_118 , 1 ) ;
if ( V_102 & V_107 )
F_9 ( V_119 , 1 ) ;
if ( V_102 & V_108 )
F_9 ( V_120 , 1 ) ;
if ( V_102 & V_109 )
F_9 ( V_121 , 1 ) ;
if ( V_102 & V_110 )
F_9 ( V_122 , 1 ) ;
}
void T_1 F_33 ( unsigned V_123 , unsigned V_102 )
{
struct V_124 * V_125 ;
switch ( V_123 ) {
case V_126 :
V_125 = & V_127 ;
F_30 ( V_102 ) ;
break;
case V_128 :
V_125 = & V_129 ;
F_31 ( V_102 ) ;
break;
case V_130 :
V_125 = & V_131 ;
F_32 ( V_102 ) ;
break;
default:
return;
}
F_3 ( V_125 ) ;
}
void T_1 F_33 ( unsigned V_123 , unsigned V_102 ) {}
static inline void F_34 ( void )
{
F_13 ( V_132 , 0 ) ;
F_13 ( V_133 , 1 ) ;
}
static inline void F_35 ( unsigned V_102 )
{
F_13 ( V_134 , 1 ) ;
F_13 ( V_135 , 0 ) ;
if ( V_102 & V_136 )
F_13 ( V_137 , 0 ) ;
if ( V_102 & V_138 )
F_13 ( V_139 , 0 ) ;
}
static inline void F_36 ( unsigned V_102 )
{
F_13 ( V_140 , 1 ) ;
F_13 ( V_141 , 0 ) ;
if ( V_102 & V_136 )
F_9 ( V_142 , 0 ) ;
if ( V_102 & V_138 )
F_9 ( V_143 , 0 ) ;
}
static inline void F_37 ( unsigned V_102 )
{
F_13 ( V_144 , 0 ) ;
F_13 ( V_145 , 1 ) ;
if ( V_102 & V_136 )
F_9 ( V_146 , 0 ) ;
if ( V_102 & V_138 )
F_9 ( V_147 , 0 ) ;
}
void T_1 F_38 ( unsigned V_123 , unsigned V_148 , unsigned V_102 )
{
struct V_124 * V_125 ;
struct V_149 * V_150 ;
switch ( V_123 ) {
case 0 :
V_125 = & V_151 ;
F_34 () ;
break;
case V_152 :
V_125 = & V_153 ;
F_35 ( V_102 ) ;
break;
case V_154 :
V_125 = & V_155 ;
F_36 ( V_102 ) ;
break;
case V_156 :
V_125 = & V_157 ;
F_37 ( V_102 ) ;
break;
default:
return;
}
V_150 = V_125 -> V_158 . V_159 ;
V_150 -> V_160 = V_148 ;
if ( V_148 < V_161 )
V_162 [ V_148 ] = V_125 ;
}
void T_1 F_39 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_161 ; V_3 ++ ) {
if ( V_162 [ V_3 ] )
F_3 ( V_162 [ V_3 ] ) ;
}
}
void T_1 F_38 ( unsigned V_123 , unsigned V_148 , unsigned V_102 ) {}
void T_1 F_39 ( void ) {}
static int T_1 F_40 ( void )
{
F_28 () ;
F_29 () ;
F_26 () ;
return 0 ;
}
