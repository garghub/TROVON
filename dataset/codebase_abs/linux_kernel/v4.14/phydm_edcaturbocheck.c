void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
V_3 -> V_4 . V_5 = false ;
V_3 -> V_4 . V_6 = false ;
F_2 ( V_3 , V_7 , L_1 ,
F_3 ( V_3 , V_8 ) ) ;
F_2 ( V_3 , V_7 , L_2 ,
F_3 ( V_3 , V_9 ) ) ;
F_2 ( V_3 , V_7 , L_3 ,
F_3 ( V_3 , V_10 ) ) ;
F_2 ( V_3 , V_7 , L_4 ,
F_3 ( V_3 , V_11 ) ) ;
}
void F_4 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( V_3 , V_7 ,
L_5 , V_12 ) ;
if ( ! ( V_3 -> V_13 & V_14 ) )
return;
switch ( V_3 -> V_15 ) {
case V_16 :
break;
case V_17 :
F_5 ( V_3 ) ;
break;
}
F_2 ( V_3 , V_7 ,
L_6 , V_12 ) ;
}
void F_5 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_18 * V_19 = (struct V_18 * ) V_3 -> V_20 ;
T_1 V_21 = 0 ;
T_1 V_22 = 0 ;
T_2 V_23 = 0x5ea42b ;
T_2 V_24 = 0x5ea42b ;
T_2 V_25 = 0x5ea42b ;
bool V_26 ;
bool V_27 = false ;
if ( V_3 -> V_28 )
return;
if ( ! V_3 -> V_29 ) {
V_19 -> V_3 . V_30 = false ;
return;
}
if ( V_19 -> V_3 . V_31 . V_32 > 0x100 )
V_19 -> V_3 . V_30 = true ;
V_19 -> V_3 . V_31 . V_32 = 0 ;
V_21 = V_19 -> V_33 . V_34 ;
V_22 = V_19 -> V_33 . V_35 ;
V_27 = ( ( ! V_19 -> V_3 . V_30 ) &&
( ! V_19 -> V_3 . V_36 ) ) ?
true :
false ;
if ( V_19 -> V_37 . V_38 == V_39 )
goto V_40;
if ( V_27 ) {
V_26 =
( V_22 > V_21 * 4 ) ? true : false ;
V_25 = V_26 ? V_24 : V_23 ;
F_6 ( V_19 , V_41 , V_25 ) ;
V_19 -> V_3 . V_26 = V_26 ;
V_19 -> V_3 . V_42 = true ;
} else {
if ( V_19 -> V_3 . V_42 ) {
T_3 V_43 = V_44 ;
V_19 -> V_45 -> V_46 -> V_47 ( V_19 -> V_48 ,
V_49 ,
( T_3 * ) ( & V_43 ) ) ;
V_19 -> V_3 . V_42 = false ;
}
}
V_40:
V_19 -> V_3 . V_30 = false ;
}
