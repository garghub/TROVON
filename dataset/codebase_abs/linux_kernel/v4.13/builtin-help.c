static enum V_1 F_1 ( const char * V_2 )
{
if ( ! strcmp ( V_2 , L_1 ) )
return V_3 ;
if ( ! strcmp ( V_2 , L_2 ) )
return V_4 ;
if ( ! strcmp ( V_2 , L_3 ) || ! strcmp ( V_2 , L_4 ) )
return V_5 ;
F_2 ( L_5 , V_2 ) ;
return V_6 ;
}
static const char * F_3 ( const char * V_7 )
{
struct V_8 * V_9 ;
for ( V_9 = V_8 ; V_9 ; V_9 = V_9 -> V_10 ) {
if ( ! strcasecmp ( V_7 , V_9 -> V_7 ) )
return V_9 -> V_11 ;
}
return NULL ;
}
static int F_4 ( void )
{
struct V_12 V_13 = V_14 ;
struct V_15 V_16 ;
const char * V_17 [] = { L_6 , L_7 , NULL } ;
int V_18 ;
int V_19 = - 1 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_20 = V_17 ;
V_16 . V_21 = - 1 ;
V_16 . V_22 = 1 ;
if ( F_5 ( & V_16 ) ) {
fprintf ( V_23 , L_8 ) ;
return - 1 ;
}
if ( F_6 ( & V_13 , V_16 . V_21 , 20 ) < 0 ) {
fprintf ( V_23 , L_9 ) ;
goto V_24;
}
F_7 ( V_16 . V_21 ) ;
F_8 ( & V_16 ) ;
if ( F_9 ( V_13 . V_25 , L_6 ) ) {
fprintf ( V_23 , L_10 ) ;
goto V_24;
}
V_18 = atoi ( V_13 . V_25 + strlen ( L_6 ) ) ;
if ( V_18 < 22 ) {
fprintf ( V_23 ,
L_11 ,
V_18 ) ;
} else
V_19 = 0 ;
V_24:
F_10 ( & V_13 ) ;
return V_19 ;
}
static void F_11 ( const char * V_26 )
{
char V_27 [ V_28 ] ;
F_12 ( L_12 , V_26 , F_13 ( V_29 , V_27 , sizeof( V_27 ) ) ) ;
}
static void F_14 ( const char * V_30 , const char * V_31 )
{
if ( ! F_4 () ) {
char * V_32 ;
if ( ! V_30 )
V_30 = L_6 ;
if ( F_15 ( & V_32 , L_13 , V_31 ) > 0 ) {
F_16 ( V_30 , L_6 , L_14 , V_32 , NULL ) ;
free ( V_32 ) ;
}
F_11 ( V_30 ) ;
}
}
static void F_17 ( const char * V_30 , const char * V_31 )
{
const char * V_33 = getenv ( L_15 ) ;
if ( V_33 && * V_33 ) {
char * V_32 ;
const char * V_34 = L_16 ;
if ( V_30 ) {
const char * V_35 = strrchr ( V_30 , '/' ) ;
if ( V_35 && ! strcmp ( V_35 + 1 , L_17 ) ) {
char * V_36 = F_18 ( V_30 ) ;
char * V_37 = strrchr ( V_36 , '/' ) ;
strcpy ( V_37 + 1 , L_16 ) ;
V_30 = V_36 ;
}
if ( V_35 )
V_34 = V_35 ;
} else
V_30 = L_16 ;
if ( F_15 ( & V_32 , L_18 , V_31 ) > 0 ) {
F_16 ( V_30 , V_34 , L_19 , V_32 , NULL ) ;
free ( V_32 ) ;
}
F_11 ( V_30 ) ;
}
}
static void F_19 ( const char * V_30 , const char * V_31 )
{
if ( ! V_30 )
V_30 = L_1 ;
F_16 ( V_30 , L_1 , V_31 , NULL ) ;
F_11 ( V_30 ) ;
}
static void F_20 ( const char * V_26 , const char * V_31 )
{
char * V_38 ;
if ( F_15 ( & V_38 , L_20 , V_26 , V_31 ) > 0 ) {
F_21 ( L_21 , L_22 , L_23 , V_38 , NULL ) ;
free ( V_38 ) ;
}
F_11 ( V_26 ) ;
}
static void F_22 ( const char * V_7 )
{
struct V_39 * * V_40 = & V_39 ;
T_1 V_41 = strlen ( V_7 ) ;
while ( * V_40 )
V_40 = & ( ( * V_40 ) -> V_10 ) ;
* V_40 = F_23 ( sizeof( * * V_40 ) + V_41 + 1 ) ;
strncpy ( ( * V_40 ) -> V_7 , V_7 , V_41 ) ;
}
static int F_24 ( const char * V_7 , T_1 V_41 )
{
return ( ! strncasecmp ( L_1 , V_7 , V_41 ) ||
! strncasecmp ( L_24 , V_7 , V_41 ) ||
! strncasecmp ( L_17 , V_7 , V_41 ) ) ;
}
static void F_25 ( const char * V_7 ,
T_1 V_41 ,
const char * V_42 )
{
struct V_8 * V_36 = F_23 ( sizeof( * V_36 ) + V_41 + 1 ) ;
strncpy ( V_36 -> V_7 , V_7 , V_41 ) ;
V_36 -> V_11 = F_18 ( V_42 ) ;
V_36 -> V_10 = V_8 ;
V_8 = V_36 ;
}
static void F_26 ( const char * V_7 , const char * V_43 )
{
F_12 ( L_25
L_26 , V_7 , V_43 ) ;
}
static int F_27 ( const char * V_7 ,
T_1 V_41 ,
const char * V_42 )
{
if ( F_24 ( V_7 , V_41 ) )
F_25 ( V_7 , V_41 , V_42 ) ;
else
F_26 ( V_7 , L_27 ) ;
return 0 ;
}
static int F_28 ( const char * V_7 ,
T_1 V_41 ,
const char * V_42 )
{
if ( F_24 ( V_7 , V_41 ) )
F_26 ( V_7 , L_28 ) ;
else
F_25 ( V_7 , V_41 , V_42 ) ;
return 0 ;
}
static int F_29 ( const char * V_43 , const char * V_42 )
{
const char * V_7 = V_43 + 4 ;
const char * V_44 = strrchr ( V_7 , '.' ) ;
if ( ! V_44 ) {
F_2 ( L_29 , V_7 ) ;
return - 1 ;
}
if ( ! strcmp ( V_44 , L_30 ) ) {
if ( ! V_42 )
return F_30 ( V_43 ) ;
return F_27 ( V_7 , V_44 - V_7 , V_42 ) ;
}
if ( ! strcmp ( V_44 , L_31 ) ) {
if ( ! V_42 )
return F_30 ( V_43 ) ;
return F_28 ( V_7 , V_44 - V_7 , V_42 ) ;
}
F_12 ( L_32 , V_44 ) ;
return 0 ;
}
static int F_31 ( const char * V_43 , const char * V_42 , void * V_45 )
{
enum V_1 * V_46 = V_45 ;
if ( ! strcmp ( V_43 , L_33 ) ) {
if ( ! V_42 )
return F_30 ( V_43 ) ;
* V_46 = F_1 ( V_42 ) ;
if ( * V_46 == V_6 )
return - 1 ;
return 0 ;
}
if ( ! strcmp ( V_43 , L_34 ) ) {
if ( ! V_42 )
return F_30 ( V_43 ) ;
F_22 ( V_42 ) ;
return 0 ;
}
if ( ! F_9 ( V_43 , L_35 ) )
return F_29 ( V_43 , V_42 ) ;
return 0 ;
}
void F_32 ( void )
{
unsigned int V_47 , V_48 = 0 ;
for ( V_47 = 0 ; V_47 < F_33 ( V_49 ) ; V_47 ++ ) {
if ( V_48 < strlen ( V_49 [ V_47 ] . V_7 ) )
V_48 = strlen ( V_49 [ V_47 ] . V_7 ) ;
}
puts ( L_36 ) ;
for ( V_47 = 0 ; V_47 < F_33 ( V_49 ) ; V_47 ++ ) {
printf ( L_37 , V_48 , V_49 [ V_47 ] . V_7 ) ;
puts ( V_49 [ V_47 ] . V_50 ) ;
}
}
static const char * F_34 ( const char * V_51 )
{
char * V_52 ;
if ( ! V_51 )
return L_38 ;
else if ( ! F_9 ( V_51 , L_38 ) )
return V_51 ;
return F_15 ( & V_52 , L_39 , V_51 ) < 0 ? NULL : V_52 ;
}
static void F_35 ( void )
{
char * V_53 ;
const char * V_54 = getenv ( L_40 ) ;
if ( F_15 ( & V_53 , L_41 , F_36 ( V_55 ) , V_54 ? : L_42 ) > 0 ) {
F_37 ( L_40 , V_53 , 1 ) ;
free ( V_53 ) ;
} else {
F_2 ( L_43 ) ;
}
}
static void F_38 ( const char * V_7 , const char * V_31 )
{
const char * V_11 = F_3 ( V_7 ) ;
if ( ! strcasecmp ( V_7 , L_1 ) )
F_19 ( V_11 , V_31 ) ;
else if ( ! strcasecmp ( V_7 , L_24 ) )
F_14 ( V_11 , V_31 ) ;
else if ( ! strcasecmp ( V_7 , L_17 ) )
F_17 ( V_11 , V_31 ) ;
else if ( V_11 )
F_20 ( V_11 , V_31 ) ;
else
F_12 ( L_44 , V_7 ) ;
}
static int F_39 ( const char * V_51 )
{
struct V_39 * V_9 ;
const char * V_31 = F_34 ( V_51 ) ;
const char * V_56 = getenv ( L_45 ) ;
F_35 () ;
for ( V_9 = V_39 ; V_9 ; V_9 = V_9 -> V_10 )
F_38 ( V_9 -> V_7 , V_31 ) ;
if ( V_56 )
F_38 ( V_56 , V_31 ) ;
F_38 ( L_1 , V_31 ) ;
F_2 ( L_46 ) ;
return - 1 ;
}
static int F_40 ( const char * V_51 )
{
const char * V_31 = F_34 ( V_51 ) ;
F_37 ( L_47 , F_36 ( V_57 ) , 1 ) ;
F_16 ( L_2 , L_2 , L_48 , V_31 , NULL ) ;
return - 1 ;
}
static int F_41 ( char * * V_58 , const char * V_31 )
{
struct V_59 V_60 ;
const char * V_61 = F_36 ( V_62 ) ;
if ( V_59 ( F_42 ( L_49 , V_61 ) , & V_60 )
|| ! F_43 ( V_60 . V_63 ) ) {
F_2 ( L_50 , V_61 ) ;
return - 1 ;
}
return F_15 ( V_58 , L_51 , V_61 , V_31 ) ;
}
static void F_44 ( const char * V_30 )
{
F_45 ( L_52 , L_23 , L_53 , V_30 , NULL ) ;
}
static int F_46 ( const char * V_51 )
{
const char * V_31 = F_34 ( V_51 ) ;
char * V_58 ;
if ( F_41 ( & V_58 , V_31 ) < 0 )
return - 1 ;
F_44 ( V_58 ) ;
return 0 ;
}
int F_47 ( int V_64 , const char * * V_20 )
{
bool V_65 = false ;
enum V_1 V_1 = V_3 ;
struct V_66 V_67 [] = {
F_48 ( 'a' , L_54 , & V_65 , L_55 ) ,
F_49 ( 'm' , L_1 , & V_1 , L_56 , V_3 ) ,
F_49 ( 'w' , L_3 , & V_1 , L_57 ,
V_5 ) ,
F_49 ( 'i' , L_2 , & V_1 , L_58 ,
V_4 ) ,
F_50 () ,
} ;
const char * const V_68 [] = {
L_59 , L_60 , L_61 , L_62 , L_63 , L_64 ,
L_65 , L_66 , L_67 , L_68 , L_69 , L_70 , L_71 ,
L_72 , L_73 , L_74 , L_75 , L_76 , L_77 , L_78 , L_79 , L_80 , L_81 ,
#ifdef F_51
L_82 ,
#endif
#ifdef F_52
L_83 ,
#endif
NULL } ;
const char * V_69 [] = {
L_84 ,
NULL
} ;
int V_70 ;
F_53 ( L_85 , & V_71 , & V_72 ) ;
V_70 = F_54 ( F_31 , & V_1 ) ;
if ( V_70 )
return V_70 ;
V_64 = F_55 ( V_64 , V_20 , V_67 ,
V_68 , V_69 , 0 ) ;
if ( V_65 ) {
printf ( L_86 , V_73 ) ;
F_56 ( L_87 , & V_71 , & V_72 ) ;
printf ( L_88 , V_74 ) ;
return 0 ;
}
if ( ! V_20 [ 0 ] ) {
printf ( L_89 , V_73 ) ;
F_32 () ;
printf ( L_90 , V_74 ) ;
return 0 ;
}
switch ( V_1 ) {
case V_3 :
V_70 = F_39 ( V_20 [ 0 ] ) ;
break;
case V_4 :
V_70 = F_40 ( V_20 [ 0 ] ) ;
break;
case V_5 :
V_70 = F_46 ( V_20 [ 0 ] ) ;
break;
case V_6 :
default:
V_70 = - 1 ;
break;
}
return V_70 ;
}
