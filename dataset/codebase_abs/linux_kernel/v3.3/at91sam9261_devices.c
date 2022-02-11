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
F_3 ( & V_92 ) ;
}
static void T_1 F_28 ( void )
{
F_3 ( & V_93 ) ;
}
static void T_1 F_28 ( void ) {}
static inline void F_29 ( unsigned V_94 )
{
if ( V_94 & V_95 )
F_13 ( V_96 , 1 ) ;
if ( V_94 & V_97 )
F_13 ( V_98 , 1 ) ;
if ( V_94 & V_99 )
F_13 ( V_77 , 1 ) ;
if ( V_94 & V_100 )
F_13 ( V_78 , 1 ) ;
if ( V_94 & V_101 )
F_13 ( V_79 , 1 ) ;
if ( V_94 & V_102 )
F_13 ( V_80 , 1 ) ;
}
static inline void F_30 ( unsigned V_94 )
{
if ( V_94 & V_95 )
F_9 ( V_103 , 1 ) ;
if ( V_94 & V_97 )
F_9 ( V_104 , 1 ) ;
if ( V_94 & V_99 )
F_9 ( V_105 , 1 ) ;
if ( V_94 & V_100 )
F_9 ( V_106 , 1 ) ;
if ( V_94 & V_101 )
F_9 ( V_107 , 1 ) ;
if ( V_94 & V_102 )
F_9 ( V_108 , 1 ) ;
}
static inline void F_31 ( unsigned V_94 )
{
if ( V_94 & V_95 )
F_9 ( V_109 , 1 ) ;
if ( V_94 & V_97 )
F_9 ( V_110 , 1 ) ;
if ( V_94 & V_99 )
F_9 ( V_111 , 1 ) ;
if ( V_94 & V_100 )
F_9 ( V_112 , 1 ) ;
if ( V_94 & V_101 )
F_9 ( V_113 , 1 ) ;
if ( V_94 & V_102 )
F_9 ( V_114 , 1 ) ;
}
void T_1 F_32 ( unsigned V_115 , unsigned V_94 )
{
struct V_116 * V_117 ;
switch ( V_115 ) {
case V_118 :
V_117 = & V_119 ;
F_29 ( V_94 ) ;
break;
case V_120 :
V_117 = & V_121 ;
F_30 ( V_94 ) ;
break;
case V_122 :
V_117 = & V_123 ;
F_31 ( V_94 ) ;
break;
default:
return;
}
F_3 ( V_117 ) ;
}
void T_1 F_32 ( unsigned V_115 , unsigned V_94 ) {}
static inline void F_33 ( void )
{
F_13 ( V_124 , 0 ) ;
F_13 ( V_125 , 1 ) ;
}
static inline void F_34 ( unsigned V_94 )
{
F_13 ( V_126 , 1 ) ;
F_13 ( V_127 , 0 ) ;
if ( V_94 & V_128 )
F_13 ( V_129 , 0 ) ;
if ( V_94 & V_130 )
F_13 ( V_131 , 0 ) ;
}
static inline void F_35 ( unsigned V_94 )
{
F_13 ( V_132 , 1 ) ;
F_13 ( V_133 , 0 ) ;
if ( V_94 & V_128 )
F_9 ( V_134 , 0 ) ;
if ( V_94 & V_130 )
F_9 ( V_135 , 0 ) ;
}
static inline void F_36 ( unsigned V_94 )
{
F_13 ( V_136 , 0 ) ;
F_13 ( V_137 , 1 ) ;
if ( V_94 & V_128 )
F_9 ( V_138 , 0 ) ;
if ( V_94 & V_130 )
F_9 ( V_139 , 0 ) ;
}
void T_1 F_37 ( unsigned V_115 , unsigned V_140 , unsigned V_94 )
{
struct V_116 * V_117 ;
struct V_141 * V_142 ;
switch ( V_115 ) {
case 0 :
V_117 = & V_143 ;
F_33 () ;
break;
case V_144 :
V_117 = & V_145 ;
F_34 ( V_94 ) ;
break;
case V_146 :
V_117 = & V_147 ;
F_35 ( V_94 ) ;
break;
case V_148 :
V_117 = & V_149 ;
F_36 ( V_94 ) ;
break;
default:
return;
}
V_142 = V_117 -> V_150 . V_151 ;
V_142 -> V_152 = V_140 ;
if ( V_140 < V_153 )
V_154 [ V_140 ] = V_117 ;
}
void T_1 F_38 ( unsigned V_140 )
{
if ( V_140 < V_153 ) {
V_155 = V_154 [ V_140 ] ;
F_39 ( V_154 [ V_140 ] -> V_115 ) ;
}
}
void T_1 F_40 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_153 ; V_3 ++ ) {
if ( V_154 [ V_3 ] )
F_3 ( V_154 [ V_3 ] ) ;
}
if ( ! V_155 )
F_41 ( V_156 L_1 ) ;
}
void T_1 F_37 ( unsigned V_115 , unsigned V_140 , unsigned V_94 ) {}
void T_1 F_38 ( unsigned V_140 ) {}
void T_1 F_40 ( void ) {}
static int T_1 F_42 ( void )
{
F_27 () ;
F_28 () ;
F_26 () ;
return 0 ;
}
