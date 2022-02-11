static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 V_5 ;
struct V_4 V_6 ;
T_1 V_7 ;
T_1 V_8 ;
T_2 V_9 ;
int V_10 ;
V_7 = 0 ;
F_2 (i)
V_7 += ( V_11 T_1 ) F_3 ( V_10 ) . V_12 [ V_13 ] ;
F_4 ( & V_5 ) ;
F_5 ( & V_5 ) ;
V_8 = F_6 ( V_7 ) * V_14 ;
V_6 . V_15 = F_7 ( V_8 , V_16 , & V_9 ) ;
V_6 . V_17 = V_9 ;
F_8 ( V_2 , L_1 ,
( unsigned long ) V_5 . V_15 ,
( V_5 . V_17 / ( V_16 / 100 ) ) ,
( unsigned long ) V_6 . V_15 ,
( V_6 . V_17 / ( V_16 / 100 ) ) ) ;
return 0 ;
}
static int F_9 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
return F_10 ( V_19 , F_1 , NULL ) ;
}
static int T_3 F_11 ( void )
{
F_12 ( L_2 , 0 , NULL , & V_20 ) ;
return 0 ;
}
