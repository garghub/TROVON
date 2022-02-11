T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_3 * V_5 ;
T_1 V_6 = V_7 ;
F_2 ( V_8 ) ;
V_5 = (struct V_3 * ) V_2 -> V_9 [ 0 ] ;
V_4 = (struct V_3 * ) V_2 -> V_9 [ 1 ] ;
if ( ( V_4 -> type == V_10 ) ||
( V_4 -> type == V_11 ) ) {
V_4 =
F_3 ( struct V_3 ,
V_4 -> V_12 ) ;
}
switch ( V_4 -> type ) {
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
V_5 -> type = V_10 ;
V_5 -> V_12 =
F_3 ( union V_23 , V_4 ) ;
break;
case V_24 :
V_5 -> type = V_11 ;
V_5 -> V_12 =
F_3 ( union V_23 , V_4 ) ;
break;
default:
V_6 = F_4 ( V_5 ,
F_5
( V_4 ) ,
V_4 -> type ) ;
break;
}
F_6 ( V_6 ) ;
}
T_1 F_7 ( struct V_1 * V_2 )
{
T_1 V_6 ;
union V_23 * V_25 ;
F_2 ( V_26 ) ;
V_25 = F_8 ( V_27 ) ;
if ( ! V_25 ) {
V_6 = V_28 ;
goto V_29;
}
V_6 = F_9 ( V_30 , 0 ,
& V_25 -> V_31 . V_32 ) ;
if ( F_10 ( V_6 ) ) {
goto V_29;
}
V_6 =
F_4 ( (struct V_3 * ) V_2 ->
V_9 [ 0 ] , V_25 , V_27 ) ;
V_29:
F_11 ( V_25 ) ;
F_6 ( V_6 ) ;
}
T_1 F_12 ( struct V_1 * V_2 )
{
T_1 V_6 = V_7 ;
union V_23 * V_25 ;
F_13 ( V_33 , V_34 ) ;
V_25 = F_8 ( V_35 ) ;
if ( ! V_25 ) {
V_6 = V_28 ;
goto V_29;
}
V_6 = F_14 ( & V_25 -> V_36 . V_37 ) ;
if ( F_10 ( V_6 ) ) {
goto V_29;
}
V_25 -> V_36 . V_38 = ( V_39 ) V_2 -> V_9 [ 1 ] -> integer . V_40 ;
V_25 -> V_36 . V_41 =
(struct V_3 * ) V_2 -> V_9 [ 0 ] ;
V_6 =
F_4 ( V_25 -> V_36 . V_41 , V_25 ,
V_35 ) ;
V_29:
F_11 ( V_25 ) ;
F_6 ( V_6 ) ;
}
T_1
F_15 ( V_39 * V_42 ,
T_2 V_43 ,
V_39 V_44 , struct V_1 * V_2 )
{
T_1 V_6 ;
union V_23 * V_25 ;
struct V_3 * V_41 ;
union V_23 * V_45 ;
F_2 ( V_46 ) ;
V_41 = V_2 -> V_47 -> V_48 . V_41 ;
if ( F_5 ( V_41 ) ) {
F_6 ( V_7 ) ;
}
if ( ! F_16 ( V_44 ) ) {
F_17 ( ( V_49 ,
L_1 ,
V_44 ) ) ;
}
F_18 ( ( V_50 , L_2 ,
F_19 ( V_44 ) , V_44 ) ) ;
V_25 = F_8 ( V_51 ) ;
if ( ! V_25 ) {
V_6 = V_28 ;
goto V_29;
}
V_45 = V_25 -> V_48 . V_52 ;
V_45 -> V_53 . V_42 = V_42 ;
V_45 -> V_53 . V_43 = V_43 ;
if ( V_2 -> V_54 ) {
V_45 -> V_53 . V_55 =
V_2 -> V_54 -> V_56 . V_41 ;
} else {
V_45 -> V_53 . V_55 = V_41 ;
}
V_25 -> V_57 . V_44 = V_44 ;
V_25 -> V_57 . V_58 = 0 ;
V_25 -> V_57 . V_59 = 0 ;
V_25 -> V_57 . V_41 = V_41 ;
V_6 = F_4 ( V_41 , V_25 , V_51 ) ;
V_29:
F_11 ( V_25 ) ;
F_6 ( V_6 ) ;
}
T_1 F_20 ( struct V_1 * V_2 )
{
union V_23 * * V_60 = & V_2 -> V_9 [ 0 ] ;
union V_23 * V_25 ;
T_1 V_6 ;
F_13 ( V_61 , V_2 ) ;
V_25 = F_8 ( V_20 ) ;
if ( ! V_25 ) {
F_6 ( V_28 ) ;
}
V_25 -> V_62 . V_63 = ( V_39 ) V_60 [ 1 ] -> integer . V_40 ;
V_25 -> V_62 . V_59 = ( V_39 ) V_60 [ 3 ] -> integer . V_40 ;
V_25 -> V_62 . V_58 =
( V_64 ) V_60 [ 2 ] -> integer . V_40 ;
V_6 = F_4 ( (struct V_3 * ) V_60 [ 0 ] ,
V_25 , V_20 ) ;
F_11 ( V_25 ) ;
F_6 ( V_6 ) ;
}
T_1 F_21 ( struct V_1 * V_2 )
{
union V_23 * * V_60 = & V_2 -> V_9 [ 0 ] ;
T_1 V_6 ;
union V_23 * V_25 ;
F_13 ( V_65 , V_2 ) ;
V_25 = F_8 ( V_19 ) ;
if ( ! V_25 ) {
F_6 ( V_28 ) ;
}
V_25 -> V_66 . V_67 = ( V_39 ) V_60 [ 1 ] -> integer . V_40 ;
V_25 -> V_66 . V_68 =
( V_69 ) V_60 [ 2 ] -> integer . V_40 ;
V_6 = F_4 ( (struct V_3 * ) V_60 [ 0 ] ,
V_25 , V_19 ) ;
F_11 ( V_25 ) ;
F_6 ( V_6 ) ;
}
T_1
F_22 ( V_39 * V_42 ,
T_2 V_43 , struct V_1 * V_2 )
{
union V_23 * * V_60 = & V_2 -> V_9 [ 0 ] ;
union V_23 * V_25 ;
T_1 V_6 ;
V_39 V_70 ;
F_13 ( V_71 , V_2 ) ;
V_25 = F_8 ( V_24 ) ;
if ( ! V_25 ) {
V_6 = V_28 ;
goto exit;
}
V_25 -> V_72 . V_42 = V_42 ;
V_25 -> V_72 . V_43 = V_43 ;
V_25 -> V_72 . V_41 = V_60 [ 0 ] ;
V_70 = ( V_39 ) V_60 [ 1 ] -> integer . V_40 ;
V_25 -> V_72 . V_73 =
( V_39 ) ( V_70 & V_74 ) ;
if ( V_70 & V_75 ) {
V_25 -> V_72 . V_76 = V_77 ;
V_25 -> V_72 . V_38 = ( V_39 )
( ( V_70 & V_78 ) >> 4 ) ;
}
V_6 = F_4 ( (struct V_3 * ) V_60 [ 0 ] ,
V_25 , V_24 ) ;
F_11 ( V_25 ) ;
exit:
F_11 ( V_60 [ 1 ] ) ;
F_6 ( V_6 ) ;
}
