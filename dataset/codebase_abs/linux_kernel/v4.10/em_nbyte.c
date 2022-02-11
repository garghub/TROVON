static int F_1 ( struct V_1 * V_1 , void * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 ;
if ( V_3 < sizeof( * V_7 ) ||
V_3 < ( sizeof( * V_7 ) + V_7 -> V_8 ) )
return - V_9 ;
V_5 -> V_10 = sizeof( * V_7 ) + V_7 -> V_8 ;
V_5 -> V_2 = ( unsigned long ) F_2 ( V_2 , V_5 -> V_10 , V_11 ) ;
if ( V_5 -> V_2 == 0UL )
return - V_12 ;
return 0 ;
}
static int F_3 ( struct V_13 * V_14 , struct V_4 * V_5 ,
struct V_15 * V_16 )
{
struct V_17 * V_7 = (struct V_17 * ) V_5 -> V_2 ;
unsigned char * V_18 = F_4 ( V_14 , V_7 -> V_19 . V_20 ) ;
V_18 += V_7 -> V_19 . V_21 ;
if ( ! F_5 ( V_14 , V_18 , V_7 -> V_19 . V_8 ) )
return 0 ;
return ! memcmp ( V_18 + V_7 -> V_19 . V_21 , V_7 -> V_22 , V_7 -> V_19 . V_8 ) ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_23 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_23 ) ;
}
