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
V_20 = F_1 ( V_2 , V_22 , V_22 , 3 ) ;
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
if ( V_2 -> V_25 != V_74 ||
V_2 -> V_14 . type >= V_75 )
return - V_45 ;
V_22 [ 0 ] = V_76 ;
V_67 = V_2 -> V_7 . V_9 . V_10 ( V_2 , V_22 , 1 ) ;
if ( V_67 )
return V_67 ;
V_67 = V_2 -> V_7 . V_9 . V_11 ( V_2 , V_22 , V_72 + 1 ) ;
if ( V_67 )
return V_67 ;
V_22 [ 0 ] &= ~ V_63 ;
if ( V_22 [ 0 ] == ( V_76 | V_34 ) )
return - V_77 ;
if ( V_22 [ 0 ] != ( V_76 | V_33 ) )
return V_78 ;
if ( V_66 > 1 )
V_71 = 0x1 ;
for ( V_42 = 0 ; V_42 < V_72 ; V_42 ++ )
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ )
V_65 [ V_42 * 16 + V_68 ] = ( V_70 [ V_42 ] >> ( 2 * V_68 ) ) & V_71 ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 , T_4 * V_79 )
{
int V_67 ;
T_2 V_22 [ V_69 ] ;
if ( V_2 -> V_25 != V_74 ||
V_2 -> V_14 . type >= V_75 )
return - V_45 ;
V_22 [ 0 ] = V_80 ;
V_67 = V_2 -> V_7 . V_9 . V_10 ( V_2 , V_22 , 1 ) ;
if ( V_67 )
return V_67 ;
V_67 = V_2 -> V_7 . V_9 . V_11 ( V_2 , V_22 , 11 ) ;
if ( V_67 )
return V_67 ;
V_22 [ 0 ] &= ~ V_63 ;
if ( V_22 [ 0 ] == ( V_76 | V_34 ) )
return - V_77 ;
if ( V_22 [ 0 ] != ( V_80 | V_33 ) )
return V_78 ;
memcpy ( V_79 , V_22 + 1 , V_81 ) ;
return 0 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_2 V_58 , T_4 * V_17 ,
T_2 V_82 )
{
T_2 V_22 [ 3 ] ;
T_4 * V_60 = ( T_4 * ) ( & V_22 [ 1 ] ) ;
T_1 V_20 ;
memset ( V_22 , 0 , sizeof( V_22 ) ) ;
V_22 [ 0 ] = V_83 ;
F_9 ( V_60 , V_17 ) ;
V_20 = F_1 ( V_2 , V_22 , V_22 , 2 ) ;
V_22 [ 0 ] &= ~ V_63 ;
if ( ! V_20 &&
( V_22 [ 0 ] == ( V_83 | V_34 ) ) ) {
F_19 ( V_2 , V_2 -> V_14 . V_17 ) ;
return V_78 ;
}
return V_20 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_2 V_58 , T_4 * V_17 ,
T_2 V_82 )
{
if ( F_26 ( V_17 , V_2 -> V_14 . V_35 ) )
return 0 ;
return - V_45 ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_86 * V_87 ;
T_2 V_22 [ V_69 ] ;
T_3 * V_88 = ( T_3 * ) & V_22 [ 1 ] ;
T_2 V_89 , V_42 ;
V_89 = F_28 ( V_85 ) ;
if ( V_89 > 30 )
V_89 = 30 ;
V_22 [ 0 ] = V_90 ;
V_22 [ 0 ] |= V_89 << V_61 ;
V_42 = 0 ;
F_29 (ha, netdev) {
if ( V_42 == V_89 )
break;
if ( F_30 ( V_87 -> V_17 ) )
continue;
V_88 [ V_42 ++ ] = F_18 ( V_2 , V_87 -> V_17 ) ;
}
F_1 ( V_2 , V_22 , V_22 , V_69 ) ;
return 0 ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
return - V_45 ;
}
static T_1 F_32 ( struct V_1 * V_2 , int V_91 )
{
T_2 V_22 [ 2 ] ;
T_1 V_67 ;
switch ( V_2 -> V_25 ) {
case V_74 :
break;
default:
return - V_45 ;
}
V_22 [ 0 ] = V_92 ;
V_22 [ 1 ] = V_91 ;
V_67 = F_1 ( V_2 , V_22 , V_22 , 2 ) ;
if ( V_67 )
return V_67 ;
V_22 [ 0 ] &= ~ V_63 ;
if ( V_22 [ 0 ] == ( V_92 | V_34 ) )
return - V_77 ;
return 0 ;
}
static T_1 F_33 ( struct V_1 * V_2 , int V_91 )
{
return - V_45 ;
}
static T_1 F_34 ( struct V_1 * V_2 , T_2 V_93 , T_2 V_94 ,
bool V_95 )
{
T_2 V_22 [ 2 ] ;
T_1 V_67 ;
V_22 [ 0 ] = V_96 ;
V_22 [ 1 ] = V_93 ;
V_22 [ 0 ] |= V_95 << V_61 ;
V_67 = F_1 ( V_2 , V_22 , V_22 , 2 ) ;
if ( V_67 )
goto V_97;
V_22 [ 0 ] &= ~ V_63 ;
V_22 [ 0 ] &= ~ ( 0xFF << V_61 ) ;
if ( V_22 [ 0 ] != ( V_96 | V_33 ) )
V_67 = V_98 ;
V_97:
return V_67 ;
}
static T_1 F_35 ( struct V_1 * V_2 , T_2 V_93 , T_2 V_94 ,
bool V_95 )
{
return - V_45 ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
T_5 V_99 , bool V_100 ,
bool V_101 )
{
return 0 ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
T_5 * V_99 ,
bool * V_102 ,
bool V_101 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_103 * V_14 = & V_2 -> V_14 ;
T_1 V_20 = 0 ;
T_2 V_104 ;
T_2 V_105 = 0 ;
if ( ! V_7 -> V_9 . V_29 ( V_2 ) || ! V_7 -> V_18 )
V_14 -> V_106 = true ;
if ( ! V_14 -> V_106 )
goto V_107;
V_104 = F_15 ( V_2 , V_108 ) ;
if ( ! ( V_104 & V_109 ) )
goto V_107;
if ( V_14 -> type == V_110 ) {
int V_42 ;
for ( V_42 = 0 ; V_42 < 5 ; V_42 ++ ) {
F_7 ( 100 ) ;
V_104 = F_15 ( V_2 , V_108 ) ;
if ( ! ( V_104 & V_109 ) )
goto V_107;
}
}
switch ( V_104 & V_111 ) {
case V_112 :
* V_99 = V_113 ;
break;
case V_114 :
* V_99 = V_115 ;
break;
case V_116 :
* V_99 = V_117 ;
break;
}
if ( V_7 -> V_9 . V_118 ( V_2 , & V_105 , 1 ) )
goto V_107;
if ( ! ( V_105 & V_63 ) ) {
if ( V_105 & V_34 )
V_20 = - 1 ;
goto V_107;
}
if ( ! V_7 -> V_18 ) {
V_20 = - 1 ;
goto V_107;
}
V_14 -> V_106 = false ;
V_107:
* V_102 = ! V_14 -> V_106 ;
return V_20 ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
T_5 * V_99 ,
bool * V_102 ,
bool V_101 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_103 * V_14 = & V_2 -> V_14 ;
T_2 V_104 ;
if ( ! V_7 -> V_9 . V_29 ( V_2 ) || ! V_7 -> V_18 )
V_14 -> V_106 = true ;
if ( ! V_14 -> V_106 )
goto V_107;
V_104 = F_15 ( V_2 , V_108 ) ;
if ( ! ( V_104 & V_109 ) )
goto V_107;
if ( V_14 -> type == V_110 ) {
int V_42 ;
for ( V_42 = 0 ; V_42 < 5 ; V_42 ++ ) {
F_7 ( 100 ) ;
V_104 = F_15 ( V_2 , V_108 ) ;
if ( ! ( V_104 & V_109 ) )
goto V_107;
}
}
switch ( V_104 & V_111 ) {
case V_112 :
* V_99 = V_113 ;
break;
case V_114 :
* V_99 = V_115 ;
break;
case V_116 :
* V_99 = V_117 ;
break;
}
V_14 -> V_106 = false ;
V_107:
* V_102 = ! V_14 -> V_106 ;
return 0 ;
}
static T_1 F_39 ( struct V_1 * V_2 , T_3 V_119 )
{
T_2 V_22 [ 2 ] ;
T_1 V_20 ;
V_22 [ 0 ] = V_120 ;
V_22 [ 1 ] = V_119 ;
V_20 = F_1 ( V_2 , V_22 , V_22 , 2 ) ;
if ( V_20 )
return V_20 ;
if ( ( V_22 [ 0 ] & V_120 ) &&
( V_22 [ 0 ] & V_34 ) )
return V_78 ;
return 0 ;
}
static T_1 F_40 ( struct V_1 * V_2 , T_3 V_119 )
{
T_2 V_121 ;
V_121 = F_15 ( V_2 , F_16 ( 0 ) ) ;
V_121 |= ( ( V_119 + 4 ) | V_122 ) ;
F_5 ( V_2 , F_16 ( 0 ) , V_121 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , int V_123 )
{
int V_67 ;
T_2 V_3 [ 3 ] ;
V_3 [ 0 ] = V_124 ;
V_3 [ 1 ] = V_123 ;
V_3 [ 2 ] = 0 ;
V_67 = F_1 ( V_2 , V_3 , V_3 , 3 ) ;
if ( ! V_67 ) {
V_3 [ 0 ] &= ~ V_63 ;
if ( V_3 [ 0 ] == ( V_124 | V_33 ) ) {
V_2 -> V_25 = V_123 ;
return 0 ;
}
V_67 = V_98 ;
}
return V_67 ;
}
static int F_42 ( struct V_1 * V_2 , int V_123 )
{
if ( V_123 != V_26 )
return V_98 ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 , unsigned int * V_125 ,
unsigned int * V_126 )
{
int V_67 ;
T_2 V_3 [ 5 ] ;
switch ( V_2 -> V_25 ) {
case V_127 :
case V_74 :
break;
default:
return 0 ;
}
V_3 [ 0 ] = V_128 ;
V_3 [ 1 ] = V_3 [ 2 ] = V_3 [ 3 ] = V_3 [ 4 ] = 0 ;
V_67 = F_1 ( V_2 , V_3 , V_3 , 5 ) ;
if ( ! V_67 ) {
V_3 [ 0 ] &= ~ V_63 ;
if ( V_3 [ 0 ] != ( V_128 | V_33 ) )
return V_78 ;
V_2 -> V_14 . V_53 = V_3 [ V_129 ] ;
if ( V_2 -> V_14 . V_53 == 0 ||
V_2 -> V_14 . V_53 > V_130 )
V_2 -> V_14 . V_53 = V_130 ;
V_2 -> V_14 . V_48 = V_3 [ V_131 ] ;
if ( V_2 -> V_14 . V_48 == 0 ||
V_2 -> V_14 . V_48 > V_132 )
V_2 -> V_14 . V_48 = V_132 ;
* V_125 = V_3 [ V_133 ] ;
if ( * V_125 > V_2 -> V_14 . V_48 )
* V_125 = 1 ;
* V_126 = V_3 [ V_134 ] ;
if ( * V_126 >= V_2 -> V_14 . V_53 )
* V_126 = 0 ;
}
return V_67 ;
}
