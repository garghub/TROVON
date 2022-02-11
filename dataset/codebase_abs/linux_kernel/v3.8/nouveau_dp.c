static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_5 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const T_1 V_9 = F_2 ( V_8 -> V_9 ) - 1 , V_10 = ! ( V_8 -> V_11 . V_10 & 1 ) ;
const T_1 V_12 = ( V_4 -> V_13 << 3 ) | ( V_10 << 2 ) | V_9 ;
T_2 V_14 [ 2 ] ;
T_1 V_15 ;
F_3 ( V_6 , L_1 , V_4 -> V_16 , V_4 -> V_17 ) ;
V_15 = ( ( V_4 -> V_17 / 27000 ) << 8 ) | V_4 -> V_16 ;
if ( V_4 -> V_18 [ 2 ] & V_19 )
V_15 |= V_20 ;
F_4 ( V_4 -> V_21 , V_22 + V_12 , V_15 ) ;
V_14 [ 0 ] = V_4 -> V_17 / 27000 ;
V_14 [ 1 ] = V_4 -> V_16 ;
if ( V_4 -> V_18 [ 2 ] & V_19 )
V_14 [ 1 ] |= V_23 ;
F_5 ( V_4 -> V_24 , V_25 , V_14 , 2 ) ;
}
static void
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 , T_2 V_26 )
{
struct V_5 * V_6 = V_5 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const T_1 V_9 = F_2 ( V_8 -> V_9 ) - 1 , V_10 = ! ( V_8 -> V_11 . V_10 & 1 ) ;
const T_1 V_12 = ( V_4 -> V_13 << 3 ) | ( V_10 << 2 ) | V_9 ;
T_2 V_27 ;
F_3 ( V_6 , L_2 , V_26 ) ;
F_4 ( V_4 -> V_21 , V_28 + V_12 , V_26 ) ;
F_7 ( V_4 -> V_24 , V_29 , & V_27 , 1 ) ;
V_27 &= ~ V_30 ;
V_27 |= V_26 ;
F_5 ( V_4 -> V_24 , V_29 , & V_27 , 1 ) ;
}
static int
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_5 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const T_1 V_9 = F_2 ( V_8 -> V_9 ) - 1 , V_10 = ! ( V_8 -> V_11 . V_10 & 1 ) ;
const T_1 V_12 = ( V_4 -> V_13 << 3 ) | ( V_10 << 2 ) | V_9 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_4 -> V_16 ; V_31 ++ ) {
T_2 V_32 = ( V_4 -> V_33 [ 4 + ( V_31 >> 1 ) ] >> ( ( V_31 & 1 ) * 4 ) ) & 0xf ;
T_2 V_34 = ( V_32 & 0x0c ) >> 2 ;
T_2 V_35 = ( V_32 & 0x03 ) >> 0 ;
V_4 -> V_36 [ V_31 ] = ( V_34 << 3 ) | V_35 ;
if ( V_35 == V_37 )
V_4 -> V_36 [ V_31 ] |= V_38 ;
if ( ( V_34 << 3 ) == V_39 )
V_4 -> V_36 [ V_31 ] |= V_40 ;
F_3 ( V_6 , L_3 , V_31 , V_4 -> V_36 [ V_31 ] ) ;
F_4 ( V_4 -> V_21 , F_9 ( V_31 ) + V_12 , ( V_35 << 8 ) | V_34 ) ;
}
return F_5 ( V_4 -> V_24 , V_41 , V_4 -> V_36 , 4 ) ;
}
static int
F_10 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_42 )
{
struct V_5 * V_6 = V_5 ( V_2 ) ;
int V_43 ;
F_11 ( V_42 ) ;
V_43 = F_7 ( V_4 -> V_24 , V_44 , V_4 -> V_33 , 6 ) ;
if ( V_43 )
return V_43 ;
F_3 ( V_6 , L_4 , 6 , V_4 -> V_33 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
bool V_45 = false , abort = false ;
int V_46 = V_4 -> V_36 [ 0 ] & V_47 ;
int V_48 = 0 , V_31 ;
F_6 ( V_2 , V_4 , V_49 ) ;
do {
if ( F_8 ( V_2 , V_4 ) ||
F_10 ( V_2 , V_4 , 100 ) )
break;
V_45 = true ;
for ( V_31 = 0 ; V_31 < V_4 -> V_16 ; V_31 ++ ) {
T_2 V_32 = ( V_4 -> V_33 [ V_31 >> 1 ] >> ( ( V_31 & 1 ) * 4 ) ) & 0xf ;
if ( ! ( V_32 & V_50 ) ) {
V_45 = false ;
if ( V_4 -> V_36 [ V_31 ] & V_38 )
abort = true ;
break;
}
}
if ( ( V_4 -> V_36 [ 0 ] & V_47 ) != V_46 ) {
V_46 = V_4 -> V_36 [ 0 ] & V_47 ;
V_48 = 0 ;
}
} while ( ! V_45 && ! abort && ++ V_48 < 5 );
return V_45 ? 0 : - 1 ;
}
static int
F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
bool V_51 , V_45 = true ;
int V_48 = 0 , V_31 ;
F_6 ( V_2 , V_4 , V_52 ) ;
do {
if ( F_10 ( V_2 , V_4 , 400 ) )
break;
V_51 = ! ! ( V_4 -> V_33 [ 2 ] & V_53 ) ;
for ( V_31 = 0 ; V_31 < V_4 -> V_16 && V_51 ; V_31 ++ ) {
T_2 V_32 = ( V_4 -> V_33 [ V_31 >> 1 ] >> ( ( V_31 & 1 ) * 4 ) ) & 0xf ;
if ( ! ( V_32 & V_50 ) )
V_45 = false ;
if ( ! ( V_32 & V_54 ) ||
! ( V_32 & V_55 ) )
V_51 = false ;
}
if ( F_8 ( V_2 , V_4 ) )
break;
} while ( ! V_51 && V_45 && ++ V_48 <= 5 );
return V_51 ? 0 : - 1 ;
}
static void
F_14 ( struct V_1 * V_2 , struct V_3 * V_4 , bool V_56 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
const T_1 V_9 = F_2 ( V_8 -> V_9 ) - 1 , V_10 = ! ( V_8 -> V_11 . V_10 & 1 ) ;
const T_1 V_12 = ( V_4 -> V_13 << 3 ) | ( V_10 << 2 ) | V_9 ;
F_4 ( V_4 -> V_21 , V_28 + V_12 , ( V_56 ?
V_57 :
V_58 ) |
V_59 ) ;
}
static void
F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
const T_1 V_9 = F_2 ( V_8 -> V_9 ) - 1 , V_10 = ! ( V_8 -> V_11 . V_10 & 1 ) ;
const T_1 V_12 = ( V_4 -> V_13 << 3 ) | ( V_10 << 2 ) | V_9 ;
F_4 ( V_4 -> V_21 , V_28 + V_12 ,
V_60 ) ;
}
static bool
F_16 ( struct V_61 * V_62 , T_1 V_63 ,
struct V_64 * V_21 )
{
struct V_65 * V_66 = V_65 ( V_62 ) ;
struct V_67 * V_68 = V_67 ( V_62 -> V_13 ) ;
struct V_69 * V_70 =
F_17 ( V_66 ) ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_5 * V_6 = V_5 ( V_2 ) ;
struct V_71 * V_72 = V_71 ( V_6 -> V_73 ) ;
struct V_74 * V_75 = V_74 ( V_6 -> V_73 ) ;
const T_1 V_76 [] = { 270000 , 162000 , 0 } ;
const T_1 * V_17 = V_76 ;
struct V_3 V_4 ;
V_4 . V_24 = V_72 -> V_77 ( V_72 , V_66 -> V_8 -> V_78 ) ;
if ( ! V_4 . V_24 )
return false ;
V_4 . V_21 = V_21 ;
V_4 . V_8 = V_66 -> V_8 ;
V_4 . V_13 = V_68 -> V_79 ;
V_4 . V_18 = V_66 -> V_4 . V_18 ;
V_63 = ( V_63 / 8 ) * 10 ;
V_75 -> V_80 ( V_75 , 0 , V_70 -> V_81 , 0xff , false ) ;
F_14 ( V_2 , & V_4 , V_66 -> V_4 . V_18 [ 3 ] & 1 ) ;
while ( * V_17 > V_66 -> V_4 . V_17 )
V_17 ++ ;
while ( V_17 [ 0 ] ) {
V_4 . V_16 = V_66 -> V_4 . V_16 ;
while ( ( V_4 . V_16 >> 1 ) * V_17 [ 0 ] > V_63 )
V_4 . V_16 >>= 1 ;
while ( ( V_17 [ 1 ] * V_4 . V_16 ) > V_63 )
V_17 ++ ;
V_4 . V_17 = V_17 [ 0 ] ;
F_1 ( V_2 , & V_4 ) ;
memset ( V_4 . V_33 , 0x00 , sizeof( V_4 . V_33 ) ) ;
if ( ! F_12 ( V_2 , & V_4 ) &&
! F_13 ( V_2 , & V_4 ) )
break;
V_17 ++ ;
}
F_6 ( V_2 , & V_4 , V_82 ) ;
F_15 ( V_2 , & V_4 ) ;
V_75 -> V_80 ( V_75 , 0 , V_70 -> V_81 , 0xff , true ) ;
return true ;
}
void
F_18 ( struct V_61 * V_62 , int V_83 , T_1 V_63 ,
struct V_64 * V_21 )
{
struct V_65 * V_66 = V_65 ( V_62 ) ;
struct V_5 * V_6 = V_5 ( V_62 -> V_2 ) ;
struct V_71 * V_72 = V_71 ( V_6 -> V_73 ) ;
struct V_84 * V_24 ;
T_2 V_85 ;
V_24 = V_72 -> V_77 ( V_72 , V_66 -> V_8 -> V_78 ) ;
if ( ! V_24 )
return;
if ( V_83 == V_86 )
V_85 = V_87 ;
else
V_85 = V_88 ;
F_5 ( V_24 , V_89 , & V_85 , 1 ) ;
if ( V_83 == V_86 )
F_16 ( V_62 , V_63 , V_21 ) ;
}
static void
F_19 ( struct V_1 * V_2 , struct V_84 * V_24 ,
T_2 * V_18 )
{
struct V_5 * V_6 = V_5 ( V_2 ) ;
T_2 V_90 [ 3 ] ;
if ( ! ( V_18 [ V_91 ] & V_92 ) )
return;
if ( ! F_7 ( V_24 , V_93 , V_90 , 3 ) )
F_3 ( V_6 , L_5 ,
V_90 [ 0 ] , V_90 [ 1 ] , V_90 [ 2 ] ) ;
if ( ! F_7 ( V_24 , V_94 , V_90 , 3 ) )
F_3 ( V_6 , L_6 ,
V_90 [ 0 ] , V_90 [ 1 ] , V_90 [ 2 ] ) ;
}
bool
F_20 ( struct V_61 * V_62 )
{
struct V_65 * V_66 = V_65 ( V_62 ) ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_5 * V_6 = V_5 ( V_2 ) ;
struct V_71 * V_72 = V_71 ( V_6 -> V_73 ) ;
struct V_84 * V_24 ;
T_2 * V_18 = V_66 -> V_4 . V_18 ;
int V_43 ;
V_24 = V_72 -> V_77 ( V_72 , V_66 -> V_8 -> V_78 ) ;
if ( ! V_24 )
return false ;
V_43 = F_7 ( V_24 , V_95 , V_18 , 8 ) ;
if ( V_43 )
return false ;
V_66 -> V_4 . V_17 = 27000 * V_18 [ 1 ] ;
V_66 -> V_4 . V_16 = V_18 [ 2 ] & V_96 ;
F_3 ( V_6 , L_7 ,
V_66 -> V_4 . V_16 , V_66 -> V_4 . V_17 , V_18 [ 0 ] ) ;
F_3 ( V_6 , L_8 ,
V_66 -> V_8 -> V_97 . V_16 ,
V_66 -> V_8 -> V_97 . V_17 ) ;
if ( V_66 -> V_8 -> V_97 . V_16 < V_66 -> V_4 . V_16 )
V_66 -> V_4 . V_16 = V_66 -> V_8 -> V_97 . V_16 ;
if ( V_66 -> V_8 -> V_97 . V_17 < V_66 -> V_4 . V_17 )
V_66 -> V_4 . V_17 = V_66 -> V_8 -> V_97 . V_17 ;
F_3 ( V_6 , L_9 ,
V_66 -> V_4 . V_16 , V_66 -> V_4 . V_17 ) ;
F_19 ( V_2 , V_24 , V_18 ) ;
return true ;
}
