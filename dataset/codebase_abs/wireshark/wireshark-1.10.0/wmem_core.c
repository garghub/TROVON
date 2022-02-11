void *
F_1 ( T_1 * V_1 , const T_2 V_2 )
{
if ( V_1 == NULL ) {
return F_2 ( V_2 ) ;
}
if ( V_2 == 0 ) {
return NULL ;
}
return V_1 -> V_3 ( V_1 -> V_4 , V_2 ) ;
}
void *
F_3 ( T_1 * V_1 , const T_2 V_2 )
{
void * V_5 ;
if ( V_2 == 0 ) {
return NULL ;
}
V_5 = F_1 ( V_1 , V_2 ) ;
memset ( V_5 , 0 , V_2 ) ;
return V_5 ;
}
void
F_4 ( T_1 * V_1 , void * V_6 )
{
if ( V_1 == NULL ) {
F_5 ( V_6 ) ;
return;
}
if ( V_6 == NULL ) {
return;
}
V_1 -> free ( V_1 -> V_4 , V_6 ) ;
}
void *
F_6 ( T_1 * V_1 , void * V_6 , const T_2 V_2 )
{
if ( V_1 == NULL ) {
return F_7 ( V_6 , V_2 ) ;
}
if ( V_6 == NULL ) {
return F_1 ( V_1 , V_2 ) ;
}
if ( V_2 == 0 ) {
F_4 ( V_1 , V_6 ) ;
return NULL ;
}
return V_1 -> realloc ( V_1 -> V_4 , V_6 , V_2 ) ;
}
void
F_8 ( T_1 * V_1 )
{
V_1 -> V_7 ( V_1 -> V_4 ) ;
}
void
F_9 ( T_1 * V_1 )
{
V_1 -> V_8 ( V_1 -> V_4 ) ;
}
void
F_10 ( T_1 * V_1 )
{
F_8 ( V_1 ) ;
V_1 -> V_9 ( V_1 ) ;
}
T_1 *
F_11 ( const T_3 type )
{
const char * V_10 ;
T_1 * V_1 ;
T_3 V_11 ;
V_10 = getenv ( L_1 ) ;
if ( V_10 == NULL ) {
V_11 = type ;
}
else if ( strncmp ( V_10 , L_2 , strlen ( L_2 ) ) == 0 ) {
V_11 = V_12 ;
}
else if ( strncmp ( V_10 , L_3 , strlen ( L_3 ) ) == 0 ) {
V_11 = V_13 ;
}
else if ( strncmp ( V_10 , L_4 , strlen ( L_4 ) ) == 0 ) {
V_11 = V_14 ;
}
else {
F_12 ( L_5 ) ;
V_11 = type ;
}
switch ( V_11 ) {
case V_12 :
V_1 = F_13 () ;
break;
case V_13 :
V_1 = F_14 () ;
break;
case V_14 :
V_1 = F_15 () ;
break;
default:
F_16 () ;
return NULL ;
} ;
V_1 -> type = V_11 ;
return V_1 ;
}
void
F_17 ( void )
{
F_18 () ;
}
void
F_19 ( void )
{
F_20 () ;
}
