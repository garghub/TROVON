static struct V_1 * F_1 ( T_1 V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
T_1 V_5 = sizeof( * V_4 ) + sizeof( struct V_6 ) + V_2 +
V_3 ;
T_2 V_7 ;
V_4 = F_2 ( F_3 ( V_5 ) , V_8 ) ;
if ( V_4 ) {
V_4 -> V_5 = F_4 ( V_5 ) ;
V_7 = F_5 ( struct V_1 , V_9 ) ;
V_4 -> V_10 = F_4 ( V_7 ) ;
V_4 -> V_11 = F_4 ( V_7 + V_2 ) ;
}
return V_4 ;
}
static inline void F_6 ( struct V_1 * V_4 )
{
F_7 ( V_4 ) ;
}
static inline struct V_6 * F_8 (
const struct V_1 * V_4 )
{
return ( void * ) V_4 + F_9 ( V_4 -> V_11 ) ;
}
static inline void * F_10 ( const struct V_1 * V_4 )
{
return ( void * ) V_4 -> V_9 ;
}
static inline void * F_11 ( const struct V_6 * V_12 )
{
return ( void * ) V_12 + F_9 ( V_12 -> V_10 ) ;
}
static int F_12 ( int V_13 )
{
F_13 ( L_1 , V_13 ) ;
switch ( V_13 ) {
case V_14 :
return - V_15 ;
case V_16 :
case V_17 :
return - V_18 ;
case V_19 :
return - V_20 ;
case V_21 :
return - V_22 ;
}
return - V_18 ;
}
static T_2 F_14 ( T_2 V_23 )
{
int V_24 ;
register T_2 T_3 V_25 ( L_2 ) = 1 ;
register T_2 T_4 V_25 ( L_3 ) = ( T_2 ) & V_24 ;
register T_2 T_5 V_25 ( L_4 ) = V_23 ;
do {
asm volatile(
__asmeq("%0", "r0")
__asmeq("%1", "r0")
__asmeq("%2", "r1")
__asmeq("%3", "r2")
#ifdef F_15
".arch_extension sec\n"
#endif
"smc #0 @ switch to secure world\n"
: "=r" (r0)
: "r" (r0), "r" (r1), "r" (r2)
: "r3");
} while ( T_3 == V_26 );
return T_3 ;
}
static int F_16 ( const struct V_1 * V_4 )
{
int V_27 ;
T_2 V_23 = F_17 ( V_4 ) ;
F_18 ( ( void * ) V_4 , V_4 -> V_5 ) ;
F_19 ( V_23 , V_23 + V_4 -> V_5 ) ;
V_27 = F_14 ( V_23 ) ;
if ( V_27 < 0 )
V_27 = F_12 ( V_27 ) ;
return V_27 ;
}
static void F_20 ( unsigned long V_28 , unsigned long V_29 )
{
T_2 V_30 , V_31 ;
asm volatile("mrc p15, 0, %0, c0, c0, 1" : "=r" (ctr));
V_30 = 4 << ( ( V_31 >> 16 ) & 0xf ) ;
V_28 = F_21 ( V_28 , V_30 ) ;
V_29 = F_22 ( V_29 , V_30 ) ;
F_23 ( V_28 , V_29 ) ;
while ( V_28 < V_29 ) {
asm ("mcr p15, 0, %0, c7, c6, 1" : : "r" (start)
: "memory");
V_28 += V_30 ;
}
F_24 () ;
F_25 () ;
}
static int F_26 ( T_2 V_32 , T_2 V_33 , const void * V_34 ,
T_1 V_35 , void * V_36 , T_1 V_37 )
{
int V_27 ;
struct V_1 * V_4 ;
struct V_6 * V_12 ;
unsigned long V_28 , V_29 ;
V_4 = F_1 ( V_35 , V_37 ) ;
if ( ! V_4 )
return - V_22 ;
V_4 -> V_38 = F_4 ( ( V_32 << 10 ) | V_33 ) ;
if ( V_34 )
memcpy ( F_10 ( V_4 ) , V_34 , V_35 ) ;
F_27 ( & V_39 ) ;
V_27 = F_16 ( V_4 ) ;
F_28 ( & V_39 ) ;
if ( V_27 )
goto V_40;
V_12 = F_8 ( V_4 ) ;
V_28 = ( unsigned long ) V_12 ;
do {
F_20 ( V_28 , V_28 + sizeof( * V_12 ) ) ;
} while ( ! V_12 -> V_41 );
V_29 = ( unsigned long ) F_11 ( V_12 ) + V_37 ;
F_20 ( V_28 , V_29 ) ;
if ( V_36 )
memcpy ( V_36 , F_11 ( V_12 ) , V_37 ) ;
V_40:
F_6 ( V_4 ) ;
return V_27 ;
}
static T_6 F_29 ( T_2 V_42 , T_2 V_4 , T_2 V_43 )
{
int V_24 ;
register T_2 T_3 V_25 ( L_2 ) = F_30 ( V_42 , V_4 , 1 ) ;
register T_2 T_4 V_25 ( L_3 ) = ( T_2 ) & V_24 ;
register T_2 T_5 V_25 ( L_4 ) = V_43 ;
asm volatile(
__asmeq("%0", "r0")
__asmeq("%1", "r0")
__asmeq("%2", "r1")
__asmeq("%3", "r2")
#ifdef F_15
".arch_extension sec\n"
#endif
"smc #0 @ switch to secure world\n"
: "=r" (r0)
: "r" (r0), "r" (r1), "r" (r2)
: "r3");
return T_3 ;
}
T_2 F_31 ( void )
{
int V_24 ;
static T_2 V_44 = - 1 ;
register T_2 T_3 V_25 ( L_2 ) ;
register T_2 T_4 V_25 ( L_3 ) ;
if ( V_44 != - 1 )
return V_44 ;
F_27 ( & V_39 ) ;
T_3 = 0x1 << 8 ;
T_4 = ( T_2 ) & V_24 ;
do {
asm volatile(
__asmeq("%0", "r0")
__asmeq("%1", "r1")
__asmeq("%2", "r0")
__asmeq("%3", "r1")
#ifdef F_15
".arch_extension sec\n"
#endif
"smc #0 @ switch to secure world\n"
: "=r" (r0), "=r" (r1)
: "r" (r0), "r" (r1)
: "r2", "r3");
} while ( T_3 == V_26 );
V_44 = T_4 ;
F_28 ( & V_39 ) ;
return V_44 ;
}
static int F_32 ( T_2 V_45 , int V_46 )
{
struct {
T_7 V_46 ;
T_7 V_45 ;
} V_4 ;
V_4 . V_45 = F_4 ( V_45 ) ;
V_4 . V_46 = F_4 ( V_46 ) ;
return F_26 ( V_47 , V_48 ,
& V_4 , sizeof( V_4 ) , NULL , 0 ) ;
}
int F_33 ( void * V_49 , const T_8 * V_50 )
{
int V_46 = 0 ;
int V_51 ;
int V_52 [] = {
V_53 ,
V_54 ,
V_55 ,
V_56 ,
} ;
if ( ! V_50 || ( V_50 && F_34 ( V_50 ) ) )
return - V_18 ;
F_35 (cpu, cpus) {
if ( V_51 < F_36 ( V_52 ) )
V_46 |= V_52 [ V_51 ] ;
else
F_37 ( V_51 , false ) ;
}
return F_32 ( F_17 ( V_49 ) , V_46 ) ;
}
int F_38 ( void * V_49 , const T_8 * V_50 )
{
int V_27 ;
int V_46 = 0 ;
int V_51 ;
F_35 (cpu, cpus) {
if ( V_49 == V_57 [ V_51 ] . V_49 )
continue;
V_46 |= V_57 [ V_51 ] . V_58 ;
}
if ( ! V_46 )
return 0 ;
V_27 = F_32 ( F_17 ( V_49 ) , V_46 ) ;
if ( ! V_27 ) {
F_35 (cpu, cpus)
V_57 [ V_51 ] . V_49 = V_49 ;
}
return V_27 ;
}
void F_39 ( T_2 V_46 )
{
F_29 ( V_47 , V_59 ,
V_46 & V_60 ) ;
}
int F_40 ( T_2 V_32 , T_2 V_33 )
{
int V_27 ;
T_2 V_61 = ( V_32 << 10 ) | V_33 ;
T_2 V_62 = 0 ;
V_27 = F_26 ( V_63 , V_64 , & V_61 ,
sizeof( V_61 ) , & V_62 , sizeof( V_62 ) ) ;
if ( V_27 )
return V_27 ;
return V_62 ;
}
int F_41 ( struct V_65 * V_66 , T_2 V_67 , T_2 * V_68 )
{
if ( V_67 > V_69 )
return - V_70 ;
return F_26 ( V_71 , V_72 ,
V_66 , V_67 * sizeof( * V_66 ) , V_68 , sizeof( * V_68 ) ) ;
}
