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
return 1 ;
default:
break;
}
switch ( type ) {
case V_17 :
case V_18 :
case V_19 :
printf ( L_6 , V_10 ) ;
return 1 ;
default:
;
}
printf ( L_7 , line ) ;
return 1 ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_9 ;
const char * V_10 ;
while ( 1 ) {
printf ( L_8 , V_20 - 1 , L_9 , _ ( V_1 -> V_21 -> V_22 ) ) ;
printf ( L_10 , V_9 -> V_23 ) ;
V_10 = F_14 ( V_9 ) ;
if ( F_14 ( V_9 ) )
printf ( L_11 , V_10 ) ;
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
T_1 V_24 , V_25 ;
while ( 1 ) {
printf ( L_8 , V_20 - 1 , L_9 , _ ( V_1 -> V_21 -> V_22 ) ) ;
if ( V_9 -> V_23 )
printf ( L_10 , V_9 -> V_23 ) ;
putchar ( '[' ) ;
V_24 = F_17 ( V_9 ) ;
switch ( V_24 ) {
case V_26 :
putchar ( 'N' ) ;
break;
case V_27 :
putchar ( 'M' ) ;
break;
case V_28 :
putchar ( 'Y' ) ;
break;
}
if ( V_24 != V_26 && F_18 ( V_9 , V_26 ) )
printf ( L_12 ) ;
if ( V_24 != V_27 && F_18 ( V_9 , V_27 ) )
printf ( L_13 ) ;
if ( V_24 != V_28 && F_18 ( V_9 , V_28 ) )
printf ( L_14 ) ;
if ( F_19 ( V_1 ) )
printf ( L_15 ) ;
printf ( L_16 ) ;
if ( ! F_8 ( V_9 , F_14 ( V_9 ) ) )
return 0 ;
F_6 ( line ) ;
switch ( line [ 0 ] ) {
case 'n' :
case 'N' :
V_25 = V_26 ;
if ( ! line [ 1 ] || ! strcmp ( & line [ 1 ] , L_17 ) )
break;
continue;
case 'm' :
case 'M' :
V_25 = V_27 ;
if ( ! line [ 1 ] )
break;
continue;
case 'y' :
case 'Y' :
V_25 = V_28 ;
if ( ! line [ 1 ] || ! strcmp ( & line [ 1 ] , L_18 ) )
break;
continue;
case 0 :
V_25 = V_24 ;
break;
case '?' :
goto V_3;
default:
continue;
}
if ( F_20 ( V_9 , V_25 ) )
return 0 ;
V_3:
F_1 ( V_1 ) ;
}
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_8 * V_9 , * V_29 ;
struct V_1 * V_30 ;
bool V_31 ;
V_9 = V_1 -> V_9 ;
V_31 = ! F_10 ( V_9 ) ;
if ( F_11 ( V_9 ) ) {
F_16 ( V_1 ) ;
F_22 ( V_9 ) ;
switch ( F_17 ( V_9 ) ) {
case V_26 :
return 1 ;
case V_27 :
return 0 ;
case V_28 :
break;
}
} else {
switch ( F_17 ( V_9 ) ) {
case V_26 :
return 1 ;
case V_27 :
printf ( L_19 , V_20 - 1 , L_9 , _ ( F_23 ( V_1 ) ) ) ;
return 0 ;
case V_28 :
break;
}
}
while ( 1 ) {
int V_32 , V_10 ;
printf ( L_19 , V_20 - 1 , L_9 , _ ( F_23 ( V_1 ) ) ) ;
V_29 = F_24 ( V_9 ) ;
V_32 = V_10 = 0 ;
line [ 0 ] = 0 ;
for ( V_30 = V_1 -> V_33 ; V_30 ; V_30 = V_30 -> V_34 ) {
if ( ! F_25 ( V_30 ) )
continue;
if ( ! V_30 -> V_9 ) {
printf ( L_20 , V_20 , '*' , _ ( F_23 ( V_30 ) ) ) ;
continue;
}
V_32 ++ ;
if ( V_30 -> V_9 == V_29 ) {
V_10 = V_32 ;
printf ( L_21 , V_20 , '>' ) ;
} else
printf ( L_21 , V_20 , ' ' ) ;
printf ( L_22 , V_32 , _ ( F_23 ( V_30 ) ) ) ;
if ( V_30 -> V_9 -> V_23 )
printf ( L_23 , V_30 -> V_9 -> V_23 ) ;
if ( ! F_10 ( V_30 -> V_9 ) )
printf ( _ ( L_24 ) ) ;
printf ( L_25 ) ;
}
printf ( _ ( L_26 ) , V_20 - 1 , L_9 ) ;
if ( V_32 == 1 ) {
printf ( L_27 ) ;
goto V_35;
}
printf ( L_28 , V_32 ) ;
if ( F_19 ( V_1 ) )
printf ( L_29 ) ;
printf ( L_30 ) ;
switch ( V_12 ) {
case V_13 :
case V_14 :
if ( ! V_31 ) {
V_32 = V_10 ;
printf ( L_31 , V_32 ) ;
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
V_32 = V_10 ;
else if ( isdigit ( line [ 0 ] ) )
V_32 = atoi ( line ) ;
else
continue;
break;
default:
break;
}
V_35:
for ( V_30 = V_1 -> V_33 ; V_30 ; V_30 = V_30 -> V_34 ) {
if ( ! V_30 -> V_9 || ! F_25 ( V_30 ) )
continue;
if ( ! -- V_32 )
break;
}
if ( ! V_30 )
continue;
if ( line [ 0 ] && line [ strlen ( line ) - 1 ] == '?' ) {
F_1 ( V_30 ) ;
continue;
}
F_26 ( V_9 , V_30 -> V_9 ) ;
for ( V_30 = V_30 -> V_33 ; V_30 ; V_30 = V_30 -> V_34 ) {
V_20 += 2 ;
F_27 ( V_30 ) ;
V_20 -= 2 ;
}
return 1 ;
}
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
struct V_36 * V_37 ;
struct V_1 * V_30 ;
if ( ! F_25 ( V_1 ) )
return;
V_9 = V_1 -> V_9 ;
V_37 = V_1 -> V_21 ;
if ( V_37 ) {
const char * V_21 ;
switch ( V_37 -> type ) {
case V_38 :
if ( ( V_12 == V_14 ||
V_12 == V_39 ||
V_12 == V_40 ) &&
V_41 != V_1 ) {
F_28 ( V_1 ) ;
return;
}
case V_42 :
V_21 = F_23 ( V_1 ) ;
if ( V_21 )
printf ( L_32 ,
V_20 , '*' ,
V_20 , '*' , _ ( V_21 ) ,
V_20 , '*' ) ;
default:
;
}
}
if ( ! V_9 )
goto V_35;
if ( F_29 ( V_9 ) ) {
F_21 ( V_1 ) ;
if ( V_9 -> V_43 . V_44 != V_27 )
return;
goto V_35;
}
switch ( V_9 -> type ) {
case V_17 :
case V_18 :
case V_19 :
F_13 ( V_1 ) ;
break;
default:
F_16 ( V_1 ) ;
break;
}
V_35:
if ( V_9 )
V_20 += 2 ;
for ( V_30 = V_1 -> V_33 ; V_30 ; V_30 = V_30 -> V_34 )
F_27 ( V_30 ) ;
if ( V_9 )
V_20 -= 2 ;
}
static void F_28 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
struct V_1 * V_30 ;
if ( ! F_25 ( V_1 ) )
return;
V_9 = V_1 -> V_9 ;
if ( V_9 && ! F_10 ( V_9 ) ) {
if ( F_11 ( V_9 ) ||
( F_29 ( V_9 ) && F_17 ( V_9 ) == V_28 ) ) {
if ( V_12 == V_39 ) {
if ( V_9 -> V_23 && ! F_30 ( V_9 ) ) {
printf ( L_33 , V_45 , V_9 -> V_23 ) ;
}
} else if ( V_12 != V_40 ) {
if ( ! V_46 ++ )
printf ( _ ( L_34 ) ) ;
V_41 = F_31 ( V_1 ) ;
F_27 ( V_41 ) ;
}
}
}
for ( V_30 = V_1 -> V_33 ; V_30 ; V_30 = V_30 -> V_34 )
F_28 ( V_30 ) ;
}
static void F_32 ( const char * V_47 )
{
printf ( L_35 , V_47 ) ;
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
}
int main ( int V_48 , char * * V_49 )
{
const char * V_47 = V_49 [ 0 ] ;
int V_50 ;
const char * V_23 , * V_51 = NULL ;
struct V_52 V_53 ;
setlocale ( V_54 , L_9 ) ;
F_33 ( V_55 , V_56 ) ;
F_34 ( V_55 ) ;
while ( ( V_50 = F_35 ( V_48 , V_49 , L_9 , V_57 , NULL ) ) != - 1 ) {
V_12 = (enum V_12 ) V_50 ;
switch ( V_50 ) {
case V_14 :
V_58 = 1 ;
break;
case V_59 :
case V_60 :
V_51 = V_61 ;
break;
case V_62 :
{
struct V_63 V_64 ;
unsigned int V_65 ;
F_36 ( & V_64 , NULL ) ;
V_65 = ( unsigned int ) ( ( V_64 . V_66 + 1 ) * ( V_64 . V_67 + 1 ) ) ;
srand ( V_65 ) ;
break;
}
case V_15 :
case V_13 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_39 :
case V_40 :
break;
case '?' :
F_32 ( V_47 ) ;
exit ( 1 ) ;
break;
}
}
if ( V_48 == V_72 ) {
printf ( _ ( L_49 ) , V_49 [ 0 ] ) ;
F_32 ( V_47 ) ;
exit ( 1 ) ;
}
V_23 = V_49 [ V_72 ] ;
F_37 ( V_23 ) ;
if ( V_58 ) {
V_23 = F_38 () ;
if ( V_52 ( V_23 , & V_53 ) ) {
fprintf ( V_73 , _ ( L_50
L_51
L_50
L_52
L_53
L_50 ) , V_23 ) ;
exit ( 1 ) ;
}
}
switch ( V_12 ) {
case V_59 :
if ( ! V_51 )
V_51 = F_39 () ;
if ( F_40 ( V_51 ) ) {
printf ( _ ( L_50
L_54
L_50 ) , V_51 ) ;
exit ( 1 ) ;
}
break;
case V_60 :
case V_14 :
case V_15 :
case V_13 :
case V_39 :
case V_40 :
F_40 ( NULL ) ;
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_62 :
V_23 = getenv ( L_55 ) ;
if ( V_23 && ! V_52 ( V_23 , & V_53 ) ) {
F_41 ( V_23 , V_74 ) ;
break;
}
switch ( V_12 ) {
case V_68 : V_23 = L_56 ; break;
case V_69 : V_23 = L_57 ; break;
case V_70 : V_23 = L_58 ; break;
case V_71 : V_23 = L_59 ; break;
case V_62 : V_23 = L_60 ; break;
default: break;
}
if ( ! V_52 ( V_23 , & V_53 ) )
F_41 ( V_23 , V_74 ) ;
else if ( ! V_52 ( L_61 , & V_53 ) )
F_41 ( L_61 , V_74 ) ;
break;
default:
break;
}
if ( V_58 ) {
if ( F_42 () ) {
V_23 = getenv ( L_62 ) ;
if ( V_23 && * V_23 ) {
fprintf ( V_73 ,
_ ( L_63 ) ) ;
return 1 ;
}
}
V_7 = F_43 ( 0 ) && F_43 ( 1 ) && F_43 ( 2 ) ;
}
switch ( V_12 ) {
case V_68 :
F_44 ( V_75 ) ;
break;
case V_69 :
F_44 ( V_76 ) ;
break;
case V_70 :
F_44 ( V_77 ) ;
break;
case V_71 :
F_44 ( V_78 ) ;
break;
case V_62 :
F_44 ( V_79 ) ;
break;
case V_59 :
F_44 ( V_78 ) ;
break;
case V_60 :
break;
case V_15 :
V_41 = & V_80 ;
F_27 ( & V_80 ) ;
V_12 = V_14 ;
case V_13 :
case V_39 :
case V_40 :
case V_14 :
do {
V_46 = 0 ;
F_28 ( & V_80 ) ;
} while ( V_46 &&
( V_12 != V_39 &&
V_12 != V_40 ) );
break;
}
if ( V_58 ) {
if ( F_42 () && F_45 ( NULL ) ) {
fprintf ( V_73 , _ ( L_64 ) ) ;
exit ( 1 ) ;
}
if ( F_46 () ) {
fprintf ( V_73 , _ ( L_65 ) ) ;
return 1 ;
}
} else if ( V_12 == V_60 ) {
if ( F_47 ( V_51 ) ) {
fprintf ( V_73 , _ ( L_66 ) ,
V_51 ) ;
return 1 ;
}
} else if ( V_12 != V_39 ) {
if ( F_45 ( NULL ) ) {
fprintf ( V_73 , _ ( L_64 ) ) ;
exit ( 1 ) ;
}
}
return 0 ;
}
void F_12 ( char * V_4 , int V_81 , T_2 * V_82 )
{
if ( fgets ( V_4 , V_81 , V_82 ) == NULL )
fprintf ( V_73 , L_67 ) ;
}
