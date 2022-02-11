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
( V_16 -> V_40 == 0x0179 || V_16 -> V_40 == 0x0189 ||
V_16 -> V_40 == 0x0329 ) )
F_12 ( V_16 , V_18 -> V_33 , 0 , 0x02 , 0x72 ) ;
#endif
return 0 ;
}
static int F_13 ( struct V_15 * V_16 , struct V_17 * V_18 , int V_19 , enum V_26 V_27 , int V_8 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
unsigned int V_41 = ( V_18 -> V_33 == 4 ) ? 1 : 0 ;
T_2 V_11 = 0 , V_7 ;
switch ( V_27 ) {
case V_42 :
return - V_43 ;
case V_44 :
case V_45 :
V_11 = F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_46 + 7 + V_41 * 2 ] ) ;
break;
case V_47 :
case V_38 :
V_11 = F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_46 + 11 + V_41 * 2 ] ) ;
break;
case V_39 :
V_7 = V_6 -> V_30 . V_46 + 15 ;
if ( V_18 -> V_33 == 4 )
V_7 += 8 ;
if ( V_18 -> V_48 . V_49 ) {
if ( V_6 -> V_30 . V_37 )
V_7 += 4 ;
if ( V_6 -> V_30 . V_50 )
V_7 += 2 ;
} else {
int V_51 = ( V_18 -> V_33 == 4 ) ? 4 : 1 ;
if ( V_6 -> V_30 . V_37 ) {
V_7 += 4 ;
V_51 <<= 1 ;
}
if ( V_6 -> V_30 . V_52 & V_51 )
V_7 += 2 ;
}
V_7 = F_3 ( V_6 -> V_1 [ V_7 ] ) ;
if ( ! V_7 ) {
F_14 ( V_22 , L_2 ) ;
return - V_53 ;
}
V_11 = F_2 ( V_6 , V_7 , V_8 ) ;
}
if ( ! V_11 ) {
F_14 ( V_22 , L_3 ) ;
return - V_53 ;
}
F_4 ( V_16 , V_11 , V_18 , V_19 , V_6 -> V_30 . V_37 ) ;
return 0 ;
}
int F_15 ( struct V_15 * V_16 , struct V_17 * V_18 , int V_19 , enum V_26 V_27 , int V_8 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_54 * V_55 = F_16 ( V_22 -> V_55 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_1 V_56 = V_6 -> V_1 [ V_6 -> V_30 . V_46 ] ;
T_3 V_57 , V_58 ;
int V_59 ;
if ( V_6 -> V_30 . V_60 == ( V_27 << 1 | V_19 ) || ! V_56 ||
( V_56 >= 0x30 && V_27 == V_42 ) )
return 0 ;
if ( ! V_6 -> V_30 . V_61 ) {
V_6 -> V_30 . V_61 = true ;
F_15 ( V_16 , V_18 , V_19 , V_42 , V_8 ) ;
}
if ( V_27 == V_45 && V_6 -> V_30 . V_62 )
F_15 ( V_16 , V_18 , V_19 , V_39 , V_8 ) ;
if ( V_27 == V_39 && V_6 -> V_30 . V_63 )
F_15 ( V_16 , V_18 , V_19 , V_38 , V_8 ) ;
F_5 ( V_22 , L_4 , V_27 ) ;
V_57 = F_17 ( V_55 , V_64 ) & 0x50000 ;
if ( V_56 < 0x30 )
V_59 = F_9 ( V_16 , V_18 , V_19 , V_27 ) ;
else
V_59 = F_13 ( V_16 , V_18 , V_19 , V_27 , V_8 ) ;
V_6 -> V_30 . V_60 = ( V_27 << 1 | V_19 ) ;
V_58 = F_18 ( V_16 , 0 , V_64 ) & ~ 0x50000 ;
F_19 ( V_16 , 0 , V_64 , V_58 | V_57 ) ;
F_20 ( V_55 , V_65 , 0 ) ;
return V_59 ;
}
static int F_21 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_66 * V_67 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_1 V_56 , V_68 , V_69 ;
memset ( V_67 , 0 , sizeof( struct V_66 ) ) ;
if ( V_6 -> V_30 . V_46 == 0x0 ) {
F_14 ( V_22 , L_5 ) ;
return - V_36 ;
}
V_56 = V_6 -> V_1 [ V_6 -> V_30 . V_46 ] ;
switch ( V_56 ) {
case 0x0a :
V_68 = 2 ;
V_69 = V_6 -> V_1 [ V_6 -> V_30 . V_46 + 1 ] ;
break;
case 0x30 :
V_68 = V_6 -> V_1 [ V_6 -> V_30 . V_46 + 1 ] ;
if ( V_68 < 0x1f ) {
F_14 ( V_22 , L_6 ) ;
return - V_36 ;
}
V_69 = V_6 -> V_1 [ V_6 -> V_30 . V_46 + 2 ] ;
break;
case 0x40 :
V_68 = V_6 -> V_1 [ V_6 -> V_30 . V_46 + 1 ] ;
if ( V_68 < 0x7 ) {
F_14 ( V_22 , L_6 ) ;
return - V_36 ;
}
V_69 = V_6 -> V_1 [ V_6 -> V_30 . V_46 + 2 ] ;
break;
default:
F_14 ( V_22 ,
L_7 ,
V_56 >> 4 , V_56 & 0xf ) ;
return - V_43 ;
}
V_67 -> V_56 = V_56 ;
V_67 -> V_68 = V_68 ;
V_67 -> V_69 = V_69 ;
return 0 ;
}
static int
F_22 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_54 * V_55 = F_23 ( V_16 ) ;
if ( V_6 -> V_12 < 5 && V_6 -> V_1 [ 0x48 ] & 0x4 )
return F_24 ( V_16 , 0 , 0xf ) & 0xf ;
if ( V_55 -> V_70 >= V_71 )
return ( F_17 ( V_55 , V_72 ) >> 24 ) & 0xf ;
else
return ( F_17 ( V_55 , V_72 ) >> 16 ) & 0xf ;
}
static int F_25 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_1 * V_73 ;
T_1 V_74 , V_68 = 0 , V_69 , V_75 = 0xf , V_76 ;
int V_59 , V_77 , V_78 ;
struct V_66 V_67 ;
if ( V_6 -> V_30 . V_79 == 0x0 ) {
#ifndef F_11
F_14 ( V_22 , L_8 ) ;
#endif
V_6 -> V_80 = 0x4b ;
return 0 ;
}
V_73 = & V_6 -> V_1 [ V_6 -> V_30 . V_79 ] ;
V_74 = V_73 [ 0 ] ;
switch ( V_74 ) {
case 0x05 :
V_69 = 42 ;
V_77 = - 1 ;
break;
case 0x10 :
V_69 = 44 ;
V_77 = 0 ;
break;
case 0x20 :
V_68 = V_73 [ 1 ] ;
V_69 = V_73 [ 2 ] ;
V_75 = V_73 [ 3 ] ;
V_6 -> V_80 = V_73 [ 4 ] ;
V_77 = - 7 ;
break;
default:
F_14 ( V_22 ,
L_9 ,
V_74 >> 4 , V_74 & 0xf ) ;
return - V_43 ;
}
if ( ! V_6 -> V_81 )
return 0 ;
V_59 = F_21 ( V_16 , V_6 , & V_67 ) ;
if ( V_59 )
return V_59 ;
if ( V_67 . V_56 == 0x30 || V_67 . V_56 == 0x40 ) {
V_6 -> V_30 . V_82 = V_6 -> V_30 . V_46 +
V_67 . V_68 + 1 ;
V_6 -> V_30 . V_83 = V_67 . V_69 ;
}
if ( V_6 -> V_30 . V_82 == 0x0 ) {
F_14 ( V_22 , L_10 ) ;
return - V_36 ;
}
V_78 = F_22 ( V_16 , V_6 ) ;
V_76 = V_6 -> V_1 [ V_6 -> V_30 . V_82 +
V_78 * V_6 -> V_30 . V_83 ] ;
if ( V_76 > V_75 ) {
F_14 ( V_22 , L_11 ) ;
return - V_53 ;
}
if ( V_67 . V_56 > 0x10 )
V_6 -> V_84 = V_78 != 0xf || V_76 != 0xf ;
if ( V_78 == 0xf || V_76 == 0xf )
return 0 ;
V_6 -> V_30 . V_85 = V_6 -> V_30 . V_79 + V_68 +
V_69 * V_76 + V_77 ;
F_5 ( V_22 , L_12 ,
F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_85 + 11 ] ) + 1 ,
F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_85 + 25 ] ) + 1 ,
F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_85 + 7 ] ) * 10 ) ;
return 0 ;
}
bool F_26 ( struct V_15 * V_16 , struct V_86 * V_87 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_1 * V_88 = & V_6 -> V_1 [ V_6 -> V_30 . V_85 ] ;
if ( ! V_87 )
return V_6 -> V_30 . V_85 ;
memset ( V_87 , 0 , sizeof( struct V_86 ) ) ;
V_87 -> clock = F_3 ( V_88 [ 7 ] ) * 10 ;
V_87 -> V_89 = F_3 ( V_88 [ 11 ] ) + 1 ;
V_87 -> V_90 = F_3 ( V_88 [ 17 ] ) + 1 ;
V_87 -> V_91 = F_3 ( V_88 [ 19 ] ) + 1 ;
V_87 -> V_92 = F_3 ( V_88 [ 21 ] ) + 1 ;
V_87 -> V_93 = F_3 ( V_88 [ 25 ] ) + 1 ;
V_87 -> V_94 = F_3 ( V_88 [ 31 ] ) + 1 ;
V_87 -> V_95 = F_3 ( V_88 [ 33 ] ) + 1 ;
V_87 -> V_96 = F_3 ( V_88 [ 35 ] ) + 1 ;
V_87 -> V_97 |= ( V_88 [ 37 ] & 0x10 ) ?
V_98 : V_99 ;
V_87 -> V_97 |= ( V_88 [ 37 ] & 0x1 ) ?
V_100 : V_101 ;
V_87 -> V_102 = V_103 ;
V_87 -> type = V_104 | V_105 ;
F_27 ( V_87 ) ;
return V_6 -> V_30 . V_85 ;
}
int F_28 ( struct V_15 * V_16 , int V_8 , bool * V_20 , bool * V_50 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_78 = F_22 ( V_16 , V_6 ) , V_106 = 0 ;
struct V_66 V_67 ;
T_2 V_107 ;
int V_59 , V_108 = V_6 -> V_108 ;
V_59 = F_21 ( V_16 , V_6 , & V_67 ) ;
if ( V_59 )
return V_59 ;
switch ( V_67 . V_56 ) {
case 0x0a :
V_106 = V_6 -> V_1 [
V_6 -> V_30 . V_109 +
V_78 ] ;
if ( ! V_8 )
break;
if ( V_108 < 0x25 ) {
V_106 =
( V_6 -> V_110 . V_111 & 1 ) ?
2 : 0 ;
if ( V_8 >= V_6 -> V_30 . V_112 )
V_106 ++ ;
} else if ( V_108 < 0x30 ) {
V_106 = 0 ;
} else {
V_106 = 0 ;
if ( V_8 >= V_6 -> V_30 . V_112 )
V_106 = 2 ;
if ( V_8 >= 140000 )
V_106 = 3 ;
}
break;
case 0x30 :
case 0x40 :
V_106 = V_78 ;
break;
default:
F_14 ( V_22 , L_13 ) ;
return - V_43 ;
}
V_107 = V_6 -> V_30 . V_31 = V_6 -> V_30 . V_46 + V_67 . V_68 + V_67 . V_69 * V_106 ;
switch ( V_67 . V_56 ) {
case 0x0a :
V_6 -> V_30 . V_63 = V_6 -> V_1 [ V_107 ] & 1 ;
V_6 -> V_30 . V_62 = V_6 -> V_1 [ V_107 ] & 2 ;
V_6 -> V_30 . V_37 = V_6 -> V_1 [ V_107 ] & 4 ;
V_6 -> V_30 . V_32 = V_6 -> V_1 [ V_107 ] & 8 ;
* V_50 = V_6 -> V_1 [ V_107 ] & 16 ;
break;
case 0x30 :
case 0x40 :
V_6 -> V_30 . V_63 = true ;
V_6 -> V_30 . V_62 = true ;
V_6 -> V_30 . V_37 = V_6 -> V_1 [ V_107 ] & 1 ;
V_6 -> V_30 . V_50 = V_6 -> V_1 [ V_107 ] & 2 ;
V_6 -> V_30 . V_52 = V_6 -> V_1 [ V_6 -> V_30 . V_46 + 4 ] ;
V_6 -> V_30 . V_112 = F_3 ( V_6 -> V_1 [ V_6 -> V_30 . V_46 + 5 ] ) * 10 ;
break;
}
if ( V_8 && ( V_108 < 0x25 || V_108 > 0x28 ) )
V_6 -> V_30 . V_37 = ( V_8 >= V_6 -> V_30 . V_112 ) ;
* V_20 = V_6 -> V_30 . V_37 ;
return 0 ;
}
int F_29 ( struct V_15 * V_16 , struct V_17 * V_18 , int V_19 , int V_8 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_54 * V_55 = F_16 ( V_22 -> V_55 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_113 = V_6 -> V_108 ;
T_2 V_7 = 0 , V_11 ;
T_3 V_57 , V_58 ;
if ( V_113 >= 0x17 && V_113 != 0x1a && V_113 != 0x20 &&
V_18 -> V_114 != V_115 )
return 0 ;
switch ( F_30 ( V_18 -> V_33 ) ) {
case 1 :
V_7 = V_6 -> V_116 . V_117 ;
break;
case 2 :
case 3 :
V_7 = V_6 -> V_116 . V_118 ;
break;
}
if ( ! V_7 ) {
F_14 ( V_22 , L_2 ) ;
return - V_36 ;
}
V_11 = F_2 ( V_6 , V_7 , V_8 ) ;
if ( ! V_11 ) {
F_14 ( V_22 , L_14 ) ;
return - V_53 ;
}
V_57 = F_17 ( V_55 , V_64 ) & 0x50000 ;
F_4 ( V_16 , V_11 , V_18 , V_19 , V_8 >= 165000 ) ;
V_58 = F_18 ( V_16 , 0 , V_64 ) & ~ 0x50000 ;
F_19 ( V_16 , 0 , V_64 , V_58 | V_57 ) ;
return 0 ;
}
static void F_31 ( struct V_5 * V_6 , T_2 V_119 )
{
V_6 -> V_14 = F_3 ( V_6 -> V_1 [ V_119 ] ) ;
}
static int F_32 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_120 * V_121 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_122 ;
T_1 V_123 , V_68 , V_124 , V_125 ;
if ( V_121 -> V_2 != 3 ) {
F_14 ( V_22 , L_15 ) ;
return - V_36 ;
}
V_122 = F_3 ( V_6 -> V_1 [ V_121 -> V_119 ] ) ;
if ( V_122 == 0x0 ) {
F_33 ( V_22 , L_16 ) ;
return - V_36 ;
}
V_123 = V_6 -> V_1 [ V_122 ] ;
if ( V_123 != 0x10 ) {
F_14 ( V_22 , L_17 ,
V_123 >> 4 , V_123 & 0xF ) ;
return - V_43 ;
}
V_68 = V_6 -> V_1 [ V_122 + 1 ] ;
V_124 = V_6 -> V_1 [ V_122 + 2 ] ;
V_125 = V_6 -> V_1 [ V_122 + 3 ] ;
if ( V_68 != 4 || V_124 != 4 || V_125 != 2 ) {
F_14 ( V_22 , L_18 ) ;
return - V_36 ;
}
V_6 -> V_126 = F_34 ( V_6 -> V_1 [ V_122 + V_68 ] ) & 0x3ff ;
return 0 ;
}
static int F_35 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_120 * V_121 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_121 -> V_2 != 4 ) {
F_14 ( V_22 , L_19 ) ;
return - V_36 ;
}
V_6 -> V_30 . V_79 = F_3 ( V_6 -> V_1 [ V_121 -> V_119 + 2 ] ) ;
return 0 ;
}
static int F_36 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_120 * V_121 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_121 -> V_2 < 14 ) {
F_14 ( V_22 , L_20 ) ;
return - V_36 ;
}
F_31 ( V_6 , V_121 -> V_119 ) ;
return 0 ;
}
static int F_37 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_120 * V_121 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_127 ;
T_1 V_128 , V_129 ;
if ( V_121 -> V_2 < 6 ) {
F_14 ( V_22 , L_21 ) ;
return - V_36 ;
}
V_6 -> V_130 = V_6 -> V_1 [ V_121 -> V_119 + 5 ] ;
V_6 -> V_81 = V_6 -> V_130 & V_131 ;
if ( V_121 -> V_2 < 15 ) {
F_38 ( V_22 , L_22
L_23 ) ;
return - V_36 ;
}
V_127 = F_3 ( V_6 -> V_1 [ V_121 -> V_119 + 13 ] ) ;
if ( ! V_127 )
return 0 ;
V_128 = V_6 -> V_1 [ V_127 ] ;
V_129 = V_6 -> V_1 [ V_127 + 1 ] ;
if ( V_128 != 0x00 && V_128 != 0x10 ) {
F_38 ( V_22 , L_24
L_25 , V_128 >> 4 , V_128 & 0xf ) ;
return - V_43 ;
}
V_6 -> V_126 = F_34 ( V_6 -> V_1 [ V_127 + V_129 ] ) ;
V_6 -> V_132 = F_34 ( V_6 -> V_1 [ V_127 + V_129 + 4 ] ) ;
return 0 ;
}
static int F_39 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_120 * V_121 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_121 -> V_2 != 2 ) {
F_14 ( V_22 , L_26 ) ;
return - V_36 ;
}
V_6 -> V_30 . V_46 = F_3 ( V_6 -> V_1 [ V_121 -> V_119 ] ) ;
return 0 ;
}
static int
F_40 ( struct V_15 * V_16 , struct V_5 * V_6 ,
struct V_120 * V_121 )
{
if ( V_121 -> V_2 < 0x5 )
return 0 ;
if ( V_121 -> V_123 < 2 ) {
V_6 -> V_133 = V_6 -> V_1 [ V_121 -> V_119 + 2 ] ;
V_6 -> V_134 = F_3 ( V_6 -> V_1 [ V_121 -> V_119 + 3 ] ) ;
} else {
V_6 -> V_133 = V_6 -> V_1 [ V_121 -> V_119 + 0 ] ;
V_6 -> V_134 = F_3 ( V_6 -> V_1 [ V_121 -> V_119 + 1 ] ) ;
}
return 0 ;
}
static int F_41 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_120 * V_121 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_135 , V_136 , V_137 ;
if ( V_121 -> V_2 != 2 ) {
F_14 ( V_22 , L_27 ) ;
return - V_36 ;
}
V_135 = F_3 ( V_6 -> V_1 [ V_121 -> V_119 ] ) ;
if ( ! V_135 ) {
F_14 ( V_22 , L_28 ) ;
return - V_36 ;
}
F_5 ( V_22 , L_29 ,
V_6 -> V_1 [ V_135 ] >> 4 , V_6 -> V_1 [ V_135 ] & 0xf ) ;
if ( V_6 -> V_1 [ V_135 ] != 0x11 )
return - V_43 ;
V_136 = F_3 ( V_6 -> V_1 [ V_135 + 7 ] ) ;
V_137 = F_3 ( V_6 -> V_1 [ V_135 + 9 ] ) ;
if ( V_6 -> V_1 [ V_136 ] != 'q' || V_6 -> V_1 [ V_137 ] != 'q' )
F_38 ( V_22 , L_30 ) ;
V_6 -> V_116 . V_117 = F_3 ( V_6 -> V_1 [ V_135 + 11 ] ) ;
V_6 -> V_116 . V_118 = F_3 ( V_6 -> V_1 [ V_135 + 13 ] ) ;
return 0 ;
}
int
F_42 ( struct V_15 * V_16 , T_4 V_138 , struct V_120 * V_139 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_4 V_140 , * V_141 ;
if ( V_6 -> type != V_142 )
return - V_143 ;
V_140 = V_6 -> V_1 [ V_6 -> V_119 + 10 ] ;
V_141 = & V_6 -> V_1 [ V_6 -> V_119 + 12 ] ;
while ( V_140 -- ) {
if ( V_141 [ 0 ] == V_138 ) {
V_139 -> V_138 = V_141 [ 0 ] ;
V_139 -> V_123 = V_141 [ 1 ] ;
V_139 -> V_2 = F_3 ( V_141 [ 2 ] ) ;
V_139 -> V_119 = F_3 ( V_141 [ 4 ] ) ;
V_139 -> V_1 = F_43 ( V_16 , V_141 [ 4 ] ) ;
return 0 ;
}
V_141 += V_6 -> V_1 [ V_6 -> V_119 + 9 ] ;
}
return - V_53 ;
}
static int
F_44 ( struct V_5 * V_6 , const T_2 V_144 ,
struct F_42 * V_145 )
{
struct V_15 * V_16 = V_6 -> V_16 ;
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_120 V_121 ;
if ( F_42 ( V_16 , V_145 -> V_138 , & V_121 ) == 0 )
return V_145 -> V_146 ( V_16 , V_6 , & V_121 ) ;
F_5 ( V_22 , L_31 , V_145 -> V_138 ) ;
return - V_43 ;
}
static int
F_45 ( struct V_5 * V_6 , const T_2 V_144 )
{
int V_59 ;
V_59 = F_44 ( V_6 , V_144 , & F_46 ( 'i' , V_3 ) ) ;
if ( V_59 )
return V_59 ;
if ( V_6 -> V_12 >= 0x60 )
F_44 ( V_6 , V_144 , & F_46 ( 'A' , V_147 ) ) ;
F_44 ( V_6 , V_144 , & F_46 ( 'D' , V_148 ) ) ;
V_59 = F_44 ( V_6 , V_144 , & F_46 ( 'I' , V_149 ) ) ;
if ( V_59 )
return V_59 ;
F_44 ( V_6 , V_144 , & F_46 ( 'M' , V_150 ) ) ;
F_44 ( V_6 , V_144 , & F_46 ( 'L' , V_151 ) ) ;
F_44 ( V_6 , V_144 , & F_46 ( 'T' , V_116 ) ) ;
return 0 ;
}
static int F_47 ( struct V_15 * V_16 , struct V_5 * V_6 , unsigned int V_119 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_1 * V_152 = & V_6 -> V_1 [ V_119 ] , V_153 , V_154 ;
T_2 V_155 ;
T_2 V_156 , V_157 ;
V_6 -> V_80 = 0x4b ;
V_6 -> V_158 = 256000 ;
V_6 -> V_159 = 128000 ;
V_6 -> V_30 . V_112 = 90000 ;
V_153 = V_152 [ 5 ] ;
V_154 = V_152 [ 6 ] ;
F_5 ( V_22 , L_32 ,
V_153 , V_154 ) ;
if ( V_153 < 5 )
* ( T_2 * ) & V_6 -> V_1 [ 0x36 ] = 0 ;
if ( ( V_153 < 5 && V_154 != 1 ) || V_153 > 5 ) {
F_14 ( V_22 , L_33
L_34 ) ;
return - V_43 ;
}
if ( V_153 == 0 )
return 0 ;
else if ( V_153 == 1 )
V_155 = 44 ;
else if ( V_153 == 2 )
V_155 = 48 ;
else if ( V_153 == 3 )
V_155 = 54 ;
else if ( V_153 == 4 || V_154 < 0x1 )
V_155 = 62 ;
else if ( V_154 < 0x6 )
V_155 = 67 ;
else if ( V_154 < 0x10 )
V_155 = 75 ;
else if ( V_154 == 0x10 )
V_155 = 89 ;
else if ( V_154 < 0x14 )
V_155 = 118 ;
else if ( V_154 < 0x24 )
V_155 = 123 ;
else if ( V_154 < 0x27 )
V_155 = 144 ;
else
V_155 = 158 ;
if ( F_1 ( V_152 , 8 ) ) {
F_14 ( V_22 , L_35 ) ;
return - V_36 ;
}
V_6 -> V_130 = V_152 [ 9 ] ;
if ( V_153 < 5 || V_154 < 0x10 )
V_6 -> V_160 = true ;
V_156 = 18 ;
if ( V_153 < 2 )
V_156 -= 4 ;
V_6 -> V_14 = F_3 ( V_152 [ V_156 ] ) ;
V_6 -> V_161 = F_3 ( V_152 [ V_156 + 2 ] ) ;
if ( V_153 > 2 ) {
V_6 -> V_110 . V_162 = F_3 ( V_152 [ 24 ] ) ;
V_6 -> V_110 . V_163 = F_3 ( V_152 [ 26 ] ) ;
V_6 -> V_110 . V_164 = F_3 ( V_152 [ 28 ] ) ;
}
V_157 = 0x48 ;
if ( V_155 > 61 )
V_157 = V_119 + 54 ;
V_6 -> V_110 . V_165 . V_166 = V_6 -> V_1 [ V_157 ] ;
V_6 -> V_110 . V_165 . V_167 = V_6 -> V_1 [ V_157 + 1 ] ;
V_6 -> V_110 . V_165 . V_168 = V_6 -> V_1 [ V_157 + 2 ] ;
if ( V_155 > 74 ) {
V_6 -> V_158 = F_34 ( V_152 [ 67 ] ) ;
V_6 -> V_159 = F_34 ( V_152 [ 71 ] ) ;
}
if ( V_155 > 88 )
F_31 ( V_6 , V_119 + 75 ) ;
if ( V_155 > 94 ) {
V_6 -> V_116 . V_117 = F_3 ( V_152 [ 89 ] ) ;
V_6 -> V_116 . V_118 = F_3 ( V_152 [ 91 ] ) ;
V_6 -> V_110 . V_111 = F_3 ( V_152 [ 95 ] ) ;
}
if ( V_155 > 108 ) {
V_6 -> V_30 . V_79 = F_3 ( V_152 [ 105 ] ) ;
V_6 -> V_30 . V_82 = F_3 ( V_152 [ 107 ] ) ;
V_6 -> V_30 . V_83 = 1 ;
}
if ( V_155 > 120 ) {
V_6 -> V_30 . V_46 = F_3 ( V_152 [ 117 ] ) ;
V_6 -> V_30 . V_109 = F_3 ( V_152 [ 119 ] ) ;
}
#if 0
if (bmplength > 143)
bios->pll_limit_tbl_ptr = ROM16(bmp[142]);
#endif
if ( V_155 > 157 )
V_6 -> V_30 . V_112 = F_3 ( V_152 [ 156 ] ) * 10 ;
return 0 ;
}
static T_2 F_48 ( T_1 * V_1 , int V_169 , const T_1 * V_170 , int V_171 )
{
int V_3 , V_172 ;
for ( V_3 = 0 ; V_3 <= ( V_169 - V_171 ) ; V_3 ++ ) {
for ( V_172 = 0 ; V_172 < V_171 ; V_172 ++ )
if ( V_1 [ V_3 + V_172 ] != V_170 [ V_172 ] )
break;
if ( V_172 == V_171 )
return V_3 ;
}
return 0 ;
}
void *
F_49 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_4 * V_173 = NULL ;
if ( F_16 ( V_22 -> V_55 ) -> V_70 > V_174 )
V_173 = F_43 ( V_16 , V_22 -> V_28 . V_1 [ 0x36 ] ) ;
if ( ! V_173 ) {
F_38 ( V_22 , L_36 ) ;
return NULL ;
}
if ( V_173 [ 0 ] >= 0x41 ) {
F_38 ( V_22 , L_37 , V_173 [ 0 ] ) ;
return NULL ;
} else
if ( V_173 [ 0 ] >= 0x30 ) {
if ( F_34 ( V_173 [ 6 ] ) == 0x4edcbdcb )
return V_173 ;
} else
if ( V_173 [ 0 ] >= 0x20 ) {
if ( F_34 ( V_173 [ 4 ] ) == 0x4edcbdcb )
return V_173 ;
} else
if ( V_173 [ 0 ] >= 0x15 ) {
if ( ! memcmp ( & V_173 [ - 7 ] , L_38 , 7 ) )
return V_173 ;
} else {
F_38 ( V_22 , L_39 ) ;
return NULL ;
}
F_38 ( V_22 , L_40 ) ;
return NULL ;
}
void *
F_50 ( struct V_15 * V_16 , T_4 V_175 )
{
T_4 * V_173 = F_49 ( V_16 ) ;
if ( V_173 && V_173 [ 0 ] >= 0x30 ) {
if ( V_175 < V_173 [ 2 ] )
return V_173 + V_173 [ 1 ] + ( V_175 * V_173 [ 3 ] ) ;
} else
if ( V_173 && V_173 [ 0 ] >= 0x20 ) {
T_4 * V_176 = F_43 ( V_16 , V_173 [ 2 ] ) ;
T_4 * V_177 = V_173 + 8 + ( V_175 * 8 ) ;
if ( V_176 && V_177 < V_176 )
return V_177 ;
} else
if ( V_173 && V_173 [ 0 ] >= 0x15 ) {
T_4 * V_176 = F_43 ( V_16 , V_173 [ 2 ] ) ;
T_4 * V_177 = V_173 + 4 + ( V_175 * 10 ) ;
if ( V_176 && V_177 < V_176 )
return V_177 ;
}
return NULL ;
}
int
F_51 ( struct V_15 * V_16 , void * V_1 ,
int (* F_52)( struct V_15 * , void * , int V_175 , T_4 * V_178 ) )
{
int V_59 , V_175 = - 1 ;
T_4 * V_178 = NULL ;
while ( ( V_178 = F_50 ( V_16 , ++ V_175 ) ) ) {
if ( F_34 ( V_178 [ 0 ] ) == 0x00000000 )
break;
if ( F_34 ( V_178 [ 0 ] ) == 0xffffffff )
break;
if ( ( V_178 [ 0 ] & 0x0f ) == V_179 )
continue;
if ( ( V_178 [ 0 ] & 0x0f ) == V_180 )
break;
V_59 = F_52 ( V_16 , V_1 , V_175 , V_178 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
T_4 *
F_53 ( struct V_15 * V_16 )
{
T_4 * V_173 = F_49 ( V_16 ) ;
if ( V_173 && V_173 [ 0 ] >= 0x30 && V_173 [ 1 ] >= 0x16 ) {
T_4 * V_181 = F_43 ( V_16 , V_173 [ 0x14 ] ) ;
if ( V_181 && V_181 [ 0 ] >= 0x30 && V_181 [ 0 ] <= 0x40 )
return V_181 ;
}
return NULL ;
}
T_4 *
F_54 ( struct V_15 * V_16 , T_4 V_175 )
{
T_4 * V_181 = F_53 ( V_16 ) ;
if ( V_181 && V_175 < V_181 [ 2 ] )
return V_181 + V_181 [ 1 ] + ( V_175 * V_181 [ 3 ] ) ;
return NULL ;
}
static struct V_17 * F_55 ( struct V_182 * V_173 )
{
struct V_17 * V_141 = & V_173 -> V_141 [ V_173 -> V_140 ] ;
memset ( V_141 , 0 , sizeof( struct V_17 ) ) ;
V_141 -> V_183 = V_173 -> V_140 ++ ;
return V_141 ;
}
static void F_56 ( struct V_182 * V_173 , int type , int V_176 ,
int V_184 , int V_33 )
{
struct V_17 * V_141 = F_55 ( V_173 ) ;
V_141 -> type = type ;
V_141 -> V_185 = V_176 ;
V_141 -> V_184 = V_184 ;
if ( type != V_186 )
V_141 -> V_114 = ! V_115 ;
V_141 -> V_33 = V_33 ;
}
static bool
F_57 ( struct V_15 * V_16 , struct V_182 * V_173 ,
T_3 V_187 , T_3 V_188 , struct V_17 * V_141 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
V_141 -> type = V_187 & 0xf ;
V_141 -> V_185 = ( V_187 >> 4 ) & 0xf ;
V_141 -> V_184 = ( V_187 >> 8 ) & 0xf ;
V_141 -> V_189 = ( V_187 >> 12 ) & 0xf ;
V_141 -> V_190 = ( V_187 >> 16 ) & 0xf ;
V_141 -> V_114 = ( V_187 >> 20 ) & 0x3 ;
V_141 -> V_33 = ( V_187 >> 24 ) & 0xf ;
switch ( V_141 -> type ) {
case V_186 :
V_141 -> V_191 . V_192 = ( V_173 -> V_123 < 0x30 ) ?
( V_188 & 0xffff ) * 10 :
( V_188 & 0xff ) * 10000 ;
break;
case V_193 :
{
T_3 V_194 ;
if ( V_188 & 0x1 )
V_141 -> V_48 . V_49 = true ;
if ( V_173 -> V_123 < 0x22 ) {
V_194 = ~ 0xd ;
V_141 -> V_48 . V_49 = true ;
if ( V_188 & 0x4 || V_188 & 0x8 )
V_141 -> V_48 . V_195 = true ;
} else {
V_194 = ~ 0x7 ;
if ( V_188 & 0x2 )
V_141 -> V_48 . V_196 = true ;
if ( V_188 & 0x4 )
V_141 -> V_48 . V_195 = true ;
V_141 -> V_48 . V_197 . V_198 = ( V_188 & 0x00000030 ) >> 4 ;
}
if ( V_188 & V_194 ) {
if ( V_173 -> V_123 >= 0x40 )
break;
F_14 ( V_22 , L_41
L_42 ) ;
}
break;
}
case V_199 :
{
if ( V_173 -> V_123 >= 0x30 )
V_141 -> V_200 . V_201 = V_188 & ( 0x8 << 4 ) ;
else
V_141 -> V_200 . V_201 = false ;
break;
}
case V_202 :
V_141 -> V_203 . V_197 . V_198 = ( V_188 & 0x00000030 ) >> 4 ;
V_141 -> V_204 = ( V_188 & 0x0000ff00 ) >> 8 ;
switch ( ( V_188 & 0x00e00000 ) >> 21 ) {
case 0 :
V_141 -> V_203 . V_205 = 162000 ;
break;
default:
V_141 -> V_203 . V_205 = 270000 ;
break;
}
switch ( ( V_188 & 0x0f000000 ) >> 24 ) {
case 0xf :
V_141 -> V_203 . V_206 = 4 ;
break;
case 0x3 :
V_141 -> V_203 . V_206 = 2 ;
break;
default:
V_141 -> V_203 . V_206 = 1 ;
break;
}
break;
case V_207 :
if ( V_173 -> V_123 >= 0x40 ) {
V_141 -> V_208 . V_197 . V_198 = ( V_188 & 0x00000030 ) >> 4 ;
V_141 -> V_204 = ( V_188 & 0x0000ff00 ) >> 8 ;
}
else if ( V_173 -> V_123 >= 0x30 )
V_141 -> V_208 . V_209 = ( V_188 & 0x00000700 ) >> 8 ;
else if ( V_173 -> V_123 >= 0x22 )
V_141 -> V_208 . V_209 = ( V_188 & 0x00000070 ) >> 4 ;
break;
case V_180 :
V_173 -> V_140 -- ;
return false ;
default:
break;
}
if ( V_173 -> V_123 < 0x40 ) {
V_141 -> V_210 =
( ( 1 << ( F_30 ( V_141 -> V_33 ) - 1 ) ) * 3 == V_141 -> V_33 ) ;
} else {
V_141 -> V_210 = ( V_141 -> V_211 . V_198 == 3 ) ;
}
if ( V_188 & 0x100000 )
V_141 -> V_212 = true ;
return true ;
}
static bool
F_58 ( struct V_15 * V_16 , struct V_182 * V_173 ,
T_3 V_187 , T_3 V_188 , struct V_17 * V_141 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
switch ( V_187 & 0x0000000f ) {
case 0 :
V_141 -> type = V_186 ;
break;
case 1 :
V_141 -> type = V_199 ;
break;
case 2 :
case 4 :
if ( V_187 & 0x10 )
V_141 -> type = V_193 ;
else
V_141 -> type = V_207 ;
break;
case 3 :
V_141 -> type = V_193 ;
break;
default:
F_14 ( V_22 , L_43 , V_187 & 0x0000000f ) ;
return false ;
}
V_141 -> V_185 = ( V_187 & 0x0003c000 ) >> 14 ;
V_141 -> V_184 = ( ( V_187 & 0x001c0000 ) >> 18 ) + 1 ;
V_141 -> V_33 = V_141 -> V_184 ;
V_141 -> V_114 = ( V_187 & 0x01e00000 ) >> 21 ;
V_141 -> V_190 = ( V_187 & 0x0e000000 ) >> 25 ;
V_141 -> V_210 = false ;
switch ( V_141 -> type ) {
case V_186 :
V_141 -> V_191 . V_192 = ( V_188 & 0xffff ) * 10 ;
break;
case V_199 :
V_141 -> V_200 . V_201 = false ;
break;
case V_193 :
if ( ( V_187 & 0x00003f00 ) >> 8 != 0x10 )
V_141 -> V_48 . V_49 = true ;
V_141 -> V_48 . V_195 = true ;
break;
default:
break;
}
return true ;
}
static
void F_59 ( struct V_15 * V_16 , struct V_182 * V_173 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
int V_3 , V_213 = 0 ;
for ( V_3 = 0 ; V_3 < V_173 -> V_140 ; V_3 ++ ) {
struct V_17 * V_214 = & V_173 -> V_141 [ V_3 ] ;
int V_172 ;
for ( V_172 = V_3 + 1 ; V_172 < V_173 -> V_140 ; V_172 ++ ) {
struct V_17 * V_215 = & V_173 -> V_141 [ V_172 ] ;
if ( V_215 -> type == 100 )
continue;
if ( V_215 -> V_185 == V_214 -> V_185 &&
V_215 -> type == V_214 -> type &&
V_215 -> V_114 == V_214 -> V_114 &&
V_215 -> V_33 == V_214 -> V_33 ) {
F_5 ( V_22 , L_44 ,
V_3 , V_172 ) ;
V_214 -> V_184 |= V_215 -> V_184 ;
V_215 -> type = 100 ;
}
}
}
for ( V_3 = 0 ; V_3 < V_173 -> V_140 ; V_3 ++ ) {
if ( V_173 -> V_141 [ V_3 ] . type == 100 )
continue;
if ( V_213 != V_3 ) {
V_173 -> V_141 [ V_213 ] = V_173 -> V_141 [ V_3 ] ;
V_173 -> V_141 [ V_213 ] . V_183 = V_213 ;
}
V_213 ++ ;
}
V_173 -> V_140 = V_213 ;
}
static bool
F_60 ( struct V_15 * V_16 , int V_175 , T_5 * V_187 , T_5 * V_188 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_182 * V_173 = & V_22 -> V_28 . V_173 ;
if ( F_61 ( V_16 , 0x040d , 0x1028 , 0x019b ) ) {
if ( * V_187 == 0x02026312 && * V_188 == 0x00000020 )
return false ;
}
if ( F_61 ( V_16 , 0x0201 , 0x1462 , 0x8851 ) ) {
if ( * V_187 == 0xf2005014 && * V_188 == 0xffffffff ) {
F_56 ( V_173 , V_207 , 1 , 1 , 1 ) ;
return false ;
}
}
if ( F_61 ( V_16 , 0x0ca3 , 0x1682 , 0x3003 ) ) {
if ( V_175 == 0 ) {
* V_187 = 0x02001300 ;
* V_188 = 0x00000028 ;
} else
if ( V_175 == 1 ) {
* V_187 = 0x01010312 ;
* V_188 = 0x00020030 ;
} else
if ( V_175 == 2 ) {
* V_187 = 0x01010310 ;
* V_188 = 0x00000028 ;
} else
if ( V_175 == 3 ) {
* V_187 = 0x02022362 ;
* V_188 = 0x00020010 ;
} else {
* V_187 = 0x0000000e ;
* V_188 = 0x00000000 ;
}
}
if ( F_61 ( V_16 , 0x0615 , 0x1682 , 0x2605 ) ) {
if ( V_175 == 0 ) {
* V_187 = 0x02002300 ;
* V_188 = 0x00000028 ;
} else
if ( V_175 == 1 ) {
* V_187 = 0x01010312 ;
* V_188 = 0x00020030 ;
} else
if ( V_175 == 2 ) {
* V_187 = 0x04020310 ;
* V_188 = 0x00000028 ;
} else
if ( V_175 == 3 ) {
* V_187 = 0x02021322 ;
* V_188 = 0x00020010 ;
} else {
* V_187 = 0x0000000e ;
* V_188 = 0x00000000 ;
}
}
if ( F_61 ( V_16 , 0x0421 , 0x3842 , 0xc793 ) ) {
if ( V_175 == 0 && * V_187 == 0x02000300 )
* V_187 = 0x02011300 ;
else
if ( V_175 == 1 && * V_187 == 0x04011310 )
* V_187 = 0x04000310 ;
else
if ( V_175 == 2 && * V_187 == 0x02011312 )
* V_187 = 0x02000312 ;
}
return true ;
}
static void
F_62 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_182 * V_173 = & V_6 -> V_173 ;
int V_216 = ( F_63 ( V_16 ) ? 3 : 1 ) ;
#ifdef F_11
if ( F_64 ( L_45 ) ) {
F_56 ( V_173 , V_207 , 0 , V_216 , 1 ) ;
F_56 ( V_173 , V_186 , 1 , V_216 , 2 ) ;
return;
}
#endif
F_56 ( V_173 , V_186 ,
V_6 -> V_110 . V_165 . V_166 , 1 , 1 ) ;
if ( F_65 ( V_16 , V_6 -> V_110 . V_165 . V_167 ) >= 0 )
F_56 ( V_173 , V_199 ,
V_6 -> V_110 . V_165 . V_167 ,
V_216 , 0 ) ;
else if ( V_6 -> V_116 . V_117 ||
V_6 -> V_116 . V_118 )
F_56 ( V_173 , V_207 ,
V_6 -> V_110 . V_165 . V_168 ,
V_216 , 1 ) ;
}
static int
F_66 ( struct V_15 * V_16 , void * V_1 , int V_175 , T_4 * V_178 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_182 * V_173 = & V_22 -> V_28 . V_173 ;
T_5 V_188 = ( V_173 -> V_123 >= 0x20 ) ? F_34 ( V_178 [ 4 ] ) : F_34 ( V_178 [ 6 ] ) ;
T_5 V_187 = F_34 ( V_178 [ 0 ] ) ;
bool V_59 ;
if ( F_60 ( V_16 , V_175 , & V_187 , & V_188 ) ) {
struct V_17 * V_141 = F_55 ( V_173 ) ;
F_5 ( V_22 , L_46 , V_175 , V_187 , V_188 ) ;
if ( V_173 -> V_123 >= 0x20 )
V_59 = F_57 ( V_16 , V_173 , V_187 , V_188 , V_141 ) ;
else
V_59 = F_58 ( V_16 , V_173 , V_187 , V_188 , V_141 ) ;
if ( ! V_59 )
return 1 ;
if ( V_141 -> type == V_199 &&
V_141 -> V_114 == V_115 )
V_141 -> V_185 = 0x0f ;
}
return 0 ;
}
static void
F_67 ( struct V_5 * V_6 )
{
struct V_182 * V_217 = & V_6 -> V_173 ;
T_4 V_218 [ 16 ] = { } ;
int V_3 , V_175 = 0 ;
if ( ! F_61 ( V_6 -> V_16 , 0x0392 , 0x107d , 0x20a2 ) ) {
for ( V_3 = 0 ; V_3 < V_217 -> V_140 ; V_3 ++ ) {
if ( V_217 -> V_141 [ V_3 ] . V_189 )
return;
}
}
for ( V_3 = 0 ; V_3 < V_217 -> V_140 ; V_3 ++ ) {
T_4 V_176 = V_217 -> V_141 [ V_3 ] . V_185 ;
if ( V_176 == 0x0f ) {
V_217 -> V_141 [ V_3 ] . V_189 = V_175 ++ ;
} else {
if ( ! V_218 [ V_176 ] )
V_218 [ V_176 ] = ++ V_175 ;
V_217 -> V_141 [ V_3 ] . V_189 = V_218 [ V_176 ] - 1 ;
}
}
if ( V_3 > 1 ) {
T_4 * V_181 = F_53 ( V_6 -> V_16 ) ;
if ( V_181 )
V_181 [ 0 ] = 0x00 ;
}
}
static int
F_68 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_182 * V_173 = & V_6 -> V_173 ;
T_4 * V_217 , * V_187 ;
int V_175 ;
V_217 = F_49 ( V_16 ) ;
if ( ! V_217 ) {
if ( V_6 -> type == V_219 ) {
F_62 ( V_16 , V_6 ) ;
return 0 ;
}
return - V_36 ;
}
F_5 ( V_22 , L_47 , V_217 [ 0 ] >> 4 , V_217 [ 0 ] & 0xf ) ;
V_173 -> V_123 = V_217 [ 0 ] ;
F_51 ( V_16 , NULL , F_66 ) ;
if ( V_173 -> V_123 < 0x21 )
F_59 ( V_16 , V_173 ) ;
V_175 = - 1 ;
while ( ( V_187 = F_54 ( V_16 , ++ V_175 ) ) ) {
if ( V_187 [ 0 ] != 0xff ) {
F_5 ( V_22 , L_48 , V_175 ) ;
if ( F_53 ( V_16 ) [ 3 ] < 4 )
F_69 ( L_49 , F_3 ( V_187 [ 0 ] ) ) ;
else
F_69 ( L_50 , F_34 ( V_187 [ 0 ] ) ) ;
}
}
F_67 ( V_6 ) ;
return 0 ;
}
static int F_70 ( struct V_15 * V_16 , struct V_5 * V_6 , T_2 V_220 , int V_141 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_54 * V_55 = F_16 ( V_22 -> V_55 ) ;
T_1 V_221 ;
T_2 V_222 ;
int V_3 ;
if ( V_6 -> V_1 [ V_220 ] <= V_141 ) {
F_14 ( V_22 , L_51
L_52 ) ;
return - V_53 ;
}
V_221 = V_6 -> V_1 [ V_220 + 1 ] ;
if ( V_221 != 36 ) {
F_14 ( V_22 , L_53 ) ;
return - V_36 ;
}
F_5 ( V_22 , L_54 ) ;
V_222 = V_220 + 2 + V_141 * V_221 ;
F_20 ( V_55 , 0x00001304 , F_34 ( V_6 -> V_1 [ V_222 ] ) ) ;
V_221 -= 4 ;
for ( V_3 = 0 ; V_3 < V_221 ; V_3 += 4 )
F_20 ( V_55 , 0x00001400 + V_3 , F_34 ( V_6 -> V_1 [ V_222 + V_3 + 4 ] ) ) ;
F_20 ( V_55 , V_223 , F_17 ( V_55 , V_223 ) | 0x18 ) ;
return 0 ;
}
static int F_71 ( struct V_15 * V_16 ,
struct V_5 * V_6 )
{
const T_1 V_224 [] = { 'H' , 'W' , 'S' , 'Q' } ;
const int V_225 = sizeof( V_224 ) ;
int V_220 ;
V_220 = F_48 ( V_6 -> V_1 , V_6 -> V_2 , V_224 , V_225 ) ;
if ( ! V_220 )
return 0 ;
return F_70 ( V_16 , V_6 , V_220 + V_225 , 0 ) ;
}
T_1 * F_72 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
const T_1 V_226 [] = {
0x00 , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0x00 } ;
T_2 V_119 = 0 ;
T_2 V_227 ;
int V_228 = V_229 ;
if ( V_6 -> V_30 . V_230 )
return V_6 -> V_30 . V_230 ;
while ( V_228 ) {
V_227 = F_48 ( & V_6 -> V_1 [ V_119 ] , V_228 ,
V_226 , 8 ) ;
if ( ! V_227 )
return NULL ;
V_119 += V_227 ;
if ( ! F_1 ( & V_6 -> V_1 [ V_119 ] , V_231 ) )
break;
V_228 -= V_119 ;
V_119 ++ ;
}
F_5 ( V_22 , L_55 ) ;
return V_6 -> V_30 . V_230 = & V_6 -> V_1 [ V_119 ] ;
}
static bool F_73 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_232 * V_6 = V_232 ( V_22 -> V_55 ) ;
struct V_5 * V_110 = & V_22 -> V_28 ;
memset ( V_110 , 0 , sizeof( struct V_5 ) ) ;
F_74 ( & V_110 -> V_233 ) ;
V_110 -> V_16 = V_16 ;
V_110 -> V_1 = V_6 -> V_1 ;
V_110 -> V_2 = V_6 -> V_234 ;
V_110 -> V_12 = V_6 -> V_123 . V_235 ;
V_110 -> V_108 = V_6 -> V_123 . V_236 ;
if ( V_6 -> V_237 ) {
V_110 -> type = V_142 ;
V_110 -> V_119 = V_6 -> V_237 ;
return ! F_45 ( V_110 , V_110 -> V_119 + 6 ) ;
} else
if ( V_6 -> V_238 ) {
V_110 -> type = V_219 ;
V_110 -> V_119 = V_6 -> V_238 ;
return ! F_47 ( V_16 , V_110 , V_110 -> V_119 ) ;
}
return false ;
}
int
F_75 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_59 = 0 ;
V_6 -> V_239 . V_240 = 0 ;
if ( V_6 -> V_12 < 5 )
F_71 ( V_16 , V_6 ) ;
if ( V_6 -> V_241 ) {
V_6 -> V_30 . V_60 = 0 ;
V_6 -> V_30 . V_61 = false ;
}
return V_59 ;
}
static bool
F_76 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
unsigned V_92 ;
if ( F_16 ( V_22 -> V_55 ) -> V_70 >= V_71 )
return true ;
V_92 = F_77 ( V_16 , 0 , 0x06 ) ;
V_92 |= ( F_77 ( V_16 , 0 , 0x07 ) & 0x01 ) << 8 ;
V_92 |= ( F_77 ( V_16 , 0 , 0x07 ) & 0x20 ) << 4 ;
V_92 |= ( F_77 ( V_16 , 0 , 0x25 ) & 0x01 ) << 10 ;
V_92 |= ( F_77 ( V_16 , 0 , 0x41 ) & 0x01 ) << 11 ;
return ( V_92 != 0 ) ;
}
int
F_78 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_59 ;
if ( ! F_73 ( V_16 ) )
return - V_143 ;
V_59 = F_68 ( V_16 , V_6 ) ;
if ( V_59 )
return V_59 ;
if ( ! V_6 -> V_12 )
return 0 ;
V_6 -> V_241 = false ;
if ( ! F_76 ( V_16 ) ) {
F_5 ( V_22 , L_56
L_57 ) ;
V_6 -> V_241 = true ;
}
V_59 = F_75 ( V_16 ) ;
if ( V_59 )
return V_59 ;
if ( V_6 -> V_12 < 5 )
V_6 -> V_81 = F_77 ( V_16 , 0 , V_242 ) & 0x40 ;
if ( V_6 -> V_81 || V_6 -> V_12 >= 5 )
V_59 = F_25 ( V_16 , V_6 ) ;
V_6 -> V_241 = true ;
return 0 ;
}
void
F_79 ( struct V_15 * V_16 )
{
}
