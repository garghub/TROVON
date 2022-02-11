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
if ( F_28 () ) {
F_16 ( L_17 ) ;
return V_48 ;
}
V_57 = F_29 ( ( V_59 + 1 ) * sizeof( * V_57 ) ,
V_68 ) ;
if ( ! V_57 )
goto V_70;
memcpy ( V_57 , V_69 ,
V_59 * sizeof( * V_57 ) ) ;
V_58 = V_57 + V_59 ;
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
V_58 -> V_64 = 1 ;
V_58 -> V_40 = F_25 ( V_26 [ 1 ] , V_68 ) ;
if ( ! V_58 -> V_40 )
goto V_71;
V_58 -> V_66 = F_25 ( V_26 [ 2 ] , V_68 ) ;
if ( ! V_58 -> V_66 )
goto V_72;
V_58 -> V_67 = F_25 ( V_26 [ 3 ] , V_68 ) ;
if ( ! V_58 -> V_67 )
goto V_73;
if ( V_58 -> V_66 [ 0 ] == '"' ) {
strcpy ( V_58 -> V_66 , V_26 [ 2 ] + 1 ) ;
V_58 -> V_66 [ strlen ( V_58 -> V_66 ) - 1 ] = '\0' ;
}
if ( V_58 -> V_67 [ 0 ] == '"' ) {
strcpy ( V_58 -> V_67 , V_26 [ 3 ] + 1 ) ;
V_58 -> V_67 [ strlen ( V_58 -> V_67 ) - 1 ] = '\0' ;
}
++ V_59 ;
V_62 = 1 ;
F_26 ( V_69 ) ;
return 0 ;
V_73:
F_26 ( V_58 -> V_66 ) ;
V_72:
F_26 ( V_58 -> V_40 ) ;
V_71:
F_26 ( V_57 ) ;
V_70:
F_16 ( L_18 , V_26 [ 1 ] ) ;
V_57 = V_69 ;
return V_48 ;
}
static int V_65 ( int V_25 , const char * * V_26 )
{
int V_10 , V_74 ;
struct V_57 * V_58 ;
if ( V_25 != 0 )
return V_29 ;
for ( V_58 = V_57 , V_10 = 0 ; V_10 < V_59 ; ++ V_10 , ++ V_58 ) {
if ( strcmp ( V_58 -> V_40 , V_26 [ 0 ] ) == 0 )
break;
}
if ( V_10 == V_59 ) {
F_16 ( L_19 ,
V_26 [ 0 ] ) ;
return V_48 ;
}
for ( V_10 = 0 ; V_10 < V_58 -> V_63 ; ++ V_10 ) {
V_26 = NULL ;
F_16 ( L_20 , V_58 -> V_40 , V_58 -> V_61 [ V_10 ] ) ;
V_74 = F_30 ( V_58 -> V_61 [ V_10 ] ) ;
if ( V_74 )
return V_74 ;
}
return 0 ;
}
static void F_31 ( const char * V_75 )
{
int V_76 ;
char * V_13 = ( char * ) V_75 , * V_77 ;
if ( * V_13 != '|' )
return;
V_13 ++ ;
while ( isspace ( * V_13 ) )
V_13 ++ ;
if ( strncmp ( V_13 , L_21 , 5 ) ) {
F_16 ( L_22 ) ;
return;
}
V_13 += 5 ;
while ( isspace ( * V_13 ) )
V_13 ++ ;
V_77 = strchr ( V_13 , '\n' ) ;
if ( V_77 )
* V_77 = '\0' ;
V_76 = strlen ( V_13 ) ;
if ( V_76 == 0 ) {
F_16 ( L_22 ) ;
return;
}
if ( * V_13 == '"' ) {
V_13 ++ ;
V_77 = strchr ( V_13 , '"' ) ;
if ( ! V_77 ) {
F_16 ( L_23 ) ;
return;
}
* V_77 = '\0' ;
}
V_78 = 0 ;
if ( * V_13 == '^' ) {
V_78 = 1 ;
V_13 ++ ;
}
V_76 = strlen ( V_13 ) ;
V_79 = 0 ;
if ( * ( V_13 + V_76 - 1 ) == '$' ) {
V_79 = 1 ;
* ( V_13 + V_76 - 1 ) = '\0' ;
}
V_76 = strlen ( V_13 ) ;
if ( ! V_76 )
return;
if ( V_76 >= V_80 ) {
F_16 ( L_24 ) ;
return;
}
strcpy ( V_81 , V_13 ) ;
V_82 ++ ;
return;
}
int F_30 ( const char * V_55 )
{
static char * V_26 [ V_83 ] ;
static int V_25 ;
static char V_84 [ V_85 + 2 ] ;
char * V_13 ;
char * V_86 , V_87 ;
T_4 * V_88 ;
int V_10 , V_89 , V_90 = 0 , V_91 ;
V_13 = ( char * ) V_55 ;
V_82 = V_91 = 0 ;
if ( F_32 ( V_92 ) ) {
F_33 ( V_92 ) ;
F_34 ( V_93 ) ;
V_25 = 0 ;
}
if ( * V_13 != '\n' && * V_13 != '\0' ) {
V_25 = 0 ;
V_86 = V_84 ;
while ( * V_13 ) {
while ( isspace ( * V_13 ) )
V_13 ++ ;
if ( ( * V_13 == '\0' ) || ( * V_13 == '\n' ) ||
( * V_13 == '#' && ! V_62 ) )
break;
if ( * V_13 == '|' ) {
V_91 ++ ;
break;
}
if ( V_86 >= V_84 + V_85 ) {
F_16 ( L_25
L_26 ,
V_55 ) ;
return V_94 ;
}
if ( V_25 >= V_83 - 1 ) {
F_16 ( L_27
L_28 , V_55 ) ;
return V_94 ;
}
V_26 [ V_25 ++ ] = V_86 ;
V_89 = 0 ;
V_87 = '\0' ;
while ( * V_13 && * V_13 != '\n' &&
( V_89 || V_87 || ! isspace ( * V_13 ) ) ) {
if ( V_86 >= V_84 + V_85 )
break;
if ( V_89 ) {
V_89 = 0 ;
* V_86 ++ = * V_13 ++ ;
continue;
}
if ( * V_13 == '\\' ) {
V_89 = 1 ;
++ V_13 ;
continue;
}
if ( * V_13 == V_87 )
V_87 = '\0' ;
else if ( * V_13 == '\'' || * V_13 == '"' )
V_87 = * V_13 ;
* V_86 = * V_13 ++ ;
if ( * V_86 == '=' && ! V_87 )
break;
++ V_86 ;
}
* V_86 ++ = '\0' ;
}
}
if ( ! V_25 )
return 0 ;
if ( V_91 )
F_31 ( V_13 ) ;
if ( V_62 ) {
int V_95 = F_22 ( V_55 , V_26 [ 0 ] ) ;
if ( ! V_62 ) {
V_25 = 0 ;
* ( V_26 [ 0 ] ) = '\0' ;
}
return V_95 ;
}
if ( V_26 [ 0 ] [ 0 ] == '-' && V_26 [ 0 ] [ 1 ] &&
( V_26 [ 0 ] [ 1 ] < '0' || V_26 [ 0 ] [ 1 ] > '9' ) ) {
V_90 = 1 ;
++ V_26 [ 0 ] ;
}
F_35 (tp, i) {
if ( V_88 -> V_96 ) {
if ( V_88 -> V_97
&& ( strlen ( V_26 [ 0 ] ) <= V_88 -> V_97 ) ) {
if ( strncmp ( V_26 [ 0 ] ,
V_88 -> V_96 ,
V_88 -> V_97 ) == 0 ) {
break;
}
}
if ( strcmp ( V_26 [ 0 ] , V_88 -> V_96 ) == 0 )
break;
}
}
if ( V_10 == V_98 ) {
F_35 (tp, i) {
if ( V_88 -> V_96 ) {
if ( strncmp ( V_26 [ 0 ] ,
V_88 -> V_96 ,
strlen ( V_88 -> V_96 ) ) == 0 ) {
break;
}
}
}
}
if ( V_10 < V_98 ) {
int V_95 ;
F_34 ( V_99 ) ;
V_95 = (* V_88 -> V_100 )( V_25 - 1 , ( const char * * ) V_26 ) ;
if ( V_95 && V_90 && V_95 > V_101 )
V_95 = 0 ;
F_36 ( V_99 ) ;
switch ( V_88 -> V_102 ) {
case V_103 :
V_25 = 0 ;
if ( V_26 [ 0 ] )
* ( V_26 [ 0 ] ) = '\0' ;
break;
case V_104 :
V_25 = 1 ;
if ( V_26 [ 1 ] )
* ( V_26 [ 1 ] ) = '\0' ;
break;
case V_105 :
break;
}
return V_95 ;
}
{
unsigned long V_17 ;
char * V_40 = NULL ;
long V_39 ;
int V_38 = 0 ;
if ( F_18 ( 0 , ( const char * * ) V_26 , & V_38 ,
& V_17 , & V_39 , & V_40 ) ) {
return V_94 ;
}
F_16 ( L_29 , V_26 [ 0 ] ) ;
F_37 ( V_17 , NULL , V_106 ) ;
F_16 ( L_30 ) ;
return 0 ;
}
}
static int F_38 ( char * V_107 )
{
#define F_39 16
#define F_40 14
if ( V_108 == V_109 )
return 0 ;
switch ( * V_107 ) {
case F_39 :
if ( V_110 != V_109 )
V_110 = ( V_110 - 1 ) % V_111 ;
strncpy ( V_112 , V_113 [ V_110 ] , V_85 ) ;
return 1 ;
case F_40 :
if ( V_110 != V_108 )
V_110 = ( V_110 + 1 ) % V_111 ;
strncpy ( V_112 , V_113 [ V_110 ] , V_85 ) ;
return 1 ;
}
return 0 ;
}
static int F_41 ( int V_25 , const char * * V_26 )
{
F_42 () ;
F_16 ( L_31 ) ;
while ( 1 )
F_43 () ;
return 0 ;
}
static void F_44 ( struct V_114 * V_115 )
{
int V_116 = V_117 ;
V_117 = 15 ;
V_118 ++ ;
F_45 ( V_115 ) ;
V_118 -- ;
F_16 ( L_30 ) ;
V_117 = V_116 ;
}
void F_46 ( struct V_1 * V_3 )
{
V_119 = V_3 ;
if ( F_47 ( V_3 ) ) {
V_36 = F_48 ( F_49 ( V_3 ) ) ;
return;
}
V_36 = NULL ;
}
static int F_50 ( T_5 V_120 , int error , struct V_114 * V_115 ,
T_6 V_121 )
{
char * V_122 ;
int V_21 ;
struct V_1 * V_123 =
F_1 ( F_51 () ) ;
F_52 ( L_32 , V_120 ) ;
V_124 = 0 ;
if ( V_120 == V_125 ) {
} else {
F_16 ( L_33 ,
V_123 , V_123 ? V_123 -> V_126 : 0 ) ;
#if F_53 ( V_127 )
F_16 ( L_34 , F_51 () ) ;
#endif
}
switch ( V_120 ) {
case V_125 :
{
switch ( V_121 ) {
case V_128 :
F_16 ( L_35 ,
V_123 , V_123 -> V_126 ) ;
#if F_53 ( V_127 )
F_16 ( L_34 , F_51 () ) ;
#endif
F_16 ( L_36 V_129 L_30 ,
F_54 ( V_115 ) ) ;
break;
case V_130 :
break;
case V_131 :
F_52 ( L_37 , V_120 ) ;
return 1 ;
default:
F_16 ( L_38 ,
V_121 ) ;
break;
}
}
break;
case V_132 :
if ( F_55 ( V_133 ) )
F_16 ( L_39 ) ;
else
F_16 ( L_40 ) ;
break;
case V_134 :
F_34 ( V_133 ) ;
F_16 ( L_39 ) ;
break;
case V_135 :
case V_136 :
F_16 ( L_41 ) ;
break;
case V_137 :
F_16 ( L_42 , V_138 ) ;
F_16 ( L_43 V_129 L_30 ,
F_54 ( V_115 ) ) ;
F_44 ( V_115 ) ;
break;
case V_139 :
F_16 ( L_44
V_129 L_30 ,
F_54 ( V_115 ) ) ;
F_44 ( V_115 ) ;
break;
case V_140 :
case V_141 :
F_16 ( L_45 V_129 L_30 ,
V_120 == V_141 ?
L_46 : L_47 , F_54 ( V_115 ) ) ;
if ( V_121 != V_128 ) {
F_16 ( L_48 ,
V_121 ) ;
F_52 ( L_49 , V_120 ) ;
return 0 ;
}
break;
case V_142 :
F_16 ( L_50 V_129 L_30 ,
F_54 ( V_115 ) ) ;
break;
default:
F_16 ( L_51 , V_120 ) ;
F_52 ( L_52 , V_120 ) ;
return 0 ;
}
while ( 1 ) {
V_143 = 1 ;
F_36 ( V_144 ) ;
V_122 = V_112 ;
* V_122 = '\0' ;
* ( V_113 [ V_108 ] ) = '\0' ;
V_145:
#if F_53 ( V_127 )
snprintf ( V_146 , V_85 , F_6 ( L_53 ) ,
F_51 () ) ;
#else
snprintf ( V_146 , V_85 , F_6 ( L_53 ) ) ;
#endif
if ( V_62 )
strncat ( V_146 , L_54 , V_85 ) ;
V_122 = F_56 ( V_122 , V_85 , V_146 ) ;
if ( * V_122 != '\n' ) {
if ( * V_122 < 32 ) {
if ( V_110 == V_108 ) {
strncpy ( V_113 [ V_108 ] , V_112 ,
V_85 ) ;
* ( V_113 [ V_108 ] +
strlen ( V_113 [ V_108 ] ) - 1 ) = '\0' ;
}
if ( ! F_38 ( V_122 ) )
* ( V_112 + strlen ( V_112 ) - 1 ) = '\0' ;
V_122 = V_112 ;
goto V_145;
} else {
strncpy ( V_113 [ V_108 ] , V_112 ,
V_85 ) ;
}
V_108 = ( V_108 + 1 ) % V_111 ;
if ( V_108 == V_109 )
V_109 = ( V_109 + 1 ) % V_111 ;
}
V_110 = V_108 ;
V_21 = F_30 ( V_122 ) ;
if ( V_21 == V_94 ) {
F_16 ( L_55 , V_122 ) ;
V_21 = 0 ;
}
if ( V_21 == V_101
|| V_21 == V_147
|| V_21 == V_148
|| V_21 == V_149 )
break;
if ( V_21 )
F_21 ( V_21 ) ;
}
F_52 ( L_56 , V_21 ) ;
return V_21 ;
}
void F_57 ( const char * V_150 , int V_17 )
{
F_16 ( L_57 ,
V_150 , F_51 () , V_17 , V_151 ,
V_152 ) ;
}
int F_58 ( T_5 V_120 , T_5 V_153 , int error ,
T_6 V_121 , struct V_114 * V_115 )
{
int V_95 = 1 ;
while ( 1 ) {
F_52 ( L_58 , V_120 ) ;
while ( F_55 ( V_154 ) ) {
if ( ! F_55 ( V_155 ) )
F_34 ( V_155 ) ;
}
F_36 ( V_144 ) ;
F_52 ( L_59 , V_120 ) ;
if ( F_55 ( V_156 ) )
break;
V_95 = F_50 ( V_153 , error , V_115 , V_121 ) ;
F_52 ( L_60 , V_95 ) ;
if ( V_95 == V_147 )
break;
if ( V_95 == V_148 ) {
F_34 ( V_157 ) ;
break;
}
if ( V_95 == V_149 ) {
if ( ! F_55 ( V_158 ) )
F_16 ( L_61
L_62 ) ;
break;
}
if ( V_95 && V_95 != 1 && V_95 != V_101 )
F_16 ( L_63 ,
V_95 ) ;
F_52 ( L_64 , V_120 ) ;
break;
}
if ( F_55 ( V_157 ) )
F_36 ( V_159 ) ;
F_59 () ;
return V_95 ;
}
static int F_60 ( unsigned long V_41 , unsigned int V_63 )
{
unsigned char V_160 ;
while ( V_63 -- ) {
if ( F_61 ( V_160 , V_41 ) )
return 0 ;
F_16 ( L_65 , V_160 ) ;
V_41 ++ ;
}
F_16 ( L_30 ) ;
return 0 ;
}
static void F_62 ( const char * V_161 , unsigned long V_41 ,
int V_162 , int V_163 , int V_164 ,
int V_165 , int V_166 , int V_167 )
{
T_3 V_47 ;
char V_84 [ 32 ] ;
char * V_160 = V_84 ;
int V_10 ;
unsigned long V_168 ;
memset ( V_84 , '\0' , sizeof( V_84 ) ) ;
if ( V_167 )
F_16 ( L_66 V_169 L_67 , V_41 ) ;
else
F_16 ( V_169 L_67 , V_41 ) ;
for ( V_10 = 0 ; V_10 < V_165 && V_166 -- ; V_10 ++ ) {
if ( V_167 ) {
if ( F_63 ( & V_168 , V_41 , V_164 ) )
break;
} else if ( F_64 ( & V_168 , V_41 , V_164 ) )
break;
F_16 ( V_161 , V_168 ) ;
if ( V_162 )
F_20 ( V_168 , & V_47 ) ;
else
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
if ( V_47 . V_170 ) {
F_37 ( V_168 , & V_47 , 0 ) ;
if ( ! V_163 ) {
F_16 ( L_30 ) ;
F_16 ( L_68
V_129 L_67
V_129 L_67
V_129 , V_47 . V_171 ,
V_47 . V_172 , V_47 . V_173 ,
V_47 . V_49 , V_47 . V_174 ) ;
}
V_41 += V_164 ;
} else {
union {
T_2 V_168 ;
unsigned char V_160 [ 8 ] ;
} V_175 ;
unsigned char * V_13 ;
#ifdef F_65
V_13 = V_175 . V_160 + 8 - V_164 ;
#else
V_13 = V_175 . V_160 ;
#endif
V_175 . V_168 = V_168 ;
#define F_66 ( V_160 ) \
({unsigned char __c = c; isascii(__c) && isprint(__c) ? __c : '.'; })
switch ( V_164 ) {
case 8 :
* V_160 ++ = F_66 ( * V_13 ++ ) ;
* V_160 ++ = F_66 ( * V_13 ++ ) ;
* V_160 ++ = F_66 ( * V_13 ++ ) ;
* V_160 ++ = F_66 ( * V_13 ++ ) ;
V_41 += 4 ;
case 4 :
* V_160 ++ = F_66 ( * V_13 ++ ) ;
* V_160 ++ = F_66 ( * V_13 ++ ) ;
V_41 += 2 ;
case 2 :
* V_160 ++ = F_66 ( * V_13 ++ ) ;
V_41 ++ ;
case 1 :
* V_160 ++ = F_66 ( * V_13 ++ ) ;
V_41 ++ ;
break;
}
#undef F_66
}
}
F_16 ( L_69 , ( int ) ( ( V_165 - V_10 ) * ( 2 * V_164 + 1 ) + 1 ) ,
L_67 , V_84 ) ;
}
static int F_67 ( int V_25 , const char * * V_26 )
{
static unsigned long V_176 ;
static int V_177 , V_178 , V_179 ;
int V_180 = 16 , V_181 = 8 , V_164 = V_182 , V_166 ;
int V_163 = 0 ;
char V_183 , V_161 [ 64 ] ;
unsigned long V_41 ;
unsigned long V_168 ;
long V_39 = 0 ;
int V_162 = 0 ;
int V_184 = 0 ;
int V_167 = 0 ;
F_11 ( L_70 , & V_181 ) ;
F_11 ( L_71 , & V_180 ) ;
F_11 ( L_72 , & V_164 ) ;
V_166 = V_181 * 16 / V_164 ;
if ( strcmp ( V_26 [ 0 ] , L_73 ) == 0 ) {
if ( V_25 != 2 )
return V_29 ;
V_184 = 1 ;
} else if ( isdigit ( V_26 [ 0 ] [ 2 ] ) ) {
V_164 = ( int ) ( V_26 [ 0 ] [ 2 ] - '0' ) ;
if ( V_164 == 0 ) {
V_164 = V_178 ;
if ( V_164 == 0 )
V_164 = 4 ;
}
V_178 = V_164 ;
V_166 = V_181 * 16 / V_164 ;
if ( ! V_26 [ 0 ] [ 3 ] )
V_184 = 1 ;
else if ( V_26 [ 0 ] [ 3 ] == 'c' && V_26 [ 0 ] [ 4 ] ) {
char * V_3 ;
V_166 = F_10 ( V_26 [ 0 ] + 4 , & V_3 , 10 ) ;
V_181 = ( ( V_166 * V_164 ) + 15 ) / 16 ;
V_184 = ! * V_3 ;
}
V_179 = V_166 ;
} else if ( strcmp ( V_26 [ 0 ] , L_74 ) == 0 )
V_184 = 1 ;
else if ( strcmp ( V_26 [ 0 ] , L_75 ) == 0 )
V_184 = 1 ;
else if ( strcmp ( V_26 [ 0 ] , L_76 ) == 0 ) {
V_167 = V_184 = 1 ;
}
if ( ! V_184 )
return V_94 ;
if ( V_25 == 0 ) {
if ( V_176 == 0 )
return V_29 ;
V_41 = V_176 ;
V_180 = V_177 ;
V_164 = V_178 ;
V_166 = V_179 ;
V_181 = ( ( V_166 * V_164 ) + 15 ) / 16 ;
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
V_181 = ( int ) V_20 ;
V_166 = V_181 * 16 / V_164 ;
}
}
if ( V_25 >= V_38 + 1 ) {
V_21 = F_12 ( V_26 [ V_38 + 1 ] , & V_20 ) ;
if ( ! V_21 )
V_180 = ( int ) V_20 ;
}
}
if ( strcmp ( V_26 [ 0 ] , L_73 ) == 0 )
return F_60 ( V_41 , V_181 ) ;
switch ( V_180 ) {
case 10 :
V_183 = 'd' ;
break;
case 16 :
V_183 = 'x' ;
break;
case 8 :
V_183 = 'o' ;
break;
default:
return V_185 ;
}
V_177 = V_180 ;
if ( V_164 > V_182 )
return V_186 ;
switch ( V_164 ) {
case 8 :
sprintf ( V_161 , L_77 , V_183 ) ;
break;
case 4 :
sprintf ( V_161 , L_78 , V_183 ) ;
break;
case 2 :
sprintf ( V_161 , L_79 , V_183 ) ;
break;
case 1 :
sprintf ( V_161 , L_80 , V_183 ) ;
break;
default:
return V_186 ;
}
V_179 = V_166 ;
V_178 = V_164 ;
if ( strcmp ( V_26 [ 0 ] , L_75 ) == 0 ) {
V_162 = 1 ;
V_164 = V_182 ;
V_166 = V_181 ;
F_11 ( L_81 , & V_163 ) ;
}
V_41 &= ~ ( V_164 - 1 ) ;
while ( V_166 > 0 ) {
unsigned long V_187 ;
int V_188 , V_189 , V_165 = ( V_162 ? 1 : ( 16 / V_164 ) ) ;
if ( F_32 ( V_92 ) )
return 0 ;
for ( V_187 = V_41 , V_189 = 0 ; V_189 < V_166 ; V_187 += V_164 , ++ V_189 ) {
if ( V_167 ) {
if ( F_63 ( & V_168 , V_187 , V_164 )
|| V_168 )
break;
} else if ( F_64 ( & V_168 , V_187 , V_164 ) || V_168 )
break;
}
V_188 = F_68 ( V_165 , V_166 ) ;
F_62 ( V_161 , V_41 , V_162 , V_163 , V_164 ,
V_165 , V_166 , V_167 ) ;
V_41 += V_164 * V_188 ;
V_166 -= V_188 ;
V_189 = ( V_189 + V_165 - 1 ) / V_165 ;
if ( V_189 > 2 ) {
int V_58 = V_165 * ( V_189 - 2 ) ;
F_16 ( V_169 L_82 V_169
L_83 ,
V_41 , V_41 + V_164 * V_58 - 1 ) ;
V_41 += V_164 * V_58 ;
V_166 -= V_58 ;
}
}
V_176 = V_41 ;
return 0 ;
}
static int F_69 ( int V_25 , const char * * V_26 )
{
int V_21 ;
unsigned long V_41 ;
long V_39 = 0 ;
unsigned long V_190 ;
int V_38 ;
int V_191 ;
if ( V_26 [ 0 ] [ 2 ] && ! isdigit ( V_26 [ 0 ] [ 2 ] ) )
return V_94 ;
if ( V_25 < 2 )
return V_29 ;
V_38 = 1 ;
V_21 = F_18 ( V_25 , V_26 , & V_38 , & V_41 , & V_39 , NULL ) ;
if ( V_21 )
return V_21 ;
if ( V_38 > V_25 )
return V_29 ;
V_21 = F_18 ( V_25 , V_26 , & V_38 , & V_190 , NULL , NULL ) ;
if ( V_21 )
return V_21 ;
if ( V_38 != V_25 + 1 )
return V_29 ;
V_191 = V_26 [ 0 ] [ 2 ] ? ( V_26 [ 0 ] [ 2 ] - '0' ) : ( V_182 ) ;
V_21 = F_70 ( V_41 , V_190 , V_191 ) ;
if ( V_21 )
return V_21 ;
F_16 ( V_129 L_84 V_129 L_30 , V_41 , V_190 ) ;
return 0 ;
}
static int F_71 ( int V_25 , const char * * V_26 )
{
unsigned long V_41 ;
int V_21 ;
int V_38 ;
long V_39 ;
if ( F_51 () != V_151 ) {
F_16 ( L_85
L_86 ,
V_151 ) ;
return V_192 ;
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
V_21 = V_101 ;
if ( F_32 ( V_193 ) ) {
F_16 ( L_87 ) ;
F_16 ( L_88 ,
V_194 ) ;
if ( V_194 == 0 && V_124 ++ == 0 ) {
F_16 ( L_89
L_90 ) ;
return 0 ;
}
if ( V_194 == 2 ) {
F_16 ( L_91 ) ;
F_41 ( 0 , NULL ) ;
}
F_16 ( L_92 ) ;
}
return V_21 ;
}
static int F_72 ( int V_25 , const char * * V_26 )
{
int V_76 = F_17 () ;
#if V_195 > 0
int V_10 ;
char * V_196 ;
int V_197 ;
T_2 V_198 ;
T_7 V_199 ;
T_8 V_200 ;
T_9 V_201 ;
if ( V_76 )
return V_76 ;
for ( V_10 = 0 ; V_10 < V_195 ; V_10 ++ ) {
V_197 = V_202 [ V_10 ] . V_203 * 2 ;
if ( V_197 > 16 )
V_197 = 2 ;
if ( V_76 + strlen ( V_202 [ V_10 ] . V_40 ) + 4 + V_197 > 80 ) {
V_76 = 0 ;
F_16 ( L_30 ) ;
}
if ( V_76 )
V_76 += F_16 ( L_93 ) ;
switch( V_202 [ V_10 ] . V_203 * 8 ) {
case 8 :
V_196 = F_73 ( V_10 , & V_201 , V_36 ) ;
if ( ! V_196 )
break;
V_76 += F_16 ( L_94 , V_196 , V_201 ) ;
break;
case 16 :
V_196 = F_73 ( V_10 , & V_200 , V_36 ) ;
if ( ! V_196 )
break;
V_76 += F_16 ( L_95 , V_196 , V_200 ) ;
break;
case 32 :
V_196 = F_73 ( V_10 , & V_199 , V_36 ) ;
if ( ! V_196 )
break;
V_76 += F_16 ( L_96 , V_196 , V_199 ) ;
break;
case 64 :
V_196 = F_73 ( V_10 , & V_198 , V_36 ) ;
if ( ! V_196 )
break;
V_76 += F_16 ( L_97 , V_196 , V_198 ) ;
break;
default:
V_76 += F_16 ( L_98 , V_202 [ V_10 ] . V_40 ) ;
}
}
F_16 ( L_30 ) ;
#else
if ( V_76 )
return V_76 ;
F_44 ( V_36 ) ;
#endif
return 0 ;
}
static int F_74 ( int V_25 , const char * * V_26 )
{
#if V_195 > 0
int V_21 ;
const char * V_196 ;
int V_10 ;
T_2 V_198 ;
T_7 V_199 ;
T_8 V_200 ;
T_9 V_201 ;
if ( V_25 != 2 )
return V_29 ;
V_196 = V_26 [ 1 ] ;
if ( * V_196 == '%' )
V_196 ++ ;
V_21 = F_13 ( V_26 [ 2 ] , & V_198 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_17 () ;
if ( V_21 )
return V_21 ;
V_21 = V_37 ;
for ( V_10 = 0 ; V_10 < V_195 ; V_10 ++ ) {
if ( strcmp ( V_196 , V_202 [ V_10 ] . V_40 ) == 0 ) {
V_21 = 0 ;
break;
}
}
if ( ! V_21 ) {
switch( V_202 [ V_10 ] . V_203 * 8 ) {
case 8 :
V_201 = V_198 ;
F_75 ( V_10 , & V_201 , V_36 ) ;
break;
case 16 :
V_200 = V_198 ;
F_75 ( V_10 , & V_200 , V_36 ) ;
break;
case 32 :
V_199 = V_198 ;
F_75 ( V_10 , & V_199 , V_36 ) ;
break;
case 64 :
F_75 ( V_10 , & V_198 , V_36 ) ;
break;
}
}
return V_21 ;
#else
F_16 ( L_99 ) ;
return 0 ;
#endif
}
static int F_76 ( int V_25 , const char * * V_26 )
{
if ( V_25 != 1 )
return V_29 ;
V_118 ++ ;
F_77 ( * V_26 [ 1 ] , false ) ;
V_118 -- ;
return 0 ;
}
static int F_78 ( int V_25 , const char * * V_26 )
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
F_45 ( (struct V_114 * ) V_41 ) ;
return 0 ;
}
static int F_79 ( int V_25 , const char * * V_26 )
{
struct V_204 * V_205 ;
if ( V_25 != 0 )
return V_29 ;
F_16 ( L_100 ) ;
F_80 (mod, kdb_modules, list) {
if ( V_205 -> V_206 == V_207 )
continue;
F_16 ( L_101 , V_205 -> V_40 ,
V_205 -> V_208 , ( void * ) V_205 ) ;
#ifdef F_81
F_16 ( L_102 , F_82 ( V_205 ) ) ;
#endif
if ( V_205 -> V_206 == V_209 )
F_16 ( L_103 ) ;
else if ( V_205 -> V_206 == V_210 )
F_16 ( L_104 ) ;
else
F_16 ( L_105 ) ;
F_16 ( L_106 , V_205 -> V_211 ) ;
#ifdef F_81
{
struct V_212 * V_213 ;
F_16 ( L_107 ) ;
F_80 (use, &mod->source_list,
source_list)
F_16 ( L_108 , V_213 -> V_214 -> V_40 ) ;
F_16 ( L_109 ) ;
}
#endif
}
return 0 ;
}
static int F_83 ( int V_25 , const char * * V_26 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( V_8 [ V_10 ] )
F_16 ( L_110 , V_8 [ V_10 ] ) ;
}
if ( F_84 ( V_215 ) )
F_16 ( L_111 , V_32 ) ;
return 0 ;
}
static int F_85 ( int V_25 , const char * * V_26 )
{
int V_21 ;
int V_216 ;
int V_217 = 0 ;
int V_218 = 0 ;
int V_188 = 0 ;
int V_219 = 0 ;
struct V_220 V_221 = { . V_222 = 1 } ;
T_1 V_76 ;
char V_223 [ 201 ] ;
if ( V_25 > 2 )
return V_29 ;
if ( V_25 ) {
char * V_13 ;
V_217 = F_86 ( V_26 [ 1 ] , & V_13 , 0 ) ;
if ( * V_13 )
V_217 = 0 ;
if ( V_25 > 1 ) {
V_218 = F_10 ( V_26 [ 2 ] , & V_13 , 0 ) ;
if ( * V_13 || V_218 < 0 )
V_218 = 0 ;
}
}
V_21 = F_11 ( L_112 , & V_216 ) ;
if ( ! V_21 && V_216 ) {
const char * V_224 [] = { L_113 , L_112 , L_114 } ;
F_15 ( 2 , V_224 ) ;
}
F_87 ( & V_221 ) ;
while ( F_88 ( & V_221 , 1 , NULL , 0 , NULL ) )
V_188 ++ ;
if ( V_217 < 0 ) {
if ( V_218 >= V_188 )
F_16 ( L_115
L_116 , V_188 ) ;
else if ( V_218 - V_217 >= V_188 )
F_16 ( L_117
L_118 , V_188 , V_188 - V_218 ) ;
V_219 = V_218 ;
V_217 = abs ( V_217 ) ;
} else if ( V_217 > 0 ) {
V_219 = V_188 - V_217 - V_218 ;
V_217 = abs ( V_217 ) ;
if ( V_218 >= V_188 ) {
F_16 ( L_119
L_120 , V_188 ) ;
V_219 = V_188 ;
} else if ( V_219 < 0 ) {
V_217 += V_219 ;
V_219 = 0 ;
F_16 ( L_121
L_122 , V_188 , V_217 ) ;
}
} else {
V_217 = V_188 ;
}
if ( V_219 >= V_188 || V_219 < 0 )
return 0 ;
F_87 ( & V_221 ) ;
while ( F_88 ( & V_221 , 1 , V_223 , sizeof( V_223 ) , & V_76 ) ) {
if ( V_219 ) {
V_219 -- ;
continue;
}
if ( ! V_217 -- )
break;
if ( F_32 ( V_92 ) )
return 0 ;
F_16 ( L_123 , ( int ) V_76 - 1 , V_223 ) ;
}
return 0 ;
}
static int F_89 ( int V_25 , const char * V_26 [] )
{
if ( F_90 ( & V_225 ) )
return 0 ;
F_91 ( & V_225 , 1 ) ;
V_226 . V_227 ( 0 ) ;
return 0 ;
}
static int F_92 ( const char * V_20 , const struct V_228 * V_229 )
{
if ( ! F_93 ( & V_225 , - 1 , 0 ) )
return - V_230 ;
V_226 . V_227 ( 1 ) ;
return 0 ;
}
static void F_94 ( void )
{
int V_10 , V_231 , V_232 = 1 ;
char V_206 , V_233 = '?' ;
F_16 ( L_124 , F_51 () ) ;
F_16 ( L_125 ) ;
for ( V_231 = - 1 , V_10 = 0 ; V_10 < V_234 ; V_10 ++ ) {
if ( ! F_95 ( V_10 ) ) {
V_206 = 'F' ;
} else {
V_206 = ' ' ;
if ( F_96 ( F_5 ( V_10 ) ) == 'I' )
V_206 = 'I' ;
}
if ( V_206 != V_233 ) {
if ( V_233 != '?' ) {
if ( ! V_232 )
F_16 ( L_126 ) ;
V_232 = 0 ;
F_16 ( L_127 , V_231 ) ;
if ( V_231 < V_10 - 1 )
F_16 ( L_128 , V_10 - 1 ) ;
if ( V_233 != ' ' )
F_16 ( L_129 , V_233 ) ;
}
V_233 = V_206 ;
V_231 = V_10 ;
}
}
if ( V_233 != 'F' ) {
if ( ! V_232 )
F_16 ( L_126 ) ;
F_16 ( L_127 , V_231 ) ;
if ( V_231 < V_10 - 1 )
F_16 ( L_128 , V_10 - 1 ) ;
if ( V_233 != ' ' )
F_16 ( L_129 , V_233 ) ;
}
F_16 ( L_30 ) ;
}
static int F_97 ( int V_25 , const char * * V_26 )
{
unsigned long V_235 ;
int V_21 ;
if ( V_25 == 0 ) {
F_94 () ;
return 0 ;
}
if ( V_25 != 1 )
return V_29 ;
V_21 = F_12 ( V_26 [ 1 ] , & V_235 ) ;
if ( V_21 )
return V_21 ;
if ( ( V_235 > V_234 ) || ! F_95 ( V_235 ) )
return V_192 ;
V_236 = V_235 ;
return V_147 ;
}
void F_98 ( void )
{
int V_237 = 0 , V_238 = 0 ;
unsigned long V_239 = F_99 ( L_130 ) ,
V_240 = F_99 ( L_131 ) ;
unsigned long V_2 ;
const struct V_1 * V_3 , * V_241 ;
F_100 (cpu) {
V_3 = F_1 ( V_2 ) ;
if ( F_101 ( V_3 , V_239 ) )
++ V_237 ;
}
F_102 (g, p) {
if ( F_101 ( V_3 , V_240 ) )
++ V_238 ;
} F_103 ( V_241 , V_3 ) ;
if ( V_237 || V_238 ) {
if ( V_237 )
F_16 ( L_132 ,
V_237 , V_237 == 1 ? L_1 : L_133 ,
V_238 ? L_134 : L_1 ) ;
if ( V_238 )
F_16 ( L_135
L_136 , V_238 ,
V_238 == 1 ? L_1 : L_133 ) ;
F_16 ( L_137 ) ;
}
}
void F_104 ( const struct V_1 * V_3 )
{
int V_2 ;
unsigned long V_242 ;
if ( ! V_3 || F_105 ( & V_242 , ( char * ) V_3 , sizeof( unsigned long ) ) )
return;
V_2 = F_49 ( V_3 ) ;
F_16 ( L_138 ,
( void * ) V_3 , V_3 -> V_126 , V_3 -> V_243 -> V_126 ,
F_47 ( V_3 ) , F_49 ( V_3 ) ,
F_96 ( V_3 ) ,
( void * ) ( & V_3 -> V_244 ) ,
V_3 == F_1 ( F_51 () ) ? '*' : ' ' ,
V_3 -> V_245 ) ;
if ( F_47 ( V_3 ) ) {
if ( ! F_5 ( V_2 ) ) {
F_16 ( L_139 ) ;
} else {
if ( F_5 ( V_2 ) != V_3 )
F_16 ( L_140
L_141 , F_5 ( V_2 ) ) ;
}
}
}
static int F_106 ( int V_25 , const char * * V_26 )
{
struct V_1 * V_241 , * V_3 ;
unsigned long V_246 , V_2 ;
if ( V_25 == 0 )
F_98 () ;
F_16 ( L_142 ,
( int ) ( 2 * sizeof( void * ) ) + 2 , L_143 ,
( int ) ( 2 * sizeof( void * ) ) + 2 , L_144 ) ;
V_246 = F_99 ( V_25 ? V_26 [ 1 ] : NULL ) ;
F_100 (cpu) {
if ( F_32 ( V_92 ) )
return 0 ;
V_3 = F_1 ( V_2 ) ;
if ( F_101 ( V_3 , V_246 ) )
F_104 ( V_3 ) ;
}
F_16 ( L_30 ) ;
F_102 (g, p) {
if ( F_32 ( V_92 ) )
return 0 ;
if ( F_101 ( V_3 , V_246 ) )
F_104 ( V_3 ) ;
} F_103 ( V_241 , V_3 ) ;
return 0 ;
}
static int F_107 ( int V_25 , const char * * V_26 )
{
struct V_1 * V_3 ;
unsigned long V_20 ;
int V_21 ;
if ( V_25 > 1 )
return V_29 ;
if ( V_25 ) {
if ( strcmp ( V_26 [ 1 ] , L_145 ) == 0 ) {
V_3 = F_5 ( V_151 ) ;
} else {
V_21 = F_12 ( V_26 [ 1 ] , & V_20 ) ;
if ( V_21 )
return V_24 ;
V_3 = F_108 ( ( V_247 ) V_20 , & V_248 ) ;
if ( ! V_3 ) {
F_16 ( L_146 , ( V_247 ) V_20 ) ;
return 0 ;
}
}
F_46 ( V_3 ) ;
}
F_16 ( L_147 ,
V_119 -> V_245 ,
V_119 -> V_126 ) ;
return 0 ;
}
static int F_109 ( int V_25 , const char * * V_26 )
{
return V_149 ;
}
static int F_110 ( int V_25 , const char * * V_26 )
{
T_4 * V_249 ;
int V_10 ;
F_16 ( L_148 , L_149 , L_150 , L_151 ) ;
F_16 ( L_152
L_153 ) ;
F_35 (kt, i) {
char * V_250 = L_1 ;
if ( F_32 ( V_92 ) )
return 0 ;
if ( ! V_249 -> V_96 )
continue;
if ( strlen ( V_249 -> V_251 ) > 20 )
V_250 = L_154 ;
F_16 ( L_155 , V_249 -> V_96 ,
V_249 -> V_251 , V_250 , V_249 -> V_252 ) ;
}
return 0 ;
}
static int F_111 ( int V_25 , const char * * V_26 )
{
long V_253 , V_126 ;
char * V_23 ;
struct V_1 * V_3 ;
struct V_254 V_255 ;
if ( V_25 != 2 )
return V_29 ;
V_253 = F_86 ( V_26 [ 1 ] , & V_23 , 0 ) ;
if ( * V_23 )
return V_24 ;
if ( V_253 >= 0 ) {
F_16 ( L_156 ) ;
return 0 ;
}
V_253 = - V_253 ;
V_126 = F_86 ( V_26 [ 2 ] , & V_23 , 0 ) ;
if ( * V_23 )
return V_24 ;
if ( V_126 <= 0 ) {
F_16 ( L_157 ) ;
return 0 ;
}
V_3 = F_108 ( V_126 , & V_248 ) ;
if ( ! V_3 ) {
F_16 ( L_158 ) ;
return 0 ;
}
V_3 = V_3 -> V_256 ;
V_255 . V_257 = V_253 ;
V_255 . V_258 = 0 ;
V_255 . V_259 = V_260 ;
V_255 . V_261 = V_126 ;
V_255 . V_262 = 0 ;
F_112 ( V_3 , & V_255 ) ;
return 0 ;
}
static void F_113 ( struct V_263 * V_264 , struct V_265 * V_266 )
{
static int V_267 [] = { 31 , 29 , 31 , 30 , 31 , 30 , 31 ,
31 , 30 , 31 , 30 , 31 } ;
memset ( V_266 , 0 , sizeof( * V_266 ) ) ;
V_266 -> V_268 = V_264 -> V_269 % ( 24 * 60 * 60 ) ;
V_266 -> V_270 = V_264 -> V_269 / ( 24 * 60 * 60 ) +
( 2 * 365 + 1 ) ;
V_266 -> V_271 = V_266 -> V_268 / 60 % 60 ;
V_266 -> V_272 = V_266 -> V_268 / 60 / 60 ;
V_266 -> V_268 = V_266 -> V_268 % 60 ;
V_266 -> V_273 = 68 + 4 * ( V_266 -> V_270 / ( 4 * 365 + 1 ) ) ;
V_266 -> V_270 %= ( 4 * 365 + 1 ) ;
V_267 [ 1 ] = 29 ;
while ( V_266 -> V_270 >= V_267 [ V_266 -> V_274 ] ) {
V_266 -> V_270 -= V_267 [ V_266 -> V_274 ] ;
if ( ++ V_266 -> V_274 == 12 ) {
V_266 -> V_274 = 0 ;
++ V_266 -> V_273 ;
V_267 [ 1 ] = 28 ;
}
}
++ V_266 -> V_270 ;
}
static void F_114 ( struct V_275 * V_20 )
{
struct V_263 V_276 ;
F_115 ( & V_276 ) ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_276 = V_276 . V_269 ;
V_20 -> V_277 [ 0 ] = V_278 [ 0 ] ;
V_20 -> V_277 [ 1 ] = V_278 [ 1 ] ;
V_20 -> V_277 [ 2 ] = V_278 [ 2 ] ;
V_20 -> V_279 = V_280 - 1 ;
F_116 ( V_20 ) ;
return;
}
static int F_117 ( int V_25 , const char * * V_26 )
{
struct V_263 V_281 ;
struct V_265 V_266 ;
struct V_275 V_20 ;
if ( V_25 )
return V_29 ;
F_16 ( L_159 , V_282 . V_40 . V_283 ) ;
F_16 ( L_160 , V_282 . V_40 . V_284 ) ;
F_16 ( L_161 , V_282 . V_40 . V_285 ) ;
F_16 ( L_162 , V_282 . V_40 . V_286 ) ;
F_16 ( L_163 , V_282 . V_40 . V_287 ) ;
F_16 ( L_164 , V_282 . V_40 . V_288 ) ;
F_16 ( L_165 , F_118 ( V_289 ) ) ;
V_281 = F_119 () ;
F_113 ( & V_281 , & V_266 ) ;
F_16 ( L_166
L_167 ,
1900 + V_266 . V_273 , V_266 . V_274 + 1 , V_266 . V_270 ,
V_266 . V_272 , V_266 . V_271 , V_266 . V_268 ,
V_290 . V_291 ) ;
F_114 ( & V_20 ) ;
F_16 ( L_168 ) ;
if ( V_20 . V_276 > ( 24 * 60 * 60 ) ) {
int V_292 = V_20 . V_276 / ( 24 * 60 * 60 ) ;
V_20 . V_276 %= ( 24 * 60 * 60 ) ;
F_16 ( L_169 , V_292 , V_292 == 1 ? L_1 : L_170 ) ;
}
F_16 ( L_171 , V_20 . V_276 / ( 60 * 60 ) , ( V_20 . V_276 / 60 ) % 60 ) ;
#define F_120 ( T_10 ) ((x) >> FSHIFT)
#define F_121 ( T_10 ) LOAD_INT(((x) & (FIXED_1-1)) * 100)
F_16 ( L_172 ,
F_120 ( V_20 . V_277 [ 0 ] ) , F_121 ( V_20 . V_277 [ 0 ] ) ,
F_120 ( V_20 . V_277 [ 1 ] ) , F_121 ( V_20 . V_277 [ 1 ] ) ,
F_120 ( V_20 . V_277 [ 2 ] ) , F_121 ( V_20 . V_277 [ 2 ] ) ) ;
#undef F_120
#undef F_121
#define F_122 ( T_10 ) ((x) << (PAGE_SHIFT - 10))
F_16 ( L_173
L_174 ,
V_20 . V_293 , V_20 . V_294 , V_20 . V_295 ) ;
return 0 ;
}
static int F_123 ( int V_25 , const char * * V_26 )
{
char V_161 [ 64 ] ;
int V_2 , V_21 , V_38 = 1 ;
unsigned long V_41 , V_296 , V_20 , V_164 = 0 , V_297 = ~ 0UL ;
if ( V_25 < 1 || V_25 > 3 )
return V_29 ;
V_21 = F_18 ( V_25 , V_26 , & V_38 , & V_296 , NULL , NULL ) ;
if ( V_21 )
return V_21 ;
if ( V_25 >= 2 ) {
V_21 = F_12 ( V_26 [ 2 ] , & V_164 ) ;
if ( V_21 )
return V_21 ;
}
if ( ! V_164 )
V_164 = V_182 ;
else if ( V_164 > V_182 )
return V_186 ;
sprintf ( V_161 , L_175 , ( int ) ( 2 * V_164 ) ) ;
if ( V_25 >= 3 ) {
V_21 = F_12 ( V_26 [ 3 ] , & V_297 ) ;
if ( V_21 )
return V_21 ;
if ( ! F_95 ( V_297 ) ) {
F_16 ( L_176 , V_297 ) ;
return V_192 ;
}
}
#ifdef F_124
#define F_125 ( V_2 ) __per_cpu_offset(cpu)
#else
#ifdef V_127
#define F_125 ( V_2 ) __per_cpu_offset[cpu]
#else
#define F_125 ( V_2 ) 0
#endif
#endif
F_100 (cpu) {
if ( F_32 ( V_92 ) )
return 0 ;
if ( V_297 != ~ 0UL && V_297 != V_2 )
continue;
V_41 = V_296 + F_125 ( V_2 ) ;
V_21 = F_64 ( & V_20 , V_41 , V_164 ) ;
if ( V_21 ) {
F_16 ( L_177 V_298 L_178
L_179 , V_2 , V_41 , V_21 ) ;
continue;
}
F_16 ( L_177 , V_2 ) ;
F_62 ( V_161 , V_41 ,
V_164 == V_182 ,
1 , V_164 , 1 , 1 , 0 ) ;
}
#undef F_125
return 0 ;
}
static int F_126 ( int V_25 , const char * * V_26 )
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
int F_127 ( char * V_107 ,
T_11 V_299 ,
char * V_66 ,
char * V_67 ,
short V_300 ,
T_12 V_166 )
{
int V_10 ;
T_4 * V_229 ;
F_35 (kp, i) {
if ( V_229 -> V_96 && ( strcmp ( V_229 -> V_96 , V_107 ) == 0 ) ) {
F_16 ( L_191
L_192 , V_107 , V_299 , V_67 ) ;
return 1 ;
}
}
F_35 (kp, i) {
if ( V_229 -> V_96 == NULL )
break;
}
if ( V_10 >= V_98 ) {
T_4 * V_301 = F_29 ( ( V_98 - V_302 +
V_303 ) * sizeof( * V_301 ) , V_68 ) ;
if ( ! V_301 ) {
F_16 ( L_193
L_194 ) ;
return 1 ;
}
if ( V_304 ) {
memcpy ( V_301 , V_304 ,
( V_98 - V_302 ) * sizeof( * V_301 ) ) ;
F_26 ( V_304 ) ;
}
memset ( V_301 + V_98 - V_302 , 0 ,
V_303 * sizeof( * V_301 ) ) ;
V_304 = V_301 ;
V_229 = V_304 + V_98 - V_302 ;
V_98 += V_303 ;
}
V_229 -> V_96 = V_107 ;
V_229 -> V_100 = V_299 ;
V_229 -> V_251 = V_66 ;
V_229 -> V_252 = V_67 ;
V_229 -> V_305 = 0 ;
V_229 -> V_97 = V_300 ;
V_229 -> V_102 = V_166 ;
return 0 ;
}
int F_23 ( char * V_107 ,
T_11 V_299 ,
char * V_66 ,
char * V_67 ,
short V_300 )
{
return F_127 ( V_107 , V_299 , V_66 , V_67 , V_300 ,
V_103 ) ;
}
int F_128 ( char * V_107 )
{
int V_10 ;
T_4 * V_229 ;
F_35 (kp, i) {
if ( V_229 -> V_96 && ( strcmp ( V_229 -> V_96 , V_107 ) == 0 ) ) {
V_229 -> V_96 = NULL ;
return 0 ;
}
}
return 1 ;
}
static void T_13 F_129 ( void )
{
int V_10 ;
T_4 * V_229 ;
F_35 (kp, i)
V_229 -> V_96 = NULL ;
F_127 ( L_74 , F_67 , L_195 ,
L_196 , 1 ,
V_104 ) ;
F_127 ( L_73 , F_67 , L_197 ,
L_198 , 0 , V_104 ) ;
F_127 ( L_76 , F_67 , L_199 ,
L_200 , 0 , V_104 ) ;
F_127 ( L_75 , F_67 , L_195 ,
L_201 , 0 , V_104 ) ;
F_127 ( L_202 , F_69 , L_203 ,
L_204 , 0 , V_104 ) ;
F_127 ( L_205 , F_71 , L_206 ,
L_207 , 1 , V_103 ) ;
F_127 ( L_208 , F_72 , L_1 ,
L_209 , 0 , V_103 ) ;
F_127 ( L_210 , F_74 , L_211 ,
L_212 , 0 , V_103 ) ;
F_127 ( L_213 , F_78 , L_195 ,
L_214 , 0 , V_103 ) ;
F_127 ( L_215 , V_306 , L_206 ,
L_216 , 1 , V_103 ) ;
F_127 ( L_217 , V_306 , L_218 ,
L_219 , 0 , V_103 ) ;
F_127 ( L_220 , V_306 , L_221 ,
L_222 , 0 , V_103 ) ;
F_127 ( L_223 , V_306 , L_1 ,
L_224 , 0 , V_103 ) ;
F_127 ( L_225 , V_306 , L_195 ,
L_226 , 0 ,
V_103 ) ;
F_127 ( L_227 , F_83 , L_1 ,
L_228 , 0 , V_103 ) ;
F_127 ( L_113 , F_15 , L_1 ,
L_229 , 0 , V_103 ) ;
F_127 ( L_230 , F_110 , L_1 ,
L_231 , 1 , V_103 ) ;
F_127 ( L_232 , F_110 , L_1 ,
L_231 , 0 , V_103 ) ;
F_127 ( L_233 , F_97 , L_234 ,
L_235 , 0 , V_103 ) ;
F_127 ( L_236 , F_109 , L_1 ,
L_237 , 0 , V_103 ) ;
F_127 ( L_238 , F_106 , L_239 ,
L_240 , 0 , V_103 ) ;
F_127 ( L_241 , F_107 , L_242 ,
L_243 , 0 , V_103 ) ;
F_127 ( L_244 , F_41 , L_1 ,
L_245 , 0 , V_103 ) ;
#if F_53 ( V_307 )
F_127 ( L_246 , F_79 , L_1 ,
L_247 , 0 , V_103 ) ;
#endif
#if F_53 ( V_308 )
F_127 ( L_248 , F_76 , L_249 ,
L_250 , 0 , V_103 ) ;
#endif
#if F_53 ( V_309 )
F_127 ( L_251 , F_85 , L_252 ,
L_253 , 0 , V_103 ) ;
#endif
if ( V_226 . V_227 ) {
F_127 ( L_254 , F_89 , L_1 ,
L_255 , 0 , V_103 ) ;
}
F_127 ( L_256 , F_27 , L_257 ,
L_258 , 0 , V_103 ) ;
F_127 ( L_259 , F_111 , L_260 ,
L_261 , 0 , V_103 ) ;
F_127 ( L_262 , F_117 , L_1 ,
L_263 , 4 , V_103 ) ;
F_127 ( L_264 , F_123 , L_265 ,
L_266 , 3 , V_103 ) ;
F_127 ( L_267 , F_126 , L_1 ,
L_268 , 0 , V_103 ) ;
}
static void T_13 F_130 ( void )
{
int V_10 , V_21 ;
for ( V_10 = 0 ; V_310 [ V_10 ] ; ++ V_10 ) {
V_21 = F_30 ( V_310 [ V_10 ] ) ;
if ( V_21 )
F_16 ( L_269 ,
V_310 [ V_10 ] , V_21 ) ;
}
if ( V_62 ) {
F_16 ( L_270 ) ;
F_30 ( L_11 ) ;
}
}
void T_13 F_131 ( int V_311 )
{
static int V_312 = V_313 ;
int V_10 ;
if ( V_312 == V_314 || V_311 <= V_312 )
return;
for ( V_10 = V_312 ; V_10 < V_311 ; V_10 ++ ) {
switch ( V_10 ) {
case V_313 :
F_129 () ;
F_132 () ;
break;
case V_315 :
F_130 () ;
break;
}
}
V_312 = V_311 ;
}
