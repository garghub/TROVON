static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
T_1 V_8 = V_4 -> V_9 ;
F_2 ( & V_4 -> V_10 ) ;
F_3 (wait, &priv->wait_list, node)
V_8 |= V_7 -> V_8 ;
F_4 ( L_1 , V_8 ) ;
V_4 -> V_11 -> V_12 ( V_8 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
V_7 -> V_13 -- ;
F_6 ( & V_7 -> V_14 ) ;
}
struct V_6 * F_7 ( struct V_1 * V_2 ,
T_1 V_8 , int V_13 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_8 ( sizeof( * V_7 ) , V_15 ) ;
unsigned long V_16 ;
F_9 ( & V_7 -> V_14 ) ;
V_7 -> V_8 = V_8 ;
V_7 -> V_13 = V_13 ;
F_10 ( & V_4 -> V_10 , V_16 ) ;
F_11 ( & V_7 -> V_17 , & V_4 -> V_18 ) ;
F_1 ( V_2 ) ;
F_12 ( & V_4 -> V_10 , V_16 ) ;
return V_7 ;
}
int V_6 ( struct V_1 * V_2 , struct V_6 * V_7 ,
unsigned long V_19 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_16 ;
int V_20 ;
V_20 = F_13 ( V_7 -> V_14 , ( V_7 -> V_13 <= 0 ) , V_19 ) ;
F_10 ( & V_4 -> V_10 , V_16 ) ;
F_14 ( & V_7 -> V_17 ) ;
F_1 ( V_2 ) ;
F_12 ( & V_4 -> V_10 , V_16 ) ;
F_15 ( V_7 ) ;
return V_20 == 0 ? - 1 : 0 ;
}
int F_16 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_16 ;
enum V_23 V_24 = F_17 ( V_22 ) ;
F_4 ( L_2 , V_2 , V_24 ) ;
F_10 ( & V_4 -> V_10 , V_16 ) ;
V_4 -> V_9 |= V_4 -> V_11 -> V_25 ( V_24 ) ;
F_1 ( V_2 ) ;
F_12 ( & V_4 -> V_10 , V_16 ) ;
return 0 ;
}
void F_18 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_16 ;
enum V_23 V_24 = F_17 ( V_22 ) ;
F_4 ( L_2 , V_2 , V_24 ) ;
F_10 ( & V_4 -> V_10 , V_16 ) ;
V_4 -> V_9 &= ~ V_4 -> V_11 -> V_25 ( V_24 ) ;
F_1 ( V_2 ) ;
F_12 ( & V_4 -> V_10 , V_16 ) ;
}
static void F_19 ( struct V_3 * V_4 ,
T_2 V_26 )
{
static F_20 ( V_27 , V_28 ,
V_29 ) ;
static const struct {
const char * V_30 ;
T_2 V_31 ;
} V_32 [] = {
{ L_3 , V_33 } ,
{ L_4 , V_34 } ,
{ L_5 , V_35 } ,
{ L_6 , V_36 } ,
} ;
const T_2 V_31 = V_33
| V_34
| V_35
| V_36 ;
unsigned int V_37 ;
F_21 ( & V_4 -> V_10 ) ;
V_26 &= V_4 -> V_9 & V_31 ;
F_22 ( & V_4 -> V_10 ) ;
if ( ! V_26 )
return;
if ( ! F_23 ( & V_27 ) )
return;
F_24 ( L_7 ) ;
for ( V_37 = 0 ; V_37 < F_25 ( V_32 ) ; ++ V_37 ) {
if ( V_32 [ V_37 ] . V_31 & V_26 )
F_26 ( L_8 , V_32 [ V_37 ] . V_30 ) ;
}
F_26 ( L_9 , V_26 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
T_2 V_26 )
{
if ( ! ( V_26 & V_38 ) )
return;
F_28 ( V_2 -> V_2 , L_10 ) ;
}
static T_3 F_29 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 , * V_41 ;
unsigned long V_16 ;
unsigned int V_42 ;
T_2 V_26 ;
V_26 = V_4 -> V_11 -> V_43 () ;
V_4 -> V_11 -> V_44 ( V_26 ) ;
V_4 -> V_11 -> V_43 () ;
F_30 ( L_11 , V_26 ) ;
for ( V_42 = 0 ; V_42 < V_4 -> V_45 ; V_42 ++ ) {
struct V_21 * V_22 = V_4 -> V_46 [ V_42 ] ;
enum V_23 V_24 = F_17 ( V_22 ) ;
if ( V_26 & V_4 -> V_11 -> V_25 ( V_24 ) ) {
F_31 ( V_2 , V_42 ) ;
F_32 ( V_22 ) ;
}
if ( V_26 & V_4 -> V_11 -> V_47 ( V_24 ) )
F_33 ( V_22 , V_26 ) ;
}
F_27 ( V_2 , V_26 ) ;
F_19 ( V_4 , V_26 ) ;
F_10 ( & V_4 -> V_10 , V_16 ) ;
F_34 (wait, n, &priv->wait_list, node) {
if ( V_7 -> V_8 & V_26 )
F_5 ( V_7 ) ;
}
F_12 ( & V_4 -> V_10 , V_16 ) ;
return V_48 ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_49 = V_4 -> V_11 -> V_50 () ;
unsigned int V_51 ;
unsigned int V_37 ;
int V_20 ;
F_36 ( & V_4 -> V_10 ) ;
F_37 ( & V_4 -> V_18 ) ;
V_4 -> V_9 = V_38 ;
V_51 = F_38 ( F_25 ( V_4 -> V_52 ) ,
F_25 ( V_53 ) ) ;
for ( V_37 = 0 ; V_37 < V_51 ; ++ V_37 ) {
if ( V_4 -> V_52 [ V_37 ] )
V_4 -> V_9 |= V_53 [ V_37 ] ;
}
for ( V_37 = 0 ; V_37 < V_49 ; ++ V_37 )
V_4 -> V_9 |= V_4 -> V_11 -> V_47 ( V_37 ) ;
V_4 -> V_11 -> V_54 () ;
V_4 -> V_11 -> V_44 ( 0xffffffff ) ;
V_4 -> V_11 -> V_55 () ;
V_20 = V_4 -> V_11 -> V_56 ( F_29 , V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
V_2 -> V_57 = true ;
return 0 ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_2 -> V_57 )
return;
V_2 -> V_57 = false ;
V_4 -> V_11 -> V_58 ( V_2 ) ;
}
