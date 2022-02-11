void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = (struct V_3 * ) ( V_2 -> V_4 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
if ( V_6 &&
V_6 -> V_8 -> V_9 <= V_10 &&
V_6 -> V_8 -> V_9 )
V_3 -> V_11 =
& V_12
[ V_6 -> V_8 -> V_9 - 1 ] ;
else
V_3 -> V_11 = & V_12 [ 0 ] ;
}
static T_1 F_2 ( T_1 V_13 )
{
T_2 V_14 ;
V_14 = V_13 * 4096 / 100 ;
return ( T_1 ) V_14 ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
const struct V_16 * V_17 = V_15 -> V_11 ;
T_3 * V_18 = & ( V_15 -> V_19 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
struct V_20 * V_8 = V_6 -> V_8 ;
struct V_21 * V_22 =
& V_2 -> V_23 . V_24 ;
int V_25 , V_26 , V_27 ;
const T_1 * V_28 ;
const T_1 * V_29 ;
V_18 -> V_30 = F_4 ( ( T_1 ) ( V_8 -> V_31 * 128 ) ) ;
V_18 -> V_32 = F_4 ( ( T_1 ) ( V_8 -> V_31 * 128 ) ) ;
F_5 ( V_8 -> V_33 <= 255 ,
L_1 ,
) ;
V_18 -> V_34 = F_4 (
V_8 -> V_33 * 256 ) ;
V_18 -> V_35 = F_4 (
V_8 -> V_36 * 256 ) ;
V_18 -> V_37 = F_4 (
F_2 ( V_22 -> V_38 ) ) ;
V_18 -> V_39 = F_4 (
F_2 ( V_22 -> V_40 ) ) ;
V_28 = V_17 -> V_41 ;
V_29 = V_17 -> V_42 ;
for ( V_25 = 0 ; V_25 < V_43 ; V_25 ++ ) {
for ( V_26 = 0 ; V_26 < V_44 ; V_26 ++ ) {
for ( V_27 = 0 ; V_27 < V_45 ; V_27 ++ ) {
V_18 -> V_41 [ V_25 ] [ V_26 ] [ V_27 ] = F_4 ( * V_28 ) ;
V_18 -> V_42 [ V_25 ] [ V_26 ] [ V_27 ] = F_4 ( * V_29 ) ;
V_28 ++ ;
V_29 ++ ;
}
}
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
const struct V_16 * V_17 = V_15 -> V_11 ;
V_15 -> V_46 . V_47 = V_17 -> V_47 ;
V_15 -> V_46 . V_48 = V_17 -> V_48 ;
V_15 -> V_46 . V_49 = 3 ;
V_15 -> V_46 . V_50 = 0 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_51 ;
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
const struct V_16 * V_17 = V_15 -> V_11 ;
V_51 = ( T_1 ) ( V_6 -> V_8 -> V_52 * 128 ) ;
V_15 -> V_46 . V_53 =
F_8 ( V_51 ) ;
V_15 -> V_46 . V_54 =
V_17 -> V_54 ;
V_15 -> V_46 . V_55 = V_17 -> V_55 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_56 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
const struct V_16 * V_17 = V_15 -> V_11 ;
T_2 V_57 ;
if ( F_10 ( V_2 -> V_58 ,
V_56 +
F_11 ( V_59 , V_60 ) ,
( T_2 * ) & V_57 , V_15 -> V_61 ) )
F_5 (false,
L_2 ,
return -EINVAL) ;
else {
V_15 -> V_46 . V_60 = V_17 -> V_60 ;
V_15 -> V_46 . V_62 =
( V_63 ) ( ( V_57 >> 16 ) & 0xff ) ;
V_15 -> V_46 . V_64 =
( V_63 ) ( ( V_57 >> 8 ) & 0xff ) ;
V_15 -> V_46 . V_65 = ( V_63 ) ( V_57 & 0xff ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_25 ;
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ )
V_15 -> V_46 . V_66 [ V_25 ] = 0 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
if ( ( V_2 -> V_23 . V_24 . V_67 & ( 1 << 15 ) )
|| 0 == V_2 -> V_23 . V_24 . V_67 )
V_2 -> V_23 . V_24 . V_67 =
V_2 -> V_23 . V_24 . V_68 ;
V_15 -> V_46 . V_69 = F_4 (
V_2 -> V_23 . V_24 . V_67 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_25 ;
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ )
V_15 -> V_46 . V_70 [ V_25 ] = 0 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
T_1 V_71 = V_15 -> V_46 . V_72 ;
T_1 V_73 = V_15 -> V_46 . V_74 ;
struct V_20 * V_75 = V_6 -> V_8 ;
V_71 = ( T_1 ) ( V_75 -> V_76 / 100 * 256 ) ;
V_73 = ( T_1 ) ( V_75 -> V_77 / 100 * 256 ) ;
V_15 -> V_46 . V_72 =
F_8 ( V_71 ) ;
V_15 -> V_46 . V_74 =
F_8 ( V_73 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
T_2 V_78 ;
if ( F_18 ( V_2 -> V_79 . V_80 ,
V_81 ) ) {
if ( F_10 ( V_2 -> V_58 ,
V_82 +
F_11 ( V_83 , V_84 ) ,
& V_78 , V_15 -> V_61 ) )
F_5 (false,
L_3 ,
return -EINVAL) ;
if ( F_6 ( V_2 ) )
F_5 (false,
L_4 ,
return -EINVAL) ;
if ( F_7 ( V_2 ) )
F_5 (false,
L_5 , return -EINVAL) ;
if ( F_9 ( V_2 , V_78 ) )
F_5 (false,
L_6
L_7 ,
return -EINVAL) ;
if ( 0 != F_12 ( V_2 ) )
F_5 (false,
L_8 ,
return -EINVAL) ;
if ( F_13 ( V_2 ) )
F_5 (false,
L_9 ,
return -EINVAL) ;
if ( F_14 ( V_2 ) )
F_5 (false,
L_10 ,
return -EINVAL) ;
if ( F_15 ( V_2 ) )
F_5 (false,
L_11 ,
return -EINVAL) ;
if ( F_16 ( V_2 ) )
F_5 (false,
L_12
L_13 , return -EINVAL) ;
if ( F_19 ( V_2 -> V_58 , V_78 ,
( V_63 * ) & V_15 -> V_46 ,
( sizeof( struct V_59 ) - 92 ) , V_15 -> V_61 ) )
F_5 (false,
L_14 ,
return -EINVAL) ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
int V_85 = 0 ;
if ( F_18 ( V_2 -> V_79 . V_80 ,
V_86 ) ) {
int V_87 ;
V_87 = F_21 ( V_2 -> V_58 ,
( T_1 ) ( V_88 ) ) ;
F_5 ( ( 0 == V_87 ) ,
L_15 , V_85 = - 1 ) ;
V_15 -> V_89 = ( 0 == V_87 ) ? true : false ;
}
return V_85 ;
}
int F_22 ( struct V_1 * V_2 , T_2 V_90 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
if ( V_15 -> V_91 &
V_92 )
return F_23 ( V_2 -> V_58 ,
V_93 , V_90 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_94 , T_2 V_95 )
{
return F_23 ( V_94 -> V_58 ,
V_96 , V_95 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
int V_87 ;
int V_85 = 0 ;
V_15 -> V_91 = 0 ;
if ( F_18 ( V_2 -> V_79 . V_80 ,
V_81 ) ) {
if ( V_15 -> V_97 ) {
V_87 = F_21 ( V_2 -> V_58 ,
( T_1 ) ( V_98 ) ) ;
F_5 ((0 == smc_result),
L_16 , result = -1;) ;
if ( 0 == V_87 )
V_15 -> V_91 |=
V_99 ;
}
if ( V_15 -> V_100 ) {
V_87 = F_21 ( V_2 -> V_58 ,
( T_1 ) ( V_101 ) ) ;
F_5 ((0 == smc_result),
L_17 , result = -1;) ;
if ( 0 == V_87 ) {
struct V_20 * V_75 =
V_6 -> V_8 ;
T_2 V_102 =
( T_2 ) ( V_75 -> V_103 * 256 ) ;
V_15 -> V_91 |=
V_92 ;
if ( F_22 ( V_2 , V_102 ) )
F_26 ( V_104 L_18 ) ;
}
}
}
return V_85 ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
struct V_20 * V_75 = V_6 -> V_8 ;
int V_105 , V_95 ;
int V_85 = 0 ;
if ( F_18 ( V_2 -> V_79 . V_80 ,
V_81 ) ) {
V_105 = V_2 -> V_79 . V_106 ?
V_2 -> V_79 . V_107 :
( - 1 * V_2 -> V_79 . V_107 ) ;
V_95 = ( ( 100 + V_105 ) * ( int ) ( V_75 -> V_31 * 256 ) ) / 100 ;
V_85 = F_24 ( V_2 , ( T_2 ) V_95 ) ;
}
return V_85 ;
}
