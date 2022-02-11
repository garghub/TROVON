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
V_4 -> V_11 -> V_13 () ;
}
static void F_5 ( struct V_6 * V_7 )
{
V_7 -> V_14 -- ;
F_6 ( & V_7 -> V_15 ) ;
}
struct V_6 * F_7 ( struct V_1 * V_2 ,
T_1 V_8 , int V_14 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_8 ( sizeof( * V_7 ) , V_16 ) ;
unsigned long V_17 ;
F_9 ( & V_7 -> V_15 ) ;
V_7 -> V_8 = V_8 ;
V_7 -> V_14 = V_14 ;
F_10 ( & V_4 -> V_10 , V_17 ) ;
F_11 ( & V_7 -> V_18 , & V_4 -> V_19 ) ;
F_1 ( V_2 ) ;
F_12 ( & V_4 -> V_10 , V_17 ) ;
return V_7 ;
}
int V_6 ( struct V_1 * V_2 , struct V_6 * V_7 ,
unsigned long V_20 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_17 ;
int V_21 ;
V_21 = F_13 ( V_7 -> V_15 , ( V_7 -> V_14 <= 0 ) , V_20 ) ;
F_10 ( & V_4 -> V_10 , V_17 ) ;
F_14 ( & V_7 -> V_18 ) ;
F_1 ( V_2 ) ;
F_12 ( & V_4 -> V_10 , V_17 ) ;
F_15 ( V_7 ) ;
return V_21 == 0 ? - 1 : 0 ;
}
int F_16 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_17 ;
enum V_24 V_25 = F_17 ( V_23 ) ;
F_4 ( L_2 , V_2 , V_25 ) ;
F_10 ( & V_4 -> V_10 , V_17 ) ;
V_4 -> V_9 |= V_4 -> V_11 -> V_26 ( V_25 ) ;
F_1 ( V_2 ) ;
F_12 ( & V_4 -> V_10 , V_17 ) ;
return 0 ;
}
void F_18 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_17 ;
enum V_24 V_25 = F_17 ( V_23 ) ;
F_4 ( L_2 , V_2 , V_25 ) ;
F_10 ( & V_4 -> V_10 , V_17 ) ;
V_4 -> V_9 &= ~ V_4 -> V_11 -> V_26 ( V_25 ) ;
F_1 ( V_2 ) ;
F_12 ( & V_4 -> V_10 , V_17 ) ;
}
static void F_19 ( struct V_3 * V_4 ,
T_2 V_27 )
{
static F_20 ( V_28 , V_29 ,
V_30 ) ;
static const struct {
const char * V_31 ;
T_2 V_32 ;
} V_33 [] = {
{ L_3 , V_34 } ,
{ L_4 , V_35 } ,
{ L_5 , V_36 } ,
{ L_6 , V_37 } ,
} ;
const T_2 V_32 = V_34
| V_35
| V_36
| V_37 ;
unsigned int V_38 ;
F_21 ( & V_4 -> V_10 ) ;
V_27 &= V_4 -> V_9 & V_32 ;
F_22 ( & V_4 -> V_10 ) ;
if ( ! V_27 )
return;
if ( ! F_23 ( & V_28 ) )
return;
F_24 ( L_7 ) ;
for ( V_38 = 0 ; V_38 < F_25 ( V_33 ) ; ++ V_38 ) {
if ( V_33 [ V_38 ] . V_32 & V_27 )
F_26 ( L_8 , V_33 [ V_38 ] . V_31 ) ;
}
F_26 ( L_9 , V_27 ) ;
}
static void F_27 ( T_2 V_27 )
{
if ( ! ( V_27 & V_39 ) )
return;
F_24 ( L_10 ) ;
}
static T_3 F_28 ( int V_40 , void * V_41 )
{
struct V_1 * V_2 = (struct V_1 * ) V_41 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 , * V_42 ;
unsigned long V_17 ;
unsigned int V_43 ;
T_2 V_27 ;
V_27 = V_4 -> V_11 -> V_44 () ;
V_4 -> V_11 -> V_45 ( V_27 ) ;
V_4 -> V_11 -> V_44 () ;
F_29 ( L_11 , V_27 ) ;
for ( V_43 = 0 ; V_43 < V_4 -> V_46 ; V_43 ++ ) {
struct V_22 * V_23 = V_4 -> V_47 [ V_43 ] ;
enum V_24 V_25 = F_17 ( V_23 ) ;
if ( V_27 & V_4 -> V_11 -> V_26 ( V_25 ) ) {
F_30 ( V_2 , V_43 ) ;
F_31 ( V_23 ) ;
}
if ( V_27 & V_4 -> V_11 -> V_48 ( V_25 ) )
F_32 ( V_23 , V_27 ) ;
}
F_27 ( V_27 ) ;
F_19 ( V_4 , V_27 ) ;
F_10 ( & V_4 -> V_10 , V_17 ) ;
F_33 (wait, n, &priv->wait_list, node) {
if ( V_7 -> V_8 & V_27 )
F_5 ( V_7 ) ;
}
F_12 ( & V_4 -> V_10 , V_17 ) ;
return V_49 ;
}
int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_50 = V_4 -> V_11 -> V_51 () ;
unsigned int V_52 ;
unsigned int V_38 ;
int V_21 ;
F_35 ( & V_4 -> V_10 ) ;
F_36 ( & V_4 -> V_19 ) ;
V_4 -> V_9 = V_39 ;
V_52 = F_37 ( F_25 ( V_4 -> V_53 ) ,
F_25 ( V_54 ) ) ;
for ( V_38 = 0 ; V_38 < V_52 ; ++ V_38 ) {
if ( V_4 -> V_53 [ V_38 ] )
V_4 -> V_9 |= V_54 [ V_38 ] ;
}
for ( V_38 = 0 ; V_38 < V_50 ; ++ V_38 )
V_4 -> V_9 |= V_4 -> V_11 -> V_48 ( V_38 ) ;
V_4 -> V_11 -> V_55 () ;
V_4 -> V_11 -> V_45 ( 0xffffffff ) ;
V_4 -> V_11 -> V_56 () ;
V_21 = V_4 -> V_11 -> V_57 ( F_28 , V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
V_2 -> V_58 = true ;
return 0 ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_2 -> V_58 )
return;
V_2 -> V_58 = false ;
V_4 -> V_11 -> V_59 ( V_2 ) ;
}
