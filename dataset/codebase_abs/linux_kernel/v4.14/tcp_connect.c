void F_1 ( struct V_1 * V_2 )
{
void (* F_2)( struct V_1 * V_2 );
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_3 ( & V_2 -> V_7 ) ;
V_4 = V_2 -> V_8 ;
if ( ! V_4 ) {
F_2 = V_2 -> V_9 ;
goto V_10;
}
V_6 = V_4 -> V_11 ;
F_2 = V_6 -> V_12 ;
F_4 ( L_1 , V_6 -> V_13 , V_2 -> V_14 ) ;
switch ( V_2 -> V_14 ) {
case V_15 :
case V_16 :
break;
case V_17 :
if ( ! F_5 ( V_4 -> V_18 -> V_19 , V_4 -> V_18 -> V_20 ) &&
F_6 ( V_4 , V_21 ,
V_22 ) ) {
F_7 ( V_4 , false ) ;
} else {
F_8 ( V_4 , V_21 ) ;
}
break;
case V_23 :
case V_24 :
F_7 ( V_4 , false ) ;
default:
break;
}
V_10:
F_9 ( & V_2 -> V_7 ) ;
F_2 ( V_2 ) ;
}
int F_10 ( struct V_3 * V_4 )
{
struct V_25 * V_1 = NULL ;
struct V_26 V_27 , V_28 ;
int V_29 ;
struct V_30 * V_31 = V_4 -> V_18 ;
struct V_5 * V_6 = V_4 -> V_11 ;
if ( V_4 -> V_32 > 0 && V_4 -> V_18 -> V_33 < 2 )
return - V_34 ;
F_11 ( & V_6 -> V_35 ) ;
if ( F_12 ( V_4 ) ) {
F_13 ( & V_6 -> V_35 ) ;
return 0 ;
}
V_29 = F_14 ( F_15 ( V_31 ) , V_36 ,
V_37 , V_38 , & V_1 ) ;
if ( V_29 < 0 )
goto V_10;
F_16 ( V_1 ) ;
V_27 . V_39 = V_40 ;
V_27 . V_41 . V_42 = ( V_43 V_44 ) V_31 -> V_19 ;
V_27 . V_45 = ( V_43 V_46 ) F_17 ( 0 ) ;
V_29 = V_1 -> V_47 -> V_48 ( V_1 , (struct V_49 * ) & V_27 , sizeof( V_27 ) ) ;
if ( V_29 ) {
F_4 ( L_2 ,
V_29 , & V_31 -> V_19 ) ;
goto V_10;
}
V_28 . V_39 = V_40 ;
V_28 . V_41 . V_42 = ( V_43 V_44 ) V_31 -> V_20 ;
V_28 . V_45 = ( V_43 V_46 ) F_17 ( V_50 ) ;
F_18 ( V_1 , V_4 ) ;
V_29 = V_1 -> V_47 -> V_51 ( V_1 , (struct V_49 * ) & V_28 , sizeof( V_28 ) ,
V_52 ) ;
F_4 ( L_3 , & V_31 -> V_20 , V_29 ) ;
if ( V_29 == - V_53 )
V_29 = 0 ;
if ( V_29 == 0 ) {
F_19 ( V_1 ) ;
V_1 = NULL ;
} else {
F_20 ( V_1 , V_4 -> V_11 ) ;
}
V_10:
F_13 ( & V_6 -> V_35 ) ;
if ( V_1 )
F_21 ( V_1 ) ;
return V_29 ;
}
void F_22 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_11 ;
struct V_25 * V_1 = V_6 -> V_13 ;
F_4 ( L_4 ,
V_4 -> V_18 , V_6 , V_1 ) ;
if ( V_1 ) {
if ( V_4 -> V_18 -> V_54 )
F_23 ( V_1 ) ;
V_1 -> V_47 -> V_55 ( V_1 , V_56 | V_57 ) ;
F_24 ( V_1 -> V_2 ) ;
F_20 ( V_1 , V_6 ) ;
F_25 ( V_1 -> V_2 ) ;
F_21 ( V_1 ) ;
}
if ( V_6 -> V_58 ) {
F_26 ( & V_6 -> V_58 -> V_59 ) ;
V_6 -> V_58 = NULL ;
}
V_6 -> V_60 = sizeof( struct V_61 ) ;
V_6 -> V_62 = 0 ;
}
