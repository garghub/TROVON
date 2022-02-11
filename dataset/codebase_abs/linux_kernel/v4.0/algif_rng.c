static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_7 , int V_8 )
{
struct V_4 * V_9 = V_4 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_15 = - V_16 ;
int V_17 = 0 ;
T_2 V_18 [ V_19 ] ;
if ( V_7 == 0 )
return 0 ;
if ( V_7 > V_19 )
V_7 = V_19 ;
memset ( V_18 , 0 , V_7 ) ;
V_17 = F_3 ( V_13 -> V_20 , V_18 , V_7 ) ;
if ( V_17 < 0 )
return V_17 ;
V_15 = F_4 ( V_6 , V_18 , V_7 ) ;
F_5 ( V_18 , V_17 ) ;
return V_15 ? V_15 : V_7 ;
}
static void * F_6 ( const char * V_21 , T_3 type , T_3 V_22 )
{
return F_7 ( V_21 , type , V_22 ) ;
}
static void F_8 ( void * V_14 )
{
F_9 ( V_14 ) ;
}
static void F_10 ( struct V_4 * V_9 )
{
struct V_10 * V_11 = F_2 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
F_11 ( V_9 , V_13 , V_13 -> V_7 ) ;
F_12 ( V_9 ) ;
}
static int F_13 ( void * V_14 , struct V_4 * V_9 )
{
struct V_12 * V_13 ;
struct V_10 * V_11 = F_2 ( V_9 ) ;
unsigned int V_7 = sizeof( * V_13 ) ;
V_13 = F_14 ( V_9 , V_7 , V_23 ) ;
if ( ! V_13 )
return - V_24 ;
V_13 -> V_7 = V_7 ;
V_13 -> V_20 = V_14 ;
V_11 -> V_14 = V_13 ;
V_9 -> V_25 = F_10 ;
return 0 ;
}
static int F_15 ( void * V_14 , const T_2 * V_26 , unsigned int V_27 )
{
return F_16 ( V_14 , ( T_2 * ) V_26 , V_27 ) ;
}
static int T_4 F_17 ( void )
{
return F_18 ( & V_28 ) ;
}
static void T_5 F_19 ( void )
{
int V_15 = F_20 ( & V_28 ) ;
F_21 ( V_15 ) ;
}
