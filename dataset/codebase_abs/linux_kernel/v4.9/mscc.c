static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_5 , V_3 ) ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_4 ;
T_2 V_8 ;
T_1 V_9 ;
T_2 V_10 [ 3 ] = { 0 , 0 , 0 } ;
struct V_6 * V_11 = V_7 ;
T_1 * V_12 = V_2 -> V_13 -> V_14 ;
F_4 ( & V_2 -> V_15 ) ;
V_4 = F_1 ( V_2 , V_16 ) ;
if ( V_4 != 0 )
goto V_17;
if ( V_7 -> V_18 & V_19 ) {
for ( V_9 = 0 ; V_9 < F_5 ( V_10 ) ; V_9 ++ )
V_10 [ V_9 ] = V_12 [ 5 - ( V_9 * 2 + 1 ) ] << 8 |
V_12 [ 5 - V_9 * 2 ] ;
F_2 ( V_2 , V_20 , V_10 [ 0 ] ) ;
F_2 ( V_2 , V_21 , V_10 [ 1 ] ) ;
F_2 ( V_2 , V_22 , V_10 [ 2 ] ) ;
} else {
F_2 ( V_2 , V_20 , 0 ) ;
F_2 ( V_2 , V_21 , 0 ) ;
F_2 ( V_2 , V_22 , 0 ) ;
}
if ( V_11 -> V_18 & V_23 ) {
for ( V_9 = 0 ; V_9 < F_5 ( V_10 ) ; V_9 ++ )
V_10 [ V_9 ] = V_11 -> V_24 [ 5 - ( V_9 * 2 + 1 ) ] << 8 |
V_11 -> V_24 [ 5 - V_9 * 2 ] ;
F_2 ( V_2 , V_25 , V_10 [ 0 ] ) ;
F_2 ( V_2 , V_26 , V_10 [ 1 ] ) ;
F_2 ( V_2 , V_27 , V_10 [ 2 ] ) ;
} else {
F_2 ( V_2 , V_25 , 0 ) ;
F_2 ( V_2 , V_26 , 0 ) ;
F_2 ( V_2 , V_27 , 0 ) ;
}
V_8 = F_6 ( V_2 , V_28 ) ;
if ( V_11 -> V_18 & V_23 )
V_8 |= V_29 ;
else
V_8 &= ~ V_29 ;
F_2 ( V_2 , V_28 , V_8 ) ;
V_4 = F_1 ( V_2 , V_30 ) ;
if ( V_4 != 0 )
goto V_17;
if ( V_7 -> V_18 & V_19 ) {
V_8 = F_6 ( V_2 , V_31 ) ;
V_8 |= V_32 ;
V_4 = F_2 ( V_2 , V_31 , V_8 ) ;
if ( V_4 != 0 )
goto V_17;
} else {
V_8 = F_6 ( V_2 , V_31 ) ;
V_8 &= ( ~ V_32 ) ;
V_4 = F_2 ( V_2 , V_31 , V_8 ) ;
if ( V_4 != 0 )
goto V_17;
}
V_8 = F_6 ( V_2 , V_33 ) ;
V_17:
F_7 ( & V_2 -> V_15 ) ;
return V_4 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_4 ;
T_2 V_8 ;
T_1 V_9 ;
T_2 V_10 [ 3 ] = { 0 , 0 , 0 } ;
struct V_6 * V_11 = V_7 ;
F_4 ( & V_2 -> V_15 ) ;
V_4 = F_1 ( V_2 , V_16 ) ;
if ( V_4 != 0 )
goto V_17;
V_8 = F_6 ( V_2 , V_28 ) ;
if ( V_8 & V_29 )
V_11 -> V_18 |= V_23 ;
if ( V_11 -> V_18 & V_23 ) {
V_10 [ 0 ] = F_6 ( V_2 , V_25 ) ;
V_10 [ 1 ] = F_6 ( V_2 , V_26 ) ;
V_10 [ 2 ] = F_6 ( V_2 , V_27 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_10 ) ; V_9 ++ ) {
V_11 -> V_24 [ 5 - V_9 * 2 ] = V_10 [ V_9 ] & 0x00ff ;
V_11 -> V_24 [ 5 - ( V_9 * 2 + 1 ) ] = ( V_10 [ V_9 ] & 0xff00 )
>> 8 ;
}
}
V_4 = F_1 ( V_2 , V_30 ) ;
V_17:
F_7 ( & V_2 -> V_15 ) ;
}
static T_1 F_9 ( T_2 V_34 ,
int V_35 )
{
int V_4 = ( V_36 - 1 ) ;
T_1 V_37 ;
T_1 V_38 ;
for ( V_37 = 0 ; V_37 < V_39 ; V_37 ++ ) {
if ( V_40 [ V_37 ] . V_34 == V_34 ) {
for ( V_38 = 0 ; V_38 < V_36 ; V_38 ++ ) {
if ( V_40 [ V_37 ] . V_35 [ V_38 ] <= V_35 ) {
V_4 = ( V_36 - V_38 - 1 ) ;
break;
}
}
}
}
return V_4 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_41 )
{
int V_4 ;
T_2 V_8 ;
F_4 ( & V_2 -> V_15 ) ;
V_4 = F_1 ( V_2 , V_16 ) ;
if ( V_4 != 0 )
goto V_17;
V_8 = F_6 ( V_2 , V_28 ) ;
V_8 &= ~ ( V_42 ) ;
V_8 |= ( V_41 << V_43 ) ;
V_4 = F_2 ( V_2 , V_28 , V_8 ) ;
if ( V_4 != 0 )
goto V_17;
V_4 = F_1 ( V_2 , V_30 ) ;
V_17:
F_7 ( & V_2 -> V_15 ) ;
return V_4 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_3 V_44 )
{
int V_4 ;
T_2 V_8 ;
F_4 ( & V_2 -> V_15 ) ;
V_8 = F_6 ( V_2 , V_45 ) ;
V_8 &= ~ ( V_46 ) ;
switch ( V_44 ) {
case V_47 :
V_8 |= ( V_48 << V_49 ) ;
break;
case V_50 :
V_8 |= ( V_51 << V_49 ) ;
break;
case V_52 :
case V_53 :
V_8 |= ( V_54 << V_49 ) ;
break;
default:
V_4 = - V_55 ;
goto V_17;
}
V_4 = F_2 ( V_2 , V_45 , V_8 ) ;
if ( V_4 != 0 )
goto V_17;
V_4 = F_12 ( V_2 ) ;
V_17:
F_7 ( & V_2 -> V_15 ) ;
return V_4 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_4 ;
T_2 V_8 ;
F_4 ( & V_2 -> V_15 ) ;
V_4 = F_1 ( V_2 , V_16 ) ;
if ( V_4 != 0 )
goto V_17;
V_8 = F_6 ( V_2 , V_56 ) ;
V_8 &= ~ ( V_57 ) ;
V_8 |= ( V_58 << V_59 ) ;
F_2 ( V_2 , V_56 , V_8 ) ;
V_4 = F_1 ( V_2 , V_30 ) ;
V_17:
F_7 ( & V_2 -> V_15 ) ;
return V_4 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_60 * V_61 = V_2 -> V_62 ;
struct V_63 * V_64 = & V_2 -> V_65 . V_64 ;
struct V_66 * V_67 = V_64 -> V_67 ;
if ( ! V_67 )
return - V_68 ;
V_4 = F_15 ( V_67 , L_1 ,
& V_61 -> V_34 ) ;
if ( V_4 == - V_55 )
V_61 -> V_34 = V_69 ;
V_4 = F_16 ( V_67 , L_2 ,
& V_61 -> V_70 ) ;
if ( V_4 == - V_55 )
V_61 -> V_70 = 0 ;
V_4 = 0 ;
return V_4 ;
}
static int F_14 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_60 * V_61 = V_2 -> V_62 ;
T_1 V_41 ;
V_4 = F_14 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_13 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_11 ( V_2 , V_2 -> V_44 ) ;
if ( V_4 )
return V_4 ;
V_41 = F_9 ( V_61 -> V_34 ,
- ( int ) V_61 -> V_70 ) ;
V_4 = F_10 ( V_2 , V_41 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_18 ( V_2 ) ;
return V_4 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
if ( V_2 -> V_71 == V_72 )
V_4 = F_6 ( V_2 , V_33 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_4 ;
if ( V_2 -> V_71 == V_72 ) {
V_4 = F_2 ( V_2 , V_31 ,
V_73 ) ;
} else {
V_4 = F_2 ( V_2 , V_31 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_6 ( V_2 , V_33 ) ;
}
return V_4 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_60 * V_61 ;
V_61 = F_22 ( & V_2 -> V_65 . V_64 , sizeof( * V_61 ) , V_74 ) ;
if ( ! V_61 )
return - V_75 ;
V_2 -> V_62 = V_61 ;
return 0 ;
}
