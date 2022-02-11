static void * F_1 ( struct V_1 * V_2 , int V_3 )
{
char * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
V_7 = V_8 -> V_9 -> V_7 ;
V_4 = ( V_4 - ( char * ) & V_10 ) + ( char * ) V_7 ;
if ( ! V_3 )
F_2 ( & V_11 ) ;
else
F_3 ( & V_11 ) ;
return V_4 ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 , void * V_4 )
{
if ( ! V_3 )
F_5 ( & V_11 ) ;
else
F_6 ( & V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_12 , T_2 * V_13 , T_3 * V_14 )
{
struct V_1 V_15 ;
int V_16 ;
memcpy ( & V_15 , V_2 , sizeof( V_15 ) ) ;
V_15 . V_5 = F_1 ( V_2 , V_3 ) ;
V_16 = F_8 ( & V_15 , V_3 , V_12 , V_13 , V_14 ) ;
F_4 ( V_2 , V_3 , V_15 . V_5 ) ;
if ( V_3 )
F_9 ( V_2 -> V_17 ) ;
return V_16 ;
}
void F_10 ( enum V_18 V_19 )
{
struct V_1 * V_2 = & V_20 [ V_19 ] ;
F_9 ( V_2 -> V_17 ) ;
}
static int T_4 F_11 ( void )
{
F_12 ( V_21 ) ;
return 0 ;
}
