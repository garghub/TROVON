static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
int V_6 = 0 ;
F_2 ( V_4 ) ;
F_3 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
V_7 . V_8 |= V_9 ;
V_10 . V_11 = V_12 ;
V_10 . V_8 |= V_13 ;
}
V_14 = F_5 ( V_15 ) ;
if ( F_6 ( V_14 ) )
return F_7 ( V_14 ) ;
V_6 = F_8 ( V_2 , V_14 ) ;
if ( V_6 < 0 )
F_9 ( V_14 ) ;
return V_6 ;
}
static int F_10 ( struct V_16 * V_5 )
{
struct V_17 * V_18 ;
int V_19 , V_20 ;
V_15 = F_11 ( L_1 ) ;
if ( F_6 ( V_15 ) )
return F_7 ( V_15 ) ;
if ( V_21 )
F_12 ( & V_22 [ 2 ] , V_21 , V_23 - 2 ) ;
V_20 = strlen ( V_22 ) ;
V_22 [ 0 ] = ( V_20 >> 8 ) & 0xFF ;
V_22 [ 1 ] = V_20 & 0xFF ;
V_18 = F_13 ( V_15 , struct V_17 , V_24 ) ;
V_18 -> V_25 = 0 ;
memcpy ( V_18 -> V_22 , V_22 , V_23 ) ;
V_18 -> V_26 = V_27 ;
V_19 = F_14 ( V_5 , V_28 ) ;
if ( V_19 < 0 ) {
F_15 ( V_15 ) ;
return V_19 ;
}
V_29 . V_30 = V_28 [ V_31 ] . V_32 ;
V_29 . V_33 = V_28 [ V_34 ] . V_32 ;
V_29 . V_35 = V_28 [ V_36 ] . V_32 ;
V_19 = F_16 ( V_5 , & V_10 , F_1 ) ;
if ( V_19 ) {
F_15 ( V_15 ) ;
return V_19 ;
}
F_17 ( V_5 , & V_37 ) ;
return V_19 ;
}
static int F_18 ( struct V_16 * V_5 )
{
F_9 ( V_14 ) ;
F_15 ( V_15 ) ;
return 0 ;
}
