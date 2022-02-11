static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 . V_7 ;
int V_8 = ( F_3 ( V_6 , V_9 ) &
V_10 ) >> 16 ;
return V_8 ;
}
static int
F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 . V_7 ;
int V_8 = V_2 -> V_11 . V_12 ;
int V_13 = F_3 ( V_6 , V_9 ) ;
F_5 ( V_6 , V_9 ,
( V_8 << 16 ) | ( V_13 & ~ V_10 ) ) ;
return 0 ;
}
static int
F_6 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = V_3 ( V_15 -> V_16 ) ;
struct V_5 * V_6 = & V_4 -> V_6 . V_7 ;
struct V_17 V_11 ;
struct V_1 * V_2 ;
if ( ! ( F_3 ( V_6 , V_9 ) & V_10 ) )
return 0 ;
memset ( & V_11 , 0 , sizeof( struct V_17 ) ) ;
V_11 . type = V_18 ;
V_11 . V_19 = 31 ;
V_2 = F_7 ( L_1 , V_15 -> V_20 , V_4 ,
& V_21 , & V_11 ) ;
if ( F_8 ( V_2 ) )
return F_9 ( V_2 ) ;
V_4 -> V_22 = V_2 ;
V_2 -> V_11 . V_12 = F_1 ( V_2 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_3 ( V_24 -> V_25 . V_25 . V_16 ) ;
struct V_5 * V_6 = & V_4 -> V_6 . V_7 ;
int V_26 = V_24 -> V_26 ;
T_1 div = 1025 ;
T_1 V_8 ;
V_8 = F_3 ( V_6 , F_12 ( V_26 ) ) ;
V_8 &= V_27 ;
return ( ( V_8 * 100 ) + ( div / 2 ) ) / div ;
}
static int
F_13 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_3 ( V_24 -> V_25 . V_25 . V_16 ) ;
struct V_5 * V_6 = & V_4 -> V_6 . V_7 ;
int V_26 = V_24 -> V_26 ;
T_1 div = 1025 ;
T_1 V_8 = ( V_2 -> V_11 . V_12 * div ) / 100 ;
F_5 ( V_6 , F_12 ( V_26 ) ,
V_28 | V_8 ) ;
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_3 ( V_24 -> V_25 . V_25 . V_16 ) ;
struct V_5 * V_6 = & V_4 -> V_6 . V_7 ;
int V_26 = V_24 -> V_26 ;
T_1 div , V_8 ;
div = F_3 ( V_6 , F_15 ( V_26 ) ) ;
V_8 = F_3 ( V_6 , F_12 ( V_26 ) ) ;
V_8 &= V_29 ;
if ( div && div >= V_8 )
return ( ( V_8 * 100 ) + ( div / 2 ) ) / div ;
return 100 ;
}
static int
F_16 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_3 ( V_24 -> V_25 . V_25 . V_16 ) ;
struct V_5 * V_6 = & V_4 -> V_6 . V_7 ;
int V_26 = V_24 -> V_26 ;
T_1 div , V_8 ;
div = F_3 ( V_6 , F_15 ( V_26 ) ) ;
V_8 = ( V_2 -> V_11 . V_12 * div ) / 100 ;
if ( div ) {
F_5 ( V_6 , F_12 ( V_26 ) , V_8 |
V_28 |
V_30 ) ;
return 0 ;
}
return - V_31 ;
}
static int
F_17 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = V_3 ( V_15 -> V_16 ) ;
struct V_5 * V_6 = & V_4 -> V_6 . V_7 ;
struct V_23 * V_24 ;
struct V_17 V_11 ;
struct V_1 * V_2 ;
const struct V_32 * V_33 ;
V_24 = F_18 ( V_15 , V_34 ) ;
if ( ! V_24 ) {
V_24 = F_18 ( V_15 , V_35 ) ;
if ( ! V_24 )
return - V_36 ;
}
if ( ! F_3 ( V_6 , F_12 ( V_24 -> V_26 ) ) )
return 0 ;
if ( V_4 -> V_6 . V_37 . V_38 <= 0xa0 ||
V_4 -> V_6 . V_37 . V_38 == 0xaa ||
V_4 -> V_6 . V_37 . V_38 == 0xac )
V_33 = & V_39 ;
else
V_33 = & V_40 ;
memset ( & V_11 , 0 , sizeof( struct V_17 ) ) ;
V_11 . type = V_18 ;
V_11 . V_19 = 100 ;
V_2 = F_7 ( L_1 , V_15 -> V_20 ,
V_24 , V_33 , & V_11 ) ;
if ( F_8 ( V_2 ) )
return F_9 ( V_2 ) ;
V_4 -> V_22 = V_2 ;
V_2 -> V_11 . V_12 = V_2 -> V_33 -> V_41 ( V_2 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
int
F_19 ( struct V_42 * V_16 )
{
struct V_3 * V_4 = V_3 ( V_16 ) ;
struct V_43 * V_6 = & V_4 -> V_6 ;
struct V_14 * V_15 ;
F_20 (connector, &dev->mode_config.connector_list, head) {
if ( V_15 -> V_44 != V_45 &&
V_15 -> V_44 != V_46 )
continue;
switch ( V_6 -> V_37 . V_47 ) {
case V_48 :
return F_6 ( V_15 ) ;
case V_49 :
case V_50 :
case V_51 :
return F_17 ( V_15 ) ;
default:
break;
}
}
return 0 ;
}
void
F_21 ( struct V_42 * V_16 )
{
struct V_3 * V_4 = V_3 ( V_16 ) ;
if ( V_4 -> V_22 ) {
F_22 ( V_4 -> V_22 ) ;
V_4 -> V_22 = NULL ;
}
}
