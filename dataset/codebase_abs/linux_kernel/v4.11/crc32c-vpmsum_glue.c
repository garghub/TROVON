static T_1 F_1 ( T_1 V_1 , unsigned char const * V_2 , T_2 V_3 )
{
unsigned int V_4 ;
unsigned int V_5 ;
if ( V_3 < ( V_6 + V_7 ) || F_2 () )
return F_3 ( V_1 , V_2 , V_3 ) ;
if ( ( unsigned long ) V_2 & V_8 ) {
V_4 = V_7 - ( ( unsigned long ) V_2 & V_8 ) ;
V_1 = F_3 ( V_1 , V_2 , V_4 ) ;
V_3 -= V_4 ;
V_2 += V_4 ;
}
if ( V_3 & ~ V_8 ) {
F_4 () ;
F_5 () ;
F_6 () ;
V_1 = F_7 ( V_1 , V_2 , V_3 & ~ V_8 ) ;
F_8 () ;
F_9 () ;
F_10 () ;
}
V_5 = V_3 & V_8 ;
if ( V_5 ) {
V_2 += V_3 & ~ V_8 ;
V_1 = F_3 ( V_1 , V_2 , V_5 ) ;
}
return V_1 ;
}
static int F_11 ( struct V_9 * V_10 )
{
T_1 * V_11 = F_12 ( V_10 ) ;
* V_11 = ~ 0 ;
return 0 ;
}
static int F_13 ( struct V_12 * V_13 , const T_3 * V_11 ,
unsigned int V_14 )
{
T_1 * V_15 = F_14 ( V_13 ) ;
if ( V_14 != sizeof( T_1 ) ) {
F_15 ( V_13 , V_16 ) ;
return - V_17 ;
}
* V_15 = F_16 ( ( V_18 * ) V_11 ) ;
return 0 ;
}
static int F_17 ( struct V_19 * V_20 )
{
T_1 * V_15 = F_14 ( V_20 -> V_10 ) ;
T_1 * V_21 = F_18 ( V_20 ) ;
* V_21 = * V_15 ;
return 0 ;
}
static int F_19 ( struct V_19 * V_20 , const T_3 * V_22 ,
unsigned int V_3 )
{
T_1 * V_21 = F_18 ( V_20 ) ;
* V_21 = F_1 ( * V_21 , V_22 , V_3 ) ;
return 0 ;
}
static int F_20 ( T_1 * V_21 , const T_3 * V_22 , unsigned int V_3 ,
T_3 * V_23 )
{
* ( V_18 * ) V_23 = ~ F_21 ( F_1 ( * V_21 , V_22 , V_3 ) ) ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 , const T_3 * V_22 ,
unsigned int V_3 , T_3 * V_23 )
{
return F_20 ( F_18 ( V_20 ) , V_22 , V_3 , V_23 ) ;
}
static int F_23 ( struct V_19 * V_20 , T_3 * V_23 )
{
T_1 * V_21 = F_18 ( V_20 ) ;
* ( V_18 * ) V_23 = ~ F_24 ( V_21 ) ;
return 0 ;
}
static int F_25 ( struct V_19 * V_20 , const T_3 * V_22 ,
unsigned int V_3 , T_3 * V_23 )
{
return F_20 ( F_14 ( V_20 -> V_10 ) , V_22 , V_3 ,
V_23 ) ;
}
static int T_4 F_26 ( void )
{
if ( ! F_27 ( V_24 ) )
return - V_25 ;
return F_28 ( & V_26 ) ;
}
static void T_5 F_29 ( void )
{
F_30 ( & V_26 ) ;
}
