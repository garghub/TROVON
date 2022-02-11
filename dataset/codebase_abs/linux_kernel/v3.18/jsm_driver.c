static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 ;
static int V_8 = 0 ;
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
V_7 = F_5 ( sizeof( struct V_6 ) , V_12 ) ;
if ( ! V_7 ) {
F_3 ( & V_2 -> V_9 ,
L_4 ) ;
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
V_7 -> V_22 = 4 ;
break;
case V_27 :
case V_28 :
case V_29 :
V_7 -> V_22 = 8 ;
break;
default:
V_7 -> V_22 = 1 ;
break;
}
F_6 ( & V_7 -> V_30 ) ;
V_7 -> V_31 = V_2 -> V_32 ;
V_7 -> V_33 = V_2 -> V_33 ;
F_7 ( V_34 , & V_7 -> V_1 , L_5 ) ;
V_7 -> V_35 = F_8 ( V_2 , 0 ) ;
V_7 -> V_36 = F_9 ( V_2 , 0 ) ;
if ( V_7 -> V_35 & 1 )
V_7 -> V_35 &= ~ 3 ;
else
V_7 -> V_35 &= ~ 15 ;
V_7 -> V_37 = & V_38 ;
V_7 -> V_39 = 0x200 ;
V_7 -> V_40 = 921600 ;
V_7 -> V_41 = F_10 ( V_7 -> V_35 , F_11 ( V_2 , 0 ) ) ;
if ( ! V_7 -> V_41 ) {
F_3 ( & V_2 -> V_9 ,
L_6
L_7 ) ;
V_5 = - V_13 ;
goto V_42;
}
V_5 = F_12 ( V_7 -> V_33 , V_7 -> V_37 -> V_43 ,
V_44 , L_8 , V_7 ) ;
if ( V_5 ) {
F_13 ( V_45 L_9 , V_7 -> V_33 ) ;
goto V_46;
}
V_5 = F_14 ( V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_9 , L_10 , V_5 ) ;
V_5 = - V_47 ;
goto V_48;
}
V_5 = F_15 ( V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_9 , L_11 , V_5 ) ;
V_5 = - V_47 ;
goto V_48;
}
F_16 ( & V_2 -> V_9 , L_12 ,
V_8 , V_7 -> V_31 , V_7 -> V_33 ) ;
F_17 ( V_2 , V_7 ) ;
F_18 ( V_2 ) ;
return 0 ;
V_48:
F_19 ( V_7 ) ;
F_20 ( V_7 -> V_33 , V_7 ) ;
V_46:
F_21 ( V_7 -> V_41 ) ;
V_42:
F_22 ( V_7 ) ;
V_14:
F_23 ( V_2 ) ;
V_11:
F_24 ( V_2 ) ;
V_10:
return V_5 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_26 ( V_2 ) ;
int V_49 = 0 ;
F_19 ( V_7 ) ;
F_20 ( V_7 -> V_33 , V_7 ) ;
F_21 ( V_7 -> V_41 ) ;
for ( V_49 = 0 ; V_49 < V_7 -> V_22 ; V_49 ++ ) {
if ( V_7 -> V_50 [ V_49 ] ) {
F_22 ( V_7 -> V_50 [ V_49 ] -> V_51 ) ;
F_22 ( V_7 -> V_50 [ V_49 ] -> V_52 ) ;
F_22 ( V_7 -> V_50 [ V_49 ] ) ;
}
}
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_22 ( V_7 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
T_2 V_53 )
{
struct V_6 * V_7 = F_26 ( V_2 ) ;
F_19 ( V_7 ) ;
return V_54 ;
}
static T_1 F_28 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
return V_55 ;
F_29 ( V_2 ) ;
return V_56 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_26 ( V_2 ) ;
F_31 ( V_2 ) ;
F_18 ( V_2 ) ;
F_15 ( V_7 ) ;
}
static int T_3 F_32 ( void )
{
int V_5 ;
V_5 = F_33 ( & V_57 ) ;
if ( ! V_5 ) {
V_5 = F_34 ( & V_58 ) ;
if ( V_5 )
F_35 ( & V_57 ) ;
}
return V_5 ;
}
static void T_4 F_36 ( void )
{
F_37 ( & V_58 ) ;
F_35 ( & V_57 ) ;
}
