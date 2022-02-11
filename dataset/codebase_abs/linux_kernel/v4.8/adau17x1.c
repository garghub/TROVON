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
static int F_17 ( struct V_43 * V_44 , int V_45 ,
int V_46 , unsigned int V_47 , unsigned int V_48 )
{
struct V_6 * V_7 = V_44 -> V_7 ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
if ( V_47 < 8000000 || V_47 > 27000000 )
return - V_33 ;
V_10 = F_18 ( V_47 , V_48 , V_9 -> V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_6 ( V_9 -> V_12 , V_15 ,
V_9 -> V_11 , F_7 ( V_9 -> V_11 ) ) ;
if ( V_10 )
return V_10 ;
V_9 -> V_49 = V_48 ;
return 0 ;
}
static int F_19 ( struct V_43 * V_44 ,
int V_50 , unsigned int V_51 , int V_52 )
{
struct V_18 * V_8 = F_11 ( V_44 -> V_7 ) ;
struct V_9 * V_9 = F_3 ( V_44 -> V_7 ) ;
bool V_53 ;
bool V_54 ;
switch ( V_50 ) {
case V_55 :
V_53 = false ;
break;
case V_56 :
if ( ! V_9 -> V_57 )
return - V_33 ;
case V_58 :
V_53 = true ;
break;
default:
return - V_33 ;
}
switch ( V_9 -> V_59 ) {
case V_55 :
V_54 = false ;
break;
case V_58 :
case V_56 :
V_54 = true ;
break;
default:
return - V_33 ;
}
V_9 -> V_60 = V_51 ;
if ( V_53 != V_54 ) {
if ( V_53 ) {
F_20 ( V_8 ,
& V_61 , 1 ) ;
} else {
F_21 ( V_8 ,
& V_61 , 1 ) ;
}
}
V_9 -> V_59 = V_50 ;
return 0 ;
}
static int F_22 ( struct V_43 * V_44 ,
struct V_62 * V_63 )
{
struct V_9 * V_9 = F_23 ( V_44 ) ;
unsigned int V_64 ;
switch ( F_24 ( V_63 ) ) {
case 48000 :
case 8000 :
case 12000 :
case 16000 :
case 24000 :
case 32000 :
case 96000 :
V_64 = 48000 * 1024 ;
break;
case 44100 :
case 7350 :
case 11025 :
case 14700 :
case 22050 :
case 29400 :
case 88200 :
V_64 = 44100 * 1024 ;
break;
default:
return - V_33 ;
}
return F_17 ( V_44 , V_65 , V_66 ,
F_25 ( V_9 -> V_57 ) , V_64 ) ;
}
static int F_26 ( struct V_67 * V_68 ,
struct V_62 * V_63 , struct V_43 * V_44 )
{
struct V_6 * V_7 = V_44 -> V_7 ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
unsigned int V_26 , div , V_69 ;
unsigned int V_51 ;
int V_10 ;
switch ( V_9 -> V_59 ) {
case V_56 :
V_10 = F_22 ( V_44 , V_63 ) ;
if ( V_10 )
return V_10 ;
case V_58 :
V_51 = V_9 -> V_49 ;
break;
default:
V_51 = V_9 -> V_60 ;
break;
}
if ( V_51 % F_24 ( V_63 ) != 0 )
return - V_33 ;
switch ( V_51 / F_24 ( V_63 ) ) {
case 1024 :
div = 0 ;
V_69 = 1 ;
break;
case 6144 :
div = 1 ;
V_69 = 6 ;
break;
case 4096 :
div = 2 ;
V_69 = 5 ;
break;
case 3072 :
div = 3 ;
V_69 = 4 ;
break;
case 2048 :
div = 4 ;
V_69 = 3 ;
break;
case 1536 :
div = 5 ;
V_69 = 2 ;
break;
case 512 :
div = 6 ;
V_69 = 0 ;
break;
default:
return - V_33 ;
}
F_5 ( V_9 -> V_12 , V_70 ,
V_71 , div ) ;
if ( F_16 ( V_9 ) ) {
F_27 ( V_9 -> V_12 , V_72 , div ) ;
F_27 ( V_9 -> V_12 , V_73 , V_69 ) ;
}
if ( V_9 -> V_74 ) {
V_10 = F_28 ( V_9 , F_24 ( V_63 ) ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_9 -> V_75 != V_76 )
return 0 ;
switch ( F_29 ( V_63 ) ) {
case 16 :
V_26 = V_77 ;
break;
case 24 :
V_26 = V_78 ;
break;
case 32 :
V_26 = V_79 ;
break;
default:
return - V_33 ;
}
return F_5 ( V_9 -> V_12 , V_80 ,
V_81 , V_26 ) ;
}
static int F_30 ( struct V_43 * V_44 ,
unsigned int V_82 )
{
struct V_9 * V_9 = F_3 ( V_44 -> V_7 ) ;
unsigned int V_83 , V_84 ;
int V_85 ;
switch ( V_82 & V_86 ) {
case V_87 :
V_83 = V_88 ;
V_9 -> V_89 = true ;
break;
case V_90 :
V_83 = 0 ;
V_9 -> V_89 = false ;
break;
default:
return - V_33 ;
}
switch ( V_82 & V_91 ) {
case V_92 :
V_85 = 0 ;
V_84 = V_93 ;
break;
case V_94 :
case V_76 :
V_85 = 1 ;
V_84 = V_79 ;
break;
case V_95 :
V_85 = 1 ;
V_83 |= V_96 ;
V_84 = V_93 ;
break;
case V_97 :
V_85 = 1 ;
V_83 |= V_96 ;
V_84 = V_79 ;
break;
default:
return - V_33 ;
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
return - V_33 ;
}
if ( V_85 )
V_83 |= V_104 ;
F_27 ( V_9 -> V_12 , V_105 , V_83 ) ;
F_27 ( V_9 -> V_12 , V_80 , V_84 ) ;
V_9 -> V_75 = V_82 & V_91 ;
return 0 ;
}
static int F_31 ( struct V_43 * V_44 ,
unsigned int V_106 , unsigned int V_107 , int V_108 , int V_109 )
{
struct V_9 * V_9 = F_3 ( V_44 -> V_7 ) ;
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
if ( V_9 -> type == V_116 )
return - V_33 ;
V_110 = V_117 ;
break;
default:
return - V_33 ;
}
switch ( V_109 * V_108 ) {
case 32 :
if ( V_9 -> type == V_40 )
return - V_33 ;
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
if ( V_9 -> type == V_116 )
return - V_33 ;
V_111 = V_122 ;
break;
default:
return - V_33 ;
}
switch ( V_107 ) {
case 0x03 :
V_113 = F_32 ( 1 ) ;
V_9 -> V_35 [ V_123 ] = 0 ;
break;
case 0x0c :
V_113 = F_32 ( 2 ) ;
V_9 -> V_35 [ V_123 ] = 1 ;
break;
case 0x30 :
V_113 = F_32 ( 3 ) ;
V_9 -> V_35 [ V_123 ] = 2 ;
break;
case 0xc0 :
V_113 = F_32 ( 4 ) ;
V_9 -> V_35 [ V_123 ] = 3 ;
break;
default:
return - V_33 ;
}
switch ( V_106 ) {
case 0x03 :
V_112 = F_33 ( 1 ) ;
V_9 -> V_35 [ V_36 ] = 0 ;
break;
case 0x0c :
V_112 = F_33 ( 2 ) ;
V_9 -> V_35 [ V_36 ] = 1 ;
break;
case 0x30 :
V_112 = F_33 ( 3 ) ;
V_9 -> V_35 [ V_36 ] = 2 ;
break;
case 0xc0 :
V_112 = F_33 ( 4 ) ;
V_9 -> V_35 [ V_36 ] = 3 ;
break;
default:
return - V_33 ;
}
F_5 ( V_9 -> V_12 , V_70 ,
V_124 , V_112 ) ;
F_5 ( V_9 -> V_12 , V_125 ,
V_126 , V_113 ) ;
F_5 ( V_9 -> V_12 , V_105 ,
V_127 , V_110 ) ;
F_5 ( V_9 -> V_12 , V_80 ,
V_128 , V_111 ) ;
if ( ! F_16 ( V_9 ) )
return 0 ;
if ( V_9 -> V_34 [ V_36 ] ) {
F_27 ( V_9 -> V_12 , V_37 ,
( V_9 -> V_35 [ V_36 ] * 2 ) + 1 ) ;
}
if ( V_9 -> V_34 [ V_123 ] ) {
F_27 ( V_9 -> V_12 , V_38 ,
( V_9 -> V_35 [ V_123 ] * 2 ) + 1 ) ;
}
return 0 ;
}
static int F_34 ( struct V_67 * V_68 ,
struct V_43 * V_44 )
{
struct V_9 * V_9 = F_3 ( V_44 -> V_7 ) ;
if ( V_9 -> V_74 )
return F_35 ( V_9 -> V_74 , V_68 ) ;
return 0 ;
}
int F_36 ( struct V_6 * V_7 ,
enum V_129 V_130 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
switch ( V_130 ) {
case V_131 :
case V_132 :
break;
default:
return - V_33 ;
}
return F_27 ( V_9 -> V_12 , V_133 , V_130 << 2 ) ;
}
bool F_37 ( struct V_134 * V_135 , unsigned int V_28 )
{
if ( V_28 < 0x400 )
return true ;
return false ;
}
bool F_38 ( struct V_134 * V_135 , unsigned int V_28 )
{
if ( V_28 < 0x400 )
return true ;
switch ( V_28 ) {
case V_13 :
case V_15 :
case V_136 :
case V_133 :
case V_105 :
case V_80 :
case V_70 :
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
case V_73 :
case V_37 :
case V_38 :
case V_147 :
case V_148 :
case V_72 :
return true ;
default:
break;
}
return false ;
}
bool F_39 ( struct V_134 * V_135 , unsigned int V_28 )
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
int F_28 ( struct V_9 * V_9 , unsigned int V_149 )
{
int V_10 ;
int V_150 ;
V_10 = F_15 ( V_9 -> V_12 , V_73 , & V_150 ) ;
if ( V_10 )
return V_10 ;
F_27 ( V_9 -> V_12 , V_147 , 1 ) ;
F_27 ( V_9 -> V_12 , V_73 , 0xf ) ;
V_10 = F_40 ( V_9 -> V_74 , V_149 ) ;
if ( V_10 ) {
F_27 ( V_9 -> V_12 , V_147 , 0 ) ;
return V_10 ;
}
F_27 ( V_9 -> V_12 , V_73 , V_150 ) ;
return 0 ;
}
int F_41 ( struct V_6 * V_7 )
{
struct V_18 * V_8 = F_11 ( V_7 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
V_10 = F_42 ( V_7 , V_151 ,
F_7 ( V_151 ) ) ;
if ( V_10 )
return V_10 ;
V_10 = F_43 ( V_8 , V_152 ,
F_7 ( V_152 ) ) ;
if ( V_10 )
return V_10 ;
if ( F_16 ( V_9 ) ) {
V_10 = F_43 ( V_8 , V_153 ,
F_7 ( V_153 ) ) ;
if ( V_10 )
return V_10 ;
if ( ! V_9 -> V_74 )
return 0 ;
V_10 = F_44 ( V_9 -> V_74 , & V_7 -> V_154 ) ;
if ( V_10 ) {
F_45 ( V_7 -> V_135 , L_1 ,
V_10 ) ;
return V_10 ;
}
}
return 0 ;
}
int F_46 ( struct V_6 * V_7 )
{
struct V_18 * V_8 = F_11 ( V_7 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
V_10 = F_20 ( V_8 , V_155 ,
F_7 ( V_155 ) ) ;
if ( V_10 )
return V_10 ;
if ( F_16 ( V_9 ) ) {
V_10 = F_20 ( V_8 , V_156 ,
F_7 ( V_156 ) ) ;
} else {
V_10 = F_20 ( V_8 , V_157 ,
F_7 ( V_157 ) ) ;
}
if ( V_9 -> V_59 != V_55 )
F_20 ( V_8 , & V_61 , 1 ) ;
return V_10 ;
}
int F_47 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_158 )
V_9 -> V_158 ( V_7 -> V_135 ) ;
F_48 ( V_9 -> V_12 ) ;
return 0 ;
}
int F_49 ( struct V_134 * V_135 , struct V_12 * V_12 ,
enum V_159 type , void (* V_158)( struct V_134 * V_135 ) ,
const char * V_160 )
{
struct V_9 * V_9 ;
int V_10 ;
if ( F_50 ( V_12 ) )
return F_51 ( V_12 ) ;
V_9 = F_52 ( V_135 , sizeof( * V_9 ) , V_161 ) ;
if ( ! V_9 )
return - V_162 ;
V_9 -> V_57 = F_53 ( V_135 , L_2 ) ;
if ( F_50 ( V_9 -> V_57 ) ) {
if ( F_51 ( V_9 -> V_57 ) != - V_163 )
return F_51 ( V_9 -> V_57 ) ;
V_9 -> V_57 = NULL ;
} else if ( V_9 -> V_57 ) {
V_9 -> V_59 = V_56 ;
V_10 = F_18 ( F_25 ( V_9 -> V_57 ) , 48000 * 1024 ,
V_9 -> V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_54 ( V_9 -> V_57 ) ;
if ( V_10 )
return V_10 ;
}
V_9 -> V_12 = V_12 ;
V_9 -> V_158 = V_158 ;
V_9 -> type = type ;
F_55 ( V_135 , V_9 ) ;
if ( V_160 ) {
V_9 -> V_74 = F_56 ( V_135 , V_12 , NULL ,
V_160 ) ;
if ( F_50 ( V_9 -> V_74 ) ) {
F_57 ( V_135 , L_3 ,
F_51 ( V_9 -> V_74 ) ) ;
V_9 -> V_74 = NULL ;
}
}
if ( V_158 )
V_158 ( V_135 ) ;
return 0 ;
}
void F_58 ( struct V_134 * V_135 )
{
struct V_9 * V_9 = F_59 ( V_135 ) ;
F_60 ( V_135 ) ;
if ( V_9 -> V_57 )
F_61 ( V_9 -> V_57 ) ;
}
