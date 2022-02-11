static bool F_1 ( const T_1 * V_1 , unsigned int V_2 )
{
int V_3 ;
T_1 V_4 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ )
V_4 += V_1 [ V_3 ] ;
if ( V_4 )
return true ;
return false ;
}
static T_2 F_2 ( struct V_5 * V_6 , T_2 V_7 , int V_8 )
{
int V_9 , V_3 = 0 ;
T_2 V_10 , V_11 = 0 ;
if ( V_6 -> V_12 < 5 )
V_9 = 3 ;
else
V_9 = 4 ;
do {
V_10 = F_3 ( V_6 -> V_1 [ V_7 + V_9 * V_3 ] ) ;
if ( V_8 >= V_10 * 10 ) {
if ( V_6 -> V_12 < 5 ) {
T_1 V_13 = V_6 -> V_1 [ V_7 + 2 + V_9 * V_3 ] ;
V_11 = F_3 ( V_6 -> V_1 [ V_6 -> V_14 + V_13 * 2 ] ) ;
} else
V_11 = F_3 ( V_6 -> V_1 [ V_7 + 2 + V_9 * V_3 ] ) ;
break;
}
V_3 ++ ;
} while ( V_10 );
return V_11 ;
}
static void
F_4 ( struct V_15 * V_16 , T_2 V_11 ,
struct V_17 * V_18 , int V_19 , bool V_20 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
F_5 ( V_22 , L_1 ,
V_11 ) ;
F_6 ( V_16 , 0 , V_23 , V_19 ? V_24 :
V_25 ) ;
F_7 ( V_16 , V_11 , V_18 , V_19 ) ;
F_8 ( V_16 , V_18 , V_19 , V_20 ) ;
}
static int F_9 ( struct V_15 * V_16 , struct V_17 * V_18 , int V_19 , enum V_26 V_27 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_1 V_29 = V_6 -> V_1 [ V_6 -> V_30 . V_31 + V_27 ] + ( V_6 -> V_30 . V_32 && V_18 -> V_33 & V_34 ? 1 : 0 ) ;
T_2 V_35 = F_3 ( V_6 -> V_1 [ V_6 -> V_14 + V_29 * 2 ] ) ;
if ( ! V_6 -> V_30 . V_31 || ! V_29 || ! V_35 )
return - V_36 ;
F_4 ( V_16 , V_35 , V_18 , V_19 , V_6 -> V_30 . V_37 ) ;
if ( V_27 == V_38 ) {
F_10 ( F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_31 + 7 ] ) ) ;
}
#ifdef F_11
if ( V_27 == V_39 &&
( V_16 -> V_40 -> V_41 == 0x0179 || V_16 -> V_40 -> V_41 == 0x0189 ||
V_16 -> V_40 -> V_41 == 0x0329 ) )
F_12 ( V_16 , V_18 -> V_33 , 0 , 0x02 , 0x72 ) ;
#endif
return 0 ;
}
static int F_13 ( struct V_15 * V_16 , struct V_17 * V_18 , int V_19 , enum V_26 V_27 , int V_8 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
unsigned int V_42 = ( V_18 -> V_33 == 4 ) ? 1 : 0 ;
T_2 V_11 = 0 , V_7 ;
switch ( V_27 ) {
case V_43 :
return - V_44 ;
case V_45 :
case V_46 :
V_11 = F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_47 + 7 + V_42 * 2 ] ) ;
break;
case V_48 :
case V_38 :
V_11 = F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_47 + 11 + V_42 * 2 ] ) ;
break;
case V_39 :
V_7 = V_6 -> V_30 . V_47 + 15 ;
if ( V_18 -> V_33 == 4 )
V_7 += 8 ;
if ( V_18 -> V_49 . V_50 ) {
if ( V_6 -> V_30 . V_37 )
V_7 += 4 ;
if ( V_6 -> V_30 . V_51 )
V_7 += 2 ;
} else {
int V_52 = ( V_18 -> V_33 == 4 ) ? 4 : 1 ;
if ( V_6 -> V_30 . V_37 ) {
V_7 += 4 ;
V_52 <<= 1 ;
}
if ( V_6 -> V_30 . V_53 & V_52 )
V_7 += 2 ;
}
V_7 = F_3 ( V_6 -> V_1 [ V_7 ] ) ;
if ( ! V_7 ) {
F_14 ( V_22 , L_2 ) ;
return - V_54 ;
}
V_11 = F_2 ( V_6 , V_7 , V_8 ) ;
}
if ( ! V_11 ) {
F_14 ( V_22 , L_3 ) ;
return - V_54 ;
}
F_4 ( V_16 , V_11 , V_18 , V_19 , V_6 -> V_30 . V_37 ) ;
return 0 ;
}
int F_15 ( struct V_15 * V_16 , struct V_17 * V_18 , int V_19 , enum V_26 V_27 , int V_8 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_55 * V_41 = & V_22 -> V_41 . V_56 ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_1 V_57 = V_6 -> V_1 [ V_6 -> V_30 . V_47 ] ;
T_3 V_58 , V_59 ;
int V_60 ;
if ( V_6 -> V_30 . V_61 == ( V_27 << 1 | V_19 ) || ! V_57 ||
( V_57 >= 0x30 && V_27 == V_43 ) )
return 0 ;
if ( ! V_6 -> V_30 . V_62 ) {
V_6 -> V_30 . V_62 = true ;
F_15 ( V_16 , V_18 , V_19 , V_43 , V_8 ) ;
}
if ( V_27 == V_46 && V_6 -> V_30 . V_63 )
F_15 ( V_16 , V_18 , V_19 , V_39 , V_8 ) ;
if ( V_27 == V_39 && V_6 -> V_30 . V_64 )
F_15 ( V_16 , V_18 , V_19 , V_38 , V_8 ) ;
F_5 ( V_22 , L_4 , V_27 ) ;
V_58 = F_16 ( V_41 , V_65 ) & 0x50000 ;
if ( V_57 < 0x30 )
V_60 = F_9 ( V_16 , V_18 , V_19 , V_27 ) ;
else
V_60 = F_13 ( V_16 , V_18 , V_19 , V_27 , V_8 ) ;
V_6 -> V_30 . V_61 = ( V_27 << 1 | V_19 ) ;
V_59 = F_17 ( V_16 , 0 , V_65 ) & ~ 0x50000 ;
F_18 ( V_16 , 0 , V_65 , V_59 | V_58 ) ;
F_19 ( V_41 , V_66 , 0 ) ;
return V_60 ;
}
static int F_20 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_67 * V_68 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_1 V_57 , V_69 , V_70 ;
memset ( V_68 , 0 , sizeof( struct V_67 ) ) ;
if ( V_6 -> V_30 . V_47 == 0x0 ) {
F_14 ( V_22 , L_5 ) ;
return - V_36 ;
}
V_57 = V_6 -> V_1 [ V_6 -> V_30 . V_47 ] ;
switch ( V_57 ) {
case 0x0a :
V_69 = 2 ;
V_70 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 1 ] ;
break;
case 0x30 :
V_69 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 1 ] ;
if ( V_69 < 0x1f ) {
F_14 ( V_22 , L_6 ) ;
return - V_36 ;
}
V_70 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 2 ] ;
break;
case 0x40 :
V_69 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 1 ] ;
if ( V_69 < 0x7 ) {
F_14 ( V_22 , L_6 ) ;
return - V_36 ;
}
V_70 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 2 ] ;
break;
default:
F_14 ( V_22 ,
L_7 ,
V_57 >> 4 , V_57 & 0xf ) ;
return - V_44 ;
}
V_68 -> V_57 = V_57 ;
V_68 -> V_69 = V_69 ;
V_68 -> V_70 = V_70 ;
return 0 ;
}
static int
F_21 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_55 * V_41 = & V_22 -> V_41 . V_56 ;
if ( V_6 -> V_12 < 5 && V_6 -> V_1 [ 0x48 ] & 0x4 )
return F_22 ( V_16 , 0 , 0xf ) & 0xf ;
if ( V_22 -> V_41 . V_71 . V_72 >= V_73 )
return F_16 ( V_41 , 0x001800 ) & 0x0000000f ;
else
if ( V_22 -> V_41 . V_71 . V_72 >= V_74 )
return ( F_16 ( V_41 , V_75 ) >> 24 ) & 0xf ;
else
return ( F_16 ( V_41 , V_75 ) >> 16 ) & 0xf ;
}
static int F_23 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_1 * V_76 ;
T_1 V_77 , V_69 = 0 , V_70 , V_78 = 0xf , V_79 ;
int V_60 , V_80 , V_81 ;
struct V_67 V_68 ;
if ( V_6 -> V_30 . V_82 == 0x0 ) {
#ifndef F_11
F_14 ( V_22 , L_8 ) ;
#endif
V_6 -> V_83 = 0x4b ;
return 0 ;
}
V_76 = & V_6 -> V_1 [ V_6 -> V_30 . V_82 ] ;
V_77 = V_76 [ 0 ] ;
switch ( V_77 ) {
case 0x05 :
V_70 = 42 ;
V_80 = - 1 ;
break;
case 0x10 :
V_70 = 44 ;
V_80 = 0 ;
break;
case 0x20 :
V_69 = V_76 [ 1 ] ;
V_70 = V_76 [ 2 ] ;
V_78 = V_76 [ 3 ] ;
V_6 -> V_83 = V_76 [ 4 ] ;
V_80 = - 7 ;
break;
default:
F_14 ( V_22 ,
L_9 ,
V_77 >> 4 , V_77 & 0xf ) ;
return - V_44 ;
}
if ( ! V_6 -> V_84 )
return 0 ;
V_60 = F_20 ( V_16 , V_6 , & V_68 ) ;
if ( V_60 )
return V_60 ;
if ( V_68 . V_57 == 0x30 || V_68 . V_57 == 0x40 ) {
V_6 -> V_30 . V_85 = V_6 -> V_30 . V_47 +
V_68 . V_69 + 1 ;
V_6 -> V_30 . V_86 = V_68 . V_70 ;
}
if ( V_6 -> V_30 . V_85 == 0x0 ) {
F_14 ( V_22 , L_10 ) ;
return - V_36 ;
}
V_81 = F_21 ( V_16 , V_6 ) ;
V_79 = V_6 -> V_1 [ V_6 -> V_30 . V_85 +
V_81 * V_6 -> V_30 . V_86 ] ;
if ( V_79 > V_78 ) {
F_14 ( V_22 , L_11 ) ;
return - V_54 ;
}
if ( V_68 . V_57 > 0x10 )
V_6 -> V_87 = V_81 != 0xf || V_79 != 0xf ;
if ( V_81 == 0xf || V_79 == 0xf )
return 0 ;
V_6 -> V_30 . V_88 = V_6 -> V_30 . V_82 + V_69 +
V_70 * V_79 + V_80 ;
F_5 ( V_22 , L_12 ,
F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_88 + 11 ] ) + 1 ,
F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_88 + 25 ] ) + 1 ,
F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_88 + 7 ] ) * 10 ) ;
return 0 ;
}
bool F_24 ( struct V_15 * V_16 , struct V_89 * V_90 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_1 * V_91 = & V_6 -> V_1 [ V_6 -> V_30 . V_88 ] ;
if ( ! V_90 )
return V_6 -> V_30 . V_88 ;
memset ( V_90 , 0 , sizeof( struct V_89 ) ) ;
V_90 -> clock = F_3 ( V_91 [ 7 ] ) * 10 ;
V_90 -> V_92 = F_3 ( V_91 [ 11 ] ) + 1 ;
V_90 -> V_93 = F_3 ( V_91 [ 17 ] ) + 1 ;
V_90 -> V_94 = F_3 ( V_91 [ 19 ] ) + 1 ;
V_90 -> V_95 = F_3 ( V_91 [ 21 ] ) + 1 ;
V_90 -> V_96 = F_3 ( V_91 [ 25 ] ) + 1 ;
V_90 -> V_97 = F_3 ( V_91 [ 31 ] ) + 1 ;
V_90 -> V_98 = F_3 ( V_91 [ 33 ] ) + 1 ;
V_90 -> V_99 = F_3 ( V_91 [ 35 ] ) + 1 ;
V_90 -> V_100 |= ( V_91 [ 37 ] & 0x10 ) ?
V_101 : V_102 ;
V_90 -> V_100 |= ( V_91 [ 37 ] & 0x1 ) ?
V_103 : V_104 ;
V_90 -> V_105 = V_106 ;
V_90 -> type = V_107 | V_108 ;
F_25 ( V_90 ) ;
return V_6 -> V_30 . V_88 ;
}
int F_26 ( struct V_15 * V_16 , int V_8 , bool * V_20 , bool * V_51 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_81 = F_21 ( V_16 , V_6 ) , V_109 = 0 ;
struct V_67 V_68 ;
T_2 V_110 ;
int V_60 , V_111 = V_6 -> V_111 ;
V_60 = F_20 ( V_16 , V_6 , & V_68 ) ;
if ( V_60 )
return V_60 ;
switch ( V_68 . V_57 ) {
case 0x0a :
V_109 = V_6 -> V_1 [
V_6 -> V_30 . V_112 +
V_81 ] ;
if ( ! V_8 )
break;
if ( V_111 < 0x25 ) {
V_109 =
( V_6 -> V_113 . V_114 & 1 ) ?
2 : 0 ;
if ( V_8 >= V_6 -> V_30 . V_115 )
V_109 ++ ;
} else if ( V_111 < 0x30 ) {
V_109 = 0 ;
} else {
V_109 = 0 ;
if ( V_8 >= V_6 -> V_30 . V_115 )
V_109 = 2 ;
if ( V_8 >= 140000 )
V_109 = 3 ;
}
break;
case 0x30 :
case 0x40 :
V_109 = V_81 ;
break;
default:
F_14 ( V_22 , L_13 ) ;
return - V_44 ;
}
V_110 = V_6 -> V_30 . V_31 = V_6 -> V_30 . V_47 + V_68 . V_69 + V_68 . V_70 * V_109 ;
switch ( V_68 . V_57 ) {
case 0x0a :
V_6 -> V_30 . V_64 = V_6 -> V_1 [ V_110 ] & 1 ;
V_6 -> V_30 . V_63 = V_6 -> V_1 [ V_110 ] & 2 ;
V_6 -> V_30 . V_37 = V_6 -> V_1 [ V_110 ] & 4 ;
V_6 -> V_30 . V_32 = V_6 -> V_1 [ V_110 ] & 8 ;
* V_51 = V_6 -> V_1 [ V_110 ] & 16 ;
break;
case 0x30 :
case 0x40 :
V_6 -> V_30 . V_64 = true ;
V_6 -> V_30 . V_63 = true ;
V_6 -> V_30 . V_37 = V_6 -> V_1 [ V_110 ] & 1 ;
V_6 -> V_30 . V_51 = V_6 -> V_1 [ V_110 ] & 2 ;
V_6 -> V_30 . V_53 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 4 ] ;
V_6 -> V_30 . V_115 = F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_47 + 5 ] ) * 10 ;
break;
}
if ( V_8 && ( V_111 < 0x25 || V_111 > 0x28 ) )
V_6 -> V_30 . V_37 = ( V_8 >= V_6 -> V_30 . V_115 ) ;
* V_20 = V_6 -> V_30 . V_37 ;
return 0 ;
}
int F_27 ( struct V_15 * V_16 , struct V_17 * V_18 , int V_19 , int V_8 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_55 * V_41 = & V_22 -> V_41 . V_56 ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_116 = V_6 -> V_111 ;
T_2 V_7 = 0 , V_11 ;
T_3 V_58 , V_59 ;
if ( V_116 >= 0x17 && V_116 != 0x1a && V_116 != 0x20 &&
V_18 -> V_117 != V_118 )
return 0 ;
switch ( F_28 ( V_18 -> V_33 ) ) {
case 1 :
V_7 = V_6 -> V_119 . V_120 ;
break;
case 2 :
case 3 :
V_7 = V_6 -> V_119 . V_121 ;
break;
}
if ( ! V_7 ) {
F_14 ( V_22 , L_2 ) ;
return - V_36 ;
}
V_11 = F_2 ( V_6 , V_7 , V_8 ) ;
if ( ! V_11 ) {
F_14 ( V_22 , L_14 ) ;
return - V_54 ;
}
V_58 = F_16 ( V_41 , V_65 ) & 0x50000 ;
F_4 ( V_16 , V_11 , V_18 , V_19 , V_8 >= 165000 ) ;
V_59 = F_17 ( V_16 , 0 , V_65 ) & ~ 0x50000 ;
F_18 ( V_16 , 0 , V_65 , V_59 | V_58 ) ;
return 0 ;
}
static void F_29 ( struct V_5 * V_6 , T_2 V_122 )
{
V_6 -> V_14 = F_3 ( V_6 -> V_1 [ V_122 ] ) ;
}
static int F_30 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_123 * V_124 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_125 ;
T_1 V_126 , V_69 , V_127 , V_128 ;
if ( V_124 -> V_2 != 3 ) {
F_14 ( V_22 , L_15 ) ;
return - V_36 ;
}
V_125 = F_3 ( V_6 -> V_1 [ V_124 -> V_122 ] ) ;
if ( V_125 == 0x0 ) {
F_31 ( V_22 , L_16 ) ;
return - V_36 ;
}
V_126 = V_6 -> V_1 [ V_125 ] ;
if ( V_126 != 0x10 ) {
F_14 ( V_22 , L_17 ,
V_126 >> 4 , V_126 & 0xF ) ;
return - V_44 ;
}
V_69 = V_6 -> V_1 [ V_125 + 1 ] ;
V_127 = V_6 -> V_1 [ V_125 + 2 ] ;
V_128 = V_6 -> V_1 [ V_125 + 3 ] ;
if ( V_69 != 4 || V_127 != 4 || V_128 != 2 ) {
F_14 ( V_22 , L_18 ) ;
return - V_36 ;
}
V_6 -> V_129 = F_32 ( V_6 -> V_1 [ V_125 + V_69 ] ) & 0x3ff ;
return 0 ;
}
static int F_33 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_123 * V_124 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_124 -> V_2 != 4 ) {
F_14 ( V_22 , L_19 ) ;
return - V_36 ;
}
V_6 -> V_30 . V_82 = F_3 ( V_6 -> V_1 [ V_124 -> V_122 + 2 ] ) ;
return 0 ;
}
static int F_34 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_123 * V_124 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_124 -> V_2 < 14 ) {
F_14 ( V_22 , L_20 ) ;
return - V_36 ;
}
F_29 ( V_6 , V_124 -> V_122 ) ;
return 0 ;
}
static int F_35 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_123 * V_124 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_130 ;
T_1 V_131 , V_132 ;
if ( V_124 -> V_2 < 6 ) {
F_14 ( V_22 , L_21 ) ;
return - V_36 ;
}
V_6 -> V_133 = V_6 -> V_1 [ V_124 -> V_122 + 5 ] ;
V_6 -> V_84 = V_6 -> V_133 & V_134 ;
if ( V_124 -> V_2 < 15 ) {
F_36 ( V_22 , L_22
L_23 ) ;
return - V_36 ;
}
V_130 = F_3 ( V_6 -> V_1 [ V_124 -> V_122 + 13 ] ) ;
if ( ! V_130 )
return 0 ;
V_131 = V_6 -> V_1 [ V_130 ] ;
V_132 = V_6 -> V_1 [ V_130 + 1 ] ;
if ( V_131 != 0x00 && V_131 != 0x10 ) {
F_36 ( V_22 , L_24
L_25 , V_131 >> 4 , V_131 & 0xf ) ;
return - V_44 ;
}
V_6 -> V_129 = F_32 ( V_6 -> V_1 [ V_130 + V_132 ] ) ;
V_6 -> V_135 = F_32 ( V_6 -> V_1 [ V_130 + V_132 + 4 ] ) ;
return 0 ;
}
static int F_37 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_123 * V_124 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_124 -> V_2 != 2 ) {
F_14 ( V_22 , L_26 ) ;
return - V_36 ;
}
V_6 -> V_30 . V_47 = F_3 ( V_6 -> V_1 [ V_124 -> V_122 ] ) ;
return 0 ;
}
static int
F_38 ( struct V_15 * V_16 , struct V_5 * V_6 ,
struct V_123 * V_124 )
{
if ( V_124 -> V_2 < 0x5 )
return 0 ;
if ( V_124 -> V_126 < 2 ) {
V_6 -> V_136 = V_6 -> V_1 [ V_124 -> V_122 + 2 ] ;
V_6 -> V_137 = F_3 ( V_6 -> V_1 [ V_124 -> V_122 + 3 ] ) ;
} else {
V_6 -> V_136 = V_6 -> V_1 [ V_124 -> V_122 + 0 ] ;
V_6 -> V_137 = F_3 ( V_6 -> V_1 [ V_124 -> V_122 + 1 ] ) ;
}
return 0 ;
}
static int F_39 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_123 * V_124 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_138 , V_139 , V_140 ;
if ( V_124 -> V_2 != 2 ) {
F_14 ( V_22 , L_27 ) ;
return - V_36 ;
}
V_138 = F_3 ( V_6 -> V_1 [ V_124 -> V_122 ] ) ;
if ( ! V_138 ) {
F_14 ( V_22 , L_28 ) ;
return - V_36 ;
}
F_5 ( V_22 , L_29 ,
V_6 -> V_1 [ V_138 ] >> 4 , V_6 -> V_1 [ V_138 ] & 0xf ) ;
if ( V_6 -> V_1 [ V_138 ] != 0x11 )
return - V_44 ;
V_139 = F_3 ( V_6 -> V_1 [ V_138 + 7 ] ) ;
V_140 = F_3 ( V_6 -> V_1 [ V_138 + 9 ] ) ;
if ( V_6 -> V_1 [ V_139 ] != 'q' || V_6 -> V_1 [ V_140 ] != 'q' )
F_36 ( V_22 , L_30 ) ;
V_6 -> V_119 . V_120 = F_3 ( V_6 -> V_1 [ V_138 + 11 ] ) ;
V_6 -> V_119 . V_121 = F_3 ( V_6 -> V_1 [ V_138 + 13 ] ) ;
return 0 ;
}
int
F_40 ( struct V_15 * V_16 , T_4 V_141 , struct V_123 * V_142 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_4 V_143 , * V_144 ;
if ( V_6 -> type != V_145 )
return - V_146 ;
V_143 = V_6 -> V_1 [ V_6 -> V_122 + 10 ] ;
V_144 = & V_6 -> V_1 [ V_6 -> V_122 + 12 ] ;
while ( V_143 -- ) {
if ( V_144 [ 0 ] == V_141 ) {
V_142 -> V_141 = V_144 [ 0 ] ;
V_142 -> V_126 = V_144 [ 1 ] ;
V_142 -> V_2 = F_3 ( V_144 [ 2 ] ) ;
V_142 -> V_122 = F_3 ( V_144 [ 4 ] ) ;
V_142 -> V_1 = F_41 ( V_16 , V_144 [ 4 ] ) ;
return 0 ;
}
V_144 += V_6 -> V_1 [ V_6 -> V_122 + 9 ] ;
}
return - V_54 ;
}
static int
F_42 ( struct V_5 * V_6 , const T_2 V_147 ,
struct F_40 * V_148 )
{
struct V_15 * V_16 = V_6 -> V_16 ;
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_123 V_124 ;
if ( F_40 ( V_16 , V_148 -> V_141 , & V_124 ) == 0 )
return V_148 -> V_149 ( V_16 , V_6 , & V_124 ) ;
F_5 ( V_22 , L_31 , V_148 -> V_141 ) ;
return - V_44 ;
}
static int
F_43 ( struct V_5 * V_6 , const T_2 V_147 )
{
int V_60 ;
V_60 = F_42 ( V_6 , V_147 , & F_44 ( 'i' , V_3 ) ) ;
if ( V_60 )
return V_60 ;
if ( V_6 -> V_12 >= 0x60 )
F_42 ( V_6 , V_147 , & F_44 ( 'A' , V_150 ) ) ;
F_42 ( V_6 , V_147 , & F_44 ( 'D' , V_151 ) ) ;
V_60 = F_42 ( V_6 , V_147 , & F_44 ( 'I' , V_152 ) ) ;
if ( V_60 )
return V_60 ;
F_42 ( V_6 , V_147 , & F_44 ( 'M' , V_153 ) ) ;
F_42 ( V_6 , V_147 , & F_44 ( 'L' , V_154 ) ) ;
F_42 ( V_6 , V_147 , & F_44 ( 'T' , V_119 ) ) ;
return 0 ;
}
static int F_45 ( struct V_15 * V_16 , struct V_5 * V_6 , unsigned int V_122 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_1 * V_155 = & V_6 -> V_1 [ V_122 ] , V_156 , V_157 ;
T_2 V_158 ;
T_2 V_159 , V_160 ;
V_6 -> V_83 = 0x4b ;
V_6 -> V_161 = 256000 ;
V_6 -> V_162 = 128000 ;
V_6 -> V_30 . V_115 = 90000 ;
V_156 = V_155 [ 5 ] ;
V_157 = V_155 [ 6 ] ;
F_5 ( V_22 , L_32 ,
V_156 , V_157 ) ;
if ( V_156 < 5 )
* ( T_2 * ) & V_6 -> V_1 [ 0x36 ] = 0 ;
if ( ( V_156 < 5 && V_157 != 1 ) || V_156 > 5 ) {
F_14 ( V_22 , L_33
L_34 ) ;
return - V_44 ;
}
if ( V_156 == 0 )
return 0 ;
else if ( V_156 == 1 )
V_158 = 44 ;
else if ( V_156 == 2 )
V_158 = 48 ;
else if ( V_156 == 3 )
V_158 = 54 ;
else if ( V_156 == 4 || V_157 < 0x1 )
V_158 = 62 ;
else if ( V_157 < 0x6 )
V_158 = 67 ;
else if ( V_157 < 0x10 )
V_158 = 75 ;
else if ( V_157 == 0x10 )
V_158 = 89 ;
else if ( V_157 < 0x14 )
V_158 = 118 ;
else if ( V_157 < 0x24 )
V_158 = 123 ;
else if ( V_157 < 0x27 )
V_158 = 144 ;
else
V_158 = 158 ;
if ( F_1 ( V_155 , 8 ) ) {
F_14 ( V_22 , L_35 ) ;
return - V_36 ;
}
V_6 -> V_133 = V_155 [ 9 ] ;
if ( V_156 < 5 || V_157 < 0x10 )
V_6 -> V_163 = true ;
V_159 = 18 ;
if ( V_156 < 2 )
V_159 -= 4 ;
V_6 -> V_14 = F_3 ( V_155 [ V_159 ] ) ;
V_6 -> V_164 = F_3 ( V_155 [ V_159 + 2 ] ) ;
if ( V_156 > 2 ) {
V_6 -> V_113 . V_165 = F_3 ( V_155 [ 24 ] ) ;
V_6 -> V_113 . V_166 = F_3 ( V_155 [ 26 ] ) ;
V_6 -> V_113 . V_167 = F_3 ( V_155 [ 28 ] ) ;
}
V_160 = 0x48 ;
if ( V_158 > 61 )
V_160 = V_122 + 54 ;
V_6 -> V_113 . V_168 . V_169 = V_6 -> V_1 [ V_160 ] ;
V_6 -> V_113 . V_168 . V_170 = V_6 -> V_1 [ V_160 + 1 ] ;
V_6 -> V_113 . V_168 . V_171 = V_6 -> V_1 [ V_160 + 2 ] ;
if ( V_158 > 74 ) {
V_6 -> V_161 = F_32 ( V_155 [ 67 ] ) ;
V_6 -> V_162 = F_32 ( V_155 [ 71 ] ) ;
}
if ( V_158 > 88 )
F_29 ( V_6 , V_122 + 75 ) ;
if ( V_158 > 94 ) {
V_6 -> V_119 . V_120 = F_3 ( V_155 [ 89 ] ) ;
V_6 -> V_119 . V_121 = F_3 ( V_155 [ 91 ] ) ;
V_6 -> V_113 . V_114 = F_3 ( V_155 [ 95 ] ) ;
}
if ( V_158 > 108 ) {
V_6 -> V_30 . V_82 = F_3 ( V_155 [ 105 ] ) ;
V_6 -> V_30 . V_85 = F_3 ( V_155 [ 107 ] ) ;
V_6 -> V_30 . V_86 = 1 ;
}
if ( V_158 > 120 ) {
V_6 -> V_30 . V_47 = F_3 ( V_155 [ 117 ] ) ;
V_6 -> V_30 . V_112 = F_3 ( V_155 [ 119 ] ) ;
}
#if 0
if (bmplength > 143)
bios->pll_limit_tbl_ptr = ROM16(bmp[142]);
#endif
if ( V_158 > 157 )
V_6 -> V_30 . V_115 = F_3 ( V_155 [ 156 ] ) * 10 ;
return 0 ;
}
static T_2 F_46 ( T_1 * V_1 , int V_172 , const T_1 * V_173 , int V_174 )
{
int V_3 , V_175 ;
for ( V_3 = 0 ; V_3 <= ( V_172 - V_174 ) ; V_3 ++ ) {
for ( V_175 = 0 ; V_175 < V_174 ; V_175 ++ )
if ( V_1 [ V_3 + V_175 ] != V_173 [ V_175 ] )
break;
if ( V_175 == V_174 )
return V_3 ;
}
return 0 ;
}
void *
F_47 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_4 * V_176 = NULL ;
if ( V_22 -> V_41 . V_71 . V_72 > V_177 )
V_176 = F_41 ( V_16 , V_22 -> V_28 . V_1 [ 0x36 ] ) ;
if ( ! V_176 ) {
F_36 ( V_22 , L_36 ) ;
return NULL ;
}
if ( V_176 [ 0 ] >= 0x42 ) {
F_36 ( V_22 , L_37 , V_176 [ 0 ] ) ;
return NULL ;
} else
if ( V_176 [ 0 ] >= 0x30 ) {
if ( F_32 ( V_176 [ 6 ] ) == 0x4edcbdcb )
return V_176 ;
} else
if ( V_176 [ 0 ] >= 0x20 ) {
if ( F_32 ( V_176 [ 4 ] ) == 0x4edcbdcb )
return V_176 ;
} else
if ( V_176 [ 0 ] >= 0x15 ) {
if ( ! memcmp ( & V_176 [ - 7 ] , L_38 , 7 ) )
return V_176 ;
} else {
F_36 ( V_22 , L_39 ) ;
return NULL ;
}
F_36 ( V_22 , L_40 ) ;
return NULL ;
}
void *
F_48 ( struct V_15 * V_16 , T_4 V_178 )
{
T_4 * V_176 = F_47 ( V_16 ) ;
if ( V_176 && V_176 [ 0 ] >= 0x30 ) {
if ( V_178 < V_176 [ 2 ] )
return V_176 + V_176 [ 1 ] + ( V_178 * V_176 [ 3 ] ) ;
} else
if ( V_176 && V_176 [ 0 ] >= 0x20 ) {
T_4 * V_179 = F_41 ( V_16 , V_176 [ 2 ] ) ;
T_4 * V_180 = V_176 + 8 + ( V_178 * 8 ) ;
if ( V_179 && V_180 < V_179 )
return V_180 ;
} else
if ( V_176 && V_176 [ 0 ] >= 0x15 ) {
T_4 * V_179 = F_41 ( V_16 , V_176 [ 2 ] ) ;
T_4 * V_180 = V_176 + 4 + ( V_178 * 10 ) ;
if ( V_179 && V_180 < V_179 )
return V_180 ;
}
return NULL ;
}
int
F_49 ( struct V_15 * V_16 , void * V_1 ,
int (* F_50)( struct V_15 * , void * , int V_178 , T_4 * V_181 ) )
{
int V_60 , V_178 = - 1 ;
T_4 * V_181 = NULL ;
while ( ( V_181 = F_48 ( V_16 , ++ V_178 ) ) ) {
if ( F_32 ( V_181 [ 0 ] ) == 0x00000000 )
break;
if ( F_32 ( V_181 [ 0 ] ) == 0xffffffff )
break;
if ( ( V_181 [ 0 ] & 0x0f ) == V_182 )
continue;
if ( ( V_181 [ 0 ] & 0x0f ) == V_183 )
break;
V_60 = F_50 ( V_16 , V_1 , V_178 , V_181 ) ;
if ( V_60 )
return V_60 ;
}
return 0 ;
}
T_4 *
F_51 ( struct V_15 * V_16 )
{
T_4 * V_176 = F_47 ( V_16 ) ;
if ( V_176 && V_176 [ 0 ] >= 0x30 && V_176 [ 1 ] >= 0x16 ) {
T_4 * V_184 = F_41 ( V_16 , V_176 [ 0x14 ] ) ;
if ( V_184 && V_184 [ 0 ] >= 0x30 && V_184 [ 0 ] <= 0x40 )
return V_184 ;
}
return NULL ;
}
T_4 *
F_52 ( struct V_15 * V_16 , T_4 V_178 )
{
T_4 * V_184 = F_51 ( V_16 ) ;
if ( V_184 && V_178 < V_184 [ 2 ] )
return V_184 + V_184 [ 1 ] + ( V_178 * V_184 [ 3 ] ) ;
return NULL ;
}
static struct V_17 * F_53 ( struct V_185 * V_176 )
{
struct V_17 * V_144 = & V_176 -> V_144 [ V_176 -> V_143 ] ;
memset ( V_144 , 0 , sizeof( struct V_17 ) ) ;
V_144 -> V_186 = V_176 -> V_143 ++ ;
return V_144 ;
}
static void F_54 ( struct V_185 * V_176 , int type , int V_179 ,
int V_187 , int V_33 )
{
struct V_17 * V_144 = F_53 ( V_176 ) ;
V_144 -> type = type ;
V_144 -> V_188 = V_179 ;
V_144 -> V_187 = V_187 ;
if ( type != V_189 )
V_144 -> V_117 = ! V_118 ;
V_144 -> V_33 = V_33 ;
}
static bool
F_55 ( struct V_15 * V_16 , struct V_185 * V_176 ,
T_3 V_190 , T_3 V_191 , struct V_17 * V_144 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
int V_192 = 0 ;
V_144 -> type = V_190 & 0xf ;
V_144 -> V_188 = ( V_190 >> 4 ) & 0xf ;
V_144 -> V_187 = ( V_190 >> 8 ) & 0xf ;
V_144 -> V_193 = ( V_190 >> 12 ) & 0xf ;
V_144 -> V_194 = ( V_190 >> 16 ) & 0xf ;
V_144 -> V_117 = ( V_190 >> 20 ) & 0x3 ;
V_144 -> V_33 = ( V_190 >> 24 ) & 0xf ;
switch ( V_144 -> type ) {
case V_189 :
V_144 -> V_195 . V_196 = ( V_176 -> V_126 < 0x30 ) ?
( V_191 & 0xffff ) * 10 :
( V_191 & 0xff ) * 10000 ;
break;
case V_197 :
{
T_3 V_198 ;
if ( V_191 & 0x1 )
V_144 -> V_49 . V_50 = true ;
if ( V_176 -> V_126 < 0x22 ) {
V_198 = ~ 0xd ;
V_144 -> V_49 . V_50 = true ;
if ( V_191 & 0x4 || V_191 & 0x8 )
V_144 -> V_49 . V_199 = true ;
} else {
V_198 = ~ 0x7 ;
if ( V_191 & 0x2 )
V_144 -> V_49 . V_200 = true ;
if ( V_191 & 0x4 )
V_144 -> V_49 . V_199 = true ;
V_144 -> V_49 . V_201 . V_192 = ( V_191 & 0x00000030 ) >> 4 ;
V_192 = V_144 -> V_49 . V_201 . V_192 ;
}
if ( V_191 & V_198 ) {
if ( V_176 -> V_126 >= 0x40 )
break;
F_14 ( V_22 , L_41
L_42 ) ;
}
break;
}
case V_202 :
{
if ( V_176 -> V_126 >= 0x30 )
V_144 -> V_203 . V_204 = V_191 & ( 0x8 << 4 ) ;
else
V_144 -> V_203 . V_204 = false ;
break;
}
case V_205 :
V_144 -> V_206 . V_201 . V_192 = ( V_191 & 0x00000030 ) >> 4 ;
V_144 -> V_207 = ( V_191 & 0x0000ff00 ) >> 8 ;
switch ( ( V_191 & 0x00e00000 ) >> 21 ) {
case 0 :
V_144 -> V_206 . V_208 = 162000 ;
break;
case 1 :
V_144 -> V_206 . V_208 = 270000 ;
break;
default:
V_144 -> V_206 . V_208 = 540000 ;
break;
}
switch ( ( V_191 & 0x0f000000 ) >> 24 ) {
case 0xf :
case 0x4 :
V_144 -> V_206 . V_209 = 4 ;
break;
case 0x3 :
case 0x2 :
V_144 -> V_206 . V_209 = 2 ;
break;
default:
V_144 -> V_206 . V_209 = 1 ;
break;
}
V_192 = V_144 -> V_206 . V_201 . V_192 ;
break;
case V_210 :
if ( V_176 -> V_126 >= 0x40 ) {
V_144 -> V_211 . V_201 . V_192 = ( V_191 & 0x00000030 ) >> 4 ;
V_144 -> V_207 = ( V_191 & 0x0000ff00 ) >> 8 ;
V_192 = V_144 -> V_211 . V_201 . V_192 ;
}
else if ( V_176 -> V_126 >= 0x30 )
V_144 -> V_211 . V_212 = ( V_191 & 0x00000700 ) >> 8 ;
else if ( V_176 -> V_126 >= 0x22 )
V_144 -> V_211 . V_212 = ( V_191 & 0x00000070 ) >> 4 ;
break;
case V_183 :
V_176 -> V_143 -- ;
return false ;
default:
break;
}
if ( V_176 -> V_126 < 0x40 ) {
V_144 -> V_213 =
( ( 1 << ( F_28 ( V_144 -> V_33 ) - 1 ) ) * 3 == V_144 -> V_33 ) ;
} else {
V_144 -> V_213 = ( V_144 -> V_214 . V_192 == 3 ) ;
}
if ( V_191 & 0x100000 )
V_144 -> V_215 = true ;
V_144 -> V_216 = ( V_144 -> V_117 << 4 ) | V_144 -> type ;
V_144 -> V_217 = ( V_144 -> V_187 << 8 ) | ( V_192 << 6 ) | V_144 -> V_33 ;
return true ;
}
static bool
F_56 ( struct V_15 * V_16 , struct V_185 * V_176 ,
T_3 V_190 , T_3 V_191 , struct V_17 * V_144 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
switch ( V_190 & 0x0000000f ) {
case 0 :
V_144 -> type = V_189 ;
break;
case 1 :
V_144 -> type = V_202 ;
break;
case 2 :
case 4 :
if ( V_190 & 0x10 )
V_144 -> type = V_197 ;
else
V_144 -> type = V_210 ;
break;
case 3 :
V_144 -> type = V_197 ;
break;
default:
F_14 ( V_22 , L_43 , V_190 & 0x0000000f ) ;
return false ;
}
V_144 -> V_188 = ( V_190 & 0x0003c000 ) >> 14 ;
V_144 -> V_187 = ( ( V_190 & 0x001c0000 ) >> 18 ) + 1 ;
V_144 -> V_33 = V_144 -> V_187 ;
V_144 -> V_117 = ( V_190 & 0x01e00000 ) >> 21 ;
V_144 -> V_194 = ( V_190 & 0x0e000000 ) >> 25 ;
V_144 -> V_213 = false ;
switch ( V_144 -> type ) {
case V_189 :
V_144 -> V_195 . V_196 = ( V_191 & 0xffff ) * 10 ;
break;
case V_202 :
V_144 -> V_203 . V_204 = false ;
break;
case V_197 :
if ( ( V_190 & 0x00003f00 ) >> 8 != 0x10 )
V_144 -> V_49 . V_50 = true ;
V_144 -> V_49 . V_199 = true ;
break;
default:
break;
}
return true ;
}
static
void F_57 ( struct V_15 * V_16 , struct V_185 * V_176 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
int V_3 , V_218 = 0 ;
for ( V_3 = 0 ; V_3 < V_176 -> V_143 ; V_3 ++ ) {
struct V_17 * V_219 = & V_176 -> V_144 [ V_3 ] ;
int V_175 ;
for ( V_175 = V_3 + 1 ; V_175 < V_176 -> V_143 ; V_175 ++ ) {
struct V_17 * V_220 = & V_176 -> V_144 [ V_175 ] ;
if ( V_220 -> type == 100 )
continue;
if ( V_220 -> V_188 == V_219 -> V_188 &&
V_220 -> type == V_219 -> type &&
V_220 -> V_117 == V_219 -> V_117 &&
V_220 -> V_33 == V_219 -> V_33 ) {
F_5 ( V_22 , L_44 ,
V_3 , V_175 ) ;
V_219 -> V_187 |= V_220 -> V_187 ;
V_220 -> type = 100 ;
}
}
}
for ( V_3 = 0 ; V_3 < V_176 -> V_143 ; V_3 ++ ) {
if ( V_176 -> V_144 [ V_3 ] . type == 100 )
continue;
if ( V_218 != V_3 ) {
V_176 -> V_144 [ V_218 ] = V_176 -> V_144 [ V_3 ] ;
V_176 -> V_144 [ V_218 ] . V_186 = V_218 ;
}
V_218 ++ ;
}
V_176 -> V_143 = V_218 ;
}
static bool
F_58 ( struct V_15 * V_16 , int V_178 , T_5 * V_190 , T_5 * V_191 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_185 * V_176 = & V_22 -> V_28 . V_176 ;
if ( F_59 ( V_16 , 0x040d , 0x1028 , 0x019b ) ) {
if ( * V_190 == 0x02026312 && * V_191 == 0x00000020 )
return false ;
}
if ( F_59 ( V_16 , 0x0201 , 0x1462 , 0x8851 ) ) {
if ( * V_190 == 0xf2005014 && * V_191 == 0xffffffff ) {
F_54 ( V_176 , V_210 , 1 , 1 , 1 ) ;
return false ;
}
}
if ( F_59 ( V_16 , 0x0ca3 , 0x1682 , 0x3003 ) ) {
if ( V_178 == 0 ) {
* V_190 = 0x02001300 ;
* V_191 = 0x00000028 ;
} else
if ( V_178 == 1 ) {
* V_190 = 0x01010312 ;
* V_191 = 0x00020030 ;
} else
if ( V_178 == 2 ) {
* V_190 = 0x01010310 ;
* V_191 = 0x00000028 ;
} else
if ( V_178 == 3 ) {
* V_190 = 0x02022362 ;
* V_191 = 0x00020010 ;
} else {
* V_190 = 0x0000000e ;
* V_191 = 0x00000000 ;
}
}
if ( F_59 ( V_16 , 0x0615 , 0x1682 , 0x2605 ) ) {
if ( V_178 == 0 ) {
* V_190 = 0x02002300 ;
* V_191 = 0x00000028 ;
} else
if ( V_178 == 1 ) {
* V_190 = 0x01010312 ;
* V_191 = 0x00020030 ;
} else
if ( V_178 == 2 ) {
* V_190 = 0x04020310 ;
* V_191 = 0x00000028 ;
} else
if ( V_178 == 3 ) {
* V_190 = 0x02021322 ;
* V_191 = 0x00020010 ;
} else {
* V_190 = 0x0000000e ;
* V_191 = 0x00000000 ;
}
}
if ( F_59 ( V_16 , 0x0421 , 0x3842 , 0xc793 ) ) {
if ( V_178 == 0 && * V_190 == 0x02000300 )
* V_190 = 0x02011300 ;
else
if ( V_178 == 1 && * V_190 == 0x04011310 )
* V_190 = 0x04000310 ;
else
if ( V_178 == 2 && * V_190 == 0x02011312 )
* V_190 = 0x02000312 ;
}
return true ;
}
static void
F_60 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_185 * V_176 = & V_6 -> V_176 ;
int V_221 = ( F_61 ( V_16 ) ? 3 : 1 ) ;
#ifdef F_11
if ( F_62 ( L_45 ) ) {
F_54 ( V_176 , V_210 , 0 , V_221 , 1 ) ;
F_54 ( V_176 , V_189 , 1 , V_221 , 2 ) ;
return;
}
#endif
F_54 ( V_176 , V_189 ,
V_6 -> V_113 . V_168 . V_169 , 1 , 1 ) ;
if ( F_63 ( V_16 , V_6 -> V_113 . V_168 . V_170 ) >= 0 )
F_54 ( V_176 , V_202 ,
V_6 -> V_113 . V_168 . V_170 ,
V_221 , 0 ) ;
else if ( V_6 -> V_119 . V_120 ||
V_6 -> V_119 . V_121 )
F_54 ( V_176 , V_210 ,
V_6 -> V_113 . V_168 . V_171 ,
V_221 , 1 ) ;
}
static int
F_64 ( struct V_15 * V_16 , void * V_1 , int V_178 , T_4 * V_181 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_185 * V_176 = & V_22 -> V_28 . V_176 ;
T_5 V_191 = ( V_176 -> V_126 >= 0x20 ) ? F_32 ( V_181 [ 4 ] ) : F_32 ( V_181 [ 6 ] ) ;
T_5 V_190 = F_32 ( V_181 [ 0 ] ) ;
bool V_60 ;
if ( F_58 ( V_16 , V_178 , & V_190 , & V_191 ) ) {
struct V_17 * V_144 = F_53 ( V_176 ) ;
F_5 ( V_22 , L_46 , V_178 , V_190 , V_191 ) ;
if ( V_176 -> V_126 >= 0x20 )
V_60 = F_55 ( V_16 , V_176 , V_190 , V_191 , V_144 ) ;
else
V_60 = F_56 ( V_16 , V_176 , V_190 , V_191 , V_144 ) ;
if ( ! V_60 )
return 1 ;
if ( V_144 -> type == V_202 &&
V_144 -> V_117 == V_118 )
V_144 -> V_188 = 0x0f ;
}
return 0 ;
}
static void
F_65 ( struct V_5 * V_6 )
{
struct V_185 * V_222 = & V_6 -> V_176 ;
T_4 V_223 [ 16 ] = { } ;
int V_3 , V_178 = 0 ;
if ( ! F_59 ( V_6 -> V_16 , 0x0392 , 0x107d , 0x20a2 ) ) {
for ( V_3 = 0 ; V_3 < V_222 -> V_143 ; V_3 ++ ) {
if ( V_222 -> V_144 [ V_3 ] . V_193 )
return;
}
}
for ( V_3 = 0 ; V_3 < V_222 -> V_143 ; V_3 ++ ) {
T_4 V_179 = V_222 -> V_144 [ V_3 ] . V_188 ;
if ( V_179 == 0x0f ) {
V_222 -> V_144 [ V_3 ] . V_193 = V_178 ++ ;
} else {
if ( ! V_223 [ V_179 ] )
V_223 [ V_179 ] = ++ V_178 ;
V_222 -> V_144 [ V_3 ] . V_193 = V_223 [ V_179 ] - 1 ;
}
}
if ( V_3 > 1 ) {
T_4 * V_184 = F_51 ( V_6 -> V_16 ) ;
if ( V_184 )
V_184 [ 0 ] = 0x00 ;
}
}
static int
F_66 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_185 * V_176 = & V_6 -> V_176 ;
T_4 * V_222 , * V_190 ;
int V_178 ;
V_222 = F_47 ( V_16 ) ;
if ( ! V_222 ) {
if ( V_6 -> type == V_224 ) {
F_60 ( V_16 , V_6 ) ;
return 0 ;
}
return - V_36 ;
}
F_5 ( V_22 , L_47 , V_222 [ 0 ] >> 4 , V_222 [ 0 ] & 0xf ) ;
V_176 -> V_126 = V_222 [ 0 ] ;
F_49 ( V_16 , NULL , F_64 ) ;
if ( V_176 -> V_126 < 0x21 )
F_57 ( V_16 , V_176 ) ;
V_178 = - 1 ;
while ( ( V_190 = F_52 ( V_16 , ++ V_178 ) ) ) {
if ( V_190 [ 0 ] != 0xff ) {
if ( F_51 ( V_16 ) [ 3 ] < 4 )
F_5 ( V_22 , L_48 ,
V_178 , F_3 ( V_190 [ 0 ] ) ) ;
else
F_5 ( V_22 , L_49 ,
V_178 , F_32 ( V_190 [ 0 ] ) ) ;
}
}
F_65 ( V_6 ) ;
return 0 ;
}
static int F_67 ( struct V_15 * V_16 , struct V_5 * V_6 , T_2 V_225 , int V_144 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_55 * V_41 = & V_22 -> V_41 . V_56 ;
T_1 V_226 ;
T_2 V_227 ;
int V_3 ;
if ( V_6 -> V_1 [ V_225 ] <= V_144 ) {
F_14 ( V_22 , L_50
L_51 ) ;
return - V_54 ;
}
V_226 = V_6 -> V_1 [ V_225 + 1 ] ;
if ( V_226 != 36 ) {
F_14 ( V_22 , L_52 ) ;
return - V_36 ;
}
F_5 ( V_22 , L_53 ) ;
V_227 = V_225 + 2 + V_144 * V_226 ;
F_19 ( V_41 , 0x00001304 , F_32 ( V_6 -> V_1 [ V_227 ] ) ) ;
V_226 -= 4 ;
for ( V_3 = 0 ; V_3 < V_226 ; V_3 += 4 )
F_19 ( V_41 , 0x00001400 + V_3 , F_32 ( V_6 -> V_1 [ V_227 + V_3 + 4 ] ) ) ;
F_19 ( V_41 , V_228 , F_16 ( V_41 , V_228 ) | 0x18 ) ;
return 0 ;
}
static int F_68 ( struct V_15 * V_16 ,
struct V_5 * V_6 )
{
const T_1 V_229 [] = { 'H' , 'W' , 'S' , 'Q' } ;
const int V_230 = sizeof( V_229 ) ;
int V_225 ;
V_225 = F_46 ( V_6 -> V_1 , V_6 -> V_2 , V_229 , V_230 ) ;
if ( ! V_225 )
return 0 ;
return F_67 ( V_16 , V_6 , V_225 + V_230 , 0 ) ;
}
T_1 * F_69 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
const T_1 V_231 [] = {
0x00 , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0x00 } ;
T_2 V_122 = 0 ;
T_2 V_232 ;
int V_233 = V_234 ;
if ( V_6 -> V_30 . V_235 )
return V_6 -> V_30 . V_235 ;
while ( V_233 ) {
V_232 = F_46 ( & V_6 -> V_1 [ V_122 ] , V_233 ,
V_231 , 8 ) ;
if ( ! V_232 )
return NULL ;
V_122 += V_232 ;
if ( ! F_1 ( & V_6 -> V_1 [ V_122 ] , V_236 ) )
break;
V_233 -= V_122 ;
V_122 ++ ;
}
F_5 ( V_22 , L_54 ) ;
return V_6 -> V_30 . V_235 = & V_6 -> V_1 [ V_122 ] ;
}
static bool F_70 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_237 * V_6 = F_71 ( & V_22 -> V_41 ) ;
struct V_5 * V_113 = & V_22 -> V_28 ;
memset ( V_113 , 0 , sizeof( struct V_5 ) ) ;
F_72 ( & V_113 -> V_238 ) ;
V_113 -> V_16 = V_16 ;
V_113 -> V_1 = V_6 -> V_1 ;
V_113 -> V_2 = V_6 -> V_239 ;
V_113 -> V_12 = V_6 -> V_126 . V_240 ;
V_113 -> V_111 = V_6 -> V_126 . V_241 ;
if ( V_6 -> V_242 ) {
V_113 -> type = V_145 ;
V_113 -> V_122 = V_6 -> V_242 ;
return ! F_43 ( V_113 , V_113 -> V_122 + 6 ) ;
} else
if ( V_6 -> V_243 ) {
V_113 -> type = V_224 ;
V_113 -> V_122 = V_6 -> V_243 ;
return ! F_45 ( V_16 , V_113 , V_113 -> V_122 ) ;
}
return false ;
}
int
F_73 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_60 = 0 ;
V_6 -> V_244 . V_245 = 0 ;
if ( V_6 -> V_12 < 5 )
F_68 ( V_16 , V_6 ) ;
if ( V_6 -> V_246 ) {
V_6 -> V_30 . V_61 = 0 ;
V_6 -> V_30 . V_62 = false ;
}
return V_60 ;
}
static bool
F_74 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
unsigned V_95 ;
if ( V_22 -> V_41 . V_71 . V_72 >= V_74 )
return true ;
V_95 = F_75 ( V_16 , 0 , 0x06 ) ;
V_95 |= ( F_75 ( V_16 , 0 , 0x07 ) & 0x01 ) << 8 ;
V_95 |= ( F_75 ( V_16 , 0 , 0x07 ) & 0x20 ) << 4 ;
V_95 |= ( F_75 ( V_16 , 0 , 0x25 ) & 0x01 ) << 10 ;
V_95 |= ( F_75 ( V_16 , 0 , 0x41 ) & 0x01 ) << 11 ;
return ( V_95 != 0 ) ;
}
int
F_76 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_60 ;
if ( ! V_16 -> V_40 )
return 0 ;
if ( ! F_70 ( V_16 ) )
return - V_146 ;
V_60 = F_66 ( V_16 , V_6 ) ;
if ( V_60 )
return V_60 ;
if ( ! V_6 -> V_12 )
return 0 ;
V_6 -> V_246 = false ;
if ( ! F_74 ( V_16 ) ) {
F_5 ( V_22 , L_55
L_56 ) ;
V_6 -> V_246 = true ;
}
V_60 = F_73 ( V_16 ) ;
if ( V_60 )
return V_60 ;
if ( V_6 -> V_12 < 5 )
V_6 -> V_84 = F_75 ( V_16 , 0 , V_247 ) & 0x40 ;
if ( V_6 -> V_84 || V_6 -> V_12 >= 5 )
V_60 = F_23 ( V_16 , V_6 ) ;
V_6 -> V_246 = true ;
return 0 ;
}
void
F_77 ( struct V_15 * V_16 )
{
}
