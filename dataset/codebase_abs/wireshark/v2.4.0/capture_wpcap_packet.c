void
F_1 ( void )
{
static const T_1 V_1 [] = {
F_2 ( V_2 , FALSE ) ,
F_2 ( V_3 , FALSE ) ,
F_2 ( V_4 , FALSE ) ,
F_2 ( V_5 , FALSE ) ,
{ NULL , NULL , FALSE }
} ;
T_2 * V_6 ;
const T_1 * V_7 ;
V_6 = F_3 ( L_1 , 0 ) ;
if ( ! V_6 ) {
return;
}
V_7 = V_1 ;
while ( V_7 -> V_8 ) {
if ( ! F_4 ( V_6 , V_7 -> V_8 , V_7 -> V_9 ) ) {
if ( V_7 -> V_10 ) {
* V_7 -> V_9 = NULL ;
} else {
return;
}
}
V_7 ++ ;
}
V_11 = TRUE ;
}
char *
F_5 ( void )
{
if( ! V_11 ) {
return NULL ;
}
return F_6 () ;
}
void *
F_7 ( char * V_12 )
{
T_3 V_13 ;
F_8 ( V_11 ) ;
V_13 = F_9 ( V_12 ) ;
return V_13 ;
}
void
F_10 ( void * V_13 )
{
F_8 ( V_11 ) ;
F_11 ( V_13 ) ;
}
int
F_12 ( void * V_13 , T_4 V_14 , int V_15 , char * V_16 , unsigned int * V_17 )
{
BOOLEAN V_18 ;
T_4 V_19 = ( sizeof( V_20 ) + ( * V_17 ) - 1 ) ;
T_5 V_21 ;
F_8 ( V_11 ) ;
if( V_22 == NULL ) {
F_13 ( L_2 ) ;
return 0 ;
}
V_21 = F_14 ( V_23 | V_24 , V_19 ) ;
if ( V_21 == NULL ) {
F_13 ( L_3 , V_19 ) ;
return 0 ;
}
V_21 -> V_14 = V_14 ;
V_21 -> V_25 = * V_17 ;
memcpy ( V_21 -> V_26 , V_16 , * V_17 ) ;
V_18 = V_22 ( V_13 , V_15 , V_21 ) ;
if( V_18 ) {
if( V_21 -> V_25 <= * V_17 ) {
memcpy ( V_16 , V_21 -> V_26 , V_21 -> V_25 ) ;
* V_17 = V_21 -> V_25 ;
} else {
F_13 ( L_4 , V_14 , V_21 -> V_25 , * V_17 ) ;
V_18 = FALSE ;
}
}
F_15 ( V_21 ) ;
if( V_18 ) {
return 1 ;
} else {
return 0 ;
}
}
int
F_16 ( void * V_13 , T_4 V_14 , T_6 * V_16 )
{
BOOLEAN V_18 ;
int V_17 = sizeof( T_6 ) ;
V_18 = F_12 ( V_13 , V_14 , FALSE , ( char * ) V_16 , & V_17 ) ;
if( V_18 && V_17 == sizeof( T_6 ) ) {
return 1 ;
} else {
return 0 ;
}
}
int
F_17 ( void * V_13 , T_4 V_14 , T_4 * V_16 )
{
BOOLEAN V_18 ;
int V_17 = sizeof( T_4 ) ;
V_18 = F_12 ( V_13 , V_14 , FALSE , ( char * ) V_16 , & V_17 ) ;
if( V_18 && V_17 == sizeof( T_4 ) ) {
return 1 ;
} else {
return 0 ;
}
}
void
F_1 ( void )
{
return;
}
