static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_1 * V_7 = V_6 ;
F_4 ( & V_6 -> V_8 ) ;
if ( F_5 ( V_9 , V_6 -> V_10 + V_11 / 4 ) || ! V_6 -> V_12 ) {
int V_13 ;
for ( V_13 = 0 ; V_13 < F_6 ( V_6 -> V_14 ) ; V_13 ++ ) {
int V_15 ;
V_15 = F_7 ( V_5 , V_13 ) ;
if ( F_8 ( V_15 < 0 ) ) {
F_9 ( V_3 ,
L_1 ,
V_15 ) ;
V_7 = F_10 ( V_15 ) ;
V_6 -> V_12 = 0 ;
goto abort;
}
V_6 -> V_14 [ V_13 ] = V_15 ;
}
V_6 -> V_10 = V_9 ;
V_6 -> V_12 = 1 ;
}
abort:
F_11 ( & V_6 -> V_8 ) ;
return V_7 ;
}
static int F_12 ( struct V_1 * V_6 , T_1 V_16 )
{
T_2 V_15 ;
V_15 = ( V_6 -> V_14 [ V_16 ] << 2 ) + ( V_6 -> V_14 [ V_16 + 1 ] >> 6 ) ;
switch ( V_16 ) {
case V_17 :
case V_18 :
V_15 = V_15 * 25 / 10 ;
break;
case V_19 :
V_15 = V_15 * 625 / 10 ;
break;
default:
F_13 ( 1 ) ;
V_15 = 0 ;
break;
}
return V_15 ;
}
static T_3 F_14 ( struct V_2 * V_3 ,
struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_24 = F_15 ( V_21 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_25 ;
if ( F_16 ( V_6 ) )
return F_17 ( V_6 ) ;
V_25 = F_12 ( V_6 , V_24 -> V_26 ) ;
return snprintf ( V_22 , V_27 , L_2 , V_25 ) ;
}
static T_3 F_18 ( struct V_2 * V_3 ,
struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_24 = F_15 ( V_21 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_28 ;
if ( F_16 ( V_6 ) )
return F_17 ( V_6 ) ;
V_28 = V_6 -> V_14 [ V_29 ] & V_24 -> V_26 ;
if ( V_28 )
F_19 ( V_5 , V_29 , ~ V_28 ) ;
return snprintf ( V_22 , V_27 , L_2 , V_28 ? 1 : 0 ) ;
}
static int F_20 ( struct V_4 * V_5 ,
const struct V_30 * V_31 )
{
struct V_32 * V_33 = V_5 -> V_33 ;
struct V_1 * V_6 ;
int V_7 ;
if ( ! F_21 ( V_33 , V_34 ) )
return - V_35 ;
if ( F_7 ( V_5 , V_36 ) < 0 ) {
F_22 ( & V_5 -> V_3 , L_3 ) ;
return - V_35 ;
}
V_6 = F_23 ( sizeof( * V_6 ) , V_37 ) ;
if ( ! V_6 ) {
V_7 = - V_38 ;
goto V_39;
}
F_24 ( V_5 , V_6 ) ;
F_25 ( & V_6 -> V_8 ) ;
F_19 ( V_5 , V_29 , 0x00 ) ;
V_7 = F_26 ( & V_5 -> V_3 . V_40 , & V_41 ) ;
if ( V_7 )
goto V_42;
V_6 -> V_43 = F_27 ( & V_5 -> V_3 ) ;
if ( F_16 ( V_6 -> V_43 ) ) {
V_7 = F_17 ( V_6 -> V_43 ) ;
goto V_44;
}
return 0 ;
V_44:
F_28 ( & V_5 -> V_3 . V_40 , & V_41 ) ;
V_42:
F_29 ( V_6 ) ;
V_39:
return V_7 ;
}
static int F_30 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_31 ( V_6 -> V_43 ) ;
F_28 ( & V_5 -> V_3 . V_40 , & V_41 ) ;
F_29 ( V_6 ) ;
return 0 ;
}
static int T_4 F_32 ( void )
{
return F_33 ( & V_45 ) ;
}
static void T_5 F_34 ( void )
{
F_35 ( & V_45 ) ;
}
