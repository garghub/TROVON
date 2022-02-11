int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
memset ( & V_4 -> V_5 , 0 , sizeof( V_4 -> V_5 ) ) ;
F_2 ( & V_4 -> V_5 . V_6 ) ;
V_4 -> V_5 . V_7 = 0xffffffffUL ;
V_4 -> V_5 . V_8 = 0xffffffffUL ;
return 0 ;
}
static unsigned F_3 ( T_1 * V_9 )
{
struct V_10 * V_11 ;
T_1 * V_12 ;
unsigned V_13 ;
if ( ! F_4 ( & V_9 -> V_6 ) ) {
F_5 ( & V_9 -> V_6 , & V_14 ) ;
}
else {
V_13 = F_6 ( V_15 , V_16 , 1 ) ;
if ( V_13 < V_16 ) {
F_7 ( V_13 , V_15 ) ;
}
else {
V_12 = NULL ;
F_8 (_p, &cxn_owners_lru) {
V_12 = F_9 ( V_11 , T_1 , V_6 ) ;
if ( ! V_12 -> V_17 && V_12 -> V_18 != V_19 )
break;
}
F_10 ( V_11 == & V_14 ) ;
V_13 = V_12 -> V_18 ;
V_12 -> V_18 = 0 ;
F_11 ( & V_12 -> V_6 ) ;
F_12 ( V_13 ) ;
}
V_9 -> V_18 = V_13 ;
F_13 ( & V_9 -> V_6 , & V_14 ) ;
}
return V_9 -> V_18 ;
}
void F_14 ( T_1 * V_20 , T_1 * V_9 , T_2 * V_21 )
{
unsigned long V_22 ;
V_22 = F_15 ( V_21 ) ;
V_20 -> V_17 = 0 ;
asm volatile("movsg scr0,%0" : "=r"(old->itlb_cached_pge));
asm volatile("movsg dampr4,%0" : "=r"(old->itlb_ptd_mapping));
asm volatile("movsg scr1,%0" : "=r"(old->dtlb_cached_pge));
asm volatile("movsg dampr5,%0" : "=r"(old->dtlb_ptd_mapping));
F_16 ( & V_23 ) ;
F_3 ( V_9 ) ;
V_9 -> V_17 = 1 ;
F_17 ( & V_23 ) ;
asm volatile("movgs %0,cxnr" : : "r"(ctx->id));
asm volatile("movgs %0,scr0" : : "r"(ctx->itlb_cached_pge));
asm volatile("movgs %0,dampr4" : : "r"(ctx->itlb_ptd_mapping));
asm volatile("movgs %0,scr1" : : "r"(ctx->dtlb_cached_pge));
asm volatile("movgs %0,dampr5" : : "r"(ctx->dtlb_ptd_mapping));
asm volatile("movgs %0,ttbr" : : "r"(_pgd));
asm volatile("movgs %0,dampr3"
:: "r"(_pgd | xAMPRx_L | xAMPRx_M | xAMPRx_SS_16Kb |
xAMPRx_S | xAMPRx_C | xAMPRx_V));
}
void F_18 ( struct V_3 * V_4 )
{
T_1 * V_9 = & V_4 -> V_5 ;
F_16 ( & V_23 ) ;
if ( ! F_4 ( & V_9 -> V_6 ) ) {
if ( V_9 -> V_18 == V_19 )
V_19 = - 1 ;
F_11 ( & V_9 -> V_6 ) ;
F_19 ( V_9 -> V_18 , V_15 ) ;
F_12 ( V_9 -> V_18 ) ;
V_9 -> V_18 = 0 ;
}
F_17 ( & V_23 ) ;
}
char * F_20 ( struct V_3 * V_4 , char * V_24 )
{
F_16 ( & V_23 ) ;
V_24 += sprintf ( V_24 , L_1 , V_4 -> V_5 . V_18 ) ;
F_17 ( & V_23 ) ;
return V_24 ;
}
int F_21 ( T_3 V_25 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = NULL ;
int V_26 ;
if ( V_25 == 0 ) {
V_19 = - 1 ;
return 0 ;
}
V_26 = - V_27 ;
F_22 ( & V_28 ) ;
V_2 = F_23 ( V_25 ) ;
if ( V_2 ) {
V_26 = - V_29 ;
F_24 ( V_2 ) ;
if ( V_2 -> V_4 ) {
V_4 = V_2 -> V_4 ;
F_25 ( V_4 ) ;
V_26 = 0 ;
}
F_26 ( V_2 ) ;
}
F_27 ( & V_28 ) ;
if ( V_26 < 0 )
return V_26 ;
F_16 ( & V_23 ) ;
V_19 = F_3 ( & V_4 -> V_5 ) ;
F_17 ( & V_23 ) ;
F_28 ( V_4 ) ;
return 0 ;
}
