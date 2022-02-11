static T_1
F_1 ( T_2 * V_1 )
{
T_3 V_2 ;
void (* F_2)( void );
T_4 * V_3 ;
if ( ! F_3 ( V_1 , L_1 , & V_2 ) ) {
return FALSE ;
}
F_2 = ( void ( * ) ( void ) ) V_2 ;
V_3 = ( T_4 * ) F_4 ( sizeof ( T_4 ) ) ;
V_3 -> F_2 = F_2 ;
V_4 = F_5 ( V_4 , V_3 ) ;
return TRUE ;
}
void
F_6 ( void )
{
F_7 ( L_2 , F_1 ) ;
}
static void
F_8 ( T_3 V_5 , T_3 T_5 V_6 )
{
T_4 * V_3 = ( T_4 * ) V_5 ;
( V_3 -> F_2 ) ( ) ;
}
void
F_9 ( void )
{
F_10 ( V_4 , F_8 , NULL ) ;
}
T_6
F_11 ( T_7 * V_7 , int * V_8 )
{
T_8 V_9 ;
if ( F_12 ( ( V_7 -> V_10 == NULL ) ? V_7 -> V_11 : V_7 -> V_10 ,
& V_9 , V_8 ) == - 1 )
return - 1 ;
return V_9 . V_12 ;
}
int
F_13 ( T_7 * V_7 , T_8 * V_9 , int * V_8 )
{
if ( F_12 ( ( V_7 -> V_10 == NULL ) ? V_7 -> V_11 : V_7 -> V_10 ,
V_9 , V_8 ) == - 1 )
return - 1 ;
return 0 ;
}
int
F_14 ( T_7 * V_7 )
{
return V_7 -> V_13 ;
}
T_1
F_15 ( T_7 * V_7 )
{
return F_16 ( ( V_7 -> V_10 == NULL ) ? V_7 -> V_11 : V_7 -> V_10 ) ;
}
T_9
F_17 ( T_7 * V_7 )
{
return V_7 -> V_14 ;
}
int
F_18 ( T_7 * V_7 )
{
return V_7 -> V_15 ;
}
int
F_19 ( T_7 * V_7 )
{
return V_7 -> V_16 ;
}
T_10 *
F_20 ( T_7 * V_7 )
{
T_10 * V_17 ;
if( V_7 == NULL )
return NULL ;
V_17 = F_21 ( T_10 , 1 ) ;
V_17 -> V_18 = V_7 -> V_17 . V_18 ;
V_17 -> V_19 = V_7 -> V_17 . V_19 ;
V_17 -> V_20 = V_7 -> V_17 . V_20 ;
V_17 -> V_21 = V_7 -> V_17 . V_21 ;
V_17 -> V_22 = V_7 -> V_17 . V_22 ;
return V_17 ;
}
void
F_22 ( T_7 * V_7 , T_11 * V_23 )
{
F_23 ( V_7 -> V_17 . V_19 ) ;
V_7 -> V_17 . V_19 = V_23 ;
}
T_12 *
F_24 ( T_7 * V_7 )
{
T_12 * V_24 ;
V_24 = F_21 ( T_12 , 1 ) ;
V_24 -> V_25 = V_7 -> V_25 ;
return V_24 ;
}
static void F_25 ( void ) {
if ( V_26 ) return;
V_26 = F_26 ( FALSE , TRUE , sizeof( struct V_27 ) ) ;
F_27 ( V_26 , V_28 , V_29 ) ;
}
int F_28 ( void ) {
F_25 () ;
return V_29 ;
}
int F_29 ( const char * V_30 , const char * V_31 ) {
struct V_27 V_32 ;
F_25 () ;
V_32 . V_30 = F_30 ( V_30 ) ;
V_32 . V_31 = F_30 ( V_31 ) ;
F_31 ( V_26 , V_32 ) ;
return V_29 ++ ;
}
const char *
F_32 ( int V_33 )
{
if ( V_33 < V_34 || V_33 >= V_35 )
return L_3 ;
else if ( V_33 == V_34 )
return L_4 ;
else
return F_33 ( V_33 ) . V_30 ;
}
const char *
F_34 ( int V_33 )
{
if ( V_33 < V_34 || V_33 >= V_35 )
return L_5 ;
else if ( V_33 == V_34 )
return L_6 ;
else
return F_33 ( V_33 ) . V_31 ;
}
int
F_35 ( const char * V_31 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
if ( F_33 ( V_33 ) . V_31 != NULL &&
strcmp ( V_31 , F_33 ( V_33 ) . V_31 ) == 0 )
return V_33 ;
}
return - 1 ;
}
const char *
F_36 ( int V_8 )
{
static char V_36 [ 128 ] ;
unsigned int V_37 ;
if ( V_8 < 0 ) {
V_37 = - 1 - V_8 ;
if ( V_37 >= V_38 ) {
F_37 ( V_36 , 128 , L_7 , V_8 ) ;
return V_36 ;
}
if ( V_39 [ V_37 ] == NULL )
return L_8 ;
return V_39 [ V_37 ] ;
} else
return F_38 ( V_8 ) ;
}
void
F_39 ( T_7 * V_7 )
{
if ( V_7 -> V_40 != NULL )
(* V_7 -> V_40 )( V_7 ) ;
if ( V_7 -> V_10 != NULL ) {
F_40 ( V_7 -> V_10 ) ;
V_7 -> V_10 = NULL ;
}
if ( V_7 -> V_41 ) {
F_41 ( V_7 -> V_41 ) ;
F_23 ( V_7 -> V_41 ) ;
V_7 -> V_41 = NULL ;
}
}
static void
F_42 ( T_3 V_5 , T_3 T_5 V_6 )
{
F_23 ( V_5 ) ;
}
void
F_43 ( T_7 * V_7 )
{
if ( V_7 -> V_10 != NULL )
F_44 ( V_7 -> V_10 ) ;
if ( V_7 -> V_11 != NULL )
F_44 ( V_7 -> V_11 ) ;
}
void
F_45 ( T_7 * V_7 )
{
T_9 V_42 , V_43 ;
T_13 * V_44 ;
T_14 * V_45 ;
F_39 ( V_7 ) ;
if ( V_7 -> V_46 != NULL )
(* V_7 -> V_46 )( V_7 ) ;
if ( V_7 -> V_11 != NULL )
F_40 ( V_7 -> V_11 ) ;
if ( V_7 -> V_47 != NULL )
F_23 ( V_7 -> V_47 ) ;
if ( V_7 -> V_48 != NULL ) {
F_46 ( V_7 -> V_48 , F_42 , NULL ) ;
F_47 ( V_7 -> V_48 , TRUE ) ;
}
for( V_42 = 0 ; V_42 < V_7 -> V_25 -> V_49 ; V_42 ++ ) {
V_44 = & F_48 ( V_7 -> V_25 , T_13 , V_42 ) ;
if( V_44 -> V_19 != NULL ) {
F_23 ( V_44 -> V_19 ) ;
}
if( V_44 -> V_50 != NULL ) {
F_23 ( V_44 -> V_50 ) ;
}
if( V_44 -> V_51 != NULL ) {
F_23 ( V_44 -> V_51 ) ;
}
if( V_44 -> V_52 != NULL ) {
F_23 ( V_44 -> V_52 ) ;
}
if( V_44 -> V_53 != NULL ) {
F_23 ( V_44 -> V_53 ) ;
}
if( V_44 -> V_54 != NULL ) {
F_23 ( V_44 -> V_54 ) ;
}
for( V_43 = 0 ; V_43 < V_44 -> V_55 ; V_43 ++ ) {
V_45 = & F_48 ( V_44 -> V_56 , T_14 , V_43 ) ;
if( V_45 -> V_19 != NULL ) {
F_23 ( V_45 -> V_19 ) ;
}
}
if( V_44 -> V_55 != 0 ) {
F_49 ( V_44 -> V_56 , TRUE ) ;
}
}
F_49 ( V_7 -> V_25 , TRUE ) ;
F_23 ( V_7 ) ;
}
void
F_50 ( T_7 * V_7 ) {
F_51 ( V_7 -> V_10 ) ;
}
void F_52 ( T_7 * V_7 , T_15 V_57 ) {
if ( V_7 )
V_7 -> V_57 = V_57 ;
}
void F_53 ( T_7 * V_7 , T_16 V_58 ) {
if ( V_7 )
V_7 -> V_58 = V_58 ;
}
T_1
F_54 ( T_7 * V_7 , int * V_8 , T_11 * * V_59 , T_6 * V_60 )
{
V_7 -> V_61 . V_62 = V_7 -> V_15 ;
if ( ! V_7 -> V_63 ( V_7 , V_8 , V_59 , V_60 ) ) {
if ( * V_8 == 0 )
* V_8 = F_55 ( V_7 -> V_10 , V_59 ) ;
return FALSE ;
}
if ( V_7 -> V_61 . V_64 > V_7 -> V_61 . V_49 )
V_7 -> V_61 . V_64 = V_7 -> V_61 . V_49 ;
F_56 ( V_7 -> V_61 . V_62 != V_34 ) ;
return TRUE ;
}
T_1
F_57 ( T_17 V_10 , T_18 * V_65 , T_9 V_66 , int * V_8 ,
T_11 * * V_59 )
{
int V_67 ;
F_58 ( V_65 , V_66 ) ;
V_68 = V_69 ;
V_67 = F_59 ( F_60 ( V_65 ) , V_66 , V_10 ) ;
if ( V_67 < 0 || ( T_9 ) V_67 != V_66 ) {
* V_8 = F_55 ( V_10 , V_59 ) ;
if ( * V_8 == 0 )
* V_8 = V_70 ;
return FALSE ;
}
return TRUE ;
}
T_6
F_61 ( T_7 * V_7 )
{
return F_62 ( V_7 -> V_10 ) ;
}
struct V_71 *
F_63 ( T_7 * V_7 )
{
return & V_7 -> V_61 ;
}
T_19 *
F_64 ( T_7 * V_7 )
{
return F_60 ( V_7 -> V_41 ) ;
}
T_1
F_65 ( T_7 * V_7 , T_6 V_72 ,
struct V_71 * V_61 , T_18 * V_65 , int * V_8 , T_11 * * V_59 )
{
if ( ! V_7 -> V_73 ( V_7 , V_72 , V_61 , V_65 , V_8 , V_59 ) )
return FALSE ;
if ( V_61 -> V_64 > V_61 -> V_49 )
V_61 -> V_64 = V_61 -> V_49 ;
F_56 ( V_61 -> V_62 != V_34 ) ;
return TRUE ;
}
