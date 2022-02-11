static int F_1 ( unsigned char * V_1 , int V_2 )
{
T_1 V_3 ;
while ( V_2 >= ( int ) sizeof( T_1 ) ) {
if ( ( V_3 = F_2 () ) == 0 )
return 0 ;
* ( ( T_1 * ) V_1 ) = V_3 ;
V_1 += sizeof( T_1 ) ;
V_2 -= sizeof( T_1 ) ;
}
if ( V_2 ) {
if ( ( V_3 = F_2 () ) == 0 )
return 0 ;
memcpy ( V_1 , & V_3 , V_2 ) ;
}
return 1 ;
}
static int F_3 ( void )
{
return 1 ;
}
static int F_4 ( T_2 * V_4 )
{
return 1 ;
}
static int F_5 ( T_2 * V_4 )
{
if ( ! F_6 ( V_4 , V_5 ) ||
! F_7 ( V_4 , V_6 ) ||
! F_8 ( V_4 , V_7 ) ||
! F_9 ( V_4 , F_4 ) ||
! F_10 ( V_4 , & V_8 ) )
return 0 ;
return 1 ;
}
static T_2 * F_11 ( void )
{
T_2 * V_9 = F_12 () ;
if ( V_9 == NULL )
return NULL ;
if ( ! F_5 ( V_9 ) ) {
F_13 ( V_9 ) ;
return NULL ;
}
return V_9 ;
}
void F_14 ( void )
{
extern unsigned int V_10 [] ;
if ( V_10 [ 1 ] & ( 1 << ( 62 - 32 ) ) ) {
T_2 * V_11 = F_11 () ;
if ( ! V_11 )
return;
F_15 ( V_11 ) ;
F_13 ( V_11 ) ;
F_16 () ;
}
}
void F_14 ( void )
{
}
