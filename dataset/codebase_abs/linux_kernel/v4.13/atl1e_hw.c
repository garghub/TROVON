int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 & V_5 ) {
V_3 &= ~ V_5 ;
F_3 ( V_2 , V_4 , V_3 ) ;
}
V_3 = F_4 ( V_2 , V_6 ) ;
return ( ( V_3 & 0xFF00 ) == 0x6C00 ) ? 0 : 1 ;
}
void F_5 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = ( ( ( T_1 ) V_2 -> V_7 [ 2 ] ) << 24 ) |
( ( ( T_1 ) V_2 -> V_7 [ 3 ] ) << 16 ) |
( ( ( T_1 ) V_2 -> V_7 [ 4 ] ) << 8 ) |
( ( ( T_1 ) V_2 -> V_7 [ 5 ] ) ) ;
F_6 ( V_2 , V_8 , 0 , V_3 ) ;
V_3 = ( ( ( T_1 ) V_2 -> V_7 [ 0 ] ) << 8 ) |
( ( ( T_1 ) V_2 -> V_7 [ 1 ] ) ) ;
F_6 ( V_2 , V_8 , 1 , V_3 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_9 [ 2 ] ;
T_1 V_10 ;
T_1 V_11 ;
T_2 V_12 [ V_13 ] ;
if ( F_8 ( V_2 -> V_14 ) )
return 0 ;
V_9 [ 0 ] = V_9 [ 1 ] = 0 ;
if ( ! F_1 ( V_2 ) ) {
V_11 = F_2 ( V_2 , V_15 ) ;
V_11 |= V_16 ;
F_3 ( V_2 , V_15 , V_11 ) ;
for ( V_10 = 0 ; V_10 < V_17 ; V_10 ++ ) {
F_9 ( 10 ) ;
V_11 = F_2 ( V_2 , V_15 ) ;
if ( ( V_11 & V_16 ) == 0 )
break;
}
if ( V_10 >= V_17 )
return V_18 ;
}
V_9 [ 0 ] = F_2 ( V_2 , V_8 ) ;
V_9 [ 1 ] = F_2 ( V_2 , V_8 + 4 ) ;
* ( T_1 * ) & V_12 [ 2 ] = F_10 ( V_9 [ 0 ] ) ;
* ( V_19 * ) & V_12 [ 0 ] = F_11 ( * ( V_19 * ) & V_9 [ 1 ] ) ;
if ( F_8 ( V_12 ) ) {
memcpy ( V_2 -> V_14 , V_12 , V_13 ) ;
return 0 ;
}
return V_20 ;
}
bool F_12 ( struct V_1 * V_2 , T_1 V_21 , T_1 V_3 )
{
return true ;
}
bool F_13 ( struct V_1 * V_2 , T_1 V_21 , T_1 * V_22 )
{
int V_10 ;
T_1 V_23 ;
if ( V_21 & 3 )
return false ;
F_3 ( V_2 , V_24 , 0 ) ;
V_23 = ( V_21 & V_25 ) << V_26 ;
F_3 ( V_2 , V_27 , V_23 ) ;
for ( V_10 = 0 ; V_10 < 10 ; V_10 ++ ) {
F_9 ( 2 ) ;
V_23 = F_2 ( V_2 , V_27 ) ;
if ( V_23 & V_28 )
break;
}
if ( V_23 & V_28 ) {
* V_22 = F_2 ( V_2 , V_24 ) ;
return true ;
}
return false ;
}
void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_29 ,
V_30 | V_31 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_32 = 0 ;
V_32 = F_7 ( V_2 ) ;
if ( V_32 )
return V_20 ;
memcpy ( V_2 -> V_7 , V_2 -> V_14 , sizeof( V_2 -> V_14 ) ) ;
return 0 ;
}
T_1 F_17 ( struct V_1 * V_2 , T_2 * V_33 )
{
T_1 V_34 ;
T_1 V_3 = 0 ;
int V_10 ;
V_34 = F_18 ( 6 , V_33 ) ;
for ( V_10 = 0 ; V_10 < 32 ; V_10 ++ )
V_3 |= ( ( ( V_34 >> V_10 ) & 1 ) << ( 31 - V_10 ) ) ;
return V_3 ;
}
void F_19 ( struct V_1 * V_2 , T_1 V_35 )
{
T_1 V_36 , V_37 ;
T_1 V_38 ;
V_37 = ( V_35 >> 31 ) & 0x1 ;
V_36 = ( V_35 >> 26 ) & 0x1F ;
V_38 = F_20 ( V_2 , V_39 , V_37 ) ;
V_38 |= ( 1 << V_36 ) ;
F_6 ( V_2 , V_39 , V_37 , V_38 ) ;
}
int F_21 ( struct V_1 * V_2 , V_19 V_40 , V_19 * V_41 )
{
T_1 V_42 ;
int V_10 ;
V_42 = ( ( T_1 ) ( V_40 & V_43 ) ) << V_44 |
V_45 | V_46 | V_47 |
V_48 << V_49 ;
F_3 ( V_2 , V_50 , V_42 ) ;
F_22 () ;
for ( V_10 = 0 ; V_10 < V_51 ; V_10 ++ ) {
F_23 ( 2 ) ;
V_42 = F_2 ( V_2 , V_50 ) ;
if ( ! ( V_42 & ( V_45 | V_52 ) ) )
break;
F_22 () ;
}
if ( ! ( V_42 & ( V_45 | V_52 ) ) ) {
* V_41 = ( V_19 ) V_42 ;
return 0 ;
}
return V_53 ;
}
int F_24 ( struct V_1 * V_2 , T_1 V_40 , V_19 V_41 )
{
int V_10 ;
T_1 V_42 ;
V_42 = ( ( T_1 ) ( V_41 & V_54 ) ) << V_55 |
( V_40 & V_43 ) << V_44 |
V_46 |
V_45 |
V_48 << V_49 ;
F_3 ( V_2 , V_50 , V_42 ) ;
F_22 () ;
for ( V_10 = 0 ; V_10 < V_51 ; V_10 ++ ) {
F_23 ( 2 ) ;
V_42 = F_2 ( V_2 , V_50 ) ;
if ( ! ( V_42 & ( V_45 | V_52 ) ) )
break;
F_22 () ;
}
if ( ! ( V_42 & ( V_45 | V_52 ) ) )
return 0 ;
return V_53 ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 , 0x1008 ) ;
V_3 |= 0x8000 ;
F_3 ( V_2 , 0x1008 , V_3 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
T_3 V_56 ;
V_19 V_57 ;
V_19 V_58 ;
if ( 0 != V_2 -> V_57 )
return 0 ;
V_57 = V_59 ;
V_58 = V_60 ;
V_57 &= ~ V_61 ;
V_58 &= ~ V_62 ;
switch ( V_2 -> V_63 ) {
case V_64 :
V_57 |= V_61 ;
V_2 -> V_65 = V_61 ;
if ( V_2 -> V_66 == V_67 ) {
V_58 |= V_68 ;
V_2 -> V_65 |= V_69 ;
}
break;
case V_70 :
V_57 |= V_71 ;
V_2 -> V_65 = V_72 ;
break;
case V_73 :
V_57 |= V_74 ;
V_2 -> V_65 = V_74 ;
break;
case V_75 :
V_57 |= V_76 ;
V_2 -> V_65 = V_76 ;
break;
default:
V_57 |= V_77 ;
V_2 -> V_65 = V_77 ;
break;
}
V_57 |= ( V_78 | V_79 ) ;
V_2 -> V_57 = V_57 ;
V_2 -> V_58 = V_58 ;
V_56 = F_24 ( V_2 , V_80 , V_57 ) ;
if ( V_56 )
return V_56 ;
if ( V_2 -> V_66 == V_67 || V_2 -> V_66 == V_81 ) {
V_56 = F_24 ( V_2 , V_82 ,
V_58 ) ;
if ( V_56 )
return V_56 ;
}
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = V_2 -> V_84 ;
int V_56 ;
V_19 V_41 ;
V_41 = V_85 | V_86 | V_87 ;
V_56 = F_24 ( V_2 , V_88 , V_41 ) ;
if ( V_56 ) {
T_1 V_42 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < 25 ; V_10 ++ ) {
F_9 ( 1 ) ;
V_42 = F_2 ( V_2 , V_50 ) ;
if ( ! ( V_42 & ( V_45 | V_52 ) ) )
break;
}
if ( 0 != ( V_42 & ( V_45 | V_52 ) ) ) {
F_28 ( V_84 -> V_89 ,
L_1 ) ;
return V_56 ;
}
F_28 ( V_84 -> V_89 , L_2 , V_10 ) ;
}
return 0 ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = V_2 -> V_84 ;
T_3 V_56 ;
V_19 V_90 ;
if ( V_2 -> V_91 ) {
if ( V_2 -> V_92 ) {
V_2 -> V_92 = false ;
return F_30 ( V_2 ) ;
}
return 0 ;
}
F_15 ( V_2 , V_29 , V_93 ) ;
F_9 ( 2 ) ;
F_15 ( V_2 , V_29 , V_93 |
V_31 ) ;
F_9 ( 2 ) ;
V_56 = F_24 ( V_2 , V_94 , 0xB ) ;
if ( V_56 )
return V_56 ;
V_56 = F_24 ( V_2 , V_95 , 0xBC00 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_24 ( V_2 , V_94 , 0 ) ;
if ( V_56 )
return V_56 ;
V_90 = 0x02ef ;
V_56 = F_24 ( V_2 , V_95 , V_90 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_24 ( V_2 , V_94 , 0x12 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_24 ( V_2 , V_95 , 0x4C04 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_24 ( V_2 , V_94 , 0x4 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_24 ( V_2 , V_95 , 0x8BBB ) ;
if ( V_56 )
return V_56 ;
V_56 = F_24 ( V_2 , V_94 , 0x5 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_24 ( V_2 , V_95 , 0x2C46 ) ;
if ( V_56 )
return V_56 ;
F_9 ( 1 ) ;
V_56 = F_24 ( V_2 , V_96 , 0xC00 ) ;
if ( V_56 ) {
F_28 ( V_84 -> V_89 ,
L_3 ) ;
return V_56 ;
}
V_56 = F_26 ( V_2 ) ;
if ( V_56 ) {
F_28 ( V_84 -> V_89 ,
L_4 ) ;
return V_56 ;
}
F_31 ( V_84 -> V_89 , L_5 ) ;
V_56 = F_27 ( V_2 ) ;
if ( V_56 ) {
F_28 ( V_84 -> V_89 , L_6 ) ;
return V_56 ;
}
V_2 -> V_91 = true ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = V_2 -> V_84 ;
struct V_97 * V_98 = V_84 -> V_98 ;
T_1 V_99 = 0 ;
V_19 V_100 = 0 ;
int V_101 = 0 ;
F_33 ( V_98 , V_102 , & V_100 ) ;
if ( ( V_100 & ( V_103 |
V_104 | V_105 ) )
!= ( V_103 | V_104 | V_105 ) ) {
V_100 |= ( V_103 |
V_104 | V_105 ) ;
F_34 ( V_98 , V_102 , V_100 ) ;
}
F_3 ( V_2 , V_106 ,
V_107 | V_108 ) ;
F_22 () ;
F_9 ( 1 ) ;
for ( V_101 = 0 ; V_101 < V_109 ; V_101 ++ ) {
V_99 = F_2 ( V_2 , V_110 ) ;
if ( V_99 == 0 )
break;
F_9 ( 1 ) ;
F_35 () ;
}
if ( V_101 >= V_109 ) {
F_28 ( V_84 -> V_89 ,
L_7 ) ;
return V_18 ;
}
return 0 ;
}
int F_36 ( struct V_1 * V_2 )
{
T_3 V_56 = 0 ;
F_25 ( V_2 ) ;
F_3 ( V_2 , V_39 , 0 ) ;
F_6 ( V_2 , V_39 , 1 , 0 ) ;
V_56 = F_29 ( V_2 ) ;
return V_56 ;
}
int F_37 ( struct V_1 * V_2 , V_19 * V_111 , V_19 * V_112 )
{
int V_32 ;
V_19 V_41 ;
V_32 = F_21 ( V_2 , V_113 , & V_41 ) ;
if ( V_32 )
return V_32 ;
if ( ! ( V_41 & V_114 ) )
return V_115 ;
switch ( V_41 & V_116 ) {
case V_117 :
* V_111 = V_118 ;
break;
case V_119 :
* V_111 = V_120 ;
break;
case V_121 :
* V_111 = V_122 ;
break;
default:
return V_123 ;
}
if ( V_41 & V_124 )
* V_112 = V_125 ;
else
* V_112 = V_126 ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 )
{
int V_32 = 0 ;
V_32 = F_24 ( V_2 , V_80 , V_2 -> V_57 ) ;
if ( V_32 )
return V_32 ;
if ( V_2 -> V_66 == V_67 || V_2 -> V_66 == V_81 ) {
V_32 = F_24 ( V_2 , V_82 ,
V_2 -> V_58 ) ;
if ( V_32 )
return V_32 ;
}
V_32 = F_24 ( V_2 , V_88 ,
V_85 | V_86 | V_87 ) ;
return V_32 ;
}
