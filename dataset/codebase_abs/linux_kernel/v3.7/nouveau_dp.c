T_1 *
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 * * V_5 )
{
struct V_6 * V_7 = V_6 ( V_2 ) ;
struct V_8 V_9 ;
T_1 * V_10 ;
int V_11 ;
if ( F_2 ( V_2 , 'd' , & V_9 ) ) {
F_3 ( V_7 , L_1 ) ;
return NULL ;
}
if ( V_9 . V_12 != 1 ) {
F_3 ( V_7 , L_2 , V_9 . V_12 ) ;
return NULL ;
}
V_10 = F_4 ( V_2 , V_9 . V_13 [ 0 ] ) ;
if ( ! V_10 ) {
F_3 ( V_7 , L_3 ) ;
return NULL ;
}
switch ( V_10 [ 0 ] ) {
case 0x20 :
case 0x21 :
case 0x30 :
case 0x40 :
break;
default:
F_3 ( V_7 , L_4 , V_10 [ 0 ] ) ;
return NULL ;
}
for ( V_11 = 0 ; V_11 < V_10 [ 3 ] ; V_11 ++ ) {
* V_5 = F_4 ( V_2 , V_10 [ V_10 [ 1 ] + ( V_11 * V_10 [ 2 ] ) ] ) ;
if ( * V_5 && F_5 ( V_4 , F_6 ( ( * V_5 ) [ 0 ] ) ) )
return V_10 ;
}
F_3 ( V_7 , L_5 ) ;
return NULL ;
}
static void
F_7 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_6 * V_7 = V_6 ( V_2 ) ;
T_1 V_16 [ 2 ] ;
F_8 ( V_7 , L_6 , V_15 -> V_17 , V_15 -> V_18 ) ;
V_15 -> V_19 -> V_20 ( V_2 , V_15 -> V_4 , V_15 -> V_21 , V_15 -> V_17 , V_15 -> V_18 ,
V_15 -> V_22 [ 2 ] & V_23 ) ;
V_16 [ 0 ] = V_15 -> V_18 / 27000 ;
V_16 [ 1 ] = V_15 -> V_17 ;
if ( V_15 -> V_22 [ 2 ] & V_23 )
V_16 [ 1 ] |= V_24 ;
F_9 ( V_15 -> V_25 , V_26 , V_16 , 2 ) ;
}
static void
F_10 ( struct V_1 * V_2 , struct V_14 * V_15 , T_1 V_27 )
{
struct V_6 * V_7 = V_6 ( V_2 ) ;
T_1 V_28 ;
F_8 ( V_7 , L_7 , V_27 ) ;
V_15 -> V_19 -> V_29 ( V_2 , V_15 -> V_4 , V_27 ) ;
F_11 ( V_15 -> V_25 , V_30 , & V_28 , 1 ) ;
V_28 &= ~ V_31 ;
V_28 |= V_27 ;
F_9 ( V_15 -> V_25 , V_30 , & V_28 , 1 ) ;
}
static int
F_12 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_6 * V_7 = V_6 ( V_2 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_15 -> V_17 ; V_11 ++ ) {
T_1 V_32 = ( V_15 -> V_33 [ 4 + ( V_11 >> 1 ) ] >> ( ( V_11 & 1 ) * 4 ) ) & 0xf ;
T_1 V_34 = ( V_32 & 0x0c ) >> 2 ;
T_1 V_35 = ( V_32 & 0x03 ) >> 0 ;
V_15 -> V_36 [ V_11 ] = ( V_34 << 3 ) | V_35 ;
if ( V_35 == V_37 )
V_15 -> V_36 [ V_11 ] |= V_38 ;
if ( ( V_34 << 3 ) == V_39 )
V_15 -> V_36 [ V_11 ] |= V_40 ;
F_8 ( V_7 , L_8 , V_11 , V_15 -> V_36 [ V_11 ] ) ;
V_15 -> V_19 -> V_41 ( V_2 , V_15 -> V_4 , V_11 , V_35 , V_34 ) ;
}
return F_9 ( V_15 -> V_25 , V_42 , V_15 -> V_36 , 4 ) ;
}
static int
F_13 ( struct V_1 * V_2 , struct V_14 * V_15 , T_2 V_43 )
{
struct V_6 * V_7 = V_6 ( V_2 ) ;
int V_44 ;
F_14 ( V_43 ) ;
V_44 = F_11 ( V_15 -> V_25 , V_45 , V_15 -> V_33 , 6 ) ;
if ( V_44 )
return V_44 ;
F_8 ( V_7 , L_9 , 6 , V_15 -> V_33 ) ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
bool V_46 = false , abort = false ;
int V_47 = V_15 -> V_36 [ 0 ] & V_48 ;
int V_49 = 0 , V_11 ;
F_10 ( V_2 , V_15 , V_50 ) ;
do {
if ( F_12 ( V_2 , V_15 ) ||
F_13 ( V_2 , V_15 , 100 ) )
break;
V_46 = true ;
for ( V_11 = 0 ; V_11 < V_15 -> V_17 ; V_11 ++ ) {
T_1 V_32 = ( V_15 -> V_33 [ V_11 >> 1 ] >> ( ( V_11 & 1 ) * 4 ) ) & 0xf ;
if ( ! ( V_32 & V_51 ) ) {
V_46 = false ;
if ( V_15 -> V_36 [ V_11 ] & V_38 )
abort = true ;
break;
}
}
if ( ( V_15 -> V_36 [ 0 ] & V_48 ) != V_47 ) {
V_47 = V_15 -> V_36 [ 0 ] & V_48 ;
V_49 = 0 ;
}
} while ( ! V_46 && ! abort && ++ V_49 < 5 );
return V_46 ? 0 : - 1 ;
}
static int
F_16 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
bool V_52 , V_46 = true ;
int V_49 = 0 , V_11 ;
F_10 ( V_2 , V_15 , V_53 ) ;
do {
if ( F_13 ( V_2 , V_15 , 400 ) )
break;
V_52 = ! ! ( V_15 -> V_33 [ 2 ] & V_54 ) ;
for ( V_11 = 0 ; V_11 < V_15 -> V_17 && V_52 ; V_11 ++ ) {
T_1 V_32 = ( V_15 -> V_33 [ V_11 >> 1 ] >> ( ( V_11 & 1 ) * 4 ) ) & 0xf ;
if ( ! ( V_32 & V_51 ) )
V_46 = false ;
if ( ! ( V_32 & V_55 ) ||
! ( V_32 & V_56 ) )
V_52 = false ;
}
if ( F_12 ( V_2 , V_15 ) )
break;
} while ( ! V_52 && V_46 && ++ V_49 <= 5 );
return V_52 ? 0 : - 1 ;
}
static void
F_17 ( struct V_1 * V_2 , struct V_14 * V_15 , bool V_57 )
{
T_3 V_58 = 0x0000 ;
T_1 * V_5 , * V_10 = F_1 ( V_2 , V_15 -> V_4 , & V_5 ) ;
if ( V_10 ) {
if ( V_10 [ 0 ] >= 0x20 && V_10 [ 0 ] <= 0x30 ) {
if ( V_57 ) V_58 = F_18 ( V_5 [ 12 ] ) ;
else V_58 = F_18 ( V_5 [ 14 ] ) ;
} else
if ( V_10 [ 0 ] == 0x40 ) {
if ( V_57 ) V_58 = F_18 ( V_5 [ 11 ] ) ;
else V_58 = F_18 ( V_5 [ 13 ] ) ;
}
}
F_19 ( V_2 , V_58 , V_15 -> V_4 , V_15 -> V_21 ) ;
}
static void
F_20 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
T_3 V_58 = 0x0000 ;
T_1 * V_5 , * V_10 = F_1 ( V_2 , V_15 -> V_4 , & V_5 ) ;
if ( V_10 ) {
if ( V_10 [ 0 ] >= 0x20 && V_10 [ 0 ] <= 0x30 )
V_58 = F_18 ( V_5 [ 6 ] ) ;
else
if ( V_10 [ 0 ] == 0x40 )
V_58 = F_18 ( V_5 [ 5 ] ) ;
}
F_19 ( V_2 , V_58 , V_15 -> V_4 , V_15 -> V_21 ) ;
}
static void
F_21 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
T_3 V_58 = 0x0000 ;
T_1 * V_5 , * V_10 = F_1 ( V_2 , V_15 -> V_4 , & V_5 ) ;
if ( V_10 ) {
if ( V_10 [ 0 ] >= 0x20 && V_10 [ 0 ] <= 0x30 )
V_58 = F_18 ( V_5 [ 8 ] ) ;
else
if ( V_10 [ 0 ] == 0x40 )
V_58 = F_18 ( V_5 [ 7 ] ) ;
}
F_19 ( V_2 , V_58 , V_15 -> V_4 , V_15 -> V_21 ) ;
}
static bool
F_22 ( struct V_59 * V_60 , T_2 V_61 ,
struct V_62 * V_19 )
{
struct V_63 * V_64 = V_63 ( V_60 ) ;
struct V_65 * V_66 = V_65 ( V_60 -> V_21 ) ;
struct V_67 * V_68 =
F_23 ( V_64 ) ;
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_6 * V_7 = V_6 ( V_2 ) ;
struct V_69 * V_70 = V_69 ( V_7 -> V_71 ) ;
struct V_72 * V_73 = V_72 ( V_7 -> V_71 ) ;
const T_2 V_74 [] = { 270000 , 162000 , 0 } ;
const T_2 * V_18 = V_74 ;
struct V_14 V_15 ;
V_15 . V_25 = V_70 -> V_75 ( V_70 , V_64 -> V_4 -> V_76 ) ;
if ( ! V_15 . V_25 )
return false ;
V_15 . V_19 = V_19 ;
V_15 . V_4 = V_64 -> V_4 ;
V_15 . V_21 = V_66 -> V_77 ;
V_15 . V_22 = V_64 -> V_15 . V_22 ;
V_61 = ( V_61 / 8 ) * 10 ;
V_73 -> V_78 ( V_73 , 0 , V_68 -> V_79 , 0xff , false ) ;
F_17 ( V_2 , & V_15 , V_64 -> V_15 . V_22 [ 3 ] & 1 ) ;
F_20 ( V_2 , & V_15 ) ;
while ( * V_18 > V_64 -> V_15 . V_18 )
V_18 ++ ;
while ( V_18 [ 0 ] ) {
V_15 . V_17 = V_64 -> V_15 . V_17 ;
while ( ( V_15 . V_17 >> 1 ) * V_18 [ 0 ] > V_61 )
V_15 . V_17 >>= 1 ;
while ( ( V_18 [ 1 ] * V_15 . V_17 ) > V_61 )
V_18 ++ ;
V_15 . V_18 = V_18 [ 0 ] ;
F_7 ( V_2 , & V_15 ) ;
memset ( V_15 . V_33 , 0x00 , sizeof( V_15 . V_33 ) ) ;
if ( ! F_15 ( V_2 , & V_15 ) &&
! F_16 ( V_2 , & V_15 ) )
break;
V_18 ++ ;
}
F_10 ( V_2 , & V_15 , V_80 ) ;
F_21 ( V_2 , & V_15 ) ;
V_73 -> V_78 ( V_73 , 0 , V_68 -> V_79 , 0xff , true ) ;
return true ;
}
void
F_24 ( struct V_59 * V_60 , int V_81 , T_2 V_61 ,
struct V_62 * V_19 )
{
struct V_63 * V_64 = V_63 ( V_60 ) ;
struct V_6 * V_7 = V_6 ( V_60 -> V_2 ) ;
struct V_69 * V_70 = V_69 ( V_7 -> V_71 ) ;
struct V_82 * V_25 ;
T_1 V_83 ;
V_25 = V_70 -> V_75 ( V_70 , V_64 -> V_4 -> V_76 ) ;
if ( ! V_25 )
return;
if ( V_81 == V_84 )
V_83 = V_85 ;
else
V_83 = V_86 ;
F_9 ( V_25 , V_87 , & V_83 , 1 ) ;
if ( V_81 == V_84 )
F_22 ( V_60 , V_61 , V_19 ) ;
}
static void
F_25 ( struct V_1 * V_2 , struct V_82 * V_25 ,
T_1 * V_22 )
{
struct V_6 * V_7 = V_6 ( V_2 ) ;
T_1 V_88 [ 3 ] ;
if ( ! ( V_22 [ V_89 ] & V_90 ) )
return;
if ( ! F_11 ( V_25 , V_91 , V_88 , 3 ) )
F_8 ( V_7 , L_10 ,
V_88 [ 0 ] , V_88 [ 1 ] , V_88 [ 2 ] ) ;
if ( ! F_11 ( V_25 , V_92 , V_88 , 3 ) )
F_8 ( V_7 , L_11 ,
V_88 [ 0 ] , V_88 [ 1 ] , V_88 [ 2 ] ) ;
}
bool
F_26 ( struct V_59 * V_60 )
{
struct V_63 * V_64 = V_63 ( V_60 ) ;
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_6 * V_7 = V_6 ( V_2 ) ;
struct V_69 * V_70 = V_69 ( V_7 -> V_71 ) ;
struct V_82 * V_25 ;
T_1 * V_22 = V_64 -> V_15 . V_22 ;
int V_44 ;
V_25 = V_70 -> V_75 ( V_70 , V_64 -> V_4 -> V_76 ) ;
if ( ! V_25 )
return false ;
V_44 = F_11 ( V_25 , V_93 , V_22 , 8 ) ;
if ( V_44 )
return false ;
V_64 -> V_15 . V_18 = 27000 * V_22 [ 1 ] ;
V_64 -> V_15 . V_17 = V_22 [ 2 ] & V_94 ;
F_8 ( V_7 , L_12 ,
V_64 -> V_15 . V_17 , V_64 -> V_15 . V_18 , V_22 [ 0 ] ) ;
F_8 ( V_7 , L_13 ,
V_64 -> V_4 -> V_95 . V_17 ,
V_64 -> V_4 -> V_95 . V_18 ) ;
if ( V_64 -> V_4 -> V_95 . V_17 < V_64 -> V_15 . V_17 )
V_64 -> V_15 . V_17 = V_64 -> V_4 -> V_95 . V_17 ;
if ( V_64 -> V_4 -> V_95 . V_18 < V_64 -> V_15 . V_18 )
V_64 -> V_15 . V_18 = V_64 -> V_4 -> V_95 . V_18 ;
F_8 ( V_7 , L_14 ,
V_64 -> V_15 . V_17 , V_64 -> V_15 . V_18 ) ;
F_25 ( V_2 , V_25 , V_22 ) ;
return true ;
}
