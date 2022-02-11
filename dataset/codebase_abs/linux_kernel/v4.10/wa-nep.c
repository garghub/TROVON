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
V_33 = - V_36 ;
goto V_32;
}
F_15 ( & V_6 -> V_7 , F_1 ) ;
V_6 -> V_9 = F_16 ( V_9 ) ;
V_6 -> V_12 = V_12 ;
memcpy ( V_6 -> V_17 , V_9 -> V_37 , V_12 ) ;
F_17 ( & V_9 -> V_16 ) ;
F_18 ( V_38 , & V_6 -> V_7 ) ;
V_32:
return V_33 ;
}
static void F_19 ( struct V_39 * V_39 )
{
int V_33 ;
struct V_8 * V_9 = V_39 -> V_40 ;
struct V_13 * V_14 = & V_9 -> V_15 -> V_14 ;
switch ( V_33 = V_39 -> V_41 ) {
case 0 :
V_33 = F_10 ( V_9 , V_39 -> V_42 ) ;
if ( V_33 < 0 )
F_6 ( V_14 , L_8
L_9 , V_33 ) ;
break;
case - V_43 :
case - V_44 :
case - V_45 :
F_20 ( V_14 , L_10 , V_39 -> V_41 ) ;
goto V_32;
default:
if ( F_21 ( & V_9 -> V_46 , V_47 ,
V_48 ) ) {
F_6 ( V_14 , L_11
L_12 ) ;
F_22 ( V_9 ) ;
goto V_32;
}
F_6 ( V_14 , L_13 , V_39 -> V_41 ) ;
}
V_33 = F_23 ( V_9 , V_35 ) ;
if ( V_33 < 0 ) {
F_6 ( V_14 , L_14 , V_33 ) ;
F_22 ( V_9 ) ;
}
V_32:
return;
}
int F_24 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
int V_33 ;
struct V_51 * V_52 ;
struct V_53 * V_54 = F_25 ( V_50 ) ;
struct V_13 * V_14 = & V_50 -> V_14 ;
F_26 ( & V_9 -> V_46 ) ;
V_52 = & V_50 -> V_55 -> V_56 [ 0 ] . V_57 ;
V_9 -> V_34 = 1024 ;
V_9 -> V_37 = F_27 ( V_9 -> V_34 , V_58 ) ;
if ( ! V_9 -> V_37 )
goto V_59;
V_9 -> V_60 = F_28 ( 0 , V_58 ) ;
if ( V_9 -> V_60 == NULL )
goto V_61;
F_29 ( V_9 -> V_60 , V_54 ,
F_30 ( V_54 , V_52 -> V_62 ) ,
V_9 -> V_37 , V_9 -> V_34 ,
F_19 , V_9 , V_52 -> V_63 ) ;
V_33 = F_23 ( V_9 , V_58 ) ;
if ( V_33 < 0 ) {
F_6 ( V_14 , L_15 , V_33 ) ;
goto V_64;
}
return 0 ;
V_64:
F_31 ( V_9 -> V_60 ) ;
V_61:
F_8 ( V_9 -> V_37 ) ;
V_59:
return - V_36 ;
}
void F_32 ( struct V_8 * V_9 )
{
F_33 ( V_9 ) ;
F_31 ( V_9 -> V_60 ) ;
F_8 ( V_9 -> V_37 ) ;
}
