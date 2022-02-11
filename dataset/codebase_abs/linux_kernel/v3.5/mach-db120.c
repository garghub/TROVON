static int F_1 ( struct V_1 * V_2 )
{
switch ( F_2 ( V_2 -> V_3 ) ) {
case 0 :
V_2 -> V_2 . V_4 = & V_5 ;
break;
}
return 0 ;
}
static void T_1 F_3 ( T_2 * V_6 )
{
memcpy ( V_5 . V_7 , V_6 ,
sizeof( V_5 . V_7 ) ) ;
F_4 ( F_1 ) ;
F_5 () ;
}
static inline void F_3 ( void ) {}
static void T_1 F_6 ( void )
{
T_2 * V_8 = ( T_2 * ) F_7 ( 0x1fff0000 ) ;
F_8 ( - 1 , F_9 ( V_9 ) ,
V_9 ) ;
F_10 ( - 1 , V_10 ,
F_9 ( V_11 ) ,
V_11 ) ;
F_11 ( & V_12 , V_13 ,
F_9 ( V_13 ) ) ;
F_12 ( V_8 + V_14 ) ;
F_3 ( V_8 + V_15 ) ;
}
