static T_1
F_1 ( int V_1 , void * V_2 )
{
T_2 V_3 ;
T_2 V_4 ;
F_2 ( V_5 , V_6 + 0 ) ;
V_3 = F_3 ( V_6 + 0 ) ;
if ( ( V_3 & 0x80 ) == 0 ) {
return V_7 ;
}
V_4 = V_3 & 0x0f ;
if ( V_4 == 2 || V_4 > 7 ) {
F_4 (KERN_ERR PFX L_1 ) ;
return V_8 ;
}
if ( V_4 == 7 ) {
F_2 ( V_9 , V_6 + 0 ) ;
V_3 = F_3 ( V_6 + 0 ) ;
if ( ( V_3 & 0x80 ) == 0 ) {
F_4 (KERN_WARNING PFX L_2 ) ;
return V_8 ;
}
}
F_5 ( V_4 ) ;
F_2 ( ( V_10 | V_4 ) , V_6 + 0 ) ;
return V_8 ;
}
static void
F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_15 ;
struct V_11 * V_16 = V_14 -> V_17 ;
T_3 V_18 ;
int V_19 ;
if ( V_14 -> V_20 )
return;
F_7 ( ! V_16 ) ;
F_7 ( ! V_14 -> V_21 ) ;
V_16 -> V_22 = V_14 -> V_21 -> V_22 ;
V_14 -> V_21 -> V_22 = F_8 ( V_14 -> V_21 ) ;
F_4 (KERN_INFO PFX L_3 ,
pci_name(pdev), pdev->irq) ;
F_9 ( V_16 , V_23 , & V_14 -> V_24 ) ;
V_14 -> V_24 &= ~ 1 ;
F_4 (KERN_INFO PFX L_4 , sio->sp1_base) ;
F_9 ( V_16 , V_25 , & V_14 -> V_26 ) ;
V_14 -> V_26 &= ~ 1 ;
F_4 (KERN_INFO PFX L_5 , sio->sp2_base) ;
F_9 ( V_16 , V_27 , & V_14 -> V_28 ) ;
V_14 -> V_28 &= ~ 1 ;
F_4 (KERN_INFO PFX L_6 , sio->pp_base) ;
F_9 ( V_16 , V_29 , & V_14 -> V_30 ) ;
V_14 -> V_30 &= ~ 1 ;
F_4 (KERN_INFO PFX L_7 , sio->fdc_base) ;
F_9 ( V_16 , V_31 , & V_14 -> V_32 ) ;
V_14 -> V_32 &= ~ 1 ;
F_4 (KERN_INFO PFX L_8 , sio->acpi_base) ;
F_10 ( V_6 , 0x1f , L_9 ) ;
F_10 ( V_33 , 0x1f , L_10 ) ;
F_10 ( V_14 -> V_32 , 0x1f , L_11 ) ;
F_11 ( V_16 , V_34 , & V_18 ) ;
V_18 |= V_35 | V_36 | V_37 ;
F_12 ( V_16 , V_34 , V_18 ) ;
F_13 ( V_16 ) ;
V_19 = F_14 ( V_16 ) ;
F_7 ( V_19 < 0 ) ;
F_15 ( V_16 , 0x64 , 0x82000000U ) ;
F_15 ( V_16 , V_38 , 0x07654300U ) ;
F_15 ( V_16 , V_39 , 0x00001000U ) ;
F_15 ( V_16 , V_40 , 0x4c880000U ) ;
F_2 ( 0x11 , V_6 + 0 ) ;
F_2 ( 0x00 , V_6 + 1 ) ;
F_2 ( 0x04 , V_6 + 1 ) ;
F_2 ( 0x01 , V_6 + 1 ) ;
F_2 ( 0xff , V_6 + 1 ) ;
F_2 ( 0xc2 , V_6 + 0 ) ;
F_2 ( 0x11 , V_33 + 0 ) ;
F_2 ( 0x00 , V_33 + 1 ) ;
F_2 ( 0x02 , V_33 + 1 ) ;
F_2 ( 0x01 , V_33 + 1 ) ;
F_2 ( 0xff , V_6 + 1 ) ;
F_2 ( 0x68 , V_6 + 0 ) ;
F_2 ( 0xff , V_6 + 1 ) ;
F_2 ( 1 , V_14 -> V_32 + V_41 ) ;
if ( F_3 ( V_14 -> V_32 + V_41 ) & 1 )
F_4 (KERN_INFO PFX L_12 ) ;
else
F_4 (KERN_ERR PFX L_13 ) ;
if ( F_16 ( V_16 -> V_22 , F_1 , 0 ,
V_42 , ( void * ) V_14 ) ) {
F_4 (KERN_ERR PFX L_14 ) ;
F_17 () ;
return;
}
V_14 -> V_20 = 1 ;
}
static void F_18 ( struct V_43 * V_44 )
{
unsigned int V_22 = V_44 -> V_22 ;
T_2 V_45 ;
if ( ( V_22 < 1 ) || ( V_22 == 2 ) || ( V_22 > 7 ) ) {
F_4 (KERN_ERR PFX L_15 ) ;
F_17 () ;
return;
}
V_45 = F_3 ( V_6 + 1 ) ;
V_45 |= ( 1 << V_22 ) ;
F_2 ( V_45 , V_6 + 1 ) ;
}
static void F_19 ( struct V_43 * V_44 )
{
unsigned int V_22 = V_44 -> V_22 ;
T_2 V_45 ;
if ( ( V_22 < 1 ) || ( V_22 == 2 ) || ( V_22 > 7 ) ) {
F_4 (KERN_ERR PFX L_16 , irq) ;
F_17 () ;
return;
}
V_45 = F_3 ( V_6 + 1 ) ;
V_45 &= ~ ( 1 << V_22 ) ;
F_2 ( V_45 , V_6 + 1 ) ;
}
int F_8 ( struct V_11 * V_12 )
{
int V_4 , V_46 ;
#ifdef F_20
int V_47 ;
V_47 = F_21 ( V_12 -> V_48 ) ;
if ( V_49 [ V_47 ] != V_12 -> V_50 ) {
F_17 () ;
return - 1 ;
}
F_4 ( L_17 ,
F_22 ( V_12 ) ,
V_12 -> V_51 , V_12 -> V_50 ,
F_23 ( 0 ) ) ;
#endif
for ( V_46 = 0 ; V_46 < 16 ; V_46 ++ ) {
F_24 ( V_46 , & V_52 ,
V_53 ) ;
}
switch( V_12 -> V_50 ) {
case V_54 :
V_4 = V_55 ;
break;
case V_56 :
V_15 . V_17 = V_12 ;
return - 1 ;
case V_57 :
V_15 . V_21 = V_12 ;
V_4 = V_58 ;
break;
default:
V_4 = - 1 ;
F_17 () ;
break;
}
return V_4 ;
}
static void T_4 F_25 ( void )
{
#ifdef F_26
int V_59 ;
struct V_60 V_61 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_62 = V_63 ;
V_61 . type = V_64 ;
V_61 . V_65 = 115200 * 16 ;
V_61 . V_66 = 16 ;
V_61 . V_67 = V_15 . V_24 ;
V_61 . V_22 = V_68 ;
V_61 . line = 0 ;
V_59 = F_27 ( & V_61 ) ;
if ( V_59 < 0 ) {
F_4 (KERN_WARNING PFX L_18 ) ;
return;
}
V_61 . V_67 = V_15 . V_26 ;
V_61 . V_22 = V_69 ;
V_61 . line = 1 ;
V_59 = F_27 ( & V_61 ) ;
if ( V_59 < 0 )
F_4 (KERN_WARNING PFX L_19 ) ;
#endif
}
static void T_4 F_28 ( void )
{
#ifdef F_29
if ( ! F_30 ( V_15 . V_28 ,
0 ,
V_70 ,
V_71 ,
NULL ,
0 ) )
F_4 (KERN_WARNING PFX L_20 ) ;
#endif
}
static void F_31 ( struct V_11 * V_16 )
{
T_2 V_72 ;
V_16 -> V_73 |= 0x5 ;
F_32 ( V_16 , V_74 , V_16 -> V_73 ) ;
F_33 ( V_16 , V_74 , & V_72 ) ;
F_4 ( L_21 , V_72 ) ;
}
static int T_4
F_34 ( struct V_11 * V_75 , const struct V_76 * V_77 )
{
struct V_13 * V_14 = & V_15 ;
F_35 ( L_22 ,
F_22 ( V_75 ) ,
V_75 -> V_51 , V_75 -> V_50 ,
V_75 -> V_78 , V_75 -> V_79 ,
V_75 -> V_73 ) ;
F_7 ( ! V_14 -> V_20 ) ;
if ( V_75 -> V_50 == V_56 ) {
F_28 () ;
F_25 () ;
return 0 ;
} else if ( V_75 -> V_50 == V_54 ) {
F_35 ( L_23 ) ;
} else if ( V_75 -> V_50 == V_57 ) {
F_35 ( L_24 ) ;
} else {
F_35 ( L_25 ) ;
}
return - V_80 ;
}
