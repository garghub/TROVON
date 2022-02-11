static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ) ;
}
static struct V_4 * F_3 (
struct V_1 * V_2 ,
T_1 V_5 )
{
int V_6 ;
T_2 V_7 = F_4 ( V_5 ) ;
T_2 V_8 = F_5 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_9 . V_10 ; V_6 ++ ) {
T_2 V_11 = V_7 ;
if ( ! V_2 -> V_9 . V_12 [ V_6 ] . V_13 )
continue;
if ( V_2 -> V_9 . V_12 [ V_6 ] . V_14 )
V_11 = V_8 ;
if ( V_2 -> V_9 . V_12 [ V_6 ] . V_7 == V_11 )
return & V_2 -> V_9 . V_12 [ V_6 ] ;
}
F_6 ( L_1 ,
V_5 , V_7 , V_8 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_9 . V_10 ; V_6 ++ ) {
if ( V_2 -> V_9 . V_12 [ V_6 ] . V_15 )
F_6 ( L_2 , V_6 ,
V_2 -> V_9 . V_12 [ V_6 ] . V_13 ? 'v' : ' ' ,
V_2 -> V_9 . V_12 [ V_6 ] . V_16 ? 'l' : ' ' ,
V_2 -> V_9 . V_12 [ V_6 ] . V_14 ? 't' : ' ' ,
V_2 -> V_9 . V_12 [ V_6 ] . V_7 ,
V_2 -> V_9 . V_12 [ V_6 ] . V_15 ) ;
}
return NULL ;
}
static int F_7 ( struct V_4 * V_17 )
{
return V_17 -> V_14 ? V_18 : V_19 ;
}
static T_2 F_8 ( struct V_4 * V_17 )
{
return ( 1ul << F_7 ( V_17 ) ) - 1 ;
}
static T_2 F_9 ( struct V_4 * V_12 , T_1 V_5 )
{
V_5 &= F_8 ( V_12 ) ;
return ( V_5 >> V_20 ) |
( ( V_12 -> V_15 ) << ( F_7 ( V_12 ) - V_20 ) ) ;
}
static T_2 F_10 ( struct V_1 * V_2 , T_1 V_5 ,
bool V_21 )
{
struct V_4 * V_12 ;
V_12 = F_3 ( V_2 , V_5 ) ;
if ( ! V_12 )
return 0 ;
return F_9 ( V_12 , V_5 ) ;
}
static int F_11 ( struct V_4 * V_17 )
{
return V_17 -> V_16 ? 24 : 12 ;
}
static T_3 F_12 ( struct V_4 * V_17 , T_1 V_5 )
{
int V_22 = F_11 ( V_17 ) ;
return ( ( V_5 & F_8 ( V_17 ) ) >> V_22 ) ;
}
static T_4 F_13 (
struct V_23 * V_24 ,
struct V_4 * V_17 , T_1 V_5 ,
bool V_25 )
{
T_2 V_26 , V_27 , V_28 ;
T_3 V_29 ;
T_4 V_30 ;
T_2 V_31 ;
V_28 = ( ( 1 << ( ( V_24 -> V_32 & 0x1f ) + 11 ) ) - 1 ) ;
V_31 = F_9 ( V_17 , V_5 ) ;
V_29 = V_17 -> V_14 ? V_33 : V_34 ;
V_26 = F_14 ( V_31 , F_11 ( V_17 ) , V_29 ) ;
if ( V_25 )
V_26 = ~ V_26 ;
V_26 &= ( ( 1ULL << 39ULL ) - 1ULL ) ;
V_26 &= V_28 ;
V_26 <<= 7ULL ;
V_27 = V_24 -> V_32 & 0xfffffffffffc0000ULL ;
V_27 |= V_26 ;
F_6 ( L_3 ,
V_35 , V_24 -> V_32 , V_27 , V_17 -> V_15 ) ;
if ( V_24 -> V_2 . V_9 . V_36 )
V_30 = V_27 ;
else
V_30 = F_15 ( V_24 -> V_2 . V_37 , V_27 >> V_38 ) ;
if ( F_16 ( V_30 ) )
return V_30 ;
return V_30 | ( V_27 & ~ V_39 ) ;
}
static T_2 F_17 ( struct V_4 * V_17 , T_1 V_5 )
{
int V_22 = F_11 ( V_17 ) ;
T_2 V_40 ;
V_40 = F_12 ( V_17 , V_5 ) ;
V_40 |= V_17 -> V_15 << ( F_7 ( V_17 ) - V_22 ) ;
if ( V_22 < 24 )
V_40 >>= ( ( 80 - V_22 ) - 56 ) - 8 ;
else
V_40 <<= 8 ;
return V_40 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_5 ,
struct V_41 * V_42 , bool V_21 )
{
struct V_23 * V_24 = F_19 ( V_2 ) ;
struct V_4 * V_17 ;
T_4 V_43 ;
T_2 V_27 [ 16 ] ;
T_2 V_40 = 0 ;
T_2 V_44 , V_30 ;
T_2 V_45 , V_46 ;
T_2 V_47 ;
int V_6 ;
T_5 V_48 , V_49 = 0 ;
bool V_50 = false ;
bool V_25 = false ;
T_6 V_51 = V_2 -> V_9 . V_52 ;
if ( F_20 ( V_51 ) &&
F_20 ( ( V_5 & ~ 0xfffULL ) == ( V_51 & ~ 0xfffULL ) ) &&
! ( V_2 -> V_9 . V_53 -> V_54 & V_55 ) ) {
V_42 -> V_5 = V_5 ;
V_42 -> V_56 = F_10 ( V_2 , V_5 , V_21 ) ;
V_42 -> V_57 = V_2 -> V_9 . V_58 | ( V_42 -> V_57 & 0xfff ) ;
V_42 -> V_57 &= V_59 ;
V_42 -> V_60 = true ;
V_42 -> V_61 = true ;
V_42 -> V_62 = true ;
return 0 ;
}
V_17 = F_3 ( V_2 , V_5 ) ;
if ( ! V_17 )
goto V_63;
V_40 = F_17 ( V_17 , V_5 ) ;
V_45 = V_40 & V_64 ;
if ( V_17 -> V_14 )
V_45 |= V_65 ;
if ( V_17 -> V_16 )
V_45 |= V_66 ;
V_45 |= V_67 ;
V_46 = V_68 | V_64 | V_66 | V_67 |
V_69 ;
V_70:
V_43 = F_13 ( V_24 , V_17 , V_5 , V_25 ) ;
if ( F_16 ( V_43 ) )
goto V_71;
if( F_21 ( V_27 , ( void V_72 * ) V_43 , sizeof( V_27 ) ) ) {
F_22 ( V_73 L_4 , V_43 ) ;
goto V_71;
}
if ( ( V_2 -> V_9 . V_53 -> V_54 & V_55 ) && V_17 -> V_74 )
V_49 = 4 ;
else if ( ! ( V_2 -> V_9 . V_53 -> V_54 & V_55 ) && V_17 -> V_75 )
V_49 = 4 ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 += 2 ) {
if ( ( V_27 [ V_6 ] & V_46 ) == V_45 ) {
V_50 = true ;
break;
}
}
if ( ! V_50 ) {
if ( V_25 )
goto V_71;
V_45 |= V_69 ;
V_25 = true ;
goto V_70;
}
V_44 = V_27 [ V_6 ] ;
V_30 = V_27 [ V_6 + 1 ] ;
V_48 = ( V_30 & V_76 ) | V_49 ;
V_47 = 0xFFF ;
V_42 -> V_5 = V_5 ;
V_42 -> V_56 = F_10 ( V_2 , V_5 , V_21 ) ;
if ( V_17 -> V_16 )
V_47 = 0xFFFFFF ;
V_42 -> V_57 = ( V_30 & V_77 & ~ V_47 ) | ( V_5 & V_47 ) ;
V_42 -> V_60 = ( ( V_30 & V_78 ) ? false : true ) ;
V_42 -> V_61 = false ;
V_42 -> V_62 = false ;
switch ( V_48 ) {
case 0 :
case 1 :
case 2 :
case 6 :
V_42 -> V_62 = true ;
case 3 :
case 5 :
case 7 :
V_42 -> V_61 = true ;
break;
}
F_6 ( L_5
L_6 ,
V_5 , V_40 , V_42 -> V_56 , V_42 -> V_57 ) ;
if ( V_42 -> V_61 ) {
V_30 |= V_79 ;
}
if ( V_21 && V_42 -> V_62 ) {
V_30 |= V_80 ;
}
if ( V_27 [ V_6 + 1 ] != V_30 ) {
V_27 [ V_6 + 1 ] = V_30 ;
F_23 ( ( void V_72 * ) V_43 , V_27 , sizeof( V_27 ) ) ;
}
if ( ! V_42 -> V_61 )
return - V_81 ;
return 0 ;
V_71:
return - V_82 ;
V_63:
F_6 ( L_7 ) ;
return - V_83 ;
}
static void F_24 ( struct V_1 * V_2 , T_2 V_84 , T_2 V_85 )
{
struct V_23 * V_24 ;
T_2 V_7 , V_8 ;
int V_10 ;
struct V_4 * V_17 ;
F_6 ( L_8 , V_84 , V_85 ) ;
V_24 = F_19 ( V_2 ) ;
V_7 = F_4 ( V_85 ) ;
V_8 = F_5 ( V_85 ) ;
V_10 = V_85 & 0xfff ;
if ( V_10 > V_2 -> V_9 . V_10 )
return;
V_17 = & V_2 -> V_9 . V_12 [ V_10 ] ;
V_17 -> V_16 = ( V_84 & V_86 ) ? 1 : 0 ;
V_17 -> V_14 = ( V_84 & V_65 ) ? 1 : 0 ;
V_17 -> V_7 = V_17 -> V_14 ? V_8 : V_7 ;
V_17 -> V_15 = ( V_84 & ~ V_68 ) >> ( F_7 ( V_17 ) - 16 ) ;
V_17 -> V_13 = ( V_85 & V_87 ) ? 1 : 0 ;
V_17 -> V_75 = ( V_84 & V_88 ) ? 1 : 0 ;
V_17 -> V_74 = ( V_84 & V_89 ) ? 1 : 0 ;
V_17 -> V_90 = ( V_84 & V_91 ) ? 1 : 0 ;
V_17 -> V_92 = ( V_84 & V_93 ) ? 1 : 0 ;
V_17 -> V_94 = V_85 & ( V_95 | V_87 ) ;
V_17 -> V_96 = V_84 ;
F_25 ( V_2 , V_7 << V_19 ) ;
}
static T_2 F_26 ( struct V_1 * V_2 , T_2 V_10 )
{
struct V_4 * V_17 ;
if ( V_10 > V_2 -> V_9 . V_10 )
return 0 ;
V_17 = & V_2 -> V_9 . V_12 [ V_10 ] ;
return V_17 -> V_94 ;
}
static T_2 F_27 ( struct V_1 * V_2 , T_2 V_10 )
{
struct V_4 * V_17 ;
if ( V_10 > V_2 -> V_9 . V_10 )
return 0 ;
V_17 = & V_2 -> V_9 . V_12 [ V_10 ] ;
return V_17 -> V_96 ;
}
static void F_28 ( struct V_1 * V_2 , T_2 V_97 )
{
struct V_4 * V_17 ;
T_2 V_98 ;
F_6 ( L_9 , V_97 ) ;
V_17 = F_3 ( V_2 , V_97 ) ;
if ( ! V_17 )
return;
F_6 ( L_10 , V_97 , V_17 -> V_7 ) ;
V_17 -> V_13 = false ;
V_17 -> V_94 = 0 ;
V_17 -> V_96 = 0 ;
V_98 = 1ull << F_7 ( V_17 ) ;
F_29 ( V_2 , V_97 & ~ ( V_98 - 1 ) , V_98 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
int V_6 ;
F_6 ( L_11 ) ;
for ( V_6 = 1 ; V_6 < V_2 -> V_9 . V_10 ; V_6 ++ ) {
V_2 -> V_9 . V_12 [ V_6 ] . V_13 = false ;
V_2 -> V_9 . V_12 [ V_6 ] . V_94 = 0 ;
V_2 -> V_9 . V_12 [ V_6 ] . V_96 = 0 ;
}
if ( V_2 -> V_9 . V_53 -> V_54 & V_99 ) {
F_31 ( V_2 ) ;
F_25 ( V_2 , F_32 ( V_2 ) ) ;
}
}
static void F_33 ( struct V_1 * V_2 , T_3 V_100 ,
T_6 V_101 )
{
T_2 V_85 = 0 , V_84 = 0 ;
F_6 ( L_12 , V_100 , V_101 ) ;
V_85 |= ( V_100 & 0xf ) << 28 ;
V_85 |= 1 << 27 ;
V_85 |= V_100 ;
V_84 |= ( V_101 & 0xfffffff ) << 12 ;
V_84 |= ( ( V_101 >> 28 ) & 0x7 ) << 9 ;
F_24 ( V_2 , V_84 , V_85 ) ;
}
static void F_34 ( struct V_1 * V_2 , T_6 V_102 ,
bool V_16 )
{
T_2 V_103 = 0xFFFFFFFFFULL ;
F_6 ( L_13 , V_102 ) ;
if ( V_16 )
V_103 = 0xFFFFFF000ULL ;
F_35 ( V_2 , V_102 >> 12 , V_103 ) ;
}
static int F_36 ( struct V_1 * V_2 , T_6 V_7 ,
T_2 * V_15 )
{
T_6 V_97 = V_7 << V_19 ;
struct V_4 * V_12 ;
T_2 V_104 = V_7 ;
T_6 V_51 = V_2 -> V_9 . V_52 ;
if ( V_2 -> V_9 . V_53 -> V_54 & ( V_105 | V_99 ) ) {
V_12 = F_3 ( V_2 , V_97 ) ;
if ( V_12 ) {
V_104 = V_12 -> V_15 ;
if ( V_12 -> V_14 ) {
V_104 <<= V_18 - V_19 ;
V_104 |= V_7 & ( ( 1ul << ( V_18 - V_19 ) ) - 1 ) ;
V_104 |= V_106 ;
}
}
}
switch ( V_2 -> V_9 . V_53 -> V_54 & ( V_105 | V_99 ) ) {
case 0 :
* V_15 = V_107 | V_7 ;
break;
case V_99 :
* V_15 = V_108 | V_104 ;
break;
case V_105 :
* V_15 = V_109 | V_104 ;
break;
case V_105 | V_99 :
if ( ! V_12 )
goto V_110;
* V_15 = V_104 ;
break;
default:
F_37 () ;
break;
}
if ( V_2 -> V_9 . V_53 -> V_54 & V_55 )
* V_15 |= V_111 ;
return 0 ;
V_110:
if ( F_20 ( V_51 ) &&
F_20 ( V_7 == ( V_51 >> V_19 ) ) &&
! ( V_2 -> V_9 . V_53 -> V_54 & V_55 ) ) {
* V_15 = V_107 | V_7 ;
return 0 ;
}
return - V_83 ;
}
static bool F_38 ( struct V_1 * V_2 )
{
return ( F_19 ( V_2 ) -> V_112 [ 5 ] & 0x80 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_113 * V_114 = & V_2 -> V_9 . V_114 ;
V_114 -> V_115 = NULL ;
V_114 -> V_116 = F_33 ;
V_114 -> V_117 = F_24 ;
V_114 -> V_118 = F_26 ;
V_114 -> V_119 = F_27 ;
V_114 -> V_120 = F_28 ;
V_114 -> V_121 = F_30 ;
V_114 -> V_122 = F_18 ;
V_114 -> V_123 = F_1 ;
V_114 -> V_124 = F_34 ;
V_114 -> V_125 = F_36 ;
V_114 -> V_126 = F_10 ;
V_114 -> V_127 = F_38 ;
V_2 -> V_9 . V_128 |= V_129 ;
}
