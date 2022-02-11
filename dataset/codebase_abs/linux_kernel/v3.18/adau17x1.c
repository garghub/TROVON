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
case 16 :
V_24 = V_60 ;
break;
case 24 :
V_24 = V_61 ;
break;
case 32 :
V_24 = V_62 ;
break;
default:
return - V_31 ;
}
return F_4 ( V_6 -> V_10 , V_63 ,
V_64 , V_24 ) ;
}
static int F_19 ( struct V_46 * V_47 , int V_65 ,
int V_66 , unsigned int V_67 , unsigned int V_68 )
{
struct V_16 * V_7 = V_47 -> V_7 ;
struct V_6 * V_6 = F_2 ( V_7 ) ;
unsigned int V_69 , V_70 , V_71 , V_72 , V_73 ;
unsigned int div ;
int V_8 ;
if ( V_67 < 8000000 || V_67 > 27000000 )
return - V_31 ;
if ( ! V_68 ) {
V_69 = 0 ;
V_70 = 0 ;
V_71 = 0 ;
div = 0 ;
} else {
if ( V_68 % V_67 != 0 ) {
div = F_20 ( V_67 , 13500000 ) ;
V_67 /= div ;
V_69 = V_68 / V_67 ;
V_72 = V_68 % V_67 ;
V_73 = F_21 ( V_72 , V_67 ) ;
V_70 = V_72 / V_73 ;
V_71 = V_67 / V_73 ;
div -- ;
} else {
V_69 = V_68 / V_67 ;
V_70 = 0 ;
V_71 = 0 ;
div = 0 ;
}
if ( V_70 > 0xffff || V_71 > 0xffff || div > 3 || V_69 > 8 || V_69 < 2 )
return - V_31 ;
}
V_6 -> V_9 [ 0 ] = V_71 >> 8 ;
V_6 -> V_9 [ 1 ] = V_71 & 0xff ;
V_6 -> V_9 [ 2 ] = V_70 >> 8 ;
V_6 -> V_9 [ 3 ] = V_70 & 0xff ;
V_6 -> V_9 [ 4 ] = ( V_69 << 3 ) | ( div << 1 ) ;
if ( V_71 != 0 )
V_6 -> V_9 [ 4 ] |= 1 ;
V_8 = F_5 ( V_6 -> V_10 , V_13 ,
V_6 -> V_9 , F_6 ( V_6 -> V_9 ) ) ;
if ( V_8 )
return V_8 ;
V_6 -> V_52 = V_68 ;
return 0 ;
}
static int F_22 ( struct V_46 * V_47 ,
int V_74 , unsigned int V_49 , int V_75 )
{
struct V_6 * V_6 = F_2 ( V_47 -> V_7 ) ;
struct V_76 * V_38 = & V_47 -> V_7 -> V_38 ;
switch ( V_74 ) {
case V_77 :
case V_51 :
break;
default:
return - V_31 ;
}
V_6 -> V_53 = V_49 ;
if ( V_6 -> V_50 != V_74 ) {
if ( V_74 == V_51 ) {
F_23 ( V_38 ,
& V_78 , 1 ) ;
} else {
F_24 ( V_38 ,
& V_78 , 1 ) ;
}
}
V_6 -> V_50 = V_74 ;
return 0 ;
}
static int F_25 ( struct V_46 * V_47 ,
unsigned int V_79 )
{
struct V_6 * V_6 = F_2 ( V_47 -> V_7 ) ;
unsigned int V_80 , V_81 ;
int V_82 ;
switch ( V_79 & V_83 ) {
case V_84 :
V_80 = V_85 ;
V_6 -> V_86 = true ;
break;
case V_87 :
V_80 = 0 ;
V_6 -> V_86 = false ;
break;
default:
return - V_31 ;
}
switch ( V_79 & V_88 ) {
case V_89 :
V_82 = 0 ;
V_81 = V_90 ;
break;
case V_91 :
case V_59 :
V_82 = 1 ;
V_81 = V_62 ;
break;
case V_92 :
V_82 = 1 ;
V_80 |= V_93 ;
V_81 = V_90 ;
break;
case V_94 :
V_82 = 1 ;
V_80 |= V_93 ;
V_81 = V_62 ;
break;
default:
return - V_31 ;
}
switch ( V_79 & V_95 ) {
case V_96 :
break;
case V_97 :
V_80 |= V_98 ;
break;
case V_99 :
V_82 = ! V_82 ;
break;
case V_100 :
V_80 |= V_98 ;
V_82 = ! V_82 ;
break;
default:
return - V_31 ;
}
if ( V_82 )
V_80 |= V_101 ;
F_17 ( V_6 -> V_10 , V_102 , V_80 ) ;
F_17 ( V_6 -> V_10 , V_63 , V_81 ) ;
V_6 -> V_58 = V_79 & V_88 ;
return 0 ;
}
static int F_26 ( struct V_46 * V_47 ,
unsigned int V_103 , unsigned int V_104 , int V_105 , int V_106 )
{
struct V_6 * V_6 = F_2 ( V_47 -> V_7 ) ;
unsigned int V_107 , V_108 ;
unsigned int V_109 , V_110 ;
if ( V_105 == 0 ) {
V_105 = 2 ;
V_104 = 3 ;
V_103 = 3 ;
V_106 = 32 ;
}
switch ( V_105 ) {
case 2 :
V_107 = V_111 ;
break;
case 4 :
V_107 = V_112 ;
break;
case 8 :
if ( V_6 -> type == V_113 )
return - V_31 ;
V_107 = V_114 ;
break;
default:
return - V_31 ;
}
switch ( V_106 * V_105 ) {
case 32 :
if ( V_6 -> type == V_39 )
return - V_31 ;
V_108 = V_115 ;
break;
case 64 :
V_108 = V_116 ;
break;
case 48 :
V_108 = V_117 ;
break;
case 128 :
V_108 = V_118 ;
break;
case 256 :
if ( V_6 -> type == V_113 )
return - V_31 ;
V_108 = V_119 ;
break;
default:
return - V_31 ;
}
switch ( V_104 ) {
case 0x03 :
V_110 = F_27 ( 1 ) ;
V_6 -> V_33 [ V_120 ] = 0 ;
break;
case 0x0c :
V_110 = F_27 ( 2 ) ;
V_6 -> V_33 [ V_120 ] = 1 ;
break;
case 0x30 :
V_110 = F_27 ( 3 ) ;
V_6 -> V_33 [ V_120 ] = 2 ;
break;
case 0xc0 :
V_110 = F_27 ( 4 ) ;
V_6 -> V_33 [ V_120 ] = 3 ;
break;
default:
return - V_31 ;
}
switch ( V_103 ) {
case 0x03 :
V_109 = F_28 ( 1 ) ;
V_6 -> V_33 [ V_34 ] = 0 ;
break;
case 0x0c :
V_109 = F_28 ( 2 ) ;
V_6 -> V_33 [ V_34 ] = 1 ;
break;
case 0x30 :
V_109 = F_28 ( 3 ) ;
V_6 -> V_33 [ V_34 ] = 2 ;
break;
case 0xc0 :
V_109 = F_28 ( 4 ) ;
V_6 -> V_33 [ V_34 ] = 3 ;
break;
default:
return - V_31 ;
}
F_4 ( V_6 -> V_10 , V_54 ,
V_121 , V_109 ) ;
F_4 ( V_6 -> V_10 , V_122 ,
V_123 , V_110 ) ;
F_4 ( V_6 -> V_10 , V_102 ,
V_124 , V_107 ) ;
F_4 ( V_6 -> V_10 , V_63 ,
V_125 , V_108 ) ;
if ( ! F_14 ( V_6 ) )
return 0 ;
if ( V_6 -> V_32 [ V_34 ] ) {
F_17 ( V_6 -> V_10 , V_35 ,
( V_6 -> V_33 [ V_34 ] * 2 ) + 1 ) ;
}
if ( V_6 -> V_32 [ V_120 ] ) {
F_17 ( V_6 -> V_10 , V_36 ,
( V_6 -> V_33 [ V_120 ] * 2 ) + 1 ) ;
}
return 0 ;
}
int F_29 ( struct V_16 * V_7 ,
enum V_126 V_127 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
switch ( V_127 ) {
case V_128 :
case V_129 :
break;
default:
return - V_31 ;
}
return F_17 ( V_6 -> V_10 , V_130 , V_127 << 2 ) ;
}
bool F_30 ( struct V_131 * V_132 , unsigned int V_26 )
{
switch ( V_26 ) {
case V_11 :
case V_13 :
case V_133 :
case V_130 :
case V_102 :
case V_63 :
case V_54 :
case V_122 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_57 :
case V_35 :
case V_36 :
case V_144 :
case V_145 :
case V_56 :
return true ;
default:
break;
}
return false ;
}
bool F_31 ( struct V_131 * V_132 , unsigned int V_26 )
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
int F_32 ( struct V_6 * V_6 , struct V_131 * V_132 ,
const char * V_146 )
{
int V_8 ;
int V_147 ;
V_8 = F_13 ( V_6 -> V_10 , V_57 , & V_147 ) ;
if ( V_8 )
return V_8 ;
F_17 ( V_6 -> V_10 , V_144 , 1 ) ;
F_17 ( V_6 -> V_10 , V_57 , 0xf ) ;
V_8 = F_33 ( V_132 , V_6 -> V_10 , V_146 ) ;
if ( V_8 ) {
F_17 ( V_6 -> V_10 , V_144 , 0 ) ;
return V_8 ;
}
F_17 ( V_6 -> V_10 , V_57 , V_147 ) ;
return 0 ;
}
int F_34 ( struct V_16 * V_7 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
int V_8 ;
V_8 = F_35 ( V_7 , V_148 ,
F_6 ( V_148 ) ) ;
if ( V_8 )
return V_8 ;
V_8 = F_36 ( & V_7 -> V_38 , V_149 ,
F_6 ( V_149 ) ) ;
if ( V_8 )
return V_8 ;
if ( F_14 ( V_6 ) ) {
V_8 = F_36 ( & V_7 -> V_38 ,
V_150 ,
F_6 ( V_150 ) ) ;
}
return V_8 ;
}
int F_37 ( struct V_16 * V_7 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
int V_8 ;
V_8 = F_23 ( & V_7 -> V_38 , V_151 ,
F_6 ( V_151 ) ) ;
if ( V_8 )
return V_8 ;
if ( F_14 ( V_6 ) ) {
V_8 = F_23 ( & V_7 -> V_38 ,
V_152 ,
F_6 ( V_152 ) ) ;
} else {
V_8 = F_23 ( & V_7 -> V_38 ,
V_153 ,
F_6 ( V_153 ) ) ;
}
return V_8 ;
}
int F_38 ( struct V_16 * V_7 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
if ( V_6 -> V_154 )
V_6 -> V_154 ( V_7 -> V_132 ) ;
F_39 ( V_6 -> V_10 ) ;
return 0 ;
}
int F_40 ( struct V_131 * V_132 , struct V_10 * V_10 ,
enum V_155 type , void (* V_154)( struct V_131 * V_132 ) )
{
struct V_6 * V_6 ;
if ( F_41 ( V_10 ) )
return F_42 ( V_10 ) ;
V_6 = F_43 ( V_132 , sizeof( * V_6 ) , V_156 ) ;
if ( ! V_6 )
return - V_157 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_154 = V_154 ;
V_6 -> type = type ;
F_44 ( V_132 , V_6 ) ;
if ( V_154 )
V_154 ( V_132 ) ;
return 0 ;
}
