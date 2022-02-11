static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 , * V_9 ;
if ( ! V_2 -> V_10 )
return;
V_4 = V_2 -> V_10 ;
V_2 -> V_10 = NULL ;
F_2 ( V_11 , L_1 , V_2 , V_2 -> V_12 ,
V_4 ) ;
F_3 (entry, next, &vdata->vd_head) {
V_6 =
F_4 ( V_8 , struct V_5 , V_13 ) ;
F_5 ( & V_6 -> V_13 ) ;
F_6 ( & V_6 -> V_14 ) ;
if ( V_6 -> V_15 )
F_7 ( V_6 , 0 ) ;
F_8 ( & V_6 -> V_14 ) ;
F_9 ( V_6 ) ;
}
F_10 ( V_4 ) ;
F_11 ( V_16 ) ;
}
static int F_12 ( struct V_17 * V_17 , struct V_1 * V_2 )
{
if ( ( V_2 -> V_18 & ( V_19 | V_20 ) ) != ( V_19 | V_20 ) )
return - V_21 ;
if ( V_2 -> V_22 & ( V_23 - 1 ) ||
V_2 -> V_24 & ( V_23 - 1 ) )
return - V_25 ;
V_2 -> V_18 |= V_26 | V_27 | V_28 |
V_29 | V_30 | V_31 ;
V_2 -> V_32 = V_33 ;
V_2 -> V_34 = & V_35 ;
V_2 -> V_10 = F_13 ( V_2 , 0 ) ;
if ( ! V_2 -> V_10 )
return - V_36 ;
F_2 ( V_11 , L_2 ,
V_17 , V_2 -> V_22 , V_2 , V_2 -> V_10 ) ;
return 0 ;
}
static int F_14 ( unsigned long V_37 )
{
struct V_38 V_39 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_40 = - V_25 ;
if ( F_15 ( & V_39 , ( void V_41 * ) V_37 , sizeof( V_39 ) ) )
return - V_42 ;
if ( V_39 . V_43 > V_44 )
return - V_25 ;
if ( V_39 . V_45 > V_46 || ! V_39 . V_47 )
return - V_25 ;
if ( ! ( V_39 . V_48 & V_49 ) )
V_39 . V_48 |= V_50 ;
F_16 ( & V_51 -> V_52 -> V_53 ) ;
V_2 = F_17 ( V_39 . V_54 ) ;
if ( V_2 ) {
V_4 = V_2 -> V_10 ;
V_4 -> V_55 = V_39 . V_48 ;
V_4 -> V_56 =
F_18 ( V_39 . V_43 ) ;
V_4 -> V_57 = F_19 ( V_39 . V_45 ) ;
V_4 -> V_58 = V_39 . V_59 ;
V_40 = 0 ;
}
F_20 ( & V_51 -> V_52 -> V_53 ) ;
return V_40 ;
}
static long F_21 ( unsigned long V_37 )
{
struct V_60 V_61 ;
int V_62 ;
if ( F_22 () > 1 &&
( F_23 ( 1 ) == F_23 ( 0 ) ) )
V_62 = 2 ;
else
V_62 = 1 ;
V_61 . V_63 = F_24 () ;
V_61 . V_64 = F_22 () ;
V_61 . V_65 = V_61 . V_64 / V_62 ;
V_61 . V_66 = V_67 * V_61 . V_65 ;
if ( F_25 ( ( void V_41 * ) V_37 , & V_61 , sizeof( V_61 ) ) )
return - V_42 ;
return 0 ;
}
static long F_26 ( struct V_17 * V_17 , unsigned int V_39 ,
unsigned long V_37 )
{
int V_68 = - V_69 ;
F_2 ( V_11 , L_3 , V_17 , V_39 , V_37 ) ;
switch ( V_39 ) {
case V_70 :
V_68 = F_14 ( V_37 ) ;
break;
case V_71 :
V_68 = F_27 ( V_37 ) ;
break;
case V_72 :
V_68 = F_28 ( V_37 ) ;
break;
case V_73 :
V_68 = F_29 ( V_37 ) ;
break;
case V_74 :
V_68 = F_30 ( V_37 ) ;
break;
case V_75 :
V_68 = F_31 ( V_37 ) ;
break;
case V_76 :
V_68 = F_32 ( V_37 ) ;
break;
case V_77 :
V_68 = F_33 ( V_37 ) ;
break;
case V_78 :
V_68 = F_21 ( V_37 ) ;
break;
case V_79 :
V_68 = F_34 ( V_37 ) ;
break;
}
return V_68 ;
}
static void F_35 ( struct V_80 * V_81 , unsigned long V_82 ,
void * V_83 , int V_84 , int V_85 )
{
F_36 ( & V_81 -> V_86 ) ;
F_36 ( & V_81 -> V_87 ) ;
V_81 -> V_88 = V_82 ;
V_81 -> V_89 = V_83 ;
V_81 -> V_90 = V_84 * V_67 + V_85 ;
V_81 -> V_91 = V_92 [ V_84 ] ;
V_81 -> V_93 = V_84 ;
V_81 -> V_94 = V_85 ;
V_81 -> V_95 = ( V_96 == 64 ) ? ~ 0 : ( 1UL << V_96 ) - 1 ;
V_81 -> V_97 = ( 1UL << V_98 ) - 1 ;
V_81 -> V_99 = V_100 ;
F_37 ( V_81 ) ;
if ( V_81 -> V_90 >= V_101 )
V_101 = V_81 -> V_90 + 1 ;
F_2 ( V_11 , L_4 ,
V_84 , V_81 -> V_90 , V_81 -> V_89 ,
V_81 -> V_88 ) ;
}
static int F_38 ( unsigned long V_102 , void * V_103 )
{
int V_104 , V_105 , V_106 , V_107 ;
int V_108 , V_109 , V_110 ;
int V_111 = F_39 ( sizeof( struct V_112 ) ) ;
struct V_113 * V_113 ;
struct V_80 * V_81 ;
unsigned long V_82 ;
void * V_83 ;
V_46 = V_114 ;
V_44 = V_115 ;
F_40 (bid) {
V_104 = F_41 ( V_106 ) ;
V_105 = F_42 ( V_106 ) ;
V_113 = F_43 ( V_105 , V_116 , V_111 ) ;
if ( ! V_113 )
goto V_117;
V_92 [ V_106 ] = F_44 ( V_113 ) ;
memset ( V_92 [ V_106 ] , 0 , sizeof( struct V_112 ) ) ;
V_92 [ V_106 ] -> V_118 = & V_92 [ V_106 ] -> V_119 [ 0 ] ;
F_36 ( & V_92 [ V_106 ] -> V_120 ) ;
F_45 ( & V_92 [ V_106 ] -> V_121 ) ;
V_109 = 0 ;
V_108 = 0 ;
for ( V_81 = V_92 [ V_106 ] -> V_119 , V_107 = 0 ;
V_107 < V_67 ;
V_107 ++ , V_81 ++ ) {
V_82 = F_46 ( V_102 , V_104 , V_107 ) ;
V_83 = F_47 ( V_103 , V_104 , V_107 ) ;
F_35 ( V_81 , V_82 , V_83 , V_106 , V_107 ) ;
V_110 = F_48 ( V_81 -> V_95 ) * V_122 ;
V_108 = F_49 ( V_108 , V_110 ) ;
V_110 = F_48 ( V_81 -> V_97 ) * V_123 ;
V_109 = F_49 ( V_109 , V_110 ) ;
}
V_46 = F_50 ( V_46 , V_108 ) ;
V_44 = F_50 ( V_44 , V_109 ) ;
}
return 0 ;
V_117:
for ( V_106 -- ; V_106 >= 0 ; V_106 -- )
F_51 ( ( unsigned long ) V_92 [ V_106 ] , V_111 ) ;
return - V_36 ;
}
static void F_52 ( void )
{
int V_106 ;
int V_111 = F_39 ( sizeof( struct V_80 ) *
V_67 ) ;
for ( V_106 = 0 ; V_106 < V_124 ; V_106 ++ )
F_51 ( ( unsigned long ) V_92 [ V_106 ] , V_111 ) ;
}
static unsigned long F_53 ( int V_125 , int V_126 , int * V_127 )
{
unsigned long V_128 = 0 ;
int V_129 ;
V_129 = F_54 ( V_126 ) + V_130 * F_55 ( V_126 ) ;
if ( V_129 >= V_131 || F_56 ( V_126 ) )
return 0 ;
if ( V_125 == 0 ) {
V_128 = V_132 +
V_129 * ( V_133 - V_132 ) ;
} else if ( V_125 == 1 ) {
V_128 = V_134 +
V_129 * ( V_135 - V_134 ) ;
} else {
F_57 () ;
}
* V_127 = V_129 ;
return V_128 ;
}
static void F_58 ( struct V_136 * V_137 )
{
}
static int F_59 ( int V_125 , char * V_138 ,
T_1 V_139 , int V_126 , int V_140 )
{
unsigned long V_128 ;
int V_141 = V_142 + V_125 ;
int V_40 , V_129 ;
V_128 = F_53 ( V_125 , V_126 , & V_129 ) ;
if ( V_128 == 0 )
return 0 ;
if ( V_143 [ V_125 ] == 0 ) {
V_144 [ V_125 ] . V_145 = V_138 ;
V_40 = F_60 ( V_141 , & V_144 [ V_125 ] ) ;
if ( V_40 ) {
F_61 ( V_146 L_5 ,
V_147 , - V_40 ) ;
return V_40 ;
}
V_40 = F_62 ( V_141 , V_139 , 0 , V_138 , NULL ) ;
if ( V_40 ) {
F_61 ( V_146 L_6 ,
V_147 , - V_40 ) ;
return V_40 ;
}
}
V_143 [ V_125 ] ++ ;
return 0 ;
}
static void F_63 ( int V_125 , int V_126 , int V_140 )
{
unsigned long V_128 ;
int V_129 , V_141 = V_142 + V_125 ;
if ( V_143 [ V_125 ] == 0 )
return;
V_128 = F_53 ( V_125 , V_126 , & V_129 ) ;
if ( V_128 == 0 )
return;
if ( -- V_143 [ V_125 ] == 0 )
F_64 ( V_141 , NULL ) ;
}
static int F_59 ( int V_125 , char * V_138 ,
T_1 V_139 , int V_126 , int V_140 )
{
unsigned long V_128 ;
int V_141 , V_129 ;
int V_40 ;
V_128 = F_53 ( V_125 , V_126 , & V_129 ) ;
if ( V_128 == 0 )
return 0 ;
V_141 = F_65 ( V_138 , V_126 , V_140 , V_128 , V_148 ) ;
if ( V_141 < 0 ) {
F_61 ( V_146 L_7 ,
V_147 , - V_141 ) ;
return V_141 ;
}
V_40 = F_62 ( V_141 , V_139 , 0 , V_138 , NULL ) ;
if ( V_40 ) {
F_66 ( V_141 ) ;
F_61 ( V_146 L_6 ,
V_147 , - V_40 ) ;
return V_40 ;
}
V_92 [ V_140 ] -> V_119 [ V_125 ] . V_149 [ V_129 ] = V_141 ;
return 0 ;
}
static void F_63 ( int V_125 , int V_126 , int V_140 )
{
int V_141 , V_129 ;
unsigned long V_128 ;
V_128 = F_53 ( V_125 , V_126 , & V_129 ) ;
if ( V_128 ) {
V_141 = V_92 [ V_140 ] -> V_119 [ V_125 ] . V_149 [ V_129 ] ;
if ( V_141 ) {
F_64 ( V_141 , NULL ) ;
F_66 ( V_141 ) ;
}
}
}
static void F_67 ( void )
{
int V_140 ;
int V_126 ;
F_68 (cpu) {
V_140 = F_69 ( V_126 ) ;
F_63 ( 0 , V_126 , V_140 ) ;
F_63 ( 1 , V_126 , V_140 ) ;
}
F_40 (blade) {
if ( F_70 ( V_140 ) )
continue;
F_63 ( 0 , 0 , V_140 ) ;
F_63 ( 1 , 0 , V_140 ) ;
}
}
static int F_71 ( void )
{
int V_140 ;
int V_126 ;
int V_40 ;
F_68 (cpu) {
V_140 = F_69 ( V_126 ) ;
V_40 = F_59 ( 0 , L_8 , V_150 , V_126 , V_140 ) ;
if ( V_40 != 0 )
goto V_151;
V_40 = F_59 ( 1 , L_9 , V_152 , V_126 , V_140 ) ;
if ( V_40 != 0 )
goto V_151;
}
F_40 (blade) {
if ( F_70 ( V_140 ) )
continue;
V_40 = F_59 ( 0 , L_8 , V_153 , 0 , V_140 ) ;
if ( V_40 != 0 )
goto V_151;
V_40 = F_59 ( 1 , L_9 , V_153 , 0 , V_140 ) ;
if ( V_40 != 0 )
goto V_151;
}
return 0 ;
V_151:
F_67 () ;
return V_40 ;
}
static int T_2 F_72 ( void )
{
int V_40 ;
if ( ! F_73 () )
return 0 ;
#if V_154 V_155
V_156 = 0xd000000000UL ;
#else
V_156 = F_74 ( V_157 ) &
0x7fffffffffffUL ;
#endif
V_158 = F_75 ( V_156 ) ;
V_159 = V_156 + V_124 * V_160 ;
F_61 ( V_161 L_10 ,
V_156 , V_159 ) ;
V_40 = F_76 ( & V_162 ) ;
if ( V_40 ) {
F_61 ( V_146 L_11 ,
V_147 ) ;
goto V_163;
}
V_40 = F_77 () ;
if ( V_40 ) {
F_61 ( V_146 L_12 , V_147 ) ;
goto V_151;
}
V_40 = F_38 ( V_156 , V_158 ) ;
if ( V_40 ) {
F_61 ( V_146 L_13 , V_147 ) ;
goto V_164;
}
V_40 = F_71 () ;
if ( V_40 != 0 )
goto V_165;
F_78 () ;
F_61 ( V_161 L_14 , V_147 ,
V_166 ) ;
return 0 ;
V_165:
F_52 () ;
V_164:
F_79 () ;
V_151:
F_80 ( & V_162 ) ;
V_163:
return V_40 ;
}
static void T_3 F_81 ( void )
{
if ( ! F_73 () )
return;
F_67 () ;
F_82 () ;
F_52 () ;
F_80 ( & V_162 ) ;
F_79 () ;
}
