static void T_1
F_1 ( struct V_1 * V_1 , char * V_2 , int V_3 , int V_4 )
{
unsigned int V_5 = V_1 -> V_5 ;
if ( ! V_1 -> V_6 || ! V_1 -> V_6 -> V_7 ) {
F_2 ( L_1 , V_2 ) ;
return;
}
#ifndef F_3
if ( V_4 != 0 )
#endif
F_2 ( L_2 ,
V_2 ,
V_1 ,
F_4 ( V_5 ) ,
F_5 ( V_5 ) ,
F_6 ( V_5 ) ? L_3 : L_4 ,
F_7 ( V_5 ) ,
V_1 -> V_8 ,
V_1 -> V_9 ,
V_1 -> V_10 ,
V_4 ) ;
#ifdef F_3
if ( ! V_3 ) {
int V_11 , V_12 ;
if ( F_8 ( V_5 ) ) {
F_9 ( V_13 L_5 , __FILE__ ) ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ )
F_9 ( L_6 , ( ( V_14 * ) V_1 -> V_15 ) [ V_11 ] ) ;
F_9 ( L_7 ) ;
}
if ( V_1 -> V_10 > 0 && V_1 -> V_16 ) {
F_9 ( V_13 L_8 , __FILE__ ,
V_1 -> V_9 ,
V_1 -> V_10 ) ;
V_12 = F_6 ( V_5 ) ?
V_1 -> V_10 : V_1 -> V_9 ;
for ( V_11 = 0 ; V_11 < 16 && V_11 < V_12 ; V_11 ++ )
F_9 ( L_6 , ( ( V_14 * ) V_1 -> V_16 ) [ V_11 ] ) ;
F_9 ( L_9 , V_11 < V_12 ? L_10 : L_11 , V_4 ) ;
}
}
#endif
}
static void F_10 (
struct V_17 * V_18 ,
char * V_19 ,
T_2 V_20 ,
char * * V_21 ,
unsigned * V_22 )
{
F_11 ( V_18 , V_21 , V_22 , L_12 ,
V_19 ,
V_20 ,
( V_20 & V_23 ) ? L_13 : L_11 ,
( V_20 & V_24 ) ? L_14 : L_11 ,
( V_20 & V_25 ) ? L_15 : L_11 ,
( V_20 & V_26 ) ? L_16 : L_11 ,
( V_20 & V_27 ) ? L_17 : L_11 ,
( V_20 & V_28 ) ? L_18 : L_11 ,
( V_20 & V_29 ) ? L_19 : L_11 ,
( V_20 & V_30 ) ? L_20 : L_11 ,
( V_20 & V_31 ) ? L_21 : L_11
) ;
}
static void F_12 (
struct V_17 * V_18 ,
char * V_19 ,
T_2 V_32 ,
char * * V_21 ,
unsigned * V_22 )
{
if ( V_32 )
F_11 ( V_18 , V_21 , V_22 , L_22 , V_19 , V_32 ) ;
}
static char * F_13 ( int V_33 )
{
switch ( V_33 ) {
case V_34 : return L_23 ;
case V_35 : return L_24 ;
case V_36 : return L_25 ;
case V_37 : return L_26 ;
}
return L_27 ;
}
static const char * F_14 ( struct V_17 * V_18 )
{
switch ( V_18 -> V_38 ) {
case V_39 :
return L_28 ;
case V_40 :
return L_29 ;
case V_41 :
return L_30 ;
}
return L_27 ;
}
static void
F_15 ( struct V_17 * V_42 , char * * V_21 , unsigned * V_22 )
{
struct V_43 T_3 * V_44 = V_42 -> V_44 ;
T_2 V_45 ;
V_45 = F_16 ( V_42 , & V_44 -> V_46 ) & 0xff ;
F_11 ( V_42 , V_21 , V_22 ,
L_31 ,
0x03 & ( V_45 >> 4 ) , ( V_45 & 0x0f ) ,
( V_45 & 0x0100 ) ? L_32 : L_33 ,
F_14 ( V_42 ) ) ;
V_45 = F_16 ( V_42 , & V_44 -> V_47 ) ;
F_11 ( V_42 , V_21 , V_22 ,
L_34 ,
V_45 ,
( V_45 & V_48 ) ? L_35 : L_11 ,
( V_45 & V_49 ) ? L_36 : L_11 ,
( V_45 & V_50 ) ? L_37 : L_11 ,
F_13 ( V_45 & V_51 ) ,
( V_45 & V_52 ) ? L_38 : L_11 ,
( V_45 & V_53 ) ? L_39 : L_11 ,
( V_45 & V_54 ) ? L_40 : L_11 ,
( V_45 & V_55 ) ? L_41 : L_11 ,
V_45 & V_56
) ;
V_45 = F_16 ( V_42 , & V_44 -> V_57 ) ;
F_11 ( V_42 , V_21 , V_22 ,
L_42 , V_45 ,
( V_45 & V_58 ) >> 16 ,
( V_45 & V_59 ) ? L_43 : L_11 ,
( V_45 & V_60 ) ? L_44 : L_11 ,
( V_45 & V_61 ) ? L_45 : L_11 ,
( V_45 & V_62 ) ? L_46 : L_11
) ;
F_10 ( V_42 , L_47 ,
F_16 ( V_42 , & V_44 -> V_63 ) ,
V_21 , V_22 ) ;
F_10 ( V_42 , L_48 ,
F_16 ( V_42 , & V_44 -> V_64 ) ,
V_21 , V_22 ) ;
F_12 ( V_42 , L_49 ,
F_16 ( V_42 , & V_44 -> V_65 ) ,
V_21 , V_22 ) ;
F_12 ( V_42 , L_50 ,
F_16 ( V_42 , & V_44 -> V_66 ) ,
V_21 , V_22 ) ;
F_12 ( V_42 , L_51 ,
F_16 ( V_42 , & V_44 -> V_67 ) ,
V_21 , V_22 ) ;
F_12 ( V_42 , L_52 ,
F_16 ( V_42 , & V_44 -> V_68 ) ,
V_21 , V_22 ) ;
F_12 ( V_42 , L_53 ,
F_16 ( V_42 , & V_44 -> V_69 ) ,
V_21 , V_22 ) ;
F_12 ( V_42 , L_54 ,
F_16 ( V_42 , & V_44 -> V_70 ) , V_21 , V_22 ) ;
}
static void
F_17 (
struct V_17 * V_42 ,
int V_71 ,
char * * V_21 ,
unsigned * V_22 )
{
T_2 V_45 , V_11 ;
V_45 = F_18 ( V_42 ) ;
if ( V_45 == ~ ( T_2 ) 0 )
return;
if ( V_71 ) {
F_11 ( V_42 , V_21 , V_22 ,
L_55 , V_45 ,
( ( V_45 & V_72 ) >> 24 ) & 0xff ,
( V_45 & V_73 ) ? L_56 : L_11 ,
( V_45 & V_74 ) ? L_57 : L_11 ,
( V_45 & V_75 ) ? L_58 : L_11 ,
( V_45 & V_76 ) ? L_59 : L_11 ,
( V_45 & V_77 ) ? L_60 : L_11 ,
( V_45 & V_78 ) , V_42 -> V_79
) ;
V_45 = F_19 ( V_42 ) ;
F_11 ( V_42 , V_21 , V_22 ,
L_61 ,
V_45 ,
( V_45 & V_80 ) >> 16 ,
( V_45 & V_81 )
) ;
V_45 = F_20 ( V_42 ) ;
F_11 ( V_42 , V_21 , V_22 ,
L_62 ,
V_45 ,
( V_45 & V_82 ) ? L_63 : L_11 ,
( V_45 & V_83 ) ? L_64 : L_11 ,
( V_45 & V_84 ) ? L_65 : L_11 ,
( V_45 & V_85 ) ? L_66 : L_11 ,
( V_45 & V_86 ) ? L_67 : L_11 ,
( V_45 & V_87 ) ? L_68 : L_11
) ;
}
for ( V_11 = 0 ; V_11 < V_42 -> V_79 ; V_11 ++ ) {
V_45 = F_21 ( V_42 , V_11 ) ;
F_22 ( V_42 , V_11 , V_45 , V_21 , V_22 ) ;
}
}
static void F_23 ( struct V_17 * V_42 , int V_71 )
{
F_24 ( V_42 , L_69 ) ;
F_15 ( V_42 , NULL , NULL ) ;
if ( V_42 -> V_88 )
F_24 ( V_42 ,
L_70 , F_25 ( V_42 ) ) ;
F_17 ( V_42 , 1 , NULL , NULL ) ;
}
static void F_26 ( const struct V_17 * V_18 , const char * V_19 ,
const struct V_89 * V_89 )
{
T_2 V_90 = F_27 ( V_18 , & V_89 -> V_91 ) ;
F_24 ( V_18 , L_71 ,
V_19 , V_89 ,
( V_90 & V_92 ) ? L_72 : L_11 ,
V_89 -> V_1 , V_89 -> V_93 ,
F_27 ( V_18 , & V_89 -> V_94 ) ) ;
if ( ( V_90 & V_95 ) == 0 ) {
const char * V_96 , * V_97 ;
T_2 V_98 , V_99 ;
switch ( V_90 & V_100 ) {
case V_101 : V_96 = V_102 ; break;
case V_103 : V_96 = V_104 ; break;
case V_105 : V_96 = L_73 ; break;
default: V_96 = L_74 ; break;
}
switch ( V_90 & V_106 ) {
case V_107 : V_97 = L_75 ; break;
case V_108 : V_97 = L_76 ; break;
case V_109 : V_97 = L_77 ; break;
default: V_97 = L_78 ; break;
}
F_24 ( V_18 , L_79 , V_90 ,
F_28 ( V_90 ) , V_96 ,
( V_90 & V_110 ) >> 21 , V_97 ,
( V_90 & V_111 ) ? L_80 : L_11 ) ;
V_98 = F_27 ( V_18 , & V_89 -> V_112 ) ;
V_99 = F_27 ( V_18 , & V_89 -> V_113 ) ;
F_24 ( V_18 , L_81 , V_98 , V_99 ,
V_98 ? ( V_99 + 1 - V_98 ) : 0 ) ;
} else {
unsigned V_11 ;
F_24 ( V_18 , L_82 , V_90 ,
F_28 ( V_90 ) ,
( V_90 >> 24 ) & 0x07 ,
( V_90 & V_110 ) >> 21 ,
V_90 & 0x0000ffff ) ;
F_24 ( V_18 , L_83 ,
F_27 ( V_18 , & V_89 -> V_112 ) & ~ 0x0fff ,
F_27 ( V_18 , & V_89 -> V_113 ) ) ;
for ( V_11 = 0 ; V_11 < V_114 ; V_11 ++ ) {
T_4 V_115 = F_29 ( V_18 , V_89 , V_11 ) ;
int V_116 = ( V_115 >> 12 ) & 0x0f ;
F_24 ( V_18 , L_84 , V_11 ,
V_115 , V_116 ,
( V_116 >= 0x0e ) ? L_85 : L_86 ,
V_115 & 0x0fff ) ;
}
}
}
static void T_1
F_30 ( const struct V_17 * V_18 , const char * V_19 ,
const struct V_117 * V_117 , int V_71 )
{
T_2 V_90 = F_31 ( V_18 , V_117 -> V_91 ) ;
char * type = L_11 ;
F_24 ( V_18 , L_87 ,
V_19 ,
V_117 , V_117 -> V_33 , F_32 ( V_117 -> type ) ,
F_27 ( V_18 , & V_117 -> V_118 ) ) ;
switch ( V_90 & ( V_119 | V_120 ) ) {
case V_120 : type = L_88 ; break;
case V_119 : type = L_89 ; break;
}
F_24 ( V_18 ,
L_90 , V_90 ,
0x03ff & ( V_90 >> 16 ) ,
( V_90 & V_121 ) ? L_91 : L_11 ,
( V_90 & V_122 ) ? L_92 : L_11 ,
( V_90 & V_123 ) ? L_93 : L_11 ,
( V_90 & V_124 ) ? L_94 : L_11 ,
0x000f & ( V_90 >> 7 ) ,
type ,
0x007f & V_90 ) ;
V_90 = F_27 ( V_18 , & V_117 -> V_125 ) ;
F_24 ( V_18 , L_95 ,
V_90 ,
( V_90 & V_126 ) ? V_104 : V_102 ,
( V_90 & V_127 ) ? L_96 : L_11 ,
F_27 ( V_18 , & V_117 -> V_128 ) ,
V_71 ? L_11 : L_97 ) ;
if ( V_71 ) {
struct V_129 * V_90 ;
F_33 (tmp, &ed->td_list) {
struct V_89 * V_89 ;
V_89 = F_34 ( V_90 , struct V_89 , V_130 ) ;
F_26 ( V_18 , L_98 , V_89 ) ;
}
}
}
static inline void F_23 ( struct V_17 * V_42 , int V_71 ) {}
static inline void F_35 ( struct V_17 * V_7 ) { }
static inline void F_36 ( struct V_17 * V_7 ) { }
static T_5
F_37 ( struct V_17 * V_18 , char * V_131 , T_6 V_132 , struct V_117 * V_117 )
{
unsigned V_45 , V_22 = V_132 ;
if ( ! V_117 )
return 0 ;
while ( V_117 -> V_133 )
V_117 = V_117 -> V_133 ;
while ( V_117 ) {
T_2 V_134 = F_31 ( V_18 , V_117 -> V_91 ) ;
T_2 V_135 = F_31 ( V_18 , V_117 -> V_125 ) ;
struct V_129 * V_136 ;
struct V_89 * V_89 ;
V_45 = F_38 ( V_131 , V_22 ,
L_99 ,
V_117 ,
( V_134 & V_124 ) ? 'l' : 'f' ,
V_134 & 0x7f ,
( V_134 >> 7 ) & 0xf ,
( V_134 & V_119 ) ? L_4 : L_3 ,
0x03ff & ( V_134 >> 16 ) ,
V_134 ,
( V_134 & V_123 ) ? L_100 : L_11 ,
( V_135 & V_127 ) ? L_101 : L_11 ,
( V_135 & V_126 ) ? V_104 : V_102 ) ;
V_22 -= V_45 ;
V_131 += V_45 ;
F_33 (entry, &ed->td_list) {
T_2 V_98 , V_99 ;
V_89 = F_34 ( V_136 , struct V_89 , V_130 ) ;
V_134 = F_27 ( V_18 , & V_89 -> V_91 ) ;
V_98 = F_27 ( V_18 , & V_89 -> V_112 ) ;
V_99 = F_27 ( V_18 , & V_89 -> V_113 ) ;
V_45 = F_38 (buf, size,
L_102 ,
td,
({ char *pid;
switch (info & TD_DP) {
case TD_DP_SETUP: pid = L_103; break;
case TD_DP_IN: pid = L_4; break;
case TD_DP_OUT: pid = L_3; break;
default: pid = L_74; break;
} pid;}),
cbp ? (be + 1 - cbp) : 0 ,
TD_CC_GET (info), td->urb, info) ;
V_22 -= V_45 ;
V_131 += V_45 ;
}
V_45 = F_38 ( V_131 , V_22 , L_7 ) ;
V_22 -= V_45 ;
V_131 += V_45 ;
V_117 = V_117 -> V_137 ;
}
return V_132 - V_22 ;
}
static T_5 F_39 ( struct V_138 * V_131 )
{
struct V_17 * V_18 ;
T_6 V_45 ;
unsigned long V_139 ;
V_18 = V_131 -> V_18 ;
F_40 ( & V_18 -> V_140 , V_139 ) ;
V_45 = F_37 ( V_18 , V_131 -> V_141 , V_131 -> V_132 , V_18 -> V_142 ) ;
V_45 += F_37 ( V_18 , V_131 -> V_141 + V_45 , V_131 -> V_132 - V_45 ,
V_18 -> V_143 ) ;
F_41 ( & V_18 -> V_140 , V_139 ) ;
return V_45 ;
}
static T_5 F_42 ( struct V_138 * V_131 )
{
struct V_17 * V_18 ;
struct V_117 * * V_144 , * V_117 ;
unsigned long V_139 ;
unsigned V_45 , V_22 , V_145 ;
char * V_21 ;
unsigned V_11 ;
if ( ! ( V_144 = F_43 ( V_146 * sizeof *V_144 , V_147 ) ) )
return 0 ;
V_145 = 0 ;
V_18 = V_131 -> V_18 ;
V_21 = V_131 -> V_141 ;
V_22 = V_148 ;
V_45 = F_38 ( V_21 , V_22 , L_104 , V_149 ) ;
V_22 -= V_45 ;
V_21 += V_45 ;
F_40 ( & V_18 -> V_140 , V_139 ) ;
for ( V_11 = 0 ; V_11 < V_149 ; V_11 ++ ) {
if ( ! ( V_117 = V_18 -> V_150 [ V_11 ] ) )
continue;
V_45 = F_38 ( V_21 , V_22 , L_105 , V_11 , V_18 -> V_151 [ V_11 ] ) ;
V_22 -= V_45 ;
V_21 += V_45 ;
do {
V_45 = F_38 ( V_21 , V_22 , L_106 ,
V_117 -> V_152 , V_117 ) ;
V_22 -= V_45 ;
V_21 += V_45 ;
for ( V_45 = 0 ; V_45 < V_145 ; V_45 ++ ) {
if ( V_144 [ V_45 ] == V_117 )
break;
}
if ( V_45 == V_145 ) {
T_2 V_134 = F_31 ( V_18 , V_117 -> V_91 ) ;
struct V_129 * V_136 ;
unsigned V_153 = 0 ;
F_33 (entry, &ed->td_list)
V_153 ++ ;
V_45 = F_38 ( V_21 , V_22 ,
L_107
L_108 ,
( V_134 & V_124 ) ? 'l' : 'f' ,
V_134 & 0x7f ,
( V_134 >> 7 ) & 0xf ,
( V_134 & V_119 ) ? L_4 : L_3 ,
( V_134 & V_122 ) ? L_109 : L_110 ,
V_153 ,
0x03ff & ( V_134 >> 16 ) ,
V_134 ,
( V_134 & V_123 ) ? L_111 : L_11 ,
( V_117 -> V_125 &
F_44 ( V_18 , V_127 ) ) ?
L_101 : L_11 ) ;
V_22 -= V_45 ;
V_21 += V_45 ;
if ( V_145 < V_146 )
V_144 [ V_145 ++ ] = V_117 ;
V_117 = V_117 -> V_137 ;
} else {
V_45 = 0 ;
V_117 = NULL ;
}
} while ( V_117 );
V_45 = F_38 ( V_21 , V_22 , L_7 ) ;
V_22 -= V_45 ;
V_21 += V_45 ;
}
F_41 ( & V_18 -> V_140 , V_139 ) ;
F_45 ( V_144 ) ;
return V_148 - V_22 ;
}
static T_5 F_46 ( struct V_138 * V_131 )
{
struct V_154 * V_155 ;
struct V_17 * V_18 ;
struct V_43 T_3 * V_44 ;
unsigned long V_139 ;
unsigned V_45 , V_22 ;
char * V_21 ;
T_2 V_156 ;
V_18 = V_131 -> V_18 ;
V_155 = F_47 ( V_18 ) ;
V_44 = V_18 -> V_44 ;
V_21 = V_131 -> V_141 ;
V_22 = V_148 ;
F_40 ( & V_18 -> V_140 , V_139 ) ;
F_48 ( V_18 , & V_21 , & V_22 ,
L_112
L_113
L_113 ,
V_155 -> V_157 . V_42 -> V_7 -> V_158 ,
F_49 ( V_155 -> V_157 . V_42 ) ,
V_155 -> V_159 ,
V_160 ) ;
if ( ! F_50 ( V_155 ) ) {
V_22 -= F_38 ( V_21 , V_22 ,
L_114 ) ;
goto V_161;
}
F_15 ( V_18 , & V_21 , & V_22 ) ;
if ( V_18 -> V_88 )
F_48 ( V_18 , & V_21 , & V_22 ,
L_115 , F_25 ( V_18 ) ) ;
V_156 = F_16 ( V_18 , & V_44 -> V_162 ) ;
V_45 = F_38 ( V_21 , V_22 ,
L_116 ,
V_156 , ( V_156 >> 31 ) ? L_117 : L_11 ,
( V_156 >> 16 ) & 0xefff , V_156 & 0xffff ) ;
V_22 -= V_45 ;
V_21 += V_45 ;
V_156 = F_16 ( V_18 , & V_44 -> V_163 ) ;
V_45 = F_38 ( V_21 , V_22 , L_118 ,
V_156 , ( V_156 >> 31 ) ? L_119 : L_11 ,
V_156 & 0x3fff ) ;
V_22 -= V_45 ;
V_21 += V_45 ;
V_156 = F_16 ( V_18 , & V_44 -> V_164 ) ;
V_45 = F_38 ( V_21 , V_22 , L_120 ,
V_156 & 0x3fff ) ;
V_22 -= V_45 ;
V_21 += V_45 ;
V_156 = F_16 ( V_18 , & V_44 -> V_165 ) ;
V_45 = F_38 ( V_21 , V_22 , L_121 ,
V_156 & 0x3fff ) ;
V_22 -= V_45 ;
V_21 += V_45 ;
V_45 = F_38 ( V_21 , V_22 , L_122 ,
F_51 ( F_47 ( V_18 ) ) ? L_123 : L_124 ) ;
V_22 -= V_45 ;
V_21 += V_45 ;
F_17 ( V_18 , 1 , & V_21 , & V_22 ) ;
V_161:
F_41 ( & V_18 -> V_140 , V_139 ) ;
return V_148 - V_22 ;
}
static struct V_138 * F_52 ( struct V_17 * V_18 ,
T_5 (* F_53)( struct V_138 * ) )
{
struct V_138 * V_131 ;
V_131 = F_54 ( sizeof( struct V_138 ) , V_166 ) ;
if ( V_131 ) {
V_131 -> V_18 = V_18 ;
V_131 -> F_53 = F_53 ;
F_55 ( & V_131 -> V_167 ) ;
}
return V_131 ;
}
static int F_56 ( struct V_138 * V_131 )
{
int V_168 = 0 ;
if ( ! V_131 -> V_141 )
V_131 -> V_141 = ( char * ) F_57 ( V_166 ) ;
if ( ! V_131 -> V_141 ) {
V_168 = - V_169 ;
goto V_170;
}
V_168 = V_131 -> F_53 ( V_131 ) ;
if ( V_168 >= 0 ) {
V_131 -> V_132 = V_168 ;
V_168 = 0 ;
}
V_170:
return V_168 ;
}
static T_5 F_58 ( struct V_171 * V_171 , char T_7 * V_172 ,
T_6 V_12 , T_8 * V_173 )
{
struct V_138 * V_131 = V_171 -> V_174 ;
int V_168 = 0 ;
F_59 ( & V_131 -> V_167 ) ;
if ( V_131 -> V_132 == 0 ) {
V_168 = F_56 ( V_131 ) ;
if ( V_168 != 0 ) {
F_60 ( & V_131 -> V_167 ) ;
goto V_170;
}
}
F_60 ( & V_131 -> V_167 ) ;
V_168 = F_61 ( V_172 , V_12 , V_173 ,
V_131 -> V_141 , V_131 -> V_132 ) ;
V_170:
return V_168 ;
}
static int F_62 ( struct V_175 * V_175 , struct V_171 * V_171 )
{
struct V_138 * V_131 = V_171 -> V_174 ;
if ( V_131 ) {
if ( V_131 -> V_141 )
F_63 ( ( unsigned long ) V_131 -> V_141 ) ;
F_45 ( V_131 ) ;
}
return 0 ;
}
static int F_64 ( struct V_175 * V_175 , struct V_171 * V_171 )
{
V_171 -> V_174 = F_52 ( V_175 -> V_176 , F_39 ) ;
return V_171 -> V_174 ? 0 : - V_169 ;
}
static int F_65 ( struct V_175 * V_175 , struct V_171 * V_171 )
{
V_171 -> V_174 = F_52 ( V_175 -> V_176 ,
F_42 ) ;
return V_171 -> V_174 ? 0 : - V_169 ;
}
static int F_66 ( struct V_175 * V_175 , struct V_171 * V_171 )
{
V_171 -> V_174 = F_52 ( V_175 -> V_176 ,
F_46 ) ;
return V_171 -> V_174 ? 0 : - V_169 ;
}
static inline void F_35 ( struct V_17 * V_18 )
{
struct V_177 * V_7 = & F_47 ( V_18 ) -> V_157 ;
V_18 -> V_178 = F_67 ( V_7 -> V_179 , V_180 ) ;
if ( ! V_18 -> V_178 )
goto V_181;
V_18 -> V_182 = F_68 ( L_125 , V_183 ,
V_18 -> V_178 , V_18 ,
& V_184 ) ;
if ( ! V_18 -> V_182 )
goto V_185;
V_18 -> V_186 = F_68 ( L_126 , V_183 ,
V_18 -> V_178 , V_18 ,
& V_187 ) ;
if ( ! V_18 -> V_186 )
goto V_188;
V_18 -> V_189 = F_68 ( L_127 , V_183 ,
V_18 -> V_178 , V_18 ,
& V_190 ) ;
if ( ! V_18 -> V_189 )
goto V_191;
F_24 ( V_18 , L_128 ) ;
return;
V_191:
F_69 ( V_18 -> V_186 ) ;
V_188:
F_69 ( V_18 -> V_182 ) ;
V_185:
F_69 ( V_18 -> V_178 ) ;
V_181:
V_18 -> V_186 = NULL ;
V_18 -> V_182 = NULL ;
V_18 -> V_178 = NULL ;
}
static inline void F_36 ( struct V_17 * V_18 )
{
F_69 ( V_18 -> V_189 ) ;
F_69 ( V_18 -> V_186 ) ;
F_69 ( V_18 -> V_182 ) ;
F_69 ( V_18 -> V_178 ) ;
}
