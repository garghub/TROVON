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
case V_54 :
V_53 &= ~ V_55 ;
break;
case V_56 :
V_53 |= V_55 ;
break;
default:
return - V_22 ;
}
V_25 |= V_55 ;
F_6 ( V_9 , V_57 , V_25 , V_53 ) ;
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
F_6 ( V_9 , V_58 , 0x0f , V_53 ) ;
return 0 ;
}
static int F_17 ( struct V_43 * V_44 ,
unsigned int V_59 )
{
struct V_8 * V_9 = V_44 -> V_9 ;
struct V_60 * V_61 = F_18 ( V_9 ) ;
unsigned char V_53 = 0 , V_25 = 0 ;
int V_62 = - V_22 ;
V_25 |= V_63 | V_64 | V_65 ;
switch ( V_59 & V_66 ) {
case V_67 :
case V_68 :
if ( V_61 -> V_69 == V_70 ) {
V_53 |= V_65 ;
V_62 = 0 ;
}
break;
case V_71 :
if ( V_61 -> V_69 == V_72 ) {
V_53 &= ~ V_65 ;
V_62 = 0 ;
}
break;
}
switch ( V_59 & V_73 ) {
case V_74 :
V_53 |= V_75 ;
V_62 = 0 ;
break;
}
V_25 |= V_76 ;
if ( V_62 )
return V_62 ;
F_6 ( V_9 , V_57 , V_25 , V_53 ) ;
return 0 ;
}
static int F_19 ( struct V_43 * V_44 ,
int V_77 , unsigned int V_78 , int V_69 )
{
struct V_8 * V_9 = V_44 -> V_9 ;
struct V_60 * V_61 = F_18 ( V_9 ) ;
if ( V_69 == V_70 )
V_61 -> V_69 = V_70 ;
else {
V_61 -> V_69 = V_72 ;
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
case V_54 :
V_53 = 0 ;
break;
case V_56 :
V_53 = V_55 ;
break;
default:
return - V_22 ;
}
F_6 ( V_9 , V_79 , V_55 , V_53 ) ;
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
F_6 ( V_9 , V_80 , 0xf , V_53 ) ;
return 0 ;
}
static int F_21 ( struct V_43 * V_44 ,
unsigned int V_59 )
{
struct V_8 * V_9 = V_44 -> V_9 ;
struct V_60 * V_61 = F_18 ( V_9 ) ;
unsigned char V_53 = 0 , V_25 = 0 ;
V_25 |= V_63 | V_64 | V_65 ;
switch ( V_59 & V_66 ) {
case V_67 :
if ( V_61 -> V_69 == V_70 )
V_53 |= V_65 ;
else
return - V_22 ;
break;
case V_71 :
if ( V_61 -> V_69 == V_72 )
V_53 &= ~ V_65 ;
else
return - V_22 ;
break;
default:
return - V_22 ;
}
switch ( V_59 & V_73 ) {
case V_74 :
V_53 |= V_75 ;
break;
default:
return - V_22 ;
}
V_25 |= V_76 ;
F_6 ( V_9 , V_79 , V_25 , V_53 ) ;
return 0 ;
}
static int F_22 ( struct V_8 * V_9 ,
enum V_81 V_82 )
{
struct V_60 * V_61 = F_18 ( V_9 ) ;
int V_35 ;
switch ( V_82 ) {
case V_83 :
break;
case V_84 :
break;
case V_85 :
if ( V_9 -> V_86 . V_87 == V_88 ) {
V_35 = V_89 | V_90 ;
F_23 ( V_61 -> V_91 , V_92 , V_35 ) ;
F_24 ( 300 ) ;
V_35 = V_89 | V_93
| V_90 ;
F_23 ( V_61 -> V_91 , V_92 , V_35 ) ;
}
break;
case V_88 :
V_35 = V_89 | V_93 | V_90 ;
F_25 ( V_61 -> V_91 , V_92 , V_35 , 0 ) ;
break;
}
V_9 -> V_86 . V_87 = V_82 ;
return 0 ;
}
static T_1 F_26 ( int V_94 , void * V_35 )
{
struct V_60 * V_61 = V_35 ;
int V_95 , V_96 , V_97 = 0 , V_98 = 0 ;
int V_25 ;
V_95 = F_27 ( V_61 -> V_91 , V_99 ) ;
V_96 = F_27 ( V_61 -> V_91 , V_100 ) ;
V_25 = V_61 -> V_101 . V_102 | V_61 -> V_101 . V_103 | V_61 -> V_101 . V_104
| V_61 -> V_101 . V_105 ;
#ifndef F_28
if ( V_95 & ( V_106 | V_107 | V_108 | V_109 |
V_110 | V_111 ) )
F_29 ( F_30 ( V_61 -> V_9 -> V_112 ) ) ;
#endif
if ( ( V_61 -> V_101 . V_105 & V_113 )
&& ( V_95 & V_106 ) )
V_97 |= V_113 ;
if ( ( V_61 -> V_101 . V_114 & V_115 )
&& ( V_95 & V_107 ) )
V_98 |= V_115 ;
if ( V_61 -> V_101 . V_102 && ( V_96 & ( V_108 | V_109 ) ) )
V_97 |= V_61 -> V_101 . V_102 ;
if ( V_61 -> V_101 . V_103 && ( V_95 & V_116 ) )
V_97 |= V_61 -> V_101 . V_103 ;
if ( V_61 -> V_101 . V_104 && ( V_96 & ( V_110 | V_111 ) ) )
V_97 |= V_61 -> V_101 . V_104 ;
if ( V_97 )
F_31 ( V_61 -> V_101 . V_117 , V_97 , V_25 ) ;
if ( V_98 )
F_31 ( V_61 -> V_101 . V_118 , V_115 ,
V_115 ) ;
F_32 ( V_61 -> V_9 -> V_112 , L_3 ,
V_97 , V_25 ) ;
F_32 ( V_61 -> V_9 -> V_112 , L_4 , V_98 ) ;
return V_119 ;
}
int F_33 ( struct V_8 * V_9 ,
struct V_120 * V_121 ,
int V_101 , int V_122 , int V_102 , int V_104 )
{
struct V_60 * V_61 = F_18 ( V_9 ) ;
int V_35 ;
V_61 -> V_101 . V_117 = V_121 ;
V_61 -> V_101 . V_105 = V_101 ;
V_61 -> V_101 . V_103 = V_122 ;
V_61 -> V_101 . V_102 = V_102 ;
V_61 -> V_101 . V_104 = V_104 ;
if ( V_101 & V_113 )
F_25 ( V_61 -> V_91 , V_123 ,
V_124 , V_124 ) ;
if ( V_102 ) {
V_35 = V_125 | V_126 ;
F_25 ( V_61 -> V_91 , V_100 , V_35 , V_35 ) ;
}
if ( V_104 ) {
V_35 = V_127 | V_128 ;
F_25 ( V_61 -> V_91 , V_100 , V_35 , V_35 ) ;
}
F_26 ( 0 , V_61 ) ;
return 0 ;
}
int F_34 ( struct V_8 * V_9 ,
struct V_120 * V_121 , int V_101 )
{
struct V_60 * V_61 = F_18 ( V_9 ) ;
V_61 -> V_101 . V_118 = V_121 ;
V_61 -> V_101 . V_114 = V_101 ;
if ( V_101 & V_115 )
F_25 ( V_61 -> V_91 , V_129 ,
V_130 , V_130 ) ;
F_26 ( 0 , V_61 ) ;
return 0 ;
}
static int F_35 ( struct V_8 * V_9 )
{
struct V_60 * V_61 = F_18 ( V_9 ) ;
int V_15 , V_62 ;
V_61 -> V_9 = V_9 ;
V_62 = F_36 ( V_9 , V_61 -> V_131 ) ;
if ( V_62 )
return V_62 ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_62 = F_37 ( V_61 -> V_94 [ V_15 ] , NULL ,
F_26 , V_132 ,
V_61 -> V_36 [ V_15 ] , V_61 ) ;
if ( V_62 < 0 ) {
F_38 ( V_9 -> V_112 , L_5 ) ;
goto V_133;
}
}
F_22 ( V_9 , V_85 ) ;
return 0 ;
V_133:
while ( -- V_15 >= 0 )
F_39 ( V_61 -> V_94 [ V_15 ] , V_61 ) ;
return V_62 ;
}
static int F_40 ( struct V_8 * V_9 )
{
struct V_60 * V_61 = F_18 ( V_9 ) ;
int V_15 ;
for ( V_15 = 3 ; V_15 >= 0 ; V_15 -- )
F_39 ( V_61 -> V_94 [ V_15 ] , V_61 ) ;
F_22 ( V_9 , V_88 ) ;
return 0 ;
}
static int F_41 ( struct V_134 * V_135 )
{
struct V_136 * V_137 = F_42 ( V_135 -> V_112 . V_138 ) ;
struct V_60 * V_61 ;
struct V_139 * V_140 ;
int V_15 , V_62 ;
V_61 = F_43 ( & V_135 -> V_112 , sizeof( struct V_60 ) ,
V_141 ) ;
if ( V_61 == NULL )
return - V_142 ;
V_61 -> V_137 = V_137 ;
V_61 -> V_91 = ( V_137 -> V_143 == V_144 ) ? V_137 -> V_145
: V_137 -> V_146 ;
V_61 -> V_131 = ( V_137 -> V_143 == V_144 ) ? V_137 -> V_131
: V_137 -> V_147 ;
F_44 ( V_135 , V_61 ) ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_140 = F_45 ( V_135 , V_148 , V_15 ) ;
if ( ! V_140 ) {
F_38 ( & V_135 -> V_112 , L_6 ) ;
return - V_22 ;
}
V_61 -> V_94 [ V_15 ] = V_140 -> V_149 + V_137 -> V_150 ;
strncpy ( V_61 -> V_36 [ V_15 ] , V_140 -> V_36 , V_151 ) ;
}
V_62 = F_46 ( & V_135 -> V_112 , & V_152 ,
V_153 , F_4 ( V_153 ) ) ;
if ( V_62 ) {
F_38 ( & V_135 -> V_112 , L_7 ) ;
return - V_22 ;
}
return V_62 ;
}
static int F_47 ( struct V_134 * V_135 )
{
F_48 ( & V_135 -> V_112 ) ;
return 0 ;
}
