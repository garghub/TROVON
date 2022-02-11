static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_5 , const void * V_6 , unsigned int V_7 )
{
struct V_8 * V_9 ;
int V_10 ;
if ( type == V_11 || type == V_12 )
{
struct V_13 * V_13 ;
V_10 = sizeof( struct V_8 ) + sizeof( struct V_13 ) ;
V_9 = (struct V_8 * ) F_2 ( V_2 , V_10 ) ;
V_13 = (struct V_13 * ) ( V_9 + 1 ) ;
V_13 -> V_14 = V_13 -> V_15 = V_16 ;
V_13 -> V_17 = V_18 ;
V_13 -> V_19 [ 0 ] = V_13 -> V_19 [ 1 ] = V_13 -> V_19 [ 2 ] = 0x00 ;
V_13 -> V_20 = F_3 ( type ) ;
}
else
{
V_10 = sizeof( struct V_8 ) ;
V_9 = (struct V_8 * ) F_2 ( V_2 , V_10 ) ;
}
if( V_6 )
memcpy ( V_9 -> V_6 , V_6 , V_4 -> V_21 ) ;
else
memcpy ( V_9 -> V_6 , V_4 -> V_22 , V_4 -> V_21 ) ;
if( V_5 )
{
memcpy ( V_9 -> V_5 , V_5 , V_4 -> V_21 ) ;
return V_10 ;
}
return - V_10 ;
}
static void F_4 ( struct V_3 * V_4 )
{
V_4 -> V_23 = & V_24 ;
V_4 -> type = V_25 ;
V_4 -> V_26 = V_27 ;
V_4 -> V_28 = 2024 ;
V_4 -> V_21 = V_29 ;
V_4 -> V_30 = 100 ;
V_4 -> V_31 = V_32 ;
memset ( V_4 -> V_33 , 0xFF , V_29 ) ;
}
struct V_3 * F_5 ( int V_34 )
{
return F_6 ( V_34 , L_1 , V_35 , F_4 ) ;
}
