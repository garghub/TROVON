void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_2 () ;
F_3 (mn, n, &mm->mmu_notifier_mm->list, hlist)
if ( V_4 -> V_7 -> V_8 )
V_4 -> V_7 -> V_8 ( V_4 , V_2 ) ;
F_4 () ;
F_5 ( & V_2 -> V_9 -> V_10 ) ;
while ( F_6 ( ! F_7 ( & V_2 -> V_9 -> V_11 ) ) ) {
V_4 = F_8 ( V_2 -> V_9 -> V_11 . V_12 ,
struct V_3 ,
V_13 ) ;
F_9 ( & V_4 -> V_13 ) ;
}
F_10 ( & V_2 -> V_9 -> V_10 ) ;
F_11 () ;
}
int F_12 ( struct V_1 * V_2 ,
unsigned long V_14 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_15 = 0 ;
F_2 () ;
F_3 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_7 -> V_16 )
V_15 |= V_4 -> V_7 -> V_16 ( V_4 , V_2 , V_14 ) ;
}
F_4 () ;
return V_15 ;
}
int F_13 ( struct V_1 * V_2 ,
unsigned long V_14 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_15 = 0 ;
F_2 () ;
F_3 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_7 -> V_17 ) {
V_15 = V_4 -> V_7 -> V_17 ( V_4 , V_2 , V_14 ) ;
if ( V_15 )
break;
}
}
F_4 () ;
return V_15 ;
}
void F_14 ( struct V_1 * V_2 , unsigned long V_14 ,
T_1 V_18 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_2 () ;
F_3 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_7 -> V_19 )
V_4 -> V_7 -> V_19 ( V_4 , V_2 , V_14 , V_18 ) ;
else if ( V_4 -> V_7 -> V_20 )
V_4 -> V_7 -> V_20 ( V_4 , V_2 , V_14 ) ;
}
F_4 () ;
}
void F_15 ( struct V_1 * V_2 ,
unsigned long V_14 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_2 () ;
F_3 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_7 -> V_20 )
V_4 -> V_7 -> V_20 ( V_4 , V_2 , V_14 ) ;
}
F_4 () ;
}
void F_16 ( struct V_1 * V_2 ,
unsigned long V_21 , unsigned long V_22 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_2 () ;
F_3 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_7 -> V_23 )
V_4 -> V_7 -> V_23 ( V_4 , V_2 , V_21 , V_22 ) ;
}
F_4 () ;
}
void F_17 ( struct V_1 * V_2 ,
unsigned long V_21 , unsigned long V_22 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_2 () ;
F_3 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_7 -> V_24 )
V_4 -> V_7 -> V_24 ( V_4 , V_2 , V_21 , V_22 ) ;
}
F_4 () ;
}
static int F_18 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_25 )
{
struct V_9 * V_9 ;
int V_26 ;
F_19 ( F_20 ( & V_2 -> V_27 ) <= 0 ) ;
V_26 = - V_28 ;
V_9 = F_21 ( sizeof( struct V_9 ) , V_29 ) ;
if ( F_6 ( ! V_9 ) )
goto V_30;
if ( V_25 )
F_22 ( & V_2 -> V_31 ) ;
V_26 = F_23 ( V_2 ) ;
if ( F_6 ( V_26 ) )
goto V_32;
if ( ! F_24 ( V_2 ) ) {
F_25 ( & V_9 -> V_11 ) ;
F_26 ( & V_9 -> V_10 ) ;
V_2 -> V_9 = V_9 ;
V_9 = NULL ;
}
F_27 ( & V_2 -> V_33 ) ;
F_5 ( & V_2 -> V_9 -> V_10 ) ;
F_28 ( & V_4 -> V_13 , & V_2 -> V_9 -> V_11 ) ;
F_10 ( & V_2 -> V_9 -> V_10 ) ;
F_29 ( V_2 ) ;
V_32:
if ( V_25 )
F_30 ( & V_2 -> V_31 ) ;
F_31 ( V_9 ) ;
V_30:
F_19 ( F_20 ( & V_2 -> V_27 ) <= 0 ) ;
return V_26 ;
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
F_19 ( ! F_7 ( & V_2 -> V_9 -> V_11 ) ) ;
F_31 ( V_2 -> V_9 ) ;
V_2 -> V_9 = V_34 ;
}
void F_35 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
F_19 ( F_20 ( & V_2 -> V_33 ) <= 0 ) ;
if ( ! F_36 ( & V_4 -> V_13 ) ) {
F_2 () ;
if ( V_4 -> V_7 -> V_8 )
V_4 -> V_7 -> V_8 ( V_4 , V_2 ) ;
F_4 () ;
F_5 ( & V_2 -> V_9 -> V_10 ) ;
F_37 ( & V_4 -> V_13 ) ;
F_10 ( & V_2 -> V_9 -> V_10 ) ;
}
F_11 () ;
F_19 ( F_20 ( & V_2 -> V_33 ) <= 0 ) ;
F_38 ( V_2 ) ;
}
