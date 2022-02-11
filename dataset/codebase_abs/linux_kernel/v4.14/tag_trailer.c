static struct V_1 * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_7 ;
int V_8 ;
T_1 * V_9 ;
V_8 = 0 ;
if ( V_2 -> V_10 < 60 )
V_8 = 60 - V_2 -> V_10 ;
V_7 = F_3 ( V_11 + V_2 -> V_10 + V_8 + 4 , V_12 ) ;
if ( ! V_7 )
return NULL ;
F_4 ( V_7 , V_11 ) ;
F_5 ( V_7 ) ;
F_6 ( V_7 , F_7 ( V_2 ) - V_2 -> V_13 ) ;
F_8 ( V_7 , F_9 ( V_2 ) - V_2 -> V_13 ) ;
F_10 ( V_2 , F_11 ( V_7 , V_2 -> V_10 ) ) ;
F_12 ( V_2 ) ;
if ( V_8 ) {
F_13 ( V_7 , V_8 ) ;
}
V_9 = F_11 ( V_7 , 4 ) ;
V_9 [ 0 ] = 0x80 ;
V_9 [ 1 ] = 1 << V_6 -> V_14 -> V_15 ;
V_9 [ 2 ] = 0x10 ;
V_9 [ 3 ] = 0x00 ;
return V_7 ;
}
static struct V_1 * F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_4 -> V_20 ;
struct V_21 * V_22 = F_15 ( V_19 ) ;
struct V_23 * V_24 = V_22 -> V_24 ;
T_1 * V_9 ;
int V_25 ;
if ( F_16 ( V_2 ) )
return NULL ;
V_9 = F_17 ( V_2 ) - 4 ;
if ( V_9 [ 0 ] != 0x80 || ( V_9 [ 1 ] & 0xf8 ) != 0x00 ||
( V_9 [ 2 ] & 0xef ) != 0x00 || V_9 [ 3 ] != 0x00 )
return NULL ;
V_25 = V_9 [ 1 ] & 7 ;
if ( V_25 >= V_24 -> V_26 || ! V_24 -> V_27 [ V_25 ] . V_28 )
return NULL ;
F_18 ( V_2 , V_2 -> V_10 - 4 ) ;
V_2 -> V_4 = V_24 -> V_27 [ V_25 ] . V_28 ;
return V_2 ;
}
