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
break;
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
static void F_34 ( bool V_66 , const char * V_8 ,
const char * V_67 , T_2 * V_68 )
{
int V_69 ;
if ( V_66 )
fprintf ( V_68 , L_19 , V_54 , V_8 ) ;
else
fprintf ( V_68 , L_20 , V_54 , V_8 ) ;
while ( 1 ) {
V_69 = strcspn ( V_67 , L_11 ) ;
if ( V_69 ) {
F_35 ( V_67 , V_69 , 1 , V_68 ) ;
V_67 += V_69 ;
}
if ( ! * V_67 )
break;
fprintf ( V_68 , L_21 , * V_67 ++ ) ;
}
fputs ( L_22 , V_68 ) ;
}
static void F_36 ( struct V_10 * V_11 , T_2 * V_68 , bool V_70 )
{
const char * V_67 ;
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
switch ( F_31 ( V_11 ) ) {
case V_33 :
if ( V_70 )
fprintf ( V_68 , L_23 ,
V_54 , V_11 -> V_8 ) ;
break;
case V_29 :
fprintf ( V_68 , L_24 , V_54 , V_11 -> V_8 ) ;
break;
case V_32 :
fprintf ( V_68 , L_25 , V_54 , V_11 -> V_8 ) ;
break;
}
break;
case V_35 :
F_34 ( false , V_11 -> V_8 , F_11 ( V_11 ) , V_68 ) ;
break;
case V_38 :
case V_37 :
V_67 = F_11 ( V_11 ) ;
fprintf ( V_68 , L_26 , V_54 , V_11 -> V_8 , V_67 ) ;
break;
case V_34 :
case V_57 :
break;
}
}
int F_37 ( const char * V_71 )
{
struct V_10 * V_11 ;
struct V_72 * V_72 ;
T_2 * V_68 ;
V_68 = fopen ( V_71 , L_27 ) ;
if ( ! V_68 )
return 1 ;
F_38 () ;
V_72 = V_73 . V_74 ;
while ( V_72 != NULL )
{
V_11 = V_72 -> V_11 ;
if ( V_11 == NULL ) {
if ( ! F_39 ( V_72 ) )
goto V_75;
} else if ( ! F_22 ( V_11 ) ) {
F_10 ( V_11 ) ;
if ( ! ( V_11 -> V_30 & V_63 ) )
goto V_75;
V_11 -> V_30 &= ~ V_63 ;
if ( ! F_40 ( V_11 ) )
goto V_75;
if ( strcmp ( F_11 ( V_11 ) , F_41 ( V_11 ) ) == 0 )
goto V_75;
if ( F_24 ( V_11 ) ) {
struct V_10 * V_58 ;
struct V_10 * V_76 ;
V_58 = F_25 ( F_26 ( V_11 ) ) ;
V_76 = F_42 ( V_58 ) ;
if ( ! F_43 ( V_58 ) && V_11 == V_76 ) {
if ( ( V_11 -> type == V_31 ) &&
F_31 ( V_11 ) == V_32 )
goto V_75;
}
}
F_36 ( V_11 , V_68 , true ) ;
}
V_75:
if ( V_72 -> V_74 != NULL ) {
V_72 = V_72 -> V_74 ;
}
else if ( V_72 -> V_77 != NULL ) {
V_72 = V_72 -> V_77 ;
} else {
while ( ( V_72 = V_72 -> V_78 ) ) {
if ( V_72 -> V_77 != NULL ) {
V_72 = V_72 -> V_77 ;
break;
}
}
}
}
fclose ( V_68 ) ;
return 0 ;
}
int F_44 ( const char * V_8 )
{
T_2 * V_68 ;
struct V_10 * V_11 ;
struct V_72 * V_72 ;
const char * V_79 ;
const char * V_67 ;
char V_80 [ V_19 + 1 ] , V_81 [ V_19 + 1 ] , V_82 [ V_19 + 1 ] ;
char * V_20 ;
V_80 [ 0 ] = 0 ;
if ( V_8 && V_8 [ 0 ] ) {
struct V_16 V_83 ;
char * V_84 ;
if ( ! V_16 ( V_8 , & V_83 ) && F_45 ( V_83 . V_85 ) ) {
strcpy ( V_80 , V_8 ) ;
strcat ( V_80 , L_28 ) ;
V_79 = F_6 () ;
} else if ( ( V_84 = strrchr ( V_8 , '/' ) ) ) {
int V_86 = V_84 - V_8 + 1 ;
memcpy ( V_80 , V_8 , V_86 ) ;
V_80 [ V_86 ] = 0 ;
if ( V_84 [ 1 ] )
V_79 = V_84 + 1 ;
else
V_79 = F_6 () ;
} else
V_79 = V_8 ;
} else
V_79 = F_6 () ;
sprintf ( V_82 , L_29 , V_80 , V_79 ) ;
V_20 = getenv ( L_30 ) ;
if ( ! V_20 || ! * V_20 ) {
sprintf ( V_81 , L_31 , V_80 , ( int ) F_46 () ) ;
V_68 = fopen ( V_81 , L_27 ) ;
} else {
* V_81 = 0 ;
V_68 = fopen ( V_82 , L_27 ) ;
}
if ( ! V_68 )
return 1 ;
fprintf ( V_68 , _ ( L_32
L_33
L_34
L_32 ) ,
V_73 . V_87 -> V_88 ) ;
if ( ! F_47 () )
F_38 () ;
V_72 = V_73 . V_74 ;
while ( V_72 ) {
V_11 = V_72 -> V_11 ;
if ( ! V_11 ) {
if ( ! F_39 ( V_72 ) )
goto V_77;
V_67 = F_48 ( V_72 ) ;
fprintf ( V_68 , L_2
L_32
L_34
L_32 , V_67 ) ;
} else if ( ! ( V_11 -> V_30 & V_89 ) ) {
F_10 ( V_11 ) ;
if ( ! ( V_11 -> V_30 & V_63 ) )
goto V_77;
V_11 -> V_30 &= ~ V_63 ;
F_36 ( V_11 , V_68 , true ) ;
}
V_77:
if ( V_72 -> V_74 ) {
V_72 = V_72 -> V_74 ;
continue;
}
if ( V_72 -> V_77 )
V_72 = V_72 -> V_77 ;
else while ( ( V_72 = V_72 -> V_78 ) ) {
if ( V_72 -> V_77 ) {
V_72 = V_72 -> V_77 ;
break;
}
}
}
fclose ( V_68 ) ;
if ( * V_81 ) {
strcat ( V_80 , V_79 ) ;
strcat ( V_80 , L_35 ) ;
rename ( V_82 , V_80 ) ;
if ( rename ( V_81 , V_82 ) )
return 1 ;
}
F_5 ( _ ( L_36 ) , V_82 ) ;
F_29 ( 0 ) ;
return 0 ;
}
static int F_49 ( void )
{
const char * V_8 ;
char V_90 [ V_19 + 1 ] ;
char * V_91 , * V_92 , V_93 ;
struct V_10 * V_11 ;
struct V_16 V_94 ;
int V_95 , V_40 , V_96 ;
V_8 = F_7 () ;
F_16 ( V_8 , V_97 ) ;
if ( F_50 ( L_37 ) )
return 1 ;
V_95 = 0 ;
F_21 (i, sym) {
F_10 ( V_11 ) ;
if ( ( V_11 -> V_30 & V_61 ) || ! V_11 -> V_8 )
continue;
if ( V_11 -> V_30 & V_63 ) {
if ( V_11 -> V_30 & V_98 ) {
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
if ( F_31 ( V_11 ) ==
V_11 -> V_23 [ V_97 ] . V_28 )
continue;
break;
case V_35 :
case V_38 :
case V_37 :
if ( ! strcmp ( F_11 ( V_11 ) ,
V_11 -> V_23 [ V_97 ] . V_39 ) )
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
} else if ( ! ( V_11 -> V_30 & V_98 ) )
continue;
V_91 = V_11 -> V_8 ;
V_92 = V_90 ;
while ( ( V_93 = * V_91 ++ ) ) {
V_93 = tolower ( V_93 ) ;
* V_92 ++ = ( V_93 == '_' ) ? '/' : V_93 ;
}
strcpy ( V_92 , L_38 ) ;
V_96 = F_51 ( V_90 , V_99 | V_100 | V_101 , 0644 ) ;
if ( V_96 == - 1 ) {
if ( V_102 != V_103 ) {
V_95 = 1 ;
break;
}
V_92 = V_90 ;
while ( ( V_92 = strchr ( V_92 , '/' ) ) ) {
* V_92 = 0 ;
if ( V_16 ( V_90 , & V_94 ) && F_52 ( V_90 , 0755 ) ) {
V_95 = 1 ;
goto V_68;
}
* V_92 ++ = '/' ;
}
V_96 = F_51 ( V_90 , V_99 | V_100 | V_101 , 0644 ) ;
if ( V_96 == - 1 ) {
V_95 = 1 ;
break;
}
}
F_53 ( V_96 ) ;
}
V_68:
if ( F_50 ( L_39 ) )
return 1 ;
return V_95 ;
}
int F_54 ( void )
{
struct V_10 * V_11 ;
const char * V_67 ;
const char * V_8 ;
T_2 * V_68 , * V_104 , * V_105 ;
int V_40 ;
F_38 () ;
F_55 ( L_40 ) ;
if ( F_49 () )
return 1 ;
V_68 = fopen ( L_41 , L_27 ) ;
if ( ! V_68 )
return 1 ;
V_104 = fopen ( L_42 , L_27 ) ;
if ( ! V_104 ) {
fclose ( V_68 ) ;
return 1 ;
}
V_105 = fopen ( L_43 , L_27 ) ;
if ( ! V_105 ) {
fclose ( V_68 ) ;
fclose ( V_104 ) ;
return 1 ;
}
fprintf ( V_68 , L_32
L_33
L_34
L_32 ,
V_73 . V_87 -> V_88 ) ;
fprintf ( V_104 , L_32
L_44
L_2 ) ;
fprintf ( V_105 , L_45
L_46
L_47
L_48 ,
V_73 . V_87 -> V_88 ) ;
F_21 (i, sym) {
F_10 ( V_11 ) ;
if ( ! ( V_11 -> V_30 & V_63 ) || ! V_11 -> V_8 )
continue;
F_36 ( V_11 , V_68 , false ) ;
switch ( V_11 -> type ) {
case V_31 :
case V_27 :
switch ( F_31 ( V_11 ) ) {
case V_33 :
break;
case V_29 :
fprintf ( V_104 , L_49 ,
V_54 , V_11 -> V_8 ) ;
fprintf ( V_105 , L_50 ,
V_54 , V_11 -> V_8 ) ;
break;
case V_32 :
if ( V_11 -> type == V_27 )
fprintf ( V_104 , L_51 ,
V_54 , V_11 -> V_8 ) ;
fprintf ( V_105 , L_52 ,
V_54 , V_11 -> V_8 ) ;
break;
}
break;
case V_35 :
F_34 ( true , V_11 -> V_8 , F_11 ( V_11 ) , V_105 ) ;
break;
case V_38 :
V_67 = F_11 ( V_11 ) ;
if ( V_67 [ 0 ] != '0' || ( V_67 [ 1 ] != 'x' && V_67 [ 1 ] != 'X' ) ) {
fprintf ( V_105 , L_53 ,
V_54 , V_11 -> V_8 , V_67 ) ;
break;
}
case V_37 :
V_67 = F_11 ( V_11 ) ;
fprintf ( V_105 , L_54 ,
V_54 , V_11 -> V_8 , V_67 ) ;
break;
default:
break;
}
}
fclose ( V_68 ) ;
fclose ( V_104 ) ;
fclose ( V_105 ) ;
V_8 = getenv ( L_55 ) ;
if ( ! V_8 )
V_8 = L_56 ;
if ( rename ( L_43 , V_8 ) )
return 1 ;
V_8 = getenv ( L_57 ) ;
if ( ! V_8 )
V_8 = L_58 ;
if ( rename ( L_42 , V_8 ) )
return 1 ;
V_8 = F_7 () ;
if ( rename ( L_41 , V_8 ) )
return 1 ;
return 0 ;
}
void F_29 ( int V_106 )
{
int V_107 = V_108 ;
V_108 = V_106 ;
if ( V_109 &&
( bool ) V_107 != ( bool ) V_106 )
V_109 () ;
}
void F_18 ( int V_106 )
{
F_29 ( V_106 + V_108 ) ;
}
bool F_47 ( void )
{
return V_108 ;
}
void F_56 ( void (* F_4)( void ) )
{
V_109 = F_4 ;
}
static void F_57 ( struct V_10 * V_110 )
{
struct V_41 * V_42 ;
struct V_10 * V_11 ;
struct V_47 * V_60 ;
int V_111 , V_23 ;
if ( V_110 -> V_64 . V_28 != V_32 )
return;
V_42 = F_26 ( V_110 ) ;
V_111 = 0 ;
F_32 (prop->expr, e, sym)
V_111 ++ ;
V_23 = ( rand () % V_111 ) ;
V_111 = 0 ;
F_32 (prop->expr, e, sym) {
if ( V_23 == V_111 ++ ) {
V_11 -> V_23 [ V_55 ] . V_28 = V_32 ;
V_110 -> V_23 [ V_55 ] . V_39 = V_11 ;
}
else {
V_11 -> V_23 [ V_55 ] . V_28 = V_33 ;
}
}
V_110 -> V_30 |= V_65 ;
V_110 -> V_30 &= ~ ( V_53 ) ;
}
static void F_58 ( struct V_10 * V_110 )
{
struct V_41 * V_42 ;
struct V_10 * V_11 ;
struct V_47 * V_60 ;
V_42 = F_26 ( V_110 ) ;
F_32 (prop->expr, e, sym) {
if ( ! F_30 ( V_11 ) )
V_11 -> V_23 [ V_55 ] . V_28 = V_33 ;
}
V_110 -> V_30 |= V_65 ;
V_110 -> V_30 &= ~ ( V_53 ) ;
}
void F_59 ( enum V_112 V_113 )
{
struct V_10 * V_11 , * V_110 ;
int V_40 , V_111 ;
F_21 (i, sym) {
if ( F_30 ( V_11 ) )
continue;
switch ( F_60 ( V_11 ) ) {
case V_31 :
case V_27 :
switch ( V_113 ) {
case V_114 :
V_11 -> V_23 [ V_55 ] . V_28 = V_32 ;
break;
case V_115 :
V_11 -> V_23 [ V_55 ] . V_28 = V_29 ;
break;
case V_116 :
V_11 -> V_23 [ V_55 ] . V_28 = V_33 ;
break;
case V_117 :
V_111 = F_60 ( V_11 ) == V_27 ? 3 : 2 ;
V_11 -> V_23 [ V_55 ] . V_28 = ( V_104 ) ( rand () % V_111 ) ;
break;
default:
continue;
}
if ( ! ( F_22 ( V_11 ) && V_113 == V_117 ) )
V_11 -> V_30 |= V_65 ;
break;
default:
break;
}
}
F_38 () ;
F_21 (i, csym) {
if ( F_30 ( V_110 ) || ! F_22 ( V_110 ) )
continue;
F_10 ( V_110 ) ;
if ( V_113 == V_117 )
F_57 ( V_110 ) ;
else
F_58 ( V_110 ) ;
}
}
