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
static int F_17 ( struct V_38 * V_39 )
{
struct V_40 * V_40 = F_18 ( V_39 -> V_12 . V_41 ) ;
struct V_42 * V_25 = & V_43 [ 0 ] ;
struct V_44 V_45 = { } ;
struct V_46 * V_47 ;
struct V_14 * V_48 ;
struct V_1 * V_2 ;
struct V_49 * V_50 ;
int V_51 ;
int error ;
V_50 = F_19 ( V_40 -> V_12 ) ;
if ( ! V_50 )
return - V_19 ;
V_47 = V_50 -> V_52 ;
if ( ! V_47 )
return - V_19 ;
V_2 = F_20 ( & V_39 -> V_12 , sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
F_21 ( & V_2 -> V_11 ) ;
V_2 -> V_6 = V_40 ;
for ( V_51 = 0 ; V_51 < V_55 ; V_51 ++ , V_25 ++ , V_47 ++ ) {
V_2 -> V_25 [ V_51 ] = V_25 ;
if ( V_47 -> V_56 ) {
struct V_57 * V_10 =
V_47 -> V_56 ;
V_2 -> V_25 [ V_51 ] -> V_26 = V_10 -> V_26 ;
}
V_2 -> V_58 [ V_51 ] . V_59 = V_25 -> V_59 ;
V_2 -> V_58 [ V_51 ] . V_60 = V_51 ;
V_2 -> V_58 [ V_51 ] . V_61 = V_25 -> V_62 ;
V_2 -> V_58 [ V_51 ] . V_63 = V_25 -> V_64 ;
V_2 -> V_58 [ V_51 ] . V_65 = & V_66 ;
V_2 -> V_58 [ V_51 ] . type = V_67 ;
V_2 -> V_58 [ V_51 ] . V_68 = V_69 ;
V_45 . V_12 = V_40 -> V_12 ;
V_45 . V_47 = V_47 ;
V_45 . V_56 = V_2 ;
V_48 = F_22 ( & V_2 -> V_58 [ V_51 ] , & V_45 ) ;
if ( F_23 ( V_48 ) ) {
F_5 ( V_40 -> V_12 ,
L_3 ,
V_39 -> V_59 ) ;
error = F_24 ( V_48 ) ;
goto V_70;
}
V_2 -> V_48 [ V_51 ] = V_48 ;
}
V_40 -> V_71 = V_2 ;
F_25 ( V_39 , V_40 ) ;
return 0 ;
V_70:
while ( -- V_51 >= 0 )
F_26 ( V_2 -> V_48 [ V_51 ] ) ;
return error ;
}
static int F_27 ( struct V_38 * V_39 )
{
struct V_40 * V_40 = F_28 ( V_39 ) ;
struct V_1 * V_2 = V_40 -> V_71 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_55 ; V_51 ++ )
F_26 ( V_2 -> V_48 [ V_51 ] ) ;
return 0 ;
}
static int T_2 F_29 ( void )
{
return F_30 ( & V_72 ) ;
}
static void T_3 F_31 ( void )
{
F_32 ( & V_72 ) ;
}
