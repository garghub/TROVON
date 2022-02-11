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
V_17 = & F_8 ( V_16 ) ;
for ( V_20 = 0 ; V_20 <= V_24 -> V_25 ; ++ V_20 ) {
struct V_26 * V_27 = V_17 -> V_28 [ V_20 ] ;
struct V_29 * V_30 ;
if ( ! F_9 ( V_20 , V_17 -> V_31 ) )
continue;
if ( ! F_3 ( V_2 , V_20 ) )
continue;
V_30 = & V_27 -> V_32 ;
F_10 ( V_27 , V_30 , V_20 , 1 ) ;
V_15 . V_33 = V_27 -> V_32 . V_34 ;
if ( ! F_11 ( V_27 , V_30 , V_20 ) )
continue;
if ( F_12 ( V_27 , 0 , & V_15 , V_19 ) )
V_24 -> V_35 ( V_30 , V_20 ) ;
}
F_13 () ;
V_2 = F_1 () | V_21 ;
F_2 ( V_2 ) ;
return V_36 ;
}
static void
F_14 ( struct V_29 * V_30 , int V_20 )
{
unsigned long V_1 , V_37 , V_38 , V_39 ;
switch ( V_20 ) {
case V_6 :
V_37 = 0 ;
V_38 = V_40 ;
break;
case V_8 :
V_37 = V_41 ;
V_38 = ( V_30 -> V_42 << V_43 ) |
V_44 ;
break;
case V_10 :
V_37 = V_45 ;
V_38 = ( V_30 -> V_42 << V_46 ) |
V_47 ;
break;
default:
F_4 ( 1 , L_1 , V_20 ) ;
return;
}
F_15 ( & V_48 , V_39 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_37 ;
V_1 |= V_38 ;
F_2 ( V_1 ) ;
F_16 ( & V_48 , V_39 ) ;
}
static void
F_17 ( struct V_29 * V_30 , int V_20 )
{
unsigned long V_1 , V_37 , V_38 , V_39 ;
switch ( V_20 ) {
case V_6 :
V_37 = V_40 ;
V_38 = 0 ;
break;
case V_8 :
V_37 = V_44 | V_41 ;
V_38 = V_49 << V_43 ;
break;
case V_10 :
V_37 = V_47 | V_45 ;
V_38 = V_49 << V_46 ;
break;
default:
F_4 ( 1 , L_1 , V_20 ) ;
return;
}
F_15 ( & V_48 , V_39 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_37 ;
V_1 |= V_38 ;
F_2 ( V_1 ) ;
F_16 ( & V_48 , V_39 ) ;
}
static int
F_18 ( struct V_16 * V_17 ,
struct V_29 * V_27 )
{
if ( V_50 == V_27 -> V_42 ) {
if ( F_19 ( V_6 , V_17 -> V_51 ) )
return - V_52 ;
return V_6 ;
} else {
if ( ! F_19 ( V_10 , V_17 -> V_51 ) )
return V_10 ;
if ( ! F_19 ( V_8 , V_17 -> V_51 ) )
return V_8 ;
return - V_52 ;
}
}
static void
F_20 ( void )
{
unsigned long V_39 , V_1 ;
F_15 ( & V_48 , V_39 ) ;
V_1 = F_1 () ;
V_1 |= V_21 ;
F_2 ( V_1 ) ;
F_16 ( & V_48 , V_39 ) ;
}
static void
F_21 ( void )
{
unsigned long V_39 , V_1 ;
F_15 ( & V_48 , V_39 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_21 ;
F_2 ( V_1 ) ;
F_16 ( & V_48 , V_39 ) ;
}
static inline T_1
F_22 ( int V_4 )
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
F_23 ( int V_4 , T_1 V_1 )
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
static const struct V_53 * T_3 F_24 ( void )
{
return & V_54 ;
}
static inline T_1
F_25 ( void )
{
T_1 V_1 ;
asm volatile("mrc p14, 0, %0, c0, c1, 0" : "=r" (val));
return V_1 & 0xff000009 ;
}
static inline void
F_26 ( T_1 V_1 )
{
V_1 &= 0xf ;
asm volatile("mcr p14, 0, %0, c0, c1, 0" : : "r" (val));
}
static inline T_1
F_27 ( void )
{
T_1 V_1 ;
asm volatile("mrc p14, 0, %0, c5, c1, 0" : "=r" (val));
return V_1 ;
}
static inline void
F_28 ( T_1 V_1 )
{
asm volatile("mcr p14, 0, %0, c5, c1, 0" : : "r" (val));
}
static inline T_1
F_29 ( void )
{
T_1 V_1 ;
asm volatile("mrc p14, 0, %0, c8, c1, 0" : "=r" (val));
return V_1 ;
}
static inline void
F_30 ( T_1 V_1 )
{
asm volatile("mcr p14, 0, %0, c8, c1, 0" : : "r"(val));
}
static inline T_1
F_31 ( void )
{
T_1 V_1 ;
asm volatile("mrc p14, 0, %0, c4, c1, 0" : "=r" (val));
return V_1 ;
}
static void
F_32 ( T_1 V_1 )
{
asm volatile("mcr p14, 0, %0, c4, c1, 0" : : "r" (val));
}
static inline int
F_33 ( unsigned long V_55 ,
enum V_3 V_4 )
{
int V_5 = 0 ;
switch ( V_4 ) {
case V_6 :
V_5 = V_55 & V_56 ;
break;
case V_8 :
V_5 = V_55 & V_57 ;
break;
case V_10 :
V_5 = V_55 & V_58 ;
break;
case V_59 :
V_5 = V_55 & V_60 ;
break;
case V_61 :
V_5 = V_55 & V_62 ;
break;
default:
F_4 ( 1 , L_1 , V_4 ) ;
}
return V_5 ;
}
static T_2
F_34 ( int V_12 , void * V_13 )
{
unsigned long V_2 , V_55 ;
struct V_14 V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
int V_20 ;
V_2 = F_25 () ;
F_26 ( V_2 & ~ V_21 ) ;
V_55 = F_27 () ;
if ( ! ( V_55 & V_63 ) )
return V_23 ;
F_28 ( V_55 ) ;
V_19 = F_6 () ;
F_7 ( & V_15 , 0 ) ;
V_17 = & F_8 ( V_16 ) ;
for ( V_20 = 0 ; V_20 <= V_24 -> V_25 ; ++ V_20 ) {
struct V_26 * V_27 = V_17 -> V_28 [ V_20 ] ;
struct V_29 * V_30 ;
if ( ! F_9 ( V_20 , V_17 -> V_31 ) )
continue;
if ( ! F_33 ( V_2 , V_20 ) )
continue;
V_30 = & V_27 -> V_32 ;
F_10 ( V_27 , V_30 , V_20 , 1 ) ;
V_15 . V_33 = V_27 -> V_32 . V_34 ;
if ( ! F_11 ( V_27 , V_30 , V_20 ) )
continue;
if ( F_12 ( V_27 , 0 , & V_15 , V_19 ) )
V_24 -> V_35 ( V_30 , V_20 ) ;
}
F_13 () ;
V_2 = F_25 () | V_21 ;
F_26 ( V_2 ) ;
return V_36 ;
}
static void
F_35 ( struct V_29 * V_30 , int V_20 )
{
unsigned long V_39 , V_64 , V_65 ;
V_64 = F_31 () ;
V_65 = F_29 () ;
switch ( V_20 ) {
case V_6 :
V_64 |= V_66 ;
break;
case V_8 :
V_64 |= V_67 ;
V_65 &= ~ V_68 ;
V_65 |= V_30 -> V_42 << V_69 ;
break;
case V_10 :
V_64 |= V_70 ;
V_65 &= ~ V_71 ;
V_65 |= V_30 -> V_42 << V_72 ;
break;
case V_59 :
V_64 |= V_73 ;
V_65 &= ~ V_74 ;
V_65 |= V_30 -> V_42 << V_75 ;
break;
case V_61 :
V_64 |= V_76 ;
V_65 &= ~ V_77 ;
V_65 |= V_30 -> V_42 << V_78 ;
break;
default:
F_4 ( 1 , L_1 , V_20 ) ;
return;
}
F_15 ( & V_48 , V_39 ) ;
F_30 ( V_65 ) ;
F_32 ( V_64 ) ;
F_16 ( & V_48 , V_39 ) ;
}
static void
F_36 ( struct V_29 * V_30 , int V_20 )
{
unsigned long V_39 , V_64 , V_65 ;
V_64 = F_31 () ;
V_65 = F_29 () ;
switch ( V_20 ) {
case V_6 :
V_64 &= ~ V_66 ;
break;
case V_8 :
V_64 &= ~ V_67 ;
V_65 &= ~ V_68 ;
V_65 |= V_49 << V_69 ;
break;
case V_10 :
V_64 &= ~ V_70 ;
V_65 &= ~ V_71 ;
V_65 |= V_49 << V_72 ;
break;
case V_59 :
V_64 &= ~ V_73 ;
V_65 &= ~ V_74 ;
V_65 |= V_49 << V_75 ;
break;
case V_61 :
V_64 &= ~ V_76 ;
V_65 &= ~ V_77 ;
V_65 |= V_49 << V_78 ;
break;
default:
F_4 ( 1 , L_1 , V_20 ) ;
return;
}
F_15 ( & V_48 , V_39 ) ;
F_30 ( V_65 ) ;
F_32 ( V_64 ) ;
F_16 ( & V_48 , V_39 ) ;
}
static int
F_37 ( struct V_16 * V_17 ,
struct V_29 * V_27 )
{
int V_20 = F_18 ( V_17 , V_27 ) ;
if ( V_20 >= 0 )
goto V_79;
if ( ! F_19 ( V_61 , V_17 -> V_51 ) )
V_20 = V_61 ;
else if ( ! F_19 ( V_59 , V_17 -> V_51 ) )
V_20 = V_59 ;
V_79:
return V_20 ;
}
static void
F_38 ( void )
{
unsigned long V_39 , V_1 ;
F_15 ( & V_48 , V_39 ) ;
V_1 = F_25 () & ~ V_80 ;
V_1 |= V_21 ;
F_26 ( V_1 ) ;
F_16 ( & V_48 , V_39 ) ;
}
static void
F_39 ( void )
{
unsigned long V_39 , V_1 ;
F_15 ( & V_48 , V_39 ) ;
V_1 = F_25 () ;
V_1 &= ~ V_21 ;
F_26 ( V_1 ) ;
F_16 ( & V_48 , V_39 ) ;
}
static inline T_1
F_40 ( int V_4 )
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
case V_59 :
asm volatile("mrc p14, 0, %0, c2, c2, 0" : "=r" (val));
break;
case V_61 :
asm volatile("mrc p14, 0, %0, c3, c2, 0" : "=r" (val));
break;
}
return V_1 ;
}
static inline void
F_41 ( int V_4 , T_1 V_1 )
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
case V_59 :
asm volatile("mcr p14, 0, %0, c2, c2, 0" : : "r" (val));
break;
case V_61 :
asm volatile("mcr p14, 0, %0, c3, c2, 0" : : "r" (val));
break;
}
}
static const struct V_53 * T_3 F_42 ( void )
{
return & V_81 ;
}
static const struct V_53 * T_3 F_24 ( void )
{
return NULL ;
}
static const struct V_53 * T_3 F_42 ( void )
{
return NULL ;
}
