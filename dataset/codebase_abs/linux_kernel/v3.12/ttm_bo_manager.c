static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
struct V_12 * V_13 = & V_10 -> V_13 ;
struct V_14 * V_15 = NULL ;
unsigned long V_16 ;
int V_17 ;
V_16 = V_6 -> V_16 ;
if ( ! V_16 )
V_16 = V_2 -> V_18 ;
V_15 = F_2 ( sizeof( * V_15 ) , V_19 ) ;
if ( ! V_15 )
return - V_20 ;
F_3 ( & V_10 -> V_21 ) ;
V_17 = F_4 ( V_13 , V_15 , V_8 -> V_22 ,
V_8 -> V_23 ,
V_6 -> V_24 , V_16 ,
V_25 ) ;
F_5 ( & V_10 -> V_21 ) ;
if ( F_6 ( V_17 ) ) {
F_7 ( V_15 ) ;
} else {
V_8 -> V_26 = V_15 ;
V_8 -> V_27 = V_15 -> V_27 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
if ( V_8 -> V_26 ) {
F_3 ( & V_10 -> V_21 ) ;
F_9 ( V_8 -> V_26 ) ;
F_5 ( & V_10 -> V_21 ) ;
F_7 ( V_8 -> V_26 ) ;
V_8 -> V_26 = NULL ;
}
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_28 )
{
struct V_9 * V_10 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_19 ) ;
if ( ! V_10 )
return - V_20 ;
F_11 ( & V_10 -> V_13 , 0 , V_28 ) ;
F_12 ( & V_10 -> V_21 ) ;
V_2 -> V_11 = V_10 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
struct V_12 * V_13 = & V_10 -> V_13 ;
F_3 ( & V_10 -> V_21 ) ;
if ( F_14 ( V_13 ) ) {
F_15 ( V_13 ) ;
F_5 ( & V_10 -> V_21 ) ;
F_7 ( V_10 ) ;
V_2 -> V_11 = NULL ;
return 0 ;
}
F_5 ( & V_10 -> V_21 ) ;
return - V_29 ;
}
static void F_16 ( struct V_1 * V_2 ,
const char * V_30 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
F_3 ( & V_10 -> V_21 ) ;
F_17 ( & V_10 -> V_13 , V_30 ) ;
F_5 ( & V_10 -> V_21 ) ;
}
