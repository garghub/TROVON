static inline T_1
F_1 ( void )
{
T_1 V_1 ;
asm volatile("mrc p14, 0, %0, c0, c0, 0" : "=r" (val));
return V_1 ;
}
static inline void
F_2 ( T_1 V_1 )
{
V_1 &= 0xffff77f ;
asm volatile("mcr p14, 0, %0, c0, c0, 0" : : "r" (val));
}
static inline int
F_3 ( unsigned long V_2 ,
enum V_3 V_4 )
{
int V_5 = 0 ;
switch ( V_4 ) {
case V_6 :
V_5 = V_2 & V_7 ;
break;
case V_8 :
V_5 = V_2 & V_9 ;
break;
case V_10 :
V_5 = V_2 & V_11 ;
break;
default:
F_4 ( 1 , L_1 , V_4 ) ;
}
return V_5 ;
}
static T_2
F_5 ( int V_12 , void * V_13 )
{
unsigned long V_2 ;
struct V_14 V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
int V_20 ;
V_2 = F_1 () ;
F_2 ( V_2 & ~ V_21 ) ;
if ( ! ( V_2 & V_22 ) )
return V_23 ;
V_19 = F_6 () ;
V_17 = & F_7 ( V_24 ) ;
for ( V_20 = 0 ; V_20 < V_25 -> V_26 ; ++ V_20 ) {
struct V_27 * V_28 = V_17 -> V_29 [ V_20 ] ;
struct V_30 * V_31 ;
if ( ! V_28 )
continue;
if ( ! F_3 ( V_2 , V_20 ) )
continue;
V_31 = & V_28 -> V_32 ;
F_8 ( V_28 , V_31 , V_20 ) ;
F_9 ( & V_15 , 0 , V_31 -> V_33 ) ;
if ( ! F_10 ( V_28 , V_31 , V_20 ) )
continue;
if ( F_11 ( V_28 , & V_15 , V_19 ) )
V_25 -> V_34 ( V_31 , V_20 ) ;
}
F_12 () ;
V_2 = F_1 () | V_21 ;
F_2 ( V_2 ) ;
return V_35 ;
}
static void
F_13 ( struct V_30 * V_31 , int V_20 )
{
unsigned long V_1 , V_36 , V_37 , V_38 ;
struct V_16 * V_29 = V_25 -> V_39 () ;
switch ( V_20 ) {
case V_6 :
V_36 = 0 ;
V_37 = V_40 ;
break;
case V_8 :
V_36 = V_41 ;
V_37 = ( V_31 -> V_42 << V_43 ) |
V_44 ;
break;
case V_10 :
V_36 = V_45 ;
V_37 = ( V_31 -> V_42 << V_46 ) |
V_47 ;
break;
default:
F_4 ( 1 , L_1 , V_20 ) ;
return;
}
F_14 ( & V_29 -> V_48 , V_38 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_36 ;
V_1 |= V_37 ;
F_2 ( V_1 ) ;
F_15 ( & V_29 -> V_48 , V_38 ) ;
}
static void
F_16 ( struct V_30 * V_31 , int V_20 )
{
unsigned long V_1 , V_36 , V_37 , V_38 ;
struct V_16 * V_29 = V_25 -> V_39 () ;
switch ( V_20 ) {
case V_6 :
V_36 = V_40 ;
V_37 = 0 ;
break;
case V_8 :
V_36 = V_44 | V_41 ;
V_37 = V_49 << V_43 ;
break;
case V_10 :
V_36 = V_47 | V_45 ;
V_37 = V_49 << V_46 ;
break;
default:
F_4 ( 1 , L_1 , V_20 ) ;
return;
}
F_14 ( & V_29 -> V_48 , V_38 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_36 ;
V_1 |= V_37 ;
F_2 ( V_1 ) ;
F_15 ( & V_29 -> V_48 , V_38 ) ;
}
static int
F_17 ( struct V_16 * V_17 ,
struct V_30 * V_28 )
{
if ( V_50 == V_28 -> V_42 ) {
if ( F_18 ( V_6 , V_17 -> V_51 ) )
return - V_52 ;
return V_6 ;
} else {
if ( ! F_18 ( V_10 , V_17 -> V_51 ) )
return V_10 ;
if ( ! F_18 ( V_8 , V_17 -> V_51 ) )
return V_8 ;
return - V_52 ;
}
}
static void
F_19 ( void )
{
unsigned long V_38 , V_1 ;
struct V_16 * V_29 = V_25 -> V_39 () ;
F_14 ( & V_29 -> V_48 , V_38 ) ;
V_1 = F_1 () ;
V_1 |= V_21 ;
F_2 ( V_1 ) ;
F_15 ( & V_29 -> V_48 , V_38 ) ;
}
static void
F_20 ( void )
{
unsigned long V_38 , V_1 ;
struct V_16 * V_29 = V_25 -> V_39 () ;
F_14 ( & V_29 -> V_48 , V_38 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_21 ;
F_2 ( V_1 ) ;
F_15 ( & V_29 -> V_48 , V_38 ) ;
}
static inline T_1
F_21 ( int V_4 )
{
T_1 V_1 = 0 ;
switch ( V_4 ) {
case V_6 :
asm volatile("mrc p14, 0, %0, c1, c0, 0" : "=r" (val));
break;
case V_8 :
asm volatile("mrc p14, 0, %0, c2, c0, 0" : "=r" (val));
break;
case V_10 :
asm volatile("mrc p14, 0, %0, c3, c0, 0" : "=r" (val));
break;
}
return V_1 ;
}
static inline void
F_22 ( int V_4 , T_1 V_1 )
{
switch ( V_4 ) {
case V_6 :
asm volatile("mcr p14, 0, %0, c1, c0, 0" : : "r" (val));
break;
case V_8 :
asm volatile("mcr p14, 0, %0, c2, c0, 0" : : "r" (val));
break;
case V_10 :
asm volatile("mcr p14, 0, %0, c3, c0, 0" : : "r" (val));
break;
}
}
static int F_23 ( struct V_27 * V_28 )
{
return F_24 ( V_28 , & V_53 ,
& V_54 , 0xFF ) ;
}
static struct V_55 * T_3 F_25 ( void )
{
return & V_56 ;
}
static inline T_1
F_26 ( void )
{
T_1 V_1 ;
asm volatile("mrc p14, 0, %0, c0, c1, 0" : "=r" (val));
return V_1 & 0xff000009 ;
}
static inline void
F_27 ( T_1 V_1 )
{
V_1 &= 0xf ;
asm volatile("mcr p14, 0, %0, c0, c1, 0" : : "r" (val));
}
static inline T_1
F_28 ( void )
{
T_1 V_1 ;
asm volatile("mrc p14, 0, %0, c5, c1, 0" : "=r" (val));
return V_1 ;
}
static inline void
F_29 ( T_1 V_1 )
{
asm volatile("mcr p14, 0, %0, c5, c1, 0" : : "r" (val));
}
static inline T_1
F_30 ( void )
{
T_1 V_1 ;
asm volatile("mrc p14, 0, %0, c8, c1, 0" : "=r" (val));
return V_1 ;
}
static inline void
F_31 ( T_1 V_1 )
{
asm volatile("mcr p14, 0, %0, c8, c1, 0" : : "r"(val));
}
static inline T_1
F_32 ( void )
{
T_1 V_1 ;
asm volatile("mrc p14, 0, %0, c4, c1, 0" : "=r" (val));
return V_1 ;
}
static void
F_33 ( T_1 V_1 )
{
asm volatile("mcr p14, 0, %0, c4, c1, 0" : : "r" (val));
}
static inline int
F_34 ( unsigned long V_57 ,
enum V_3 V_4 )
{
int V_5 = 0 ;
switch ( V_4 ) {
case V_6 :
V_5 = V_57 & V_58 ;
break;
case V_8 :
V_5 = V_57 & V_59 ;
break;
case V_10 :
V_5 = V_57 & V_60 ;
break;
case V_61 :
V_5 = V_57 & V_62 ;
break;
case V_63 :
V_5 = V_57 & V_64 ;
break;
default:
F_4 ( 1 , L_1 , V_4 ) ;
}
return V_5 ;
}
static T_2
F_35 ( int V_12 , void * V_13 )
{
unsigned long V_2 , V_57 ;
struct V_14 V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
int V_20 ;
V_2 = F_26 () ;
F_27 ( V_2 & ~ V_21 ) ;
V_57 = F_28 () ;
if ( ! ( V_57 & V_65 ) )
return V_23 ;
F_29 ( V_57 ) ;
V_19 = F_6 () ;
V_17 = & F_7 ( V_24 ) ;
for ( V_20 = 0 ; V_20 < V_25 -> V_26 ; ++ V_20 ) {
struct V_27 * V_28 = V_17 -> V_29 [ V_20 ] ;
struct V_30 * V_31 ;
if ( ! V_28 )
continue;
if ( ! F_34 ( V_57 , V_20 ) )
continue;
V_31 = & V_28 -> V_32 ;
F_8 ( V_28 , V_31 , V_20 ) ;
F_9 ( & V_15 , 0 , V_31 -> V_33 ) ;
if ( ! F_10 ( V_28 , V_31 , V_20 ) )
continue;
if ( F_11 ( V_28 , & V_15 , V_19 ) )
V_25 -> V_34 ( V_31 , V_20 ) ;
}
F_12 () ;
V_2 = F_26 () | V_21 ;
F_27 ( V_2 ) ;
return V_35 ;
}
static void
F_36 ( struct V_30 * V_31 , int V_20 )
{
unsigned long V_38 , V_66 , V_67 ;
struct V_16 * V_29 = V_25 -> V_39 () ;
V_66 = F_32 () ;
V_67 = F_30 () ;
switch ( V_20 ) {
case V_6 :
V_66 |= V_68 ;
break;
case V_8 :
V_66 |= V_69 ;
V_67 &= ~ V_70 ;
V_67 |= V_31 -> V_42 << V_71 ;
break;
case V_10 :
V_66 |= V_72 ;
V_67 &= ~ V_73 ;
V_67 |= V_31 -> V_42 << V_74 ;
break;
case V_61 :
V_66 |= V_75 ;
V_67 &= ~ V_76 ;
V_67 |= V_31 -> V_42 << V_77 ;
break;
case V_63 :
V_66 |= V_78 ;
V_67 &= ~ V_79 ;
V_67 |= V_31 -> V_42 << V_80 ;
break;
default:
F_4 ( 1 , L_1 , V_20 ) ;
return;
}
F_14 ( & V_29 -> V_48 , V_38 ) ;
F_31 ( V_67 ) ;
F_33 ( V_66 ) ;
F_15 ( & V_29 -> V_48 , V_38 ) ;
}
static void
F_37 ( struct V_30 * V_31 , int V_20 )
{
unsigned long V_38 , V_66 , V_67 , V_57 ;
struct V_16 * V_29 = V_25 -> V_39 () ;
V_66 = F_32 () ;
V_67 = F_30 () ;
switch ( V_20 ) {
case V_6 :
V_66 &= ~ V_68 ;
V_57 = V_58 ;
break;
case V_8 :
V_66 &= ~ V_69 ;
V_67 &= ~ V_70 ;
V_67 |= V_49 << V_71 ;
V_57 = V_59 ;
break;
case V_10 :
V_66 &= ~ V_72 ;
V_67 &= ~ V_73 ;
V_67 |= V_49 << V_74 ;
V_57 = V_60 ;
break;
case V_61 :
V_66 &= ~ V_75 ;
V_67 &= ~ V_76 ;
V_67 |= V_49 << V_77 ;
V_57 = V_62 ;
break;
case V_63 :
V_66 &= ~ V_78 ;
V_67 &= ~ V_79 ;
V_67 |= V_49 << V_80 ;
V_57 = V_64 ;
break;
default:
F_4 ( 1 , L_1 , V_20 ) ;
return;
}
F_14 ( & V_29 -> V_48 , V_38 ) ;
F_31 ( V_67 ) ;
F_33 ( V_66 ) ;
F_29 ( V_57 ) ;
F_15 ( & V_29 -> V_48 , V_38 ) ;
}
static int
F_38 ( struct V_16 * V_17 ,
struct V_30 * V_28 )
{
int V_20 = F_17 ( V_17 , V_28 ) ;
if ( V_20 >= 0 )
goto V_81;
if ( ! F_18 ( V_63 , V_17 -> V_51 ) )
V_20 = V_63 ;
else if ( ! F_18 ( V_61 , V_17 -> V_51 ) )
V_20 = V_61 ;
V_81:
return V_20 ;
}
static void
F_39 ( void )
{
unsigned long V_38 , V_1 ;
struct V_16 * V_29 = V_25 -> V_39 () ;
F_14 ( & V_29 -> V_48 , V_38 ) ;
V_1 = F_26 () & ~ V_82 ;
V_1 |= V_21 ;
F_27 ( V_1 ) ;
F_15 ( & V_29 -> V_48 , V_38 ) ;
}
static void
F_40 ( void )
{
unsigned long V_38 , V_1 ;
struct V_16 * V_29 = V_25 -> V_39 () ;
F_14 ( & V_29 -> V_48 , V_38 ) ;
V_1 = F_26 () ;
V_1 &= ~ V_21 ;
F_27 ( V_1 ) ;
F_15 ( & V_29 -> V_48 , V_38 ) ;
}
static inline T_1
F_41 ( int V_4 )
{
T_1 V_1 = 0 ;
switch ( V_4 ) {
case V_6 :
asm volatile("mrc p14, 0, %0, c1, c1, 0" : "=r" (val));
break;
case V_8 :
asm volatile("mrc p14, 0, %0, c0, c2, 0" : "=r" (val));
break;
case V_10 :
asm volatile("mrc p14, 0, %0, c1, c2, 0" : "=r" (val));
break;
case V_61 :
asm volatile("mrc p14, 0, %0, c2, c2, 0" : "=r" (val));
break;
case V_63 :
asm volatile("mrc p14, 0, %0, c3, c2, 0" : "=r" (val));
break;
}
return V_1 ;
}
static inline void
F_42 ( int V_4 , T_1 V_1 )
{
switch ( V_4 ) {
case V_6 :
asm volatile("mcr p14, 0, %0, c1, c1, 0" : : "r" (val));
break;
case V_8 :
asm volatile("mcr p14, 0, %0, c0, c2, 0" : : "r" (val));
break;
case V_10 :
asm volatile("mcr p14, 0, %0, c1, c2, 0" : : "r" (val));
break;
case V_61 :
asm volatile("mcr p14, 0, %0, c2, c2, 0" : : "r" (val));
break;
case V_63 :
asm volatile("mcr p14, 0, %0, c3, c2, 0" : : "r" (val));
break;
}
}
static struct V_55 * T_3 F_43 ( void )
{
return & V_83 ;
}
static struct V_55 * T_3 F_25 ( void )
{
return NULL ;
}
static struct V_55 * T_3 F_43 ( void )
{
return NULL ;
}
