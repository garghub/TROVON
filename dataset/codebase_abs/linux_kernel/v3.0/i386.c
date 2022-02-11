static int
F_1 ( struct V_1 * V_2 ) {
if ( ( V_3 & V_4 ) &&
! ( V_2 -> V_5 -> V_6 & V_7 ) )
return 1 ;
return 0 ;
}
T_1
F_2 ( void * V_8 , const struct V_9 * V_10 ,
T_1 V_11 , T_1 V_12 )
{
struct V_1 * V_2 = V_8 ;
T_1 V_13 = V_10 -> V_13 ;
if ( V_10 -> V_14 & V_15 ) {
if ( F_1 ( V_2 ) )
return V_13 ;
if ( V_13 & 0x300 )
V_13 = ( V_13 + 0x3ff ) & ~ 0x3ff ;
}
return V_13 ;
}
static void T_2 F_3 ( struct V_16 * V_17 )
{
struct V_18 * V_5 ;
struct V_1 * V_2 ;
int V_19 ;
struct V_9 * V_20 ;
F_4 (bus, bus_list, node) {
if ( ( V_2 = V_5 -> V_21 ) ) {
for ( V_19 = V_22 ;
V_19 < V_23 ; V_19 ++ ) {
V_20 = & V_2 -> V_9 [ V_19 ] ;
if ( ! V_20 -> V_14 )
continue;
if ( ! V_20 -> V_13 ||
F_5 ( V_2 , V_19 ) < 0 ) {
V_20 -> V_13 = V_20 -> V_24 = 0 ;
V_20 -> V_14 = 0 ;
}
}
}
F_3 ( & V_5 -> V_25 ) ;
}
}
static void T_2 F_6 ( int V_26 )
{
struct V_1 * V_2 = NULL ;
int V_19 , V_27 , V_28 ;
T_3 V_29 ;
struct V_9 * V_20 ;
struct V_30 V_31 [] = {
{ V_32 , V_33 } ,
#ifdef F_7
{ V_34 , V_35 } ,
#endif
} ;
F_8 (dev) {
F_9 ( V_2 , V_36 , & V_29 ) ;
for ( V_28 = 0 ; V_28 < F_10 ( V_31 ) ; V_28 ++ )
for ( V_19 = V_31 [ V_28 ] . V_13 ; V_19 <= V_31 [ V_28 ] . V_24 ; V_19 ++ ) {
V_20 = & V_2 -> V_9 [ V_19 ] ;
if ( V_20 -> V_37 )
continue;
if ( ! V_20 -> V_13 )
continue;
if ( V_20 -> V_14 & V_15 )
V_27 = ! ( V_29 & V_38 ) ;
else
V_27 = ! ( V_29 & V_39 ) ;
if ( V_26 == V_27 ) {
F_11 ( & V_2 -> V_2 ,
L_1 ,
V_19 , V_20 , V_27 , V_26 ) ;
if ( F_5 ( V_2 , V_19 ) < 0 ) {
V_2 -> V_40 [ V_19 ] = V_20 -> V_13 ;
V_20 -> V_24 -= V_20 -> V_13 ;
V_20 -> V_13 = 0 ;
}
}
}
if ( ! V_26 ) {
V_20 = & V_2 -> V_9 [ V_41 ] ;
if ( V_20 -> V_14 & V_42 ) {
T_4 V_43 ;
F_11 ( & V_2 -> V_2 , L_2 , V_20 ) ;
V_20 -> V_14 &= ~ V_42 ;
F_12 ( V_2 ,
V_2 -> V_44 , & V_43 ) ;
F_13 ( V_2 , V_2 -> V_44 ,
V_43 & ~ V_45 ) ;
}
}
}
}
static int T_2 F_14 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_9 * V_20 ;
if ( ! ( V_3 & V_46 ) ) {
F_8 (dev) {
V_20 = & V_2 -> V_9 [ V_41 ] ;
if ( ! V_20 -> V_14 || ! V_20 -> V_13 )
continue;
if ( F_5 ( V_2 , V_41 ) < 0 ) {
V_20 -> V_24 -= V_20 -> V_13 ;
V_20 -> V_13 = 0 ;
}
}
}
F_15 () ;
return 0 ;
}
void T_2 F_16 ( void )
{
F_17 ( L_3 ) ;
F_3 ( & V_47 ) ;
F_6 ( 0 ) ;
F_6 ( 1 ) ;
F_18 () ;
F_19 () ;
}
void F_20 ( struct V_1 * V_2 )
{
T_5 V_48 ;
F_21 ( V_2 , V_49 , & V_48 ) ;
if ( V_48 < 16 )
V_48 = ( 64 <= V_50 ) ? 64 : V_50 ;
else if ( V_48 > V_50 )
V_48 = V_50 ;
else
return;
F_22 ( V_51 , & V_2 -> V_2 , L_4 , V_48 ) ;
F_23 ( V_2 , V_49 , V_48 ) ;
}
int F_24 ( struct V_1 * V_2 , struct V_52 * V_53 ,
enum V_54 V_55 , int V_56 )
{
unsigned long V_57 ;
if ( V_55 == V_58 )
return - V_59 ;
V_57 = F_25 ( V_53 -> V_60 ) ;
if ( ! V_61 && V_56 )
return - V_59 ;
if ( V_61 && V_56 )
V_57 |= V_62 ;
else if ( V_61 || V_63 . V_64 > 3 )
V_57 |= V_65 ;
V_57 |= V_66 ;
V_53 -> V_60 = F_26 ( V_57 ) ;
if ( F_27 ( V_53 , V_53 -> V_67 , V_53 -> V_68 ,
V_53 -> V_69 - V_53 -> V_67 ,
V_53 -> V_60 ) )
return - V_70 ;
V_53 -> V_71 = & V_72 ;
return 0 ;
}
