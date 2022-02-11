static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 == NULL ) {
F_2 (KERN_ERR MODULE_NAME L_1 ) ;
F_3 () ;
return ( 0 ) ;
}
return ( ( int ) ( V_3 >= 0xffffffffUL ) ) ;
}
static void * F_4 ( struct V_1 * V_2 , T_2 V_4 ,
T_3 * V_5 )
{
void * V_6 ;
V_6 = ( void * ) F_5 ( V_7 , F_6 ( V_4 ) ) ;
if ( V_6 != NULL ) {
memset ( V_6 , 0 , V_4 ) ;
* V_5 = F_7 ( V_6 ) ;
}
return V_6 ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_4 ,
void * V_8 , T_3 V_5 )
{
F_9 ( ( unsigned long ) V_8 , F_6 ( V_4 ) ) ;
}
static T_3 F_10 ( struct V_1 * V_2 , void * V_9 , T_2 V_4 ,
int V_10 )
{
return F_7 ( V_9 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_3 V_11 ,
T_2 V_4 , int V_10 )
{
}
static int F_12 ( struct V_1 * V_2 , struct V_12 * V_13 , int V_14 , int V_10 )
{
int V_15 = V_14 ;
while ( V_14 ) {
F_13 ( V_13 ) = F_10 ( V_2 , V_13 -> V_16 , V_13 -> V_17 , V_10 ) ;
F_14 ( V_13 ) = V_13 -> V_17 ;
V_14 -- ;
V_13 ++ ;
}
return V_15 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_12 * V_13 , int V_14 , int V_10 )
{
#if 0
while (nents) {
ccio_unmap_single(dev, sg_dma_address(sglist), sg_dma_len(sglist), direction);
nents--;
sglist++;
}
return;
#else
#endif
}
static int T_4
F_16 ( struct V_18 * V_2 )
{
F_2 ( V_19 L_2 , V_20 ,
V_2 -> V_21 . V_22 == V_23 ? L_3 : L_4 ,
V_2 -> V_24 . V_25 ) ;
#if 0
ccio_hw_init(ccio_dev);
ccio_common_init(ccio_dev);
#endif
V_26 = & V_27 ;
return 0 ;
}
void T_4 F_17 ( void )
{
F_18 ( & V_28 ) ;
}
