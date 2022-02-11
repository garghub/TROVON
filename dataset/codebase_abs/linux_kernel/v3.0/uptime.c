static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 V_5 ;
struct V_4 V_6 ;
int V_7 ;
T_1 V_8 = V_9 ;
F_2 (i)
V_8 = F_3 ( V_8 , F_4 ( V_7 ) . V_10 . V_6 ) ;
F_5 ( & V_5 ) ;
F_6 ( & V_5 ) ;
F_7 ( V_8 , & V_6 ) ;
F_8 ( V_2 , L_1 ,
( unsigned long ) V_5 . V_11 ,
( V_5 . V_12 / ( V_13 / 100 ) ) ,
( unsigned long ) V_6 . V_11 ,
( V_6 . V_12 / ( V_13 / 100 ) ) ) ;
return 0 ;
}
static int F_9 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
return F_10 ( V_15 , F_1 , NULL ) ;
}
static int T_2 F_11 ( void )
{
F_12 ( L_2 , 0 , NULL , & V_16 ) ;
return 0 ;
}
