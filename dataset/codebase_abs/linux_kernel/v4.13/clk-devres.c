static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( * (struct V_4 * * ) V_3 ) ;
}
struct V_4 * F_3 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_4 * * V_6 , * V_4 ;
V_6 = F_4 ( F_1 , sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return F_5 ( - V_8 ) ;
V_4 = F_6 ( V_2 , V_5 ) ;
if ( ! F_7 ( V_4 ) ) {
* V_6 = V_4 ;
F_8 ( V_2 , V_6 ) ;
} else {
F_9 ( V_6 ) ;
}
return V_4 ;
}
static void F_10 ( struct V_1 * V_2 , void * V_3 )
{
struct V_9 * V_10 = V_3 ;
F_11 ( V_10 -> V_11 , V_10 -> V_12 ) ;
}
int T_1 F_12 ( struct V_1 * V_2 , int V_11 ,
struct V_13 * V_12 )
{
struct V_9 * V_10 ;
int V_14 ;
V_10 = F_4 ( F_10 ,
sizeof( * V_10 ) , V_7 ) ;
if ( ! V_10 )
return - V_8 ;
V_14 = F_13 ( V_2 , V_11 , V_12 ) ;
if ( ! V_14 ) {
V_10 -> V_12 = V_12 ;
V_10 -> V_11 = V_11 ;
F_8 ( V_2 , V_10 ) ;
} else {
F_9 ( V_10 ) ;
}
return V_14 ;
}
static int F_14 ( struct V_1 * V_2 , void * V_3 , void * V_15 )
{
struct V_4 * * V_16 = V_3 ;
if ( ! V_16 || ! * V_16 ) {
F_15 ( ! V_16 || ! * V_16 ) ;
return 0 ;
}
return * V_16 == V_15 ;
}
void F_16 ( struct V_1 * V_2 , struct V_4 * V_4 )
{
int V_14 ;
V_14 = F_17 ( V_2 , F_1 , F_14 , V_4 ) ;
F_15 ( V_14 ) ;
}
struct V_4 * F_18 ( struct V_1 * V_2 ,
struct V_17 * V_18 , const char * V_19 )
{
struct V_4 * * V_6 , * V_4 ;
V_6 = F_4 ( F_1 , sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return F_5 ( - V_8 ) ;
V_4 = F_19 ( V_18 , V_19 ) ;
if ( ! F_7 ( V_4 ) ) {
* V_6 = V_4 ;
F_8 ( V_2 , V_6 ) ;
} else {
F_9 ( V_6 ) ;
}
return V_4 ;
}
