static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
struct V_12 * V_13 = & V_10 -> V_13 ;
struct V_14 * V_15 ;
enum V_16 V_17 ;
unsigned long V_18 ;
int V_19 ;
V_18 = V_6 -> V_18 ;
if ( ! V_18 )
V_18 = V_2 -> V_20 ;
V_15 = F_2 ( sizeof( * V_15 ) , V_21 ) ;
if ( ! V_15 )
return - V_22 ;
V_17 = V_23 ;
if ( V_6 -> V_24 & V_25 )
V_17 = V_26 ;
F_3 ( & V_10 -> V_27 ) ;
V_19 = F_4 ( V_13 , V_15 ,
V_8 -> V_28 ,
V_8 -> V_29 , 0 ,
V_6 -> V_30 , V_18 , V_17 ) ;
F_5 ( & V_10 -> V_27 ) ;
if ( F_6 ( V_19 ) ) {
F_7 ( V_15 ) ;
} else {
V_8 -> V_31 = V_15 ;
V_8 -> V_32 = V_15 -> V_32 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
if ( V_8 -> V_31 ) {
F_3 ( & V_10 -> V_27 ) ;
F_9 ( V_8 -> V_31 ) ;
F_5 ( & V_10 -> V_27 ) ;
F_7 ( V_8 -> V_31 ) ;
V_8 -> V_31 = NULL ;
}
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_33 )
{
struct V_9 * V_10 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_21 ) ;
if ( ! V_10 )
return - V_22 ;
F_11 ( & V_10 -> V_13 , 0 , V_33 ) ;
F_12 ( & V_10 -> V_27 ) ;
V_2 -> V_11 = V_10 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
struct V_12 * V_13 = & V_10 -> V_13 ;
F_3 ( & V_10 -> V_27 ) ;
if ( F_14 ( V_13 ) ) {
F_15 ( V_13 ) ;
F_5 ( & V_10 -> V_27 ) ;
F_7 ( V_10 ) ;
V_2 -> V_11 = NULL ;
return 0 ;
}
F_5 ( & V_10 -> V_27 ) ;
return - V_34 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
F_3 ( & V_10 -> V_27 ) ;
F_17 ( & V_10 -> V_13 , V_36 ) ;
F_5 ( & V_10 -> V_27 ) ;
}
