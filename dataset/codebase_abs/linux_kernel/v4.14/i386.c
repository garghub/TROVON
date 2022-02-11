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
} else if ( V_22 -> V_8 & V_27 ) {
if ( V_25 < V_28 )
V_25 = V_28 ;
}
return V_25 ;
}
static void F_20 ( struct V_2 * V_3 )
{
int V_6 ;
struct V_21 * V_29 ;
for ( V_6 = V_30 ; V_6 < V_31 ; V_6 ++ ) {
V_29 = & V_3 -> V_21 [ V_6 ] ;
if ( ! V_29 -> V_8 )
continue;
if ( V_29 -> V_32 )
continue;
if ( ! V_29 -> V_25 || F_21 ( V_3 , V_6 ) < 0 ) {
V_29 -> V_25 = V_29 -> V_33 = 0 ;
V_29 -> V_8 = 0 ;
}
}
}
static void F_22 ( struct V_34 * V_17 )
{
struct V_34 * V_35 ;
if ( V_17 -> V_36 )
F_20 ( V_17 -> V_36 ) ;
F_4 (child, &bus->children, node)
F_22 ( V_35 ) ;
}
static void F_23 ( struct V_2 * V_3 , int V_37 )
{
int V_6 , V_38 , V_39 ;
T_3 V_40 ;
struct V_21 * V_29 ;
struct V_41 V_42 [] = {
{ V_43 , V_44 } ,
#ifdef F_24
{ V_45 , V_46 } ,
#endif
} ;
F_25 ( V_3 , V_47 , & V_40 ) ;
for ( V_39 = 0 ; V_39 < F_26 ( V_42 ) ; V_39 ++ )
for ( V_6 = V_42 [ V_39 ] . V_25 ; V_6 <= V_42 [ V_39 ] . V_33 ; V_6 ++ ) {
V_29 = & V_3 -> V_21 [ V_6 ] ;
if ( V_29 -> V_32 )
continue;
if ( ! V_29 -> V_25 )
continue;
if ( V_29 -> V_8 & V_26 )
V_38 = ! ( V_40 & V_48 ) ;
else
V_38 = ! ( V_40 & V_49 ) ;
if ( V_37 == V_38 ) {
F_27 ( & V_3 -> V_3 ,
L_1 ,
V_6 , V_29 , V_38 , V_37 ) ;
if ( F_28 ( V_3 , V_6 ) < 0 ) {
if ( V_29 -> V_8 & V_50 ) {
F_29 ( & V_3 -> V_3 , L_2 ,
V_6 , V_29 ) ;
} else {
F_5 ( V_3 ,
V_6 , V_29 -> V_25 ) ;
V_29 -> V_33 -= V_29 -> V_25 ;
V_29 -> V_25 = 0 ;
}
}
}
}
if ( ! V_37 ) {
V_29 = & V_3 -> V_21 [ V_51 ] ;
if ( V_29 -> V_8 & V_52 ) {
T_4 V_53 ;
F_27 ( & V_3 -> V_3 , L_3 , V_29 ) ;
V_29 -> V_8 &= ~ V_52 ;
F_30 ( V_3 , V_3 -> V_54 , & V_53 ) ;
F_31 ( V_3 , V_3 -> V_54 ,
V_53 & ~ V_55 ) ;
}
}
}
static void F_32 ( struct V_34 * V_17 , int V_37 )
{
struct V_2 * V_3 ;
struct V_34 * V_35 ;
F_4 (dev, &bus->devices, bus_list) {
F_23 ( V_3 , V_37 ) ;
V_35 = V_3 -> V_56 ;
if ( V_35 )
F_32 ( V_35 , V_37 ) ;
}
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_21 * V_29 ;
V_29 = & V_3 -> V_21 [ V_51 ] ;
if ( ! V_29 -> V_8 || ! V_29 -> V_25 )
return;
if ( V_29 -> V_32 )
return;
if ( F_28 ( V_3 , V_51 ) < 0 ) {
V_29 -> V_33 -= V_29 -> V_25 ;
V_29 -> V_25 = 0 ;
}
}
static void F_34 ( struct V_34 * V_17 )
{
struct V_2 * V_3 ;
struct V_34 * V_35 ;
F_4 (dev, &bus->devices, bus_list) {
F_33 ( V_3 ) ;
V_35 = V_3 -> V_56 ;
if ( V_35 )
F_34 ( V_35 ) ;
}
}
static int T_2 F_35 ( void )
{
struct V_34 * V_17 ;
if ( ! ( V_15 & V_57 ) )
F_4 (bus, &pci_root_buses, node)
F_34 ( V_17 ) ;
F_36 () ;
F_13 () ;
return 0 ;
}
void F_37 ( struct V_34 * V_17 )
{
F_38 ( V_58 , & V_17 -> V_3 , L_4 ) ;
F_22 ( V_17 ) ;
F_32 ( V_17 , 0 ) ;
F_32 ( V_17 , 1 ) ;
if ( ! ( V_15 & V_57 ) )
F_34 ( V_17 ) ;
}
void T_2 F_39 ( void )
{
struct V_34 * V_17 ;
F_40 ( L_5 ) ;
F_4 (bus, &pci_root_buses, node)
F_22 ( V_17 ) ;
F_4 (bus, &pci_root_buses, node)
F_32 ( V_17 , 0 ) ;
F_4 (bus, &pci_root_buses, node)
F_32 ( V_17 , 1 ) ;
F_41 () ;
F_42 () ;
}
