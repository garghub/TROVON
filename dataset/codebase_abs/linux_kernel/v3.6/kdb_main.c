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
V_143:
#if F_52 ( V_123 )
snprintf ( V_144 , V_81 , F_6 ( L_53 ) ,
F_50 () ) ;
#else
snprintf ( V_144 , V_81 , F_6 ( L_53 ) ) ;
#endif
if ( V_62 )
strncat ( V_144 , L_54 , V_81 ) ;
V_118 = F_55 ( V_118 , V_81 , V_144 ) ;
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
goto V_143;
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
F_16 ( L_55 , V_118 ) ;
V_21 = 0 ;
}
if ( V_21 == V_97
|| V_21 == V_145
|| V_21 == V_146
|| V_21 == V_127
|| V_21 == V_147 )
break;
if ( V_21 )
F_21 ( V_21 ) ;
}
F_51 ( L_56 , V_21 ) ;
return V_21 ;
}
void F_56 ( const char * V_148 , int V_17 )
{
F_16 ( L_57 ,
V_148 , F_50 () , V_17 , V_149 ,
V_150 ) ;
}
int F_57 ( T_5 V_116 , T_5 V_151 , int error ,
T_6 V_117 , struct V_110 * V_111 )
{
int V_91 = 1 ;
while ( 1 ) {
F_51 ( L_58 , V_116 ) ;
while ( F_54 ( V_152 ) ) {
if ( ! F_54 ( V_153 ) )
F_33 ( V_153 ) ;
}
F_35 ( V_142 ) ;
F_51 ( L_59 , V_116 ) ;
if ( F_54 ( V_154 ) )
break;
V_91 = F_49 ( V_151 , error , V_111 , V_117 ) ;
F_51 ( L_60 , V_91 ) ;
if ( V_91 == V_145 )
break;
if ( V_91 == V_146 ) {
F_33 ( V_155 ) ;
break;
}
if ( V_91 == V_127 ) {
F_33 ( V_155 ) ;
F_33 ( V_156 ) ;
break;
}
if ( V_91 == V_147 ) {
if ( ! F_54 ( V_157 ) )
F_16 ( L_61
L_62 ) ;
break;
}
if ( V_91 && V_91 != 1 && V_91 != V_97 )
F_16 ( L_63 ,
V_91 ) ;
F_51 ( L_64 , V_116 ) ;
break;
}
if ( F_54 ( V_155 ) )
F_35 ( V_158 ) ;
F_58 () ;
return V_91 ;
}
static int F_59 ( unsigned long V_41 , unsigned int V_63 )
{
unsigned char V_159 ;
while ( V_63 -- ) {
if ( F_60 ( V_159 , V_41 ) )
return 0 ;
F_16 ( L_65 , V_159 ) ;
V_41 ++ ;
}
F_16 ( L_29 ) ;
return 0 ;
}
static void F_61 ( const char * V_160 , unsigned long V_41 ,
int V_161 , int V_162 , int V_163 ,
int V_164 , int V_165 , int V_166 )
{
T_3 V_47 ;
char V_80 [ 32 ] ;
char * V_159 = V_80 ;
int V_10 ;
unsigned long V_167 ;
memset ( V_80 , '\0' , sizeof( V_80 ) ) ;
if ( V_166 )
F_16 ( L_66 V_168 L_67 , V_41 ) ;
else
F_16 ( V_168 L_67 , V_41 ) ;
for ( V_10 = 0 ; V_10 < V_164 && V_165 -- ; V_10 ++ ) {
if ( V_166 ) {
if ( F_62 ( & V_167 , V_41 , V_163 ) )
break;
} else if ( F_63 ( & V_167 , V_41 , V_163 ) )
break;
F_16 ( V_160 , V_167 ) ;
if ( V_161 )
F_20 ( V_167 , & V_47 ) ;
else
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
if ( V_47 . V_169 ) {
F_36 ( V_167 , & V_47 , 0 ) ;
if ( ! V_162 ) {
F_16 ( L_29 ) ;
F_16 ( L_68
V_125 L_67
V_125 L_67
V_125 , V_47 . V_170 ,
V_47 . V_171 , V_47 . V_172 ,
V_47 . V_49 , V_47 . V_173 ) ;
}
V_41 += V_163 ;
} else {
union {
T_2 V_167 ;
unsigned char V_159 [ 8 ] ;
} V_174 ;
unsigned char * V_13 ;
#ifdef F_64
V_13 = V_174 . V_159 + 8 - V_163 ;
#else
V_13 = V_174 . V_159 ;
#endif
V_174 . V_167 = V_167 ;
#define F_65 ( V_159 ) \
({unsigned char __c = c; isascii(__c) && isprint(__c) ? __c : '.'; })
switch ( V_163 ) {
case 8 :
* V_159 ++ = F_65 ( * V_13 ++ ) ;
* V_159 ++ = F_65 ( * V_13 ++ ) ;
* V_159 ++ = F_65 ( * V_13 ++ ) ;
* V_159 ++ = F_65 ( * V_13 ++ ) ;
V_41 += 4 ;
case 4 :
* V_159 ++ = F_65 ( * V_13 ++ ) ;
* V_159 ++ = F_65 ( * V_13 ++ ) ;
V_41 += 2 ;
case 2 :
* V_159 ++ = F_65 ( * V_13 ++ ) ;
V_41 ++ ;
case 1 :
* V_159 ++ = F_65 ( * V_13 ++ ) ;
V_41 ++ ;
break;
}
#undef F_65
}
}
F_16 ( L_69 , ( int ) ( ( V_164 - V_10 ) * ( 2 * V_163 + 1 ) + 1 ) ,
L_67 , V_80 ) ;
}
static int F_66 ( int V_25 , const char * * V_26 )
{
static unsigned long V_175 ;
static int V_176 , V_177 , V_178 ;
int V_179 = 16 , V_180 = 8 , V_163 = V_181 , V_165 ;
int V_162 = 0 ;
char V_182 , V_160 [ 64 ] ;
unsigned long V_41 ;
unsigned long V_167 ;
long V_39 = 0 ;
int V_161 = 0 ;
int V_183 = 0 ;
int V_166 = 0 ;
F_11 ( L_70 , & V_180 ) ;
F_11 ( L_71 , & V_179 ) ;
F_11 ( L_72 , & V_163 ) ;
V_165 = V_180 * 16 / V_163 ;
if ( strcmp ( V_26 [ 0 ] , L_73 ) == 0 ) {
if ( V_25 != 2 )
return V_29 ;
V_183 = 1 ;
} else if ( isdigit ( V_26 [ 0 ] [ 2 ] ) ) {
V_163 = ( int ) ( V_26 [ 0 ] [ 2 ] - '0' ) ;
if ( V_163 == 0 ) {
V_163 = V_177 ;
if ( V_163 == 0 )
V_163 = 4 ;
}
V_177 = V_163 ;
V_165 = V_180 * 16 / V_163 ;
if ( ! V_26 [ 0 ] [ 3 ] )
V_183 = 1 ;
else if ( V_26 [ 0 ] [ 3 ] == 'c' && V_26 [ 0 ] [ 4 ] ) {
char * V_3 ;
V_165 = F_10 ( V_26 [ 0 ] + 4 , & V_3 , 10 ) ;
V_180 = ( ( V_165 * V_163 ) + 15 ) / 16 ;
V_183 = ! * V_3 ;
}
V_178 = V_165 ;
} else if ( strcmp ( V_26 [ 0 ] , L_74 ) == 0 )
V_183 = 1 ;
else if ( strcmp ( V_26 [ 0 ] , L_75 ) == 0 )
V_183 = 1 ;
else if ( strcmp ( V_26 [ 0 ] , L_76 ) == 0 ) {
V_166 = V_183 = 1 ;
}
if ( ! V_183 )
return V_90 ;
if ( V_25 == 0 ) {
if ( V_175 == 0 )
return V_29 ;
V_41 = V_175 ;
V_179 = V_176 ;
V_163 = V_177 ;
V_165 = V_178 ;
V_180 = ( ( V_165 * V_163 ) + 15 ) / 16 ;
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
V_180 = ( int ) V_20 ;
V_165 = V_180 * 16 / V_163 ;
}
}
if ( V_25 >= V_38 + 1 ) {
V_21 = F_12 ( V_26 [ V_38 + 1 ] , & V_20 ) ;
if ( ! V_21 )
V_179 = ( int ) V_20 ;
}
}
if ( strcmp ( V_26 [ 0 ] , L_73 ) == 0 )
return F_59 ( V_41 , V_180 ) ;
switch ( V_179 ) {
case 10 :
V_182 = 'd' ;
break;
case 16 :
V_182 = 'x' ;
break;
case 8 :
V_182 = 'o' ;
break;
default:
return V_184 ;
}
V_176 = V_179 ;
if ( V_163 > V_181 )
return V_185 ;
switch ( V_163 ) {
case 8 :
sprintf ( V_160 , L_77 , V_182 ) ;
break;
case 4 :
sprintf ( V_160 , L_78 , V_182 ) ;
break;
case 2 :
sprintf ( V_160 , L_79 , V_182 ) ;
break;
case 1 :
sprintf ( V_160 , L_80 , V_182 ) ;
break;
default:
return V_185 ;
}
V_178 = V_165 ;
V_177 = V_163 ;
if ( strcmp ( V_26 [ 0 ] , L_75 ) == 0 ) {
V_161 = 1 ;
V_163 = V_181 ;
V_165 = V_180 ;
F_11 ( L_81 , & V_162 ) ;
}
V_41 &= ~ ( V_163 - 1 ) ;
while ( V_165 > 0 ) {
unsigned long V_186 ;
int V_187 , V_188 , V_164 = ( V_161 ? 1 : ( 16 / V_163 ) ) ;
if ( F_31 ( V_88 ) )
return 0 ;
for ( V_186 = V_41 , V_188 = 0 ; V_188 < V_165 ; V_186 += V_163 , ++ V_188 ) {
if ( V_166 ) {
if ( F_62 ( & V_167 , V_186 , V_163 )
|| V_167 )
break;
} else if ( F_63 ( & V_167 , V_186 , V_163 ) || V_167 )
break;
}
V_187 = F_67 ( V_164 , V_165 ) ;
F_61 ( V_160 , V_41 , V_161 , V_162 , V_163 ,
V_164 , V_165 , V_166 ) ;
V_41 += V_163 * V_187 ;
V_165 -= V_187 ;
V_188 = ( V_188 + V_164 - 1 ) / V_164 ;
if ( V_188 > 2 ) {
int V_58 = V_164 * ( V_188 - 2 ) ;
F_16 ( V_168 L_82 V_168
L_83 ,
V_41 , V_41 + V_163 * V_58 - 1 ) ;
V_41 += V_163 * V_58 ;
V_165 -= V_58 ;
}
}
V_175 = V_41 ;
return 0 ;
}
static int F_68 ( int V_25 , const char * * V_26 )
{
int V_21 ;
unsigned long V_41 ;
long V_39 = 0 ;
unsigned long V_189 ;
int V_38 ;
int V_190 ;
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
V_21 = F_18 ( V_25 , V_26 , & V_38 , & V_189 , NULL , NULL ) ;
if ( V_21 )
return V_21 ;
if ( V_38 != V_25 + 1 )
return V_29 ;
V_190 = V_26 [ 0 ] [ 2 ] ? ( V_26 [ 0 ] [ 2 ] - '0' ) : ( V_181 ) ;
V_21 = F_69 ( V_41 , V_189 , V_190 ) ;
if ( V_21 )
return V_21 ;
F_16 ( V_125 L_84 V_125 L_29 , V_41 , V_189 ) ;
return 0 ;
}
static int F_70 ( int V_25 , const char * * V_26 )
{
unsigned long V_41 ;
int V_21 ;
int V_38 ;
long V_39 ;
if ( F_50 () != V_149 ) {
F_16 ( L_85
L_86 ,
V_149 ) ;
return V_191 ;
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
if ( F_31 ( V_192 ) ) {
F_16 ( L_87 ) ;
F_16 ( L_88 ,
V_193 ) ;
if ( V_193 == 0 && V_120 ++ == 0 ) {
F_16 ( L_89
L_90 ) ;
return 0 ;
}
if ( V_193 == 2 ) {
F_16 ( L_91 ) ;
F_40 ( 0 , NULL ) ;
}
F_16 ( L_92 ) ;
}
return V_21 ;
}
static int F_71 ( int V_25 , const char * * V_26 )
{
int V_72 = F_17 () ;
#if V_194 > 0
int V_10 ;
char * V_195 ;
int V_196 ;
T_2 V_197 ;
T_7 V_198 ;
T_8 V_199 ;
T_9 V_200 ;
if ( V_72 )
return V_72 ;
for ( V_10 = 0 ; V_10 < V_194 ; V_10 ++ ) {
V_196 = V_201 [ V_10 ] . V_202 * 2 ;
if ( V_196 > 16 )
V_196 = 2 ;
if ( V_72 + strlen ( V_201 [ V_10 ] . V_40 ) + 4 + V_196 > 80 ) {
V_72 = 0 ;
F_16 ( L_29 ) ;
}
if ( V_72 )
V_72 += F_16 ( L_93 ) ;
switch( V_201 [ V_10 ] . V_202 * 8 ) {
case 8 :
V_195 = F_72 ( V_10 , & V_200 , V_36 ) ;
if ( ! V_195 )
break;
V_72 += F_16 ( L_94 , V_195 , V_200 ) ;
break;
case 16 :
V_195 = F_72 ( V_10 , & V_199 , V_36 ) ;
if ( ! V_195 )
break;
V_72 += F_16 ( L_95 , V_195 , V_199 ) ;
break;
case 32 :
V_195 = F_72 ( V_10 , & V_198 , V_36 ) ;
if ( ! V_195 )
break;
V_72 += F_16 ( L_96 , V_195 , V_198 ) ;
break;
case 64 :
V_195 = F_72 ( V_10 , & V_197 , V_36 ) ;
if ( ! V_195 )
break;
V_72 += F_16 ( L_97 , V_195 , V_197 ) ;
break;
default:
V_72 += F_16 ( L_98 , V_201 [ V_10 ] . V_40 ) ;
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
#if V_194 > 0
int V_21 ;
const char * V_195 ;
int V_10 ;
T_2 V_197 ;
T_7 V_198 ;
T_8 V_199 ;
T_9 V_200 ;
if ( V_25 != 2 )
return V_29 ;
V_195 = V_26 [ 1 ] ;
if ( * V_195 == '%' )
V_195 ++ ;
V_21 = F_13 ( V_26 [ 2 ] , & V_197 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_17 () ;
if ( V_21 )
return V_21 ;
V_21 = V_37 ;
for ( V_10 = 0 ; V_10 < V_194 ; V_10 ++ ) {
if ( strcmp ( V_195 , V_201 [ V_10 ] . V_40 ) == 0 ) {
V_21 = 0 ;
break;
}
}
if ( ! V_21 ) {
switch( V_201 [ V_10 ] . V_202 * 8 ) {
case 8 :
V_200 = V_197 ;
F_74 ( V_10 , & V_200 , V_36 ) ;
break;
case 16 :
V_199 = V_197 ;
F_74 ( V_10 , & V_199 , V_36 ) ;
break;
case 32 :
V_198 = V_197 ;
F_74 ( V_10 , & V_198 , V_36 ) ;
break;
case 64 :
F_74 ( V_10 , & V_197 , V_36 ) ;
break;
}
}
return V_21 ;
#else
F_16 ( L_99 ) ;
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
struct V_203 * V_204 ;
if ( V_25 != 0 )
return V_29 ;
F_16 ( L_100 ) ;
F_79 (mod, kdb_modules, list) {
F_16 ( L_101 , V_204 -> V_40 ,
V_204 -> V_205 , ( void * ) V_204 ) ;
#ifdef F_80
F_16 ( L_102 , F_81 ( V_204 ) ) ;
#endif
if ( V_204 -> V_206 == V_207 )
F_16 ( L_103 ) ;
else if ( V_204 -> V_206 == V_208 )
F_16 ( L_104 ) ;
else
F_16 ( L_105 ) ;
F_16 ( L_106 , V_204 -> V_209 ) ;
#ifdef F_80
{
struct V_210 * V_211 ;
F_16 ( L_107 ) ;
F_79 (use, &mod->source_list,
source_list)
F_16 ( L_108 , V_211 -> V_212 -> V_40 ) ;
F_16 ( L_109 ) ;
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
F_16 ( L_110 , V_8 [ V_10 ] ) ;
}
if ( F_83 ( V_213 ) )
F_16 ( L_111 , V_32 ) ;
return 0 ;
}
static int F_84 ( int V_25 , const char * * V_26 )
{
int V_21 ;
int V_214 ;
int V_215 = 0 ;
int V_216 = 0 ;
int V_187 = 0 ;
int V_217 = 0 ;
struct V_218 V_219 = { . V_220 = 1 } ;
T_1 V_72 ;
char V_221 [ 201 ] ;
if ( V_25 > 2 )
return V_29 ;
if ( V_25 ) {
char * V_13 ;
V_215 = F_85 ( V_26 [ 1 ] , & V_13 , 0 ) ;
if ( * V_13 )
V_215 = 0 ;
if ( V_25 > 1 ) {
V_216 = F_10 ( V_26 [ 2 ] , & V_13 , 0 ) ;
if ( * V_13 || V_216 < 0 )
V_216 = 0 ;
}
}
V_21 = F_11 ( L_112 , & V_214 ) ;
if ( ! V_21 && V_214 ) {
const char * V_222 [] = { L_113 , L_112 , L_114 } ;
F_15 ( 2 , V_222 ) ;
}
F_86 ( & V_219 ) ;
while ( F_87 ( & V_219 , 1 , NULL , 0 , NULL ) )
V_187 ++ ;
if ( V_215 < 0 ) {
if ( V_216 >= V_187 )
F_16 ( L_115
L_116 , V_187 ) ;
else if ( V_216 - V_215 >= V_187 )
F_16 ( L_117
L_118 , V_187 , V_187 - V_216 ) ;
V_217 = V_216 ;
V_215 = abs ( V_215 ) ;
} else if ( V_215 > 0 ) {
V_217 = V_187 - V_215 - V_216 ;
V_215 = abs ( V_215 ) ;
if ( V_216 >= V_187 ) {
F_16 ( L_119
L_120 , V_187 ) ;
V_217 = V_187 ;
} else if ( V_217 < 0 ) {
V_215 += V_217 ;
V_217 = 0 ;
F_16 ( L_121
L_122 , V_187 , V_215 ) ;
}
} else {
V_215 = V_187 ;
}
if ( V_217 >= V_187 || V_217 < 0 )
return 0 ;
F_86 ( & V_219 ) ;
while ( F_87 ( & V_219 , 1 , V_221 , sizeof( V_221 ) , & V_72 ) ) {
if ( V_217 ) {
V_217 -- ;
continue;
}
if ( ! V_215 -- )
break;
F_16 ( L_123 , ( int ) V_72 - 1 , V_221 ) ;
}
return 0 ;
}
static void F_88 ( void )
{
int V_10 , V_223 , V_224 = 1 ;
char V_206 , V_225 = '?' ;
F_16 ( L_124 , F_50 () ) ;
F_16 ( L_125 ) ;
for ( V_223 = - 1 , V_10 = 0 ; V_10 < V_226 ; V_10 ++ ) {
if ( ! F_89 ( V_10 ) ) {
V_206 = 'F' ;
} else {
V_206 = ' ' ;
if ( F_90 ( F_5 ( V_10 ) ) == 'I' )
V_206 = 'I' ;
}
if ( V_206 != V_225 ) {
if ( V_225 != '?' ) {
if ( ! V_224 )
F_16 ( L_126 ) ;
V_224 = 0 ;
F_16 ( L_127 , V_223 ) ;
if ( V_223 < V_10 - 1 )
F_16 ( L_128 , V_10 - 1 ) ;
if ( V_225 != ' ' )
F_16 ( L_129 , V_225 ) ;
}
V_225 = V_206 ;
V_223 = V_10 ;
}
}
if ( V_225 != 'F' ) {
if ( ! V_224 )
F_16 ( L_126 ) ;
F_16 ( L_127 , V_223 ) ;
if ( V_223 < V_10 - 1 )
F_16 ( L_128 , V_10 - 1 ) ;
if ( V_225 != ' ' )
F_16 ( L_129 , V_225 ) ;
}
F_16 ( L_29 ) ;
}
static int F_91 ( int V_25 , const char * * V_26 )
{
unsigned long V_227 ;
int V_21 ;
if ( V_25 == 0 ) {
F_88 () ;
return 0 ;
}
if ( V_25 != 1 )
return V_29 ;
V_21 = F_12 ( V_26 [ 1 ] , & V_227 ) ;
if ( V_21 )
return V_21 ;
if ( ( V_227 > V_226 ) || ! F_89 ( V_227 ) )
return V_191 ;
V_228 = V_227 ;
return V_145 ;
}
void F_92 ( void )
{
int V_229 = 0 , V_230 = 0 ;
unsigned long V_231 = F_93 ( L_130 ) ,
V_232 = F_93 ( L_131 ) ;
unsigned long V_2 ;
const struct V_1 * V_3 , * V_233 ;
F_94 (cpu) {
V_3 = F_1 ( V_2 ) ;
if ( F_95 ( V_3 , V_231 ) )
++ V_229 ;
}
F_96 (g, p) {
if ( F_95 ( V_3 , V_232 ) )
++ V_230 ;
} F_97 ( V_233 , V_3 ) ;
if ( V_229 || V_230 ) {
if ( V_229 )
F_16 ( L_132 ,
V_229 , V_229 == 1 ? L_1 : L_133 ,
V_230 ? L_134 : L_1 ) ;
if ( V_230 )
F_16 ( L_135
L_136 , V_230 ,
V_230 == 1 ? L_1 : L_133 ) ;
F_16 ( L_137 ) ;
}
}
void F_98 ( const struct V_1 * V_3 )
{
int V_2 ;
unsigned long V_234 ;
if ( ! V_3 || F_99 ( & V_234 , ( char * ) V_3 , sizeof( unsigned long ) ) )
return;
V_2 = F_48 ( V_3 ) ;
F_16 ( L_138 ,
( void * ) V_3 , V_3 -> V_122 , V_3 -> V_235 -> V_122 ,
F_46 ( V_3 ) , F_48 ( V_3 ) ,
F_90 ( V_3 ) ,
( void * ) ( & V_3 -> V_236 ) ,
V_3 == F_1 ( F_50 () ) ? '*' : ' ' ,
V_3 -> V_237 ) ;
if ( F_46 ( V_3 ) ) {
if ( ! F_5 ( V_2 ) ) {
F_16 ( L_139 ) ;
} else {
if ( F_5 ( V_2 ) != V_3 )
F_16 ( L_140
L_141 , F_5 ( V_2 ) ) ;
}
}
}
static int F_100 ( int V_25 , const char * * V_26 )
{
struct V_1 * V_233 , * V_3 ;
unsigned long V_238 , V_2 ;
if ( V_25 == 0 )
F_92 () ;
F_16 ( L_142 ,
( int ) ( 2 * sizeof( void * ) ) + 2 , L_143 ,
( int ) ( 2 * sizeof( void * ) ) + 2 , L_144 ) ;
V_238 = F_93 ( V_25 ? V_26 [ 1 ] : NULL ) ;
F_94 (cpu) {
if ( F_31 ( V_88 ) )
return 0 ;
V_3 = F_1 ( V_2 ) ;
if ( F_95 ( V_3 , V_238 ) )
F_98 ( V_3 ) ;
}
F_16 ( L_29 ) ;
F_96 (g, p) {
if ( F_31 ( V_88 ) )
return 0 ;
if ( F_95 ( V_3 , V_238 ) )
F_98 ( V_3 ) ;
} F_97 ( V_233 , V_3 ) ;
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
if ( strcmp ( V_26 [ 1 ] , L_145 ) == 0 ) {
V_3 = F_5 ( V_149 ) ;
} else {
V_21 = F_12 ( V_26 [ 1 ] , & V_20 ) ;
if ( V_21 )
return V_24 ;
V_3 = F_102 ( ( V_239 ) V_20 , & V_240 ) ;
if ( ! V_3 ) {
F_16 ( L_146 , ( V_239 ) V_20 ) ;
return 0 ;
}
}
F_45 ( V_3 ) ;
}
F_16 ( L_147 ,
V_115 -> V_237 ,
V_115 -> V_122 ) ;
return 0 ;
}
static int F_103 ( int V_25 , const char * * V_26 )
{
int V_21 = 0 ;
unsigned long V_41 ;
long V_39 = 0 ;
unsigned long V_241 ;
unsigned long V_242 ;
int V_38 ;
const char * V_61 ;
if ( V_25 != 3 )
return V_29 ;
V_38 = 1 ;
V_21 = F_18 ( V_25 , V_26 , & V_38 , & V_41 , & V_39 , NULL ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_26 [ 2 ] , & V_242 ) ;
if ( V_21 )
return V_21 ;
V_241 = V_41 ;
V_61 = F_25 ( V_26 [ 3 ] , V_68 ) ;
if ( ! V_61 ) {
F_16 ( L_148 , V_243 ) ;
return 0 ;
}
V_26 = NULL ;
while ( V_241 ) {
char V_221 [ 80 ] ;
if ( F_31 ( V_88 ) )
goto V_244;
sprintf ( V_221 , L_108 V_125 L_29 , V_61 , V_241 ) ;
V_21 = F_29 ( V_221 ) ;
if ( V_21 )
goto V_244;
V_41 = V_241 + V_242 ;
if ( F_63 ( & V_241 , V_41 , sizeof( V_241 ) ) )
goto V_244;
}
V_244:
F_26 ( V_61 ) ;
return V_21 ;
}
static int F_104 ( int V_25 , const char * * V_26 )
{
return V_147 ;
}
static int F_105 ( int V_25 , const char * * V_26 )
{
T_4 * V_245 ;
int V_10 ;
F_16 ( L_149 , L_150 , L_151 , L_152 ) ;
F_16 ( L_153
L_154 ) ;
F_34 (kt, i) {
if ( V_245 -> V_92 )
F_16 ( L_149 , V_245 -> V_92 ,
V_245 -> V_246 , V_245 -> V_247 ) ;
if ( F_31 ( V_88 ) )
return 0 ;
}
return 0 ;
}
static int F_106 ( int V_25 , const char * * V_26 )
{
long V_248 , V_122 ;
char * V_23 ;
struct V_1 * V_3 ;
struct V_249 V_250 ;
if ( V_25 != 2 )
return V_29 ;
V_248 = F_85 ( V_26 [ 1 ] , & V_23 , 0 ) ;
if ( * V_23 )
return V_24 ;
if ( V_248 >= 0 ) {
F_16 ( L_155 ) ;
return 0 ;
}
V_248 = - V_248 ;
V_122 = F_85 ( V_26 [ 2 ] , & V_23 , 0 ) ;
if ( * V_23 )
return V_24 ;
if ( V_122 <= 0 ) {
F_16 ( L_156 ) ;
return 0 ;
}
V_3 = F_102 ( V_122 , & V_240 ) ;
if ( ! V_3 ) {
F_16 ( L_157 ) ;
return 0 ;
}
V_3 = V_3 -> V_251 ;
V_250 . V_252 = V_248 ;
V_250 . V_253 = 0 ;
V_250 . V_254 = V_255 ;
V_250 . V_256 = V_122 ;
V_250 . V_257 = 0 ;
F_107 ( V_3 , & V_250 ) ;
return 0 ;
}
static void F_108 ( struct V_258 * V_259 , struct V_260 * V_261 )
{
static int V_262 [] = { 31 , 29 , 31 , 30 , 31 , 30 , 31 ,
31 , 30 , 31 , 30 , 31 } ;
memset ( V_261 , 0 , sizeof( * V_261 ) ) ;
V_261 -> V_263 = V_259 -> V_264 % ( 24 * 60 * 60 ) ;
V_261 -> V_265 = V_259 -> V_264 / ( 24 * 60 * 60 ) +
( 2 * 365 + 1 ) ;
V_261 -> V_266 = V_261 -> V_263 / 60 % 60 ;
V_261 -> V_267 = V_261 -> V_263 / 60 / 60 ;
V_261 -> V_263 = V_261 -> V_263 % 60 ;
V_261 -> V_268 = 68 + 4 * ( V_261 -> V_265 / ( 4 * 365 + 1 ) ) ;
V_261 -> V_265 %= ( 4 * 365 + 1 ) ;
V_262 [ 1 ] = 29 ;
while ( V_261 -> V_265 >= V_262 [ V_261 -> V_269 ] ) {
V_261 -> V_265 -= V_262 [ V_261 -> V_269 ] ;
if ( ++ V_261 -> V_269 == 12 ) {
V_261 -> V_269 = 0 ;
++ V_261 -> V_268 ;
V_262 [ 1 ] = 28 ;
}
}
++ V_261 -> V_265 ;
}
static void F_109 ( struct V_270 * V_20 )
{
struct V_258 V_271 ;
F_110 ( & V_271 ) ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_271 = V_271 . V_264 ;
V_20 -> V_272 [ 0 ] = V_273 [ 0 ] ;
V_20 -> V_272 [ 1 ] = V_273 [ 1 ] ;
V_20 -> V_272 [ 2 ] = V_273 [ 2 ] ;
V_20 -> V_274 = V_275 - 1 ;
F_111 ( V_20 ) ;
return;
}
static int F_112 ( int V_25 , const char * * V_26 )
{
struct V_258 V_276 ;
struct V_260 V_261 ;
struct V_270 V_20 ;
if ( V_25 )
return V_29 ;
F_16 ( L_158 , V_277 . V_40 . V_278 ) ;
F_16 ( L_159 , V_277 . V_40 . V_279 ) ;
F_16 ( L_160 , V_277 . V_40 . V_280 ) ;
F_16 ( L_161 , V_277 . V_40 . V_281 ) ;
F_16 ( L_162 , V_277 . V_40 . V_282 ) ;
F_16 ( L_163 , V_277 . V_40 . V_283 ) ;
F_16 ( L_164 , F_113 ( V_284 ) ) ;
V_276 = F_114 () ;
F_108 ( & V_276 , & V_261 ) ;
F_16 ( L_165
L_166 ,
1900 + V_261 . V_268 , V_261 . V_269 + 1 , V_261 . V_265 ,
V_261 . V_267 , V_261 . V_266 , V_261 . V_263 ,
V_285 . V_286 ) ;
F_109 ( & V_20 ) ;
F_16 ( L_167 ) ;
if ( V_20 . V_271 > ( 24 * 60 * 60 ) ) {
int V_287 = V_20 . V_271 / ( 24 * 60 * 60 ) ;
V_20 . V_271 %= ( 24 * 60 * 60 ) ;
F_16 ( L_168 , V_287 , V_287 == 1 ? L_1 : L_169 ) ;
}
F_16 ( L_170 , V_20 . V_271 / ( 60 * 60 ) , ( V_20 . V_271 / 60 ) % 60 ) ;
#define F_115 ( T_10 ) ((x) >> FSHIFT)
#define F_116 ( T_10 ) LOAD_INT(((x) & (FIXED_1-1)) * 100)
F_16 ( L_171 ,
F_115 ( V_20 . V_272 [ 0 ] ) , F_116 ( V_20 . V_272 [ 0 ] ) ,
F_115 ( V_20 . V_272 [ 1 ] ) , F_116 ( V_20 . V_272 [ 1 ] ) ,
F_115 ( V_20 . V_272 [ 2 ] ) , F_116 ( V_20 . V_272 [ 2 ] ) ) ;
#undef F_115
#undef F_116
#define F_117 ( T_10 ) ((x) << (PAGE_SHIFT - 10))
F_16 ( L_172
L_173 ,
V_20 . V_288 , V_20 . V_289 , V_20 . V_290 ) ;
return 0 ;
}
static int F_118 ( int V_25 , const char * * V_26 )
{
char V_160 [ 64 ] ;
int V_2 , V_21 , V_38 = 1 ;
unsigned long V_41 , V_291 , V_20 , V_163 = 0 , V_292 = ~ 0UL ;
if ( V_25 < 1 || V_25 > 3 )
return V_29 ;
V_21 = F_18 ( V_25 , V_26 , & V_38 , & V_291 , NULL , NULL ) ;
if ( V_21 )
return V_21 ;
if ( V_25 >= 2 ) {
V_21 = F_12 ( V_26 [ 2 ] , & V_163 ) ;
if ( V_21 )
return V_21 ;
}
if ( ! V_163 )
V_163 = V_181 ;
else if ( V_163 > V_181 )
return V_185 ;
sprintf ( V_160 , L_174 , ( int ) ( 2 * V_163 ) ) ;
if ( V_25 >= 3 ) {
V_21 = F_12 ( V_26 [ 3 ] , & V_292 ) ;
if ( V_21 )
return V_21 ;
if ( ! F_89 ( V_292 ) ) {
F_16 ( L_175 , V_292 ) ;
return V_191 ;
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
if ( V_292 != ~ 0UL && V_292 != V_2 )
continue;
V_41 = V_291 + F_120 ( V_2 ) ;
V_21 = F_63 ( & V_20 , V_41 , V_163 ) ;
if ( V_21 ) {
F_16 ( L_176 V_293 L_177
L_178 , V_2 , V_41 , V_21 ) ;
continue;
}
F_16 ( L_176 , V_2 ) ;
F_61 ( V_160 , V_41 ,
V_163 == V_181 ,
1 , V_163 , 1 , 1 , 0 ) ;
}
#undef F_120
return 0 ;
}
static int F_121 ( int V_25 , const char * * V_26 )
{
F_16 ( L_179 ) ;
F_16 ( L_180 ) ;
F_16 ( L_181 ) ;
F_16 ( L_182 ) ;
F_16 ( L_183
L_184 ) ;
F_16 ( L_185 ) ;
F_16 ( L_186
L_187 ) ;
F_16 ( L_188
L_189 ) ;
return 0 ;
}
int F_122 ( char * V_103 ,
T_11 V_294 ,
char * V_66 ,
char * V_67 ,
short V_295 ,
T_12 V_165 )
{
int V_10 ;
T_4 * V_296 ;
F_34 (kp, i) {
if ( V_296 -> V_92 && ( strcmp ( V_296 -> V_92 , V_103 ) == 0 ) ) {
F_16 ( L_190
L_191 , V_103 , V_294 , V_67 ) ;
return 1 ;
}
}
F_34 (kp, i) {
if ( V_296 -> V_92 == NULL )
break;
}
if ( V_10 >= V_94 ) {
T_4 * V_297 = F_28 ( ( V_94 - V_298 +
V_299 ) * sizeof( * V_297 ) , V_68 ) ;
if ( ! V_297 ) {
F_16 ( L_192
L_193 ) ;
return 1 ;
}
if ( V_300 ) {
memcpy ( V_297 , V_300 ,
( V_94 - V_298 ) * sizeof( * V_297 ) ) ;
F_26 ( V_300 ) ;
}
memset ( V_297 + V_94 , 0 ,
V_299 * sizeof( * V_297 ) ) ;
V_300 = V_297 ;
V_296 = V_300 + V_94 - V_298 ;
V_94 += V_299 ;
}
V_296 -> V_92 = V_103 ;
V_296 -> V_96 = V_294 ;
V_296 -> V_246 = V_66 ;
V_296 -> V_247 = V_67 ;
V_296 -> V_301 = 0 ;
V_296 -> V_93 = V_295 ;
V_296 -> V_98 = V_165 ;
return 0 ;
}
int F_23 ( char * V_103 ,
T_11 V_294 ,
char * V_66 ,
char * V_67 ,
short V_295 )
{
return F_122 ( V_103 , V_294 , V_66 , V_67 , V_295 ,
V_99 ) ;
}
int F_123 ( char * V_103 )
{
int V_10 ;
T_4 * V_296 ;
F_34 (kp, i) {
if ( V_296 -> V_92 && ( strcmp ( V_296 -> V_92 , V_103 ) == 0 ) ) {
V_296 -> V_92 = NULL ;
return 0 ;
}
}
return 1 ;
}
static void T_13 F_124 ( void )
{
int V_10 ;
T_4 * V_296 ;
F_34 (kp, i)
V_296 -> V_92 = NULL ;
F_122 ( L_74 , F_66 , L_194 ,
L_195 , 1 ,
V_100 ) ;
F_122 ( L_73 , F_66 , L_196 ,
L_197 , 0 , V_100 ) ;
F_122 ( L_76 , F_66 , L_198 ,
L_199 , 0 , V_100 ) ;
F_122 ( L_75 , F_66 , L_194 ,
L_200 , 0 , V_100 ) ;
F_122 ( L_201 , F_68 , L_202 ,
L_203 , 0 , V_100 ) ;
F_122 ( L_204 , F_70 , L_205 ,
L_206 , 1 , V_99 ) ;
F_122 ( L_207 , F_71 , L_1 ,
L_208 , 0 , V_99 ) ;
F_122 ( L_209 , F_73 , L_210 ,
L_211 , 0 , V_99 ) ;
F_122 ( L_212 , F_77 , L_194 ,
L_213 , 0 , V_99 ) ;
F_122 ( L_214 , V_302 , L_205 ,
L_215 , 1 , V_99 ) ;
F_122 ( L_216 , V_302 , L_217 ,
L_218 , 0 , V_99 ) ;
F_122 ( L_219 , V_302 , L_220 ,
L_221 , 0 , V_99 ) ;
F_122 ( L_222 , V_302 , L_1 ,
L_223 , 0 , V_99 ) ;
F_122 ( L_224 , V_302 , L_194 ,
L_225 , 0 ,
V_99 ) ;
F_122 ( L_226 , F_103 , L_227 ,
L_228 , 0 , V_99 ) ;
F_122 ( L_229 , F_82 , L_1 ,
L_230 , 0 , V_99 ) ;
F_122 ( L_113 , F_15 , L_1 ,
L_231 , 0 , V_99 ) ;
F_122 ( L_232 , F_105 , L_1 ,
L_233 , 1 , V_99 ) ;
F_122 ( L_234 , F_105 , L_1 ,
L_233 , 0 , V_99 ) ;
F_122 ( L_235 , F_91 , L_236 ,
L_237 , 0 , V_99 ) ;
F_122 ( L_238 , F_104 , L_1 ,
L_239 , 0 , V_99 ) ;
F_122 ( L_240 , F_100 , L_241 ,
L_242 , 0 , V_99 ) ;
F_122 ( L_243 , F_101 , L_244 ,
L_245 , 0 , V_99 ) ;
F_122 ( L_246 , F_40 , L_1 ,
L_247 , 0 , V_99 ) ;
#if F_52 ( V_303 )
F_122 ( L_248 , F_78 , L_1 ,
L_249 , 0 , V_99 ) ;
#endif
#if F_52 ( V_304 )
F_122 ( L_250 , F_75 , L_251 ,
L_252 , 0 , V_99 ) ;
#endif
#if F_52 ( V_305 )
F_122 ( L_253 , F_84 , L_254 ,
L_255 , 0 , V_99 ) ;
#endif
F_122 ( L_256 , F_27 , L_257 ,
L_258 , 0 , V_99 ) ;
F_122 ( L_259 , F_106 , L_260 ,
L_261 , 0 , V_99 ) ;
F_122 ( L_262 , F_112 , L_1 ,
L_263 , 4 , V_99 ) ;
F_122 ( L_264 , F_118 , L_265 ,
L_266 , 3 , V_99 ) ;
F_122 ( L_267 , F_121 , L_1 ,
L_268 , 0 , V_99 ) ;
}
static void T_13 F_125 ( void )
{
int V_10 , V_21 ;
for ( V_10 = 0 ; V_306 [ V_10 ] ; ++ V_10 ) {
V_21 = F_29 ( V_306 [ V_10 ] ) ;
if ( V_21 )
F_16 ( L_269 ,
V_306 [ V_10 ] , V_21 ) ;
}
if ( V_62 ) {
F_16 ( L_270 ) ;
F_29 ( L_11 ) ;
}
}
void T_13 F_126 ( int V_307 )
{
static int V_308 = V_309 ;
int V_10 ;
if ( V_308 == V_310 || V_307 <= V_308 )
return;
for ( V_10 = V_308 ; V_10 < V_307 ; V_10 ++ ) {
switch ( V_10 ) {
case V_309 :
F_124 () ;
F_127 () ;
break;
case V_311 :
F_125 () ;
break;
}
}
V_308 = V_307 ;
}
