static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 , void * V_5 )
{
int V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( ! F_3 ( & V_2 -> V_8 ) )
return V_7 ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( V_2 -> V_10 [ V_6 ] . V_11 & V_12 )
* V_4 |= V_13 ;
if ( V_2 -> V_10 [ V_6 ] . V_11 & V_14 )
* V_4 |= V_15 ;
}
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , void * V_5 )
{
struct V_16 * V_17 ;
int V_18 ;
V_17 = F_5 ( V_2 ) ;
if ( ! F_6 ( V_2 ) && F_7 ( V_4 ) ) {
if ( F_8 ( V_19 ) )
F_9 (KERN_DEBUG DRV_NAME L_1 ,
pci_name(dev)) ;
V_18 = F_10 ( V_2 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 )
V_17 -> V_20 = 1 ;
} else if ( F_6 ( V_2 ) && ! F_7 ( V_4 ) ) {
if ( F_8 ( V_19 ) )
F_9 (KERN_DEBUG DRV_NAME L_2 ,
pci_name(dev)) ;
F_11 ( V_2 ) ;
if ( V_17 )
V_17 -> V_20 = 0 ;
}
if ( ! V_2 -> V_21 && F_12 ( V_4 ) ) {
if ( F_8 ( V_19 ) )
F_9 (KERN_DEBUG DRV_NAME L_3 ,
pci_name(dev)) ;
F_13 ( V_2 ) ;
}
if ( V_4 & V_22 ) {
if ( F_8 ( V_19 ) )
F_9 (KERN_DEBUG
DRV_NAME L_4 ,
pci_name(dev)) ;
V_18 = F_14 ( V_2 ) ;
if ( V_18 ) {
F_9 (KERN_WARNING
DRV_NAME L_5
L_6 ,
pci_name(dev), err) ;
V_4 &= ~ V_22 ;
}
}
return F_15 ( V_2 , V_3 , V_4 ) ;
}
static int F_16 ( struct V_1 * V_2 , int V_3 , T_2 V_4 , void * V_5 )
{
struct V_23 * V_24 = V_5 ;
if ( F_8 ( ! V_24 ) ) {
F_9 (KERN_WARNING DRV_NAME L_7 ,
pci_name(dev)) ;
return V_25 ;
}
if ( V_4 == ~ V_26 )
V_24 -> V_27 = 1 ;
else {
T_2 V_28 ;
F_17 ( V_2 , V_3 , & V_28 ) ;
if ( V_28 != V_24 -> V_29 && V_4 == V_24 -> V_29 ) {
F_18 ( V_2 , V_3 , V_24 -> V_29 ) ;
}
V_24 -> V_27 = 0 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_3 , T_2 V_4 , void * V_5 )
{
struct V_23 * V_24 = V_5 ;
if ( F_8 ( ! V_24 ) ) {
F_9 (KERN_WARNING DRV_NAME L_7 ,
pci_name(dev)) ;
return V_25 ;
}
if ( V_4 == ~ 0 )
V_24 -> V_27 = 1 ;
else {
T_2 V_28 ;
F_17 ( V_2 , V_3 , & V_28 ) ;
if ( V_28 != V_24 -> V_29 && V_4 == V_24 -> V_29 ) {
F_18 ( V_2 , V_3 , V_24 -> V_29 ) ;
}
V_24 -> V_27 = 0 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 , void * V_5 )
{
struct V_23 * V_24 = V_5 ;
if ( F_8 ( ! V_24 ) ) {
F_9 (KERN_WARNING DRV_NAME L_7 ,
pci_name(dev)) ;
return V_25 ;
}
* V_4 = V_24 -> V_27 ? V_24 -> V_30 : V_24 -> V_29 ;
return 0 ;
}
static inline void F_21 ( struct V_1 * V_2 ,
struct V_23 * V_31 , int V_3 ,
T_2 V_32 )
{
int V_33 ;
struct V_10 * V_34 = V_2 -> V_10 ;
if ( V_3 == V_35 || V_3 == V_36 )
V_33 = V_9 ;
else {
V_33 = ( V_3 - V_37 ) / 4 ;
if ( V_33 && ( ( V_34 [ V_33 - 1 ] . V_11 & ( V_38 |
V_39 ) ) ==
( V_40 |
V_41 ) ) ) {
V_31 -> V_29 = V_34 [ V_33 - 1 ] . V_42 >> 32 ;
V_31 -> V_30 = V_34 [ V_33 - 1 ] . V_43 >> 32 ;
return;
}
}
V_31 -> V_29 = V_34 [ V_33 ] . V_42 |
( V_34 [ V_33 ] . V_11 & V_44 ) ;
V_31 -> V_30 = V_34 [ V_33 ] . V_43 - V_34 [ V_33 ] . V_42 + 1 ;
}
static void * F_22 ( struct V_1 * V_2 , int V_3 )
{
struct V_23 * V_24 = F_23 ( sizeof( * V_24 ) , V_45 ) ;
if ( ! V_24 )
return F_24 ( - V_46 ) ;
F_21 ( V_2 , V_24 , V_3 , ~ 0 ) ;
V_24 -> V_27 = 0 ;
return V_24 ;
}
static void * F_25 ( struct V_1 * V_2 , int V_3 )
{
struct V_23 * V_24 = F_23 ( sizeof( * V_24 ) , V_45 ) ;
if ( ! V_24 )
return F_24 ( - V_46 ) ;
F_21 ( V_2 , V_24 , V_3 , ~ V_26 ) ;
V_24 -> V_27 = 0 ;
return V_24 ;
}
static void F_26 ( struct V_1 * V_2 , int V_3 , void * V_5 )
{
struct V_23 * V_24 = V_5 ;
V_24 -> V_27 = 0 ;
}
static void F_27 ( struct V_1 * V_2 , int V_3 , void * V_5 )
{
F_28 ( V_5 ) ;
}
static int F_29 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_4 , void * V_5 )
{
* V_4 = V_2 -> V_47 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_4 , void * V_5 )
{
* V_4 = V_2 -> V_48 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , int V_3 , T_3 * V_4 ,
void * V_5 )
{
* V_4 = ( T_3 ) V_2 -> V_49 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , int V_3 , T_3 V_4 , void * V_5 )
{
T_3 V_50 ;
int V_18 ;
V_18 = F_33 ( V_2 , V_3 , & V_50 ) ;
if ( V_18 )
goto V_51;
if ( ( V_50 & ~ V_52 ) == ( V_4 & ~ V_52 )
|| V_4 == V_52 )
V_18 = F_34 ( V_2 , V_3 , V_4 ) ;
V_51:
return V_18 ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_18 ;
V_18 = F_36 ( V_2 , V_53 ) ;
if ( V_18 )
goto V_51;
switch ( V_2 -> V_54 ) {
case V_55 :
V_18 = F_36 ( V_2 , V_56 ) ;
break;
case V_57 :
V_18 = F_36 ( V_2 , V_58 ) ;
break;
default:
V_18 = - V_59 ;
F_9 (KERN_ERR DRV_NAME L_8 ,
pci_name(dev), dev->hdr_type) ;
break;
}
V_51:
return V_18 ;
}
