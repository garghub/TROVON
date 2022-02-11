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
T_2 V_34 ;
T_2 V_35 ;
T_4 V_36 ;
V_2 -> V_3 = true ;
V_34 = V_2 -> V_5 . V_37 ;
for ( V_36 = 0 ; V_36 < V_34 ; V_36 ++ ) {
V_35 = F_10 ( V_2 , F_11 ( V_36 ) ) ;
if ( V_35 & V_38 ) {
V_35 &= ~ V_38 ;
F_4 ( V_2 , F_11 ( V_36 ) , V_35 ) ;
}
}
F_5 ( V_2 ) ;
F_4 ( V_2 , V_39 , V_40 ) ;
F_10 ( V_2 , V_41 ) ;
V_34 = V_2 -> V_5 . V_42 ;
for ( V_36 = 0 ; V_36 < V_34 ; V_36 ++ ) {
V_35 = F_10 ( V_2 , F_12 ( V_36 ) ) ;
if ( V_35 & V_43 ) {
V_35 &= ~ V_43 ;
F_4 ( V_2 , F_12 ( V_36 ) , V_35 ) ;
}
}
return 0 ;
}
static T_1 F_13 ( struct V_1 * V_2 , T_3 * V_44 )
{
T_2 V_45 = 0 ;
switch ( V_2 -> V_5 . V_32 ) {
case 0 :
V_45 = ( ( V_44 [ 4 ] >> 4 ) | ( ( ( T_4 ) V_44 [ 5 ] ) << 4 ) ) ;
break;
case 1 :
V_45 = ( ( V_44 [ 4 ] >> 3 ) | ( ( ( T_4 ) V_44 [ 5 ] ) << 5 ) ) ;
break;
case 2 :
V_45 = ( ( V_44 [ 4 ] >> 2 ) | ( ( ( T_4 ) V_44 [ 5 ] ) << 6 ) ) ;
break;
case 3 :
V_45 = ( ( V_44 [ 4 ] ) | ( ( ( T_4 ) V_44 [ 5 ] ) << 8 ) ) ;
break;
default:
break;
}
V_45 &= 0xFFF ;
return V_45 ;
}
static T_1 F_14 ( struct V_1 * V_2 , T_3 * V_46 )
{
F_8 ( V_46 , V_2 -> V_5 . V_31 ) ;
return 0 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_2 V_47 , T_3 * V_9 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_16 [ 3 ] ;
T_3 * V_48 = ( T_3 * ) ( & V_16 [ 1 ] ) ;
T_1 V_14 ;
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
V_16 [ 0 ] |= V_47 << V_49 ;
V_16 [ 0 ] |= V_50 ;
if ( V_9 )
F_8 ( V_48 , V_9 ) ;
V_14 = V_11 -> V_6 . V_27 ( V_2 , V_16 , 3 ) ;
if ( ! V_14 )
V_14 = V_11 -> V_6 . V_28 ( V_2 , V_16 , 3 ) ;
V_16 [ 0 ] &= ~ V_51 ;
if ( ! V_14 )
if ( V_16 [ 0 ] ==
( V_50 | V_30 ) )
V_14 = - V_52 ;
return V_14 ;
}
int F_16 ( struct V_1 * V_2 , T_2 * V_53 , int V_54 )
{
int V_55 , V_36 , V_56 ;
T_2 V_16 [ V_57 ] ;
T_2 * V_58 = & V_16 [ 1 ] ;
T_2 V_59 = 0 ;
int V_60 = V_61 / 16 ;
if ( V_2 -> V_19 != V_62 ||
V_2 -> V_5 . type >= V_63 )
return - V_64 ;
V_16 [ 0 ] = V_65 ;
V_55 = V_2 -> V_11 . V_6 . V_27 ( V_2 , V_16 , 1 ) ;
if ( V_55 )
return V_55 ;
V_55 = V_2 -> V_11 . V_6 . V_28 ( V_2 , V_16 , V_60 + 1 ) ;
if ( V_55 )
return V_55 ;
V_16 [ 0 ] &= ~ V_51 ;
if ( V_16 [ 0 ] == ( V_65 | V_30 ) )
return - V_66 ;
if ( V_16 [ 0 ] != ( V_65 | V_29 ) )
return V_67 ;
if ( V_54 > 1 )
V_59 = 0x1 ;
for ( V_36 = 0 ; V_36 < V_60 ; V_36 ++ )
for ( V_56 = 0 ; V_56 < 16 ; V_56 ++ )
V_53 [ V_36 * 16 + V_56 ] = ( V_58 [ V_36 ] >> ( 2 * V_56 ) ) & V_59 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , T_3 * V_68 )
{
int V_55 ;
T_2 V_16 [ V_57 ] ;
if ( V_2 -> V_19 != V_62 ||
V_2 -> V_5 . type >= V_63 )
return - V_64 ;
V_16 [ 0 ] = V_69 ;
V_55 = V_2 -> V_11 . V_6 . V_27 ( V_2 , V_16 , 1 ) ;
if ( V_55 )
return V_55 ;
V_55 = V_2 -> V_11 . V_6 . V_28 ( V_2 , V_16 , 11 ) ;
if ( V_55 )
return V_55 ;
V_16 [ 0 ] &= ~ V_51 ;
if ( V_16 [ 0 ] == ( V_65 | V_30 ) )
return - V_66 ;
if ( V_16 [ 0 ] != ( V_69 | V_29 ) )
return V_67 ;
memcpy ( V_68 , V_16 + 1 , V_70 ) ;
return 0 ;
}
static T_1 F_18 ( struct V_1 * V_2 , T_2 V_47 , T_3 * V_9 ,
T_2 V_71 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_16 [ 3 ] ;
T_3 * V_48 = ( T_3 * ) ( & V_16 [ 1 ] ) ;
T_1 V_14 ;
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
V_16 [ 0 ] = V_72 ;
F_8 ( V_48 , V_9 ) ;
V_14 = V_11 -> V_6 . V_27 ( V_2 , V_16 , 3 ) ;
if ( ! V_14 )
V_14 = V_11 -> V_6 . V_28 ( V_2 , V_16 , 3 ) ;
V_16 [ 0 ] &= ~ V_51 ;
if ( ! V_14 &&
( V_16 [ 0 ] == ( V_72 | V_30 ) ) )
F_14 ( V_2 , V_2 -> V_5 . V_9 ) ;
return V_14 ;
}
static void F_19 ( struct V_1 * V_2 ,
T_2 * V_73 , T_4 V_74 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_75 [ V_57 ] ;
T_1 V_76 = V_11 -> V_6 . V_27 ( V_2 , V_73 , V_74 ) ;
if ( ! V_76 )
V_11 -> V_6 . V_28 ( V_2 , V_75 , V_74 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 ;
T_2 V_16 [ V_57 ] ;
T_4 * V_81 = ( T_4 * ) & V_16 [ 1 ] ;
T_2 V_82 , V_36 ;
V_82 = F_21 ( V_78 ) ;
if ( V_82 > 30 )
V_82 = 30 ;
V_16 [ 0 ] = V_83 ;
V_16 [ 0 ] |= V_82 << V_49 ;
V_36 = 0 ;
F_22 (ha, netdev) {
if ( V_36 == V_82 )
break;
if ( F_23 ( V_80 -> V_9 ) )
continue;
V_81 [ V_36 ++ ] = F_13 ( V_2 , V_80 -> V_9 ) ;
}
F_19 ( V_2 , V_16 , V_57 ) ;
return 0 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_77 * V_78 , int V_84 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_16 [ 2 ] ;
T_1 V_55 ;
switch ( V_2 -> V_19 ) {
case V_62 :
break;
default:
return - V_64 ;
}
V_16 [ 0 ] = V_85 ;
V_16 [ 1 ] = V_84 ;
V_55 = V_11 -> V_6 . V_27 ( V_2 , V_16 , 2 ) ;
if ( V_55 )
return V_55 ;
V_55 = V_11 -> V_6 . V_28 ( V_2 , V_16 , 2 ) ;
if ( V_55 )
return V_55 ;
V_16 [ 0 ] &= ~ V_51 ;
if ( V_16 [ 0 ] == ( V_85 | V_30 ) )
return - V_66 ;
return 0 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_2 V_86 , T_2 V_87 ,
bool V_88 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_16 [ 2 ] ;
T_1 V_55 ;
V_16 [ 0 ] = V_89 ;
V_16 [ 1 ] = V_86 ;
V_16 [ 0 ] |= V_88 << V_49 ;
V_55 = V_11 -> V_6 . V_27 ( V_2 , V_16 , 2 ) ;
if ( V_55 )
goto V_90;
V_55 = V_11 -> V_6 . V_28 ( V_2 , V_16 , 2 ) ;
if ( V_55 )
goto V_90;
V_16 [ 0 ] &= ~ V_51 ;
V_16 [ 0 ] &= ~ ( 0xFF << V_49 ) ;
if ( V_16 [ 0 ] != ( V_89 | V_29 ) )
V_55 = V_91 ;
V_90:
return V_55 ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
T_5 V_92 , bool V_93 ,
bool V_94 )
{
return 0 ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
T_5 * V_92 ,
bool * V_95 ,
bool V_94 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
struct V_96 * V_5 = & V_2 -> V_5 ;
T_1 V_14 = 0 ;
T_2 V_97 ;
T_2 V_98 = 0 ;
if ( ! V_11 -> V_6 . V_23 ( V_2 ) || ! V_11 -> V_12 )
V_5 -> V_99 = true ;
if ( ! V_5 -> V_99 )
goto V_100;
V_97 = F_10 ( V_2 , V_101 ) ;
if ( ! ( V_97 & V_102 ) )
goto V_100;
if ( V_5 -> type == V_103 ) {
int V_36 ;
for ( V_36 = 0 ; V_36 < 5 ; V_36 ++ ) {
F_6 ( 100 ) ;
V_97 = F_10 ( V_2 , V_101 ) ;
if ( ! ( V_97 & V_102 ) )
goto V_100;
}
}
switch ( V_97 & V_104 ) {
case V_105 :
* V_92 = V_106 ;
break;
case V_107 :
* V_92 = V_108 ;
break;
case V_109 :
* V_92 = V_110 ;
break;
}
if ( V_11 -> V_6 . V_111 ( V_2 , & V_98 , 1 ) )
goto V_100;
if ( ! ( V_98 & V_51 ) ) {
if ( V_98 & V_30 )
V_14 = - 1 ;
goto V_100;
}
if ( ! V_11 -> V_12 ) {
V_14 = - 1 ;
goto V_100;
}
V_5 -> V_99 = false ;
V_100:
* V_95 = ! V_5 -> V_99 ;
return V_14 ;
}
void F_28 ( struct V_1 * V_2 , T_4 V_112 )
{
T_2 V_16 [ 2 ] ;
V_16 [ 0 ] = V_113 ;
V_16 [ 1 ] = V_112 ;
F_19 ( V_2 , V_16 , 2 ) ;
}
int F_29 ( struct V_1 * V_2 , int V_114 )
{
int V_55 ;
T_2 V_73 [ 3 ] ;
V_73 [ 0 ] = V_115 ;
V_73 [ 1 ] = V_114 ;
V_73 [ 2 ] = 0 ;
V_55 = V_2 -> V_11 . V_6 . V_27 ( V_2 , V_73 , 3 ) ;
if ( ! V_55 )
V_55 = V_2 -> V_11 . V_6 . V_28 ( V_2 , V_73 , 3 ) ;
if ( ! V_55 ) {
V_73 [ 0 ] &= ~ V_51 ;
if ( V_73 [ 0 ] == ( V_115 | V_29 ) ) {
V_2 -> V_19 = V_114 ;
return 0 ;
}
V_55 = V_91 ;
}
return V_55 ;
}
int F_30 ( struct V_1 * V_2 , unsigned int * V_116 ,
unsigned int * V_117 )
{
int V_55 ;
T_2 V_73 [ 5 ] ;
switch ( V_2 -> V_19 ) {
case V_118 :
case V_62 :
break;
default:
return 0 ;
}
V_73 [ 0 ] = V_119 ;
V_73 [ 1 ] = V_73 [ 2 ] = V_73 [ 3 ] = V_73 [ 4 ] = 0 ;
V_55 = V_2 -> V_11 . V_6 . V_27 ( V_2 , V_73 , 5 ) ;
if ( ! V_55 )
V_55 = V_2 -> V_11 . V_6 . V_28 ( V_2 , V_73 , 5 ) ;
if ( ! V_55 ) {
V_73 [ 0 ] &= ~ V_51 ;
if ( V_73 [ 0 ] != ( V_119 | V_29 ) )
return V_67 ;
V_2 -> V_5 . V_42 = V_73 [ V_120 ] ;
if ( V_2 -> V_5 . V_42 == 0 ||
V_2 -> V_5 . V_42 > V_121 )
V_2 -> V_5 . V_42 = V_121 ;
V_2 -> V_5 . V_37 = V_73 [ V_122 ] ;
if ( V_2 -> V_5 . V_37 == 0 ||
V_2 -> V_5 . V_37 > V_123 )
V_2 -> V_5 . V_37 = V_123 ;
* V_116 = V_73 [ V_124 ] ;
if ( * V_116 > V_2 -> V_5 . V_37 )
* V_116 = 1 ;
* V_117 = V_73 [ V_125 ] ;
if ( * V_117 >= V_2 -> V_5 . V_42 )
* V_117 = 0 ;
}
return V_55 ;
}
