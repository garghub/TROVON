static inline T_1 F_1 ( struct V_1 * V_2 , T_2 * V_3 ,
T_2 * V_4 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_1 V_8 = V_7 -> V_9 . V_10 ( V_2 , V_3 , V_5 ) ;
if ( V_8 )
return V_8 ;
return V_7 -> V_9 . V_11 ( V_2 , V_4 , V_5 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
V_2 -> V_12 = false ;
return 0 ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
T_1 V_13 = V_2 -> V_14 . V_9 . V_15 ( V_2 ) ;
V_2 -> V_14 . V_9 . V_16 ( V_2 , V_2 -> V_14 . V_17 ) ;
return V_13 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_2 V_18 = V_19 ;
T_1 V_20 = V_21 ;
T_2 V_22 [ V_23 ] ;
T_4 * V_17 = ( T_4 * ) ( & V_22 [ 1 ] ) ;
V_2 -> V_14 . V_9 . V_24 ( V_2 ) ;
V_2 -> V_25 = V_26 ;
F_5 ( V_2 , V_27 , V_28 ) ;
F_6 ( V_2 ) ;
while ( ! V_7 -> V_9 . V_29 ( V_2 ) && V_18 ) {
V_18 -- ;
F_7 ( 5 ) ;
}
if ( ! V_18 )
return V_30 ;
V_7 -> V_18 = V_31 ;
V_22 [ 0 ] = V_32 ;
V_7 -> V_9 . V_10 ( V_2 , V_22 , 1 ) ;
F_8 ( 10 ) ;
V_20 = V_7 -> V_9 . V_11 ( V_2 , V_22 , V_23 ) ;
if ( V_20 )
return V_20 ;
if ( V_22 [ 0 ] != ( V_32 | V_33 ) &&
V_22 [ 0 ] != ( V_32 | V_34 ) )
return V_21 ;
if ( V_22 [ 0 ] == ( V_32 | V_33 ) )
F_9 ( V_2 -> V_14 . V_35 , V_17 ) ;
V_2 -> V_14 . V_36 = V_22 [ V_37 ] ;
return 0 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
#if F_11 ( V_38 )
struct V_39 * V_40 = V_2 -> V_41 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < 6 ; V_42 ++ )
F_12 ( V_40 -> V_43 ,
( V_42 + V_44 ) ,
& V_2 -> V_14 . V_35 [ V_42 ] ) ;
return 0 ;
#else
F_13 ( L_1 ) ;
return - V_45 ;
#endif
}
static T_1 F_14 ( struct V_1 * V_2 )
{
T_2 V_46 ;
T_2 V_47 ;
T_3 V_42 ;
V_2 -> V_12 = true ;
V_46 = V_2 -> V_14 . V_48 ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_47 = F_15 ( V_2 , F_16 ( V_42 ) ) ;
if ( V_47 & V_49 ) {
V_47 &= ~ V_49 ;
F_5 ( V_2 , F_16 ( V_42 ) , V_47 ) ;
}
}
F_6 ( V_2 ) ;
F_5 ( V_2 , V_50 , V_51 ) ;
F_15 ( V_2 , V_52 ) ;
V_46 = V_2 -> V_14 . V_53 ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_47 = F_15 ( V_2 , F_17 ( V_42 ) ) ;
if ( V_47 & V_54 ) {
V_47 &= ~ V_54 ;
F_5 ( V_2 , F_17 ( V_42 ) , V_47 ) ;
}
}
return 0 ;
}
static T_1 F_18 ( struct V_1 * V_2 , T_4 * V_55 )
{
T_2 V_56 = 0 ;
switch ( V_2 -> V_14 . V_36 ) {
case 0 :
V_56 = ( ( V_55 [ 4 ] >> 4 ) | ( ( ( T_3 ) V_55 [ 5 ] ) << 4 ) ) ;
break;
case 1 :
V_56 = ( ( V_55 [ 4 ] >> 3 ) | ( ( ( T_3 ) V_55 [ 5 ] ) << 5 ) ) ;
break;
case 2 :
V_56 = ( ( V_55 [ 4 ] >> 2 ) | ( ( ( T_3 ) V_55 [ 5 ] ) << 6 ) ) ;
break;
case 3 :
V_56 = ( ( V_55 [ 4 ] ) | ( ( ( T_3 ) V_55 [ 5 ] ) << 8 ) ) ;
break;
default:
break;
}
V_56 &= 0xFFF ;
return V_56 ;
}
static T_1 F_19 ( struct V_1 * V_2 , T_4 * V_57 )
{
F_9 ( V_57 , V_2 -> V_14 . V_35 ) ;
return 0 ;
}
static T_1 F_20 ( struct V_1 * V_2 , T_2 V_58 , T_4 * V_17 )
{
T_2 V_22 [ 3 ] , V_59 ;
T_4 * V_60 = ( T_4 * ) ( & V_22 [ 1 ] ) ;
T_1 V_20 ;
memset ( V_22 , 0 , sizeof( V_22 ) ) ;
V_22 [ 0 ] |= V_58 << V_61 ;
V_22 [ 0 ] |= V_62 ;
V_59 = V_22 [ 0 ] ;
if ( V_17 )
F_9 ( V_60 , V_17 ) ;
V_20 = F_1 ( V_2 , V_22 , V_22 ,
sizeof( V_22 ) / sizeof( T_2 ) ) ;
if ( ! V_20 ) {
V_22 [ 0 ] &= ~ V_63 ;
if ( V_22 [ 0 ] == ( V_59 | V_34 ) )
return - V_64 ;
}
return V_20 ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_2 V_58 , T_4 * V_17 )
{
return - V_45 ;
}
int F_22 ( struct V_1 * V_2 , T_2 * V_65 , int V_66 )
{
int V_67 , V_42 , V_68 ;
T_2 V_22 [ V_69 ] ;
T_2 * V_70 = & V_22 [ 1 ] ;
T_2 V_71 = 0 ;
int V_72 = V_73 / 16 ;
switch ( V_2 -> V_25 ) {
case V_74 :
case V_75 :
if ( V_2 -> V_14 . type < V_76 )
break;
default:
return - V_45 ;
}
V_22 [ 0 ] = V_77 ;
V_67 = V_2 -> V_7 . V_9 . V_10 ( V_2 , V_22 , 1 ) ;
if ( V_67 )
return V_67 ;
V_67 = V_2 -> V_7 . V_9 . V_11 ( V_2 , V_22 , V_72 + 1 ) ;
if ( V_67 )
return V_67 ;
V_22 [ 0 ] &= ~ V_63 ;
if ( V_22 [ 0 ] == ( V_77 | V_34 ) )
return - V_78 ;
if ( V_22 [ 0 ] != ( V_77 | V_33 ) )
return V_79 ;
if ( V_66 > 1 )
V_71 = 0x1 ;
for ( V_42 = 0 ; V_42 < V_72 ; V_42 ++ )
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ )
V_65 [ V_42 * 16 + V_68 ] = ( V_70 [ V_42 ] >> ( 2 * V_68 ) ) & V_71 ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 , T_4 * V_80 )
{
int V_67 ;
T_2 V_22 [ V_69 ] ;
switch ( V_2 -> V_25 ) {
case V_74 :
case V_75 :
if ( V_2 -> V_14 . type < V_76 )
break;
default:
return - V_45 ;
}
V_22 [ 0 ] = V_81 ;
V_67 = V_2 -> V_7 . V_9 . V_10 ( V_2 , V_22 , 1 ) ;
if ( V_67 )
return V_67 ;
V_67 = V_2 -> V_7 . V_9 . V_11 ( V_2 , V_22 , 11 ) ;
if ( V_67 )
return V_67 ;
V_22 [ 0 ] &= ~ V_63 ;
if ( V_22 [ 0 ] == ( V_81 | V_34 ) )
return - V_78 ;
if ( V_22 [ 0 ] != ( V_81 | V_33 ) )
return V_79 ;
memcpy ( V_80 , V_22 + 1 , V_82 ) ;
return 0 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_2 V_58 , T_4 * V_17 ,
T_2 V_83 )
{
T_2 V_22 [ 3 ] ;
T_4 * V_60 = ( T_4 * ) ( & V_22 [ 1 ] ) ;
T_1 V_20 ;
memset ( V_22 , 0 , sizeof( V_22 ) ) ;
V_22 [ 0 ] = V_84 ;
F_9 ( V_60 , V_17 ) ;
V_20 = F_1 ( V_2 , V_22 , V_22 ,
sizeof( V_22 ) / sizeof( T_2 ) ) ;
V_22 [ 0 ] &= ~ V_63 ;
if ( ! V_20 &&
( V_22 [ 0 ] == ( V_84 | V_34 ) ) ) {
F_19 ( V_2 , V_2 -> V_14 . V_17 ) ;
return V_79 ;
}
return V_20 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_2 V_58 , T_4 * V_17 ,
T_2 V_83 )
{
if ( F_26 ( V_17 , V_2 -> V_14 . V_35 ) )
return 0 ;
return - V_45 ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
struct V_87 * V_88 ;
T_2 V_22 [ V_69 ] ;
T_3 * V_89 = ( T_3 * ) & V_22 [ 1 ] ;
T_2 V_90 , V_42 ;
V_90 = F_28 ( V_86 ) ;
if ( V_90 > 30 )
V_90 = 30 ;
V_22 [ 0 ] = V_91 ;
V_22 [ 0 ] |= V_90 << V_61 ;
V_42 = 0 ;
F_29 (ha, netdev) {
if ( V_42 == V_90 )
break;
if ( F_30 ( V_88 -> V_17 ) )
continue;
V_89 [ V_42 ++ ] = F_18 ( V_2 , V_88 -> V_17 ) ;
}
F_1 ( V_2 , V_22 , V_22 , V_69 ) ;
return 0 ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
return - V_45 ;
}
static T_1 F_32 ( struct V_1 * V_2 , int V_92 )
{
T_2 V_22 [ 2 ] ;
T_1 V_67 ;
switch ( V_2 -> V_25 ) {
case V_75 :
if ( V_92 == V_93 )
return - V_45 ;
case V_74 :
break;
default:
return - V_45 ;
}
V_22 [ 0 ] = V_94 ;
V_22 [ 1 ] = V_92 ;
V_67 = F_1 ( V_2 , V_22 , V_22 ,
sizeof( V_22 ) / sizeof( T_2 ) ) ;
if ( V_67 )
return V_67 ;
V_22 [ 0 ] &= ~ V_63 ;
if ( V_22 [ 0 ] == ( V_94 | V_34 ) )
return - V_78 ;
return 0 ;
}
static T_1 F_33 ( struct V_1 * V_2 , int V_92 )
{
return - V_45 ;
}
static T_1 F_34 ( struct V_1 * V_2 , T_2 V_95 , T_2 V_96 ,
bool V_97 )
{
T_2 V_22 [ 2 ] ;
T_1 V_67 ;
V_22 [ 0 ] = V_98 ;
V_22 [ 1 ] = V_95 ;
V_22 [ 0 ] |= V_97 << V_61 ;
V_67 = F_1 ( V_2 , V_22 , V_22 ,
sizeof( V_22 ) / sizeof( T_2 ) ) ;
if ( V_67 )
goto V_99;
V_22 [ 0 ] &= ~ V_63 ;
V_22 [ 0 ] &= ~ ( 0xFF << V_61 ) ;
if ( V_22 [ 0 ] != ( V_98 | V_33 ) )
V_67 = V_100 ;
V_99:
return V_67 ;
}
static T_1 F_35 ( struct V_1 * V_2 , T_2 V_95 , T_2 V_96 ,
bool V_97 )
{
return - V_45 ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
T_5 V_101 , bool V_102 ,
bool V_103 )
{
return 0 ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
T_5 * V_101 ,
bool * V_104 ,
bool V_103 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_105 * V_14 = & V_2 -> V_14 ;
T_1 V_20 = 0 ;
T_2 V_106 ;
T_2 V_107 = 0 ;
if ( ! V_7 -> V_9 . V_29 ( V_2 ) || ! V_7 -> V_18 )
V_14 -> V_108 = true ;
if ( ! V_14 -> V_108 )
goto V_109;
V_106 = F_15 ( V_2 , V_110 ) ;
if ( ! ( V_106 & V_111 ) )
goto V_109;
if ( V_14 -> type == V_112 ) {
int V_42 ;
for ( V_42 = 0 ; V_42 < 5 ; V_42 ++ ) {
F_7 ( 100 ) ;
V_106 = F_15 ( V_2 , V_110 ) ;
if ( ! ( V_106 & V_111 ) )
goto V_109;
}
}
switch ( V_106 & V_113 ) {
case V_114 :
* V_101 = V_115 ;
break;
case V_116 :
* V_101 = V_117 ;
break;
case V_118 :
* V_101 = V_119 ;
break;
}
if ( V_7 -> V_9 . V_120 ( V_2 , & V_107 , 1 ) )
goto V_109;
if ( ! ( V_107 & V_63 ) ) {
if ( V_107 & V_34 )
V_20 = - 1 ;
goto V_109;
}
if ( ! V_7 -> V_18 ) {
V_20 = - 1 ;
goto V_109;
}
V_14 -> V_108 = false ;
V_109:
* V_104 = ! V_14 -> V_108 ;
return V_20 ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
T_5 * V_101 ,
bool * V_104 ,
bool V_103 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_105 * V_14 = & V_2 -> V_14 ;
T_2 V_106 ;
if ( ! V_7 -> V_9 . V_29 ( V_2 ) || ! V_7 -> V_18 )
V_14 -> V_108 = true ;
if ( ! V_14 -> V_108 )
goto V_109;
V_106 = F_15 ( V_2 , V_110 ) ;
if ( ! ( V_106 & V_111 ) )
goto V_109;
if ( V_14 -> type == V_112 ) {
int V_42 ;
for ( V_42 = 0 ; V_42 < 5 ; V_42 ++ ) {
F_7 ( 100 ) ;
V_106 = F_15 ( V_2 , V_110 ) ;
if ( ! ( V_106 & V_111 ) )
goto V_109;
}
}
switch ( V_106 & V_113 ) {
case V_114 :
* V_101 = V_115 ;
break;
case V_116 :
* V_101 = V_117 ;
break;
case V_118 :
* V_101 = V_119 ;
break;
}
V_14 -> V_108 = false ;
V_109:
* V_104 = ! V_14 -> V_108 ;
return 0 ;
}
static T_1 F_39 ( struct V_1 * V_2 , T_3 V_121 )
{
T_2 V_22 [ 2 ] ;
T_1 V_20 ;
V_22 [ 0 ] = V_122 ;
V_22 [ 1 ] = V_121 ;
V_20 = F_1 ( V_2 , V_22 , V_22 ,
sizeof( V_22 ) / sizeof( T_2 ) ) ;
if ( V_20 )
return V_20 ;
if ( ( V_22 [ 0 ] & V_122 ) &&
( V_22 [ 0 ] & V_34 ) )
return V_79 ;
return 0 ;
}
static T_1 F_40 ( struct V_1 * V_2 , T_3 V_121 )
{
T_2 V_123 ;
V_123 = F_15 ( V_2 , F_16 ( 0 ) ) ;
V_123 |= ( ( V_121 + 4 ) | V_124 ) ;
F_5 ( V_2 , F_16 ( 0 ) , V_123 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , int V_125 )
{
int V_67 ;
T_2 V_3 [ 3 ] ;
V_3 [ 0 ] = V_126 ;
V_3 [ 1 ] = V_125 ;
V_3 [ 2 ] = 0 ;
V_67 = F_1 ( V_2 , V_3 , V_3 ,
sizeof( V_3 ) / sizeof( T_2 ) ) ;
if ( ! V_67 ) {
V_3 [ 0 ] &= ~ V_63 ;
if ( V_3 [ 0 ] == ( V_126 | V_33 ) ) {
V_2 -> V_25 = V_125 ;
return 0 ;
}
V_67 = V_100 ;
}
return V_67 ;
}
static int F_42 ( struct V_1 * V_2 , int V_125 )
{
if ( V_125 != V_26 )
return V_100 ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 , unsigned int * V_127 ,
unsigned int * V_128 )
{
int V_67 ;
T_2 V_3 [ 5 ] ;
switch ( V_2 -> V_25 ) {
case V_129 :
case V_75 :
case V_74 :
break;
default:
return 0 ;
}
V_3 [ 0 ] = V_130 ;
V_3 [ 1 ] = V_3 [ 2 ] = V_3 [ 3 ] = V_3 [ 4 ] = 0 ;
V_67 = F_1 ( V_2 , V_3 , V_3 ,
sizeof( V_3 ) / sizeof( T_2 ) ) ;
if ( ! V_67 ) {
V_3 [ 0 ] &= ~ V_63 ;
if ( V_3 [ 0 ] != ( V_130 | V_33 ) )
return V_79 ;
V_2 -> V_14 . V_53 = V_3 [ V_131 ] ;
if ( V_2 -> V_14 . V_53 == 0 ||
V_2 -> V_14 . V_53 > V_132 )
V_2 -> V_14 . V_53 = V_132 ;
V_2 -> V_14 . V_48 = V_3 [ V_133 ] ;
if ( V_2 -> V_14 . V_48 == 0 ||
V_2 -> V_14 . V_48 > V_134 )
V_2 -> V_14 . V_48 = V_134 ;
* V_127 = V_3 [ V_135 ] ;
if ( * V_127 > V_2 -> V_14 . V_48 )
* V_127 = 1 ;
* V_128 = V_3 [ V_136 ] ;
if ( * V_128 >= V_2 -> V_14 . V_53 )
* V_128 = 0 ;
}
return V_67 ;
}
