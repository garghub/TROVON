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
do {
V_17 = F_2 ( V_13 ) ;
if ( F_3 ( V_17 ) )
return V_17 ;
F_4 ( & V_10 -> V_19 ) ;
V_15 = F_5 ( V_13 ,
V_8 -> V_20 , V_8 -> V_21 ,
V_6 -> V_22 , V_16 , 1 ) ;
if ( F_3 ( V_15 == NULL ) ) {
F_6 ( & V_10 -> V_19 ) ;
return 0 ;
}
V_15 = F_7 ( V_15 , V_8 -> V_20 ,
V_8 -> V_21 ,
V_6 -> V_22 ,
V_16 ) ;
F_6 ( & V_10 -> V_19 ) ;
} while ( V_15 == NULL );
V_8 -> V_23 = V_15 ;
V_8 -> V_24 = V_15 -> V_24 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
if ( V_8 -> V_23 ) {
F_4 ( & V_10 -> V_19 ) ;
F_9 ( V_8 -> V_23 ) ;
F_6 ( & V_10 -> V_19 ) ;
V_8 -> V_23 = NULL ;
}
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_25 )
{
struct V_9 * V_10 ;
V_10 = F_11 ( sizeof( * V_10 ) , V_26 ) ;
if ( ! V_10 )
return - V_27 ;
F_12 ( & V_10 -> V_13 , 0 , V_25 ) ;
F_13 ( & V_10 -> V_19 ) ;
V_2 -> V_11 = V_10 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
struct V_12 * V_13 = & V_10 -> V_13 ;
F_4 ( & V_10 -> V_19 ) ;
if ( F_15 ( V_13 ) ) {
F_16 ( V_13 ) ;
F_6 ( & V_10 -> V_19 ) ;
F_17 ( V_10 ) ;
V_2 -> V_11 = NULL ;
return 0 ;
}
F_6 ( & V_10 -> V_19 ) ;
return - V_28 ;
}
static void F_18 ( struct V_1 * V_2 ,
const char * V_29 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
F_4 ( & V_10 -> V_19 ) ;
F_19 ( & V_10 -> V_13 , V_29 ) ;
F_6 ( & V_10 -> V_19 ) ;
}
