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
printf ( L_5 , V_36 ) ;
#if 0
{
int n;
for (n = 0; n < nr_tokens; n++)
printf("Token %3u: '%*.*s'\n",
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
int V_44 ;
if ( V_37 != 4 ) {
fprintf ( V_34 , L_6 ,
V_38 [ 0 ] ) ;
exit ( 2 ) ;
}
V_35 = V_38 [ 1 ] ;
V_45 = V_38 [ 2 ] ;
V_46 = V_38 [ 3 ] ;
V_44 = F_3 ( V_35 , V_47 ) ;
if ( V_44 < 0 ) {
perror ( V_35 ) ;
exit ( 1 ) ;
}
if ( F_4 ( V_44 , & V_40 ) < 0 ) {
perror ( V_35 ) ;
exit ( 1 ) ;
}
if ( ! ( V_11 = malloc ( V_40 . V_48 + 1 ) ) ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
if ( ( V_41 = F_5 ( V_44 , V_11 , V_40 . V_48 ) ) < 0 ) {
perror ( V_35 ) ;
exit ( 1 ) ;
}
if ( F_6 ( V_44 ) < 0 ) {
perror ( V_35 ) ;
exit ( 1 ) ;
}
if ( V_41 != V_40 . V_48 ) {
fprintf ( V_34 , L_7 , V_35 ) ;
exit ( 1 ) ;
}
V_15 = strrchr ( V_38 [ 1 ] , '/' ) ;
V_15 = V_15 ? V_15 + 1 : V_38 [ 1 ] ;
V_49 = F_7 ( V_15 ) ;
if ( ! V_15 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_15 = strchr ( V_49 , '.' ) ;
if ( V_15 )
* V_15 = '\0' ;
V_11 [ V_41 ] = 0 ;
F_2 ( V_11 , V_11 + V_41 ) ;
F_8 () ;
F_9 () ;
V_42 = fopen ( V_45 , L_8 ) ;
if ( ! V_42 ) {
perror ( V_45 ) ;
exit ( 1 ) ;
}
V_43 = fopen ( V_46 , L_8 ) ;
if ( ! V_42 ) {
perror ( V_46 ) ;
exit ( 1 ) ;
}
F_10 ( V_42 , V_43 ) ;
if ( fclose ( V_42 ) < 0 ) {
perror ( V_45 ) ;
exit ( 1 ) ;
}
if ( fclose ( V_43 ) < 0 ) {
perror ( V_46 ) ;
exit ( 1 ) ;
}
return 0 ;
}
static int F_11 ( const void * V_50 , const void * V_51 )
{
const struct type * const * V_52 = V_50 , * const * V_53 = V_51 ;
if ( ( * V_52 ) -> V_54 -> V_9 != ( * V_53 ) -> V_54 -> V_9 )
return ( * V_52 ) -> V_54 -> V_9 - ( * V_53 ) -> V_54 -> V_9 ;
else
return memcmp ( ( * V_52 ) -> V_54 -> V_10 , ( * V_53 ) -> V_54 -> V_10 ,
( * V_52 ) -> V_54 -> V_9 ) ;
}
static int F_12 ( const void * V_1 , const void * V_55 )
{
const struct V_3 * V_3 = V_1 ;
const struct type * const * V_56 = V_55 ;
const struct type * type = * V_56 ;
if ( V_3 -> V_9 != type -> V_54 -> V_9 )
return V_3 -> V_9 - type -> V_54 -> V_9 ;
else
return memcmp ( V_3 -> V_10 , type -> V_54 -> V_10 ,
V_3 -> V_9 ) ;
}
static void F_8 ( void )
{
struct type * V_57 ;
unsigned V_58 , V_59 , V_60 ;
V_58 = 0 ;
for ( V_60 = 0 ; V_60 < V_36 - 1 ; V_60 ++ )
if ( V_19 [ V_60 + 0 ] . V_21 == V_24 &&
V_19 [ V_60 + 1 ] . V_21 == V_26 )
V_58 ++ ;
if ( V_58 == 0 ) {
fprintf ( V_34 , L_9 , V_35 ) ;
exit ( 1 ) ;
}
V_61 = V_58 ;
V_57 = V_62 = calloc ( V_58 + 1 , sizeof( V_62 [ 0 ] ) ) ;
if ( ! V_62 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_63 = calloc ( V_58 , sizeof( V_63 [ 0 ] ) ) ;
if ( ! V_63 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_59 = 0 ;
V_57 [ V_59 ] . V_64 |= V_65 ;
for ( V_60 = 0 ; V_60 < V_36 - 1 ; V_60 ++ ) {
if ( V_19 [ V_60 + 0 ] . V_21 == V_24 &&
V_19 [ V_60 + 1 ] . V_21 == V_26 ) {
V_57 [ V_59 ] . V_54 = & V_19 [ V_60 ] ;
V_63 [ V_59 ] = & V_57 [ V_59 ] ;
V_59 ++ ;
}
}
V_57 [ V_59 ] . V_54 = & V_19 [ V_60 + 1 ] ;
V_57 [ V_59 ] . V_64 |= V_66 ;
qsort ( V_63 , V_58 , sizeof( V_63 [ 0 ] ) , F_11 ) ;
printf ( L_10 , V_61 ) ;
#if 0
for (n = 0; n < nr_types; n++) {
struct type *type = type_index[n];
printf("- %*.*s\n",
(int)type->name->size,
(int)type->name->size,
type->name->value);
}
#endif
}
static void F_9 ( void )
{
struct V_3 * V_67 ;
struct type * type ;
type = V_62 ;
do {
V_67 = type -> V_54 ;
if ( V_67 [ 0 ] . V_21 != V_24 ||
V_67 [ 1 ] . V_21 != V_26 )
abort () ;
V_67 += 2 ;
type -> V_68 = F_13 ( & V_67 , type [ 1 ] . V_54 , NULL ) ;
type -> V_68 -> V_69 = type ;
if ( V_67 != type [ 1 ] . V_54 ) {
fprintf ( V_34 , L_11 ,
V_35 , V_67 -> line ,
( int ) V_67 -> V_9 , ( int ) V_67 -> V_9 , V_67 -> V_10 ) ;
exit ( 1 ) ;
}
} while ( type ++ , ! ( type -> V_64 & V_66 ) );
printf ( L_12 , V_70 ) ;
}
static struct V_68 * F_14 ( struct V_3 * type )
{
struct V_68 * V_71 = calloc ( 1 , sizeof( * V_71 ) ) ;
if ( ! V_71 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_71 -> V_72 = V_73 ;
V_73 = V_71 ;
return V_71 ;
}
static struct V_68 * F_13 ( struct V_3 * * V_74 , struct V_3 * V_12 ,
struct V_3 * V_54 )
{
struct V_68 * V_75 , * V_68 ;
struct V_76 * V_76 , * * V_77 ;
struct V_3 * V_67 = * V_74 ;
struct type * * V_78 ;
char * V_15 ;
int V_79 = 0 , V_80 = 0 ;
V_75 = V_68 = F_14 ( V_67 ) ;
V_68 -> V_81 = V_82 ;
V_68 -> V_83 = V_84 ;
V_68 -> V_85 = V_86 [ V_67 -> V_21 ] ;
V_68 -> V_54 = V_54 ;
if ( V_67 -> V_21 == V_31 ) {
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_87;
switch ( V_67 -> V_21 ) {
case V_88 :
V_68 -> V_81 = V_82 ;
V_67 ++ ;
break;
case V_89 :
V_68 -> V_81 = V_90 ;
V_67 ++ ;
break;
case V_25 :
V_68 -> V_81 = V_91 ;
break;
case V_92 :
V_68 -> V_81 = V_93 ;
V_67 ++ ;
break;
default:
fprintf ( V_34 , L_13 ,
V_35 , V_67 -> line ,
( int ) V_67 -> V_9 , ( int ) V_67 -> V_9 , V_67 -> V_10 ) ;
exit ( 1 ) ;
}
if ( V_67 >= V_12 )
goto V_87;
if ( V_67 -> V_21 != V_25 ) {
fprintf ( V_34 , L_14 ,
V_35 , V_67 -> line ,
( int ) V_67 -> V_9 , ( int ) V_67 -> V_9 , V_67 -> V_10 ) ;
exit ( 1 ) ;
}
V_68 -> V_85 &= ~ 0x1f ;
V_68 -> V_85 |= strtoul ( V_67 -> V_10 , & V_15 , 10 ) ;
if ( V_15 - V_67 -> V_10 != V_67 -> V_9 )
abort () ;
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_87;
if ( V_67 -> V_21 != V_32 ) {
fprintf ( V_34 , L_15 ,
V_35 , V_67 -> line ,
( int ) V_67 -> V_9 , ( int ) V_67 -> V_9 , V_67 -> V_10 ) ;
exit ( 1 ) ;
}
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_87;
V_79 = 1 ;
}
if ( V_67 -> V_21 == V_94 ) {
V_68 -> V_64 |= V_95 ;
V_80 = 1 ;
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_87;
} else if ( V_67 -> V_21 == V_96 ) {
V_68 -> V_64 |= V_97 ;
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_87;
}
if ( V_79 ) {
if ( ! V_80 )
V_68 -> V_83 |= V_98 ;
V_68 -> V_99 = V_80 ? V_100 : V_101 ;
V_68 -> V_102 = F_14 ( V_67 ) ;
V_68 = V_68 -> V_102 ;
V_68 -> V_81 = V_82 ;
V_68 -> V_83 = V_84 ;
V_68 -> V_85 = V_86 [ V_67 -> V_21 ] ;
V_68 -> V_54 = V_54 ;
}
V_68 -> type = V_67 ;
switch ( V_67 -> V_21 ) {
case V_103 :
V_68 -> V_99 = V_104 ;
V_67 ++ ;
break;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
V_68 -> V_99 = V_109 ;
V_67 ++ ;
break;
case V_110 :
V_68 -> V_83 = V_98 ;
case V_111 :
case V_112 :
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
V_68 -> V_99 = V_109 ;
V_67 ++ ;
break;
case V_127 :
case V_128 :
V_68 -> V_99 = V_109 ;
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_87;
if ( V_67 -> V_21 != V_129 )
goto V_130;
V_67 ++ ;
break;
case V_131 :
V_68 -> V_99 = V_109 ;
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_87;
if ( V_67 -> V_21 != V_132 )
goto V_130;
V_67 ++ ;
break;
case V_24 :
V_68 -> V_99 = V_133 ;
V_78 = bsearch ( V_67 , V_63 , V_61 , sizeof( V_63 [ 0 ] ) ,
F_12 ) ;
if ( ! V_78 ) {
fprintf ( V_34 , L_16 ,
V_35 , V_67 -> line ,
( int ) V_67 -> V_9 , ( int ) V_67 -> V_9 , V_67 -> V_10 ) ;
exit ( 1 ) ;
}
V_67 -> type = * V_78 ;
( * V_78 ) -> V_134 ++ ;
V_67 ++ ;
break;
case V_135 :
V_68 -> V_99 = V_136 ;
V_67 ++ ;
V_68 -> V_102 = F_15 ( & V_67 , V_12 , 1 ) ;
break;
case V_137 :
V_68 -> V_99 = V_101 ;
V_68 -> V_83 = V_98 ;
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_87;
if ( V_67 -> V_21 == V_138 ) {
V_68 -> V_99 = V_139 ;
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_87;
V_68 -> V_102 = F_13 ( & V_67 , V_12 , NULL ) ;
} else {
V_68 -> V_102 = F_15 ( & V_67 , V_12 , 0 ) ;
}
break;
case V_140 :
V_68 -> V_99 = V_141 ;
V_68 -> V_83 = V_98 ;
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_87;
if ( V_67 -> V_21 == V_138 ) {
V_68 -> V_99 = V_142 ;
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_130;
V_68 -> V_102 = F_13 ( & V_67 , V_12 , NULL ) ;
} else {
V_68 -> V_102 = F_15 ( & V_67 , V_12 , 1 ) ;
}
break;
default:
fprintf ( V_34 , L_17 ,
V_35 , V_67 -> line ,
( int ) V_67 -> V_9 , ( int ) V_67 -> V_9 , V_67 -> V_10 ) ;
exit ( 1 ) ;
}
if ( V_67 < V_12 && ( V_67 -> V_21 == V_143 ||
V_67 -> V_21 == V_144 )
) {
V_67 ++ ;
V_75 -> V_64 |= V_145 ;
}
if ( V_67 < V_12 && V_67 -> V_21 == V_27 ) {
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_87;
if ( V_67 -> V_21 != V_22 ) {
fprintf ( V_34 , L_18 ,
V_35 , V_67 -> line ,
( int ) V_67 -> V_9 , ( int ) V_67 -> V_9 , V_67 -> V_10 ) ;
exit ( 1 ) ;
}
V_76 = malloc ( sizeof( struct V_76 ) + V_67 -> V_9 + 1 ) ;
if ( ! V_76 ) {
perror ( NULL ) ;
exit ( 1 ) ;
}
V_76 -> V_146 = 0 ;
memcpy ( V_76 -> V_54 , V_67 -> V_10 , V_67 -> V_9 ) ;
V_76 -> V_54 [ V_67 -> V_9 ] = 0 ;
for ( V_77 = & V_147 ;
* V_77 ;
V_77 = & ( * V_77 ) -> V_148
) {
int V_149 = strcmp ( V_76 -> V_54 , ( * V_77 ) -> V_54 ) ;
if ( V_149 == 0 ) {
free ( V_76 ) ;
V_76 = * V_77 ;
goto V_150;
}
if ( V_149 < 0 ) {
V_76 -> V_148 = * V_77 ;
* V_77 = V_76 ;
V_70 ++ ;
goto V_150;
}
}
V_76 -> V_148 = NULL ;
* V_77 = V_76 ;
V_70 ++ ;
V_150:
V_68 -> V_76 = V_76 ;
V_67 -> V_76 = V_76 ;
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_87;
if ( V_67 -> V_21 != V_28 ) {
fprintf ( V_34 , L_19 ,
V_35 , V_67 -> line ,
( int ) V_67 -> V_9 , ( int ) V_67 -> V_9 , V_67 -> V_10 ) ;
exit ( 1 ) ;
}
V_67 ++ ;
}
* V_74 = V_67 ;
return V_75 ;
V_130:
fprintf ( V_34 , L_20 ,
V_35 , V_67 -> line ,
( int ) V_67 -> V_9 , ( int ) V_67 -> V_9 , V_67 -> V_10 ) ;
exit ( 1 ) ;
V_87:
fprintf ( V_34 , L_21 , V_35 ) ;
exit ( 1 ) ;
}
static struct V_68 * F_15 ( struct V_3 * * V_74 , struct V_3 * V_12 ,
int V_151 )
{
struct V_68 * V_102 , * * V_152 = & V_102 , * V_68 ;
struct V_3 * V_67 = * V_74 , * V_54 ;
if ( V_67 -> V_21 != V_29 ) {
fprintf ( V_34 , L_22 ,
V_35 , V_67 -> line ,
( int ) V_67 -> V_9 , ( int ) V_67 -> V_9 , V_67 -> V_10 ) ;
exit ( 1 ) ;
}
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_87;
if ( V_67 -> V_21 == V_29 ) {
fprintf ( V_34 , L_23 ,
V_35 , V_67 -> line ) ;
exit ( 1 ) ;
}
for (; ; ) {
V_54 = NULL ;
if ( V_67 -> V_21 == V_22 ) {
V_54 = V_67 ;
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_87;
}
V_68 = F_13 ( & V_67 , V_12 , V_54 ) ;
if ( V_151 )
V_68 -> V_64 |= V_145 | V_153 ;
* V_152 = V_68 ;
V_152 = & V_68 -> V_148 ;
if ( V_67 >= V_12 )
goto V_87;
if ( V_67 -> V_21 != V_33 )
break;
V_67 ++ ;
if ( V_67 >= V_12 )
goto V_87;
}
V_102 -> V_64 &= ~ V_153 ;
if ( V_67 -> V_21 != V_30 ) {
fprintf ( V_34 , L_24 ,
V_35 , V_67 -> line ,
( int ) V_67 -> V_9 , ( int ) V_67 -> V_9 , V_67 -> V_10 ) ;
exit ( 1 ) ;
}
V_67 ++ ;
* V_74 = V_67 ;
return V_102 ;
V_87:
fprintf ( V_34 , L_21 , V_35 ) ;
exit ( 1 ) ;
}
static void F_16 ( T_3 * V_42 , const char * V_154 , ... )
{
T_4 V_155 ;
if ( V_42 ) {
fprintf ( V_42 , L_25 , V_156 , V_157 , L_26 ) ;
va_start ( V_155 , V_154 ) ;
vfprintf ( V_42 , V_154 , V_155 ) ;
va_end ( V_155 ) ;
}
V_156 ++ ;
}
static void F_17 ( T_3 * V_42 , const char * V_154 , ... )
{
T_4 V_155 ;
if ( V_42 ) {
va_start ( V_155 , V_154 ) ;
vfprintf ( V_42 , V_154 , V_155 ) ;
va_end ( V_155 ) ;
}
}
static void F_10 ( T_3 * V_42 , T_3 * V_43 )
{
struct V_68 * V_71 ;
struct V_76 * V_76 ;
struct type * V_158 ;
int V_146 ;
fprintf ( V_43 , L_27 ) ;
fprintf ( V_43 , L_28 ) ;
fprintf ( V_43 , L_29 ) ;
fprintf ( V_43 , L_30 , V_49 ) ;
fprintf ( V_43 , L_31 ) ;
fprintf ( V_43 , L_32 ) ;
fprintf ( V_43 , L_33 ) ;
fprintf ( V_43 , L_34 , V_49 ) ;
if ( ferror ( V_43 ) ) {
perror ( V_46 ) ;
exit ( 1 ) ;
}
fprintf ( V_42 , L_27 ) ;
fprintf ( V_42 , L_28 ) ;
fprintf ( V_42 , L_29 ) ;
fprintf ( V_42 , L_30 , V_49 ) ;
fprintf ( V_42 , L_31 ) ;
fprintf ( V_42 , L_35 ) ;
fprintf ( V_42 , L_36 , V_49 ) ;
fprintf ( V_42 , L_33 ) ;
if ( ferror ( V_42 ) ) {
perror ( V_45 ) ;
exit ( 1 ) ;
}
fprintf ( V_43 , L_33 ) ;
V_146 = 0 ;
for ( V_76 = V_147 ; V_76 ; V_76 = V_76 -> V_148 ) {
V_76 -> V_146 = V_146 ++ ;
fprintf ( V_43 ,
L_37
L_38 ,
V_76 -> V_54 ) ;
}
fprintf ( V_43 , L_33 ) ;
fprintf ( V_42 , L_39 , V_49 ) ;
for ( V_76 = V_147 ; V_76 ; V_76 = V_76 -> V_148 )
fprintf ( V_42 , L_40 ,
V_76 -> V_54 , V_76 -> V_146 ) ;
fprintf ( V_42 , L_41 , V_49 , V_70 ) ;
fprintf ( V_42 , L_42 ) ;
fprintf ( V_42 , L_33 ) ;
fprintf ( V_42 , L_43 ,
V_49 , V_49 ) ;
for ( V_76 = V_147 ; V_76 ; V_76 = V_76 -> V_148 )
fprintf ( V_42 , L_44 , V_76 -> V_146 , V_76 -> V_54 ) ;
fprintf ( V_42 , L_42 ) ;
if ( ferror ( V_42 ) ) {
perror ( V_45 ) ;
exit ( 1 ) ;
}
printf ( L_45 ) ;
V_156 = 0 ;
V_158 = & V_62 [ 0 ] ;
F_18 ( NULL , V_158 -> V_68 , NULL ) ;
F_16 ( NULL , L_46 ) ;
F_19 ( NULL ) ;
for ( V_71 = V_73 ; V_71 ; V_71 = V_71 -> V_72 )
V_71 -> V_64 &= ~ V_159 ;
printf ( L_47 ) ;
fprintf ( V_42 , L_33 ) ;
fprintf ( V_42 , L_48 ,
V_49 ) ;
V_156 = 0 ;
V_158 = & V_62 [ 0 ] ;
F_18 ( V_42 , V_158 -> V_68 , NULL ) ;
F_16 ( V_42 , L_46 ) ;
F_19 ( V_42 ) ;
fprintf ( V_42 , L_42 ) ;
fprintf ( V_42 , L_33 ) ;
fprintf ( V_42 , L_49 , V_49 ) ;
fprintf ( V_42 , L_50 , V_49 ) ;
fprintf ( V_42 , L_51 , V_49 ) ;
fprintf ( V_42 , L_52 , V_49 ) ;
fprintf ( V_42 , L_42 ) ;
}
static void F_19 ( T_3 * V_42 )
{
struct V_68 * V_71 , * V_160 ;
const char * V_161 ;
int V_162 ;
while ( ( V_71 = V_163 ) ) {
V_163 = V_71 -> V_164 ;
if ( ! V_163 )
V_165 = & V_163 ;
F_17 ( V_42 , L_33 ) ;
V_71 -> V_166 = V_162 = V_156 ;
V_157 ++ ;
for ( V_160 = V_71 -> V_102 ; V_160 ; V_160 = V_160 -> V_148 )
F_18 ( V_42 , V_160 , NULL ) ;
V_157 -- ;
V_161 = V_71 -> V_76 ? L_53 : L_26 ;
switch ( V_71 -> V_99 ) {
case V_101 :
F_16 ( V_42 , L_54 , V_161 ) ;
break;
case V_139 :
F_16 ( V_42 , L_55 , V_161 ) ;
F_16 ( V_42 , L_56 , V_162 ) ;
break;
case V_141 :
F_16 ( V_42 , L_57 , V_161 ) ;
break;
case V_142 :
F_16 ( V_42 , L_58 , V_161 ) ;
F_16 ( V_42 , L_56 , V_162 ) ;
break;
}
if ( V_71 -> V_76 )
F_16 ( V_42 , L_59 ,
V_71 -> V_76 -> V_54 ) ;
F_16 ( V_42 , L_60 ) ;
}
}
static void F_18 ( T_3 * V_42 , struct V_68 * V_71 , struct V_68 * V_85 )
{
struct V_68 * V_167 ;
const char * V_168 , * V_161 ;
int V_162 , V_169 = 0 , V_170 = 0 ;
if ( V_71 -> V_64 & V_145 ||
( V_85 && V_85 -> V_64 & V_145 ) )
V_169 = 1 ;
if ( ( V_71 -> V_69 && V_71 -> V_69 -> V_134 > 1 ) ||
V_169 )
V_170 = 1 ;
if ( V_71 -> V_69 && V_42 ) {
F_17 ( V_42 , L_61 ,
( int ) V_71 -> V_69 -> V_54 -> V_9 , ( int ) V_71 -> V_69 -> V_54 -> V_9 ,
V_71 -> V_69 -> V_54 -> V_10 ) ;
}
V_168 = ( V_71 -> V_64 & V_153 ||
( V_85 && V_85 -> V_64 & V_153 ) ) ? L_62 : L_26 ;
V_161 = V_71 -> V_76 ? L_53 : L_26 ;
switch ( V_71 -> V_99 ) {
case V_104 :
F_16 ( V_42 , L_63 , V_168 , V_161 ) ;
if ( V_71 -> V_54 )
F_17 ( V_42 , L_64 ,
( int ) V_71 -> V_54 -> V_9 , ( int ) V_71 -> V_54 -> V_9 ,
V_71 -> V_54 -> V_10 ) ;
F_17 ( V_42 , L_33 ) ;
goto V_171;
case V_100 :
F_18 ( V_42 , V_71 -> V_102 , V_71 ) ;
return;
case V_101 :
case V_139 :
case V_141 :
case V_142 :
F_16 ( V_42 , L_65 ,
V_168 ,
V_170 ? L_66 : L_26 ,
V_169 ? L_67 : L_26 ) ;
break;
case V_136 :
goto V_171;
case V_133 :
if ( V_71 -> V_81 == V_82 && V_71 -> V_83 == V_84 && V_71 -> V_85 == 0 )
goto V_171;
default:
F_16 ( V_42 , L_65 ,
V_168 , V_161 ,
V_169 ? L_67 : L_26 ) ;
break;
}
if ( V_71 -> V_54 )
F_17 ( V_42 , L_64 ,
( int ) V_71 -> V_54 -> V_9 , ( int ) V_71 -> V_54 -> V_9 ,
V_71 -> V_54 -> V_10 ) ;
F_17 ( V_42 , L_33 ) ;
if ( ! V_85 )
V_85 = V_71 ;
if ( V_85 -> V_81 == V_82 &&
V_85 -> V_85 != 14 &&
V_85 -> V_85 != 15 &&
V_85 -> V_85 != 31 )
F_16 ( V_42 , L_68 ,
V_172 [ V_85 -> V_81 ] ,
V_173 [ V_85 -> V_83 | V_71 -> V_83 ] ,
V_174 [ V_85 -> V_85 ] ) ;
else
F_16 ( V_42 , L_69 ,
V_172 [ V_85 -> V_81 ] ,
V_173 [ V_85 -> V_83 | V_71 -> V_83 ] ,
V_85 -> V_85 ) ;
V_85 = NULL ;
V_171:
switch ( V_71 -> V_99 ) {
case V_133 :
F_18 ( V_42 , V_71 -> type -> type -> V_68 , V_85 ) ;
if ( V_71 -> V_76 )
F_16 ( V_42 , L_70 ) ;
break;
case V_101 :
if ( V_170 ) {
F_16 ( V_42 , L_71 , V_71 -> V_166 ) ;
if ( V_71 -> V_69 && V_71 -> V_69 -> V_54 )
F_17 ( V_42 , L_72 ,
( int ) V_71 -> V_69 -> V_54 -> V_9 ,
( int ) V_71 -> V_69 -> V_54 -> V_9 ,
V_71 -> V_69 -> V_54 -> V_10 ) ;
F_17 ( V_42 , L_33 ) ;
if ( ! ( V_71 -> V_64 & V_159 ) ) {
V_71 -> V_64 |= V_159 ;
* V_165 = V_71 ;
V_165 = & V_71 -> V_164 ;
}
return;
} else {
V_157 ++ ;
for ( V_167 = V_71 -> V_102 ; V_167 ; V_167 = V_167 -> V_148 )
F_18 ( V_42 , V_167 , NULL ) ;
V_157 -- ;
F_16 ( V_42 , L_54 , V_161 ) ;
}
break;
case V_139 :
case V_142 :
if ( V_170 ) {
F_16 ( V_42 , L_71 , V_71 -> V_166 ) ;
if ( V_71 -> V_69 && V_71 -> V_69 -> V_54 )
F_17 ( V_42 , L_72 ,
( int ) V_71 -> V_69 -> V_54 -> V_9 ,
( int ) V_71 -> V_69 -> V_54 -> V_9 ,
V_71 -> V_69 -> V_54 -> V_10 ) ;
F_17 ( V_42 , L_33 ) ;
if ( ! ( V_71 -> V_64 & V_159 ) ) {
V_71 -> V_64 |= V_159 ;
* V_165 = V_71 ;
V_165 = & V_71 -> V_164 ;
}
return;
} else {
V_162 = V_156 ;
V_157 ++ ;
F_18 ( V_42 , V_71 -> V_102 , NULL ) ;
V_157 -- ;
if ( V_71 -> V_99 == V_139 )
F_16 ( V_42 , L_55 , V_161 ) ;
else
F_16 ( V_42 , L_58 , V_161 ) ;
F_16 ( V_42 , L_56 , V_162 ) ;
}
break;
case V_141 :
fprintf ( V_34 , L_73 ) ;
exit ( 1 ) ;
case V_136 :
for ( V_167 = V_71 -> V_102 ; V_167 ; V_167 = V_167 -> V_148 )
F_18 ( V_42 , V_167 , NULL ) ;
if ( ! V_169 )
F_16 ( V_42 , L_74 ) ;
if ( V_71 -> V_76 )
F_16 ( V_42 , L_70 ) ;
break;
default:
break;
}
if ( V_71 -> V_76 )
F_16 ( V_42 , L_59 , V_71 -> V_76 -> V_54 ) ;
}
