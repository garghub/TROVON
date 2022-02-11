static int F_1 ( unsigned char * V_1 , int V_2 )
{
T_1 V_3 ;
while ( V_2 >= ( int ) sizeof( T_1 ) ) {
if ( ( V_3 = F_2 () ) == 0 ) return 0 ;
* ( ( T_1 * ) V_1 ) = V_3 ;
V_1 += sizeof( T_1 ) ;
V_2 -= sizeof( T_1 ) ;
}
if ( V_2 ) {
if ( ( V_3 = F_2 () ) == 0 ) return 0 ;
memcpy ( V_1 , & V_3 , V_2 ) ;
}
return 1 ;
}
static int F_3 ( void )
{ return 1 ; }
static int F_4 ( T_2 * V_4 )
{ return 1 ; }
static int F_5 ( T_2 * V_4 )
{
if ( ! F_6 ( V_4 , V_5 ) ||
! F_7 ( V_4 , V_6 ) ||
! F_8 ( V_4 , F_4 ) ||
! F_9 ( V_4 , & V_7 ) )
return 0 ;
return 1 ;
}
static T_2 * F_10 ( void )
{
T_2 * V_8 = F_11 () ;
if( ! V_8 )
return NULL ;
if( ! F_5 ( V_8 ) )
{
F_12 ( V_8 ) ;
return NULL ;
}
return V_8 ;
}
void F_13 ( void )
{
extern unsigned int V_9 [] ;
if ( V_9 [ 1 ] & ( 1 << ( 62 - 32 ) ) )
{
T_2 * V_10 = F_10 () ;
if( ! V_10 ) return;
F_14 ( V_10 ) ;
F_12 ( V_10 ) ;
F_15 () ;
}
}
void F_13 ( void ) {}
