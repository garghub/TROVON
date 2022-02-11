static void F_1 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
fprintf ( V_3 , L_1 , V_4 , V_5 ) ;
vfprintf ( V_3 , V_1 , V_2 ) ;
fprintf ( V_3 , L_2 ) ;
va_end ( V_2 ) ;
V_6 ++ ;
}
static void F_2 ( const char * V_1 , T_1 V_2 )
{
printf ( L_3 ) ;
vprintf ( V_1 , V_2 ) ;
printf ( L_4 ) ;
}
void F_3 ( void (* F_4) ( const char * V_1 , T_1 V_2 ) )
{
V_7 = F_4 ;
}
static void F_5 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
if ( V_7 )
V_7 ( V_1 , V_2 ) ;
}
const char * F_6 ( void )
{
char * V_8 = getenv ( L_5 ) ;
return V_8 ? V_8 : L_6 ;
}
const char * F_7 ( void )
{
char * V_8 = getenv ( L_7 ) ;
return V_8 ? V_8 : L_8 ;
}
static char * F_8 ( const char * V_9 )
{
struct V_10 * V_11 ;
const char * V_12 ;
static char V_13 [ V_14 ] ;
char * V_15 , V_8 [ V_14 ] ;
V_13 [ 0 ] = 0 ;
V_15 = V_8 ;
while ( ( V_12 = strchr ( V_9 , '$' ) ) ) {
strncat ( V_13 , V_9 , V_12 - V_9 ) ;
V_12 ++ ;
V_15 = V_8 ;
while ( isalnum ( * V_12 ) || * V_12 == '_' )
* V_15 ++ = * V_12 ++ ;
* V_15 = 0 ;
V_11 = F_9 ( V_8 , 0 ) ;
F_10 ( V_11 ) ;
strcat ( V_13 , F_11 ( V_11 ) ) ;
V_9 = V_12 ;
}
strcat ( V_13 , V_9 ) ;
return V_13 ;
}
char * F_12 ( void )
{
struct V_16 V_17 ;
static char V_18 [ V_19 + 1 ] ;
char * V_20 , * V_8 ;
V_8 = F_8 ( V_21 ) ;
V_20 = getenv ( V_22 ) ;
if ( V_20 ) {
sprintf ( V_18 , L_9 , V_20 , V_8 ) ;
if ( ! V_16 ( V_18 , & V_17 ) )
return V_18 ;
}
return V_8 ;
}
static int F_13 ( struct V_10 * V_11 , int V_23 , int V_24 , char * V_25 )
{
char * V_26 ;
switch ( V_11 -> type ) {
case V_27 :
if ( V_25 [ 0 ] == 'm' ) {
V_11 -> V_23 [ V_23 ] . V_28 = V_29 ;
V_11 -> V_30 |= V_24 ;
break;
}
case V_31 :
if ( V_25 [ 0 ] == 'y' ) {
V_11 -> V_23 [ V_23 ] . V_28 = V_32 ;
V_11 -> V_30 |= V_24 ;
break;
}
if ( V_25 [ 0 ] == 'n' ) {
V_11 -> V_23 [ V_23 ] . V_28 = V_33 ;
V_11 -> V_30 |= V_24 ;
break;
}
F_1 ( L_10 , V_25 , V_11 -> V_8 ) ;
return 1 ;
case V_34 :
if ( * V_25 != '"' ) {
for ( V_26 = V_25 ; * V_26 && ! isspace ( * V_26 ) ; V_26 ++ )
;
V_11 -> type = V_35 ;
goto V_36;
}
case V_35 :
if ( * V_25 ++ != '"' )
break;
for ( V_26 = V_25 ; ( V_26 = strpbrk ( V_26 , L_11 ) ) ; V_26 ++ ) {
if ( * V_26 == '"' ) {
* V_26 = 0 ;
break;
}
memmove ( V_26 , V_26 + 1 , strlen ( V_26 ) ) ;
}
if ( ! V_26 ) {
F_1 ( L_12 ) ;
return 1 ;
}
case V_37 :
case V_38 :
V_36:
if ( F_14 ( V_11 , V_25 ) ) {
V_11 -> V_23 [ V_23 ] . V_39 = F_15 ( V_25 ) ;
V_11 -> V_30 |= V_24 ;
} else {
F_1 ( L_10 , V_25 , V_11 -> V_8 ) ;
return 1 ;
}
break;
default:
;
}
return 0 ;
}
static int F_16 ( int V_40 , char * * V_41 , T_2 V_42 , T_2 * V_43 )
{
char * V_44 ;
T_2 V_45 = V_42 + 1 ;
if ( V_45 > * V_43 ) {
V_45 += V_46 - 1 ;
V_45 *= 2 ;
V_44 = realloc ( * V_41 , V_45 ) ;
if ( ! V_44 )
return - 1 ;
* V_41 = V_44 ;
* V_43 = V_45 ;
}
( * V_41 ) [ V_42 ] = V_40 ;
return 0 ;
}
static T_3 F_17 ( char * * V_41 , T_2 * V_43 , T_4 * V_47 )
{
char * line = * V_41 ;
T_2 V_42 = 0 ;
for (; ; ) {
int V_40 = getc ( V_47 ) ;
switch ( V_40 ) {
case '\n' :
if ( F_16 ( V_40 , & line , V_42 , V_43 ) < 0 )
goto V_48;
V_42 ++ ;
case V_49 :
if ( F_16 ( '\0' , & line , V_42 , V_43 ) < 0 )
goto V_48;
* V_41 = line ;
if ( V_42 == 0 )
return - 1 ;
return V_42 ;
default:
if ( F_16 ( V_40 , & line , V_42 , V_43 ) < 0 )
goto V_48;
V_42 ++ ;
}
}
V_48:
line [ V_42 - 1 ] = '\0' ;
* V_41 = line ;
return - 1 ;
}
int F_18 ( const char * V_8 , int V_23 )
{
T_4 * V_9 = NULL ;
char * line = NULL ;
T_2 V_50 = 0 ;
char * V_25 , * V_26 ;
struct V_10 * V_11 ;
int V_51 , V_24 ;
if ( V_8 ) {
V_9 = F_19 ( V_8 ) ;
} else {
struct V_52 * V_53 ;
V_8 = F_6 () ;
V_9 = F_19 ( V_8 ) ;
if ( V_9 )
goto V_54;
F_20 ( 1 ) ;
if ( ! V_55 ) {
if ( V_56 )
F_10 ( V_56 ) ;
return 1 ;
}
F_21 (sym_defconfig_list, prop) {
if ( F_22 ( V_53 -> V_57 . V_58 ) == V_33 ||
V_53 -> V_58 -> type != V_59 )
continue;
V_8 = F_8 ( V_53 -> V_58 -> V_60 . V_11 -> V_8 ) ;
V_9 = F_19 ( V_8 ) ;
if ( V_9 ) {
F_5 ( _ ( L_13 ) ,
V_8 ) ;
goto V_54;
}
}
}
if ( ! V_9 )
return 1 ;
V_54:
V_4 = V_8 ;
V_5 = 0 ;
V_6 = 0 ;
V_61 = 0 ;
V_24 = V_62 << V_23 ;
F_23 (i, sym) {
V_11 -> V_30 |= V_63 ;
V_11 -> V_30 &= ~ ( V_24 | V_64 ) ;
if ( F_24 ( V_11 ) )
V_11 -> V_30 |= V_24 ;
switch ( V_11 -> type ) {
case V_37 :
case V_38 :
case V_35 :
if ( V_11 -> V_23 [ V_23 ] . V_39 )
free ( V_11 -> V_23 [ V_23 ] . V_39 ) ;
default:
V_11 -> V_23 [ V_23 ] . V_39 = NULL ;
V_11 -> V_23 [ V_23 ] . V_28 = V_33 ;
}
}
while ( F_17 ( & line , & V_50 , V_9 ) != - 1 ) {
V_5 ++ ;
V_11 = NULL ;
if ( line [ 0 ] == '#' ) {
if ( memcmp ( line + 2 , V_65 , strlen ( V_65 ) ) )
continue;
V_25 = strchr ( line + 2 + strlen ( V_65 ) , ' ' ) ;
if ( ! V_25 )
continue;
* V_25 ++ = 0 ;
if ( strncmp ( V_25 , L_14 , 10 ) )
continue;
if ( V_23 == V_66 ) {
V_11 = F_25 ( line + 2 + strlen ( V_65 ) ) ;
if ( ! V_11 ) {
F_20 ( 1 ) ;
goto V_67;
}
} else {
V_11 = F_9 ( line + 2 + strlen ( V_65 ) , 0 ) ;
if ( V_11 -> type == V_68 )
V_11 -> type = V_31 ;
}
if ( V_11 -> V_30 & V_24 ) {
F_1 ( L_15 , V_11 -> V_8 ) ;
}
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
V_11 -> V_23 [ V_23 ] . V_28 = V_33 ;
V_11 -> V_30 |= V_24 ;
break;
default:
;
}
} else if ( memcmp ( line , V_65 , strlen ( V_65 ) ) == 0 ) {
V_25 = strchr ( line + strlen ( V_65 ) , '=' ) ;
if ( ! V_25 )
continue;
* V_25 ++ = 0 ;
V_26 = strchr ( V_25 , '\n' ) ;
if ( V_26 ) {
* V_26 -- = 0 ;
if ( * V_26 == '\r' )
* V_26 = 0 ;
}
if ( V_23 == V_66 ) {
V_11 = F_25 ( line + strlen ( V_65 ) ) ;
if ( ! V_11 ) {
F_20 ( 1 ) ;
goto V_67;
}
} else {
V_11 = F_9 ( line + strlen ( V_65 ) , 0 ) ;
if ( V_11 -> type == V_68 )
V_11 -> type = V_34 ;
}
if ( V_11 -> V_30 & V_24 ) {
F_1 ( L_15 , V_11 -> V_8 ) ;
}
if ( F_13 ( V_11 , V_23 , V_24 , V_25 ) )
continue;
} else {
if ( line [ 0 ] != '\r' && line [ 0 ] != '\n' )
F_1 ( L_16 ) ;
continue;
}
V_67:
if ( V_11 && F_26 ( V_11 ) ) {
struct V_10 * V_69 = F_27 ( F_28 ( V_11 ) ) ;
switch ( V_11 -> V_23 [ V_23 ] . V_28 ) {
case V_33 :
break;
case V_29 :
if ( V_69 -> V_23 [ V_23 ] . V_28 == V_32 ) {
F_1 ( L_17 , V_11 -> V_8 ) ;
V_69 -> V_30 &= ~ V_24 ;
}
break;
case V_32 :
if ( V_69 -> V_23 [ V_23 ] . V_28 != V_33 )
F_1 ( L_18 , V_11 -> V_8 ) ;
V_69 -> V_23 [ V_23 ] . V_39 = V_11 ;
break;
}
V_69 -> V_23 [ V_23 ] . V_28 = F_29 ( V_69 -> V_23 [ V_23 ] . V_28 , V_11 -> V_23 [ V_23 ] . V_28 ) ;
}
}
free ( line ) ;
fclose ( V_9 ) ;
if ( V_56 )
F_10 ( V_56 ) ;
return 0 ;
}
int F_30 ( const char * V_8 )
{
struct V_10 * V_11 ;
int V_51 ;
F_31 ( 0 ) ;
if ( F_18 ( V_8 , V_66 ) )
return 1 ;
F_23 (i, sym) {
F_10 ( V_11 ) ;
if ( F_24 ( V_11 ) || ( V_11 -> V_30 & V_70 ) )
continue;
if ( F_32 ( V_11 ) && ( V_11 -> V_30 & V_71 ) ) {
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
if ( V_11 -> V_23 [ V_66 ] . V_28 != F_33 ( V_11 ) )
break;
if ( ! F_24 ( V_11 ) )
continue;
default:
if ( ! strcmp ( V_11 -> V_72 . V_39 , V_11 -> V_23 [ V_66 ] . V_39 ) )
continue;
break;
}
} else if ( ! F_32 ( V_11 ) && ! ( V_11 -> V_30 & V_71 ) )
continue;
V_61 ++ ;
}
F_23 (i, sym) {
if ( F_32 ( V_11 ) && ! F_26 ( V_11 ) ) {
if ( V_11 -> V_57 == V_33 && ! V_61 )
V_11 -> V_30 &= ~ V_73 ;
switch ( V_11 -> type ) {
case V_35 :
case V_37 :
case V_38 :
if ( F_34 ( V_11 , V_11 -> V_23 [ V_66 ] . V_39 ) )
break;
V_11 -> V_30 &= ~ ( V_64 | V_73 ) ;
V_61 ++ ;
break;
default:
break;
}
}
}
F_20 ( V_6 || V_61 ) ;
return 0 ;
}
static void
F_35 ( T_4 * V_74 , struct V_10 * V_11 , const char * V_75 , void * V_76 )
{
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
if ( * V_75 == 'n' ) {
bool V_77 = ( V_76 != NULL ) ;
if ( ! V_77 )
fprintf ( V_74 , L_19 ,
V_65 , V_11 -> V_8 ) ;
return;
}
break;
default:
break;
}
fprintf ( V_74 , L_20 , V_65 , V_11 -> V_8 , V_75 ) ;
}
static void
F_36 ( T_4 * V_74 , const char * V_75 , void * V_76 )
{
const char * V_25 = V_75 ;
T_2 V_78 ;
for (; ; ) {
V_78 = strcspn ( V_25 , L_2 ) ;
fprintf ( V_74 , L_21 ) ;
if ( V_78 ) {
fprintf ( V_74 , L_22 ) ;
F_37 ( V_25 , V_78 , 1 , V_74 ) ;
V_25 += V_78 ;
}
fprintf ( V_74 , L_2 ) ;
if ( * V_25 ++ == '\0' )
break;
}
}
static void
F_38 ( T_4 * V_74 , struct V_10 * V_11 , const char * V_75 , void * V_76 )
{
switch ( V_11 -> type ) {
case V_31 :
case V_27 : {
const char * V_79 = L_23 ;
switch ( * V_75 ) {
case 'n' :
break;
case 'm' :
V_79 = L_24 ;
default:
fprintf ( V_74 , L_25 ,
V_65 , V_11 -> V_8 , V_79 ) ;
}
break;
}
case V_38 : {
const char * V_80 = L_23 ;
if ( V_75 [ 0 ] != '0' || ( V_75 [ 1 ] != 'x' && V_75 [ 1 ] != 'X' ) )
V_80 = L_26 ;
fprintf ( V_74 , L_27 ,
V_65 , V_11 -> V_8 , V_80 , V_75 ) ;
break;
}
case V_35 :
case V_37 :
fprintf ( V_74 , L_28 ,
V_65 , V_11 -> V_8 , V_75 ) ;
break;
default:
break;
}
}
static void
F_39 ( T_4 * V_74 , const char * V_75 , void * V_76 )
{
const char * V_25 = V_75 ;
T_2 V_78 ;
fprintf ( V_74 , L_29 ) ;
for (; ; ) {
V_78 = strcspn ( V_25 , L_2 ) ;
fprintf ( V_74 , L_30 ) ;
if ( V_78 ) {
fprintf ( V_74 , L_22 ) ;
F_37 ( V_25 , V_78 , 1 , V_74 ) ;
V_25 += V_78 ;
}
fprintf ( V_74 , L_2 ) ;
if ( * V_25 ++ == '\0' )
break;
}
fprintf ( V_74 , L_31 ) ;
}
static void
F_40 ( T_4 * V_74 , struct V_10 * V_11 , const char * V_75 , void * V_76 )
{
if ( V_11 -> type == V_27 && * V_75 != 'n' )
fprintf ( V_74 , L_32 , V_65 , V_11 -> V_8 , ( char ) toupper ( * V_75 ) ) ;
}
static void F_41 ( T_4 * V_74 , struct V_10 * V_11 ,
struct V_81 * V_82 , void * V_83 )
{
const char * V_84 ;
switch ( V_11 -> type ) {
case V_34 :
case V_68 :
break;
case V_35 :
V_84 = F_11 ( V_11 ) ;
V_84 = F_42 ( V_84 ) ;
V_82 -> V_85 ( V_74 , V_11 , V_84 , V_83 ) ;
free ( ( void * ) V_84 ) ;
break;
default:
V_84 = F_11 ( V_11 ) ;
V_82 -> V_85 ( V_74 , V_11 , V_84 , V_83 ) ;
}
}
static void
F_43 ( T_4 * V_74 , struct V_81 * V_82 , void * V_83 )
{
char V_17 [ 256 ] ;
snprintf ( V_17 , sizeof( V_17 ) ,
L_2
L_33
L_34 ,
V_86 . V_87 -> V_88 ) ;
V_82 -> V_89 ( V_74 , V_17 , V_83 ) ;
}
int F_44 ( const char * V_90 )
{
struct V_10 * V_11 ;
struct V_91 * V_91 ;
T_4 * V_92 ;
V_92 = fopen ( V_90 , L_35 ) ;
if ( ! V_92 )
return 1 ;
F_45 () ;
V_91 = V_86 . V_93 ;
while ( V_91 != NULL )
{
V_11 = V_91 -> V_11 ;
if ( V_11 == NULL ) {
if ( ! F_46 ( V_91 ) )
goto V_94;
} else if ( ! F_24 ( V_11 ) ) {
F_10 ( V_11 ) ;
if ( ! ( V_11 -> V_30 & V_71 ) )
goto V_94;
V_11 -> V_30 &= ~ V_71 ;
if ( ! F_47 ( V_11 ) )
goto V_94;
if ( strcmp ( F_11 ( V_11 ) , F_48 ( V_11 ) ) == 0 )
goto V_94;
if ( F_26 ( V_11 ) ) {
struct V_10 * V_69 ;
struct V_10 * V_95 ;
V_69 = F_27 ( F_28 ( V_11 ) ) ;
V_95 = F_49 ( V_69 ) ;
if ( ! F_50 ( V_69 ) && V_11 == V_95 ) {
if ( ( V_11 -> type == V_31 ) &&
F_33 ( V_11 ) == V_32 )
goto V_94;
}
}
F_41 ( V_92 , V_11 , & V_96 , NULL ) ;
}
V_94:
if ( V_91 -> V_93 != NULL ) {
V_91 = V_91 -> V_93 ;
}
else if ( V_91 -> V_97 != NULL ) {
V_91 = V_91 -> V_97 ;
} else {
while ( ( V_91 = V_91 -> V_98 ) ) {
if ( V_91 -> V_97 != NULL ) {
V_91 = V_91 -> V_97 ;
break;
}
}
}
}
fclose ( V_92 ) ;
return 0 ;
}
int F_51 ( const char * V_8 )
{
T_4 * V_92 ;
struct V_10 * V_11 ;
struct V_91 * V_91 ;
const char * V_99 ;
const char * V_84 ;
char V_100 [ V_19 + 1 ] , V_101 [ V_19 + 1 ] , V_102 [ V_19 + 1 ] ;
char * V_20 ;
V_100 [ 0 ] = 0 ;
if ( V_8 && V_8 [ 0 ] ) {
struct V_16 V_103 ;
char * V_104 ;
if ( ! V_16 ( V_8 , & V_103 ) && F_52 ( V_103 . V_105 ) ) {
strcpy ( V_100 , V_8 ) ;
strcat ( V_100 , L_36 ) ;
V_99 = F_6 () ;
} else if ( ( V_104 = strrchr ( V_8 , '/' ) ) ) {
int V_106 = V_104 - V_8 + 1 ;
memcpy ( V_100 , V_8 , V_106 ) ;
V_100 [ V_106 ] = 0 ;
if ( V_104 [ 1 ] )
V_99 = V_104 + 1 ;
else
V_99 = F_6 () ;
} else
V_99 = V_8 ;
} else
V_99 = F_6 () ;
sprintf ( V_102 , L_37 , V_100 , V_99 ) ;
V_20 = getenv ( L_38 ) ;
if ( ! V_20 || ! * V_20 ) {
sprintf ( V_101 , L_39 , V_100 , ( int ) F_53 () ) ;
V_92 = fopen ( V_101 , L_35 ) ;
} else {
* V_101 = 0 ;
V_92 = fopen ( V_102 , L_35 ) ;
}
if ( ! V_92 )
return 1 ;
F_43 ( V_92 , & V_96 , NULL ) ;
if ( ! F_54 () )
F_45 () ;
V_91 = V_86 . V_93 ;
while ( V_91 ) {
V_11 = V_91 -> V_11 ;
if ( ! V_11 ) {
if ( ! F_46 ( V_91 ) )
goto V_97;
V_84 = F_55 ( V_91 ) ;
fprintf ( V_92 , L_2
L_40
L_41
L_40 , V_84 ) ;
} else if ( ! ( V_11 -> V_30 & V_107 ) ) {
F_10 ( V_11 ) ;
if ( ! ( V_11 -> V_30 & V_71 ) )
goto V_97;
V_11 -> V_30 &= ~ V_71 ;
F_41 ( V_92 , V_11 , & V_96 , NULL ) ;
}
V_97:
if ( V_91 -> V_93 ) {
V_91 = V_91 -> V_93 ;
continue;
}
if ( V_91 -> V_97 )
V_91 = V_91 -> V_97 ;
else while ( ( V_91 = V_91 -> V_98 ) ) {
if ( V_91 -> V_97 ) {
V_91 = V_91 -> V_97 ;
break;
}
}
}
fclose ( V_92 ) ;
if ( * V_101 ) {
strcat ( V_100 , V_99 ) ;
strcat ( V_100 , L_42 ) ;
rename ( V_102 , V_100 ) ;
if ( rename ( V_101 , V_102 ) )
return 1 ;
}
F_5 ( _ ( L_43 ) , V_102 ) ;
F_31 ( 0 ) ;
return 0 ;
}
static int F_56 ( void )
{
const char * V_8 ;
char V_108 [ V_19 + 1 ] ;
char * V_109 , * V_110 , V_40 ;
struct V_10 * V_11 ;
struct V_16 V_111 ;
int V_112 , V_51 , V_113 ;
V_8 = F_7 () ;
F_18 ( V_8 , V_114 ) ;
if ( F_57 ( L_44 ) )
return 1 ;
V_112 = 0 ;
F_23 (i, sym) {
F_10 ( V_11 ) ;
if ( ( V_11 -> V_30 & V_70 ) || ! V_11 -> V_8 )
continue;
if ( V_11 -> V_30 & V_71 ) {
if ( V_11 -> V_30 & V_115 ) {
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
if ( F_33 ( V_11 ) ==
V_11 -> V_23 [ V_114 ] . V_28 )
continue;
break;
case V_35 :
case V_38 :
case V_37 :
if ( ! strcmp ( F_11 ( V_11 ) ,
V_11 -> V_23 [ V_114 ] . V_39 ) )
continue;
break;
default:
break;
}
} else {
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
if ( F_33 ( V_11 ) == V_33 )
continue;
break;
default:
break;
}
}
} else if ( ! ( V_11 -> V_30 & V_115 ) )
continue;
V_109 = V_11 -> V_8 ;
V_110 = V_108 ;
while ( ( V_40 = * V_109 ++ ) ) {
V_40 = tolower ( V_40 ) ;
* V_110 ++ = ( V_40 == '_' ) ? '/' : V_40 ;
}
strcpy ( V_110 , L_45 ) ;
V_113 = F_58 ( V_108 , V_116 | V_117 | V_118 , 0644 ) ;
if ( V_113 == - 1 ) {
if ( V_119 != V_120 ) {
V_112 = 1 ;
break;
}
V_110 = V_108 ;
while ( ( V_110 = strchr ( V_110 , '/' ) ) ) {
* V_110 = 0 ;
if ( V_16 ( V_108 , & V_111 ) && F_59 ( V_108 , 0755 ) ) {
V_112 = 1 ;
goto V_92;
}
* V_110 ++ = '/' ;
}
V_113 = F_58 ( V_108 , V_116 | V_117 | V_118 , 0644 ) ;
if ( V_113 == - 1 ) {
V_112 = 1 ;
break;
}
}
F_60 ( V_113 ) ;
}
V_92:
if ( F_57 ( L_46 ) )
return 1 ;
return V_112 ;
}
int F_61 ( void )
{
struct V_10 * V_11 ;
const char * V_8 ;
T_4 * V_92 , * V_121 , * V_122 ;
int V_51 ;
F_45 () ;
F_62 ( L_47 ) ;
if ( F_56 () )
return 1 ;
V_92 = fopen ( L_48 , L_35 ) ;
if ( ! V_92 )
return 1 ;
V_121 = fopen ( L_49 , L_35 ) ;
if ( ! V_121 ) {
fclose ( V_92 ) ;
return 1 ;
}
V_122 = fopen ( L_50 , L_35 ) ;
if ( ! V_122 ) {
fclose ( V_92 ) ;
fclose ( V_121 ) ;
return 1 ;
}
F_43 ( V_92 , & V_96 , NULL ) ;
F_43 ( V_121 , & V_123 , NULL ) ;
F_43 ( V_122 , & V_124 , NULL ) ;
F_23 (i, sym) {
F_10 ( V_11 ) ;
if ( ! ( V_11 -> V_30 & V_71 ) || ! V_11 -> V_8 )
continue;
F_41 ( V_92 , V_11 , & V_96 , ( void * ) 1 ) ;
F_41 ( V_121 , V_11 , & V_123 , ( void * ) 1 ) ;
F_41 ( V_122 , V_11 , & V_124 , NULL ) ;
}
fclose ( V_92 ) ;
fclose ( V_121 ) ;
fclose ( V_122 ) ;
V_8 = getenv ( L_51 ) ;
if ( ! V_8 )
V_8 = L_52 ;
if ( rename ( L_50 , V_8 ) )
return 1 ;
V_8 = getenv ( L_53 ) ;
if ( ! V_8 )
V_8 = L_54 ;
if ( rename ( L_49 , V_8 ) )
return 1 ;
V_8 = F_7 () ;
if ( rename ( L_48 , V_8 ) )
return 1 ;
return 0 ;
}
void F_31 ( int V_125 )
{
int V_126 = V_127 ;
V_127 = V_125 ;
if ( V_128 &&
( bool ) V_126 != ( bool ) V_125 )
V_128 () ;
}
void F_20 ( int V_125 )
{
F_31 ( V_125 + V_127 ) ;
}
bool F_54 ( void )
{
return V_127 ;
}
void F_63 ( void (* F_4)( void ) )
{
V_128 = F_4 ;
}
static void F_64 ( struct V_10 * V_129 )
{
struct V_52 * V_53 ;
struct V_10 * V_11 ;
struct V_58 * V_130 ;
int V_131 , V_23 ;
if ( V_129 -> V_72 . V_28 != V_32 )
return;
V_53 = F_28 ( V_129 ) ;
V_131 = 0 ;
F_65 (prop->expr, e, sym)
V_131 ++ ;
V_23 = ( rand () % V_131 ) ;
V_131 = 0 ;
F_65 (prop->expr, e, sym) {
if ( V_23 == V_131 ++ ) {
V_11 -> V_23 [ V_66 ] . V_28 = V_32 ;
V_129 -> V_23 [ V_66 ] . V_39 = V_11 ;
}
else {
V_11 -> V_23 [ V_66 ] . V_28 = V_33 ;
}
}
V_129 -> V_30 |= V_73 ;
V_129 -> V_30 &= ~ ( V_64 ) ;
}
static void F_66 ( struct V_10 * V_129 )
{
struct V_52 * V_53 ;
struct V_10 * V_11 ;
struct V_58 * V_130 ;
V_53 = F_28 ( V_129 ) ;
F_65 (prop->expr, e, sym) {
if ( ! F_32 ( V_11 ) )
V_11 -> V_23 [ V_66 ] . V_28 = V_33 ;
}
V_129 -> V_30 |= V_73 ;
V_129 -> V_30 &= ~ ( V_64 ) ;
}
void F_67 ( enum V_132 V_133 )
{
struct V_10 * V_11 , * V_129 ;
int V_51 , V_131 ;
F_23 (i, sym) {
if ( F_32 ( V_11 ) )
continue;
switch ( F_68 ( V_11 ) ) {
case V_31 :
case V_27 :
switch ( V_133 ) {
case V_134 :
V_11 -> V_23 [ V_66 ] . V_28 = V_32 ;
break;
case V_135 :
V_11 -> V_23 [ V_66 ] . V_28 = V_29 ;
break;
case V_136 :
V_11 -> V_23 [ V_66 ] . V_28 = V_33 ;
break;
case V_137 :
V_131 = F_68 ( V_11 ) == V_27 ? 3 : 2 ;
V_11 -> V_23 [ V_66 ] . V_28 = ( V_121 ) ( rand () % V_131 ) ;
break;
default:
continue;
}
if ( ! ( F_24 ( V_11 ) && V_133 == V_137 ) )
V_11 -> V_30 |= V_73 ;
break;
default:
break;
}
}
F_45 () ;
F_23 (i, csym) {
if ( F_32 ( V_129 ) || ! F_24 ( V_129 ) )
continue;
F_10 ( V_129 ) ;
if ( V_133 == V_137 )
F_64 ( V_129 ) ;
else
F_66 ( V_129 ) ;
}
}
