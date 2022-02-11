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
static int F_14 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_7 ;
int V_20 , V_21 ;
if ( V_16 -> V_22 != 1 ) {
F_15 ( & V_16 -> V_23 , L_1 ,
V_16 -> V_22 ) ;
return - V_24 ;
}
V_7 = F_16 ( & V_16 -> V_23 , sizeof( * V_7 ) , V_25 ) ;
if ( ! V_7 )
return - V_26 ;
for ( V_20 = 0 ; V_20 < V_27 ; V_20 ++ ) {
struct V_1 * V_28 = & V_7 -> V_29 [ V_20 ] . V_2 ;
V_7 -> V_29 [ V_20 ] . V_8 = ( void V_30 * ) V_16 -> V_31 [ 0 ] . V_32 ;
V_28 -> V_33 = V_18 [ V_20 ] . V_33 ;
V_28 -> V_34 = V_35 ;
V_28 -> V_36 = V_18 [ V_20 ] . V_37 ;
V_28 -> V_38 = V_18 [ V_20 ] . V_38 ;
V_21 = F_17 ( & V_16 -> V_23 , V_28 ) ;
if ( V_21 ) {
F_15 ( & V_16 -> V_23 , L_2 ,
V_28 -> V_33 ) ;
for ( V_20 -- ; V_20 >= 0 ; V_20 -- )
F_18 ( & V_7 -> V_29 [ V_20 ] . V_2 ) ;
return V_21 ;
}
}
F_19 ( V_16 , V_7 ) ;
return 0 ;
}
static int F_20 ( struct V_15 * V_16 )
{
struct V_19 * V_7 = F_21 ( V_16 ) ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_27 ; V_20 ++ )
F_18 ( & V_7 -> V_29 [ V_20 ] . V_2 ) ;
return 0 ;
}
static int F_22 ( struct V_15 * V_16 )
{
return F_14 ( V_16 , V_39 ) ;
}
static int F_23 ( struct V_15 * V_16 )
{
return F_14 ( V_16 , V_40 ) ;
}
static int T_3 F_24 ( void )
{
return F_25 ( V_41 , F_26 ( V_41 ) ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( V_41 , F_26 ( V_41 ) ) ;
}
