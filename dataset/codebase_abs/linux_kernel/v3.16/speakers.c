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
V_21 = F_12 ( & V_49 -> V_53 , V_15 ) ;
if ( V_21 < 0 )
return V_21 ;
return 0 ;
}
static int F_13 ( struct V_30 * V_31 )
{
return 0 ;
}
static void F_14 ( struct V_49 * V_49 )
{
if ( F_15 ( & V_49 -> V_53 ) ) {
F_16 ( & V_49 -> V_53 ) ;
F_17 ( & V_49 -> V_54 ) ;
}
}
static int F_18 ( struct V_30 * V_31 ,
struct V_1 * V_55 )
{
struct V_49 * V_49 = V_31 -> V_50 ;
int V_21 ;
F_19 ( & V_49 -> V_56 ) ;
F_14 ( V_49 ) ;
F_20 ( & V_49 -> V_56 ) ;
V_21 = F_21 ( V_31 ,
F_22 ( V_55 ) ) ;
if ( V_21 < 0 )
goto error;
F_23 ( & V_49 -> V_53 ,
F_24 ( V_55 ) ,
F_25 ( V_55 ) ,
0 ) ;
F_26 ( & V_49 -> V_53 ,
F_27 ( V_55 ) ) ;
V_21 = F_28 ( V_49 -> V_57 , F_24 ( V_55 ) ,
V_58 , 0 ) ;
if ( V_21 < 0 ) {
F_29 ( & V_49 -> V_57 -> V_59 , L_1 ) ;
goto V_60;
}
return 0 ;
V_60:
F_30 ( V_31 ) ;
error:
return V_21 ;
}
static int F_31 ( struct V_30 * V_31 )
{
struct V_49 * V_49 = V_31 -> V_50 ;
F_19 ( & V_49 -> V_56 ) ;
F_14 ( V_49 ) ;
F_20 ( & V_49 -> V_56 ) ;
return F_30 ( V_31 ) ;
}
static int F_32 ( struct V_30 * V_31 )
{
struct V_49 * V_49 = V_31 -> V_50 ;
int V_21 ;
F_19 ( & V_49 -> V_56 ) ;
if ( F_33 ( & V_49 -> V_53 ) )
F_14 ( V_49 ) ;
if ( ! F_15 ( & V_49 -> V_53 ) ) {
V_21 = F_34 ( & V_49 -> V_54 ,
F_35 ( & V_49 -> V_53 ) ) ;
if ( V_21 < 0 )
goto V_61;
V_21 = F_36 ( & V_49 -> V_53 ,
V_49 -> V_54 . V_62 . V_63 ,
V_49 -> V_54 . V_64 ) ;
if ( V_21 < 0 )
goto V_65;
}
F_20 ( & V_49 -> V_56 ) ;
F_37 ( & V_49 -> V_53 ) ;
return 0 ;
V_65:
F_17 ( & V_49 -> V_54 ) ;
V_61:
F_20 ( & V_49 -> V_56 ) ;
return V_21 ;
}
static int F_38 ( struct V_30 * V_31 , int V_66 )
{
struct V_49 * V_49 = V_31 -> V_50 ;
struct V_30 * V_67 ;
switch ( V_66 ) {
case V_68 :
V_67 = V_31 ;
break;
case V_69 :
V_67 = NULL ;
break;
default:
return - V_70 ;
}
F_39 ( & V_49 -> V_53 , V_67 ) ;
return 0 ;
}
static T_1 F_40 ( struct V_30 * V_31 )
{
struct V_49 * V_49 = V_31 -> V_50 ;
return F_41 ( & V_49 -> V_53 ) ;
}
static int F_42 ( struct V_49 * V_49 )
{
static struct V_71 V_72 = {
. V_73 = F_10 ,
. V_74 = F_13 ,
. V_75 = V_76 ,
. V_55 = F_18 ,
. V_77 = F_31 ,
. V_78 = F_32 ,
. V_79 = F_38 ,
. V_80 = F_40 ,
. V_81 = V_82 ,
. V_83 = V_84 ,
} ;
struct V_85 * V_67 ;
int V_21 ;
V_21 = F_43 ( V_49 -> V_86 , L_2 , 0 , 1 , 0 , & V_67 ) ;
if ( V_21 < 0 )
return V_21 ;
V_67 -> V_50 = V_49 ;
strcpy ( V_67 -> V_87 , V_49 -> V_51 -> V_88 ) ;
F_44 ( V_67 , V_89 , & V_72 ) ;
return 0 ;
}
static int F_45 ( struct V_49 * V_49 , bool * V_90 ,
enum V_91 V_92 )
{
T_2 * V_93 ;
T_2 V_94 ;
int V_21 ;
V_93 = F_46 ( 11 , V_95 ) ;
if ( ! V_93 )
return - V_96 ;
if ( V_92 == V_97 ) {
V_93 [ 0 ] = 0x01 ;
V_94 = 0x0c ;
} else {
V_93 [ 0 ] = 0x00 ;
V_94 = 0x09 ;
}
V_93 [ 1 ] = 0x08 ;
V_93 [ 2 ] = 0xb8 ;
V_93 [ 3 ] = 0x81 ;
V_93 [ 4 ] = V_49 -> V_51 -> V_98 ;
V_93 [ 5 ] = 0x10 ;
V_93 [ 6 ] = 0x02 ;
V_93 [ 7 ] = 0x00 ;
V_93 [ 8 ] = 0x01 ;
V_93 [ 9 ] = 0x01 ;
if ( V_92 == V_97 )
V_93 [ 10 ] = 0xff ;
else
V_93 [ 10 ] = * V_90 ? 0x70 : 0x60 ;
V_21 = F_47 ( V_49 -> V_57 , V_93 , 11 , V_93 , 11 , 0x3fe ) ;
if ( V_21 < 0 )
goto error;
if ( V_21 < 11 ) {
F_29 ( & V_49 -> V_57 -> V_59 , L_3 ) ;
V_21 = - V_99 ;
goto error;
}
if ( V_93 [ 0 ] != V_94 ) {
F_29 ( & V_49 -> V_57 -> V_59 , L_4 ) ;
V_21 = - V_99 ;
goto error;
}
if ( V_92 == V_97 )
* V_90 = V_93 [ 10 ] == 0x70 ;
V_21 = 0 ;
error:
F_48 ( V_93 ) ;
return V_21 ;
}
static int F_49 ( struct V_49 * V_49 , T_3 * V_90 ,
unsigned int V_63 ,
enum V_100 V_101 ,
enum V_91 V_92 )
{
T_2 * V_93 ;
T_2 V_94 ;
int V_21 ;
V_93 = F_46 ( 12 , V_95 ) ;
if ( ! V_93 )
return - V_96 ;
if ( V_92 == V_97 ) {
V_93 [ 0 ] = 0x01 ;
V_94 = 0x0c ;
} else {
V_93 [ 0 ] = 0x00 ;
V_94 = 0x09 ;
}
V_93 [ 1 ] = 0x08 ;
V_93 [ 2 ] = 0xb8 ;
V_93 [ 3 ] = 0x81 ;
V_93 [ 4 ] = V_49 -> V_51 -> V_102 ;
V_93 [ 5 ] = V_101 ;
V_93 [ 6 ] = 0x02 ;
V_93 [ 7 ] = V_63 ;
V_93 [ 8 ] = 0x02 ;
V_93 [ 9 ] = 0x02 ;
if ( V_92 == V_97 ) {
V_93 [ 10 ] = 0xff ;
V_93 [ 11 ] = 0xff ;
} else {
V_93 [ 10 ] = * V_90 >> 8 ;
V_93 [ 11 ] = * V_90 ;
}
V_21 = F_47 ( V_49 -> V_57 , V_93 , 12 , V_93 , 12 , 0x3fe ) ;
if ( V_21 < 0 )
goto error;
if ( V_21 < 12 ) {
F_29 ( & V_49 -> V_57 -> V_59 , L_3 ) ;
V_21 = - V_99 ;
goto error;
}
if ( V_93 [ 0 ] != V_94 ) {
F_29 ( & V_49 -> V_57 -> V_59 , L_5 ) ;
V_21 = - V_99 ;
goto error;
}
if ( V_92 == V_97 )
* V_90 = ( V_93 [ 10 ] << 8 ) | V_93 [ 11 ] ;
V_21 = 0 ;
error:
F_48 ( V_93 ) ;
return V_21 ;
}
static int F_50 ( struct V_103 * V_104 ,
struct V_105 * V_90 )
{
struct V_49 * V_49 = V_104 -> V_50 ;
V_90 -> V_90 . integer . V_90 [ 0 ] = ! V_49 -> V_106 ;
return 0 ;
}
static int F_51 ( struct V_103 * V_104 ,
struct V_105 * V_90 )
{
struct V_49 * V_49 = V_104 -> V_50 ;
bool V_106 ;
int V_21 ;
V_106 = ! V_90 -> V_90 . integer . V_90 [ 0 ] ;
if ( V_106 == V_49 -> V_106 )
return 0 ;
V_21 = F_45 ( V_49 , & V_106 , V_107 ) ;
if ( V_21 < 0 )
return V_21 ;
V_49 -> V_106 = V_106 ;
return 1 ;
}
static int F_52 ( struct V_103 * V_104 ,
struct V_108 * V_34 )
{
struct V_49 * V_49 = V_104 -> V_50 ;
V_34 -> type = V_109 ;
V_34 -> V_19 = V_49 -> V_51 -> V_110 ;
V_34 -> V_90 . integer . V_12 = V_49 -> V_111 ;
V_34 -> V_90 . integer . V_13 = V_49 -> V_112 ;
return 0 ;
}
static int F_53 ( struct V_103 * V_104 ,
struct V_105 * V_90 )
{
struct V_49 * V_49 = V_104 -> V_50 ;
unsigned int V_113 ;
for ( V_113 = 0 ; V_113 < V_49 -> V_51 -> V_110 ; ++ V_113 )
V_90 -> V_90 . integer . V_90 [ V_114 [ V_113 ] ] = V_49 -> V_115 [ V_113 ] ;
return 0 ;
}
static int F_54 ( struct V_103 * V_104 ,
struct V_105 * V_90 )
{
struct V_49 * V_49 = V_104 -> V_50 ;
unsigned int V_113 , V_116 ;
bool V_117 = true ;
T_3 V_115 ;
int V_21 ;
for ( V_113 = 0 ; V_113 < V_49 -> V_51 -> V_110 ; ++ V_113 ) {
if ( V_90 -> V_90 . integer . V_90 [ V_113 ] < V_49 -> V_111 ||
V_90 -> V_90 . integer . V_90 [ V_113 ] > V_49 -> V_112 )
return - V_70 ;
if ( V_90 -> V_90 . integer . V_90 [ V_113 ] !=
V_90 -> V_90 . integer . V_90 [ 0 ] )
V_117 = false ;
}
V_116 = 0 ;
for ( V_113 = 0 ; V_113 < V_49 -> V_51 -> V_110 ; ++ V_113 )
if ( V_90 -> V_90 . integer . V_90 [ V_114 [ V_113 ] ] !=
V_49 -> V_115 [ V_113 ] )
V_116 |= 1 << ( V_113 + 1 ) ;
if ( V_117 && V_116 != 0 )
V_116 = 1 << 0 ;
for ( V_113 = 0 ; V_113 <= V_49 -> V_51 -> V_110 ; ++ V_113 ) {
V_115 = V_90 -> V_90 . integer . V_90 [ V_114 [ V_113 ? V_113 - 1 : 0 ] ] ;
if ( V_116 & ( 1 << V_113 ) ) {
V_21 = F_49 ( V_49 , & V_115 , V_113 ,
V_118 , V_107 ) ;
if ( V_21 < 0 )
return V_21 ;
}
if ( V_113 > 0 )
V_49 -> V_115 [ V_113 - 1 ] = V_115 ;
}
return V_116 != 0 ;
}
static int F_55 ( struct V_49 * V_49 )
{
static const struct V_119 V_120 [] = {
{
. V_121 = V_122 ,
. V_87 = L_6 ,
. V_34 = V_123 ,
. V_124 = F_50 ,
. V_125 = F_51 ,
} ,
{
. V_121 = V_122 ,
. V_87 = L_7 ,
. V_34 = F_52 ,
. V_124 = F_53 ,
. V_125 = F_54 ,
} ,
} ;
unsigned int V_113 , V_126 ;
int V_21 ;
V_21 = F_49 ( V_49 , & V_49 -> V_111 ,
0 , V_127 , V_97 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_49 ( V_49 , & V_49 -> V_112 ,
0 , V_128 , V_97 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_45 ( V_49 , & V_49 -> V_106 , V_97 ) ;
if ( V_21 < 0 )
return V_21 ;
V_126 = V_49 -> V_51 -> V_110 == 1 ? 0 : 1 ;
for ( V_113 = 0 ; V_113 < V_49 -> V_51 -> V_110 ; ++ V_113 ) {
V_21 = F_49 ( V_49 , & V_49 -> V_115 [ V_113 ] ,
V_126 + V_113 , V_118 , V_97 ) ;
if ( V_21 < 0 )
return V_21 ;
}
for ( V_113 = 0 ; V_113 < F_56 ( V_120 ) ; ++ V_113 ) {
V_21 = F_57 ( V_49 -> V_86 ,
F_58 ( & V_120 [ V_113 ] , V_49 ) ) ;
if ( V_21 < 0 )
return V_21 ;
}
return 0 ;
}
static T_4 F_59 ( struct V_129 * V_57 )
{
T_5 V_130 ;
int V_21 ;
V_21 = F_60 ( V_57 , V_131 ,
V_132 , & V_130 , 4 , 0 ) ;
return V_21 >= 0 ? F_61 ( V_130 ) : 0 ;
}
static void F_62 ( struct V_133 * V_86 )
{
struct V_49 * V_49 = V_86 -> V_50 ;
F_63 ( & V_49 -> V_53 ) ;
F_64 ( & V_49 -> V_54 ) ;
F_65 ( V_49 -> V_57 ) ;
F_66 ( & V_49 -> V_56 ) ;
}
static int F_67 ( struct V_129 * V_57 ,
const struct V_134 * V_135 )
{
struct V_136 * V_137 = F_68 ( V_57 ) ;
struct V_133 * V_86 ;
struct V_49 * V_49 ;
T_4 V_138 ;
int V_21 ;
V_21 = F_69 ( & V_57 -> V_59 , - 1 , NULL , V_139 ,
sizeof( * V_49 ) , & V_86 ) ;
if ( V_21 < 0 )
return V_21 ;
V_49 = V_86 -> V_50 ;
V_49 -> V_86 = V_86 ;
F_70 ( & V_49 -> V_56 ) ;
V_49 -> V_57 = F_71 ( V_57 ) ;
V_49 -> V_51 = ( const struct V_51 * ) V_135 -> V_140 ;
V_21 = F_72 ( & V_49 -> V_54 , V_57 , V_141 , 0 ) ;
if ( V_21 < 0 )
goto V_142;
V_21 = F_73 ( & V_49 -> V_53 , V_57 , V_143 ,
V_144 ) ;
if ( V_21 < 0 )
goto V_65;
V_86 -> V_145 = F_62 ;
strcpy ( V_86 -> V_146 , V_49 -> V_51 -> V_147 ) ;
strcpy ( V_86 -> V_148 , V_49 -> V_51 -> V_88 ) ;
V_138 = F_59 ( V_57 ) ;
snprintf ( V_86 -> V_149 , sizeof( V_86 -> V_149 ) ,
L_8 ,
V_49 -> V_51 -> V_150 ,
V_138 >> 20 , V_138 & 0xffff ,
V_137 -> V_151 [ 3 ] , V_137 -> V_151 [ 4 ] ,
F_74 ( & V_57 -> V_59 ) , 100 << V_137 -> V_152 ) ;
strcpy ( V_86 -> V_153 , L_2 ) ;
V_21 = F_42 ( V_49 ) ;
if ( V_21 < 0 )
goto error;
V_21 = F_55 ( V_49 ) ;
if ( V_21 < 0 )
goto error;
V_21 = F_75 ( V_86 ) ;
if ( V_21 < 0 )
goto error;
F_76 ( & V_57 -> V_59 , V_49 ) ;
return 0 ;
V_65:
F_64 ( & V_49 -> V_54 ) ;
V_142:
F_65 ( V_49 -> V_57 ) ;
F_66 ( & V_49 -> V_56 ) ;
error:
F_77 ( V_86 ) ;
return V_21 ;
}
static void F_78 ( struct V_129 * V_57 )
{
struct V_49 * V_49 = F_79 ( & V_57 -> V_59 ) ;
F_80 ( V_49 -> V_57 ) ;
if ( F_81 ( & V_49 -> V_54 ) < 0 ) {
F_82 ( & V_49 -> V_53 ) ;
F_19 ( & V_49 -> V_56 ) ;
F_14 ( V_49 ) ;
F_20 ( & V_49 -> V_56 ) ;
return;
}
F_83 ( & V_49 -> V_53 ) ;
}
static void F_84 ( struct V_129 * V_57 )
{
struct V_49 * V_49 = F_79 ( & V_57 -> V_59 ) ;
F_82 ( & V_49 -> V_53 ) ;
F_85 ( V_49 -> V_86 ) ;
F_19 ( & V_49 -> V_56 ) ;
F_14 ( V_49 ) ;
F_20 ( & V_49 -> V_56 ) ;
F_86 ( V_49 -> V_86 ) ;
}
static int T_6 F_87 ( void )
{
return F_88 ( & V_154 . V_146 ) ;
}
static void T_7 F_89 ( void )
{
F_90 ( & V_154 . V_146 ) ;
}
