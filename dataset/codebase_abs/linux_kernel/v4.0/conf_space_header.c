static void * F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
int V_7 ;
if ( ! V_5 )
return F_3 ( - V_8 ) ;
V_7 = F_4 ( V_2 , V_9 , & V_5 -> V_10 ) ;
if ( V_7 ) {
F_5 ( V_5 ) ;
return F_3 ( V_7 ) ;
}
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 , T_1 * V_11 , void * V_12 )
{
int V_13 = F_4 ( V_2 , V_3 , V_11 ) ;
const struct V_4 * V_5 = V_12 ;
* V_11 &= V_14 ;
* V_11 |= V_5 -> V_10 & ~ V_14 ;
return V_13 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 , T_1 V_11 , void * V_12 )
{
struct V_15 * V_16 ;
int V_7 ;
T_1 V_10 ;
struct V_4 * V_5 = V_12 ;
V_16 = F_8 ( V_2 ) ;
if ( ! F_9 ( V_2 ) && F_10 ( V_11 ) ) {
if ( F_11 ( V_17 ) )
F_12 (KERN_DEBUG DRV_NAME L_1 ,
pci_name(dev)) ;
V_7 = F_13 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_16 )
V_16 -> V_18 = 1 ;
} else if ( F_9 ( V_2 ) && ! F_10 ( V_11 ) ) {
if ( F_11 ( V_17 ) )
F_12 (KERN_DEBUG DRV_NAME L_2 ,
pci_name(dev)) ;
F_14 ( V_2 ) ;
if ( V_16 )
V_16 -> V_18 = 0 ;
}
if ( ! V_2 -> V_19 && F_15 ( V_11 ) ) {
if ( F_11 ( V_17 ) )
F_12 (KERN_DEBUG DRV_NAME L_3 ,
pci_name(dev)) ;
F_16 ( V_2 ) ;
}
if ( V_11 & V_20 ) {
if ( F_11 ( V_17 ) )
F_12 (KERN_DEBUG
DRV_NAME L_4 ,
pci_name(dev)) ;
V_7 = F_17 ( V_2 ) ;
if ( V_7 ) {
F_18 ( L_5 ,
F_19 ( V_2 ) , V_7 ) ;
V_11 &= ~ V_20 ;
}
}
V_5 -> V_10 = V_11 ;
if ( ! V_21 && ( ! V_16 || ! V_16 -> V_21 ) )
return 0 ;
V_7 = F_4 ( V_2 , V_3 , & V_10 ) ;
if ( V_7 || V_10 == V_11 )
return V_7 ;
V_11 &= V_14 ;
V_11 |= V_10 & ~ V_14 ;
return F_20 ( V_2 , V_3 , V_11 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_3 , T_2 V_11 , void * V_12 )
{
struct V_22 * V_23 = V_12 ;
if ( F_11 ( ! V_23 ) ) {
F_18 ( V_24 L_6 ,
F_19 ( V_2 ) ) ;
return V_25 ;
}
if ( V_11 == ~ V_26 )
V_23 -> V_27 = 1 ;
else {
T_2 V_28 ;
F_22 ( V_2 , V_3 , & V_28 ) ;
if ( V_28 != V_23 -> V_10 && V_11 == V_23 -> V_10 ) {
F_23 ( V_2 , V_3 , V_23 -> V_10 ) ;
}
V_23 -> V_27 = 0 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_3 , T_2 V_11 , void * V_12 )
{
struct V_22 * V_23 = V_12 ;
if ( F_11 ( ! V_23 ) ) {
F_18 ( V_24 L_6 ,
F_19 ( V_2 ) ) ;
return V_25 ;
}
if ( V_11 == ~ 0 )
V_23 -> V_27 = 1 ;
else {
T_2 V_28 ;
F_22 ( V_2 , V_3 , & V_28 ) ;
if ( V_28 != V_23 -> V_10 && V_11 == V_23 -> V_10 ) {
F_23 ( V_2 , V_3 , V_23 -> V_10 ) ;
}
V_23 -> V_27 = 0 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , int V_3 , T_2 * V_11 , void * V_12 )
{
struct V_22 * V_23 = V_12 ;
if ( F_11 ( ! V_23 ) ) {
F_18 ( V_24 L_6 ,
F_19 ( V_2 ) ) ;
return V_25 ;
}
* V_11 = V_23 -> V_27 ? V_23 -> V_29 : V_23 -> V_10 ;
return 0 ;
}
static inline void F_26 ( struct V_1 * V_2 ,
struct V_22 * V_30 , int V_3 ,
T_2 V_31 )
{
int V_32 ;
struct V_33 * V_34 = V_2 -> V_33 ;
if ( V_3 == V_35 || V_3 == V_36 )
V_32 = V_37 ;
else {
V_32 = ( V_3 - V_38 ) / 4 ;
if ( V_32 && ( ( V_34 [ V_32 - 1 ] . V_39 & ( V_40 |
V_41 ) ) ==
( V_42 |
V_43 ) ) ) {
V_30 -> V_10 = V_34 [ V_32 - 1 ] . V_44 >> 32 ;
V_30 -> V_29 = V_34 [ V_32 - 1 ] . V_45 >> 32 ;
return;
}
}
V_30 -> V_10 = V_34 [ V_32 ] . V_44 |
( V_34 [ V_32 ] . V_39 & V_46 ) ;
V_30 -> V_29 = F_27 ( & V_34 [ V_32 ] ) ;
}
static void * F_28 ( struct V_1 * V_2 , int V_3 )
{
struct V_22 * V_23 = F_2 ( sizeof( * V_23 ) , V_6 ) ;
if ( ! V_23 )
return F_3 ( - V_8 ) ;
F_26 ( V_2 , V_23 , V_3 , ~ 0 ) ;
V_23 -> V_27 = 0 ;
return V_23 ;
}
static void * F_29 ( struct V_1 * V_2 , int V_3 )
{
struct V_22 * V_23 = F_2 ( sizeof( * V_23 ) , V_6 ) ;
if ( ! V_23 )
return F_3 ( - V_8 ) ;
F_26 ( V_2 , V_23 , V_3 , ~ V_26 ) ;
V_23 -> V_27 = 0 ;
return V_23 ;
}
static void F_30 ( struct V_1 * V_2 , int V_3 , void * V_12 )
{
struct V_22 * V_23 = V_12 ;
V_23 -> V_27 = 0 ;
}
static void F_31 ( struct V_1 * V_2 , int V_3 , void * V_12 )
{
F_5 ( V_12 ) ;
}
static int F_32 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_11 , void * V_12 )
{
* V_11 = V_2 -> V_47 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_11 , void * V_12 )
{
* V_11 = V_2 -> V_48 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_3 , T_3 * V_11 ,
void * V_12 )
{
* V_11 = ( T_3 ) V_2 -> V_49 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , int V_3 , T_3 V_11 , void * V_12 )
{
T_3 V_50 ;
int V_7 ;
V_7 = F_36 ( V_2 , V_3 , & V_50 ) ;
if ( V_7 )
goto V_51;
if ( ( V_50 & ~ V_52 ) == ( V_11 & ~ V_52 )
|| V_11 == V_52 )
V_7 = F_37 ( V_2 , V_3 , V_11 ) ;
V_51:
return V_7 ;
}
int F_38 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_39 ( V_2 , V_53 ) ;
if ( V_7 )
goto V_51;
switch ( V_2 -> V_54 ) {
case V_55 :
V_7 = F_39 ( V_2 , V_56 ) ;
break;
case V_57 :
V_7 = F_39 ( V_2 , V_58 ) ;
break;
default:
V_7 = - V_59 ;
F_40 ( L_7 ,
F_19 ( V_2 ) , V_2 -> V_54 ) ;
break;
}
V_51:
return V_7 ;
}
