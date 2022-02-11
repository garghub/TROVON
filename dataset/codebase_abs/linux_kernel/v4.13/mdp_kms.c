static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
T_1 V_4 = V_1 -> V_5 ;
F_2 ( & V_6 ) ;
F_3 (irq, &mdp_kms->irq_list, node)
V_4 |= V_3 -> V_4 ;
V_1 -> V_7 -> V_8 ( V_1 , V_4 , V_1 -> V_9 ) ;
V_1 -> V_9 = V_4 ;
}
void F_4 ( struct V_1 * V_1 )
{
unsigned long V_10 ;
F_5 ( & V_6 , V_10 ) ;
F_1 ( V_1 ) ;
F_6 ( & V_6 , V_10 ) ;
}
void F_7 ( struct V_1 * V_1 , T_1 V_11 )
{
struct V_2 * V_12 , * V_13 ;
unsigned long V_10 ;
F_5 ( & V_6 , V_10 ) ;
V_1 -> V_14 = true ;
F_8 (handler, n, &mdp_kms->irq_list, node) {
if ( V_12 -> V_4 & V_11 ) {
F_6 ( & V_6 , V_10 ) ;
V_12 -> V_3 ( V_12 , V_12 -> V_4 & V_11 ) ;
F_5 ( & V_6 , V_10 ) ;
}
}
V_1 -> V_14 = false ;
F_1 ( V_1 ) ;
F_6 ( & V_6 , V_10 ) ;
}
void F_9 ( struct V_1 * V_1 , T_1 V_15 , bool V_16 )
{
unsigned long V_10 ;
F_5 ( & V_6 , V_10 ) ;
if ( V_16 )
V_1 -> V_5 |= V_15 ;
else
V_1 -> V_5 &= ~ V_15 ;
F_1 ( V_1 ) ;
F_6 ( & V_6 , V_10 ) ;
}
static void F_10 ( struct V_2 * V_3 , T_1 V_17 )
{
struct V_18 * V_19 =
F_11 ( V_3 , struct V_18 , V_3 ) ;
V_19 -> V_20 -- ;
F_12 ( & V_21 ) ;
}
void V_18 ( struct V_1 * V_1 , T_1 V_4 )
{
struct V_18 V_19 = {
. V_3 = {
. V_3 = F_10 ,
. V_4 = V_4 ,
} ,
. V_20 = 1 ,
} ;
F_13 ( V_1 , & V_19 . V_3 ) ;
F_14 ( V_21 , ( V_19 . V_20 <= 0 ) ,
F_15 ( 100 ) ) ;
F_16 ( V_1 , & V_19 . V_3 ) ;
}
void F_13 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
unsigned long V_10 ;
bool V_22 = false ;
F_5 ( & V_6 , V_10 ) ;
if ( ! V_3 -> V_23 ) {
V_3 -> V_23 = true ;
F_17 ( & V_3 -> V_24 , & V_1 -> V_25 ) ;
V_22 = ! V_1 -> V_14 ;
}
F_6 ( & V_6 , V_10 ) ;
if ( V_22 )
F_4 ( V_1 ) ;
}
void F_16 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
unsigned long V_10 ;
bool V_22 = false ;
F_5 ( & V_6 , V_10 ) ;
if ( V_3 -> V_23 ) {
V_3 -> V_23 = false ;
F_18 ( & V_3 -> V_24 ) ;
V_22 = ! V_1 -> V_14 ;
}
F_6 ( & V_6 , V_10 ) ;
if ( V_22 )
F_4 ( V_1 ) ;
}
