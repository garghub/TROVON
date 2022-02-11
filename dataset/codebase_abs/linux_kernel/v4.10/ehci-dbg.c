static void F_1 ( struct V_1 * V_2 , char * V_3 )
{
T_1 V_4 = F_2 ( V_2 , & V_2 -> V_5 -> V_6 ) ;
F_3 ( V_2 ,
L_1 ,
V_3 , V_4 ,
F_4 ( V_4 ) ,
F_5 ( V_4 ) ? L_2 : L_3 ,
F_6 ( V_4 ) ,
F_7 ( V_4 ) ,
F_8 ( V_4 ) ? L_3 : L_4 ,
F_9 ( V_4 ) ? L_3 : L_5 ,
F_10 ( V_4 ) ) ;
if ( F_8 ( V_4 ) ) {
int V_7 ;
char V_8 [ 46 ] , V_9 [ 7 ] , V_10 ;
V_8 [ 0 ] = 0 ;
for ( V_7 = 0 ; V_7 < F_10 ( V_4 ) ; V_7 ++ ) {
V_10 = F_11 ( & V_2 -> V_5 -> V_11 [ ( V_7 >> 1 ) ] ) ;
sprintf ( V_9 , L_6 ,
( V_7 & 0x1 ) ? V_10 & 0xf : ( V_10 >> 4 ) & 0xf ) ;
strcat ( V_8 , V_9 ) ;
}
F_3 ( V_2 , L_7 , V_3 , V_8 ) ;
}
}
static void F_12 ( struct V_1 * V_2 , char * V_3 )
{
T_1 V_4 = F_2 ( V_2 , & V_2 -> V_5 -> V_12 ) ;
if ( F_13 ( V_4 ) ) {
F_3 ( V_2 ,
L_8 ,
V_3 , V_4 ,
F_14 ( V_4 ) ? L_9 : L_10 ,
F_15 ( V_4 ) ? L_11 : L_3 ,
F_16 ( V_4 ) ? L_12 : L_3 ) ;
} else {
F_3 ( V_2 ,
L_13 ,
V_3 ,
V_4 ,
F_17 ( V_4 ) ,
F_14 ( V_4 ) ? L_9 : L_10 ,
F_15 ( V_4 ) ? L_11 : L_3 ,
F_16 ( V_4 ) ? L_12 : L_3 ,
F_18 ( V_4 ) ? L_14 : L_3 ,
F_19 ( V_4 ) ? L_15 : L_3 ,
F_20 ( V_4 ) ? L_16 : L_3 ,
F_21 ( V_4 ) ?
L_17 : L_3 ) ;
}
}
static void T_2
F_22 ( const char * V_3 , struct V_1 * V_2 , struct V_13 * V_14 )
{
F_3 ( V_2 , L_18 , V_3 , V_14 ,
F_23 ( V_2 , & V_14 -> V_15 ) ,
F_23 ( V_2 , & V_14 -> V_16 ) ,
F_23 ( V_2 , & V_14 -> V_17 ) ,
F_23 ( V_2 , & V_14 -> V_18 [ 0 ] ) ) ;
if ( V_14 -> V_18 [ 1 ] )
F_3 ( V_2 , L_19 ,
F_23 ( V_2 , & V_14 -> V_18 [ 1 ] ) ,
F_23 ( V_2 , & V_14 -> V_18 [ 2 ] ) ,
F_23 ( V_2 , & V_14 -> V_18 [ 3 ] ) ,
F_23 ( V_2 , & V_14 -> V_18 [ 4 ] ) ) ;
}
static void T_2
F_24 ( const char * V_3 , struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_22 ;
F_3 ( V_2 , L_20 , V_3 ,
V_20 , V_22 -> V_15 , V_22 -> V_23 , V_22 -> V_24 , V_22 -> V_25 ) ;
F_22 ( L_21 , V_2 , (struct V_13 * ) & V_22 -> V_26 ) ;
}
static void T_2
F_25 ( const char * V_3 , struct V_1 * V_2 , struct V_27 * V_28 )
{
F_3 ( V_2 , L_22 ,
V_3 , V_28 -> V_29 , V_28 , F_26 ( V_2 , V_28 -> V_15 ) ,
V_28 -> V_30 ) ;
F_3 ( V_2 ,
L_23 ,
F_26 ( V_2 , V_28 -> V_31 [ 0 ] ) ,
F_26 ( V_2 , V_28 -> V_31 [ 1 ] ) ,
F_26 ( V_2 , V_28 -> V_31 [ 2 ] ) ,
F_26 ( V_2 , V_28 -> V_31 [ 3 ] ) ,
F_26 ( V_2 , V_28 -> V_31 [ 4 ] ) ,
F_26 ( V_2 , V_28 -> V_31 [ 5 ] ) ,
F_26 ( V_2 , V_28 -> V_31 [ 6 ] ) ,
F_26 ( V_2 , V_28 -> V_31 [ 7 ] ) ) ;
F_3 ( V_2 ,
L_24 ,
F_26 ( V_2 , V_28 -> V_32 [ 0 ] ) ,
F_26 ( V_2 , V_28 -> V_32 [ 1 ] ) ,
F_26 ( V_2 , V_28 -> V_32 [ 2 ] ) ,
F_26 ( V_2 , V_28 -> V_32 [ 3 ] ) ,
F_26 ( V_2 , V_28 -> V_32 [ 4 ] ) ,
F_26 ( V_2 , V_28 -> V_32 [ 5 ] ) ,
F_26 ( V_2 , V_28 -> V_32 [ 6 ] ) ) ;
F_3 ( V_2 , L_25 ,
V_28 -> V_33 [ 0 ] , V_28 -> V_33 [ 1 ] , V_28 -> V_33 [ 2 ] ,
V_28 -> V_33 [ 3 ] , V_28 -> V_33 [ 4 ] , V_28 -> V_33 [ 5 ] ,
V_28 -> V_33 [ 6 ] , V_28 -> V_33 [ 7 ] ) ;
}
static void T_2
F_27 ( const char * V_3 , struct V_1 * V_2 , struct V_34 * V_35 )
{
F_3 ( V_2 , L_26 ,
V_3 , V_35 -> V_29 , V_35 , F_26 ( V_2 , V_35 -> V_15 ) ,
V_35 -> V_30 ) ;
F_3 ( V_2 ,
L_27 ,
F_26 ( V_2 , V_35 -> V_36 ) ,
F_26 ( V_2 , V_35 -> V_37 ) ,
F_26 ( V_2 , V_35 -> V_38 ) ,
F_26 ( V_2 , V_35 -> V_18 [ 0 ] ) ,
F_26 ( V_2 , V_35 -> V_18 [ 1 ] ) ) ;
}
static int T_2
F_28 ( char * V_8 , unsigned V_39 , const char * V_3 , T_1 V_40 )
{
return F_29 ( V_8 , V_39 ,
L_28 ,
V_3 , V_3 [ 0 ] ? L_29 : L_3 , V_40 ,
( V_40 & V_41 ) ? L_30 : L_3 ,
( V_40 & V_42 ) ? L_31 : L_3 ,
( V_40 & V_43 ) ? L_32 : L_3 ,
( V_40 & V_44 ) ? L_33 : L_3 ,
( V_40 & V_45 ) ? L_34 : L_3 ,
( V_40 & V_46 ) ? L_35 : L_3 ,
( V_40 & V_47 ) ? L_36 : L_3 ,
( V_40 & V_48 ) ? L_37 : L_3 ,
( V_40 & V_49 ) ? L_38 : L_3 ,
( V_40 & V_50 ) ? L_39 : L_3 ,
( V_40 & V_51 ) ? L_40 : L_3 ) ;
}
static int T_2
F_30 ( char * V_8 , unsigned V_39 , const char * V_3 , T_1 V_52 )
{
return F_29 ( V_8 , V_39 ,
L_41 ,
V_3 , V_3 [ 0 ] ? L_29 : L_3 , V_52 ,
( V_52 & V_41 ) ? L_30 : L_3 ,
( V_52 & V_46 ) ? L_35 : L_3 ,
( V_52 & V_47 ) ? L_36 : L_3 ,
( V_52 & V_48 ) ? L_37 : L_3 ,
( V_52 & V_49 ) ? L_38 : L_3 ,
( V_52 & V_50 ) ? L_39 : L_3 ,
( V_52 & V_51 ) ? L_40 : L_3 ) ;
}
static int
F_31 ( char * V_8 , unsigned V_39 , const char * V_3 , T_1 V_53 )
{
return F_29 ( V_8 , V_39 ,
L_42
L_43 ,
V_3 , V_3 [ 0 ] ? L_29 : L_3 , V_53 ,
( V_53 & V_54 ) ? L_44 : L_3 ,
( V_53 & V_55 ) ? L_45 : L_3 ,
( V_53 & V_56 ) ? L_46 : L_3 ,
( V_53 & V_57 ) ? L_47 : L_3 ,
( V_53 & V_58 ) ? L_48 : L_3 ,
( V_53 & V_59 ) ? L_11 : L_49 ,
F_32 ( V_53 ) ,
( V_53 >> 16 ) & 0x3f ,
( V_53 & V_60 ) ? L_50 : L_3 ,
( V_53 & V_61 ) ? L_51 : L_3 ,
( V_53 & V_62 ) ? L_31 : L_3 ,
( V_53 & V_63 ) ? L_32 : L_3 ,
V_64 [ ( V_53 >> 2 ) & 0x3 ] ,
( V_53 & V_65 ) ? L_52 : L_3 ,
( V_53 & V_66 ) ? L_53 : L_54 ) ;
}
static int
F_33 ( char * V_8 , unsigned V_39 , const char * V_3 , int V_67 , T_1 V_40 )
{
char * V_68 ;
switch ( V_40 & ( 3 << 10 ) ) {
case 0 << 10 :
V_68 = L_55 ;
break;
case 1 << 10 :
V_68 = L_56 ;
break;
case 2 << 10 :
V_68 = L_57 ;
break;
default:
V_68 = L_58 ;
break;
}
return F_29 ( V_8 , V_39 ,
L_59
L_60 ,
V_3 , V_3 [ 0 ] ? L_29 : L_3 , V_67 , V_40 ,
V_40 >> 25 ,
( V_40 & V_69 ) >> 23 == V_70 ?
L_61 : L_3 ,
( V_40 & V_69 ) >> 23 == V_71 ?
L_62 : L_3 ,
( V_40 & V_69 ) >> 23 == V_72 ?
L_63 : L_3 ,
( V_40 & V_69 ) >> 23 == V_73 ?
L_39 : L_3 ,
( V_40 & V_74 ) ? L_64 : L_3 ,
( V_40 & V_75 ) ? L_65 : L_3 ,
V_68 ,
( V_40 & V_76 ) ? L_14 : L_3 ,
( V_40 & V_77 ) ? L_66 : L_3 ,
( V_40 & V_78 ) ? L_67 : L_3 ,
( V_40 & V_79 ) ? L_68 : L_3 ,
( V_40 & V_80 ) ? L_69 : L_3 ,
( V_40 & V_81 ) ? L_70 : L_3 ,
( V_40 & V_82 ) ? L_71 : L_3 ,
( V_40 & V_83 ) ? L_72 : L_3 ,
( V_40 & V_84 ) ? L_73 : L_3 ,
( V_40 & V_85 ) ? L_74 : L_3 ) ;
}
static inline void
F_34 ( struct V_1 * V_2 , const char * V_3 , T_1 V_40 )
{
char V_8 [ 80 ] ;
F_28 ( V_8 , sizeof( V_8 ) , V_3 , V_40 ) ;
F_3 ( V_2 , L_75 , V_8 ) ;
}
static inline void
F_35 ( struct V_1 * V_2 , const char * V_3 , T_1 V_53 )
{
char V_8 [ 80 ] ;
F_31 ( V_8 , sizeof( V_8 ) , V_3 , V_53 ) ;
F_3 ( V_2 , L_75 , V_8 ) ;
}
static inline void
F_36 ( struct V_1 * V_2 , const char * V_3 , int V_67 , T_1 V_40 )
{
char V_8 [ 80 ] ;
F_33 ( V_8 , sizeof( V_8 ) , V_3 , V_67 , V_40 ) ;
F_3 ( V_2 , L_75 , V_8 ) ;
}
static inline char F_37 ( T_1 V_86 )
{
switch ( V_86 & ( 3 << 12 ) ) {
case V_87 :
return 'f' ;
case V_88 :
return 'l' ;
case V_89 :
return 'h' ;
default:
return '?' ;
}
}
static inline char F_38 ( struct V_1 * V_2 , T_3 V_90 )
{
T_4 V_91 = F_26 ( V_2 , V_90 ) ;
if ( V_91 & V_92 )
return '*' ;
if ( V_91 & V_93 )
return '-' ;
if ( ! F_39 ( V_91 ) )
return ' ' ;
return '/' ;
}
static void F_40 ( struct V_1 * V_2 , struct V_19 * V_20 ,
char * * V_94 , unsigned * V_95 )
{
T_1 V_96 ;
T_1 V_97 ;
struct V_98 * V_99 ;
struct V_13 * V_100 ;
unsigned V_101 ;
unsigned V_102 = * V_95 ;
char * V_103 = * V_94 ;
char V_104 ;
T_5 V_105 = F_41 ( V_2 ) ;
struct V_21 * V_22 = V_20 -> V_22 ;
if ( V_22 -> V_26 == V_105 )
V_104 = '@' ;
else
V_104 = F_38 ( V_2 , V_22 -> V_17 ) ;
if ( V_104 == '/' ) {
if ( ( V_22 -> V_16 & F_42 ( V_2 ) )
== V_2 -> V_106 -> V_22 -> V_16 )
V_104 = '#' ;
else if ( V_22 -> V_16 == V_105 )
V_104 = '.' ;
}
V_96 = F_23 ( V_2 , & V_22 -> V_23 ) ;
V_97 = ( V_104 == '*' ) ? F_23 ( V_2 , & V_22 -> V_25 ) : 0 ;
V_101 = F_29 ( V_103 , V_102 ,
L_76
L_77 ,
V_20 , V_96 & 0x007f ,
F_37 ( V_96 ) ,
( V_96 >> 8 ) & 0x000f ,
V_96 , F_23 ( V_2 , & V_22 -> V_24 ) ,
F_23 ( V_2 , & V_22 -> V_17 ) , V_104 ,
( F_43 ( V_2 , V_107 ) & V_22 -> V_17 )
? L_78 : L_79 ,
( F_23 ( V_2 , & V_22 -> V_16 ) >> 1 ) & 0x0f ,
F_23 ( V_2 , & V_22 -> V_25 ) ,
F_23 ( V_2 , & V_22 -> V_26 ) ,
F_23 ( V_2 , & V_22 -> V_18 [ 0 ] ) ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
F_44 (entry, &qh->qtd_list) {
char * type ;
V_100 = F_45 ( V_99 , struct V_13 , V_108 ) ;
V_96 = F_23 ( V_2 , & V_100 -> V_17 ) ;
V_104 = ' ' ;
if ( V_97 == V_100 -> V_109 ) {
V_104 = '*' ;
} else if ( V_22 -> V_26 == F_43 ( V_2 , V_100 -> V_109 ) ) {
V_104 = '+' ;
} else if ( F_46 ( V_96 ) ) {
if ( V_100 -> V_16 == V_2 -> V_106 -> V_22 -> V_16 )
V_104 = '#' ;
else if ( V_100 -> V_16 != V_105 )
V_104 = '/' ;
}
switch ( ( V_96 >> 8 ) & 0x03 ) {
case 0 :
type = L_80 ;
break;
case 1 :
type = L_81 ;
break;
case 2 :
type = L_82 ;
break;
default:
type = L_58 ;
break;
}
V_101 = F_29 ( V_103 , V_102 ,
L_83
L_84 ,
V_100 , V_104 , type ,
( V_96 >> 16 ) & 0x7fff ,
V_96 ,
V_100 -> V_30 ,
( T_1 ) V_100 -> V_109 ,
F_23 ( V_2 , & V_100 -> V_18 [ 0 ] ) ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
if ( V_101 == V_102 )
goto V_110;
}
V_101 = F_29 ( V_103 , V_102 , L_85 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
V_110:
* V_95 = V_102 ;
* V_94 = V_103 ;
}
static T_6 F_47 ( struct V_111 * V_8 )
{
struct V_112 * V_113 ;
struct V_1 * V_2 ;
unsigned long V_114 ;
unsigned V_101 , V_102 ;
char * V_103 ;
struct V_19 * V_20 ;
V_113 = F_48 ( V_8 -> V_115 ) ;
V_2 = F_49 ( V_113 ) ;
V_103 = V_8 -> V_116 ;
V_102 = V_8 -> V_117 ;
* V_103 = 0 ;
F_50 ( & V_2 -> V_118 , V_114 ) ;
for ( V_20 = V_2 -> V_106 -> V_119 . V_20 ; V_102 > 0 && V_20 ; V_20 = V_20 -> V_119 . V_20 )
F_40 ( V_2 , V_20 , & V_103 , & V_102 ) ;
if ( ! F_51 ( & V_2 -> V_120 ) && V_102 > 0 ) {
V_101 = F_29 ( V_103 , V_102 , L_86 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
F_52 (qh, &ehci->async_unlink, unlink_node) {
if ( V_102 <= 0 )
break;
F_40 ( V_2 , V_20 , & V_103 , & V_102 ) ;
}
}
F_53 ( & V_2 -> V_118 , V_114 ) ;
return strlen ( V_8 -> V_116 ) ;
}
static T_6 F_54 ( struct V_111 * V_8 )
{
struct V_1 * V_2 ;
struct V_121 * V_122 ;
struct V_123 * V_124 ;
unsigned V_101 , V_102 ;
char * V_103 ;
unsigned V_7 ;
T_7 * V_125 ;
T_8 * V_126 ;
T_7 V_127 [ V_128 ] ;
V_2 = F_49 ( F_48 ( V_8 -> V_115 ) ) ;
V_103 = V_8 -> V_116 ;
V_102 = V_8 -> V_117 ;
* V_103 = 0 ;
F_55 ( & V_2 -> V_118 ) ;
V_101 = F_29 ( V_103 , V_102 ,
L_87 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
for ( V_7 = 0 ; V_7 < V_128 ; V_7 += 8 ) {
V_125 = & V_2 -> V_129 [ V_7 ] ;
V_101 = F_29 ( V_103 , V_102 ,
L_88 ,
V_7 , V_125 [ 0 ] , V_125 [ 1 ] , V_125 [ 2 ] , V_125 [ 3 ] ,
V_125 [ 4 ] , V_125 [ 5 ] , V_125 [ 6 ] , V_125 [ 7 ] ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
}
F_52 (tt, &ehci->tt_list, tt_list) {
V_101 = F_29 ( V_103 , V_102 ,
L_89 ,
F_56 ( & V_122 -> V_130 -> V_131 -> V_132 ) ,
V_122 -> V_133 + ! ! V_122 -> V_130 -> V_134 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
V_126 = V_122 -> V_129 ;
V_101 = F_29 ( V_103 , V_102 ,
L_90 ,
V_126 [ 0 ] , V_126 [ 1 ] , V_126 [ 2 ] , V_126 [ 3 ] ,
V_126 [ 4 ] , V_126 [ 5 ] , V_126 [ 6 ] , V_126 [ 7 ] ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
V_101 = F_29 ( V_103 , V_102 ,
L_91 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
F_57 ( V_127 , V_122 ) ;
for ( V_7 = 0 ; V_7 < V_128 ; V_7 += 8 ) {
V_125 = & V_127 [ V_7 ] ;
V_101 = F_29 ( V_103 , V_102 ,
L_88 ,
V_7 , V_125 [ 0 ] , V_125 [ 1 ] , V_125 [ 2 ] , V_125 [ 3 ] ,
V_125 [ 4 ] , V_125 [ 5 ] , V_125 [ 6 ] , V_125 [ 7 ] ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
}
F_52 (ps, &tt->ps_list, ps_list) {
V_101 = F_29 ( V_103 , V_102 ,
L_92 ,
F_56 ( & V_124 -> V_135 -> V_132 ) ,
V_124 -> V_136 -> V_137 . V_138 ,
V_124 -> V_139 ,
V_124 -> V_140 , V_124 -> V_141 ,
V_124 -> V_142 , V_124 -> V_143 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
}
}
F_58 ( & V_2 -> V_118 ) ;
return V_103 - V_8 -> V_116 ;
}
static unsigned F_59 ( char * V_8 , struct V_1 * V_2 ,
struct V_21 * V_22 , struct V_19 * V_20 , unsigned V_102 )
{
T_1 V_96 = F_23 ( V_2 , & V_22 -> V_23 ) ;
struct V_13 * V_14 ;
char * type = L_3 ;
unsigned V_101 = 0 ;
F_52 (qtd, &qh->qtd_list, qtd_list) {
V_101 ++ ;
switch ( ( F_26 ( V_2 , V_14 -> V_17 ) >> 8 ) & 0x03 ) {
case 0 :
type = L_80 ;
continue;
case 1 :
type = L_81 ;
continue;
}
}
return F_29 ( V_8 , V_102 , L_93 ,
F_37 ( V_96 ) , V_96 & 0x007f ,
( V_96 >> 8 ) & 0x000f , type , V_20 -> V_124 . V_144 ,
V_20 -> V_124 . V_145 , V_101 , 0x7ff & ( V_96 >> 16 ) ) ;
}
static T_6 F_60 ( struct V_111 * V_8 )
{
struct V_112 * V_113 ;
struct V_1 * V_2 ;
unsigned long V_114 ;
union V_146 V_147 , * V_148 ;
unsigned V_101 , V_102 , V_149 ;
char * V_103 ;
unsigned V_7 ;
T_3 V_150 ;
V_148 = F_61 ( V_151 , sizeof( * V_148 ) , V_152 ) ;
if ( ! V_148 )
return 0 ;
V_149 = 0 ;
V_113 = F_48 ( V_8 -> V_115 ) ;
V_2 = F_49 ( V_113 ) ;
V_103 = V_8 -> V_116 ;
V_102 = V_8 -> V_117 ;
V_101 = F_29 ( V_103 , V_102 , L_94 , V_2 -> V_153 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
F_50 ( & V_2 -> V_118 , V_114 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_153 ; V_7 ++ ) {
V_147 = V_2 -> V_154 [ V_7 ] ;
if ( F_62 ( ! V_147 . V_155 ) )
continue;
V_150 = F_63 ( V_2 , V_2 -> V_156 [ V_7 ] ) ;
V_101 = F_29 ( V_103 , V_102 , L_95 , V_7 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
do {
struct V_21 * V_22 ;
switch ( F_26 ( V_2 , V_150 ) ) {
case V_157 :
V_22 = V_147 . V_20 -> V_22 ;
V_101 = F_29 ( V_103 , V_102 , L_96 ,
V_147 . V_20 -> V_124 . V_158 ,
F_23 ( V_2 ,
& V_22 -> V_24 )
& ( V_159 | V_160 ) ,
V_147 . V_20 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
for ( V_101 = 0 ; V_101 < V_149 ; V_101 ++ ) {
if ( V_148 [ V_101 ] . V_155 != V_147 . V_155 )
continue;
if ( V_147 . V_20 -> V_119 . V_155 ) {
V_101 = F_29 ( V_103 , V_102 ,
L_97 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
}
break;
}
if ( V_101 == V_149 ) {
V_101 = F_59 ( V_103 , V_2 ,
V_22 , V_147 . V_20 , V_102 ) ;
if ( V_149 < V_151 )
V_148 [ V_149 ++ ] . V_20 = V_147 . V_20 ;
} else {
V_101 = 0 ;
}
V_150 = F_63 ( V_2 , V_22 -> V_15 ) ;
V_147 = V_147 . V_20 -> V_119 ;
break;
case V_161 :
V_101 = F_29 ( V_103 , V_102 ,
L_98 , V_147 . V_162 -> V_163 ,
V_147 . V_162 ) ;
V_150 = F_63 ( V_2 , V_147 . V_162 -> V_15 ) ;
V_147 = V_147 . V_162 -> V_164 ;
break;
case V_165 :
V_101 = F_29 ( V_103 , V_102 ,
L_99 , V_147 . V_28 ) ;
V_150 = F_63 ( V_2 , V_147 . V_28 -> V_15 ) ;
V_147 = V_147 . V_28 -> V_166 ;
break;
case V_167 :
V_101 = F_29 ( V_103 , V_102 ,
L_100 ,
V_147 . V_35 -> V_168 -> V_124 . V_158 ,
F_23 ( V_2 , & V_147 . V_35 -> V_37 )
& 0x0000ffff ,
V_147 . V_35 ) ;
V_150 = F_63 ( V_2 , V_147 . V_35 -> V_15 ) ;
V_147 = V_147 . V_35 -> V_169 ;
break;
}
V_102 -= V_101 ;
V_103 += V_101 ;
} while ( V_147 . V_155 );
V_101 = F_29 ( V_103 , V_102 , L_85 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
}
F_53 ( & V_2 -> V_118 , V_114 ) ;
F_64 ( V_148 ) ;
return V_8 -> V_117 - V_102 ;
}
static const char * F_65 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_170 ) {
case V_171 :
return L_101 ;
case V_172 :
return L_102 ;
case V_173 :
return L_103 ;
case V_174 :
return L_104 ;
}
return L_58 ;
}
static T_6 F_66 ( struct V_111 * V_8 )
{
struct V_112 * V_113 ;
struct V_1 * V_2 ;
unsigned long V_114 ;
unsigned V_101 , V_102 , V_7 ;
char * V_103 , V_96 [ 80 ] ;
static char V_175 [] = L_105 ;
static char V_3 [] = L_3 ;
V_113 = F_48 ( V_8 -> V_115 ) ;
V_2 = F_49 ( V_113 ) ;
V_103 = V_8 -> V_116 ;
V_102 = V_8 -> V_117 ;
F_50 ( & V_2 -> V_118 , V_114 ) ;
if ( ! F_67 ( V_113 ) ) {
V_102 = F_29 ( V_103 , V_102 ,
L_106
L_75
L_107 ,
V_113 -> V_176 . V_177 -> V_115 -> V_178 ,
F_56 ( V_113 -> V_176 . V_177 ) ,
V_113 -> V_179 ) ;
goto V_110;
}
V_7 = F_68 ( V_2 , F_2 ( V_2 , & V_2 -> V_5 -> V_180 ) ) ;
V_101 = F_29 ( V_103 , V_102 ,
L_106
L_75
L_108 ,
V_113 -> V_176 . V_177 -> V_115 -> V_178 ,
F_56 ( V_113 -> V_176 . V_177 ) ,
V_113 -> V_179 ,
V_7 >> 8 , V_7 & 0x0ff , F_65 ( V_2 ) ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
#ifdef F_69
if ( F_70 ( V_113 -> V_176 . V_177 ) ) {
struct V_181 * V_182 ;
T_1 V_183 , V_184 , V_185 ;
unsigned V_186 = 256 / 4 ;
V_182 = F_71 ( F_72 ( V_2 ) -> V_176 . V_177 ) ;
V_183 = F_73 ( F_2 ( V_2 ,
& V_2 -> V_5 -> V_12 ) ) ;
while ( V_183 && V_186 -- ) {
F_74 ( V_182 , V_183 , & V_184 ) ;
switch ( V_184 & 0xff ) {
case 1 :
V_101 = F_29 ( V_103 , V_102 ,
L_109 , V_184 ,
( V_184 & ( 1 << 24 ) ) ? L_110 : L_3 ,
( V_184 & ( 1 << 16 ) ) ? L_111 : L_3 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
V_183 += 4 ;
F_74 ( V_182 , V_183 , & V_185 ) ;
V_101 = F_29 ( V_103 , V_102 ,
L_112 , V_185 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
break;
case 0 :
V_184 = 0 ;
default:
break;
}
V_101 = ( V_184 >> 8 ) & 0xff ;
}
}
#endif
V_7 = F_2 ( V_2 , & V_2 -> V_5 -> V_6 ) ;
V_101 = F_29 ( V_103 , V_102 , L_113 , V_7 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
V_7 = F_2 ( V_2 , & V_2 -> V_5 -> V_12 ) ;
V_101 = F_29 ( V_103 , V_102 , L_114 , V_7 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
V_101 = F_28 ( V_96 , sizeof( V_96 ) , V_3 ,
F_2 ( V_2 , & V_2 -> V_187 -> V_40 ) ) ;
V_101 = F_29 ( V_103 , V_102 , V_175 , V_101 , V_96 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
V_101 = F_31 ( V_96 , sizeof( V_96 ) , V_3 ,
F_2 ( V_2 , & V_2 -> V_187 -> V_53 ) ) ;
V_101 = F_29 ( V_103 , V_102 , V_175 , V_101 , V_96 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
V_101 = F_30 ( V_96 , sizeof( V_96 ) , V_3 ,
F_2 ( V_2 , & V_2 -> V_187 -> V_188 ) ) ;
V_101 = F_29 ( V_103 , V_102 , V_175 , V_101 , V_96 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
V_101 = F_29 ( V_103 , V_102 , L_115 ,
F_75 ( V_2 ) ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
for ( V_7 = 1 ; V_7 <= F_10 ( V_2 -> V_6 ) ; V_7 ++ ) {
V_101 = F_33 ( V_96 , sizeof( V_96 ) , V_3 , V_7 ,
F_2 ( V_2 ,
& V_2 -> V_187 -> V_189 [ V_7 - 1 ] ) ) ;
V_101 = F_29 ( V_103 , V_102 , V_175 , V_101 , V_96 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
if ( V_7 == F_4 ( V_2 -> V_6 ) && V_2 -> V_190 ) {
V_101 = F_29 ( V_103 , V_102 ,
L_116 ,
F_2 ( V_2 ,
& V_2 -> V_190 -> V_191 ) ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
}
}
if ( ! F_51 ( & V_2 -> V_120 ) ) {
V_101 = F_29 ( V_103 , V_102 , L_117 ,
F_76 ( & V_2 -> V_120 ,
struct V_19 , V_192 ) ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
}
#ifdef F_77
V_101 = F_29 ( V_103 , V_102 ,
L_118 ,
V_2 -> V_193 . V_194 , V_2 -> V_193 . error , V_2 -> V_193 . V_195 ,
V_2 -> V_193 . V_196 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
V_101 = F_29 ( V_103 , V_102 , L_119 ,
V_2 -> V_193 . V_197 , V_2 -> V_193 . V_198 ) ;
V_102 -= V_101 ;
V_103 += V_101 ;
#endif
V_110:
F_53 ( & V_2 -> V_118 , V_114 ) ;
return V_8 -> V_117 - V_102 ;
}
static struct V_111 * F_78 ( struct V_199 * V_115 ,
T_6 (* F_79)( struct V_111 * ) )
{
struct V_111 * V_8 ;
V_8 = F_80 ( sizeof( * V_8 ) , V_200 ) ;
if ( V_8 ) {
V_8 -> V_115 = V_115 ;
V_8 -> F_79 = F_79 ;
F_81 ( & V_8 -> V_201 ) ;
V_8 -> V_117 = V_202 ;
}
return V_8 ;
}
static int F_82 ( struct V_111 * V_8 )
{
int V_203 = 0 ;
if ( ! V_8 -> V_116 )
V_8 -> V_116 = F_83 ( V_8 -> V_117 ) ;
if ( ! V_8 -> V_116 ) {
V_203 = - V_204 ;
goto V_205;
}
V_203 = V_8 -> F_79 ( V_8 ) ;
if ( V_203 >= 0 ) {
V_8 -> V_186 = V_203 ;
V_203 = 0 ;
}
V_205:
return V_203 ;
}
static T_6 F_84 ( struct V_206 * V_206 , char T_9 * V_207 ,
T_10 V_39 , T_11 * V_183 )
{
struct V_111 * V_8 = V_206 -> V_208 ;
int V_203 = 0 ;
F_85 ( & V_8 -> V_201 ) ;
if ( V_8 -> V_186 == 0 ) {
V_203 = F_82 ( V_8 ) ;
if ( V_203 != 0 ) {
F_86 ( & V_8 -> V_201 ) ;
goto V_205;
}
}
F_86 ( & V_8 -> V_201 ) ;
V_203 = F_87 ( V_207 , V_39 , V_183 ,
V_8 -> V_116 , V_8 -> V_186 ) ;
V_205:
return V_203 ;
}
static int F_88 ( struct V_209 * V_209 , struct V_206 * V_206 )
{
struct V_111 * V_8 = V_206 -> V_208 ;
if ( V_8 ) {
F_89 ( V_8 -> V_116 ) ;
F_64 ( V_8 ) ;
}
return 0 ;
}
static int F_90 ( struct V_209 * V_209 , struct V_206 * V_206 )
{
V_206 -> V_208 = F_78 ( V_209 -> V_210 , F_47 ) ;
return V_206 -> V_208 ? 0 : - V_204 ;
}
static int F_91 ( struct V_209 * V_209 , struct V_206 * V_206 )
{
V_206 -> V_208 = F_78 ( V_209 -> V_210 ,
F_54 ) ;
return V_206 -> V_208 ? 0 : - V_204 ;
}
static int F_92 ( struct V_209 * V_209 , struct V_206 * V_206 )
{
struct V_111 * V_8 ;
V_8 = F_78 ( V_209 -> V_210 , F_60 ) ;
if ( ! V_8 )
return - V_204 ;
V_8 -> V_117 = ( sizeof( void * ) == 4 ? 6 : 8 ) * V_202 ;
V_206 -> V_208 = V_8 ;
return 0 ;
}
static int F_93 ( struct V_209 * V_209 , struct V_206 * V_206 )
{
V_206 -> V_208 = F_78 ( V_209 -> V_210 ,
F_66 ) ;
return V_206 -> V_208 ? 0 : - V_204 ;
}
static inline void F_94 ( struct V_1 * V_2 )
{
struct V_199 * V_115 = & F_72 ( V_2 ) -> V_176 ;
V_2 -> V_211 = F_95 ( V_115 -> V_212 , V_213 ) ;
if ( ! V_2 -> V_211 )
return;
if ( ! F_96 ( L_120 , V_214 , V_2 -> V_211 , V_115 ,
& V_215 ) )
goto V_216;
if ( ! F_96 ( L_121 , V_214 , V_2 -> V_211 , V_115 ,
& V_217 ) )
goto V_216;
if ( ! F_96 ( L_122 , V_214 , V_2 -> V_211 , V_115 ,
& V_218 ) )
goto V_216;
if ( ! F_96 ( L_123 , V_214 , V_2 -> V_211 , V_115 ,
& V_219 ) )
goto V_216;
return;
V_216:
F_97 ( V_2 -> V_211 ) ;
}
static inline void F_98 ( struct V_1 * V_2 )
{
F_97 ( V_2 -> V_211 ) ;
}
static inline void F_1 ( struct V_1 * V_2 , char * V_3 ) { }
static inline void F_12 ( struct V_1 * V_2 , char * V_3 ) { }
static inline void T_2 F_24 ( const char * V_3 ,
struct V_1 * V_2 , struct V_19 * V_20 ) { }
static inline int T_2 F_28 ( const char * V_8 ,
unsigned int V_39 , const char * V_3 , T_1 V_40 )
{ return 0 ; }
static inline int T_2 F_31 ( const char * V_8 ,
unsigned int V_39 , const char * V_3 , T_1 V_53 )
{ return 0 ; }
static inline int T_2 F_30 ( const char * V_8 ,
unsigned int V_39 , const char * V_3 , T_1 V_52 )
{ return 0 ; }
static inline int T_2 F_33 ( char * V_8 ,
unsigned int V_39 , const char * V_3 , int V_67 , T_1 V_40 )
{ return 0 ; }
static inline void F_34 ( struct V_1 * V_2 , const char * V_3 ,
T_1 V_40 ) { }
static inline void F_35 ( struct V_1 * V_2 , const char * V_3 ,
T_1 V_53 ) { }
static inline void F_36 ( struct V_1 * V_2 , const char * V_3 ,
int V_67 , T_1 V_40 ) { }
static inline void F_94 ( struct V_1 * V_115 ) { }
static inline void F_98 ( struct V_1 * V_115 ) { }
