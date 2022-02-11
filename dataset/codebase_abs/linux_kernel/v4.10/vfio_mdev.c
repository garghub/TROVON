static int F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_5 ;
int V_6 ;
if ( F_2 ( ! V_5 -> V_7 -> V_8 ) )
return - V_9 ;
if ( ! F_3 ( V_10 ) )
return - V_11 ;
V_6 = V_5 -> V_7 -> V_8 ( V_3 ) ;
if ( V_6 )
F_4 ( V_10 ) ;
return V_6 ;
}
static void F_5 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_5 ;
if ( F_6 ( V_5 -> V_7 -> V_12 ) )
V_5 -> V_7 -> V_12 ( V_3 ) ;
F_4 ( V_10 ) ;
}
static long F_7 ( void * V_1 ,
unsigned int V_13 , unsigned long V_14 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_5 ;
if ( F_2 ( ! V_5 -> V_7 -> V_15 ) )
return - V_9 ;
return V_5 -> V_7 -> V_15 ( V_3 , V_13 , V_14 ) ;
}
static T_1 F_8 ( void * V_1 , char T_2 * V_16 ,
T_3 V_17 , T_4 * V_18 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_5 ;
if ( F_2 ( ! V_5 -> V_7 -> V_19 ) )
return - V_9 ;
return V_5 -> V_7 -> V_19 ( V_3 , V_16 , V_17 , V_18 ) ;
}
static T_1 F_9 ( void * V_1 , const char T_2 * V_16 ,
T_3 V_17 , T_4 * V_18 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_5 ;
if ( F_2 ( ! V_5 -> V_7 -> V_20 ) )
return - V_9 ;
return V_5 -> V_7 -> V_20 ( V_3 , V_16 , V_17 , V_18 ) ;
}
static int F_10 ( void * V_1 , struct V_21 * V_22 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_5 ;
if ( F_2 ( ! V_5 -> V_7 -> V_23 ) )
return - V_9 ;
return V_5 -> V_7 -> V_23 ( V_3 , V_22 ) ;
}
int F_11 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_12 ( V_25 ) ;
return F_13 ( V_25 , & V_26 , V_3 ) ;
}
void F_14 ( struct V_24 * V_25 )
{
F_15 ( V_25 ) ;
}
static int T_5 F_16 ( void )
{
return F_17 ( & V_27 , V_10 ) ;
}
static void T_6 F_18 ( void )
{
F_19 ( & V_27 ) ;
}
