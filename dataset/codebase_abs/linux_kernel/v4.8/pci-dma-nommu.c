static void * F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 ,
T_3 V_5 , unsigned long V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 = & V_11 ;
unsigned long V_12 ;
unsigned long V_13 = V_14 ;
unsigned long V_15 ;
if ( ! V_14 ) {
F_2 ( L_1 , V_16 ) ;
return NULL ;
}
V_8 = F_3 ( sizeof ( * V_8 ) , V_17 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_18 = ( V_3 + 31 ) & ~ 31 ;
F_4 ( & V_19 , V_12 ) ;
F_5 (this, &dma_alloc_list) {
struct V_7 * V_20 = F_6 ( V_10 , struct V_7 , V_21 ) ;
V_15 = V_20 -> V_22 ;
if ( V_15 - V_13 >= V_3 )
goto V_23;
V_13 = V_20 -> V_22 + V_20 -> V_18 ;
}
V_15 = V_24 ;
V_10 = & V_11 ;
if ( V_15 - V_13 >= V_3 ) {
V_23:
V_8 -> V_22 = V_13 ;
F_7 ( & V_8 -> V_21 , V_10 ) ;
F_8 ( & V_19 , V_12 ) ;
* V_4 = V_13 ;
return ( void * ) V_13 ;
}
F_9 ( V_8 ) ;
F_8 ( & V_19 , V_12 ) ;
return NULL ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_3 , void * V_25 ,
T_2 V_4 , unsigned long V_6 )
{
struct V_7 * V_26 ;
unsigned long V_12 ;
F_4 ( & V_19 , V_12 ) ;
F_11 (rec, &dma_alloc_list, list) {
if ( V_26 -> V_22 == V_4 ) {
F_12 ( & V_26 -> V_21 ) ;
F_9 ( V_26 ) ;
F_8 ( & V_19 , V_12 ) ;
return;
}
}
F_8 ( & V_19 , V_12 ) ;
F_13 () ;
}
static int F_14 ( struct V_1 * V_27 , struct V_28 * V_29 ,
int V_30 , enum V_31 V_32 ,
unsigned long V_6 )
{
int V_33 ;
struct V_28 * V_34 ;
F_15 (sglist, sg, nents, i) {
F_16 ( F_17 ( V_34 ) ,
F_17 ( V_34 ) + F_18 ( V_34 ) ) ;
}
F_19 ( V_32 == V_35 ) ;
return V_30 ;
}
static T_2 F_20 ( struct V_1 * V_27 , struct V_36 * V_36 ,
unsigned long V_37 , T_1 V_3 ,
enum V_31 V_32 , unsigned long V_6 )
{
F_19 ( V_32 == V_35 ) ;
F_21 ( V_36 ) ;
return ( T_2 ) F_22 ( V_36 ) + V_37 ;
}
static void F_23 ( struct V_1 * V_27 ,
T_2 V_4 , T_1 V_3 ,
enum V_31 V_32 )
{
F_24 () ;
}
static void F_25 ( struct V_1 * V_27 ,
struct V_28 * V_34 , int V_38 ,
enum V_31 V_32 )
{
F_24 () ;
}
static int F_26 ( struct V_1 * V_27 , T_4 V_39 )
{
if ( V_39 < 0x00ffffff )
return 0 ;
return 1 ;
}
