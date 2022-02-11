static int
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
V_11 = F_2 ( V_2 , V_3 , V_5 , & V_10 ) ;
* V_8 = F_3 ( V_10 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_10 ) -> V_12 = V_13 ;
V_10 -> V_14 . V_15 = V_16 ;
return 0 ;
}
static int
F_5 ( struct V_1 * V_17 )
{
struct V_9 * V_10 = ( void * ) V_17 ;
T_1 V_18 = F_6 ( V_10 , 0x10020c ) ;
F_7 ( V_10 , 0x000200 , 0xffffffff ) ;
F_7 ( V_10 , 0x001700 , V_18 ) ;
F_7 ( V_10 , 0x001704 , 0 ) ;
F_7 ( V_10 , 0x001708 , 0 ) ;
F_7 ( V_10 , 0x00170c , V_18 ) ;
return F_8 ( & V_10 -> V_14 ) ;
}
