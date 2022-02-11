static void F_1 ( void )
{
struct V_1 * V_2 ;
unsigned long V_3 , V_4 ;
asm volatile("slbmte %0,%0; slbia" : : "r" (0));
#ifdef F_2
if ( F_3 () -> V_5 . V_6 )
return;
#endif
V_2 = F_4 () ;
if ( ! V_2 )
return;
V_4 = F_5 ( V_7 , F_6 ( V_2 -> V_8 ) , V_9 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
unsigned long V_10 = F_7 ( V_2 -> V_11 [ V_3 ] . V_12 ) ;
unsigned long V_13 = F_7 ( V_2 -> V_11 [ V_3 ] . V_14 ) ;
V_10 = ( V_10 & ~ 0xFFFul ) | V_3 ;
asm volatile("slbmte %0,%1" : : "r" (rs), "r" (rb));
}
}
static long F_8 ( T_1 V_15 , T_1 V_16 )
{
long V_17 = 1 ;
if ( V_15 & V_16 ) {
F_1 () ;
V_15 &= ~ ( V_16 ) ;
}
if ( V_15 & V_18 ) {
if ( V_19 && V_19 -> V_20 )
V_19 -> V_20 ( V_21 ) ;
V_15 &= ~ V_18 ;
}
if ( V_15 & 0xffffffffUL )
V_17 = 0 ;
return V_17 ;
}
static long F_9 ( T_1 V_15 )
{
return F_8 ( V_15 , V_22 ) ;
}
static long F_10 ( T_1 V_23 )
{
long V_17 = 0 ;
switch ( F_11 ( V_23 ) ) {
case 0 :
break;
case V_24 :
case V_25 :
F_1 () ;
V_17 = 1 ;
break;
case V_26 :
if ( V_19 && V_19 -> V_20 ) {
V_19 -> V_20 ( V_21 ) ;
V_17 = 1 ;
}
break;
default:
break;
}
return V_17 ;
}
static long F_12 ( T_1 V_23 )
{
long V_17 = 0 ;
V_17 = F_10 ( V_23 ) ;
if ( F_11 ( V_23 ) == V_27 ) {
F_1 () ;
V_17 = 1 ;
}
return V_17 ;
}
static void F_13 ( struct V_28 * V_29 , T_1 V_23 )
{
switch ( F_11 ( V_23 ) ) {
case V_24 :
V_29 -> V_30 = V_31 ;
V_29 -> V_32 . V_33 = V_34 ;
break;
case V_25 :
V_29 -> V_30 = V_31 ;
V_29 -> V_32 . V_33 = V_35 ;
break;
case V_26 :
V_29 -> V_30 = V_36 ;
V_29 -> V_32 . V_37 = V_38 ;
break;
case V_39 :
case V_40 :
V_29 -> V_30 = V_41 ;
V_29 -> V_32 . V_42 = V_43 ;
break;
case V_44 :
V_29 -> V_30 = V_41 ;
V_29 -> V_32 . V_42 =
V_45 ;
break;
}
}
static void F_14 ( struct V_28 * V_29 , T_1 V_23 )
{
F_13 ( V_29 , V_23 ) ;
if ( F_11 ( V_23 ) == V_27 ) {
V_29 -> V_30 = V_31 ;
V_29 -> V_32 . V_33 = V_46 ;
}
}
static void F_15 ( struct V_28 * V_29 , T_1 V_15 )
{
if ( V_15 & V_47 ) {
V_29 -> V_30 = V_41 ;
V_29 -> V_32 . V_42 = V_48 ;
} else if ( V_15 & V_49 ) {
V_29 -> V_30 = V_41 ;
V_29 -> V_32 . V_42 =
V_50 ;
} else if ( V_15 & V_51 ) {
V_29 -> V_30 = V_52 ;
V_29 -> V_32 . V_53 = V_54 ;
} else if ( V_15 & V_55 ) {
V_29 -> V_30 = V_31 ;
V_29 -> V_32 . V_33 = V_35 ;
} else if ( V_15 & V_56 ) {
V_29 -> V_30 = V_31 ;
V_29 -> V_32 . V_33 = V_34 ;
} else if ( V_15 & V_18 ) {
V_29 -> V_30 = V_36 ;
V_29 -> V_32 . V_37 = V_38 ;
} else if ( V_15 & V_57 ) {
V_29 -> V_30 = V_31 ;
V_29 -> V_32 . V_33 = V_46 ;
}
}
static long F_16 ( struct V_58 * V_59 )
{
long V_17 = 0 ;
if ( V_60 . V_61 ) {
if ( V_60 . V_61 ( V_59 ) )
V_17 = 1 ;
}
return V_17 ;
}
long F_17 ( struct V_58 * V_59 )
{
T_1 V_23 , V_62 , V_63 ;
long V_17 = 1 ;
struct V_28 V_28 = { 0 } ;
V_23 = V_59 -> V_64 ;
V_62 = V_59 -> V_62 ;
if ( F_18 ( V_23 ) ) {
V_17 = F_9 ( V_59 -> V_15 ) ;
F_15 ( & V_28 , V_59 -> V_15 ) ;
V_63 = V_59 -> V_65 ;
} else {
V_17 = F_12 ( V_23 ) ;
F_14 ( & V_28 , V_23 ) ;
V_63 = V_59 -> V_62 ;
}
if ( V_28 . V_30 == V_41 )
V_17 = F_16 ( V_59 ) ;
F_19 ( V_59 , V_17 , & V_28 , V_62 , V_63 ) ;
return V_17 ;
}
static void F_20 ( struct V_28 * V_29 , T_1 V_23 )
{
F_13 ( V_29 , V_23 ) ;
if ( F_11 ( V_23 ) == V_66 ) {
V_29 -> V_30 = V_52 ;
V_29 -> V_32 . V_53 = V_54 ;
}
}
static void F_21 ( struct V_28 * V_29 , T_1 V_15 )
{
F_15 ( V_29 , V_15 ) ;
if ( V_15 & V_67 ) {
V_29 -> V_30 = V_52 ;
V_29 -> V_32 . V_53 = V_54 ;
}
}
static long F_22 ( T_1 V_23 )
{
long V_17 = 0 ;
V_17 = F_10 ( V_23 ) ;
if ( F_11 ( V_23 ) == V_66 ) {
F_1 () ;
V_17 = 1 ;
}
return V_17 ;
}
static long F_23 ( T_1 V_15 )
{
return F_8 ( V_15 , V_68 ) ;
}
long F_24 ( struct V_58 * V_59 )
{
T_1 V_23 , V_62 , V_63 ;
long V_17 = 1 ;
struct V_28 V_28 = { 0 } ;
V_23 = V_59 -> V_64 ;
V_62 = V_59 -> V_62 ;
if ( F_18 ( V_23 ) ) {
V_17 = F_23 ( V_59 -> V_15 ) ;
F_21 ( & V_28 , V_59 -> V_15 ) ;
V_63 = V_59 -> V_65 ;
} else {
V_17 = F_22 ( V_23 ) ;
F_20 ( & V_28 , V_23 ) ;
V_63 = V_59 -> V_62 ;
}
if ( V_28 . V_30 == V_41 )
V_17 = F_16 ( V_59 ) ;
F_19 ( V_59 , V_17 , & V_28 , V_62 , V_63 ) ;
return V_17 ;
}
