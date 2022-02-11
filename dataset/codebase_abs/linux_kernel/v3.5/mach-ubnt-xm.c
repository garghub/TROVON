static int F_1 ( struct V_1 * V_2 )
{
switch ( F_2 ( V_2 -> V_3 ) ) {
case 0 :
V_2 -> V_2 . V_4 = & V_5 ;
break;
}
return 0 ;
}
static void T_1 F_3 ( void )
{
memcpy ( V_5 . V_6 , V_7 ,
sizeof( V_5 . V_6 ) ) ;
F_4 ( F_1 ) ;
F_5 () ;
}
static inline void F_3 ( void ) {}
static void T_1 F_6 ( void )
{
F_7 ( - 1 , F_8 ( V_8 ) ,
V_8 ) ;
F_9 ( - 1 , V_9 ,
F_8 ( V_10 ) ,
V_10 ) ;
F_10 ( & V_11 , V_12 ,
F_8 ( V_12 ) ) ;
F_3 () ;
}
