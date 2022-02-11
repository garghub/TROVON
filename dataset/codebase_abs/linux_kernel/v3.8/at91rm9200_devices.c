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
if ( F_2 ( V_2 -> V_10 ) )
F_7 ( V_2 -> V_10 , 0 ) ;
V_11 = * V_2 ;
F_4 ( & V_12 ) ;
}
void T_1 F_5 ( struct V_8 * V_2 ) {}
void T_1 F_8 ( struct V_13 * V_2 )
{
if ( ! V_2 )
return;
if ( F_2 ( V_2 -> V_14 ) ) {
F_3 ( V_2 -> V_14 , 0 ) ;
F_6 ( V_2 -> V_14 , 1 ) ;
}
F_9 ( V_15 , 0 ) ;
F_9 ( V_16 , 0 ) ;
F_9 ( V_17 , 0 ) ;
F_9 ( V_18 , 0 ) ;
F_9 ( V_19 , 0 ) ;
F_9 ( V_20 , 0 ) ;
F_9 ( V_21 , 0 ) ;
F_9 ( V_22 , 0 ) ;
F_9 ( V_23 , 0 ) ;
F_9 ( V_24 , 0 ) ;
if ( ! V_2 -> V_25 ) {
F_10 ( V_26 , 0 ) ;
F_10 ( V_27 , 0 ) ;
F_10 ( V_28 , 0 ) ;
F_10 ( V_29 , 0 ) ;
F_10 ( V_30 , 0 ) ;
F_10 ( V_31 , 0 ) ;
F_10 ( V_32 , 0 ) ;
F_10 ( V_33 , 0 ) ;
}
V_34 = * V_2 ;
F_4 ( & V_35 ) ;
}
void T_1 F_8 ( struct V_13 * V_2 ) {}
void T_1 F_11 ( struct V_36 * V_2 )
{
unsigned int V_37 ;
if ( ! V_2 )
return;
V_2 -> V_38 = 4 ;
V_37 = F_12 ( 0 , V_39 ) ;
F_13 ( 0 , V_39 , V_37 | V_40 ) ;
F_13 ( 0 , F_14 ( 4 ) ,
V_41
| V_42
| V_43
| V_44
| F_15 ( 32 )
| F_16 ( 6 )
| F_17 ( 4 )
) ;
if ( F_2 ( V_2 -> V_45 ) ) {
F_3 ( V_2 -> V_45 , 1 ) ;
F_6 ( V_2 -> V_45 , 1 ) ;
}
F_3 ( V_2 -> V_46 , 1 ) ;
F_6 ( V_2 -> V_46 , 1 ) ;
if ( F_2 ( V_2 -> V_47 ) )
F_7 ( V_2 -> V_47 , 0 ) ;
F_7 ( V_2 -> V_48 , 0 ) ;
F_9 ( V_49 , 0 ) ;
F_9 ( V_50 , 0 ) ;
F_9 ( V_51 , 0 ) ;
F_9 ( V_52 , 0 ) ;
F_9 ( V_53 , 1 ) ;
V_54 = * V_2 ;
F_4 ( & V_55 ) ;
}
void T_1 F_11 ( struct V_36 * V_2 ) {}
void T_1 F_18 ( short V_56 , struct V_57 * V_2 )
{
unsigned int V_3 ;
unsigned int V_58 = 0 ;
if ( ! V_2 )
return;
for ( V_3 = 0 ; V_3 < V_59 ; V_3 ++ ) {
if ( ! V_2 -> V_60 [ V_3 ] . V_61 )
continue;
if ( F_2 ( V_2 -> V_60 [ V_3 ] . V_62 ) ) {
F_3 ( V_2 -> V_60 [ V_3 ] . V_62 , 1 ) ;
F_6 ( V_2 -> V_60 [ V_3 ] . V_62 , 1 ) ;
}
if ( F_2 ( V_2 -> V_60 [ V_3 ] . V_63 ) )
F_3 ( V_2 -> V_60 [ V_3 ] . V_63 , 1 ) ;
switch ( V_3 ) {
case 0 :
F_9 ( V_64 , 1 ) ;
F_9 ( V_65 , 1 ) ;
if ( V_2 -> V_60 [ V_3 ] . V_61 == 4 ) {
F_10 ( V_66 , 1 ) ;
F_10 ( V_67 , 1 ) ;
F_10 ( V_68 , 1 ) ;
}
V_58 ++ ;
break;
case 1 :
F_10 ( V_23 , 1 ) ;
F_10 ( V_22 , 1 ) ;
if ( V_2 -> V_60 [ V_3 ] . V_61 == 4 ) {
F_10 ( V_21 , 1 ) ;
F_10 ( V_20 , 1 ) ;
F_10 ( V_19 , 1 ) ;
}
V_58 ++ ;
break;
default:
F_19 ( V_69
L_1 , V_3 ) ;
break;
}
if ( V_58 ) {
F_9 ( V_70 , 0 ) ;
V_71 = * V_2 ;
F_4 ( & V_72 ) ;
}
}
}
void T_1 F_18 ( short V_56 , struct V_57 * V_2 ) {}
void T_1 F_20 ( struct V_73 * V_2 )
{
unsigned int V_37 ;
if ( ! V_2 )
return;
V_37 = F_12 ( 0 , V_39 ) ;
F_13 ( 0 , V_39 , V_37 | V_74 ) ;
F_13 ( 0 , F_14 ( 3 ) , V_41 | V_75 | V_44
| F_15 ( 5 )
| F_21 ( 1 )
| F_16 ( 0 )
| F_17 ( 1 )
) ;
if ( F_2 ( V_2 -> V_76 ) )
F_7 ( V_2 -> V_76 , 1 ) ;
if ( F_2 ( V_2 -> V_77 ) )
F_3 ( V_2 -> V_77 , 1 ) ;
if ( F_2 ( V_2 -> V_46 ) )
F_3 ( V_2 -> V_46 , 1 ) ;
F_9 ( V_78 , 0 ) ;
F_9 ( V_79 , 0 ) ;
V_80 = * V_2 ;
F_4 ( & V_81 ) ;
}
void T_1 F_20 ( struct V_73 * V_2 ) {}
void T_1 F_22 ( struct V_82 * V_83 , int V_84 )
{
F_23 ( V_85 , 1 ) ;
F_24 ( V_85 , 1 ) ;
F_23 ( V_86 , 1 ) ;
F_24 ( V_86 , 1 ) ;
F_25 ( 0 , V_83 , V_84 ) ;
F_4 ( & V_87 ) ;
}
void T_1 F_22 ( struct V_82 * V_83 , int V_84 )
{
F_9 ( V_85 , 0 ) ;
F_24 ( V_85 , 1 ) ;
F_9 ( V_86 , 0 ) ;
F_24 ( V_86 , 1 ) ;
F_25 ( 0 , V_83 , V_84 ) ;
F_4 ( & V_87 ) ;
}
void T_1 F_22 ( struct V_82 * V_83 , int V_84 ) {}
void T_1 F_26 ( struct V_88 * V_83 , int V_84 )
{
int V_3 ;
unsigned long V_89 ;
F_9 ( V_90 , 0 ) ;
F_9 ( V_91 , 0 ) ;
F_9 ( V_92 , 0 ) ;
for ( V_3 = 0 ; V_3 < V_84 ; V_3 ++ ) {
if ( V_83 [ V_3 ] . V_93 )
V_89 = ( unsigned long ) V_83 [ V_3 ] . V_93 ;
else
V_89 = V_94 [ V_83 [ V_3 ] . V_95 ] ;
if ( V_83 [ V_3 ] . V_95 == 0 )
F_9 ( V_89 , 0 ) ;
else
F_7 ( V_89 , 1 ) ;
V_83 [ V_3 ] . V_93 = ( void * ) V_89 ;
}
F_27 ( V_83 , V_84 ) ;
F_4 ( & V_96 ) ;
}
void T_1 F_26 ( struct V_88 * V_83 , int V_84 ) {}
static void T_1 F_28 ( void )
{
F_4 ( & V_97 ) ;
F_4 ( & V_98 ) ;
}
static void T_1 F_28 ( void ) { }
static void T_1 F_29 ( void )
{
F_4 ( & V_99 ) ;
}
static void T_1 F_29 ( void ) {}
static void T_1 F_30 ( void )
{
F_4 ( & V_100 ) ;
}
static void T_1 F_30 ( void ) {}
static inline void F_31 ( unsigned V_101 )
{
if ( V_101 & V_102 )
F_9 ( V_103 , 1 ) ;
if ( V_101 & V_104 )
F_9 ( V_105 , 1 ) ;
if ( V_101 & V_106 )
F_9 ( V_107 , 1 ) ;
if ( V_101 & V_108 )
F_9 ( V_66 , 1 ) ;
if ( V_101 & V_109 )
F_9 ( V_67 , 1 ) ;
if ( V_101 & V_110 )
F_9 ( V_68 , 1 ) ;
}
static inline void F_32 ( unsigned V_101 )
{
if ( V_101 & V_102 )
F_9 ( V_111 , 1 ) ;
if ( V_101 & V_104 )
F_9 ( V_112 , 1 ) ;
if ( V_101 & V_106 )
F_9 ( V_113 , 1 ) ;
if ( V_101 & V_108 )
F_9 ( V_114 , 1 ) ;
if ( V_101 & V_109 )
F_9 ( V_115 , 1 ) ;
if ( V_101 & V_110 )
F_9 ( V_116 , 1 ) ;
}
static inline void F_33 ( unsigned V_101 )
{
if ( V_101 & V_102 )
F_9 ( V_33 , 1 ) ;
if ( V_101 & V_104 )
F_9 ( V_32 , 1 ) ;
if ( V_101 & V_106 )
F_9 ( V_31 , 1 ) ;
if ( V_101 & V_108 )
F_9 ( V_30 , 1 ) ;
if ( V_101 & V_109 )
F_9 ( V_29 , 1 ) ;
if ( V_101 & V_110 )
F_9 ( V_28 , 1 ) ;
}
void T_1 F_34 ( unsigned V_117 , unsigned V_101 )
{
struct V_118 * V_119 ;
switch ( V_117 ) {
case V_120 :
V_119 = & V_121 ;
F_31 ( V_101 ) ;
break;
case V_122 :
V_119 = & V_123 ;
F_32 ( V_101 ) ;
break;
case V_124 :
V_119 = & V_125 ;
F_33 ( V_101 ) ;
break;
default:
return;
}
F_4 ( V_119 ) ;
}
void T_1 F_34 ( unsigned V_117 , unsigned V_101 ) {}
static inline void F_35 ( void )
{
F_9 ( V_126 , 0 ) ;
F_9 ( V_127 , 1 ) ;
}
static inline void F_36 ( unsigned V_101 )
{
F_9 ( V_128 , 1 ) ;
F_9 ( V_129 , 0 ) ;
if ( V_101 & V_130 )
F_9 ( V_131 , 0 ) ;
if ( V_101 & V_132 ) {
F_7 ( V_133 , 1 ) ;
}
}
static inline void F_37 ( unsigned V_101 )
{
F_9 ( V_134 , 1 ) ;
F_9 ( V_135 , 0 ) ;
if ( V_101 & V_136 )
F_9 ( V_27 , 0 ) ;
if ( V_101 & V_137 )
F_9 ( V_26 , 0 ) ;
if ( V_101 & V_138 )
F_9 ( V_139 , 0 ) ;
if ( V_101 & V_130 )
F_9 ( V_140 , 0 ) ;
if ( V_101 & V_141 )
F_9 ( V_142 , 0 ) ;
if ( V_101 & V_132 )
F_9 ( V_143 , 0 ) ;
}
static inline void F_38 ( unsigned V_101 )
{
F_9 ( V_144 , 0 ) ;
F_9 ( V_145 , 1 ) ;
if ( V_101 & V_130 )
F_10 ( V_126 , 0 ) ;
if ( V_101 & V_132 )
F_10 ( V_127 , 0 ) ;
}
static inline void F_39 ( unsigned V_101 )
{
F_10 ( V_146 , 1 ) ;
F_10 ( V_147 , 0 ) ;
if ( V_101 & V_130 )
F_10 ( V_105 , 0 ) ;
if ( V_101 & V_132 )
F_10 ( V_103 , 0 ) ;
}
void T_1 F_40 ( unsigned V_117 , unsigned V_148 , unsigned V_101 )
{
struct V_118 * V_119 ;
struct V_149 * V_150 ;
switch ( V_117 ) {
case 0 :
V_119 = & V_151 ;
F_35 () ;
break;
case V_152 :
V_119 = & V_153 ;
F_36 ( V_101 ) ;
break;
case V_154 :
V_119 = & V_155 ;
F_37 ( V_101 ) ;
break;
case V_156 :
V_119 = & V_157 ;
F_38 ( V_101 ) ;
break;
case V_158 :
V_119 = & V_159 ;
F_39 ( V_101 ) ;
break;
default:
return;
}
V_150 = V_119 -> V_160 . V_161 ;
V_150 -> V_162 = V_148 ;
if ( V_148 < V_163 )
V_164 [ V_148 ] = V_119 ;
}
void T_1 F_41 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_163 ; V_3 ++ ) {
if ( V_164 [ V_3 ] )
F_4 ( V_164 [ V_3 ] ) ;
}
}
void T_1 F_40 ( unsigned V_117 , unsigned V_148 , unsigned V_101 ) {}
void T_1 F_41 ( void ) {}
static int T_1 F_42 ( void )
{
F_29 () ;
F_30 () ;
F_28 () ;
return 0 ;
}
