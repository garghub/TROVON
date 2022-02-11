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
} else if ( V_2 -> V_19 && ! F_15 ( V_11 ) ) {
if ( F_11 ( V_17 ) )
F_12 (KERN_DEBUG DRV_NAME L_4 ,
pci_name(dev)) ;
F_17 ( V_2 ) ;
}
if ( ! ( V_5 -> V_10 & V_20 ) &&
( V_11 & V_20 ) ) {
if ( F_11 ( V_17 ) )
F_12 (KERN_DEBUG
DRV_NAME L_5 ,
pci_name(dev)) ;
V_7 = F_18 ( V_2 ) ;
if ( V_7 ) {
F_19 ( L_6 ,
F_20 ( V_2 ) , V_7 ) ;
V_11 &= ~ V_20 ;
}
} else if ( ( V_5 -> V_10 & V_20 ) &&
! ( V_11 & V_20 ) ) {
if ( F_11 ( V_17 ) )
F_12 (KERN_DEBUG
DRV_NAME L_7 ,
pci_name(dev)) ;
F_21 ( V_2 ) ;
}
V_5 -> V_10 = V_11 ;
if ( ! V_21 && ( ! V_16 || ! V_16 -> V_22 ) )
return 0 ;
V_7 = F_4 ( V_2 , V_3 , & V_10 ) ;
if ( V_7 || V_10 == V_11 )
return V_7 ;
V_11 &= V_14 ;
V_11 |= V_10 & ~ V_14 ;
return F_22 ( V_2 , V_3 , V_11 ) ;
}
static int F_23 ( struct V_1 * V_2 , int V_3 , T_2 V_11 , void * V_12 )
{
struct V_23 * V_24 = V_12 ;
if ( F_11 ( ! V_24 ) ) {
F_19 ( V_25 L_8 ,
F_20 ( V_2 ) ) ;
return V_26 ;
}
if ( V_11 == ~ V_27 )
V_24 -> V_28 = 1 ;
else {
T_2 V_29 ;
F_24 ( V_2 , V_3 , & V_29 ) ;
if ( V_29 != V_24 -> V_10 && V_11 == V_24 -> V_10 ) {
F_25 ( V_2 , V_3 , V_24 -> V_10 ) ;
}
V_24 -> V_28 = 0 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , int V_3 , T_2 V_11 , void * V_12 )
{
struct V_23 * V_24 = V_12 ;
if ( F_11 ( ! V_24 ) ) {
F_19 ( V_25 L_8 ,
F_20 ( V_2 ) ) ;
return V_26 ;
}
if ( V_11 == ~ 0 )
V_24 -> V_28 = 1 ;
else {
T_2 V_29 ;
F_24 ( V_2 , V_3 , & V_29 ) ;
if ( V_29 != V_24 -> V_10 && V_11 == V_24 -> V_10 ) {
F_25 ( V_2 , V_3 , V_24 -> V_10 ) ;
}
V_24 -> V_28 = 0 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , int V_3 , T_2 * V_11 , void * V_12 )
{
struct V_23 * V_24 = V_12 ;
if ( F_11 ( ! V_24 ) ) {
F_19 ( V_25 L_8 ,
F_20 ( V_2 ) ) ;
return V_26 ;
}
* V_11 = V_24 -> V_28 ? V_24 -> V_30 : V_24 -> V_10 ;
return 0 ;
}
static inline void F_28 ( struct V_1 * V_2 ,
struct V_23 * V_31 , int V_3 ,
T_2 V_32 )
{
int V_33 ;
struct V_34 * V_35 = V_2 -> V_34 ;
if ( V_3 == V_36 || V_3 == V_37 )
V_33 = V_38 ;
else {
V_33 = ( V_3 - V_39 ) / 4 ;
if ( V_33 && ( ( V_35 [ V_33 - 1 ] . V_40 & ( V_41 |
V_42 ) ) ==
( V_43 |
V_44 ) ) ) {
V_31 -> V_10 = V_35 [ V_33 - 1 ] . V_45 >> 32 ;
V_31 -> V_30 = V_35 [ V_33 - 1 ] . V_46 >> 32 ;
return;
}
}
V_31 -> V_10 = V_35 [ V_33 ] . V_45 |
( V_35 [ V_33 ] . V_40 & V_47 ) ;
V_31 -> V_30 = F_29 ( & V_35 [ V_33 ] ) ;
}
static void * F_30 ( struct V_1 * V_2 , int V_3 )
{
struct V_23 * V_24 = F_2 ( sizeof( * V_24 ) , V_6 ) ;
if ( ! V_24 )
return F_3 ( - V_8 ) ;
F_28 ( V_2 , V_24 , V_3 , ~ 0 ) ;
V_24 -> V_28 = 0 ;
return V_24 ;
}
static void * F_31 ( struct V_1 * V_2 , int V_3 )
{
struct V_23 * V_24 = F_2 ( sizeof( * V_24 ) , V_6 ) ;
if ( ! V_24 )
return F_3 ( - V_8 ) ;
F_28 ( V_2 , V_24 , V_3 , ~ V_27 ) ;
V_24 -> V_28 = 0 ;
return V_24 ;
}
static void F_32 ( struct V_1 * V_2 , int V_3 , void * V_12 )
{
struct V_23 * V_24 = V_12 ;
V_24 -> V_28 = 0 ;
}
static void F_33 ( struct V_1 * V_2 , int V_3 , void * V_12 )
{
F_5 ( V_12 ) ;
}
static int F_34 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_11 , void * V_12 )
{
* V_11 = V_2 -> V_48 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_11 , void * V_12 )
{
* V_11 = V_2 -> V_49 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , int V_3 , T_3 * V_11 ,
void * V_12 )
{
* V_11 = ( T_3 ) V_2 -> V_50 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , int V_3 , T_3 V_11 , void * V_12 )
{
T_3 V_51 ;
int V_7 ;
V_7 = F_38 ( V_2 , V_3 , & V_51 ) ;
if ( V_7 )
goto V_52;
if ( ( V_51 & ~ V_53 ) == ( V_11 & ~ V_53 )
|| V_11 == V_53 )
V_7 = F_39 ( V_2 , V_3 , V_11 ) ;
V_52:
return V_7 ;
}
int F_40 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_41 ( V_2 , V_54 ) ;
if ( V_7 )
goto V_52;
switch ( V_2 -> V_55 ) {
case V_56 :
V_7 = F_41 ( V_2 , V_57 ) ;
break;
case V_58 :
V_7 = F_41 ( V_2 , V_59 ) ;
break;
default:
V_7 = - V_60 ;
F_42 ( L_9 ,
F_20 ( V_2 ) , V_2 -> V_55 ) ;
break;
}
V_52:
return V_7 ;
}
