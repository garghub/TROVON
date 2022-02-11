static long F_1 ( long V_1 , int type )
{
return ( V_1 ^ V_2 [ type ] [ 0 ] ) * V_2 [ type ] [ 1 ] ;
}
static int F_2 ( void * V_3 , void * V_4 , enum V_5 type )
{
long V_6 ;
V_6 = F_1 ( ( long ) V_3 , type ) - F_1 ( ( long ) V_4 , type ) ;
return ( V_6 < 0 ) | ( ( V_6 > 0 ) << 1 ) ;
}
static struct V_7 *
F_3 ( struct V_8 * V_9 , unsigned int V_10 )
{
struct V_7 * V_7 = NULL ;
F_4 ( V_9 ) ;
F_5 () ;
if ( V_9 -> V_11 )
V_7 = F_6 ( V_9 -> V_11 , V_10 ) ;
F_7 () ;
F_8 ( V_9 ) ;
return V_7 ;
}
static void F_9 ( struct V_12 * V_13 , struct V_12 * V_14 )
{
if ( F_10 ( V_14 != V_13 ) )
F_11 ( V_14 ) ;
F_11 ( V_13 ) ;
}
static int F_12 ( struct V_12 * V_13 , struct V_12 * V_14 )
{
int V_15 ;
if ( V_14 > V_13 )
F_13 ( V_13 , V_14 ) ;
V_15 = F_14 ( V_13 ) ;
if ( ! V_15 && F_10 ( V_13 != V_14 ) ) {
V_15 = F_15 ( V_14 , V_16 ) ;
if ( V_15 )
F_11 ( V_13 ) ;
}
return V_15 ;
}
static T_1 int F_16 ( void )
{
int V_17 ;
F_17 ( V_2 , sizeof( V_2 ) ) ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
V_2 [ V_17 ] [ 1 ] |= ( ~ ( ~ 0UL >> 1 ) | 1 ) ;
return 0 ;
}
