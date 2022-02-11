void F_1 ( const T_1 * V_1 )
{
V_2 = V_1 ;
}
void F_2 ( struct V_3 * V_4 , unsigned V_5 , unsigned V_6 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_7 = V_4 -> V_8 = V_5 ;
V_4 -> V_9 = V_4 -> V_10 = V_6 ;
V_4 -> V_11 . V_12 = V_4 -> V_13 . V_12 = V_5 ;
V_4 -> V_11 . V_14 = V_4 -> V_13 . V_14 = V_6 ;
V_4 -> V_15 = true ;
V_4 -> V_16 = true ;
V_4 -> V_17 = 128 ;
V_4 -> V_18 = 128 ;
V_4 -> V_19 = 128 ;
V_4 -> V_20 = 0 ;
V_4 -> V_21 = V_22 ;
V_4 -> V_23 = V_22 ;
V_4 -> V_24 = V_25 ;
F_3 ( V_4 , V_26 ) ;
V_4 -> V_27 = V_28 ;
V_4 -> V_29 = 100 ;
}
int F_4 ( struct V_3 * V_4 , unsigned V_30 )
{
unsigned V_31 ;
unsigned V_32 ;
V_4 -> V_33 = V_30 ;
for ( V_31 = 0 ; V_31 < V_34 ; V_31 ++ ) {
for ( V_32 = 0 ; V_32 < V_35 ; V_32 ++ ) {
unsigned V_36 = V_32 ? 1 : 4 ;
V_4 -> V_37 [ V_31 ] [ V_32 ] = F_5 ( V_30 * 2 * V_36 ) ;
if ( ! V_4 -> V_37 [ V_31 ] [ V_32 ] )
return - V_38 ;
}
}
for ( V_32 = 0 ; V_32 < V_35 ; V_32 ++ ) {
unsigned V_36 = V_32 ? 1 : 4 ;
V_4 -> V_39 [ V_32 ] = F_5 ( V_30 * V_36 ) ;
if ( ! V_4 -> V_39 [ V_32 ] )
return - V_38 ;
V_4 -> V_40 [ V_32 ] = F_5 ( V_30 * V_36 ) ;
if ( ! V_4 -> V_40 [ V_32 ] )
return - V_38 ;
V_4 -> V_41 [ V_32 ] = F_5 ( V_30 * 2 * V_36 ) ;
if ( ! V_4 -> V_41 [ V_32 ] )
return - V_38 ;
}
return 0 ;
}
void F_6 ( struct V_3 * V_4 )
{
unsigned V_31 ;
unsigned V_32 ;
for ( V_31 = 0 ; V_31 < V_34 ; V_31 ++ )
for ( V_32 = 0 ; V_32 < V_35 ; V_32 ++ ) {
F_7 ( V_4 -> V_37 [ V_31 ] [ V_32 ] ) ;
V_4 -> V_37 [ V_31 ] [ V_32 ] = NULL ;
}
for ( V_32 = 0 ; V_32 < V_35 ; V_32 ++ ) {
F_7 ( V_4 -> V_39 [ V_32 ] ) ;
F_7 ( V_4 -> V_40 [ V_32 ] ) ;
F_7 ( V_4 -> V_41 [ V_32 ] ) ;
V_4 -> V_39 [ V_32 ] = NULL ;
V_4 -> V_40 [ V_32 ] = NULL ;
V_4 -> V_41 [ V_32 ] = NULL ;
}
}
bool F_3 ( struct V_3 * V_4 , T_2 V_42 )
{
V_4 -> V_42 = V_42 ;
V_4 -> V_43 = 1 ;
V_4 -> V_15 = true ;
switch ( V_42 ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_26 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_4 -> V_57 = false ;
break;
case V_58 :
case V_59 :
V_4 -> V_43 = 2 ;
case V_60 :
case V_61 :
case V_62 :
case V_63 :
V_4 -> V_57 = true ;
break;
default:
return false ;
}
switch ( V_42 ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
V_4 -> V_64 [ 0 ] = 2 * 2 ;
break;
case V_26 :
case V_50 :
V_4 -> V_64 [ 0 ] = 2 * 3 ;
break;
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_4 -> V_64 [ 0 ] = 2 * 4 ;
break;
case V_58 :
case V_59 :
V_4 -> V_64 [ 0 ] = 2 ;
V_4 -> V_64 [ 1 ] = 2 ;
break;
}
return true ;
}
void F_8 ( struct V_3 * V_4 , const struct V_65 * V_11 ,
const struct V_65 * V_13 )
{
V_4 -> V_11 = * V_11 ;
V_4 -> V_13 = * V_13 ;
V_4 -> V_7 = ( V_4 -> V_8 * V_4 -> V_13 . V_12 +
V_4 -> V_11 . V_12 - 1 ) / V_4 -> V_11 . V_12 ;
V_4 -> V_7 &= ~ 1 ;
if ( V_4 -> V_7 > V_4 -> V_33 )
V_4 -> V_7 = V_4 -> V_33 ;
if ( V_4 -> V_7 < 2 )
V_4 -> V_7 = 2 ;
V_4 -> V_66 = true ;
}
void F_9 ( struct V_3 * V_4 , unsigned V_12 , unsigned V_14 ,
T_2 V_24 )
{
unsigned V_67 ;
V_4 -> V_8 = V_12 ;
V_4 -> V_9 = V_14 ;
V_4 -> V_24 = V_24 ;
V_4 -> V_10 = V_14 ;
if ( F_10 ( V_24 ) )
V_4 -> V_10 /= 2 ;
V_4 -> V_7 = V_12 ;
V_4 -> V_11 . V_68 = V_4 -> V_11 . V_69 = 0 ;
V_4 -> V_11 . V_12 = V_12 ;
V_4 -> V_11 . V_14 = V_14 ;
V_4 -> V_13 . V_68 = V_4 -> V_13 . V_69 = 0 ;
V_4 -> V_13 . V_12 = V_12 ;
V_4 -> V_13 . V_14 = V_4 -> V_10 ;
for ( V_67 = 0 ; V_67 < V_4 -> V_43 ; V_67 ++ )
V_4 -> V_70 [ V_67 ] = V_12 * V_4 -> V_64 [ V_67 ] / 2 ;
V_4 -> V_16 = true ;
}
static enum V_71 F_11 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_72 ) {
case V_73 :
return V_74 ;
case V_75 :
return V_76 ;
default:
return V_77 ;
}
}
static enum V_71 F_12 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_72 ) {
case V_78 :
case V_75 :
return V_79 ;
case V_73 :
return V_77 ;
default:
return V_74 ;
}
}
static T_3 F_13 ( struct V_3 * V_4 , int V_80 , int V_81 , int V_82 )
{
switch ( V_4 -> V_27 ) {
case V_83 :
case V_84 :
case V_85 :
return ( ( 16829 * V_80 + 33039 * V_81 + 6416 * V_82 + 16 * 32768 ) >> 16 ) + ( 16 << 4 ) ;
case V_86 :
return ( ( 11932 * V_80 + 39455 * V_81 + 4897 * V_82 + 16 * 32768 ) >> 16 ) + ( 16 << 4 ) ;
case V_87 :
case V_28 :
default:
return ( ( 11966 * V_80 + 40254 * V_81 + 4064 * V_82 + 16 * 32768 ) >> 16 ) + ( 16 << 4 ) ;
}
}
static T_3 F_14 ( struct V_3 * V_4 , int V_80 , int V_81 , int V_82 )
{
switch ( V_4 -> V_27 ) {
case V_83 :
case V_84 :
case V_85 :
return ( ( - 9714 * V_80 - 19070 * V_81 + 28784 * V_82 + 16 * 32768 ) >> 16 ) + ( 128 << 4 ) ;
case V_86 :
return ( ( - 6684 * V_80 - 22100 * V_81 + 28784 * V_82 + 16 * 32768 ) >> 16 ) + ( 128 << 4 ) ;
case V_87 :
case V_28 :
default:
return ( ( - 6596 * V_80 - 22189 * V_81 + 28784 * V_82 + 16 * 32768 ) >> 16 ) + ( 128 << 4 ) ;
}
}
static T_3 F_15 ( struct V_3 * V_4 , int V_80 , int V_81 , int V_82 )
{
switch ( V_4 -> V_27 ) {
case V_83 :
case V_84 :
case V_85 :
return ( ( 28784 * V_80 - 24103 * V_81 - 4681 * V_82 + 16 * 32768 ) >> 16 ) + ( 128 << 4 ) ;
case V_86 :
return ( ( 28784 * V_80 - 25606 * V_81 - 3178 * V_82 + 16 * 32768 ) >> 16 ) + ( 128 << 4 ) ;
case V_87 :
case V_28 :
default:
return ( ( 28784 * V_80 - 26145 * V_81 - 2639 * V_82 + 16 * 32768 ) >> 16 ) + ( 128 << 4 ) ;
}
}
static T_3 F_16 ( struct V_3 * V_4 , int V_88 , int V_89 , int V_90 )
{
int V_80 ;
V_88 -= 16 << 4 ;
V_89 -= 128 << 4 ;
V_90 -= 128 << 4 ;
switch ( V_4 -> V_27 ) {
case V_83 :
case V_84 :
case V_85 :
V_80 = 4769 * V_88 + 6537 * V_90 ;
break;
case V_86 :
V_80 = 4769 * V_88 + 7376 * V_90 ;
break;
case V_87 :
case V_28 :
default:
V_80 = 4769 * V_88 + 7343 * V_90 ;
break;
}
return F_17 ( V_80 >> 12 , 0 , 0xff0 ) ;
}
static T_3 F_18 ( struct V_3 * V_4 , int V_88 , int V_89 , int V_90 )
{
int V_81 ;
V_88 -= 16 << 4 ;
V_89 -= 128 << 4 ;
V_90 -= 128 << 4 ;
switch ( V_4 -> V_27 ) {
case V_83 :
case V_84 :
case V_85 :
V_81 = 4769 * V_88 - 1605 * V_89 - 3330 * V_90 ;
break;
case V_86 :
V_81 = 4769 * V_88 - 1055 * V_89 - 2341 * V_90 ;
break;
case V_87 :
case V_28 :
default:
V_81 = 4769 * V_88 - 873 * V_89 - 2183 * V_90 ;
break;
}
return F_17 ( V_81 >> 12 , 0 , 0xff0 ) ;
}
static T_3 F_19 ( struct V_3 * V_4 , int V_88 , int V_89 , int V_90 )
{
int V_82 ;
V_88 -= 16 << 4 ;
V_89 -= 128 << 4 ;
V_90 -= 128 << 4 ;
switch ( V_4 -> V_27 ) {
case V_83 :
case V_84 :
case V_85 :
V_82 = 4769 * V_88 + 7343 * V_89 ;
break;
case V_86 :
V_82 = 4769 * V_88 + 8552 * V_89 ;
break;
case V_87 :
case V_28 :
default:
V_82 = 4769 * V_88 + 8652 * V_89 ;
break;
}
return F_17 ( V_82 >> 12 , 0 , 0xff0 ) ;
}
static void F_20 ( struct V_3 * V_4 , int V_91 )
{
int V_92 = V_91 ;
int V_80 = V_93 [ V_92 ] . V_80 ;
int V_81 = V_93 [ V_92 ] . V_81 ;
int V_82 = V_93 [ V_92 ] . V_82 ;
if ( V_91 == V_94 ) {
V_92 = F_11 ( V_4 ) ;
V_80 = V_93 [ V_92 ] . V_80 ;
V_81 = V_93 [ V_92 ] . V_81 ;
V_82 = V_93 [ V_92 ] . V_82 ;
} else if ( V_91 == V_95 ) {
V_92 = F_12 ( V_4 ) ;
V_80 = V_93 [ V_92 ] . V_80 ;
V_81 = V_93 [ V_92 ] . V_81 ;
V_82 = V_93 [ V_92 ] . V_82 ;
} else if ( V_4 -> V_72 == V_96 ) {
V_80 = V_81 = V_82 = F_21 ( 256 ) ;
} else if ( V_91 == V_97 ) {
V_80 = V_81 = V_82 = V_4 -> V_98 + F_21 ( 196 ) ;
} else if ( V_91 >= V_99 ) {
V_80 = V_81 = V_82 = V_91 - V_99 ;
}
if ( V_4 -> V_72 == V_75 && V_92 <= V_76 ) {
V_80 = V_100 [ V_4 -> V_27 ] [ V_92 ] . V_80 ;
V_81 = V_100 [ V_4 -> V_27 ] [ V_92 ] . V_81 ;
V_82 = V_100 [ V_4 -> V_27 ] [ V_92 ] . V_82 ;
} else {
V_80 <<= 4 ;
V_81 <<= 4 ;
V_82 <<= 4 ;
}
if ( V_4 -> V_101 == V_102 )
V_80 = V_81 = V_82 = F_13 ( V_4 , V_80 , V_81 , V_82 ) ;
if ( V_4 -> V_103 == V_104 &&
V_4 -> V_105 == V_106 ) {
V_80 = ( V_80 * 219 ) / 255 + ( 16 << 4 ) ;
V_81 = ( V_81 * 219 ) / 255 + ( 16 << 4 ) ;
V_82 = ( V_82 * 219 ) / 255 + ( 16 << 4 ) ;
} else if ( V_4 -> V_103 != V_104 &&
V_4 -> V_105 == V_104 ) {
V_80 = F_17 ( V_80 , 16 << 4 , 235 << 4 ) ;
V_81 = F_17 ( V_81 , 16 << 4 , 235 << 4 ) ;
V_82 = F_17 ( V_82 , 16 << 4 , 235 << 4 ) ;
V_80 = ( V_80 - ( 16 << 4 ) ) * 255 / 219 ;
V_81 = ( V_81 - ( 16 << 4 ) ) * 255 / 219 ;
V_82 = ( V_82 - ( 16 << 4 ) ) * 255 / 219 ;
}
if ( V_4 -> V_17 != 128 || V_4 -> V_18 != 128 ||
V_4 -> V_19 != 128 || V_4 -> V_20 ) {
int V_88 = F_13 ( V_4 , V_80 , V_81 , V_82 ) ;
int V_89 = F_14 ( V_4 , V_80 , V_81 , V_82 ) ;
int V_90 = F_15 ( V_4 , V_80 , V_81 , V_82 ) ;
int V_107 , V_108 ;
V_88 = ( 16 << 4 ) + ( ( V_88 - ( 16 << 4 ) ) * V_4 -> V_18 ) / 128 ;
V_88 += ( V_4 -> V_17 << 4 ) - ( 128 << 4 ) ;
V_89 -= 128 << 4 ;
V_90 -= 128 << 4 ;
V_107 = ( V_89 * cos ( 128 + V_4 -> V_20 ) ) / 127 + ( V_90 * sin [ 128 + V_4 -> V_20 ] ) / 127 ;
V_108 = ( V_90 * cos ( 128 + V_4 -> V_20 ) ) / 127 - ( V_89 * sin [ 128 + V_4 -> V_20 ] ) / 127 ;
V_89 = ( 128 << 4 ) + ( V_107 * V_4 -> V_18 * V_4 -> V_19 ) / ( 128 * 128 ) ;
V_90 = ( 128 << 4 ) + ( V_108 * V_4 -> V_18 * V_4 -> V_19 ) / ( 128 * 128 ) ;
if ( V_4 -> V_57 ) {
V_4 -> V_109 [ V_91 ] [ 0 ] = F_17 ( V_88 >> 4 , 1 , 254 ) ;
V_4 -> V_109 [ V_91 ] [ 1 ] = F_17 ( V_89 >> 4 , 1 , 254 ) ;
V_4 -> V_109 [ V_91 ] [ 2 ] = F_17 ( V_90 >> 4 , 1 , 254 ) ;
return;
}
V_80 = F_16 ( V_4 , V_88 , V_89 , V_90 ) ;
V_81 = F_18 ( V_4 , V_88 , V_89 , V_90 ) ;
V_82 = F_19 ( V_4 , V_88 , V_89 , V_90 ) ;
}
if ( V_4 -> V_57 ) {
T_3 V_88 = F_13 ( V_4 , V_80 , V_81 , V_82 ) ;
T_3 V_89 = F_14 ( V_4 , V_80 , V_81 , V_82 ) ;
T_3 V_90 = F_15 ( V_4 , V_80 , V_81 , V_82 ) ;
V_4 -> V_109 [ V_91 ] [ 0 ] = F_17 ( V_88 >> 4 , 1 , 254 ) ;
V_4 -> V_109 [ V_91 ] [ 1 ] = F_17 ( V_89 >> 4 , 1 , 254 ) ;
V_4 -> V_109 [ V_91 ] [ 2 ] = F_17 ( V_90 >> 4 , 1 , 254 ) ;
} else {
switch ( V_4 -> V_42 ) {
case V_44 :
case V_45 :
V_80 >>= 7 ;
V_81 >>= 6 ;
V_82 >>= 7 ;
break;
case V_46 :
case V_47 :
case V_48 :
case V_49 :
V_80 >>= 7 ;
V_81 >>= 7 ;
V_82 >>= 7 ;
break;
default:
V_80 >>= 4 ;
V_81 >>= 4 ;
V_82 >>= 4 ;
break;
}
V_4 -> V_109 [ V_91 ] [ 0 ] = V_80 ;
V_4 -> V_109 [ V_91 ] [ 1 ] = V_81 ;
V_4 -> V_109 [ V_91 ] [ 2 ] = V_82 ;
}
}
static void F_22 ( struct V_3 * V_4 )
{
int V_91 ;
for ( V_91 = 0 ; V_91 < V_110 ; V_91 ++ )
F_20 ( V_4 , V_91 ) ;
}
static void F_23 ( struct V_3 * V_4 ,
T_1 V_111 [ V_35 ] [ 8 ] , int V_112 , bool V_113 )
{
unsigned V_114 = V_113 * V_4 -> V_64 [ 0 ] / 2 ;
T_1 V_115 = V_4 -> V_116 ;
T_1 V_117 , V_118 , V_119 ;
if ( V_4 -> V_120 && V_112 != V_121 &&
V_112 != V_122 &&
V_112 != V_123 )
V_115 = 0 ;
if ( V_112 == V_97 )
F_20 ( V_4 , V_112 ) ;
V_117 = V_4 -> V_109 [ V_112 ] [ 0 ] ;
V_118 = V_4 -> V_109 [ V_112 ] [ 1 ] ;
V_119 = V_4 -> V_109 [ V_112 ] [ 2 ] ;
switch ( V_4 -> V_42 ) {
case V_58 :
V_111 [ 0 ] [ V_114 ] = V_117 ;
V_111 [ 1 ] [ V_114 ] = V_113 ? V_119 : V_118 ;
break;
case V_59 :
V_111 [ 0 ] [ V_114 ] = V_117 ;
V_111 [ 1 ] [ V_114 ] = V_113 ? V_118 : V_119 ;
break;
case V_60 :
V_111 [ 0 ] [ V_114 ] = V_117 ;
V_111 [ 0 ] [ V_114 + 1 ] = V_113 ? V_119 : V_118 ;
break;
case V_61 :
V_111 [ 0 ] [ V_114 ] = V_113 ? V_119 : V_118 ;
V_111 [ 0 ] [ V_114 + 1 ] = V_117 ;
break;
case V_62 :
V_111 [ 0 ] [ V_114 ] = V_117 ;
V_111 [ 0 ] [ V_114 + 1 ] = V_113 ? V_118 : V_119 ;
break;
case V_63 :
V_111 [ 0 ] [ V_114 ] = V_113 ? V_118 : V_119 ;
V_111 [ 0 ] [ V_114 + 1 ] = V_117 ;
break;
case V_44 :
V_111 [ 0 ] [ V_114 ] = ( V_118 << 5 ) | V_119 ;
V_111 [ 0 ] [ V_114 + 1 ] = ( V_117 << 3 ) | ( V_118 >> 3 ) ;
break;
case V_45 :
V_111 [ 0 ] [ V_114 ] = ( V_117 << 3 ) | ( V_118 >> 3 ) ;
V_111 [ 0 ] [ V_114 + 1 ] = ( V_118 << 5 ) | V_119 ;
break;
case V_46 :
case V_47 :
V_115 = 0 ;
case V_48 :
V_111 [ 0 ] [ V_114 ] = ( V_118 << 5 ) | V_119 ;
V_111 [ 0 ] [ V_114 + 1 ] = ( V_115 & 0x80 ) | ( V_117 << 2 ) | ( V_118 >> 3 ) ;
break;
case V_49 :
V_111 [ 0 ] [ V_114 ] = ( V_115 & 0x80 ) | ( V_117 << 2 ) | ( V_118 >> 3 ) ;
V_111 [ 0 ] [ V_114 + 1 ] = ( V_118 << 5 ) | V_119 ;
break;
case V_26 :
V_111 [ 0 ] [ V_114 ] = V_117 ;
V_111 [ 0 ] [ V_114 + 1 ] = V_118 ;
V_111 [ 0 ] [ V_114 + 2 ] = V_119 ;
break;
case V_50 :
V_111 [ 0 ] [ V_114 ] = V_119 ;
V_111 [ 0 ] [ V_114 + 1 ] = V_118 ;
V_111 [ 0 ] [ V_114 + 2 ] = V_117 ;
break;
case V_51 :
case V_53 :
V_115 = 0 ;
case V_55 :
V_111 [ 0 ] [ V_114 ] = V_115 ;
V_111 [ 0 ] [ V_114 + 1 ] = V_117 ;
V_111 [ 0 ] [ V_114 + 2 ] = V_118 ;
V_111 [ 0 ] [ V_114 + 3 ] = V_119 ;
break;
case V_52 :
case V_54 :
V_115 = 0 ;
case V_56 :
V_111 [ 0 ] [ V_114 ] = V_119 ;
V_111 [ 0 ] [ V_114 + 1 ] = V_118 ;
V_111 [ 0 ] [ V_114 + 2 ] = V_117 ;
V_111 [ 0 ] [ V_114 + 3 ] = V_115 ;
break;
}
}
static unsigned F_24 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_72 ) {
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
return 2 ;
case V_130 :
case V_131 :
return 8 ;
default:
return 1 ;
}
}
static unsigned F_25 ( struct V_3 * V_4 , unsigned line )
{
switch ( V_4 -> V_72 ) {
case V_124 :
return ( line >> 4 ) & 1 ;
case V_125 :
case V_126 :
return line & 1 ;
case V_130 :
case V_131 :
return ( line * 8 ) / V_4 -> V_9 ;
case V_127 :
return line == V_4 -> V_9 / 2 ;
case V_128 :
return ( line + 1 ) / 2 == V_4 -> V_9 / 4 ;
case V_129 :
return ( line + 10 ) / 20 == V_4 -> V_9 / 40 ;
default:
return 0 ;
}
}
static enum V_71 F_26 ( struct V_3 * V_4 , unsigned V_132 , unsigned V_133 )
{
static const enum V_71 V_134 [ 3 ] [ 8 ] = {
{ V_79 , V_135 ,
V_136 , V_137 ,
V_138 , V_123 ,
V_139 , V_77 , } ,
{ V_74 , V_140 ,
V_141 , V_142 ,
V_143 , V_122 ,
V_144 , V_77 , } ,
{ V_79 , V_145 ,
V_146 , V_147 ,
V_148 , V_121 ,
V_149 , V_76 , } ,
} ;
switch ( V_4 -> V_72 ) {
case V_78 :
case V_150 :
case V_75 :
return V_134 [ V_4 -> V_72 ] [ ( ( V_133 * 8 ) / V_4 -> V_8 ) % 8 ] ;
case V_130 :
return V_134 [ 1 ] [ ( V_132 + ( V_133 * 8 ) / V_4 -> V_8 ) % 8 ] ;
case V_131 :
return V_134 [ 1 ] [ V_132 ] ;
case V_73 :
return V_77 ;
case V_151 :
return V_74 ;
case V_152 :
return V_122 ;
case V_153 :
return V_142 ;
case V_154 :
return V_144 ;
case V_124 :
return ( ( ( V_133 >> 4 ) & 1 ) ^ ( V_132 & 1 ) ) ?
V_77 : V_74 ;
case V_125 :
return ( ( V_133 & 1 ) ^ ( V_132 & 1 ) ) ?
V_74 : V_77 ;
case V_126 :
return V_132 ? V_74 : V_77 ;
case V_155 :
return ( V_133 & 1 ) ? V_74 : V_77 ;
case V_127 :
if ( V_132 || ( V_133 % V_4 -> V_8 ) == V_4 -> V_8 / 2 )
return V_77 ;
return V_74 ;
case V_128 :
if ( V_132 || ( ( V_133 % V_4 -> V_8 ) + 1 ) / 2 == V_4 -> V_8 / 4 )
return V_77 ;
return V_74 ;
case V_129 :
if ( V_132 || ( ( V_133 % V_4 -> V_8 ) + 10 ) / 20 == V_4 -> V_8 / 40 )
return V_77 ;
return V_74 ;
case V_156 :
return V_99 + ( ( V_133 % V_4 -> V_8 ) * 256 ) / V_4 -> V_8 ;
default:
return V_122 ;
}
}
static void F_27 ( struct V_3 * V_4 )
{
unsigned V_5 = V_4 -> V_8 ;
unsigned V_6 = V_4 -> V_9 ;
unsigned V_157 , V_158 ;
V_157 = ( V_5 * 2 / 5 ) & ~ 1 ;
if ( ( ( V_5 - V_157 ) / 2 ) & 1 )
V_157 += 2 ;
V_158 = V_157 ;
V_4 -> V_159 . V_12 = V_157 ;
if ( V_4 -> V_160 == V_161 ) {
unsigned V_162 = ( V_157 / 4 ) * 3 ;
if ( ( ( V_5 - V_162 ) / 2 ) & 1 )
V_162 += 2 ;
V_4 -> V_159 . V_12 = V_162 ;
}
V_4 -> V_159 . V_69 = ( V_5 - V_4 -> V_159 . V_12 ) / 2 ;
if ( V_4 -> V_163 == V_164 )
V_158 = V_157 * 10 / 11 ;
else if ( V_4 -> V_163 == V_165 )
V_158 = V_157 * 59 / 54 ;
V_4 -> V_159 . V_14 = V_158 ;
V_4 -> V_159 . V_68 = ( V_6 - V_158 ) / 2 ;
V_4 -> V_166 . V_69 = 0 ;
V_4 -> V_166 . V_12 = V_5 ;
V_4 -> V_166 . V_68 = 0 ;
V_4 -> V_166 . V_14 = V_6 ;
switch ( V_4 -> V_160 ) {
case V_167 :
if ( V_4 -> V_163 )
return;
if ( 3 * V_5 >= 4 * V_6 ) {
V_4 -> V_166 . V_12 = ( ( 4 * V_6 ) / 3 ) & ~ 1 ;
if ( ( ( V_5 - V_4 -> V_166 . V_12 ) / 2 ) & ~ 1 )
V_4 -> V_166 . V_12 -= 2 ;
V_4 -> V_166 . V_69 = ( V_5 - V_4 -> V_166 . V_12 ) / 2 ;
break;
}
V_4 -> V_166 . V_14 = ( ( 3 * V_5 ) / 4 ) & ~ 1 ;
V_4 -> V_166 . V_68 = ( V_6 - V_4 -> V_166 . V_14 ) / 2 ;
break;
case V_168 :
if ( V_4 -> V_163 ) {
V_4 -> V_166 . V_14 = V_4 -> V_163 == V_164 ? 420 : 506 ;
V_4 -> V_166 . V_68 = ( V_6 - V_4 -> V_166 . V_14 ) / 2 ;
break;
}
if ( 9 * V_5 >= 14 * V_6 ) {
V_4 -> V_166 . V_12 = ( ( 14 * V_6 ) / 9 ) & ~ 1 ;
if ( ( ( V_5 - V_4 -> V_166 . V_12 ) / 2 ) & ~ 1 )
V_4 -> V_166 . V_12 -= 2 ;
V_4 -> V_166 . V_69 = ( V_5 - V_4 -> V_166 . V_12 ) / 2 ;
break;
}
V_4 -> V_166 . V_14 = ( ( 9 * V_5 ) / 14 ) & ~ 1 ;
V_4 -> V_166 . V_68 = ( V_6 - V_4 -> V_166 . V_14 ) / 2 ;
break;
case V_169 :
if ( V_4 -> V_163 ) {
V_4 -> V_166 . V_14 = V_4 -> V_163 == V_164 ? 368 : 442 ;
V_4 -> V_166 . V_68 = ( V_6 - V_4 -> V_166 . V_14 ) / 2 ;
break;
}
if ( 9 * V_5 >= 16 * V_6 ) {
V_4 -> V_166 . V_12 = ( ( 16 * V_6 ) / 9 ) & ~ 1 ;
if ( ( ( V_5 - V_4 -> V_166 . V_12 ) / 2 ) & ~ 1 )
V_4 -> V_166 . V_12 -= 2 ;
V_4 -> V_166 . V_69 = ( V_5 - V_4 -> V_166 . V_12 ) / 2 ;
break;
}
V_4 -> V_166 . V_14 = ( ( 9 * V_5 ) / 16 ) & ~ 1 ;
V_4 -> V_166 . V_68 = ( V_6 - V_4 -> V_166 . V_14 ) / 2 ;
break;
default:
break;
}
}
static void F_28 ( struct V_3 * V_4 )
{
enum V_71 V_18 ;
unsigned V_31 ;
unsigned V_67 ;
unsigned V_133 ;
switch ( V_4 -> V_72 ) {
case V_153 :
V_18 = V_122 ;
break;
case V_75 :
V_18 = V_147 ;
break;
default:
V_18 = V_142 ;
break;
}
for ( V_31 = 0 ; V_31 < F_24 ( V_4 ) ; V_31 ++ ) {
unsigned V_170 = V_4 -> V_8 / V_4 -> V_7 ;
unsigned V_171 = V_4 -> V_8 % V_4 -> V_7 ;
unsigned V_172 = 0 ;
unsigned error = 0 ;
for ( V_133 = 0 ; V_133 < V_4 -> V_7 * 2 ; V_133 += 2 ) {
unsigned V_173 = V_172 ;
enum V_71 V_174 , V_175 ;
T_1 V_176 [ V_35 ] [ 8 ] ;
V_173 = V_4 -> V_177 ? V_4 -> V_8 * 2 - V_173 - 2 : V_173 ;
V_174 = F_26 ( V_4 , V_31 , V_173 ) ;
V_172 += V_170 ;
error += V_171 ;
if ( error >= V_4 -> V_7 ) {
error -= V_4 -> V_7 ;
V_172 ++ ;
}
V_173 = V_172 ;
V_173 = V_4 -> V_177 ? V_4 -> V_8 * 2 - V_173 - 2 : V_173 ;
V_175 = F_26 ( V_4 , V_31 , V_173 ) ;
V_172 += V_170 ;
error += V_171 ;
if ( error >= V_4 -> V_7 ) {
error -= V_4 -> V_7 ;
V_172 ++ ;
}
F_23 ( V_4 , V_176 , V_4 -> V_177 ? V_175 : V_174 , 0 ) ;
F_23 ( V_4 , V_176 , V_4 -> V_177 ? V_174 : V_175 , 1 ) ;
for ( V_67 = 0 ; V_67 < V_4 -> V_43 ; V_67 ++ ) {
unsigned V_178 = V_4 -> V_64 [ V_67 ] ;
T_1 * V_179 = V_4 -> V_37 [ V_31 ] [ V_67 ] + V_133 * V_178 / 2 ;
memcpy ( V_179 , V_176 [ V_67 ] , V_178 ) ;
}
}
}
for ( V_133 = 0 ; V_133 < V_4 -> V_7 ; V_133 += 2 ) {
T_1 V_176 [ V_35 ] [ 8 ] ;
F_23 ( V_4 , V_176 , V_18 , 0 ) ;
F_23 ( V_4 , V_176 , V_18 , 1 ) ;
for ( V_67 = 0 ; V_67 < V_4 -> V_43 ; V_67 ++ ) {
unsigned V_178 = V_4 -> V_64 [ V_67 ] ;
T_1 * V_179 = V_4 -> V_39 [ V_67 ] + V_133 * V_178 / 2 ;
memcpy ( V_179 , V_176 [ V_67 ] , V_178 ) ;
}
}
for ( V_133 = 0 ; V_133 < V_4 -> V_7 ; V_133 += 2 ) {
T_1 V_176 [ V_35 ] [ 8 ] ;
F_23 ( V_4 , V_176 , V_77 , 0 ) ;
F_23 ( V_4 , V_176 , V_77 , 1 ) ;
for ( V_67 = 0 ; V_67 < V_4 -> V_43 ; V_67 ++ ) {
unsigned V_178 = V_4 -> V_64 [ V_67 ] ;
T_1 * V_179 = V_4 -> V_40 [ V_67 ] + V_133 * V_178 / 2 ;
memcpy ( V_179 , V_176 [ V_67 ] , V_178 ) ;
}
}
for ( V_133 = 0 ; V_133 < V_4 -> V_7 * 2 ; V_133 += 2 ) {
T_1 V_176 [ V_35 ] [ 8 ] ;
F_23 ( V_4 , V_176 , V_97 , 0 ) ;
F_23 ( V_4 , V_176 , V_97 , 1 ) ;
for ( V_67 = 0 ; V_67 < V_4 -> V_43 ; V_67 ++ ) {
unsigned V_178 = V_4 -> V_64 [ V_67 ] ;
T_1 * V_179 = V_4 -> V_41 [ V_67 ] + V_133 * V_178 / 2 ;
memcpy ( V_179 , V_176 [ V_67 ] , V_178 ) ;
}
}
F_23 ( V_4 , V_4 -> V_180 , V_94 , 0 ) ;
F_23 ( V_4 , V_4 -> V_180 , V_94 , 1 ) ;
F_23 ( V_4 , V_4 -> V_181 , V_95 , 0 ) ;
F_23 ( V_4 , V_4 -> V_181 , V_95 , 1 ) ;
}
void F_29 ( struct V_3 * V_4 , T_1 * V_182 [ V_35 ] [ 2 ] ,
int V_88 , int V_133 , char * V_183 )
{
int line ;
unsigned V_184 = F_10 ( V_4 -> V_24 ) ? 2 : 1 ;
unsigned div = V_184 ;
unsigned V_185 = 0 ;
unsigned V_186 = strlen ( V_183 ) ;
unsigned V_67 ;
if ( V_2 == NULL || V_182 == NULL )
return;
if ( V_88 + 16 >= V_4 -> V_13 . V_14 || V_133 + 8 >= V_4 -> V_13 . V_12 )
return;
if ( V_186 > ( V_4 -> V_13 . V_12 - V_133 ) / 8 )
V_186 = ( V_4 -> V_13 . V_12 - V_133 ) / 8 ;
if ( V_4 -> V_187 )
V_88 = V_4 -> V_13 . V_14 - V_88 - 16 ;
if ( V_4 -> V_177 )
V_133 = V_4 -> V_13 . V_12 - V_133 - 8 ;
V_88 += V_4 -> V_13 . V_68 ;
V_133 += V_4 -> V_13 . V_69 ;
if ( V_4 -> V_24 == V_188 )
V_185 = 1 ;
else if ( V_4 -> V_24 == V_189 || V_4 -> V_24 == V_190 )
div = 2 ;
for ( V_67 = 0 ; V_67 < V_4 -> V_43 ; V_67 ++ ) {
#define F_30 ( T_4 ) do { \
PIXTYPE fg; \
PIXTYPE bg; \
memcpy(&fg, tpg->textfg[p], sizeof(PIXTYPE)); \
memcpy(&bg, tpg->textbg[p], sizeof(PIXTYPE)); \
\
for (line = first; line < 16; line += step) { \
int l = tpg->vflip ? 15 - line : line; \
PIXTYPE *pos = (PIXTYPE *)(basep[p][line & 1] + \
((y * step + l) / div) * tpg->bytesperline[p] + \
x * sizeof(PIXTYPE)); \
unsigned s; \
\
for (s = 0; s < len; s++) { \
u8 chr = font8x16[text[s] * 16 + line]; \
\
if (tpg->hflip) { \
pos[7] = (chr & (0x01 << 7) ? fg : bg); \
pos[6] = (chr & (0x01 << 6) ? fg : bg); \
pos[5] = (chr & (0x01 << 5) ? fg : bg); \
pos[4] = (chr & (0x01 << 4) ? fg : bg); \
pos[3] = (chr & (0x01 << 3) ? fg : bg); \
pos[2] = (chr & (0x01 << 2) ? fg : bg); \
pos[1] = (chr & (0x01 << 1) ? fg : bg); \
pos[0] = (chr & (0x01 << 0) ? fg : bg); \
} else { \
pos[0] = (chr & (0x01 << 7) ? fg : bg); \
pos[1] = (chr & (0x01 << 6) ? fg : bg); \
pos[2] = (chr & (0x01 << 5) ? fg : bg); \
pos[3] = (chr & (0x01 << 4) ? fg : bg); \
pos[4] = (chr & (0x01 << 3) ? fg : bg); \
pos[5] = (chr & (0x01 << 2) ? fg : bg); \
pos[6] = (chr & (0x01 << 1) ? fg : bg); \
pos[7] = (chr & (0x01 << 0) ? fg : bg); \
} \
\
pos += tpg->hflip ? -8 : 8; \
} \
} \
} while (0)
switch ( V_4 -> V_64 [ V_67 ] ) {
case 2 :
F_30 ( T_1 ) ; break;
case 4 :
F_30 ( T_3 ) ; break;
case 6 :
F_30 ( V_191 ) ; break;
case 8 :
F_30 ( T_2 ) ; break;
}
}
}
void F_31 ( struct V_3 * V_4 )
{
int V_192 = V_4 -> V_21 > V_22 ? - 1 : 1 ;
if ( V_4 -> V_177 )
V_192 = - V_192 ;
switch ( V_4 -> V_21 ) {
case V_193 :
case V_194 :
V_4 -> V_195 = ( ( V_4 -> V_8 + 319 ) / 320 ) * 4 ;
break;
case V_196 :
case V_197 :
V_4 -> V_195 = ( ( V_4 -> V_8 + 639 ) / 640 ) * 4 ;
break;
case V_198 :
case V_199 :
V_4 -> V_195 = 2 ;
break;
case V_22 :
V_4 -> V_195 = 0 ;
break;
}
if ( V_192 < 0 )
V_4 -> V_195 = V_4 -> V_8 - V_4 -> V_195 ;
V_192 = V_4 -> V_23 > V_22 ? - 1 : 1 ;
switch ( V_4 -> V_23 ) {
case V_193 :
case V_194 :
V_4 -> V_200 = ( ( V_4 -> V_8 + 319 ) / 320 ) * 4 ;
break;
case V_196 :
case V_197 :
V_4 -> V_200 = ( ( V_4 -> V_8 + 639 ) / 640 ) * 4 ;
break;
case V_198 :
case V_199 :
V_4 -> V_200 = 1 ;
break;
case V_22 :
V_4 -> V_200 = 0 ;
break;
}
if ( V_192 < 0 )
V_4 -> V_200 = V_4 -> V_9 - V_4 -> V_200 ;
}
static unsigned F_32 ( struct V_3 * V_4 , unsigned V_201 ,
unsigned V_24 )
{
switch ( V_24 ) {
case V_202 :
return V_4 -> V_11 . V_68 + V_201 * 2 ;
case V_188 :
return V_4 -> V_11 . V_68 + V_201 * 2 + 1 ;
default:
return V_201 + V_4 -> V_11 . V_68 ;
}
}
static unsigned F_33 ( struct V_3 * V_4 , unsigned V_88 ,
unsigned V_24 )
{
V_88 += V_4 -> V_13 . V_68 ;
switch ( V_24 ) {
case V_189 :
if ( V_88 & 1 )
return V_4 -> V_10 / 2 + V_88 / 2 ;
return V_88 / 2 ;
case V_190 :
if ( V_88 & 1 )
return V_88 / 2 ;
return V_4 -> V_10 / 2 + V_88 / 2 ;
default:
return V_88 ;
}
}
static void F_34 ( struct V_3 * V_4 )
{
if ( V_4 -> V_15 ) {
V_4 -> V_15 = false ;
V_4 -> V_66 = true ;
F_22 ( V_4 ) ;
}
if ( V_4 -> V_16 ) {
V_4 -> V_16 = false ;
F_27 ( V_4 ) ;
}
if ( V_4 -> V_66 ) {
V_4 -> V_66 = false ;
F_28 ( V_4 ) ;
}
}
void F_35 ( struct V_3 * V_4 ,
T_1 * V_182 [ V_35 ] [ 2 ] , unsigned V_67 , T_1 * V_203 )
{
unsigned V_204 = V_4 -> V_70 [ V_67 ] ;
F_34 ( V_4 ) ;
V_182 [ V_67 ] [ 0 ] = V_203 ;
V_182 [ V_67 ] [ 1 ] = V_203 ;
if ( V_4 -> V_24 == V_189 )
V_182 [ V_67 ] [ 1 ] += V_4 -> V_10 * V_204 / 2 ;
else if ( V_4 -> V_24 == V_190 )
V_182 [ V_67 ] [ 0 ] += V_4 -> V_10 * V_204 / 2 ;
}
void F_36 ( struct V_3 * V_4 , T_5 V_205 , unsigned V_67 , T_1 * V_203 )
{
bool V_206 = V_205 ;
bool V_207 = V_206 && ( V_205 & V_208 ) ;
unsigned V_209 = V_4 -> V_210 % V_4 -> V_8 ;
unsigned V_211 = ( V_4 -> V_210 + V_4 -> V_195 ) % V_4 -> V_8 ;
unsigned V_212 = V_4 -> V_213 % V_4 -> V_9 ;
unsigned V_214 = ( V_4 -> V_213 + V_4 -> V_200 ) % V_4 -> V_9 ;
unsigned V_215 ;
unsigned V_1 ;
int V_216 = ( V_4 -> V_13 . V_14 * V_4 -> V_29 ) / 100 ;
int V_6 ;
unsigned V_178 = V_4 -> V_64 [ V_67 ] ;
unsigned V_217 = V_4 -> V_13 . V_12 * V_178 / 2 ;
unsigned V_218 ;
unsigned V_219 = 0 ;
unsigned V_220 = V_217 ;
unsigned V_204 = V_4 -> V_70 [ V_67 ] ;
unsigned V_192 = F_10 ( V_4 -> V_24 ) ? 2 : 1 ;
T_1 * V_221 = V_203 ;
unsigned V_170 = ( V_4 -> V_11 . V_14 / V_192 ) / V_4 -> V_13 . V_14 ;
unsigned V_171 = ( V_4 -> V_11 . V_14 / V_192 ) % V_4 -> V_13 . V_14 ;
unsigned V_201 = 0 ;
unsigned error = 0 ;
F_34 ( V_4 ) ;
V_209 = ( V_209 * V_4 -> V_7 / V_4 -> V_8 ) & ~ 1 ;
V_211 = ( V_211 * V_4 -> V_7 / V_4 -> V_8 ) & ~ 1 ;
V_215 = V_4 -> V_11 . V_69 < V_4 -> V_8 / 2 ?
V_4 -> V_8 / 2 - V_4 -> V_11 . V_69 : 0 ;
if ( V_215 > V_4 -> V_11 . V_12 )
V_215 = V_4 -> V_11 . V_12 ;
V_215 = V_215 * V_4 -> V_7 / V_4 -> V_8 ;
V_203 += V_4 -> V_13 . V_69 * V_178 / 2 ;
V_218 = V_4 -> V_11 . V_69 * V_4 -> V_7 / V_4 -> V_8 ;
V_218 = ( V_218 & ~ 1 ) * V_178 / 2 ;
if ( V_4 -> V_11 . V_69 < V_4 -> V_166 . V_69 ) {
V_219 = V_4 -> V_166 . V_69 - V_4 -> V_11 . V_69 ;
if ( V_219 > V_4 -> V_11 . V_12 )
V_219 = V_4 -> V_11 . V_12 ;
V_219 = ( V_219 * V_4 -> V_7 ) / V_4 -> V_8 ;
V_219 = ( V_219 & ~ 1 ) * V_178 / 2 ;
}
if ( V_4 -> V_11 . V_69 + V_4 -> V_11 . V_12 > V_4 -> V_166 . V_69 + V_4 -> V_166 . V_12 ) {
V_220 = V_4 -> V_166 . V_69 + V_4 -> V_166 . V_12 - V_4 -> V_11 . V_69 ;
V_220 = ( V_220 * V_4 -> V_7 ) / V_4 -> V_8 ;
V_220 = ( V_220 & ~ 1 ) * V_178 / 2 ;
if ( V_220 > V_217 )
V_220 = V_217 ;
}
V_1 = V_4 -> V_24 == ( V_207 ? V_202 : V_188 ) ;
for ( V_6 = 0 ; V_6 < V_4 -> V_13 . V_14 ; V_6 ++ ) {
bool V_222 ;
bool V_223 = false ;
unsigned V_224 ;
unsigned V_225 ;
unsigned V_226 ;
unsigned V_227 ;
T_1 * V_228 ;
T_1 * V_229 ;
T_1 * V_230 ;
T_1 * V_231 ;
V_224 = F_32 ( V_4 , V_201 , V_4 -> V_24 ) ;
V_222 = ! ( V_224 & 1 ) ;
V_225 = F_33 ( V_4 , V_6 , V_4 -> V_24 ) ;
V_201 += V_170 ;
error += V_171 ;
if ( error >= V_4 -> V_13 . V_14 ) {
error -= V_4 -> V_13 . V_14 ;
V_201 ++ ;
}
if ( V_6 >= V_216 ) {
if ( V_216 == V_4 -> V_13 . V_14 )
continue;
if ( ! V_4 -> V_232 )
continue;
V_223 = true ;
}
if ( V_4 -> V_187 )
V_224 = V_4 -> V_9 - V_224 - 1 ;
if ( V_223 ) {
V_228 = V_4 -> V_39 [ V_67 ] ;
V_229 = V_4 -> V_39 [ V_67 ] ;
} else if ( V_4 -> V_101 != V_233 &&
( V_224 < V_4 -> V_166 . V_68 ||
V_224 >= V_4 -> V_166 . V_68 + V_4 -> V_166 . V_14 ) ) {
V_228 = V_4 -> V_40 [ V_67 ] ;
V_229 = V_4 -> V_40 [ V_67 ] ;
} else if ( V_4 -> V_72 == V_96 || V_4 -> V_101 == V_233 ) {
V_228 = V_4 -> V_41 [ V_67 ] +
V_178 * F_21 ( V_4 -> V_8 / 2 ) ;
V_229 = V_4 -> V_41 [ V_67 ] +
V_178 * F_21 ( V_4 -> V_8 / 2 ) ;
} else {
V_226 = F_25 ( V_4 ,
( V_224 + V_212 ) % V_4 -> V_9 ) ;
V_227 = F_25 ( V_4 ,
( V_224 + V_214 ) % V_4 -> V_9 ) ;
V_228 = V_4 -> V_37 [ V_226 ] [ V_67 ] +
V_209 * V_178 / 2 ;
V_229 = V_4 -> V_37 [ V_227 ] [ V_67 ] +
V_211 * V_178 / 2 ;
V_228 += V_218 ;
V_229 += V_218 ;
}
if ( V_207 ) {
V_230 = V_229 ;
V_231 = V_228 ;
} else {
V_230 = V_228 ;
V_231 = V_229 ;
}
switch ( V_4 -> V_24 ) {
case V_234 :
case V_235 :
case V_189 :
case V_190 :
if ( V_222 )
memcpy ( V_203 + V_225 * V_204 , V_230 , V_217 ) ;
else
memcpy ( V_203 + V_225 * V_204 , V_231 , V_217 ) ;
break;
case V_236 :
if ( V_222 )
memcpy ( V_203 + V_225 * V_204 , V_231 , V_217 ) ;
else
memcpy ( V_203 + V_225 * V_204 , V_230 , V_217 ) ;
break;
case V_202 :
memcpy ( V_203 + V_225 * V_204 , V_230 , V_217 ) ;
break;
case V_188 :
memcpy ( V_203 + V_225 * V_204 , V_231 , V_217 ) ;
break;
case V_25 :
default:
memcpy ( V_203 + V_225 * V_204 , V_228 , V_217 ) ;
break;
}
if ( V_206 && ! V_207 && V_224 == 0 && V_215 ) {
T_1 * V_237 = V_4 -> V_41 [ V_67 ] +
V_178 * F_21 ( V_4 -> V_8 / 2 ) ;
memcpy ( V_203 + V_225 * V_204 , V_237 , V_215 * V_178 / 2 ) ;
}
}
V_203 = V_221 ;
V_203 += V_4 -> V_13 . V_69 * V_178 / 2 ;
V_201 = 0 ;
error = 0 ;
for ( V_6 = 0 ; V_6 < V_4 -> V_13 . V_14 ; V_6 ++ ) {
unsigned V_224 = F_32 ( V_4 , V_201 , V_4 -> V_24 ) ;
unsigned V_225 = F_33 ( V_4 , V_6 , V_4 -> V_24 ) ;
const struct V_65 * V_238 = & V_4 -> V_159 ;
const struct V_65 * V_82 = & V_4 -> V_166 ;
const struct V_65 * V_239 = & V_4 -> V_11 ;
V_201 += V_170 ;
error += V_171 ;
if ( error >= V_4 -> V_13 . V_14 ) {
error -= V_4 -> V_13 . V_14 ;
V_201 ++ ;
}
if ( V_4 -> V_240 && V_224 >= V_82 -> V_68 &&
V_224 < V_82 -> V_68 + V_82 -> V_14 ) {
unsigned V_241 = V_82 -> V_68 + V_82 -> V_14 - 1 ;
unsigned V_69 = V_219 ;
unsigned V_242 = V_220 ;
if ( V_224 == V_82 -> V_68 || V_224 == V_82 -> V_68 + 1 ||
V_224 == V_241 || V_224 == V_241 - 1 ) {
memcpy ( V_203 + V_225 * V_204 + V_69 , V_4 -> V_39 [ V_67 ] ,
V_242 - V_69 ) ;
} else {
if ( V_82 -> V_69 >= V_239 -> V_69 &&
V_82 -> V_69 < V_239 -> V_69 + V_239 -> V_12 )
memcpy ( V_203 + V_225 * V_204 + V_69 ,
V_4 -> V_39 [ V_67 ] , V_178 ) ;
if ( V_82 -> V_69 + V_82 -> V_12 > V_239 -> V_69 &&
V_82 -> V_69 + V_82 -> V_12 <= V_239 -> V_69 + V_239 -> V_12 )
memcpy ( V_203 + V_225 * V_204 + V_242 - V_178 ,
V_4 -> V_39 [ V_67 ] , V_178 ) ;
}
}
if ( V_4 -> V_101 != V_233 && V_224 >= V_82 -> V_68 &&
V_224 < V_82 -> V_68 + V_82 -> V_14 ) {
memcpy ( V_203 + V_225 * V_204 , V_4 -> V_40 [ V_67 ] , V_219 ) ;
memcpy ( V_203 + V_225 * V_204 + V_220 , V_4 -> V_40 [ V_67 ] ,
V_217 - V_220 ) ;
}
if ( V_4 -> V_243 && V_224 >= V_238 -> V_68 &&
V_224 < V_238 -> V_68 + V_238 -> V_14 &&
V_238 -> V_69 < V_239 -> V_69 + V_239 -> V_12 &&
V_238 -> V_69 + V_238 -> V_12 >= V_239 -> V_69 ) {
unsigned V_69 = V_238 -> V_69 ;
unsigned V_12 = V_238 -> V_12 ;
if ( V_239 -> V_69 > V_69 ) {
V_12 -= V_239 -> V_69 - V_69 ;
V_69 = V_239 -> V_69 ;
}
if ( V_239 -> V_69 + V_239 -> V_12 < V_69 + V_12 )
V_12 -= V_69 + V_12 - V_239 -> V_69 - V_239 -> V_12 ;
V_69 -= V_239 -> V_69 ;
V_69 = ( V_69 * V_4 -> V_7 ) / V_4 -> V_8 ;
V_69 = ( V_69 & ~ 1 ) * V_178 / 2 ;
V_12 = ( V_12 * V_4 -> V_7 ) / V_4 -> V_8 ;
V_12 = ( V_12 & ~ 1 ) * V_178 / 2 ;
memcpy ( V_203 + V_225 * V_204 + V_69 , V_4 -> V_39 [ V_67 ] , V_12 ) ;
}
if ( V_4 -> V_244 ) {
unsigned V_114 = ( V_4 -> V_13 . V_12 / 6 ) * V_178 ;
T_1 * V_67 = V_203 + V_225 * V_204 + V_114 ;
unsigned V_245 = 0 , V_246 = 0 ;
V_67 [ 0 ] = 0xff ;
V_67 [ 1 ] = 0 ;
V_67 [ 2 ] = 0 ;
V_67 [ 3 ] = 0x80 | ( V_1 << 6 ) | ( V_245 << 5 ) | ( V_246 << 4 ) |
( ( V_246 ^ V_245 ) << 3 ) |
( ( V_246 ^ V_1 ) << 2 ) |
( ( V_1 ^ V_245 ) << 1 ) |
( V_246 ^ V_245 ^ V_1 ) ;
}
if ( V_4 -> V_247 ) {
unsigned V_114 = ( V_4 -> V_13 . V_12 / 6 ) * 2 * V_178 ;
T_1 * V_67 = V_203 + V_225 * V_204 + V_114 ;
unsigned V_245 = 0 , V_246 = 1 ;
V_67 [ 0 ] = 0xff ;
V_67 [ 1 ] = 0 ;
V_67 [ 2 ] = 0 ;
V_67 [ 3 ] = 0x80 | ( V_1 << 6 ) | ( V_245 << 5 ) | ( V_246 << 4 ) |
( ( V_246 ^ V_245 ) << 3 ) |
( ( V_246 ^ V_1 ) << 2 ) |
( ( V_1 ^ V_245 ) << 1 ) |
( V_246 ^ V_245 ^ V_1 ) ;
}
}
}
