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
struct V_10 * V_11 , * V_59 ;
struct V_41 * V_42 ;
struct V_47 * V_60 ;
int V_40 , V_30 ;
F_29 ( 0 ) ;
if ( F_16 ( V_8 , V_55 ) )
return 1 ;
F_21 (i, sym) {
F_10 ( V_11 ) ;
if ( F_22 ( V_11 ) || ( V_11 -> V_30 & V_61 ) )
goto V_62;
if ( F_30 ( V_11 ) && ( V_11 -> V_30 & V_63 ) ) {
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
if ( V_11 -> V_23 [ V_55 ] . V_28 != F_31 ( V_11 ) )
break;
if ( ! F_22 ( V_11 ) )
goto V_62;
default:
if ( ! strcmp ( V_11 -> V_64 . V_39 , V_11 -> V_23 [ V_55 ] . V_39 ) )
goto V_62;
break;
}
} else if ( ! F_30 ( V_11 ) && ! ( V_11 -> V_30 & V_63 ) )
goto V_62;
V_50 ++ ;
V_62:
if ( ! F_22 ( V_11 ) )
continue;
V_42 = F_26 ( V_11 ) ;
V_30 = V_11 -> V_30 ;
F_32 (prop->expr, e, choice_sym)
if ( V_59 -> V_46 != V_33 )
V_30 &= V_59 -> V_30 ;
V_11 -> V_30 &= V_30 | ~ V_65 ;
}
F_21 (i, sym) {
if ( F_30 ( V_11 ) && ! F_24 ( V_11 ) ) {
if ( V_11 -> V_46 == V_33 && ! V_50 )
V_11 -> V_30 &= ~ V_65 ;
switch ( V_11 -> type ) {
case V_35 :
case V_37 :
case V_38 :
if ( F_33 ( V_11 , V_11 -> V_23 [ V_55 ] . V_39 ) )
break;
V_11 -> V_30 &= ~ ( V_53 | V_65 ) ;
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
F_34 ( T_2 * V_66 , struct V_10 * V_11 , const char * V_67 , void * V_68 )
{
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
if ( * V_67 == 'n' ) {
bool V_69 = ( V_68 != NULL ) ;
if ( ! V_69 )
fprintf ( V_66 , L_19 ,
V_54 , V_11 -> V_8 ) ;
return;
}
break;
default:
break;
}
fprintf ( V_66 , L_20 , V_54 , V_11 -> V_8 , V_67 ) ;
}
static void
F_35 ( T_2 * V_66 , const char * V_67 , void * V_68 )
{
const char * V_25 = V_67 ;
T_3 V_70 ;
for (; ; ) {
V_70 = strcspn ( V_25 , L_2 ) ;
fprintf ( V_66 , L_21 ) ;
if ( V_70 ) {
fprintf ( V_66 , L_22 ) ;
fwrite ( V_25 , V_70 , 1 , V_66 ) ;
V_25 += V_70 ;
}
fprintf ( V_66 , L_2 ) ;
if ( * V_25 ++ == '\0' )
break;
}
}
static void
F_36 ( T_2 * V_66 , struct V_10 * V_11 , const char * V_67 , void * V_68 )
{
switch ( V_11 -> type ) {
case V_31 :
case V_27 : {
const char * V_71 = L_23 ;
switch ( * V_67 ) {
case 'n' :
break;
case 'm' :
V_71 = L_24 ;
default:
fprintf ( V_66 , L_25 ,
V_54 , V_11 -> V_8 , V_71 ) ;
}
break;
}
case V_38 : {
const char * V_72 = L_23 ;
if ( V_67 [ 0 ] != '0' || ( V_67 [ 1 ] != 'x' && V_67 [ 1 ] != 'X' ) )
V_72 = L_26 ;
fprintf ( V_66 , L_27 ,
V_54 , V_11 -> V_8 , V_72 , V_67 ) ;
break;
}
case V_35 :
case V_37 :
fprintf ( V_66 , L_28 ,
V_54 , V_11 -> V_8 , V_67 ) ;
break;
default:
break;
}
}
static void
F_37 ( T_2 * V_66 , const char * V_67 , void * V_68 )
{
const char * V_25 = V_67 ;
T_3 V_70 ;
fprintf ( V_66 , L_29 ) ;
for (; ; ) {
V_70 = strcspn ( V_25 , L_2 ) ;
fprintf ( V_66 , L_30 ) ;
if ( V_70 ) {
fprintf ( V_66 , L_22 ) ;
fwrite ( V_25 , V_70 , 1 , V_66 ) ;
V_25 += V_70 ;
}
fprintf ( V_66 , L_2 ) ;
if ( * V_25 ++ == '\0' )
break;
}
fprintf ( V_66 , L_31 ) ;
}
static void
F_38 ( T_2 * V_66 , struct V_10 * V_11 , const char * V_67 , void * V_68 )
{
switch ( V_11 -> type ) {
case V_31 :
case V_27 : {
fprintf ( V_66 , L_32 V_54 L_33 ,
V_11 -> V_8 , ( * V_67 == 'y' ) ) ;
fprintf ( V_66 , L_32 V_54 L_34 ,
V_11 -> V_8 , ( * V_67 == 'm' ) ) ;
break;
}
default:
break;
}
}
static void
F_39 ( T_2 * V_66 , struct V_10 * V_11 , const char * V_67 , void * V_68 )
{
if ( V_11 -> type == V_27 && * V_67 != 'n' )
fprintf ( V_66 , L_35 , V_54 , V_11 -> V_8 , ( char ) toupper ( * V_67 ) ) ;
}
static void F_40 ( T_2 * V_66 , struct V_10 * V_11 ,
struct V_73 * V_74 , void * V_75 )
{
const char * V_76 ;
switch ( V_11 -> type ) {
case V_34 :
case V_57 :
break;
case V_35 :
V_76 = F_11 ( V_11 ) ;
V_76 = F_41 ( V_76 ) ;
V_74 -> V_77 ( V_66 , V_11 , V_76 , V_75 ) ;
free ( ( void * ) V_76 ) ;
break;
default:
V_76 = F_11 ( V_11 ) ;
V_74 -> V_77 ( V_66 , V_11 , V_76 , V_75 ) ;
}
}
static void
F_42 ( T_2 * V_66 , struct V_73 * V_74 , void * V_75 )
{
char V_17 [ 256 ] ;
snprintf ( V_17 , sizeof( V_17 ) ,
L_2
L_36
L_37 ,
V_78 . V_79 -> V_80 ) ;
V_74 -> V_81 ( V_66 , V_17 , V_75 ) ;
}
int F_43 ( const char * V_82 )
{
struct V_10 * V_11 ;
struct V_83 * V_83 ;
T_2 * V_84 ;
V_84 = fopen ( V_82 , L_38 ) ;
if ( ! V_84 )
return 1 ;
F_44 () ;
V_83 = V_78 . V_85 ;
while ( V_83 != NULL )
{
V_11 = V_83 -> V_11 ;
if ( V_11 == NULL ) {
if ( ! F_45 ( V_83 ) )
goto V_86;
} else if ( ! F_22 ( V_11 ) ) {
F_10 ( V_11 ) ;
if ( ! ( V_11 -> V_30 & V_63 ) )
goto V_86;
V_11 -> V_30 &= ~ V_63 ;
if ( ! F_46 ( V_11 ) )
goto V_86;
if ( strcmp ( F_11 ( V_11 ) , F_47 ( V_11 ) ) == 0 )
goto V_86;
if ( F_24 ( V_11 ) ) {
struct V_10 * V_58 ;
struct V_10 * V_87 ;
V_58 = F_25 ( F_26 ( V_11 ) ) ;
V_87 = F_48 ( V_58 ) ;
if ( ! F_49 ( V_58 ) && V_11 == V_87 ) {
if ( ( V_11 -> type == V_31 ) &&
F_31 ( V_11 ) == V_32 )
goto V_86;
}
}
F_40 ( V_84 , V_11 , & V_88 , NULL ) ;
}
V_86:
if ( V_83 -> V_85 != NULL ) {
V_83 = V_83 -> V_85 ;
}
else if ( V_83 -> V_89 != NULL ) {
V_83 = V_83 -> V_89 ;
} else {
while ( ( V_83 = V_83 -> V_90 ) ) {
if ( V_83 -> V_89 != NULL ) {
V_83 = V_83 -> V_89 ;
break;
}
}
}
}
fclose ( V_84 ) ;
return 0 ;
}
int F_50 ( const char * V_8 )
{
T_2 * V_84 ;
struct V_10 * V_11 ;
struct V_83 * V_83 ;
const char * V_91 ;
const char * V_76 ;
char V_92 [ V_19 + 1 ] , V_93 [ V_19 + 1 ] , V_94 [ V_19 + 1 ] ;
char * V_20 ;
V_92 [ 0 ] = 0 ;
if ( V_8 && V_8 [ 0 ] ) {
struct V_16 V_95 ;
char * V_96 ;
if ( ! V_16 ( V_8 , & V_95 ) && F_51 ( V_95 . V_97 ) ) {
strcpy ( V_92 , V_8 ) ;
strcat ( V_92 , L_39 ) ;
V_91 = F_6 () ;
} else if ( ( V_96 = strrchr ( V_8 , '/' ) ) ) {
int V_98 = V_96 - V_8 + 1 ;
memcpy ( V_92 , V_8 , V_98 ) ;
V_92 [ V_98 ] = 0 ;
if ( V_96 [ 1 ] )
V_91 = V_96 + 1 ;
else
V_91 = F_6 () ;
} else
V_91 = V_8 ;
} else
V_91 = F_6 () ;
sprintf ( V_94 , L_40 , V_92 , V_91 ) ;
V_20 = getenv ( L_41 ) ;
if ( ! V_20 || ! * V_20 ) {
sprintf ( V_93 , L_42 , V_92 , ( int ) F_52 () ) ;
V_84 = fopen ( V_93 , L_38 ) ;
} else {
* V_93 = 0 ;
V_84 = fopen ( V_94 , L_38 ) ;
}
if ( ! V_84 )
return 1 ;
F_42 ( V_84 , & V_88 , NULL ) ;
if ( ! F_53 () )
F_44 () ;
V_83 = V_78 . V_85 ;
while ( V_83 ) {
V_11 = V_83 -> V_11 ;
if ( ! V_11 ) {
if ( ! F_45 ( V_83 ) )
goto V_89;
V_76 = F_54 ( V_83 ) ;
fprintf ( V_84 , L_2
L_43
L_44
L_43 , V_76 ) ;
} else if ( ! ( V_11 -> V_30 & V_99 ) ) {
F_10 ( V_11 ) ;
if ( ! ( V_11 -> V_30 & V_63 ) )
goto V_89;
V_11 -> V_30 &= ~ V_63 ;
F_40 ( V_84 , V_11 , & V_88 , NULL ) ;
}
V_89:
if ( V_83 -> V_85 ) {
V_83 = V_83 -> V_85 ;
continue;
}
if ( V_83 -> V_89 )
V_83 = V_83 -> V_89 ;
else while ( ( V_83 = V_83 -> V_90 ) ) {
if ( V_83 -> V_89 ) {
V_83 = V_83 -> V_89 ;
break;
}
}
}
fclose ( V_84 ) ;
if ( * V_93 ) {
strcat ( V_92 , V_91 ) ;
strcat ( V_92 , L_45 ) ;
rename ( V_94 , V_92 ) ;
if ( rename ( V_93 , V_94 ) )
return 1 ;
}
F_5 ( _ ( L_46 ) , V_94 ) ;
F_29 ( 0 ) ;
return 0 ;
}
static int F_55 ( void )
{
const char * V_8 ;
char V_100 [ V_19 + 1 ] ;
char * V_101 , * V_102 , V_103 ;
struct V_10 * V_11 ;
struct V_16 V_104 ;
int V_105 , V_40 , V_106 ;
V_8 = F_7 () ;
F_16 ( V_8 , V_107 ) ;
if ( F_56 ( L_47 ) )
return 1 ;
V_105 = 0 ;
F_21 (i, sym) {
F_10 ( V_11 ) ;
if ( ( V_11 -> V_30 & V_61 ) || ! V_11 -> V_8 )
continue;
if ( V_11 -> V_30 & V_63 ) {
if ( V_11 -> V_30 & V_108 ) {
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
if ( F_31 ( V_11 ) ==
V_11 -> V_23 [ V_107 ] . V_28 )
continue;
break;
case V_35 :
case V_38 :
case V_37 :
if ( ! strcmp ( F_11 ( V_11 ) ,
V_11 -> V_23 [ V_107 ] . V_39 ) )
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
} else if ( ! ( V_11 -> V_30 & V_108 ) )
continue;
V_101 = V_11 -> V_8 ;
V_102 = V_100 ;
while ( ( V_103 = * V_101 ++ ) ) {
V_103 = tolower ( V_103 ) ;
* V_102 ++ = ( V_103 == '_' ) ? '/' : V_103 ;
}
strcpy ( V_102 , L_48 ) ;
V_106 = F_57 ( V_100 , V_109 | V_110 | V_111 , 0644 ) ;
if ( V_106 == - 1 ) {
if ( V_112 != V_113 ) {
V_105 = 1 ;
break;
}
V_102 = V_100 ;
while ( ( V_102 = strchr ( V_102 , '/' ) ) ) {
* V_102 = 0 ;
if ( V_16 ( V_100 , & V_104 ) && F_58 ( V_100 , 0755 ) ) {
V_105 = 1 ;
goto V_84;
}
* V_102 ++ = '/' ;
}
V_106 = F_57 ( V_100 , V_109 | V_110 | V_111 , 0644 ) ;
if ( V_106 == - 1 ) {
V_105 = 1 ;
break;
}
}
F_59 ( V_106 ) ;
}
V_84:
if ( F_56 ( L_49 ) )
return 1 ;
return V_105 ;
}
int F_60 ( void )
{
struct V_10 * V_11 ;
const char * V_8 ;
T_2 * V_84 , * V_114 , * V_115 ;
int V_40 ;
F_44 () ;
F_61 ( L_50 ) ;
if ( F_55 () )
return 1 ;
V_84 = fopen ( L_51 , L_38 ) ;
if ( ! V_84 )
return 1 ;
V_114 = fopen ( L_52 , L_38 ) ;
if ( ! V_114 ) {
fclose ( V_84 ) ;
return 1 ;
}
V_115 = fopen ( L_53 , L_38 ) ;
if ( ! V_115 ) {
fclose ( V_84 ) ;
fclose ( V_114 ) ;
return 1 ;
}
F_42 ( V_84 , & V_88 , NULL ) ;
F_42 ( V_114 , & V_116 , NULL ) ;
F_42 ( V_115 , & V_117 , NULL ) ;
F_21 (i, sym) {
if ( ! V_11 -> V_8 )
continue;
F_10 ( V_11 ) ;
F_40 ( V_115 , V_11 , & V_118 , NULL ) ;
if ( ! ( V_11 -> V_30 & V_63 ) )
continue;
F_40 ( V_84 , V_11 , & V_88 , ( void * ) 1 ) ;
F_40 ( V_114 , V_11 , & V_116 , ( void * ) 1 ) ;
F_40 ( V_115 , V_11 , & V_117 , NULL ) ;
}
fclose ( V_84 ) ;
fclose ( V_114 ) ;
fclose ( V_115 ) ;
V_8 = getenv ( L_54 ) ;
if ( ! V_8 )
V_8 = L_55 ;
if ( rename ( L_53 , V_8 ) )
return 1 ;
V_8 = getenv ( L_56 ) ;
if ( ! V_8 )
V_8 = L_57 ;
if ( rename ( L_52 , V_8 ) )
return 1 ;
V_8 = F_7 () ;
if ( rename ( L_51 , V_8 ) )
return 1 ;
return 0 ;
}
void F_29 ( int V_119 )
{
int V_120 = V_121 ;
V_121 = V_119 ;
if ( V_122 &&
( bool ) V_120 != ( bool ) V_119 )
V_122 () ;
}
void F_18 ( int V_119 )
{
F_29 ( V_119 + V_121 ) ;
}
bool F_53 ( void )
{
return V_121 ;
}
void F_62 ( void (* F_4)( void ) )
{
V_122 = F_4 ;
}
static void F_63 ( struct V_10 * V_123 )
{
struct V_41 * V_42 ;
struct V_10 * V_11 ;
struct V_47 * V_60 ;
int V_124 , V_23 ;
if ( V_123 -> V_64 . V_28 != V_32 )
return;
V_42 = F_26 ( V_123 ) ;
V_124 = 0 ;
F_32 (prop->expr, e, sym)
V_124 ++ ;
V_23 = ( rand () % V_124 ) ;
V_124 = 0 ;
F_32 (prop->expr, e, sym) {
if ( V_23 == V_124 ++ ) {
V_11 -> V_23 [ V_55 ] . V_28 = V_32 ;
V_123 -> V_23 [ V_55 ] . V_39 = V_11 ;
}
else {
V_11 -> V_23 [ V_55 ] . V_28 = V_33 ;
}
}
V_123 -> V_30 |= V_65 ;
V_123 -> V_30 &= ~ ( V_53 ) ;
}
static void F_64 ( struct V_10 * V_123 )
{
struct V_41 * V_42 ;
struct V_10 * V_11 ;
struct V_47 * V_60 ;
V_42 = F_26 ( V_123 ) ;
F_32 (prop->expr, e, sym) {
if ( ! F_30 ( V_11 ) )
V_11 -> V_23 [ V_55 ] . V_28 = V_33 ;
}
V_123 -> V_30 |= V_65 ;
V_123 -> V_30 &= ~ ( V_53 ) ;
}
void F_65 ( enum V_125 V_126 )
{
struct V_10 * V_11 , * V_123 ;
int V_40 , V_124 ;
F_21 (i, sym) {
if ( F_30 ( V_11 ) )
continue;
switch ( F_66 ( V_11 ) ) {
case V_31 :
case V_27 :
switch ( V_126 ) {
case V_127 :
V_11 -> V_23 [ V_55 ] . V_28 = V_32 ;
break;
case V_128 :
V_11 -> V_23 [ V_55 ] . V_28 = V_29 ;
break;
case V_129 :
V_11 -> V_23 [ V_55 ] . V_28 = V_33 ;
break;
case V_130 :
V_124 = F_66 ( V_11 ) == V_27 ? 3 : 2 ;
V_11 -> V_23 [ V_55 ] . V_28 = ( V_114 ) ( rand () % V_124 ) ;
break;
default:
continue;
}
if ( ! ( F_22 ( V_11 ) && V_126 == V_130 ) )
V_11 -> V_30 |= V_65 ;
break;
default:
break;
}
}
F_44 () ;
F_21 (i, csym) {
if ( F_30 ( V_123 ) || ! F_22 ( V_123 ) )
continue;
F_10 ( V_123 ) ;
if ( V_126 == V_130 )
F_63 ( V_123 ) ;
else
F_64 ( V_123 ) ;
}
}
