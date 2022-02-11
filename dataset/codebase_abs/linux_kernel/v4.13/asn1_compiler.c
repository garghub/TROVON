static int F_1 ( const void * V_1 , const void * V_2 )
{
const struct V_3 * V_3 = V_1 ;
const char * const * V_4 = V_2 , * V_5 = * V_4 ;
T_1 V_6 , V_7 ;
int V_8 ;
V_6 = strlen ( V_5 ) ;
V_7 = ( V_6 < V_3 -> V_9 ) ? V_6 : V_3 -> V_9 ;
V_8 = memcmp ( V_3 -> V_10 , V_5 , V_7 ) ;
if ( V_8 != 0 ) {
return V_8 ;
}
if ( V_6 == V_3 -> V_9 ) {
return 0 ;
}
return V_6 - V_3 -> V_9 ;
}
static void F_2 ( char * V_11 , char * V_12 )
{
struct V_3 * V_13 ;
char * line , * V_14 , * V_15 , * V_16 , * V_17 ;
unsigned V_18 , V_19 ;
V_20 = V_13 = calloc ( ( V_12 - V_11 ) / 2 , sizeof( struct V_3 ) ) ;
if ( ! V_13 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_18 = 0 ;
V_19 = 0 ;
while ( V_11 < V_12 ) {
V_19 ++ ;
line = V_11 ;
V_14 = memchr ( line , '\n' , V_12 - V_11 ) ;
if ( ! V_14 ) {
V_11 = V_14 = V_12 ;
} else {
V_11 = V_14 + 1 ;
* V_14 = '\0' ;
}
V_16 = line ;
V_21:
while ( ( V_16 = memchr ( V_16 , '-' , V_14 - V_16 ) ) ) {
if ( V_16 [ 1 ] == '-' ) {
V_17 = V_16 + 2 ;
while ( ( V_17 = memchr ( V_17 , '-' , V_14 - V_17 ) ) ) {
if ( V_17 [ 1 ] == '-' ) {
V_17 += 2 ;
memmove ( V_16 , V_17 , V_14 - V_17 ) ;
goto V_21;
}
V_17 ++ ;
}
* V_16 = '\0' ;
V_14 = V_16 ;
break;
} else {
V_16 ++ ;
}
}
V_16 = line ;
while ( V_16 < V_14 ) {
while ( V_16 < V_14 && isspace ( * V_16 ) )
* ( V_16 ++ ) = 0 ;
if ( V_16 >= V_14 )
break;
V_13 [ V_18 ] . line = V_19 ;
V_15 = V_16 ;
if ( isalpha ( * V_16 ) ) {
const char * * V_5 , * V_15 = V_16 ;
V_17 = V_16 + 1 ;
while ( V_17 < V_14 && ( isalnum ( * V_17 ) || * V_17 == '-' || * V_17 == '_' ) )
V_17 ++ ;
V_13 [ V_18 ] . V_9 = V_17 - V_16 ;
V_16 = V_17 ;
V_13 [ V_18 ] . V_10 = malloc ( V_13 [ V_18 ] . V_9 + 1 ) ;
if ( ! V_13 [ V_18 ] . V_10 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
memcpy ( V_13 [ V_18 ] . V_10 , V_15 , V_13 [ V_18 ] . V_9 ) ;
V_13 [ V_18 ] . V_10 [ V_13 [ V_18 ] . V_9 ] = 0 ;
if ( islower ( V_13 [ V_18 ] . V_10 [ 0 ] ) ) {
V_13 [ V_18 ++ ] . V_22 = V_23 ;
continue;
}
V_5 = bsearch ( & V_13 [ V_18 ] , V_24 ,
sizeof( V_24 ) / sizeof( V_24 [ 1 ] ) ,
sizeof( V_24 [ 1 ] ) ,
F_1 ) ;
if ( V_5 ) {
V_13 [ V_18 ++ ] . V_22 = V_5 - V_24 ;
continue;
}
V_13 [ V_18 ++ ] . V_22 = V_25 ;
continue;
}
if ( isdigit ( * V_16 ) ) {
V_17 = V_16 + 1 ;
while ( V_17 < V_14 && ( isdigit ( * V_17 ) ) )
V_17 ++ ;
V_13 [ V_18 ] . V_9 = V_17 - V_16 ;
V_16 = V_17 ;
V_13 [ V_18 ] . V_10 = malloc ( V_13 [ V_18 ] . V_9 + 1 ) ;
if ( ! V_13 [ V_18 ] . V_10 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
memcpy ( V_13 [ V_18 ] . V_10 , V_15 , V_13 [ V_18 ] . V_9 ) ;
V_13 [ V_18 ] . V_10 [ V_13 [ V_18 ] . V_9 ] = 0 ;
V_13 [ V_18 ++ ] . V_22 = V_26 ;
continue;
}
if ( V_14 - V_16 >= 3 ) {
if ( memcmp ( V_16 , L_1 , 3 ) == 0 ) {
V_16 += 3 ;
V_13 [ V_18 ] . V_9 = 3 ;
V_13 [ V_18 ] . V_10 = L_1 ;
V_13 [ V_18 ++ ] . V_22 = V_27 ;
continue;
}
}
if ( V_14 - V_16 >= 2 ) {
if ( memcmp ( V_16 , L_2 , 2 ) == 0 ) {
V_16 += 2 ;
V_13 [ V_18 ] . V_9 = 2 ;
V_13 [ V_18 ] . V_10 = L_2 ;
V_13 [ V_18 ++ ] . V_22 = V_28 ;
continue;
}
if ( memcmp ( V_16 , L_3 , 2 ) == 0 ) {
V_16 += 2 ;
V_13 [ V_18 ] . V_9 = 2 ;
V_13 [ V_18 ] . V_10 = L_3 ;
V_13 [ V_18 ++ ] . V_22 = V_29 ;
continue;
}
}
if ( V_14 - V_16 >= 1 ) {
V_13 [ V_18 ] . V_9 = 1 ;
switch ( * V_16 ) {
case '{' :
V_16 += 1 ;
V_13 [ V_18 ] . V_10 = L_4 ;
V_13 [ V_18 ++ ] . V_22 = V_30 ;
continue;
case '}' :
V_16 += 1 ;
V_13 [ V_18 ] . V_10 = L_5 ;
V_13 [ V_18 ++ ] . V_22 = V_31 ;
continue;
case '[' :
V_16 += 1 ;
V_13 [ V_18 ] . V_10 = L_6 ;
V_13 [ V_18 ++ ] . V_22 = V_32 ;
continue;
case ']' :
V_16 += 1 ;
V_13 [ V_18 ] . V_10 = L_7 ;
V_13 [ V_18 ++ ] . V_22 = V_33 ;
continue;
case ',' :
V_16 += 1 ;
V_13 [ V_18 ] . V_10 = L_8 ;
V_13 [ V_18 ++ ] . V_22 = V_34 ;
continue;
default:
break;
}
}
fprintf ( V_35 , L_9 ,
V_36 , V_19 , * V_16 ) ;
exit ( 1 ) ;
}
}
V_37 = V_18 ;
F_3 ( L_10 , V_37 ) ;
#if 0
{
int n;
for (n = 0; n < nr_tokens; n++)
debug("Token %3u: '%s'\n", n, token_list[n].content);
}
#endif
}
int main ( int V_38 , char * * V_39 )
{
struct V_40 V_41 ;
T_2 V_42 ;
T_3 * V_43 , * V_44 ;
char * V_11 , * V_16 ;
char * V_45 ;
int V_46 ;
V_45 = getenv ( L_11 ) ;
if ( V_45 )
V_47 = atoi ( V_45 ) ;
while ( V_38 > 4 ) {
if ( strcmp ( V_39 [ 1 ] , L_12 ) == 0 )
V_47 = true ;
else if ( strcmp ( V_39 [ 1 ] , L_13 ) == 0 )
V_48 = true ;
else
break;
memmove ( & V_39 [ 1 ] , & V_39 [ 2 ] , ( V_38 - 2 ) * sizeof( char * ) ) ;
V_38 -- ;
}
if ( V_38 != 4 ) {
fprintf ( V_35 , L_14 ,
V_39 [ 0 ] ) ;
exit ( 2 ) ;
}
V_36 = V_39 [ 1 ] ;
V_49 = V_39 [ 2 ] ;
V_50 = V_39 [ 3 ] ;
V_46 = F_4 ( V_36 , V_51 ) ;
if ( V_46 < 0 ) {
perror ( V_36 ) ;
exit ( 1 ) ;
}
if ( F_5 ( V_46 , & V_41 ) < 0 ) {
perror ( V_36 ) ;
exit ( 1 ) ;
}
if ( ! ( V_11 = malloc ( V_41 . V_52 + 1 ) ) ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
if ( ( V_42 = F_6 ( V_46 , V_11 , V_41 . V_52 ) ) < 0 ) {
perror ( V_36 ) ;
exit ( 1 ) ;
}
if ( F_7 ( V_46 ) < 0 ) {
perror ( V_36 ) ;
exit ( 1 ) ;
}
if ( V_42 != V_41 . V_52 ) {
fprintf ( V_35 , L_15 , V_36 ) ;
exit ( 1 ) ;
}
V_16 = strrchr ( V_39 [ 1 ] , '/' ) ;
V_16 = V_16 ? V_16 + 1 : V_39 [ 1 ] ;
V_53 = F_8 ( V_16 ) ;
if ( ! V_16 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_16 = strchr ( V_53 , '.' ) ;
if ( V_16 )
* V_16 = '\0' ;
V_11 [ V_42 ] = 0 ;
F_2 ( V_11 , V_11 + V_42 ) ;
F_9 () ;
F_10 () ;
F_11 () ;
V_43 = fopen ( V_49 , L_16 ) ;
if ( ! V_43 ) {
perror ( V_49 ) ;
exit ( 1 ) ;
}
V_44 = fopen ( V_50 , L_16 ) ;
if ( ! V_44 ) {
perror ( V_50 ) ;
exit ( 1 ) ;
}
F_12 ( V_43 , V_44 ) ;
if ( fclose ( V_43 ) < 0 ) {
perror ( V_49 ) ;
exit ( 1 ) ;
}
if ( fclose ( V_44 ) < 0 ) {
perror ( V_50 ) ;
exit ( 1 ) ;
}
return 0 ;
}
static int F_13 ( const void * V_54 , const void * V_55 )
{
const struct type * const * V_56 = V_54 , * const * V_57 = V_55 ;
if ( ( * V_56 ) -> V_58 -> V_9 != ( * V_57 ) -> V_58 -> V_9 )
return ( * V_56 ) -> V_58 -> V_9 - ( * V_57 ) -> V_58 -> V_9 ;
else
return memcmp ( ( * V_56 ) -> V_58 -> V_10 , ( * V_57 ) -> V_58 -> V_10 ,
( * V_56 ) -> V_58 -> V_9 ) ;
}
static int F_14 ( const void * V_1 , const void * V_59 )
{
const struct V_3 * V_3 = V_1 ;
const struct type * const * V_60 = V_59 ;
const struct type * type = * V_60 ;
if ( V_3 -> V_9 != type -> V_58 -> V_9 )
return V_3 -> V_9 - type -> V_58 -> V_9 ;
else
return memcmp ( V_3 -> V_10 , type -> V_58 -> V_10 ,
V_3 -> V_9 ) ;
}
static void F_9 ( void )
{
struct type * V_61 ;
unsigned V_62 , V_63 , V_64 ;
V_62 = 0 ;
for ( V_64 = 0 ; V_64 < V_37 - 1 ; V_64 ++ )
if ( V_20 [ V_64 + 0 ] . V_22 == V_25 &&
V_20 [ V_64 + 1 ] . V_22 == V_27 )
V_62 ++ ;
if ( V_62 == 0 ) {
fprintf ( V_35 , L_17 , V_36 ) ;
exit ( 1 ) ;
}
V_65 = V_62 ;
V_61 = V_66 = calloc ( V_62 + 1 , sizeof( V_66 [ 0 ] ) ) ;
if ( ! V_66 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_67 = calloc ( V_62 , sizeof( V_67 [ 0 ] ) ) ;
if ( ! V_67 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_63 = 0 ;
V_61 [ V_63 ] . V_68 |= V_69 ;
for ( V_64 = 0 ; V_64 < V_37 - 1 ; V_64 ++ ) {
if ( V_20 [ V_64 + 0 ] . V_22 == V_25 &&
V_20 [ V_64 + 1 ] . V_22 == V_27 ) {
V_61 [ V_63 ] . V_58 = & V_20 [ V_64 ] ;
V_67 [ V_63 ] = & V_61 [ V_63 ] ;
V_63 ++ ;
}
}
V_61 [ V_63 ] . V_58 = & V_20 [ V_64 + 1 ] ;
V_61 [ V_63 ] . V_68 |= V_70 ;
qsort ( V_67 , V_62 , sizeof( V_67 [ 0 ] ) , F_13 ) ;
F_3 ( L_18 , V_65 ) ;
#if 0
for (n = 0; n < nr_types; n++) {
struct type *type = type_index[n];
debug("- %*.*s\n", type->name->content);
}
#endif
}
static void F_10 ( void )
{
struct V_3 * V_71 ;
struct type * type ;
type = V_66 ;
do {
V_71 = type -> V_58 ;
if ( V_71 [ 0 ] . V_22 != V_25 ||
V_71 [ 1 ] . V_22 != V_27 )
abort () ;
V_71 += 2 ;
type -> V_72 = F_15 ( & V_71 , type [ 1 ] . V_58 , NULL ) ;
type -> V_72 -> V_73 = type ;
if ( V_71 != type [ 1 ] . V_58 ) {
fprintf ( V_35 , L_19 ,
V_36 , V_71 -> line , V_71 -> V_10 ) ;
exit ( 1 ) ;
}
} while ( type ++ , ! ( type -> V_68 & V_70 ) );
F_3 ( L_20 , V_74 ) ;
}
static struct V_72 * F_16 ( struct V_3 * type )
{
struct V_72 * V_75 = calloc ( 1 , sizeof( * V_75 ) ) ;
if ( ! V_75 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_75 -> V_76 = V_77 ;
V_77 = V_75 ;
return V_75 ;
}
static struct V_72 * F_15 ( struct V_3 * * V_78 , struct V_3 * V_12 ,
struct V_3 * V_58 )
{
struct V_72 * V_79 , * V_72 ;
struct V_80 * V_80 , * * V_81 ;
struct V_3 * V_71 = * V_78 ;
struct type * * V_82 ;
char * V_16 ;
int V_83 = 0 , V_84 = 0 ;
V_79 = V_72 = F_16 ( V_71 ) ;
V_72 -> V_85 = V_86 ;
V_72 -> V_87 = V_88 ;
V_72 -> V_89 = V_90 [ V_71 -> V_22 ] ;
V_72 -> V_58 = V_58 ;
if ( V_71 -> V_22 == V_32 ) {
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_91;
switch ( V_71 -> V_22 ) {
case V_92 :
V_72 -> V_85 = V_86 ;
V_71 ++ ;
break;
case V_93 :
V_72 -> V_85 = V_94 ;
V_71 ++ ;
break;
case V_26 :
V_72 -> V_85 = V_95 ;
break;
case V_96 :
V_72 -> V_85 = V_97 ;
V_71 ++ ;
break;
default:
fprintf ( V_35 , L_21 ,
V_36 , V_71 -> line , V_71 -> V_10 ) ;
exit ( 1 ) ;
}
if ( V_71 >= V_12 )
goto V_91;
if ( V_71 -> V_22 != V_26 ) {
fprintf ( V_35 , L_22 ,
V_36 , V_71 -> line , V_71 -> V_10 ) ;
exit ( 1 ) ;
}
V_72 -> V_89 &= ~ 0x1f ;
V_72 -> V_89 |= strtoul ( V_71 -> V_10 , & V_16 , 10 ) ;
V_72 -> V_68 |= V_98 ;
if ( V_16 - V_71 -> V_10 != V_71 -> V_9 )
abort () ;
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_91;
if ( V_71 -> V_22 != V_33 ) {
fprintf ( V_35 , L_23 ,
V_36 , V_71 -> line , V_71 -> V_10 ) ;
exit ( 1 ) ;
}
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_91;
V_83 = 1 ;
}
if ( V_71 -> V_22 == V_99 ) {
V_72 -> V_68 |= V_100 ;
V_84 = 1 ;
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_91;
} else if ( V_71 -> V_22 == V_101 ) {
V_72 -> V_68 |= V_102 ;
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_91;
}
if ( V_83 ) {
if ( ! V_84 )
V_72 -> V_87 |= V_103 ;
V_72 -> V_104 = V_84 ? V_105 : V_106 ;
V_72 -> V_107 = F_16 ( V_71 ) ;
V_72 = V_72 -> V_107 ;
V_72 -> V_85 = V_86 ;
V_72 -> V_87 = V_88 ;
V_72 -> V_89 = V_90 [ V_71 -> V_22 ] ;
V_72 -> V_58 = V_58 ;
}
V_72 -> type = V_71 ;
switch ( V_71 -> V_22 ) {
case V_108 :
V_72 -> V_104 = V_109 ;
V_71 ++ ;
break;
case V_110 :
case V_111 :
case V_112 :
case V_113 :
V_72 -> V_104 = V_114 ;
V_71 ++ ;
break;
case V_115 :
V_72 -> V_87 = V_103 ;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
V_72 -> V_104 = V_114 ;
V_71 ++ ;
break;
case V_132 :
case V_133 :
V_72 -> V_104 = V_114 ;
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_91;
if ( V_71 -> V_22 != V_134 )
goto V_135;
V_71 ++ ;
break;
case V_136 :
V_72 -> V_104 = V_114 ;
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_91;
if ( V_71 -> V_22 != V_137 )
goto V_135;
V_71 ++ ;
break;
case V_25 :
V_72 -> V_104 = V_138 ;
V_82 = bsearch ( V_71 , V_67 , V_65 , sizeof( V_67 [ 0 ] ) ,
F_14 ) ;
if ( ! V_82 ) {
fprintf ( V_35 , L_24 ,
V_36 , V_71 -> line , V_71 -> V_10 ) ;
exit ( 1 ) ;
}
V_71 -> type = * V_82 ;
( * V_82 ) -> V_139 ++ ;
V_71 ++ ;
break;
case V_140 :
V_72 -> V_104 = V_141 ;
V_71 ++ ;
V_72 -> V_107 = F_17 ( & V_71 , V_12 , 1 ) ;
break;
case V_142 :
V_72 -> V_104 = V_106 ;
V_72 -> V_87 = V_103 ;
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_91;
if ( V_71 -> V_22 == V_143 ) {
V_72 -> V_104 = V_144 ;
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_91;
V_72 -> V_107 = F_15 ( & V_71 , V_12 , NULL ) ;
} else {
V_72 -> V_107 = F_17 ( & V_71 , V_12 , 0 ) ;
}
break;
case V_145 :
V_72 -> V_104 = V_146 ;
V_72 -> V_87 = V_103 ;
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_91;
if ( V_71 -> V_22 == V_143 ) {
V_72 -> V_104 = V_147 ;
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_135;
V_72 -> V_107 = F_15 ( & V_71 , V_12 , NULL ) ;
} else {
V_72 -> V_107 = F_17 ( & V_71 , V_12 , 1 ) ;
}
break;
default:
fprintf ( V_35 , L_25 ,
V_36 , V_71 -> line , V_71 -> V_10 ) ;
exit ( 1 ) ;
}
if ( V_71 < V_12 && ( V_71 -> V_22 == V_148 ||
V_71 -> V_22 == V_149 )
) {
V_71 ++ ;
V_79 -> V_68 |= V_150 ;
}
if ( V_71 < V_12 && V_71 -> V_22 == V_28 ) {
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_91;
if ( V_71 -> V_22 != V_23 ) {
fprintf ( V_35 , L_26 ,
V_36 , V_71 -> line , V_71 -> V_10 ) ;
exit ( 1 ) ;
}
V_80 = malloc ( sizeof( struct V_80 ) ) ;
if ( ! V_80 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_80 -> V_151 = 0 ;
V_80 -> V_58 = V_71 -> V_10 ;
for ( V_81 = & V_152 ;
* V_81 ;
V_81 = & ( * V_81 ) -> V_153
) {
int V_154 = strcmp ( V_80 -> V_58 , ( * V_81 ) -> V_58 ) ;
if ( V_154 == 0 ) {
free ( V_80 ) ;
V_80 = * V_81 ;
goto V_155;
}
if ( V_154 < 0 ) {
V_80 -> V_153 = * V_81 ;
* V_81 = V_80 ;
V_74 ++ ;
goto V_155;
}
}
V_80 -> V_153 = NULL ;
* V_81 = V_80 ;
V_74 ++ ;
V_155:
V_72 -> V_80 = V_80 ;
V_71 -> V_80 = V_80 ;
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_91;
if ( V_71 -> V_22 != V_29 ) {
fprintf ( V_35 , L_27 ,
V_36 , V_71 -> line , V_71 -> V_10 ) ;
exit ( 1 ) ;
}
V_71 ++ ;
}
* V_78 = V_71 ;
return V_79 ;
V_135:
fprintf ( V_35 , L_28 ,
V_36 , V_71 -> line , V_71 -> V_10 ) ;
exit ( 1 ) ;
V_91:
fprintf ( V_35 , L_29 , V_36 ) ;
exit ( 1 ) ;
}
static struct V_72 * F_17 ( struct V_3 * * V_78 , struct V_3 * V_12 ,
int V_156 )
{
struct V_72 * V_107 , * * V_157 = & V_107 , * V_72 ;
struct V_3 * V_71 = * V_78 , * V_58 ;
if ( V_71 -> V_22 != V_30 ) {
fprintf ( V_35 , L_30 ,
V_36 , V_71 -> line , V_71 -> V_10 ) ;
exit ( 1 ) ;
}
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_91;
if ( V_71 -> V_22 == V_30 ) {
fprintf ( V_35 , L_31 ,
V_36 , V_71 -> line ) ;
exit ( 1 ) ;
}
for (; ; ) {
V_58 = NULL ;
if ( V_71 -> V_22 == V_23 ) {
V_58 = V_71 ;
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_91;
}
V_72 = F_15 ( & V_71 , V_12 , V_58 ) ;
if ( V_156 )
V_72 -> V_68 |= V_150 | V_158 ;
* V_157 = V_72 ;
V_157 = & V_72 -> V_153 ;
if ( V_71 >= V_12 )
goto V_91;
if ( V_71 -> V_22 != V_34 )
break;
V_71 ++ ;
if ( V_71 >= V_12 )
goto V_91;
}
V_107 -> V_68 &= ~ V_158 ;
if ( V_71 -> V_22 != V_31 ) {
fprintf ( V_35 , L_32 ,
V_36 , V_71 -> line , V_71 -> V_10 ) ;
exit ( 1 ) ;
}
V_71 ++ ;
* V_78 = V_71 ;
return V_107 ;
V_91:
fprintf ( V_35 , L_29 , V_36 ) ;
exit ( 1 ) ;
}
static void F_18 ( const struct V_72 * V_75 , int V_159 )
{
const struct V_72 * V_160 ;
const struct type * V_63 = V_75 -> V_73 ;
const char * V_58 = V_75 -> V_58 ? V_75 -> V_58 -> V_10 : L_33 ;
const char * V_161 = V_63 && V_63 -> V_58 ? V_63 -> V_58 -> V_10 : L_33 ;
char V_89 [ 32 ] ;
if ( V_75 -> V_85 == 0 && V_75 -> V_87 == 0 && V_75 -> V_89 == 0 )
strcpy ( V_89 , L_34 ) ;
else if ( V_75 -> V_85 == V_86 )
sprintf ( V_89 , L_35 ,
V_162 [ V_75 -> V_85 ] ,
V_163 [ V_75 -> V_87 ] ,
V_164 [ V_75 -> V_89 ] ) ;
else
sprintf ( V_89 , L_36 ,
V_162 [ V_75 -> V_85 ] ,
V_163 [ V_75 -> V_87 ] ,
V_75 -> V_89 ) ;
printf ( L_37 ,
V_75 -> V_68 & V_100 ? 'I' : '-' ,
V_75 -> V_68 & V_102 ? 'E' : '-' ,
V_75 -> V_68 & V_98 ? 'T' : '-' ,
V_75 -> V_68 & V_150 ? 'S' : '-' ,
V_75 -> V_68 & V_158 ? 'C' : '-' ,
L_38 [ V_75 -> V_104 ] ,
V_159 , L_39 ,
V_89 ,
V_161 ,
V_58 ,
V_75 -> V_80 ? V_75 -> V_80 -> V_58 : L_39 ) ;
if ( V_75 -> V_104 == V_138 )
F_18 ( V_75 -> type -> type -> V_72 , V_159 + 3 ) ;
else
for ( V_160 = V_75 -> V_107 ; V_160 ; V_160 = V_160 -> V_153 )
F_18 ( V_160 , V_159 + 3 ) ;
}
static void F_11 ( void )
{
if ( V_48 )
F_18 ( V_66 [ 0 ] . V_72 , 0 ) ;
}
static void F_19 ( T_3 * V_43 , const char * V_165 , ... )
{
T_4 V_166 ;
if ( V_43 ) {
fprintf ( V_43 , L_40 , V_167 , V_168 , L_39 ) ;
va_start ( V_166 , V_165 ) ;
vfprintf ( V_43 , V_165 , V_166 ) ;
va_end ( V_166 ) ;
}
V_167 ++ ;
}
static void F_20 ( T_3 * V_43 , const char * V_165 , ... )
{
T_4 V_166 ;
if ( V_43 ) {
va_start ( V_166 , V_165 ) ;
vfprintf ( V_43 , V_165 , V_166 ) ;
va_end ( V_166 ) ;
}
}
static void F_12 ( T_3 * V_43 , T_3 * V_44 )
{
struct V_72 * V_75 ;
struct V_80 * V_80 ;
struct type * V_169 ;
int V_151 ;
fprintf ( V_44 , L_41 ) ;
fprintf ( V_44 , L_42 ) ;
fprintf ( V_44 , L_43 ) ;
fprintf ( V_44 , L_44 , V_53 ) ;
fprintf ( V_44 , L_45 ) ;
fprintf ( V_44 , L_46 ) ;
fprintf ( V_44 , L_47 ) ;
fprintf ( V_44 , L_48 , V_53 ) ;
if ( ferror ( V_44 ) ) {
perror ( V_50 ) ;
exit ( 1 ) ;
}
fprintf ( V_43 , L_41 ) ;
fprintf ( V_43 , L_42 ) ;
fprintf ( V_43 , L_43 ) ;
fprintf ( V_43 , L_44 , V_53 ) ;
fprintf ( V_43 , L_45 ) ;
fprintf ( V_43 , L_49 ) ;
fprintf ( V_43 , L_50 , V_53 ) ;
fprintf ( V_43 , L_47 ) ;
if ( ferror ( V_43 ) ) {
perror ( V_49 ) ;
exit ( 1 ) ;
}
fprintf ( V_44 , L_47 ) ;
V_151 = 0 ;
for ( V_80 = V_152 ; V_80 ; V_80 = V_80 -> V_153 ) {
V_80 -> V_151 = V_151 ++ ;
fprintf ( V_44 ,
L_51
L_52 ,
V_80 -> V_58 ) ;
}
fprintf ( V_44 , L_47 ) ;
fprintf ( V_43 , L_53 , V_53 ) ;
for ( V_80 = V_152 ; V_80 ; V_80 = V_80 -> V_153 )
fprintf ( V_43 , L_54 ,
V_80 -> V_58 , V_80 -> V_151 ) ;
fprintf ( V_43 , L_55 , V_53 , V_74 ) ;
fprintf ( V_43 , L_56 ) ;
fprintf ( V_43 , L_47 ) ;
fprintf ( V_43 , L_57 ,
V_53 , V_53 ) ;
for ( V_80 = V_152 ; V_80 ; V_80 = V_80 -> V_153 )
fprintf ( V_43 , L_58 , V_80 -> V_151 , V_80 -> V_58 ) ;
fprintf ( V_43 , L_56 ) ;
if ( ferror ( V_43 ) ) {
perror ( V_49 ) ;
exit ( 1 ) ;
}
F_3 ( L_59 ) ;
V_167 = 0 ;
V_169 = & V_66 [ 0 ] ;
F_21 ( NULL , V_169 -> V_72 , NULL ) ;
F_19 ( NULL , L_60 ) ;
F_22 ( NULL ) ;
for ( V_75 = V_77 ; V_75 ; V_75 = V_75 -> V_76 )
V_75 -> V_68 &= ~ V_170 ;
F_3 ( L_61 ) ;
fprintf ( V_43 , L_47 ) ;
fprintf ( V_43 , L_62 ,
V_53 ) ;
V_167 = 0 ;
V_169 = & V_66 [ 0 ] ;
F_21 ( V_43 , V_169 -> V_72 , NULL ) ;
F_19 ( V_43 , L_60 ) ;
F_22 ( V_43 ) ;
fprintf ( V_43 , L_56 ) ;
fprintf ( V_43 , L_47 ) ;
fprintf ( V_43 , L_63 , V_53 ) ;
fprintf ( V_43 , L_64 , V_53 ) ;
fprintf ( V_43 , L_65 , V_53 ) ;
fprintf ( V_43 , L_66 , V_53 ) ;
fprintf ( V_43 , L_56 ) ;
}
static void F_22 ( T_3 * V_43 )
{
struct V_72 * V_75 , * V_171 ;
const char * V_172 ;
int V_173 ;
while ( ( V_75 = V_174 ) ) {
V_174 = V_75 -> V_175 ;
if ( ! V_174 )
V_176 = & V_174 ;
F_20 ( V_43 , L_47 ) ;
V_75 -> V_177 = V_173 = V_167 ;
V_168 ++ ;
for ( V_171 = V_75 -> V_107 ; V_171 ; V_171 = V_171 -> V_153 )
F_21 ( V_43 , V_171 , NULL ) ;
V_168 -- ;
V_172 = V_75 -> V_80 ? L_67 : L_39 ;
switch ( V_75 -> V_104 ) {
case V_106 :
F_19 ( V_43 , L_68 , V_172 ) ;
break;
case V_144 :
F_19 ( V_43 , L_69 , V_172 ) ;
F_19 ( V_43 , L_70 , V_173 ) ;
break;
case V_146 :
F_19 ( V_43 , L_71 , V_172 ) ;
break;
case V_147 :
F_19 ( V_43 , L_72 , V_172 ) ;
F_19 ( V_43 , L_70 , V_173 ) ;
break;
default:
break;
}
if ( V_75 -> V_80 )
F_19 ( V_43 , L_73 ,
V_75 -> V_80 -> V_58 ) ;
F_19 ( V_43 , L_74 ) ;
}
}
static void F_21 ( T_3 * V_43 , struct V_72 * V_75 , struct V_72 * V_89 )
{
struct V_72 * V_178 , * V_179 ;
const char * V_180 , * V_172 ;
int V_173 , V_181 = 0 , V_182 = 0 ;
if ( V_75 -> V_68 & V_150 ||
( V_89 && V_89 -> V_68 & V_150 ) )
V_181 = 1 ;
if ( ( V_75 -> V_73 && V_75 -> V_73 -> V_139 > 1 ) ||
V_181 )
V_182 = 1 ;
if ( V_75 -> V_73 && V_43 ) {
F_20 ( V_43 , L_75 , V_75 -> V_73 -> V_58 -> V_10 ) ;
}
V_180 = ( V_75 -> V_68 & V_158 ||
( V_89 && V_89 -> V_68 & V_158 ) ) ? L_76 : L_39 ;
V_172 = V_75 -> V_80 ? L_67 : L_39 ;
switch ( V_75 -> V_104 ) {
case V_109 :
F_19 ( V_43 , L_77 ,
V_180 , V_172 , V_181 ? L_78 : L_39 ) ;
if ( V_75 -> V_58 )
F_20 ( V_43 , L_79 , V_75 -> V_58 -> V_10 ) ;
F_20 ( V_43 , L_47 ) ;
goto V_183;
case V_105 :
F_21 ( V_43 , V_75 -> V_107 , V_75 ) ;
return;
case V_106 :
case V_144 :
case V_146 :
case V_147 :
F_19 ( V_43 , L_80 ,
V_180 ,
V_182 ? L_81 : L_39 ,
V_181 ? L_78 : L_39 ) ;
break;
case V_141 :
goto V_183;
case V_138 :
if ( V_75 -> V_85 == V_86 && V_75 -> V_87 == V_88 && V_75 -> V_89 == 0 )
goto V_183;
default:
F_19 ( V_43 , L_80 ,
V_180 , V_172 ,
V_181 ? L_78 : L_39 ) ;
break;
}
V_179 = V_89 ? : V_75 ;
if ( V_179 -> V_58 )
F_20 ( V_43 , L_79 , V_179 -> V_58 -> V_10 ) ;
F_20 ( V_43 , L_47 ) ;
if ( ! V_89 || ! ( V_89 -> V_68 & V_98 ) )
V_89 = V_75 ;
if ( V_89 -> V_85 == V_86 &&
V_89 -> V_89 != 14 &&
V_89 -> V_89 != 15 &&
V_89 -> V_89 != 31 )
F_19 ( V_43 , L_82 ,
V_162 [ V_89 -> V_85 ] ,
V_163 [ V_89 -> V_87 | V_75 -> V_87 ] ,
V_164 [ V_89 -> V_89 ] ) ;
else
F_19 ( V_43 , L_83 ,
V_162 [ V_89 -> V_85 ] ,
V_163 [ V_89 -> V_87 | V_75 -> V_87 ] ,
V_89 -> V_89 ) ;
V_89 = NULL ;
V_183:
switch ( V_75 -> V_104 ) {
case V_138 :
F_21 ( V_43 , V_75 -> type -> type -> V_72 , V_89 ) ;
if ( V_75 -> V_80 )
F_19 ( V_43 , L_84 ,
V_181 ? L_85 : L_39 ) ;
break;
case V_106 :
if ( V_182 ) {
F_19 ( V_43 , L_86 , V_75 -> V_177 ) ;
if ( V_75 -> V_73 && V_75 -> V_73 -> V_58 )
F_20 ( V_43 , L_87 ,
V_75 -> V_73 -> V_58 -> V_10 ) ;
F_20 ( V_43 , L_47 ) ;
if ( ! ( V_75 -> V_68 & V_170 ) ) {
V_75 -> V_68 |= V_170 ;
* V_176 = V_75 ;
V_176 = & V_75 -> V_175 ;
}
return;
} else {
V_168 ++ ;
for ( V_178 = V_75 -> V_107 ; V_178 ; V_178 = V_178 -> V_153 )
F_21 ( V_43 , V_178 , NULL ) ;
V_168 -- ;
F_19 ( V_43 , L_68 , V_172 ) ;
}
break;
case V_144 :
case V_147 :
if ( V_182 ) {
F_19 ( V_43 , L_86 , V_75 -> V_177 ) ;
if ( V_75 -> V_73 && V_75 -> V_73 -> V_58 )
F_20 ( V_43 , L_87 ,
V_75 -> V_73 -> V_58 -> V_10 ) ;
F_20 ( V_43 , L_47 ) ;
if ( ! ( V_75 -> V_68 & V_170 ) ) {
V_75 -> V_68 |= V_170 ;
* V_176 = V_75 ;
V_176 = & V_75 -> V_175 ;
}
return;
} else {
V_173 = V_167 ;
V_168 ++ ;
F_21 ( V_43 , V_75 -> V_107 , NULL ) ;
V_168 -- ;
if ( V_75 -> V_104 == V_144 )
F_19 ( V_43 , L_69 , V_172 ) ;
else
F_19 ( V_43 , L_72 , V_172 ) ;
F_19 ( V_43 , L_70 , V_173 ) ;
}
break;
case V_146 :
fprintf ( V_35 , L_88 ) ;
exit ( 1 ) ;
case V_141 :
for ( V_178 = V_75 -> V_107 ; V_178 ; V_178 = V_178 -> V_153 )
F_21 ( V_43 , V_178 , V_178 ) ;
if ( ! V_181 )
F_19 ( V_43 , L_89 ) ;
if ( V_75 -> V_80 )
F_19 ( V_43 , L_90 ) ;
break;
default:
break;
}
if ( V_75 -> V_80 )
F_19 ( V_43 , L_73 , V_75 -> V_80 -> V_58 ) ;
}
