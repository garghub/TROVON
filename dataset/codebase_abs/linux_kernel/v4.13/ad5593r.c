static int F_1 ( struct V_1 * V_2 , unsigned V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
return F_3 ( V_6 ,
V_8 | V_3 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
T_2 V_9 ;
V_9 = F_3 ( V_6 ,
V_10 | V_11 , F_5 ( V_3 ) ) ;
if ( V_9 < 0 )
return ( int ) V_9 ;
V_9 = F_6 ( V_6 , V_12 ) ;
if ( V_9 < 0 )
return ( int ) V_9 ;
* V_4 = ( T_1 ) V_9 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_3 V_13 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
return F_3 ( V_6 ,
V_10 | V_13 , V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_3 V_13 , T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
T_2 V_9 ;
V_9 = F_6 ( V_6 , V_14 | V_13 ) ;
if ( V_9 < 0 )
return ( int ) V_9 ;
* V_4 = ( T_1 ) V_9 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
T_2 V_9 ;
V_9 = F_6 ( V_6 , V_15 ) ;
if ( V_9 < 0 )
return ( int ) V_9 ;
* V_4 = ( T_3 ) V_9 ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 ,
const struct V_16 * V_17 )
{
return F_11 ( & V_6 -> V_7 , V_17 -> V_18 , & V_19 ) ;
}
static int F_12 ( struct V_5 * V_6 )
{
return F_13 ( & V_6 -> V_7 ) ;
}
