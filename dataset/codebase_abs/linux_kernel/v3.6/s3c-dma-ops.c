static void F_1 ( struct V_1 * V_2 , void * V_3 ,
int V_4 , enum V_5 V_6 )
{
struct V_7 * V_8 = V_3 ;
V_8 -> V_9 ( V_8 -> V_10 ) ;
}
static unsigned F_2 ( enum V_11 V_11 ,
struct V_12 * V_3 )
{
struct V_7 * V_8 ;
if ( F_3 ( V_11 , V_3 -> V_13 , NULL ) < 0 ) {
F_4 ( V_11 , V_3 -> V_13 ) ;
return 0 ;
}
if ( V_3 -> V_14 == V_15 )
F_5 ( V_11 , V_16 ) ;
V_8 = F_6 ( sizeof( struct V_7 ) , V_17 ) ;
V_8 -> V_18 = V_11 ;
F_7 ( & V_8 -> V_19 , & V_20 ) ;
return ( unsigned ) V_11 ;
}
static int F_8 ( unsigned V_18 , void * V_3 )
{
struct V_7 * V_8 ;
F_9 (data, &dma_list, node)
if ( V_8 -> V_18 == V_18 )
break;
F_10 ( & V_8 -> V_19 ) ;
F_4 ( V_18 , V_3 ) ;
F_11 ( V_8 ) ;
return 0 ;
}
static int F_12 ( unsigned V_18 , struct V_21 * V_3 )
{
F_13 ( V_18 , V_3 -> V_22 , V_3 -> V_23 ) ;
F_14 ( V_18 , V_3 -> V_24 ) ;
return 0 ;
}
static int F_15 ( unsigned V_18 , struct V_25 * V_3 )
{
struct V_7 * V_8 ;
int V_26 = ( V_3 -> V_14 == V_15 ) ? V_3 -> V_27 : V_3 -> V_26 ;
F_9 (data, &dma_list, node)
if ( V_8 -> V_18 == V_18 )
break;
if ( ! V_8 -> V_9 ) {
F_16 ( V_18 , F_1 ) ;
V_8 -> V_9 = V_3 -> V_9 ;
V_8 -> V_10 = V_3 -> V_10 ;
}
F_17 ( V_18 , ( void * ) V_8 , V_3 -> V_28 , V_26 ) ;
return 0 ;
}
static inline int F_18 ( unsigned V_18 )
{
return F_19 ( V_18 , V_29 ) ;
}
static inline int F_20 ( unsigned V_18 )
{
return F_19 ( V_18 , V_30 ) ;
}
static inline int F_21 ( unsigned V_18 )
{
return F_19 ( V_18 , V_31 ) ;
}
static inline int F_22 ( unsigned V_18 )
{
return F_19 ( V_18 , V_32 ) ;
}
void * F_23 ( void )
{
return & V_33 ;
}
