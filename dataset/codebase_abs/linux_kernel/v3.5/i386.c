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
F_6 ( & V_5 , V_8 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_7 ( & V_5 , V_8 ) ;
V_4 = F_8 ( sizeof( * V_4 ) , V_9 ) ;
if ( ! V_4 )
return;
V_4 -> V_3 = F_9 ( V_3 ) ;
V_4 -> V_7 [ V_6 ] = V_7 ;
F_10 ( & V_4 -> V_10 ) ;
F_6 ( & V_5 , V_8 ) ;
F_11 ( & V_4 -> V_10 , & V_11 ) ;
} else
V_4 -> V_7 [ V_6 ] = V_7 ;
F_7 ( & V_5 , V_8 ) ;
}
T_1 F_12 ( struct V_2 * V_3 , int V_6 )
{
unsigned long V_8 ;
struct V_1 * V_4 ;
T_1 V_7 = 0 ;
F_6 ( & V_5 , V_8 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 )
V_7 = V_4 -> V_7 [ V_6 ] ;
F_7 ( & V_5 , V_8 ) ;
return V_7 ;
}
static void F_13 ( void )
{
unsigned long V_8 ;
struct V_1 * V_12 , * V_13 ;
F_6 ( & V_5 , V_8 ) ;
F_14 (entry, next, &pcibios_fwaddrmappings, list) {
F_15 ( & V_12 -> V_10 ) ;
F_16 ( V_12 -> V_3 ) ;
F_17 ( V_12 ) ;
}
F_7 ( & V_5 , V_8 ) ;
}
static int
F_18 ( struct V_2 * V_3 ) {
if ( ( V_14 & V_15 ) &&
! ( V_3 -> V_16 -> V_17 & V_18 ) )
return 1 ;
return 0 ;
}
T_1
F_19 ( void * V_19 , const struct V_20 * V_21 ,
T_1 V_22 , T_1 V_23 )
{
struct V_2 * V_3 = V_19 ;
T_1 V_24 = V_21 -> V_24 ;
if ( V_21 -> V_8 & V_25 ) {
if ( F_18 ( V_3 ) )
return V_24 ;
if ( V_24 & 0x300 )
V_24 = ( V_24 + 0x3ff ) & ~ 0x3ff ;
}
return V_24 ;
}
static void T_2 F_20 ( struct V_26 * V_27 )
{
struct V_28 * V_16 ;
struct V_2 * V_3 ;
int V_6 ;
struct V_20 * V_29 ;
F_4 (bus, bus_list, node) {
if ( ( V_3 = V_16 -> V_30 ) ) {
for ( V_6 = V_31 ;
V_6 < V_32 ; V_6 ++ ) {
V_29 = & V_3 -> V_20 [ V_6 ] ;
if ( ! V_29 -> V_8 )
continue;
if ( ! V_29 -> V_24 ||
F_21 ( V_3 , V_6 ) < 0 ) {
V_29 -> V_24 = V_29 -> V_33 = 0 ;
V_29 -> V_8 = 0 ;
}
}
}
F_20 ( & V_16 -> V_34 ) ;
}
}
static void T_2 F_22 ( int V_35 )
{
struct V_2 * V_3 = NULL ;
int V_6 , V_36 , V_37 ;
T_3 V_38 ;
struct V_20 * V_29 ;
struct V_39 V_40 [] = {
{ V_41 , V_42 } ,
#ifdef F_23
{ V_43 , V_44 } ,
#endif
} ;
F_24 (dev) {
F_25 ( V_3 , V_45 , & V_38 ) ;
for ( V_37 = 0 ; V_37 < F_26 ( V_40 ) ; V_37 ++ )
for ( V_6 = V_40 [ V_37 ] . V_24 ; V_6 <= V_40 [ V_37 ] . V_33 ; V_6 ++ ) {
V_29 = & V_3 -> V_20 [ V_6 ] ;
if ( V_29 -> V_46 )
continue;
if ( ! V_29 -> V_24 )
continue;
if ( V_29 -> V_8 & V_25 )
V_36 = ! ( V_38 & V_47 ) ;
else
V_36 = ! ( V_38 & V_48 ) ;
if ( V_35 == V_36 ) {
F_27 ( & V_3 -> V_3 ,
L_1 ,
V_6 , V_29 , V_36 , V_35 ) ;
if ( F_21 ( V_3 , V_6 ) < 0 ) {
F_5 ( V_3 ,
V_6 , V_29 -> V_24 ) ;
V_29 -> V_33 -= V_29 -> V_24 ;
V_29 -> V_24 = 0 ;
}
}
}
if ( ! V_35 ) {
V_29 = & V_3 -> V_20 [ V_49 ] ;
if ( V_29 -> V_8 & V_50 ) {
T_4 V_51 ;
F_27 ( & V_3 -> V_3 , L_2 , V_29 ) ;
V_29 -> V_8 &= ~ V_50 ;
F_28 ( V_3 ,
V_3 -> V_52 , & V_51 ) ;
F_29 ( V_3 , V_3 -> V_52 ,
V_51 & ~ V_53 ) ;
}
}
}
}
static int T_2 F_30 ( void )
{
struct V_2 * V_3 = NULL ;
struct V_20 * V_29 ;
if ( ! ( V_14 & V_54 ) ) {
F_24 (dev) {
V_29 = & V_3 -> V_20 [ V_49 ] ;
if ( ! V_29 -> V_8 || ! V_29 -> V_24 )
continue;
if ( F_21 ( V_3 , V_49 ) < 0 ) {
V_29 -> V_33 -= V_29 -> V_24 ;
V_29 -> V_24 = 0 ;
}
}
}
F_31 () ;
F_13 () ;
return 0 ;
}
void T_2 F_32 ( void )
{
F_33 ( L_3 ) ;
F_20 ( & V_55 ) ;
F_22 ( 0 ) ;
F_22 ( 1 ) ;
F_34 () ;
F_35 () ;
}
int F_36 ( struct V_2 * V_3 , struct V_56 * V_57 ,
enum V_58 V_59 , int V_60 )
{
unsigned long V_61 ;
if ( V_59 == V_62 )
return - V_63 ;
V_61 = F_37 ( V_57 -> V_64 ) ;
if ( ! V_65 && V_60 )
return - V_63 ;
if ( V_65 && V_60 )
V_61 |= V_66 ;
else if ( V_65 || V_67 . V_68 > 3 )
V_61 |= V_69 ;
V_61 |= V_70 ;
V_57 -> V_64 = F_38 ( V_61 ) ;
if ( F_39 ( V_57 , V_57 -> V_71 , V_57 -> V_72 ,
V_57 -> V_73 - V_57 -> V_71 ,
V_57 -> V_64 ) )
return - V_74 ;
V_57 -> V_75 = & V_76 ;
return 0 ;
}
