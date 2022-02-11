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
static inline int F_5 ( int V_5 )
{
return V_5 >= V_6 && V_5 <= V_7 ;
}
static inline int F_6 ( T_1 V_3 , int V_5 )
{
int V_8 = 0 ;
T_1 V_9 ;
if ( ! F_5 ( V_5 ) ) {
F_7 ( L_1 ,
F_8 () , V_5 ) ;
} else {
V_9 = F_9 ( V_5 ) ;
V_8 = V_3 & F_10 ( V_9 ) ;
}
return V_8 ;
}
static inline int F_11 ( int V_5 )
{
T_1 V_9 ;
if ( ! F_5 ( V_5 ) ) {
F_7 ( L_2 ,
F_8 () , V_5 ) ;
return - V_10 ;
}
V_9 = F_9 ( V_5 ) ;
asm volatile("mcr p15, 0, %0, c9, c12, 5" : : "r" (counter));
F_3 () ;
return V_5 ;
}
static inline T_1 F_12 ( int V_5 )
{
T_1 V_11 = 0 ;
if ( ! F_5 ( V_5 ) )
F_7 ( L_3 ,
F_8 () , V_5 ) ;
else if ( V_5 == V_6 )
asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (value));
else if ( F_11 ( V_5 ) == V_5 )
asm volatile("mrc p15, 0, %0, c9, c13, 2" : "=r" (value));
return V_11 ;
}
static inline void F_13 ( int V_5 , T_1 V_11 )
{
if ( ! F_5 ( V_5 ) )
F_7 ( L_4 ,
F_8 () , V_5 ) ;
else if ( V_5 == V_6 )
asm volatile("mcr p15, 0, %0, c9, c13, 0" : : "r" (value));
else if ( F_11 ( V_5 ) == V_5 )
asm volatile("mcr p15, 0, %0, c9, c13, 2" : : "r" (value));
}
static inline void F_14 ( int V_5 , T_1 V_1 )
{
if ( F_11 ( V_5 ) == V_5 ) {
V_1 &= V_12 ;
asm volatile("mcr p15, 0, %0, c9, c13, 1" : : "r" (val));
}
}
static inline int F_15 ( int V_5 )
{
T_1 V_9 ;
if ( ! F_5 ( V_5 ) ) {
F_7 ( L_5 ,
F_8 () , V_5 ) ;
return - V_10 ;
}
V_9 = F_9 ( V_5 ) ;
asm volatile("mcr p15, 0, %0, c9, c12, 1" : : "r" (BIT(counter)));
return V_5 ;
}
static inline int F_16 ( int V_5 )
{
T_1 V_9 ;
if ( ! F_5 ( V_5 ) ) {
F_7 ( L_6 ,
F_8 () , V_5 ) ;
return - V_10 ;
}
V_9 = F_9 ( V_5 ) ;
asm volatile("mcr p15, 0, %0, c9, c12, 2" : : "r" (BIT(counter)));
return V_5 ;
}
static inline int F_17 ( int V_5 )
{
T_1 V_9 ;
if ( ! F_5 ( V_5 ) ) {
F_7 ( L_7 ,
F_8 () , V_5 ) ;
return - V_10 ;
}
V_9 = F_9 ( V_5 ) ;
asm volatile("mcr p15, 0, %0, c9, c14, 1" : : "r" (BIT(counter)));
return V_5 ;
}
static inline int F_18 ( int V_5 )
{
T_1 V_9 ;
if ( ! F_5 ( V_5 ) ) {
F_7 ( L_8 ,
F_8 () , V_5 ) ;
return - V_10 ;
}
V_9 = F_9 ( V_5 ) ;
asm volatile("mcr p15, 0, %0, c9, c14, 2" : : "r" (BIT(counter)));
return V_5 ;
}
static inline T_1 F_19 ( void )
{
T_1 V_1 ;
asm volatile("mrc p15, 0, %0, c9, c12, 3" : "=r" (val));
V_1 &= V_13 ;
asm volatile("mcr p15, 0, %0, c9, c12, 3" : : "r" (val));
return V_1 ;
}
static void F_20 ( void )
{
T_1 V_1 ;
unsigned int V_14 ;
F_21 ( V_15 L_9 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 0" : "=r" (val));
F_21 ( V_15 L_10 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 1" : "=r" (val));
F_21 ( V_15 L_11 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c14, 1" : "=r" (val));
F_21 ( V_15 L_12 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 3" : "=r" (val));
F_21 ( V_15 L_13 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 5" : "=r" (val));
F_21 ( V_15 L_14 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (val));
F_21 ( V_15 L_15 , V_1 ) ;
for ( V_14 = V_16 ; V_14 <= V_7 ; V_14 ++ ) {
F_11 ( V_14 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 2" : "=r" (val));
F_21 ( V_15 L_16 ,
F_9 ( V_14 ) , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 1" : "=r" (val));
F_21 ( V_15 L_17 ,
F_9 ( V_14 ) , V_1 ) ;
}
}
static void F_22 ( struct V_17 * V_18 , int V_5 )
{
unsigned long V_19 ;
struct V_20 * V_21 = V_22 -> V_23 () ;
F_23 ( & V_21 -> V_24 , V_19 ) ;
F_16 ( V_5 ) ;
if ( V_25 . V_26 || V_5 != V_6 )
F_14 ( V_5 , V_18 -> V_27 ) ;
F_17 ( V_5 ) ;
F_15 ( V_5 ) ;
F_24 ( & V_21 -> V_24 , V_19 ) ;
}
static void F_25 ( struct V_17 * V_18 , int V_5 )
{
unsigned long V_19 ;
struct V_20 * V_21 = V_22 -> V_23 () ;
F_23 ( & V_21 -> V_24 , V_19 ) ;
F_16 ( V_5 ) ;
F_18 ( V_5 ) ;
F_24 ( & V_21 -> V_24 , V_19 ) ;
}
static T_2 F_26 ( int V_28 , void * V_29 )
{
T_1 V_3 ;
struct V_30 V_31 ;
struct V_20 * V_32 ;
struct V_33 * V_34 ;
int V_5 ;
V_3 = F_19 () ;
if ( ! F_4 ( V_3 ) )
return V_35 ;
V_34 = F_27 () ;
F_28 ( & V_31 , 0 ) ;
V_32 = & F_29 ( V_36 ) ;
for ( V_5 = 0 ; V_5 < V_22 -> V_37 ; ++ V_5 ) {
struct V_38 * V_39 = V_32 -> V_21 [ V_5 ] ;
struct V_17 * V_18 ;
if ( ! F_6 ( V_3 , V_5 ) )
continue;
V_18 = & V_39 -> V_40 ;
F_30 ( V_39 , V_18 , V_5 , 1 ) ;
V_31 . V_41 = V_39 -> V_40 . V_42 ;
if ( ! F_31 ( V_39 , V_18 , V_5 ) )
continue;
if ( F_32 ( V_39 , & V_31 , V_34 ) )
V_22 -> V_43 ( V_18 , V_5 ) ;
}
F_33 () ;
return V_44 ;
}
static void F_34 ( void )
{
unsigned long V_19 ;
struct V_20 * V_21 = V_22 -> V_23 () ;
F_23 ( & V_21 -> V_24 , V_19 ) ;
F_2 ( F_1 () | V_45 ) ;
F_24 ( & V_21 -> V_24 , V_19 ) ;
}
static void F_35 ( void )
{
unsigned long V_19 ;
struct V_20 * V_21 = V_22 -> V_23 () ;
F_23 ( & V_21 -> V_24 , V_19 ) ;
F_2 ( F_1 () & ~ V_45 ) ;
F_24 ( & V_21 -> V_24 , V_19 ) ;
}
static int F_36 ( struct V_20 * V_32 ,
struct V_17 * V_39 )
{
int V_5 ;
unsigned long V_46 = V_39 -> V_27 & V_47 ;
if ( V_46 == V_48 ) {
if ( F_37 ( V_6 , V_32 -> V_49 ) )
return - V_50 ;
return V_6 ;
}
for ( V_5 = V_16 ; V_5 < V_22 -> V_37 ; ++ V_5 ) {
if ( ! F_37 ( V_5 , V_32 -> V_49 ) )
return V_5 ;
}
return - V_50 ;
}
static int F_38 ( struct V_17 * V_39 ,
struct V_51 * V_52 )
{
unsigned long V_27 = 0 ;
if ( V_52 -> V_53 )
return - V_54 ;
if ( V_52 -> V_55 )
V_27 |= V_56 ;
if ( V_52 -> V_57 )
V_27 |= V_58 ;
if ( ! V_52 -> V_59 )
V_27 |= V_60 ;
V_39 -> V_27 = V_27 ;
return 0 ;
}
static void F_39 ( void * V_61 )
{
T_1 V_5 , V_62 = V_22 -> V_37 ;
for ( V_5 = V_6 ; V_5 < V_62 ; ++ V_5 )
F_25 ( NULL , V_5 ) ;
F_2 ( V_63 | V_64 ) ;
}
static int F_40 ( struct V_38 * V_39 )
{
return F_41 ( V_39 , & V_65 ,
& V_66 , 0xFF ) ;
}
static int F_42 ( struct V_38 * V_39 )
{
return F_41 ( V_39 , & V_67 ,
& V_68 , 0xFF ) ;
}
static int F_43 ( struct V_38 * V_39 )
{
return F_41 ( V_39 , & V_69 ,
& V_70 , 0xFF ) ;
}
static int F_44 ( struct V_38 * V_39 )
{
return F_41 ( V_39 , & V_71 ,
& V_72 , 0xFF ) ;
}
static T_1 T_3 F_45 ( void )
{
T_1 V_62 ;
V_62 = ( F_1 () >> V_73 ) & V_74 ;
return V_62 + 1 ;
}
static struct V_75 * T_3 F_46 ( void )
{
V_25 . V_76 = V_77 ;
V_25 . V_78 = L_18 ;
V_25 . V_79 = F_40 ;
V_25 . V_37 = F_45 () ;
return & V_25 ;
}
static struct V_75 * T_3 F_47 ( void )
{
V_25 . V_76 = V_80 ;
V_25 . V_78 = L_19 ;
V_25 . V_79 = F_42 ;
V_25 . V_37 = F_45 () ;
return & V_25 ;
}
static struct V_75 * T_3 F_48 ( void )
{
V_25 . V_76 = V_81 ;
V_25 . V_78 = L_20 ;
V_25 . V_79 = F_43 ;
V_25 . V_37 = F_45 () ;
return & V_25 ;
}
static struct V_75 * T_3 F_49 ( void )
{
V_25 . V_76 = V_82 ;
V_25 . V_78 = L_21 ;
V_25 . V_79 = F_44 ;
V_25 . V_37 = F_45 () ;
V_25 . V_26 = F_38 ;
return & V_25 ;
}
static struct V_75 * T_3 F_46 ( void )
{
return NULL ;
}
static struct V_75 * T_3 F_47 ( void )
{
return NULL ;
}
static struct V_75 * T_3 F_48 ( void )
{
return NULL ;
}
static struct V_75 * T_3 F_49 ( void )
{
return NULL ;
}
