static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_1 * V_7 = V_6 ;
F_4 ( & V_6 -> V_8 ) ;
if ( F_5 ( V_9 , V_6 -> V_10 + V_11 / 6 ) || ! V_6 -> V_12 ) {
int V_13 ;
F_6 ( & V_5 -> V_3 , L_1 ) ;
for ( V_13 = 0 ; V_13 < F_7 ( V_6 -> V_14 ) ; V_13 ++ ) {
int V_15 ;
V_15 = F_8 ( V_5 , V_13 ) ;
if ( F_9 ( V_15 < 0 ) ) {
F_6 ( V_3 ,
L_2 ,
V_15 ) ;
V_7 = F_10 ( V_15 ) ;
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
V_15 = ( V_6 -> V_14 [ V_16 ] << 4 ) + ( V_6 -> V_14 [ V_16 + 1 ] >> 4 ) ;
switch ( V_16 ) {
case V_17 :
V_15 = V_15 * 500 / 1000 ;
break;
case V_18 :
V_15 = V_15 * 20 ;
break;
case V_19 :
V_15 = V_15 * 25 ;
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
return snprintf ( V_22 , V_27 , L_3 , V_25 ) ;
}
static int F_18 ( struct V_4 * V_5 ,
const struct V_28 * V_29 )
{
struct V_30 * V_31 = V_5 -> V_31 ;
struct V_1 * V_6 ;
int V_7 ;
if ( ! F_19 ( V_31 , V_32 ) )
return - V_33 ;
V_6 = F_20 ( sizeof( * V_6 ) , V_34 ) ;
if ( ! V_6 ) {
V_7 = - V_35 ;
goto V_36;
}
F_21 ( V_5 , V_6 ) ;
F_22 ( & V_6 -> V_8 ) ;
V_7 = F_23 ( & V_5 -> V_3 . V_37 , & V_38 ) ;
if ( V_7 )
goto V_39;
V_6 -> V_40 = F_24 ( & V_5 -> V_3 ) ;
if ( F_16 ( V_6 -> V_40 ) ) {
V_7 = F_17 ( V_6 -> V_40 ) ;
goto V_41;
}
return 0 ;
V_41:
F_25 ( & V_5 -> V_3 . V_37 , & V_38 ) ;
V_39:
F_26 ( V_6 ) ;
V_36:
return V_7 ;
}
static int F_27 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_28 ( V_6 -> V_40 ) ;
F_25 ( & V_5 -> V_3 . V_37 , & V_38 ) ;
F_26 ( V_6 ) ;
return 0 ;
}
