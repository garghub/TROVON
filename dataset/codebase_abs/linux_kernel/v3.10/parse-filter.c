static void F_1 ( char * * V_1 , const char * V_2 , ... )
{
unsigned long long V_3 ;
const char * V_4 ;
char * error ;
T_1 V_5 ;
int V_6 ;
int V_7 ;
if ( ! V_1 )
return;
V_4 = F_2 () ;
V_3 = F_3 () ;
V_6 = V_4 ? strlen ( V_4 ) : 0 ;
error = F_4 ( V_8 + ( V_6 * 2 ) + 3 ) ;
if ( V_6 ) {
strcpy ( error , V_4 ) ;
error [ V_6 ] = '\n' ;
for ( V_7 = 1 ; V_7 < V_6 && V_7 < V_3 ; V_7 ++ )
error [ V_6 + V_7 ] = ' ' ;
error [ V_6 + V_7 ] = '^' ;
error [ V_6 + V_7 + 1 ] = '\n' ;
V_6 += V_7 + 2 ;
}
va_start ( V_5 , V_2 ) ;
vsnprintf ( error + V_6 , V_8 , V_2 , V_5 ) ;
va_end ( V_5 ) ;
* V_1 = error ;
}
static void F_5 ( char * V_9 )
{
F_6 ( V_9 ) ;
}
static enum V_10 F_7 ( char * * V_11 )
{
enum V_10 type ;
char * V_9 = NULL ;
do {
F_5 ( V_9 ) ;
type = F_8 ( & V_9 ) ;
} while ( type == V_12 || type == V_13 );
if ( V_9 &&
( strcmp ( V_9 , L_1 ) == 0 || strcmp ( V_9 , L_2 ) == 0 ) &&
F_9 () == '~' ) {
* V_11 = F_4 ( 3 ) ;
sprintf ( * V_11 , L_3 , * V_9 , '~' ) ;
F_5 ( V_9 ) ;
F_8 ( & V_9 ) ;
F_5 ( V_9 ) ;
} else
* V_11 = V_9 ;
return type ;
}
static int F_10 ( const void * V_14 , const void * V_15 )
{
const struct V_16 * V_17 = V_14 ;
const struct V_16 * V_18 = V_15 ;
if ( V_17 -> V_19 < V_18 -> V_19 )
return - 1 ;
if ( V_17 -> V_19 > V_18 -> V_19 )
return 1 ;
return 0 ;
}
static struct V_16 *
F_11 ( struct V_20 * V_21 , int V_22 )
{
struct V_16 * V_16 ;
struct V_16 V_23 ;
V_23 . V_19 = V_22 ;
V_16 = bsearch ( & V_23 , V_21 -> V_24 ,
V_21 -> V_25 ,
sizeof( * V_21 -> V_24 ) ,
F_10 ) ;
return V_16 ;
}
static struct V_16 *
F_12 ( struct V_20 * V_21 , int V_22 )
{
struct V_16 * V_16 ;
int V_7 ;
V_16 = F_11 ( V_21 , V_22 ) ;
if ( V_16 )
return V_16 ;
V_21 -> V_24 = realloc ( V_21 -> V_24 ,
sizeof( * V_21 -> V_24 ) *
( V_21 -> V_25 + 1 ) ) ;
if ( ! V_21 -> V_24 )
F_13 ( L_4 ) ;
for ( V_7 = 0 ; V_7 < V_21 -> V_25 ; V_7 ++ ) {
if ( V_21 -> V_24 [ V_7 ] . V_19 > V_22 )
break;
}
if ( V_7 < V_21 -> V_25 )
memmove ( & V_21 -> V_24 [ V_7 + 1 ] ,
& V_21 -> V_24 [ V_7 ] ,
sizeof( * V_21 -> V_24 ) *
( V_21 -> V_25 - V_7 ) ) ;
V_16 = & V_21 -> V_24 [ V_7 ] ;
V_16 -> V_19 = V_22 ;
V_16 -> V_26 = F_14 ( V_21 -> V_27 , V_22 ) ;
V_16 -> V_21 = NULL ;
V_21 -> V_25 ++ ;
return V_16 ;
}
struct V_20 * F_15 ( struct V_27 * V_27 )
{
struct V_20 * V_21 ;
V_21 = F_4 ( sizeof( * V_21 ) ) ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_27 = V_27 ;
F_16 ( V_27 ) ;
return V_21 ;
}
static struct V_28 * F_17 ( void )
{
struct V_28 * V_29 ;
V_29 = F_4 ( sizeof( * V_29 ) ) ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
return V_29 ;
}
static void F_18 ( struct V_28 * V_29 )
{
if ( ! V_29 )
return;
switch ( V_29 -> type ) {
case V_30 :
case V_31 :
break;
case V_32 :
F_18 ( V_29 -> V_33 . V_34 ) ;
F_18 ( V_29 -> V_33 . V_35 ) ;
break;
case V_36 :
F_18 ( V_29 -> exp . V_34 ) ;
F_18 ( V_29 -> exp . V_35 ) ;
break;
case V_37 :
free ( V_29 -> V_38 . V_39 ) ;
regfree ( & V_29 -> V_38 . V_40 ) ;
free ( V_29 -> V_38 . V_41 ) ;
break;
case V_42 :
if ( V_29 -> V_43 . type == V_44 ||
V_29 -> V_43 . type == V_45 )
free ( V_29 -> V_43 . V_38 ) ;
break;
case V_46 :
F_18 ( V_29 -> V_47 . V_34 ) ;
F_18 ( V_29 -> V_47 . V_35 ) ;
default:
break;
}
free ( V_29 ) ;
}
static void F_19 ( struct V_48 * * V_49 ,
struct V_50 * V_26 )
{
struct V_48 * V_51 ;
V_51 = F_4 ( sizeof( * V_51 ) ) ;
V_51 -> V_52 = * V_49 ;
* V_49 = V_51 ;
V_51 -> V_26 = V_26 ;
}
static int F_20 ( struct V_50 * V_26 ,
T_2 * V_53 , T_2 * V_54 )
{
if ( V_53 ) {
return ! regexec ( V_53 , V_26 -> system , 0 , NULL , 0 ) &&
! regexec ( V_54 , V_26 -> V_55 , 0 , NULL , 0 ) ;
}
return ! regexec ( V_54 , V_26 -> system , 0 , NULL , 0 ) ||
! regexec ( V_54 , V_26 -> V_55 , 0 , NULL , 0 ) ;
}
static int
F_21 ( struct V_27 * V_27 , struct V_48 * * V_49 ,
char * V_56 , char * V_57 )
{
struct V_50 * V_26 ;
T_2 V_54 ;
T_2 V_53 ;
int V_58 = 0 ;
char * V_40 ;
int V_59 ;
int V_7 ;
if ( ! V_57 ) {
V_57 = V_56 ;
V_56 = NULL ;
}
V_40 = F_4 ( strlen ( V_57 ) + 3 ) ;
sprintf ( V_40 , L_5 , V_57 ) ;
V_59 = regcomp ( & V_54 , V_40 , V_60 | V_61 ) ;
free ( V_40 ) ;
if ( V_59 )
return - 1 ;
if ( V_56 ) {
V_40 = F_4 ( strlen ( V_56 ) + 3 ) ;
sprintf ( V_40 , L_5 , V_56 ) ;
V_59 = regcomp ( & V_53 , V_40 , V_60 | V_61 ) ;
free ( V_40 ) ;
if ( V_59 ) {
regfree ( & V_54 ) ;
return - 1 ;
}
}
for ( V_7 = 0 ; V_7 < V_27 -> V_62 ; V_7 ++ ) {
V_26 = V_27 -> V_49 [ V_7 ] ;
if ( F_20 ( V_26 , V_56 ? & V_53 : NULL , & V_54 ) ) {
V_58 = 1 ;
F_19 ( V_49 , V_26 ) ;
}
}
regfree ( & V_54 ) ;
if ( V_56 )
regfree ( & V_53 ) ;
if ( ! V_58 )
return - 1 ;
return 0 ;
}
static void F_22 ( struct V_48 * V_49 )
{
struct V_48 * V_26 ;
while ( V_49 ) {
V_26 = V_49 ;
V_49 = V_49 -> V_52 ;
free ( V_26 ) ;
}
}
static struct V_28 *
F_23 ( struct V_50 * V_26 , const char * V_9 ,
enum V_10 type , char * * V_1 )
{
struct V_63 * V_64 ;
struct V_28 * V_29 ;
V_29 = F_17 () ;
switch ( type ) {
case V_65 :
case V_66 :
V_29 -> type = V_42 ;
V_29 -> V_43 . type =
type == V_66 ? V_44 : V_45 ;
V_29 -> V_43 . V_38 = F_24 ( V_9 ) ;
if ( ! V_29 -> V_43 . V_38 )
F_13 ( L_6 ) ;
break;
case V_67 :
if ( isdigit ( V_9 [ 0 ] ) ) {
V_29 -> type = V_42 ;
V_29 -> V_43 . type = V_68 ;
V_29 -> V_43 . V_39 = F_25 ( V_9 , NULL , 0 ) ;
break;
}
V_64 = F_26 ( V_26 , V_9 ) ;
if ( ! V_64 ) {
if ( strcmp ( V_9 , V_69 ) != 0 ) {
V_29 -> type = V_31 ;
V_29 -> boolean . V_43 = V_70 ;
break;
}
V_64 = & V_71 ;
}
V_29 -> type = V_72 ;
V_29 -> V_64 . V_64 = V_64 ;
break;
default:
F_18 ( V_29 ) ;
F_1 ( V_1 , L_7 ,
V_9 ) ;
return NULL ;
}
return V_29 ;
}
static struct V_28 *
F_27 ( enum V_73 V_74 )
{
struct V_28 * V_29 ;
V_29 = F_17 () ;
V_29 -> type = V_46 ;
V_29 -> V_47 . type = V_74 ;
return V_29 ;
}
static struct V_28 *
F_28 ( enum V_75 V_76 )
{
struct V_28 * V_29 ;
V_29 = F_17 () ;
V_29 -> type = V_36 ;
V_29 -> V_47 . type = V_76 ;
return V_29 ;
}
static struct V_28 *
F_29 ( enum V_75 V_76 )
{
struct V_28 * V_29 ;
V_29 = F_17 () ;
V_29 -> type = V_32 ;
V_29 -> V_47 . type = V_76 ;
return V_29 ;
}
static int F_30 ( struct V_28 * V_47 , struct V_28 * V_29 ,
char * * V_1 )
{
struct V_28 * V_34 ;
char * V_38 ;
int V_77 ;
int V_59 ;
switch ( V_47 -> type ) {
case V_36 :
if ( V_47 -> exp . V_35 )
goto V_78;
V_47 -> exp . V_35 = V_29 ;
break;
case V_46 :
if ( V_47 -> V_47 . V_35 )
goto V_78;
V_47 -> V_47 . V_35 = V_29 ;
break;
case V_32 :
if ( V_47 -> V_47 . V_35 )
goto V_78;
switch ( V_29 -> type ) {
case V_42 :
case V_72 :
break;
default:
F_1 ( V_1 ,
L_8 ) ;
return - 1 ;
}
switch ( V_29 -> V_43 . type ) {
case V_45 :
if ( strlen ( V_29 -> V_43 . V_38 ) == 1 &&
V_47 -> V_33 . type != V_79 &&
V_47 -> V_33 . type != V_80 ) {
V_29 -> V_43 . type = V_68 ;
goto V_81;
}
case V_44 :
V_77 = V_47 -> V_33 . type ;
V_34 = V_47 -> V_33 . V_34 ;
V_38 = V_29 -> V_43 . V_38 ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
if ( V_34 -> type == V_31 ) {
F_18 ( V_34 ) ;
F_18 ( V_29 ) ;
V_47 -> type = V_31 ;
V_47 -> boolean . V_43 = V_70 ;
break;
}
if ( V_34 -> type != V_72 ) {
F_1 ( V_1 ,
L_9 ) ;
return - 1 ;
}
switch ( V_77 ) {
case V_82 :
V_77 = V_83 ;
break;
case V_84 :
V_77 = V_85 ;
break;
case V_79 :
case V_80 :
V_59 = regcomp ( & V_47 -> V_38 . V_40 , V_38 , V_60 | V_61 ) ;
if ( V_59 ) {
F_1 ( V_1 ,
L_10 ,
V_38 ) ;
return - 1 ;
}
break;
default:
F_1 ( V_1 ,
L_11 ) ;
return - 1 ;
}
V_47 -> type = V_37 ;
V_47 -> V_38 . type = V_77 ;
V_47 -> V_38 . V_64 = V_34 -> V_64 . V_64 ;
V_47 -> V_38 . V_39 = F_24 ( V_38 ) ;
if ( ! V_47 -> V_38 . V_39 )
F_13 ( L_6 ) ;
V_47 -> V_38 . V_41 = F_4 ( V_47 -> V_38 . V_64 -> V_86 + 1 ) ;
V_47 -> V_38 . V_41 [ V_47 -> V_38 . V_64 -> V_86 ] = 0 ;
F_18 ( V_29 ) ;
F_18 ( V_34 ) ;
break;
case V_68 :
V_81:
switch ( V_47 -> V_33 . type ) {
case V_79 :
case V_80 :
F_1 ( V_1 ,
L_12 ) ;
return - 1 ;
default:
break;
}
V_47 -> V_33 . V_35 = V_29 ;
break;
default:
goto V_78;
}
break;
default:
goto V_78;
}
return 0 ;
V_78:
F_1 ( V_1 ,
L_13 ) ;
return - 1 ;
}
static struct V_28 *
F_31 ( struct V_28 * V_14 , struct V_28 * V_15 )
{
struct V_28 * V_29 ;
V_29 = V_14 -> V_47 . V_35 ;
V_14 -> V_47 . V_35 = V_15 ;
return V_29 ;
}
static int F_32 ( struct V_28 * V_47 , struct V_28 * V_29 )
{
switch ( V_47 -> type ) {
case V_36 :
if ( V_29 -> type == V_46 )
V_29 = F_31 ( V_29 , V_47 ) ;
V_47 -> exp . V_34 = V_29 ;
break;
case V_46 :
V_47 -> V_47 . V_34 = V_29 ;
break;
case V_32 :
if ( V_29 -> type == V_46 )
V_29 = F_31 ( V_29 , V_47 ) ;
if ( V_29 -> type != V_72 &&
V_29 -> type != V_31 )
return - 1 ;
V_47 -> V_33 . V_34 = V_29 ;
break;
default:
return - 1 ;
}
return 0 ;
}
static enum V_77 F_33 ( const char * V_9 ,
enum V_73 * V_74 ,
enum V_87 * V_88 ,
enum V_75 * V_76 )
{
* V_74 = V_89 ;
* V_76 = V_90 ;
* V_88 = V_91 ;
if ( strcmp ( V_9 , L_14 ) == 0 )
* V_74 = V_92 ;
else if ( strcmp ( V_9 , L_15 ) == 0 )
* V_74 = V_93 ;
else if ( strcmp ( V_9 , L_2 ) == 0 )
return V_94 ;
if ( * V_74 != V_89 )
return V_95 ;
if ( strcmp ( V_9 , L_16 ) == 0 ) {
* V_76 = V_96 ;
} else if ( strcmp ( V_9 , L_17 ) == 0 ) {
* V_76 = V_97 ;
} else if ( strcmp ( V_9 , L_18 ) == 0 ) {
* V_76 = V_98 ;
} else if ( strcmp ( V_9 , L_19 ) == 0 ) {
* V_76 = V_99 ;
} else if ( strcmp ( V_9 , L_20 ) == 0 ) {
* V_76 = V_100 ;
} else if ( strcmp ( V_9 , L_21 ) == 0 ) {
* V_76 = V_101 ;
} else if ( strcmp ( V_9 , L_22 ) == 0 ) {
* V_76 = V_102 ;
} else if ( strcmp ( V_9 , L_23 ) == 0 ) {
* V_76 = V_103 ;
} else if ( strcmp ( V_9 , L_24 ) == 0 ) {
* V_76 = V_104 ;
} else if ( strcmp ( V_9 , L_25 ) == 0 ) {
* V_76 = V_105 ;
} else if ( strcmp ( V_9 , L_26 ) == 0 )
* V_76 = V_106 ;
if ( * V_76 != V_90 )
return V_107 ;
if ( strcmp ( V_9 , L_27 ) == 0 )
* V_88 = V_82 ;
else if ( strcmp ( V_9 , L_28 ) == 0 )
* V_88 = V_84 ;
else if ( strcmp ( V_9 , L_29 ) == 0 )
* V_88 = V_108 ;
else if ( strcmp ( V_9 , L_30 ) == 0 )
* V_88 = V_109 ;
else if ( strcmp ( V_9 , L_31 ) == 0 )
* V_88 = V_110 ;
else if ( strcmp ( V_9 , L_32 ) == 0 )
* V_88 = V_111 ;
else if ( strcmp ( V_9 , L_33 ) == 0 )
* V_88 = V_79 ;
else if ( strcmp ( V_9 , L_34 ) == 0 )
* V_88 = V_80 ;
else
return V_112 ;
return V_113 ;
}
static int F_34 ( struct V_28 * V_29 )
{
switch ( V_29 -> type ) {
case V_36 :
return V_29 -> exp . V_35 != NULL ;
case V_46 :
return V_29 -> V_47 . V_35 != NULL ;
case V_32 :
return V_29 -> V_33 . V_35 != NULL ;
case V_37 :
return 1 ;
case V_31 :
return 1 ;
default:
return 0 ;
}
}
void F_35 ( struct V_28 * V_114 , struct V_28 * V_115 ,
struct V_28 * V_29 )
{
struct V_28 * V_116 ;
struct V_28 * * V_117 ;
if ( V_114 -> type != V_46 &&
V_29 -> type != V_46 )
F_13 ( L_35 ) ;
if ( V_115 -> V_47 . V_35 == V_29 ) {
V_117 = & V_115 -> V_47 . V_35 ;
V_116 = V_115 -> V_47 . V_34 ;
} else if ( V_115 -> V_47 . V_34 == V_29 ) {
V_117 = & V_115 -> V_47 . V_34 ;
V_116 = V_115 -> V_47 . V_35 ;
} else
F_13 ( L_36 ) ;
* V_117 = NULL ;
if ( V_114 == V_115 ) {
F_18 ( V_116 ) ;
* V_114 = * V_29 ;
free ( V_29 ) ;
return;
}
if ( V_114 -> V_47 . V_35 == V_115 )
V_117 = & V_114 -> V_47 . V_35 ;
else if ( V_114 -> V_47 . V_34 == V_115 )
V_117 = & V_114 -> V_47 . V_34 ;
else
F_13 ( L_37 ) ;
* V_117 = V_29 ;
F_18 ( V_115 ) ;
}
enum V_118 F_36 ( struct V_28 * V_114 , struct V_28 * V_29 )
{
enum V_118 V_119 , V_120 ;
switch ( V_29 -> type ) {
case V_31 :
return V_121 + V_29 -> boolean . V_43 ;
case V_37 :
case V_42 :
case V_72 :
return V_122 ;
case V_36 :
V_119 = F_36 ( V_29 , V_29 -> exp . V_34 ) ;
if ( V_119 != V_122 )
return V_119 ;
V_120 = F_36 ( V_29 , V_29 -> exp . V_35 ) ;
if ( V_120 != V_122 )
return V_120 ;
return V_122 ;
case V_32 :
V_119 = F_36 ( V_29 , V_29 -> V_33 . V_34 ) ;
if ( V_119 != V_122 )
return V_119 ;
V_120 = F_36 ( V_29 , V_29 -> V_33 . V_35 ) ;
if ( V_120 != V_122 )
return V_120 ;
return V_122 ;
case V_46 :
if ( V_29 -> V_47 . type != V_89 ) {
V_119 = F_36 ( V_29 , V_29 -> V_47 . V_34 ) ;
switch ( V_119 ) {
case V_122 :
break;
case V_123 :
if ( V_29 -> V_47 . type == V_93 )
return V_123 ;
V_120 = F_36 ( V_29 , V_29 -> V_47 . V_35 ) ;
if ( V_120 != V_122 )
return V_120 ;
F_35 ( V_114 , V_29 , V_29 -> V_47 . V_35 ) ;
return V_122 ;
case V_121 :
if ( V_29 -> V_47 . type == V_92 )
return V_121 ;
V_120 = F_36 ( V_29 , V_29 -> V_47 . V_35 ) ;
if ( V_120 != V_122 )
return V_120 ;
F_35 ( V_114 , V_29 , V_29 -> V_47 . V_35 ) ;
return V_122 ;
}
}
V_120 = F_36 ( V_29 , V_29 -> V_47 . V_35 ) ;
switch ( V_120 ) {
case V_122 :
break;
case V_123 :
if ( V_29 -> V_47 . type == V_93 )
return V_123 ;
if ( V_29 -> V_47 . type == V_89 )
return V_121 ;
F_35 ( V_114 , V_29 , V_29 -> V_47 . V_34 ) ;
return V_122 ;
case V_121 :
if ( V_29 -> V_47 . type == V_92 )
return V_121 ;
if ( V_29 -> V_47 . type == V_89 )
return V_123 ;
F_35 ( V_114 , V_29 , V_29 -> V_47 . V_34 ) ;
return V_122 ;
}
return V_122 ;
default:
F_13 ( L_38 ) ;
}
return V_122 ;
}
static struct V_28 * F_37 ( struct V_28 * V_29 )
{
enum V_118 V_59 ;
V_59 = F_36 ( V_29 , V_29 ) ;
switch ( V_59 ) {
case V_122 :
return V_29 ;
case V_123 :
case V_121 :
F_18 ( V_29 ) ;
V_29 = F_17 () ;
V_29 -> type = V_31 ;
V_29 -> boolean . V_43 = V_59 == V_123 ;
}
return V_29 ;
}
static int
F_38 ( struct V_50 * V_26 , struct V_28 * * V_124 ,
char * * V_1 , int V_125 )
{
enum V_10 type ;
char * V_9 = NULL ;
struct V_28 * V_126 = NULL ;
struct V_28 * V_127 = NULL ;
struct V_28 * V_128 = NULL ;
struct V_28 * V_29 = NULL ;
enum V_77 V_77 ;
enum V_73 V_74 ;
enum V_75 V_76 ;
enum V_87 V_88 ;
int V_59 ;
* V_124 = NULL ;
do {
free ( V_9 ) ;
type = F_7 ( & V_9 ) ;
switch ( type ) {
case V_65 :
case V_66 :
case V_67 :
V_29 = F_23 ( V_26 , V_9 , type , V_1 ) ;
if ( ! V_29 )
goto V_129;
if ( ! V_128 )
V_128 = V_29 ;
else if ( V_127 ) {
V_59 = F_30 ( V_127 , V_29 , V_1 ) ;
if ( V_59 < 0 )
goto V_129;
V_128 = NULL ;
if ( V_125 ) {
V_29 = NULL ;
if ( V_126 )
goto V_130;
free ( V_9 ) ;
* V_124 = V_127 ;
return 0 ;
}
} else
goto V_130;
V_29 = NULL ;
break;
case V_131 :
if ( * V_9 == ',' ) {
F_1 ( V_1 ,
L_39 ) ;
goto V_129;
}
if ( * V_9 == '(' ) {
if ( V_128 ) {
F_1 ( V_1 ,
L_40 ) ;
goto V_129;
}
if ( V_127 ) {
F_1 ( V_1 ,
L_41 ) ;
goto V_129;
}
V_59 = F_38 ( V_26 , & V_29 , V_1 , 0 ) ;
if ( V_59 != 1 ) {
if ( V_59 == 0 )
F_1 ( V_1 ,
L_42 ) ;
goto V_129;
}
V_59 = 0 ;
if ( V_125 ) {
if ( V_126 )
goto V_130;
* V_124 = V_29 ;
return 0 ;
}
if ( V_126 )
V_59 = F_30 ( V_126 , V_29 , V_1 ) ;
else
V_127 = V_29 ;
if ( V_59 < 0 )
goto V_129;
} else {
if ( ! V_126 && ! V_127 )
goto V_130;
if ( V_127 && ! F_34 ( V_127 ) )
goto V_130;
if ( V_126 && ! F_34 ( V_126 ) )
goto V_130;
if ( V_126 )
* V_124 = V_126 ;
else
* V_124 = V_127 ;
return 1 ;
}
break;
case V_132 :
V_77 = F_33 ( V_9 , & V_74 , & V_88 , & V_76 ) ;
switch ( V_77 ) {
case V_95 :
if ( ! V_127 && ! V_126 )
goto V_130;
case V_94 :
if ( V_128 )
goto V_130;
break;
case V_107 :
case V_113 :
if ( ! V_128 )
goto V_130;
break;
case V_112 :
F_1 ( V_1 ,
L_43 , V_9 ) ;
goto V_129;
}
V_59 = 0 ;
switch ( V_77 ) {
case V_95 :
V_29 = F_27 ( V_74 ) ;
if ( V_126 )
V_59 = F_32 ( V_29 , V_126 ) ;
else
V_59 = F_32 ( V_29 , V_127 ) ;
V_126 = V_29 ;
V_127 = NULL ;
break;
case V_94 :
V_29 = F_27 ( V_74 ) ;
if ( V_126 )
V_59 = F_30 ( V_126 , V_29 , V_1 ) ;
if ( V_59 < 0 )
goto V_129;
V_127 = V_29 ;
V_59 = F_38 ( V_26 , & V_29 , V_1 , 1 ) ;
if ( V_59 < 0 )
goto V_129;
V_59 = F_30 ( V_127 , V_29 , V_1 ) ;
if ( V_59 < 0 )
goto V_129;
break;
case V_107 :
case V_113 :
if ( V_77 == V_107 )
V_29 = F_28 ( V_76 ) ;
else
V_29 = F_29 ( V_88 ) ;
if ( V_126 )
V_59 = F_30 ( V_126 , V_29 , V_1 ) ;
if ( V_59 < 0 )
goto V_129;
V_59 = F_32 ( V_29 , V_128 ) ;
if ( V_59 < 0 ) {
V_29 = NULL ;
goto V_130;
}
V_127 = V_29 ;
break;
default:
break;
}
V_29 = NULL ;
if ( V_59 < 0 )
goto V_130;
break;
case V_133 :
break;
default:
goto V_130;
}
} while ( type != V_133 );
if ( ! V_126 && ! V_127 )
goto V_130;
if ( ! V_126 )
V_126 = V_127 ;
V_126 = F_37 ( V_126 ) ;
* V_124 = V_126 ;
return 0 ;
V_130:
F_1 ( V_1 , L_13 ) ;
V_129:
F_18 ( V_126 ) ;
F_18 ( V_127 ) ;
F_18 ( V_29 ) ;
free ( V_9 ) ;
return - 1 ;
}
static int
F_39 ( struct V_50 * V_26 , const char * V_134 ,
struct V_28 * * V_124 , char * * V_1 )
{
int V_59 ;
F_40 ( V_134 , strlen ( V_134 ) ) ;
V_59 = F_38 ( V_26 , V_124 , V_1 , 0 ) ;
if ( V_59 == 1 ) {
F_1 ( V_1 ,
L_44 ) ;
return - 1 ;
}
if ( V_59 < 0 )
return V_59 ;
if ( ! * V_124 ) {
* V_124 = F_17 () ;
( * V_124 ) -> type = V_31 ;
( * V_124 ) -> boolean . V_43 = V_70 ;
}
return 0 ;
}
static int F_41 ( struct V_20 * V_21 ,
struct V_50 * V_26 ,
const char * V_134 , char * * V_1 )
{
struct V_16 * V_16 ;
struct V_28 * V_29 ;
int V_59 ;
if ( V_134 ) {
V_59 = F_39 ( V_26 , V_134 , & V_29 , V_1 ) ;
if ( V_59 < 0 )
return V_59 ;
} else {
V_29 = F_17 () ;
V_29 -> type = V_31 ;
V_29 -> boolean . V_43 = V_135 ;
}
V_16 = F_12 ( V_21 , V_26 -> V_22 ) ;
if ( V_16 -> V_21 )
F_18 ( V_16 -> V_21 ) ;
V_16 -> V_21 = V_29 ;
return 0 ;
}
int F_42 ( struct V_20 * V_21 ,
const char * V_134 ,
char * * V_1 )
{
struct V_27 * V_27 = V_21 -> V_27 ;
struct V_48 * V_26 ;
struct V_48 * V_49 = NULL ;
const char * V_136 ;
const char * V_137 ;
char * V_138 ;
char * V_57 = NULL ;
char * V_56 = NULL ;
char * V_139 ;
int V_140 = 0 ;
int V_6 ;
int V_59 ;
F_40 ( L_45 , 0 ) ;
if ( V_1 )
* V_1 = NULL ;
V_136 = strchr ( V_134 , ':' ) ;
if ( V_136 )
V_6 = V_136 - V_134 ;
else
V_6 = strlen ( V_134 ) ;
do {
V_137 = strchr ( V_134 , ',' ) ;
if ( V_137 &&
( ! V_136 || V_137 < V_136 ) )
V_6 = V_137 - V_134 ;
else if ( V_136 )
V_6 = V_136 - V_134 ;
else
V_6 = strlen ( V_134 ) ;
V_138 = F_4 ( V_6 + 1 ) ;
memcpy ( V_138 , V_134 , V_6 ) ;
V_138 [ V_6 ] = 0 ;
if ( V_137 )
V_137 ++ ;
V_134 = V_137 ;
V_56 = strtok_r ( V_138 , L_19 , & V_139 ) ;
V_57 = strtok_r ( NULL , L_19 , & V_139 ) ;
if ( ! V_56 ) {
F_1 ( V_1 , L_46 ) ;
F_22 ( V_49 ) ;
free ( V_138 ) ;
return - 1 ;
}
V_59 = F_21 ( V_27 , & V_49 , F_43 ( V_56 ) , F_43 ( V_57 ) ) ;
if ( V_59 < 0 ) {
if ( V_57 )
F_1 ( V_1 ,
L_47 ,
V_56 , V_57 ) ;
else
F_1 ( V_1 ,
L_48 ,
V_56 ) ;
F_22 ( V_49 ) ;
free ( V_138 ) ;
return - 1 ;
}
free ( V_138 ) ;
} while ( V_134 );
if ( V_136 )
V_136 ++ ;
for ( V_26 = V_49 ; V_26 ; V_26 = V_26 -> V_52 ) {
V_59 = F_41 ( V_21 , V_26 -> V_26 , V_136 ,
V_1 ) ;
if ( V_59 < 0 )
V_140 = V_59 ;
if ( V_59 >= 0 && V_27 -> V_141 ) {
char * V_142 ;
V_142 = F_44 ( V_21 , V_26 -> V_26 -> V_22 ) ;
printf ( L_49 , V_26 -> V_26 -> V_55 , V_142 ) ;
free ( V_142 ) ;
}
}
F_22 ( V_49 ) ;
if ( V_140 >= 0 && V_27 -> V_141 )
exit ( 0 ) ;
return V_140 ;
}
static void F_45 ( struct V_16 * V_16 )
{
F_18 ( V_16 -> V_21 ) ;
}
int F_46 ( struct V_20 * V_21 ,
int V_19 )
{
struct V_16 * V_16 ;
unsigned long V_6 ;
if ( ! V_21 -> V_25 )
return 0 ;
V_16 = F_11 ( V_21 , V_19 ) ;
if ( ! V_16 )
return 0 ;
F_45 ( V_16 ) ;
V_6 = ( unsigned long ) ( V_21 -> V_24 + V_21 -> V_25 ) -
( unsigned long ) ( V_16 + 1 ) ;
memmove ( V_16 , V_16 + 1 , V_6 ) ;
V_21 -> V_25 -- ;
memset ( & V_21 -> V_24 [ V_21 -> V_25 ] , 0 ,
sizeof( * V_16 ) ) ;
return 1 ;
}
void F_47 ( struct V_20 * V_21 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_21 -> V_25 ; V_7 ++ )
F_45 ( & V_21 -> V_24 [ V_7 ] ) ;
free ( V_21 -> V_24 ) ;
V_21 -> V_25 = 0 ;
V_21 -> V_24 = NULL ;
}
void F_48 ( struct V_20 * V_21 )
{
F_49 ( V_21 -> V_27 ) ;
F_47 ( V_21 ) ;
free ( V_21 ) ;
}
static int F_50 ( struct V_20 * V_21 ,
struct V_20 * V_143 ,
struct V_16 * V_16 )
{
struct V_28 * V_29 ;
struct V_50 * V_26 ;
const char * V_144 ;
const char * V_55 ;
char * V_38 ;
V_144 = V_16 -> V_26 -> system ;
V_55 = V_16 -> V_26 -> V_55 ;
V_26 = F_51 ( V_21 -> V_27 , V_144 , V_55 ) ;
if ( ! V_26 )
return - 1 ;
V_38 = F_52 ( V_143 , V_16 -> V_21 ) ;
if ( ! V_38 )
return - 1 ;
if ( strcmp ( V_38 , L_50 ) == 0 || strcmp ( V_38 , L_51 ) == 0 ) {
V_29 = F_17 () ;
V_29 -> type = V_31 ;
if ( strcmp ( V_38 , L_50 ) == 0 )
V_29 -> boolean . V_43 = 1 ;
else
V_29 -> boolean . V_43 = 0 ;
V_16 = F_12 ( V_21 , V_26 -> V_22 ) ;
V_16 -> V_21 = V_29 ;
free ( V_38 ) ;
return 0 ;
}
F_41 ( V_21 , V_26 , V_38 , NULL ) ;
free ( V_38 ) ;
return 0 ;
}
int F_53 ( struct V_20 * V_145 , struct V_20 * V_143 )
{
int V_59 = 0 ;
int V_7 ;
F_47 ( V_145 ) ;
for ( V_7 = 0 ; V_7 < V_143 -> V_25 ; V_7 ++ ) {
if ( F_50 ( V_145 , V_143 , & V_143 -> V_24 [ V_7 ] ) )
V_59 = - 1 ;
}
return V_59 ;
}
int F_54 ( struct V_20 * V_145 , struct V_20 * V_143 ,
enum V_146 type )
{
struct V_27 * V_147 ;
struct V_27 * V_148 ;
struct V_50 * V_26 ;
struct V_16 * V_16 ;
struct V_28 * V_29 ;
char * V_38 ;
int V_7 ;
V_147 = V_143 -> V_27 ;
V_148 = V_145 -> V_27 ;
if ( ! V_145 -> V_25 || ! V_143 -> V_25 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_145 -> V_25 ; V_7 ++ ) {
V_16 = & V_145 -> V_24 [ V_7 ] ;
V_29 = V_16 -> V_21 ;
if ( V_29 -> type != V_31 )
continue;
if ( ( V_29 -> boolean . V_43 && type == V_149 ) ||
( ! V_29 -> boolean . V_43 && type == V_150 ) )
continue;
V_26 = V_16 -> V_26 ;
if ( V_147 != V_148 ) {
V_26 = F_51 ( V_147 ,
V_26 -> system ,
V_26 -> V_55 ) ;
if ( ! V_26 )
return - 1 ;
}
V_38 = F_44 ( V_143 , V_26 -> V_22 ) ;
if ( ! V_38 )
continue;
if ( strcmp ( V_38 , L_50 ) != 0 && strcmp ( V_38 , L_51 ) != 0 )
F_41 ( V_145 , V_26 , V_38 , NULL ) ;
free ( V_38 ) ;
}
return 0 ;
}
void F_55 ( struct V_20 * V_21 ,
enum V_146 type )
{
struct V_16 * V_16 ;
int V_151 = 0 ;
int * V_152 = NULL ;
int V_7 ;
if ( ! V_21 -> V_25 )
return;
for ( V_7 = 0 ; V_7 < V_21 -> V_25 ; V_7 ++ ) {
V_16 = & V_21 -> V_24 [ V_7 ] ;
if ( V_16 -> V_21 -> type != V_31 )
continue;
switch ( type ) {
case V_149 :
if ( V_16 -> V_21 -> boolean . V_43 )
continue;
case V_150 :
if ( ! V_16 -> V_21 -> boolean . V_43 )
continue;
default:
break;
}
V_152 = realloc ( V_152 , sizeof( * V_152 ) * ( V_151 + 1 ) ) ;
if ( ! V_152 )
F_13 ( L_52 ) ;
V_152 [ V_151 ++ ] = V_16 -> V_19 ;
}
if ( ! V_151 )
return;
for ( V_7 = 0 ; V_7 < V_151 ; V_7 ++ )
F_46 ( V_21 , V_152 [ V_7 ] ) ;
free ( V_152 ) ;
}
int F_56 ( struct V_20 * V_21 ,
int V_19 ,
enum V_146 type )
{
struct V_16 * V_16 ;
if ( ! V_21 -> V_25 )
return 0 ;
V_16 = F_11 ( V_21 , V_19 ) ;
if ( ! V_16 )
return 0 ;
if ( V_16 -> V_21 -> type != V_31 )
return 0 ;
switch ( type ) {
case V_149 :
return ! V_16 -> V_21 -> boolean . V_43 ;
case V_150 :
return V_16 -> V_21 -> boolean . V_43 ;
default:
return 1 ;
}
}
static const char *
F_57 ( struct V_50 * V_26 , struct V_153 * V_154 )
{
const char * V_71 ;
int V_155 ;
V_155 = F_58 ( V_26 -> V_27 , V_154 ) ;
V_71 = F_59 ( V_26 -> V_27 , V_155 ) ;
return V_71 ;
}
static unsigned long long
F_60 ( struct V_50 * V_26 ,
struct V_63 * V_64 , struct V_153 * V_154 )
{
unsigned long long V_39 ;
if ( V_64 == & V_71 ) {
const char * V_55 ;
V_55 = F_57 ( V_26 , V_154 ) ;
return ( unsigned long ) V_55 ;
}
F_61 ( V_64 , V_154 -> V_156 , & V_39 ) ;
if ( ! ( V_64 -> V_157 & V_158 ) )
return V_39 ;
switch ( V_64 -> V_86 ) {
case 1 :
return ( char ) V_39 ;
case 2 :
return ( short ) V_39 ;
case 4 :
return ( int ) V_39 ;
case 8 :
return ( long long ) V_39 ;
}
return V_39 ;
}
static unsigned long long
F_62 ( struct V_50 * V_26 , struct V_28 * V_29 , struct V_153 * V_154 )
{
unsigned long long V_119 , V_120 ;
V_119 = F_63 ( V_26 , V_29 -> exp . V_34 , V_154 ) ;
V_120 = F_63 ( V_26 , V_29 -> exp . V_35 , V_154 ) ;
switch ( V_29 -> exp . type ) {
case V_96 :
return V_119 + V_120 ;
case V_97 :
return V_119 - V_120 ;
case V_98 :
return V_119 * V_120 ;
case V_99 :
return V_119 / V_120 ;
case V_100 :
return V_119 % V_120 ;
case V_101 :
return V_119 >> V_120 ;
case V_102 :
return V_119 << V_120 ;
case V_103 :
return V_119 & V_120 ;
case V_104 :
return V_119 | V_120 ;
case V_105 :
return V_119 ^ V_120 ;
case V_106 :
default:
F_13 ( L_53 ) ;
}
return 0 ;
}
static unsigned long long
F_63 ( struct V_50 * V_26 , struct V_28 * V_29 , struct V_153 * V_154 )
{
switch ( V_29 -> type ) {
case V_72 :
return F_60 ( V_26 , V_29 -> V_64 . V_64 , V_154 ) ;
case V_42 :
if ( V_29 -> V_43 . type != V_68 )
F_13 ( L_54 ) ;
return V_29 -> V_43 . V_39 ;
case V_36 :
return F_62 ( V_26 , V_29 , V_154 ) ;
default:
F_13 ( L_55 ) ;
}
return 0 ;
}
static int F_64 ( struct V_50 * V_26 ,
struct V_28 * V_29 , struct V_153 * V_154 )
{
unsigned long long V_119 , V_120 ;
V_119 = F_63 ( V_26 , V_29 -> V_33 . V_34 , V_154 ) ;
V_120 = F_63 ( V_26 , V_29 -> V_33 . V_35 , V_154 ) ;
switch ( V_29 -> V_33 . type ) {
case V_82 :
return V_119 == V_120 ;
case V_84 :
return V_119 != V_120 ;
case V_109 :
return V_119 > V_120 ;
case V_108 :
return V_119 < V_120 ;
case V_111 :
return V_119 >= V_120 ;
case V_110 :
return V_119 <= V_120 ;
default:
return 0 ;
}
}
static const char * F_65 ( struct V_28 * V_29 , struct V_153 * V_154 )
{
struct V_50 * V_26 ;
struct V_27 * V_27 ;
unsigned long long V_159 ;
const char * V_39 = NULL ;
char V_160 [ 64 ] ;
if ( V_29 -> V_38 . V_64 -> V_157 & V_161 ) {
V_39 = V_154 -> V_156 + V_29 -> V_38 . V_64 -> V_162 ;
if ( * ( V_39 + V_29 -> V_38 . V_64 -> V_86 - 1 ) ) {
memcpy ( V_29 -> V_38 . V_41 , V_39 , V_29 -> V_38 . V_64 -> V_86 ) ;
V_39 = V_29 -> V_38 . V_41 ;
}
} else {
V_26 = V_29 -> V_38 . V_64 -> V_26 ;
V_27 = V_26 -> V_27 ;
V_159 = F_60 ( V_26 , V_29 -> V_38 . V_64 , V_154 ) ;
if ( V_29 -> V_38 . V_64 -> V_157 & ( V_163 | V_164 ) )
V_39 = F_66 ( V_27 , V_159 ) ;
if ( V_39 == NULL ) {
snprintf ( V_160 , 64 , L_56 , V_159 ) ;
V_39 = V_160 ;
}
}
return V_39 ;
}
static int F_67 ( struct V_50 * V_26 ,
struct V_28 * V_29 , struct V_153 * V_154 )
{
const char * V_39 ;
if ( V_29 -> V_38 . V_64 == & V_71 )
V_39 = F_57 ( V_26 , V_154 ) ;
else
V_39 = F_65 ( V_29 , V_154 ) ;
switch ( V_29 -> V_38 . type ) {
case V_83 :
return strcmp ( V_39 , V_29 -> V_38 . V_39 ) == 0 ;
case V_85 :
return strcmp ( V_39 , V_29 -> V_38 . V_39 ) != 0 ;
case V_79 :
return ! regexec ( & V_29 -> V_38 . V_40 , V_39 , 0 , NULL , 0 ) ;
case V_80 :
return regexec ( & V_29 -> V_38 . V_40 , V_39 , 0 , NULL , 0 ) ;
default:
return 0 ;
}
}
static int F_68 ( struct V_50 * V_26 ,
struct V_28 * V_29 , struct V_153 * V_154 )
{
switch ( V_29 -> V_47 . type ) {
case V_92 :
return F_69 ( V_26 , V_29 -> V_47 . V_34 , V_154 ) &&
F_69 ( V_26 , V_29 -> V_47 . V_35 , V_154 ) ;
case V_93 :
return F_69 ( V_26 , V_29 -> V_47 . V_34 , V_154 ) ||
F_69 ( V_26 , V_29 -> V_47 . V_35 , V_154 ) ;
case V_89 :
return ! F_69 ( V_26 , V_29 -> V_47 . V_35 , V_154 ) ;
default:
return 0 ;
}
}
static int F_69 ( struct V_50 * V_26 ,
struct V_28 * V_29 , struct V_153 * V_154 )
{
switch ( V_29 -> type ) {
case V_31 :
return V_29 -> boolean . V_43 ;
case V_46 :
return F_68 ( V_26 , V_29 , V_154 ) ;
case V_32 :
return F_64 ( V_26 , V_29 , V_154 ) ;
case V_37 :
return F_67 ( V_26 , V_29 , V_154 ) ;
case V_36 :
case V_42 :
case V_72 :
return ! ! F_63 ( V_26 , V_29 , V_154 ) ;
default:
F_13 ( L_57 ) ;
return 0 ;
}
}
int F_70 ( struct V_20 * V_21 ,
int V_19 )
{
struct V_16 * V_16 ;
if ( ! V_21 -> V_25 )
return 0 ;
V_16 = F_11 ( V_21 , V_19 ) ;
return V_16 ? 1 : 0 ;
}
int F_71 ( struct V_20 * V_21 ,
struct V_153 * V_154 )
{
struct V_27 * V_27 = V_21 -> V_27 ;
struct V_16 * V_16 ;
int V_19 ;
if ( ! V_21 -> V_25 )
return V_165 ;
V_19 = F_72 ( V_27 , V_154 ) ;
V_16 = F_11 ( V_21 , V_19 ) ;
if ( ! V_16 )
return V_166 ;
return F_69 ( V_16 -> V_26 , V_16 -> V_21 , V_154 ) ?
V_167 : V_168 ;
}
static char * F_73 ( struct V_20 * V_21 , struct V_28 * V_29 )
{
char * V_38 = NULL ;
char * V_34 = NULL ;
char * V_35 = NULL ;
char * V_47 = NULL ;
int V_169 = - 1 ;
int V_170 = - 1 ;
int V_39 ;
int V_6 ;
switch ( V_29 -> V_47 . type ) {
case V_92 :
V_47 = L_14 ;
case V_93 :
if ( ! V_47 )
V_47 = L_15 ;
V_34 = F_52 ( V_21 , V_29 -> V_47 . V_34 ) ;
V_35 = F_52 ( V_21 , V_29 -> V_47 . V_35 ) ;
if ( ! V_34 || ! V_35 )
break;
if ( strcmp ( V_34 , L_50 ) == 0 )
V_169 = 1 ;
else if ( strcmp ( V_34 , L_51 ) == 0 )
V_169 = 0 ;
if ( strcmp ( V_35 , L_50 ) == 0 )
V_170 = 1 ;
else if ( strcmp ( V_35 , L_51 ) == 0 )
V_170 = 0 ;
if ( V_169 >= 0 ) {
if ( ( V_29 -> V_47 . type == V_92 && ! V_169 ) ||
( V_29 -> V_47 . type == V_93 && V_169 ) ) {
V_38 = V_34 ;
V_34 = NULL ;
break;
}
if ( V_170 >= 0 ) {
V_39 = 0 ;
switch ( V_29 -> V_47 . type ) {
case V_92 :
V_39 = V_169 && V_170 ;
break;
case V_93 :
V_39 = V_169 || V_170 ;
break;
default:
break;
}
V_38 = F_4 ( 6 ) ;
if ( V_39 )
strcpy ( V_38 , L_50 ) ;
else
strcpy ( V_38 , L_51 ) ;
break;
}
}
if ( V_170 >= 0 ) {
if ( ( V_29 -> V_47 . type == V_92 && ! V_170 ) ||
( V_29 -> V_47 . type == V_93 && V_170 ) ) {
V_38 = V_35 ;
V_35 = NULL ;
break;
}
V_38 = V_34 ;
V_34 = NULL ;
break;
}
V_6 = strlen ( V_34 ) + strlen ( V_35 ) + strlen ( V_47 ) + 10 ;
V_38 = F_4 ( V_6 ) ;
snprintf ( V_38 , V_6 , L_58 ,
V_34 , V_47 , V_35 ) ;
break;
case V_89 :
V_47 = L_2 ;
V_35 = F_52 ( V_21 , V_29 -> V_47 . V_35 ) ;
if ( ! V_35 )
break;
if ( strcmp ( V_35 , L_50 ) == 0 )
V_170 = 1 ;
else if ( strcmp ( V_35 , L_51 ) == 0 )
V_170 = 0 ;
if ( V_170 >= 0 ) {
V_38 = F_4 ( 6 ) ;
if ( V_170 )
strcpy ( V_38 , L_51 ) ;
else
strcpy ( V_38 , L_50 ) ;
break;
}
V_6 = strlen ( V_35 ) + strlen ( V_47 ) + 3 ;
V_38 = F_4 ( V_6 ) ;
snprintf ( V_38 , V_6 , L_59 , V_47 , V_35 ) ;
break;
default:
break;
}
free ( V_34 ) ;
free ( V_35 ) ;
return V_38 ;
}
static char * F_74 ( struct V_20 * V_21 , struct V_28 * V_29 )
{
char * V_38 ;
V_38 = F_4 ( 30 ) ;
snprintf ( V_38 , 30 , L_60 , V_29 -> V_43 . V_39 ) ;
return V_38 ;
}
static char * F_75 ( struct V_20 * V_21 , struct V_28 * V_29 )
{
return F_24 ( V_29 -> V_64 . V_64 -> V_55 ) ;
}
static char * F_76 ( struct V_20 * V_21 , struct V_28 * V_29 )
{
char * V_171 ;
char * V_172 ;
char * V_47 ;
char * V_38 = NULL ;
int V_6 ;
V_171 = F_52 ( V_21 , V_29 -> exp . V_34 ) ;
V_172 = F_52 ( V_21 , V_29 -> exp . V_35 ) ;
if ( ! V_171 || ! V_172 )
goto V_173;
switch ( V_29 -> exp . type ) {
case V_96 :
V_47 = L_16 ;
break;
case V_97 :
V_47 = L_17 ;
break;
case V_98 :
V_47 = L_18 ;
break;
case V_99 :
V_47 = L_19 ;
break;
case V_100 :
V_47 = L_20 ;
break;
case V_101 :
V_47 = L_21 ;
break;
case V_102 :
V_47 = L_22 ;
break;
case V_103 :
V_47 = L_23 ;
break;
case V_104 :
V_47 = L_24 ;
break;
case V_105 :
V_47 = L_25 ;
break;
default:
F_13 ( L_61 ) ;
}
V_6 = strlen ( V_47 ) + strlen ( V_171 ) + strlen ( V_172 ) + 4 ;
V_38 = F_4 ( V_6 ) ;
snprintf ( V_38 , V_6 , L_62 , V_171 , V_47 , V_172 ) ;
V_173:
free ( V_171 ) ;
free ( V_172 ) ;
return V_38 ;
}
static char * F_77 ( struct V_20 * V_21 , struct V_28 * V_29 )
{
char * V_171 ;
char * V_172 ;
char * V_38 = NULL ;
char * V_47 = NULL ;
int V_6 ;
V_171 = F_52 ( V_21 , V_29 -> V_33 . V_34 ) ;
V_172 = F_52 ( V_21 , V_29 -> V_33 . V_35 ) ;
if ( ! V_171 || ! V_172 )
goto V_173;
switch ( V_29 -> V_33 . type ) {
case V_82 :
V_47 = L_27 ;
case V_84 :
if ( ! V_47 )
V_47 = L_28 ;
case V_109 :
if ( ! V_47 )
V_47 = L_30 ;
case V_108 :
if ( ! V_47 )
V_47 = L_29 ;
case V_111 :
if ( ! V_47 )
V_47 = L_32 ;
case V_110 :
if ( ! V_47 )
V_47 = L_31 ;
V_6 = strlen ( V_171 ) + strlen ( V_47 ) + strlen ( V_172 ) + 4 ;
V_38 = F_4 ( V_6 ) ;
sprintf ( V_38 , L_62 , V_171 , V_47 , V_172 ) ;
break;
default:
break;
}
V_173:
free ( V_171 ) ;
free ( V_172 ) ;
return V_38 ;
}
static char * F_78 ( struct V_20 * V_21 , struct V_28 * V_29 )
{
char * V_38 = NULL ;
char * V_47 = NULL ;
int V_6 ;
switch ( V_29 -> V_38 . type ) {
case V_83 :
V_47 = L_27 ;
case V_85 :
if ( ! V_47 )
V_47 = L_28 ;
case V_79 :
if ( ! V_47 )
V_47 = L_33 ;
case V_80 :
if ( ! V_47 )
V_47 = L_34 ;
V_6 = strlen ( V_29 -> V_38 . V_64 -> V_55 ) + strlen ( V_47 ) +
strlen ( V_29 -> V_38 . V_39 ) + 6 ;
V_38 = F_4 ( V_6 ) ;
snprintf ( V_38 , V_6 , L_63 ,
V_29 -> V_38 . V_64 -> V_55 ,
V_47 , V_29 -> V_38 . V_39 ) ;
break;
default:
break;
}
return V_38 ;
}
static char * F_52 ( struct V_20 * V_21 , struct V_28 * V_29 )
{
char * V_38 ;
switch ( V_29 -> type ) {
case V_31 :
V_38 = F_4 ( 6 ) ;
if ( V_29 -> boolean . V_43 )
strcpy ( V_38 , L_50 ) ;
else
strcpy ( V_38 , L_51 ) ;
return V_38 ;
case V_46 :
return F_73 ( V_21 , V_29 ) ;
case V_32 :
return F_77 ( V_21 , V_29 ) ;
case V_37 :
return F_78 ( V_21 , V_29 ) ;
case V_42 :
return F_74 ( V_21 , V_29 ) ;
case V_72 :
return F_75 ( V_21 , V_29 ) ;
case V_36 :
return F_76 ( V_21 , V_29 ) ;
default:
return NULL ;
}
}
char *
F_44 ( struct V_20 * V_21 , int V_19 )
{
struct V_16 * V_16 ;
if ( ! V_21 -> V_25 )
return NULL ;
V_16 = F_11 ( V_21 , V_19 ) ;
if ( ! V_16 )
return NULL ;
return F_52 ( V_21 , V_16 -> V_21 ) ;
}
int F_79 ( struct V_20 * V_174 , struct V_20 * V_175 )
{
struct V_16 * V_176 ;
struct V_16 * V_177 ;
char * V_178 , * V_179 ;
int V_180 ;
int V_7 ;
if ( V_174 -> V_25 != V_175 -> V_25 )
return 0 ;
if ( ! V_174 -> V_25 && ! V_175 -> V_25 )
return 1 ;
for ( V_7 = 0 ; V_7 < V_174 -> V_25 ; V_7 ++ ) {
V_176 = & V_174 -> V_24 [ V_7 ] ;
V_177 = F_11 ( V_175 , V_176 -> V_19 ) ;
if ( ! V_177 )
break;
if ( V_176 -> V_21 -> type != V_177 -> V_21 -> type )
break;
switch ( V_176 -> V_21 -> type ) {
case V_149 :
case V_150 :
continue;
default:
break;
}
V_178 = F_52 ( V_174 , V_176 -> V_21 ) ;
V_179 = F_52 ( V_175 , V_177 -> V_21 ) ;
if ( V_178 && V_179 )
V_180 = strcmp ( V_178 , V_179 ) != 0 ;
else
V_180 = 1 ;
free ( V_178 ) ;
free ( V_179 ) ;
if ( V_180 )
break;
}
if ( V_7 < V_174 -> V_25 )
return 0 ;
return 1 ;
}
