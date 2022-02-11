int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return F_3 ( V_2 -> V_3 ,
V_4 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_7 ) ) {
return F_6 ( V_2 -> V_3 ,
V_8 , 1 ) ;
} else {
return F_6 ( V_2 -> V_3 ,
V_8 , 0 ) ;
}
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) )
return F_3 ( V_2 -> V_3 ,
V_9 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) )
return F_3 ( V_2 -> V_3 ,
V_10 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_11 ) )
return F_3 ( V_2 -> V_3 ,
V_12 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_11 ) )
return F_3 ( V_2 -> V_3 ,
V_13 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_2 -> V_16 ) ;
V_15 -> V_17 = false ;
V_15 -> V_18 = false ;
V_15 -> V_19 = false ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 , bool V_20 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_2 -> V_16 ) ;
if ( V_15 -> V_17 == V_20 )
return 0 ;
V_15 -> V_17 = V_20 ;
if ( V_20 ) {
F_14 ( V_2 -> V_21 ,
V_22 ,
V_23 ) ;
F_15 ( V_2 , true ) ;
F_1 ( V_2 ) ;
} else {
F_4 ( V_2 ) ;
F_15 ( V_2 , false ) ;
F_14 ( V_2 -> V_21 ,
V_22 ,
V_24 ) ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , bool V_20 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_2 -> V_16 ) ;
if ( V_15 -> V_18 == V_20 )
return 0 ;
V_15 -> V_18 = V_20 ;
if ( V_20 ) {
F_14 ( V_2 -> V_21 ,
V_25 ,
V_23 ) ;
F_17 ( V_2 , true ) ;
F_7 ( V_2 ) ;
} else {
F_9 ( V_2 ) ;
F_17 ( V_2 , false ) ;
F_14 ( V_2 -> V_21 ,
V_25 ,
V_24 ) ;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 , bool V_20 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_2 -> V_16 ) ;
if ( V_15 -> V_19 == V_20 )
return 0 ;
V_15 -> V_19 = V_20 ;
if ( V_20 ) {
F_19 ( V_2 , true ) ;
F_10 ( V_2 ) ;
} else {
F_11 ( V_2 ) ;
F_19 ( V_2 , false ) ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
const T_1 * V_26 )
{
T_2 V_27 ;
T_1 V_28 ;
switch ( ( * V_26 & V_29 ) >> V_30 ) {
case V_31 :
switch ( ( * V_26 & V_32 ) >> V_33 ) {
case V_34 :
if ( V_35 & * V_26 ) {
V_27 = ( ( * V_26 & V_36 ) & V_37 ) ?
V_38 :
V_39 ;
V_28 = V_40 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
if ( V_41 & * V_26 ) {
V_27 = ( * V_26 & V_36 ) & V_42
? V_38
: V_39 ;
V_28 = V_43 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
break;
case V_44 :
if ( V_35 & * V_26 ) {
V_27 = ( ( * V_26 & V_36 ) & V_37 ) ?
V_38 :
V_39 ;
V_28 = V_45 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
if ( V_41 & * V_26 ) {
V_27 = ( * V_26 & V_36 ) & V_42 ?
V_38 :
V_39 ;
V_28 = V_46 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
break;
case V_47 :
if ( V_41 & * V_26 ) {
V_27 = ( * V_26 & V_36 ) & V_42 ?
V_38 :
V_39 ;
V_28 = V_48 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
break;
case V_49 :
if ( V_41 & * V_26 ) {
V_27 = ( * V_26 & V_36 ) & V_42 ?
V_38 :
V_39 ;
V_28 = V_50 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
break;
case V_51 :
if ( V_35 & * V_26 ) {
V_27 = ( ( * V_26 & V_36 ) & V_37 ) ?
V_38 :
V_39 ;
V_28 = ( V_52 | V_53 |
V_54 ) ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
break;
default:
return - 1 ;
}
break;
case V_55 :
switch ( ( * V_26 & V_32 ) >> V_33 ) {
case V_56 :
if ( V_35 & * V_26 ) {
V_27 = ( * V_26 & V_36 ) & V_37 ?
V_38 :
V_39 ;
V_28 = V_57 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
if ( V_41 & * V_26 ) {
V_27 = ( * V_26 & V_36 ) & V_42 ?
V_38 :
V_39 ;
V_28 = V_58 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
break;
case V_59 :
if ( V_35 & * V_26 ) {
V_27 = ( ( * V_26 & V_36 ) & V_37 ) ?
V_38 :
V_39 ;
V_28 = V_60 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
if ( V_41 & * V_26 ) {
V_27 = ( * V_26 & V_36 ) & V_42 ?
V_38 :
V_39 ;
V_28 = V_61 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
break;
case V_62 :
if ( V_35 & * V_26 ) {
V_27 = ( * V_26 & V_36 ) & V_37 ?
V_38 :
V_39 ;
V_28 = V_63 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
if ( V_41 & * V_26 ) {
V_27 = ( * V_26 & V_36 ) & V_42 ?
V_38 :
V_39 ;
V_28 = V_64 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
break;
case V_65 :
if ( V_35 & * V_26 ) {
V_27 = ( ( * V_26 & V_36 ) & V_37 ) ?
V_38 :
V_39 ;
V_28 = V_66 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
if ( V_41 & * V_26 ) {
V_27 = ( * V_26 & V_36 ) & V_42 ?
V_38 :
V_39 ;
V_28 = V_67 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
break;
case V_68 :
if ( V_35 & * V_26 ) {
V_27 = ( ( * V_26 & V_36 ) & V_37 ) ?
V_38 :
V_39 ;
V_28 = V_69 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
if ( V_41 & * V_26 ) {
V_27 = ( * V_26 & V_36 ) & V_42 ?
V_38 :
V_39 ;
V_28 = V_70 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
break;
case V_71 :
if ( V_35 & * V_26 ) {
V_27 = ( ( * V_26 & V_36 ) & V_37 ) ?
V_38 :
V_39 ;
V_28 = V_72 ;
if ( F_6 (
V_2 -> V_3 , V_27 , V_28 ) )
return - 1 ;
}
break;
default:
return - 1 ;
}
break;
default:
return - 1 ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 , bool V_73 )
{
struct V_74 V_75 = { 0 } ;
T_1 V_76 ;
int V_77 ;
V_75 . V_78 = sizeof( struct V_74 ) ;
V_75 . V_79 = V_80 ;
V_77 = F_22 ( V_2 -> V_21 , & V_75 ) ;
if ( V_77 )
return - V_81 ;
else
V_76 = V_75 . V_28 ;
if ( V_73 )
return F_6 ( V_2 -> V_3 ,
V_82 , V_76 ) ;
else
return F_3 ( V_2 -> V_3 ,
V_83 ) ;
}
