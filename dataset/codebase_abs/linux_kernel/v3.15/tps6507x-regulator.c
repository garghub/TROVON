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
static struct V_38 * F_17 (
struct V_39 * V_40 ,
struct V_41 * * V_42 )
{
struct V_38 * V_43 ;
struct V_44 * V_45 = V_40 -> V_12 . V_46 -> V_47 ;
struct V_44 * V_48 ;
struct V_41 * V_49 ;
static struct V_50 * V_51 ;
int V_52 = 0 , V_53 , V_54 ;
V_43 = F_18 ( & V_40 -> V_12 , sizeof( * V_43 ) ,
V_55 ) ;
if ( ! V_43 )
return NULL ;
V_48 = F_19 ( V_45 , L_3 ) ;
if ( ! V_48 ) {
F_5 ( & V_40 -> V_12 , L_4 ) ;
return NULL ;
}
V_53 = F_20 ( V_56 ) ;
V_49 = V_56 ;
V_54 = V_41 ( & V_40 -> V_12 , V_48 , V_49 , V_53 ) ;
F_21 ( V_48 ) ;
if ( V_54 < 0 ) {
F_5 ( & V_40 -> V_12 , L_5 ,
V_54 ) ;
return NULL ;
}
* V_42 = V_49 ;
V_51 = F_18 ( & V_40 -> V_12 , ( sizeof( struct V_50 )
* V_57 ) , V_55 ) ;
if ( ! V_51 )
return NULL ;
V_43 -> V_58 = V_51 ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
if ( ! V_49 [ V_52 ] . V_59 || ! V_49 [ V_52 ] . V_47 )
continue;
memcpy ( & V_51 [ V_52 ] , V_49 [ V_52 ] . V_59 ,
sizeof( struct V_50 ) ) ;
}
return V_43 ;
}
static int F_22 ( struct V_39 * V_40 )
{
struct V_60 * V_60 = F_23 ( V_40 -> V_12 . V_46 ) ;
struct V_61 * V_25 = & V_62 [ 0 ] ;
struct V_63 V_64 = { } ;
struct V_50 * V_59 ;
struct V_14 * V_65 ;
struct V_1 * V_2 ;
struct V_38 * V_43 ;
struct V_41 * V_42 = NULL ;
int V_66 ;
int error ;
unsigned int V_67 ;
V_43 = F_24 ( V_60 -> V_12 ) ;
if ( F_25 ( V_68 ) && ! V_43 &&
V_60 -> V_12 -> V_47 )
V_43 = F_17 ( V_40 ,
& V_42 ) ;
if ( ! V_43 )
return - V_19 ;
V_59 = V_43 -> V_58 ;
if ( ! V_59 )
return - V_19 ;
V_2 = F_18 ( & V_40 -> V_12 , sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 )
return - V_69 ;
F_26 ( & V_2 -> V_11 ) ;
V_2 -> V_6 = V_60 ;
for ( V_66 = 0 ; V_66 < V_57 ; V_66 ++ , V_25 ++ , V_59 ++ ) {
V_2 -> V_25 [ V_66 ] = V_25 ;
if ( V_59 -> V_70 ) {
struct V_71 * V_10 =
V_59 -> V_70 ;
V_2 -> V_25 [ V_66 ] -> V_26 = V_10 -> V_26 ;
}
V_2 -> V_72 [ V_66 ] . V_73 = V_25 -> V_73 ;
V_2 -> V_72 [ V_66 ] . V_74 = V_66 ;
V_2 -> V_72 [ V_66 ] . V_75 = V_25 -> V_76 ;
V_2 -> V_72 [ V_66 ] . V_77 = V_25 -> V_78 ;
V_2 -> V_72 [ V_66 ] . V_79 = & V_80 ;
V_2 -> V_72 [ V_66 ] . type = V_81 ;
V_2 -> V_72 [ V_66 ] . V_82 = V_83 ;
V_64 . V_12 = V_60 -> V_12 ;
V_64 . V_59 = V_59 ;
V_64 . V_70 = V_2 ;
if ( V_42 ) {
error = F_27 (
V_42 [ V_66 ] . V_47 ,
L_6 , & V_67 ) ;
if ( ! error )
V_2 -> V_25 [ V_66 ] -> V_26 = V_67 ;
V_64 . V_47 = V_42 [ V_66 ] . V_47 ;
}
V_65 = F_28 ( & V_40 -> V_12 , & V_2 -> V_72 [ V_66 ] ,
& V_64 ) ;
if ( F_29 ( V_65 ) ) {
F_5 ( V_60 -> V_12 ,
L_7 ,
V_40 -> V_73 ) ;
return F_30 ( V_65 ) ;
}
V_2 -> V_65 [ V_66 ] = V_65 ;
}
V_60 -> V_84 = V_2 ;
F_31 ( V_40 , V_60 ) ;
return 0 ;
}
static int T_2 F_32 ( void )
{
return F_33 ( & V_85 ) ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_85 ) ;
}
