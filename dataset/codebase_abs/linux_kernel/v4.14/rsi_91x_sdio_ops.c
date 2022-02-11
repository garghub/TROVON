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
struct V_15 * V_16 =
(struct V_15 * ) V_2 -> V_17 ;
T_2 V_18 = 0 ;
T_3 V_19 = 0 ;
int V_6 = 0 ;
T_2 V_20 = 0 ;
V_18 = ( ( V_2 -> V_21 & 1 ) |
( ( V_2 -> V_21 >> V_22 ) << 1 ) ) ;
if ( ! V_18 ) {
V_6 = F_5 ( V_2 ,
V_23 ,
& V_20 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_4 ,
V_8 ) ;
return V_6 ;
}
V_18 = V_20 & 0x1f ;
}
if ( V_16 -> V_24 == 2 )
F_6 ( V_13 -> V_14 , ( 1 << V_25 ) ) ;
if ( F_7 ( ! V_18 ) ) {
V_16 -> V_24 = 2 ;
return - 1 ;
}
V_19 = ( V_18 * 256 ) ;
V_13 -> V_26 = F_8 ( V_19 , V_27 ) ;
if ( ! V_13 -> V_26 ) {
F_2 ( V_10 , L_5 ,
V_8 ) ;
return - V_28 ;
}
V_6 = F_9 ( V_2 ,
V_13 -> V_26 ,
V_19 ) ;
if ( V_6 ) {
F_2 ( V_10 , L_6 ,
V_8 ) ;
goto V_29;
}
V_6 = F_10 ( V_13 , V_19 ) ;
V_29:
F_11 ( V_13 -> V_26 ) ;
return V_6 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_15 * V_16 =
(struct V_15 * ) V_2 -> V_17 ;
T_2 V_5 = 0 ;
T_2 V_4 ;
int V_6 = 0 ;
if ( V_16 -> V_30 ) {
V_4 = V_16 -> V_30 ;
V_6 = F_3 ( V_2 ,
V_5 ,
V_31 ,
& V_4 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_7 ,
V_8 ) ;
return - 1 ;
}
}
if ( V_16 -> V_32 ) {
F_2 ( V_7 , L_8 , V_8 ) ;
V_4 = 0x3 ;
V_6 = F_3 ( V_2 ,
V_5 ,
V_33 ,
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
V_34 ,
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
V_35 ,
& V_4 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_13 , V_8 ) ;
return - 1 ;
}
V_4 = 32 ;
V_6 = F_3 ( V_2 ,
V_5 ,
V_36 ,
& V_4 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_14 , V_8 ) ;
return - 1 ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_15 * V_16 =
(struct V_15 * ) V_2 -> V_17 ;
int V_6 ;
enum V_37 V_38 ;
T_2 V_39 = 0 ;
T_2 V_40 = 0 ;
V_16 -> V_41 . V_42 ++ ;
do {
F_14 ( & V_13 -> V_43 ) ;
V_6 = F_5 ( V_13 -> V_14 ,
V_44 ,
& V_39 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_15 ,
V_8 ) ;
F_15 ( & V_13 -> V_43 ) ;
return;
}
V_2 -> V_21 = V_39 ;
if ( V_39 == 0 ) {
F_16 ( & V_13 -> V_45 . V_46 ) ;
V_16 -> V_41 . V_47 ++ ;
F_15 ( & V_13 -> V_43 ) ;
return;
}
F_2 ( V_48 , L_16 ,
V_8 , V_39 , ( 1 << V_25 ) ,
( 1 << V_49 ) ) ;
do {
F_17 ( V_39 , V_38 ) ;
switch ( V_38 ) {
case V_50 :
V_6 = F_18 ( V_2 ,
0 ) ;
if ( V_6 < 0 )
F_2 ( V_10 ,
L_17 ,
V_8 ) ;
F_6 ( V_13 -> V_14 ,
( 1 << V_51 ) ) ;
F_16 ( & V_13 -> V_45 . V_46 ) ;
F_2 ( V_48 ,
L_18 ,
V_8 ) ;
V_16 -> V_52 = true ;
break;
case V_53 :
F_2 ( V_10 ,
L_19 ,
V_8 ) ;
V_6 = F_5 ( V_13 -> V_14 ,
V_54 ,
& V_40 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_20 ,
V_8 ) ;
} else {
F_2 ( V_10 ,
L_21 ,
V_8 , V_40 ) ;
F_6 ( V_13 -> V_14 ,
( 1 << V_49 ) ) ;
}
V_13 -> V_55 = V_56 ;
break;
case V_57 :
F_2 ( V_48 , L_22 ) ;
V_16 -> V_41 . V_58 ++ ;
V_6 = F_4 ( V_13 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_23 ,
V_8 ) ;
F_15 ( & V_13 -> V_43 ) ;
return;
}
break;
default:
F_6 ( V_13 -> V_14 , V_39 ) ;
V_16 -> V_41 . V_59 ++ ;
V_39 = 0 ;
F_2 ( V_48 ,
L_24 ,
V_39 ) ;
break;
}
V_39 ^= F_19 ( V_38 - 1 ) ;
} while ( V_39 );
F_15 ( & V_13 -> V_43 ) ;
} while ( 1 );
}
int F_18 ( struct V_1 * V_2 , T_2 V_60 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_15 * V_16 =
(struct V_15 * ) V_2 -> V_17 ;
T_2 V_61 = 0 ;
int V_6 = 0 ;
static int V_62 = 4 ;
if ( ! V_16 -> V_52 && V_62 ) {
V_62 -- ;
goto V_63;
}
V_16 -> V_52 = false ;
V_6 = F_5 ( V_13 -> V_14 ,
V_64 ,
& V_61 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_25 , V_8 ) ;
return - 1 ;
}
if ( V_61 & ( F_19 ( V_65 ) ) ) {
if ( ! V_16 -> V_41 . V_66 )
V_16 -> V_41 . V_67 ++ ;
V_16 -> V_41 . V_66 = true ;
} else {
V_16 -> V_41 . V_66 = false ;
}
if ( V_61 & ( F_19 ( V_68 ) ) ) {
if ( ! V_16 -> V_41 . V_69 )
V_16 -> V_41 . V_70 ++ ;
V_16 -> V_41 . V_69 = true ;
} else {
V_16 -> V_41 . V_69 = false ;
}
if ( V_61 & ( F_19 ( V_71 ) ) ) {
if ( ! V_16 -> V_41 . V_72 )
V_16 -> V_41 . V_73 ++ ;
V_16 -> V_41 . V_72 = true ;
} else {
V_16 -> V_41 . V_72 = false ;
}
if ( V_16 -> V_41 . V_66 || V_16 -> V_41 . V_70 )
V_62 = 1 ;
else
V_62 = 4 ;
V_63:
if ( ( V_60 == V_74 ) && ( V_16 -> V_41 . V_66 ) )
return V_75 ;
if ( ( V_60 < V_74 ) && ( V_16 -> V_41 . V_69 ) )
return V_75 ;
return V_76 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_15 * V_16 =
(struct V_15 * ) V_2 -> V_17 ;
if ( V_16 -> V_41 . V_69 )
return 2 ;
return V_77 ;
}
