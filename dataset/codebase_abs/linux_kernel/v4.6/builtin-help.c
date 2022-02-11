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
V_18 = atoi ( V_13 . V_23 + strlen ( L_6 ) ) ;
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
static void F_11 ( const char * V_24 , const char * V_25 )
{
char V_26 [ V_27 ] ;
if ( ! F_4 () ) {
char * V_28 ;
if ( ! V_24 )
V_24 = L_6 ;
if ( F_12 ( & V_28 , L_11 , V_25 ) > 0 ) {
F_13 ( V_24 , L_6 , L_12 , V_28 , NULL ) ;
free ( V_28 ) ;
}
F_14 ( L_13 , V_24 ,
F_15 ( V_29 , V_26 , sizeof( V_26 ) ) ) ;
}
}
static void F_16 ( const char * V_24 , const char * V_25 )
{
const char * V_30 = getenv ( L_14 ) ;
if ( V_30 && * V_30 ) {
char * V_28 ;
const char * V_31 = L_15 ;
char V_26 [ V_27 ] ;
if ( V_24 ) {
const char * V_32 = strrchr ( V_24 , '/' ) ;
if ( V_32 && ! strcmp ( V_32 + 1 , L_16 ) ) {
char * V_33 = F_17 ( V_24 ) ;
char * V_34 = strrchr ( V_33 , '/' ) ;
strcpy ( V_34 + 1 , L_15 ) ;
V_24 = V_33 ;
}
if ( V_32 )
V_31 = V_32 ;
} else
V_24 = L_15 ;
if ( F_12 ( & V_28 , L_17 , V_25 ) > 0 ) {
F_13 ( V_24 , V_31 , L_18 , V_28 , NULL ) ;
free ( V_28 ) ;
}
F_14 ( L_13 , V_24 ,
F_15 ( V_29 , V_26 , sizeof( V_26 ) ) ) ;
}
}
static void F_18 ( const char * V_24 , const char * V_25 )
{
char V_26 [ V_27 ] ;
if ( ! V_24 )
V_24 = L_1 ;
F_13 ( V_24 , L_1 , V_25 , NULL ) ;
F_14 ( L_13 , V_24 ,
F_15 ( V_29 , V_26 , sizeof( V_26 ) ) ) ;
}
static void F_19 ( const char * V_35 , const char * V_25 )
{
char V_26 [ V_27 ] ;
char * V_36 ;
if ( F_12 ( & V_36 , L_19 , V_35 , V_25 ) > 0 ) {
F_20 ( L_20 , L_21 , L_22 , V_36 , NULL ) ;
free ( V_36 ) ;
}
F_14 ( L_13 , V_35 ,
F_15 ( V_29 , V_26 , sizeof( V_26 ) ) ) ;
}
static void F_21 ( const char * V_7 )
{
struct V_37 * * V_38 = & V_37 ;
T_1 V_39 = strlen ( V_7 ) ;
while ( * V_38 )
V_38 = & ( ( * V_38 ) -> V_10 ) ;
* V_38 = F_22 ( sizeof( * * V_38 ) + V_39 + 1 ) ;
strncpy ( ( * V_38 ) -> V_7 , V_7 , V_39 ) ;
}
static int F_23 ( const char * V_7 , T_1 V_39 )
{
return ( ! strncasecmp ( L_1 , V_7 , V_39 ) ||
! strncasecmp ( L_23 , V_7 , V_39 ) ||
! strncasecmp ( L_16 , V_7 , V_39 ) ) ;
}
static void F_24 ( const char * V_7 ,
T_1 V_39 ,
const char * V_40 )
{
struct V_8 * V_33 = F_22 ( sizeof( * V_33 ) + V_39 + 1 ) ;
strncpy ( V_33 -> V_7 , V_7 , V_39 ) ;
V_33 -> V_11 = F_17 ( V_40 ) ;
V_33 -> V_10 = V_8 ;
V_8 = V_33 ;
}
static int F_25 ( const char * V_7 ,
T_1 V_39 ,
const char * V_40 )
{
if ( F_23 ( V_7 , V_39 ) )
F_24 ( V_7 , V_39 , V_40 ) ;
else
F_14 ( L_24
L_25 ,
V_7 ) ;
return 0 ;
}
static int F_26 ( const char * V_7 ,
T_1 V_39 ,
const char * V_40 )
{
if ( F_23 ( V_7 , V_39 ) )
F_14 ( L_26
L_27 ,
V_7 ) ;
else
F_24 ( V_7 , V_39 , V_40 ) ;
return 0 ;
}
static int F_27 ( const char * V_41 , const char * V_40 )
{
const char * V_7 = V_41 + 4 ;
const char * V_42 = strrchr ( V_7 , '.' ) ;
if ( ! V_42 )
return error ( L_28 , V_7 ) ;
if ( ! strcmp ( V_42 , L_29 ) ) {
if ( ! V_40 )
return F_28 ( V_41 ) ;
return F_25 ( V_7 , V_42 - V_7 , V_40 ) ;
}
if ( ! strcmp ( V_42 , L_30 ) ) {
if ( ! V_40 )
return F_28 ( V_41 ) ;
return F_26 ( V_7 , V_42 - V_7 , V_40 ) ;
}
F_14 ( L_31 , V_42 ) ;
return 0 ;
}
static int F_29 ( const char * V_41 , const char * V_40 , void * V_43 )
{
enum V_1 * V_44 = V_43 ;
if ( ! strcmp ( V_41 , L_32 ) ) {
if ( ! V_40 )
return F_28 ( V_41 ) ;
* V_44 = F_1 ( V_40 ) ;
if ( * V_44 == V_6 )
return - 1 ;
return 0 ;
}
if ( ! strcmp ( V_41 , L_33 ) ) {
if ( ! V_40 )
return F_28 ( V_41 ) ;
F_21 ( V_40 ) ;
return 0 ;
}
if ( ! F_9 ( V_41 , L_34 ) )
return F_27 ( V_41 , V_40 ) ;
return 0 ;
}
void F_30 ( void )
{
unsigned int V_45 , V_46 = 0 ;
for ( V_45 = 0 ; V_45 < F_31 ( V_47 ) ; V_45 ++ ) {
if ( V_46 < strlen ( V_47 [ V_45 ] . V_7 ) )
V_46 = strlen ( V_47 [ V_45 ] . V_7 ) ;
}
puts ( L_35 ) ;
for ( V_45 = 0 ; V_45 < F_31 ( V_47 ) ; V_45 ++ ) {
printf ( L_36 , V_46 , V_47 [ V_45 ] . V_7 ) ;
puts ( V_47 [ V_45 ] . V_48 ) ;
}
}
static int F_32 ( const char * V_49 )
{
return F_33 ( & V_50 , V_49 ) ||
F_33 ( & V_51 , V_49 ) ;
}
static const char * F_34 ( const char * V_52 )
{
char * V_49 ;
if ( ! V_52 )
return L_37 ;
else if ( ! F_9 ( V_52 , L_37 ) )
return V_52 ;
return F_12 ( & V_49 , L_38 , V_52 ) < 0 ? NULL : V_49 ;
}
static void F_35 ( void )
{
char * V_53 ;
const char * V_54 = getenv ( L_39 ) ;
if ( F_12 ( & V_53 , L_40 , F_36 ( V_55 ) , V_54 ? : L_41 ) > 0 ) {
F_37 ( L_39 , V_53 , 1 ) ;
free ( V_53 ) ;
} else {
error ( L_42 ) ;
}
}
static void F_38 ( const char * V_7 , const char * V_25 )
{
const char * V_11 = F_3 ( V_7 ) ;
if ( ! strcasecmp ( V_7 , L_1 ) )
F_18 ( V_11 , V_25 ) ;
else if ( ! strcasecmp ( V_7 , L_23 ) )
F_11 ( V_11 , V_25 ) ;
else if ( ! strcasecmp ( V_7 , L_16 ) )
F_16 ( V_11 , V_25 ) ;
else if ( V_11 )
F_19 ( V_11 , V_25 ) ;
else
F_14 ( L_43 , V_7 ) ;
}
static int F_39 ( const char * V_52 )
{
struct V_37 * V_9 ;
const char * V_25 = F_34 ( V_52 ) ;
const char * V_56 = getenv ( L_44 ) ;
F_35 () ;
for ( V_9 = V_37 ; V_9 ; V_9 = V_9 -> V_10 )
F_38 ( V_9 -> V_7 , V_25 ) ;
if ( V_56 )
F_38 ( V_56 , V_25 ) ;
F_38 ( L_1 , V_25 ) ;
F_2 ( L_45 ) ;
return - 1 ;
}
static int F_40 ( const char * V_52 )
{
const char * V_25 = F_34 ( V_52 ) ;
F_37 ( L_46 , F_36 ( V_57 ) , 1 ) ;
F_13 ( L_2 , L_2 , L_47 , V_25 , NULL ) ;
return - 1 ;
}
static int F_41 ( char * * V_58 , const char * V_25 )
{
struct V_59 V_60 ;
const char * V_61 = F_36 ( V_62 ) ;
if ( V_59 ( F_42 ( L_48 , V_61 ) , & V_60 )
|| ! F_43 ( V_60 . V_63 ) ) {
F_2 ( L_49 , V_61 ) ;
return - 1 ;
}
return F_12 ( V_58 , L_50 , V_61 , V_25 ) ;
}
static void F_44 ( const char * V_24 )
{
F_45 ( L_51 , L_22 , L_52 , V_24 , NULL ) ;
}
static int F_46 ( const char * V_52 )
{
const char * V_25 = F_34 ( V_52 ) ;
char * V_58 ;
if ( F_41 ( & V_58 , V_25 ) < 0 )
return - 1 ;
F_44 ( V_58 ) ;
return 0 ;
}
int F_47 ( int V_64 , const char * * V_19 , const char * T_2 V_65 )
{
bool V_66 = false ;
enum V_1 V_1 = V_3 ;
struct V_67 V_68 [] = {
F_48 ( 'a' , L_53 , & V_66 , L_54 ) ,
F_49 ( 'm' , L_1 , & V_1 , L_55 , V_3 ) ,
F_49 ( 'w' , L_3 , & V_1 , L_56 ,
V_5 ) ,
F_49 ( 'i' , L_2 , & V_1 , L_57 ,
V_4 ) ,
F_50 () ,
} ;
const char * const V_69 [] = {
L_58 , L_59 , L_60 , L_61 , L_62 , L_63 ,
L_64 , L_65 , L_66 , L_67 , L_68 , L_69 , L_70 ,
L_71 , L_72 , L_73 , L_74 , L_75 , L_76 , L_77 , L_78 , L_79 ,
#ifdef F_51
L_80 ,
#endif
#ifdef F_52
L_81 ,
#endif
NULL } ;
const char * V_70 [] = {
L_82 ,
NULL
} ;
const char * V_71 ;
int V_72 = 0 ;
F_53 ( L_83 , & V_50 , & V_51 ) ;
F_54 ( F_29 , & V_1 ) ;
V_64 = F_55 ( V_64 , V_19 , V_68 ,
V_69 , V_70 , 0 ) ;
if ( V_66 ) {
printf ( L_84 , V_73 ) ;
F_56 ( L_85 , & V_50 , & V_51 ) ;
printf ( L_86 , V_74 ) ;
return 0 ;
}
if ( ! V_19 [ 0 ] ) {
printf ( L_87 , V_73 ) ;
F_30 () ;
printf ( L_88 , V_74 ) ;
return 0 ;
}
V_71 = F_57 ( V_19 [ 0 ] ) ;
if ( V_71 && ! F_32 ( V_19 [ 0 ] ) ) {
printf ( L_89 , V_19 [ 0 ] , V_71 ) ;
return 0 ;
}
switch ( V_1 ) {
case V_3 :
V_72 = F_39 ( V_19 [ 0 ] ) ;
break;
case V_4 :
V_72 = F_40 ( V_19 [ 0 ] ) ;
break;
case V_5 :
V_72 = F_46 ( V_19 [ 0 ] ) ;
break;
case V_6 :
default:
V_72 = - 1 ;
break;
}
return V_72 ;
}
