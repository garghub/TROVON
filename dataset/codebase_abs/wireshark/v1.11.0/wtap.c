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
}
int F_18 ( void ) {
F_15 () ;
return V_24 ;
}
int F_19 ( const char * V_25 , const char * V_26 ) {
struct V_22 V_27 ;
F_15 () ;
V_27 . V_25 = F_20 ( V_25 ) ;
V_27 . V_26 = F_20 ( V_26 ) ;
F_21 ( V_21 , V_27 ) ;
return V_24 ++ ;
}
const char *
F_22 ( int V_28 )
{
if ( V_28 < V_29 || V_28 >= V_30 )
return L_1 ;
else if ( V_28 == V_29 )
return L_2 ;
else
return F_23 ( V_28 ) . V_25 ;
}
const char *
F_24 ( int V_28 )
{
if ( V_28 < V_29 || V_28 >= V_30 )
return L_3 ;
else if ( V_28 == V_29 )
return L_4 ;
else
return F_23 ( V_28 ) . V_26 ;
}
int
F_25 ( const char * V_26 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
if ( F_23 ( V_28 ) . V_26 != NULL &&
strcmp ( V_26 , F_23 ( V_28 ) . V_26 ) == 0 )
return V_28 ;
}
return - 1 ;
}
const char *
F_26 ( int V_2 )
{
static char V_31 [ 128 ] ;
unsigned int V_32 ;
if ( V_2 < 0 ) {
V_32 = - 1 - V_2 ;
if ( V_32 >= V_33 ) {
F_27 ( V_31 , 128 , L_5 , V_2 ) ;
return V_31 ;
}
if ( V_34 [ V_32 ] == NULL )
return L_6 ;
return V_34 [ V_32 ] ;
} else
return F_28 ( V_2 ) ;
}
void
F_29 ( T_2 * V_1 )
{
if ( V_1 -> V_35 != NULL )
(* V_1 -> V_35 )( V_1 ) ;
if ( V_1 -> V_4 != NULL ) {
F_30 ( V_1 -> V_4 ) ;
V_1 -> V_4 = NULL ;
}
if ( V_1 -> V_36 ) {
F_31 ( V_1 -> V_36 ) ;
F_13 ( V_1 -> V_36 ) ;
V_1 -> V_36 = NULL ;
}
}
static void
F_32 ( T_9 V_37 , T_9 T_10 V_38 )
{
F_13 ( V_37 ) ;
}
void
F_33 ( T_2 * V_1 )
{
if ( V_1 -> V_4 != NULL )
F_34 ( V_1 -> V_4 ) ;
if ( V_1 -> V_5 != NULL )
F_34 ( V_1 -> V_5 ) ;
}
void
F_35 ( T_2 * V_1 )
{
T_11 V_39 , V_40 ;
T_12 * V_41 ;
T_13 * V_42 ;
F_29 ( V_1 ) ;
if ( V_1 -> V_43 != NULL )
(* V_1 -> V_43 )( V_1 ) ;
if ( V_1 -> V_5 != NULL )
F_30 ( V_1 -> V_5 ) ;
if ( V_1 -> V_44 != NULL )
F_13 ( V_1 -> V_44 ) ;
if ( V_1 -> V_45 != NULL ) {
F_36 ( V_1 -> V_45 , F_32 , NULL ) ;
F_37 ( V_1 -> V_45 , TRUE ) ;
}
for( V_39 = 0 ; V_39 < ( T_11 ) V_1 -> V_19 ; V_39 ++ ) {
V_41 = & F_38 ( V_1 -> V_20 , T_12 , V_39 ) ;
if( V_41 -> V_13 != NULL ) {
F_13 ( V_41 -> V_13 ) ;
}
if( V_41 -> V_46 != NULL ) {
F_13 ( V_41 -> V_46 ) ;
}
if( V_41 -> V_47 != NULL ) {
F_13 ( V_41 -> V_47 ) ;
}
if( V_41 -> V_48 != NULL ) {
F_13 ( V_41 -> V_48 ) ;
}
if( V_41 -> V_49 != NULL ) {
F_13 ( V_41 -> V_49 ) ;
}
if( V_41 -> V_50 != NULL ) {
F_13 ( V_41 -> V_50 ) ;
}
for( V_40 = 0 ; V_40 < ( T_11 ) V_41 -> V_51 ; V_40 ++ ) {
V_42 = & F_38 ( V_41 -> V_52 , T_13 , V_40 ) ;
if( V_42 -> V_13 != NULL ) {
F_13 ( V_42 -> V_13 ) ;
}
}
if( V_41 -> V_51 != 0 ) {
F_39 ( V_41 -> V_52 , TRUE ) ;
}
}
if( V_1 -> V_19 != 0 ) {
F_39 ( V_1 -> V_20 , TRUE ) ;
}
F_13 ( V_1 ) ;
}
void
F_40 ( T_2 * V_1 ) {
F_41 ( V_1 -> V_4 ) ;
}
void F_42 ( T_2 * V_1 , T_14 V_53 ) {
if ( V_1 )
V_1 -> V_53 = V_53 ;
}
void F_43 ( T_2 * V_1 , T_15 V_54 ) {
if ( V_1 )
V_1 -> V_54 = V_54 ;
}
T_4
F_44 ( T_2 * V_1 , int * V_2 , T_7 * * V_55 , T_1 * V_56 )
{
V_1 -> V_57 . V_58 = V_1 -> V_9 ;
if ( ! V_1 -> V_59 ( V_1 , V_2 , V_55 , V_56 ) ) {
if ( * V_2 == 0 )
* V_2 = F_45 ( V_1 -> V_4 , V_55 ) ;
return FALSE ;
}
if ( V_1 -> V_57 . V_60 > V_1 -> V_57 . V_61 )
V_1 -> V_57 . V_60 = V_1 -> V_57 . V_61 ;
F_46 ( V_1 -> V_57 . V_58 != V_29 ) ;
return TRUE ;
}
T_4
F_47 ( T_16 V_4 , T_17 * V_62 , T_5 V_63 , int * V_2 ,
T_7 * * V_55 )
{
int V_64 ;
F_48 ( V_62 , V_63 ) ;
V_65 = V_66 ;
V_64 = F_49 ( F_50 ( V_62 ) , V_63 , V_4 ) ;
if ( V_64 < 0 || ( T_5 ) V_64 != V_63 ) {
* V_2 = F_45 ( V_4 , V_55 ) ;
if ( * V_2 == 0 )
* V_2 = V_67 ;
return FALSE ;
}
return TRUE ;
}
T_1
F_51 ( T_2 * V_1 )
{
return F_52 ( V_1 -> V_4 ) ;
}
struct V_68 *
F_53 ( T_2 * V_1 )
{
return & V_1 -> V_57 ;
}
T_18 *
F_54 ( T_2 * V_1 )
{
return F_50 ( V_1 -> V_36 ) ;
}
T_4
F_55 ( T_2 * V_1 , T_1 V_69 ,
struct V_68 * V_57 , T_17 * V_62 , int V_61 ,
int * V_2 , T_7 * * V_55 )
{
return V_1 -> V_70 ( V_1 , V_69 , V_57 , V_62 , V_61 ,
V_2 , V_55 ) ;
}
