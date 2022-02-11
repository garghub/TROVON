static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = 0 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = ~ 0 ;
return 0 ;
}
static int F_4 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_5 ( V_7 -> V_2 ) ;
struct V_8 * V_9 = F_6 ( V_7 ) ;
V_9 -> V_10 = V_4 -> V_5 ;
return 0 ;
}
static int F_7 ( struct V_11 * V_2 , const T_1 * V_12 ,
unsigned int V_13 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
if ( V_13 != sizeof( V_4 -> V_5 ) ) {
F_8 ( V_2 , V_14 ) ;
return - V_15 ;
}
V_4 -> V_5 = F_9 ( * ( V_16 * ) V_12 ) ;
return 0 ;
}
static int F_10 ( struct V_11 * V_2 , const T_1 * V_12 ,
unsigned int V_13 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
if ( V_13 != sizeof( V_4 -> V_5 ) ) {
F_8 ( V_2 , V_14 ) ;
return - V_15 ;
}
V_4 -> V_5 = F_11 ( * ( V_17 * ) V_12 ) ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 , T_1 * V_18 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
* ( V_16 * ) V_18 = F_13 ( & V_9 -> V_10 ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 , T_1 * V_18 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
* ( V_17 * ) V_18 = F_15 ( & V_9 -> V_10 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , T_1 * V_18 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
* ( V_16 * ) V_18 = ~ F_13 ( & V_9 -> V_10 ) ;
return 0 ;
}
static int F_17 ( T_2 * V_10 , const T_1 * V_19 , unsigned int V_20 ,
T_1 * V_18 )
{
* ( V_16 * ) V_18 = F_18 ( F_19 ( * V_10 , V_19 , V_20 ) ) ;
return 0 ;
}
static int F_20 ( T_2 * V_10 , const T_1 * V_19 , unsigned int V_20 ,
T_1 * V_18 )
{
* ( V_17 * ) V_18 = F_21 ( F_22 ( * V_10 , V_19 , V_20 ) ) ;
return 0 ;
}
static int F_23 ( T_2 * V_10 , const T_1 * V_19 , unsigned int V_20 ,
T_1 * V_18 )
{
* ( V_16 * ) V_18 = ~ F_18 ( F_24 ( * V_10 , V_19 , V_20 ) ) ;
return 0 ;
}
static int T_3 F_25 ( void )
{
return F_26 ( V_21 ,
F_27 ( V_21 ) ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( V_21 , F_27 ( V_21 ) ) ;
}
