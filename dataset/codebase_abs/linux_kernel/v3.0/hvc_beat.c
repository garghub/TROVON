static int F_1 ( T_1 V_1 , char * V_2 , int V_3 )
{
static unsigned char V_4 [ sizeof( unsigned long ) * 2]
F_2 ( ( F_3 ( sizeof( unsigned long ) ) ) ) ;
static int V_5 = 0 ;
T_2 V_6 ;
V_7:
if ( V_5 ) {
if ( V_5 > V_3 ) {
memcpy ( V_2 , V_4 , V_3 ) ;
V_5 -= V_3 ;
memmove ( V_4 + V_3 , V_4 , V_5 ) ;
return V_3 ;
} else {
int V_8 ;
memcpy ( V_2 , V_4 , V_5 ) ;
V_8 = V_5 ;
V_5 = 0 ;
return V_8 ;
}
}
if ( F_4 ( V_1 , & V_6 ,
( ( T_2 * ) V_4 ) , ( ( T_2 * ) V_4 ) + 1 ) == 0 ) {
V_5 = V_6 ;
goto V_7;
}
return 0 ;
}
static int F_5 ( T_1 V_1 , const char * V_2 , int V_3 )
{
unsigned long V_9 [ 2 ] ;
int V_10 , V_11 ;
for ( V_10 = V_3 ; V_10 > 0 ; V_10 -= V_11 ) {
V_11 = ( V_10 > 16 ) ? 16 : V_10 ;
memcpy ( V_9 , V_2 , V_11 ) ;
F_6 ( V_1 , V_11 , V_9 [ 0 ] , V_9 [ 1 ] ) ;
V_2 += V_11 ;
}
return V_3 ;
}
static int F_7 ( char * V_12 )
{
V_13 = F_8 ( V_12 , NULL , 0 ) ;
return 0 ;
}
static int T_3 F_9 ( void )
{
if ( V_13 && F_10 ( L_1 ) ) {
F_11 ( 0 , 0 , & V_14 ) ;
}
return 0 ;
}
static int T_3 F_12 ( void )
{
struct V_15 * V_16 ;
if ( ! F_13 ( V_17 ) )
return - V_18 ;
V_16 = F_14 ( 0 , V_19 , & V_14 , 16 ) ;
if ( F_15 ( V_16 ) )
return F_16 ( V_16 ) ;
V_20 = V_16 ;
return 0 ;
}
static void T_4 F_17 ( void )
{
if ( V_20 )
F_18 ( V_20 ) ;
}
