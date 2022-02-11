static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_5 , V_6 = F_2 ( V_2 -> V_7 ) ;
T_1 V_8 , V_9 ;
int V_10 , V_11 ;
V_5 = V_2 -> V_12 [ V_4 -> V_13 ] ;
if ( V_5 ) {
V_10 = V_6 / V_5 ;
V_4 -> V_14 = 1 << F_3 ( V_10 + 1 ) ;
} else {
V_4 -> V_14 = 8 ;
}
V_5 = V_6 / V_4 -> V_14 ;
V_8 = V_15 / V_5 ;
V_9 = V_4 -> V_16 / V_8 ;
for ( V_11 = 0 ; V_11 < F_4 ( V_17 ) ; V_11 ++ ) {
if ( V_17 [ V_11 ] > V_9 ) {
V_4 -> V_18 = V_11 ;
break;
}
}
for ( V_11 = 0 ; V_11 < F_4 ( V_19 ) ; V_11 ++ )
V_2 -> V_20 [ V_11 ] =
V_5 / ( 6 + V_19 [ V_11 ] *
( 25 + V_17 [ V_4 -> V_18 ] ) ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
V_4 -> V_21 = V_22 ;
V_4 -> V_23 = V_24 ;
V_4 -> V_25 = true ;
V_4 -> V_26 = true ;
V_4 -> V_27 = 12 ;
V_4 -> V_28 = 1 ;
V_4 -> V_13 = V_29 ;
F_1 ( V_2 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_30 = 0 ;
int V_31 = 0 ;
switch ( V_4 -> V_21 ) {
case V_32 :
V_30 |= V_33 ;
break;
case V_34 :
V_30 |= V_35 ;
break;
default:
break;
}
V_30 |= V_36 ;
V_30 |= V_37 ;
switch ( V_4 -> V_23 ) {
case V_24 :
break;
case V_38 :
V_30 |= V_39 ;
break;
case V_40 :
V_30 |= V_41 ;
break;
default:
F_7 ( V_2 -> V_42 , L_1 ) ;
}
if ( V_4 -> V_26 )
V_30 |= V_43 ;
F_8 ( V_30 , V_2 -> V_44 + V_45 ) ;
F_8 ( V_31 , V_2 -> V_44 + V_46 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_47 , V_48 ;
if ( ! V_2 -> V_4 . V_25 )
return;
V_48 = V_49 | V_50 ;
F_8 ( V_48 , V_2 -> V_44 + V_51 ) ;
V_47 = F_10 ( V_2 -> V_44 + V_46 ) ;
F_8 ( V_47 | V_52 , V_2 -> V_44 + V_46 ) ;
if ( ! F_11 ( & V_2 -> V_53 , V_54 ) )
F_7 ( V_2 -> V_42 , L_2 ) ;
V_47 = F_10 ( V_2 -> V_44 + V_55 ) ;
if ( V_47 & V_56 )
F_7 ( V_2 -> V_42 , L_3 ) ;
V_2 -> V_4 . V_25 = false ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & ( V_2 -> V_4 ) ;
int V_30 ;
V_30 = F_10 ( V_2 -> V_44 + V_45 ) ;
V_30 &= ~ V_36 ;
if ( V_4 -> V_13 == V_29 )
V_30 |= V_36 ;
V_30 &= ~ V_37 ;
if ( V_4 -> V_13 == V_57 )
V_30 |= V_37 ;
F_8 ( V_30 , V_2 -> V_44 + V_45 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & ( V_2 -> V_4 ) ;
int V_30 , V_31 ;
V_30 = F_10 ( V_2 -> V_44 + V_45 ) ;
V_31 = F_10 ( V_2 -> V_44 + V_46 ) ;
V_30 &= ~ V_58 ;
switch ( V_4 -> V_27 ) {
case 8 :
V_30 |= V_59 ;
break;
case 10 :
V_30 |= V_60 ;
break;
case 12 :
V_30 |= V_61 ;
break;
default:
F_7 ( V_2 -> V_42 , L_4 ) ;
break;
}
V_30 &= ~ ( V_62 | V_63 ) ;
switch ( V_4 -> V_14 ) {
case 1 :
break;
case 2 :
V_30 |= V_64 ;
break;
case 4 :
V_30 |= V_65 ;
break;
case 8 :
V_30 |= V_66 ;
break;
case 16 :
switch ( V_4 -> V_21 ) {
case V_22 :
V_30 |= V_67 | V_66 ;
break;
default:
F_7 ( V_2 -> V_42 , L_5 ) ;
break;
}
break;
}
switch ( V_4 -> V_18 ) {
case V_68 :
break;
case V_69 :
V_30 |= V_70 ;
break;
case V_71 :
V_30 |= V_72 ;
break;
case V_73 :
V_30 |= V_74 ;
break;
case V_75 :
V_30 |= V_76 ;
break;
case V_77 :
V_30 |= V_76 ;
V_30 |= V_70 ;
break;
case V_78 :
V_30 |= V_76 ;
V_30 |= V_72 ;
break;
case V_79 :
V_30 |= V_76 ;
V_30 |= V_72 ;
break;
default:
F_7 ( V_2 -> V_42 , L_6 ) ;
}
V_30 &= ~ V_80 ;
V_31 &= ~ V_81 ;
switch ( V_4 -> V_28 ) {
case V_82 :
break;
case V_83 :
V_31 |= V_81 ;
break;
case V_84 :
V_31 |= V_81 ;
V_30 |= V_85 ;
break;
case V_86 :
V_31 |= V_81 ;
V_30 |= V_87 ;
break;
case V_88 :
V_31 |= V_81 ;
V_30 |= V_89 ;
break;
default:
F_7 ( V_2 -> V_42 ,
L_7 ) ;
}
F_8 ( V_30 , V_2 -> V_44 + V_45 ) ;
F_8 ( V_31 , V_2 -> V_44 + V_46 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_13 ( V_2 ) ;
F_9 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static int F_15 ( struct V_90 * V_91 ,
const struct V_92 * V_93 ,
unsigned int V_94 )
{
struct V_1 * V_2 = F_16 ( V_91 ) ;
F_17 ( & V_91 -> V_95 ) ;
V_2 -> V_4 . V_13 = V_94 ;
F_1 ( V_2 ) ;
F_14 ( V_2 ) ;
F_18 ( & V_91 -> V_95 ) ;
return 0 ;
}
static int F_19 ( struct V_90 * V_91 ,
const struct V_92 * V_93 )
{
struct V_1 * V_2 = F_16 ( V_91 ) ;
return V_2 -> V_4 . V_13 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_96 ;
V_96 = F_10 ( V_2 -> V_44 + V_97 ) ;
switch ( V_2 -> V_4 . V_27 ) {
case 8 :
V_96 &= 0xFF ;
break;
case 10 :
V_96 &= 0x3FF ;
break;
case 12 :
V_96 &= 0xFFF ;
break;
default:
break;
}
return V_96 ;
}
static T_2 F_21 ( int V_98 , void * V_99 )
{
struct V_90 * V_91 = (struct V_90 * ) V_99 ;
struct V_1 * V_2 = F_16 ( V_91 ) ;
int V_100 ;
V_100 = F_10 ( V_2 -> V_44 + V_101 ) ;
if ( V_100 & V_102 ) {
V_2 -> V_103 = F_20 ( V_2 ) ;
if ( F_22 ( V_91 ) ) {
V_2 -> V_104 [ 0 ] = V_2 -> V_103 ;
F_23 ( V_91 ,
V_2 -> V_104 , F_24 () ) ;
F_25 ( V_91 -> V_105 ) ;
} else
F_26 ( & V_2 -> V_53 ) ;
}
return V_106 ;
}
static T_3 F_27 ( struct V_107 * V_42 ,
struct V_108 * V_109 , char * V_110 )
{
struct V_1 * V_2 = F_16 ( F_28 ( V_42 ) ) ;
T_4 V_111 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_4 ( V_2 -> V_20 ) ; V_11 ++ )
V_111 += F_29 ( V_110 + V_111 , V_112 - V_111 ,
L_8 , V_2 -> V_20 [ V_11 ] ) ;
V_110 [ V_111 - 1 ] = '\n' ;
return V_111 ;
}
static int F_30 ( struct V_90 * V_91 ,
struct V_92 const * V_93 ,
int * V_113 ,
int * V_114 ,
long V_115 )
{
struct V_1 * V_2 = F_16 ( V_91 ) ;
unsigned int V_48 ;
long V_116 ;
switch ( V_115 ) {
case V_117 :
case V_118 :
F_17 ( & V_91 -> V_95 ) ;
if ( F_22 ( V_91 ) ) {
F_18 ( & V_91 -> V_95 ) ;
return - V_119 ;
}
F_31 ( & V_2 -> V_53 ) ;
V_48 = F_32 ( V_93 -> V_120 ) ;
V_48 |= V_49 ;
F_8 ( V_48 , V_2 -> V_44 + V_51 ) ;
V_116 = F_33
( & V_2 -> V_53 , V_54 ) ;
if ( V_116 == 0 ) {
F_18 ( & V_91 -> V_95 ) ;
return - V_121 ;
}
if ( V_116 < 0 ) {
F_18 ( & V_91 -> V_95 ) ;
return V_116 ;
}
switch ( V_93 -> type ) {
case V_122 :
* V_113 = V_2 -> V_103 ;
break;
case V_123 :
* V_113 = 25000 - ( ( int ) V_2 -> V_103 - V_124 ) *
1000000 / V_125 ;
break;
default:
F_18 ( & V_91 -> V_95 ) ;
return - V_126 ;
}
F_18 ( & V_91 -> V_95 ) ;
return V_127 ;
case V_128 :
* V_113 = V_2 -> V_129 / 1000 ;
* V_114 = V_2 -> V_4 . V_27 ;
return V_130 ;
case V_131 :
* V_113 = V_2 -> V_20 [ V_2 -> V_4 . V_28 ] ;
* V_114 = 0 ;
return V_127 ;
default:
break;
}
return - V_126 ;
}
static int F_34 ( struct V_90 * V_91 ,
struct V_92 const * V_93 ,
int V_113 ,
int V_114 ,
long V_115 )
{
struct V_1 * V_2 = F_16 ( V_91 ) ;
int V_11 ;
switch ( V_115 ) {
case V_131 :
for ( V_11 = 0 ;
V_11 < F_4 ( V_2 -> V_20 ) ;
V_11 ++ )
if ( V_113 == V_2 -> V_20 [ V_11 ] ) {
V_2 -> V_4 . V_28 = V_11 ;
F_13 ( V_2 ) ;
return 0 ;
}
break;
default:
break;
}
return - V_126 ;
}
static int F_35 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_16 ( V_91 ) ;
unsigned int V_120 ;
int V_116 ;
int V_113 ;
V_116 = F_36 ( V_91 ) ;
if ( V_116 )
return V_116 ;
V_113 = F_10 ( V_2 -> V_44 + V_46 ) ;
V_113 |= V_132 ;
F_8 ( V_113 , V_2 -> V_44 + V_46 ) ;
V_120 = F_37 ( V_91 -> V_133 ,
V_91 -> V_134 ) ;
V_113 = F_32 ( V_120 ) ;
V_113 |= V_49 ;
F_8 ( V_113 , V_2 -> V_44 + V_51 ) ;
return 0 ;
}
static int F_38 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_16 ( V_91 ) ;
unsigned int V_48 = 0 ;
int V_113 ;
V_113 = F_10 ( V_2 -> V_44 + V_46 ) ;
V_113 &= ~ V_132 ;
F_8 ( V_113 , V_2 -> V_44 + V_46 ) ;
V_48 |= V_50 ;
V_48 &= ~ V_49 ;
F_8 ( V_48 , V_2 -> V_44 + V_51 ) ;
return F_39 ( V_91 ) ;
}
static int F_40 ( struct V_90 * V_91 ,
unsigned V_135 , unsigned V_136 ,
unsigned * V_137 )
{
struct V_1 * V_2 = F_16 ( V_91 ) ;
if ( ( V_137 == NULL ) ||
( ( V_135 % 4 ) || ( V_135 > V_138 ) ) )
return - V_126 ;
* V_137 = F_10 ( V_2 -> V_44 + V_135 ) ;
return 0 ;
}
static int F_41 ( struct V_139 * V_140 )
{
struct V_1 * V_2 ;
struct V_90 * V_91 ;
struct V_141 * V_142 ;
int V_98 ;
int V_116 ;
V_91 = F_42 ( & V_140 -> V_42 , sizeof( struct V_1 ) ) ;
if ( ! V_91 ) {
F_7 ( & V_140 -> V_42 , L_9 ) ;
return - V_143 ;
}
V_2 = F_16 ( V_91 ) ;
V_2 -> V_42 = & V_140 -> V_42 ;
V_142 = F_43 ( V_140 , V_144 , 0 ) ;
V_2 -> V_44 = F_44 ( & V_140 -> V_42 , V_142 ) ;
if ( F_45 ( V_2 -> V_44 ) )
return F_46 ( V_2 -> V_44 ) ;
V_98 = F_47 ( V_140 , 0 ) ;
if ( V_98 < 0 ) {
F_7 ( & V_140 -> V_42 , L_10 ) ;
return V_98 ;
}
V_116 = F_48 ( V_2 -> V_42 , V_98 ,
F_21 , 0 ,
F_49 ( & V_140 -> V_42 ) , V_91 ) ;
if ( V_116 < 0 ) {
F_7 ( & V_140 -> V_42 , L_11 , V_98 ) ;
return V_116 ;
}
V_2 -> V_7 = F_50 ( & V_140 -> V_42 , L_12 ) ;
if ( F_45 ( V_2 -> V_7 ) ) {
F_7 ( & V_140 -> V_42 , L_13 ,
F_46 ( V_2 -> V_7 ) ) ;
return F_46 ( V_2 -> V_7 ) ;
}
V_2 -> V_145 = F_51 ( & V_140 -> V_42 , L_14 ) ;
if ( F_45 ( V_2 -> V_145 ) )
return F_46 ( V_2 -> V_145 ) ;
V_116 = F_52 ( V_2 -> V_145 ) ;
if ( V_116 )
return V_116 ;
V_2 -> V_129 = F_53 ( V_2 -> V_145 ) ;
F_54 ( V_140 -> V_42 . V_146 , L_15 ,
V_2 -> V_12 , 3 ) ;
V_116 = F_55 ( V_140 -> V_42 . V_146 , L_16 ,
& V_2 -> V_4 . V_16 ) ;
if ( V_116 )
V_2 -> V_4 . V_16 = V_147 ;
F_56 ( V_140 , V_91 ) ;
F_57 ( & V_2 -> V_53 ) ;
V_91 -> V_148 = F_49 ( & V_140 -> V_42 ) ;
V_91 -> V_42 . V_149 = & V_140 -> V_42 ;
V_91 -> V_42 . V_146 = V_140 -> V_42 . V_146 ;
V_91 -> V_2 = & V_150 ;
V_91 -> V_151 = V_152 ;
V_91 -> V_153 = V_154 ;
V_91 -> V_155 = F_4 ( V_154 ) ;
V_116 = F_58 ( V_2 -> V_7 ) ;
if ( V_116 ) {
F_7 ( & V_140 -> V_42 ,
L_17 ) ;
goto V_156;
}
F_5 ( V_2 ) ;
F_14 ( V_2 ) ;
V_116 = F_59 ( V_91 , & V_157 ,
NULL , & V_158 ) ;
if ( V_116 < 0 ) {
F_7 ( & V_140 -> V_42 , L_18 ) ;
goto V_159;
}
V_116 = F_60 ( V_91 ) ;
if ( V_116 ) {
F_7 ( & V_140 -> V_42 , L_19 ) ;
goto V_160;
}
return 0 ;
V_160:
F_61 ( V_91 ) ;
V_159:
F_62 ( V_2 -> V_7 ) ;
V_156:
F_63 ( V_2 -> V_145 ) ;
return V_116 ;
}
static int F_64 ( struct V_139 * V_140 )
{
struct V_90 * V_91 = F_65 ( V_140 ) ;
struct V_1 * V_2 = F_16 ( V_91 ) ;
F_66 ( V_91 ) ;
F_61 ( V_91 ) ;
F_63 ( V_2 -> V_145 ) ;
F_62 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_67 ( struct V_107 * V_42 )
{
struct V_90 * V_91 = F_68 ( V_42 ) ;
struct V_1 * V_2 = F_16 ( V_91 ) ;
int V_48 ;
V_48 = F_10 ( V_2 -> V_44 + V_51 ) ;
V_48 |= V_50 ;
F_8 ( V_48 , V_2 -> V_44 + V_51 ) ;
F_62 ( V_2 -> V_7 ) ;
F_63 ( V_2 -> V_145 ) ;
return 0 ;
}
static int F_69 ( struct V_107 * V_42 )
{
struct V_90 * V_91 = F_68 ( V_42 ) ;
struct V_1 * V_2 = F_16 ( V_91 ) ;
int V_116 ;
V_116 = F_52 ( V_2 -> V_145 ) ;
if ( V_116 )
return V_116 ;
V_116 = F_58 ( V_2 -> V_7 ) ;
if ( V_116 )
goto V_161;
F_14 ( V_2 ) ;
return 0 ;
V_161:
F_63 ( V_2 -> V_145 ) ;
return V_116 ;
}
