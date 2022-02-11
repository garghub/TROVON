static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
if ( ! ( V_2 -> V_4 -> V_5 . V_6 & 1 ) ) {
T_2 V_7 = F_2 ( V_2 -> V_4 -> V_5 . V_8 ) ;
switch ( F_3 ( V_2 -> V_4 -> V_5 . V_9 ) ) {
case V_10 :
F_4 ( V_2 -> V_11 -> V_12 , V_7 ) ;
break;
default:
V_3 = V_13 | V_14 ;
break;
}
} else {
V_3 = V_13 | V_14 ;
}
F_5 ( V_2 , V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_15 * V_12 = V_2 -> V_11 -> V_12 ;
T_1 V_3 = 0 ;
T_2 V_7 = 0 ;
if ( V_2 -> V_4 -> V_16 . V_6 & 1 ) {
switch ( F_3 ( V_2 -> V_4 -> V_16 . V_9 ) ) {
case V_17 :
V_7 = V_12 -> V_18 ;
break;
default:
V_3 = V_13 | V_14 ;
break;
}
} else {
switch ( F_3 ( V_2 -> V_4 -> V_16 . V_9 ) ) {
case V_19 :
V_7 = V_12 -> V_20 -> V_21 ;
break;
case V_10 :
V_7 = V_12 -> V_22 ;
break;
case V_23 :
V_7 = V_12 -> V_24 ;
break;
default:
V_3 = V_13 | V_14 ;
break;
}
}
V_2 -> V_25 -> V_26 . T_2 = F_7 ( V_7 ) ;
F_5 ( V_2 , V_3 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_27 * V_4 = V_2 -> V_4 ;
V_2 -> V_28 = NULL ;
switch ( V_4 -> V_29 . V_30 ) {
case V_31 :
V_2 -> V_32 = 0 ;
V_2 -> V_33 = F_1 ;
break;
case V_34 :
V_2 -> V_32 = 0 ;
V_2 -> V_33 = F_6 ;
break;
default:
F_9 ( L_1 ,
V_4 -> V_29 . V_30 ) ;
return V_35 | V_14 ;
}
return 0 ;
}
static T_1 F_10 ( struct V_15 * V_12 , struct V_1 * V_2 )
{
struct V_36 * V_37 = & V_2 -> V_4 -> V_38 ;
T_1 V_39 = F_11 ( V_37 -> V_39 ) ;
T_1 V_40 = F_11 ( V_37 -> V_40 ) ;
struct V_15 * V_41 ;
V_41 = F_12 ( & V_2 -> V_11 -> V_12 , NULL , V_12 ) ;
if ( V_41 ) {
F_13 ( L_2 ) ;
return V_42 | V_14 ;
}
F_14 ( V_12 , V_2 -> V_43 , V_39 , V_40 ) ;
F_15 ( V_12 , V_2 -> V_11 , V_39 , V_40 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = & V_2 -> V_4 -> V_38 ;
struct V_44 * V_45 ;
struct V_15 * V_12 = NULL ;
T_1 V_3 = 0 ;
V_45 = F_17 ( F_18 ( V_2 -> V_46 ) ) + V_2 -> V_46 -> V_9 ;
V_2 -> V_25 -> V_26 . V_47 = 0 ;
if ( V_37 -> V_48 != 0 ) {
F_13 ( L_3 ,
F_11 ( V_37 -> V_48 ) ) ;
V_3 = V_49 | V_14 ;
goto V_50;
}
if ( F_19 ( V_45 -> V_51 != F_20 ( 0xffff ) ) ) {
F_13 ( L_4 ,
V_45 -> V_51 ) ;
V_3 = V_52 | V_14 ;
V_2 -> V_25 -> V_26 . V_47 = F_21 ( V_51 ) ;
goto V_50;
}
V_3 = F_22 ( V_45 -> V_53 , V_45 -> V_54 , V_2 ,
F_3 ( V_37 -> V_55 ) , & V_12 ) ;
if ( V_3 )
goto V_50;
V_3 = F_10 ( V_12 , V_2 ) ;
if ( V_3 ) {
F_23 ( V_12 ) ;
goto V_50;
}
F_24 ( L_5 ,
V_12 -> V_51 , V_12 -> V_20 -> V_53 , V_12 -> V_54 ) ;
V_2 -> V_25 -> V_26 . T_1 = F_20 ( V_12 -> V_51 ) ;
V_50:
F_25 ( F_18 ( V_2 -> V_46 ) ) ;
F_5 ( V_2 , V_3 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = & V_2 -> V_4 -> V_38 ;
struct V_44 * V_45 ;
struct V_15 * V_12 = NULL ;
T_1 V_39 = F_11 ( V_37 -> V_39 ) ;
T_1 V_3 = 0 ;
V_45 = F_17 ( F_18 ( V_2 -> V_46 ) ) + V_2 -> V_46 -> V_9 ;
V_2 -> V_25 -> V_26 . V_47 = 0 ;
if ( V_37 -> V_48 != 0 ) {
F_13 ( L_3 ,
F_11 ( V_37 -> V_48 ) ) ;
V_3 = V_49 | V_14 ;
goto V_50;
}
V_3 = F_27 ( V_45 -> V_53 , V_45 -> V_54 ,
F_11 ( V_45 -> V_51 ) ,
V_2 , & V_12 ) ;
if ( V_3 )
goto V_50;
if ( F_19 ( V_39 > V_12 -> V_20 -> V_56 ) ) {
F_13 ( L_6 , V_39 ) ;
V_3 = V_52 | V_14 ;
V_2 -> V_25 -> V_26 . V_47 = F_28 ( V_39 ) ;
goto V_57;
}
V_3 = F_10 ( V_12 , V_2 ) ;
if ( V_3 ) {
V_2 -> V_25 -> V_26 . T_1 = F_20 ( V_12 -> V_51 ) ;
goto V_57;
}
F_24 ( L_7 , V_39 , V_12 -> V_51 ) ;
V_50:
F_25 ( F_18 ( V_2 -> V_46 ) ) ;
F_5 ( V_2 , V_3 ) ;
return;
V_57:
F_23 ( V_12 ) ;
goto V_50;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_27 * V_4 = V_2 -> V_4 ;
V_2 -> V_28 = NULL ;
if ( V_4 -> V_58 . V_59 != V_60 ) {
F_9 ( L_8 ,
V_4 -> V_29 . V_59 ) ;
return V_35 | V_14 ;
}
if ( V_4 -> V_29 . V_30 != V_61 ) {
F_9 ( L_9 ,
V_4 -> V_29 . V_30 ) ;
return V_35 | V_14 ;
}
V_2 -> V_32 = sizeof( struct V_44 ) ;
if ( V_4 -> V_38 . V_39 == 0 )
V_2 -> V_33 = F_16 ;
else
V_2 -> V_33 = F_26 ;
return 0 ;
}
