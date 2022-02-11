static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
T_1 V_8 = V_4 -> V_9 ;
F_2 ( & V_4 -> V_10 ) ;
F_3 (wait, &priv->wait_list, node)
V_8 |= V_7 -> V_8 ;
F_4 ( L_1 , V_8 ) ;
F_5 ( V_8 ) ;
F_6 () ;
}
static void F_7 ( struct V_6 * V_7 )
{
V_7 -> V_11 -- ;
F_8 ( & V_7 -> V_12 ) ;
}
struct V_6 * F_9 ( struct V_1 * V_2 ,
T_1 V_8 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_10 ( sizeof( * V_7 ) , V_13 ) ;
unsigned long V_14 ;
F_11 ( & V_7 -> V_12 ) ;
V_7 -> V_8 = V_8 ;
V_7 -> V_11 = V_11 ;
F_12 ( & V_4 -> V_10 , V_14 ) ;
F_13 ( & V_7 -> V_15 , & V_4 -> V_16 ) ;
F_1 ( V_2 ) ;
F_14 ( & V_4 -> V_10 , V_14 ) ;
return V_7 ;
}
int V_6 ( struct V_1 * V_2 , struct V_6 * V_7 ,
unsigned long V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_14 ;
int V_18 ;
V_18 = F_15 ( V_7 -> V_12 , ( V_7 -> V_11 <= 0 ) , V_17 ) ;
F_12 ( & V_4 -> V_10 , V_14 ) ;
F_16 ( & V_7 -> V_15 ) ;
F_1 ( V_2 ) ;
F_14 ( & V_4 -> V_10 , V_14 ) ;
F_17 ( V_7 ) ;
return V_18 == 0 ? - 1 : 0 ;
}
int F_18 ( struct V_1 * V_2 , unsigned int V_19 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 = V_4 -> V_22 [ V_19 ] ;
unsigned long V_14 ;
F_4 ( L_2 , V_2 , V_19 ) ;
F_12 ( & V_4 -> V_10 , V_14 ) ;
V_4 -> V_9 |= F_19 ( F_20 ( V_21 ) ) ;
F_1 ( V_2 ) ;
F_14 ( & V_4 -> V_10 , V_14 ) ;
return 0 ;
}
void F_21 ( struct V_1 * V_2 , unsigned int V_19 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 = V_4 -> V_22 [ V_19 ] ;
unsigned long V_14 ;
F_4 ( L_2 , V_2 , V_19 ) ;
F_12 ( & V_4 -> V_10 , V_14 ) ;
V_4 -> V_9 &= ~ F_19 ( F_20 ( V_21 ) ) ;
F_1 ( V_2 ) ;
F_14 ( & V_4 -> V_10 , V_14 ) ;
}
static void F_22 ( struct V_3 * V_4 ,
T_2 V_23 )
{
static F_23 ( V_24 , V_25 ,
V_26 ) ;
static const struct {
const char * V_27 ;
T_2 V_28 ;
} V_29 [] = {
{ L_3 , V_30 } ,
{ L_4 , V_31 } ,
{ L_5 , V_32 } ,
{ L_6 , V_33 } ,
} ;
const T_2 V_28 = V_30
| V_31
| V_32
| V_33 ;
unsigned int V_34 ;
F_24 ( & V_4 -> V_10 ) ;
V_23 &= V_4 -> V_9 & V_28 ;
F_25 ( & V_4 -> V_10 ) ;
if ( ! V_23 )
return;
if ( ! F_26 ( & V_24 ) )
return;
F_27 ( L_7 ) ;
for ( V_34 = 0 ; V_34 < F_28 ( V_29 ) ; ++ V_34 ) {
if ( V_29 [ V_34 ] . V_28 & V_23 )
F_29 ( L_8 , V_29 [ V_34 ] . V_27 ) ;
}
F_29 ( L_9 , V_23 ) ;
}
static void F_30 ( T_2 V_23 )
{
if ( ! ( V_23 & V_35 ) )
return;
F_27 ( L_10 ) ;
}
static T_3 F_31 ( int V_36 , void * V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 , * V_38 ;
unsigned long V_14 ;
unsigned int V_39 ;
T_2 V_23 ;
V_23 = F_32 () ;
F_33 ( V_23 ) ;
F_32 () ;
F_34 ( L_11 , V_23 ) ;
for ( V_39 = 0 ; V_39 < V_4 -> V_40 ; V_39 ++ ) {
struct V_20 * V_21 = V_4 -> V_22 [ V_39 ] ;
enum V_41 V_42 = F_20 ( V_21 ) ;
if ( V_23 & F_19 ( V_42 ) ) {
F_35 ( V_2 , V_39 ) ;
F_36 ( V_21 ) ;
}
if ( V_23 & F_37 ( V_42 ) )
F_38 ( V_21 , V_23 ) ;
}
F_30 ( V_23 ) ;
F_22 ( V_4 , V_23 ) ;
F_12 ( & V_4 -> V_10 , V_14 ) ;
F_39 (wait, n, &priv->wait_list, node) {
if ( V_7 -> V_8 & V_23 )
F_7 ( V_7 ) ;
}
F_14 ( & V_4 -> V_10 , V_14 ) ;
return V_43 ;
}
int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_44 = F_41 () ;
unsigned int V_45 ;
unsigned int V_34 ;
int V_18 ;
F_42 ( & V_4 -> V_10 ) ;
F_43 ( & V_4 -> V_16 ) ;
V_4 -> V_9 = V_35 ;
V_45 = F_44 ( F_28 ( V_4 -> V_46 ) ,
F_28 ( V_47 ) ) ;
for ( V_34 = 0 ; V_34 < V_45 ; ++ V_34 ) {
if ( V_4 -> V_46 [ V_34 ] )
V_4 -> V_9 |= V_47 [ V_34 ] ;
}
for ( V_34 = 0 ; V_34 < V_44 ; ++ V_34 )
V_4 -> V_9 |= F_37 ( V_34 ) ;
F_45 () ;
F_33 ( 0xffffffff ) ;
F_46 () ;
V_18 = F_47 ( F_31 , V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_2 -> V_48 = true ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 )
{
unsigned long V_49 ;
int V_34 ;
if ( ! V_2 -> V_48 )
return;
V_2 -> V_48 = false ;
if ( V_2 -> V_40 ) {
F_12 ( & V_2 -> V_50 , V_49 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_40 ; V_34 ++ ) {
F_8 ( & V_2 -> V_51 [ V_34 ] . V_52 ) ;
V_2 -> V_51 [ V_34 ] . V_53 = false ;
V_2 -> V_51 [ V_34 ] . V_54 =
V_2 -> V_55 -> V_56 ( V_2 , V_34 ) ;
}
F_14 ( & V_2 -> V_50 , V_49 ) ;
}
F_49 ( V_2 ) ;
}
