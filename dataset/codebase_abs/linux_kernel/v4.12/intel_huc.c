static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
unsigned long V_9 = 0 ;
T_1 V_10 ;
int V_11 ;
V_11 = F_2 ( V_4 -> V_12 , false ) ;
if ( V_11 ) {
F_3 ( L_1 , V_11 ) ;
return V_11 ;
}
V_8 = F_4 ( V_4 -> V_12 , NULL , 0 , 0 ,
V_13 | V_14 ) ;
if ( F_5 ( V_8 ) ) {
F_3 ( L_2 , ( int ) F_6 ( V_8 ) ) ;
return F_6 ( V_8 ) ;
}
F_7 ( V_2 , V_15 ) ;
F_8 ( V_16 , F_9 ( V_2 ) ) ;
F_8 ( V_17 , V_18 |
V_19 ) ;
V_9 = F_10 ( V_8 ) + V_4 -> V_20 ;
F_8 ( V_21 , F_11 ( V_9 ) ) ;
F_8 ( V_22 , F_12 ( V_9 ) & 0xFFFF ) ;
F_8 ( V_23 , 0 ) ;
F_8 ( V_24 , V_25 ) ;
V_10 = V_4 -> V_26 + V_4 -> V_27 ;
F_8 ( V_28 , V_10 ) ;
F_8 ( V_29 , F_13 ( V_30 | V_31 ) ) ;
V_11 = F_14 ( ( F_15 ( V_29 ) & V_31 ) == 0 , 100 ) ;
F_3 ( L_3 , V_11 ) ;
F_8 ( V_29 , F_16 ( V_30 ) ) ;
F_17 ( V_2 , V_15 ) ;
F_18 ( V_8 ) ;
return V_11 ;
}
void F_19 ( struct V_32 * V_5 )
{
struct V_1 * V_2 = F_20 ( V_5 ) ;
V_5 -> V_6 . V_33 = NULL ;
V_5 -> V_6 . V_34 = V_35 ;
V_5 -> V_6 . V_36 = V_35 ;
V_5 -> V_6 . type = V_37 ;
if ( V_38 . V_39 ) {
V_5 -> V_6 . V_33 = V_38 . V_39 ;
V_5 -> V_6 . V_40 = 0 ;
V_5 -> V_6 . V_41 = 0 ;
} else if ( F_21 ( V_2 ) ) {
V_5 -> V_6 . V_33 = V_42 ;
V_5 -> V_6 . V_40 = V_43 ;
V_5 -> V_6 . V_41 = V_44 ;
} else if ( F_22 ( V_2 ) ) {
V_5 -> V_6 . V_33 = V_45 ;
V_5 -> V_6 . V_40 = V_46 ;
V_5 -> V_6 . V_41 = V_47 ;
} else if ( F_23 ( V_2 ) ) {
V_5 -> V_6 . V_33 = V_48 ;
V_5 -> V_6 . V_40 = V_49 ;
V_5 -> V_6 . V_41 = V_50 ;
} else {
F_24 ( L_4 ) ;
return;
}
}
int F_25 ( struct V_32 * V_5 )
{
struct V_1 * V_2 = F_20 ( V_5 ) ;
int V_51 ;
if ( V_5 -> V_6 . V_34 == V_35 )
return 0 ;
F_3 ( L_5 ,
V_5 -> V_6 . V_33 ,
F_26 ( V_5 -> V_6 . V_34 ) ,
F_26 ( V_5 -> V_6 . V_36 ) ) ;
if ( V_5 -> V_6 . V_34 == V_52 &&
V_5 -> V_6 . V_36 == V_53 )
return - V_54 ;
V_5 -> V_6 . V_36 = V_55 ;
switch ( V_5 -> V_6 . V_34 ) {
case V_53 :
V_51 = - V_56 ;
goto V_57;
case V_35 :
case V_55 :
default:
F_27 ( 1 , L_6 ,
V_5 -> V_6 . V_33 ,
F_26 ( V_5 -> V_6 . V_34 ) ,
V_5 -> V_6 . V_34 ) ;
V_51 = - V_58 ;
goto V_57;
case V_52 :
break;
}
V_51 = F_1 ( V_2 ) ;
if ( V_51 )
goto V_57;
V_5 -> V_6 . V_36 = V_52 ;
F_3 ( L_5 ,
V_5 -> V_6 . V_33 ,
F_26 ( V_5 -> V_6 . V_34 ) ,
F_26 ( V_5 -> V_6 . V_36 ) ) ;
return 0 ;
V_57:
if ( V_5 -> V_6 . V_36 == V_55 )
V_5 -> V_6 . V_36 = V_53 ;
F_24 ( L_7 , V_51 ) ;
return V_51 ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = & V_2 -> V_60 ;
struct V_32 * V_5 = & V_2 -> V_5 ;
struct V_7 * V_8 ;
int V_11 ;
T_1 V_61 [ 2 ] ;
if ( V_5 -> V_6 . V_36 != V_52 )
return;
V_8 = F_4 ( V_5 -> V_6 . V_12 , NULL , 0 , 0 ,
V_13 | V_14 ) ;
if ( F_5 ( V_8 ) ) {
F_24 ( L_8 ,
( int ) F_6 ( V_8 ) ) ;
return;
}
V_61 [ 0 ] = V_62 ;
V_61 [ 1 ] = F_10 ( V_8 ) + V_5 -> V_6 . V_63 ;
V_11 = F_29 ( V_60 , V_61 , F_30 ( V_61 ) ) ;
if ( V_11 ) {
F_24 ( L_9 , V_11 ) ;
goto V_64;
}
V_11 = F_31 ( V_2 ,
V_65 ,
V_66 ,
V_66 ,
50 ) ;
if ( V_11 ) {
F_24 ( L_10 , V_11 ) ;
goto V_64;
}
V_64:
F_18 ( V_8 ) ;
}
