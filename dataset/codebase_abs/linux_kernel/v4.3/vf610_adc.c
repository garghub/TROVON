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
V_8 = V_15 / V_5 ;
V_9 = V_4 -> V_16 / V_8 ;
for ( V_11 = 0 ; V_11 < F_4 ( V_17 ) ; V_11 ++ ) {
if ( V_17 [ V_11 ] > V_9 ) {
V_4 -> V_18 = V_11 ;
break;
}
}
V_5 = V_6 / V_2 -> V_4 . V_14 ;
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
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
int V_100 ;
V_100 = F_10 ( V_2 -> V_44 + V_101 ) ;
if ( V_100 & V_102 ) {
V_2 -> V_103 = F_20 ( V_2 ) ;
F_22 ( & V_2 -> V_53 ) ;
}
return V_104 ;
}
static T_3 F_23 ( struct V_105 * V_42 ,
struct V_106 * V_107 , char * V_108 )
{
struct V_1 * V_2 = F_16 ( F_24 ( V_42 ) ) ;
T_4 V_109 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_4 ( V_2 -> V_20 ) ; V_11 ++ )
V_109 += F_25 ( V_108 + V_109 , V_110 - V_109 ,
L_8 , V_2 -> V_20 [ V_11 ] ) ;
V_108 [ V_109 - 1 ] = '\n' ;
return V_109 ;
}
static int F_26 ( struct V_90 * V_91 ,
struct V_92 const * V_93 ,
int * V_111 ,
int * V_112 ,
long V_113 )
{
struct V_1 * V_2 = F_16 ( V_91 ) ;
unsigned int V_48 ;
long V_114 ;
switch ( V_113 ) {
case V_115 :
case V_116 :
F_17 ( & V_91 -> V_95 ) ;
F_27 ( & V_2 -> V_53 ) ;
V_48 = F_28 ( V_93 -> V_117 ) ;
V_48 |= V_49 ;
F_8 ( V_48 , V_2 -> V_44 + V_51 ) ;
V_114 = F_29
( & V_2 -> V_53 , V_54 ) ;
if ( V_114 == 0 ) {
F_18 ( & V_91 -> V_95 ) ;
return - V_118 ;
}
if ( V_114 < 0 ) {
F_18 ( & V_91 -> V_95 ) ;
return V_114 ;
}
switch ( V_93 -> type ) {
case V_119 :
* V_111 = V_2 -> V_103 ;
break;
case V_120 :
* V_111 = 25000 - ( ( int ) V_2 -> V_103 - 864 ) * 1000000 / 1840 ;
break;
default:
F_18 ( & V_91 -> V_95 ) ;
return - V_121 ;
}
F_18 ( & V_91 -> V_95 ) ;
return V_122 ;
case V_123 :
* V_111 = V_2 -> V_124 / 1000 ;
* V_112 = V_2 -> V_4 . V_27 ;
return V_125 ;
case V_126 :
* V_111 = V_2 -> V_20 [ V_2 -> V_4 . V_28 ] ;
* V_112 = 0 ;
return V_122 ;
default:
break;
}
return - V_121 ;
}
static int F_30 ( struct V_90 * V_91 ,
struct V_92 const * V_93 ,
int V_111 ,
int V_112 ,
long V_113 )
{
struct V_1 * V_2 = F_16 ( V_91 ) ;
int V_11 ;
switch ( V_113 ) {
case V_126 :
for ( V_11 = 0 ;
V_11 < F_4 ( V_2 -> V_20 ) ;
V_11 ++ )
if ( V_111 == V_2 -> V_20 [ V_11 ] ) {
V_2 -> V_4 . V_28 = V_11 ;
F_13 ( V_2 ) ;
return 0 ;
}
break;
default:
break;
}
return - V_121 ;
}
static int F_31 ( struct V_90 * V_91 ,
unsigned V_127 , unsigned V_128 ,
unsigned * V_129 )
{
struct V_1 * V_2 = F_16 ( V_91 ) ;
if ( ( V_129 == NULL ) ||
( ( V_127 % 4 ) || ( V_127 > V_130 ) ) )
return - V_121 ;
* V_129 = F_10 ( V_2 -> V_44 + V_127 ) ;
return 0 ;
}
static int F_32 ( struct V_131 * V_132 )
{
struct V_1 * V_2 ;
struct V_90 * V_91 ;
struct V_133 * V_134 ;
int V_98 ;
int V_114 ;
V_91 = F_33 ( & V_132 -> V_42 , sizeof( struct V_1 ) ) ;
if ( ! V_91 ) {
F_7 ( & V_132 -> V_42 , L_9 ) ;
return - V_135 ;
}
V_2 = F_16 ( V_91 ) ;
V_2 -> V_42 = & V_132 -> V_42 ;
V_134 = F_34 ( V_132 , V_136 , 0 ) ;
V_2 -> V_44 = F_35 ( & V_132 -> V_42 , V_134 ) ;
if ( F_36 ( V_2 -> V_44 ) )
return F_37 ( V_2 -> V_44 ) ;
V_98 = F_38 ( V_132 , 0 ) ;
if ( V_98 < 0 ) {
F_7 ( & V_132 -> V_42 , L_10 ) ;
return V_98 ;
}
V_114 = F_39 ( V_2 -> V_42 , V_98 ,
F_21 , 0 ,
F_40 ( & V_132 -> V_42 ) , V_2 ) ;
if ( V_114 < 0 ) {
F_7 ( & V_132 -> V_42 , L_11 , V_98 ) ;
return V_114 ;
}
V_2 -> V_7 = F_41 ( & V_132 -> V_42 , L_12 ) ;
if ( F_36 ( V_2 -> V_7 ) ) {
F_7 ( & V_132 -> V_42 , L_13 ,
F_37 ( V_2 -> V_7 ) ) ;
return F_37 ( V_2 -> V_7 ) ;
}
V_2 -> V_137 = F_42 ( & V_132 -> V_42 , L_14 ) ;
if ( F_36 ( V_2 -> V_137 ) )
return F_37 ( V_2 -> V_137 ) ;
V_114 = F_43 ( V_2 -> V_137 ) ;
if ( V_114 )
return V_114 ;
V_2 -> V_124 = F_44 ( V_2 -> V_137 ) ;
F_45 ( V_132 -> V_42 . V_138 , L_15 ,
V_2 -> V_12 , 3 ) ;
V_114 = F_46 ( V_132 -> V_42 . V_138 , L_16 ,
& V_2 -> V_4 . V_16 ) ;
if ( V_114 )
V_2 -> V_4 . V_16 = V_139 ;
F_47 ( V_132 , V_91 ) ;
F_48 ( & V_2 -> V_53 ) ;
V_91 -> V_140 = F_40 ( & V_132 -> V_42 ) ;
V_91 -> V_42 . V_141 = & V_132 -> V_42 ;
V_91 -> V_42 . V_138 = V_132 -> V_42 . V_138 ;
V_91 -> V_2 = & V_142 ;
V_91 -> V_143 = V_144 ;
V_91 -> V_145 = V_146 ;
V_91 -> V_147 = F_4 ( V_146 ) ;
V_114 = F_49 ( V_2 -> V_7 ) ;
if ( V_114 ) {
F_7 ( & V_132 -> V_42 ,
L_17 ) ;
goto V_148;
}
F_5 ( V_2 ) ;
F_14 ( V_2 ) ;
V_114 = F_50 ( V_91 ) ;
if ( V_114 ) {
F_7 ( & V_132 -> V_42 , L_18 ) ;
goto V_149;
}
return 0 ;
V_149:
F_51 ( V_2 -> V_7 ) ;
V_148:
F_52 ( V_2 -> V_137 ) ;
return V_114 ;
}
static int F_53 ( struct V_131 * V_132 )
{
struct V_90 * V_91 = F_54 ( V_132 ) ;
struct V_1 * V_2 = F_16 ( V_91 ) ;
F_55 ( V_91 ) ;
F_52 ( V_2 -> V_137 ) ;
F_51 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_56 ( struct V_105 * V_42 )
{
struct V_90 * V_91 = F_57 ( V_42 ) ;
struct V_1 * V_2 = F_16 ( V_91 ) ;
int V_48 ;
V_48 = F_10 ( V_2 -> V_44 + V_51 ) ;
V_48 |= V_50 ;
F_8 ( V_48 , V_2 -> V_44 + V_51 ) ;
F_51 ( V_2 -> V_7 ) ;
F_52 ( V_2 -> V_137 ) ;
return 0 ;
}
static int F_58 ( struct V_105 * V_42 )
{
struct V_90 * V_91 = F_57 ( V_42 ) ;
struct V_1 * V_2 = F_16 ( V_91 ) ;
int V_114 ;
V_114 = F_43 ( V_2 -> V_137 ) ;
if ( V_114 )
return V_114 ;
V_114 = F_49 ( V_2 -> V_7 ) ;
if ( V_114 )
goto V_150;
F_14 ( V_2 ) ;
return 0 ;
V_150:
F_52 ( V_2 -> V_137 ) ;
return V_114 ;
}
