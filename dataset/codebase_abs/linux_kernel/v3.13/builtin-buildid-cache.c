static int F_1 ( const char * V_1 , char * V_2 )
{
char V_3 [ V_4 ] ;
char V_5 [ V_4 ] ;
T_1 V_6 [ V_7 ] ;
char * V_8 ;
F_2 ( V_3 , V_1 , sizeof( V_3 ) ) ;
V_8 = strrchr ( V_3 , '/' ) ;
if ( ! V_8 )
return - 1 ;
* V_8 = '\0' ;
F_3 ( V_5 , sizeof( V_5 ) , L_1 , V_3 ) ;
if ( F_4 ( V_5 , V_6 , sizeof( V_6 ) ) )
return - 1 ;
F_5 ( V_6 , sizeof( V_6 ) , V_2 ) ;
return 0 ;
}
static int F_6 ( char * V_9 , T_2 V_10 )
{
struct V_11 V_12 ;
struct V_13 V_13 ;
char V_14 [ 32 ] ;
if ( F_7 ( & V_12 , NULL ) || ! localtime_r ( & V_12 . V_15 , & V_13 ) )
return - 1 ;
if ( ! strftime ( V_14 , sizeof( V_14 ) , L_2 , & V_13 ) )
return - 1 ;
F_3 ( V_9 , V_10 , L_3 , V_14 , ( unsigned ) V_12 . V_16 / 10000 ) ;
return 0 ;
}
static int F_8 ( const char * V_17 , char * V_18 ,
T_2 V_19 )
{
char V_20 [ V_4 ] ;
char V_21 [ V_4 ] ;
struct V_22 * V_23 ;
int V_24 = - 1 ;
T_3 * V_25 ;
V_25 = F_9 ( V_18 ) ;
if ( ! V_25 )
return - 1 ;
F_3 ( V_20 , sizeof( V_20 ) , L_4 , V_17 ) ;
while ( 1 ) {
V_23 = F_10 ( V_25 ) ;
if ( ! V_23 )
break;
if ( V_23 -> V_26 != V_27 )
continue;
F_3 ( V_21 , sizeof( V_21 ) , L_5 , V_18 ,
V_23 -> V_28 ) ;
if ( ! F_11 ( V_20 , V_21 ) ) {
F_3 ( V_21 , sizeof( V_21 ) , L_6 , V_18 ,
V_23 -> V_28 ) ;
F_2 ( V_18 , V_21 , V_19 ) ;
V_24 = 0 ;
break;
}
}
F_12 ( V_25 ) ;
return V_24 ;
}
static int F_13 ( const char * V_29 , const char * V_30 )
{
char V_9 [ 32 ] , V_2 [ V_7 * 2 + 1 ] ;
char V_17 [ V_4 ] , V_18 [ V_4 ] ;
char * V_8 ;
F_2 ( V_17 , V_29 , sizeof( V_17 ) ) ;
V_8 = strrchr ( V_17 , '/' ) ;
if ( ! V_8 || strcmp ( V_8 + 1 , L_7 ) )
return - 1 ;
* V_8 = '\0' ;
if ( F_1 ( V_17 , V_2 ) )
return - 1 ;
F_3 ( V_18 , sizeof( V_18 ) , L_8 ,
V_30 , V_2 ) ;
if ( ! F_8 ( V_17 , V_18 , sizeof( V_18 ) ) ) {
F_14 ( L_9 , V_18 ) ;
return 0 ;
}
if ( F_6 ( V_9 , sizeof( V_9 ) ) )
return - 1 ;
F_3 ( V_18 , sizeof( V_18 ) , L_10 ,
V_30 , V_2 , V_9 ) ;
if ( F_15 ( V_18 , 0755 ) )
return - 1 ;
if ( F_16 ( V_17 , V_18 ) ) {
if ( ! F_17 ( V_18 ) ) {
V_8 = strrchr ( V_18 , '/' ) ;
if ( V_8 )
* V_8 = '\0' ;
if ( ! F_17 ( V_18 ) ) {
V_8 = strrchr ( V_18 , '/' ) ;
if ( V_8 )
* V_8 = '\0' ;
F_17 ( V_18 ) ;
}
}
return - 1 ;
}
F_14 ( L_11 , V_18 ) ;
return 0 ;
}
static int F_18 ( const char * V_29 , const char * V_30 )
{
char V_31 [ V_7 * 2 + 1 ] ;
T_1 V_6 [ V_7 ] ;
int V_32 ;
if ( F_19 ( V_29 , & V_6 , sizeof( V_6 ) ) < 0 ) {
F_14 ( L_12 , V_29 ) ;
return - 1 ;
}
F_5 ( V_6 , sizeof( V_6 ) , V_31 ) ;
V_32 = F_20 ( V_31 , V_30 , V_29 ,
false , false ) ;
if ( V_33 )
F_21 ( L_13 , V_31 , V_29 ,
V_32 ? L_14 : L_15 ) ;
return V_32 ;
}
static int F_22 ( const char * V_29 ,
const char * V_30 )
{
T_1 V_6 [ V_7 ] ;
char V_31 [ V_7 * 2 + 1 ] ;
int V_32 ;
if ( F_19 ( V_29 , & V_6 , sizeof( V_6 ) ) < 0 ) {
F_14 ( L_12 , V_29 ) ;
return - 1 ;
}
F_5 ( V_6 , sizeof( V_6 ) , V_31 ) ;
V_32 = F_23 ( V_31 , V_30 ) ;
if ( V_33 )
F_21 ( L_16 , V_31 , V_29 ,
V_32 ? L_14 : L_15 ) ;
return V_32 ;
}
static bool F_24 ( struct V_34 * V_34 , int T_4 V_35 )
{
char V_29 [ V_4 ] ;
T_1 V_6 [ V_7 ] ;
if ( F_25 ( V_34 , V_29 , sizeof( V_29 ) ) &&
F_19 ( V_29 , V_6 ,
sizeof( V_6 ) ) != sizeof( V_6 ) ) {
if ( V_36 == V_37 )
return false ;
F_26 ( L_17 ,
V_29 ) ;
} else if ( memcmp ( V_34 -> V_6 , V_6 , sizeof( V_34 -> V_6 ) ) ) {
F_26 ( L_17 ,
V_29 ) ;
}
return true ;
}
static int F_27 ( const char * V_29 , bool V_38 , T_5 * V_39 )
{
struct V_40 V_41 = {
. V_42 = V_29 ,
. V_43 = V_44 ,
. V_38 = V_38 ,
} ;
struct V_45 * V_46 = F_28 ( & V_41 , false , NULL ) ;
if ( V_46 == NULL )
return - 1 ;
F_29 ( V_46 , V_39 , F_24 , 0 ) ;
F_30 ( V_46 ) ;
return 0 ;
}
static int F_31 ( const char * V_29 ,
const char * V_30 )
{
T_1 V_6 [ V_7 ] ;
char V_31 [ V_7 * 2 + 1 ] ;
int V_32 ;
if ( F_19 ( V_29 , & V_6 , sizeof( V_6 ) ) < 0 ) {
F_14 ( L_12 , V_29 ) ;
return - 1 ;
}
F_5 ( V_6 , sizeof( V_6 ) , V_31 ) ;
V_32 = F_23 ( V_31 , V_30 ) ;
if ( ! V_32 ) {
V_32 = F_20 ( V_31 , V_30 , V_29 ,
false , false ) ;
}
if ( V_33 )
F_21 ( L_18 , V_31 , V_29 ,
V_32 ? L_14 : L_15 ) ;
return V_32 ;
}
int F_32 ( int V_47 , const char * * V_48 ,
const char * T_6 V_35 )
{
struct V_49 * V_50 ;
struct V_51 * V_52 ;
int V_24 = 0 ;
bool V_38 = false ;
char V_30 [ V_4 ] ;
char const * V_53 = NULL ,
* V_54 = NULL ,
* V_55 = NULL ,
* V_56 = NULL ,
* V_57 ;
const struct V_58 V_59 [] = {
F_33 ( 'a' , L_19 , & V_53 ,
L_20 , L_21 ) ,
F_33 ( 'k' , L_7 , & V_57 ,
L_22 , L_23 ) ,
F_33 ( 'r' , L_24 , & V_54 , L_20 ,
L_25 ) ,
F_33 ( 'M' , L_26 , & V_55 , L_22 ,
L_27 ) ,
F_34 ( 'f' , L_28 , & V_38 , L_29 ) ,
F_33 ( 'u' , L_30 , & V_56 , L_20 ,
L_31 ) ,
F_35 ( 'v' , L_32 , & V_33 , L_33 ) ,
F_36 ()
} ;
const char * const V_60 [] = {
L_34 ,
NULL
} ;
V_47 = F_37 ( V_47 , V_48 , V_59 ,
V_60 , 0 ) ;
if ( F_38 () < 0 )
return - 1 ;
F_39 () ;
snprintf ( V_30 , sizeof( V_30 ) , L_35 , V_61 ) ;
if ( V_53 ) {
V_50 = F_40 ( true , V_53 ) ;
if ( V_50 ) {
F_41 (pos, list)
if ( F_18 ( V_52 -> V_62 , V_30 ) ) {
if ( V_36 == V_63 ) {
F_14 ( L_36 ,
V_52 -> V_62 ) ;
continue;
}
F_26 ( L_37 ,
V_52 -> V_62 , strerror ( V_36 ) ) ;
}
F_42 ( V_50 ) ;
}
}
if ( V_54 ) {
V_50 = F_40 ( true , V_54 ) ;
if ( V_50 ) {
F_41 (pos, list)
if ( F_22 ( V_52 -> V_62 , V_30 ) ) {
if ( V_36 == V_37 ) {
F_14 ( L_38 ,
V_52 -> V_62 ) ;
continue;
}
F_26 ( L_39 ,
V_52 -> V_62 , strerror ( V_36 ) ) ;
}
F_42 ( V_50 ) ;
}
}
if ( V_55 )
V_24 = F_27 ( V_55 , V_38 , stdout ) ;
if ( V_56 ) {
V_50 = F_40 ( true , V_56 ) ;
if ( V_50 ) {
F_41 (pos, list)
if ( F_31 ( V_52 -> V_62 , V_30 ) ) {
if ( V_36 == V_37 ) {
F_14 ( L_38 ,
V_52 -> V_62 ) ;
continue;
}
F_26 ( L_40 ,
V_52 -> V_62 , strerror ( V_36 ) ) ;
}
F_42 ( V_50 ) ;
}
}
if ( V_57 &&
F_13 ( V_57 , V_30 ) )
F_26 ( L_41 , V_57 ) ;
return V_24 ;
}
