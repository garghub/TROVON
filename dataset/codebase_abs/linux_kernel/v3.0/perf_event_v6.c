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
if ( V_7 == V_16 ) {
V_17 = 0 ;
V_18 = V_20 ;
} else if ( V_9 == V_16 ) {
V_17 = V_21 ;
V_18 = ( V_15 -> V_22 << V_23 ) |
V_24 ;
} else if ( V_11 == V_16 ) {
V_17 = V_25 ;
V_18 = ( V_15 -> V_22 << V_26 ) |
V_27 ;
} else {
F_5 ( 1 , L_1 , V_16 ) ;
return;
}
F_9 ( & V_28 , V_19 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_17 ;
V_1 |= V_18 ;
F_2 ( V_1 ) ;
F_10 ( & V_28 , V_19 ) ;
}
static T_2
F_11 ( int V_29 ,
void * V_30 )
{
unsigned long V_2 = F_1 () ;
struct V_31 V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
int V_16 ;
if ( ! F_3 ( V_2 ) )
return V_37 ;
V_36 = F_12 () ;
F_2 ( V_2 ) ;
F_13 ( & V_32 , 0 ) ;
V_34 = & F_14 ( V_33 ) ;
for ( V_16 = 0 ; V_16 <= V_38 -> V_39 ; ++ V_16 ) {
struct V_40 * V_41 = V_34 -> V_42 [ V_16 ] ;
struct V_14 * V_15 ;
if ( ! F_15 ( V_16 , V_34 -> V_43 ) )
continue;
if ( ! F_4 ( V_2 , V_16 ) )
continue;
V_15 = & V_41 -> V_44 ;
F_16 ( V_41 , V_15 , V_16 , 1 ) ;
V_32 . V_45 = V_41 -> V_44 . V_46 ;
if ( ! F_17 ( V_41 , V_15 , V_16 ) )
continue;
if ( F_18 ( V_41 , 0 , & V_32 , V_36 ) )
V_38 -> V_47 ( V_15 , V_16 ) ;
}
F_19 () ;
return V_48 ;
}
static void
F_20 ( void )
{
unsigned long V_19 , V_1 ;
F_9 ( & V_28 , V_19 ) ;
V_1 = F_1 () ;
V_1 |= V_49 ;
F_2 ( V_1 ) ;
F_10 ( & V_28 , V_19 ) ;
}
static void
F_21 ( void )
{
unsigned long V_19 , V_1 ;
F_9 ( & V_28 , V_19 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_49 ;
F_2 ( V_1 ) ;
F_10 ( & V_28 , V_19 ) ;
}
static int
F_22 ( struct V_33 * V_34 ,
struct V_14 * V_41 )
{
if ( V_50 == V_41 -> V_22 ) {
if ( F_23 ( V_7 , V_34 -> V_51 ) )
return - V_52 ;
return V_7 ;
} else {
if ( ! F_23 ( V_11 , V_34 -> V_51 ) )
return V_11 ;
if ( ! F_23 ( V_9 , V_34 -> V_51 ) )
return V_9 ;
return - V_52 ;
}
}
static void
F_24 ( struct V_14 * V_15 ,
int V_16 )
{
unsigned long V_1 , V_17 , V_18 , V_19 ;
if ( V_7 == V_16 ) {
V_17 = V_20 ;
V_18 = 0 ;
} else if ( V_9 == V_16 ) {
V_17 = V_24 | V_21 ;
V_18 = V_53 << V_23 ;
} else if ( V_11 == V_16 ) {
V_17 = V_27 | V_25 ;
V_18 = V_53 << V_26 ;
} else {
F_5 ( 1 , L_1 , V_16 ) ;
return;
}
F_9 ( & V_28 , V_19 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_17 ;
V_1 |= V_18 ;
F_2 ( V_1 ) ;
F_10 ( & V_28 , V_19 ) ;
}
static void
F_25 ( struct V_14 * V_15 ,
int V_16 )
{
unsigned long V_1 , V_17 , V_19 , V_18 = 0 ;
if ( V_7 == V_16 ) {
V_17 = V_20 ;
} else if ( V_9 == V_16 ) {
V_17 = V_24 ;
} else if ( V_11 == V_16 ) {
V_17 = V_27 ;
} else {
F_5 ( 1 , L_1 , V_16 ) ;
return;
}
F_9 ( & V_28 , V_19 ) ;
V_1 = F_1 () ;
V_1 &= ~ V_17 ;
V_1 |= V_18 ;
F_2 ( V_1 ) ;
F_10 ( & V_28 , V_19 ) ;
}
static const struct V_54 * T_3 F_26 ( void )
{
return & V_55 ;
}
static const struct V_54 * T_3 F_27 ( void )
{
return & V_56 ;
}
static const struct V_54 * T_3 F_26 ( void )
{
return NULL ;
}
static const struct V_54 * T_3 F_27 ( void )
{
return NULL ;
}
