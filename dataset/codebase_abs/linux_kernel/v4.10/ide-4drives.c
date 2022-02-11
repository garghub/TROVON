static void F_1 ( T_1 * V_1 )
{
if ( V_1 -> V_2 -> V_3 )
V_1 -> V_4 ^= 0x20 ;
}
static int T_2 F_2 ( void )
{
unsigned long V_5 = 0x1f0 , V_6 = 0x3f6 ;
struct V_7 V_8 , * V_9 [] = { & V_8 , & V_8 } ;
if ( V_10 == 0 )
return - V_11 ;
if ( ! F_3 ( V_5 , 8 , V_12 ) ) {
F_4 ( V_13 L_1 ,
V_12 , V_5 , V_5 + 7 ) ;
return - V_14 ;
}
if ( ! F_3 ( V_6 , 1 , V_12 ) ) {
F_4 ( V_13 L_2 ,
V_12 , V_6 ) ;
F_5 ( V_5 , 8 ) ;
return - V_14 ;
}
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
F_6 ( & V_8 , V_5 , V_6 ) ;
V_8 . V_15 = 14 ;
return F_7 ( & V_16 , V_9 , 2 , NULL ) ;
}
