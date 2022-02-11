static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned char V_5 ;
int V_6 ;
int V_7 ;
struct V_8 * V_9 ;
union V_10 * V_11 ;
V_6 = F_2 ( V_2 , 1 + V_12 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_3 ( V_2 , sizeof( struct V_13 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_14 -> V_15 = ( void V_16 * ) ( unsigned long ) V_4 -> V_17 [ 0 ] ;
V_2 -> V_18 = L_1 ;
if ( ( F_4 ( V_14 -> V_15 ) & V_19 ) != V_19 ) {
F_5 ( V_20 L_2
L_3 ,
V_2 -> V_21 , V_14 -> V_15 ) ;
return - V_22 ;
}
F_5 ( V_23 L_4 ,
V_2 -> V_21 , V_14 -> V_15 ) ;
for ( V_5 = 0 ; V_5 < V_12 ; V_5 ++ ) {
V_9 = & V_2 -> V_24 [ V_5 ] ;
V_7 = F_4 ( V_14 -> V_15 + ( V_5 + 1 ) * V_25 ) ;
V_9 -> V_26 = V_14 -> V_27 + V_5 ;
V_11 = V_9 -> V_26 ;
switch ( V_7 ) {
case V_28 :
V_11 -> V_29 . V_30 =
V_14 -> V_15 + ( V_5 + 1 ) * V_25 ;
F_6 ( V_2 , V_9 , V_4 -> V_17 [ 2 * V_5 + 2 ] ,
V_4 -> V_17 [ 2 * V_5 + 3 ] ) ;
F_5 ( V_23 L_5
L_6 ,
V_2 -> V_21 , V_5 + 1 ) ;
break;
case V_31 :
V_11 -> V_32 . V_30 =
V_14 -> V_15 + ( V_5 + 1 ) * V_25 ;
F_7 ( V_2 , V_9 , V_4 -> V_17 [ 2 * V_5 + 2 ] ,
V_4 -> V_17 [ 2 * V_5 + 3 ] ) ;
F_5 ( V_23 L_5
L_7 ,
V_2 -> V_21 , V_5 + 1 ) ;
break;
default:
F_5 ( V_20 L_8
L_9 ,
V_7 , V_5 ) ;
case V_33 :
V_9 -> type = V_34 ;
break;
}
}
F_8 ( V_2 , & V_2 -> V_24 [ V_12 ] ) ;
return 1 ;
}
static void F_9 ( struct V_1 * V_2 )
{
}
static int F_6 ( struct V_1 * V_2 , struct V_8 * V_9 ,
int V_35 , int V_36 )
{
union V_10 * V_11 = V_9 -> V_26 ;
if ( V_35 < 0 || V_35 > 2 )
V_35 = 0 ;
if ( V_36 < 0 || V_36 > 2 )
V_36 = 0 ;
V_11 -> V_29 . V_37 [ 0 ] = V_38 [ V_35 ] ;
V_11 -> V_29 . V_37 [ 1 ] = V_38 [ V_36 ] ;
V_9 -> type = V_39 ;
V_9 -> V_40 = V_41 ;
V_9 -> V_42 = 2 ;
V_9 -> V_43 = 2 ;
V_9 -> V_44 = V_45 ;
V_9 -> V_46 = V_47 ;
V_9 -> V_48 = 0xffff ;
V_9 -> V_49 = V_11 -> V_29 . V_37 ;
return 0 ;
}
static int V_45 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_50 * V_51 , unsigned int * V_52 )
{
union V_10 * V_11 = V_9 -> V_26 ;
V_52 [ 0 ] = V_11 -> V_29 . V_53 [ F_10 ( V_51 -> V_54 ) ] ;
return 1 ;
}
static int V_47 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_50 * V_51 , unsigned int * V_52 )
{
union V_10 * V_11 = V_9 -> V_26 ;
int V_55 , V_56 ;
unsigned int V_57 ;
V_11 -> V_29 . V_53 [ F_10 ( V_51 -> V_54 ) ] = V_52 [ 0 ] ;
V_57 = ( ( ( unsigned int ) V_52 [ 0 ] + 0x8000 ) & 0xffff ) ;
V_56 = ( V_57 & 0xff ) ;
V_55 = ( ( V_57 >> 8 ) & 0xff ) ;
switch ( F_10 ( V_51 -> V_54 ) ) {
case 0 :
F_11 ( V_56 , V_11 -> V_30 + V_58 ) ;
F_11 ( V_55 , V_11 -> V_30 + V_58 + 1 ) ;
F_11 ( 0x00 , V_11 -> V_30 + V_59 ) ;
break;
case 1 :
F_11 ( V_56 , V_11 -> V_30 + V_60 ) ;
F_11 ( V_55 , V_11 -> V_30 + V_60 + 1 ) ;
F_11 ( 0x00 , V_11 -> V_30 + V_61 ) ;
break;
default:
F_5 ( V_20
L_10 , V_2 -> V_21 ) ;
return - V_22 ;
}
return 1 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_8 * V_9 ,
int V_35 , int V_36 )
{
union V_10 * V_11 = V_9 -> V_26 ;
int V_62 ;
if ( V_35 < 0 || V_35 > 3 )
V_35 = 0 ;
V_11 -> V_32 . V_63 = V_64 [ V_35 ] ;
V_11 -> V_32 . V_65 = V_66 [ V_35 ] ;
V_9 -> type = V_67 ;
V_9 -> V_40 = V_68 ;
V_9 -> V_42 = V_69 ;
V_9 -> V_43 = V_70 ;
V_9 -> V_44 = V_71 ;
V_9 -> V_48 = 0xffff ;
V_9 -> V_72 = V_73 [ V_35 ] ;
V_62 = V_11 -> V_32 . V_63 | V_74 ;
F_11 ( V_75 , V_11 -> V_30 + V_76 ) ;
F_11 ( V_77 , V_11 -> V_30 + V_78 ) ;
F_11 ( V_62 , V_11 -> V_30 + V_79 ) ;
F_11 ( V_11 -> V_32 . V_65 ,
V_11 -> V_30 + V_80 ) ;
return 0 ;
}
static int V_71 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_50 * V_51 , unsigned int * V_52 )
{
union V_10 * V_11 = V_9 -> V_26 ;
unsigned int V_5 = 0 , V_81 = 0 ;
int V_56 , V_55 ;
unsigned char V_82 ;
unsigned int V_83 ;
unsigned int V_57 ;
F_11 ( 1 , V_11 -> V_30 + V_84 ) ;
V_83 = V_85 | V_86 | ( V_11 -> V_32 . V_87 << 3 )
| F_10 ( V_51 -> V_54 ) ;
F_11 ( V_83 , V_11 -> V_30 + V_88 ) ;
F_11 ( 0x00 , V_11 -> V_30 + V_89 ) ;
F_11 ( 0x00 , V_11 -> V_30 + V_90 ) ;
for ( V_5 = 0 ; V_5 < V_51 -> V_91 ; V_5 ++ ) {
V_81 = 0 ;
F_4 ( V_11 -> V_30 + V_92 ) ;
V_82 = F_4 ( V_11 -> V_30 + V_93 ) ;
while ( ( V_82 < 0x80 ) && V_81 < 100 ) {
V_81 ++ ;
V_82 = F_4 ( V_11 -> V_30 + V_93 ) ;
}
if ( V_81 >= 100 ) {
F_5 ( V_20
L_11
L_12 ,
V_2 -> V_21 , V_5 ) ;
return - V_22 ;
}
V_56 = F_4 ( V_11 -> V_30 + V_94 ) ;
V_55 = F_4 ( V_11 -> V_30 + V_94 + 1 ) ;
V_57 = V_56 + 0x100 * V_55 ;
V_52 [ V_5 ] = ( short ) ( ( V_57 + 0x8000 ) & 0xffff ) ;
}
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
V_9 -> type = V_95 ;
V_9 -> V_40 = V_68 | V_41 ;
V_9 -> V_42 = 32 ;
V_9 -> V_96 = V_97 ;
V_9 -> V_98 = V_99 ;
V_9 -> V_48 = 1 ;
V_9 -> V_43 = 32 ;
V_9 -> V_72 = & V_100 ;
V_9 -> V_101 = 0 ;
F_12 ( V_2 , V_9 ) ;
return 0 ;
}
static int V_99 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_50 * V_51 ,
unsigned int * V_52 )
{
int V_102 , V_103 ;
V_102 = 1 << F_10 ( V_51 -> V_54 ) ;
if ( V_102 & 0x000000ff )
V_103 = 0x000000ff ;
else if ( V_102 & 0x0000ff00 )
V_103 = 0x0000ff00 ;
else if ( V_102 & 0x00ff0000 )
V_103 = 0x00ff0000 ;
else
V_103 = 0xff000000 ;
if ( V_52 [ 0 ] )
V_9 -> V_101 |= V_103 ;
else
V_9 -> V_101 &= ~ V_103 ;
F_12 ( V_2 , V_9 ) ;
return 1 ;
}
static int V_97 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_50 * V_51 , unsigned int * V_52 )
{
unsigned int V_102 = V_52 [ 0 ] ;
V_9 -> V_104 &= ~ V_102 ;
V_9 -> V_104 |= ( V_102 & V_52 [ 1 ] ) ;
V_102 &= V_9 -> V_101 ;
if ( V_102 & 0x000000ff )
F_11 ( ( V_9 -> V_104 >> 0 ) & 0xff ,
V_14 -> V_15 + V_105 ) ;
if ( V_102 & 0x0000ff00 )
F_11 ( ( V_9 -> V_104 >> 8 ) & 0xff ,
V_14 -> V_15 + V_106 ) ;
if ( V_102 & 0x00ff0000 )
F_11 ( ( V_9 -> V_104 >> 16 ) & 0xff ,
V_14 -> V_15 + V_107 ) ;
if ( V_102 & 0xff000000 )
F_11 ( ( V_9 -> V_104 >> 24 ) & 0xff ,
V_14 -> V_15 + V_108 ) ;
V_52 [ 1 ] = F_4 ( V_14 -> V_15 + V_105 ) ;
V_52 [ 1 ] |= F_4 ( V_14 -> V_15 + V_106 ) << 8 ;
V_52 [ 1 ] |= F_4 ( V_14 -> V_15 + V_107 ) << 16 ;
V_52 [ 1 ] |= F_4 ( V_14 -> V_15 + V_108 ) << 24 ;
return V_51 -> V_91 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
unsigned char V_109 ;
unsigned char V_110 ;
unsigned char V_111 ;
V_109 = F_4 ( V_14 -> V_15 + V_112 ) ;
V_110 = F_4 ( V_14 -> V_15 + V_113 ) ;
V_111 = F_4 ( V_14 -> V_15 + V_114 ) ;
if ( V_9 -> V_101 & 0x000000ff ) {
V_109 &= V_115 ;
V_111 = ( V_111 & ( ~ ( V_116 << V_117 ) ) ) | ( V_118 <<
V_117 ) ;
} else {
V_109 = ( V_109 & V_119 ) | V_120 ;
V_111 = ( V_111 & ( ~ ( V_121 << V_117 ) ) ) ;
}
if ( V_9 -> V_101 & 0x0000ff00 ) {
V_109 &= V_122 ;
V_111 = ( V_111 & ( ~ ( V_116 << V_123 ) ) ) | ( V_118 <<
V_123 ) ;
} else {
V_109 = ( V_109 & V_119 ) | V_124 ;
V_111 = ( V_111 & ( ~ ( V_121 << V_123 ) ) ) ;
}
if ( V_9 -> V_101 & 0x00ff0000 ) {
V_110 &= V_115 ;
V_111 = ( V_111 & ( ~ ( V_116 << V_125 ) ) ) | ( V_118 <<
V_125 ) ;
} else {
V_110 = ( V_110 & V_119 ) | V_120 ;
V_111 = ( V_111 & ( ~ ( V_121 << V_125 ) ) ) ;
}
if ( V_9 -> V_101 & 0xff000000 ) {
V_110 &= V_122 ;
V_111 = ( V_111 & ( ~ ( V_116 << V_126 ) ) ) | ( V_118 <<
V_126 ) ;
} else {
V_110 = ( V_110 & V_119 ) | V_124 ;
V_111 = ( V_111 & ( ~ ( V_121 << V_126 ) ) ) ;
}
F_11 ( V_109 , V_14 -> V_15 + V_112 ) ;
F_11 ( V_110 , V_14 -> V_15 + V_113 ) ;
F_11 ( V_111 , V_14 -> V_15 + V_114 ) ;
}
