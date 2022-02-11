static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
int V_8 ;
if ( F_3 ( V_5 ) ) {
V_6 -> V_9 [ 5 ] = 1 ;
} else {
V_6 -> V_9 [ 5 ] = 0 ;
F_4 ( V_6 -> V_10 , V_11 ,
V_12 , 0 ) ;
}
V_8 = F_5 ( V_6 -> V_10 , V_13 ,
V_6 -> V_9 , F_6 ( V_6 -> V_9 ) ) ;
if ( F_3 ( V_5 ) ) {
F_7 ( 5 ) ;
F_4 ( V_6 -> V_10 , V_11 ,
V_12 ,
V_12 ) ;
}
return 0 ;
}
static int F_8 ( struct V_3 * V_4 ,
struct V_14 * V_15 )
{
struct V_16 * V_7 = F_9 ( V_4 ) ;
struct V_6 * V_6 = F_2 ( V_7 ) ;
struct V_17 * V_18 = (struct V_17 * ) V_4 -> V_19 ;
struct V_20 V_21 ;
unsigned int V_22 = V_18 -> V_23 ;
unsigned int V_24 , V_25 ;
int V_26 ;
if ( V_15 -> V_27 . V_28 . V_29 [ 0 ] >= V_18 -> V_30 )
return - V_31 ;
switch ( V_15 -> V_27 . V_28 . V_29 [ 0 ] ) {
case 0 :
V_24 = 0 ;
V_6 -> V_32 [ V_22 ] = false ;
break;
default:
V_24 = ( V_6 -> V_33 [ V_22 ] * 2 ) + 1 ;
V_6 -> V_32 [ V_22 ] = true ;
break;
}
if ( V_22 == V_34 )
V_26 = V_35 ;
else
V_26 = V_36 ;
V_25 = F_10 ( V_7 , V_26 , 0xff , V_24 ) ;
if ( V_25 ) {
V_21 . V_4 = V_4 ;
V_21 . V_37 = 0xff ;
V_21 . V_26 = V_26 ;
V_21 . V_24 = V_24 ;
F_11 ( & V_7 -> V_38 , V_4 ,
V_15 -> V_27 . V_28 . V_29 [ 0 ] , V_18 , & V_21 ) ;
}
return V_25 ;
}
static int F_12 ( struct V_3 * V_4 ,
struct V_14 * V_15 )
{
struct V_16 * V_7 = F_9 ( V_4 ) ;
struct V_6 * V_6 = F_2 ( V_7 ) ;
struct V_17 * V_18 = (struct V_17 * ) V_4 -> V_19 ;
unsigned int V_22 = V_18 -> V_23 ;
unsigned int V_26 , V_24 ;
int V_8 ;
if ( V_22 == V_34 )
V_26 = V_35 ;
else
V_26 = V_36 ;
V_8 = F_13 ( V_6 -> V_10 , V_26 , & V_24 ) ;
if ( V_8 )
return V_8 ;
if ( V_24 != 0 )
V_24 = 1 ;
V_15 -> V_27 . V_28 . V_29 [ 0 ] = V_24 ;
return 0 ;
}
bool F_14 ( struct V_6 * V_6 )
{
switch ( V_6 -> type ) {
case V_39 :
case V_40 :
case V_41 :
return true ;
default:
return false ;
}
}
static int F_15 ( struct V_42 * V_43 ,
struct V_44 * V_45 , struct V_46 * V_47 )
{
struct V_16 * V_7 = V_47 -> V_7 ;
struct V_6 * V_6 = F_2 ( V_7 ) ;
unsigned int V_24 , div , V_48 ;
unsigned int V_49 ;
if ( V_6 -> V_50 == V_51 )
V_49 = V_6 -> V_52 ;
else
V_49 = V_6 -> V_53 ;
if ( V_49 % F_16 ( V_45 ) != 0 )
return - V_31 ;
switch ( V_49 / F_16 ( V_45 ) ) {
case 1024 :
div = 0 ;
V_48 = 1 ;
break;
case 6144 :
div = 1 ;
V_48 = 6 ;
break;
case 4096 :
div = 2 ;
V_48 = 5 ;
break;
case 3072 :
div = 3 ;
V_48 = 4 ;
break;
case 2048 :
div = 4 ;
V_48 = 3 ;
break;
case 1536 :
div = 5 ;
V_48 = 2 ;
break;
case 512 :
div = 6 ;
V_48 = 0 ;
break;
default:
return - V_31 ;
}
F_4 ( V_6 -> V_10 , V_54 ,
V_55 , div ) ;
if ( F_14 ( V_6 ) ) {
F_17 ( V_6 -> V_10 , V_56 , div ) ;
F_17 ( V_6 -> V_10 , V_57 , V_48 ) ;
}
if ( V_6 -> V_58 != V_59 )
return 0 ;
switch ( F_18 ( V_45 ) ) {
case V_60 :
V_24 = V_61 ;
break;
case V_62 :
V_24 = V_63 ;
break;
case V_64 :
V_24 = V_65 ;
break;
default:
return - V_31 ;
}
return F_4 ( V_6 -> V_10 , V_66 ,
V_67 , V_24 ) ;
}
static int F_19 ( struct V_46 * V_47 , int V_68 ,
int V_69 , unsigned int V_70 , unsigned int V_71 )
{
struct V_16 * V_7 = V_47 -> V_7 ;
struct V_6 * V_6 = F_2 ( V_7 ) ;
unsigned int V_72 , V_73 , V_74 , V_75 , V_76 ;
unsigned int div ;
int V_8 ;
if ( V_70 < 8000000 || V_70 > 27000000 )
return - V_31 ;
if ( ! V_71 ) {
V_72 = 0 ;
V_73 = 0 ;
V_74 = 0 ;
div = 0 ;
} else {
if ( V_71 % V_70 != 0 ) {
div = F_20 ( V_70 , 13500000 ) ;
V_70 /= div ;
V_72 = V_71 / V_70 ;
V_75 = V_71 % V_70 ;
V_76 = F_21 ( V_75 , V_70 ) ;
V_73 = V_75 / V_76 ;
V_74 = V_70 / V_76 ;
div -- ;
} else {
V_72 = V_71 / V_70 ;
V_73 = 0 ;
V_74 = 0 ;
div = 0 ;
}
if ( V_73 > 0xffff || V_74 > 0xffff || div > 3 || V_72 > 8 || V_72 < 2 )
return - V_31 ;
}
V_6 -> V_9 [ 0 ] = V_74 >> 8 ;
V_6 -> V_9 [ 1 ] = V_74 & 0xff ;
V_6 -> V_9 [ 2 ] = V_73 >> 8 ;
V_6 -> V_9 [ 3 ] = V_73 & 0xff ;
V_6 -> V_9 [ 4 ] = ( V_72 << 3 ) | ( div << 1 ) ;
if ( V_74 != 0 )
V_6 -> V_9 [ 4 ] |= 1 ;
V_8 = F_5 ( V_6 -> V_10 , V_13 ,
V_6 -> V_9 , F_6 ( V_6 -> V_9 ) ) ;
if ( V_8 )
return V_8 ;
V_6 -> V_52 = V_71 ;
return 0 ;
}
static int F_22 ( struct V_46 * V_47 ,
int V_77 , unsigned int V_49 , int V_78 )
{
struct V_6 * V_6 = F_2 ( V_47 -> V_7 ) ;
struct V_79 * V_38 = & V_47 -> V_7 -> V_38 ;
switch ( V_77 ) {
case V_80 :
case V_51 :
break;
default:
return - V_31 ;
}
V_6 -> V_53 = V_49 ;
if ( V_6 -> V_50 != V_77 ) {
if ( V_77 == V_51 ) {
F_23 ( V_38 ,
& V_81 , 1 ) ;
} else {
F_24 ( V_38 ,
& V_81 , 1 ) ;
}
}
V_6 -> V_50 = V_77 ;
return 0 ;
}
static int F_25 ( struct V_46 * V_47 ,
unsigned int V_82 )
{
struct V_6 * V_6 = F_2 ( V_47 -> V_7 ) ;
unsigned int V_83 , V_84 ;
int V_85 ;
switch ( V_82 & V_86 ) {
case V_87 :
V_83 = V_88 ;
V_6 -> V_89 = true ;
break;
case V_90 :
V_83 = 0 ;
V_6 -> V_89 = false ;
break;
default:
return - V_31 ;
}
switch ( V_82 & V_91 ) {
case V_92 :
V_85 = 0 ;
V_84 = V_93 ;
break;
case V_94 :
case V_59 :
V_85 = 1 ;
V_84 = V_65 ;
break;
case V_95 :
V_85 = 1 ;
V_83 |= V_96 ;
V_84 = V_93 ;
break;
case V_97 :
V_85 = 1 ;
V_83 |= V_96 ;
V_84 = V_65 ;
break;
default:
return - V_31 ;
}
switch ( V_82 & V_98 ) {
case V_99 :
break;
case V_100 :
V_83 |= V_101 ;
break;
case V_102 :
V_85 = ! V_85 ;
break;
case V_103 :
V_83 |= V_101 ;
V_85 = ! V_85 ;
break;
default:
return - V_31 ;
}
if ( V_85 )
V_83 |= V_104 ;
F_17 ( V_6 -> V_10 , V_105 , V_83 ) ;
F_17 ( V_6 -> V_10 , V_66 , V_84 ) ;
V_6 -> V_58 = V_82 & V_91 ;
return 0 ;
}
static int F_26 ( struct V_46 * V_47 ,
unsigned int V_106 , unsigned int V_107 , int V_108 , int V_109 )
{
struct V_6 * V_6 = F_2 ( V_47 -> V_7 ) ;
unsigned int V_110 , V_111 ;
unsigned int V_112 , V_113 ;
if ( V_108 == 0 ) {
V_108 = 2 ;
V_107 = 3 ;
V_106 = 3 ;
V_109 = 32 ;
}
switch ( V_108 ) {
case 2 :
V_110 = V_114 ;
break;
case 4 :
V_110 = V_115 ;
break;
case 8 :
if ( V_6 -> type == V_116 )
return - V_31 ;
V_110 = V_117 ;
break;
default:
return - V_31 ;
}
switch ( V_109 * V_108 ) {
case 32 :
if ( V_6 -> type == V_39 )
return - V_31 ;
V_111 = V_118 ;
break;
case 64 :
V_111 = V_119 ;
break;
case 48 :
V_111 = V_120 ;
break;
case 128 :
V_111 = V_121 ;
break;
case 256 :
if ( V_6 -> type == V_116 )
return - V_31 ;
V_111 = V_122 ;
break;
default:
return - V_31 ;
}
switch ( V_107 ) {
case 0x03 :
V_113 = F_27 ( 1 ) ;
V_6 -> V_33 [ V_123 ] = 0 ;
break;
case 0x0c :
V_113 = F_27 ( 2 ) ;
V_6 -> V_33 [ V_123 ] = 1 ;
break;
case 0x30 :
V_113 = F_27 ( 3 ) ;
V_6 -> V_33 [ V_123 ] = 2 ;
break;
case 0xc0 :
V_113 = F_27 ( 4 ) ;
V_6 -> V_33 [ V_123 ] = 3 ;
break;
default:
return - V_31 ;
}
switch ( V_106 ) {
case 0x03 :
V_112 = F_28 ( 1 ) ;
V_6 -> V_33 [ V_34 ] = 0 ;
break;
case 0x0c :
V_112 = F_28 ( 2 ) ;
V_6 -> V_33 [ V_34 ] = 1 ;
break;
case 0x30 :
V_112 = F_28 ( 3 ) ;
V_6 -> V_33 [ V_34 ] = 2 ;
break;
case 0xc0 :
V_112 = F_28 ( 4 ) ;
V_6 -> V_33 [ V_34 ] = 3 ;
break;
default:
return - V_31 ;
}
F_4 ( V_6 -> V_10 , V_54 ,
V_124 , V_112 ) ;
F_4 ( V_6 -> V_10 , V_125 ,
V_126 , V_113 ) ;
F_4 ( V_6 -> V_10 , V_105 ,
V_127 , V_110 ) ;
F_4 ( V_6 -> V_10 , V_66 ,
V_128 , V_111 ) ;
if ( ! F_14 ( V_6 ) )
return 0 ;
if ( V_6 -> V_32 [ V_34 ] ) {
F_17 ( V_6 -> V_10 , V_35 ,
( V_6 -> V_33 [ V_34 ] * 2 ) + 1 ) ;
}
if ( V_6 -> V_32 [ V_123 ] ) {
F_17 ( V_6 -> V_10 , V_36 ,
( V_6 -> V_33 [ V_123 ] * 2 ) + 1 ) ;
}
return 0 ;
}
int F_29 ( struct V_16 * V_7 ,
enum V_129 V_130 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
switch ( V_130 ) {
case V_131 :
case V_132 :
break;
default:
return - V_31 ;
}
return F_17 ( V_6 -> V_10 , V_133 , V_130 << 2 ) ;
}
bool F_30 ( struct V_134 * V_135 , unsigned int V_26 )
{
switch ( V_26 ) {
case V_11 :
case V_13 :
case V_136 :
case V_133 :
case V_105 :
case V_66 :
case V_54 :
case V_125 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_57 :
case V_35 :
case V_36 :
case V_147 :
case V_148 :
case V_56 :
return true ;
default:
break;
}
return false ;
}
bool F_31 ( struct V_134 * V_135 , unsigned int V_26 )
{
if ( V_26 < 0x4000 )
return true ;
switch ( V_26 ) {
case V_13 :
case V_13 + 1 :
case V_13 + 2 :
case V_13 + 3 :
case V_13 + 4 :
case V_13 + 5 :
return true ;
default:
break;
}
return false ;
}
int F_32 ( struct V_6 * V_6 , struct V_134 * V_135 ,
const char * V_149 )
{
int V_8 ;
int V_150 ;
V_8 = F_13 ( V_6 -> V_10 , V_57 , & V_150 ) ;
if ( V_8 )
return V_8 ;
F_17 ( V_6 -> V_10 , V_147 , 1 ) ;
F_17 ( V_6 -> V_10 , V_57 , 0xf ) ;
V_8 = F_33 ( V_135 , V_6 -> V_10 , V_149 ) ;
if ( V_8 ) {
F_17 ( V_6 -> V_10 , V_147 , 0 ) ;
return V_8 ;
}
F_17 ( V_6 -> V_10 , V_57 , V_150 ) ;
return 0 ;
}
int F_34 ( struct V_16 * V_7 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
int V_8 ;
V_8 = F_35 ( V_7 , V_151 ,
F_6 ( V_151 ) ) ;
if ( V_8 )
return V_8 ;
V_8 = F_36 ( & V_7 -> V_38 , V_152 ,
F_6 ( V_152 ) ) ;
if ( V_8 )
return V_8 ;
if ( F_14 ( V_6 ) ) {
V_8 = F_36 ( & V_7 -> V_38 ,
V_153 ,
F_6 ( V_153 ) ) ;
}
return V_8 ;
}
int F_37 ( struct V_16 * V_7 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
int V_8 ;
V_8 = F_23 ( & V_7 -> V_38 , V_154 ,
F_6 ( V_154 ) ) ;
if ( V_8 )
return V_8 ;
if ( F_14 ( V_6 ) ) {
V_8 = F_23 ( & V_7 -> V_38 ,
V_155 ,
F_6 ( V_155 ) ) ;
} else {
V_8 = F_23 ( & V_7 -> V_38 ,
V_156 ,
F_6 ( V_156 ) ) ;
}
return V_8 ;
}
int F_38 ( struct V_16 * V_7 )
{
V_7 -> V_157 -> V_158 ( V_7 , V_159 ) ;
return 0 ;
}
int F_39 ( struct V_16 * V_7 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
if ( V_6 -> V_160 )
V_6 -> V_160 ( V_7 -> V_135 ) ;
V_7 -> V_157 -> V_158 ( V_7 , V_161 ) ;
F_40 ( V_6 -> V_10 ) ;
return 0 ;
}
int F_41 ( struct V_134 * V_135 , struct V_10 * V_10 ,
enum V_162 type , void (* V_160)( struct V_134 * V_135 ) )
{
struct V_6 * V_6 ;
if ( F_42 ( V_10 ) )
return F_43 ( V_10 ) ;
V_6 = F_44 ( V_135 , sizeof( * V_6 ) , V_163 ) ;
if ( ! V_6 )
return - V_164 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_160 = V_160 ;
V_6 -> type = type ;
F_45 ( V_135 , V_6 ) ;
if ( V_160 )
V_160 ( V_135 ) ;
return 0 ;
}
