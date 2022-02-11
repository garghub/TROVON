void F_1 ( void * V_1 )
{
V_2 = ( int ( * ) ( void * ) ) V_1 ;
}
int F_2 ( const char * V_3 , int V_4 , int V_5 , ... )
{
int V_6 ;
struct V_7 {
const char * V_3 ;
int V_4 ;
int V_5 ;
unsigned int args [ 12 ] ;
} args ;
T_1 V_8 ;
args . V_3 = V_3 ;
args . V_4 = V_4 ;
args . V_5 = V_5 ;
va_start ( V_8 , V_5 ) ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ )
args . args [ V_6 ] = va_arg (list, unsigned int) ;
va_end ( V_8 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
args . args [ V_4 + V_6 ] = 0 ;
if ( V_2 ( & args ) < 0 )
return - 1 ;
return ( V_5 > 0 ) ? args . args [ V_4 ] : 0 ;
}
static int F_3 ( const char * V_3 , int V_4 , int V_5 ,
unsigned int * V_9 , ... )
{
int V_6 ;
struct V_7 {
const char * V_3 ;
int V_4 ;
int V_5 ;
unsigned int args [ 12 ] ;
} args ;
T_1 V_8 ;
args . V_3 = V_3 ;
args . V_4 = V_4 ;
args . V_5 = V_5 ;
va_start ( V_8 , V_9 ) ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ )
args . args [ V_6 ] = va_arg (list, unsigned int) ;
va_end ( V_8 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
args . args [ V_4 + V_6 ] = 0 ;
if ( V_2 ( & args ) < 0 )
return - 1 ;
if ( V_9 != ( void * ) 0 )
for ( V_6 = 1 ; V_6 < V_5 ; ++ V_6 )
V_9 [ V_6 - 1 ] = args . args [ V_4 + V_6 ] ;
return ( V_5 > 0 ) ? args . args [ V_4 ] : 0 ;
}
static int F_4 ( const char * V_10 , const char * V_11 )
{
for (; * V_11 ; ++ V_11 )
if ( * V_10 ++ != * V_11 )
return 0 ;
return 1 ;
}
static int F_5 ( void )
{
T_2 V_12 , V_13 ;
char V_14 [ 64 ] ;
V_12 = F_6 ( L_1 ) ;
if ( V_12 == ( T_2 ) - 1 )
return 0 ;
if ( F_7 ( V_12 , L_2 , V_14 , sizeof( V_14 ) ) <= 0 )
return 0 ;
V_14 [ sizeof( V_14 ) - 1 ] = 0 ;
printf ( L_3 , V_14 ) ;
if ( ! F_4 ( V_14 , L_4 )
&& ! F_4 ( V_14 , L_5 ) )
return 0 ;
V_13 = F_6 ( L_6 ) ;
if ( V_13 == ( T_2 ) - 1 ) {
V_13 = F_6 ( L_7 ) ;
if ( V_13 == ( T_2 ) - 1 ) {
printf ( L_8 ) ;
return 0 ;
}
}
if ( F_7 ( V_13 , L_9 , & V_15 , sizeof( V_15 ) ) <= 0 ) {
printf ( L_10 ) ;
return 0 ;
}
V_16 = ( V_17 ) F_2 ( L_11 , 1 , 1 , L_12 ) ;
if ( V_16 == ( V_17 ) - 1 ) {
V_16 = ( V_17 ) F_2 ( L_11 , 1 , 1 , L_13 ) ;
if ( V_16 == ( V_17 ) - 1 ) {
printf ( L_14 ) ;
return 0 ;
}
}
printf ( L_15 ) ;
return 1 ;
}
void * F_8 ( unsigned long V_18 , unsigned long V_19 , unsigned long V_20 )
{
int V_21 ;
unsigned int V_22 ;
if ( V_23 < 0 )
V_23 = F_5 () ;
if ( V_20 || ! V_23 )
return ( void * ) F_2 ( L_16 , 3 , 1 , V_18 , V_19 , V_20 ) ;
V_21 = F_3 ( L_17 , 5 , 2 , & V_22 , L_16 , V_16 ,
V_20 , V_19 , V_18 ) ;
if ( V_21 != 0 || V_22 == - 1 )
return ( void * ) - 1 ;
V_21 = F_3 ( L_17 , 5 , 2 , & V_22 , L_16 , V_15 ,
V_20 , V_19 , V_18 ) ;
V_21 = F_2 ( L_17 , 6 , 1 , L_18 , V_15 ,
0x12 , V_19 , V_18 , V_18 ) ;
return ( void * ) V_18 ;
}
void * F_9 ( unsigned long V_19 )
{
unsigned long V_24 = ( unsigned long ) V_25 , V_26 = ( unsigned long ) V_27 ;
void * V_28 ;
void * V_29 ;
V_28 = F_8 ( V_24 , V_26 - V_24 , 0 ) ;
printf ( L_19 ,
V_24 , V_26 , V_26 - V_24 , V_28 ) ;
V_29 = malloc ( V_19 ) ;
if ( ! V_29 )
F_10 ( L_20 ) ;
return V_29 ;
}
void F_11 ( void )
{
F_2 ( L_21 , 0 , 0 ) ;
}
void * F_6 ( const char * V_30 )
{
return ( T_2 ) F_2 ( L_22 , 1 , 1 , V_30 ) ;
}
int F_7 ( const void * T_2 , const char * V_30 , void * V_31 ,
const int V_32 )
{
return F_2 ( L_23 , 4 , 1 , T_2 , V_30 , V_31 , V_32 ) ;
}
int F_12 ( const void * T_2 , const char * V_30 , const void * V_31 ,
const int V_32 )
{
return F_2 ( L_24 , 4 , 1 , T_2 , V_30 , V_31 , V_32 ) ;
}
