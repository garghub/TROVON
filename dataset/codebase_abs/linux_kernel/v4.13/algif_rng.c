static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_5 ,
int V_6 )
{
struct V_2 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_13 = - V_14 ;
int V_15 = 0 ;
T_2 V_16 [ V_17 ] ;
if ( V_5 == 0 )
return 0 ;
if ( V_5 > V_17 )
V_5 = V_17 ;
memset ( V_16 , 0 , V_5 ) ;
V_15 = F_3 ( V_11 -> V_18 , V_16 , V_5 ) ;
if ( V_15 < 0 )
return V_15 ;
V_13 = F_4 ( V_4 , V_16 , V_5 ) ;
F_5 ( V_16 , V_5 ) ;
return V_13 ? V_13 : V_5 ;
}
static void * F_6 ( const char * V_19 , T_3 type , T_3 V_20 )
{
return F_7 ( V_19 , type , V_20 ) ;
}
static void F_8 ( void * V_12 )
{
F_9 ( V_12 ) ;
}
static void F_10 ( struct V_2 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
F_11 ( V_7 , V_11 , V_11 -> V_5 ) ;
F_12 ( V_7 ) ;
}
static int F_13 ( void * V_12 , struct V_2 * V_7 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
unsigned int V_5 = sizeof( * V_11 ) ;
V_11 = F_14 ( V_7 , V_5 , V_21 ) ;
if ( ! V_11 )
return - V_22 ;
V_11 -> V_5 = V_5 ;
V_11 -> V_18 = V_12 ;
V_9 -> V_12 = V_11 ;
V_7 -> V_23 = F_10 ;
return 0 ;
}
static int F_15 ( void * V_12 , const T_2 * V_24 , unsigned int V_25 )
{
return F_16 ( V_12 , V_24 , V_25 ) ;
}
static int T_4 F_17 ( void )
{
return F_18 ( & V_26 ) ;
}
static void T_5 F_19 ( void )
{
int V_13 = F_20 ( & V_26 ) ;
F_21 ( V_13 ) ;
}
