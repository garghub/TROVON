void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = 0 ;
int V_6 = 0 ;
if ( ! V_2 )
return;
V_4 = V_2 -> V_7 ;
if ( ! V_4 )
return;
if ( V_2 -> V_8 & V_9 )
return;
if ( ( V_2 -> V_10 & V_11 ) &&
( V_2 -> V_12 . V_13 > 0 ) )
F_2 ( V_2 -> V_12 . V_14 ) ;
if ( V_2 -> V_15 & V_16 )
V_6 = 1 ;
if ( ( V_2 -> V_15 & V_16 ) ||
( V_2 -> V_17 . V_18 & V_19 ) ||
( V_2 -> V_10 & V_20 ) )
V_5 = 1 ;
if ( ( ( V_2 -> V_10 & V_11 ) == 0 ) &&
( ( V_2 -> V_10 & V_21 ) == 0 ) &&
( V_5 == 1 ) ) {
V_4 -> V_22 = 1 ;
if ( F_3 ( & V_2 -> V_23 ) )
F_4 ( & V_2 -> V_23 ) ;
}
if ( ( V_5 == 0 ) &&
( ( V_2 -> V_10 & V_24 ) != 0 ) &&
( V_6 == 0 ) ) {
V_4 -> V_22 = 1 ;
V_2 -> V_10 &= ~ ( V_25 | V_26 | V_27 | V_28 ) ;
if ( F_3 ( & V_2 -> V_23 ) )
F_4 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_12 . V_13 > 0 )
F_2 ( V_2 -> V_12 . V_14 ) ;
if ( V_2 -> V_29 . V_13 > 0 )
F_2 ( V_2 -> V_29 . V_14 ) ;
}
if ( V_5 == 1 )
V_2 -> V_10 |= V_21 ;
else
V_2 -> V_10 &= ~ V_21 ;
if ( V_6 == 1 )
V_2 -> V_10 |= V_24 ;
else
V_2 -> V_10 &= ~ V_24 ;
}
