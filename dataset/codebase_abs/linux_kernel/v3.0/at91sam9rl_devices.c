void T_1 F_1 ( void )
{
F_2 ( V_1 , V_2 . V_3 ) ;
F_3 ( & V_4 ) ;
}
void T_1 F_1 ( void ) {}
void T_1 F_4 ( struct V_5 * V_6 )
{
V_7 . V_8 . V_9 = - V_10 ;
V_7 . V_8 . V_11 = F_5 ( V_12 ) ;
memcpy ( V_7 . V_13 , V_12 , sizeof( V_12 ) ) ;
if ( V_6 && V_6 -> V_9 > 0 ) {
F_6 ( V_6 -> V_9 , 0 ) ;
F_7 ( V_6 -> V_9 , 1 ) ;
V_7 . V_8 . V_9 = V_6 -> V_9 ;
}
F_3 ( & V_14 ) ;
}
void T_1 F_4 ( struct V_5 * V_6 ) {}
void T_1 F_8 ( short V_15 , struct V_16 * V_6 )
{
if ( ! V_6 )
return;
if ( V_6 -> V_17 ) {
F_6 ( V_6 -> V_17 , 1 ) ;
F_7 ( V_6 -> V_17 , 1 ) ;
}
if ( V_6 -> V_18 )
F_6 ( V_6 -> V_18 , 1 ) ;
if ( V_6 -> V_19 )
F_9 ( V_6 -> V_19 , 0 ) ;
F_10 ( V_20 , 0 ) ;
F_10 ( V_21 , 1 ) ;
F_10 ( V_22 , 1 ) ;
if ( V_6 -> V_23 ) {
F_10 ( V_24 , 1 ) ;
F_10 ( V_25 , 1 ) ;
F_10 ( V_26 , 1 ) ;
}
V_27 = * V_6 ;
F_3 ( & V_28 ) ;
}
void T_1 F_8 ( short V_15 , struct V_16 * V_6 ) {}
void T_1 F_11 ( struct V_29 * V_6 )
{
unsigned long V_30 ;
if ( ! V_6 )
return;
V_30 = F_12 ( V_31 ) ;
F_13 ( V_31 , V_30 | V_32 ) ;
if ( V_6 -> V_33 )
F_9 ( V_6 -> V_33 , 1 ) ;
if ( V_6 -> V_34 )
F_6 ( V_6 -> V_34 , 1 ) ;
if ( V_6 -> V_17 )
F_6 ( V_6 -> V_17 , 1 ) ;
F_10 ( V_35 , 0 ) ;
F_10 ( V_36 , 0 ) ;
V_37 = * V_6 ;
F_3 ( & V_38 ) ;
}
void T_1 F_11 ( struct V_29 * V_6 ) {}
void T_1 F_14 ( struct V_39 * V_40 , int V_41 )
{
F_15 ( V_42 , 1 ) ;
F_16 ( V_42 , 1 ) ;
F_15 ( V_43 , 1 ) ;
F_16 ( V_43 , 1 ) ;
F_17 ( 0 , V_40 , V_41 ) ;
F_3 ( & V_44 ) ;
}
void T_1 F_14 ( struct V_39 * V_40 , int V_41 )
{
F_10 ( V_42 , 0 ) ;
F_16 ( V_42 , 1 ) ;
F_10 ( V_43 , 0 ) ;
F_16 ( V_43 , 1 ) ;
F_17 ( 0 , V_40 , V_41 ) ;
F_3 ( & V_44 ) ;
}
void T_1 F_14 ( struct V_39 * V_40 , int V_41 ) {}
void T_1 F_18 ( struct V_45 * V_40 , int V_41 )
{
int V_46 ;
unsigned long V_47 ;
F_10 ( V_48 , 0 ) ;
F_10 ( V_49 , 0 ) ;
F_10 ( V_50 , 0 ) ;
for ( V_46 = 0 ; V_46 < V_41 ; V_46 ++ ) {
if ( V_40 [ V_46 ] . V_51 )
V_47 = ( unsigned long ) V_40 [ V_46 ] . V_51 ;
else
V_47 = V_52 [ V_40 [ V_46 ] . V_53 ] ;
F_9 ( V_47 , 1 ) ;
V_40 [ V_46 ] . V_51 = ( void * ) V_47 ;
}
F_19 ( V_40 , V_41 ) ;
F_3 ( & V_54 ) ;
}
void T_1 F_18 ( struct V_45 * V_40 , int V_41 ) {}
void T_1 F_20 ( struct V_55 * V_6 )
{
if ( ! V_6 )
return;
F_10 ( V_56 , 0 ) ;
F_10 ( V_57 , 0 ) ;
F_10 ( V_58 , 0 ) ;
F_10 ( V_59 , 0 ) ;
if ( V_6 -> V_60 )
F_9 ( V_6 -> V_60 , 0 ) ;
V_61 = * V_6 ;
F_3 ( & V_62 ) ;
}
void T_1 F_20 ( struct V_55 * V_6 ) {}
void T_1 F_21 ( struct V_63 * V_6 )
{
if ( ! V_6 ) {
return;
}
F_22 ( V_64 , 0 ) ;
F_10 ( V_65 , 0 ) ;
F_10 ( V_66 , 0 ) ;
F_10 ( V_67 , 0 ) ;
F_10 ( V_68 , 0 ) ;
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
F_22 ( V_83 , 0 ) ;
F_22 ( V_84 , 0 ) ;
V_85 = * V_6 ;
F_3 ( & V_86 ) ;
}
void T_1 F_21 ( struct V_63 * V_6 ) {}
static void T_1 F_23 ( void )
{
F_3 ( & V_87 ) ;
}
static void T_1 F_23 ( void ) { }
void T_1 F_24 ( struct V_88 * V_6 )
{
if ( ! V_6 )
return;
F_10 ( V_89 , 0 ) ;
F_10 ( V_90 , 0 ) ;
F_10 ( V_91 , 0 ) ;
F_10 ( V_92 , 0 ) ;
V_93 = * V_6 ;
F_3 ( & V_94 ) ;
}
void T_1 F_24 ( struct V_88 * V_6 ) {}
static void T_1 F_25 ( void )
{
F_3 ( & V_95 ) ;
}
static void T_1 F_25 ( void ) {}
static void T_1 F_26 ( void )
{
F_3 ( & V_96 ) ;
}
static void T_1 F_27 ( void )
{
F_3 ( & V_97 ) ;
}
static void T_1 F_27 ( void ) {}
void T_1 F_28 ( T_2 V_98 )
{
if ( V_98 & ( 1 << V_99 ) )
F_22 ( V_100 , 1 ) ;
if ( V_98 & ( 1 << V_101 ) )
F_22 ( V_102 , 1 ) ;
if ( V_98 & ( 1 << V_103 ) )
F_22 ( V_104 , 1 ) ;
if ( V_98 & ( 1 << V_105 ) )
F_22 ( V_106 , 1 ) ;
V_107 = V_98 ;
F_3 ( & V_108 ) ;
}
void T_1 F_28 ( T_2 V_98 ) {}
static inline void F_29 ( unsigned V_109 )
{
if ( V_109 & V_110 )
F_10 ( V_111 , 1 ) ;
if ( V_109 & V_112 )
F_10 ( V_64 , 1 ) ;
if ( V_109 & V_113 )
F_10 ( V_114 , 1 ) ;
if ( V_109 & V_115 )
F_10 ( V_116 , 1 ) ;
if ( V_109 & V_117 )
F_22 ( V_118 , 1 ) ;
if ( V_109 & V_119 )
F_22 ( V_120 , 1 ) ;
}
static inline void F_30 ( unsigned V_109 )
{
if ( V_109 & V_110 )
F_22 ( V_121 , 1 ) ;
if ( V_109 & V_112 )
F_22 ( V_122 , 1 ) ;
if ( V_109 & V_113 )
F_22 ( V_123 , 1 ) ;
if ( V_109 & V_115 )
F_22 ( V_124 , 1 ) ;
if ( V_109 & V_117 )
F_22 ( V_125 , 1 ) ;
if ( V_109 & V_119 )
F_22 ( V_126 , 1 ) ;
}
void T_1 F_31 ( unsigned V_127 , unsigned V_109 )
{
struct V_128 * V_129 ;
switch ( V_127 ) {
case V_130 :
V_129 = & V_131 ;
F_29 ( V_109 ) ;
break;
case V_132 :
V_129 = & V_133 ;
F_30 ( V_109 ) ;
break;
default:
return;
}
F_3 ( V_129 ) ;
}
void T_1 F_31 ( unsigned V_127 , unsigned V_109 ) {}
static inline void F_32 ( void )
{
F_10 ( V_134 , 0 ) ;
F_10 ( V_120 , 1 ) ;
}
static inline void F_33 ( unsigned V_109 )
{
F_10 ( V_135 , 1 ) ;
F_10 ( V_136 , 0 ) ;
if ( V_109 & V_137 )
F_10 ( V_125 , 0 ) ;
if ( V_109 & V_138 )
F_10 ( V_118 , 0 ) ;
if ( V_109 & V_139 )
F_10 ( V_140 , 0 ) ;
if ( V_109 & V_141 )
F_10 ( V_142 , 0 ) ;
if ( V_109 & V_143 )
F_10 ( V_144 , 0 ) ;
if ( V_109 & V_145 )
F_10 ( V_146 , 0 ) ;
}
static inline void F_34 ( unsigned V_109 )
{
F_10 ( V_147 , 1 ) ;
F_10 ( V_148 , 0 ) ;
if ( V_109 & V_137 )
F_22 ( V_90 , 0 ) ;
if ( V_109 & V_138 )
F_22 ( V_91 , 0 ) ;
}
static inline void F_35 ( unsigned V_109 )
{
F_10 ( V_123 , 1 ) ;
F_10 ( V_124 , 0 ) ;
if ( V_109 & V_137 )
F_10 ( V_121 , 0 ) ;
if ( V_109 & V_138 )
F_10 ( V_122 , 0 ) ;
}
static inline void F_36 ( unsigned V_109 )
{
F_10 ( V_149 , 1 ) ;
F_10 ( V_150 , 0 ) ;
if ( V_109 & V_137 )
F_22 ( V_59 , 0 ) ;
if ( V_109 & V_138 )
F_22 ( V_58 , 0 ) ;
}
void T_1 F_37 ( unsigned V_127 , unsigned V_151 , unsigned V_109 )
{
struct V_128 * V_129 ;
struct V_152 * V_8 ;
switch ( V_127 ) {
case 0 :
V_129 = & V_153 ;
F_32 () ;
break;
case V_154 :
V_129 = & V_155 ;
F_33 ( V_109 ) ;
break;
case V_156 :
V_129 = & V_157 ;
F_34 ( V_109 ) ;
break;
case V_158 :
V_129 = & V_159 ;
F_35 ( V_109 ) ;
break;
case V_160 :
V_129 = & V_161 ;
F_36 ( V_109 ) ;
break;
default:
return;
}
V_8 = V_129 -> V_162 . V_163 ;
V_8 -> V_164 = V_151 ;
if ( V_151 < V_165 )
V_166 [ V_151 ] = V_129 ;
}
void T_1 F_38 ( unsigned V_151 )
{
if ( V_151 < V_165 ) {
V_167 = V_166 [ V_151 ] ;
F_39 ( V_166 [ V_151 ] -> V_127 ) ;
}
}
void T_1 F_40 ( void )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_165 ; V_46 ++ ) {
if ( V_166 [ V_46 ] )
F_3 ( V_166 [ V_46 ] ) ;
}
if ( ! V_167 )
F_41 ( V_168 L_1 ) ;
}
void T_1 F_37 ( unsigned V_127 , unsigned V_151 , unsigned V_109 ) {}
void T_1 F_38 ( unsigned V_151 ) {}
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
