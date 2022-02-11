static inline unsigned long F_1 ( void )
{
T_1 V_1 ;
asm volatile("mrc p15, 0, %0, c9, c12, 0" : "=r"(val));
return V_1 ;
}
static inline void F_2 ( unsigned long V_1 )
{
V_1 &= V_2 ;
F_3 () ;
asm volatile("mcr p15, 0, %0, c9, c12, 0" : : "r"(val));
}
static inline int F_4 ( unsigned long V_3 )
{
return V_3 & V_4 ;
}
static inline int F_5 ( unsigned long V_3 ,
enum V_5 V_6 )
{
int V_7 = 0 ;
if ( V_6 == V_8 )
V_7 = V_3 & V_9 ;
else if ( ( V_6 >= V_10 ) && ( V_6 <= V_11 ) )
V_7 = V_3 & F_6 ( V_6 ) ;
else
F_7 ( L_1 ,
F_8 () , V_6 ) ;
return V_7 ;
}
static inline int F_9 ( unsigned int V_12 )
{
T_1 V_1 ;
if ( ( V_12 < V_10 ) || ( V_12 > V_11 ) ) {
F_7 ( L_2
L_3 , F_8 () , V_12 ) ;
return - 1 ;
}
V_1 = ( V_12 - V_13 ) & V_14 ;
asm volatile("mcr p15, 0, %0, c9, c12, 5" : : "r" (val));
F_3 () ;
return V_12 ;
}
static inline T_1 F_10 ( int V_12 )
{
unsigned long V_15 = 0 ;
if ( V_12 == V_8 )
asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (value));
else if ( ( V_12 >= V_10 ) && ( V_12 <= V_11 ) ) {
if ( F_9 ( V_12 ) == V_12 )
asm volatile("mrc p15, 0, %0, c9, c13, 2"
: "=r" (value));
} else
F_7 ( L_4 ,
F_8 () , V_12 ) ;
return V_15 ;
}
static inline void F_11 ( int V_12 , T_1 V_15 )
{
if ( V_12 == V_8 )
asm volatile("mcr p15, 0, %0, c9, c13, 0" : : "r" (value));
else if ( ( V_12 >= V_10 ) && ( V_12 <= V_11 ) ) {
if ( F_9 ( V_12 ) == V_12 )
asm volatile("mcr p15, 0, %0, c9, c13, 2"
: : "r" (value));
} else
F_7 ( L_5 ,
F_8 () , V_12 ) ;
}
static inline void F_12 ( unsigned int V_12 , T_1 V_1 )
{
if ( F_9 ( V_12 ) == V_12 ) {
V_1 &= V_16 ;
asm volatile("mcr p15, 0, %0, c9, c13, 1" : : "r" (val));
}
}
static inline T_1 F_13 ( unsigned int V_12 )
{
T_1 V_1 ;
if ( ( V_12 != V_8 ) &&
( ( V_12 < V_10 ) || ( V_12 > V_11 ) ) ) {
F_7 ( L_6
L_3 , F_8 () , V_12 ) ;
return - 1 ;
}
if ( V_12 == V_8 )
V_1 = V_17 ;
else
V_1 = F_14 ( V_12 ) ;
asm volatile("mcr p15, 0, %0, c9, c12, 1" : : "r" (val));
return V_12 ;
}
static inline T_1 F_15 ( unsigned int V_12 )
{
T_1 V_1 ;
if ( ( V_12 != V_8 ) &&
( ( V_12 < V_10 ) || ( V_12 > V_11 ) ) ) {
F_7 ( L_7
L_3 , F_8 () , V_12 ) ;
return - 1 ;
}
if ( V_12 == V_8 )
V_1 = V_18 ;
else
V_1 = F_16 ( V_12 ) ;
asm volatile("mcr p15, 0, %0, c9, c12, 2" : : "r" (val));
return V_12 ;
}
static inline T_1 F_17 ( unsigned int V_12 )
{
T_1 V_1 ;
if ( ( V_12 != V_8 ) &&
( ( V_12 < V_10 ) || ( V_12 > V_11 ) ) ) {
F_7 ( L_6
L_8 , F_8 () , V_12 ) ;
return - 1 ;
}
if ( V_12 == V_8 )
V_1 = V_19 ;
else
V_1 = F_18 ( V_12 ) ;
asm volatile("mcr p15, 0, %0, c9, c14, 1" : : "r" (val));
return V_12 ;
}
static inline T_1 F_19 ( unsigned int V_12 )
{
T_1 V_1 ;
if ( ( V_12 != V_8 ) &&
( ( V_12 < V_10 ) || ( V_12 > V_11 ) ) ) {
F_7 ( L_7
L_8 , F_8 () , V_12 ) ;
return - 1 ;
}
if ( V_12 == V_8 )
V_1 = V_20 ;
else
V_1 = F_20 ( V_12 ) ;
asm volatile("mcr p15, 0, %0, c9, c14, 2" : : "r" (val));
return V_12 ;
}
static inline T_1 F_21 ( void )
{
T_1 V_1 ;
asm volatile("mrc p15, 0, %0, c9, c12, 3" : "=r" (val));
V_1 &= V_21 ;
asm volatile("mcr p15, 0, %0, c9, c12, 3" : : "r" (val));
return V_1 ;
}
static void F_22 ( void )
{
T_1 V_1 ;
unsigned int V_22 ;
F_23 ( V_23 L_9 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 0" : "=r" (val));
F_23 ( V_23 L_10 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 1" : "=r" (val));
F_23 ( V_23 L_11 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c14, 1" : "=r" (val));
F_23 ( V_23 L_12 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 3" : "=r" (val));
F_23 ( V_23 L_13 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 5" : "=r" (val));
F_23 ( V_23 L_14 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (val));
F_23 ( V_23 L_15 , V_1 ) ;
for ( V_22 = V_10 ; V_22 < V_11 ; V_22 ++ ) {
F_9 ( V_22 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 2" : "=r" (val));
F_23 ( V_23 L_16 ,
V_22 - V_13 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 1" : "=r" (val));
F_23 ( V_23 L_17 ,
V_22 - V_13 , V_1 ) ;
}
}
static void F_24 ( struct V_24 * V_25 , int V_12 )
{
unsigned long V_26 ;
F_25 ( & V_27 , V_26 ) ;
F_15 ( V_12 ) ;
if ( V_12 != V_8 )
F_12 ( V_12 , V_25 -> V_28 ) ;
F_17 ( V_12 ) ;
F_13 ( V_12 ) ;
F_26 ( & V_27 , V_26 ) ;
}
static void F_27 ( struct V_24 * V_25 , int V_12 )
{
unsigned long V_26 ;
F_25 ( & V_27 , V_26 ) ;
F_15 ( V_12 ) ;
F_19 ( V_12 ) ;
F_26 ( & V_27 , V_26 ) ;
}
static T_2 F_28 ( int V_29 , void * V_30 )
{
unsigned long V_3 ;
struct V_31 V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
int V_12 ;
V_3 = F_21 () ;
if ( ! F_4 ( V_3 ) )
return V_37 ;
V_36 = F_29 () ;
F_30 ( & V_32 , 0 ) ;
V_34 = & F_31 ( V_33 ) ;
for ( V_12 = 0 ; V_12 <= V_38 -> V_39 ; ++ V_12 ) {
struct V_40 * V_41 = V_34 -> V_42 [ V_12 ] ;
struct V_24 * V_25 ;
if ( ! F_32 ( V_12 , V_34 -> V_43 ) )
continue;
if ( ! F_5 ( V_3 , V_12 ) )
continue;
V_25 = & V_41 -> V_44 ;
F_33 ( V_41 , V_25 , V_12 , 1 ) ;
V_32 . V_45 = V_41 -> V_44 . V_46 ;
if ( ! F_34 ( V_41 , V_25 , V_12 ) )
continue;
if ( F_35 ( V_41 , 0 , & V_32 , V_36 ) )
V_38 -> V_47 ( V_25 , V_12 ) ;
}
F_36 () ;
return V_48 ;
}
static void F_37 ( void )
{
unsigned long V_26 ;
F_25 ( & V_27 , V_26 ) ;
F_2 ( F_1 () | V_49 ) ;
F_26 ( & V_27 , V_26 ) ;
}
static void F_38 ( void )
{
unsigned long V_26 ;
F_25 ( & V_27 , V_26 ) ;
F_2 ( F_1 () & ~ V_49 ) ;
F_26 ( & V_27 , V_26 ) ;
}
static int F_39 ( struct V_33 * V_34 ,
struct V_24 * V_41 )
{
int V_12 ;
if ( V_41 -> V_28 == V_50 ) {
if ( F_40 ( V_8 , V_34 -> V_51 ) )
return - V_52 ;
return V_8 ;
} else {
for ( V_12 = V_10 ; V_12 <= V_38 -> V_39 ; ++ V_12 ) {
if ( ! F_40 ( V_12 , V_34 -> V_51 ) )
return V_12 ;
}
return - V_52 ;
}
}
static void F_41 ( void * V_53 )
{
T_1 V_12 , V_54 = V_38 -> V_39 ;
for ( V_12 = 1 ; V_12 < V_54 ; ++ V_12 )
F_27 ( NULL , V_12 ) ;
F_2 ( V_55 | V_56 ) ;
}
static T_1 T_3 F_42 ( void )
{
T_1 V_54 ;
V_54 = ( F_1 () >> V_57 ) & V_58 ;
return V_54 + 1 ;
}
static const struct V_59 * T_3 F_43 ( void )
{
V_60 . V_61 = V_62 ;
V_60 . V_63 = L_18 ;
V_60 . V_64 = & V_65 ;
V_60 . V_66 = & V_67 ;
V_60 . V_39 = F_42 () ;
return & V_60 ;
}
static const struct V_59 * T_3 F_44 ( void )
{
V_60 . V_61 = V_68 ;
V_60 . V_63 = L_19 ;
V_60 . V_64 = & V_69 ;
V_60 . V_66 = & V_70 ;
V_60 . V_39 = F_42 () ;
return & V_60 ;
}
static const struct V_59 * T_3 F_43 ( void )
{
return NULL ;
}
static const struct V_59 * T_3 F_44 ( void )
{
return NULL ;
}
