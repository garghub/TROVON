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
if ( F_8 ( V_13 ) )
return - V_21 ;
F_9 ( & V_2 -> V_22 ) ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 ) {
F_10 ( & V_2 -> V_22 ) ;
return V_4 ;
}
V_4 = F_11 ( V_2 -> V_5 , V_15 -> V_23 ) ;
F_10 ( & V_2 -> V_22 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_16 = V_4 ;
return V_24 ;
case V_25 :
V_19 = ( V_2 -> V_26 & V_27 ) >> V_28 ;
* V_16 = V_29 [ V_19 ] [ 0 ] ;
* V_17 = V_29 [ V_19 ] [ 1 ] ;
return V_30 ;
case V_31 :
* V_16 = 0 ;
* V_17 = V_32 [ V_2 -> V_33 & V_34 ] * 1000 ;
return V_30 ;
}
return - V_35 ;
}
static int F_12 ( struct V_12 * V_13 ,
struct V_14 const * V_15 ,
int V_16 , int V_17 , long V_18 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
int V_19 ;
switch ( V_18 ) {
case V_25 :
for ( V_19 = 0 ; V_19 < F_13 ( V_29 ) ; V_19 ++ ) {
if ( V_16 == V_29 [ V_19 ] [ 0 ] &&
V_17 == V_29 [ V_19 ] [ 1 ] ) {
V_2 -> V_26 &= ~ V_27 ;
V_2 -> V_26 |= V_19 << V_28 ;
return F_2 (
V_2 -> V_5 , V_36 ,
V_2 -> V_26 ) ;
}
}
return - V_35 ;
case V_31 :
if ( V_16 != 0 )
return - V_35 ;
for ( V_19 = 0 ; V_19 < F_13 ( V_32 ) ; V_19 ++ ) {
if ( V_16 == V_32 [ V_19 ] * 1000 ) {
V_2 -> V_33 &= ~ V_34 ;
V_2 -> V_33 |= V_19 ;
return F_2 (
V_2 -> V_5 , V_37 ,
V_2 -> V_33 ) ;
}
}
return - V_35 ;
default:
return - V_35 ;
}
}
static T_1 F_14 ( int V_38 , void * V_39 )
{
struct V_40 * V_41 = V_39 ;
struct V_12 * V_13 = V_41 -> V_13 ;
struct V_1 * V_2 = F_7 ( V_13 ) ;
int V_19 , V_42 = 0 ;
F_15 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
int V_4 = F_11 ( V_2 -> V_5 ,
V_43 + 2 * V_19 ) ;
if ( V_4 < 0 )
goto V_44;
V_2 -> V_45 [ V_42 ++ ] = V_4 ;
}
F_16 ( V_13 , V_2 -> V_45 ,
F_17 () ) ;
V_44:
F_18 ( V_13 -> V_46 ) ;
return V_47 ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
V_2 -> V_7 |= V_8 ;
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 ) ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
int V_4 ;
V_4 = F_21 ( V_13 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_7 &= ~ V_8 ;
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 ) ;
}
static int F_22 ( struct V_48 * V_5 ,
const struct V_49 * V_50 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_4 ;
V_13 = F_23 ( & V_5 -> V_10 , sizeof( * V_2 ) ) ;
if ( V_13 == NULL )
return - V_51 ;
V_2 = F_7 ( V_13 ) ;
F_24 ( V_5 , V_13 ) ;
V_2 -> V_5 = V_5 ;
F_25 ( & V_2 -> V_22 ) ;
V_13 -> V_10 . V_52 = & V_5 -> V_10 ;
V_13 -> V_53 = & V_54 ;
V_13 -> V_55 = V_56 ;
V_13 -> V_57 = V_58 ;
V_13 -> V_59 = F_13 ( V_58 ) ;
V_13 -> V_60 = V_61 ;
V_4 = F_3 ( V_2 -> V_5 , V_62 ) ;
if ( V_4 < 0 )
return V_4 ;
switch ( V_4 & 0xf0 ) {
case 0x00 :
F_26 ( & V_5 -> V_10 , L_2 ) ;
break;
case 0x10 :
F_26 ( & V_5 -> V_10 , L_3 ) ;
break;
default:
return - V_63 ;
}
V_2 -> V_7 = V_64 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_33 = V_65 ;
V_4 = F_2 ( V_2 -> V_5 , V_37 ,
V_2 -> V_33 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_3 ( V_2 -> V_5 , V_36 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_26 = V_4 ;
V_4 = F_27 ( V_13 , NULL ,
F_14 , & V_66 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_28 ( V_13 ) ;
if ( V_4 < 0 )
goto V_67;
return 0 ;
V_67:
F_29 ( V_13 ) ;
return V_4 ;
}
static int F_30 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 & ~ ( V_64 |
V_8 ) ) ;
}
static int F_31 ( struct V_48 * V_5 )
{
struct V_12 * V_13 = F_32 ( V_5 ) ;
F_33 ( V_13 ) ;
F_29 ( V_13 ) ;
F_30 ( F_7 ( V_13 ) ) ;
return 0 ;
}
static int F_34 ( struct V_68 * V_10 )
{
struct V_1 * V_2 = F_7 ( F_32 (
F_35 ( V_10 ) ) ) ;
return F_30 ( V_2 ) ;
}
static int F_36 ( struct V_68 * V_10 )
{
struct V_1 * V_2 = F_7 ( F_32 (
F_35 ( V_10 ) ) ) ;
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 ) ;
}
