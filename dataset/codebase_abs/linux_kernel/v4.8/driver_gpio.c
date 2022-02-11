static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_6 == V_7 )
return F_3 ( V_5 -> V_8 , V_3 ) ;
else
return - V_9 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return ! ! F_5 ( & V_5 -> V_10 , 1 << V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_7 ( & V_5 -> V_10 , 1 << V_3 , V_11 ? 1 << V_3 : 0 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_9 ( & V_5 -> V_10 , 1 << V_3 , 0 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_9 ( & V_5 -> V_10 , 1 << V_3 , 1 << V_3 ) ;
F_7 ( & V_5 -> V_10 , 1 << V_3 , V_11 ? 1 << V_3 : 0 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_12 ( & V_5 -> V_10 , 1 << V_3 , 0 ) ;
F_13 ( & V_5 -> V_10 , 1 << V_3 , 0 ) ;
F_14 ( & V_5 -> V_10 , 1 << V_3 , 1 << V_3 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_14 ( & V_5 -> V_10 , 1 << V_3 , 0 ) ;
}
static void F_16 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_17 ( V_13 ) ;
int V_3 = F_18 ( V_13 ) ;
F_19 ( & V_5 -> V_10 , F_20 ( V_3 ) , 0 ) ;
}
static void F_21 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_17 ( V_13 ) ;
int V_3 = F_18 ( V_13 ) ;
T_1 V_14 = F_5 ( & V_5 -> V_10 , F_20 ( V_3 ) ) ;
F_22 ( & V_5 -> V_10 , F_20 ( V_3 ) , V_14 ) ;
F_19 ( & V_5 -> V_10 , F_20 ( V_3 ) , F_20 ( V_3 ) ) ;
}
static T_2 F_23 ( int V_15 , void * V_16 )
{
struct V_4 * V_5 = V_16 ;
struct V_17 * V_10 = & V_5 -> V_10 ;
T_1 V_14 = F_24 ( V_10 , V_18 ) ;
T_1 V_19 = F_24 ( V_10 , V_20 ) ;
T_1 V_21 = F_24 ( V_10 , V_22 ) ;
unsigned long V_23 = ( V_14 ^ V_21 ) & V_19 ;
int V_3 ;
if ( ! V_23 )
return V_24 ;
F_25 (gpio, &irqs, bus->gpio.ngpio)
F_26 ( F_1 ( & V_5 -> V_3 , V_3 ) ) ;
F_22 ( V_10 , V_23 , V_14 & V_23 ) ;
return V_25 ;
}
static int F_27 ( struct V_4 * V_5 )
{
struct V_17 * V_10 = & V_5 -> V_10 ;
struct V_1 * V_2 = & V_5 -> V_3 ;
int V_3 , V_26 , V_27 ;
if ( V_5 -> V_6 != V_7 )
return 0 ;
V_5 -> V_8 = F_28 ( NULL , V_2 -> V_28 ,
& V_29 , V_10 ) ;
if ( ! V_5 -> V_8 ) {
V_27 = - V_30 ;
goto V_31;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_28 ; V_3 ++ ) {
int V_15 = F_29 ( V_5 -> V_8 , V_3 ) ;
F_30 ( V_15 , V_5 ) ;
F_31 ( V_15 , & V_32 ,
V_33 ) ;
}
V_26 = F_32 ( V_5 -> V_10 . V_34 ) + 2 ;
V_27 = F_33 ( V_26 , F_23 , V_35 ,
L_1 , V_5 ) ;
if ( V_27 )
goto V_36;
F_19 ( & V_5 -> V_10 , ~ 0 , 0 ) ;
F_34 ( V_10 , V_37 , V_38 ) ;
return 0 ;
V_36:
for ( V_3 = 0 ; V_3 < V_2 -> V_28 ; V_3 ++ ) {
int V_15 = F_3 ( V_5 -> V_8 , V_3 ) ;
F_35 ( V_15 ) ;
}
F_36 ( V_5 -> V_8 ) ;
V_31:
return V_27 ;
}
static void F_37 ( struct V_4 * V_5 )
{
struct V_17 * V_10 = & V_5 -> V_10 ;
struct V_1 * V_2 = & V_5 -> V_3 ;
int V_3 ;
if ( V_5 -> V_6 != V_7 )
return;
F_38 ( V_10 , V_37 , ~ V_38 ) ;
F_39 ( F_32 ( V_5 -> V_10 . V_34 ) + 2 , V_10 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_28 ; V_3 ++ ) {
int V_15 = F_3 ( V_5 -> V_8 , V_3 ) ;
F_35 ( V_15 ) ;
}
F_36 ( V_5 -> V_8 ) ;
}
static int F_27 ( struct V_4 * V_5 )
{
return 0 ;
}
static void F_37 ( struct V_4 * V_5 )
{
}
static int F_40 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_3 ;
int V_27 ;
V_2 -> V_39 = L_2 ;
V_2 -> V_40 = V_41 ;
V_2 -> V_42 = F_11 ;
V_2 -> free = F_15 ;
V_2 -> V_43 = F_4 ;
V_2 -> V_44 = F_6 ;
V_2 -> V_45 = F_8 ;
V_2 -> V_46 = F_10 ;
#if F_41 ( V_47 )
V_2 -> V_48 = F_1 ;
#endif
V_2 -> V_28 = 16 ;
if ( V_5 -> V_6 == V_7 )
V_2 -> V_49 = 0 ;
else
V_2 -> V_49 = - 1 ;
V_27 = F_27 ( V_5 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_42 ( V_2 , V_5 ) ;
if ( V_27 ) {
F_37 ( V_5 ) ;
return V_27 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return ! ! F_44 ( & V_5 -> V_50 , 1 << V_3 ) ;
}
static void F_45 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_46 ( & V_5 -> V_50 , 1 << V_3 , V_11 ? 1 << V_3 : 0 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_48 ( & V_5 -> V_50 , 1 << V_3 , 0 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_48 ( & V_5 -> V_50 , 1 << V_3 , 1 << V_3 ) ;
F_46 ( & V_5 -> V_50 , 1 << V_3 , V_11 ? 1 << V_3 : 0 ) ;
return 0 ;
}
static void F_50 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_17 ( V_13 ) ;
int V_3 = F_18 ( V_13 ) ;
F_51 ( & V_5 -> V_50 , F_20 ( V_3 ) , 0 ) ;
}
static void F_52 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_17 ( V_13 ) ;
int V_3 = F_18 ( V_13 ) ;
T_1 V_14 = F_44 ( & V_5 -> V_50 , F_20 ( V_3 ) ) ;
F_53 ( & V_5 -> V_50 , F_20 ( V_3 ) , V_14 ) ;
F_51 ( & V_5 -> V_50 , F_20 ( V_3 ) , F_20 ( V_3 ) ) ;
}
static T_2 F_54 ( int V_15 , void * V_16 )
{
struct V_4 * V_5 = V_16 ;
struct V_51 * V_50 = & V_5 -> V_50 ;
T_1 V_14 = F_55 ( V_50 -> V_34 , V_52 ) ;
T_1 V_19 = F_55 ( V_50 -> V_34 , V_53 ) ;
T_1 V_21 = F_55 ( V_50 -> V_34 , V_54 ) ;
unsigned long V_23 = ( V_14 ^ V_21 ) & V_19 ;
int V_3 ;
if ( ! V_23 )
return V_24 ;
F_25 (gpio, &irqs, bus->gpio.ngpio)
F_26 ( F_1 ( & V_5 -> V_3 , V_3 ) ) ;
F_53 ( V_50 , V_23 , V_14 & V_23 ) ;
return V_25 ;
}
static int F_56 ( struct V_4 * V_5 )
{
struct V_51 * V_50 = & V_5 -> V_50 ;
struct V_1 * V_2 = & V_5 -> V_3 ;
int V_3 , V_26 , V_27 ;
if ( V_5 -> V_6 != V_7 )
return 0 ;
V_5 -> V_8 = F_28 ( NULL , V_2 -> V_28 ,
& V_29 , V_50 ) ;
if ( ! V_5 -> V_8 ) {
V_27 = - V_30 ;
goto V_31;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_28 ; V_3 ++ ) {
int V_15 = F_29 ( V_5 -> V_8 , V_3 ) ;
F_30 ( V_15 , V_5 ) ;
F_31 ( V_15 , & V_55 ,
V_33 ) ;
}
V_26 = F_32 ( V_5 -> V_50 . V_34 ) + 2 ;
V_27 = F_33 ( V_26 , F_54 , V_35 ,
L_1 , V_5 ) ;
if ( V_27 )
goto V_36;
F_51 ( & V_5 -> V_50 , ~ 0 , 0 ) ;
return 0 ;
V_36:
for ( V_3 = 0 ; V_3 < V_2 -> V_28 ; V_3 ++ ) {
int V_15 = F_3 ( V_5 -> V_8 , V_3 ) ;
F_35 ( V_15 ) ;
}
F_36 ( V_5 -> V_8 ) ;
V_31:
return V_27 ;
}
static void F_57 ( struct V_4 * V_5 )
{
struct V_51 * V_50 = & V_5 -> V_50 ;
struct V_1 * V_2 = & V_5 -> V_3 ;
int V_3 ;
if ( V_5 -> V_6 != V_7 )
return;
F_39 ( F_32 ( V_5 -> V_50 . V_34 ) + 2 , V_50 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_28 ; V_3 ++ ) {
int V_15 = F_3 ( V_5 -> V_8 , V_3 ) ;
F_35 ( V_15 ) ;
}
F_36 ( V_5 -> V_8 ) ;
}
static int F_56 ( struct V_4 * V_5 )
{
return 0 ;
}
static void F_57 ( struct V_4 * V_5 )
{
}
static int F_58 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_3 ;
int V_27 ;
V_2 -> V_39 = L_3 ;
V_2 -> V_40 = V_41 ;
V_2 -> V_43 = F_43 ;
V_2 -> V_44 = F_45 ;
V_2 -> V_45 = F_47 ;
V_2 -> V_46 = F_49 ;
#if F_41 ( V_47 )
V_2 -> V_48 = F_1 ;
#endif
V_2 -> V_28 = 5 ;
if ( V_5 -> V_6 == V_7 )
V_2 -> V_49 = 0 ;
else
V_2 -> V_49 = - 1 ;
V_27 = F_56 ( V_5 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_42 ( V_2 , V_5 ) ;
if ( V_27 ) {
F_57 ( V_5 ) ;
return V_27 ;
}
return 0 ;
}
static int F_58 ( struct V_4 * V_5 )
{
return - V_56 ;
}
int F_59 ( struct V_4 * V_5 )
{
if ( F_60 ( & V_5 -> V_10 ) )
return F_40 ( V_5 ) ;
else if ( F_61 ( & V_5 -> V_50 ) )
return F_58 ( V_5 ) ;
else
F_62 ( 1 ) ;
return - 1 ;
}
int F_63 ( struct V_4 * V_5 )
{
if ( F_60 ( & V_5 -> V_10 ) ||
F_61 ( & V_5 -> V_50 ) ) {
F_64 ( & V_5 -> V_3 ) ;
return 0 ;
} else {
F_62 ( 1 ) ;
}
return - 1 ;
}
