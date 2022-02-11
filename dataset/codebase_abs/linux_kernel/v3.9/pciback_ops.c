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
if ( F_4 ( V_2 ) )
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
int V_28 ;
if ( F_16 ( V_29 ) )
F_17 (KERN_DEBUG DRV_NAME L_16 , pci_name(dev)) ;
V_28 = F_18 ( V_2 ) ;
if ( V_28 ) {
F_19 ( V_30 L_17 ,
F_20 ( V_2 ) , V_25 -> V_31 -> V_32 ,
V_28 ) ;
V_27 -> V_33 = 0 ;
return V_34 ;
}
V_27 -> V_33 = V_2 -> V_13 ? F_21 ( V_2 -> V_13 ) : 0 ;
if ( F_16 ( V_29 ) )
F_17 (KERN_DEBUG DRV_NAME L_18 , pci_name(dev),
op->value) ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_5 -> V_11 = 0 ;
return 0 ;
}
static
int F_22 ( struct V_24 * V_25 ,
struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_4 * V_5 ;
if ( F_16 ( V_29 ) )
F_17 (KERN_DEBUG DRV_NAME L_19 ,
pci_name(dev)) ;
F_11 ( V_2 ) ;
V_27 -> V_33 = V_2 -> V_13 ? F_21 ( V_2 -> V_13 ) : 0 ;
if ( F_16 ( V_29 ) )
F_17 (KERN_DEBUG DRV_NAME L_18 , pci_name(dev),
op->value) ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_5 -> V_11 = 1 ;
return 0 ;
}
static
int F_23 ( struct V_24 * V_25 ,
struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_4 * V_5 ;
int V_35 , V_36 ;
struct V_37 * V_38 ;
if ( F_16 ( V_29 ) )
F_17 (KERN_DEBUG DRV_NAME L_20 ,
pci_name(dev)) ;
if ( V_27 -> V_33 > V_39 )
return - V_40 ;
V_38 = F_24 ( V_27 -> V_33 * sizeof( * V_38 ) , V_41 ) ;
if ( V_38 == NULL )
return - V_42 ;
for ( V_35 = 0 ; V_35 < V_27 -> V_33 ; V_35 ++ ) {
V_38 [ V_35 ] . V_43 = V_27 -> V_44 [ V_35 ] . V_43 ;
V_38 [ V_35 ] . V_45 = V_27 -> V_44 [ V_35 ] . V_45 ;
}
V_36 = F_25 ( V_2 , V_38 , V_27 -> V_33 ) ;
if ( V_36 == 0 ) {
for ( V_35 = 0 ; V_35 < V_27 -> V_33 ; V_35 ++ ) {
V_27 -> V_44 [ V_35 ] . V_43 = V_38 [ V_35 ] . V_43 ;
if ( V_38 [ V_35 ] . V_45 )
V_27 -> V_44 [ V_35 ] . V_45 =
F_21 ( V_38 [ V_35 ] . V_45 ) ;
if ( F_16 ( V_29 ) )
F_17 (KERN_DEBUG DRV_NAME L_21 \
L_22 ,
pci_name(dev), i,
op->msix_entries[i].vector) ;
}
} else
F_19 ( V_30 L_23 ,
F_20 ( V_2 ) , V_25 -> V_31 -> V_32 ,
V_36 ) ;
F_26 ( V_38 ) ;
V_27 -> V_33 = V_36 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_5 -> V_11 = 0 ;
return V_36 > 0 ? 0 : V_36 ;
}
static
int F_27 ( struct V_24 * V_25 ,
struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_4 * V_5 ;
if ( F_16 ( V_29 ) )
F_17 (KERN_DEBUG DRV_NAME L_24 ,
pci_name(dev)) ;
F_10 ( V_2 ) ;
V_27 -> V_33 = V_2 -> V_13 ? F_21 ( V_2 -> V_13 ) : 0 ;
if ( F_16 ( V_29 ) )
F_17 (KERN_DEBUG DRV_NAME L_25 , pci_name(dev),
op->value) ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_5 -> V_11 = 1 ;
return 0 ;
}
void F_28 ( struct V_24 * V_25 )
{
if ( F_29 ( V_46 , ( unsigned long * ) & V_25 -> V_47 -> V_48 )
&& ! F_30 ( V_49 , & V_25 -> V_48 ) ) {
F_31 ( V_50 , & V_25 -> V_51 ) ;
}
if ( ! F_29 ( V_52 , ( unsigned long * ) & V_25 -> V_47 -> V_48 )
&& F_29 ( V_53 , & V_25 -> V_48 ) ) {
F_32 ( & V_54 ) ;
}
}
void F_33 ( struct V_55 * V_56 )
{
struct V_24 * V_25 =
F_34 ( V_56 , struct V_24 , V_51 ) ;
struct V_1 * V_2 ;
struct V_4 * V_5 = NULL ;
struct V_26 * V_27 = & V_25 -> V_47 -> V_27 ;
int V_57 = 0 ;
V_2 = F_35 ( V_25 , V_27 -> V_58 , V_27 -> V_59 , V_27 -> V_60 ) ;
if ( V_2 == NULL )
V_27 -> V_61 = V_62 ;
else {
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_57 = V_5 -> V_10 ;
switch ( V_27 -> V_20 ) {
case V_63 :
V_27 -> V_61 = F_36 ( V_2 ,
V_27 -> V_64 , V_27 -> V_65 , & V_27 -> V_33 ) ;
break;
case V_66 :
V_27 -> V_61 = F_37 ( V_2 ,
V_27 -> V_64 , V_27 -> V_65 , V_27 -> V_33 ) ;
break;
#ifdef F_9
case V_67 :
V_27 -> V_61 = F_15 ( V_25 , V_2 , V_27 ) ;
break;
case V_68 :
V_27 -> V_61 = F_22 ( V_25 , V_2 , V_27 ) ;
break;
case V_69 :
V_27 -> V_61 = F_23 ( V_25 , V_2 , V_27 ) ;
break;
case V_70 :
V_27 -> V_61 = F_27 ( V_25 , V_2 , V_27 ) ;
break;
#endif
default:
V_27 -> V_61 = V_71 ;
break;
}
}
if ( ! V_27 -> V_61 && V_2 && V_5 ) {
if ( ( V_5 -> V_10 != V_57 ) )
F_1 ( V_2 , 0 ) ;
}
F_38 () ;
F_39 ( V_46 , ( unsigned long * ) & V_25 -> V_47 -> V_48 ) ;
F_40 ( V_25 -> V_72 ) ;
F_41 () ;
F_39 ( V_49 , & V_25 -> V_48 ) ;
F_42 () ;
F_28 ( V_25 ) ;
}
T_2 F_43 ( int V_13 , void * V_73 )
{
struct V_24 * V_25 = V_73 ;
F_28 ( V_25 ) ;
return V_74 ;
}
static T_2 V_18 ( int V_13 , void * V_73 )
{
struct V_1 * V_2 = (struct V_1 * ) V_73 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_12 && V_5 -> V_11 ) {
V_5 -> V_75 ++ ;
if ( ( V_5 -> V_75 % 1000 ) == 0 ) {
if ( F_44 ( V_13 ) ) {
F_17 ( V_76 L_26
L_27 ,
V_5 -> V_15 ) ;
V_5 -> V_11 = 0 ;
}
}
return V_74 ;
}
return V_77 ;
}
