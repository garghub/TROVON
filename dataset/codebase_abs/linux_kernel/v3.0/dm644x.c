void F_1 ( struct V_1 * V_2 )
{
V_3 . V_4 . V_5 = V_2 ;
}
void T_1 F_2 ( struct V_6 * V_7 )
{
F_3 ( V_8 ) ;
V_9 . V_4 . V_5 = V_7 ;
F_4 ( & V_9 ) ;
}
void T_1 F_5 ( void )
{
F_6 ( & V_10 ) ;
}
static int T_1 F_7 ( void )
{
if ( ! F_8 () )
return 0 ;
F_9 ( L_1 , V_11 . V_12 , L_2 , NULL ) ;
F_9 ( L_3 , V_11 . V_12 , L_4 , NULL ) ;
F_4 ( & V_13 ) ;
F_4 ( & V_14 ) ;
F_4 ( & V_15 ) ;
F_9 ( NULL , F_10 ( & V_14 . V_4 ) ,
NULL , & V_15 . V_4 ) ;
F_4 ( & V_16 ) ;
F_4 ( & V_11 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
