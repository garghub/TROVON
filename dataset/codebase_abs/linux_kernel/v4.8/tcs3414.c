static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 25 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 | V_8 ) ;
if ( V_4 < 0 )
return V_4 ;
while ( V_3 -- ) {
V_4 = F_3 ( V_2 -> V_5 , V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 & V_9 )
break;
F_4 ( 20 ) ;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_3 < 0 ) {
F_5 ( & V_2 -> V_5 -> V_10 , L_1 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_6 ( struct V_12 * V_13 ,
struct V_14 const * V_15 ,
int * V_16 , int * V_17 , long V_18 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
int V_19 , V_4 ;
switch ( V_18 ) {
case V_20 :
V_4 = F_8 ( V_13 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 ) {
F_9 ( V_13 ) ;
return V_4 ;
}
V_4 = F_10 ( V_2 -> V_5 , V_15 -> V_21 ) ;
F_9 ( V_13 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_16 = V_4 ;
return V_22 ;
case V_23 :
V_19 = ( V_2 -> V_24 & V_25 ) >> V_26 ;
* V_16 = V_27 [ V_19 ] [ 0 ] ;
* V_17 = V_27 [ V_19 ] [ 1 ] ;
return V_28 ;
case V_29 :
* V_16 = 0 ;
* V_17 = V_30 [ V_2 -> V_31 & V_32 ] * 1000 ;
return V_28 ;
}
return - V_33 ;
}
static int F_11 ( struct V_12 * V_13 ,
struct V_14 const * V_15 ,
int V_16 , int V_17 , long V_18 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
int V_19 ;
switch ( V_18 ) {
case V_23 :
for ( V_19 = 0 ; V_19 < F_12 ( V_27 ) ; V_19 ++ ) {
if ( V_16 == V_27 [ V_19 ] [ 0 ] &&
V_17 == V_27 [ V_19 ] [ 1 ] ) {
V_2 -> V_24 &= ~ V_25 ;
V_2 -> V_24 |= V_19 << V_26 ;
return F_2 (
V_2 -> V_5 , V_34 ,
V_2 -> V_24 ) ;
}
}
return - V_33 ;
case V_29 :
if ( V_16 != 0 )
return - V_33 ;
for ( V_19 = 0 ; V_19 < F_12 ( V_30 ) ; V_19 ++ ) {
if ( V_17 == V_30 [ V_19 ] * 1000 ) {
V_2 -> V_31 &= ~ V_32 ;
V_2 -> V_31 |= V_19 ;
return F_2 (
V_2 -> V_5 , V_35 ,
V_2 -> V_31 ) ;
}
}
return - V_33 ;
default:
return - V_33 ;
}
}
static T_1 F_13 ( int V_36 , void * V_37 )
{
struct V_38 * V_39 = V_37 ;
struct V_12 * V_13 = V_39 -> V_13 ;
struct V_1 * V_2 = F_7 ( V_13 ) ;
int V_19 , V_40 = 0 ;
F_14 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
int V_4 = F_10 ( V_2 -> V_5 ,
V_41 + 2 * V_19 ) ;
if ( V_4 < 0 )
goto V_42;
V_2 -> V_43 [ V_40 ++ ] = V_4 ;
}
F_15 ( V_13 , V_2 -> V_43 ,
F_16 ( V_13 ) ) ;
V_42:
F_17 ( V_13 -> V_44 ) ;
return V_45 ;
}
static int F_18 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
V_2 -> V_7 |= V_8 ;
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 ) ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
int V_4 ;
V_4 = F_20 ( V_13 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_7 &= ~ V_8 ;
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 ) ;
}
static int F_21 ( struct V_46 * V_5 ,
const struct V_47 * V_48 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_4 ;
V_13 = F_22 ( & V_5 -> V_10 , sizeof( * V_2 ) ) ;
if ( V_13 == NULL )
return - V_49 ;
V_2 = F_7 ( V_13 ) ;
F_23 ( V_5 , V_13 ) ;
V_2 -> V_5 = V_5 ;
V_13 -> V_10 . V_50 = & V_5 -> V_10 ;
V_13 -> V_51 = & V_52 ;
V_13 -> V_53 = V_54 ;
V_13 -> V_55 = V_56 ;
V_13 -> V_57 = F_12 ( V_56 ) ;
V_13 -> V_58 = V_59 ;
V_4 = F_3 ( V_2 -> V_5 , V_60 ) ;
if ( V_4 < 0 )
return V_4 ;
switch ( V_4 & 0xf0 ) {
case 0x00 :
F_24 ( & V_5 -> V_10 , L_2 ) ;
break;
case 0x10 :
F_24 ( & V_5 -> V_10 , L_3 ) ;
break;
default:
return - V_61 ;
}
V_2 -> V_7 = V_62 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_31 = V_63 ;
V_4 = F_2 ( V_2 -> V_5 , V_35 ,
V_2 -> V_31 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_3 ( V_2 -> V_5 , V_34 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_24 = V_4 ;
V_4 = F_25 ( V_13 , NULL ,
F_13 , & V_64 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_26 ( V_13 ) ;
if ( V_4 < 0 )
goto V_65;
return 0 ;
V_65:
F_27 ( V_13 ) ;
return V_4 ;
}
static int F_28 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 & ~ ( V_62 |
V_8 ) ) ;
}
static int F_29 ( struct V_46 * V_5 )
{
struct V_12 * V_13 = F_30 ( V_5 ) ;
F_31 ( V_13 ) ;
F_27 ( V_13 ) ;
F_28 ( F_7 ( V_13 ) ) ;
return 0 ;
}
static int F_32 ( struct V_66 * V_10 )
{
struct V_1 * V_2 = F_7 ( F_30 (
F_33 ( V_10 ) ) ) ;
return F_28 ( V_2 ) ;
}
static int F_34 ( struct V_66 * V_10 )
{
struct V_1 * V_2 = F_7 ( F_30 (
F_33 ( V_10 ) ) ) ;
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 ) ;
}
