static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
int V_4 ;
struct V_5 * V_6 =
(struct V_5 * ) V_3 -> V_7 ;
V_4 = V_6 -> V_8 ;
V_1 = F_2 ( V_4 , V_9 , 0 ) ;
if ( ! V_1 )
return NULL ;
F_3 ( V_1 ) ;
F_4 ( & V_10 -> V_11 ) ;
return V_1 ;
}
static void F_5 ( struct V_12 * V_13 )
{
F_6 ( V_13 -> V_3 -> V_7 ) ;
}
static unsigned long
F_7 ( struct V_2 * V_3 , T_1 V_14 ,
int type )
{
return F_8 ( V_14 ) ;
}
static void F_9 ( struct V_2 * V_3 , T_2 V_15 )
{
F_10 ( V_3 -> V_7 ) ;
}
static int F_11 ( void )
{
return 0 ;
}
static int F_12 ( void )
{
struct V_5 * V_6 =
(struct V_5 * ) V_10 -> V_7 ;
V_16 [ 0 ] . V_17 = V_6 -> V_18 / F_13 ( 1 ) ;
V_16 [ 0 ] . V_19 = V_6 -> V_20 ;
return V_16 [ 0 ] . V_17 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_3 -> V_7 ;
V_3 -> V_21 = ( T_2 * ) V_6 -> V_22 ;
V_3 -> V_23 = V_3 -> V_21 ;
V_3 -> V_24 = V_6 -> V_25 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_16 ( struct V_12 * V_13 , T_3 V_26 ,
int type )
{
int V_19 ;
T_4 V_27 ;
T_3 V_28 ;
void * V_29 ;
struct V_2 * V_3 ;
T_5 * V_30 ;
V_3 = V_13 -> V_3 ;
if ( ! V_3 )
return - V_31 ;
V_30 = ( T_5 * ) V_3 -> V_23 ;
V_29 = V_3 -> V_32 ;
switch ( V_3 -> V_33 -> V_34 ) {
case V_35 :
V_19 = F_17 ( V_29 ) -> V_19 ;
break;
case V_36 :
V_19 = F_18 ( V_29 ) -> V_19 ;
break;
case V_37 :
V_19 = F_19 ( V_29 ) -> V_19 ;
break;
case V_38 :
V_19 = F_20 ( V_29 ) -> V_19 ;
break;
case V_39 :
return - V_31 ;
default:
V_19 = 0 ;
break;
}
V_19 -= V_40 / V_41 ;
if ( V_19 < 0 )
V_19 = 0 ;
if ( type != 0 || V_13 -> type != 0 ) {
return - V_31 ;
}
if ( ( V_26 + V_13 -> V_42 ) > V_19 )
return - V_31 ;
V_28 = V_26 ;
while ( V_28 < ( V_26 + V_13 -> V_42 ) ) {
if ( V_30 [ V_28 ] )
return - V_43 ;
V_28 ++ ;
}
if ( ! V_13 -> V_44 ) {
V_3 -> V_33 -> V_45 () ;
V_13 -> V_44 = true ;
}
for ( V_27 = 0 , V_28 = V_26 ; V_27 < V_13 -> V_42 ; V_27 ++ , V_28 ++ ) {
V_30 [ V_28 ] =
V_3 -> V_33 -> V_46 ( V_3 ,
F_21 ( V_13 -> V_47 [ V_27 ] ) ,
V_13 -> type ) ;
}
V_3 -> V_33 -> V_48 ( V_13 ) ;
return 0 ;
}
static int F_22 ( struct V_12 * V_13 , T_3 V_26 ,
int type )
{
T_4 V_27 ;
struct V_2 * V_3 ;
T_5 * V_30 ;
V_3 = V_13 -> V_3 ;
if ( ! V_3 )
return - V_31 ;
if ( type != 0 || V_13 -> type != 0 ) {
return - V_31 ;
}
V_30 = ( T_5 * ) V_3 -> V_23 ;
for ( V_27 = V_26 ; V_27 < ( V_13 -> V_42 + V_26 ) ; V_27 ++ ) {
V_30 [ V_27 ] = 0 ;
}
V_3 -> V_33 -> V_48 ( V_13 ) ;
return 0 ;
}
static void F_23 ( void )
{
}
static void F_24 ( void )
{
}
static struct V_2 * F_25 ( struct V_49 * V_50 )
{
struct V_2 * V_3 ;
F_26 (bridge, &agp_bridges, list) {
if ( V_3 -> V_51 -> V_52 == V_50 -> V_52 )
break;
}
return V_3 ;
}
static int T_6 F_27 ( void )
{
unsigned int V_28 ;
struct V_5 * V_6 ;
struct V_49 * V_50 = NULL ;
if ( V_53 )
F_28 (KERN_INFO PFX L_1 ) ;
else
return 0 ;
V_54 = F_29 ( V_53 *
sizeof( struct V_2 * ) ,
V_9 ) ;
if ( ! V_54 )
return - V_55 ;
V_28 = 0 ;
F_26 (info, &tioca_list, ca_list) {
if ( F_30 ( V_6 -> V_56 ) )
continue;
F_26 (pdev, info->ca_devices, bus_list) {
T_7 V_57 ;
if ( V_50 -> V_58 != ( V_59 << 8 ) )
continue;
V_57 = F_31 ( V_50 , V_60 ) ;
if ( ! V_57 )
continue;
}
V_54 [ V_28 ] = F_32 () ;
F_28 (KERN_INFO PFX L_2 , j,
sgi_tioca_agp_bridges[j]) ;
if ( V_54 [ V_28 ] ) {
V_54 [ V_28 ] -> V_51 = V_50 ;
V_54 [ V_28 ] -> V_7 = V_6 ;
V_54 [ V_28 ] -> V_33 = & V_61 ;
V_54 [ V_28 ] -> V_62 =
V_6 -> V_63 ;
V_54 [ V_28 ] -> V_15 = ( 0x7D << 24 ) |
( 0x1 << 9 ) |
( 0x1 << 5 ) |
( 0x1 << 4 ) |
( 0x1 << 3 ) |
0x2 ;
V_54 [ V_28 ] -> V_32 =
V_54 [ V_28 ] -> V_64 =
( void * ) & V_16 [ 0 ] ;
F_33 ( V_54 [ V_28 ] ) ;
}
V_28 ++ ;
}
V_65 = & F_25 ;
return 0 ;
}
static void T_8 F_34 ( void )
{
F_35 ( V_54 ) ;
V_54 = NULL ;
}
