static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_1 V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_14 ;
struct V_15 * V_16 = NULL ;
enum V_17 V_18 = V_19 ;
unsigned long V_20 ;
int V_21 ;
V_20 = V_6 -> V_20 ;
if ( ! V_20 )
V_20 = V_2 -> V_22 ;
V_16 = F_2 ( sizeof( * V_16 ) , V_23 ) ;
if ( ! V_16 )
return - V_24 ;
if ( V_7 & V_25 )
V_18 = V_26 ;
F_3 ( & V_11 -> V_27 ) ;
V_21 = F_4 ( V_14 , V_16 , V_9 -> V_28 ,
V_9 -> V_29 , 0 ,
V_6 -> V_30 , V_20 ,
V_31 ,
V_18 ) ;
F_5 ( & V_11 -> V_27 ) ;
if ( F_6 ( V_21 ) ) {
F_7 ( V_16 ) ;
} else {
V_9 -> V_32 = V_16 ;
V_9 -> V_33 = V_16 -> V_33 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
if ( V_9 -> V_32 ) {
F_3 ( & V_11 -> V_27 ) ;
F_9 ( V_9 -> V_32 ) ;
F_5 ( & V_11 -> V_27 ) ;
F_7 ( V_9 -> V_32 ) ;
V_9 -> V_32 = NULL ;
}
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_34 )
{
struct V_10 * V_11 ;
V_11 = F_2 ( sizeof( * V_11 ) , V_23 ) ;
if ( ! V_11 )
return - V_24 ;
F_11 ( & V_11 -> V_14 , 0 , V_34 ) ;
F_12 ( & V_11 -> V_27 ) ;
V_2 -> V_12 = V_11 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_14 ;
F_3 ( & V_11 -> V_27 ) ;
if ( F_14 ( V_14 ) ) {
F_15 ( V_14 ) ;
F_5 ( & V_11 -> V_27 ) ;
F_7 ( V_11 ) ;
V_2 -> V_12 = NULL ;
return 0 ;
}
F_5 ( & V_11 -> V_27 ) ;
return - V_35 ;
}
static void F_16 ( struct V_1 * V_2 ,
const char * V_36 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
F_3 ( & V_11 -> V_27 ) ;
F_17 ( & V_11 -> V_14 , V_36 ) ;
F_5 ( & V_11 -> V_27 ) ;
}
