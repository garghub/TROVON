static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_3 ) ;
}
static int T_1 F_5 ( void )
{
int V_4 ;
struct V_5 * V_6 ;
V_6 = F_6 ( NULL , NULL , L_1 ) ;
if ( ! V_6 )
return 0 ;
F_7 ( V_6 ) ;
F_8 ( L_2 ) ;
F_9 ( V_7 , V_8 . V_9 ) ;
F_9 ( V_10 , V_8 . V_11 ) ;
F_9 ( V_12 , V_8 . V_13 ) ;
V_4 = F_10 ( & V_14 ) ;
if ( V_4 )
return V_4 ;
F_11 ( & V_14 . V_2 , 1 ) ;
return 0 ;
}
