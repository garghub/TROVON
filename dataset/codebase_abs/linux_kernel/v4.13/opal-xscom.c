static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
struct F_1 * V_5 ;
const T_3 * V_6 ;
if ( ! F_2 ( V_2 , L_1 , NULL ) ) {
F_3 ( L_2 ,
V_7 , V_2 -> V_8 ) ;
return V_9 ;
}
V_6 = F_2 ( V_2 , L_3 , NULL ) ;
if ( ! V_6 ) {
F_3 ( L_4 ,
V_7 , V_2 -> V_8 ) ;
return V_9 ;
}
V_5 = F_4 ( sizeof( struct F_1 ) , V_10 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_11 = F_5 ( V_6 ) ;
V_5 -> V_12 = V_3 ;
return ( T_1 ) V_5 ;
}
static void F_6 ( T_1 V_13 )
{
F_7 ( V_13 ) ;
}
static int F_8 ( T_4 V_14 )
{
switch( V_14 ) {
case 0 :
return 0 ;
default:
return - V_15 ;
}
}
static T_2 F_9 ( T_2 V_12 )
{
T_2 V_16 ;
V_16 = V_12 ;
V_16 &= 0x0f00000000000000 ;
V_12 &= 0xf0ffffffffffffff ;
V_12 |= V_16 << 4 ;
return V_12 ;
}
static int F_10 ( T_1 V_13 , T_2 V_3 , T_2 * V_17 )
{
struct F_1 * V_5 = V_13 ;
T_4 V_14 ;
T_5 V_18 ;
V_3 = F_9 ( V_5 -> V_12 + V_3 ) ;
V_14 = F_11 ( V_5 -> V_11 , V_3 , ( T_5 * ) F_12 ( & V_18 ) ) ;
* V_17 = F_13 ( V_18 ) ;
return F_8 ( V_14 ) ;
}
static int F_14 ( T_1 V_13 , T_2 V_3 , T_2 V_17 )
{
struct F_1 * V_5 = V_13 ;
T_4 V_14 ;
V_3 = F_9 ( V_5 -> V_12 + V_3 ) ;
V_14 = F_15 ( V_5 -> V_11 , V_3 , V_17 ) ;
return F_8 ( V_14 ) ;
}
static int F_16 ( void )
{
if ( F_17 ( V_19 ) )
F_18 ( & V_20 ) ;
return 0 ;
}
