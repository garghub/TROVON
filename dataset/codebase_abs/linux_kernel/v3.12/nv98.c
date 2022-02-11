static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
int V_5 ;
V_5 = F_2 ( & V_4 -> V_6 ) ;
if ( V_5 )
return V_5 ;
F_3 ( V_4 , 0x086010 , 0x0000ffd2 ) ;
F_3 ( V_4 , 0x08601c , 0x0000fff2 ) ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_7 , struct V_1 * V_8 ,
struct V_9 * V_10 , void * V_11 , T_1 V_12 ,
struct V_1 * * V_13 )
{
struct V_3 * V_4 ;
int V_5 ;
V_5 = F_5 ( V_7 , V_8 , V_10 , 0x086000 , true ,
L_1 , L_2 , & V_4 ) ;
* V_13 = F_6 ( V_4 ) ;
if ( V_5 )
return V_5 ;
F_7 ( V_4 ) -> V_14 = 0x00400002 ;
F_8 ( V_4 ) -> V_15 = & V_16 ;
F_8 ( V_4 ) -> V_17 = V_18 ;
return 0 ;
}
