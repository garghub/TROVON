T_1
F_1 ( T_2 * V_1 , int * V_2 )
{
T_3 V_3 ;
if ( F_2 ( ( V_1 -> V_4 == NULL ) ? V_1 -> V_5 : V_1 -> V_4 ,
& V_3 , V_2 ) == - 1 )
return - 1 ;
return V_3 . V_6 ;
}
int
F_3 ( T_2 * V_1 , T_3 * V_3 , int * V_2 )
{
if ( F_2 ( ( V_1 -> V_4 == NULL ) ? V_1 -> V_5 : V_1 -> V_4 ,
V_3 , V_2 ) == - 1 )
return - 1 ;
return 0 ;
}
int
F_4 ( T_2 * V_1 )
{
return V_1 -> V_7 ;
}
T_4
F_5 ( T_2 * V_1 )
{
return F_6 ( ( V_1 -> V_4 == NULL ) ? V_1 -> V_5 : V_1 -> V_4 ) ;
}
T_5
F_7 ( T_2 * V_1 )
{
return V_1 -> V_8 ;
}
int
F_8 ( T_2 * V_1 )
{
return V_1 -> V_9 ;
}
int
F_9 ( T_2 * V_1 )
{
return V_1 -> V_10 ;
}
T_6 *
F_10 ( T_2 * V_1 )
{
T_6 * V_11 ;
if( V_1 == NULL )
return NULL ;
V_11 = F_11 ( T_6 , 1 ) ;
V_11 -> V_12 = V_1 -> V_11 . V_12 ;
V_11 -> V_13 = V_1 -> V_11 . V_13 ;
V_11 -> V_14 = V_1 -> V_11 . V_14 ;
V_11 -> V_15 = V_1 -> V_11 . V_15 ;
V_11 -> V_16 = V_1 -> V_11 . V_16 ;
return V_11 ;
}
void
F_12 ( T_2 * V_1 , T_7 * V_17 )
{
F_13 ( V_1 -> V_11 . V_13 ) ;
V_1 -> V_11 . V_13 = V_17 ;
}
T_8 *
F_14 ( T_2 * V_1 )
{
T_8 * V_18 ;
V_18 = F_11 ( T_8 , 1 ) ;
V_18 -> V_19 = V_1 -> V_19 ;
V_18 -> V_20 = V_1 -> V_20 ;
return V_18 ;
}
static void F_15 ( void ) {
if ( V_21 ) return;
V_21 = F_16 ( FALSE , TRUE , sizeof( struct V_22 ) ) ;
F_17 ( V_21 , V_23 , V_24 ) ;
V_25 = ( void * ) V_21 -> V_26 ;
}
int F_18 ( void ) {
F_15 () ;
return V_24 ;
}
int F_19 ( char * V_27 , char * V_28 ) {
struct V_22 V_29 ;
F_15 () ;
V_29 . V_27 = F_20 ( V_27 ) ;
V_29 . V_28 = F_20 ( V_28 ) ;
F_21 ( V_21 , V_29 ) ;
V_25 = ( void * ) V_21 -> V_26 ;
return V_24 ++ ;
}
const char *
F_22 ( int V_30 )
{
if ( V_30 < V_31 || V_30 >= V_32 )
return L_1 ;
else if ( V_30 == V_31 )
return L_2 ;
else
return V_25 [ V_30 ] . V_27 ;
}
const char *
F_23 ( int V_30 )
{
if ( V_30 < V_31 || V_30 >= V_32 )
return L_3 ;
else if ( V_30 == V_31 )
return L_4 ;
else
return V_25 [ V_30 ] . V_28 ;
}
int
F_24 ( const char * V_28 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_32 ; V_30 ++ ) {
if ( V_25 [ V_30 ] . V_28 != NULL &&
strcmp ( V_28 , V_25 [ V_30 ] . V_28 ) == 0 )
return V_30 ;
}
return - 1 ;
}
const char *
F_25 ( int V_2 )
{
static char V_33 [ 128 ] ;
unsigned int V_34 ;
if ( V_2 < 0 ) {
V_34 = - 1 - V_2 ;
if ( V_34 >= V_35 ) {
F_26 ( V_33 , 128 , L_5 , V_2 ) ;
return V_33 ;
}
if ( V_36 [ V_34 ] == NULL )
return L_6 ;
return V_36 [ V_34 ] ;
} else
return F_27 ( V_2 ) ;
}
void
F_28 ( T_2 * V_1 )
{
if ( V_1 -> V_37 != NULL )
(* V_1 -> V_37 )( V_1 ) ;
if ( V_1 -> V_4 != NULL ) {
F_29 ( V_1 -> V_4 ) ;
V_1 -> V_4 = NULL ;
}
if ( V_1 -> V_38 ) {
F_30 ( V_1 -> V_38 ) ;
F_13 ( V_1 -> V_38 ) ;
V_1 -> V_38 = NULL ;
}
}
static void
F_31 ( T_9 V_26 , T_9 T_10 V_39 )
{
F_13 ( V_26 ) ;
}
void
F_32 ( T_2 * V_1 )
{
if ( V_1 -> V_4 != NULL )
F_33 ( V_1 -> V_4 ) ;
if ( V_1 -> V_5 != NULL )
F_33 ( V_1 -> V_5 ) ;
}
void
F_34 ( T_2 * V_1 )
{
T_11 V_40 , V_41 ;
T_12 * V_42 ;
T_13 * V_43 ;
F_28 ( V_1 ) ;
if ( V_1 -> V_44 != NULL )
(* V_1 -> V_44 )( V_1 ) ;
if ( V_1 -> V_5 != NULL )
F_29 ( V_1 -> V_5 ) ;
if ( V_1 -> V_45 != NULL )
F_13 ( V_1 -> V_45 ) ;
if ( V_1 -> V_46 != NULL ) {
F_35 ( V_1 -> V_46 , F_31 , NULL ) ;
F_36 ( V_1 -> V_46 , TRUE ) ;
}
for( V_40 = 0 ; V_40 < ( T_11 ) V_1 -> V_19 ; V_40 ++ ) {
V_42 = & F_37 ( V_1 -> V_20 , T_12 , V_40 ) ;
if( V_42 -> V_13 != NULL ) {
F_13 ( V_42 -> V_13 ) ;
}
if( V_42 -> V_47 != NULL ) {
F_13 ( V_42 -> V_47 ) ;
}
if( V_42 -> V_48 != NULL ) {
F_13 ( V_42 -> V_48 ) ;
}
if( V_42 -> V_49 != NULL ) {
F_13 ( V_42 -> V_49 ) ;
}
if( V_42 -> V_50 != NULL ) {
F_13 ( V_42 -> V_50 ) ;
}
if( V_42 -> V_51 != NULL ) {
F_13 ( V_42 -> V_51 ) ;
}
for( V_41 = 0 ; V_41 < ( T_11 ) V_42 -> V_52 ; V_41 ++ ) {
V_43 = & F_37 ( V_42 -> V_53 , T_13 , V_41 ) ;
if( V_43 -> V_13 != NULL ) {
F_13 ( V_43 -> V_13 ) ;
}
}
if( V_42 -> V_52 != 0 ) {
F_38 ( V_42 -> V_53 , TRUE ) ;
}
}
if( V_1 -> V_19 != 0 ) {
F_38 ( V_1 -> V_20 , TRUE ) ;
}
F_13 ( V_1 ) ;
}
void
F_39 ( T_2 * V_1 ) {
F_40 ( V_1 -> V_4 ) ;
}
void F_41 ( T_2 * V_1 , T_14 V_54 ) {
if ( V_1 )
V_1 -> V_54 = V_54 ;
}
void F_42 ( T_2 * V_1 , T_15 V_55 ) {
if ( V_1 )
V_1 -> V_55 = V_55 ;
}
T_4
F_43 ( T_2 * V_1 , int * V_2 , T_7 * * V_56 , T_1 * V_57 )
{
V_1 -> V_58 . V_59 = V_1 -> V_9 ;
if ( ! V_1 -> V_60 ( V_1 , V_2 , V_56 , V_57 ) ) {
if ( * V_2 == 0 )
* V_2 = F_44 ( V_1 -> V_4 , V_56 ) ;
return FALSE ;
}
if ( V_1 -> V_58 . V_61 > V_1 -> V_58 . V_62 )
V_1 -> V_58 . V_61 = V_1 -> V_58 . V_62 ;
F_45 ( V_1 -> V_58 . V_59 != V_31 ) ;
return TRUE ;
}
T_1
F_46 ( T_2 * V_1 )
{
return F_47 ( V_1 -> V_4 ) ;
}
struct V_63 *
F_48 ( T_2 * V_1 )
{
return & V_1 -> V_58 ;
}
union V_64 *
F_49 ( T_2 * V_1 )
{
return & V_1 -> V_65 ;
}
T_16 *
F_50 ( T_2 * V_1 )
{
return F_51 ( V_1 -> V_38 ) ;
}
T_4
F_52 ( T_2 * V_1 , T_1 V_66 ,
union V_64 * V_65 , T_16 * V_67 , int V_62 ,
int * V_2 , T_7 * * V_56 )
{
return V_1 -> V_68 ( V_1 , V_66 , V_65 , V_67 , V_62 ,
V_2 , V_56 ) ;
}
