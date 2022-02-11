static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned short V_5 , V_6 ;
int V_7 , V_8 , V_9 , V_10 ;
V_5 = V_11 . V_5 ;
V_7 = V_5 & 0xff ;
V_8 = V_5 >> 8 ;
V_9 = V_7 - V_12 ;
V_10 = V_8 - V_13 ;
if ( V_9 < - 127 ) V_9 = ( 256 + V_7 ) - V_12 ;
if ( V_9 > 127 ) V_9 = ( V_7 - 256 ) - V_12 ;
if ( V_10 < - 127 ) V_10 = ( 256 + V_8 ) - V_13 ;
if ( V_10 > 127 ) V_10 = ( V_8 - 256 ) - V_13 ;
V_12 = V_7 ;
V_13 = V_8 ;
V_6 = V_11 . V_6 ;
F_2 ( V_4 , V_14 , V_9 ) ;
F_2 ( V_4 , V_15 , V_10 ) ;
F_3 ( V_4 , V_16 , V_17 . V_18 & 0x40 ) ;
F_3 ( V_4 , V_19 , V_6 & 0x0100 ) ;
F_3 ( V_4 , V_20 , V_6 & 0x0400 ) ;
F_4 ( V_4 ) ;
return V_21 ;
}
static int F_5 ( struct V_3 * V_4 )
{
unsigned short V_5 ;
int error ;
V_5 = V_11 . V_5 ;
V_12 = V_5 & 0xff ;
V_13 = V_5 >> 8 ;
error = F_6 ( V_22 , F_1 , 0 , L_1 ,
V_4 ) ;
if ( error )
F_7 ( & V_4 -> V_4 , L_2 , V_22 ) ;
return error ;
}
static void F_8 ( struct V_3 * V_4 )
{
F_9 ( V_22 , V_4 ) ;
}
static int T_2 F_10 ( struct V_23 * V_24 )
{
int V_25 ;
struct V_3 * V_4 ;
V_4 = F_11 () ;
if ( ! V_4 )
return - V_26 ;
V_4 -> V_27 = V_24 -> V_27 ;
V_4 -> V_28 = L_3 ;
V_4 -> V_29 . V_30 = V_31 ;
V_4 -> V_29 . V_32 = 0x0001 ;
V_4 -> V_29 . V_33 = 0x0002 ;
V_4 -> V_29 . V_34 = 0x0100 ;
V_4 -> V_35 [ 0 ] = F_12 ( V_36 ) | F_12 ( V_37 ) ;
V_4 -> V_38 [ 0 ] = F_12 ( V_14 ) | F_12 ( V_15 ) ;
V_4 -> V_39 [ F_13 ( V_16 ) ] = F_12 ( V_16 ) |
F_12 ( V_19 ) | F_12 ( V_20 ) ;
V_4 -> V_40 = F_5 ;
V_4 -> V_41 = F_8 ;
V_4 -> V_4 . V_42 = & V_24 -> V_4 ;
V_25 = F_14 ( V_4 ) ;
if ( V_25 ) {
F_15 ( V_4 ) ;
return V_25 ;
}
F_16 ( V_24 , V_4 ) ;
return 0 ;
}
static int T_3 F_17 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = F_18 ( V_24 ) ;
F_19 ( V_4 ) ;
return 0 ;
}
