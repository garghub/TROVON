int
main ( int V_1 , char * V_2 [] )
{
int V_3 ;
while ( ( V_3 = F_1 ( V_1 , V_2 , L_1 ) ) != - 1 )
switch ( V_3 ) {
case 'i' :
V_3 = * V_4 ++ ;
if ( V_3 == 'D' )
F_2 ( true , true , V_4 ) ;
else if ( V_3 == 'U' )
F_2 ( true , false , V_4 ) ;
else
F_3 () ;
break;
case 'D' :
F_2 ( false , true , V_4 ) ;
break;
case 'U' :
F_2 ( false , false , V_4 ) ;
break;
case 'I' :
break;
case 'b' :
case 'l' :
V_5 = true ;
break;
case 'B' :
V_6 = true ;
break;
case 'c' :
V_7 = true ;
break;
case 'd' :
V_8 = true ;
break;
case 'e' :
V_9 = true ;
break;
case 'K' :
V_10 = true ;
break;
case 'k' :
V_11 = true ;
break;
case 'n' :
V_12 = true ;
break;
case 'o' :
V_13 = V_4 ;
break;
case 's' :
V_14 = true ;
break;
case 'S' :
V_14 = V_15 = true ;
break;
case 't' :
V_16 = true ;
break;
case 'V' :
F_4 () ;
default:
F_3 () ;
}
V_1 -= V_17 ;
V_2 += V_17 ;
if ( V_6 && V_5 )
F_5 ( 2 , L_2 ) ;
if ( V_1 > 1 ) {
F_5 ( 2 , L_3 ) ;
} else if ( V_1 == 1 && strcmp ( * V_2 , L_4 ) != 0 ) {
V_18 = * V_2 ;
V_19 = fopen ( V_18 , L_5 ) ;
if ( V_19 == NULL )
F_6 ( 2 , L_6 , V_18 ) ;
} else {
V_18 = L_7 ;
V_19 = V_20 ;
}
if ( V_13 == NULL ) {
V_13 = L_8 ;
V_21 = stdout ;
} else {
struct V_22 V_23 , V_24 ;
if ( V_22 ( V_13 , & V_24 ) == 0 &&
F_7 ( fileno ( V_19 ) , & V_23 ) == 0 )
V_25 = ( V_23 . V_26 == V_24 . V_26
&& V_23 . V_27 == V_24 . V_27 ) ;
if ( V_25 ) {
const char * V_28 ;
int V_29 ;
V_28 = strrchr ( V_13 , '/' ) ;
if ( V_28 != NULL )
snprintf ( V_30 , sizeof( V_30 ) ,
L_9 V_31 ,
( int ) ( V_28 - V_13 ) , V_13 ) ;
else
snprintf ( V_30 , sizeof( V_30 ) ,
V_31 ) ;
V_29 = F_8 ( V_30 ) ;
if ( V_29 != - 1 )
V_21 = fdopen ( V_29 , L_10 ) ;
if ( V_21 == NULL )
F_6 ( 2 , L_11 ) ;
F_9 ( V_29 , V_23 . V_32 & ( V_33 | V_34 | V_35 ) ) ;
} else {
V_21 = fopen ( V_13 , L_12 ) ;
if ( V_21 == NULL )
F_6 ( 2 , L_6 , V_13 ) ;
}
}
F_10 () ;
abort () ;
}
static void
F_4 ( void )
{
const char * V_36 = V_37 ;
for (; ; ) {
while ( * ++ V_36 != '$' )
if ( * V_36 == '\0' )
exit ( 0 ) ;
while ( * ++ V_36 != '$' )
putc ( * V_36 , V_38 ) ;
putc ( '\n' , V_38 ) ;
}
}
static void
F_3 ( void )
{
fprintf ( V_38 , L_13
L_14 ) ;
exit ( 2 ) ;
}
static void F_11 ( void ) { error ( L_15 ) ; }
static void F_12 ( void ) { error ( L_16 ) ; }
static void F_13 ( void ) { error ( L_17 ) ; }
static void F_14 ( void ) { error ( L_18 ) ; }
static void F_15 ( void ) { error ( L_19 ) ; }
static void F_16 ( void ) { F_17 ( true ) ; }
static void F_18 ( void ) { F_17 ( false ) ; }
static void F_19 ( void ) { F_18 () ; F_20 () ; F_21 ( V_39 ) ; }
static void F_22 ( void ) { F_18 () ; F_20 () ; F_21 ( V_40 ) ; }
static void F_23 ( void ) { F_18 () ; F_21 ( V_41 ) ; }
static void F_24 ( void ) { F_16 () ; F_20 () ; F_21 ( V_42 ) ; }
static void F_25 ( void ) { F_16 () ; F_21 ( V_43 ) ; }
static void F_26 ( void ) { F_16 () ; F_27 () ; }
static void F_28 ( void ) { F_18 () ; F_20 () ; F_21 ( V_44 ) ; }
static void F_29 ( void ) { F_18 () ; F_20 () ; F_21 ( V_45 ) ; }
static void F_30 ( void ) { F_18 () ; F_21 ( V_46 ) ; }
static void F_31 ( void ) { F_18 () ; F_27 () ; }
static void F_32 ( void ) { F_33 () ; F_28 () ; }
static void F_34 ( void ) { F_33 () ; F_24 () ; }
static void F_35 ( void ) { F_33 () ; F_19 () ; }
static void F_36 ( void ) { F_33 () ; F_22 () ; }
static void F_37 ( void ) { if ( ! V_9 ) F_15 () ; F_34 () ; F_38 () ; }
static void F_39 ( void ) { if ( ! V_9 ) F_15 () ; F_34 () ; }
static void F_40 ( void ) { if ( ! V_9 ) F_15 () ; F_24 () ; }
static void F_41 ( void ) { F_32 () ; F_38 () ; }
static void F_42 ( void ) { F_35 () ; F_38 () ; }
static void F_43 ( void ) { F_36 () ; F_38 () ; }
static void F_44 ( void ) { strncpy ( V_47 , L_20 , 4 ) ; F_24 () ; }
static void F_45 ( void ) { F_46 ( L_21 ) ; F_21 ( V_48 ) ; }
static void F_47 ( void ) { F_46 ( L_22 ) ; F_21 ( V_44 ) ; }
static void F_48 ( void ) { F_46 ( L_22 ) ; F_21 ( V_46 ) ; }
static void
F_20 ( void )
{
if ( V_49 == 0 )
abort () ;
V_50 [ V_49 ] = V_50 [ V_49 - 1 ] ;
}
static void
F_38 ( void )
{
V_50 [ V_49 ] = true ;
}
static void
F_46 ( const char * V_51 )
{
snprintf ( V_47 , V_52 + sizeof( V_52 ) - V_47 ,
L_23 , V_51 , V_53 ) ;
F_16 () ;
}
static void
F_33 ( void )
{
if ( V_49 > V_54 - 1 )
abort () ;
if ( V_49 == V_54 - 1 )
error ( L_24 ) ;
V_49 += 1 ;
V_55 [ V_49 ] = V_56 ;
}
static void
F_27 ( void )
{
if ( V_49 == 0 )
abort () ;
V_49 -= 1 ;
}
static void
F_21 ( T_1 V_57 )
{
V_58 [ V_49 ] = V_57 ;
}
static void
F_17 ( bool V_59 )
{
if ( V_14 )
return;
if ( V_59 ^ V_7 ) {
bool V_60 = V_52 [ strspn ( V_52 , L_25 ) ] == '\0' ;
if ( V_60 && V_6 && V_61 != V_62 ) {
V_63 += 1 ;
V_61 += 1 ;
} else {
if ( V_12 && V_63 > 0 )
printf ( L_26 , V_56 , V_53 ) ;
fputs ( V_52 , V_21 ) ;
V_63 = 0 ;
V_62 = V_61 = V_60 ? V_61 + 1 : 0 ;
}
} else {
if ( V_5 )
fputs ( V_53 , V_21 ) ;
V_64 = 1 ;
V_63 += 1 ;
V_61 = 0 ;
}
if ( V_8 )
fflush ( V_21 ) ;
}
static void
F_10 ( void )
{
V_62 = V_61 = 1000 ;
for (; ; ) {
T_2 V_65 = F_49 () ;
V_66 [ V_58 [ V_49 ] ] [ V_65 ] ( ) ;
F_50 ( L_27 ,
V_56 , V_67 [ V_65 ] ,
V_68 [ V_58 [ V_49 ] ] , V_49 ) ;
}
}
static void
F_51 ( void )
{
if ( V_15 && ! V_69 )
printf ( L_28 ) ;
if ( fclose ( V_21 ) == V_70 ) {
F_52 ( L_29 , V_13 ) ;
if ( V_25 ) {
F_53 ( V_30 ) ;
F_5 ( 2 , L_30 , V_18 ) ;
} else {
exit ( 2 ) ;
}
}
}
static void
F_54 ( void )
{
if ( V_71 )
error ( L_31 ) ;
F_51 () ;
if ( V_25 && rename ( V_30 , V_13 ) == - 1 ) {
F_52 ( L_32 ) ;
F_53 ( V_30 ) ;
F_5 ( 2 , L_30 , V_13 ) ;
}
exit ( V_64 ) ;
}
static T_2
F_49 ( void )
{
const char * V_72 ;
int V_73 ;
int V_74 ;
T_2 V_75 ;
T_3 V_76 ;
V_56 ++ ;
if ( fgets ( V_52 , V_77 , V_19 ) == NULL )
return ( V_78 ) ;
if ( V_53 == NULL ) {
if ( strrchr ( V_52 , '\n' ) == strrchr ( V_52 , '\r' ) + 1 )
V_53 = V_79 ;
else
V_53 = V_80 ;
}
V_75 = V_81 ;
V_76 = V_71 ;
V_72 = F_55 ( V_52 ) ;
if ( V_82 == V_83 ) {
if ( * V_72 == '#' ) {
V_82 = V_84 ;
V_85 = true ;
V_72 = F_55 ( V_72 + 1 ) ;
} else if ( * V_72 != '\0' )
V_82 = V_86 ;
}
if ( ! V_71 && V_82 == V_84 ) {
V_47 = V_52 + ( V_72 - V_52 ) ;
V_72 = F_56 ( V_72 ) ;
V_74 = V_72 - V_47 ;
if ( strncmp ( V_72 , L_33 , 3 ) == 0 ||
strncmp ( V_72 , L_34 , 2 ) == 0 )
F_15 () ;
if ( F_57 ( L_35 , V_47 , V_74 ) == 0 ||
F_57 ( L_36 , V_47 , V_74 ) == 0 ) {
V_72 = F_55 ( V_72 ) ;
if ( ( V_73 = F_58 ( V_72 ) ) < 0 )
V_75 = V_87 ;
else {
V_75 = ( V_47 [ 2 ] == 'n' )
? V_88 : V_89 ;
if ( V_90 [ V_73 ] == NULL )
V_75 = ( V_75 == V_89 )
? V_88 : V_89 ;
if ( V_91 [ V_73 ] )
V_75 = ( V_75 == V_89 )
? V_92 : V_93 ;
}
V_72 = F_56 ( V_72 ) ;
} else if ( F_57 ( L_37 , V_47 , V_74 ) == 0 )
V_75 = F_59 ( & V_72 ) ;
else if ( F_57 ( L_38 , V_47 , V_74 ) == 0 )
V_75 = F_59 ( & V_72 ) - V_87 + V_94 ;
else if ( F_57 ( L_21 , V_47 , V_74 ) == 0 )
V_75 = V_95 ;
else if ( F_57 ( L_22 , V_47 , V_74 ) == 0 )
V_75 = V_96 ;
else {
V_82 = V_86 ;
V_75 = V_81 ;
}
V_72 = F_55 ( V_72 ) ;
if ( * V_72 != '\0' ) {
V_82 = V_86 ;
if ( V_75 == V_89 || V_75 == V_88 ||
V_75 == V_92 || V_75 == V_93 )
V_75 = V_87 ;
if ( V_75 == V_97 || V_75 == V_98 )
V_75 = V_94 ;
}
if ( V_75 != V_81 && ( V_76 || V_71 ) ) {
V_75 += V_99 ;
if ( V_71 )
V_82 = V_86 ;
}
if ( V_82 == V_84 ) {
T_4 V_100 = V_72 - V_52 ;
if ( fgets ( V_52 + V_100 , V_77 - V_100 , V_19 ) == NULL ) {
strcpy ( V_52 + V_100 , V_53 ) ;
V_72 += strlen ( V_53 ) ;
V_82 = V_83 ;
} else {
V_82 = V_86 ;
}
}
}
if ( V_82 == V_86 ) {
while ( * V_72 != '\0' )
V_72 = F_55 ( V_72 + 1 ) ;
}
F_50 ( L_39 , V_56 ,
V_101 [ V_71 ] , V_102 [ V_82 ] ) ;
return ( V_75 ) ;
}
static T_2 F_60 ( int * V_103 , int V_104 , T_2 V_105 , T_2 V_106 ) {
if( V_105 == V_87 || V_106 == V_87 ) return ( V_87 ) ;
return ( * V_103 = V_104 , V_104 ? V_89 : V_88 ) ;
}
static T_2 F_61 ( int * V_103 , T_2 V_105 , int V_107 , T_2 V_106 , int V_108 ) {
return F_60 ( V_103 , V_107 < V_108 , V_105 , V_106 ) ;
}
static T_2 F_62 ( int * V_103 , T_2 V_105 , int V_107 , T_2 V_106 , int V_108 ) {
return F_60 ( V_103 , V_107 > V_108 , V_105 , V_106 ) ;
}
static T_2 F_63 ( int * V_103 , T_2 V_105 , int V_107 , T_2 V_106 , int V_108 ) {
return F_60 ( V_103 , V_107 <= V_108 , V_105 , V_106 ) ;
}
static T_2 F_64 ( int * V_103 , T_2 V_105 , int V_107 , T_2 V_106 , int V_108 ) {
return F_60 ( V_103 , V_107 >= V_108 , V_105 , V_106 ) ;
}
static T_2 F_65 ( int * V_103 , T_2 V_105 , int V_107 , T_2 V_106 , int V_108 ) {
return F_60 ( V_103 , V_107 == V_108 , V_105 , V_106 ) ;
}
static T_2 F_66 ( int * V_103 , T_2 V_105 , int V_107 , T_2 V_106 , int V_108 ) {
return F_60 ( V_103 , V_107 != V_108 , V_105 , V_106 ) ;
}
static T_2 F_67 ( int * V_103 , T_2 V_105 , int V_107 , T_2 V_106 , int V_108 ) {
if ( ! V_10 && ( V_105 == V_89 || V_106 == V_89 ) )
return ( * V_103 = 1 , V_89 ) ;
return F_60 ( V_103 , V_107 || V_108 , V_105 , V_106 ) ;
}
static T_2 F_68 ( int * V_103 , T_2 V_105 , int V_107 , T_2 V_106 , int V_108 ) {
if ( ! V_10 && ( V_105 == V_88 || V_106 == V_88 ) )
return ( * V_103 = 0 , V_88 ) ;
return F_60 ( V_103 , V_107 && V_108 , V_105 , V_106 ) ;
}
static T_2
F_69 ( const struct V_109 * V_109 , int * V_110 , const char * * V_111 )
{
const char * V_72 ;
char * V_112 ;
int V_113 ;
bool V_114 ;
T_2 V_115 ;
V_72 = F_55 ( * V_111 ) ;
if ( * V_72 == '!' ) {
F_50 ( L_40 , V_109 - V_116 ) ;
V_72 ++ ;
V_115 = F_69 ( V_109 , V_110 , & V_72 ) ;
if ( V_115 == V_117 )
return ( V_117 ) ;
if ( V_115 != V_87 ) {
* V_110 = ! * V_110 ;
V_115 = * V_110 ? V_89 : V_88 ;
}
} else if ( * V_72 == '(' ) {
V_72 ++ ;
F_50 ( L_41 , V_109 - V_116 ) ;
V_115 = F_70 ( V_116 , V_110 , & V_72 ) ;
if ( V_115 == V_117 )
return ( V_117 ) ;
V_72 = F_55 ( V_72 ) ;
if ( * V_72 ++ != ')' )
return ( V_117 ) ;
} else if ( isdigit ( ( unsigned char ) * V_72 ) ) {
F_50 ( L_42 , V_109 - V_116 ) ;
* V_110 = strtol ( V_72 , & V_112 , 0 ) ;
if ( V_112 == V_72 )
return ( V_117 ) ;
V_115 = * V_110 ? V_89 : V_88 ;
V_72 = F_56 ( V_72 ) ;
} else if ( strncmp ( V_72 , L_43 , 7 ) == 0 && F_71 ( V_72 [ 7 ] ) ) {
V_72 = F_55 ( V_72 + 7 ) ;
F_50 ( L_44 , V_109 - V_116 ) ;
if ( * V_72 == '(' ) {
V_72 = F_55 ( V_72 + 1 ) ;
V_114 = true ;
} else {
V_114 = false ;
}
V_113 = F_58 ( V_72 ) ;
if ( V_113 < 0 ) {
V_115 = V_87 ;
} else {
* V_110 = ( V_90 [ V_113 ] != NULL ) ;
V_115 = * V_110 ? V_89 : V_88 ;
}
V_72 = F_56 ( V_72 ) ;
V_72 = F_55 ( V_72 ) ;
if ( V_114 && * V_72 ++ != ')' )
return ( V_117 ) ;
V_118 = false ;
} else if ( ! F_71 ( * V_72 ) ) {
F_50 ( L_45 , V_109 - V_116 ) ;
V_113 = F_58 ( V_72 ) ;
V_72 = F_56 ( V_72 ) ;
if ( V_113 < 0 ) {
V_115 = V_87 ;
V_72 = F_72 ( V_72 ) ;
} else if ( V_90 [ V_113 ] == NULL ) {
* V_110 = 0 ;
V_115 = V_88 ;
} else {
* V_110 = strtol ( V_90 [ V_113 ] , & V_112 , 0 ) ;
if ( * V_112 != '\0' || V_112 == V_90 [ V_113 ] )
return ( V_117 ) ;
V_115 = * V_110 ? V_89 : V_88 ;
V_72 = F_72 ( V_72 ) ;
}
V_118 = false ;
} else {
F_50 ( L_46 , V_109 - V_116 ) ;
return ( V_117 ) ;
}
* V_111 = V_72 ;
F_50 ( L_47 , V_109 - V_116 , * V_110 ) ;
return ( V_115 ) ;
}
static T_2
F_70 ( const struct V_109 * V_109 , int * V_110 , const char * * V_111 )
{
const struct V_119 * V_119 ;
const char * V_72 ;
int V_120 ;
T_2 V_115 , V_121 ;
F_50 ( L_48 , V_109 - V_116 ) ;
V_72 = * V_111 ;
V_115 = V_109 -> V_122 ( V_109 + 1 , V_110 , & V_72 ) ;
if ( V_115 == V_117 )
return ( V_117 ) ;
for (; ; ) {
V_72 = F_55 ( V_72 ) ;
for ( V_119 = V_109 -> V_119 ; V_119 -> V_123 != NULL ; V_119 ++ )
if ( strncmp ( V_72 , V_119 -> V_123 , strlen ( V_119 -> V_123 ) ) == 0 )
break;
if ( V_119 -> V_123 == NULL )
break;
V_72 += strlen ( V_119 -> V_123 ) ;
F_50 ( L_49 , V_109 - V_116 , V_119 -> V_123 ) ;
V_121 = V_109 -> V_122 ( V_109 + 1 , & V_120 , & V_72 ) ;
if ( V_121 == V_117 )
return ( V_117 ) ;
V_115 = V_119 -> V_124 ( V_110 , V_115 , * V_110 , V_121 , V_120 ) ;
}
* V_111 = V_72 ;
F_50 ( L_47 , V_109 - V_116 , * V_110 ) ;
F_50 ( L_50 , V_109 - V_116 , V_67 [ V_115 ] ) ;
return ( V_115 ) ;
}
static T_2
F_59 ( const char * * V_111 )
{
int V_125 ;
int V_120 = 0 ;
F_50 ( L_51 , * V_111 ) ;
V_118 = V_11 ? false : true ;
V_125 = F_70 ( V_116 , & V_120 , V_111 ) ;
F_50 ( L_52 , V_120 ) ;
return ( V_118 ? V_87 : V_125 == V_117 ? V_87 : V_125 ) ;
}
static const char *
F_55 ( const char * V_72 )
{
if ( V_16 || V_50 [ V_49 ] ) {
for (; isspace ( ( unsigned char ) * V_72 ) ; V_72 ++ )
if ( * V_72 == '\n' )
V_82 = V_83 ;
return ( V_72 ) ;
}
while ( * V_72 != '\0' )
if ( strncmp ( V_72 , L_33 , 3 ) == 0 )
V_72 += 3 ;
else if ( strncmp ( V_72 , L_34 , 2 ) == 0 )
V_72 += 2 ;
else switch ( V_71 ) {
case V_126 :
if ( strncmp ( V_72 , L_53 , 4 ) == 0 ) {
V_71 = V_127 ;
V_72 += 4 ;
} else if ( strncmp ( V_72 , L_54 , 3 ) == 0 ) {
V_71 = V_127 ;
V_72 += 3 ;
} else if ( strncmp ( V_72 , L_55 , 2 ) == 0 ) {
V_71 = V_128 ;
V_72 += 2 ;
} else if ( strncmp ( V_72 , L_56 , 2 ) == 0 ) {
V_71 = V_129 ;
V_72 += 2 ;
} else if ( strncmp ( V_72 , L_57 , 1 ) == 0 ) {
V_71 = V_130 ;
V_82 = V_86 ;
V_72 += 1 ;
} else if ( strncmp ( V_72 , L_58 , 1 ) == 0 ) {
V_71 = V_131 ;
V_82 = V_86 ;
V_72 += 1 ;
} else if ( strncmp ( V_72 , L_28 , 1 ) == 0 ) {
V_82 = V_83 ;
V_72 += 1 ;
} else if ( strchr ( L_59 , * V_72 ) != NULL ) {
V_72 += 1 ;
} else
return ( V_72 ) ;
continue;
case V_129 :
if ( strncmp ( V_72 , L_28 , 1 ) == 0 ) {
V_71 = V_126 ;
V_82 = V_83 ;
}
V_72 += 1 ;
continue;
case V_130 :
case V_131 :
if ( ( V_71 == V_130 && V_72 [ 0 ] == '\'' ) ||
( V_71 == V_131 && V_72 [ 0 ] == '\"' ) ) {
V_71 = V_126 ;
V_72 += 1 ;
} else if ( V_72 [ 0 ] == '\\' ) {
if ( V_72 [ 1 ] == '\0' )
V_72 += 1 ;
else
V_72 += 2 ;
} else if ( strncmp ( V_72 , L_28 , 1 ) == 0 ) {
if ( V_71 == V_130 )
error ( L_60 ) ;
else
error ( L_61 ) ;
} else
V_72 += 1 ;
continue;
case V_128 :
if ( strncmp ( V_72 , L_62 , 4 ) == 0 ) {
V_71 = V_132 ;
V_72 += 4 ;
} else if ( strncmp ( V_72 , L_63 , 3 ) == 0 ) {
V_71 = V_132 ;
V_72 += 3 ;
} else if ( strncmp ( V_72 , L_64 , 2 ) == 0 ) {
V_71 = V_126 ;
V_72 += 2 ;
} else
V_72 += 1 ;
continue;
case V_127 :
if ( * V_72 == '*' ) {
V_71 = V_128 ;
V_72 += 1 ;
} else if ( * V_72 == '/' ) {
V_71 = V_129 ;
V_72 += 1 ;
} else {
V_71 = V_126 ;
V_82 = V_86 ;
}
continue;
case V_132 :
if ( * V_72 == '/' ) {
V_71 = V_126 ;
V_72 += 1 ;
} else
V_71 = V_128 ;
continue;
default:
abort () ;
}
return ( V_72 ) ;
}
static const char *
F_72 ( const char * V_72 )
{
const char * V_133 = V_72 ;
int V_134 = 0 ;
V_72 = F_55 ( V_72 ) ;
if ( * V_72 != '(' )
return ( V_72 ) ;
do {
if ( * V_72 == '(' )
V_134 ++ ;
if ( * V_72 == ')' )
V_134 -- ;
V_72 = F_55 ( V_72 + 1 ) ;
} while ( V_134 != 0 && * V_72 != '\0' );
if ( V_134 == 0 )
return ( V_72 ) ;
else
return ( V_133 ) ;
}
static const char *
F_56 ( const char * V_72 )
{
while ( ! F_71 ( * V_72 ) )
++ V_72 ;
return ( V_72 ) ;
}
static int
F_58 ( const char * V_123 )
{
const char * V_72 ;
int V_135 ;
V_72 = F_56 ( V_123 ) ;
if ( V_72 == V_123 )
return ( - 1 ) ;
if ( V_14 ) {
if ( V_15 && V_85 )
printf ( L_65 , V_69 ? L_66 : L_28 , V_49 ) ;
V_85 = V_69 = false ;
printf ( L_67 ,
V_15 ? L_68 : L_66 ,
( int ) ( V_72 - V_123 ) , V_123 ,
V_15 ? L_66 : L_28 ) ;
return ( 0 ) ;
}
for ( V_135 = 0 ; V_135 < V_136 ; ++ V_135 ) {
if ( F_57 ( V_137 [ V_135 ] , V_123 , V_72 - V_123 ) == 0 ) {
F_50 ( L_69 , V_137 [ V_135 ] ,
V_90 [ V_135 ] ? V_90 [ V_135 ] : L_66 ) ;
return ( V_135 ) ;
}
}
return ( - 1 ) ;
}
static void
F_2 ( bool V_138 , bool V_139 , char * V_113 )
{
int V_135 ;
char * V_120 ;
V_135 = F_58 ( V_113 ) ;
if ( V_135 < 0 ) {
if ( V_136 >= V_140 )
F_5 ( 2 , L_70 ) ;
V_135 = V_136 ++ ;
}
V_137 [ V_135 ] = V_113 ;
V_91 [ V_135 ] = V_138 ;
V_120 = V_113 + ( F_56 ( V_113 ) - V_113 ) ;
if ( V_139 ) {
if ( * V_120 == '=' ) {
V_90 [ V_135 ] = V_120 + 1 ;
* V_120 = '\0' ;
} else if ( * V_120 == '\0' )
V_90 [ V_135 ] = L_71 ;
else
F_3 () ;
} else {
if ( * V_120 != '\0' )
F_3 () ;
V_90 [ V_135 ] = NULL ;
}
F_50 ( L_72 , V_137 [ V_135 ] ,
V_90 [ V_135 ] ? V_90 [ V_135 ] : L_73 ) ;
}
static int
F_57 ( const char * V_141 , const char * V_142 , T_4 V_143 )
{
while ( V_143 -- && * V_142 != '\0' )
if ( * V_141 != * V_142 )
return ( ( unsigned char ) * V_141 - ( unsigned char ) * V_142 ) ;
else
++ V_141 , ++ V_142 ;
return ( ( unsigned char ) * V_141 ) ;
}
static void
F_50 ( const char * V_144 , ... )
{
T_5 V_145 ;
if ( V_8 ) {
va_start ( V_145 , V_144 ) ;
F_73 ( V_144 , V_145 ) ;
va_end ( V_145 ) ;
}
}
static void
error ( const char * V_144 )
{
if ( V_49 == 0 )
F_74 ( L_74 , V_18 , V_56 , V_144 ) ;
else
F_74 ( L_75 ,
V_18 , V_56 , V_144 , V_55 [ V_49 ] , V_49 ) ;
F_51 () ;
F_5 ( 2 , L_76 ) ;
}
