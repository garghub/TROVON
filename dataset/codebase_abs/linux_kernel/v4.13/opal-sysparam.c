static T_1 F_1 ( T_2 V_1 , T_2 V_2 , void * V_3 )
{
struct V_4 V_5 ;
T_1 V_6 ;
int V_7 ;
V_7 = F_2 () ;
if ( V_7 < 0 ) {
if ( V_7 != - V_8 )
F_3 ( L_1 ,
V_9 ) ;
V_6 = V_7 ;
goto V_10;
}
V_6 = F_4 ( V_7 , V_1 , ( V_11 ) V_3 , V_2 ) ;
if ( V_6 != V_12 ) {
V_6 = F_5 ( V_6 ) ;
goto V_13;
}
V_6 = F_6 ( V_7 , & V_5 ) ;
if ( V_6 ) {
F_3 ( L_2 ,
V_9 , V_6 ) ;
goto V_13;
}
V_6 = F_5 ( F_7 ( V_5 ) ) ;
V_13:
F_8 ( V_7 ) ;
V_10:
return V_6 ;
}
static int F_9 ( T_2 V_1 , T_2 V_2 , void * V_3 )
{
struct V_4 V_5 ;
int V_6 , V_7 ;
V_7 = F_2 () ;
if ( V_7 < 0 ) {
if ( V_7 != - V_8 )
F_3 ( L_1 ,
V_9 ) ;
V_6 = V_7 ;
goto V_10;
}
V_6 = F_10 ( V_7 , V_1 , ( V_11 ) V_3 , V_2 ) ;
if ( V_6 != V_12 ) {
V_6 = F_5 ( V_6 ) ;
goto V_13;
}
V_6 = F_6 ( V_7 , & V_5 ) ;
if ( V_6 ) {
F_3 ( L_3 ,
V_9 , V_6 ) ;
goto V_13;
}
V_6 = F_5 ( F_7 ( V_5 ) ) ;
V_13:
F_8 ( V_7 ) ;
V_10:
return V_6 ;
}
static T_1 F_11 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_19 * V_20 = F_12 ( V_17 , struct V_19 ,
V_17 ) ;
T_1 V_6 ;
F_13 ( & V_21 ) ;
V_6 = F_1 ( V_20 -> V_1 , V_20 -> V_22 ,
V_23 ) ;
if ( V_6 )
goto V_10;
memcpy ( V_18 , V_23 , V_20 -> V_22 ) ;
V_6 = V_20 -> V_22 ;
V_10:
F_14 ( & V_21 ) ;
return V_6 ;
}
static T_1 F_15 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_18 , T_3 V_24 )
{
struct V_19 * V_20 = F_12 ( V_17 , struct V_19 ,
V_17 ) ;
T_1 V_6 ;
if ( V_24 > V_25 )
V_24 = V_25 ;
F_13 ( & V_21 ) ;
memcpy ( V_23 , V_18 , V_24 ) ;
V_6 = F_9 ( V_20 -> V_1 , V_20 -> V_22 ,
V_23 ) ;
F_14 ( & V_21 ) ;
if ( ! V_6 )
V_6 = V_24 ;
return V_6 ;
}
void T_4 F_16 ( void )
{
struct V_26 * V_27 ;
struct V_19 * V_20 ;
T_2 * V_28 , * V_29 ;
int V_24 , V_30 ;
T_5 * V_31 ;
if ( ! V_32 ) {
F_17 ( L_4 ) ;
goto V_10;
}
V_27 = F_18 ( L_5 ) ;
if ( ! V_27 )
goto V_10;
if ( ! F_19 ( V_27 , L_6 ) ) {
F_3 ( L_7 ) ;
goto V_33;
}
V_34 = F_20 ( L_8 , V_32 ) ;
if ( ! V_34 ) {
F_3 ( L_9 ) ;
goto V_33;
}
V_23 = F_21 ( V_25 , V_35 ) ;
if ( ! V_23 ) {
F_3 ( L_10
L_11 ) ;
goto V_36;
}
V_24 = F_22 ( V_27 , L_12 ) ;
if ( V_24 < 0 ) {
F_3 ( L_13
L_14 , V_27 -> V_37 ) ;
goto V_38;
}
V_28 = F_21 ( sizeof( * V_28 ) * V_24 , V_35 ) ;
if ( ! V_28 ) {
F_3 ( L_15
L_16 ) ;
goto V_38;
}
V_29 = F_21 ( sizeof( * V_29 ) * V_24 , V_35 ) ;
if ( ! V_29 ) {
F_3 ( L_15
L_17 ) ;
goto V_39;
}
V_31 = F_21 ( sizeof( * V_31 ) * V_24 , V_35 ) ;
if ( ! V_31 ) {
F_3 ( L_18
L_19 ) ;
goto V_40;
}
if ( F_23 ( V_27 , L_20 , V_28 , V_24 ) ) {
F_3 ( L_21 ) ;
goto V_41;
}
if ( F_23 ( V_27 , L_22 , V_29 , V_24 ) ) {
F_3 ( L_23 ) ;
goto V_41;
}
if ( F_24 ( V_27 , L_24 , V_31 , V_24 ) ) {
F_3 ( L_25 ) ;
goto V_41;
}
V_20 = F_21 ( sizeof( * V_20 ) * V_24 , V_35 ) ;
if ( ! V_20 ) {
F_3 ( L_26
L_27 ) ;
goto V_41;
}
for ( V_30 = 0 ; V_30 < V_24 ; V_30 ++ ) {
if ( V_29 [ V_30 ] > V_25 ) {
F_17 ( L_28
L_29 , V_30 ) ;
continue;
}
F_25 ( & V_20 [ V_30 ] . V_17 . V_20 ) ;
V_20 [ V_30 ] . V_1 = V_28 [ V_30 ] ;
V_20 [ V_30 ] . V_22 = V_29 [ V_30 ] ;
if ( F_26 ( V_27 , L_12 , V_30 ,
& V_20 [ V_30 ] . V_17 . V_20 . V_37 ) )
continue;
switch ( V_31 [ V_30 ] & 3 ) {
case V_42 :
V_20 [ V_30 ] . V_17 . V_20 . V_43 = V_44 ;
break;
case V_45 :
V_20 [ V_30 ] . V_17 . V_20 . V_43 = V_46 ;
break;
case V_47 :
V_20 [ V_30 ] . V_17 . V_20 . V_43 = V_44 | V_46 ;
break;
default:
break;
}
V_20 [ V_30 ] . V_17 . V_48 = F_11 ;
V_20 [ V_30 ] . V_17 . V_49 = F_15 ;
if ( F_27 ( V_34 , & V_20 [ V_30 ] . V_17 . V_20 ) ) {
F_3 ( L_30 ,
V_20 [ V_30 ] . V_17 . V_20 . V_37 ) ;
goto V_50;
}
}
F_28 ( V_31 ) ;
F_28 ( V_29 ) ;
F_28 ( V_28 ) ;
F_29 ( V_27 ) ;
return;
V_50:
F_28 ( V_20 ) ;
V_41:
F_28 ( V_31 ) ;
V_40:
F_28 ( V_29 ) ;
V_39:
F_28 ( V_28 ) ;
V_38:
F_28 ( V_23 ) ;
V_36:
F_30 ( V_34 ) ;
V_33:
F_29 ( V_27 ) ;
V_10:
return;
}
