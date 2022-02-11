struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 ,
T_1 V_5 , T_2 V_6 , const void * V_7 )
{
unsigned long V_8 = V_3 -> V_9 , V_10 = V_3 -> V_11 ;
unsigned long V_12 ;
struct V_1 * V_13 , * V_14 ;
if ( V_3 -> V_11 - V_3 -> V_9 < V_5 ) {
F_2 ( V_15 L_1 ,
V_16 , V_5 ) ;
goto V_17;
}
V_14 = F_3 ( sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_14 )
goto V_17;
V_14 -> V_7 = V_7 ;
F_4 ( & V_3 -> V_18 , V_12 ) ;
V_10 = F_5 ( V_10 - V_5 , V_4 ) ;
F_6 (c, &head->vm_list, vm_list) {
if ( V_10 >= V_13 -> V_11 )
goto V_19;
V_10 = F_5 ( V_13 -> V_9 - V_5 , V_4 ) ;
if ( V_10 < V_8 )
goto V_20;
}
V_19:
F_7 ( & V_14 -> V_21 , & V_13 -> V_21 ) ;
V_14 -> V_9 = V_10 ;
V_14 -> V_11 = V_10 + V_5 ;
V_14 -> V_22 = 1 ;
F_8 ( & V_3 -> V_18 , V_12 ) ;
return V_14 ;
V_20:
F_8 ( & V_3 -> V_18 , V_12 ) ;
F_9 ( V_14 ) ;
V_17:
return NULL ;
}
static struct V_1 * F_10 ( struct V_2 * V_3 , unsigned long V_10 )
{
struct V_1 * V_13 ;
F_11 (c, &head->vm_list, vm_list) {
if ( V_13 -> V_22 && V_13 -> V_9 == V_10 )
goto V_17;
}
V_13 = NULL ;
V_17:
return V_13 ;
}
struct V_1 * F_12 ( struct V_2 * V_3 , unsigned long V_10 )
{
struct V_1 * V_13 ;
unsigned long V_12 ;
F_4 ( & V_3 -> V_18 , V_12 ) ;
V_13 = F_10 ( V_3 , V_10 ) ;
F_8 ( & V_3 -> V_18 , V_12 ) ;
return V_13 ;
}
struct V_1 * F_13 ( struct V_2 * V_3 , unsigned long V_10 )
{
struct V_1 * V_13 ;
unsigned long V_12 ;
F_4 ( & V_3 -> V_18 , V_12 ) ;
V_13 = F_10 ( V_3 , V_10 ) ;
if ( V_13 )
V_13 -> V_22 = 0 ;
F_8 ( & V_3 -> V_18 , V_12 ) ;
return V_13 ;
}
void F_14 ( struct V_2 * V_3 , struct V_1 * V_13 )
{
unsigned long V_12 ;
F_4 ( & V_3 -> V_18 , V_12 ) ;
F_15 ( & V_13 -> V_21 ) ;
F_8 ( & V_3 -> V_18 , V_12 ) ;
F_9 ( V_13 ) ;
}
static int F_16 ( struct V_23 * V_24 , void * V_25 )
{
struct V_1 * V_13 = F_17 ( V_25 , struct V_1 , V_21 ) ;
F_18 ( V_24 , L_2 , V_13 -> V_9 , V_13 -> V_11 ,
V_13 -> V_11 - V_13 -> V_9 ) ;
if ( V_13 -> V_7 )
F_18 ( V_24 , L_3 , ( void * ) V_13 -> V_7 ) ;
F_19 ( V_24 , '\n' ) ;
return 0 ;
}
static void * F_20 ( struct V_23 * V_24 , T_3 * V_26 )
{
struct V_2 * V_27 = V_24 -> V_28 ;
F_21 ( & V_27 -> V_18 ) ;
return F_22 ( & V_27 -> V_21 , * V_26 ) ;
}
static void * F_23 ( struct V_23 * V_24 , void * V_25 , T_3 * V_26 )
{
struct V_2 * V_27 = V_24 -> V_28 ;
return F_24 ( V_25 , & V_27 -> V_21 , V_26 ) ;
}
static void F_25 ( struct V_23 * V_24 , void * V_25 )
{
struct V_2 * V_27 = V_24 -> V_28 ;
F_26 ( & V_27 -> V_18 ) ;
}
static int F_27 ( struct V_29 * V_29 , struct V_30 * V_30 )
{
struct V_2 * V_27 = F_28 ( V_29 ) -> V_31 ;
int V_32 = F_29 ( V_30 , & V_33 ) ;
if ( ! V_32 ) {
struct V_23 * V_24 = V_30 -> V_34 ;
V_24 -> V_28 = V_27 ;
}
return V_32 ;
}
int F_30 ( const char * V_35 , struct V_2 * V_27 )
{
F_31 ( V_35 , V_36 , NULL , & V_37 , V_27 ) ;
return 0 ;
}
int F_30 ( const char * V_35 , struct V_2 * V_27 )
{
return 0 ;
}
