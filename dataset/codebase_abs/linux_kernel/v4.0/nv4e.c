static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = ( void * ) F_2 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 ;
F_3 ( V_5 , V_7 -> V_8 , 0x2f , V_3 ? 0x21 : 0x01 ) ;
}
static void
F_4 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = ( void * ) F_2 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 ;
F_3 ( V_5 , V_7 -> V_8 , 0x1f , V_3 ? 0x11 : 0x01 ) ;
}
static int
F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = ( void * ) F_2 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 ;
return ! ! ( F_6 ( V_5 , V_7 -> V_8 ) & 0x00040000 ) ;
}
static int
F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = ( void * ) F_2 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 ;
return ! ! ( F_6 ( V_5 , V_7 -> V_8 ) & 0x00080000 ) ;
}
static int
F_8 ( struct V_9 * V_10 , struct V_9 * V_11 ,
struct V_12 * V_13 , void * V_14 , T_1 V_15 ,
struct V_9 * * V_16 )
{
struct V_17 * V_18 = V_14 ;
struct V_6 * V_7 ;
int V_19 ;
V_19 = F_9 ( V_10 , V_11 , V_13 , V_15 ,
& V_20 , & V_21 , & V_7 ) ;
* V_16 = F_10 ( V_7 ) ;
if ( V_19 )
return V_19 ;
V_7 -> V_8 = 0x600800 + V_18 -> V_22 ;
return 0 ;
}
