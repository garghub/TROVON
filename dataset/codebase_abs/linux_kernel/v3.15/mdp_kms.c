static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
T_1 V_4 = V_1 -> V_5 ;
F_2 ( ! F_3 ( & V_6 ) ) ;
F_4 (irq, &mdp_kms->irq_list, node)
V_4 |= V_3 -> V_4 ;
V_1 -> V_7 -> V_8 ( V_1 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_1 )
{
unsigned long V_9 ;
F_6 ( & V_6 , V_9 ) ;
F_1 ( V_1 ) ;
F_7 ( & V_6 , V_9 ) ;
}
void F_8 ( struct V_1 * V_1 , T_1 V_10 )
{
struct V_2 * V_11 , * V_12 ;
unsigned long V_9 ;
F_6 ( & V_6 , V_9 ) ;
V_1 -> V_13 = true ;
F_9 (handler, n, &mdp_kms->irq_list, node) {
if ( V_11 -> V_4 & V_10 ) {
F_7 ( & V_6 , V_9 ) ;
V_11 -> V_3 ( V_11 , V_11 -> V_4 & V_10 ) ;
F_6 ( & V_6 , V_9 ) ;
}
}
V_1 -> V_13 = false ;
F_1 ( V_1 ) ;
F_7 ( & V_6 , V_9 ) ;
}
void F_10 ( struct V_1 * V_1 , T_1 V_14 , bool V_15 )
{
unsigned long V_9 ;
F_6 ( & V_6 , V_9 ) ;
if ( V_15 )
V_1 -> V_5 |= V_14 ;
else
V_1 -> V_5 &= ~ V_14 ;
F_1 ( V_1 ) ;
F_7 ( & V_6 , V_9 ) ;
}
static void F_11 ( struct V_2 * V_3 , T_1 V_16 )
{
struct V_17 * V_18 =
F_12 ( V_3 , struct V_17 , V_3 ) ;
V_18 -> V_19 -- ;
F_13 ( & V_20 ) ;
}
void V_17 ( struct V_1 * V_1 , T_1 V_4 )
{
struct V_17 V_18 = {
. V_3 = {
. V_3 = F_11 ,
. V_4 = V_4 ,
} ,
. V_19 = 1 ,
} ;
F_14 ( V_1 , & V_18 . V_3 ) ;
F_15 ( V_20 , ( V_18 . V_19 <= 0 ) ,
F_16 ( 100 ) ) ;
F_17 ( V_1 , & V_18 . V_3 ) ;
}
void F_14 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
unsigned long V_9 ;
bool V_21 = false ;
F_6 ( & V_6 , V_9 ) ;
if ( ! V_3 -> V_22 ) {
V_3 -> V_22 = true ;
F_18 ( & V_3 -> V_23 , & V_1 -> V_24 ) ;
V_21 = ! V_1 -> V_13 ;
}
F_7 ( & V_6 , V_9 ) ;
if ( V_21 )
F_5 ( V_1 ) ;
}
void F_17 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
unsigned long V_9 ;
bool V_21 = false ;
F_6 ( & V_6 , V_9 ) ;
if ( V_3 -> V_22 ) {
V_3 -> V_22 = false ;
F_19 ( & V_3 -> V_23 ) ;
V_21 = ! V_1 -> V_13 ;
}
F_7 ( & V_6 , V_9 ) ;
if ( V_21 )
F_5 ( V_1 ) ;
}
