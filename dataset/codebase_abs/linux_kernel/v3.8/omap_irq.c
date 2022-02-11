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
F_4 ( ! F_5 ( & V_11 ) ) ;
F_6 (irq, &priv->irq_list, node)
V_9 |= V_2 -> V_9 ;
F_7 ( L_2 , V_9 ) ;
F_8 ( V_9 ) ;
F_9 () ;
}
void F_10 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned long V_12 ;
F_11 () ;
F_12 ( & V_11 , V_12 ) ;
if ( ! F_13 ( V_2 -> V_13 ) ) {
V_2 -> V_13 = true ;
F_14 ( & V_2 -> V_14 , & V_7 -> V_15 ) ;
F_3 ( V_5 ) ;
}
F_15 ( & V_11 , V_12 ) ;
F_16 () ;
}
void F_17 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
unsigned long V_12 ;
F_11 () ;
F_12 ( & V_11 , V_12 ) ;
if ( ! F_13 ( ! V_2 -> V_13 ) ) {
V_2 -> V_13 = false ;
F_18 ( & V_2 -> V_14 ) ;
F_3 ( V_5 ) ;
}
F_15 ( & V_11 , V_12 ) ;
F_16 () ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_16 * V_17 =
F_20 ( V_2 , struct V_16 , V_2 ) ;
V_17 -> V_18 -- ;
F_21 ( & V_19 ) ;
}
struct V_16 * F_22 ( struct V_4 * V_5 ,
T_1 V_9 , int V_18 )
{
struct V_16 * V_17 = F_23 ( sizeof( * V_17 ) , V_20 ) ;
V_17 -> V_2 . V_2 = F_19 ;
V_17 -> V_2 . V_9 = V_9 ;
V_17 -> V_18 = V_18 ;
F_10 ( V_5 , & V_17 -> V_2 ) ;
return V_17 ;
}
int V_16 ( struct V_4 * V_5 , struct V_16 * V_17 ,
unsigned long V_21 )
{
int V_22 = F_24 ( V_19 , ( V_17 -> V_18 <= 0 ) , V_21 ) ;
F_17 ( V_5 , & V_17 -> V_2 ) ;
F_25 ( V_17 ) ;
if ( V_22 == 0 )
return - 1 ;
return 0 ;
}
int F_26 ( struct V_4 * V_5 , int V_23 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned long V_12 ;
F_7 ( L_3 , V_5 , V_23 ) ;
F_11 () ;
F_12 ( & V_11 , V_12 ) ;
V_7 -> V_10 |= F_27 ( V_23 ) ;
F_3 ( V_5 ) ;
F_15 ( & V_11 , V_12 ) ;
F_16 () ;
return 0 ;
}
void F_28 ( struct V_4 * V_5 , int V_23 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned long V_12 ;
F_7 ( L_3 , V_5 , V_23 ) ;
F_11 () ;
F_12 ( & V_11 , V_12 ) ;
V_7 -> V_10 &= ~ F_27 ( V_23 ) ;
F_3 ( V_5 ) ;
F_15 ( & V_11 , V_12 ) ;
F_16 () ;
}
T_2 F_29 ( T_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_24 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_25 , * V_26 ;
unsigned long V_12 ;
unsigned int V_27 ;
T_4 V_3 ;
V_3 = F_30 () ;
F_31 ( V_3 ) ;
F_30 () ;
F_32 ( L_4 , V_3 ) ;
for ( V_27 = 0 ; V_27 < V_7 -> V_28 ; V_27 ++ )
if ( V_3 & F_27 ( V_27 ) )
F_33 ( V_5 , V_27 ) ;
F_12 ( & V_11 , V_12 ) ;
F_34 (handler, n, &priv->irq_list, node) {
if ( V_25 -> V_9 & V_3 ) {
F_15 ( & V_11 , V_12 ) ;
V_25 -> V_2 ( V_25 , V_25 -> V_9 & V_3 ) ;
F_12 ( & V_11 , V_12 ) ;
}
}
F_15 ( & V_11 , V_12 ) ;
return V_29 ;
}
void F_35 ( struct V_4 * V_5 )
{
F_7 ( L_5 , V_5 ) ;
F_11 () ;
F_31 ( 0xffffffff ) ;
F_16 () ;
}
int F_36 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_30 = & V_7 -> V_30 ;
F_7 ( L_5 , V_5 ) ;
F_37 ( & V_7 -> V_15 ) ;
V_30 -> V_2 = F_1 ;
V_30 -> V_9 = V_31 ;
V_30 -> V_9 &= ~ V_32 ;
F_10 ( V_5 , V_30 ) ;
return 0 ;
}
void F_38 ( struct V_4 * V_5 )
{
F_7 ( L_5 , V_5 ) ;
}
int F_39 ( struct V_4 * V_5 )
{
int V_22 ;
F_40 ( & V_5 -> V_33 ) ;
if ( V_5 -> V_34 ) {
F_41 ( & V_5 -> V_33 ) ;
return - V_35 ;
}
V_5 -> V_34 = 1 ;
F_41 ( & V_5 -> V_33 ) ;
if ( V_5 -> V_36 -> V_37 )
V_5 -> V_36 -> V_37 ( V_5 ) ;
V_22 = F_42 ( V_5 -> V_36 -> V_38 , V_5 ) ;
if ( V_22 < 0 ) {
F_40 ( & V_5 -> V_33 ) ;
V_5 -> V_34 = 0 ;
F_41 ( & V_5 -> V_33 ) ;
return V_22 ;
}
if ( V_5 -> V_36 -> V_39 )
V_22 = V_5 -> V_36 -> V_39 ( V_5 ) ;
if ( V_22 < 0 ) {
F_40 ( & V_5 -> V_33 ) ;
V_5 -> V_34 = 0 ;
F_41 ( & V_5 -> V_33 ) ;
F_43 ( V_5 ) ;
}
return V_22 ;
}
int F_44 ( struct V_4 * V_5 )
{
unsigned long V_40 ;
int V_34 , V_41 ;
F_40 ( & V_5 -> V_33 ) ;
V_34 = V_5 -> V_34 ;
V_5 -> V_34 = 0 ;
F_41 ( & V_5 -> V_33 ) ;
if ( V_5 -> V_28 ) {
F_12 ( & V_5 -> V_42 , V_40 ) ;
for ( V_41 = 0 ; V_41 < V_5 -> V_28 ; V_41 ++ ) {
F_45 ( & V_5 -> V_43 [ V_41 ] ) ;
V_5 -> V_44 [ V_41 ] = 0 ;
V_5 -> V_45 [ V_41 ] =
V_5 -> V_36 -> V_46 ( V_5 , V_41 ) ;
}
F_15 ( & V_5 -> V_42 , V_40 ) ;
}
if ( ! V_34 )
return - V_47 ;
if ( V_5 -> V_36 -> V_48 )
V_5 -> V_36 -> V_48 ( V_5 ) ;
F_43 ( V_5 ) ;
return 0 ;
}
