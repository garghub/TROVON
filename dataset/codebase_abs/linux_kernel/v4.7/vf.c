static T_1 F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = false ;
return 0 ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
T_1 V_4 = V_2 -> V_5 . V_6 . V_7 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_8 ( V_2 , V_2 -> V_5 . V_9 ) ;
return V_4 ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_12 = V_13 ;
T_1 V_14 = V_15 ;
T_2 V_16 [ V_17 ] ;
T_3 * V_9 = ( T_3 * ) ( & V_16 [ 1 ] ) ;
V_2 -> V_5 . V_6 . V_18 ( V_2 ) ;
V_2 -> V_19 = V_20 ;
F_4 ( V_2 , V_21 , V_22 ) ;
F_5 ( V_2 ) ;
while ( ! V_11 -> V_6 . V_23 ( V_2 ) && V_12 ) {
V_12 -- ;
F_6 ( 5 ) ;
}
if ( ! V_12 )
return V_24 ;
V_11 -> V_12 = V_25 ;
V_16 [ 0 ] = V_26 ;
V_11 -> V_6 . V_27 ( V_2 , V_16 , 1 ) ;
F_7 ( 10 ) ;
V_14 = V_11 -> V_6 . V_28 ( V_2 , V_16 , V_17 ) ;
if ( V_14 )
return V_14 ;
if ( V_16 [ 0 ] != ( V_26 | V_29 ) &&
V_16 [ 0 ] != ( V_26 | V_30 ) )
return V_15 ;
if ( V_16 [ 0 ] == ( V_26 | V_29 ) )
F_8 ( V_2 -> V_5 . V_31 , V_9 ) ;
V_2 -> V_5 . V_32 = V_16 [ V_33 ] ;
return 0 ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
#if F_10 ( V_34 )
struct V_35 * V_36 = V_2 -> V_37 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < 6 ; V_38 ++ )
F_11 ( V_36 -> V_39 ,
( V_38 + V_40 ) ,
& V_2 -> V_5 . V_31 [ V_38 ] ) ;
return 0 ;
#else
F_12 ( L_1 ) ;
return - V_41 ;
#endif
}
static T_1 F_13 ( struct V_1 * V_2 )
{
T_2 V_42 ;
T_2 V_43 ;
T_4 V_38 ;
V_2 -> V_3 = true ;
V_42 = V_2 -> V_5 . V_44 ;
for ( V_38 = 0 ; V_38 < V_42 ; V_38 ++ ) {
V_43 = F_14 ( V_2 , F_15 ( V_38 ) ) ;
if ( V_43 & V_45 ) {
V_43 &= ~ V_45 ;
F_4 ( V_2 , F_15 ( V_38 ) , V_43 ) ;
}
}
F_5 ( V_2 ) ;
F_4 ( V_2 , V_46 , V_47 ) ;
F_14 ( V_2 , V_48 ) ;
V_42 = V_2 -> V_5 . V_49 ;
for ( V_38 = 0 ; V_38 < V_42 ; V_38 ++ ) {
V_43 = F_14 ( V_2 , F_16 ( V_38 ) ) ;
if ( V_43 & V_50 ) {
V_43 &= ~ V_50 ;
F_4 ( V_2 , F_16 ( V_38 ) , V_43 ) ;
}
}
return 0 ;
}
static T_1 F_17 ( struct V_1 * V_2 , T_3 * V_51 )
{
T_2 V_52 = 0 ;
switch ( V_2 -> V_5 . V_32 ) {
case 0 :
V_52 = ( ( V_51 [ 4 ] >> 4 ) | ( ( ( T_4 ) V_51 [ 5 ] ) << 4 ) ) ;
break;
case 1 :
V_52 = ( ( V_51 [ 4 ] >> 3 ) | ( ( ( T_4 ) V_51 [ 5 ] ) << 5 ) ) ;
break;
case 2 :
V_52 = ( ( V_51 [ 4 ] >> 2 ) | ( ( ( T_4 ) V_51 [ 5 ] ) << 6 ) ) ;
break;
case 3 :
V_52 = ( ( V_51 [ 4 ] ) | ( ( ( T_4 ) V_51 [ 5 ] ) << 8 ) ) ;
break;
default:
break;
}
V_52 &= 0xFFF ;
return V_52 ;
}
static T_1 F_18 ( struct V_1 * V_2 , T_3 * V_53 )
{
F_8 ( V_53 , V_2 -> V_5 . V_31 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_1 * V_2 , T_2 V_54 , T_3 * V_9 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_16 [ 3 ] ;
T_3 * V_55 = ( T_3 * ) ( & V_16 [ 1 ] ) ;
T_1 V_14 ;
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
V_16 [ 0 ] |= V_54 << V_56 ;
V_16 [ 0 ] |= V_57 ;
if ( V_9 )
F_8 ( V_55 , V_9 ) ;
V_14 = V_11 -> V_6 . V_27 ( V_2 , V_16 , 3 ) ;
if ( ! V_14 )
V_14 = V_11 -> V_6 . V_28 ( V_2 , V_16 , 3 ) ;
V_16 [ 0 ] &= ~ V_58 ;
if ( ! V_14 )
if ( V_16 [ 0 ] ==
( V_57 | V_30 ) )
V_14 = - V_59 ;
return V_14 ;
}
static T_1 F_20 ( struct V_1 * V_2 , T_2 V_54 , T_3 * V_9 )
{
return - V_41 ;
}
int F_21 ( struct V_1 * V_2 , T_2 * V_60 , int V_61 )
{
int V_62 , V_38 , V_63 ;
T_2 V_16 [ V_64 ] ;
T_2 * V_65 = & V_16 [ 1 ] ;
T_2 V_66 = 0 ;
int V_67 = V_68 / 16 ;
if ( V_2 -> V_19 != V_69 ||
V_2 -> V_5 . type >= V_70 )
return - V_41 ;
V_16 [ 0 ] = V_71 ;
V_62 = V_2 -> V_11 . V_6 . V_27 ( V_2 , V_16 , 1 ) ;
if ( V_62 )
return V_62 ;
V_62 = V_2 -> V_11 . V_6 . V_28 ( V_2 , V_16 , V_67 + 1 ) ;
if ( V_62 )
return V_62 ;
V_16 [ 0 ] &= ~ V_58 ;
if ( V_16 [ 0 ] == ( V_71 | V_30 ) )
return - V_72 ;
if ( V_16 [ 0 ] != ( V_71 | V_29 ) )
return V_73 ;
if ( V_61 > 1 )
V_66 = 0x1 ;
for ( V_38 = 0 ; V_38 < V_67 ; V_38 ++ )
for ( V_63 = 0 ; V_63 < 16 ; V_63 ++ )
V_60 [ V_38 * 16 + V_63 ] = ( V_65 [ V_38 ] >> ( 2 * V_63 ) ) & V_66 ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , T_3 * V_74 )
{
int V_62 ;
T_2 V_16 [ V_64 ] ;
if ( V_2 -> V_19 != V_69 ||
V_2 -> V_5 . type >= V_70 )
return - V_41 ;
V_16 [ 0 ] = V_75 ;
V_62 = V_2 -> V_11 . V_6 . V_27 ( V_2 , V_16 , 1 ) ;
if ( V_62 )
return V_62 ;
V_62 = V_2 -> V_11 . V_6 . V_28 ( V_2 , V_16 , 11 ) ;
if ( V_62 )
return V_62 ;
V_16 [ 0 ] &= ~ V_58 ;
if ( V_16 [ 0 ] == ( V_71 | V_30 ) )
return - V_72 ;
if ( V_16 [ 0 ] != ( V_75 | V_29 ) )
return V_73 ;
memcpy ( V_74 , V_16 + 1 , V_76 ) ;
return 0 ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_2 V_54 , T_3 * V_9 ,
T_2 V_77 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_16 [ 3 ] ;
T_3 * V_55 = ( T_3 * ) ( & V_16 [ 1 ] ) ;
T_1 V_14 ;
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
V_16 [ 0 ] = V_78 ;
F_8 ( V_55 , V_9 ) ;
V_14 = V_11 -> V_6 . V_27 ( V_2 , V_16 , 3 ) ;
if ( ! V_14 )
V_14 = V_11 -> V_6 . V_28 ( V_2 , V_16 , 3 ) ;
V_16 [ 0 ] &= ~ V_58 ;
if ( ! V_14 &&
( V_16 [ 0 ] == ( V_78 | V_30 ) ) ) {
F_18 ( V_2 , V_2 -> V_5 . V_9 ) ;
return V_73 ;
}
return V_14 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_2 V_54 , T_3 * V_9 ,
T_2 V_77 )
{
if ( F_25 ( V_9 , V_2 -> V_5 . V_31 ) )
return 0 ;
return - V_41 ;
}
static void F_26 ( struct V_1 * V_2 ,
T_2 * V_79 , T_4 V_80 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_81 [ V_64 ] ;
T_1 V_82 = V_11 -> V_6 . V_27 ( V_2 , V_79 , V_80 ) ;
if ( ! V_82 )
V_11 -> V_6 . V_28 ( V_2 , V_81 , V_80 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
struct V_85 * V_86 ;
T_2 V_16 [ V_64 ] ;
T_4 * V_87 = ( T_4 * ) & V_16 [ 1 ] ;
T_2 V_88 , V_38 ;
V_88 = F_28 ( V_84 ) ;
if ( V_88 > 30 )
V_88 = 30 ;
V_16 [ 0 ] = V_89 ;
V_16 [ 0 ] |= V_88 << V_56 ;
V_38 = 0 ;
F_29 (ha, netdev) {
if ( V_38 == V_88 )
break;
if ( F_30 ( V_86 -> V_9 ) )
continue;
V_87 [ V_38 ++ ] = F_17 ( V_2 , V_86 -> V_9 ) ;
}
F_26 ( V_2 , V_16 , V_64 ) ;
return 0 ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
return - V_41 ;
}
static T_1 F_32 ( struct V_1 * V_2 , int V_90 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_16 [ 2 ] ;
T_1 V_62 ;
switch ( V_2 -> V_19 ) {
case V_69 :
break;
default:
return - V_41 ;
}
V_16 [ 0 ] = V_91 ;
V_16 [ 1 ] = V_90 ;
V_62 = V_11 -> V_6 . V_27 ( V_2 , V_16 , 2 ) ;
if ( V_62 )
return V_62 ;
V_62 = V_11 -> V_6 . V_28 ( V_2 , V_16 , 2 ) ;
if ( V_62 )
return V_62 ;
V_16 [ 0 ] &= ~ V_58 ;
if ( V_16 [ 0 ] == ( V_91 | V_30 ) )
return - V_72 ;
return 0 ;
}
static T_1 F_33 ( struct V_1 * V_2 , int V_90 )
{
return - V_41 ;
}
static T_1 F_34 ( struct V_1 * V_2 , T_2 V_92 , T_2 V_93 ,
bool V_94 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_16 [ 2 ] ;
T_1 V_62 ;
V_16 [ 0 ] = V_95 ;
V_16 [ 1 ] = V_92 ;
V_16 [ 0 ] |= V_94 << V_56 ;
V_62 = V_11 -> V_6 . V_27 ( V_2 , V_16 , 2 ) ;
if ( V_62 )
goto V_96;
V_62 = V_11 -> V_6 . V_28 ( V_2 , V_16 , 2 ) ;
if ( V_62 )
goto V_96;
V_16 [ 0 ] &= ~ V_58 ;
V_16 [ 0 ] &= ~ ( 0xFF << V_56 ) ;
if ( V_16 [ 0 ] != ( V_95 | V_29 ) )
V_62 = V_97 ;
V_96:
return V_62 ;
}
static T_1 F_35 ( struct V_1 * V_2 , T_2 V_92 , T_2 V_93 ,
bool V_94 )
{
return - V_41 ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
T_5 V_98 , bool V_99 ,
bool V_100 )
{
return 0 ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
T_5 * V_98 ,
bool * V_101 ,
bool V_100 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
struct V_102 * V_5 = & V_2 -> V_5 ;
T_1 V_14 = 0 ;
T_2 V_103 ;
T_2 V_104 = 0 ;
if ( ! V_11 -> V_6 . V_23 ( V_2 ) || ! V_11 -> V_12 )
V_5 -> V_105 = true ;
if ( ! V_5 -> V_105 )
goto V_106;
V_103 = F_14 ( V_2 , V_107 ) ;
if ( ! ( V_103 & V_108 ) )
goto V_106;
if ( V_5 -> type == V_109 ) {
int V_38 ;
for ( V_38 = 0 ; V_38 < 5 ; V_38 ++ ) {
F_6 ( 100 ) ;
V_103 = F_14 ( V_2 , V_107 ) ;
if ( ! ( V_103 & V_108 ) )
goto V_106;
}
}
switch ( V_103 & V_110 ) {
case V_111 :
* V_98 = V_112 ;
break;
case V_113 :
* V_98 = V_114 ;
break;
case V_115 :
* V_98 = V_116 ;
break;
}
if ( V_11 -> V_6 . V_117 ( V_2 , & V_104 , 1 ) )
goto V_106;
if ( ! ( V_104 & V_58 ) ) {
if ( V_104 & V_30 )
V_14 = - 1 ;
goto V_106;
}
if ( ! V_11 -> V_12 ) {
V_14 = - 1 ;
goto V_106;
}
V_5 -> V_105 = false ;
V_106:
* V_101 = ! V_5 -> V_105 ;
return V_14 ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
T_5 * V_98 ,
bool * V_101 ,
bool V_100 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
struct V_102 * V_5 = & V_2 -> V_5 ;
T_2 V_103 ;
if ( ! V_11 -> V_6 . V_23 ( V_2 ) || ! V_11 -> V_12 )
V_5 -> V_105 = true ;
if ( ! V_5 -> V_105 )
goto V_106;
V_103 = F_14 ( V_2 , V_107 ) ;
if ( ! ( V_103 & V_108 ) )
goto V_106;
if ( V_5 -> type == V_109 ) {
int V_38 ;
for ( V_38 = 0 ; V_38 < 5 ; V_38 ++ ) {
F_6 ( 100 ) ;
V_103 = F_14 ( V_2 , V_107 ) ;
if ( ! ( V_103 & V_108 ) )
goto V_106;
}
}
switch ( V_103 & V_110 ) {
case V_111 :
* V_98 = V_112 ;
break;
case V_113 :
* V_98 = V_114 ;
break;
case V_115 :
* V_98 = V_116 ;
break;
}
V_5 -> V_105 = false ;
V_106:
* V_101 = ! V_5 -> V_105 ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 , T_4 V_118 )
{
T_2 V_16 [ 2 ] ;
V_16 [ 0 ] = V_119 ;
V_16 [ 1 ] = V_118 ;
F_26 ( V_2 , V_16 , 2 ) ;
}
static void F_40 ( struct V_1 * V_2 , T_4 V_118 )
{
T_2 V_120 ;
V_120 = F_14 ( V_2 , F_15 ( 0 ) ) ;
V_120 |= ( ( V_118 + 4 ) | V_121 ) ;
F_4 ( V_2 , F_15 ( 0 ) , V_120 ) ;
}
static int F_41 ( struct V_1 * V_2 , int V_122 )
{
int V_62 ;
T_2 V_79 [ 3 ] ;
V_79 [ 0 ] = V_123 ;
V_79 [ 1 ] = V_122 ;
V_79 [ 2 ] = 0 ;
V_62 = V_2 -> V_11 . V_6 . V_27 ( V_2 , V_79 , 3 ) ;
if ( ! V_62 )
V_62 = V_2 -> V_11 . V_6 . V_28 ( V_2 , V_79 , 3 ) ;
if ( ! V_62 ) {
V_79 [ 0 ] &= ~ V_58 ;
if ( V_79 [ 0 ] == ( V_123 | V_29 ) ) {
V_2 -> V_19 = V_122 ;
return 0 ;
}
V_62 = V_97 ;
}
return V_62 ;
}
static int F_42 ( struct V_1 * V_2 , int V_122 )
{
if ( V_122 != V_20 )
return V_97 ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 , unsigned int * V_124 ,
unsigned int * V_125 )
{
int V_62 ;
T_2 V_79 [ 5 ] ;
switch ( V_2 -> V_19 ) {
case V_126 :
case V_69 :
break;
default:
return 0 ;
}
V_79 [ 0 ] = V_127 ;
V_79 [ 1 ] = V_79 [ 2 ] = V_79 [ 3 ] = V_79 [ 4 ] = 0 ;
V_62 = V_2 -> V_11 . V_6 . V_27 ( V_2 , V_79 , 5 ) ;
if ( ! V_62 )
V_62 = V_2 -> V_11 . V_6 . V_28 ( V_2 , V_79 , 5 ) ;
if ( ! V_62 ) {
V_79 [ 0 ] &= ~ V_58 ;
if ( V_79 [ 0 ] != ( V_127 | V_29 ) )
return V_73 ;
V_2 -> V_5 . V_49 = V_79 [ V_128 ] ;
if ( V_2 -> V_5 . V_49 == 0 ||
V_2 -> V_5 . V_49 > V_129 )
V_2 -> V_5 . V_49 = V_129 ;
V_2 -> V_5 . V_44 = V_79 [ V_130 ] ;
if ( V_2 -> V_5 . V_44 == 0 ||
V_2 -> V_5 . V_44 > V_131 )
V_2 -> V_5 . V_44 = V_131 ;
* V_124 = V_79 [ V_132 ] ;
if ( * V_124 > V_2 -> V_5 . V_44 )
* V_124 = 1 ;
* V_125 = V_79 [ V_133 ] ;
if ( * V_125 >= V_2 -> V_5 . V_49 )
* V_125 = 0 ;
}
return V_62 ;
}
