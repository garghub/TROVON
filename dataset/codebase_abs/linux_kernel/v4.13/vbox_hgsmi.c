static T_1 F_1 ( T_1 V_1 , const T_2 * V_2 , int V_3 )
{
while ( V_3 -- ) {
V_1 += * V_2 ++ ;
V_1 += ( V_1 << 10 ) ;
V_1 ^= ( V_1 >> 6 ) ;
}
return V_1 ;
}
static T_1 F_2 ( T_1 V_1 )
{
V_1 += ( V_1 << 3 ) ;
V_1 ^= ( V_1 >> 11 ) ;
V_1 += ( V_1 << 15 ) ;
return V_1 ;
}
static T_1 F_3 ( T_1 V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_1 V_9 ;
V_9 = F_1 ( 0 , ( T_2 * ) & V_4 , sizeof( V_4 ) ) ;
V_9 = F_1 ( V_9 , ( T_2 * ) V_6 , sizeof( * V_6 ) ) ;
V_9 = F_1 ( V_9 , ( T_2 * ) V_8 , 4 ) ;
return F_2 ( V_9 ) ;
}
void * F_4 ( struct V_10 * V_11 , T_3 V_3 ,
T_2 V_12 , T_4 V_13 )
{
struct V_5 * V_14 ;
struct V_7 * V_15 ;
T_3 V_16 ;
T_5 V_4 ;
V_16 = V_3 + sizeof( * V_14 ) + sizeof( * V_15 ) ;
V_14 = F_5 ( V_11 , V_16 , & V_4 ) ;
if ( ! V_14 )
return NULL ;
V_15 = (struct V_7 * ) ( ( T_2 * ) V_14 + sizeof( * V_14 ) + V_3 ) ;
V_14 -> V_17 = V_18 ;
V_14 -> V_19 = V_3 ;
V_14 -> V_12 = V_12 ;
V_14 -> V_13 = V_13 ;
memset ( & V_14 -> V_20 . V_21 , 0 , sizeof( V_14 -> V_20 . V_21 ) ) ;
V_15 -> V_22 = 0 ;
V_15 -> V_9 = F_3 ( V_4 , V_14 , V_15 ) ;
return ( T_2 * ) V_14 + sizeof( * V_14 ) ;
}
void F_6 ( struct V_10 * V_11 , void * V_23 )
{
struct V_5 * V_14 =
(struct V_5 * ) ( ( T_2 * ) V_23 - sizeof( * V_14 ) ) ;
T_3 V_16 = V_14 -> V_19 + sizeof( * V_14 ) +
sizeof( struct V_7 ) ;
F_7 ( V_11 , ( unsigned long ) V_14 , V_16 ) ;
}
int F_8 ( struct V_10 * V_11 , void * V_23 )
{
T_6 V_4 ;
V_4 = F_9 ( V_11 , ( unsigned long ) V_23 -
sizeof( struct V_5 ) ) ;
F_10 ( V_4 , V_24 ) ;
F_11 () ;
return 0 ;
}
