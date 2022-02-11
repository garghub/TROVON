static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char V_5 [ 8 ] ;
if ( ! ( F_2 ( V_2 ) >= V_2 -> V_6 &&
F_2 ( V_2 ) + V_7 <= V_2 -> V_8 ) &&
V_4 -> V_9 != 0 ) {
V_4 -> V_10 = true ;
return false ;
}
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
if ( F_3 ( V_2 ) -> V_11 == F_4 ( V_12 ) ) {
if ( F_5 ( V_2 ) -> V_13 == 0x6 ) {
memcpy ( V_5 , F_3 ( V_2 ) -> V_14 , 3 ) ;
memcpy ( V_5 + 5 , F_3 ( V_2 ) -> V_14 + 3 , 3 ) ;
V_5 [ 3 ] = 0xff ;
V_5 [ 4 ] = 0xfe ;
V_5 [ 0 ] ^= 0x02 ;
if ( ! memcmp ( F_5 ( V_2 ) -> V_15 . V_16 + 8 , V_5 ,
sizeof( V_5 ) ) )
return true ;
}
}
return false ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_17 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_17 ) ;
}
