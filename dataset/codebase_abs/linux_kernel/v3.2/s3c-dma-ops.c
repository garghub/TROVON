static void F_1 ( struct V_1 * V_2 , void * V_3 ,
int V_4 , enum V_5 V_6 )
{
struct V_7 * V_8 = V_3 ;
V_8 -> V_9 ( V_8 -> V_10 ) ;
}
static unsigned F_2 ( enum V_11 V_11 ,
struct V_12 * V_13 )
{
struct V_7 * V_8 ;
if ( F_3 ( V_11 , V_13 -> V_14 , NULL ) < 0 ) {
F_4 ( V_11 , V_13 -> V_14 ) ;
return 0 ;
}
V_8 = F_5 ( sizeof( struct V_7 ) , V_15 ) ;
V_8 -> V_16 = V_11 ;
F_6 ( & V_8 -> V_17 , & V_18 ) ;
F_7 ( V_11 , V_13 -> V_19 , V_13 -> V_20 ) ;
if ( V_13 -> V_21 == V_22 )
F_8 ( V_11 , V_23 ) ;
F_9 ( V_11 , V_13 -> V_24 ) ;
return ( unsigned ) V_11 ;
}
static int F_10 ( unsigned V_16 , struct V_25 * V_14 )
{
struct V_7 * V_8 ;
F_11 (data, &dma_list, node)
if ( V_8 -> V_16 == V_16 )
break;
F_12 ( & V_8 -> V_17 ) ;
F_4 ( V_16 , V_14 ) ;
F_13 ( V_8 ) ;
return 0 ;
}
static int F_14 ( unsigned V_16 , struct V_26 * V_13 )
{
struct V_7 * V_8 ;
int V_27 = ( V_13 -> V_21 == V_22 ) ? V_13 -> V_28 : V_13 -> V_27 ;
F_11 (data, &dma_list, node)
if ( V_8 -> V_16 == V_16 )
break;
if ( ! V_8 -> V_9 ) {
F_15 ( V_16 , F_1 ) ;
V_8 -> V_9 = V_13 -> V_9 ;
V_8 -> V_10 = V_13 -> V_10 ;
}
F_16 ( V_16 , ( void * ) V_8 , V_13 -> V_29 , V_27 ) ;
return 0 ;
}
static inline int F_17 ( unsigned V_16 )
{
return F_18 ( V_16 , V_30 ) ;
}
static inline int F_19 ( unsigned V_16 )
{
return F_18 ( V_16 , V_31 ) ;
}
static inline int F_20 ( unsigned V_16 )
{
return F_18 ( V_16 , V_32 ) ;
}
static inline int F_21 ( unsigned V_16 )
{
return F_18 ( V_16 , V_33 ) ;
}
void * F_22 ( void )
{
return & V_34 ;
}
