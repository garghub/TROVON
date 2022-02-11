static void T_1
F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
int V_5 , V_6 ;
int * V_7 ;
int V_8 = 0 ;
for ( V_5 = V_9 , V_6 = 0 ;
V_5 <= V_3 ;
V_5 += 4 , V_6 ++ )
{
F_2 ( V_2 , V_5 , 0xffffffff ) ;
F_3 ( V_2 , V_5 , & V_4 ) ;
if ( ! V_4 )
continue;
if ( V_4 & V_10 )
{
V_4 &= V_11 ;
V_7 = & V_12 ;
F_4 ( L_1 , V_6 ) ;
}
else
{
if ( ( V_4 & V_13 ) ==
V_14 )
V_8 = 1 ;
V_4 &= V_15 ;
V_7 = & V_16 ;
F_4 ( L_2 , V_6 ) ;
}
* V_7 = ( * V_7 + V_4 ) & V_4 ;
F_2 ( V_2 , V_5 , * V_7 ) ;
if ( V_8 )
F_2 ( V_2 , ( V_5 += 4 ) , 0x00000000 ) ;
F_4 ( L_3 , ~ V_4 + 1 , * V_7 ) ;
}
}
static void T_1
F_5 ( struct V_17 * V_18 , struct V_1 * V_2 , int V_19 )
{
T_2 V_20 ;
int V_21 = 0 ;
F_6 ( V_2 , V_22 , & V_20 ) ;
if ( V_20 == 0 || V_20 > 4 )
V_20 = 1 ;
if ( V_18 -> V_23 )
V_21 = V_18 -> V_23 ( V_2 , F_7 ( V_19 ) , V_20 ) ;
if ( V_21 == - 1 )
V_21 = 0 ;
F_4 ( L_4 , V_21 , V_20 ) ;
F_8 ( V_2 , V_24 , V_21 ) ;
}
static void T_1
F_9 ( struct V_1 * V_2 , int V_25 ,
int V_26 , int * V_27 , int * V_28 )
{
F_8 ( V_2 , V_29 , V_25 ) ;
F_8 ( V_2 , V_30 , V_26 + 1 ) ;
F_8 ( V_2 , V_31 , 0xff ) ;
V_16 &= ~ ( 0x100000 - 1 ) ;
* V_28 = V_16 ;
V_12 &= ~ ( 0x1000 - 1 ) ;
* V_27 = V_12 ;
F_10 ( V_2 , V_32 ,
( ( V_16 - 1 ) & 0xfff00000 ) >> 16 ) ;
F_8 ( V_2 , V_33 ,
( ( V_12 - 1 ) & 0x0000f000 ) >> 8 ) ;
F_10 ( V_2 , V_34 ,
( ( V_12 - 1 ) & 0xffff0000 ) >> 16 ) ;
}
static void T_1
F_11 ( struct V_1 * V_2 , int V_25 , int V_26 ,
int * V_27 , int * V_28 )
{
int V_35 ;
F_8 ( V_2 , V_31 , V_26 ) ;
V_16 &= ~ ( 0x100000 - 1 ) ;
if ( * V_28 == V_16 )
V_16 -= 0x00100000 ;
F_10 ( V_2 , V_36 , V_16 >> 16 ) ;
F_10 ( V_2 , V_37 ,
( ( V_16 - 1 ) & 0xfff00000 ) >> 16 ) ;
V_16 -= 0x100000 ;
F_10 ( V_2 , V_38 ,
V_16 >> 16 ) ;
V_12 &= ~ ( 0x1000 - 1 ) ;
if ( * V_27 == V_12 )
V_12 -= 0x1000 ;
F_8 ( V_2 , V_39 ,
( V_12 & 0x0000f000 ) >> 8 ) ;
F_10 ( V_2 , V_40 ,
V_12 >> 16 ) ;
F_3 ( V_2 , V_41 , & V_35 ) ;
F_2 ( V_2 , V_41 ,
V_35 |
V_42 |
V_43 |
V_44 ) ;
}
int T_1 F_12 ( struct V_17 * V_18 , int V_25 )
{
int V_26 , V_45 , V_46 , V_35 , V_47 = 0 ;
unsigned short V_48 ;
unsigned char V_49 ;
struct V_1 * V_2 = & V_50 ;
V_50 . V_51 = & V_52 ;
V_50 . V_53 = V_18 ;
V_52 . V_54 = V_18 -> V_54 ;
if ( V_25 == V_18 -> V_55 )
{
V_12 = V_18 -> V_56 . V_57 + 1 ;
V_16 = V_18 -> V_58 [ 0 ] . V_57 + 1 ;
}
V_26 = V_25 ;
for ( V_45 = 0 ; V_45 < 0xff ; V_45 ++ )
{
if ( ( V_25 == V_18 -> V_55 ) && ( V_45 == 0 ) )
continue;
if ( F_13 ( V_45 ) && ! V_47 )
continue;
V_52 . V_59 = V_25 ;
V_50 . V_19 = V_45 ;
if ( F_6 ( V_2 , V_60 , & V_49 ) )
continue;
if ( ! F_13 ( V_45 ) )
V_47 = V_49 & 0x80 ;
F_14 ( V_2 , V_61 , & V_48 ) ;
if ( V_48 == 0xffff || V_48 == 0x0000 ) {
V_47 = 0 ;
continue;
}
F_3 ( V_2 , V_62 , & V_46 ) ;
if ( ( V_46 >> 16 ) == V_63 ) {
int V_27 , V_28 ;
F_4 ( L_5 ,
F_7 ( V_45 ) ) ;
F_1 ( V_2 , V_64 ) ;
F_9 ( V_2 , V_25 , V_26 ,
& V_27 , & V_28 ) ;
V_26 = F_12 ( V_18 , V_26 + 1 ) ;
F_11 ( V_2 , V_25 , V_26 ,
& V_27 , & V_28 ) ;
V_52 . V_59 = V_25 ;
continue;
}
#if 0
if ((pci_class >> 16) == PCI_CLASS_STORAGE_IDE) {
unsigned char prg_iface;
pci_read_config_byte(dev, PCI_CLASS_PROG, &prg_iface);
if (!(prg_iface & PCIAUTO_IDE_MODE_MASK)) {
DBG("PCI Autoconfig: Skipping legacy mode "
"IDE controller\n");
continue;
}
}
#endif
F_3 ( V_2 , V_41 , & V_35 ) ;
F_2 ( V_2 , V_41 ,
V_35 |
V_42 |
V_43 |
V_44 ) ;
F_8 ( V_2 , V_65 , 0x80 ) ;
F_4 ( L_6 ,
V_25 , F_7 ( V_45 ) , F_13 ( V_45 ) ) ;
F_1 ( V_2 , V_66 ) ;
F_5 ( V_18 , V_2 , V_45 ) ;
}
return V_26 ;
}
