static void F_1 ( struct V_1 * V_1 )
{
struct V_2 V_3 = F_2 () ;
F_3 ( V_1 , & V_3 ) ;
printf ( L_1 , F_4 ( & V_3 ) ) ;
F_5 ( & V_3 ) ;
}
static void F_6 ( char * V_4 )
{
char * V_5 = V_4 ;
int V_6 ;
while ( ( isspace ( * V_5 ) ) )
V_5 ++ ;
V_6 = strlen ( V_5 ) ;
if ( V_5 != V_4 )
memmove ( V_4 , V_5 , V_6 + 1 ) ;
if ( ! V_6 )
return;
V_5 = V_4 + V_6 - 1 ;
while ( ( isspace ( * V_5 ) ) )
* V_5 -- = 0 ;
}
static void F_7 ( void )
{
if ( ! V_7 ) {
printf ( _ ( L_2 ) ) ;
printf ( _ ( L_3 ) ) ;
printf ( _ ( L_4 ) ) ;
exit ( 1 ) ;
}
}
static int F_8 ( struct V_8 * V_9 , const char * V_10 )
{
enum V_11 type = F_9 ( V_9 ) ;
if ( ! F_10 ( V_9 ) )
printf ( _ ( L_5 ) ) ;
line [ 0 ] = '\n' ;
line [ 1 ] = 0 ;
if ( ! F_11 ( V_9 ) ) {
printf ( L_6 , V_10 ) ;
line [ 0 ] = '\n' ;
line [ 1 ] = 0 ;
return 0 ;
}
switch ( V_12 ) {
case V_13 :
case V_14 :
if ( F_10 ( V_9 ) ) {
printf ( L_6 , V_10 ) ;
return 0 ;
}
F_7 () ;
case V_15 :
fflush ( stdout ) ;
F_12 ( line , 128 , V_16 ) ;
if ( ! V_17 )
printf ( L_7 ) ;
return 1 ;
default:
break;
}
switch ( type ) {
case V_18 :
case V_19 :
case V_20 :
printf ( L_6 , V_10 ) ;
return 1 ;
default:
;
}
printf ( L_8 , line ) ;
return 1 ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_9 ;
const char * V_10 ;
while ( 1 ) {
printf ( L_9 , V_21 - 1 , L_10 , _ ( V_1 -> V_22 -> V_23 ) ) ;
printf ( L_11 , V_9 -> V_24 ) ;
V_10 = F_14 ( V_9 ) ;
if ( F_14 ( V_9 ) )
printf ( L_12 , V_10 ) ;
if ( ! F_8 ( V_9 , V_10 ) )
return 0 ;
switch ( line [ 0 ] ) {
case '\n' :
break;
case '?' :
if ( line [ 1 ] == '\n' ) {
F_1 ( V_1 ) ;
V_10 = NULL ;
break;
}
default:
line [ strlen ( line ) - 1 ] = 0 ;
V_10 = line ;
}
if ( V_10 && F_15 ( V_9 , V_10 ) )
return 0 ;
}
}
static int F_16 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_9 ;
T_1 V_25 , V_26 ;
while ( 1 ) {
printf ( L_9 , V_21 - 1 , L_10 , _ ( V_1 -> V_22 -> V_23 ) ) ;
if ( V_9 -> V_24 )
printf ( L_11 , V_9 -> V_24 ) ;
putchar ( '[' ) ;
V_25 = F_17 ( V_9 ) ;
switch ( V_25 ) {
case V_27 :
putchar ( 'N' ) ;
break;
case V_28 :
putchar ( 'M' ) ;
break;
case V_29 :
putchar ( 'Y' ) ;
break;
}
if ( V_25 != V_27 && F_18 ( V_9 , V_27 ) )
printf ( L_13 ) ;
if ( V_25 != V_28 && F_18 ( V_9 , V_28 ) )
printf ( L_14 ) ;
if ( V_25 != V_29 && F_18 ( V_9 , V_29 ) )
printf ( L_15 ) ;
if ( F_19 ( V_1 ) )
printf ( L_16 ) ;
printf ( L_17 ) ;
if ( ! F_8 ( V_9 , F_14 ( V_9 ) ) )
return 0 ;
F_6 ( line ) ;
switch ( line [ 0 ] ) {
case 'n' :
case 'N' :
V_26 = V_27 ;
if ( ! line [ 1 ] || ! strcmp ( & line [ 1 ] , L_18 ) )
break;
continue;
case 'm' :
case 'M' :
V_26 = V_28 ;
if ( ! line [ 1 ] )
break;
continue;
case 'y' :
case 'Y' :
V_26 = V_29 ;
if ( ! line [ 1 ] || ! strcmp ( & line [ 1 ] , L_19 ) )
break;
continue;
case 0 :
V_26 = V_25 ;
break;
case '?' :
goto V_3;
default:
continue;
}
if ( F_20 ( V_9 , V_26 ) )
return 0 ;
V_3:
F_1 ( V_1 ) ;
}
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_8 * V_9 , * V_30 ;
struct V_1 * V_31 ;
bool V_32 ;
V_9 = V_1 -> V_9 ;
V_32 = ! F_10 ( V_9 ) ;
if ( F_11 ( V_9 ) ) {
F_16 ( V_1 ) ;
F_22 ( V_9 ) ;
switch ( F_17 ( V_9 ) ) {
case V_27 :
return 1 ;
case V_28 :
return 0 ;
case V_29 :
break;
}
} else {
switch ( F_17 ( V_9 ) ) {
case V_27 :
return 1 ;
case V_28 :
printf ( L_20 , V_21 - 1 , L_10 , _ ( F_23 ( V_1 ) ) ) ;
return 0 ;
case V_29 :
break;
}
}
while ( 1 ) {
int V_33 , V_10 ;
printf ( L_20 , V_21 - 1 , L_10 , _ ( F_23 ( V_1 ) ) ) ;
V_30 = F_24 ( V_9 ) ;
V_33 = V_10 = 0 ;
line [ 0 ] = 0 ;
for ( V_31 = V_1 -> V_34 ; V_31 ; V_31 = V_31 -> V_35 ) {
if ( ! F_25 ( V_31 ) )
continue;
if ( ! V_31 -> V_9 ) {
printf ( L_21 , V_21 , '*' , _ ( F_23 ( V_31 ) ) ) ;
continue;
}
V_33 ++ ;
if ( V_31 -> V_9 == V_30 ) {
V_10 = V_33 ;
printf ( L_22 , V_21 , '>' ) ;
} else
printf ( L_22 , V_21 , ' ' ) ;
printf ( L_23 , V_33 , _ ( F_23 ( V_31 ) ) ) ;
if ( V_31 -> V_9 -> V_24 )
printf ( L_24 , V_31 -> V_9 -> V_24 ) ;
if ( ! F_10 ( V_31 -> V_9 ) )
printf ( _ ( L_25 ) ) ;
printf ( L_7 ) ;
}
printf ( _ ( L_26 ) , V_21 - 1 , L_10 ) ;
if ( V_33 == 1 ) {
printf ( L_27 ) ;
goto V_36;
}
printf ( L_28 , V_33 ) ;
if ( F_19 ( V_1 ) )
printf ( L_29 ) ;
printf ( L_30 ) ;
switch ( V_12 ) {
case V_13 :
case V_14 :
if ( ! V_32 ) {
V_33 = V_10 ;
printf ( L_31 , V_33 ) ;
break;
}
F_7 () ;
case V_15 :
fflush ( stdout ) ;
F_12 ( line , 128 , V_16 ) ;
F_6 ( line ) ;
if ( line [ 0 ] == '?' ) {
F_1 ( V_1 ) ;
continue;
}
if ( ! line [ 0 ] )
V_33 = V_10 ;
else if ( isdigit ( line [ 0 ] ) )
V_33 = atoi ( line ) ;
else
continue;
break;
default:
break;
}
V_36:
for ( V_31 = V_1 -> V_34 ; V_31 ; V_31 = V_31 -> V_35 ) {
if ( ! V_31 -> V_9 || ! F_25 ( V_31 ) )
continue;
if ( ! -- V_33 )
break;
}
if ( ! V_31 )
continue;
if ( line [ 0 ] && line [ strlen ( line ) - 1 ] == '?' ) {
F_1 ( V_31 ) ;
continue;
}
F_26 ( V_9 , V_31 -> V_9 ) ;
for ( V_31 = V_31 -> V_34 ; V_31 ; V_31 = V_31 -> V_35 ) {
V_21 += 2 ;
F_27 ( V_31 ) ;
V_21 -= 2 ;
}
return 1 ;
}
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
struct V_37 * V_38 ;
struct V_1 * V_31 ;
if ( ! F_25 ( V_1 ) )
return;
V_9 = V_1 -> V_9 ;
V_38 = V_1 -> V_22 ;
if ( V_38 ) {
const char * V_22 ;
switch ( V_38 -> type ) {
case V_39 :
if ( ( V_12 == V_14 ||
V_12 == V_40 ||
V_12 == V_41 ) &&
V_42 != V_1 ) {
F_28 ( V_1 ) ;
return;
}
case V_43 :
V_22 = F_23 ( V_1 ) ;
if ( V_22 )
printf ( L_32 ,
V_21 , '*' ,
V_21 , '*' , _ ( V_22 ) ,
V_21 , '*' ) ;
default:
;
}
}
if ( ! V_9 )
goto V_36;
if ( F_29 ( V_9 ) ) {
F_21 ( V_1 ) ;
if ( V_9 -> V_44 . V_45 != V_28 )
return;
goto V_36;
}
switch ( V_9 -> type ) {
case V_18 :
case V_19 :
case V_20 :
F_13 ( V_1 ) ;
break;
default:
F_16 ( V_1 ) ;
break;
}
V_36:
if ( V_9 )
V_21 += 2 ;
for ( V_31 = V_1 -> V_34 ; V_31 ; V_31 = V_31 -> V_35 )
F_27 ( V_31 ) ;
if ( V_9 )
V_21 -= 2 ;
}
static void F_28 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
struct V_1 * V_31 ;
if ( ! F_25 ( V_1 ) )
return;
V_9 = V_1 -> V_9 ;
if ( V_9 && ! F_10 ( V_9 ) ) {
if ( F_11 ( V_9 ) ||
( F_29 ( V_9 ) && F_17 ( V_9 ) == V_29 ) ) {
if ( V_12 == V_40 ) {
if ( V_9 -> V_24 && ! F_30 ( V_9 ) ) {
printf ( L_33 , V_46 , V_9 -> V_24 ) ;
}
} else if ( V_12 != V_41 ) {
if ( ! V_47 ++ )
printf ( _ ( L_34 ) ) ;
V_42 = F_31 ( V_1 ) ;
F_27 ( V_42 ) ;
}
}
}
for ( V_31 = V_1 -> V_34 ; V_31 ; V_31 = V_31 -> V_35 )
F_28 ( V_31 ) ;
}
static void F_32 ( const char * V_48 )
{
printf ( L_35 , V_48 ) ;
printf ( L_36 ) ;
printf ( L_37 ) ;
printf ( L_38 ) ;
printf ( L_39 ) ;
printf ( L_40 ) ;
printf ( L_41 ) ;
printf ( L_42 ) ;
printf ( L_43 ) ;
printf ( L_44 ) ;
printf ( L_45 ) ;
printf ( L_46 ) ;
printf ( L_47 ) ;
printf ( L_48 ) ;
printf ( L_49 ) ;
}
int main ( int V_49 , char * * V_50 )
{
const char * V_48 = V_50 [ 0 ] ;
int V_51 ;
const char * V_24 , * V_52 = NULL ;
struct V_53 V_54 ;
setlocale ( V_55 , L_10 ) ;
F_33 ( V_56 , V_57 ) ;
F_34 ( V_56 ) ;
V_17 = F_35 ( 0 ) && F_35 ( 1 ) && F_35 ( 2 ) ;
while ( ( V_51 = F_36 ( V_49 , V_50 , L_10 , V_58 , NULL ) ) != - 1 ) {
V_12 = (enum V_12 ) V_51 ;
switch ( V_51 ) {
case V_14 :
V_59 = 1 ;
break;
case V_60 :
case V_61 :
V_52 = V_62 ;
break;
case V_63 :
{
struct V_64 V_65 ;
unsigned int V_66 ;
char * V_67 ;
F_37 ( & V_65 , NULL ) ;
V_66 = ( unsigned int ) ( ( V_65 . V_68 + 1 ) * ( V_65 . V_69 + 1 ) ) ;
V_67 = getenv ( L_50 ) ;
if( V_67 && * V_67 ) {
char * V_70 ;
int V_71 = ( int ) strtol ( V_67 , & V_70 , 0 ) ;
if ( * V_70 == '\0' ) {
V_66 = V_71 ;
}
}
fprintf ( V_72 , L_51 , V_66 ) ;
srand ( V_66 ) ;
break;
}
case V_15 :
case V_13 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_40 :
case V_41 :
break;
case '?' :
F_32 ( V_48 ) ;
exit ( 1 ) ;
break;
}
}
if ( V_49 == V_77 ) {
printf ( _ ( L_52 ) , V_50 [ 0 ] ) ;
F_32 ( V_48 ) ;
exit ( 1 ) ;
}
V_24 = V_50 [ V_77 ] ;
F_38 ( V_24 ) ;
if ( V_59 ) {
V_24 = F_39 () ;
if ( V_53 ( V_24 , & V_54 ) ) {
fprintf ( V_72 , _ ( L_53
L_54
L_53
L_55
L_56
L_53 ) , V_24 ) ;
exit ( 1 ) ;
}
}
switch ( V_12 ) {
case V_60 :
if ( ! V_52 )
V_52 = F_40 () ;
if ( F_41 ( V_52 ) ) {
printf ( _ ( L_53
L_57
L_53 ) , V_52 ) ;
exit ( 1 ) ;
}
break;
case V_61 :
case V_14 :
case V_15 :
case V_13 :
case V_40 :
case V_41 :
F_41 ( NULL ) ;
break;
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_63 :
V_24 = getenv ( L_58 ) ;
if ( ! V_24 )
break;
if ( ( strcmp ( V_24 , L_10 ) != 0 ) && ( strcmp ( V_24 , L_59 ) != 0 ) ) {
if ( F_42 ( V_24 , V_78 ) ) {
fprintf ( V_72 ,
_ ( L_60 ) ,
V_24 ) ;
exit ( 1 ) ;
}
break;
}
switch ( V_12 ) {
case V_73 : V_24 = L_61 ; break;
case V_74 : V_24 = L_62 ; break;
case V_75 : V_24 = L_63 ; break;
case V_76 : V_24 = L_64 ; break;
case V_63 : V_24 = L_65 ; break;
default: break;
}
if ( F_42 ( V_24 , V_78 ) &&
F_42 ( L_66 , V_78 ) ) {
fprintf ( V_72 ,
_ ( L_67 ) ,
V_24 ) ;
exit ( 1 ) ;
}
break;
default:
break;
}
if ( V_59 ) {
if ( F_43 () ) {
V_24 = getenv ( L_68 ) ;
if ( V_24 && * V_24 ) {
fprintf ( V_72 ,
_ ( L_69 ) ) ;
return 1 ;
}
}
V_7 = V_17 ;
}
switch ( V_12 ) {
case V_73 :
F_44 ( V_79 ) ;
break;
case V_74 :
F_44 ( V_80 ) ;
break;
case V_75 :
F_44 ( V_81 ) ;
break;
case V_76 :
F_44 ( V_82 ) ;
break;
case V_63 :
while ( F_44 ( V_83 ) ) ;
break;
case V_60 :
F_44 ( V_82 ) ;
break;
case V_61 :
break;
case V_15 :
V_42 = & V_84 ;
F_27 ( & V_84 ) ;
V_12 = V_14 ;
case V_13 :
case V_40 :
case V_41 :
case V_14 :
do {
V_47 = 0 ;
F_28 ( & V_84 ) ;
} while ( V_47 &&
( V_12 != V_40 &&
V_12 != V_41 ) );
break;
}
if ( V_59 ) {
if ( F_43 () && F_45 ( NULL ) ) {
fprintf ( V_72 , _ ( L_70 ) ) ;
exit ( 1 ) ;
}
if ( F_46 () ) {
fprintf ( V_72 , _ ( L_71 ) ) ;
return 1 ;
}
} else if ( V_12 == V_61 ) {
if ( F_47 ( V_52 ) ) {
fprintf ( V_72 , _ ( L_72 ) ,
V_52 ) ;
return 1 ;
}
} else if ( V_12 != V_40 ) {
if ( F_45 ( NULL ) ) {
fprintf ( V_72 , _ ( L_70 ) ) ;
exit ( 1 ) ;
}
}
return 0 ;
}
void F_12 ( char * V_4 , int V_85 , T_2 * V_86 )
{
if ( fgets ( V_4 , V_85 , V_86 ) == NULL )
fprintf ( V_72 , L_73 ) ;
}
