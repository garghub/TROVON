static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 , V_6 ;
asm volatile("slbmte %0,%0; slbia" : : "r" (0));
V_4 = V_2 -> V_7 . V_3 . V_8 ;
if ( ! V_4 )
return;
V_6 = F_2 ( V_9 , V_4 -> V_10 , V_11 ) ;
if ( ( void * ) & V_4 -> V_12 [ V_6 ] > V_2 -> V_7 . V_3 . V_13 )
return;
for ( V_5 = 0 ; V_5 < V_6 ; ++ V_5 ) {
unsigned long V_14 = V_4 -> V_12 [ V_5 ] . V_15 ;
unsigned long V_16 = V_4 -> V_12 [ V_5 ] . V_17 ;
V_14 = ( V_14 & ~ 0xFFFul ) | V_5 ;
asm volatile("slbmte %0,%1" : : "r" (rs), "r" (rb));
}
}
static long F_3 ( struct V_1 * V_2 )
{
unsigned long V_18 = V_2 -> V_7 . V_19 . V_20 ;
struct V_21 V_22 ;
long V_23 = 1 ;
if ( V_18 & V_24 ) {
unsigned long V_25 = V_2 -> V_7 . V_19 . V_25 ;
if ( V_25 & ( V_26 | V_27 |
V_28 | V_29 ) ) {
F_1 ( V_2 ) ;
V_25 &= ~ ( V_26 | V_27 |
V_28 | V_29 ) ;
}
if ( V_25 & V_30 ) {
if ( V_31 && V_31 -> V_32 )
V_31 -> V_32 ( V_33 ) ;
V_25 &= ~ V_30 ;
}
if ( V_25 & 0xffffffffUL )
V_23 = 0 ;
}
switch ( ( V_18 >> V_34 ) & V_35 ) {
case 0 :
break;
case V_36 :
case V_37 :
case V_38 :
F_1 ( V_2 ) ;
break;
case V_39 :
if ( V_31 && V_31 -> V_32 )
V_31 -> V_32 ( V_33 ) ;
break;
default:
V_23 = 0 ;
}
if ( ! F_4 ( & V_22 , V_40 ) )
goto V_41;
if ( V_22 . V_42 == V_43 &&
( V_22 . V_44 == V_45 ||
V_22 . V_46 == V_47 ) )
V_23 = 1 ;
V_41:
if ( V_23 )
F_5 () ;
return V_23 ;
}
long F_6 ( struct V_1 * V_2 )
{
if ( F_7 ( V_48 ) )
return F_3 ( V_2 ) ;
return 0 ;
}
