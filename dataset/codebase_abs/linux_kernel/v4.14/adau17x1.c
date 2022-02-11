static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
if ( F_4 ( V_5 ) ) {
V_9 -> V_10 [ 5 ] = 1 ;
} else {
V_9 -> V_10 [ 5 ] = 0 ;
F_5 ( V_9 -> V_11 , V_12 ,
V_13 , 0 ) ;
}
F_6 ( V_9 -> V_11 , V_14 ,
V_9 -> V_10 , F_7 ( V_9 -> V_10 ) ) ;
if ( F_4 ( V_5 ) ) {
F_8 ( 5 ) ;
F_5 ( V_9 -> V_11 , V_12 ,
V_13 ,
V_13 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
F_5 ( V_9 -> V_11 , V_15 ,
V_16 , V_16 ) ;
F_5 ( V_9 -> V_11 , V_15 ,
V_16 , 0 ) ;
return 0 ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_17 * V_18 )
{
struct V_6 * V_7 = F_11 ( V_4 ) ;
struct V_19 * V_8 = F_12 ( V_7 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
struct V_20 * V_21 = (struct V_20 * ) V_4 -> V_22 ;
struct V_23 V_24 = { 0 } ;
unsigned int V_25 = V_21 -> V_26 ;
unsigned int V_27 , V_28 ;
int V_29 ;
if ( V_18 -> V_30 . V_31 . V_32 [ 0 ] >= V_21 -> V_33 )
return - V_34 ;
switch ( V_18 -> V_30 . V_31 . V_32 [ 0 ] ) {
case 0 :
V_27 = 0 ;
V_9 -> V_35 [ V_25 ] = false ;
break;
default:
V_27 = ( V_9 -> V_36 [ V_25 ] * 2 ) + 1 ;
V_9 -> V_35 [ V_25 ] = true ;
break;
}
if ( V_25 == V_37 )
V_29 = V_38 ;
else
V_29 = V_39 ;
V_28 = F_13 ( V_7 , V_29 , 0xff , V_27 ) ;
if ( V_28 ) {
V_24 . V_4 = V_4 ;
V_24 . V_40 = 0xff ;
V_24 . V_29 = V_29 ;
V_24 . V_27 = V_27 ;
F_14 ( V_8 , V_4 ,
V_18 -> V_30 . V_31 . V_32 [ 0 ] , V_21 , & V_24 ) ;
}
return V_28 ;
}
static int F_15 ( struct V_3 * V_4 ,
struct V_17 * V_18 )
{
struct V_6 * V_7 = F_11 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
struct V_20 * V_21 = (struct V_20 * ) V_4 -> V_22 ;
unsigned int V_25 = V_21 -> V_26 ;
unsigned int V_29 , V_27 ;
int V_41 ;
if ( V_25 == V_37 )
V_29 = V_38 ;
else
V_29 = V_39 ;
V_41 = F_16 ( V_9 -> V_11 , V_29 , & V_27 ) ;
if ( V_41 )
return V_41 ;
if ( V_27 != 0 )
V_27 = 1 ;
V_18 -> V_30 . V_31 . V_32 [ 0 ] = V_27 ;
return 0 ;
}
bool F_17 ( struct V_9 * V_9 )
{
switch ( V_9 -> type ) {
case V_42 :
case V_43 :
case V_44 :
return true ;
default:
return false ;
}
}
static int F_18 ( struct V_45 * V_46 , int V_47 ,
int V_48 , unsigned int V_49 , unsigned int V_50 )
{
struct V_6 * V_7 = V_46 -> V_7 ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
int V_41 ;
if ( V_49 < 8000000 || V_49 > 27000000 )
return - V_34 ;
V_41 = F_19 ( V_49 , V_50 , V_9 -> V_10 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_6 ( V_9 -> V_11 , V_14 ,
V_9 -> V_10 , F_7 ( V_9 -> V_10 ) ) ;
if ( V_41 )
return V_41 ;
V_9 -> V_51 = V_50 ;
return 0 ;
}
static int F_20 ( struct V_45 * V_46 ,
int V_52 , unsigned int V_53 , int V_54 )
{
struct V_19 * V_8 = F_12 ( V_46 -> V_7 ) ;
struct V_9 * V_9 = F_3 ( V_46 -> V_7 ) ;
bool V_55 ;
bool V_56 ;
switch ( V_52 ) {
case V_57 :
V_55 = false ;
break;
case V_58 :
if ( ! V_9 -> V_59 )
return - V_34 ;
case V_60 :
V_55 = true ;
break;
default:
return - V_34 ;
}
switch ( V_9 -> V_61 ) {
case V_57 :
V_56 = false ;
break;
case V_60 :
case V_58 :
V_56 = true ;
break;
default:
return - V_34 ;
}
V_9 -> V_62 = V_53 ;
if ( V_55 != V_56 ) {
if ( V_55 ) {
F_21 ( V_8 ,
& V_63 , 1 ) ;
} else {
F_22 ( V_8 ,
& V_63 , 1 ) ;
}
}
V_9 -> V_61 = V_52 ;
return 0 ;
}
static int F_23 ( struct V_45 * V_46 ,
struct V_64 * V_65 )
{
struct V_9 * V_9 = F_24 ( V_46 ) ;
unsigned int V_66 ;
switch ( F_25 ( V_65 ) ) {
case 48000 :
case 8000 :
case 12000 :
case 16000 :
case 24000 :
case 32000 :
case 96000 :
V_66 = 48000 * 1024 ;
break;
case 44100 :
case 7350 :
case 11025 :
case 14700 :
case 22050 :
case 29400 :
case 88200 :
V_66 = 44100 * 1024 ;
break;
default:
return - V_34 ;
}
return F_18 ( V_46 , V_67 , V_68 ,
F_26 ( V_9 -> V_59 ) , V_66 ) ;
}
static int F_27 ( struct V_69 * V_70 ,
struct V_64 * V_65 , struct V_45 * V_46 )
{
struct V_6 * V_7 = V_46 -> V_7 ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
unsigned int V_27 , div , V_71 ;
unsigned int V_53 ;
int V_41 ;
switch ( V_9 -> V_61 ) {
case V_58 :
V_41 = F_23 ( V_46 , V_65 ) ;
if ( V_41 )
return V_41 ;
case V_60 :
V_53 = V_9 -> V_51 ;
break;
default:
V_53 = V_9 -> V_62 ;
break;
}
if ( V_53 % F_25 ( V_65 ) != 0 )
return - V_34 ;
switch ( V_53 / F_25 ( V_65 ) ) {
case 1024 :
div = 0 ;
V_71 = 1 ;
break;
case 6144 :
div = 1 ;
V_71 = 6 ;
break;
case 4096 :
div = 2 ;
V_71 = 5 ;
break;
case 3072 :
div = 3 ;
V_71 = 4 ;
break;
case 2048 :
div = 4 ;
V_71 = 3 ;
break;
case 1536 :
div = 5 ;
V_71 = 2 ;
break;
case 512 :
div = 6 ;
V_71 = 0 ;
break;
default:
return - V_34 ;
}
F_5 ( V_9 -> V_11 , V_15 ,
V_72 , div ) ;
if ( F_17 ( V_9 ) ) {
F_28 ( V_9 -> V_11 , V_73 , div ) ;
F_28 ( V_9 -> V_11 , V_74 , V_71 ) ;
}
if ( V_9 -> V_75 ) {
V_41 = F_29 ( V_9 , F_25 ( V_65 ) ) ;
if ( V_41 < 0 )
return V_41 ;
}
if ( V_9 -> V_76 != V_77 )
return 0 ;
switch ( F_30 ( V_65 ) ) {
case 16 :
V_27 = V_78 ;
break;
case 24 :
V_27 = V_79 ;
break;
case 32 :
V_27 = V_80 ;
break;
default:
return - V_34 ;
}
return F_5 ( V_9 -> V_11 , V_81 ,
V_82 , V_27 ) ;
}
static int F_31 ( struct V_45 * V_46 ,
unsigned int V_83 )
{
struct V_9 * V_9 = F_3 ( V_46 -> V_7 ) ;
unsigned int V_84 , V_85 ;
int V_86 ;
switch ( V_83 & V_87 ) {
case V_88 :
V_84 = V_89 ;
V_9 -> V_90 = true ;
break;
case V_91 :
V_84 = 0 ;
V_9 -> V_90 = false ;
break;
default:
return - V_34 ;
}
switch ( V_83 & V_92 ) {
case V_93 :
V_86 = 0 ;
V_85 = V_94 ;
break;
case V_95 :
case V_77 :
V_86 = 1 ;
V_85 = V_80 ;
break;
case V_96 :
V_86 = 1 ;
V_84 |= V_97 ;
V_85 = V_94 ;
break;
case V_98 :
V_86 = 1 ;
V_84 |= V_97 ;
V_85 = V_80 ;
break;
default:
return - V_34 ;
}
switch ( V_83 & V_99 ) {
case V_100 :
break;
case V_101 :
V_84 |= V_102 ;
break;
case V_103 :
V_86 = ! V_86 ;
break;
case V_104 :
V_84 |= V_102 ;
V_86 = ! V_86 ;
break;
default:
return - V_34 ;
}
if ( V_86 )
V_84 |= V_105 ;
F_28 ( V_9 -> V_11 , V_106 , V_84 ) ;
F_28 ( V_9 -> V_11 , V_81 , V_85 ) ;
V_9 -> V_76 = V_83 & V_92 ;
return 0 ;
}
static int F_32 ( struct V_45 * V_46 ,
unsigned int V_107 , unsigned int V_108 , int V_109 , int V_110 )
{
struct V_9 * V_9 = F_3 ( V_46 -> V_7 ) ;
unsigned int V_111 , V_112 ;
unsigned int V_113 , V_114 ;
if ( V_109 == 0 ) {
V_109 = 2 ;
V_108 = 3 ;
V_107 = 3 ;
V_110 = 32 ;
}
switch ( V_109 ) {
case 2 :
V_111 = V_115 ;
break;
case 4 :
V_111 = V_116 ;
break;
case 8 :
if ( V_9 -> type == V_117 )
return - V_34 ;
V_111 = V_118 ;
break;
default:
return - V_34 ;
}
switch ( V_110 * V_109 ) {
case 32 :
if ( V_9 -> type == V_42 )
return - V_34 ;
V_112 = V_119 ;
break;
case 64 :
V_112 = V_120 ;
break;
case 48 :
V_112 = V_121 ;
break;
case 128 :
V_112 = V_122 ;
break;
case 256 :
if ( V_9 -> type == V_117 )
return - V_34 ;
V_112 = V_123 ;
break;
default:
return - V_34 ;
}
switch ( V_108 ) {
case 0x03 :
V_114 = F_33 ( 1 ) ;
V_9 -> V_36 [ V_124 ] = 0 ;
break;
case 0x0c :
V_114 = F_33 ( 2 ) ;
V_9 -> V_36 [ V_124 ] = 1 ;
break;
case 0x30 :
V_114 = F_33 ( 3 ) ;
V_9 -> V_36 [ V_124 ] = 2 ;
break;
case 0xc0 :
V_114 = F_33 ( 4 ) ;
V_9 -> V_36 [ V_124 ] = 3 ;
break;
default:
return - V_34 ;
}
switch ( V_107 ) {
case 0x03 :
V_113 = F_34 ( 1 ) ;
V_9 -> V_36 [ V_37 ] = 0 ;
break;
case 0x0c :
V_113 = F_34 ( 2 ) ;
V_9 -> V_36 [ V_37 ] = 1 ;
break;
case 0x30 :
V_113 = F_34 ( 3 ) ;
V_9 -> V_36 [ V_37 ] = 2 ;
break;
case 0xc0 :
V_113 = F_34 ( 4 ) ;
V_9 -> V_36 [ V_37 ] = 3 ;
break;
default:
return - V_34 ;
}
F_5 ( V_9 -> V_11 , V_15 ,
V_125 , V_113 ) ;
F_5 ( V_9 -> V_11 , V_126 ,
V_127 , V_114 ) ;
F_5 ( V_9 -> V_11 , V_106 ,
V_128 , V_111 ) ;
F_5 ( V_9 -> V_11 , V_81 ,
V_129 , V_112 ) ;
if ( ! F_17 ( V_9 ) )
return 0 ;
if ( V_9 -> V_35 [ V_37 ] ) {
F_28 ( V_9 -> V_11 , V_38 ,
( V_9 -> V_36 [ V_37 ] * 2 ) + 1 ) ;
}
if ( V_9 -> V_35 [ V_124 ] ) {
F_28 ( V_9 -> V_11 , V_39 ,
( V_9 -> V_36 [ V_124 ] * 2 ) + 1 ) ;
}
return 0 ;
}
static int F_35 ( struct V_69 * V_70 ,
struct V_45 * V_46 )
{
struct V_9 * V_9 = F_3 ( V_46 -> V_7 ) ;
if ( V_9 -> V_75 )
return F_36 ( V_9 -> V_75 , V_70 ) ;
return 0 ;
}
int F_37 ( struct V_6 * V_7 ,
enum V_130 V_131 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
switch ( V_131 ) {
case V_132 :
case V_133 :
break;
default:
return - V_34 ;
}
return F_28 ( V_9 -> V_11 , V_134 , V_131 << 2 ) ;
}
bool F_38 ( struct V_135 * V_136 , unsigned int V_29 )
{
if ( V_29 < 0x400 )
return true ;
return false ;
}
bool F_39 ( struct V_135 * V_136 , unsigned int V_29 )
{
if ( V_29 < 0x400 )
return true ;
switch ( V_29 ) {
case V_12 :
case V_14 :
case V_137 :
case V_134 :
case V_106 :
case V_81 :
case V_15 :
case V_126 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_74 :
case V_38 :
case V_39 :
case V_148 :
case V_149 :
case V_73 :
return true ;
default:
break;
}
return false ;
}
bool F_40 ( struct V_135 * V_136 , unsigned int V_29 )
{
if ( V_29 < 0x4000 )
return true ;
switch ( V_29 ) {
case V_14 :
case V_14 + 1 :
case V_14 + 2 :
case V_14 + 3 :
case V_14 + 4 :
case V_14 + 5 :
return true ;
default:
break;
}
return false ;
}
int F_29 ( struct V_9 * V_9 , unsigned int V_150 )
{
int V_41 ;
int V_151 ;
V_41 = F_16 ( V_9 -> V_11 , V_74 , & V_151 ) ;
if ( V_41 )
return V_41 ;
F_28 ( V_9 -> V_11 , V_148 , 1 ) ;
F_28 ( V_9 -> V_11 , V_74 , 0xf ) ;
V_41 = F_41 ( V_9 -> V_75 , V_150 ) ;
if ( V_41 ) {
F_28 ( V_9 -> V_11 , V_148 , 0 ) ;
return V_41 ;
}
F_28 ( V_9 -> V_11 , V_74 , V_151 ) ;
return 0 ;
}
int F_42 ( struct V_6 * V_7 )
{
struct V_19 * V_8 = F_12 ( V_7 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
int V_41 ;
V_41 = F_43 ( V_7 , V_152 ,
F_7 ( V_152 ) ) ;
if ( V_41 )
return V_41 ;
V_41 = F_44 ( V_8 , V_153 ,
F_7 ( V_153 ) ) ;
if ( V_41 )
return V_41 ;
if ( F_17 ( V_9 ) ) {
V_41 = F_44 ( V_8 , V_154 ,
F_7 ( V_154 ) ) ;
if ( V_41 )
return V_41 ;
if ( ! V_9 -> V_75 )
return 0 ;
V_41 = F_45 ( V_9 -> V_75 , & V_7 -> V_155 ) ;
if ( V_41 ) {
F_46 ( V_7 -> V_136 , L_1 ,
V_41 ) ;
return V_41 ;
}
}
return 0 ;
}
int F_47 ( struct V_6 * V_7 )
{
struct V_19 * V_8 = F_12 ( V_7 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
int V_41 ;
V_41 = F_21 ( V_8 , V_156 ,
F_7 ( V_156 ) ) ;
if ( V_41 )
return V_41 ;
if ( F_17 ( V_9 ) ) {
V_41 = F_21 ( V_8 , V_157 ,
F_7 ( V_157 ) ) ;
} else {
V_41 = F_21 ( V_8 , V_158 ,
F_7 ( V_158 ) ) ;
}
if ( V_9 -> V_61 != V_57 )
F_21 ( V_8 , & V_63 , 1 ) ;
return V_41 ;
}
int F_48 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_159 )
V_9 -> V_159 ( V_7 -> V_136 ) ;
F_49 ( V_9 -> V_11 ) ;
return 0 ;
}
int F_50 ( struct V_135 * V_136 , struct V_11 * V_11 ,
enum V_160 type , void (* V_159)( struct V_135 * V_136 ) ,
const char * V_161 )
{
struct V_9 * V_9 ;
int V_41 ;
if ( F_51 ( V_11 ) )
return F_52 ( V_11 ) ;
V_9 = F_53 ( V_136 , sizeof( * V_9 ) , V_162 ) ;
if ( ! V_9 )
return - V_163 ;
V_9 -> V_59 = F_54 ( V_136 , L_2 ) ;
if ( F_51 ( V_9 -> V_59 ) ) {
if ( F_52 ( V_9 -> V_59 ) != - V_164 )
return F_52 ( V_9 -> V_59 ) ;
V_9 -> V_59 = NULL ;
} else if ( V_9 -> V_59 ) {
V_9 -> V_61 = V_58 ;
V_41 = F_19 ( F_26 ( V_9 -> V_59 ) , 48000 * 1024 ,
V_9 -> V_10 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_55 ( V_9 -> V_59 ) ;
if ( V_41 )
return V_41 ;
}
V_9 -> V_11 = V_11 ;
V_9 -> V_159 = V_159 ;
V_9 -> type = type ;
F_56 ( V_136 , V_9 ) ;
if ( V_161 ) {
V_9 -> V_75 = F_57 ( V_136 , V_11 , NULL ,
V_161 ) ;
if ( F_51 ( V_9 -> V_75 ) ) {
F_58 ( V_136 , L_3 ,
F_52 ( V_9 -> V_75 ) ) ;
V_9 -> V_75 = NULL ;
}
}
if ( V_159 )
V_159 ( V_136 ) ;
return 0 ;
}
void F_59 ( struct V_135 * V_136 )
{
struct V_9 * V_9 = F_60 ( V_136 ) ;
F_61 ( V_136 ) ;
if ( V_9 -> V_59 )
F_62 ( V_9 -> V_59 ) ;
}
