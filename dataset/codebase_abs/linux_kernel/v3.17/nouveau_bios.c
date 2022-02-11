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
struct V_55 * V_41 = & V_22 -> V_41 ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_1 V_56 = V_6 -> V_1 [ V_6 -> V_30 . V_47 ] ;
T_3 V_57 , V_58 ;
int V_59 ;
if ( V_6 -> V_30 . V_60 == ( V_27 << 1 | V_19 ) || ! V_56 ||
( V_56 >= 0x30 && V_27 == V_43 ) )
return 0 ;
if ( ! V_6 -> V_30 . V_61 ) {
V_6 -> V_30 . V_61 = true ;
F_15 ( V_16 , V_18 , V_19 , V_43 , V_8 ) ;
}
if ( V_27 == V_46 && V_6 -> V_30 . V_62 )
F_15 ( V_16 , V_18 , V_19 , V_39 , V_8 ) ;
if ( V_27 == V_39 && V_6 -> V_30 . V_63 )
F_15 ( V_16 , V_18 , V_19 , V_38 , V_8 ) ;
F_5 ( V_22 , L_4 , V_27 ) ;
V_57 = F_16 ( V_41 , V_64 ) & 0x50000 ;
if ( V_56 < 0x30 )
V_59 = F_9 ( V_16 , V_18 , V_19 , V_27 ) ;
else
V_59 = F_13 ( V_16 , V_18 , V_19 , V_27 , V_8 ) ;
V_6 -> V_30 . V_60 = ( V_27 << 1 | V_19 ) ;
V_58 = F_17 ( V_16 , 0 , V_64 ) & ~ 0x50000 ;
F_18 ( V_16 , 0 , V_64 , V_58 | V_57 ) ;
F_19 ( V_41 , V_65 , 0 ) ;
return V_59 ;
}
static int F_20 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_66 * V_67 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_1 V_56 , V_68 , V_69 ;
memset ( V_67 , 0 , sizeof( struct V_66 ) ) ;
if ( V_6 -> V_30 . V_47 == 0x0 ) {
F_14 ( V_22 , L_5 ) ;
return - V_36 ;
}
V_56 = V_6 -> V_1 [ V_6 -> V_30 . V_47 ] ;
switch ( V_56 ) {
case 0x0a :
V_68 = 2 ;
V_69 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 1 ] ;
break;
case 0x30 :
V_68 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 1 ] ;
if ( V_68 < 0x1f ) {
F_14 ( V_22 , L_6 ) ;
return - V_36 ;
}
V_69 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 2 ] ;
break;
case 0x40 :
V_68 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 1 ] ;
if ( V_68 < 0x7 ) {
F_14 ( V_22 , L_6 ) ;
return - V_36 ;
}
V_69 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 2 ] ;
break;
default:
F_14 ( V_22 ,
L_7 ,
V_56 >> 4 , V_56 & 0xf ) ;
return - V_44 ;
}
V_67 -> V_56 = V_56 ;
V_67 -> V_68 = V_68 ;
V_67 -> V_69 = V_69 ;
return 0 ;
}
static int
F_21 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_55 * V_41 = & V_21 ( V_16 ) -> V_41 ;
if ( V_6 -> V_12 < 5 && V_6 -> V_1 [ 0x48 ] & 0x4 )
return F_22 ( V_16 , 0 , 0xf ) & 0xf ;
if ( V_41 -> V_70 . V_71 >= V_72 )
return ( F_16 ( V_41 , V_73 ) >> 24 ) & 0xf ;
else
return ( F_16 ( V_41 , V_73 ) >> 16 ) & 0xf ;
}
static int F_23 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_1 * V_74 ;
T_1 V_75 , V_68 = 0 , V_69 , V_76 = 0xf , V_77 ;
int V_59 , V_78 , V_79 ;
struct V_66 V_67 ;
if ( V_6 -> V_30 . V_80 == 0x0 ) {
#ifndef F_11
F_14 ( V_22 , L_8 ) ;
#endif
V_6 -> V_81 = 0x4b ;
return 0 ;
}
V_74 = & V_6 -> V_1 [ V_6 -> V_30 . V_80 ] ;
V_75 = V_74 [ 0 ] ;
switch ( V_75 ) {
case 0x05 :
V_69 = 42 ;
V_78 = - 1 ;
break;
case 0x10 :
V_69 = 44 ;
V_78 = 0 ;
break;
case 0x20 :
V_68 = V_74 [ 1 ] ;
V_69 = V_74 [ 2 ] ;
V_76 = V_74 [ 3 ] ;
V_6 -> V_81 = V_74 [ 4 ] ;
V_78 = - 7 ;
break;
default:
F_14 ( V_22 ,
L_9 ,
V_75 >> 4 , V_75 & 0xf ) ;
return - V_44 ;
}
if ( ! V_6 -> V_82 )
return 0 ;
V_59 = F_20 ( V_16 , V_6 , & V_67 ) ;
if ( V_59 )
return V_59 ;
if ( V_67 . V_56 == 0x30 || V_67 . V_56 == 0x40 ) {
V_6 -> V_30 . V_83 = V_6 -> V_30 . V_47 +
V_67 . V_68 + 1 ;
V_6 -> V_30 . V_84 = V_67 . V_69 ;
}
if ( V_6 -> V_30 . V_83 == 0x0 ) {
F_14 ( V_22 , L_10 ) ;
return - V_36 ;
}
V_79 = F_21 ( V_16 , V_6 ) ;
V_77 = V_6 -> V_1 [ V_6 -> V_30 . V_83 +
V_79 * V_6 -> V_30 . V_84 ] ;
if ( V_77 > V_76 ) {
F_14 ( V_22 , L_11 ) ;
return - V_54 ;
}
if ( V_67 . V_56 > 0x10 )
V_6 -> V_85 = V_79 != 0xf || V_77 != 0xf ;
if ( V_79 == 0xf || V_77 == 0xf )
return 0 ;
V_6 -> V_30 . V_86 = V_6 -> V_30 . V_80 + V_68 +
V_69 * V_77 + V_78 ;
F_5 ( V_22 , L_12 ,
F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_86 + 11 ] ) + 1 ,
F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_86 + 25 ] ) + 1 ,
F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_86 + 7 ] ) * 10 ) ;
return 0 ;
}
bool F_24 ( struct V_15 * V_16 , struct V_87 * V_88 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_1 * V_89 = & V_6 -> V_1 [ V_6 -> V_30 . V_86 ] ;
if ( ! V_88 )
return V_6 -> V_30 . V_86 ;
memset ( V_88 , 0 , sizeof( struct V_87 ) ) ;
V_88 -> clock = F_3 ( V_89 [ 7 ] ) * 10 ;
V_88 -> V_90 = F_3 ( V_89 [ 11 ] ) + 1 ;
V_88 -> V_91 = F_3 ( V_89 [ 17 ] ) + 1 ;
V_88 -> V_92 = F_3 ( V_89 [ 19 ] ) + 1 ;
V_88 -> V_93 = F_3 ( V_89 [ 21 ] ) + 1 ;
V_88 -> V_94 = F_3 ( V_89 [ 25 ] ) + 1 ;
V_88 -> V_95 = F_3 ( V_89 [ 31 ] ) + 1 ;
V_88 -> V_96 = F_3 ( V_89 [ 33 ] ) + 1 ;
V_88 -> V_97 = F_3 ( V_89 [ 35 ] ) + 1 ;
V_88 -> V_98 |= ( V_89 [ 37 ] & 0x10 ) ?
V_99 : V_100 ;
V_88 -> V_98 |= ( V_89 [ 37 ] & 0x1 ) ?
V_101 : V_102 ;
V_88 -> V_103 = V_104 ;
V_88 -> type = V_105 | V_106 ;
F_25 ( V_88 ) ;
return V_6 -> V_30 . V_86 ;
}
int F_26 ( struct V_15 * V_16 , int V_8 , bool * V_20 , bool * V_51 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_79 = F_21 ( V_16 , V_6 ) , V_107 = 0 ;
struct V_66 V_67 ;
T_2 V_108 ;
int V_59 , V_109 = V_6 -> V_109 ;
V_59 = F_20 ( V_16 , V_6 , & V_67 ) ;
if ( V_59 )
return V_59 ;
switch ( V_67 . V_56 ) {
case 0x0a :
V_107 = V_6 -> V_1 [
V_6 -> V_30 . V_110 +
V_79 ] ;
if ( ! V_8 )
break;
if ( V_109 < 0x25 ) {
V_107 =
( V_6 -> V_111 . V_112 & 1 ) ?
2 : 0 ;
if ( V_8 >= V_6 -> V_30 . V_113 )
V_107 ++ ;
} else if ( V_109 < 0x30 ) {
V_107 = 0 ;
} else {
V_107 = 0 ;
if ( V_8 >= V_6 -> V_30 . V_113 )
V_107 = 2 ;
if ( V_8 >= 140000 )
V_107 = 3 ;
}
break;
case 0x30 :
case 0x40 :
V_107 = V_79 ;
break;
default:
F_14 ( V_22 , L_13 ) ;
return - V_44 ;
}
V_108 = V_6 -> V_30 . V_31 = V_6 -> V_30 . V_47 + V_67 . V_68 + V_67 . V_69 * V_107 ;
switch ( V_67 . V_56 ) {
case 0x0a :
V_6 -> V_30 . V_63 = V_6 -> V_1 [ V_108 ] & 1 ;
V_6 -> V_30 . V_62 = V_6 -> V_1 [ V_108 ] & 2 ;
V_6 -> V_30 . V_37 = V_6 -> V_1 [ V_108 ] & 4 ;
V_6 -> V_30 . V_32 = V_6 -> V_1 [ V_108 ] & 8 ;
* V_51 = V_6 -> V_1 [ V_108 ] & 16 ;
break;
case 0x30 :
case 0x40 :
V_6 -> V_30 . V_63 = true ;
V_6 -> V_30 . V_62 = true ;
V_6 -> V_30 . V_37 = V_6 -> V_1 [ V_108 ] & 1 ;
V_6 -> V_30 . V_51 = V_6 -> V_1 [ V_108 ] & 2 ;
V_6 -> V_30 . V_53 = V_6 -> V_1 [ V_6 -> V_30 . V_47 + 4 ] ;
V_6 -> V_30 . V_113 = F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_47 + 5 ] ) * 10 ;
break;
}
if ( V_8 && ( V_109 < 0x25 || V_109 > 0x28 ) )
V_6 -> V_30 . V_37 = ( V_8 >= V_6 -> V_30 . V_113 ) ;
* V_20 = V_6 -> V_30 . V_37 ;
return 0 ;
}
int F_27 ( struct V_15 * V_16 , struct V_17 * V_18 , int V_19 , int V_8 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_55 * V_41 = & V_22 -> V_41 ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_114 = V_6 -> V_109 ;
T_2 V_7 = 0 , V_11 ;
T_3 V_57 , V_58 ;
if ( V_114 >= 0x17 && V_114 != 0x1a && V_114 != 0x20 &&
V_18 -> V_115 != V_116 )
return 0 ;
switch ( F_28 ( V_18 -> V_33 ) ) {
case 1 :
V_7 = V_6 -> V_117 . V_118 ;
break;
case 2 :
case 3 :
V_7 = V_6 -> V_117 . V_119 ;
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
V_57 = F_16 ( V_41 , V_64 ) & 0x50000 ;
F_4 ( V_16 , V_11 , V_18 , V_19 , V_8 >= 165000 ) ;
V_58 = F_17 ( V_16 , 0 , V_64 ) & ~ 0x50000 ;
F_18 ( V_16 , 0 , V_64 , V_58 | V_57 ) ;
return 0 ;
}
static void F_29 ( struct V_5 * V_6 , T_2 V_120 )
{
V_6 -> V_14 = F_3 ( V_6 -> V_1 [ V_120 ] ) ;
}
static int F_30 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_121 * V_122 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_123 ;
T_1 V_124 , V_68 , V_125 , V_126 ;
if ( V_122 -> V_2 != 3 ) {
F_14 ( V_22 , L_15 ) ;
return - V_36 ;
}
V_123 = F_3 ( V_6 -> V_1 [ V_122 -> V_120 ] ) ;
if ( V_123 == 0x0 ) {
F_31 ( V_22 , L_16 ) ;
return - V_36 ;
}
V_124 = V_6 -> V_1 [ V_123 ] ;
if ( V_124 != 0x10 ) {
F_14 ( V_22 , L_17 ,
V_124 >> 4 , V_124 & 0xF ) ;
return - V_44 ;
}
V_68 = V_6 -> V_1 [ V_123 + 1 ] ;
V_125 = V_6 -> V_1 [ V_123 + 2 ] ;
V_126 = V_6 -> V_1 [ V_123 + 3 ] ;
if ( V_68 != 4 || V_125 != 4 || V_126 != 2 ) {
F_14 ( V_22 , L_18 ) ;
return - V_36 ;
}
V_6 -> V_127 = F_32 ( V_6 -> V_1 [ V_123 + V_68 ] ) & 0x3ff ;
return 0 ;
}
static int F_33 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_121 * V_122 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_122 -> V_2 != 4 ) {
F_14 ( V_22 , L_19 ) ;
return - V_36 ;
}
V_6 -> V_30 . V_80 = F_3 ( V_6 -> V_1 [ V_122 -> V_120 + 2 ] ) ;
return 0 ;
}
static int F_34 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_121 * V_122 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_122 -> V_2 < 14 ) {
F_14 ( V_22 , L_20 ) ;
return - V_36 ;
}
F_29 ( V_6 , V_122 -> V_120 ) ;
return 0 ;
}
static int F_35 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_121 * V_122 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_128 ;
T_1 V_129 , V_130 ;
if ( V_122 -> V_2 < 6 ) {
F_14 ( V_22 , L_21 ) ;
return - V_36 ;
}
V_6 -> V_131 = V_6 -> V_1 [ V_122 -> V_120 + 5 ] ;
V_6 -> V_82 = V_6 -> V_131 & V_132 ;
if ( V_122 -> V_2 < 15 ) {
F_36 ( V_22 , L_22
L_23 ) ;
return - V_36 ;
}
V_128 = F_3 ( V_6 -> V_1 [ V_122 -> V_120 + 13 ] ) ;
if ( ! V_128 )
return 0 ;
V_129 = V_6 -> V_1 [ V_128 ] ;
V_130 = V_6 -> V_1 [ V_128 + 1 ] ;
if ( V_129 != 0x00 && V_129 != 0x10 ) {
F_36 ( V_22 , L_24
L_25 , V_129 >> 4 , V_129 & 0xf ) ;
return - V_44 ;
}
V_6 -> V_127 = F_32 ( V_6 -> V_1 [ V_128 + V_130 ] ) ;
V_6 -> V_133 = F_32 ( V_6 -> V_1 [ V_128 + V_130 + 4 ] ) ;
return 0 ;
}
static int F_37 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_121 * V_122 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_122 -> V_2 != 2 ) {
F_14 ( V_22 , L_26 ) ;
return - V_36 ;
}
V_6 -> V_30 . V_47 = F_3 ( V_6 -> V_1 [ V_122 -> V_120 ] ) ;
return 0 ;
}
static int
F_38 ( struct V_15 * V_16 , struct V_5 * V_6 ,
struct V_121 * V_122 )
{
if ( V_122 -> V_2 < 0x5 )
return 0 ;
if ( V_122 -> V_124 < 2 ) {
V_6 -> V_134 = V_6 -> V_1 [ V_122 -> V_120 + 2 ] ;
V_6 -> V_135 = F_3 ( V_6 -> V_1 [ V_122 -> V_120 + 3 ] ) ;
} else {
V_6 -> V_134 = V_6 -> V_1 [ V_122 -> V_120 + 0 ] ;
V_6 -> V_135 = F_3 ( V_6 -> V_1 [ V_122 -> V_120 + 1 ] ) ;
}
return 0 ;
}
static int F_39 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_121 * V_122 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_136 , V_137 , V_138 ;
if ( V_122 -> V_2 != 2 ) {
F_14 ( V_22 , L_27 ) ;
return - V_36 ;
}
V_136 = F_3 ( V_6 -> V_1 [ V_122 -> V_120 ] ) ;
if ( ! V_136 ) {
F_14 ( V_22 , L_28 ) ;
return - V_36 ;
}
F_5 ( V_22 , L_29 ,
V_6 -> V_1 [ V_136 ] >> 4 , V_6 -> V_1 [ V_136 ] & 0xf ) ;
if ( V_6 -> V_1 [ V_136 ] != 0x11 )
return - V_44 ;
V_137 = F_3 ( V_6 -> V_1 [ V_136 + 7 ] ) ;
V_138 = F_3 ( V_6 -> V_1 [ V_136 + 9 ] ) ;
if ( V_6 -> V_1 [ V_137 ] != 'q' || V_6 -> V_1 [ V_138 ] != 'q' )
F_36 ( V_22 , L_30 ) ;
V_6 -> V_117 . V_118 = F_3 ( V_6 -> V_1 [ V_136 + 11 ] ) ;
V_6 -> V_117 . V_119 = F_3 ( V_6 -> V_1 [ V_136 + 13 ] ) ;
return 0 ;
}
int
F_40 ( struct V_15 * V_16 , T_4 V_139 , struct V_121 * V_140 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_4 V_141 , * V_142 ;
if ( V_6 -> type != V_143 )
return - V_144 ;
V_141 = V_6 -> V_1 [ V_6 -> V_120 + 10 ] ;
V_142 = & V_6 -> V_1 [ V_6 -> V_120 + 12 ] ;
while ( V_141 -- ) {
if ( V_142 [ 0 ] == V_139 ) {
V_140 -> V_139 = V_142 [ 0 ] ;
V_140 -> V_124 = V_142 [ 1 ] ;
V_140 -> V_2 = F_3 ( V_142 [ 2 ] ) ;
V_140 -> V_120 = F_3 ( V_142 [ 4 ] ) ;
V_140 -> V_1 = F_41 ( V_16 , V_142 [ 4 ] ) ;
return 0 ;
}
V_142 += V_6 -> V_1 [ V_6 -> V_120 + 9 ] ;
}
return - V_54 ;
}
static int
F_42 ( struct V_5 * V_6 , const T_2 V_145 ,
struct F_40 * V_146 )
{
struct V_15 * V_16 = V_6 -> V_16 ;
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_121 V_122 ;
if ( F_40 ( V_16 , V_146 -> V_139 , & V_122 ) == 0 )
return V_146 -> V_147 ( V_16 , V_6 , & V_122 ) ;
F_5 ( V_22 , L_31 , V_146 -> V_139 ) ;
return - V_44 ;
}
static int
F_43 ( struct V_5 * V_6 , const T_2 V_145 )
{
int V_59 ;
V_59 = F_42 ( V_6 , V_145 , & F_44 ( 'i' , V_3 ) ) ;
if ( V_59 )
return V_59 ;
if ( V_6 -> V_12 >= 0x60 )
F_42 ( V_6 , V_145 , & F_44 ( 'A' , V_148 ) ) ;
F_42 ( V_6 , V_145 , & F_44 ( 'D' , V_149 ) ) ;
V_59 = F_42 ( V_6 , V_145 , & F_44 ( 'I' , V_150 ) ) ;
if ( V_59 )
return V_59 ;
F_42 ( V_6 , V_145 , & F_44 ( 'M' , V_151 ) ) ;
F_42 ( V_6 , V_145 , & F_44 ( 'L' , V_152 ) ) ;
F_42 ( V_6 , V_145 , & F_44 ( 'T' , V_117 ) ) ;
return 0 ;
}
static int F_45 ( struct V_15 * V_16 , struct V_5 * V_6 , unsigned int V_120 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_1 * V_153 = & V_6 -> V_1 [ V_120 ] , V_154 , V_155 ;
T_2 V_156 ;
T_2 V_157 , V_158 ;
V_6 -> V_81 = 0x4b ;
V_6 -> V_159 = 256000 ;
V_6 -> V_160 = 128000 ;
V_6 -> V_30 . V_113 = 90000 ;
V_154 = V_153 [ 5 ] ;
V_155 = V_153 [ 6 ] ;
F_5 ( V_22 , L_32 ,
V_154 , V_155 ) ;
if ( V_154 < 5 )
* ( T_2 * ) & V_6 -> V_1 [ 0x36 ] = 0 ;
if ( ( V_154 < 5 && V_155 != 1 ) || V_154 > 5 ) {
F_14 ( V_22 , L_33
L_34 ) ;
return - V_44 ;
}
if ( V_154 == 0 )
return 0 ;
else if ( V_154 == 1 )
V_156 = 44 ;
else if ( V_154 == 2 )
V_156 = 48 ;
else if ( V_154 == 3 )
V_156 = 54 ;
else if ( V_154 == 4 || V_155 < 0x1 )
V_156 = 62 ;
else if ( V_155 < 0x6 )
V_156 = 67 ;
else if ( V_155 < 0x10 )
V_156 = 75 ;
else if ( V_155 == 0x10 )
V_156 = 89 ;
else if ( V_155 < 0x14 )
V_156 = 118 ;
else if ( V_155 < 0x24 )
V_156 = 123 ;
else if ( V_155 < 0x27 )
V_156 = 144 ;
else
V_156 = 158 ;
if ( F_1 ( V_153 , 8 ) ) {
F_14 ( V_22 , L_35 ) ;
return - V_36 ;
}
V_6 -> V_131 = V_153 [ 9 ] ;
if ( V_154 < 5 || V_155 < 0x10 )
V_6 -> V_161 = true ;
V_157 = 18 ;
if ( V_154 < 2 )
V_157 -= 4 ;
V_6 -> V_14 = F_3 ( V_153 [ V_157 ] ) ;
V_6 -> V_162 = F_3 ( V_153 [ V_157 + 2 ] ) ;
if ( V_154 > 2 ) {
V_6 -> V_111 . V_163 = F_3 ( V_153 [ 24 ] ) ;
V_6 -> V_111 . V_164 = F_3 ( V_153 [ 26 ] ) ;
V_6 -> V_111 . V_165 = F_3 ( V_153 [ 28 ] ) ;
}
V_158 = 0x48 ;
if ( V_156 > 61 )
V_158 = V_120 + 54 ;
V_6 -> V_111 . V_166 . V_167 = V_6 -> V_1 [ V_158 ] ;
V_6 -> V_111 . V_166 . V_168 = V_6 -> V_1 [ V_158 + 1 ] ;
V_6 -> V_111 . V_166 . V_169 = V_6 -> V_1 [ V_158 + 2 ] ;
if ( V_156 > 74 ) {
V_6 -> V_159 = F_32 ( V_153 [ 67 ] ) ;
V_6 -> V_160 = F_32 ( V_153 [ 71 ] ) ;
}
if ( V_156 > 88 )
F_29 ( V_6 , V_120 + 75 ) ;
if ( V_156 > 94 ) {
V_6 -> V_117 . V_118 = F_3 ( V_153 [ 89 ] ) ;
V_6 -> V_117 . V_119 = F_3 ( V_153 [ 91 ] ) ;
V_6 -> V_111 . V_112 = F_3 ( V_153 [ 95 ] ) ;
}
if ( V_156 > 108 ) {
V_6 -> V_30 . V_80 = F_3 ( V_153 [ 105 ] ) ;
V_6 -> V_30 . V_83 = F_3 ( V_153 [ 107 ] ) ;
V_6 -> V_30 . V_84 = 1 ;
}
if ( V_156 > 120 ) {
V_6 -> V_30 . V_47 = F_3 ( V_153 [ 117 ] ) ;
V_6 -> V_30 . V_110 = F_3 ( V_153 [ 119 ] ) ;
}
#if 0
if (bmplength > 143)
bios->pll_limit_tbl_ptr = ROM16(bmp[142]);
#endif
if ( V_156 > 157 )
V_6 -> V_30 . V_113 = F_3 ( V_153 [ 156 ] ) * 10 ;
return 0 ;
}
static T_2 F_46 ( T_1 * V_1 , int V_170 , const T_1 * V_171 , int V_172 )
{
int V_3 , V_173 ;
for ( V_3 = 0 ; V_3 <= ( V_170 - V_172 ) ; V_3 ++ ) {
for ( V_173 = 0 ; V_173 < V_172 ; V_173 ++ )
if ( V_1 [ V_3 + V_173 ] != V_171 [ V_173 ] )
break;
if ( V_173 == V_172 )
return V_3 ;
}
return 0 ;
}
void *
F_47 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_4 * V_174 = NULL ;
if ( V_22 -> V_41 . V_70 . V_71 > V_175 )
V_174 = F_41 ( V_16 , V_22 -> V_28 . V_1 [ 0x36 ] ) ;
if ( ! V_174 ) {
F_36 ( V_22 , L_36 ) ;
return NULL ;
}
if ( V_174 [ 0 ] >= 0x41 ) {
F_36 ( V_22 , L_37 , V_174 [ 0 ] ) ;
return NULL ;
} else
if ( V_174 [ 0 ] >= 0x30 ) {
if ( F_32 ( V_174 [ 6 ] ) == 0x4edcbdcb )
return V_174 ;
} else
if ( V_174 [ 0 ] >= 0x20 ) {
if ( F_32 ( V_174 [ 4 ] ) == 0x4edcbdcb )
return V_174 ;
} else
if ( V_174 [ 0 ] >= 0x15 ) {
if ( ! memcmp ( & V_174 [ - 7 ] , L_38 , 7 ) )
return V_174 ;
} else {
F_36 ( V_22 , L_39 ) ;
return NULL ;
}
F_36 ( V_22 , L_40 ) ;
return NULL ;
}
void *
F_48 ( struct V_15 * V_16 , T_4 V_176 )
{
T_4 * V_174 = F_47 ( V_16 ) ;
if ( V_174 && V_174 [ 0 ] >= 0x30 ) {
if ( V_176 < V_174 [ 2 ] )
return V_174 + V_174 [ 1 ] + ( V_176 * V_174 [ 3 ] ) ;
} else
if ( V_174 && V_174 [ 0 ] >= 0x20 ) {
T_4 * V_177 = F_41 ( V_16 , V_174 [ 2 ] ) ;
T_4 * V_178 = V_174 + 8 + ( V_176 * 8 ) ;
if ( V_177 && V_178 < V_177 )
return V_178 ;
} else
if ( V_174 && V_174 [ 0 ] >= 0x15 ) {
T_4 * V_177 = F_41 ( V_16 , V_174 [ 2 ] ) ;
T_4 * V_178 = V_174 + 4 + ( V_176 * 10 ) ;
if ( V_177 && V_178 < V_177 )
return V_178 ;
}
return NULL ;
}
int
F_49 ( struct V_15 * V_16 , void * V_1 ,
int (* F_50)( struct V_15 * , void * , int V_176 , T_4 * V_179 ) )
{
int V_59 , V_176 = - 1 ;
T_4 * V_179 = NULL ;
while ( ( V_179 = F_48 ( V_16 , ++ V_176 ) ) ) {
if ( F_32 ( V_179 [ 0 ] ) == 0x00000000 )
break;
if ( F_32 ( V_179 [ 0 ] ) == 0xffffffff )
break;
if ( ( V_179 [ 0 ] & 0x0f ) == V_180 )
continue;
if ( ( V_179 [ 0 ] & 0x0f ) == V_181 )
break;
V_59 = F_50 ( V_16 , V_1 , V_176 , V_179 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
T_4 *
F_51 ( struct V_15 * V_16 )
{
T_4 * V_174 = F_47 ( V_16 ) ;
if ( V_174 && V_174 [ 0 ] >= 0x30 && V_174 [ 1 ] >= 0x16 ) {
T_4 * V_182 = F_41 ( V_16 , V_174 [ 0x14 ] ) ;
if ( V_182 && V_182 [ 0 ] >= 0x30 && V_182 [ 0 ] <= 0x40 )
return V_182 ;
}
return NULL ;
}
T_4 *
F_52 ( struct V_15 * V_16 , T_4 V_176 )
{
T_4 * V_182 = F_51 ( V_16 ) ;
if ( V_182 && V_176 < V_182 [ 2 ] )
return V_182 + V_182 [ 1 ] + ( V_176 * V_182 [ 3 ] ) ;
return NULL ;
}
static struct V_17 * F_53 ( struct V_183 * V_174 )
{
struct V_17 * V_142 = & V_174 -> V_142 [ V_174 -> V_141 ] ;
memset ( V_142 , 0 , sizeof( struct V_17 ) ) ;
V_142 -> V_184 = V_174 -> V_141 ++ ;
return V_142 ;
}
static void F_54 ( struct V_183 * V_174 , int type , int V_177 ,
int V_185 , int V_33 )
{
struct V_17 * V_142 = F_53 ( V_174 ) ;
V_142 -> type = type ;
V_142 -> V_186 = V_177 ;
V_142 -> V_185 = V_185 ;
if ( type != V_187 )
V_142 -> V_115 = ! V_116 ;
V_142 -> V_33 = V_33 ;
}
static bool
F_55 ( struct V_15 * V_16 , struct V_183 * V_174 ,
T_3 V_188 , T_3 V_189 , struct V_17 * V_142 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
int V_190 = 0 ;
V_142 -> type = V_188 & 0xf ;
V_142 -> V_186 = ( V_188 >> 4 ) & 0xf ;
V_142 -> V_185 = ( V_188 >> 8 ) & 0xf ;
V_142 -> V_191 = ( V_188 >> 12 ) & 0xf ;
V_142 -> V_192 = ( V_188 >> 16 ) & 0xf ;
V_142 -> V_115 = ( V_188 >> 20 ) & 0x3 ;
V_142 -> V_33 = ( V_188 >> 24 ) & 0xf ;
switch ( V_142 -> type ) {
case V_187 :
V_142 -> V_193 . V_194 = ( V_174 -> V_124 < 0x30 ) ?
( V_189 & 0xffff ) * 10 :
( V_189 & 0xff ) * 10000 ;
break;
case V_195 :
{
T_3 V_196 ;
if ( V_189 & 0x1 )
V_142 -> V_49 . V_50 = true ;
if ( V_174 -> V_124 < 0x22 ) {
V_196 = ~ 0xd ;
V_142 -> V_49 . V_50 = true ;
if ( V_189 & 0x4 || V_189 & 0x8 )
V_142 -> V_49 . V_197 = true ;
} else {
V_196 = ~ 0x7 ;
if ( V_189 & 0x2 )
V_142 -> V_49 . V_198 = true ;
if ( V_189 & 0x4 )
V_142 -> V_49 . V_197 = true ;
V_142 -> V_49 . V_199 . V_190 = ( V_189 & 0x00000030 ) >> 4 ;
V_190 = V_142 -> V_49 . V_199 . V_190 ;
}
if ( V_189 & V_196 ) {
if ( V_174 -> V_124 >= 0x40 )
break;
F_14 ( V_22 , L_41
L_42 ) ;
}
break;
}
case V_200 :
{
if ( V_174 -> V_124 >= 0x30 )
V_142 -> V_201 . V_202 = V_189 & ( 0x8 << 4 ) ;
else
V_142 -> V_201 . V_202 = false ;
break;
}
case V_203 :
V_142 -> V_204 . V_199 . V_190 = ( V_189 & 0x00000030 ) >> 4 ;
V_142 -> V_205 = ( V_189 & 0x0000ff00 ) >> 8 ;
switch ( ( V_189 & 0x00e00000 ) >> 21 ) {
case 0 :
V_142 -> V_204 . V_206 = 162000 ;
break;
case 1 :
V_142 -> V_204 . V_206 = 270000 ;
break;
default:
V_142 -> V_204 . V_206 = 540000 ;
break;
}
switch ( ( V_189 & 0x0f000000 ) >> 24 ) {
case 0xf :
V_142 -> V_204 . V_207 = 4 ;
break;
case 0x3 :
V_142 -> V_204 . V_207 = 2 ;
break;
default:
V_142 -> V_204 . V_207 = 1 ;
break;
}
V_190 = V_142 -> V_204 . V_199 . V_190 ;
break;
case V_208 :
if ( V_174 -> V_124 >= 0x40 ) {
V_142 -> V_209 . V_199 . V_190 = ( V_189 & 0x00000030 ) >> 4 ;
V_142 -> V_205 = ( V_189 & 0x0000ff00 ) >> 8 ;
V_190 = V_142 -> V_209 . V_199 . V_190 ;
}
else if ( V_174 -> V_124 >= 0x30 )
V_142 -> V_209 . V_210 = ( V_189 & 0x00000700 ) >> 8 ;
else if ( V_174 -> V_124 >= 0x22 )
V_142 -> V_209 . V_210 = ( V_189 & 0x00000070 ) >> 4 ;
break;
case V_181 :
V_174 -> V_141 -- ;
return false ;
default:
break;
}
if ( V_174 -> V_124 < 0x40 ) {
V_142 -> V_211 =
( ( 1 << ( F_28 ( V_142 -> V_33 ) - 1 ) ) * 3 == V_142 -> V_33 ) ;
} else {
V_142 -> V_211 = ( V_142 -> V_212 . V_190 == 3 ) ;
}
if ( V_189 & 0x100000 )
V_142 -> V_213 = true ;
V_142 -> V_214 = ( V_142 -> V_115 << 4 ) | V_142 -> type ;
V_142 -> V_215 = ( V_142 -> V_185 << 8 ) | ( V_190 << 6 ) | V_142 -> V_33 ;
return true ;
}
static bool
F_56 ( struct V_15 * V_16 , struct V_183 * V_174 ,
T_3 V_188 , T_3 V_189 , struct V_17 * V_142 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
switch ( V_188 & 0x0000000f ) {
case 0 :
V_142 -> type = V_187 ;
break;
case 1 :
V_142 -> type = V_200 ;
break;
case 2 :
case 4 :
if ( V_188 & 0x10 )
V_142 -> type = V_195 ;
else
V_142 -> type = V_208 ;
break;
case 3 :
V_142 -> type = V_195 ;
break;
default:
F_14 ( V_22 , L_43 , V_188 & 0x0000000f ) ;
return false ;
}
V_142 -> V_186 = ( V_188 & 0x0003c000 ) >> 14 ;
V_142 -> V_185 = ( ( V_188 & 0x001c0000 ) >> 18 ) + 1 ;
V_142 -> V_33 = V_142 -> V_185 ;
V_142 -> V_115 = ( V_188 & 0x01e00000 ) >> 21 ;
V_142 -> V_192 = ( V_188 & 0x0e000000 ) >> 25 ;
V_142 -> V_211 = false ;
switch ( V_142 -> type ) {
case V_187 :
V_142 -> V_193 . V_194 = ( V_189 & 0xffff ) * 10 ;
break;
case V_200 :
V_142 -> V_201 . V_202 = false ;
break;
case V_195 :
if ( ( V_188 & 0x00003f00 ) >> 8 != 0x10 )
V_142 -> V_49 . V_50 = true ;
V_142 -> V_49 . V_197 = true ;
break;
default:
break;
}
return true ;
}
static
void F_57 ( struct V_15 * V_16 , struct V_183 * V_174 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
int V_3 , V_216 = 0 ;
for ( V_3 = 0 ; V_3 < V_174 -> V_141 ; V_3 ++ ) {
struct V_17 * V_217 = & V_174 -> V_142 [ V_3 ] ;
int V_173 ;
for ( V_173 = V_3 + 1 ; V_173 < V_174 -> V_141 ; V_173 ++ ) {
struct V_17 * V_218 = & V_174 -> V_142 [ V_173 ] ;
if ( V_218 -> type == 100 )
continue;
if ( V_218 -> V_186 == V_217 -> V_186 &&
V_218 -> type == V_217 -> type &&
V_218 -> V_115 == V_217 -> V_115 &&
V_218 -> V_33 == V_217 -> V_33 ) {
F_5 ( V_22 , L_44 ,
V_3 , V_173 ) ;
V_217 -> V_185 |= V_218 -> V_185 ;
V_218 -> type = 100 ;
}
}
}
for ( V_3 = 0 ; V_3 < V_174 -> V_141 ; V_3 ++ ) {
if ( V_174 -> V_142 [ V_3 ] . type == 100 )
continue;
if ( V_216 != V_3 ) {
V_174 -> V_142 [ V_216 ] = V_174 -> V_142 [ V_3 ] ;
V_174 -> V_142 [ V_216 ] . V_184 = V_216 ;
}
V_216 ++ ;
}
V_174 -> V_141 = V_216 ;
}
static bool
F_58 ( struct V_15 * V_16 , int V_176 , T_5 * V_188 , T_5 * V_189 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_183 * V_174 = & V_22 -> V_28 . V_174 ;
if ( F_59 ( V_16 , 0x040d , 0x1028 , 0x019b ) ) {
if ( * V_188 == 0x02026312 && * V_189 == 0x00000020 )
return false ;
}
if ( F_59 ( V_16 , 0x0201 , 0x1462 , 0x8851 ) ) {
if ( * V_188 == 0xf2005014 && * V_189 == 0xffffffff ) {
F_54 ( V_174 , V_208 , 1 , 1 , 1 ) ;
return false ;
}
}
if ( F_59 ( V_16 , 0x0ca3 , 0x1682 , 0x3003 ) ) {
if ( V_176 == 0 ) {
* V_188 = 0x02001300 ;
* V_189 = 0x00000028 ;
} else
if ( V_176 == 1 ) {
* V_188 = 0x01010312 ;
* V_189 = 0x00020030 ;
} else
if ( V_176 == 2 ) {
* V_188 = 0x01010310 ;
* V_189 = 0x00000028 ;
} else
if ( V_176 == 3 ) {
* V_188 = 0x02022362 ;
* V_189 = 0x00020010 ;
} else {
* V_188 = 0x0000000e ;
* V_189 = 0x00000000 ;
}
}
if ( F_59 ( V_16 , 0x0615 , 0x1682 , 0x2605 ) ) {
if ( V_176 == 0 ) {
* V_188 = 0x02002300 ;
* V_189 = 0x00000028 ;
} else
if ( V_176 == 1 ) {
* V_188 = 0x01010312 ;
* V_189 = 0x00020030 ;
} else
if ( V_176 == 2 ) {
* V_188 = 0x04020310 ;
* V_189 = 0x00000028 ;
} else
if ( V_176 == 3 ) {
* V_188 = 0x02021322 ;
* V_189 = 0x00020010 ;
} else {
* V_188 = 0x0000000e ;
* V_189 = 0x00000000 ;
}
}
if ( F_59 ( V_16 , 0x0421 , 0x3842 , 0xc793 ) ) {
if ( V_176 == 0 && * V_188 == 0x02000300 )
* V_188 = 0x02011300 ;
else
if ( V_176 == 1 && * V_188 == 0x04011310 )
* V_188 = 0x04000310 ;
else
if ( V_176 == 2 && * V_188 == 0x02011312 )
* V_188 = 0x02000312 ;
}
return true ;
}
static void
F_60 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_183 * V_174 = & V_6 -> V_174 ;
int V_219 = ( F_61 ( V_16 ) ? 3 : 1 ) ;
#ifdef F_11
if ( F_62 ( L_45 ) ) {
F_54 ( V_174 , V_208 , 0 , V_219 , 1 ) ;
F_54 ( V_174 , V_187 , 1 , V_219 , 2 ) ;
return;
}
#endif
F_54 ( V_174 , V_187 ,
V_6 -> V_111 . V_166 . V_167 , 1 , 1 ) ;
if ( F_63 ( V_16 , V_6 -> V_111 . V_166 . V_168 ) >= 0 )
F_54 ( V_174 , V_200 ,
V_6 -> V_111 . V_166 . V_168 ,
V_219 , 0 ) ;
else if ( V_6 -> V_117 . V_118 ||
V_6 -> V_117 . V_119 )
F_54 ( V_174 , V_208 ,
V_6 -> V_111 . V_166 . V_169 ,
V_219 , 1 ) ;
}
static int
F_64 ( struct V_15 * V_16 , void * V_1 , int V_176 , T_4 * V_179 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_183 * V_174 = & V_22 -> V_28 . V_174 ;
T_5 V_189 = ( V_174 -> V_124 >= 0x20 ) ? F_32 ( V_179 [ 4 ] ) : F_32 ( V_179 [ 6 ] ) ;
T_5 V_188 = F_32 ( V_179 [ 0 ] ) ;
bool V_59 ;
if ( F_58 ( V_16 , V_176 , & V_188 , & V_189 ) ) {
struct V_17 * V_142 = F_53 ( V_174 ) ;
F_5 ( V_22 , L_46 , V_176 , V_188 , V_189 ) ;
if ( V_174 -> V_124 >= 0x20 )
V_59 = F_55 ( V_16 , V_174 , V_188 , V_189 , V_142 ) ;
else
V_59 = F_56 ( V_16 , V_174 , V_188 , V_189 , V_142 ) ;
if ( ! V_59 )
return 1 ;
if ( V_142 -> type == V_200 &&
V_142 -> V_115 == V_116 )
V_142 -> V_186 = 0x0f ;
}
return 0 ;
}
static void
F_65 ( struct V_5 * V_6 )
{
struct V_183 * V_220 = & V_6 -> V_174 ;
T_4 V_221 [ 16 ] = { } ;
int V_3 , V_176 = 0 ;
if ( ! F_59 ( V_6 -> V_16 , 0x0392 , 0x107d , 0x20a2 ) ) {
for ( V_3 = 0 ; V_3 < V_220 -> V_141 ; V_3 ++ ) {
if ( V_220 -> V_142 [ V_3 ] . V_191 )
return;
}
}
for ( V_3 = 0 ; V_3 < V_220 -> V_141 ; V_3 ++ ) {
T_4 V_177 = V_220 -> V_142 [ V_3 ] . V_186 ;
if ( V_177 == 0x0f ) {
V_220 -> V_142 [ V_3 ] . V_191 = V_176 ++ ;
} else {
if ( ! V_221 [ V_177 ] )
V_221 [ V_177 ] = ++ V_176 ;
V_220 -> V_142 [ V_3 ] . V_191 = V_221 [ V_177 ] - 1 ;
}
}
if ( V_3 > 1 ) {
T_4 * V_182 = F_51 ( V_6 -> V_16 ) ;
if ( V_182 )
V_182 [ 0 ] = 0x00 ;
}
}
static int
F_66 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_183 * V_174 = & V_6 -> V_174 ;
T_4 * V_220 , * V_188 ;
int V_176 ;
V_220 = F_47 ( V_16 ) ;
if ( ! V_220 ) {
if ( V_6 -> type == V_222 ) {
F_60 ( V_16 , V_6 ) ;
return 0 ;
}
return - V_36 ;
}
F_5 ( V_22 , L_47 , V_220 [ 0 ] >> 4 , V_220 [ 0 ] & 0xf ) ;
V_174 -> V_124 = V_220 [ 0 ] ;
F_49 ( V_16 , NULL , F_64 ) ;
if ( V_174 -> V_124 < 0x21 )
F_57 ( V_16 , V_174 ) ;
V_176 = - 1 ;
while ( ( V_188 = F_52 ( V_16 , ++ V_176 ) ) ) {
if ( V_188 [ 0 ] != 0xff ) {
F_5 ( V_22 , L_48 , V_176 ) ;
if ( F_51 ( V_16 ) [ 3 ] < 4 )
F_67 ( L_49 , F_3 ( V_188 [ 0 ] ) ) ;
else
F_67 ( L_50 , F_32 ( V_188 [ 0 ] ) ) ;
}
}
F_65 ( V_6 ) ;
return 0 ;
}
static int F_68 ( struct V_15 * V_16 , struct V_5 * V_6 , T_2 V_223 , int V_142 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_55 * V_41 = & V_22 -> V_41 ;
T_1 V_224 ;
T_2 V_225 ;
int V_3 ;
if ( V_6 -> V_1 [ V_223 ] <= V_142 ) {
F_14 ( V_22 , L_51
L_52 ) ;
return - V_54 ;
}
V_224 = V_6 -> V_1 [ V_223 + 1 ] ;
if ( V_224 != 36 ) {
F_14 ( V_22 , L_53 ) ;
return - V_36 ;
}
F_5 ( V_22 , L_54 ) ;
V_225 = V_223 + 2 + V_142 * V_224 ;
F_19 ( V_41 , 0x00001304 , F_32 ( V_6 -> V_1 [ V_225 ] ) ) ;
V_224 -= 4 ;
for ( V_3 = 0 ; V_3 < V_224 ; V_3 += 4 )
F_19 ( V_41 , 0x00001400 + V_3 , F_32 ( V_6 -> V_1 [ V_225 + V_3 + 4 ] ) ) ;
F_19 ( V_41 , V_226 , F_16 ( V_41 , V_226 ) | 0x18 ) ;
return 0 ;
}
static int F_69 ( struct V_15 * V_16 ,
struct V_5 * V_6 )
{
const T_1 V_227 [] = { 'H' , 'W' , 'S' , 'Q' } ;
const int V_228 = sizeof( V_227 ) ;
int V_223 ;
V_223 = F_46 ( V_6 -> V_1 , V_6 -> V_2 , V_227 , V_228 ) ;
if ( ! V_223 )
return 0 ;
return F_68 ( V_16 , V_6 , V_223 + V_228 , 0 ) ;
}
T_1 * F_70 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
const T_1 V_229 [] = {
0x00 , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0x00 } ;
T_2 V_120 = 0 ;
T_2 V_230 ;
int V_231 = V_232 ;
if ( V_6 -> V_30 . V_233 )
return V_6 -> V_30 . V_233 ;
while ( V_231 ) {
V_230 = F_46 ( & V_6 -> V_1 [ V_120 ] , V_231 ,
V_229 , 8 ) ;
if ( ! V_230 )
return NULL ;
V_120 += V_230 ;
if ( ! F_1 ( & V_6 -> V_1 [ V_120 ] , V_234 ) )
break;
V_231 -= V_120 ;
V_120 ++ ;
}
F_5 ( V_22 , L_55 ) ;
return V_6 -> V_30 . V_233 = & V_6 -> V_1 [ V_120 ] ;
}
static bool F_71 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_235 * V_6 = F_72 ( & V_22 -> V_41 ) ;
struct V_5 * V_111 = & V_22 -> V_28 ;
memset ( V_111 , 0 , sizeof( struct V_5 ) ) ;
F_73 ( & V_111 -> V_236 ) ;
V_111 -> V_16 = V_16 ;
V_111 -> V_1 = V_6 -> V_1 ;
V_111 -> V_2 = V_6 -> V_237 ;
V_111 -> V_12 = V_6 -> V_124 . V_238 ;
V_111 -> V_109 = V_6 -> V_124 . V_239 ;
if ( V_6 -> V_240 ) {
V_111 -> type = V_143 ;
V_111 -> V_120 = V_6 -> V_240 ;
return ! F_43 ( V_111 , V_111 -> V_120 + 6 ) ;
} else
if ( V_6 -> V_241 ) {
V_111 -> type = V_222 ;
V_111 -> V_120 = V_6 -> V_241 ;
return ! F_45 ( V_16 , V_111 , V_111 -> V_120 ) ;
}
return false ;
}
int
F_74 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_59 = 0 ;
V_6 -> V_242 . V_243 = 0 ;
if ( V_6 -> V_12 < 5 )
F_69 ( V_16 , V_6 ) ;
if ( V_6 -> V_244 ) {
V_6 -> V_30 . V_60 = 0 ;
V_6 -> V_30 . V_61 = false ;
}
return V_59 ;
}
static bool
F_75 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
unsigned V_93 ;
if ( V_22 -> V_41 . V_70 . V_71 >= V_72 )
return true ;
V_93 = F_76 ( V_16 , 0 , 0x06 ) ;
V_93 |= ( F_76 ( V_16 , 0 , 0x07 ) & 0x01 ) << 8 ;
V_93 |= ( F_76 ( V_16 , 0 , 0x07 ) & 0x20 ) << 4 ;
V_93 |= ( F_76 ( V_16 , 0 , 0x25 ) & 0x01 ) << 10 ;
V_93 |= ( F_76 ( V_16 , 0 , 0x41 ) & 0x01 ) << 11 ;
return ( V_93 != 0 ) ;
}
int
F_77 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_59 ;
if ( ! V_16 -> V_40 )
return 0 ;
if ( ! F_71 ( V_16 ) )
return - V_144 ;
V_59 = F_66 ( V_16 , V_6 ) ;
if ( V_59 )
return V_59 ;
if ( ! V_6 -> V_12 )
return 0 ;
V_6 -> V_244 = false ;
if ( ! F_75 ( V_16 ) ) {
F_5 ( V_22 , L_56
L_57 ) ;
V_6 -> V_244 = true ;
}
V_59 = F_74 ( V_16 ) ;
if ( V_59 )
return V_59 ;
if ( V_6 -> V_12 < 5 )
V_6 -> V_82 = F_76 ( V_16 , 0 , V_245 ) & 0x40 ;
if ( V_6 -> V_82 || V_6 -> V_12 >= 5 )
V_59 = F_23 ( V_16 , V_6 ) ;
V_6 -> V_244 = true ;
return 0 ;
}
void
F_78 ( struct V_15 * V_16 )
{
}
