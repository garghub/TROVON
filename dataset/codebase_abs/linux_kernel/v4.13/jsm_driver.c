static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 ;
static int V_8 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_9 , L_1 ) ;
goto V_10;
}
V_5 = F_4 ( V_2 , V_11 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_9 , L_2 ) ;
goto V_12;
}
V_7 = F_5 ( sizeof( * V_7 ) , V_13 ) ;
if ( ! V_7 ) {
V_5 = - V_14 ;
goto V_15;
}
V_7 -> V_16 = V_8 ++ ;
V_7 -> V_1 = V_2 ;
switch ( V_2 -> V_17 ) {
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
V_7 -> V_23 = 2 ;
break;
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
V_7 -> V_23 = 4 ;
break;
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
V_7 -> V_23 = 8 ;
break;
default:
V_7 -> V_23 = 1 ;
break;
}
F_6 ( & V_7 -> V_35 ) ;
V_7 -> V_36 = V_2 -> V_37 ;
V_7 -> V_38 = V_2 -> V_38 ;
switch ( V_2 -> V_17 ) {
case V_24 :
case V_25 :
case V_30 :
case V_31 :
F_7 ( V_39 , & V_7 -> V_1 ,
L_3 ) ;
V_7 -> V_40 = F_8 ( V_2 , 4 ) ;
V_7 -> V_41 = F_9 ( V_2 , 4 ) ;
if ( V_7 -> V_40 & 0x1 )
V_7 -> V_40 &= ~ 0x3 ;
else
V_7 -> V_40 &= ~ 0xF ;
V_7 -> V_42 = F_8 ( V_2 , 1 ) ;
V_7 -> V_43 = F_9 ( V_2 , 1 ) ;
V_7 -> V_42 = ( ( unsigned int ) ( V_7 -> V_42 ) ) & 0xFFFE ;
V_7 -> V_44 = & V_45 ;
V_7 -> V_46 = 0x8 ;
V_7 -> V_47 = 921600 ;
V_7 -> V_48 = F_10 ( V_7 -> V_40 ,
F_11 ( V_2 , 4 ) ) ;
if ( ! V_7 -> V_48 ) {
F_3 ( & V_2 -> V_9 ,
L_4 ) ;
V_5 = - V_14 ;
goto V_49;
}
F_12 ( 0x43 , V_7 -> V_42 + 0x4c ) ;
break;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_32 :
case V_33 :
case V_34 :
F_7 ( V_39 , & V_7 -> V_1 , L_5 ) ;
V_7 -> V_40 = F_8 ( V_2 , 0 ) ;
V_7 -> V_41 = F_9 ( V_2 , 0 ) ;
if ( V_7 -> V_40 & 1 )
V_7 -> V_40 &= ~ 0x3 ;
else
V_7 -> V_40 &= ~ 0xF ;
V_7 -> V_44 = & V_50 ;
V_7 -> V_46 = 0x200 ;
V_7 -> V_47 = 921600 ;
V_7 -> V_48 = F_10 ( V_7 -> V_40 ,
F_11 ( V_2 , 0 ) ) ;
if ( ! V_7 -> V_48 ) {
F_3 ( & V_2 -> V_9 ,
L_4 ) ;
V_5 = - V_14 ;
goto V_49;
}
break;
default:
return - V_51 ;
}
V_5 = F_13 ( V_7 -> V_38 , V_7 -> V_44 -> V_52 , V_53 , L_6 , V_7 ) ;
if ( V_5 ) {
F_14 ( & V_2 -> V_9 , L_7 , V_7 -> V_38 ) ;
goto V_54;
}
V_5 = F_15 ( V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_9 , L_8 , V_5 ) ;
V_5 = - V_51 ;
goto V_55;
}
V_5 = F_16 ( V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_9 , L_9 , V_5 ) ;
V_5 = - V_51 ;
goto V_55;
}
F_17 ( & V_2 -> V_9 , L_10 ,
V_8 , V_7 -> V_36 , V_7 -> V_38 ) ;
F_18 ( V_2 , V_7 ) ;
F_19 ( V_2 ) ;
return 0 ;
V_55:
F_20 ( V_7 ) ;
F_21 ( V_7 -> V_38 , V_7 ) ;
V_54:
F_22 ( V_7 -> V_48 ) ;
V_49:
F_23 ( V_7 ) ;
V_15:
F_24 ( V_2 ) ;
V_12:
F_25 ( V_2 ) ;
V_10:
return V_5 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_27 ( V_2 ) ;
int V_56 = 0 ;
switch ( V_2 -> V_17 ) {
case V_24 :
case V_25 :
case V_30 :
case V_31 :
F_12 ( 0x0 , V_7 -> V_42 + 0x4c ) ;
break;
default:
break;
}
F_20 ( V_7 ) ;
F_21 ( V_7 -> V_38 , V_7 ) ;
F_22 ( V_7 -> V_48 ) ;
for ( V_56 = 0 ; V_56 < V_7 -> V_23 ; V_56 ++ ) {
if ( V_7 -> V_57 [ V_56 ] ) {
F_23 ( V_7 -> V_57 [ V_56 ] -> V_58 ) ;
F_23 ( V_7 -> V_57 [ V_56 ] -> V_59 ) ;
F_23 ( V_7 -> V_57 [ V_56 ] ) ;
}
}
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
F_23 ( V_7 ) ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
T_2 V_60 )
{
struct V_6 * V_7 = F_27 ( V_2 ) ;
F_20 ( V_7 ) ;
return V_61 ;
}
static T_1 F_29 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
return V_62 ;
F_30 ( V_2 ) ;
return V_63 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_27 ( V_2 ) ;
F_32 ( V_2 ) ;
F_19 ( V_2 ) ;
F_16 ( V_7 ) ;
}
static int T_3 F_33 ( void )
{
int V_5 ;
V_5 = F_34 ( & V_64 ) ;
if ( ! V_5 ) {
V_5 = F_35 ( & V_65 ) ;
if ( V_5 )
F_36 ( & V_64 ) ;
}
return V_5 ;
}
static void T_4 F_37 ( void )
{
F_38 ( & V_65 ) ;
F_36 ( & V_64 ) ;
}
