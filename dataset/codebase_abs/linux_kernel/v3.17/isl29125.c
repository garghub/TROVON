static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 5 ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_7 ,
V_2 -> V_8 | V_9 [ V_3 ] . V_10 ) ;
if ( V_5 < 0 )
return V_5 ;
F_3 ( 101 ) ;
while ( V_4 -- ) {
V_5 = F_4 ( V_2 -> V_6 , V_11 ) ;
if ( V_5 < 0 )
goto V_12;
if ( V_5 & V_13 )
break;
F_3 ( 20 ) ;
}
if ( V_4 < 0 ) {
F_5 ( & V_2 -> V_6 -> V_14 , L_1 ) ;
V_5 = - V_15 ;
goto V_12;
}
V_5 = F_6 ( V_2 -> V_6 , V_9 [ V_3 ] . V_2 ) ;
V_12:
F_2 ( V_2 -> V_6 , V_7 , V_2 -> V_8 ) ;
return V_5 ;
}
static int F_7 ( struct V_16 * V_17 ,
struct V_18 const * V_19 ,
int * V_20 , int * V_21 , long V_22 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
int V_5 ;
switch ( V_22 ) {
case V_23 :
if ( F_9 ( V_17 ) )
return - V_24 ;
F_10 ( & V_2 -> V_25 ) ;
V_5 = F_1 ( V_2 , V_19 -> V_26 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_20 = V_5 ;
return V_27 ;
case V_28 :
* V_20 = 0 ;
if ( V_2 -> V_8 & V_29 )
* V_21 = 152590 ;
else
* V_21 = 5722 ;
return V_30 ;
}
return - V_31 ;
}
static int F_12 ( struct V_16 * V_17 ,
struct V_18 const * V_19 ,
int V_20 , int V_21 , long V_22 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
switch ( V_22 ) {
case V_28 :
if ( V_20 != 0 )
return - V_31 ;
if ( V_21 == 152590 )
V_2 -> V_8 |= V_29 ;
else if ( V_21 == 5722 )
V_2 -> V_8 &= ~ V_29 ;
else
return - V_31 ;
return F_2 ( V_2 -> V_6 , V_7 ,
V_2 -> V_8 ) ;
default:
return - V_31 ;
}
}
static T_1 F_13 ( int V_32 , void * V_33 )
{
struct V_34 * V_35 = V_33 ;
struct V_16 * V_17 = V_35 -> V_17 ;
struct V_1 * V_2 = F_8 ( V_17 ) ;
int V_36 , V_37 = 0 ;
F_14 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
int V_5 = F_6 ( V_2 -> V_6 ,
V_9 [ V_36 ] . V_2 ) ;
if ( V_5 < 0 )
goto V_38;
V_2 -> V_39 [ V_37 ++ ] = V_5 ;
}
F_15 ( V_17 , V_2 -> V_39 ,
F_16 () ) ;
V_38:
F_17 ( V_17 -> V_40 ) ;
return V_41 ;
}
static int F_18 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
V_2 -> V_8 |= V_42 ;
return F_2 ( V_2 -> V_6 , V_7 ,
V_2 -> V_8 ) ;
}
static int F_19 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
int V_5 ;
V_5 = F_20 ( V_17 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_8 &= ~ V_43 ;
V_2 -> V_8 |= V_44 ;
return F_2 ( V_2 -> V_6 , V_7 ,
V_2 -> V_8 ) ;
}
static int F_21 ( struct V_45 * V_6 ,
const struct V_46 * V_47 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
int V_5 ;
V_17 = F_22 ( & V_6 -> V_14 , sizeof( * V_2 ) ) ;
if ( V_17 == NULL )
return - V_48 ;
V_2 = F_8 ( V_17 ) ;
F_23 ( V_6 , V_17 ) ;
V_2 -> V_6 = V_6 ;
F_24 ( & V_2 -> V_25 ) ;
V_17 -> V_14 . V_49 = & V_6 -> V_14 ;
V_17 -> V_50 = & V_51 ;
V_17 -> V_52 = V_53 ;
V_17 -> V_54 = V_55 ;
V_17 -> V_56 = F_25 ( V_55 ) ;
V_17 -> V_57 = V_58 ;
V_5 = F_4 ( V_2 -> V_6 , V_59 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != V_60 )
return - V_61 ;
V_2 -> V_8 = V_44 | V_29 ;
V_5 = F_2 ( V_2 -> V_6 , V_7 ,
V_2 -> V_8 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_11 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_26 ( V_17 , NULL ,
F_13 , & V_62 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_27 ( V_17 ) ;
if ( V_5 < 0 )
goto V_63;
return 0 ;
V_63:
F_28 ( V_17 ) ;
return V_5 ;
}
static int F_29 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_6 , V_7 ,
( V_2 -> V_8 & ~ V_43 ) | V_44 ) ;
}
static int F_30 ( struct V_45 * V_6 )
{
struct V_16 * V_17 = F_31 ( V_6 ) ;
F_32 ( V_17 ) ;
F_28 ( V_17 ) ;
F_29 ( F_8 ( V_17 ) ) ;
return 0 ;
}
static int F_33 ( struct V_64 * V_14 )
{
struct V_1 * V_2 = F_8 ( F_31 (
F_34 ( V_14 ) ) ) ;
return F_29 ( V_2 ) ;
}
static int F_35 ( struct V_64 * V_14 )
{
struct V_1 * V_2 = F_8 ( F_31 (
F_34 ( V_14 ) ) ) ;
return F_2 ( V_2 -> V_6 , V_7 ,
V_2 -> V_8 ) ;
}
