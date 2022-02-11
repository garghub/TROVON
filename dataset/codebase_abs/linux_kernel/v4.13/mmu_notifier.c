void F_1 ( struct V_1 * V_2 ,
void (* F_2)( struct V_1 * V_2 ) )
{
F_3 ( & V_3 , V_2 , F_2 ) ;
}
void F_4 ( void )
{
F_5 ( & V_3 ) ;
}
void F_6 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_7 ( & V_3 ) ;
F_8 (mn, &mm->mmu_notifier_mm->list, hlist)
if ( V_7 -> V_9 -> V_10 )
V_7 -> V_9 -> V_10 ( V_7 , V_5 ) ;
F_9 ( & V_5 -> V_11 -> V_12 ) ;
while ( F_10 ( ! F_11 ( & V_5 -> V_11 -> V_13 ) ) ) {
V_7 = F_12 ( V_5 -> V_11 -> V_13 . V_14 ,
struct V_6 ,
V_15 ) ;
F_13 ( & V_7 -> V_15 ) ;
}
F_14 ( & V_5 -> V_11 -> V_12 ) ;
F_15 ( & V_3 , V_8 ) ;
F_16 ( & V_3 ) ;
}
int F_17 ( struct V_4 * V_5 ,
unsigned long V_16 ,
unsigned long V_17 )
{
struct V_6 * V_7 ;
int V_18 = 0 , V_8 ;
V_8 = F_7 ( & V_3 ) ;
F_8 (mn, &mm->mmu_notifier_mm->list, hlist) {
if ( V_7 -> V_9 -> V_19 )
V_18 |= V_7 -> V_9 -> V_19 ( V_7 , V_5 , V_16 , V_17 ) ;
}
F_15 ( & V_3 , V_8 ) ;
return V_18 ;
}
int F_18 ( struct V_4 * V_5 ,
unsigned long V_16 ,
unsigned long V_17 )
{
struct V_6 * V_7 ;
int V_18 = 0 , V_8 ;
V_8 = F_7 ( & V_3 ) ;
F_8 (mn, &mm->mmu_notifier_mm->list, hlist) {
if ( V_7 -> V_9 -> V_20 )
V_18 |= V_7 -> V_9 -> V_20 ( V_7 , V_5 , V_16 , V_17 ) ;
}
F_15 ( & V_3 , V_8 ) ;
return V_18 ;
}
int F_19 ( struct V_4 * V_5 ,
unsigned long V_21 )
{
struct V_6 * V_7 ;
int V_18 = 0 , V_8 ;
V_8 = F_7 ( & V_3 ) ;
F_8 (mn, &mm->mmu_notifier_mm->list, hlist) {
if ( V_7 -> V_9 -> V_22 ) {
V_18 = V_7 -> V_9 -> V_22 ( V_7 , V_5 , V_21 ) ;
if ( V_18 )
break;
}
}
F_15 ( & V_3 , V_8 ) ;
return V_18 ;
}
void F_20 ( struct V_4 * V_5 , unsigned long V_21 ,
T_1 V_23 )
{
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_7 ( & V_3 ) ;
F_8 (mn, &mm->mmu_notifier_mm->list, hlist) {
if ( V_7 -> V_9 -> V_24 )
V_7 -> V_9 -> V_24 ( V_7 , V_5 , V_21 , V_23 ) ;
}
F_15 ( & V_3 , V_8 ) ;
}
void F_21 ( struct V_4 * V_5 ,
unsigned long V_16 , unsigned long V_17 )
{
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_7 ( & V_3 ) ;
F_8 (mn, &mm->mmu_notifier_mm->list, hlist) {
if ( V_7 -> V_9 -> V_25 )
V_7 -> V_9 -> V_25 ( V_7 , V_5 , V_16 , V_17 ) ;
}
F_15 ( & V_3 , V_8 ) ;
}
void F_22 ( struct V_4 * V_5 ,
unsigned long V_16 , unsigned long V_17 )
{
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_7 ( & V_3 ) ;
F_8 (mn, &mm->mmu_notifier_mm->list, hlist) {
if ( V_7 -> V_9 -> V_26 )
V_7 -> V_9 -> V_26 ( V_7 , V_5 , V_16 , V_17 ) ;
if ( V_7 -> V_9 -> V_27 )
V_7 -> V_9 -> V_27 ( V_7 , V_5 , V_16 , V_17 ) ;
}
F_15 ( & V_3 , V_8 ) ;
}
void F_23 ( struct V_4 * V_5 ,
unsigned long V_16 , unsigned long V_17 )
{
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_7 ( & V_3 ) ;
F_8 (mn, &mm->mmu_notifier_mm->list, hlist) {
if ( V_7 -> V_9 -> V_26 )
V_7 -> V_9 -> V_26 ( V_7 , V_5 , V_16 , V_17 ) ;
}
F_15 ( & V_3 , V_8 ) ;
}
static int F_24 ( struct V_6 * V_7 ,
struct V_4 * V_5 ,
int V_28 )
{
struct V_11 * V_11 ;
int V_29 ;
F_25 ( F_26 ( & V_5 -> V_30 ) <= 0 ) ;
V_29 = - V_31 ;
V_11 = F_27 ( sizeof( struct V_11 ) , V_32 ) ;
if ( F_10 ( ! V_11 ) )
goto V_33;
if ( V_28 )
F_28 ( & V_5 -> V_34 ) ;
V_29 = F_29 ( V_5 ) ;
if ( F_10 ( V_29 ) )
goto V_35;
if ( ! F_30 ( V_5 ) ) {
F_31 ( & V_11 -> V_13 ) ;
F_32 ( & V_11 -> V_12 ) ;
V_5 -> V_11 = V_11 ;
V_11 = NULL ;
}
F_33 ( V_5 ) ;
F_9 ( & V_5 -> V_11 -> V_12 ) ;
F_34 ( & V_7 -> V_15 , & V_5 -> V_11 -> V_13 ) ;
F_14 ( & V_5 -> V_11 -> V_12 ) ;
F_35 ( V_5 ) ;
V_35:
if ( V_28 )
F_36 ( & V_5 -> V_34 ) ;
F_37 ( V_11 ) ;
V_33:
F_25 ( F_26 ( & V_5 -> V_30 ) <= 0 ) ;
return V_29 ;
}
int F_38 ( struct V_6 * V_7 , struct V_4 * V_5 )
{
return F_24 ( V_7 , V_5 , 1 ) ;
}
int F_39 ( struct V_6 * V_7 , struct V_4 * V_5 )
{
return F_24 ( V_7 , V_5 , 0 ) ;
}
void F_40 ( struct V_4 * V_5 )
{
F_25 ( ! F_11 ( & V_5 -> V_11 -> V_13 ) ) ;
F_37 ( V_5 -> V_11 ) ;
V_5 -> V_11 = V_36 ;
}
void F_41 ( struct V_6 * V_7 , struct V_4 * V_5 )
{
F_25 ( F_26 ( & V_5 -> V_37 ) <= 0 ) ;
if ( ! F_42 ( & V_7 -> V_15 ) ) {
int V_8 ;
V_8 = F_7 ( & V_3 ) ;
if ( V_7 -> V_9 -> V_10 )
V_7 -> V_9 -> V_10 ( V_7 , V_5 ) ;
F_15 ( & V_3 , V_8 ) ;
F_9 ( & V_5 -> V_11 -> V_12 ) ;
F_13 ( & V_7 -> V_15 ) ;
F_14 ( & V_5 -> V_11 -> V_12 ) ;
}
F_16 ( & V_3 ) ;
F_25 ( F_26 ( & V_5 -> V_37 ) <= 0 ) ;
F_43 ( V_5 ) ;
}
void F_44 ( struct V_6 * V_7 ,
struct V_4 * V_5 )
{
F_9 ( & V_5 -> V_11 -> V_12 ) ;
F_13 ( & V_7 -> V_15 ) ;
F_14 ( & V_5 -> V_11 -> V_12 ) ;
F_25 ( F_26 ( & V_5 -> V_37 ) <= 0 ) ;
F_43 ( V_5 ) ;
}
