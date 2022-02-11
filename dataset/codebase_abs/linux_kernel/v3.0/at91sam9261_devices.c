void T_1 F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
V_3 = * V_2 ;
F_2 ( & V_4 ) ;
}
void T_1 F_1 ( struct V_1 * V_2 ) {}
void T_1 F_3 ( struct V_5 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_6 ) {
F_4 ( V_2 -> V_6 , 0 ) ;
F_5 ( V_2 -> V_6 , 1 ) ;
}
V_7 = * V_2 ;
F_2 ( & V_8 ) ;
}
void T_1 F_3 ( struct V_5 * V_2 ) {}
void T_1 F_6 ( short V_9 , struct V_10 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_11 ) {
F_4 ( V_2 -> V_11 , 1 ) ;
F_5 ( V_2 -> V_11 , 1 ) ;
}
if ( V_2 -> V_12 )
F_4 ( V_2 -> V_12 , 1 ) ;
if ( V_2 -> V_13 )
F_7 ( V_2 -> V_13 , 0 ) ;
F_8 ( V_14 , 0 ) ;
F_8 ( V_15 , 1 ) ;
F_8 ( V_16 , 1 ) ;
if ( V_2 -> V_17 ) {
F_8 ( V_18 , 1 ) ;
F_8 ( V_19 , 1 ) ;
F_8 ( V_20 , 1 ) ;
}
V_21 = * V_2 ;
F_2 ( & V_22 ) ;
}
void T_1 F_6 ( short V_9 , struct V_10 * V_2 ) {}
void T_1 F_9 ( struct V_23 * V_2 )
{
unsigned long V_24 ;
if ( ! V_2 )
return;
V_24 = F_10 ( V_25 ) ;
F_11 ( V_25 , V_24 | V_26 ) ;
if ( V_2 -> V_27 )
F_7 ( V_2 -> V_27 , 1 ) ;
if ( V_2 -> V_28 )
F_4 ( V_2 -> V_28 , 1 ) ;
if ( V_2 -> V_11 )
F_4 ( V_2 -> V_11 , 1 ) ;
F_12 ( V_29 , 0 ) ;
F_12 ( V_30 , 0 ) ;
V_31 = * V_2 ;
F_2 ( & V_32 ) ;
}
void T_1 F_9 ( struct V_23 * V_2 ) {}
void T_1 F_13 ( struct V_33 * V_34 , int V_35 )
{
F_14 ( V_36 , 1 ) ;
F_15 ( V_36 , 1 ) ;
F_14 ( V_37 , 1 ) ;
F_15 ( V_37 , 1 ) ;
F_16 ( 0 , V_34 , V_35 ) ;
F_2 ( & V_38 ) ;
}
void T_1 F_13 ( struct V_33 * V_34 , int V_35 )
{
F_12 ( V_36 , 0 ) ;
F_15 ( V_36 , 1 ) ;
F_12 ( V_37 , 0 ) ;
F_15 ( V_37 , 1 ) ;
F_16 ( 0 , V_34 , V_35 ) ;
F_2 ( & V_38 ) ;
}
void T_1 F_13 ( struct V_33 * V_34 , int V_35 ) {}
void T_1 F_17 ( struct V_39 * V_34 , int V_35 )
{
int V_40 ;
unsigned long V_41 ;
short V_42 = 0 ;
short V_43 = 0 ;
for ( V_40 = 0 ; V_40 < V_35 ; V_40 ++ ) {
if ( V_34 [ V_40 ] . V_44 )
V_41 = ( unsigned long ) V_34 [ V_40 ] . V_44 ;
else if ( V_34 [ V_40 ] . V_45 == 0 )
V_41 = V_46 [ V_34 [ V_40 ] . V_47 ] ;
else
V_41 = V_48 [ V_34 [ V_40 ] . V_47 ] ;
if ( V_34 [ V_40 ] . V_45 == 0 )
V_42 = 1 ;
else
V_43 = 1 ;
F_7 ( V_41 , 1 ) ;
V_34 [ V_40 ] . V_44 = ( void * ) V_41 ;
}
F_18 ( V_34 , V_35 ) ;
if ( V_42 ) {
F_12 ( V_16 , 0 ) ;
F_12 ( V_15 , 0 ) ;
F_12 ( V_14 , 0 ) ;
F_2 ( & V_49 ) ;
}
if ( V_43 ) {
F_12 ( V_50 , 0 ) ;
F_12 ( V_51 , 0 ) ;
F_12 ( V_52 , 0 ) ;
F_2 ( & V_53 ) ;
}
}
void T_1 F_17 ( struct V_39 * V_34 , int V_35 ) {}
void T_1 F_19 ( struct V_54 * V_2 )
{
if ( ! V_2 ) {
return;
}
#if F_20 ( V_55 )
F_12 ( V_56 , 0 ) ;
F_12 ( V_57 , 0 ) ;
F_12 ( V_58 , 0 ) ;
F_12 ( V_59 , 0 ) ;
F_12 ( V_60 , 0 ) ;
F_12 ( V_61 , 0 ) ;
F_12 ( V_62 , 0 ) ;
F_12 ( V_63 , 0 ) ;
F_12 ( V_64 , 0 ) ;
#else
F_12 ( V_57 , 0 ) ;
F_12 ( V_58 , 0 ) ;
F_12 ( V_59 , 0 ) ;
F_12 ( V_60 , 0 ) ;
F_12 ( V_63 , 0 ) ;
F_12 ( V_64 , 0 ) ;
F_12 ( V_65 , 0 ) ;
F_12 ( V_66 , 0 ) ;
F_12 ( V_67 , 0 ) ;
F_12 ( V_68 , 0 ) ;
F_12 ( V_69 , 0 ) ;
F_12 ( V_70 , 0 ) ;
F_12 ( V_71 , 0 ) ;
F_12 ( V_72 , 0 ) ;
F_12 ( V_73 , 0 ) ;
F_12 ( V_74 , 0 ) ;
F_8 ( V_75 , 0 ) ;
F_8 ( V_76 , 0 ) ;
F_8 ( V_77 , 0 ) ;
F_8 ( V_78 , 0 ) ;
F_8 ( V_79 , 0 ) ;
F_8 ( V_80 , 0 ) ;
#endif
if ( F_21 ( V_81 ) > 2 ) {
void T_2 * V_82 ;
struct V_83 * V_84 = & V_81 [ 2 ] ;
T_3 V_85 = V_84 -> V_86 - V_84 -> V_87 + 1 ;
V_82 = F_22 ( V_84 -> V_87 , V_85 ) ;
if ( V_82 ) {
memset ( V_82 , 0 , V_85 ) ;
F_23 ( V_82 ) ;
}
}
V_88 = * V_2 ;
F_2 ( & V_89 ) ;
}
void T_1 F_19 ( struct V_54 * V_2 ) {}
static void T_1 F_24 ( void )
{
F_2 ( & V_90 ) ;
}
static void T_1 F_24 ( void ) { }
static void T_1 F_25 ( void )
{
F_2 ( & V_91 ) ;
}
static void T_1 F_26 ( void )
{
F_2 ( & V_92 ) ;
}
static void T_1 F_26 ( void ) {}
static inline void F_27 ( unsigned V_93 )
{
if ( V_93 & V_94 )
F_12 ( V_95 , 1 ) ;
if ( V_93 & V_96 )
F_12 ( V_97 , 1 ) ;
if ( V_93 & V_98 )
F_12 ( V_75 , 1 ) ;
if ( V_93 & V_99 )
F_12 ( V_76 , 1 ) ;
if ( V_93 & V_100 )
F_12 ( V_77 , 1 ) ;
if ( V_93 & V_101 )
F_12 ( V_78 , 1 ) ;
}
static inline void F_28 ( unsigned V_93 )
{
if ( V_93 & V_94 )
F_8 ( V_102 , 1 ) ;
if ( V_93 & V_96 )
F_8 ( V_103 , 1 ) ;
if ( V_93 & V_98 )
F_8 ( V_104 , 1 ) ;
if ( V_93 & V_99 )
F_8 ( V_105 , 1 ) ;
if ( V_93 & V_100 )
F_8 ( V_106 , 1 ) ;
if ( V_93 & V_101 )
F_8 ( V_107 , 1 ) ;
}
static inline void F_29 ( unsigned V_93 )
{
if ( V_93 & V_94 )
F_8 ( V_108 , 1 ) ;
if ( V_93 & V_96 )
F_8 ( V_109 , 1 ) ;
if ( V_93 & V_98 )
F_8 ( V_110 , 1 ) ;
if ( V_93 & V_99 )
F_8 ( V_111 , 1 ) ;
if ( V_93 & V_100 )
F_8 ( V_112 , 1 ) ;
if ( V_93 & V_101 )
F_8 ( V_113 , 1 ) ;
}
void T_1 F_30 ( unsigned V_114 , unsigned V_93 )
{
struct V_115 * V_116 ;
switch ( V_114 ) {
case V_117 :
V_116 = & V_118 ;
F_27 ( V_93 ) ;
break;
case V_119 :
V_116 = & V_120 ;
F_28 ( V_93 ) ;
break;
case V_121 :
V_116 = & V_122 ;
F_29 ( V_93 ) ;
break;
default:
return;
}
F_2 ( V_116 ) ;
}
void T_1 F_30 ( unsigned V_114 , unsigned V_93 ) {}
static inline void F_31 ( void )
{
F_12 ( V_123 , 0 ) ;
F_12 ( V_124 , 1 ) ;
}
static inline void F_32 ( unsigned V_93 )
{
F_12 ( V_125 , 1 ) ;
F_12 ( V_126 , 0 ) ;
if ( V_93 & V_127 )
F_12 ( V_128 , 0 ) ;
if ( V_93 & V_129 )
F_12 ( V_130 , 0 ) ;
}
static inline void F_33 ( unsigned V_93 )
{
F_12 ( V_131 , 1 ) ;
F_12 ( V_132 , 0 ) ;
if ( V_93 & V_127 )
F_8 ( V_133 , 0 ) ;
if ( V_93 & V_129 )
F_8 ( V_134 , 0 ) ;
}
static inline void F_34 ( unsigned V_93 )
{
F_12 ( V_135 , 0 ) ;
F_12 ( V_136 , 1 ) ;
if ( V_93 & V_127 )
F_8 ( V_137 , 0 ) ;
if ( V_93 & V_129 )
F_8 ( V_138 , 0 ) ;
}
void T_1 F_35 ( unsigned V_114 , unsigned V_139 , unsigned V_93 )
{
struct V_115 * V_116 ;
struct V_140 * V_141 ;
switch ( V_114 ) {
case 0 :
V_116 = & V_142 ;
F_31 () ;
break;
case V_143 :
V_116 = & V_144 ;
F_32 ( V_93 ) ;
break;
case V_145 :
V_116 = & V_146 ;
F_33 ( V_93 ) ;
break;
case V_147 :
V_116 = & V_148 ;
F_34 ( V_93 ) ;
break;
default:
return;
}
V_141 = V_116 -> V_149 . V_150 ;
V_141 -> V_151 = V_139 ;
if ( V_139 < V_152 )
V_153 [ V_139 ] = V_116 ;
}
void T_1 F_36 ( unsigned V_139 )
{
if ( V_139 < V_152 ) {
V_154 = V_153 [ V_139 ] ;
F_37 ( V_153 [ V_139 ] -> V_114 ) ;
}
}
void T_1 F_38 ( void )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_152 ; V_40 ++ ) {
if ( V_153 [ V_40 ] )
F_2 ( V_153 [ V_40 ] ) ;
}
if ( ! V_154 )
F_39 ( V_155 L_1 ) ;
}
void T_1 F_35 ( unsigned V_114 , unsigned V_139 , unsigned V_93 ) {}
void T_1 F_36 ( unsigned V_139 ) {}
void T_1 F_38 ( void ) {}
static int T_1 F_40 ( void )
{
F_25 () ;
F_26 () ;
F_24 () ;
return 0 ;
}
