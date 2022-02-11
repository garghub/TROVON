static T_1 F_1 ( const char * type , T_1 V_1 )
{
unsigned long args [ 5 ] ;
args [ 0 ] = ( unsigned long ) type ;
args [ 1 ] = 1 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned int ) V_1 ;
args [ 4 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
return ( T_1 ) args [ 4 ] ;
}
inline T_1 F_3 ( T_1 V_1 )
{
return F_1 ( L_1 , V_1 ) ;
}
T_1 F_4 ( T_1 V_1 )
{
T_1 V_2 ;
if ( ( V_3 ) V_1 == - 1 )
return 0 ;
V_2 = F_3 ( V_1 ) ;
if ( ( V_3 ) V_2 == - 1 )
return 0 ;
return V_2 ;
}
inline T_1 F_5 ( T_1 V_1 )
{
T_1 V_2 ;
if ( ( V_3 ) V_1 == - 1 )
return 0 ;
V_2 = F_1 ( L_2 , V_1 ) ;
if ( ( V_3 ) V_2 == - 1 )
return 0 ;
return V_2 ;
}
inline T_1 F_6 ( T_1 V_1 )
{
return F_1 ( V_4 , V_1 ) ;
}
T_1 F_7 ( T_1 V_1 )
{
T_1 V_5 ;
if ( ( V_3 ) V_1 == - 1 )
return 0 ;
V_5 = F_6 ( V_1 ) ;
if ( ( V_3 ) V_5 == - 1 )
return 0 ;
return V_5 ;
}
int F_8 ( T_1 V_1 , const char * V_6 )
{
unsigned long args [ 6 ] ;
if ( ! V_1 || ! V_6 )
return - 1 ;
args [ 0 ] = ( unsigned long ) L_3 ;
args [ 1 ] = 2 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned int ) V_1 ;
args [ 4 ] = ( unsigned long ) V_6 ;
args [ 5 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
return ( int ) args [ 5 ] ;
}
int F_9 ( T_1 V_1 , const char * V_6 ,
char * V_7 , int V_8 )
{
unsigned long args [ 8 ] ;
int V_9 ;
V_9 = F_8 ( V_1 , V_6 ) ;
if ( ( V_9 > V_8 ) || ( V_9 == 0 ) || ( V_9 == - 1 ) )
return - 1 ;
args [ 0 ] = ( unsigned long ) V_10 ;
args [ 1 ] = 4 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned int ) V_1 ;
args [ 4 ] = ( unsigned long ) V_6 ;
args [ 5 ] = ( unsigned long ) V_7 ;
args [ 6 ] = V_8 ;
args [ 7 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
return ( int ) args [ 7 ] ;
}
int F_10 ( T_1 V_1 , const char * V_6 )
{
int V_11 ;
if ( F_9 ( V_1 , V_6 , ( char * ) & V_11 , sizeof( int ) ) != - 1 )
return V_11 ;
return - 1 ;
}
int F_11 ( T_1 V_1 , const char * V_12 , int V_13 )
{
int V_14 ;
V_14 = F_10 ( V_1 , V_12 ) ;
if ( V_14 == - 1 )
return V_13 ;
return V_14 ;
}
int F_12 ( T_1 V_1 , const char * V_6 )
{
int V_14 ;
V_14 = F_8 ( V_1 , V_6 ) ;
if ( V_14 == - 1 )
return 0 ;
return 1 ;
}
void F_13 ( T_1 V_1 , const char * V_6 , char * V_15 ,
int V_16 )
{
int V_17 ;
V_17 = F_9 ( V_1 , V_6 , V_15 , V_16 ) ;
if ( V_17 != - 1 )
return;
V_15 [ 0 ] = 0 ;
}
int F_14 ( T_1 V_1 , const char * V_18 )
{
char V_19 [ 128 ] ;
F_9 ( V_1 , L_4 , V_19 , sizeof( V_19 ) ) ;
if ( strcmp ( V_19 , V_18 ) == 0 )
return 1 ;
return 0 ;
}
T_1 F_15 ( T_1 V_20 , const char * V_21 )
{
T_1 V_22 ;
int error ;
char V_23 [ 128 ] ;
for( V_22 = V_20 ; V_22 ;
V_22 = F_7 ( V_22 ) ) {
error = F_9 ( V_22 , L_4 , V_23 ,
sizeof( V_23 ) ) ;
if( error == - 1 ) continue;
if( strcmp ( V_21 , V_23 ) == 0 ) return V_22 ;
}
return 0 ;
}
char * F_16 ( T_1 V_1 , char * V_7 )
{
unsigned long args [ 7 ] ;
* V_7 = 0 ;
if ( ( V_3 ) V_1 == - 1 )
return V_7 ;
args [ 0 ] = ( unsigned long ) V_24 ;
args [ 1 ] = 3 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned int ) V_1 ;
args [ 4 ] = 0 ;
args [ 5 ] = ( unsigned long ) V_7 ;
args [ 6 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
return V_7 ;
}
char * F_17 ( T_1 V_1 , const char * V_25 , char * V_7 )
{
unsigned long args [ 7 ] ;
char V_26 [ 32 ] ;
if ( ( V_3 ) V_1 == - 1 ) {
* V_7 = 0 ;
return V_7 ;
}
if ( V_25 == V_7 ) {
strcpy ( V_26 , V_25 ) ;
V_25 = V_26 ;
}
args [ 0 ] = ( unsigned long ) V_24 ;
args [ 1 ] = 3 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned int ) V_1 ;
args [ 4 ] = ( unsigned long ) V_25 ;
args [ 5 ] = ( unsigned long ) V_7 ;
args [ 6 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
return V_7 ;
}
T_1 F_18 ( const char * V_18 )
{
unsigned long args [ 5 ] ;
if ( ! V_18 )
return 0 ;
args [ 0 ] = ( unsigned long ) L_5 ;
args [ 1 ] = 1 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned long ) V_18 ;
args [ 4 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
return ( int ) args [ 4 ] ;
}
int F_19 ( T_1 V_1 , const char * V_6 )
{
char V_26 [ 32 ] ;
* V_26 = 0 ;
do {
F_17 ( V_1 , V_26 , V_26 ) ;
if ( ! strcmp ( V_26 , V_6 ) )
return 1 ;
} while ( * V_26 );
return 0 ;
}
int
F_20 ( T_1 V_1 , const char * V_27 , char * V_28 , int V_29 )
{
unsigned long args [ 8 ] ;
if ( V_29 == 0 )
return 0 ;
if ( ( V_27 == 0 ) || ( V_28 == 0 ) )
return 0 ;
#ifdef F_21
if ( V_30 ) {
F_22 ( V_27 , V_28 ) ;
return 0 ;
}
#endif
args [ 0 ] = ( unsigned long ) L_6 ;
args [ 1 ] = 4 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned int ) V_1 ;
args [ 4 ] = ( unsigned long ) V_27 ;
args [ 5 ] = ( unsigned long ) V_28 ;
args [ 6 ] = V_29 ;
args [ 7 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
return ( int ) args [ 7 ] ;
}
inline T_1 F_23 ( int V_31 )
{
unsigned long args [ 5 ] ;
T_1 V_1 ;
args [ 0 ] = ( unsigned long ) L_7 ;
args [ 1 ] = 1 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned int ) V_31 ;
args [ 4 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
V_1 = ( int ) args [ 4 ] ;
if ( ( V_3 ) V_1 == - 1 )
return 0 ;
return V_1 ;
}
int F_24 ( int V_32 , char * V_7 , int V_8 )
{
unsigned long args [ 7 ] ;
args [ 0 ] = ( unsigned long ) L_8 ;
args [ 1 ] = 3 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned int ) V_32 ;
args [ 4 ] = ( unsigned long ) V_7 ;
args [ 5 ] = V_8 ;
args [ 6 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
return ( int ) args [ 6 ] ;
}
