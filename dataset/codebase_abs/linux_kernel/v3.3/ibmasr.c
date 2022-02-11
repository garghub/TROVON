static void F_1 ( void )
{
unsigned char V_1 ;
V_1 = F_2 ( V_2 ) ;
F_3 ( V_1 & ~ V_3 , V_4 ) ;
V_1 = F_2 ( V_2 ) ;
F_3 ( V_1 | V_3 , V_4 ) ;
V_1 = F_2 ( V_2 ) ;
F_3 ( V_1 & ~ V_3 , V_4 ) ;
V_1 = F_2 ( V_2 ) ;
}
static void F_4 ( void )
{
F_5 ( & V_5 ) ;
F_1 () ;
F_6 ( & V_5 ) ;
}
static void F_7 ( void )
{
unsigned char V_1 ;
F_5 ( & V_5 ) ;
if ( V_6 == V_7 ) {
V_1 = F_2 ( V_2 ) ;
F_3 ( V_1 & ~ ( V_8 | V_9 ) ,
V_2 ) ;
} else {
F_1 () ;
V_1 = F_2 ( V_2 ) ;
F_3 ( V_1 & ~ V_10 , V_4 ) ;
}
V_1 = F_2 ( V_2 ) ;
F_6 ( & V_5 ) ;
}
static void F_8 ( void )
{
unsigned char V_1 ;
F_5 ( & V_5 ) ;
V_1 = F_2 ( V_2 ) ;
if ( V_6 == V_7 )
F_3 ( V_1 | V_8 | V_9 ,
V_2 ) ;
else {
F_3 ( V_1 | V_3 , V_4 ) ;
V_1 = F_2 ( V_2 ) ;
F_3 ( V_1 | V_10 , V_4 ) ;
}
V_1 = F_2 ( V_2 ) ;
F_6 ( & V_5 ) ;
}
static int T_1 F_9 ( void )
{
unsigned char V_11 , V_12 ;
const char * type = L_1 ;
V_13 = 1 ;
switch ( V_6 ) {
case V_7 :
F_3 ( 0x07 , 0x2e ) ;
F_3 ( 0x07 , 0x2f ) ;
F_3 ( 0x60 , 0x2e ) ;
V_12 = F_2 ( 0x2f ) ;
F_3 ( 0x61 , 0x2e ) ;
V_11 = F_2 ( 0x2f ) ;
V_14 = ( V_12 << 16 ) | V_11 ;
V_2 = V_4 =
V_14 + V_15 ;
V_13 = 5 ;
break;
case V_16 :
type = L_2 ;
#if 0
u32 r;
pdev = pci_get_bus_and_slot(0, DEVFN(0x1f, 0));
if (pdev == NULL)
return -ENODEV;
pci_read_config_dword(pdev, 0x58, &r);
asr_base = r & 0xFFFE;
pci_dev_put(pdev);
#else
F_10 ( 0x8000f858 , 0xcf8 ) ;
V_14 = F_11 ( 0xcfc ) & 0xfffe ;
#endif
V_2 = V_4 =
V_14 + V_17 ;
V_3 = V_18 ;
V_10 = V_19 ;
V_13 = V_17 + 1 ;
break;
case V_20 :
type = L_3 ;
V_14 = V_21 ;
V_2 = V_22 ;
V_4 = V_23 ;
V_3 = V_24 ;
V_10 = V_25 ;
V_13 = 4 ;
break;
case V_26 :
type = L_4 ;
V_14 = V_27 ;
V_2 = V_4 = V_14 ;
V_3 = V_28 ;
V_10 = V_29 ;
break;
case V_30 :
type = L_5 ;
V_14 = V_31 ;
V_2 = V_4 = V_14 ;
V_3 = V_32 ;
V_10 = V_33 ;
break;
}
if ( ! F_12 ( V_14 , V_13 , L_6 ) ) {
F_13 (KERN_ERR PFX L_7 ,
asr_base) ;
return - V_34 ;
}
F_13 (KERN_INFO PFX L_8 , type, asr_base) ;
return 0 ;
}
static T_2 F_14 ( struct V_35 * V_35 , const char T_3 * V_36 ,
T_4 V_37 , T_5 * V_38 )
{
if ( V_37 ) {
if ( ! V_39 ) {
T_4 V_40 ;
V_41 = 0 ;
for ( V_40 = 0 ; V_40 != V_37 ; V_40 ++ ) {
char V_42 ;
if ( F_15 ( V_42 , V_36 + V_40 ) )
return - V_43 ;
if ( V_42 == 'V' )
V_41 = 42 ;
}
}
F_4 () ;
}
return V_37 ;
}
static long F_16 ( struct V_35 * V_35 , unsigned int V_44 , unsigned long V_45 )
{
static const struct V_46 V_47 = {
. V_48 = V_49 |
V_50 ,
. V_51 = L_9 ,
} ;
void T_3 * V_52 = ( void T_3 * ) V_45 ;
int T_3 * V_53 = V_52 ;
int V_54 ;
switch ( V_44 ) {
case V_55 :
return F_17 ( V_52 , & V_47 , sizeof( V_47 ) ) ? - V_43 : 0 ;
case V_56 :
case V_57 :
return F_18 ( 0 , V_53 ) ;
case V_58 :
{
int V_59 , V_60 = - V_61 ;
if ( F_15 ( V_59 , V_53 ) )
return - V_43 ;
if ( V_59 & V_62 ) {
F_8 () ;
V_60 = 0 ;
}
if ( V_59 & V_63 ) {
F_7 () ;
F_4 () ;
V_60 = 0 ;
}
return V_60 ;
}
case V_64 :
F_4 () ;
return 0 ;
case V_65 :
V_54 = 256 ;
return F_18 ( V_54 , V_53 ) ;
default:
return - V_66 ;
}
}
static int F_19 ( struct V_67 * V_67 , struct V_35 * V_35 )
{
if ( F_20 ( 0 , & V_68 ) )
return - V_34 ;
F_4 () ;
F_7 () ;
return F_21 ( V_67 , V_35 ) ;
}
static int F_22 ( struct V_67 * V_67 , struct V_35 * V_35 )
{
if ( V_41 == 42 )
F_8 () ;
else {
F_13 (KERN_CRIT PFX
L_10 ) ;
F_4 () ;
}
F_23 ( 0 , & V_68 ) ;
V_41 = 0 ;
return 0 ;
}
static int T_1 F_24 ( void )
{
struct V_69 * V_70 ;
int V_71 ;
for ( V_70 = V_72 ; V_70 -> V_73 ; V_70 ++ ) {
if ( F_25 ( V_74 , V_70 -> V_73 , NULL ) ) {
V_6 = V_70 -> type ;
break;
}
}
if ( ! V_6 )
return - V_75 ;
V_71 = F_9 () ;
if ( V_71 )
return V_71 ;
V_71 = F_26 ( & V_76 ) ;
if ( V_71 < 0 ) {
F_27 ( V_14 , V_13 ) ;
F_13 (KERN_ERR PFX L_11 ) ;
return V_71 ;
}
return 0 ;
}
static void T_6 F_28 ( void )
{
if ( ! V_39 )
F_8 () ;
F_29 ( & V_76 ) ;
F_27 ( V_14 , V_13 ) ;
}
