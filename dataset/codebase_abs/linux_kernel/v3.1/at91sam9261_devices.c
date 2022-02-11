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
T_3 V_85 = F_22 ( V_84 ) ;
V_82 = F_23 ( V_84 -> V_86 , V_85 ) ;
if ( V_82 ) {
memset ( V_82 , 0 , V_85 ) ;
F_24 ( V_82 ) ;
}
}
V_87 = * V_2 ;
F_2 ( & V_88 ) ;
}
void T_1 F_19 ( struct V_54 * V_2 ) {}
static void T_1 F_25 ( void )
{
F_2 ( & V_89 ) ;
}
static void T_1 F_25 ( void ) { }
static void T_1 F_26 ( void )
{
F_2 ( & V_90 ) ;
}
static void T_1 F_27 ( void )
{
F_2 ( & V_91 ) ;
}
static void T_1 F_27 ( void ) {}
static inline void F_28 ( unsigned V_92 )
{
if ( V_92 & V_93 )
F_12 ( V_94 , 1 ) ;
if ( V_92 & V_95 )
F_12 ( V_96 , 1 ) ;
if ( V_92 & V_97 )
F_12 ( V_75 , 1 ) ;
if ( V_92 & V_98 )
F_12 ( V_76 , 1 ) ;
if ( V_92 & V_99 )
F_12 ( V_77 , 1 ) ;
if ( V_92 & V_100 )
F_12 ( V_78 , 1 ) ;
}
static inline void F_29 ( unsigned V_92 )
{
if ( V_92 & V_93 )
F_8 ( V_101 , 1 ) ;
if ( V_92 & V_95 )
F_8 ( V_102 , 1 ) ;
if ( V_92 & V_97 )
F_8 ( V_103 , 1 ) ;
if ( V_92 & V_98 )
F_8 ( V_104 , 1 ) ;
if ( V_92 & V_99 )
F_8 ( V_105 , 1 ) ;
if ( V_92 & V_100 )
F_8 ( V_106 , 1 ) ;
}
static inline void F_30 ( unsigned V_92 )
{
if ( V_92 & V_93 )
F_8 ( V_107 , 1 ) ;
if ( V_92 & V_95 )
F_8 ( V_108 , 1 ) ;
if ( V_92 & V_97 )
F_8 ( V_109 , 1 ) ;
if ( V_92 & V_98 )
F_8 ( V_110 , 1 ) ;
if ( V_92 & V_99 )
F_8 ( V_111 , 1 ) ;
if ( V_92 & V_100 )
F_8 ( V_112 , 1 ) ;
}
void T_1 F_31 ( unsigned V_113 , unsigned V_92 )
{
struct V_114 * V_115 ;
switch ( V_113 ) {
case V_116 :
V_115 = & V_117 ;
F_28 ( V_92 ) ;
break;
case V_118 :
V_115 = & V_119 ;
F_29 ( V_92 ) ;
break;
case V_120 :
V_115 = & V_121 ;
F_30 ( V_92 ) ;
break;
default:
return;
}
F_2 ( V_115 ) ;
}
void T_1 F_31 ( unsigned V_113 , unsigned V_92 ) {}
static inline void F_32 ( void )
{
F_12 ( V_122 , 0 ) ;
F_12 ( V_123 , 1 ) ;
}
static inline void F_33 ( unsigned V_92 )
{
F_12 ( V_124 , 1 ) ;
F_12 ( V_125 , 0 ) ;
if ( V_92 & V_126 )
F_12 ( V_127 , 0 ) ;
if ( V_92 & V_128 )
F_12 ( V_129 , 0 ) ;
}
static inline void F_34 ( unsigned V_92 )
{
F_12 ( V_130 , 1 ) ;
F_12 ( V_131 , 0 ) ;
if ( V_92 & V_126 )
F_8 ( V_132 , 0 ) ;
if ( V_92 & V_128 )
F_8 ( V_133 , 0 ) ;
}
static inline void F_35 ( unsigned V_92 )
{
F_12 ( V_134 , 0 ) ;
F_12 ( V_135 , 1 ) ;
if ( V_92 & V_126 )
F_8 ( V_136 , 0 ) ;
if ( V_92 & V_128 )
F_8 ( V_137 , 0 ) ;
}
void T_1 F_36 ( unsigned V_113 , unsigned V_138 , unsigned V_92 )
{
struct V_114 * V_115 ;
struct V_139 * V_140 ;
switch ( V_113 ) {
case 0 :
V_115 = & V_141 ;
F_32 () ;
break;
case V_142 :
V_115 = & V_143 ;
F_33 ( V_92 ) ;
break;
case V_144 :
V_115 = & V_145 ;
F_34 ( V_92 ) ;
break;
case V_146 :
V_115 = & V_147 ;
F_35 ( V_92 ) ;
break;
default:
return;
}
V_140 = V_115 -> V_148 . V_149 ;
V_140 -> V_150 = V_138 ;
if ( V_138 < V_151 )
V_152 [ V_138 ] = V_115 ;
}
void T_1 F_37 ( unsigned V_138 )
{
if ( V_138 < V_151 ) {
V_153 = V_152 [ V_138 ] ;
F_38 ( V_152 [ V_138 ] -> V_113 ) ;
}
}
void T_1 F_39 ( void )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_151 ; V_40 ++ ) {
if ( V_152 [ V_40 ] )
F_2 ( V_152 [ V_40 ] ) ;
}
if ( ! V_153 )
F_40 ( V_154 L_1 ) ;
}
void T_1 F_36 ( unsigned V_113 , unsigned V_138 , unsigned V_92 ) {}
void T_1 F_37 ( unsigned V_138 ) {}
void T_1 F_39 ( void ) {}
static int T_1 F_41 ( void )
{
F_26 () ;
F_27 () ;
F_25 () ;
return 0 ;
}
