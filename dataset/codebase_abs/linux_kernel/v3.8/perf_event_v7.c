static inline T_1 F_1 ( void )
{
T_1 V_1 ;
asm volatile("mrc p15, 0, %0, c9, c12, 0" : "=r"(val));
return V_1 ;
}
static inline void F_2 ( T_1 V_1 )
{
V_1 &= V_2 ;
F_3 () ;
asm volatile("mcr p15, 0, %0, c9, c12, 0" : : "r"(val));
}
static inline int F_4 ( T_1 V_3 )
{
return V_3 & V_4 ;
}
static inline int F_5 ( struct V_5 * V_6 , int V_7 )
{
return V_7 >= V_8 &&
V_7 <= F_6 ( V_6 ) ;
}
static inline int F_7 ( T_1 V_3 , int V_7 )
{
return V_3 & F_8 ( F_9 ( V_7 ) ) ;
}
static inline int F_10 ( int V_7 )
{
T_1 V_9 = F_9 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c12, 5" : : "r" (counter));
F_3 () ;
return V_7 ;
}
static inline T_1 F_11 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
T_1 V_16 = 0 ;
if ( ! F_5 ( V_6 , V_7 ) )
F_13 ( L_1 ,
F_14 () , V_7 ) ;
else if ( V_7 == V_8 )
asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (value));
else if ( F_10 ( V_7 ) == V_7 )
asm volatile("mrc p15, 0, %0, c9, c13, 2" : "=r" (value));
return V_16 ;
}
static inline void F_15 ( struct V_10 * V_11 , T_1 V_16 )
{
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
if ( ! F_5 ( V_6 , V_7 ) )
F_13 ( L_2 ,
F_14 () , V_7 ) ;
else if ( V_7 == V_8 )
asm volatile("mcr p15, 0, %0, c9, c13, 0" : : "r" (value));
else if ( F_10 ( V_7 ) == V_7 )
asm volatile("mcr p15, 0, %0, c9, c13, 2" : : "r" (value));
}
static inline void F_16 ( int V_7 , T_1 V_1 )
{
if ( F_10 ( V_7 ) == V_7 ) {
V_1 &= V_17 ;
asm volatile("mcr p15, 0, %0, c9, c13, 1" : : "r" (val));
}
}
static inline int F_17 ( int V_7 )
{
T_1 V_9 = F_9 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c12, 1" : : "r" (BIT(counter)));
return V_7 ;
}
static inline int F_18 ( int V_7 )
{
T_1 V_9 = F_9 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c12, 2" : : "r" (BIT(counter)));
return V_7 ;
}
static inline int F_19 ( int V_7 )
{
T_1 V_9 = F_9 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c14, 1" : : "r" (BIT(counter)));
return V_7 ;
}
static inline int F_20 ( int V_7 )
{
T_1 V_9 = F_9 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c14, 2" : : "r" (BIT(counter)));
F_3 () ;
asm volatile("mcr p15, 0, %0, c9, c12, 3" : : "r" (BIT(counter)));
F_3 () ;
return V_7 ;
}
static inline T_1 F_21 ( void )
{
T_1 V_1 ;
asm volatile("mrc p15, 0, %0, c9, c12, 3" : "=r" (val));
V_1 &= V_18 ;
asm volatile("mcr p15, 0, %0, c9, c12, 3" : : "r" (val));
return V_1 ;
}
static void F_22 ( struct V_5 * V_6 )
{
T_1 V_1 ;
unsigned int V_19 ;
F_23 ( V_20 L_3 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 0" : "=r" (val));
F_23 ( V_20 L_4 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 1" : "=r" (val));
F_23 ( V_20 L_5 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c14, 1" : "=r" (val));
F_23 ( V_20 L_6 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 3" : "=r" (val));
F_23 ( V_20 L_7 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 5" : "=r" (val));
F_23 ( V_20 L_8 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (val));
F_23 ( V_20 L_9 , V_1 ) ;
for ( V_19 = V_21 ;
V_19 <= F_6 ( V_6 ) ; V_19 ++ ) {
F_10 ( V_19 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 2" : "=r" (val));
F_23 ( V_20 L_10 ,
F_9 ( V_19 ) , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 1" : "=r" (val));
F_23 ( V_20 L_11 ,
F_9 ( V_19 ) , V_1 ) ;
}
}
static void F_24 ( struct V_10 * V_11 )
{
unsigned long V_22 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_23 * V_24 = V_6 -> V_25 () ;
int V_7 = V_14 -> V_7 ;
if ( ! F_5 ( V_6 , V_7 ) ) {
F_13 ( L_12 ,
F_14 () , V_7 ) ;
return;
}
F_25 ( & V_24 -> V_26 , V_22 ) ;
F_18 ( V_7 ) ;
if ( V_6 -> V_27 || V_7 != V_8 )
F_16 ( V_7 , V_14 -> V_28 ) ;
F_19 ( V_7 ) ;
F_17 ( V_7 ) ;
F_26 ( & V_24 -> V_26 , V_22 ) ;
}
static void F_27 ( struct V_10 * V_11 )
{
unsigned long V_22 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_23 * V_24 = V_6 -> V_25 () ;
int V_7 = V_14 -> V_7 ;
if ( ! F_5 ( V_6 , V_7 ) ) {
F_13 ( L_13 ,
F_14 () , V_7 ) ;
return;
}
F_25 ( & V_24 -> V_26 , V_22 ) ;
F_18 ( V_7 ) ;
F_20 ( V_7 ) ;
F_26 ( & V_24 -> V_26 , V_22 ) ;
}
static T_2 F_28 ( int V_29 , void * V_30 )
{
T_1 V_3 ;
struct V_31 V_32 ;
struct V_5 * V_6 = (struct V_5 * ) V_30 ;
struct V_23 * V_33 = V_6 -> V_25 () ;
struct V_34 * V_35 ;
int V_7 ;
V_3 = F_21 () ;
if ( ! F_4 ( V_3 ) )
return V_36 ;
V_35 = F_29 () ;
for ( V_7 = 0 ; V_7 < V_6 -> V_37 ; ++ V_7 ) {
struct V_10 * V_11 = V_33 -> V_24 [ V_7 ] ;
struct V_13 * V_14 ;
if ( ! V_11 )
continue;
if ( ! F_7 ( V_3 , V_7 ) )
continue;
V_14 = & V_11 -> V_15 ;
F_30 ( V_11 ) ;
F_31 ( & V_32 , 0 , V_14 -> V_38 ) ;
if ( ! F_32 ( V_11 ) )
continue;
if ( F_33 ( V_11 , & V_32 , V_35 ) )
V_6 -> V_39 ( V_11 ) ;
}
F_34 () ;
return V_40 ;
}
static void F_35 ( struct V_5 * V_6 )
{
unsigned long V_22 ;
struct V_23 * V_24 = V_6 -> V_25 () ;
F_25 ( & V_24 -> V_26 , V_22 ) ;
F_2 ( F_1 () | V_41 ) ;
F_26 ( & V_24 -> V_26 , V_22 ) ;
}
static void F_36 ( struct V_5 * V_6 )
{
unsigned long V_22 ;
struct V_23 * V_24 = V_6 -> V_25 () ;
F_25 ( & V_24 -> V_26 , V_22 ) ;
F_2 ( F_1 () & ~ V_41 ) ;
F_26 ( & V_24 -> V_26 , V_22 ) ;
}
static int F_37 ( struct V_23 * V_33 ,
struct V_10 * V_11 )
{
int V_7 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_13 * V_14 = & V_11 -> V_15 ;
unsigned long V_42 = V_14 -> V_28 & V_43 ;
if ( V_42 == V_44 ) {
if ( F_38 ( V_8 , V_33 -> V_45 ) )
return - V_46 ;
return V_8 ;
}
for ( V_7 = V_21 ; V_7 < V_6 -> V_37 ; ++ V_7 ) {
if ( ! F_38 ( V_7 , V_33 -> V_45 ) )
return V_7 ;
}
return - V_46 ;
}
static int F_39 ( struct V_13 * V_11 ,
struct V_47 * V_48 )
{
unsigned long V_28 = 0 ;
if ( V_48 -> V_49 )
return - V_50 ;
if ( V_48 -> V_51 )
V_28 |= V_52 ;
if ( V_48 -> V_53 )
V_28 |= V_54 ;
if ( ! V_48 -> V_55 )
V_28 |= V_56 ;
V_11 -> V_28 = V_28 ;
return 0 ;
}
static void F_40 ( void * V_57 )
{
struct V_5 * V_6 = (struct V_5 * ) V_57 ;
T_1 V_7 , V_58 = V_6 -> V_37 ;
for ( V_7 = V_8 ; V_7 < V_58 ; ++ V_7 ) {
F_18 ( V_7 ) ;
F_20 ( V_7 ) ;
}
F_2 ( V_59 | V_60 ) ;
}
static int F_41 ( struct V_10 * V_11 )
{
return F_42 ( V_11 , & V_61 ,
& V_62 , 0xFF ) ;
}
static int F_43 ( struct V_10 * V_11 )
{
return F_42 ( V_11 , & V_63 ,
& V_64 , 0xFF ) ;
}
static int F_44 ( struct V_10 * V_11 )
{
return F_42 ( V_11 , & V_65 ,
& V_66 , 0xFF ) ;
}
static int F_45 ( struct V_10 * V_11 )
{
return F_42 ( V_11 , & V_67 ,
& V_68 , 0xFF ) ;
}
static int F_46 ( struct V_10 * V_11 )
{
return F_42 ( V_11 , & V_69 ,
& V_70 , 0xFF ) ;
}
static void F_47 ( struct V_5 * V_6 )
{
V_6 -> V_71 = F_28 ;
V_6 -> V_72 = F_24 ;
V_6 -> V_39 = F_27 ;
V_6 -> V_73 = F_11 ;
V_6 -> V_74 = F_15 ;
V_6 -> V_75 = F_37 ;
V_6 -> V_76 = F_35 ;
V_6 -> V_77 = F_36 ;
V_6 -> V_78 = F_40 ;
V_6 -> V_79 = ( 1LLU << 32 ) - 1 ;
}
static T_1 F_48 ( void )
{
T_1 V_58 ;
V_58 = ( F_1 () >> V_80 ) & V_81 ;
return V_58 + 1 ;
}
static int F_49 ( struct V_5 * V_6 )
{
F_47 ( V_6 ) ;
V_6 -> V_82 = L_14 ;
V_6 -> V_83 = F_41 ;
V_6 -> V_37 = F_48 () ;
return 0 ;
}
static int F_50 ( struct V_5 * V_6 )
{
F_47 ( V_6 ) ;
V_6 -> V_82 = L_15 ;
V_6 -> V_83 = F_43 ;
V_6 -> V_37 = F_48 () ;
return 0 ;
}
static int F_51 ( struct V_5 * V_6 )
{
F_47 ( V_6 ) ;
V_6 -> V_82 = L_16 ;
V_6 -> V_83 = F_44 ;
V_6 -> V_37 = F_48 () ;
return 0 ;
}
static int F_52 ( struct V_5 * V_6 )
{
F_47 ( V_6 ) ;
V_6 -> V_82 = L_17 ;
V_6 -> V_83 = F_45 ;
V_6 -> V_37 = F_48 () ;
V_6 -> V_27 = F_39 ;
return 0 ;
}
static int F_53 ( struct V_5 * V_6 )
{
F_47 ( V_6 ) ;
V_6 -> V_82 = L_18 ;
V_6 -> V_83 = F_46 ;
V_6 -> V_37 = F_48 () ;
V_6 -> V_27 = F_39 ;
return 0 ;
}
static inline int F_49 ( struct V_5 * V_6 )
{
return - V_84 ;
}
static inline int F_50 ( struct V_5 * V_6 )
{
return - V_84 ;
}
static inline int F_51 ( struct V_5 * V_6 )
{
return - V_84 ;
}
static inline int F_52 ( struct V_5 * V_6 )
{
return - V_84 ;
}
static inline int F_53 ( struct V_5 * V_6 )
{
return - V_84 ;
}
