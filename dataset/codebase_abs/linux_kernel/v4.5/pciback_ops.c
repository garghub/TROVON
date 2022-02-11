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
if ( V_2 -> V_16 || V_2 -> V_17 )
goto V_14;
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
if ( V_2 -> V_16 )
V_28 = - V_30 ;
else if ( V_2 -> V_17 )
V_28 = - V_31 ;
else
V_28 = F_18 ( V_2 ) ;
if ( V_28 ) {
F_19 ( L_17 ,
F_20 ( V_2 ) , V_25 -> V_32 -> V_33 ,
V_28 ) ;
V_27 -> V_34 = 0 ;
return V_35 ;
}
V_27 -> V_34 = V_2 -> V_13 ? F_21 ( V_2 -> V_13 ) : 0 ;
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
if ( F_16 ( V_29 ) )
F_17 (KERN_DEBUG DRV_NAME L_19 ,
pci_name(dev)) ;
if ( V_2 -> V_16 ) {
struct V_4 * V_5 ;
F_11 ( V_2 ) ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_5 -> V_11 = 1 ;
}
V_27 -> V_34 = V_2 -> V_13 ? F_21 ( V_2 -> V_13 ) : 0 ;
if ( F_16 ( V_29 ) )
F_17 (KERN_DEBUG DRV_NAME L_18 , pci_name(dev),
op->value) ;
return 0 ;
}
static
int F_23 ( struct V_24 * V_25 ,
struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_4 * V_5 ;
int V_36 , V_37 ;
struct V_38 * V_39 ;
T_1 V_20 ;
if ( F_16 ( V_29 ) )
F_17 (KERN_DEBUG DRV_NAME L_20 ,
pci_name(dev)) ;
if ( V_27 -> V_34 > V_40 )
return - V_41 ;
if ( V_2 -> V_17 )
return - V_30 ;
F_14 ( F_24 ( V_2 ) , V_21 , & V_20 ) ;
if ( V_2 -> V_16 || ! ( V_20 & V_42 ) )
return - V_31 ;
V_39 = F_25 ( V_27 -> V_34 * sizeof( * V_39 ) , V_43 ) ;
if ( V_39 == NULL )
return - V_44 ;
for ( V_36 = 0 ; V_36 < V_27 -> V_34 ; V_36 ++ ) {
V_39 [ V_36 ] . V_45 = V_27 -> V_46 [ V_36 ] . V_45 ;
V_39 [ V_36 ] . V_47 = V_27 -> V_46 [ V_36 ] . V_47 ;
}
V_37 = F_26 ( V_2 , V_39 , V_27 -> V_34 ) ;
if ( V_37 == 0 ) {
for ( V_36 = 0 ; V_36 < V_27 -> V_34 ; V_36 ++ ) {
V_27 -> V_46 [ V_36 ] . V_45 = V_39 [ V_36 ] . V_45 ;
if ( V_39 [ V_36 ] . V_47 ) {
V_27 -> V_46 [ V_36 ] . V_47 =
F_21 ( V_39 [ V_36 ] . V_47 ) ;
if ( F_16 ( V_29 ) )
F_17 (KERN_DEBUG DRV_NAME L_21 \
L_22 ,
pci_name(dev), i,
op->msix_entries[i].vector) ;
}
}
} else
F_19 ( L_23 ,
F_20 ( V_2 ) , V_25 -> V_32 -> V_33 ,
V_37 ) ;
F_27 ( V_39 ) ;
V_27 -> V_34 = V_37 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_5 -> V_11 = 0 ;
return V_37 > 0 ? 0 : V_37 ;
}
static
int F_28 ( struct V_24 * V_25 ,
struct V_1 * V_2 , struct V_26 * V_27 )
{
if ( F_16 ( V_29 ) )
F_17 (KERN_DEBUG DRV_NAME L_24 ,
pci_name(dev)) ;
if ( V_2 -> V_17 ) {
struct V_4 * V_5 ;
F_10 ( V_2 ) ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_5 -> V_11 = 1 ;
}
V_27 -> V_34 = V_2 -> V_13 ? F_21 ( V_2 -> V_13 ) : 0 ;
if ( F_16 ( V_29 ) )
F_17 (KERN_DEBUG DRV_NAME L_25 ,
pci_name(dev), op->value) ;
return 0 ;
}
void F_29 ( struct V_24 * V_25 )
{
if ( F_30 ( V_48 , ( unsigned long * ) & V_25 -> V_49 -> V_50 )
&& ! F_31 ( V_51 , & V_25 -> V_50 ) ) {
F_32 ( V_52 , & V_25 -> V_53 ) ;
}
if ( ! F_30 ( V_54 , ( unsigned long * ) & V_25 -> V_49 -> V_50 )
&& F_30 ( V_55 , & V_25 -> V_50 ) ) {
F_33 ( & V_56 ) ;
}
}
void F_34 ( struct V_57 * V_58 )
{
struct V_24 * V_25 =
F_35 ( V_58 , struct V_24 , V_53 ) ;
struct V_1 * V_2 ;
struct V_4 * V_5 = NULL ;
struct V_26 * V_27 = & V_25 -> V_27 ;
int V_59 = 0 ;
#ifdef F_9
unsigned int V_60 = 0 ;
#endif
* V_27 = V_25 -> V_49 -> V_27 ;
F_36 () ;
V_2 = F_37 ( V_25 , V_27 -> V_61 , V_27 -> V_62 , V_27 -> V_63 ) ;
if ( V_2 == NULL )
V_27 -> V_64 = V_65 ;
else {
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_59 = V_5 -> V_10 ;
switch ( V_27 -> V_20 ) {
case V_66 :
V_27 -> V_64 = F_38 ( V_2 ,
V_27 -> V_67 , V_27 -> V_68 , & V_27 -> V_34 ) ;
break;
case V_69 :
V_27 -> V_64 = F_39 ( V_2 ,
V_27 -> V_67 , V_27 -> V_68 , V_27 -> V_34 ) ;
break;
#ifdef F_9
case V_70 :
V_27 -> V_64 = F_15 ( V_25 , V_2 , V_27 ) ;
break;
case V_71 :
V_27 -> V_64 = F_22 ( V_25 , V_2 , V_27 ) ;
break;
case V_72 :
V_60 = V_27 -> V_34 ;
V_27 -> V_64 = F_23 ( V_25 , V_2 , V_27 ) ;
break;
case V_73 :
V_27 -> V_64 = F_28 ( V_25 , V_2 , V_27 ) ;
break;
#endif
default:
V_27 -> V_64 = V_74 ;
break;
}
}
if ( ! V_27 -> V_64 && V_2 && V_5 ) {
if ( ( V_5 -> V_10 != V_59 ) )
F_1 ( V_2 , 0 ) ;
}
V_25 -> V_49 -> V_27 . V_64 = V_27 -> V_64 ;
V_25 -> V_49 -> V_27 . V_34 = V_27 -> V_34 ;
#ifdef F_9
if ( V_27 -> V_20 == V_72 && V_27 -> V_64 == 0 ) {
unsigned int V_36 ;
for ( V_36 = 0 ; V_36 < V_60 ; V_36 ++ )
V_25 -> V_49 -> V_27 . V_46 [ V_36 ] . V_47 =
V_27 -> V_46 [ V_36 ] . V_47 ;
}
#endif
F_40 () ;
F_41 ( V_48 , ( unsigned long * ) & V_25 -> V_49 -> V_50 ) ;
F_42 ( V_25 -> V_75 ) ;
F_43 () ;
F_41 ( V_51 , & V_25 -> V_50 ) ;
F_44 () ;
F_29 ( V_25 ) ;
}
T_2 F_45 ( int V_13 , void * V_76 )
{
struct V_24 * V_25 = V_76 ;
F_29 ( V_25 ) ;
return V_77 ;
}
static T_2 V_18 ( int V_13 , void * V_76 )
{
struct V_1 * V_2 = (struct V_1 * ) V_76 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_12 && V_5 -> V_11 ) {
V_5 -> V_78 ++ ;
if ( ( V_5 -> V_78 % 1000 ) == 0 ) {
if ( F_46 ( V_13 ) ) {
F_47 ( L_26
L_27 ,
V_5 -> V_15 ) ;
V_5 -> V_11 = 0 ;
}
}
return V_77 ;
}
return V_79 ;
}
