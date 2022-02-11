void
F_1 ( long V_1 , ... )
{ T_1 V_2 ;
if ( V_3 . V_4 )
{ va_start ( V_2 , V_1 ) ;
( V_3 . V_4 )
( V_3 . V_5 , ( unsigned long ) V_1 , V_2 ) ;
va_end ( V_2 ) ;
} }
int
F_2 ( char * V_6 , char * V_7 , unsigned long V_8 )
{
int V_9 ;
F_3 () ;
V_3 . V_10 = V_11 ;
V_3 . V_5 = - 1 ;
V_3 . V_8 = V_8 | ( V_12 | V_13 | V_14 ) ;
V_9 = strlen ( V_6 ) ;
memcpy ( V_3 . V_6 , V_6 ,
( V_9 < sizeof( V_3 . V_6 ) ) ?
V_9 : sizeof( V_3 . V_6 ) - 1 ) ;
V_9 = strlen ( V_7 ) ;
memcpy ( V_3 . V_7 , V_7 ,
( V_9 < sizeof( V_3 . V_7 ) ) ?
V_9 : sizeof( V_3 . V_7 ) - 1 ) ;
F_4 ( L_1 , & V_3 ) ;
if ( V_3 . V_15 )
{
return ( 1 ) ;
}
if ( V_3 . V_16 != NULL
&& ( V_3 . V_17 . V_18 ||
V_3 . V_17 . V_19 ) )
{
F_4 ( L_2 , V_6 ) ;
V_3 . V_16 =
( ( V_20 * ) & V_3 ) -> V_16 ;
F_3 () ;
}
return ( 0 ) ;
}
void
F_5 ( unsigned long V_8 )
{
V_3 . V_8 = V_8 | ( V_12 | V_13 | V_14 ) ;
}
void
F_3 ( void )
{
if ( V_3 . V_16 )
{
( V_3 . V_16 ) ( & V_3 ) ;
}
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
}
void F_6 ( char * V_21 , ... ) {
T_1 V_2 ;
va_start ( V_2 , V_21 ) ;
if ( V_3 . V_16 &&
( V_3 . V_22 || V_3 . V_23 ) &&
( V_3 . V_8 & V_24 ) ) {
if ( V_3 . V_22 ) {
( * ( V_3 . V_22 ) ) ( V_3 . V_5 ,
( V_21 [ 0 ] != 0 ) ? V_25 : V_26 , V_21 , V_2 ) ;
} else {
( * ( V_3 . V_23 ) ) ( V_3 . V_5 , V_21 , V_2 ) ;
}
}
va_end ( V_2 ) ;
}
