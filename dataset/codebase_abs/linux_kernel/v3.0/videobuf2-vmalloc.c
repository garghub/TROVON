static void * F_1 ( void * V_1 , unsigned long V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( sizeof *V_4 , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_2 = V_2 ;
V_4 -> V_6 = F_3 ( V_4 -> V_2 ) ;
V_4 -> V_7 . V_8 = & V_4 -> V_8 ;
V_4 -> V_7 . V_9 = V_10 ;
V_4 -> V_7 . V_11 = V_4 ;
if ( ! V_4 -> V_6 ) {
F_4 ( V_12 L_1 , V_4 -> V_2 ) ;
F_5 ( V_4 ) ;
return NULL ;
}
F_6 ( & V_4 -> V_8 ) ;
F_4 ( V_13 L_2 ,
V_4 -> V_2 , V_4 -> V_6 ) ;
return V_4 ;
}
static void V_10 ( void * V_14 )
{
struct V_3 * V_4 = V_14 ;
if ( F_7 ( & V_4 -> V_8 ) ) {
F_4 ( V_13 L_3 ,
V_15 , V_4 -> V_6 ) ;
F_8 ( V_4 -> V_6 ) ;
F_5 ( V_4 ) ;
}
}
static void * F_9 ( void * V_14 )
{
struct V_3 * V_4 = V_14 ;
F_10 ( ! V_4 ) ;
if ( ! V_4 -> V_6 ) {
F_4 ( V_12 L_4 ) ;
return NULL ;
}
return V_4 -> V_6 ;
}
static unsigned int F_11 ( void * V_14 )
{
struct V_3 * V_4 = V_14 ;
return F_12 ( & V_4 -> V_8 ) ;
}
static int F_13 ( void * V_14 , struct V_16 * V_17 )
{
struct V_3 * V_4 = V_14 ;
int V_18 ;
if ( ! V_4 ) {
F_4 ( V_12 L_5 ) ;
return - V_19 ;
}
V_18 = F_14 ( V_17 , V_4 -> V_6 , 0 ) ;
if ( V_18 ) {
F_4 ( V_12 L_6 , V_18 ) ;
return V_18 ;
}
V_17 -> V_20 |= V_21 ;
V_17 -> V_22 = & V_4 -> V_7 ;
V_17 -> V_23 = & V_24 ;
V_17 -> V_23 -> V_25 ( V_17 ) ;
return 0 ;
}
