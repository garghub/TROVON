static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = 0 ;
T_2 V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
if ( V_3 & ( V_8 & ~ V_9 ) ) {
V_5 = 0x02 ;
F_3 ( 1 , V_10 , V_2 , L_1 ) ;
} else {
V_5 = 0x00 ;
F_3 ( 1 , V_10 , V_2 , L_2 ) ;
}
V_4 |= F_4 ( V_7 , 0x01 , V_5 ) ;
V_4 |= F_4 ( V_7 , 0x02 , V_5 ) ;
V_4 |= F_4 ( V_7 , 0x03 , V_5 ) ;
if ( V_4 )
F_5 ( V_2 , L_3 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_11 )
{
return F_1 ( V_2 , V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_8 ( V_7 , V_13 , V_14 , 0 ) ;
}
static int F_9 ( struct V_6 * V_7 ,
const struct V_15 * V_16 )
{
struct V_1 * V_2 ;
T_1 V_17 = V_18 ;
if ( ! F_10 ( V_7 -> V_19 , V_20 ) )
return - V_21 ;
F_11 ( V_7 , L_4 ,
V_7 -> V_22 << 1 , V_7 -> V_19 -> V_23 ) ;
V_2 = F_12 ( sizeof( struct V_1 ) , V_24 ) ;
if ( V_2 == NULL )
return - V_25 ;
F_13 ( V_2 , V_7 , & V_26 ) ;
return F_1 ( V_2 , V_17 ) ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_15 ( V_7 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
