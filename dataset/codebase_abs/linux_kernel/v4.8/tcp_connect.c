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
F_5 ( V_4 , V_18 ) ;
break;
case V_19 :
case V_20 :
F_6 ( V_4 ) ;
default:
break;
}
V_10:
F_7 ( & V_2 -> V_7 ) ;
F_2 ( V_2 ) ;
}
int F_8 ( struct V_3 * V_4 )
{
struct V_21 * V_1 = NULL ;
struct V_22 V_23 , V_24 ;
int V_25 ;
struct V_26 * V_27 = V_4 -> V_28 ;
struct V_5 * V_6 = V_4 -> V_11 ;
if ( V_4 -> V_29 > 0 && V_4 -> V_28 -> V_30 < 2 )
return - V_31 ;
F_9 ( & V_6 -> V_32 ) ;
if ( F_10 ( V_4 ) ) {
F_11 ( & V_6 -> V_32 ) ;
return 0 ;
}
V_25 = F_12 ( F_13 ( V_27 ) , V_33 ,
V_34 , V_35 , & V_1 ) ;
if ( V_25 < 0 )
goto V_10;
F_14 ( V_1 ) ;
V_23 . V_36 = V_37 ;
V_23 . V_38 . V_39 = ( V_40 V_41 ) V_27 -> V_42 ;
V_23 . V_43 = ( V_40 V_44 ) F_15 ( 0 ) ;
V_25 = V_1 -> V_45 -> V_46 ( V_1 , (struct V_47 * ) & V_23 , sizeof( V_23 ) ) ;
if ( V_25 ) {
F_4 ( L_2 ,
V_25 , & V_27 -> V_42 ) ;
goto V_10;
}
V_24 . V_36 = V_37 ;
V_24 . V_38 . V_39 = ( V_40 V_41 ) V_27 -> V_48 ;
V_24 . V_43 = ( V_40 V_44 ) F_15 ( V_49 ) ;
F_16 ( V_1 , V_4 ) ;
V_25 = V_1 -> V_45 -> V_50 ( V_1 , (struct V_47 * ) & V_24 , sizeof( V_24 ) ,
V_51 ) ;
V_4 -> V_52 = 1 ;
F_4 ( L_3 , & V_27 -> V_48 , V_25 ) ;
if ( V_25 == - V_53 )
V_25 = 0 ;
if ( V_25 == 0 ) {
F_17 ( V_1 ) ;
V_1 = NULL ;
} else {
F_18 ( V_1 , V_4 -> V_11 ) ;
}
V_10:
F_11 ( & V_6 -> V_32 ) ;
if ( V_1 )
F_19 ( V_1 ) ;
return V_25 ;
}
void F_20 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_11 ;
struct V_21 * V_1 = V_6 -> V_13 ;
F_4 ( L_4 ,
V_4 -> V_28 , V_6 , V_1 ) ;
if ( V_1 ) {
V_1 -> V_45 -> V_54 ( V_1 , V_55 | V_56 ) ;
F_21 ( V_1 -> V_2 ) ;
F_18 ( V_1 , V_6 ) ;
F_22 ( V_1 -> V_2 ) ;
F_19 ( V_1 ) ;
}
if ( V_6 -> V_57 ) {
F_23 ( & V_6 -> V_57 -> V_58 ) ;
V_6 -> V_57 = NULL ;
}
V_6 -> V_59 = sizeof( struct V_60 ) ;
V_6 -> V_61 = 0 ;
}
