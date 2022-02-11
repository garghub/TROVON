static int F_1 ( struct V_1 * V_2 , const bool V_3 )
{
T_1 V_4 = V_3 ? 1 : 0 ;
T_1 V_5 = 0 ;
T_2 V_6 = 0 ;
T_1 V_7 ;
T_1 V_8 ;
if ( V_2 -> V_9 == V_10 )
V_7 = V_11 ;
else
V_7 = V_12 ;
V_5 = F_2 ( V_2 -> V_13 . V_14 , V_15 ) ? V_4 : 0 ;
V_8 = F_3 ( V_2 -> V_16 , V_17 , V_18 ) ;
V_8 &= ~ V_19 ;
V_8 |= ( ( V_5 << V_20 ) & V_19 ) ;
F_4 ( V_2 -> V_16 , V_17 , V_18 , V_8 ) ;
V_7 &= ~ V_21 ;
V_7 |= V_5 << V_22 ;
V_5 = F_2 ( V_2 -> V_13 . V_14 , V_23 ) ? V_4 : 0 ;
V_8 = F_3 ( V_2 -> V_16 , V_17 , V_24 ) ;
V_8 &= ~ V_25 ;
V_8 |= ( ( V_5 << V_26 ) & V_25 ) ;
F_4 ( V_2 -> V_16 , V_17 , V_24 , V_8 ) ;
V_7 &= ~ V_27 ;
V_7 |= V_5 << V_28 ;
V_5 = F_2 ( V_2 -> V_13 . V_14 , V_29 ) ? V_4 : 0 ;
V_8 = F_3 ( V_2 -> V_16 , V_17 , V_30 ) ;
V_8 &= ~ V_31 ;
V_8 |= ( ( V_5 << V_32 ) & V_31 ) ;
F_4 ( V_2 -> V_16 , V_17 , V_30 , V_8 ) ;
V_7 &= ~ V_33 ;
V_7 |= V_5 << V_34 ;
V_5 = F_2 ( V_2 -> V_13 . V_14 , V_35 ) ? V_4 : 0 ;
V_8 = F_3 ( V_2 -> V_16 , V_17 , V_36 ) ;
V_8 &= ~ V_37 ;
V_8 |= ( ( V_5 << V_38 ) & V_37 ) ;
F_4 ( V_2 -> V_16 , V_17 , V_36 , V_8 ) ;
V_7 &= ~ V_39 ;
V_7 |= V_5 << V_40 ;
if ( V_3 )
V_6 = F_5 ( V_2 -> V_41 , V_42 , V_7 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_43 * V_44 )
{
const struct V_43 * V_45 = V_44 ;
T_1 V_46 = 0 ;
T_1 V_8 = 0 ;
F_7 ((config_regs != NULL), L_1 , return -EINVAL) ;
while ( V_45 -> V_47 != 0xFFFFFFFF ) {
if ( V_45 -> type == V_48 )
V_46 |= ( ( V_45 -> V_49 << V_45 -> V_50 ) & V_45 -> V_51 ) ;
else {
switch ( V_45 -> type ) {
case V_52 :
V_8 = F_3 ( V_2 -> V_16 , V_53 , V_45 -> V_47 ) ;
break;
case V_54 :
V_8 = F_3 ( V_2 -> V_16 , V_17 , V_45 -> V_47 ) ;
break;
case V_55 :
V_8 = F_3 ( V_2 -> V_16 , V_56 , V_45 -> V_47 ) ;
break;
default:
V_8 = F_8 ( V_2 -> V_16 , V_45 -> V_47 ) ;
break;
}
V_8 &= ~ V_45 -> V_51 ;
V_8 |= ( ( V_45 -> V_49 << V_45 -> V_50 ) & V_45 -> V_51 ) ;
V_8 |= V_46 ;
switch ( V_45 -> type ) {
case V_52 :
F_4 ( V_2 -> V_16 , V_53 , V_45 -> V_47 , V_8 ) ;
break;
case V_54 :
F_4 ( V_2 -> V_16 , V_17 , V_45 -> V_47 , V_8 ) ;
break;
case V_55 :
F_4 ( V_2 -> V_16 , V_56 , V_45 -> V_47 , V_8 ) ;
break;
default:
F_9 ( V_2 -> V_16 , V_45 -> V_47 , V_8 ) ;
break;
}
V_46 = 0 ;
}
V_45 ++ ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_6 ;
T_1 V_57 = 0 ;
T_1 V_58 , V_49 , V_59 ;
struct V_60 V_61 = { 0 } ;
V_61 . V_62 = sizeof( struct V_60 ) ;
V_61 . V_63 = V_64 ;
V_6 = F_11 ( V_2 -> V_16 , & V_61 ) ;
if ( V_6 == 0 )
V_57 = V_61 . V_49 ;
if ( F_2 ( V_2 -> V_13 . V_14 , V_15 ) ||
F_2 ( V_2 -> V_13 . V_14 , V_23 ) ||
F_2 ( V_2 -> V_13 . V_14 , V_29 ) ||
F_2 ( V_2 -> V_13 . V_14 , V_35 ) ) {
F_12 ( V_2 -> V_16 , true ) ;
V_49 = 0 ;
V_59 = F_8 ( V_2 -> V_16 , V_65 ) ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
V_49 = V_66
| V_67
| ( V_58 << V_68 ) ;
F_9 ( V_2 -> V_16 , V_65 , V_49 ) ;
if ( V_2 -> V_9 == V_69 ) {
V_6 = F_6 ( V_2 , V_70 ) ;
F_7 ((result == 0), L_2 , return result) ;
V_6 = F_6 ( V_2 , V_71 ) ;
F_7 ((result == 0), L_2 , return result) ;
} else if ( V_2 -> V_9 == V_10 ) {
V_6 = F_6 ( V_2 , V_72 ) ;
F_7 ((result == 0), L_2 , return result) ;
if ( V_2 -> V_41 -> V_73 )
V_6 = F_6 ( V_2 , V_74 ) ;
else
V_6 = F_6 ( V_2 , V_75 ) ;
F_7 ((result == 0), L_2 , return result) ;
} else if ( V_2 -> V_9 == V_76 ) {
V_6 = F_6 ( V_2 , V_72 ) ;
F_7 ((result == 0), L_2 , return result) ;
V_6 = F_6 ( V_2 , V_77 ) ;
F_7 ((result == 0), L_2 , return result) ;
}
}
F_9 ( V_2 -> V_16 , V_65 , V_59 ) ;
V_6 = F_1 ( V_2 , true ) ;
F_7 ((result == 0), L_3 , return result) ;
if ( V_2 -> V_9 == V_10 ) {
V_6 = F_13 ( V_2 -> V_41 ,
( V_78 ) ( V_79 ) ) ;
F_7 ((0 == result),
L_4 , return result) ;
}
F_12 ( V_2 -> V_16 , false ) ;
}
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_6 ;
if ( F_2 ( V_2 -> V_13 . V_14 , V_15 ) ||
F_2 ( V_2 -> V_13 . V_14 , V_23 ) ||
F_2 ( V_2 -> V_13 . V_14 , V_29 ) ||
F_2 ( V_2 -> V_13 . V_14 , V_35 ) ) {
F_12 ( V_2 -> V_16 , true ) ;
V_6 = F_1 ( V_2 , false ) ;
F_7 ((result == 0),
L_5 ,
return result) ;
if ( V_2 -> V_9 == V_10 ) {
V_6 = F_13 ( V_2 -> V_41 ,
( V_78 ) ( V_80 ) ) ;
F_7 ((0 == result),
L_6 , return result) ;
}
F_12 ( V_2 -> V_16 , false ) ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_81 * V_8 = (struct V_81 * ) ( V_2 -> V_82 ) ;
int V_6 = 0 ;
if ( F_2 ( V_2 -> V_13 . V_14 ,
V_83 ) ) {
int V_84 ;
V_84 = F_13 ( V_2 -> V_41 ,
( V_78 ) ( V_85 ) ) ;
F_7 ( ( 0 == V_84 ) ,
L_7 , V_6 = - 1 ) ;
V_8 -> V_86 = ( 0 == V_84 ) ? true : false ;
}
return V_6 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_81 * V_8 = (struct V_81 * ) ( V_2 -> V_82 ) ;
int V_6 = 0 ;
if ( F_2 ( V_2 -> V_13 . V_14 ,
V_83 ) && V_8 -> V_86 ) {
int V_84 = F_13 ( V_2 -> V_41 ,
( V_78 ) ( V_87 ) ) ;
F_7 ( ( V_84 == 0 ) ,
L_8 , V_6 = - 1 ) ;
V_8 -> V_86 = false ;
}
return V_6 ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_88 )
{
struct V_81 * V_8 = (struct V_81 * ) ( V_2 -> V_82 ) ;
if ( V_8 -> V_89 &
V_90 )
return F_5 ( V_2 -> V_41 ,
V_91 , V_88 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_1 V_92 )
{
return F_5 ( V_2 -> V_41 ,
V_93 , V_92 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_81 * V_8 = (struct V_81 * ) ( V_2 -> V_82 ) ;
struct V_94 * V_95 =
(struct V_94 * ) ( V_2 -> V_96 ) ;
int V_84 ;
int V_6 = 0 ;
struct V_97 * V_98 ;
V_8 -> V_89 = 0 ;
if ( V_2 -> V_99 == V_100 )
V_98 = V_95 -> V_101 ;
else
V_98 = V_2 -> V_102 . V_101 ;
if ( F_2 ( V_2 -> V_13 . V_14 ,
V_103 ) ) {
if ( V_8 -> V_104 ) {
V_84 = F_13 ( V_2 -> V_41 ,
( V_78 ) ( V_105 ) ) ;
F_7 ((0 == smc_result),
L_9 , result = -1;) ;
if ( 0 == V_84 )
V_8 -> V_89 |=
V_106 ;
}
if ( V_8 -> V_107 ) {
V_84 = F_13 ( V_2 -> V_41 ,
( V_78 ) ( V_108 ) ) ;
F_7 ((0 == smc_result),
L_10 , result = -1;) ;
if ( 0 == V_84 ) {
T_1 V_109 =
( T_1 ) ( V_98 -> V_110 * 256 ) ;
V_8 -> V_89 |=
V_90 ;
if ( F_17 ( V_2 , V_109 ) )
F_20 ( L_11 ) ;
}
}
}
return V_6 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_81 * V_8 = (struct V_81 * ) ( V_2 -> V_82 ) ;
int V_6 = 0 ;
if ( F_2 ( V_2 -> V_13 . V_14 ,
V_103 ) &&
V_8 -> V_89 ) {
int V_84 ;
if ( V_8 -> V_89 &
V_106 ) {
V_84 = F_13 ( V_2 -> V_41 ,
( V_78 ) ( V_111 ) ) ;
F_7 ( ( V_84 == 0 ) ,
L_12 ,
V_6 = V_84 ) ;
}
if ( V_8 -> V_89 &
V_112 ) {
V_84 = F_13 ( V_2 -> V_41 ,
( V_78 ) ( V_113 ) ) ;
F_7 ( ( V_84 == 0 ) ,
L_13 ,
V_6 = V_84 ) ;
}
if ( V_8 -> V_89 &
V_90 ) {
V_84 = F_13 ( V_2 -> V_41 ,
( V_78 ) ( V_114 ) ) ;
F_7 ( ( V_84 == 0 ) ,
L_14 ,
V_6 = V_84 ) ;
}
V_8 -> V_89 = 0 ;
}
return V_6 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_94 * V_95 =
(struct V_94 * ) ( V_2 -> V_96 ) ;
struct V_97 * V_98 ;
int V_115 , V_92 ;
int V_6 = 0 ;
if ( V_2 -> V_99 == V_100 )
V_98 = V_95 -> V_101 ;
else
V_98 = V_2 -> V_102 . V_101 ;
if ( F_2 ( V_2 -> V_13 . V_14 ,
V_103 ) ) {
V_115 = V_2 -> V_13 . V_116 ?
V_2 -> V_13 . V_117 :
( - 1 * V_2 -> V_13 . V_117 ) ;
V_92 = ( ( 100 + V_115 ) * ( int ) ( V_98 -> V_118 * 256 ) ) / 100 ;
V_6 = F_18 ( V_2 , ( T_1 ) V_92 ) ;
}
return V_6 ;
}
