static struct V_1 * F_1 ( unsigned int V_2 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 ;
F_2 (lh, &pool_list) {
V_5 = F_3 ( V_4 , struct V_1 , V_6 ) ;
if ( V_5 -> V_2 == V_2 )
return V_5 ;
}
return NULL ;
}
unsigned long F_4 ( unsigned int V_2 , T_1 V_7 )
{
unsigned long V_8 ;
struct V_1 * V_5 ;
V_5 = F_1 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
V_8 = F_5 ( V_5 -> V_5 , V_7 ) ;
if ( ! V_8 )
return 0 ;
return V_8 ;
}
void F_6 ( unsigned int V_2 , unsigned long V_9 , T_1 V_7 )
{
struct V_1 * V_5 ;
V_5 = F_1 ( V_2 ) ;
if ( ! V_5 )
return;
F_7 ( V_5 -> V_5 , V_9 , V_7 ) ;
}
unsigned int F_8 ( unsigned long V_10 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 ;
unsigned long V_9 = ( unsigned long ) V_10 ;
F_2 (lh, &pool_list) {
V_5 = F_3 ( V_4 , struct V_1 , V_6 ) ;
if ( V_9 >= V_5 -> V_11 && V_9 < V_5 -> V_12 )
return V_5 -> V_2 ;
}
return V_13 ;
}
int T_2 F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_5 ;
V_5 = F_10 ( sizeof( * V_5 ) , V_16 ) ;
if ( ! V_5 ) {
F_11 ( L_1 ) ;
return - V_17 ;
}
V_5 -> V_2 = V_15 -> V_2 ;
V_5 -> V_11 = V_15 -> V_18 . V_11 ;
V_5 -> V_12 = V_15 -> V_18 . V_12 ;
V_5 -> V_5 = F_12 ( 3 , - 1 ) ;
if ( ! V_5 -> V_5 ) {
F_11 ( L_2 ) ;
F_13 ( V_5 ) ;
return - V_17 ;
}
if ( F_14 ( V_5 -> V_5 , V_15 -> V_18 . V_11 ,
V_15 -> V_18 . V_12 - V_15 -> V_18 . V_11 + 1 , - 1 ) ) {
F_11 ( L_3 ) ;
return - V_17 ;
}
F_15 ( L_4 ,
V_15 -> V_18 . V_19 , V_15 -> V_18 . V_12 - V_15 -> V_18 . V_11 + 1 ,
V_15 -> V_18 . V_11 ) ;
F_16 ( & V_5 -> V_6 , & V_20 ) ;
return 0 ;
}
