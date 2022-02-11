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
static inline T_1
F_6 ( int V_5 )
{
unsigned long V_13 = 0 ;
if ( V_7 == V_5 )
asm volatile("mrc p15, 0, %0, c15, c12, 1" : "=r"(value));
else if ( V_9 == V_5 )
asm volatile("mrc p15, 0, %0, c15, c12, 2" : "=r"(value));
else if ( V_11 == V_5 )
asm volatile("mrc p15, 0, %0, c15, c12, 3" : "=r"(value));
else
F_5 ( 1 , L_1 , V_5 ) ;
return V_13 ;
}
static inline void
F_7 ( int V_5 ,
T_1 V_13 )
{
if ( V_7 == V_5 )
asm volatile("mcr p15, 0, %0, c15, c12, 1" : : "r"(value));
else if ( V_9 == V_5 )
asm volatile("mcr p15, 0, %0, c15, c12, 2" : : "r"(value));
else if ( V_11 == V_5 )
asm volatile("mcr p15, 0, %0, c15, c12, 3" : : "r"(value));
else
F_5 ( 1 , L_1 , V_5 ) ;
}
static void
F_8 ( struct V_14 * V_15 ,
int V_16 )
{
unsigned long V_1 , V_17 , V_18 , V_19 ;
struct V_20 * V_21 = V_22 -> V_23 () ;
if ( V_7 == V_16 ) {
V_17 = 0 ;
V_18 = V_24 ;
} else if ( V_9 == V_16 ) {
V_17 = V_25 ;
V_18 = ( V_15 -> V_26 << V_27 ) |
V_28 ;
} else if ( V_11 == V_16 ) {
V_17 = V_29 ;
V_18 = ( V_15 -> V_26 << V_30 ) |
V_31 ;
} else {
F_5 ( 1 , L_1 , V_16 ) ;
return;
}
F_9 ( & V_21 -> V_32 , V_19 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_17 ;
V_1 |= V_18 ;
F_2 ( V_1 ) ;
F_10 ( & V_21 -> V_32 , V_19 ) ;
}
static int F_11 ( unsigned long V_2 , int V_16 )
{
unsigned long V_17 = 0 ;
if ( V_16 == V_7 )
V_17 = V_24 ;
else if ( V_16 == V_9 )
V_17 = V_28 ;
else if ( V_16 == V_11 )
V_17 = V_31 ;
if ( V_17 )
return V_2 & V_17 ;
F_5 ( 1 , L_1 , V_16 ) ;
return 0 ;
}
static T_2
F_12 ( int V_33 ,
void * V_34 )
{
unsigned long V_2 = F_1 () ;
struct V_35 V_36 ;
struct V_20 * V_37 ;
struct V_38 * V_39 ;
int V_16 ;
if ( ! F_3 ( V_2 ) )
return V_40 ;
V_39 = F_13 () ;
F_2 ( V_2 ) ;
F_14 ( & V_36 , 0 ) ;
V_37 = & F_15 ( V_41 ) ;
for ( V_16 = 0 ; V_16 < V_22 -> V_42 ; ++ V_16 ) {
struct V_43 * V_44 = V_37 -> V_21 [ V_16 ] ;
struct V_14 * V_15 ;
if ( ! F_11 ( V_2 , V_16 ) )
continue;
if ( ! F_4 ( V_2 , V_16 ) )
continue;
V_15 = & V_44 -> V_45 ;
F_16 ( V_44 , V_15 , V_16 , 1 ) ;
V_36 . V_46 = V_44 -> V_45 . V_47 ;
if ( ! F_17 ( V_44 , V_15 , V_16 ) )
continue;
if ( F_18 ( V_44 , & V_36 , V_39 ) )
V_22 -> V_48 ( V_15 , V_16 ) ;
}
F_19 () ;
return V_49 ;
}
static void
F_20 ( void )
{
unsigned long V_19 , V_1 ;
struct V_20 * V_21 = V_22 -> V_23 () ;
F_9 ( & V_21 -> V_32 , V_19 ) ;
V_1 = F_1 () ;
V_1 |= V_50 ;
F_2 ( V_1 ) ;
F_10 ( & V_21 -> V_32 , V_19 ) ;
}
static void
F_21 ( void )
{
unsigned long V_19 , V_1 ;
struct V_20 * V_21 = V_22 -> V_23 () ;
F_9 ( & V_21 -> V_32 , V_19 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_50 ;
F_2 ( V_1 ) ;
F_10 ( & V_21 -> V_32 , V_19 ) ;
}
static int
F_22 ( struct V_20 * V_37 ,
struct V_14 * V_44 )
{
if ( V_51 == V_44 -> V_26 ) {
if ( F_23 ( V_7 , V_37 -> V_52 ) )
return - V_53 ;
return V_7 ;
} else {
if ( ! F_23 ( V_11 , V_37 -> V_52 ) )
return V_11 ;
if ( ! F_23 ( V_9 , V_37 -> V_52 ) )
return V_9 ;
return - V_53 ;
}
}
static void
F_24 ( struct V_14 * V_15 ,
int V_16 )
{
unsigned long V_1 , V_17 , V_18 , V_19 ;
struct V_20 * V_21 = V_22 -> V_23 () ;
if ( V_7 == V_16 ) {
V_17 = V_24 ;
V_18 = 0 ;
} else if ( V_9 == V_16 ) {
V_17 = V_28 | V_25 ;
V_18 = V_54 << V_27 ;
} else if ( V_11 == V_16 ) {
V_17 = V_31 | V_29 ;
V_18 = V_54 << V_30 ;
} else {
F_5 ( 1 , L_1 , V_16 ) ;
return;
}
F_9 ( & V_21 -> V_32 , V_19 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_17 ;
V_1 |= V_18 ;
F_2 ( V_1 ) ;
F_10 ( & V_21 -> V_32 , V_19 ) ;
}
static void
F_25 ( struct V_14 * V_15 ,
int V_16 )
{
unsigned long V_1 , V_17 , V_19 , V_18 = 0 ;
struct V_20 * V_21 = V_22 -> V_23 () ;
if ( V_7 == V_16 ) {
V_17 = V_24 ;
} else if ( V_9 == V_16 ) {
V_17 = V_28 ;
} else if ( V_11 == V_16 ) {
V_17 = V_31 ;
} else {
F_5 ( 1 , L_1 , V_16 ) ;
return;
}
F_9 ( & V_21 -> V_32 , V_19 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_17 ;
V_1 |= V_18 ;
F_2 ( V_1 ) ;
F_10 ( & V_21 -> V_32 , V_19 ) ;
}
static int F_26 ( struct V_43 * V_44 )
{
return F_27 ( V_44 , & V_55 ,
& V_56 , 0xFF ) ;
}
static struct V_57 * T_3 F_28 ( void )
{
return & V_58 ;
}
static int F_29 ( struct V_43 * V_44 )
{
return F_27 ( V_44 , & V_59 ,
& V_60 , 0xFF ) ;
}
static struct V_57 * T_3 F_30 ( void )
{
return & V_61 ;
}
static struct V_57 * T_3 F_28 ( void )
{
return NULL ;
}
static struct V_57 * T_3 F_30 ( void )
{
return NULL ;
}
