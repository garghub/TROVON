static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
if ( F_4 ( V_5 ) ) {
V_9 -> V_11 [ 5 ] = 1 ;
} else {
V_9 -> V_11 [ 5 ] = 0 ;
F_5 ( V_9 -> V_12 , V_13 ,
V_14 , 0 ) ;
}
V_10 = F_6 ( V_9 -> V_12 , V_15 ,
V_9 -> V_11 , F_7 ( V_9 -> V_11 ) ) ;
if ( F_4 ( V_5 ) ) {
F_8 ( 5 ) ;
F_5 ( V_9 -> V_12 , V_13 ,
V_14 ,
V_14 ) ;
}
return 0 ;
}
static int F_9 ( struct V_3 * V_4 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 = F_10 ( V_4 ) ;
struct V_18 * V_8 = F_11 ( V_7 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
struct V_19 * V_20 = (struct V_19 * ) V_4 -> V_21 ;
struct V_22 V_23 ;
unsigned int V_24 = V_20 -> V_25 ;
unsigned int V_26 , V_27 ;
int V_28 ;
if ( V_17 -> V_29 . V_30 . V_31 [ 0 ] >= V_20 -> V_32 )
return - V_33 ;
switch ( V_17 -> V_29 . V_30 . V_31 [ 0 ] ) {
case 0 :
V_26 = 0 ;
V_9 -> V_34 [ V_24 ] = false ;
break;
default:
V_26 = ( V_9 -> V_35 [ V_24 ] * 2 ) + 1 ;
V_9 -> V_34 [ V_24 ] = true ;
break;
}
if ( V_24 == V_36 )
V_28 = V_37 ;
else
V_28 = V_38 ;
V_27 = F_12 ( V_7 , V_28 , 0xff , V_26 ) ;
if ( V_27 ) {
V_23 . V_4 = V_4 ;
V_23 . V_39 = 0xff ;
V_23 . V_28 = V_28 ;
V_23 . V_26 = V_26 ;
F_13 ( V_8 , V_4 ,
V_17 -> V_29 . V_30 . V_31 [ 0 ] , V_20 , & V_23 ) ;
}
return V_27 ;
}
static int F_14 ( struct V_3 * V_4 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 = F_10 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
struct V_19 * V_20 = (struct V_19 * ) V_4 -> V_21 ;
unsigned int V_24 = V_20 -> V_25 ;
unsigned int V_28 , V_26 ;
int V_10 ;
if ( V_24 == V_36 )
V_28 = V_37 ;
else
V_28 = V_38 ;
V_10 = F_15 ( V_9 -> V_12 , V_28 , & V_26 ) ;
if ( V_10 )
return V_10 ;
if ( V_26 != 0 )
V_26 = 1 ;
V_17 -> V_29 . V_30 . V_31 [ 0 ] = V_26 ;
return 0 ;
}
bool F_16 ( struct V_9 * V_9 )
{
switch ( V_9 -> type ) {
case V_40 :
case V_41 :
case V_42 :
return true ;
default:
return false ;
}
}
static int F_17 ( struct V_43 * V_44 ,
struct V_45 * V_46 , struct V_47 * V_48 )
{
struct V_6 * V_7 = V_48 -> V_7 ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
unsigned int V_26 , div , V_49 ;
unsigned int V_50 ;
int V_10 ;
if ( V_9 -> V_51 == V_52 )
V_50 = V_9 -> V_53 ;
else
V_50 = V_9 -> V_54 ;
if ( V_50 % F_18 ( V_46 ) != 0 )
return - V_33 ;
switch ( V_50 / F_18 ( V_46 ) ) {
case 1024 :
div = 0 ;
V_49 = 1 ;
break;
case 6144 :
div = 1 ;
V_49 = 6 ;
break;
case 4096 :
div = 2 ;
V_49 = 5 ;
break;
case 3072 :
div = 3 ;
V_49 = 4 ;
break;
case 2048 :
div = 4 ;
V_49 = 3 ;
break;
case 1536 :
div = 5 ;
V_49 = 2 ;
break;
case 512 :
div = 6 ;
V_49 = 0 ;
break;
default:
return - V_33 ;
}
F_5 ( V_9 -> V_12 , V_55 ,
V_56 , div ) ;
if ( F_16 ( V_9 ) ) {
F_19 ( V_9 -> V_12 , V_57 , div ) ;
F_19 ( V_9 -> V_12 , V_58 , V_49 ) ;
}
if ( V_9 -> V_59 ) {
V_10 = F_20 ( V_9 , F_18 ( V_46 ) ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_9 -> V_60 != V_61 )
return 0 ;
switch ( F_21 ( V_46 ) ) {
case 16 :
V_26 = V_62 ;
break;
case 24 :
V_26 = V_63 ;
break;
case 32 :
V_26 = V_64 ;
break;
default:
return - V_33 ;
}
return F_5 ( V_9 -> V_12 , V_65 ,
V_66 , V_26 ) ;
}
static int F_22 ( struct V_47 * V_48 , int V_67 ,
int V_68 , unsigned int V_69 , unsigned int V_70 )
{
struct V_6 * V_7 = V_48 -> V_7 ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
unsigned int V_71 , V_72 , V_73 , V_74 , V_75 ;
unsigned int div ;
int V_10 ;
if ( V_69 < 8000000 || V_69 > 27000000 )
return - V_33 ;
if ( ! V_70 ) {
V_71 = 0 ;
V_72 = 0 ;
V_73 = 0 ;
div = 0 ;
} else {
if ( V_70 % V_69 != 0 ) {
div = F_23 ( V_69 , 13500000 ) ;
V_69 /= div ;
V_71 = V_70 / V_69 ;
V_74 = V_70 % V_69 ;
V_75 = F_24 ( V_74 , V_69 ) ;
V_72 = V_74 / V_75 ;
V_73 = V_69 / V_75 ;
div -- ;
} else {
V_71 = V_70 / V_69 ;
V_72 = 0 ;
V_73 = 0 ;
div = 0 ;
}
if ( V_72 > 0xffff || V_73 > 0xffff || div > 3 || V_71 > 8 || V_71 < 2 )
return - V_33 ;
}
V_9 -> V_11 [ 0 ] = V_73 >> 8 ;
V_9 -> V_11 [ 1 ] = V_73 & 0xff ;
V_9 -> V_11 [ 2 ] = V_72 >> 8 ;
V_9 -> V_11 [ 3 ] = V_72 & 0xff ;
V_9 -> V_11 [ 4 ] = ( V_71 << 3 ) | ( div << 1 ) ;
if ( V_73 != 0 )
V_9 -> V_11 [ 4 ] |= 1 ;
V_10 = F_6 ( V_9 -> V_12 , V_15 ,
V_9 -> V_11 , F_7 ( V_9 -> V_11 ) ) ;
if ( V_10 )
return V_10 ;
V_9 -> V_53 = V_70 ;
return 0 ;
}
static int F_25 ( struct V_47 * V_48 ,
int V_76 , unsigned int V_50 , int V_77 )
{
struct V_18 * V_8 = F_11 ( V_48 -> V_7 ) ;
struct V_9 * V_9 = F_3 ( V_48 -> V_7 ) ;
switch ( V_76 ) {
case V_78 :
case V_52 :
break;
default:
return - V_33 ;
}
V_9 -> V_54 = V_50 ;
if ( V_9 -> V_51 != V_76 ) {
if ( V_76 == V_52 ) {
F_26 ( V_8 ,
& V_79 , 1 ) ;
} else {
F_27 ( V_8 ,
& V_79 , 1 ) ;
}
}
V_9 -> V_51 = V_76 ;
return 0 ;
}
static int F_28 ( struct V_47 * V_48 ,
unsigned int V_80 )
{
struct V_9 * V_9 = F_3 ( V_48 -> V_7 ) ;
unsigned int V_81 , V_82 ;
int V_83 ;
switch ( V_80 & V_84 ) {
case V_85 :
V_81 = V_86 ;
V_9 -> V_87 = true ;
break;
case V_88 :
V_81 = 0 ;
V_9 -> V_87 = false ;
break;
default:
return - V_33 ;
}
switch ( V_80 & V_89 ) {
case V_90 :
V_83 = 0 ;
V_82 = V_91 ;
break;
case V_92 :
case V_61 :
V_83 = 1 ;
V_82 = V_64 ;
break;
case V_93 :
V_83 = 1 ;
V_81 |= V_94 ;
V_82 = V_91 ;
break;
case V_95 :
V_83 = 1 ;
V_81 |= V_94 ;
V_82 = V_64 ;
break;
default:
return - V_33 ;
}
switch ( V_80 & V_96 ) {
case V_97 :
break;
case V_98 :
V_81 |= V_99 ;
break;
case V_100 :
V_83 = ! V_83 ;
break;
case V_101 :
V_81 |= V_99 ;
V_83 = ! V_83 ;
break;
default:
return - V_33 ;
}
if ( V_83 )
V_81 |= V_102 ;
F_19 ( V_9 -> V_12 , V_103 , V_81 ) ;
F_19 ( V_9 -> V_12 , V_65 , V_82 ) ;
V_9 -> V_60 = V_80 & V_89 ;
return 0 ;
}
static int F_29 ( struct V_47 * V_48 ,
unsigned int V_104 , unsigned int V_105 , int V_106 , int V_107 )
{
struct V_9 * V_9 = F_3 ( V_48 -> V_7 ) ;
unsigned int V_108 , V_109 ;
unsigned int V_110 , V_111 ;
if ( V_106 == 0 ) {
V_106 = 2 ;
V_105 = 3 ;
V_104 = 3 ;
V_107 = 32 ;
}
switch ( V_106 ) {
case 2 :
V_108 = V_112 ;
break;
case 4 :
V_108 = V_113 ;
break;
case 8 :
if ( V_9 -> type == V_114 )
return - V_33 ;
V_108 = V_115 ;
break;
default:
return - V_33 ;
}
switch ( V_107 * V_106 ) {
case 32 :
if ( V_9 -> type == V_40 )
return - V_33 ;
V_109 = V_116 ;
break;
case 64 :
V_109 = V_117 ;
break;
case 48 :
V_109 = V_118 ;
break;
case 128 :
V_109 = V_119 ;
break;
case 256 :
if ( V_9 -> type == V_114 )
return - V_33 ;
V_109 = V_120 ;
break;
default:
return - V_33 ;
}
switch ( V_105 ) {
case 0x03 :
V_111 = F_30 ( 1 ) ;
V_9 -> V_35 [ V_121 ] = 0 ;
break;
case 0x0c :
V_111 = F_30 ( 2 ) ;
V_9 -> V_35 [ V_121 ] = 1 ;
break;
case 0x30 :
V_111 = F_30 ( 3 ) ;
V_9 -> V_35 [ V_121 ] = 2 ;
break;
case 0xc0 :
V_111 = F_30 ( 4 ) ;
V_9 -> V_35 [ V_121 ] = 3 ;
break;
default:
return - V_33 ;
}
switch ( V_104 ) {
case 0x03 :
V_110 = F_31 ( 1 ) ;
V_9 -> V_35 [ V_36 ] = 0 ;
break;
case 0x0c :
V_110 = F_31 ( 2 ) ;
V_9 -> V_35 [ V_36 ] = 1 ;
break;
case 0x30 :
V_110 = F_31 ( 3 ) ;
V_9 -> V_35 [ V_36 ] = 2 ;
break;
case 0xc0 :
V_110 = F_31 ( 4 ) ;
V_9 -> V_35 [ V_36 ] = 3 ;
break;
default:
return - V_33 ;
}
F_5 ( V_9 -> V_12 , V_55 ,
V_122 , V_110 ) ;
F_5 ( V_9 -> V_12 , V_123 ,
V_124 , V_111 ) ;
F_5 ( V_9 -> V_12 , V_103 ,
V_125 , V_108 ) ;
F_5 ( V_9 -> V_12 , V_65 ,
V_126 , V_109 ) ;
if ( ! F_16 ( V_9 ) )
return 0 ;
if ( V_9 -> V_34 [ V_36 ] ) {
F_19 ( V_9 -> V_12 , V_37 ,
( V_9 -> V_35 [ V_36 ] * 2 ) + 1 ) ;
}
if ( V_9 -> V_34 [ V_121 ] ) {
F_19 ( V_9 -> V_12 , V_38 ,
( V_9 -> V_35 [ V_121 ] * 2 ) + 1 ) ;
}
return 0 ;
}
static int F_32 ( struct V_43 * V_44 ,
struct V_47 * V_48 )
{
struct V_9 * V_9 = F_3 ( V_48 -> V_7 ) ;
if ( V_9 -> V_59 )
return F_33 ( V_9 -> V_59 , V_44 ) ;
return 0 ;
}
int F_34 ( struct V_6 * V_7 ,
enum V_127 V_128 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
switch ( V_128 ) {
case V_129 :
case V_130 :
break;
default:
return - V_33 ;
}
return F_19 ( V_9 -> V_12 , V_131 , V_128 << 2 ) ;
}
bool F_35 ( struct V_132 * V_133 , unsigned int V_28 )
{
if ( V_28 < 0x400 )
return true ;
return false ;
}
bool F_36 ( struct V_132 * V_133 , unsigned int V_28 )
{
if ( V_28 < 0x400 )
return true ;
switch ( V_28 ) {
case V_13 :
case V_15 :
case V_134 :
case V_131 :
case V_103 :
case V_65 :
case V_55 :
case V_123 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_58 :
case V_37 :
case V_38 :
case V_145 :
case V_146 :
case V_57 :
return true ;
default:
break;
}
return false ;
}
bool F_37 ( struct V_132 * V_133 , unsigned int V_28 )
{
if ( V_28 < 0x4000 )
return true ;
switch ( V_28 ) {
case V_15 :
case V_15 + 1 :
case V_15 + 2 :
case V_15 + 3 :
case V_15 + 4 :
case V_15 + 5 :
return true ;
default:
break;
}
return false ;
}
int F_20 ( struct V_9 * V_9 , unsigned int V_147 )
{
int V_10 ;
int V_148 ;
V_10 = F_15 ( V_9 -> V_12 , V_58 , & V_148 ) ;
if ( V_10 )
return V_10 ;
F_19 ( V_9 -> V_12 , V_145 , 1 ) ;
F_19 ( V_9 -> V_12 , V_58 , 0xf ) ;
V_10 = F_38 ( V_9 -> V_59 , V_147 ) ;
if ( V_10 ) {
F_19 ( V_9 -> V_12 , V_145 , 0 ) ;
return V_10 ;
}
F_19 ( V_9 -> V_12 , V_58 , V_148 ) ;
return 0 ;
}
int F_39 ( struct V_6 * V_7 )
{
struct V_18 * V_8 = F_11 ( V_7 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
V_10 = F_40 ( V_7 , V_149 ,
F_7 ( V_149 ) ) ;
if ( V_10 )
return V_10 ;
V_10 = F_41 ( V_8 , V_150 ,
F_7 ( V_150 ) ) ;
if ( V_10 )
return V_10 ;
if ( F_16 ( V_9 ) ) {
V_10 = F_41 ( V_8 , V_151 ,
F_7 ( V_151 ) ) ;
if ( V_10 )
return V_10 ;
if ( ! V_9 -> V_59 )
return 0 ;
V_10 = F_42 ( V_9 -> V_59 , & V_7 -> V_152 ) ;
if ( V_10 ) {
F_43 ( V_7 -> V_133 , L_1 ,
V_10 ) ;
return V_10 ;
}
}
return 0 ;
}
int F_44 ( struct V_6 * V_7 )
{
struct V_18 * V_8 = F_11 ( V_7 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
V_10 = F_26 ( V_8 , V_153 ,
F_7 ( V_153 ) ) ;
if ( V_10 )
return V_10 ;
if ( F_16 ( V_9 ) ) {
V_10 = F_26 ( V_8 , V_154 ,
F_7 ( V_154 ) ) ;
} else {
V_10 = F_26 ( V_8 , V_155 ,
F_7 ( V_155 ) ) ;
}
return V_10 ;
}
int F_45 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_156 )
V_9 -> V_156 ( V_7 -> V_133 ) ;
F_46 ( V_9 -> V_12 ) ;
return 0 ;
}
int F_47 ( struct V_132 * V_133 , struct V_12 * V_12 ,
enum V_157 type , void (* V_156)( struct V_132 * V_133 ) ,
const char * V_158 )
{
struct V_9 * V_9 ;
if ( F_48 ( V_12 ) )
return F_49 ( V_12 ) ;
V_9 = F_50 ( V_133 , sizeof( * V_9 ) , V_159 ) ;
if ( ! V_9 )
return - V_160 ;
V_9 -> V_12 = V_12 ;
V_9 -> V_156 = V_156 ;
V_9 -> type = type ;
F_51 ( V_133 , V_9 ) ;
if ( V_158 ) {
V_9 -> V_59 = F_52 ( V_133 , V_12 , NULL ,
V_158 ) ;
if ( F_48 ( V_9 -> V_59 ) ) {
F_53 ( V_133 , L_2 ,
F_49 ( V_9 -> V_59 ) ) ;
V_9 -> V_59 = NULL ;
}
}
if ( V_156 )
V_156 ( V_133 ) ;
return 0 ;
}
