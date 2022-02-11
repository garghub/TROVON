static void F_1 ( T_1 * V_1 , unsigned int V_2 )
{
T_2 * V_3 = V_1 -> V_3 ;
T_3 V_4 = 0 ;
unsigned long V_5 ;
V_4 = V_2 ? ( 0x21 | 0x82 ) : ( 0x21 & ~ 0x82 ) ;
F_2 ( V_5 ) ;
if ( V_4 != V_3 -> V_6 ) {
V_3 -> V_6 = V_4 ;
F_3 ( 0x51 | ( V_3 -> V_7 << 3 ) , V_3 -> V_8 + 1 ) ;
F_4 ( V_4 & 0xff , V_3 -> V_8 ) ;
}
if ( V_1 -> V_9 & V_10 ) {
V_4 = F_5 ( V_3 -> V_8 + 3 ) ;
V_4 &= 0x13 ;
V_4 &= ~ ( 1 << V_3 -> V_7 ) ;
F_4 ( V_4 , V_3 -> V_8 + 3 ) ;
}
F_6 ( V_5 ) ;
}
static void F_7 ( T_1 * V_1 )
{
F_1 ( V_1 , ! ! ( V_1 -> V_9 & V_11 ) ) ;
F_3 ( V_1 -> V_12 | V_13 , V_1 -> V_3 -> V_14 . V_15 ) ;
}
static int F_8 ( T_1 * V_1 , struct V_16 * V_17 )
{
if ( V_17 -> V_18 & V_19 ) {
#ifdef F_9
return 1 ;
#endif
}
return 0 ;
}
static int F_10 ( T_1 * V_1 , struct V_16 * V_17 )
{
T_2 * V_3 = V_1 -> V_3 ;
unsigned int V_20 , V_21 = ( V_17 -> V_18 & V_19 ) ? 1 : 2 ;
V_20 = F_11 ( V_1 , V_17 ) ;
if ( V_20 == 0 )
return 1 ;
F_12 ( V_3 -> V_22 | V_21 , V_3 -> V_23 ) ;
F_4 ( V_20 * 2 - 1 , V_3 -> V_23 + 2 ) ;
return 0 ;
}
static void F_13 ( T_1 * V_1 )
{
F_1 ( V_1 , 1 ) ;
}
static int F_14 ( T_1 * V_1 )
{
T_3 V_24 = F_5 ( V_1 -> V_3 -> V_23 + 2 ) ;
F_1 ( V_1 , 0 ) ;
return V_24 != 0x00ff ;
}
static int F_15 ( T_1 * V_1 )
{
T_3 V_24 = F_5 ( V_1 -> V_3 -> V_23 + 2 ) ;
return V_24 == 0x00ff ;
}
static void F_16 ( T_1 * V_1 , int V_25 )
{
}
static void F_17 ( T_2 * V_3 )
{
struct V_26 * V_27 = F_18 ( V_3 -> V_27 ) ;
unsigned int V_28 = F_19 ( V_27 , 4 ) ;
unsigned long V_5 ;
T_4 V_4 = 0 ;
if ( ( V_27 -> V_29 & 5 ) && V_28 )
F_20 (KERN_INFO DRV_NAME L_1 , pci_name(dev)) ;
else {
V_28 = 0x3df0 ;
F_20 (KERN_INFO DRV_NAME L_2 , pci_name(dev)) ;
}
F_20 ( V_30 L_3 , V_28 ) ;
V_3 -> V_8 = V_28 ;
V_3 -> V_23 = ( V_28 + 4 ) ^ ( V_3 -> V_7 ? 0x80 : 0 ) ;
F_20 ( V_31 L_4 ,
V_3 -> V_32 , V_3 -> V_23 , V_3 -> V_23 + 3 ) ;
if ( F_21 ( V_3 ) )
return;
F_2 ( V_5 ) ;
F_3 ( 0x51 | ( V_3 -> V_7 << 3 ) , V_3 -> V_8 + 1 ) ;
V_3 -> V_6 = 0x21 ;
F_3 ( V_3 -> V_6 , V_3 -> V_8 ) ;
V_4 = F_22 ( V_3 -> V_8 + 3 ) ;
V_4 = ( V_4 & 0x10 ) | 0x03 ;
F_3 ( V_4 , V_3 -> V_8 + 3 ) ;
F_6 ( V_5 ) ;
if ( V_4 & 0x10 )
V_3 -> V_33 = V_3 -> V_7 ? 15 : 14 ;
#if 1
{
T_3 V_34 , V_35 , V_36 = V_3 -> V_7 ? 0x374 : 0x3f4 ;
static T_3 V_37 = 0 ;
T_4 V_38 ;
F_3 ( 0x54 | ( V_3 -> V_7 << 3 ) , V_3 -> V_8 + 1 ) ;
V_35 = F_5 ( V_3 -> V_8 ) ;
V_35 &= ~ 1 ;
V_38 = F_22 ( V_35 + 2 ) ;
if ( V_35 != V_36 && V_38 == 0xff ) {
V_36 += ( V_37 += 0x400 ) ;
V_3 -> V_14 . V_39 = V_36 + 2 ;
F_4 ( V_36 | 1 , V_3 -> V_8 ) ;
V_34 = F_5 ( V_3 -> V_8 ) ;
F_20 ( V_31 L_5
L_6 ,
V_3 -> V_32 , V_35 , V_34 & ~ 1 ) ;
}
}
#endif
}
static int F_23 ( struct V_26 * V_27 , const struct V_40 * V_41 )
{
return F_24 ( V_27 , & V_42 , NULL ) ;
}
static int T_5 F_25 ( void )
{
return F_26 ( & V_43 ) ;
}
static void T_6 F_27 ( void )
{
F_28 ( & V_43 ) ;
}
