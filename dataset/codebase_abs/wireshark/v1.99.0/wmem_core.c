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
T_1 * V_1 ;
T_4 V_14 ;
if ( V_15 ) {
V_14 = V_16 ;
}
else {
V_14 = type ;
}
V_1 = F_15 ( NULL , T_1 ) ;
V_1 -> type = V_14 ;
V_1 -> V_17 = NULL ;
V_1 -> V_3 = TRUE ;
switch ( V_14 ) {
case V_18 :
F_16 ( V_1 ) ;
break;
case V_19 :
F_17 ( V_1 ) ;
break;
case V_20 :
F_18 ( V_1 ) ;
break;
case V_21 :
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
const char * V_22 ;
V_22 = getenv ( L_1 ) ;
if ( V_22 == NULL ) {
V_15 = FALSE ;
}
else {
V_15 = TRUE ;
if ( strncmp ( V_22 , L_2 , strlen ( L_2 ) ) == 0 ) {
V_16 = V_18 ;
}
else if ( strncmp ( V_22 , L_3 , strlen ( L_3 ) ) == 0 ) {
V_16 = V_19 ;
}
else if ( strncmp ( V_22 , L_4 , strlen ( L_4 ) ) == 0 ) {
V_16 = V_21 ;
}
else if ( strncmp ( V_22 , L_5 , strlen ( L_5 ) ) == 0 ) {
V_16 = V_20 ;
}
else {
F_22 ( L_6 ) ;
V_15 = FALSE ;
}
}
F_23 () ;
F_24 () ;
}
void
F_25 ( void )
{
F_26 () ;
}
