static T_1
F_1 ( void )
{
T_2 V_1 ;
T_3 V_2 ;
T_4 V_3 = 0 ;
V_1 = F_2 () ;
if ( F_3 ( V_1 , & V_2 , sizeof( V_2 ) ) ) {
V_3 = V_2 . V_4 ;
}
F_4 ( V_1 ) ;
if( V_3 == 0 ) {
return - 1 ;
} else{
return ( int ) V_3 ;
}
}
static T_5
F_5 ( T_1 * V_5 , T_1 * V_6 )
{
static int V_7 = - 1 ;
static T_6 V_8 = 0 ;
char V_9 [ 128 ] ;
unsigned long V_10 , V_11 ;
T_7 V_12 ;
if ( ! V_8 )
V_8 = F_6 ( V_13 ) ;
if ( V_8 == - 1 )
return FALSE ;
if ( V_7 < 0 ) {
char V_14 [ 64 ] ;
F_7 ( V_14 , sizeof( V_14 ) , L_1 , F_8 () ) ;
V_7 = F_9 ( V_14 , V_15 ) ;
}
if ( V_7 < 0 )
return FALSE ;
V_12 = F_10 ( V_7 , V_9 , sizeof( V_9 ) - 1 , 0 ) ;
if ( V_12 <= 0 )
return FALSE ;
V_9 [ V_12 ] = '\0' ;
if ( sscanf ( V_9 , L_2 , & V_10 , & V_11 ) != 2 )
return FALSE ;
if ( V_5 )
* V_5 = V_8 * ( T_1 ) V_10 ;
if ( V_6 )
* V_6 = V_8 * ( T_1 ) V_11 ;
return TRUE ;
}
static T_1
F_11 ( void )
{
T_1 V_10 ;
if ( ! F_5 ( & V_10 , NULL ) )
V_10 = 0 ;
return V_10 ;
}
static T_1
F_12 ( void )
{
T_1 V_11 ;
if ( ! F_5 ( NULL , & V_11 ) )
V_11 = 0 ;
return V_11 ;
}
void
F_13 ( const T_8 * V_16 )
{
if ( V_17 >= V_18 )
return;
V_19 [ V_17 ++ ] = V_16 ;
}
const char *
F_14 ( T_9 V_20 , T_1 * V_21 )
{
if ( V_20 >= V_17 )
return NULL ;
if ( V_21 )
* V_21 = V_19 [ V_20 ] -> F_15 () ;
return V_19 [ V_20 ] -> V_22 ;
}
void
F_16 ( void )
{
T_9 V_23 ;
for ( V_23 = 0 ; V_23 < V_17 ; V_23 ++ ) {
if ( V_19 [ V_23 ] -> V_24 )
V_19 [ V_23 ] -> V_24 () ;
}
}
