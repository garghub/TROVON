static inline void F_1 ( struct V_1 * V_2 , ... ) {}
static void F_2 ( struct V_1 * V_2 , char * V_3 )
{
T_1 V_4 = F_3 ( V_2 , & V_2 -> V_5 -> V_6 ) ;
F_4 ( V_2 ,
L_1 ,
V_3 , V_4 ,
F_5 ( V_4 ) ,
F_6 ( V_4 ) ? L_2 : L_3 ,
F_7 ( V_4 ) ,
F_8 ( V_4 ) ,
F_9 ( V_4 ) ? L_3 : L_4 ,
F_10 ( V_4 ) ? L_3 : L_5 ,
F_11 ( V_4 )
) ;
if ( F_9 ( V_4 ) ) {
int V_7 ;
char V_8 [ 46 ] , V_9 [ 7 ] , V_10 ;
V_8 [ 0 ] = 0 ;
for ( V_7 = 0 ; V_7 < F_11 ( V_4 ) ; V_7 ++ ) {
V_10 = F_12 ( & V_2 -> V_5 -> V_11 [ ( V_7 >> 1 ) ] ) ;
sprintf ( V_9 , L_6 ,
( ( V_7 & 0x1 ) ? ( ( V_10 ) & 0xf ) : ( ( V_10 >> 4 ) & 0xf ) ) ) ;
strcat ( V_8 , V_9 ) ;
}
F_4 ( V_2 , L_7 ,
V_3 , V_8 ) ;
}
}
static inline void F_2 ( struct V_1 * V_2 , char * V_3 ) {}
static void F_13 ( struct V_1 * V_2 , char * V_3 )
{
T_1 V_4 = F_3 ( V_2 , & V_2 -> V_5 -> V_12 ) ;
if ( F_14 ( V_4 ) ) {
F_4 ( V_2 ,
L_8 ,
V_3 , V_4 ,
F_15 ( V_4 ) ? L_9 : L_10 ,
F_16 ( V_4 ) ? L_11 : L_3 ,
F_17 ( V_4 ) ? L_12 : L_3 ) ;
} else {
F_4 ( V_2 ,
L_13 ,
V_3 ,
V_4 ,
F_18 ( V_4 ) ,
F_15 ( V_4 ) ? L_9 : L_10 ,
F_16 ( V_4 ) ? L_11 : L_3 ,
F_17 ( V_4 ) ? L_12 : L_3 ,
F_19 ( V_4 ) ? L_14 : L_3 ,
F_20 ( V_4 ) ? L_15 : L_3 ,
F_21 ( V_4 ) ? L_16 : L_3 ,
F_22 ( V_4 ) ?
L_17 : L_3 ) ;
}
}
static inline void F_13 ( struct V_1 * V_2 , char * V_3 ) {}
static void T_2
F_23 ( const char * V_3 , struct V_1 * V_2 , struct V_13 * V_14 )
{
F_4 ( V_2 , L_18 , V_3 , V_14 ,
F_24 ( V_2 , & V_14 -> V_15 ) ,
F_24 ( V_2 , & V_14 -> V_16 ) ,
F_24 ( V_2 , & V_14 -> V_17 ) ,
F_24 ( V_2 , & V_14 -> V_18 [ 0 ] ) ) ;
if ( V_14 -> V_18 [ 1 ] )
F_4 ( V_2 , L_19 ,
F_24 ( V_2 , & V_14 -> V_18 [ 1 ] ) ,
F_24 ( V_2 , & V_14 -> V_18 [ 2 ] ) ,
F_24 ( V_2 , & V_14 -> V_18 [ 3 ] ) ,
F_24 ( V_2 , & V_14 -> V_18 [ 4 ] ) ) ;
}
static void T_2
F_25 ( const char * V_3 , struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_22 ;
F_4 ( V_2 , L_20 , V_3 ,
V_20 , V_22 -> V_15 , V_22 -> V_23 , V_22 -> V_24 , V_22 -> V_25 ) ;
F_23 ( L_21 , V_2 , (struct V_13 * ) & V_22 -> V_26 ) ;
}
static void T_2
F_26 ( const char * V_3 , struct V_1 * V_2 , struct V_27 * V_28 )
{
F_4 ( V_2 , L_22 ,
V_3 , V_28 -> V_29 , V_28 , F_27 ( V_2 , V_28 -> V_15 ) ,
V_28 -> V_30 ) ;
F_4 ( V_2 ,
L_23 ,
F_27 ( V_2 , V_28 -> V_31 [ 0 ] ) ,
F_27 ( V_2 , V_28 -> V_31 [ 1 ] ) ,
F_27 ( V_2 , V_28 -> V_31 [ 2 ] ) ,
F_27 ( V_2 , V_28 -> V_31 [ 3 ] ) ,
F_27 ( V_2 , V_28 -> V_31 [ 4 ] ) ,
F_27 ( V_2 , V_28 -> V_31 [ 5 ] ) ,
F_27 ( V_2 , V_28 -> V_31 [ 6 ] ) ,
F_27 ( V_2 , V_28 -> V_31 [ 7 ] ) ) ;
F_4 ( V_2 ,
L_24 ,
F_27 ( V_2 , V_28 -> V_32 [ 0 ] ) ,
F_27 ( V_2 , V_28 -> V_32 [ 1 ] ) ,
F_27 ( V_2 , V_28 -> V_32 [ 2 ] ) ,
F_27 ( V_2 , V_28 -> V_32 [ 3 ] ) ,
F_27 ( V_2 , V_28 -> V_32 [ 4 ] ) ,
F_27 ( V_2 , V_28 -> V_32 [ 5 ] ) ,
F_27 ( V_2 , V_28 -> V_32 [ 6 ] ) ) ;
F_4 ( V_2 , L_25 ,
V_28 -> V_33 [ 0 ] , V_28 -> V_33 [ 1 ] , V_28 -> V_33 [ 2 ] ,
V_28 -> V_33 [ 3 ] , V_28 -> V_33 [ 4 ] , V_28 -> V_33 [ 5 ] ,
V_28 -> V_33 [ 6 ] , V_28 -> V_33 [ 7 ] ) ;
}
static void T_2
F_28 ( const char * V_3 , struct V_1 * V_2 , struct V_34 * V_35 )
{
F_4 ( V_2 , L_26 ,
V_3 , V_35 -> V_29 , V_35 , F_27 ( V_2 , V_35 -> V_15 ) ,
V_35 -> V_30 ) ;
F_4 ( V_2 ,
L_27 ,
F_27 ( V_2 , V_35 -> V_36 ) ,
F_27 ( V_2 , V_35 -> V_37 ) ,
F_27 ( V_2 , V_35 -> V_38 ) ,
F_27 ( V_2 , V_35 -> V_18 [ 0 ] ) ,
F_27 ( V_2 , V_35 -> V_18 [ 1 ] ) ) ;
}
static int T_2
F_29 ( char * V_8 , unsigned V_39 , const char * V_3 , T_1 V_40 )
{
return F_30 ( V_8 , V_39 ,
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
( V_40 & V_51 ) ? L_40 : L_3
) ;
}
static int T_2
F_31 ( char * V_8 , unsigned V_39 , const char * V_3 , T_1 V_52 )
{
return F_30 ( V_8 , V_39 ,
L_41 ,
V_3 , V_3 [ 0 ] ? L_29 : L_3 , V_52 ,
( V_52 & V_41 ) ? L_30 : L_3 ,
( V_52 & V_46 ) ? L_35 : L_3 ,
( V_52 & V_47 ) ? L_36 : L_3 ,
( V_52 & V_48 ) ? L_37 : L_3 ,
( V_52 & V_49 ) ? L_38 : L_3 ,
( V_52 & V_50 ) ? L_39 : L_3 ,
( V_52 & V_51 ) ? L_40 : L_3
) ;
}
static int
F_32 ( char * V_8 , unsigned V_39 , const char * V_3 , T_1 V_53 )
{
return F_30 ( V_8 , V_39 ,
L_42
L_43 ,
V_3 , V_3 [ 0 ] ? L_29 : L_3 , V_53 ,
( V_53 & V_54 ) ? L_44 : L_3 ,
( V_53 & V_55 ) ? L_45 : L_3 ,
( V_53 & V_56 ) ? L_46 : L_3 ,
( V_53 & V_57 ) ? L_47 : L_3 ,
( V_53 & V_58 ) ? L_48 : L_3 ,
( V_53 & V_59 ) ? L_11 : L_49 ,
F_33 ( V_53 ) ,
( V_53 >> 16 ) & 0x3f ,
( V_53 & V_60 ) ? L_50 : L_3 ,
( V_53 & V_61 ) ? L_51 : L_3 ,
( V_53 & V_62 ) ? L_31 : L_3 ,
( V_53 & V_63 ) ? L_32 : L_3 ,
V_64 [ ( V_53 >> 2 ) & 0x3 ] ,
( V_53 & V_65 ) ? L_52 : L_3 ,
( V_53 & V_66 ) ? L_53 : L_54
) ;
}
static int
F_34 ( char * V_8 , unsigned V_39 , const char * V_3 , int V_67 , T_1 V_40 )
{
char * V_68 ;
switch ( V_40 & ( 3 << 10 ) ) {
case 0 << 10 : V_68 = L_55 ; break;
case 1 << 10 : V_68 = L_56 ; break;
case 2 << 10 : V_68 = L_57 ; break;
default: V_68 = L_58 ; break;
}
return F_30 ( V_8 , V_39 ,
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
static inline void T_2
F_25 ( char * V_3 , struct V_1 * V_2 , struct V_19 * V_20 )
{}
static inline int T_2
F_29 ( char * V_8 , unsigned V_39 , const char * V_3 , T_1 V_40 )
{ return 0 ; }
static inline int T_2
F_32 ( char * V_8 , unsigned V_39 , const char * V_3 , T_1 V_53 )
{ return 0 ; }
static inline int T_2
F_31 ( char * V_8 , unsigned V_39 , const char * V_3 , T_1 V_52 )
{ return 0 ; }
static inline int T_2
F_34 ( char * V_8 , unsigned V_39 , const char * V_3 , int V_67 , T_1 V_40 )
{ return 0 ; }
static inline void F_35 ( struct V_1 * V_86 ) { }
static inline void F_36 ( struct V_1 * V_86 ) { }
static inline char F_37 ( struct V_1 * V_2 , T_3 V_87 )
{
T_4 V_88 = F_27 ( V_2 , V_87 ) ;
if ( V_88 & V_89 )
return '*' ;
if ( V_88 & V_90 )
return '-' ;
if ( ! F_38 ( V_88 ) )
return ' ' ;
return '/' ;
}
static void F_39 (
struct V_1 * V_2 ,
struct V_19 * V_20 ,
char * * V_91 ,
unsigned * V_92
)
{
T_1 V_93 ;
T_1 V_94 ;
struct V_95 * V_96 ;
struct V_13 * V_97 ;
unsigned V_98 ;
unsigned V_99 = * V_92 ;
char * V_100 = * V_91 ;
char V_101 ;
T_5 V_102 = F_40 ( V_2 ) ;
struct V_21 * V_22 = V_20 -> V_22 ;
if ( V_22 -> V_26 == V_102 )
V_101 = '@' ;
else
V_101 = F_37 ( V_2 , V_22 -> V_17 ) ;
if ( V_101 == '/' ) {
if ( ( V_22 -> V_16 & F_41 ( V_2 ) )
== V_2 -> V_103 -> V_22 -> V_16 )
V_101 = '#' ;
else if ( V_22 -> V_16 == V_102 )
V_101 = '.' ;
}
V_93 = F_24 ( V_2 , & V_22 -> V_23 ) ;
V_94 = ( V_101 == '*' ) ? F_24 ( V_2 , & V_22 -> V_25 ) : 0 ;
V_98 = F_30 ( V_100 , V_99 ,
L_75 ,
V_20 , V_93 & 0x007f ,
F_42 ( V_93 ) ,
( V_93 >> 8 ) & 0x000f ,
V_93 , F_24 ( V_2 , & V_22 -> V_24 ) ,
F_24 ( V_2 , & V_22 -> V_17 ) , V_101 ,
( F_43 ( V_2 , V_104 ) & V_22 -> V_17 )
? L_76 : L_77 ,
( F_24 ( V_2 , & V_22 -> V_16 ) >> 1 ) & 0x0f ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
F_44 (entry, &qh->qtd_list) {
V_97 = F_45 ( V_96 , struct V_13 , V_105 ) ;
V_93 = F_24 ( V_2 , & V_97 -> V_17 ) ;
V_101 = ' ' ;
if ( V_94 == V_97 -> V_106 )
V_101 = '*' ;
else if ( V_22 -> V_26 == F_43 ( V_2 , V_97 -> V_106 ) )
V_101 = '+' ;
else if ( F_46 ( V_93 ) ) {
if ( V_97 -> V_16 == V_2 -> V_103 -> V_22 -> V_16 )
V_101 = '#' ;
else if ( V_97 -> V_16 != V_102 )
V_101 = '/' ;
}
V_98 = snprintf (next, size,
L_78 ,
td, mark, ({ char *tmp;
switch ((scratch>>8)&0x03) {
case 0: tmp = L_79; break;
case 1: tmp = L_80; break;
case 2: tmp = L_81; break;
default: tmp = L_58; break;
} tmp;}),
(scratch >> 16) & 0x7fff ,
scratch,
td->urb) ;
if ( V_99 < V_98 )
V_98 = V_99 ;
V_99 -= V_98 ;
V_100 += V_98 ;
if ( V_98 == V_99 )
goto V_107;
}
V_98 = snprintf ( V_100 , V_99 , L_82 ) ;
if ( V_99 < V_98 )
V_98 = V_99 ;
V_99 -= V_98 ;
V_100 += V_98 ;
V_107:
* V_92 = V_99 ;
* V_91 = V_100 ;
}
static T_6 F_47 ( struct V_108 * V_8 )
{
struct V_109 * V_110 ;
struct V_1 * V_2 ;
unsigned long V_111 ;
unsigned V_98 , V_99 ;
char * V_100 ;
struct V_19 * V_20 ;
V_110 = F_48 ( V_8 -> V_86 ) ;
V_2 = F_49 ( V_110 ) ;
V_100 = V_8 -> V_112 ;
V_99 = V_8 -> V_113 ;
* V_100 = 0 ;
F_50 ( & V_2 -> V_114 , V_111 ) ;
for ( V_20 = V_2 -> V_103 -> V_115 . V_20 ; V_99 > 0 && V_20 ; V_20 = V_20 -> V_115 . V_20 )
F_39 ( V_2 , V_20 , & V_100 , & V_99 ) ;
if ( V_2 -> V_116 && V_99 > 0 ) {
V_98 = F_30 ( V_100 , V_99 , L_83 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
for ( V_20 = V_2 -> V_116 ; V_99 > 0 && V_20 ;
V_20 = V_20 -> V_117 )
F_39 ( V_2 , V_20 , & V_100 , & V_99 ) ;
}
F_51 ( & V_2 -> V_114 , V_111 ) ;
return strlen ( V_8 -> V_112 ) ;
}
static T_6 F_52 ( struct V_108 * V_8 )
{
struct V_109 * V_110 ;
struct V_1 * V_2 ;
unsigned long V_111 ;
union V_118 V_119 , * V_120 ;
unsigned V_98 , V_99 , V_121 ;
char * V_100 ;
unsigned V_7 ;
T_3 V_122 ;
if ( ! ( V_120 = F_53 ( V_123 * sizeof *V_120 , V_124 ) ) )
return 0 ;
V_121 = 0 ;
V_110 = F_48 ( V_8 -> V_86 ) ;
V_2 = F_49 ( V_110 ) ;
V_100 = V_8 -> V_112 ;
V_99 = V_8 -> V_113 ;
V_98 = F_30 ( V_100 , V_99 , L_84 , V_2 -> V_125 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
F_50 ( & V_2 -> V_114 , V_111 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_125 ; V_7 ++ ) {
V_119 = V_2 -> V_126 [ V_7 ] ;
if ( F_54 ( ! V_119 . V_127 ) )
continue;
V_122 = F_55 ( V_2 , V_2 -> V_128 [ V_7 ] ) ;
V_98 = F_30 ( V_100 , V_99 , L_85 , V_7 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
do {
struct V_21 * V_22 ;
switch ( F_27 ( V_2 , V_122 ) ) {
case V_129 :
V_22 = V_119 . V_20 -> V_22 ;
V_98 = F_30 ( V_100 , V_99 , L_86 ,
V_119 . V_20 -> V_130 ,
F_24 ( V_2 ,
& V_22 -> V_24 )
& ( V_131 | V_132 ) ,
V_119 . V_20 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
for ( V_98 = 0 ; V_98 < V_121 ; V_98 ++ ) {
if ( V_120 [ V_98 ] . V_127 != V_119 . V_127 )
continue;
if ( V_119 . V_20 -> V_115 . V_127 ) {
V_98 = F_30 ( V_100 , V_99 ,
L_87 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
}
break;
}
if ( V_98 == V_121 ) {
T_1 V_93 = F_24 ( V_2 ,
& V_22 -> V_23 ) ;
struct V_13 * V_14 ;
char * type = L_3 ;
V_98 = 0 ;
F_56 (qtd,
&p.qh->qtd_list,
qtd_list) {
V_98 ++ ;
switch ( 0x03 & ( F_27 (
V_2 ,
V_14 -> V_17 ) >> 8 ) ) {
case 0 : type = L_79 ; continue;
case 1 : type = L_80 ; continue;
}
}
V_98 = F_30 ( V_100 , V_99 ,
L_88
L_89 ,
F_42 ( V_93 ) ,
V_93 & 0x007f ,
( V_93 >> 8 ) & 0x000f , type ,
V_119 . V_20 -> V_133 , V_119 . V_20 -> V_134 ,
V_98 ,
0x7ff & ( V_93 >> 16 ) ) ;
if ( V_121 < V_123 )
V_120 [ V_121 ++ ] . V_20 = V_119 . V_20 ;
} else
V_98 = 0 ;
if ( V_119 . V_20 ) {
V_122 = F_55 ( V_2 , V_22 -> V_15 ) ;
V_119 = V_119 . V_20 -> V_115 ;
}
break;
case V_135 :
V_98 = F_30 ( V_100 , V_99 ,
L_90 , V_119 . V_136 -> V_137 ,
V_119 . V_136 ) ;
V_122 = F_55 ( V_2 , V_119 . V_136 -> V_15 ) ;
V_119 = V_119 . V_136 -> V_138 ;
break;
case V_139 :
V_98 = F_30 ( V_100 , V_99 ,
L_91 , V_119 . V_28 ) ;
V_122 = F_55 ( V_2 , V_119 . V_28 -> V_15 ) ;
V_119 = V_119 . V_28 -> V_140 ;
break;
case V_141 :
V_98 = F_30 ( V_100 , V_99 ,
L_92 ,
V_119 . V_35 -> V_142 -> V_143 ,
F_24 ( V_2 , & V_119 . V_35 -> V_37 )
& 0x0000ffff ,
V_119 . V_35 ) ;
V_122 = F_55 ( V_2 , V_119 . V_35 -> V_15 ) ;
V_119 = V_119 . V_35 -> V_144 ;
break;
}
V_99 -= V_98 ;
V_100 += V_98 ;
} while ( V_119 . V_127 );
V_98 = F_30 ( V_100 , V_99 , L_82 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
}
F_51 ( & V_2 -> V_114 , V_111 ) ;
F_57 ( V_120 ) ;
return V_8 -> V_113 - V_99 ;
}
static const char * F_58 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_145 ) {
case V_146 :
return L_93 ;
case V_147 :
return L_94 ;
case V_148 :
return L_95 ;
case V_149 :
return L_96 ;
}
return L_58 ;
}
static T_6 F_59 ( struct V_108 * V_8 )
{
struct V_109 * V_110 ;
struct V_1 * V_2 ;
unsigned long V_111 ;
unsigned V_98 , V_99 , V_7 ;
char * V_100 , V_93 [ 80 ] ;
static char V_150 [] = L_97 ;
static char V_3 [] = L_3 ;
V_110 = F_48 ( V_8 -> V_86 ) ;
V_2 = F_49 ( V_110 ) ;
V_100 = V_8 -> V_112 ;
V_99 = V_8 -> V_113 ;
F_50 ( & V_2 -> V_114 , V_111 ) ;
if ( ! F_60 ( V_110 ) ) {
V_99 = F_30 ( V_100 , V_99 ,
L_98
L_99
L_100 ,
V_110 -> V_151 . V_152 -> V_86 -> V_153 ,
F_61 ( V_110 -> V_151 . V_152 ) ,
V_110 -> V_154 ) ;
goto V_107;
}
V_7 = F_62 ( V_2 , F_3 ( V_2 , & V_2 -> V_5 -> V_155 ) ) ;
V_98 = F_30 ( V_100 , V_99 ,
L_98
L_99
L_101 ,
V_110 -> V_151 . V_152 -> V_86 -> V_153 ,
F_61 ( V_110 -> V_151 . V_152 ) ,
V_110 -> V_154 ,
V_7 >> 8 , V_7 & 0x0ff , F_58 ( V_2 ) ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
#ifdef F_63
if ( V_110 -> V_151 . V_152 -> V_86 == & V_156 ) {
struct V_157 * V_158 ;
T_1 V_159 , V_160 , V_161 ;
unsigned V_162 = 256 / 4 ;
V_158 = F_64 ( F_65 ( V_2 ) -> V_151 . V_152 ) ;
V_159 = F_66 ( F_3 ( V_2 ,
& V_2 -> V_5 -> V_12 ) ) ;
while ( V_159 && V_162 -- ) {
F_67 ( V_158 , V_159 , & V_160 ) ;
switch ( V_160 & 0xff ) {
case 1 :
V_98 = F_30 ( V_100 , V_99 ,
L_102 , V_160 ,
( V_160 & ( 1 << 24 ) ) ? L_103 : L_3 ,
( V_160 & ( 1 << 16 ) ) ? L_104 : L_3 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
V_159 += 4 ;
F_67 ( V_158 , V_159 , & V_161 ) ;
V_98 = F_30 ( V_100 , V_99 ,
L_105 , V_161 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
break;
case 0 :
V_160 = 0 ;
default:
break;
}
V_98 = ( V_160 >> 8 ) & 0xff ;
}
}
#endif
V_7 = F_3 ( V_2 , & V_2 -> V_5 -> V_6 ) ;
V_98 = F_30 ( V_100 , V_99 , L_106 , V_7 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
V_7 = F_3 ( V_2 , & V_2 -> V_5 -> V_12 ) ;
V_98 = F_30 ( V_100 , V_99 , L_107 , V_7 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
V_98 = F_29 ( V_93 , sizeof V_93 , V_3 ,
F_3 ( V_2 , & V_2 -> V_163 -> V_40 ) ) ;
V_98 = F_30 ( V_100 , V_99 , V_150 , V_98 , V_93 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
V_98 = F_32 ( V_93 , sizeof V_93 , V_3 ,
F_3 ( V_2 , & V_2 -> V_163 -> V_53 ) ) ;
V_98 = F_30 ( V_100 , V_99 , V_150 , V_98 , V_93 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
V_98 = F_31 ( V_93 , sizeof V_93 , V_3 ,
F_3 ( V_2 , & V_2 -> V_163 -> V_164 ) ) ;
V_98 = F_30 ( V_100 , V_99 , V_150 , V_98 , V_93 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
V_98 = F_30 ( V_100 , V_99 , L_108 ,
F_68 ( V_2 ) ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
for ( V_7 = 1 ; V_7 <= F_11 ( V_2 -> V_6 ) ; V_7 ++ ) {
V_98 = F_34 ( V_93 , sizeof V_93 , V_3 , V_7 ,
F_3 ( V_2 ,
& V_2 -> V_163 -> V_165 [ V_7 - 1 ] ) ) ;
V_98 = F_30 ( V_100 , V_99 , V_150 , V_98 , V_93 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
if ( V_7 == F_5 ( V_2 -> V_6 ) && V_2 -> V_166 ) {
V_98 = F_30 ( V_100 , V_99 ,
L_109 ,
F_3 ( V_2 ,
& V_2 -> V_166 -> V_167 ) ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
}
}
if ( V_2 -> V_116 ) {
V_98 = F_30 ( V_100 , V_99 , L_110 ,
V_2 -> V_116 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
}
#ifdef F_69
V_98 = F_30 ( V_100 , V_99 ,
L_111 ,
V_2 -> V_168 . V_169 , V_2 -> V_168 . error , V_2 -> V_168 . V_170 ,
V_2 -> V_168 . V_171 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
V_98 = F_30 ( V_100 , V_99 , L_112 ,
V_2 -> V_168 . V_172 , V_2 -> V_168 . V_173 ) ;
V_99 -= V_98 ;
V_100 += V_98 ;
#endif
V_107:
F_51 ( & V_2 -> V_114 , V_111 ) ;
return V_8 -> V_113 - V_99 ;
}
static struct V_108 * F_70 ( struct V_174 * V_86 ,
T_6 (* F_71)( struct V_108 * ) )
{
struct V_108 * V_8 ;
V_8 = F_72 ( sizeof( struct V_108 ) , V_175 ) ;
if ( V_8 ) {
V_8 -> V_86 = V_86 ;
V_8 -> F_71 = F_71 ;
F_73 ( & V_8 -> V_176 ) ;
V_8 -> V_113 = V_177 ;
}
return V_8 ;
}
static int F_74 ( struct V_108 * V_8 )
{
int V_178 = 0 ;
if ( ! V_8 -> V_112 )
V_8 -> V_112 = F_75 ( V_8 -> V_113 ) ;
if ( ! V_8 -> V_112 ) {
V_178 = - V_179 ;
goto V_180;
}
V_178 = V_8 -> F_71 ( V_8 ) ;
if ( V_178 >= 0 ) {
V_8 -> V_162 = V_178 ;
V_178 = 0 ;
}
V_180:
return V_178 ;
}
static T_6 F_76 ( struct V_181 * V_181 , char T_7 * V_182 ,
T_8 V_39 , T_9 * V_159 )
{
struct V_108 * V_8 = V_181 -> V_183 ;
int V_178 = 0 ;
F_77 ( & V_8 -> V_176 ) ;
if ( V_8 -> V_162 == 0 ) {
V_178 = F_74 ( V_8 ) ;
if ( V_178 != 0 ) {
F_78 ( & V_8 -> V_176 ) ;
goto V_180;
}
}
F_78 ( & V_8 -> V_176 ) ;
V_178 = F_79 ( V_182 , V_39 , V_159 ,
V_8 -> V_112 , V_8 -> V_162 ) ;
V_180:
return V_178 ;
}
static int F_80 ( struct V_184 * V_184 , struct V_181 * V_181 )
{
struct V_108 * V_8 = V_181 -> V_183 ;
if ( V_8 ) {
F_81 ( V_8 -> V_112 ) ;
F_57 ( V_8 ) ;
}
return 0 ;
}
static int F_82 ( struct V_184 * V_184 , struct V_181 * V_181 )
{
V_181 -> V_183 = F_70 ( V_184 -> V_185 , F_47 ) ;
return V_181 -> V_183 ? 0 : - V_179 ;
}
static int F_83 ( struct V_184 * V_184 , struct V_181 * V_181 )
{
struct V_108 * V_8 ;
V_8 = F_70 ( V_184 -> V_185 , F_52 ) ;
if ( ! V_8 )
return - V_179 ;
V_8 -> V_113 = ( sizeof( void * ) == 4 ? 6 : 8 ) * V_177 ;
V_181 -> V_183 = V_8 ;
return 0 ;
}
static int F_84 ( struct V_184 * V_184 , struct V_181 * V_181 )
{
V_181 -> V_183 = F_70 ( V_184 -> V_185 ,
F_59 ) ;
return V_181 -> V_183 ? 0 : - V_179 ;
}
static int F_85 ( struct V_184 * V_184 , struct V_181 * V_181 )
{
return 0 ;
}
static T_6 F_86 ( struct V_181 * V_181 , char T_7 * V_182 ,
T_8 V_162 , T_9 * V_186 )
{
return 0 ;
}
static T_6 F_87 ( struct V_181 * V_181 , const char T_7 * V_182 ,
T_8 V_162 , T_9 * V_186 )
{
struct V_109 * V_110 ;
struct V_1 * V_2 ;
char V_8 [ 50 ] ;
T_8 V_39 ;
T_1 V_98 ;
unsigned long V_67 ;
T_1 T_10 * V_187 ;
T_1 V_4 ;
V_110 = F_48 ( V_181 -> V_183 ) ;
V_2 = F_49 ( V_110 ) ;
V_39 = F_88 ( V_162 , sizeof( V_8 ) - 1 ) ;
if ( F_89 ( V_8 , V_182 , V_39 ) )
return - V_188 ;
V_8 [ V_39 ] = '\0' ;
if ( V_39 > 0 && V_8 [ V_39 - 1 ] == '\n' )
V_8 [ V_39 - 1 ] = '\0' ;
if ( strncmp ( V_8 , L_113 , 5 ) == 0 ) {
if ( F_90 ( V_8 + 7 , 10 , & V_67 ) )
return - V_189 ;
V_4 = F_3 ( V_2 , & V_2 -> V_5 -> V_6 ) ;
if ( V_67 > F_11 ( V_4 ) ) {
F_4 ( V_2 , L_114 , V_67 ) ;
return - V_190 ;
}
V_187 = & V_2 -> V_163 -> V_165 [ V_67 - 1 ] ;
V_98 = F_3 ( V_2 , V_187 ) ;
if ( ! ( V_98 & V_191 ) ) {
F_4 ( V_2 , L_115 ) ;
return - V_190 ;
}
V_98 |= V_76 ;
F_91 ( V_2 , V_98 , V_187 ) ;
F_92 ( V_192 L_116 , V_67 ) ;
} else if ( strncmp ( V_8 , L_117 , 5 ) == 0 ) {
unsigned long V_193 ;
if ( F_90 ( V_8 + 5 , 16 , & V_193 ) )
return - V_189 ;
F_92 ( V_192 L_118 , V_8 + 6 , V_193 ) ;
V_2 -> V_53 = ( V_2 -> V_53 & ~ V_54 ) | ( V_193 << 24 ) ;
F_91 ( V_2 , V_2 -> V_53 , & V_2 -> V_163 -> V_53 ) ;
} else if ( strncmp ( V_8 , L_119 , 7 ) == 0 ) {
if ( F_90 ( V_8 + 8 , 10 , & V_67 ) )
return - V_189 ;
V_4 = F_3 ( V_2 , & V_2 -> V_5 -> V_6 ) ;
if ( V_67 > F_11 ( V_4 ) ) {
F_4 ( V_2 , L_120 , V_67 ) ;
return - V_190 ;
}
V_187 = & V_2 -> V_163 -> V_165 [ V_67 - 1 ] ;
V_98 = F_3 ( V_2 , V_187 ) ;
if ( ! ( V_98 & V_191 ) ) {
F_4 ( V_2 , L_121 ) ;
return - V_190 ;
}
V_98 &= ~ V_76 ;
F_91 ( V_2 , V_98 , V_187 ) ;
F_92 ( V_192 L_122 , V_67 ) ;
} else
return - V_194 ;
return V_162 ;
}
static inline void F_35 ( struct V_1 * V_2 )
{
struct V_174 * V_86 = & F_65 ( V_2 ) -> V_151 ;
V_2 -> V_195 = F_93 ( V_86 -> V_196 , V_197 ) ;
if ( ! V_2 -> V_195 )
return;
if ( ! F_94 ( L_123 , V_198 , V_2 -> V_195 , V_86 ,
& V_199 ) )
goto V_200;
if ( ! F_94 ( L_124 , V_198 , V_2 -> V_195 , V_86 ,
& V_201 ) )
goto V_200;
if ( ! F_94 ( L_125 , V_198 , V_2 -> V_195 , V_86 ,
& V_202 ) )
goto V_200;
if ( ! F_94 ( L_126 , V_198 | V_203 , V_2 -> V_195 , V_86 ,
& V_204 ) )
goto V_200;
return;
V_200:
F_95 ( V_2 -> V_195 ) ;
}
static inline void F_36 ( struct V_1 * V_2 )
{
F_95 ( V_2 -> V_195 ) ;
}
