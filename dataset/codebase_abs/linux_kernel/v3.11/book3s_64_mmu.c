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
int V_6 ;
T_5 V_44 = 0 ;
bool V_45 = false ;
int V_25 = 0 ;
T_6 V_46 = V_2 -> V_9 . V_47 ;
if ( F_20 ( V_46 ) &&
F_20 ( ( V_5 & ~ 0xfffULL ) == ( V_46 & ~ 0xfffULL ) ) &&
! ( V_2 -> V_9 . V_48 -> V_49 & V_50 ) ) {
V_42 -> V_5 = V_5 ;
V_42 -> V_51 = F_10 ( V_2 , V_5 , V_21 ) ;
V_42 -> V_52 = V_2 -> V_9 . V_53 | ( V_42 -> V_52 & 0xfff ) ;
V_42 -> V_52 &= V_54 ;
V_42 -> V_55 = true ;
V_42 -> V_56 = true ;
V_42 -> V_57 = true ;
return 0 ;
}
V_17 = F_3 ( V_2 , V_5 ) ;
if ( ! V_17 )
goto V_58;
V_40 = F_17 ( V_17 , V_5 ) ;
if ( V_17 -> V_14 )
V_40 |= V_59 ;
V_60:
V_43 = F_13 ( V_24 , V_17 , V_5 , V_25 ) ;
if ( F_16 ( V_43 ) )
goto V_61;
if( F_21 ( V_27 , ( void V_62 * ) V_43 , sizeof( V_27 ) ) ) {
F_22 ( V_63 L_4 , V_43 ) ;
goto V_61;
}
if ( ( V_2 -> V_9 . V_48 -> V_49 & V_50 ) && V_17 -> V_64 )
V_44 = 4 ;
else if ( ! ( V_2 -> V_9 . V_48 -> V_49 & V_50 ) && V_17 -> V_65 )
V_44 = 4 ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 += 2 ) {
T_2 V_66 = V_27 [ V_6 ] ;
T_2 V_30 = V_27 [ V_6 + 1 ] ;
if ( ! ( V_66 & V_67 ) )
continue;
if ( ( V_66 & V_68 ) != V_25 )
continue;
if ( F_23 ( V_40 , V_66 ) ) {
T_5 V_69 = ( V_30 & V_70 ) | V_44 ;
int V_71 = 0xFFF ;
V_42 -> V_5 = V_5 ;
V_42 -> V_51 = F_10 ( V_2 ,
V_5 ,
V_21 ) ;
if ( V_17 -> V_16 )
V_71 = 0xFFFFFF ;
V_42 -> V_52 = ( V_30 & V_72 ) | ( V_5 & V_71 ) ;
V_42 -> V_55 = ( ( V_30 & V_73 ) ? false : true ) ;
V_42 -> V_56 = false ;
V_42 -> V_57 = false ;
switch ( V_69 ) {
case 0 :
case 1 :
case 2 :
case 6 :
V_42 -> V_57 = true ;
case 3 :
case 5 :
case 7 :
V_42 -> V_56 = true ;
break;
}
F_6 ( L_5
L_6 ,
V_5 , V_40 , V_42 -> V_51 , V_42 -> V_52 ) ;
V_45 = true ;
break;
}
}
if ( V_45 ) {
T_3 V_74 = V_27 [ V_6 + 1 ] ;
if ( V_42 -> V_56 ) {
V_27 [ V_6 + 1 ] |= V_75 ;
}
if ( V_42 -> V_57 ) {
V_27 [ V_6 + 1 ] |= V_76 ;
} else {
F_6 ( L_7 ) ;
}
if ( V_27 [ V_6 + 1 ] != V_74 )
F_24 ( ( void V_62 * ) V_43 , V_27 , sizeof( V_27 ) ) ;
if ( ! V_42 -> V_56 )
return - V_77 ;
return 0 ;
} else {
F_6 ( L_8
L_9 ,
V_5 , F_19 ( V_2 ) -> V_32 , V_43 ) ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 += 2 )
F_6 ( L_10 ,
V_6 , V_27 [ V_6 ] , V_27 [ V_6 + 1 ] , V_40 ) ;
if ( ! V_25 ) {
V_25 = V_68 ;
goto V_60;
}
}
V_61:
return - V_78 ;
V_58:
F_6 ( L_11 ) ;
return - V_79 ;
}
static void F_25 ( struct V_1 * V_2 , T_2 V_80 , T_2 V_81 )
{
struct V_23 * V_24 ;
T_2 V_7 , V_8 ;
int V_10 ;
struct V_4 * V_17 ;
F_6 ( L_12 , V_80 , V_81 ) ;
V_24 = F_19 ( V_2 ) ;
V_7 = F_4 ( V_81 ) ;
V_8 = F_5 ( V_81 ) ;
V_10 = V_81 & 0xfff ;
if ( V_10 > V_2 -> V_9 . V_10 )
return;
V_17 = & V_2 -> V_9 . V_12 [ V_10 ] ;
V_17 -> V_16 = ( V_80 & V_82 ) ? 1 : 0 ;
V_17 -> V_14 = ( V_80 & V_59 ) ? 1 : 0 ;
V_17 -> V_7 = V_17 -> V_14 ? V_8 : V_7 ;
V_17 -> V_15 = ( V_80 & ~ V_83 ) >> ( F_7 ( V_17 ) - 16 ) ;
V_17 -> V_13 = ( V_81 & V_84 ) ? 1 : 0 ;
V_17 -> V_65 = ( V_80 & V_85 ) ? 1 : 0 ;
V_17 -> V_64 = ( V_80 & V_86 ) ? 1 : 0 ;
V_17 -> V_87 = ( V_80 & V_88 ) ? 1 : 0 ;
V_17 -> V_89 = ( V_80 & V_90 ) ? 1 : 0 ;
V_17 -> V_91 = V_81 & ( V_92 | V_84 ) ;
V_17 -> V_93 = V_80 ;
F_26 ( V_2 , V_7 << V_19 ) ;
}
static T_2 F_27 ( struct V_1 * V_2 , T_2 V_10 )
{
struct V_4 * V_17 ;
if ( V_10 > V_2 -> V_9 . V_10 )
return 0 ;
V_17 = & V_2 -> V_9 . V_12 [ V_10 ] ;
return V_17 -> V_91 ;
}
static T_2 F_28 ( struct V_1 * V_2 , T_2 V_10 )
{
struct V_4 * V_17 ;
if ( V_10 > V_2 -> V_9 . V_10 )
return 0 ;
V_17 = & V_2 -> V_9 . V_12 [ V_10 ] ;
return V_17 -> V_93 ;
}
static void F_29 ( struct V_1 * V_2 , T_2 V_94 )
{
struct V_4 * V_17 ;
T_2 V_95 ;
F_6 ( L_13 , V_94 ) ;
V_17 = F_3 ( V_2 , V_94 ) ;
if ( ! V_17 )
return;
F_6 ( L_14 , V_94 , V_17 -> V_7 ) ;
V_17 -> V_13 = false ;
V_17 -> V_91 = 0 ;
V_17 -> V_93 = 0 ;
V_95 = 1ull << F_7 ( V_17 ) ;
F_30 ( V_2 , V_94 & ~ ( V_95 - 1 ) , V_95 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
int V_6 ;
F_6 ( L_15 ) ;
for ( V_6 = 1 ; V_6 < V_2 -> V_9 . V_10 ; V_6 ++ ) {
V_2 -> V_9 . V_12 [ V_6 ] . V_13 = false ;
V_2 -> V_9 . V_12 [ V_6 ] . V_91 = 0 ;
V_2 -> V_9 . V_12 [ V_6 ] . V_93 = 0 ;
}
if ( V_2 -> V_9 . V_48 -> V_49 & V_96 ) {
F_32 ( V_2 ) ;
F_26 ( V_2 , F_33 ( V_2 ) ) ;
}
}
static void F_34 ( struct V_1 * V_2 , T_3 V_97 ,
T_6 V_98 )
{
T_2 V_81 = 0 , V_80 = 0 ;
F_6 ( L_16 , V_97 , V_98 ) ;
V_81 |= ( V_97 & 0xf ) << 28 ;
V_81 |= 1 << 27 ;
V_81 |= V_97 ;
V_80 |= ( V_98 & 0xfffffff ) << 12 ;
V_80 |= ( ( V_98 >> 28 ) & 0x7 ) << 9 ;
F_25 ( V_2 , V_80 , V_81 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_6 V_99 ,
bool V_16 )
{
T_2 V_100 = 0xFFFFFFFFFULL ;
F_6 ( L_17 , V_99 ) ;
if ( V_16 )
V_100 = 0xFFFFFF000ULL ;
F_36 ( V_2 , V_99 >> 12 , V_100 ) ;
}
static int F_37 ( struct V_1 * V_2 , T_6 V_7 ,
T_2 * V_15 )
{
T_6 V_94 = V_7 << V_19 ;
struct V_4 * V_12 ;
T_2 V_101 = V_7 ;
T_6 V_46 = V_2 -> V_9 . V_47 ;
if ( V_2 -> V_9 . V_48 -> V_49 & ( V_102 | V_96 ) ) {
V_12 = F_3 ( V_2 , V_94 ) ;
if ( V_12 ) {
V_101 = V_12 -> V_15 ;
if ( V_12 -> V_14 ) {
V_101 <<= V_18 - V_19 ;
V_101 |= V_7 & ( ( 1ul << ( V_18 - V_19 ) ) - 1 ) ;
V_101 |= V_103 ;
}
}
}
switch ( V_2 -> V_9 . V_48 -> V_49 & ( V_102 | V_96 ) ) {
case 0 :
* V_15 = V_104 | V_7 ;
break;
case V_96 :
* V_15 = V_105 | V_101 ;
break;
case V_102 :
* V_15 = V_106 | V_101 ;
break;
case V_102 | V_96 :
if ( ! V_12 )
goto V_107;
* V_15 = V_101 ;
break;
default:
F_38 () ;
break;
}
if ( V_2 -> V_9 . V_48 -> V_49 & V_50 )
* V_15 |= V_108 ;
return 0 ;
V_107:
if ( F_20 ( V_46 ) &&
F_20 ( V_7 == ( V_46 >> V_19 ) ) &&
! ( V_2 -> V_9 . V_48 -> V_49 & V_50 ) ) {
* V_15 = V_104 | V_7 ;
return 0 ;
}
return - V_79 ;
}
static bool F_39 ( struct V_1 * V_2 )
{
return ( F_19 ( V_2 ) -> V_109 [ 5 ] & 0x80 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = & V_2 -> V_9 . V_111 ;
V_111 -> V_112 = NULL ;
V_111 -> V_113 = F_34 ;
V_111 -> V_114 = F_25 ;
V_111 -> V_115 = F_27 ;
V_111 -> V_116 = F_28 ;
V_111 -> V_117 = F_29 ;
V_111 -> V_118 = F_31 ;
V_111 -> V_119 = F_18 ;
V_111 -> V_120 = F_1 ;
V_111 -> V_121 = F_35 ;
V_111 -> V_122 = F_37 ;
V_111 -> V_123 = F_10 ;
V_111 -> V_124 = F_39 ;
V_2 -> V_9 . V_125 |= V_126 ;
}
