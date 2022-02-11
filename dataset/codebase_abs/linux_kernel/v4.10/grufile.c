static int F_1 ( void )
{
return F_2 () &&
( V_1 -> V_2 < V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 , * V_12 ;
if ( ! V_5 -> V_13 )
return;
V_7 = V_5 -> V_13 ;
V_5 -> V_13 = NULL ;
F_4 ( V_14 , L_1 , V_5 , V_5 -> V_15 ,
V_7 ) ;
F_5 (entry, next, &vdata->vd_head) {
V_9 =
F_6 ( V_11 , struct V_8 , V_16 ) ;
F_7 ( & V_9 -> V_16 ) ;
F_8 ( & V_9 -> V_17 ) ;
if ( V_9 -> V_18 )
F_9 ( V_9 , 0 ) ;
F_10 ( & V_9 -> V_17 ) ;
F_11 ( V_9 ) ;
}
F_12 ( V_7 ) ;
F_13 ( V_19 ) ;
}
static int F_14 ( struct V_20 * V_20 , struct V_4 * V_5 )
{
if ( ( V_5 -> V_21 & ( V_22 | V_23 ) ) != ( V_22 | V_23 ) )
return - V_24 ;
if ( V_5 -> V_25 & ( V_26 - 1 ) ||
V_5 -> V_27 & ( V_26 - 1 ) )
return - V_28 ;
V_5 -> V_21 |= V_29 | V_30 | V_31 |
V_32 | V_33 | V_34 ;
V_5 -> V_35 = V_36 ;
V_5 -> V_37 = & V_38 ;
V_5 -> V_13 = F_15 ( V_5 , 0 ) ;
if ( ! V_5 -> V_13 )
return - V_39 ;
F_4 ( V_14 , L_2 ,
V_20 , V_5 -> V_25 , V_5 , V_5 -> V_13 ) ;
return 0 ;
}
static int F_16 ( unsigned long V_40 )
{
struct V_41 V_42 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_43 = - V_28 ;
if ( F_17 ( & V_42 , ( void V_44 * ) V_40 , sizeof( V_42 ) ) )
return - V_45 ;
if ( V_42 . V_46 > V_47 )
return - V_28 ;
if ( V_42 . V_48 > V_49 || ! V_42 . V_50 )
return - V_28 ;
if ( ! ( V_42 . V_51 & V_52 ) )
V_42 . V_51 |= V_53 ;
F_18 ( & V_54 -> V_55 -> V_56 ) ;
V_5 = F_19 ( V_42 . V_57 ) ;
if ( V_5 ) {
V_7 = V_5 -> V_13 ;
V_7 -> V_58 = V_42 . V_51 ;
V_7 -> V_59 =
F_20 ( V_42 . V_46 ) ;
V_7 -> V_60 = F_21 ( V_42 . V_48 ) ;
V_7 -> V_61 = V_42 . V_62 ;
V_43 = 0 ;
}
F_22 ( & V_54 -> V_55 -> V_56 ) ;
return V_43 ;
}
static long F_23 ( unsigned long V_40 )
{
struct V_63 V_64 ;
int V_65 ;
if ( F_24 () > 1 &&
( F_25 ( 1 ) == F_25 ( 0 ) ) )
V_65 = 2 ;
else
V_65 = 1 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_66 = F_26 () ;
V_64 . V_67 = F_24 () ;
V_64 . V_68 = V_64 . V_67 / V_65 ;
V_64 . V_69 = V_70 * V_64 . V_68 ;
if ( F_27 ( ( void V_44 * ) V_40 , & V_64 , sizeof( V_64 ) ) )
return - V_45 ;
return 0 ;
}
static long F_28 ( struct V_20 * V_20 , unsigned int V_42 ,
unsigned long V_40 )
{
int V_71 = - V_72 ;
F_4 ( V_14 , L_3 , V_20 , V_42 , V_40 ) ;
switch ( V_42 ) {
case V_73 :
V_71 = F_16 ( V_40 ) ;
break;
case V_74 :
V_71 = F_29 ( V_40 ) ;
break;
case V_75 :
V_71 = F_30 ( V_40 ) ;
break;
case V_76 :
V_71 = F_31 ( V_40 ) ;
break;
case V_77 :
V_71 = F_32 ( V_40 ) ;
break;
case V_78 :
V_71 = F_33 ( V_40 ) ;
break;
case V_79 :
V_71 = F_34 ( V_40 ) ;
break;
case V_80 :
V_71 = F_35 ( V_40 ) ;
break;
case V_81 :
V_71 = F_23 ( V_40 ) ;
break;
case V_82 :
V_71 = F_36 ( V_40 ) ;
break;
}
return V_71 ;
}
static void F_37 ( struct V_83 * V_84 , unsigned long V_85 ,
void * V_86 , int V_87 , int V_88 )
{
F_38 ( & V_84 -> V_89 ) ;
F_38 ( & V_84 -> V_90 ) ;
V_84 -> V_91 = V_85 ;
V_84 -> V_92 = V_86 ;
V_84 -> V_93 = V_87 * V_70 + V_88 ;
V_84 -> V_94 = V_95 [ V_87 ] ;
V_84 -> V_96 = V_87 ;
V_84 -> V_97 = V_88 ;
V_84 -> V_98 = ( V_99 == 64 ) ? ~ 0 : ( 1UL << V_99 ) - 1 ;
V_84 -> V_100 = ( 1UL << V_101 ) - 1 ;
V_84 -> V_102 = V_103 ;
F_39 ( V_84 ) ;
if ( V_84 -> V_93 >= V_104 )
V_104 = V_84 -> V_93 + 1 ;
F_4 ( V_14 , L_4 ,
V_87 , V_84 -> V_93 , V_84 -> V_92 ,
V_84 -> V_91 ) ;
}
static int F_40 ( unsigned long V_105 , void * V_106 )
{
int V_107 , V_108 , V_109 , V_110 ;
int V_111 , V_112 , V_113 ;
int V_114 = F_41 ( sizeof( struct V_115 ) ) ;
struct V_116 * V_116 ;
struct V_83 * V_84 ;
unsigned long V_85 ;
void * V_86 ;
V_49 = V_117 ;
V_47 = V_118 ;
F_42 (bid) {
V_107 = F_43 ( V_109 ) ;
V_108 = F_44 ( V_109 ) ;
V_116 = F_45 ( V_108 , V_119 , V_114 ) ;
if ( ! V_116 )
goto V_120;
V_95 [ V_109 ] = F_46 ( V_116 ) ;
memset ( V_95 [ V_109 ] , 0 , sizeof( struct V_115 ) ) ;
V_95 [ V_109 ] -> V_121 = & V_95 [ V_109 ] -> V_122 [ 0 ] ;
F_38 ( & V_95 [ V_109 ] -> V_123 ) ;
F_47 ( & V_95 [ V_109 ] -> V_124 ) ;
V_112 = 0 ;
V_111 = 0 ;
for ( V_84 = V_95 [ V_109 ] -> V_122 , V_110 = 0 ;
V_110 < V_70 ;
V_110 ++ , V_84 ++ ) {
V_85 = F_48 ( V_105 , V_107 , V_110 ) ;
V_86 = F_49 ( V_106 , V_107 , V_110 ) ;
F_37 ( V_84 , V_85 , V_86 , V_109 , V_110 ) ;
V_113 = F_50 ( V_84 -> V_98 ) * V_125 ;
V_111 = F_51 ( V_111 , V_113 ) ;
V_113 = F_50 ( V_84 -> V_100 ) * V_126 ;
V_112 = F_51 ( V_112 , V_113 ) ;
}
V_49 = F_52 ( V_49 , V_111 ) ;
V_47 = F_52 ( V_47 , V_112 ) ;
}
return 0 ;
V_120:
for ( V_109 -- ; V_109 >= 0 ; V_109 -- )
F_53 ( ( unsigned long ) V_95 [ V_109 ] , V_114 ) ;
return - V_39 ;
}
static void F_54 ( void )
{
int V_109 ;
int V_114 = F_41 ( sizeof( struct V_83 ) *
V_70 ) ;
for ( V_109 = 0 ; V_109 < V_127 ; V_109 ++ )
F_53 ( ( unsigned long ) V_95 [ V_109 ] , V_114 ) ;
}
static unsigned long F_55 ( int V_128 , int V_129 , int * V_130 )
{
unsigned long V_131 = 0 ;
int V_132 ;
V_132 = F_56 ( V_129 ) + V_133 * F_57 ( V_129 ) ;
if ( V_132 >= V_134 || F_58 ( V_129 ) )
return 0 ;
if ( V_128 == 0 ) {
V_131 = V_135 +
V_132 * ( V_136 - V_135 ) ;
} else if ( V_128 == 1 ) {
V_131 = V_137 +
V_132 * ( V_138 - V_137 ) ;
} else {
F_59 () ;
}
* V_130 = V_132 ;
return V_131 ;
}
static void F_60 ( struct V_139 * V_140 )
{
}
static int F_61 ( int V_128 , char * V_141 ,
T_1 V_142 , int V_129 , int V_143 )
{
unsigned long V_131 ;
int V_144 = V_145 + V_128 ;
int V_43 , V_132 ;
V_131 = F_55 ( V_128 , V_129 , & V_132 ) ;
if ( V_131 == 0 )
return 0 ;
if ( V_146 [ V_128 ] == 0 ) {
V_147 [ V_128 ] . V_148 = V_141 ;
V_43 = F_62 ( V_144 , & V_147 [ V_128 ] ) ;
if ( V_43 ) {
F_63 ( V_149 L_5 ,
V_150 , - V_43 ) ;
return V_43 ;
}
V_43 = F_64 ( V_144 , V_142 , 0 , V_141 , NULL ) ;
if ( V_43 ) {
F_63 ( V_149 L_6 ,
V_150 , - V_43 ) ;
return V_43 ;
}
}
V_146 [ V_128 ] ++ ;
return 0 ;
}
static void F_65 ( int V_128 , int V_129 , int V_143 )
{
unsigned long V_131 ;
int V_132 , V_144 = V_145 + V_128 ;
if ( V_146 [ V_128 ] == 0 )
return;
V_131 = F_55 ( V_128 , V_129 , & V_132 ) ;
if ( V_131 == 0 )
return;
if ( -- V_146 [ V_128 ] == 0 )
F_66 ( V_144 , NULL ) ;
}
static int F_61 ( int V_128 , char * V_141 ,
T_1 V_142 , int V_129 , int V_143 )
{
unsigned long V_131 ;
int V_144 , V_132 ;
int V_43 ;
V_131 = F_55 ( V_128 , V_129 , & V_132 ) ;
if ( V_131 == 0 )
return 0 ;
V_144 = F_67 ( V_141 , V_129 , V_143 , V_131 , V_151 ) ;
if ( V_144 < 0 ) {
F_63 ( V_149 L_7 ,
V_150 , - V_144 ) ;
return V_144 ;
}
V_43 = F_64 ( V_144 , V_142 , 0 , V_141 , NULL ) ;
if ( V_43 ) {
F_68 ( V_144 ) ;
F_63 ( V_149 L_6 ,
V_150 , - V_43 ) ;
return V_43 ;
}
V_95 [ V_143 ] -> V_122 [ V_128 ] . V_152 [ V_132 ] = V_144 ;
return 0 ;
}
static void F_65 ( int V_128 , int V_129 , int V_143 )
{
int V_144 , V_132 ;
unsigned long V_131 ;
V_131 = F_55 ( V_128 , V_129 , & V_132 ) ;
if ( V_131 ) {
V_144 = V_95 [ V_143 ] -> V_122 [ V_128 ] . V_152 [ V_132 ] ;
if ( V_144 ) {
F_66 ( V_144 , NULL ) ;
F_68 ( V_144 ) ;
}
}
}
static void F_69 ( void )
{
int V_143 ;
int V_129 ;
F_70 (cpu) {
V_143 = F_71 ( V_129 ) ;
F_65 ( 0 , V_129 , V_143 ) ;
F_65 ( 1 , V_129 , V_143 ) ;
}
F_42 (blade) {
if ( F_72 ( V_143 ) )
continue;
F_65 ( 0 , 0 , V_143 ) ;
F_65 ( 1 , 0 , V_143 ) ;
}
}
static int F_73 ( void )
{
int V_143 ;
int V_129 ;
int V_43 ;
F_70 (cpu) {
V_143 = F_71 ( V_129 ) ;
V_43 = F_61 ( 0 , L_8 , V_153 , V_129 , V_143 ) ;
if ( V_43 != 0 )
goto V_154;
V_43 = F_61 ( 1 , L_9 , V_155 , V_129 , V_143 ) ;
if ( V_43 != 0 )
goto V_154;
}
F_42 (blade) {
if ( F_72 ( V_143 ) )
continue;
V_43 = F_61 ( 0 , L_8 , V_156 , 0 , V_143 ) ;
if ( V_43 != 0 )
goto V_154;
V_43 = F_61 ( 1 , L_9 , V_156 , 0 , V_143 ) ;
if ( V_43 != 0 )
goto V_154;
}
return 0 ;
V_154:
F_69 () ;
return V_43 ;
}
static int T_2 F_74 ( void )
{
int V_43 ;
if ( ! F_1 () )
return 0 ;
#if V_157 V_158
V_159 = 0xd000000000UL ;
#else
V_159 = F_75 ( V_160 ) &
0x7fffffffffffUL ;
#endif
V_161 = F_76 ( V_159 ) ;
V_162 = V_159 + V_127 * V_163 ;
F_63 ( V_164 L_10 ,
V_159 , V_162 ) ;
V_43 = F_77 ( & V_165 ) ;
if ( V_43 ) {
F_63 ( V_149 L_11 ,
V_150 ) ;
goto V_166;
}
V_43 = F_78 () ;
if ( V_43 ) {
F_63 ( V_149 L_12 , V_150 ) ;
goto V_154;
}
V_43 = F_40 ( V_159 , V_161 ) ;
if ( V_43 ) {
F_63 ( V_149 L_13 , V_150 ) ;
goto V_167;
}
V_43 = F_73 () ;
if ( V_43 != 0 )
goto V_168;
F_79 () ;
F_63 ( V_164 L_14 , V_150 ,
V_169 ) ;
return 0 ;
V_168:
F_54 () ;
V_167:
F_80 () ;
V_154:
F_81 ( & V_165 ) ;
V_166:
return V_43 ;
}
static void T_3 F_82 ( void )
{
if ( ! F_1 () )
return;
F_69 () ;
F_83 () ;
F_54 () ;
F_81 ( & V_165 ) ;
F_80 () ;
}
