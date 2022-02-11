static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
T_1 V_4 = V_1 -> V_5 ;
F_2 ( ! F_3 ( & V_6 ) ) ;
F_4 (irq, &mdp4_kms->irq_list, node)
V_4 |= V_3 -> V_4 ;
F_5 ( V_1 , V_7 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
unsigned long V_8 ;
F_7 ( & V_6 , V_8 ) ;
F_1 ( V_1 ) ;
F_8 ( & V_6 , V_8 ) ;
}
static void F_9 ( struct V_2 * V_3 , T_1 V_9 )
{
F_10 ( L_1 , V_9 ) ;
}
void F_11 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = F_12 ( V_11 ) ;
F_5 ( V_1 , V_12 , 0xffffffff ) ;
}
int F_13 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = F_12 ( V_11 ) ;
struct V_2 * V_13 = & V_1 -> V_13 ;
F_14 ( & V_1 -> V_14 ) ;
V_13 -> V_3 = F_9 ;
V_13 -> V_4 = V_15 |
V_16 ;
F_15 ( V_1 , V_13 ) ;
return 0 ;
}
void F_16 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = F_12 ( V_11 ) ;
F_5 ( V_1 , V_7 , 0x00000000 ) ;
}
T_2 V_2 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = F_12 ( V_11 ) ;
struct V_17 * V_18 = V_1 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_2 * V_22 , * V_23 ;
unsigned long V_8 ;
unsigned int V_24 ;
T_1 V_25 ;
V_25 = F_17 ( V_1 , V_26 ) ;
F_5 ( V_1 , V_12 , V_25 ) ;
F_18 ( L_2 , V_25 ) ;
for ( V_24 = 0 ; V_24 < V_20 -> V_27 ; V_24 ++ )
if ( V_25 & F_19 ( V_20 -> V_28 [ V_24 ] ) )
F_20 ( V_18 , V_24 ) ;
F_7 ( & V_6 , V_8 ) ;
V_1 -> V_29 = true ;
F_21 (handler, n, &mdp4_kms->irq_list, node) {
if ( V_22 -> V_4 & V_25 ) {
F_8 ( & V_6 , V_8 ) ;
V_22 -> V_3 ( V_22 , V_22 -> V_4 & V_25 ) ;
F_7 ( & V_6 , V_8 ) ;
}
}
V_1 -> V_29 = false ;
F_1 ( V_1 ) ;
F_8 ( & V_6 , V_8 ) ;
return V_30 ;
}
int F_22 ( struct V_10 * V_11 , struct V_31 * V_32 )
{
struct V_1 * V_1 = F_12 ( V_11 ) ;
unsigned long V_8 ;
F_7 ( & V_6 , V_8 ) ;
V_1 -> V_5 |= F_19 ( V_32 ) ;
F_1 ( V_1 ) ;
F_8 ( & V_6 , V_8 ) ;
return 0 ;
}
void F_23 ( struct V_10 * V_11 , struct V_31 * V_32 )
{
struct V_1 * V_1 = F_12 ( V_11 ) ;
unsigned long V_8 ;
F_7 ( & V_6 , V_8 ) ;
V_1 -> V_5 &= ~ F_19 ( V_32 ) ;
F_1 ( V_1 ) ;
F_8 ( & V_6 , V_8 ) ;
}
static void F_24 ( struct V_2 * V_3 , T_1 V_9 )
{
struct V_33 * V_34 =
F_25 ( V_3 , struct V_33 , V_3 ) ;
V_34 -> V_35 -- ;
F_26 ( & V_36 ) ;
}
void V_33 ( struct V_1 * V_1 , T_1 V_4 )
{
struct V_33 V_34 = {
. V_3 = {
. V_3 = F_24 ,
. V_4 = V_4 ,
} ,
. V_35 = 1 ,
} ;
F_15 ( V_1 , & V_34 . V_3 ) ;
V_36 ( V_36 , ( V_34 . V_35 <= 0 ) ) ;
F_27 ( V_1 , & V_34 . V_3 ) ;
}
void F_15 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
unsigned long V_8 ;
bool V_37 = false ;
F_7 ( & V_6 , V_8 ) ;
if ( ! V_3 -> V_38 ) {
V_3 -> V_38 = true ;
F_28 ( & V_3 -> V_39 , & V_1 -> V_14 ) ;
V_37 = ! V_1 -> V_29 ;
}
F_8 ( & V_6 , V_8 ) ;
if ( V_37 )
F_6 ( V_1 ) ;
}
void F_27 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
unsigned long V_8 ;
bool V_37 = false ;
F_7 ( & V_6 , V_8 ) ;
if ( V_3 -> V_38 ) {
V_3 -> V_38 = false ;
F_29 ( & V_3 -> V_39 ) ;
V_37 = ! V_1 -> V_29 ;
}
F_8 ( & V_6 , V_8 ) ;
if ( V_37 )
F_6 ( V_1 ) ;
}
