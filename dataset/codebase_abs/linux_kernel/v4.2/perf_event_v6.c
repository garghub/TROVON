static inline unsigned long
F_1 ( void )
{
T_1 V_1 ;
asm volatile("mrc p15, 0, %0, c15, c12, 0" : "=r"(val));
return V_1 ;
}
static inline void
F_2 ( unsigned long V_1 )
{
asm volatile("mcr p15, 0, %0, c15, c12, 0" : : "r"(val));
}
static inline int
F_3 ( unsigned long V_2 )
{
return V_2 & V_3 ;
}
static inline int
F_4 ( unsigned long V_2 ,
enum V_4 V_5 )
{
int V_6 = 0 ;
if ( V_7 == V_5 )
V_6 = V_2 & V_8 ;
else if ( V_9 == V_5 )
V_6 = V_2 & V_10 ;
else if ( V_11 == V_5 )
V_6 = V_2 & V_12 ;
else
F_5 ( 1 , L_1 , V_5 ) ;
return V_6 ;
}
static inline T_1 F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_17 ;
int V_5 = V_16 -> V_18 ;
unsigned long V_19 = 0 ;
if ( V_7 == V_5 )
asm volatile("mrc p15, 0, %0, c15, c12, 1" : "=r"(value));
else if ( V_9 == V_5 )
asm volatile("mrc p15, 0, %0, c15, c12, 2" : "=r"(value));
else if ( V_11 == V_5 )
asm volatile("mrc p15, 0, %0, c15, c12, 3" : "=r"(value));
else
F_5 ( 1 , L_1 , V_5 ) ;
return V_19 ;
}
static inline void F_7 ( struct V_13 * V_14 , T_1 V_19 )
{
struct V_15 * V_16 = & V_14 -> V_17 ;
int V_5 = V_16 -> V_18 ;
if ( V_7 == V_5 )
asm volatile("mcr p15, 0, %0, c15, c12, 1" : : "r"(value));
else if ( V_9 == V_5 )
asm volatile("mcr p15, 0, %0, c15, c12, 2" : : "r"(value));
else if ( V_11 == V_5 )
asm volatile("mcr p15, 0, %0, c15, c12, 3" : : "r"(value));
else
F_5 ( 1 , L_1 , V_5 ) ;
}
static void F_8 ( struct V_13 * V_14 )
{
unsigned long V_1 , V_20 , V_21 , V_22 ;
struct V_23 * V_24 = F_9 ( V_14 -> V_25 ) ;
struct V_15 * V_16 = & V_14 -> V_17 ;
struct V_26 * V_27 = F_10 ( V_24 -> V_28 ) ;
int V_18 = V_16 -> V_18 ;
if ( V_7 == V_18 ) {
V_20 = 0 ;
V_21 = V_29 ;
} else if ( V_9 == V_18 ) {
V_20 = V_30 ;
V_21 = ( V_16 -> V_31 << V_32 ) |
V_33 ;
} else if ( V_11 == V_18 ) {
V_20 = V_34 ;
V_21 = ( V_16 -> V_31 << V_35 ) |
V_36 ;
} else {
F_5 ( 1 , L_1 , V_18 ) ;
return;
}
F_11 ( & V_27 -> V_37 , V_22 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_20 ;
V_1 |= V_21 ;
F_2 ( V_1 ) ;
F_12 ( & V_27 -> V_37 , V_22 ) ;
}
static T_2
F_13 ( int V_38 ,
void * V_39 )
{
unsigned long V_2 = F_1 () ;
struct V_40 V_41 ;
struct V_23 * V_24 = (struct V_23 * ) V_39 ;
struct V_26 * V_42 = F_10 ( V_24 -> V_28 ) ;
struct V_43 * V_44 ;
int V_18 ;
if ( ! F_3 ( V_2 ) )
return V_45 ;
V_44 = F_14 () ;
F_2 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_24 -> V_46 ; ++ V_18 ) {
struct V_13 * V_14 = V_42 -> V_27 [ V_18 ] ;
struct V_15 * V_16 ;
if ( ! V_14 )
continue;
if ( ! F_4 ( V_2 , V_18 ) )
continue;
V_16 = & V_14 -> V_17 ;
F_15 ( V_14 ) ;
F_16 ( & V_41 , 0 , V_16 -> V_47 ) ;
if ( ! F_17 ( V_14 ) )
continue;
if ( F_18 ( V_14 , & V_41 , V_44 ) )
V_24 -> V_48 ( V_14 ) ;
}
F_19 () ;
return V_49 ;
}
static void F_20 ( struct V_23 * V_24 )
{
unsigned long V_22 , V_1 ;
struct V_26 * V_27 = F_10 ( V_24 -> V_28 ) ;
F_11 ( & V_27 -> V_37 , V_22 ) ;
V_1 = F_1 () ;
V_1 |= V_50 ;
F_2 ( V_1 ) ;
F_12 ( & V_27 -> V_37 , V_22 ) ;
}
static void F_21 ( struct V_23 * V_24 )
{
unsigned long V_22 , V_1 ;
struct V_26 * V_27 = F_10 ( V_24 -> V_28 ) ;
F_11 ( & V_27 -> V_37 , V_22 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_50 ;
F_2 ( V_1 ) ;
F_12 ( & V_27 -> V_37 , V_22 ) ;
}
static int
F_22 ( struct V_26 * V_42 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_17 ;
if ( V_51 == V_16 -> V_31 ) {
if ( F_23 ( V_7 , V_42 -> V_52 ) )
return - V_53 ;
return V_7 ;
} else {
if ( ! F_23 ( V_11 , V_42 -> V_52 ) )
return V_11 ;
if ( ! F_23 ( V_9 , V_42 -> V_52 ) )
return V_9 ;
return - V_53 ;
}
}
static void F_24 ( struct V_13 * V_14 )
{
unsigned long V_1 , V_20 , V_21 , V_22 ;
struct V_23 * V_24 = F_9 ( V_14 -> V_25 ) ;
struct V_15 * V_16 = & V_14 -> V_17 ;
struct V_26 * V_27 = F_10 ( V_24 -> V_28 ) ;
int V_18 = V_16 -> V_18 ;
if ( V_7 == V_18 ) {
V_20 = V_29 ;
V_21 = 0 ;
} else if ( V_9 == V_18 ) {
V_20 = V_33 | V_30 ;
V_21 = V_54 << V_32 ;
} else if ( V_11 == V_18 ) {
V_20 = V_36 | V_34 ;
V_21 = V_54 << V_35 ;
} else {
F_5 ( 1 , L_1 , V_18 ) ;
return;
}
F_11 ( & V_27 -> V_37 , V_22 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_20 ;
V_1 |= V_21 ;
F_2 ( V_1 ) ;
F_12 ( & V_27 -> V_37 , V_22 ) ;
}
static void F_25 ( struct V_13 * V_14 )
{
unsigned long V_1 , V_20 , V_22 , V_21 = 0 ;
struct V_23 * V_24 = F_9 ( V_14 -> V_25 ) ;
struct V_15 * V_16 = & V_14 -> V_17 ;
struct V_26 * V_27 = F_10 ( V_24 -> V_28 ) ;
int V_18 = V_16 -> V_18 ;
if ( V_7 == V_18 ) {
V_20 = V_29 ;
} else if ( V_9 == V_18 ) {
V_20 = V_33 ;
} else if ( V_11 == V_18 ) {
V_20 = V_36 ;
} else {
F_5 ( 1 , L_1 , V_18 ) ;
return;
}
F_11 ( & V_27 -> V_37 , V_22 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_20 ;
V_1 |= V_21 ;
F_2 ( V_1 ) ;
F_12 ( & V_27 -> V_37 , V_22 ) ;
}
static int F_26 ( struct V_13 * V_14 )
{
return F_27 ( V_14 , & V_55 ,
& V_56 , 0xFF ) ;
}
static void F_28 ( struct V_23 * V_24 )
{
V_24 -> V_57 = F_13 ;
V_24 -> V_58 = F_8 ;
V_24 -> V_48 = F_24 ;
V_24 -> V_59 = F_6 ;
V_24 -> V_60 = F_7 ;
V_24 -> V_61 = F_22 ;
V_24 -> V_62 = F_20 ;
V_24 -> V_63 = F_21 ;
V_24 -> V_64 = F_26 ;
V_24 -> V_46 = 3 ;
V_24 -> V_65 = ( 1LLU << 32 ) - 1 ;
}
static int F_29 ( struct V_23 * V_24 )
{
F_28 ( V_24 ) ;
V_24 -> V_66 = L_2 ;
return 0 ;
}
static int F_30 ( struct V_23 * V_24 )
{
F_28 ( V_24 ) ;
V_24 -> V_66 = L_3 ;
return 0 ;
}
static int F_31 ( struct V_23 * V_24 )
{
F_28 ( V_24 ) ;
V_24 -> V_66 = L_4 ;
return 0 ;
}
static int F_32 ( struct V_13 * V_14 )
{
return F_27 ( V_14 , & V_67 ,
& V_68 , 0xFF ) ;
}
static int F_33 ( struct V_23 * V_24 )
{
V_24 -> V_66 = L_5 ;
V_24 -> V_57 = F_13 ;
V_24 -> V_58 = F_8 ;
V_24 -> V_48 = F_25 ;
V_24 -> V_59 = F_6 ;
V_24 -> V_60 = F_7 ;
V_24 -> V_61 = F_22 ;
V_24 -> V_62 = F_20 ;
V_24 -> V_63 = F_21 ;
V_24 -> V_64 = F_32 ;
V_24 -> V_46 = 3 ;
V_24 -> V_65 = ( 1LLU << 32 ) - 1 ;
return 0 ;
}
static int F_34 ( struct V_69 * V_70 )
{
return F_35 ( V_70 , V_71 ,
V_72 ) ;
}
static int T_3 F_36 ( void )
{
return F_37 ( & V_73 ) ;
}
