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
if ( ! F_4 () ) {
struct V_12 V_26 = V_14 ;
if ( ! V_24 )
V_24 = L_6 ;
F_13 ( & V_26 , L_11 , V_25 ) ;
F_14 ( V_24 , L_6 , L_12 , V_26 . V_23 , NULL ) ;
F_15 ( L_13 , V_24 , strerror ( V_27 ) ) ;
}
}
static void F_16 ( const char * V_24 , const char * V_25 )
{
const char * V_28 = getenv ( L_14 ) ;
if ( V_28 && * V_28 ) {
struct V_12 V_26 = V_14 ;
const char * V_29 = L_15 ;
if ( V_24 ) {
const char * V_30 = strrchr ( V_24 , '/' ) ;
if ( V_30 && ! strcmp ( V_30 + 1 , L_16 ) ) {
char * V_31 = F_17 ( V_24 ) ;
char * V_32 = strrchr ( V_31 , '/' ) ;
strcpy ( V_32 + 1 , L_15 ) ;
V_24 = V_31 ;
}
if ( V_30 )
V_29 = V_30 ;
} else
V_24 = L_15 ;
F_13 ( & V_26 , L_17 , V_25 ) ;
F_14 ( V_24 , V_29 , L_18 , V_26 . V_23 , NULL ) ;
F_15 ( L_13 , V_24 , strerror ( V_27 ) ) ;
}
}
static void F_18 ( const char * V_24 , const char * V_25 )
{
if ( ! V_24 )
V_24 = L_1 ;
F_14 ( V_24 , L_1 , V_25 , NULL ) ;
F_15 ( L_13 , V_24 , strerror ( V_27 ) ) ;
}
static void F_19 ( const char * V_33 , const char * V_25 )
{
struct V_12 V_34 = V_14 ;
F_13 ( & V_34 , L_19 , V_33 , V_25 ) ;
F_20 ( L_20 , L_21 , L_22 , V_34 . V_23 , NULL ) ;
F_15 ( L_13 , V_33 , strerror ( V_27 ) ) ;
}
static void F_21 ( const char * V_7 )
{
struct V_35 * * V_36 = & V_35 ;
T_1 V_37 = strlen ( V_7 ) ;
while ( * V_36 )
V_36 = & ( ( * V_36 ) -> V_10 ) ;
* V_36 = F_22 ( sizeof( * * V_36 ) + V_37 + 1 ) ;
strncpy ( ( * V_36 ) -> V_7 , V_7 , V_37 ) ;
}
static int F_23 ( const char * V_7 , T_1 V_37 )
{
return ( ! strncasecmp ( L_1 , V_7 , V_37 ) ||
! strncasecmp ( L_23 , V_7 , V_37 ) ||
! strncasecmp ( L_16 , V_7 , V_37 ) ) ;
}
static void F_24 ( const char * V_7 ,
T_1 V_37 ,
const char * V_38 )
{
struct V_8 * V_31 = F_22 ( sizeof( * V_31 ) + V_37 + 1 ) ;
strncpy ( V_31 -> V_7 , V_7 , V_37 ) ;
V_31 -> V_11 = F_17 ( V_38 ) ;
V_31 -> V_10 = V_8 ;
V_8 = V_31 ;
}
static int F_25 ( const char * V_7 ,
T_1 V_37 ,
const char * V_38 )
{
if ( F_23 ( V_7 , V_37 ) )
F_24 ( V_7 , V_37 , V_38 ) ;
else
F_15 ( L_24
L_25 ,
V_7 ) ;
return 0 ;
}
static int F_26 ( const char * V_7 ,
T_1 V_37 ,
const char * V_38 )
{
if ( F_23 ( V_7 , V_37 ) )
F_15 ( L_26
L_27 ,
V_7 ) ;
else
F_24 ( V_7 , V_37 , V_38 ) ;
return 0 ;
}
static int F_27 ( const char * V_39 , const char * V_38 )
{
const char * V_7 = V_39 + 4 ;
const char * V_40 = strrchr ( V_7 , '.' ) ;
if ( ! V_40 )
return error ( L_28 , V_7 ) ;
if ( ! strcmp ( V_40 , L_29 ) ) {
if ( ! V_38 )
return F_28 ( V_39 ) ;
return F_25 ( V_7 , V_40 - V_7 , V_38 ) ;
}
if ( ! strcmp ( V_40 , L_30 ) ) {
if ( ! V_38 )
return F_28 ( V_39 ) ;
return F_26 ( V_7 , V_40 - V_7 , V_38 ) ;
}
F_15 ( L_31 , V_40 ) ;
return 0 ;
}
static int F_29 ( const char * V_39 , const char * V_38 , void * V_41 )
{
enum V_1 * V_42 = V_41 ;
if ( ! strcmp ( V_39 , L_32 ) ) {
if ( ! V_38 )
return F_28 ( V_39 ) ;
* V_42 = F_1 ( V_38 ) ;
if ( * V_42 == V_6 )
return - 1 ;
return 0 ;
}
if ( ! strcmp ( V_39 , L_33 ) ) {
if ( ! V_38 )
return F_28 ( V_39 ) ;
F_21 ( V_38 ) ;
return 0 ;
}
if ( ! F_9 ( V_39 , L_34 ) )
return F_27 ( V_39 , V_38 ) ;
return F_30 ( V_39 , V_38 , V_41 ) ;
}
void F_31 ( void )
{
unsigned int V_43 , V_44 = 0 ;
for ( V_43 = 0 ; V_43 < F_32 ( V_45 ) ; V_43 ++ ) {
if ( V_44 < strlen ( V_45 [ V_43 ] . V_7 ) )
V_44 = strlen ( V_45 [ V_43 ] . V_7 ) ;
}
puts ( L_35 ) ;
for ( V_43 = 0 ; V_43 < F_32 ( V_45 ) ; V_43 ++ ) {
printf ( L_36 , V_44 , V_45 [ V_43 ] . V_7 ) ;
puts ( V_45 [ V_43 ] . V_46 ) ;
}
}
static int F_33 ( const char * V_47 )
{
return F_34 ( & V_48 , V_47 ) ||
F_34 ( & V_49 , V_47 ) ;
}
static const char * F_35 ( const char * V_50 , const char * V_33 )
{
T_1 V_51 = strlen ( V_50 ) ;
T_1 V_52 = strlen ( V_33 ) ;
char * V_36 = malloc ( V_51 + V_52 + 1 ) ;
memcpy ( V_36 , V_50 , V_51 ) ;
strcpy ( V_36 + V_51 , V_33 ) ;
return V_36 ;
}
static const char * F_36 ( const char * V_53 )
{
if ( ! V_53 )
return L_37 ;
else if ( ! F_9 ( V_53 , L_37 ) )
return V_53 ;
else
return F_35 ( L_38 , V_53 ) ;
}
static void F_37 ( void )
{
struct V_12 V_54 = V_14 ;
const char * V_55 = getenv ( L_39 ) ;
F_38 ( & V_54 , F_39 ( V_56 ) ) ;
F_40 ( & V_54 , ':' ) ;
if ( V_55 )
F_38 ( & V_54 , V_55 ) ;
F_41 ( L_39 , V_54 . V_23 , 1 ) ;
F_10 ( & V_54 ) ;
}
static void F_42 ( const char * V_7 , const char * V_25 )
{
const char * V_11 = F_3 ( V_7 ) ;
if ( ! strcasecmp ( V_7 , L_1 ) )
F_18 ( V_11 , V_25 ) ;
else if ( ! strcasecmp ( V_7 , L_23 ) )
F_12 ( V_11 , V_25 ) ;
else if ( ! strcasecmp ( V_7 , L_16 ) )
F_16 ( V_11 , V_25 ) ;
else if ( V_11 )
F_19 ( V_11 , V_25 ) ;
else
F_15 ( L_40 , V_7 ) ;
}
static int F_43 ( const char * V_53 )
{
struct V_35 * V_9 ;
const char * V_25 = F_36 ( V_53 ) ;
const char * V_57 = getenv ( L_41 ) ;
F_37 () ;
for ( V_9 = V_35 ; V_9 ; V_9 = V_9 -> V_10 )
F_42 ( V_9 -> V_7 , V_25 ) ;
if ( V_57 )
F_42 ( V_57 , V_25 ) ;
F_42 ( L_1 , V_25 ) ;
F_2 ( L_42 ) ;
return - 1 ;
}
static int F_44 ( const char * V_53 )
{
const char * V_25 = F_36 ( V_53 ) ;
F_41 ( L_43 , F_39 ( V_58 ) , 1 ) ;
F_14 ( L_2 , L_2 , L_44 , V_25 , NULL ) ;
return - 1 ;
}
static int F_45 ( struct V_12 * V_59 , const char * V_25 )
{
struct V_60 V_61 ;
const char * V_62 = F_39 ( V_63 ) ;
if ( V_60 ( F_46 ( L_45 , V_62 ) , & V_61 )
|| ! F_47 ( V_61 . V_64 ) ) {
F_2 ( L_46 , V_62 ) ;
return - 1 ;
}
F_48 ( V_59 , 0 ) ;
F_13 ( V_59 , L_47 , V_62 , V_25 ) ;
return 0 ;
}
static void F_49 ( const char * V_24 )
{
F_50 ( L_48 , L_22 , L_49 , V_24 , NULL ) ;
}
static int F_51 ( const char * V_53 )
{
const char * V_25 = F_36 ( V_53 ) ;
struct V_12 V_59 ;
if ( F_45 ( & V_59 , V_25 ) != 0 )
return - 1 ;
F_49 ( V_59 . V_23 ) ;
return 0 ;
}
int F_52 ( int V_65 , const char * * V_19 , const char * V_50 V_66 )
{
bool V_67 = false ;
enum V_1 V_1 = V_3 ;
struct V_68 V_69 [] = {
F_53 ( 'a' , L_50 , & V_67 , L_51 ) ,
F_54 ( 'm' , L_1 , & V_1 , L_52 , V_3 ) ,
F_54 ( 'w' , L_3 , & V_1 , L_53 ,
V_5 ) ,
F_54 ( 'i' , L_2 , & V_1 , L_54 ,
V_4 ) ,
F_55 () ,
} ;
const char * const V_70 [] = {
L_55 ,
NULL
} ;
const char * V_71 ;
int V_72 = 0 ;
F_56 ( L_38 , & V_48 , & V_49 ) ;
F_57 ( F_29 , & V_1 ) ;
V_65 = F_58 ( V_65 , V_19 , V_69 ,
V_70 , 0 ) ;
if ( V_67 ) {
printf ( L_56 , V_73 ) ;
F_59 ( L_57 , & V_48 , & V_49 ) ;
printf ( L_58 , V_74 ) ;
return 0 ;
}
if ( ! V_19 [ 0 ] ) {
printf ( L_56 , V_73 ) ;
F_31 () ;
printf ( L_59 , V_74 ) ;
return 0 ;
}
V_71 = F_60 ( V_19 [ 0 ] ) ;
if ( V_71 && ! F_33 ( V_19 [ 0 ] ) ) {
printf ( L_60 , V_19 [ 0 ] , V_71 ) ;
return 0 ;
}
switch ( V_1 ) {
case V_3 :
V_72 = F_43 ( V_19 [ 0 ] ) ;
break;
case V_4 :
V_72 = F_44 ( V_19 [ 0 ] ) ;
break;
case V_5 :
V_72 = F_51 ( V_19 [ 0 ] ) ;
break;
case V_6 :
default:
V_72 = - 1 ;
break;
}
return V_72 ;
}
