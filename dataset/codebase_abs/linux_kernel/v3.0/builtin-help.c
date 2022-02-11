static enum V_1 F_1 ( const char * V_2 )
{
if ( ! strcmp ( V_2 , L_1 ) )
return V_3 ;
if ( ! strcmp ( V_2 , L_2 ) )
return V_4 ;
if ( ! strcmp ( V_2 , L_3 ) || ! strcmp ( V_2 , L_4 ) )
return V_5 ;
F_2 ( L_5 , V_2 ) ;
}
static const char * F_3 ( const char * V_6 )
{
struct V_7 * V_8 ;
for ( V_8 = V_7 ; V_8 ; V_8 = V_8 -> V_9 ) {
if ( ! strcasecmp ( V_6 , V_8 -> V_6 ) )
return V_8 -> V_10 ;
}
return NULL ;
}
static int F_4 ( void )
{
struct V_11 V_12 = V_13 ;
struct V_14 V_15 ;
const char * V_16 [] = { L_6 , L_7 , NULL } ;
int V_17 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_18 = V_16 ;
V_15 . V_19 = - 1 ;
V_15 . V_20 = 1 ;
if ( F_5 ( & V_15 ) ) {
fprintf ( V_21 , L_8 ) ;
return - 1 ;
}
F_6 ( & V_12 , V_15 . V_19 , 20 ) ;
F_7 ( V_15 . V_19 ) ;
F_8 ( & V_15 ) ;
if ( F_9 ( V_12 . V_22 , L_6 ) ) {
fprintf ( V_21 , L_9 ) ;
F_10 ( & V_12 ) ;
return - 1 ;
}
F_11 ( & V_12 , 0 , strlen ( L_6 ) ) ;
V_17 = atoi ( V_12 . V_22 ) ;
if ( V_17 < 22 ) {
fprintf ( V_21 ,
L_10 ,
V_17 ) ;
F_10 ( & V_12 ) ;
return - 1 ;
}
F_10 ( & V_12 ) ;
return 0 ;
}
static void F_12 ( const char * V_23 , const char * V_24 )
{
if ( ! F_4 () ) {
struct V_11 V_25 = V_13 ;
if ( ! V_23 )
V_23 = L_6 ;
F_13 ( & V_25 , L_11 , V_24 ) ;
F_14 ( V_23 , L_6 , L_12 , V_25 . V_22 , NULL ) ;
F_15 ( L_13 , V_23 , strerror ( V_26 ) ) ;
}
}
static void F_16 ( const char * V_23 , const char * V_24 )
{
const char * V_27 = getenv ( L_14 ) ;
if ( V_27 && * V_27 ) {
struct V_11 V_25 = V_13 ;
const char * V_28 = L_15 ;
if ( V_23 ) {
const char * V_29 = strrchr ( V_23 , '/' ) ;
if ( V_29 && ! strcmp ( V_29 + 1 , L_16 ) ) {
char * V_30 = F_17 ( V_23 ) ;
char * V_31 = strrchr ( V_30 , '/' ) ;
strcpy ( V_31 + 1 , L_15 ) ;
V_23 = V_30 ;
}
if ( V_29 )
V_28 = V_29 ;
} else
V_23 = L_15 ;
F_13 ( & V_25 , L_17 , V_24 ) ;
F_14 ( V_23 , V_28 , L_18 , V_25 . V_22 , NULL ) ;
F_15 ( L_13 , V_23 , strerror ( V_26 ) ) ;
}
}
static void F_18 ( const char * V_23 , const char * V_24 )
{
if ( ! V_23 )
V_23 = L_1 ;
F_14 ( V_23 , L_1 , V_24 , NULL ) ;
F_15 ( L_13 , V_23 , strerror ( V_26 ) ) ;
}
static void F_19 ( const char * V_32 , const char * V_24 )
{
struct V_11 V_33 = V_13 ;
F_13 ( & V_33 , L_19 , V_32 , V_24 ) ;
F_20 ( L_20 , L_21 , L_22 , V_33 . V_22 , NULL ) ;
F_15 ( L_13 , V_32 , strerror ( V_26 ) ) ;
}
static void F_21 ( const char * V_6 )
{
struct V_34 * * V_35 = & V_34 ;
T_1 V_36 = strlen ( V_6 ) ;
while ( * V_35 )
V_35 = & ( ( * V_35 ) -> V_9 ) ;
* V_35 = F_22 ( sizeof( * * V_35 ) + V_36 + 1 ) ;
strncpy ( ( * V_35 ) -> V_6 , V_6 , V_36 ) ;
}
static int F_23 ( const char * V_6 , T_1 V_36 )
{
return ( ! strncasecmp ( L_1 , V_6 , V_36 ) ||
! strncasecmp ( L_23 , V_6 , V_36 ) ||
! strncasecmp ( L_16 , V_6 , V_36 ) ) ;
}
static void F_24 ( const char * V_6 ,
T_1 V_36 ,
const char * V_37 )
{
struct V_7 * V_30 = F_22 ( sizeof( * V_30 ) + V_36 + 1 ) ;
strncpy ( V_30 -> V_6 , V_6 , V_36 ) ;
V_30 -> V_10 = F_17 ( V_37 ) ;
V_30 -> V_9 = V_7 ;
V_7 = V_30 ;
}
static int F_25 ( const char * V_6 ,
T_1 V_36 ,
const char * V_37 )
{
if ( F_23 ( V_6 , V_36 ) )
F_24 ( V_6 , V_36 , V_37 ) ;
else
F_15 ( L_24
L_25 ,
V_6 ) ;
return 0 ;
}
static int F_26 ( const char * V_6 ,
T_1 V_36 ,
const char * V_37 )
{
if ( F_23 ( V_6 , V_36 ) )
F_15 ( L_26
L_27 ,
V_6 ) ;
else
F_24 ( V_6 , V_36 , V_37 ) ;
return 0 ;
}
static int F_27 ( const char * V_38 , const char * V_37 )
{
const char * V_6 = V_38 + 4 ;
const char * V_39 = strrchr ( V_6 , '.' ) ;
if ( ! V_39 )
return error ( L_28 , V_6 ) ;
if ( ! strcmp ( V_39 , L_29 ) ) {
if ( ! V_37 )
return F_28 ( V_38 ) ;
return F_25 ( V_6 , V_39 - V_6 , V_37 ) ;
}
if ( ! strcmp ( V_39 , L_30 ) ) {
if ( ! V_37 )
return F_28 ( V_38 ) ;
return F_26 ( V_6 , V_39 - V_6 , V_37 ) ;
}
F_15 ( L_31 , V_39 ) ;
return 0 ;
}
static int F_29 ( const char * V_38 , const char * V_37 , void * V_40 )
{
if ( ! strcmp ( V_38 , L_32 ) ) {
if ( ! V_37 )
return F_28 ( V_38 ) ;
V_1 = F_1 ( V_37 ) ;
return 0 ;
}
if ( ! strcmp ( V_38 , L_33 ) ) {
if ( ! V_37 )
return F_28 ( V_38 ) ;
F_21 ( V_37 ) ;
return 0 ;
}
if ( ! F_9 ( V_38 , L_34 ) )
return F_27 ( V_38 , V_37 ) ;
return F_30 ( V_38 , V_37 , V_40 ) ;
}
void F_31 ( void )
{
unsigned int V_41 , V_42 = 0 ;
for ( V_41 = 0 ; V_41 < F_32 ( V_43 ) ; V_41 ++ ) {
if ( V_42 < strlen ( V_43 [ V_41 ] . V_6 ) )
V_42 = strlen ( V_43 [ V_41 ] . V_6 ) ;
}
puts ( L_35 ) ;
for ( V_41 = 0 ; V_41 < F_32 ( V_43 ) ; V_41 ++ ) {
printf ( L_36 , V_42 , V_43 [ V_41 ] . V_6 ) ;
puts ( V_43 [ V_41 ] . V_44 ) ;
}
}
static int F_33 ( const char * V_45 )
{
return F_34 ( & V_46 , V_45 ) ||
F_34 ( & V_47 , V_45 ) ;
}
static const char * F_35 ( const char * V_48 , const char * V_32 )
{
T_1 V_49 = strlen ( V_48 ) ;
T_1 V_50 = strlen ( V_32 ) ;
char * V_35 = malloc ( V_49 + V_50 + 1 ) ;
memcpy ( V_35 , V_48 , V_49 ) ;
strcpy ( V_35 + V_49 , V_32 ) ;
return V_35 ;
}
static const char * F_36 ( const char * V_51 )
{
if ( ! V_51 )
return L_37 ;
else if ( ! F_9 ( V_51 , L_37 ) )
return V_51 ;
else
return F_35 ( L_38 , V_51 ) ;
}
static void F_37 ( void )
{
struct V_11 V_52 = V_13 ;
const char * V_53 = getenv ( L_39 ) ;
F_38 ( & V_52 , F_39 ( V_54 ) ) ;
F_40 ( & V_52 , ':' ) ;
if ( V_53 )
F_38 ( & V_52 , V_53 ) ;
F_41 ( L_39 , V_52 . V_22 , 1 ) ;
F_10 ( & V_52 ) ;
}
static void F_42 ( const char * V_6 , const char * V_24 )
{
const char * V_10 = F_3 ( V_6 ) ;
if ( ! strcasecmp ( V_6 , L_1 ) )
F_18 ( V_10 , V_24 ) ;
else if ( ! strcasecmp ( V_6 , L_23 ) )
F_12 ( V_10 , V_24 ) ;
else if ( ! strcasecmp ( V_6 , L_16 ) )
F_16 ( V_10 , V_24 ) ;
else if ( V_10 )
F_19 ( V_10 , V_24 ) ;
else
F_15 ( L_40 , V_6 ) ;
}
static void F_43 ( const char * V_51 )
{
struct V_34 * V_8 ;
const char * V_24 = F_36 ( V_51 ) ;
const char * V_55 = getenv ( L_41 ) ;
F_37 () ;
for ( V_8 = V_34 ; V_8 ; V_8 = V_8 -> V_9 )
F_42 ( V_8 -> V_6 , V_24 ) ;
if ( V_55 )
F_42 ( V_55 , V_24 ) ;
F_42 ( L_1 , V_24 ) ;
F_2 ( L_42 ) ;
}
static void F_44 ( const char * V_51 )
{
const char * V_24 = F_36 ( V_51 ) ;
F_41 ( L_43 , F_39 ( V_56 ) , 1 ) ;
F_14 ( L_2 , L_2 , L_44 , V_24 , NULL ) ;
}
static void F_45 ( struct V_11 * V_57 , const char * V_24 )
{
struct V_58 V_59 ;
const char * V_60 = F_39 ( V_61 ) ;
if ( V_58 ( F_46 ( L_45 , V_60 ) , & V_59 )
|| ! F_47 ( V_59 . V_62 ) )
F_2 ( L_46 , V_60 ) ;
F_48 ( V_57 , 0 ) ;
F_13 ( V_57 , L_47 , V_60 , V_24 ) ;
}
static void F_49 ( const char * V_23 )
{
F_50 ( L_48 , L_22 , L_49 , V_23 , NULL ) ;
}
static void F_51 ( const char * V_51 )
{
const char * V_24 = F_36 ( V_51 ) ;
struct V_11 V_57 ;
F_45 ( & V_57 , V_24 ) ;
F_49 ( V_57 . V_22 ) ;
}
int F_52 ( int V_63 , const char * * V_18 , const char * V_48 V_64 )
{
const char * V_65 ;
F_53 ( L_38 , & V_46 , & V_47 ) ;
F_54 ( F_29 , NULL ) ;
V_63 = F_55 ( V_63 , V_18 , V_66 ,
V_67 , 0 ) ;
if ( V_68 ) {
printf ( L_50 , V_69 ) ;
F_56 ( L_51 , & V_46 , & V_47 ) ;
printf ( L_52 , V_70 ) ;
return 0 ;
}
if ( ! V_18 [ 0 ] ) {
printf ( L_50 , V_69 ) ;
F_31 () ;
printf ( L_53 , V_70 ) ;
return 0 ;
}
V_65 = F_57 ( V_18 [ 0 ] ) ;
if ( V_65 && ! F_33 ( V_18 [ 0 ] ) ) {
printf ( L_54 , V_18 [ 0 ] , V_65 ) ;
return 0 ;
}
switch ( V_1 ) {
case V_3 :
F_43 ( V_18 [ 0 ] ) ;
break;
case V_4 :
F_44 ( V_18 [ 0 ] ) ;
break;
case V_5 :
F_51 ( V_18 [ 0 ] ) ;
default:
break;
}
return 0 ;
}
