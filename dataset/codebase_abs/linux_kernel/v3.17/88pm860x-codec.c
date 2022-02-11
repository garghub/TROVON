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
struct V_8 * V_9 = V_28 -> V_9 ;
F_6 ( V_9 , V_30 , V_31 , 0 ) ;
F_6 ( V_9 , V_32 ,
V_33 , V_33 ) ;
return 0 ;
}
static int F_11 ( struct V_27 * V_28 ,
struct V_1 * V_2 , int V_29 )
{
struct V_8 * V_9 = V_28 -> V_9 ;
unsigned int V_34 = 0 ;
int V_35 ;
if ( ! strcmp ( V_28 -> V_36 , L_1 ) )
V_34 = V_37 ;
if ( ! strcmp ( V_28 -> V_36 , L_2 ) )
V_34 = V_38 ;
switch ( V_29 ) {
case V_39 :
if ( V_34 ) {
V_34 |= V_40 ;
F_6 ( V_9 , V_30 ,
V_31 , V_31 ) ;
F_6 ( V_9 , V_32 ,
V_33 , V_33 ) ;
F_6 ( V_9 , V_41 ,
V_34 , V_34 ) ;
}
break;
case V_42 :
if ( V_34 ) {
F_6 ( V_9 , V_30 ,
V_31 , V_31 ) ;
F_6 ( V_9 , V_32 ,
V_33 , V_33 ) ;
V_35 = F_3 ( V_9 , V_41 ) ;
V_35 &= ~ V_34 ;
if ( ! ( V_35 & ( V_37 | V_38 ) ) )
V_35 &= ~ V_40 ;
F_12 ( V_9 , V_41 , V_35 ) ;
}
break;
}
return 0 ;
}
static int F_13 ( struct V_43 * V_44 , int V_45 )
{
struct V_8 * V_9 = V_44 -> V_9 ;
int V_35 = 0 , V_25 = V_46 | V_47 ;
if ( V_45 )
V_35 = V_25 ;
F_6 ( V_9 , V_30 , V_25 , V_35 ) ;
F_6 ( V_9 , V_32 ,
V_33 , V_33 ) ;
return 0 ;
}
static int F_14 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_43 * V_52 )
{
struct V_8 * V_9 = V_52 -> V_9 ;
unsigned char V_53 = 0 , V_25 = 0 ;
switch ( F_15 ( V_51 ) ) {
case 16 :
V_53 &= ~ V_54 ;
break;
case 18 :
V_53 |= V_54 ;
break;
default:
return - V_22 ;
}
V_25 |= V_54 ;
F_6 ( V_9 , V_55 , V_25 , V_53 ) ;
switch ( F_16 ( V_51 ) ) {
case 8000 :
V_53 = 0 ;
break;
case 16000 :
V_53 = 3 ;
break;
case 32000 :
V_53 = 6 ;
break;
case 48000 :
V_53 = 8 ;
break;
default:
return - V_22 ;
}
F_6 ( V_9 , V_56 , 0x0f , V_53 ) ;
return 0 ;
}
static int F_17 ( struct V_43 * V_44 ,
unsigned int V_57 )
{
struct V_8 * V_9 = V_44 -> V_9 ;
struct V_58 * V_59 = F_18 ( V_9 ) ;
unsigned char V_53 = 0 , V_25 = 0 ;
int V_60 = - V_22 ;
V_25 |= V_61 | V_62 | V_63 ;
switch ( V_57 & V_64 ) {
case V_65 :
case V_66 :
if ( V_59 -> V_67 == V_68 ) {
V_53 |= V_63 ;
V_60 = 0 ;
}
break;
case V_69 :
if ( V_59 -> V_67 == V_70 ) {
V_53 &= ~ V_63 ;
V_60 = 0 ;
}
break;
}
switch ( V_57 & V_71 ) {
case V_72 :
V_53 |= V_73 ;
V_60 = 0 ;
break;
}
V_25 |= V_74 ;
if ( V_60 )
return V_60 ;
F_6 ( V_9 , V_55 , V_25 , V_53 ) ;
return 0 ;
}
static int F_19 ( struct V_43 * V_44 ,
int V_75 , unsigned int V_76 , int V_67 )
{
struct V_8 * V_9 = V_44 -> V_9 ;
struct V_58 * V_59 = F_18 ( V_9 ) ;
if ( V_67 == V_68 )
V_59 -> V_67 = V_68 ;
else {
V_59 -> V_67 = V_70 ;
return - V_22 ;
}
return 0 ;
}
static int F_20 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_43 * V_52 )
{
struct V_8 * V_9 = V_52 -> V_9 ;
unsigned char V_53 ;
switch ( F_15 ( V_51 ) ) {
case 16 :
V_53 = 0 ;
break;
case 18 :
V_53 = V_54 ;
break;
default:
return - V_22 ;
}
F_6 ( V_9 , V_77 , V_54 , V_53 ) ;
switch ( F_16 ( V_51 ) ) {
case 8000 :
V_53 = 0 ;
break;
case 11025 :
V_53 = 1 ;
break;
case 16000 :
V_53 = 3 ;
break;
case 22050 :
V_53 = 4 ;
break;
case 32000 :
V_53 = 6 ;
break;
case 44100 :
V_53 = 7 ;
break;
case 48000 :
V_53 = 8 ;
break;
default:
return - V_22 ;
}
F_6 ( V_9 , V_78 , 0xf , V_53 ) ;
return 0 ;
}
static int F_21 ( struct V_43 * V_44 ,
unsigned int V_57 )
{
struct V_8 * V_9 = V_44 -> V_9 ;
struct V_58 * V_59 = F_18 ( V_9 ) ;
unsigned char V_53 = 0 , V_25 = 0 ;
V_25 |= V_61 | V_62 | V_63 ;
switch ( V_57 & V_64 ) {
case V_65 :
if ( V_59 -> V_67 == V_68 )
V_53 |= V_63 ;
else
return - V_22 ;
break;
case V_69 :
if ( V_59 -> V_67 == V_70 )
V_53 &= ~ V_63 ;
else
return - V_22 ;
break;
default:
return - V_22 ;
}
switch ( V_57 & V_71 ) {
case V_72 :
V_53 |= V_73 ;
break;
default:
return - V_22 ;
}
V_25 |= V_74 ;
F_6 ( V_9 , V_77 , V_25 , V_53 ) ;
return 0 ;
}
static int F_22 ( struct V_8 * V_9 ,
enum V_79 V_80 )
{
struct V_58 * V_59 = F_18 ( V_9 ) ;
int V_35 ;
switch ( V_80 ) {
case V_81 :
break;
case V_82 :
break;
case V_83 :
if ( V_9 -> V_84 . V_85 == V_86 ) {
V_35 = V_87 | V_88 ;
F_23 ( V_59 -> V_89 , V_90 , V_35 ) ;
F_24 ( 300 ) ;
V_35 = V_87 | V_91
| V_88 ;
F_23 ( V_59 -> V_89 , V_90 , V_35 ) ;
}
break;
case V_86 :
V_35 = V_87 | V_91 | V_88 ;
F_25 ( V_59 -> V_89 , V_90 , V_35 , 0 ) ;
break;
}
V_9 -> V_84 . V_85 = V_80 ;
return 0 ;
}
static T_1 F_26 ( int V_92 , void * V_35 )
{
struct V_58 * V_59 = V_35 ;
int V_93 , V_94 , V_95 = 0 , V_96 = 0 ;
int V_25 ;
V_93 = F_27 ( V_59 -> V_89 , V_97 ) ;
V_94 = F_27 ( V_59 -> V_89 , V_98 ) ;
V_25 = V_59 -> V_99 . V_100 | V_59 -> V_99 . V_101 | V_59 -> V_99 . V_102
| V_59 -> V_99 . V_103 ;
#ifndef F_28
if ( V_93 & ( V_104 | V_105 | V_106 | V_107 |
V_108 | V_109 ) )
F_29 ( F_30 ( V_59 -> V_9 -> V_110 ) ) ;
#endif
if ( ( V_59 -> V_99 . V_103 & V_111 )
&& ( V_93 & V_104 ) )
V_95 |= V_111 ;
if ( ( V_59 -> V_99 . V_112 & V_113 )
&& ( V_93 & V_105 ) )
V_96 |= V_113 ;
if ( V_59 -> V_99 . V_100 && ( V_94 & ( V_106 | V_107 ) ) )
V_95 |= V_59 -> V_99 . V_100 ;
if ( V_59 -> V_99 . V_101 && ( V_93 & V_114 ) )
V_95 |= V_59 -> V_99 . V_101 ;
if ( V_59 -> V_99 . V_102 && ( V_94 & ( V_108 | V_109 ) ) )
V_95 |= V_59 -> V_99 . V_102 ;
if ( V_95 )
F_31 ( V_59 -> V_99 . V_115 , V_95 , V_25 ) ;
if ( V_96 )
F_31 ( V_59 -> V_99 . V_116 , V_113 ,
V_113 ) ;
F_32 ( V_59 -> V_9 -> V_110 , L_3 ,
V_95 , V_25 ) ;
F_32 ( V_59 -> V_9 -> V_110 , L_4 , V_96 ) ;
return V_117 ;
}
int F_33 ( struct V_8 * V_9 ,
struct V_118 * V_119 ,
int V_99 , int V_120 , int V_100 , int V_102 )
{
struct V_58 * V_59 = F_18 ( V_9 ) ;
int V_35 ;
V_59 -> V_99 . V_115 = V_119 ;
V_59 -> V_99 . V_103 = V_99 ;
V_59 -> V_99 . V_101 = V_120 ;
V_59 -> V_99 . V_100 = V_100 ;
V_59 -> V_99 . V_102 = V_102 ;
if ( V_99 & V_111 )
F_25 ( V_59 -> V_89 , V_121 ,
V_122 , V_122 ) ;
if ( V_100 ) {
V_35 = V_123 | V_124 ;
F_25 ( V_59 -> V_89 , V_98 , V_35 , V_35 ) ;
}
if ( V_102 ) {
V_35 = V_125 | V_126 ;
F_25 ( V_59 -> V_89 , V_98 , V_35 , V_35 ) ;
}
F_26 ( 0 , V_59 ) ;
return 0 ;
}
int F_34 ( struct V_8 * V_9 ,
struct V_118 * V_119 , int V_99 )
{
struct V_58 * V_59 = F_18 ( V_9 ) ;
V_59 -> V_99 . V_116 = V_119 ;
V_59 -> V_99 . V_112 = V_99 ;
if ( V_99 & V_113 )
F_25 ( V_59 -> V_89 , V_127 ,
V_128 , V_128 ) ;
F_26 ( 0 , V_59 ) ;
return 0 ;
}
static int F_35 ( struct V_8 * V_9 )
{
struct V_58 * V_59 = F_18 ( V_9 ) ;
int V_15 , V_60 ;
V_59 -> V_9 = V_9 ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_60 = F_36 ( V_59 -> V_92 [ V_15 ] , NULL ,
F_26 , V_129 ,
V_59 -> V_36 [ V_15 ] , V_59 ) ;
if ( V_60 < 0 ) {
F_37 ( V_9 -> V_110 , L_5 ) ;
goto V_130;
}
}
F_22 ( V_9 , V_83 ) ;
return 0 ;
V_130:
while ( -- V_15 >= 0 )
F_38 ( V_59 -> V_92 [ V_15 ] , V_59 ) ;
return V_60 ;
}
static int F_39 ( struct V_8 * V_9 )
{
struct V_58 * V_59 = F_18 ( V_9 ) ;
int V_15 ;
for ( V_15 = 3 ; V_15 >= 0 ; V_15 -- )
F_38 ( V_59 -> V_92 [ V_15 ] , V_59 ) ;
F_22 ( V_9 , V_86 ) ;
return 0 ;
}
static struct V_131 * F_40 ( struct V_132 * V_110 )
{
struct V_58 * V_59 = F_41 ( V_110 ) ;
return V_59 -> V_131 ;
}
static int F_42 ( struct V_133 * V_134 )
{
struct V_135 * V_136 = F_41 ( V_134 -> V_110 . V_137 ) ;
struct V_58 * V_59 ;
struct V_138 * V_139 ;
int V_15 , V_60 ;
V_59 = F_43 ( & V_134 -> V_110 , sizeof( struct V_58 ) ,
V_140 ) ;
if ( V_59 == NULL )
return - V_141 ;
V_59 -> V_136 = V_136 ;
V_59 -> V_89 = ( V_136 -> V_142 == V_143 ) ? V_136 -> V_144
: V_136 -> V_145 ;
V_59 -> V_131 = ( V_136 -> V_142 == V_143 ) ? V_136 -> V_131
: V_136 -> V_146 ;
F_44 ( V_134 , V_59 ) ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_139 = F_45 ( V_134 , V_147 , V_15 ) ;
if ( ! V_139 ) {
F_37 ( & V_134 -> V_110 , L_6 ) ;
return - V_22 ;
}
V_59 -> V_92 [ V_15 ] = V_139 -> V_148 + V_136 -> V_149 ;
strncpy ( V_59 -> V_36 [ V_15 ] , V_139 -> V_36 , V_150 ) ;
}
V_60 = F_46 ( & V_134 -> V_110 , & V_151 ,
V_152 , F_4 ( V_152 ) ) ;
if ( V_60 ) {
F_37 ( & V_134 -> V_110 , L_7 ) ;
return - V_22 ;
}
return V_60 ;
}
static int F_47 ( struct V_133 * V_134 )
{
F_48 ( & V_134 -> V_110 ) ;
return 0 ;
}
