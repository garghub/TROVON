static T_1 F_1 ( struct V_1 * V_2 , T_2 * V_3 ,
T_3 V_4 )
{
T_2 * V_5 ;
T_1 V_6 ;
if ( ! V_2 -> V_7 )
return - V_8 ;
V_5 = F_2 ( V_3 , V_4 , V_9 ) ;
if ( ! V_5 )
return - V_10 ;
V_6 = V_2 -> V_7 ( V_2 , V_5 , V_4 , V_11 ) ;
F_3 ( V_5 ) ;
return V_6 ;
}
static void F_4 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_5 ( V_13 , struct V_14 ,
V_16 ) ;
unsigned long V_17 ;
F_6 ( & V_15 -> V_18 , V_17 ) ;
while ( V_15 -> V_19 != V_15 -> V_20 ) {
F_7 ( & V_15 -> V_18 , V_17 ) ;
F_1 ( V_15 -> V_2 , V_15 -> V_21 [ V_15 -> V_20 ] . V_22 ,
V_15 -> V_21 [ V_15 -> V_20 ] . V_23 ) ;
F_6 ( & V_15 -> V_18 , V_17 ) ;
V_15 -> V_20 = ( V_15 -> V_20 + 1 ) % V_24 ;
}
F_7 ( & V_15 -> V_18 , V_17 ) ;
}
static void F_8 ( struct V_14 * V_15 , const T_2 * V_3 ,
T_3 V_4 )
{
unsigned long V_17 ;
T_2 V_25 ;
if ( V_4 > V_26 ) {
F_9 ( V_15 -> V_2 , L_1 ) ;
return;
}
F_6 ( & V_15 -> V_18 , V_17 ) ;
memcpy ( V_15 -> V_21 [ V_15 -> V_19 ] . V_22 , V_3 , V_4 ) ;
V_15 -> V_21 [ V_15 -> V_19 ] . V_23 = V_4 ;
V_25 = ( V_15 -> V_19 + 1 ) % V_24 ;
if ( V_15 -> V_19 == V_15 -> V_20 ) {
V_15 -> V_19 = V_25 ;
F_10 ( & V_15 -> V_16 ) ;
} else if ( V_25 != V_15 -> V_20 ) {
V_15 -> V_19 = V_25 ;
} else {
F_9 ( V_15 -> V_2 , L_2 ) ;
}
F_7 ( & V_15 -> V_18 , V_17 ) ;
}
static inline void F_11 ( struct V_14 * V_15 , T_2 * V_27 )
{
if ( V_15 -> V_28 . V_17 & V_29 )
* V_27 |= 0x01 ;
}
static void F_12 ( struct V_14 * V_15 , T_2 V_30 )
{
T_2 V_31 [ 2 ] ;
V_30 = ! ! V_30 ;
if ( V_30 == ! ! ( V_15 -> V_28 . V_17 & V_29 ) )
return;
if ( V_30 )
V_15 -> V_28 . V_17 |= V_29 ;
else
V_15 -> V_28 . V_17 &= ~ V_29 ;
V_31 [ 0 ] = V_32 ;
V_31 [ 1 ] = 0 ;
F_11 ( V_15 , & V_31 [ 1 ] ) ;
F_8 ( V_15 , V_31 , sizeof( V_31 ) ) ;
}
static void F_13 ( struct V_14 * V_15 , int V_33 )
{
T_2 V_31 [ 2 ] ;
V_33 &= V_34 ;
if ( ( V_15 -> V_28 . V_17 & V_34 ) == V_33 )
return;
V_15 -> V_28 . V_17 = ( V_15 -> V_28 . V_17 & ~ V_34 ) | V_33 ;
V_31 [ 0 ] = V_35 ;
V_31 [ 1 ] = 0 ;
if ( V_33 & V_36 )
V_31 [ 1 ] |= 0x10 ;
if ( V_33 & V_37 )
V_31 [ 1 ] |= 0x20 ;
if ( V_33 & V_38 )
V_31 [ 1 ] |= 0x40 ;
if ( V_33 & V_39 )
V_31 [ 1 ] |= 0x80 ;
F_11 ( V_15 , & V_31 [ 1 ] ) ;
F_8 ( V_15 , V_31 , sizeof( V_31 ) ) ;
}
static T_2 F_14 ( struct V_14 * V_15 )
{
T_2 V_40 = V_15 -> V_28 . V_17 & V_41 ;
bool V_42 = F_15 ( V_15 ) ;
if ( V_40 == V_43 ) {
if ( V_15 -> V_28 . V_17 & V_44 )
return V_45 ;
else
return V_46 ;
} else if ( V_40 == V_47 ) {
return V_48 ;
} else if ( V_40 == V_49 ) {
return V_50 ;
} else {
if ( V_15 -> V_28 . V_17 & V_44 ) {
if ( V_42 )
return V_51 ;
else
return V_52 ;
} else {
if ( V_42 )
return V_53 ;
else
return V_54 ;
}
}
}
void F_16 ( struct V_14 * V_15 , T_2 V_55 )
{
T_2 V_31 [ 3 ] ;
if ( V_55 == V_56 )
V_55 = F_14 ( V_15 ) ;
V_31 [ 0 ] = V_57 ;
V_31 [ 1 ] = 0 ;
V_31 [ 2 ] = V_55 ;
V_15 -> V_28 . V_55 = V_55 ;
F_11 ( V_15 , & V_31 [ 1 ] ) ;
F_8 ( V_15 , V_31 , sizeof( V_31 ) ) ;
}
static void F_17 ( struct V_14 * V_15 )
{
T_2 V_31 [ 2 ] ;
V_31 [ 0 ] = V_58 ;
V_31 [ 1 ] = 0 ;
F_11 ( V_15 , & V_31 [ 1 ] ) ;
F_8 ( V_15 , V_31 , sizeof( V_31 ) ) ;
}
static void F_18 ( struct V_14 * V_15 , T_2 V_59 )
{
V_59 = ! ! V_59 ;
if ( V_59 == ! ! ( V_15 -> V_28 . V_17 & V_44 ) )
return;
if ( V_59 )
V_15 -> V_28 . V_17 |= V_44 ;
else
V_15 -> V_28 . V_17 &= ~ V_44 ;
F_16 ( V_15 , V_56 ) ;
}
static void F_19 ( struct V_14 * V_15 , T_2 V_17 )
{
T_2 V_31 [ 2 ] ;
V_31 [ 0 ] = V_60 ;
V_31 [ 1 ] = V_17 ;
F_11 ( V_15 , & V_31 [ 1 ] ) ;
F_8 ( V_15 , V_31 , sizeof( V_31 ) ) ;
}
static void F_20 ( struct V_14 * V_15 , T_2 V_17 )
{
T_2 V_31 [ 2 ] ;
V_31 [ 0 ] = V_61 ;
V_31 [ 1 ] = V_17 ;
F_11 ( V_15 , & V_31 [ 1 ] ) ;
F_8 ( V_15 , V_31 , sizeof( V_31 ) ) ;
}
static void F_21 ( struct V_14 * V_15 , bool V_62 ,
T_4 V_63 , const T_2 * V_5 , T_2 V_23 )
{
T_2 V_31 [ 22 ] ;
if ( V_23 > 16 || V_23 == 0 ) {
F_9 ( V_15 -> V_2 , L_3 , V_23 ) ;
return;
}
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
V_31 [ 0 ] = V_64 ;
V_31 [ 2 ] = ( V_63 >> 16 ) & 0xff ;
V_31 [ 3 ] = ( V_63 >> 8 ) & 0xff ;
V_31 [ 4 ] = V_63 & 0xff ;
V_31 [ 5 ] = V_23 ;
memcpy ( & V_31 [ 6 ] , V_5 , V_23 ) ;
if ( ! V_62 )
V_31 [ 1 ] |= 0x04 ;
F_11 ( V_15 , & V_31 [ 1 ] ) ;
F_8 ( V_15 , V_31 , sizeof( V_31 ) ) ;
}
void F_22 ( struct V_14 * V_15 , bool V_62 , T_4 V_63 ,
T_5 V_23 )
{
T_2 V_31 [ 7 ] ;
if ( V_23 == 0 ) {
F_9 ( V_15 -> V_2 , L_4 , V_23 ) ;
return;
}
V_31 [ 0 ] = V_65 ;
V_31 [ 1 ] = 0 ;
V_31 [ 2 ] = ( V_63 >> 16 ) & 0xff ;
V_31 [ 3 ] = ( V_63 >> 8 ) & 0xff ;
V_31 [ 4 ] = V_63 & 0xff ;
V_31 [ 5 ] = ( V_23 >> 8 ) & 0xff ;
V_31 [ 6 ] = V_23 & 0xff ;
if ( ! V_62 )
V_31 [ 1 ] |= 0x04 ;
F_11 ( V_15 , & V_31 [ 1 ] ) ;
F_8 ( V_15 , V_31 , sizeof( V_31 ) ) ;
}
int F_23 ( struct V_14 * V_15 , T_4 V_63 ,
const T_2 * V_66 , T_2 V_23 )
{
unsigned long V_17 ;
int V_6 ;
F_6 ( & V_15 -> V_28 . V_67 , V_17 ) ;
F_24 ( V_15 , V_64 , 0 ) ;
F_25 ( V_15 , V_63 , V_66 , V_23 ) ;
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
V_6 = F_26 ( V_15 ) ;
if ( ! V_6 && V_15 -> V_28 . V_68 )
V_6 = - V_69 ;
return V_6 ;
}
T_1 F_27 ( struct V_14 * V_15 , T_4 V_63 , T_2 * V_70 ,
T_2 V_23 )
{
unsigned long V_17 ;
T_1 V_6 ;
F_6 ( & V_15 -> V_28 . V_67 , V_17 ) ;
V_15 -> V_28 . V_71 = V_23 ;
V_15 -> V_28 . V_72 = V_70 ;
F_24 ( V_15 , V_65 , V_63 & 0xffff ) ;
F_28 ( V_15 , V_63 , V_23 ) ;
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
V_6 = F_26 ( V_15 ) ;
F_6 ( & V_15 -> V_28 . V_67 , V_17 ) ;
V_15 -> V_28 . V_72 = NULL ;
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
if ( ! V_6 ) {
if ( V_15 -> V_28 . V_71 == 0 )
V_6 = - V_69 ;
else
V_6 = V_15 -> V_28 . V_71 ;
}
return V_6 ;
}
static int F_29 ( struct V_73 * V_74 ,
enum V_75 V_76 ,
union V_77 * V_78 )
{
struct V_14 * V_15 = F_5 ( V_74 ,
struct V_14 , V_79 ) ;
int V_6 = 0 , V_28 ;
unsigned long V_17 ;
if ( V_76 == V_80 ) {
V_78 -> V_81 = V_82 ;
return 0 ;
}
V_6 = F_30 ( V_15 ) ;
if ( V_6 )
return V_6 ;
F_6 ( & V_15 -> V_28 . V_67 , V_17 ) ;
F_24 ( V_15 , V_58 , 0 ) ;
F_17 ( V_15 ) ;
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
V_6 = F_26 ( V_15 ) ;
V_28 = V_15 -> V_28 . V_83 ;
F_31 ( V_15 ) ;
if ( V_6 )
return V_6 ;
switch ( V_76 ) {
case V_84 :
V_78 -> V_81 = V_28 * 100 / 255 ;
break;
default:
V_6 = - V_85 ;
break;
}
return V_6 ;
}
static int F_32 ( struct V_14 * V_15 , T_5 V_86 )
{
int V_6 ;
unsigned long V_17 ;
T_2 V_87 = 0 ;
static const T_2 V_88 [] = { 0x01 } ;
static const T_2 V_89 [] = { 0x02 , 0x00 , 0x00 , 0x71 , 0x01 ,
0x00 , 0xaa , 0x00 , 0x64 } ;
static const T_2 V_90 [] = { 0x63 , 0x03 } ;
static const T_2 V_91 [] = { 0x08 } ;
F_6 ( & V_15 -> V_28 . V_67 , V_17 ) ;
if ( V_86 == ( V_15 -> V_28 . V_17 & V_41 ) ) {
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
return 0 ;
}
if ( V_86 == 0 ) {
V_15 -> V_28 . V_17 &= ~ V_41 ;
F_19 ( V_15 , 0 ) ;
F_20 ( V_15 , 0 ) ;
F_16 ( V_15 , V_56 ) ;
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
return 0 ;
}
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
V_6 = F_30 ( V_15 ) ;
if ( V_6 )
return V_6 ;
F_6 ( & V_15 -> V_28 . V_67 , V_17 ) ;
F_24 ( V_15 , V_60 , 0 ) ;
F_19 ( V_15 , 0x06 ) ;
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
V_6 = F_26 ( V_15 ) ;
if ( V_6 )
goto V_92;
if ( V_15 -> V_28 . V_68 ) {
V_6 = - V_69 ;
goto V_92;
}
F_6 ( & V_15 -> V_28 . V_67 , V_17 ) ;
F_24 ( V_15 , V_61 , 0 ) ;
F_20 ( V_15 , 0x06 ) ;
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
V_6 = F_26 ( V_15 ) ;
if ( V_6 )
goto V_92;
if ( V_15 -> V_28 . V_68 ) {
V_6 = - V_69 ;
goto V_92;
}
V_6 = F_23 ( V_15 , 0xb00030 , V_88 ,
sizeof( V_88 ) ) ;
if ( V_6 )
goto V_92;
V_6 = F_23 ( V_15 , 0xb00000 , V_89 ,
sizeof( V_89 ) ) ;
if ( V_6 )
goto V_92;
V_6 = F_23 ( V_15 , 0xb0001a , V_90 ,
sizeof( V_90 ) ) ;
if ( V_6 )
goto V_92;
switch ( V_86 ) {
case V_49 :
V_87 = 5 ;
break;
case V_47 :
V_87 = 3 ;
break;
case V_43 :
V_87 = 1 ;
break;
}
V_6 = F_23 ( V_15 , 0xb00033 , & V_87 , sizeof( V_87 ) ) ;
if ( V_6 )
goto V_92;
V_6 = F_23 ( V_15 , 0xb00030 , V_91 , sizeof( V_91 ) ) ;
if ( V_6 )
goto V_92;
F_6 ( & V_15 -> V_28 . V_67 , V_17 ) ;
V_15 -> V_28 . V_17 &= ~ V_41 ;
V_15 -> V_28 . V_17 |= V_86 & V_41 ;
F_16 ( V_15 , V_56 ) ;
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
V_92:
F_31 ( V_15 ) ;
return V_6 ;
}
static enum V_93 F_33 ( struct V_94 * V_95 )
{
struct V_14 * V_15 ;
struct V_96 * V_97 = V_95 -> V_97 -> V_98 ;
int V_99 ;
unsigned long V_17 ;
bool V_100 = false ;
V_15 = F_34 ( F_5 ( V_97 , struct V_1 , V_97 ) ) ;
for ( V_99 = 0 ; V_99 < 4 ; ++ V_99 ) {
if ( V_15 -> V_33 [ V_99 ] == V_95 ) {
F_6 ( & V_15 -> V_28 . V_67 , V_17 ) ;
V_100 = V_15 -> V_28 . V_17 & F_35 ( V_99 + 1 ) ;
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
break;
}
}
return V_100 ? V_101 : V_102 ;
}
static void F_36 ( struct V_94 * V_95 ,
enum V_93 V_100 )
{
struct V_14 * V_15 ;
struct V_96 * V_97 = V_95 -> V_97 -> V_98 ;
int V_99 ;
unsigned long V_17 ;
T_2 V_28 , V_103 ;
V_15 = F_34 ( F_5 ( V_97 , struct V_1 , V_97 ) ) ;
for ( V_99 = 0 ; V_99 < 4 ; ++ V_99 ) {
if ( V_15 -> V_33 [ V_99 ] == V_95 ) {
V_103 = F_35 ( V_99 + 1 ) ;
F_6 ( & V_15 -> V_28 . V_67 , V_17 ) ;
V_28 = V_15 -> V_28 . V_17 ;
if ( V_100 == V_102 )
F_13 ( V_15 , V_28 & ~ V_103 ) ;
else
F_13 ( V_15 , V_28 | V_103 ) ;
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
break;
}
}
}
static int F_37 ( struct V_104 * V_97 , void * V_22 ,
struct V_105 * V_106 )
{
struct V_14 * V_15 = F_38 ( V_97 ) ;
T_2 V_100 ;
unsigned long V_17 ;
if ( V_106 -> V_107 . V_30 . V_108 || V_106 -> V_107 . V_30 . V_109 )
V_100 = 1 ;
else
V_100 = 0 ;
F_6 ( & V_15 -> V_28 . V_67 , V_17 ) ;
F_12 ( V_15 , V_100 ) ;
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
return 0 ;
}
static int F_39 ( struct V_104 * V_97 )
{
struct V_14 * V_15 = F_38 ( V_97 ) ;
return F_40 ( V_15 -> V_2 ) ;
}
static void F_41 ( struct V_104 * V_97 )
{
struct V_14 * V_15 = F_38 ( V_97 ) ;
F_42 ( V_15 -> V_2 ) ;
}
static int F_43 ( struct V_104 * V_97 )
{
struct V_14 * V_15 = F_38 ( V_97 ) ;
int V_6 ;
unsigned long V_17 ;
V_6 = F_40 ( V_15 -> V_2 ) ;
if ( V_6 )
return V_6 ;
F_6 ( & V_15 -> V_28 . V_67 , V_17 ) ;
F_18 ( V_15 , true ) ;
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
return 0 ;
}
static void F_44 ( struct V_104 * V_97 )
{
struct V_14 * V_15 = F_38 ( V_97 ) ;
unsigned long V_17 ;
F_6 ( & V_15 -> V_28 . V_67 , V_17 ) ;
F_18 ( V_15 , false ) ;
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
F_42 ( V_15 -> V_2 ) ;
}
static int F_45 ( struct V_104 * V_97 )
{
struct V_14 * V_15 = F_38 ( V_97 ) ;
int V_6 ;
V_6 = F_40 ( V_15 -> V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_32 ( V_15 , V_43 ) ;
if ( V_6 ) {
F_42 ( V_15 -> V_2 ) ;
return V_6 ;
}
return 0 ;
}
static void F_46 ( struct V_104 * V_97 )
{
struct V_14 * V_15 = F_38 ( V_97 ) ;
F_32 ( V_15 , 0 ) ;
F_42 ( V_15 -> V_2 ) ;
}
static void F_47 ( struct V_14 * V_15 , const T_2 * V_110 )
{
F_48 ( V_15 -> V_111 , V_112 [ V_113 ] ,
! ! ( V_110 [ 0 ] & 0x01 ) ) ;
F_48 ( V_15 -> V_111 , V_112 [ V_114 ] ,
! ! ( V_110 [ 0 ] & 0x02 ) ) ;
F_48 ( V_15 -> V_111 , V_112 [ V_115 ] ,
! ! ( V_110 [ 0 ] & 0x04 ) ) ;
F_48 ( V_15 -> V_111 , V_112 [ V_116 ] ,
! ! ( V_110 [ 0 ] & 0x08 ) ) ;
F_48 ( V_15 -> V_111 , V_112 [ V_117 ] ,
! ! ( V_110 [ 0 ] & 0x10 ) ) ;
F_48 ( V_15 -> V_111 , V_112 [ V_118 ] ,
! ! ( V_110 [ 1 ] & 0x01 ) ) ;
F_48 ( V_15 -> V_111 , V_112 [ V_119 ] ,
! ! ( V_110 [ 1 ] & 0x02 ) ) ;
F_48 ( V_15 -> V_111 , V_112 [ V_120 ] ,
! ! ( V_110 [ 1 ] & 0x04 ) ) ;
F_48 ( V_15 -> V_111 , V_112 [ V_121 ] ,
! ! ( V_110 [ 1 ] & 0x08 ) ) ;
F_48 ( V_15 -> V_111 , V_112 [ V_122 ] ,
! ! ( V_110 [ 1 ] & 0x10 ) ) ;
F_48 ( V_15 -> V_111 , V_112 [ V_123 ] ,
! ! ( V_110 [ 1 ] & 0x80 ) ) ;
F_49 ( V_15 -> V_111 ) ;
}
static void F_50 ( struct V_14 * V_15 , const T_2 * V_110 )
{
T_5 V_124 , V_125 , V_126 ;
if ( ! ( V_15 -> V_28 . V_17 & V_44 ) )
return;
V_124 = V_110 [ 2 ] << 2 ;
V_125 = V_110 [ 3 ] << 2 ;
V_126 = V_110 [ 4 ] << 2 ;
V_124 |= ( V_110 [ 0 ] >> 5 ) & 0x3 ;
V_125 |= ( V_110 [ 1 ] >> 4 ) & 0x2 ;
V_126 |= ( V_110 [ 1 ] >> 5 ) & 0x2 ;
F_51 ( V_15 -> V_59 , V_127 , V_124 - 0x200 ) ;
F_51 ( V_15 -> V_59 , V_128 , V_125 - 0x200 ) ;
F_51 ( V_15 -> V_59 , V_129 , V_126 - 0x200 ) ;
F_49 ( V_15 -> V_59 ) ;
}
static void F_52 ( struct V_14 * V_15 , const T_2 * V_40 ,
bool V_130 , T_2 V_131 , T_2 V_132 )
{
T_5 V_124 , V_125 ;
if ( ! ( V_15 -> V_28 . V_17 & V_41 ) )
return;
if ( V_130 ) {
V_124 = V_40 [ 1 ] | ( ( V_40 [ 0 ] & 0x03 ) << 8 ) ;
V_125 = V_40 [ 2 ] | ( ( V_40 [ 0 ] & 0x0c ) << 6 ) ;
} else {
V_124 = V_40 [ 0 ] | ( ( V_40 [ 2 ] & 0x30 ) << 4 ) ;
V_125 = V_40 [ 1 ] | ( ( V_40 [ 2 ] & 0xc0 ) << 2 ) ;
}
F_51 ( V_15 -> V_40 , V_131 , V_124 ) ;
F_51 ( V_15 -> V_40 , V_132 , V_125 ) ;
}
static void F_53 ( struct V_14 * V_15 , const T_2 * V_110 )
{
F_47 ( V_15 , V_110 ) ;
F_16 ( V_15 , V_56 ) ;
F_54 ( V_15 , V_110 [ 2 ] & 0x02 ) ;
if ( F_55 ( V_15 , V_58 , 0 ) ) {
V_15 -> V_28 . V_83 = V_110 [ 5 ] ;
F_56 ( V_15 ) ;
}
}
static void F_57 ( struct V_14 * V_15 , const T_2 * V_110 )
{
T_5 V_63 = V_110 [ 3 ] << 8 | V_110 [ 4 ] ;
T_2 V_23 = ( V_110 [ 2 ] >> 4 ) + 1 ;
T_2 V_133 = V_110 [ 2 ] & 0x0f ;
F_47 ( V_15 , V_110 ) ;
if ( F_55 ( V_15 , V_65 , V_63 ) ) {
if ( V_133 )
V_23 = 0 ;
else if ( V_23 > V_15 -> V_28 . V_71 )
V_23 = V_15 -> V_28 . V_71 ;
V_15 -> V_28 . V_71 = V_23 ;
if ( V_15 -> V_28 . V_72 )
memcpy ( V_15 -> V_28 . V_72 , & V_110 [ 5 ] , V_23 ) ;
F_56 ( V_15 ) ;
}
}
static void F_58 ( struct V_14 * V_15 , const T_2 * V_110 )
{
T_2 V_133 = V_110 [ 3 ] ;
T_2 V_31 = V_110 [ 2 ] ;
F_47 ( V_15 , V_110 ) ;
if ( F_55 ( V_15 , V_31 , 0 ) ) {
V_15 -> V_28 . V_68 = V_133 ;
F_56 ( V_15 ) ;
} else if ( V_133 ) {
F_9 ( V_15 -> V_2 , L_5 , V_133 ,
V_31 ) ;
}
}
static void F_59 ( struct V_14 * V_15 , const T_2 * V_110 )
{
F_47 ( V_15 , V_110 ) ;
F_50 ( V_15 , V_110 ) ;
}
static void F_60 ( struct V_14 * V_15 , const T_2 * V_110 )
{
F_47 ( V_15 , V_110 ) ;
F_61 ( V_15 , & V_110 [ 2 ] ) ;
}
static void F_62 ( struct V_14 * V_15 , const T_2 * V_110 )
{
F_47 ( V_15 , V_110 ) ;
F_50 ( V_15 , V_110 ) ;
F_63 ( V_15 , & V_110 [ 5 ] , false ) ;
F_64 ( V_15 , & V_110 [ 8 ] , false ) ;
F_65 ( V_15 , & V_110 [ 11 ] , false ) ;
F_66 ( V_15 , & V_110 [ 14 ] , false ) ;
F_49 ( V_15 -> V_40 ) ;
}
static void F_67 ( struct V_14 * V_15 , const T_2 * V_110 )
{
F_47 ( V_15 , V_110 ) ;
F_61 ( V_15 , & V_110 [ 2 ] ) ;
}
static void F_68 ( struct V_14 * V_15 , const T_2 * V_110 )
{
F_47 ( V_15 , V_110 ) ;
F_63 ( V_15 , & V_110 [ 2 ] , false ) ;
F_64 ( V_15 , & V_110 [ 4 ] , true ) ;
F_65 ( V_15 , & V_110 [ 7 ] , false ) ;
F_66 ( V_15 , & V_110 [ 9 ] , true ) ;
F_49 ( V_15 -> V_40 ) ;
F_61 ( V_15 , & V_110 [ 12 ] ) ;
}
static void F_69 ( struct V_14 * V_15 , const T_2 * V_110 )
{
F_47 ( V_15 , V_110 ) ;
F_50 ( V_15 , V_110 ) ;
F_61 ( V_15 , & V_110 [ 5 ] ) ;
}
static void F_70 ( struct V_14 * V_15 , const T_2 * V_110 )
{
F_47 ( V_15 , V_110 ) ;
F_50 ( V_15 , V_110 ) ;
F_63 ( V_15 , & V_110 [ 5 ] , false ) ;
F_64 ( V_15 , & V_110 [ 7 ] , true ) ;
F_65 ( V_15 , & V_110 [ 10 ] , false ) ;
F_66 ( V_15 , & V_110 [ 12 ] , true ) ;
F_49 ( V_15 -> V_40 ) ;
F_61 ( V_15 , & V_110 [ 15 ] ) ;
}
static void F_71 ( struct V_14 * V_15 , const T_2 * V_110 )
{
F_61 ( V_15 , V_110 ) ;
}
static void F_72 ( struct V_14 * V_15 , const T_2 * V_110 )
{
F_47 ( V_15 , V_110 ) ;
V_15 -> V_28 . V_134 [ 0 ] = V_110 [ 2 ] ;
V_15 -> V_28 . V_134 [ 1 ] = ( V_110 [ 0 ] >> 1 ) & ( 0x10 | 0x20 ) ;
V_15 -> V_28 . V_134 [ 1 ] |= ( V_110 [ 1 ] << 1 ) & ( 0x40 | 0x80 ) ;
F_63 ( V_15 , & V_110 [ 3 ] , false ) ;
F_64 ( V_15 , & V_110 [ 12 ] , false ) ;
F_49 ( V_15 -> V_40 ) ;
}
static void F_73 ( struct V_14 * V_15 , const T_2 * V_110 )
{
T_2 V_5 [ 5 ] ;
F_47 ( V_15 , V_110 ) ;
V_15 -> V_28 . V_134 [ 1 ] |= ( V_110 [ 0 ] >> 5 ) & ( 0x01 | 0x02 ) ;
V_15 -> V_28 . V_134 [ 1 ] |= ( V_110 [ 1 ] >> 3 ) & ( 0x04 | 0x08 ) ;
V_5 [ 0 ] = 0 ;
V_5 [ 1 ] = 0 ;
V_5 [ 2 ] = V_15 -> V_28 . V_134 [ 0 ] ;
V_5 [ 3 ] = V_110 [ 2 ] ;
V_5 [ 4 ] = V_15 -> V_28 . V_134 [ 1 ] ;
F_50 ( V_15 , V_5 ) ;
F_65 ( V_15 , & V_110 [ 3 ] , false ) ;
F_66 ( V_15 , & V_110 [ 12 ] , false ) ;
F_49 ( V_15 -> V_40 ) ;
}
static int F_74 ( struct V_1 * V_2 , struct V_135 * V_136 ,
T_6 * V_137 , int V_23 )
{
struct V_14 * V_15 = F_34 ( V_2 ) ;
struct V_138 * V_139 ;
int V_99 ;
unsigned long V_17 ;
bool V_140 = false ;
if ( V_23 < 1 )
return - V_85 ;
F_6 ( & V_15 -> V_28 . V_67 , V_17 ) ;
for ( V_99 = 0 ; V_141 [ V_99 ] . V_142 ; ++ V_99 ) {
V_139 = & V_141 [ V_99 ] ;
if ( V_139 -> V_142 == V_137 [ 0 ] && V_139 -> V_23 < V_23 ) {
V_139 -> V_143 ( V_15 , & V_137 [ 1 ] ) ;
V_140 = true ;
}
}
if ( ! V_140 )
F_9 ( V_2 , L_6 , V_137 [ 0 ] ,
V_23 ) ;
F_7 ( & V_15 -> V_28 . V_67 , V_17 ) ;
return 0 ;
}
static void F_75 ( struct V_14 * V_15 )
{
int V_99 ;
struct V_94 * V_144 ;
for ( V_99 = 0 ; V_99 < 4 ; ++ V_99 ) {
if ( V_15 -> V_33 [ V_99 ] ) {
V_144 = V_15 -> V_33 [ V_99 ] ;
V_15 -> V_33 [ V_99 ] = NULL ;
F_76 ( V_144 ) ;
F_3 ( V_144 ) ;
}
}
}
static int F_77 ( struct V_14 * V_15 )
{
int V_99 , V_6 ;
struct V_96 * V_97 = & V_15 -> V_2 -> V_97 ;
T_3 V_145 = strlen ( F_78 ( V_97 ) ) + 9 ;
struct V_94 * V_144 ;
char * V_146 ;
for ( V_99 = 0 ; V_99 < 4 ; ++ V_99 ) {
V_144 = F_79 ( sizeof( struct V_94 ) + V_145 , V_9 ) ;
if ( ! V_144 ) {
V_6 = - V_10 ;
goto V_133;
}
V_146 = ( void * ) & V_144 [ 1 ] ;
snprintf ( V_146 , V_145 , L_7 , F_78 ( V_97 ) , V_99 ) ;
V_144 -> V_146 = V_146 ;
V_144 -> V_147 = 0 ;
V_144 -> V_148 = 1 ;
V_144 -> V_149 = F_33 ;
V_144 -> V_150 = F_36 ;
V_6 = F_80 ( V_97 , V_144 ) ;
if ( V_6 ) {
F_3 ( V_144 ) ;
goto V_133;
}
V_15 -> V_33 [ V_99 ] = V_144 ;
}
return 0 ;
V_133:
F_75 ( V_15 ) ;
return V_6 ;
}
static struct V_14 * F_81 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_99 ;
V_15 = F_79 ( sizeof( * V_15 ) , V_9 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_111 = F_82 () ;
if ( ! V_15 -> V_111 )
goto V_133;
V_15 -> V_2 = V_2 ;
F_83 ( V_2 , V_15 ) ;
F_84 ( V_15 -> V_111 , V_15 ) ;
V_15 -> V_111 -> V_151 = F_39 ;
V_15 -> V_111 -> V_152 = F_41 ;
V_15 -> V_111 -> V_97 . V_98 = & V_15 -> V_2 -> V_97 ;
V_15 -> V_111 -> V_142 . V_153 = V_15 -> V_2 -> V_154 ;
V_15 -> V_111 -> V_142 . V_155 = V_15 -> V_2 -> V_155 ;
V_15 -> V_111 -> V_142 . V_156 = V_15 -> V_2 -> V_156 ;
V_15 -> V_111 -> V_142 . V_157 = V_15 -> V_2 -> V_157 ;
V_15 -> V_111 -> V_146 = V_158 ;
F_85 ( V_159 , V_15 -> V_111 -> V_160 ) ;
for ( V_99 = 0 ; V_99 < V_161 ; ++ V_99 )
F_85 ( V_112 [ V_99 ] , V_15 -> V_111 -> V_162 ) ;
F_85 ( V_163 , V_15 -> V_111 -> V_164 ) ;
if ( F_86 ( V_15 -> V_111 , NULL , F_37 ) )
goto V_165;
V_15 -> V_59 = F_82 () ;
if ( ! V_15 -> V_59 )
goto V_165;
F_84 ( V_15 -> V_59 , V_15 ) ;
V_15 -> V_59 -> V_151 = F_43 ;
V_15 -> V_59 -> V_152 = F_44 ;
V_15 -> V_59 -> V_97 . V_98 = & V_15 -> V_2 -> V_97 ;
V_15 -> V_59 -> V_142 . V_153 = V_15 -> V_2 -> V_154 ;
V_15 -> V_59 -> V_142 . V_155 = V_15 -> V_2 -> V_155 ;
V_15 -> V_59 -> V_142 . V_156 = V_15 -> V_2 -> V_156 ;
V_15 -> V_59 -> V_142 . V_157 = V_15 -> V_2 -> V_157 ;
V_15 -> V_59 -> V_146 = V_158 L_8 ;
F_85 ( V_166 , V_15 -> V_59 -> V_160 ) ;
F_85 ( V_127 , V_15 -> V_59 -> V_167 ) ;
F_85 ( V_128 , V_15 -> V_59 -> V_167 ) ;
F_85 ( V_129 , V_15 -> V_59 -> V_167 ) ;
F_87 ( V_15 -> V_59 , V_127 , - 500 , 500 , 2 , 4 ) ;
F_87 ( V_15 -> V_59 , V_128 , - 500 , 500 , 2 , 4 ) ;
F_87 ( V_15 -> V_59 , V_129 , - 500 , 500 , 2 , 4 ) ;
V_15 -> V_40 = F_82 () ;
if ( ! V_15 -> V_40 )
goto V_168;
F_84 ( V_15 -> V_40 , V_15 ) ;
V_15 -> V_40 -> V_151 = F_45 ;
V_15 -> V_40 -> V_152 = F_46 ;
V_15 -> V_40 -> V_97 . V_98 = & V_15 -> V_2 -> V_97 ;
V_15 -> V_40 -> V_142 . V_153 = V_15 -> V_2 -> V_154 ;
V_15 -> V_40 -> V_142 . V_155 = V_15 -> V_2 -> V_155 ;
V_15 -> V_40 -> V_142 . V_156 = V_15 -> V_2 -> V_156 ;
V_15 -> V_40 -> V_142 . V_157 = V_15 -> V_2 -> V_157 ;
V_15 -> V_40 -> V_146 = V_158 L_9 ;
F_85 ( V_166 , V_15 -> V_40 -> V_160 ) ;
F_85 ( V_169 , V_15 -> V_40 -> V_167 ) ;
F_85 ( V_170 , V_15 -> V_40 -> V_167 ) ;
F_85 ( V_171 , V_15 -> V_40 -> V_167 ) ;
F_85 ( V_172 , V_15 -> V_40 -> V_167 ) ;
F_85 ( V_173 , V_15 -> V_40 -> V_167 ) ;
F_85 ( V_174 , V_15 -> V_40 -> V_167 ) ;
F_85 ( V_175 , V_15 -> V_40 -> V_167 ) ;
F_85 ( V_176 , V_15 -> V_40 -> V_167 ) ;
F_87 ( V_15 -> V_40 , V_169 , 0 , 1023 , 2 , 4 ) ;
F_87 ( V_15 -> V_40 , V_170 , 0 , 767 , 2 , 4 ) ;
F_87 ( V_15 -> V_40 , V_171 , 0 , 1023 , 2 , 4 ) ;
F_87 ( V_15 -> V_40 , V_172 , 0 , 767 , 2 , 4 ) ;
F_87 ( V_15 -> V_40 , V_173 , 0 , 1023 , 2 , 4 ) ;
F_87 ( V_15 -> V_40 , V_174 , 0 , 767 , 2 , 4 ) ;
F_87 ( V_15 -> V_40 , V_175 , 0 , 1023 , 2 , 4 ) ;
F_87 ( V_15 -> V_40 , V_176 , 0 , 767 , 2 , 4 ) ;
F_88 ( & V_15 -> V_18 ) ;
F_89 ( & V_15 -> V_16 , F_4 ) ;
F_88 ( & V_15 -> V_28 . V_67 ) ;
F_90 ( & V_15 -> V_28 . V_177 ) ;
F_91 ( & V_15 -> V_28 . V_178 ) ;
V_15 -> V_28 . V_55 = V_54 ;
return V_15 ;
V_168:
F_92 ( V_15 -> V_59 ) ;
V_165:
F_92 ( V_15 -> V_111 ) ;
V_133:
F_3 ( V_15 ) ;
return NULL ;
}
static void F_93 ( struct V_14 * V_15 )
{
F_94 ( V_15 ) ;
F_95 ( V_15 ) ;
F_75 ( V_15 ) ;
F_96 ( & V_15 -> V_79 ) ;
F_97 ( V_15 -> V_59 ) ;
F_97 ( V_15 -> V_40 ) ;
F_97 ( V_15 -> V_111 ) ;
F_98 ( & V_15 -> V_16 ) ;
F_99 ( V_15 -> V_2 ) ;
F_3 ( V_15 ) ;
}
static int F_100 ( struct V_1 * V_2 ,
const struct V_179 * V_142 )
{
struct V_14 * V_15 ;
int V_6 ;
V_2 -> V_180 |= V_181 ;
V_15 = F_81 ( V_2 ) ;
if ( ! V_15 ) {
F_101 ( V_2 , L_10 ) ;
return - V_10 ;
}
V_6 = F_102 ( V_2 ) ;
if ( V_6 ) {
F_101 ( V_2 , L_11 ) ;
goto V_133;
}
V_6 = F_103 ( V_2 , V_182 ) ;
if ( V_6 ) {
F_101 ( V_2 , L_12 ) ;
goto V_133;
}
V_6 = F_104 ( V_15 -> V_59 ) ;
if ( V_6 ) {
F_101 ( V_2 , L_13 ) ;
goto V_183;
}
V_6 = F_104 ( V_15 -> V_40 ) ;
if ( V_6 ) {
F_101 ( V_2 , L_13 ) ;
goto V_168;
}
V_6 = F_104 ( V_15 -> V_111 ) ;
if ( V_6 ) {
F_101 ( V_2 , L_13 ) ;
goto V_165;
}
V_15 -> V_79 . V_184 = V_185 ;
V_15 -> V_79 . V_186 = F_105 ( V_185 ) ;
V_15 -> V_79 . V_187 = F_29 ;
V_15 -> V_79 . V_146 = L_14 ;
V_15 -> V_79 . type = V_188 ;
V_15 -> V_79 . V_189 = 0 ;
V_6 = F_106 ( & V_15 -> V_2 -> V_97 , & V_15 -> V_79 ) ;
if ( V_6 ) {
F_101 ( V_2 , L_15 ) ;
goto V_190;
}
F_107 ( & V_15 -> V_79 , & V_2 -> V_97 ) ;
V_6 = F_77 ( V_15 ) ;
if ( V_6 )
goto V_191;
V_6 = F_108 ( V_15 ) ;
if ( V_6 )
goto V_191;
V_6 = F_109 ( V_15 ) ;
if ( V_6 )
goto V_191;
F_110 ( V_2 , L_16 ) ;
F_111 ( & V_15 -> V_28 . V_67 ) ;
F_13 ( V_15 , V_36 ) ;
F_112 ( & V_15 -> V_28 . V_67 ) ;
return 0 ;
V_191:
F_93 ( V_15 ) ;
return V_6 ;
V_190:
F_97 ( V_15 -> V_111 ) ;
V_15 -> V_111 = NULL ;
V_165:
F_97 ( V_15 -> V_40 ) ;
V_15 -> V_40 = NULL ;
V_168:
F_97 ( V_15 -> V_59 ) ;
V_15 -> V_59 = NULL ;
V_183:
F_99 ( V_2 ) ;
V_133:
F_92 ( V_15 -> V_40 ) ;
F_92 ( V_15 -> V_59 ) ;
F_92 ( V_15 -> V_111 ) ;
F_3 ( V_15 ) ;
return V_6 ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_34 ( V_2 ) ;
F_110 ( V_2 , L_17 ) ;
F_93 ( V_15 ) ;
}
