struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 ) ;
#ifdef F_3
if ( ( F_4 ( V_3 ) -> V_4 & F_3 ) && F_5 ( V_2 ) )
V_3 = V_5 -> V_3 ;
#endif
return V_3 ;
}
char * F_6 ( const char * V_6 )
{
char * * V_7 = V_8 ;
int V_9 = strlen ( V_6 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
char * V_12 = * V_7 ++ ;
if ( ! V_12 )
continue;
if ( ( strncmp ( V_6 , V_12 , V_9 ) == 0 )
&& ( ( V_12 [ V_9 ] == '\0' )
|| ( V_12 [ V_9 ] == '=' ) ) ) {
char * V_13 = strchr ( V_12 , '=' ) ;
return V_13 ? ++ V_13 : L_1 ;
}
}
return NULL ;
}
static char * F_7 ( T_1 V_14 )
{
#define F_8 512
static char V_15 [ F_8 ] ;
static int V_16 ;
char * V_7 = NULL ;
if ( ( F_8 - V_16 ) >= V_14 ) {
V_7 = & V_15 [ V_16 ] ;
V_16 += V_14 ;
}
return V_7 ;
}
static int F_9 ( const char * V_6 , unsigned long * V_17 )
{
char * V_7 ;
V_7 = F_6 ( V_6 ) ;
if ( ! V_7 )
return V_18 ;
if ( strlen ( V_7 ) == 0 )
return V_19 ;
* V_17 = F_10 ( V_7 , NULL , 0 ) ;
return 0 ;
}
int F_11 ( const char * V_6 , int * V_17 )
{
unsigned long V_20 ;
int V_21 ;
V_21 = F_9 ( V_6 , & V_20 ) ;
if ( ! V_21 )
* V_17 = ( int ) V_20 ;
return V_21 ;
}
int F_12 ( const char * V_22 , unsigned long * V_17 )
{
char * V_23 ;
unsigned long V_20 ;
V_20 = F_10 ( V_22 , & V_23 , 0 ) ;
if ( V_23 == V_22 ) {
V_20 = F_10 ( V_22 , & V_23 , 16 ) ;
if ( V_23 == V_22 )
return V_24 ;
}
* V_17 = V_20 ;
return 0 ;
}
int F_13 ( const char * V_22 , T_2 * V_17 )
{
char * V_23 ;
T_2 V_20 ;
V_20 = F_14 ( V_22 , & V_23 , 0 ) ;
if ( V_23 == V_22 ) {
V_20 = F_14 ( V_22 , & V_23 , 16 ) ;
if ( V_23 == V_22 )
return V_24 ;
}
* V_17 = V_20 ;
return 0 ;
}
int F_15 ( int V_25 , const char * * V_26 )
{
int V_10 ;
char * V_7 ;
T_1 V_27 , V_28 ;
if ( V_25 == 3 ) {
V_26 [ 2 ] = V_26 [ 3 ] ;
V_25 -- ;
}
if ( V_25 != 2 )
return V_29 ;
if ( strcmp ( V_26 [ 1 ] , L_2 ) == 0 ) {
unsigned int V_30 ;
char * V_13 ;
V_30 = F_10 ( V_26 [ 2 ] , & V_13 , 0 ) ;
if ( V_13 == V_26 [ 2 ] || V_30 & ~ V_31 ) {
F_16 ( L_3 ,
V_26 [ 2 ] ) ;
return 0 ;
}
V_32 = ( V_32 &
~ ( V_31 << V_33 ) )
| ( V_30 << V_33 ) ;
return 0 ;
}
V_27 = strlen ( V_26 [ 1 ] ) ;
V_28 = strlen ( V_26 [ 2 ] ) ;
V_7 = F_7 ( V_27 + V_28 + 2 ) ;
if ( V_7 == ( char * ) 0 )
return V_34 ;
sprintf ( V_7 , L_4 , V_26 [ 1 ] , V_26 [ 2 ] ) ;
V_7 [ V_27 + V_28 + 1 ] = '\0' ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( V_8 [ V_10 ]
&& ( ( strncmp ( V_8 [ V_10 ] , V_26 [ 1 ] , V_27 ) == 0 )
&& ( ( V_8 [ V_10 ] [ V_27 ] == '\0' )
|| ( V_8 [ V_10 ] [ V_27 ] == '=' ) ) ) ) {
V_8 [ V_10 ] = V_7 ;
return 0 ;
}
}
for ( V_10 = 0 ; V_10 < V_11 - 1 ; V_10 ++ ) {
if ( V_8 [ V_10 ] == ( char * ) 0 ) {
V_8 [ V_10 ] = V_7 ;
return 0 ;
}
}
return V_35 ;
}
static int F_17 ( void )
{
if ( ! V_36 ) {
F_16 ( L_5
L_6 ) ;
return V_37 ;
}
return 0 ;
}
int F_18 ( int V_25 , const char * * V_26 , int * V_38 ,
unsigned long * V_17 , long * V_39 ,
char * * V_40 )
{
unsigned long V_41 ;
unsigned long V_42 = 0 ;
int V_43 ;
int V_21 ;
int V_44 = 0 ;
char * V_45 ;
char V_46 = '\0' ;
char * V_13 ;
T_3 V_47 ;
if ( * V_38 > V_25 )
return V_29 ;
V_45 = ( char * ) V_26 [ * V_38 ] ;
V_13 = strpbrk ( V_45 , L_7 ) ;
if ( V_13 != NULL ) {
V_46 = * V_13 ;
* V_13 ++ = '\0' ;
}
if ( V_45 [ 0 ] == '$' ) {
V_21 = F_9 ( & V_45 [ 1 ] , & V_41 ) ;
if ( V_21 )
return V_21 ;
} else if ( V_45 [ 0 ] == '%' ) {
V_21 = F_17 () ;
if ( V_21 )
return V_21 ;
return V_48 ;
} else {
V_44 = F_19 ( V_45 , & V_47 ) ;
if ( V_44 ) {
V_41 = V_47 . V_49 ;
} else {
V_21 = F_12 ( V_26 [ * V_38 ] , & V_41 ) ;
if ( V_21 )
return V_21 ;
}
}
if ( ! V_44 )
V_44 = F_20 ( V_41 , & V_47 ) ;
( * V_38 ) ++ ;
if ( V_40 )
* V_40 = V_45 ;
if ( V_17 )
* V_17 = V_41 ;
if ( V_39 && V_40 && * V_40 )
* V_39 = V_41 - V_47 . V_49 ;
if ( ( * V_38 > V_25 )
&& ( V_46 == '\0' ) )
return 0 ;
if ( V_46 == '\0' ) {
if ( ( V_26 [ * V_38 ] [ 0 ] != '+' )
&& ( V_26 [ * V_38 ] [ 0 ] != '-' ) ) {
return 0 ;
} else {
V_43 = ( V_26 [ * V_38 ] [ 0 ] == '+' ) ;
( * V_38 ) ++ ;
}
} else
V_43 = ( V_46 == '+' ) ;
if ( ( * V_38 > V_25 )
&& ( V_46 == '\0' ) ) {
return V_50 ;
}
if ( ! V_46 ) {
V_13 = ( char * ) V_26 [ * V_38 ] ;
( * V_38 ) ++ ;
}
V_21 = F_12 ( V_13 , & V_42 ) ;
if ( V_21 )
return V_21 ;
if ( ! V_43 )
V_42 = - V_42 ;
if ( V_39 )
* V_39 += V_42 ;
if ( V_17 )
* V_17 += V_42 ;
return 0 ;
}
static void F_21 ( int V_21 )
{
int V_10 ;
if ( V_21 >= 0 ) {
F_16 ( L_8 , V_21 ) ;
return;
}
for ( V_10 = 0 ; V_10 < V_51 ; V_10 ++ ) {
if ( V_52 [ V_10 ] . V_53 == V_21 ) {
F_16 ( L_9 , V_21 , V_52 [ V_10 ] . V_54 ) ;
return;
}
}
F_16 ( L_10 , - V_21 ) ;
}
static int F_22 ( const char * V_55 , const char * V_56 )
{
struct V_57 * V_58 = V_57 + V_59 - 1 ;
char * * V_60 = V_58 -> V_61 ;
if ( strcmp ( V_56 , L_11 ) == 0 ) {
V_62 = 0 ;
if ( ! V_58 -> V_63 )
V_58 -> V_64 = 0 ;
if ( V_58 -> V_64 )
F_23 ( V_58 -> V_40 , V_65 ,
V_58 -> V_66 , V_58 -> V_67 , 0 ) ;
return 0 ;
}
if ( ! V_58 -> V_64 )
return V_48 ;
V_58 -> V_61 = F_24 ( ( V_58 -> V_63 + 1 ) * sizeof( * ( V_58 -> V_61 ) ) , V_68 ) ;
if ( ! V_58 -> V_61 ) {
F_16 ( L_12 ,
V_55 ) ;
V_58 -> V_64 = 0 ;
return V_48 ;
}
memcpy ( V_58 -> V_61 , V_60 , V_58 -> V_63 * sizeof( * ( V_58 -> V_61 ) ) ) ;
V_58 -> V_61 [ V_58 -> V_63 ++ ] = F_25 ( V_55 , V_68 ) ;
F_26 ( V_60 ) ;
return 0 ;
}
static int F_27 ( int V_25 , const char * * V_26 )
{
struct V_57 * V_69 = V_57 , * V_58 ;
if ( V_62 ) {
F_16 ( L_13
L_14 ) ;
F_22 ( L_11 , L_11 ) ;
}
if ( V_25 == 0 ) {
int V_10 ;
for ( V_58 = V_57 ; V_58 < V_57 + V_59 ; ++ V_58 ) {
F_16 ( L_15 , V_58 -> V_40 ,
V_58 -> V_66 , V_58 -> V_67 ) ;
for ( V_10 = 0 ; V_10 < V_58 -> V_63 ; ++ V_10 )
F_16 ( L_16 , V_58 -> V_61 [ V_10 ] ) ;
F_16 ( L_14 ) ;
}
return 0 ;
}
if ( V_25 != 3 )
return V_29 ;
V_57 = F_28 ( ( V_59 + 1 ) * sizeof( * V_57 ) ,
V_68 ) ;
if ( ! V_57 ) {
F_16 ( L_17 ,
V_26 [ 1 ] ) ;
V_57 = V_69 ;
return V_48 ;
}
memcpy ( V_57 , V_69 ,
V_59 * sizeof( * V_57 ) ) ;
F_26 ( V_69 ) ;
V_58 = V_57 + V_59 ;
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
V_58 -> V_64 = 1 ;
V_58 -> V_40 = F_25 ( V_26 [ 1 ] , V_68 ) ;
V_58 -> V_66 = F_25 ( V_26 [ 2 ] , V_68 ) ;
V_58 -> V_67 = F_25 ( V_26 [ 3 ] , V_68 ) ;
if ( V_58 -> V_66 [ 0 ] == '"' ) {
strcpy ( V_58 -> V_66 , V_58 -> V_66 + 1 ) ;
V_58 -> V_66 [ strlen ( V_58 -> V_66 ) - 1 ] = '\0' ;
}
if ( V_58 -> V_67 [ 0 ] == '"' ) {
strcpy ( V_58 -> V_67 , V_58 -> V_67 + 1 ) ;
V_58 -> V_67 [ strlen ( V_58 -> V_67 ) - 1 ] = '\0' ;
}
++ V_59 ;
V_62 = 1 ;
return 0 ;
}
static int V_65 ( int V_25 , const char * * V_26 )
{
int V_10 , V_70 ;
struct V_57 * V_58 ;
if ( V_25 != 0 )
return V_29 ;
for ( V_58 = V_57 , V_10 = 0 ; V_10 < V_59 ; ++ V_10 , ++ V_58 ) {
if ( strcmp ( V_58 -> V_40 , V_26 [ 0 ] ) == 0 )
break;
}
if ( V_10 == V_59 ) {
F_16 ( L_18 ,
V_26 [ 0 ] ) ;
return V_48 ;
}
for ( V_10 = 0 ; V_10 < V_58 -> V_63 ; ++ V_10 ) {
V_26 = NULL ;
F_16 ( L_19 , V_58 -> V_40 , V_58 -> V_61 [ V_10 ] ) ;
V_70 = F_29 ( V_58 -> V_61 [ V_10 ] ) ;
if ( V_70 )
return V_70 ;
}
return 0 ;
}
static void F_30 ( const char * V_71 )
{
int V_72 ;
char * V_13 = ( char * ) V_71 , * V_73 ;
if ( * V_13 != '|' )
return;
V_13 ++ ;
while ( isspace ( * V_13 ) )
V_13 ++ ;
if ( strncmp ( V_13 , L_20 , 5 ) ) {
F_16 ( L_21 ) ;
return;
}
V_13 += 5 ;
while ( isspace ( * V_13 ) )
V_13 ++ ;
V_73 = strchr ( V_13 , '\n' ) ;
if ( V_73 )
* V_73 = '\0' ;
V_72 = strlen ( V_13 ) ;
if ( V_72 == 0 ) {
F_16 ( L_21 ) ;
return;
}
if ( * V_13 == '"' ) {
V_13 ++ ;
V_73 = strchr ( V_13 , '"' ) ;
if ( ! V_73 ) {
F_16 ( L_22 ) ;
return;
}
* V_73 = '\0' ;
}
V_74 = 0 ;
if ( * V_13 == '^' ) {
V_74 = 1 ;
V_13 ++ ;
}
V_72 = strlen ( V_13 ) ;
V_75 = 0 ;
if ( * ( V_13 + V_72 - 1 ) == '$' ) {
V_75 = 1 ;
* ( V_13 + V_72 - 1 ) = '\0' ;
}
V_72 = strlen ( V_13 ) ;
if ( ! V_72 )
return;
if ( V_72 >= V_76 ) {
F_16 ( L_23 ) ;
return;
}
strcpy ( V_77 , V_13 ) ;
V_78 ++ ;
return;
}
int F_29 ( const char * V_55 )
{
static char * V_26 [ V_79 ] ;
static int V_25 ;
static char V_80 [ V_81 + 2 ] ;
char * V_13 ;
char * V_82 , V_83 ;
T_4 * V_84 ;
int V_10 , V_85 , V_86 = 0 , V_87 ;
V_13 = ( char * ) V_55 ;
V_78 = V_87 = 0 ;
if ( F_31 ( V_88 ) ) {
F_32 ( V_88 ) ;
F_33 ( V_89 ) ;
V_25 = 0 ;
}
if ( * V_13 != '\n' && * V_13 != '\0' ) {
V_25 = 0 ;
V_82 = V_80 ;
while ( * V_13 ) {
while ( isspace ( * V_13 ) )
V_13 ++ ;
if ( ( * V_13 == '\0' ) || ( * V_13 == '\n' ) ||
( * V_13 == '#' && ! V_62 ) )
break;
if ( * V_13 == '|' ) {
V_87 ++ ;
break;
}
if ( V_82 >= V_80 + V_81 ) {
F_16 ( L_24
L_25 ,
V_55 ) ;
return V_90 ;
}
if ( V_25 >= V_79 - 1 ) {
F_16 ( L_26
L_27 , V_55 ) ;
return V_90 ;
}
V_26 [ V_25 ++ ] = V_82 ;
V_85 = 0 ;
V_83 = '\0' ;
while ( * V_13 && * V_13 != '\n' &&
( V_85 || V_83 || ! isspace ( * V_13 ) ) ) {
if ( V_82 >= V_80 + V_81 )
break;
if ( V_85 ) {
V_85 = 0 ;
* V_82 ++ = * V_13 ++ ;
continue;
}
if ( * V_13 == '\\' ) {
V_85 = 1 ;
++ V_13 ;
continue;
}
if ( * V_13 == V_83 )
V_83 = '\0' ;
else if ( * V_13 == '\'' || * V_13 == '"' )
V_83 = * V_13 ;
* V_82 = * V_13 ++ ;
if ( * V_82 == '=' && ! V_83 )
break;
++ V_82 ;
}
* V_82 ++ = '\0' ;
}
}
if ( ! V_25 )
return 0 ;
if ( V_87 )
F_30 ( V_13 ) ;
if ( V_62 ) {
int V_91 = F_22 ( V_55 , V_26 [ 0 ] ) ;
if ( ! V_62 ) {
V_25 = 0 ;
* ( V_26 [ 0 ] ) = '\0' ;
}
return V_91 ;
}
if ( V_26 [ 0 ] [ 0 ] == '-' && V_26 [ 0 ] [ 1 ] &&
( V_26 [ 0 ] [ 1 ] < '0' || V_26 [ 0 ] [ 1 ] > '9' ) ) {
V_86 = 1 ;
++ V_26 [ 0 ] ;
}
F_34 (tp, i) {
if ( V_84 -> V_92 ) {
if ( V_84 -> V_93
&& ( strlen ( V_26 [ 0 ] ) <= V_84 -> V_93 ) ) {
if ( strncmp ( V_26 [ 0 ] ,
V_84 -> V_92 ,
V_84 -> V_93 ) == 0 ) {
break;
}
}
if ( strcmp ( V_26 [ 0 ] , V_84 -> V_92 ) == 0 )
break;
}
}
if ( V_10 == V_94 ) {
F_34 (tp, i) {
if ( V_84 -> V_92 ) {
if ( strncmp ( V_26 [ 0 ] ,
V_84 -> V_92 ,
strlen ( V_84 -> V_92 ) ) == 0 ) {
break;
}
}
}
}
if ( V_10 < V_94 ) {
int V_91 ;
F_33 ( V_95 ) ;
V_91 = (* V_84 -> V_96 )( V_25 - 1 , ( const char * * ) V_26 ) ;
if ( V_91 && V_86 && V_91 > V_97 )
V_91 = 0 ;
F_35 ( V_95 ) ;
switch ( V_84 -> V_98 ) {
case V_99 :
V_25 = 0 ;
if ( V_26 [ 0 ] )
* ( V_26 [ 0 ] ) = '\0' ;
break;
case V_100 :
V_25 = 1 ;
if ( V_26 [ 1 ] )
* ( V_26 [ 1 ] ) = '\0' ;
break;
case V_101 :
break;
}
return V_91 ;
}
{
unsigned long V_17 ;
char * V_40 = NULL ;
long V_39 ;
int V_38 = 0 ;
if ( F_18 ( 0 , ( const char * * ) V_26 , & V_38 ,
& V_17 , & V_39 , & V_40 ) ) {
return V_90 ;
}
F_16 ( L_28 , V_26 [ 0 ] ) ;
F_36 ( V_17 , NULL , V_102 ) ;
F_16 ( L_29 ) ;
return 0 ;
}
}
static int F_37 ( char * V_103 )
{
#define F_38 16
#define F_39 14
if ( V_104 == V_105 )
return 0 ;
switch ( * V_103 ) {
case F_38 :
if ( V_106 != V_105 )
V_106 = ( V_106 - 1 ) % V_107 ;
strncpy ( V_108 , V_109 [ V_106 ] , V_81 ) ;
return 1 ;
case F_39 :
if ( V_106 != V_104 )
V_106 = ( V_106 + 1 ) % V_107 ;
strncpy ( V_108 , V_109 [ V_106 ] , V_81 ) ;
return 1 ;
}
return 0 ;
}
static int F_40 ( int V_25 , const char * * V_26 )
{
F_41 () ;
F_16 ( L_30 ) ;
while ( 1 )
F_42 () ;
return 0 ;
}
static void F_43 ( struct V_110 * V_111 )
{
int V_112 = V_113 ;
V_113 = 15 ;
V_114 ++ ;
F_44 ( V_111 ) ;
V_114 -- ;
F_16 ( L_29 ) ;
V_113 = V_112 ;
}
void F_45 ( struct V_1 * V_3 )
{
V_115 = V_3 ;
if ( F_46 ( V_3 ) ) {
V_36 = F_47 ( F_48 ( V_3 ) ) ;
return;
}
V_36 = NULL ;
}
static int F_49 ( T_5 V_116 , int error , struct V_110 * V_111 ,
T_6 V_117 )
{
char * V_118 ;
int V_21 ;
struct V_1 * V_119 =
F_1 ( F_50 () ) ;
F_51 ( L_31 , V_116 ) ;
V_120 = 0 ;
if ( V_116 == V_121 ) {
} else {
F_16 ( L_32 ,
V_119 , V_119 ? V_119 -> V_122 : 0 ) ;
#if F_52 ( V_123 )
F_16 ( L_33 , F_50 () ) ;
#endif
}
switch ( V_116 ) {
case V_121 :
{
switch ( V_117 ) {
case V_124 :
F_16 ( L_34 ,
V_119 , V_119 -> V_122 ) ;
#if F_52 ( V_123 )
F_16 ( L_33 , F_50 () ) ;
#endif
F_16 ( L_35 V_125 L_29 ,
F_53 ( V_111 ) ) ;
break;
case V_126 :
F_51 ( L_36 , V_116 ) ;
return V_127 ;
break;
case V_128 :
break;
case V_129 :
F_51 ( L_37 , V_116 ) ;
return 1 ;
default:
F_16 ( L_38 ,
V_117 ) ;
break;
}
}
break;
case V_130 :
if ( F_54 ( V_131 ) )
F_16 ( L_39 ) ;
else
F_16 ( L_40 ) ;
break;
case V_132 :
F_33 ( V_131 ) ;
F_16 ( L_39 ) ;
break;
case V_133 :
case V_134 :
F_16 ( L_41 ) ;
break;
case V_135 :
F_16 ( L_42 , V_136 ) ;
F_16 ( L_43 V_125 L_29 ,
F_53 ( V_111 ) ) ;
F_43 ( V_111 ) ;
break;
case V_137 :
F_16 ( L_44
V_125 L_29 ,
F_53 ( V_111 ) ) ;
F_43 ( V_111 ) ;
break;
case V_138 :
case V_139 :
F_16 ( L_45 V_125 L_29 ,
V_116 == V_139 ?
L_46 : L_47 , F_53 ( V_111 ) ) ;
if ( V_117 != V_124 ) {
F_16 ( L_48 ,
V_117 ) ;
F_51 ( L_49 , V_116 ) ;
return 0 ;
}
break;
case V_140 :
F_16 ( L_50 V_125 L_29 ,
F_53 ( V_111 ) ) ;
break;
default:
F_16 ( L_51 , V_116 ) ;
F_51 ( L_52 , V_116 ) ;
return 0 ;
}
while ( 1 ) {
V_141 = 1 ;
F_35 ( V_142 ) ;
V_118 = V_108 ;
* V_118 = '\0' ;
* ( V_109 [ V_104 ] ) = '\0' ;
if ( F_31 ( V_143 ) ) {
const char * V_144 [] = { L_53 , L_54 , L_55 } ;
F_15 ( 2 , V_144 ) ;
F_40 ( 0 , NULL ) ;
}
V_145:
#if F_52 ( V_123 )
snprintf ( V_146 , V_81 , F_6 ( L_56 ) ,
F_50 () ) ;
#else
snprintf ( V_146 , V_81 , F_6 ( L_56 ) ) ;
#endif
if ( V_62 )
strncat ( V_146 , L_57 , V_81 ) ;
V_118 = F_55 ( V_118 , V_81 , V_146 ) ;
if ( * V_118 != '\n' ) {
if ( * V_118 < 32 ) {
if ( V_106 == V_104 ) {
strncpy ( V_109 [ V_104 ] , V_108 ,
V_81 ) ;
* ( V_109 [ V_104 ] +
strlen ( V_109 [ V_104 ] ) - 1 ) = '\0' ;
}
if ( ! F_37 ( V_118 ) )
* ( V_108 + strlen ( V_108 ) - 1 ) = '\0' ;
V_118 = V_108 ;
goto V_145;
} else {
strncpy ( V_109 [ V_104 ] , V_108 ,
V_81 ) ;
}
V_104 = ( V_104 + 1 ) % V_107 ;
if ( V_104 == V_105 )
V_105 = ( V_105 + 1 ) % V_107 ;
}
V_106 = V_104 ;
V_21 = F_29 ( V_118 ) ;
if ( V_21 == V_90 ) {
F_16 ( L_58 , V_118 ) ;
V_21 = 0 ;
}
if ( V_21 == V_97
|| V_21 == V_147
|| V_21 == V_148
|| V_21 == V_127
|| V_21 == V_149 )
break;
if ( V_21 )
F_21 ( V_21 ) ;
}
F_51 ( L_59 , V_21 ) ;
return V_21 ;
}
void F_56 ( const char * V_150 , int V_17 )
{
F_16 ( L_60 ,
V_150 , F_50 () , V_17 , V_151 ,
V_152 ) ;
}
int F_57 ( T_5 V_116 , T_5 V_153 , int error ,
T_6 V_117 , struct V_110 * V_111 )
{
int V_91 = 1 ;
while ( 1 ) {
F_51 ( L_61 , V_116 ) ;
while ( F_54 ( V_154 ) ) {
if ( ! F_54 ( V_155 ) )
F_33 ( V_155 ) ;
}
F_35 ( V_142 ) ;
F_51 ( L_62 , V_116 ) ;
if ( F_54 ( V_156 ) )
break;
V_91 = F_49 ( V_153 , error , V_111 , V_117 ) ;
F_51 ( L_63 , V_91 ) ;
if ( V_91 == V_147 )
break;
if ( V_91 == V_148 ) {
F_33 ( V_157 ) ;
break;
}
if ( V_91 == V_127 ) {
F_33 ( V_157 ) ;
F_33 ( V_158 ) ;
break;
}
if ( V_91 == V_149 ) {
if ( ! F_54 ( V_159 ) )
F_16 ( L_64
L_65 ) ;
break;
}
if ( V_91 && V_91 != 1 && V_91 != V_97 )
F_16 ( L_66 ,
V_91 ) ;
F_51 ( L_67 , V_116 ) ;
break;
}
if ( F_54 ( V_157 ) )
F_35 ( V_160 ) ;
F_58 () ;
return V_91 ;
}
static int F_59 ( unsigned long V_41 , unsigned int V_63 )
{
unsigned char V_161 ;
while ( V_63 -- ) {
if ( F_60 ( V_161 , V_41 ) )
return 0 ;
F_16 ( L_68 , V_161 ) ;
V_41 ++ ;
}
F_16 ( L_29 ) ;
return 0 ;
}
static void F_61 ( const char * V_162 , unsigned long V_41 ,
int V_163 , int V_164 , int V_165 ,
int V_166 , int V_167 , int V_168 )
{
T_3 V_47 ;
char V_80 [ 32 ] ;
char * V_161 = V_80 ;
int V_10 ;
unsigned long V_169 ;
memset ( V_80 , '\0' , sizeof( V_80 ) ) ;
if ( V_168 )
F_16 ( L_69 V_170 L_70 , V_41 ) ;
else
F_16 ( V_170 L_70 , V_41 ) ;
for ( V_10 = 0 ; V_10 < V_166 && V_167 -- ; V_10 ++ ) {
if ( V_168 ) {
if ( F_62 ( & V_169 , V_41 , V_165 ) )
break;
} else if ( F_63 ( & V_169 , V_41 , V_165 ) )
break;
F_16 ( V_162 , V_169 ) ;
if ( V_163 )
F_20 ( V_169 , & V_47 ) ;
else
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
if ( V_47 . V_171 ) {
F_36 ( V_169 , & V_47 , 0 ) ;
if ( ! V_164 ) {
F_16 ( L_29 ) ;
F_16 ( L_71
V_125 L_70
V_125 L_70
V_125 , V_47 . V_172 ,
V_47 . V_173 , V_47 . V_174 ,
V_47 . V_49 , V_47 . V_175 ) ;
}
V_41 += V_165 ;
} else {
union {
T_2 V_169 ;
unsigned char V_161 [ 8 ] ;
} V_176 ;
unsigned char * V_13 ;
#ifdef F_64
V_13 = V_176 . V_161 + 8 - V_165 ;
#else
V_13 = V_176 . V_161 ;
#endif
V_176 . V_169 = V_169 ;
#define F_65 ( V_161 ) \
({unsigned char __c = c; isascii(__c) && isprint(__c) ? __c : '.'; })
switch ( V_165 ) {
case 8 :
* V_161 ++ = F_65 ( * V_13 ++ ) ;
* V_161 ++ = F_65 ( * V_13 ++ ) ;
* V_161 ++ = F_65 ( * V_13 ++ ) ;
* V_161 ++ = F_65 ( * V_13 ++ ) ;
V_41 += 4 ;
case 4 :
* V_161 ++ = F_65 ( * V_13 ++ ) ;
* V_161 ++ = F_65 ( * V_13 ++ ) ;
V_41 += 2 ;
case 2 :
* V_161 ++ = F_65 ( * V_13 ++ ) ;
V_41 ++ ;
case 1 :
* V_161 ++ = F_65 ( * V_13 ++ ) ;
V_41 ++ ;
break;
}
#undef F_65
}
}
F_16 ( L_72 , ( int ) ( ( V_166 - V_10 ) * ( 2 * V_165 + 1 ) + 1 ) ,
L_70 , V_80 ) ;
}
static int F_66 ( int V_25 , const char * * V_26 )
{
static unsigned long V_177 ;
static int V_178 , V_179 , V_180 ;
int V_181 = 16 , V_182 = 8 , V_165 = V_183 , V_167 ;
int V_164 = 0 ;
char V_184 , V_162 [ 64 ] ;
unsigned long V_41 ;
unsigned long V_169 ;
long V_39 = 0 ;
int V_163 = 0 ;
int V_185 = 0 ;
int V_168 = 0 ;
F_11 ( L_73 , & V_182 ) ;
F_11 ( L_74 , & V_181 ) ;
F_11 ( L_75 , & V_165 ) ;
V_167 = V_182 * 16 / V_165 ;
if ( strcmp ( V_26 [ 0 ] , L_76 ) == 0 ) {
if ( V_25 != 2 )
return V_29 ;
V_185 = 1 ;
} else if ( isdigit ( V_26 [ 0 ] [ 2 ] ) ) {
V_165 = ( int ) ( V_26 [ 0 ] [ 2 ] - '0' ) ;
if ( V_165 == 0 ) {
V_165 = V_179 ;
if ( V_165 == 0 )
V_165 = 4 ;
}
V_179 = V_165 ;
V_167 = V_182 * 16 / V_165 ;
if ( ! V_26 [ 0 ] [ 3 ] )
V_185 = 1 ;
else if ( V_26 [ 0 ] [ 3 ] == 'c' && V_26 [ 0 ] [ 4 ] ) {
char * V_3 ;
V_167 = F_10 ( V_26 [ 0 ] + 4 , & V_3 , 10 ) ;
V_182 = ( ( V_167 * V_165 ) + 15 ) / 16 ;
V_185 = ! * V_3 ;
}
V_180 = V_167 ;
} else if ( strcmp ( V_26 [ 0 ] , L_77 ) == 0 )
V_185 = 1 ;
else if ( strcmp ( V_26 [ 0 ] , L_78 ) == 0 )
V_185 = 1 ;
else if ( strcmp ( V_26 [ 0 ] , L_79 ) == 0 ) {
V_168 = V_185 = 1 ;
}
if ( ! V_185 )
return V_90 ;
if ( V_25 == 0 ) {
if ( V_177 == 0 )
return V_29 ;
V_41 = V_177 ;
V_181 = V_178 ;
V_165 = V_179 ;
V_167 = V_180 ;
V_182 = ( ( V_167 * V_165 ) + 15 ) / 16 ;
}
if ( V_25 ) {
unsigned long V_20 ;
int V_21 , V_38 = 1 ;
V_21 = F_18 ( V_25 , V_26 , & V_38 , & V_41 ,
& V_39 , NULL ) ;
if ( V_21 )
return V_21 ;
if ( V_25 > V_38 + 2 )
return V_29 ;
if ( V_25 >= V_38 ) {
V_21 = F_12 ( V_26 [ V_38 ] , & V_20 ) ;
if ( ! V_21 ) {
V_182 = ( int ) V_20 ;
V_167 = V_182 * 16 / V_165 ;
}
}
if ( V_25 >= V_38 + 1 ) {
V_21 = F_12 ( V_26 [ V_38 + 1 ] , & V_20 ) ;
if ( ! V_21 )
V_181 = ( int ) V_20 ;
}
}
if ( strcmp ( V_26 [ 0 ] , L_76 ) == 0 )
return F_59 ( V_41 , V_182 ) ;
switch ( V_181 ) {
case 10 :
V_184 = 'd' ;
break;
case 16 :
V_184 = 'x' ;
break;
case 8 :
V_184 = 'o' ;
break;
default:
return V_186 ;
}
V_178 = V_181 ;
if ( V_165 > V_183 )
return V_187 ;
switch ( V_165 ) {
case 8 :
sprintf ( V_162 , L_80 , V_184 ) ;
break;
case 4 :
sprintf ( V_162 , L_81 , V_184 ) ;
break;
case 2 :
sprintf ( V_162 , L_82 , V_184 ) ;
break;
case 1 :
sprintf ( V_162 , L_83 , V_184 ) ;
break;
default:
return V_187 ;
}
V_180 = V_167 ;
V_179 = V_165 ;
if ( strcmp ( V_26 [ 0 ] , L_78 ) == 0 ) {
V_163 = 1 ;
V_165 = V_183 ;
V_167 = V_182 ;
F_11 ( L_84 , & V_164 ) ;
}
V_41 &= ~ ( V_165 - 1 ) ;
while ( V_167 > 0 ) {
unsigned long V_188 ;
int V_189 , V_190 , V_166 = ( V_163 ? 1 : ( 16 / V_165 ) ) ;
if ( F_31 ( V_88 ) )
return 0 ;
for ( V_188 = V_41 , V_190 = 0 ; V_190 < V_167 ; V_188 += V_165 , ++ V_190 ) {
if ( V_168 ) {
if ( F_62 ( & V_169 , V_188 , V_165 )
|| V_169 )
break;
} else if ( F_63 ( & V_169 , V_188 , V_165 ) || V_169 )
break;
}
V_189 = F_67 ( V_166 , V_167 ) ;
F_61 ( V_162 , V_41 , V_163 , V_164 , V_165 ,
V_166 , V_167 , V_168 ) ;
V_41 += V_165 * V_189 ;
V_167 -= V_189 ;
V_190 = ( V_190 + V_166 - 1 ) / V_166 ;
if ( V_190 > 2 ) {
int V_58 = V_166 * ( V_190 - 2 ) ;
F_16 ( V_170 L_85 V_170
L_86 ,
V_41 , V_41 + V_165 * V_58 - 1 ) ;
V_41 += V_165 * V_58 ;
V_167 -= V_58 ;
}
}
V_177 = V_41 ;
return 0 ;
}
static int F_68 ( int V_25 , const char * * V_26 )
{
int V_21 ;
unsigned long V_41 ;
long V_39 = 0 ;
unsigned long V_191 ;
int V_38 ;
int V_192 ;
if ( V_26 [ 0 ] [ 2 ] && ! isdigit ( V_26 [ 0 ] [ 2 ] ) )
return V_90 ;
if ( V_25 < 2 )
return V_29 ;
V_38 = 1 ;
V_21 = F_18 ( V_25 , V_26 , & V_38 , & V_41 , & V_39 , NULL ) ;
if ( V_21 )
return V_21 ;
if ( V_38 > V_25 )
return V_29 ;
V_21 = F_18 ( V_25 , V_26 , & V_38 , & V_191 , NULL , NULL ) ;
if ( V_21 )
return V_21 ;
if ( V_38 != V_25 + 1 )
return V_29 ;
V_192 = V_26 [ 0 ] [ 2 ] ? ( V_26 [ 0 ] [ 2 ] - '0' ) : ( V_183 ) ;
V_21 = F_69 ( V_41 , V_191 , V_192 ) ;
if ( V_21 )
return V_21 ;
F_16 ( V_125 L_87 V_125 L_29 , V_41 , V_191 ) ;
return 0 ;
}
static int F_70 ( int V_25 , const char * * V_26 )
{
unsigned long V_41 ;
int V_21 ;
int V_38 ;
long V_39 ;
if ( F_50 () != V_151 ) {
F_16 ( L_88
L_89 ,
V_151 ) ;
return V_193 ;
}
if ( V_25 == 1 ) {
V_38 = 1 ;
V_21 = F_18 ( V_25 , V_26 , & V_38 ,
& V_41 , & V_39 , NULL ) ;
if ( V_21 )
return V_21 ;
} else if ( V_25 ) {
return V_29 ;
}
V_21 = V_97 ;
if ( F_31 ( V_194 ) ) {
F_16 ( L_90 ) ;
F_16 ( L_91 ,
V_195 ) ;
if ( V_195 == 0 && V_120 ++ == 0 ) {
F_16 ( L_92
L_93 ) ;
return 0 ;
}
if ( V_195 == 2 ) {
F_16 ( L_94 ) ;
F_40 ( 0 , NULL ) ;
}
F_16 ( L_95 ) ;
}
return V_21 ;
}
static int F_71 ( int V_25 , const char * * V_26 )
{
int V_72 = F_17 () ;
#if V_196 > 0
int V_10 ;
char * V_197 ;
int V_198 ;
T_2 V_199 ;
T_7 V_200 ;
T_8 V_201 ;
T_9 V_202 ;
if ( V_72 )
return V_72 ;
for ( V_10 = 0 ; V_10 < V_196 ; V_10 ++ ) {
V_198 = V_203 [ V_10 ] . V_204 * 2 ;
if ( V_198 > 16 )
V_198 = 2 ;
if ( V_72 + strlen ( V_203 [ V_10 ] . V_40 ) + 4 + V_198 > 80 ) {
V_72 = 0 ;
F_16 ( L_29 ) ;
}
if ( V_72 )
V_72 += F_16 ( L_96 ) ;
switch( V_203 [ V_10 ] . V_204 * 8 ) {
case 8 :
V_197 = F_72 ( V_10 , & V_202 , V_36 ) ;
if ( ! V_197 )
break;
V_72 += F_16 ( L_97 , V_197 , V_202 ) ;
break;
case 16 :
V_197 = F_72 ( V_10 , & V_201 , V_36 ) ;
if ( ! V_197 )
break;
V_72 += F_16 ( L_98 , V_197 , V_201 ) ;
break;
case 32 :
V_197 = F_72 ( V_10 , & V_200 , V_36 ) ;
if ( ! V_197 )
break;
V_72 += F_16 ( L_99 , V_197 , V_200 ) ;
break;
case 64 :
V_197 = F_72 ( V_10 , & V_199 , V_36 ) ;
if ( ! V_197 )
break;
V_72 += F_16 ( L_100 , V_197 , V_199 ) ;
break;
default:
V_72 += F_16 ( L_101 , V_203 [ V_10 ] . V_40 ) ;
}
}
F_16 ( L_29 ) ;
#else
if ( V_72 )
return V_72 ;
F_43 ( V_36 ) ;
#endif
return 0 ;
}
static int F_73 ( int V_25 , const char * * V_26 )
{
#if V_196 > 0
int V_21 ;
const char * V_197 ;
int V_10 ;
T_2 V_199 ;
T_7 V_200 ;
T_8 V_201 ;
T_9 V_202 ;
if ( V_25 != 2 )
return V_29 ;
V_197 = V_26 [ 1 ] ;
if ( * V_197 == '%' )
V_197 ++ ;
V_21 = F_13 ( V_26 [ 2 ] , & V_199 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_17 () ;
if ( V_21 )
return V_21 ;
V_21 = V_37 ;
for ( V_10 = 0 ; V_10 < V_196 ; V_10 ++ ) {
if ( strcmp ( V_197 , V_203 [ V_10 ] . V_40 ) == 0 ) {
V_21 = 0 ;
break;
}
}
if ( ! V_21 ) {
switch( V_203 [ V_10 ] . V_204 * 8 ) {
case 8 :
V_202 = V_199 ;
F_74 ( V_10 , & V_202 , V_36 ) ;
break;
case 16 :
V_201 = V_199 ;
F_74 ( V_10 , & V_201 , V_36 ) ;
break;
case 32 :
V_200 = V_199 ;
F_74 ( V_10 , & V_200 , V_36 ) ;
break;
case 64 :
F_74 ( V_10 , & V_199 , V_36 ) ;
break;
}
}
return V_21 ;
#else
F_16 ( L_102 ) ;
return 0 ;
#endif
}
static int F_75 ( int V_25 , const char * * V_26 )
{
if ( V_25 != 1 )
return V_29 ;
V_114 ++ ;
F_76 ( * V_26 [ 1 ] , false ) ;
V_114 -- ;
return 0 ;
}
static int F_77 ( int V_25 , const char * * V_26 )
{
int V_21 ;
unsigned long V_41 ;
long V_39 ;
int V_38 ;
if ( V_25 != 1 )
return V_29 ;
V_38 = 1 ;
V_21 = F_18 ( V_25 , V_26 , & V_38 , & V_41 , & V_39 , NULL ) ;
if ( V_21 )
return V_21 ;
F_44 ( (struct V_110 * ) V_41 ) ;
return 0 ;
}
static int F_78 ( int V_25 , const char * * V_26 )
{
struct V_205 * V_206 ;
if ( V_25 != 0 )
return V_29 ;
F_16 ( L_103 ) ;
F_79 (mod, kdb_modules, list) {
F_16 ( L_104 , V_206 -> V_40 ,
V_206 -> V_207 , ( void * ) V_206 ) ;
#ifdef F_80
F_16 ( L_105 , F_81 ( V_206 ) ) ;
#endif
if ( V_206 -> V_208 == V_209 )
F_16 ( L_106 ) ;
else if ( V_206 -> V_208 == V_210 )
F_16 ( L_107 ) ;
else
F_16 ( L_108 ) ;
F_16 ( L_109 , V_206 -> V_211 ) ;
#ifdef F_80
{
struct V_212 * V_213 ;
F_16 ( L_110 ) ;
F_79 (use, &mod->source_list,
source_list)
F_16 ( L_111 , V_213 -> V_214 -> V_40 ) ;
F_16 ( L_112 ) ;
}
#endif
}
return 0 ;
}
static int F_82 ( int V_25 , const char * * V_26 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( V_8 [ V_10 ] )
F_16 ( L_113 , V_8 [ V_10 ] ) ;
}
if ( F_83 ( V_215 ) )
F_16 ( L_114 , V_32 ) ;
return 0 ;
}
static int F_84 ( int V_25 , const char * * V_26 )
{
int V_21 ;
int V_216 ;
int V_217 = 0 ;
int V_218 = 0 ;
int V_189 = 0 ;
int V_219 = 0 ;
struct V_220 V_221 = { . V_222 = 1 } ;
T_1 V_72 ;
char V_223 [ 201 ] ;
if ( V_25 > 2 )
return V_29 ;
if ( V_25 ) {
char * V_13 ;
V_217 = F_85 ( V_26 [ 1 ] , & V_13 , 0 ) ;
if ( * V_13 )
V_217 = 0 ;
if ( V_25 > 1 ) {
V_218 = F_10 ( V_26 [ 2 ] , & V_13 , 0 ) ;
if ( * V_13 || V_218 < 0 )
V_218 = 0 ;
}
}
V_21 = F_11 ( L_54 , & V_216 ) ;
if ( ! V_21 && V_216 ) {
const char * V_144 [] = { L_53 , L_54 , L_115 } ;
F_15 ( 2 , V_144 ) ;
}
F_86 ( & V_221 ) ;
while ( F_87 ( & V_221 , 1 , NULL , 0 , NULL ) )
V_189 ++ ;
if ( V_217 < 0 ) {
if ( V_218 >= V_189 )
F_16 ( L_116
L_117 , V_189 ) ;
else if ( V_218 - V_217 >= V_189 )
F_16 ( L_118
L_119 , V_189 , V_189 - V_218 ) ;
V_219 = V_218 ;
V_217 = abs ( V_217 ) ;
} else if ( V_217 > 0 ) {
V_219 = V_189 - V_217 - V_218 ;
V_217 = abs ( V_217 ) ;
if ( V_218 >= V_189 ) {
F_16 ( L_120
L_121 , V_189 ) ;
V_219 = V_189 ;
} else if ( V_219 < 0 ) {
V_217 += V_219 ;
V_219 = 0 ;
F_16 ( L_122
L_123 , V_189 , V_217 ) ;
}
} else {
V_217 = V_189 ;
}
if ( V_219 >= V_189 || V_219 < 0 )
return 0 ;
F_86 ( & V_221 ) ;
while ( F_87 ( & V_221 , 1 , V_223 , sizeof( V_223 ) , & V_72 ) ) {
if ( V_219 ) {
V_219 -- ;
continue;
}
if ( ! V_217 -- )
break;
F_16 ( L_124 , ( int ) V_72 - 1 , V_223 ) ;
}
return 0 ;
}
static void F_88 ( void )
{
int V_10 , V_224 , V_225 = 1 ;
char V_208 , V_226 = '?' ;
F_16 ( L_125 , F_50 () ) ;
F_16 ( L_126 ) ;
for ( V_224 = - 1 , V_10 = 0 ; V_10 < V_227 ; V_10 ++ ) {
if ( ! F_89 ( V_10 ) ) {
V_208 = 'F' ;
} else {
V_208 = ' ' ;
if ( F_90 ( F_5 ( V_10 ) ) == 'I' )
V_208 = 'I' ;
}
if ( V_208 != V_226 ) {
if ( V_226 != '?' ) {
if ( ! V_225 )
F_16 ( L_127 ) ;
V_225 = 0 ;
F_16 ( L_128 , V_224 ) ;
if ( V_224 < V_10 - 1 )
F_16 ( L_129 , V_10 - 1 ) ;
if ( V_226 != ' ' )
F_16 ( L_130 , V_226 ) ;
}
V_226 = V_208 ;
V_224 = V_10 ;
}
}
if ( V_226 != 'F' ) {
if ( ! V_225 )
F_16 ( L_127 ) ;
F_16 ( L_128 , V_224 ) ;
if ( V_224 < V_10 - 1 )
F_16 ( L_129 , V_10 - 1 ) ;
if ( V_226 != ' ' )
F_16 ( L_130 , V_226 ) ;
}
F_16 ( L_29 ) ;
}
static int F_91 ( int V_25 , const char * * V_26 )
{
unsigned long V_228 ;
int V_21 ;
if ( V_25 == 0 ) {
F_88 () ;
return 0 ;
}
if ( V_25 != 1 )
return V_29 ;
V_21 = F_12 ( V_26 [ 1 ] , & V_228 ) ;
if ( V_21 )
return V_21 ;
if ( ( V_228 > V_227 ) || ! F_89 ( V_228 ) )
return V_193 ;
V_229 = V_228 ;
return V_147 ;
}
void F_92 ( void )
{
int V_230 = 0 , V_231 = 0 ;
unsigned long V_232 = F_93 ( L_131 ) ,
V_233 = F_93 ( L_132 ) ;
unsigned long V_2 ;
const struct V_1 * V_3 , * V_234 ;
F_94 (cpu) {
V_3 = F_1 ( V_2 ) ;
if ( F_95 ( V_3 , V_232 ) )
++ V_230 ;
}
F_96 (g, p) {
if ( F_95 ( V_3 , V_233 ) )
++ V_231 ;
} F_97 ( V_234 , V_3 ) ;
if ( V_230 || V_231 ) {
if ( V_230 )
F_16 ( L_133 ,
V_230 , V_230 == 1 ? L_1 : L_134 ,
V_231 ? L_135 : L_1 ) ;
if ( V_231 )
F_16 ( L_136
L_137 , V_231 ,
V_231 == 1 ? L_1 : L_134 ) ;
F_16 ( L_138 ) ;
}
}
void F_98 ( const struct V_1 * V_3 )
{
int V_2 ;
unsigned long V_235 ;
if ( ! V_3 || F_99 ( & V_235 , ( char * ) V_3 , sizeof( unsigned long ) ) )
return;
V_2 = F_48 ( V_3 ) ;
F_16 ( L_139 ,
( void * ) V_3 , V_3 -> V_122 , V_3 -> V_236 -> V_122 ,
F_46 ( V_3 ) , F_48 ( V_3 ) ,
F_90 ( V_3 ) ,
( void * ) ( & V_3 -> V_237 ) ,
V_3 == F_1 ( F_50 () ) ? '*' : ' ' ,
V_3 -> V_238 ) ;
if ( F_46 ( V_3 ) ) {
if ( ! F_5 ( V_2 ) ) {
F_16 ( L_140 ) ;
} else {
if ( F_5 ( V_2 ) != V_3 )
F_16 ( L_141
L_142 , F_5 ( V_2 ) ) ;
}
}
}
static int F_100 ( int V_25 , const char * * V_26 )
{
struct V_1 * V_234 , * V_3 ;
unsigned long V_239 , V_2 ;
if ( V_25 == 0 )
F_92 () ;
F_16 ( L_143 ,
( int ) ( 2 * sizeof( void * ) ) + 2 , L_144 ,
( int ) ( 2 * sizeof( void * ) ) + 2 , L_145 ) ;
V_239 = F_93 ( V_25 ? V_26 [ 1 ] : NULL ) ;
F_94 (cpu) {
if ( F_31 ( V_88 ) )
return 0 ;
V_3 = F_1 ( V_2 ) ;
if ( F_95 ( V_3 , V_239 ) )
F_98 ( V_3 ) ;
}
F_16 ( L_29 ) ;
F_96 (g, p) {
if ( F_31 ( V_88 ) )
return 0 ;
if ( F_95 ( V_3 , V_239 ) )
F_98 ( V_3 ) ;
} F_97 ( V_234 , V_3 ) ;
return 0 ;
}
static int F_101 ( int V_25 , const char * * V_26 )
{
struct V_1 * V_3 ;
unsigned long V_20 ;
int V_21 ;
if ( V_25 > 1 )
return V_29 ;
if ( V_25 ) {
if ( strcmp ( V_26 [ 1 ] , L_146 ) == 0 ) {
V_3 = F_5 ( V_151 ) ;
} else {
V_21 = F_12 ( V_26 [ 1 ] , & V_20 ) ;
if ( V_21 )
return V_24 ;
V_3 = F_102 ( ( V_240 ) V_20 , & V_241 ) ;
if ( ! V_3 ) {
F_16 ( L_147 , ( V_240 ) V_20 ) ;
return 0 ;
}
}
F_45 ( V_3 ) ;
}
F_16 ( L_148 ,
V_115 -> V_238 ,
V_115 -> V_122 ) ;
return 0 ;
}
static int F_103 ( int V_25 , const char * * V_26 )
{
int V_21 = 0 ;
unsigned long V_41 ;
long V_39 = 0 ;
unsigned long V_242 ;
unsigned long V_243 ;
int V_38 ;
const char * V_61 ;
if ( V_25 != 3 )
return V_29 ;
V_38 = 1 ;
V_21 = F_18 ( V_25 , V_26 , & V_38 , & V_41 , & V_39 , NULL ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_26 [ 2 ] , & V_243 ) ;
if ( V_21 )
return V_21 ;
V_242 = V_41 ;
V_61 = F_25 ( V_26 [ 3 ] , V_68 ) ;
if ( ! V_61 ) {
F_16 ( L_149 , V_244 ) ;
return 0 ;
}
V_26 = NULL ;
while ( V_242 ) {
char V_223 [ 80 ] ;
if ( F_31 ( V_88 ) )
goto V_245;
sprintf ( V_223 , L_111 V_125 L_29 , V_61 , V_242 ) ;
V_21 = F_29 ( V_223 ) ;
if ( V_21 )
goto V_245;
V_41 = V_242 + V_243 ;
if ( F_63 ( & V_242 , V_41 , sizeof( V_242 ) ) )
goto V_245;
}
V_245:
F_26 ( V_61 ) ;
return V_21 ;
}
static int F_104 ( int V_25 , const char * * V_26 )
{
return V_149 ;
}
static int F_105 ( int V_25 , const char * * V_26 )
{
T_4 * V_246 ;
int V_10 ;
F_16 ( L_150 , L_151 , L_152 , L_153 ) ;
F_16 ( L_154
L_155 ) ;
F_34 (kt, i) {
if ( V_246 -> V_92 )
F_16 ( L_150 , V_246 -> V_92 ,
V_246 -> V_247 , V_246 -> V_248 ) ;
if ( F_31 ( V_88 ) )
return 0 ;
}
return 0 ;
}
static int F_106 ( int V_25 , const char * * V_26 )
{
long V_249 , V_122 ;
char * V_23 ;
struct V_1 * V_3 ;
struct V_250 V_251 ;
if ( V_25 != 2 )
return V_29 ;
V_249 = F_85 ( V_26 [ 1 ] , & V_23 , 0 ) ;
if ( * V_23 )
return V_24 ;
if ( V_249 >= 0 ) {
F_16 ( L_156 ) ;
return 0 ;
}
V_249 = - V_249 ;
V_122 = F_85 ( V_26 [ 2 ] , & V_23 , 0 ) ;
if ( * V_23 )
return V_24 ;
if ( V_122 <= 0 ) {
F_16 ( L_157 ) ;
return 0 ;
}
V_3 = F_102 ( V_122 , & V_241 ) ;
if ( ! V_3 ) {
F_16 ( L_158 ) ;
return 0 ;
}
V_3 = V_3 -> V_252 ;
V_251 . V_253 = V_249 ;
V_251 . V_254 = 0 ;
V_251 . V_255 = V_256 ;
V_251 . V_257 = V_122 ;
V_251 . V_258 = 0 ;
F_107 ( V_3 , & V_251 ) ;
return 0 ;
}
static void F_108 ( struct V_259 * V_260 , struct V_261 * V_262 )
{
static int V_263 [] = { 31 , 29 , 31 , 30 , 31 , 30 , 31 ,
31 , 30 , 31 , 30 , 31 } ;
memset ( V_262 , 0 , sizeof( * V_262 ) ) ;
V_262 -> V_264 = V_260 -> V_265 % ( 24 * 60 * 60 ) ;
V_262 -> V_266 = V_260 -> V_265 / ( 24 * 60 * 60 ) +
( 2 * 365 + 1 ) ;
V_262 -> V_267 = V_262 -> V_264 / 60 % 60 ;
V_262 -> V_268 = V_262 -> V_264 / 60 / 60 ;
V_262 -> V_264 = V_262 -> V_264 % 60 ;
V_262 -> V_269 = 68 + 4 * ( V_262 -> V_266 / ( 4 * 365 + 1 ) ) ;
V_262 -> V_266 %= ( 4 * 365 + 1 ) ;
V_263 [ 1 ] = 29 ;
while ( V_262 -> V_266 >= V_263 [ V_262 -> V_270 ] ) {
V_262 -> V_266 -= V_263 [ V_262 -> V_270 ] ;
if ( ++ V_262 -> V_270 == 12 ) {
V_262 -> V_270 = 0 ;
++ V_262 -> V_269 ;
V_263 [ 1 ] = 28 ;
}
}
++ V_262 -> V_266 ;
}
static void F_109 ( struct V_271 * V_20 )
{
struct V_259 V_272 ;
F_110 ( & V_272 ) ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_272 = V_272 . V_265 ;
V_20 -> V_273 [ 0 ] = V_274 [ 0 ] ;
V_20 -> V_273 [ 1 ] = V_274 [ 1 ] ;
V_20 -> V_273 [ 2 ] = V_274 [ 2 ] ;
V_20 -> V_275 = V_276 - 1 ;
F_111 ( V_20 ) ;
return;
}
static int F_112 ( int V_25 , const char * * V_26 )
{
struct V_259 V_277 ;
struct V_261 V_262 ;
struct V_271 V_20 ;
if ( V_25 )
return V_29 ;
F_16 ( L_159 , V_278 . V_40 . V_279 ) ;
F_16 ( L_160 , V_278 . V_40 . V_280 ) ;
F_16 ( L_161 , V_278 . V_40 . V_281 ) ;
F_16 ( L_162 , V_278 . V_40 . V_282 ) ;
F_16 ( L_163 , V_278 . V_40 . V_283 ) ;
F_16 ( L_164 , V_278 . V_40 . V_284 ) ;
F_16 ( L_165 , F_113 ( V_285 ) ) ;
V_277 = F_114 () ;
F_108 ( & V_277 , & V_262 ) ;
F_16 ( L_166
L_167 ,
1900 + V_262 . V_269 , V_262 . V_270 + 1 , V_262 . V_266 ,
V_262 . V_268 , V_262 . V_267 , V_262 . V_264 ,
V_286 . V_287 ) ;
F_109 ( & V_20 ) ;
F_16 ( L_168 ) ;
if ( V_20 . V_272 > ( 24 * 60 * 60 ) ) {
int V_288 = V_20 . V_272 / ( 24 * 60 * 60 ) ;
V_20 . V_272 %= ( 24 * 60 * 60 ) ;
F_16 ( L_169 , V_288 , V_288 == 1 ? L_1 : L_170 ) ;
}
F_16 ( L_171 , V_20 . V_272 / ( 60 * 60 ) , ( V_20 . V_272 / 60 ) % 60 ) ;
#define F_115 ( T_10 ) ((x) >> FSHIFT)
#define F_116 ( T_10 ) LOAD_INT(((x) & (FIXED_1-1)) * 100)
F_16 ( L_172 ,
F_115 ( V_20 . V_273 [ 0 ] ) , F_116 ( V_20 . V_273 [ 0 ] ) ,
F_115 ( V_20 . V_273 [ 1 ] ) , F_116 ( V_20 . V_273 [ 1 ] ) ,
F_115 ( V_20 . V_273 [ 2 ] ) , F_116 ( V_20 . V_273 [ 2 ] ) ) ;
#undef F_115
#undef F_116
#define F_117 ( T_10 ) ((x) << (PAGE_SHIFT - 10))
F_16 ( L_173
L_174 ,
V_20 . V_289 , V_20 . V_290 , V_20 . V_291 ) ;
return 0 ;
}
static int F_118 ( int V_25 , const char * * V_26 )
{
char V_162 [ 64 ] ;
int V_2 , V_21 , V_38 = 1 ;
unsigned long V_41 , V_292 , V_20 , V_165 = 0 , V_293 = ~ 0UL ;
if ( V_25 < 1 || V_25 > 3 )
return V_29 ;
V_21 = F_18 ( V_25 , V_26 , & V_38 , & V_292 , NULL , NULL ) ;
if ( V_21 )
return V_21 ;
if ( V_25 >= 2 ) {
V_21 = F_12 ( V_26 [ 2 ] , & V_165 ) ;
if ( V_21 )
return V_21 ;
}
if ( ! V_165 )
V_165 = V_183 ;
else if ( V_165 > V_183 )
return V_187 ;
sprintf ( V_162 , L_175 , ( int ) ( 2 * V_165 ) ) ;
if ( V_25 >= 3 ) {
V_21 = F_12 ( V_26 [ 3 ] , & V_293 ) ;
if ( V_21 )
return V_21 ;
if ( ! F_89 ( V_293 ) ) {
F_16 ( L_176 , V_293 ) ;
return V_193 ;
}
}
#ifdef F_119
#define F_120 ( V_2 ) __per_cpu_offset(cpu)
#else
#ifdef V_123
#define F_120 ( V_2 ) __per_cpu_offset[cpu]
#else
#define F_120 ( V_2 ) 0
#endif
#endif
F_94 (cpu) {
if ( F_31 ( V_88 ) )
return 0 ;
if ( V_293 != ~ 0UL && V_293 != V_2 )
continue;
V_41 = V_292 + F_120 ( V_2 ) ;
V_21 = F_63 ( & V_20 , V_41 , V_165 ) ;
if ( V_21 ) {
F_16 ( L_177 V_294 L_178
L_179 , V_2 , V_41 , V_21 ) ;
continue;
}
F_16 ( L_177 , V_2 ) ;
F_61 ( V_162 , V_41 ,
V_165 == V_183 ,
1 , V_165 , 1 , 1 , 0 ) ;
}
#undef F_120
return 0 ;
}
static int F_121 ( int V_25 , const char * * V_26 )
{
F_16 ( L_180 ) ;
F_16 ( L_181 ) ;
F_16 ( L_182 ) ;
F_16 ( L_183 ) ;
F_16 ( L_184
L_185 ) ;
F_16 ( L_186 ) ;
F_16 ( L_187
L_188 ) ;
F_16 ( L_189
L_190 ) ;
return 0 ;
}
int F_122 ( char * V_103 ,
T_11 V_295 ,
char * V_66 ,
char * V_67 ,
short V_296 ,
T_12 V_167 )
{
int V_10 ;
T_4 * V_297 ;
F_34 (kp, i) {
if ( V_297 -> V_92 && ( strcmp ( V_297 -> V_92 , V_103 ) == 0 ) ) {
F_16 ( L_191
L_192 , V_103 , V_295 , V_67 ) ;
return 1 ;
}
}
F_34 (kp, i) {
if ( V_297 -> V_92 == NULL )
break;
}
if ( V_10 >= V_94 ) {
T_4 * V_298 = F_28 ( ( V_94 - V_299 +
V_300 ) * sizeof( * V_298 ) , V_68 ) ;
if ( ! V_298 ) {
F_16 ( L_193
L_194 ) ;
return 1 ;
}
if ( V_301 ) {
memcpy ( V_298 , V_301 ,
( V_94 - V_299 ) * sizeof( * V_298 ) ) ;
F_26 ( V_301 ) ;
}
memset ( V_298 + V_94 , 0 ,
V_300 * sizeof( * V_298 ) ) ;
V_301 = V_298 ;
V_297 = V_301 + V_94 - V_299 ;
V_94 += V_300 ;
}
V_297 -> V_92 = V_103 ;
V_297 -> V_96 = V_295 ;
V_297 -> V_247 = V_66 ;
V_297 -> V_248 = V_67 ;
V_297 -> V_302 = 0 ;
V_297 -> V_93 = V_296 ;
V_297 -> V_98 = V_167 ;
return 0 ;
}
int F_23 ( char * V_103 ,
T_11 V_295 ,
char * V_66 ,
char * V_67 ,
short V_296 )
{
return F_122 ( V_103 , V_295 , V_66 , V_67 , V_296 ,
V_99 ) ;
}
int F_123 ( char * V_103 )
{
int V_10 ;
T_4 * V_297 ;
F_34 (kp, i) {
if ( V_297 -> V_92 && ( strcmp ( V_297 -> V_92 , V_103 ) == 0 ) ) {
V_297 -> V_92 = NULL ;
return 0 ;
}
}
return 1 ;
}
static void T_13 F_124 ( void )
{
int V_10 ;
T_4 * V_297 ;
F_34 (kp, i)
V_297 -> V_92 = NULL ;
F_122 ( L_77 , F_66 , L_195 ,
L_196 , 1 ,
V_100 ) ;
F_122 ( L_76 , F_66 , L_197 ,
L_198 , 0 , V_100 ) ;
F_122 ( L_79 , F_66 , L_199 ,
L_200 , 0 , V_100 ) ;
F_122 ( L_78 , F_66 , L_195 ,
L_201 , 0 , V_100 ) ;
F_122 ( L_202 , F_68 , L_203 ,
L_204 , 0 , V_100 ) ;
F_122 ( L_205 , F_70 , L_206 ,
L_207 , 1 , V_99 ) ;
F_122 ( L_208 , F_71 , L_1 ,
L_209 , 0 , V_99 ) ;
F_122 ( L_210 , F_73 , L_211 ,
L_212 , 0 , V_99 ) ;
F_122 ( L_213 , F_77 , L_195 ,
L_214 , 0 , V_99 ) ;
F_122 ( L_215 , V_303 , L_206 ,
L_216 , 1 , V_99 ) ;
F_122 ( L_217 , V_303 , L_218 ,
L_219 , 0 , V_99 ) ;
F_122 ( L_220 , V_303 , L_221 ,
L_222 , 0 , V_99 ) ;
F_122 ( L_223 , V_303 , L_1 ,
L_224 , 0 , V_99 ) ;
F_122 ( L_225 , V_303 , L_195 ,
L_226 , 0 ,
V_99 ) ;
F_122 ( L_227 , F_103 , L_228 ,
L_229 , 0 , V_99 ) ;
F_122 ( L_230 , F_82 , L_1 ,
L_231 , 0 , V_99 ) ;
F_122 ( L_53 , F_15 , L_1 ,
L_232 , 0 , V_99 ) ;
F_122 ( L_233 , F_105 , L_1 ,
L_234 , 1 , V_99 ) ;
F_122 ( L_235 , F_105 , L_1 ,
L_234 , 0 , V_99 ) ;
F_122 ( L_236 , F_91 , L_237 ,
L_238 , 0 , V_99 ) ;
F_122 ( L_239 , F_104 , L_1 ,
L_240 , 0 , V_99 ) ;
F_122 ( L_241 , F_100 , L_242 ,
L_243 , 0 , V_99 ) ;
F_122 ( L_244 , F_101 , L_245 ,
L_246 , 0 , V_99 ) ;
F_122 ( L_247 , F_40 , L_1 ,
L_248 , 0 , V_99 ) ;
#if F_52 ( V_304 )
F_122 ( L_249 , F_78 , L_1 ,
L_250 , 0 , V_99 ) ;
#endif
#if F_52 ( V_305 )
F_122 ( L_251 , F_75 , L_252 ,
L_253 , 0 , V_99 ) ;
#endif
#if F_52 ( V_306 )
F_122 ( L_254 , F_84 , L_255 ,
L_256 , 0 , V_99 ) ;
#endif
F_122 ( L_257 , F_27 , L_258 ,
L_259 , 0 , V_99 ) ;
F_122 ( L_260 , F_106 , L_261 ,
L_262 , 0 , V_99 ) ;
F_122 ( L_263 , F_112 , L_1 ,
L_264 , 4 , V_99 ) ;
F_122 ( L_265 , F_118 , L_266 ,
L_267 , 3 , V_99 ) ;
F_122 ( L_268 , F_121 , L_1 ,
L_269 , 0 , V_99 ) ;
}
static void T_13 F_125 ( void )
{
int V_10 , V_21 ;
for ( V_10 = 0 ; V_307 [ V_10 ] ; ++ V_10 ) {
V_21 = F_29 ( V_307 [ V_10 ] ) ;
if ( V_21 )
F_16 ( L_270 ,
V_307 [ V_10 ] , V_21 ) ;
}
if ( V_62 ) {
F_16 ( L_271 ) ;
F_29 ( L_11 ) ;
}
}
void T_13 F_126 ( int V_308 )
{
static int V_309 = V_310 ;
int V_10 ;
if ( V_309 == V_311 || V_308 <= V_309 )
return;
for ( V_10 = V_309 ; V_10 < V_308 ; V_10 ++ ) {
switch ( V_10 ) {
case V_310 :
F_124 () ;
F_127 () ;
break;
case V_312 :
F_125 () ;
break;
}
}
V_309 = V_308 ;
}
