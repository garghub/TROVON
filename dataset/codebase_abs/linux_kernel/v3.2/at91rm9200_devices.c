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
if ( V_2 -> V_9 ) {
F_2 ( V_2 -> V_9 , 0 ) ;
F_5 ( V_2 -> V_9 , 1 ) ;
}
if ( V_2 -> V_10 )
F_6 ( V_2 -> V_10 , 0 ) ;
V_11 = * V_2 ;
F_3 ( & V_12 ) ;
}
void T_1 F_4 ( struct V_8 * V_2 ) {}
void T_1 F_7 ( struct V_13 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_14 ) {
F_2 ( V_2 -> V_14 , 0 ) ;
F_5 ( V_2 -> V_14 , 1 ) ;
}
F_8 ( V_15 , 0 ) ;
F_8 ( V_16 , 0 ) ;
F_8 ( V_17 , 0 ) ;
F_8 ( V_18 , 0 ) ;
F_8 ( V_19 , 0 ) ;
F_8 ( V_20 , 0 ) ;
F_8 ( V_21 , 0 ) ;
F_8 ( V_22 , 0 ) ;
F_8 ( V_23 , 0 ) ;
F_8 ( V_24 , 0 ) ;
if ( ! V_2 -> V_25 ) {
F_9 ( V_26 , 0 ) ;
F_9 ( V_27 , 0 ) ;
F_9 ( V_28 , 0 ) ;
F_9 ( V_29 , 0 ) ;
F_9 ( V_30 , 0 ) ;
F_9 ( V_31 , 0 ) ;
F_9 ( V_32 , 0 ) ;
F_9 ( V_33 , 0 ) ;
}
V_34 = * V_2 ;
F_3 ( & V_35 ) ;
}
void T_1 F_7 ( struct V_13 * V_2 ) {}
void T_1 F_10 ( struct V_36 * V_2 )
{
unsigned int V_37 ;
if ( ! V_2 )
return;
V_2 -> V_38 = 4 ;
V_37 = F_11 ( V_39 ) ;
F_12 ( V_39 , V_37 | V_40 ) ;
F_12 ( F_13 ( 4 ) ,
V_41
| V_42
| V_43
| V_44
| F_14 ( 32 )
| F_15 ( 6 )
| F_16 ( 4 )
) ;
if ( V_2 -> V_45 ) {
F_2 ( V_2 -> V_45 , 1 ) ;
F_5 ( V_2 -> V_45 , 1 ) ;
}
F_2 ( V_2 -> V_46 , 1 ) ;
F_5 ( V_2 -> V_46 , 1 ) ;
if ( V_2 -> V_47 )
F_6 ( V_2 -> V_47 , 0 ) ;
F_6 ( V_2 -> V_48 , 0 ) ;
F_8 ( V_49 , 0 ) ;
F_8 ( V_50 , 0 ) ;
F_8 ( V_51 , 0 ) ;
F_8 ( V_52 , 0 ) ;
F_8 ( V_53 , 1 ) ;
V_54 = * V_2 ;
F_3 ( & V_55 ) ;
}
void T_1 F_10 ( struct V_36 * V_2 ) {}
void T_1 F_17 ( short V_56 , struct V_57 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_46 ) {
F_2 ( V_2 -> V_46 , 1 ) ;
F_5 ( V_2 -> V_46 , 1 ) ;
}
if ( V_2 -> V_58 )
F_2 ( V_2 -> V_58 , 1 ) ;
if ( V_2 -> V_47 )
F_6 ( V_2 -> V_47 , 0 ) ;
F_8 ( V_59 , 0 ) ;
if ( V_2 -> V_60 ) {
F_9 ( V_23 , 1 ) ;
F_9 ( V_22 , 1 ) ;
if ( V_2 -> V_61 ) {
F_9 ( V_21 , 1 ) ;
F_9 ( V_20 , 1 ) ;
F_9 ( V_19 , 1 ) ;
}
} else {
F_8 ( V_62 , 1 ) ;
F_8 ( V_63 , 1 ) ;
if ( V_2 -> V_61 ) {
F_9 ( V_64 , 1 ) ;
F_9 ( V_65 , 1 ) ;
F_9 ( V_66 , 1 ) ;
}
}
V_67 = * V_2 ;
F_3 ( & V_68 ) ;
}
void T_1 F_17 ( short V_56 , struct V_57 * V_2 ) {}
void T_1 F_18 ( struct V_69 * V_2 )
{
unsigned int V_37 ;
if ( ! V_2 )
return;
V_37 = F_11 ( V_39 ) ;
F_12 ( V_39 , V_37 | V_70 ) ;
F_12 ( F_13 ( 3 ) , V_41 | V_71 | V_44
| F_14 ( 5 )
| F_19 ( 1 )
| F_15 ( 0 )
| F_16 ( 1 )
) ;
if ( V_2 -> V_72 )
F_6 ( V_2 -> V_72 , 1 ) ;
if ( V_2 -> V_73 )
F_2 ( V_2 -> V_73 , 1 ) ;
if ( V_2 -> V_46 )
F_2 ( V_2 -> V_46 , 1 ) ;
F_8 ( V_74 , 0 ) ;
F_8 ( V_75 , 0 ) ;
V_76 = * V_2 ;
F_3 ( & V_77 ) ;
}
void T_1 F_18 ( struct V_69 * V_2 ) {}
void T_1 F_20 ( struct V_78 * V_79 , int V_80 )
{
F_21 ( V_81 , 1 ) ;
F_22 ( V_81 , 1 ) ;
F_21 ( V_82 , 1 ) ;
F_22 ( V_82 , 1 ) ;
F_23 ( 0 , V_79 , V_80 ) ;
F_3 ( & V_83 ) ;
}
void T_1 F_20 ( struct V_78 * V_79 , int V_80 )
{
F_8 ( V_81 , 0 ) ;
F_22 ( V_81 , 1 ) ;
F_8 ( V_82 , 0 ) ;
F_22 ( V_82 , 1 ) ;
F_23 ( 0 , V_79 , V_80 ) ;
F_3 ( & V_83 ) ;
}
void T_1 F_20 ( struct V_78 * V_79 , int V_80 ) {}
void T_1 F_24 ( struct V_84 * V_79 , int V_80 )
{
int V_3 ;
unsigned long V_85 ;
F_8 ( V_86 , 0 ) ;
F_8 ( V_87 , 0 ) ;
F_8 ( V_88 , 0 ) ;
for ( V_3 = 0 ; V_3 < V_80 ; V_3 ++ ) {
if ( V_79 [ V_3 ] . V_89 )
V_85 = ( unsigned long ) V_79 [ V_3 ] . V_89 ;
else
V_85 = V_90 [ V_79 [ V_3 ] . V_91 ] ;
if ( V_79 [ V_3 ] . V_91 == 0 )
F_8 ( V_85 , 0 ) ;
else
F_6 ( V_85 , 1 ) ;
V_79 [ V_3 ] . V_89 = ( void * ) V_85 ;
}
F_25 ( V_79 , V_80 ) ;
F_3 ( & V_92 ) ;
}
void T_1 F_24 ( struct V_84 * V_79 , int V_80 ) {}
static void T_1 F_26 ( void )
{
F_3 ( & V_93 ) ;
F_3 ( & V_94 ) ;
}
static void T_1 F_26 ( void ) { }
static void T_1 F_27 ( void )
{
F_3 ( & V_95 ) ;
}
static void T_1 F_27 ( void ) {}
static void T_1 F_28 ( void )
{
F_3 ( & V_96 ) ;
}
static void T_1 F_28 ( void ) {}
static inline void F_29 ( unsigned V_97 )
{
if ( V_97 & V_98 )
F_8 ( V_99 , 1 ) ;
if ( V_97 & V_100 )
F_8 ( V_101 , 1 ) ;
if ( V_97 & V_102 )
F_8 ( V_103 , 1 ) ;
if ( V_97 & V_104 )
F_8 ( V_64 , 1 ) ;
if ( V_97 & V_105 )
F_8 ( V_65 , 1 ) ;
if ( V_97 & V_106 )
F_8 ( V_66 , 1 ) ;
}
static inline void F_30 ( unsigned V_97 )
{
if ( V_97 & V_98 )
F_8 ( V_107 , 1 ) ;
if ( V_97 & V_100 )
F_8 ( V_108 , 1 ) ;
if ( V_97 & V_102 )
F_8 ( V_109 , 1 ) ;
if ( V_97 & V_104 )
F_8 ( V_110 , 1 ) ;
if ( V_97 & V_105 )
F_8 ( V_111 , 1 ) ;
if ( V_97 & V_106 )
F_8 ( V_112 , 1 ) ;
}
static inline void F_31 ( unsigned V_97 )
{
if ( V_97 & V_98 )
F_8 ( V_33 , 1 ) ;
if ( V_97 & V_100 )
F_8 ( V_32 , 1 ) ;
if ( V_97 & V_102 )
F_8 ( V_31 , 1 ) ;
if ( V_97 & V_104 )
F_8 ( V_30 , 1 ) ;
if ( V_97 & V_105 )
F_8 ( V_29 , 1 ) ;
if ( V_97 & V_106 )
F_8 ( V_28 , 1 ) ;
}
void T_1 F_32 ( unsigned V_113 , unsigned V_97 )
{
struct V_114 * V_115 ;
switch ( V_113 ) {
case V_116 :
V_115 = & V_117 ;
F_29 ( V_97 ) ;
break;
case V_118 :
V_115 = & V_119 ;
F_30 ( V_97 ) ;
break;
case V_120 :
V_115 = & V_121 ;
F_31 ( V_97 ) ;
break;
default:
return;
}
F_3 ( V_115 ) ;
}
void T_1 F_32 ( unsigned V_113 , unsigned V_97 ) {}
static inline void F_33 ( void )
{
F_8 ( V_122 , 0 ) ;
F_8 ( V_123 , 1 ) ;
}
static inline void F_34 ( unsigned V_97 )
{
F_8 ( V_124 , 1 ) ;
F_8 ( V_125 , 0 ) ;
if ( V_97 & V_126 )
F_8 ( V_127 , 0 ) ;
if ( V_97 & V_128 ) {
F_6 ( V_129 , 1 ) ;
}
}
static inline void F_35 ( unsigned V_97 )
{
F_8 ( V_130 , 1 ) ;
F_8 ( V_131 , 0 ) ;
if ( V_97 & V_132 )
F_8 ( V_27 , 0 ) ;
if ( V_97 & V_133 )
F_8 ( V_26 , 0 ) ;
if ( V_97 & V_134 )
F_8 ( V_135 , 0 ) ;
if ( V_97 & V_126 )
F_8 ( V_136 , 0 ) ;
if ( V_97 & V_137 )
F_8 ( V_138 , 0 ) ;
if ( V_97 & V_128 )
F_8 ( V_139 , 0 ) ;
}
static inline void F_36 ( unsigned V_97 )
{
F_8 ( V_140 , 0 ) ;
F_8 ( V_141 , 1 ) ;
if ( V_97 & V_126 )
F_9 ( V_122 , 0 ) ;
if ( V_97 & V_128 )
F_9 ( V_123 , 0 ) ;
}
static inline void F_37 ( unsigned V_97 )
{
F_9 ( V_142 , 1 ) ;
F_9 ( V_143 , 0 ) ;
if ( V_97 & V_126 )
F_9 ( V_101 , 0 ) ;
if ( V_97 & V_128 )
F_9 ( V_99 , 0 ) ;
}
void T_1 F_38 ( unsigned V_113 , unsigned V_144 , unsigned V_97 )
{
struct V_114 * V_115 ;
struct V_145 * V_146 ;
switch ( V_113 ) {
case 0 :
V_115 = & V_147 ;
F_33 () ;
break;
case V_148 :
V_115 = & V_149 ;
F_34 ( V_97 ) ;
break;
case V_150 :
V_115 = & V_151 ;
F_35 ( V_97 ) ;
break;
case V_152 :
V_115 = & V_153 ;
F_36 ( V_97 ) ;
break;
case V_154 :
V_115 = & V_155 ;
F_37 ( V_97 ) ;
break;
default:
return;
}
V_146 = V_115 -> V_156 . V_157 ;
V_146 -> V_158 = V_144 ;
if ( V_144 < V_159 )
V_160 [ V_144 ] = V_115 ;
}
void T_1 F_39 ( unsigned V_144 )
{
if ( V_144 < V_159 ) {
V_161 = V_160 [ V_144 ] ;
F_40 ( V_160 [ V_144 ] -> V_113 ) ;
}
}
void T_1 F_41 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_159 ; V_3 ++ ) {
if ( V_160 [ V_3 ] )
F_3 ( V_160 [ V_3 ] ) ;
}
if ( ! V_161 )
F_42 ( V_162 L_1 ) ;
}
void T_1 T_2 F_43 ( struct V_163 * V_164 ) {}
void T_1 F_38 ( unsigned V_113 , unsigned V_144 , unsigned V_97 ) {}
void T_1 F_39 ( unsigned V_144 ) {}
void T_1 F_41 ( void ) {}
static int T_1 F_44 ( void )
{
F_27 () ;
F_28 () ;
F_26 () ;
return 0 ;
}
