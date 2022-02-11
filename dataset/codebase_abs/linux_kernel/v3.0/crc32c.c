static T_1 F_1 ( T_1 V_1 , const T_2 * V_2 , unsigned int V_3 )
{
while ( V_3 -- )
V_1 = V_4 [ ( V_1 ^ * V_2 ++ ) & 0xFFL ] ^ ( V_1 >> 8 ) ;
return V_1 ;
}
static int F_2 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 -> V_9 ) ;
struct V_10 * V_11 = F_4 ( V_6 ) ;
V_11 -> V_1 = V_8 -> V_12 ;
return 0 ;
}
static int F_5 ( struct V_13 * V_9 , const T_2 * V_12 ,
unsigned int V_14 )
{
struct V_7 * V_8 = F_3 ( V_9 ) ;
if ( V_14 != sizeof( V_8 -> V_12 ) ) {
F_6 ( V_9 , V_15 ) ;
return - V_16 ;
}
V_8 -> V_12 = F_7 ( * ( V_17 * ) V_12 ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 , const T_2 * V_2 ,
unsigned int V_3 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
V_11 -> V_1 = F_1 ( V_11 -> V_1 , V_2 , V_3 ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , T_2 * V_18 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
* ( V_17 * ) V_18 = ~ F_10 ( & V_11 -> V_1 ) ;
return 0 ;
}
static int F_11 ( T_1 * V_19 , const T_2 * V_2 , unsigned int V_20 , T_2 * V_18 )
{
* ( V_17 * ) V_18 = ~ F_12 ( F_1 ( * V_19 , V_2 , V_20 ) ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 , const T_2 * V_2 ,
unsigned int V_20 , T_2 * V_18 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
return F_11 ( & V_11 -> V_1 , V_2 , V_20 , V_18 ) ;
}
static int F_14 ( struct V_5 * V_6 , const T_2 * V_2 ,
unsigned int V_3 , T_2 * V_18 )
{
struct V_7 * V_8 = F_3 ( V_6 -> V_9 ) ;
return F_11 ( & V_8 -> V_12 , V_2 , V_3 , V_18 ) ;
}
static int F_15 ( struct V_21 * V_9 )
{
struct V_7 * V_8 = F_16 ( V_9 ) ;
V_8 -> V_12 = ~ 0 ;
return 0 ;
}
static int T_3 F_17 ( void )
{
return F_18 ( & V_22 ) ;
}
static void T_4 F_19 ( void )
{
F_20 ( & V_22 ) ;
}
