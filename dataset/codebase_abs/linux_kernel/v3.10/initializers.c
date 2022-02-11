int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( V_2 , L_1 ) ;
V_2 -> V_4 [ 0 ] = 0x1 ;
V_3 = F_3 ( V_2 , V_2 -> V_5 ,
0x0C , V_6 | V_7 ,
0x01 , 0x0 , V_2 -> V_4 , 0x1 , 5000 ) ;
F_2 ( V_2 , L_2 , V_3 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 -> V_4 ;
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_4 ;
int V_12 ;
unsigned int V_13 ;
static char V_14 [] = L_3 ;
F_2 ( V_2 , L_4 ) ;
V_9 -> V_15 = F_5 ( V_16 ) ;
V_9 -> V_17 = 0 ;
V_9 -> V_18 = F_5 ( 0 ) ;
V_9 -> V_19 = V_9 -> V_20 = 0 ;
V_9 -> V_21 = sizeof( V_14 ) - 1 ;
memset ( V_9 -> V_22 , 0 , sizeof( V_9 -> V_22 ) ) ;
memcpy ( V_9 -> V_22 , V_14 , sizeof( V_14 ) - 1 ) ;
V_12 = F_6 ( V_2 , V_2 -> V_23 , V_9 ,
V_24 , & V_13 ) ;
if ( V_12 )
return - V_25 ;
F_2 ( V_2 , L_5 ) ;
V_12 = F_6 ( V_2 , V_2 -> V_26 , V_11 ,
V_27 , & V_13 ) ;
if ( V_12 )
return - V_25 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_3 ( V_2 , V_2 -> V_5 ,
V_28 ,
V_29 | V_30 ,
0x01 , 0x0 , NULL , 0x0 , 1000 ) ;
F_2 ( V_2 , L_6 , V_3 ) ;
return 0 ;
}
