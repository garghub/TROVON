static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) , 0x00310000 , 0x00000000 ) ;
}
static int
F_3 ( struct V_1 * V_2 , int V_3 )
{
const T_1 V_4 = 1 ;
const T_1 V_5 = V_4 ? 0x00100000 : 0x00200000 ;
const T_1 V_6 = V_4 ? 0x01000000 : 0x02000000 ;
T_1 V_7 , V_8 ;
V_8 = 1000 ;
do {
V_7 = F_4 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) ) ;
F_5 ( 1 ) ;
if ( ! V_8 -- ) {
F_6 ( L_1 , V_7 ) ;
return - V_9 ;
}
} while ( V_7 & 0x03010000 );
F_2 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) , 0x00300000 , V_5 ) ;
V_8 = 1000 ;
do {
V_7 = F_4 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) ) ;
F_5 ( 1 ) ;
if ( ! V_8 -- ) {
F_6 ( L_2 , V_7 ) ;
F_1 ( V_2 , V_3 ) ;
return - V_9 ;
}
} while ( ( V_7 & 0x03000000 ) != V_6 );
return 0 ;
}
static int
F_7 ( struct V_1 * V_2 , int V_3 , T_2 type , T_1 V_10 , T_2 * V_11 , T_2 V_12 )
{
T_1 V_7 , V_13 , V_8 , V_14 ;
T_1 V_15 [ 4 ] = {} ;
int V_16 , V_17 ;
F_8 ( L_3 , type , V_10 , V_12 ) ;
V_16 = F_3 ( V_2 , V_3 ) ;
if ( V_16 )
goto V_18;
V_13 = F_4 ( V_2 , 0x00e4e8 + ( V_3 * 0x50 ) ) ;
if ( ! ( V_13 & 0x10000000 ) ) {
F_8 ( L_4 ) ;
V_16 = - V_19 ;
goto V_18;
}
if ( ! ( type & 1 ) ) {
memcpy ( V_15 , V_11 , V_12 ) ;
for ( V_17 = 0 ; V_17 < 16 ; V_17 += 4 ) {
F_8 ( L_5 , V_15 [ V_17 / 4 ] ) ;
F_9 ( V_2 , 0x00e4c0 + ( V_3 * 0x50 ) + V_17 , V_15 [ V_17 / 4 ] ) ;
}
}
V_7 = F_4 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) ) ;
V_7 &= ~ 0x0001f0ff ;
V_7 |= type << 12 ;
V_7 |= V_12 - 1 ;
F_9 ( V_2 , 0x00e4e0 + ( V_3 * 0x50 ) , V_10 ) ;
V_16 = - V_20 ;
for ( V_14 = 0 ; V_14 < 32 ; V_14 ++ ) {
F_9 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) , 0x80000000 | V_7 ) ;
F_9 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) , 0x00000000 | V_7 ) ;
if ( V_14 )
F_5 ( 400 ) ;
F_9 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) , 0x00010000 | V_7 ) ;
V_8 = 1000 ;
do {
V_7 = F_4 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) ) ;
F_5 ( 1 ) ;
if ( ! V_8 -- ) {
F_6 ( L_6 , V_7 ) ;
goto V_18;
}
} while ( V_7 & 0x00010000 );
V_13 = F_2 ( V_2 , 0x00e4e8 + ( V_3 * 0x50 ) , 0 , 0 ) ;
if ( ! ( V_13 & 0x000f0f00 ) ) {
V_16 = 0 ;
break;
}
F_8 ( L_7 , V_14 , V_7 , V_13 ) ;
}
if ( type & 1 ) {
for ( V_17 = 0 ; V_17 < 16 ; V_17 += 4 ) {
V_15 [ V_17 / 4 ] = F_4 ( V_2 , 0x00e4d0 + ( V_3 * 0x50 ) + V_17 ) ;
F_8 ( L_8 , V_15 [ V_17 / 4 ] ) ;
}
memcpy ( V_11 , V_15 , V_12 ) ;
}
V_18:
F_1 ( V_2 , V_3 ) ;
return V_16 ;
}
T_2 *
F_10 ( struct V_1 * V_2 , struct V_21 * V_22 , T_2 * * V_23 )
{
struct V_24 V_25 ;
T_2 * V_26 ;
int V_17 ;
if ( F_11 ( V_2 , 'd' , & V_25 ) ) {
F_12 ( V_2 , L_9 ) ;
return NULL ;
}
if ( V_25 . V_27 != 1 ) {
F_12 ( V_2 , L_10 , V_25 . V_27 ) ;
return NULL ;
}
V_26 = F_13 ( V_2 , V_25 . V_11 [ 0 ] ) ;
if ( ! V_26 ) {
F_12 ( V_2 , L_11 ) ;
return NULL ;
}
switch ( V_26 [ 0 ] ) {
case 0x20 :
case 0x21 :
case 0x30 :
case 0x40 :
break;
default:
F_12 ( V_2 , L_12 , V_26 [ 0 ] ) ;
return NULL ;
}
for ( V_17 = 0 ; V_17 < V_26 [ 3 ] ; V_17 ++ ) {
* V_23 = F_13 ( V_2 , V_26 [ V_26 [ 1 ] + ( V_17 * V_26 [ 2 ] ) ] ) ;
if ( * V_23 && F_14 ( V_22 , F_15 ( ( * V_23 ) [ 0 ] ) ) )
return V_26 ;
}
F_12 ( V_2 , L_13 ) ;
return NULL ;
}
static void
F_16 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
T_2 V_30 [ 2 ] ;
F_17 ( V_2 , L_14 , V_29 -> V_31 , V_29 -> V_32 ) ;
V_29 -> V_33 -> V_34 ( V_2 , V_29 -> V_22 , V_29 -> V_35 , V_29 -> V_31 , V_29 -> V_32 ,
V_29 -> V_36 [ 2 ] & V_37 ) ;
V_30 [ 0 ] = V_29 -> V_32 / 27000 ;
V_30 [ 1 ] = V_29 -> V_31 ;
if ( V_29 -> V_36 [ 2 ] & V_37 )
V_30 [ 1 ] |= V_38 ;
F_7 ( V_2 , V_29 -> V_39 , 8 , V_40 , V_30 , 2 ) ;
}
static void
F_18 ( struct V_1 * V_2 , struct V_28 * V_29 , T_2 V_41 )
{
T_2 V_42 ;
F_17 ( V_2 , L_15 , V_41 ) ;
V_29 -> V_33 -> V_43 ( V_2 , V_29 -> V_22 , V_41 ) ;
F_7 ( V_2 , V_29 -> V_39 , 9 , V_44 , & V_42 , 1 ) ;
V_42 &= ~ V_45 ;
V_42 |= V_41 ;
F_7 ( V_2 , V_29 -> V_39 , 8 , V_44 , & V_42 , 1 ) ;
}
static int
F_19 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_29 -> V_31 ; V_17 ++ ) {
T_2 V_46 = ( V_29 -> V_13 [ 4 + ( V_17 >> 1 ) ] >> ( ( V_17 & 1 ) * 4 ) ) & 0xf ;
T_2 V_47 = ( V_46 & 0x0c ) >> 2 ;
T_2 V_48 = ( V_46 & 0x03 ) >> 0 ;
V_29 -> V_49 [ V_17 ] = ( V_47 << 3 ) | V_48 ;
if ( V_48 == V_50 )
V_29 -> V_49 [ V_17 ] |= V_51 ;
if ( ( V_47 << 3 ) == V_52 )
V_29 -> V_49 [ V_17 ] |= V_53 ;
F_17 ( V_2 , L_16 , V_17 , V_29 -> V_49 [ V_17 ] ) ;
V_29 -> V_33 -> V_54 ( V_2 , V_29 -> V_22 , V_17 , V_48 , V_47 ) ;
}
return F_7 ( V_2 , V_29 -> V_39 , 8 , V_55 , V_29 -> V_49 , 4 ) ;
}
static int
F_20 ( struct V_1 * V_2 , struct V_28 * V_29 , T_1 V_56 )
{
int V_16 ;
F_5 ( V_56 ) ;
V_16 = F_7 ( V_2 , V_29 -> V_39 , 9 , V_57 , V_29 -> V_13 , 6 ) ;
if ( V_16 )
return V_16 ;
F_17 ( V_2 , L_17 ,
V_29 -> V_13 [ 0 ] , V_29 -> V_13 [ 1 ] , V_29 -> V_13 [ 2 ] , V_29 -> V_13 [ 3 ] ,
V_29 -> V_13 [ 4 ] , V_29 -> V_13 [ 5 ] ) ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
bool V_58 = false , abort = false ;
int V_59 = V_29 -> V_49 [ 0 ] & V_60 ;
int V_61 = 0 , V_17 ;
F_18 ( V_2 , V_29 , V_62 ) ;
do {
if ( F_19 ( V_2 , V_29 ) ||
F_20 ( V_2 , V_29 , 100 ) )
break;
V_58 = true ;
for ( V_17 = 0 ; V_17 < V_29 -> V_31 ; V_17 ++ ) {
T_2 V_46 = ( V_29 -> V_13 [ V_17 >> 1 ] >> ( ( V_17 & 1 ) * 4 ) ) & 0xf ;
if ( ! ( V_46 & V_63 ) ) {
V_58 = false ;
if ( V_29 -> V_49 [ V_17 ] & V_51 )
abort = true ;
break;
}
}
if ( ( V_29 -> V_49 [ 0 ] & V_60 ) != V_59 ) {
V_59 = V_29 -> V_49 [ 0 ] & V_60 ;
V_61 = 0 ;
}
} while ( ! V_58 && ! abort && ++ V_61 < 5 );
return V_58 ? 0 : - 1 ;
}
static int
F_22 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
bool V_64 , V_58 = true ;
int V_61 = 0 , V_17 ;
F_18 ( V_2 , V_29 , V_65 ) ;
do {
if ( F_20 ( V_2 , V_29 , 400 ) )
break;
V_64 = ! ! ( V_29 -> V_13 [ 2 ] & V_66 ) ;
for ( V_17 = 0 ; V_17 < V_29 -> V_31 && V_64 ; V_17 ++ ) {
T_2 V_46 = ( V_29 -> V_13 [ V_17 >> 1 ] >> ( ( V_17 & 1 ) * 4 ) ) & 0xf ;
if ( ! ( V_46 & V_63 ) )
V_58 = false ;
if ( ! ( V_46 & V_67 ) ||
! ( V_46 & V_68 ) )
V_64 = false ;
}
if ( F_19 ( V_2 , V_29 ) )
break;
} while ( ! V_64 && V_58 && ++ V_61 <= 5 );
return V_64 ? 0 : - 1 ;
}
static void
F_23 ( struct V_1 * V_2 , struct V_28 * V_29 , bool V_69 )
{
T_3 V_70 = 0x0000 ;
T_2 * V_23 , * V_26 = F_10 ( V_2 , V_29 -> V_22 , & V_23 ) ;
if ( V_26 ) {
if ( V_26 [ 0 ] >= 0x20 && V_26 [ 0 ] <= 0x30 ) {
if ( V_69 ) V_70 = F_24 ( V_23 [ 12 ] ) ;
else V_70 = F_24 ( V_23 [ 14 ] ) ;
} else
if ( V_26 [ 0 ] == 0x40 ) {
if ( V_69 ) V_70 = F_24 ( V_23 [ 11 ] ) ;
else V_70 = F_24 ( V_23 [ 13 ] ) ;
}
}
F_25 ( V_2 , V_70 , V_29 -> V_22 , V_29 -> V_35 ) ;
}
static void
F_26 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
T_3 V_70 = 0x0000 ;
T_2 * V_23 , * V_26 = F_10 ( V_2 , V_29 -> V_22 , & V_23 ) ;
if ( V_26 ) {
if ( V_26 [ 0 ] >= 0x20 && V_26 [ 0 ] <= 0x30 )
V_70 = F_24 ( V_23 [ 6 ] ) ;
else
if ( V_26 [ 0 ] == 0x40 )
V_70 = F_24 ( V_23 [ 5 ] ) ;
}
F_25 ( V_2 , V_70 , V_29 -> V_22 , V_29 -> V_35 ) ;
}
static void
F_27 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
T_3 V_70 = 0x0000 ;
T_2 * V_23 , * V_26 = F_10 ( V_2 , V_29 -> V_22 , & V_23 ) ;
if ( V_26 ) {
if ( V_26 [ 0 ] >= 0x20 && V_26 [ 0 ] <= 0x30 )
V_70 = F_24 ( V_23 [ 8 ] ) ;
else
if ( V_26 [ 0 ] == 0x40 )
V_70 = F_24 ( V_23 [ 7 ] ) ;
}
F_25 ( V_2 , V_70 , V_29 -> V_22 , V_29 -> V_35 ) ;
}
bool
F_28 ( struct V_71 * V_72 , T_1 V_73 ,
struct V_74 * V_33 )
{
struct V_75 * V_76 = V_75 ( V_72 ) ;
struct V_77 * V_78 = V_77 ( V_72 -> V_35 ) ;
struct V_79 * V_80 =
F_29 ( V_76 ) ;
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_81 * V_39 ;
const T_1 V_82 [] = { 270000 , 162000 , 0 } ;
const T_1 * V_32 = V_82 ;
struct V_28 V_29 ;
V_39 = F_30 ( V_2 , V_76 -> V_22 -> V_83 ) ;
if ( ! V_39 )
return false ;
V_29 . V_33 = V_33 ;
V_29 . V_22 = V_76 -> V_22 ;
V_29 . V_35 = V_78 -> V_84 ;
V_29 . V_39 = V_39 -> V_85 ;
V_29 . V_36 = V_76 -> V_29 . V_36 ;
V_73 = ( V_73 / 8 ) * 10 ;
F_31 ( V_2 , 0 , V_80 -> V_86 , 0xff , false ) ;
F_23 ( V_2 , & V_29 , V_76 -> V_29 . V_36 [ 3 ] & 1 ) ;
F_26 ( V_2 , & V_29 ) ;
while ( * V_32 > V_76 -> V_29 . V_32 )
V_32 ++ ;
while ( V_32 [ 0 ] ) {
V_29 . V_31 = V_76 -> V_29 . V_31 ;
while ( ( V_29 . V_31 >> 1 ) * V_32 [ 0 ] > V_73 )
V_29 . V_31 >>= 1 ;
while ( ( V_32 [ 1 ] * V_29 . V_31 ) > V_73 )
V_32 ++ ;
V_29 . V_32 = V_32 [ 0 ] ;
F_16 ( V_2 , & V_29 ) ;
memset ( V_29 . V_13 , 0x00 , sizeof( V_29 . V_13 ) ) ;
if ( ! F_21 ( V_2 , & V_29 ) &&
! F_22 ( V_2 , & V_29 ) )
break;
V_32 ++ ;
}
F_18 ( V_2 , & V_29 , V_87 ) ;
F_27 ( V_2 , & V_29 ) ;
F_31 ( V_2 , 0 , V_80 -> V_86 , 0xff , true ) ;
return true ;
}
void
F_32 ( struct V_71 * V_72 , int V_88 , T_1 V_73 ,
struct V_74 * V_33 )
{
struct V_75 * V_76 = V_75 ( V_72 ) ;
struct V_81 * V_39 ;
T_2 V_89 ;
V_39 = F_30 ( V_72 -> V_2 , V_76 -> V_22 -> V_83 ) ;
if ( ! V_39 )
return;
if ( V_88 == V_90 )
V_89 = V_91 ;
else
V_89 = V_92 ;
F_33 ( V_39 , 8 , V_93 , & V_89 , 1 ) ;
if ( V_88 == V_90 )
F_28 ( V_72 , V_73 , V_33 ) ;
}
bool
F_34 ( struct V_71 * V_72 )
{
struct V_75 * V_76 = V_75 ( V_72 ) ;
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_81 * V_39 ;
T_2 * V_36 = V_76 -> V_29 . V_36 ;
int V_16 ;
V_39 = F_30 ( V_2 , V_76 -> V_22 -> V_83 ) ;
if ( ! V_39 )
return false ;
V_16 = F_7 ( V_2 , V_39 -> V_85 , 9 , V_94 , V_36 , 8 ) ;
if ( V_16 )
return false ;
V_76 -> V_29 . V_32 = 27000 * V_36 [ 1 ] ;
V_76 -> V_29 . V_31 = V_36 [ 2 ] & V_95 ;
F_17 ( V_2 , L_18 ,
V_76 -> V_29 . V_31 , V_76 -> V_29 . V_32 , V_36 [ 0 ] ) ;
F_17 ( V_2 , L_19 ,
V_76 -> V_22 -> V_96 . V_31 ,
V_76 -> V_22 -> V_96 . V_32 ) ;
if ( V_76 -> V_22 -> V_96 . V_31 < V_76 -> V_29 . V_31 )
V_76 -> V_29 . V_31 = V_76 -> V_22 -> V_96 . V_31 ;
if ( V_76 -> V_22 -> V_96 . V_32 < V_76 -> V_29 . V_32 )
V_76 -> V_29 . V_32 = V_76 -> V_22 -> V_96 . V_32 ;
F_17 ( V_2 , L_20 ,
V_76 -> V_29 . V_31 , V_76 -> V_29 . V_32 ) ;
return true ;
}
int
F_33 ( struct V_81 * V_39 , int V_97 , int V_10 ,
T_4 * V_11 , int V_98 )
{
return F_7 ( V_39 -> V_2 , V_39 -> V_85 , V_97 , V_10 , V_11 , V_98 ) ;
}
static int
F_35 ( struct V_99 * V_100 , struct V_101 * V_102 , int V_103 )
{
struct V_81 * V_39 = (struct V_81 * ) V_100 ;
struct V_101 * V_104 = V_102 ;
int V_16 , V_105 = V_103 ;
while ( V_105 -- ) {
T_2 V_106 = V_104 -> V_107 ;
T_2 * V_108 = V_104 -> V_109 ;
while ( V_106 ) {
T_2 V_110 = ( V_106 > 16 ) ? 16 : V_106 ;
T_2 V_97 ;
if ( V_104 -> V_111 & V_112 )
V_97 = V_113 ;
else
V_97 = V_114 ;
if ( V_105 || V_106 > 16 )
V_97 |= V_115 ;
V_16 = F_33 ( V_39 , V_97 , V_104 -> V_10 , V_108 , V_110 ) ;
if ( V_16 < 0 )
return V_16 ;
V_108 += V_110 ;
V_106 -= V_110 ;
}
V_104 ++ ;
}
return V_103 ;
}
static T_1
F_36 ( struct V_99 * V_100 )
{
return V_116 | V_117 ;
}
