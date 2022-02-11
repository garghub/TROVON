static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
int V_7 = 0 ;
V_5 = F_2 ( V_2 ) ;
if ( ! V_5 )
return;
if ( V_2 -> V_8 != V_9 )
return;
if ( V_3 ) {
V_5 -> V_10 = 0 ;
V_5 -> V_11 = 0 ;
}
V_7 = V_5 -> V_10 ;
if ( ! V_7 && ! V_5 -> V_12 )
return;
if ( V_7 )
V_5 -> V_13 = V_2 -> V_13 ;
if ( V_5 -> V_13 == 0 )
goto V_14;
F_3 ( & V_2 -> V_2 , L_1 ,
V_5 -> V_15 ,
V_5 -> V_13 ,
F_4 ( V_2 ) ? L_2 : L_3 ,
V_2 -> V_16 ? L_4 : L_5 ,
V_2 -> V_17 ? L_6 : L_5 ,
V_5 -> V_12 ? L_7 : L_8 ,
V_7 ? L_7 : L_8 ) ;
if ( V_7 ) {
V_6 = F_5 ( V_5 -> V_13 ,
V_18 , V_19 ,
V_5 -> V_15 , V_2 ) ;
if ( V_6 ) {
F_6 ( & V_2 -> V_2 , L_9 \
L_10 ,
V_5 -> V_15 , V_5 -> V_13 , V_6 ) ;
goto V_14;
}
} else {
F_7 ( V_5 -> V_13 , V_2 ) ;
V_5 -> V_13 = 0 ;
}
V_5 -> V_12 = V_7 ;
V_5 -> V_11 = V_7 ;
V_14:
F_3 ( & V_2 -> V_2 , L_11 ,
V_5 -> V_15 ,
V_5 -> V_13 ,
F_4 ( V_2 ) ? L_2 : L_3 ,
V_2 -> V_16 ? L_4 : L_5 ,
V_2 -> V_17 ? L_6 : L_5 ,
V_7 ? ( V_5 -> V_12 ? L_12 : L_13 ) :
( V_5 -> V_12 ? L_14 : L_15 ) ) ;
}
void F_8 ( struct V_1 * V_2 )
{
T_1 V_20 ;
F_1 ( V_2 , 1 ) ;
if ( V_2 -> V_8 == V_9 ) {
#ifdef F_9
if ( V_2 -> V_17 )
F_10 ( V_2 ) ;
if ( V_2 -> V_16 )
F_11 ( V_2 ) ;
#endif
F_12 ( V_2 ) ;
F_13 ( V_2 , V_21 , 0 ) ;
V_2 -> V_22 = 0 ;
} else {
F_14 ( V_2 , V_21 , & V_20 ) ;
if ( V_20 & ( V_23 ) ) {
V_20 &= ~ ( V_23 ) ;
F_13 ( V_2 , V_21 , V_20 ) ;
V_2 -> V_22 = 0 ;
}
}
}
static
int F_15 ( struct V_24 * V_25 ,
struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_4 * V_5 ;
int V_28 = V_25 -> V_29 -> V_30 ;
int V_31 ;
if ( F_16 ( V_32 ) )
F_17 (KERN_DEBUG DRV_NAME L_16 , pci_name(dev)) ;
V_31 = F_18 ( V_2 ) ;
if ( V_31 ) {
F_17 ( V_33 L_17 ,
V_28 , V_31 ) ;
V_27 -> V_34 = 0 ;
return V_35 ;
}
V_27 -> V_34 = V_2 -> V_13 ? F_19 ( V_2 -> V_13 ) : 0 ;
if ( F_16 ( V_32 ) )
F_17 (KERN_DEBUG DRV_NAME L_18 , pci_name(dev),
op->value) ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_5 -> V_11 = 0 ;
return 0 ;
}
static
int F_20 ( struct V_24 * V_25 ,
struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_4 * V_5 ;
if ( F_16 ( V_32 ) )
F_17 (KERN_DEBUG DRV_NAME L_19 ,
pci_name(dev)) ;
F_11 ( V_2 ) ;
V_27 -> V_34 = V_2 -> V_13 ? F_19 ( V_2 -> V_13 ) : 0 ;
if ( F_16 ( V_32 ) )
F_17 (KERN_DEBUG DRV_NAME L_18 , pci_name(dev),
op->value) ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_5 -> V_11 = 1 ;
return 0 ;
}
static
int F_21 ( struct V_24 * V_25 ,
struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_4 * V_5 ;
int V_36 , V_37 ;
struct V_38 * V_39 ;
if ( F_16 ( V_32 ) )
F_17 (KERN_DEBUG DRV_NAME L_20 ,
pci_name(dev)) ;
if ( V_27 -> V_34 > V_40 )
return - V_41 ;
V_39 = F_22 ( V_27 -> V_34 * sizeof( * V_39 ) , V_42 ) ;
if ( V_39 == NULL )
return - V_43 ;
for ( V_36 = 0 ; V_36 < V_27 -> V_34 ; V_36 ++ ) {
V_39 [ V_36 ] . V_44 = V_27 -> V_45 [ V_36 ] . V_44 ;
V_39 [ V_36 ] . V_46 = V_27 -> V_45 [ V_36 ] . V_46 ;
}
V_37 = F_23 ( V_2 , V_39 , V_27 -> V_34 ) ;
if ( V_37 == 0 ) {
for ( V_36 = 0 ; V_36 < V_27 -> V_34 ; V_36 ++ ) {
V_27 -> V_45 [ V_36 ] . V_44 = V_39 [ V_36 ] . V_44 ;
if ( V_39 [ V_36 ] . V_46 )
V_27 -> V_45 [ V_36 ] . V_46 =
F_19 ( V_39 [ V_36 ] . V_46 ) ;
if ( F_16 ( V_32 ) )
F_17 (KERN_DEBUG DRV_NAME L_21 \
L_22 ,
pci_name(dev), i,
op->msix_entries[i].vector) ;
}
} else {
F_17 (KERN_WARNING DRV_NAME L_23 ,
pci_name(dev), result) ;
}
F_24 ( V_39 ) ;
V_27 -> V_34 = V_37 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_5 -> V_11 = 0 ;
return V_37 > 0 ? 0 : V_37 ;
}
static
int F_25 ( struct V_24 * V_25 ,
struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_4 * V_5 ;
if ( F_16 ( V_32 ) )
F_17 (KERN_DEBUG DRV_NAME L_24 ,
pci_name(dev)) ;
F_10 ( V_2 ) ;
V_27 -> V_34 = V_2 -> V_13 ? F_19 ( V_2 -> V_13 ) : 0 ;
if ( F_16 ( V_32 ) )
F_17 (KERN_DEBUG DRV_NAME L_25 , pci_name(dev),
op->value) ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_5 -> V_11 = 1 ;
return 0 ;
}
void F_26 ( struct V_24 * V_25 )
{
if ( F_27 ( V_47 , ( unsigned long * ) & V_25 -> V_48 -> V_49 )
&& ! F_28 ( V_50 , & V_25 -> V_49 ) ) {
F_29 ( V_51 , & V_25 -> V_52 ) ;
}
if ( ! F_27 ( V_53 , ( unsigned long * ) & V_25 -> V_48 -> V_49 )
&& F_27 ( V_54 , & V_25 -> V_49 ) ) {
F_30 ( & V_55 ) ;
}
}
void F_31 ( struct V_56 * V_57 )
{
struct V_24 * V_25 =
F_32 ( V_57 , struct V_24 , V_52 ) ;
struct V_1 * V_2 ;
struct V_4 * V_5 = NULL ;
struct V_26 * V_27 = & V_25 -> V_48 -> V_27 ;
int V_58 = 0 ;
V_2 = F_33 ( V_25 , V_27 -> V_59 , V_27 -> V_60 , V_27 -> V_61 ) ;
if ( V_2 == NULL )
V_27 -> V_62 = V_63 ;
else {
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_58 = V_5 -> V_10 ;
switch ( V_27 -> V_20 ) {
case V_64 :
V_27 -> V_62 = F_34 ( V_2 ,
V_27 -> V_65 , V_27 -> V_66 , & V_27 -> V_34 ) ;
break;
case V_67 :
V_27 -> V_62 = F_35 ( V_2 ,
V_27 -> V_65 , V_27 -> V_66 , V_27 -> V_34 ) ;
break;
#ifdef F_9
case V_68 :
V_27 -> V_62 = F_15 ( V_25 , V_2 , V_27 ) ;
break;
case V_69 :
V_27 -> V_62 = F_20 ( V_25 , V_2 , V_27 ) ;
break;
case V_70 :
V_27 -> V_62 = F_21 ( V_25 , V_2 , V_27 ) ;
break;
case V_71 :
V_27 -> V_62 = F_25 ( V_25 , V_2 , V_27 ) ;
break;
#endif
default:
V_27 -> V_62 = V_72 ;
break;
}
}
if ( ! V_27 -> V_62 && V_2 && V_5 ) {
if ( ( V_5 -> V_10 != V_58 ) )
F_1 ( V_2 , 0 ) ;
}
F_36 () ;
F_37 ( V_47 , ( unsigned long * ) & V_25 -> V_48 -> V_49 ) ;
F_38 ( V_25 -> V_73 ) ;
F_39 () ;
F_37 ( V_50 , & V_25 -> V_49 ) ;
F_40 () ;
F_26 ( V_25 ) ;
}
T_2 F_41 ( int V_13 , void * V_74 )
{
struct V_24 * V_25 = V_74 ;
F_26 ( V_25 ) ;
return V_75 ;
}
static T_2 V_18 ( int V_13 , void * V_74 )
{
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_12 && V_5 -> V_11 ) {
V_5 -> V_76 ++ ;
if ( ( V_5 -> V_76 % 1000 ) == 0 ) {
if ( F_42 ( V_13 ) ) {
F_17 ( V_77 L_26
L_27 ,
V_5 -> V_15 ) ;
V_5 -> V_11 = 0 ;
}
}
return V_75 ;
}
return V_78 ;
}
