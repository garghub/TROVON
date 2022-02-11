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
static void F_3 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned long V_3 ;
unsigned int V_4 ;
unsigned int V_10 ;
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
if ( F_4 () )
V_10 = 1 ;
else
V_10 = 0 ;
asm volatile(PPC_TLBIEL(%0, %1, %2, %3, %4) : :
"r"(rb), "r"(0), "i"(2), "i"(0), "r"(r));
for ( V_4 = 1 ; V_4 < V_1 ; V_4 ++ ) {
unsigned long V_11 = V_4 * ( 1 << V_9 ) ;
asm volatile(PPC_TLBIEL(%0, %1, %2, %3, %4) : :
"r"(rb+set), "r"(0), "i"(2), "i"(0), "r"(r));
}
asm volatile(PPC_TLBIEL(%0, %1, %2, %3, %4) : :
"r"(rb), "r"(0), "i"(2), "i"(1), "r"(r));
if ( F_4 () ) {
for ( V_4 = 1 ; V_4 < V_1 ; V_4 ++ ) {
unsigned long V_11 = V_4 * ( 1 << V_9 ) ;
asm volatile(PPC_TLBIEL(%0, %1, %2, %3, %4) : :
"r"(rb+set), "r"(0), "i"(2), "i"(1), "r"(r));
}
}
asm volatile("ptesync" : : : "memory");
}
void F_5 ( unsigned int V_2 )
{
F_1 ( V_12 , V_2 ) ;
}
void F_6 ( unsigned int V_2 )
{
F_1 ( V_13 , V_2 ) ;
}
void F_7 ( unsigned int V_2 )
{
unsigned int V_1 ;
if ( F_8 () )
V_1 = V_14 ;
else
V_1 = V_15 ;
F_3 ( V_1 , V_2 ) ;
}
static void F_9 ( void )
{
struct V_16 * V_17 ;
unsigned long V_4 , V_18 ;
asm volatile("slbmte %0,%0; slbia" : : "r" (0));
#ifdef F_10
if ( F_11 () -> V_19 . V_20 )
return;
#endif
V_17 = F_12 () ;
if ( ! V_17 )
return;
V_18 = F_13 ( V_21 , F_14 ( V_17 -> V_22 ) , V_23 ) ;
for ( V_4 = 0 ; V_4 < V_18 ; V_4 ++ ) {
unsigned long V_3 = F_15 ( V_17 -> V_24 [ V_4 ] . V_25 ) ;
unsigned long V_26 = F_15 ( V_17 -> V_24 [ V_4 ] . V_27 ) ;
V_3 = ( V_3 & ~ 0xFFFul ) | V_4 ;
asm volatile("slbmte %0,%1" : : "r" (rs), "r" (rb));
}
}
static void F_16 ( void )
{
asm volatile(PPC_INVALIDATE_ERAT : : :"memory");
}
static int F_17 ( int V_28 )
{
#ifdef F_18
if ( V_28 == V_29 ) {
F_9 () ;
return 1 ;
}
#endif
if ( V_28 == V_30 ) {
F_16 () ;
return 1 ;
}
if ( V_28 == V_31 ) {
if ( V_32 && V_32 -> V_33 ) {
V_32 -> V_33 ( V_5 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_19 ( struct V_34 * V_35 ,
const struct V_36 V_37 [] ,
struct V_38 * V_39 , T_1 * V_40 )
{
T_1 V_41 = V_35 -> V_42 ;
int V_43 = 0 ;
int V_4 ;
* V_40 = 0 ;
for ( V_4 = 0 ; V_37 [ V_4 ] . V_44 ; V_4 ++ ) {
if ( ( V_41 & V_37 [ V_4 ] . V_44 ) != V_37 [ V_4 ] . V_45 )
continue;
switch ( V_37 [ V_4 ] . V_46 ) {
case V_47 :
V_43 = F_17 ( V_29 ) ;
break;
case V_48 :
V_43 = F_17 ( V_30 ) ;
break;
case V_49 :
V_43 = F_17 ( V_31 ) ;
break;
}
V_39 -> V_46 = V_37 [ V_4 ] . V_46 ;
switch ( V_37 [ V_4 ] . V_46 ) {
case V_50 :
V_39 -> V_51 . V_52 = V_37 [ V_4 ] . V_53 ;
break;
case V_47 :
V_39 -> V_51 . V_54 = V_37 [ V_4 ] . V_53 ;
break;
case V_48 :
V_39 -> V_51 . V_55 = V_37 [ V_4 ] . V_53 ;
break;
case V_49 :
V_39 -> V_51 . V_56 = V_37 [ V_4 ] . V_53 ;
break;
case V_57 :
V_39 -> V_51 . V_58 = V_37 [ V_4 ] . V_53 ;
break;
case V_59 :
V_39 -> V_51 . V_60 = V_37 [ V_4 ] . V_53 ;
break;
case V_61 :
V_39 -> V_51 . V_62 = V_37 [ V_4 ] . V_53 ;
break;
}
V_39 -> V_63 = V_37 [ V_4 ] . V_63 ;
V_39 -> V_64 = V_37 [ V_4 ] . V_64 ;
if ( V_37 [ V_4 ] . V_65 )
* V_40 = V_35 -> V_66 ;
return V_43 ;
}
V_39 -> V_46 = V_67 ;
V_39 -> V_63 = V_68 ;
V_39 -> V_64 = V_69 ;
return 0 ;
}
static int F_20 ( struct V_34 * V_35 ,
const struct V_70 V_37 [] ,
struct V_38 * V_39 , T_1 * V_40 )
{
T_1 V_71 = V_35 -> V_71 ;
int V_43 = 0 ;
int V_72 = 0 ;
int V_4 ;
* V_40 = 0 ;
for ( V_4 = 0 ; V_37 [ V_4 ] . V_73 ; V_4 ++ ) {
if ( ! ( V_71 & V_37 [ V_4 ] . V_73 ) )
continue;
switch ( V_37 [ V_4 ] . V_46 ) {
case V_47 :
if ( F_17 ( V_29 ) )
V_43 = 1 ;
break;
case V_48 :
if ( F_17 ( V_30 ) )
V_43 = 1 ;
break;
case V_49 :
if ( F_17 ( V_31 ) )
V_43 = 1 ;
break;
}
if ( V_72 )
continue;
V_39 -> V_46 = V_37 [ V_4 ] . V_46 ;
switch ( V_37 [ V_4 ] . V_46 ) {
case V_50 :
V_39 -> V_51 . V_52 = V_37 [ V_4 ] . V_53 ;
break;
case V_47 :
V_39 -> V_51 . V_54 = V_37 [ V_4 ] . V_53 ;
break;
case V_48 :
V_39 -> V_51 . V_55 = V_37 [ V_4 ] . V_53 ;
break;
case V_49 :
V_39 -> V_51 . V_56 = V_37 [ V_4 ] . V_53 ;
break;
case V_57 :
V_39 -> V_51 . V_58 = V_37 [ V_4 ] . V_53 ;
break;
case V_59 :
V_39 -> V_51 . V_60 = V_37 [ V_4 ] . V_53 ;
break;
case V_61 :
V_39 -> V_51 . V_62 = V_37 [ V_4 ] . V_53 ;
break;
}
V_39 -> V_63 = V_37 [ V_4 ] . V_63 ;
V_39 -> V_64 = V_37 [ V_4 ] . V_64 ;
if ( V_37 [ V_4 ] . V_74 )
* V_40 = V_35 -> V_75 ;
V_72 = 1 ;
}
if ( V_72 )
return V_43 ;
V_39 -> V_46 = V_67 ;
V_39 -> V_63 = V_68 ;
V_39 -> V_64 = V_69 ;
return 0 ;
}
static long F_21 ( struct V_34 * V_35 )
{
long V_43 = 0 ;
if ( V_76 . V_77 ) {
if ( V_76 . V_77 ( V_35 ) )
V_43 = 1 ;
}
return V_43 ;
}
static long F_22 ( struct V_34 * V_35 ,
const struct V_70 V_78 [] ,
const struct V_36 V_79 [] )
{
struct V_38 V_39 = { 0 } ;
T_1 V_40 ;
T_1 V_41 = V_35 -> V_42 ;
long V_43 ;
if ( F_23 ( V_41 ) )
V_43 = F_20 ( V_35 , V_78 , & V_39 , & V_40 ) ;
else
V_43 = F_19 ( V_35 , V_79 , & V_39 , & V_40 ) ;
if ( ! V_43 && V_39 . V_46 == V_50 )
V_43 = F_21 ( V_35 ) ;
F_24 ( V_35 , V_43 , & V_39 , V_35 -> V_66 , V_40 ) ;
return V_43 ;
}
long F_25 ( struct V_34 * V_35 )
{
V_35 -> V_71 &= 0x0000ffff ;
return F_22 ( V_35 , V_80 , V_81 ) ;
}
long F_26 ( struct V_34 * V_35 )
{
return F_22 ( V_35 , V_82 , V_83 ) ;
}
long F_27 ( struct V_34 * V_35 )
{
if ( F_23 ( V_35 -> V_42 ) && V_35 -> V_71 == 0x02000000 )
return 1 ;
return F_22 ( V_35 , V_84 , V_85 ) ;
}
