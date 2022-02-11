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
static void F_19 ( void ) {
if ( V_16 ) return;
V_16 = F_20 ( FALSE , TRUE , sizeof( struct V_17 ) ) ;
F_21 ( V_16 , V_18 , V_19 ) ;
}
int F_22 ( void ) {
F_19 () ;
return V_19 ;
}
int F_23 ( const char * V_20 , const char * V_21 ) {
struct V_17 V_22 ;
F_19 () ;
V_22 . V_20 = F_24 ( V_20 ) ;
V_22 . V_21 = F_24 ( V_21 ) ;
F_25 ( V_16 , V_22 ) ;
return V_19 ++ ;
}
const char *
F_26 ( int V_23 )
{
if ( V_23 < V_24 || V_23 >= V_25 )
return L_3 ;
else if ( V_23 == V_24 )
return L_4 ;
else
return F_27 ( V_23 ) . V_20 ;
}
const char *
F_28 ( int V_23 )
{
if ( V_23 < V_24 || V_23 >= V_25 )
return L_5 ;
else if ( V_23 == V_24 )
return L_6 ;
else
return F_27 ( V_23 ) . V_21 ;
}
int
F_29 ( const char * V_21 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ ) {
if ( F_27 ( V_23 ) . V_21 != NULL &&
strcmp ( V_21 , F_27 ( V_23 ) . V_21 ) == 0 )
return V_23 ;
}
return - 1 ;
}
const char *
F_30 ( int V_8 )
{
static char V_26 [ 128 ] ;
unsigned int V_27 ;
if ( V_8 < 0 ) {
V_27 = - 1 - V_8 ;
if ( V_27 >= V_28 ) {
F_31 ( V_26 , 128 , L_7 , V_8 ) ;
return V_26 ;
}
if ( V_29 [ V_27 ] == NULL )
return L_8 ;
return V_29 [ V_27 ] ;
} else
return F_32 ( V_8 ) ;
}
void
F_33 ( T_7 * V_7 )
{
if ( V_7 -> V_30 != NULL )
(* V_7 -> V_30 )( V_7 ) ;
if ( V_7 -> V_10 != NULL ) {
F_34 ( V_7 -> V_10 ) ;
V_7 -> V_10 = NULL ;
}
if ( V_7 -> V_31 ) {
F_35 ( V_7 -> V_31 ) ;
F_36 ( V_7 -> V_31 ) ;
V_7 -> V_31 = NULL ;
}
}
static void
F_37 ( T_3 V_5 , T_3 T_5 V_6 )
{
F_36 ( V_5 ) ;
}
void
F_38 ( T_7 * V_7 )
{
if ( V_7 -> V_10 != NULL )
F_39 ( V_7 -> V_10 ) ;
if ( V_7 -> V_11 != NULL )
F_39 ( V_7 -> V_11 ) ;
}
void
F_40 ( T_7 * V_7 )
{
F_33 ( V_7 ) ;
if ( V_7 -> V_32 != NULL )
(* V_7 -> V_32 )( V_7 ) ;
if ( V_7 -> V_11 != NULL )
F_34 ( V_7 -> V_11 ) ;
if ( V_7 -> V_33 != NULL )
F_36 ( V_7 -> V_33 ) ;
if ( V_7 -> V_34 != NULL ) {
F_41 ( V_7 -> V_34 , F_37 , NULL ) ;
F_42 ( V_7 -> V_34 , TRUE ) ;
}
F_36 ( V_7 ) ;
}
void
F_43 ( T_7 * V_7 ) {
F_44 ( V_7 -> V_10 ) ;
}
T_1
F_45 ( T_7 * V_7 , int * V_8 , T_10 * * V_35 , T_6 * V_36 )
{
#if 0
wth->phdr.pkt_encap = wth->file_encap;
#endif
if ( ! V_7 -> V_37 ( V_7 , V_8 , V_35 , V_36 ) ) {
if ( * V_8 == 0 )
* V_8 = F_46 ( V_7 -> V_10 , V_35 ) ;
return FALSE ;
}
#if 0
if (wth->phdr.caplen > wth->phdr.len)
wth->phdr.caplen = wth->phdr.len;
g_assert(wth->phdr.pkt_encap != FTAP_ENCAP_PER_RECORD);
#endif
return TRUE ;
}
T_1
F_47 ( T_11 V_10 , T_12 * V_38 , T_9 V_39 , int * V_8 ,
T_10 * * V_35 )
{
int V_40 ;
F_48 ( V_38 , V_39 ) ;
V_41 = V_42 ;
V_40 = F_49 ( F_50 ( V_38 ) , V_39 , V_10 ) ;
if ( V_40 < 0 || ( T_9 ) V_40 != V_39 ) {
* V_8 = F_46 ( V_10 , V_35 ) ;
if ( * V_8 == 0 )
* V_8 = V_43 ;
return FALSE ;
}
return TRUE ;
}
T_6
F_51 ( T_7 * V_7 )
{
return F_52 ( V_7 -> V_10 ) ;
}
T_1
F_53 ( T_7 * V_7 , T_6 V_44 ,
T_12 * V_38 , int V_45 ,
int * V_8 , T_10 * * V_35 )
{
return V_7 -> V_46 ( V_7 , V_44 , V_38 , V_45 ,
V_8 , V_35 ) ;
}
