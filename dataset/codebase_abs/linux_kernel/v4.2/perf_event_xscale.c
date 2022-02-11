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
struct V_16 * V_17 = (struct V_16 * ) V_13 ;
struct V_18 * V_19 = F_6 ( V_17 -> V_20 ) ;
struct V_21 * V_22 ;
int V_23 ;
V_2 = F_1 () ;
F_2 ( V_2 & ~ V_24 ) ;
if ( ! ( V_2 & V_25 ) )
return V_26 ;
V_22 = F_7 () ;
for ( V_23 = 0 ; V_23 < V_17 -> V_27 ; ++ V_23 ) {
struct V_28 * V_29 = V_19 -> V_30 [ V_23 ] ;
struct V_31 * V_32 ;
if ( ! V_29 )
continue;
if ( ! F_3 ( V_2 , V_23 ) )
continue;
V_32 = & V_29 -> V_33 ;
F_8 ( V_29 ) ;
F_9 ( & V_15 , 0 , V_32 -> V_34 ) ;
if ( ! F_10 ( V_29 ) )
continue;
if ( F_11 ( V_29 , & V_15 , V_22 ) )
V_17 -> V_35 ( V_29 ) ;
}
F_12 () ;
V_2 = F_1 () | V_24 ;
F_2 ( V_2 ) ;
return V_36 ;
}
static void F_13 ( struct V_28 * V_29 )
{
unsigned long V_1 , V_37 , V_38 , V_39 ;
struct V_16 * V_17 = F_14 ( V_29 -> V_40 ) ;
struct V_31 * V_32 = & V_29 -> V_33 ;
struct V_18 * V_30 = F_6 ( V_17 -> V_20 ) ;
int V_23 = V_32 -> V_23 ;
switch ( V_23 ) {
case V_6 :
V_37 = 0 ;
V_38 = V_41 ;
break;
case V_8 :
V_37 = V_42 ;
V_38 = ( V_32 -> V_43 << V_44 ) |
V_45 ;
break;
case V_10 :
V_37 = V_46 ;
V_38 = ( V_32 -> V_43 << V_47 ) |
V_48 ;
break;
default:
F_4 ( 1 , L_1 , V_23 ) ;
return;
}
F_15 ( & V_30 -> V_49 , V_39 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_37 ;
V_1 |= V_38 ;
F_2 ( V_1 ) ;
F_16 ( & V_30 -> V_49 , V_39 ) ;
}
static void F_17 ( struct V_28 * V_29 )
{
unsigned long V_1 , V_37 , V_38 , V_39 ;
struct V_16 * V_17 = F_14 ( V_29 -> V_40 ) ;
struct V_31 * V_32 = & V_29 -> V_33 ;
struct V_18 * V_30 = F_6 ( V_17 -> V_20 ) ;
int V_23 = V_32 -> V_23 ;
switch ( V_23 ) {
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
F_4 ( 1 , L_1 , V_23 ) ;
return;
}
F_15 ( & V_30 -> V_49 , V_39 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_37 ;
V_1 |= V_38 ;
F_2 ( V_1 ) ;
F_16 ( & V_30 -> V_49 , V_39 ) ;
}
static int
F_18 ( struct V_18 * V_19 ,
struct V_28 * V_29 )
{
struct V_31 * V_32 = & V_29 -> V_33 ;
if ( V_51 == V_32 -> V_43 ) {
if ( F_19 ( V_6 , V_19 -> V_52 ) )
return - V_53 ;
return V_6 ;
} else {
if ( ! F_19 ( V_10 , V_19 -> V_52 ) )
return V_10 ;
if ( ! F_19 ( V_8 , V_19 -> V_52 ) )
return V_8 ;
return - V_53 ;
}
}
static void F_20 ( struct V_16 * V_17 )
{
unsigned long V_39 , V_1 ;
struct V_18 * V_30 = F_6 ( V_17 -> V_20 ) ;
F_15 ( & V_30 -> V_49 , V_39 ) ;
V_1 = F_1 () ;
V_1 |= V_24 ;
F_2 ( V_1 ) ;
F_16 ( & V_30 -> V_49 , V_39 ) ;
}
static void F_21 ( struct V_16 * V_17 )
{
unsigned long V_39 , V_1 ;
struct V_18 * V_30 = F_6 ( V_17 -> V_20 ) ;
F_15 ( & V_30 -> V_49 , V_39 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_24 ;
F_2 ( V_1 ) ;
F_16 ( & V_30 -> V_49 , V_39 ) ;
}
static inline T_1 F_22 ( struct V_28 * V_29 )
{
struct V_31 * V_32 = & V_29 -> V_33 ;
int V_4 = V_32 -> V_23 ;
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
static inline void F_23 ( struct V_28 * V_29 , T_1 V_1 )
{
struct V_31 * V_32 = & V_29 -> V_33 ;
int V_4 = V_32 -> V_23 ;
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
static int F_24 ( struct V_28 * V_29 )
{
return F_25 ( V_29 , & V_54 ,
& V_55 , 0xFF ) ;
}
static int F_26 ( struct V_16 * V_17 )
{
V_17 -> V_56 = L_2 ;
V_17 -> V_57 = F_5 ;
V_17 -> V_58 = F_13 ;
V_17 -> V_35 = F_17 ;
V_17 -> V_59 = F_22 ;
V_17 -> V_60 = F_23 ;
V_17 -> V_61 = F_18 ;
V_17 -> V_62 = F_20 ;
V_17 -> V_63 = F_21 ;
V_17 -> V_64 = F_24 ;
V_17 -> V_27 = 3 ;
V_17 -> V_65 = ( 1LLU << 32 ) - 1 ;
return 0 ;
}
static inline T_1
F_27 ( void )
{
T_1 V_1 ;
asm volatile("mrc p14, 0, %0, c0, c1, 0" : "=r" (val));
return V_1 & 0xff000009 ;
}
static inline void
F_28 ( T_1 V_1 )
{
V_1 &= 0xf ;
asm volatile("mcr p14, 0, %0, c0, c1, 0" : : "r" (val));
}
static inline T_1
F_29 ( void )
{
T_1 V_1 ;
asm volatile("mrc p14, 0, %0, c5, c1, 0" : "=r" (val));
return V_1 ;
}
static inline void
F_30 ( T_1 V_1 )
{
asm volatile("mcr p14, 0, %0, c5, c1, 0" : : "r" (val));
}
static inline T_1
F_31 ( void )
{
T_1 V_1 ;
asm volatile("mrc p14, 0, %0, c8, c1, 0" : "=r" (val));
return V_1 ;
}
static inline void
F_32 ( T_1 V_1 )
{
asm volatile("mcr p14, 0, %0, c8, c1, 0" : : "r"(val));
}
static inline T_1
F_33 ( void )
{
T_1 V_1 ;
asm volatile("mrc p14, 0, %0, c4, c1, 0" : "=r" (val));
return V_1 ;
}
static void
F_34 ( T_1 V_1 )
{
asm volatile("mcr p14, 0, %0, c4, c1, 0" : : "r" (val));
}
static inline int
F_35 ( unsigned long V_66 ,
enum V_3 V_4 )
{
int V_5 = 0 ;
switch ( V_4 ) {
case V_6 :
V_5 = V_66 & V_67 ;
break;
case V_8 :
V_5 = V_66 & V_68 ;
break;
case V_10 :
V_5 = V_66 & V_69 ;
break;
case V_70 :
V_5 = V_66 & V_71 ;
break;
case V_72 :
V_5 = V_66 & V_73 ;
break;
default:
F_4 ( 1 , L_1 , V_4 ) ;
}
return V_5 ;
}
static T_2
F_36 ( int V_12 , void * V_13 )
{
unsigned long V_2 , V_66 ;
struct V_14 V_15 ;
struct V_16 * V_17 = (struct V_16 * ) V_13 ;
struct V_18 * V_19 = F_6 ( V_17 -> V_20 ) ;
struct V_21 * V_22 ;
int V_23 ;
V_2 = F_27 () ;
F_28 ( V_2 & ~ V_24 ) ;
V_66 = F_29 () ;
if ( ! ( V_66 & V_74 ) )
return V_26 ;
F_30 ( V_66 ) ;
V_22 = F_7 () ;
for ( V_23 = 0 ; V_23 < V_17 -> V_27 ; ++ V_23 ) {
struct V_28 * V_29 = V_19 -> V_30 [ V_23 ] ;
struct V_31 * V_32 ;
if ( ! V_29 )
continue;
if ( ! F_35 ( V_66 , V_23 ) )
continue;
V_32 = & V_29 -> V_33 ;
F_8 ( V_29 ) ;
F_9 ( & V_15 , 0 , V_32 -> V_34 ) ;
if ( ! F_10 ( V_29 ) )
continue;
if ( F_11 ( V_29 , & V_15 , V_22 ) )
V_17 -> V_35 ( V_29 ) ;
}
F_12 () ;
V_2 = F_27 () | V_24 ;
F_28 ( V_2 ) ;
return V_36 ;
}
static void F_37 ( struct V_28 * V_29 )
{
unsigned long V_39 , V_75 , V_76 ;
struct V_16 * V_17 = F_14 ( V_29 -> V_40 ) ;
struct V_31 * V_32 = & V_29 -> V_33 ;
struct V_18 * V_30 = F_6 ( V_17 -> V_20 ) ;
int V_23 = V_32 -> V_23 ;
V_75 = F_33 () ;
V_76 = F_31 () ;
switch ( V_23 ) {
case V_6 :
V_75 |= V_77 ;
break;
case V_8 :
V_75 |= V_78 ;
V_76 &= ~ V_79 ;
V_76 |= V_32 -> V_43 << V_80 ;
break;
case V_10 :
V_75 |= V_81 ;
V_76 &= ~ V_82 ;
V_76 |= V_32 -> V_43 << V_83 ;
break;
case V_70 :
V_75 |= V_84 ;
V_76 &= ~ V_85 ;
V_76 |= V_32 -> V_43 << V_86 ;
break;
case V_72 :
V_75 |= V_87 ;
V_76 &= ~ V_88 ;
V_76 |= V_32 -> V_43 << V_89 ;
break;
default:
F_4 ( 1 , L_1 , V_23 ) ;
return;
}
F_15 ( & V_30 -> V_49 , V_39 ) ;
F_32 ( V_76 ) ;
F_34 ( V_75 ) ;
F_16 ( & V_30 -> V_49 , V_39 ) ;
}
static void F_38 ( struct V_28 * V_29 )
{
unsigned long V_39 , V_75 , V_76 , V_66 ;
struct V_16 * V_17 = F_14 ( V_29 -> V_40 ) ;
struct V_31 * V_32 = & V_29 -> V_33 ;
struct V_18 * V_30 = F_6 ( V_17 -> V_20 ) ;
int V_23 = V_32 -> V_23 ;
V_75 = F_33 () ;
V_76 = F_31 () ;
switch ( V_23 ) {
case V_6 :
V_75 &= ~ V_77 ;
V_66 = V_67 ;
break;
case V_8 :
V_75 &= ~ V_78 ;
V_76 &= ~ V_79 ;
V_76 |= V_50 << V_80 ;
V_66 = V_68 ;
break;
case V_10 :
V_75 &= ~ V_81 ;
V_76 &= ~ V_82 ;
V_76 |= V_50 << V_83 ;
V_66 = V_69 ;
break;
case V_70 :
V_75 &= ~ V_84 ;
V_76 &= ~ V_85 ;
V_76 |= V_50 << V_86 ;
V_66 = V_71 ;
break;
case V_72 :
V_75 &= ~ V_87 ;
V_76 &= ~ V_88 ;
V_76 |= V_50 << V_89 ;
V_66 = V_73 ;
break;
default:
F_4 ( 1 , L_1 , V_23 ) ;
return;
}
F_15 ( & V_30 -> V_49 , V_39 ) ;
F_32 ( V_76 ) ;
F_34 ( V_75 ) ;
F_30 ( V_66 ) ;
F_16 ( & V_30 -> V_49 , V_39 ) ;
}
static int
F_39 ( struct V_18 * V_19 ,
struct V_28 * V_29 )
{
int V_23 = F_18 ( V_19 , V_29 ) ;
if ( V_23 >= 0 )
goto V_90;
if ( ! F_19 ( V_72 , V_19 -> V_52 ) )
V_23 = V_72 ;
else if ( ! F_19 ( V_70 , V_19 -> V_52 ) )
V_23 = V_70 ;
V_90:
return V_23 ;
}
static void F_40 ( struct V_16 * V_17 )
{
unsigned long V_39 , V_1 ;
struct V_18 * V_30 = F_6 ( V_17 -> V_20 ) ;
F_15 ( & V_30 -> V_49 , V_39 ) ;
V_1 = F_27 () & ~ V_91 ;
V_1 |= V_24 ;
F_28 ( V_1 ) ;
F_16 ( & V_30 -> V_49 , V_39 ) ;
}
static void F_41 ( struct V_16 * V_17 )
{
unsigned long V_39 , V_1 ;
struct V_18 * V_30 = F_6 ( V_17 -> V_20 ) ;
F_15 ( & V_30 -> V_49 , V_39 ) ;
V_1 = F_27 () ;
V_1 &= ~ V_24 ;
F_28 ( V_1 ) ;
F_16 ( & V_30 -> V_49 , V_39 ) ;
}
static inline T_1 F_42 ( struct V_28 * V_29 )
{
struct V_31 * V_32 = & V_29 -> V_33 ;
int V_4 = V_32 -> V_23 ;
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
case V_70 :
asm volatile("mrc p14, 0, %0, c2, c2, 0" : "=r" (val));
break;
case V_72 :
asm volatile("mrc p14, 0, %0, c3, c2, 0" : "=r" (val));
break;
}
return V_1 ;
}
static inline void F_43 ( struct V_28 * V_29 , T_1 V_1 )
{
struct V_31 * V_32 = & V_29 -> V_33 ;
int V_4 = V_32 -> V_23 ;
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
case V_70 :
asm volatile("mcr p14, 0, %0, c2, c2, 0" : : "r" (val));
break;
case V_72 :
asm volatile("mcr p14, 0, %0, c3, c2, 0" : : "r" (val));
break;
}
}
static int F_44 ( struct V_16 * V_17 )
{
V_17 -> V_56 = L_3 ;
V_17 -> V_57 = F_36 ;
V_17 -> V_58 = F_37 ;
V_17 -> V_35 = F_38 ;
V_17 -> V_59 = F_42 ;
V_17 -> V_60 = F_43 ;
V_17 -> V_61 = F_39 ;
V_17 -> V_62 = F_40 ;
V_17 -> V_63 = F_41 ;
V_17 -> V_64 = F_24 ;
V_17 -> V_27 = 5 ;
V_17 -> V_65 = ( 1LLU << 32 ) - 1 ;
return 0 ;
}
static int F_45 ( struct V_92 * V_93 )
{
return F_46 ( V_93 , NULL , V_94 ) ;
}
static int T_3 F_47 ( void )
{
return F_48 ( & V_95 ) ;
}
