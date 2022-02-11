static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static unsigned int V_5 [] = { 48000 , 96000 } ;
struct V_6 * V_7 =
F_2 ( V_2 , V_8 ) ;
struct V_6 * V_9 =
F_2 ( V_2 , V_10 ) ;
if ( F_3 ( V_7 ) < 6 )
return F_4 ( V_9 , 2 , V_5 , 0 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const struct V_6 V_11 = { . V_12 = 6 , . V_13 = 6 } ;
struct V_6 * V_9 =
F_2 ( V_2 , V_10 ) ;
struct V_6 * V_7 =
F_2 ( V_2 , V_8 ) ;
if ( F_3 ( V_9 ) < 48000 )
return F_6 ( V_7 , & V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 )
{
static unsigned int V_16 [] = { 2 , 6 } ;
static struct V_17 V_18 = {
. V_19 = 2 ,
. V_20 = V_16 ,
} ;
int V_21 ;
V_15 -> V_22 . V_23 = V_24 |
V_25 |
V_26 |
V_27 ;
V_15 -> V_22 . V_28 = 6 ;
V_21 = V_17 ( V_15 , 0 ,
V_8 ,
& V_18 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_8 ( V_15 , 0 , V_10 ,
F_1 , NULL ,
V_8 , - 1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_8 ( V_15 , 0 , V_8 ,
F_5 , NULL ,
V_10 , - 1 ) ;
if ( V_21 < 0 )
return V_21 ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 )
{
V_15 -> V_22 . V_23 = V_24 |
V_25 |
V_26 |
V_29 |
V_27 ;
return 0 ;
}
static int F_10 ( struct V_30 * V_31 )
{
static const struct V_32 V_33 = {
. V_34 = V_35 |
V_36 |
V_37 |
V_38 |
V_39 ,
. V_40 = V_41 ,
. V_42 = 2 ,
. V_28 = 2 ,
. V_43 = 4 * 1024 * 1024 ,
. V_44 = 1 ,
. V_45 = V_46 ,
. V_47 = 1 ,
. V_48 = V_46 ,
} ;
struct V_49 * V_49 = V_31 -> V_50 ;
struct V_14 * V_15 = V_31 -> V_15 ;
int V_21 ;
V_15 -> V_22 = V_33 ;
V_21 = V_49 -> V_51 -> V_52 ( V_15 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_11 ( V_15 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_12 ( V_15 ,
V_53 ,
5000 , 8192000 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_13 ( V_15 , 0 , 32 , 24 ) ;
if ( V_21 < 0 )
return V_21 ;
return 0 ;
}
static int F_14 ( struct V_30 * V_31 )
{
return 0 ;
}
static void F_15 ( struct V_49 * V_49 )
{
if ( V_49 -> V_54 ) {
F_16 ( & V_49 -> V_55 ) ;
F_17 ( & V_49 -> V_56 ) ;
V_49 -> V_54 = false ;
}
}
static int F_18 ( struct V_49 * V_49 , unsigned int V_57 )
{
T_1 * V_58 ;
int V_21 ;
V_58 = F_19 ( 8 , V_59 ) ;
if ( ! V_58 )
return - V_60 ;
V_58 [ 0 ] = 0x00 ;
V_58 [ 1 ] = 0xff ;
V_58 [ 2 ] = 0x19 ;
V_58 [ 3 ] = 0x00 ;
V_58 [ 4 ] = 0x90 ;
V_58 [ 5 ] = 0x00 | V_57 ;
V_58 [ 6 ] = 0xff ;
V_58 [ 7 ] = 0xff ;
V_21 = F_20 ( V_49 -> V_61 , V_58 , 8 , V_58 , 8 ,
F_21 ( 1 ) | F_21 ( 2 ) | F_21 ( 3 ) | F_21 ( 4 ) | F_21 ( 5 ) ) ;
if ( V_21 < 0 )
goto error;
if ( V_21 < 6 || V_58 [ 0 ] != 0x09 ) {
F_22 ( & V_49 -> V_61 -> V_62 , L_1 ) ;
V_21 = - V_63 ;
goto error;
}
V_21 = 0 ;
error:
F_23 ( V_58 ) ;
return V_21 ;
}
static int F_24 ( struct V_30 * V_31 ,
struct V_1 * V_64 )
{
struct V_49 * V_49 = V_31 -> V_50 ;
int V_21 ;
F_25 ( & V_49 -> V_65 ) ;
F_15 ( V_49 ) ;
F_26 ( & V_49 -> V_65 ) ;
V_21 = F_27 ( V_31 ,
F_28 ( V_64 ) ) ;
if ( V_21 < 0 )
goto error;
F_29 ( & V_49 -> V_55 , F_30 ( V_64 ) ) ;
F_31 ( & V_49 -> V_55 , F_32 ( V_64 ) ) ;
F_33 ( & V_49 -> V_55 ,
F_34 ( V_64 ) ) ;
V_21 = F_18 ( V_49 , V_49 -> V_55 . V_57 ) ;
if ( V_21 < 0 )
goto V_66;
return 0 ;
V_66:
F_35 ( V_31 ) ;
error:
return V_21 ;
}
static int F_36 ( struct V_30 * V_31 )
{
struct V_49 * V_49 = V_31 -> V_50 ;
F_25 ( & V_49 -> V_65 ) ;
F_15 ( V_49 ) ;
F_26 ( & V_49 -> V_65 ) ;
return F_35 ( V_31 ) ;
}
static int F_37 ( struct V_30 * V_31 )
{
struct V_49 * V_49 = V_31 -> V_50 ;
int V_21 ;
F_25 ( & V_49 -> V_65 ) ;
if ( F_38 ( & V_49 -> V_55 ) )
F_15 ( V_49 ) ;
if ( ! V_49 -> V_54 ) {
V_21 = F_39 ( & V_49 -> V_56 ,
F_40 ( & V_49 -> V_55 ) ) ;
if ( V_21 < 0 )
goto V_67;
V_21 = F_41 ( & V_49 -> V_55 ,
V_49 -> V_56 . V_68 . V_69 ,
V_49 -> V_56 . V_70 ) ;
if ( V_21 < 0 )
goto V_71;
V_49 -> V_54 = true ;
}
F_26 ( & V_49 -> V_65 ) ;
F_42 ( & V_49 -> V_55 ) ;
return 0 ;
V_71:
F_17 ( & V_49 -> V_56 ) ;
V_67:
F_26 ( & V_49 -> V_65 ) ;
return V_21 ;
}
static int F_43 ( struct V_30 * V_31 , int V_72 )
{
struct V_49 * V_49 = V_31 -> V_50 ;
struct V_30 * V_73 ;
switch ( V_72 ) {
case V_74 :
V_73 = V_31 ;
break;
case V_75 :
V_73 = NULL ;
break;
default:
return - V_76 ;
}
F_44 ( & V_49 -> V_55 , V_73 ) ;
return 0 ;
}
static T_2 F_45 ( struct V_30 * V_31 )
{
struct V_49 * V_49 = V_31 -> V_50 ;
return F_46 ( & V_49 -> V_55 ) ;
}
static int F_47 ( struct V_49 * V_49 )
{
static struct V_77 V_78 = {
. V_79 = F_10 ,
. V_80 = F_14 ,
. V_81 = V_82 ,
. V_64 = F_24 ,
. V_83 = F_36 ,
. V_84 = F_37 ,
. V_85 = F_43 ,
. V_86 = F_45 ,
. V_87 = V_88 ,
. V_89 = V_90 ,
} ;
struct V_91 * V_73 ;
int V_21 ;
V_21 = F_48 ( V_49 -> V_92 , L_2 , 0 , 1 , 0 , & V_73 ) ;
if ( V_21 < 0 )
return V_21 ;
V_73 -> V_50 = V_49 ;
strcpy ( V_73 -> V_93 , V_49 -> V_51 -> V_94 ) ;
V_49 -> V_73 = V_73 -> V_95 [ V_96 ] . V_31 ;
V_49 -> V_73 -> V_78 = & V_78 ;
return 0 ;
}
static int F_49 ( struct V_49 * V_49 , bool * V_97 ,
enum V_98 V_99 )
{
T_1 * V_58 ;
T_1 V_100 ;
int V_21 ;
V_58 = F_19 ( 11 , V_59 ) ;
if ( ! V_58 )
return - V_60 ;
if ( V_99 == V_101 ) {
V_58 [ 0 ] = 0x01 ;
V_100 = 0x0c ;
} else {
V_58 [ 0 ] = 0x00 ;
V_100 = 0x09 ;
}
V_58 [ 1 ] = 0x08 ;
V_58 [ 2 ] = 0xb8 ;
V_58 [ 3 ] = 0x81 ;
V_58 [ 4 ] = V_49 -> V_51 -> V_102 ;
V_58 [ 5 ] = 0x10 ;
V_58 [ 6 ] = 0x02 ;
V_58 [ 7 ] = 0x00 ;
V_58 [ 8 ] = 0x01 ;
V_58 [ 9 ] = 0x01 ;
if ( V_99 == V_101 )
V_58 [ 10 ] = 0xff ;
else
V_58 [ 10 ] = * V_97 ? 0x70 : 0x60 ;
V_21 = F_20 ( V_49 -> V_61 , V_58 , 11 , V_58 , 11 , 0x3fe ) ;
if ( V_21 < 0 )
goto error;
if ( V_21 < 11 ) {
F_22 ( & V_49 -> V_61 -> V_62 , L_3 ) ;
V_21 = - V_63 ;
goto error;
}
if ( V_58 [ 0 ] != V_100 ) {
F_22 ( & V_49 -> V_61 -> V_62 , L_4 ) ;
V_21 = - V_63 ;
goto error;
}
if ( V_99 == V_101 )
* V_97 = V_58 [ 10 ] == 0x70 ;
V_21 = 0 ;
error:
F_23 ( V_58 ) ;
return V_21 ;
}
static int F_50 ( struct V_49 * V_49 , T_3 * V_97 ,
unsigned int V_69 ,
enum V_103 V_104 ,
enum V_98 V_99 )
{
T_1 * V_58 ;
T_1 V_100 ;
int V_21 ;
V_58 = F_19 ( 12 , V_59 ) ;
if ( ! V_58 )
return - V_60 ;
if ( V_99 == V_101 ) {
V_58 [ 0 ] = 0x01 ;
V_100 = 0x0c ;
} else {
V_58 [ 0 ] = 0x00 ;
V_100 = 0x09 ;
}
V_58 [ 1 ] = 0x08 ;
V_58 [ 2 ] = 0xb8 ;
V_58 [ 3 ] = 0x81 ;
V_58 [ 4 ] = V_49 -> V_51 -> V_105 ;
V_58 [ 5 ] = V_104 ;
V_58 [ 6 ] = 0x02 ;
V_58 [ 7 ] = V_69 ;
V_58 [ 8 ] = 0x02 ;
V_58 [ 9 ] = 0x02 ;
if ( V_99 == V_101 ) {
V_58 [ 10 ] = 0xff ;
V_58 [ 11 ] = 0xff ;
} else {
V_58 [ 10 ] = * V_97 >> 8 ;
V_58 [ 11 ] = * V_97 ;
}
V_21 = F_20 ( V_49 -> V_61 , V_58 , 12 , V_58 , 12 , 0x3fe ) ;
if ( V_21 < 0 )
goto error;
if ( V_21 < 12 ) {
F_22 ( & V_49 -> V_61 -> V_62 , L_3 ) ;
V_21 = - V_63 ;
goto error;
}
if ( V_58 [ 0 ] != V_100 ) {
F_22 ( & V_49 -> V_61 -> V_62 , L_5 ) ;
V_21 = - V_63 ;
goto error;
}
if ( V_99 == V_101 )
* V_97 = ( V_58 [ 10 ] << 8 ) | V_58 [ 11 ] ;
V_21 = 0 ;
error:
F_23 ( V_58 ) ;
return V_21 ;
}
static int F_51 ( struct V_106 * V_107 ,
struct V_108 * V_97 )
{
struct V_49 * V_49 = V_107 -> V_50 ;
V_97 -> V_97 . integer . V_97 [ 0 ] = ! V_49 -> V_109 ;
return 0 ;
}
static int F_52 ( struct V_106 * V_107 ,
struct V_108 * V_97 )
{
struct V_49 * V_49 = V_107 -> V_50 ;
bool V_109 ;
int V_21 ;
V_109 = ! V_97 -> V_97 . integer . V_97 [ 0 ] ;
if ( V_109 == V_49 -> V_109 )
return 0 ;
V_21 = F_49 ( V_49 , & V_109 , V_110 ) ;
if ( V_21 < 0 )
return V_21 ;
V_49 -> V_109 = V_109 ;
return 1 ;
}
static int F_53 ( struct V_106 * V_107 ,
struct V_111 * V_34 )
{
struct V_49 * V_49 = V_107 -> V_50 ;
V_34 -> type = V_112 ;
V_34 -> V_19 = V_49 -> V_51 -> V_113 ;
V_34 -> V_97 . integer . V_12 = V_49 -> V_114 ;
V_34 -> V_97 . integer . V_13 = V_49 -> V_115 ;
return 0 ;
}
static int F_54 ( struct V_106 * V_107 ,
struct V_108 * V_97 )
{
struct V_49 * V_49 = V_107 -> V_50 ;
unsigned int V_116 ;
for ( V_116 = 0 ; V_116 < V_49 -> V_51 -> V_113 ; ++ V_116 )
V_97 -> V_97 . integer . V_97 [ V_117 [ V_116 ] ] = V_49 -> V_118 [ V_116 ] ;
return 0 ;
}
static int F_55 ( struct V_106 * V_107 ,
struct V_108 * V_97 )
{
struct V_49 * V_49 = V_107 -> V_50 ;
unsigned int V_116 , V_119 ;
bool V_120 = true ;
T_3 V_118 ;
int V_21 ;
for ( V_116 = 0 ; V_116 < V_49 -> V_51 -> V_113 ; ++ V_116 ) {
if ( V_97 -> V_97 . integer . V_97 [ V_116 ] < V_49 -> V_114 ||
V_97 -> V_97 . integer . V_97 [ V_116 ] > V_49 -> V_115 )
return - V_76 ;
if ( V_97 -> V_97 . integer . V_97 [ V_116 ] !=
V_97 -> V_97 . integer . V_97 [ 0 ] )
V_120 = false ;
}
V_119 = 0 ;
for ( V_116 = 0 ; V_116 < V_49 -> V_51 -> V_113 ; ++ V_116 )
if ( V_97 -> V_97 . integer . V_97 [ V_117 [ V_116 ] ] !=
V_49 -> V_118 [ V_116 ] )
V_119 |= 1 << ( V_116 + 1 ) ;
if ( V_120 && V_119 != 0 )
V_119 = 1 << 0 ;
for ( V_116 = 0 ; V_116 <= V_49 -> V_51 -> V_113 ; ++ V_116 ) {
V_118 = V_97 -> V_97 . integer . V_97 [ V_117 [ V_116 ? V_116 - 1 : 0 ] ] ;
if ( V_119 & ( 1 << V_116 ) ) {
V_21 = F_50 ( V_49 , & V_118 , V_116 ,
V_121 , V_110 ) ;
if ( V_21 < 0 )
return V_21 ;
}
if ( V_116 > 0 )
V_49 -> V_118 [ V_116 - 1 ] = V_118 ;
}
return V_119 != 0 ;
}
static int F_56 ( struct V_49 * V_49 )
{
static const struct V_122 V_123 [] = {
{
. V_124 = V_125 ,
. V_93 = L_6 ,
. V_34 = V_126 ,
. V_127 = F_51 ,
. V_128 = F_52 ,
} ,
{
. V_124 = V_125 ,
. V_93 = L_7 ,
. V_34 = F_53 ,
. V_127 = F_54 ,
. V_128 = F_55 ,
} ,
} ;
unsigned int V_116 , V_129 ;
int V_21 ;
V_21 = F_50 ( V_49 , & V_49 -> V_114 ,
0 , V_130 , V_101 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_50 ( V_49 , & V_49 -> V_115 ,
0 , V_131 , V_101 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_49 ( V_49 , & V_49 -> V_109 , V_101 ) ;
if ( V_21 < 0 )
return V_21 ;
V_129 = V_49 -> V_51 -> V_113 == 1 ? 0 : 1 ;
for ( V_116 = 0 ; V_116 < V_49 -> V_51 -> V_113 ; ++ V_116 ) {
V_21 = F_50 ( V_49 , & V_49 -> V_118 [ V_116 ] ,
V_129 + V_116 , V_121 , V_101 ) ;
if ( V_21 < 0 )
return V_21 ;
}
for ( V_116 = 0 ; V_116 < F_57 ( V_123 ) ; ++ V_116 ) {
V_21 = F_58 ( V_49 -> V_92 ,
F_59 ( & V_123 [ V_116 ] , V_49 ) ) ;
if ( V_21 < 0 )
return V_21 ;
}
return 0 ;
}
static T_4 F_60 ( struct V_132 * V_61 )
{
T_5 V_133 ;
int V_21 ;
V_21 = F_61 ( V_61 , V_134 ,
V_135 , & V_133 , 4 ) ;
return V_21 >= 0 ? F_62 ( V_133 ) : 0 ;
}
static void F_63 ( struct V_136 * V_92 )
{
struct V_49 * V_49 = V_92 -> V_50 ;
struct V_137 * V_138 = F_64 ( V_49 -> V_61 ) ;
F_65 ( & V_49 -> V_55 ) ;
F_66 ( & V_49 -> V_56 ) ;
F_67 ( V_49 -> V_61 ) ;
F_68 ( V_138 ) ;
F_69 ( & V_49 -> V_65 ) ;
}
static const struct V_51 * T_6 F_70 ( struct V_137 * V_138 )
{
static const struct V_51 V_139 = {
. V_140 = L_8 ,
. V_94 = L_8 ,
. V_141 = L_9 ,
. V_52 = F_7 ,
. V_113 = 6 ,
. V_102 = 0x01 ,
. V_105 = 0x02 ,
} ;
static const struct V_51 V_142 = {
. V_140 = L_10 ,
. V_94 = L_11 ,
. V_141 = L_12 ,
. V_52 = F_9 ,
. V_113 = 1 ,
. V_102 = 0x01 ,
. V_105 = 0x01 ,
} ;
struct V_143 V_116 ;
int V_144 , V_97 ;
F_71 ( & V_116 , V_138 -> V_145 ) ;
while ( F_72 ( & V_116 , & V_144 , & V_97 ) )
if ( V_144 == V_146 )
switch ( V_97 ) {
case V_147 :
return & V_139 ;
case V_148 :
return & V_142 ;
}
return NULL ;
}
static int T_6 F_73 ( struct V_62 * V_149 )
{
struct V_132 * V_61 = V_132 ( V_149 ) ;
struct V_137 * V_150 = F_64 ( V_61 ) ;
struct V_136 * V_92 ;
struct V_49 * V_49 ;
T_4 V_151 ;
int V_21 ;
V_21 = F_74 ( - 1 , NULL , V_152 , sizeof( * V_49 ) , & V_92 ) ;
if ( V_21 < 0 )
return V_21 ;
F_75 ( V_92 , V_149 ) ;
V_49 = V_92 -> V_50 ;
V_49 -> V_92 = V_92 ;
F_76 ( & V_49 -> V_65 ) ;
F_77 ( V_150 ) ;
V_49 -> V_61 = F_78 ( V_61 ) ;
V_49 -> V_51 = F_70 ( V_150 ) ;
if ( ! V_49 -> V_51 ) {
V_21 = - V_153 ;
goto V_154;
}
V_21 = F_79 ( & V_49 -> V_56 , V_61 , 0 ) ;
if ( V_21 < 0 )
goto V_154;
V_21 = F_80 ( & V_49 -> V_55 , V_61 , V_155 ) ;
if ( V_21 < 0 )
goto V_71;
V_92 -> V_156 = F_63 ;
strcpy ( V_92 -> V_157 , V_49 -> V_51 -> V_140 ) ;
strcpy ( V_92 -> V_158 , V_49 -> V_51 -> V_94 ) ;
V_151 = F_60 ( V_61 ) ;
snprintf ( V_92 -> V_159 , sizeof( V_92 -> V_159 ) ,
L_13 ,
V_49 -> V_51 -> V_141 ,
V_151 >> 20 , V_151 & 0xffff ,
V_150 -> V_145 [ 3 ] , V_150 -> V_145 [ 4 ] ,
F_81 ( & V_61 -> V_62 ) , 100 << V_150 -> V_160 ) ;
strcpy ( V_92 -> V_161 , L_2 ) ;
V_21 = F_47 ( V_49 ) ;
if ( V_21 < 0 )
goto error;
V_21 = F_56 ( V_49 ) ;
if ( V_21 < 0 )
goto error;
V_21 = F_82 ( V_92 ) ;
if ( V_21 < 0 )
goto error;
F_83 ( V_149 , V_49 ) ;
return 0 ;
V_71:
F_66 ( & V_49 -> V_56 ) ;
V_154:
F_67 ( V_49 -> V_61 ) ;
F_68 ( V_150 ) ;
F_69 ( & V_49 -> V_65 ) ;
error:
F_84 ( V_92 ) ;
return V_21 ;
}
static int T_7 F_85 ( struct V_62 * V_138 )
{
struct V_49 * V_49 = F_86 ( V_138 ) ;
F_25 ( & V_49 -> V_65 ) ;
F_87 ( & V_49 -> V_55 ) ;
F_88 ( V_49 -> V_92 ) ;
F_15 ( V_49 ) ;
F_26 ( & V_49 -> V_65 ) ;
F_89 ( V_49 -> V_92 ) ;
return 0 ;
}
static void F_90 ( struct V_132 * V_61 )
{
struct V_49 * V_49 = F_86 ( & V_61 -> V_62 ) ;
F_91 ( V_49 -> V_61 ) ;
if ( F_92 ( & V_49 -> V_56 ) < 0 ) {
F_25 ( & V_49 -> V_65 ) ;
F_87 ( & V_49 -> V_55 ) ;
F_15 ( V_49 ) ;
F_26 ( & V_49 -> V_65 ) ;
return;
}
F_93 ( & V_49 -> V_55 ) ;
}
static int T_8 F_94 ( void )
{
return F_95 ( & V_162 . V_157 ) ;
}
static void T_9 F_96 ( void )
{
F_97 ( & V_162 . V_157 ) ;
}
