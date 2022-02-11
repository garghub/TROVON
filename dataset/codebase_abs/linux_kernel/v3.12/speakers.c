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
5000 , V_46 ) ;
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
F_49 ( V_73 , V_95 , & V_78 ) ;
return 0 ;
}
static int F_50 ( struct V_49 * V_49 , bool * V_96 ,
enum V_97 V_98 )
{
T_1 * V_58 ;
T_1 V_99 ;
int V_21 ;
V_58 = F_19 ( 11 , V_59 ) ;
if ( ! V_58 )
return - V_60 ;
if ( V_98 == V_100 ) {
V_58 [ 0 ] = 0x01 ;
V_99 = 0x0c ;
} else {
V_58 [ 0 ] = 0x00 ;
V_99 = 0x09 ;
}
V_58 [ 1 ] = 0x08 ;
V_58 [ 2 ] = 0xb8 ;
V_58 [ 3 ] = 0x81 ;
V_58 [ 4 ] = V_49 -> V_51 -> V_101 ;
V_58 [ 5 ] = 0x10 ;
V_58 [ 6 ] = 0x02 ;
V_58 [ 7 ] = 0x00 ;
V_58 [ 8 ] = 0x01 ;
V_58 [ 9 ] = 0x01 ;
if ( V_98 == V_100 )
V_58 [ 10 ] = 0xff ;
else
V_58 [ 10 ] = * V_96 ? 0x70 : 0x60 ;
V_21 = F_20 ( V_49 -> V_61 , V_58 , 11 , V_58 , 11 , 0x3fe ) ;
if ( V_21 < 0 )
goto error;
if ( V_21 < 11 ) {
F_22 ( & V_49 -> V_61 -> V_62 , L_3 ) ;
V_21 = - V_63 ;
goto error;
}
if ( V_58 [ 0 ] != V_99 ) {
F_22 ( & V_49 -> V_61 -> V_62 , L_4 ) ;
V_21 = - V_63 ;
goto error;
}
if ( V_98 == V_100 )
* V_96 = V_58 [ 10 ] == 0x70 ;
V_21 = 0 ;
error:
F_23 ( V_58 ) ;
return V_21 ;
}
static int F_51 ( struct V_49 * V_49 , T_3 * V_96 ,
unsigned int V_69 ,
enum V_102 V_103 ,
enum V_97 V_98 )
{
T_1 * V_58 ;
T_1 V_99 ;
int V_21 ;
V_58 = F_19 ( 12 , V_59 ) ;
if ( ! V_58 )
return - V_60 ;
if ( V_98 == V_100 ) {
V_58 [ 0 ] = 0x01 ;
V_99 = 0x0c ;
} else {
V_58 [ 0 ] = 0x00 ;
V_99 = 0x09 ;
}
V_58 [ 1 ] = 0x08 ;
V_58 [ 2 ] = 0xb8 ;
V_58 [ 3 ] = 0x81 ;
V_58 [ 4 ] = V_49 -> V_51 -> V_104 ;
V_58 [ 5 ] = V_103 ;
V_58 [ 6 ] = 0x02 ;
V_58 [ 7 ] = V_69 ;
V_58 [ 8 ] = 0x02 ;
V_58 [ 9 ] = 0x02 ;
if ( V_98 == V_100 ) {
V_58 [ 10 ] = 0xff ;
V_58 [ 11 ] = 0xff ;
} else {
V_58 [ 10 ] = * V_96 >> 8 ;
V_58 [ 11 ] = * V_96 ;
}
V_21 = F_20 ( V_49 -> V_61 , V_58 , 12 , V_58 , 12 , 0x3fe ) ;
if ( V_21 < 0 )
goto error;
if ( V_21 < 12 ) {
F_22 ( & V_49 -> V_61 -> V_62 , L_3 ) ;
V_21 = - V_63 ;
goto error;
}
if ( V_58 [ 0 ] != V_99 ) {
F_22 ( & V_49 -> V_61 -> V_62 , L_5 ) ;
V_21 = - V_63 ;
goto error;
}
if ( V_98 == V_100 )
* V_96 = ( V_58 [ 10 ] << 8 ) | V_58 [ 11 ] ;
V_21 = 0 ;
error:
F_23 ( V_58 ) ;
return V_21 ;
}
static int F_52 ( struct V_105 * V_106 ,
struct V_107 * V_96 )
{
struct V_49 * V_49 = V_106 -> V_50 ;
V_96 -> V_96 . integer . V_96 [ 0 ] = ! V_49 -> V_108 ;
return 0 ;
}
static int F_53 ( struct V_105 * V_106 ,
struct V_107 * V_96 )
{
struct V_49 * V_49 = V_106 -> V_50 ;
bool V_108 ;
int V_21 ;
V_108 = ! V_96 -> V_96 . integer . V_96 [ 0 ] ;
if ( V_108 == V_49 -> V_108 )
return 0 ;
V_21 = F_50 ( V_49 , & V_108 , V_109 ) ;
if ( V_21 < 0 )
return V_21 ;
V_49 -> V_108 = V_108 ;
return 1 ;
}
static int F_54 ( struct V_105 * V_106 ,
struct V_110 * V_34 )
{
struct V_49 * V_49 = V_106 -> V_50 ;
V_34 -> type = V_111 ;
V_34 -> V_19 = V_49 -> V_51 -> V_112 ;
V_34 -> V_96 . integer . V_12 = V_49 -> V_113 ;
V_34 -> V_96 . integer . V_13 = V_49 -> V_114 ;
return 0 ;
}
static int F_55 ( struct V_105 * V_106 ,
struct V_107 * V_96 )
{
struct V_49 * V_49 = V_106 -> V_50 ;
unsigned int V_115 ;
for ( V_115 = 0 ; V_115 < V_49 -> V_51 -> V_112 ; ++ V_115 )
V_96 -> V_96 . integer . V_96 [ V_116 [ V_115 ] ] = V_49 -> V_117 [ V_115 ] ;
return 0 ;
}
static int F_56 ( struct V_105 * V_106 ,
struct V_107 * V_96 )
{
struct V_49 * V_49 = V_106 -> V_50 ;
unsigned int V_115 , V_118 ;
bool V_119 = true ;
T_3 V_117 ;
int V_21 ;
for ( V_115 = 0 ; V_115 < V_49 -> V_51 -> V_112 ; ++ V_115 ) {
if ( V_96 -> V_96 . integer . V_96 [ V_115 ] < V_49 -> V_113 ||
V_96 -> V_96 . integer . V_96 [ V_115 ] > V_49 -> V_114 )
return - V_76 ;
if ( V_96 -> V_96 . integer . V_96 [ V_115 ] !=
V_96 -> V_96 . integer . V_96 [ 0 ] )
V_119 = false ;
}
V_118 = 0 ;
for ( V_115 = 0 ; V_115 < V_49 -> V_51 -> V_112 ; ++ V_115 )
if ( V_96 -> V_96 . integer . V_96 [ V_116 [ V_115 ] ] !=
V_49 -> V_117 [ V_115 ] )
V_118 |= 1 << ( V_115 + 1 ) ;
if ( V_119 && V_118 != 0 )
V_118 = 1 << 0 ;
for ( V_115 = 0 ; V_115 <= V_49 -> V_51 -> V_112 ; ++ V_115 ) {
V_117 = V_96 -> V_96 . integer . V_96 [ V_116 [ V_115 ? V_115 - 1 : 0 ] ] ;
if ( V_118 & ( 1 << V_115 ) ) {
V_21 = F_51 ( V_49 , & V_117 , V_115 ,
V_120 , V_109 ) ;
if ( V_21 < 0 )
return V_21 ;
}
if ( V_115 > 0 )
V_49 -> V_117 [ V_115 - 1 ] = V_117 ;
}
return V_118 != 0 ;
}
static int F_57 ( struct V_49 * V_49 )
{
static const struct V_121 V_122 [] = {
{
. V_123 = V_124 ,
. V_93 = L_6 ,
. V_34 = V_125 ,
. V_126 = F_52 ,
. V_127 = F_53 ,
} ,
{
. V_123 = V_124 ,
. V_93 = L_7 ,
. V_34 = F_54 ,
. V_126 = F_55 ,
. V_127 = F_56 ,
} ,
} ;
unsigned int V_115 , V_128 ;
int V_21 ;
V_21 = F_51 ( V_49 , & V_49 -> V_113 ,
0 , V_129 , V_100 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_51 ( V_49 , & V_49 -> V_114 ,
0 , V_130 , V_100 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_50 ( V_49 , & V_49 -> V_108 , V_100 ) ;
if ( V_21 < 0 )
return V_21 ;
V_128 = V_49 -> V_51 -> V_112 == 1 ? 0 : 1 ;
for ( V_115 = 0 ; V_115 < V_49 -> V_51 -> V_112 ; ++ V_115 ) {
V_21 = F_51 ( V_49 , & V_49 -> V_117 [ V_115 ] ,
V_128 + V_115 , V_120 , V_100 ) ;
if ( V_21 < 0 )
return V_21 ;
}
for ( V_115 = 0 ; V_115 < F_58 ( V_122 ) ; ++ V_115 ) {
V_21 = F_59 ( V_49 -> V_92 ,
F_60 ( & V_122 [ V_115 ] , V_49 ) ) ;
if ( V_21 < 0 )
return V_21 ;
}
return 0 ;
}
static T_4 F_61 ( struct V_131 * V_61 )
{
T_5 V_132 ;
int V_21 ;
V_21 = F_62 ( V_61 , V_133 ,
V_134 , & V_132 , 4 ) ;
return V_21 >= 0 ? F_63 ( V_132 ) : 0 ;
}
static void F_64 ( struct V_135 * V_92 )
{
struct V_49 * V_49 = V_92 -> V_50 ;
F_65 ( & V_49 -> V_55 ) ;
F_66 ( & V_49 -> V_56 ) ;
F_67 ( V_49 -> V_61 ) ;
F_68 ( & V_49 -> V_65 ) ;
}
static int F_69 ( struct V_131 * V_61 ,
const struct V_136 * V_137 )
{
struct V_138 * V_139 = F_70 ( V_61 ) ;
struct V_135 * V_92 ;
struct V_49 * V_49 ;
T_4 V_140 ;
int V_21 ;
V_21 = F_71 ( - 1 , NULL , V_141 , sizeof( * V_49 ) , & V_92 ) ;
if ( V_21 < 0 )
return V_21 ;
F_72 ( V_92 , & V_61 -> V_62 ) ;
V_49 = V_92 -> V_50 ;
V_49 -> V_92 = V_92 ;
F_73 ( & V_49 -> V_65 ) ;
V_49 -> V_61 = F_74 ( V_61 ) ;
V_49 -> V_51 = ( const struct V_51 * ) V_137 -> V_142 ;
V_21 = F_75 ( & V_49 -> V_56 , V_61 , 0 ) ;
if ( V_21 < 0 )
goto V_143;
V_21 = F_76 ( & V_49 -> V_55 , V_61 , V_144 ) ;
if ( V_21 < 0 )
goto V_71;
V_92 -> V_145 = F_64 ;
strcpy ( V_92 -> V_146 , V_49 -> V_51 -> V_147 ) ;
strcpy ( V_92 -> V_148 , V_49 -> V_51 -> V_94 ) ;
V_140 = F_61 ( V_61 ) ;
snprintf ( V_92 -> V_149 , sizeof( V_92 -> V_149 ) ,
L_8 ,
V_49 -> V_51 -> V_150 ,
V_140 >> 20 , V_140 & 0xffff ,
V_139 -> V_151 [ 3 ] , V_139 -> V_151 [ 4 ] ,
F_77 ( & V_61 -> V_62 ) , 100 << V_139 -> V_152 ) ;
strcpy ( V_92 -> V_153 , L_2 ) ;
V_21 = F_47 ( V_49 ) ;
if ( V_21 < 0 )
goto error;
V_21 = F_57 ( V_49 ) ;
if ( V_21 < 0 )
goto error;
V_21 = F_78 ( V_92 ) ;
if ( V_21 < 0 )
goto error;
F_79 ( & V_61 -> V_62 , V_49 ) ;
return 0 ;
V_71:
F_66 ( & V_49 -> V_56 ) ;
V_143:
F_67 ( V_49 -> V_61 ) ;
F_68 ( & V_49 -> V_65 ) ;
error:
F_80 ( V_92 ) ;
return V_21 ;
}
static void F_81 ( struct V_131 * V_61 )
{
struct V_49 * V_49 = F_82 ( & V_61 -> V_62 ) ;
F_83 ( V_49 -> V_61 ) ;
if ( F_84 ( & V_49 -> V_56 ) < 0 ) {
F_85 ( & V_49 -> V_55 ) ;
F_25 ( & V_49 -> V_65 ) ;
F_15 ( V_49 ) ;
F_26 ( & V_49 -> V_65 ) ;
return;
}
F_86 ( & V_49 -> V_55 ) ;
}
static void F_87 ( struct V_131 * V_61 )
{
struct V_49 * V_49 = F_82 ( & V_61 -> V_62 ) ;
F_85 ( & V_49 -> V_55 ) ;
F_88 ( V_49 -> V_92 ) ;
F_25 ( & V_49 -> V_65 ) ;
F_15 ( V_49 ) ;
F_26 ( & V_49 -> V_65 ) ;
F_89 ( V_49 -> V_92 ) ;
}
static int T_6 F_90 ( void )
{
return F_91 ( & V_154 . V_146 ) ;
}
static void T_7 F_92 ( void )
{
F_93 ( & V_154 . V_146 ) ;
}
