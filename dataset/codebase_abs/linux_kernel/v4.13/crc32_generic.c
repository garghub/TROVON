static T_1 F_1 ( T_1 V_1 , unsigned char const * V_2 , T_2 V_3 )
{
return F_2 ( V_1 , V_2 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
T_1 * V_6 = F_4 ( V_5 ) ;
* V_6 = 0 ;
return 0 ;
}
static int F_5 ( struct V_7 * V_8 , const T_3 * V_6 ,
unsigned int V_9 )
{
T_1 * V_10 = F_6 ( V_8 ) ;
if ( V_9 != sizeof( T_1 ) ) {
F_7 ( V_8 , V_11 ) ;
return - V_12 ;
}
* V_10 = F_8 ( ( V_13 * ) V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 )
{
T_1 * V_10 = F_6 ( V_15 -> V_5 ) ;
T_1 * V_16 = F_10 ( V_15 ) ;
* V_16 = * V_10 ;
return 0 ;
}
static int F_11 ( struct V_14 * V_15 , const T_3 * V_17 ,
unsigned int V_3 )
{
T_1 * V_16 = F_10 ( V_15 ) ;
* V_16 = F_1 ( * V_16 , V_17 , V_3 ) ;
return 0 ;
}
static int F_12 ( T_1 * V_16 , const T_3 * V_17 , unsigned int V_3 ,
T_3 * V_18 )
{
* ( V_13 * ) V_18 = F_13 ( F_1 ( * V_16 , V_17 , V_3 ) ) ;
return 0 ;
}
static int F_14 ( struct V_14 * V_15 , const T_3 * V_17 ,
unsigned int V_3 , T_3 * V_18 )
{
return F_12 ( F_10 ( V_15 ) , V_17 , V_3 , V_18 ) ;
}
static int F_15 ( struct V_14 * V_15 , T_3 * V_18 )
{
T_1 * V_16 = F_10 ( V_15 ) ;
* ( V_13 * ) V_18 = F_16 ( V_16 ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 , const T_3 * V_17 ,
unsigned int V_3 , T_3 * V_18 )
{
return F_12 ( F_6 ( V_15 -> V_5 ) , V_17 , V_3 ,
V_18 ) ;
}
static int T_4 F_18 ( void )
{
return F_19 ( & V_19 ) ;
}
static void T_5 F_20 ( void )
{
F_21 ( & V_19 ) ;
}
