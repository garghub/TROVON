void F_1 ( void * V_1 )
{
#ifndef F_2
V_2 = ( int ( * ) ( void * ) ) V_1 ;
#endif
}
int F_3 ( const char * V_3 , int V_4 , int V_5 , ... )
{
int V_6 ;
struct V_7 args ;
T_1 V_8 ;
args . V_3 = F_4 ( F_5 ( V_3 ) ) ;
args . V_4 = F_4 ( V_4 ) ;
args . V_5 = F_4 ( V_5 ) ;
va_start ( V_8 , V_5 ) ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ )
args . args [ V_6 ] = F_4 ( va_arg ( V_8 , V_9 ) ) ;
va_end ( V_8 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
args . args [ V_4 + V_6 ] = 0 ;
if ( V_2 ( & args ) < 0 )
return V_10 ;
return ( V_5 > 0 ) ? F_6 ( args . args [ V_4 ] ) : 0 ;
}
static int F_7 ( const char * V_3 , int V_4 , int V_5 ,
V_9 * V_11 , ... )
{
int V_6 ;
struct V_7 args ;
T_1 V_8 ;
args . V_3 = F_4 ( F_5 ( V_3 ) ) ;
args . V_4 = F_4 ( V_4 ) ;
args . V_5 = F_4 ( V_5 ) ;
va_start ( V_8 , V_11 ) ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ )
args . args [ V_6 ] = F_4 ( va_arg ( V_8 , V_9 ) ) ;
va_end ( V_8 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
args . args [ V_4 + V_6 ] = 0 ;
if ( V_2 ( & args ) < 0 )
return V_10 ;
if ( V_11 != NULL )
for ( V_6 = 1 ; V_6 < V_5 ; ++ V_6 )
V_11 [ V_6 - 1 ] = F_6 ( args . args [ V_4 + V_6 ] ) ;
return ( V_5 > 0 ) ? F_6 ( args . args [ V_4 ] ) : 0 ;
}
static int F_8 ( const char * V_12 , const char * V_13 )
{
for (; * V_13 ; ++ V_13 )
if ( * V_12 ++ != * V_13 )
return 0 ;
return 1 ;
}
static int F_9 ( void )
{
T_2 V_14 , V_15 ;
char V_16 [ 64 ] ;
V_14 = F_10 ( L_1 ) ;
if ( V_14 == ( T_2 ) - 1 )
return 0 ;
if ( F_11 ( V_14 , L_2 , V_16 , sizeof( V_16 ) ) <= 0 )
return 0 ;
V_16 [ sizeof( V_16 ) - 1 ] = 0 ;
printf ( L_3 , V_16 ) ;
if ( ! F_8 ( V_16 , L_4 )
&& ! F_8 ( V_16 , L_5 ) )
return 0 ;
V_15 = F_10 ( L_6 ) ;
if ( V_15 == ( T_2 ) - 1 ) {
V_15 = F_10 ( L_7 ) ;
if ( V_15 == ( T_2 ) - 1 ) {
printf ( L_8 ) ;
return 0 ;
}
}
if ( F_11 ( V_15 , L_9 , & V_17 , sizeof( V_17 ) ) <= 0 ) {
printf ( L_10 ) ;
return 0 ;
}
V_18 = F_3 ( L_11 , 1 , 1 , L_12 ) ;
if ( V_18 == V_10 ) {
V_18 = F_3 ( L_11 , 1 , 1 , L_13 ) ;
if ( V_18 == V_10 ) {
printf ( L_14 ) ;
return 0 ;
}
}
printf ( L_15 ) ;
return 1 ;
}
unsigned int F_12 ( unsigned long V_19 , unsigned long V_20 ,
unsigned long V_21 )
{
int V_22 ;
V_9 V_23 ;
if ( V_24 < 0 )
V_24 = F_9 () ;
if ( V_21 || ! V_24 )
return F_3 ( L_16 , 3 , 1 , V_19 , V_20 , V_21 ) ;
V_22 = F_7 ( L_17 , 5 , 2 , & V_23 , L_16 , V_18 ,
V_21 , V_20 , V_19 ) ;
if ( V_22 != 0 || V_23 == - 1 )
return - 1 ;
V_22 = F_7 ( L_17 , 5 , 2 , & V_23 , L_16 , V_17 ,
V_21 , V_20 , V_19 ) ;
V_22 = F_3 ( L_17 , 6 , 1 , L_18 , V_17 ,
0x12 , V_20 , V_19 , V_19 ) ;
return V_19 ;
}
void * F_13 ( unsigned long V_20 )
{
unsigned long V_25 = ( unsigned long ) V_26 , V_27 = ( unsigned long ) V_28 ;
unsigned long V_29 ;
void * V_30 ;
V_29 = ( unsigned long ) F_12 ( V_25 , V_27 - V_25 , 0 ) ;
printf ( L_19 ,
V_25 , V_27 , V_27 - V_25 , V_29 ) ;
V_30 = malloc ( V_20 ) ;
if ( ! V_30 )
F_14 ( L_20 ) ;
return V_30 ;
}
void F_15 ( void )
{
F_3 ( L_21 , 0 , 0 ) ;
}
void * F_10 ( const char * V_31 )
{
return ( void * ) ( unsigned long ) F_3 ( L_22 , 1 , 1 , V_31 ) ;
}
int F_11 ( const void * T_2 , const char * V_31 , void * V_32 ,
const int V_33 )
{
return F_3 ( L_23 , 4 , 1 , T_2 , V_31 , V_32 , V_33 ) ;
}
int F_16 ( const void * T_2 , const char * V_31 , const void * V_32 ,
const int V_33 )
{
return F_3 ( L_24 , 4 , 1 , T_2 , V_31 , V_32 , V_33 ) ;
}
