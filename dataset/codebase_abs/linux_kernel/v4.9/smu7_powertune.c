static int F_1 ( struct V_1 * V_2 , const bool V_3 )
{
T_1 V_4 = V_3 ? 1 : 0 ;
T_2 V_5 = 0 ;
T_1 V_6 ;
if ( F_2 ( V_2 -> V_7 . V_8 , V_9 ) ) {
V_6 = F_3 ( V_2 -> V_10 , V_11 , V_12 ) ;
V_6 &= ~ V_13 ;
V_6 |= ( ( V_4 << V_14 ) & V_13 ) ;
F_4 ( V_2 -> V_10 , V_11 , V_12 , V_6 ) ;
V_15 &= ~ V_16 ;
V_15 |= V_4 << V_17 ;
}
if ( F_2 ( V_2 -> V_7 . V_8 , V_18 ) ) {
V_6 = F_3 ( V_2 -> V_10 , V_11 , V_19 ) ;
V_6 &= ~ V_20 ;
V_6 |= ( ( V_4 << V_21 ) & V_20 ) ;
F_4 ( V_2 -> V_10 , V_11 , V_19 , V_6 ) ;
V_15 &= ~ V_22 ;
V_15 |= V_4 << V_23 ;
}
if ( F_2 ( V_2 -> V_7 . V_8 , V_24 ) ) {
V_6 = F_3 ( V_2 -> V_10 , V_11 , V_25 ) ;
V_6 &= ~ V_26 ;
V_6 |= ( ( V_4 << V_27 ) & V_26 ) ;
F_4 ( V_2 -> V_10 , V_11 , V_25 , V_6 ) ;
V_15 &= ~ V_28 ;
V_15 |= V_4 << V_29 ;
}
if ( F_2 ( V_2 -> V_7 . V_8 , V_30 ) ) {
V_6 = F_3 ( V_2 -> V_10 , V_11 , V_31 ) ;
V_6 &= ~ V_32 ;
V_6 |= ( ( V_4 << V_33 ) & V_32 ) ;
F_4 ( V_2 -> V_10 , V_11 , V_31 , V_6 ) ;
V_15 &= ~ V_34 ;
V_15 |= V_4 << V_35 ;
}
if ( V_3 )
V_5 = F_5 ( V_2 -> V_36 , V_37 , V_15 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_38 * V_39 )
{
const struct V_38 * V_40 = V_39 ;
T_1 V_41 = 0 ;
T_1 V_6 = 0 ;
F_7 ((config_regs != NULL), L_1 , return -EINVAL) ;
while ( V_40 -> V_42 != 0xFFFFFFFF ) {
if ( V_40 -> type == V_43 )
V_41 |= ( ( V_40 -> V_44 << V_40 -> V_45 ) & V_40 -> V_46 ) ;
else {
switch ( V_40 -> type ) {
case V_47 :
V_6 = F_3 ( V_2 -> V_10 , V_48 , V_40 -> V_42 ) ;
break;
case V_49 :
V_6 = F_3 ( V_2 -> V_10 , V_11 , V_40 -> V_42 ) ;
break;
case V_50 :
V_6 = F_3 ( V_2 -> V_10 , V_51 , V_40 -> V_42 ) ;
break;
default:
V_6 = F_8 ( V_2 -> V_10 , V_40 -> V_42 ) ;
break;
}
V_6 &= ~ V_40 -> V_46 ;
V_6 |= ( ( V_40 -> V_44 << V_40 -> V_45 ) & V_40 -> V_46 ) ;
V_6 |= V_41 ;
switch ( V_40 -> type ) {
case V_47 :
F_4 ( V_2 -> V_10 , V_48 , V_40 -> V_42 , V_6 ) ;
break;
case V_49 :
F_4 ( V_2 -> V_10 , V_11 , V_40 -> V_42 , V_6 ) ;
break;
case V_50 :
F_4 ( V_2 -> V_10 , V_51 , V_40 -> V_42 , V_6 ) ;
break;
default:
F_9 ( V_2 -> V_10 , V_40 -> V_42 , V_6 ) ;
break;
}
V_41 = 0 ;
}
V_40 ++ ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_52 = 0 ;
T_1 V_53 , V_44 , V_54 ;
struct V_55 V_56 = { 0 } ;
V_56 . V_57 = sizeof( struct V_55 ) ;
V_56 . V_58 = V_59 ;
V_5 = F_11 ( V_2 -> V_10 , & V_56 ) ;
if ( V_5 == 0 )
V_52 = V_56 . V_44 ;
if ( F_2 ( V_2 -> V_7 . V_8 , V_9 ) ||
F_2 ( V_2 -> V_7 . V_8 , V_18 ) ||
F_2 ( V_2 -> V_7 . V_8 , V_24 ) ||
F_2 ( V_2 -> V_7 . V_8 , V_30 ) ) {
V_44 = 0 ;
V_54 = F_8 ( V_2 -> V_10 , V_60 ) ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
V_44 = V_61
| V_62
| ( V_53 << V_63 ) ;
F_9 ( V_2 -> V_10 , V_60 , V_44 ) ;
if ( V_2 -> V_64 == V_65 ) {
V_5 = F_6 ( V_2 , V_66 ) ;
F_7 ((result == 0), L_2 , return result) ;
V_5 = F_6 ( V_2 , V_67 ) ;
F_7 ((result == 0), L_2 , return result) ;
} else if ( V_2 -> V_64 == V_68 ) {
V_5 = F_6 ( V_2 , V_69 ) ;
F_7 ((result == 0), L_2 , return result) ;
V_5 = F_6 ( V_2 , V_70 ) ;
F_7 ((result == 0), L_2 , return result) ;
}
}
F_9 ( V_2 -> V_10 , V_60 , V_54 ) ;
V_5 = F_1 ( V_2 , true ) ;
F_7 ((result == 0), L_3 , return result) ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_5 ;
if ( F_2 ( V_2 -> V_7 . V_8 , V_9 ) ||
F_2 ( V_2 -> V_7 . V_8 , V_18 ) ||
F_2 ( V_2 -> V_7 . V_8 , V_24 ) ||
F_2 ( V_2 -> V_7 . V_8 , V_30 ) ) {
V_5 = F_1 ( V_2 , false ) ;
F_7 ((result == 0), L_4 , return result) ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_71 * V_6 = (struct V_71 * ) ( V_2 -> V_72 ) ;
int V_5 = 0 ;
if ( F_2 ( V_2 -> V_7 . V_8 ,
V_73 ) ) {
int V_74 ;
V_74 = F_14 ( V_2 -> V_36 ,
( V_75 ) ( V_76 ) ) ;
F_7 ( ( 0 == V_74 ) ,
L_5 , V_5 = - 1 ) ;
V_6 -> V_77 = ( 0 == V_74 ) ? true : false ;
}
return V_5 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_71 * V_6 = (struct V_71 * ) ( V_2 -> V_72 ) ;
int V_5 = 0 ;
if ( F_2 ( V_2 -> V_7 . V_8 ,
V_73 ) && V_6 -> V_77 ) {
int V_74 = F_14 ( V_2 -> V_36 ,
( V_75 ) ( V_78 ) ) ;
F_7 ( ( V_74 == 0 ) ,
L_6 , V_5 = - 1 ) ;
V_6 -> V_77 = false ;
}
return V_5 ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_79 )
{
struct V_71 * V_6 = (struct V_71 * ) ( V_2 -> V_72 ) ;
if ( V_6 -> V_80 &
V_81 )
return F_5 ( V_2 -> V_36 ,
V_82 , V_79 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_83 , T_1 V_84 )
{
return F_5 ( V_83 -> V_36 ,
V_85 , V_84 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
struct V_71 * V_6 = (struct V_71 * ) ( V_2 -> V_72 ) ;
struct V_86 * V_87 =
(struct V_86 * ) ( V_2 -> V_88 ) ;
int V_74 ;
int V_5 = 0 ;
struct V_89 * V_90 ;
V_6 -> V_80 = 0 ;
if ( V_2 -> V_91 == V_92 )
V_90 = V_87 -> V_93 ;
else
V_90 = V_2 -> V_94 . V_93 ;
if ( F_2 ( V_2 -> V_7 . V_8 ,
V_95 ) ) {
if ( V_6 -> V_96 ) {
V_74 = F_14 ( V_2 -> V_36 ,
( V_75 ) ( V_97 ) ) ;
F_7 ((0 == smc_result),
L_7 , result = -1;) ;
if ( 0 == V_74 )
V_6 -> V_80 |=
V_98 ;
}
if ( V_6 -> V_99 ) {
V_74 = F_14 ( V_2 -> V_36 ,
( V_75 ) ( V_100 ) ) ;
F_7 ((0 == smc_result),
L_8 , result = -1;) ;
if ( 0 == V_74 ) {
T_1 V_101 =
( T_1 ) ( V_90 -> V_102 * 256 ) ;
V_6 -> V_80 |=
V_81 ;
if ( F_16 ( V_2 , V_101 ) )
F_19 ( V_103 L_9 ) ;
}
}
}
return V_5 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_71 * V_6 = (struct V_71 * ) ( V_2 -> V_72 ) ;
int V_5 = 0 ;
if ( F_2 ( V_2 -> V_7 . V_8 ,
V_95 ) &&
V_6 -> V_80 ) {
int V_74 ;
if ( V_6 -> V_80 &
V_98 ) {
V_74 = F_14 ( V_2 -> V_36 ,
( V_75 ) ( V_104 ) ) ;
F_7 ( ( V_74 == 0 ) ,
L_10 ,
V_5 = V_74 ) ;
}
if ( V_6 -> V_80 &
V_105 ) {
V_74 = F_14 ( V_2 -> V_36 ,
( V_75 ) ( V_106 ) ) ;
F_7 ( ( V_74 == 0 ) ,
L_11 ,
V_5 = V_74 ) ;
}
if ( V_6 -> V_80 &
V_81 ) {
V_74 = F_14 ( V_2 -> V_36 ,
( V_75 ) ( V_107 ) ) ;
F_7 ( ( V_74 == 0 ) ,
L_12 ,
V_5 = V_74 ) ;
}
V_6 -> V_80 = 0 ;
}
return V_5 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_86 * V_87 =
(struct V_86 * ) ( V_2 -> V_88 ) ;
struct V_89 * V_90 ;
int V_108 , V_84 ;
int V_5 = 0 ;
if ( V_2 -> V_91 == V_92 )
V_90 = V_87 -> V_93 ;
else
V_90 = V_2 -> V_94 . V_93 ;
if ( F_2 ( V_2 -> V_7 . V_8 ,
V_95 ) ) {
V_108 = V_2 -> V_7 . V_109 ?
V_2 -> V_7 . V_110 :
( - 1 * V_2 -> V_7 . V_110 ) ;
V_84 = ( ( 100 + V_108 ) * ( int ) ( V_90 -> V_111 * 256 ) ) / 100 ;
V_5 = F_17 ( V_2 , ( T_1 ) V_84 ) ;
}
return V_5 ;
}
