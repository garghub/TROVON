static unsigned char F_1 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned short V_4 , int V_5 )
{
if ( V_4 < 3 )
return 0xff ;
if ( V_4 > 11 )
return 0xff ;
if ( V_2 -> V_6 )
return V_7 ;
if ( V_2 -> V_8 == V_9 )
return V_10 [ V_5 ] [ V_2 -> V_11 [ V_5 ] . V_12 [ V_3 ] ] [ V_4 - 3 ] ;
else
return V_13 [ V_4 - 3 ] ;
}
static int F_2 ( struct V_14 * V_15 , unsigned short V_16 )
{
unsigned short V_17 , V_18 , V_19 , V_20 ;
unsigned int V_21 ;
if ( ! ( V_15 -> V_22 & V_23 ) )
return - V_24 ;
if ( V_15 -> V_25 & V_26 ) {
switch ( V_16 ) {
case 48000 : V_18 = 0 ; break;
case 44100 : V_18 = 1 << V_27 ; break;
default:
F_3 ( V_15 , V_28 , V_29 , 0 ) ;
return - V_30 ;
}
V_19 = V_31 ;
V_20 = 1 << V_27 ;
} else {
if ( V_15 -> V_32 == V_33 && V_16 != 48000 ) {
F_3 ( V_15 , V_28 , V_29 , 0 ) ;
return - V_30 ;
}
switch ( V_16 ) {
case 44100 : V_18 = V_34 ; break;
case 48000 : V_18 = V_35 ; break;
case 32000 : V_18 = V_36 ; break;
default:
F_3 ( V_15 , V_28 , V_29 , 0 ) ;
return - V_30 ;
}
V_19 = V_7 ;
V_20 = V_37 ;
}
F_4 ( & V_15 -> V_38 ) ;
V_17 = F_5 ( V_15 , V_19 ) & V_20 ;
if ( V_17 != V_18 ) {
F_6 ( V_15 , V_28 , V_29 , 0 ) ;
F_6 ( V_15 , V_19 , V_20 , V_18 ) ;
V_21 = V_15 -> V_39 ;
if ( V_21 & V_40 ) {
V_21 &= ~ V_41 ;
switch ( V_16 ) {
case 44100 : V_21 |= V_42 ; break;
case 48000 : V_21 |= V_43 ; break;
case 32000 : V_21 |= V_44 ; break;
}
} else {
V_21 &= ~ ( V_45 << 24 ) ;
switch ( V_16 ) {
case 44100 : V_21 |= V_46 << 24 ; break;
case 48000 : V_21 |= V_47 << 24 ; break;
case 32000 : V_21 |= V_48 << 24 ; break;
}
}
V_15 -> V_39 = V_21 ;
}
F_6 ( V_15 , V_28 , V_29 , V_29 ) ;
F_7 ( & V_15 -> V_38 ) ;
return 0 ;
}
int F_8 ( struct V_14 * V_15 , int V_19 , unsigned int V_16 )
{
int V_5 ;
unsigned int V_49 ;
V_5 = V_16 > 48000 ;
if ( V_5 ) {
if ( ! ( V_15 -> V_25 & V_50 ) )
return - V_30 ;
if ( V_19 != V_51 )
return - V_30 ;
}
F_9 ( V_15 , V_19 , 1 ) ;
switch ( V_19 ) {
case V_52 :
if ( ( V_15 -> V_53 [ V_28 ] & V_54 ) == 0 )
if ( V_16 != 48000 )
return - V_30 ;
break;
case V_51 :
case V_55 :
if ( ( V_15 -> V_53 [ V_28 ] & V_56 ) == 0 )
if ( V_16 != 48000 && V_16 != 96000 )
return - V_30 ;
break;
case V_57 :
if ( ! ( V_15 -> V_58 & V_59 ) )
return - V_30 ;
break;
case V_60 :
if ( ! ( V_15 -> V_58 & V_61 ) )
return - V_30 ;
break;
case V_7 :
return F_2 ( V_15 , V_16 ) ;
default:
return - V_30 ;
}
if ( V_5 )
V_16 /= 2 ;
V_49 = ( V_16 * V_15 -> V_62 -> clock ) / 48000 ;
if ( V_49 > 65535 )
return - V_30 ;
if ( ( V_15 -> V_22 & V_63 ) && V_19 == V_51 )
F_3 ( V_15 , V_28 ,
V_64 , V_5 ? V_64 : 0 ) ;
F_10 ( V_15 , V_19 , V_49 & 0xffff ) ;
F_5 ( V_15 , V_19 ) ;
if ( ( V_15 -> V_22 & V_63 ) && V_19 == V_51 ) {
F_3 ( V_15 , V_65 ,
V_66 ,
V_5 ? V_67 : 0 ) ;
F_5 ( V_15 , V_65 ) ;
}
return 0 ;
}
static unsigned short F_11 ( struct V_14 * V_15 , unsigned char * V_12 , unsigned short * V_68 )
{
if ( ! F_12 ( V_15 ) )
return 0 ;
if ( F_13 ( V_15 ) || F_14 ( V_15 ) ) {
unsigned short V_69 = 0 ;
if ( F_13 ( V_15 ) ) {
T_1 V_70 ;
V_70 = V_15 -> V_53 [ V_71 ] &= ~ V_72 ;
switch ( V_15 -> V_73 ) {
case 1 :
case 2 : V_70 |= ( 1 << V_74 ) ; break;
case 3 : V_70 |= ( 2 << V_74 ) ; break;
}
F_15 ( V_15 , V_71 , V_70 ) ;
}
switch ( V_15 -> V_73 ) {
case 0 :
V_69 |= ( 1 << V_75 ) | ( 1 << V_76 ) ;
if ( V_15 -> V_58 & V_59 )
V_69 |= ( 1 << V_77 ) | ( 1 << V_78 ) ;
if ( V_15 -> V_58 & V_61 )
V_69 |= ( 1 << V_79 ) | ( 1 << V_80 ) ;
if ( V_15 -> V_22 & V_23 ) {
if ( ! ( V_15 -> V_58 & V_59 ) )
* V_68 = ( 1 << V_81 ) | ( 1 << V_82 ) ;
else if ( ! ( V_15 -> V_58 & V_61 ) )
* V_68 = ( 1 << V_83 ) | ( 1 << V_84 ) ;
else
* V_68 = ( 1 << V_85 ) | ( 1 << V_86 ) ;
}
* V_12 = 0 ;
break;
case 1 :
case 2 :
V_69 |= ( 1 << V_77 ) | ( 1 << V_78 ) ;
if ( V_15 -> V_58 & V_59 )
V_69 |= ( 1 << V_79 ) | ( 1 << V_80 ) ;
if ( V_15 -> V_22 & V_23 ) {
if ( ! ( V_15 -> V_58 & V_59 ) )
* V_68 = ( 1 << V_83 ) | ( 1 << V_84 ) ;
else
* V_68 = ( 1 << V_85 ) | ( 1 << V_86 ) ;
}
* V_12 = 1 ;
break;
case 3 :
V_69 |= ( 1 << V_79 ) | ( 1 << V_80 ) ;
if ( V_15 -> V_22 & V_23 )
* V_68 = ( 1 << V_85 ) | ( 1 << V_86 ) ;
* V_12 = 2 ;
break;
}
return V_69 ;
} else {
unsigned short V_69 ;
V_69 = ( 1 << V_75 ) | ( 1 << V_76 ) ;
if ( V_15 -> V_58 & V_59 )
V_69 |= ( 1 << V_77 ) | ( 1 << V_78 ) ;
if ( V_15 -> V_58 & V_61 )
V_69 |= ( 1 << V_79 ) | ( 1 << V_80 ) ;
if ( V_15 -> V_22 & V_23 ) {
if ( ! ( V_15 -> V_58 & V_59 ) )
* V_68 = ( 1 << V_81 ) | ( 1 << V_82 ) ;
else if ( ! ( V_15 -> V_58 & V_61 ) )
* V_68 = ( 1 << V_83 ) | ( 1 << V_84 ) ;
else
* V_68 = ( 1 << V_85 ) | ( 1 << V_86 ) ;
}
* V_12 = 0 ;
return V_69 ;
}
}
static unsigned short F_16 ( struct V_14 * V_15 )
{
unsigned short V_69 ;
if ( ! F_12 ( V_15 ) )
return 0 ;
V_69 = ( 1 << V_75 ) | ( 1 << V_76 ) ;
V_69 |= ( 1 << V_87 ) ;
return V_69 ;
}
static unsigned int F_17 ( struct V_1 * V_2 , unsigned int V_3 , unsigned short V_69 , int V_5 )
{
int V_88 , V_89 ;
unsigned int V_90 = ~ 0 ;
unsigned char V_19 ;
for ( V_88 = 3 ; V_88 < 12 ; V_88 ++ ) {
if ( ! ( V_69 & ( 1 << V_88 ) ) )
continue;
V_19 = F_1 ( V_2 , V_3 , V_88 , V_5 ) ;
switch ( V_19 ) {
case V_51 : V_89 = V_91 ; break;
case V_57 : V_89 = V_92 ; break;
case V_60 : V_89 = V_93 ; break;
case V_55 : V_89 = V_94 ; break;
case V_52 : V_89 = V_95 ; break;
default: V_89 = V_96 ; break;
}
V_90 &= V_2 -> V_11 [ V_5 ] . V_97 [ V_3 ] -> V_90 [ V_89 ] ;
}
if ( ! V_5 )
V_90 &= ~ ( V_98 | V_99 |
V_100 ) ;
return V_90 ;
}
int F_18 ( struct V_101 * V_62 ,
unsigned short V_102 ,
const struct V_1 * V_103 )
{
int V_88 , V_104 , V_105 ;
const struct V_1 * V_2 ;
struct V_1 * V_106 , * V_107 ;
unsigned short V_108 [ 2 ] [ 4 ] ;
unsigned char V_12 [ 2 ] [ 4 ] ;
unsigned short V_49 , V_69 ;
unsigned short V_68 [ 4 ] ;
unsigned int V_90 ;
struct V_14 * V_97 ;
V_106 = F_19 ( V_102 , sizeof( struct V_1 ) , V_109 ) ;
if ( V_106 == NULL )
return - V_110 ;
memset ( V_108 , 0 , sizeof( V_108 ) ) ;
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
memset ( V_68 , 0 , sizeof( V_68 ) ) ;
for ( V_88 = 0 ; V_88 < 4 ; V_88 ++ ) {
V_97 = V_62 -> V_97 [ V_88 ] ;
if ( ! V_97 )
continue;
V_108 [ 0 ] [ V_88 ] = F_11 ( V_97 , & V_12 [ 0 ] [ V_88 ] , & V_68 [ V_88 ] ) ;
V_108 [ 1 ] [ V_88 ] = F_16 ( V_97 ) ;
if ( ! ( V_97 -> V_58 & V_111 ) ) {
for ( V_104 = 0 ; V_104 < V_88 ; V_104 ++ ) {
if ( V_62 -> V_97 [ V_104 ] )
V_108 [ 1 ] [ V_88 ] &= ~ V_108 [ 1 ] [ V_104 ] ;
}
}
}
for ( V_88 = 0 ; V_88 < V_102 ; V_88 ++ ) {
V_2 = & V_103 [ V_88 ] ;
V_107 = & V_106 [ V_88 ] ;
if ( V_2 -> V_112 ) {
* V_107 = * V_2 ;
continue;
}
V_107 -> V_8 = V_2 -> V_8 ;
V_107 -> V_113 = V_2 -> V_113 ;
V_107 -> V_6 = V_2 -> V_6 ;
V_107 -> V_114 = V_2 -> V_114 ;
V_107 -> V_62 = V_62 ;
V_107 -> V_90 = ~ 0 ;
V_69 = V_2 -> V_11 [ 0 ] . V_69 ;
for ( V_104 = 0 ; V_104 < 4 && V_69 ; V_104 ++ ) {
if ( ! V_62 -> V_97 [ V_104 ] )
continue;
V_90 = ~ 0 ;
if ( V_2 -> V_6 && V_2 -> V_8 == 0 )
V_49 = V_68 [ V_104 ] ;
else
V_49 = V_108 [ V_2 -> V_8 ] [ V_104 ] ;
if ( V_2 -> V_113 ) {
V_49 &= V_69 ;
for ( V_105 = 0 ; V_105 < V_88 ; V_105 ++ ) {
if ( V_107 -> V_8 == V_106 [ V_105 ] . V_8 )
V_49 &= ~ V_106 [ V_105 ] . V_11 [ 0 ] . V_115 [ V_104 ] ;
}
} else {
V_49 &= V_2 -> V_11 [ 0 ] . V_69 ;
}
if ( V_49 ) {
V_107 -> V_11 [ 0 ] . V_115 [ V_104 ] = V_49 ;
V_107 -> V_11 [ 0 ] . V_97 [ V_104 ] = V_62 -> V_97 [ V_104 ] ;
V_107 -> V_11 [ 0 ] . V_12 [ V_104 ] = V_12 [ V_2 -> V_8 ] [ V_104 ] ;
if ( V_62 -> V_116 )
V_90 = V_117 ;
else
V_90 = F_17 ( V_107 , V_104 , V_49 , 0 ) ;
if ( V_2 -> V_113 )
V_108 [ V_2 -> V_8 ] [ V_104 ] &= ~ V_49 ;
}
V_69 &= ~ V_49 ;
V_107 -> V_11 [ 0 ] . V_69 |= V_49 ;
V_107 -> V_90 &= V_90 ;
}
if ( V_2 -> V_8 == V_9 &&
V_62 -> V_97 [ 0 ] && ( V_62 -> V_97 [ 0 ] -> V_25 & V_50 ) &&
V_12 [ V_2 -> V_8 ] [ 0 ] == 0 ) {
V_49 = ( 1 << V_75 ) | ( 1 << V_76 ) |
( 1 << V_118 ) | ( 1 << V_119 ) ;
if ( ( V_49 & V_2 -> V_11 [ 1 ] . V_69 ) == V_49 ) {
V_107 -> V_11 [ 1 ] . V_69 = V_49 ;
V_107 -> V_11 [ 1 ] . V_115 [ 0 ] = V_49 ;
V_107 -> V_11 [ 1 ] . V_12 [ 0 ] = 0 ;
V_107 -> V_11 [ 1 ] . V_97 [ 0 ] = V_62 -> V_97 [ 0 ] ;
if ( V_2 -> V_113 )
V_108 [ V_2 -> V_8 ] [ 0 ] &= ~ V_49 ;
if ( V_62 -> V_116 )
V_90 = V_100 ;
else
V_90 = F_17 ( V_107 , 0 , V_49 , 1 ) ;
V_107 -> V_90 |= V_90 ;
}
}
if ( V_107 -> V_90 == ~ 0 )
V_107 -> V_90 = 0 ;
}
V_62 -> V_102 = V_102 ;
V_62 -> V_103 = V_106 ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , unsigned int V_16 ,
enum V_120 V_121 , unsigned short V_69 )
{
struct V_101 * V_62 ;
int V_88 , V_3 , V_11 , V_122 ;
unsigned int V_123 [ 4 ] = { 0 , 0 , 0 , 0 } ;
unsigned char V_19 ;
int V_124 = 0 ;
V_11 = V_16 > 48000 ;
V_62 = V_2 -> V_62 ;
if ( V_121 == V_125 ) {
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ )
if ( V_62 -> V_97 [ V_3 ] && ( V_62 -> V_97 [ V_3 ] -> V_22 & V_23 ) ) {
V_124 = F_2 ( V_62 -> V_97 [ V_3 ] , V_16 ) ;
if ( V_124 < 0 )
return V_124 ;
}
}
F_21 ( & V_2 -> V_62 -> V_126 ) ;
for ( V_88 = 3 ; V_88 < 12 ; V_88 ++ ) {
if ( ! ( V_69 & ( 1 << V_88 ) ) )
continue;
V_122 = 0 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
if ( V_62 -> V_127 [ V_2 -> V_8 ] [ V_3 ] & ( 1 << V_88 ) ) {
F_22 ( & V_2 -> V_62 -> V_126 ) ;
V_124 = - V_128 ;
goto error;
}
if ( V_2 -> V_11 [ V_11 ] . V_115 [ V_3 ] & ( 1 << V_88 ) ) {
V_62 -> V_127 [ V_2 -> V_8 ] [ V_3 ] |= ( 1 << V_88 ) ;
V_122 ++ ;
}
}
if ( ! V_122 ) {
F_22 ( & V_2 -> V_62 -> V_126 ) ;
F_23 ( V_129 L_1 , V_88 ) ;
V_124 = - V_130 ;
goto error;
}
}
V_2 -> V_131 = V_11 ;
F_22 ( & V_2 -> V_62 -> V_126 ) ;
for ( V_88 = 3 ; V_88 < 12 ; V_88 ++ ) {
if ( ! ( V_69 & ( 1 << V_88 ) ) )
continue;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
if ( V_2 -> V_11 [ V_11 ] . V_115 [ V_3 ] & ( 1 << V_88 ) ) {
V_19 = F_1 ( V_2 , V_3 , V_88 , V_11 ) ;
if ( V_19 == 0xff ) {
F_23 ( V_129 L_2 , V_88 ) ;
continue;
}
if ( V_123 [ V_3 ] & ( 1 << ( V_19 - V_51 ) ) )
continue;
V_124 = F_8 ( V_2 -> V_11 [ V_11 ] . V_97 [ V_3 ] , V_19 , V_16 ) ;
if ( V_124 < 0 )
F_23 ( V_129 L_3 , V_3 , V_19 , V_16 , V_124 ) ;
else
V_123 [ V_3 ] |= ( 1 << ( V_19 - V_51 ) ) ;
}
}
}
V_2 -> V_132 = V_69 ;
return 0 ;
error:
V_2 -> V_132 = V_69 ;
F_24 ( V_2 ) ;
return V_124 ;
}
int F_24 ( struct V_1 * V_2 )
{
struct V_101 * V_62 ;
unsigned short V_69 = V_2 -> V_132 ;
int V_88 , V_3 ;
#ifdef F_25
int V_11 = V_2 -> V_131 ;
for ( V_88 = 3 ; V_88 < 12 ; V_88 ++ ) {
if ( ! ( V_69 & ( 1 << V_88 ) ) )
continue;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
if ( V_2 -> V_11 [ V_11 ] . V_115 [ V_3 ] & ( 1 << V_88 ) ) {
int V_19 = F_1 ( V_2 , V_3 , V_88 , V_11 ) ;
F_9 ( V_2 -> V_11 [ V_11 ] . V_97 [ V_3 ] ,
V_19 , 0 ) ;
}
}
}
#endif
V_62 = V_2 -> V_62 ;
F_21 ( & V_2 -> V_62 -> V_126 ) ;
for ( V_88 = 3 ; V_88 < 12 ; V_88 ++ ) {
if ( ! ( V_69 & ( 1 << V_88 ) ) )
continue;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ )
V_62 -> V_127 [ V_2 -> V_8 ] [ V_3 ] &= ~ ( 1 << V_88 ) ;
}
V_2 -> V_132 = 0 ;
V_2 -> V_131 = 0 ;
F_22 ( & V_2 -> V_62 -> V_126 ) ;
return 0 ;
}
static int F_26 ( struct V_133 * V_134 ,
struct V_135 * V_136 )
{
struct V_137 * V_138 = F_27 ( V_134 , V_139 ) ;
if ( V_138 -> V_140 > 2 ) {
static const struct V_137 V_141 = {
. V_140 = 1 ,
. V_142 = 48000 ,
} ;
struct V_137 * V_16 = F_27 ( V_134 , V_143 ) ;
return F_28 ( V_16 , & V_141 ) ;
}
return 0 ;
}
static int F_29 ( struct V_133 * V_134 ,
struct V_135 * V_136 )
{
struct V_137 * V_16 = F_27 ( V_134 , V_143 ) ;
if ( V_16 -> V_140 > 48000 ) {
static const struct V_137 V_144 = {
. V_140 = 2 ,
. V_142 = 2 ,
} ;
struct V_137 * V_138 = F_27 ( V_134 , V_139 ) ;
return F_28 ( V_138 , & V_144 ) ;
}
return 0 ;
}
int F_30 ( struct V_145 * V_146 )
{
int V_124 ;
V_124 = F_31 ( V_146 , 0 , V_143 ,
F_26 , NULL ,
V_139 , - 1 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_31 ( V_146 , 0 , V_139 ,
F_29 , NULL ,
V_143 , - 1 ) ;
return V_124 ;
}
