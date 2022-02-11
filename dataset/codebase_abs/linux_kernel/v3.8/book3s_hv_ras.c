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
static void F_3 ( struct V_1 * V_2 )
{
unsigned long V_5 , V_14 ;
V_14 = V_18 ;
for ( V_5 = 0 ; V_5 < V_19 ; ++ V_5 ) {
asm volatile("tlbiel %0" : : "r" (rb));
V_14 += 1 << V_20 ;
}
}
static long F_4 ( struct V_1 * V_2 )
{
unsigned long V_21 = V_2 -> V_7 . V_22 . V_23 ;
#ifdef F_5
struct V_24 * V_25 ;
#endif
long V_26 = 1 ;
if ( V_21 & V_27 ) {
unsigned long V_28 = V_2 -> V_7 . V_22 . V_28 ;
if ( V_28 & ( V_29 | V_30 |
V_31 | V_32 ) ) {
F_1 ( V_2 ) ;
V_28 &= ~ ( V_29 | V_30 |
V_31 | V_32 ) ;
}
if ( V_28 & V_33 ) {
F_3 ( V_2 ) ;
V_28 &= ~ V_33 ;
}
if ( V_28 & 0xffffffffUL )
V_26 = 0 ;
}
switch ( ( V_21 >> V_34 ) & V_35 ) {
case 0 :
break;
case V_36 :
case V_37 :
case V_38 :
F_1 ( V_2 ) ;
break;
case V_39 :
F_3 ( V_2 ) ;
break;
default:
V_26 = 0 ;
}
#ifdef F_5
V_25 = V_40 -> V_41 ;
if ( V_25 -> V_42 == V_43 &&
( V_25 -> V_44 == V_45 ||
V_25 -> V_46 == V_47 ) )
V_26 = 1 ;
if ( V_26 )
V_25 -> V_48 = 0 ;
#endif
return V_26 ;
}
long F_6 ( struct V_1 * V_2 )
{
if ( F_7 ( V_49 ) )
return F_4 ( V_2 ) ;
return 0 ;
}
