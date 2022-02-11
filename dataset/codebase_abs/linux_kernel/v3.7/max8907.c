static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_6 :
case V_7 :
case V_8 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ! F_1 ( V_2 , V_3 ) ;
}
static bool F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 <= V_10 )
return true ;
switch ( V_3 ) {
case V_11 :
case V_12 :
return true ;
default:
return false ;
}
}
static bool F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_12 :
return true ;
default:
return false ;
}
}
static bool F_6 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_11 :
case V_12 :
return false ;
default:
return true ;
}
}
static void F_7 ( void )
{
F_8 ( V_13 -> V_14 , V_15 ,
V_16 , V_16 ) ;
}
static T_1 int F_9 ( struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
struct V_21 * V_21 ;
int V_22 ;
struct V_23 * V_24 = F_10 ( & V_18 -> V_2 ) ;
bool V_25 = false ;
if ( V_24 )
V_25 = V_24 -> V_25 ;
else if ( V_18 -> V_2 . V_26 )
V_25 = F_11 ( V_18 -> V_2 . V_26 ,
L_1 ) ;
V_21 = F_12 ( & V_18 -> V_2 , sizeof( struct V_21 ) , V_27 ) ;
if ( ! V_21 ) {
V_22 = - V_28 ;
goto V_29;
}
V_21 -> V_2 = & V_18 -> V_2 ;
F_13 ( V_21 -> V_2 , V_21 ) ;
V_21 -> V_30 = V_18 ;
F_14 ( V_18 , V_21 ) ;
V_21 -> V_14 = F_15 ( V_18 ,
& V_31 ) ;
if ( F_16 ( V_21 -> V_14 ) ) {
V_22 = F_17 ( V_21 -> V_14 ) ;
F_18 ( & V_18 -> V_2 , L_2 , V_22 ) ;
goto V_32;
}
V_21 -> V_33 = F_19 ( V_18 -> V_34 , V_35 ) ;
if ( ! V_21 -> V_33 ) {
V_22 = - V_28 ;
goto V_36;
}
F_14 ( V_21 -> V_33 , V_21 ) ;
V_21 -> V_37 = F_15 ( V_21 -> V_33 ,
& V_38 ) ;
if ( F_16 ( V_21 -> V_37 ) ) {
V_22 = F_17 ( V_21 -> V_37 ) ;
F_18 ( & V_18 -> V_2 , L_3 , V_22 ) ;
goto V_39;
}
F_20 ( V_21 -> V_30 -> V_40 , V_41 ) ;
V_22 = F_21 ( V_21 -> V_14 , V_21 -> V_30 -> V_40 ,
V_42 | V_43 , - 1 ,
& V_44 ,
& V_21 -> V_45 ) ;
if ( V_22 != 0 ) {
F_18 ( & V_18 -> V_2 , L_4 , V_22 ) ;
goto V_46;
}
V_22 = F_21 ( V_21 -> V_14 , V_21 -> V_30 -> V_40 ,
V_42 | V_43 , - 1 ,
& V_47 ,
& V_21 -> V_48 ) ;
if ( V_22 != 0 ) {
F_18 ( & V_18 -> V_2 , L_5 , V_22 ) ;
goto V_49;
}
V_22 = F_21 ( V_21 -> V_37 , V_21 -> V_30 -> V_40 ,
V_42 | V_43 , - 1 ,
& V_50 ,
& V_21 -> V_51 ) ;
if ( V_22 != 0 ) {
F_18 ( & V_18 -> V_2 , L_6 , V_22 ) ;
goto V_52;
}
F_22 ( V_21 -> V_30 -> V_40 ) ;
V_22 = F_23 ( V_21 -> V_2 , - 1 , V_53 ,
F_24 ( V_53 ) , NULL , 0 , NULL ) ;
if ( V_22 != 0 ) {
F_18 ( & V_18 -> V_2 , L_7 , V_22 ) ;
goto V_54;
}
if ( V_25 && ! V_55 ) {
V_13 = V_21 ;
V_55 = F_7 ;
}
return 0 ;
V_54:
F_25 ( V_21 -> V_30 -> V_40 , V_21 -> V_51 ) ;
V_52:
F_25 ( V_21 -> V_30 -> V_40 , V_21 -> V_48 ) ;
V_49:
F_25 ( V_21 -> V_30 -> V_40 , V_21 -> V_45 ) ;
V_46:
V_39:
F_26 ( V_21 -> V_33 ) ;
V_36:
V_32:
V_29:
return V_22 ;
}
static T_2 int F_27 ( struct V_17 * V_18 )
{
struct V_21 * V_21 = F_28 ( V_18 ) ;
F_29 ( V_21 -> V_2 ) ;
F_25 ( V_21 -> V_30 -> V_40 , V_21 -> V_51 ) ;
F_25 ( V_21 -> V_30 -> V_40 , V_21 -> V_48 ) ;
F_25 ( V_21 -> V_30 -> V_40 , V_21 -> V_45 ) ;
F_26 ( V_21 -> V_33 ) ;
return 0 ;
}
static int T_3 F_30 ( void )
{
int V_22 = - V_56 ;
V_22 = F_31 ( & V_57 ) ;
if ( V_22 != 0 )
F_32 ( L_8 , V_22 ) ;
return V_22 ;
}
static void T_4 F_33 ( void )
{
F_34 ( & V_57 ) ;
}
