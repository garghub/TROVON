static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 [ 0 ] = V_4 -> V_5 [ 1 ] ;
V_4 -> V_6 = 1 ;
return 1 ;
}
static int F_2 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
V_10 = F_3 ( sizeof( * V_10 ) , V_11 ) ;
if ( ! V_10 )
return - V_12 ;
F_4 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
V_10 = F_6 ( V_8 ) ;
F_7 ( V_10 ) ;
return 0 ;
}
static void F_8 ( struct V_13 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_14 ;
const struct V_15 * V_16 = V_13 -> V_17 ;
const unsigned char * V_18 ;
T_1 V_19 ;
if ( V_13 -> V_20 <= V_21 || ! V_16 -> V_22 )
return;
V_18 = ( char * ) V_13 -> V_17 + V_21 ;
V_19 = F_9 ( T_1 , V_13 -> V_20 - V_21 ,
V_16 -> V_22 ) ;
F_10 ( & V_8 -> V_8 , V_18 , V_19 ) ;
F_11 ( & V_8 -> V_8 ) ;
}
static int F_12 ( struct V_7 * V_8 ,
void * V_23 , T_1 V_24 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
struct V_15 * V_25 = V_23 ;
V_24 = F_9 ( T_1 , V_24 , V_26 ) ;
V_24 = F_13 ( & V_8 -> V_27 , V_23 + V_21 ,
V_24 , & V_8 -> V_28 ) ;
V_25 -> V_29 = V_10 -> V_30 ++ ;
V_25 -> V_22 = V_24 ;
V_25 -> V_31 = 0x03 ;
V_25 -> V_32 = 0x00 ;
return V_33 ;
}
