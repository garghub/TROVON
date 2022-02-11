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
F_14 ( V_2 , true ) ;
F_1 ( V_2 ) ;
} else {
F_4 ( V_2 ) ;
F_14 ( V_2 , false ) ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 , bool V_20 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_2 -> V_16 ) ;
if ( V_15 -> V_18 == V_20 )
return 0 ;
V_15 -> V_18 = V_20 ;
if ( V_20 )
F_7 ( V_2 ) ;
else
F_9 ( V_2 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , bool V_20 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_2 -> V_16 ) ;
if ( V_15 -> V_19 == V_20 )
return 0 ;
V_15 -> V_19 = V_20 ;
if ( V_20 ) {
F_17 ( V_2 , true ) ;
F_10 ( V_2 ) ;
} else {
F_11 ( V_2 ) ;
F_17 ( V_2 , false ) ;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
const T_1 * V_21 )
{
T_2 V_22 ;
T_1 V_23 ;
switch ( ( * V_21 & V_24 ) >> V_25 ) {
case V_26 :
switch ( ( * V_21 & V_27 ) >> V_28 ) {
case V_29 :
if ( V_30 & * V_21 ) {
V_22 = ( ( * V_21 & V_31 ) & V_32 ) ?
V_33 :
V_34 ;
V_23 = V_35 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
if ( V_36 & * V_21 ) {
V_22 = ( * V_21 & V_31 ) & V_37
? V_33
: V_34 ;
V_23 = V_38 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
break;
case V_39 :
if ( V_30 & * V_21 ) {
V_22 = ( ( * V_21 & V_31 ) & V_32 ) ?
V_33 :
V_34 ;
V_23 = V_40 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
if ( V_36 & * V_21 ) {
V_22 = ( * V_21 & V_31 ) & V_37 ?
V_33 :
V_34 ;
V_23 = V_41 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
break;
case V_42 :
if ( V_36 & * V_21 ) {
V_22 = ( * V_21 & V_31 ) & V_37 ?
V_33 :
V_34 ;
V_23 = V_43 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
break;
case V_44 :
if ( V_36 & * V_21 ) {
V_22 = ( * V_21 & V_31 ) & V_37 ?
V_33 :
V_34 ;
V_23 = V_45 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
break;
case V_46 :
if ( V_30 & * V_21 ) {
V_22 = ( ( * V_21 & V_31 ) & V_32 ) ?
V_33 :
V_34 ;
V_23 = ( V_47 | V_48 |
V_49 ) ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
break;
default:
return - 1 ;
}
break;
case V_50 :
switch ( ( * V_21 & V_27 ) >> V_28 ) {
case V_51 :
if ( V_30 & * V_21 ) {
V_22 = ( * V_21 & V_31 ) & V_32 ?
V_33 :
V_34 ;
V_23 = V_52 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
if ( V_36 & * V_21 ) {
V_22 = ( * V_21 & V_31 ) & V_37 ?
V_33 :
V_34 ;
V_23 = V_53 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
break;
case V_54 :
if ( V_30 & * V_21 ) {
V_22 = ( ( * V_21 & V_31 ) & V_32 ) ?
V_33 :
V_34 ;
V_23 = V_55 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
if ( V_36 & * V_21 ) {
V_22 = ( * V_21 & V_31 ) & V_37 ?
V_33 :
V_34 ;
V_23 = V_56 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
break;
case V_57 :
if ( V_30 & * V_21 ) {
V_22 = ( * V_21 & V_31 ) & V_32 ?
V_33 :
V_34 ;
V_23 = V_58 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
if ( V_36 & * V_21 ) {
V_22 = ( * V_21 & V_31 ) & V_37 ?
V_33 :
V_34 ;
V_23 = V_59 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
break;
case V_60 :
if ( V_30 & * V_21 ) {
V_22 = ( ( * V_21 & V_31 ) & V_32 ) ?
V_33 :
V_34 ;
V_23 = V_61 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
if ( V_36 & * V_21 ) {
V_22 = ( * V_21 & V_31 ) & V_37 ?
V_33 :
V_34 ;
V_23 = V_62 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
break;
case V_63 :
if ( V_30 & * V_21 ) {
V_22 = ( ( * V_21 & V_31 ) & V_32 ) ?
V_33 :
V_34 ;
V_23 = V_64 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
if ( V_36 & * V_21 ) {
V_22 = ( * V_21 & V_31 ) & V_37 ?
V_33 :
V_34 ;
V_23 = V_65 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
return - 1 ;
}
break;
case V_66 :
if ( V_30 & * V_21 ) {
V_22 = ( ( * V_21 & V_31 ) & V_32 ) ?
V_33 :
V_34 ;
V_23 = V_67 ;
if ( F_6 (
V_2 -> V_3 , V_22 , V_23 ) )
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
int F_19 ( struct V_1 * V_2 , bool V_68 )
{
struct V_69 V_70 = { 0 } ;
T_1 V_71 ;
int V_72 ;
V_70 . V_73 = sizeof( struct V_69 ) ;
V_70 . V_74 = V_75 ;
V_72 = F_20 ( V_2 -> V_76 , & V_70 ) ;
if ( V_72 )
return - V_77 ;
else
V_71 = V_70 . V_23 ;
if ( V_68 )
return F_6 ( V_2 -> V_3 ,
V_78 , V_71 ) ;
else
return F_3 ( V_2 -> V_3 ,
V_79 ) ;
}
