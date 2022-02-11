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
return ( F_16 ( V_41 , V_74 ) >> 24 ) & 0xf ;
else
return ( F_16 ( V_41 , V_74 ) >> 16 ) & 0xf ;
}
static int F_23 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_1 * V_75 ;
T_1 V_76 , V_69 = 0 , V_70 , V_77 = 0xf , V_78 ;
int V_60 , V_79 , V_80 ;
struct V_67 V_68 ;
if ( V_6 -> V_30 . V_81 == 0x0 ) {
#ifndef F_11
F_14 ( V_22 , L_8 ) ;
#endif
V_6 -> V_82 = 0x4b ;
return 0 ;
}
V_75 = & V_6 -> V_1 [ V_6 -> V_30 . V_81 ] ;
V_76 = V_75 [ 0 ] ;
switch ( V_76 ) {
case 0x05 :
V_70 = 42 ;
V_79 = - 1 ;
break;
case 0x10 :
V_70 = 44 ;
V_79 = 0 ;
break;
case 0x20 :
V_69 = V_75 [ 1 ] ;
V_70 = V_75 [ 2 ] ;
V_77 = V_75 [ 3 ] ;
V_6 -> V_82 = V_75 [ 4 ] ;
V_79 = - 7 ;
break;
default:
F_14 ( V_22 ,
L_9 ,
V_76 >> 4 , V_76 & 0xf ) ;
return - V_44 ;
}
if ( ! V_6 -> V_83 )
return 0 ;
V_60 = F_20 ( V_16 , V_6 , & V_68 ) ;
if ( V_60 )
return V_60 ;
if ( V_68 . V_57 == 0x30 || V_68 . V_57 == 0x40 ) {
V_6 -> V_30 . V_84 = V_6 -> V_30 . V_47 +
V_68 . V_69 + 1 ;
V_6 -> V_30 . V_85 = V_68 . V_70 ;
}
if ( V_6 -> V_30 . V_84 == 0x0 ) {
F_14 ( V_22 , L_10 ) ;
return - V_36 ;
}
V_80 = F_21 ( V_16 , V_6 ) ;
V_78 = V_6 -> V_1 [ V_6 -> V_30 . V_84 +
V_80 * V_6 -> V_30 . V_85 ] ;
if ( V_78 > V_77 ) {
F_14 ( V_22 , L_11 ) ;
return - V_54 ;
}
if ( V_68 . V_57 > 0x10 )
V_6 -> V_86 = V_80 != 0xf || V_78 != 0xf ;
if ( V_80 == 0xf || V_78 == 0xf )
return 0 ;
V_6 -> V_30 . V_87 = V_6 -> V_30 . V_81 + V_69 +
V_70 * V_78 + V_79 ;
F_5 ( V_22 , L_12 ,
F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_87 + 11 ] ) + 1 ,
F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_87 + 25 ] ) + 1 ,
F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_87 + 7 ] ) * 10 ) ;
return 0 ;
}
bool F_24 ( struct V_15 * V_16 , struct V_88 * V_89 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_1 * V_90 = & V_6 -> V_1 [ V_6 -> V_30 . V_87 ] ;
if ( ! V_89 )
return V_6 -> V_30 . V_87 ;
memset ( V_89 , 0 , sizeof( struct V_88 ) ) ;
V_89 -> clock = F_3 ( V_90 [ 7 ] ) * 10 ;
V_89 -> V_91 = F_3 ( V_90 [ 11 ] ) + 1 ;
V_89 -> V_92 = F_3 ( V_90 [ 17 ] ) + 1 ;
V_89 -> V_93 = F_3 ( V_90 [ 19 ] ) + 1 ;
V_89 -> V_94 = F_3 ( V_90 [ 21 ] ) + 1 ;
V_89 -> V_95 = F_3 ( V_90 [ 25 ] ) + 1 ;
V_89 -> V_96 = F_3 ( V_90 [ 31 ] ) + 1 ;
V_89 -> V_97 = F_3 ( V_90 [ 33 ] ) + 1 ;
V_89 -> V_98 = F_3 ( V_90 [ 35 ] ) + 1 ;
V_89 -> V_99 |= ( V_90 [ 37 ] & 0x10 ) ?
V_100 : V_101 ;
V_89 -> V_99 |= ( V_90 [ 37 ] & 0x1 ) ?
V_102 : V_103 ;
V_89 -> V_104 = V_105 ;
V_89 -> type = V_106 | V_107 ;
F_25 ( V_89 ) ;
return V_6 -> V_30 . V_87 ;
}
int F_26 ( struct V_15 * V_16 , int V_8 , bool * V_20 , bool * V_51 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_80 = F_21 ( V_16 , V_6 ) , V_108 = 0 ;
struct V_67 V_68 ;
T_2 V_109 ;
int V_60 , V_110 = V_6 -> V_110 ;
V_60 = F_20 ( V_16 , V_6 , & V_68 ) ;
if ( V_60 )
return V_60 ;
switch ( V_68 . V_57 ) {
case 0x0a :
V_108 = V_6 -> V_1 [
V_6 -> V_30 . V_111 +
V_80 ] ;
if ( ! V_8 )
break;
if ( V_110 < 0x25 ) {
V_108 =
( V_6 -> V_112 . V_113 & 1 ) ?
2 : 0 ;
if ( V_8 >= V_6 -> V_30 . V_114 )
V_108 ++ ;
} else if ( V_110 < 0x30 ) {
V_108 = 0 ;
} else {
V_108 = 0 ;
if ( V_8 >= V_6 -> V_30 . V_114 )
V_108 = 2 ;
if ( V_8 >= 140000 )
V_108 = 3 ;
}
break;
case 0x30 :
case 0x40 :
V_108 = V_80 ;
break;
default:
F_14 ( V_22 , L_13 ) ;
return - V_44 ;
}
V_109 = V_6 -> V_30 . V_31 = V_6 -> V_30 . V_47 + V_68 . V_69 + V_68 . V_70 * V_108 ;
switch ( V_68 . V_57 ) {
case 0x0a :
V_6 -> V_30 . V_64 = V_6 -> V_1 [ V_109 ] & 1 ;
V_6 -> V_30 . V_63 = V_6 -> V_1 [ V_109 ] & 2 ;
V_6 -> V_30 . V_37 = V_6 -> V_1 [ V_109 ] & 4 ;
V_6 -> V_30 . V_32 = V_6 -> V_1 [ V_109 ] & 8 ;
* V_51 = V_6 -> V_1 [ V_109 ] & 16 ;
break;
case 0x30 :
case 0x40 :
V_6 -> V_30 . V_64 = true ;
V_6 -> V_30 . V_63 = true ;
V_6 -> V_30 . V_37 = V_6 -> V_1 [ V_109 ] & 1 ;
V_6 -> V_30 . V_51 = V_6 -> V_1 [ V_109 ] & 2 ;
V_6 -> V_30 . V_53 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 4 ] ;
V_6 -> V_30 . V_114 = F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_47 + 5 ] ) * 10 ;
break;
}
if ( V_8 && ( V_110 < 0x25 || V_110 > 0x28 ) )
V_6 -> V_30 . V_37 = ( V_8 >= V_6 -> V_30 . V_114 ) ;
* V_20 = V_6 -> V_30 . V_37 ;
return 0 ;
}
int F_27 ( struct V_15 * V_16 , struct V_17 * V_18 , int V_19 , int V_8 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_55 * V_41 = & V_22 -> V_41 . V_56 ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_115 = V_6 -> V_110 ;
T_2 V_7 = 0 , V_11 ;
T_3 V_58 , V_59 ;
if ( V_115 >= 0x17 && V_115 != 0x1a && V_115 != 0x20 &&
V_18 -> V_116 != V_117 )
return 0 ;
switch ( F_28 ( V_18 -> V_33 ) ) {
case 1 :
V_7 = V_6 -> V_118 . V_119 ;
break;
case 2 :
case 3 :
V_7 = V_6 -> V_118 . V_120 ;
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
static void F_29 ( struct V_5 * V_6 , T_2 V_121 )
{
V_6 -> V_14 = F_3 ( V_6 -> V_1 [ V_121 ] ) ;
}
static int F_30 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_122 * V_123 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_124 ;
T_1 V_125 , V_69 , V_126 , V_127 ;
if ( V_123 -> V_2 != 3 ) {
F_14 ( V_22 , L_15 ) ;
return - V_36 ;
}
V_124 = F_3 ( V_6 -> V_1 [ V_123 -> V_121 ] ) ;
if ( V_124 == 0x0 ) {
F_31 ( V_22 , L_16 ) ;
return - V_36 ;
}
V_125 = V_6 -> V_1 [ V_124 ] ;
if ( V_125 != 0x10 ) {
F_14 ( V_22 , L_17 ,
V_125 >> 4 , V_125 & 0xF ) ;
return - V_44 ;
}
V_69 = V_6 -> V_1 [ V_124 + 1 ] ;
V_126 = V_6 -> V_1 [ V_124 + 2 ] ;
V_127 = V_6 -> V_1 [ V_124 + 3 ] ;
if ( V_69 != 4 || V_126 != 4 || V_127 != 2 ) {
F_14 ( V_22 , L_18 ) ;
return - V_36 ;
}
V_6 -> V_128 = F_32 ( V_6 -> V_1 [ V_124 + V_69 ] ) & 0x3ff ;
return 0 ;
}
static int F_33 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_122 * V_123 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_123 -> V_2 != 4 ) {
F_14 ( V_22 , L_19 ) ;
return - V_36 ;
}
V_6 -> V_30 . V_81 = F_3 ( V_6 -> V_1 [ V_123 -> V_121 + 2 ] ) ;
return 0 ;
}
static int F_34 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_122 * V_123 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_123 -> V_2 < 14 ) {
F_14 ( V_22 , L_20 ) ;
return - V_36 ;
}
F_29 ( V_6 , V_123 -> V_121 ) ;
return 0 ;
}
static int F_35 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_122 * V_123 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_129 ;
T_1 V_130 , V_131 ;
if ( V_123 -> V_2 < 6 ) {
F_14 ( V_22 , L_21 ) ;
return - V_36 ;
}
V_6 -> V_132 = V_6 -> V_1 [ V_123 -> V_121 + 5 ] ;
V_6 -> V_83 = V_6 -> V_132 & V_133 ;
if ( V_123 -> V_2 < 15 ) {
F_36 ( V_22 , L_22
L_23 ) ;
return - V_36 ;
}
V_129 = F_3 ( V_6 -> V_1 [ V_123 -> V_121 + 13 ] ) ;
if ( ! V_129 )
return 0 ;
V_130 = V_6 -> V_1 [ V_129 ] ;
V_131 = V_6 -> V_1 [ V_129 + 1 ] ;
if ( V_130 != 0x00 && V_130 != 0x10 ) {
F_36 ( V_22 , L_24
L_25 , V_130 >> 4 , V_130 & 0xf ) ;
return - V_44 ;
}
V_6 -> V_128 = F_32 ( V_6 -> V_1 [ V_129 + V_131 ] ) ;
V_6 -> V_134 = F_32 ( V_6 -> V_1 [ V_129 + V_131 + 4 ] ) ;
return 0 ;
}
static int F_37 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_122 * V_123 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_123 -> V_2 != 2 ) {
F_14 ( V_22 , L_26 ) ;
return - V_36 ;
}
V_6 -> V_30 . V_47 = F_3 ( V_6 -> V_1 [ V_123 -> V_121 ] ) ;
return 0 ;
}
static int
F_38 ( struct V_15 * V_16 , struct V_5 * V_6 ,
struct V_122 * V_123 )
{
if ( V_123 -> V_2 < 0x5 )
return 0 ;
if ( V_123 -> V_125 < 2 ) {
V_6 -> V_135 = V_6 -> V_1 [ V_123 -> V_121 + 2 ] ;
V_6 -> V_136 = F_3 ( V_6 -> V_1 [ V_123 -> V_121 + 3 ] ) ;
} else {
V_6 -> V_135 = V_6 -> V_1 [ V_123 -> V_121 + 0 ] ;
V_6 -> V_136 = F_3 ( V_6 -> V_1 [ V_123 -> V_121 + 1 ] ) ;
}
return 0 ;
}
static int F_39 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_122 * V_123 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_137 , V_138 , V_139 ;
if ( V_123 -> V_2 != 2 ) {
F_14 ( V_22 , L_27 ) ;
return - V_36 ;
}
V_137 = F_3 ( V_6 -> V_1 [ V_123 -> V_121 ] ) ;
if ( ! V_137 ) {
F_14 ( V_22 , L_28 ) ;
return - V_36 ;
}
F_5 ( V_22 , L_29 ,
V_6 -> V_1 [ V_137 ] >> 4 , V_6 -> V_1 [ V_137 ] & 0xf ) ;
if ( V_6 -> V_1 [ V_137 ] != 0x11 )
return - V_44 ;
V_138 = F_3 ( V_6 -> V_1 [ V_137 + 7 ] ) ;
V_139 = F_3 ( V_6 -> V_1 [ V_137 + 9 ] ) ;
if ( V_6 -> V_1 [ V_138 ] != 'q' || V_6 -> V_1 [ V_139 ] != 'q' )
F_36 ( V_22 , L_30 ) ;
V_6 -> V_118 . V_119 = F_3 ( V_6 -> V_1 [ V_137 + 11 ] ) ;
V_6 -> V_118 . V_120 = F_3 ( V_6 -> V_1 [ V_137 + 13 ] ) ;
return 0 ;
}
int
F_40 ( struct V_15 * V_16 , T_4 V_140 , struct V_122 * V_141 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_4 V_142 , * V_143 ;
if ( V_6 -> type != V_144 )
return - V_145 ;
V_142 = V_6 -> V_1 [ V_6 -> V_121 + 10 ] ;
V_143 = & V_6 -> V_1 [ V_6 -> V_121 + 12 ] ;
while ( V_142 -- ) {
if ( V_143 [ 0 ] == V_140 ) {
V_141 -> V_140 = V_143 [ 0 ] ;
V_141 -> V_125 = V_143 [ 1 ] ;
V_141 -> V_2 = F_3 ( V_143 [ 2 ] ) ;
V_141 -> V_121 = F_3 ( V_143 [ 4 ] ) ;
V_141 -> V_1 = F_41 ( V_16 , V_143 [ 4 ] ) ;
return 0 ;
}
V_143 += V_6 -> V_1 [ V_6 -> V_121 + 9 ] ;
}
return - V_54 ;
}
static int
F_42 ( struct V_5 * V_6 , const T_2 V_146 ,
struct F_40 * V_147 )
{
struct V_15 * V_16 = V_6 -> V_16 ;
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_122 V_123 ;
if ( F_40 ( V_16 , V_147 -> V_140 , & V_123 ) == 0 )
return V_147 -> V_148 ( V_16 , V_6 , & V_123 ) ;
F_5 ( V_22 , L_31 , V_147 -> V_140 ) ;
return - V_44 ;
}
static int
F_43 ( struct V_5 * V_6 , const T_2 V_146 )
{
int V_60 ;
V_60 = F_42 ( V_6 , V_146 , & F_44 ( 'i' , V_3 ) ) ;
if ( V_60 )
return V_60 ;
if ( V_6 -> V_12 >= 0x60 )
F_42 ( V_6 , V_146 , & F_44 ( 'A' , V_149 ) ) ;
F_42 ( V_6 , V_146 , & F_44 ( 'D' , V_150 ) ) ;
V_60 = F_42 ( V_6 , V_146 , & F_44 ( 'I' , V_151 ) ) ;
if ( V_60 )
return V_60 ;
F_42 ( V_6 , V_146 , & F_44 ( 'M' , V_152 ) ) ;
F_42 ( V_6 , V_146 , & F_44 ( 'L' , V_153 ) ) ;
F_42 ( V_6 , V_146 , & F_44 ( 'T' , V_118 ) ) ;
return 0 ;
}
static int F_45 ( struct V_15 * V_16 , struct V_5 * V_6 , unsigned int V_121 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_1 * V_154 = & V_6 -> V_1 [ V_121 ] , V_155 , V_156 ;
T_2 V_157 ;
T_2 V_158 , V_159 ;
V_6 -> V_82 = 0x4b ;
V_6 -> V_160 = 256000 ;
V_6 -> V_161 = 128000 ;
V_6 -> V_30 . V_114 = 90000 ;
V_155 = V_154 [ 5 ] ;
V_156 = V_154 [ 6 ] ;
F_5 ( V_22 , L_32 ,
V_155 , V_156 ) ;
if ( V_155 < 5 )
* ( T_2 * ) & V_6 -> V_1 [ 0x36 ] = 0 ;
if ( ( V_155 < 5 && V_156 != 1 ) || V_155 > 5 ) {
F_14 ( V_22 , L_33
L_34 ) ;
return - V_44 ;
}
if ( V_155 == 0 )
return 0 ;
else if ( V_155 == 1 )
V_157 = 44 ;
else if ( V_155 == 2 )
V_157 = 48 ;
else if ( V_155 == 3 )
V_157 = 54 ;
else if ( V_155 == 4 || V_156 < 0x1 )
V_157 = 62 ;
else if ( V_156 < 0x6 )
V_157 = 67 ;
else if ( V_156 < 0x10 )
V_157 = 75 ;
else if ( V_156 == 0x10 )
V_157 = 89 ;
else if ( V_156 < 0x14 )
V_157 = 118 ;
else if ( V_156 < 0x24 )
V_157 = 123 ;
else if ( V_156 < 0x27 )
V_157 = 144 ;
else
V_157 = 158 ;
if ( F_1 ( V_154 , 8 ) ) {
F_14 ( V_22 , L_35 ) ;
return - V_36 ;
}
V_6 -> V_132 = V_154 [ 9 ] ;
if ( V_155 < 5 || V_156 < 0x10 )
V_6 -> V_162 = true ;
V_158 = 18 ;
if ( V_155 < 2 )
V_158 -= 4 ;
V_6 -> V_14 = F_3 ( V_154 [ V_158 ] ) ;
V_6 -> V_163 = F_3 ( V_154 [ V_158 + 2 ] ) ;
if ( V_155 > 2 ) {
V_6 -> V_112 . V_164 = F_3 ( V_154 [ 24 ] ) ;
V_6 -> V_112 . V_165 = F_3 ( V_154 [ 26 ] ) ;
V_6 -> V_112 . V_166 = F_3 ( V_154 [ 28 ] ) ;
}
V_159 = 0x48 ;
if ( V_157 > 61 )
V_159 = V_121 + 54 ;
V_6 -> V_112 . V_167 . V_168 = V_6 -> V_1 [ V_159 ] ;
V_6 -> V_112 . V_167 . V_169 = V_6 -> V_1 [ V_159 + 1 ] ;
V_6 -> V_112 . V_167 . V_170 = V_6 -> V_1 [ V_159 + 2 ] ;
if ( V_157 > 74 ) {
V_6 -> V_160 = F_32 ( V_154 [ 67 ] ) ;
V_6 -> V_161 = F_32 ( V_154 [ 71 ] ) ;
}
if ( V_157 > 88 )
F_29 ( V_6 , V_121 + 75 ) ;
if ( V_157 > 94 ) {
V_6 -> V_118 . V_119 = F_3 ( V_154 [ 89 ] ) ;
V_6 -> V_118 . V_120 = F_3 ( V_154 [ 91 ] ) ;
V_6 -> V_112 . V_113 = F_3 ( V_154 [ 95 ] ) ;
}
if ( V_157 > 108 ) {
V_6 -> V_30 . V_81 = F_3 ( V_154 [ 105 ] ) ;
V_6 -> V_30 . V_84 = F_3 ( V_154 [ 107 ] ) ;
V_6 -> V_30 . V_85 = 1 ;
}
if ( V_157 > 120 ) {
V_6 -> V_30 . V_47 = F_3 ( V_154 [ 117 ] ) ;
V_6 -> V_30 . V_111 = F_3 ( V_154 [ 119 ] ) ;
}
#if 0
if (bmplength > 143)
bios->pll_limit_tbl_ptr = ROM16(bmp[142]);
#endif
if ( V_157 > 157 )
V_6 -> V_30 . V_114 = F_3 ( V_154 [ 156 ] ) * 10 ;
return 0 ;
}
static T_2 F_46 ( T_1 * V_1 , int V_171 , const T_1 * V_172 , int V_173 )
{
int V_3 , V_174 ;
for ( V_3 = 0 ; V_3 <= ( V_171 - V_173 ) ; V_3 ++ ) {
for ( V_174 = 0 ; V_174 < V_173 ; V_174 ++ )
if ( V_1 [ V_3 + V_174 ] != V_172 [ V_174 ] )
break;
if ( V_174 == V_173 )
return V_3 ;
}
return 0 ;
}
void *
F_47 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_4 * V_175 = NULL ;
if ( V_22 -> V_41 . V_71 . V_72 > V_176 )
V_175 = F_41 ( V_16 , V_22 -> V_28 . V_1 [ 0x36 ] ) ;
if ( ! V_175 ) {
F_36 ( V_22 , L_36 ) ;
return NULL ;
}
if ( V_175 [ 0 ] >= 0x42 ) {
F_36 ( V_22 , L_37 , V_175 [ 0 ] ) ;
return NULL ;
} else
if ( V_175 [ 0 ] >= 0x30 ) {
if ( F_32 ( V_175 [ 6 ] ) == 0x4edcbdcb )
return V_175 ;
} else
if ( V_175 [ 0 ] >= 0x20 ) {
if ( F_32 ( V_175 [ 4 ] ) == 0x4edcbdcb )
return V_175 ;
} else
if ( V_175 [ 0 ] >= 0x15 ) {
if ( ! memcmp ( & V_175 [ - 7 ] , L_38 , 7 ) )
return V_175 ;
} else {
F_36 ( V_22 , L_39 ) ;
return NULL ;
}
F_36 ( V_22 , L_40 ) ;
return NULL ;
}
void *
F_48 ( struct V_15 * V_16 , T_4 V_177 )
{
T_4 * V_175 = F_47 ( V_16 ) ;
if ( V_175 && V_175 [ 0 ] >= 0x30 ) {
if ( V_177 < V_175 [ 2 ] )
return V_175 + V_175 [ 1 ] + ( V_177 * V_175 [ 3 ] ) ;
} else
if ( V_175 && V_175 [ 0 ] >= 0x20 ) {
T_4 * V_178 = F_41 ( V_16 , V_175 [ 2 ] ) ;
T_4 * V_179 = V_175 + 8 + ( V_177 * 8 ) ;
if ( V_178 && V_179 < V_178 )
return V_179 ;
} else
if ( V_175 && V_175 [ 0 ] >= 0x15 ) {
T_4 * V_178 = F_41 ( V_16 , V_175 [ 2 ] ) ;
T_4 * V_179 = V_175 + 4 + ( V_177 * 10 ) ;
if ( V_178 && V_179 < V_178 )
return V_179 ;
}
return NULL ;
}
int
F_49 ( struct V_15 * V_16 , void * V_1 ,
int (* F_50)( struct V_15 * , void * , int V_177 , T_4 * V_180 ) )
{
int V_60 , V_177 = - 1 ;
T_4 * V_180 = NULL ;
while ( ( V_180 = F_48 ( V_16 , ++ V_177 ) ) ) {
if ( F_32 ( V_180 [ 0 ] ) == 0x00000000 )
break;
if ( F_32 ( V_180 [ 0 ] ) == 0xffffffff )
break;
if ( ( V_180 [ 0 ] & 0x0f ) == V_181 )
continue;
if ( ( V_180 [ 0 ] & 0x0f ) == V_182 )
break;
V_60 = F_50 ( V_16 , V_1 , V_177 , V_180 ) ;
if ( V_60 )
return V_60 ;
}
return 0 ;
}
T_4 *
F_51 ( struct V_15 * V_16 )
{
T_4 * V_175 = F_47 ( V_16 ) ;
if ( V_175 && V_175 [ 0 ] >= 0x30 && V_175 [ 1 ] >= 0x16 ) {
T_4 * V_183 = F_41 ( V_16 , V_175 [ 0x14 ] ) ;
if ( V_183 && V_183 [ 0 ] >= 0x30 && V_183 [ 0 ] <= 0x40 )
return V_183 ;
}
return NULL ;
}
T_4 *
F_52 ( struct V_15 * V_16 , T_4 V_177 )
{
T_4 * V_183 = F_51 ( V_16 ) ;
if ( V_183 && V_177 < V_183 [ 2 ] )
return V_183 + V_183 [ 1 ] + ( V_177 * V_183 [ 3 ] ) ;
return NULL ;
}
static struct V_17 * F_53 ( struct V_184 * V_175 )
{
struct V_17 * V_143 = & V_175 -> V_143 [ V_175 -> V_142 ] ;
memset ( V_143 , 0 , sizeof( struct V_17 ) ) ;
V_143 -> V_185 = V_175 -> V_142 ++ ;
return V_143 ;
}
static void F_54 ( struct V_184 * V_175 , int type , int V_178 ,
int V_186 , int V_33 )
{
struct V_17 * V_143 = F_53 ( V_175 ) ;
V_143 -> type = type ;
V_143 -> V_187 = V_178 ;
V_143 -> V_186 = V_186 ;
if ( type != V_188 )
V_143 -> V_116 = ! V_117 ;
V_143 -> V_33 = V_33 ;
}
static bool
F_55 ( struct V_15 * V_16 , struct V_184 * V_175 ,
T_3 V_189 , T_3 V_190 , struct V_17 * V_143 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
int V_191 = 0 ;
V_143 -> type = V_189 & 0xf ;
V_143 -> V_187 = ( V_189 >> 4 ) & 0xf ;
V_143 -> V_186 = ( V_189 >> 8 ) & 0xf ;
V_143 -> V_192 = ( V_189 >> 12 ) & 0xf ;
V_143 -> V_193 = ( V_189 >> 16 ) & 0xf ;
V_143 -> V_116 = ( V_189 >> 20 ) & 0x3 ;
V_143 -> V_33 = ( V_189 >> 24 ) & 0xf ;
switch ( V_143 -> type ) {
case V_188 :
V_143 -> V_194 . V_195 = ( V_175 -> V_125 < 0x30 ) ?
( V_190 & 0xffff ) * 10 :
( V_190 & 0xff ) * 10000 ;
break;
case V_196 :
{
T_3 V_197 ;
if ( V_190 & 0x1 )
V_143 -> V_49 . V_50 = true ;
if ( V_175 -> V_125 < 0x22 ) {
V_197 = ~ 0xd ;
V_143 -> V_49 . V_50 = true ;
if ( V_190 & 0x4 || V_190 & 0x8 )
V_143 -> V_49 . V_198 = true ;
} else {
V_197 = ~ 0x7 ;
if ( V_190 & 0x2 )
V_143 -> V_49 . V_199 = true ;
if ( V_190 & 0x4 )
V_143 -> V_49 . V_198 = true ;
V_143 -> V_49 . V_200 . V_191 = ( V_190 & 0x00000030 ) >> 4 ;
V_191 = V_143 -> V_49 . V_200 . V_191 ;
}
if ( V_190 & V_197 ) {
if ( V_175 -> V_125 >= 0x40 )
break;
F_14 ( V_22 , L_41
L_42 ) ;
}
break;
}
case V_201 :
{
if ( V_175 -> V_125 >= 0x30 )
V_143 -> V_202 . V_203 = V_190 & ( 0x8 << 4 ) ;
else
V_143 -> V_202 . V_203 = false ;
break;
}
case V_204 :
V_143 -> V_205 . V_200 . V_191 = ( V_190 & 0x00000030 ) >> 4 ;
V_143 -> V_206 = ( V_190 & 0x0000ff00 ) >> 8 ;
switch ( ( V_190 & 0x00e00000 ) >> 21 ) {
case 0 :
V_143 -> V_205 . V_207 = 162000 ;
break;
case 1 :
V_143 -> V_205 . V_207 = 270000 ;
break;
default:
V_143 -> V_205 . V_207 = 540000 ;
break;
}
switch ( ( V_190 & 0x0f000000 ) >> 24 ) {
case 0xf :
case 0x4 :
V_143 -> V_205 . V_208 = 4 ;
break;
case 0x3 :
case 0x2 :
V_143 -> V_205 . V_208 = 2 ;
break;
default:
V_143 -> V_205 . V_208 = 1 ;
break;
}
V_191 = V_143 -> V_205 . V_200 . V_191 ;
break;
case V_209 :
if ( V_175 -> V_125 >= 0x40 ) {
V_143 -> V_210 . V_200 . V_191 = ( V_190 & 0x00000030 ) >> 4 ;
V_143 -> V_206 = ( V_190 & 0x0000ff00 ) >> 8 ;
V_191 = V_143 -> V_210 . V_200 . V_191 ;
}
else if ( V_175 -> V_125 >= 0x30 )
V_143 -> V_210 . V_211 = ( V_190 & 0x00000700 ) >> 8 ;
else if ( V_175 -> V_125 >= 0x22 )
V_143 -> V_210 . V_211 = ( V_190 & 0x00000070 ) >> 4 ;
break;
case V_182 :
V_175 -> V_142 -- ;
return false ;
default:
break;
}
if ( V_175 -> V_125 < 0x40 ) {
V_143 -> V_212 =
( ( 1 << ( F_28 ( V_143 -> V_33 ) - 1 ) ) * 3 == V_143 -> V_33 ) ;
} else {
V_143 -> V_212 = ( V_143 -> V_213 . V_191 == 3 ) ;
}
if ( V_190 & 0x100000 )
V_143 -> V_214 = true ;
V_143 -> V_215 = ( V_143 -> V_116 << 4 ) | V_143 -> type ;
V_143 -> V_216 = ( V_143 -> V_186 << 8 ) | ( V_191 << 6 ) | V_143 -> V_33 ;
return true ;
}
static bool
F_56 ( struct V_15 * V_16 , struct V_184 * V_175 ,
T_3 V_189 , T_3 V_190 , struct V_17 * V_143 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
switch ( V_189 & 0x0000000f ) {
case 0 :
V_143 -> type = V_188 ;
break;
case 1 :
V_143 -> type = V_201 ;
break;
case 2 :
case 4 :
if ( V_189 & 0x10 )
V_143 -> type = V_196 ;
else
V_143 -> type = V_209 ;
break;
case 3 :
V_143 -> type = V_196 ;
break;
default:
F_14 ( V_22 , L_43 , V_189 & 0x0000000f ) ;
return false ;
}
V_143 -> V_187 = ( V_189 & 0x0003c000 ) >> 14 ;
V_143 -> V_186 = ( ( V_189 & 0x001c0000 ) >> 18 ) + 1 ;
V_143 -> V_33 = V_143 -> V_186 ;
V_143 -> V_116 = ( V_189 & 0x01e00000 ) >> 21 ;
V_143 -> V_193 = ( V_189 & 0x0e000000 ) >> 25 ;
V_143 -> V_212 = false ;
switch ( V_143 -> type ) {
case V_188 :
V_143 -> V_194 . V_195 = ( V_190 & 0xffff ) * 10 ;
break;
case V_201 :
V_143 -> V_202 . V_203 = false ;
break;
case V_196 :
if ( ( V_189 & 0x00003f00 ) >> 8 != 0x10 )
V_143 -> V_49 . V_50 = true ;
V_143 -> V_49 . V_198 = true ;
break;
default:
break;
}
return true ;
}
static
void F_57 ( struct V_15 * V_16 , struct V_184 * V_175 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
int V_3 , V_217 = 0 ;
for ( V_3 = 0 ; V_3 < V_175 -> V_142 ; V_3 ++ ) {
struct V_17 * V_218 = & V_175 -> V_143 [ V_3 ] ;
int V_174 ;
for ( V_174 = V_3 + 1 ; V_174 < V_175 -> V_142 ; V_174 ++ ) {
struct V_17 * V_219 = & V_175 -> V_143 [ V_174 ] ;
if ( V_219 -> type == 100 )
continue;
if ( V_219 -> V_187 == V_218 -> V_187 &&
V_219 -> type == V_218 -> type &&
V_219 -> V_116 == V_218 -> V_116 &&
V_219 -> V_33 == V_218 -> V_33 ) {
F_5 ( V_22 , L_44 ,
V_3 , V_174 ) ;
V_218 -> V_186 |= V_219 -> V_186 ;
V_219 -> type = 100 ;
}
}
}
for ( V_3 = 0 ; V_3 < V_175 -> V_142 ; V_3 ++ ) {
if ( V_175 -> V_143 [ V_3 ] . type == 100 )
continue;
if ( V_217 != V_3 ) {
V_175 -> V_143 [ V_217 ] = V_175 -> V_143 [ V_3 ] ;
V_175 -> V_143 [ V_217 ] . V_185 = V_217 ;
}
V_217 ++ ;
}
V_175 -> V_142 = V_217 ;
}
static bool
F_58 ( struct V_15 * V_16 , int V_177 , T_5 * V_189 , T_5 * V_190 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_184 * V_175 = & V_22 -> V_28 . V_175 ;
if ( F_59 ( V_16 , 0x040d , 0x1028 , 0x019b ) ) {
if ( * V_189 == 0x02026312 && * V_190 == 0x00000020 )
return false ;
}
if ( F_59 ( V_16 , 0x0201 , 0x1462 , 0x8851 ) ) {
if ( * V_189 == 0xf2005014 && * V_190 == 0xffffffff ) {
F_54 ( V_175 , V_209 , 1 , 1 , 1 ) ;
return false ;
}
}
if ( F_59 ( V_16 , 0x0ca3 , 0x1682 , 0x3003 ) ) {
if ( V_177 == 0 ) {
* V_189 = 0x02001300 ;
* V_190 = 0x00000028 ;
} else
if ( V_177 == 1 ) {
* V_189 = 0x01010312 ;
* V_190 = 0x00020030 ;
} else
if ( V_177 == 2 ) {
* V_189 = 0x01010310 ;
* V_190 = 0x00000028 ;
} else
if ( V_177 == 3 ) {
* V_189 = 0x02022362 ;
* V_190 = 0x00020010 ;
} else {
* V_189 = 0x0000000e ;
* V_190 = 0x00000000 ;
}
}
if ( F_59 ( V_16 , 0x0615 , 0x1682 , 0x2605 ) ) {
if ( V_177 == 0 ) {
* V_189 = 0x02002300 ;
* V_190 = 0x00000028 ;
} else
if ( V_177 == 1 ) {
* V_189 = 0x01010312 ;
* V_190 = 0x00020030 ;
} else
if ( V_177 == 2 ) {
* V_189 = 0x04020310 ;
* V_190 = 0x00000028 ;
} else
if ( V_177 == 3 ) {
* V_189 = 0x02021322 ;
* V_190 = 0x00020010 ;
} else {
* V_189 = 0x0000000e ;
* V_190 = 0x00000000 ;
}
}
if ( F_59 ( V_16 , 0x0421 , 0x3842 , 0xc793 ) ) {
if ( V_177 == 0 && * V_189 == 0x02000300 )
* V_189 = 0x02011300 ;
else
if ( V_177 == 1 && * V_189 == 0x04011310 )
* V_189 = 0x04000310 ;
else
if ( V_177 == 2 && * V_189 == 0x02011312 )
* V_189 = 0x02000312 ;
}
return true ;
}
static void
F_60 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_184 * V_175 = & V_6 -> V_175 ;
int V_220 = ( F_61 ( V_16 ) ? 3 : 1 ) ;
#ifdef F_11
if ( F_62 ( L_45 ) ) {
F_54 ( V_175 , V_209 , 0 , V_220 , 1 ) ;
F_54 ( V_175 , V_188 , 1 , V_220 , 2 ) ;
return;
}
#endif
F_54 ( V_175 , V_188 ,
V_6 -> V_112 . V_167 . V_168 , 1 , 1 ) ;
if ( F_63 ( V_16 , V_6 -> V_112 . V_167 . V_169 ) >= 0 )
F_54 ( V_175 , V_201 ,
V_6 -> V_112 . V_167 . V_169 ,
V_220 , 0 ) ;
else if ( V_6 -> V_118 . V_119 ||
V_6 -> V_118 . V_120 )
F_54 ( V_175 , V_209 ,
V_6 -> V_112 . V_167 . V_170 ,
V_220 , 1 ) ;
}
static int
F_64 ( struct V_15 * V_16 , void * V_1 , int V_177 , T_4 * V_180 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_184 * V_175 = & V_22 -> V_28 . V_175 ;
T_5 V_190 = ( V_175 -> V_125 >= 0x20 ) ? F_32 ( V_180 [ 4 ] ) : F_32 ( V_180 [ 6 ] ) ;
T_5 V_189 = F_32 ( V_180 [ 0 ] ) ;
bool V_60 ;
if ( F_58 ( V_16 , V_177 , & V_189 , & V_190 ) ) {
struct V_17 * V_143 = F_53 ( V_175 ) ;
F_5 ( V_22 , L_46 , V_177 , V_189 , V_190 ) ;
if ( V_175 -> V_125 >= 0x20 )
V_60 = F_55 ( V_16 , V_175 , V_189 , V_190 , V_143 ) ;
else
V_60 = F_56 ( V_16 , V_175 , V_189 , V_190 , V_143 ) ;
if ( ! V_60 )
return 1 ;
if ( V_143 -> type == V_201 &&
V_143 -> V_116 == V_117 )
V_143 -> V_187 = 0x0f ;
}
return 0 ;
}
static void
F_65 ( struct V_5 * V_6 )
{
struct V_184 * V_221 = & V_6 -> V_175 ;
T_4 V_222 [ 16 ] = { } ;
int V_3 , V_177 = 0 ;
if ( ! F_59 ( V_6 -> V_16 , 0x0392 , 0x107d , 0x20a2 ) ) {
for ( V_3 = 0 ; V_3 < V_221 -> V_142 ; V_3 ++ ) {
if ( V_221 -> V_143 [ V_3 ] . V_192 )
return;
}
}
for ( V_3 = 0 ; V_3 < V_221 -> V_142 ; V_3 ++ ) {
T_4 V_178 = V_221 -> V_143 [ V_3 ] . V_187 ;
if ( V_178 == 0x0f ) {
V_221 -> V_143 [ V_3 ] . V_192 = V_177 ++ ;
} else {
if ( ! V_222 [ V_178 ] )
V_222 [ V_178 ] = ++ V_177 ;
V_221 -> V_143 [ V_3 ] . V_192 = V_222 [ V_178 ] - 1 ;
}
}
if ( V_3 > 1 ) {
T_4 * V_183 = F_51 ( V_6 -> V_16 ) ;
if ( V_183 )
V_183 [ 0 ] = 0x00 ;
}
}
static int
F_66 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_184 * V_175 = & V_6 -> V_175 ;
T_4 * V_221 , * V_189 ;
int V_177 ;
V_221 = F_47 ( V_16 ) ;
if ( ! V_221 ) {
if ( V_6 -> type == V_223 ) {
F_60 ( V_16 , V_6 ) ;
return 0 ;
}
return - V_36 ;
}
F_5 ( V_22 , L_47 , V_221 [ 0 ] >> 4 , V_221 [ 0 ] & 0xf ) ;
V_175 -> V_125 = V_221 [ 0 ] ;
F_49 ( V_16 , NULL , F_64 ) ;
if ( V_175 -> V_125 < 0x21 )
F_57 ( V_16 , V_175 ) ;
V_177 = - 1 ;
while ( ( V_189 = F_52 ( V_16 , ++ V_177 ) ) ) {
if ( V_189 [ 0 ] != 0xff ) {
if ( F_51 ( V_16 ) [ 3 ] < 4 )
F_5 ( V_22 , L_48 ,
V_177 , F_3 ( V_189 [ 0 ] ) ) ;
else
F_5 ( V_22 , L_49 ,
V_177 , F_32 ( V_189 [ 0 ] ) ) ;
}
}
F_65 ( V_6 ) ;
return 0 ;
}
static int F_67 ( struct V_15 * V_16 , struct V_5 * V_6 , T_2 V_224 , int V_143 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_55 * V_41 = & V_22 -> V_41 . V_56 ;
T_1 V_225 ;
T_2 V_226 ;
int V_3 ;
if ( V_6 -> V_1 [ V_224 ] <= V_143 ) {
F_14 ( V_22 , L_50
L_51 ) ;
return - V_54 ;
}
V_225 = V_6 -> V_1 [ V_224 + 1 ] ;
if ( V_225 != 36 ) {
F_14 ( V_22 , L_52 ) ;
return - V_36 ;
}
F_5 ( V_22 , L_53 ) ;
V_226 = V_224 + 2 + V_143 * V_225 ;
F_19 ( V_41 , 0x00001304 , F_32 ( V_6 -> V_1 [ V_226 ] ) ) ;
V_225 -= 4 ;
for ( V_3 = 0 ; V_3 < V_225 ; V_3 += 4 )
F_19 ( V_41 , 0x00001400 + V_3 , F_32 ( V_6 -> V_1 [ V_226 + V_3 + 4 ] ) ) ;
F_19 ( V_41 , V_227 , F_16 ( V_41 , V_227 ) | 0x18 ) ;
return 0 ;
}
static int F_68 ( struct V_15 * V_16 ,
struct V_5 * V_6 )
{
const T_1 V_228 [] = { 'H' , 'W' , 'S' , 'Q' } ;
const int V_229 = sizeof( V_228 ) ;
int V_224 ;
V_224 = F_46 ( V_6 -> V_1 , V_6 -> V_2 , V_228 , V_229 ) ;
if ( ! V_224 )
return 0 ;
return F_67 ( V_16 , V_6 , V_224 + V_229 , 0 ) ;
}
T_1 * F_69 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
const T_1 V_230 [] = {
0x00 , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0x00 } ;
T_2 V_121 = 0 ;
T_2 V_231 ;
int V_232 = V_233 ;
if ( V_6 -> V_30 . V_234 )
return V_6 -> V_30 . V_234 ;
while ( V_232 ) {
V_231 = F_46 ( & V_6 -> V_1 [ V_121 ] , V_232 ,
V_230 , 8 ) ;
if ( ! V_231 )
return NULL ;
V_121 += V_231 ;
if ( ! F_1 ( & V_6 -> V_1 [ V_121 ] , V_235 ) )
break;
V_232 -= V_121 ;
V_121 ++ ;
}
F_5 ( V_22 , L_54 ) ;
return V_6 -> V_30 . V_234 = & V_6 -> V_1 [ V_121 ] ;
}
static bool F_70 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_236 * V_6 = F_71 ( & V_22 -> V_41 ) ;
struct V_5 * V_112 = & V_22 -> V_28 ;
memset ( V_112 , 0 , sizeof( struct V_5 ) ) ;
F_72 ( & V_112 -> V_237 ) ;
V_112 -> V_16 = V_16 ;
V_112 -> V_1 = V_6 -> V_1 ;
V_112 -> V_2 = V_6 -> V_238 ;
V_112 -> V_12 = V_6 -> V_125 . V_239 ;
V_112 -> V_110 = V_6 -> V_125 . V_240 ;
if ( V_6 -> V_241 ) {
V_112 -> type = V_144 ;
V_112 -> V_121 = V_6 -> V_241 ;
return ! F_43 ( V_112 , V_112 -> V_121 + 6 ) ;
} else
if ( V_6 -> V_242 ) {
V_112 -> type = V_223 ;
V_112 -> V_121 = V_6 -> V_242 ;
return ! F_45 ( V_16 , V_112 , V_112 -> V_121 ) ;
}
return false ;
}
int
F_73 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_60 = 0 ;
V_6 -> V_243 . V_244 = 0 ;
if ( V_6 -> V_12 < 5 )
F_68 ( V_16 , V_6 ) ;
if ( V_6 -> V_245 ) {
V_6 -> V_30 . V_61 = 0 ;
V_6 -> V_30 . V_62 = false ;
}
return V_60 ;
}
static bool
F_74 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
unsigned V_94 ;
if ( V_22 -> V_41 . V_71 . V_72 >= V_73 )
return true ;
V_94 = F_75 ( V_16 , 0 , 0x06 ) ;
V_94 |= ( F_75 ( V_16 , 0 , 0x07 ) & 0x01 ) << 8 ;
V_94 |= ( F_75 ( V_16 , 0 , 0x07 ) & 0x20 ) << 4 ;
V_94 |= ( F_75 ( V_16 , 0 , 0x25 ) & 0x01 ) << 10 ;
V_94 |= ( F_75 ( V_16 , 0 , 0x41 ) & 0x01 ) << 11 ;
return ( V_94 != 0 ) ;
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
return - V_145 ;
V_60 = F_66 ( V_16 , V_6 ) ;
if ( V_60 )
return V_60 ;
if ( ! V_6 -> V_12 )
return 0 ;
V_6 -> V_245 = false ;
if ( ! F_74 ( V_16 ) ) {
F_5 ( V_22 , L_55
L_56 ) ;
V_6 -> V_245 = true ;
}
V_60 = F_73 ( V_16 ) ;
if ( V_60 )
return V_60 ;
if ( V_6 -> V_12 < 5 )
V_6 -> V_83 = F_75 ( V_16 , 0 , V_246 ) & 0x40 ;
if ( V_6 -> V_83 || V_6 -> V_12 >= 5 )
V_60 = F_23 ( V_16 , V_6 ) ;
V_6 -> V_245 = true ;
return 0 ;
}
void
F_77 ( struct V_15 * V_16 )
{
}
