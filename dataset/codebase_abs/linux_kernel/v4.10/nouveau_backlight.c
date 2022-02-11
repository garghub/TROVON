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
struct V_13 * V_14 = & V_12 -> V_14 . V_15 ;
int V_16 = ( F_5 ( V_14 , V_17 ) &
V_18 ) >> 16 ;
return V_16 ;
}
static int
F_6 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_13 * V_14 = & V_12 -> V_14 . V_15 ;
int V_16 = V_10 -> V_19 . V_20 ;
int V_21 = F_5 ( V_14 , V_17 ) ;
F_7 ( V_14 , V_17 ,
( V_16 << 16 ) | ( V_21 & ~ V_18 ) ) ;
return 0 ;
}
static int
F_8 ( struct V_22 * V_4 )
{
struct V_11 * V_12 = V_11 ( V_4 -> V_23 ) ;
struct V_13 * V_14 = & V_12 -> V_14 . V_15 ;
struct V_24 V_19 ;
struct V_9 * V_10 ;
struct V_3 V_25 ;
char V_1 [ V_2 ] ;
if ( ! ( F_5 ( V_14 , V_17 ) & V_18 ) )
return 0 ;
memset ( & V_19 , 0 , sizeof( struct V_24 ) ) ;
V_19 . type = V_26 ;
V_19 . V_27 = 31 ;
if ( ! F_1 ( V_1 , & V_25 ) ) {
F_9 ( V_12 , L_3 ) ;
return 0 ;
}
V_10 = F_10 ( V_1 , V_4 -> V_28 , V_12 ,
& V_29 , & V_19 ) ;
if ( F_11 ( V_10 ) ) {
if ( V_25 . V_8 > 0 )
F_12 ( & V_6 , V_25 . V_8 ) ;
return F_13 ( V_10 ) ;
}
F_14 ( & V_25 . V_30 , & V_12 -> V_31 ) ;
V_12 -> V_32 = V_10 ;
V_10 -> V_19 . V_20 = F_3 ( V_10 ) ;
F_15 ( V_10 ) ;
return 0 ;
}
static int
F_16 ( struct V_9 * V_10 )
{
struct V_33 * V_34 = F_4 ( V_10 ) ;
struct V_11 * V_12 = V_11 ( V_34 -> V_35 . V_35 . V_23 ) ;
struct V_13 * V_14 = & V_12 -> V_14 . V_15 ;
int V_36 = V_34 -> V_36 ;
T_1 div = 1025 ;
T_1 V_16 ;
V_16 = F_5 ( V_14 , F_17 ( V_36 ) ) ;
V_16 &= V_37 ;
return ( ( V_16 * 100 ) + ( div / 2 ) ) / div ;
}
static int
F_18 ( struct V_9 * V_10 )
{
struct V_33 * V_34 = F_4 ( V_10 ) ;
struct V_11 * V_12 = V_11 ( V_34 -> V_35 . V_35 . V_23 ) ;
struct V_13 * V_14 = & V_12 -> V_14 . V_15 ;
int V_36 = V_34 -> V_36 ;
T_1 div = 1025 ;
T_1 V_16 = ( V_10 -> V_19 . V_20 * div ) / 100 ;
F_7 ( V_14 , F_17 ( V_36 ) ,
V_38 | V_16 ) ;
return 0 ;
}
static int
F_19 ( struct V_9 * V_10 )
{
struct V_33 * V_34 = F_4 ( V_10 ) ;
struct V_11 * V_12 = V_11 ( V_34 -> V_35 . V_35 . V_23 ) ;
struct V_13 * V_14 = & V_12 -> V_14 . V_15 ;
int V_36 = V_34 -> V_36 ;
T_1 div , V_16 ;
div = F_5 ( V_14 , F_20 ( V_36 ) ) ;
V_16 = F_5 ( V_14 , F_17 ( V_36 ) ) ;
V_16 &= V_39 ;
if ( div && div >= V_16 )
return ( ( V_16 * 100 ) + ( div / 2 ) ) / div ;
return 100 ;
}
static int
F_21 ( struct V_9 * V_10 )
{
struct V_33 * V_34 = F_4 ( V_10 ) ;
struct V_11 * V_12 = V_11 ( V_34 -> V_35 . V_35 . V_23 ) ;
struct V_13 * V_14 = & V_12 -> V_14 . V_15 ;
int V_36 = V_34 -> V_36 ;
T_1 div , V_16 ;
div = F_5 ( V_14 , F_20 ( V_36 ) ) ;
V_16 = ( V_10 -> V_19 . V_20 * div ) / 100 ;
if ( div ) {
F_7 ( V_14 , F_17 ( V_36 ) , V_16 |
V_38 |
V_40 ) ;
return 0 ;
}
return - V_41 ;
}
static int
F_22 ( struct V_22 * V_4 )
{
struct V_11 * V_12 = V_11 ( V_4 -> V_23 ) ;
struct V_13 * V_14 = & V_12 -> V_14 . V_15 ;
struct V_33 * V_34 ;
struct V_24 V_19 ;
struct V_9 * V_10 ;
const struct V_42 * V_43 ;
struct V_3 V_25 ;
char V_1 [ V_2 ] ;
V_34 = F_23 ( V_4 , V_44 ) ;
if ( ! V_34 ) {
V_34 = F_23 ( V_4 , V_45 ) ;
if ( ! V_34 )
return - V_46 ;
}
if ( ! F_5 ( V_14 , F_17 ( V_34 -> V_36 ) ) )
return 0 ;
if ( V_12 -> V_14 . V_47 . V_48 <= 0xa0 ||
V_12 -> V_14 . V_47 . V_48 == 0xaa ||
V_12 -> V_14 . V_47 . V_48 == 0xac )
V_43 = & V_49 ;
else
V_43 = & V_50 ;
memset ( & V_19 , 0 , sizeof( struct V_24 ) ) ;
V_19 . type = V_26 ;
V_19 . V_27 = 100 ;
if ( ! F_1 ( V_1 , & V_25 ) ) {
F_9 ( V_12 , L_3 ) ;
return 0 ;
}
V_10 = F_10 ( V_1 , V_4 -> V_28 ,
V_34 , V_43 , & V_19 ) ;
if ( F_11 ( V_10 ) ) {
if ( V_25 . V_8 > 0 )
F_12 ( & V_6 , V_25 . V_8 ) ;
return F_13 ( V_10 ) ;
}
F_14 ( & V_25 . V_30 , & V_12 -> V_31 ) ;
V_12 -> V_32 = V_10 ;
V_10 -> V_19 . V_20 = V_10 -> V_43 -> V_51 ( V_10 ) ;
F_15 ( V_10 ) ;
return 0 ;
}
int
F_24 ( struct V_52 * V_23 )
{
struct V_11 * V_12 = V_11 ( V_23 ) ;
struct V_53 * V_14 = & V_12 -> V_14 ;
struct V_22 * V_4 ;
if ( F_25 () ) {
F_26 ( V_12 , L_4 ) ;
return 0 ;
}
F_27 ( & V_12 -> V_31 ) ;
F_28 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_54 != V_55 &&
V_4 -> V_54 != V_56 )
continue;
switch ( V_14 -> V_47 . V_57 ) {
case V_58 :
return F_8 ( V_4 ) ;
case V_59 :
case V_60 :
case V_61 :
case V_62 :
return F_22 ( V_4 ) ;
default:
break;
}
}
return 0 ;
}
void
F_29 ( struct V_52 * V_23 )
{
struct V_11 * V_12 = V_11 ( V_23 ) ;
struct V_3 * V_4 ;
F_28 (connector, &drm->bl_connectors, head) {
if ( V_4 -> V_8 >= 0 )
F_12 ( & V_6 , V_4 -> V_8 ) ;
}
if ( V_12 -> V_32 ) {
F_30 ( V_12 -> V_32 ) ;
V_12 -> V_32 = NULL ;
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
