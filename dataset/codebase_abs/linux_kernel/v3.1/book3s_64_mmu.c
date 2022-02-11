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
static T_2 F_7 ( struct V_1 * V_2 , T_1 V_5 ,
bool V_17 )
{
struct V_4 * V_12 ;
V_12 = F_3 ( V_2 , V_5 ) ;
if ( ! V_12 )
return 0 ;
if ( V_12 -> V_14 )
return ( ( ( T_2 ) V_5 >> 12 ) & 0xfffffff ) |
( ( ( T_2 ) V_12 -> V_15 ) << 28 ) ;
return ( ( ( T_2 ) V_5 >> 12 ) & 0xffff ) | ( ( ( T_2 ) V_12 -> V_15 ) << 16 ) ;
}
static int F_8 ( struct V_4 * V_18 )
{
return V_18 -> V_16 ? 24 : 12 ;
}
static T_3 F_9 ( struct V_4 * V_18 , T_1 V_5 )
{
int V_19 = F_8 ( V_18 ) ;
return ( ( V_5 & 0xfffffff ) >> V_19 ) ;
}
static T_4 F_10 (
struct V_20 * V_21 ,
struct V_4 * V_18 , T_1 V_5 ,
bool V_22 )
{
T_2 V_23 , V_24 , V_25 ;
T_3 V_26 ;
T_4 V_27 ;
V_26 = F_9 ( V_18 , V_5 ) ;
V_25 = ( ( 1 << ( ( V_21 -> V_28 & 0x1f ) + 11 ) ) - 1 ) ;
V_23 = V_18 -> V_15 ^ V_26 ;
if ( V_22 )
V_23 = ~ V_23 ;
V_23 &= ( ( 1ULL << 39ULL ) - 1ULL ) ;
V_23 &= V_25 ;
V_23 <<= 7ULL ;
V_24 = V_21 -> V_28 & 0xfffffffffffc0000ULL ;
V_24 |= V_23 ;
F_6 ( L_3 ,
V_26 , V_21 -> V_28 , V_24 , V_18 -> V_15 ) ;
V_27 = F_11 ( V_21 -> V_2 . V_29 , V_24 >> V_30 ) ;
if ( F_12 ( V_27 ) )
return V_27 ;
return V_27 | ( V_24 & ~ V_31 ) ;
}
static T_2 F_13 ( struct V_4 * V_18 , T_1 V_5 )
{
int V_19 = F_8 ( V_18 ) ;
T_2 V_32 ;
V_32 = F_9 ( V_18 , V_5 ) ;
V_32 |= V_18 -> V_15 << ( 28 - V_19 ) ;
if ( V_19 < 24 )
V_32 >>= ( ( 80 - V_19 ) - 56 ) - 8 ;
else
V_32 <<= 8 ;
return V_32 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_5 ,
struct V_33 * V_34 , bool V_17 )
{
struct V_20 * V_21 = F_15 ( V_2 ) ;
struct V_4 * V_18 ;
T_4 V_35 ;
T_2 V_24 [ 16 ] ;
T_2 V_32 = 0 ;
int V_6 ;
T_5 V_36 = 0 ;
bool V_37 = false ;
bool V_38 = false ;
int V_22 = 0 ;
T_6 V_39 = V_2 -> V_9 . V_40 ;
if ( F_16 ( V_39 ) &&
F_16 ( ( V_5 & ~ 0xfffULL ) == ( V_39 & ~ 0xfffULL ) ) &&
! ( V_2 -> V_9 . V_41 -> V_42 & V_43 ) ) {
V_34 -> V_5 = V_5 ;
V_34 -> V_44 = F_7 ( V_2 , V_5 , V_17 ) ;
V_34 -> V_45 = V_2 -> V_9 . V_46 | ( V_34 -> V_45 & 0xfff ) ;
V_34 -> V_45 &= V_47 ;
V_34 -> V_48 = true ;
V_34 -> V_49 = true ;
V_34 -> V_50 = true ;
return 0 ;
}
V_18 = F_3 ( V_2 , V_5 ) ;
if ( ! V_18 )
goto V_51;
V_52:
V_35 = F_10 ( V_21 , V_18 , V_5 , V_22 ) ;
if ( F_12 ( V_35 ) )
goto V_53;
V_32 = F_13 ( V_18 , V_5 ) ;
if( F_17 ( V_24 , ( void V_54 * ) V_35 , sizeof( V_24 ) ) ) {
F_18 ( V_55 L_4 , V_35 ) ;
goto V_53;
}
if ( ( V_2 -> V_9 . V_41 -> V_42 & V_43 ) && V_18 -> V_56 )
V_36 = 4 ;
else if ( ! ( V_2 -> V_9 . V_41 -> V_42 & V_43 ) && V_18 -> V_57 )
V_36 = 4 ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 += 2 ) {
T_2 V_58 = V_24 [ V_6 ] ;
T_2 V_27 = V_24 [ V_6 + 1 ] ;
if ( ! ( V_58 & V_59 ) )
continue;
if ( ( V_58 & V_60 ) != V_22 )
continue;
if ( F_19 ( V_32 ) == F_19 ( V_58 ) ) {
T_5 V_61 = ( V_27 & V_62 ) | V_36 ;
int V_63 = 0xFFF ;
V_34 -> V_5 = V_5 ;
V_34 -> V_44 = F_7 ( V_2 ,
V_5 ,
V_17 ) ;
if ( V_18 -> V_16 )
V_63 = 0xFFFFFF ;
V_34 -> V_45 = ( V_27 & V_64 ) | ( V_5 & V_63 ) ;
V_34 -> V_48 = ( ( V_27 & V_65 ) ? false : true ) ;
V_34 -> V_49 = false ;
V_34 -> V_50 = false ;
switch ( V_61 ) {
case 0 :
case 1 :
case 2 :
case 6 :
V_34 -> V_50 = true ;
case 3 :
case 5 :
case 7 :
V_34 -> V_49 = true ;
break;
}
if ( ! V_34 -> V_49 ) {
V_38 = true ;
continue;
}
F_6 ( L_5
L_6 ,
V_5 , V_32 , V_34 -> V_44 , V_34 -> V_45 ) ;
V_37 = true ;
break;
}
}
if ( V_37 ) {
T_3 V_66 = V_24 [ V_6 + 1 ] ;
if ( V_34 -> V_49 ) {
V_24 [ V_6 + 1 ] |= V_67 ;
}
if ( V_34 -> V_50 ) {
V_24 [ V_6 + 1 ] |= V_68 ;
} else {
F_6 ( L_7 ) ;
}
if ( V_24 [ V_6 + 1 ] != V_66 )
F_20 ( ( void V_54 * ) V_35 , V_24 , sizeof( V_24 ) ) ;
return 0 ;
} else {
F_6 ( L_8
L_9 ,
V_5 , F_15 ( V_2 ) -> V_28 , V_35 ) ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 += 2 )
F_6 ( L_10 ,
V_6 , V_24 [ V_6 ] , V_24 [ V_6 + 1 ] , V_32 ) ;
if ( ! V_22 ) {
V_22 = V_60 ;
goto V_52;
}
}
V_53:
if ( V_38 )
return - V_69 ;
return - V_70 ;
V_51:
F_6 ( L_11 ) ;
return - V_71 ;
}
static void F_21 ( struct V_1 * V_2 , T_2 V_72 , T_2 V_73 )
{
struct V_20 * V_21 ;
T_2 V_7 , V_8 ;
int V_10 ;
struct V_4 * V_18 ;
F_6 ( L_12 , V_72 , V_73 ) ;
V_21 = F_15 ( V_2 ) ;
V_7 = F_4 ( V_73 ) ;
V_8 = F_5 ( V_73 ) ;
V_10 = V_73 & 0xfff ;
if ( V_10 > V_2 -> V_9 . V_10 )
return;
V_18 = & V_2 -> V_9 . V_12 [ V_10 ] ;
V_18 -> V_16 = ( V_72 & V_74 ) ? 1 : 0 ;
V_18 -> V_14 = ( V_72 & V_75 ) ? 1 : 0 ;
V_18 -> V_7 = V_18 -> V_14 ? V_8 : V_7 ;
V_18 -> V_15 = V_72 >> 12 ;
V_18 -> V_13 = ( V_73 & V_76 ) ? 1 : 0 ;
V_18 -> V_57 = ( V_72 & V_77 ) ? 1 : 0 ;
V_18 -> V_56 = ( V_72 & V_78 ) ? 1 : 0 ;
V_18 -> V_79 = ( V_72 & V_80 ) ? 1 : 0 ;
V_18 -> V_81 = ( V_72 & V_82 ) ? 1 : 0 ;
V_18 -> V_83 = V_73 & ( V_84 | V_76 ) ;
V_18 -> V_85 = V_72 ;
F_22 ( V_2 , V_7 << V_86 ) ;
}
static T_2 F_23 ( struct V_1 * V_2 , T_2 V_10 )
{
struct V_4 * V_18 ;
if ( V_10 > V_2 -> V_9 . V_10 )
return 0 ;
V_18 = & V_2 -> V_9 . V_12 [ V_10 ] ;
return V_18 -> V_83 ;
}
static T_2 F_24 ( struct V_1 * V_2 , T_2 V_10 )
{
struct V_4 * V_18 ;
if ( V_10 > V_2 -> V_9 . V_10 )
return 0 ;
V_18 = & V_2 -> V_9 . V_12 [ V_10 ] ;
return V_18 -> V_85 ;
}
static void F_25 ( struct V_1 * V_2 , T_2 V_87 )
{
struct V_4 * V_18 ;
F_6 ( L_13 , V_87 ) ;
V_18 = F_3 ( V_2 , V_87 ) ;
if ( ! V_18 )
return;
F_6 ( L_14 , V_87 , V_18 -> V_7 ) ;
V_18 -> V_13 = false ;
F_22 ( V_2 , V_87 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
int V_6 ;
F_6 ( L_15 ) ;
for ( V_6 = 1 ; V_6 < V_2 -> V_9 . V_10 ; V_6 ++ )
V_2 -> V_9 . V_12 [ V_6 ] . V_13 = false ;
if ( V_2 -> V_9 . V_41 -> V_42 & V_88 ) {
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
bool V_16 )
{
T_2 V_92 = 0xFFFFFFFFFULL ;
F_6 ( L_17 , V_91 ) ;
if ( V_16 )
V_92 = 0xFFFFFF000ULL ;
F_31 ( V_2 , V_91 >> 12 , V_92 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_6 V_7 ,
T_2 * V_15 )
{
T_6 V_87 = V_7 << V_86 ;
struct V_4 * V_12 ;
T_2 V_93 = V_7 ;
T_6 V_39 = V_2 -> V_9 . V_40 ;
if ( V_2 -> V_9 . V_41 -> V_42 & ( V_94 | V_88 ) ) {
V_12 = F_3 ( V_2 , V_87 ) ;
if ( V_12 )
V_93 = V_12 -> V_15 ;
}
switch ( V_2 -> V_9 . V_41 -> V_42 & ( V_94 | V_88 ) ) {
case 0 :
* V_15 = V_95 | V_7 ;
break;
case V_88 :
* V_15 = V_96 | V_93 ;
break;
case V_94 :
* V_15 = V_97 | V_93 ;
break;
case V_94 | V_88 :
if ( ! V_12 )
goto V_98;
* V_15 = V_93 ;
break;
default:
F_33 () ;
break;
}
if ( V_2 -> V_9 . V_41 -> V_42 & V_43 )
* V_15 |= V_99 ;
return 0 ;
V_98:
if ( F_16 ( V_39 ) &&
F_16 ( V_7 == ( V_39 >> V_86 ) ) &&
! ( V_2 -> V_9 . V_41 -> V_42 & V_43 ) ) {
* V_15 = V_95 | V_7 ;
return 0 ;
}
return - V_71 ;
}
static bool F_34 ( struct V_1 * V_2 )
{
return ( F_15 ( V_2 ) -> V_100 [ 5 ] & 0x80 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_101 * V_102 = & V_2 -> V_9 . V_102 ;
V_102 -> V_103 = NULL ;
V_102 -> V_104 = F_29 ;
V_102 -> V_105 = F_21 ;
V_102 -> V_106 = F_23 ;
V_102 -> V_107 = F_24 ;
V_102 -> V_108 = F_25 ;
V_102 -> V_109 = F_26 ;
V_102 -> V_110 = F_14 ;
V_102 -> V_111 = F_1 ;
V_102 -> V_112 = F_30 ;
V_102 -> V_113 = F_32 ;
V_102 -> V_114 = F_7 ;
V_102 -> V_115 = F_34 ;
V_2 -> V_9 . V_116 |= V_117 ;
}
