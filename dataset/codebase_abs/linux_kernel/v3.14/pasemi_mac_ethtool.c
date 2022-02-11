static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 )
return - V_9 ;
return F_3 ( V_8 , V_4 ) ;
}
static int
F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 )
return - V_9 ;
return F_5 ( V_8 , V_4 ) ;
}
static T_1
F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_10 ;
}
static void
F_7 ( struct V_1 * V_2 ,
T_1 V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_10 = V_11 ;
}
static void
F_8 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_13 -> V_14 = V_15 / 2 ;
V_13 -> V_16 = F_9 ( V_6 -> V_17 ) / 2 ;
V_13 -> V_18 = V_19 / 4 ;
V_13 -> V_20 = F_9 ( V_6 -> V_21 ) / 4 ;
}
static int F_10 ( struct V_1 * V_2 , int V_22 )
{
switch ( V_22 ) {
case V_23 :
return F_11 ( V_24 ) ;
default:
return - V_9 ;
}
}
static void F_12 ( struct V_1 * V_2 ,
struct V_25 * V_26 , T_2 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_28 ;
V_27 [ 0 ] = F_13 ( F_14 ( V_6 -> V_29 ) )
>> V_30 ;
for ( V_28 = 0 ; V_28 < 32 ; V_28 ++ )
V_27 [ 1 + V_28 ] = F_15 ( V_6 -> V_29 , F_16 ( V_28 ) ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_31 ,
T_3 * V_27 )
{
memcpy ( V_27 , V_24 , sizeof( V_24 ) ) ;
}
