static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
if ( F_2 ( & V_3 ) )
return NULL ;
V_2 = F_3 ( V_3 . V_4 , struct V_1 , V_5 ) ;
if ( V_2 == V_6 )
return NULL ;
return V_2 ;
}
static int F_4 ( struct V_1 * V_7 )
{
struct V_8 * V_9 , * V_10 = & V_3 ;
F_5 (tmp, &unwinder_list) {
struct V_1 * V_11 ;
V_11 = F_3 ( V_9 , struct V_1 , V_5 ) ;
if ( V_11 == V_7 )
return - V_12 ;
if ( V_11 -> V_13 >= V_7 -> V_13 )
V_10 = V_9 ;
}
F_6 ( & V_7 -> V_5 , V_10 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_14 )
{
unsigned long V_15 ;
int V_16 ;
F_8 ( & V_17 , V_15 ) ;
V_16 = F_4 ( V_14 ) ;
if ( ! V_16 )
V_6 = F_1 () ;
F_9 ( & V_17 , V_15 ) ;
return V_16 ;
}
void F_10 ( struct V_18 * V_19 , struct V_20 * V_21 ,
unsigned long * V_22 , const struct V_23 * V_7 ,
void * V_24 )
{
unsigned long V_15 ;
if ( V_25 ) {
F_8 ( & V_17 , V_15 ) ;
if ( V_25 && ! F_11 ( & V_3 ) ) {
F_12 ( & V_6 -> V_5 ) ;
V_6 = F_1 () ;
V_25 = 0 ;
}
F_9 ( & V_17 , V_15 ) ;
}
V_6 -> V_26 ( V_19 , V_21 , V_22 , V_7 , V_24 ) ;
}
