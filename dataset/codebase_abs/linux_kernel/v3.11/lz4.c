static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = F_3 ( V_6 ) ;
if ( ! V_4 -> V_5 )
return - V_7 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_4 -> V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , const T_1 * V_8 ,
unsigned int V_9 , T_1 * V_10 , unsigned int * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_12 = * V_11 ;
int V_13 ;
V_13 = F_7 ( V_8 , V_9 , V_10 , & V_12 , V_4 -> V_5 ) ;
if ( V_13 < 0 )
return - V_14 ;
* V_11 = V_12 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , const T_1 * V_8 ,
unsigned int V_9 , T_1 * V_10 , unsigned int * V_11 )
{
int V_13 ;
T_2 V_12 = * V_11 ;
T_2 V_15 = V_9 ;
V_13 = F_9 ( V_8 , & V_15 , V_10 , V_12 ) ;
if ( V_13 < 0 )
return - V_14 ;
* V_11 = V_12 ;
return V_13 ;
}
static int T_3 F_10 ( void )
{
return F_11 ( & V_16 ) ;
}
static void T_4 F_12 ( void )
{
F_13 ( & V_16 ) ;
}
