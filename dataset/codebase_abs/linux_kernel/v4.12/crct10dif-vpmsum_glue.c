static T_1 F_1 ( T_1 V_1 , unsigned char const * V_2 , T_2 V_3 )
{
unsigned int V_4 ;
unsigned int V_5 ;
T_3 V_6 = V_1 ;
if ( V_3 < ( V_7 + V_8 ) || F_2 () )
return F_3 ( V_6 , V_2 , V_3 ) ;
if ( ( unsigned long ) V_2 & V_9 ) {
V_4 = V_8 - ( ( unsigned long ) V_2 & V_9 ) ;
V_6 = F_3 ( V_6 , V_2 , V_4 ) ;
V_3 -= V_4 ;
V_2 += V_4 ;
}
if ( V_3 & ~ V_9 ) {
V_6 <<= 16 ;
F_4 () ;
F_5 () ;
F_6 () ;
V_6 = F_7 ( V_6 , V_2 , V_3 & ~ V_9 ) ;
F_8 () ;
F_9 () ;
F_10 () ;
V_6 >>= 16 ;
}
V_5 = V_3 & V_9 ;
if ( V_5 ) {
V_2 += V_3 & ~ V_9 ;
V_6 = F_3 ( V_6 , V_2 , V_5 ) ;
}
return V_6 & 0xffff ;
}
static int F_11 ( struct V_10 * V_11 )
{
T_1 * V_6 = F_12 ( V_11 ) ;
* V_6 = 0 ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 , const T_4 * V_12 ,
unsigned int V_13 )
{
T_1 * V_6 = F_12 ( V_11 ) ;
* V_6 = F_1 ( * V_6 , V_12 , V_13 ) ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 , T_4 * V_14 )
{
T_1 * V_15 = F_12 ( V_11 ) ;
* ( T_1 * ) V_14 = * V_15 ;
return 0 ;
}
static int T_5 F_15 ( void )
{
if ( ! F_16 ( V_16 ) )
return - V_17 ;
return F_17 ( & V_18 ) ;
}
static void T_6 F_18 ( void )
{
F_19 ( & V_18 ) ;
}
