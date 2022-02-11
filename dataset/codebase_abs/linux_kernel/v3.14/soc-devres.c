static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( * (struct V_1 * * ) V_3 ) ;
}
int F_3 ( struct V_1 * V_2 ,
const struct V_4 * V_5 ,
struct V_6 * V_7 , int V_8 )
{
struct V_1 * * V_9 ;
int V_10 ;
V_9 = F_4 ( F_1 , sizeof( * V_9 ) , V_11 ) ;
if ( ! V_9 )
return - V_12 ;
V_10 = F_5 ( V_2 , V_5 , V_7 , V_8 ) ;
if ( V_10 == 0 ) {
* V_9 = V_2 ;
F_6 ( V_2 , V_9 ) ;
} else {
F_7 ( V_9 ) ;
}
return V_10 ;
}
static void F_8 ( struct V_1 * V_2 , void * V_3 )
{
F_9 ( * (struct V_13 * * ) V_3 ) ;
}
int F_10 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_13 * * V_9 ;
int V_10 ;
V_9 = F_4 ( F_8 , sizeof( * V_9 ) , V_11 ) ;
if ( ! V_9 )
return - V_12 ;
V_10 = F_11 ( V_14 ) ;
if ( V_10 == 0 ) {
* V_9 = V_14 ;
F_6 ( V_2 , V_9 ) ;
} else {
F_7 ( V_9 ) ;
}
return V_10 ;
}
static void F_12 ( struct V_1 * V_2 , void * V_3 )
{
F_13 ( * (struct V_1 * * ) V_3 ) ;
}
int F_14 ( struct V_1 * V_2 ,
const struct V_15 * V_16 , unsigned int V_17 )
{
struct V_1 * * V_9 ;
int V_10 ;
V_9 = F_4 ( F_12 , sizeof( * V_9 ) , V_11 ) ;
if ( ! V_9 )
return - V_12 ;
V_10 = F_15 ( V_2 , V_16 , V_17 ) ;
if ( V_10 == 0 ) {
* V_9 = V_2 ;
F_6 ( V_2 , V_9 ) ;
} else {
F_7 ( V_9 ) ;
}
return V_10 ;
}
