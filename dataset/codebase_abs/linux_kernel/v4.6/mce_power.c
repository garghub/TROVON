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
F_1 ( V_12 , V_2 ) ;
}
static void F_6 ( void )
{
struct V_13 * V_14 ;
unsigned long V_4 , V_15 ;
asm volatile("slbmte %0,%0; slbia" : : "r" (0));
#ifdef F_7
if ( F_8 () -> V_16 . V_17 )
return;
#endif
V_14 = F_9 () ;
if ( ! V_14 )
return;
V_15 = F_10 ( V_18 , F_11 ( V_14 -> V_19 ) , V_20 ) ;
for ( V_4 = 0 ; V_4 < V_15 ; V_4 ++ ) {
unsigned long V_3 = F_12 ( V_14 -> V_21 [ V_4 ] . V_22 ) ;
unsigned long V_23 = F_12 ( V_14 -> V_21 [ V_4 ] . V_24 ) ;
V_3 = ( V_3 & ~ 0xFFFul ) | V_4 ;
asm volatile("slbmte %0,%1" : : "r" (rs), "r" (rb));
}
}
static long F_13 ( T_1 V_25 , T_1 V_26 )
{
long V_27 = 1 ;
if ( V_25 & V_26 ) {
F_6 () ;
V_25 &= ~ ( V_26 ) ;
}
if ( V_25 & V_28 ) {
if ( V_29 && V_29 -> V_30 )
V_29 -> V_30 ( V_5 ) ;
V_25 &= ~ V_28 ;
}
if ( V_25 & 0xffffffffUL )
V_27 = 0 ;
return V_27 ;
}
static long F_14 ( T_1 V_25 )
{
return F_13 ( V_25 , V_31 ) ;
}
static long F_15 ( T_1 V_32 )
{
long V_27 = 0 ;
switch ( F_16 ( V_32 ) ) {
case 0 :
break;
case V_33 :
case V_34 :
F_6 () ;
V_27 = 1 ;
break;
case V_35 :
if ( V_29 && V_29 -> V_30 ) {
V_29 -> V_30 ( V_5 ) ;
V_27 = 1 ;
}
break;
default:
break;
}
return V_27 ;
}
static long F_17 ( T_1 V_32 )
{
long V_27 = 0 ;
V_27 = F_15 ( V_32 ) ;
if ( F_16 ( V_32 ) == V_36 ) {
F_6 () ;
V_27 = 1 ;
}
return V_27 ;
}
static void F_18 ( struct V_37 * V_38 , T_1 V_32 )
{
switch ( F_16 ( V_32 ) ) {
case V_33 :
V_38 -> V_39 = V_40 ;
V_38 -> V_41 . V_42 = V_43 ;
break;
case V_34 :
V_38 -> V_39 = V_40 ;
V_38 -> V_41 . V_42 = V_44 ;
break;
case V_35 :
V_38 -> V_39 = V_45 ;
V_38 -> V_41 . V_46 = V_47 ;
break;
case V_48 :
case V_49 :
V_38 -> V_39 = V_50 ;
V_38 -> V_41 . V_51 = V_52 ;
break;
case V_53 :
V_38 -> V_39 = V_50 ;
V_38 -> V_41 . V_51 =
V_54 ;
break;
}
}
static void F_19 ( struct V_37 * V_38 , T_1 V_32 )
{
F_18 ( V_38 , V_32 ) ;
if ( F_16 ( V_32 ) == V_36 ) {
V_38 -> V_39 = V_40 ;
V_38 -> V_41 . V_42 = V_55 ;
}
}
static void F_20 ( struct V_37 * V_38 , T_1 V_25 )
{
if ( V_25 & V_56 ) {
V_38 -> V_39 = V_50 ;
V_38 -> V_41 . V_51 = V_57 ;
} else if ( V_25 & V_58 ) {
V_38 -> V_39 = V_50 ;
V_38 -> V_41 . V_51 =
V_59 ;
} else if ( V_25 & V_60 ) {
V_38 -> V_39 = V_61 ;
V_38 -> V_41 . V_62 = V_63 ;
} else if ( V_25 & V_64 ) {
V_38 -> V_39 = V_40 ;
V_38 -> V_41 . V_42 = V_44 ;
} else if ( V_25 & V_65 ) {
V_38 -> V_39 = V_40 ;
V_38 -> V_41 . V_42 = V_43 ;
} else if ( V_25 & V_28 ) {
V_38 -> V_39 = V_45 ;
V_38 -> V_41 . V_46 = V_47 ;
} else if ( V_25 & V_66 ) {
V_38 -> V_39 = V_40 ;
V_38 -> V_41 . V_42 = V_55 ;
}
}
static long F_21 ( struct V_67 * V_68 )
{
long V_27 = 0 ;
if ( V_69 . V_70 ) {
if ( V_69 . V_70 ( V_68 ) )
V_27 = 1 ;
}
return V_27 ;
}
long F_22 ( struct V_67 * V_68 )
{
T_1 V_32 , V_71 , V_72 ;
long V_27 = 1 ;
struct V_37 V_37 = { 0 } ;
V_32 = V_68 -> V_73 ;
V_71 = V_68 -> V_71 ;
if ( F_23 ( V_32 ) ) {
V_27 = F_14 ( V_68 -> V_25 ) ;
F_20 ( & V_37 , V_68 -> V_25 ) ;
V_72 = V_68 -> V_74 ;
} else {
V_27 = F_17 ( V_32 ) ;
F_19 ( & V_37 , V_32 ) ;
V_72 = V_68 -> V_71 ;
}
if ( V_37 . V_39 == V_50 )
V_27 = F_21 ( V_68 ) ;
F_24 ( V_68 , V_27 , & V_37 , V_71 , V_72 ) ;
return V_27 ;
}
static void F_25 ( struct V_37 * V_38 , T_1 V_32 )
{
F_18 ( V_38 , V_32 ) ;
if ( F_16 ( V_32 ) == V_75 ) {
V_38 -> V_39 = V_61 ;
V_38 -> V_41 . V_62 = V_63 ;
}
}
static void F_26 ( struct V_37 * V_38 , T_1 V_25 )
{
F_20 ( V_38 , V_25 ) ;
if ( V_25 & V_76 ) {
V_38 -> V_39 = V_61 ;
V_38 -> V_41 . V_62 = V_63 ;
}
}
static long F_27 ( T_1 V_32 )
{
long V_27 = 0 ;
V_27 = F_15 ( V_32 ) ;
if ( F_16 ( V_32 ) == V_75 ) {
F_6 () ;
V_27 = 1 ;
}
return V_27 ;
}
static long F_28 ( T_1 V_25 )
{
return F_13 ( V_25 , V_77 ) ;
}
long F_29 ( struct V_67 * V_68 )
{
T_1 V_32 , V_71 , V_72 ;
long V_27 = 1 ;
struct V_37 V_37 = { 0 } ;
V_32 = V_68 -> V_73 ;
V_71 = V_68 -> V_71 ;
if ( F_23 ( V_32 ) ) {
V_27 = F_28 ( V_68 -> V_25 ) ;
F_26 ( & V_37 , V_68 -> V_25 ) ;
V_72 = V_68 -> V_74 ;
} else {
V_27 = F_27 ( V_32 ) ;
F_25 ( & V_37 , V_32 ) ;
V_72 = V_68 -> V_71 ;
}
if ( V_37 . V_39 == V_50 )
V_27 = F_21 ( V_68 ) ;
F_24 ( V_68 , V_27 , & V_37 , V_71 , V_72 ) ;
return V_27 ;
}
