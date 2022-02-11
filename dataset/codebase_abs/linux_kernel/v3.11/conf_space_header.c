static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 , void * V_5 )
{
int V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( ! F_3 ( V_2 ) )
return V_7 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
if ( V_2 -> V_9 [ V_6 ] . V_10 & V_11 )
* V_4 |= V_12 ;
if ( V_2 -> V_9 [ V_6 ] . V_10 & V_13 )
* V_4 |= V_14 ;
}
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , void * V_5 )
{
struct V_15 * V_16 ;
int V_17 ;
V_16 = F_5 ( V_2 ) ;
if ( ! F_3 ( V_2 ) && F_6 ( V_4 ) ) {
if ( F_7 ( V_18 ) )
F_8 (KERN_DEBUG DRV_NAME L_1 ,
pci_name(dev)) ;
V_17 = F_9 ( V_2 ) ;
if ( V_17 )
return V_17 ;
if ( V_16 )
V_16 -> V_19 = 1 ;
} else if ( F_3 ( V_2 ) && ! F_6 ( V_4 ) ) {
if ( F_7 ( V_18 ) )
F_8 (KERN_DEBUG DRV_NAME L_2 ,
pci_name(dev)) ;
F_10 ( V_2 ) ;
if ( V_16 )
V_16 -> V_19 = 0 ;
}
if ( ! V_2 -> V_20 && F_11 ( V_4 ) ) {
if ( F_7 ( V_18 ) )
F_8 (KERN_DEBUG DRV_NAME L_3 ,
pci_name(dev)) ;
F_12 ( V_2 ) ;
}
if ( V_4 & V_21 ) {
if ( F_7 ( V_18 ) )
F_8 (KERN_DEBUG
DRV_NAME L_4 ,
pci_name(dev)) ;
V_17 = F_13 ( V_2 ) ;
if ( V_17 ) {
F_14 ( L_5 ,
F_15 ( V_2 ) , V_17 ) ;
V_4 &= ~ V_21 ;
}
}
return F_16 ( V_2 , V_3 , V_4 ) ;
}
static int F_17 ( struct V_1 * V_2 , int V_3 , T_2 V_4 , void * V_5 )
{
struct V_22 * V_23 = V_5 ;
if ( F_7 ( ! V_23 ) ) {
F_14 ( V_24 L_6 ,
F_15 ( V_2 ) ) ;
return V_25 ;
}
if ( V_4 == ~ V_26 )
V_23 -> V_27 = 1 ;
else {
T_2 V_28 ;
F_18 ( V_2 , V_3 , & V_28 ) ;
if ( V_28 != V_23 -> V_29 && V_4 == V_23 -> V_29 ) {
F_19 ( V_2 , V_3 , V_23 -> V_29 ) ;
}
V_23 -> V_27 = 0 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_3 , T_2 V_4 , void * V_5 )
{
struct V_22 * V_23 = V_5 ;
if ( F_7 ( ! V_23 ) ) {
F_14 ( V_24 L_6 ,
F_15 ( V_2 ) ) ;
return V_25 ;
}
if ( V_4 == ~ 0 )
V_23 -> V_27 = 1 ;
else {
T_2 V_28 ;
F_18 ( V_2 , V_3 , & V_28 ) ;
if ( V_28 != V_23 -> V_29 && V_4 == V_23 -> V_29 ) {
F_19 ( V_2 , V_3 , V_23 -> V_29 ) ;
}
V_23 -> V_27 = 0 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 , void * V_5 )
{
struct V_22 * V_23 = V_5 ;
if ( F_7 ( ! V_23 ) ) {
F_14 ( V_24 L_6 ,
F_15 ( V_2 ) ) ;
return V_25 ;
}
* V_4 = V_23 -> V_27 ? V_23 -> V_30 : V_23 -> V_29 ;
return 0 ;
}
static inline void F_22 ( struct V_1 * V_2 ,
struct V_22 * V_31 , int V_3 ,
T_2 V_32 )
{
int V_33 ;
struct V_9 * V_34 = V_2 -> V_9 ;
if ( V_3 == V_35 || V_3 == V_36 )
V_33 = V_8 ;
else {
V_33 = ( V_3 - V_37 ) / 4 ;
if ( V_33 && ( ( V_34 [ V_33 - 1 ] . V_10 & ( V_38 |
V_39 ) ) ==
( V_40 |
V_41 ) ) ) {
V_31 -> V_29 = V_34 [ V_33 - 1 ] . V_42 >> 32 ;
V_31 -> V_30 = V_34 [ V_33 - 1 ] . V_43 >> 32 ;
return;
}
}
V_31 -> V_29 = V_34 [ V_33 ] . V_42 |
( V_34 [ V_33 ] . V_10 & V_44 ) ;
V_31 -> V_30 = F_23 ( & V_34 [ V_33 ] ) ;
}
static void * F_24 ( struct V_1 * V_2 , int V_3 )
{
struct V_22 * V_23 = F_25 ( sizeof( * V_23 ) , V_45 ) ;
if ( ! V_23 )
return F_26 ( - V_46 ) ;
F_22 ( V_2 , V_23 , V_3 , ~ 0 ) ;
V_23 -> V_27 = 0 ;
return V_23 ;
}
static void * F_27 ( struct V_1 * V_2 , int V_3 )
{
struct V_22 * V_23 = F_25 ( sizeof( * V_23 ) , V_45 ) ;
if ( ! V_23 )
return F_26 ( - V_46 ) ;
F_22 ( V_2 , V_23 , V_3 , ~ V_26 ) ;
V_23 -> V_27 = 0 ;
return V_23 ;
}
static void F_28 ( struct V_1 * V_2 , int V_3 , void * V_5 )
{
struct V_22 * V_23 = V_5 ;
V_23 -> V_27 = 0 ;
}
static void F_29 ( struct V_1 * V_2 , int V_3 , void * V_5 )
{
F_30 ( V_5 ) ;
}
static int F_31 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_4 , void * V_5 )
{
* V_4 = V_2 -> V_47 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_4 , void * V_5 )
{
* V_4 = V_2 -> V_48 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_3 , T_3 * V_4 ,
void * V_5 )
{
* V_4 = ( T_3 ) V_2 -> V_49 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_3 , T_3 V_4 , void * V_5 )
{
T_3 V_50 ;
int V_17 ;
V_17 = F_35 ( V_2 , V_3 , & V_50 ) ;
if ( V_17 )
goto V_51;
if ( ( V_50 & ~ V_52 ) == ( V_4 & ~ V_52 )
|| V_4 == V_52 )
V_17 = F_36 ( V_2 , V_3 , V_4 ) ;
V_51:
return V_17 ;
}
int F_37 ( struct V_1 * V_2 )
{
int V_17 ;
V_17 = F_38 ( V_2 , V_53 ) ;
if ( V_17 )
goto V_51;
switch ( V_2 -> V_54 ) {
case V_55 :
V_17 = F_38 ( V_2 , V_56 ) ;
break;
case V_57 :
V_17 = F_38 ( V_2 , V_58 ) ;
break;
default:
V_17 = - V_59 ;
F_39 ( L_7 ,
F_15 ( V_2 ) , V_2 -> V_54 ) ;
break;
}
V_51:
return V_17 ;
}
