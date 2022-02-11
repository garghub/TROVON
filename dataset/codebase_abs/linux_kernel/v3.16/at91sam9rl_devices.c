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
if ( F_25 ( 0 , & V_3 -> V_87 ) )
F_9 ( V_88 , 0 ) ;
if ( F_25 ( 1 , & V_3 -> V_87 ) )
F_9 ( V_89 , 0 ) ;
if ( F_25 ( 2 , & V_3 -> V_87 ) )
F_9 ( V_90 , 0 ) ;
if ( F_25 ( 3 , & V_3 -> V_87 ) )
F_9 ( V_91 , 0 ) ;
if ( F_25 ( 4 , & V_3 -> V_87 ) )
F_9 ( V_92 , 0 ) ;
if ( F_25 ( 5 , & V_3 -> V_87 ) )
F_9 ( V_93 , 0 ) ;
if ( V_3 -> V_94 )
F_9 ( V_95 , 0 ) ;
V_3 -> V_96 = 40 ;
V_3 -> V_97 = 4 ;
V_3 -> V_98 = V_99 ;
V_100 = * V_3 ;
F_2 ( & V_101 ) ;
}
void T_1 F_24 ( struct V_86 * V_3 ) {}
static void T_1 F_26 ( void )
{
F_2 ( & V_102 ) ;
}
static void T_1 F_26 ( void ) {}
static void T_1 F_27 ( void )
{
V_103 . V_104 = L_1 ;
V_103 . V_105 = 3 ;
V_106 [ 1 ] . V_107 = V_108 +
4 * V_109 ;
V_106 [ 1 ] . V_110 = V_106 [ 1 ] . V_107 + 3 ;
V_106 [ 2 ] . V_107 = V_111 + V_112 ;
V_106 [ 2 ] . V_110 = V_111 + V_112 ;
}
static void T_1 F_27 ( void )
{
V_103 . V_105 = 1 ;
}
static void T_1 F_28 ( void )
{
F_27 () ;
F_2 ( & V_103 ) ;
}
static void T_1 F_29 ( void )
{
F_2 ( & V_113 ) ;
}
static void T_1 F_29 ( void ) {}
void T_1 F_30 ( T_2 V_114 )
{
if ( V_114 & ( 1 << V_115 ) )
F_22 ( V_116 , 1 ) ;
if ( V_114 & ( 1 << V_117 ) )
F_22 ( V_118 , 1 ) ;
if ( V_114 & ( 1 << V_119 ) )
F_22 ( V_120 , 1 ) ;
if ( V_114 & ( 1 << V_121 ) )
F_22 ( V_122 , 1 ) ;
V_123 = V_114 ;
F_2 ( & V_124 ) ;
}
void T_1 F_30 ( T_2 V_114 ) {}
static inline void F_31 ( unsigned V_125 )
{
if ( V_125 & V_126 )
F_9 ( V_127 , 1 ) ;
if ( V_125 & V_128 )
F_9 ( V_62 , 1 ) ;
if ( V_125 & V_129 )
F_9 ( V_130 , 1 ) ;
if ( V_125 & V_131 )
F_9 ( V_132 , 1 ) ;
if ( V_125 & V_133 )
F_22 ( V_134 , 1 ) ;
if ( V_125 & V_135 )
F_22 ( V_136 , 1 ) ;
}
static inline void F_32 ( unsigned V_125 )
{
if ( V_125 & V_126 )
F_22 ( V_137 , 1 ) ;
if ( V_125 & V_128 )
F_22 ( V_138 , 1 ) ;
if ( V_125 & V_129 )
F_22 ( V_139 , 1 ) ;
if ( V_125 & V_131 )
F_22 ( V_140 , 1 ) ;
if ( V_125 & V_133 )
F_22 ( V_141 , 1 ) ;
if ( V_125 & V_135 )
F_22 ( V_142 , 1 ) ;
}
void T_1 F_33 ( unsigned V_143 , unsigned V_125 )
{
struct V_144 * V_145 ;
switch ( V_143 ) {
case V_146 :
V_145 = & V_147 ;
F_31 ( V_125 ) ;
break;
case V_148 :
V_145 = & V_149 ;
F_32 ( V_125 ) ;
break;
default:
return;
}
F_2 ( V_145 ) ;
}
void T_1 F_33 ( unsigned V_143 , unsigned V_125 ) {}
static inline void F_34 ( void )
{
F_9 ( V_150 , 0 ) ;
F_9 ( V_136 , 1 ) ;
}
static inline void F_35 ( unsigned V_125 )
{
F_9 ( V_151 , 1 ) ;
F_9 ( V_152 , 0 ) ;
if ( V_125 & V_153 )
F_9 ( V_141 , 0 ) ;
if ( V_125 & V_154 )
F_9 ( V_134 , 0 ) ;
if ( V_125 & V_155 )
F_9 ( V_156 , 0 ) ;
if ( V_125 & V_157 )
F_9 ( V_158 , 0 ) ;
if ( V_125 & V_159 )
F_9 ( V_160 , 0 ) ;
if ( V_125 & V_161 )
F_9 ( V_162 , 0 ) ;
}
static inline void F_36 ( unsigned V_125 )
{
F_9 ( V_163 , 1 ) ;
F_9 ( V_164 , 0 ) ;
if ( V_125 & V_153 )
F_22 ( V_89 , 0 ) ;
if ( V_125 & V_154 )
F_22 ( V_90 , 0 ) ;
}
static inline void F_37 ( unsigned V_125 )
{
F_9 ( V_139 , 1 ) ;
F_9 ( V_140 , 0 ) ;
if ( V_125 & V_153 )
F_9 ( V_137 , 0 ) ;
if ( V_125 & V_154 )
F_9 ( V_138 , 0 ) ;
}
static inline void F_38 ( unsigned V_125 )
{
F_9 ( V_165 , 1 ) ;
F_9 ( V_166 , 0 ) ;
if ( V_125 & V_153 )
F_22 ( V_57 , 0 ) ;
if ( V_125 & V_154 )
F_22 ( V_56 , 0 ) ;
}
void T_1 F_39 ( unsigned V_143 , unsigned V_167 , unsigned V_125 )
{
struct V_144 * V_145 ;
struct V_168 * V_5 ;
switch ( V_143 ) {
case 0 :
V_145 = & V_169 ;
F_34 () ;
break;
case V_170 :
V_145 = & V_171 ;
F_35 ( V_125 ) ;
break;
case V_172 :
V_145 = & V_173 ;
F_36 ( V_125 ) ;
break;
case V_174 :
V_145 = & V_175 ;
F_37 ( V_125 ) ;
break;
case V_176 :
V_145 = & V_177 ;
F_38 ( V_125 ) ;
break;
default:
return;
}
V_5 = V_145 -> V_178 . V_179 ;
V_5 -> V_180 = V_167 ;
if ( V_167 < V_181 )
V_182 [ V_167 ] = V_145 ;
}
void T_1 F_40 ( void )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_181 ; V_44 ++ ) {
if ( V_182 [ V_44 ] )
F_2 ( V_182 [ V_44 ] ) ;
}
}
void T_1 F_39 ( unsigned V_143 , unsigned V_167 , unsigned V_125 ) {}
void T_1 F_40 ( void ) {}
static int T_1 F_41 ( void )
{
F_1 () ;
F_26 () ;
F_28 () ;
F_29 () ;
F_23 () ;
return 0 ;
}
