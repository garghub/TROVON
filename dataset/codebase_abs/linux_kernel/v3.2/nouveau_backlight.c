static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = ( F_3 ( V_4 , V_6 ) & V_7 )
>> 16 ;
return V_5 ;
}
static int
F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_2 -> V_8 . V_9 ;
int V_10 = F_3 ( V_4 , V_6 ) ;
F_5 ( V_4 , V_6 ,
( V_5 << 16 ) | ( V_10 & ~ V_7 ) ) ;
return 0 ;
}
static int
F_6 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = V_12 -> V_4 ;
struct V_13 * V_14 = V_4 -> V_15 ;
struct V_16 V_8 ;
struct V_1 * V_2 ;
if ( ! ( F_3 ( V_4 , V_6 ) & V_7 ) )
return 0 ;
memset ( & V_8 , 0 , sizeof( struct V_16 ) ) ;
V_8 . type = V_17 ;
V_8 . V_18 = 31 ;
V_2 = F_7 ( L_1 , & V_12 -> V_19 , V_4 ,
& V_20 , & V_8 ) ;
if ( F_8 ( V_2 ) )
return F_9 ( V_2 ) ;
V_14 -> V_21 = V_2 ;
V_2 -> V_8 . V_9 = F_1 ( V_2 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_23 -> V_24 . V_24 . V_4 ;
int V_25 = V_23 -> V_25 ;
T_1 div = 1025 ;
T_1 V_5 ;
V_5 = F_3 ( V_4 , F_12 ( V_25 ) ) ;
V_5 &= V_26 ;
return ( ( V_5 * 100 ) + ( div / 2 ) ) / div ;
}
static int
F_13 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_23 -> V_24 . V_24 . V_4 ;
int V_25 = V_23 -> V_25 ;
T_1 div = 1025 ;
T_1 V_5 = ( V_2 -> V_8 . V_9 * div ) / 100 ;
F_5 ( V_4 , F_12 ( V_25 ) ,
V_27 | V_5 ) ;
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_23 -> V_24 . V_24 . V_4 ;
int V_25 = V_23 -> V_25 ;
T_1 div , V_5 ;
div = F_3 ( V_4 , F_15 ( V_25 ) ) ;
V_5 = F_3 ( V_4 , F_12 ( V_25 ) ) ;
V_5 &= V_28 ;
if ( div && div >= V_5 )
return ( ( V_5 * 100 ) + ( div / 2 ) ) / div ;
return 100 ;
}
static int
F_16 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_23 -> V_24 . V_24 . V_4 ;
int V_25 = V_23 -> V_25 ;
T_1 div , V_5 ;
div = F_3 ( V_4 , F_15 ( V_25 ) ) ;
V_5 = ( V_2 -> V_8 . V_9 * div ) / 100 ;
if ( div ) {
F_5 ( V_4 , F_12 ( V_25 ) , V_5 |
V_27 |
V_29 ) ;
return 0 ;
}
return - V_30 ;
}
static int
F_17 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = V_12 -> V_4 ;
struct V_13 * V_14 = V_4 -> V_15 ;
struct V_22 * V_23 ;
struct V_16 V_8 ;
struct V_1 * V_2 ;
const struct V_31 * V_32 ;
V_23 = F_18 ( V_12 , V_33 ) ;
if ( ! V_23 ) {
V_23 = F_18 ( V_12 , V_34 ) ;
if ( ! V_23 )
return - V_35 ;
}
if ( ! F_3 ( V_4 , F_12 ( V_23 -> V_25 ) ) )
return 0 ;
if ( V_14 -> V_36 <= 0xa0 ||
V_14 -> V_36 == 0xaa ||
V_14 -> V_36 == 0xac )
V_32 = & V_37 ;
else
V_32 = & V_38 ;
memset ( & V_8 , 0 , sizeof( struct V_16 ) ) ;
V_8 . type = V_17 ;
V_8 . V_18 = 100 ;
V_2 = F_7 ( L_1 , & V_12 -> V_19 ,
V_23 , V_32 , & V_8 ) ;
if ( F_8 ( V_2 ) )
return F_9 ( V_2 ) ;
V_14 -> V_21 = V_2 ;
V_2 -> V_8 . V_9 = V_2 -> V_32 -> V_39 ( V_2 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
int
F_19 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_15 ;
struct V_11 * V_12 ;
#ifdef F_20
if ( F_21 () ) {
F_22 ( V_4 , L_2
L_3 ) ;
return 0 ;
}
#endif
F_23 (connector, &dev->mode_config.connector_list, head) {
if ( V_12 -> V_40 != V_41 &&
V_12 -> V_40 != V_42 )
continue;
switch ( V_14 -> V_43 ) {
case V_44 :
return F_6 ( V_12 ) ;
case V_45 :
return F_17 ( V_12 ) ;
default:
break;
}
}
return 0 ;
}
void
F_24 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_15 ;
if ( V_14 -> V_21 ) {
F_25 ( V_14 -> V_21 ) ;
V_14 -> V_21 = NULL ;
}
}
