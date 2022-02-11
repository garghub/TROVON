static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = F_3 ( V_6 ,
V_7 | V_8 ) ;
if ( ! V_4 -> V_5 )
V_4 -> V_5 = F_4 ( V_6 ) ;
if ( ! V_4 -> V_5 )
return - V_9 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_6 ( V_4 -> V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 , const T_1 * V_10 ,
unsigned int V_11 , T_1 * V_12 , unsigned int * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_14 = * V_13 ;
int V_15 ;
V_15 = F_8 ( V_10 , V_11 , V_12 , & V_14 , V_4 -> V_5 ) ;
if ( V_15 != V_16 )
return - V_17 ;
* V_13 = V_14 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , const T_1 * V_10 ,
unsigned int V_11 , T_1 * V_12 , unsigned int * V_13 )
{
int V_15 ;
T_2 V_14 = * V_13 ;
V_15 = F_10 ( V_10 , V_11 , V_12 , & V_14 ) ;
if ( V_15 != V_16 )
return - V_17 ;
* V_13 = V_14 ;
return 0 ;
}
static int T_3 F_11 ( void )
{
return F_12 ( & V_18 ) ;
}
static void T_4 F_13 ( void )
{
F_14 ( & V_18 ) ;
}
