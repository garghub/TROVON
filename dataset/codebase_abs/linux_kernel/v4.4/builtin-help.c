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
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_19 = V_17 ;
V_16 . V_20 = - 1 ;
V_16 . V_21 = 1 ;
if ( F_5 ( & V_16 ) ) {
fprintf ( V_22 , L_8 ) ;
return - 1 ;
}
F_6 ( & V_13 , V_16 . V_20 , 20 ) ;
F_7 ( V_16 . V_20 ) ;
F_8 ( & V_16 ) ;
if ( F_9 ( V_13 . V_23 , L_6 ) ) {
fprintf ( V_22 , L_9 ) ;
F_10 ( & V_13 ) ;
return - 1 ;
}
F_11 ( & V_13 , 0 , strlen ( L_6 ) ) ;
V_18 = atoi ( V_13 . V_23 ) ;
if ( V_18 < 22 ) {
fprintf ( V_22 ,
L_10 ,
V_18 ) ;
F_10 ( & V_13 ) ;
return - 1 ;
}
F_10 ( & V_13 ) ;
return 0 ;
}
static void F_12 ( const char * V_24 , const char * V_25 )
{
char V_26 [ V_27 ] ;
if ( ! F_4 () ) {
struct V_12 V_28 = V_14 ;
if ( ! V_24 )
V_24 = L_6 ;
F_13 ( & V_28 , L_11 , V_25 ) ;
F_14 ( V_24 , L_6 , L_12 , V_28 . V_23 , NULL ) ;
F_15 ( L_13 , V_24 ,
F_16 ( V_29 , V_26 , sizeof( V_26 ) ) ) ;
}
}
static void F_17 ( const char * V_24 , const char * V_25 )
{
const char * V_30 = getenv ( L_14 ) ;
if ( V_30 && * V_30 ) {
struct V_12 V_28 = V_14 ;
const char * V_31 = L_15 ;
char V_26 [ V_27 ] ;
if ( V_24 ) {
const char * V_32 = strrchr ( V_24 , '/' ) ;
if ( V_32 && ! strcmp ( V_32 + 1 , L_16 ) ) {
char * V_33 = F_18 ( V_24 ) ;
char * V_34 = strrchr ( V_33 , '/' ) ;
strcpy ( V_34 + 1 , L_15 ) ;
V_24 = V_33 ;
}
if ( V_32 )
V_31 = V_32 ;
} else
V_24 = L_15 ;
F_13 ( & V_28 , L_17 , V_25 ) ;
F_14 ( V_24 , V_31 , L_18 , V_28 . V_23 , NULL ) ;
F_15 ( L_13 , V_24 ,
F_16 ( V_29 , V_26 , sizeof( V_26 ) ) ) ;
}
}
static void F_19 ( const char * V_24 , const char * V_25 )
{
char V_26 [ V_27 ] ;
if ( ! V_24 )
V_24 = L_1 ;
F_14 ( V_24 , L_1 , V_25 , NULL ) ;
F_15 ( L_13 , V_24 ,
F_16 ( V_29 , V_26 , sizeof( V_26 ) ) ) ;
}
static void F_20 ( const char * V_35 , const char * V_25 )
{
struct V_12 V_36 = V_14 ;
char V_26 [ V_27 ] ;
F_13 ( & V_36 , L_19 , V_35 , V_25 ) ;
F_21 ( L_20 , L_21 , L_22 , V_36 . V_23 , NULL ) ;
F_15 ( L_13 , V_35 ,
F_16 ( V_29 , V_26 , sizeof( V_26 ) ) ) ;
}
static void F_22 ( const char * V_7 )
{
struct V_37 * * V_38 = & V_37 ;
T_1 V_39 = strlen ( V_7 ) ;
while ( * V_38 )
V_38 = & ( ( * V_38 ) -> V_10 ) ;
* V_38 = F_23 ( sizeof( * * V_38 ) + V_39 + 1 ) ;
strncpy ( ( * V_38 ) -> V_7 , V_7 , V_39 ) ;
}
static int F_24 ( const char * V_7 , T_1 V_39 )
{
return ( ! strncasecmp ( L_1 , V_7 , V_39 ) ||
! strncasecmp ( L_23 , V_7 , V_39 ) ||
! strncasecmp ( L_16 , V_7 , V_39 ) ) ;
}
static void F_25 ( const char * V_7 ,
T_1 V_39 ,
const char * V_40 )
{
struct V_8 * V_33 = F_23 ( sizeof( * V_33 ) + V_39 + 1 ) ;
strncpy ( V_33 -> V_7 , V_7 , V_39 ) ;
V_33 -> V_11 = F_18 ( V_40 ) ;
V_33 -> V_10 = V_8 ;
V_8 = V_33 ;
}
static int F_26 ( const char * V_7 ,
T_1 V_39 ,
const char * V_40 )
{
if ( F_24 ( V_7 , V_39 ) )
F_25 ( V_7 , V_39 , V_40 ) ;
else
F_15 ( L_24
L_25 ,
V_7 ) ;
return 0 ;
}
static int F_27 ( const char * V_7 ,
T_1 V_39 ,
const char * V_40 )
{
if ( F_24 ( V_7 , V_39 ) )
F_15 ( L_26
L_27 ,
V_7 ) ;
else
F_25 ( V_7 , V_39 , V_40 ) ;
return 0 ;
}
static int F_28 ( const char * V_41 , const char * V_40 )
{
const char * V_7 = V_41 + 4 ;
const char * V_42 = strrchr ( V_7 , '.' ) ;
if ( ! V_42 )
return error ( L_28 , V_7 ) ;
if ( ! strcmp ( V_42 , L_29 ) ) {
if ( ! V_40 )
return F_29 ( V_41 ) ;
return F_26 ( V_7 , V_42 - V_7 , V_40 ) ;
}
if ( ! strcmp ( V_42 , L_30 ) ) {
if ( ! V_40 )
return F_29 ( V_41 ) ;
return F_27 ( V_7 , V_42 - V_7 , V_40 ) ;
}
F_15 ( L_31 , V_42 ) ;
return 0 ;
}
static int F_30 ( const char * V_41 , const char * V_40 , void * V_43 )
{
enum V_1 * V_44 = V_43 ;
if ( ! strcmp ( V_41 , L_32 ) ) {
if ( ! V_40 )
return F_29 ( V_41 ) ;
* V_44 = F_1 ( V_40 ) ;
if ( * V_44 == V_6 )
return - 1 ;
return 0 ;
}
if ( ! strcmp ( V_41 , L_33 ) ) {
if ( ! V_40 )
return F_29 ( V_41 ) ;
F_22 ( V_40 ) ;
return 0 ;
}
if ( ! F_9 ( V_41 , L_34 ) )
return F_28 ( V_41 , V_40 ) ;
return F_31 ( V_41 , V_40 , V_43 ) ;
}
void F_32 ( void )
{
unsigned int V_45 , V_46 = 0 ;
for ( V_45 = 0 ; V_45 < F_33 ( V_47 ) ; V_45 ++ ) {
if ( V_46 < strlen ( V_47 [ V_45 ] . V_7 ) )
V_46 = strlen ( V_47 [ V_45 ] . V_7 ) ;
}
puts ( L_35 ) ;
for ( V_45 = 0 ; V_45 < F_33 ( V_47 ) ; V_45 ++ ) {
printf ( L_36 , V_46 , V_47 [ V_45 ] . V_7 ) ;
puts ( V_47 [ V_45 ] . V_48 ) ;
}
}
static int F_34 ( const char * V_49 )
{
return F_35 ( & V_50 , V_49 ) ||
F_35 ( & V_51 , V_49 ) ;
}
static const char * F_36 ( const char * V_52 , const char * V_35 )
{
T_1 V_53 = strlen ( V_52 ) ;
T_1 V_54 = strlen ( V_35 ) ;
char * V_38 = malloc ( V_53 + V_54 + 1 ) ;
memcpy ( V_38 , V_52 , V_53 ) ;
strcpy ( V_38 + V_53 , V_35 ) ;
return V_38 ;
}
static const char * F_37 ( const char * V_55 )
{
if ( ! V_55 )
return L_37 ;
else if ( ! F_9 ( V_55 , L_37 ) )
return V_55 ;
else
return F_36 ( L_38 , V_55 ) ;
}
static void F_38 ( void )
{
struct V_12 V_56 = V_14 ;
const char * V_57 = getenv ( L_39 ) ;
F_39 ( & V_56 , F_40 ( V_58 ) ) ;
F_41 ( & V_56 , ':' ) ;
if ( V_57 )
F_39 ( & V_56 , V_57 ) ;
F_42 ( L_39 , V_56 . V_23 , 1 ) ;
F_10 ( & V_56 ) ;
}
static void F_43 ( const char * V_7 , const char * V_25 )
{
const char * V_11 = F_3 ( V_7 ) ;
if ( ! strcasecmp ( V_7 , L_1 ) )
F_19 ( V_11 , V_25 ) ;
else if ( ! strcasecmp ( V_7 , L_23 ) )
F_12 ( V_11 , V_25 ) ;
else if ( ! strcasecmp ( V_7 , L_16 ) )
F_17 ( V_11 , V_25 ) ;
else if ( V_11 )
F_20 ( V_11 , V_25 ) ;
else
F_15 ( L_40 , V_7 ) ;
}
static int F_44 ( const char * V_55 )
{
struct V_37 * V_9 ;
const char * V_25 = F_37 ( V_55 ) ;
const char * V_59 = getenv ( L_41 ) ;
F_38 () ;
for ( V_9 = V_37 ; V_9 ; V_9 = V_9 -> V_10 )
F_43 ( V_9 -> V_7 , V_25 ) ;
if ( V_59 )
F_43 ( V_59 , V_25 ) ;
F_43 ( L_1 , V_25 ) ;
F_2 ( L_42 ) ;
return - 1 ;
}
static int F_45 ( const char * V_55 )
{
const char * V_25 = F_37 ( V_55 ) ;
F_42 ( L_43 , F_40 ( V_60 ) , 1 ) ;
F_14 ( L_2 , L_2 , L_44 , V_25 , NULL ) ;
return - 1 ;
}
static int F_46 ( struct V_12 * V_61 , const char * V_25 )
{
struct V_62 V_63 ;
const char * V_64 = F_40 ( V_65 ) ;
if ( V_62 ( F_47 ( L_45 , V_64 ) , & V_63 )
|| ! F_48 ( V_63 . V_66 ) ) {
F_2 ( L_46 , V_64 ) ;
return - 1 ;
}
F_49 ( V_61 , 0 ) ;
F_13 ( V_61 , L_47 , V_64 , V_25 ) ;
return 0 ;
}
static void F_50 ( const char * V_24 )
{
F_51 ( L_48 , L_22 , L_49 , V_24 , NULL ) ;
}
static int F_52 ( const char * V_55 )
{
const char * V_25 = F_37 ( V_55 ) ;
struct V_12 V_61 ;
if ( F_46 ( & V_61 , V_25 ) != 0 )
return - 1 ;
F_50 ( V_61 . V_23 ) ;
return 0 ;
}
int F_53 ( int V_67 , const char * * V_19 , const char * V_52 V_68 )
{
bool V_69 = false ;
enum V_1 V_1 = V_3 ;
struct V_70 V_71 [] = {
F_54 ( 'a' , L_50 , & V_69 , L_51 ) ,
F_55 ( 'm' , L_1 , & V_1 , L_52 , V_3 ) ,
F_55 ( 'w' , L_3 , & V_1 , L_53 ,
V_5 ) ,
F_55 ( 'i' , L_2 , & V_1 , L_54 ,
V_4 ) ,
F_56 () ,
} ;
const char * const V_72 [] = {
L_55 , L_56 , L_57 , L_58 , L_59 , L_60 ,
L_61 , L_62 , L_63 , L_64 , L_65 , L_66 , L_67 ,
L_68 , L_69 , L_70 , L_71 , L_72 , L_73 , L_74 , L_75 , L_76 ,
#ifdef F_57
L_77 ,
#endif
#ifdef F_58
L_78 ,
#endif
NULL } ;
const char * V_73 [] = {
L_79 ,
NULL
} ;
const char * V_74 ;
int V_75 = 0 ;
F_59 ( L_38 , & V_50 , & V_51 ) ;
F_60 ( F_30 , & V_1 ) ;
V_67 = F_61 ( V_67 , V_19 , V_71 ,
V_72 , V_73 , 0 ) ;
if ( V_69 ) {
printf ( L_80 , V_76 ) ;
F_62 ( L_81 , & V_50 , & V_51 ) ;
printf ( L_82 , V_77 ) ;
return 0 ;
}
if ( ! V_19 [ 0 ] ) {
printf ( L_83 , V_76 ) ;
F_32 () ;
printf ( L_84 , V_77 ) ;
return 0 ;
}
V_74 = F_63 ( V_19 [ 0 ] ) ;
if ( V_74 && ! F_34 ( V_19 [ 0 ] ) ) {
printf ( L_85 , V_19 [ 0 ] , V_74 ) ;
return 0 ;
}
switch ( V_1 ) {
case V_3 :
V_75 = F_44 ( V_19 [ 0 ] ) ;
break;
case V_4 :
V_75 = F_45 ( V_19 [ 0 ] ) ;
break;
case V_5 :
V_75 = F_52 ( V_19 [ 0 ] ) ;
break;
case V_6 :
default:
V_75 = - 1 ;
break;
}
return V_75 ;
}
