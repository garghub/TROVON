static inline bool F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 )
{
return V_2 -> V_5 . V_3 == V_3 && V_2 -> V_5 . V_4 == V_4 ;
}
static inline void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_3 = V_6 ;
F_3 ( & V_2 -> V_5 . V_7 ) ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return F_5 ( & V_2 -> V_5 . V_8 ) ? - V_9 : 0 ;
}
static inline void F_6 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 )
{
F_7 ( V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_3 = V_3 ;
V_2 -> V_5 . V_4 = V_4 ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_5 . V_8 ) ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_11 ( & V_2 -> V_5 . V_7 , V_11 ) ;
if ( V_10 < 0 )
return - V_9 ;
else if ( V_10 == 0 )
return - V_12 ;
else
return 0 ;
}
static T_2 F_12 ( struct V_13 * V_14 , T_3 * V_15 ,
T_4 V_16 )
{
T_3 * V_17 ;
T_2 V_10 ;
if ( ! V_14 -> V_18 )
return - V_19 ;
V_17 = F_13 ( V_15 , V_16 , V_20 ) ;
if ( ! V_17 )
return - V_21 ;
V_10 = V_14 -> V_18 ( V_14 , V_17 , V_16 , V_22 ) ;
F_14 ( V_17 ) ;
return V_10 ;
}
static void F_15 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_16 ( V_24 , struct V_1 ,
V_25 ) ;
unsigned long V_26 ;
F_17 ( & V_2 -> V_27 , V_26 ) ;
while ( V_2 -> V_28 != V_2 -> V_29 ) {
F_18 ( & V_2 -> V_27 , V_26 ) ;
F_12 ( V_2 -> V_14 , V_2 -> V_30 [ V_2 -> V_29 ] . V_31 ,
V_2 -> V_30 [ V_2 -> V_29 ] . V_32 ) ;
F_17 ( & V_2 -> V_27 , V_26 ) ;
V_2 -> V_29 = ( V_2 -> V_29 + 1 ) % V_33 ;
}
F_18 ( & V_2 -> V_27 , V_26 ) ;
}
static void F_19 ( struct V_1 * V_2 , const T_3 * V_15 ,
T_4 V_16 )
{
unsigned long V_26 ;
T_3 V_34 ;
if ( V_16 > V_35 ) {
F_20 ( V_2 -> V_14 , L_1 ) ;
return;
}
F_17 ( & V_2 -> V_27 , V_26 ) ;
memcpy ( V_2 -> V_30 [ V_2 -> V_28 ] . V_31 , V_15 , V_16 ) ;
V_2 -> V_30 [ V_2 -> V_28 ] . V_32 = V_16 ;
V_34 = ( V_2 -> V_28 + 1 ) % V_33 ;
if ( V_2 -> V_28 == V_2 -> V_29 ) {
V_2 -> V_28 = V_34 ;
F_21 ( & V_2 -> V_25 ) ;
} else if ( V_34 != V_2 -> V_29 ) {
V_2 -> V_28 = V_34 ;
} else {
F_20 ( V_2 -> V_14 , L_2 ) ;
}
F_18 ( & V_2 -> V_27 , V_26 ) ;
}
static inline void F_22 ( struct V_1 * V_2 , T_3 * V_36 )
{
if ( V_2 -> V_5 . V_26 & V_37 )
* V_36 |= 0x01 ;
}
static void F_23 ( struct V_1 * V_2 , T_3 V_38 )
{
T_3 V_3 [ 2 ] ;
V_38 = ! ! V_38 ;
if ( V_38 == ! ! ( V_2 -> V_5 . V_26 & V_37 ) )
return;
if ( V_38 )
V_2 -> V_5 . V_26 |= V_37 ;
else
V_2 -> V_5 . V_26 &= ~ V_37 ;
V_3 [ 0 ] = V_39 ;
V_3 [ 1 ] = 0 ;
F_22 ( V_2 , & V_3 [ 1 ] ) ;
F_19 ( V_2 , V_3 , sizeof( V_3 ) ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_40 )
{
T_3 V_3 [ 2 ] ;
V_40 &= V_41 ;
if ( ( V_2 -> V_5 . V_26 & V_41 ) == V_40 )
return;
V_2 -> V_5 . V_26 = ( V_2 -> V_5 . V_26 & ~ V_41 ) | V_40 ;
V_3 [ 0 ] = V_42 ;
V_3 [ 1 ] = 0 ;
if ( V_40 & V_43 )
V_3 [ 1 ] |= 0x10 ;
if ( V_40 & V_44 )
V_3 [ 1 ] |= 0x20 ;
if ( V_40 & V_45 )
V_3 [ 1 ] |= 0x40 ;
if ( V_40 & V_46 )
V_3 [ 1 ] |= 0x80 ;
F_22 ( V_2 , & V_3 [ 1 ] ) ;
F_19 ( V_2 , V_3 , sizeof( V_3 ) ) ;
}
static T_3 F_25 ( struct V_1 * V_2 )
{
T_3 V_47 = V_2 -> V_5 . V_26 & V_48 ;
if ( V_47 == V_49 ) {
if ( V_2 -> V_5 . V_26 & V_50 )
return V_51 ;
else
return V_52 ;
} else if ( V_47 == V_53 ) {
return V_54 ;
} else if ( V_47 == V_55 ) {
return V_56 ;
} else {
if ( V_2 -> V_5 . V_26 & V_50 )
return V_57 ;
else
return V_58 ;
}
}
static void F_26 ( struct V_1 * V_2 , T_3 V_59 )
{
T_3 V_3 [ 3 ] ;
if ( V_59 == V_6 )
V_59 = F_25 ( V_2 ) ;
V_3 [ 0 ] = V_60 ;
V_3 [ 1 ] = 0 ;
V_3 [ 2 ] = V_59 ;
F_22 ( V_2 , & V_3 [ 1 ] ) ;
F_19 ( V_2 , V_3 , sizeof( V_3 ) ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_3 V_3 [ 2 ] ;
V_3 [ 0 ] = V_61 ;
V_3 [ 1 ] = 0 ;
F_22 ( V_2 , & V_3 [ 1 ] ) ;
F_19 ( V_2 , V_3 , sizeof( V_3 ) ) ;
}
static void F_28 ( struct V_1 * V_2 , T_3 V_62 )
{
V_62 = ! ! V_62 ;
if ( V_62 == ! ! ( V_2 -> V_5 . V_26 & V_50 ) )
return;
if ( V_62 )
V_2 -> V_5 . V_26 |= V_50 ;
else
V_2 -> V_5 . V_26 &= ~ V_50 ;
F_26 ( V_2 , V_6 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_3 V_26 )
{
T_3 V_3 [ 2 ] ;
V_3 [ 0 ] = V_63 ;
V_3 [ 1 ] = V_26 ;
F_22 ( V_2 , & V_3 [ 1 ] ) ;
F_19 ( V_2 , V_3 , sizeof( V_3 ) ) ;
}
static void F_30 ( struct V_1 * V_2 , T_3 V_26 )
{
T_3 V_3 [ 2 ] ;
V_3 [ 0 ] = V_64 ;
V_3 [ 1 ] = V_26 ;
F_22 ( V_2 , & V_3 [ 1 ] ) ;
F_19 ( V_2 , V_3 , sizeof( V_3 ) ) ;
}
static void F_31 ( struct V_1 * V_2 , bool V_65 ,
T_1 V_66 , const T_3 * V_17 , T_3 V_32 )
{
T_3 V_3 [ 22 ] ;
if ( V_32 > 16 || V_32 == 0 ) {
F_20 ( V_2 -> V_14 , L_3 , V_32 ) ;
return;
}
memset ( V_3 , 0 , sizeof( V_3 ) ) ;
V_3 [ 0 ] = V_67 ;
V_3 [ 2 ] = ( V_66 >> 16 ) & 0xff ;
V_3 [ 3 ] = ( V_66 >> 8 ) & 0xff ;
V_3 [ 4 ] = V_66 & 0xff ;
V_3 [ 5 ] = V_32 ;
memcpy ( & V_3 [ 6 ] , V_17 , V_32 ) ;
if ( ! V_65 )
V_3 [ 1 ] |= 0x04 ;
F_22 ( V_2 , & V_3 [ 1 ] ) ;
F_19 ( V_2 , V_3 , sizeof( V_3 ) ) ;
}
static int F_32 ( struct V_1 * V_2 , T_1 V_66 ,
const T_3 * V_68 , T_3 V_32 )
{
unsigned long V_26 ;
int V_10 ;
F_17 ( & V_2 -> V_5 . V_69 , V_26 ) ;
F_6 ( V_2 , V_67 , 0 ) ;
F_33 ( V_2 , V_66 , V_68 , V_32 ) ;
F_18 ( & V_2 -> V_5 . V_69 , V_26 ) ;
V_10 = F_10 ( V_2 ) ;
if ( ! V_10 && V_2 -> V_5 . V_70 )
V_10 = - V_12 ;
return V_10 ;
}
static int F_34 ( struct V_71 * V_72 ,
enum V_73 V_74 ,
union V_75 * V_76 )
{
struct V_1 * V_2 = F_16 ( V_72 ,
struct V_1 , V_77 ) ;
int V_10 = 0 , V_5 ;
unsigned long V_26 ;
V_10 = F_4 ( V_2 ) ;
if ( V_10 )
return V_10 ;
F_17 ( & V_2 -> V_5 . V_69 , V_26 ) ;
F_6 ( V_2 , V_61 , 0 ) ;
F_27 ( V_2 ) ;
F_18 ( & V_2 -> V_5 . V_69 , V_26 ) ;
V_10 = F_10 ( V_2 ) ;
V_5 = V_2 -> V_5 . V_78 ;
F_8 ( V_2 ) ;
if ( V_10 )
return V_10 ;
switch ( V_74 ) {
case V_79 :
V_76 -> V_80 = V_5 * 100 / 255 ;
break;
default:
V_10 = - V_81 ;
break;
}
return V_10 ;
}
static int F_35 ( struct V_1 * V_2 , T_5 V_82 )
{
int V_10 ;
unsigned long V_26 ;
T_3 V_83 = 0 ;
static const T_3 V_84 [] = { 0x01 } ;
static const T_3 V_85 [] = { 0x02 , 0x00 , 0x00 , 0x71 , 0x01 ,
0x00 , 0xaa , 0x00 , 0x64 } ;
static const T_3 V_86 [] = { 0x63 , 0x03 } ;
static const T_3 V_87 [] = { 0x08 } ;
F_17 ( & V_2 -> V_5 . V_69 , V_26 ) ;
if ( V_82 == ( V_2 -> V_5 . V_26 & V_48 ) ) {
F_18 ( & V_2 -> V_5 . V_69 , V_26 ) ;
return 0 ;
}
if ( V_82 == 0 ) {
V_2 -> V_5 . V_26 &= ~ V_48 ;
F_29 ( V_2 , 0 ) ;
F_30 ( V_2 , 0 ) ;
F_26 ( V_2 , V_6 ) ;
F_18 ( & V_2 -> V_5 . V_69 , V_26 ) ;
return 0 ;
}
F_18 ( & V_2 -> V_5 . V_69 , V_26 ) ;
V_10 = F_4 ( V_2 ) ;
if ( V_10 )
return V_10 ;
F_17 ( & V_2 -> V_5 . V_69 , V_26 ) ;
F_6 ( V_2 , V_63 , 0 ) ;
F_29 ( V_2 , 0x06 ) ;
F_18 ( & V_2 -> V_5 . V_69 , V_26 ) ;
V_10 = F_10 ( V_2 ) ;
if ( V_10 )
goto V_88;
if ( V_2 -> V_5 . V_70 ) {
V_10 = - V_12 ;
goto V_88;
}
F_17 ( & V_2 -> V_5 . V_69 , V_26 ) ;
F_6 ( V_2 , V_64 , 0 ) ;
F_30 ( V_2 , 0x06 ) ;
F_18 ( & V_2 -> V_5 . V_69 , V_26 ) ;
V_10 = F_10 ( V_2 ) ;
if ( V_10 )
goto V_88;
if ( V_2 -> V_5 . V_70 ) {
V_10 = - V_12 ;
goto V_88;
}
V_10 = F_32 ( V_2 , 0xb00030 , V_84 ,
sizeof( V_84 ) ) ;
if ( V_10 )
goto V_88;
V_10 = F_32 ( V_2 , 0xb00000 , V_85 ,
sizeof( V_85 ) ) ;
if ( V_10 )
goto V_88;
V_10 = F_32 ( V_2 , 0xb0001a , V_86 ,
sizeof( V_86 ) ) ;
if ( V_10 )
goto V_88;
switch ( V_82 ) {
case V_55 :
V_83 = 5 ;
break;
case V_53 :
V_83 = 3 ;
break;
case V_49 :
V_83 = 1 ;
break;
}
V_10 = F_32 ( V_2 , 0xb00033 , & V_83 , sizeof( V_83 ) ) ;
if ( V_10 )
goto V_88;
V_10 = F_32 ( V_2 , 0xb00030 , V_87 , sizeof( V_87 ) ) ;
if ( V_10 )
goto V_88;
F_17 ( & V_2 -> V_5 . V_69 , V_26 ) ;
V_2 -> V_5 . V_26 &= ~ V_48 ;
V_2 -> V_5 . V_26 |= V_82 & V_48 ;
F_26 ( V_2 , V_6 ) ;
F_18 ( & V_2 -> V_5 . V_69 , V_26 ) ;
V_88:
F_8 ( V_2 ) ;
return V_10 ;
}
static enum V_89 F_36 ( struct V_90 * V_91 )
{
struct V_1 * V_2 ;
struct V_92 * V_93 = V_91 -> V_93 -> V_94 ;
int V_95 ;
unsigned long V_26 ;
bool V_96 = false ;
V_2 = F_37 ( F_16 ( V_93 , struct V_13 , V_93 ) ) ;
for ( V_95 = 0 ; V_95 < 4 ; ++ V_95 ) {
if ( V_2 -> V_40 [ V_95 ] == V_91 ) {
F_17 ( & V_2 -> V_5 . V_69 , V_26 ) ;
V_96 = V_2 -> V_5 . V_26 & F_38 ( V_95 + 1 ) ;
F_18 ( & V_2 -> V_5 . V_69 , V_26 ) ;
break;
}
}
return V_96 ? V_97 : V_98 ;
}
static void F_39 ( struct V_90 * V_91 ,
enum V_89 V_96 )
{
struct V_1 * V_2 ;
struct V_92 * V_93 = V_91 -> V_93 -> V_94 ;
int V_95 ;
unsigned long V_26 ;
T_3 V_5 , V_99 ;
V_2 = F_37 ( F_16 ( V_93 , struct V_13 , V_93 ) ) ;
for ( V_95 = 0 ; V_95 < 4 ; ++ V_95 ) {
if ( V_2 -> V_40 [ V_95 ] == V_91 ) {
V_99 = F_38 ( V_95 + 1 ) ;
F_17 ( & V_2 -> V_5 . V_69 , V_26 ) ;
V_5 = V_2 -> V_5 . V_26 ;
if ( V_96 == V_98 )
F_24 ( V_2 , V_5 & ~ V_99 ) ;
else
F_24 ( V_2 , V_5 | V_99 ) ;
F_18 ( & V_2 -> V_5 . V_69 , V_26 ) ;
break;
}
}
}
static int F_40 ( struct V_100 * V_93 , void * V_31 ,
struct V_101 * V_102 )
{
struct V_1 * V_2 = F_41 ( V_93 ) ;
T_3 V_96 ;
unsigned long V_26 ;
if ( V_102 -> V_103 . V_38 . V_104 || V_102 -> V_103 . V_38 . V_105 )
V_96 = 1 ;
else
V_96 = 0 ;
F_17 ( & V_2 -> V_5 . V_69 , V_26 ) ;
F_23 ( V_2 , V_96 ) ;
F_18 ( & V_2 -> V_5 . V_69 , V_26 ) ;
return 0 ;
}
static int F_42 ( struct V_100 * V_93 )
{
struct V_1 * V_2 = F_41 ( V_93 ) ;
return F_43 ( V_2 -> V_14 ) ;
}
static void F_44 ( struct V_100 * V_93 )
{
struct V_1 * V_2 = F_41 ( V_93 ) ;
F_45 ( V_2 -> V_14 ) ;
}
static int F_46 ( struct V_100 * V_93 )
{
struct V_1 * V_2 = F_41 ( V_93 ) ;
int V_10 ;
unsigned long V_26 ;
V_10 = F_43 ( V_2 -> V_14 ) ;
if ( V_10 )
return V_10 ;
F_17 ( & V_2 -> V_5 . V_69 , V_26 ) ;
F_28 ( V_2 , true ) ;
F_18 ( & V_2 -> V_5 . V_69 , V_26 ) ;
return 0 ;
}
static void F_47 ( struct V_100 * V_93 )
{
struct V_1 * V_2 = F_41 ( V_93 ) ;
unsigned long V_26 ;
F_17 ( & V_2 -> V_5 . V_69 , V_26 ) ;
F_28 ( V_2 , false ) ;
F_18 ( & V_2 -> V_5 . V_69 , V_26 ) ;
F_45 ( V_2 -> V_14 ) ;
}
static int F_48 ( struct V_100 * V_93 )
{
struct V_1 * V_2 = F_41 ( V_93 ) ;
int V_10 ;
V_10 = F_43 ( V_2 -> V_14 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_35 ( V_2 , V_49 ) ;
if ( V_10 ) {
F_45 ( V_2 -> V_14 ) ;
return V_10 ;
}
return 0 ;
}
static void F_49 ( struct V_100 * V_93 )
{
struct V_1 * V_2 = F_41 ( V_93 ) ;
F_35 ( V_2 , 0 ) ;
F_45 ( V_2 -> V_14 ) ;
}
static void F_50 ( struct V_1 * V_2 , const T_3 * V_106 )
{
F_51 ( V_2 -> V_107 , V_108 [ V_109 ] ,
! ! ( V_106 [ 0 ] & 0x01 ) ) ;
F_51 ( V_2 -> V_107 , V_108 [ V_110 ] ,
! ! ( V_106 [ 0 ] & 0x02 ) ) ;
F_51 ( V_2 -> V_107 , V_108 [ V_111 ] ,
! ! ( V_106 [ 0 ] & 0x04 ) ) ;
F_51 ( V_2 -> V_107 , V_108 [ V_112 ] ,
! ! ( V_106 [ 0 ] & 0x08 ) ) ;
F_51 ( V_2 -> V_107 , V_108 [ V_113 ] ,
! ! ( V_106 [ 0 ] & 0x10 ) ) ;
F_51 ( V_2 -> V_107 , V_108 [ V_114 ] ,
! ! ( V_106 [ 1 ] & 0x01 ) ) ;
F_51 ( V_2 -> V_107 , V_108 [ V_115 ] ,
! ! ( V_106 [ 1 ] & 0x02 ) ) ;
F_51 ( V_2 -> V_107 , V_108 [ V_116 ] ,
! ! ( V_106 [ 1 ] & 0x04 ) ) ;
F_51 ( V_2 -> V_107 , V_108 [ V_117 ] ,
! ! ( V_106 [ 1 ] & 0x08 ) ) ;
F_51 ( V_2 -> V_107 , V_108 [ V_118 ] ,
! ! ( V_106 [ 1 ] & 0x10 ) ) ;
F_51 ( V_2 -> V_107 , V_108 [ V_119 ] ,
! ! ( V_106 [ 1 ] & 0x80 ) ) ;
F_52 ( V_2 -> V_107 ) ;
}
static void F_53 ( struct V_1 * V_2 , const T_3 * V_106 )
{
T_5 V_120 , V_121 , V_122 ;
if ( ! ( V_2 -> V_5 . V_26 & V_50 ) )
return;
V_120 = V_106 [ 2 ] << 2 ;
V_121 = V_106 [ 3 ] << 2 ;
V_122 = V_106 [ 4 ] << 2 ;
V_120 |= ( V_106 [ 0 ] >> 5 ) & 0x3 ;
V_121 |= ( V_106 [ 1 ] >> 4 ) & 0x2 ;
V_122 |= ( V_106 [ 1 ] >> 5 ) & 0x2 ;
F_54 ( V_2 -> V_62 , V_123 , V_120 - 0x200 ) ;
F_54 ( V_2 -> V_62 , V_124 , V_121 - 0x200 ) ;
F_54 ( V_2 -> V_62 , V_125 , V_122 - 0x200 ) ;
F_52 ( V_2 -> V_62 ) ;
}
static void F_55 ( struct V_1 * V_2 , const T_3 * V_47 ,
bool V_126 , T_3 V_127 , T_3 V_128 )
{
T_5 V_120 , V_121 ;
if ( ! ( V_2 -> V_5 . V_26 & V_48 ) )
return;
if ( V_126 ) {
V_120 = V_47 [ 1 ] << 2 ;
V_121 = V_47 [ 2 ] << 2 ;
V_120 |= V_47 [ 0 ] & 0x3 ;
V_121 |= ( V_47 [ 0 ] >> 2 ) & 0x3 ;
} else {
V_120 = V_47 [ 0 ] << 2 ;
V_121 = V_47 [ 1 ] << 2 ;
V_120 |= ( V_47 [ 2 ] >> 4 ) & 0x3 ;
V_121 |= ( V_47 [ 2 ] >> 6 ) & 0x3 ;
}
F_54 ( V_2 -> V_47 , V_127 , V_120 ) ;
F_54 ( V_2 -> V_47 , V_128 , V_121 ) ;
}
static void F_56 ( struct V_1 * V_2 , const T_3 * V_106 )
{
F_50 ( V_2 , V_106 ) ;
F_26 ( V_2 , V_6 ) ;
if ( F_1 ( V_2 , V_61 , 0 ) ) {
V_2 -> V_5 . V_78 = V_106 [ 5 ] ;
F_2 ( V_2 ) ;
}
}
static void F_57 ( struct V_1 * V_2 , const T_3 * V_106 )
{
F_50 ( V_2 , V_106 ) ;
}
static void F_58 ( struct V_1 * V_2 , const T_3 * V_106 )
{
T_3 V_129 = V_106 [ 3 ] ;
T_3 V_3 = V_106 [ 2 ] ;
F_50 ( V_2 , V_106 ) ;
if ( F_1 ( V_2 , V_3 , 0 ) ) {
V_2 -> V_5 . V_70 = V_129 ;
F_2 ( V_2 ) ;
} else if ( V_129 ) {
F_20 ( V_2 -> V_14 , L_4 , V_129 ,
V_3 ) ;
}
}
static void F_59 ( struct V_1 * V_2 , const T_3 * V_106 )
{
F_50 ( V_2 , V_106 ) ;
F_53 ( V_2 , V_106 ) ;
}
static void F_60 ( struct V_1 * V_2 , const T_3 * V_106 )
{
F_50 ( V_2 , V_106 ) ;
}
static void F_61 ( struct V_1 * V_2 , const T_3 * V_106 )
{
F_50 ( V_2 , V_106 ) ;
F_53 ( V_2 , V_106 ) ;
F_62 ( V_2 , & V_106 [ 5 ] , false ) ;
F_63 ( V_2 , & V_106 [ 8 ] , false ) ;
F_64 ( V_2 , & V_106 [ 11 ] , false ) ;
F_65 ( V_2 , & V_106 [ 14 ] , false ) ;
F_52 ( V_2 -> V_47 ) ;
}
static void F_66 ( struct V_1 * V_2 , const T_3 * V_106 )
{
F_50 ( V_2 , V_106 ) ;
}
static void F_67 ( struct V_1 * V_2 , const T_3 * V_106 )
{
F_50 ( V_2 , V_106 ) ;
F_62 ( V_2 , & V_106 [ 2 ] , false ) ;
F_63 ( V_2 , & V_106 [ 4 ] , true ) ;
F_64 ( V_2 , & V_106 [ 7 ] , false ) ;
F_65 ( V_2 , & V_106 [ 9 ] , true ) ;
F_52 ( V_2 -> V_47 ) ;
}
static void F_68 ( struct V_1 * V_2 , const T_3 * V_106 )
{
F_50 ( V_2 , V_106 ) ;
F_53 ( V_2 , V_106 ) ;
}
static void F_69 ( struct V_1 * V_2 , const T_3 * V_106 )
{
F_50 ( V_2 , V_106 ) ;
F_53 ( V_2 , V_106 ) ;
F_62 ( V_2 , & V_106 [ 5 ] , false ) ;
F_63 ( V_2 , & V_106 [ 7 ] , true ) ;
F_64 ( V_2 , & V_106 [ 10 ] , false ) ;
F_65 ( V_2 , & V_106 [ 12 ] , true ) ;
F_52 ( V_2 -> V_47 ) ;
}
static void F_70 ( struct V_1 * V_2 , const T_3 * V_106 )
{
}
static void F_71 ( struct V_1 * V_2 , const T_3 * V_106 )
{
F_50 ( V_2 , V_106 ) ;
V_2 -> V_5 . V_130 [ 0 ] = V_106 [ 2 ] ;
V_2 -> V_5 . V_130 [ 1 ] = ( V_106 [ 0 ] >> 1 ) & ( 0x10 | 0x20 ) ;
V_2 -> V_5 . V_130 [ 1 ] |= ( V_106 [ 1 ] << 1 ) & ( 0x40 | 0x80 ) ;
F_62 ( V_2 , & V_106 [ 3 ] , false ) ;
F_63 ( V_2 , & V_106 [ 12 ] , false ) ;
F_52 ( V_2 -> V_47 ) ;
}
static void F_72 ( struct V_1 * V_2 , const T_3 * V_106 )
{
T_3 V_17 [ 5 ] ;
F_50 ( V_2 , V_106 ) ;
V_2 -> V_5 . V_130 [ 1 ] |= ( V_106 [ 0 ] >> 5 ) & ( 0x01 | 0x02 ) ;
V_2 -> V_5 . V_130 [ 1 ] |= ( V_106 [ 1 ] >> 3 ) & ( 0x04 | 0x08 ) ;
V_17 [ 0 ] = 0 ;
V_17 [ 1 ] = 0 ;
V_17 [ 2 ] = V_2 -> V_5 . V_130 [ 0 ] ;
V_17 [ 3 ] = V_106 [ 2 ] ;
V_17 [ 4 ] = V_2 -> V_5 . V_130 [ 1 ] ;
F_53 ( V_2 , V_17 ) ;
F_64 ( V_2 , & V_106 [ 3 ] , false ) ;
F_65 ( V_2 , & V_106 [ 12 ] , false ) ;
F_52 ( V_2 -> V_47 ) ;
}
static int F_73 ( struct V_13 * V_14 , struct V_131 * V_132 ,
T_6 * V_133 , int V_32 )
{
struct V_1 * V_2 = F_37 ( V_14 ) ;
struct V_134 * V_135 ;
int V_95 ;
unsigned long V_26 ;
bool V_136 = false ;
if ( V_32 < 1 )
return - V_81 ;
F_17 ( & V_2 -> V_5 . V_69 , V_26 ) ;
for ( V_95 = 0 ; V_137 [ V_95 ] . V_138 ; ++ V_95 ) {
V_135 = & V_137 [ V_95 ] ;
if ( V_135 -> V_138 == V_133 [ 0 ] && V_135 -> V_32 < V_32 ) {
V_135 -> V_139 ( V_2 , & V_133 [ 1 ] ) ;
V_136 = true ;
}
}
if ( ! V_136 )
F_20 ( V_14 , L_5 , V_133 [ 0 ] ,
V_32 ) ;
F_18 ( & V_2 -> V_5 . V_69 , V_26 ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 )
{
int V_95 ;
struct V_90 * V_140 ;
for ( V_95 = 0 ; V_95 < 4 ; ++ V_95 ) {
if ( V_2 -> V_40 [ V_95 ] ) {
V_140 = V_2 -> V_40 [ V_95 ] ;
V_2 -> V_40 [ V_95 ] = NULL ;
F_75 ( V_140 ) ;
F_14 ( V_140 ) ;
}
}
}
static int F_76 ( struct V_1 * V_2 )
{
int V_95 , V_10 ;
struct V_92 * V_93 = & V_2 -> V_14 -> V_93 ;
T_4 V_141 = strlen ( F_77 ( V_93 ) ) + 9 ;
struct V_90 * V_140 ;
char * V_142 ;
for ( V_95 = 0 ; V_95 < 4 ; ++ V_95 ) {
V_140 = F_78 ( sizeof( struct V_90 ) + V_141 , V_20 ) ;
if ( ! V_140 ) {
V_10 = - V_21 ;
goto V_129;
}
V_142 = ( void * ) & V_140 [ 1 ] ;
snprintf ( V_142 , V_141 , L_6 , F_77 ( V_93 ) , V_95 ) ;
V_140 -> V_142 = V_142 ;
V_140 -> V_143 = 0 ;
V_140 -> V_144 = 1 ;
V_140 -> V_145 = F_36 ;
V_140 -> V_146 = F_39 ;
V_10 = F_79 ( V_93 , V_140 ) ;
if ( V_10 ) {
F_14 ( V_140 ) ;
goto V_129;
}
V_2 -> V_40 [ V_95 ] = V_140 ;
}
return 0 ;
V_129:
F_74 ( V_2 ) ;
return V_10 ;
}
static struct V_1 * F_80 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
int V_95 ;
V_2 = F_78 ( sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_107 = F_81 () ;
if ( ! V_2 -> V_107 )
goto V_129;
V_2 -> V_14 = V_14 ;
F_82 ( V_14 , V_2 ) ;
F_83 ( V_2 -> V_107 , V_2 ) ;
V_2 -> V_107 -> V_147 = F_42 ;
V_2 -> V_107 -> V_148 = F_44 ;
V_2 -> V_107 -> V_93 . V_94 = & V_2 -> V_14 -> V_93 ;
V_2 -> V_107 -> V_138 . V_149 = V_2 -> V_14 -> V_150 ;
V_2 -> V_107 -> V_138 . V_151 = V_2 -> V_14 -> V_151 ;
V_2 -> V_107 -> V_138 . V_152 = V_2 -> V_14 -> V_152 ;
V_2 -> V_107 -> V_138 . V_153 = V_2 -> V_14 -> V_153 ;
V_2 -> V_107 -> V_142 = V_154 ;
F_84 ( V_155 , V_2 -> V_107 -> V_156 ) ;
for ( V_95 = 0 ; V_95 < V_157 ; ++ V_95 )
F_84 ( V_108 [ V_95 ] , V_2 -> V_107 -> V_158 ) ;
F_84 ( V_159 , V_2 -> V_107 -> V_160 ) ;
if ( F_85 ( V_2 -> V_107 , NULL , F_40 ) )
goto V_161;
V_2 -> V_62 = F_81 () ;
if ( ! V_2 -> V_62 )
goto V_161;
F_83 ( V_2 -> V_62 , V_2 ) ;
V_2 -> V_62 -> V_147 = F_46 ;
V_2 -> V_62 -> V_148 = F_47 ;
V_2 -> V_62 -> V_93 . V_94 = & V_2 -> V_14 -> V_93 ;
V_2 -> V_62 -> V_138 . V_149 = V_2 -> V_14 -> V_150 ;
V_2 -> V_62 -> V_138 . V_151 = V_2 -> V_14 -> V_151 ;
V_2 -> V_62 -> V_138 . V_152 = V_2 -> V_14 -> V_152 ;
V_2 -> V_62 -> V_138 . V_153 = V_2 -> V_14 -> V_153 ;
V_2 -> V_62 -> V_142 = V_154 L_7 ;
F_84 ( V_162 , V_2 -> V_62 -> V_156 ) ;
F_84 ( V_123 , V_2 -> V_62 -> V_163 ) ;
F_84 ( V_124 , V_2 -> V_62 -> V_163 ) ;
F_84 ( V_125 , V_2 -> V_62 -> V_163 ) ;
F_86 ( V_2 -> V_62 , V_123 , - 500 , 500 , 2 , 4 ) ;
F_86 ( V_2 -> V_62 , V_124 , - 500 , 500 , 2 , 4 ) ;
F_86 ( V_2 -> V_62 , V_125 , - 500 , 500 , 2 , 4 ) ;
V_2 -> V_47 = F_81 () ;
if ( ! V_2 -> V_47 )
goto V_164;
F_83 ( V_2 -> V_47 , V_2 ) ;
V_2 -> V_47 -> V_147 = F_48 ;
V_2 -> V_47 -> V_148 = F_49 ;
V_2 -> V_47 -> V_93 . V_94 = & V_2 -> V_14 -> V_93 ;
V_2 -> V_47 -> V_138 . V_149 = V_2 -> V_14 -> V_150 ;
V_2 -> V_47 -> V_138 . V_151 = V_2 -> V_14 -> V_151 ;
V_2 -> V_47 -> V_138 . V_152 = V_2 -> V_14 -> V_152 ;
V_2 -> V_47 -> V_138 . V_153 = V_2 -> V_14 -> V_153 ;
V_2 -> V_47 -> V_142 = V_154 L_8 ;
F_84 ( V_162 , V_2 -> V_47 -> V_156 ) ;
F_84 ( V_165 , V_2 -> V_47 -> V_163 ) ;
F_84 ( V_166 , V_2 -> V_47 -> V_163 ) ;
F_84 ( V_167 , V_2 -> V_47 -> V_163 ) ;
F_84 ( V_168 , V_2 -> V_47 -> V_163 ) ;
F_84 ( V_169 , V_2 -> V_47 -> V_163 ) ;
F_84 ( V_170 , V_2 -> V_47 -> V_163 ) ;
F_84 ( V_171 , V_2 -> V_47 -> V_163 ) ;
F_84 ( V_172 , V_2 -> V_47 -> V_163 ) ;
F_86 ( V_2 -> V_47 , V_165 , 0 , 1023 , 2 , 4 ) ;
F_86 ( V_2 -> V_47 , V_166 , 0 , 767 , 2 , 4 ) ;
F_86 ( V_2 -> V_47 , V_167 , 0 , 1023 , 2 , 4 ) ;
F_86 ( V_2 -> V_47 , V_168 , 0 , 767 , 2 , 4 ) ;
F_86 ( V_2 -> V_47 , V_169 , 0 , 1023 , 2 , 4 ) ;
F_86 ( V_2 -> V_47 , V_170 , 0 , 767 , 2 , 4 ) ;
F_86 ( V_2 -> V_47 , V_171 , 0 , 1023 , 2 , 4 ) ;
F_86 ( V_2 -> V_47 , V_172 , 0 , 767 , 2 , 4 ) ;
F_87 ( & V_2 -> V_27 ) ;
F_88 ( & V_2 -> V_25 , F_15 ) ;
F_87 ( & V_2 -> V_5 . V_69 ) ;
F_89 ( & V_2 -> V_5 . V_7 ) ;
F_90 ( & V_2 -> V_5 . V_8 ) ;
return V_2 ;
V_164:
F_91 ( V_2 -> V_62 ) ;
V_161:
F_91 ( V_2 -> V_107 ) ;
V_129:
F_14 ( V_2 ) ;
return NULL ;
}
static void F_92 ( struct V_1 * V_2 )
{
F_74 ( V_2 ) ;
F_93 ( & V_2 -> V_77 ) ;
F_94 ( V_2 -> V_62 ) ;
F_94 ( V_2 -> V_47 ) ;
F_94 ( V_2 -> V_107 ) ;
F_95 ( & V_2 -> V_25 ) ;
F_96 ( V_2 -> V_14 ) ;
F_14 ( V_2 ) ;
}
static int F_97 ( struct V_13 * V_14 ,
const struct V_173 * V_138 )
{
struct V_1 * V_2 ;
int V_10 ;
V_2 = F_80 ( V_14 ) ;
if ( ! V_2 ) {
F_98 ( V_14 , L_9 ) ;
return - V_21 ;
}
V_10 = F_99 ( V_14 ) ;
if ( V_10 ) {
F_98 ( V_14 , L_10 ) ;
goto V_129;
}
V_10 = F_100 ( V_14 , V_174 ) ;
if ( V_10 ) {
F_98 ( V_14 , L_11 ) ;
goto V_129;
}
V_10 = F_101 ( V_2 -> V_62 ) ;
if ( V_10 ) {
F_98 ( V_14 , L_12 ) ;
goto V_175;
}
V_10 = F_101 ( V_2 -> V_47 ) ;
if ( V_10 ) {
F_98 ( V_14 , L_12 ) ;
goto V_164;
}
V_10 = F_101 ( V_2 -> V_107 ) ;
if ( V_10 ) {
F_98 ( V_14 , L_12 ) ;
goto V_161;
}
V_2 -> V_77 . V_176 = V_177 ;
V_2 -> V_77 . V_178 = F_102 ( V_177 ) ;
V_2 -> V_77 . V_179 = F_34 ;
V_2 -> V_77 . V_142 = L_13 ;
V_2 -> V_77 . type = V_180 ;
V_2 -> V_77 . V_181 = 0 ;
V_10 = F_103 ( & V_2 -> V_14 -> V_93 , & V_2 -> V_77 ) ;
if ( V_10 ) {
F_98 ( V_14 , L_14 ) ;
goto V_182;
}
V_10 = F_76 ( V_2 ) ;
if ( V_10 )
goto V_183;
F_104 ( V_14 , L_15 ) ;
F_105 ( & V_2 -> V_5 . V_69 ) ;
F_24 ( V_2 , V_43 ) ;
F_106 ( & V_2 -> V_5 . V_69 ) ;
return 0 ;
V_183:
F_92 ( V_2 ) ;
return V_10 ;
V_182:
F_94 ( V_2 -> V_107 ) ;
V_2 -> V_107 = NULL ;
V_161:
F_94 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
V_164:
F_94 ( V_2 -> V_62 ) ;
V_2 -> V_62 = NULL ;
V_175:
F_96 ( V_14 ) ;
V_129:
F_91 ( V_2 -> V_47 ) ;
F_91 ( V_2 -> V_62 ) ;
F_91 ( V_2 -> V_107 ) ;
F_14 ( V_2 ) ;
return V_10 ;
}
static void F_107 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_37 ( V_14 ) ;
F_104 ( V_14 , L_16 ) ;
F_92 ( V_2 ) ;
}
static int T_7 F_108 ( void )
{
int V_10 ;
V_10 = F_109 ( & V_184 ) ;
if ( V_10 )
F_110 ( L_17 ) ;
return V_10 ;
}
static void T_8 F_111 ( void )
{
F_112 ( & V_184 ) ;
}
