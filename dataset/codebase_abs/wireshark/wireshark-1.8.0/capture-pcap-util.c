T_1 *
F_1 ( char * V_1 , char * V_2 )
{
T_1 * V_3 ;
V_3 = ( T_1 * ) F_2 ( sizeof ( T_1 ) ) ;
V_3 -> V_1 = F_3 ( V_1 ) ;
if ( V_2 == NULL )
V_3 -> V_2 = NULL ;
else
V_3 -> V_2 = F_3 ( V_2 ) ;
V_3 -> V_4 = NULL ;
V_3 -> V_5 = FALSE ;
return V_3 ;
}
void
F_4 ( T_1 * V_3 , struct V_6 * V_7 )
{
T_2 * V_8 ;
struct V_9 * V_10 ;
#ifdef F_5
struct V_11 * V_12 ;
#endif
switch ( V_7 -> V_13 ) {
case V_14 :
V_10 = (struct V_9 * ) ( void * ) V_7 ;
V_8 = ( T_2 * ) F_2 ( sizeof( * V_8 ) ) ;
V_8 -> V_15 = V_16 ;
V_8 -> V_7 . V_17 =
* ( ( V_18 * ) & ( V_10 -> V_19 . V_20 ) ) ;
V_3 -> V_4 = F_6 ( V_3 -> V_4 , V_8 ) ;
break;
#ifdef F_5
case V_21 :
V_12 = (struct V_11 * ) ( void * ) V_7 ;
V_8 = ( T_2 * ) F_2 ( sizeof( * V_8 ) ) ;
V_8 -> V_15 = V_22 ;
memcpy ( ( void * ) & V_8 -> V_7 . V_23 ,
( void * ) & V_12 -> V_24 . V_25 ,
sizeof V_8 -> V_7 . V_23 ) ;
V_3 -> V_4 = F_6 ( V_3 -> V_4 , V_8 ) ;
break;
#endif
}
}
static void
F_7 ( T_1 * V_3 , T_3 * V_26 )
{
T_4 * V_27 ;
V_3 -> V_5 = ( V_26 -> V_28 & V_29 ) ? TRUE : FALSE ;
for ( V_27 = V_26 -> V_30 ; V_27 != NULL ; V_27 = V_27 -> V_31 ) {
if ( V_27 -> V_7 != NULL )
F_4 ( V_3 , V_27 -> V_7 ) ;
}
}
T_5 *
F_8 ( const char * V_32 ,
struct V_33 * V_34 ,
int * V_35 , char * * V_36 )
{
T_5 * V_37 = NULL ;
T_3 * V_38 , * V_39 ;
T_1 * V_3 ;
char V_40 [ V_41 ] ;
if ( F_9 ( ( char * ) V_32 , V_34 , & V_38 , V_40 ) == - 1 ) {
* V_35 = V_42 ;
if ( V_36 != NULL )
* V_36 = F_10 ( V_40 ) ;
return NULL ;
}
if ( V_38 == NULL ) {
* V_35 = V_43 ;
if ( V_36 != NULL )
* V_36 = NULL ;
return NULL ;
}
for ( V_39 = V_38 ; V_39 != NULL ; V_39 = V_39 -> V_31 ) {
V_3 = F_1 ( V_39 -> V_1 , V_39 -> V_2 ) ;
V_37 = F_11 ( V_37 , V_3 ) ;
F_7 ( V_3 , V_39 ) ;
}
F_12 ( V_38 ) ;
return V_37 ;
}
T_5 *
F_13 ( int * V_35 , char * * V_36 )
{
T_5 * V_37 = NULL ;
T_3 * V_38 , * V_39 ;
T_1 * V_3 ;
char V_40 [ V_41 ] ;
if ( F_14 ( & V_38 , V_40 ) == - 1 ) {
* V_35 = V_42 ;
if ( V_36 != NULL )
* V_36 = F_10 ( V_40 ) ;
return NULL ;
}
if ( V_38 == NULL ) {
* V_35 = V_43 ;
if ( V_36 != NULL )
* V_36 = NULL ;
return NULL ;
}
for ( V_39 = V_38 ; V_39 != NULL ; V_39 = V_39 -> V_31 ) {
V_3 = F_1 ( V_39 -> V_1 , V_39 -> V_2 ) ;
V_37 = F_11 ( V_37 , V_3 ) ;
F_7 ( V_3 , V_39 ) ;
}
F_12 ( V_38 ) ;
return V_37 ;
}
static void
F_15 ( T_6 V_7 , T_6 T_7 V_44 )
{
F_16 ( V_7 ) ;
}
static void
F_17 ( T_6 V_45 , T_6 T_7 V_44 )
{
T_1 * V_3 = ( T_1 * ) V_45 ;
F_16 ( V_3 -> V_1 ) ;
F_16 ( V_3 -> V_2 ) ;
F_18 ( V_3 -> V_4 , F_15 , NULL ) ;
F_19 ( V_3 -> V_4 ) ;
F_16 ( V_3 ) ;
}
void
F_20 ( T_5 * V_46 )
{
F_21 ( V_46 , F_17 , NULL ) ;
F_22 ( V_46 ) ;
}
static int
F_23 ( const char * V_1 )
{
int V_47 ;
for ( V_47 = 0 ; V_48 [ V_47 ] . V_1 != NULL ; V_47 ++ ) {
if ( F_24 ( V_48 [ V_47 ] . V_1 + sizeof( L_1 ) - 1 ,
V_1 ) == 0 )
return ( V_48 [ V_47 ] . V_49 ) ;
}
return ( - 1 ) ;
}
static const char *
F_25 ( int V_49 )
{
int V_47 ;
for ( V_47 = 0 ; V_48 [ V_47 ] . V_1 != NULL ; V_47 ++ ) {
if ( V_48 [ V_47 ] . V_49 == V_49 )
return ( V_48 [ V_47 ] . V_1 + sizeof( L_1 ) - 1 ) ;
}
return ( NULL ) ;
}
const char *
F_26 ( int V_49 )
{
int V_47 ;
for ( V_47 = 0 ; V_48 [ V_47 ] . V_1 != NULL ; V_47 ++ ) {
if ( V_48 [ V_47 ] . V_49 == V_49 )
return ( V_48 [ V_47 ] . V_2 ) ;
}
return ( NULL ) ;
}
static void
F_27 ( T_6 V_45 , T_6 T_7 V_44 )
{
T_8 * V_50 = ( T_8 * ) V_45 ;
F_16 ( V_50 -> V_1 ) ;
F_16 ( V_50 -> V_2 ) ;
}
void
F_28 ( T_9 * V_51 )
{
F_21 ( V_51 -> V_52 , F_27 , NULL ) ;
F_22 ( V_51 -> V_52 ) ;
F_16 ( V_51 ) ;
}
const char *
F_29 ( int V_49 )
{
return F_25 ( V_49 ) ;
}
int F_30 ( const char * V_53 )
{
return F_23 ( V_53 ) ;
}
