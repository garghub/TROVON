static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
int V_5 ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 -> V_6 , V_3 , 1 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return V_2 -> V_6 -> V_8 ( V_2 -> V_6 , V_3 , 1 , & V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
int V_5 , V_10 ;
F_4 ( & V_2 -> V_11 ) ;
V_10 = F_1 ( V_2 , V_3 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_6 -> V_12 , L_1 , V_3 ) ;
V_5 = V_10 ;
goto V_13;
}
V_10 |= V_9 ;
V_5 = F_2 ( V_2 , V_3 , V_10 ) ;
if ( V_5 )
F_5 ( V_2 -> V_6 -> V_12 , L_2 , V_3 ) ;
V_13:
F_6 ( & V_2 -> V_11 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
int V_5 , V_10 ;
F_4 ( & V_2 -> V_11 ) ;
V_10 = F_1 ( V_2 , V_3 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_6 -> V_12 , L_1 , V_3 ) ;
V_5 = V_10 ;
goto V_13;
}
V_10 &= ~ V_9 ;
V_5 = F_2 ( V_2 , V_3 , V_10 ) ;
if ( V_5 )
F_5 ( V_2 -> V_6 -> V_12 , L_2 , V_3 ) ;
V_13:
F_6 ( & V_2 -> V_11 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_10 ;
F_4 ( & V_2 -> V_11 ) ;
V_10 = F_1 ( V_2 , V_3 ) ;
if ( V_10 < 0 )
F_5 ( V_2 -> V_6 -> V_12 , L_1 , V_3 ) ;
F_6 ( & V_2 -> V_11 ) ;
return V_10 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
F_4 ( & V_2 -> V_11 ) ;
V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
F_5 ( V_2 -> V_6 -> V_12 , L_2 , V_3 ) ;
F_6 ( & V_2 -> V_11 ) ;
return V_5 ;
}
static int F_10 ( struct V_14 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_10 , V_15 = F_12 ( V_12 ) ;
T_1 V_16 ;
if ( V_15 < V_17 || V_15 > V_18 )
return - V_19 ;
V_16 = V_20 - V_15 ;
V_10 = F_8 ( V_2 , V_21 ) ;
if ( V_10 < 0 )
return V_10 ;
else
return ( V_10 & 1 << V_16 ) ? 1 : 0 ;
}
static int F_13 ( struct V_14 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_10 , V_22 = F_12 ( V_12 ) ;
T_1 V_16 ;
if ( V_22 < V_23 || V_22 > V_24 )
return - V_19 ;
V_16 = V_20 - V_22 ;
V_10 = F_8 ( V_2 , V_21 ) ;
if ( V_10 < 0 )
return V_10 ;
else
return ( V_10 & 1 << V_16 ) ? 1 : 0 ;
}
static int F_14 ( struct V_14 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_15 = F_12 ( V_12 ) ;
T_1 V_16 ;
if ( V_15 < V_17 || V_15 > V_18 )
return - V_19 ;
V_16 = V_20 - V_15 ;
return F_3 ( V_2 , V_21 , 1 << V_16 ) ;
}
static int F_15 ( struct V_14 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_15 = F_12 ( V_12 ) ;
T_1 V_16 ;
if ( V_15 < V_17 || V_15 > V_18 )
return - V_19 ;
V_16 = V_20 - V_15 ;
return F_7 ( V_2 , V_21 ,
1 << V_16 ) ;
}
static int F_16 ( struct V_14 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_22 = F_12 ( V_12 ) ;
T_1 V_16 ;
if ( V_22 < V_23 || V_22 > V_24 )
return - V_19 ;
V_16 = V_20 - V_22 ;
return F_3 ( V_2 , V_21 , 1 << V_16 ) ;
}
static int F_17 ( struct V_14 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_22 = F_12 ( V_12 ) ;
T_1 V_16 ;
if ( V_22 < V_23 || V_22 > V_24 )
return - V_19 ;
V_16 = V_20 - V_22 ;
return F_7 ( V_2 , V_21 ,
1 << V_16 ) ;
}
static int F_18 ( struct V_14 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_10 , V_15 = F_12 ( V_12 ) ;
T_1 V_3 ;
switch ( V_15 ) {
case V_17 :
V_3 = V_25 ;
break;
case V_26 :
if ( V_2 -> V_27 [ V_15 ] -> V_28 )
V_3 = V_29 ;
else
V_3 = V_30 ;
break;
case V_18 :
if ( V_2 -> V_27 [ V_15 ] -> V_28 )
V_3 = V_31 ;
else
V_3 = V_32 ;
break;
default:
return - V_19 ;
}
V_10 = F_8 ( V_2 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= V_33 ;
return V_2 -> V_27 [ V_15 ] -> V_34 [ V_10 ] * 1000 ;
}
static int F_19 ( struct V_14 * V_12 ,
int V_35 , int V_36 ,
unsigned * V_37 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_10 , V_38 , V_15 = F_12 ( V_12 ) ;
T_1 V_3 ;
switch ( V_15 ) {
case V_17 :
V_3 = V_25 ;
break;
case V_26 :
if ( V_2 -> V_27 [ V_15 ] -> V_28 )
V_3 = V_29 ;
else
V_3 = V_30 ;
break;
case V_18 :
if ( V_2 -> V_27 [ V_15 ] -> V_28 )
V_3 = V_31 ;
else
V_3 = V_32 ;
break;
default:
return - V_19 ;
}
if ( V_35 < V_2 -> V_27 [ V_15 ] -> V_35
|| V_35 > V_2 -> V_27 [ V_15 ] -> V_36 )
return - V_19 ;
if ( V_36 < V_2 -> V_27 [ V_15 ] -> V_35
|| V_36 > V_2 -> V_27 [ V_15 ] -> V_36 )
return - V_19 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_27 [ V_15 ] -> V_39 ; V_38 ++ ) {
int V_40 = V_2 -> V_27 [ V_15 ] -> V_34 [ V_38 ] ;
int V_41 = V_40 * 1000 ;
if ( V_35 <= V_41 && V_41 <= V_36 )
break;
}
if ( V_38 == V_2 -> V_27 [ V_15 ] -> V_39 )
return - V_19 ;
* V_37 = V_38 ;
V_10 = F_8 ( V_2 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ~ V_33 ;
V_10 |= V_38 ;
return F_9 ( V_2 , V_3 , V_10 ) ;
}
static int F_20 ( struct V_14 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_10 , V_22 = F_12 ( V_12 ) ;
T_1 V_3 , V_9 ;
if ( V_22 < V_23 || V_22 > V_24 )
return - V_19 ;
else {
V_3 = ( V_22 == V_23 ?
V_42 : V_43 ) ;
V_9 = ( V_22 == V_23 ?
V_44 :
V_45 ) ;
}
V_10 = F_8 ( V_2 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= V_9 ;
return V_2 -> V_27 [ V_22 ] -> V_34 [ V_10 ] * 1000 ;
}
static int F_21 ( struct V_14 * V_12 ,
int V_35 , int V_36 ,
unsigned * V_37 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_10 , V_38 , V_22 = F_12 ( V_12 ) ;
T_1 V_3 , V_9 ;
if ( V_22 < V_23 || V_22 > V_24 )
return - V_19 ;
else {
V_3 = ( V_22 == V_23 ?
V_42 : V_43 ) ;
V_9 = ( V_22 == V_23 ?
V_44 :
V_45 ) ;
}
if ( V_35 < V_2 -> V_27 [ V_22 ] -> V_35 || V_35 > V_2 -> V_27 [ V_22 ] -> V_36 )
return - V_19 ;
if ( V_36 < V_2 -> V_27 [ V_22 ] -> V_35 || V_36 > V_2 -> V_27 [ V_22 ] -> V_36 )
return - V_19 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_27 [ V_22 ] -> V_39 ; V_38 ++ ) {
int V_40 = V_2 -> V_27 [ V_22 ] -> V_34 [ V_38 ] ;
int V_41 = V_40 * 1000 ;
if ( V_35 <= V_41 && V_41 <= V_36 )
break;
}
if ( V_38 == V_2 -> V_27 [ V_22 ] -> V_39 )
return - V_19 ;
* V_37 = V_38 ;
V_10 = F_8 ( V_2 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ~ V_9 ;
V_10 |= V_38 ;
return F_9 ( V_2 , V_3 , V_10 ) ;
}
static int F_22 ( struct V_14 * V_12 ,
unsigned V_37 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_15 = F_12 ( V_12 ) ;
if ( V_15 < V_17 || V_15 > V_18 )
return - V_19 ;
if ( V_37 >= V_2 -> V_27 [ V_15 ] -> V_39 )
return - V_19 ;
else
return V_2 -> V_27 [ V_15 ] -> V_34 [ V_37 ] * 1000 ;
}
static int F_23 ( struct V_14 * V_12 ,
unsigned V_37 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_22 = F_12 ( V_12 ) ;
if ( V_22 < V_23 || V_22 > V_24 )
return - V_19 ;
if ( V_37 >= V_2 -> V_27 [ V_22 ] -> V_39 )
return - V_19 ;
else
return V_2 -> V_27 [ V_22 ] -> V_34 [ V_37 ] * 1000 ;
}
static T_2
int F_24 ( struct V_46 * V_47 )
{
struct V_48 * V_48 = F_25 ( V_47 -> V_12 . V_49 ) ;
struct V_50 * V_27 = & V_51 [ 0 ] ;
struct V_52 * V_53 ;
struct V_14 * V_54 ;
struct V_1 * V_2 ;
struct V_55 * V_56 ;
int V_57 ;
int error ;
V_56 = F_26 ( V_48 -> V_12 ) ;
if ( ! V_56 )
return - V_19 ;
V_53 = V_56 -> V_58 ;
if ( ! V_53 )
return - V_19 ;
V_2 = F_27 ( sizeof( * V_2 ) , V_59 ) ;
if ( ! V_2 )
return - V_60 ;
F_28 ( & V_2 -> V_11 ) ;
V_2 -> V_6 = V_48 ;
for ( V_57 = 0 ; V_57 < V_61 ; V_57 ++ , V_27 ++ , V_53 ++ ) {
V_2 -> V_27 [ V_57 ] = V_27 ;
if ( V_53 -> V_62 ) {
struct V_63 * V_10 =
V_53 -> V_62 ;
V_2 -> V_27 [ V_57 ] -> V_28 = V_10 -> V_28 ;
}
V_2 -> V_64 [ V_57 ] . V_65 = V_27 -> V_65 ;
V_2 -> V_64 [ V_57 ] . V_66 = V_57 ;
V_2 -> V_64 [ V_57 ] . V_67 = V_27 -> V_39 ;
V_2 -> V_64 [ V_57 ] . V_68 = ( V_57 > V_18 ?
& V_69 : & V_70 ) ;
V_2 -> V_64 [ V_57 ] . type = V_71 ;
V_2 -> V_64 [ V_57 ] . V_72 = V_73 ;
V_54 = F_29 ( & V_2 -> V_64 [ V_57 ] ,
V_48 -> V_12 , V_53 , V_2 ) ;
if ( F_30 ( V_54 ) ) {
F_5 ( V_48 -> V_12 ,
L_3 ,
V_47 -> V_65 ) ;
error = F_31 ( V_54 ) ;
goto V_74;
}
V_2 -> V_54 [ V_57 ] = V_54 ;
}
V_48 -> V_75 = V_2 ;
F_32 ( V_47 , V_48 ) ;
return 0 ;
V_74:
while ( -- V_57 >= 0 )
F_33 ( V_2 -> V_54 [ V_57 ] ) ;
F_34 ( V_2 ) ;
return error ;
}
static int T_3 F_35 ( struct V_46 * V_47 )
{
struct V_48 * V_48 = F_36 ( V_47 ) ;
struct V_1 * V_2 = V_48 -> V_75 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_61 ; V_57 ++ )
F_33 ( V_2 -> V_54 [ V_57 ] ) ;
F_34 ( V_2 ) ;
return 0 ;
}
static int T_4 F_37 ( void )
{
return F_38 ( & V_76 ) ;
}
static void T_5 F_39 ( void )
{
F_40 ( & V_76 ) ;
}
