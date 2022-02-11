static void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned long V_3 ;
unsigned int V_4 ;
switch ( V_2 ) {
case V_5 :
V_3 = V_6 ;
break;
case V_7 :
V_3 = V_8 ;
break;
default:
F_2 () ;
break;
}
asm volatile("ptesync" : : : "memory");
for ( V_4 = 0 ; V_4 < V_1 ; V_4 ++ ) {
asm volatile("tlbiel %0" : : "r" (rb));
V_3 += 1 << V_9 ;
}
asm volatile("ptesync" : : : "memory");
}
void F_3 ( unsigned int V_2 )
{
F_1 ( V_10 , V_2 ) ;
}
void F_4 ( unsigned int V_2 )
{
F_1 ( V_11 , V_2 ) ;
}
static void F_5 ( void )
{
struct V_12 * V_13 ;
unsigned long V_4 , V_14 ;
asm volatile("slbmte %0,%0; slbia" : : "r" (0));
#ifdef F_6
if ( F_7 () -> V_15 . V_16 )
return;
#endif
V_13 = F_8 () ;
if ( ! V_13 )
return;
V_14 = F_9 ( V_17 , F_10 ( V_13 -> V_18 ) , V_19 ) ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ ) {
unsigned long V_3 = F_11 ( V_13 -> V_20 [ V_4 ] . V_21 ) ;
unsigned long V_22 = F_11 ( V_13 -> V_20 [ V_4 ] . V_23 ) ;
V_3 = ( V_3 & ~ 0xFFFul ) | V_4 ;
asm volatile("slbmte %0,%1" : : "r" (rs), "r" (rb));
}
}
static long F_12 ( T_1 V_24 , T_1 V_25 )
{
long V_26 = 1 ;
if ( V_24 & V_25 ) {
F_5 () ;
V_24 &= ~ ( V_25 ) ;
}
if ( V_24 & V_27 ) {
if ( V_28 && V_28 -> V_29 )
V_28 -> V_29 ( V_5 ) ;
V_24 &= ~ V_27 ;
}
if ( V_24 & 0xffffffffUL )
V_26 = 0 ;
return V_26 ;
}
static long F_13 ( T_1 V_24 )
{
return F_12 ( V_24 , V_30 ) ;
}
static long F_14 ( T_1 V_31 )
{
long V_26 = 0 ;
switch ( F_15 ( V_31 ) ) {
case 0 :
break;
case V_32 :
case V_33 :
F_5 () ;
V_26 = 1 ;
break;
case V_34 :
if ( V_28 && V_28 -> V_29 ) {
V_28 -> V_29 ( V_5 ) ;
V_26 = 1 ;
}
break;
default:
break;
}
return V_26 ;
}
static long F_16 ( T_1 V_31 )
{
long V_26 = 0 ;
V_26 = F_14 ( V_31 ) ;
if ( F_15 ( V_31 ) == V_35 ) {
F_5 () ;
V_26 = 1 ;
}
return V_26 ;
}
static void F_17 ( struct V_36 * V_37 , T_1 V_31 )
{
switch ( F_15 ( V_31 ) ) {
case V_32 :
V_37 -> V_38 = V_39 ;
V_37 -> V_40 . V_41 = V_42 ;
break;
case V_33 :
V_37 -> V_38 = V_39 ;
V_37 -> V_40 . V_41 = V_43 ;
break;
case V_34 :
V_37 -> V_38 = V_44 ;
V_37 -> V_40 . V_45 = V_46 ;
break;
case V_47 :
case V_48 :
V_37 -> V_38 = V_49 ;
V_37 -> V_40 . V_50 = V_51 ;
break;
case V_52 :
V_37 -> V_38 = V_49 ;
V_37 -> V_40 . V_50 =
V_53 ;
break;
}
}
static void F_18 ( struct V_36 * V_37 , T_1 V_31 )
{
F_17 ( V_37 , V_31 ) ;
if ( F_15 ( V_31 ) == V_35 ) {
V_37 -> V_38 = V_39 ;
V_37 -> V_40 . V_41 = V_54 ;
}
}
static void F_19 ( struct V_36 * V_37 , T_1 V_24 )
{
if ( V_24 & V_55 ) {
V_37 -> V_38 = V_49 ;
V_37 -> V_40 . V_50 = V_56 ;
} else if ( V_24 & V_57 ) {
V_37 -> V_38 = V_49 ;
V_37 -> V_40 . V_50 =
V_58 ;
} else if ( V_24 & V_59 ) {
V_37 -> V_38 = V_60 ;
V_37 -> V_40 . V_61 = V_62 ;
} else if ( V_24 & V_63 ) {
V_37 -> V_38 = V_39 ;
V_37 -> V_40 . V_41 = V_43 ;
} else if ( V_24 & V_64 ) {
V_37 -> V_38 = V_39 ;
V_37 -> V_40 . V_41 = V_42 ;
} else if ( V_24 & V_27 ) {
V_37 -> V_38 = V_44 ;
V_37 -> V_40 . V_45 = V_46 ;
} else if ( V_24 & V_65 ) {
V_37 -> V_38 = V_39 ;
V_37 -> V_40 . V_41 = V_54 ;
}
}
static long F_20 ( struct V_66 * V_67 )
{
long V_26 = 0 ;
if ( V_68 . V_69 ) {
if ( V_68 . V_69 ( V_67 ) )
V_26 = 1 ;
}
return V_26 ;
}
long F_21 ( struct V_66 * V_67 )
{
T_1 V_31 , V_70 , V_71 ;
long V_26 = 1 ;
struct V_36 V_36 = { 0 } ;
V_31 = V_67 -> V_72 ;
V_70 = V_67 -> V_70 ;
if ( F_22 ( V_31 ) ) {
V_26 = F_13 ( V_67 -> V_24 ) ;
F_19 ( & V_36 , V_67 -> V_24 ) ;
V_71 = V_67 -> V_73 ;
} else {
V_26 = F_16 ( V_31 ) ;
F_18 ( & V_36 , V_31 ) ;
V_71 = V_67 -> V_70 ;
}
if ( V_36 . V_38 == V_49 )
V_26 = F_20 ( V_67 ) ;
F_23 ( V_67 , V_26 , & V_36 , V_70 , V_71 ) ;
return V_26 ;
}
static void F_24 ( struct V_36 * V_37 , T_1 V_31 )
{
F_17 ( V_37 , V_31 ) ;
if ( F_15 ( V_31 ) == V_74 ) {
V_37 -> V_38 = V_60 ;
V_37 -> V_40 . V_61 = V_62 ;
}
}
static void F_25 ( struct V_36 * V_37 , T_1 V_24 )
{
F_19 ( V_37 , V_24 ) ;
if ( V_24 & V_75 ) {
V_37 -> V_38 = V_60 ;
V_37 -> V_40 . V_61 = V_62 ;
}
}
static long F_26 ( T_1 V_31 )
{
long V_26 = 0 ;
V_26 = F_14 ( V_31 ) ;
if ( F_15 ( V_31 ) == V_74 ) {
F_5 () ;
V_26 = 1 ;
}
return V_26 ;
}
static long F_27 ( T_1 V_24 )
{
return F_12 ( V_24 , V_76 ) ;
}
long F_28 ( struct V_66 * V_67 )
{
T_1 V_31 , V_70 , V_71 ;
long V_26 = 1 ;
struct V_36 V_36 = { 0 } ;
V_31 = V_67 -> V_72 ;
V_70 = V_67 -> V_70 ;
if ( F_22 ( V_31 ) ) {
V_26 = F_27 ( V_67 -> V_24 ) ;
F_25 ( & V_36 , V_67 -> V_24 ) ;
V_71 = V_67 -> V_73 ;
} else {
V_26 = F_26 ( V_31 ) ;
F_24 ( & V_36 , V_31 ) ;
V_71 = V_67 -> V_70 ;
}
if ( V_36 . V_38 == V_49 )
V_26 = F_20 ( V_67 ) ;
F_23 ( V_67 , V_26 , & V_36 , V_70 , V_71 ) ;
return V_26 ;
}
