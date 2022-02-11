void T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
T_2 V_7 ;
int V_8 , V_9 ;
if ( ! ( V_2 -> V_10 . V_11 & V_12 ) )
return;
V_7 = F_2 ( V_13 ) ;
V_8 = ( V_7 >> 12 ) & 0xf ;
V_9 = ( V_7 >> 20 ) & 0xf ;
F_3 ( V_4 -> V_14 , V_15 , V_8 ) ;
F_3 ( V_4 -> V_16 , V_17 , V_8 ) ;
F_3 ( V_4 -> V_18 , V_19 , V_9 ) ;
F_3 ( V_4 -> V_20 , V_21 , V_9 ) ;
V_6 -> V_22 [ V_23 ] = F_2 ( V_24 ) ;
}
void T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
T_2 V_7 ;
int V_8 , V_9 ;
if ( ! ( V_2 -> V_10 . V_11 & V_12 ) )
return;
V_7 = F_2 ( V_13 ) ;
V_8 = ( V_7 >> 12 ) & 0xf ;
V_9 = ( V_7 >> 20 ) & 0xf ;
F_5 ( V_4 -> V_14 , V_15 , V_8 ) ;
F_5 ( V_4 -> V_16 , V_17 , V_8 ) ;
F_5 ( V_4 -> V_18 , V_19 , V_9 ) ;
F_5 ( V_4 -> V_20 , V_21 , V_9 ) ;
F_6 ( V_6 -> V_22 [ V_23 ] , V_24 ) ;
}
void T_1 F_7 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_10 . V_6 . V_22 [ V_25 ] & V_26 ) ||
( V_2 -> V_10 . V_6 . V_22 [ V_25 ] & V_27 ) )
V_2 -> V_10 . V_11 |= V_12 ;
F_1 ( V_2 , & V_2 -> V_10 . V_28 ,
F_8 ( V_2 -> V_10 . V_29 ) ) ;
}
void T_1 F_9 ( struct V_1 * V_2 )
{
F_4 ( V_2 , & V_2 -> V_10 . V_28 ,
F_8 ( V_2 -> V_10 . V_29 ) ) ;
if ( V_2 -> V_10 . V_11 & V_12 )
V_2 -> V_10 . V_11 &= ~ V_12 ;
}
static T_3 T_1 F_10 ( void )
{
return F_2 ( V_30 ) ;
}
