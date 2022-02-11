static int F_1 ( struct V_1 * V_2 , void T_1 * V_3 )
{
F_2 ( V_4 , V_5 ) ;
F_2 ( V_6 ,
V_7 ) ;
F_2 ( ( F_3 ( V_8 ) | ( 0x800 ) ) , V_8 ) ;
F_4 ( 20 ) ;
F_2 ( ( F_3 ( V_9 ) & ( ~ 0x1000 ) ) ,
V_9 ) ;
F_4 ( 20 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_5 ) ;
F_2 ( 0 , V_7 ) ;
F_2 ( ( F_3 ( V_9 ) | ( 0x1000 ) ) ,
V_9 ) ;
F_4 ( 20 ) ;
F_2 ( ( F_3 ( V_8 ) & ( ~ 0x800 ) ) , V_8 ) ;
F_4 ( 20 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 . V_11 . V_12 == V_13 )
return 0 ;
F_5 ( V_2 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 . V_11 . V_12 == V_14 )
return 0 ;
return F_1 ( V_2 , NULL ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( NULL , V_15 ,
V_16 , NULL ) ;
}
