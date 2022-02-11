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
int F_16 ( const char * V_8 , int V_23 )
{
T_2 * V_9 = NULL ;
char line [ 1024 ] ;
char * V_25 , * V_26 ;
struct V_10 * V_11 ;
int V_40 , V_24 ;
if ( V_8 ) {
V_9 = F_17 ( V_8 ) ;
} else {
struct V_41 * V_42 ;
V_8 = F_6 () ;
V_9 = F_17 ( V_8 ) ;
if ( V_9 )
goto V_43;
F_18 ( 1 ) ;
if ( ! V_44 ) {
if ( V_45 )
F_10 ( V_45 ) ;
return 1 ;
}
F_19 (sym_defconfig_list, prop) {
if ( F_20 ( V_42 -> V_46 . V_47 ) == V_33 ||
V_42 -> V_47 -> type != V_48 )
continue;
V_8 = F_8 ( V_42 -> V_47 -> V_49 . V_11 -> V_8 ) ;
V_9 = F_17 ( V_8 ) ;
if ( V_9 ) {
F_5 ( _ ( L_13 ) ,
V_8 ) ;
goto V_43;
}
}
}
if ( ! V_9 )
return 1 ;
V_43:
V_4 = V_8 ;
V_5 = 0 ;
V_6 = 0 ;
V_50 = 0 ;
V_24 = V_51 << V_23 ;
F_21 (i, sym) {
V_11 -> V_30 |= V_52 ;
V_11 -> V_30 &= ~ ( V_24 | V_53 ) ;
if ( F_22 ( V_11 ) )
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
while ( fgets ( line , sizeof( line ) , V_9 ) ) {
V_5 ++ ;
V_11 = NULL ;
if ( line [ 0 ] == '#' ) {
if ( memcmp ( line + 2 , V_54 , strlen ( V_54 ) ) )
continue;
V_25 = strchr ( line + 2 + strlen ( V_54 ) , ' ' ) ;
if ( ! V_25 )
continue;
* V_25 ++ = 0 ;
if ( strncmp ( V_25 , L_14 , 10 ) )
continue;
if ( V_23 == V_55 ) {
V_11 = F_23 ( line + 2 + strlen ( V_54 ) ) ;
if ( ! V_11 ) {
F_18 ( 1 ) ;
goto V_56;
}
} else {
V_11 = F_9 ( line + 2 + strlen ( V_54 ) , 0 ) ;
if ( V_11 -> type == V_57 )
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
} else if ( memcmp ( line , V_54 , strlen ( V_54 ) ) == 0 ) {
V_25 = strchr ( line + strlen ( V_54 ) , '=' ) ;
if ( ! V_25 )
continue;
* V_25 ++ = 0 ;
V_26 = strchr ( V_25 , '\n' ) ;
if ( V_26 ) {
* V_26 -- = 0 ;
if ( * V_26 == '\r' )
* V_26 = 0 ;
}
if ( V_23 == V_55 ) {
V_11 = F_23 ( line + strlen ( V_54 ) ) ;
if ( ! V_11 ) {
F_18 ( 1 ) ;
goto V_56;
}
} else {
V_11 = F_9 ( line + strlen ( V_54 ) , 0 ) ;
if ( V_11 -> type == V_57 )
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
V_56:
if ( V_11 && F_24 ( V_11 ) ) {
struct V_10 * V_58 = F_25 ( F_26 ( V_11 ) ) ;
switch ( V_11 -> V_23 [ V_23 ] . V_28 ) {
case V_33 :
break;
case V_29 :
if ( V_58 -> V_23 [ V_23 ] . V_28 == V_32 ) {
F_1 ( L_17 , V_11 -> V_8 ) ;
V_58 -> V_30 &= ~ V_24 ;
}
break;
case V_32 :
if ( V_58 -> V_23 [ V_23 ] . V_28 != V_33 )
F_1 ( L_18 , V_11 -> V_8 ) ;
V_58 -> V_23 [ V_23 ] . V_39 = V_11 ;
break;
}
V_58 -> V_23 [ V_23 ] . V_28 = F_27 ( V_58 -> V_23 [ V_23 ] . V_28 , V_11 -> V_23 [ V_23 ] . V_28 ) ;
}
}
fclose ( V_9 ) ;
if ( V_45 )
F_10 ( V_45 ) ;
return 0 ;
}
int F_28 ( const char * V_8 )
{
struct V_10 * V_11 ;
int V_40 ;
F_29 ( 0 ) ;
if ( F_16 ( V_8 , V_55 ) )
return 1 ;
F_21 (i, sym) {
F_10 ( V_11 ) ;
if ( F_22 ( V_11 ) || ( V_11 -> V_30 & V_59 ) )
continue;
if ( F_30 ( V_11 ) && ( V_11 -> V_30 & V_60 ) ) {
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
if ( V_11 -> V_23 [ V_55 ] . V_28 != F_31 ( V_11 ) )
break;
if ( ! F_22 ( V_11 ) )
continue;
default:
if ( ! strcmp ( V_11 -> V_61 . V_39 , V_11 -> V_23 [ V_55 ] . V_39 ) )
continue;
break;
}
} else if ( ! F_30 ( V_11 ) && ! ( V_11 -> V_30 & V_60 ) )
continue;
V_50 ++ ;
}
F_21 (i, sym) {
if ( F_30 ( V_11 ) && ! F_24 ( V_11 ) ) {
if ( V_11 -> V_46 == V_33 && ! V_50 )
V_11 -> V_30 &= ~ V_62 ;
switch ( V_11 -> type ) {
case V_35 :
case V_37 :
case V_38 :
if ( F_32 ( V_11 , V_11 -> V_23 [ V_55 ] . V_39 ) )
break;
V_11 -> V_30 &= ~ ( V_53 | V_62 ) ;
V_50 ++ ;
break;
default:
break;
}
}
}
F_18 ( V_6 || V_50 ) ;
return 0 ;
}
static void
F_33 ( T_2 * V_63 , struct V_10 * V_11 , const char * V_64 , void * V_65 )
{
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
if ( * V_64 == 'n' ) {
bool V_66 = ( V_65 != NULL ) ;
if ( ! V_66 )
fprintf ( V_63 , L_19 ,
V_54 , V_11 -> V_8 ) ;
return;
}
break;
default:
break;
}
fprintf ( V_63 , L_20 , V_54 , V_11 -> V_8 , V_64 ) ;
}
static void
F_34 ( T_2 * V_63 , const char * V_64 , void * V_65 )
{
const char * V_25 = V_64 ;
T_3 V_67 ;
for (; ; ) {
V_67 = strcspn ( V_25 , L_2 ) ;
fprintf ( V_63 , L_21 ) ;
if ( V_67 ) {
fprintf ( V_63 , L_22 ) ;
F_35 ( V_25 , V_67 , 1 , V_63 ) ;
V_25 += V_67 ;
}
fprintf ( V_63 , L_2 ) ;
if ( * V_25 ++ == '\0' )
break;
}
}
static void
F_36 ( T_2 * V_63 , struct V_10 * V_11 , const char * V_64 , void * V_65 )
{
switch ( V_11 -> type ) {
case V_31 :
case V_27 : {
const char * V_68 = L_23 ;
switch ( * V_64 ) {
case 'n' :
break;
case 'm' :
V_68 = L_24 ;
default:
fprintf ( V_63 , L_25 ,
V_54 , V_11 -> V_8 , V_68 ) ;
}
break;
}
case V_38 : {
const char * V_69 = L_23 ;
if ( V_64 [ 0 ] != '0' || ( V_64 [ 1 ] != 'x' && V_64 [ 1 ] != 'X' ) )
V_69 = L_26 ;
fprintf ( V_63 , L_27 ,
V_54 , V_11 -> V_8 , V_69 , V_64 ) ;
break;
}
case V_35 :
case V_37 :
fprintf ( V_63 , L_28 ,
V_54 , V_11 -> V_8 , V_64 ) ;
break;
default:
break;
}
}
static void
F_37 ( T_2 * V_63 , const char * V_64 , void * V_65 )
{
const char * V_25 = V_64 ;
T_3 V_67 ;
fprintf ( V_63 , L_29 ) ;
for (; ; ) {
V_67 = strcspn ( V_25 , L_2 ) ;
fprintf ( V_63 , L_30 ) ;
if ( V_67 ) {
fprintf ( V_63 , L_22 ) ;
F_35 ( V_25 , V_67 , 1 , V_63 ) ;
V_25 += V_67 ;
}
fprintf ( V_63 , L_2 ) ;
if ( * V_25 ++ == '\0' )
break;
}
fprintf ( V_63 , L_31 ) ;
}
static void
F_38 ( T_2 * V_63 , struct V_10 * V_11 , const char * V_64 , void * V_65 )
{
if ( V_11 -> type == V_27 && * V_64 != 'n' )
fprintf ( V_63 , L_32 , V_54 , V_11 -> V_8 , ( char ) toupper ( * V_64 ) ) ;
}
static void F_39 ( T_2 * V_63 , struct V_10 * V_11 ,
struct V_70 * V_71 , void * V_72 )
{
const char * V_73 ;
switch ( V_11 -> type ) {
case V_34 :
case V_57 :
break;
case V_35 :
V_73 = F_11 ( V_11 ) ;
V_73 = F_40 ( V_73 ) ;
V_71 -> V_74 ( V_63 , V_11 , V_73 , V_72 ) ;
free ( ( void * ) V_73 ) ;
break;
default:
V_73 = F_11 ( V_11 ) ;
V_71 -> V_74 ( V_63 , V_11 , V_73 , V_72 ) ;
}
}
static void
F_41 ( T_2 * V_63 , struct V_70 * V_71 , void * V_72 )
{
char V_17 [ 256 ] ;
snprintf ( V_17 , sizeof( V_17 ) ,
L_2
L_33
L_34 ,
V_75 . V_76 -> V_77 ) ;
V_71 -> V_78 ( V_63 , V_17 , V_72 ) ;
}
int F_42 ( const char * V_79 )
{
struct V_10 * V_11 ;
struct V_80 * V_80 ;
T_2 * V_81 ;
V_81 = fopen ( V_79 , L_35 ) ;
if ( ! V_81 )
return 1 ;
F_43 () ;
V_80 = V_75 . V_82 ;
while ( V_80 != NULL )
{
V_11 = V_80 -> V_11 ;
if ( V_11 == NULL ) {
if ( ! F_44 ( V_80 ) )
goto V_83;
} else if ( ! F_22 ( V_11 ) ) {
F_10 ( V_11 ) ;
if ( ! ( V_11 -> V_30 & V_60 ) )
goto V_83;
V_11 -> V_30 &= ~ V_60 ;
if ( ! F_45 ( V_11 ) )
goto V_83;
if ( strcmp ( F_11 ( V_11 ) , F_46 ( V_11 ) ) == 0 )
goto V_83;
if ( F_24 ( V_11 ) ) {
struct V_10 * V_58 ;
struct V_10 * V_84 ;
V_58 = F_25 ( F_26 ( V_11 ) ) ;
V_84 = F_47 ( V_58 ) ;
if ( ! F_48 ( V_58 ) && V_11 == V_84 ) {
if ( ( V_11 -> type == V_31 ) &&
F_31 ( V_11 ) == V_32 )
goto V_83;
}
}
F_39 ( V_81 , V_11 , & V_85 , NULL ) ;
}
V_83:
if ( V_80 -> V_82 != NULL ) {
V_80 = V_80 -> V_82 ;
}
else if ( V_80 -> V_86 != NULL ) {
V_80 = V_80 -> V_86 ;
} else {
while ( ( V_80 = V_80 -> V_87 ) ) {
if ( V_80 -> V_86 != NULL ) {
V_80 = V_80 -> V_86 ;
break;
}
}
}
}
fclose ( V_81 ) ;
return 0 ;
}
int F_49 ( const char * V_8 )
{
T_2 * V_81 ;
struct V_10 * V_11 ;
struct V_80 * V_80 ;
const char * V_88 ;
const char * V_73 ;
char V_89 [ V_19 + 1 ] , V_90 [ V_19 + 1 ] , V_91 [ V_19 + 1 ] ;
char * V_20 ;
V_89 [ 0 ] = 0 ;
if ( V_8 && V_8 [ 0 ] ) {
struct V_16 V_92 ;
char * V_93 ;
if ( ! V_16 ( V_8 , & V_92 ) && F_50 ( V_92 . V_94 ) ) {
strcpy ( V_89 , V_8 ) ;
strcat ( V_89 , L_36 ) ;
V_88 = F_6 () ;
} else if ( ( V_93 = strrchr ( V_8 , '/' ) ) ) {
int V_95 = V_93 - V_8 + 1 ;
memcpy ( V_89 , V_8 , V_95 ) ;
V_89 [ V_95 ] = 0 ;
if ( V_93 [ 1 ] )
V_88 = V_93 + 1 ;
else
V_88 = F_6 () ;
} else
V_88 = V_8 ;
} else
V_88 = F_6 () ;
sprintf ( V_91 , L_37 , V_89 , V_88 ) ;
V_20 = getenv ( L_38 ) ;
if ( ! V_20 || ! * V_20 ) {
sprintf ( V_90 , L_39 , V_89 , ( int ) F_51 () ) ;
V_81 = fopen ( V_90 , L_35 ) ;
} else {
* V_90 = 0 ;
V_81 = fopen ( V_91 , L_35 ) ;
}
if ( ! V_81 )
return 1 ;
F_41 ( V_81 , & V_85 , NULL ) ;
if ( ! F_52 () )
F_43 () ;
V_80 = V_75 . V_82 ;
while ( V_80 ) {
V_11 = V_80 -> V_11 ;
if ( ! V_11 ) {
if ( ! F_44 ( V_80 ) )
goto V_86;
V_73 = F_53 ( V_80 ) ;
fprintf ( V_81 , L_2
L_40
L_41
L_40 , V_73 ) ;
} else if ( ! ( V_11 -> V_30 & V_96 ) ) {
F_10 ( V_11 ) ;
if ( ! ( V_11 -> V_30 & V_60 ) )
goto V_86;
V_11 -> V_30 &= ~ V_60 ;
F_39 ( V_81 , V_11 , & V_85 , NULL ) ;
}
V_86:
if ( V_80 -> V_82 ) {
V_80 = V_80 -> V_82 ;
continue;
}
if ( V_80 -> V_86 )
V_80 = V_80 -> V_86 ;
else while ( ( V_80 = V_80 -> V_87 ) ) {
if ( V_80 -> V_86 ) {
V_80 = V_80 -> V_86 ;
break;
}
}
}
fclose ( V_81 ) ;
if ( * V_90 ) {
strcat ( V_89 , V_88 ) ;
strcat ( V_89 , L_42 ) ;
rename ( V_91 , V_89 ) ;
if ( rename ( V_90 , V_91 ) )
return 1 ;
}
F_5 ( _ ( L_43 ) , V_91 ) ;
F_29 ( 0 ) ;
return 0 ;
}
static int F_54 ( void )
{
const char * V_8 ;
char V_97 [ V_19 + 1 ] ;
char * V_98 , * V_99 , V_100 ;
struct V_10 * V_11 ;
struct V_16 V_101 ;
int V_102 , V_40 , V_103 ;
V_8 = F_7 () ;
F_16 ( V_8 , V_104 ) ;
if ( F_55 ( L_44 ) )
return 1 ;
V_102 = 0 ;
F_21 (i, sym) {
F_10 ( V_11 ) ;
if ( ( V_11 -> V_30 & V_59 ) || ! V_11 -> V_8 )
continue;
if ( V_11 -> V_30 & V_60 ) {
if ( V_11 -> V_30 & V_105 ) {
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
if ( F_31 ( V_11 ) ==
V_11 -> V_23 [ V_104 ] . V_28 )
continue;
break;
case V_35 :
case V_38 :
case V_37 :
if ( ! strcmp ( F_11 ( V_11 ) ,
V_11 -> V_23 [ V_104 ] . V_39 ) )
continue;
break;
default:
break;
}
} else {
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
if ( F_31 ( V_11 ) == V_33 )
continue;
break;
default:
break;
}
}
} else if ( ! ( V_11 -> V_30 & V_105 ) )
continue;
V_98 = V_11 -> V_8 ;
V_99 = V_97 ;
while ( ( V_100 = * V_98 ++ ) ) {
V_100 = tolower ( V_100 ) ;
* V_99 ++ = ( V_100 == '_' ) ? '/' : V_100 ;
}
strcpy ( V_99 , L_45 ) ;
V_103 = F_56 ( V_97 , V_106 | V_107 | V_108 , 0644 ) ;
if ( V_103 == - 1 ) {
if ( V_109 != V_110 ) {
V_102 = 1 ;
break;
}
V_99 = V_97 ;
while ( ( V_99 = strchr ( V_99 , '/' ) ) ) {
* V_99 = 0 ;
if ( V_16 ( V_97 , & V_101 ) && F_57 ( V_97 , 0755 ) ) {
V_102 = 1 ;
goto V_81;
}
* V_99 ++ = '/' ;
}
V_103 = F_56 ( V_97 , V_106 | V_107 | V_108 , 0644 ) ;
if ( V_103 == - 1 ) {
V_102 = 1 ;
break;
}
}
F_58 ( V_103 ) ;
}
V_81:
if ( F_55 ( L_46 ) )
return 1 ;
return V_102 ;
}
int F_59 ( void )
{
struct V_10 * V_11 ;
const char * V_8 ;
T_2 * V_81 , * V_111 , * V_112 ;
int V_40 ;
F_43 () ;
F_60 ( L_47 ) ;
if ( F_54 () )
return 1 ;
V_81 = fopen ( L_48 , L_35 ) ;
if ( ! V_81 )
return 1 ;
V_111 = fopen ( L_49 , L_35 ) ;
if ( ! V_111 ) {
fclose ( V_81 ) ;
return 1 ;
}
V_112 = fopen ( L_50 , L_35 ) ;
if ( ! V_112 ) {
fclose ( V_81 ) ;
fclose ( V_111 ) ;
return 1 ;
}
F_41 ( V_81 , & V_85 , NULL ) ;
F_41 ( V_111 , & V_113 , NULL ) ;
F_41 ( V_112 , & V_114 , NULL ) ;
F_21 (i, sym) {
F_10 ( V_11 ) ;
if ( ! ( V_11 -> V_30 & V_60 ) || ! V_11 -> V_8 )
continue;
F_39 ( V_81 , V_11 , & V_85 , ( void * ) 1 ) ;
F_39 ( V_111 , V_11 , & V_113 , ( void * ) 1 ) ;
F_39 ( V_112 , V_11 , & V_114 , NULL ) ;
}
fclose ( V_81 ) ;
fclose ( V_111 ) ;
fclose ( V_112 ) ;
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
void F_29 ( int V_115 )
{
int V_116 = V_117 ;
V_117 = V_115 ;
if ( V_118 &&
( bool ) V_116 != ( bool ) V_115 )
V_118 () ;
}
void F_18 ( int V_115 )
{
F_29 ( V_115 + V_117 ) ;
}
bool F_52 ( void )
{
return V_117 ;
}
void F_61 ( void (* F_4)( void ) )
{
V_118 = F_4 ;
}
static void F_62 ( struct V_10 * V_119 )
{
struct V_41 * V_42 ;
struct V_10 * V_11 ;
struct V_47 * V_120 ;
int V_121 , V_23 ;
if ( V_119 -> V_61 . V_28 != V_32 )
return;
V_42 = F_26 ( V_119 ) ;
V_121 = 0 ;
F_63 (prop->expr, e, sym)
V_121 ++ ;
V_23 = ( rand () % V_121 ) ;
V_121 = 0 ;
F_63 (prop->expr, e, sym) {
if ( V_23 == V_121 ++ ) {
V_11 -> V_23 [ V_55 ] . V_28 = V_32 ;
V_119 -> V_23 [ V_55 ] . V_39 = V_11 ;
}
else {
V_11 -> V_23 [ V_55 ] . V_28 = V_33 ;
}
}
V_119 -> V_30 |= V_62 ;
V_119 -> V_30 &= ~ ( V_53 ) ;
}
static void F_64 ( struct V_10 * V_119 )
{
struct V_41 * V_42 ;
struct V_10 * V_11 ;
struct V_47 * V_120 ;
V_42 = F_26 ( V_119 ) ;
F_63 (prop->expr, e, sym) {
if ( ! F_30 ( V_11 ) )
V_11 -> V_23 [ V_55 ] . V_28 = V_33 ;
}
V_119 -> V_30 |= V_62 ;
V_119 -> V_30 &= ~ ( V_53 ) ;
}
void F_65 ( enum V_122 V_123 )
{
struct V_10 * V_11 , * V_119 ;
int V_40 , V_121 ;
F_21 (i, sym) {
if ( F_30 ( V_11 ) )
continue;
switch ( F_66 ( V_11 ) ) {
case V_31 :
case V_27 :
switch ( V_123 ) {
case V_124 :
V_11 -> V_23 [ V_55 ] . V_28 = V_32 ;
break;
case V_125 :
V_11 -> V_23 [ V_55 ] . V_28 = V_29 ;
break;
case V_126 :
V_11 -> V_23 [ V_55 ] . V_28 = V_33 ;
break;
case V_127 :
V_121 = F_66 ( V_11 ) == V_27 ? 3 : 2 ;
V_11 -> V_23 [ V_55 ] . V_28 = ( V_111 ) ( rand () % V_121 ) ;
break;
default:
continue;
}
if ( ! ( F_22 ( V_11 ) && V_123 == V_127 ) )
V_11 -> V_30 |= V_62 ;
break;
default:
break;
}
}
F_43 () ;
F_21 (i, csym) {
if ( F_30 ( V_119 ) || ! F_22 ( V_119 ) )
continue;
F_10 ( V_119 ) ;
if ( V_123 == V_127 )
F_62 ( V_119 ) ;
else
F_64 ( V_119 ) ;
}
}
