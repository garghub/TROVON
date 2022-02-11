static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_2 , L_1 ,
V_4 ,
V_5 ? F_3 ( & V_5 -> V_6 ) : 0 ,
V_5 ? V_5 -> V_7 : 0 ,
V_5 ? V_5 -> V_8 : 0 ) ;
return 0 ;
}
static int F_4 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
return F_5 ( V_10 , F_1 , NULL ) ;
}
static int F_6 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_2 , L_2 ,
V_11 . V_12 ,
V_11 . V_13 ,
V_11 . V_14 ,
V_11 . V_15 ,
V_11 . V_16 ,
V_11 . V_17 ,
V_11 . V_18 ,
V_11 . V_19 ) ;
return 0 ;
}
static int F_7 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
return F_5 ( V_10 , F_6 , NULL ) ;
}
void
F_8 ( void )
{
F_9 ( L_3 , 0 , NULL , & V_20 ) ;
F_9 ( L_4 , 0 , NULL , & V_21 ) ;
}
void
F_10 ( void )
{
F_11 ( L_4 , NULL ) ;
F_11 ( L_3 , NULL ) ;
}
