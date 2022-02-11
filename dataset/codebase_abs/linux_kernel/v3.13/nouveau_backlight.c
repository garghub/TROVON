static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
int V_7 = ( F_4 ( V_6 , V_8 ) &
V_9 ) >> 16 ;
return V_7 ;
}
static int
F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
int V_7 = V_2 -> V_10 . V_11 ;
int V_12 = F_4 ( V_6 , V_8 ) ;
F_6 ( V_6 , V_8 ,
( V_7 << 16 ) | ( V_12 & ~ V_9 ) ) ;
return 0 ;
}
static int
F_7 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = V_3 ( V_14 -> V_15 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
struct V_16 V_10 ;
struct V_1 * V_2 ;
if ( ! ( F_4 ( V_6 , V_8 ) & V_9 ) )
return 0 ;
memset ( & V_10 , 0 , sizeof( struct V_16 ) ) ;
V_10 . type = V_17 ;
V_10 . V_18 = 31 ;
V_2 = F_8 ( L_1 , V_14 -> V_19 , V_4 ,
& V_20 , & V_10 ) ;
if ( F_9 ( V_2 ) )
return F_10 ( V_2 ) ;
V_4 -> V_21 = V_2 ;
V_2 -> V_10 . V_11 = F_1 ( V_2 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_3 ( V_23 -> V_24 . V_24 . V_15 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
int V_25 = V_23 -> V_25 ;
T_1 div = 1025 ;
T_1 V_7 ;
V_7 = F_4 ( V_6 , F_13 ( V_25 ) ) ;
V_7 &= V_26 ;
return ( ( V_7 * 100 ) + ( div / 2 ) ) / div ;
}
static int
F_14 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_3 ( V_23 -> V_24 . V_24 . V_15 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
int V_25 = V_23 -> V_25 ;
T_1 div = 1025 ;
T_1 V_7 = ( V_2 -> V_10 . V_11 * div ) / 100 ;
F_6 ( V_6 , F_13 ( V_25 ) ,
V_27 | V_7 ) ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_3 ( V_23 -> V_24 . V_24 . V_15 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
int V_25 = V_23 -> V_25 ;
T_1 div , V_7 ;
div = F_4 ( V_6 , F_16 ( V_25 ) ) ;
V_7 = F_4 ( V_6 , F_13 ( V_25 ) ) ;
V_7 &= V_28 ;
if ( div && div >= V_7 )
return ( ( V_7 * 100 ) + ( div / 2 ) ) / div ;
return 100 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_3 ( V_23 -> V_24 . V_24 . V_15 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
int V_25 = V_23 -> V_25 ;
T_1 div , V_7 ;
div = F_4 ( V_6 , F_16 ( V_25 ) ) ;
V_7 = ( V_2 -> V_10 . V_11 * div ) / 100 ;
if ( div ) {
F_6 ( V_6 , F_13 ( V_25 ) , V_7 |
V_27 |
V_29 ) ;
return 0 ;
}
return - V_30 ;
}
static int
F_18 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = V_3 ( V_14 -> V_15 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
struct V_22 * V_23 ;
struct V_16 V_10 ;
struct V_1 * V_2 ;
const struct V_31 * V_32 ;
V_23 = F_19 ( V_14 , V_33 ) ;
if ( ! V_23 ) {
V_23 = F_19 ( V_14 , V_34 ) ;
if ( ! V_23 )
return - V_35 ;
}
if ( ! F_4 ( V_6 , F_13 ( V_23 -> V_25 ) ) )
return 0 ;
if ( V_6 -> V_36 <= 0xa0 ||
V_6 -> V_36 == 0xaa ||
V_6 -> V_36 == 0xac )
V_32 = & V_37 ;
else
V_32 = & V_38 ;
memset ( & V_10 , 0 , sizeof( struct V_16 ) ) ;
V_10 . type = V_17 ;
V_10 . V_18 = 100 ;
V_2 = F_8 ( L_1 , V_14 -> V_19 ,
V_23 , V_32 , & V_10 ) ;
if ( F_9 ( V_2 ) )
return F_10 ( V_2 ) ;
V_4 -> V_21 = V_2 ;
V_2 -> V_10 . V_11 = V_2 -> V_32 -> V_39 ( V_2 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
int
F_20 ( struct V_40 * V_15 )
{
struct V_3 * V_4 = V_3 ( V_15 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
struct V_13 * V_14 ;
#ifdef F_21
if ( F_22 () ) {
F_23 ( V_4 , L_2
L_3 ) ;
return 0 ;
}
#endif
F_24 (connector, &dev->mode_config.connector_list, head) {
if ( V_14 -> V_41 != V_42 &&
V_14 -> V_41 != V_43 )
continue;
switch ( V_6 -> V_44 ) {
case V_45 :
return F_7 ( V_14 ) ;
case V_46 :
case V_47 :
case V_48 :
case V_49 :
return F_18 ( V_14 ) ;
default:
break;
}
}
return 0 ;
}
void
F_25 ( struct V_40 * V_15 )
{
struct V_3 * V_4 = V_3 ( V_15 ) ;
if ( V_4 -> V_21 ) {
F_26 ( V_4 -> V_21 ) ;
V_4 -> V_21 = NULL ;
}
}
