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
int V_15 = F_12 ( V_12 ) ;
T_1 V_16 ;
if ( V_15 < V_17 || V_15 > V_18 )
return - V_19 ;
V_16 = V_20 - V_15 ;
return F_3 ( V_2 , V_21 , 1 << V_16 ) ;
}
static int F_14 ( struct V_14 * V_12 )
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
static int F_15 ( struct V_14 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_10 , V_15 = F_12 ( V_12 ) ;
T_1 V_3 , V_9 ;
switch ( V_15 ) {
case V_17 :
V_3 = V_22 ;
V_9 = V_23 ;
break;
case V_24 :
if ( V_2 -> V_25 [ V_15 ] -> V_26 )
V_3 = V_27 ;
else
V_3 = V_28 ;
V_9 = V_23 ;
break;
case V_29 :
if ( V_2 -> V_25 [ V_15 ] -> V_26 )
V_3 = V_30 ;
else
V_3 = V_31 ;
V_9 = V_23 ;
break;
case V_32 :
V_3 = V_33 ;
V_9 = V_34 ;
break;
case V_18 :
V_3 = V_35 ;
V_9 = V_36 ;
break;
default:
return - V_19 ;
}
V_10 = F_8 ( V_2 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= V_9 ;
return V_10 ;
}
static int F_16 ( struct V_14 * V_12 ,
unsigned V_37 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_10 , V_15 = F_12 ( V_12 ) ;
T_1 V_3 , V_9 ;
switch ( V_15 ) {
case V_17 :
V_3 = V_22 ;
V_9 = V_23 ;
break;
case V_24 :
if ( V_2 -> V_25 [ V_15 ] -> V_26 )
V_3 = V_27 ;
else
V_3 = V_28 ;
V_9 = V_23 ;
break;
case V_29 :
if ( V_2 -> V_25 [ V_15 ] -> V_26 )
V_3 = V_30 ;
else
V_3 = V_31 ;
V_9 = V_23 ;
break;
case V_32 :
V_3 = V_33 ;
V_9 = V_34 ;
break;
case V_18 :
V_3 = V_35 ;
V_9 = V_36 ;
break;
default:
return - V_19 ;
}
V_10 = F_8 ( V_2 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ~ V_9 ;
V_10 |= V_37 ;
return F_9 ( V_2 , V_3 , V_10 ) ;
}
static int F_17 ( struct V_14 * V_12 ,
unsigned V_37 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_15 = F_12 ( V_12 ) ;
if ( V_15 < V_17 || V_15 > V_18 )
return - V_19 ;
if ( V_37 >= V_2 -> V_25 [ V_15 ] -> V_38 )
return - V_19 ;
else
return V_2 -> V_25 [ V_15 ] -> V_39 [ V_37 ] * 1000 ;
}
static T_2 int F_18 ( struct V_40 * V_41 )
{
struct V_42 * V_42 = F_19 ( V_41 -> V_12 . V_43 ) ;
struct V_44 * V_25 = & V_45 [ 0 ] ;
struct V_46 V_47 = { } ;
struct V_48 * V_49 ;
struct V_14 * V_50 ;
struct V_1 * V_2 ;
struct V_51 * V_52 ;
int V_53 ;
int error ;
V_52 = F_20 ( V_42 -> V_12 ) ;
if ( ! V_52 )
return - V_19 ;
V_49 = V_52 -> V_54 ;
if ( ! V_49 )
return - V_19 ;
V_2 = F_21 ( & V_41 -> V_12 , sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 )
return - V_56 ;
F_22 ( & V_2 -> V_11 ) ;
V_2 -> V_6 = V_42 ;
for ( V_53 = 0 ; V_53 < V_57 ; V_53 ++ , V_25 ++ , V_49 ++ ) {
V_2 -> V_25 [ V_53 ] = V_25 ;
if ( V_49 -> V_58 ) {
struct V_59 * V_10 =
V_49 -> V_58 ;
V_2 -> V_25 [ V_53 ] -> V_26 = V_10 -> V_26 ;
}
V_2 -> V_60 [ V_53 ] . V_61 = V_25 -> V_61 ;
V_2 -> V_60 [ V_53 ] . V_62 = V_53 ;
V_2 -> V_60 [ V_53 ] . V_63 = V_25 -> V_38 ;
V_2 -> V_60 [ V_53 ] . V_64 = & V_65 ;
V_2 -> V_60 [ V_53 ] . type = V_66 ;
V_2 -> V_60 [ V_53 ] . V_67 = V_68 ;
V_47 . V_12 = V_42 -> V_12 ;
V_47 . V_49 = V_49 ;
V_47 . V_58 = V_2 ;
V_50 = F_23 ( & V_2 -> V_60 [ V_53 ] , & V_47 ) ;
if ( F_24 ( V_50 ) ) {
F_5 ( V_42 -> V_12 ,
L_3 ,
V_41 -> V_61 ) ;
error = F_25 ( V_50 ) ;
goto V_69;
}
V_2 -> V_50 [ V_53 ] = V_50 ;
}
V_42 -> V_70 = V_2 ;
F_26 ( V_41 , V_42 ) ;
return 0 ;
V_69:
while ( -- V_53 >= 0 )
F_27 ( V_2 -> V_50 [ V_53 ] ) ;
return error ;
}
static int T_3 F_28 ( struct V_40 * V_41 )
{
struct V_42 * V_42 = F_29 ( V_41 ) ;
struct V_1 * V_2 = V_42 -> V_70 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_57 ; V_53 ++ )
F_27 ( V_2 -> V_50 [ V_53 ] ) ;
return 0 ;
}
static int T_4 F_30 ( void )
{
return F_31 ( & V_71 ) ;
}
static void T_5 F_32 ( void )
{
F_33 ( & V_71 ) ;
}
