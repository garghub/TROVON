static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 = F_3 ( V_7 -> V_8 ) ;
switch ( V_5 ) {
case V_9 :
if ( V_4 )
V_8 &= ~ V_5 ;
else
V_8 |= V_5 ;
break;
default:
if ( V_4 )
V_8 |= V_5 ;
else
V_8 &= ~ V_5 ;
break;
}
F_4 ( V_8 , V_7 -> V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
F_1 ( V_2 , V_4 , V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
F_1 ( V_2 , V_4 , V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
F_1 ( V_2 , V_4 , V_11 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_2 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_8 = F_9 ( V_7 -> V_8 ) ;
switch ( V_5 ) {
case V_12 :
if ( V_4 )
V_8 &= ~ V_5 ;
else
V_8 |= V_5 ;
break;
default:
if ( V_4 )
V_8 |= V_5 ;
else
V_8 &= ~ V_5 ;
break;
}
F_10 ( V_8 , V_7 -> V_8 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
F_8 ( V_2 , V_4 , V_12 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
F_8 ( V_2 , V_4 , V_13 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
F_8 ( V_2 , V_4 , V_14 ) ;
}
static int T_3 F_14 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_7 ;
int V_20 , V_21 = - V_22 ;
if ( V_16 -> V_23 != 1 ) {
F_15 (KERN_ERR PFX L_1 ,
pdev->num_resources) ;
goto V_24;
}
V_7 = F_16 ( sizeof( * V_7 ) , V_25 ) ;
if ( ! V_7 ) {
F_15 (KERN_ERR PFX L_2 ) ;
goto V_24;
}
for ( V_20 = 0 ; V_20 < V_26 ; V_20 ++ ) {
struct V_1 * V_27 = & V_7 -> V_28 [ V_20 ] . V_2 ;
V_7 -> V_28 [ V_20 ] . V_8 = ( void V_29 * ) V_16 -> V_30 [ 0 ] . V_31 ;
V_27 -> V_32 = V_18 [ V_20 ] . V_32 ;
V_27 -> V_33 = V_34 ;
V_27 -> V_35 = V_18 [ V_20 ] . V_36 ;
V_27 -> V_37 = V_18 [ V_20 ] . V_37 ;
V_21 = F_17 ( & V_16 -> V_38 , V_27 ) ;
if ( V_21 ) {
F_15 (KERN_ERR PFX L_3 ,
lp->name) ;
goto V_39;
}
}
F_18 ( & V_16 -> V_38 , V_7 ) ;
V_21 = 0 ;
V_24:
return V_21 ;
V_39:
for ( V_20 -- ; V_20 >= 0 ; V_20 -- )
F_19 ( & V_7 -> V_28 [ V_20 ] . V_2 ) ;
goto V_24;
}
static int T_4 F_20 ( struct V_15 * V_16 )
{
struct V_19 * V_7 = F_21 ( & V_16 -> V_38 ) ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_26 ; V_20 ++ )
F_19 ( & V_7 -> V_28 [ V_20 ] . V_2 ) ;
F_22 ( V_7 ) ;
return 0 ;
}
static int T_3 F_23 ( struct V_15 * V_16 )
{
return F_14 ( V_16 , V_40 ) ;
}
static int T_3 F_24 ( struct V_15 * V_16 )
{
return F_14 ( V_16 , V_41 ) ;
}
static int T_5 F_25 ( void )
{
int V_21 = F_26 ( & V_42 ) ;
if ( V_21 ) {
F_15 (KERN_ERR PFX L_4 ) ;
return V_21 ;
}
V_21 = F_26 ( & V_43 ) ;
if ( V_21 ) {
F_15 (KERN_ERR PFX L_5 ) ;
F_27 ( & V_42 ) ;
}
return V_21 ;
}
static void T_6 F_28 ( void )
{
F_27 ( & V_42 ) ;
F_27 ( & V_43 ) ;
}
