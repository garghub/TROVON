static void * F_1 ( void * V_1 , unsigned long V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 ;
V_6 = F_2 ( sizeof *V_6 , V_7 ) ;
if ( ! V_6 )
return F_3 ( - V_8 ) ;
V_6 -> V_9 = F_4 ( V_4 -> V_10 , V_2 , & V_6 -> V_11 ,
V_7 ) ;
if ( ! V_6 -> V_9 ) {
F_5 ( V_4 -> V_10 , L_1 ,
V_2 ) ;
F_6 ( V_6 ) ;
return F_3 ( - V_8 ) ;
}
V_6 -> V_4 = V_4 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_12 . V_13 = & V_6 -> V_13 ;
V_6 -> V_12 . V_14 = V_15 ;
V_6 -> V_12 . V_16 = V_6 ;
F_7 ( & V_6 -> V_13 ) ;
return V_6 ;
}
static void V_15 ( void * V_17 )
{
struct V_5 * V_6 = V_17 ;
if ( F_8 ( & V_6 -> V_13 ) ) {
F_9 ( V_6 -> V_4 -> V_10 , V_6 -> V_2 , V_6 -> V_9 ,
V_6 -> V_11 ) ;
F_6 ( V_6 ) ;
}
}
static void * F_10 ( void * V_17 )
{
struct V_5 * V_6 = V_17 ;
return & V_6 -> V_11 ;
}
static void * F_11 ( void * V_17 )
{
struct V_5 * V_6 = V_17 ;
if ( ! V_6 )
return 0 ;
return V_6 -> V_9 ;
}
static unsigned int F_12 ( void * V_17 )
{
struct V_5 * V_6 = V_17 ;
return F_13 ( & V_6 -> V_13 ) ;
}
static int F_14 ( void * V_17 , struct V_18 * V_19 )
{
struct V_5 * V_6 = V_17 ;
if ( ! V_6 ) {
F_15 ( V_20 L_2 ) ;
return - V_21 ;
}
return F_16 ( V_19 , V_6 -> V_11 , V_6 -> V_2 ,
& V_22 , & V_6 -> V_12 ) ;
}
static void * F_17 ( void * V_1 , unsigned long V_9 ,
unsigned long V_2 , int V_23 )
{
struct V_5 * V_6 ;
struct V_18 * V_19 ;
T_1 V_11 = 0 ;
int V_24 ;
V_6 = F_2 ( sizeof *V_6 , V_7 ) ;
if ( ! V_6 )
return F_3 ( - V_8 ) ;
V_24 = F_18 ( V_9 , V_2 , & V_19 , & V_11 ) ;
if ( V_24 ) {
F_15 ( V_20 L_3 ,
V_9 ) ;
F_6 ( V_6 ) ;
return F_3 ( V_24 ) ;
}
V_6 -> V_2 = V_2 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_19 = V_19 ;
return V_6 ;
}
static void F_19 ( void * V_25 )
{
struct V_5 * V_6 = V_25 ;
if ( ! V_6 )
return;
F_20 ( V_6 -> V_19 ) ;
F_6 ( V_6 ) ;
}
void * F_21 ( struct V_26 * V_10 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( sizeof *V_4 , V_7 ) ;
if ( ! V_4 )
return F_3 ( - V_8 ) ;
V_4 -> V_10 = V_10 ;
return V_4 ;
}
void F_22 ( void * V_1 )
{
F_6 ( V_1 ) ;
}
