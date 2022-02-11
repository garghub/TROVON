T_1 * F_1 ( void )
{
T_1 * V_1 = F_2 ( sizeof( V_2 ) ) ;
if ( V_1 == NULL )
return NULL ;
if ( ! F_3 ( V_1 , 0x400 ) ) {
F_4 ( V_1 ) ;
return NULL ;
}
return V_1 ;
}
int F_5 ( T_1 * V_1 )
{
F_6 ( V_1 ) ;
return 1 ;
}
int F_7 ( T_1 * V_1 )
{
F_6 ( V_1 ) ;
return 1 ;
}
int F_8 ( T_1 * V_1 )
{
F_9 ( V_1 ) ;
return 1 ;
}
void F_10 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return;
F_11 ( V_1 ) ;
F_4 ( V_1 ) ;
return;
}
int F_12 ( T_2 * V_3 , void (* F_13)( void ) )
{
LONG volatile * V_1 = ( LONG * ) V_3 ;
LONG V_4 ;
if ( * V_1 == V_5 )
return 1 ;
do {
V_4 = F_14 ( V_1 , V_6 , V_7 ) ;
if ( V_4 == V_7 ) {
F_13 () ;
* V_1 = V_5 ;
return 1 ;
}
} while ( V_4 == V_6 );
return ( * V_1 == V_5 ) ;
}
int F_15 ( T_3 * V_8 , void (* F_16)( void * ) )
{
* V_8 = F_17 () ;
if ( * V_8 == V_9 )
return 0 ;
return 1 ;
}
void * F_18 ( T_3 * V_8 )
{
return F_19 ( * V_8 ) ;
}
int F_20 ( T_3 * V_8 , void * V_10 )
{
if ( F_21 ( * V_8 , V_10 ) == 0 )
return 0 ;
return 1 ;
}
int F_22 ( T_3 * V_8 )
{
if ( F_23 ( * V_8 ) == 0 )
return 0 ;
return 1 ;
}
T_4 F_24 ( void )
{
return F_25 () ;
}
int F_26 ( T_4 V_11 , T_4 V_12 )
{
return ( V_11 == V_12 ) ;
}
int F_27 ( int * V_10 , int V_13 , int * V_14 , T_1 * V_1 )
{
* V_14 = F_28 ( V_10 , V_13 ) + V_13 ;
return 1 ;
}
