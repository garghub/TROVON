static bool
F_1 ( char V_1 [ V_2 ] , struct V_3
* V_4 )
{
const int V_5 = F_2 ( & V_6 , 0 , 0 , V_7 ) ;
if ( V_5 < 0 || V_5 >= 100 )
return false ;
if ( V_5 > 0 )
snprintf ( V_1 , V_2 , L_1 , V_5 ) ;
else
snprintf ( V_1 , V_2 , L_2 ) ;
V_4 -> V_8 = V_5 ;
return true ;
}
static int
F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_13 * V_14 = & V_12 -> V_15 . V_14 . V_16 ;
int V_17 = ( F_5 ( V_14 , V_18 ) &
V_19 ) >> 16 ;
return V_17 ;
}
static int
F_6 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_13 * V_14 = & V_12 -> V_15 . V_14 . V_16 ;
int V_17 = V_10 -> V_20 . V_21 ;
int V_22 = F_5 ( V_14 , V_18 ) ;
F_7 ( V_14 , V_18 ,
( V_17 << 16 ) | ( V_22 & ~ V_19 ) ) ;
return 0 ;
}
static int
F_8 ( struct V_23 * V_4 )
{
struct V_11 * V_12 = V_11 ( V_4 -> V_24 ) ;
struct V_13 * V_14 = & V_12 -> V_15 . V_14 . V_16 ;
struct V_25 V_20 ;
struct V_9 * V_10 ;
struct V_3 V_26 ;
char V_1 [ V_2 ] ;
if ( ! ( F_5 ( V_14 , V_18 ) & V_19 ) )
return 0 ;
memset ( & V_20 , 0 , sizeof( struct V_25 ) ) ;
V_20 . type = V_27 ;
V_20 . V_28 = 31 ;
if ( ! F_1 ( V_1 , & V_26 ) ) {
F_9 ( V_12 , L_3 ) ;
return 0 ;
}
V_10 = F_10 ( V_1 , V_4 -> V_29 , V_12 ,
& V_30 , & V_20 ) ;
if ( F_11 ( V_10 ) ) {
if ( V_26 . V_8 > 0 )
F_12 ( & V_6 , V_26 . V_8 ) ;
return F_13 ( V_10 ) ;
}
F_14 ( & V_26 . V_31 , & V_12 -> V_32 ) ;
V_12 -> V_33 = V_10 ;
V_10 -> V_20 . V_21 = F_3 ( V_10 ) ;
F_15 ( V_10 ) ;
return 0 ;
}
static int
F_16 ( struct V_9 * V_10 )
{
struct V_34 * V_35 = F_4 ( V_10 ) ;
struct V_11 * V_12 = V_11 ( V_35 -> V_36 . V_36 . V_24 ) ;
struct V_13 * V_14 = & V_12 -> V_15 . V_14 . V_16 ;
int V_37 = V_35 -> V_37 ;
T_1 div = 1025 ;
T_1 V_17 ;
V_17 = F_5 ( V_14 , F_17 ( V_37 ) ) ;
V_17 &= V_38 ;
return ( ( V_17 * 100 ) + ( div / 2 ) ) / div ;
}
static int
F_18 ( struct V_9 * V_10 )
{
struct V_34 * V_35 = F_4 ( V_10 ) ;
struct V_11 * V_12 = V_11 ( V_35 -> V_36 . V_36 . V_24 ) ;
struct V_13 * V_14 = & V_12 -> V_15 . V_14 . V_16 ;
int V_37 = V_35 -> V_37 ;
T_1 div = 1025 ;
T_1 V_17 = ( V_10 -> V_20 . V_21 * div ) / 100 ;
F_7 ( V_14 , F_17 ( V_37 ) ,
V_39 | V_17 ) ;
return 0 ;
}
static int
F_19 ( struct V_9 * V_10 )
{
struct V_34 * V_35 = F_4 ( V_10 ) ;
struct V_11 * V_12 = V_11 ( V_35 -> V_36 . V_36 . V_24 ) ;
struct V_13 * V_14 = & V_12 -> V_15 . V_14 . V_16 ;
int V_37 = V_35 -> V_37 ;
T_1 div , V_17 ;
div = F_5 ( V_14 , F_20 ( V_37 ) ) ;
V_17 = F_5 ( V_14 , F_17 ( V_37 ) ) ;
V_17 &= V_40 ;
if ( div && div >= V_17 )
return ( ( V_17 * 100 ) + ( div / 2 ) ) / div ;
return 100 ;
}
static int
F_21 ( struct V_9 * V_10 )
{
struct V_34 * V_35 = F_4 ( V_10 ) ;
struct V_11 * V_12 = V_11 ( V_35 -> V_36 . V_36 . V_24 ) ;
struct V_13 * V_14 = & V_12 -> V_15 . V_14 . V_16 ;
int V_37 = V_35 -> V_37 ;
T_1 div , V_17 ;
div = F_5 ( V_14 , F_20 ( V_37 ) ) ;
V_17 = ( V_10 -> V_20 . V_21 * div ) / 100 ;
if ( div ) {
F_7 ( V_14 , F_17 ( V_37 ) , V_17 |
V_39 |
V_41 ) ;
return 0 ;
}
return - V_42 ;
}
static int
F_22 ( struct V_23 * V_4 )
{
struct V_11 * V_12 = V_11 ( V_4 -> V_24 ) ;
struct V_13 * V_14 = & V_12 -> V_15 . V_14 . V_16 ;
struct V_34 * V_35 ;
struct V_25 V_20 ;
struct V_9 * V_10 ;
const struct V_43 * V_44 ;
struct V_3 V_26 ;
char V_1 [ V_2 ] ;
V_35 = F_23 ( V_4 , V_45 ) ;
if ( ! V_35 ) {
V_35 = F_23 ( V_4 , V_46 ) ;
if ( ! V_35 )
return - V_47 ;
}
if ( ! F_5 ( V_14 , F_17 ( V_35 -> V_37 ) ) )
return 0 ;
if ( V_12 -> V_15 . V_14 . V_48 . V_49 <= 0xa0 ||
V_12 -> V_15 . V_14 . V_48 . V_49 == 0xaa ||
V_12 -> V_15 . V_14 . V_48 . V_49 == 0xac )
V_44 = & V_50 ;
else
V_44 = & V_51 ;
memset ( & V_20 , 0 , sizeof( struct V_25 ) ) ;
V_20 . type = V_27 ;
V_20 . V_28 = 100 ;
if ( ! F_1 ( V_1 , & V_26 ) ) {
F_9 ( V_12 , L_3 ) ;
return 0 ;
}
V_10 = F_10 ( V_1 , V_4 -> V_29 ,
V_35 , V_44 , & V_20 ) ;
if ( F_11 ( V_10 ) ) {
if ( V_26 . V_8 > 0 )
F_12 ( & V_6 , V_26 . V_8 ) ;
return F_13 ( V_10 ) ;
}
F_14 ( & V_26 . V_31 , & V_12 -> V_32 ) ;
V_12 -> V_33 = V_10 ;
V_10 -> V_20 . V_21 = V_10 -> V_44 -> V_52 ( V_10 ) ;
F_15 ( V_10 ) ;
return 0 ;
}
int
F_24 ( struct V_53 * V_24 )
{
struct V_11 * V_12 = V_11 ( V_24 ) ;
struct V_54 * V_14 = & V_12 -> V_15 . V_14 ;
struct V_23 * V_4 ;
if ( F_25 () ) {
F_26 ( V_12 , L_4 ) ;
return 0 ;
}
F_27 ( & V_12 -> V_32 ) ;
F_28 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_55 != V_56 &&
V_4 -> V_55 != V_57 )
continue;
switch ( V_14 -> V_48 . V_58 ) {
case V_59 :
return F_8 ( V_4 ) ;
case V_60 :
case V_61 :
case V_62 :
case V_63 :
return F_22 ( V_4 ) ;
default:
break;
}
}
return 0 ;
}
void
F_29 ( struct V_53 * V_24 )
{
struct V_11 * V_12 = V_11 ( V_24 ) ;
struct V_3 * V_4 ;
F_28 (connector, &drm->bl_connectors, head) {
if ( V_4 -> V_8 >= 0 )
F_12 ( & V_6 , V_4 -> V_8 ) ;
}
if ( V_12 -> V_33 ) {
F_30 ( V_12 -> V_33 ) ;
V_12 -> V_33 = NULL ;
}
}
void
F_31 ( void )
{
F_32 ( & V_6 ) ;
}
void
F_33 ( void )
{
F_34 ( & V_6 ) ;
}
