static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned char V_5 ;
int V_6 ;
int V_7 ;
struct V_8 * V_9 ;
union V_10 * V_11 ;
V_6 = F_2 ( V_2 , 1 + V_12 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , sizeof( struct V_13 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_14 -> V_15 = ( void * ) ( unsigned long ) V_4 -> V_16 [ 0 ] ;
V_2 -> V_17 = L_1 ;
if ( ( F_4 ( V_14 -> V_15 ) & V_18 ) != V_18 ) {
F_5 ( V_19 L_2
L_3 ,
V_2 -> V_20 , V_14 -> V_15 ) ;
return - V_21 ;
}
F_5 ( V_22 L_4 ,
V_2 -> V_20 , V_14 -> V_15 ) ;
for ( V_5 = 0 ; V_5 < V_12 ; V_5 ++ ) {
V_9 = V_2 -> V_23 + V_5 ;
V_7 = F_4 ( V_14 -> V_15 + ( V_5 + 1 ) * V_24 ) ;
V_9 -> V_25 = V_14 -> V_26 + V_5 ;
V_11 = V_9 -> V_25 ;
switch ( V_7 ) {
case V_27 :
V_11 -> V_28 . V_29 =
V_14 -> V_15 + ( V_5 + 1 ) * V_24 ;
F_6 ( V_2 , V_9 , V_4 -> V_16 [ 2 * V_5 + 2 ] ,
V_4 -> V_16 [ 2 * V_5 + 3 ] ) ;
F_5 ( V_22 L_5
L_6 ,
V_2 -> V_20 , V_5 + 1 ) ;
break;
case V_30 :
V_11 -> V_31 . V_29 =
V_14 -> V_15 + ( V_5 + 1 ) * V_24 ;
F_7 ( V_2 , V_9 , V_4 -> V_16 [ 2 * V_5 + 2 ] ,
V_4 -> V_16 [ 2 * V_5 + 3 ] ) ;
F_5 ( V_22 L_5
L_7 ,
V_2 -> V_20 , V_5 + 1 ) ;
break;
default:
F_5 ( V_19 L_8
L_9 ,
V_7 , V_5 ) ;
case V_32 :
V_9 -> type = V_33 ;
break;
}
}
F_8 ( V_2 , V_2 -> V_23 + V_12 ) ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_5 ( V_22 L_10 , V_2 -> V_20 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_8 * V_9 ,
int V_34 , int V_35 )
{
union V_10 * V_11 = V_9 -> V_25 ;
if ( V_34 < 0 || V_34 > 2 )
V_34 = 0 ;
if ( V_35 < 0 || V_35 > 2 )
V_35 = 0 ;
V_11 -> V_28 . V_36 [ 0 ] = V_37 [ V_34 ] ;
V_11 -> V_28 . V_36 [ 1 ] = V_37 [ V_35 ] ;
V_9 -> type = V_38 ;
V_9 -> V_39 = V_40 ;
V_9 -> V_41 = 2 ;
V_9 -> V_42 = 2 ;
V_9 -> V_43 = V_44 ;
V_9 -> V_45 = V_46 ;
V_9 -> V_47 = 0xffff ;
V_9 -> V_48 = V_11 -> V_28 . V_36 ;
return 0 ;
}
static int V_44 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_49 * V_50 , unsigned int * V_51 )
{
union V_10 * V_11 = V_9 -> V_25 ;
V_51 [ 0 ] = V_11 -> V_28 . V_52 [ F_10 ( V_50 -> V_53 ) ] ;
return 1 ;
}
static int V_46 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_49 * V_50 , unsigned int * V_51 )
{
union V_10 * V_11 = V_9 -> V_25 ;
int V_54 , V_55 ;
unsigned int V_56 ;
V_11 -> V_28 . V_52 [ F_10 ( V_50 -> V_53 ) ] = V_51 [ 0 ] ;
V_56 = ( ( ( unsigned int ) V_51 [ 0 ] + 0x8000 ) & 0xffff ) ;
V_55 = ( V_56 & 0xff ) ;
V_54 = ( ( V_56 >> 8 ) & 0xff ) ;
switch ( F_10 ( V_50 -> V_53 ) ) {
case 0 :
F_11 ( V_55 , V_11 -> V_29 + V_57 ) ;
F_11 ( V_54 , V_11 -> V_29 + V_57 + 1 ) ;
F_11 ( 0x00 , V_11 -> V_29 + V_58 ) ;
break;
case 1 :
F_11 ( V_55 , V_11 -> V_29 + V_59 ) ;
F_11 ( V_54 , V_11 -> V_29 + V_59 + 1 ) ;
F_11 ( 0x00 , V_11 -> V_29 + V_60 ) ;
break;
default:
F_5 ( V_19
L_11 , V_2 -> V_20 ) ;
return - V_21 ;
}
return 1 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_8 * V_9 ,
int V_34 , int V_35 )
{
union V_10 * V_11 = V_9 -> V_25 ;
int V_61 ;
if ( V_34 < 0 || V_34 > 3 )
V_34 = 0 ;
V_11 -> V_31 . V_62 = V_63 [ V_34 ] ;
V_11 -> V_31 . V_64 = V_65 [ V_34 ] ;
V_9 -> type = V_66 ;
V_9 -> V_39 = V_67 ;
V_9 -> V_41 = V_68 ;
V_9 -> V_42 = V_69 ;
V_9 -> V_43 = V_70 ;
V_9 -> V_47 = 0xffff ;
V_9 -> V_71 = V_72 [ V_34 ] ;
V_61 = V_11 -> V_31 . V_62 | V_73 ;
F_11 ( V_74 , V_11 -> V_29 + V_75 ) ;
F_11 ( V_76 , V_11 -> V_29 + V_77 ) ;
F_11 ( V_61 , V_11 -> V_29 + V_78 ) ;
F_11 ( V_11 -> V_31 . V_64 ,
V_11 -> V_29 + V_79 ) ;
return 0 ;
}
static int V_70 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_49 * V_50 , unsigned int * V_51 )
{
union V_10 * V_11 = V_9 -> V_25 ;
unsigned int V_5 = 0 , V_80 = 0 ;
int V_55 , V_54 ;
unsigned char V_81 ;
unsigned int V_82 ;
unsigned int V_56 ;
F_11 ( 1 , V_11 -> V_29 + V_83 ) ;
V_82 = V_84 | V_85 | ( V_11 -> V_31 . V_86 << 3 )
| F_10 ( V_50 -> V_53 ) ;
F_11 ( V_82 , V_11 -> V_29 + V_87 ) ;
F_11 ( 0x00 , V_11 -> V_29 + V_88 ) ;
F_11 ( 0x00 , V_11 -> V_29 + V_89 ) ;
for ( V_5 = 0 ; V_5 < V_50 -> V_90 ; V_5 ++ ) {
V_80 = 0 ;
F_4 ( V_11 -> V_29 + V_91 ) ;
V_81 = F_4 ( V_11 -> V_29 + V_92 ) ;
while ( ( V_81 < 0x80 ) && V_80 < 100 ) {
V_80 ++ ;
V_81 = F_4 ( V_11 -> V_29 + V_92 ) ;
}
if ( V_80 >= 100 ) {
F_5 ( V_19
L_12
L_13 ,
V_2 -> V_20 , V_5 ) ;
return - V_21 ;
}
V_55 = F_4 ( V_11 -> V_29 + V_93 ) ;
V_54 = F_4 ( V_11 -> V_29 + V_93 + 1 ) ;
V_56 = V_55 + 0x100 * V_54 ;
V_51 [ V_5 ] = ( short ) ( ( V_56 + 0x8000 ) & 0xffff ) ;
}
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
V_9 -> type = V_94 ;
V_9 -> V_39 = V_67 | V_40 ;
V_9 -> V_41 = 32 ;
V_9 -> V_95 = V_96 ;
V_9 -> V_97 = V_98 ;
V_9 -> V_47 = 1 ;
V_9 -> V_42 = 32 ;
V_9 -> V_71 = & V_99 ;
V_9 -> V_100 = 0 ;
F_12 ( V_2 , V_9 ) ;
return 0 ;
}
static int V_98 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_49 * V_50 ,
unsigned int * V_51 )
{
int V_101 , V_102 ;
V_101 = 1 << F_10 ( V_50 -> V_53 ) ;
if ( V_101 & 0x000000ff )
V_102 = 0x000000ff ;
else if ( V_101 & 0x0000ff00 )
V_102 = 0x0000ff00 ;
else if ( V_101 & 0x00ff0000 )
V_102 = 0x00ff0000 ;
else
V_102 = 0xff000000 ;
if ( V_51 [ 0 ] )
V_9 -> V_100 |= V_102 ;
else
V_9 -> V_100 &= ~ V_102 ;
F_12 ( V_2 , V_9 ) ;
return 1 ;
}
static int V_96 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_49 * V_50 , unsigned int * V_51 )
{
unsigned int V_101 = V_51 [ 0 ] ;
V_9 -> V_103 &= ~ V_101 ;
V_9 -> V_103 |= ( V_101 & V_51 [ 1 ] ) ;
V_101 &= V_9 -> V_100 ;
if ( V_101 & 0x000000ff )
F_11 ( ( V_9 -> V_103 >> 0 ) & 0xff ,
V_14 -> V_15 + V_104 ) ;
if ( V_101 & 0x0000ff00 )
F_11 ( ( V_9 -> V_103 >> 8 ) & 0xff ,
V_14 -> V_15 + V_105 ) ;
if ( V_101 & 0x00ff0000 )
F_11 ( ( V_9 -> V_103 >> 16 ) & 0xff ,
V_14 -> V_15 + V_106 ) ;
if ( V_101 & 0xff000000 )
F_11 ( ( V_9 -> V_103 >> 24 ) & 0xff ,
V_14 -> V_15 + V_107 ) ;
V_51 [ 1 ] = F_4 ( V_14 -> V_15 + V_104 ) ;
V_51 [ 1 ] |= F_4 ( V_14 -> V_15 + V_105 ) << 8 ;
V_51 [ 1 ] |= F_4 ( V_14 -> V_15 + V_106 ) << 16 ;
V_51 [ 1 ] |= F_4 ( V_14 -> V_15 + V_107 ) << 24 ;
return 2 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
unsigned char V_108 ;
unsigned char V_109 ;
unsigned char V_110 ;
V_108 = F_4 ( V_14 -> V_15 + V_111 ) ;
V_109 = F_4 ( V_14 -> V_15 + V_112 ) ;
V_110 = F_4 ( V_14 -> V_15 + V_113 ) ;
if ( V_9 -> V_100 & 0x000000ff ) {
V_108 &= V_114 ;
V_110 = ( V_110 & ( ~ ( V_115 << V_116 ) ) ) | ( V_117 <<
V_116 ) ;
} else {
V_108 = ( V_108 & V_118 ) | V_119 ;
V_110 = ( V_110 & ( ~ ( V_120 << V_116 ) ) ) ;
}
if ( V_9 -> V_100 & 0x0000ff00 ) {
V_108 &= V_121 ;
V_110 = ( V_110 & ( ~ ( V_115 << V_122 ) ) ) | ( V_117 <<
V_122 ) ;
} else {
V_108 = ( V_108 & V_118 ) | V_123 ;
V_110 = ( V_110 & ( ~ ( V_120 << V_122 ) ) ) ;
}
if ( V_9 -> V_100 & 0x00ff0000 ) {
V_109 &= V_114 ;
V_110 = ( V_110 & ( ~ ( V_115 << V_124 ) ) ) | ( V_117 <<
V_124 ) ;
} else {
V_109 = ( V_109 & V_118 ) | V_119 ;
V_110 = ( V_110 & ( ~ ( V_120 << V_124 ) ) ) ;
}
if ( V_9 -> V_100 & 0xff000000 ) {
V_109 &= V_121 ;
V_110 = ( V_110 & ( ~ ( V_115 << V_125 ) ) ) | ( V_117 <<
V_125 ) ;
} else {
V_109 = ( V_109 & V_118 ) | V_123 ;
V_110 = ( V_110 & ( ~ ( V_120 << V_125 ) ) ) ;
}
F_11 ( V_108 , V_14 -> V_15 + V_111 ) ;
F_11 ( V_109 , V_14 -> V_15 + V_112 ) ;
F_11 ( V_110 , V_14 -> V_15 + V_113 ) ;
}
static int T_1 F_13 ( void )
{
return F_14 ( & V_126 ) ;
}
static void T_2 F_15 ( void )
{
F_16 ( & V_126 ) ;
}
