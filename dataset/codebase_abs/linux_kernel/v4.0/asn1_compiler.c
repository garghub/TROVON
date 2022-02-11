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
char * line , * V_14 , * V_15 , * V_16 ;
unsigned V_17 , V_18 ;
V_19 = V_13 = calloc ( ( V_12 - V_11 ) / 2 , sizeof( struct V_3 ) ) ;
if ( ! V_13 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_17 = 0 ;
V_18 = 0 ;
while ( V_11 < V_12 ) {
V_18 ++ ;
line = V_11 ;
V_14 = memchr ( line , '\n' , V_12 - V_11 ) ;
if ( ! V_14 ) {
V_11 = V_14 = V_12 ;
} else {
V_11 = V_14 + 1 ;
* V_14 = '\0' ;
}
V_15 = line ;
V_20:
while ( ( V_15 = memchr ( V_15 , '-' , V_14 - V_15 ) ) ) {
if ( V_15 [ 1 ] == '-' ) {
V_16 = V_15 + 2 ;
while ( ( V_16 = memchr ( V_16 , '-' , V_14 - V_16 ) ) ) {
if ( V_16 [ 1 ] == '-' ) {
V_16 += 2 ;
memmove ( V_15 , V_16 , V_14 - V_16 ) ;
goto V_20;
}
V_16 ++ ;
}
* V_15 = '\0' ;
V_14 = V_15 ;
break;
} else {
V_15 ++ ;
}
}
V_15 = line ;
while ( V_15 < V_14 ) {
while ( V_15 < V_14 && isspace ( * V_15 ) )
* ( V_15 ++ ) = 0 ;
if ( V_15 >= V_14 )
break;
V_13 [ V_17 ] . line = V_18 ;
V_13 [ V_17 ] . V_10 = V_15 ;
if ( isalpha ( * V_15 ) ) {
const char * * V_5 ;
V_16 = V_15 + 1 ;
while ( V_16 < V_14 && ( isalnum ( * V_16 ) || * V_16 == '-' || * V_16 == '_' ) )
V_16 ++ ;
V_13 [ V_17 ] . V_9 = V_16 - V_15 ;
V_15 = V_16 ;
if ( islower ( V_13 [ V_17 ] . V_10 [ 0 ] ) ) {
V_13 [ V_17 ++ ] . V_21 = V_22 ;
continue;
}
V_5 = bsearch ( & V_13 [ V_17 ] , V_23 ,
sizeof( V_23 ) / sizeof( V_23 [ 1 ] ) ,
sizeof( V_23 [ 1 ] ) ,
F_1 ) ;
if ( V_5 ) {
V_13 [ V_17 ++ ] . V_21 = V_5 - V_23 ;
continue;
}
V_13 [ V_17 ++ ] . V_21 = V_24 ;
continue;
}
if ( isdigit ( * V_15 ) ) {
V_16 = V_15 + 1 ;
while ( V_16 < V_14 && ( isdigit ( * V_16 ) ) )
V_16 ++ ;
V_13 [ V_17 ] . V_9 = V_16 - V_15 ;
V_15 = V_16 ;
V_13 [ V_17 ++ ] . V_21 = V_25 ;
continue;
}
if ( V_14 - V_15 >= 3 ) {
if ( memcmp ( V_15 , L_1 , 3 ) == 0 ) {
V_15 += 3 ;
V_13 [ V_17 ] . V_9 = 3 ;
V_13 [ V_17 ++ ] . V_21 = V_26 ;
continue;
}
}
if ( V_14 - V_15 >= 2 ) {
if ( memcmp ( V_15 , L_2 , 2 ) == 0 ) {
V_15 += 2 ;
V_13 [ V_17 ] . V_9 = 2 ;
V_13 [ V_17 ++ ] . V_21 = V_27 ;
continue;
}
if ( memcmp ( V_15 , L_3 , 2 ) == 0 ) {
V_15 += 2 ;
V_13 [ V_17 ] . V_9 = 2 ;
V_13 [ V_17 ++ ] . V_21 = V_28 ;
continue;
}
}
if ( V_14 - V_15 >= 1 ) {
V_13 [ V_17 ] . V_9 = 1 ;
switch ( * V_15 ) {
case '{' :
V_15 += 1 ;
V_13 [ V_17 ++ ] . V_21 = V_29 ;
continue;
case '}' :
V_15 += 1 ;
V_13 [ V_17 ++ ] . V_21 = V_30 ;
continue;
case '[' :
V_15 += 1 ;
V_13 [ V_17 ++ ] . V_21 = V_31 ;
continue;
case ']' :
V_15 += 1 ;
V_13 [ V_17 ++ ] . V_21 = V_32 ;
continue;
case ',' :
V_15 += 1 ;
V_13 [ V_17 ++ ] . V_21 = V_33 ;
continue;
default:
break;
}
}
fprintf ( V_34 , L_4 ,
V_35 , V_18 , * V_15 ) ;
exit ( 1 ) ;
}
}
V_36 = V_17 ;
F_3 ( L_5 , V_36 ) ;
#if 0
{
int n;
for (n = 0; n < nr_tokens; n++)
debug("Token %3u: '%*.*s'\n",
n,
(int)token_list[n].size, (int)token_list[n].size,
token_list[n].value);
}
#endif
}
int main ( int V_37 , char * * V_38 )
{
struct V_39 V_40 ;
T_2 V_41 ;
T_3 * V_42 , * V_43 ;
char * V_11 , * V_15 ;
char * V_44 ;
int V_45 ;
if ( V_37 != 4 ) {
fprintf ( V_34 , L_6 ,
V_38 [ 0 ] ) ;
exit ( 2 ) ;
}
V_44 = getenv ( L_7 ) ;
if ( V_44 )
V_46 = atoi ( V_44 ) ;
V_35 = V_38 [ 1 ] ;
V_47 = V_38 [ 2 ] ;
V_48 = V_38 [ 3 ] ;
V_45 = F_4 ( V_35 , V_49 ) ;
if ( V_45 < 0 ) {
perror ( V_35 ) ;
exit ( 1 ) ;
}
if ( F_5 ( V_45 , & V_40 ) < 0 ) {
perror ( V_35 ) ;
exit ( 1 ) ;
}
if ( ! ( V_11 = malloc ( V_40 . V_50 + 1 ) ) ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
if ( ( V_41 = F_6 ( V_45 , V_11 , V_40 . V_50 ) ) < 0 ) {
perror ( V_35 ) ;
exit ( 1 ) ;
}
if ( F_7 ( V_45 ) < 0 ) {
perror ( V_35 ) ;
exit ( 1 ) ;
}
if ( V_41 != V_40 . V_50 ) {
fprintf ( V_34 , L_8 , V_35 ) ;
exit ( 1 ) ;
}
V_15 = strrchr ( V_38 [ 1 ] , '/' ) ;
V_15 = V_15 ? V_15 + 1 : V_38 [ 1 ] ;
V_51 = F_8 ( V_15 ) ;
if ( ! V_15 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_15 = strchr ( V_51 , '.' ) ;
if ( V_15 )
* V_15 = '\0' ;
V_11 [ V_41 ] = 0 ;
F_2 ( V_11 , V_11 + V_41 ) ;
F_9 () ;
F_10 () ;
V_42 = fopen ( V_47 , L_9 ) ;
if ( ! V_42 ) {
perror ( V_47 ) ;
exit ( 1 ) ;
}
V_43 = fopen ( V_48 , L_9 ) ;
if ( ! V_42 ) {
perror ( V_48 ) ;
exit ( 1 ) ;
}
F_11 ( V_42 , V_43 ) ;
if ( fclose ( V_42 ) < 0 ) {
perror ( V_47 ) ;
exit ( 1 ) ;
}
if ( fclose ( V_43 ) < 0 ) {
perror ( V_48 ) ;
exit ( 1 ) ;
}
return 0 ;
}
static int F_12 ( const void * V_52 , const void * V_53 )
{
const struct type * const * V_54 = V_52 , * const * V_55 = V_53 ;
if ( ( * V_54 ) -> V_56 -> V_9 != ( * V_55 ) -> V_56 -> V_9 )
return ( * V_54 ) -> V_56 -> V_9 - ( * V_55 ) -> V_56 -> V_9 ;
else
return memcmp ( ( * V_54 ) -> V_56 -> V_10 , ( * V_55 ) -> V_56 -> V_10 ,
( * V_54 ) -> V_56 -> V_9 ) ;
}
static int F_13 ( const void * V_1 , const void * V_57 )
{
const struct V_3 * V_3 = V_1 ;
const struct type * const * V_58 = V_57 ;
const struct type * type = * V_58 ;
if ( V_3 -> V_9 != type -> V_56 -> V_9 )
return V_3 -> V_9 - type -> V_56 -> V_9 ;
else
return memcmp ( V_3 -> V_10 , type -> V_56 -> V_10 ,
V_3 -> V_9 ) ;
}
static void F_9 ( void )
{
struct type * V_59 ;
unsigned V_60 , V_61 , V_62 ;
V_60 = 0 ;
for ( V_62 = 0 ; V_62 < V_36 - 1 ; V_62 ++ )
if ( V_19 [ V_62 + 0 ] . V_21 == V_24 &&
V_19 [ V_62 + 1 ] . V_21 == V_26 )
V_60 ++ ;
if ( V_60 == 0 ) {
fprintf ( V_34 , L_10 , V_35 ) ;
exit ( 1 ) ;
}
V_63 = V_60 ;
V_59 = V_64 = calloc ( V_60 + 1 , sizeof( V_64 [ 0 ] ) ) ;
if ( ! V_64 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_65 = calloc ( V_60 , sizeof( V_65 [ 0 ] ) ) ;
if ( ! V_65 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_61 = 0 ;
V_59 [ V_61 ] . V_66 |= V_67 ;
for ( V_62 = 0 ; V_62 < V_36 - 1 ; V_62 ++ ) {
if ( V_19 [ V_62 + 0 ] . V_21 == V_24 &&
V_19 [ V_62 + 1 ] . V_21 == V_26 ) {
V_59 [ V_61 ] . V_56 = & V_19 [ V_62 ] ;
V_65 [ V_61 ] = & V_59 [ V_61 ] ;
V_61 ++ ;
}
}
V_59 [ V_61 ] . V_56 = & V_19 [ V_62 + 1 ] ;
V_59 [ V_61 ] . V_66 |= V_68 ;
qsort ( V_65 , V_60 , sizeof( V_65 [ 0 ] ) , F_12 ) ;
F_3 ( L_11 , V_63 ) ;
#if 0
for (n = 0; n < nr_types; n++) {
struct type *type = type_index[n];
debug("- %*.*s\n",
(int)type->name->size,
(int)type->name->size,
type->name->value);
}
#endif
}
static void F_10 ( void )
{
struct V_3 * V_69 ;
struct type * type ;
type = V_64 ;
do {
V_69 = type -> V_56 ;
if ( V_69 [ 0 ] . V_21 != V_24 ||
V_69 [ 1 ] . V_21 != V_26 )
abort () ;
V_69 += 2 ;
type -> V_70 = F_14 ( & V_69 , type [ 1 ] . V_56 , NULL ) ;
type -> V_70 -> V_71 = type ;
if ( V_69 != type [ 1 ] . V_56 ) {
fprintf ( V_34 , L_12 ,
V_35 , V_69 -> line ,
( int ) V_69 -> V_9 , ( int ) V_69 -> V_9 , V_69 -> V_10 ) ;
exit ( 1 ) ;
}
} while ( type ++ , ! ( type -> V_66 & V_68 ) );
F_3 ( L_13 , V_72 ) ;
}
static struct V_70 * F_15 ( struct V_3 * type )
{
struct V_70 * V_73 = calloc ( 1 , sizeof( * V_73 ) ) ;
if ( ! V_73 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_73 -> V_74 = V_75 ;
V_75 = V_73 ;
return V_73 ;
}
static struct V_70 * F_14 ( struct V_3 * * V_76 , struct V_3 * V_12 ,
struct V_3 * V_56 )
{
struct V_70 * V_77 , * V_70 ;
struct V_78 * V_78 , * * V_79 ;
struct V_3 * V_69 = * V_76 ;
struct type * * V_80 ;
char * V_15 ;
int V_81 = 0 , V_82 = 0 ;
V_77 = V_70 = F_15 ( V_69 ) ;
V_70 -> V_83 = V_84 ;
V_70 -> V_85 = V_86 ;
V_70 -> V_87 = V_88 [ V_69 -> V_21 ] ;
V_70 -> V_56 = V_56 ;
if ( V_69 -> V_21 == V_31 ) {
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_89;
switch ( V_69 -> V_21 ) {
case V_90 :
V_70 -> V_83 = V_84 ;
V_69 ++ ;
break;
case V_91 :
V_70 -> V_83 = V_92 ;
V_69 ++ ;
break;
case V_25 :
V_70 -> V_83 = V_93 ;
break;
case V_94 :
V_70 -> V_83 = V_95 ;
V_69 ++ ;
break;
default:
fprintf ( V_34 , L_14 ,
V_35 , V_69 -> line ,
( int ) V_69 -> V_9 , ( int ) V_69 -> V_9 , V_69 -> V_10 ) ;
exit ( 1 ) ;
}
if ( V_69 >= V_12 )
goto V_89;
if ( V_69 -> V_21 != V_25 ) {
fprintf ( V_34 , L_15 ,
V_35 , V_69 -> line ,
( int ) V_69 -> V_9 , ( int ) V_69 -> V_9 , V_69 -> V_10 ) ;
exit ( 1 ) ;
}
V_70 -> V_87 &= ~ 0x1f ;
V_70 -> V_87 |= strtoul ( V_69 -> V_10 , & V_15 , 10 ) ;
if ( V_15 - V_69 -> V_10 != V_69 -> V_9 )
abort () ;
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_89;
if ( V_69 -> V_21 != V_32 ) {
fprintf ( V_34 , L_16 ,
V_35 , V_69 -> line ,
( int ) V_69 -> V_9 , ( int ) V_69 -> V_9 , V_69 -> V_10 ) ;
exit ( 1 ) ;
}
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_89;
V_81 = 1 ;
}
if ( V_69 -> V_21 == V_96 ) {
V_70 -> V_66 |= V_97 ;
V_82 = 1 ;
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_89;
} else if ( V_69 -> V_21 == V_98 ) {
V_70 -> V_66 |= V_99 ;
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_89;
}
if ( V_81 ) {
if ( ! V_82 )
V_70 -> V_85 |= V_100 ;
V_70 -> V_101 = V_82 ? V_102 : V_103 ;
V_70 -> V_104 = F_15 ( V_69 ) ;
V_70 = V_70 -> V_104 ;
V_70 -> V_83 = V_84 ;
V_70 -> V_85 = V_86 ;
V_70 -> V_87 = V_88 [ V_69 -> V_21 ] ;
V_70 -> V_56 = V_56 ;
}
V_70 -> type = V_69 ;
switch ( V_69 -> V_21 ) {
case V_105 :
V_70 -> V_101 = V_106 ;
V_69 ++ ;
break;
case V_107 :
case V_108 :
case V_109 :
case V_110 :
V_70 -> V_101 = V_111 ;
V_69 ++ ;
break;
case V_112 :
V_70 -> V_85 = V_100 ;
case V_113 :
case V_114 :
case V_115 :
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
V_70 -> V_101 = V_111 ;
V_69 ++ ;
break;
case V_129 :
case V_130 :
V_70 -> V_101 = V_111 ;
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_89;
if ( V_69 -> V_21 != V_131 )
goto V_132;
V_69 ++ ;
break;
case V_133 :
V_70 -> V_101 = V_111 ;
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_89;
if ( V_69 -> V_21 != V_134 )
goto V_132;
V_69 ++ ;
break;
case V_24 :
V_70 -> V_101 = V_135 ;
V_80 = bsearch ( V_69 , V_65 , V_63 , sizeof( V_65 [ 0 ] ) ,
F_13 ) ;
if ( ! V_80 ) {
fprintf ( V_34 , L_17 ,
V_35 , V_69 -> line ,
( int ) V_69 -> V_9 , ( int ) V_69 -> V_9 , V_69 -> V_10 ) ;
exit ( 1 ) ;
}
V_69 -> type = * V_80 ;
( * V_80 ) -> V_136 ++ ;
V_69 ++ ;
break;
case V_137 :
V_70 -> V_101 = V_138 ;
V_69 ++ ;
V_70 -> V_104 = F_16 ( & V_69 , V_12 , 1 ) ;
break;
case V_139 :
V_70 -> V_101 = V_103 ;
V_70 -> V_85 = V_100 ;
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_89;
if ( V_69 -> V_21 == V_140 ) {
V_70 -> V_101 = V_141 ;
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_89;
V_70 -> V_104 = F_14 ( & V_69 , V_12 , NULL ) ;
} else {
V_70 -> V_104 = F_16 ( & V_69 , V_12 , 0 ) ;
}
break;
case V_142 :
V_70 -> V_101 = V_143 ;
V_70 -> V_85 = V_100 ;
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_89;
if ( V_69 -> V_21 == V_140 ) {
V_70 -> V_101 = V_144 ;
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_132;
V_70 -> V_104 = F_14 ( & V_69 , V_12 , NULL ) ;
} else {
V_70 -> V_104 = F_16 ( & V_69 , V_12 , 1 ) ;
}
break;
default:
fprintf ( V_34 , L_18 ,
V_35 , V_69 -> line ,
( int ) V_69 -> V_9 , ( int ) V_69 -> V_9 , V_69 -> V_10 ) ;
exit ( 1 ) ;
}
if ( V_69 < V_12 && ( V_69 -> V_21 == V_145 ||
V_69 -> V_21 == V_146 )
) {
V_69 ++ ;
V_77 -> V_66 |= V_147 ;
}
if ( V_69 < V_12 && V_69 -> V_21 == V_27 ) {
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_89;
if ( V_69 -> V_21 != V_22 ) {
fprintf ( V_34 , L_19 ,
V_35 , V_69 -> line ,
( int ) V_69 -> V_9 , ( int ) V_69 -> V_9 , V_69 -> V_10 ) ;
exit ( 1 ) ;
}
V_78 = malloc ( sizeof( struct V_78 ) + V_69 -> V_9 + 1 ) ;
if ( ! V_78 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_78 -> V_148 = 0 ;
memcpy ( V_78 -> V_56 , V_69 -> V_10 , V_69 -> V_9 ) ;
V_78 -> V_56 [ V_69 -> V_9 ] = 0 ;
for ( V_79 = & V_149 ;
* V_79 ;
V_79 = & ( * V_79 ) -> V_150
) {
int V_151 = strcmp ( V_78 -> V_56 , ( * V_79 ) -> V_56 ) ;
if ( V_151 == 0 ) {
free ( V_78 ) ;
V_78 = * V_79 ;
goto V_152;
}
if ( V_151 < 0 ) {
V_78 -> V_150 = * V_79 ;
* V_79 = V_78 ;
V_72 ++ ;
goto V_152;
}
}
V_78 -> V_150 = NULL ;
* V_79 = V_78 ;
V_72 ++ ;
V_152:
V_70 -> V_78 = V_78 ;
V_69 -> V_78 = V_78 ;
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_89;
if ( V_69 -> V_21 != V_28 ) {
fprintf ( V_34 , L_20 ,
V_35 , V_69 -> line ,
( int ) V_69 -> V_9 , ( int ) V_69 -> V_9 , V_69 -> V_10 ) ;
exit ( 1 ) ;
}
V_69 ++ ;
}
* V_76 = V_69 ;
return V_77 ;
V_132:
fprintf ( V_34 , L_21 ,
V_35 , V_69 -> line ,
( int ) V_69 -> V_9 , ( int ) V_69 -> V_9 , V_69 -> V_10 ) ;
exit ( 1 ) ;
V_89:
fprintf ( V_34 , L_22 , V_35 ) ;
exit ( 1 ) ;
}
static struct V_70 * F_16 ( struct V_3 * * V_76 , struct V_3 * V_12 ,
int V_153 )
{
struct V_70 * V_104 , * * V_154 = & V_104 , * V_70 ;
struct V_3 * V_69 = * V_76 , * V_56 ;
if ( V_69 -> V_21 != V_29 ) {
fprintf ( V_34 , L_23 ,
V_35 , V_69 -> line ,
( int ) V_69 -> V_9 , ( int ) V_69 -> V_9 , V_69 -> V_10 ) ;
exit ( 1 ) ;
}
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_89;
if ( V_69 -> V_21 == V_29 ) {
fprintf ( V_34 , L_24 ,
V_35 , V_69 -> line ) ;
exit ( 1 ) ;
}
for (; ; ) {
V_56 = NULL ;
if ( V_69 -> V_21 == V_22 ) {
V_56 = V_69 ;
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_89;
}
V_70 = F_14 ( & V_69 , V_12 , V_56 ) ;
if ( V_153 )
V_70 -> V_66 |= V_147 | V_155 ;
* V_154 = V_70 ;
V_154 = & V_70 -> V_150 ;
if ( V_69 >= V_12 )
goto V_89;
if ( V_69 -> V_21 != V_33 )
break;
V_69 ++ ;
if ( V_69 >= V_12 )
goto V_89;
}
V_104 -> V_66 &= ~ V_155 ;
if ( V_69 -> V_21 != V_30 ) {
fprintf ( V_34 , L_25 ,
V_35 , V_69 -> line ,
( int ) V_69 -> V_9 , ( int ) V_69 -> V_9 , V_69 -> V_10 ) ;
exit ( 1 ) ;
}
V_69 ++ ;
* V_76 = V_69 ;
return V_104 ;
V_89:
fprintf ( V_34 , L_22 , V_35 ) ;
exit ( 1 ) ;
}
static void F_17 ( T_3 * V_42 , const char * V_156 , ... )
{
T_4 V_157 ;
if ( V_42 ) {
fprintf ( V_42 , L_26 , V_158 , V_159 , L_27 ) ;
va_start ( V_157 , V_156 ) ;
vfprintf ( V_42 , V_156 , V_157 ) ;
va_end ( V_157 ) ;
}
V_158 ++ ;
}
static void F_18 ( T_3 * V_42 , const char * V_156 , ... )
{
T_4 V_157 ;
if ( V_42 ) {
va_start ( V_157 , V_156 ) ;
vfprintf ( V_42 , V_156 , V_157 ) ;
va_end ( V_157 ) ;
}
}
static void F_11 ( T_3 * V_42 , T_3 * V_43 )
{
struct V_70 * V_73 ;
struct V_78 * V_78 ;
struct type * V_160 ;
int V_148 ;
fprintf ( V_43 , L_28 ) ;
fprintf ( V_43 , L_29 ) ;
fprintf ( V_43 , L_30 ) ;
fprintf ( V_43 , L_31 , V_51 ) ;
fprintf ( V_43 , L_32 ) ;
fprintf ( V_43 , L_33 ) ;
fprintf ( V_43 , L_34 ) ;
fprintf ( V_43 , L_35 , V_51 ) ;
if ( ferror ( V_43 ) ) {
perror ( V_48 ) ;
exit ( 1 ) ;
}
fprintf ( V_42 , L_28 ) ;
fprintf ( V_42 , L_29 ) ;
fprintf ( V_42 , L_30 ) ;
fprintf ( V_42 , L_31 , V_51 ) ;
fprintf ( V_42 , L_32 ) ;
fprintf ( V_42 , L_36 ) ;
fprintf ( V_42 , L_37 , V_51 ) ;
fprintf ( V_42 , L_34 ) ;
if ( ferror ( V_42 ) ) {
perror ( V_47 ) ;
exit ( 1 ) ;
}
fprintf ( V_43 , L_34 ) ;
V_148 = 0 ;
for ( V_78 = V_149 ; V_78 ; V_78 = V_78 -> V_150 ) {
V_78 -> V_148 = V_148 ++ ;
fprintf ( V_43 ,
L_38
L_39 ,
V_78 -> V_56 ) ;
}
fprintf ( V_43 , L_34 ) ;
fprintf ( V_42 , L_40 , V_51 ) ;
for ( V_78 = V_149 ; V_78 ; V_78 = V_78 -> V_150 )
fprintf ( V_42 , L_41 ,
V_78 -> V_56 , V_78 -> V_148 ) ;
fprintf ( V_42 , L_42 , V_51 , V_72 ) ;
fprintf ( V_42 , L_43 ) ;
fprintf ( V_42 , L_34 ) ;
fprintf ( V_42 , L_44 ,
V_51 , V_51 ) ;
for ( V_78 = V_149 ; V_78 ; V_78 = V_78 -> V_150 )
fprintf ( V_42 , L_45 , V_78 -> V_148 , V_78 -> V_56 ) ;
fprintf ( V_42 , L_43 ) ;
if ( ferror ( V_42 ) ) {
perror ( V_47 ) ;
exit ( 1 ) ;
}
F_3 ( L_46 ) ;
V_158 = 0 ;
V_160 = & V_64 [ 0 ] ;
F_19 ( NULL , V_160 -> V_70 , NULL ) ;
F_17 ( NULL , L_47 ) ;
F_20 ( NULL ) ;
for ( V_73 = V_75 ; V_73 ; V_73 = V_73 -> V_74 )
V_73 -> V_66 &= ~ V_161 ;
F_3 ( L_48 ) ;
fprintf ( V_42 , L_34 ) ;
fprintf ( V_42 , L_49 ,
V_51 ) ;
V_158 = 0 ;
V_160 = & V_64 [ 0 ] ;
F_19 ( V_42 , V_160 -> V_70 , NULL ) ;
F_17 ( V_42 , L_47 ) ;
F_20 ( V_42 ) ;
fprintf ( V_42 , L_43 ) ;
fprintf ( V_42 , L_34 ) ;
fprintf ( V_42 , L_50 , V_51 ) ;
fprintf ( V_42 , L_51 , V_51 ) ;
fprintf ( V_42 , L_52 , V_51 ) ;
fprintf ( V_42 , L_53 , V_51 ) ;
fprintf ( V_42 , L_43 ) ;
}
static void F_20 ( T_3 * V_42 )
{
struct V_70 * V_73 , * V_162 ;
const char * V_163 ;
int V_164 ;
while ( ( V_73 = V_165 ) ) {
V_165 = V_73 -> V_166 ;
if ( ! V_165 )
V_167 = & V_165 ;
F_18 ( V_42 , L_34 ) ;
V_73 -> V_168 = V_164 = V_158 ;
V_159 ++ ;
for ( V_162 = V_73 -> V_104 ; V_162 ; V_162 = V_162 -> V_150 )
F_19 ( V_42 , V_162 , NULL ) ;
V_159 -- ;
V_163 = V_73 -> V_78 ? L_54 : L_27 ;
switch ( V_73 -> V_101 ) {
case V_103 :
F_17 ( V_42 , L_55 , V_163 ) ;
break;
case V_141 :
F_17 ( V_42 , L_56 , V_163 ) ;
F_17 ( V_42 , L_57 , V_164 ) ;
break;
case V_143 :
F_17 ( V_42 , L_58 , V_163 ) ;
break;
case V_144 :
F_17 ( V_42 , L_59 , V_163 ) ;
F_17 ( V_42 , L_57 , V_164 ) ;
break;
default:
break;
}
if ( V_73 -> V_78 )
F_17 ( V_42 , L_60 ,
V_73 -> V_78 -> V_56 ) ;
F_17 ( V_42 , L_61 ) ;
}
}
static void F_19 ( T_3 * V_42 , struct V_70 * V_73 , struct V_70 * V_87 )
{
struct V_70 * V_169 ;
const char * V_170 , * V_163 ;
int V_164 , V_171 = 0 , V_172 = 0 ;
if ( V_73 -> V_66 & V_147 ||
( V_87 && V_87 -> V_66 & V_147 ) )
V_171 = 1 ;
if ( ( V_73 -> V_71 && V_73 -> V_71 -> V_136 > 1 ) ||
V_171 )
V_172 = 1 ;
if ( V_73 -> V_71 && V_42 ) {
F_18 ( V_42 , L_62 ,
( int ) V_73 -> V_71 -> V_56 -> V_9 , ( int ) V_73 -> V_71 -> V_56 -> V_9 ,
V_73 -> V_71 -> V_56 -> V_10 ) ;
}
V_170 = ( V_73 -> V_66 & V_155 ||
( V_87 && V_87 -> V_66 & V_155 ) ) ? L_63 : L_27 ;
V_163 = V_73 -> V_78 ? L_54 : L_27 ;
switch ( V_73 -> V_101 ) {
case V_106 :
F_17 ( V_42 , L_64 , V_170 , V_163 ) ;
if ( V_73 -> V_56 )
F_18 ( V_42 , L_65 ,
( int ) V_73 -> V_56 -> V_9 , ( int ) V_73 -> V_56 -> V_9 ,
V_73 -> V_56 -> V_10 ) ;
F_18 ( V_42 , L_34 ) ;
goto V_173;
case V_102 :
F_19 ( V_42 , V_73 -> V_104 , V_73 ) ;
return;
case V_103 :
case V_141 :
case V_143 :
case V_144 :
F_17 ( V_42 , L_66 ,
V_170 ,
V_172 ? L_67 : L_27 ,
V_171 ? L_68 : L_27 ) ;
break;
case V_138 :
goto V_173;
case V_135 :
if ( V_73 -> V_83 == V_84 && V_73 -> V_85 == V_86 && V_73 -> V_87 == 0 )
goto V_173;
default:
F_17 ( V_42 , L_66 ,
V_170 , V_163 ,
V_171 ? L_68 : L_27 ) ;
break;
}
if ( V_73 -> V_56 )
F_18 ( V_42 , L_65 ,
( int ) V_73 -> V_56 -> V_9 , ( int ) V_73 -> V_56 -> V_9 ,
V_73 -> V_56 -> V_10 ) ;
F_18 ( V_42 , L_34 ) ;
if ( ! V_87 )
V_87 = V_73 ;
if ( V_87 -> V_83 == V_84 &&
V_87 -> V_87 != 14 &&
V_87 -> V_87 != 15 &&
V_87 -> V_87 != 31 )
F_17 ( V_42 , L_69 ,
V_174 [ V_87 -> V_83 ] ,
V_175 [ V_87 -> V_85 | V_73 -> V_85 ] ,
V_176 [ V_87 -> V_87 ] ) ;
else
F_17 ( V_42 , L_70 ,
V_174 [ V_87 -> V_83 ] ,
V_175 [ V_87 -> V_85 | V_73 -> V_85 ] ,
V_87 -> V_87 ) ;
V_87 = NULL ;
V_173:
switch ( V_73 -> V_101 ) {
case V_135 :
F_19 ( V_42 , V_73 -> type -> type -> V_70 , V_87 ) ;
if ( V_73 -> V_78 )
F_17 ( V_42 , L_71 ) ;
break;
case V_103 :
if ( V_172 ) {
F_17 ( V_42 , L_72 , V_73 -> V_168 ) ;
if ( V_73 -> V_71 && V_73 -> V_71 -> V_56 )
F_18 ( V_42 , L_73 ,
( int ) V_73 -> V_71 -> V_56 -> V_9 ,
( int ) V_73 -> V_71 -> V_56 -> V_9 ,
V_73 -> V_71 -> V_56 -> V_10 ) ;
F_18 ( V_42 , L_34 ) ;
if ( ! ( V_73 -> V_66 & V_161 ) ) {
V_73 -> V_66 |= V_161 ;
* V_167 = V_73 ;
V_167 = & V_73 -> V_166 ;
}
return;
} else {
V_159 ++ ;
for ( V_169 = V_73 -> V_104 ; V_169 ; V_169 = V_169 -> V_150 )
F_19 ( V_42 , V_169 , NULL ) ;
V_159 -- ;
F_17 ( V_42 , L_55 , V_163 ) ;
}
break;
case V_141 :
case V_144 :
if ( V_172 ) {
F_17 ( V_42 , L_72 , V_73 -> V_168 ) ;
if ( V_73 -> V_71 && V_73 -> V_71 -> V_56 )
F_18 ( V_42 , L_73 ,
( int ) V_73 -> V_71 -> V_56 -> V_9 ,
( int ) V_73 -> V_71 -> V_56 -> V_9 ,
V_73 -> V_71 -> V_56 -> V_10 ) ;
F_18 ( V_42 , L_34 ) ;
if ( ! ( V_73 -> V_66 & V_161 ) ) {
V_73 -> V_66 |= V_161 ;
* V_167 = V_73 ;
V_167 = & V_73 -> V_166 ;
}
return;
} else {
V_164 = V_158 ;
V_159 ++ ;
F_19 ( V_42 , V_73 -> V_104 , NULL ) ;
V_159 -- ;
if ( V_73 -> V_101 == V_141 )
F_17 ( V_42 , L_56 , V_163 ) ;
else
F_17 ( V_42 , L_59 , V_163 ) ;
F_17 ( V_42 , L_57 , V_164 ) ;
}
break;
case V_143 :
fprintf ( V_34 , L_74 ) ;
exit ( 1 ) ;
case V_138 :
for ( V_169 = V_73 -> V_104 ; V_169 ; V_169 = V_169 -> V_150 )
F_19 ( V_42 , V_169 , NULL ) ;
if ( ! V_171 )
F_17 ( V_42 , L_75 ) ;
if ( V_73 -> V_78 )
F_17 ( V_42 , L_71 ) ;
break;
default:
break;
}
if ( V_73 -> V_78 )
F_17 ( V_42 , L_60 , V_73 -> V_78 -> V_56 ) ;
}
