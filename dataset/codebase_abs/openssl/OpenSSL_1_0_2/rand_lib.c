int F_1 ( const T_1 * V_1 )
{
#ifndef F_2
if ( V_2 ) {
F_3 ( V_2 ) ;
V_2 = NULL ;
}
#endif
V_3 = V_1 ;
return 1 ;
}
const T_1 * F_4 ( void )
{
if ( ! V_3 ) {
#ifndef F_2
T_2 * V_4 = F_5 () ;
if ( V_4 ) {
V_3 = F_6 ( V_4 ) ;
if ( ! V_3 ) {
F_3 ( V_4 ) ;
V_4 = NULL ;
}
}
if ( V_4 )
V_2 = V_4 ;
else
#endif
V_3 = F_7 () ;
}
return V_3 ;
}
int F_8 ( T_2 * V_5 )
{
const T_1 * V_6 = NULL ;
if ( V_5 ) {
if ( ! F_9 ( V_5 ) )
return 0 ;
V_6 = F_6 ( V_5 ) ;
if ( ! V_6 ) {
F_3 ( V_5 ) ;
return 0 ;
}
}
F_1 ( V_6 ) ;
V_2 = V_5 ;
return 1 ;
}
void F_10 ( void )
{
const T_1 * V_1 = F_4 () ;
if ( V_1 && V_1 -> V_7 )
V_1 -> V_7 () ;
F_1 ( NULL ) ;
}
void F_11 ( const void * V_8 , int V_9 )
{
const T_1 * V_1 = F_4 () ;
if ( V_1 && V_1 -> V_10 )
V_1 -> V_10 ( V_8 , V_9 ) ;
}
void F_12 ( const void * V_8 , int V_9 , double V_11 )
{
const T_1 * V_1 = F_4 () ;
if ( V_1 && V_1 -> V_12 )
V_1 -> V_12 ( V_8 , V_9 , V_11 ) ;
}
int F_13 ( unsigned char * V_8 , int V_9 )
{
const T_1 * V_1 = F_4 () ;
if ( V_1 && V_1 -> V_13 )
return V_1 -> V_13 ( V_8 , V_9 ) ;
return ( - 1 ) ;
}
int F_14 ( unsigned char * V_8 , int V_9 )
{
const T_1 * V_1 = F_4 () ;
if ( V_1 && V_1 -> V_14 )
return V_1 -> V_14 ( V_8 , V_9 ) ;
return ( - 1 ) ;
}
int F_15 ( void )
{
const T_1 * V_1 = F_4 () ;
if ( V_1 && V_1 -> V_15 )
return V_1 -> V_15 () ;
return 0 ;
}
static T_3 F_16 ( T_4 * V_16 , unsigned char * * V_17 ,
int V_11 , T_3 V_18 , T_3 V_19 )
{
V_18 = ( ( V_18 + 19 ) / 20 ) * 20 ;
* V_17 = F_17 ( V_18 ) ;
if ( ! * V_17 )
return 0 ;
if ( F_18 ( * V_17 , V_18 , 0 , 0 ) <= 0 ) {
F_19 ( * V_17 ) ;
* V_17 = NULL ;
return 0 ;
}
return V_18 ;
}
static void F_20 ( T_4 * V_16 , unsigned char * V_20 , T_3 V_21 )
{
if ( V_20 ) {
F_21 ( V_20 , V_21 ) ;
F_19 ( V_20 ) ;
}
}
static T_3 F_22 ( T_4 * V_16 , unsigned char * * V_17 )
{
static unsigned char V_8 [ 16 ] ;
static unsigned long V_22 ;
F_23 ( V_8 , & V_22 ) ;
* V_17 = V_8 ;
return sizeof( V_8 ) ;
}
static int F_24 ( T_4 * V_16 , const void * V_23 , int V_24 ,
double V_11 )
{
F_7 () -> V_12 ( V_23 , V_24 , V_11 ) ;
return 1 ;
}
static int F_25 ( T_4 * V_16 , const void * V_23 , int V_24 )
{
F_7 () -> V_10 ( V_23 , V_24 ) ;
return 1 ;
}
void F_26 ( int type , int V_25 )
{
V_26 = type ;
V_27 = V_25 ;
}
int F_27 ( void )
{
T_4 * V_28 ;
T_3 V_29 ;
unsigned char V_30 [ 32 ] , * V_31 ;
# ifndef F_28
if ( V_26 >> 16 ) {
F_29 ( V_32 , V_33 ) ;
return 0 ;
}
# endif
V_28 = F_30 () ;
if ( F_31 ( V_28 , V_26 , V_27 ) <= 0 ) {
F_29 ( V_32 , V_34 ) ;
return 0 ;
}
F_32 ( V_28 ,
F_16 , F_20 , 20 ,
F_16 , F_20 ) ;
F_33 ( V_28 , F_22 , 0 ,
F_25 , F_24 ) ;
strcpy ( ( char * ) V_30 , L_1 ) ;
V_29 = F_22 ( V_28 , & V_31 ) ;
memcpy ( V_30 + 16 , V_31 , V_29 ) ;
if ( F_34 ( V_28 , V_30 , sizeof( V_30 ) ) <= 0 ) {
F_29 ( V_32 , V_35 ) ;
return 0 ;
}
F_35 ( F_36 () ) ;
return 1 ;
}
