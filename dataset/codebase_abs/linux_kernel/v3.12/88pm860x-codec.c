static int F_1 ( unsigned int V_1 )
{
F_2 ( V_1 >= V_2 ) ;
switch ( V_1 ) {
case V_3 :
return 1 ;
}
return 0 ;
}
static unsigned int F_3 ( struct V_4 * V_5 ,
unsigned int V_1 )
{
unsigned char * V_6 = V_5 -> V_7 ;
F_2 ( V_1 >= V_2 ) ;
if ( F_1 ( V_1 ) )
return V_6 [ V_1 ] ;
V_1 += V_8 ;
return F_4 ( V_5 -> V_9 , V_1 ) ;
}
static int F_5 ( struct V_4 * V_5 ,
unsigned int V_1 , unsigned int V_10 )
{
unsigned char * V_6 = V_5 -> V_7 ;
F_2 ( V_1 >= V_2 ) ;
if ( ! F_1 ( V_1 ) )
V_6 [ V_1 ] = ( unsigned char ) V_10 ;
V_1 += V_8 ;
return F_6 ( V_5 -> V_9 , V_1 , V_10 ) ;
}
static int F_7 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 =
(struct V_15 * ) V_12 -> V_17 ;
struct V_4 * V_5 = F_8 ( V_12 ) ;
unsigned int V_1 = V_16 -> V_1 ;
unsigned int V_18 = V_16 -> V_19 ;
int V_20 [ 2 ] , V_21 [ 2 ] , V_22 ;
V_20 [ 0 ] = F_9 ( V_5 , V_1 ) & 0x3f ;
V_20 [ 1 ] = ( F_9 ( V_5 , V_23 ) >> 4 ) & 0xf ;
V_21 [ 0 ] = F_9 ( V_5 , V_18 ) & 0x3f ;
V_21 [ 1 ] = ( F_9 ( V_5 , V_23 ) ) & 0xf ;
for ( V_22 = 0 ; V_22 < F_10 ( V_24 ) ; V_22 ++ ) {
if ( ( V_24 [ V_22 ] . V_25 == V_20 [ 0 ] ) && ( V_24 [ V_22 ] . V_26 == V_20 [ 1 ] ) )
V_14 -> V_10 . integer . V_10 [ 0 ] = V_22 ;
if ( ( V_24 [ V_22 ] . V_25 == V_21 [ 0 ] ) && ( V_24 [ V_22 ] . V_26 == V_21 [ 1 ] ) )
V_14 -> V_10 . integer . V_10 [ 1 ] = V_22 ;
}
return 0 ;
}
static int F_11 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 =
(struct V_15 * ) V_12 -> V_17 ;
struct V_4 * V_5 = F_8 ( V_12 ) ;
unsigned int V_1 = V_16 -> V_1 ;
unsigned int V_18 = V_16 -> V_19 ;
int V_27 ;
unsigned int V_20 , V_21 ;
V_20 = V_14 -> V_10 . integer . V_10 [ 0 ] ;
V_21 = V_14 -> V_10 . integer . V_10 [ 1 ] ;
if ( V_20 >= F_10 ( V_24 ) || V_21 >= F_10 ( V_24 ) )
return - V_28 ;
V_27 = F_12 ( V_5 , V_1 , 0x3f , V_24 [ V_20 ] . V_25 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_12 ( V_5 , V_23 , 0xf0 ,
V_24 [ V_20 ] . V_26 << 4 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_12 ( V_5 , V_18 , 0x3f , V_24 [ V_21 ] . V_25 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_12 ( V_5 , V_23 , 0x0f ,
V_24 [ V_21 ] . V_26 ) ;
return V_27 ;
}
static int F_13 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 =
(struct V_15 * ) V_12 -> V_17 ;
struct V_4 * V_5 = F_8 ( V_12 ) ;
unsigned int V_1 = V_16 -> V_1 ;
unsigned int V_18 = V_16 -> V_19 ;
unsigned int V_29 = V_16 -> V_29 ;
int V_30 = V_16 -> V_30 , V_20 , V_21 ;
unsigned int V_31 = ( 1 << F_14 ( V_30 ) ) - 1 ;
V_20 = F_9 ( V_5 , V_1 ) >> V_29 ;
V_21 = F_9 ( V_5 , V_18 ) >> V_29 ;
V_14 -> V_10 . integer . V_10 [ 0 ] = ( V_30 - V_20 ) & V_31 ;
V_14 -> V_10 . integer . V_10 [ 1 ] = ( V_30 - V_21 ) & V_31 ;
return 0 ;
}
static int F_15 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 =
(struct V_15 * ) V_12 -> V_17 ;
struct V_4 * V_5 = F_8 ( V_12 ) ;
unsigned int V_1 = V_16 -> V_1 ;
unsigned int V_18 = V_16 -> V_19 ;
unsigned int V_29 = V_16 -> V_29 ;
int V_30 = V_16 -> V_30 ;
unsigned int V_31 = ( 1 << F_14 ( V_30 ) ) - 1 ;
int V_27 ;
unsigned int V_20 , V_21 , V_32 ;
V_32 = V_31 << V_29 ;
V_20 = ( ( V_30 - V_14 -> V_10 . integer . V_10 [ 0 ] ) & V_31 ) ;
V_21 = ( ( V_30 - V_14 -> V_10 . integer . V_10 [ 1 ] ) & V_31 ) ;
V_20 = V_20 << V_29 ;
V_21 = V_21 << V_29 ;
V_27 = F_12 ( V_5 , V_1 , V_32 , V_20 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_12 ( V_5 , V_18 , V_32 , V_21 ) ;
return V_27 ;
}
static int F_16 ( struct V_33 * V_34 ,
struct V_11 * V_12 , int V_35 )
{
struct V_4 * V_5 = V_34 -> V_5 ;
F_12 ( V_5 , V_36 , V_37 , 0 ) ;
F_12 ( V_5 , V_38 ,
V_39 , V_39 ) ;
return 0 ;
}
static int F_17 ( struct V_33 * V_34 ,
struct V_11 * V_12 , int V_35 )
{
struct V_4 * V_5 = V_34 -> V_5 ;
unsigned int V_40 = 0 ;
int V_41 ;
if ( ! strcmp ( V_34 -> V_42 , L_1 ) )
V_40 = V_43 ;
if ( ! strcmp ( V_34 -> V_42 , L_2 ) )
V_40 = V_44 ;
switch ( V_35 ) {
case V_45 :
if ( V_40 ) {
V_40 |= V_46 ;
F_12 ( V_5 , V_36 ,
V_37 , V_37 ) ;
F_12 ( V_5 , V_38 ,
V_39 , V_39 ) ;
F_12 ( V_5 , V_47 ,
V_40 , V_40 ) ;
}
break;
case V_48 :
if ( V_40 ) {
F_12 ( V_5 , V_36 ,
V_37 , V_37 ) ;
F_12 ( V_5 , V_38 ,
V_39 , V_39 ) ;
V_41 = F_9 ( V_5 , V_47 ) ;
V_41 &= ~ V_40 ;
if ( ! ( V_41 & ( V_43 | V_44 ) ) )
V_41 &= ~ V_46 ;
F_18 ( V_5 , V_47 , V_41 ) ;
}
break;
}
return 0 ;
}
static int F_19 ( struct V_49 * V_50 , int V_51 )
{
struct V_4 * V_5 = V_50 -> V_5 ;
int V_41 = 0 , V_31 = V_52 | V_53 ;
if ( V_51 )
V_41 = V_31 ;
F_12 ( V_5 , V_36 , V_31 , V_41 ) ;
F_12 ( V_5 , V_38 ,
V_39 , V_39 ) ;
return 0 ;
}
static int F_20 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_49 * V_58 )
{
struct V_4 * V_5 = V_58 -> V_5 ;
unsigned char V_59 = 0 , V_31 = 0 ;
switch ( F_21 ( V_57 ) ) {
case V_60 :
V_59 &= ~ V_61 ;
break;
case V_62 :
V_59 |= V_61 ;
break;
default:
return - V_28 ;
}
V_31 |= V_61 ;
F_12 ( V_5 , V_63 , V_31 , V_59 ) ;
switch ( F_22 ( V_57 ) ) {
case 8000 :
V_59 = 0 ;
break;
case 16000 :
V_59 = 3 ;
break;
case 32000 :
V_59 = 6 ;
break;
case 48000 :
V_59 = 8 ;
break;
default:
return - V_28 ;
}
F_12 ( V_5 , V_64 , 0x0f , V_59 ) ;
return 0 ;
}
static int F_23 ( struct V_49 * V_50 ,
unsigned int V_65 )
{
struct V_4 * V_5 = V_50 -> V_5 ;
struct V_66 * V_67 = F_24 ( V_5 ) ;
unsigned char V_59 = 0 , V_31 = 0 ;
int V_68 = - V_28 ;
V_31 |= V_69 | V_70 | V_71 ;
switch ( V_65 & V_72 ) {
case V_73 :
case V_74 :
if ( V_67 -> V_75 == V_76 ) {
V_59 |= V_71 ;
V_68 = 0 ;
}
break;
case V_77 :
if ( V_67 -> V_75 == V_78 ) {
V_59 &= ~ V_71 ;
V_68 = 0 ;
}
break;
}
switch ( V_65 & V_79 ) {
case V_80 :
V_59 |= V_81 ;
V_68 = 0 ;
break;
}
V_31 |= V_82 ;
if ( V_68 )
return V_68 ;
F_12 ( V_5 , V_63 , V_31 , V_59 ) ;
return 0 ;
}
static int F_25 ( struct V_49 * V_50 ,
int V_83 , unsigned int V_84 , int V_75 )
{
struct V_4 * V_5 = V_50 -> V_5 ;
struct V_66 * V_67 = F_24 ( V_5 ) ;
if ( V_75 == V_76 )
V_67 -> V_75 = V_76 ;
else {
V_67 -> V_75 = V_78 ;
return - V_28 ;
}
return 0 ;
}
static int F_26 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_49 * V_58 )
{
struct V_4 * V_5 = V_58 -> V_5 ;
unsigned char V_59 ;
switch ( F_21 ( V_57 ) ) {
case V_60 :
V_59 = 0 ;
break;
case V_62 :
V_59 = V_61 ;
break;
default:
return - V_28 ;
}
F_12 ( V_5 , V_85 , V_61 , V_59 ) ;
switch ( F_22 ( V_57 ) ) {
case 8000 :
V_59 = 0 ;
break;
case 11025 :
V_59 = 1 ;
break;
case 16000 :
V_59 = 3 ;
break;
case 22050 :
V_59 = 4 ;
break;
case 32000 :
V_59 = 6 ;
break;
case 44100 :
V_59 = 7 ;
break;
case 48000 :
V_59 = 8 ;
break;
default:
return - V_28 ;
}
F_12 ( V_5 , V_86 , 0xf , V_59 ) ;
return 0 ;
}
static int F_27 ( struct V_49 * V_50 ,
unsigned int V_65 )
{
struct V_4 * V_5 = V_50 -> V_5 ;
struct V_66 * V_67 = F_24 ( V_5 ) ;
unsigned char V_59 = 0 , V_31 = 0 ;
V_31 |= V_69 | V_70 | V_71 ;
switch ( V_65 & V_72 ) {
case V_73 :
if ( V_67 -> V_75 == V_76 )
V_59 |= V_71 ;
else
return - V_28 ;
break;
case V_77 :
if ( V_67 -> V_75 == V_78 )
V_59 &= ~ V_71 ;
else
return - V_28 ;
break;
default:
return - V_28 ;
}
switch ( V_65 & V_79 ) {
case V_80 :
V_59 |= V_81 ;
break;
default:
return - V_28 ;
}
V_31 |= V_82 ;
F_12 ( V_5 , V_85 , V_31 , V_59 ) ;
return 0 ;
}
static int F_28 ( struct V_4 * V_5 ,
enum V_87 V_88 )
{
int V_41 ;
switch ( V_88 ) {
case V_89 :
break;
case V_90 :
break;
case V_91 :
if ( V_5 -> V_92 . V_93 == V_94 ) {
V_41 = V_95 | V_96 ;
F_6 ( V_5 -> V_9 , V_97 , V_41 ) ;
F_29 ( 300 ) ;
V_41 = V_95 | V_98
| V_96 ;
F_6 ( V_5 -> V_9 , V_97 , V_41 ) ;
}
break;
case V_94 :
V_41 = V_95 | V_98 | V_96 ;
F_30 ( V_5 -> V_9 , V_97 , V_41 , 0 ) ;
break;
}
V_5 -> V_92 . V_93 = V_88 ;
return 0 ;
}
static T_1 F_31 ( int V_99 , void * V_41 )
{
struct V_66 * V_67 = V_41 ;
int V_100 , V_101 , V_102 = 0 , V_103 = 0 ;
int V_31 ;
V_100 = F_4 ( V_67 -> V_104 , V_105 ) ;
V_101 = F_4 ( V_67 -> V_104 , V_106 ) ;
V_31 = V_67 -> V_107 . V_108 | V_67 -> V_107 . V_109 | V_67 -> V_107 . V_110
| V_67 -> V_107 . V_111 ;
#ifndef F_32
if ( V_100 & ( V_112 | V_113 | V_114 | V_115 |
V_116 | V_117 ) )
F_33 ( F_34 ( V_67 -> V_5 -> V_118 ) ) ;
#endif
if ( ( V_67 -> V_107 . V_111 & V_119 )
&& ( V_100 & V_112 ) )
V_102 |= V_119 ;
if ( ( V_67 -> V_107 . V_120 & V_121 )
&& ( V_100 & V_113 ) )
V_103 |= V_121 ;
if ( V_67 -> V_107 . V_108 && ( V_101 & ( V_114 | V_115 ) ) )
V_102 |= V_67 -> V_107 . V_108 ;
if ( V_67 -> V_107 . V_109 && ( V_100 & V_122 ) )
V_102 |= V_67 -> V_107 . V_109 ;
if ( V_67 -> V_107 . V_110 && ( V_101 & ( V_116 | V_117 ) ) )
V_102 |= V_67 -> V_107 . V_110 ;
if ( V_102 )
F_35 ( V_67 -> V_107 . V_123 , V_102 , V_31 ) ;
if ( V_103 )
F_35 ( V_67 -> V_107 . V_124 , V_121 ,
V_121 ) ;
F_36 ( V_67 -> V_5 -> V_118 , L_3 ,
V_102 , V_31 ) ;
F_36 ( V_67 -> V_5 -> V_118 , L_4 , V_103 ) ;
return V_125 ;
}
int F_37 ( struct V_4 * V_5 ,
struct V_126 * V_127 ,
int V_107 , int V_128 , int V_108 , int V_110 )
{
struct V_66 * V_67 = F_24 ( V_5 ) ;
int V_41 ;
V_67 -> V_107 . V_123 = V_127 ;
V_67 -> V_107 . V_111 = V_107 ;
V_67 -> V_107 . V_109 = V_128 ;
V_67 -> V_107 . V_108 = V_108 ;
V_67 -> V_107 . V_110 = V_110 ;
if ( V_107 & V_119 )
F_30 ( V_5 -> V_9 , V_129 ,
V_130 , V_130 ) ;
if ( V_108 ) {
V_41 = V_131 | V_132 ;
F_30 ( V_5 -> V_9 , V_106 , V_41 , V_41 ) ;
}
if ( V_110 ) {
V_41 = V_133 | V_134 ;
F_30 ( V_5 -> V_9 , V_106 , V_41 , V_41 ) ;
}
F_31 ( 0 , V_67 ) ;
return 0 ;
}
int F_38 ( struct V_4 * V_5 ,
struct V_126 * V_127 , int V_107 )
{
struct V_66 * V_67 = F_24 ( V_5 ) ;
V_67 -> V_107 . V_124 = V_127 ;
V_67 -> V_107 . V_120 = V_107 ;
if ( V_107 & V_121 )
F_30 ( V_5 -> V_9 , V_135 ,
V_136 , V_136 ) ;
F_31 ( 0 , V_67 ) ;
return 0 ;
}
static int F_39 ( struct V_4 * V_5 )
{
struct V_66 * V_67 = F_24 ( V_5 ) ;
int V_22 , V_68 ;
V_67 -> V_5 = V_5 ;
V_5 -> V_9 = V_67 -> V_104 ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
V_68 = F_40 ( V_67 -> V_99 [ V_22 ] , NULL ,
F_31 , V_137 ,
V_67 -> V_42 [ V_22 ] , V_67 ) ;
if ( V_68 < 0 ) {
F_41 ( V_5 -> V_118 , L_5 ) ;
goto V_138;
}
}
F_28 ( V_5 , V_91 ) ;
V_68 = F_42 ( V_5 -> V_9 , V_8 ,
V_2 , V_5 -> V_7 ) ;
if ( V_68 < 0 ) {
F_41 ( V_5 -> V_118 , L_6 ,
V_68 ) ;
goto V_138;
}
return 0 ;
V_138:
while ( -- V_22 >= 0 )
F_43 ( V_67 -> V_99 [ V_22 ] , V_67 ) ;
return V_68 ;
}
static int F_44 ( struct V_4 * V_5 )
{
struct V_66 * V_67 = F_24 ( V_5 ) ;
int V_22 ;
for ( V_22 = 3 ; V_22 >= 0 ; V_22 -- )
F_43 ( V_67 -> V_99 [ V_22 ] , V_67 ) ;
F_28 ( V_5 , V_94 ) ;
return 0 ;
}
static int F_45 ( struct V_139 * V_140 )
{
struct V_141 * V_142 = F_46 ( V_140 -> V_118 . V_143 ) ;
struct V_66 * V_67 ;
struct V_144 * V_145 ;
int V_22 , V_68 ;
V_67 = F_47 ( & V_140 -> V_118 , sizeof( struct V_66 ) ,
V_146 ) ;
if ( V_67 == NULL )
return - V_147 ;
V_67 -> V_142 = V_142 ;
V_67 -> V_104 = ( V_142 -> V_148 == V_149 ) ? V_142 -> V_150
: V_142 -> V_151 ;
F_48 ( V_140 , V_67 ) ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
V_145 = F_49 ( V_140 , V_152 , V_22 ) ;
if ( ! V_145 ) {
F_41 ( & V_140 -> V_118 , L_7 ) ;
return - V_28 ;
}
V_67 -> V_99 [ V_22 ] = V_145 -> V_153 + V_142 -> V_154 ;
strncpy ( V_67 -> V_42 [ V_22 ] , V_145 -> V_42 , V_155 ) ;
}
V_68 = F_50 ( & V_140 -> V_118 , & V_156 ,
V_157 , F_10 ( V_157 ) ) ;
if ( V_68 ) {
F_41 ( & V_140 -> V_118 , L_8 ) ;
return - V_28 ;
}
return V_68 ;
}
static int F_51 ( struct V_139 * V_140 )
{
F_52 ( & V_140 -> V_118 ) ;
return 0 ;
}
