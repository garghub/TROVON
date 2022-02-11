static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ) ;
}
static struct V_4 * F_3 (
struct V_5 * V_6 ,
T_1 V_7 )
{
int V_8 ;
T_2 V_9 = F_4 ( V_7 ) ;
T_2 V_10 = F_5 ( V_7 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_11 ; V_8 ++ ) {
T_2 V_12 = V_9 ;
if ( ! V_6 -> V_13 [ V_8 ] . V_14 )
continue;
if ( V_6 -> V_13 [ V_8 ] . V_15 )
V_12 = V_10 ;
if ( V_6 -> V_13 [ V_8 ] . V_9 == V_12 )
return & V_6 -> V_13 [ V_8 ] ;
}
F_6 ( L_1 ,
V_7 , V_9 , V_10 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_11 ; V_8 ++ ) {
if ( V_6 -> V_13 [ V_8 ] . V_16 )
F_6 ( L_2 , V_8 ,
V_6 -> V_13 [ V_8 ] . V_14 ? 'v' : ' ' ,
V_6 -> V_13 [ V_8 ] . V_17 ? 'l' : ' ' ,
V_6 -> V_13 [ V_8 ] . V_15 ? 't' : ' ' ,
V_6 -> V_13 [ V_8 ] . V_9 ,
V_6 -> V_13 [ V_8 ] . V_16 ) ;
}
return NULL ;
}
static T_2 F_7 ( struct V_1 * V_2 , T_1 V_7 ,
bool V_18 )
{
struct V_4 * V_13 ;
V_13 = F_3 ( F_8 ( V_2 ) , V_7 ) ;
if ( ! V_13 )
return 0 ;
if ( V_13 -> V_15 )
return ( ( ( T_2 ) V_7 >> 12 ) & 0xfffffff ) |
( ( ( T_2 ) V_13 -> V_16 ) << 28 ) ;
return ( ( ( T_2 ) V_7 >> 12 ) & 0xffff ) | ( ( ( T_2 ) V_13 -> V_16 ) << 16 ) ;
}
static int F_9 ( struct V_4 * V_19 )
{
return V_19 -> V_17 ? 24 : 12 ;
}
static T_3 F_10 ( struct V_4 * V_19 , T_1 V_7 )
{
int V_20 = F_9 ( V_19 ) ;
return ( ( V_7 & 0xfffffff ) >> V_20 ) ;
}
static T_4 F_11 (
struct V_5 * V_6 ,
struct V_4 * V_19 , T_1 V_7 ,
bool V_21 )
{
T_2 V_22 , V_23 , V_24 ;
T_3 V_25 ;
T_4 V_26 ;
V_25 = F_10 ( V_19 , V_7 ) ;
V_24 = ( ( 1 << ( ( V_6 -> V_27 & 0x1f ) + 11 ) ) - 1 ) ;
V_22 = V_19 -> V_16 ^ V_25 ;
if ( V_21 )
V_22 = ~ V_22 ;
V_22 &= ( ( 1ULL << 39ULL ) - 1ULL ) ;
V_22 &= V_24 ;
V_22 <<= 7ULL ;
V_23 = V_6 -> V_27 & 0xfffffffffffc0000ULL ;
V_23 |= V_22 ;
F_6 ( L_3 ,
V_25 , V_6 -> V_27 , V_23 , V_19 -> V_16 ) ;
V_26 = F_12 ( V_6 -> V_2 . V_28 , V_23 >> V_29 ) ;
if ( F_13 ( V_26 ) )
return V_26 ;
return V_26 | ( V_23 & ~ V_30 ) ;
}
static T_2 F_14 ( struct V_4 * V_19 , T_1 V_7 )
{
int V_20 = F_9 ( V_19 ) ;
T_2 V_31 ;
V_31 = F_10 ( V_19 , V_7 ) ;
V_31 |= V_19 -> V_16 << ( 28 - V_20 ) ;
if ( V_20 < 24 )
V_31 >>= ( ( 80 - V_20 ) - 56 ) - 8 ;
else
V_31 <<= 8 ;
return V_31 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_7 ,
struct V_32 * V_33 , bool V_18 )
{
struct V_5 * V_6 = F_8 ( V_2 ) ;
struct V_4 * V_19 ;
T_4 V_34 ;
T_2 V_23 [ 16 ] ;
T_2 V_31 = 0 ;
int V_8 ;
T_5 V_35 = 0 ;
bool V_36 = false ;
bool V_37 = false ;
int V_21 = 0 ;
T_6 V_38 = V_2 -> V_39 . V_40 ;
if ( F_16 ( V_38 ) &&
F_16 ( ( V_7 & ~ 0xfffULL ) == ( V_38 & ~ 0xfffULL ) ) &&
! ( V_2 -> V_39 . V_41 -> V_42 & V_43 ) ) {
V_33 -> V_7 = V_7 ;
V_33 -> V_44 = F_7 ( V_2 , V_7 , V_18 ) ;
V_33 -> V_45 = V_2 -> V_39 . V_46 | ( V_33 -> V_45 & 0xfff ) ;
V_33 -> V_45 &= V_47 ;
V_33 -> V_48 = true ;
V_33 -> V_49 = true ;
V_33 -> V_50 = true ;
return 0 ;
}
V_19 = F_3 ( V_6 , V_7 ) ;
if ( ! V_19 )
goto V_51;
V_52:
V_34 = F_11 ( V_6 , V_19 , V_7 , V_21 ) ;
if ( F_13 ( V_34 ) )
goto V_53;
V_31 = F_14 ( V_19 , V_7 ) ;
if( F_17 ( V_23 , ( void V_54 * ) V_34 , sizeof( V_23 ) ) ) {
F_18 ( V_55 L_4 , V_34 ) ;
goto V_53;
}
if ( ( V_2 -> V_39 . V_41 -> V_42 & V_43 ) && V_19 -> V_56 )
V_35 = 4 ;
else if ( ! ( V_2 -> V_39 . V_41 -> V_42 & V_43 ) && V_19 -> V_57 )
V_35 = 4 ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 += 2 ) {
T_2 V_58 = V_23 [ V_8 ] ;
T_2 V_26 = V_23 [ V_8 + 1 ] ;
if ( ! ( V_58 & V_59 ) )
continue;
if ( ( V_58 & V_60 ) != V_21 )
continue;
if ( F_19 ( V_31 ) == F_19 ( V_58 ) ) {
T_5 V_61 = ( V_26 & V_62 ) | V_35 ;
int V_63 = 0xFFF ;
V_33 -> V_7 = V_7 ;
V_33 -> V_44 = F_7 ( V_2 ,
V_7 ,
V_18 ) ;
if ( V_19 -> V_17 )
V_63 = 0xFFFFFF ;
V_33 -> V_45 = ( V_26 & V_64 ) | ( V_7 & V_63 ) ;
V_33 -> V_48 = ( ( V_26 & V_65 ) ? false : true ) ;
V_33 -> V_49 = false ;
V_33 -> V_50 = false ;
switch ( V_61 ) {
case 0 :
case 1 :
case 2 :
case 6 :
V_33 -> V_50 = true ;
case 3 :
case 5 :
case 7 :
V_33 -> V_49 = true ;
break;
}
if ( ! V_33 -> V_49 ) {
V_37 = true ;
continue;
}
F_6 ( L_5
L_6 ,
V_7 , V_31 , V_33 -> V_44 , V_33 -> V_45 ) ;
V_36 = true ;
break;
}
}
if ( V_36 ) {
T_3 V_66 = V_23 [ V_8 + 1 ] ;
if ( V_33 -> V_49 ) {
V_23 [ V_8 + 1 ] |= V_67 ;
}
if ( V_33 -> V_50 ) {
V_23 [ V_8 + 1 ] |= V_68 ;
} else {
F_6 ( L_7 ) ;
}
if ( V_23 [ V_8 + 1 ] != V_66 )
F_20 ( ( void V_54 * ) V_34 , V_23 , sizeof( V_23 ) ) ;
return 0 ;
} else {
F_6 ( L_8
L_9 ,
V_7 , F_8 ( V_2 ) -> V_27 , V_34 ) ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 += 2 )
F_6 ( L_10 ,
V_8 , V_23 [ V_8 ] , V_23 [ V_8 + 1 ] , V_31 ) ;
if ( ! V_21 ) {
V_21 = V_60 ;
goto V_52;
}
}
V_53:
if ( V_37 )
return - V_69 ;
return - V_70 ;
V_51:
F_6 ( L_11 ) ;
return - V_71 ;
}
static void F_21 ( struct V_1 * V_2 , T_2 V_72 , T_2 V_73 )
{
struct V_5 * V_6 ;
T_2 V_9 , V_10 ;
int V_11 ;
struct V_4 * V_19 ;
F_6 ( L_12 , V_72 , V_73 ) ;
V_6 = F_8 ( V_2 ) ;
V_9 = F_4 ( V_73 ) ;
V_10 = F_5 ( V_73 ) ;
V_11 = V_73 & 0xfff ;
if ( V_11 > V_6 -> V_11 )
return;
V_19 = & V_6 -> V_13 [ V_11 ] ;
V_19 -> V_17 = ( V_72 & V_74 ) ? 1 : 0 ;
V_19 -> V_15 = ( V_72 & V_75 ) ? 1 : 0 ;
V_19 -> V_9 = V_19 -> V_15 ? V_10 : V_9 ;
V_19 -> V_16 = V_72 >> 12 ;
V_19 -> V_14 = ( V_73 & V_76 ) ? 1 : 0 ;
V_19 -> V_57 = ( V_72 & V_77 ) ? 1 : 0 ;
V_19 -> V_56 = ( V_72 & V_78 ) ? 1 : 0 ;
V_19 -> V_79 = ( V_72 & V_80 ) ? 1 : 0 ;
V_19 -> V_81 = ( V_72 & V_82 ) ? 1 : 0 ;
V_19 -> V_83 = V_73 & ( V_84 | V_76 ) ;
V_19 -> V_85 = V_72 ;
F_22 ( V_2 , V_9 << V_86 ) ;
}
static T_2 F_23 ( struct V_1 * V_2 , T_2 V_11 )
{
struct V_5 * V_6 = F_8 ( V_2 ) ;
struct V_4 * V_19 ;
if ( V_11 > V_6 -> V_11 )
return 0 ;
V_19 = & V_6 -> V_13 [ V_11 ] ;
return V_19 -> V_83 ;
}
static T_2 F_24 ( struct V_1 * V_2 , T_2 V_11 )
{
struct V_5 * V_6 = F_8 ( V_2 ) ;
struct V_4 * V_19 ;
if ( V_11 > V_6 -> V_11 )
return 0 ;
V_19 = & V_6 -> V_13 [ V_11 ] ;
return V_19 -> V_85 ;
}
static void F_25 ( struct V_1 * V_2 , T_2 V_87 )
{
struct V_5 * V_6 = F_8 ( V_2 ) ;
struct V_4 * V_19 ;
F_6 ( L_13 , V_87 ) ;
V_19 = F_3 ( V_6 , V_87 ) ;
if ( ! V_19 )
return;
F_6 ( L_14 , V_87 , V_19 -> V_9 ) ;
V_19 -> V_14 = false ;
F_22 ( V_2 , V_87 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_8 ( V_2 ) ;
int V_8 ;
F_6 ( L_15 ) ;
for ( V_8 = 1 ; V_8 < V_6 -> V_11 ; V_8 ++ )
V_6 -> V_13 [ V_8 ] . V_14 = false ;
if ( V_2 -> V_39 . V_41 -> V_42 & V_88 ) {
F_27 ( V_2 ) ;
F_22 ( V_2 , F_28 ( V_2 ) ) ;
}
}
static void F_29 ( struct V_1 * V_2 , T_3 V_89 ,
T_6 V_90 )
{
T_2 V_73 = 0 , V_72 = 0 ;
F_6 ( L_16 , V_89 , V_90 ) ;
V_73 |= ( V_89 & 0xf ) << 28 ;
V_73 |= 1 << 27 ;
V_73 |= V_89 ;
V_72 |= ( V_90 & 0xfffffff ) << 12 ;
V_72 |= ( ( V_90 >> 28 ) & 0x7 ) << 9 ;
F_21 ( V_2 , V_72 , V_73 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_6 V_91 ,
bool V_17 )
{
T_2 V_92 = 0xFFFFFFFFFULL ;
F_6 ( L_17 , V_91 ) ;
if ( V_17 )
V_92 = 0xFFFFFF000ULL ;
F_31 ( V_2 , V_91 >> 12 , V_92 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_6 V_9 ,
T_2 * V_16 )
{
T_6 V_87 = V_9 << V_86 ;
struct V_4 * V_13 ;
T_2 V_93 = V_9 ;
T_6 V_38 = V_2 -> V_39 . V_40 ;
if ( V_2 -> V_39 . V_41 -> V_42 & ( V_94 | V_88 ) ) {
V_13 = F_3 ( F_8 ( V_2 ) , V_87 ) ;
if ( V_13 )
V_93 = V_13 -> V_16 ;
}
switch ( V_2 -> V_39 . V_41 -> V_42 & ( V_94 | V_88 ) ) {
case 0 :
* V_16 = V_95 | V_9 ;
break;
case V_88 :
* V_16 = V_96 | V_93 ;
break;
case V_94 :
* V_16 = V_97 | V_93 ;
break;
case V_94 | V_88 :
if ( ! V_13 )
goto V_98;
* V_16 = V_93 ;
break;
default:
F_33 () ;
break;
}
if ( V_2 -> V_39 . V_41 -> V_42 & V_43 )
* V_16 |= V_99 ;
return 0 ;
V_98:
if ( F_16 ( V_38 ) &&
F_16 ( V_9 == ( V_38 >> V_86 ) ) &&
! ( V_2 -> V_39 . V_41 -> V_42 & V_43 ) ) {
* V_16 = V_95 | V_9 ;
return 0 ;
}
return - V_71 ;
}
static bool F_34 ( struct V_1 * V_2 )
{
return ( F_8 ( V_2 ) -> V_100 [ 5 ] & 0x80 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_101 * V_102 = & V_2 -> V_39 . V_102 ;
V_102 -> V_103 = NULL ;
V_102 -> V_104 = F_29 ;
V_102 -> V_105 = F_21 ;
V_102 -> V_106 = F_23 ;
V_102 -> V_107 = F_24 ;
V_102 -> V_108 = F_25 ;
V_102 -> V_109 = F_26 ;
V_102 -> V_110 = F_15 ;
V_102 -> V_111 = F_1 ;
V_102 -> V_112 = F_30 ;
V_102 -> V_113 = F_32 ;
V_102 -> V_114 = F_7 ;
V_102 -> V_115 = F_34 ;
V_2 -> V_39 . V_116 |= V_117 ;
}
