static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned int V_10 = V_6 -> V_10 ;
unsigned int V_11 = V_6 -> V_12 ;
int V_13 [ 2 ] , V_14 [ 2 ] , V_15 ;
V_13 [ 0 ] = F_3 ( V_9 , V_10 ) & 0x3f ;
V_13 [ 1 ] = ( F_3 ( V_9 , V_16 ) >> 4 ) & 0xf ;
V_14 [ 0 ] = F_3 ( V_9 , V_11 ) & 0x3f ;
V_14 [ 1 ] = ( F_3 ( V_9 , V_16 ) ) & 0xf ;
for ( V_15 = 0 ; V_15 < F_4 ( V_17 ) ; V_15 ++ ) {
if ( ( V_17 [ V_15 ] . V_18 == V_13 [ 0 ] ) && ( V_17 [ V_15 ] . V_19 == V_13 [ 1 ] ) )
V_4 -> V_20 . integer . V_20 [ 0 ] = V_15 ;
if ( ( V_17 [ V_15 ] . V_18 == V_14 [ 0 ] ) && ( V_17 [ V_15 ] . V_19 == V_14 [ 1 ] ) )
V_4 -> V_20 . integer . V_20 [ 1 ] = V_15 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned int V_10 = V_6 -> V_10 ;
unsigned int V_11 = V_6 -> V_12 ;
int V_21 ;
unsigned int V_13 , V_14 ;
V_13 = V_4 -> V_20 . integer . V_20 [ 0 ] ;
V_14 = V_4 -> V_20 . integer . V_20 [ 1 ] ;
if ( V_13 >= F_4 ( V_17 ) || V_14 >= F_4 ( V_17 ) )
return - V_22 ;
V_21 = F_6 ( V_9 , V_10 , 0x3f , V_17 [ V_13 ] . V_18 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_6 ( V_9 , V_16 , 0xf0 ,
V_17 [ V_13 ] . V_19 << 4 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_6 ( V_9 , V_11 , 0x3f , V_17 [ V_14 ] . V_18 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_6 ( V_9 , V_16 , 0x0f ,
V_17 [ V_14 ] . V_19 ) ;
return V_21 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned int V_10 = V_6 -> V_10 ;
unsigned int V_11 = V_6 -> V_12 ;
unsigned int V_23 = V_6 -> V_23 ;
int V_24 = V_6 -> V_24 , V_13 , V_14 ;
unsigned int V_25 = ( 1 << F_8 ( V_24 ) ) - 1 ;
V_13 = F_3 ( V_9 , V_10 ) >> V_23 ;
V_14 = F_3 ( V_9 , V_11 ) >> V_23 ;
V_4 -> V_20 . integer . V_20 [ 0 ] = ( V_24 - V_13 ) & V_25 ;
V_4 -> V_20 . integer . V_20 [ 1 ] = ( V_24 - V_14 ) & V_25 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned int V_10 = V_6 -> V_10 ;
unsigned int V_11 = V_6 -> V_12 ;
unsigned int V_23 = V_6 -> V_23 ;
int V_24 = V_6 -> V_24 ;
unsigned int V_25 = ( 1 << F_8 ( V_24 ) ) - 1 ;
int V_21 ;
unsigned int V_13 , V_14 , V_26 ;
V_26 = V_25 << V_23 ;
V_13 = ( ( V_24 - V_4 -> V_20 . integer . V_20 [ 0 ] ) & V_25 ) ;
V_14 = ( ( V_24 - V_4 -> V_20 . integer . V_20 [ 1 ] ) & V_25 ) ;
V_13 = V_13 << V_23 ;
V_14 = V_14 << V_23 ;
V_21 = F_6 ( V_9 , V_10 , V_26 , V_13 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_6 ( V_9 , V_11 , V_26 , V_14 ) ;
return V_21 ;
}
static int F_10 ( struct V_27 * V_28 ,
struct V_1 * V_2 , int V_29 )
{
struct V_8 * V_9 = F_11 ( V_28 -> V_30 ) ;
F_6 ( V_9 , V_31 , V_32 , 0 ) ;
F_6 ( V_9 , V_33 ,
V_34 , V_34 ) ;
return 0 ;
}
static int F_12 ( struct V_27 * V_28 ,
struct V_1 * V_2 , int V_29 )
{
struct V_8 * V_9 = F_11 ( V_28 -> V_30 ) ;
unsigned int V_35 = 0 ;
int V_36 ;
if ( ! strcmp ( V_28 -> V_37 , L_1 ) )
V_35 = V_38 ;
if ( ! strcmp ( V_28 -> V_37 , L_2 ) )
V_35 = V_39 ;
switch ( V_29 ) {
case V_40 :
if ( V_35 ) {
V_35 |= V_41 ;
F_6 ( V_9 , V_31 ,
V_32 , V_32 ) ;
F_6 ( V_9 , V_33 ,
V_34 , V_34 ) ;
F_6 ( V_9 , V_42 ,
V_35 , V_35 ) ;
}
break;
case V_43 :
if ( V_35 ) {
F_6 ( V_9 , V_31 ,
V_32 , V_32 ) ;
F_6 ( V_9 , V_33 ,
V_34 , V_34 ) ;
V_36 = F_3 ( V_9 , V_42 ) ;
V_36 &= ~ V_35 ;
if ( ! ( V_36 & ( V_38 | V_39 ) ) )
V_36 &= ~ V_41 ;
F_13 ( V_9 , V_42 , V_36 ) ;
}
break;
}
return 0 ;
}
static int F_14 ( struct V_44 * V_45 , int V_46 )
{
struct V_8 * V_9 = V_45 -> V_9 ;
int V_36 = 0 , V_25 = V_47 | V_48 ;
if ( V_46 )
V_36 = V_25 ;
F_6 ( V_9 , V_31 , V_25 , V_36 ) ;
F_6 ( V_9 , V_33 ,
V_34 , V_34 ) ;
return 0 ;
}
static int F_15 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_44 * V_53 )
{
struct V_8 * V_9 = V_53 -> V_9 ;
unsigned char V_54 = 0 , V_25 = 0 ;
switch ( F_16 ( V_52 ) ) {
case 16 :
V_54 &= ~ V_55 ;
break;
case 18 :
V_54 |= V_55 ;
break;
default:
return - V_22 ;
}
V_25 |= V_55 ;
F_6 ( V_9 , V_56 , V_25 , V_54 ) ;
switch ( F_17 ( V_52 ) ) {
case 8000 :
V_54 = 0 ;
break;
case 16000 :
V_54 = 3 ;
break;
case 32000 :
V_54 = 6 ;
break;
case 48000 :
V_54 = 8 ;
break;
default:
return - V_22 ;
}
F_6 ( V_9 , V_57 , 0x0f , V_54 ) ;
return 0 ;
}
static int F_18 ( struct V_44 * V_45 ,
unsigned int V_58 )
{
struct V_8 * V_9 = V_45 -> V_9 ;
struct V_59 * V_60 = F_19 ( V_9 ) ;
unsigned char V_54 = 0 , V_25 = 0 ;
int V_61 = - V_22 ;
V_25 |= V_62 | V_63 | V_64 ;
switch ( V_58 & V_65 ) {
case V_66 :
case V_67 :
if ( V_60 -> V_68 == V_69 ) {
V_54 |= V_64 ;
V_61 = 0 ;
}
break;
case V_70 :
if ( V_60 -> V_68 == V_71 ) {
V_54 &= ~ V_64 ;
V_61 = 0 ;
}
break;
}
switch ( V_58 & V_72 ) {
case V_73 :
V_54 |= V_74 ;
V_61 = 0 ;
break;
}
V_25 |= V_75 ;
if ( V_61 )
return V_61 ;
F_6 ( V_9 , V_56 , V_25 , V_54 ) ;
return 0 ;
}
static int F_20 ( struct V_44 * V_45 ,
int V_76 , unsigned int V_77 , int V_68 )
{
struct V_8 * V_9 = V_45 -> V_9 ;
struct V_59 * V_60 = F_19 ( V_9 ) ;
if ( V_68 == V_69 )
V_60 -> V_68 = V_69 ;
else {
V_60 -> V_68 = V_71 ;
return - V_22 ;
}
return 0 ;
}
static int F_21 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_44 * V_53 )
{
struct V_8 * V_9 = V_53 -> V_9 ;
unsigned char V_54 ;
switch ( F_16 ( V_52 ) ) {
case 16 :
V_54 = 0 ;
break;
case 18 :
V_54 = V_55 ;
break;
default:
return - V_22 ;
}
F_6 ( V_9 , V_78 , V_55 , V_54 ) ;
switch ( F_17 ( V_52 ) ) {
case 8000 :
V_54 = 0 ;
break;
case 11025 :
V_54 = 1 ;
break;
case 16000 :
V_54 = 3 ;
break;
case 22050 :
V_54 = 4 ;
break;
case 32000 :
V_54 = 6 ;
break;
case 44100 :
V_54 = 7 ;
break;
case 48000 :
V_54 = 8 ;
break;
default:
return - V_22 ;
}
F_6 ( V_9 , V_79 , 0xf , V_54 ) ;
return 0 ;
}
static int F_22 ( struct V_44 * V_45 ,
unsigned int V_58 )
{
struct V_8 * V_9 = V_45 -> V_9 ;
struct V_59 * V_60 = F_19 ( V_9 ) ;
unsigned char V_54 = 0 , V_25 = 0 ;
V_25 |= V_62 | V_63 | V_64 ;
switch ( V_58 & V_65 ) {
case V_66 :
if ( V_60 -> V_68 == V_69 )
V_54 |= V_64 ;
else
return - V_22 ;
break;
case V_70 :
if ( V_60 -> V_68 == V_71 )
V_54 &= ~ V_64 ;
else
return - V_22 ;
break;
default:
return - V_22 ;
}
switch ( V_58 & V_72 ) {
case V_73 :
V_54 |= V_74 ;
break;
default:
return - V_22 ;
}
V_25 |= V_75 ;
F_6 ( V_9 , V_78 , V_25 , V_54 ) ;
return 0 ;
}
static int F_23 ( struct V_8 * V_9 ,
enum V_80 V_81 )
{
struct V_59 * V_60 = F_19 ( V_9 ) ;
int V_36 ;
switch ( V_81 ) {
case V_82 :
break;
case V_83 :
break;
case V_84 :
if ( F_24 ( V_9 ) == V_85 ) {
V_36 = V_86 | V_87 ;
F_25 ( V_60 -> V_88 , V_89 , V_36 ) ;
F_26 ( 300 ) ;
V_36 = V_86 | V_90
| V_87 ;
F_25 ( V_60 -> V_88 , V_89 , V_36 ) ;
}
break;
case V_85 :
V_36 = V_86 | V_90 | V_87 ;
F_27 ( V_60 -> V_88 , V_89 , V_36 , 0 ) ;
break;
}
return 0 ;
}
static T_1 F_28 ( int V_91 , void * V_36 )
{
struct V_59 * V_60 = V_36 ;
int V_92 , V_93 , V_94 = 0 , V_95 = 0 ;
int V_25 ;
V_92 = F_29 ( V_60 -> V_88 , V_96 ) ;
V_93 = F_29 ( V_60 -> V_88 , V_97 ) ;
V_25 = V_60 -> V_98 . V_99 | V_60 -> V_98 . V_100 | V_60 -> V_98 . V_101
| V_60 -> V_98 . V_102 ;
#ifndef F_30
if ( V_92 & ( V_103 | V_104 | V_105 | V_106 |
V_107 | V_108 ) )
F_31 ( F_32 ( V_60 -> V_9 -> V_109 ) ) ;
#endif
if ( ( V_60 -> V_98 . V_102 & V_110 )
&& ( V_92 & V_103 ) )
V_94 |= V_110 ;
if ( ( V_60 -> V_98 . V_111 & V_112 )
&& ( V_92 & V_104 ) )
V_95 |= V_112 ;
if ( V_60 -> V_98 . V_99 && ( V_93 & ( V_105 | V_106 ) ) )
V_94 |= V_60 -> V_98 . V_99 ;
if ( V_60 -> V_98 . V_100 && ( V_92 & V_113 ) )
V_94 |= V_60 -> V_98 . V_100 ;
if ( V_60 -> V_98 . V_101 && ( V_93 & ( V_107 | V_108 ) ) )
V_94 |= V_60 -> V_98 . V_101 ;
if ( V_94 )
F_33 ( V_60 -> V_98 . V_114 , V_94 , V_25 ) ;
if ( V_95 )
F_33 ( V_60 -> V_98 . V_115 , V_112 ,
V_112 ) ;
F_34 ( V_60 -> V_9 -> V_109 , L_3 ,
V_94 , V_25 ) ;
F_34 ( V_60 -> V_9 -> V_109 , L_4 , V_95 ) ;
return V_116 ;
}
int F_35 ( struct V_8 * V_9 ,
struct V_117 * V_118 ,
int V_98 , int V_119 , int V_99 , int V_101 )
{
struct V_59 * V_60 = F_19 ( V_9 ) ;
int V_36 ;
V_60 -> V_98 . V_114 = V_118 ;
V_60 -> V_98 . V_102 = V_98 ;
V_60 -> V_98 . V_100 = V_119 ;
V_60 -> V_98 . V_99 = V_99 ;
V_60 -> V_98 . V_101 = V_101 ;
if ( V_98 & V_110 )
F_27 ( V_60 -> V_88 , V_120 ,
V_121 , V_121 ) ;
if ( V_99 ) {
V_36 = V_122 | V_123 ;
F_27 ( V_60 -> V_88 , V_97 , V_36 , V_36 ) ;
}
if ( V_101 ) {
V_36 = V_124 | V_125 ;
F_27 ( V_60 -> V_88 , V_97 , V_36 , V_36 ) ;
}
F_28 ( 0 , V_60 ) ;
return 0 ;
}
int F_36 ( struct V_8 * V_9 ,
struct V_117 * V_118 , int V_98 )
{
struct V_59 * V_60 = F_19 ( V_9 ) ;
V_60 -> V_98 . V_115 = V_118 ;
V_60 -> V_98 . V_111 = V_98 ;
if ( V_98 & V_112 )
F_27 ( V_60 -> V_88 , V_126 ,
V_127 , V_127 ) ;
F_28 ( 0 , V_60 ) ;
return 0 ;
}
static int F_37 ( struct V_8 * V_9 )
{
struct V_59 * V_60 = F_19 ( V_9 ) ;
int V_15 , V_61 ;
V_60 -> V_9 = V_9 ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_61 = F_38 ( V_60 -> V_91 [ V_15 ] , NULL ,
F_28 , V_128 ,
V_60 -> V_37 [ V_15 ] , V_60 ) ;
if ( V_61 < 0 ) {
F_39 ( V_9 -> V_109 , L_5 ) ;
goto V_129;
}
}
return 0 ;
V_129:
while ( -- V_15 >= 0 )
F_40 ( V_60 -> V_91 [ V_15 ] , V_60 ) ;
return V_61 ;
}
static int F_41 ( struct V_8 * V_9 )
{
struct V_59 * V_60 = F_19 ( V_9 ) ;
int V_15 ;
for ( V_15 = 3 ; V_15 >= 0 ; V_15 -- )
F_40 ( V_60 -> V_91 [ V_15 ] , V_60 ) ;
return 0 ;
}
static struct V_130 * F_42 ( struct V_131 * V_109 )
{
struct V_59 * V_60 = F_43 ( V_109 ) ;
return V_60 -> V_130 ;
}
static int F_44 ( struct V_132 * V_133 )
{
struct V_134 * V_135 = F_43 ( V_133 -> V_109 . V_136 ) ;
struct V_59 * V_60 ;
struct V_137 * V_138 ;
int V_15 , V_61 ;
V_60 = F_45 ( & V_133 -> V_109 , sizeof( struct V_59 ) ,
V_139 ) ;
if ( V_60 == NULL )
return - V_140 ;
V_60 -> V_135 = V_135 ;
V_60 -> V_88 = ( V_135 -> V_141 == V_142 ) ? V_135 -> V_143
: V_135 -> V_144 ;
V_60 -> V_130 = ( V_135 -> V_141 == V_142 ) ? V_135 -> V_130
: V_135 -> V_145 ;
F_46 ( V_133 , V_60 ) ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_138 = F_47 ( V_133 , V_146 , V_15 ) ;
if ( ! V_138 ) {
F_39 ( & V_133 -> V_109 , L_6 ) ;
return - V_22 ;
}
V_60 -> V_91 [ V_15 ] = V_138 -> V_147 + V_135 -> V_148 ;
strncpy ( V_60 -> V_37 [ V_15 ] , V_138 -> V_37 , V_149 ) ;
}
V_61 = F_48 ( & V_133 -> V_109 , & V_150 ,
V_151 , F_4 ( V_151 ) ) ;
if ( V_61 ) {
F_39 ( & V_133 -> V_109 , L_7 ) ;
return - V_22 ;
}
return V_61 ;
}
static int F_49 ( struct V_132 * V_133 )
{
F_50 ( & V_133 -> V_109 ) ;
return 0 ;
}
