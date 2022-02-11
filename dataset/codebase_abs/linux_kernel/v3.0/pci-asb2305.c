T_1 F_1 ( void * V_1 , const struct V_2 * V_3 ,
T_1 V_4 , T_1 V_5 )
{
T_1 V_6 = V_3 -> V_6 ;
#if 0
struct pci_dev *dev = data;
printk(KERN_DEBUG
"### PCIBIOS_ALIGN_RESOURCE(%s,,{%08lx-%08lx,%08lx},%lx)\n",
pci_name(dev),
res->start,
res->end,
res->flags,
size
);
#endif
if ( ( V_3 -> V_7 & V_8 ) && ( V_6 & 0x300 ) )
V_6 = ( V_6 + 0x3ff ) & ~ 0x3ff ;
return V_6 ;
}
static void T_2 F_2 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 ;
struct V_2 * V_16 ;
F_3 (bus, bus_list, node) {
V_14 = V_12 -> V_17 ;
if ( V_14 ) {
for ( V_15 = V_18 ;
V_15 < V_19 ;
V_15 ++ ) {
V_16 = & V_14 -> V_2 [ V_15 ] ;
if ( ! V_16 -> V_7 )
continue;
if ( ! V_16 -> V_6 ||
F_4 ( V_14 , V_15 ) < 0 ) {
F_5 ( V_20 L_1
L_2
L_3 ,
V_15 , F_6 ( V_14 ) ) ;
V_16 -> V_6 = V_16 -> V_21 = 0 ;
V_16 -> V_7 = 0 ;
}
}
}
F_2 ( & V_12 -> V_22 ) ;
}
}
static void T_2 F_7 ( int V_23 )
{
struct V_13 * V_14 = NULL ;
int V_15 , V_24 ;
T_3 V_25 ;
struct V_2 * V_16 ;
F_8 (dev) {
F_9 ( V_14 , V_26 , & V_25 ) ;
for ( V_15 = 0 ; V_15 < 6 ; V_15 ++ ) {
V_16 = & V_14 -> V_2 [ V_15 ] ;
if ( V_16 -> V_27 )
continue;
if ( ! V_16 -> V_6 )
continue;
if ( V_16 -> V_7 & V_8 )
V_24 = ! ( V_25 & V_28 ) ;
else
V_24 = ! ( V_25 & V_29 ) ;
if ( V_23 == V_24 ) {
F_10 ( L_4
L_5 ,
F_6 ( V_14 ) , V_16 -> V_6 , V_16 -> V_21 , V_16 -> V_7 ,
V_24 , V_23 ) ;
if ( F_4 ( V_14 , V_15 ) < 0 ) {
F_5 ( V_20 L_1
L_2
L_6 ,
V_15 , F_6 ( V_14 ) ) ;
V_16 -> V_21 -= V_16 -> V_6 ;
V_16 -> V_6 = 0 ;
}
}
}
if ( ! V_23 ) {
V_16 = & V_14 -> V_2 [ V_30 ] ;
if ( V_16 -> V_7 & V_31 ) {
T_4 V_32 ;
F_10 ( L_7 ,
F_6 ( V_14 ) ) ;
V_16 -> V_7 &= ~ V_31 ;
F_11 (
V_14 , V_14 -> V_33 , & V_32 ) ;
F_12 (
V_14 , V_14 -> V_33 ,
V_32 & ~ V_34 ) ;
}
}
}
}
static int T_2 F_13 ( void )
{
struct V_13 * V_14 = NULL ;
struct V_2 * V_16 ;
if ( ! ( V_35 & V_36 ) ) {
F_8 (dev) {
V_16 = & V_14 -> V_2 [ V_30 ] ;
if ( ! V_16 -> V_7 || ! V_16 -> V_6 )
continue;
if ( F_4 ( V_14 , V_30 ) < 0 ) {
V_16 -> V_21 -= V_16 -> V_6 ;
V_16 -> V_6 = 0 ;
}
}
}
F_14 () ;
return 0 ;
}
void T_2 F_15 ( void )
{
F_10 ( L_8 ) ;
F_2 ( & V_37 ) ;
F_7 ( 0 ) ;
F_7 ( 1 ) ;
}
void F_16 ( struct V_13 * V_14 )
{
T_5 V_38 ;
F_17 ( V_14 , V_39 , & V_38 ) ;
if ( V_38 < 16 )
V_38 = ( 64 <= V_40 ) ? 64 : V_40 ;
else if ( V_38 > V_40 )
V_38 = V_40 ;
else
return;
F_18 ( V_14 , V_39 , V_38 ) ;
}
int F_19 ( struct V_13 * V_14 , struct V_41 * V_42 ,
enum V_43 V_44 , int V_45 )
{
unsigned long V_46 ;
V_42 -> V_47 |= V_48 | V_49 ;
V_46 = F_20 ( V_42 -> V_50 ) ;
V_46 &= ~ V_51 ;
V_42 -> V_50 = F_21 ( V_46 ) ;
if ( F_22 ( V_42 , V_42 -> V_52 , V_42 -> V_53 ,
V_42 -> V_54 - V_42 -> V_52 ,
V_42 -> V_50 ) )
return - V_55 ;
return 0 ;
}
