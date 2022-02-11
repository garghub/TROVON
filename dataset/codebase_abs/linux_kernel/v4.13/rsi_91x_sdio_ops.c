int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 ;
T_2 V_5 = 0 ;
int V_6 = 0 ;
V_4 = ( T_2 ) ( V_3 & 0x00FF ) ;
F_2 ( V_7 ,
L_1 , V_8 , V_4 ) ;
V_6 = F_3 ( V_2 ,
V_5 ,
V_9 ,
& V_4 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_2 ,
V_8 ) ;
return - 1 ;
}
V_4 = ( T_2 ) ( V_3 >> 8 ) ;
F_2 ( V_7 , L_3 , V_8 , V_4 ) ;
V_6 = F_3 ( V_2 ,
V_5 ,
V_11 ,
& V_4 ) ;
return V_6 ;
}
static int F_4 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
T_2 V_15 = 0 ;
T_3 V_16 = 0 ;
int V_6 = 0 ;
V_6 = F_5 ( V_2 ,
V_17 ,
& V_15 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_4 ,
V_8 ) ;
return V_6 ;
}
V_16 = ( V_15 * 256 ) ;
V_13 -> V_18 = F_6 ( V_16 , V_19 ) ;
if ( ! V_13 -> V_18 ) {
F_2 ( V_10 , L_5 ,
V_8 ) ;
return - V_20 ;
}
V_6 = F_7 ( V_2 ,
V_13 -> V_18 ,
V_16 ) ;
if ( V_6 ) {
F_2 ( V_10 , L_6 ,
V_8 ) ;
goto V_21;
}
V_6 = F_8 ( V_13 , V_16 ) ;
V_21:
F_9 ( V_13 -> V_18 ) ;
return V_6 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_22 * V_23 =
(struct V_22 * ) V_2 -> V_24 ;
T_2 V_5 = 0 ;
T_2 V_4 ;
int V_6 = 0 ;
if ( V_23 -> V_25 ) {
V_4 = V_23 -> V_25 ;
V_6 = F_3 ( V_2 ,
V_5 ,
V_26 ,
& V_4 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_7 ,
V_8 ) ;
return - 1 ;
}
}
if ( V_23 -> V_27 ) {
F_2 ( V_7 , L_8 , V_8 ) ;
V_4 = 0x3 ;
V_6 = F_3 ( V_2 ,
V_5 ,
V_28 ,
& V_4 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_9 ,
V_8 ) ;
return - 1 ;
}
}
F_2 ( V_7 , L_10 , V_8 ) ;
V_4 = 0x24 ;
V_6 = F_3 ( V_2 ,
V_5 ,
V_29 ,
& V_4 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_11 , V_8 ) ;
return - 1 ;
}
F_2 ( V_7 , L_12 , V_8 ) ;
V_4 = ( 128 - 32 ) ;
V_6 = F_3 ( V_2 ,
V_5 ,
V_30 ,
& V_4 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_13 , V_8 ) ;
return - 1 ;
}
V_4 = 32 ;
V_6 = F_3 ( V_2 ,
V_5 ,
V_31 ,
& V_4 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_14 , V_8 ) ;
return - 1 ;
}
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_22 * V_23 =
(struct V_22 * ) V_2 -> V_24 ;
int V_6 ;
enum V_32 V_33 ;
T_2 V_34 = 0 ;
T_2 V_35 = 0 ;
V_23 -> V_36 . V_37 ++ ;
do {
F_12 ( & V_13 -> V_38 ) ;
V_6 = F_5 ( V_13 -> V_14 ,
V_39 ,
& V_34 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_15 ,
V_8 ) ;
F_13 ( & V_13 -> V_38 ) ;
return;
}
if ( V_34 == 0 ) {
F_14 ( & V_13 -> V_40 . V_41 ) ;
V_23 -> V_36 . V_42 ++ ;
F_13 ( & V_13 -> V_38 ) ;
return;
}
F_2 ( V_43 , L_16 ,
V_8 , V_34 , ( 1 << V_44 ) ,
( 1 << V_45 ) ) ;
do {
F_15 ( V_34 , V_33 ) ;
switch ( V_33 ) {
case V_46 :
V_23 -> V_36 . V_47 = 0 ;
V_23 -> V_36 . V_48 = false ;
V_23 -> V_36 . V_49 = false ;
V_23 -> V_36 . V_50 = false ;
F_16 ( V_13 -> V_14 ,
( 1 << V_51 ) ) ;
F_14 ( & V_13 -> V_40 . V_41 ) ;
F_2 ( V_43 ,
L_17 ,
V_8 ) ;
V_23 -> V_36 . V_52 ++ ;
break;
case V_53 :
F_2 ( V_10 ,
L_18 ,
V_8 ) ;
V_6 = F_5 ( V_13 -> V_14 ,
V_54 ,
& V_35 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_19 ,
V_8 ) ;
} else {
F_2 ( V_10 ,
L_20 ,
V_8 , V_35 ) ;
F_16 ( V_13 -> V_14 ,
( 1 << V_45 ) ) ;
}
V_13 -> V_55 = V_56 ;
break;
case V_57 :
F_2 ( V_43 , L_21 ) ;
V_23 -> V_36 . V_58 ++ ;
V_6 = F_4 ( V_13 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_22 ,
V_8 ) ;
F_13 ( & V_13 -> V_38 ) ;
return;
}
break;
default:
F_16 ( V_13 -> V_14 , V_34 ) ;
V_23 -> V_36 . V_59 ++ ;
V_34 = 0 ;
F_2 ( V_43 ,
L_23 ,
V_34 ) ;
break;
}
V_34 ^= F_17 ( V_33 - 1 ) ;
} while ( V_34 );
F_13 ( & V_13 -> V_38 ) ;
} while ( 1 );
}
int F_18 ( struct V_1 * V_2 , T_2 V_60 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_22 * V_23 =
(struct V_22 * ) V_2 -> V_24 ;
T_2 V_61 = 0 ;
int V_6 = 0 ;
V_6 = F_5 ( V_13 -> V_14 ,
V_62 ,
& V_61 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_24 , V_8 ) ;
return - 1 ;
}
if ( V_61 & ( F_17 ( V_63 ) ) ) {
if ( ! V_23 -> V_36 . V_50 )
V_23 -> V_36 . V_64 ++ ;
V_23 -> V_36 . V_50 = true ;
} else {
V_23 -> V_36 . V_50 = false ;
}
if ( V_61 & ( F_17 ( V_65 ) ) ) {
if ( ! V_23 -> V_36 . V_48 )
V_23 -> V_36 . V_66 ++ ;
V_23 -> V_36 . V_48 = true ;
} else {
V_23 -> V_36 . V_48 = false ;
}
if ( V_61 & ( F_17 ( V_67 ) ) ) {
if ( ! V_23 -> V_36 . V_49 )
V_23 -> V_36 . V_68 ++ ;
V_23 -> V_36 . V_49 = true ;
} else {
V_23 -> V_36 . V_49 = false ;
}
if ( ( V_60 == V_69 ) && ( V_23 -> V_36 . V_50 ) )
return V_70 ;
if ( V_23 -> V_36 . V_48 )
return V_70 ;
return V_71 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_22 * V_23 =
(struct V_22 * ) V_2 -> V_24 ;
if ( V_23 -> V_36 . V_48 )
return 2 ;
return V_72 ;
}
