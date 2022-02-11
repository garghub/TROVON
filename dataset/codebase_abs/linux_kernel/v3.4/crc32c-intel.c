static T_1 F_1 ( T_1 V_1 , unsigned char const * V_2 , T_2 V_3 )
{
while ( V_3 -- ) {
__asm__ __volatile__(
".byte 0xf2, 0xf, 0x38, 0xf0, 0xf1"
:"=S"(crc)
:"0"(crc), "c"(*data)
);
V_2 ++ ;
}
return V_1 ;
}
static T_1 T_3 F_2 ( T_1 V_1 , unsigned char const * V_4 , T_2 V_5 )
{
unsigned int V_6 = V_5 / V_7 ;
unsigned int V_8 = V_5 % V_7 ;
unsigned long * V_9 = ( unsigned long * ) V_4 ;
while ( V_6 -- ) {
__asm__ __volatile__(
".byte 0xf2, " REX_PRE "0xf, 0x38, 0xf1, 0xf1;"
:"=S"(crc)
:"0"(crc), "c"(*ptmp)
);
V_9 ++ ;
}
if ( V_8 )
V_1 = F_1 ( V_1 , ( unsigned char * ) V_9 ,
V_8 ) ;
return V_1 ;
}
static int F_3 ( struct V_10 * V_11 , const T_4 * V_12 ,
unsigned int V_13 )
{
T_1 * V_14 = F_4 ( V_11 ) ;
if ( V_13 != sizeof( T_1 ) ) {
F_5 ( V_11 , V_15 ) ;
return - V_16 ;
}
* V_14 = F_6 ( ( V_17 * ) V_12 ) ;
return 0 ;
}
static int F_7 ( struct V_18 * V_19 )
{
T_1 * V_14 = F_4 ( V_19 -> V_20 ) ;
T_1 * V_21 = F_8 ( V_19 ) ;
* V_21 = * V_14 ;
return 0 ;
}
static int F_9 ( struct V_18 * V_19 , const T_4 * V_2 ,
unsigned int V_5 )
{
T_1 * V_21 = F_8 ( V_19 ) ;
* V_21 = F_2 ( * V_21 , V_2 , V_5 ) ;
return 0 ;
}
static int F_10 ( T_1 * V_21 , const T_4 * V_2 , unsigned int V_5 ,
T_4 * V_22 )
{
* ( V_17 * ) V_22 = ~ F_11 ( F_2 ( * V_21 , V_2 , V_5 ) ) ;
return 0 ;
}
static int F_12 ( struct V_18 * V_19 , const T_4 * V_2 ,
unsigned int V_5 , T_4 * V_22 )
{
return F_10 ( F_8 ( V_19 ) , V_2 , V_5 , V_22 ) ;
}
static int F_13 ( struct V_18 * V_19 , T_4 * V_22 )
{
T_1 * V_21 = F_8 ( V_19 ) ;
* ( V_17 * ) V_22 = ~ F_14 ( V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_18 * V_19 , const T_4 * V_2 ,
unsigned int V_5 , T_4 * V_22 )
{
return F_10 ( F_4 ( V_19 -> V_20 ) , V_2 , V_5 ,
V_22 ) ;
}
static int F_16 ( struct V_23 * V_20 )
{
T_1 * V_12 = F_17 ( V_20 ) ;
* V_12 = ~ 0 ;
return 0 ;
}
static int T_5 F_18 ( void )
{
if ( ! F_19 ( V_24 ) )
return - V_25 ;
return F_20 ( & V_26 ) ;
}
static void T_6 F_21 ( void )
{
F_22 ( & V_26 ) ;
}
