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
unsigned int V_1 ;
if ( F_6 () )
V_1 = V_12 ;
else
V_1 = V_13 ;
F_1 ( V_1 , V_2 ) ;
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
static void F_14 ( void )
{
asm volatile(PPC_INVALIDATE_ERAT : : :"memory");
}
static int F_15 ( int V_26 )
{
#ifdef F_16
if ( V_26 == V_27 ) {
F_7 () ;
return 1 ;
}
#endif
if ( V_26 == V_28 ) {
F_14 () ;
return 1 ;
}
if ( V_26 == V_29 ) {
if ( V_30 && V_30 -> V_31 ) {
V_30 -> V_31 ( V_5 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_17 ( struct V_32 * V_33 ,
const struct V_34 V_35 [] ,
struct V_36 * V_37 , T_1 * V_38 )
{
T_1 V_39 = V_33 -> V_40 ;
int V_41 = 0 ;
int V_4 ;
* V_38 = 0 ;
for ( V_4 = 0 ; V_35 [ V_4 ] . V_42 ; V_4 ++ ) {
if ( ( V_39 & V_35 [ V_4 ] . V_42 ) != V_35 [ V_4 ] . V_43 )
continue;
switch ( V_35 [ V_4 ] . V_44 ) {
case V_45 :
V_41 = F_15 ( V_27 ) ;
break;
case V_46 :
V_41 = F_15 ( V_28 ) ;
break;
case V_47 :
V_41 = F_15 ( V_29 ) ;
break;
}
V_37 -> V_44 = V_35 [ V_4 ] . V_44 ;
switch ( V_35 [ V_4 ] . V_44 ) {
case V_48 :
V_37 -> V_49 . V_50 = V_35 [ V_4 ] . V_51 ;
break;
case V_45 :
V_37 -> V_49 . V_52 = V_35 [ V_4 ] . V_51 ;
break;
case V_46 :
V_37 -> V_49 . V_53 = V_35 [ V_4 ] . V_51 ;
break;
case V_47 :
V_37 -> V_49 . V_54 = V_35 [ V_4 ] . V_51 ;
break;
case V_55 :
V_37 -> V_49 . V_56 = V_35 [ V_4 ] . V_51 ;
break;
case V_57 :
V_37 -> V_49 . V_58 = V_35 [ V_4 ] . V_51 ;
break;
case V_59 :
V_37 -> V_49 . V_60 = V_35 [ V_4 ] . V_51 ;
break;
}
V_37 -> V_61 = V_35 [ V_4 ] . V_61 ;
V_37 -> V_62 = V_35 [ V_4 ] . V_62 ;
if ( V_35 [ V_4 ] . V_63 )
* V_38 = V_33 -> V_64 ;
return V_41 ;
}
V_37 -> V_44 = V_65 ;
V_37 -> V_61 = V_66 ;
V_37 -> V_62 = V_67 ;
return 0 ;
}
static int F_18 ( struct V_32 * V_33 ,
const struct V_68 V_35 [] ,
struct V_36 * V_37 , T_1 * V_38 )
{
T_1 V_69 = V_33 -> V_69 ;
int V_41 = 0 ;
int V_70 = 0 ;
int V_4 ;
* V_38 = 0 ;
for ( V_4 = 0 ; V_35 [ V_4 ] . V_71 ; V_4 ++ ) {
if ( ! ( V_69 & V_35 [ V_4 ] . V_71 ) )
continue;
switch ( V_35 [ V_4 ] . V_44 ) {
case V_45 :
if ( F_15 ( V_27 ) )
V_41 = 1 ;
break;
case V_46 :
if ( F_15 ( V_28 ) )
V_41 = 1 ;
break;
case V_47 :
if ( F_15 ( V_29 ) )
V_41 = 1 ;
break;
}
if ( V_70 )
continue;
V_37 -> V_44 = V_35 [ V_4 ] . V_44 ;
switch ( V_35 [ V_4 ] . V_44 ) {
case V_48 :
V_37 -> V_49 . V_50 = V_35 [ V_4 ] . V_51 ;
break;
case V_45 :
V_37 -> V_49 . V_52 = V_35 [ V_4 ] . V_51 ;
break;
case V_46 :
V_37 -> V_49 . V_53 = V_35 [ V_4 ] . V_51 ;
break;
case V_47 :
V_37 -> V_49 . V_54 = V_35 [ V_4 ] . V_51 ;
break;
case V_55 :
V_37 -> V_49 . V_56 = V_35 [ V_4 ] . V_51 ;
break;
case V_57 :
V_37 -> V_49 . V_58 = V_35 [ V_4 ] . V_51 ;
break;
case V_59 :
V_37 -> V_49 . V_60 = V_35 [ V_4 ] . V_51 ;
break;
}
V_37 -> V_61 = V_35 [ V_4 ] . V_61 ;
V_37 -> V_62 = V_35 [ V_4 ] . V_62 ;
if ( V_35 [ V_4 ] . V_72 )
* V_38 = V_33 -> V_73 ;
V_70 = 1 ;
}
if ( V_70 )
return V_41 ;
V_37 -> V_44 = V_65 ;
V_37 -> V_61 = V_66 ;
V_37 -> V_62 = V_67 ;
return 0 ;
}
static long F_19 ( struct V_32 * V_33 )
{
long V_41 = 0 ;
if ( V_74 . V_75 ) {
if ( V_74 . V_75 ( V_33 ) )
V_41 = 1 ;
}
return V_41 ;
}
static long F_20 ( struct V_32 * V_33 ,
const struct V_68 V_76 [] ,
const struct V_34 V_77 [] )
{
struct V_36 V_37 = { 0 } ;
T_1 V_38 ;
T_1 V_39 = V_33 -> V_40 ;
long V_41 ;
if ( F_21 ( V_39 ) )
V_41 = F_18 ( V_33 , V_76 , & V_37 , & V_38 ) ;
else
V_41 = F_17 ( V_33 , V_77 , & V_37 , & V_38 ) ;
if ( ! V_41 && V_37 . V_44 == V_48 )
V_41 = F_19 ( V_33 ) ;
F_22 ( V_33 , V_41 , & V_37 , V_33 -> V_64 , V_38 ) ;
return V_41 ;
}
long F_23 ( struct V_32 * V_33 )
{
V_33 -> V_69 &= 0x0000ffff ;
return F_20 ( V_33 , V_78 , V_79 ) ;
}
long F_24 ( struct V_32 * V_33 )
{
return F_20 ( V_33 , V_80 , V_81 ) ;
}
long F_25 ( struct V_32 * V_33 )
{
return F_20 ( V_33 , V_82 , V_83 ) ;
}
