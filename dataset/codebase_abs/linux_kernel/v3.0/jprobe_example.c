static long F_1 ( unsigned long V_1 , unsigned long V_2 ,
struct V_3 * V_4 , unsigned long V_5 ,
int T_1 * V_6 , int T_1 * V_7 )
{
F_2 ( V_8 L_1
L_2 ,
V_1 , V_5 , V_4 ) ;
F_3 () ;
return 0 ;
}
static int T_2 F_4 ( void )
{
int V_9 ;
V_9 = F_5 ( & V_10 ) ;
if ( V_9 < 0 ) {
F_2 ( V_8 L_3 , V_9 ) ;
return - 1 ;
}
F_2 ( V_8 L_4 ,
V_10 . V_11 . V_12 , V_10 . V_13 ) ;
return 0 ;
}
static void T_3 F_6 ( void )
{
F_7 ( & V_10 ) ;
F_2 ( V_8 L_5 , V_10 . V_11 . V_12 ) ;
}
