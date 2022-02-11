static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 == 1 && ( F_2 ( V_2 -> V_5 ) ) == 0 )
V_2 -> V_2 . V_6 = & V_7 ;
return 0 ;
}
static void T_1 F_3 ( T_2 * V_8 )
{
memcpy ( V_7 . V_9 , V_8 ,
sizeof( V_7 . V_9 ) ) ;
F_4 ( F_1 ) ;
F_5 () ;
}
static inline void F_3 ( void ) {}
static void T_1 F_6 ( void )
{
T_2 * V_10 = ( T_2 * ) F_7 ( 0x1fff0000 ) ;
F_8 ( - 1 , F_9 ( V_11 ) ,
V_11 ) ;
F_10 ( - 1 , V_12 ,
F_9 ( V_13 ) ,
V_13 ) ;
F_11 ( & V_14 , V_15 ,
F_9 ( V_15 ) ) ;
F_12 () ;
F_13 ( V_10 + V_16 ) ;
F_3 ( V_10 + V_17 ) ;
}
