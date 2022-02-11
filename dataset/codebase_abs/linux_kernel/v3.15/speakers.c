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
if ( F_16 ( & V_49 -> V_54 ) ) {
F_17 ( & V_49 -> V_54 ) ;
F_18 ( & V_49 -> V_55 ) ;
}
}
static int F_19 ( struct V_49 * V_49 , unsigned int V_56 )
{
T_1 * V_57 ;
int V_21 ;
V_57 = F_20 ( 8 , V_58 ) ;
if ( ! V_57 )
return - V_59 ;
V_57 [ 0 ] = 0x00 ;
V_57 [ 1 ] = 0xff ;
V_57 [ 2 ] = 0x19 ;
V_57 [ 3 ] = 0x00 ;
V_57 [ 4 ] = 0x90 ;
V_57 [ 5 ] = 0x00 | V_56 ;
V_57 [ 6 ] = 0xff ;
V_57 [ 7 ] = 0xff ;
V_21 = F_21 ( V_49 -> V_60 , V_57 , 8 , V_57 , 8 ,
F_22 ( 1 ) | F_22 ( 2 ) | F_22 ( 3 ) | F_22 ( 4 ) | F_22 ( 5 ) ) ;
if ( V_21 < 0 )
goto error;
if ( V_21 < 6 || V_57 [ 0 ] != 0x09 ) {
F_23 ( & V_49 -> V_60 -> V_61 , L_1 ) ;
V_21 = - V_62 ;
goto error;
}
V_21 = 0 ;
error:
F_24 ( V_57 ) ;
return V_21 ;
}
static int F_25 ( struct V_30 * V_31 ,
struct V_1 * V_63 )
{
struct V_49 * V_49 = V_31 -> V_50 ;
int V_21 ;
F_26 ( & V_49 -> V_64 ) ;
F_15 ( V_49 ) ;
F_27 ( & V_49 -> V_64 ) ;
V_21 = F_28 ( V_31 ,
F_29 ( V_63 ) ) ;
if ( V_21 < 0 )
goto error;
F_30 ( & V_49 -> V_54 ,
F_31 ( V_63 ) ,
F_32 ( V_63 ) ,
0 ) ;
F_33 ( & V_49 -> V_54 ,
F_34 ( V_63 ) ) ;
V_21 = F_19 ( V_49 , V_49 -> V_54 . V_56 ) ;
if ( V_21 < 0 )
goto V_65;
return 0 ;
V_65:
F_35 ( V_31 ) ;
error:
return V_21 ;
}
static int F_36 ( struct V_30 * V_31 )
{
struct V_49 * V_49 = V_31 -> V_50 ;
F_26 ( & V_49 -> V_64 ) ;
F_15 ( V_49 ) ;
F_27 ( & V_49 -> V_64 ) ;
return F_35 ( V_31 ) ;
}
static int F_37 ( struct V_30 * V_31 )
{
struct V_49 * V_49 = V_31 -> V_50 ;
int V_21 ;
F_26 ( & V_49 -> V_64 ) ;
if ( F_38 ( & V_49 -> V_54 ) )
F_15 ( V_49 ) ;
if ( ! F_16 ( & V_49 -> V_54 ) ) {
V_21 = F_39 ( & V_49 -> V_55 ,
F_40 ( & V_49 -> V_54 ) ) ;
if ( V_21 < 0 )
goto V_66;
V_21 = F_41 ( & V_49 -> V_54 ,
V_49 -> V_55 . V_67 . V_68 ,
V_49 -> V_55 . V_69 ) ;
if ( V_21 < 0 )
goto V_70;
}
F_27 ( & V_49 -> V_64 ) ;
F_42 ( & V_49 -> V_54 ) ;
return 0 ;
V_70:
F_18 ( & V_49 -> V_55 ) ;
V_66:
F_27 ( & V_49 -> V_64 ) ;
return V_21 ;
}
static int F_43 ( struct V_30 * V_31 , int V_71 )
{
struct V_49 * V_49 = V_31 -> V_50 ;
struct V_30 * V_72 ;
switch ( V_71 ) {
case V_73 :
V_72 = V_31 ;
break;
case V_74 :
V_72 = NULL ;
break;
default:
return - V_75 ;
}
F_44 ( & V_49 -> V_54 , V_72 ) ;
return 0 ;
}
static T_2 F_45 ( struct V_30 * V_31 )
{
struct V_49 * V_49 = V_31 -> V_50 ;
return F_46 ( & V_49 -> V_54 ) ;
}
static int F_47 ( struct V_49 * V_49 )
{
static struct V_76 V_77 = {
. V_78 = F_10 ,
. V_79 = F_14 ,
. V_80 = V_81 ,
. V_63 = F_25 ,
. V_82 = F_36 ,
. V_83 = F_37 ,
. V_84 = F_43 ,
. V_85 = F_45 ,
. V_86 = V_87 ,
. V_88 = V_89 ,
} ;
struct V_90 * V_72 ;
int V_21 ;
V_21 = F_48 ( V_49 -> V_91 , L_2 , 0 , 1 , 0 , & V_72 ) ;
if ( V_21 < 0 )
return V_21 ;
V_72 -> V_50 = V_49 ;
strcpy ( V_72 -> V_92 , V_49 -> V_51 -> V_93 ) ;
F_49 ( V_72 , V_94 , & V_77 ) ;
return 0 ;
}
static int F_50 ( struct V_49 * V_49 , bool * V_95 ,
enum V_96 V_97 )
{
T_1 * V_57 ;
T_1 V_98 ;
int V_21 ;
V_57 = F_20 ( 11 , V_58 ) ;
if ( ! V_57 )
return - V_59 ;
if ( V_97 == V_99 ) {
V_57 [ 0 ] = 0x01 ;
V_98 = 0x0c ;
} else {
V_57 [ 0 ] = 0x00 ;
V_98 = 0x09 ;
}
V_57 [ 1 ] = 0x08 ;
V_57 [ 2 ] = 0xb8 ;
V_57 [ 3 ] = 0x81 ;
V_57 [ 4 ] = V_49 -> V_51 -> V_100 ;
V_57 [ 5 ] = 0x10 ;
V_57 [ 6 ] = 0x02 ;
V_57 [ 7 ] = 0x00 ;
V_57 [ 8 ] = 0x01 ;
V_57 [ 9 ] = 0x01 ;
if ( V_97 == V_99 )
V_57 [ 10 ] = 0xff ;
else
V_57 [ 10 ] = * V_95 ? 0x70 : 0x60 ;
V_21 = F_21 ( V_49 -> V_60 , V_57 , 11 , V_57 , 11 , 0x3fe ) ;
if ( V_21 < 0 )
goto error;
if ( V_21 < 11 ) {
F_23 ( & V_49 -> V_60 -> V_61 , L_3 ) ;
V_21 = - V_62 ;
goto error;
}
if ( V_57 [ 0 ] != V_98 ) {
F_23 ( & V_49 -> V_60 -> V_61 , L_4 ) ;
V_21 = - V_62 ;
goto error;
}
if ( V_97 == V_99 )
* V_95 = V_57 [ 10 ] == 0x70 ;
V_21 = 0 ;
error:
F_24 ( V_57 ) ;
return V_21 ;
}
static int F_51 ( struct V_49 * V_49 , T_3 * V_95 ,
unsigned int V_68 ,
enum V_101 V_102 ,
enum V_96 V_97 )
{
T_1 * V_57 ;
T_1 V_98 ;
int V_21 ;
V_57 = F_20 ( 12 , V_58 ) ;
if ( ! V_57 )
return - V_59 ;
if ( V_97 == V_99 ) {
V_57 [ 0 ] = 0x01 ;
V_98 = 0x0c ;
} else {
V_57 [ 0 ] = 0x00 ;
V_98 = 0x09 ;
}
V_57 [ 1 ] = 0x08 ;
V_57 [ 2 ] = 0xb8 ;
V_57 [ 3 ] = 0x81 ;
V_57 [ 4 ] = V_49 -> V_51 -> V_103 ;
V_57 [ 5 ] = V_102 ;
V_57 [ 6 ] = 0x02 ;
V_57 [ 7 ] = V_68 ;
V_57 [ 8 ] = 0x02 ;
V_57 [ 9 ] = 0x02 ;
if ( V_97 == V_99 ) {
V_57 [ 10 ] = 0xff ;
V_57 [ 11 ] = 0xff ;
} else {
V_57 [ 10 ] = * V_95 >> 8 ;
V_57 [ 11 ] = * V_95 ;
}
V_21 = F_21 ( V_49 -> V_60 , V_57 , 12 , V_57 , 12 , 0x3fe ) ;
if ( V_21 < 0 )
goto error;
if ( V_21 < 12 ) {
F_23 ( & V_49 -> V_60 -> V_61 , L_3 ) ;
V_21 = - V_62 ;
goto error;
}
if ( V_57 [ 0 ] != V_98 ) {
F_23 ( & V_49 -> V_60 -> V_61 , L_5 ) ;
V_21 = - V_62 ;
goto error;
}
if ( V_97 == V_99 )
* V_95 = ( V_57 [ 10 ] << 8 ) | V_57 [ 11 ] ;
V_21 = 0 ;
error:
F_24 ( V_57 ) ;
return V_21 ;
}
static int F_52 ( struct V_104 * V_105 ,
struct V_106 * V_95 )
{
struct V_49 * V_49 = V_105 -> V_50 ;
V_95 -> V_95 . integer . V_95 [ 0 ] = ! V_49 -> V_107 ;
return 0 ;
}
static int F_53 ( struct V_104 * V_105 ,
struct V_106 * V_95 )
{
struct V_49 * V_49 = V_105 -> V_50 ;
bool V_107 ;
int V_21 ;
V_107 = ! V_95 -> V_95 . integer . V_95 [ 0 ] ;
if ( V_107 == V_49 -> V_107 )
return 0 ;
V_21 = F_50 ( V_49 , & V_107 , V_108 ) ;
if ( V_21 < 0 )
return V_21 ;
V_49 -> V_107 = V_107 ;
return 1 ;
}
static int F_54 ( struct V_104 * V_105 ,
struct V_109 * V_34 )
{
struct V_49 * V_49 = V_105 -> V_50 ;
V_34 -> type = V_110 ;
V_34 -> V_19 = V_49 -> V_51 -> V_111 ;
V_34 -> V_95 . integer . V_12 = V_49 -> V_112 ;
V_34 -> V_95 . integer . V_13 = V_49 -> V_113 ;
return 0 ;
}
static int F_55 ( struct V_104 * V_105 ,
struct V_106 * V_95 )
{
struct V_49 * V_49 = V_105 -> V_50 ;
unsigned int V_114 ;
for ( V_114 = 0 ; V_114 < V_49 -> V_51 -> V_111 ; ++ V_114 )
V_95 -> V_95 . integer . V_95 [ V_115 [ V_114 ] ] = V_49 -> V_116 [ V_114 ] ;
return 0 ;
}
static int F_56 ( struct V_104 * V_105 ,
struct V_106 * V_95 )
{
struct V_49 * V_49 = V_105 -> V_50 ;
unsigned int V_114 , V_117 ;
bool V_118 = true ;
T_3 V_116 ;
int V_21 ;
for ( V_114 = 0 ; V_114 < V_49 -> V_51 -> V_111 ; ++ V_114 ) {
if ( V_95 -> V_95 . integer . V_95 [ V_114 ] < V_49 -> V_112 ||
V_95 -> V_95 . integer . V_95 [ V_114 ] > V_49 -> V_113 )
return - V_75 ;
if ( V_95 -> V_95 . integer . V_95 [ V_114 ] !=
V_95 -> V_95 . integer . V_95 [ 0 ] )
V_118 = false ;
}
V_117 = 0 ;
for ( V_114 = 0 ; V_114 < V_49 -> V_51 -> V_111 ; ++ V_114 )
if ( V_95 -> V_95 . integer . V_95 [ V_115 [ V_114 ] ] !=
V_49 -> V_116 [ V_114 ] )
V_117 |= 1 << ( V_114 + 1 ) ;
if ( V_118 && V_117 != 0 )
V_117 = 1 << 0 ;
for ( V_114 = 0 ; V_114 <= V_49 -> V_51 -> V_111 ; ++ V_114 ) {
V_116 = V_95 -> V_95 . integer . V_95 [ V_115 [ V_114 ? V_114 - 1 : 0 ] ] ;
if ( V_117 & ( 1 << V_114 ) ) {
V_21 = F_51 ( V_49 , & V_116 , V_114 ,
V_119 , V_108 ) ;
if ( V_21 < 0 )
return V_21 ;
}
if ( V_114 > 0 )
V_49 -> V_116 [ V_114 - 1 ] = V_116 ;
}
return V_117 != 0 ;
}
static int F_57 ( struct V_49 * V_49 )
{
static const struct V_120 V_121 [] = {
{
. V_122 = V_123 ,
. V_92 = L_6 ,
. V_34 = V_124 ,
. V_125 = F_52 ,
. V_126 = F_53 ,
} ,
{
. V_122 = V_123 ,
. V_92 = L_7 ,
. V_34 = F_54 ,
. V_125 = F_55 ,
. V_126 = F_56 ,
} ,
} ;
unsigned int V_114 , V_127 ;
int V_21 ;
V_21 = F_51 ( V_49 , & V_49 -> V_112 ,
0 , V_128 , V_99 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_51 ( V_49 , & V_49 -> V_113 ,
0 , V_129 , V_99 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_50 ( V_49 , & V_49 -> V_107 , V_99 ) ;
if ( V_21 < 0 )
return V_21 ;
V_127 = V_49 -> V_51 -> V_111 == 1 ? 0 : 1 ;
for ( V_114 = 0 ; V_114 < V_49 -> V_51 -> V_111 ; ++ V_114 ) {
V_21 = F_51 ( V_49 , & V_49 -> V_116 [ V_114 ] ,
V_127 + V_114 , V_119 , V_99 ) ;
if ( V_21 < 0 )
return V_21 ;
}
for ( V_114 = 0 ; V_114 < F_58 ( V_121 ) ; ++ V_114 ) {
V_21 = F_59 ( V_49 -> V_91 ,
F_60 ( & V_121 [ V_114 ] , V_49 ) ) ;
if ( V_21 < 0 )
return V_21 ;
}
return 0 ;
}
static T_4 F_61 ( struct V_130 * V_60 )
{
T_5 V_131 ;
int V_21 ;
V_21 = F_62 ( V_60 , V_132 ,
V_133 , & V_131 , 4 , 0 ) ;
return V_21 >= 0 ? F_63 ( V_131 ) : 0 ;
}
static void F_64 ( struct V_134 * V_91 )
{
struct V_49 * V_49 = V_91 -> V_50 ;
F_65 ( & V_49 -> V_54 ) ;
F_66 ( & V_49 -> V_55 ) ;
F_67 ( V_49 -> V_60 ) ;
F_68 ( & V_49 -> V_64 ) ;
}
static int F_69 ( struct V_130 * V_60 ,
const struct V_135 * V_136 )
{
struct V_137 * V_138 = F_70 ( V_60 ) ;
struct V_134 * V_91 ;
struct V_49 * V_49 ;
T_4 V_139 ;
int V_21 ;
V_21 = F_71 ( & V_60 -> V_61 , - 1 , NULL , V_140 ,
sizeof( * V_49 ) , & V_91 ) ;
if ( V_21 < 0 )
return V_21 ;
V_49 = V_91 -> V_50 ;
V_49 -> V_91 = V_91 ;
F_72 ( & V_49 -> V_64 ) ;
V_49 -> V_60 = F_73 ( V_60 ) ;
V_49 -> V_51 = ( const struct V_51 * ) V_136 -> V_141 ;
V_21 = F_74 ( & V_49 -> V_55 , V_60 , 0 ) ;
if ( V_21 < 0 )
goto V_142;
V_21 = F_75 ( & V_49 -> V_54 , V_60 , V_143 ) ;
if ( V_21 < 0 )
goto V_70;
V_91 -> V_144 = F_64 ;
strcpy ( V_91 -> V_145 , V_49 -> V_51 -> V_146 ) ;
strcpy ( V_91 -> V_147 , V_49 -> V_51 -> V_93 ) ;
V_139 = F_61 ( V_60 ) ;
snprintf ( V_91 -> V_148 , sizeof( V_91 -> V_148 ) ,
L_8 ,
V_49 -> V_51 -> V_149 ,
V_139 >> 20 , V_139 & 0xffff ,
V_138 -> V_150 [ 3 ] , V_138 -> V_150 [ 4 ] ,
F_76 ( & V_60 -> V_61 ) , 100 << V_138 -> V_151 ) ;
strcpy ( V_91 -> V_152 , L_2 ) ;
V_21 = F_47 ( V_49 ) ;
if ( V_21 < 0 )
goto error;
V_21 = F_57 ( V_49 ) ;
if ( V_21 < 0 )
goto error;
V_21 = F_77 ( V_91 ) ;
if ( V_21 < 0 )
goto error;
F_78 ( & V_60 -> V_61 , V_49 ) ;
return 0 ;
V_70:
F_66 ( & V_49 -> V_55 ) ;
V_142:
F_67 ( V_49 -> V_60 ) ;
F_68 ( & V_49 -> V_64 ) ;
error:
F_79 ( V_91 ) ;
return V_21 ;
}
static void F_80 ( struct V_130 * V_60 )
{
struct V_49 * V_49 = F_81 ( & V_60 -> V_61 ) ;
F_82 ( V_49 -> V_60 ) ;
if ( F_83 ( & V_49 -> V_55 ) < 0 ) {
F_84 ( & V_49 -> V_54 ) ;
F_26 ( & V_49 -> V_64 ) ;
F_15 ( V_49 ) ;
F_27 ( & V_49 -> V_64 ) ;
return;
}
F_85 ( & V_49 -> V_54 ) ;
}
static void F_86 ( struct V_130 * V_60 )
{
struct V_49 * V_49 = F_81 ( & V_60 -> V_61 ) ;
F_84 ( & V_49 -> V_54 ) ;
F_87 ( V_49 -> V_91 ) ;
F_26 ( & V_49 -> V_64 ) ;
F_15 ( V_49 ) ;
F_27 ( & V_49 -> V_64 ) ;
F_88 ( V_49 -> V_91 ) ;
}
static int T_6 F_89 ( void )
{
return F_90 ( & V_153 . V_145 ) ;
}
static void T_7 F_91 ( void )
{
F_92 ( & V_153 . V_145 ) ;
}
