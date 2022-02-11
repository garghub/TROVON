static long F_1 ( long V_1 , int type )
{
return ( V_1 ^ V_2 [ type ] [ 0 ] ) * V_2 [ type ] [ 1 ] ;
}
static int F_2 ( void * V_3 , void * V_4 , enum V_5 type )
{
long V_6 , V_7 ;
V_6 = F_1 ( ( long ) V_3 , type ) ;
V_7 = F_1 ( ( long ) V_4 , type ) ;
return ( V_6 < V_7 ) | ( ( V_6 > V_7 ) << 1 ) ;
}
static struct V_8 *
F_3 ( struct V_9 * V_10 , unsigned int V_11 )
{
struct V_8 * V_8 = NULL ;
F_4 ( V_10 ) ;
F_5 () ;
if ( V_10 -> V_12 )
V_8 = F_6 ( V_10 -> V_12 , V_11 ) ;
F_7 () ;
F_8 ( V_10 ) ;
return V_8 ;
}
static void F_9 ( struct V_13 * V_14 , struct V_13 * V_15 )
{
if ( F_10 ( V_15 != V_14 ) )
F_11 ( V_15 ) ;
F_11 ( V_14 ) ;
}
static int F_12 ( struct V_13 * V_14 , struct V_13 * V_15 )
{
int V_16 ;
if ( V_15 > V_14 )
F_13 ( V_14 , V_15 ) ;
V_16 = F_14 ( V_14 ) ;
if ( ! V_16 && F_10 ( V_14 != V_15 ) ) {
V_16 = F_15 ( V_15 , V_17 ) ;
if ( V_16 )
F_11 ( V_14 ) ;
}
return V_16 ;
}
static int F_16 ( struct V_9 * V_18 ,
struct V_9 * V_19 ,
unsigned long V_20 ,
struct V_21 T_1 * V_22 )
{
struct V_8 * V_23 , * V_24 , * V_25 ;
struct V_21 V_26 ;
struct V_27 * V_12 ;
if ( F_17 ( & V_26 , V_22 , sizeof( V_26 ) ) )
return - V_28 ;
V_23 = F_3 ( V_18 , V_20 ) ;
if ( ! V_23 )
return - V_29 ;
V_12 = F_18 ( V_19 ) ;
if ( ! V_12 )
return - V_29 ;
F_19 ( & V_12 -> V_30 ) ;
V_24 = F_6 ( V_12 , V_26 . V_31 ) ;
if ( V_24 )
F_20 ( V_24 ) ;
else
V_25 = F_21 ( - V_29 ) ;
F_22 ( & V_12 -> V_30 ) ;
F_23 ( V_12 ) ;
if ( V_24 ) {
V_25 = F_24 ( V_24 , V_26 . V_32 , V_26 . V_33 ) ;
F_25 ( V_24 ) ;
}
if ( F_26 ( V_25 ) )
return F_27 ( V_25 ) ;
return F_2 ( V_23 , V_25 , V_34 ) ;
}
static int F_16 ( struct V_9 * V_18 ,
struct V_9 * V_19 ,
unsigned long V_20 ,
struct V_21 T_1 * V_22 )
{
return - V_35 ;
}
static T_2 int F_28 ( void )
{
int V_36 ;
F_29 ( V_2 , sizeof( V_2 ) ) ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
V_2 [ V_36 ] [ 1 ] |= ( ~ ( ~ 0UL >> 1 ) | 1 ) ;
return 0 ;
}
