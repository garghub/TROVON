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
bool
F_29 ( struct V_17 * V_113 , T_4 V_114 )
{
if ( ( V_114 & 0x000000f0 ) != ( V_113 -> V_115 << 4 ) )
return false ;
if ( ( V_114 & 0x0000000f ) != V_113 -> type )
return false ;
if ( ! ( V_114 & ( V_113 -> V_33 << 16 ) ) )
return false ;
switch ( V_113 -> type ) {
case V_116 :
case V_117 :
case V_118 :
if ( V_114 & 0x00c00000 ) {
if ( ! ( V_114 & ( V_113 -> V_119 . V_120 << 22 ) ) )
return false ;
}
default:
return true ;
}
}
int
F_30 ( struct V_15 * V_16 , T_5 type , int V_121 ,
struct V_17 * V_18 , int V_122 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_1 * V_123 = & V_6 -> V_1 [ V_6 -> V_124 . V_125 ] ;
T_1 * V_126 = NULL ;
T_2 V_27 ;
int V_3 ;
if ( ! V_6 -> V_124 . V_125 ) {
F_14 ( V_22 , L_14 ) ;
return 1 ;
}
if ( V_123 [ 0 ] < 0x20 )
return 1 ;
if ( V_123 [ 0 ] != 0x20 && V_123 [ 0 ] != 0x21 ) {
F_14 ( V_22 , L_15 ,
V_123 [ 0 ] ) ;
return 1 ;
}
F_31 ( V_22 , L_16 ,
V_18 -> type , V_18 -> V_115 , V_18 -> V_33 ) ;
for ( V_3 = 0 ; V_3 < V_123 [ 3 ] ; V_3 ++ ) {
V_126 = F_32 ( V_16 , V_123 [ V_123 [ 1 ] + ( V_3 * V_123 [ 2 ] ) ] ) ;
if ( V_126 && F_29 ( V_18 , F_33 ( V_126 [ 0 ] ) ) )
break;
}
if ( ! V_126 ) {
F_31 ( V_22 , L_17 ) ;
return 1 ;
}
if ( V_121 < - 2 || V_121 > 0 ) {
for ( V_3 = 0 ; V_3 < V_126 [ 5 ] ; V_3 ++ ) {
if ( F_3 ( V_126 [ V_123 [ 4 ] + V_3 * 6 ] ) == type )
break;
}
if ( V_3 == V_126 [ 5 ] ) {
F_14 ( V_22 , L_18
L_19 ,
type , V_18 -> type , V_18 -> V_33 ) ;
V_3 = 0 ;
}
}
if ( V_121 == 0 ) {
V_27 = F_3 ( V_126 [ 6 ] ) ;
if ( ! V_27 ) {
F_31 ( V_22 , L_20 ) ;
return 1 ;
}
F_31 ( V_22 , L_21 , V_27 ) ;
F_7 ( V_16 , V_27 , V_18 , V_122 ) ;
} else
if ( V_121 == - 1 ) {
V_27 = F_3 ( V_126 [ 8 ] ) ;
if ( ! V_27 ) {
F_31 ( V_22 , L_22 ) ;
return 1 ;
}
F_31 ( V_22 , L_23 , V_27 ) ;
F_7 ( V_16 , V_27 , V_18 , V_122 ) ;
} else
if ( V_121 == - 2 ) {
if ( V_123 [ 4 ] >= 12 )
V_27 = F_3 ( V_126 [ 10 ] ) ;
else
V_27 = 0 ;
if ( ! V_27 ) {
F_31 ( V_22 , L_24 ) ;
return 1 ;
}
F_31 ( V_22 , L_25 , V_27 ) ;
F_7 ( V_16 , V_27 , V_18 , V_122 ) ;
} else
if ( V_121 > 0 ) {
V_27 = F_3 ( V_126 [ V_123 [ 4 ] + V_3 * 6 + 2 ] ) ;
if ( V_27 )
V_27 = F_2 ( V_6 , V_27 , V_121 ) ;
if ( ! V_27 ) {
F_31 ( V_22 , L_26 ) ;
return 1 ;
}
F_31 ( V_22 , L_27 , V_27 ) ;
F_7 ( V_16 , V_27 , V_18 , V_122 ) ;
} else
if ( V_121 < 0 ) {
V_27 = F_3 ( V_126 [ V_123 [ 4 ] + V_3 * 6 + 4 ] ) ;
if ( V_27 )
V_27 = F_2 ( V_6 , V_27 , - V_121 ) ;
if ( ! V_27 ) {
F_31 ( V_22 , L_28 ) ;
return 1 ;
}
F_31 ( V_22 , L_29 , V_27 ) ;
F_7 ( V_16 , V_27 , V_18 , V_122 ) ;
}
return 0 ;
}
int F_34 ( struct V_15 * V_16 , struct V_17 * V_18 , int V_19 , int V_8 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_54 * V_55 = F_16 ( V_22 -> V_55 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_127 = V_6 -> V_108 ;
T_2 V_7 = 0 , V_11 ;
T_3 V_57 , V_58 ;
if ( V_127 >= 0x17 && V_127 != 0x1a && V_127 != 0x20 &&
V_18 -> V_115 != V_128 )
return 0 ;
switch ( F_35 ( V_18 -> V_33 ) ) {
case 1 :
V_7 = V_6 -> V_129 . V_130 ;
break;
case 2 :
case 3 :
V_7 = V_6 -> V_129 . V_131 ;
break;
}
if ( ! V_7 ) {
F_14 ( V_22 , L_2 ) ;
return - V_36 ;
}
V_11 = F_2 ( V_6 , V_7 , V_8 ) ;
if ( ! V_11 ) {
F_14 ( V_22 , L_30 ) ;
return - V_53 ;
}
V_57 = F_17 ( V_55 , V_64 ) & 0x50000 ;
F_4 ( V_16 , V_11 , V_18 , V_19 , V_8 >= 165000 ) ;
V_58 = F_18 ( V_16 , 0 , V_64 ) & ~ 0x50000 ;
F_19 ( V_16 , 0 , V_64 , V_58 | V_57 ) ;
return 0 ;
}
static void F_36 ( struct V_15 * V_16 , struct V_5 * V_6 , T_2 V_132 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
V_6 -> V_12 = V_6 -> V_1 [ V_132 + 3 ] ;
V_6 -> V_108 = V_6 -> V_1 [ V_132 + 2 ] ;
F_5 ( V_22 , L_31 ,
V_6 -> V_1 [ V_132 + 3 ] , V_6 -> V_1 [ V_132 + 2 ] ,
V_6 -> V_1 [ V_132 + 1 ] , V_6 -> V_1 [ V_132 ] ) ;
}
static void F_37 ( struct V_5 * V_6 , T_2 V_132 )
{
V_6 -> V_14 = F_3 ( V_6 -> V_1 [ V_132 ] ) ;
V_6 -> V_133 = F_3 ( V_6 -> V_1 [ V_132 + 2 ] ) ;
V_6 -> V_134 = F_3 ( V_6 -> V_1 [ V_132 + 4 ] ) ;
V_6 -> V_135 = F_3 ( V_6 -> V_1 [ V_132 + 6 ] ) ;
V_6 -> V_136 = F_3 ( V_6 -> V_1 [ V_132 + 8 ] ) ;
V_6 -> V_137 = F_3 ( V_6 -> V_1 [ V_132 + 10 ] ) ;
V_6 -> V_138 = F_3 ( V_6 -> V_1 [ V_132 + 12 ] ) ;
}
static int F_38 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_139 * V_140 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_141 ;
T_1 V_142 , V_68 , V_143 , V_144 ;
if ( V_140 -> V_2 != 3 ) {
F_14 ( V_22 , L_32 ) ;
return - V_36 ;
}
V_141 = F_3 ( V_6 -> V_1 [ V_140 -> V_132 ] ) ;
if ( V_141 == 0x0 ) {
F_31 ( V_22 , L_33 ) ;
return - V_36 ;
}
V_142 = V_6 -> V_1 [ V_141 ] ;
if ( V_142 != 0x10 ) {
F_14 ( V_22 , L_34 ,
V_142 >> 4 , V_142 & 0xF ) ;
return - V_43 ;
}
V_68 = V_6 -> V_1 [ V_141 + 1 ] ;
V_143 = V_6 -> V_1 [ V_141 + 2 ] ;
V_144 = V_6 -> V_1 [ V_141 + 3 ] ;
if ( V_68 != 4 || V_143 != 4 || V_144 != 2 ) {
F_14 ( V_22 , L_35 ) ;
return - V_36 ;
}
V_6 -> V_145 = F_33 ( V_6 -> V_1 [ V_141 + V_68 ] ) & 0x3ff ;
return 0 ;
}
static int F_39 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_139 * V_140 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_140 -> V_2 < 10 ) {
F_14 ( V_22 , L_36 ) ;
return - V_36 ;
}
V_6 -> V_146 = F_3 ( V_6 -> V_1 [ V_140 -> V_132 + 8 ] ) ;
return 0 ;
}
static int F_40 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_139 * V_140 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_140 -> V_2 != 4 ) {
F_14 ( V_22 , L_37 ) ;
return - V_36 ;
}
V_6 -> V_30 . V_79 = F_3 ( V_6 -> V_1 [ V_140 -> V_132 + 2 ] ) ;
return 0 ;
}
static int F_41 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_139 * V_140 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_140 -> V_2 < 14 ) {
F_14 ( V_22 , L_38 ) ;
return - V_36 ;
}
F_37 ( V_6 , V_140 -> V_132 ) ;
if ( V_140 -> V_2 >= 16 )
V_6 -> V_147 = F_3 ( V_6 -> V_1 [ V_140 -> V_132 + 14 ] ) ;
if ( V_140 -> V_2 >= 18 )
V_6 -> V_148 = F_3 ( V_6 -> V_1 [ V_140 -> V_132 + 16 ] ) ;
return 0 ;
}
static int F_42 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_139 * V_140 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_149 ;
T_1 V_150 , V_151 ;
if ( V_140 -> V_2 < 6 ) {
F_14 ( V_22 , L_39 ) ;
return - V_36 ;
}
F_36 ( V_16 , V_6 , V_140 -> V_132 ) ;
V_6 -> V_152 = V_6 -> V_1 [ V_140 -> V_132 + 5 ] ;
V_6 -> V_81 = V_6 -> V_152 & V_153 ;
if ( V_140 -> V_2 < 15 ) {
F_43 ( V_22 , L_40
L_41 ) ;
return - V_36 ;
}
V_149 = F_3 ( V_6 -> V_1 [ V_140 -> V_132 + 13 ] ) ;
if ( ! V_149 )
return 0 ;
V_150 = V_6 -> V_1 [ V_149 ] ;
V_151 = V_6 -> V_1 [ V_149 + 1 ] ;
if ( V_150 != 0x00 && V_150 != 0x10 ) {
F_43 ( V_22 , L_42
L_43 , V_150 >> 4 , V_150 & 0xf ) ;
return - V_43 ;
}
V_6 -> V_145 = F_33 ( V_6 -> V_1 [ V_149 + V_151 ] ) ;
V_6 -> V_154 = F_33 ( V_6 -> V_1 [ V_149 + V_151 + 4 ] ) ;
return 0 ;
}
static int F_44 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_139 * V_140 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
if ( V_140 -> V_2 != 2 ) {
F_14 ( V_22 , L_44 ) ;
return - V_36 ;
}
V_6 -> V_30 . V_46 = F_3 ( V_6 -> V_1 [ V_140 -> V_132 ] ) ;
return 0 ;
}
static int
F_45 ( struct V_15 * V_16 , struct V_5 * V_6 ,
struct V_139 * V_140 )
{
if ( V_140 -> V_2 < 0x5 )
return 0 ;
if ( V_140 -> V_142 < 2 ) {
V_6 -> V_155 = V_6 -> V_1 [ V_140 -> V_132 + 2 ] ;
V_6 -> V_156 = F_3 ( V_6 -> V_1 [ V_140 -> V_132 + 3 ] ) ;
} else {
V_6 -> V_155 = V_6 -> V_1 [ V_140 -> V_132 + 0 ] ;
V_6 -> V_156 = F_3 ( V_6 -> V_1 [ V_140 -> V_132 + 1 ] ) ;
}
return 0 ;
}
static int F_46 ( struct V_15 * V_16 , struct V_5 * V_6 , struct V_139 * V_140 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_157 , V_158 , V_159 ;
if ( V_140 -> V_2 != 2 ) {
F_14 ( V_22 , L_45 ) ;
return - V_36 ;
}
V_157 = F_3 ( V_6 -> V_1 [ V_140 -> V_132 ] ) ;
if ( ! V_157 ) {
F_14 ( V_22 , L_46 ) ;
return - V_36 ;
}
F_5 ( V_22 , L_47 ,
V_6 -> V_1 [ V_157 ] >> 4 , V_6 -> V_1 [ V_157 ] & 0xf ) ;
if ( V_6 -> V_1 [ V_157 ] != 0x11 )
return - V_43 ;
V_158 = F_3 ( V_6 -> V_1 [ V_157 + 7 ] ) ;
V_159 = F_3 ( V_6 -> V_1 [ V_157 + 9 ] ) ;
if ( V_6 -> V_1 [ V_158 ] != 'q' || V_6 -> V_1 [ V_159 ] != 'q' )
F_43 ( V_22 , L_48 ) ;
V_6 -> V_129 . V_130 = F_3 ( V_6 -> V_1 [ V_157 + 11 ] ) ;
V_6 -> V_129 . V_131 = F_3 ( V_6 -> V_1 [ V_157 + 13 ] ) ;
return 0 ;
}
static int
F_47 ( struct V_15 * V_16 , struct V_5 * V_6 ,
struct V_139 * V_140 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_2 V_160 ;
if ( V_140 -> V_2 != 3 ) {
F_14 ( V_22 , L_49 ) ;
return - V_36 ;
}
V_160 = F_3 ( V_6 -> V_1 [ V_140 -> V_132 ] ) ;
V_6 -> V_124 . V_125 = V_160 ;
return 0 ;
}
int
F_48 ( struct V_15 * V_16 , T_6 V_161 , struct V_139 * V_162 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
T_6 V_163 , * V_164 ;
if ( V_6 -> type != V_165 )
return - V_166 ;
V_163 = V_6 -> V_1 [ V_6 -> V_132 + 10 ] ;
V_164 = & V_6 -> V_1 [ V_6 -> V_132 + 12 ] ;
while ( V_163 -- ) {
if ( V_164 [ 0 ] == V_161 ) {
V_162 -> V_161 = V_164 [ 0 ] ;
V_162 -> V_142 = V_164 [ 1 ] ;
V_162 -> V_2 = F_3 ( V_164 [ 2 ] ) ;
V_162 -> V_132 = F_3 ( V_164 [ 4 ] ) ;
V_162 -> V_1 = F_32 ( V_16 , V_164 [ 4 ] ) ;
return 0 ;
}
V_164 += V_6 -> V_1 [ V_6 -> V_132 + 9 ] ;
}
return - V_53 ;
}
static int
F_49 ( struct V_5 * V_6 , const T_2 V_167 ,
struct F_48 * V_123 )
{
struct V_15 * V_16 = V_6 -> V_16 ;
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_139 V_140 ;
if ( F_48 ( V_16 , V_123 -> V_161 , & V_140 ) == 0 )
return V_123 -> V_168 ( V_16 , V_6 , & V_140 ) ;
F_5 ( V_22 , L_50 , V_123 -> V_161 ) ;
return - V_43 ;
}
static int
F_50 ( struct V_5 * V_6 , const T_2 V_167 )
{
int V_59 ;
V_59 = F_49 ( V_6 , V_167 , & F_51 ( 'i' , V_3 ) ) ;
if ( V_59 )
return V_59 ;
if ( V_6 -> V_12 >= 0x60 )
F_49 ( V_6 , V_167 , & F_51 ( 'A' , V_169 ) ) ;
V_59 = F_49 ( V_6 , V_167 , & F_51 ( 'C' , V_170 ) ) ;
if ( V_59 )
return V_59 ;
F_49 ( V_6 , V_167 , & F_51 ( 'D' , V_124 ) ) ;
V_59 = F_49 ( V_6 , V_167 , & F_51 ( 'I' , V_171 ) ) ;
if ( V_59 )
return V_59 ;
F_49 ( V_6 , V_167 , & F_51 ( 'M' , V_172 ) ) ;
F_49 ( V_6 , V_167 , & F_51 ( 'L' , V_173 ) ) ;
F_49 ( V_6 , V_167 , & F_51 ( 'T' , V_129 ) ) ;
F_49 ( V_6 , V_167 , & F_51 ( 'U' , V_174 ) ) ;
return 0 ;
}
static int F_52 ( struct V_15 * V_16 , struct V_5 * V_6 , unsigned int V_132 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_1 * V_175 = & V_6 -> V_1 [ V_132 ] , V_176 , V_177 ;
T_2 V_178 ;
T_2 V_179 , V_180 ;
V_6 -> V_80 = 0x4b ;
V_6 -> V_181 = 256000 ;
V_6 -> V_182 = 128000 ;
V_6 -> V_30 . V_112 = 90000 ;
V_176 = V_175 [ 5 ] ;
V_177 = V_175 [ 6 ] ;
F_5 ( V_22 , L_51 ,
V_176 , V_177 ) ;
if ( V_176 < 5 )
* ( T_2 * ) & V_6 -> V_1 [ 0x36 ] = 0 ;
if ( ( V_176 < 5 && V_177 != 1 ) || V_176 > 5 ) {
F_14 ( V_22 , L_52
L_53 ) ;
return - V_43 ;
}
if ( V_176 == 0 )
return 0 ;
else if ( V_176 == 1 )
V_178 = 44 ;
else if ( V_176 == 2 )
V_178 = 48 ;
else if ( V_176 == 3 )
V_178 = 54 ;
else if ( V_176 == 4 || V_177 < 0x1 )
V_178 = 62 ;
else if ( V_177 < 0x6 )
V_178 = 67 ;
else if ( V_177 < 0x10 )
V_178 = 75 ;
else if ( V_177 == 0x10 )
V_178 = 89 ;
else if ( V_177 < 0x14 )
V_178 = 118 ;
else if ( V_177 < 0x24 )
V_178 = 123 ;
else if ( V_177 < 0x27 )
V_178 = 144 ;
else
V_178 = 158 ;
if ( F_1 ( V_175 , 8 ) ) {
F_14 ( V_22 , L_54 ) ;
return - V_36 ;
}
V_6 -> V_152 = V_175 [ 9 ] ;
F_36 ( V_16 , V_6 , V_132 + 10 ) ;
if ( V_176 < 5 || V_177 < 0x10 )
V_6 -> V_183 = true ;
V_179 = 18 ;
if ( V_176 < 2 )
V_179 -= 4 ;
V_6 -> V_14 = F_3 ( V_175 [ V_179 ] ) ;
V_6 -> V_184 = F_3 ( V_175 [ V_179 + 2 ] ) ;
if ( V_176 > 2 ) {
V_6 -> V_110 . V_185 = F_3 ( V_175 [ 24 ] ) ;
V_6 -> V_110 . V_186 = F_3 ( V_175 [ 26 ] ) ;
V_6 -> V_110 . V_187 = F_3 ( V_175 [ 28 ] ) ;
}
V_180 = 0x48 ;
if ( V_178 > 61 )
V_180 = V_132 + 54 ;
V_6 -> V_110 . V_188 . V_189 = V_6 -> V_1 [ V_180 ] ;
V_6 -> V_110 . V_188 . V_190 = V_6 -> V_1 [ V_180 + 1 ] ;
V_6 -> V_110 . V_188 . V_191 = V_6 -> V_1 [ V_180 + 2 ] ;
if ( V_178 > 74 ) {
V_6 -> V_181 = F_33 ( V_175 [ 67 ] ) ;
V_6 -> V_182 = F_33 ( V_175 [ 71 ] ) ;
}
if ( V_178 > 88 )
F_37 ( V_6 , V_132 + 75 ) ;
if ( V_178 > 94 ) {
V_6 -> V_129 . V_130 = F_3 ( V_175 [ 89 ] ) ;
V_6 -> V_129 . V_131 = F_3 ( V_175 [ 91 ] ) ;
V_6 -> V_110 . V_111 = F_3 ( V_175 [ 95 ] ) ;
}
if ( V_178 > 108 ) {
V_6 -> V_30 . V_79 = F_3 ( V_175 [ 105 ] ) ;
V_6 -> V_30 . V_82 = F_3 ( V_175 [ 107 ] ) ;
V_6 -> V_30 . V_83 = 1 ;
}
if ( V_178 > 120 ) {
V_6 -> V_30 . V_46 = F_3 ( V_175 [ 117 ] ) ;
V_6 -> V_30 . V_109 = F_3 ( V_175 [ 119 ] ) ;
}
if ( V_178 > 143 )
V_6 -> V_146 = F_3 ( V_175 [ 142 ] ) ;
if ( V_178 > 157 )
V_6 -> V_30 . V_112 = F_3 ( V_175 [ 156 ] ) * 10 ;
return 0 ;
}
static T_2 F_53 ( T_1 * V_1 , int V_192 , const T_1 * V_193 , int V_194 )
{
int V_3 , V_195 ;
for ( V_3 = 0 ; V_3 <= ( V_192 - V_194 ) ; V_3 ++ ) {
for ( V_195 = 0 ; V_195 < V_194 ; V_195 ++ )
if ( V_1 [ V_3 + V_195 ] != V_193 [ V_195 ] )
break;
if ( V_195 == V_194 )
return V_3 ;
}
return 0 ;
}
void *
F_54 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
T_6 * V_113 = NULL ;
if ( F_16 ( V_22 -> V_55 ) -> V_70 > V_196 )
V_113 = F_32 ( V_16 , V_22 -> V_28 . V_1 [ 0x36 ] ) ;
if ( ! V_113 ) {
F_43 ( V_22 , L_55 ) ;
return NULL ;
}
if ( V_113 [ 0 ] >= 0x41 ) {
F_43 ( V_22 , L_56 , V_113 [ 0 ] ) ;
return NULL ;
} else
if ( V_113 [ 0 ] >= 0x30 ) {
if ( F_33 ( V_113 [ 6 ] ) == 0x4edcbdcb )
return V_113 ;
} else
if ( V_113 [ 0 ] >= 0x20 ) {
if ( F_33 ( V_113 [ 4 ] ) == 0x4edcbdcb )
return V_113 ;
} else
if ( V_113 [ 0 ] >= 0x15 ) {
if ( ! memcmp ( & V_113 [ - 7 ] , L_57 , 7 ) )
return V_113 ;
} else {
F_43 ( V_22 , L_58 ) ;
return NULL ;
}
F_43 ( V_22 , L_59 ) ;
return NULL ;
}
void *
F_55 ( struct V_15 * V_16 , T_6 V_197 )
{
T_6 * V_113 = F_54 ( V_16 ) ;
if ( V_113 && V_113 [ 0 ] >= 0x30 ) {
if ( V_197 < V_113 [ 2 ] )
return V_113 + V_113 [ 1 ] + ( V_197 * V_113 [ 3 ] ) ;
} else
if ( V_113 && V_113 [ 0 ] >= 0x20 ) {
T_6 * V_198 = F_32 ( V_16 , V_113 [ 2 ] ) ;
T_6 * V_199 = V_113 + 8 + ( V_197 * 8 ) ;
if ( V_198 && V_199 < V_198 )
return V_199 ;
} else
if ( V_113 && V_113 [ 0 ] >= 0x15 ) {
T_6 * V_198 = F_32 ( V_16 , V_113 [ 2 ] ) ;
T_6 * V_199 = V_113 + 4 + ( V_197 * 10 ) ;
if ( V_198 && V_199 < V_198 )
return V_199 ;
}
return NULL ;
}
int
F_56 ( struct V_15 * V_16 , void * V_1 ,
int (* F_57)( struct V_15 * , void * , int V_197 , T_6 * V_200 ) )
{
int V_59 , V_197 = - 1 ;
T_6 * V_200 = NULL ;
while ( ( V_200 = F_55 ( V_16 , ++ V_197 ) ) ) {
if ( F_33 ( V_200 [ 0 ] ) == 0x00000000 )
break;
if ( F_33 ( V_200 [ 0 ] ) == 0xffffffff )
break;
if ( ( V_200 [ 0 ] & 0x0f ) == V_201 )
continue;
if ( ( V_200 [ 0 ] & 0x0f ) == V_202 )
break;
V_59 = F_57 ( V_16 , V_1 , V_197 , V_200 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
T_6 *
F_58 ( struct V_15 * V_16 )
{
T_6 * V_113 = F_54 ( V_16 ) ;
if ( V_113 && V_113 [ 0 ] >= 0x30 && V_113 [ 1 ] >= 0x16 ) {
T_6 * V_203 = F_32 ( V_16 , V_113 [ 0x14 ] ) ;
if ( V_203 && V_203 [ 0 ] >= 0x30 && V_203 [ 0 ] <= 0x40 )
return V_203 ;
}
return NULL ;
}
T_6 *
F_59 ( struct V_15 * V_16 , T_6 V_197 )
{
T_6 * V_203 = F_58 ( V_16 ) ;
if ( V_203 && V_197 < V_203 [ 2 ] )
return V_203 + V_203 [ 1 ] + ( V_197 * V_203 [ 3 ] ) ;
return NULL ;
}
static struct V_17 * F_60 ( struct V_204 * V_113 )
{
struct V_17 * V_164 = & V_113 -> V_164 [ V_113 -> V_163 ] ;
memset ( V_164 , 0 , sizeof( struct V_17 ) ) ;
V_164 -> V_205 = V_113 -> V_163 ++ ;
return V_164 ;
}
static void F_61 ( struct V_204 * V_113 , int type , int V_198 ,
int V_206 , int V_33 )
{
struct V_17 * V_164 = F_60 ( V_113 ) ;
V_164 -> type = type ;
V_164 -> V_207 = V_198 ;
V_164 -> V_206 = V_206 ;
if ( type != V_208 )
V_164 -> V_115 = ! V_128 ;
V_164 -> V_33 = V_33 ;
}
static bool
F_62 ( struct V_15 * V_16 , struct V_204 * V_113 ,
T_3 V_209 , T_3 V_210 , struct V_17 * V_164 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
V_164 -> type = V_209 & 0xf ;
V_164 -> V_207 = ( V_209 >> 4 ) & 0xf ;
V_164 -> V_206 = ( V_209 >> 8 ) & 0xf ;
V_164 -> V_211 = ( V_209 >> 12 ) & 0xf ;
V_164 -> V_212 = ( V_209 >> 16 ) & 0xf ;
V_164 -> V_115 = ( V_209 >> 20 ) & 0x3 ;
V_164 -> V_33 = ( V_209 >> 24 ) & 0xf ;
switch ( V_164 -> type ) {
case V_208 :
V_164 -> V_213 . V_214 = ( V_113 -> V_142 < 0x30 ) ?
( V_210 & 0xffff ) * 10 :
( V_210 & 0xff ) * 10000 ;
break;
case V_117 :
{
T_3 V_215 ;
if ( V_210 & 0x1 )
V_164 -> V_48 . V_49 = true ;
if ( V_113 -> V_142 < 0x22 ) {
V_215 = ~ 0xd ;
V_164 -> V_48 . V_49 = true ;
if ( V_210 & 0x4 || V_210 & 0x8 )
V_164 -> V_48 . V_216 = true ;
} else {
V_215 = ~ 0x7 ;
if ( V_210 & 0x2 )
V_164 -> V_48 . V_217 = true ;
if ( V_210 & 0x4 )
V_164 -> V_48 . V_216 = true ;
V_164 -> V_48 . V_218 . V_120 = ( V_210 & 0x00000030 ) >> 4 ;
}
if ( V_210 & V_215 ) {
if ( V_113 -> V_142 >= 0x40 )
break;
F_14 ( V_22 , L_60
L_61 ) ;
}
break;
}
case V_219 :
{
if ( V_113 -> V_142 >= 0x30 )
V_164 -> V_220 . V_221 = V_210 & ( 0x8 << 4 ) ;
else
V_164 -> V_220 . V_221 = false ;
break;
}
case V_118 :
V_164 -> V_222 . V_218 . V_120 = ( V_210 & 0x00000030 ) >> 4 ;
switch ( ( V_210 & 0x00e00000 ) >> 21 ) {
case 0 :
V_164 -> V_222 . V_223 = 162000 ;
break;
default:
V_164 -> V_222 . V_223 = 270000 ;
break;
}
switch ( ( V_210 & 0x0f000000 ) >> 24 ) {
case 0xf :
V_164 -> V_222 . V_224 = 4 ;
break;
case 0x3 :
V_164 -> V_222 . V_224 = 2 ;
break;
default:
V_164 -> V_222 . V_224 = 1 ;
break;
}
break;
case V_116 :
if ( V_113 -> V_142 >= 0x40 )
V_164 -> V_225 . V_218 . V_120 = ( V_210 & 0x00000030 ) >> 4 ;
else if ( V_113 -> V_142 >= 0x30 )
V_164 -> V_225 . V_226 = ( V_210 & 0x00000700 ) >> 8 ;
else if ( V_113 -> V_142 >= 0x22 )
V_164 -> V_225 . V_226 = ( V_210 & 0x00000070 ) >> 4 ;
break;
case V_202 :
V_113 -> V_163 -- ;
return false ;
default:
break;
}
if ( V_113 -> V_142 < 0x40 ) {
V_164 -> V_227 =
( ( 1 << ( F_35 ( V_164 -> V_33 ) - 1 ) ) * 3 == V_164 -> V_33 ) ;
} else {
V_164 -> V_227 = ( V_164 -> V_119 . V_120 == 3 ) ;
}
if ( V_210 & 0x100000 )
V_164 -> V_228 = true ;
return true ;
}
static bool
F_63 ( struct V_15 * V_16 , struct V_204 * V_113 ,
T_3 V_209 , T_3 V_210 , struct V_17 * V_164 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
switch ( V_209 & 0x0000000f ) {
case 0 :
V_164 -> type = V_208 ;
break;
case 1 :
V_164 -> type = V_219 ;
break;
case 2 :
case 4 :
if ( V_209 & 0x10 )
V_164 -> type = V_117 ;
else
V_164 -> type = V_116 ;
break;
case 3 :
V_164 -> type = V_117 ;
break;
default:
F_14 ( V_22 , L_62 , V_209 & 0x0000000f ) ;
return false ;
}
V_164 -> V_207 = ( V_209 & 0x0003c000 ) >> 14 ;
V_164 -> V_206 = ( ( V_209 & 0x001c0000 ) >> 18 ) + 1 ;
V_164 -> V_33 = V_164 -> V_206 ;
V_164 -> V_115 = ( V_209 & 0x01e00000 ) >> 21 ;
V_164 -> V_212 = ( V_209 & 0x0e000000 ) >> 25 ;
V_164 -> V_227 = false ;
switch ( V_164 -> type ) {
case V_208 :
V_164 -> V_213 . V_214 = ( V_210 & 0xffff ) * 10 ;
break;
case V_219 :
V_164 -> V_220 . V_221 = false ;
break;
case V_117 :
if ( ( V_209 & 0x00003f00 ) >> 8 != 0x10 )
V_164 -> V_48 . V_49 = true ;
V_164 -> V_48 . V_216 = true ;
break;
default:
break;
}
return true ;
}
static
void F_64 ( struct V_15 * V_16 , struct V_204 * V_113 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
int V_3 , V_229 = 0 ;
for ( V_3 = 0 ; V_3 < V_113 -> V_163 ; V_3 ++ ) {
struct V_17 * V_230 = & V_113 -> V_164 [ V_3 ] ;
int V_195 ;
for ( V_195 = V_3 + 1 ; V_195 < V_113 -> V_163 ; V_195 ++ ) {
struct V_17 * V_231 = & V_113 -> V_164 [ V_195 ] ;
if ( V_231 -> type == 100 )
continue;
if ( V_231 -> V_207 == V_230 -> V_207 &&
V_231 -> type == V_230 -> type &&
V_231 -> V_115 == V_230 -> V_115 &&
V_231 -> V_33 == V_230 -> V_33 ) {
F_5 ( V_22 , L_63 ,
V_3 , V_195 ) ;
V_230 -> V_206 |= V_231 -> V_206 ;
V_231 -> type = 100 ;
}
}
}
for ( V_3 = 0 ; V_3 < V_113 -> V_163 ; V_3 ++ ) {
if ( V_113 -> V_164 [ V_3 ] . type == 100 )
continue;
if ( V_229 != V_3 ) {
V_113 -> V_164 [ V_229 ] = V_113 -> V_164 [ V_3 ] ;
V_113 -> V_164 [ V_229 ] . V_205 = V_229 ;
}
V_229 ++ ;
}
V_113 -> V_163 = V_229 ;
}
static bool
F_65 ( struct V_15 * V_16 , int V_197 , T_4 * V_209 , T_4 * V_210 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_204 * V_113 = & V_22 -> V_28 . V_113 ;
if ( F_66 ( V_16 , 0x040d , 0x1028 , 0x019b ) ) {
if ( * V_209 == 0x02026312 && * V_210 == 0x00000020 )
return false ;
}
if ( F_66 ( V_16 , 0x0201 , 0x1462 , 0x8851 ) ) {
if ( * V_209 == 0xf2005014 && * V_210 == 0xffffffff ) {
F_61 ( V_113 , V_116 , 1 , 1 , 1 ) ;
return false ;
}
}
if ( F_66 ( V_16 , 0x0ca3 , 0x1682 , 0x3003 ) ) {
if ( V_197 == 0 ) {
* V_209 = 0x02001300 ;
* V_210 = 0x00000028 ;
} else
if ( V_197 == 1 ) {
* V_209 = 0x01010312 ;
* V_210 = 0x00020030 ;
} else
if ( V_197 == 2 ) {
* V_209 = 0x01010310 ;
* V_210 = 0x00000028 ;
} else
if ( V_197 == 3 ) {
* V_209 = 0x02022362 ;
* V_210 = 0x00020010 ;
} else {
* V_209 = 0x0000000e ;
* V_210 = 0x00000000 ;
}
}
if ( F_66 ( V_16 , 0x0615 , 0x1682 , 0x2605 ) ) {
if ( V_197 == 0 ) {
* V_209 = 0x02002300 ;
* V_210 = 0x00000028 ;
} else
if ( V_197 == 1 ) {
* V_209 = 0x01010312 ;
* V_210 = 0x00020030 ;
} else
if ( V_197 == 2 ) {
* V_209 = 0x04020310 ;
* V_210 = 0x00000028 ;
} else
if ( V_197 == 3 ) {
* V_209 = 0x02021322 ;
* V_210 = 0x00020010 ;
} else {
* V_209 = 0x0000000e ;
* V_210 = 0x00000000 ;
}
}
if ( F_66 ( V_16 , 0x0421 , 0x3842 , 0xc793 ) ) {
if ( V_197 == 0 && * V_209 == 0x02000300 )
* V_209 = 0x02011300 ;
else
if ( V_197 == 1 && * V_209 == 0x04011310 )
* V_209 = 0x04000310 ;
else
if ( V_197 == 2 && * V_209 == 0x02011312 )
* V_209 = 0x02000312 ;
}
return true ;
}
static void
F_67 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_204 * V_113 = & V_6 -> V_113 ;
int V_232 = ( F_68 ( V_16 ) ? 3 : 1 ) ;
#ifdef F_11
if ( F_69 ( L_64 ) ) {
F_61 ( V_113 , V_116 , 0 , V_232 , 1 ) ;
F_61 ( V_113 , V_208 , 1 , V_232 , 2 ) ;
return;
}
#endif
F_61 ( V_113 , V_208 ,
V_6 -> V_110 . V_188 . V_189 , 1 , 1 ) ;
if ( F_70 ( V_16 , V_6 -> V_110 . V_188 . V_190 ) >= 0 )
F_61 ( V_113 , V_219 ,
V_6 -> V_110 . V_188 . V_190 ,
V_232 , 0 ) ;
else if ( V_6 -> V_129 . V_130 ||
V_6 -> V_129 . V_131 )
F_61 ( V_113 , V_116 ,
V_6 -> V_110 . V_188 . V_191 ,
V_232 , 1 ) ;
}
static int
F_71 ( struct V_15 * V_16 , void * V_1 , int V_197 , T_6 * V_200 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_204 * V_113 = & V_22 -> V_28 . V_113 ;
T_4 V_210 = ( V_113 -> V_142 >= 0x20 ) ? F_33 ( V_200 [ 4 ] ) : F_33 ( V_200 [ 6 ] ) ;
T_4 V_209 = F_33 ( V_200 [ 0 ] ) ;
bool V_59 ;
if ( F_65 ( V_16 , V_197 , & V_209 , & V_210 ) ) {
struct V_17 * V_164 = F_60 ( V_113 ) ;
F_5 ( V_22 , L_65 , V_197 , V_209 , V_210 ) ;
if ( V_113 -> V_142 >= 0x20 )
V_59 = F_62 ( V_16 , V_113 , V_209 , V_210 , V_164 ) ;
else
V_59 = F_63 ( V_16 , V_113 , V_209 , V_210 , V_164 ) ;
if ( ! V_59 )
return 1 ;
if ( V_164 -> type == V_219 &&
V_164 -> V_115 == V_128 )
V_164 -> V_207 = 0x0f ;
}
return 0 ;
}
static void
F_72 ( struct V_5 * V_6 )
{
struct V_204 * V_233 = & V_6 -> V_113 ;
T_6 V_234 [ 16 ] = { } ;
int V_3 , V_197 = 0 ;
if ( ! F_66 ( V_6 -> V_16 , 0x0392 , 0x107d , 0x20a2 ) ) {
for ( V_3 = 0 ; V_3 < V_233 -> V_163 ; V_3 ++ ) {
if ( V_233 -> V_164 [ V_3 ] . V_211 )
return;
}
}
for ( V_3 = 0 ; V_3 < V_233 -> V_163 ; V_3 ++ ) {
T_6 V_198 = V_233 -> V_164 [ V_3 ] . V_207 ;
if ( V_198 == 0x0f ) {
V_233 -> V_164 [ V_3 ] . V_211 = V_197 ++ ;
} else {
if ( ! V_234 [ V_198 ] )
V_234 [ V_198 ] = ++ V_197 ;
V_233 -> V_164 [ V_3 ] . V_211 = V_234 [ V_198 ] - 1 ;
}
}
if ( V_3 > 1 ) {
T_6 * V_203 = F_58 ( V_6 -> V_16 ) ;
if ( V_203 )
V_203 [ 0 ] = 0x00 ;
}
}
static int
F_73 ( struct V_15 * V_16 , struct V_5 * V_6 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_204 * V_113 = & V_6 -> V_113 ;
T_6 * V_233 , * V_209 ;
int V_197 ;
V_233 = F_54 ( V_16 ) ;
if ( ! V_233 ) {
if ( V_6 -> type == V_235 ) {
F_67 ( V_16 , V_6 ) ;
return 0 ;
}
return - V_36 ;
}
F_5 ( V_22 , L_66 , V_233 [ 0 ] >> 4 , V_233 [ 0 ] & 0xf ) ;
V_113 -> V_142 = V_233 [ 0 ] ;
F_56 ( V_16 , NULL , F_71 ) ;
if ( V_113 -> V_142 < 0x21 )
F_64 ( V_16 , V_113 ) ;
if ( ! V_113 -> V_163 )
return - V_236 ;
V_197 = - 1 ;
while ( ( V_209 = F_59 ( V_16 , ++ V_197 ) ) ) {
if ( V_209 [ 0 ] != 0xff ) {
F_5 ( V_22 , L_67 , V_197 ) ;
if ( F_58 ( V_16 ) [ 3 ] < 4 )
F_74 ( L_68 , F_3 ( V_209 [ 0 ] ) ) ;
else
F_74 ( L_69 , F_33 ( V_209 [ 0 ] ) ) ;
}
}
F_72 ( V_6 ) ;
return 0 ;
}
static int F_75 ( struct V_15 * V_16 , struct V_5 * V_6 , T_2 V_237 , int V_164 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_54 * V_55 = F_16 ( V_22 -> V_55 ) ;
T_1 V_238 ;
T_2 V_239 ;
int V_3 ;
if ( V_6 -> V_1 [ V_237 ] <= V_164 ) {
F_14 ( V_22 , L_70
L_71 ) ;
return - V_53 ;
}
V_238 = V_6 -> V_1 [ V_237 + 1 ] ;
if ( V_238 != 36 ) {
F_14 ( V_22 , L_72 ) ;
return - V_36 ;
}
F_5 ( V_22 , L_73 ) ;
V_239 = V_237 + 2 + V_164 * V_238 ;
F_20 ( V_55 , 0x00001304 , F_33 ( V_6 -> V_1 [ V_239 ] ) ) ;
V_238 -= 4 ;
for ( V_3 = 0 ; V_3 < V_238 ; V_3 += 4 )
F_20 ( V_55 , 0x00001400 + V_3 , F_33 ( V_6 -> V_1 [ V_239 + V_3 + 4 ] ) ) ;
F_20 ( V_55 , V_240 , F_17 ( V_55 , V_240 ) | 0x18 ) ;
return 0 ;
}
static int F_76 ( struct V_15 * V_16 ,
struct V_5 * V_6 )
{
const T_1 V_241 [] = { 'H' , 'W' , 'S' , 'Q' } ;
const int V_242 = sizeof( V_241 ) ;
int V_237 ;
V_237 = F_53 ( V_6 -> V_1 , V_6 -> V_2 , V_241 , V_242 ) ;
if ( ! V_237 )
return 0 ;
return F_75 ( V_16 , V_6 , V_237 + V_242 , 0 ) ;
}
T_1 * F_77 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
const T_1 V_243 [] = {
0x00 , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0x00 } ;
T_2 V_132 = 0 ;
T_2 V_244 ;
int V_245 = V_246 ;
if ( V_6 -> V_30 . V_247 )
return V_6 -> V_30 . V_247 ;
while ( V_245 ) {
V_244 = F_53 ( & V_6 -> V_1 [ V_132 ] , V_245 ,
V_243 , 8 ) ;
if ( ! V_244 )
return NULL ;
V_132 += V_244 ;
if ( ! F_1 ( & V_6 -> V_1 [ V_132 ] , V_248 ) )
break;
V_245 -= V_132 ;
V_132 ++ ;
}
F_5 ( V_22 , L_74 ) ;
return V_6 -> V_30 . V_247 = & V_6 -> V_1 [ V_132 ] ;
}
static bool F_78 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
F_79 ( & V_6 -> V_249 ) ;
V_6 -> V_16 = V_16 ;
V_6 -> V_1 = F_80 ( V_22 -> V_55 ) -> V_1 ;
V_6 -> V_2 = F_80 ( V_22 -> V_55 ) -> V_250 ;
return true ;
}
static int F_81 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
const T_1 V_251 [] = { 0xff , 0xb8 , 'B' , 'I' , 'T' } ;
const T_1 V_252 [] = { 0xff , 0x7f , 'N' , 'V' , 0x0 } ;
int V_132 ;
V_132 = F_53 ( V_6 -> V_1 , V_6 -> V_2 ,
V_251 , sizeof( V_251 ) ) ;
if ( V_132 ) {
F_5 ( V_22 , L_75 ) ;
V_6 -> type = V_165 ;
V_6 -> V_132 = V_132 ;
return F_50 ( V_6 , V_132 + 6 ) ;
}
V_132 = F_53 ( V_6 -> V_1 , V_6 -> V_2 ,
V_252 , sizeof( V_252 ) ) ;
if ( V_132 ) {
F_5 ( V_22 , L_76 ) ;
V_6 -> type = V_235 ;
V_6 -> V_132 = V_132 ;
return F_52 ( V_16 , V_6 , V_132 ) ;
}
F_14 ( V_22 , L_77 ) ;
return - V_166 ;
}
int
F_82 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_3 , V_59 = 0 ;
V_6 -> V_253 . V_254 = 0 ;
if ( V_6 -> V_12 < 5 )
F_76 ( V_16 , V_6 ) ;
if ( V_6 -> V_255 ) {
V_6 -> V_30 . V_60 = 0 ;
V_6 -> V_30 . V_61 = false ;
}
if ( F_16 ( V_22 -> V_55 ) -> V_70 >= V_71 ) {
for ( V_3 = 0 ; V_6 -> V_255 && V_3 < V_6 -> V_113 . V_163 ; V_3 ++ ) {
F_30 ( V_16 , 0 , 0 ,
& V_6 -> V_113 . V_164 [ V_3 ] , - 1 ) ;
}
}
return V_59 ;
}
static bool
F_83 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
unsigned V_92 ;
if ( F_16 ( V_22 -> V_55 ) -> V_70 >= V_71 ) {
if ( F_84 ( V_16 , 0 , 0x00 ) == 0 &&
F_84 ( V_16 , 0 , 0x1a ) == 0 )
return false ;
return true ;
}
V_92 = F_84 ( V_16 , 0 , 0x06 ) ;
V_92 |= ( F_84 ( V_16 , 0 , 0x07 ) & 0x01 ) << 8 ;
V_92 |= ( F_84 ( V_16 , 0 , 0x07 ) & 0x20 ) << 4 ;
V_92 |= ( F_84 ( V_16 , 0 , 0x25 ) & 0x01 ) << 10 ;
V_92 |= ( F_84 ( V_16 , 0 , 0x41 ) & 0x01 ) << 11 ;
return ( V_92 != 0 ) ;
}
int
F_85 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_21 ( V_16 ) ;
struct V_5 * V_6 = & V_22 -> V_28 ;
int V_59 ;
if ( ! F_78 ( V_16 ) )
return - V_166 ;
V_59 = F_81 ( V_16 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_73 ( V_16 , V_6 ) ;
if ( V_59 )
return V_59 ;
if ( ! V_6 -> V_12 )
return 0 ;
V_6 -> V_255 = false ;
if ( ! F_83 ( V_16 ) ) {
F_5 ( V_22 , L_78
L_79 ) ;
V_6 -> V_255 = true ;
}
V_59 = F_82 ( V_16 ) ;
if ( V_59 )
return V_59 ;
if ( V_6 -> V_12 < 5 )
V_6 -> V_81 = F_84 ( V_16 , 0 , V_256 ) & 0x40 ;
if ( V_6 -> V_81 || V_6 -> V_12 >= 5 )
V_59 = F_25 ( V_16 , V_6 ) ;
V_6 -> V_255 = true ;
return 0 ;
}
void
F_86 ( struct V_15 * V_16 )
{
}
