static long F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 , int T_1 * V_4 ,
int T_1 * V_5 , unsigned long V_6 )
{
F_2 ( L_1
L_2 , V_1 , V_2 , V_3 ) ;
F_3 () ;
return 0 ;
}
static int T_2 F_4 ( void )
{
int V_7 ;
V_7 = F_5 ( & V_8 ) ;
if ( V_7 < 0 ) {
F_6 ( L_3 , V_7 ) ;
return - 1 ;
}
F_2 ( L_4 ,
V_8 . V_9 . V_10 , V_8 . V_11 ) ;
return 0 ;
}
static void T_3 F_7 ( void )
{
F_8 ( & V_8 ) ;
F_2 ( L_5 , V_8 . V_9 . V_10 ) ;
}
