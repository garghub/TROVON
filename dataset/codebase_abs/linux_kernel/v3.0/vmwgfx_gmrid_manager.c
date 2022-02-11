static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 =
(struct V_9 * ) V_2 -> V_11 ;
int V_12 ;
int V_13 ;
V_8 -> V_14 = NULL ;
do {
if ( F_2 ( F_3 ( & V_10 -> V_15 , V_16 ) == 0 ) )
return - V_17 ;
F_4 ( & V_10 -> V_18 ) ;
V_12 = F_5 ( & V_10 -> V_15 , & V_13 ) ;
if ( F_2 ( V_12 == 0 && V_13 >= V_10 -> V_19 ) ) {
F_6 ( & V_10 -> V_15 , V_13 ) ;
F_7 ( & V_10 -> V_18 ) ;
return 0 ;
}
F_7 ( & V_10 -> V_18 ) ;
} while ( V_12 == - V_20 );
if ( F_8 ( V_12 == 0 ) ) {
V_8 -> V_14 = V_10 ;
V_8 -> V_21 = V_13 ;
}
return V_12 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 =
(struct V_9 * ) V_2 -> V_11 ;
if ( V_8 -> V_14 ) {
F_4 ( & V_10 -> V_18 ) ;
F_6 ( & V_10 -> V_15 , V_8 -> V_21 ) ;
F_7 ( & V_10 -> V_18 ) ;
V_8 -> V_14 = NULL ;
}
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_22 )
{
struct V_9 * V_10 =
F_11 ( sizeof( * V_10 ) , V_16 ) ;
if ( F_2 ( V_10 == NULL ) )
return - V_17 ;
F_12 ( & V_10 -> V_18 ) ;
F_13 ( & V_10 -> V_15 ) ;
V_10 -> V_19 = V_22 ;
V_2 -> V_11 = ( void * ) V_10 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_9 * V_10 =
(struct V_9 * ) V_2 -> V_11 ;
if ( V_10 ) {
F_15 ( & V_10 -> V_15 ) ;
F_16 ( V_10 ) ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 ,
const char * V_23 )
{
F_18 ( V_24 L_1
L_2 , V_23 ) ;
}
