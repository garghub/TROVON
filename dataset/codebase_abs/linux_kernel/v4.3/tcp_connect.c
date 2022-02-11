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
switch( V_2 -> V_14 ) {
case V_15 :
case V_16 :
break;
case V_17 :
F_5 ( V_4 ) ;
break;
case V_18 :
case V_19 :
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
struct V_20 * V_1 = NULL ;
struct V_21 V_22 , V_23 ;
int V_24 ;
V_24 = F_9 ( F_10 ( V_4 ) , V_25 ,
V_26 , V_27 , & V_1 ) ;
if ( V_24 < 0 )
goto V_10;
F_11 ( V_1 ) ;
V_22 . V_28 = V_29 ;
V_22 . V_30 . V_31 = ( V_32 V_33 ) V_4 -> V_34 ;
V_22 . V_35 = ( V_32 V_36 ) F_12 ( 0 ) ;
V_24 = V_1 -> V_37 -> V_38 ( V_1 , (struct V_39 * ) & V_22 , sizeof( V_22 ) ) ;
if ( V_24 ) {
F_4 ( L_2 ,
V_24 , & V_4 -> V_34 ) ;
goto V_10;
}
V_23 . V_28 = V_29 ;
V_23 . V_30 . V_31 = ( V_32 V_33 ) V_4 -> V_40 ;
V_23 . V_35 = ( V_32 V_36 ) F_12 ( V_41 ) ;
F_13 ( V_1 , V_4 ) ;
V_24 = V_1 -> V_37 -> V_42 ( V_1 , (struct V_39 * ) & V_23 , sizeof( V_23 ) ,
V_43 ) ;
F_4 ( L_3 , & V_4 -> V_40 , V_24 ) ;
if ( V_24 == - V_44 )
V_24 = 0 ;
if ( V_24 == 0 ) {
F_14 ( V_1 ) ;
V_1 = NULL ;
} else {
F_15 ( V_1 , V_4 -> V_11 ) ;
}
V_10:
if ( V_1 )
F_16 ( V_1 ) ;
return V_24 ;
}
void F_17 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_11 ;
struct V_20 * V_1 = V_6 -> V_13 ;
F_4 ( L_4 , V_4 , V_6 , V_1 ) ;
if ( V_1 ) {
V_1 -> V_37 -> V_45 ( V_1 , V_46 | V_47 ) ;
F_18 ( V_1 -> V_2 ) ;
F_15 ( V_1 , V_6 ) ;
F_19 ( V_1 -> V_2 ) ;
F_16 ( V_1 ) ;
}
if ( V_6 -> V_48 ) {
F_20 ( & V_6 -> V_48 -> V_49 ) ;
V_6 -> V_48 = NULL ;
}
V_6 -> V_50 = sizeof( struct V_51 ) ;
V_6 -> V_52 = 0 ;
}
