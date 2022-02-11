static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct F_1 * V_8 = V_3 ;
V_5 = F_2 ( V_2 ) ;
V_7 = (struct V_6 * ) V_5 -> V_9 ;
memset ( V_7 -> V_10 , 0 , sizeof( V_7 -> V_10 ) ) ;
V_7 -> V_11 = NULL ;
V_7 -> V_12 = V_8 -> V_12 ;
V_7 -> V_13 = - 1 ;
V_7 -> V_2 = V_2 ;
F_3 ( & V_7 -> V_14 ) ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = NULL ;
V_2 -> V_17 = 0 ;
V_2 -> type = V_18 ;
V_2 -> V_19 = 256 ;
V_2 -> V_20 = V_21 ;
F_4 ( L_1 , V_7 -> V_12 ) ;
}
static unsigned short F_5 ( struct V_22 * V_23 )
{
return F_6 ( V_24 ) ;
}
static int F_7 ( int V_25 , struct V_22 * V_26 , struct V_4 * V_27 )
{
return F_8 ( V_25 , F_9 ( V_26 ) , V_26 -> V_2 -> V_28 ,
(struct V_6 * ) & V_27 -> V_9 ) ;
}
static int F_10 ( int V_25 , struct V_22 * V_26 , struct V_4 * V_27 )
{
return F_11 ( V_25 , V_26 -> V_3 , V_26 -> V_29 ,
(struct V_6 * ) & V_27 -> V_9 ) ;
}
static int F_12 ( char * V_30 , char * * V_31 , void * V_3 )
{
struct F_1 * V_8 = V_3 ;
* V_8 = ( (struct F_1 ) { . V_12 = NULL } ) ;
if ( V_30 [ 0 ] != '\0' )
V_8 -> V_12 = V_30 ;
return 1 ;
}
static int F_13 ( void )
{
F_14 ( & V_32 ) ;
return 0 ;
}
