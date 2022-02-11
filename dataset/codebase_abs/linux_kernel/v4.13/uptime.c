static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 V_5 ;
struct V_4 V_6 ;
T_1 V_7 ;
T_2 V_8 ;
int V_9 ;
V_7 = 0 ;
F_2 (i)
V_7 += ( V_10 T_1 ) F_3 ( V_9 ) . V_11 [ V_12 ] ;
F_4 ( & V_5 ) ;
V_6 . V_13 = F_5 ( V_7 , V_14 , & V_8 ) ;
V_6 . V_15 = V_8 ;
F_6 ( V_2 , L_1 ,
( unsigned long ) V_5 . V_13 ,
( V_5 . V_15 / ( V_14 / 100 ) ) ,
( unsigned long ) V_6 . V_13 ,
( V_6 . V_15 / ( V_14 / 100 ) ) ) ;
return 0 ;
}
static int F_7 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
return F_8 ( V_17 , F_1 , NULL ) ;
}
static int T_3 F_9 ( void )
{
F_10 ( L_2 , 0 , NULL , & V_18 ) ;
return 0 ;
}
