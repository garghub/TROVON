static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
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
static int F_4 ( struct V_12 * V_13 ,
const T_2 * V_14 ,
T_3 V_15 ,
T_3 V_16 )
{
struct V_1 * V_2 = V_13 -> V_17 ;
struct V_18 * V_19 =
(struct V_18 * ) V_2 -> V_20 ;
T_3 V_21 , V_22 ;
T_3 V_23 = V_19 -> V_24 ;
T_3 V_25 ;
T_4 V_26 [] = { V_27 , V_28 ,
V_29 , V_30 } ;
T_3 V_31 [] = { V_32 , V_33 ,
V_34 , V_35 } ;
T_3 V_36 ;
T_1 V_37 ;
V_36 = V_38 ;
V_37 = V_36 >> 16 ;
for ( V_21 = 0 , V_22 = 0 ; V_22 < V_16 ; V_22 ++ , V_21 += V_23 ) {
V_25 = ( ( T_1 ) V_36 | V_39 ) ;
if ( F_5 ( V_2 ,
V_25 ,
( T_2 * ) ( V_14 + V_21 ) ,
V_23 ) ) {
F_2 ( V_10 ,
L_4 , V_8 ,
V_40 ) ;
return - 1 ;
}
F_2 ( V_7 , L_5 , V_8 , V_22 ) ;
V_36 += V_23 ;
if ( ( V_36 >> 16 ) != V_37 ) {
V_37 += 1 ;
if ( F_1 ( V_2 ,
V_37 ) ) {
F_2 ( V_10 ,
L_6 ,
V_8 ) ;
return - 1 ;
}
}
}
if ( V_15 % V_23 ) {
V_25 = ( ( T_1 ) V_36 | V_39 ) ;
if ( F_5 ( V_2 ,
V_25 ,
( T_2 * ) ( V_14 + V_21 ) ,
V_15 % V_23 ) ) {
F_2 ( V_10 ,
L_7 , V_8 ) ;
return - 1 ;
}
}
F_2 ( V_7 ,
L_8 , V_8 ) ;
if ( F_1 ( V_2 , V_41 ) ) {
F_2 ( V_10 ,
L_9 ,
V_8 ) ;
return - 1 ;
}
for ( V_22 = 0 ; V_22 < F_6 ( V_26 ) ; V_22 ++ ) {
if ( F_5 ( V_2 ,
( V_31 [ V_22 ] |
V_39 ) ,
( T_2 * ) & V_26 [ V_22 ] ,
4 ) ) {
F_2 ( V_10 ,
L_10 , V_8 ) ;
return - 1 ;
}
}
F_2 ( V_7 , L_11 , V_8 ) ;
return 0 ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_17 ;
struct V_18 * V_19 =
(struct V_18 * ) V_2 -> V_20 ;
T_3 V_15 ;
T_3 V_16 ;
const T_2 * V_14 ;
const struct V_42 * V_43 = NULL ;
T_3 V_23 = V_19 -> V_24 ;
int V_6 = 0 ;
T_3 V_36 ;
T_1 V_37 ;
if ( F_1 ( V_2 , V_41 ) ) {
F_2 ( V_10 ,
L_9 ,
V_8 ) ;
return - 1 ;
}
V_36 = V_38 ;
V_37 = ( V_36 >> 16 ) ;
if ( F_1 ( V_2 , V_37 ) ) {
F_2 ( V_10 ,
L_6 , V_8 ) ;
return - 1 ;
}
V_6 = F_8 ( & V_43 , V_40 , V_2 -> V_44 ) ;
if ( V_6 < 0 ) {
F_2 ( V_10 , L_12 ,
V_8 , V_40 ) ;
return V_6 ;
}
V_14 = F_9 ( V_43 -> V_26 , V_43 -> V_45 , V_46 ) ;
if ( ! V_14 ) {
V_6 = - V_47 ;
goto V_48;
}
V_15 = V_43 -> V_45 ;
if ( V_15 % 4 )
V_15 += ( 4 - ( V_15 % 4 ) ) ;
V_16 = ( V_15 / V_23 ) ;
F_2 ( V_7 , L_13 , V_8 , V_15 ) ;
F_2 ( V_7 , L_14 , V_8 , V_16 ) ;
V_6 = F_4 ( V_13 , V_14 , V_15 , V_16 ) ;
F_10 ( V_14 ) ;
V_48:
F_11 ( V_43 ) ;
return V_6 ;
}
static int F_12 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_17 ;
T_2 V_49 = 0 ;
T_3 V_50 = 0 ;
int V_6 = 0 ;
V_6 = F_13 ( V_2 ,
V_51 ,
& V_49 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_15 ,
V_8 ) ;
return V_6 ;
}
V_50 = ( V_49 * 256 ) ;
V_13 -> V_52 = F_14 ( V_50 , V_46 ) ;
if ( ! V_13 -> V_52 ) {
F_2 ( V_10 , L_16 ,
V_8 ) ;
return - V_47 ;
}
V_6 = F_15 ( V_2 ,
V_13 -> V_52 ,
V_50 ) ;
if ( V_6 ) {
F_2 ( V_10 , L_17 ,
V_8 ) ;
goto V_53;
}
V_6 = F_16 ( V_13 , V_50 ) ;
V_53:
F_10 ( V_13 -> V_52 ) ;
return V_6 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_18 * V_19 =
(struct V_18 * ) V_2 -> V_20 ;
T_2 V_5 = 0 ;
T_2 V_4 ;
int V_6 = 0 ;
if ( V_19 -> V_54 ) {
V_4 = V_19 -> V_54 ;
V_6 = F_3 ( V_2 ,
V_5 ,
V_55 ,
& V_4 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_18 ,
V_8 ) ;
return - 1 ;
}
}
if ( V_19 -> V_56 ) {
F_2 ( V_7 , L_19 , V_8 ) ;
V_4 = 0x3 ;
V_6 = F_3 ( V_2 ,
V_5 ,
V_57 ,
& V_4 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_20 ,
V_8 ) ;
return - 1 ;
}
}
F_2 ( V_7 , L_21 , V_8 ) ;
V_4 = 0x24 ;
V_6 = F_3 ( V_2 ,
V_5 ,
V_58 ,
& V_4 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_22 , V_8 ) ;
return - 1 ;
}
F_2 ( V_7 , L_23 , V_8 ) ;
V_4 = ( 128 - 32 ) ;
V_6 = F_3 ( V_2 ,
V_5 ,
V_59 ,
& V_4 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_24 , V_8 ) ;
return - 1 ;
}
V_4 = 32 ;
V_6 = F_3 ( V_2 ,
V_5 ,
V_60 ,
& V_4 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_25 , V_8 ) ;
return - 1 ;
}
return 0 ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_17 ;
struct V_18 * V_19 =
(struct V_18 * ) V_2 -> V_20 ;
int V_6 ;
enum V_61 V_62 ;
T_2 V_63 = 0 ;
T_2 V_64 = 0 ;
V_19 -> V_65 . V_66 ++ ;
do {
F_19 ( & V_13 -> V_67 ) ;
V_6 = F_13 ( V_13 -> V_17 ,
V_68 ,
& V_63 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_26 ,
V_8 ) ;
F_20 ( & V_13 -> V_67 ) ;
return;
}
if ( V_63 == 0 ) {
F_21 ( & V_13 -> V_69 . V_70 ) ;
V_19 -> V_65 . V_71 ++ ;
F_20 ( & V_13 -> V_67 ) ;
return;
}
F_2 ( V_72 , L_27 ,
V_8 , V_63 , ( 1 << V_73 ) ,
( 1 << V_74 ) ) ;
do {
F_22 ( V_63 , V_62 ) ;
switch ( V_62 ) {
case V_75 :
V_19 -> V_65 . V_76 = 0 ;
V_19 -> V_65 . V_77 = false ;
V_19 -> V_65 . V_78 = false ;
V_19 -> V_65 . V_79 = false ;
F_23 ( V_13 -> V_17 ,
( 1 << V_80 ) ) ;
F_21 ( & V_13 -> V_69 . V_70 ) ;
F_2 ( V_72 ,
L_28 ,
V_8 ) ;
V_19 -> V_65 . V_81 ++ ;
break;
case V_82 :
F_2 ( V_10 ,
L_29 ,
V_8 ) ;
V_6 = F_13 ( V_13 -> V_17 ,
V_83 ,
& V_64 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_30 ,
V_8 ) ;
} else {
F_2 ( V_10 ,
L_31 ,
V_8 , V_64 ) ;
F_23 ( V_13 -> V_17 ,
( 1 << V_74 ) ) ;
}
V_13 -> V_84 = V_85 ;
break;
case V_86 :
F_2 ( V_72 , L_32 ) ;
V_19 -> V_65 . V_87 ++ ;
V_6 = F_12 ( V_13 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_33 ,
V_8 ) ;
F_20 ( & V_13 -> V_67 ) ;
return;
}
break;
default:
F_23 ( V_13 -> V_17 , V_63 ) ;
V_19 -> V_65 . V_88 ++ ;
V_63 = 0 ;
F_2 ( V_72 ,
L_34 ,
V_63 ) ;
break;
}
V_63 ^= F_24 ( V_62 - 1 ) ;
} while ( V_63 );
F_20 ( & V_13 -> V_67 ) ;
} while ( 1 );
}
int F_25 ( struct V_12 * V_13 )
{
if ( F_7 ( V_13 ) )
return - 1 ;
if ( F_1 ( V_13 -> V_17 , V_89 ) ) {
F_2 ( V_10 , L_6 ,
V_8 ) ;
return - 1 ;
}
F_2 ( V_7 ,
L_35 , V_8 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , T_2 V_90 )
{
struct V_12 * V_13 = V_2 -> V_17 ;
struct V_18 * V_19 =
(struct V_18 * ) V_2 -> V_20 ;
T_2 V_91 = 0 ;
int V_6 = 0 ;
V_6 = F_13 ( V_13 -> V_17 ,
V_92 ,
& V_91 ) ;
if ( V_6 ) {
F_2 ( V_10 ,
L_36 , V_8 ) ;
return - 1 ;
}
if ( V_91 & ( F_24 ( V_93 ) ) ) {
if ( ! V_19 -> V_65 . V_79 )
V_19 -> V_65 . V_94 ++ ;
V_19 -> V_65 . V_79 = true ;
} else {
V_19 -> V_65 . V_79 = false ;
}
if ( V_91 & ( F_24 ( V_95 ) ) ) {
if ( ! V_19 -> V_65 . V_77 )
V_19 -> V_65 . V_96 ++ ;
V_19 -> V_65 . V_77 = true ;
} else {
V_19 -> V_65 . V_77 = false ;
}
if ( V_91 & ( F_24 ( V_97 ) ) ) {
if ( ! V_19 -> V_65 . V_78 )
V_19 -> V_65 . V_98 ++ ;
V_19 -> V_65 . V_78 = true ;
} else {
V_19 -> V_65 . V_78 = false ;
}
if ( ( V_90 == V_99 ) && ( V_19 -> V_65 . V_79 ) )
return V_100 ;
if ( V_19 -> V_65 . V_77 )
return V_100 ;
return V_101 ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_18 * V_19 =
(struct V_18 * ) V_2 -> V_20 ;
if ( V_19 -> V_65 . V_77 )
return 2 ;
return V_102 ;
}
