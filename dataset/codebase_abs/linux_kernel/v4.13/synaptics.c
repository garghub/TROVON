static int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
T_1 V_3 [ 1 ] ;
int error ;
error = F_2 ( V_1 , V_2 ) ;
if ( error )
return error ;
V_3 [ 0 ] = V_4 ;
error = F_3 ( & V_1 -> V_5 , V_3 , V_6 ) ;
if ( error )
return error ;
return 0 ;
}
int F_4 ( struct V_1 * V_1 , bool V_7 )
{
struct V_5 * V_5 = & V_1 -> V_5 ;
T_1 V_3 [ 4 ] ;
V_3 [ 0 ] = 0 ;
F_3 ( V_5 , V_3 , V_8 ) ;
F_3 ( V_5 , V_3 , V_8 ) ;
F_3 ( V_5 , V_3 , V_8 ) ;
F_3 ( V_5 , V_3 , V_8 ) ;
F_3 ( V_5 , V_3 , V_9 ) ;
if ( V_3 [ 1 ] != 0x47 )
return - V_10 ;
if ( V_7 ) {
V_1 -> V_11 = L_1 ;
V_1 -> V_12 = L_2 ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0 ) ;
}
static int F_6 ( struct V_1 * V_1 , T_1 V_13 , T_1 * V_3 )
{
int error ;
error = F_2 ( V_1 , V_13 ) ;
if ( error )
return error ;
error = F_3 ( & V_1 -> V_5 , V_3 , V_9 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , T_1 V_14 , T_2 * V_15 )
{
int error ;
union {
T_3 V_16 ;
char V_17 [ 4 ] ;
} V_18 = { 0 } ;
error = F_6 ( V_1 , V_14 , V_18 . V_17 + 1 ) ;
if ( error )
return error ;
* V_15 = F_8 ( V_18 . V_16 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 ,
struct V_19 * V_20 )
{
int error ;
error = F_7 ( V_1 , V_21 , & V_20 -> V_22 ) ;
if ( error )
return error ;
return F_10 ( V_20 -> V_22 ) ? 0 : - V_23 ;
}
static int F_11 ( struct V_1 * V_1 ,
struct V_19 * V_20 )
{
return F_7 ( V_1 , V_24 , & V_20 -> V_25 ) ;
}
static int F_12 ( struct V_1 * V_1 ,
struct V_19 * V_20 )
{
return F_7 ( V_1 , V_26 ,
& V_20 -> V_27 ) ;
}
static int F_13 ( struct V_1 * V_1 ,
struct V_19 * V_20 )
{
T_1 V_28 [ 3 ] ;
int error ;
if ( F_14 ( V_20 -> V_22 ) < 0x705 )
return 0 ;
error = F_6 ( V_1 , V_29 , V_28 ) ;
if ( error )
return error ;
V_20 -> V_30 = ( ( V_28 [ 0 ] & 0xfc ) << 6 ) | V_28 [ 1 ] ;
if ( F_15 ( V_28 [ 0 ] ) )
return F_7 ( V_1 , V_31 ,
& V_20 -> V_32 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_1 ,
struct V_19 * V_20 )
{
int error ;
error = F_7 ( V_1 , V_33 ,
& V_20 -> V_34 ) ;
if ( error )
return error ;
V_20 -> V_35 = V_20 -> V_36 = 0 ;
if ( F_14 ( V_20 -> V_22 ) < 0x705 &&
F_17 ( V_20 -> V_34 ) != 0x47 ) {
return - V_23 ;
}
if ( ! F_18 ( V_20 -> V_34 ) )
V_20 -> V_34 = 0 ;
if ( F_19 ( V_20 -> V_34 ) >= 1 ) {
error = F_7 ( V_1 , V_37 ,
& V_20 -> V_35 ) ;
if ( error ) {
F_20 ( V_1 ,
L_3 ) ;
} else {
if ( F_21 ( V_20 -> V_35 ) > 8 )
V_20 -> V_35 &= ~ V_38 ;
}
}
if ( F_19 ( V_20 -> V_34 ) >= 4 ) {
error = F_7 ( V_1 , V_39 ,
& V_20 -> V_36 ) ;
if ( error )
F_20 ( V_1 ,
L_4 ) ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_1 ,
struct V_19 * V_20 )
{
T_1 V_18 [ 3 ] ;
int error ;
if ( F_23 ( V_20 -> V_22 ) < 4 )
return 0 ;
error = F_6 ( V_1 , V_40 , V_18 ) ;
if ( ! error ) {
if ( V_18 [ 0 ] != 0 && ( V_18 [ 1 ] & 0x80 ) && V_18 [ 2 ] != 0 ) {
V_20 -> V_41 = V_18 [ 0 ] ;
V_20 -> V_42 = V_18 [ 2 ] ;
}
}
if ( F_19 ( V_20 -> V_34 ) >= 5 &&
F_24 ( V_20 -> V_36 ) ) {
error = F_6 ( V_1 ,
V_43 , V_18 ) ;
if ( error ) {
F_20 ( V_1 ,
L_5 ) ;
} else {
V_20 -> V_44 = ( V_18 [ 0 ] << 5 ) | ( ( V_18 [ 1 ] & 0x0f ) << 1 ) ;
V_20 -> V_45 = ( V_18 [ 2 ] << 5 ) | ( ( V_18 [ 1 ] & 0xf0 ) >> 3 ) ;
F_25 ( V_1 ,
L_6 ,
V_20 -> V_44 , V_20 -> V_45 ) ;
}
}
if ( F_26 ( V_20 -> V_36 ) &&
( F_19 ( V_20 -> V_34 ) >= 7 ||
F_14 ( V_20 -> V_22 ) == 0x801 ) ) {
error = F_6 ( V_1 ,
V_46 , V_18 ) ;
if ( error ) {
F_20 ( V_1 ,
L_7 ) ;
} else {
V_20 -> V_47 = ( V_18 [ 0 ] << 5 ) | ( ( V_18 [ 1 ] & 0x0f ) << 1 ) ;
V_20 -> V_48 = ( V_18 [ 2 ] << 5 ) | ( ( V_18 [ 1 ] & 0xf0 ) >> 3 ) ;
F_25 ( V_1 ,
L_8 ,
V_20 -> V_47 , V_20 -> V_48 ) ;
}
}
return 0 ;
}
static int F_27 ( struct V_1 * V_1 ,
struct V_19 * V_20 )
{
int error ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
error = F_9 ( V_1 , V_20 ) ;
if ( error )
return error ;
error = F_11 ( V_1 , V_20 ) ;
if ( error )
return error ;
error = F_12 ( V_1 , V_20 ) ;
if ( error )
return error ;
error = F_13 ( V_1 , V_20 ) ;
if ( error )
return error ;
error = F_16 ( V_1 , V_20 ) ;
if ( error )
return error ;
error = F_22 ( V_1 , V_20 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_28 ( int V_49 )
{
return V_50 + V_51 - V_49 ;
}
static void F_29 ( struct V_1 * V_1 ,
struct V_19 * V_20 )
{
int V_52 ;
for ( V_52 = 0 ; V_53 [ V_52 ] . V_54 ; V_52 ++ ) {
if ( ! F_30 ( V_1 ,
V_53 [ V_52 ] . V_54 ) )
continue;
if ( V_53 [ V_52 ] . V_30 . V_55 != V_56 &&
V_20 -> V_30 < V_53 [ V_52 ] . V_30 . V_55 )
continue;
if ( V_53 [ V_52 ] . V_30 . V_57 != V_56 &&
V_20 -> V_30 > V_53 [ V_52 ] . V_30 . V_57 )
continue;
V_20 -> V_47 = V_53 [ V_52 ] . V_47 ;
V_20 -> V_44 = V_53 [ V_52 ] . V_44 ;
V_20 -> V_48 = V_53 [ V_52 ] . V_48 ;
V_20 -> V_45 = V_53 [ V_52 ] . V_45 ;
F_25 ( V_1 ,
L_9 ,
V_20 -> V_47 , V_20 -> V_44 ,
V_20 -> V_48 , V_20 -> V_45 ) ;
break;
}
}
static bool F_31 ( struct V_58 * V_59 )
{
return ( F_32 ( V_59 -> V_20 . V_36 ) ||
F_33 ( V_59 -> V_20 . V_36 ) ) ;
}
static int F_34 ( struct V_1 * V_1 )
{
static T_1 V_3 = 0xc8 ;
int error ;
error = F_2 ( V_1 , V_24 ) ;
if ( error )
return error ;
error = F_3 ( & V_1 -> V_5 , & V_3 , V_6 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 )
{
struct V_58 * V_59 = V_1 -> V_60 ;
int error ;
V_59 -> V_2 = 0 ;
if ( V_59 -> V_61 )
V_59 -> V_2 |= V_62 ;
if ( V_59 -> V_63 )
V_59 -> V_2 |= V_64 ;
if ( V_1 -> V_65 >= 80 )
V_59 -> V_2 |= V_66 ;
if ( F_18 ( V_59 -> V_20 . V_34 ) )
V_59 -> V_2 |= V_67 ;
error = F_1 ( V_1 , V_59 -> V_2 ) ;
if ( error )
return error ;
if ( V_59 -> V_61 && F_31 ( V_59 ) ) {
error = F_34 ( V_1 ) ;
if ( error ) {
F_36 ( V_1 ,
L_10 ,
error ) ;
return error ;
}
}
return 0 ;
}
static void F_37 ( struct V_1 * V_1 , unsigned int V_65 )
{
struct V_58 * V_59 = V_1 -> V_60 ;
if ( V_65 >= 80 ) {
V_59 -> V_2 |= V_66 ;
V_1 -> V_65 = 80 ;
} else {
V_59 -> V_2 &= ~ V_66 ;
V_1 -> V_65 = 40 ;
}
F_1 ( V_1 , V_59 -> V_2 ) ;
}
static int F_38 ( struct V_68 * V_68 , T_1 V_69 )
{
struct V_1 * V_70 = F_39 ( V_68 -> V_70 ) ;
T_1 V_71 = V_72 ;
int error ;
error = F_2 ( V_70 , V_69 ) ;
if ( error )
return error ;
error = F_3 ( & V_70 -> V_5 , & V_71 , V_6 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_40 ( struct V_68 * V_68 )
{
struct V_1 * V_70 = F_39 ( V_68 -> V_70 ) ;
struct V_58 * V_59 = V_70 -> V_60 ;
F_41 ( V_70 -> V_5 . V_68 ) ;
V_59 -> V_73 = V_68 ;
F_42 ( V_70 -> V_5 . V_68 ) ;
return 0 ;
}
static void F_43 ( struct V_68 * V_68 )
{
struct V_1 * V_70 = F_39 ( V_68 -> V_70 ) ;
struct V_58 * V_59 = V_70 -> V_60 ;
F_41 ( V_70 -> V_5 . V_68 ) ;
V_59 -> V_73 = NULL ;
F_42 ( V_70 -> V_5 . V_68 ) ;
}
static int F_44 ( T_1 * V_17 )
{
return ( V_17 [ 0 ] & 0xFC ) == 0x84 && ( V_17 [ 3 ] & 0xCC ) == 0xC4 ;
}
static void F_45 ( struct V_68 * V_74 , T_1 * V_75 )
{
struct V_1 * V_76 = F_39 ( V_74 ) ;
if ( V_76 && V_76 -> V_77 == V_78 ) {
F_46 ( V_74 , V_75 [ 1 ] , 0 ) ;
F_46 ( V_74 , V_75 [ 4 ] , 0 ) ;
F_46 ( V_74 , V_75 [ 5 ] , 0 ) ;
if ( V_76 -> V_79 == 4 )
F_46 ( V_74 , V_75 [ 2 ] , 0 ) ;
} else {
F_46 ( V_74 , V_75 [ 1 ] , 0 ) ;
}
}
static void F_47 ( struct V_1 * V_1 )
{
struct V_58 * V_59 = V_1 -> V_60 ;
struct V_1 * V_76 = F_39 ( V_59 -> V_73 ) ;
if ( V_76 ) {
if ( V_76 -> V_79 == 4 )
V_59 -> V_2 |= V_80 ;
else
V_59 -> V_2 &= ~ V_80 ;
if ( F_1 ( V_1 , V_59 -> V_2 ) )
F_20 ( V_1 ,
L_11 ) ;
}
}
static void F_48 ( struct V_1 * V_1 )
{
struct V_68 * V_68 ;
V_68 = F_49 ( sizeof( struct V_68 ) , V_81 ) ;
if ( ! V_68 ) {
F_36 ( V_1 ,
L_12 ) ;
return;
}
V_68 -> V_82 . type = V_83 ;
F_50 ( V_68 -> V_12 , L_13 , sizeof( V_68 -> V_12 ) ) ;
F_50 ( V_68 -> V_84 , L_14 , sizeof( V_68 -> V_12 ) ) ;
V_68 -> V_85 = F_38 ;
V_68 -> V_86 = F_40 ;
V_68 -> V_87 = F_43 ;
V_68 -> V_70 = V_1 -> V_5 . V_68 ;
V_1 -> V_88 = F_47 ;
F_25 ( V_1 , L_15 ,
V_68 -> V_12 , V_1 -> V_84 ) ;
F_51 ( V_68 ) ;
}
static void F_52 ( const T_1 V_17 [] ,
struct V_58 * V_59 ,
struct V_89 * V_90 )
{
struct V_89 * V_91 = & V_59 -> V_91 ;
int V_92 ;
V_92 = ( V_17 [ 5 ] & 0x30 ) >> 4 ;
switch ( V_92 ) {
case 1 :
V_91 -> V_93 = V_90 -> V_93 ;
V_91 -> V_94 = ( ( ( V_17 [ 4 ] & 0x0f ) << 8 ) | V_17 [ 1 ] ) << 1 ;
V_91 -> V_49 = ( ( ( V_17 [ 4 ] & 0xf0 ) << 4 ) | V_17 [ 2 ] ) << 1 ;
V_91 -> V_95 = ( ( V_17 [ 3 ] & 0x30 ) | ( V_17 [ 5 ] & 0x0f ) ) << 1 ;
break;
case 2 :
V_59 -> V_96 = V_17 [ 1 ] ;
break;
default:
break;
}
}
static void F_53 ( const T_1 V_17 [] ,
struct V_58 * V_59 ,
struct V_89 * V_90 )
{
unsigned int V_97 =
( F_21 ( V_59 -> V_20 . V_35 ) + 1 ) >> 1 ;
unsigned int V_98 = F_54 ( V_97 - 1 , 0 ) ;
V_90 -> V_99 = V_17 [ 4 ] & V_98 ;
V_90 -> V_99 |= ( V_17 [ 5 ] & V_98 ) << V_97 ;
}
static int F_55 ( const T_1 V_17 [] ,
struct V_58 * V_59 ,
struct V_89 * V_90 )
{
memset ( V_90 , 0 , sizeof( struct V_89 ) ) ;
if ( F_56 ( V_59 -> V_20 . V_25 ) ) {
V_90 -> V_93 = ( ( ( V_17 [ 0 ] & 0x30 ) >> 2 ) |
( ( V_17 [ 0 ] & 0x04 ) >> 1 ) |
( ( V_17 [ 3 ] & 0x04 ) >> 2 ) ) ;
if ( F_31 ( V_59 ) && V_90 -> V_93 == 2 ) {
F_52 ( V_17 , V_59 , V_90 ) ;
return 1 ;
}
V_90 -> V_94 = ( ( ( V_17 [ 3 ] & 0x10 ) << 8 ) |
( ( V_17 [ 1 ] & 0x0f ) << 8 ) |
V_17 [ 4 ] ) ;
V_90 -> V_49 = ( ( ( V_17 [ 3 ] & 0x20 ) << 7 ) |
( ( V_17 [ 1 ] & 0xf0 ) << 4 ) |
V_17 [ 5 ] ) ;
V_90 -> V_95 = V_17 [ 2 ] ;
V_90 -> V_100 = ( V_17 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_90 -> V_101 = ( V_17 [ 0 ] & 0x02 ) ? 1 : 0 ;
if ( V_59 -> V_102 ) {
if ( V_90 -> V_95 == 0 ) {
V_59 -> V_103 = V_59 -> V_104 = false ;
} else if ( V_90 -> V_93 >= 4 && ( ( V_17 [ 0 ] ^ V_17 [ 3 ] ) & 0x01 ) ) {
if ( ! V_59 -> V_103 ) {
V_59 -> V_105 = V_106 ;
V_59 -> V_103 = true ;
} else if ( F_57 ( V_106 ,
V_59 -> V_105 +
F_58 ( 50 ) ) ) {
V_59 -> V_104 = true ;
}
} else {
V_59 -> V_103 = false ;
}
V_90 -> V_100 = V_59 -> V_104 ;
} else if ( F_59 ( V_59 -> V_20 . V_36 ) ) {
V_90 -> V_100 = ( ( V_17 [ 0 ] ^ V_17 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
} else if ( F_60 ( V_59 -> V_20 . V_34 ) ) {
V_90 -> V_107 = ( ( V_17 [ 0 ] ^ V_17 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
if ( V_90 -> V_93 == 2 )
V_90 -> V_108 = ( V_109 ) V_17 [ 1 ] ;
}
if ( F_61 ( V_59 -> V_20 . V_34 ) ) {
V_90 -> V_110 = ( ( V_17 [ 0 ] ^ V_17 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
V_90 -> V_111 = ( ( V_17 [ 0 ] ^ V_17 [ 3 ] ) & 0x02 ) ? 1 : 0 ;
}
if ( F_21 ( V_59 -> V_20 . V_35 ) > 0 &&
( ( V_17 [ 0 ] ^ V_17 [ 3 ] ) & 0x02 ) ) {
F_53 ( V_17 , V_59 , V_90 ) ;
}
} else {
V_90 -> V_94 = ( ( ( V_17 [ 1 ] & 0x1f ) << 8 ) | V_17 [ 2 ] ) ;
V_90 -> V_49 = ( ( ( V_17 [ 4 ] & 0x1f ) << 8 ) | V_17 [ 5 ] ) ;
V_90 -> V_95 = ( ( ( V_17 [ 0 ] & 0x30 ) << 2 ) | ( V_17 [ 3 ] & 0x3F ) ) ;
V_90 -> V_93 = ( ( ( V_17 [ 1 ] & 0x80 ) >> 4 ) | ( ( V_17 [ 0 ] & 0x04 ) >> 1 ) ) ;
V_90 -> V_100 = ( V_17 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_90 -> V_101 = ( V_17 [ 0 ] & 0x02 ) ? 1 : 0 ;
}
if ( V_90 -> V_94 > V_112 )
V_90 -> V_94 -= 1 << V_113 ;
else if ( V_90 -> V_94 == V_112 )
V_90 -> V_94 = V_114 ;
if ( V_90 -> V_49 > V_115 )
V_90 -> V_49 -= 1 << V_113 ;
else if ( V_90 -> V_49 == V_115 )
V_90 -> V_49 = V_116 ;
return 0 ;
}
static void F_62 ( struct V_117 * V_118 , int V_119 ,
bool V_120 , int V_94 , int V_49 )
{
F_63 ( V_118 , V_119 ) ;
F_64 ( V_118 , V_121 , V_120 ) ;
if ( V_120 ) {
F_65 ( V_118 , V_122 , V_94 ) ;
F_65 ( V_118 , V_123 , F_28 ( V_49 ) ) ;
}
}
static void F_66 ( struct V_117 * V_118 ,
const struct V_89 * V_124 ,
const struct V_89 * V_125 ,
int V_126 )
{
if ( V_126 >= 2 ) {
F_62 ( V_118 , 0 , true , V_55 ( V_124 -> V_94 , V_125 -> V_94 ) ,
V_55 ( V_124 -> V_49 , V_125 -> V_49 ) ) ;
F_62 ( V_118 , 1 , true , V_57 ( V_124 -> V_94 , V_125 -> V_94 ) ,
V_57 ( V_124 -> V_49 , V_125 -> V_49 ) ) ;
} else if ( V_126 == 1 ) {
F_62 ( V_118 , 0 , true , V_124 -> V_94 , V_124 -> V_49 ) ;
F_62 ( V_118 , 1 , false , 0 , 0 ) ;
} else {
F_62 ( V_118 , 0 , false , 0 , 0 ) ;
F_62 ( V_118 , 1 , false , 0 , 0 ) ;
}
}
static void F_67 ( struct V_1 * V_1 ,
const struct V_89 * V_90 )
{
struct V_117 * V_118 = V_1 -> V_118 ;
struct V_58 * V_59 = V_1 -> V_60 ;
int V_97 = ( F_21 ( V_59 -> V_20 . V_35 ) + 1 ) >> 1 ;
int V_52 ;
if ( ! F_21 ( V_59 -> V_20 . V_35 ) )
return;
if ( ( F_14 ( V_59 -> V_20 . V_22 ) == 0x801 ||
F_14 ( V_59 -> V_20 . V_22 ) == 0x802 ) &&
! ( ( V_1 -> V_75 [ 0 ] ^ V_1 -> V_75 [ 3 ] ) & 0x02 ) )
return;
if ( ! F_68 ( V_59 -> V_20 . V_32 ) ) {
for ( V_52 = 0 ; V_52 < V_97 ; V_52 ++ ) {
F_69 ( V_118 , V_127 + 2 * V_52 ,
V_90 -> V_99 & F_70 ( V_52 ) ) ;
F_69 ( V_118 , V_128 + 2 * V_52 ,
V_90 -> V_99 & F_70 ( V_52 + V_97 ) ) ;
}
return;
}
if ( V_59 -> V_73 ) {
T_1 V_129 ;
V_129 = F_71 ( V_90 -> V_99 ) |
F_72 ( V_90 -> V_99 ) << 1 |
F_73 ( V_90 -> V_99 ) << 2 ;
F_46 ( V_59 -> V_73 ,
V_130 , V_131 ) ;
F_46 ( V_59 -> V_73 , V_129 , V_131 ) ;
}
}
static void F_74 ( struct V_1 * V_1 ,
const struct V_89 * V_90 )
{
struct V_117 * V_118 = V_1 -> V_118 ;
struct V_58 * V_59 = V_1 -> V_60 ;
F_69 ( V_118 , V_132 , V_90 -> V_100 ) ;
F_69 ( V_118 , V_133 , V_90 -> V_101 ) ;
if ( F_60 ( V_59 -> V_20 . V_34 ) )
F_69 ( V_118 , V_134 , V_90 -> V_107 ) ;
if ( F_61 ( V_59 -> V_20 . V_34 ) ) {
F_69 ( V_118 , V_135 , V_90 -> V_110 ) ;
F_69 ( V_118 , V_136 , V_90 -> V_111 ) ;
}
F_67 ( V_1 , V_90 ) ;
}
static void F_75 ( struct V_1 * V_1 ,
const struct V_89 * V_137 ,
int V_126 )
{
struct V_117 * V_118 = V_1 -> V_118 ;
struct V_58 * V_59 = V_1 -> V_60 ;
const struct V_89 * V_90 [ 2 ] = { V_137 , & V_59 -> V_91 } ;
struct V_138 V_139 [ 2 ] ;
int V_119 [ 2 ] , V_140 , V_52 ;
V_140 = F_76 ( V_126 , 0 , 2 ) ;
for ( V_52 = 0 ; V_52 < V_140 ; V_52 ++ ) {
V_139 [ V_52 ] . V_94 = V_90 [ V_52 ] -> V_94 ;
V_139 [ V_52 ] . V_49 = F_28 ( V_90 [ V_52 ] -> V_49 ) ;
}
F_77 ( V_118 , V_119 , V_139 , V_140 , V_141 * V_59 -> V_20 . V_41 ) ;
for ( V_52 = 0 ; V_52 < V_140 ; V_52 ++ ) {
F_63 ( V_118 , V_119 [ V_52 ] ) ;
F_64 ( V_118 , V_121 , true ) ;
F_65 ( V_118 , V_122 , V_139 [ V_52 ] . V_94 ) ;
F_65 ( V_118 , V_123 , V_139 [ V_52 ] . V_49 ) ;
F_65 ( V_118 , V_142 , V_90 [ V_52 ] -> V_95 ) ;
}
F_78 ( V_118 ) ;
F_79 ( V_118 , false ) ;
F_80 ( V_118 , V_126 ) ;
F_74 ( V_1 , V_137 ) ;
F_81 ( V_118 ) ;
}
static void F_82 ( struct V_1 * V_1 ,
struct V_89 * V_137 )
{
struct V_58 * V_59 = V_1 -> V_60 ;
int V_126 ;
if ( V_137 -> V_95 == 0 )
V_126 = 0 ;
else if ( V_137 -> V_93 >= 4 )
V_126 = 1 ;
else if ( V_137 -> V_93 == 0 )
V_126 = 2 ;
else if ( V_137 -> V_93 == 1 )
V_126 = V_59 -> V_96 ? V_59 -> V_96 : 3 ;
else
V_126 = 4 ;
F_75 ( V_1 , V_137 , V_126 ) ;
}
static bool F_83 ( struct V_58 * V_59 )
{
if ( F_84 ( V_59 -> V_20 . V_34 ) )
return true ;
return F_31 ( V_59 ) ;
}
static void F_85 ( struct V_1 * V_1 )
{
struct V_117 * V_118 = V_1 -> V_118 ;
struct V_58 * V_59 = V_1 -> V_60 ;
struct V_19 * V_20 = & V_59 -> V_20 ;
struct V_89 V_90 ;
int V_126 ;
int V_143 ;
if ( F_55 ( V_1 -> V_75 , V_59 , & V_90 ) )
return;
if ( F_33 ( V_20 -> V_36 ) ) {
F_82 ( V_1 , & V_90 ) ;
return;
}
if ( V_90 . V_108 ) {
V_59 -> V_108 += V_90 . V_108 ;
while ( V_59 -> V_108 >= 4 ) {
F_69 ( V_118 , V_136 , ! V_90 . V_111 ) ;
F_81 ( V_118 ) ;
F_69 ( V_118 , V_136 , V_90 . V_111 ) ;
F_81 ( V_118 ) ;
V_59 -> V_108 -= 4 ;
}
while ( V_59 -> V_108 <= - 4 ) {
F_69 ( V_118 , V_135 , ! V_90 . V_110 ) ;
F_81 ( V_118 ) ;
F_69 ( V_118 , V_135 , V_90 . V_110 ) ;
F_81 ( V_118 ) ;
V_59 -> V_108 += 4 ;
}
return;
}
if ( V_90 . V_95 > 0 && V_90 . V_94 > 1 ) {
V_126 = 1 ;
V_143 = 5 ;
if ( F_18 ( V_20 -> V_34 ) ) {
switch ( V_90 . V_93 ) {
case 0 ... 1 :
if ( F_83 ( V_59 ) )
V_126 = V_90 . V_93 + 2 ;
break;
case 2 :
if ( F_86 ( V_20 -> V_25 ) )
;
break;
case 4 ... 15 :
if ( F_87 ( V_20 -> V_34 ) )
V_143 = V_90 . V_93 ;
break;
}
}
} else {
V_126 = 0 ;
V_143 = 0 ;
}
if ( V_144 ) {
F_75 ( V_1 , & V_90 , V_126 ) ;
return;
}
if ( F_32 ( V_20 -> V_36 ) )
F_66 ( V_118 , & V_90 , & V_59 -> V_91 ,
V_126 ) ;
if ( V_90 . V_95 > 30 ) F_69 ( V_118 , V_145 , 1 ) ;
if ( V_90 . V_95 < 25 ) F_69 ( V_118 , V_145 , 0 ) ;
if ( V_126 > 0 ) {
F_65 ( V_118 , V_146 , V_90 . V_94 ) ;
F_65 ( V_118 , V_147 , F_28 ( V_90 . V_49 ) ) ;
}
F_65 ( V_118 , V_148 , V_90 . V_95 ) ;
if ( F_87 ( V_20 -> V_34 ) )
F_65 ( V_118 , V_149 , V_143 ) ;
F_69 ( V_118 , V_150 , V_126 == 1 ) ;
if ( F_83 ( V_59 ) ) {
F_69 ( V_118 , V_151 , V_126 == 2 ) ;
F_69 ( V_118 , V_152 , V_126 == 3 ) ;
}
F_74 ( V_1 , & V_90 ) ;
F_81 ( V_118 ) ;
}
static bool F_88 ( struct V_1 * V_1 ,
int V_153 , enum V_154 V_155 )
{
static const T_1 V_156 [] = { 0xC8 , 0x00 , 0x00 , 0xC8 , 0x00 } ;
static const T_1 V_157 [] = { 0xC0 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const T_1 V_158 [] = { 0x80 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const T_1 V_159 [] = { 0xC0 , 0x60 , 0x00 , 0xC0 , 0x60 } ;
static const T_1 V_160 [] = { 0xC0 , 0x00 , 0x00 , 0x80 , 0x00 } ;
const T_1 * V_75 = V_1 -> V_75 ;
if ( V_153 < 0 || V_153 > 4 )
return false ;
switch ( V_155 ) {
case V_161 :
case V_162 :
return ( V_75 [ V_153 ] & V_157 [ V_153 ] ) == V_158 [ V_153 ] ;
case V_163 :
return ( V_75 [ V_153 ] & V_156 [ V_153 ] ) == V_158 [ V_153 ] ;
case V_164 :
return ( V_75 [ V_153 ] & V_159 [ V_153 ] ) == V_160 [ V_153 ] ;
default:
F_36 ( V_1 , L_16 , V_155 ) ;
return false ;
}
}
static enum V_154
F_89 ( struct V_1 * V_1 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < 5 ; V_52 ++ ) {
if ( ! F_88 ( V_1 , V_52 , V_163 ) ) {
F_25 ( V_1 , L_17 ) ;
return V_162 ;
}
}
return V_163 ;
}
static T_4 F_90 ( struct V_1 * V_1 )
{
struct V_58 * V_59 = V_1 -> V_60 ;
if ( V_1 -> V_165 >= 6 ) {
if ( F_91 ( V_59 -> V_155 == V_161 ) )
V_59 -> V_155 = F_89 ( V_1 ) ;
if ( F_92 ( V_59 -> V_20 . V_34 ) &&
F_44 ( V_1 -> V_75 ) ) {
if ( V_59 -> V_73 )
F_45 ( V_59 -> V_73 ,
V_1 -> V_75 ) ;
} else
F_85 ( V_1 ) ;
return V_166 ;
}
return F_88 ( V_1 , V_1 -> V_165 - 1 , V_59 -> V_155 ) ?
V_167 : V_168 ;
}
static void F_93 ( struct V_117 * V_118 ,
struct V_19 * V_20 ,
int V_169 , int V_170 )
{
int V_47 = V_20 -> V_47 ? : V_171 ;
int V_44 = V_20 -> V_44 ? : V_172 ;
int V_48 = V_20 -> V_48 ? : V_51 ;
int V_45 = V_20 -> V_45 ? : V_50 ;
int V_173 = F_94 ( V_20 -> V_36 ) ?
V_174 : 0 ;
F_95 ( V_118 , V_169 , V_47 , V_44 , V_173 , 0 ) ;
F_95 ( V_118 , V_170 , V_48 , V_45 , V_173 , 0 ) ;
F_96 ( V_118 , V_169 , V_20 -> V_41 ) ;
F_96 ( V_118 , V_170 , V_20 -> V_42 ) ;
}
static void F_97 ( struct V_1 * V_1 ,
struct V_58 * V_59 )
{
struct V_117 * V_118 = V_1 -> V_118 ;
struct V_19 * V_20 = & V_59 -> V_20 ;
int V_52 ;
F_98 ( V_175 , V_118 -> V_176 ) ;
F_98 ( V_177 , V_118 -> V_178 ) ;
F_98 ( V_132 , V_118 -> V_179 ) ;
F_98 ( V_133 , V_118 -> V_179 ) ;
if ( F_60 ( V_20 -> V_34 ) )
F_98 ( V_134 , V_118 -> V_179 ) ;
if ( ! V_59 -> V_61 ) {
F_98 ( V_180 , V_118 -> V_178 ) ;
F_98 ( V_181 , V_118 -> V_182 ) ;
F_98 ( V_183 , V_118 -> V_182 ) ;
return;
}
F_98 ( V_184 , V_118 -> V_178 ) ;
F_93 ( V_118 , & V_59 -> V_20 , V_146 , V_147 ) ;
F_95 ( V_118 , V_148 , 0 , 255 , 0 , 0 ) ;
if ( V_144 )
F_95 ( V_118 , V_142 , 0 , 255 , 0 , 0 ) ;
if ( F_33 ( V_20 -> V_36 ) ) {
F_93 ( V_118 , V_20 ,
V_122 , V_123 ) ;
F_95 ( V_118 , V_142 , 0 , 255 , 0 , 0 ) ;
F_99 ( V_118 , 2 , V_185 | V_186 ) ;
F_98 ( V_187 , V_118 -> V_179 ) ;
F_98 ( V_188 , V_118 -> V_179 ) ;
} else if ( F_32 ( V_20 -> V_36 ) ) {
F_93 ( V_118 , V_20 ,
V_122 , V_123 ) ;
F_99 ( V_118 , 2 ,
V_185 |
( V_144 ?
V_186 : V_189 ) ) ;
}
if ( F_87 ( V_20 -> V_34 ) )
F_95 ( V_118 , V_149 , 0 , 15 , 0 , 0 ) ;
F_98 ( V_145 , V_118 -> V_179 ) ;
F_98 ( V_150 , V_118 -> V_179 ) ;
if ( F_83 ( V_59 ) ) {
F_98 ( V_151 , V_118 -> V_179 ) ;
F_98 ( V_152 , V_118 -> V_179 ) ;
}
if ( F_61 ( V_20 -> V_34 ) ||
F_60 ( V_20 -> V_34 ) ) {
F_98 ( V_135 , V_118 -> V_179 ) ;
F_98 ( V_136 , V_118 -> V_179 ) ;
}
if ( ! F_68 ( V_20 -> V_32 ) )
for ( V_52 = 0 ; V_52 < F_21 ( V_20 -> V_35 ) ; V_52 ++ )
F_98 ( V_127 + V_52 , V_118 -> V_179 ) ;
F_100 ( V_180 , V_118 -> V_178 ) ;
F_100 ( V_181 , V_118 -> V_182 ) ;
F_100 ( V_183 , V_118 -> V_182 ) ;
if ( F_59 ( V_20 -> V_36 ) ) {
F_98 ( V_190 , V_118 -> V_176 ) ;
if ( F_30 ( V_1 , V_191 ) &&
! F_68 ( V_20 -> V_32 ) )
F_98 ( V_192 , V_118 -> V_176 ) ;
F_100 ( V_133 , V_118 -> V_179 ) ;
F_100 ( V_134 , V_118 -> V_179 ) ;
}
}
static T_5 F_101 ( struct V_1 * V_1 ,
void * V_193 , char * V_17 )
{
struct V_58 * V_59 = V_1 -> V_60 ;
return sprintf ( V_17 , L_18 , V_59 -> V_63 ? '1' : '0' ) ;
}
static T_5 F_102 ( struct V_1 * V_1 ,
void * V_193 , const char * V_17 ,
T_6 V_194 )
{
struct V_58 * V_59 = V_1 -> V_60 ;
unsigned int V_195 ;
int V_196 ;
V_196 = F_103 ( V_17 , 10 , & V_195 ) ;
if ( V_196 )
return V_196 ;
if ( V_195 > 1 )
return - V_197 ;
if ( V_195 == V_59 -> V_63 )
return V_194 ;
V_59 -> V_63 = V_195 ;
if ( V_195 )
V_59 -> V_2 |= V_64 ;
else
V_59 -> V_2 &= ~ V_64 ;
if ( F_1 ( V_1 , V_59 -> V_2 ) )
return - V_198 ;
return V_194 ;
}
static void F_104 ( struct V_1 * V_1 )
{
struct V_58 * V_59 = V_1 -> V_60 ;
F_105 ( V_1 ) ;
if ( ! V_59 -> V_61 &&
F_106 ( V_59 -> V_20 . V_22 ) )
F_107 ( & V_1 -> V_5 . V_68 -> V_118 ,
& V_199 . V_200 ) ;
F_5 ( V_1 ) ;
F_108 ( V_59 ) ;
V_1 -> V_60 = NULL ;
}
static int F_109 ( struct V_1 * V_1 )
{
struct V_58 * V_59 = V_1 -> V_60 ;
struct V_19 V_20 ;
T_1 V_3 [ 2 ] ;
int V_201 = 0 ;
int error ;
do {
F_110 ( V_1 ) ;
if ( V_201 ) {
F_111 ( 1 ) ;
}
F_3 ( & V_1 -> V_5 , V_3 , V_202 ) ;
error = F_4 ( V_1 , 0 ) ;
} while ( error && ++ V_201 < 3 );
if ( error )
return error ;
if ( V_201 > 1 )
F_112 ( V_1 , L_19 , V_201 ) ;
error = F_27 ( V_1 , & V_20 ) ;
if ( error ) {
F_36 ( V_1 , L_20 ) ;
return error ;
}
error = F_35 ( V_1 ) ;
if ( error ) {
F_36 ( V_1 , L_21 ) ;
return error ;
}
if ( V_20 . V_22 != V_59 -> V_20 . V_22 ||
V_20 . V_25 != V_59 -> V_20 . V_25 ||
V_20 . V_34 != V_59 -> V_20 . V_34 ||
V_20 . V_35 != V_59 -> V_20 . V_35 ) {
F_36 ( V_1 ,
L_22 ,
V_59 -> V_20 . V_22 , V_20 . V_22 ,
V_59 -> V_20 . V_25 , V_20 . V_25 ,
V_59 -> V_20 . V_34 , V_20 . V_34 ,
V_59 -> V_20 . V_35 , V_20 . V_35 ) ;
return - V_23 ;
}
return 0 ;
}
void T_7 F_113 ( void )
{
V_203 = F_114 ( V_204 ) ;
V_205 = F_114 ( V_206 ) ;
V_144 = F_114 ( V_207 ) ;
}
static int F_115 ( struct V_1 * V_1 ,
struct V_19 * V_20 ,
bool V_61 )
{
struct V_58 * V_59 ;
int V_196 ;
F_29 ( V_1 , V_20 ) ;
V_1 -> V_60 = V_59 = F_49 ( sizeof( struct V_58 ) , V_81 ) ;
if ( ! V_59 )
return - V_208 ;
V_59 -> V_20 = * V_20 ;
V_59 -> V_61 = V_61 ;
if ( F_106 ( V_20 -> V_22 ) )
V_59 -> V_63 = true ;
V_59 -> V_102 = F_30 ( V_1 , V_209 ) ;
V_196 = F_35 ( V_1 ) ;
if ( V_196 ) {
F_36 ( V_1 , L_21 ) ;
goto V_210;
}
V_59 -> V_155 = F_56 ( V_20 -> V_25 ) ?
V_161 : V_164 ;
F_25 ( V_1 ,
L_23 ,
F_116 ( V_20 -> V_22 ) ,
F_23 ( V_20 -> V_22 ) , F_117 ( V_20 -> V_22 ) ,
V_20 -> V_25 ,
V_20 -> V_34 , V_20 -> V_35 , V_20 -> V_36 ,
V_20 -> V_32 , V_20 -> V_30 , V_20 -> V_27 ) ;
F_97 ( V_1 , V_59 ) ;
V_1 -> V_211 = ( ( V_20 -> V_25 & 0x00ff0000 ) >> 8 ) |
( V_20 -> V_25 & 0x000000ff ) ;
if ( V_61 ) {
V_1 -> V_212 = F_90 ;
V_1 -> V_79 = 6 ;
} else {
V_1 -> V_212 = V_213 ;
V_1 -> V_79 = 3 ;
}
V_1 -> V_214 = F_37 ;
V_1 -> V_215 = F_104 ;
V_1 -> V_216 = F_109 ;
V_1 -> V_217 = F_5 ;
V_1 -> V_218 = 0 ;
if ( F_92 ( V_20 -> V_34 ) )
F_48 ( V_1 ) ;
if ( V_1 -> V_65 >= 80 && V_203 ) {
F_25 ( V_1 ,
L_24 ,
F_118 ( V_219 ) ) ;
V_1 -> V_65 = 40 ;
}
if ( ! V_59 -> V_61 && F_106 ( V_20 -> V_22 ) ) {
V_196 = F_119 ( & V_1 -> V_5 . V_68 -> V_118 ,
& V_199 . V_200 ) ;
if ( V_196 ) {
F_36 ( V_1 ,
L_25 ,
V_196 ) ;
goto V_210;
}
}
return 0 ;
V_210:
F_108 ( V_59 ) ;
return V_196 ;
}
static int F_120 ( struct V_1 * V_1 , bool V_61 )
{
struct V_19 V_20 ;
int error ;
F_110 ( V_1 ) ;
error = F_27 ( V_1 , & V_20 ) ;
if ( error ) {
F_36 ( V_1 , L_26 , error ) ;
return error ;
}
return F_115 ( V_1 , & V_20 , V_61 ) ;
}
int F_121 ( struct V_1 * V_1 )
{
return F_120 ( V_1 , true ) ;
}
int F_122 ( struct V_1 * V_1 )
{
return F_120 ( V_1 , false ) ;
}
static int F_123 ( struct V_1 * V_1 ,
struct V_19 * V_20 )
{
bool V_61 = true ;
int error ;
if ( V_205 ) {
F_25 ( V_1 ,
L_27 ) ;
V_61 = false ;
}
error = F_115 ( V_1 , V_20 , V_61 ) ;
if ( error )
return error ;
return V_61 ? V_220 : V_221 ;
}
void T_7 F_113 ( void )
{
}
static int T_8
F_123 ( struct V_1 * V_1 ,
struct V_19 * V_20 )
{
return - V_222 ;
}
static int F_124 ( struct V_1 * V_1 ,
struct V_19 * V_20 ,
bool V_223 )
{
bool V_224 =
F_30 ( V_1 , V_191 ) &&
! F_68 ( V_20 -> V_32 ) ;
const struct V_225 V_226 = {
. V_227 = {
. V_228 = V_229 ,
. V_230 . V_231 = true ,
. V_232 = true ,
. V_224 = V_224 ,
} ,
. V_233 = {
. V_234 = F_59 ( V_20 -> V_36 ) ,
. V_235 =
! ! F_68 ( V_20 -> V_32 ) ,
} ,
} ;
const struct V_236 V_237 = {
F_125 ( L_28 , 0x2c ) ,
. V_238 = V_239 ,
} ;
return F_126 ( V_1 , & V_237 ,
& V_226 , sizeof( V_226 ) ,
V_223 ) ;
}
static int F_127 ( struct V_1 * V_1 ,
struct V_19 * V_20 ,
bool V_223 )
{
int error ;
if ( V_240 == V_241 )
return - V_23 ;
if ( V_240 == V_242 ) {
if ( ! F_30 ( V_1 , V_191 ) &&
! F_30 ( V_1 , V_243 ) ) {
if ( ! F_30 ( V_1 , V_209 ) )
F_25 ( V_1 ,
L_29
L_30 ,
V_1 -> V_5 . V_68 -> V_27 ) ;
return - V_23 ;
}
}
F_25 ( V_1 , L_31 ) ;
error = F_124 ( V_1 , V_20 , V_223 ) ;
if ( error ) {
if ( error == - V_244 )
F_25 ( V_1 , L_32 ) ;
else
F_36 ( V_1 , L_33 ) ;
return error ;
}
return 0 ;
}
int F_128 ( struct V_1 * V_1 )
{
struct V_19 V_20 ;
int error ;
F_110 ( V_1 ) ;
error = F_27 ( V_1 , & V_20 ) ;
if ( error ) {
F_36 ( V_1 , L_26 , error ) ;
return error ;
}
if ( ! F_129 ( V_20 . V_36 ) )
return - V_23 ;
return F_124 ( V_1 , & V_20 , false ) ;
}
static int T_8
F_127 ( struct V_1 * V_1 ,
struct V_19 * V_20 ,
bool V_223 )
{
return - V_222 ;
}
int F_128 ( struct V_1 * V_1 )
{
return - V_222 ;
}
int F_130 ( struct V_1 * V_1 )
{
struct V_19 V_20 ;
int error ;
int V_245 ;
F_110 ( V_1 ) ;
error = F_27 ( V_1 , & V_20 ) ;
if ( error ) {
F_36 ( V_1 , L_26 , error ) ;
return error ;
}
if ( F_129 ( V_20 . V_36 ) ) {
if ( ( ! F_131 ( V_246 ) ||
! F_131 ( V_247 ) ) &&
! F_30 ( V_1 , V_209 ) ) {
F_20 ( V_1 ,
L_34
L_35 ) ;
}
error = F_127 ( V_1 , & V_20 , true ) ;
if ( ! error )
return V_248 ;
}
V_245 = F_123 ( V_1 , & V_20 ) ;
if ( V_245 < 0 ) {
F_105 ( V_1 ) ;
}
return V_245 ;
}
int F_130 ( struct V_1 * V_1 )
{
return - V_222 ;
}
