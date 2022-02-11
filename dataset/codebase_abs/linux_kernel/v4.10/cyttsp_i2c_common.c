int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_4 , T_1 V_5 , void * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 = V_8 -> V_4 | ( ( V_4 >> 8 ) & 0x1 ) ;
T_1 V_10 = V_4 & 0xFF ;
struct V_11 V_12 [] = {
{
. V_4 = V_9 ,
. V_13 = 0 ,
. V_14 = 1 ,
. V_15 = & V_10 ,
} ,
{
. V_4 = V_9 ,
. V_13 = V_16 ,
. V_14 = V_5 ,
. V_15 = V_6 ,
} ,
} ;
int V_17 ;
V_17 = F_3 ( V_8 -> V_18 , V_12 , F_4 ( V_12 ) ) ;
if ( V_17 < 0 )
return V_17 ;
return V_17 != F_4 ( V_12 ) ? - V_19 : 0 ;
}
int F_5 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_4 , T_1 V_5 , const void * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 = V_8 -> V_4 | ( ( V_4 >> 8 ) & 0x1 ) ;
T_1 V_10 = V_4 & 0xFF ;
struct V_11 V_12 [] = {
{
. V_4 = V_9 ,
. V_13 = 0 ,
. V_14 = V_5 + 1 ,
. V_15 = V_3 ,
} ,
} ;
int V_17 ;
V_3 [ 0 ] = V_10 ;
memcpy ( & V_3 [ 1 ] , V_6 , V_5 ) ;
V_17 = F_3 ( V_8 -> V_18 , V_12 , F_4 ( V_12 ) ) ;
if ( V_17 < 0 )
return V_17 ;
return V_17 != F_4 ( V_12 ) ? - V_19 : 0 ;
}
