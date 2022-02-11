static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = F_3 ( V_6 ,
V_7 | V_8 | V_9 ) ;
if ( ! V_4 -> V_5 )
V_4 -> V_5 = F_4 ( V_6 ) ;
if ( ! V_4 -> V_5 )
return - V_10 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_6 ( V_4 -> V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 , const T_1 * V_11 ,
unsigned int V_12 , T_1 * V_13 , unsigned int * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_15 = * V_14 ;
int V_16 ;
V_16 = F_8 ( V_11 , V_12 , V_13 , & V_15 , V_4 -> V_5 ) ;
if ( V_16 != V_17 )
return - V_18 ;
* V_14 = V_15 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , const T_1 * V_11 ,
unsigned int V_12 , T_1 * V_13 , unsigned int * V_14 )
{
int V_16 ;
T_2 V_15 = * V_14 ;
V_16 = F_10 ( V_11 , V_12 , V_13 , & V_15 ) ;
if ( V_16 != V_17 )
return - V_18 ;
* V_14 = V_15 ;
return 0 ;
}
static int T_3 F_11 ( void )
{
return F_12 ( & V_19 ) ;
}
static void T_4 F_13 ( void )
{
F_14 ( & V_19 ) ;
}
