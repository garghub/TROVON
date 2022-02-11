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
if ( V_6 != V_12 )
goto V_13;
V_6 = F_5 ( V_7 , & V_5 ) ;
if ( V_6 ) {
F_3 ( L_2 ,
V_9 , V_6 ) ;
goto V_13;
}
V_6 = F_6 ( V_5 . V_14 [ 1 ] ) ;
V_13:
F_7 ( V_7 ) ;
V_10:
return V_6 ;
}
static int F_8 ( T_2 V_1 , T_2 V_2 , void * V_3 )
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
V_6 = F_9 ( V_7 , V_1 , ( V_11 ) V_3 , V_2 ) ;
if ( V_6 != V_12 )
goto V_13;
V_6 = F_5 ( V_7 , & V_5 ) ;
if ( V_6 ) {
F_3 ( L_3 ,
V_9 , V_6 ) ;
goto V_13;
}
V_6 = F_6 ( V_5 . V_14 [ 1 ] ) ;
V_13:
F_7 ( V_7 ) ;
V_10:
return V_6 ;
}
static T_1 F_10 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_21 = F_11 ( V_18 , struct V_20 ,
V_18 ) ;
T_1 V_6 ;
F_12 ( & V_22 ) ;
V_6 = F_1 ( V_21 -> V_1 , V_21 -> V_23 ,
V_24 ) ;
if ( V_6 )
goto V_10;
memcpy ( V_19 , V_24 , V_21 -> V_23 ) ;
V_6 = V_21 -> V_23 ;
V_10:
F_13 ( & V_22 ) ;
return V_6 ;
}
static T_1 F_14 ( struct V_15 * V_16 ,
struct V_17 * V_18 , const char * V_19 , T_3 V_25 )
{
struct V_20 * V_21 = F_11 ( V_18 , struct V_20 ,
V_18 ) ;
T_1 V_6 ;
if ( V_25 > V_26 )
V_25 = V_26 ;
F_12 ( & V_22 ) ;
memcpy ( V_24 , V_19 , V_25 ) ;
V_6 = F_8 ( V_21 -> V_1 , V_21 -> V_23 ,
V_24 ) ;
F_13 ( & V_22 ) ;
if ( ! V_6 )
V_6 = V_25 ;
return V_6 ;
}
void T_4 F_15 ( void )
{
struct V_27 * V_28 ;
struct V_20 * V_21 ;
T_2 * V_29 , * V_30 ;
int V_25 , V_31 ;
T_5 * V_32 ;
if ( ! V_33 ) {
F_16 ( L_4 ) ;
goto V_10;
}
V_34 = F_17 ( L_5 , V_33 ) ;
if ( ! V_34 ) {
F_3 ( L_6 ) ;
goto V_10;
}
V_24 = F_18 ( V_26 , V_35 ) ;
if ( ! V_24 ) {
F_3 ( L_7
L_8 ) ;
goto V_36;
}
V_28 = F_19 ( L_9 ) ;
if ( ! V_28 ) {
F_3 ( L_10 ) ;
goto V_37;
}
if ( ! F_20 ( V_28 , L_11 ) ) {
F_3 ( L_12 ) ;
goto V_38;
}
V_25 = F_21 ( V_28 , L_13 ) ;
if ( V_25 < 0 ) {
F_3 ( L_14
L_15 , V_28 -> V_39 ) ;
goto V_38;
}
V_29 = F_18 ( sizeof( * V_29 ) * V_25 , V_35 ) ;
if ( ! V_29 ) {
F_3 ( L_16
L_17 ) ;
goto V_38;
}
V_30 = F_18 ( sizeof( * V_30 ) * V_25 , V_35 ) ;
if ( ! V_30 ) {
F_3 ( L_16
L_18 ) ;
goto V_40;
}
V_32 = F_18 ( sizeof( * V_32 ) * V_25 , V_35 ) ;
if ( ! V_32 ) {
F_3 ( L_19
L_20 ) ;
goto V_41;
}
if ( F_22 ( V_28 , L_21 , V_29 , V_25 ) ) {
F_3 ( L_22 ) ;
goto V_42;
}
if ( F_22 ( V_28 , L_23 , V_30 , V_25 ) ) {
F_3 ( L_24 ) ;
goto V_42;
}
if ( F_23 ( V_28 , L_25 , V_32 , V_25 ) ) {
F_3 ( L_26 ) ;
goto V_42;
}
V_21 = F_18 ( sizeof( * V_21 ) * V_25 , V_35 ) ;
if ( ! V_21 ) {
F_3 ( L_27
L_28 ) ;
goto V_42;
}
for ( V_31 = 0 ; V_31 < V_25 ; V_31 ++ ) {
if ( V_30 [ V_31 ] > V_26 ) {
F_16 ( L_29
L_30 , V_31 ) ;
continue;
}
F_24 ( & V_21 [ V_31 ] . V_18 . V_21 ) ;
V_21 [ V_31 ] . V_1 = V_29 [ V_31 ] ;
V_21 [ V_31 ] . V_23 = V_30 [ V_31 ] ;
if ( F_25 ( V_28 , L_13 , V_31 ,
& V_21 [ V_31 ] . V_18 . V_21 . V_39 ) )
continue;
switch ( V_32 [ V_31 ] & 3 ) {
case V_43 :
V_21 [ V_31 ] . V_18 . V_21 . V_44 = V_45 ;
break;
case V_46 :
V_21 [ V_31 ] . V_18 . V_21 . V_44 = V_47 ;
break;
case V_48 :
V_21 [ V_31 ] . V_18 . V_21 . V_44 = V_45 | V_47 ;
break;
default:
break;
}
V_21 [ V_31 ] . V_18 . V_49 = F_10 ;
V_21 [ V_31 ] . V_18 . V_50 = F_14 ;
if ( F_26 ( V_34 , & V_21 [ V_31 ] . V_18 . V_21 ) ) {
F_3 ( L_31 ,
V_21 [ V_31 ] . V_18 . V_21 . V_39 ) ;
goto V_51;
}
}
F_27 ( V_32 ) ;
F_27 ( V_30 ) ;
F_27 ( V_29 ) ;
F_28 ( V_28 ) ;
return;
V_51:
F_27 ( V_21 ) ;
V_42:
F_27 ( V_32 ) ;
V_41:
F_27 ( V_30 ) ;
V_40:
F_27 ( V_29 ) ;
V_38:
F_28 ( V_28 ) ;
V_37:
F_27 ( V_24 ) ;
V_36:
F_29 ( V_34 ) ;
V_10:
return;
}
