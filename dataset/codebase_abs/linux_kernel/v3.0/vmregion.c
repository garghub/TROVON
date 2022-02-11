struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 ,
T_1 V_5 , T_2 V_6 )
{
unsigned long V_7 = V_3 -> V_8 , V_9 = V_3 -> V_10 ;
unsigned long V_11 ;
struct V_1 * V_12 , * V_13 ;
if ( V_3 -> V_10 - V_3 -> V_8 < V_5 ) {
F_2 ( V_14 L_1 ,
V_15 , V_5 ) ;
goto V_16;
}
V_13 = F_3 ( sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_13 )
goto V_16;
F_4 ( & V_3 -> V_17 , V_11 ) ;
V_9 = F_5 ( V_9 - V_5 , V_4 ) ;
F_6 (c, &head->vm_list, vm_list) {
if ( V_9 >= V_12 -> V_10 )
goto V_18;
V_9 = F_5 ( V_12 -> V_8 - V_5 , V_4 ) ;
if ( V_9 < V_7 )
goto V_19;
}
V_18:
F_7 ( & V_13 -> V_20 , & V_12 -> V_20 ) ;
V_13 -> V_8 = V_9 ;
V_13 -> V_10 = V_9 + V_5 ;
V_13 -> V_21 = 1 ;
F_8 ( & V_3 -> V_17 , V_11 ) ;
return V_13 ;
V_19:
F_8 ( & V_3 -> V_17 , V_11 ) ;
F_9 ( V_13 ) ;
V_16:
return NULL ;
}
static struct V_1 * F_10 ( struct V_2 * V_3 , unsigned long V_9 )
{
struct V_1 * V_12 ;
F_11 (c, &head->vm_list, vm_list) {
if ( V_12 -> V_21 && V_12 -> V_8 == V_9 )
goto V_16;
}
V_12 = NULL ;
V_16:
return V_12 ;
}
struct V_1 * F_12 ( struct V_2 * V_3 , unsigned long V_9 )
{
struct V_1 * V_12 ;
unsigned long V_11 ;
F_4 ( & V_3 -> V_17 , V_11 ) ;
V_12 = F_10 ( V_3 , V_9 ) ;
F_8 ( & V_3 -> V_17 , V_11 ) ;
return V_12 ;
}
struct V_1 * F_13 ( struct V_2 * V_3 , unsigned long V_9 )
{
struct V_1 * V_12 ;
unsigned long V_11 ;
F_4 ( & V_3 -> V_17 , V_11 ) ;
V_12 = F_10 ( V_3 , V_9 ) ;
if ( V_12 )
V_12 -> V_21 = 0 ;
F_8 ( & V_3 -> V_17 , V_11 ) ;
return V_12 ;
}
void F_14 ( struct V_2 * V_3 , struct V_1 * V_12 )
{
unsigned long V_11 ;
F_4 ( & V_3 -> V_17 , V_11 ) ;
F_15 ( & V_12 -> V_20 ) ;
F_8 ( & V_3 -> V_17 , V_11 ) ;
F_9 ( V_12 ) ;
}
