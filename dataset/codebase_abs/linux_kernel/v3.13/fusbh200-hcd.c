static inline void F_1 ( struct V_1 * V_2 , ... ) {}
static void F_2 ( struct V_1 * V_2 , char * V_3 )
{
T_1 V_4 = F_3 ( V_2 , & V_2 -> V_5 -> V_6 ) ;
F_4 ( V_2 ,
L_1 ,
V_3 , V_4 ,
F_5 ( V_4 )
) ;
}
static inline void F_2 ( struct V_1 * V_2 , char * V_3 ) {}
static void F_6 ( struct V_1 * V_2 , char * V_3 )
{
T_1 V_4 = F_3 ( V_2 , & V_2 -> V_5 -> V_7 ) ;
F_4 ( V_2 ,
L_2 ,
V_3 ,
V_4 ,
F_7 ( V_4 ) ? L_3 : L_4 ,
F_8 ( V_4 ) ? L_5 : L_6 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , char * V_3 ) {}
static void T_2
F_9 ( const char * V_3 , struct V_1 * V_2 , struct V_8 * V_9 )
{
F_4 ( V_2 , L_7 , V_3 , V_9 ,
F_10 ( V_2 , & V_9 -> V_10 ) ,
F_10 ( V_2 , & V_9 -> V_11 ) ,
F_10 ( V_2 , & V_9 -> V_12 ) ,
F_10 ( V_2 , & V_9 -> V_13 [ 0 ] ) ) ;
if ( V_9 -> V_13 [ 1 ] )
F_4 ( V_2 , L_8 ,
F_10 ( V_2 , & V_9 -> V_13 [ 1 ] ) ,
F_10 ( V_2 , & V_9 -> V_13 [ 2 ] ) ,
F_10 ( V_2 , & V_9 -> V_13 [ 3 ] ) ,
F_10 ( V_2 , & V_9 -> V_13 [ 4 ] ) ) ;
}
static void T_2
F_11 ( const char * V_3 , struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
F_4 ( V_2 , L_9 , V_3 ,
V_15 , V_17 -> V_10 , V_17 -> V_18 , V_17 -> V_19 , V_17 -> V_20 ) ;
F_9 ( L_10 , V_2 , (struct V_8 * ) & V_17 -> V_21 ) ;
}
static void T_2
F_12 ( const char * V_3 , struct V_1 * V_2 , struct V_22 * V_23 )
{
F_4 ( V_2 , L_11 ,
V_3 , V_23 -> V_24 , V_23 , F_13 ( V_2 , V_23 -> V_10 ) ,
V_23 -> V_25 ) ;
F_4 ( V_2 ,
L_12 ,
F_13 ( V_2 , V_23 -> V_26 [ 0 ] ) ,
F_13 ( V_2 , V_23 -> V_26 [ 1 ] ) ,
F_13 ( V_2 , V_23 -> V_26 [ 2 ] ) ,
F_13 ( V_2 , V_23 -> V_26 [ 3 ] ) ,
F_13 ( V_2 , V_23 -> V_26 [ 4 ] ) ,
F_13 ( V_2 , V_23 -> V_26 [ 5 ] ) ,
F_13 ( V_2 , V_23 -> V_26 [ 6 ] ) ,
F_13 ( V_2 , V_23 -> V_26 [ 7 ] ) ) ;
F_4 ( V_2 ,
L_13 ,
F_13 ( V_2 , V_23 -> V_27 [ 0 ] ) ,
F_13 ( V_2 , V_23 -> V_27 [ 1 ] ) ,
F_13 ( V_2 , V_23 -> V_27 [ 2 ] ) ,
F_13 ( V_2 , V_23 -> V_27 [ 3 ] ) ,
F_13 ( V_2 , V_23 -> V_27 [ 4 ] ) ,
F_13 ( V_2 , V_23 -> V_27 [ 5 ] ) ,
F_13 ( V_2 , V_23 -> V_27 [ 6 ] ) ) ;
F_4 ( V_2 , L_14 ,
V_23 -> V_28 [ 0 ] , V_23 -> V_28 [ 1 ] , V_23 -> V_28 [ 2 ] ,
V_23 -> V_28 [ 3 ] , V_23 -> V_28 [ 4 ] , V_23 -> V_28 [ 5 ] ,
V_23 -> V_28 [ 6 ] , V_23 -> V_28 [ 7 ] ) ;
}
static int T_2
F_14 ( char * V_29 , unsigned V_30 , const char * V_3 , T_1 V_31 )
{
return F_15 ( V_29 , V_30 ,
L_15 ,
V_3 , V_3 [ 0 ] ? L_16 : L_6 , V_31 ,
( V_31 & V_32 ) ? L_17 : L_6 ,
( V_31 & V_33 ) ? L_18 : L_6 ,
( V_31 & V_34 ) ? L_19 : L_6 ,
( V_31 & V_35 ) ? L_20 : L_6 ,
( V_31 & V_36 ) ? L_21 : L_6 ,
( V_31 & V_37 ) ? L_22 : L_6 ,
( V_31 & V_38 ) ? L_23 : L_6 ,
( V_31 & V_39 ) ? L_24 : L_6 ,
( V_31 & V_40 ) ? L_25 : L_6 ,
( V_31 & V_41 ) ? L_26 : L_6
) ;
}
static int T_2
F_16 ( char * V_29 , unsigned V_30 , const char * V_3 , T_1 V_42 )
{
return F_15 ( V_29 , V_30 ,
L_27 ,
V_3 , V_3 [ 0 ] ? L_16 : L_6 , V_42 ,
( V_42 & V_36 ) ? L_21 : L_6 ,
( V_42 & V_37 ) ? L_22 : L_6 ,
( V_42 & V_38 ) ? L_23 : L_6 ,
( V_42 & V_39 ) ? L_24 : L_6 ,
( V_42 & V_40 ) ? L_25 : L_6 ,
( V_42 & V_41 ) ? L_26 : L_6
) ;
}
static int
F_17 ( char * V_29 , unsigned V_30 , const char * V_3 , T_1 V_43 )
{
return F_15 ( V_29 , V_30 ,
L_28
L_29 ,
V_3 , V_3 [ 0 ] ? L_16 : L_6 , V_43 ,
( V_43 & V_44 ) ? L_5 : L_30 ,
F_18 ( V_43 ) ,
( V_43 >> 16 ) & 0x3f ,
( V_43 & V_45 ) ? L_31 : L_6 ,
( V_43 & V_46 ) ? L_17 : L_6 ,
( V_43 & V_47 ) ? L_18 : L_6 ,
V_48 [ ( V_43 >> 2 ) & 0x3 ] ,
( V_43 & V_49 ) ? L_32 : L_6 ,
( V_43 & V_50 ) ? L_33 : L_34
) ;
}
static int
F_19 ( char * V_29 , unsigned V_30 , const char * V_3 , int V_51 , T_1 V_31 )
{
char * V_52 ;
switch ( V_31 & ( 3 << 10 ) ) {
case 0 << 10 : V_52 = L_35 ; break;
case 1 << 10 : V_52 = L_36 ; break;
case 2 << 10 : V_52 = L_37 ; break;
default: V_52 = L_38 ; break;
}
return F_15 ( V_29 , V_30 ,
L_39
L_40 ,
V_3 , V_3 [ 0 ] ? L_16 : L_6 , V_51 , V_31 ,
V_31 >> 25 ,
V_52 ,
( V_31 & V_53 ) ? L_41 : L_6 ,
( V_31 & V_54 ) ? L_42 : L_6 ,
( V_31 & V_55 ) ? L_43 : L_6 ,
( V_31 & V_56 ) ? L_44 : L_6 ,
( V_31 & V_57 ) ? L_45 : L_6 ,
( V_31 & V_58 ) ? L_46 : L_6 ,
( V_31 & V_59 ) ? L_47 : L_6 ) ;
}
static inline void T_2
F_11 ( char * V_3 , struct V_1 * V_2 , struct V_14 * V_15 )
{}
static inline int T_2
F_14 ( char * V_29 , unsigned V_30 , const char * V_3 , T_1 V_31 )
{ return 0 ; }
static inline int T_2
F_17 ( char * V_29 , unsigned V_30 , const char * V_3 , T_1 V_43 )
{ return 0 ; }
static inline int T_2
F_16 ( char * V_29 , unsigned V_30 , const char * V_3 , T_1 V_42 )
{ return 0 ; }
static inline int T_2
F_19 ( char * V_29 , unsigned V_30 , const char * V_3 , int V_51 , T_1 V_31 )
{ return 0 ; }
static inline void F_20 ( struct V_1 * V_60 ) { }
static inline void F_21 ( struct V_1 * V_60 ) { }
static inline char F_22 ( struct V_1 * V_2 , T_3 V_61 )
{
T_4 V_62 = F_13 ( V_2 , V_61 ) ;
if ( V_62 & V_63 )
return '*' ;
if ( V_62 & V_64 )
return '-' ;
if ( ! F_23 ( V_62 ) )
return ' ' ;
return '/' ;
}
static void F_24 (
struct V_1 * V_2 ,
struct V_14 * V_15 ,
char * * V_65 ,
unsigned * V_66
)
{
T_1 V_67 ;
T_1 V_68 ;
struct V_8 * V_69 ;
unsigned V_70 ;
unsigned V_71 = * V_66 ;
char * V_72 = * V_65 ;
char V_73 ;
T_5 V_74 = F_25 ( V_2 ) ;
struct V_16 * V_17 = V_15 -> V_17 ;
if ( V_17 -> V_21 == V_74 )
V_73 = '@' ;
else
V_73 = F_22 ( V_2 , V_17 -> V_12 ) ;
if ( V_73 == '/' ) {
if ( ( V_17 -> V_11 & F_26 ( V_2 ) )
== V_2 -> V_75 -> V_17 -> V_11 )
V_73 = '#' ;
else if ( V_17 -> V_11 == V_74 )
V_73 = '.' ;
}
V_67 = F_10 ( V_2 , & V_17 -> V_18 ) ;
V_68 = ( V_73 == '*' ) ? F_10 ( V_2 , & V_17 -> V_20 ) : 0 ;
V_70 = F_15 ( V_72 , V_71 ,
L_48 ,
V_15 , V_67 & 0x007f ,
F_27 ( V_67 ) ,
( V_67 >> 8 ) & 0x000f ,
V_67 , F_10 ( V_2 , & V_17 -> V_19 ) ,
F_10 ( V_2 , & V_17 -> V_12 ) , V_73 ,
( F_28 ( V_2 , V_76 ) & V_17 -> V_12 )
? L_49 : L_50 ,
( F_10 ( V_2 , & V_17 -> V_11 ) >> 1 ) & 0x0f ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
F_29 (td, &qh->qtd_list, qtd_list) {
V_67 = F_10 ( V_2 , & V_69 -> V_12 ) ;
V_73 = ' ' ;
if ( V_68 == V_69 -> V_77 )
V_73 = '*' ;
else if ( V_17 -> V_21 == F_28 ( V_2 , V_69 -> V_77 ) )
V_73 = '+' ;
else if ( F_30 ( V_67 ) ) {
if ( V_69 -> V_11 == V_2 -> V_75 -> V_17 -> V_11 )
V_73 = '#' ;
else if ( V_69 -> V_11 != V_74 )
V_73 = '/' ;
}
V_70 = snprintf (next, size,
L_51 ,
td, mark, ({ char *tmp;
switch ((scratch>>8)&0x03) {
case 0: tmp = L_52; break;
case 1: tmp = L_53; break;
case 2: tmp = L_54; break;
default: tmp = L_38; break;
} tmp;}),
(scratch >> 16) & 0x7fff ,
scratch,
td->urb) ;
if ( V_71 < V_70 )
V_70 = V_71 ;
V_71 -= V_70 ;
V_72 += V_70 ;
if ( V_70 == V_71 )
goto V_78;
}
V_70 = snprintf ( V_72 , V_71 , L_55 ) ;
if ( V_71 < V_70 )
V_70 = V_71 ;
V_71 -= V_70 ;
V_72 += V_70 ;
V_78:
* V_66 = V_71 ;
* V_65 = V_72 ;
}
static T_6 F_31 ( struct V_79 * V_29 )
{
struct V_80 * V_81 ;
struct V_1 * V_2 ;
unsigned long V_82 ;
unsigned V_70 , V_71 ;
char * V_72 ;
struct V_14 * V_15 ;
V_81 = F_32 ( V_29 -> V_60 ) ;
V_2 = F_33 ( V_81 ) ;
V_72 = V_29 -> V_83 ;
V_71 = V_29 -> V_84 ;
* V_72 = 0 ;
F_34 ( & V_2 -> V_85 , V_82 ) ;
for ( V_15 = V_2 -> V_75 -> V_86 . V_15 ; V_71 > 0 && V_15 ; V_15 = V_15 -> V_86 . V_15 )
F_24 ( V_2 , V_15 , & V_72 , & V_71 ) ;
if ( V_2 -> V_87 && V_71 > 0 ) {
V_70 = F_15 ( V_72 , V_71 , L_56 ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
for ( V_15 = V_2 -> V_87 ; V_71 > 0 && V_15 ;
V_15 = V_15 -> V_88 )
F_24 ( V_2 , V_15 , & V_72 , & V_71 ) ;
}
F_35 ( & V_2 -> V_85 , V_82 ) ;
return strlen ( V_29 -> V_83 ) ;
}
static T_6 F_36 ( struct V_79 * V_29 )
{
struct V_80 * V_81 ;
struct V_1 * V_2 ;
unsigned long V_82 ;
union V_89 V_90 , * V_91 ;
unsigned V_70 , V_71 , V_92 ;
char * V_72 ;
unsigned V_93 ;
T_3 V_94 ;
if ( ! ( V_91 = F_37 ( V_95 * sizeof *V_91 , V_96 ) ) )
return 0 ;
V_92 = 0 ;
V_81 = F_32 ( V_29 -> V_60 ) ;
V_2 = F_33 ( V_81 ) ;
V_72 = V_29 -> V_83 ;
V_71 = V_29 -> V_84 ;
V_70 = F_15 ( V_72 , V_71 , L_57 , V_2 -> V_97 ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
F_34 ( & V_2 -> V_85 , V_82 ) ;
for ( V_93 = 0 ; V_93 < V_2 -> V_97 ; V_93 ++ ) {
V_90 = V_2 -> V_98 [ V_93 ] ;
if ( F_38 ( ! V_90 . V_99 ) )
continue;
V_94 = F_39 ( V_2 , V_2 -> V_100 [ V_93 ] ) ;
V_70 = F_15 ( V_72 , V_71 , L_58 , V_93 ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
do {
struct V_16 * V_17 ;
switch ( F_13 ( V_2 , V_94 ) ) {
case V_101 :
V_17 = V_90 . V_15 -> V_17 ;
V_70 = F_15 ( V_72 , V_71 , L_59 ,
V_90 . V_15 -> V_102 ,
F_10 ( V_2 ,
& V_17 -> V_19 )
& ( V_103 | V_104 ) ,
V_90 . V_15 ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
for ( V_70 = 0 ; V_70 < V_92 ; V_70 ++ ) {
if ( V_91 [ V_70 ] . V_99 != V_90 . V_99 )
continue;
if ( V_90 . V_15 -> V_86 . V_99 ) {
V_70 = F_15 ( V_72 , V_71 ,
L_60 ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
}
break;
}
if ( V_70 == V_92 ) {
T_1 V_67 = F_10 ( V_2 ,
& V_17 -> V_18 ) ;
struct V_8 * V_9 ;
char * type = L_6 ;
V_70 = 0 ;
F_29 (qtd,
&p.qh->qtd_list,
qtd_list) {
V_70 ++ ;
switch ( 0x03 & ( F_13 (
V_2 ,
V_9 -> V_12 ) >> 8 ) ) {
case 0 : type = L_52 ; continue;
case 1 : type = L_53 ; continue;
}
}
V_70 = F_15 ( V_72 , V_71 ,
L_61
L_62 ,
F_27 ( V_67 ) ,
V_67 & 0x007f ,
( V_67 >> 8 ) & 0x000f , type ,
V_90 . V_15 -> V_105 , V_90 . V_15 -> V_106 ,
V_70 ,
0x7ff & ( V_67 >> 16 ) ) ;
if ( V_92 < V_95 )
V_91 [ V_92 ++ ] . V_15 = V_90 . V_15 ;
} else
V_70 = 0 ;
V_94 = F_39 ( V_2 , V_17 -> V_10 ) ;
V_90 = V_90 . V_15 -> V_86 ;
break;
case V_107 :
V_70 = F_15 ( V_72 , V_71 ,
L_63 , V_90 . V_108 -> V_109 ,
V_90 . V_108 ) ;
V_94 = F_39 ( V_2 , V_90 . V_108 -> V_10 ) ;
V_90 = V_90 . V_108 -> V_110 ;
break;
case V_111 :
V_70 = F_15 ( V_72 , V_71 ,
L_64 , V_90 . V_23 ) ;
V_94 = F_39 ( V_2 , V_90 . V_23 -> V_10 ) ;
V_90 = V_90 . V_23 -> V_112 ;
break;
}
V_71 -= V_70 ;
V_72 += V_70 ;
} while ( V_90 . V_99 );
V_70 = F_15 ( V_72 , V_71 , L_55 ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
}
F_35 ( & V_2 -> V_85 , V_82 ) ;
F_40 ( V_91 ) ;
return V_29 -> V_84 - V_71 ;
}
static const char * F_41 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_113 ) {
case V_114 :
return L_65 ;
case V_115 :
return L_66 ;
case V_116 :
return L_67 ;
case V_117 :
return L_68 ;
}
return L_38 ;
}
static T_6 F_42 ( struct V_79 * V_29 )
{
struct V_80 * V_81 ;
struct V_1 * V_2 ;
unsigned long V_82 ;
unsigned V_70 , V_71 , V_93 ;
char * V_72 , V_67 [ 80 ] ;
static char V_118 [] = L_69 ;
static char V_3 [] = L_6 ;
V_81 = F_32 ( V_29 -> V_60 ) ;
V_2 = F_33 ( V_81 ) ;
V_72 = V_29 -> V_83 ;
V_71 = V_29 -> V_84 ;
F_34 ( & V_2 -> V_85 , V_82 ) ;
if ( ! F_43 ( V_81 ) ) {
V_71 = F_15 ( V_72 , V_71 ,
L_70
L_71
L_72 ,
V_81 -> V_119 . V_120 -> V_60 -> V_121 ,
F_44 ( V_81 -> V_119 . V_120 ) ,
V_81 -> V_122 ) ;
goto V_78;
}
V_93 = F_45 ( V_2 , F_3 ( V_2 , & V_2 -> V_5 -> V_123 ) ) ;
V_70 = F_15 ( V_72 , V_71 ,
L_70
L_71
L_73 ,
V_81 -> V_119 . V_120 -> V_60 -> V_121 ,
F_44 ( V_81 -> V_119 . V_120 ) ,
V_81 -> V_122 ,
V_93 >> 8 , V_93 & 0x0ff , F_41 ( V_2 ) ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
V_93 = F_3 ( V_2 , & V_2 -> V_5 -> V_6 ) ;
V_70 = F_15 ( V_72 , V_71 , L_74 , V_93 ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
V_93 = F_3 ( V_2 , & V_2 -> V_5 -> V_7 ) ;
V_70 = F_15 ( V_72 , V_71 , L_75 , V_93 ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
V_70 = F_14 ( V_67 , sizeof V_67 , V_3 ,
F_3 ( V_2 , & V_2 -> V_124 -> V_31 ) ) ;
V_70 = F_15 ( V_72 , V_71 , V_118 , V_70 , V_67 ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
V_70 = F_17 ( V_67 , sizeof V_67 , V_3 ,
F_3 ( V_2 , & V_2 -> V_124 -> V_43 ) ) ;
V_70 = F_15 ( V_72 , V_71 , V_118 , V_70 , V_67 ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
V_70 = F_16 ( V_67 , sizeof V_67 , V_3 ,
F_3 ( V_2 , & V_2 -> V_124 -> V_125 ) ) ;
V_70 = F_15 ( V_72 , V_71 , V_118 , V_70 , V_67 ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
V_70 = F_15 ( V_72 , V_71 , L_76 ,
F_46 ( V_2 ) ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
if ( V_2 -> V_87 ) {
V_70 = F_15 ( V_72 , V_71 , L_77 ,
V_2 -> V_87 ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
}
#ifdef F_47
V_70 = F_15 ( V_72 , V_71 ,
L_78 ,
V_2 -> V_126 . V_127 , V_2 -> V_126 . error , V_2 -> V_126 . V_128 ,
V_2 -> V_126 . V_129 ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
V_70 = F_15 ( V_72 , V_71 , L_79 ,
V_2 -> V_126 . V_130 , V_2 -> V_126 . V_131 ) ;
V_71 -= V_70 ;
V_72 += V_70 ;
#endif
V_78:
F_35 ( & V_2 -> V_85 , V_82 ) ;
return V_29 -> V_84 - V_71 ;
}
static struct V_79 * F_48 ( struct V_132 * V_60 ,
T_6 (* F_49)( struct V_79 * ) )
{
struct V_79 * V_29 ;
V_29 = F_50 ( sizeof( struct V_79 ) , V_133 ) ;
if ( V_29 ) {
V_29 -> V_60 = V_60 ;
V_29 -> F_49 = F_49 ;
F_51 ( & V_29 -> V_134 ) ;
V_29 -> V_84 = V_135 ;
}
return V_29 ;
}
static int F_52 ( struct V_79 * V_29 )
{
int V_136 = 0 ;
if ( ! V_29 -> V_83 )
V_29 -> V_83 = F_53 ( V_29 -> V_84 ) ;
if ( ! V_29 -> V_83 ) {
V_136 = - V_137 ;
goto V_138;
}
V_136 = V_29 -> F_49 ( V_29 ) ;
if ( V_136 >= 0 ) {
V_29 -> V_139 = V_136 ;
V_136 = 0 ;
}
V_138:
return V_136 ;
}
static T_6 F_54 ( struct V_140 * V_140 , char T_7 * V_141 ,
T_8 V_30 , T_9 * V_142 )
{
struct V_79 * V_29 = V_140 -> V_143 ;
int V_136 = 0 ;
F_55 ( & V_29 -> V_134 ) ;
if ( V_29 -> V_139 == 0 ) {
V_136 = F_52 ( V_29 ) ;
if ( V_136 != 0 ) {
F_56 ( & V_29 -> V_134 ) ;
goto V_138;
}
}
F_56 ( & V_29 -> V_134 ) ;
V_136 = F_57 ( V_141 , V_30 , V_142 ,
V_29 -> V_83 , V_29 -> V_139 ) ;
V_138:
return V_136 ;
}
static int F_58 ( struct V_144 * V_144 , struct V_140 * V_140 )
{
struct V_79 * V_29 = V_140 -> V_143 ;
if ( V_29 ) {
F_59 ( V_29 -> V_83 ) ;
F_40 ( V_29 ) ;
}
return 0 ;
}
static int F_60 ( struct V_144 * V_144 , struct V_140 * V_140 )
{
V_140 -> V_143 = F_48 ( V_144 -> V_145 , F_31 ) ;
return V_140 -> V_143 ? 0 : - V_137 ;
}
static int F_61 ( struct V_144 * V_144 , struct V_140 * V_140 )
{
struct V_79 * V_29 ;
V_29 = F_48 ( V_144 -> V_145 , F_36 ) ;
if ( ! V_29 )
return - V_137 ;
V_29 -> V_84 = ( sizeof( void * ) == 4 ? 6 : 8 ) * V_135 ;
V_140 -> V_143 = V_29 ;
return 0 ;
}
static int F_62 ( struct V_144 * V_144 , struct V_140 * V_140 )
{
V_140 -> V_143 = F_48 ( V_144 -> V_145 ,
F_42 ) ;
return V_140 -> V_143 ? 0 : - V_137 ;
}
static inline void F_20 ( struct V_1 * V_2 )
{
struct V_132 * V_60 = & F_63 ( V_2 ) -> V_119 ;
V_2 -> V_146 = F_64 ( V_60 -> V_147 , V_148 ) ;
if ( ! V_2 -> V_146 )
return;
if ( ! F_65 ( L_80 , V_149 , V_2 -> V_146 , V_60 ,
& V_150 ) )
goto V_151;
if ( ! F_65 ( L_81 , V_149 , V_2 -> V_146 , V_60 ,
& V_152 ) )
goto V_151;
if ( ! F_65 ( L_82 , V_149 , V_2 -> V_146 , V_60 ,
& V_153 ) )
goto V_151;
return;
V_151:
F_66 ( V_2 -> V_146 ) ;
}
static inline void F_21 ( struct V_1 * V_2 )
{
F_66 ( V_2 -> V_146 ) ;
}
static int F_67 ( struct V_1 * V_2 , void T_10 * V_99 ,
T_1 V_154 , T_1 V_78 , int V_155 )
{
T_1 V_156 ;
do {
V_156 = F_3 ( V_2 , V_99 ) ;
if ( V_156 == ~ ( T_1 ) 0 )
return - V_157 ;
V_156 &= V_154 ;
if ( V_156 == V_78 )
return 0 ;
F_68 ( 1 ) ;
V_155 -- ;
} while ( V_155 > 0 );
return - V_158 ;
}
static int F_69 ( struct V_1 * V_2 )
{
T_1 V_70 ;
F_70 ( & V_2 -> V_85 ) ;
F_71 ( V_2 , 0 , & V_2 -> V_124 -> V_125 ) ;
V_2 -> V_43 &= ~ V_50 ;
V_70 = F_3 ( V_2 , & V_2 -> V_124 -> V_43 ) ;
V_70 &= ~ ( V_50 | V_45 ) ;
F_71 ( V_2 , V_70 , & V_2 -> V_124 -> V_43 ) ;
F_72 ( & V_2 -> V_85 ) ;
F_73 ( F_63 ( V_2 ) -> V_159 ) ;
return F_67 ( V_2 , & V_2 -> V_124 -> V_31 ,
V_35 , V_35 , 16 * 125 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_160 ;
T_1 V_43 = F_3 ( V_2 , & V_2 -> V_124 -> V_43 ) ;
if ( V_2 -> V_161 && ! F_75 ( F_63 ( V_2 ) ) )
V_2 -> V_161 = NULL ;
V_43 |= V_49 ;
F_76 ( V_2 , L_83 , V_43 ) ;
F_71 ( V_2 , V_43 , & V_2 -> V_124 -> V_43 ) ;
V_2 -> V_113 = V_114 ;
V_2 -> V_162 = V_163 ;
V_160 = F_67 ( V_2 , & V_2 -> V_124 -> V_43 ,
V_49 , 0 , 250 * 1000 ) ;
if ( V_160 )
return V_160 ;
if ( V_2 -> V_161 )
F_77 ( F_63 ( V_2 ) ) ;
V_2 -> V_164 = V_2 -> V_165 =
V_2 -> V_166 = 0 ;
return V_160 ;
}
static void F_78 ( struct V_1 * V_2 )
{
T_1 V_70 ;
if ( V_2 -> V_113 != V_116 )
return;
V_70 = ( V_2 -> V_43 << 10 ) & ( V_32 | V_33 ) ;
F_67 ( V_2 , & V_2 -> V_124 -> V_31 , V_32 | V_33 , V_70 , 16 * 125 ) ;
F_70 ( & V_2 -> V_85 ) ;
V_2 -> V_43 &= ~ ( V_46 | V_47 ) ;
F_71 ( V_2 , V_2 -> V_43 , & V_2 -> V_124 -> V_43 ) ;
F_72 ( & V_2 -> V_85 ) ;
F_67 ( V_2 , & V_2 -> V_124 -> V_31 , V_32 | V_33 , 0 , 16 * 125 ) ;
}
static void F_79 ( struct V_1 * V_2 , T_1 V_167 )
{
V_2 -> V_43 |= V_167 ;
F_71 ( V_2 , V_2 -> V_43 , & V_2 -> V_124 -> V_43 ) ;
F_3 ( V_2 , & V_2 -> V_124 -> V_43 ) ;
}
static void F_80 ( struct V_1 * V_2 , T_1 V_167 )
{
V_2 -> V_43 &= ~ V_167 ;
F_71 ( V_2 , V_2 -> V_43 , & V_2 -> V_124 -> V_43 ) ;
F_3 ( V_2 , & V_2 -> V_124 -> V_43 ) ;
}
static void F_81 ( struct V_1 * V_2 , unsigned V_168 ,
bool V_169 )
{
T_11 * V_170 = & V_2 -> V_171 [ V_168 ] ;
if ( V_169 )
* V_170 = F_82 ( F_83 () ,
F_84 ( 0 , V_172 [ V_168 ] ) ) ;
V_2 -> V_173 |= ( 1 << V_168 ) ;
if ( V_168 < V_2 -> V_174 ) {
V_2 -> V_174 = V_168 ;
F_85 ( & V_2 -> V_175 , * V_170 ,
V_176 , V_177 ) ;
}
}
static void F_86 ( struct V_1 * V_2 )
{
unsigned V_178 , V_179 ;
if ( V_2 -> V_113 != V_116 )
return;
V_179 = ( V_2 -> V_43 & V_46 ) ? V_32 : 0 ;
V_178 = F_3 ( V_2 , & V_2 -> V_124 -> V_31 ) & V_32 ;
if ( V_179 != V_178 ) {
if ( V_2 -> V_180 ++ < 20 ) {
F_81 ( V_2 , V_181 , true ) ;
return;
}
F_4 ( V_2 , L_84 ,
V_179 , V_178 ) ;
}
V_2 -> V_180 = 0 ;
if ( V_179 == 0 ) {
if ( V_2 -> V_182 > 0 )
F_79 ( V_2 , V_46 ) ;
} else {
if ( V_2 -> V_182 == 0 ) {
F_81 ( V_2 , V_183 ,
true ) ;
}
}
}
static void F_87 ( struct V_1 * V_2 )
{
F_80 ( V_2 , V_46 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
unsigned V_178 , V_179 ;
if ( V_2 -> V_113 != V_116 )
return;
V_179 = ( V_2 -> V_43 & V_47 ) ? V_33 : 0 ;
V_178 = F_3 ( V_2 , & V_2 -> V_124 -> V_31 ) & V_33 ;
if ( V_179 != V_178 ) {
if ( V_2 -> V_184 ++ < 20 ) {
F_81 ( V_2 , V_185 , true ) ;
return;
}
F_4 ( V_2 , L_85 ,
V_179 , V_178 ) ;
}
V_2 -> V_184 = 0 ;
if ( V_179 == 0 ) {
if ( V_2 -> V_186 > 0 )
F_79 ( V_2 , V_47 ) ;
} else {
if ( V_2 -> V_186 == 0 ) {
F_81 ( V_2 , V_187 ,
true ) ;
}
}
}
static void F_89 ( struct V_1 * V_2 )
{
F_80 ( V_2 , V_47 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
if ( ! ( F_3 ( V_2 , & V_2 -> V_124 -> V_31 ) & V_35 ) ) {
if ( V_2 -> V_188 ++ < 5 ) {
F_81 ( V_2 , V_189 , true ) ;
return;
}
F_91 ( V_2 , L_86 ) ;
}
V_2 -> V_113 = V_114 ;
F_71 ( V_2 , 0 , & V_2 -> V_124 -> V_125 ) ;
F_92 ( V_2 ) ;
F_93 ( V_2 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
bool V_190 = ( V_2 -> V_113 < V_116 ) ;
V_2 -> V_191 = true ;
while ( V_2 -> V_192 ) {
struct V_14 * V_15 = V_2 -> V_192 ;
if ( ! V_190 && V_15 -> V_193 == V_2 -> V_194 )
break;
V_2 -> V_192 = V_15 -> V_88 ;
V_15 -> V_88 = NULL ;
F_95 ( V_2 , V_15 ) ;
}
if ( V_2 -> V_192 ) {
F_81 ( V_2 , V_195 , true ) ;
++ V_2 -> V_194 ;
}
V_2 -> V_191 = false ;
}
static void F_96 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_173 & F_97 ( V_196 ) ) ) {
V_2 -> V_197 = F_98 (
V_2 -> V_198 . V_199 ,
struct V_22 , V_200 ) ;
F_81 ( V_2 , V_196 , true ) ;
}
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_22 * V_23 , * V_201 ;
if ( V_2 -> V_113 < V_116 ) {
V_2 -> V_197 = NULL ;
}
F_100 (itd, n, &fusbh200->cached_itd_list, itd_list) {
F_101 ( & V_23 -> V_200 ) ;
F_102 ( V_2 -> V_202 , V_23 , V_23 -> V_203 ) ;
if ( V_23 == V_2 -> V_197 )
break;
}
if ( ! F_103 ( & V_2 -> V_198 ) )
F_96 ( V_2 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
if ( V_2 -> V_113 != V_116 )
return;
if ( V_2 -> V_204 ) {
T_1 V_205 , V_31 ;
V_205 = F_3 ( V_2 , & V_2 -> V_124 -> V_43 ) ;
V_31 = F_3 ( V_2 , & V_2 -> V_124 -> V_31 ) ;
if ( ( V_31 & V_36 ) || ! ( V_205 & V_45 ) ) {
F_105 ( V_2 -> V_126 . V_129 ) ;
F_71 ( V_2 , V_36 , & V_2 -> V_124 -> V_31 ) ;
}
F_1 ( V_2 , L_87 ,
V_31 , V_205 ) ;
F_93 ( V_2 ) ;
}
}
static void F_106 ( struct V_1 * V_2 )
{
if ( V_2 -> V_113 != V_116 ||
( V_2 -> V_173 &
F_97 ( V_206 ) ) )
return;
if ( V_2 -> V_207 > 0 || ( V_2 -> V_208 &&
V_2 -> V_182 + V_2 -> V_209 > 0 ) )
F_81 ( V_2 , V_206 , true ) ;
}
static enum V_210 F_107 ( struct V_175 * V_211 )
{
struct V_1 * V_2 = F_108 ( V_211 , struct V_1 , V_175 ) ;
T_11 V_212 ;
unsigned long V_213 ;
unsigned long V_82 ;
unsigned V_214 ;
F_34 ( & V_2 -> V_85 , V_82 ) ;
V_213 = V_2 -> V_173 ;
V_2 -> V_173 = 0 ;
V_2 -> V_174 = V_215 ;
V_212 = F_83 () ;
F_109 (e, &events, FUSBH200_HRTIMER_NUM_EVENTS) {
if ( V_212 . V_216 >= V_2 -> V_171 [ V_214 ] . V_216 )
V_217 [ V_214 ] ( V_2 ) ;
else
F_81 ( V_2 , V_214 , false ) ;
}
F_35 ( & V_2 -> V_85 , V_82 ) ;
return V_218 ;
}
static int F_110 (
struct V_1 * V_2 ,
int V_28 ,
T_1 T_10 * V_219 ,
int V_220
) {
if ( ! ( V_220 & V_59 ) )
return V_220 ;
if ( ! ( V_220 & V_57 ) ) {
F_4 ( V_2 ,
L_88 ,
V_28 + 1 ) ;
return V_220 ;
} else {
F_4 ( V_2 , L_89 ,
V_28 + 1 ) ;
}
return V_220 ;
}
static int
F_111 ( struct V_80 * V_81 , char * V_29 )
{
struct V_1 * V_2 = F_33 ( V_81 ) ;
T_1 V_70 , V_31 ;
T_1 V_154 ;
int V_160 = 1 ;
unsigned long V_82 ;
V_29 [ 0 ] = 0 ;
V_31 = V_2 -> V_166 ;
V_154 = V_58 | V_56 ;
F_34 ( & V_2 -> V_85 , V_82 ) ;
V_70 = F_3 ( V_2 , & V_2 -> V_124 -> V_220 ) ;
if ( ( V_70 & V_154 ) != 0 || F_112 ( 0 , & V_2 -> V_164 )
|| ( V_2 -> V_221 [ 0 ] && F_113 (
V_163 , V_2 -> V_221 [ 0 ] ) ) ) {
V_29 [ 0 ] |= 1 << 1 ;
V_31 = V_39 ;
}
F_35 ( & V_2 -> V_85 , V_82 ) ;
return V_31 ? V_160 : 0 ;
}
static void
F_114 (
struct V_1 * V_2 ,
struct V_222 * V_223
) {
int V_224 = F_5 ( V_2 -> V_6 ) ;
T_12 V_70 ;
V_223 -> V_225 = 0x29 ;
V_223 -> V_226 = 10 ;
V_223 -> V_227 = 0 ;
V_223 -> V_228 = V_224 ;
V_70 = 1 + ( V_224 / 8 ) ;
V_223 -> V_229 = 7 + 2 * V_70 ;
memset ( & V_223 -> V_230 . V_231 . V_232 [ 0 ] , 0 , V_70 ) ;
memset ( & V_223 -> V_230 . V_231 . V_232 [ V_70 ] , 0xff , V_70 ) ;
V_70 = 0x0008 ;
V_70 |= 0x0002 ;
V_223 -> V_233 = F_115 ( V_70 ) ;
}
static int F_116 (
struct V_80 * V_81 ,
T_12 V_234 ,
T_12 V_235 ,
T_12 V_236 ,
char * V_29 ,
T_12 V_237
) {
struct V_1 * V_2 = F_33 ( V_81 ) ;
int V_224 = F_5 ( V_2 -> V_6 ) ;
T_1 T_10 * V_219 = & V_2 -> V_124 -> V_220 ;
T_1 V_70 , V_238 , V_31 ;
unsigned long V_82 ;
int V_160 = 0 ;
unsigned V_239 ;
F_34 ( & V_2 -> V_85 , V_82 ) ;
switch ( V_234 ) {
case V_240 :
switch ( V_235 ) {
case V_241 :
case V_242 :
break;
default:
goto error;
}
break;
case V_243 :
if ( ! V_236 || V_236 > V_224 )
goto error;
V_236 -- ;
V_70 = F_3 ( V_2 , V_219 ) ;
V_70 &= ~ V_244 ;
switch ( V_235 ) {
case V_245 :
F_71 ( V_2 , V_70 & ~ V_57 , V_219 ) ;
break;
case V_246 :
F_71 ( V_2 , V_70 | V_56 , V_219 ) ;
break;
case V_247 :
if ( V_70 & V_53 )
goto error;
if ( ! ( V_70 & V_54 ) )
break;
if ( ( V_70 & V_57 ) == 0 )
goto error;
F_71 ( V_2 , V_70 | V_55 , V_219 ) ;
V_2 -> V_221 [ V_236 ] = V_163
+ F_117 ( 20 ) ;
break;
case V_248 :
F_118 ( V_236 , & V_2 -> V_164 ) ;
break;
case V_249 :
F_71 ( V_2 , V_70 | V_58 , V_219 ) ;
break;
case V_250 :
F_71 ( V_2 , V_70 | V_251 , & V_2 -> V_124 -> V_252 ) ;
break;
case V_253 :
break;
default:
goto error;
}
F_3 ( V_2 , & V_2 -> V_124 -> V_43 ) ;
break;
case V_254 :
F_114 ( V_2 , (struct V_222 * )
V_29 ) ;
break;
case V_255 :
memset ( V_29 , 0 , 4 ) ;
break;
case V_256 :
if ( ! V_236 || V_236 > V_224 )
goto error;
V_236 -- ;
V_31 = 0 ;
V_70 = F_3 ( V_2 , V_219 ) ;
if ( V_70 & V_58 )
V_31 |= V_257 << 16 ;
if ( V_70 & V_56 )
V_31 |= V_258 << 16 ;
V_238 = F_3 ( V_2 , & V_2 -> V_124 -> V_252 ) ;
if ( V_238 & V_251 )
V_31 |= V_259 << 16 ;
if ( V_70 & V_55 ) {
if ( ! V_2 -> V_221 [ V_236 ] ) {
V_2 -> V_221 [ V_236 ] = V_163
+ F_117 ( 20 ) ;
F_119 ( & F_63 ( V_2 ) -> V_260 ,
V_2 -> V_221 [ V_236 ] ) ;
}
else if ( F_113 ( V_163 ,
V_2 -> V_221 [ V_236 ] ) ) {
F_118 ( V_236 , & V_2 -> V_165 ) ;
F_120 ( V_236 , & V_2 -> V_164 ) ;
V_2 -> V_221 [ V_236 ] = 0 ;
V_70 = F_3 ( V_2 , V_219 ) ;
F_71 ( V_2 ,
V_70 & ~ ( V_244 | V_55 ) ,
V_219 ) ;
F_118 ( V_236 , & V_2 -> V_166 ) ;
V_160 = F_67 ( V_2 , V_219 ,
V_55 , 0 , 2000 ) ;
if ( V_160 != 0 ) {
F_121 ( V_2 ,
L_90 ,
V_236 + 1 , V_160 ) ;
goto error;
}
V_70 &= ~ ( V_54 | V_55 | ( 3 << 10 ) ) ;
}
}
if ( ( V_70 & V_53 )
&& F_113 ( V_163 ,
V_2 -> V_221 [ V_236 ] ) ) {
V_31 |= V_261 << 16 ;
V_2 -> V_221 [ V_236 ] = 0 ;
F_118 ( V_236 , & V_2 -> V_166 ) ;
F_71 ( V_2 , V_70 & ~ ( V_244 | V_53 ) ,
V_219 ) ;
V_160 = F_67 ( V_2 , V_219 ,
V_53 , 0 , 1000 ) ;
if ( V_160 != 0 ) {
F_121 ( V_2 , L_91 ,
V_236 + 1 , V_160 ) ;
goto error;
}
V_70 = F_110 ( V_2 , V_236 , V_219 ,
F_3 ( V_2 , V_219 ) ) ;
}
if ( ! ( V_70 & ( V_55 | V_53 ) ) ) {
V_2 -> V_221 [ V_236 ] = 0 ;
F_118 ( V_236 , & V_2 -> V_166 ) ;
}
if ( ( V_70 & V_59 ) &&
F_112 ( V_236 , & V_2 -> V_262 ) ) {
V_70 &= ~ V_244 ;
F_71 ( V_2 , V_70 , V_219 ) ;
F_4 ( V_2 , L_92 , V_236 + 1 ) ;
V_70 = F_3 ( V_2 , V_219 ) ;
}
if ( V_70 & V_59 ) {
V_31 |= V_263 ;
V_31 |= F_122 ( V_2 , V_70 ) ;
}
if ( V_70 & V_57 )
V_31 |= V_264 ;
if ( V_70 & ( V_54 | V_55 ) ) {
V_31 |= V_265 ;
} else if ( F_112 ( V_236 , & V_2 -> V_165 ) ) {
F_118 ( V_236 , & V_2 -> V_165 ) ;
F_118 ( V_236 , & V_2 -> V_166 ) ;
V_2 -> V_221 [ V_236 ] = 0 ;
if ( V_70 & V_57 )
F_120 ( V_236 , & V_2 -> V_164 ) ;
}
V_238 = F_3 ( V_2 , & V_2 -> V_124 -> V_252 ) ;
if ( V_238 & V_251 )
V_31 |= V_266 ;
if ( V_70 & V_53 )
V_31 |= V_267 ;
if ( F_112 ( V_236 , & V_2 -> V_164 ) )
V_31 |= V_268 << 16 ;
#ifndef F_123
if ( V_31 & ~ 0xffff )
#endif
F_124 ( V_2 , L_93 , V_236 + 1 , V_70 ) ;
F_125 ( V_31 , V_29 ) ;
break;
case V_269 :
switch ( V_235 ) {
case V_241 :
case V_242 :
break;
default:
goto error;
}
break;
case V_270 :
V_239 = V_236 >> 8 ;
V_236 &= 0xff ;
if ( ! V_236 || V_236 > V_224 )
goto error;
V_236 -- ;
V_70 = F_3 ( V_2 , V_219 ) ;
V_70 &= ~ V_244 ;
switch ( V_235 ) {
case V_247 :
if ( ( V_70 & V_57 ) == 0
|| ( V_70 & V_53 ) != 0 )
goto error;
F_71 ( V_2 , V_70 | V_54 , V_219 ) ;
F_120 ( V_236 , & V_2 -> V_165 ) ;
break;
case V_271 :
if ( V_70 & V_55 )
goto error;
F_1 ( V_2 , L_94 , V_236 + 1 ) ;
V_70 |= V_53 ;
V_70 &= ~ V_57 ;
V_2 -> V_221 [ V_236 ] = V_163
+ F_117 ( 50 ) ;
F_71 ( V_2 , V_70 , V_219 ) ;
break;
case V_272 :
if ( ! V_239 || V_239 > 5 )
goto error;
F_35 ( & V_2 -> V_85 , V_82 ) ;
F_78 ( V_2 ) ;
F_34 ( & V_2 -> V_85 , V_82 ) ;
V_70 = F_3 ( V_2 , V_219 ) & ~ V_244 ;
if ( V_70 & V_57 )
F_71 ( V_2 , V_70 | V_54 ,
V_219 ) ;
F_35 ( & V_2 -> V_85 , V_82 ) ;
F_69 ( V_2 ) ;
F_34 ( & V_2 -> V_85 , V_82 ) ;
V_70 = F_3 ( V_2 , V_219 ) ;
V_70 |= V_239 << 16 ;
F_71 ( V_2 , V_70 , V_219 ) ;
break;
default:
goto error;
}
F_3 ( V_2 , & V_2 -> V_124 -> V_43 ) ;
break;
default:
error:
V_160 = - V_273 ;
}
F_35 ( & V_2 -> V_85 , V_82 ) ;
return V_160 ;
}
static void T_2 F_126 ( struct V_80 * V_81 ,
int V_274 )
{
return;
}
static int T_2 F_127 ( struct V_80 * V_81 ,
int V_274 )
{
return 0 ;
}
static inline void F_128 ( struct V_1 * V_2 , struct V_8 * V_9 ,
T_13 V_275 )
{
memset ( V_9 , 0 , sizeof *V_9 ) ;
V_9 -> V_77 = V_275 ;
V_9 -> V_12 = F_28 ( V_2 , V_64 ) ;
V_9 -> V_10 = F_25 ( V_2 ) ;
V_9 -> V_11 = F_25 ( V_2 ) ;
F_129 ( & V_9 -> V_276 ) ;
}
static struct V_8 * F_130 ( struct V_1 * V_2 , T_14 V_82 )
{
struct V_8 * V_9 ;
T_13 V_275 ;
V_9 = F_131 ( V_2 -> V_277 , V_82 , & V_275 ) ;
if ( V_9 != NULL ) {
F_128 ( V_2 , V_9 , V_275 ) ;
}
return V_9 ;
}
static inline void F_132 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
F_102 ( V_2 -> V_277 , V_9 , V_9 -> V_77 ) ;
}
static void F_133 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
if ( ! F_103 ( & V_15 -> V_276 ) || V_15 -> V_86 . V_99 ) {
F_4 ( V_2 , L_95 ) ;
F_134 () ;
}
if ( V_15 -> V_278 )
F_132 ( V_2 , V_15 -> V_278 ) ;
F_102 ( V_2 -> V_279 , V_15 -> V_17 , V_15 -> V_280 ) ;
F_40 ( V_15 ) ;
}
static struct V_14 * F_135 ( struct V_1 * V_2 , T_14 V_82 )
{
struct V_14 * V_15 ;
T_13 V_275 ;
V_15 = F_50 ( sizeof *V_15 , V_96 ) ;
if ( ! V_15 )
goto V_78;
V_15 -> V_17 = (struct V_16 * )
F_131 ( V_2 -> V_279 , V_82 , & V_275 ) ;
if ( ! V_15 -> V_17 )
goto V_281;
memset ( V_15 -> V_17 , 0 , sizeof * V_15 -> V_17 ) ;
V_15 -> V_280 = V_275 ;
F_129 ( & V_15 -> V_276 ) ;
V_15 -> V_278 = F_130 ( V_2 , V_82 ) ;
if ( V_15 -> V_278 == NULL ) {
F_4 ( V_2 , L_96 ) ;
goto V_282;
}
V_78:
return V_15 ;
V_282:
F_102 ( V_2 -> V_279 , V_15 -> V_17 , V_15 -> V_280 ) ;
V_281:
F_40 ( V_15 ) ;
return NULL ;
}
static void F_136 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 )
F_133 ( V_2 , V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
if ( V_2 -> V_278 )
F_133 ( V_2 , V_2 -> V_278 ) ;
V_2 -> V_278 = NULL ;
if ( V_2 -> V_277 )
F_137 ( V_2 -> V_277 ) ;
V_2 -> V_277 = NULL ;
if ( V_2 -> V_279 ) {
F_137 ( V_2 -> V_279 ) ;
V_2 -> V_279 = NULL ;
}
if ( V_2 -> V_202 )
F_137 ( V_2 -> V_202 ) ;
V_2 -> V_202 = NULL ;
if ( V_2 -> V_100 )
F_138 ( F_63 ( V_2 ) -> V_119 . V_120 ,
V_2 -> V_97 * sizeof ( T_1 ) ,
V_2 -> V_100 , V_2 -> V_283 ) ;
V_2 -> V_100 = NULL ;
F_40 ( V_2 -> V_98 ) ;
V_2 -> V_98 = NULL ;
}
static int F_139 ( struct V_1 * V_2 , T_14 V_82 )
{
int V_93 ;
V_2 -> V_277 = F_140 ( L_97 ,
F_63 ( V_2 ) -> V_119 . V_120 ,
sizeof ( struct V_8 ) ,
32 ,
4096 ) ;
if ( ! V_2 -> V_277 ) {
goto V_281;
}
V_2 -> V_279 = F_140 ( L_98 ,
F_63 ( V_2 ) -> V_119 . V_120 ,
sizeof( struct V_16 ) ,
32 ,
4096 ) ;
if ( ! V_2 -> V_279 ) {
goto V_281;
}
V_2 -> V_75 = F_135 ( V_2 , V_82 ) ;
if ( ! V_2 -> V_75 ) {
goto V_281;
}
V_2 -> V_202 = F_140 ( L_99 ,
F_63 ( V_2 ) -> V_119 . V_120 ,
sizeof ( struct V_22 ) ,
64 ,
4096 ) ;
if ( ! V_2 -> V_202 ) {
goto V_281;
}
V_2 -> V_100 = ( T_5 * )
F_141 ( F_63 ( V_2 ) -> V_119 . V_120 ,
V_2 -> V_97 * sizeof( T_5 ) ,
& V_2 -> V_283 , 0 ) ;
if ( V_2 -> V_100 == NULL ) {
goto V_281;
}
for ( V_93 = 0 ; V_93 < V_2 -> V_97 ; V_93 ++ )
V_2 -> V_100 [ V_93 ] = F_25 ( V_2 ) ;
V_2 -> V_98 = F_142 ( V_2 -> V_97 , sizeof( void * ) , V_82 ) ;
if ( V_2 -> V_98 != NULL )
return 0 ;
V_281:
F_4 ( V_2 , L_100 ) ;
F_136 ( V_2 ) ;
return - V_137 ;
}
static int
F_143 ( struct V_1 * V_2 , struct V_8 * V_9 , T_13 V_29 ,
T_8 V_30 , int V_61 , int V_284 )
{
int V_93 , V_139 ;
T_15 V_285 = V_29 ;
V_9 -> V_13 [ 0 ] = F_28 ( V_2 , ( T_1 ) V_285 ) ;
V_9 -> V_286 [ 0 ] = F_28 ( V_2 , ( T_1 ) ( V_285 >> 32 ) ) ;
V_139 = 0x1000 - ( V_29 & 0x0fff ) ;
if ( F_38 ( V_30 < V_139 ) )
V_139 = V_30 ;
else {
V_29 += 0x1000 ;
V_29 &= ~ 0x0fff ;
for ( V_93 = 1 ; V_139 < V_30 && V_93 < 5 ; V_93 ++ ) {
V_285 = V_29 ;
V_9 -> V_13 [ V_93 ] = F_28 ( V_2 , ( T_1 ) V_285 ) ;
V_9 -> V_286 [ V_93 ] = F_28 ( V_2 ,
( T_1 ) ( V_285 >> 32 ) ) ;
V_29 += 0x1000 ;
if ( ( V_139 + 0x1000 ) < V_30 )
V_139 += 0x1000 ;
else
V_139 = V_30 ;
}
if ( V_139 != V_30 )
V_139 -= ( V_139 % V_284 ) ;
}
V_9 -> V_12 = F_28 ( V_2 , ( V_139 << 16 ) | V_61 ) ;
V_9 -> V_287 = V_139 ;
return V_139 ;
}
static inline void
F_144 ( struct V_1 * V_2 , struct V_14 * V_15 , struct V_8 * V_9 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
F_145 ( V_15 -> V_288 != V_289 ) ;
V_17 -> V_21 = F_146 ( V_2 , V_9 -> V_77 ) ;
V_17 -> V_11 = F_25 ( V_2 ) ;
if ( ! ( V_17 -> V_18 & F_28 ( V_2 , V_290 ) ) ) {
unsigned V_291 , V_292 ;
V_291 = V_15 -> V_291 ;
V_292 = ( F_10 ( V_2 , & V_17 -> V_18 ) >> 8 ) & 0x0f ;
if ( F_147 ( ! F_148 ( V_15 -> V_293 , V_292 , V_291 ) ) ) {
V_17 -> V_12 &= ~ F_28 ( V_2 , V_76 ) ;
F_149 ( V_15 -> V_293 , V_292 , V_291 , 1 ) ;
}
}
V_17 -> V_12 &= F_28 ( V_2 , V_76 | V_294 ) ;
}
static void
F_150 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_8 * V_9 ;
if ( F_103 ( & V_15 -> V_276 ) )
V_9 = V_15 -> V_278 ;
else {
V_9 = F_98 ( V_15 -> V_276 . V_72 ,
struct V_8 , V_276 ) ;
if ( F_28 ( V_2 , V_9 -> V_77 ) == V_15 -> V_17 -> V_20 ) {
V_15 -> V_17 -> V_21 = V_9 -> V_10 ;
V_9 = NULL ;
}
}
if ( V_9 )
F_144 ( V_2 , V_15 , V_9 ) ;
}
static void F_151 ( struct V_80 * V_81 ,
struct V_295 * V_296 )
{
struct V_1 * V_2 = F_33 ( V_81 ) ;
struct V_14 * V_15 = V_296 -> V_297 ;
unsigned long V_82 ;
F_34 ( & V_2 -> V_85 , V_82 ) ;
V_15 -> V_298 = 0 ;
if ( V_15 -> V_288 == V_289 && ! F_103 ( & V_15 -> V_276 )
&& V_2 -> V_113 == V_116 )
F_152 ( V_2 , V_15 ) ;
F_35 ( & V_2 -> V_85 , V_82 ) ;
}
static void F_153 ( struct V_1 * V_2 , struct V_14 * V_15 ,
struct V_25 * V_25 , T_1 V_61 )
{
if ( V_25 -> V_293 -> V_299 && ! F_154 ( V_25 -> V_300 ) && ! V_15 -> V_298 ) {
#ifdef F_155
struct V_301 * V_299 = V_25 -> V_293 -> V_299 -> V_302 ;
F_156 ( & V_299 -> V_293 ,
L_101 ,
V_25 -> V_293 -> V_303 , V_25 -> V_293 -> V_304 ,
F_157 ( V_25 -> V_300 ) , V_61 ) ;
#endif
if ( V_25 -> V_293 -> V_299 -> V_302 !=
F_63 ( V_2 ) -> V_119 . V_305 ) {
if ( F_158 ( V_25 ) == 0 )
V_15 -> V_298 = 1 ;
}
}
}
static int F_159 (
struct V_1 * V_2 ,
struct V_25 * V_25 ,
T_8 V_287 ,
T_1 V_61
)
{
int V_31 = - V_306 ;
if ( F_38 ( F_160 ( V_61 ) != 2 ) )
V_25 -> V_307 += V_287 - F_30 ( V_61 ) ;
if ( F_147 ( V_25 -> V_308 ) )
return V_31 ;
if ( F_147 ( F_23 ( V_61 ) ) )
V_31 = - V_309 ;
if ( V_61 & V_64 ) {
if ( V_61 & V_310 ) {
V_31 = - V_311 ;
} else if ( F_161 ( V_61 ) ) {
V_31 = - V_273 ;
} else if ( V_61 & V_312 ) {
V_31 = - V_313 ;
} else if ( V_61 & V_314 ) {
V_31 = ( F_160 ( V_61 ) == 1 )
? - V_315
: - V_316 ;
} else if ( V_61 & V_317 ) {
F_4 ( V_2 , L_102 ,
V_25 -> V_293 -> V_318 ,
F_157 ( V_25 -> V_300 ) ,
F_162 ( V_25 -> V_300 ) ? L_53 : L_52 ) ;
V_31 = - V_313 ;
} else {
V_31 = - V_313 ;
}
F_1 ( V_2 ,
L_103 ,
F_163 ( V_25 -> V_300 ) ,
F_157 ( V_25 -> V_300 ) ,
F_162 ( V_25 -> V_300 ) ? L_53 : L_52 ,
V_61 , V_31 ) ;
}
return V_31 ;
}
static void
F_164 ( struct V_1 * V_2 , struct V_25 * V_25 , int V_31 )
__releases( V_2 -> V_85 )
__acquires( V_2 -> V_85 )
{
if ( F_38 ( V_25 -> V_297 != NULL ) ) {
struct V_14 * V_15 = (struct V_14 * ) V_25 -> V_297 ;
if ( ( V_15 -> V_17 -> V_19 & F_28 ( V_2 , V_104 ) ) != 0 ) {
F_63 ( V_2 ) -> V_119 . V_319 -- ;
}
}
if ( F_147 ( V_25 -> V_308 ) ) {
F_105 ( V_2 -> V_126 . V_131 ) ;
} else {
if ( V_31 == - V_306 || V_31 == - V_309 )
V_31 = 0 ;
F_105 ( V_2 -> V_126 . V_130 ) ;
}
#ifdef F_165
F_4 ( V_2 ,
L_104 ,
V_320 , V_25 -> V_293 -> V_318 , V_25 ,
F_157 ( V_25 -> V_300 ) ,
F_162 ( V_25 -> V_300 ) ? L_53 : L_52 ,
V_31 ,
V_25 -> V_307 , V_25 -> V_321 ) ;
#endif
F_166 ( F_63 ( V_2 ) , V_25 ) ;
F_167 ( & V_2 -> V_85 ) ;
F_168 ( F_63 ( V_2 ) , V_25 , V_31 ) ;
F_169 ( & V_2 -> V_85 ) ;
}
static unsigned
F_170 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_8 * V_322 , * V_323 = V_15 -> V_278 ;
struct V_324 * V_325 , * V_326 ;
int V_327 ;
int V_190 ;
unsigned V_139 = 0 ;
T_16 V_328 ;
struct V_16 * V_17 = V_15 -> V_17 ;
if ( F_147 ( F_103 ( & V_15 -> V_276 ) ) )
return V_139 ;
V_328 = V_15 -> V_288 ;
V_15 -> V_288 = V_329 ;
V_190 = ( V_328 == V_289 ) ;
V_330:
V_322 = NULL ;
V_327 = - V_306 ;
V_15 -> V_331 = 0 ;
F_171 (entry, tmp, &qh->qtd_list) {
struct V_8 * V_9 ;
struct V_25 * V_25 ;
T_1 V_61 = 0 ;
V_9 = F_98 ( V_325 , struct V_8 , V_276 ) ;
V_25 = V_9 -> V_25 ;
if ( V_322 ) {
if ( F_38 ( V_322 -> V_25 != V_25 ) ) {
F_164 ( V_2 , V_322 -> V_25 , V_327 ) ;
V_139 ++ ;
V_327 = - V_306 ;
}
F_132 ( V_2 , V_322 ) ;
V_322 = NULL ;
}
if ( V_9 == V_323 )
break;
F_172 () ;
V_61 = F_13 ( V_2 , V_9 -> V_12 ) ;
V_332:
if ( ( V_61 & V_63 ) == 0 ) {
if ( V_61 & V_314 )
F_4 ( V_2 ,
L_105 ,
V_25 ,
F_173 ( & V_25 -> V_296 -> V_223 ) ,
F_174 ( & V_25 -> V_296 -> V_223 ) ? L_53 : L_52 ,
V_25 -> V_321 ,
V_9 ,
V_15 ) ;
if ( ( V_61 & V_64 ) != 0 ) {
if ( ( V_61 & V_317 ) &&
F_161 ( V_61 ) == 0 &&
++ V_15 -> V_333 < V_334 &&
! V_25 -> V_308 ) {
F_4 ( V_2 ,
L_106 ,
V_9 -> V_287 - F_30 ( V_61 ) , V_9 -> V_287 , V_15 -> V_333 ) ;
V_61 &= ~ V_64 ;
V_61 |= V_63 |
( V_335 << 10 ) ;
V_9 -> V_12 = F_28 ( V_2 ,
V_61 ) ;
F_175 () ;
V_17 -> V_12 = F_28 ( V_2 ,
V_61 ) ;
goto V_332;
}
V_190 = 1 ;
} else if ( F_23 ( V_61 )
&& ! ( V_9 -> V_11
& F_25 ( V_2 ) ) ) {
V_190 = 1 ;
}
} else if ( F_38 ( ! V_190
&& V_2 -> V_113 >= V_116 ) ) {
break;
} else {
V_190 = 1 ;
if ( V_2 -> V_113 < V_116 )
V_327 = - V_336 ;
else if ( V_327 == - V_306 && ! V_25 -> V_308 )
continue;
if ( V_328 == V_289
&& F_28 ( V_2 , V_9 -> V_77 )
== V_17 -> V_20 ) {
V_61 = F_13 ( V_2 , V_17 -> V_12 ) ;
F_153 ( V_2 , V_15 , V_25 , V_61 ) ;
}
}
if ( V_327 == - V_306 ) {
V_327 = F_159 ( V_2 , V_25 ,
V_9 -> V_287 , V_61 ) ;
if ( V_327 == - V_309
&& ( V_9 -> V_11
& F_25 ( V_2 ) ) )
V_327 = - V_306 ;
if ( F_147 ( V_327 != - V_306 &&
V_327 != - V_309 ) ) {
if ( V_327 != - V_273 )
F_153 ( V_2 , V_15 , V_25 ,
V_61 ) ;
}
}
if ( V_190 && V_9 -> V_276 . V_199 != & V_15 -> V_276 ) {
V_322 = F_98 ( V_9 -> V_276 . V_199 ,
struct V_8 , V_276 ) ;
V_322 -> V_10 = V_9 -> V_10 ;
}
F_101 ( & V_9 -> V_276 ) ;
V_322 = V_9 ;
V_15 -> V_333 = 0 ;
}
if ( F_38 ( V_322 != NULL ) ) {
F_164 ( V_2 , V_322 -> V_25 , V_327 ) ;
V_139 ++ ;
F_132 ( V_2 , V_322 ) ;
}
if ( F_147 ( V_15 -> V_331 ) ) {
if ( V_328 == V_289 )
goto V_330;
if ( V_328 != V_337 )
V_15 -> V_331 = 0 ;
}
V_15 -> V_288 = V_328 ;
if ( V_190 != 0 || V_17 -> V_21 == F_25 ( V_2 ) ) {
switch ( V_328 ) {
case V_289 :
F_150 ( V_2 , V_15 ) ;
break;
case V_337 :
V_15 -> V_331 = 1 ;
break;
}
}
return V_139 ;
}
static void F_176 (
struct V_1 * V_2 ,
struct V_25 * V_25 ,
struct V_324 * V_276
) {
struct V_324 * V_325 , * V_70 ;
F_171 (entry, temp, qtd_list) {
struct V_8 * V_9 ;
V_9 = F_98 ( V_325 , struct V_8 , V_276 ) ;
F_101 ( & V_9 -> V_276 ) ;
F_132 ( V_2 , V_9 ) ;
}
}
static struct V_324 *
F_177 (
struct V_1 * V_2 ,
struct V_25 * V_25 ,
struct V_324 * V_338 ,
T_14 V_82
) {
struct V_8 * V_9 , * V_339 ;
T_13 V_29 ;
int V_30 , V_340 , V_284 ;
int V_341 ;
T_1 V_61 ;
int V_93 ;
struct V_342 * V_343 ;
V_9 = F_130 ( V_2 , V_82 ) ;
if ( F_147 ( ! V_9 ) )
return NULL ;
F_178 ( & V_9 -> V_276 , V_338 ) ;
V_9 -> V_25 = V_25 ;
V_61 = V_63 ;
V_61 |= ( V_335 << 10 ) ;
V_30 = V_25 -> V_321 ;
V_341 = F_162 ( V_25 -> V_300 ) ;
if ( F_179 ( V_25 -> V_300 ) ) {
F_143 ( V_2 , V_9 , V_25 -> V_344 ,
sizeof ( struct V_345 ) ,
V_61 | ( 2 << 8 ) , 8 ) ;
V_61 ^= V_76 ;
V_339 = V_9 ;
V_9 = F_130 ( V_2 , V_82 ) ;
if ( F_147 ( ! V_9 ) )
goto V_346;
V_9 -> V_25 = V_25 ;
V_339 -> V_10 = F_146 ( V_2 , V_9 -> V_77 ) ;
F_178 ( & V_9 -> V_276 , V_338 ) ;
if ( V_30 == 0 )
V_61 |= ( 1 << 8 ) ;
}
V_93 = V_25 -> V_347 ;
if ( V_30 > 0 && V_93 > 0 ) {
V_343 = V_25 -> V_343 ;
V_29 = F_180 ( V_343 ) ;
V_340 = F_181 ( int , F_182 ( V_343 ) , V_30 ) ;
} else {
V_343 = NULL ;
V_29 = V_25 -> V_348 ;
V_340 = V_30 ;
}
if ( V_341 )
V_61 |= ( 1 << 8 ) ;
V_284 = F_183 ( F_184 ( V_25 -> V_293 , V_25 -> V_300 , ! V_341 ) ) ;
for (; ; ) {
int V_349 ;
V_349 = F_143 ( V_2 , V_9 , V_29 , V_340 , V_61 ,
V_284 ) ;
V_340 -= V_349 ;
V_30 -= V_349 ;
V_29 += V_349 ;
if ( V_341 )
V_9 -> V_11 = V_2 -> V_75 -> V_17 -> V_11 ;
if ( ( V_284 & ( V_349 + ( V_284 - 1 ) ) ) == 0 )
V_61 ^= V_76 ;
if ( F_38 ( V_340 <= 0 ) ) {
if ( -- V_93 <= 0 || V_30 <= 0 )
break;
V_343 = F_185 ( V_343 ) ;
V_29 = F_180 ( V_343 ) ;
V_340 = F_181 ( int , F_182 ( V_343 ) , V_30 ) ;
}
V_339 = V_9 ;
V_9 = F_130 ( V_2 , V_82 ) ;
if ( F_147 ( ! V_9 ) )
goto V_346;
V_9 -> V_25 = V_25 ;
V_339 -> V_10 = F_146 ( V_2 , V_9 -> V_77 ) ;
F_178 ( & V_9 -> V_276 , V_338 ) ;
}
if ( F_38 ( ( V_25 -> V_350 & V_351 ) == 0
|| F_179 ( V_25 -> V_300 ) ) )
V_9 -> V_11 = F_25 ( V_2 ) ;
if ( F_38 ( V_25 -> V_321 != 0 ) ) {
int V_352 = 0 ;
if ( F_179 ( V_25 -> V_300 ) ) {
V_352 = 1 ;
V_61 ^= 0x0100 ;
V_61 |= V_76 ;
} else if ( F_186 ( V_25 -> V_300 )
&& ( V_25 -> V_350 & V_353 )
&& ! ( V_25 -> V_321 % V_284 ) ) {
V_352 = 1 ;
}
if ( V_352 ) {
V_339 = V_9 ;
V_9 = F_130 ( V_2 , V_82 ) ;
if ( F_147 ( ! V_9 ) )
goto V_346;
V_9 -> V_25 = V_25 ;
V_339 -> V_10 = F_146 ( V_2 , V_9 -> V_77 ) ;
F_178 ( & V_9 -> V_276 , V_338 ) ;
F_143 ( V_2 , V_9 , 0 , 0 , V_61 , 0 ) ;
}
}
if ( F_38 ( ! ( V_25 -> V_350 & V_354 ) ) )
V_9 -> V_12 |= F_28 ( V_2 , V_355 ) ;
return V_338 ;
V_346:
F_176 ( V_2 , V_25 , V_338 ) ;
return NULL ;
}
static struct V_14 *
F_187 (
struct V_1 * V_2 ,
struct V_25 * V_25 ,
T_14 V_82
) {
struct V_14 * V_15 = F_135 ( V_2 , V_82 ) ;
T_1 V_356 = 0 , V_357 = 0 ;
int V_341 , type ;
int V_358 = 0 ;
struct V_359 * V_299 = V_25 -> V_293 -> V_299 ;
struct V_16 * V_17 ;
if ( ! V_15 )
return V_15 ;
V_356 |= F_157 ( V_25 -> V_300 ) << 8 ;
V_356 |= F_163 ( V_25 -> V_300 ) << 0 ;
V_341 = F_162 ( V_25 -> V_300 ) ;
type = F_188 ( V_25 -> V_300 ) ;
V_358 = F_184 ( V_25 -> V_293 , V_25 -> V_300 , ! V_341 ) ;
if ( F_183 ( V_358 ) > 1024 ) {
F_4 ( V_2 , L_107 , F_183 ( V_358 ) ) ;
goto V_78;
}
if ( type == V_360 ) {
V_15 -> V_105 = F_189 ( F_190 ( V_361 ,
V_341 , 0 ,
F_191 ( V_358 ) * F_183 ( V_358 ) ) ) ;
V_15 -> V_362 = V_363 ;
if ( V_25 -> V_293 -> V_364 == V_361 ) {
V_15 -> V_106 = 0 ;
V_15 -> V_365 = 0 ;
V_15 -> V_102 = V_25 -> V_366 >> 3 ;
if ( V_15 -> V_102 == 0 && V_25 -> V_366 != 1 ) {
V_25 -> V_366 = 1 ;
} else if ( V_15 -> V_102 > V_2 -> V_97 ) {
V_15 -> V_102 = V_2 -> V_97 ;
V_25 -> V_366 = V_15 -> V_102 << 3 ;
}
} else {
int V_367 ;
V_15 -> V_365 = 1 + F_190 ( V_25 -> V_293 -> V_364 ,
V_341 , 0 , V_358 ) / ( 125 * 1000 ) ;
if ( V_341 ) {
V_15 -> V_106 = V_15 -> V_105 + F_192 ( 0 ) ;
V_15 -> V_105 = F_192 ( 1 ) ;
} else {
V_15 -> V_105 += F_192 ( 1 ) ;
V_15 -> V_106 = F_192 ( 0 ) ;
}
V_367 = V_299 ? V_299 -> V_367 : 0 ;
V_15 -> V_368 = F_189 ( V_367 +
F_190 ( V_25 -> V_293 -> V_364 ,
V_341 , 0 , F_183 ( V_358 ) ) ) ;
V_15 -> V_102 = V_25 -> V_366 ;
if ( V_15 -> V_102 > V_2 -> V_97 ) {
V_15 -> V_102 = V_2 -> V_97 ;
V_25 -> V_366 = V_15 -> V_102 ;
}
}
}
V_15 -> V_293 = V_25 -> V_293 ;
switch ( V_25 -> V_293 -> V_364 ) {
case V_369 :
V_356 |= V_370 ;
case V_371 :
if ( type != V_360 )
V_356 |= ( V_372 << 28 ) ;
if ( type == V_373 ) {
V_356 |= V_374 ;
V_356 |= V_290 ;
}
V_356 |= V_358 << 16 ;
V_357 |= ( V_375 << 30 ) ;
if ( F_193 ( V_2 ) )
V_357 |= ( V_25 -> V_293 -> V_303 - 1 ) << 23 ;
else
V_357 |= V_25 -> V_293 -> V_303 << 23 ;
if ( V_299 && V_299 -> V_302 != F_63 ( V_2 ) -> V_119 . V_305 )
V_357 |= V_299 -> V_302 -> V_304 << 16 ;
break;
case V_361 :
V_356 |= V_376 ;
if ( type == V_373 ) {
V_356 |= ( V_377 << 28 ) ;
V_356 |= 64 << 16 ;
V_356 |= V_290 ;
V_357 |= ( V_378 << 30 ) ;
} else if ( type == V_379 ) {
V_356 |= ( V_377 << 28 ) ;
V_356 |= F_183 ( V_358 ) << 16 ;
V_357 |= ( V_378 << 30 ) ;
} else {
V_356 |= F_183 ( V_358 ) << 16 ;
V_357 |= F_191 ( V_358 ) << 30 ;
}
break;
default:
F_4 ( V_2 , L_108 , V_25 -> V_293 ,
V_25 -> V_293 -> V_364 ) ;
V_78:
F_133 ( V_2 , V_15 ) ;
return NULL ;
}
V_15 -> V_288 = V_289 ;
V_17 = V_15 -> V_17 ;
V_17 -> V_18 = F_28 ( V_2 , V_356 ) ;
V_17 -> V_19 = F_28 ( V_2 , V_357 ) ;
V_15 -> V_291 = ! V_341 ;
F_149 ( V_25 -> V_293 , F_157 ( V_25 -> V_300 ) , ! V_341 , 1 ) ;
F_150 ( V_2 , V_15 ) ;
return V_15 ;
}
static void F_194 ( struct V_1 * V_2 )
{
if ( V_2 -> V_182 ++ )
return;
V_2 -> V_173 &= ~ F_97 ( V_183 ) ;
F_86 ( V_2 ) ;
F_106 ( V_2 ) ;
}
static void F_195 ( struct V_1 * V_2 )
{
if ( -- V_2 -> V_182 )
return;
F_196 ( V_2 -> V_75 -> V_86 . V_15 || V_2 -> V_87 ) ;
F_86 ( V_2 ) ;
}
static void F_152 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
T_3 V_275 = F_197 ( V_2 , V_15 -> V_280 ) ;
struct V_14 * V_338 ;
if ( F_147 ( V_15 -> V_298 ) )
return;
F_196 ( V_15 -> V_288 != V_289 ) ;
F_150 ( V_2 , V_15 ) ;
V_338 = V_2 -> V_75 ;
V_15 -> V_86 = V_338 -> V_86 ;
V_15 -> V_17 -> V_10 = V_338 -> V_17 -> V_10 ;
F_175 () ;
V_338 -> V_86 . V_15 = V_15 ;
V_338 -> V_17 -> V_10 = V_275 ;
V_15 -> V_333 = 0 ;
V_15 -> V_288 = V_337 ;
F_194 ( V_2 ) ;
}
static struct V_14 * F_198 (
struct V_1 * V_2 ,
struct V_25 * V_25 ,
struct V_324 * V_276 ,
int V_292 ,
void * * V_99
)
{
struct V_14 * V_15 = NULL ;
T_3 V_380 = F_28 ( V_2 , 0x7f ) ;
V_15 = (struct V_14 * ) * V_99 ;
if ( F_147 ( V_15 == NULL ) ) {
V_15 = F_187 ( V_2 , V_25 , V_96 ) ;
* V_99 = V_15 ;
}
if ( F_38 ( V_15 != NULL ) ) {
struct V_8 * V_9 ;
if ( F_147 ( F_103 ( V_276 ) ) )
V_9 = NULL ;
else
V_9 = F_98 ( V_276 -> V_72 , struct V_8 ,
V_276 ) ;
if ( F_147 ( V_292 == 0 ) ) {
if ( F_163 ( V_25 -> V_300 ) == 0 )
V_15 -> V_17 -> V_18 &= ~ V_380 ;
}
if ( F_38 ( V_9 != NULL ) ) {
struct V_8 * V_278 ;
T_13 V_275 ;
T_3 V_61 ;
V_61 = V_9 -> V_12 ;
V_9 -> V_12 = F_199 ( V_2 ) ;
V_278 = V_15 -> V_278 ;
V_275 = V_278 -> V_77 ;
* V_278 = * V_9 ;
V_278 -> V_77 = V_275 ;
F_101 ( & V_9 -> V_276 ) ;
F_200 ( & V_278 -> V_276 , V_276 ) ;
F_201 ( V_276 , & V_15 -> V_276 ) ;
F_128 ( V_2 , V_9 , V_9 -> V_77 ) ;
V_15 -> V_278 = V_9 ;
V_275 = V_9 -> V_77 ;
V_9 = F_98 ( V_15 -> V_276 . V_199 ,
struct V_8 , V_276 ) ;
V_9 -> V_10 = F_146 ( V_2 , V_275 ) ;
F_175 () ;
V_278 -> V_12 = V_61 ;
V_25 -> V_297 = V_15 ;
}
}
return V_15 ;
}
static int
F_202 (
struct V_1 * V_2 ,
struct V_25 * V_25 ,
struct V_324 * V_276 ,
T_14 V_381
) {
int V_292 ;
unsigned long V_82 ;
struct V_14 * V_15 = NULL ;
int V_382 ;
V_292 = V_25 -> V_296 -> V_223 . V_383 ;
#ifdef F_165
{
struct V_8 * V_9 ;
V_9 = F_98 ( V_276 -> V_72 , struct V_8 , V_276 ) ;
F_4 ( V_2 ,
L_109 ,
V_320 , V_25 -> V_293 -> V_318 , V_25 ,
V_292 & 0x0f , ( V_292 & V_384 ) ? L_53 : L_52 ,
V_25 -> V_321 ,
V_9 , V_25 -> V_296 -> V_297 ) ;
}
#endif
F_34 ( & V_2 -> V_85 , V_82 ) ;
if ( F_147 ( ! F_43 ( F_63 ( V_2 ) ) ) ) {
V_382 = - V_336 ;
goto V_78;
}
V_382 = F_203 ( F_63 ( V_2 ) , V_25 ) ;
if ( F_147 ( V_382 ) )
goto V_78;
V_15 = F_198 ( V_2 , V_25 , V_276 , V_292 , & V_25 -> V_296 -> V_297 ) ;
if ( F_147 ( V_15 == NULL ) ) {
F_166 ( F_63 ( V_2 ) , V_25 ) ;
V_382 = - V_137 ;
goto V_78;
}
if ( F_38 ( V_15 -> V_288 == V_289 ) )
F_152 ( V_2 , V_15 ) ;
V_78:
F_35 ( & V_2 -> V_85 , V_82 ) ;
if ( F_147 ( V_15 == NULL ) )
F_176 ( V_2 , V_25 , V_276 ) ;
return V_382 ;
}
static void F_204 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_14 * V_199 ;
V_15 -> V_288 = V_385 ;
if ( V_2 -> V_87 )
V_2 -> V_386 -> V_88 = V_15 ;
else
V_2 -> V_87 = V_15 ;
V_2 -> V_386 = V_15 ;
V_199 = V_2 -> V_75 ;
while ( V_199 -> V_86 . V_15 != V_15 )
V_199 = V_199 -> V_86 . V_15 ;
V_199 -> V_17 -> V_10 = V_15 -> V_17 -> V_10 ;
V_199 -> V_86 = V_15 -> V_86 ;
if ( V_2 -> V_387 == V_15 )
V_2 -> V_387 = V_15 -> V_86 . V_15 ;
}
static void F_205 ( struct V_1 * V_2 , bool V_388 )
{
if ( V_2 -> V_204 || V_2 -> V_389 )
return;
V_2 -> V_204 = V_2 -> V_87 ;
V_2 -> V_87 = NULL ;
if ( F_147 ( V_2 -> V_113 < V_116 ) ) {
if ( ! V_388 )
F_93 ( V_2 ) ;
} else if ( F_38 ( V_2 -> V_113 == V_116 ) ) {
F_175 () ;
F_71 ( V_2 , V_2 -> V_43 | V_45 ,
& V_2 -> V_124 -> V_43 ) ;
F_3 ( V_2 , & V_2 -> V_124 -> V_43 ) ;
F_81 ( V_2 , V_390 , true ) ;
}
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
V_391:
V_2 -> V_389 = true ;
while ( V_2 -> V_204 ) {
V_15 = V_2 -> V_204 ;
V_2 -> V_204 = V_15 -> V_88 ;
V_15 -> V_88 = NULL ;
V_15 -> V_288 = V_289 ;
V_15 -> V_86 . V_15 = NULL ;
F_170 ( V_2 , V_15 ) ;
if ( ! F_103 ( & V_15 -> V_276 ) &&
V_2 -> V_113 == V_116 )
F_152 ( V_2 , V_15 ) ;
F_195 ( V_2 ) ;
}
V_2 -> V_389 = false ;
if ( V_2 -> V_87 ) {
F_205 ( V_2 , true ) ;
if ( F_147 ( V_2 -> V_113 < V_116 ) )
goto V_391;
}
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_14 * V_15 , * V_72 ;
bool V_190 = ( V_2 -> V_113 < V_116 ) ;
bool V_392 = false ;
V_72 = V_2 -> V_75 -> V_86 . V_15 ;
while ( V_72 ) {
V_15 = V_72 ;
V_72 = V_15 -> V_86 . V_15 ;
if ( F_103 ( & V_15 -> V_276 ) &&
V_15 -> V_288 == V_337 ) {
if ( ! V_190 && V_15 -> V_193 ==
V_2 -> V_393 )
V_392 = true ;
else
F_204 ( V_2 , V_15 ) ;
}
}
if ( V_2 -> V_87 )
F_205 ( V_2 , false ) ;
if ( V_392 ) {
F_81 ( V_2 , V_394 , true ) ;
++ V_2 -> V_393 ;
}
}
static void F_207 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
if ( V_15 -> V_288 != V_337 ) {
if ( V_15 -> V_288 == V_329 )
V_15 -> V_331 = 1 ;
return;
}
F_204 ( V_2 , V_15 ) ;
F_205 ( V_2 , false ) ;
}
static void F_208 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
bool V_392 = false ;
V_2 -> V_387 = V_2 -> V_75 -> V_86 . V_15 ;
while ( V_2 -> V_387 ) {
V_15 = V_2 -> V_387 ;
V_2 -> V_387 = V_15 -> V_86 . V_15 ;
V_330:
if ( ! F_103 ( & V_15 -> V_276 ) ) {
int V_70 ;
V_70 = F_170 ( V_2 , V_15 ) ;
if ( V_15 -> V_331 ) {
F_207 ( V_2 , V_15 ) ;
} else if ( F_103 ( & V_15 -> V_276 )
&& V_15 -> V_288 == V_337 ) {
V_15 -> V_193 = V_2 -> V_393 ;
V_392 = true ;
} else if ( V_70 != 0 )
goto V_330;
}
}
if ( V_392 && V_2 -> V_113 == V_116 &&
! ( V_2 -> V_173 &
F_97 ( V_394 ) ) ) {
F_81 ( V_2 , V_394 , true ) ;
++ V_2 -> V_393 ;
}
}
static union V_89 *
F_209 ( struct V_1 * V_2 , union V_89 * V_100 ,
T_3 V_94 )
{
switch ( F_13 ( V_2 , V_94 ) ) {
case V_101 :
return & V_100 -> V_15 -> V_86 ;
case V_107 :
return & V_100 -> V_108 -> V_110 ;
default:
return & V_100 -> V_23 -> V_112 ;
}
}
static T_3 *
F_210 ( struct V_1 * V_2 , union V_89 * V_100 ,
T_3 V_94 )
{
switch ( F_13 ( V_2 , V_94 ) ) {
case V_101 :
return & V_100 -> V_15 -> V_17 -> V_10 ;
default:
return V_100 -> V_10 ;
}
}
static void F_211 ( struct V_1 * V_2 , unsigned V_24 , void * V_99 )
{
union V_89 * V_395 = & V_2 -> V_98 [ V_24 ] ;
T_3 * V_396 = & V_2 -> V_100 [ V_24 ] ;
union V_89 V_397 = * V_395 ;
while ( V_397 . V_99 && V_397 . V_99 != V_99 ) {
V_395 = F_209 ( V_2 , V_395 ,
F_39 ( V_2 , * V_396 ) ) ;
V_396 = F_210 ( V_2 , & V_397 ,
F_39 ( V_2 , * V_396 ) ) ;
V_397 = * V_395 ;
}
if ( ! V_397 . V_99 )
return;
* V_395 = * F_209 ( V_2 , & V_397 ,
F_39 ( V_2 , * V_396 ) ) ;
* V_396 = * F_210 ( V_2 , & V_397 ,
F_39 ( V_2 , * V_396 ) ) ;
}
static unsigned short
F_212 ( struct V_1 * V_2 , unsigned V_24 , unsigned V_398 )
{
T_3 * V_396 = & V_2 -> V_100 [ V_24 ] ;
union V_89 * V_399 = & V_2 -> V_98 [ V_24 ] ;
unsigned V_105 = 0 ;
struct V_16 * V_17 ;
while ( V_399 -> V_99 ) {
switch ( F_13 ( V_2 , F_39 ( V_2 , * V_396 ) ) ) {
case V_101 :
V_17 = V_399 -> V_15 -> V_17 ;
if ( V_17 -> V_19 & F_28 ( V_2 , 1 << V_398 ) )
V_105 += V_399 -> V_15 -> V_105 ;
if ( V_17 -> V_19 & F_28 ( V_2 ,
1 << ( 8 + V_398 ) ) )
V_105 += V_399 -> V_15 -> V_106 ;
V_396 = & V_17 -> V_10 ;
V_399 = & V_399 -> V_15 -> V_86 ;
break;
default:
if ( V_399 -> V_108 -> V_109 != F_25 ( V_2 ) ) {
F_4 ( V_2 , L_110 ) ;
}
V_396 = & V_399 -> V_108 -> V_10 ;
V_399 = & V_399 -> V_108 -> V_110 ;
break;
case V_111 :
if ( V_399 -> V_23 -> V_26 [ V_398 ] )
V_105 += V_399 -> V_23 -> V_400 -> V_105 ;
V_396 = & V_399 -> V_23 -> V_10 ;
V_399 = & V_399 -> V_23 -> V_112 ;
break;
}
}
#ifdef F_155
if ( V_105 > V_2 -> V_401 )
F_121 ( V_2 , L_111 ,
V_24 * 8 + V_398 , V_105 ) ;
#endif
return V_105 ;
}
static int F_213 ( struct V_301 * V_402 , struct V_301 * V_403 )
{
if ( ! V_402 -> V_299 || ! V_403 -> V_299 )
return 0 ;
if ( V_402 -> V_299 != V_403 -> V_299 )
return 0 ;
if ( V_402 -> V_299 -> V_404 )
return V_402 -> V_303 == V_403 -> V_303 ;
else
return 1 ;
}
static int F_214 (
struct V_1 * V_2 ,
unsigned V_102 ,
struct V_301 * V_293 ,
unsigned V_24 ,
T_1 V_405
)
{
if ( V_102 == 0 )
return 0 ;
for (; V_24 < V_2 -> V_97 ; V_24 += V_102 ) {
union V_89 V_397 ;
T_3 type ;
struct V_16 * V_17 ;
V_397 = V_2 -> V_98 [ V_24 ] ;
type = F_39 ( V_2 , V_2 -> V_100 [ V_24 ] ) ;
while ( V_397 . V_99 ) {
switch ( F_13 ( V_2 , type ) ) {
case V_111 :
type = F_39 ( V_2 , V_397 . V_23 -> V_10 ) ;
V_397 = V_397 . V_23 -> V_112 ;
continue;
case V_101 :
V_17 = V_397 . V_15 -> V_17 ;
if ( F_213 ( V_293 , V_397 . V_15 -> V_293 ) ) {
T_1 V_154 ;
V_154 = F_13 ( V_2 ,
V_17 -> V_19 ) ;
V_154 |= V_154 >> 8 ;
if ( V_154 & V_405 )
break;
}
type = F_39 ( V_2 , V_17 -> V_10 ) ;
V_397 = V_397 . V_15 -> V_86 ;
continue;
default:
F_4 ( V_2 ,
L_112 ,
V_24 , type ) ;
}
return 0 ;
}
}
return 1 ;
}
static void F_215 ( struct V_1 * V_2 )
{
if ( V_2 -> V_186 ++ )
return;
V_2 -> V_173 &= ~ F_97 ( V_187 ) ;
F_88 ( V_2 ) ;
F_106 ( V_2 ) ;
}
static void F_216 ( struct V_1 * V_2 )
{
if ( -- V_2 -> V_186 )
return;
F_88 ( V_2 ) ;
}
static void F_217 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
unsigned V_93 ;
unsigned V_102 = V_15 -> V_102 ;
F_156 ( & V_15 -> V_293 -> V_293 ,
L_113 ,
V_102 , F_10 ( V_2 , & V_15 -> V_17 -> V_19 )
& ( V_103 | V_104 ) ,
V_15 , V_15 -> V_362 , V_15 -> V_105 , V_15 -> V_106 ) ;
if ( V_102 == 0 )
V_102 = 1 ;
for ( V_93 = V_15 -> V_362 ; V_93 < V_2 -> V_97 ; V_93 += V_102 ) {
union V_89 * V_199 = & V_2 -> V_98 [ V_93 ] ;
T_3 * V_396 = & V_2 -> V_100 [ V_93 ] ;
union V_89 V_397 = * V_199 ;
T_3 type = 0 ;
while ( V_397 . V_99 ) {
type = F_39 ( V_2 , * V_396 ) ;
if ( type == F_28 ( V_2 , V_101 ) )
break;
V_199 = F_209 ( V_2 , V_199 , type ) ;
V_396 = F_210 ( V_2 , & V_397 , type ) ;
V_397 = * V_199 ;
}
while ( V_397 . V_99 && V_15 != V_397 . V_15 ) {
if ( V_15 -> V_102 > V_397 . V_15 -> V_102 )
break;
V_199 = & V_397 . V_15 -> V_86 ;
V_396 = & V_397 . V_15 -> V_17 -> V_10 ;
V_397 = * V_199 ;
}
if ( V_15 != V_397 . V_15 ) {
V_15 -> V_86 = V_397 ;
if ( V_397 . V_15 )
V_15 -> V_17 -> V_10 = * V_396 ;
F_175 () ;
V_199 -> V_15 = V_15 ;
* V_396 = F_197 ( V_2 , V_15 -> V_280 ) ;
}
}
V_15 -> V_288 = V_337 ;
V_15 -> V_333 = 0 ;
F_63 ( V_2 ) -> V_119 . V_406 += V_15 -> V_102
? ( ( V_15 -> V_105 + V_15 -> V_106 ) / V_15 -> V_102 )
: ( V_15 -> V_105 * 8 ) ;
F_200 ( & V_15 -> V_407 , & V_2 -> V_408 ) ;
++ V_2 -> V_209 ;
F_215 ( V_2 ) ;
}
static void F_218 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
unsigned V_93 ;
unsigned V_102 ;
if ( ( V_102 = V_15 -> V_102 ) == 0 )
V_102 = 1 ;
for ( V_93 = V_15 -> V_362 ; V_93 < V_2 -> V_97 ; V_93 += V_102 )
F_211 ( V_2 , V_93 , V_15 ) ;
F_63 ( V_2 ) -> V_119 . V_406 -= V_15 -> V_102
? ( ( V_15 -> V_105 + V_15 -> V_106 ) / V_15 -> V_102 )
: ( V_15 -> V_105 * 8 ) ;
F_156 ( & V_15 -> V_293 -> V_293 ,
L_114 ,
V_15 -> V_102 ,
F_10 ( V_2 , & V_15 -> V_17 -> V_19 ) & ( V_103 | V_104 ) ,
V_15 , V_15 -> V_362 , V_15 -> V_105 , V_15 -> V_106 ) ;
V_15 -> V_288 = V_385 ;
V_15 -> V_86 . V_99 = NULL ;
if ( V_2 -> V_387 == V_15 )
V_2 -> V_387 = F_98 ( V_15 -> V_407 . V_72 ,
struct V_14 , V_407 ) ;
F_101 ( & V_15 -> V_407 ) ;
}
static void F_219 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
if ( V_15 -> V_288 != V_337 ) {
if ( V_15 -> V_288 == V_329 )
V_15 -> V_331 = 1 ;
return;
}
F_218 ( V_2 , V_15 ) ;
F_175 () ;
V_15 -> V_193 = V_2 -> V_194 ;
if ( V_2 -> V_192 )
V_2 -> V_409 -> V_88 = V_15 ;
else
V_2 -> V_192 = V_15 ;
V_2 -> V_409 = V_15 ;
if ( V_2 -> V_191 )
;
else if ( V_2 -> V_113 < V_116 )
F_94 ( V_2 ) ;
else if ( V_2 -> V_192 == V_15 ) {
F_81 ( V_2 , V_195 , true ) ;
++ V_2 -> V_194 ;
}
}
static void F_95 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
int V_382 ;
V_15 -> V_288 = V_289 ;
V_17 -> V_10 = F_25 ( V_2 ) ;
F_170 ( V_2 , V_15 ) ;
if ( ! F_103 ( & V_15 -> V_276 ) && V_2 -> V_113 == V_116 ) {
V_382 = F_220 ( V_2 , V_15 ) ;
if ( V_382 != 0 )
F_121 ( V_2 , L_115 ,
V_15 , V_382 ) ;
}
-- V_2 -> V_209 ;
F_216 ( V_2 ) ;
}
static int F_221 (
struct V_1 * V_2 ,
unsigned V_24 ,
unsigned V_398 ,
unsigned V_102 ,
unsigned V_105
) {
int V_410 ;
if ( V_398 >= 8 )
return 0 ;
V_105 = V_2 -> V_401 - V_105 ;
if ( F_147 ( V_102 == 0 ) ) {
do {
for ( V_398 = 0 ; V_398 < 7 ; V_398 ++ ) {
V_410 = F_212 ( V_2 , V_24 , V_398 ) ;
if ( V_410 > V_105 )
return 0 ;
}
} while ( ( V_24 += 1 ) < V_2 -> V_97 );
} else {
do {
V_410 = F_212 ( V_2 , V_24 , V_398 ) ;
if ( V_410 > V_105 )
return 0 ;
} while ( ( V_24 += V_102 ) < V_2 -> V_97 );
}
return 1 ;
}
static int F_222 (
struct V_1 * V_2 ,
unsigned V_24 ,
unsigned V_398 ,
const struct V_14 * V_15 ,
T_3 * V_411
)
{
int V_160 = - V_412 ;
T_16 V_154 = 0 ;
if ( V_15 -> V_106 && V_398 >= 6 )
goto V_78;
if ( ! F_221 ( V_2 , V_24 , V_398 , V_15 -> V_102 , V_15 -> V_105 ) )
goto V_78;
if ( ! V_15 -> V_106 ) {
V_160 = 0 ;
* V_411 = 0 ;
goto V_78;
}
V_154 = 0x03 << ( V_398 + V_15 -> V_365 ) ;
* V_411 = F_28 ( V_2 , V_154 << 8 ) ;
V_154 |= 1 << V_398 ;
if ( F_214 ( V_2 , V_15 -> V_102 , V_15 -> V_293 , V_24 , V_154 ) ) {
if ( ! F_221 ( V_2 , V_24 , V_398 + V_15 -> V_365 + 1 ,
V_15 -> V_102 , V_15 -> V_106 ) )
goto V_78;
if ( ! F_221 ( V_2 , V_24 , V_398 + V_15 -> V_365 ,
V_15 -> V_102 , V_15 -> V_106 ) )
goto V_78;
V_160 = 0 ;
}
V_78:
return V_160 ;
}
static int F_220 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
int V_31 ;
unsigned V_398 ;
T_3 V_413 ;
unsigned V_24 ;
struct V_16 * V_17 = V_15 -> V_17 ;
F_150 ( V_2 , V_15 ) ;
V_17 -> V_10 = F_25 ( V_2 ) ;
V_24 = V_15 -> V_362 ;
if ( V_24 < V_15 -> V_102 ) {
V_398 = F_223 ( F_10 ( V_2 , & V_17 -> V_19 ) & V_104 ) ;
V_31 = F_222 ( V_2 , V_24 , -- V_398 ,
V_15 , & V_413 ) ;
} else {
V_398 = 0 ;
V_413 = 0 ;
V_31 = - V_412 ;
}
if ( V_31 ) {
if ( V_15 -> V_102 ) {
int V_93 ;
for ( V_93 = V_15 -> V_102 ; V_31 && V_93 > 0 ; -- V_93 ) {
V_24 = ++ V_2 -> V_414 % V_15 -> V_102 ;
for ( V_398 = 0 ; V_398 < 8 ; V_398 ++ ) {
V_31 = F_222 ( V_2 ,
V_24 , V_398 , V_15 ,
& V_413 ) ;
if ( V_31 == 0 )
break;
}
}
} else {
V_24 = 0 ;
V_31 = F_222 ( V_2 , 0 , 0 , V_15 , & V_413 ) ;
}
if ( V_31 )
goto V_78;
V_15 -> V_362 = V_24 ;
V_17 -> V_19 &= F_28 ( V_2 , ~ ( V_103 | V_104 ) ) ;
V_17 -> V_19 |= V_15 -> V_102
? F_28 ( V_2 , 1 << V_398 )
: F_28 ( V_2 , V_104 ) ;
V_17 -> V_19 |= V_413 ;
} else
F_4 ( V_2 , L_116 , V_15 ) ;
F_217 ( V_2 , V_15 ) ;
V_78:
return V_31 ;
}
static int F_224 (
struct V_1 * V_2 ,
struct V_25 * V_25 ,
struct V_324 * V_276 ,
T_14 V_381
) {
unsigned V_292 ;
unsigned long V_82 ;
struct V_14 * V_15 ;
int V_31 ;
struct V_324 V_415 ;
V_292 = V_25 -> V_296 -> V_223 . V_383 ;
F_34 ( & V_2 -> V_85 , V_82 ) ;
if ( F_147 ( ! F_43 ( F_63 ( V_2 ) ) ) ) {
V_31 = - V_336 ;
goto V_416;
}
V_31 = F_203 ( F_63 ( V_2 ) , V_25 ) ;
if ( F_147 ( V_31 ) )
goto V_416;
F_129 ( & V_415 ) ;
V_15 = F_198 ( V_2 , V_25 , & V_415 , V_292 , & V_25 -> V_296 -> V_297 ) ;
if ( V_15 == NULL ) {
V_31 = - V_137 ;
goto V_78;
}
if ( V_15 -> V_288 == V_289 ) {
if ( ( V_31 = F_220 ( V_2 , V_15 ) ) != 0 )
goto V_78;
}
V_15 = F_198 ( V_2 , V_25 , V_276 , V_292 , & V_25 -> V_296 -> V_297 ) ;
F_145 ( V_15 == NULL ) ;
F_63 ( V_2 ) -> V_119 . V_319 ++ ;
V_78:
if ( F_147 ( V_31 ) )
F_166 ( F_63 ( V_2 ) , V_25 ) ;
V_416:
F_35 ( & V_2 -> V_85 , V_82 ) ;
if ( V_31 )
F_176 ( V_2 , V_25 , V_276 ) ;
return V_31 ;
}
static void F_225 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
F_100 (qh, fusbh200->qh_scan_next, &fusbh200->intr_qh_list,
intr_node) {
V_330:
if ( ! F_103 ( & V_15 -> V_276 ) ) {
int V_70 ;
V_70 = F_170 ( V_2 , V_15 ) ;
if ( F_147 ( V_15 -> V_331 ||
( F_103 ( & V_15 -> V_276 ) &&
V_15 -> V_288 == V_337 ) ) )
F_219 ( V_2 , V_15 ) ;
else if ( V_70 != 0 )
goto V_330;
}
}
}
static struct V_417 *
F_226 ( T_14 V_381 )
{
struct V_417 * V_400 ;
V_400 = F_50 ( sizeof *V_400 , V_381 ) ;
if ( F_38 ( V_400 != NULL ) ) {
F_129 ( & V_400 -> V_418 ) ;
F_129 ( & V_400 -> V_419 ) ;
V_400 -> V_420 = - 1 ;
}
return V_400 ;
}
static void
F_227 (
struct V_1 * V_2 ,
struct V_417 * V_400 ,
struct V_301 * V_293 ,
int V_300 ,
unsigned V_366
)
{
T_1 V_421 ;
unsigned V_292 , V_358 ;
int V_341 ;
long V_422 ;
unsigned V_404 ;
V_292 = F_157 ( V_300 ) ;
V_341 = F_162 ( V_300 ) ? V_384 : 0 ;
V_358 = F_184 ( V_293 , V_300 , ! V_341 ) ;
if ( V_341 ) {
V_421 = ( 1 << 11 ) ;
} else {
V_421 = 0 ;
}
V_358 = F_183 ( V_358 ) ;
V_404 = F_191 ( V_358 ) ;
V_421 |= V_358 ;
V_358 *= V_404 ;
V_400 -> V_423 = F_28 ( V_2 , ( V_292 << 8 ) | V_293 -> V_304 ) ;
V_400 -> V_421 = F_28 ( V_2 , V_421 ) ;
V_400 -> V_424 = F_28 ( V_2 , V_404 ) ;
if ( V_293 -> V_364 == V_371 ) {
V_366 <<= 3 ;
V_400 -> V_105 = F_189 ( F_190 ( V_293 -> V_364 ,
V_341 , 1 , V_358 ) ) ;
V_400 -> V_105 /= 8 ;
} else {
V_400 -> V_425 = 1 ;
V_400 -> V_105 = F_228 ( V_358 ) ;
}
V_422 = V_400 -> V_105 * 8 ;
V_422 /= V_366 ;
V_400 -> V_422 = V_422 ;
V_400 -> V_426 = V_293 ;
V_400 -> V_383 = V_341 | V_292 ;
V_400 -> V_366 = V_366 ;
V_400 -> V_358 = V_358 ;
}
static struct V_417 *
F_229 ( struct V_1 * V_2 , struct V_25 * V_25 )
{
unsigned V_292 ;
struct V_417 * V_400 ;
struct V_295 * V_296 ;
unsigned long V_82 ;
V_292 = F_157 ( V_25 -> V_300 ) ;
if ( F_162 ( V_25 -> V_300 ) )
V_296 = V_25 -> V_293 -> V_427 [ V_292 ] ;
else
V_296 = V_25 -> V_293 -> V_428 [ V_292 ] ;
F_34 ( & V_2 -> V_85 , V_82 ) ;
V_400 = V_296 -> V_297 ;
if ( F_147 ( V_400 == NULL ) ) {
V_400 = F_226 ( V_96 ) ;
if ( F_38 ( V_400 != NULL ) ) {
V_296 -> V_297 = V_400 ;
V_400 -> V_296 = V_296 ;
F_227 ( V_2 , V_400 , V_25 -> V_293 , V_25 -> V_300 ,
V_25 -> V_366 ) ;
}
} else if ( F_147 ( V_400 -> V_17 != NULL ) ) {
F_4 ( V_2 , L_117 ,
V_25 -> V_293 -> V_318 , V_292 ,
F_162 ( V_25 -> V_300 ) ? L_53 : L_52 ) ;
V_400 = NULL ;
}
F_35 ( & V_2 -> V_85 , V_82 ) ;
return V_400 ;
}
static struct V_429 *
F_230 ( unsigned V_430 , T_14 V_381 )
{
struct V_429 * V_431 ;
int V_71 = sizeof *V_431 ;
V_71 += V_430 * sizeof ( struct V_432 ) ;
V_431 = F_50 ( V_71 , V_381 ) ;
if ( F_38 ( V_431 != NULL ) ) {
F_129 ( & V_431 -> V_418 ) ;
}
return V_431 ;
}
static inline void
F_231 (
struct V_1 * V_2 ,
struct V_429 * V_431 ,
struct V_417 * V_400 ,
struct V_25 * V_25
)
{
unsigned V_93 ;
T_13 V_275 = V_25 -> V_348 ;
V_431 -> V_433 = V_25 -> V_434 * V_400 -> V_366 ;
for ( V_93 = 0 ; V_93 < V_25 -> V_434 ; V_93 ++ ) {
struct V_432 * V_398 = & V_431 -> V_435 [ V_93 ] ;
unsigned V_287 ;
T_13 V_29 ;
T_1 V_436 ;
V_287 = V_25 -> V_437 [ V_93 ] . V_287 ;
V_29 = V_275 + V_25 -> V_437 [ V_93 ] . V_142 ;
V_436 = V_438 ;
V_436 |= V_29 & 0x0fff ;
if ( F_147 ( ( ( V_93 + 1 ) == V_25 -> V_434 ) )
&& ! ( V_25 -> V_350 & V_354 ) )
V_436 |= V_439 ;
V_436 |= V_287 << 16 ;
V_398 -> V_440 = F_28 ( V_2 , V_436 ) ;
V_398 -> V_441 = ( V_29 & ~ ( T_15 ) 0x0fff ) ;
V_29 += V_287 ;
if ( F_147 ( ( V_398 -> V_441 != ( V_29 & ~ ( T_15 ) 0x0fff ) ) ) )
V_398 -> V_442 = 1 ;
}
}
static void
F_232 (
struct V_417 * V_400 ,
struct V_429 * V_431
)
{
if ( ! V_431 )
return;
F_233 ( & V_431 -> V_418 , & V_400 -> V_419 ) ;
F_40 ( V_431 ) ;
}
static int
F_234 (
struct V_417 * V_400 ,
struct V_1 * V_2 ,
struct V_25 * V_25 ,
T_14 V_381
)
{
struct V_22 * V_23 ;
T_13 V_203 ;
int V_93 ;
unsigned V_443 ;
struct V_429 * V_444 ;
unsigned long V_82 ;
V_444 = F_230 ( V_25 -> V_434 , V_381 ) ;
if ( F_147 ( V_444 == NULL ) )
return - V_137 ;
F_231 ( V_2 , V_444 , V_400 , V_25 ) ;
if ( V_25 -> V_366 < 8 )
V_443 = 1 + ( V_444 -> V_433 + 7 ) / 8 ;
else
V_443 = V_25 -> V_434 ;
F_34 ( & V_2 -> V_85 , V_82 ) ;
for ( V_93 = 0 ; V_93 < V_443 ; V_93 ++ ) {
if ( F_38 ( ! F_103 ( & V_400 -> V_419 ) ) ) {
V_23 = F_235 ( & V_400 -> V_419 ,
struct V_22 , V_200 ) ;
if ( V_23 -> V_24 == V_2 -> V_445 )
goto V_446;
F_101 ( & V_23 -> V_200 ) ;
V_203 = V_23 -> V_203 ;
} else {
V_446:
F_35 ( & V_2 -> V_85 , V_82 ) ;
V_23 = F_131 ( V_2 -> V_202 , V_381 ,
& V_203 ) ;
F_34 ( & V_2 -> V_85 , V_82 ) ;
if ( ! V_23 ) {
F_232 ( V_400 , V_444 ) ;
F_35 ( & V_2 -> V_85 , V_82 ) ;
return - V_137 ;
}
}
memset ( V_23 , 0 , sizeof *V_23 ) ;
V_23 -> V_203 = V_203 ;
F_200 ( & V_23 -> V_200 , & V_444 -> V_418 ) ;
}
F_35 ( & V_2 -> V_85 , V_82 ) ;
V_25 -> V_297 = V_444 ;
V_25 -> V_447 = 0 ;
return 0 ;
}
static inline int
F_236 (
struct V_1 * V_2 ,
T_1 V_448 ,
T_1 V_398 ,
T_16 V_105 ,
T_1 V_102
)
{
V_398 %= V_102 ;
do {
if ( F_212 ( V_2 , V_398 >> 3 , V_398 & 0x7 )
> ( V_2 -> V_401 - V_105 ) )
return 0 ;
V_398 += V_102 ;
} while ( V_398 < V_448 );
return 1 ;
}
static int
F_237 (
struct V_1 * V_2 ,
struct V_25 * V_25 ,
struct V_417 * V_400
)
{
T_1 V_212 , V_72 , V_362 , V_102 , V_433 ;
int V_31 ;
unsigned V_448 = V_2 -> V_97 << 3 ;
struct V_429 * V_444 = V_25 -> V_297 ;
V_102 = V_25 -> V_366 ;
V_433 = V_444 -> V_433 ;
if ( V_433 > V_448 - V_449 ) {
F_4 ( V_2 , L_118 , V_25 ) ;
V_31 = - V_450 ;
goto V_281;
}
V_212 = F_46 ( V_2 ) & ( V_448 - 1 ) ;
if ( F_38 ( ! F_103 ( & V_400 -> V_418 ) ) ) {
T_1 V_451 ;
if ( ! V_400 -> V_425 && V_2 -> V_452 )
V_72 = V_212 + V_2 -> V_453 ;
else
V_72 = V_212 ;
V_451 = ( V_400 -> V_420 - V_102 - V_72 ) & ( V_448 - 1 ) ;
if ( V_451 >= V_448 - 2 * V_449 )
V_362 = V_72 + V_451 - V_448 + V_102 *
F_238 ( V_448 - V_451 , V_102 ) ;
else
V_362 = V_72 + V_451 + V_102 ;
if ( V_362 - V_212 >= V_448 ) {
F_4 ( V_2 , L_119 ,
V_25 , V_362 - V_212 - V_102 , V_102 ,
V_448 ) ;
V_31 = - V_450 ;
goto V_281;
}
}
else {
int V_78 = 0 ;
V_362 = V_449 + ( V_212 & ~ 0x07 ) ;
V_72 = V_362 ;
V_362 += V_102 ;
do {
V_362 -- ;
if ( F_236 ( V_2 , V_448 , V_362 ,
V_400 -> V_105 , V_102 ) )
V_78 = 1 ;
} while ( V_362 > V_72 && ! V_78 );
if ( ! V_78 ) {
F_4 ( V_2 , L_120 ,
V_25 , V_212 , V_212 + V_448 ) ;
V_31 = - V_412 ;
goto V_281;
}
}
if ( F_147 ( V_362 - V_212 + V_433 - V_102
>= V_448 - 2 * V_449 ) ) {
F_4 ( V_2 , L_119 ,
V_25 , V_362 - V_212 , V_433 - V_102 ,
V_448 - 2 * V_449 ) ;
V_31 = - V_450 ;
goto V_281;
}
V_400 -> V_420 = V_362 & ( V_448 - 1 ) ;
V_25 -> V_454 = V_400 -> V_420 ;
if ( ! V_400 -> V_425 )
V_25 -> V_454 >>= 3 ;
if ( V_2 -> V_207 == 0 )
V_2 -> V_455 = V_212 >> 3 ;
return 0 ;
V_281:
F_232 ( V_400 , V_444 ) ;
V_25 -> V_297 = NULL ;
return V_31 ;
}
static inline void
F_239 ( struct V_1 * V_2 , struct V_417 * V_400 ,
struct V_22 * V_23 )
{
int V_93 ;
V_23 -> V_10 = F_25 ( V_2 ) ;
V_23 -> V_27 [ 0 ] = V_400 -> V_423 ;
V_23 -> V_27 [ 1 ] = V_400 -> V_421 ;
V_23 -> V_27 [ 2 ] = V_400 -> V_424 ;
for ( V_93 = 0 ; V_93 < 8 ; V_93 ++ )
V_23 -> V_28 [ V_93 ] = - 1 ;
}
static inline void
F_240 (
struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_429 * V_431 ,
unsigned V_28 ,
T_12 V_398
)
{
struct V_432 * V_456 = & V_431 -> V_435 [ V_28 ] ;
unsigned V_457 = V_23 -> V_457 ;
V_398 &= 0x07 ;
V_23 -> V_28 [ V_398 ] = V_28 ;
V_23 -> V_26 [ V_398 ] = V_456 -> V_440 ;
V_23 -> V_26 [ V_398 ] |= F_28 ( V_2 , V_457 << 12 ) ;
V_23 -> V_27 [ V_457 ] |= F_28 ( V_2 , V_456 -> V_441 & ~ ( T_1 ) 0 ) ;
V_23 -> V_458 [ V_457 ] |= F_28 ( V_2 , ( T_1 ) ( V_456 -> V_441 >> 32 ) ) ;
if ( F_147 ( V_456 -> V_442 ) ) {
T_15 V_441 = V_456 -> V_441 + 4096 ;
V_23 -> V_457 = ++ V_457 ;
V_23 -> V_27 [ V_457 ] |= F_28 ( V_2 , V_441 & ~ ( T_1 ) 0 ) ;
V_23 -> V_458 [ V_457 ] |= F_28 ( V_2 , ( T_1 ) ( V_441 >> 32 ) ) ;
}
}
static inline void
F_241 ( struct V_1 * V_2 , unsigned V_24 , struct V_22 * V_23 )
{
union V_89 * V_199 = & V_2 -> V_98 [ V_24 ] ;
T_3 * V_396 = & V_2 -> V_100 [ V_24 ] ;
union V_89 V_397 = * V_199 ;
T_3 type = 0 ;
while ( V_397 . V_99 ) {
type = F_39 ( V_2 , * V_396 ) ;
if ( type == F_28 ( V_2 , V_101 ) )
break;
V_199 = F_209 ( V_2 , V_199 , type ) ;
V_396 = F_210 ( V_2 , & V_397 , type ) ;
V_397 = * V_199 ;
}
V_23 -> V_112 = V_397 ;
V_23 -> V_10 = * V_396 ;
V_199 -> V_23 = V_23 ;
V_23 -> V_24 = V_24 ;
F_175 () ;
* V_396 = F_28 ( V_2 , V_23 -> V_203 | V_111 ) ;
}
static void F_242 (
struct V_1 * V_2 ,
struct V_25 * V_25 ,
unsigned V_448 ,
struct V_417 * V_400
)
{
int V_435 ;
unsigned V_420 , V_398 , V_24 ;
struct V_429 * V_431 = V_25 -> V_297 ;
struct V_22 * V_23 ;
V_420 = V_400 -> V_420 & ( V_448 - 1 ) ;
if ( F_147 ( F_103 ( & V_400 -> V_418 ) ) ) {
F_63 ( V_2 ) -> V_119 . V_406
+= V_400 -> V_422 ;
F_1 ( V_2 ,
L_121 ,
V_25 -> V_293 -> V_318 , V_400 -> V_383 & 0x0f ,
( V_400 -> V_383 & V_384 ) ? L_53 : L_52 ,
V_25 -> V_366 ,
V_420 >> 3 , V_420 & 0x7 ) ;
}
for ( V_435 = 0 , V_23 = NULL ; V_435 < V_25 -> V_434 ; ) {
if ( V_23 == NULL ) {
V_23 = F_98 ( V_431 -> V_418 . V_72 ,
struct V_22 , V_200 ) ;
F_243 ( & V_23 -> V_200 , & V_400 -> V_418 ) ;
V_23 -> V_400 = V_400 ;
V_23 -> V_25 = V_25 ;
F_239 ( V_2 , V_400 , V_23 ) ;
}
V_398 = V_420 & 0x07 ;
V_24 = V_420 >> 3 ;
F_240 ( V_2 , V_23 , V_431 , V_435 , V_398 ) ;
V_420 += V_400 -> V_366 ;
V_420 &= V_448 - 1 ;
V_435 ++ ;
if ( ( ( V_420 >> 3 ) != V_24 )
|| V_435 == V_25 -> V_434 ) {
F_241 ( V_2 , V_24 & ( V_2 -> V_97 - 1 ) , V_23 ) ;
V_23 = NULL ;
}
}
V_400 -> V_420 = V_420 ;
F_232 ( V_400 , V_431 ) ;
V_25 -> V_297 = NULL ;
++ V_2 -> V_207 ;
F_215 ( V_2 ) ;
}
static bool F_244 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_25 * V_25 = V_23 -> V_25 ;
struct V_459 * V_223 ;
T_1 V_211 ;
unsigned V_398 ;
int V_460 = - 1 ;
struct V_417 * V_400 = V_23 -> V_400 ;
struct V_301 * V_293 ;
bool V_160 = false ;
for ( V_398 = 0 ; V_398 < 8 ; V_398 ++ ) {
if ( F_38 ( V_23 -> V_28 [ V_398 ] == - 1 ) )
continue;
V_460 = V_23 -> V_28 [ V_398 ] ;
V_223 = & V_25 -> V_437 [ V_460 ] ;
V_211 = F_10 ( V_2 , & V_23 -> V_26 [ V_398 ] ) ;
V_23 -> V_26 [ V_398 ] = 0 ;
if ( F_147 ( V_211 & V_461 ) ) {
V_25 -> V_447 ++ ;
if ( V_211 & V_462 )
V_223 -> V_31 = F_162 ( V_25 -> V_300 )
? - V_315
: - V_316 ;
else if ( V_211 & V_463 )
V_223 -> V_31 = - V_311 ;
else
V_223 -> V_31 = - V_313 ;
if ( ! ( V_211 & V_463 ) ) {
V_223 -> V_307 = F_245 ( V_25 , V_223 , V_211 ) ;
V_25 -> V_307 += V_223 -> V_307 ;
}
} else if ( F_38 ( ( V_211 & V_438 ) == 0 ) ) {
V_223 -> V_31 = 0 ;
V_223 -> V_307 = F_245 ( V_25 , V_223 , V_211 ) ;
V_25 -> V_307 += V_223 -> V_307 ;
} else {
V_223 -> V_31 = - V_464 ;
}
}
if ( F_38 ( ( V_460 + 1 ) != V_25 -> V_434 ) )
goto V_78;
V_293 = V_25 -> V_293 ;
F_164 ( V_2 , V_25 , 0 ) ;
V_160 = true ;
V_25 = NULL ;
-- V_2 -> V_207 ;
F_216 ( V_2 ) ;
if ( F_147 ( F_246 ( & V_400 -> V_418 ) ) ) {
F_63 ( V_2 ) -> V_119 . V_406
-= V_400 -> V_422 ;
F_1 ( V_2 ,
L_122 ,
V_293 -> V_318 , V_400 -> V_383 & 0x0f ,
( V_400 -> V_383 & V_384 ) ? L_53 : L_52 ) ;
}
V_78:
V_23 -> V_25 = NULL ;
F_243 ( & V_23 -> V_200 , & V_400 -> V_419 ) ;
if ( F_103 ( & V_400 -> V_418 ) ) {
F_247 ( & V_400 -> V_419 ,
& V_2 -> V_198 ) ;
F_96 ( V_2 ) ;
}
return V_160 ;
}
static int F_248 ( struct V_1 * V_2 , struct V_25 * V_25 ,
T_14 V_381 )
{
int V_31 = - V_465 ;
unsigned long V_82 ;
struct V_417 * V_400 ;
V_400 = F_229 ( V_2 , V_25 ) ;
if ( F_147 ( V_400 == NULL ) ) {
F_4 ( V_2 , L_123 ) ;
return - V_137 ;
}
if ( F_147 ( V_25 -> V_366 != V_400 -> V_366 &&
F_122 ( V_2 , 0 ) == V_466 ) ) {
F_4 ( V_2 , L_124 ,
V_400 -> V_366 , V_25 -> V_366 ) ;
goto V_78;
}
#ifdef F_165
F_4 ( V_2 ,
L_125 ,
V_320 , V_25 -> V_293 -> V_318 , V_25 ,
F_157 ( V_25 -> V_300 ) ,
F_162 ( V_25 -> V_300 ) ? L_53 : L_52 ,
V_25 -> V_321 ,
V_25 -> V_434 , V_25 -> V_366 ,
V_400 ) ;
#endif
V_31 = F_234 ( V_400 , V_2 , V_25 , V_381 ) ;
if ( F_147 ( V_31 < 0 ) ) {
F_4 ( V_2 , L_126 ) ;
goto V_78;
}
F_34 ( & V_2 -> V_85 , V_82 ) ;
if ( F_147 ( ! F_43 ( F_63 ( V_2 ) ) ) ) {
V_31 = - V_336 ;
goto V_416;
}
V_31 = F_203 ( F_63 ( V_2 ) , V_25 ) ;
if ( F_147 ( V_31 ) )
goto V_416;
V_31 = F_237 ( V_2 , V_25 , V_400 ) ;
if ( F_38 ( V_31 == 0 ) )
F_242 ( V_2 , V_25 , V_2 -> V_97 << 3 , V_400 ) ;
else
F_166 ( F_63 ( V_2 ) , V_25 ) ;
V_416:
F_35 ( & V_2 -> V_85 , V_82 ) ;
V_78:
return V_31 ;
}
static void F_249 ( struct V_1 * V_2 )
{
unsigned V_456 , V_445 , V_24 ;
unsigned V_467 = V_2 -> V_97 - 1 ;
bool V_468 , V_469 ;
if ( V_2 -> V_113 >= V_116 ) {
V_456 = F_46 ( V_2 ) ;
V_445 = ( V_456 >> 3 ) & V_467 ;
V_469 = true ;
} else {
V_445 = ( V_2 -> V_455 - 1 ) & V_467 ;
V_469 = false ;
}
V_2 -> V_445 = V_445 ;
V_24 = V_2 -> V_455 ;
for (; ; ) {
union V_89 V_399 , * V_470 ;
T_3 type , * V_396 ;
V_391:
V_470 = & V_2 -> V_98 [ V_24 ] ;
V_396 = & V_2 -> V_100 [ V_24 ] ;
V_399 . V_99 = V_470 -> V_99 ;
type = F_39 ( V_2 , * V_396 ) ;
V_468 = false ;
while ( V_399 . V_99 != NULL ) {
switch ( F_13 ( V_2 , type ) ) {
case V_111 :
if ( V_24 == V_445 && V_469 ) {
F_172 () ;
for ( V_456 = 0 ; V_456 < 8 ; V_456 ++ ) {
if ( V_399 . V_23 -> V_26 [ V_456 ] &
F_250 ( V_2 ) )
break;
}
if ( V_456 < 8 ) {
V_470 = & V_399 . V_23 -> V_112 ;
V_396 = & V_399 . V_23 -> V_10 ;
type = F_39 ( V_2 ,
V_399 . V_23 -> V_10 ) ;
V_399 = * V_470 ;
break;
}
}
* V_470 = V_399 . V_23 -> V_112 ;
* V_396 = V_399 . V_23 -> V_10 ;
type = F_39 ( V_2 , V_399 . V_23 -> V_10 ) ;
F_175 () ;
V_468 = F_244 ( V_2 , V_399 . V_23 ) ;
V_399 = * V_470 ;
break;
default:
F_4 ( V_2 , L_127 ,
type , V_24 , V_399 . V_99 ) ;
case V_101 :
case V_107 :
V_399 . V_99 = NULL ;
break;
}
if ( F_147 ( V_468 && V_2 -> V_207 > 0 ) )
goto V_391;
}
if ( V_24 == V_445 )
break;
V_24 = ( V_24 + 1 ) & V_467 ;
}
V_2 -> V_455 = V_445 ;
}
static T_6 F_251 ( struct V_471 * V_293 ,
struct V_472 * V_473 ,
char * V_29 )
{
struct V_1 * V_2 ;
int V_201 ;
V_2 = F_33 ( F_32 ( F_252 ( V_293 ) ) ) ;
V_201 = F_15 ( V_29 , V_135 , L_128 , V_2 -> V_401 ) ;
return V_201 ;
}
static T_6 F_253 ( struct V_471 * V_293 ,
struct V_472 * V_473 ,
const char * V_29 , T_8 V_139 )
{
struct V_1 * V_2 ;
unsigned V_401 ;
unsigned V_24 , V_398 ;
unsigned short V_474 ;
unsigned long V_82 ;
T_6 V_136 ;
V_2 = F_33 ( F_32 ( F_252 ( V_293 ) ) ) ;
if ( F_254 ( V_29 , 0 , & V_401 ) < 0 )
return - V_465 ;
if ( V_401 < 100 || V_401 >= 125 ) {
F_255 ( V_2 , L_129
L_130 , V_401 ) ;
return - V_465 ;
}
V_136 = - V_465 ;
F_34 ( & V_2 -> V_85 , V_82 ) ;
if ( V_401 < V_2 -> V_401 ) {
V_474 = 0 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_97 ; ++ V_24 )
for ( V_398 = 0 ; V_398 < 7 ; ++ V_398 )
V_474 = F_256 ( V_474 ,
F_212 ( V_2 , V_24 , V_398 ) ) ;
if ( V_474 > V_401 ) {
F_255 ( V_2 ,
L_131
L_132
L_133 ,
V_474 , V_401 ) ;
goto V_475;
}
}
F_255 ( V_2 , L_134
L_135 ,
100 * V_401 / 125 , V_401 ) ;
if ( V_401 != 100 )
F_91 ( V_2 , L_136 ) ;
V_2 -> V_401 = V_401 ;
V_136 = V_139 ;
V_475:
F_35 ( & V_2 -> V_85 , V_82 ) ;
return V_136 ;
}
static inline int F_257 ( struct V_1 * V_2 )
{
struct V_471 * V_120 = F_63 ( V_2 ) -> V_119 . V_120 ;
int V_93 = 0 ;
if ( V_93 )
goto V_138;
V_93 = F_258 ( V_120 , & V_476 ) ;
V_138:
return V_93 ;
}
static inline void F_259 ( struct V_1 * V_2 )
{
struct V_471 * V_120 = F_63 ( V_2 ) -> V_119 . V_120 ;
F_260 ( V_120 , & V_476 ) ;
}
static void F_261 ( struct V_1 * V_2 )
{
T_1 T_10 * V_219 = & V_2 -> V_124 -> V_220 ;
F_71 ( V_2 , V_244 , V_219 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
F_69 ( V_2 ) ;
F_70 ( & V_2 -> V_85 ) ;
V_2 -> V_113 = V_114 ;
F_261 ( V_2 ) ;
F_72 ( & V_2 -> V_85 ) ;
}
static void F_263 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_33 ( V_81 ) ;
F_70 ( & V_2 -> V_85 ) ;
V_2 -> V_477 = true ;
V_2 -> V_113 = V_117 ;
V_2 -> V_173 = 0 ;
F_72 ( & V_2 -> V_85 ) ;
F_262 ( V_2 ) ;
F_264 ( & V_2 -> V_175 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
if ( V_2 -> V_478 ) {
V_2 -> V_479 = true ;
return;
}
V_2 -> V_478 = true ;
V_330:
V_2 -> V_479 = false ;
if ( V_2 -> V_182 )
F_208 ( V_2 ) ;
if ( V_2 -> V_209 > 0 )
F_225 ( V_2 ) ;
if ( V_2 -> V_207 > 0 )
F_249 ( V_2 ) ;
if ( V_2 -> V_479 )
goto V_330;
V_2 -> V_478 = false ;
F_106 ( V_2 ) ;
}
static void F_265 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_33 ( V_81 ) ;
F_4 ( V_2 , L_137 ) ;
F_70 ( & V_2 -> V_85 ) ;
V_2 -> V_173 = 0 ;
F_72 ( & V_2 -> V_85 ) ;
F_78 ( V_2 ) ;
F_262 ( V_2 ) ;
F_74 ( V_2 ) ;
F_264 ( & V_2 -> V_175 ) ;
F_259 ( V_2 ) ;
F_21 ( V_2 ) ;
F_70 ( & V_2 -> V_85 ) ;
F_99 ( V_2 ) ;
F_72 ( & V_2 -> V_85 ) ;
F_136 ( V_2 ) ;
#ifdef F_47
F_4 ( V_2 , L_78 ,
V_2 -> V_126 . V_127 , V_2 -> V_126 . error , V_2 -> V_126 . V_128 ,
V_2 -> V_126 . V_129 ) ;
F_4 ( V_2 , L_79 ,
V_2 -> V_126 . V_130 , V_2 -> V_126 . V_131 ) ;
#endif
F_266 ( V_2 , L_138 ,
F_3 ( V_2 , & V_2 -> V_124 -> V_31 ) ) ;
}
static int F_267 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_33 ( V_81 ) ;
T_1 V_70 ;
int V_160 ;
T_1 V_7 ;
struct V_16 * V_17 ;
F_268 ( & V_2 -> V_85 ) ;
V_2 -> V_208 = 1 ;
F_269 ( & V_2 -> V_175 , V_480 , V_177 ) ;
V_2 -> V_175 . V_481 = F_107 ;
V_2 -> V_174 = V_215 ;
V_7 = F_3 ( V_2 , & V_2 -> V_5 -> V_7 ) ;
V_2 -> V_401 = 100 ;
V_2 -> V_97 = V_482 ;
F_129 ( & V_2 -> V_408 ) ;
F_129 ( & V_2 -> V_198 ) ;
if ( F_7 ( V_7 ) ) {
switch ( V_483 ) {
case 0 : V_2 -> V_97 = 1024 ; break;
case 1 : V_2 -> V_97 = 512 ; break;
case 2 : V_2 -> V_97 = 256 ; break;
default: F_134 () ;
}
}
if ( ( V_160 = F_139 ( V_2 , V_133 ) ) < 0 )
return V_160 ;
V_2 -> V_453 = 2 ;
V_2 -> V_75 -> V_86 . V_15 = NULL ;
V_17 = V_2 -> V_75 -> V_17 ;
V_17 -> V_10 = F_197 ( V_2 , V_2 -> V_75 -> V_280 ) ;
V_17 -> V_18 = F_28 ( V_2 , V_484 ) ;
V_17 -> V_12 = F_28 ( V_2 , V_64 ) ;
V_17 -> V_21 = F_25 ( V_2 ) ;
V_2 -> V_75 -> V_288 = V_337 ;
V_17 -> V_11 = F_146 ( V_2 , V_2 -> V_75 -> V_278 -> V_77 ) ;
if ( V_485 < 0 || V_485 > 6 )
V_485 = 0 ;
V_70 = 1 << ( 16 + V_485 ) ;
if ( F_8 ( V_7 ) ) {
if ( V_486 ) {
V_486 = F_270 ( V_486 , ( unsigned ) 3 ) ;
V_70 |= V_44 ;
V_70 |= V_486 << 8 ;
}
F_4 ( V_2 , L_139 , V_486 ) ;
}
if ( F_7 ( V_7 ) ) {
V_70 &= ~ ( 3 << 2 ) ;
V_70 |= ( V_483 << 2 ) ;
}
V_2 -> V_43 = V_70 ;
if ( ! ( V_81 -> V_487 -> V_82 & V_488 ) )
V_81 -> V_119 . V_489 = ~ 0 ;
return 0 ;
}
static int F_271 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_33 ( V_81 ) ;
T_1 V_70 ;
T_1 V_7 ;
V_81 -> V_490 = 1 ;
F_71 ( V_2 , V_2 -> V_283 , & V_2 -> V_124 -> V_491 ) ;
F_71 ( V_2 , ( T_1 ) V_2 -> V_75 -> V_280 , & V_2 -> V_124 -> V_492 ) ;
V_7 = F_3 ( V_2 , & V_2 -> V_5 -> V_7 ) ;
V_2 -> V_43 &= ~ ( V_45 | V_47 | V_46 | V_49 ) ;
V_2 -> V_43 |= V_50 ;
F_71 ( V_2 , V_2 -> V_43 , & V_2 -> V_124 -> V_43 ) ;
F_76 ( V_2 , L_140 , V_2 -> V_43 ) ;
F_272 ( & V_493 ) ;
V_2 -> V_113 = V_116 ;
F_3 ( V_2 , & V_2 -> V_124 -> V_43 ) ;
F_273 ( 5 ) ;
F_274 ( & V_493 ) ;
V_2 -> V_494 = F_275 () ;
V_70 = F_45 ( V_2 , F_3 ( V_2 , & V_2 -> V_5 -> V_123 ) ) ;
F_255 ( V_2 ,
L_141 ,
( ( V_2 -> V_495 & 0xf0 ) >> 4 ) , ( V_2 -> V_495 & 0x0f ) ,
V_70 >> 8 , V_70 & 0xff ) ;
F_71 ( V_2 , V_496 ,
& V_2 -> V_124 -> V_125 ) ;
F_20 ( V_2 ) ;
F_257 ( V_2 ) ;
return 0 ;
}
static int F_276 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_33 ( V_81 ) ;
int V_160 ;
V_2 -> V_124 = ( void T_10 * ) V_2 -> V_5 +
F_277 ( V_2 , F_3 ( V_2 , & V_2 -> V_5 -> V_123 ) ) ;
F_2 ( V_2 , L_83 ) ;
F_6 ( V_2 , L_83 ) ;
V_2 -> V_6 = F_3 ( V_2 , & V_2 -> V_5 -> V_6 ) ;
V_2 -> V_495 = V_497 ;
V_160 = F_267 ( V_81 ) ;
if ( V_160 )
return V_160 ;
V_160 = F_69 ( V_2 ) ;
if ( V_160 )
return V_160 ;
F_74 ( V_2 ) ;
return 0 ;
}
static T_17 F_278 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_33 ( V_81 ) ;
T_1 V_31 , V_498 , V_499 = 0 , V_205 ;
int V_500 ;
F_169 ( & V_2 -> V_85 ) ;
V_31 = F_3 ( V_2 , & V_2 -> V_124 -> V_31 ) ;
if ( V_31 == ~ ( T_1 ) 0 ) {
F_4 ( V_2 , L_142 ) ;
goto V_501;
}
V_498 = V_31 & ( V_496 | V_38 ) ;
if ( ! V_498 || F_147 ( V_2 -> V_113 == V_114 ) ) {
F_167 ( & V_2 -> V_85 ) ;
return V_502 ;
}
F_71 ( V_2 , V_498 , & V_2 -> V_124 -> V_31 ) ;
V_205 = F_3 ( V_2 , & V_2 -> V_124 -> V_43 ) ;
V_500 = 0 ;
#ifdef F_123
F_266 ( V_2 , L_143 , V_31 ) ;
#endif
if ( F_38 ( ( V_31 & ( V_41 | V_40 ) ) != 0 ) ) {
if ( F_38 ( ( V_31 & V_40 ) == 0 ) )
F_105 ( V_2 -> V_126 . V_127 ) ;
else
F_105 ( V_2 -> V_126 . error ) ;
V_500 = 1 ;
}
if ( V_31 & V_36 ) {
V_2 -> V_173 &= ~ F_97 ( V_390 ) ;
if ( V_2 -> V_174 == V_390 )
++ V_2 -> V_174 ;
if ( V_205 & V_45 )
F_4 ( V_2 , L_144 ) ;
if ( V_2 -> V_204 ) {
F_105 ( V_2 -> V_126 . V_128 ) ;
F_93 ( V_2 ) ;
} else
F_4 ( V_2 , L_145 ) ;
}
if ( V_31 & V_39 ) {
int V_503 ;
T_1 T_10 * V_219 = & V_2 -> V_124 -> V_220 ;
V_499 = V_31 ;
if ( V_2 -> V_113 == V_115 )
F_279 ( V_81 ) ;
V_503 = F_3 ( V_2 , V_219 ) ;
if ( F_112 ( 0 , & V_2 -> V_165 ) &&
( ( V_503 & V_55 ) ||
! ( V_503 & V_54 ) ) &&
( V_503 & V_57 ) &&
V_2 -> V_221 [ 0 ] == 0 ) {
V_2 -> V_221 [ 0 ] = V_163 + F_117 ( 25 ) ;
F_120 ( 0 , & V_2 -> V_166 ) ;
F_4 ( V_2 , L_146 ) ;
F_119 ( & V_81 -> V_260 , V_2 -> V_221 [ 0 ] ) ;
}
}
if ( F_147 ( ( V_31 & V_37 ) != 0 ) ) {
F_121 ( V_2 , L_147 ) ;
F_76 ( V_2 , L_148 , V_205 ) ;
F_266 ( V_2 , L_148 , V_31 ) ;
V_501:
F_280 ( V_81 ) ;
V_2 -> V_477 = true ;
V_2 -> V_113 = V_117 ;
V_2 -> V_43 &= ~ ( V_50 | V_46 | V_47 ) ;
F_71 ( V_2 , V_2 -> V_43 , & V_2 -> V_124 -> V_43 ) ;
F_71 ( V_2 , 0 , & V_2 -> V_124 -> V_125 ) ;
F_90 ( V_2 ) ;
V_500 = 0 ;
}
if ( V_500 )
F_92 ( V_2 ) ;
F_167 ( & V_2 -> V_85 ) ;
if ( V_499 )
F_281 ( V_81 ) ;
return V_504 ;
}
static int F_282 (
struct V_80 * V_81 ,
struct V_25 * V_25 ,
T_14 V_381
) {
struct V_1 * V_2 = F_33 ( V_81 ) ;
struct V_324 V_276 ;
F_129 ( & V_276 ) ;
switch ( F_188 ( V_25 -> V_300 ) ) {
case V_373 :
if ( V_25 -> V_321 > ( 16 * 1024 ) )
return - V_505 ;
default:
if ( ! F_177 ( V_2 , V_25 , & V_276 , V_381 ) )
return - V_137 ;
return F_202 ( V_2 , V_25 , & V_276 , V_381 ) ;
case V_360 :
if ( ! F_177 ( V_2 , V_25 , & V_276 , V_381 ) )
return - V_137 ;
return F_224 ( V_2 , V_25 , & V_276 , V_381 ) ;
case V_506 :
return F_248 ( V_2 , V_25 , V_381 ) ;
}
}
static int F_283 ( struct V_80 * V_81 , struct V_25 * V_25 , int V_31 )
{
struct V_1 * V_2 = F_33 ( V_81 ) ;
struct V_14 * V_15 ;
unsigned long V_82 ;
int V_382 ;
F_34 ( & V_2 -> V_85 , V_82 ) ;
V_382 = F_284 ( V_81 , V_25 , V_31 ) ;
if ( V_382 )
goto V_78;
switch ( F_188 ( V_25 -> V_300 ) ) {
default:
V_15 = (struct V_14 * ) V_25 -> V_297 ;
if ( ! V_15 )
break;
switch ( V_15 -> V_288 ) {
case V_337 :
case V_329 :
F_207 ( V_2 , V_15 ) ;
break;
case V_385 :
case V_507 :
break;
case V_289 :
F_170 ( V_2 , V_15 ) ;
break;
}
break;
case V_360 :
V_15 = (struct V_14 * ) V_25 -> V_297 ;
if ( ! V_15 )
break;
switch ( V_15 -> V_288 ) {
case V_337 :
case V_329 :
F_219 ( V_2 , V_15 ) ;
break;
case V_289 :
F_170 ( V_2 , V_15 ) ;
break;
default:
F_4 ( V_2 , L_149 ,
V_15 , V_15 -> V_288 ) ;
goto V_78;
}
break;
case V_506 :
break;
}
V_78:
F_35 ( & V_2 -> V_85 , V_82 ) ;
return V_382 ;
}
static void
F_285 ( struct V_80 * V_81 , struct V_295 * V_296 )
{
struct V_1 * V_2 = F_33 ( V_81 ) ;
unsigned long V_82 ;
struct V_14 * V_15 , * V_326 ;
V_330:
F_34 ( & V_2 -> V_85 , V_82 ) ;
V_15 = V_296 -> V_297 ;
if ( ! V_15 )
goto V_78;
if ( V_15 -> V_17 == NULL ) {
struct V_417 * V_400 = V_296 -> V_297 ;
if ( ! F_103 ( & V_400 -> V_418 ) )
goto V_508;
F_40 ( V_400 ) ;
goto V_78;
}
if ( V_2 -> V_113 < V_116 )
V_15 -> V_288 = V_289 ;
switch ( V_15 -> V_288 ) {
case V_337 :
case V_329 :
for ( V_326 = V_2 -> V_75 -> V_86 . V_15 ;
V_326 && V_326 != V_15 ;
V_326 = V_326 -> V_86 . V_15 )
continue;
if ( V_326 )
F_207 ( V_2 , V_15 ) ;
case V_385 :
case V_507 :
V_508:
F_35 ( & V_2 -> V_85 , V_82 ) ;
F_286 ( 1 ) ;
goto V_330;
case V_289 :
if ( V_15 -> V_298 )
goto V_508;
if ( F_103 ( & V_15 -> V_276 ) ) {
F_133 ( V_2 , V_15 ) ;
break;
}
default:
F_121 ( V_2 , L_150 ,
V_15 , V_296 -> V_223 . V_383 , V_15 -> V_288 ,
F_103 ( & V_15 -> V_276 ) ? L_6 : L_151 ) ;
break;
}
V_78:
V_296 -> V_297 = NULL ;
F_35 ( & V_2 -> V_85 , V_82 ) ;
}
static void
F_287 ( struct V_80 * V_81 , struct V_295 * V_296 )
{
struct V_1 * V_2 = F_33 ( V_81 ) ;
struct V_14 * V_15 ;
int V_509 = F_288 ( & V_296 -> V_223 ) ;
int V_292 = F_173 ( & V_296 -> V_223 ) ;
int V_291 = F_289 ( & V_296 -> V_223 ) ;
unsigned long V_82 ;
if ( V_509 != V_510 && V_509 != V_511 )
return;
F_34 ( & V_2 -> V_85 , V_82 ) ;
V_15 = V_296 -> V_297 ;
if ( V_15 ) {
F_149 ( V_15 -> V_293 , V_292 , V_291 , 0 ) ;
if ( ! F_103 ( & V_15 -> V_276 ) ) {
F_290 ( 1 , L_152 ) ;
} else if ( V_15 -> V_288 == V_337 ||
V_15 -> V_288 == V_329 ) {
if ( V_509 == V_510 )
F_207 ( V_2 , V_15 ) ;
else
F_219 ( V_2 , V_15 ) ;
}
}
F_35 ( & V_2 -> V_85 , V_82 ) ;
}
static int F_291 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_33 ( V_81 ) ;
return ( F_46 ( V_2 ) >> 3 ) % V_2 -> V_97 ;
}
static void F_292 ( struct V_1 * V_2 )
{
T_1 V_512 ;
V_512 = F_3 ( V_2 , & V_2 -> V_124 -> V_513 ) ;
V_512 |= V_514 ;
V_512 &= ~ V_515 ;
F_71 ( V_2 , V_512 , & V_2 -> V_124 -> V_513 ) ;
V_512 = F_3 ( V_2 , & V_2 -> V_124 -> V_516 ) ;
F_71 ( V_2 , V_512 | V_517 | V_518 ,
& V_2 -> V_124 -> V_516 ) ;
}
static int F_293 ( struct V_519 * V_520 )
{
struct V_471 * V_293 = & V_520 -> V_293 ;
struct V_80 * V_81 ;
struct V_521 * V_522 ;
int V_159 ;
int V_160 = - V_157 ;
struct V_1 * V_2 ;
if ( F_294 () )
return - V_157 ;
V_520 -> V_293 . V_523 . V_524 = V_525 ;
V_522 = F_295 ( V_520 , V_526 , 0 ) ;
if ( ! V_522 ) {
F_296 ( V_293 ,
L_153 ,
F_44 ( V_293 ) ) ;
return - V_157 ;
}
V_159 = V_522 -> V_362 ;
V_81 = F_297 ( & V_527 , V_293 ,
F_44 ( V_293 ) ) ;
if ( ! V_81 ) {
F_296 ( V_293 , L_154 , V_160 ) ;
V_160 = - V_137 ;
goto V_528;
}
V_522 = F_295 ( V_520 , V_529 , 0 ) ;
if ( ! V_522 ) {
F_296 ( V_293 ,
L_155 ,
F_44 ( V_293 ) ) ;
V_160 = - V_157 ;
goto V_530;
}
V_81 -> V_531 = V_522 -> V_362 ;
V_81 -> V_532 = F_298 ( V_522 ) ;
V_81 -> V_533 = 1 ;
if ( ! F_299 ( V_81 -> V_531 , V_81 -> V_532 ,
V_527 . V_534 ) ) {
F_156 ( V_293 , L_156 ) ;
V_160 = - V_535 ;
goto V_530;
}
V_522 = F_295 ( V_520 , V_536 , 0 ) ;
if ( ! V_522 ) {
F_296 ( V_293 ,
L_155 ,
F_44 ( V_293 ) ) ;
V_160 = - V_157 ;
goto V_530;
}
V_81 -> V_124 = F_300 ( V_522 -> V_362 , F_298 ( V_522 ) ) ;
if ( V_81 -> V_124 == NULL ) {
F_156 ( V_293 , L_157 ) ;
V_160 = - V_537 ;
goto V_538;
}
V_2 = F_33 ( V_81 ) ;
V_2 -> V_5 = V_81 -> V_124 ;
V_160 = F_276 ( V_81 ) ;
if ( V_160 )
goto V_539;
F_292 ( V_2 ) ;
V_160 = F_301 ( V_81 , V_159 , V_540 ) ;
if ( V_160 ) {
F_296 ( V_293 , L_158 , V_160 ) ;
goto V_539;
}
return V_160 ;
V_539:
F_302 ( V_81 -> V_124 ) ;
V_538:
F_303 ( V_81 -> V_531 , V_81 -> V_532 ) ;
V_530:
F_304 ( V_81 ) ;
V_528:
F_296 ( V_293 , L_159 , F_44 ( V_293 ) , V_160 ) ;
return V_160 ;
}
static int F_305 ( struct V_519 * V_520 )
{
struct V_471 * V_293 = & V_520 -> V_293 ;
struct V_80 * V_81 = F_252 ( V_293 ) ;
if ( ! V_81 )
return 0 ;
F_306 ( V_81 ) ;
F_302 ( V_81 -> V_124 ) ;
F_303 ( V_81 -> V_531 , V_81 -> V_532 ) ;
F_304 ( V_81 ) ;
return 0 ;
}
static int T_18 F_307 ( void )
{
int V_160 = 0 ;
if ( F_294 () )
return - V_157 ;
F_308 ( V_541 L_160 V_542 L_55 , V_543 ) ;
F_120 ( V_544 , & V_545 ) ;
if ( F_112 ( V_546 , & V_545 ) ||
F_112 ( V_547 , & V_545 ) )
F_308 ( V_548 L_161
L_162 ) ;
F_309 ( L_163 ,
V_543 ,
sizeof( struct V_14 ) , sizeof( struct V_8 ) ,
sizeof( struct V_22 ) ) ;
#ifdef F_155
V_148 = F_64 ( L_164 , V_549 ) ;
if ( ! V_148 ) {
V_160 = - V_550 ;
goto V_551;
}
#endif
V_160 = F_310 ( & V_552 ) ;
if ( V_160 < 0 )
goto V_553;
return V_160 ;
F_311 ( & V_552 ) ;
V_553:
#ifdef F_155
F_312 ( V_148 ) ;
V_148 = NULL ;
V_551:
#endif
F_118 ( V_544 , & V_545 ) ;
return V_160 ;
}
static void T_19 F_313 ( void )
{
F_311 ( & V_552 ) ;
#ifdef F_155
F_312 ( V_148 ) ;
#endif
F_118 ( V_544 , & V_545 ) ;
}
