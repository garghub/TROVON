static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( F_3 (
F_4 ( V_2 ) ) ) ;
T_1 V_5 [ 2 ] ;
V_5 [ 0 ] = ( V_4 -> V_6 + 1 ) << 4 ;
V_5 [ 1 ] = 0 ;
V_4 -> V_7 = true ;
return F_5 ( V_4 -> V_8 , V_5 , 2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( F_3 (
F_4 ( V_2 ) ) ) ;
T_1 V_5 [ 2 ] ;
V_5 [ 0 ] = ( V_4 -> V_9 >> 8 ) & 0xf ;
V_5 [ 1 ] = V_4 -> V_9 & 0xff ;
V_4 -> V_7 = false ;
return F_5 ( V_4 -> V_8 , V_5 , 2 ) ;
}
static T_2 F_7 ( struct V_1 * V_2 ,
struct V_10 * V_11 , const char * V_12 , T_3 V_13 )
{
struct V_14 * V_15 = F_8 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_15 ) ;
int V_16 = 20 ;
T_1 V_17 [ 3 ] ;
bool V_18 ;
int V_19 ;
V_19 = F_9 ( V_12 , & V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ! V_18 )
return 0 ;
V_17 [ 0 ] = 0x60 ;
V_17 [ 0 ] |= V_4 -> V_20 << 3 ;
V_17 [ 1 ] = V_4 -> V_9 >> 4 ;
V_17 [ 2 ] = ( V_4 -> V_9 & 0xf ) << 4 ;
V_19 = F_5 ( V_4 -> V_8 , V_17 , 3 ) ;
if ( V_19 < 0 )
return V_19 ;
else if ( V_19 != 3 )
return - V_21 ;
while ( V_16 -- ) {
F_10 ( 20 ) ;
V_19 = F_11 ( V_4 -> V_8 , V_17 , 3 ) ;
if ( V_19 < 0 )
return V_19 ;
else if ( V_19 != 3 )
return - V_21 ;
if ( V_17 [ 0 ] & 0x80 )
break;
}
if ( V_16 < 0 ) {
F_12 ( & V_4 -> V_8 -> V_2 ,
L_1 ) ;
return - V_21 ;
}
return V_13 ;
}
static int F_13 ( struct V_14 * V_15 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
return V_4 -> V_6 ;
}
static int F_14 ( struct V_14 * V_15 ,
const struct V_22 * V_23 , unsigned V_24 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
V_4 -> V_6 = V_24 ;
return 0 ;
}
static T_2 F_15 ( struct V_14 * V_15 ,
T_4 V_25 , const struct V_22 * V_23 , char * V_12 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
return sprintf ( V_12 , L_2 , V_4 -> V_7 ) ;
}
static T_2 F_16 ( struct V_14 * V_15 ,
T_4 V_25 , const struct V_22 * V_23 ,
const char * V_12 , T_3 V_13 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
bool V_18 ;
int V_19 ;
V_19 = F_9 ( V_12 , & V_18 ) ;
if ( V_19 )
return V_19 ;
if ( V_18 )
V_19 = F_1 ( & V_4 -> V_8 -> V_2 ) ;
else
V_19 = F_6 ( & V_4 -> V_8 -> V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
return V_13 ;
}
static int F_17 ( struct V_14 * V_15 , int V_26 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
T_1 V_5 [ 2 ] ;
int V_19 ;
if ( V_26 >= ( 1 << 12 ) || V_26 < 0 )
return - V_27 ;
V_5 [ 0 ] = ( V_26 >> 8 ) & 0xf ;
V_5 [ 1 ] = V_26 & 0xff ;
V_19 = F_5 ( V_4 -> V_8 , V_5 , 2 ) ;
if ( V_19 < 0 )
return V_19 ;
else if ( V_19 != 2 )
return - V_21 ;
else
return 0 ;
}
static int F_18 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
T_1 V_5 [ 3 ] ;
int V_19 ;
V_5 [ 0 ] = 0x40 ;
V_5 [ 0 ] |= V_4 -> V_20 << 3 ;
if ( V_4 -> V_7 )
V_5 [ 0 ] |= V_4 -> V_7 << 1 ;
V_5 [ 1 ] = V_4 -> V_9 >> 4 ;
V_5 [ 2 ] = ( V_4 -> V_9 & 0xf ) << 4 ;
V_19 = F_5 ( V_4 -> V_8 , V_5 , 3 ) ;
if ( V_19 < 0 )
return V_19 ;
else if ( V_19 != 3 )
return - V_21 ;
else
return 0 ;
}
static int F_19 ( struct V_14 * V_15 ,
struct V_22 const * V_23 ,
int * V_26 , int * V_28 , long V_29 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
int V_19 ;
switch ( V_29 ) {
case V_30 :
* V_26 = V_4 -> V_9 ;
return V_31 ;
case V_32 :
if ( V_4 -> V_20 == V_33 )
V_19 = F_20 ( V_4 -> V_34 ) ;
else
V_19 = F_20 ( V_4 -> V_35 ) ;
if ( V_19 < 0 )
return V_19 ;
* V_26 = V_19 / 1000 ;
* V_28 = 12 ;
return V_36 ;
}
return - V_27 ;
}
static int F_21 ( struct V_14 * V_15 ,
struct V_22 const * V_23 ,
int V_26 , int V_28 , long V_29 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
int V_19 ;
switch ( V_29 ) {
case V_30 :
V_19 = F_17 ( V_15 , V_26 ) ;
V_4 -> V_9 = V_26 ;
break;
default:
V_19 = - V_27 ;
break;
}
return V_19 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = V_2 -> V_41 ;
if ( ! V_40 )
return - V_42 ;
V_38 -> V_43 = F_23 ( V_40 , L_3 ) ;
V_38 -> V_44 =
F_23 ( V_40 , L_4 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_37 * V_45 )
{
return - V_42 ;
}
static int F_24 ( struct V_46 * V_8 ,
const struct V_47 * V_48 )
{
struct V_3 * V_4 ;
struct V_14 * V_15 ;
struct V_37 * V_38 , V_49 ;
T_1 V_50 [ 4 ] ;
T_1 V_51 ;
T_1 V_52 ;
int V_53 ;
V_15 = F_25 ( & V_8 -> V_2 , sizeof( * V_4 ) ) ;
if ( V_15 == NULL )
return - V_54 ;
V_4 = F_2 ( V_15 ) ;
F_26 ( V_8 , V_15 ) ;
V_4 -> V_8 = V_8 ;
V_4 -> V_48 = V_48 -> V_55 ;
V_38 = F_27 ( & V_8 -> V_2 ) ;
if ( ! V_38 ) {
V_53 = F_22 ( & V_8 -> V_2 , & V_49 ) ;
if ( V_53 ) {
F_12 ( & V_8 -> V_2 ,
L_5 ) ;
return V_53 ;
}
V_38 = & V_49 ;
}
if ( V_4 -> V_48 == V_56 && V_38 -> V_43 ) {
F_12 ( & V_8 -> V_2 ,
L_6 ) ;
return - V_27 ;
}
if ( ! V_38 -> V_43 && V_38 -> V_44 ) {
F_12 ( & V_8 -> V_2 ,
L_7 ) ;
return - V_27 ;
}
if ( ! V_38 -> V_43 )
V_4 -> V_20 = V_33 ;
else
V_4 -> V_20 = V_38 -> V_44 ?
V_57 :
V_58 ;
V_4 -> V_34 = F_28 ( & V_8 -> V_2 , L_8 ) ;
if ( F_29 ( V_4 -> V_34 ) )
return F_30 ( V_4 -> V_34 ) ;
V_53 = F_31 ( V_4 -> V_34 ) ;
if ( V_53 )
return V_53 ;
if ( V_38 -> V_43 ) {
V_4 -> V_35 = F_28 ( & V_8 -> V_2 , L_9 ) ;
if ( F_29 ( V_4 -> V_35 ) ) {
V_53 = F_30 ( V_4 -> V_35 ) ;
goto V_59;
}
V_53 = F_31 ( V_4 -> V_35 ) ;
if ( V_53 )
goto V_59;
}
V_15 -> V_2 . V_60 = & V_8 -> V_2 ;
V_15 -> V_61 = V_48 -> V_61 ;
V_15 -> V_62 = & V_63 ;
V_15 -> V_64 = & V_65 [ V_48 -> V_55 ] ;
V_15 -> V_66 = 1 ;
V_15 -> V_67 = V_68 ;
V_53 = F_11 ( V_8 , V_50 , V_4 -> V_48 == V_56 ? 3 : 4 ) ;
if ( V_53 < 0 ) {
F_12 ( & V_8 -> V_2 , L_10 ) ;
goto V_69;
}
V_51 = ( V_50 [ 0 ] >> 1 ) & 0x3 ;
V_4 -> V_7 = V_51 > 0 ? true : false ;
V_4 -> V_6 = V_51 ? V_51 - 1 : 2 ;
V_4 -> V_9 = ( V_50 [ 1 ] << 4 ) | ( V_50 [ 2 ] >> 4 ) ;
if ( V_4 -> V_48 == V_70 )
V_52 = ( V_50 [ 3 ] >> 3 ) & 0x3 ;
if ( V_4 -> V_48 == V_70 && V_52 != V_4 -> V_20 ) {
F_32 ( & V_8 -> V_2 ,
L_11 ,
V_4 -> V_20 , V_52 , V_4 -> V_20 ) ;
V_53 = F_18 ( V_15 ) ;
if ( V_53 < 0 )
goto V_69;
}
V_53 = F_33 ( V_15 ) ;
if ( V_53 )
goto V_69;
return 0 ;
V_69:
if ( V_4 -> V_35 )
F_34 ( V_4 -> V_35 ) ;
V_59:
F_34 ( V_4 -> V_34 ) ;
return V_53 ;
}
static int F_35 ( struct V_46 * V_8 )
{
struct V_14 * V_15 = F_3 ( V_8 ) ;
struct V_3 * V_4 = F_2 ( V_15 ) ;
F_36 ( V_15 ) ;
if ( V_4 -> V_35 )
F_34 ( V_4 -> V_35 ) ;
F_34 ( V_4 -> V_34 ) ;
return 0 ;
}
