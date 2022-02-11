static bool F_1 ( int V_1 )
{
return V_1 != 0x10 && V_1 != 0x11 ;
}
static unsigned int F_2 ( int V_1 )
{
return V_1 + 0x40 ;
}
static int F_3 ( struct V_2 * V_3 , int V_1 , int V_4 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_8 V_9 [ 2 ] ;
T_1 V_10 [ 2 ] , V_11 = V_4 ;
int V_12 , V_13 ;
if ( ! F_1 ( V_1 ) )
return 0xffff ;
V_12 = F_2 ( V_1 ) ;
V_9 [ 0 ] . V_14 = V_12 ;
V_9 [ 0 ] . V_15 = 0 ;
V_9 [ 0 ] . V_16 = 1 ;
V_9 [ 0 ] . V_17 = & V_11 ;
V_9 [ 1 ] . V_14 = V_12 ;
V_9 [ 1 ] . V_15 = V_18 ;
V_9 [ 1 ] . V_16 = sizeof( V_10 ) ;
V_9 [ 1 ] . V_17 = V_10 ;
V_13 = F_4 ( V_6 , V_9 , F_5 ( V_9 ) ) ;
if ( V_13 != F_5 ( V_9 ) )
return 0xffff ;
return V_10 [ 0 ] << 8 | V_10 [ 1 ] ;
}
static int F_6 ( struct V_2 * V_3 , int V_1 , int V_4 , T_2 V_19 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_8 V_20 ;
int V_13 ;
T_1 V_10 [ 3 ] ;
if ( ! F_1 ( V_1 ) )
return 0 ;
V_10 [ 0 ] = V_4 ;
V_10 [ 1 ] = V_19 >> 8 ;
V_10 [ 2 ] = V_19 ;
V_20 . V_14 = F_2 ( V_1 ) ;
V_20 . V_15 = 0 ;
V_20 . V_16 = 3 ;
V_20 . V_17 = V_10 ;
V_13 = F_4 ( V_6 , & V_20 , 1 ) ;
return V_13 < 0 ? V_13 : 0 ;
}
struct V_2 * F_7 ( struct V_21 * V_22 , struct V_5 * V_6 )
{
struct V_2 * V_23 ;
if ( ! F_8 ( V_6 , V_24 ) )
return F_9 ( - V_25 ) ;
V_23 = F_10 () ;
if ( ! V_23 )
return F_9 ( - V_26 ) ;
snprintf ( V_23 -> V_27 , V_28 , L_1 , F_11 ( V_22 ) ) ;
V_23 -> V_22 = V_22 ;
V_23 -> V_29 = F_3 ;
V_23 -> V_30 = F_6 ;
V_23 -> V_7 = V_6 ;
return V_23 ;
}
