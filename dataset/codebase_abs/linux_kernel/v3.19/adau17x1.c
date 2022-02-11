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
struct V_9 * V_9 = F_3 ( V_7 ) ;
struct V_18 * V_19 = (struct V_18 * ) V_4 -> V_20 ;
struct V_21 V_22 ;
unsigned int V_23 = V_19 -> V_24 ;
unsigned int V_25 , V_26 ;
int V_27 ;
if ( V_17 -> V_28 . V_29 . V_30 [ 0 ] >= V_19 -> V_31 )
return - V_32 ;
switch ( V_17 -> V_28 . V_29 . V_30 [ 0 ] ) {
case 0 :
V_25 = 0 ;
V_9 -> V_33 [ V_23 ] = false ;
break;
default:
V_25 = ( V_9 -> V_34 [ V_23 ] * 2 ) + 1 ;
V_9 -> V_33 [ V_23 ] = true ;
break;
}
if ( V_23 == V_35 )
V_27 = V_36 ;
else
V_27 = V_37 ;
V_26 = F_11 ( V_7 , V_27 , 0xff , V_25 ) ;
if ( V_26 ) {
V_22 . V_4 = V_4 ;
V_22 . V_38 = 0xff ;
V_22 . V_27 = V_27 ;
V_22 . V_25 = V_25 ;
F_12 ( & V_7 -> V_8 , V_4 ,
V_17 -> V_28 . V_29 . V_30 [ 0 ] , V_19 , & V_22 ) ;
}
return V_26 ;
}
static int F_13 ( struct V_3 * V_4 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 = F_10 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
struct V_18 * V_19 = (struct V_18 * ) V_4 -> V_20 ;
unsigned int V_23 = V_19 -> V_24 ;
unsigned int V_27 , V_25 ;
int V_10 ;
if ( V_23 == V_35 )
V_27 = V_36 ;
else
V_27 = V_37 ;
V_10 = F_14 ( V_9 -> V_12 , V_27 , & V_25 ) ;
if ( V_10 )
return V_10 ;
if ( V_25 != 0 )
V_25 = 1 ;
V_17 -> V_28 . V_29 . V_30 [ 0 ] = V_25 ;
return 0 ;
}
bool F_15 ( struct V_9 * V_9 )
{
switch ( V_9 -> type ) {
case V_39 :
case V_40 :
case V_41 :
return true ;
default:
return false ;
}
}
static int F_16 ( struct V_42 * V_43 ,
struct V_44 * V_45 , struct V_46 * V_47 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
unsigned int V_25 , div , V_48 ;
unsigned int V_49 ;
int V_10 ;
if ( V_9 -> V_50 == V_51 )
V_49 = V_9 -> V_52 ;
else
V_49 = V_9 -> V_53 ;
if ( V_49 % F_17 ( V_45 ) != 0 )
return - V_32 ;
switch ( V_49 / F_17 ( V_45 ) ) {
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
return - V_32 ;
}
F_5 ( V_9 -> V_12 , V_54 ,
V_55 , div ) ;
if ( F_15 ( V_9 ) ) {
F_18 ( V_9 -> V_12 , V_56 , div ) ;
F_18 ( V_9 -> V_12 , V_57 , V_48 ) ;
}
if ( V_9 -> V_58 ) {
V_10 = F_19 ( V_9 , F_17 ( V_45 ) ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_9 -> V_59 != V_60 )
return 0 ;
switch ( F_20 ( V_45 ) ) {
case 16 :
V_25 = V_61 ;
break;
case 24 :
V_25 = V_62 ;
break;
case 32 :
V_25 = V_63 ;
break;
default:
return - V_32 ;
}
return F_5 ( V_9 -> V_12 , V_64 ,
V_65 , V_25 ) ;
}
static int F_21 ( struct V_46 * V_47 , int V_66 ,
int V_67 , unsigned int V_68 , unsigned int V_69 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
unsigned int V_70 , V_71 , V_72 , V_73 , V_74 ;
unsigned int div ;
int V_10 ;
if ( V_68 < 8000000 || V_68 > 27000000 )
return - V_32 ;
if ( ! V_69 ) {
V_70 = 0 ;
V_71 = 0 ;
V_72 = 0 ;
div = 0 ;
} else {
if ( V_69 % V_68 != 0 ) {
div = F_22 ( V_68 , 13500000 ) ;
V_68 /= div ;
V_70 = V_69 / V_68 ;
V_73 = V_69 % V_68 ;
V_74 = F_23 ( V_73 , V_68 ) ;
V_71 = V_73 / V_74 ;
V_72 = V_68 / V_74 ;
div -- ;
} else {
V_70 = V_69 / V_68 ;
V_71 = 0 ;
V_72 = 0 ;
div = 0 ;
}
if ( V_71 > 0xffff || V_72 > 0xffff || div > 3 || V_70 > 8 || V_70 < 2 )
return - V_32 ;
}
V_9 -> V_11 [ 0 ] = V_72 >> 8 ;
V_9 -> V_11 [ 1 ] = V_72 & 0xff ;
V_9 -> V_11 [ 2 ] = V_71 >> 8 ;
V_9 -> V_11 [ 3 ] = V_71 & 0xff ;
V_9 -> V_11 [ 4 ] = ( V_70 << 3 ) | ( div << 1 ) ;
if ( V_72 != 0 )
V_9 -> V_11 [ 4 ] |= 1 ;
V_10 = F_6 ( V_9 -> V_12 , V_15 ,
V_9 -> V_11 , F_7 ( V_9 -> V_11 ) ) ;
if ( V_10 )
return V_10 ;
V_9 -> V_52 = V_69 ;
return 0 ;
}
static int F_24 ( struct V_46 * V_47 ,
int V_75 , unsigned int V_49 , int V_76 )
{
struct V_9 * V_9 = F_3 ( V_47 -> V_7 ) ;
struct V_77 * V_8 = & V_47 -> V_7 -> V_8 ;
switch ( V_75 ) {
case V_78 :
case V_51 :
break;
default:
return - V_32 ;
}
V_9 -> V_53 = V_49 ;
if ( V_9 -> V_50 != V_75 ) {
if ( V_75 == V_51 ) {
F_25 ( V_8 ,
& V_79 , 1 ) ;
} else {
F_26 ( V_8 ,
& V_79 , 1 ) ;
}
}
V_9 -> V_50 = V_75 ;
return 0 ;
}
static int F_27 ( struct V_46 * V_47 ,
unsigned int V_80 )
{
struct V_9 * V_9 = F_3 ( V_47 -> V_7 ) ;
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
return - V_32 ;
}
switch ( V_80 & V_89 ) {
case V_90 :
V_83 = 0 ;
V_82 = V_91 ;
break;
case V_92 :
case V_60 :
V_83 = 1 ;
V_82 = V_63 ;
break;
case V_93 :
V_83 = 1 ;
V_81 |= V_94 ;
V_82 = V_91 ;
break;
case V_95 :
V_83 = 1 ;
V_81 |= V_94 ;
V_82 = V_63 ;
break;
default:
return - V_32 ;
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
return - V_32 ;
}
if ( V_83 )
V_81 |= V_102 ;
F_18 ( V_9 -> V_12 , V_103 , V_81 ) ;
F_18 ( V_9 -> V_12 , V_64 , V_82 ) ;
V_9 -> V_59 = V_80 & V_89 ;
return 0 ;
}
static int F_28 ( struct V_46 * V_47 ,
unsigned int V_104 , unsigned int V_105 , int V_106 , int V_107 )
{
struct V_9 * V_9 = F_3 ( V_47 -> V_7 ) ;
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
return - V_32 ;
V_108 = V_115 ;
break;
default:
return - V_32 ;
}
switch ( V_107 * V_106 ) {
case 32 :
if ( V_9 -> type == V_39 )
return - V_32 ;
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
return - V_32 ;
V_109 = V_120 ;
break;
default:
return - V_32 ;
}
switch ( V_105 ) {
case 0x03 :
V_111 = F_29 ( 1 ) ;
V_9 -> V_34 [ V_121 ] = 0 ;
break;
case 0x0c :
V_111 = F_29 ( 2 ) ;
V_9 -> V_34 [ V_121 ] = 1 ;
break;
case 0x30 :
V_111 = F_29 ( 3 ) ;
V_9 -> V_34 [ V_121 ] = 2 ;
break;
case 0xc0 :
V_111 = F_29 ( 4 ) ;
V_9 -> V_34 [ V_121 ] = 3 ;
break;
default:
return - V_32 ;
}
switch ( V_104 ) {
case 0x03 :
V_110 = F_30 ( 1 ) ;
V_9 -> V_34 [ V_35 ] = 0 ;
break;
case 0x0c :
V_110 = F_30 ( 2 ) ;
V_9 -> V_34 [ V_35 ] = 1 ;
break;
case 0x30 :
V_110 = F_30 ( 3 ) ;
V_9 -> V_34 [ V_35 ] = 2 ;
break;
case 0xc0 :
V_110 = F_30 ( 4 ) ;
V_9 -> V_34 [ V_35 ] = 3 ;
break;
default:
return - V_32 ;
}
F_5 ( V_9 -> V_12 , V_54 ,
V_122 , V_110 ) ;
F_5 ( V_9 -> V_12 , V_123 ,
V_124 , V_111 ) ;
F_5 ( V_9 -> V_12 , V_103 ,
V_125 , V_108 ) ;
F_5 ( V_9 -> V_12 , V_64 ,
V_126 , V_109 ) ;
if ( ! F_15 ( V_9 ) )
return 0 ;
if ( V_9 -> V_33 [ V_35 ] ) {
F_18 ( V_9 -> V_12 , V_36 ,
( V_9 -> V_34 [ V_35 ] * 2 ) + 1 ) ;
}
if ( V_9 -> V_33 [ V_121 ] ) {
F_18 ( V_9 -> V_12 , V_37 ,
( V_9 -> V_34 [ V_121 ] * 2 ) + 1 ) ;
}
return 0 ;
}
static int F_31 ( struct V_42 * V_43 ,
struct V_46 * V_47 )
{
struct V_9 * V_9 = F_3 ( V_47 -> V_7 ) ;
if ( V_9 -> V_58 )
return F_32 ( V_9 -> V_58 , V_43 ) ;
return 0 ;
}
int F_33 ( struct V_6 * V_7 ,
enum V_127 V_128 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
switch ( V_128 ) {
case V_129 :
case V_130 :
break;
default:
return - V_32 ;
}
return F_18 ( V_9 -> V_12 , V_131 , V_128 << 2 ) ;
}
bool F_34 ( struct V_132 * V_133 , unsigned int V_27 )
{
if ( V_27 < 0x400 )
return true ;
return false ;
}
bool F_35 ( struct V_132 * V_133 , unsigned int V_27 )
{
if ( V_27 < 0x400 )
return true ;
switch ( V_27 ) {
case V_13 :
case V_15 :
case V_134 :
case V_131 :
case V_103 :
case V_64 :
case V_54 :
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
case V_57 :
case V_36 :
case V_37 :
case V_145 :
case V_146 :
case V_56 :
return true ;
default:
break;
}
return false ;
}
bool F_36 ( struct V_132 * V_133 , unsigned int V_27 )
{
if ( V_27 < 0x4000 )
return true ;
switch ( V_27 ) {
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
int F_19 ( struct V_9 * V_9 , unsigned int V_147 )
{
int V_10 ;
int V_148 ;
V_10 = F_14 ( V_9 -> V_12 , V_57 , & V_148 ) ;
if ( V_10 )
return V_10 ;
F_18 ( V_9 -> V_12 , V_145 , 1 ) ;
F_18 ( V_9 -> V_12 , V_57 , 0xf ) ;
V_10 = F_37 ( V_9 -> V_58 , V_147 ) ;
if ( V_10 ) {
F_18 ( V_9 -> V_12 , V_145 , 0 ) ;
return V_10 ;
}
F_18 ( V_9 -> V_12 , V_57 , V_148 ) ;
return 0 ;
}
int F_38 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
V_10 = F_39 ( V_7 , V_149 ,
F_7 ( V_149 ) ) ;
if ( V_10 )
return V_10 ;
V_10 = F_40 ( & V_7 -> V_8 , V_150 ,
F_7 ( V_150 ) ) ;
if ( V_10 )
return V_10 ;
if ( F_15 ( V_9 ) ) {
V_10 = F_40 ( & V_7 -> V_8 ,
V_151 ,
F_7 ( V_151 ) ) ;
if ( V_10 )
return V_10 ;
if ( ! V_9 -> V_58 )
return 0 ;
V_10 = F_41 ( V_9 -> V_58 , & V_7 -> V_152 ) ;
if ( V_10 ) {
F_42 ( V_7 -> V_133 , L_1 ,
V_10 ) ;
return V_10 ;
}
}
return 0 ;
}
int F_43 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
V_10 = F_25 ( & V_7 -> V_8 , V_153 ,
F_7 ( V_153 ) ) ;
if ( V_10 )
return V_10 ;
if ( F_15 ( V_9 ) ) {
V_10 = F_25 ( & V_7 -> V_8 ,
V_154 ,
F_7 ( V_154 ) ) ;
} else {
V_10 = F_25 ( & V_7 -> V_8 ,
V_155 ,
F_7 ( V_155 ) ) ;
}
return V_10 ;
}
int F_44 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_156 )
V_9 -> V_156 ( V_7 -> V_133 ) ;
F_45 ( V_9 -> V_12 ) ;
return 0 ;
}
int F_46 ( struct V_132 * V_133 , struct V_12 * V_12 ,
enum V_157 type , void (* V_156)( struct V_132 * V_133 ) ,
const char * V_158 )
{
struct V_9 * V_9 ;
if ( F_47 ( V_12 ) )
return F_48 ( V_12 ) ;
V_9 = F_49 ( V_133 , sizeof( * V_9 ) , V_159 ) ;
if ( ! V_9 )
return - V_160 ;
V_9 -> V_12 = V_12 ;
V_9 -> V_156 = V_156 ;
V_9 -> type = type ;
F_50 ( V_133 , V_9 ) ;
if ( V_158 ) {
V_9 -> V_58 = F_51 ( V_133 , V_12 , NULL ,
V_158 ) ;
if ( F_47 ( V_9 -> V_58 ) ) {
F_52 ( V_133 , L_2 ,
F_48 ( V_9 -> V_58 ) ) ;
V_9 -> V_58 = NULL ;
}
}
if ( V_156 )
V_156 ( V_133 ) ;
return 0 ;
}
