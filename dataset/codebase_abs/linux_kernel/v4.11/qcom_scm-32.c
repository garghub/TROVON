static inline struct V_1 * F_1 (
const struct V_2 * V_3 )
{
return ( void * ) V_3 + F_2 ( V_3 -> V_4 ) ;
}
static inline void * F_3 ( const struct V_2 * V_3 )
{
return ( void * ) V_3 -> V_5 ;
}
static inline void * F_4 ( const struct V_1 * V_6 )
{
return ( void * ) V_6 + F_2 ( V_6 -> V_7 ) ;
}
static T_1 F_5 ( T_1 V_8 )
{
int V_9 ;
register T_1 T_2 V_10 ( L_1 ) = 1 ;
register T_1 T_3 V_10 ( L_2 ) = ( T_1 ) & V_9 ;
register T_1 T_4 V_10 ( L_3 ) = V_8 ;
do {
asm volatile(
__asmeq("%0", "r0")
__asmeq("%1", "r0")
__asmeq("%2", "r1")
__asmeq("%3", "r2")
#ifdef F_6
".arch_extension sec\n"
#endif
"smc #0 @ switch to secure world\n"
: "=r" (r0)
: "r" (r0), "r" (r1), "r" (r2)
: "r3");
} while ( T_2 == V_11 );
return T_2 ;
}
static int F_7 ( struct V_12 * V_13 , T_1 V_14 , T_1 V_15 ,
const void * V_16 , T_5 V_17 , void * V_18 ,
T_5 V_19 )
{
int V_20 ;
struct V_2 * V_3 ;
struct V_1 * V_6 ;
T_5 V_21 = sizeof( * V_3 ) + V_17 + sizeof( * V_6 ) + V_19 ;
T_6 V_22 ;
V_3 = F_8 ( F_9 ( V_21 ) , V_23 ) ;
if ( ! V_3 )
return - V_24 ;
V_3 -> V_25 = F_10 ( V_21 ) ;
V_3 -> V_7 = F_10 ( sizeof( * V_3 ) ) ;
V_3 -> V_4 = F_10 ( sizeof( * V_3 ) + V_17 ) ;
V_3 -> V_26 = F_10 ( ( V_14 << 10 ) | V_15 ) ;
if ( V_16 )
memcpy ( F_3 ( V_3 ) , V_16 , V_17 ) ;
V_6 = F_1 ( V_3 ) ;
V_22 = F_11 ( V_13 , V_3 , V_21 , V_27 ) ;
if ( F_12 ( V_13 , V_22 ) ) {
F_13 ( V_3 ) ;
return - V_24 ;
}
F_14 ( & V_28 ) ;
V_20 = F_5 ( V_22 ) ;
if ( V_20 < 0 )
V_20 = F_15 ( V_20 ) ;
F_16 ( & V_28 ) ;
if ( V_20 )
goto V_29;
do {
F_17 ( V_13 , V_22 + sizeof( * V_3 ) + V_17 ,
sizeof( * V_6 ) , V_30 ) ;
} while ( ! V_6 -> V_31 );
if ( V_18 ) {
F_17 ( V_13 , V_22 + sizeof( * V_3 ) + V_17 +
F_2 ( V_6 -> V_7 ) ,
V_19 , V_30 ) ;
memcpy ( V_18 , F_4 ( V_6 ) ,
V_19 ) ;
}
V_29:
F_18 ( V_13 , V_22 , V_21 , V_27 ) ;
F_13 ( V_3 ) ;
return V_20 ;
}
static T_7 F_19 ( T_1 V_32 , T_1 V_3 , T_1 V_33 )
{
int V_9 ;
register T_1 T_2 V_10 ( L_1 ) = F_20 ( V_32 , V_3 , 1 ) ;
register T_1 T_3 V_10 ( L_2 ) = ( T_1 ) & V_9 ;
register T_1 T_4 V_10 ( L_3 ) = V_33 ;
asm volatile(
__asmeq("%0", "r0")
__asmeq("%1", "r0")
__asmeq("%2", "r1")
__asmeq("%3", "r2")
#ifdef F_6
".arch_extension sec\n"
#endif
"smc #0 @ switch to secure world\n"
: "=r" (r0)
: "r" (r0), "r" (r1), "r" (r2)
: "r3");
return T_2 ;
}
static T_7 F_21 ( T_1 V_32 , T_1 V_3 , T_1 V_33 , T_1 V_34 )
{
int V_9 ;
register T_1 T_2 V_10 ( L_1 ) = F_20 ( V_32 , V_3 , 2 ) ;
register T_1 T_3 V_10 ( L_2 ) = ( T_1 ) & V_9 ;
register T_1 T_4 V_10 ( L_3 ) = V_33 ;
register T_1 T_8 V_10 ( L_4 ) = V_34 ;
asm volatile(
__asmeq("%0", "r0")
__asmeq("%1", "r0")
__asmeq("%2", "r1")
__asmeq("%3", "r2")
__asmeq("%4", "r3")
#ifdef F_6
".arch_extension sec\n"
#endif
"smc #0 @ switch to secure world\n"
: "=r" (r0)
: "r" (r0), "r" (r1), "r" (r2), "r" (r3)
);
return T_2 ;
}
T_1 F_22 ( void )
{
int V_9 ;
static T_1 V_35 = - 1 ;
register T_1 T_2 V_10 ( L_1 ) ;
register T_1 T_3 V_10 ( L_2 ) ;
if ( V_35 != - 1 )
return V_35 ;
F_14 ( & V_28 ) ;
T_2 = 0x1 << 8 ;
T_3 = ( T_1 ) & V_9 ;
do {
asm volatile(
__asmeq("%0", "r0")
__asmeq("%1", "r1")
__asmeq("%2", "r0")
__asmeq("%3", "r1")
#ifdef F_6
".arch_extension sec\n"
#endif
"smc #0 @ switch to secure world\n"
: "=r" (r0), "=r" (r1)
: "r" (r0), "r" (r1)
: "r2", "r3");
} while ( T_2 == V_11 );
V_35 = T_3 ;
F_16 ( & V_28 ) ;
return V_35 ;
}
int F_23 ( void * V_36 , const T_9 * V_37 )
{
int V_38 = 0 ;
int V_39 ;
int V_40 [] = {
V_41 ,
V_42 ,
V_43 ,
V_44 ,
} ;
if ( ! V_37 || ( V_37 && F_24 ( V_37 ) ) )
return - V_45 ;
F_25 (cpu, cpus) {
if ( V_39 < F_26 ( V_40 ) )
V_38 |= V_40 [ V_39 ] ;
else
F_27 ( V_39 , false ) ;
}
return F_21 ( V_46 , V_47 ,
V_38 , F_28 ( V_36 ) ) ;
}
int F_29 ( struct V_12 * V_13 , void * V_36 ,
const T_9 * V_37 )
{
int V_20 ;
int V_38 = 0 ;
int V_39 ;
struct {
T_10 V_38 ;
T_10 V_48 ;
} V_3 ;
F_25 (cpu, cpus) {
if ( V_36 == V_49 [ V_39 ] . V_36 )
continue;
V_38 |= V_49 [ V_39 ] . V_50 ;
}
if ( ! V_38 )
return 0 ;
V_3 . V_48 = F_10 ( F_28 ( V_36 ) ) ;
V_3 . V_38 = F_10 ( V_38 ) ;
V_20 = F_7 ( V_13 , V_46 , V_47 ,
& V_3 , sizeof( V_3 ) , NULL , 0 ) ;
if ( ! V_20 ) {
F_25 (cpu, cpus)
V_49 [ V_39 ] . V_36 = V_36 ;
}
return V_20 ;
}
void F_30 ( T_1 V_38 )
{
F_19 ( V_46 , V_51 ,
V_38 & V_52 ) ;
}
int F_31 ( struct V_12 * V_13 , T_1 V_14 , T_1 V_15 )
{
int V_20 ;
T_10 V_53 = F_10 ( ( V_14 << 10 ) | V_15 ) ;
T_10 V_54 = 0 ;
V_20 = F_7 ( V_13 , V_55 , V_56 ,
& V_53 , sizeof( V_53 ) , & V_54 ,
sizeof( V_54 ) ) ;
if ( V_20 )
return V_20 ;
return F_2 ( V_54 ) ;
}
int F_32 ( struct V_12 * V_13 , struct V_57 * V_58 ,
T_1 V_59 , T_1 * V_60 )
{
if ( V_59 > V_61 )
return - V_62 ;
return F_7 ( V_13 , V_63 , V_64 ,
V_58 , V_59 * sizeof( * V_58 ) , V_60 , sizeof( * V_60 ) ) ;
}
void F_33 ( void )
{
}
bool F_34 ( struct V_12 * V_13 , T_1 V_65 )
{
T_10 V_29 ;
T_10 V_66 ;
int V_20 ;
V_66 = F_10 ( V_65 ) ;
V_20 = F_7 ( V_13 , V_67 ,
V_68 ,
& V_66 , sizeof( V_66 ) ,
& V_29 , sizeof( V_29 ) ) ;
return V_20 ? false : ! ! V_29 ;
}
int F_35 ( struct V_12 * V_13 , T_1 V_65 ,
T_6 V_69 )
{
T_10 V_70 ;
int V_20 ;
struct {
T_10 V_71 ;
T_10 V_72 ;
} V_73 ;
V_73 . V_71 = F_10 ( V_65 ) ;
V_73 . V_72 = F_10 ( V_69 ) ;
V_20 = F_7 ( V_13 , V_67 ,
V_74 ,
& V_73 , sizeof( V_73 ) ,
& V_70 , sizeof( V_70 ) ) ;
return V_20 ? : F_2 ( V_70 ) ;
}
int F_36 ( struct V_12 * V_13 , T_1 V_65 ,
T_11 V_48 , T_11 V_75 )
{
T_10 V_70 ;
int V_20 ;
struct {
T_10 V_71 ;
T_10 V_48 ;
T_10 V_25 ;
} V_73 ;
V_73 . V_71 = F_10 ( V_65 ) ;
V_73 . V_48 = F_10 ( V_48 ) ;
V_73 . V_25 = F_10 ( V_75 ) ;
V_20 = F_7 ( V_13 , V_67 ,
V_76 ,
& V_73 , sizeof( V_73 ) ,
& V_70 , sizeof( V_70 ) ) ;
return V_20 ? : F_2 ( V_70 ) ;
}
int F_37 ( struct V_12 * V_13 , T_1 V_65 )
{
T_10 V_29 ;
T_10 V_66 ;
int V_20 ;
V_66 = F_10 ( V_65 ) ;
V_20 = F_7 ( V_13 , V_67 ,
V_77 ,
& V_66 , sizeof( V_66 ) ,
& V_29 , sizeof( V_29 ) ) ;
return V_20 ? : F_2 ( V_29 ) ;
}
int F_38 ( struct V_12 * V_13 , T_1 V_65 )
{
T_10 V_29 ;
T_10 V_66 ;
int V_20 ;
V_66 = F_10 ( V_65 ) ;
V_20 = F_7 ( V_13 , V_67 ,
V_78 ,
& V_66 , sizeof( V_66 ) ,
& V_29 , sizeof( V_29 ) ) ;
return V_20 ? : F_2 ( V_29 ) ;
}
int F_39 ( struct V_12 * V_13 , bool V_79 )
{
T_10 V_29 ;
T_10 V_66 = F_10 ( V_79 ) ;
int V_20 ;
V_20 = F_7 ( V_13 , V_67 , V_80 ,
& V_66 , sizeof( V_66 ) ,
& V_29 , sizeof( V_29 ) ) ;
return V_20 ? : F_2 ( V_29 ) ;
}
int F_40 ( struct V_12 * V_13 , T_1 V_81 , T_1 V_26 )
{
struct {
T_10 V_81 ;
T_10 V_26 ;
} V_58 ;
T_10 V_70 = 0 ;
int V_20 ;
V_58 . V_81 = F_10 ( V_81 ) ;
V_58 . V_26 = F_10 ( V_26 ) ;
V_20 = F_7 ( V_13 , V_46 , V_82 ,
& V_58 , sizeof( V_58 ) , & V_70 , sizeof( V_70 ) ) ;
return V_20 ? : F_2 ( V_70 ) ;
}
