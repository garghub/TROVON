void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_7 = F_2 ( & V_8 ) ;
F_3 (mn, n, &mm->mmu_notifier_mm->list, hlist)
if ( V_4 -> V_9 -> V_10 )
V_4 -> V_9 -> V_10 ( V_4 , V_2 ) ;
F_4 ( & V_8 , V_7 ) ;
F_5 ( & V_2 -> V_11 -> V_12 ) ;
while ( F_6 ( ! F_7 ( & V_2 -> V_11 -> V_13 ) ) ) {
V_4 = F_8 ( V_2 -> V_11 -> V_13 . V_14 ,
struct V_3 ,
V_15 ) ;
F_9 ( & V_4 -> V_15 ) ;
}
F_10 ( & V_2 -> V_11 -> V_12 ) ;
F_11 ( & V_8 ) ;
}
int F_12 ( struct V_1 * V_2 ,
unsigned long V_16 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_17 = 0 , V_7 ;
V_7 = F_2 ( & V_8 ) ;
F_3 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_9 -> V_18 )
V_17 |= V_4 -> V_9 -> V_18 ( V_4 , V_2 , V_16 ) ;
}
F_4 ( & V_8 , V_7 ) ;
return V_17 ;
}
int F_13 ( struct V_1 * V_2 ,
unsigned long V_16 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_17 = 0 , V_7 ;
V_7 = F_2 ( & V_8 ) ;
F_3 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_9 -> V_19 ) {
V_17 = V_4 -> V_9 -> V_19 ( V_4 , V_2 , V_16 ) ;
if ( V_17 )
break;
}
}
F_4 ( & V_8 , V_7 ) ;
return V_17 ;
}
void F_14 ( struct V_1 * V_2 , unsigned long V_16 ,
T_1 V_20 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_7 = F_2 ( & V_8 ) ;
F_3 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_9 -> V_21 )
V_4 -> V_9 -> V_21 ( V_4 , V_2 , V_16 , V_20 ) ;
}
F_4 ( & V_8 , V_7 ) ;
}
void F_15 ( struct V_1 * V_2 ,
unsigned long V_16 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_7 = F_2 ( & V_8 ) ;
F_3 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_9 -> V_22 )
V_4 -> V_9 -> V_22 ( V_4 , V_2 , V_16 ) ;
}
F_4 ( & V_8 , V_7 ) ;
}
void F_16 ( struct V_1 * V_2 ,
unsigned long V_23 , unsigned long V_24 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_7 = F_2 ( & V_8 ) ;
F_3 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_9 -> V_25 )
V_4 -> V_9 -> V_25 ( V_4 , V_2 , V_23 , V_24 ) ;
}
F_4 ( & V_8 , V_7 ) ;
}
void F_17 ( struct V_1 * V_2 ,
unsigned long V_23 , unsigned long V_24 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_7 = F_2 ( & V_8 ) ;
F_3 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_9 -> V_26 )
V_4 -> V_9 -> V_26 ( V_4 , V_2 , V_23 , V_24 ) ;
}
F_4 ( & V_8 , V_7 ) ;
}
static int F_18 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_27 )
{
struct V_11 * V_11 ;
int V_28 ;
F_19 ( F_20 ( & V_2 -> V_29 ) <= 0 ) ;
F_19 ( ! V_8 . V_30 ) ;
V_28 = - V_31 ;
V_11 = F_21 ( sizeof( struct V_11 ) , V_32 ) ;
if ( F_6 ( ! V_11 ) )
goto V_33;
if ( V_27 )
F_22 ( & V_2 -> V_34 ) ;
V_28 = F_23 ( V_2 ) ;
if ( F_6 ( V_28 ) )
goto V_35;
if ( ! F_24 ( V_2 ) ) {
F_25 ( & V_11 -> V_13 ) ;
F_26 ( & V_11 -> V_12 ) ;
V_2 -> V_11 = V_11 ;
V_11 = NULL ;
}
F_27 ( & V_2 -> V_36 ) ;
F_5 ( & V_2 -> V_11 -> V_12 ) ;
F_28 ( & V_4 -> V_15 , & V_2 -> V_11 -> V_13 ) ;
F_10 ( & V_2 -> V_11 -> V_12 ) ;
F_29 ( V_2 ) ;
V_35:
if ( V_27 )
F_30 ( & V_2 -> V_34 ) ;
F_31 ( V_11 ) ;
V_33:
F_19 ( F_20 ( & V_2 -> V_29 ) <= 0 ) ;
return V_28 ;
}
int F_32 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
return F_18 ( V_4 , V_2 , 1 ) ;
}
int F_33 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
return F_18 ( V_4 , V_2 , 0 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
F_19 ( ! F_7 ( & V_2 -> V_11 -> V_13 ) ) ;
F_31 ( V_2 -> V_11 ) ;
V_2 -> V_11 = V_37 ;
}
void F_35 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
F_19 ( F_20 ( & V_2 -> V_36 ) <= 0 ) ;
if ( ! F_36 ( & V_4 -> V_15 ) ) {
int V_7 ;
V_7 = F_2 ( & V_8 ) ;
if ( V_4 -> V_9 -> V_10 )
V_4 -> V_9 -> V_10 ( V_4 , V_2 ) ;
F_4 ( & V_8 , V_7 ) ;
F_5 ( & V_2 -> V_11 -> V_12 ) ;
F_37 ( & V_4 -> V_15 ) ;
F_10 ( & V_2 -> V_11 -> V_12 ) ;
}
F_11 ( & V_8 ) ;
F_19 ( F_20 ( & V_2 -> V_36 ) <= 0 ) ;
F_38 ( V_2 ) ;
}
static int T_2 F_39 ( void )
{
return F_40 ( & V_8 ) ;
}
