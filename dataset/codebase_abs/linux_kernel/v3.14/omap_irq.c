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
F_11 ( & V_11 , V_12 ) ;
if ( ! F_12 ( V_2 -> V_13 ) ) {
V_2 -> V_13 = true ;
F_13 ( & V_2 -> V_14 , & V_7 -> V_15 ) ;
F_3 ( V_5 ) ;
}
F_14 ( & V_11 , V_12 ) ;
}
void F_15 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
F_16 () ;
F_10 ( V_5 , V_2 ) ;
F_17 () ;
}
void F_18 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
unsigned long V_12 ;
F_11 ( & V_11 , V_12 ) ;
if ( ! F_12 ( ! V_2 -> V_13 ) ) {
V_2 -> V_13 = false ;
F_19 ( & V_2 -> V_14 ) ;
F_3 ( V_5 ) ;
}
F_14 ( & V_11 , V_12 ) ;
}
void F_20 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
F_16 () ;
F_18 ( V_5 , V_2 ) ;
F_17 () ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_16 * V_17 =
F_22 ( V_2 , struct V_16 , V_2 ) ;
V_17 -> V_18 -- ;
F_23 ( & V_19 ) ;
}
struct V_16 * F_24 ( struct V_4 * V_5 ,
T_1 V_9 , int V_18 )
{
struct V_16 * V_17 = F_25 ( sizeof( * V_17 ) , V_20 ) ;
V_17 -> V_2 . V_2 = F_21 ;
V_17 -> V_2 . V_9 = V_9 ;
V_17 -> V_18 = V_18 ;
F_15 ( V_5 , & V_17 -> V_2 ) ;
return V_17 ;
}
int V_16 ( struct V_4 * V_5 , struct V_16 * V_17 ,
unsigned long V_21 )
{
int V_22 = F_26 ( V_19 , ( V_17 -> V_18 <= 0 ) , V_21 ) ;
F_20 ( V_5 , & V_17 -> V_2 ) ;
F_27 ( V_17 ) ;
if ( V_22 == 0 )
return - 1 ;
return 0 ;
}
int F_28 ( struct V_4 * V_5 , int V_23 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_24 * V_25 = V_7 -> V_26 [ V_23 ] ;
unsigned long V_12 ;
F_7 ( L_3 , V_5 , V_23 ) ;
F_16 () ;
F_11 ( & V_11 , V_12 ) ;
V_7 -> V_10 |= F_29 ( V_25 ) ;
F_3 ( V_5 ) ;
F_14 ( & V_11 , V_12 ) ;
F_17 () ;
return 0 ;
}
void F_30 ( struct V_4 * V_5 , int V_23 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_24 * V_25 = V_7 -> V_26 [ V_23 ] ;
unsigned long V_12 ;
F_7 ( L_3 , V_5 , V_23 ) ;
F_16 () ;
F_11 ( & V_11 , V_12 ) ;
V_7 -> V_10 &= ~ F_29 ( V_25 ) ;
F_3 ( V_5 ) ;
F_14 ( & V_11 , V_12 ) ;
F_17 () ;
}
T_2 F_31 ( int V_2 , void * V_27 )
{
struct V_4 * V_5 = (struct V_4 * ) V_27 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_28 , * V_29 ;
unsigned long V_12 ;
unsigned int V_30 ;
T_3 V_3 ;
V_3 = F_32 () ;
F_33 ( V_3 ) ;
F_32 () ;
F_34 ( L_4 , V_3 ) ;
for ( V_30 = 0 ; V_30 < V_7 -> V_31 ; V_30 ++ ) {
struct V_24 * V_25 = V_7 -> V_26 [ V_30 ] ;
if ( V_3 & F_29 ( V_25 ) )
F_35 ( V_5 , V_30 ) ;
}
F_11 ( & V_11 , V_12 ) ;
F_36 (handler, n, &priv->irq_list, node) {
if ( V_28 -> V_9 & V_3 ) {
F_14 ( & V_11 , V_12 ) ;
V_28 -> V_2 ( V_28 , V_28 -> V_9 & V_3 ) ;
F_11 ( & V_11 , V_12 ) ;
}
}
F_14 ( & V_11 , V_12 ) ;
return V_32 ;
}
void F_37 ( struct V_4 * V_5 )
{
F_7 ( L_5 , V_5 ) ;
F_16 () ;
F_33 ( 0xffffffff ) ;
F_17 () ;
}
int F_38 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_33 = & V_7 -> V_33 ;
F_7 ( L_5 , V_5 ) ;
F_39 ( & V_7 -> V_15 ) ;
V_33 -> V_2 = F_1 ;
V_33 -> V_9 = V_34 ;
V_33 -> V_9 &= ~ V_35 ;
F_15 ( V_5 , V_33 ) ;
return 0 ;
}
void F_40 ( struct V_4 * V_5 )
{
F_7 ( L_5 , V_5 ) ;
}
int F_41 ( struct V_4 * V_5 )
{
int V_22 ;
F_42 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_37 ) {
F_43 ( & V_5 -> V_36 ) ;
return - V_38 ;
}
V_5 -> V_37 = true ;
F_43 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_39 -> V_40 )
V_5 -> V_39 -> V_40 ( V_5 ) ;
V_22 = F_44 ( V_5 -> V_39 -> V_41 , V_5 ) ;
if ( V_22 < 0 ) {
F_42 ( & V_5 -> V_36 ) ;
V_5 -> V_37 = false ;
F_43 ( & V_5 -> V_36 ) ;
return V_22 ;
}
if ( V_5 -> V_39 -> V_42 )
V_22 = V_5 -> V_39 -> V_42 ( V_5 ) ;
if ( V_22 < 0 ) {
F_42 ( & V_5 -> V_36 ) ;
V_5 -> V_37 = false ;
F_43 ( & V_5 -> V_36 ) ;
F_45 ( V_5 ) ;
}
return V_22 ;
}
int F_46 ( struct V_4 * V_5 )
{
unsigned long V_43 ;
bool V_37 ;
int V_44 ;
F_42 ( & V_5 -> V_36 ) ;
V_37 = V_5 -> V_37 ;
V_5 -> V_37 = false ;
F_43 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_31 ) {
F_11 ( & V_5 -> V_45 , V_43 ) ;
for ( V_44 = 0 ; V_44 < V_5 -> V_31 ; V_44 ++ ) {
F_47 ( & V_5 -> V_46 [ V_44 ] . V_47 ) ;
V_5 -> V_46 [ V_44 ] . V_48 = false ;
V_5 -> V_46 [ V_44 ] . V_49 =
V_5 -> V_39 -> V_50 ( V_5 , V_44 ) ;
}
F_14 ( & V_5 -> V_45 , V_43 ) ;
}
if ( ! V_37 )
return - V_51 ;
if ( V_5 -> V_39 -> V_52 )
V_5 -> V_39 -> V_52 ( V_5 ) ;
F_45 ( V_5 ) ;
return 0 ;
}
