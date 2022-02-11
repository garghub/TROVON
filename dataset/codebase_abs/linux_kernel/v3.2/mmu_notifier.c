void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_5 -> V_6 ) ;
while ( F_3 ( ! F_4 ( & V_2 -> V_5 -> V_7 ) ) ) {
V_4 = F_5 ( V_2 -> V_5 -> V_7 . V_8 ,
struct V_3 ,
V_9 ) ;
F_6 ( & V_4 -> V_9 ) ;
F_7 () ;
F_8 ( & V_2 -> V_5 -> V_6 ) ;
if ( V_4 -> V_10 -> V_11 )
V_4 -> V_10 -> V_11 ( V_4 , V_2 ) ;
F_9 () ;
F_2 ( & V_2 -> V_5 -> V_6 ) ;
}
F_8 ( & V_2 -> V_5 -> V_6 ) ;
F_10 () ;
}
int F_11 ( struct V_1 * V_2 ,
unsigned long V_12 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
int V_15 = 0 ;
F_7 () ;
F_12 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_10 -> V_16 )
V_15 |= V_4 -> V_10 -> V_16 ( V_4 , V_2 , V_12 ) ;
}
F_9 () ;
return V_15 ;
}
int F_13 ( struct V_1 * V_2 ,
unsigned long V_12 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
int V_15 = 0 ;
F_7 () ;
F_12 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_10 -> V_17 ) {
V_15 = V_4 -> V_10 -> V_17 ( V_4 , V_2 , V_12 ) ;
if ( V_15 )
break;
}
}
F_9 () ;
return V_15 ;
}
void F_14 ( struct V_1 * V_2 , unsigned long V_12 ,
T_1 V_18 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
F_7 () ;
F_12 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_10 -> V_19 )
V_4 -> V_10 -> V_19 ( V_4 , V_2 , V_12 , V_18 ) ;
else if ( V_4 -> V_10 -> V_20 )
V_4 -> V_10 -> V_20 ( V_4 , V_2 , V_12 ) ;
}
F_9 () ;
}
void F_15 ( struct V_1 * V_2 ,
unsigned long V_12 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
F_7 () ;
F_12 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_10 -> V_20 )
V_4 -> V_10 -> V_20 ( V_4 , V_2 , V_12 ) ;
}
F_9 () ;
}
void F_16 ( struct V_1 * V_2 ,
unsigned long V_21 , unsigned long V_22 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
F_7 () ;
F_12 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_10 -> V_23 )
V_4 -> V_10 -> V_23 ( V_4 , V_2 , V_21 , V_22 ) ;
}
F_9 () ;
}
void F_17 ( struct V_1 * V_2 ,
unsigned long V_21 , unsigned long V_22 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
F_7 () ;
F_12 (mn, n, &mm->mmu_notifier_mm->list, hlist) {
if ( V_4 -> V_10 -> V_24 )
V_4 -> V_10 -> V_24 ( V_4 , V_2 , V_21 , V_22 ) ;
}
F_9 () ;
}
static int F_18 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_25 )
{
struct V_5 * V_5 ;
int V_26 ;
F_19 ( F_20 ( & V_2 -> V_27 ) <= 0 ) ;
V_26 = - V_28 ;
V_5 = F_21 ( sizeof( struct V_5 ) , V_29 ) ;
if ( F_3 ( ! V_5 ) )
goto V_30;
if ( V_25 )
F_22 ( & V_2 -> V_31 ) ;
V_26 = F_23 ( V_2 ) ;
if ( F_3 ( V_26 ) )
goto V_32;
if ( ! F_24 ( V_2 ) ) {
F_25 ( & V_5 -> V_7 ) ;
F_26 ( & V_5 -> V_6 ) ;
V_2 -> V_5 = V_5 ;
V_5 = NULL ;
}
F_27 ( & V_2 -> V_33 ) ;
F_2 ( & V_2 -> V_5 -> V_6 ) ;
F_28 ( & V_4 -> V_9 , & V_2 -> V_5 -> V_7 ) ;
F_8 ( & V_2 -> V_5 -> V_6 ) ;
F_29 ( V_2 ) ;
V_32:
if ( V_25 )
F_30 ( & V_2 -> V_31 ) ;
F_31 ( V_5 ) ;
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
F_19 ( ! F_4 ( & V_2 -> V_5 -> V_7 ) ) ;
F_31 ( V_2 -> V_5 ) ;
V_2 -> V_5 = V_34 ;
}
void F_35 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
F_19 ( F_20 ( & V_2 -> V_33 ) <= 0 ) ;
F_2 ( & V_2 -> V_5 -> V_6 ) ;
if ( ! F_36 ( & V_4 -> V_9 ) ) {
F_37 ( & V_4 -> V_9 ) ;
F_7 () ;
F_8 ( & V_2 -> V_5 -> V_6 ) ;
if ( V_4 -> V_10 -> V_11 )
V_4 -> V_10 -> V_11 ( V_4 , V_2 ) ;
F_9 () ;
} else
F_8 ( & V_2 -> V_5 -> V_6 ) ;
F_10 () ;
F_19 ( F_20 ( & V_2 -> V_33 ) <= 0 ) ;
F_38 ( V_2 ) ;
}
