static void F_1 (
struct V_1 * V_2 ,
char * V_3 ,
T_1 V_4 ,
char * * V_5 ,
unsigned * V_6 )
{
F_2 ( V_2 , V_5 , V_6 , L_1 ,
V_3 ,
V_4 ,
( V_4 & V_7 ) ? L_2 : L_3 ,
( V_4 & V_8 ) ? L_4 : L_3 ,
( V_4 & V_9 ) ? L_5 : L_3 ,
( V_4 & V_10 ) ? L_6 : L_3 ,
( V_4 & V_11 ) ? L_7 : L_3 ,
( V_4 & V_12 ) ? L_8 : L_3 ,
( V_4 & V_13 ) ? L_9 : L_3 ,
( V_4 & V_14 ) ? L_10 : L_3 ,
( V_4 & V_15 ) ? L_11 : L_3
) ;
}
static void F_3 (
struct V_1 * V_2 ,
char * V_3 ,
T_1 V_16 ,
char * * V_5 ,
unsigned * V_6 )
{
if ( V_16 )
F_2 ( V_2 , V_5 , V_6 , L_12 , V_3 , V_16 ) ;
}
static char * F_4 ( int V_17 )
{
switch ( V_17 ) {
case V_18 : return L_13 ;
case V_19 : return L_14 ;
case V_20 : return L_15 ;
case V_21 : return L_16 ;
}
return L_17 ;
}
static const char * F_5 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_22 ) {
case V_23 :
return L_18 ;
case V_24 :
return L_19 ;
case V_25 :
return L_20 ;
}
return L_17 ;
}
static void
F_6 ( struct V_1 * V_26 , char * * V_5 , unsigned * V_6 )
{
struct V_27 T_2 * V_28 = V_26 -> V_28 ;
T_1 V_29 ;
V_29 = F_7 ( V_26 , & V_28 -> V_30 ) & 0xff ;
F_2 ( V_26 , V_5 , V_6 ,
L_21 ,
0x03 & ( V_29 >> 4 ) , ( V_29 & 0x0f ) ,
( V_29 & 0x0100 ) ? L_22 : L_23 ,
F_5 ( V_26 ) ) ;
V_29 = F_7 ( V_26 , & V_28 -> V_31 ) ;
F_2 ( V_26 , V_5 , V_6 ,
L_24 ,
V_29 ,
( V_29 & V_32 ) ? L_25 : L_3 ,
( V_29 & V_33 ) ? L_26 : L_3 ,
( V_29 & V_34 ) ? L_27 : L_3 ,
F_4 ( V_29 & V_35 ) ,
( V_29 & V_36 ) ? L_28 : L_3 ,
( V_29 & V_37 ) ? L_29 : L_3 ,
( V_29 & V_38 ) ? L_30 : L_3 ,
( V_29 & V_39 ) ? L_31 : L_3 ,
V_29 & V_40
) ;
V_29 = F_7 ( V_26 , & V_28 -> V_41 ) ;
F_2 ( V_26 , V_5 , V_6 ,
L_32 , V_29 ,
( V_29 & V_42 ) >> 16 ,
( V_29 & V_43 ) ? L_33 : L_3 ,
( V_29 & V_44 ) ? L_34 : L_3 ,
( V_29 & V_45 ) ? L_35 : L_3 ,
( V_29 & V_46 ) ? L_36 : L_3
) ;
F_1 ( V_26 , L_37 ,
F_7 ( V_26 , & V_28 -> V_47 ) ,
V_5 , V_6 ) ;
F_1 ( V_26 , L_38 ,
F_7 ( V_26 , & V_28 -> V_48 ) ,
V_5 , V_6 ) ;
F_3 ( V_26 , L_39 ,
F_7 ( V_26 , & V_28 -> V_49 ) ,
V_5 , V_6 ) ;
F_3 ( V_26 , L_40 ,
F_7 ( V_26 , & V_28 -> V_50 ) ,
V_5 , V_6 ) ;
F_3 ( V_26 , L_41 ,
F_7 ( V_26 , & V_28 -> V_51 ) ,
V_5 , V_6 ) ;
F_3 ( V_26 , L_42 ,
F_7 ( V_26 , & V_28 -> V_52 ) ,
V_5 , V_6 ) ;
F_3 ( V_26 , L_43 ,
F_7 ( V_26 , & V_28 -> V_53 ) ,
V_5 , V_6 ) ;
F_3 ( V_26 , L_44 ,
F_7 ( V_26 , & V_28 -> V_54 ) , V_5 , V_6 ) ;
}
static void
F_8 (
struct V_1 * V_26 ,
int V_55 ,
char * * V_5 ,
unsigned * V_6 )
{
T_1 V_29 , V_56 ;
V_29 = F_9 ( V_26 ) ;
if ( V_29 == ~ ( T_1 ) 0 )
return;
if ( V_55 ) {
F_2 ( V_26 , V_5 , V_6 ,
L_45 , V_29 ,
( ( V_29 & V_57 ) >> 24 ) & 0xff ,
( V_29 & V_58 ) ? L_46 : L_3 ,
( V_29 & V_59 ) ? L_47 : L_3 ,
( V_29 & V_60 ) ? L_48 : L_3 ,
( V_29 & V_61 ) ? L_49 : L_3 ,
( V_29 & V_62 ) ? L_50 : L_3 ,
( V_29 & V_63 ) , V_26 -> V_64
) ;
V_29 = F_10 ( V_26 ) ;
F_2 ( V_26 , V_5 , V_6 ,
L_51 ,
V_29 ,
( V_29 & V_65 ) >> 16 ,
( V_29 & V_66 )
) ;
V_29 = F_11 ( V_26 ) ;
F_2 ( V_26 , V_5 , V_6 ,
L_52 ,
V_29 ,
( V_29 & V_67 ) ? L_53 : L_3 ,
( V_29 & V_68 ) ? L_54 : L_3 ,
( V_29 & V_69 ) ? L_55 : L_3 ,
( V_29 & V_70 ) ? L_56 : L_3 ,
( V_29 & V_71 ) ? L_57 : L_3 ,
( V_29 & V_72 ) ? L_58 : L_3
) ;
}
for ( V_56 = 0 ; V_56 < V_26 -> V_64 ; V_56 ++ ) {
V_29 = F_12 ( V_26 , V_56 ) ;
F_13 ( V_26 , V_56 , V_29 , V_5 , V_6 ) ;
}
}
static void F_14 ( struct V_1 * V_26 )
{
F_15 ( V_26 , L_59 ) ;
F_6 ( V_26 , NULL , NULL ) ;
if ( V_26 -> V_73 )
F_15 ( V_26 ,
L_60 , F_16 ( V_26 ) ) ;
F_8 ( V_26 , 1 , NULL , NULL ) ;
}
static void F_17 ( const struct V_1 * V_2 , const char * V_3 ,
const struct V_74 * V_74 )
{
T_1 V_75 = F_18 ( V_2 , & V_74 -> V_76 ) ;
F_15 ( V_2 , L_61 ,
V_3 , V_74 ,
( V_75 & V_77 ) ? L_62 : L_3 ,
V_74 -> V_78 , V_74 -> V_79 ,
F_18 ( V_2 , & V_74 -> V_80 ) ) ;
if ( ( V_75 & V_81 ) == 0 ) {
const char * V_82 , * V_83 ;
T_1 V_84 , V_85 ;
switch ( V_75 & V_86 ) {
case V_87 : V_82 = V_88 ; break;
case V_89 : V_82 = V_90 ; break;
case V_91 : V_82 = L_63 ; break;
default: V_82 = L_64 ; break;
}
switch ( V_75 & V_92 ) {
case V_93 : V_83 = L_65 ; break;
case V_94 : V_83 = L_66 ; break;
case V_95 : V_83 = L_67 ; break;
default: V_83 = L_68 ; break;
}
F_15 ( V_2 , L_69 , V_75 ,
F_19 ( V_75 ) , V_82 ,
( V_75 & V_96 ) >> 21 , V_83 ,
( V_75 & V_97 ) ? L_70 : L_3 ) ;
V_84 = F_18 ( V_2 , & V_74 -> V_98 ) ;
V_85 = F_18 ( V_2 , & V_74 -> V_99 ) ;
F_15 ( V_2 , L_71 , V_84 , V_85 ,
V_84 ? ( V_85 + 1 - V_84 ) : 0 ) ;
} else {
unsigned V_56 ;
F_15 ( V_2 , L_72 , V_75 ,
F_19 ( V_75 ) ,
( V_75 >> 24 ) & 0x07 ,
( V_75 & V_96 ) >> 21 ,
V_75 & 0x0000ffff ) ;
F_15 ( V_2 , L_73 ,
F_18 ( V_2 , & V_74 -> V_98 ) & ~ 0x0fff ,
F_18 ( V_2 , & V_74 -> V_99 ) ) ;
for ( V_56 = 0 ; V_56 < V_100 ; V_56 ++ ) {
T_3 V_101 = F_20 ( V_2 , V_74 , V_56 ) ;
int V_102 = ( V_101 >> 12 ) & 0x0f ;
F_15 ( V_2 , L_74 , V_56 ,
V_101 , V_102 ,
( V_102 >= 0x0e ) ? L_75 : L_76 ,
V_101 & 0x0fff ) ;
}
}
}
static void T_4
F_21 ( const struct V_1 * V_2 , const char * V_3 ,
const struct V_103 * V_103 , int V_55 )
{
T_1 V_75 = F_22 ( V_2 , V_103 -> V_76 ) ;
char * type = L_3 ;
F_15 ( V_2 , L_77 ,
V_3 ,
V_103 , V_103 -> V_17 , F_23 ( V_103 -> type ) ,
F_18 ( V_2 , & V_103 -> V_104 ) ) ;
switch ( V_75 & ( V_105 | V_106 ) ) {
case V_106 : type = L_78 ; break;
case V_105 : type = L_79 ; break;
}
F_15 ( V_2 ,
L_80 , V_75 ,
0x03ff & ( V_75 >> 16 ) ,
( V_75 & V_107 ) ? L_81 : L_3 ,
( V_75 & V_108 ) ? L_82 : L_3 ,
( V_75 & V_109 ) ? L_83 : L_3 ,
( V_75 & V_110 ) ? L_84 : L_3 ,
0x000f & ( V_75 >> 7 ) ,
type ,
0x007f & V_75 ) ;
V_75 = F_18 ( V_2 , & V_103 -> V_111 ) ;
F_15 ( V_2 , L_85 ,
V_75 ,
( V_75 & V_112 ) ? V_90 : V_88 ,
( V_75 & V_113 ) ? L_86 : L_3 ,
F_18 ( V_2 , & V_103 -> V_114 ) ,
V_55 ? L_3 : L_87 ) ;
if ( V_55 ) {
struct V_115 * V_75 ;
F_24 (tmp, &ed->td_list) {
struct V_74 * V_74 ;
V_74 = F_25 ( V_75 , struct V_74 , V_116 ) ;
F_17 ( V_2 , L_88 , V_74 ) ;
}
}
}
static T_5
F_26 ( struct V_1 * V_2 , char * V_117 , T_6 V_118 , struct V_103 * V_103 )
{
unsigned V_29 , V_6 = V_118 ;
if ( ! V_103 )
return 0 ;
while ( V_103 -> V_119 )
V_103 = V_103 -> V_119 ;
while ( V_103 ) {
T_1 V_120 = F_22 ( V_2 , V_103 -> V_76 ) ;
T_1 V_121 = F_22 ( V_2 , V_103 -> V_111 ) ;
struct V_115 * V_122 ;
struct V_74 * V_74 ;
V_29 = F_27 ( V_117 , V_6 ,
L_89 ,
V_103 ,
( V_120 & V_110 ) ? 'l' : 'f' ,
V_120 & 0x7f ,
( V_120 >> 7 ) & 0xf ,
( V_120 & V_105 ) ? L_90 : L_91 ,
0x03ff & ( V_120 >> 16 ) ,
V_120 ,
( V_120 & V_109 ) ? L_92 : L_3 ,
( V_121 & V_113 ) ? L_93 : L_3 ,
( V_121 & V_112 ) ? V_90 : V_88 ) ;
V_6 -= V_29 ;
V_117 += V_29 ;
F_24 (entry, &ed->td_list) {
T_1 V_84 , V_85 ;
V_74 = F_25 ( V_122 , struct V_74 , V_116 ) ;
V_120 = F_18 ( V_2 , & V_74 -> V_76 ) ;
V_84 = F_18 ( V_2 , & V_74 -> V_98 ) ;
V_85 = F_18 ( V_2 , & V_74 -> V_99 ) ;
V_29 = F_27 (buf, size,
L_94 ,
td,
({ char *pid;
switch (info & TD_DP) {
case TD_DP_SETUP: pid = L_95; break;
case TD_DP_IN: pid = L_90; break;
case TD_DP_OUT: pid = L_91; break;
default: pid = L_64; break;
} pid;}),
cbp ? (be + 1 - cbp) : 0 ,
TD_CC_GET (info), td->urb, info) ;
V_6 -= V_29 ;
V_117 += V_29 ;
}
V_29 = F_27 ( V_117 , V_6 , L_96 ) ;
V_6 -= V_29 ;
V_117 += V_29 ;
V_103 = V_103 -> V_123 ;
}
return V_118 - V_6 ;
}
static T_5 F_28 ( struct V_124 * V_117 )
{
struct V_1 * V_2 ;
T_6 V_29 , V_6 ;
unsigned long V_125 ;
V_2 = V_117 -> V_2 ;
V_6 = V_126 ;
F_29 ( & V_2 -> V_127 , V_125 ) ;
V_29 = F_26 ( V_2 , V_117 -> V_128 , V_6 , V_2 -> V_129 ) ;
V_29 += F_26 ( V_2 , V_117 -> V_128 + V_29 , V_6 - V_29 ,
V_2 -> V_130 ) ;
F_30 ( & V_2 -> V_127 , V_125 ) ;
return V_29 ;
}
static T_5 F_31 ( struct V_124 * V_117 )
{
struct V_1 * V_2 ;
struct V_103 * * V_131 , * V_103 ;
unsigned long V_125 ;
unsigned V_29 , V_6 , V_132 ;
char * V_5 ;
unsigned V_56 ;
if ( ! ( V_131 = F_32 ( V_133 * sizeof *V_131 , V_134 ) ) )
return 0 ;
V_132 = 0 ;
V_2 = V_117 -> V_2 ;
V_5 = V_117 -> V_128 ;
V_6 = V_126 ;
V_29 = F_27 ( V_5 , V_6 , L_97 , V_135 ) ;
V_6 -= V_29 ;
V_5 += V_29 ;
F_29 ( & V_2 -> V_127 , V_125 ) ;
for ( V_56 = 0 ; V_56 < V_135 ; V_56 ++ ) {
if ( ! ( V_103 = V_2 -> V_136 [ V_56 ] ) )
continue;
V_29 = F_27 ( V_5 , V_6 , L_98 , V_56 , V_2 -> V_137 [ V_56 ] ) ;
V_6 -= V_29 ;
V_5 += V_29 ;
do {
V_29 = F_27 ( V_5 , V_6 , L_99 ,
V_103 -> V_138 , V_103 ) ;
V_6 -= V_29 ;
V_5 += V_29 ;
for ( V_29 = 0 ; V_29 < V_132 ; V_29 ++ ) {
if ( V_131 [ V_29 ] == V_103 )
break;
}
if ( V_29 == V_132 ) {
T_1 V_120 = F_22 ( V_2 , V_103 -> V_76 ) ;
struct V_115 * V_122 ;
unsigned V_139 = 0 ;
F_24 (entry, &ed->td_list)
V_139 ++ ;
V_29 = F_27 ( V_5 , V_6 ,
L_100
L_101 ,
( V_120 & V_110 ) ? 'l' : 'f' ,
V_120 & 0x7f ,
( V_120 >> 7 ) & 0xf ,
( V_120 & V_105 ) ? L_90 : L_91 ,
( V_120 & V_108 ) ? L_102 : L_103 ,
V_139 ,
0x03ff & ( V_120 >> 16 ) ,
V_120 ,
( V_120 & V_109 ) ? L_104 : L_3 ,
( V_103 -> V_111 &
F_33 ( V_2 , V_113 ) ) ?
L_93 : L_3 ) ;
V_6 -= V_29 ;
V_5 += V_29 ;
if ( V_132 < V_133 )
V_131 [ V_132 ++ ] = V_103 ;
V_103 = V_103 -> V_123 ;
} else {
V_29 = 0 ;
V_103 = NULL ;
}
} while ( V_103 );
V_29 = F_27 ( V_5 , V_6 , L_96 ) ;
V_6 -= V_29 ;
V_5 += V_29 ;
}
F_30 ( & V_2 -> V_127 , V_125 ) ;
F_34 ( V_131 ) ;
return V_126 - V_6 ;
}
static T_5 F_35 ( struct V_124 * V_117 )
{
struct V_140 * V_141 ;
struct V_1 * V_2 ;
struct V_27 T_2 * V_28 ;
unsigned long V_125 ;
unsigned V_29 , V_6 ;
char * V_5 ;
T_1 V_142 ;
V_2 = V_117 -> V_2 ;
V_141 = F_36 ( V_2 ) ;
V_28 = V_2 -> V_28 ;
V_5 = V_117 -> V_128 ;
V_6 = V_126 ;
F_29 ( & V_2 -> V_127 , V_125 ) ;
F_37 ( V_2 , & V_5 , & V_6 ,
L_105
L_106
L_106 ,
V_141 -> V_143 . V_26 -> V_144 -> V_145 ,
F_38 ( V_141 -> V_143 . V_26 ) ,
V_141 -> V_146 ,
V_147 ) ;
if ( ! F_39 ( V_141 ) ) {
V_6 -= F_27 ( V_5 , V_6 ,
L_107 ) ;
goto V_148;
}
F_6 ( V_2 , & V_5 , & V_6 ) ;
if ( V_2 -> V_73 )
F_37 ( V_2 , & V_5 , & V_6 ,
L_108 , F_16 ( V_2 ) ) ;
V_142 = F_7 ( V_2 , & V_28 -> V_149 ) ;
V_29 = F_27 ( V_5 , V_6 ,
L_109 ,
V_142 , ( V_142 >> 31 ) ? L_110 : L_3 ,
( V_142 >> 16 ) & 0xefff , V_142 & 0xffff ) ;
V_6 -= V_29 ;
V_5 += V_29 ;
V_142 = F_7 ( V_2 , & V_28 -> V_150 ) ;
V_29 = F_27 ( V_5 , V_6 , L_111 ,
V_142 , ( V_142 >> 31 ) ? L_112 : L_3 ,
V_142 & 0x3fff ) ;
V_6 -= V_29 ;
V_5 += V_29 ;
V_142 = F_7 ( V_2 , & V_28 -> V_151 ) ;
V_29 = F_27 ( V_5 , V_6 , L_113 ,
V_142 & 0x3fff ) ;
V_6 -= V_29 ;
V_5 += V_29 ;
V_142 = F_7 ( V_2 , & V_28 -> V_152 ) ;
V_29 = F_27 ( V_5 , V_6 , L_114 ,
V_142 & 0x3fff ) ;
V_6 -= V_29 ;
V_5 += V_29 ;
V_29 = F_27 ( V_5 , V_6 , L_115 ,
F_40 ( F_36 ( V_2 ) ) ? L_116 : L_117 ) ;
V_6 -= V_29 ;
V_5 += V_29 ;
F_8 ( V_2 , 1 , & V_5 , & V_6 ) ;
V_148:
F_30 ( & V_2 -> V_127 , V_125 ) ;
return V_126 - V_6 ;
}
static struct V_124 * F_41 ( struct V_1 * V_2 ,
T_5 (* F_42)( struct V_124 * ) )
{
struct V_124 * V_117 ;
V_117 = F_43 ( sizeof( struct V_124 ) , V_153 ) ;
if ( V_117 ) {
V_117 -> V_2 = V_2 ;
V_117 -> F_42 = F_42 ;
F_44 ( & V_117 -> V_154 ) ;
}
return V_117 ;
}
static int F_45 ( struct V_124 * V_117 )
{
int V_155 = 0 ;
if ( ! V_117 -> V_128 )
V_117 -> V_128 = ( char * ) F_46 ( V_153 ) ;
if ( ! V_117 -> V_128 ) {
V_155 = - V_156 ;
goto V_157;
}
V_155 = V_117 -> F_42 ( V_117 ) ;
if ( V_155 >= 0 ) {
V_117 -> V_118 = V_155 ;
V_155 = 0 ;
}
V_157:
return V_155 ;
}
static T_5 F_47 ( struct V_158 * V_158 , char T_7 * V_159 ,
T_6 V_160 , T_8 * V_161 )
{
struct V_124 * V_117 = V_158 -> V_162 ;
int V_155 = 0 ;
F_48 ( & V_117 -> V_154 ) ;
if ( V_117 -> V_118 == 0 ) {
V_155 = F_45 ( V_117 ) ;
if ( V_155 != 0 ) {
F_49 ( & V_117 -> V_154 ) ;
goto V_157;
}
}
F_49 ( & V_117 -> V_154 ) ;
V_155 = F_50 ( V_159 , V_160 , V_161 ,
V_117 -> V_128 , V_117 -> V_118 ) ;
V_157:
return V_155 ;
}
static int F_51 ( struct V_163 * V_163 , struct V_158 * V_158 )
{
struct V_124 * V_117 = V_158 -> V_162 ;
if ( V_117 ) {
if ( V_117 -> V_128 )
F_52 ( ( unsigned long ) V_117 -> V_128 ) ;
F_34 ( V_117 ) ;
}
return 0 ;
}
static int F_53 ( struct V_163 * V_163 , struct V_158 * V_158 )
{
V_158 -> V_162 = F_41 ( V_163 -> V_164 , F_28 ) ;
return V_158 -> V_162 ? 0 : - V_156 ;
}
static int F_54 ( struct V_163 * V_163 , struct V_158 * V_158 )
{
V_158 -> V_162 = F_41 ( V_163 -> V_164 ,
F_31 ) ;
return V_158 -> V_162 ? 0 : - V_156 ;
}
static int F_55 ( struct V_163 * V_163 , struct V_158 * V_158 )
{
V_158 -> V_162 = F_41 ( V_163 -> V_164 ,
F_35 ) ;
return V_158 -> V_162 ? 0 : - V_156 ;
}
static inline void F_56 ( struct V_1 * V_2 )
{
struct V_165 * V_144 = & F_36 ( V_2 ) -> V_143 ;
V_2 -> V_166 = F_57 ( V_144 -> V_167 , V_168 ) ;
if ( ! V_2 -> V_166 )
goto V_169;
V_2 -> V_170 = F_58 ( L_118 , V_171 ,
V_2 -> V_166 , V_2 ,
& V_172 ) ;
if ( ! V_2 -> V_170 )
goto V_173;
V_2 -> V_174 = F_58 ( L_119 , V_171 ,
V_2 -> V_166 , V_2 ,
& V_175 ) ;
if ( ! V_2 -> V_174 )
goto V_176;
V_2 -> V_177 = F_58 ( L_120 , V_171 ,
V_2 -> V_166 , V_2 ,
& V_178 ) ;
if ( ! V_2 -> V_177 )
goto V_179;
F_15 ( V_2 , L_121 ) ;
return;
V_179:
F_59 ( V_2 -> V_174 ) ;
V_176:
F_59 ( V_2 -> V_170 ) ;
V_173:
F_59 ( V_2 -> V_166 ) ;
V_169:
V_2 -> V_174 = NULL ;
V_2 -> V_170 = NULL ;
V_2 -> V_166 = NULL ;
}
static inline void F_60 ( struct V_1 * V_2 )
{
F_59 ( V_2 -> V_177 ) ;
F_59 ( V_2 -> V_174 ) ;
F_59 ( V_2 -> V_170 ) ;
F_59 ( V_2 -> V_166 ) ;
}
