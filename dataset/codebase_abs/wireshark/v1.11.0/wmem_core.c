void *
F_1 ( T_1 * V_1 , const T_2 V_2 )
{
if ( V_1 == NULL ) {
return F_2 ( V_2 ) ;
}
F_3 ( V_1 -> V_3 ) ;
if ( V_2 == 0 ) {
return NULL ;
}
return V_1 -> V_4 ( V_1 -> V_5 , V_2 ) ;
}
void *
F_4 ( T_1 * V_1 , const T_2 V_2 )
{
void * V_6 ;
V_6 = F_1 ( V_1 , V_2 ) ;
if ( V_6 ) {
memset ( V_6 , 0 , V_2 ) ;
}
return V_6 ;
}
void
F_5 ( T_1 * V_1 , void * V_7 )
{
if ( V_1 == NULL ) {
F_6 ( V_7 ) ;
return;
}
F_3 ( V_1 -> V_3 ) ;
if ( V_7 == NULL ) {
return;
}
V_1 -> free ( V_1 -> V_5 , V_7 ) ;
}
void *
F_7 ( T_1 * V_1 , void * V_7 , const T_2 V_2 )
{
if ( V_1 == NULL ) {
return F_8 ( V_7 , V_2 ) ;
}
if ( V_7 == NULL ) {
return F_1 ( V_1 , V_2 ) ;
}
if ( V_2 == 0 ) {
F_5 ( V_1 , V_7 ) ;
return NULL ;
}
F_3 ( V_1 -> V_3 ) ;
return V_1 -> realloc ( V_1 -> V_5 , V_7 , V_2 ) ;
}
static void
F_9 ( T_1 * V_1 , T_3 V_8 )
{
F_10 ( V_1 ,
V_8 ? V_9 : V_10 ) ;
V_1 -> V_11 ( V_1 -> V_5 ) ;
}
void
F_11 ( T_1 * V_1 )
{
F_9 ( V_1 , FALSE ) ;
}
void
F_12 ( T_1 * V_1 )
{
V_1 -> V_12 ( V_1 -> V_5 ) ;
}
void
F_13 ( T_1 * V_1 )
{
F_9 ( V_1 , TRUE ) ;
V_1 -> V_13 ( V_1 -> V_5 ) ;
F_5 ( NULL , V_1 ) ;
}
T_1 *
F_14 ( const T_4 type )
{
const char * V_14 ;
T_1 * V_1 ;
T_4 V_15 ;
V_14 = getenv ( L_1 ) ;
if ( V_14 == NULL ) {
V_15 = type ;
}
else if ( strncmp ( V_14 , L_2 , strlen ( L_2 ) ) == 0 ) {
V_15 = V_16 ;
}
else if ( strncmp ( V_14 , L_3 , strlen ( L_3 ) ) == 0 ) {
V_15 = V_17 ;
}
else if ( strncmp ( V_14 , L_4 , strlen ( L_4 ) ) == 0 ) {
V_15 = V_18 ;
}
else {
F_15 ( L_5 ) ;
V_15 = type ;
}
V_1 = F_16 ( NULL , T_1 ) ;
V_1 -> type = V_15 ;
V_1 -> V_19 = NULL ;
V_1 -> V_3 = TRUE ;
switch ( V_15 ) {
case V_16 :
F_17 ( V_1 ) ;
break;
case V_17 :
F_18 ( V_1 ) ;
break;
case V_18 :
F_19 ( V_1 ) ;
break;
default:
F_20 () ;
return NULL ;
} ;
return V_1 ;
}
void
F_21 ( void )
{
F_22 () ;
}
void
F_23 ( void )
{
F_24 () ;
}
