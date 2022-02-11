static struct V_1 * F_1 ( union V_2 * V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 , V_7 ;
if ( V_3 -> V_8 == 0 || V_3 -> V_9 != 4 ||
V_3 -> V_10 == 0 )
return F_2 ( - V_11 ) ;
V_6 = F_3 ( V_3 -> V_10 , 8 ) ;
if ( V_6 == 0 ||
V_3 -> V_8 > ( V_12 - sizeof( * V_5 ) ) / V_6 )
return F_2 ( - V_13 ) ;
V_7 = sizeof( * V_5 ) + V_3 -> V_8 * V_6 ;
V_5 = F_4 ( V_7 , V_14 | V_15 ) ;
if ( ! V_5 ) {
V_5 = F_5 ( V_7 ) ;
if ( ! V_5 )
return F_2 ( - V_13 ) ;
}
V_5 -> V_16 . V_9 = V_3 -> V_9 ;
V_5 -> V_16 . V_10 = V_3 -> V_10 ;
V_5 -> V_16 . V_8 = V_3 -> V_8 ;
V_5 -> V_6 = V_6 ;
return & V_5 -> V_16 ;
}
static void * F_6 ( struct V_1 * V_16 , void * V_17 )
{
struct V_4 * V_5 = F_7 ( V_16 , struct V_4 , V_16 ) ;
T_1 V_18 = * ( T_1 * ) V_17 ;
if ( V_18 >= V_5 -> V_16 . V_8 )
return NULL ;
return V_5 -> V_19 + V_5 -> V_6 * V_18 ;
}
static int F_8 ( struct V_1 * V_16 , void * V_17 , void * V_20 )
{
struct V_4 * V_5 = F_7 ( V_16 , struct V_4 , V_16 ) ;
T_1 V_18 = * ( T_1 * ) V_17 ;
T_1 * V_21 = ( T_1 * ) V_20 ;
if ( V_18 >= V_5 -> V_16 . V_8 ) {
* V_21 = 0 ;
return 0 ;
}
if ( V_18 == V_5 -> V_16 . V_8 - 1 )
return - V_22 ;
* V_21 = V_18 + 1 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_16 , void * V_17 , void * V_19 ,
T_2 V_23 )
{
struct V_4 * V_5 = F_7 ( V_16 , struct V_4 , V_16 ) ;
T_1 V_18 = * ( T_1 * ) V_17 ;
if ( V_23 > V_24 )
return - V_11 ;
if ( V_18 >= V_5 -> V_16 . V_8 )
return - V_25 ;
if ( V_23 == V_26 )
return - V_27 ;
memcpy ( V_5 -> V_19 + V_5 -> V_6 * V_18 , V_19 , V_5 -> V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_16 , void * V_17 )
{
return - V_11 ;
}
static void F_11 ( struct V_1 * V_16 )
{
struct V_4 * V_5 = F_7 ( V_16 , struct V_4 , V_16 ) ;
F_12 () ;
F_13 ( V_5 ) ;
}
static int T_3 F_14 ( void )
{
F_15 ( & V_28 ) ;
return 0 ;
}
