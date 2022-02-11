static void * F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 ,
T_3 V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 = & V_12 ;
unsigned long V_13 ;
unsigned long V_14 = V_15 ;
unsigned long V_16 ;
if ( ! V_15 ) {
F_2 ( L_1 , V_17 ) ;
return NULL ;
}
V_9 = F_3 ( sizeof ( * V_9 ) , V_18 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_19 = ( V_3 + 31 ) & ~ 31 ;
F_4 ( & V_20 , V_13 ) ;
F_5 (this, &dma_alloc_list) {
struct V_8 * V_21 = F_6 ( V_11 , struct V_8 , V_22 ) ;
V_16 = V_21 -> V_23 ;
if ( V_16 - V_14 >= V_3 )
goto V_24;
V_14 = V_21 -> V_23 + V_21 -> V_19 ;
}
V_16 = V_25 ;
V_11 = & V_12 ;
if ( V_16 - V_14 >= V_3 ) {
V_24:
V_9 -> V_23 = V_14 ;
F_7 ( & V_9 -> V_22 , V_11 ) ;
F_8 ( & V_20 , V_13 ) ;
* V_4 = V_14 ;
return ( void * ) V_14 ;
}
F_9 ( V_9 ) ;
F_8 ( & V_20 , V_13 ) ;
return NULL ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_3 , void * V_26 ,
T_2 V_4 , struct V_6 * V_7 )
{
struct V_8 * V_27 ;
unsigned long V_13 ;
F_4 ( & V_20 , V_13 ) ;
F_11 (rec, &dma_alloc_list, list) {
if ( V_27 -> V_23 == V_4 ) {
F_12 ( & V_27 -> V_22 ) ;
F_9 ( V_27 ) ;
F_8 ( & V_20 , V_13 ) ;
return;
}
}
F_8 ( & V_20 , V_13 ) ;
F_13 () ;
}
static int F_14 ( struct V_1 * V_28 , struct V_29 * V_30 ,
int V_31 , enum V_32 V_33 ,
struct V_6 * V_7 )
{
int V_34 ;
struct V_29 * V_35 ;
F_15 (sglist, sg, nents, i) {
F_16 ( F_17 ( V_35 ) ,
F_17 ( V_35 ) + F_18 ( V_35 ) ) ;
}
F_19 ( V_33 == V_36 ) ;
return V_31 ;
}
static T_2 F_20 ( struct V_1 * V_28 , struct V_37 * V_37 ,
unsigned long V_38 , T_1 V_3 ,
enum V_32 V_33 , struct V_6 * V_7 )
{
F_19 ( V_33 == V_36 ) ;
F_21 ( V_37 ) ;
return ( T_2 ) F_22 ( V_37 ) + V_38 ;
}
static void F_23 ( struct V_1 * V_28 ,
T_2 V_4 , T_1 V_3 ,
enum V_32 V_33 )
{
F_24 () ;
}
static void F_25 ( struct V_1 * V_28 ,
struct V_29 * V_35 , int V_39 ,
enum V_32 V_33 )
{
F_24 () ;
}
static int F_26 ( struct V_1 * V_28 , T_4 V_40 )
{
if ( V_40 < 0x00ffffff )
return 0 ;
return 1 ;
}
