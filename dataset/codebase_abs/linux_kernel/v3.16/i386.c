static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( ! F_3 ( & V_5 ) ) ;
F_4 (map, &pcibios_fwaddrmappings, list)
if ( V_4 -> V_3 == V_3 )
return V_4 ;
return NULL ;
}
static void
F_5 ( struct V_2 * V_3 , int V_6 , T_1 V_7 )
{
unsigned long V_8 ;
struct V_1 * V_4 ;
if ( V_9 )
return;
F_6 ( & V_5 , V_8 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_7 ( & V_5 , V_8 ) ;
V_4 = F_8 ( sizeof( * V_4 ) , V_10 ) ;
if ( ! V_4 )
return;
V_4 -> V_3 = F_9 ( V_3 ) ;
V_4 -> V_7 [ V_6 ] = V_7 ;
F_10 ( & V_4 -> V_11 ) ;
F_6 ( & V_5 , V_8 ) ;
F_11 ( & V_4 -> V_11 , & V_12 ) ;
} else
V_4 -> V_7 [ V_6 ] = V_7 ;
F_7 ( & V_5 , V_8 ) ;
}
T_1 F_12 ( struct V_2 * V_3 , int V_6 )
{
unsigned long V_8 ;
struct V_1 * V_4 ;
T_1 V_7 = 0 ;
if ( V_9 )
return 0 ;
F_6 ( & V_5 , V_8 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 )
V_7 = V_4 -> V_7 [ V_6 ] ;
F_7 ( & V_5 , V_8 ) ;
return V_7 ;
}
static void T_2 F_13 ( void )
{
unsigned long V_8 ;
struct V_1 * V_13 , * V_14 ;
F_6 ( & V_5 , V_8 ) ;
F_14 (entry, next, &pcibios_fwaddrmappings, list) {
F_15 ( & V_13 -> V_11 ) ;
F_16 ( V_13 -> V_3 ) ;
F_17 ( V_13 ) ;
}
F_7 ( & V_5 , V_8 ) ;
V_9 = true ;
}
static int
F_18 ( struct V_2 * V_3 ) {
if ( ( V_15 & V_16 ) &&
! ( V_3 -> V_17 -> V_18 & V_19 ) )
return 1 ;
return 0 ;
}
T_1
F_19 ( void * V_20 , const struct V_21 * V_22 ,
T_1 V_23 , T_1 V_24 )
{
struct V_2 * V_3 = V_20 ;
T_1 V_25 = V_22 -> V_25 ;
if ( V_22 -> V_8 & V_26 ) {
if ( F_18 ( V_3 ) )
return V_25 ;
if ( V_25 & 0x300 )
V_25 = ( V_25 + 0x3ff ) & ~ 0x3ff ;
}
return V_25 ;
}
static void F_20 ( struct V_2 * V_3 )
{
int V_6 ;
struct V_21 * V_27 ;
for ( V_6 = V_28 ; V_6 < V_29 ; V_6 ++ ) {
V_27 = & V_3 -> V_21 [ V_6 ] ;
if ( ! V_27 -> V_8 )
continue;
if ( V_27 -> V_30 )
continue;
if ( ! V_27 -> V_25 || F_21 ( V_3 , V_6 ) < 0 ) {
V_27 -> V_25 = V_27 -> V_31 = 0 ;
V_27 -> V_8 = 0 ;
}
}
}
static void F_22 ( struct V_32 * V_17 )
{
struct V_32 * V_33 ;
if ( V_17 -> V_34 )
F_20 ( V_17 -> V_34 ) ;
F_4 (child, &bus->children, node)
F_22 ( V_33 ) ;
}
static void F_23 ( struct V_2 * V_3 , int V_35 )
{
int V_6 , V_36 , V_37 ;
T_3 V_38 ;
struct V_21 * V_27 ;
struct V_39 V_40 [] = {
{ V_41 , V_42 } ,
#ifdef F_24
{ V_43 , V_44 } ,
#endif
} ;
F_25 ( V_3 , V_45 , & V_38 ) ;
for ( V_37 = 0 ; V_37 < F_26 ( V_40 ) ; V_37 ++ )
for ( V_6 = V_40 [ V_37 ] . V_25 ; V_6 <= V_40 [ V_37 ] . V_31 ; V_6 ++ ) {
V_27 = & V_3 -> V_21 [ V_6 ] ;
if ( V_27 -> V_30 )
continue;
if ( ! V_27 -> V_25 )
continue;
if ( V_27 -> V_8 & V_26 )
V_36 = ! ( V_38 & V_46 ) ;
else
V_36 = ! ( V_38 & V_47 ) ;
if ( V_35 == V_36 ) {
F_27 ( & V_3 -> V_3 ,
L_1 ,
V_6 , V_27 , V_36 , V_35 ) ;
if ( F_21 ( V_3 , V_6 ) < 0 ) {
if ( V_27 -> V_8 & V_48 ) {
F_28 ( & V_3 -> V_3 , L_2 ,
V_6 , V_27 ) ;
} else {
F_5 ( V_3 ,
V_6 , V_27 -> V_25 ) ;
V_27 -> V_31 -= V_27 -> V_25 ;
V_27 -> V_25 = 0 ;
}
}
}
}
if ( ! V_35 ) {
V_27 = & V_3 -> V_21 [ V_49 ] ;
if ( V_27 -> V_8 & V_50 ) {
T_4 V_51 ;
F_27 ( & V_3 -> V_3 , L_3 , V_27 ) ;
V_27 -> V_8 &= ~ V_50 ;
F_29 ( V_3 , V_3 -> V_52 , & V_51 ) ;
F_30 ( V_3 , V_3 -> V_52 ,
V_51 & ~ V_53 ) ;
}
}
}
static void F_31 ( struct V_32 * V_17 , int V_35 )
{
struct V_2 * V_3 ;
struct V_32 * V_33 ;
F_4 (dev, &bus->devices, bus_list) {
F_23 ( V_3 , V_35 ) ;
V_33 = V_3 -> V_54 ;
if ( V_33 )
F_31 ( V_33 , V_35 ) ;
}
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_21 * V_27 ;
V_27 = & V_3 -> V_21 [ V_49 ] ;
if ( ! V_27 -> V_8 || ! V_27 -> V_25 )
return;
if ( V_27 -> V_30 )
return;
if ( F_21 ( V_3 , V_49 ) < 0 ) {
V_27 -> V_31 -= V_27 -> V_25 ;
V_27 -> V_25 = 0 ;
}
}
static void F_33 ( struct V_32 * V_17 )
{
struct V_2 * V_3 ;
struct V_32 * V_33 ;
F_4 (dev, &bus->devices, bus_list) {
F_32 ( V_3 ) ;
V_33 = V_3 -> V_54 ;
if ( V_33 )
F_33 ( V_33 ) ;
}
}
static int T_2 F_34 ( void )
{
struct V_32 * V_17 ;
if ( ! ( V_15 & V_55 ) )
F_4 (bus, &pci_root_buses, node)
F_33 ( V_17 ) ;
F_35 () ;
F_13 () ;
return 0 ;
}
void F_36 ( struct V_32 * V_17 )
{
F_37 ( V_56 , & V_17 -> V_3 , L_4 ) ;
F_22 ( V_17 ) ;
F_31 ( V_17 , 0 ) ;
F_31 ( V_17 , 1 ) ;
if ( ! ( V_15 & V_55 ) )
F_33 ( V_17 ) ;
}
void T_2 F_38 ( void )
{
struct V_32 * V_17 ;
F_39 ( L_5 ) ;
F_4 (bus, &pci_root_buses, node)
F_22 ( V_17 ) ;
F_4 (bus, &pci_root_buses, node)
F_31 ( V_17 , 0 ) ;
F_4 (bus, &pci_root_buses, node)
F_31 ( V_17 , 1 ) ;
F_40 () ;
F_41 () ;
}
int F_42 ( struct V_2 * V_3 , struct V_57 * V_58 ,
enum V_59 V_60 , int V_61 )
{
unsigned long V_62 ;
if ( V_60 == V_63 )
return - V_64 ;
V_62 = F_43 ( V_58 -> V_65 ) ;
if ( ! V_66 && V_61 )
return - V_64 ;
if ( V_66 && V_61 )
V_62 |= V_67 ;
else if ( V_66 || V_68 . V_69 > 3 )
V_62 |= V_70 ;
V_62 |= V_71 ;
V_58 -> V_65 = F_44 ( V_62 ) ;
if ( F_45 ( V_58 , V_58 -> V_72 , V_58 -> V_73 ,
V_58 -> V_74 - V_58 -> V_72 ,
V_58 -> V_65 ) )
return - V_75 ;
V_58 -> V_76 = & V_77 ;
return 0 ;
}
