static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
T_1 V_6 ;
long V_7 , V_8 ;
V_6 = V_9 [ 0 ] . V_10 ;
V_7 = V_9 [ 0 ] . V_11 - V_2 -> V_12 . V_11 ;
if ( V_7 < 0 ) V_7 = - V_7 ;
for ( V_5 = 1 ; V_5 < F_2 ( V_9 ) ; V_5 ++ ) {
V_8 = V_9 [ V_5 ] . V_11 - V_2 -> V_12 . V_11 ;
if ( V_8 < 0L ) V_8 = - V_8 ;
if ( V_8 < V_7 ) {
V_7 = V_8 ;
V_6 = V_9 [ V_5 ] . V_10 ;
}
}
F_3 ( V_6 , V_4 -> V_13 + V_14 ) ;
F_3 ( V_6 | 0x80000100 , V_4 -> V_13 + V_14 ) ;
F_4 ( 500 ) ;
F_3 ( V_6 & 0x7FFFFFFF , V_4 -> V_13 + V_14 ) ;
F_3 ( V_6 & 0x7FFFFEFF , V_4 -> V_13 + V_14 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_15 ;
V_15 = F_6 ( V_4 -> V_13 + V_16 ) ;
V_15 &= ~ ( V_17 | V_18
| V_19 | V_20
| V_21 | V_22
| V_23 | V_24
| V_25 ) ;
V_15 |= ( V_26 | V_27
| V_28 ) ;
if ( V_4 -> V_29 ) {
V_15 |= V_23 ;
V_15 |= V_25 | V_24 ;
}
if ( V_4 -> V_30 > 0 ) {
V_15 |= V_21 ;
V_15 |= V_22 ;
}
if ( V_2 -> V_12 . V_31 & V_32 )
V_15 |= V_19 ;
if ( V_2 -> V_12 . V_31 & V_33 )
V_15 |= V_20 ;
F_3 ( V_15 , V_4 -> V_13 + V_16 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_34 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_15 ;
int V_35 , V_36 , V_37 ;
switch ( V_34 ) {
case V_38 :
V_35 = 0 ; V_36 = 1 ; V_37 = 1 ;
break;
case V_39 :
V_35 = 1 ; V_36 = 1 ; V_37 = 1 ;
break;
case V_40 :
V_35 = 1 ; V_36 = 1 ; V_37 = 0 ;
break;
case V_41 :
V_35 = 1 ; V_36 = 0 ; V_37 = 1 ;
break;
case V_42 :
V_35 = 1 ; V_36 = 0 ; V_37 = 0 ;
break;
default:
return - V_43 ;
}
V_15 = F_6 ( V_4 -> V_13 + V_16 ) ;
V_15 &= ~ ( V_44 | V_23
| V_25 | V_24
| V_22 | V_21 ) ;
if ( V_4 -> V_29 ) {
if ( ! V_35 )
V_15 |= V_44 | V_23 ;
if ( V_36 )
V_15 |= V_25 ;
if ( V_37 )
V_15 |= V_24 ;
}
if ( V_4 -> V_30 > 0 ) {
if ( ! V_35 )
V_15 |= V_22 ;
if ( V_36 && V_37 )
V_15 |= V_21 ;
}
F_3 ( V_15 , V_4 -> V_13 + V_16 ) ;
return 0 ;
}
