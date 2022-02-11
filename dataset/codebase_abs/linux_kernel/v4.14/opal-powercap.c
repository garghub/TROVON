static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ,
struct V_6 , V_4 ) ;
struct V_8 V_9 ;
T_2 V_10 ;
int V_11 , V_12 ;
V_12 = F_3 () ;
if ( V_12 < 0 ) {
F_4 ( L_1 ) ;
return V_12 ;
}
V_11 = F_5 ( & V_13 ) ;
if ( V_11 )
goto V_14;
V_11 = F_6 ( V_7 -> V_15 , V_12 , ( T_2 * ) F_7 ( & V_10 ) ) ;
switch ( V_11 ) {
case V_16 :
V_11 = F_8 ( V_12 , & V_9 ) ;
if ( V_11 ) {
F_4 ( L_2 ) ;
V_11 = - V_17 ;
goto V_18;
}
V_11 = F_9 ( F_10 ( V_9 ) ) ;
if ( ! V_11 ) {
V_11 = sprintf ( V_5 , L_3 , F_11 ( V_10 ) ) ;
if ( V_11 < 0 )
V_11 = - V_17 ;
}
break;
case V_19 :
V_11 = sprintf ( V_5 , L_3 , F_11 ( V_10 ) ) ;
if ( V_11 < 0 )
V_11 = - V_17 ;
break;
default:
V_11 = F_9 ( V_11 ) ;
}
V_18:
F_12 ( & V_13 ) ;
V_14:
F_13 ( V_12 ) ;
return V_11 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 ,
T_3 V_20 )
{
struct V_6 * V_7 = F_2 ( V_4 ,
struct V_6 , V_4 ) ;
struct V_8 V_9 ;
T_2 V_10 ;
int V_11 , V_12 ;
V_11 = F_15 ( V_5 , 0 , & V_10 ) ;
if ( V_11 )
return V_11 ;
V_12 = F_3 () ;
if ( V_12 < 0 ) {
F_4 ( L_1 ) ;
return V_12 ;
}
V_11 = F_5 ( & V_13 ) ;
if ( V_11 )
goto V_14;
V_11 = F_16 ( V_7 -> V_15 , V_12 , V_10 ) ;
switch ( V_11 ) {
case V_16 :
V_11 = F_8 ( V_12 , & V_9 ) ;
if ( V_11 ) {
F_4 ( L_2 ) ;
V_11 = - V_17 ;
goto V_18;
}
V_11 = F_9 ( F_10 ( V_9 ) ) ;
if ( ! V_11 )
V_11 = V_20 ;
break;
case V_19 :
V_11 = V_20 ;
break;
default:
V_11 = F_9 ( V_11 ) ;
}
V_18:
F_12 ( & V_13 ) ;
V_14:
F_13 ( V_12 ) ;
return V_11 ;
}
static void F_17 ( int V_15 , const char * V_21 ,
struct V_6 * V_4 )
{
V_4 -> V_15 = V_15 ;
F_18 ( & V_4 -> V_4 . V_4 ) ;
V_4 -> V_4 . V_4 . V_21 = V_21 ;
V_4 -> V_4 . V_4 . V_22 = 0444 ;
V_4 -> V_4 . V_23 = F_1 ;
}
void T_4 F_19 ( void )
{
struct V_24 * V_25 , * V_26 ;
int V_27 = 0 ;
V_25 = F_20 ( NULL , NULL , L_4 ) ;
if ( ! V_25 ) {
F_4 ( L_5 ) ;
return;
}
V_28 = F_21 ( F_22 ( V_25 ) , sizeof( * V_28 ) ,
V_29 ) ;
if ( ! V_28 )
return;
V_30 = F_23 ( L_6 , V_31 ) ;
if ( ! V_30 ) {
F_24 ( L_7 ) ;
goto V_32;
}
V_27 = 0 ;
F_25 (powercap, node) {
T_2 V_33 , V_34 , V_35 ;
int V_36 = 0 ;
bool V_37 = false , V_38 = false , V_39 = false ;
if ( ! F_26 ( V_26 , L_8 , & V_34 ) ) {
V_36 ++ ;
V_38 = true ;
}
if ( ! F_26 ( V_26 , L_9 , & V_35 ) ) {
V_36 ++ ;
V_39 = true ;
}
if ( ! F_26 ( V_26 , L_10 , & V_33 ) ) {
V_36 ++ ;
V_37 = true ;
}
V_28 [ V_27 ] . V_40 = F_21 ( V_36 , sizeof( struct V_6 ) ,
V_29 ) ;
if ( ! V_28 [ V_27 ] . V_40 )
goto V_41;
V_28 [ V_27 ] . V_42 . V_43 = F_21 ( V_36 + 1 , sizeof( struct V_44 * ) ,
V_29 ) ;
if ( ! V_28 [ V_27 ] . V_42 . V_43 ) {
F_27 ( V_28 [ V_27 ] . V_40 ) ;
goto V_41;
}
V_36 = 0 ;
V_28 [ V_27 ] . V_42 . V_21 = V_26 -> V_21 ;
if ( V_38 ) {
F_17 ( V_34 , L_8 ,
& V_28 [ V_27 ] . V_40 [ V_36 ] ) ;
V_28 [ V_27 ] . V_42 . V_43 [ V_36 ] = & V_28 [ V_27 ] . V_40 [ V_36 ] . V_4 . V_4 ;
V_36 ++ ;
}
if ( V_39 ) {
F_17 ( V_35 , L_9 ,
& V_28 [ V_27 ] . V_40 [ V_36 ] ) ;
V_28 [ V_27 ] . V_42 . V_43 [ V_36 ] = & V_28 [ V_27 ] . V_40 [ V_36 ] . V_4 . V_4 ;
V_36 ++ ;
}
if ( V_37 ) {
F_17 ( V_33 , L_10 ,
& V_28 [ V_27 ] . V_40 [ V_36 ] ) ;
V_28 [ V_27 ] . V_40 [ V_36 ] . V_4 . V_4 . V_22 |= 0220 ;
V_28 [ V_27 ] . V_40 [ V_36 ] . V_4 . V_45 = F_14 ;
V_28 [ V_27 ] . V_42 . V_43 [ V_36 ] = & V_28 [ V_27 ] . V_40 [ V_36 ] . V_4 . V_4 ;
V_36 ++ ;
}
if ( F_28 ( V_30 , & V_28 [ V_27 ] . V_42 ) ) {
F_24 ( L_11 ,
V_28 [ V_27 ] . V_42 . V_21 ) ;
goto V_41;
}
V_27 ++ ;
}
return;
V_41:
while ( -- V_27 >= 0 ) {
F_27 ( V_28 [ V_27 ] . V_40 ) ;
F_27 ( V_28 [ V_27 ] . V_42 . V_43 ) ;
}
F_29 ( V_30 ) ;
V_32:
F_27 ( V_28 ) ;
}
