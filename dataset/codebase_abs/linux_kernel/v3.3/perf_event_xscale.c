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
F_7 ( & V_15 , 0 ) ;
V_17 = & F_8 ( V_24 ) ;
for ( V_20 = 0 ; V_20 < V_25 -> V_26 ; ++ V_20 ) {
struct V_27 * V_28 = V_17 -> V_29 [ V_20 ] ;
struct V_30 * V_31 ;
if ( ! V_28 )
continue;
if ( ! F_3 ( V_2 , V_20 ) )
continue;
V_31 = & V_28 -> V_32 ;
F_9 ( V_28 , V_31 , V_20 ) ;
V_15 . V_33 = V_28 -> V_32 . V_34 ;
if ( ! F_10 ( V_28 , V_31 , V_20 ) )
continue;
if ( F_11 ( V_28 , & V_15 , V_19 ) )
V_25 -> V_35 ( V_31 , V_20 ) ;
}
F_12 () ;
V_2 = F_1 () | V_21 ;
F_2 ( V_2 ) ;
return V_36 ;
}
static void
F_13 ( struct V_30 * V_31 , int V_20 )
{
unsigned long V_1 , V_37 , V_38 , V_39 ;
struct V_16 * V_29 = V_25 -> V_40 () ;
switch ( V_20 ) {
case V_6 :
V_37 = 0 ;
V_38 = V_41 ;
break;
case V_8 :
V_37 = V_42 ;
V_38 = ( V_31 -> V_43 << V_44 ) |
V_45 ;
break;
case V_10 :
V_37 = V_46 ;
V_38 = ( V_31 -> V_43 << V_47 ) |
V_48 ;
break;
default:
F_4 ( 1 , L_1 , V_20 ) ;
return;
}
F_14 ( & V_29 -> V_49 , V_39 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_37 ;
V_1 |= V_38 ;
F_2 ( V_1 ) ;
F_15 ( & V_29 -> V_49 , V_39 ) ;
}
static void
F_16 ( struct V_30 * V_31 , int V_20 )
{
unsigned long V_1 , V_37 , V_38 , V_39 ;
struct V_16 * V_29 = V_25 -> V_40 () ;
switch ( V_20 ) {
case V_6 :
V_37 = V_41 ;
V_38 = 0 ;
break;
case V_8 :
V_37 = V_45 | V_42 ;
V_38 = V_50 << V_44 ;
break;
case V_10 :
V_37 = V_48 | V_46 ;
V_38 = V_50 << V_47 ;
break;
default:
F_4 ( 1 , L_1 , V_20 ) ;
return;
}
F_14 ( & V_29 -> V_49 , V_39 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_37 ;
V_1 |= V_38 ;
F_2 ( V_1 ) ;
F_15 ( & V_29 -> V_49 , V_39 ) ;
}
static int
F_17 ( struct V_16 * V_17 ,
struct V_30 * V_28 )
{
if ( V_51 == V_28 -> V_43 ) {
if ( F_18 ( V_6 , V_17 -> V_52 ) )
return - V_53 ;
return V_6 ;
} else {
if ( ! F_18 ( V_10 , V_17 -> V_52 ) )
return V_10 ;
if ( ! F_18 ( V_8 , V_17 -> V_52 ) )
return V_8 ;
return - V_53 ;
}
}
static void
F_19 ( void )
{
unsigned long V_39 , V_1 ;
struct V_16 * V_29 = V_25 -> V_40 () ;
F_14 ( & V_29 -> V_49 , V_39 ) ;
V_1 = F_1 () ;
V_1 |= V_21 ;
F_2 ( V_1 ) ;
F_15 ( & V_29 -> V_49 , V_39 ) ;
}
static void
F_20 ( void )
{
unsigned long V_39 , V_1 ;
struct V_16 * V_29 = V_25 -> V_40 () ;
F_14 ( & V_29 -> V_49 , V_39 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_21 ;
F_2 ( V_1 ) ;
F_15 ( & V_29 -> V_49 , V_39 ) ;
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
return F_24 ( V_28 , & V_54 ,
& V_55 , 0xFF ) ;
}
static struct V_56 * T_3 F_25 ( void )
{
return & V_57 ;
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
F_34 ( unsigned long V_58 ,
enum V_3 V_4 )
{
int V_5 = 0 ;
switch ( V_4 ) {
case V_6 :
V_5 = V_58 & V_59 ;
break;
case V_8 :
V_5 = V_58 & V_60 ;
break;
case V_10 :
V_5 = V_58 & V_61 ;
break;
case V_62 :
V_5 = V_58 & V_63 ;
break;
case V_64 :
V_5 = V_58 & V_65 ;
break;
default:
F_4 ( 1 , L_1 , V_4 ) ;
}
return V_5 ;
}
static T_2
F_35 ( int V_12 , void * V_13 )
{
unsigned long V_2 , V_58 ;
struct V_14 V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
int V_20 ;
V_2 = F_26 () ;
F_27 ( V_2 & ~ V_21 ) ;
V_58 = F_28 () ;
if ( ! ( V_58 & V_66 ) )
return V_23 ;
F_29 ( V_58 ) ;
V_19 = F_6 () ;
F_7 ( & V_15 , 0 ) ;
V_17 = & F_8 ( V_24 ) ;
for ( V_20 = 0 ; V_20 < V_25 -> V_26 ; ++ V_20 ) {
struct V_27 * V_28 = V_17 -> V_29 [ V_20 ] ;
struct V_30 * V_31 ;
if ( ! V_28 )
continue;
if ( ! F_34 ( V_58 , V_20 ) )
continue;
V_31 = & V_28 -> V_32 ;
F_9 ( V_28 , V_31 , V_20 ) ;
V_15 . V_33 = V_28 -> V_32 . V_34 ;
if ( ! F_10 ( V_28 , V_31 , V_20 ) )
continue;
if ( F_11 ( V_28 , & V_15 , V_19 ) )
V_25 -> V_35 ( V_31 , V_20 ) ;
}
F_12 () ;
V_2 = F_26 () | V_21 ;
F_27 ( V_2 ) ;
return V_36 ;
}
static void
F_36 ( struct V_30 * V_31 , int V_20 )
{
unsigned long V_39 , V_67 , V_68 ;
struct V_16 * V_29 = V_25 -> V_40 () ;
V_67 = F_32 () ;
V_68 = F_30 () ;
switch ( V_20 ) {
case V_6 :
V_67 |= V_69 ;
break;
case V_8 :
V_67 |= V_70 ;
V_68 &= ~ V_71 ;
V_68 |= V_31 -> V_43 << V_72 ;
break;
case V_10 :
V_67 |= V_73 ;
V_68 &= ~ V_74 ;
V_68 |= V_31 -> V_43 << V_75 ;
break;
case V_62 :
V_67 |= V_76 ;
V_68 &= ~ V_77 ;
V_68 |= V_31 -> V_43 << V_78 ;
break;
case V_64 :
V_67 |= V_79 ;
V_68 &= ~ V_80 ;
V_68 |= V_31 -> V_43 << V_81 ;
break;
default:
F_4 ( 1 , L_1 , V_20 ) ;
return;
}
F_14 ( & V_29 -> V_49 , V_39 ) ;
F_31 ( V_68 ) ;
F_33 ( V_67 ) ;
F_15 ( & V_29 -> V_49 , V_39 ) ;
}
static void
F_37 ( struct V_30 * V_31 , int V_20 )
{
unsigned long V_39 , V_67 , V_68 , V_58 ;
struct V_16 * V_29 = V_25 -> V_40 () ;
V_67 = F_32 () ;
V_68 = F_30 () ;
switch ( V_20 ) {
case V_6 :
V_67 &= ~ V_69 ;
V_58 = V_59 ;
break;
case V_8 :
V_67 &= ~ V_70 ;
V_68 &= ~ V_71 ;
V_68 |= V_50 << V_72 ;
V_58 = V_60 ;
break;
case V_10 :
V_67 &= ~ V_73 ;
V_68 &= ~ V_74 ;
V_68 |= V_50 << V_75 ;
V_58 = V_61 ;
break;
case V_62 :
V_67 &= ~ V_76 ;
V_68 &= ~ V_77 ;
V_68 |= V_50 << V_78 ;
V_58 = V_63 ;
break;
case V_64 :
V_67 &= ~ V_79 ;
V_68 &= ~ V_80 ;
V_68 |= V_50 << V_81 ;
V_58 = V_65 ;
break;
default:
F_4 ( 1 , L_1 , V_20 ) ;
return;
}
F_14 ( & V_29 -> V_49 , V_39 ) ;
F_31 ( V_68 ) ;
F_33 ( V_67 ) ;
F_29 ( V_58 ) ;
F_15 ( & V_29 -> V_49 , V_39 ) ;
}
static int
F_38 ( struct V_16 * V_17 ,
struct V_30 * V_28 )
{
int V_20 = F_17 ( V_17 , V_28 ) ;
if ( V_20 >= 0 )
goto V_82;
if ( ! F_18 ( V_64 , V_17 -> V_52 ) )
V_20 = V_64 ;
else if ( ! F_18 ( V_62 , V_17 -> V_52 ) )
V_20 = V_62 ;
V_82:
return V_20 ;
}
static void
F_39 ( void )
{
unsigned long V_39 , V_1 ;
struct V_16 * V_29 = V_25 -> V_40 () ;
F_14 ( & V_29 -> V_49 , V_39 ) ;
V_1 = F_26 () & ~ V_83 ;
V_1 |= V_21 ;
F_27 ( V_1 ) ;
F_15 ( & V_29 -> V_49 , V_39 ) ;
}
static void
F_40 ( void )
{
unsigned long V_39 , V_1 ;
struct V_16 * V_29 = V_25 -> V_40 () ;
F_14 ( & V_29 -> V_49 , V_39 ) ;
V_1 = F_26 () ;
V_1 &= ~ V_21 ;
F_27 ( V_1 ) ;
F_15 ( & V_29 -> V_49 , V_39 ) ;
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
case V_62 :
asm volatile("mrc p14, 0, %0, c2, c2, 0" : "=r" (val));
break;
case V_64 :
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
case V_62 :
asm volatile("mcr p14, 0, %0, c2, c2, 0" : : "r" (val));
break;
case V_64 :
asm volatile("mcr p14, 0, %0, c3, c2, 0" : : "r" (val));
break;
}
}
static struct V_56 * T_3 F_43 ( void )
{
return & V_84 ;
}
static struct V_56 * T_3 F_25 ( void )
{
return NULL ;
}
static struct V_56 * T_3 F_43 ( void )
{
return NULL ;
}
