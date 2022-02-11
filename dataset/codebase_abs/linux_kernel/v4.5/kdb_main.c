struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 ) ;
#ifdef F_3
if ( ( F_4 ( V_3 ) -> V_4 & F_3 ) && F_5 ( V_2 ) )
V_3 = V_5 -> V_3 ;
#endif
return V_3 ;
}
static inline bool F_6 ( T_1 V_4 , int V_6 ,
bool V_7 )
{
V_6 &= V_8 ;
V_6 |= V_9 ;
if ( V_7 )
V_6 |= V_6 << V_10 ;
V_4 |= V_11 ;
return V_6 & V_4 ;
}
char * F_7 ( const char * V_12 )
{
char * * V_13 = V_14 ;
int V_15 = strlen ( V_12 ) ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
char * V_18 = * V_13 ++ ;
if ( ! V_18 )
continue;
if ( ( strncmp ( V_12 , V_18 , V_15 ) == 0 )
&& ( ( V_18 [ V_15 ] == '\0' )
|| ( V_18 [ V_15 ] == '=' ) ) ) {
char * V_19 = strchr ( V_18 , '=' ) ;
return V_19 ? ++ V_19 : L_1 ;
}
}
return NULL ;
}
static char * F_8 ( T_2 V_20 )
{
#define F_9 512
static char V_21 [ F_9 ] ;
static int V_22 ;
char * V_13 = NULL ;
if ( ( F_9 - V_22 ) >= V_20 ) {
V_13 = & V_21 [ V_22 ] ;
V_22 += V_20 ;
}
return V_13 ;
}
static int F_10 ( const char * V_12 , unsigned long * V_23 )
{
char * V_13 ;
V_13 = F_7 ( V_12 ) ;
if ( ! V_13 )
return V_24 ;
if ( strlen ( V_13 ) == 0 )
return V_25 ;
* V_23 = F_11 ( V_13 , NULL , 0 ) ;
return 0 ;
}
int F_12 ( const char * V_12 , int * V_23 )
{
unsigned long V_26 ;
int V_27 ;
V_27 = F_10 ( V_12 , & V_26 ) ;
if ( ! V_27 )
* V_23 = ( int ) V_26 ;
return V_27 ;
}
int F_13 ( const char * V_28 , unsigned long * V_23 )
{
char * V_29 ;
unsigned long V_26 ;
V_26 = F_11 ( V_28 , & V_29 , 0 ) ;
if ( V_29 == V_28 ) {
V_26 = F_11 ( V_28 , & V_29 , 16 ) ;
if ( V_29 == V_28 )
return V_30 ;
}
* V_23 = V_26 ;
return 0 ;
}
int F_14 ( const char * V_28 , T_3 * V_23 )
{
char * V_29 ;
T_3 V_26 ;
V_26 = F_15 ( V_28 , & V_29 , 0 ) ;
if ( V_29 == V_28 ) {
V_26 = F_15 ( V_28 , & V_29 , 16 ) ;
if ( V_29 == V_28 )
return V_30 ;
}
* V_23 = V_26 ;
return 0 ;
}
int F_16 ( int V_31 , const char * * V_32 )
{
int V_16 ;
char * V_13 ;
T_2 V_33 , V_34 ;
if ( V_31 == 3 ) {
V_32 [ 2 ] = V_32 [ 3 ] ;
V_31 -- ;
}
if ( V_31 != 2 )
return V_35 ;
if ( strcmp ( V_32 [ 1 ] , L_2 ) == 0 ) {
unsigned int V_36 ;
char * V_19 ;
V_36 = F_11 ( V_32 [ 2 ] , & V_19 , 0 ) ;
if ( V_19 == V_32 [ 2 ] || V_36 & ~ V_37 ) {
F_17 ( L_3 ,
V_32 [ 2 ] ) ;
return 0 ;
}
V_38 = ( V_38 &
~ ( V_37 << V_39 ) )
| ( V_36 << V_39 ) ;
return 0 ;
}
V_33 = strlen ( V_32 [ 1 ] ) ;
V_34 = strlen ( V_32 [ 2 ] ) ;
V_13 = F_8 ( V_33 + V_34 + 2 ) ;
if ( V_13 == ( char * ) 0 )
return V_40 ;
sprintf ( V_13 , L_4 , V_32 [ 1 ] , V_32 [ 2 ] ) ;
V_13 [ V_33 + V_34 + 1 ] = '\0' ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
if ( V_14 [ V_16 ]
&& ( ( strncmp ( V_14 [ V_16 ] , V_32 [ 1 ] , V_33 ) == 0 )
&& ( ( V_14 [ V_16 ] [ V_33 ] == '\0' )
|| ( V_14 [ V_16 ] [ V_33 ] == '=' ) ) ) ) {
V_14 [ V_16 ] = V_13 ;
return 0 ;
}
}
for ( V_16 = 0 ; V_16 < V_17 - 1 ; V_16 ++ ) {
if ( V_14 [ V_16 ] == ( char * ) 0 ) {
V_14 [ V_16 ] = V_13 ;
return 0 ;
}
}
return V_41 ;
}
static int F_18 ( void )
{
if ( ! V_42 ) {
F_17 ( L_5
L_6 ) ;
return V_43 ;
}
return 0 ;
}
int F_19 ( int V_31 , const char * * V_32 , int * V_44 ,
unsigned long * V_23 , long * V_45 ,
char * * V_46 )
{
unsigned long V_47 ;
unsigned long V_48 = 0 ;
int V_49 ;
int V_27 ;
int V_50 = 0 ;
char * V_51 ;
char V_52 = '\0' ;
char * V_19 ;
T_4 V_53 ;
if ( ! F_6 ( V_54 | V_55 ,
V_56 , false ) )
return V_57 ;
if ( * V_44 > V_31 )
return V_35 ;
V_51 = ( char * ) V_32 [ * V_44 ] ;
V_19 = strpbrk ( V_51 , L_7 ) ;
if ( V_19 != NULL ) {
V_52 = * V_19 ;
* V_19 ++ = '\0' ;
}
if ( V_51 [ 0 ] == '$' ) {
V_27 = F_10 ( & V_51 [ 1 ] , & V_47 ) ;
if ( V_27 )
return V_27 ;
} else if ( V_51 [ 0 ] == '%' ) {
V_27 = F_18 () ;
if ( V_27 )
return V_27 ;
return V_58 ;
} else {
V_50 = F_20 ( V_51 , & V_53 ) ;
if ( V_50 ) {
V_47 = V_53 . V_59 ;
} else {
V_27 = F_13 ( V_32 [ * V_44 ] , & V_47 ) ;
if ( V_27 )
return V_27 ;
}
}
if ( ! V_50 )
V_50 = F_21 ( V_47 , & V_53 ) ;
( * V_44 ) ++ ;
if ( V_46 )
* V_46 = V_51 ;
if ( V_23 )
* V_23 = V_47 ;
if ( V_45 && V_46 && * V_46 )
* V_45 = V_47 - V_53 . V_59 ;
if ( ( * V_44 > V_31 )
&& ( V_52 == '\0' ) )
return 0 ;
if ( V_52 == '\0' ) {
if ( ( V_32 [ * V_44 ] [ 0 ] != '+' )
&& ( V_32 [ * V_44 ] [ 0 ] != '-' ) ) {
return 0 ;
} else {
V_49 = ( V_32 [ * V_44 ] [ 0 ] == '+' ) ;
( * V_44 ) ++ ;
}
} else
V_49 = ( V_52 == '+' ) ;
if ( ( * V_44 > V_31 )
&& ( V_52 == '\0' ) ) {
return V_60 ;
}
if ( ! V_52 ) {
V_19 = ( char * ) V_32 [ * V_44 ] ;
( * V_44 ) ++ ;
}
V_27 = F_13 ( V_19 , & V_48 ) ;
if ( V_27 )
return V_27 ;
if ( ! V_49 )
V_48 = - V_48 ;
if ( V_45 )
* V_45 += V_48 ;
if ( V_23 )
* V_23 += V_48 ;
return 0 ;
}
static void F_22 ( int V_27 )
{
int V_16 ;
if ( V_27 >= 0 ) {
F_17 ( L_8 , V_27 ) ;
return;
}
for ( V_16 = 0 ; V_16 < V_61 ; V_16 ++ ) {
if ( V_62 [ V_16 ] . V_63 == V_27 ) {
F_17 ( L_9 , V_27 , V_62 [ V_16 ] . V_64 ) ;
return;
}
}
F_17 ( L_10 , - V_27 ) ;
}
static int F_23 ( const char * V_65 , const char * V_66 )
{
struct V_67 * V_68 = V_67 + V_69 - 1 ;
char * * V_70 = V_68 -> V_71 ;
if ( strcmp ( V_66 , L_11 ) == 0 ) {
V_72 = 0 ;
if ( ! V_68 -> V_73 )
V_68 -> V_74 = 0 ;
if ( V_68 -> V_74 )
F_24 ( V_68 -> V_46 , V_75 , V_68 -> V_76 ,
V_68 -> V_77 , 0 ,
V_9 ) ;
return 0 ;
}
if ( ! V_68 -> V_74 )
return V_58 ;
V_68 -> V_71 = F_25 ( ( V_68 -> V_73 + 1 ) * sizeof( * ( V_68 -> V_71 ) ) , V_78 ) ;
if ( ! V_68 -> V_71 ) {
F_17 ( L_12 ,
V_65 ) ;
V_68 -> V_74 = 0 ;
return V_58 ;
}
memcpy ( V_68 -> V_71 , V_70 , V_68 -> V_73 * sizeof( * ( V_68 -> V_71 ) ) ) ;
V_68 -> V_71 [ V_68 -> V_73 ++ ] = F_26 ( V_65 , V_78 ) ;
F_27 ( V_70 ) ;
return 0 ;
}
static int F_28 ( int V_31 , const char * * V_32 )
{
struct V_67 * V_79 = V_67 , * V_68 ;
if ( V_72 ) {
F_17 ( L_13
L_14 ) ;
F_23 ( L_11 , L_11 ) ;
}
if ( V_31 == 0 ) {
int V_16 ;
for ( V_68 = V_67 ; V_68 < V_67 + V_69 ; ++ V_68 ) {
F_17 ( L_15 , V_68 -> V_46 ,
V_68 -> V_76 , V_68 -> V_77 ) ;
for ( V_16 = 0 ; V_16 < V_68 -> V_73 ; ++ V_16 )
F_17 ( L_16 , V_68 -> V_71 [ V_16 ] ) ;
F_17 ( L_14 ) ;
}
return 0 ;
}
if ( V_31 != 3 )
return V_35 ;
if ( F_29 () ) {
F_17 ( L_17 ) ;
return V_58 ;
}
V_67 = F_30 ( ( V_69 + 1 ) * sizeof( * V_67 ) ,
V_78 ) ;
if ( ! V_67 )
goto V_80;
memcpy ( V_67 , V_79 ,
V_69 * sizeof( * V_67 ) ) ;
V_68 = V_67 + V_69 ;
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
V_68 -> V_74 = 1 ;
V_68 -> V_46 = F_26 ( V_32 [ 1 ] , V_78 ) ;
if ( ! V_68 -> V_46 )
goto V_81;
V_68 -> V_76 = F_26 ( V_32 [ 2 ] , V_78 ) ;
if ( ! V_68 -> V_76 )
goto V_82;
V_68 -> V_77 = F_26 ( V_32 [ 3 ] , V_78 ) ;
if ( ! V_68 -> V_77 )
goto V_83;
if ( V_68 -> V_76 [ 0 ] == '"' ) {
strcpy ( V_68 -> V_76 , V_32 [ 2 ] + 1 ) ;
V_68 -> V_76 [ strlen ( V_68 -> V_76 ) - 1 ] = '\0' ;
}
if ( V_68 -> V_77 [ 0 ] == '"' ) {
strcpy ( V_68 -> V_77 , V_32 [ 3 ] + 1 ) ;
V_68 -> V_77 [ strlen ( V_68 -> V_77 ) - 1 ] = '\0' ;
}
++ V_69 ;
V_72 = 1 ;
F_27 ( V_79 ) ;
return 0 ;
V_83:
F_27 ( V_68 -> V_76 ) ;
V_82:
F_27 ( V_68 -> V_46 ) ;
V_81:
F_27 ( V_67 ) ;
V_80:
F_17 ( L_18 , V_32 [ 1 ] ) ;
V_67 = V_79 ;
return V_58 ;
}
static int V_75 ( int V_31 , const char * * V_32 )
{
int V_16 , V_84 ;
struct V_67 * V_68 ;
if ( V_31 != 0 )
return V_35 ;
for ( V_68 = V_67 , V_16 = 0 ; V_16 < V_69 ; ++ V_16 , ++ V_68 ) {
if ( strcmp ( V_68 -> V_46 , V_32 [ 0 ] ) == 0 )
break;
}
if ( V_16 == V_69 ) {
F_17 ( L_19 ,
V_32 [ 0 ] ) ;
return V_58 ;
}
for ( V_16 = 0 ; V_16 < V_68 -> V_73 ; ++ V_16 ) {
V_32 = NULL ;
F_17 ( L_20 , V_68 -> V_46 , V_68 -> V_71 [ V_16 ] ) ;
V_84 = F_31 ( V_68 -> V_71 [ V_16 ] ) ;
if ( V_84 )
return V_84 ;
}
return 0 ;
}
static void F_32 ( const char * V_85 )
{
int V_86 ;
char * V_19 = ( char * ) V_85 , * V_87 ;
if ( * V_19 != '|' )
return;
V_19 ++ ;
while ( isspace ( * V_19 ) )
V_19 ++ ;
if ( strncmp ( V_19 , L_21 , 5 ) ) {
F_17 ( L_22 ) ;
return;
}
V_19 += 5 ;
while ( isspace ( * V_19 ) )
V_19 ++ ;
V_87 = strchr ( V_19 , '\n' ) ;
if ( V_87 )
* V_87 = '\0' ;
V_86 = strlen ( V_19 ) ;
if ( V_86 == 0 ) {
F_17 ( L_22 ) ;
return;
}
if ( * V_19 == '"' ) {
V_19 ++ ;
V_87 = strchr ( V_19 , '"' ) ;
if ( ! V_87 ) {
F_17 ( L_23 ) ;
return;
}
* V_87 = '\0' ;
}
V_88 = 0 ;
if ( * V_19 == '^' ) {
V_88 = 1 ;
V_19 ++ ;
}
V_86 = strlen ( V_19 ) ;
V_89 = 0 ;
if ( * ( V_19 + V_86 - 1 ) == '$' ) {
V_89 = 1 ;
* ( V_19 + V_86 - 1 ) = '\0' ;
}
V_86 = strlen ( V_19 ) ;
if ( ! V_86 )
return;
if ( V_86 >= V_90 ) {
F_17 ( L_24 ) ;
return;
}
strcpy ( V_91 , V_19 ) ;
V_92 ++ ;
return;
}
int F_31 ( const char * V_65 )
{
static char * V_32 [ V_93 ] ;
static int V_31 ;
static char V_94 [ V_95 + 2 ] ;
char * V_19 ;
char * V_96 , V_97 ;
T_5 * V_98 ;
int V_16 , V_99 , V_100 = 0 , V_101 = 0 ;
V_19 = ( char * ) V_65 ;
if ( F_33 ( V_102 ) ) {
F_34 ( V_102 ) ;
F_35 ( V_103 ) ;
V_31 = 0 ;
}
if ( * V_19 != '\n' && * V_19 != '\0' ) {
V_31 = 0 ;
V_96 = V_94 ;
while ( * V_19 ) {
while ( isspace ( * V_19 ) )
V_19 ++ ;
if ( ( * V_19 == '\0' ) || ( * V_19 == '\n' ) ||
( * V_19 == '#' && ! V_72 ) )
break;
if ( * V_19 == '|' ) {
V_101 ++ ;
break;
}
if ( V_96 >= V_94 + V_95 ) {
F_17 ( L_25
L_26 ,
V_65 ) ;
return V_104 ;
}
if ( V_31 >= V_93 - 1 ) {
F_17 ( L_27
L_28 , V_65 ) ;
return V_104 ;
}
V_32 [ V_31 ++ ] = V_96 ;
V_99 = 0 ;
V_97 = '\0' ;
while ( * V_19 && * V_19 != '\n' &&
( V_99 || V_97 || ! isspace ( * V_19 ) ) ) {
if ( V_96 >= V_94 + V_95 )
break;
if ( V_99 ) {
V_99 = 0 ;
* V_96 ++ = * V_19 ++ ;
continue;
}
if ( * V_19 == '\\' ) {
V_99 = 1 ;
++ V_19 ;
continue;
}
if ( * V_19 == V_97 )
V_97 = '\0' ;
else if ( * V_19 == '\'' || * V_19 == '"' )
V_97 = * V_19 ;
* V_96 = * V_19 ++ ;
if ( * V_96 == '=' && ! V_97 )
break;
++ V_96 ;
}
* V_96 ++ = '\0' ;
}
}
if ( ! V_31 )
return 0 ;
if ( V_101 )
F_32 ( V_19 ) ;
if ( V_72 ) {
int V_105 = F_23 ( V_65 , V_32 [ 0 ] ) ;
if ( ! V_72 ) {
V_31 = 0 ;
* ( V_32 [ 0 ] ) = '\0' ;
}
return V_105 ;
}
if ( V_32 [ 0 ] [ 0 ] == '-' && V_32 [ 0 ] [ 1 ] &&
( V_32 [ 0 ] [ 1 ] < '0' || V_32 [ 0 ] [ 1 ] > '9' ) ) {
V_100 = 1 ;
++ V_32 [ 0 ] ;
}
F_36 (tp, i) {
if ( V_98 -> V_106 ) {
if ( V_98 -> V_107
&& ( strlen ( V_32 [ 0 ] ) <= V_98 -> V_107 ) ) {
if ( strncmp ( V_32 [ 0 ] ,
V_98 -> V_106 ,
V_98 -> V_107 ) == 0 ) {
break;
}
}
if ( strcmp ( V_32 [ 0 ] , V_98 -> V_106 ) == 0 )
break;
}
}
if ( V_16 == V_108 ) {
F_36 (tp, i) {
if ( V_98 -> V_106 ) {
if ( strncmp ( V_32 [ 0 ] ,
V_98 -> V_106 ,
strlen ( V_98 -> V_106 ) ) == 0 ) {
break;
}
}
}
}
if ( V_16 < V_108 ) {
int V_105 ;
if ( ! F_6 ( V_98 -> V_109 , V_56 , V_31 <= 1 ) )
return V_57 ;
F_35 ( V_110 ) ;
V_105 = (* V_98 -> V_111 )( V_31 - 1 , ( const char * * ) V_32 ) ;
if ( V_105 && V_100 && V_105 > V_112 )
V_105 = 0 ;
F_37 ( V_110 ) ;
if ( V_98 -> V_109 & V_113 )
return V_105 ;
V_31 = V_98 -> V_109 & V_114 ? 1 : 0 ;
if ( V_32 [ V_31 ] )
* ( V_32 [ V_31 ] ) = '\0' ;
return V_105 ;
}
{
unsigned long V_23 ;
char * V_46 = NULL ;
long V_45 ;
int V_44 = 0 ;
if ( F_19 ( 0 , ( const char * * ) V_32 , & V_44 ,
& V_23 , & V_45 , & V_46 ) ) {
return V_104 ;
}
F_17 ( L_29 , V_32 [ 0 ] ) ;
F_38 ( V_23 , NULL , V_115 ) ;
F_17 ( L_30 ) ;
return 0 ;
}
}
static int F_39 ( char * V_116 )
{
#define F_40 16
#define F_41 14
if ( V_117 == V_118 )
return 0 ;
switch ( * V_116 ) {
case F_40 :
if ( V_119 != V_118 )
V_119 = ( V_119 - 1 ) % V_120 ;
strncpy ( V_121 , V_122 [ V_119 ] , V_95 ) ;
return 1 ;
case F_41 :
if ( V_119 != V_117 )
V_119 = ( V_119 + 1 ) % V_120 ;
strncpy ( V_121 , V_122 [ V_119 ] , V_95 ) ;
return 1 ;
}
return 0 ;
}
static int F_42 ( int V_31 , const char * * V_32 )
{
F_43 () ;
F_17 ( L_31 ) ;
while ( 1 )
F_44 () ;
return 0 ;
}
static void F_45 ( struct V_123 * V_124 )
{
int V_125 = V_126 ;
V_126 = V_127 ;
V_128 ++ ;
F_46 ( V_124 ) ;
V_128 -- ;
F_17 ( L_30 ) ;
V_126 = V_125 ;
}
void F_47 ( struct V_1 * V_3 )
{
V_129 = V_3 ;
if ( F_48 ( V_3 ) ) {
V_42 = F_49 ( F_50 ( V_3 ) ) ;
return;
}
V_42 = NULL ;
}
static int F_51 ( T_6 V_130 , int error , struct V_123 * V_124 ,
T_7 V_131 )
{
char * V_132 ;
int V_27 ;
struct V_1 * V_133 =
F_1 ( F_52 () ) ;
F_53 ( L_32 , V_130 ) ;
V_134 = 0 ;
if ( V_130 == V_135 ) {
} else {
F_17 ( L_33 ,
V_133 , V_133 ? V_133 -> V_136 : 0 ) ;
#if F_54 ( V_137 )
F_17 ( L_34 , F_52 () ) ;
#endif
}
switch ( V_130 ) {
case V_135 :
{
switch ( V_131 ) {
case V_138 :
F_17 ( L_35 ,
V_133 , V_133 -> V_136 ) ;
#if F_54 ( V_137 )
F_17 ( L_34 , F_52 () ) ;
#endif
F_17 ( L_36 V_139 L_30 ,
F_55 ( V_124 ) ) ;
break;
case V_140 :
break;
case V_141 :
F_53 ( L_37 , V_130 ) ;
return 1 ;
default:
F_17 ( L_38 ,
V_131 ) ;
break;
}
}
break;
case V_142 :
if ( F_56 ( V_143 ) )
F_17 ( L_39 ) ;
else
F_17 ( L_40 ) ;
break;
case V_144 :
F_35 ( V_143 ) ;
F_17 ( L_39 ) ;
break;
case V_145 :
case V_146 :
F_17 ( L_41 ) ;
break;
case V_147 :
F_17 ( L_42 , V_148 ) ;
F_17 ( L_43 V_139 L_30 ,
F_55 ( V_124 ) ) ;
F_45 ( V_124 ) ;
break;
case V_149 :
F_17 ( L_44 ) ;
break;
case V_150 :
F_17 ( L_45
V_139 L_30 ,
F_55 ( V_124 ) ) ;
break;
case V_151 :
case V_152 :
F_17 ( L_46 V_139 L_30 ,
V_130 == V_152 ?
L_47 : L_48 , F_55 ( V_124 ) ) ;
if ( V_131 != V_138 ) {
F_17 ( L_49 ,
V_131 ) ;
F_53 ( L_50 , V_130 ) ;
return 0 ;
}
break;
case V_153 :
F_17 ( L_51 V_139 L_30 ,
F_55 ( V_124 ) ) ;
break;
default:
F_17 ( L_52 , V_130 ) ;
F_53 ( L_53 , V_130 ) ;
return 0 ;
}
while ( 1 ) {
V_154 = 1 ;
F_37 ( V_155 ) ;
V_92 = 0 ;
V_91 [ 0 ] = '\0' ;
V_132 = V_121 ;
* V_132 = '\0' ;
* ( V_122 [ V_117 ] ) = '\0' ;
V_156:
#if F_54 ( V_137 )
snprintf ( V_157 , V_95 , F_7 ( L_54 ) ,
F_52 () ) ;
#else
snprintf ( V_157 , V_95 , F_7 ( L_54 ) ) ;
#endif
if ( V_72 )
strncat ( V_157 , L_55 , V_95 ) ;
V_132 = F_57 ( V_132 , V_95 , V_157 ) ;
if ( * V_132 != '\n' ) {
if ( * V_132 < 32 ) {
if ( V_119 == V_117 ) {
strncpy ( V_122 [ V_117 ] , V_121 ,
V_95 ) ;
* ( V_122 [ V_117 ] +
strlen ( V_122 [ V_117 ] ) - 1 ) = '\0' ;
}
if ( ! F_39 ( V_132 ) )
* ( V_121 + strlen ( V_121 ) - 1 ) = '\0' ;
V_132 = V_121 ;
goto V_156;
} else {
strncpy ( V_122 [ V_117 ] , V_121 ,
V_95 ) ;
}
V_117 = ( V_117 + 1 ) % V_120 ;
if ( V_117 == V_118 )
V_118 = ( V_118 + 1 ) % V_120 ;
}
V_119 = V_117 ;
V_27 = F_31 ( V_132 ) ;
if ( V_27 == V_104 ) {
F_17 ( L_56 , V_132 ) ;
V_27 = 0 ;
}
if ( V_27 == V_112
|| V_27 == V_158
|| V_27 == V_159
|| V_27 == V_160 )
break;
if ( V_27 )
F_22 ( V_27 ) ;
}
F_53 ( L_57 , V_27 ) ;
return V_27 ;
}
void F_58 ( const char * V_161 , int V_23 )
{
F_17 ( L_58 ,
V_161 , F_52 () , V_23 , V_162 ,
V_163 ) ;
}
int F_59 ( T_6 V_130 , T_6 V_164 , int error ,
T_7 V_131 , struct V_123 * V_124 )
{
int V_105 = 1 ;
while ( 1 ) {
F_53 ( L_59 , V_130 ) ;
while ( F_56 ( V_165 ) ) {
if ( ! F_56 ( V_166 ) )
F_35 ( V_166 ) ;
}
F_37 ( V_155 ) ;
F_53 ( L_60 , V_130 ) ;
if ( F_56 ( V_167 ) )
break;
V_105 = F_51 ( V_164 , error , V_124 , V_131 ) ;
F_53 ( L_61 , V_105 ) ;
if ( V_105 == V_158 )
break;
if ( V_105 == V_159 ) {
F_35 ( V_168 ) ;
break;
}
if ( V_105 == V_160 ) {
if ( ! F_56 ( V_169 ) )
F_17 ( L_62
L_63 ) ;
break;
}
if ( V_105 && V_105 != 1 && V_105 != V_112 )
F_17 ( L_64 ,
V_105 ) ;
F_53 ( L_65 , V_130 ) ;
break;
}
if ( F_56 ( V_168 ) )
F_37 ( V_170 ) ;
F_60 () ;
return V_105 ;
}
static int F_61 ( unsigned long V_47 , unsigned int V_73 )
{
unsigned char V_171 ;
while ( V_73 -- ) {
if ( F_62 ( V_171 , V_47 ) )
return 0 ;
F_17 ( L_66 , V_171 ) ;
V_47 ++ ;
}
F_17 ( L_30 ) ;
return 0 ;
}
static void F_63 ( const char * V_172 , unsigned long V_47 ,
int V_173 , int V_174 , int V_175 ,
int V_176 , int V_177 , int V_178 )
{
T_4 V_53 ;
char V_94 [ 32 ] ;
char * V_171 = V_94 ;
int V_16 ;
unsigned long V_179 ;
memset ( V_94 , '\0' , sizeof( V_94 ) ) ;
if ( V_178 )
F_17 ( L_67 V_180 L_68 , V_47 ) ;
else
F_17 ( V_180 L_68 , V_47 ) ;
for ( V_16 = 0 ; V_16 < V_176 && V_177 -- ; V_16 ++ ) {
if ( V_178 ) {
if ( F_64 ( & V_179 , V_47 , V_175 ) )
break;
} else if ( F_65 ( & V_179 , V_47 , V_175 ) )
break;
F_17 ( V_172 , V_179 ) ;
if ( V_173 )
F_21 ( V_179 , & V_53 ) ;
else
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
if ( V_53 . V_181 ) {
F_38 ( V_179 , & V_53 , 0 ) ;
if ( ! V_174 ) {
F_17 ( L_30 ) ;
F_17 ( L_69
V_139 L_68
V_139 L_68
V_139 , V_53 . V_182 ,
V_53 . V_183 , V_53 . V_184 ,
V_53 . V_59 , V_53 . V_185 ) ;
}
V_47 += V_175 ;
} else {
union {
T_3 V_179 ;
unsigned char V_171 [ 8 ] ;
} V_186 ;
unsigned char * V_19 ;
#ifdef F_66
V_19 = V_186 . V_171 + 8 - V_175 ;
#else
V_19 = V_186 . V_171 ;
#endif
V_186 . V_179 = V_179 ;
#define F_67 ( V_171 ) \
({unsigned char __c = c; isascii(__c) && isprint(__c) ? __c : '.'; })
switch ( V_175 ) {
case 8 :
* V_171 ++ = F_67 ( * V_19 ++ ) ;
* V_171 ++ = F_67 ( * V_19 ++ ) ;
* V_171 ++ = F_67 ( * V_19 ++ ) ;
* V_171 ++ = F_67 ( * V_19 ++ ) ;
V_47 += 4 ;
case 4 :
* V_171 ++ = F_67 ( * V_19 ++ ) ;
* V_171 ++ = F_67 ( * V_19 ++ ) ;
V_47 += 2 ;
case 2 :
* V_171 ++ = F_67 ( * V_19 ++ ) ;
V_47 ++ ;
case 1 :
* V_171 ++ = F_67 ( * V_19 ++ ) ;
V_47 ++ ;
break;
}
#undef F_67
}
}
F_17 ( L_70 , ( int ) ( ( V_176 - V_16 ) * ( 2 * V_175 + 1 ) + 1 ) ,
L_68 , V_94 ) ;
}
static int F_68 ( int V_31 , const char * * V_32 )
{
static unsigned long V_187 ;
static int V_188 , V_189 , V_190 ;
int V_191 = 16 , V_192 = 8 , V_175 = V_193 , V_177 ;
int V_174 = 0 ;
char V_194 , V_172 [ 64 ] ;
unsigned long V_47 ;
unsigned long V_179 ;
long V_45 = 0 ;
int V_173 = 0 ;
int V_195 = 0 ;
int V_178 = 0 ;
F_12 ( L_71 , & V_192 ) ;
F_12 ( L_72 , & V_191 ) ;
F_12 ( L_73 , & V_175 ) ;
V_177 = V_192 * 16 / V_175 ;
if ( strcmp ( V_32 [ 0 ] , L_74 ) == 0 ) {
if ( V_31 != 2 )
return V_35 ;
V_195 = 1 ;
} else if ( isdigit ( V_32 [ 0 ] [ 2 ] ) ) {
V_175 = ( int ) ( V_32 [ 0 ] [ 2 ] - '0' ) ;
if ( V_175 == 0 ) {
V_175 = V_189 ;
if ( V_175 == 0 )
V_175 = 4 ;
}
V_189 = V_175 ;
V_177 = V_192 * 16 / V_175 ;
if ( ! V_32 [ 0 ] [ 3 ] )
V_195 = 1 ;
else if ( V_32 [ 0 ] [ 3 ] == 'c' && V_32 [ 0 ] [ 4 ] ) {
char * V_3 ;
V_177 = F_11 ( V_32 [ 0 ] + 4 , & V_3 , 10 ) ;
V_192 = ( ( V_177 * V_175 ) + 15 ) / 16 ;
V_195 = ! * V_3 ;
}
V_190 = V_177 ;
} else if ( strcmp ( V_32 [ 0 ] , L_75 ) == 0 )
V_195 = 1 ;
else if ( strcmp ( V_32 [ 0 ] , L_76 ) == 0 )
V_195 = 1 ;
else if ( strcmp ( V_32 [ 0 ] , L_77 ) == 0 ) {
V_178 = V_195 = 1 ;
}
if ( ! V_195 )
return V_104 ;
if ( V_31 == 0 ) {
if ( V_187 == 0 )
return V_35 ;
V_47 = V_187 ;
V_191 = V_188 ;
V_175 = V_189 ;
V_177 = V_190 ;
V_192 = ( ( V_177 * V_175 ) + 15 ) / 16 ;
}
if ( V_31 ) {
unsigned long V_26 ;
int V_27 , V_44 = 1 ;
V_27 = F_19 ( V_31 , V_32 , & V_44 , & V_47 ,
& V_45 , NULL ) ;
if ( V_27 )
return V_27 ;
if ( V_31 > V_44 + 2 )
return V_35 ;
if ( V_31 >= V_44 ) {
V_27 = F_13 ( V_32 [ V_44 ] , & V_26 ) ;
if ( ! V_27 ) {
V_192 = ( int ) V_26 ;
V_177 = V_192 * 16 / V_175 ;
}
}
if ( V_31 >= V_44 + 1 ) {
V_27 = F_13 ( V_32 [ V_44 + 1 ] , & V_26 ) ;
if ( ! V_27 )
V_191 = ( int ) V_26 ;
}
}
if ( strcmp ( V_32 [ 0 ] , L_74 ) == 0 )
return F_61 ( V_47 , V_192 ) ;
switch ( V_191 ) {
case 10 :
V_194 = 'd' ;
break;
case 16 :
V_194 = 'x' ;
break;
case 8 :
V_194 = 'o' ;
break;
default:
return V_196 ;
}
V_188 = V_191 ;
if ( V_175 > V_193 )
return V_197 ;
switch ( V_175 ) {
case 8 :
sprintf ( V_172 , L_78 , V_194 ) ;
break;
case 4 :
sprintf ( V_172 , L_79 , V_194 ) ;
break;
case 2 :
sprintf ( V_172 , L_80 , V_194 ) ;
break;
case 1 :
sprintf ( V_172 , L_81 , V_194 ) ;
break;
default:
return V_197 ;
}
V_190 = V_177 ;
V_189 = V_175 ;
if ( strcmp ( V_32 [ 0 ] , L_76 ) == 0 ) {
V_173 = 1 ;
V_175 = V_193 ;
V_177 = V_192 ;
F_12 ( L_82 , & V_174 ) ;
}
V_47 &= ~ ( V_175 - 1 ) ;
while ( V_177 > 0 ) {
unsigned long V_198 ;
int V_199 , V_200 , V_176 = ( V_173 ? 1 : ( 16 / V_175 ) ) ;
if ( F_33 ( V_102 ) )
return 0 ;
for ( V_198 = V_47 , V_200 = 0 ; V_200 < V_177 ; V_198 += V_175 , ++ V_200 ) {
if ( V_178 ) {
if ( F_64 ( & V_179 , V_198 , V_175 )
|| V_179 )
break;
} else if ( F_65 ( & V_179 , V_198 , V_175 ) || V_179 )
break;
}
V_199 = F_69 ( V_176 , V_177 ) ;
F_63 ( V_172 , V_47 , V_173 , V_174 , V_175 ,
V_176 , V_177 , V_178 ) ;
V_47 += V_175 * V_199 ;
V_177 -= V_199 ;
V_200 = ( V_200 + V_176 - 1 ) / V_176 ;
if ( V_200 > 2 ) {
int V_68 = V_176 * ( V_200 - 2 ) ;
F_17 ( V_180 L_83 V_180
L_84 ,
V_47 , V_47 + V_175 * V_68 - 1 ) ;
V_47 += V_175 * V_68 ;
V_177 -= V_68 ;
}
}
V_187 = V_47 ;
return 0 ;
}
static int F_70 ( int V_31 , const char * * V_32 )
{
int V_27 ;
unsigned long V_47 ;
long V_45 = 0 ;
unsigned long V_201 ;
int V_44 ;
int V_202 ;
if ( V_32 [ 0 ] [ 2 ] && ! isdigit ( V_32 [ 0 ] [ 2 ] ) )
return V_104 ;
if ( V_31 < 2 )
return V_35 ;
V_44 = 1 ;
V_27 = F_19 ( V_31 , V_32 , & V_44 , & V_47 , & V_45 , NULL ) ;
if ( V_27 )
return V_27 ;
if ( V_44 > V_31 )
return V_35 ;
V_27 = F_19 ( V_31 , V_32 , & V_44 , & V_201 , NULL , NULL ) ;
if ( V_27 )
return V_27 ;
if ( V_44 != V_31 + 1 )
return V_35 ;
V_202 = V_32 [ 0 ] [ 2 ] ? ( V_32 [ 0 ] [ 2 ] - '0' ) : ( V_193 ) ;
V_27 = F_71 ( V_47 , V_201 , V_202 ) ;
if ( V_27 )
return V_27 ;
F_17 ( V_139 L_85 V_139 L_30 , V_47 , V_201 ) ;
return 0 ;
}
static int F_72 ( int V_31 , const char * * V_32 )
{
unsigned long V_47 ;
int V_27 ;
int V_44 ;
long V_45 ;
if ( F_52 () != V_162 ) {
F_17 ( L_86
L_87 ,
V_162 ) ;
return V_203 ;
}
if ( V_31 == 1 ) {
V_44 = 1 ;
V_27 = F_19 ( V_31 , V_32 , & V_44 ,
& V_47 , & V_45 , NULL ) ;
if ( V_27 )
return V_27 ;
} else if ( V_31 ) {
return V_35 ;
}
V_27 = V_112 ;
if ( F_33 ( V_204 ) ) {
F_17 ( L_88 ) ;
F_17 ( L_89 ,
V_205 ) ;
if ( V_205 == 0 && V_134 ++ == 0 ) {
F_17 ( L_90
L_91 ) ;
return 0 ;
}
if ( V_205 == 2 ) {
F_17 ( L_92 ) ;
F_42 ( 0 , NULL ) ;
}
F_17 ( L_93 ) ;
}
return V_27 ;
}
static int F_73 ( int V_31 , const char * * V_32 )
{
int V_86 = F_18 () ;
#if V_206 > 0
int V_16 ;
char * V_207 ;
int V_208 ;
T_3 V_209 ;
T_8 V_210 ;
T_9 V_211 ;
T_10 V_212 ;
if ( V_86 )
return V_86 ;
for ( V_16 = 0 ; V_16 < V_206 ; V_16 ++ ) {
V_208 = V_213 [ V_16 ] . V_214 * 2 ;
if ( V_208 > 16 )
V_208 = 2 ;
if ( V_86 + strlen ( V_213 [ V_16 ] . V_46 ) + 4 + V_208 > 80 ) {
V_86 = 0 ;
F_17 ( L_30 ) ;
}
if ( V_86 )
V_86 += F_17 ( L_94 ) ;
switch( V_213 [ V_16 ] . V_214 * 8 ) {
case 8 :
V_207 = F_74 ( V_16 , & V_212 , V_42 ) ;
if ( ! V_207 )
break;
V_86 += F_17 ( L_95 , V_207 , V_212 ) ;
break;
case 16 :
V_207 = F_74 ( V_16 , & V_211 , V_42 ) ;
if ( ! V_207 )
break;
V_86 += F_17 ( L_96 , V_207 , V_211 ) ;
break;
case 32 :
V_207 = F_74 ( V_16 , & V_210 , V_42 ) ;
if ( ! V_207 )
break;
V_86 += F_17 ( L_97 , V_207 , V_210 ) ;
break;
case 64 :
V_207 = F_74 ( V_16 , & V_209 , V_42 ) ;
if ( ! V_207 )
break;
V_86 += F_17 ( L_98 , V_207 , V_209 ) ;
break;
default:
V_86 += F_17 ( L_99 , V_213 [ V_16 ] . V_46 ) ;
}
}
F_17 ( L_30 ) ;
#else
if ( V_86 )
return V_86 ;
F_45 ( V_42 ) ;
#endif
return 0 ;
}
static int F_75 ( int V_31 , const char * * V_32 )
{
#if V_206 > 0
int V_27 ;
const char * V_207 ;
int V_16 ;
T_3 V_209 ;
T_8 V_210 ;
T_9 V_211 ;
T_10 V_212 ;
if ( V_31 != 2 )
return V_35 ;
V_207 = V_32 [ 1 ] ;
if ( * V_207 == '%' )
V_207 ++ ;
V_27 = F_14 ( V_32 [ 2 ] , & V_209 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_18 () ;
if ( V_27 )
return V_27 ;
V_27 = V_43 ;
for ( V_16 = 0 ; V_16 < V_206 ; V_16 ++ ) {
if ( strcmp ( V_207 , V_213 [ V_16 ] . V_46 ) == 0 ) {
V_27 = 0 ;
break;
}
}
if ( ! V_27 ) {
switch( V_213 [ V_16 ] . V_214 * 8 ) {
case 8 :
V_212 = V_209 ;
F_76 ( V_16 , & V_212 , V_42 ) ;
break;
case 16 :
V_211 = V_209 ;
F_76 ( V_16 , & V_211 , V_42 ) ;
break;
case 32 :
V_210 = V_209 ;
F_76 ( V_16 , & V_210 , V_42 ) ;
break;
case 64 :
F_76 ( V_16 , & V_209 , V_42 ) ;
break;
}
}
return V_27 ;
#else
F_17 ( L_100 ) ;
return 0 ;
#endif
}
static int F_77 ( int V_31 , const char * * V_32 )
{
bool V_215 =
! F_6 ( V_11 , V_56 , false ) ;
if ( V_31 != 1 )
return V_35 ;
V_128 ++ ;
F_78 ( * V_32 [ 1 ] , V_215 ) ;
V_128 -- ;
return 0 ;
}
static int F_79 ( int V_31 , const char * * V_32 )
{
int V_27 ;
unsigned long V_47 ;
long V_45 ;
int V_44 ;
if ( V_31 != 1 )
return V_35 ;
V_44 = 1 ;
V_27 = F_19 ( V_31 , V_32 , & V_44 , & V_47 , & V_45 , NULL ) ;
if ( V_27 )
return V_27 ;
F_46 ( (struct V_123 * ) V_47 ) ;
return 0 ;
}
static int F_80 ( int V_31 , const char * * V_32 )
{
struct V_216 * V_217 ;
if ( V_31 != 0 )
return V_35 ;
F_17 ( L_101 ) ;
F_81 (mod, kdb_modules, list) {
if ( V_217 -> V_218 == V_219 )
continue;
F_17 ( L_102 , V_217 -> V_46 ,
V_217 -> V_220 . V_214 , ( void * ) V_217 ) ;
#ifdef F_82
F_17 ( L_103 , F_83 ( V_217 ) ) ;
#endif
if ( V_217 -> V_218 == V_221 )
F_17 ( L_104 ) ;
else if ( V_217 -> V_218 == V_222 )
F_17 ( L_105 ) ;
else
F_17 ( L_106 ) ;
F_17 ( L_107 , V_217 -> V_220 . V_223 ) ;
#ifdef F_82
{
struct V_224 * V_225 ;
F_17 ( L_108 ) ;
F_81 (use, &mod->source_list,
source_list)
F_17 ( L_109 , V_225 -> V_226 -> V_46 ) ;
F_17 ( L_110 ) ;
}
#endif
}
return 0 ;
}
static int F_84 ( int V_31 , const char * * V_32 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
if ( V_14 [ V_16 ] )
F_17 ( L_111 , V_14 [ V_16 ] ) ;
}
if ( F_85 ( V_227 ) )
F_17 ( L_112 , V_38 ) ;
return 0 ;
}
static int F_86 ( int V_31 , const char * * V_32 )
{
int V_27 ;
int V_228 ;
int V_229 = 0 ;
int V_230 = 0 ;
int V_199 = 0 ;
int V_231 = 0 ;
struct V_232 V_233 = { . V_234 = 1 } ;
T_2 V_86 ;
char V_235 [ 201 ] ;
if ( V_31 > 2 )
return V_35 ;
if ( V_31 ) {
char * V_19 ;
V_229 = F_87 ( V_32 [ 1 ] , & V_19 , 0 ) ;
if ( * V_19 )
V_229 = 0 ;
if ( V_31 > 1 ) {
V_230 = F_11 ( V_32 [ 2 ] , & V_19 , 0 ) ;
if ( * V_19 || V_230 < 0 )
V_230 = 0 ;
}
}
V_27 = F_12 ( L_113 , & V_228 ) ;
if ( ! V_27 && V_228 ) {
const char * V_236 [] = { L_114 , L_113 , L_115 } ;
F_16 ( 2 , V_236 ) ;
}
F_88 ( & V_233 ) ;
while ( F_89 ( & V_233 , 1 , NULL , 0 , NULL ) )
V_199 ++ ;
if ( V_229 < 0 ) {
if ( V_230 >= V_199 )
F_17 ( L_116
L_117 , V_199 ) ;
else if ( V_230 - V_229 >= V_199 )
F_17 ( L_118
L_119 , V_199 , V_199 - V_230 ) ;
V_231 = V_230 ;
V_229 = abs ( V_229 ) ;
} else if ( V_229 > 0 ) {
V_231 = V_199 - V_229 - V_230 ;
V_229 = abs ( V_229 ) ;
if ( V_230 >= V_199 ) {
F_17 ( L_120
L_121 , V_199 ) ;
V_231 = V_199 ;
} else if ( V_231 < 0 ) {
V_229 += V_231 ;
V_231 = 0 ;
F_17 ( L_122
L_123 , V_199 , V_229 ) ;
}
} else {
V_229 = V_199 ;
}
if ( V_231 >= V_199 || V_231 < 0 )
return 0 ;
F_88 ( & V_233 ) ;
while ( F_89 ( & V_233 , 1 , V_235 , sizeof( V_235 ) , & V_86 ) ) {
if ( V_231 ) {
V_231 -- ;
continue;
}
if ( ! V_229 -- )
break;
if ( F_33 ( V_102 ) )
return 0 ;
F_17 ( L_124 , ( int ) V_86 - 1 , V_235 ) ;
}
return 0 ;
}
static int F_90 ( int V_31 , const char * V_32 [] )
{
if ( F_91 ( & V_237 ) )
return 0 ;
F_92 ( & V_237 , 1 ) ;
V_238 . V_239 ( 0 ) ;
return 0 ;
}
static int F_93 ( const char * V_26 , const struct V_240 * V_241 )
{
if ( ! F_94 ( & V_237 , - 1 , 0 ) )
return - V_242 ;
V_238 . V_239 ( 1 ) ;
return 0 ;
}
static void F_95 ( void )
{
int V_16 , V_243 , V_244 = 1 ;
char V_218 , V_245 = '?' ;
F_17 ( L_125 , F_52 () ) ;
F_17 ( L_126 ) ;
for ( V_243 = - 1 , V_16 = 0 ; V_16 < V_246 ; V_16 ++ ) {
if ( ! F_96 ( V_16 ) ) {
V_218 = 'F' ;
} else if ( ! V_247 [ V_16 ] . V_248 ) {
V_218 = 'D' ;
} else {
V_218 = ' ' ;
if ( F_97 ( F_5 ( V_16 ) ) == 'I' )
V_218 = 'I' ;
}
if ( V_218 != V_245 ) {
if ( V_245 != '?' ) {
if ( ! V_244 )
F_17 ( L_127 ) ;
V_244 = 0 ;
F_17 ( L_128 , V_243 ) ;
if ( V_243 < V_16 - 1 )
F_17 ( L_129 , V_16 - 1 ) ;
if ( V_245 != ' ' )
F_17 ( L_130 , V_245 ) ;
}
V_245 = V_218 ;
V_243 = V_16 ;
}
}
if ( V_245 != 'F' ) {
if ( ! V_244 )
F_17 ( L_127 ) ;
F_17 ( L_128 , V_243 ) ;
if ( V_243 < V_16 - 1 )
F_17 ( L_129 , V_16 - 1 ) ;
if ( V_245 != ' ' )
F_17 ( L_130 , V_245 ) ;
}
F_17 ( L_30 ) ;
}
static int F_98 ( int V_31 , const char * * V_32 )
{
unsigned long V_249 ;
int V_27 ;
if ( V_31 == 0 ) {
F_95 () ;
return 0 ;
}
if ( V_31 != 1 )
return V_35 ;
V_27 = F_13 ( V_32 [ 1 ] , & V_249 ) ;
if ( V_27 )
return V_27 ;
if ( ( V_249 >= V_250 ) || ! V_247 [ V_249 ] . V_248 )
return V_203 ;
V_251 = V_249 ;
return V_158 ;
}
void F_99 ( void )
{
int V_252 = 0 , V_253 = 0 ;
unsigned long V_254 = F_100 ( L_131 ) ,
V_255 = F_100 ( L_132 ) ;
unsigned long V_2 ;
const struct V_1 * V_3 , * V_256 ;
F_101 (cpu) {
V_3 = F_1 ( V_2 ) ;
if ( F_102 ( V_3 , V_254 ) )
++ V_252 ;
}
F_103 (g, p) {
if ( F_102 ( V_3 , V_255 ) )
++ V_253 ;
} F_104 ( V_256 , V_3 ) ;
if ( V_252 || V_253 ) {
if ( V_252 )
F_17 ( L_133 ,
V_252 , V_252 == 1 ? L_1 : L_134 ,
V_253 ? L_135 : L_1 ) ;
if ( V_253 )
F_17 ( L_136
L_137 , V_253 ,
V_253 == 1 ? L_1 : L_134 ) ;
F_17 ( L_138 ) ;
}
}
void F_105 ( const struct V_1 * V_3 )
{
int V_2 ;
unsigned long V_257 ;
if ( ! V_3 || F_106 ( & V_257 , ( char * ) V_3 , sizeof( unsigned long ) ) )
return;
V_2 = F_50 ( V_3 ) ;
F_17 ( L_139 ,
( void * ) V_3 , V_3 -> V_136 , V_3 -> V_258 -> V_136 ,
F_48 ( V_3 ) , F_50 ( V_3 ) ,
F_97 ( V_3 ) ,
( void * ) ( & V_3 -> V_259 ) ,
V_3 == F_1 ( F_52 () ) ? '*' : ' ' ,
V_3 -> V_260 ) ;
if ( F_48 ( V_3 ) ) {
if ( ! F_5 ( V_2 ) ) {
F_17 ( L_140 ) ;
} else {
if ( F_5 ( V_2 ) != V_3 )
F_17 ( L_141
L_142 , F_5 ( V_2 ) ) ;
}
}
}
static int F_107 ( int V_31 , const char * * V_32 )
{
struct V_1 * V_256 , * V_3 ;
unsigned long V_261 , V_2 ;
if ( V_31 == 0 )
F_99 () ;
F_17 ( L_143 ,
( int ) ( 2 * sizeof( void * ) ) + 2 , L_144 ,
( int ) ( 2 * sizeof( void * ) ) + 2 , L_145 ) ;
V_261 = F_100 ( V_31 ? V_32 [ 1 ] : NULL ) ;
F_101 (cpu) {
if ( F_33 ( V_102 ) )
return 0 ;
V_3 = F_1 ( V_2 ) ;
if ( F_102 ( V_3 , V_261 ) )
F_105 ( V_3 ) ;
}
F_17 ( L_30 ) ;
F_103 (g, p) {
if ( F_33 ( V_102 ) )
return 0 ;
if ( F_102 ( V_3 , V_261 ) )
F_105 ( V_3 ) ;
} F_104 ( V_256 , V_3 ) ;
return 0 ;
}
static int F_108 ( int V_31 , const char * * V_32 )
{
struct V_1 * V_3 ;
unsigned long V_26 ;
int V_27 ;
if ( V_31 > 1 )
return V_35 ;
if ( V_31 ) {
if ( strcmp ( V_32 [ 1 ] , L_146 ) == 0 ) {
V_3 = F_5 ( V_162 ) ;
} else {
V_27 = F_13 ( V_32 [ 1 ] , & V_26 ) ;
if ( V_27 )
return V_30 ;
V_3 = F_109 ( ( V_262 ) V_26 , & V_263 ) ;
if ( ! V_3 ) {
F_17 ( L_147 , ( V_262 ) V_26 ) ;
return 0 ;
}
}
F_47 ( V_3 ) ;
}
F_17 ( L_148 ,
V_129 -> V_260 ,
V_129 -> V_136 ) ;
return 0 ;
}
static int F_110 ( int V_31 , const char * * V_32 )
{
return V_160 ;
}
static int F_111 ( int V_31 , const char * * V_32 )
{
T_5 * V_264 ;
int V_16 ;
F_17 ( L_149 , L_150 , L_151 , L_152 ) ;
F_17 ( L_153
L_154 ) ;
F_36 (kt, i) {
char * V_265 = L_1 ;
if ( F_33 ( V_102 ) )
return 0 ;
if ( ! V_264 -> V_106 )
continue;
if ( ! F_6 ( V_264 -> V_109 , V_56 , true ) )
continue;
if ( strlen ( V_264 -> V_266 ) > 20 )
V_265 = L_155 ;
F_17 ( L_156 , V_264 -> V_106 ,
V_264 -> V_266 , V_265 , V_264 -> V_267 ) ;
}
return 0 ;
}
static int F_112 ( int V_31 , const char * * V_32 )
{
long V_268 , V_136 ;
char * V_29 ;
struct V_1 * V_3 ;
struct V_269 V_270 ;
if ( V_31 != 2 )
return V_35 ;
V_268 = F_87 ( V_32 [ 1 ] , & V_29 , 0 ) ;
if ( * V_29 )
return V_30 ;
if ( V_268 >= 0 ) {
F_17 ( L_157 ) ;
return 0 ;
}
V_268 = - V_268 ;
V_136 = F_87 ( V_32 [ 2 ] , & V_29 , 0 ) ;
if ( * V_29 )
return V_30 ;
if ( V_136 <= 0 ) {
F_17 ( L_158 ) ;
return 0 ;
}
V_3 = F_109 ( V_136 , & V_263 ) ;
if ( ! V_3 ) {
F_17 ( L_159 ) ;
return 0 ;
}
V_3 = V_3 -> V_271 ;
V_270 . V_272 = V_268 ;
V_270 . V_273 = 0 ;
V_270 . V_274 = V_275 ;
V_270 . V_276 = V_136 ;
V_270 . V_277 = 0 ;
F_113 ( V_3 , & V_270 ) ;
return 0 ;
}
static void F_114 ( struct V_278 * V_279 , struct V_280 * V_281 )
{
static int V_282 [] = { 31 , 29 , 31 , 30 , 31 , 30 , 31 ,
31 , 30 , 31 , 30 , 31 } ;
memset ( V_281 , 0 , sizeof( * V_281 ) ) ;
V_281 -> V_283 = V_279 -> V_284 % ( 24 * 60 * 60 ) ;
V_281 -> V_285 = V_279 -> V_284 / ( 24 * 60 * 60 ) +
( 2 * 365 + 1 ) ;
V_281 -> V_286 = V_281 -> V_283 / 60 % 60 ;
V_281 -> V_287 = V_281 -> V_283 / 60 / 60 ;
V_281 -> V_283 = V_281 -> V_283 % 60 ;
V_281 -> V_288 = 68 + 4 * ( V_281 -> V_285 / ( 4 * 365 + 1 ) ) ;
V_281 -> V_285 %= ( 4 * 365 + 1 ) ;
V_282 [ 1 ] = 29 ;
while ( V_281 -> V_285 >= V_282 [ V_281 -> V_289 ] ) {
V_281 -> V_285 -= V_282 [ V_281 -> V_289 ] ;
if ( ++ V_281 -> V_289 == 12 ) {
V_281 -> V_289 = 0 ;
++ V_281 -> V_288 ;
V_282 [ 1 ] = 28 ;
}
}
++ V_281 -> V_285 ;
}
static void F_115 ( struct V_290 * V_26 )
{
struct V_278 V_291 ;
F_116 ( & V_291 ) ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
V_26 -> V_291 = V_291 . V_284 ;
V_26 -> V_292 [ 0 ] = V_293 [ 0 ] ;
V_26 -> V_292 [ 1 ] = V_293 [ 1 ] ;
V_26 -> V_292 [ 2 ] = V_293 [ 2 ] ;
V_26 -> V_294 = V_295 - 1 ;
F_117 ( V_26 ) ;
return;
}
static int F_118 ( int V_31 , const char * * V_32 )
{
struct V_278 V_296 ;
struct V_280 V_281 ;
struct V_290 V_26 ;
if ( V_31 )
return V_35 ;
F_17 ( L_160 , V_297 . V_46 . V_298 ) ;
F_17 ( L_161 , V_297 . V_46 . V_299 ) ;
F_17 ( L_162 , V_297 . V_46 . V_300 ) ;
F_17 ( L_163 , V_297 . V_46 . V_301 ) ;
F_17 ( L_164 , V_297 . V_46 . V_302 ) ;
F_17 ( L_165 , V_297 . V_46 . V_303 ) ;
F_17 ( L_166 , F_119 ( V_304 ) ) ;
V_296 = F_120 () ;
F_114 ( & V_296 , & V_281 ) ;
F_17 ( L_167
L_168 ,
1900 + V_281 . V_288 , V_281 . V_289 + 1 , V_281 . V_285 ,
V_281 . V_287 , V_281 . V_286 , V_281 . V_283 ,
V_305 . V_306 ) ;
F_115 ( & V_26 ) ;
F_17 ( L_169 ) ;
if ( V_26 . V_291 > ( 24 * 60 * 60 ) ) {
int V_307 = V_26 . V_291 / ( 24 * 60 * 60 ) ;
V_26 . V_291 %= ( 24 * 60 * 60 ) ;
F_17 ( L_170 , V_307 , V_307 == 1 ? L_1 : L_171 ) ;
}
F_17 ( L_172 , V_26 . V_291 / ( 60 * 60 ) , ( V_26 . V_291 / 60 ) % 60 ) ;
#define F_121 ( T_11 ) ((x) >> FSHIFT)
#define F_122 ( T_11 ) LOAD_INT(((x) & (FIXED_1-1)) * 100)
F_17 ( L_173 ,
F_121 ( V_26 . V_292 [ 0 ] ) , F_122 ( V_26 . V_292 [ 0 ] ) ,
F_121 ( V_26 . V_292 [ 1 ] ) , F_122 ( V_26 . V_292 [ 1 ] ) ,
F_121 ( V_26 . V_292 [ 2 ] ) , F_122 ( V_26 . V_292 [ 2 ] ) ) ;
#undef F_121
#undef F_122
#define F_123 ( T_11 ) ((x) << (PAGE_SHIFT - 10))
F_17 ( L_174
L_175 ,
F_123 ( V_26 . V_308 ) , F_123 ( V_26 . V_309 ) , F_123 ( V_26 . V_310 ) ) ;
return 0 ;
}
static int F_124 ( int V_31 , const char * * V_32 )
{
char V_172 [ 64 ] ;
int V_2 , V_27 , V_44 = 1 ;
unsigned long V_47 , V_311 , V_26 , V_175 = 0 , V_312 = ~ 0UL ;
if ( V_31 < 1 || V_31 > 3 )
return V_35 ;
V_27 = F_19 ( V_31 , V_32 , & V_44 , & V_311 , NULL , NULL ) ;
if ( V_27 )
return V_27 ;
if ( V_31 >= 2 ) {
V_27 = F_13 ( V_32 [ 2 ] , & V_175 ) ;
if ( V_27 )
return V_27 ;
}
if ( ! V_175 )
V_175 = V_193 ;
else if ( V_175 > V_193 )
return V_197 ;
sprintf ( V_172 , L_176 , ( int ) ( 2 * V_175 ) ) ;
if ( V_31 >= 3 ) {
V_27 = F_13 ( V_32 [ 3 ] , & V_312 ) ;
if ( V_27 )
return V_27 ;
if ( ! F_96 ( V_312 ) ) {
F_17 ( L_177 , V_312 ) ;
return V_203 ;
}
}
#ifdef F_125
#define F_126 ( V_2 ) __per_cpu_offset(cpu)
#else
#ifdef V_137
#define F_126 ( V_2 ) __per_cpu_offset[cpu]
#else
#define F_126 ( V_2 ) 0
#endif
#endif
F_101 (cpu) {
if ( F_33 ( V_102 ) )
return 0 ;
if ( V_312 != ~ 0UL && V_312 != V_2 )
continue;
V_47 = V_311 + F_126 ( V_2 ) ;
V_27 = F_65 ( & V_26 , V_47 , V_175 ) ;
if ( V_27 ) {
F_17 ( L_178 V_313 L_179
L_180 , V_2 , V_47 , V_27 ) ;
continue;
}
F_17 ( L_178 , V_2 ) ;
F_63 ( V_172 , V_47 ,
V_175 == V_193 ,
1 , V_175 , 1 , 1 , 0 ) ;
}
#undef F_126
return 0 ;
}
static int F_127 ( int V_31 , const char * * V_32 )
{
F_17 ( L_181 ) ;
F_17 ( L_182 ) ;
F_17 ( L_183 ) ;
F_17 ( L_184 ) ;
F_17 ( L_185
L_186 ) ;
F_17 ( L_187 ) ;
F_17 ( L_188
L_189 ) ;
F_17 ( L_190
L_191 ) ;
return 0 ;
}
int F_24 ( char * V_116 ,
T_12 V_314 ,
char * V_76 ,
char * V_77 ,
short V_315 ,
T_1 V_4 )
{
int V_16 ;
T_5 * V_241 ;
F_36 (kp, i) {
if ( V_241 -> V_106 && ( strcmp ( V_241 -> V_106 , V_116 ) == 0 ) ) {
F_17 ( L_192
L_193 , V_116 , V_314 , V_77 ) ;
return 1 ;
}
}
F_36 (kp, i) {
if ( V_241 -> V_106 == NULL )
break;
}
if ( V_16 >= V_108 ) {
T_5 * V_316 = F_30 ( ( V_108 - V_317 +
V_318 ) * sizeof( * V_316 ) , V_78 ) ;
if ( ! V_316 ) {
F_17 ( L_194
L_195 ) ;
return 1 ;
}
if ( V_319 ) {
memcpy ( V_316 , V_319 ,
( V_108 - V_317 ) * sizeof( * V_316 ) ) ;
F_27 ( V_319 ) ;
}
memset ( V_316 + V_108 - V_317 , 0 ,
V_318 * sizeof( * V_316 ) ) ;
V_319 = V_316 ;
V_241 = V_319 + V_108 - V_317 ;
V_108 += V_318 ;
}
V_241 -> V_106 = V_116 ;
V_241 -> V_111 = V_314 ;
V_241 -> V_266 = V_76 ;
V_241 -> V_267 = V_77 ;
V_241 -> V_107 = V_315 ;
V_241 -> V_109 = V_4 ;
return 0 ;
}
int F_128 ( char * V_116 ,
T_12 V_314 ,
char * V_76 ,
char * V_77 ,
short V_315 )
{
return F_24 ( V_116 , V_314 , V_76 , V_77 , V_315 , 0 ) ;
}
int F_129 ( char * V_116 )
{
int V_16 ;
T_5 * V_241 ;
F_36 (kp, i) {
if ( V_241 -> V_106 && ( strcmp ( V_241 -> V_106 , V_116 ) == 0 ) ) {
V_241 -> V_106 = NULL ;
return 0 ;
}
}
return 1 ;
}
static void T_13 F_130 ( void )
{
int V_16 ;
T_5 * V_241 ;
F_36 (kp, i)
V_241 -> V_106 = NULL ;
F_24 ( L_75 , F_68 , L_196 ,
L_197 , 1 ,
V_54 | V_114 ) ;
F_24 ( L_74 , F_68 , L_198 ,
L_199 , 0 ,
V_54 | V_114 ) ;
F_24 ( L_77 , F_68 , L_200 ,
L_201 , 0 ,
V_54 | V_114 ) ;
F_24 ( L_76 , F_68 , L_196 ,
L_202 , 0 ,
V_54 | V_114 ) ;
F_24 ( L_203 , F_70 , L_204 ,
L_205 , 0 ,
V_320 | V_114 ) ;
F_24 ( L_206 , F_72 , L_207 ,
L_208 , 1 ,
V_321 | V_322 ) ;
F_24 ( L_209 , F_73 , L_1 ,
L_210 , 0 ,
V_323 ) ;
F_24 ( L_211 , F_75 , L_212 ,
L_213 , 0 ,
V_321 ) ;
F_24 ( L_214 , F_79 , L_196 ,
L_215 , 0 ,
V_54 ) ;
F_24 ( L_216 , V_324 , L_207 ,
L_217 , 1 ,
V_54 | V_325 ) ;
F_24 ( L_218 , V_324 , L_219 ,
L_220 , 0 ,
V_326 ) ;
F_24 ( L_221 , V_324 , L_222 ,
L_223 , 0 ,
V_326 ) ;
F_24 ( L_224 , V_324 , L_1 ,
L_225 , 0 ,
V_326 ) ;
F_24 ( L_226 , V_324 , L_196 ,
L_227 , 0 ,
V_54 | V_325 ) ;
F_24 ( L_228 , F_84 , L_1 ,
L_229 , 0 ,
V_9 ) ;
F_24 ( L_114 , F_16 , L_1 ,
L_230 , 0 ,
V_9 ) ;
F_24 ( L_231 , F_111 , L_1 ,
L_232 , 1 ,
V_9 ) ;
F_24 ( L_233 , F_111 , L_1 ,
L_232 , 0 ,
V_9 ) ;
F_24 ( L_234 , F_98 , L_235 ,
L_236 , 0 ,
V_322 ) ;
F_24 ( L_237 , F_110 , L_1 ,
L_238 , 0 , 0 ) ;
F_24 ( L_239 , F_107 , L_240 ,
L_241 , 0 ,
V_326 ) ;
F_24 ( L_242 , F_108 , L_243 ,
L_244 , 0 ,
V_326 ) ;
F_24 ( L_245 , F_42 , L_1 ,
L_246 , 0 ,
V_327 ) ;
#if F_54 ( V_328 )
F_24 ( L_247 , F_80 , L_1 ,
L_248 , 0 ,
V_326 ) ;
#endif
#if F_54 ( V_329 )
F_24 ( L_249 , F_77 , L_250 ,
L_251 , 0 ,
V_9 ) ;
#endif
#if F_54 ( V_330 )
F_24 ( L_252 , F_86 , L_253 ,
L_254 , 0 ,
V_9 ) ;
#endif
if ( V_238 . V_239 ) {
F_24 ( L_255 , F_90 , L_1 ,
L_256 , 0 ,
V_9 ) ;
}
F_24 ( L_257 , F_28 , L_258 ,
L_259 , 0 ,
V_9 ) ;
F_24 ( L_260 , F_112 , L_261 ,
L_262 , 0 ,
V_331 ) ;
F_24 ( L_263 , F_118 , L_1 ,
L_264 , 4 ,
V_9 ) ;
F_24 ( L_265 , F_124 , L_266 ,
L_267 , 3 ,
V_54 ) ;
F_24 ( L_268 , F_127 , L_1 ,
L_269 , 0 ,
V_9 ) ;
}
static void T_13 F_131 ( void )
{
int V_16 , V_27 ;
for ( V_16 = 0 ; V_332 [ V_16 ] ; ++ V_16 ) {
V_27 = F_31 ( V_332 [ V_16 ] ) ;
if ( V_27 )
F_17 ( L_270 ,
V_332 [ V_16 ] , V_27 ) ;
}
if ( V_72 ) {
F_17 ( L_271 ) ;
F_31 ( L_11 ) ;
}
}
void T_13 F_132 ( int V_333 )
{
static int V_334 = V_335 ;
int V_16 ;
if ( V_334 == V_336 || V_333 <= V_334 )
return;
for ( V_16 = V_334 ; V_16 < V_333 ; V_16 ++ ) {
switch ( V_16 ) {
case V_335 :
F_130 () ;
F_133 () ;
break;
case V_337 :
F_131 () ;
break;
}
}
V_334 = V_333 ;
}
