static void F_1 ( char * V_1 , const char * V_2 , ... )
{
unsigned long long V_3 ;
const char * V_4 ;
T_1 V_5 ;
int V_6 ;
int V_7 ;
V_4 = F_2 () ;
V_3 = F_3 () ;
V_6 = V_4 ? strlen ( V_4 ) : 0 ;
if ( V_6 ) {
strcpy ( V_1 , V_4 ) ;
V_1 [ V_6 ] = '\n' ;
for ( V_7 = 1 ; V_7 < V_6 && V_7 < V_3 ; V_7 ++ )
V_1 [ V_6 + V_7 ] = ' ' ;
V_1 [ V_6 + V_7 ] = '^' ;
V_1 [ V_6 + V_7 + 1 ] = '\n' ;
V_6 += V_7 + 2 ;
}
va_start ( V_5 , V_2 ) ;
vsnprintf ( V_1 + V_6 , V_8 - V_6 , V_2 , V_5 ) ;
va_end ( V_5 ) ;
}
static void F_4 ( char * V_9 )
{
F_5 ( V_9 ) ;
}
static enum V_10 F_6 ( char * * V_11 )
{
enum V_10 type ;
char * V_9 = NULL ;
do {
F_4 ( V_9 ) ;
type = F_7 ( & V_9 ) ;
} while ( type == V_12 || type == V_13 );
if ( V_9 &&
( strcmp ( V_9 , L_1 ) == 0 || strcmp ( V_9 , L_2 ) == 0 ) &&
F_8 () == '~' ) {
* V_11 = malloc ( 3 ) ;
if ( * V_11 == NULL ) {
F_4 ( V_9 ) ;
return V_14 ;
}
sprintf ( * V_11 , L_3 , * V_9 , '~' ) ;
F_4 ( V_9 ) ;
F_7 ( & V_9 ) ;
F_4 ( V_9 ) ;
} else
* V_11 = V_9 ;
return type ;
}
static int F_9 ( const void * V_15 , const void * V_16 )
{
const struct V_17 * V_18 = V_15 ;
const struct V_17 * V_19 = V_16 ;
if ( V_18 -> V_20 < V_19 -> V_20 )
return - 1 ;
if ( V_18 -> V_20 > V_19 -> V_20 )
return 1 ;
return 0 ;
}
static struct V_17 *
F_10 ( struct V_21 * V_22 , int V_23 )
{
struct V_17 * V_17 ;
struct V_17 V_24 ;
V_24 . V_20 = V_23 ;
V_17 = bsearch ( & V_24 , V_22 -> V_25 ,
V_22 -> V_26 ,
sizeof( * V_22 -> V_25 ) ,
F_9 ) ;
return V_17 ;
}
static struct V_17 *
F_11 ( struct V_21 * V_22 , int V_23 )
{
struct V_17 * V_17 ;
int V_7 ;
V_17 = F_10 ( V_22 , V_23 ) ;
if ( V_17 )
return V_17 ;
V_17 = realloc ( V_22 -> V_25 ,
sizeof( * V_22 -> V_25 ) *
( V_22 -> V_26 + 1 ) ) ;
if ( ! V_17 )
return NULL ;
V_22 -> V_25 = V_17 ;
for ( V_7 = 0 ; V_7 < V_22 -> V_26 ; V_7 ++ ) {
if ( V_22 -> V_25 [ V_7 ] . V_20 > V_23 )
break;
}
if ( V_7 < V_22 -> V_26 )
memmove ( & V_22 -> V_25 [ V_7 + 1 ] ,
& V_22 -> V_25 [ V_7 ] ,
sizeof( * V_22 -> V_25 ) *
( V_22 -> V_26 - V_7 ) ) ;
V_17 = & V_22 -> V_25 [ V_7 ] ;
V_17 -> V_20 = V_23 ;
V_17 -> V_27 = F_12 ( V_22 -> V_28 , V_23 ) ;
V_17 -> V_22 = NULL ;
V_22 -> V_26 ++ ;
return V_17 ;
}
struct V_21 * F_13 ( struct V_28 * V_28 )
{
struct V_21 * V_22 ;
V_22 = malloc ( sizeof( * V_22 ) ) ;
if ( V_22 == NULL )
return NULL ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_28 = V_28 ;
F_14 ( V_28 ) ;
return V_22 ;
}
static struct V_29 * F_15 ( void )
{
return calloc ( 1 , sizeof( struct V_29 ) ) ;
}
static void F_16 ( struct V_29 * V_30 )
{
if ( ! V_30 )
return;
switch ( V_30 -> type ) {
case V_31 :
case V_32 :
break;
case V_33 :
F_16 ( V_30 -> V_34 . V_35 ) ;
F_16 ( V_30 -> V_34 . V_36 ) ;
break;
case V_37 :
F_16 ( V_30 -> exp . V_35 ) ;
F_16 ( V_30 -> exp . V_36 ) ;
break;
case V_38 :
free ( V_30 -> V_39 . V_40 ) ;
regfree ( & V_30 -> V_39 . V_41 ) ;
free ( V_30 -> V_39 . V_42 ) ;
break;
case V_43 :
if ( V_30 -> V_44 . type == V_45 ||
V_30 -> V_44 . type == V_46 )
free ( V_30 -> V_44 . V_39 ) ;
break;
case V_47 :
F_16 ( V_30 -> V_48 . V_35 ) ;
F_16 ( V_30 -> V_48 . V_36 ) ;
default:
break;
}
free ( V_30 ) ;
}
static int F_17 ( struct V_49 * * V_50 ,
struct V_51 * V_27 )
{
struct V_49 * V_52 ;
V_52 = malloc ( sizeof( * V_52 ) ) ;
if ( V_52 == NULL )
return - 1 ;
V_52 -> V_53 = * V_50 ;
* V_50 = V_52 ;
V_52 -> V_27 = V_27 ;
return 0 ;
}
static int F_18 ( struct V_51 * V_27 ,
T_2 * V_54 , T_2 * V_55 )
{
if ( V_54 ) {
return ! regexec ( V_54 , V_27 -> system , 0 , NULL , 0 ) &&
! regexec ( V_55 , V_27 -> V_56 , 0 , NULL , 0 ) ;
}
return ! regexec ( V_55 , V_27 -> system , 0 , NULL , 0 ) ||
! regexec ( V_55 , V_27 -> V_56 , 0 , NULL , 0 ) ;
}
static enum V_57
F_19 ( struct V_28 * V_28 , struct V_49 * * V_50 ,
char * V_58 , char * V_59 )
{
struct V_51 * V_27 ;
T_2 V_55 ;
T_2 V_54 ;
int V_60 = 0 ;
int V_61 = 0 ;
char * V_41 ;
int V_62 ;
int V_7 ;
if ( ! V_59 ) {
V_59 = V_58 ;
V_58 = NULL ;
}
V_41 = malloc ( strlen ( V_59 ) + 3 ) ;
if ( V_41 == NULL )
return V_63 ;
sprintf ( V_41 , L_4 , V_59 ) ;
V_62 = regcomp ( & V_55 , V_41 , V_64 | V_65 ) ;
free ( V_41 ) ;
if ( V_62 )
return V_66 ;
if ( V_58 ) {
V_41 = malloc ( strlen ( V_58 ) + 3 ) ;
if ( V_41 == NULL ) {
regfree ( & V_55 ) ;
return V_63 ;
}
sprintf ( V_41 , L_4 , V_58 ) ;
V_62 = regcomp ( & V_54 , V_41 , V_64 | V_65 ) ;
free ( V_41 ) ;
if ( V_62 ) {
regfree ( & V_55 ) ;
return V_66 ;
}
}
for ( V_7 = 0 ; V_7 < V_28 -> V_67 ; V_7 ++ ) {
V_27 = V_28 -> V_50 [ V_7 ] ;
if ( F_18 ( V_27 , V_58 ? & V_54 : NULL , & V_55 ) ) {
V_60 = 1 ;
if ( F_17 ( V_50 , V_27 ) < 0 ) {
V_61 = 1 ;
break;
}
}
}
regfree ( & V_55 ) ;
if ( V_58 )
regfree ( & V_54 ) ;
if ( ! V_60 )
return V_68 ;
if ( V_61 )
return V_63 ;
return 0 ;
}
static void F_20 ( struct V_49 * V_50 )
{
struct V_49 * V_27 ;
while ( V_50 ) {
V_27 = V_50 ;
V_50 = V_50 -> V_53 ;
free ( V_27 ) ;
}
}
static enum V_57
F_21 ( struct V_51 * V_27 , const char * V_9 ,
enum V_10 type , struct V_29 * * V_69 , char * V_70 )
{
struct V_71 * V_72 ;
struct V_29 * V_30 ;
V_30 = F_15 () ;
if ( V_30 == NULL ) {
F_1 ( V_70 , L_5 ) ;
return V_63 ;
}
switch ( type ) {
case V_73 :
case V_74 :
V_30 -> type = V_43 ;
V_30 -> V_44 . type =
type == V_74 ? V_45 : V_46 ;
V_30 -> V_44 . V_39 = F_22 ( V_9 ) ;
if ( ! V_30 -> V_44 . V_39 ) {
F_16 ( V_30 ) ;
F_1 ( V_70 , L_6 ) ;
return V_63 ;
}
break;
case V_75 :
if ( isdigit ( V_9 [ 0 ] ) ) {
V_30 -> type = V_43 ;
V_30 -> V_44 . type = V_76 ;
V_30 -> V_44 . V_40 = F_23 ( V_9 , NULL , 0 ) ;
break;
}
V_72 = F_24 ( V_27 , V_9 ) ;
if ( ! V_72 ) {
if ( strcmp ( V_9 , V_77 ) == 0 ) {
V_72 = & V_78 ;
} else if ( strcmp ( V_9 , V_79 ) == 0 ) {
V_72 = & V_80 ;
} else {
V_30 -> type = V_32 ;
V_30 -> boolean . V_44 = V_81 ;
break;
}
}
V_30 -> type = V_82 ;
V_30 -> V_72 . V_72 = V_72 ;
break;
default:
F_16 ( V_30 ) ;
F_1 ( V_70 , L_7 , V_9 ) ;
return V_83 ;
}
* V_69 = V_30 ;
return 0 ;
}
static struct V_29 *
F_25 ( enum V_84 V_85 )
{
struct V_29 * V_30 ;
V_30 = F_15 () ;
if ( ! V_30 )
return NULL ;
V_30 -> type = V_47 ;
V_30 -> V_48 . type = V_85 ;
return V_30 ;
}
static struct V_29 *
F_26 ( enum V_86 V_87 )
{
struct V_29 * V_30 ;
V_30 = F_15 () ;
if ( ! V_30 )
return NULL ;
V_30 -> type = V_37 ;
V_30 -> V_48 . type = V_87 ;
return V_30 ;
}
static struct V_29 *
F_27 ( enum V_86 V_87 )
{
struct V_29 * V_30 ;
V_30 = F_15 () ;
if ( ! V_30 )
return NULL ;
V_30 -> type = V_33 ;
V_30 -> V_48 . type = V_87 ;
return V_30 ;
}
static enum V_57
F_28 ( struct V_29 * V_48 , struct V_29 * V_30 , char * V_70 )
{
struct V_29 * V_35 ;
char * V_39 ;
int V_88 ;
int V_62 ;
switch ( V_48 -> type ) {
case V_37 :
if ( V_48 -> exp . V_36 )
goto V_89;
V_48 -> exp . V_36 = V_30 ;
break;
case V_47 :
if ( V_48 -> V_48 . V_36 )
goto V_89;
V_48 -> V_48 . V_36 = V_30 ;
break;
case V_33 :
if ( V_48 -> V_48 . V_36 )
goto V_89;
switch ( V_30 -> type ) {
case V_43 :
case V_82 :
break;
default:
F_1 ( V_70 , L_8 ) ;
return V_90 ;
}
switch ( V_30 -> V_44 . type ) {
case V_46 :
if ( strlen ( V_30 -> V_44 . V_39 ) == 1 &&
V_48 -> V_34 . type != V_91 &&
V_48 -> V_34 . type != V_92 ) {
V_30 -> V_44 . type = V_76 ;
goto V_93;
}
case V_45 :
V_88 = V_48 -> V_34 . type ;
V_35 = V_48 -> V_34 . V_35 ;
V_39 = V_30 -> V_44 . V_39 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
if ( V_35 -> type == V_32 ) {
F_16 ( V_35 ) ;
F_16 ( V_30 ) ;
V_48 -> type = V_32 ;
V_48 -> boolean . V_44 = V_81 ;
break;
}
if ( V_35 -> type != V_82 ) {
F_1 ( V_70 ,
L_9 ) ;
return V_94 ;
}
switch ( V_88 ) {
case V_95 :
V_88 = V_96 ;
break;
case V_97 :
V_88 = V_98 ;
break;
case V_91 :
case V_92 :
V_62 = regcomp ( & V_48 -> V_39 . V_41 , V_39 , V_64 | V_65 ) ;
if ( V_62 ) {
F_1 ( V_70 ,
L_10 ,
V_39 ) ;
return V_99 ;
}
break;
default:
F_1 ( V_70 ,
L_11 ) ;
return V_100 ;
}
V_48 -> type = V_38 ;
V_48 -> V_39 . type = V_88 ;
V_48 -> V_39 . V_72 = V_35 -> V_72 . V_72 ;
V_48 -> V_39 . V_40 = F_22 ( V_39 ) ;
if ( ! V_48 -> V_39 . V_40 ) {
F_1 ( V_70 , L_12 ) ;
return V_63 ;
}
V_48 -> V_39 . V_42 = malloc ( V_48 -> V_39 . V_72 -> V_101 + 1 ) ;
if ( ! V_48 -> V_39 . V_42 ) {
F_1 ( V_70 , L_12 ) ;
return V_63 ;
}
V_48 -> V_39 . V_42 [ V_48 -> V_39 . V_72 -> V_101 ] = 0 ;
F_16 ( V_30 ) ;
F_16 ( V_35 ) ;
break;
case V_76 :
V_93:
switch ( V_48 -> V_34 . type ) {
case V_91 :
case V_92 :
F_1 ( V_70 ,
L_13 ) ;
return V_102 ;
default:
break;
}
V_48 -> V_34 . V_36 = V_30 ;
break;
default:
goto V_89;
}
break;
default:
goto V_89;
}
return 0 ;
V_89:
F_1 ( V_70 , L_14 ) ;
return V_103 ;
}
static struct V_29 *
F_29 ( struct V_29 * V_15 , struct V_29 * V_16 )
{
struct V_29 * V_30 ;
V_30 = V_15 -> V_48 . V_36 ;
V_15 -> V_48 . V_36 = V_16 ;
return V_30 ;
}
static enum V_57 F_30 ( struct V_29 * V_48 , struct V_29 * V_30 )
{
switch ( V_48 -> type ) {
case V_37 :
if ( V_30 -> type == V_47 )
V_30 = F_29 ( V_30 , V_48 ) ;
V_48 -> exp . V_35 = V_30 ;
break;
case V_47 :
V_48 -> V_48 . V_35 = V_30 ;
break;
case V_33 :
if ( V_30 -> type == V_47 )
V_30 = F_29 ( V_30 , V_48 ) ;
if ( V_30 -> type != V_82 &&
V_30 -> type != V_32 )
return V_104 ;
V_48 -> V_34 . V_35 = V_30 ;
break;
default:
return V_104 ;
}
return 0 ;
}
static enum V_88 F_31 ( const char * V_9 ,
enum V_84 * V_85 ,
enum V_105 * V_106 ,
enum V_86 * V_87 )
{
* V_85 = V_107 ;
* V_87 = V_108 ;
* V_106 = V_109 ;
if ( strcmp ( V_9 , L_15 ) == 0 )
* V_85 = V_110 ;
else if ( strcmp ( V_9 , L_16 ) == 0 )
* V_85 = V_111 ;
else if ( strcmp ( V_9 , L_2 ) == 0 )
return V_112 ;
if ( * V_85 != V_107 )
return V_113 ;
if ( strcmp ( V_9 , L_17 ) == 0 ) {
* V_87 = V_114 ;
} else if ( strcmp ( V_9 , L_18 ) == 0 ) {
* V_87 = V_115 ;
} else if ( strcmp ( V_9 , L_19 ) == 0 ) {
* V_87 = V_116 ;
} else if ( strcmp ( V_9 , L_20 ) == 0 ) {
* V_87 = V_117 ;
} else if ( strcmp ( V_9 , L_21 ) == 0 ) {
* V_87 = V_118 ;
} else if ( strcmp ( V_9 , L_22 ) == 0 ) {
* V_87 = V_119 ;
} else if ( strcmp ( V_9 , L_23 ) == 0 ) {
* V_87 = V_120 ;
} else if ( strcmp ( V_9 , L_24 ) == 0 ) {
* V_87 = V_121 ;
} else if ( strcmp ( V_9 , L_25 ) == 0 ) {
* V_87 = V_122 ;
} else if ( strcmp ( V_9 , L_26 ) == 0 ) {
* V_87 = V_123 ;
} else if ( strcmp ( V_9 , L_27 ) == 0 )
* V_87 = V_124 ;
if ( * V_87 != V_108 )
return V_125 ;
if ( strcmp ( V_9 , L_28 ) == 0 )
* V_106 = V_95 ;
else if ( strcmp ( V_9 , L_29 ) == 0 )
* V_106 = V_97 ;
else if ( strcmp ( V_9 , L_30 ) == 0 )
* V_106 = V_126 ;
else if ( strcmp ( V_9 , L_31 ) == 0 )
* V_106 = V_127 ;
else if ( strcmp ( V_9 , L_32 ) == 0 )
* V_106 = V_128 ;
else if ( strcmp ( V_9 , L_33 ) == 0 )
* V_106 = V_129 ;
else if ( strcmp ( V_9 , L_34 ) == 0 )
* V_106 = V_91 ;
else if ( strcmp ( V_9 , L_35 ) == 0 )
* V_106 = V_92 ;
else
return V_130 ;
return V_131 ;
}
static int F_32 ( struct V_29 * V_30 )
{
switch ( V_30 -> type ) {
case V_37 :
return V_30 -> exp . V_36 != NULL ;
case V_47 :
return V_30 -> V_48 . V_36 != NULL ;
case V_33 :
return V_30 -> V_34 . V_36 != NULL ;
case V_38 :
return 1 ;
case V_32 :
return 1 ;
default:
return 0 ;
}
}
static enum V_57
F_33 ( struct V_29 * V_132 , struct V_29 * V_133 ,
struct V_29 * V_30 , char * V_70 )
{
struct V_29 * V_134 ;
struct V_29 * * V_135 ;
if ( V_132 -> type != V_47 &&
V_30 -> type != V_47 ) {
F_1 ( V_70 , L_36 ) ;
return V_136 ;
}
if ( V_133 -> V_48 . V_36 == V_30 ) {
V_135 = & V_133 -> V_48 . V_36 ;
V_134 = V_133 -> V_48 . V_35 ;
} else if ( V_133 -> V_48 . V_35 == V_30 ) {
V_135 = & V_133 -> V_48 . V_35 ;
V_134 = V_133 -> V_48 . V_36 ;
} else {
F_1 ( V_70 , L_37 ) ;
return V_137 ;
}
* V_135 = NULL ;
if ( V_132 == V_133 ) {
F_16 ( V_134 ) ;
* V_132 = * V_30 ;
free ( V_30 ) ;
return 0 ;
}
if ( V_132 -> V_48 . V_36 == V_133 )
V_135 = & V_132 -> V_48 . V_36 ;
else if ( V_132 -> V_48 . V_35 == V_133 )
V_135 = & V_132 -> V_48 . V_35 ;
else {
F_1 ( V_70 , L_38 ) ;
return V_137 ;
}
* V_135 = V_30 ;
F_16 ( V_133 ) ;
return 0 ;
}
static int F_34 ( struct V_29 * V_132 , struct V_29 * V_30 ,
char * V_70 )
{
int V_138 , V_139 ;
switch ( V_30 -> type ) {
case V_32 :
return V_140 + V_30 -> boolean . V_44 ;
case V_38 :
case V_43 :
case V_82 :
return V_141 ;
case V_37 :
V_138 = F_34 ( V_30 , V_30 -> exp . V_35 , V_70 ) ;
if ( V_138 != V_141 )
return V_138 ;
V_139 = F_34 ( V_30 , V_30 -> exp . V_36 , V_70 ) ;
if ( V_139 != V_141 )
return V_139 ;
return V_141 ;
case V_33 :
V_138 = F_34 ( V_30 , V_30 -> V_34 . V_35 , V_70 ) ;
if ( V_138 != V_141 )
return V_138 ;
V_139 = F_34 ( V_30 , V_30 -> V_34 . V_36 , V_70 ) ;
if ( V_139 != V_141 )
return V_139 ;
return V_141 ;
case V_47 :
if ( V_30 -> V_48 . type != V_107 ) {
V_138 = F_34 ( V_30 , V_30 -> V_48 . V_35 , V_70 ) ;
switch ( V_138 ) {
case V_141 :
break;
case V_142 :
if ( V_30 -> V_48 . type == V_111 )
return V_142 ;
V_139 = F_34 ( V_30 , V_30 -> V_48 . V_36 , V_70 ) ;
if ( V_139 != V_141 )
return V_139 ;
return F_33 ( V_132 , V_30 , V_30 -> V_48 . V_36 ,
V_70 ) ;
case V_140 :
if ( V_30 -> V_48 . type == V_110 )
return V_140 ;
V_139 = F_34 ( V_30 , V_30 -> V_48 . V_36 , V_70 ) ;
if ( V_139 != V_141 )
return V_139 ;
return F_33 ( V_132 , V_30 , V_30 -> V_48 . V_36 ,
V_70 ) ;
default:
return V_138 ;
}
}
V_139 = F_34 ( V_30 , V_30 -> V_48 . V_36 , V_70 ) ;
switch ( V_139 ) {
case V_141 :
default:
break;
case V_142 :
if ( V_30 -> V_48 . type == V_111 )
return V_142 ;
if ( V_30 -> V_48 . type == V_107 )
return V_140 ;
return F_33 ( V_132 , V_30 , V_30 -> V_48 . V_35 ,
V_70 ) ;
case V_140 :
if ( V_30 -> V_48 . type == V_110 )
return V_140 ;
if ( V_30 -> V_48 . type == V_107 )
return V_142 ;
return F_33 ( V_132 , V_30 , V_30 -> V_48 . V_35 ,
V_70 ) ;
}
return V_139 ;
default:
F_1 ( V_70 , L_39 ) ;
return V_143 ;
}
return V_141 ;
}
static int F_35 ( struct V_29 * V_30 ,
struct V_29 * * V_144 , char * V_70 )
{
int V_62 ;
V_62 = F_34 ( V_30 , V_30 , V_70 ) ;
switch ( V_62 ) {
case V_141 :
break;
case V_142 :
case V_140 :
F_16 ( V_30 ) ;
V_30 = F_15 () ;
if ( V_30 ) {
V_30 -> type = V_32 ;
V_30 -> boolean . V_44 = V_62 == V_142 ;
} else {
F_1 ( V_70 , L_40 ) ;
V_62 = V_63 ;
}
break;
default:
F_16 ( V_30 ) ;
V_30 = NULL ;
break;
}
* V_144 = V_30 ;
return V_62 ;
}
static enum V_57
F_36 ( struct V_51 * V_27 , struct V_29 * * V_69 ,
char * V_70 , int V_145 )
{
enum V_10 type ;
char * V_9 = NULL ;
struct V_29 * V_146 = NULL ;
struct V_29 * V_147 = NULL ;
struct V_29 * V_148 = NULL ;
struct V_29 * V_30 = NULL ;
enum V_88 V_88 ;
enum V_84 V_85 ;
enum V_86 V_87 ;
enum V_105 V_106 ;
enum V_57 V_62 ;
* V_69 = NULL ;
do {
free ( V_9 ) ;
type = F_6 ( & V_9 ) ;
switch ( type ) {
case V_73 :
case V_74 :
case V_75 :
V_62 = F_21 ( V_27 , V_9 , type , & V_30 , V_70 ) ;
if ( V_62 < 0 )
goto V_61;
if ( ! V_148 )
V_148 = V_30 ;
else if ( V_147 ) {
V_62 = F_28 ( V_147 , V_30 , V_70 ) ;
if ( V_62 < 0 )
goto V_61;
V_148 = NULL ;
if ( V_145 ) {
V_30 = NULL ;
if ( V_146 )
goto V_149;
free ( V_9 ) ;
* V_69 = V_147 ;
return 0 ;
}
} else
goto V_149;
V_30 = NULL ;
break;
case V_150 :
if ( * V_9 == ',' ) {
F_1 ( V_70 , L_41 ) ;
V_62 = V_151 ;
goto V_61;
}
if ( * V_9 == '(' ) {
if ( V_148 ) {
F_1 ( V_70 ,
L_42 ) ;
V_62 = V_152 ;
goto V_61;
}
if ( V_147 ) {
F_1 ( V_70 ,
L_43 ) ;
V_62 = V_152 ;
goto V_61;
}
V_62 = F_36 ( V_27 , & V_30 , V_70 , 0 ) ;
if ( V_62 != V_153 ) {
if ( V_62 == 0 ) {
F_1 ( V_70 ,
L_44 ) ;
V_62 = V_153 ;
}
goto V_61;
}
V_62 = 0 ;
if ( V_145 ) {
if ( V_146 )
goto V_149;
* V_69 = V_30 ;
return 0 ;
}
if ( V_146 )
V_62 = F_28 ( V_146 , V_30 , V_70 ) ;
else
V_147 = V_30 ;
if ( V_62 < 0 )
goto V_61;
} else {
if ( ! V_146 && ! V_147 )
goto V_149;
if ( V_147 && ! F_32 ( V_147 ) )
goto V_149;
if ( V_146 && ! F_32 ( V_146 ) )
goto V_149;
if ( V_146 )
* V_69 = V_146 ;
else
* V_69 = V_147 ;
free ( V_9 ) ;
return V_153 ;
}
break;
case V_154 :
V_88 = F_31 ( V_9 , & V_85 , & V_106 , & V_87 ) ;
switch ( V_88 ) {
case V_113 :
if ( ! V_147 && ! V_146 )
goto V_149;
case V_112 :
if ( V_148 )
goto V_149;
break;
case V_125 :
case V_131 :
if ( ! V_148 )
goto V_149;
break;
case V_130 :
F_1 ( V_70 ,
L_45 , V_9 ) ;
V_62 = V_155 ;
goto V_61;
}
V_62 = 0 ;
switch ( V_88 ) {
case V_113 :
V_30 = F_25 ( V_85 ) ;
if ( V_30 == NULL )
goto V_156;
if ( V_146 )
V_62 = F_30 ( V_30 , V_146 ) ;
else
V_62 = F_30 ( V_30 , V_147 ) ;
V_146 = V_30 ;
V_147 = NULL ;
break;
case V_112 :
V_30 = F_25 ( V_85 ) ;
if ( V_30 == NULL )
goto V_156;
if ( V_146 )
V_62 = F_28 ( V_146 , V_30 , V_70 ) ;
if ( V_62 < 0 )
goto V_61;
V_147 = V_30 ;
V_62 = F_36 ( V_27 , & V_30 , V_70 , 1 ) ;
if ( V_62 < 0 )
goto V_61;
V_62 = F_28 ( V_147 , V_30 , V_70 ) ;
if ( V_62 < 0 )
goto V_61;
break;
case V_125 :
case V_131 :
if ( V_88 == V_125 )
V_30 = F_26 ( V_87 ) ;
else
V_30 = F_27 ( V_106 ) ;
if ( V_30 == NULL )
goto V_156;
if ( V_146 )
V_62 = F_28 ( V_146 , V_30 , V_70 ) ;
if ( V_62 < 0 )
goto V_61;
V_62 = F_30 ( V_30 , V_148 ) ;
if ( V_62 < 0 ) {
V_30 = NULL ;
goto V_149;
}
V_147 = V_30 ;
break;
default:
break;
}
V_30 = NULL ;
if ( V_62 < 0 )
goto V_149;
break;
case V_157 :
break;
case V_14 :
goto V_156;
default:
goto V_149;
}
} while ( type != V_157 );
if ( ! V_146 && ! V_147 )
goto V_149;
if ( ! V_146 )
V_146 = V_147 ;
V_62 = F_35 ( V_146 , V_69 , V_70 ) ;
V_146 = NULL ;
if ( V_62 < 0 )
goto V_61;
free ( V_9 ) ;
return 0 ;
V_156:
F_1 ( V_70 , L_5 ) ;
V_62 = V_63 ;
goto V_61;
V_149:
F_1 ( V_70 , L_14 ) ;
V_62 = V_103 ;
V_61:
F_16 ( V_146 ) ;
F_16 ( V_147 ) ;
F_16 ( V_30 ) ;
free ( V_9 ) ;
return V_62 ;
}
static enum V_57
F_37 ( struct V_51 * V_27 , const char * V_158 ,
struct V_29 * * V_69 , char * V_70 )
{
int V_62 ;
F_38 ( V_158 , strlen ( V_158 ) ) ;
V_62 = F_36 ( V_27 , V_69 , V_70 , 0 ) ;
if ( V_62 < 0 )
return V_62 ;
if ( ! * V_69 ) {
* V_69 = F_15 () ;
if ( * V_69 == NULL )
return V_63 ;
( * V_69 ) -> type = V_32 ;
( * V_69 ) -> boolean . V_44 = V_81 ;
}
return 0 ;
}
static enum V_57
F_39 ( struct V_21 * V_22 , struct V_51 * V_27 ,
const char * V_158 , char * V_70 )
{
struct V_17 * V_17 ;
struct V_29 * V_30 ;
enum V_57 V_62 ;
if ( V_158 ) {
V_62 = F_37 ( V_27 , V_158 , & V_30 , V_70 ) ;
if ( V_62 < 0 )
return V_62 ;
} else {
V_30 = F_15 () ;
if ( V_30 == NULL )
return V_63 ;
V_30 -> type = V_32 ;
V_30 -> boolean . V_44 = V_159 ;
}
V_17 = F_11 ( V_22 , V_27 -> V_23 ) ;
if ( V_17 == NULL )
return V_63 ;
if ( V_17 -> V_22 )
F_16 ( V_17 -> V_22 ) ;
V_17 -> V_22 = V_30 ;
return 0 ;
}
static void F_40 ( struct V_21 * V_22 )
{
F_38 ( L_46 , 0 ) ;
V_22 -> V_160 [ 0 ] = '\0' ;
}
enum V_57 F_41 ( struct V_21 * V_22 ,
const char * V_158 )
{
struct V_28 * V_28 = V_22 -> V_28 ;
struct V_49 * V_27 ;
struct V_49 * V_50 = NULL ;
const char * V_161 ;
const char * V_162 ;
char * V_163 ;
char * V_59 = NULL ;
char * V_58 = NULL ;
char * V_164 ;
enum V_57 V_165 = 0 ;
int V_6 ;
int V_62 ;
F_40 ( V_22 ) ;
V_161 = strchr ( V_158 , ':' ) ;
if ( V_161 )
V_6 = V_161 - V_158 ;
else
V_6 = strlen ( V_158 ) ;
do {
V_162 = strchr ( V_158 , ',' ) ;
if ( V_162 &&
( ! V_161 || V_162 < V_161 ) )
V_6 = V_162 - V_158 ;
else if ( V_161 )
V_6 = V_161 - V_158 ;
else
V_6 = strlen ( V_158 ) ;
V_163 = malloc ( V_6 + 1 ) ;
if ( V_163 == NULL ) {
F_20 ( V_50 ) ;
return V_63 ;
}
memcpy ( V_163 , V_158 , V_6 ) ;
V_163 [ V_6 ] = 0 ;
if ( V_162 )
V_162 ++ ;
V_158 = V_162 ;
V_58 = strtok_r ( V_163 , L_20 , & V_164 ) ;
V_59 = strtok_r ( NULL , L_20 , & V_164 ) ;
if ( ! V_58 ) {
F_20 ( V_50 ) ;
free ( V_163 ) ;
return V_166 ;
}
V_62 = F_19 ( V_28 , & V_50 , F_42 ( V_58 ) , F_42 ( V_59 ) ) ;
if ( V_62 < 0 ) {
F_20 ( V_50 ) ;
free ( V_163 ) ;
return V_62 ;
}
free ( V_163 ) ;
} while ( V_158 );
if ( V_161 )
V_161 ++ ;
for ( V_27 = V_50 ; V_27 ; V_27 = V_27 -> V_53 ) {
V_62 = F_39 ( V_22 , V_27 -> V_27 , V_161 ,
V_22 -> V_160 ) ;
if ( V_62 < 0 )
V_165 = V_62 ;
if ( V_62 >= 0 && V_28 -> V_167 ) {
char * V_168 ;
V_168 = F_43 ( V_22 , V_27 -> V_27 -> V_23 ) ;
if ( V_168 ) {
printf ( L_47 , V_27 -> V_27 -> V_56 , V_168 ) ;
free ( V_168 ) ;
}
}
}
F_20 ( V_50 ) ;
if ( V_165 >= 0 && V_28 -> V_167 )
exit ( 0 ) ;
return V_165 ;
}
static void F_44 ( struct V_17 * V_17 )
{
F_16 ( V_17 -> V_22 ) ;
}
int F_45 ( struct V_21 * V_22 , enum V_57 V_169 ,
char * V_170 , T_3 V_171 )
{
if ( V_169 <= V_172 || V_169 >= V_173 )
return - 1 ;
if ( strlen ( V_22 -> V_160 ) > 0 ) {
T_3 V_6 = snprintf ( V_170 , V_171 , L_48 , V_22 -> V_160 ) ;
if ( V_6 > V_171 )
return - 1 ;
return 0 ;
}
return F_46 ( V_22 -> V_28 , V_169 , V_170 , V_171 ) ;
}
int F_47 ( struct V_21 * V_22 ,
int V_20 )
{
struct V_17 * V_17 ;
unsigned long V_6 ;
if ( ! V_22 -> V_26 )
return 0 ;
V_17 = F_10 ( V_22 , V_20 ) ;
if ( ! V_17 )
return 0 ;
F_44 ( V_17 ) ;
V_6 = ( unsigned long ) ( V_22 -> V_25 + V_22 -> V_26 ) -
( unsigned long ) ( V_17 + 1 ) ;
memmove ( V_17 , V_17 + 1 , V_6 ) ;
V_22 -> V_26 -- ;
memset ( & V_22 -> V_25 [ V_22 -> V_26 ] , 0 ,
sizeof( * V_17 ) ) ;
return 1 ;
}
void F_48 ( struct V_21 * V_22 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_22 -> V_26 ; V_7 ++ )
F_44 ( & V_22 -> V_25 [ V_7 ] ) ;
free ( V_22 -> V_25 ) ;
V_22 -> V_26 = 0 ;
V_22 -> V_25 = NULL ;
}
void F_49 ( struct V_21 * V_22 )
{
F_50 ( V_22 -> V_28 ) ;
F_48 ( V_22 ) ;
free ( V_22 ) ;
}
static int F_51 ( struct V_21 * V_22 ,
struct V_21 * V_174 ,
struct V_17 * V_17 )
{
struct V_29 * V_30 ;
struct V_51 * V_27 ;
const char * V_175 ;
const char * V_56 ;
char * V_39 ;
V_175 = V_17 -> V_27 -> system ;
V_56 = V_17 -> V_27 -> V_56 ;
V_27 = F_52 ( V_22 -> V_28 , V_175 , V_56 ) ;
if ( ! V_27 )
return - 1 ;
V_39 = F_53 ( V_174 , V_17 -> V_22 ) ;
if ( ! V_39 )
return - 1 ;
if ( strcmp ( V_39 , L_49 ) == 0 || strcmp ( V_39 , L_50 ) == 0 ) {
V_30 = F_15 () ;
if ( V_30 == NULL )
return - 1 ;
V_30 -> type = V_32 ;
if ( strcmp ( V_39 , L_49 ) == 0 )
V_30 -> boolean . V_44 = 1 ;
else
V_30 -> boolean . V_44 = 0 ;
V_17 = F_11 ( V_22 , V_27 -> V_23 ) ;
if ( V_17 == NULL )
return - 1 ;
V_17 -> V_22 = V_30 ;
free ( V_39 ) ;
return 0 ;
}
F_39 ( V_22 , V_27 , V_39 , NULL ) ;
free ( V_39 ) ;
return 0 ;
}
int F_54 ( struct V_21 * V_176 , struct V_21 * V_174 )
{
int V_62 = 0 ;
int V_7 ;
F_48 ( V_176 ) ;
for ( V_7 = 0 ; V_7 < V_174 -> V_26 ; V_7 ++ ) {
if ( F_51 ( V_176 , V_174 , & V_174 -> V_25 [ V_7 ] ) )
V_62 = - 1 ;
}
return V_62 ;
}
int F_55 ( struct V_21 * V_176 , struct V_21 * V_174 ,
enum V_177 type )
{
struct V_28 * V_178 ;
struct V_28 * V_179 ;
struct V_51 * V_27 ;
struct V_17 * V_17 ;
struct V_29 * V_30 ;
char * V_39 ;
int V_7 ;
V_178 = V_174 -> V_28 ;
V_179 = V_176 -> V_28 ;
if ( ! V_176 -> V_26 || ! V_174 -> V_26 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_176 -> V_26 ; V_7 ++ ) {
V_17 = & V_176 -> V_25 [ V_7 ] ;
V_30 = V_17 -> V_22 ;
if ( V_30 -> type != V_32 )
continue;
if ( ( V_30 -> boolean . V_44 && type == V_180 ) ||
( ! V_30 -> boolean . V_44 && type == V_181 ) )
continue;
V_27 = V_17 -> V_27 ;
if ( V_178 != V_179 ) {
V_27 = F_52 ( V_178 ,
V_27 -> system ,
V_27 -> V_56 ) ;
if ( ! V_27 )
return - 1 ;
}
V_39 = F_43 ( V_174 , V_27 -> V_23 ) ;
if ( ! V_39 )
continue;
if ( strcmp ( V_39 , L_49 ) != 0 && strcmp ( V_39 , L_50 ) != 0 )
F_39 ( V_176 , V_27 , V_39 , NULL ) ;
free ( V_39 ) ;
}
return 0 ;
}
int F_56 ( struct V_21 * V_22 ,
enum V_177 type )
{
struct V_17 * V_17 ;
int V_182 = 0 ;
int * V_183 = NULL ;
int V_7 ;
if ( ! V_22 -> V_26 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_22 -> V_26 ; V_7 ++ ) {
int * V_184 ;
V_17 = & V_22 -> V_25 [ V_7 ] ;
if ( V_17 -> V_22 -> type != V_32 )
continue;
switch ( type ) {
case V_180 :
if ( V_17 -> V_22 -> boolean . V_44 )
continue;
case V_181 :
if ( ! V_17 -> V_22 -> boolean . V_44 )
continue;
default:
break;
}
V_184 = realloc ( V_183 , sizeof( * V_183 ) * ( V_182 + 1 ) ) ;
if ( ! V_184 ) {
free ( V_183 ) ;
return - 1 ;
}
V_183 = V_184 ;
V_183 [ V_182 ++ ] = V_17 -> V_20 ;
}
if ( ! V_182 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_182 ; V_7 ++ )
F_47 ( V_22 , V_183 [ V_7 ] ) ;
free ( V_183 ) ;
return 0 ;
}
int F_57 ( struct V_21 * V_22 ,
int V_20 ,
enum V_177 type )
{
struct V_17 * V_17 ;
if ( ! V_22 -> V_26 )
return 0 ;
V_17 = F_10 ( V_22 , V_20 ) ;
if ( ! V_17 )
return 0 ;
if ( V_17 -> V_22 -> type != V_32 )
return 0 ;
switch ( type ) {
case V_180 :
return ! V_17 -> V_22 -> boolean . V_44 ;
case V_181 :
return V_17 -> V_22 -> boolean . V_44 ;
default:
return 1 ;
}
}
static const char *
F_58 ( struct V_51 * V_27 , struct V_185 * V_186 )
{
const char * V_78 ;
int V_187 ;
V_187 = F_59 ( V_27 -> V_28 , V_186 ) ;
V_78 = F_60 ( V_27 -> V_28 , V_187 ) ;
return V_78 ;
}
static unsigned long long
F_61 ( struct V_51 * V_27 ,
struct V_71 * V_72 , struct V_185 * V_186 )
{
unsigned long long V_40 ;
if ( V_72 == & V_78 ) {
const char * V_56 ;
V_56 = F_58 ( V_27 , V_186 ) ;
return ( unsigned long ) V_56 ;
}
if ( V_72 == & V_80 )
return V_186 -> V_80 ;
F_62 ( V_72 , V_186 -> V_188 , & V_40 ) ;
if ( ! ( V_72 -> V_189 & V_190 ) )
return V_40 ;
switch ( V_72 -> V_101 ) {
case 1 :
return ( char ) V_40 ;
case 2 :
return ( short ) V_40 ;
case 4 :
return ( int ) V_40 ;
case 8 :
return ( long long ) V_40 ;
}
return V_40 ;
}
static unsigned long long
F_63 ( struct V_51 * V_27 , struct V_29 * V_30 ,
struct V_185 * V_186 , enum V_57 * V_169 )
{
unsigned long long V_138 , V_139 ;
V_138 = F_64 ( V_27 , V_30 -> exp . V_35 , V_186 , V_169 ) ;
V_139 = F_64 ( V_27 , V_30 -> exp . V_36 , V_186 , V_169 ) ;
if ( * V_169 ) {
return 0 ;
}
switch ( V_30 -> exp . type ) {
case V_114 :
return V_138 + V_139 ;
case V_115 :
return V_138 - V_139 ;
case V_116 :
return V_138 * V_139 ;
case V_117 :
return V_138 / V_139 ;
case V_118 :
return V_138 % V_139 ;
case V_119 :
return V_138 >> V_139 ;
case V_120 :
return V_138 << V_139 ;
case V_121 :
return V_138 & V_139 ;
case V_122 :
return V_138 | V_139 ;
case V_123 :
return V_138 ^ V_139 ;
case V_124 :
default:
if ( ! * V_169 )
* V_169 = V_191 ;
}
return 0 ;
}
static unsigned long long
F_64 ( struct V_51 * V_27 , struct V_29 * V_30 ,
struct V_185 * V_186 , enum V_57 * V_169 )
{
switch ( V_30 -> type ) {
case V_82 :
return F_61 ( V_27 , V_30 -> V_72 . V_72 , V_186 ) ;
case V_43 :
if ( V_30 -> V_44 . type != V_76 ) {
if ( ! * V_169 )
* V_169 = V_192 ;
}
return V_30 -> V_44 . V_40 ;
case V_37 :
return F_63 ( V_27 , V_30 , V_186 , V_169 ) ;
default:
if ( ! * V_169 )
* V_169 = V_104 ;
}
return 0 ;
}
static int F_65 ( struct V_51 * V_27 , struct V_29 * V_30 ,
struct V_185 * V_186 , enum V_57 * V_169 )
{
unsigned long long V_138 , V_139 ;
V_138 = F_64 ( V_27 , V_30 -> V_34 . V_35 , V_186 , V_169 ) ;
V_139 = F_64 ( V_27 , V_30 -> V_34 . V_36 , V_186 , V_169 ) ;
if ( * V_169 ) {
return 0 ;
}
switch ( V_30 -> V_34 . type ) {
case V_95 :
return V_138 == V_139 ;
case V_97 :
return V_138 != V_139 ;
case V_127 :
return V_138 > V_139 ;
case V_126 :
return V_138 < V_139 ;
case V_129 :
return V_138 >= V_139 ;
case V_128 :
return V_138 <= V_139 ;
default:
if ( ! * V_169 )
* V_169 = V_102 ;
return 0 ;
}
}
static const char * F_66 ( struct V_29 * V_30 , struct V_185 * V_186 )
{
struct V_51 * V_27 ;
struct V_28 * V_28 ;
unsigned long long V_193 ;
const char * V_40 = NULL ;
char V_194 [ 64 ] ;
if ( V_30 -> V_39 . V_72 -> V_189 & V_195 ) {
V_40 = V_186 -> V_188 + V_30 -> V_39 . V_72 -> V_196 ;
if ( * ( V_40 + V_30 -> V_39 . V_72 -> V_101 - 1 ) ) {
memcpy ( V_30 -> V_39 . V_42 , V_40 , V_30 -> V_39 . V_72 -> V_101 ) ;
V_40 = V_30 -> V_39 . V_42 ;
}
} else {
V_27 = V_30 -> V_39 . V_72 -> V_27 ;
V_28 = V_27 -> V_28 ;
V_193 = F_61 ( V_27 , V_30 -> V_39 . V_72 , V_186 ) ;
if ( V_30 -> V_39 . V_72 -> V_189 & ( V_197 | V_198 ) )
V_40 = F_67 ( V_28 , V_193 ) ;
if ( V_40 == NULL ) {
snprintf ( V_194 , 64 , L_51 , V_193 ) ;
V_40 = V_194 ;
}
}
return V_40 ;
}
static int F_68 ( struct V_51 * V_27 , struct V_29 * V_30 ,
struct V_185 * V_186 , enum V_57 * V_169 )
{
const char * V_40 ;
if ( V_30 -> V_39 . V_72 == & V_78 )
V_40 = F_58 ( V_27 , V_186 ) ;
else
V_40 = F_66 ( V_30 , V_186 ) ;
switch ( V_30 -> V_39 . type ) {
case V_96 :
return strcmp ( V_40 , V_30 -> V_39 . V_40 ) == 0 ;
case V_98 :
return strcmp ( V_40 , V_30 -> V_39 . V_40 ) != 0 ;
case V_91 :
return ! regexec ( & V_30 -> V_39 . V_41 , V_40 , 0 , NULL , 0 ) ;
case V_92 :
return regexec ( & V_30 -> V_39 . V_41 , V_40 , 0 , NULL , 0 ) ;
default:
if ( ! * V_169 )
* V_169 = V_100 ;
return 0 ;
}
}
static int F_69 ( struct V_51 * V_27 , struct V_29 * V_30 ,
struct V_185 * V_186 , enum V_57 * V_169 )
{
switch ( V_30 -> V_48 . type ) {
case V_110 :
return F_70 ( V_27 , V_30 -> V_48 . V_35 , V_186 , V_169 ) &&
F_70 ( V_27 , V_30 -> V_48 . V_36 , V_186 , V_169 ) ;
case V_111 :
return F_70 ( V_27 , V_30 -> V_48 . V_35 , V_186 , V_169 ) ||
F_70 ( V_27 , V_30 -> V_48 . V_36 , V_186 , V_169 ) ;
case V_107 :
return ! F_70 ( V_27 , V_30 -> V_48 . V_36 , V_186 , V_169 ) ;
default:
if ( ! * V_169 )
* V_169 = V_199 ;
return 0 ;
}
}
static int F_70 ( struct V_51 * V_27 , struct V_29 * V_30 ,
struct V_185 * V_186 , enum V_57 * V_169 )
{
if ( * V_169 ) {
return 0 ;
}
switch ( V_30 -> type ) {
case V_32 :
return V_30 -> boolean . V_44 ;
case V_47 :
return F_69 ( V_27 , V_30 , V_186 , V_169 ) ;
case V_33 :
return F_65 ( V_27 , V_30 , V_186 , V_169 ) ;
case V_38 :
return F_68 ( V_27 , V_30 , V_186 , V_169 ) ;
case V_37 :
case V_43 :
case V_82 :
return ! ! F_64 ( V_27 , V_30 , V_186 , V_169 ) ;
default:
if ( ! * V_169 )
* V_169 = V_104 ;
return 0 ;
}
}
int F_71 ( struct V_21 * V_22 , int V_20 )
{
struct V_17 * V_17 ;
if ( ! V_22 -> V_26 )
return 0 ;
V_17 = F_10 ( V_22 , V_20 ) ;
return V_17 ? 1 : 0 ;
}
enum V_57 F_72 ( struct V_21 * V_22 ,
struct V_185 * V_186 )
{
struct V_28 * V_28 = V_22 -> V_28 ;
struct V_17 * V_17 ;
int V_20 ;
int V_62 ;
enum V_57 V_169 = 0 ;
F_40 ( V_22 ) ;
if ( ! V_22 -> V_26 )
return V_200 ;
V_20 = F_73 ( V_28 , V_186 ) ;
V_17 = F_10 ( V_22 , V_20 ) ;
if ( ! V_17 )
return V_166 ;
V_62 = F_70 ( V_17 -> V_27 , V_17 -> V_22 , V_186 , & V_169 ) ;
if ( V_169 )
return V_169 ;
return V_62 ? V_201 : V_202 ;
}
static char * F_74 ( struct V_21 * V_22 , struct V_29 * V_30 )
{
char * V_39 = NULL ;
char * V_35 = NULL ;
char * V_36 = NULL ;
char * V_48 = NULL ;
int V_203 = - 1 ;
int V_204 = - 1 ;
int V_40 ;
switch ( V_30 -> V_48 . type ) {
case V_110 :
V_48 = L_15 ;
case V_111 :
if ( ! V_48 )
V_48 = L_16 ;
V_35 = F_53 ( V_22 , V_30 -> V_48 . V_35 ) ;
V_36 = F_53 ( V_22 , V_30 -> V_48 . V_36 ) ;
if ( ! V_35 || ! V_36 )
break;
if ( strcmp ( V_35 , L_49 ) == 0 )
V_203 = 1 ;
else if ( strcmp ( V_35 , L_50 ) == 0 )
V_203 = 0 ;
if ( strcmp ( V_36 , L_49 ) == 0 )
V_204 = 1 ;
else if ( strcmp ( V_36 , L_50 ) == 0 )
V_204 = 0 ;
if ( V_203 >= 0 ) {
if ( ( V_30 -> V_48 . type == V_110 && ! V_203 ) ||
( V_30 -> V_48 . type == V_111 && V_203 ) ) {
V_39 = V_35 ;
V_35 = NULL ;
break;
}
if ( V_204 >= 0 ) {
V_40 = 0 ;
switch ( V_30 -> V_48 . type ) {
case V_110 :
V_40 = V_203 && V_204 ;
break;
case V_111 :
V_40 = V_203 || V_204 ;
break;
default:
break;
}
F_75 ( & V_39 , V_40 ? L_49 : L_50 ) ;
break;
}
}
if ( V_204 >= 0 ) {
if ( ( V_30 -> V_48 . type == V_110 && ! V_204 ) ||
( V_30 -> V_48 . type == V_111 && V_204 ) ) {
V_39 = V_36 ;
V_36 = NULL ;
break;
}
V_39 = V_35 ;
V_35 = NULL ;
break;
}
F_75 ( & V_39 , L_52 , V_35 , V_48 , V_36 ) ;
break;
case V_107 :
V_48 = L_2 ;
V_36 = F_53 ( V_22 , V_30 -> V_48 . V_36 ) ;
if ( ! V_36 )
break;
if ( strcmp ( V_36 , L_49 ) == 0 )
V_204 = 1 ;
else if ( strcmp ( V_36 , L_50 ) == 0 )
V_204 = 0 ;
if ( V_204 >= 0 ) {
F_75 ( & V_39 , V_204 ? L_50 : L_49 ) ;
break;
}
F_75 ( & V_39 , L_53 , V_48 , V_36 ) ;
break;
default:
break;
}
free ( V_35 ) ;
free ( V_36 ) ;
return V_39 ;
}
static char * F_76 ( struct V_21 * V_22 , struct V_29 * V_30 )
{
char * V_39 = NULL ;
F_75 ( & V_39 , L_54 , V_30 -> V_44 . V_40 ) ;
return V_39 ;
}
static char * F_77 ( struct V_21 * V_22 , struct V_29 * V_30 )
{
return F_22 ( V_30 -> V_72 . V_72 -> V_56 ) ;
}
static char * F_78 ( struct V_21 * V_22 , struct V_29 * V_30 )
{
char * V_205 ;
char * V_206 ;
char * V_48 ;
char * V_39 = NULL ;
V_205 = F_53 ( V_22 , V_30 -> exp . V_35 ) ;
V_206 = F_53 ( V_22 , V_30 -> exp . V_36 ) ;
if ( ! V_205 || ! V_206 )
goto V_207;
switch ( V_30 -> exp . type ) {
case V_114 :
V_48 = L_17 ;
break;
case V_115 :
V_48 = L_18 ;
break;
case V_116 :
V_48 = L_19 ;
break;
case V_117 :
V_48 = L_20 ;
break;
case V_118 :
V_48 = L_21 ;
break;
case V_119 :
V_48 = L_22 ;
break;
case V_120 :
V_48 = L_23 ;
break;
case V_121 :
V_48 = L_24 ;
break;
case V_122 :
V_48 = L_25 ;
break;
case V_123 :
V_48 = L_26 ;
break;
default:
V_48 = L_55 ;
break;
}
F_75 ( & V_39 , L_56 , V_205 , V_48 , V_206 ) ;
V_207:
free ( V_205 ) ;
free ( V_206 ) ;
return V_39 ;
}
static char * F_79 ( struct V_21 * V_22 , struct V_29 * V_30 )
{
char * V_205 ;
char * V_206 ;
char * V_39 = NULL ;
char * V_48 = NULL ;
V_205 = F_53 ( V_22 , V_30 -> V_34 . V_35 ) ;
V_206 = F_53 ( V_22 , V_30 -> V_34 . V_36 ) ;
if ( ! V_205 || ! V_206 )
goto V_207;
switch ( V_30 -> V_34 . type ) {
case V_95 :
V_48 = L_28 ;
case V_97 :
if ( ! V_48 )
V_48 = L_29 ;
case V_127 :
if ( ! V_48 )
V_48 = L_31 ;
case V_126 :
if ( ! V_48 )
V_48 = L_30 ;
case V_129 :
if ( ! V_48 )
V_48 = L_33 ;
case V_128 :
if ( ! V_48 )
V_48 = L_32 ;
F_75 ( & V_39 , L_56 , V_205 , V_48 , V_206 ) ;
break;
default:
break;
}
V_207:
free ( V_205 ) ;
free ( V_206 ) ;
return V_39 ;
}
static char * F_80 ( struct V_21 * V_22 , struct V_29 * V_30 )
{
char * V_39 = NULL ;
char * V_48 = NULL ;
switch ( V_30 -> V_39 . type ) {
case V_96 :
V_48 = L_28 ;
case V_98 :
if ( ! V_48 )
V_48 = L_29 ;
case V_91 :
if ( ! V_48 )
V_48 = L_34 ;
case V_92 :
if ( ! V_48 )
V_48 = L_35 ;
F_75 ( & V_39 , L_57 ,
V_30 -> V_39 . V_72 -> V_56 , V_48 , V_30 -> V_39 . V_40 ) ;
break;
default:
break;
}
return V_39 ;
}
static char * F_53 ( struct V_21 * V_22 , struct V_29 * V_30 )
{
char * V_39 = NULL ;
switch ( V_30 -> type ) {
case V_32 :
F_75 ( & V_39 , V_30 -> boolean . V_44 ? L_49 : L_50 ) ;
return V_39 ;
case V_47 :
return F_74 ( V_22 , V_30 ) ;
case V_33 :
return F_79 ( V_22 , V_30 ) ;
case V_38 :
return F_80 ( V_22 , V_30 ) ;
case V_43 :
return F_76 ( V_22 , V_30 ) ;
case V_82 :
return F_77 ( V_22 , V_30 ) ;
case V_37 :
return F_78 ( V_22 , V_30 ) ;
default:
return NULL ;
}
}
char *
F_43 ( struct V_21 * V_22 , int V_20 )
{
struct V_17 * V_17 ;
if ( ! V_22 -> V_26 )
return NULL ;
V_17 = F_10 ( V_22 , V_20 ) ;
if ( ! V_17 )
return NULL ;
return F_53 ( V_22 , V_17 -> V_22 ) ;
}
int F_81 ( struct V_21 * V_208 , struct V_21 * V_209 )
{
struct V_17 * V_210 ;
struct V_17 * V_211 ;
char * V_212 , * V_213 ;
int V_214 ;
int V_7 ;
if ( V_208 -> V_26 != V_209 -> V_26 )
return 0 ;
if ( ! V_208 -> V_26 && ! V_209 -> V_26 )
return 1 ;
for ( V_7 = 0 ; V_7 < V_208 -> V_26 ; V_7 ++ ) {
V_210 = & V_208 -> V_25 [ V_7 ] ;
V_211 = F_10 ( V_209 , V_210 -> V_20 ) ;
if ( ! V_211 )
break;
if ( V_210 -> V_22 -> type != V_211 -> V_22 -> type )
break;
switch ( V_210 -> V_22 -> type ) {
case V_180 :
case V_181 :
continue;
default:
break;
}
V_212 = F_53 ( V_208 , V_210 -> V_22 ) ;
V_213 = F_53 ( V_209 , V_211 -> V_22 ) ;
if ( V_212 && V_213 )
V_214 = strcmp ( V_212 , V_213 ) != 0 ;
else
V_214 = 1 ;
free ( V_212 ) ;
free ( V_213 ) ;
if ( V_214 )
break;
}
if ( V_7 < V_208 -> V_26 )
return 0 ;
return 1 ;
}
