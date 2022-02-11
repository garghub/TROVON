void * F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 , T_3 V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 = & V_10 ;
unsigned long V_11 ;
unsigned long V_12 = V_13 ;
unsigned long V_14 ;
if ( ! V_13 ) {
F_2 ( L_1 , V_15 ) ;
return NULL ;
}
V_7 = F_3 ( sizeof ( * V_7 ) , V_16 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_17 = ( V_3 + 31 ) & ~ 31 ;
F_4 ( & V_18 , V_11 ) ;
F_5 (this, &dma_alloc_list) {
struct V_6 * V_19 = F_6 ( V_9 , struct V_6 , V_20 ) ;
V_14 = V_19 -> V_21 ;
if ( V_14 - V_12 >= V_3 )
goto V_22;
V_12 = V_19 -> V_21 + V_19 -> V_17 ;
}
V_14 = V_23 ;
V_9 = & V_10 ;
if ( V_14 - V_12 >= V_3 ) {
V_22:
V_7 -> V_21 = V_12 ;
F_7 ( & V_7 -> V_20 , V_9 ) ;
F_8 ( & V_18 , V_11 ) ;
* V_4 = V_12 ;
return ( void * ) V_12 ;
}
F_9 ( V_7 ) ;
F_8 ( & V_18 , V_11 ) ;
return NULL ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_3 , void * V_24 , T_2 V_4 )
{
struct V_6 * V_25 ;
unsigned long V_11 ;
F_4 ( & V_18 , V_11 ) ;
F_11 (rec, &dma_alloc_list, list) {
if ( V_25 -> V_21 == V_4 ) {
F_12 ( & V_25 -> V_20 ) ;
F_9 ( V_25 ) ;
F_8 ( & V_18 , V_11 ) ;
return;
}
}
F_8 ( & V_18 , V_11 ) ;
F_13 () ;
}
T_2 F_14 ( struct V_1 * V_26 , void * V_27 , T_1 V_3 ,
enum V_28 V_29 )
{
F_15 ( V_29 == V_30 ) ;
F_16 ( ( unsigned long ) V_27 , ( unsigned long ) V_27 + V_3 ) ;
return F_17 ( V_27 ) ;
}
int F_18 ( struct V_1 * V_26 , struct V_31 * V_32 , int V_33 ,
enum V_28 V_29 )
{
int V_34 ;
struct V_31 * V_35 ;
F_19 (sglist, sg, nents, i) {
F_16 ( F_20 ( V_35 ) ,
F_20 ( V_35 ) + F_21 ( V_35 ) ) ;
}
F_15 ( V_29 == V_30 ) ;
return V_33 ;
}
T_2 F_22 ( struct V_1 * V_26 , struct V_36 * V_36 , unsigned long V_37 ,
T_1 V_3 , enum V_28 V_29 )
{
F_15 ( V_29 == V_30 ) ;
F_23 ( V_36 ) ;
return ( T_2 ) F_24 ( V_36 ) + V_37 ;
}
