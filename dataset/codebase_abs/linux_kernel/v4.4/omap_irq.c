static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
F_2 ( L_1 , V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_2 ;
T_1 V_9 = V_7 -> V_10 ;
F_4 ( & V_11 ) ;
F_5 (irq, &priv->irq_list, node)
V_9 |= V_2 -> V_9 ;
F_6 ( L_2 , V_9 ) ;
F_7 ( V_9 ) ;
F_8 () ;
}
void F_9 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned long V_12 ;
F_10 ( & V_11 , V_12 ) ;
if ( ! F_11 ( V_2 -> V_13 ) ) {
V_2 -> V_13 = true ;
F_12 ( & V_2 -> V_14 , & V_7 -> V_15 ) ;
F_3 ( V_5 ) ;
}
F_13 ( & V_11 , V_12 ) ;
}
void F_14 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
F_15 () ;
F_9 ( V_5 , V_2 ) ;
F_16 () ;
}
void F_17 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
unsigned long V_12 ;
F_10 ( & V_11 , V_12 ) ;
if ( ! F_11 ( ! V_2 -> V_13 ) ) {
V_2 -> V_13 = false ;
F_18 ( & V_2 -> V_14 ) ;
F_3 ( V_5 ) ;
}
F_13 ( & V_11 , V_12 ) ;
}
void F_19 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
F_15 () ;
F_17 ( V_5 , V_2 ) ;
F_16 () ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_16 * V_17 =
F_21 ( V_2 , struct V_16 , V_2 ) ;
V_17 -> V_18 -- ;
F_22 ( & V_19 ) ;
}
struct V_16 * F_23 ( struct V_4 * V_5 ,
T_1 V_9 , int V_18 )
{
struct V_16 * V_17 = F_24 ( sizeof( * V_17 ) , V_20 ) ;
V_17 -> V_2 . V_2 = F_20 ;
V_17 -> V_2 . V_9 = V_9 ;
V_17 -> V_18 = V_18 ;
F_14 ( V_5 , & V_17 -> V_2 ) ;
return V_17 ;
}
int V_16 ( struct V_4 * V_5 , struct V_16 * V_17 ,
unsigned long V_21 )
{
int V_22 = F_25 ( V_19 , ( V_17 -> V_18 <= 0 ) , V_21 ) ;
F_19 ( V_5 , & V_17 -> V_2 ) ;
F_26 ( V_17 ) ;
if ( V_22 == 0 )
return - 1 ;
return 0 ;
}
int F_27 ( struct V_4 * V_5 , unsigned int V_23 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_24 * V_25 = V_7 -> V_26 [ V_23 ] ;
unsigned long V_12 ;
F_6 ( L_3 , V_5 , V_23 ) ;
F_10 ( & V_11 , V_12 ) ;
V_7 -> V_10 |= F_28 ( V_25 ) ;
F_3 ( V_5 ) ;
F_13 ( & V_11 , V_12 ) ;
return 0 ;
}
void F_29 ( struct V_4 * V_5 , unsigned int V_23 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_24 * V_25 = V_7 -> V_26 [ V_23 ] ;
unsigned long V_12 ;
F_6 ( L_3 , V_5 , V_23 ) ;
F_10 ( & V_11 , V_12 ) ;
V_7 -> V_10 &= ~ F_28 ( V_25 ) ;
F_3 ( V_5 ) ;
F_13 ( & V_11 , V_12 ) ;
}
static T_2 F_30 ( int V_2 , void * V_27 )
{
struct V_4 * V_5 = (struct V_4 * ) V_27 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_28 , * V_29 ;
unsigned long V_12 ;
unsigned int V_30 ;
T_3 V_3 ;
V_3 = F_31 () ;
F_32 ( V_3 ) ;
F_31 () ;
F_33 ( L_4 , V_3 ) ;
for ( V_30 = 0 ; V_30 < V_7 -> V_31 ; V_30 ++ ) {
struct V_24 * V_25 = V_7 -> V_26 [ V_30 ] ;
if ( V_3 & F_28 ( V_25 ) )
F_34 ( V_5 , V_30 ) ;
}
F_10 ( & V_11 , V_12 ) ;
F_35 (handler, n, &priv->irq_list, node) {
if ( V_28 -> V_9 & V_3 ) {
F_13 ( & V_11 , V_12 ) ;
V_28 -> V_2 ( V_28 , V_28 -> V_9 & V_3 ) ;
F_10 ( & V_11 , V_12 ) ;
}
}
F_13 ( & V_11 , V_12 ) ;
return V_32 ;
}
int F_36 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_33 = & V_7 -> V_33 ;
int V_22 ;
F_37 ( & V_7 -> V_15 ) ;
F_15 () ;
F_32 ( 0xffffffff ) ;
F_16 () ;
V_22 = F_38 ( F_30 , V_5 ) ;
if ( V_22 < 0 )
return V_22 ;
V_33 -> V_2 = F_1 ;
V_33 -> V_9 = V_34 ;
V_33 -> V_9 &= ~ V_35 ;
F_14 ( V_5 , V_33 ) ;
V_5 -> V_36 = true ;
return 0 ;
}
void F_39 ( struct V_4 * V_5 )
{
unsigned long V_37 ;
int V_38 ;
if ( ! V_5 -> V_36 )
return;
V_5 -> V_36 = false ;
if ( V_5 -> V_31 ) {
F_10 ( & V_5 -> V_39 , V_37 ) ;
for ( V_38 = 0 ; V_38 < V_5 -> V_31 ; V_38 ++ ) {
F_40 ( & V_5 -> V_40 [ V_38 ] . V_41 ) ;
V_5 -> V_40 [ V_38 ] . V_42 = false ;
V_5 -> V_40 [ V_38 ] . V_43 =
V_5 -> V_44 -> V_45 ( V_5 , V_38 ) ;
}
F_13 ( & V_5 -> V_39 , V_37 ) ;
}
F_41 ( V_5 ) ;
}
