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
V_5 = F_4 ( V_2 , L_2 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_9 , L_3 ) ;
goto V_11;
}
V_7 = F_5 ( sizeof( * V_7 ) , V_12 ) ;
if ( ! V_7 ) {
V_5 = - V_13 ;
goto V_14;
}
V_7 -> V_15 = V_8 ++ ;
V_7 -> V_1 = V_2 ;
switch ( V_2 -> V_16 ) {
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
V_7 -> V_22 = 2 ;
break;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
V_7 -> V_22 = 4 ;
break;
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
V_7 -> V_22 = 8 ;
break;
default:
V_7 -> V_22 = 1 ;
break;
}
F_6 ( & V_7 -> V_34 ) ;
V_7 -> V_35 = V_2 -> V_36 ;
V_7 -> V_37 = V_2 -> V_37 ;
switch ( V_2 -> V_16 ) {
case V_23 :
case V_24 :
case V_29 :
case V_30 :
F_7 ( V_38 , & V_7 -> V_1 ,
L_4 ) ;
V_7 -> V_39 = F_8 ( V_2 , 4 ) ;
V_7 -> V_40 = F_9 ( V_2 , 4 ) ;
if ( V_7 -> V_39 & 0x1 )
V_7 -> V_39 &= ~ 0x3 ;
else
V_7 -> V_39 &= ~ 0xF ;
V_7 -> V_41 = F_8 ( V_2 , 1 ) ;
V_7 -> V_42 = F_9 ( V_2 , 1 ) ;
V_7 -> V_41 = ( ( unsigned int ) ( V_7 -> V_41 ) ) & 0xFFFE ;
V_7 -> V_43 = & V_44 ;
V_7 -> V_45 = 0x8 ;
V_7 -> V_46 = 921600 ;
V_7 -> V_47 = F_10 ( V_7 -> V_39 ,
F_11 ( V_2 , 4 ) ) ;
if ( ! V_7 -> V_47 ) {
F_3 ( & V_2 -> V_9 ,
L_5 ) ;
V_5 = - V_13 ;
goto V_48;
}
F_12 ( 0x43 , V_7 -> V_41 + 0x4c ) ;
break;
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_31 :
case V_32 :
case V_33 :
F_7 ( V_38 , & V_7 -> V_1 , L_6 ) ;
V_7 -> V_39 = F_8 ( V_2 , 0 ) ;
V_7 -> V_40 = F_9 ( V_2 , 0 ) ;
if ( V_7 -> V_39 & 1 )
V_7 -> V_39 &= ~ 0x3 ;
else
V_7 -> V_39 &= ~ 0xF ;
V_7 -> V_43 = & V_49 ;
V_7 -> V_45 = 0x200 ;
V_7 -> V_46 = 921600 ;
V_7 -> V_47 = F_10 ( V_7 -> V_39 ,
F_11 ( V_2 , 0 ) ) ;
if ( ! V_7 -> V_47 ) {
F_3 ( & V_2 -> V_9 ,
L_5 ) ;
V_5 = - V_13 ;
goto V_48;
}
break;
default:
return - V_50 ;
}
V_5 = F_13 ( V_7 -> V_37 , V_7 -> V_43 -> V_51 , V_52 , L_7 , V_7 ) ;
if ( V_5 ) {
F_14 ( & V_2 -> V_9 , L_8 , V_7 -> V_37 ) ;
goto V_53;
}
V_5 = F_15 ( V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_9 , L_9 , V_5 ) ;
V_5 = - V_50 ;
goto V_54;
}
V_5 = F_16 ( V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_9 , L_10 , V_5 ) ;
V_5 = - V_50 ;
goto V_54;
}
F_17 ( & V_2 -> V_9 , L_11 ,
V_8 , V_7 -> V_35 , V_7 -> V_37 ) ;
F_18 ( V_2 , V_7 ) ;
F_19 ( V_2 ) ;
return 0 ;
V_54:
F_20 ( V_7 ) ;
F_21 ( V_7 -> V_37 , V_7 ) ;
V_53:
F_22 ( V_7 -> V_47 ) ;
V_48:
F_23 ( V_7 ) ;
V_14:
F_24 ( V_2 ) ;
V_11:
F_25 ( V_2 ) ;
V_10:
return V_5 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_27 ( V_2 ) ;
int V_55 = 0 ;
switch ( V_2 -> V_16 ) {
case V_23 :
case V_24 :
case V_29 :
case V_30 :
F_12 ( 0x0 , V_7 -> V_41 + 0x4c ) ;
break;
default:
break;
}
F_20 ( V_7 ) ;
F_21 ( V_7 -> V_37 , V_7 ) ;
F_22 ( V_7 -> V_47 ) ;
for ( V_55 = 0 ; V_55 < V_7 -> V_22 ; V_55 ++ ) {
if ( V_7 -> V_56 [ V_55 ] ) {
F_23 ( V_7 -> V_56 [ V_55 ] -> V_57 ) ;
F_23 ( V_7 -> V_56 [ V_55 ] -> V_58 ) ;
F_23 ( V_7 -> V_56 [ V_55 ] ) ;
}
}
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
F_23 ( V_7 ) ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
T_2 V_59 )
{
struct V_6 * V_7 = F_27 ( V_2 ) ;
F_20 ( V_7 ) ;
return V_60 ;
}
static T_1 F_29 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
return V_61 ;
F_30 ( V_2 ) ;
return V_62 ;
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
V_5 = F_34 ( & V_63 ) ;
if ( ! V_5 ) {
V_5 = F_35 ( & V_64 ) ;
if ( V_5 )
F_36 ( & V_63 ) ;
}
return V_5 ;
}
static void T_4 F_37 ( void )
{
F_38 ( & V_64 ) ;
F_36 ( & V_63 ) ;
}
