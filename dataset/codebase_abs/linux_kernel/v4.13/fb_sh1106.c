static int F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 -> V_4 . V_5 || V_2 -> V_3 -> V_4 . V_5 > V_6 ||
! V_2 -> V_3 -> V_4 . V_7 || V_2 -> V_3 -> V_4 . V_7 > V_8 ||
V_2 -> V_3 -> V_4 . V_7 % 8 ) {
F_2 ( V_2 -> V_3 -> V_9 , L_1 ) ;
return - V_10 ;
}
if ( V_2 -> V_3 -> V_4 . V_11 ) {
F_2 ( V_2 -> V_3 -> V_9 , L_2 ) ;
return - V_10 ;
}
V_2 -> V_12 . V_13 ( V_2 ) ;
F_3 ( V_2 , 0xAE ) ;
F_3 ( V_2 , 0xD5 , 0x80 ) ;
F_3 ( V_2 , 0xA8 , V_2 -> V_3 -> V_4 . V_7 - 1 ) ;
F_3 ( V_2 , 0xD3 , 0x00 ) ;
F_3 ( V_2 , 0x40 | 0x0 ) ;
F_3 ( V_2 , 0xA0 | 0x1 ) ;
F_3 ( V_2 , 0xC8 ) ;
if ( V_2 -> V_3 -> V_4 . V_7 == 64 )
F_3 ( V_2 , 0xDA , 0x12 ) ;
else if ( V_2 -> V_3 -> V_4 . V_7 == 48 )
F_3 ( V_2 , 0xDA , 0x12 ) ;
else
F_3 ( V_2 , 0xDA , 0x02 ) ;
F_3 ( V_2 , 0xD9 , 0xF1 ) ;
F_3 ( V_2 , 0xDB , 0x40 ) ;
F_3 ( V_2 , 0xAF ) ;
F_4 ( 150 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , int V_14 , int V_15 , int V_16 , int V_17 )
{
}
static int F_6 ( struct V_1 * V_2 , bool V_18 )
{
F_7 ( V_19 , V_2 , L_3 ,
V_20 , V_18 ? L_4 : L_5 ) ;
F_3 ( V_2 , V_18 ? 0xAE : 0xAF ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 * V_21 )
{
V_21 [ 0 ] &= 0xFF ;
F_3 ( V_2 , 0x81 , V_21 [ 0 ] ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_22 , T_2 V_23 )
{
T_3 * V_24 = ( T_3 * ) V_2 -> V_3 -> V_25 ;
T_1 V_5 = V_2 -> V_3 -> V_4 . V_5 ;
int V_26 , V_27 , V_28 , V_29 , V_30 , V_31 ;
T_4 * V_32 = V_2 -> V_33 . V_32 ;
V_27 = V_22 / ( 8 * 2 * V_5 ) ;
V_28 = F_10 ( V_22 + V_23 , 8 * 2 * V_5 ) ;
for ( V_26 = V_27 ; V_26 < V_28 ; V_26 ++ ) {
F_3 ( V_2 , 0xb0 | V_26 , 0x00 | 2 , 0x10 | 0 ) ;
memset ( V_32 , 0 , V_5 ) ;
for ( V_29 = 0 ; V_29 < V_5 ; V_29 ++ )
for ( V_30 = 0 ; V_30 < 8 ; V_30 ++ )
if ( V_24 [ ( V_26 * 8 + V_30 ) * V_5 + V_29 ] )
V_32 [ V_29 ] |= F_11 ( V_30 ) ;
V_31 = F_12 ( V_2 , V_32 , V_5 , 1 ) ;
if ( V_31 < 0 )
return V_31 ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_2 , int V_23 , ... )
{
T_5 args ;
int V_30 ;
va_start ( args , V_23 ) ;
for ( V_30 = 0 ; V_30 < V_23 ; V_30 ++ )
V_2 -> V_32 [ V_30 ] = va_arg (args, unsigned int) ;
F_12 ( V_2 , V_2 -> V_32 , V_23 , 0 ) ;
va_end ( args ) ;
}
