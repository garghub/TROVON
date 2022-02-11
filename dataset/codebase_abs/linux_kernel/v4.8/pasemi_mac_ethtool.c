static T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static void
F_3 ( struct V_1 * V_2 ,
T_1 V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = V_6 ;
}
static void
F_4 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_8 -> V_9 = V_10 / 2 ;
V_8 -> V_11 = F_5 ( V_4 -> V_12 ) / 2 ;
V_8 -> V_13 = V_14 / 4 ;
V_8 -> V_15 = F_5 ( V_4 -> V_16 ) / 4 ;
}
static int F_6 ( struct V_1 * V_2 , int V_17 )
{
switch ( V_17 ) {
case V_18 :
return F_7 ( V_19 ) ;
default:
return - V_20 ;
}
}
static void F_8 ( struct V_1 * V_2 ,
struct V_21 * V_22 , T_2 * V_23 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_24 ;
V_23 [ 0 ] = F_9 ( F_10 ( V_4 -> V_25 ) )
>> V_26 ;
for ( V_24 = 0 ; V_24 < 32 ; V_24 ++ )
V_23 [ 1 + V_24 ] = F_11 ( V_4 -> V_25 , F_12 ( V_24 ) ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_27 ,
T_3 * V_23 )
{
memcpy ( V_23 , V_19 , sizeof( V_19 ) ) ;
}
