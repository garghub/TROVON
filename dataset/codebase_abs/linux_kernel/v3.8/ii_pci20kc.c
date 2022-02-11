static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned char V_7 ;
int V_8 ;
int V_9 ;
struct V_10 * V_11 ;
union V_12 * V_13 ;
V_8 = F_2 ( V_2 , 1 + V_14 ) ;
if ( V_8 )
return V_8 ;
V_6 = F_3 ( sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return - V_16 ;
V_2 -> V_17 = V_6 ;
V_6 -> V_18 = ( void V_19 * ) ( unsigned long ) V_4 -> V_20 [ 0 ] ;
V_2 -> V_21 = L_1 ;
if ( ( F_4 ( V_6 -> V_18 ) & V_22 ) != V_22 ) {
F_5 ( V_2 -> V_23 ,
L_2 ,
V_6 -> V_18 ) ;
return - V_24 ;
}
F_6 ( V_2 -> V_23 , L_3 ,
V_6 -> V_18 ) ;
for ( V_7 = 0 ; V_7 < V_14 ; V_7 ++ ) {
V_11 = & V_2 -> V_25 [ V_7 ] ;
V_9 = F_4 ( V_6 -> V_18 + ( V_7 + 1 ) * V_26 ) ;
V_11 -> V_17 = V_6 -> V_27 + V_7 ;
V_13 = V_11 -> V_17 ;
switch ( V_9 ) {
case V_28 :
V_13 -> V_29 . V_30 =
V_6 -> V_18 + ( V_7 + 1 ) * V_26 ;
F_7 ( V_2 , V_11 , V_4 -> V_20 [ 2 * V_7 + 2 ] ,
V_4 -> V_20 [ 2 * V_7 + 3 ] ) ;
F_6 ( V_2 -> V_23 ,
L_4 , V_7 + 1 ) ;
break;
case V_31 :
V_13 -> V_32 . V_30 =
V_6 -> V_18 + ( V_7 + 1 ) * V_26 ;
F_8 ( V_2 , V_11 , V_4 -> V_20 [ 2 * V_7 + 2 ] ,
V_4 -> V_20 [ 2 * V_7 + 3 ] ) ;
F_6 ( V_2 -> V_23 ,
L_5 , V_7 + 1 ) ;
break;
default:
F_5 ( V_2 -> V_23 ,
L_6 ,
V_9 , V_7 ) ;
case V_33 :
V_11 -> type = V_34 ;
break;
}
}
F_9 ( V_2 , & V_2 -> V_25 [ V_14 ] ) ;
return 1 ;
}
static void F_10 ( struct V_1 * V_2 )
{
}
static int F_7 ( struct V_1 * V_2 , struct V_10 * V_11 ,
int V_35 , int V_36 )
{
union V_12 * V_13 = V_11 -> V_17 ;
if ( V_35 < 0 || V_35 > 2 )
V_35 = 0 ;
if ( V_36 < 0 || V_36 > 2 )
V_36 = 0 ;
V_13 -> V_29 . V_37 [ 0 ] = V_38 [ V_35 ] ;
V_13 -> V_29 . V_37 [ 1 ] = V_38 [ V_36 ] ;
V_11 -> type = V_39 ;
V_11 -> V_40 = V_41 ;
V_11 -> V_42 = 2 ;
V_11 -> V_43 = 2 ;
V_11 -> V_44 = V_45 ;
V_11 -> V_46 = V_47 ;
V_11 -> V_48 = 0xffff ;
V_11 -> V_49 = V_13 -> V_29 . V_37 ;
return 0 ;
}
static int V_45 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_50 * V_51 , unsigned int * V_52 )
{
union V_12 * V_13 = V_11 -> V_17 ;
V_52 [ 0 ] = V_13 -> V_29 . V_53 [ F_11 ( V_51 -> V_54 ) ] ;
return 1 ;
}
static int V_47 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_50 * V_51 , unsigned int * V_52 )
{
union V_12 * V_13 = V_11 -> V_17 ;
int V_55 , V_56 ;
unsigned int V_57 ;
V_13 -> V_29 . V_53 [ F_11 ( V_51 -> V_54 ) ] = V_52 [ 0 ] ;
V_57 = ( ( ( unsigned int ) V_52 [ 0 ] + 0x8000 ) & 0xffff ) ;
V_56 = ( V_57 & 0xff ) ;
V_55 = ( ( V_57 >> 8 ) & 0xff ) ;
switch ( F_11 ( V_51 -> V_54 ) ) {
case 0 :
F_12 ( V_56 , V_13 -> V_30 + V_58 ) ;
F_12 ( V_55 , V_13 -> V_30 + V_58 + 1 ) ;
F_12 ( 0x00 , V_13 -> V_30 + V_59 ) ;
break;
case 1 :
F_12 ( V_56 , V_13 -> V_30 + V_60 ) ;
F_12 ( V_55 , V_13 -> V_30 + V_60 + 1 ) ;
F_12 ( 0x00 , V_13 -> V_30 + V_61 ) ;
break;
default:
F_5 ( V_2 -> V_23 , L_7 ) ;
return - V_24 ;
}
return 1 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_10 * V_11 ,
int V_35 , int V_36 )
{
union V_12 * V_13 = V_11 -> V_17 ;
int V_62 ;
if ( V_35 < 0 || V_35 > 3 )
V_35 = 0 ;
V_13 -> V_32 . V_63 = V_64 [ V_35 ] ;
V_13 -> V_32 . V_65 = V_66 [ V_35 ] ;
V_11 -> type = V_67 ;
V_11 -> V_40 = V_68 ;
V_11 -> V_42 = V_69 ;
V_11 -> V_43 = V_70 ;
V_11 -> V_44 = V_71 ;
V_11 -> V_48 = 0xffff ;
V_11 -> V_72 = V_73 [ V_35 ] ;
V_62 = V_13 -> V_32 . V_63 | V_74 ;
F_12 ( V_75 , V_13 -> V_30 + V_76 ) ;
F_12 ( V_77 , V_13 -> V_30 + V_78 ) ;
F_12 ( V_62 , V_13 -> V_30 + V_79 ) ;
F_12 ( V_13 -> V_32 . V_65 ,
V_13 -> V_30 + V_80 ) ;
return 0 ;
}
static int V_71 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_50 * V_51 , unsigned int * V_52 )
{
union V_12 * V_13 = V_11 -> V_17 ;
unsigned int V_7 = 0 , V_81 = 0 ;
int V_56 , V_55 ;
unsigned char V_82 ;
unsigned int V_83 ;
unsigned int V_57 ;
F_12 ( 1 , V_13 -> V_30 + V_84 ) ;
V_83 = V_85 | V_86 | ( V_13 -> V_32 . V_87 << 3 )
| F_11 ( V_51 -> V_54 ) ;
F_12 ( V_83 , V_13 -> V_30 + V_88 ) ;
F_12 ( 0x00 , V_13 -> V_30 + V_89 ) ;
F_12 ( 0x00 , V_13 -> V_30 + V_90 ) ;
for ( V_7 = 0 ; V_7 < V_51 -> V_91 ; V_7 ++ ) {
V_81 = 0 ;
F_4 ( V_13 -> V_30 + V_92 ) ;
V_82 = F_4 ( V_13 -> V_30 + V_93 ) ;
while ( ( V_82 < 0x80 ) && V_81 < 100 ) {
V_81 ++ ;
V_82 = F_4 ( V_13 -> V_30 + V_93 ) ;
}
if ( V_81 >= 100 ) {
F_5 ( V_2 -> V_23 ,
L_8 , V_7 ) ;
return - V_24 ;
}
V_56 = F_4 ( V_13 -> V_30 + V_94 ) ;
V_55 = F_4 ( V_13 -> V_30 + V_94 + 1 ) ;
V_57 = V_56 + 0x100 * V_55 ;
V_52 [ V_7 ] = ( short ) ( ( V_57 + 0x8000 ) & 0xffff ) ;
}
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
V_11 -> type = V_95 ;
V_11 -> V_40 = V_68 | V_41 ;
V_11 -> V_42 = 32 ;
V_11 -> V_96 = V_97 ;
V_11 -> V_98 = V_99 ;
V_11 -> V_48 = 1 ;
V_11 -> V_43 = 32 ;
V_11 -> V_72 = & V_100 ;
V_11 -> V_101 = 0 ;
F_13 ( V_2 , V_11 ) ;
return 0 ;
}
static int V_99 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_50 * V_51 ,
unsigned int * V_52 )
{
int V_102 , V_103 ;
V_102 = 1 << F_11 ( V_51 -> V_54 ) ;
if ( V_102 & 0x000000ff )
V_103 = 0x000000ff ;
else if ( V_102 & 0x0000ff00 )
V_103 = 0x0000ff00 ;
else if ( V_102 & 0x00ff0000 )
V_103 = 0x00ff0000 ;
else
V_103 = 0xff000000 ;
if ( V_52 [ 0 ] )
V_11 -> V_101 |= V_103 ;
else
V_11 -> V_101 &= ~ V_103 ;
F_13 ( V_2 , V_11 ) ;
return 1 ;
}
static int V_97 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_50 * V_51 , unsigned int * V_52 )
{
struct V_5 * V_6 = V_2 -> V_17 ;
unsigned int V_102 = V_52 [ 0 ] ;
V_11 -> V_104 &= ~ V_102 ;
V_11 -> V_104 |= ( V_102 & V_52 [ 1 ] ) ;
V_102 &= V_11 -> V_101 ;
if ( V_102 & 0x000000ff )
F_12 ( ( V_11 -> V_104 >> 0 ) & 0xff ,
V_6 -> V_18 + V_105 ) ;
if ( V_102 & 0x0000ff00 )
F_12 ( ( V_11 -> V_104 >> 8 ) & 0xff ,
V_6 -> V_18 + V_106 ) ;
if ( V_102 & 0x00ff0000 )
F_12 ( ( V_11 -> V_104 >> 16 ) & 0xff ,
V_6 -> V_18 + V_107 ) ;
if ( V_102 & 0xff000000 )
F_12 ( ( V_11 -> V_104 >> 24 ) & 0xff ,
V_6 -> V_18 + V_108 ) ;
V_52 [ 1 ] = F_4 ( V_6 -> V_18 + V_105 ) ;
V_52 [ 1 ] |= F_4 ( V_6 -> V_18 + V_106 ) << 8 ;
V_52 [ 1 ] |= F_4 ( V_6 -> V_18 + V_107 ) << 16 ;
V_52 [ 1 ] |= F_4 ( V_6 -> V_18 + V_108 ) << 24 ;
return V_51 -> V_91 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = V_2 -> V_17 ;
unsigned char V_109 ;
unsigned char V_110 ;
unsigned char V_111 ;
V_109 = F_4 ( V_6 -> V_18 + V_112 ) ;
V_110 = F_4 ( V_6 -> V_18 + V_113 ) ;
V_111 = F_4 ( V_6 -> V_18 + V_114 ) ;
if ( V_11 -> V_101 & 0x000000ff ) {
V_109 &= V_115 ;
V_111 = ( V_111 & ( ~ ( V_116 << V_117 ) ) ) | ( V_118 <<
V_117 ) ;
} else {
V_109 = ( V_109 & V_119 ) | V_120 ;
V_111 = ( V_111 & ( ~ ( V_121 << V_117 ) ) ) ;
}
if ( V_11 -> V_101 & 0x0000ff00 ) {
V_109 &= V_122 ;
V_111 = ( V_111 & ( ~ ( V_116 << V_123 ) ) ) | ( V_118 <<
V_123 ) ;
} else {
V_109 = ( V_109 & V_119 ) | V_124 ;
V_111 = ( V_111 & ( ~ ( V_121 << V_123 ) ) ) ;
}
if ( V_11 -> V_101 & 0x00ff0000 ) {
V_110 &= V_115 ;
V_111 = ( V_111 & ( ~ ( V_116 << V_125 ) ) ) | ( V_118 <<
V_125 ) ;
} else {
V_110 = ( V_110 & V_119 ) | V_120 ;
V_111 = ( V_111 & ( ~ ( V_121 << V_125 ) ) ) ;
}
if ( V_11 -> V_101 & 0xff000000 ) {
V_110 &= V_122 ;
V_111 = ( V_111 & ( ~ ( V_116 << V_126 ) ) ) | ( V_118 <<
V_126 ) ;
} else {
V_110 = ( V_110 & V_119 ) | V_124 ;
V_111 = ( V_111 & ( ~ ( V_121 << V_126 ) ) ) ;
}
F_12 ( V_109 , V_6 -> V_18 + V_112 ) ;
F_12 ( V_110 , V_6 -> V_18 + V_113 ) ;
F_12 ( V_111 , V_6 -> V_18 + V_114 ) ;
}
