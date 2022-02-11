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
struct V_55 * V_41 = & V_22 -> V_56 . V_41 . V_57 ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_1 V_58 = V_6 -> V_1 [ V_6 -> V_30 . V_47 ] ;
T_3 V_59 , V_60 ;
int V_61 ;
if ( V_6 -> V_30 . V_62 == ( V_27 << 1 | V_19 ) || ! V_58 ||
( V_58 >= 0x30 && V_27 == V_43 ) )
return 0 ;
if ( ! V_6 -> V_30 . V_63 ) {
V_6 -> V_30 . V_63 = true ;
F_15 ( V_16 , V_18 , V_19 , V_43 , V_8 ) ;
}
if ( V_27 == V_46 && V_6 -> V_30 . V_64 )
F_15 ( V_16 , V_18 , V_19 , V_39 , V_8 ) ;
if ( V_27 == V_39 && V_6 -> V_30 . V_65 )
F_15 ( V_16 , V_18 , V_19 , V_38 , V_8 ) ;
F_5 ( V_22 , L_4 , V_27 ) ;
V_59 = F_16 ( V_41 , V_66 ) & 0x50000 ;
if ( V_58 < 0x30 )
V_61 = F_9 ( V_16 , V_18 , V_19 , V_27 ) ;
else
V_61 = F_13 ( V_16 , V_18 , V_19 , V_27 , V_8 ) ;
V_6 -> V_30 . V_62 = ( V_27 << 1 | V_19 ) ;
V_60 = F_17 ( V_16 , 0 , V_66 ) & ~ 0x50000 ;
F_18 ( V_16 , 0 , V_66 , V_60 | V_59 ) ;
F_19 ( V_41 , V_67 , 0 ) ;
return V_61 ;
}
static int F_20 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_68 * V_69 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_1 V_58 , V_70 , V_71 ;
memset ( V_69 , 0 , sizeof( struct V_68 ) ) ;
if ( V_6 -> V_30 . V_47 == 0x0 ) {
F_14 ( V_22 , L_5 ) ;
return - V_36 ;
}
V_58 = V_6 -> V_1 [ V_6 -> V_30 . V_47 ] ;
switch ( V_58 ) {
case 0x0a :
V_70 = 2 ;
V_71 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 1 ] ;
break;
case 0x30 :
V_70 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 1 ] ;
if ( V_70 < 0x1f ) {
F_14 ( V_22 , L_6 ) ;
return - V_36 ;
}
V_71 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 2 ] ;
break;
case 0x40 :
V_70 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 1 ] ;
if ( V_70 < 0x7 ) {
F_14 ( V_22 , L_6 ) ;
return - V_36 ;
}
V_71 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 2 ] ;
break;
default:
F_14 ( V_22 ,
L_7 ,
V_58 >> 4 , V_58 & 0xf ) ;
return - V_44 ;
}
V_69 -> V_58 = V_58 ;
V_69 -> V_70 = V_70 ;
V_69 -> V_71 = V_71 ;
return 0 ;
}
static int
F_21 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_55 * V_41 = & V_22 -> V_56 . V_41 . V_57 ;
if ( V_6 -> V_12 < 5 && V_6 -> V_1 [ 0x48 ] & 0x4 )
return F_22 ( V_16 , 0 , 0xf ) & 0xf ;
if ( V_22 -> V_56 . V_41 . V_72 . V_73 >= V_74 )
return F_16 ( V_41 , 0x001800 ) & 0x0000000f ;
else
if ( V_22 -> V_56 . V_41 . V_72 . V_73 >= V_75 )
return ( F_16 ( V_41 , V_76 ) >> 24 ) & 0xf ;
else
return ( F_16 ( V_41 , V_76 ) >> 16 ) & 0xf ;
}
static int F_23 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_1 * V_77 ;
T_1 V_78 , V_70 = 0 , V_71 , V_79 = 0xf , V_80 ;
int V_61 , V_81 , V_82 ;
struct V_68 V_69 ;
if ( V_6 -> V_30 . V_83 == 0x0 ) {
#ifndef F_11
F_14 ( V_22 , L_8 ) ;
#endif
V_6 -> V_84 = 0x4b ;
return 0 ;
}
V_77 = & V_6 -> V_1 [ V_6 -> V_30 . V_83 ] ;
V_78 = V_77 [ 0 ] ;
switch ( V_78 ) {
case 0x05 :
V_71 = 42 ;
V_81 = - 1 ;
break;
case 0x10 :
V_71 = 44 ;
V_81 = 0 ;
break;
case 0x20 :
V_70 = V_77 [ 1 ] ;
V_71 = V_77 [ 2 ] ;
V_79 = V_77 [ 3 ] ;
V_6 -> V_84 = V_77 [ 4 ] ;
V_81 = - 7 ;
break;
default:
F_14 ( V_22 ,
L_9 ,
V_78 >> 4 , V_78 & 0xf ) ;
return - V_44 ;
}
if ( ! V_6 -> V_85 )
return 0 ;
V_61 = F_20 ( V_16 , V_6 , & V_69 ) ;
if ( V_61 )
return V_61 ;
if ( V_69 . V_58 == 0x30 || V_69 . V_58 == 0x40 ) {
V_6 -> V_30 . V_86 = V_6 -> V_30 . V_47 +
V_69 . V_70 + 1 ;
V_6 -> V_30 . V_87 = V_69 . V_71 ;
}
if ( V_6 -> V_30 . V_86 == 0x0 ) {
F_14 ( V_22 , L_10 ) ;
return - V_36 ;
}
V_82 = F_21 ( V_16 , V_6 ) ;
V_80 = V_6 -> V_1 [ V_6 -> V_30 . V_86 +
V_82 * V_6 -> V_30 . V_87 ] ;
if ( V_80 > V_79 ) {
F_14 ( V_22 , L_11 ) ;
return - V_54 ;
}
if ( V_69 . V_58 > 0x10 )
V_6 -> V_88 = V_82 != 0xf || V_80 != 0xf ;
if ( V_82 == 0xf || V_80 == 0xf )
return 0 ;
V_6 -> V_30 . V_89 = V_6 -> V_30 . V_83 + V_70 +
V_71 * V_80 + V_81 ;
F_5 ( V_22 , L_12 ,
F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_89 + 11 ] ) + 1 ,
F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_89 + 25 ] ) + 1 ,
F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_89 + 7 ] ) * 10 ) ;
return 0 ;
}
bool F_24 ( struct V_15 * V_16 , struct V_90 * V_91 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_1 * V_92 = & V_6 -> V_1 [ V_6 -> V_30 . V_89 ] ;
if ( ! V_91 )
return V_6 -> V_30 . V_89 ;
memset ( V_91 , 0 , sizeof( struct V_90 ) ) ;
V_91 -> clock = F_3 ( V_92 [ 7 ] ) * 10 ;
V_91 -> V_93 = F_3 ( V_92 [ 11 ] ) + 1 ;
V_91 -> V_94 = F_3 ( V_92 [ 17 ] ) + 1 ;
V_91 -> V_95 = F_3 ( V_92 [ 19 ] ) + 1 ;
V_91 -> V_96 = F_3 ( V_92 [ 21 ] ) + 1 ;
V_91 -> V_97 = F_3 ( V_92 [ 25 ] ) + 1 ;
V_91 -> V_98 = F_3 ( V_92 [ 31 ] ) + 1 ;
V_91 -> V_99 = F_3 ( V_92 [ 33 ] ) + 1 ;
V_91 -> V_100 = F_3 ( V_92 [ 35 ] ) + 1 ;
V_91 -> V_101 |= ( V_92 [ 37 ] & 0x10 ) ?
V_102 : V_103 ;
V_91 -> V_101 |= ( V_92 [ 37 ] & 0x1 ) ?
V_104 : V_105 ;
V_91 -> V_106 = V_107 ;
V_91 -> type = V_108 | V_109 ;
F_25 ( V_91 ) ;
return V_6 -> V_30 . V_89 ;
}
int F_26 ( struct V_15 * V_16 , int V_8 , bool * V_20 , bool * V_51 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_82 = F_21 ( V_16 , V_6 ) , V_110 = 0 ;
struct V_68 V_69 ;
T_2 V_111 ;
int V_61 , V_112 = V_6 -> V_112 ;
V_61 = F_20 ( V_16 , V_6 , & V_69 ) ;
if ( V_61 )
return V_61 ;
switch ( V_69 . V_58 ) {
case 0x0a :
V_110 = V_6 -> V_1 [
V_6 -> V_30 . V_113 +
V_82 ] ;
if ( ! V_8 )
break;
if ( V_112 < 0x25 ) {
V_110 =
( V_6 -> V_114 . V_115 & 1 ) ?
2 : 0 ;
if ( V_8 >= V_6 -> V_30 . V_116 )
V_110 ++ ;
} else if ( V_112 < 0x30 ) {
V_110 = 0 ;
} else {
V_110 = 0 ;
if ( V_8 >= V_6 -> V_30 . V_116 )
V_110 = 2 ;
if ( V_8 >= 140000 )
V_110 = 3 ;
}
break;
case 0x30 :
case 0x40 :
V_110 = V_82 ;
break;
default:
F_14 ( V_22 , L_13 ) ;
return - V_44 ;
}
V_111 = V_6 -> V_30 . V_31 = V_6 -> V_30 . V_47 + V_69 . V_70 + V_69 . V_71 * V_110 ;
switch ( V_69 . V_58 ) {
case 0x0a :
V_6 -> V_30 . V_65 = V_6 -> V_1 [ V_111 ] & 1 ;
V_6 -> V_30 . V_64 = V_6 -> V_1 [ V_111 ] & 2 ;
V_6 -> V_30 . V_37 = V_6 -> V_1 [ V_111 ] & 4 ;
V_6 -> V_30 . V_32 = V_6 -> V_1 [ V_111 ] & 8 ;
* V_51 = V_6 -> V_1 [ V_111 ] & 16 ;
break;
case 0x30 :
case 0x40 :
V_6 -> V_30 . V_65 = true ;
V_6 -> V_30 . V_64 = true ;
V_6 -> V_30 . V_37 = V_6 -> V_1 [ V_111 ] & 1 ;
V_6 -> V_30 . V_51 = V_6 -> V_1 [ V_111 ] & 2 ;
V_6 -> V_30 . V_53 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 4 ] ;
V_6 -> V_30 . V_116 = F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_47 + 5 ] ) * 10 ;
break;
}
if ( V_8 && ( V_112 < 0x25 || V_112 > 0x28 ) )
V_6 -> V_30 . V_37 = ( V_8 >= V_6 -> V_30 . V_116 ) ;
* V_20 = V_6 -> V_30 . V_37 ;
return 0 ;
}
int F_27 ( struct V_15 * V_16 , struct V_17 * V_18 , int V_19 , int V_8 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_55 * V_41 = & V_22 -> V_56 . V_41 . V_57 ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_117 = V_6 -> V_112 ;
T_2 V_7 = 0 , V_11 ;
T_3 V_59 , V_60 ;
if ( V_117 >= 0x17 && V_117 != 0x1a && V_117 != 0x20 &&
V_18 -> V_118 != V_119 )
return 0 ;
switch ( F_28 ( V_18 -> V_33 ) ) {
case 1 :
V_7 = V_6 -> V_120 . V_121 ;
break;
case 2 :
case 3 :
V_7 = V_6 -> V_120 . V_122 ;
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
V_59 = F_16 ( V_41 , V_66 ) & 0x50000 ;
F_4 ( V_16 , V_11 , V_18 , V_19 , V_8 >= 165000 ) ;
V_60 = F_17 ( V_16 , 0 , V_66 ) & ~ 0x50000 ;
F_18 ( V_16 , 0 , V_66 , V_60 | V_59 ) ;
return 0 ;
}
static void F_29 ( struct V_5 * V_6 , T_2 V_123 )
{
V_6 -> V_14 = F_3 ( V_6 -> V_1 [ V_123 ] ) ;
}
static int F_30 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_124 * V_125 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_126 ;
T_1 V_127 , V_70 , V_128 , V_129 ;
if ( V_125 -> V_2 != 3 ) {
F_14 ( V_22 , L_15 ) ;
return - V_36 ;
}
V_126 = F_3 ( V_6 -> V_1 [ V_125 -> V_123 ] ) ;
if ( V_126 == 0x0 ) {
F_31 ( V_22 , L_16 ) ;
return - V_36 ;
}
V_127 = V_6 -> V_1 [ V_126 ] ;
if ( V_127 != 0x10 ) {
F_14 ( V_22 , L_17 ,
V_127 >> 4 , V_127 & 0xF ) ;
return - V_44 ;
}
V_70 = V_6 -> V_1 [ V_126 + 1 ] ;
V_128 = V_6 -> V_1 [ V_126 + 2 ] ;
V_129 = V_6 -> V_1 [ V_126 + 3 ] ;
if ( V_70 != 4 || V_128 != 4 || V_129 != 2 ) {
F_14 ( V_22 , L_18 ) ;
return - V_36 ;
}
V_6 -> V_130 = F_32 ( V_6 -> V_1 [ V_126 + V_70 ] ) & 0x3ff ;
return 0 ;
}
static int F_33 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_124 * V_125 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_125 -> V_2 != 4 ) {
F_14 ( V_22 , L_19 ) ;
return - V_36 ;
}
V_6 -> V_30 . V_83 = F_3 ( V_6 -> V_1 [ V_125 -> V_123 + 2 ] ) ;
return 0 ;
}
static int F_34 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_124 * V_125 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_125 -> V_2 < 14 ) {
F_14 ( V_22 , L_20 ) ;
return - V_36 ;
}
F_29 ( V_6 , V_125 -> V_123 ) ;
return 0 ;
}
static int F_35 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_124 * V_125 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_131 ;
T_1 V_132 , V_133 ;
if ( V_125 -> V_2 < 6 ) {
F_14 ( V_22 , L_21 ) ;
return - V_36 ;
}
V_6 -> V_134 = V_6 -> V_1 [ V_125 -> V_123 + 5 ] ;
V_6 -> V_85 = V_6 -> V_134 & V_135 ;
if ( V_125 -> V_2 < 15 ) {
F_36 ( V_22 , L_22
L_23 ) ;
return - V_36 ;
}
V_131 = F_3 ( V_6 -> V_1 [ V_125 -> V_123 + 13 ] ) ;
if ( ! V_131 )
return 0 ;
V_132 = V_6 -> V_1 [ V_131 ] ;
V_133 = V_6 -> V_1 [ V_131 + 1 ] ;
if ( V_132 != 0x00 && V_132 != 0x10 ) {
F_36 ( V_22 , L_24
L_25 , V_132 >> 4 , V_132 & 0xf ) ;
return - V_44 ;
}
V_6 -> V_130 = F_32 ( V_6 -> V_1 [ V_131 + V_133 ] ) ;
V_6 -> V_136 = F_32 ( V_6 -> V_1 [ V_131 + V_133 + 4 ] ) ;
return 0 ;
}
static int F_37 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_124 * V_125 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_125 -> V_2 != 2 ) {
F_14 ( V_22 , L_26 ) ;
return - V_36 ;
}
V_6 -> V_30 . V_47 = F_3 ( V_6 -> V_1 [ V_125 -> V_123 ] ) ;
return 0 ;
}
static int
F_38 ( struct V_15 * V_16 , struct V_5 * V_6 ,
struct V_124 * V_125 )
{
if ( V_125 -> V_2 < 0x5 )
return 0 ;
if ( V_125 -> V_127 < 2 ) {
V_6 -> V_137 = V_6 -> V_1 [ V_125 -> V_123 + 2 ] ;
V_6 -> V_138 = F_3 ( V_6 -> V_1 [ V_125 -> V_123 + 3 ] ) ;
} else {
V_6 -> V_137 = V_6 -> V_1 [ V_125 -> V_123 + 0 ] ;
V_6 -> V_138 = F_3 ( V_6 -> V_1 [ V_125 -> V_123 + 1 ] ) ;
}
return 0 ;
}
static int F_39 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_124 * V_125 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_139 , V_140 , V_141 ;
if ( V_125 -> V_2 != 2 ) {
F_14 ( V_22 , L_27 ) ;
return - V_36 ;
}
V_139 = F_3 ( V_6 -> V_1 [ V_125 -> V_123 ] ) ;
if ( ! V_139 ) {
F_14 ( V_22 , L_28 ) ;
return - V_36 ;
}
F_5 ( V_22 , L_29 ,
V_6 -> V_1 [ V_139 ] >> 4 , V_6 -> V_1 [ V_139 ] & 0xf ) ;
if ( V_6 -> V_1 [ V_139 ] != 0x11 )
return - V_44 ;
V_140 = F_3 ( V_6 -> V_1 [ V_139 + 7 ] ) ;
V_141 = F_3 ( V_6 -> V_1 [ V_139 + 9 ] ) ;
if ( V_6 -> V_1 [ V_140 ] != 'q' || V_6 -> V_1 [ V_141 ] != 'q' )
F_36 ( V_22 , L_30 ) ;
V_6 -> V_120 . V_121 = F_3 ( V_6 -> V_1 [ V_139 + 11 ] ) ;
V_6 -> V_120 . V_122 = F_3 ( V_6 -> V_1 [ V_139 + 13 ] ) ;
return 0 ;
}
int
F_40 ( struct V_15 * V_16 , T_4 V_142 , struct V_124 * V_143 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_4 V_144 , * V_145 ;
if ( V_6 -> type != V_146 )
return - V_147 ;
V_144 = V_6 -> V_1 [ V_6 -> V_123 + 10 ] ;
V_145 = & V_6 -> V_1 [ V_6 -> V_123 + 12 ] ;
while ( V_144 -- ) {
if ( V_145 [ 0 ] == V_142 ) {
V_143 -> V_142 = V_145 [ 0 ] ;
V_143 -> V_127 = V_145 [ 1 ] ;
V_143 -> V_2 = F_3 ( V_145 [ 2 ] ) ;
V_143 -> V_123 = F_3 ( V_145 [ 4 ] ) ;
V_143 -> V_1 = F_41 ( V_16 , V_145 [ 4 ] ) ;
return 0 ;
}
V_145 += V_6 -> V_1 [ V_6 -> V_123 + 9 ] ;
}
return - V_54 ;
}
static int
F_42 ( struct V_5 * V_6 , const T_2 V_148 ,
struct F_40 * V_149 )
{
struct V_15 * V_16 = V_6 -> V_16 ;
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_124 V_125 ;
if ( F_40 ( V_16 , V_149 -> V_142 , & V_125 ) == 0 )
return V_149 -> V_150 ( V_16 , V_6 , & V_125 ) ;
F_5 ( V_22 , L_31 , V_149 -> V_142 ) ;
return - V_44 ;
}
static int
F_43 ( struct V_5 * V_6 , const T_2 V_148 )
{
int V_61 ;
V_61 = F_42 ( V_6 , V_148 , & F_44 ( 'i' , V_3 ) ) ;
if ( V_61 )
return V_61 ;
if ( V_6 -> V_12 >= 0x60 )
F_42 ( V_6 , V_148 , & F_44 ( 'A' , V_151 ) ) ;
F_42 ( V_6 , V_148 , & F_44 ( 'D' , V_152 ) ) ;
V_61 = F_42 ( V_6 , V_148 , & F_44 ( 'I' , V_153 ) ) ;
if ( V_61 )
return V_61 ;
F_42 ( V_6 , V_148 , & F_44 ( 'M' , V_154 ) ) ;
F_42 ( V_6 , V_148 , & F_44 ( 'L' , V_155 ) ) ;
F_42 ( V_6 , V_148 , & F_44 ( 'T' , V_120 ) ) ;
return 0 ;
}
static int F_45 ( struct V_15 * V_16 , struct V_5 * V_6 , unsigned int V_123 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_1 * V_156 = & V_6 -> V_1 [ V_123 ] , V_157 , V_158 ;
T_2 V_159 ;
T_2 V_160 , V_161 ;
V_6 -> V_84 = 0x4b ;
V_6 -> V_162 = 256000 ;
V_6 -> V_163 = 128000 ;
V_6 -> V_30 . V_116 = 90000 ;
V_157 = V_156 [ 5 ] ;
V_158 = V_156 [ 6 ] ;
F_5 ( V_22 , L_32 ,
V_157 , V_158 ) ;
if ( V_157 < 5 )
* ( T_2 * ) & V_6 -> V_1 [ 0x36 ] = 0 ;
if ( ( V_157 < 5 && V_158 != 1 ) || V_157 > 5 ) {
F_14 ( V_22 , L_33
L_34 ) ;
return - V_44 ;
}
if ( V_157 == 0 )
return 0 ;
else if ( V_157 == 1 )
V_159 = 44 ;
else if ( V_157 == 2 )
V_159 = 48 ;
else if ( V_157 == 3 )
V_159 = 54 ;
else if ( V_157 == 4 || V_158 < 0x1 )
V_159 = 62 ;
else if ( V_158 < 0x6 )
V_159 = 67 ;
else if ( V_158 < 0x10 )
V_159 = 75 ;
else if ( V_158 == 0x10 )
V_159 = 89 ;
else if ( V_158 < 0x14 )
V_159 = 118 ;
else if ( V_158 < 0x24 )
V_159 = 123 ;
else if ( V_158 < 0x27 )
V_159 = 144 ;
else
V_159 = 158 ;
if ( F_1 ( V_156 , 8 ) ) {
F_14 ( V_22 , L_35 ) ;
return - V_36 ;
}
V_6 -> V_134 = V_156 [ 9 ] ;
if ( V_157 < 5 || V_158 < 0x10 )
V_6 -> V_164 = true ;
V_160 = 18 ;
if ( V_157 < 2 )
V_160 -= 4 ;
V_6 -> V_14 = F_3 ( V_156 [ V_160 ] ) ;
V_6 -> V_165 = F_3 ( V_156 [ V_160 + 2 ] ) ;
if ( V_157 > 2 ) {
V_6 -> V_114 . V_166 = F_3 ( V_156 [ 24 ] ) ;
V_6 -> V_114 . V_167 = F_3 ( V_156 [ 26 ] ) ;
V_6 -> V_114 . V_168 = F_3 ( V_156 [ 28 ] ) ;
}
V_161 = 0x48 ;
if ( V_159 > 61 )
V_161 = V_123 + 54 ;
V_6 -> V_114 . V_169 . V_170 = V_6 -> V_1 [ V_161 ] ;
V_6 -> V_114 . V_169 . V_171 = V_6 -> V_1 [ V_161 + 1 ] ;
V_6 -> V_114 . V_169 . V_172 = V_6 -> V_1 [ V_161 + 2 ] ;
if ( V_159 > 74 ) {
V_6 -> V_162 = F_32 ( V_156 [ 67 ] ) ;
V_6 -> V_163 = F_32 ( V_156 [ 71 ] ) ;
}
if ( V_159 > 88 )
F_29 ( V_6 , V_123 + 75 ) ;
if ( V_159 > 94 ) {
V_6 -> V_120 . V_121 = F_3 ( V_156 [ 89 ] ) ;
V_6 -> V_120 . V_122 = F_3 ( V_156 [ 91 ] ) ;
V_6 -> V_114 . V_115 = F_3 ( V_156 [ 95 ] ) ;
}
if ( V_159 > 108 ) {
V_6 -> V_30 . V_83 = F_3 ( V_156 [ 105 ] ) ;
V_6 -> V_30 . V_86 = F_3 ( V_156 [ 107 ] ) ;
V_6 -> V_30 . V_87 = 1 ;
}
if ( V_159 > 120 ) {
V_6 -> V_30 . V_47 = F_3 ( V_156 [ 117 ] ) ;
V_6 -> V_30 . V_113 = F_3 ( V_156 [ 119 ] ) ;
}
#if 0
if (bmplength > 143)
bios->pll_limit_tbl_ptr = ROM16(bmp[142]);
#endif
if ( V_159 > 157 )
V_6 -> V_30 . V_116 = F_3 ( V_156 [ 156 ] ) * 10 ;
return 0 ;
}
static T_2 F_46 ( T_1 * V_1 , int V_173 , const T_1 * V_174 , int V_175 )
{
int V_3 , V_176 ;
for ( V_3 = 0 ; V_3 <= ( V_173 - V_175 ) ; V_3 ++ ) {
for ( V_176 = 0 ; V_176 < V_175 ; V_176 ++ )
if ( V_1 [ V_3 + V_176 ] != V_174 [ V_176 ] )
break;
if ( V_176 == V_175 )
return V_3 ;
}
return 0 ;
}
void *
F_47 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_4 * V_177 = NULL ;
if ( V_22 -> V_56 . V_41 . V_72 . V_73 > V_178 )
V_177 = F_41 ( V_16 , V_22 -> V_28 . V_1 [ 0x36 ] ) ;
if ( ! V_177 ) {
F_36 ( V_22 , L_36 ) ;
return NULL ;
}
if ( V_177 [ 0 ] >= 0x42 ) {
F_36 ( V_22 , L_37 , V_177 [ 0 ] ) ;
return NULL ;
} else
if ( V_177 [ 0 ] >= 0x30 ) {
if ( F_32 ( V_177 [ 6 ] ) == 0x4edcbdcb )
return V_177 ;
} else
if ( V_177 [ 0 ] >= 0x20 ) {
if ( F_32 ( V_177 [ 4 ] ) == 0x4edcbdcb )
return V_177 ;
} else
if ( V_177 [ 0 ] >= 0x15 ) {
if ( ! memcmp ( & V_177 [ - 7 ] , L_38 , 7 ) )
return V_177 ;
} else {
F_36 ( V_22 , L_39 ) ;
return NULL ;
}
F_36 ( V_22 , L_40 ) ;
return NULL ;
}
void *
F_48 ( struct V_15 * V_16 , T_4 V_179 )
{
T_4 * V_177 = F_47 ( V_16 ) ;
if ( V_177 && V_177 [ 0 ] >= 0x30 ) {
if ( V_179 < V_177 [ 2 ] )
return V_177 + V_177 [ 1 ] + ( V_179 * V_177 [ 3 ] ) ;
} else
if ( V_177 && V_177 [ 0 ] >= 0x20 ) {
T_4 * V_180 = F_41 ( V_16 , V_177 [ 2 ] ) ;
T_4 * V_181 = V_177 + 8 + ( V_179 * 8 ) ;
if ( V_180 && V_181 < V_180 )
return V_181 ;
} else
if ( V_177 && V_177 [ 0 ] >= 0x15 ) {
T_4 * V_180 = F_41 ( V_16 , V_177 [ 2 ] ) ;
T_4 * V_181 = V_177 + 4 + ( V_179 * 10 ) ;
if ( V_180 && V_181 < V_180 )
return V_181 ;
}
return NULL ;
}
int
F_49 ( struct V_15 * V_16 , void * V_1 ,
int (* F_50)( struct V_15 * , void * , int V_179 , T_4 * V_182 ) )
{
int V_61 , V_179 = - 1 ;
T_4 * V_182 = NULL ;
while ( ( V_182 = F_48 ( V_16 , ++ V_179 ) ) ) {
if ( F_32 ( V_182 [ 0 ] ) == 0x00000000 )
break;
if ( F_32 ( V_182 [ 0 ] ) == 0xffffffff )
break;
if ( ( V_182 [ 0 ] & 0x0f ) == V_183 )
continue;
if ( ( V_182 [ 0 ] & 0x0f ) == V_184 )
break;
V_61 = F_50 ( V_16 , V_1 , V_179 , V_182 ) ;
if ( V_61 )
return V_61 ;
}
return 0 ;
}
T_4 *
F_51 ( struct V_15 * V_16 )
{
T_4 * V_177 = F_47 ( V_16 ) ;
if ( V_177 && V_177 [ 0 ] >= 0x30 && V_177 [ 1 ] >= 0x16 ) {
T_4 * V_185 = F_41 ( V_16 , V_177 [ 0x14 ] ) ;
if ( V_185 && V_185 [ 0 ] >= 0x30 && V_185 [ 0 ] <= 0x40 )
return V_185 ;
}
return NULL ;
}
T_4 *
F_52 ( struct V_15 * V_16 , T_4 V_179 )
{
T_4 * V_185 = F_51 ( V_16 ) ;
if ( V_185 && V_179 < V_185 [ 2 ] )
return V_185 + V_185 [ 1 ] + ( V_179 * V_185 [ 3 ] ) ;
return NULL ;
}
static struct V_17 * F_53 ( struct V_186 * V_177 )
{
struct V_17 * V_145 = & V_177 -> V_145 [ V_177 -> V_144 ] ;
memset ( V_145 , 0 , sizeof( struct V_17 ) ) ;
V_145 -> V_187 = V_177 -> V_144 ++ ;
return V_145 ;
}
static void F_54 ( struct V_186 * V_177 , int type , int V_180 ,
int V_188 , int V_33 )
{
struct V_17 * V_145 = F_53 ( V_177 ) ;
V_145 -> type = type ;
V_145 -> V_189 = V_180 ;
V_145 -> V_188 = V_188 ;
if ( type != V_190 )
V_145 -> V_118 = ! V_119 ;
V_145 -> V_33 = V_33 ;
}
static bool
F_55 ( struct V_15 * V_16 , struct V_186 * V_177 ,
T_3 V_191 , T_3 V_192 , struct V_17 * V_145 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
int V_193 = 0 ;
V_145 -> type = V_191 & 0xf ;
V_145 -> V_189 = ( V_191 >> 4 ) & 0xf ;
V_145 -> V_188 = ( V_191 >> 8 ) & 0xf ;
V_145 -> V_194 = ( V_191 >> 12 ) & 0xf ;
V_145 -> V_195 = ( V_191 >> 16 ) & 0xf ;
V_145 -> V_118 = ( V_191 >> 20 ) & 0x3 ;
V_145 -> V_33 = ( V_191 >> 24 ) & 0xf ;
switch ( V_145 -> type ) {
case V_190 :
V_145 -> V_196 . V_197 = ( V_177 -> V_127 < 0x30 ) ?
( V_192 & 0xffff ) * 10 :
( V_192 & 0xff ) * 10000 ;
break;
case V_198 :
{
T_3 V_199 ;
if ( V_192 & 0x1 )
V_145 -> V_49 . V_50 = true ;
if ( V_177 -> V_127 < 0x22 ) {
V_199 = ~ 0xd ;
V_145 -> V_49 . V_50 = true ;
if ( V_192 & 0x4 || V_192 & 0x8 )
V_145 -> V_49 . V_200 = true ;
} else {
V_199 = ~ 0x7 ;
if ( V_192 & 0x2 )
V_145 -> V_49 . V_201 = true ;
if ( V_192 & 0x4 )
V_145 -> V_49 . V_200 = true ;
V_145 -> V_49 . V_202 . V_193 = ( V_192 & 0x00000030 ) >> 4 ;
V_193 = V_145 -> V_49 . V_202 . V_193 ;
}
if ( V_192 & V_199 ) {
if ( V_177 -> V_127 >= 0x40 )
break;
F_14 ( V_22 , L_41
L_42 ) ;
}
break;
}
case V_203 :
{
if ( V_177 -> V_127 >= 0x30 )
V_145 -> V_204 . V_205 = V_192 & ( 0x8 << 4 ) ;
else
V_145 -> V_204 . V_205 = false ;
break;
}
case V_206 :
V_145 -> V_207 . V_202 . V_193 = ( V_192 & 0x00000030 ) >> 4 ;
V_145 -> V_208 = ( V_192 & 0x0000ff00 ) >> 8 ;
switch ( ( V_192 & 0x00e00000 ) >> 21 ) {
case 0 :
V_145 -> V_207 . V_209 = 162000 ;
break;
case 1 :
V_145 -> V_207 . V_209 = 270000 ;
break;
default:
V_145 -> V_207 . V_209 = 540000 ;
break;
}
switch ( ( V_192 & 0x0f000000 ) >> 24 ) {
case 0xf :
case 0x4 :
V_145 -> V_207 . V_210 = 4 ;
break;
case 0x3 :
case 0x2 :
V_145 -> V_207 . V_210 = 2 ;
break;
default:
V_145 -> V_207 . V_210 = 1 ;
break;
}
V_193 = V_145 -> V_207 . V_202 . V_193 ;
break;
case V_211 :
if ( V_177 -> V_127 >= 0x40 ) {
V_145 -> V_212 . V_202 . V_193 = ( V_192 & 0x00000030 ) >> 4 ;
V_145 -> V_208 = ( V_192 & 0x0000ff00 ) >> 8 ;
V_193 = V_145 -> V_212 . V_202 . V_193 ;
}
else if ( V_177 -> V_127 >= 0x30 )
V_145 -> V_212 . V_213 = ( V_192 & 0x00000700 ) >> 8 ;
else if ( V_177 -> V_127 >= 0x22 )
V_145 -> V_212 . V_213 = ( V_192 & 0x00000070 ) >> 4 ;
break;
case V_184 :
V_177 -> V_144 -- ;
return false ;
default:
break;
}
if ( V_177 -> V_127 < 0x40 ) {
V_145 -> V_214 =
( ( 1 << ( F_28 ( V_145 -> V_33 ) - 1 ) ) * 3 == V_145 -> V_33 ) ;
} else {
V_145 -> V_214 = ( V_145 -> V_215 . V_193 == 3 ) ;
}
if ( V_192 & 0x100000 )
V_145 -> V_216 = true ;
V_145 -> V_217 = ( V_145 -> V_208 << 8 ) | ( V_145 -> V_118 << 4 ) |
V_145 -> type ;
V_145 -> V_218 = ( V_145 -> V_188 << 8 ) | ( V_193 << 6 ) | V_145 -> V_33 ;
return true ;
}
static bool
F_56 ( struct V_15 * V_16 , struct V_186 * V_177 ,
T_3 V_191 , T_3 V_192 , struct V_17 * V_145 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
switch ( V_191 & 0x0000000f ) {
case 0 :
V_145 -> type = V_190 ;
break;
case 1 :
V_145 -> type = V_203 ;
break;
case 2 :
case 4 :
if ( V_191 & 0x10 )
V_145 -> type = V_198 ;
else
V_145 -> type = V_211 ;
break;
case 3 :
V_145 -> type = V_198 ;
break;
default:
F_14 ( V_22 , L_43 , V_191 & 0x0000000f ) ;
return false ;
}
V_145 -> V_189 = ( V_191 & 0x0003c000 ) >> 14 ;
V_145 -> V_188 = ( ( V_191 & 0x001c0000 ) >> 18 ) + 1 ;
V_145 -> V_33 = V_145 -> V_188 ;
V_145 -> V_118 = ( V_191 & 0x01e00000 ) >> 21 ;
V_145 -> V_195 = ( V_191 & 0x0e000000 ) >> 25 ;
V_145 -> V_214 = false ;
switch ( V_145 -> type ) {
case V_190 :
V_145 -> V_196 . V_197 = ( V_192 & 0xffff ) * 10 ;
break;
case V_203 :
V_145 -> V_204 . V_205 = false ;
break;
case V_198 :
if ( ( V_191 & 0x00003f00 ) >> 8 != 0x10 )
V_145 -> V_49 . V_50 = true ;
V_145 -> V_49 . V_200 = true ;
break;
default:
break;
}
return true ;
}
static
void F_57 ( struct V_15 * V_16 , struct V_186 * V_177 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
int V_3 , V_219 = 0 ;
for ( V_3 = 0 ; V_3 < V_177 -> V_144 ; V_3 ++ ) {
struct V_17 * V_220 = & V_177 -> V_145 [ V_3 ] ;
int V_176 ;
for ( V_176 = V_3 + 1 ; V_176 < V_177 -> V_144 ; V_176 ++ ) {
struct V_17 * V_221 = & V_177 -> V_145 [ V_176 ] ;
if ( V_221 -> type == 100 )
continue;
if ( V_221 -> V_189 == V_220 -> V_189 &&
V_221 -> type == V_220 -> type &&
V_221 -> V_118 == V_220 -> V_118 &&
V_221 -> V_33 == V_220 -> V_33 ) {
F_5 ( V_22 , L_44 ,
V_3 , V_176 ) ;
V_220 -> V_188 |= V_221 -> V_188 ;
V_221 -> type = 100 ;
}
}
}
for ( V_3 = 0 ; V_3 < V_177 -> V_144 ; V_3 ++ ) {
if ( V_177 -> V_145 [ V_3 ] . type == 100 )
continue;
if ( V_219 != V_3 ) {
V_177 -> V_145 [ V_219 ] = V_177 -> V_145 [ V_3 ] ;
V_177 -> V_145 [ V_219 ] . V_187 = V_219 ;
}
V_219 ++ ;
}
V_177 -> V_144 = V_219 ;
}
static bool
F_58 ( struct V_15 * V_16 , int V_179 , T_5 * V_191 , T_5 * V_192 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_186 * V_177 = & V_22 -> V_28 . V_177 ;
if ( F_59 ( V_16 , 0x040d , 0x1028 , 0x019b ) ) {
if ( * V_191 == 0x02026312 && * V_192 == 0x00000020 )
return false ;
}
if ( F_59 ( V_16 , 0x0201 , 0x1462 , 0x8851 ) ) {
if ( * V_191 == 0xf2005014 && * V_192 == 0xffffffff ) {
F_54 ( V_177 , V_211 , 1 , 1 , 1 ) ;
return false ;
}
}
if ( F_59 ( V_16 , 0x0ca3 , 0x1682 , 0x3003 ) ) {
if ( V_179 == 0 ) {
* V_191 = 0x02001300 ;
* V_192 = 0x00000028 ;
} else
if ( V_179 == 1 ) {
* V_191 = 0x01010312 ;
* V_192 = 0x00020030 ;
} else
if ( V_179 == 2 ) {
* V_191 = 0x01010310 ;
* V_192 = 0x00000028 ;
} else
if ( V_179 == 3 ) {
* V_191 = 0x02022362 ;
* V_192 = 0x00020010 ;
} else {
* V_191 = 0x0000000e ;
* V_192 = 0x00000000 ;
}
}
if ( F_59 ( V_16 , 0x0615 , 0x1682 , 0x2605 ) ) {
if ( V_179 == 0 ) {
* V_191 = 0x02002300 ;
* V_192 = 0x00000028 ;
} else
if ( V_179 == 1 ) {
* V_191 = 0x01010312 ;
* V_192 = 0x00020030 ;
} else
if ( V_179 == 2 ) {
* V_191 = 0x04020310 ;
* V_192 = 0x00000028 ;
} else
if ( V_179 == 3 ) {
* V_191 = 0x02021322 ;
* V_192 = 0x00020010 ;
} else {
* V_191 = 0x0000000e ;
* V_192 = 0x00000000 ;
}
}
if ( F_59 ( V_16 , 0x0421 , 0x3842 , 0xc793 ) ) {
if ( V_179 == 0 && * V_191 == 0x02000300 )
* V_191 = 0x02011300 ;
else
if ( V_179 == 1 && * V_191 == 0x04011310 )
* V_191 = 0x04000310 ;
else
if ( V_179 == 2 && * V_191 == 0x02011312 )
* V_191 = 0x02000312 ;
}
return true ;
}
static void
F_60 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_186 * V_177 = & V_6 -> V_177 ;
int V_222 = ( F_61 ( V_16 ) ? 3 : 1 ) ;
#ifdef F_11
if ( F_62 ( L_45 ) ) {
F_54 ( V_177 , V_211 , 0 , V_222 , 1 ) ;
F_54 ( V_177 , V_190 , 1 , V_222 , 2 ) ;
return;
}
#endif
F_54 ( V_177 , V_190 ,
V_6 -> V_114 . V_169 . V_170 , 1 , 1 ) ;
if ( F_63 ( V_16 , V_6 -> V_114 . V_169 . V_171 ) >= 0 )
F_54 ( V_177 , V_203 ,
V_6 -> V_114 . V_169 . V_171 ,
V_222 , 0 ) ;
else if ( V_6 -> V_120 . V_121 ||
V_6 -> V_120 . V_122 )
F_54 ( V_177 , V_211 ,
V_6 -> V_114 . V_169 . V_172 ,
V_222 , 1 ) ;
}
static int
F_64 ( struct V_15 * V_16 , void * V_1 , int V_179 , T_4 * V_182 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_186 * V_177 = & V_22 -> V_28 . V_177 ;
T_5 V_192 = ( V_177 -> V_127 >= 0x20 ) ? F_32 ( V_182 [ 4 ] ) : F_32 ( V_182 [ 6 ] ) ;
T_5 V_191 = F_32 ( V_182 [ 0 ] ) ;
bool V_61 ;
if ( F_58 ( V_16 , V_179 , & V_191 , & V_192 ) ) {
struct V_17 * V_145 = F_53 ( V_177 ) ;
F_5 ( V_22 , L_46 , V_179 , V_191 , V_192 ) ;
if ( V_177 -> V_127 >= 0x20 )
V_61 = F_55 ( V_16 , V_177 , V_191 , V_192 , V_145 ) ;
else
V_61 = F_56 ( V_16 , V_177 , V_191 , V_192 , V_145 ) ;
if ( ! V_61 )
return 1 ;
if ( V_145 -> type == V_203 &&
V_145 -> V_118 == V_119 )
V_145 -> V_189 = 0x0f ;
}
return 0 ;
}
static void
F_65 ( struct V_5 * V_6 )
{
struct V_186 * V_223 = & V_6 -> V_177 ;
T_4 V_224 [ 16 ] = { } ;
int V_3 , V_179 = 0 ;
if ( ! F_59 ( V_6 -> V_16 , 0x0392 , 0x107d , 0x20a2 ) ) {
for ( V_3 = 0 ; V_3 < V_223 -> V_144 ; V_3 ++ ) {
if ( V_223 -> V_145 [ V_3 ] . V_194 )
return;
}
}
for ( V_3 = 0 ; V_3 < V_223 -> V_144 ; V_3 ++ ) {
T_4 V_180 = V_223 -> V_145 [ V_3 ] . V_189 ;
if ( V_180 == 0x0f ) {
V_223 -> V_145 [ V_3 ] . V_194 = V_179 ++ ;
} else {
if ( ! V_224 [ V_180 ] )
V_224 [ V_180 ] = ++ V_179 ;
V_223 -> V_145 [ V_3 ] . V_194 = V_224 [ V_180 ] - 1 ;
}
}
if ( V_3 > 1 ) {
T_4 * V_185 = F_51 ( V_6 -> V_16 ) ;
if ( V_185 )
V_185 [ 0 ] = 0x00 ;
}
}
static int
F_66 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_186 * V_177 = & V_6 -> V_177 ;
T_4 * V_223 , * V_191 ;
int V_179 ;
V_223 = F_47 ( V_16 ) ;
if ( ! V_223 ) {
if ( V_6 -> type == V_225 ) {
F_60 ( V_16 , V_6 ) ;
return 0 ;
}
return - V_36 ;
}
F_5 ( V_22 , L_47 , V_223 [ 0 ] >> 4 , V_223 [ 0 ] & 0xf ) ;
V_177 -> V_127 = V_223 [ 0 ] ;
F_49 ( V_16 , NULL , F_64 ) ;
if ( V_177 -> V_127 < 0x21 )
F_57 ( V_16 , V_177 ) ;
V_179 = - 1 ;
while ( ( V_191 = F_52 ( V_16 , ++ V_179 ) ) ) {
if ( V_191 [ 0 ] != 0xff ) {
if ( F_51 ( V_16 ) [ 3 ] < 4 )
F_5 ( V_22 , L_48 ,
V_179 , F_3 ( V_191 [ 0 ] ) ) ;
else
F_5 ( V_22 , L_49 ,
V_179 , F_32 ( V_191 [ 0 ] ) ) ;
}
}
F_65 ( V_6 ) ;
return 0 ;
}
static int F_67 ( struct V_15 * V_16 , struct V_5 * V_6 , T_2 V_226 , int V_145 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_55 * V_41 = & V_22 -> V_56 . V_41 . V_57 ;
T_1 V_227 ;
T_2 V_228 ;
int V_3 ;
if ( V_6 -> V_1 [ V_226 ] <= V_145 ) {
F_14 ( V_22 , L_50
L_51 ) ;
return - V_54 ;
}
V_227 = V_6 -> V_1 [ V_226 + 1 ] ;
if ( V_227 != 36 ) {
F_14 ( V_22 , L_52 ) ;
return - V_36 ;
}
F_5 ( V_22 , L_53 ) ;
V_228 = V_226 + 2 + V_145 * V_227 ;
F_19 ( V_41 , 0x00001304 , F_32 ( V_6 -> V_1 [ V_228 ] ) ) ;
V_227 -= 4 ;
for ( V_3 = 0 ; V_3 < V_227 ; V_3 += 4 )
F_19 ( V_41 , 0x00001400 + V_3 , F_32 ( V_6 -> V_1 [ V_228 + V_3 + 4 ] ) ) ;
F_19 ( V_41 , V_229 , F_16 ( V_41 , V_229 ) | 0x18 ) ;
return 0 ;
}
static int F_68 ( struct V_15 * V_16 ,
struct V_5 * V_6 )
{
const T_1 V_230 [] = { 'H' , 'W' , 'S' , 'Q' } ;
const int V_231 = sizeof( V_230 ) ;
int V_226 ;
V_226 = F_46 ( V_6 -> V_1 , V_6 -> V_2 , V_230 , V_231 ) ;
if ( ! V_226 )
return 0 ;
return F_67 ( V_16 , V_6 , V_226 + V_231 , 0 ) ;
}
T_1 * F_69 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
const T_1 V_232 [] = {
0x00 , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0x00 } ;
T_2 V_123 = 0 ;
T_2 V_233 ;
int V_234 = V_235 ;
if ( V_6 -> V_30 . V_236 )
return V_6 -> V_30 . V_236 ;
while ( V_234 ) {
V_233 = F_46 ( & V_6 -> V_1 [ V_123 ] , V_234 ,
V_232 , 8 ) ;
if ( ! V_233 )
return NULL ;
V_123 += V_233 ;
if ( ! F_1 ( & V_6 -> V_1 [ V_123 ] , V_237 ) )
break;
V_234 -= V_123 ;
V_123 ++ ;
}
F_5 ( V_22 , L_54 ) ;
return V_6 -> V_30 . V_236 = & V_6 -> V_1 [ V_123 ] ;
}
static bool F_70 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_238 * V_6 = F_71 ( & V_22 -> V_56 . V_41 ) ;
struct V_5 * V_114 = & V_22 -> V_28 ;
memset ( V_114 , 0 , sizeof( struct V_5 ) ) ;
F_72 ( & V_114 -> V_239 ) ;
V_114 -> V_16 = V_16 ;
V_114 -> V_1 = V_6 -> V_1 ;
V_114 -> V_2 = V_6 -> V_240 ;
V_114 -> V_12 = V_6 -> V_127 . V_241 ;
V_114 -> V_112 = V_6 -> V_127 . V_242 ;
if ( V_6 -> V_243 ) {
V_114 -> type = V_146 ;
V_114 -> V_123 = V_6 -> V_243 ;
return ! F_43 ( V_114 , V_114 -> V_123 + 6 ) ;
} else
if ( V_6 -> V_244 ) {
V_114 -> type = V_225 ;
V_114 -> V_123 = V_6 -> V_244 ;
return ! F_45 ( V_16 , V_114 , V_114 -> V_123 ) ;
}
return false ;
}
int
F_73 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_61 = 0 ;
V_6 -> V_245 . V_246 = 0 ;
if ( V_6 -> V_12 < 5 )
F_68 ( V_16 , V_6 ) ;
if ( V_6 -> V_247 ) {
V_6 -> V_30 . V_62 = 0 ;
V_6 -> V_30 . V_63 = false ;
}
return V_61 ;
}
static bool
F_74 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
unsigned V_96 ;
if ( V_22 -> V_56 . V_41 . V_72 . V_73 >= V_75 )
return true ;
V_96 = F_75 ( V_16 , 0 , 0x06 ) ;
V_96 |= ( F_75 ( V_16 , 0 , 0x07 ) & 0x01 ) << 8 ;
V_96 |= ( F_75 ( V_16 , 0 , 0x07 ) & 0x20 ) << 4 ;
V_96 |= ( F_75 ( V_16 , 0 , 0x25 ) & 0x01 ) << 10 ;
V_96 |= ( F_75 ( V_16 , 0 , 0x41 ) & 0x01 ) << 11 ;
return ( V_96 != 0 ) ;
}
int
F_76 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_61 ;
if ( ! V_16 -> V_40 )
return 0 ;
if ( ! F_70 ( V_16 ) )
return - V_147 ;
V_61 = F_66 ( V_16 , V_6 ) ;
if ( V_61 )
return V_61 ;
if ( ! V_6 -> V_12 )
return 0 ;
V_6 -> V_247 = false ;
if ( ! F_74 ( V_16 ) ) {
F_5 ( V_22 , L_55
L_56 ) ;
V_6 -> V_247 = true ;
}
V_61 = F_73 ( V_16 ) ;
if ( V_61 )
return V_61 ;
if ( V_6 -> V_12 < 5 )
V_6 -> V_85 = F_75 ( V_16 , 0 , V_248 ) & 0x40 ;
if ( V_6 -> V_85 || V_6 -> V_12 >= 5 )
V_61 = F_23 ( V_16 , V_6 ) ;
V_6 -> V_247 = true ;
return 0 ;
}
void
F_77 ( struct V_15 * V_16 )
{
}
