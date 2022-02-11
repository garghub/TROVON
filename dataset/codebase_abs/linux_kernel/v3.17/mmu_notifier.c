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
unsigned long V_16 )
{
struct V_6 * V_7 ;
int V_17 = 0 , V_8 ;
V_8 = F_7 ( & V_3 ) ;
F_8 (mn, &mm->mmu_notifier_mm->list, hlist) {
if ( V_7 -> V_9 -> V_18 )
V_17 |= V_7 -> V_9 -> V_18 ( V_7 , V_5 , V_16 ) ;
}
F_15 ( & V_3 , V_8 ) ;
return V_17 ;
}
int F_18 ( struct V_4 * V_5 ,
unsigned long V_16 )
{
struct V_6 * V_7 ;
int V_17 = 0 , V_8 ;
V_8 = F_7 ( & V_3 ) ;
F_8 (mn, &mm->mmu_notifier_mm->list, hlist) {
if ( V_7 -> V_9 -> V_19 ) {
V_17 = V_7 -> V_9 -> V_19 ( V_7 , V_5 , V_16 ) ;
if ( V_17 )
break;
}
}
F_15 ( & V_3 , V_8 ) ;
return V_17 ;
}
void F_19 ( struct V_4 * V_5 , unsigned long V_16 ,
T_1 V_20 )
{
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_7 ( & V_3 ) ;
F_8 (mn, &mm->mmu_notifier_mm->list, hlist) {
if ( V_7 -> V_9 -> V_21 )
V_7 -> V_9 -> V_21 ( V_7 , V_5 , V_16 , V_20 ) ;
}
F_15 ( & V_3 , V_8 ) ;
}
void F_20 ( struct V_4 * V_5 ,
unsigned long V_16 )
{
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_7 ( & V_3 ) ;
F_8 (mn, &mm->mmu_notifier_mm->list, hlist) {
if ( V_7 -> V_9 -> V_22 )
V_7 -> V_9 -> V_22 ( V_7 , V_5 , V_16 ) ;
}
F_15 ( & V_3 , V_8 ) ;
}
void F_21 ( struct V_4 * V_5 ,
unsigned long V_23 , unsigned long V_24 )
{
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_7 ( & V_3 ) ;
F_8 (mn, &mm->mmu_notifier_mm->list, hlist) {
if ( V_7 -> V_9 -> V_25 )
V_7 -> V_9 -> V_25 ( V_7 , V_5 , V_23 , V_24 ) ;
}
F_15 ( & V_3 , V_8 ) ;
}
void F_22 ( struct V_4 * V_5 ,
unsigned long V_23 , unsigned long V_24 )
{
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_7 ( & V_3 ) ;
F_8 (mn, &mm->mmu_notifier_mm->list, hlist) {
if ( V_7 -> V_9 -> V_26 )
V_7 -> V_9 -> V_26 ( V_7 , V_5 , V_23 , V_24 ) ;
}
F_15 ( & V_3 , V_8 ) ;
}
static int F_23 ( struct V_6 * V_7 ,
struct V_4 * V_5 ,
int V_27 )
{
struct V_11 * V_11 ;
int V_28 ;
F_24 ( F_25 ( & V_5 -> V_29 ) <= 0 ) ;
F_24 ( ! V_3 . V_30 ) ;
V_28 = - V_31 ;
V_11 = F_26 ( sizeof( struct V_11 ) , V_32 ) ;
if ( F_10 ( ! V_11 ) )
goto V_33;
if ( V_27 )
F_27 ( & V_5 -> V_34 ) ;
V_28 = F_28 ( V_5 ) ;
if ( F_10 ( V_28 ) )
goto V_35;
if ( ! F_29 ( V_5 ) ) {
F_30 ( & V_11 -> V_13 ) ;
F_31 ( & V_11 -> V_12 ) ;
V_5 -> V_11 = V_11 ;
V_11 = NULL ;
}
F_32 ( & V_5 -> V_36 ) ;
F_9 ( & V_5 -> V_11 -> V_12 ) ;
F_33 ( & V_7 -> V_15 , & V_5 -> V_11 -> V_13 ) ;
F_14 ( & V_5 -> V_11 -> V_12 ) ;
F_34 ( V_5 ) ;
V_35:
if ( V_27 )
F_35 ( & V_5 -> V_34 ) ;
F_36 ( V_11 ) ;
V_33:
F_24 ( F_25 ( & V_5 -> V_29 ) <= 0 ) ;
return V_28 ;
}
int F_37 ( struct V_6 * V_7 , struct V_4 * V_5 )
{
return F_23 ( V_7 , V_5 , 1 ) ;
}
int F_38 ( struct V_6 * V_7 , struct V_4 * V_5 )
{
return F_23 ( V_7 , V_5 , 0 ) ;
}
void F_39 ( struct V_4 * V_5 )
{
F_24 ( ! F_11 ( & V_5 -> V_11 -> V_13 ) ) ;
F_36 ( V_5 -> V_11 ) ;
V_5 -> V_11 = V_37 ;
}
void F_40 ( struct V_6 * V_7 , struct V_4 * V_5 )
{
F_24 ( F_25 ( & V_5 -> V_36 ) <= 0 ) ;
if ( ! F_41 ( & V_7 -> V_15 ) ) {
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
F_24 ( F_25 ( & V_5 -> V_36 ) <= 0 ) ;
F_42 ( V_5 ) ;
}
void F_43 ( struct V_6 * V_7 ,
struct V_4 * V_5 )
{
F_9 ( & V_5 -> V_11 -> V_12 ) ;
F_13 ( & V_7 -> V_15 ) ;
F_14 ( & V_5 -> V_11 -> V_12 ) ;
F_24 ( F_25 ( & V_5 -> V_36 ) <= 0 ) ;
F_42 ( V_5 ) ;
}
static int T_2 F_44 ( void )
{
return F_45 ( & V_3 ) ;
}
