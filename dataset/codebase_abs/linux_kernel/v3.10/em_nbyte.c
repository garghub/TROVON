static int F_1 ( struct V_1 * V_2 , void * V_3 , int V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_3 ;
if ( V_4 < sizeof( * V_8 ) ||
V_4 < ( sizeof( * V_8 ) + V_8 -> V_9 ) )
return - V_10 ;
V_6 -> V_11 = sizeof( * V_8 ) + V_8 -> V_9 ;
V_6 -> V_3 = ( unsigned long ) F_2 ( V_3 , V_6 -> V_11 , V_12 ) ;
if ( V_6 -> V_3 == 0UL )
return - V_13 ;
return 0 ;
}
static int F_3 ( struct V_14 * V_15 , struct V_5 * V_6 ,
struct V_16 * V_17 )
{
struct V_18 * V_8 = (struct V_18 * ) V_6 -> V_3 ;
unsigned char * V_19 = F_4 ( V_15 , V_8 -> V_20 . V_21 ) ;
V_19 += V_8 -> V_20 . V_22 ;
if ( ! F_5 ( V_15 , V_19 , V_8 -> V_20 . V_9 ) )
return 0 ;
return ! memcmp ( V_19 + V_8 -> V_20 . V_22 , V_8 -> V_23 , V_8 -> V_20 . V_9 ) ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_24 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_24 ) ;
}
