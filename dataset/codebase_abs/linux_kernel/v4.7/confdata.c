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
va_end ( V_2 ) ;
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
if ( V_23 != V_34 )
F_1 ( L_10 ,
V_25 , V_11 -> V_8 ) ;
return 1 ;
case V_35 :
if ( * V_25 != '"' ) {
for ( V_26 = V_25 ; * V_26 && ! isspace ( * V_26 ) ; V_26 ++ )
;
V_11 -> type = V_36 ;
goto V_37;
}
case V_36 :
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
if ( V_23 != V_34 )
F_1 ( L_12 ) ;
return 1 ;
}
case V_38 :
case V_39 :
V_37:
if ( F_14 ( V_11 , V_25 ) ) {
V_11 -> V_23 [ V_23 ] . V_40 = F_15 ( V_25 ) ;
V_11 -> V_30 |= V_24 ;
} else {
if ( V_23 != V_34 )
F_1 ( L_10 ,
V_25 , V_11 -> V_8 ) ;
return 1 ;
}
break;
default:
;
}
return 0 ;
}
static int F_16 ( int V_41 , char * * V_42 , T_2 V_43 , T_2 * V_44 )
{
char * V_45 ;
T_2 V_46 = V_43 + 1 ;
if ( V_46 > * V_44 ) {
V_46 += V_47 - 1 ;
V_46 *= 2 ;
V_45 = realloc ( * V_42 , V_46 ) ;
if ( ! V_45 )
return - 1 ;
* V_42 = V_45 ;
* V_44 = V_46 ;
}
( * V_42 ) [ V_43 ] = V_41 ;
return 0 ;
}
static T_3 F_17 ( char * * V_42 , T_2 * V_44 , T_4 * V_48 )
{
char * line = * V_42 ;
T_2 V_43 = 0 ;
for (; ; ) {
int V_41 = getc ( V_48 ) ;
switch ( V_41 ) {
case '\n' :
if ( F_16 ( V_41 , & line , V_43 , V_44 ) < 0 )
goto V_49;
V_43 ++ ;
case V_50 :
if ( F_16 ( '\0' , & line , V_43 , V_44 ) < 0 )
goto V_49;
* V_42 = line ;
if ( V_43 == 0 )
return - 1 ;
return V_43 ;
default:
if ( F_16 ( V_41 , & line , V_43 , V_44 ) < 0 )
goto V_49;
V_43 ++ ;
}
}
V_49:
line [ V_43 - 1 ] = '\0' ;
* V_42 = line ;
return - 1 ;
}
int F_18 ( const char * V_8 , int V_23 )
{
T_4 * V_9 = NULL ;
char * line = NULL ;
T_2 V_51 = 0 ;
char * V_25 , * V_26 ;
struct V_10 * V_11 ;
int V_52 , V_24 ;
if ( V_8 ) {
V_9 = F_19 ( V_8 ) ;
} else {
struct V_53 * V_54 ;
V_8 = F_6 () ;
V_9 = F_19 ( V_8 ) ;
if ( V_9 )
goto V_55;
F_20 ( 1 ) ;
if ( ! V_56 )
return 1 ;
F_21 (sym_defconfig_list, prop) {
if ( F_22 ( V_54 -> V_57 . V_58 ) == V_33 ||
V_54 -> V_58 -> type != V_59 )
continue;
V_8 = F_8 ( V_54 -> V_58 -> V_60 . V_11 -> V_8 ) ;
V_9 = F_19 ( V_8 ) ;
if ( V_9 ) {
F_5 ( _ ( L_13 ) ,
V_8 ) ;
goto V_55;
}
}
}
if ( ! V_9 )
return 1 ;
V_55:
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
case V_38 :
case V_39 :
case V_36 :
if ( V_11 -> V_23 [ V_23 ] . V_40 )
free ( V_11 -> V_23 [ V_23 ] . V_40 ) ;
default:
V_11 -> V_23 [ V_23 ] . V_40 = NULL ;
V_11 -> V_23 [ V_23 ] . V_28 = V_33 ;
}
}
while ( F_17 ( & line , & V_51 , V_9 ) != - 1 ) {
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
V_11 -> type = V_35 ;
}
if ( V_11 -> V_30 & V_24 ) {
F_1 ( L_15 , V_11 -> V_8 ) ;
}
if ( F_13 ( V_11 , V_23 , V_24 , V_25 ) )
continue;
} else {
if ( line [ 0 ] != '\r' && line [ 0 ] != '\n' )
F_1 ( L_16 ,
( int ) strcspn ( line , L_17 ) , line ) ;
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
F_1 ( L_18 , V_11 -> V_8 ) ;
V_69 -> V_30 &= ~ V_24 ;
}
break;
case V_32 :
if ( V_69 -> V_23 [ V_23 ] . V_28 != V_33 )
F_1 ( L_19 , V_11 -> V_8 ) ;
V_69 -> V_23 [ V_23 ] . V_40 = V_11 ;
break;
}
V_69 -> V_23 [ V_23 ] . V_28 = F_29 ( V_69 -> V_23 [ V_23 ] . V_28 , V_11 -> V_23 [ V_23 ] . V_28 ) ;
}
}
free ( line ) ;
fclose ( V_9 ) ;
return 0 ;
}
int F_30 ( const char * V_8 )
{
struct V_10 * V_11 ;
int V_52 ;
F_31 ( 0 ) ;
if ( F_18 ( V_8 , V_66 ) ) {
F_10 ( V_70 ) ;
return 1 ;
}
F_10 ( V_70 ) ;
F_23 (i, sym) {
F_10 ( V_11 ) ;
if ( F_24 ( V_11 ) || ( V_11 -> V_30 & V_71 ) )
continue;
if ( F_32 ( V_11 ) && ( V_11 -> V_30 & V_72 ) ) {
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
if ( V_11 -> V_23 [ V_66 ] . V_28 != F_33 ( V_11 ) )
break;
if ( ! F_24 ( V_11 ) )
continue;
default:
if ( ! strcmp ( V_11 -> V_73 . V_40 , V_11 -> V_23 [ V_66 ] . V_40 ) )
continue;
break;
}
} else if ( ! F_32 ( V_11 ) && ! ( V_11 -> V_30 & V_72 ) )
continue;
V_61 ++ ;
}
F_23 (i, sym) {
if ( F_32 ( V_11 ) && ! F_26 ( V_11 ) ) {
if ( V_11 -> V_57 == V_33 && ! V_61 )
V_11 -> V_30 &= ~ V_74 ;
switch ( V_11 -> type ) {
case V_36 :
case V_38 :
case V_39 :
if ( F_34 ( V_11 , V_11 -> V_23 [ V_66 ] . V_40 ) )
break;
V_11 -> V_30 &= ~ ( V_64 | V_74 ) ;
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
F_35 ( T_4 * V_75 , struct V_10 * V_11 , const char * V_76 , void * V_77 )
{
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
if ( * V_76 == 'n' ) {
bool V_78 = ( V_77 != NULL ) ;
if ( ! V_78 )
fprintf ( V_75 , L_20 ,
V_65 , V_11 -> V_8 ) ;
return;
}
break;
default:
break;
}
fprintf ( V_75 , L_21 , V_65 , V_11 -> V_8 , V_76 ) ;
}
static void
F_36 ( T_4 * V_75 , const char * V_76 , void * V_77 )
{
const char * V_25 = V_76 ;
T_2 V_79 ;
for (; ; ) {
V_79 = strcspn ( V_25 , L_2 ) ;
fprintf ( V_75 , L_22 ) ;
if ( V_79 ) {
fprintf ( V_75 , L_23 ) ;
F_37 ( V_25 , V_79 , 1 , V_75 ) ;
V_25 += V_79 ;
}
fprintf ( V_75 , L_2 ) ;
if ( * V_25 ++ == '\0' )
break;
}
}
static void
F_38 ( T_4 * V_75 , struct V_10 * V_11 , const char * V_76 , void * V_77 )
{
switch ( V_11 -> type ) {
case V_31 :
case V_27 : {
const char * V_80 = L_24 ;
switch ( * V_76 ) {
case 'n' :
break;
case 'm' :
V_80 = L_25 ;
default:
fprintf ( V_75 , L_26 ,
V_65 , V_11 -> V_8 , V_80 ) ;
}
break;
}
case V_39 : {
const char * V_81 = L_24 ;
if ( V_76 [ 0 ] != '0' || ( V_76 [ 1 ] != 'x' && V_76 [ 1 ] != 'X' ) )
V_81 = L_27 ;
fprintf ( V_75 , L_28 ,
V_65 , V_11 -> V_8 , V_81 , V_76 ) ;
break;
}
case V_36 :
case V_38 :
fprintf ( V_75 , L_29 ,
V_65 , V_11 -> V_8 , V_76 ) ;
break;
default:
break;
}
}
static void
F_39 ( T_4 * V_75 , const char * V_76 , void * V_77 )
{
const char * V_25 = V_76 ;
T_2 V_79 ;
fprintf ( V_75 , L_30 ) ;
for (; ; ) {
V_79 = strcspn ( V_25 , L_2 ) ;
fprintf ( V_75 , L_31 ) ;
if ( V_79 ) {
fprintf ( V_75 , L_23 ) ;
F_37 ( V_25 , V_79 , 1 , V_75 ) ;
V_25 += V_79 ;
}
fprintf ( V_75 , L_2 ) ;
if ( * V_25 ++ == '\0' )
break;
}
fprintf ( V_75 , L_32 ) ;
}
static void
F_40 ( T_4 * V_75 , struct V_10 * V_11 , const char * V_76 , void * V_77 )
{
if ( V_11 -> type == V_27 && * V_76 != 'n' )
fprintf ( V_75 , L_33 , V_65 , V_11 -> V_8 , ( char ) toupper ( * V_76 ) ) ;
}
static void F_41 ( T_4 * V_75 , struct V_10 * V_11 ,
struct V_82 * V_83 , void * V_84 )
{
const char * V_85 ;
switch ( V_11 -> type ) {
case V_35 :
case V_68 :
break;
case V_36 :
V_85 = F_11 ( V_11 ) ;
V_85 = F_42 ( V_85 ) ;
V_83 -> V_86 ( V_75 , V_11 , V_85 , V_84 ) ;
free ( ( void * ) V_85 ) ;
break;
default:
V_85 = F_11 ( V_11 ) ;
V_83 -> V_86 ( V_75 , V_11 , V_85 , V_84 ) ;
}
}
static void
F_43 ( T_4 * V_75 , struct V_82 * V_83 , void * V_84 )
{
char V_17 [ 256 ] ;
snprintf ( V_17 , sizeof( V_17 ) ,
L_2
L_34
L_35 ,
V_87 . V_88 -> V_89 ) ;
V_83 -> V_90 ( V_75 , V_17 , V_84 ) ;
}
int F_44 ( const char * V_91 )
{
struct V_10 * V_11 ;
struct V_92 * V_92 ;
T_4 * V_93 ;
V_93 = fopen ( V_91 , L_36 ) ;
if ( ! V_93 )
return 1 ;
F_45 () ;
V_92 = V_87 . V_94 ;
while ( V_92 != NULL )
{
V_11 = V_92 -> V_11 ;
if ( V_11 == NULL ) {
if ( ! F_46 ( V_92 ) )
goto V_95;
} else if ( ! F_24 ( V_11 ) ) {
F_10 ( V_11 ) ;
if ( ! ( V_11 -> V_30 & V_72 ) )
goto V_95;
V_11 -> V_30 &= ~ V_72 ;
if ( ! F_47 ( V_11 ) )
goto V_95;
if ( strcmp ( F_11 ( V_11 ) , F_48 ( V_11 ) ) == 0 )
goto V_95;
if ( F_26 ( V_11 ) ) {
struct V_10 * V_69 ;
struct V_10 * V_96 ;
V_69 = F_27 ( F_28 ( V_11 ) ) ;
V_96 = F_49 ( V_69 ) ;
if ( ! F_50 ( V_69 ) && V_11 == V_96 ) {
if ( ( V_11 -> type == V_31 ) &&
F_33 ( V_11 ) == V_32 )
goto V_95;
}
}
F_41 ( V_93 , V_11 , & V_97 , NULL ) ;
}
V_95:
if ( V_92 -> V_94 != NULL ) {
V_92 = V_92 -> V_94 ;
}
else if ( V_92 -> V_98 != NULL ) {
V_92 = V_92 -> V_98 ;
} else {
while ( ( V_92 = V_92 -> V_99 ) ) {
if ( V_92 -> V_98 != NULL ) {
V_92 = V_92 -> V_98 ;
break;
}
}
}
}
fclose ( V_93 ) ;
return 0 ;
}
int F_51 ( const char * V_8 )
{
T_4 * V_93 ;
struct V_10 * V_11 ;
struct V_92 * V_92 ;
const char * V_100 ;
const char * V_85 ;
char V_101 [ V_19 + 1 ] , V_102 [ V_19 + 1 ] , V_103 [ V_19 + 1 ] ;
char * V_20 ;
V_101 [ 0 ] = 0 ;
if ( V_8 && V_8 [ 0 ] ) {
struct V_16 V_104 ;
char * V_105 ;
if ( ! V_16 ( V_8 , & V_104 ) && F_52 ( V_104 . V_106 ) ) {
strcpy ( V_101 , V_8 ) ;
strcat ( V_101 , L_37 ) ;
V_100 = F_6 () ;
} else if ( ( V_105 = strrchr ( V_8 , '/' ) ) ) {
int V_107 = V_105 - V_8 + 1 ;
memcpy ( V_101 , V_8 , V_107 ) ;
V_101 [ V_107 ] = 0 ;
if ( V_105 [ 1 ] )
V_100 = V_105 + 1 ;
else
V_100 = F_6 () ;
} else
V_100 = V_8 ;
} else
V_100 = F_6 () ;
sprintf ( V_103 , L_38 , V_101 , V_100 ) ;
V_20 = getenv ( L_39 ) ;
if ( ! V_20 || ! * V_20 ) {
sprintf ( V_102 , L_40 , V_101 , ( int ) F_53 () ) ;
V_93 = fopen ( V_102 , L_36 ) ;
} else {
* V_102 = 0 ;
V_93 = fopen ( V_103 , L_36 ) ;
}
if ( ! V_93 )
return 1 ;
F_43 ( V_93 , & V_97 , NULL ) ;
if ( ! F_54 () )
F_45 () ;
V_92 = V_87 . V_94 ;
while ( V_92 ) {
V_11 = V_92 -> V_11 ;
if ( ! V_11 ) {
if ( ! F_46 ( V_92 ) )
goto V_98;
V_85 = F_55 ( V_92 ) ;
fprintf ( V_93 , L_2
L_41
L_42
L_41 , V_85 ) ;
} else if ( ! ( V_11 -> V_30 & V_108 ) ) {
F_10 ( V_11 ) ;
if ( ! ( V_11 -> V_30 & V_72 ) )
goto V_98;
V_11 -> V_30 &= ~ V_72 ;
F_41 ( V_93 , V_11 , & V_97 , NULL ) ;
}
V_98:
if ( V_92 -> V_94 ) {
V_92 = V_92 -> V_94 ;
continue;
}
if ( V_92 -> V_98 )
V_92 = V_92 -> V_98 ;
else while ( ( V_92 = V_92 -> V_99 ) ) {
if ( V_92 -> V_98 ) {
V_92 = V_92 -> V_98 ;
break;
}
}
}
fclose ( V_93 ) ;
if ( * V_102 ) {
strcat ( V_101 , V_100 ) ;
strcat ( V_101 , L_43 ) ;
rename ( V_103 , V_101 ) ;
if ( rename ( V_102 , V_103 ) )
return 1 ;
}
F_5 ( _ ( L_44 ) , V_103 ) ;
F_31 ( 0 ) ;
return 0 ;
}
static int F_56 ( void )
{
const char * V_8 ;
char V_109 [ V_19 + 1 ] ;
char * V_110 , * V_111 , V_41 ;
struct V_10 * V_11 ;
struct V_16 V_112 ;
int V_113 , V_52 , V_114 ;
V_8 = F_7 () ;
F_18 ( V_8 , V_34 ) ;
F_10 ( V_70 ) ;
if ( F_57 ( L_45 ) )
return 1 ;
V_113 = 0 ;
F_23 (i, sym) {
F_10 ( V_11 ) ;
if ( ( V_11 -> V_30 & V_71 ) || ! V_11 -> V_8 )
continue;
if ( V_11 -> V_30 & V_72 ) {
if ( V_11 -> V_30 & V_115 ) {
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
if ( F_33 ( V_11 ) ==
V_11 -> V_23 [ V_34 ] . V_28 )
continue;
break;
case V_36 :
case V_39 :
case V_38 :
if ( ! strcmp ( F_11 ( V_11 ) ,
V_11 -> V_23 [ V_34 ] . V_40 ) )
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
V_110 = V_11 -> V_8 ;
V_111 = V_109 ;
while ( ( V_41 = * V_110 ++ ) ) {
V_41 = tolower ( V_41 ) ;
* V_111 ++ = ( V_41 == '_' ) ? '/' : V_41 ;
}
strcpy ( V_111 , L_46 ) ;
V_114 = F_58 ( V_109 , V_116 | V_117 | V_118 , 0644 ) ;
if ( V_114 == - 1 ) {
if ( V_119 != V_120 ) {
V_113 = 1 ;
break;
}
V_111 = V_109 ;
while ( ( V_111 = strchr ( V_111 , '/' ) ) ) {
* V_111 = 0 ;
if ( V_16 ( V_109 , & V_112 ) && F_59 ( V_109 , 0755 ) ) {
V_113 = 1 ;
goto V_93;
}
* V_111 ++ = '/' ;
}
V_114 = F_58 ( V_109 , V_116 | V_117 | V_118 , 0644 ) ;
if ( V_114 == - 1 ) {
V_113 = 1 ;
break;
}
}
F_60 ( V_114 ) ;
}
V_93:
if ( F_57 ( L_47 ) )
return 1 ;
return V_113 ;
}
int F_61 ( void )
{
struct V_10 * V_11 ;
const char * V_8 ;
T_4 * V_93 , * V_121 , * V_122 ;
int V_52 ;
F_45 () ;
F_62 ( L_48 ) ;
if ( F_56 () )
return 1 ;
V_93 = fopen ( L_49 , L_36 ) ;
if ( ! V_93 )
return 1 ;
V_121 = fopen ( L_50 , L_36 ) ;
if ( ! V_121 ) {
fclose ( V_93 ) ;
return 1 ;
}
V_122 = fopen ( L_51 , L_36 ) ;
if ( ! V_122 ) {
fclose ( V_93 ) ;
fclose ( V_121 ) ;
return 1 ;
}
F_43 ( V_93 , & V_97 , NULL ) ;
F_43 ( V_121 , & V_123 , NULL ) ;
F_43 ( V_122 , & V_124 , NULL ) ;
F_23 (i, sym) {
F_10 ( V_11 ) ;
if ( ! ( V_11 -> V_30 & V_72 ) || ! V_11 -> V_8 )
continue;
F_41 ( V_93 , V_11 , & V_97 , ( void * ) 1 ) ;
F_41 ( V_121 , V_11 , & V_123 , ( void * ) 1 ) ;
F_41 ( V_122 , V_11 , & V_124 , NULL ) ;
}
fclose ( V_93 ) ;
fclose ( V_121 ) ;
fclose ( V_122 ) ;
V_8 = getenv ( L_52 ) ;
if ( ! V_8 )
V_8 = L_53 ;
if ( rename ( L_51 , V_8 ) )
return 1 ;
V_8 = getenv ( L_54 ) ;
if ( ! V_8 )
V_8 = L_55 ;
if ( rename ( L_50 , V_8 ) )
return 1 ;
V_8 = F_7 () ;
if ( rename ( L_49 , V_8 ) )
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
static bool F_64 ( struct V_10 * V_129 )
{
struct V_53 * V_54 ;
struct V_10 * V_11 ;
struct V_58 * V_130 ;
int V_131 , V_23 ;
if ( V_129 -> V_73 . V_28 != V_32 )
return false ;
V_54 = F_28 ( V_129 ) ;
V_131 = 0 ;
F_65 (prop->expr, e, sym)
V_131 ++ ;
V_23 = ( rand () % V_131 ) ;
V_131 = 0 ;
F_65 (prop->expr, e, sym) {
if ( V_23 == V_131 ++ ) {
V_11 -> V_23 [ V_66 ] . V_28 = V_32 ;
V_129 -> V_23 [ V_66 ] . V_40 = V_11 ;
}
else {
V_11 -> V_23 [ V_66 ] . V_28 = V_33 ;
}
V_11 -> V_30 |= V_74 ;
V_11 -> V_30 &= ~ V_64 ;
}
V_129 -> V_30 |= V_74 ;
V_129 -> V_30 &= ~ ( V_64 ) ;
return true ;
}
void F_66 ( struct V_10 * V_129 )
{
struct V_53 * V_54 ;
struct V_10 * V_11 ;
struct V_58 * V_130 ;
V_54 = F_28 ( V_129 ) ;
F_65 (prop->expr, e, sym) {
if ( ! F_32 ( V_11 ) )
V_11 -> V_23 [ V_66 ] . V_28 = V_33 ;
}
V_129 -> V_30 |= V_74 ;
V_129 -> V_30 &= ~ ( V_64 | V_132 ) ;
}
bool F_67 ( enum V_133 V_134 )
{
struct V_10 * V_11 , * V_129 ;
int V_52 , V_131 , V_135 , V_136 , V_137 ;
V_135 = 50 ; V_136 = V_137 = 33 ;
if ( V_134 == V_138 ) {
int V_44 , V_25 [ 3 ] ;
char * V_20 = getenv ( L_56 ) ;
V_44 = 0 ;
while( V_20 && * V_20 ) {
char * V_139 ;
int V_140 = strtol ( V_20 , & V_139 , 10 ) ;
if( V_140 >= 0 && V_140 <= 100 ) {
V_25 [ V_44 ++ ] = V_140 ;
} else {
V_119 = V_141 ;
perror ( L_56 ) ;
exit ( 1 ) ;
}
V_20 = ( * V_139 == ':' ) ? V_139 + 1 : V_139 ;
if( V_44 >= 3 ) {
break;
}
}
switch( V_44 ) {
case 1 :
V_135 = V_25 [ 0 ] ; V_137 = V_135 / 2 ; V_136 = V_135 - V_137 ;
break;
case 2 :
V_136 = V_25 [ 0 ] ; V_137 = V_25 [ 1 ] ; V_135 = V_136 + V_137 ;
break;
case 3 :
V_135 = V_25 [ 0 ] ; V_136 = V_25 [ 1 ] ; V_137 = V_25 [ 2 ] ;
break;
}
if( V_136 + V_137 > 100 ) {
V_119 = V_141 ;
perror ( L_56 ) ;
exit ( 1 ) ;
}
}
bool V_142 = false ;
F_23 (i, sym) {
if ( F_32 ( V_11 ) || ( V_11 -> V_30 & V_64 ) )
continue;
switch ( F_68 ( V_11 ) ) {
case V_31 :
case V_27 :
V_142 = true ;
switch ( V_134 ) {
case V_143 :
V_11 -> V_23 [ V_66 ] . V_28 = V_32 ;
break;
case V_144 :
V_11 -> V_23 [ V_66 ] . V_28 = V_29 ;
break;
case V_145 :
if ( V_11 -> V_30 & V_146 )
V_11 -> V_23 [ V_66 ] . V_28 = V_32 ;
else
V_11 -> V_23 [ V_66 ] . V_28 = V_33 ;
break;
case V_138 :
V_11 -> V_23 [ V_66 ] . V_28 = V_33 ;
V_131 = rand () % 100 ;
if ( V_11 -> type == V_27 ) {
if ( V_131 < V_136 )
V_11 -> V_23 [ V_66 ] . V_28 = V_32 ;
else if ( V_131 < ( V_136 + V_137 ) )
V_11 -> V_23 [ V_66 ] . V_28 = V_29 ;
} else if ( V_131 < V_135 )
V_11 -> V_23 [ V_66 ] . V_28 = V_32 ;
break;
default:
continue;
}
if ( ! ( F_24 ( V_11 ) && V_134 == V_138 ) )
V_11 -> V_30 |= V_74 ;
break;
default:
break;
}
}
F_45 () ;
if ( V_134 != V_138 ) {
F_23 (i, csym) {
if ( ( F_24 ( V_129 ) && ! F_32 ( V_129 ) ) ||
F_26 ( V_129 ) )
V_129 -> V_30 |= V_132 ;
}
}
F_23 (i, csym) {
if ( F_32 ( V_129 ) || ! F_24 ( V_129 ) )
continue;
F_10 ( V_129 ) ;
if ( V_134 == V_138 )
V_142 = F_64 ( V_129 ) ;
else {
F_66 ( V_129 ) ;
V_142 = true ;
}
}
return V_142 ;
}
