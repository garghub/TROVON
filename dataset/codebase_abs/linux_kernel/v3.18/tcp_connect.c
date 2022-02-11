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
struct V_19 * V_1 = NULL ;
struct V_20 V_21 , V_22 ;
int V_23 ;
V_23 = F_9 ( V_24 , V_25 , V_26 , & V_1 ) ;
if ( V_23 < 0 )
goto V_10;
F_10 ( V_1 ) ;
V_21 . V_27 = V_28 ;
V_21 . V_29 . V_30 = ( V_31 V_32 ) V_4 -> V_33 ;
V_21 . V_34 = ( V_31 V_35 ) F_11 ( 0 ) ;
V_23 = V_1 -> V_36 -> V_37 ( V_1 , (struct V_38 * ) & V_21 , sizeof( V_21 ) ) ;
if ( V_23 ) {
F_4 ( L_2 ,
V_23 , & V_4 -> V_33 ) ;
goto V_10;
}
V_22 . V_27 = V_28 ;
V_22 . V_29 . V_30 = ( V_31 V_32 ) V_4 -> V_39 ;
V_22 . V_34 = ( V_31 V_35 ) F_11 ( V_40 ) ;
F_12 ( V_1 , V_4 ) ;
V_23 = V_1 -> V_36 -> V_41 ( V_1 , (struct V_38 * ) & V_22 , sizeof( V_22 ) ,
V_42 ) ;
F_4 ( L_3 , & V_4 -> V_39 , V_23 ) ;
if ( V_23 == - V_43 )
V_23 = 0 ;
if ( V_23 == 0 )
V_1 = NULL ;
else
F_13 ( V_1 , V_4 -> V_11 ) ;
V_10:
if ( V_1 )
F_14 ( V_1 ) ;
return V_23 ;
}
void F_15 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_11 ;
struct V_19 * V_1 = V_6 -> V_13 ;
F_4 ( L_4 , V_4 , V_6 , V_1 ) ;
if ( V_1 ) {
V_1 -> V_36 -> V_44 ( V_1 , V_45 | V_46 ) ;
F_16 ( V_1 -> V_2 ) ;
F_13 ( V_1 , V_6 ) ;
F_17 ( V_1 -> V_2 ) ;
F_14 ( V_1 ) ;
}
if ( V_6 -> V_47 ) {
F_18 ( & V_6 -> V_47 -> V_48 ) ;
V_6 -> V_47 = NULL ;
}
V_6 -> V_49 = sizeof( struct V_50 ) ;
V_6 -> V_51 = 0 ;
}
