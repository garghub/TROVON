static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
T_2 * V_5 = F_2 ( V_2 ) ;
if ( V_4 != sizeof( T_2 ) ) {
F_3 ( V_2 , V_6 ) ;
return - V_7 ;
}
* ( V_8 * ) V_5 = F_4 ( ( V_8 * ) V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
T_2 * V_5 = F_2 ( V_10 -> V_11 ) ;
T_2 * V_12 = F_6 ( V_10 ) ;
* V_12 = * V_5 ;
return 0 ;
}
static void F_7 ( T_2 * V_12 , const T_3 * V_13 , unsigned int V_14 )
{
unsigned int V_15 ;
V_15 = V_14 & ~ 7U ;
if ( V_15 ) {
F_8 ( V_12 , V_13 , V_15 ) ;
V_13 += V_15 / 8 ;
V_14 -= V_15 ;
}
if ( V_14 )
* V_12 = F_9 ( * V_12 , ( const unsigned char * ) V_13 , V_14 ) ;
}
static int F_10 ( struct V_9 * V_10 , const T_1 * V_13 ,
unsigned int V_14 )
{
T_2 * V_12 = F_6 ( V_10 ) ;
F_7 ( V_12 , ( const T_3 * ) V_13 , V_14 ) ;
return 0 ;
}
static int F_11 ( T_2 * V_12 , const T_1 * V_13 , unsigned int V_14 ,
T_1 * V_16 )
{
T_2 V_17 = * V_12 ;
F_7 ( & V_17 , ( const T_3 * ) V_13 , V_14 ) ;
* ( V_8 * ) V_16 = ~ F_12 ( V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 , const T_1 * V_13 ,
unsigned int V_14 , T_1 * V_16 )
{
return F_11 ( F_6 ( V_10 ) , V_13 , V_14 , V_16 ) ;
}
static int F_14 ( struct V_9 * V_10 , T_1 * V_16 )
{
T_2 * V_12 = F_6 ( V_10 ) ;
* ( V_8 * ) V_16 = ~ F_15 ( V_12 ) ;
return 0 ;
}
static int F_16 ( struct V_9 * V_10 , const T_1 * V_13 ,
unsigned int V_14 , T_1 * V_16 )
{
return F_11 ( F_2 ( V_10 -> V_11 ) , V_13 , V_14 ,
V_16 ) ;
}
static int F_17 ( struct V_18 * V_11 )
{
T_2 * V_3 = F_18 ( V_11 ) ;
* V_3 = ~ 0 ;
return 0 ;
}
static bool T_4 F_19 ( void )
{
unsigned long V_19 ;
if ( ! ( V_20 & V_21 ) )
return false ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if ( ! ( V_19 & V_22 ) )
return false ;
return true ;
}
static int T_4 F_20 ( void )
{
if ( F_19 () ) {
F_21 ( L_1 ) ;
return F_22 ( & V_23 ) ;
}
F_21 ( L_2 ) ;
return - V_24 ;
}
static void T_5 F_23 ( void )
{
F_24 ( & V_23 ) ;
}
