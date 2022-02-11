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
void F_5 ( unsigned int V_2 )
{
if ( F_6 () )
F_1 ( V_12 , V_2 ) ;
F_1 ( V_13 , V_2 ) ;
}
static void F_7 ( void )
{
struct V_14 * V_15 ;
unsigned long V_4 , V_16 ;
asm volatile("slbmte %0,%0; slbia" : : "r" (0));
#ifdef F_8
if ( F_9 () -> V_17 . V_18 )
return;
#endif
V_15 = F_10 () ;
if ( ! V_15 )
return;
V_16 = F_11 ( V_19 , F_12 ( V_15 -> V_20 ) , V_21 ) ;
for ( V_4 = 0 ; V_4 < V_16 ; V_4 ++ ) {
unsigned long V_3 = F_13 ( V_15 -> V_22 [ V_4 ] . V_23 ) ;
unsigned long V_24 = F_13 ( V_15 -> V_22 [ V_4 ] . V_25 ) ;
V_3 = ( V_3 & ~ 0xFFFul ) | V_4 ;
asm volatile("slbmte %0,%1" : : "r" (rs), "r" (rb));
}
}
static long F_14 ( T_1 V_26 , T_1 V_27 )
{
long V_28 = 1 ;
#ifdef F_15
if ( V_26 & V_27 ) {
F_7 () ;
V_26 &= ~ ( V_27 ) ;
}
if ( V_26 & V_29 ) {
if ( V_30 && V_30 -> V_31 )
V_30 -> V_31 ( V_5 ) ;
V_26 &= ~ V_29 ;
}
#endif
if ( V_26 & 0xffffffffUL )
V_28 = 0 ;
return V_28 ;
}
static long F_16 ( T_1 V_26 )
{
return F_14 ( V_26 , V_32 ) ;
}
static long F_17 ( T_1 V_33 )
{
long V_28 = 0 ;
switch ( F_18 ( V_33 ) ) {
case 0 :
break;
#ifdef F_15
case V_34 :
case V_35 :
F_7 () ;
V_28 = 1 ;
break;
case V_36 :
if ( V_30 && V_30 -> V_31 ) {
V_30 -> V_31 ( V_5 ) ;
V_28 = 1 ;
}
break;
#endif
default:
break;
}
return V_28 ;
}
static long F_19 ( T_1 V_33 )
{
long V_28 = 0 ;
V_28 = F_17 ( V_33 ) ;
#ifdef F_15
if ( F_18 ( V_33 ) == V_37 ) {
F_7 () ;
V_28 = 1 ;
}
#endif
return V_28 ;
}
static void F_20 ( struct V_38 * V_39 , T_1 V_33 )
{
switch ( F_18 ( V_33 ) ) {
case V_34 :
V_39 -> V_40 = V_41 ;
V_39 -> V_42 . V_43 = V_44 ;
break;
case V_35 :
V_39 -> V_40 = V_41 ;
V_39 -> V_42 . V_43 = V_45 ;
break;
case V_36 :
V_39 -> V_40 = V_46 ;
V_39 -> V_42 . V_47 = V_48 ;
break;
case V_49 :
case V_50 :
V_39 -> V_40 = V_51 ;
V_39 -> V_42 . V_52 = V_53 ;
break;
case V_54 :
V_39 -> V_40 = V_51 ;
V_39 -> V_42 . V_52 =
V_55 ;
break;
}
}
static void F_21 ( struct V_38 * V_39 , T_1 V_33 )
{
F_20 ( V_39 , V_33 ) ;
if ( F_18 ( V_33 ) == V_37 ) {
V_39 -> V_40 = V_41 ;
V_39 -> V_42 . V_43 = V_56 ;
}
}
static void F_22 ( struct V_38 * V_39 , T_1 V_26 )
{
if ( V_26 & V_57 ) {
V_39 -> V_40 = V_51 ;
V_39 -> V_42 . V_52 = V_58 ;
} else if ( V_26 & V_59 ) {
V_39 -> V_40 = V_51 ;
V_39 -> V_42 . V_52 =
V_60 ;
} else if ( V_26 & V_61 ) {
V_39 -> V_40 = V_62 ;
V_39 -> V_42 . V_63 = V_64 ;
} else if ( V_26 & V_65 ) {
V_39 -> V_40 = V_41 ;
V_39 -> V_42 . V_43 = V_45 ;
} else if ( V_26 & V_66 ) {
V_39 -> V_40 = V_41 ;
V_39 -> V_42 . V_43 = V_44 ;
} else if ( V_26 & V_29 ) {
V_39 -> V_40 = V_46 ;
V_39 -> V_42 . V_47 = V_48 ;
} else if ( V_26 & V_67 ) {
V_39 -> V_40 = V_41 ;
V_39 -> V_42 . V_43 = V_56 ;
}
}
static long F_23 ( struct V_68 * V_69 )
{
long V_28 = 0 ;
if ( V_70 . V_71 ) {
if ( V_70 . V_71 ( V_69 ) )
V_28 = 1 ;
}
return V_28 ;
}
long F_24 ( struct V_68 * V_69 )
{
T_1 V_33 , V_72 , V_73 ;
long V_28 = 1 ;
struct V_38 V_38 = { 0 } ;
V_33 = V_69 -> V_74 ;
V_72 = V_69 -> V_72 ;
if ( F_25 ( V_33 ) ) {
V_28 = F_16 ( V_69 -> V_26 ) ;
F_22 ( & V_38 , V_69 -> V_26 ) ;
V_73 = V_69 -> V_75 ;
} else {
V_28 = F_19 ( V_33 ) ;
F_21 ( & V_38 , V_33 ) ;
V_73 = V_69 -> V_72 ;
}
if ( V_38 . V_40 == V_51 )
V_28 = F_23 ( V_69 ) ;
F_26 ( V_69 , V_28 , & V_38 , V_72 , V_73 ) ;
return V_28 ;
}
static void F_27 ( struct V_38 * V_39 , T_1 V_33 )
{
F_20 ( V_39 , V_33 ) ;
if ( F_18 ( V_33 ) == V_76 ) {
V_39 -> V_40 = V_62 ;
V_39 -> V_42 . V_63 = V_64 ;
}
}
static void F_28 ( struct V_38 * V_39 , T_1 V_26 )
{
F_22 ( V_39 , V_26 ) ;
if ( V_26 & V_77 ) {
V_39 -> V_40 = V_62 ;
V_39 -> V_42 . V_63 = V_64 ;
}
}
static long F_29 ( T_1 V_33 )
{
long V_28 = 0 ;
V_28 = F_17 ( V_33 ) ;
#ifdef F_15
if ( F_18 ( V_33 ) == V_76 ) {
F_7 () ;
V_28 = 1 ;
}
#endif
return V_28 ;
}
static long F_30 ( T_1 V_26 )
{
return F_14 ( V_26 , V_78 ) ;
}
long F_31 ( struct V_68 * V_69 )
{
T_1 V_33 , V_72 , V_73 ;
long V_28 = 1 ;
struct V_38 V_38 = { 0 } ;
V_33 = V_69 -> V_74 ;
V_72 = V_69 -> V_72 ;
if ( F_25 ( V_33 ) ) {
V_28 = F_30 ( V_69 -> V_26 ) ;
F_28 ( & V_38 , V_69 -> V_26 ) ;
V_73 = V_69 -> V_75 ;
} else {
V_28 = F_29 ( V_33 ) ;
F_27 ( & V_38 , V_33 ) ;
V_73 = V_69 -> V_72 ;
}
if ( V_38 . V_40 == V_51 )
V_28 = F_23 ( V_69 ) ;
F_26 ( V_69 , V_28 , & V_38 , V_72 , V_73 ) ;
return V_28 ;
}
