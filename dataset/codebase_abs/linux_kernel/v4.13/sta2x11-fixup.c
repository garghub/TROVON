static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return;
V_4 -> V_6 = V_2 -> V_7 -> V_8 + 1 ;
if ( F_3 ( & V_9 ) ) {
int V_10 = V_11 ;
F_4 ( & V_2 -> V_12 , L_1 , V_10 ) ;
if ( F_5 ( V_10 ) )
F_6 ( & V_2 -> V_12 , L_2 ) ;
}
F_7 ( & V_4 -> V_13 , & V_9 ) ;
}
static struct V_3 * F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_14 ;
F_9 (instance, &sta2x11_instance_list, list) {
V_14 = V_2 -> V_15 -> V_8 - V_4 -> V_6 ;
if ( V_14 >= 0 && V_14 < V_16 )
return V_4 ;
}
return NULL ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_8 ( V_2 ) ;
if ( ! V_4 )
return - 1 ;
return V_2 -> V_15 -> V_8 - V_4 -> V_6 ;
}
static struct V_17 * F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_14 ;
V_4 = F_8 ( V_2 ) ;
if ( ! V_4 )
return NULL ;
V_14 = F_10 ( V_2 ) ;
return V_4 -> V_18 + V_14 ;
}
struct V_3 * F_12 ( struct V_1 * V_2 )
{
return F_8 ( V_2 ) ;
}
static T_1 F_13 ( T_1 V_19 , struct V_1 * V_2 )
{
struct V_17 * V_18 ;
T_1 V_20 ;
V_18 = F_11 ( V_2 ) ;
V_20 = V_19 + V_18 -> V_21 ;
return V_20 ;
}
static T_1 F_14 ( T_1 V_20 , struct V_1 * V_2 )
{
struct V_17 * V_18 ;
T_1 V_19 ;
V_18 = F_11 ( V_2 ) ;
V_19 = V_20 - V_18 -> V_21 ;
return V_19 ;
}
static void * F_15 ( struct V_22 * V_12 ,
T_2 V_10 ,
T_1 * V_23 ,
T_3 V_24 ,
unsigned long V_25 )
{
void * V_26 ;
V_26 = F_16 ( V_12 , V_10 , V_23 , V_24 , V_25 ) ;
* V_23 = F_13 ( * V_23 , F_17 ( V_12 ) ) ;
return V_26 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_8 ( V_2 ) ;
if ( ! V_4 )
return;
F_19 ( V_2 , V_27 - 1 ) ;
F_20 ( V_2 , V_27 - 1 ) ;
V_2 -> V_12 . V_28 = & V_29 ;
F_21 ( V_2 ) ;
}
bool F_22 ( struct V_22 * V_12 , T_1 V_30 , T_2 V_10 )
{
struct V_17 * V_18 ;
if ( V_12 -> V_28 != & V_29 ) {
if ( ! V_12 -> V_31 )
return false ;
return V_30 + V_10 - 1 <= * V_12 -> V_31 ;
}
V_18 = F_11 ( F_17 ( V_12 ) ) ;
if ( ! V_18 || ( V_30 < V_18 -> V_21 ) )
return false ;
if ( V_30 + V_10 >= V_18 -> V_21 + V_27 ) {
return false ;
}
return true ;
}
T_1 F_23 ( struct V_22 * V_12 , T_4 V_32 )
{
if ( V_12 -> V_28 != & V_29 )
return V_32 ;
return F_13 ( V_32 , F_17 ( V_12 ) ) ;
}
T_4 F_24 ( struct V_22 * V_12 , T_1 V_33 )
{
if ( V_12 -> V_28 != & V_29 )
return V_33 ;
return F_14 ( V_33 , F_17 ( V_12 ) ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
int V_34 ;
if ( ! V_18 )
return;
F_26 ( V_2 , F_27 ( 0 ) , & V_18 -> V_21 ) ;
F_28 ( V_2 , F_29 ( 0 ) , 0 ) ;
F_28 ( V_2 , F_30 ( 0 ) , 0 ) ;
F_28 ( V_2 , F_31 ( 0 ) , V_27 |
V_35 | V_36 ) ;
for ( V_34 = 1 ; V_34 < V_37 ; V_34 ++ )
F_28 ( V_2 , F_31 ( V_34 ) , 0 ) ;
F_4 ( & V_2 -> V_12 ,
L_3 ,
F_10 ( V_2 ) , V_18 -> V_21 ,
V_18 -> V_21 + V_27 - 1 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
int V_34 ;
if ( ! V_18 )
return;
if ( V_18 -> V_38 )
return;
V_18 -> V_38 = 1 ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 ++ ) {
struct V_39 * V_40 = V_18 -> V_40 + V_34 ;
F_26 ( V_2 , F_27 ( V_34 ) , & V_40 -> V_41 ) ;
F_26 ( V_2 , F_29 ( V_34 ) , & V_40 -> V_42 ) ;
F_26 ( V_2 , F_30 ( V_34 ) , & V_40 -> V_43 ) ;
F_26 ( V_2 , F_31 ( V_34 ) , & V_40 -> V_44 ) ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
int V_34 ;
if ( ! V_18 )
return;
if ( ! V_18 -> V_38 )
goto V_45;
V_18 -> V_38 = 0 ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 ++ ) {
struct V_39 * V_40 = V_18 -> V_40 + V_34 ;
F_28 ( V_2 , F_27 ( V_34 ) , V_40 -> V_41 ) ;
F_28 ( V_2 , F_29 ( V_34 ) , V_40 -> V_42 ) ;
F_28 ( V_2 , F_30 ( V_34 ) , V_40 -> V_43 ) ;
F_28 ( V_2 , F_31 ( V_34 ) , V_40 -> V_44 ) ;
}
V_45:
F_21 ( V_2 ) ;
}
