int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
const T_2 * V_3 ;
T_3 V_4 = 0 ;
unsigned long V_5 ;
T_4 V_6 ;
V_2 = F_2 ( NULL , V_7 ) ;
if ( ! V_2 )
return - V_8 ;
V_3 = F_3 ( V_2 , 0 , & V_4 , NULL ) ;
if ( ! V_3 )
return - V_9 ;
if ( V_4 < 4 * sizeof( T_4 ) || V_4 > ( T_3 ) V_10 )
return - V_9 ;
V_5 = ( unsigned long ) V_4 ;
V_6 = F_4 ( V_3 ) ;
if ( ! V_6 )
return - V_9 ;
V_11 = F_5 ( V_6 , V_5 ) ;
if ( ! V_11 )
return - V_12 ;
V_13 = V_6 ;
F_6 ( L_1 ) ;
return 0 ;
}
static int F_7 ( T_4 V_14 , T_4 V_6 )
{
register T_4 T_5 V_15 ( L_2 ) ;
register T_4 T_6 V_15 ( L_3 ) ;
register T_4 T_7 V_15 ( L_4 ) ;
register T_4 T_8 V_15 ( L_5 ) ;
register T_4 T_9 V_15 ( L_6 ) ;
T_7 = V_14 ;
T_8 = 0x3 ;
T_9 = V_6 ;
asm volatile (
__asmeq("%0", "ip")
__asmeq("%1", "r0")
__asmeq("%2", "r4")
__asmeq("%3", "r5")
__asmeq("%4", "r6")
#ifdef F_8
".arch_extension sec\n"
#endif
" smc #0\n"
: "=r" (ip), "=r" (r0)
: "r" (r4), "r" (r5), "r" (r6)
: "r1", "r2", "r3", "r7", "lr");
F_9 ( T_5 != V_16 ) ;
return T_6 ;
}
static void F_10 ( void * V_17 )
{
struct V_18 * V_19 = V_17 ;
T_4 * args = V_11 ;
F_9 ( F_11 () != 0 ) ;
F_9 ( ! args ) ;
F_12 ( V_19 -> V_20 , args ++ ) ;
F_12 ( V_19 -> V_21 , args ++ ) ;
F_12 ( V_19 -> V_22 , args ++ ) ;
F_13 ( V_19 -> V_23 , args ) ;
F_14 () ;
V_19 -> V_24 = F_7 ( V_19 -> V_14 , V_13 ) ;
}
unsigned F_15 ( unsigned V_14 , unsigned V_20 , unsigned V_21 ,
unsigned V_22 , unsigned V_23 )
{
struct V_18 V_19 ;
V_19 . V_14 = V_14 ;
V_19 . V_20 = V_20 ;
V_19 . V_21 = V_21 ;
V_19 . V_22 = V_22 ;
V_19 . V_23 = V_23 ;
V_19 . V_24 = 0 ;
F_16 ( 0 , F_10 , & V_19 , 1 ) ;
return V_19 . V_24 ;
}
