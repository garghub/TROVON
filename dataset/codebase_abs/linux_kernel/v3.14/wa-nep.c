static void F_1 ( struct V_1 * V_2 )
{
void * V_3 ;
T_1 V_4 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_7 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 ;
T_2 V_12 ;
struct V_13 * V_14 = & V_9 -> V_15 -> V_14 ;
#if 0
if (usb_hcd->state == HC_STATE_QUIESCING)
goto out;
#endif
F_3 ( & V_9 -> V_16 ) ;
V_14 = & V_9 -> V_15 -> V_14 ;
V_12 = V_6 -> V_12 ;
V_3 = V_6 -> V_17 ;
while ( V_12 ) {
if ( V_12 < sizeof( * V_11 ) ) {
V_4 = sizeof( * V_11 ) - V_12 ;
goto V_18;
}
V_11 = V_3 ;
if ( V_12 < V_11 -> V_19 )
goto V_18;
V_3 += V_11 -> V_19 ;
V_12 -= V_11 -> V_19 ;
switch ( V_11 -> V_20 ) {
case V_21 : {
struct V_22 * V_23 ;
V_23 = F_2 ( V_11 , struct V_22 ,
V_24 ) ;
F_4 ( V_9 -> V_25 , V_23 -> V_26 ,
V_23 -> V_27 ,
V_11 -> V_19 - sizeof( * V_23 ) ) ;
break;
}
case V_28 :
F_5 ( V_9 , V_11 ) ;
break;
case V_29 :
break;
case V_30 :
case V_31 :
default:
F_6 ( V_14 , L_1
L_2 ,
V_11 -> V_20 ,
( T_2 ) V_11 -> V_19 ) ;
break;
}
}
V_32:
F_7 ( V_9 ) ;
F_8 ( V_6 ) ;
return;
V_18:
F_9 ( V_14 , L_3
L_4 ,
V_4 , ( int ) V_12 ) ;
goto V_32;
}
static int F_10 ( struct V_8 * V_9 , T_2 V_12 )
{
int V_33 = 0 ;
struct V_13 * V_14 = & V_9 -> V_15 -> V_14 ;
struct V_5 * V_6 ;
F_11 ( V_12 > V_9 -> V_34 ) ;
if ( V_12 == 0 )
goto V_32;
if ( F_12 ( & V_9 -> V_16 ) > 200 ) {
if ( F_13 () )
F_6 ( V_14 , L_5
L_6 ) ;
goto V_32;
}
V_6 = F_14 ( sizeof( * V_6 ) + V_12 , V_35 ) ;
if ( V_6 == NULL ) {
if ( F_13 () )
F_6 ( V_14 , L_7 ) ;
goto V_32;
}
F_15 ( & V_6 -> V_7 , F_1 ) ;
V_6 -> V_9 = F_16 ( V_9 ) ;
V_6 -> V_12 = V_12 ;
memcpy ( V_6 -> V_17 , V_9 -> V_36 , V_12 ) ;
F_17 ( & V_9 -> V_16 ) ;
F_18 ( V_37 , & V_6 -> V_7 ) ;
V_32:
return V_33 ;
}
static void F_19 ( struct V_38 * V_38 )
{
int V_33 ;
struct V_8 * V_9 = V_38 -> V_39 ;
struct V_13 * V_14 = & V_9 -> V_15 -> V_14 ;
switch ( V_33 = V_38 -> V_40 ) {
case 0 :
V_33 = F_10 ( V_9 , V_38 -> V_41 ) ;
if ( V_33 < 0 )
F_6 ( V_14 , L_8
L_9 , V_33 ) ;
break;
case - V_42 :
case - V_43 :
case - V_44 :
F_20 ( V_14 , L_10 , V_38 -> V_40 ) ;
goto V_32;
default:
if ( F_21 ( & V_9 -> V_45 , V_46 ,
V_47 ) ) {
F_6 ( V_14 , L_11
L_12 ) ;
F_22 ( V_9 ) ;
goto V_32;
}
F_6 ( V_14 , L_13 , V_38 -> V_40 ) ;
}
V_33 = F_23 ( V_9 , V_35 ) ;
if ( V_33 < 0 ) {
F_6 ( V_14 , L_14 , V_33 ) ;
F_22 ( V_9 ) ;
}
V_32:
return;
}
int F_24 ( struct V_8 * V_9 , struct V_48 * V_49 )
{
int V_33 ;
struct V_50 * V_51 ;
struct V_52 * V_53 = F_25 ( V_49 ) ;
struct V_13 * V_14 = & V_49 -> V_14 ;
F_26 ( & V_9 -> V_45 ) ;
V_51 = & V_49 -> V_54 -> V_55 [ 0 ] . V_56 ;
V_9 -> V_34 = 1024 ;
V_9 -> V_36 = F_27 ( V_9 -> V_34 , V_57 ) ;
if ( V_9 -> V_36 == NULL ) {
F_6 ( V_14 ,
L_15 ) ;
goto V_58;
}
V_9 -> V_59 = F_28 ( 0 , V_57 ) ;
if ( V_9 -> V_59 == NULL ) {
F_6 ( V_14 , L_16 ) ;
goto V_60;
}
F_29 ( V_9 -> V_59 , V_53 ,
F_30 ( V_53 , V_51 -> V_61 ) ,
V_9 -> V_36 , V_9 -> V_34 ,
F_19 , V_9 , V_51 -> V_62 ) ;
V_33 = F_23 ( V_9 , V_57 ) ;
if ( V_33 < 0 ) {
F_6 ( V_14 , L_17 , V_33 ) ;
goto V_63;
}
return 0 ;
V_63:
F_31 ( V_9 -> V_59 ) ;
V_60:
F_8 ( V_9 -> V_36 ) ;
V_58:
return - V_64 ;
}
void F_32 ( struct V_8 * V_9 )
{
F_33 ( V_9 ) ;
F_31 ( V_9 -> V_59 ) ;
F_8 ( V_9 -> V_36 ) ;
}
