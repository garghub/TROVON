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
F_8 (KERN_WARNING
DRV_NAME L_5
L_6 ,
pci_name(dev), err) ;
V_4 &= ~ V_21 ;
}
}
return F_14 ( V_2 , V_3 , V_4 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_3 , T_2 V_4 , void * V_5 )
{
struct V_22 * V_23 = V_5 ;
if ( F_7 ( ! V_23 ) ) {
F_8 (KERN_WARNING DRV_NAME L_7 ,
pci_name(dev)) ;
return V_24 ;
}
if ( V_4 == ~ V_25 )
V_23 -> V_26 = 1 ;
else {
T_2 V_27 ;
F_16 ( V_2 , V_3 , & V_27 ) ;
if ( V_27 != V_23 -> V_28 && V_4 == V_23 -> V_28 ) {
F_17 ( V_2 , V_3 , V_23 -> V_28 ) ;
}
V_23 -> V_26 = 0 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_3 , T_2 V_4 , void * V_5 )
{
struct V_22 * V_23 = V_5 ;
if ( F_7 ( ! V_23 ) ) {
F_8 (KERN_WARNING DRV_NAME L_7 ,
pci_name(dev)) ;
return V_24 ;
}
if ( V_4 == ~ 0 )
V_23 -> V_26 = 1 ;
else {
T_2 V_27 ;
F_16 ( V_2 , V_3 , & V_27 ) ;
if ( V_27 != V_23 -> V_28 && V_4 == V_23 -> V_28 ) {
F_17 ( V_2 , V_3 , V_23 -> V_28 ) ;
}
V_23 -> V_26 = 0 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 , void * V_5 )
{
struct V_22 * V_23 = V_5 ;
if ( F_7 ( ! V_23 ) ) {
F_8 (KERN_WARNING DRV_NAME L_7 ,
pci_name(dev)) ;
return V_24 ;
}
* V_4 = V_23 -> V_26 ? V_23 -> V_29 : V_23 -> V_28 ;
return 0 ;
}
static inline void F_20 ( struct V_1 * V_2 ,
struct V_22 * V_30 , int V_3 ,
T_2 V_31 )
{
int V_32 ;
struct V_9 * V_33 = V_2 -> V_9 ;
if ( V_3 == V_34 || V_3 == V_35 )
V_32 = V_8 ;
else {
V_32 = ( V_3 - V_36 ) / 4 ;
if ( V_32 && ( ( V_33 [ V_32 - 1 ] . V_10 & ( V_37 |
V_38 ) ) ==
( V_39 |
V_40 ) ) ) {
V_30 -> V_28 = V_33 [ V_32 - 1 ] . V_41 >> 32 ;
V_30 -> V_29 = V_33 [ V_32 - 1 ] . V_42 >> 32 ;
return;
}
}
V_30 -> V_28 = V_33 [ V_32 ] . V_41 |
( V_33 [ V_32 ] . V_10 & V_43 ) ;
V_30 -> V_29 = F_21 ( & V_33 [ V_32 ] ) ;
}
static void * F_22 ( struct V_1 * V_2 , int V_3 )
{
struct V_22 * V_23 = F_23 ( sizeof( * V_23 ) , V_44 ) ;
if ( ! V_23 )
return F_24 ( - V_45 ) ;
F_20 ( V_2 , V_23 , V_3 , ~ 0 ) ;
V_23 -> V_26 = 0 ;
return V_23 ;
}
static void * F_25 ( struct V_1 * V_2 , int V_3 )
{
struct V_22 * V_23 = F_23 ( sizeof( * V_23 ) , V_44 ) ;
if ( ! V_23 )
return F_24 ( - V_45 ) ;
F_20 ( V_2 , V_23 , V_3 , ~ V_25 ) ;
V_23 -> V_26 = 0 ;
return V_23 ;
}
static void F_26 ( struct V_1 * V_2 , int V_3 , void * V_5 )
{
struct V_22 * V_23 = V_5 ;
V_23 -> V_26 = 0 ;
}
static void F_27 ( struct V_1 * V_2 , int V_3 , void * V_5 )
{
F_28 ( V_5 ) ;
}
static int F_29 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_4 , void * V_5 )
{
* V_4 = V_2 -> V_46 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_4 , void * V_5 )
{
* V_4 = V_2 -> V_47 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , int V_3 , T_3 * V_4 ,
void * V_5 )
{
* V_4 = ( T_3 ) V_2 -> V_48 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , int V_3 , T_3 V_4 , void * V_5 )
{
T_3 V_49 ;
int V_17 ;
V_17 = F_33 ( V_2 , V_3 , & V_49 ) ;
if ( V_17 )
goto V_50;
if ( ( V_49 & ~ V_51 ) == ( V_4 & ~ V_51 )
|| V_4 == V_51 )
V_17 = F_34 ( V_2 , V_3 , V_4 ) ;
V_50:
return V_17 ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_17 ;
V_17 = F_36 ( V_2 , V_52 ) ;
if ( V_17 )
goto V_50;
switch ( V_2 -> V_53 ) {
case V_54 :
V_17 = F_36 ( V_2 , V_55 ) ;
break;
case V_56 :
V_17 = F_36 ( V_2 , V_57 ) ;
break;
default:
V_17 = - V_58 ;
F_8 (KERN_ERR DRV_NAME L_8 ,
pci_name(dev), dev->hdr_type) ;
break;
}
V_50:
return V_17 ;
}
