static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_6 == V_7 )
return F_4 ( V_5 -> V_8 , V_4 ) ;
else
return - V_9 ;
}
static int F_5 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return ! ! F_6 ( & V_5 -> V_10 , 1 << V_4 ) ;
}
static void F_7 ( struct V_2 * V_3 , unsigned V_4 ,
int V_11 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_8 ( & V_5 -> V_10 , 1 << V_4 , V_11 ? 1 << V_4 : 0 ) ;
}
static int F_9 ( struct V_2 * V_3 ,
unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_10 ( & V_5 -> V_10 , 1 << V_4 , 0 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 ,
unsigned V_4 , int V_11 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_10 ( & V_5 -> V_10 , 1 << V_4 , 1 << V_4 ) ;
F_8 ( & V_5 -> V_10 , 1 << V_4 , V_11 ? 1 << V_4 : 0 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_13 ( & V_5 -> V_10 , 1 << V_4 , 0 ) ;
F_14 ( & V_5 -> V_10 , 1 << V_4 , 0 ) ;
F_15 ( & V_5 -> V_10 , 1 << V_4 , 1 << V_4 ) ;
return 0 ;
}
static void F_16 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_15 ( & V_5 -> V_10 , 1 << V_4 , 0 ) ;
}
static void F_17 ( struct V_12 * V_13 )
{
struct V_1 * V_5 = F_18 ( V_13 ) ;
int V_4 = F_19 ( V_13 ) ;
F_20 ( & V_5 -> V_10 , F_21 ( V_4 ) , 0 ) ;
}
static void F_22 ( struct V_12 * V_13 )
{
struct V_1 * V_5 = F_18 ( V_13 ) ;
int V_4 = F_19 ( V_13 ) ;
T_1 V_14 = F_6 ( & V_5 -> V_10 , F_21 ( V_4 ) ) ;
F_23 ( & V_5 -> V_10 , F_21 ( V_4 ) , V_14 ) ;
F_20 ( & V_5 -> V_10 , F_21 ( V_4 ) , F_21 ( V_4 ) ) ;
}
static T_2 F_24 ( int V_15 , void * V_16 )
{
struct V_1 * V_5 = V_16 ;
struct V_17 * V_10 = & V_5 -> V_10 ;
T_1 V_14 = F_25 ( V_10 , V_18 ) ;
T_1 V_19 = F_25 ( V_10 , V_20 ) ;
T_1 V_21 = F_25 ( V_10 , V_22 ) ;
unsigned long V_23 = ( V_14 ^ V_21 ) & V_19 ;
int V_4 ;
if ( ! V_23 )
return V_24 ;
F_26 (gpio, &irqs, bus->gpio.ngpio)
F_27 ( F_3 ( & V_5 -> V_4 , V_4 ) ) ;
F_23 ( V_10 , V_23 , V_14 & V_23 ) ;
return V_25 ;
}
static int F_28 ( struct V_1 * V_5 )
{
struct V_17 * V_10 = & V_5 -> V_10 ;
struct V_2 * V_3 = & V_5 -> V_4 ;
int V_4 , V_26 , V_27 ;
if ( V_5 -> V_6 != V_7 )
return 0 ;
V_5 -> V_8 = F_29 ( NULL , V_3 -> V_28 ,
& V_29 , V_10 ) ;
if ( ! V_5 -> V_8 ) {
V_27 = - V_30 ;
goto V_31;
}
for ( V_4 = 0 ; V_4 < V_3 -> V_28 ; V_4 ++ ) {
int V_15 = F_30 ( V_5 -> V_8 , V_4 ) ;
F_31 ( V_15 , V_5 ) ;
F_32 ( V_15 , & V_32 ,
V_33 ) ;
}
V_26 = F_33 ( V_5 -> V_10 . V_34 ) + 2 ;
V_27 = F_34 ( V_26 , F_24 , V_35 ,
L_1 , V_5 ) ;
if ( V_27 )
goto V_36;
F_20 ( & V_5 -> V_10 , ~ 0 , 0 ) ;
F_35 ( V_10 , V_37 , V_38 ) ;
return 0 ;
V_36:
for ( V_4 = 0 ; V_4 < V_3 -> V_28 ; V_4 ++ ) {
int V_15 = F_4 ( V_5 -> V_8 , V_4 ) ;
F_36 ( V_15 ) ;
}
F_37 ( V_5 -> V_8 ) ;
V_31:
return V_27 ;
}
static void F_38 ( struct V_1 * V_5 )
{
struct V_17 * V_10 = & V_5 -> V_10 ;
struct V_2 * V_3 = & V_5 -> V_4 ;
int V_4 ;
if ( V_5 -> V_6 != V_7 )
return;
F_39 ( V_10 , V_37 , ~ V_38 ) ;
F_40 ( F_33 ( V_5 -> V_10 . V_34 ) + 2 , V_10 ) ;
for ( V_4 = 0 ; V_4 < V_3 -> V_28 ; V_4 ++ ) {
int V_15 = F_4 ( V_5 -> V_8 , V_4 ) ;
F_36 ( V_15 ) ;
}
F_37 ( V_5 -> V_8 ) ;
}
static int F_28 ( struct V_1 * V_5 )
{
return 0 ;
}
static void F_38 ( struct V_1 * V_5 )
{
}
static int F_41 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_4 ;
int V_27 ;
V_3 -> V_39 = L_2 ;
V_3 -> V_40 = V_41 ;
V_3 -> V_42 = F_12 ;
V_3 -> free = F_16 ;
V_3 -> V_43 = F_5 ;
V_3 -> V_44 = F_7 ;
V_3 -> V_45 = F_9 ;
V_3 -> V_46 = F_11 ;
#if F_42 ( V_47 )
V_3 -> V_48 = F_3 ;
#endif
V_3 -> V_28 = 16 ;
if ( V_5 -> V_6 == V_7 )
V_3 -> V_49 = 0 ;
else
V_3 -> V_49 = - 1 ;
V_27 = F_28 ( V_5 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_43 ( V_3 ) ;
if ( V_27 ) {
F_38 ( V_5 ) ;
return V_27 ;
}
return 0 ;
}
static int F_44 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return ! ! F_45 ( & V_5 -> V_50 , 1 << V_4 ) ;
}
static void F_46 ( struct V_2 * V_3 , unsigned V_4 ,
int V_11 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_47 ( & V_5 -> V_50 , 1 << V_4 , V_11 ? 1 << V_4 : 0 ) ;
}
static int F_48 ( struct V_2 * V_3 ,
unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_49 ( & V_5 -> V_50 , 1 << V_4 , 0 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_3 ,
unsigned V_4 , int V_11 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_49 ( & V_5 -> V_50 , 1 << V_4 , 1 << V_4 ) ;
F_47 ( & V_5 -> V_50 , 1 << V_4 , V_11 ? 1 << V_4 : 0 ) ;
return 0 ;
}
static void F_51 ( struct V_12 * V_13 )
{
struct V_1 * V_5 = F_18 ( V_13 ) ;
int V_4 = F_19 ( V_13 ) ;
F_52 ( & V_5 -> V_50 , F_21 ( V_4 ) , 0 ) ;
}
static void F_53 ( struct V_12 * V_13 )
{
struct V_1 * V_5 = F_18 ( V_13 ) ;
int V_4 = F_19 ( V_13 ) ;
T_1 V_14 = F_45 ( & V_5 -> V_50 , F_21 ( V_4 ) ) ;
F_54 ( & V_5 -> V_50 , F_21 ( V_4 ) , V_14 ) ;
F_52 ( & V_5 -> V_50 , F_21 ( V_4 ) , F_21 ( V_4 ) ) ;
}
static T_2 F_55 ( int V_15 , void * V_16 )
{
struct V_1 * V_5 = V_16 ;
struct V_51 * V_50 = & V_5 -> V_50 ;
T_1 V_14 = F_56 ( V_50 -> V_34 , V_52 ) ;
T_1 V_19 = F_56 ( V_50 -> V_34 , V_53 ) ;
T_1 V_21 = F_56 ( V_50 -> V_34 , V_54 ) ;
unsigned long V_23 = ( V_14 ^ V_21 ) & V_19 ;
int V_4 ;
if ( ! V_23 )
return V_24 ;
F_26 (gpio, &irqs, bus->gpio.ngpio)
F_27 ( F_3 ( & V_5 -> V_4 , V_4 ) ) ;
F_54 ( V_50 , V_23 , V_14 & V_23 ) ;
return V_25 ;
}
static int F_57 ( struct V_1 * V_5 )
{
struct V_51 * V_50 = & V_5 -> V_50 ;
struct V_2 * V_3 = & V_5 -> V_4 ;
int V_4 , V_26 , V_27 ;
if ( V_5 -> V_6 != V_7 )
return 0 ;
V_5 -> V_8 = F_29 ( NULL , V_3 -> V_28 ,
& V_29 , V_50 ) ;
if ( ! V_5 -> V_8 ) {
V_27 = - V_30 ;
goto V_31;
}
for ( V_4 = 0 ; V_4 < V_3 -> V_28 ; V_4 ++ ) {
int V_15 = F_30 ( V_5 -> V_8 , V_4 ) ;
F_31 ( V_15 , V_5 ) ;
F_32 ( V_15 , & V_55 ,
V_33 ) ;
}
V_26 = F_33 ( V_5 -> V_50 . V_34 ) + 2 ;
V_27 = F_34 ( V_26 , F_55 , V_35 ,
L_1 , V_5 ) ;
if ( V_27 )
goto V_36;
F_52 ( & V_5 -> V_50 , ~ 0 , 0 ) ;
return 0 ;
V_36:
for ( V_4 = 0 ; V_4 < V_3 -> V_28 ; V_4 ++ ) {
int V_15 = F_4 ( V_5 -> V_8 , V_4 ) ;
F_36 ( V_15 ) ;
}
F_37 ( V_5 -> V_8 ) ;
V_31:
return V_27 ;
}
static void F_58 ( struct V_1 * V_5 )
{
struct V_51 * V_50 = & V_5 -> V_50 ;
struct V_2 * V_3 = & V_5 -> V_4 ;
int V_4 ;
if ( V_5 -> V_6 != V_7 )
return;
F_40 ( F_33 ( V_5 -> V_50 . V_34 ) + 2 , V_50 ) ;
for ( V_4 = 0 ; V_4 < V_3 -> V_28 ; V_4 ++ ) {
int V_15 = F_4 ( V_5 -> V_8 , V_4 ) ;
F_36 ( V_15 ) ;
}
F_37 ( V_5 -> V_8 ) ;
}
static int F_57 ( struct V_1 * V_5 )
{
return 0 ;
}
static void F_58 ( struct V_1 * V_5 )
{
}
static int F_59 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_4 ;
int V_27 ;
V_3 -> V_39 = L_3 ;
V_3 -> V_40 = V_41 ;
V_3 -> V_43 = F_44 ;
V_3 -> V_44 = F_46 ;
V_3 -> V_45 = F_48 ;
V_3 -> V_46 = F_50 ;
#if F_42 ( V_47 )
V_3 -> V_48 = F_3 ;
#endif
V_3 -> V_28 = 5 ;
if ( V_5 -> V_6 == V_7 )
V_3 -> V_49 = 0 ;
else
V_3 -> V_49 = - 1 ;
V_27 = F_57 ( V_5 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_43 ( V_3 ) ;
if ( V_27 ) {
F_58 ( V_5 ) ;
return V_27 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_5 )
{
return - V_56 ;
}
int F_60 ( struct V_1 * V_5 )
{
if ( F_61 ( & V_5 -> V_10 ) )
return F_41 ( V_5 ) ;
else if ( F_62 ( & V_5 -> V_50 ) )
return F_59 ( V_5 ) ;
else
F_63 ( 1 ) ;
return - 1 ;
}
int F_64 ( struct V_1 * V_5 )
{
if ( F_61 ( & V_5 -> V_10 ) ||
F_62 ( & V_5 -> V_50 ) ) {
F_65 ( & V_5 -> V_4 ) ;
return 0 ;
} else {
F_63 ( 1 ) ;
}
return - 1 ;
}
