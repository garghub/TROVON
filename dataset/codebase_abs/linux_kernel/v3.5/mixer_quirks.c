static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static int F_3 ( struct V_4 * V_5 ,
unsigned int V_6 ,
unsigned int V_7 ,
unsigned int V_8 ,
int V_9 ,
const char * V_10 ,
T_1 * V_11 )
{
int V_12 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
V_14 = F_4 ( sizeof( * V_14 ) , V_15 ) ;
if ( ! V_14 )
return - V_16 ;
V_14 -> V_17 = V_6 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_9 = V_9 ;
V_14 -> V_18 = 1 ;
V_14 -> V_7 = V_7 ;
V_14 -> V_8 = V_8 ;
V_14 -> V_19 = 0 ;
V_14 -> V_20 = 1 ;
V_14 -> V_21 = 0 ;
V_14 -> V_22 = 0 ;
V_14 -> V_23 = 0 ;
V_2 = F_5 ( V_24 , V_14 ) ;
if ( ! V_2 ) {
F_2 ( V_14 ) ;
return - V_16 ;
}
snprintf ( V_2 -> V_17 . V_10 , sizeof( V_2 -> V_17 . V_10 ) , V_10 ) ;
V_2 -> V_25 = F_1 ;
if ( V_11 ) {
V_2 -> V_26 . V_27 = V_11 ;
V_2 -> V_28 [ 0 ] . V_29 |=
V_30 |
V_31 ;
}
V_12 = F_6 ( V_5 , V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static void F_7 ( struct V_32 * V_32 )
{
struct V_4 * V_5 = V_32 -> V_33 ;
const struct V_34 * V_35 = V_5 -> V_36 ;
T_2 V_37 ;
if ( V_32 -> V_38 < 0 || V_32 -> V_39 < V_35 -> V_40 )
return;
V_37 = V_5 -> V_41 [ V_35 -> V_42 ] ;
if ( V_35 -> V_43 == 2 )
V_37 |= V_5 -> V_41 [ V_35 -> V_42 + 1 ] << 8 ;
if ( V_37 == V_35 -> V_44 )
F_8 ( V_5 , V_35 -> V_45 ) ;
V_5 -> V_46 = V_37 ;
F_9 () ;
F_10 ( & V_5 -> V_47 ) ;
}
static long F_11 ( struct V_48 * V_49 , char T_3 * V_50 ,
long V_51 , T_4 * V_42 )
{
struct V_4 * V_5 = V_49 -> V_3 ;
int V_12 ;
T_2 V_46 ;
if ( V_51 != 1 && V_51 != 4 )
return - V_52 ;
V_12 = F_12 ( V_5 -> V_47 ,
( V_46 = F_13 ( & V_5 -> V_46 , 0 ) ) != 0 ) ;
if ( V_12 == 0 ) {
if ( V_51 == 1 )
V_12 = F_14 ( V_46 , V_50 ) ;
else
V_12 = F_14 ( V_46 , ( T_2 T_3 * ) V_50 ) ;
}
return V_12 < 0 ? V_12 : V_51 ;
}
static unsigned int F_15 ( struct V_48 * V_49 , struct V_53 * V_53 ,
T_5 * V_54 )
{
struct V_4 * V_5 = V_49 -> V_3 ;
F_16 ( V_53 , & V_5 -> V_47 , V_54 ) ;
return V_5 -> V_46 ? V_55 | V_56 : 0 ;
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_48 * V_57 ;
int V_12 , V_58 , V_59 ;
for ( V_59 = 0 ; V_59 < F_18 ( V_60 ) ; ++ V_59 )
if ( V_60 [ V_59 ] . V_61 == V_5 -> V_62 -> V_61 )
break;
if ( V_59 >= F_18 ( V_60 ) )
return 0 ;
V_5 -> V_36 = & V_60 [ V_59 ] ;
V_58 = V_5 -> V_36 -> V_63 ;
F_19 ( & V_5 -> V_47 ) ;
V_12 = F_20 ( V_5 -> V_62 -> V_64 , L_1 , 0 , & V_57 ) ;
if ( V_12 < 0 )
return V_12 ;
snprintf ( V_57 -> V_10 , sizeof( V_57 -> V_10 ) ,
L_2 , V_5 -> V_62 -> V_64 -> V_65 ) ;
V_57 -> V_66 = V_67 ;
V_57 -> V_3 = V_5 ;
V_57 -> V_68 . V_69 = F_11 ;
V_57 -> V_68 . V_70 = F_15 ;
V_57 -> V_71 = 1 ;
V_5 -> V_72 = F_21 ( 0 , V_15 ) ;
if ( ! V_5 -> V_72 )
return - V_16 ;
V_5 -> V_73 = F_22 ( sizeof( * V_5 -> V_73 ) , V_15 ) ;
if ( ! V_5 -> V_73 ) {
F_23 ( V_5 -> V_72 ) ;
V_5 -> V_72 = NULL ;
return - V_16 ;
}
V_5 -> V_73 -> V_74 =
V_75 | V_76 | V_77 ;
V_5 -> V_73 -> V_78 = V_79 ;
V_5 -> V_73 -> V_80 = F_24 ( 0 ) ;
V_5 -> V_73 -> V_81 = F_24 ( 0 ) ;
V_5 -> V_73 -> V_82 = F_24 ( V_58 ) ;
F_25 ( V_5 -> V_72 , V_5 -> V_62 -> V_83 ,
F_26 ( V_5 -> V_62 -> V_83 , 0 ) ,
( V_84 * ) V_5 -> V_73 , V_5 -> V_41 , V_58 ,
F_7 , V_5 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_85 , struct V_86 * V_87 )
{
struct V_4 * V_5 = F_28 ( V_85 ) ;
int V_88 = V_85 -> V_89 ;
V_87 -> V_90 . integer . V_90 [ 0 ] = V_5 -> V_91 [ V_88 ] ;
return 0 ;
}
static int F_29 ( struct V_1 * V_85 , struct V_86 * V_87 )
{
struct V_4 * V_5 = F_28 ( V_85 ) ;
int V_88 = V_85 -> V_89 ;
int V_90 = V_87 -> V_90 . integer . V_90 [ 0 ] ;
int V_12 , V_92 ;
if ( V_90 > 1 )
return - V_52 ;
V_92 = V_90 != V_5 -> V_91 [ V_88 ] ;
if ( V_5 -> V_62 -> V_61 == F_30 ( 0x041e , 0x3042 ) )
V_12 = F_31 ( V_5 -> V_62 -> V_83 ,
F_32 ( V_5 -> V_62 -> V_83 , 0 ) , 0x24 ,
V_93 | V_94 | V_95 ,
! V_90 , 0 , NULL , 0 ) ;
if ( V_5 -> V_62 -> V_61 == F_30 ( 0x041e , 0x30df ) )
V_12 = F_31 ( V_5 -> V_62 -> V_83 ,
F_32 ( V_5 -> V_62 -> V_83 , 0 ) , 0x24 ,
V_93 | V_94 | V_95 ,
! V_90 , 0 , NULL , 0 ) ;
else
V_12 = F_31 ( V_5 -> V_62 -> V_83 ,
F_32 ( V_5 -> V_62 -> V_83 , 0 ) , 0x24 ,
V_93 | V_94 | V_95 ,
V_90 , V_88 + 2 , NULL , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_5 -> V_91 [ V_88 ] = V_90 ;
return V_92 ;
}
static int F_33 ( struct V_4 * V_5 )
{
int V_59 , V_12 ;
for ( V_59 = 0 ; V_59 < F_18 ( V_96 ) ; ++ V_59 ) {
if ( ( V_5 -> V_62 -> V_61 == F_30 ( 0x041e , 0x3042 ) ) && V_59 == 0 )
continue;
if ( ( V_5 -> V_62 -> V_61 == F_30 ( 0x041e , 0x30df ) ) && V_59 == 0 )
continue;
if ( V_59 > 1 &&
( V_5 -> V_62 -> V_61 == F_30 ( 0x041e , 0x3040 ) ||
V_5 -> V_62 -> V_61 == F_30 ( 0x041e , 0x3042 ) ||
V_5 -> V_62 -> V_61 == F_30 ( 0x041e , 0x30df ) ||
V_5 -> V_62 -> V_61 == F_30 ( 0x041e , 0x3048 ) ) )
break;
V_12 = F_34 ( V_5 -> V_62 -> V_64 ,
F_5 ( & V_96 [ V_59 ] , V_5 ) ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_5 -> V_91 [ 1 ] = 1 ;
return 0 ;
}
static void F_35 ( struct V_97 * V_98 ,
struct V_99 * V_100 )
{
static const struct V_101 {
int V_6 ;
const char * V_10 ;
} V_102 [] = {
{ 4 , L_3 } ,
{ 7 , L_4 } ,
{ 19 , L_5 } ,
{ 20 , L_6 } ,
{ - 1 , NULL }
} , V_103 [] = {
{ 4 , L_4 } ,
{ 3 , L_6 } ,
{ 0 , L_7 } ,
{ - 1 , NULL }
} ;
const struct V_101 * V_104 ;
struct V_4 * V_5 = V_98 -> V_3 ;
int V_59 , V_12 ;
V_84 V_50 [ 3 ] ;
F_36 ( V_100 , L_8 , V_5 -> V_62 -> V_64 -> V_65 ) ;
if ( V_5 -> V_62 -> V_61 == F_30 ( 0x041e , 0x3020 ) )
V_104 = V_102 ;
else if ( V_5 -> V_62 -> V_61 == F_30 ( 0x041e , 0x3040 ) ||
V_5 -> V_62 -> V_61 == F_30 ( 0x041e , 0x3048 ) )
V_104 = V_103 ;
else
return;
for ( V_59 = 0 ; V_104 [ V_59 ] . V_10 ; ++ V_59 ) {
F_36 ( V_100 , L_9 , V_104 [ V_59 ] . V_10 ) ;
V_12 = F_31 ( V_5 -> V_62 -> V_83 ,
F_26 ( V_5 -> V_62 -> V_83 , 0 ) ,
V_79 , V_75 | V_76 |
V_77 , 0 ,
V_104 [ V_59 ] . V_6 << 8 , V_50 , 3 ) ;
if ( V_12 == 3 && ( V_50 [ 0 ] == 3 || V_50 [ 0 ] == 6 ) )
F_36 ( V_100 , L_10 , V_50 [ 1 ] , V_50 [ 2 ] ) ;
else
F_36 ( V_100 , L_11 ) ;
}
}
static int F_37 ( struct V_1 * V_85 ,
struct V_86 * V_87 )
{
struct V_4 * V_5 = F_28 ( V_85 ) ;
V_87 -> V_90 . integer . V_90 [ 0 ] = ! ! ( V_5 -> V_105 & 0x02 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_85 ,
struct V_86 * V_87 )
{
struct V_4 * V_5 = F_28 ( V_85 ) ;
V_84 V_106 , V_107 ;
int V_12 , V_92 ;
V_106 = V_5 -> V_105 ;
if ( V_87 -> V_90 . integer . V_90 [ 0 ] )
V_107 = V_106 | 0x02 ;
else
V_107 = V_106 & ~ 0x02 ;
V_92 = V_107 != V_106 ;
V_12 = F_31 ( V_5 -> V_62 -> V_83 ,
F_32 ( V_5 -> V_62 -> V_83 , 0 ) , 0x08 ,
V_93 | V_94 | V_95 ,
50 , 0 , & V_107 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_5 -> V_105 = V_107 ;
return V_92 ;
}
static int F_39 ( struct V_4 * V_5 )
{
int V_12 ;
V_12 = F_34 ( V_5 -> V_62 -> V_64 ,
F_5 ( & V_108 , V_5 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_5 -> V_105 = 0x05 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_85 ,
struct V_86 * V_87 )
{
struct V_4 * V_5 = F_28 ( V_85 ) ;
struct V_109 * V_83 = V_5 -> V_62 -> V_83 ;
V_84 V_78 = ( V_85 -> V_89 >> 16 ) & 0xff ;
T_6 V_81 = V_85 -> V_89 & 0xffff ;
V_84 V_110 ;
int V_111 = F_41 ( V_83 , F_26 ( V_83 , 0 ) , V_78 ,
V_94 | V_112 | V_75 ,
0 , F_24 ( V_81 ) ,
& V_110 , sizeof( V_110 ) , 1000 ) ;
if ( V_111 < 0 ) {
F_42 ( V_113
L_12 , V_111 ) ;
return V_111 ;
}
V_87 -> V_90 . integer . V_90 [ 0 ] = V_110 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_85 ,
struct V_86 * V_87 )
{
struct V_4 * V_5 = F_28 ( V_85 ) ;
struct V_109 * V_83 = V_5 -> V_62 -> V_83 ;
V_84 V_78 = ( V_85 -> V_89 >> 16 ) & 0xff ;
T_6 V_81 = V_85 -> V_89 & 0xffff ;
T_6 V_80 = V_87 -> V_90 . integer . V_90 [ 0 ] ;
int V_111 = F_41 ( V_83 , F_32 ( V_83 , 0 ) , V_78 ,
V_94 | V_112 | V_93 ,
F_24 ( V_80 ) , F_24 ( V_81 ) ,
NULL , 0 , 1000 ) ;
if ( V_111 < 0 ) {
F_42 ( V_113
L_13 , V_111 ) ;
return V_111 ;
}
return 0 ;
}
static int F_44 ( struct V_4 * V_5 ,
const struct V_114 * V_115 ,
unsigned int V_51 )
{
int V_59 , V_12 = 0 ;
struct V_114 V_116 = {
. V_66 = V_117 ,
. V_29 = V_118 ,
. V_119 = F_40 ,
. V_120 = F_43 ,
. V_121 = V_122 ,
} ;
for ( V_59 = 0 ; V_59 < V_51 ; V_59 ++ ) {
struct V_1 * V_27 ;
V_116 . V_10 = V_115 [ V_59 ] . V_10 ;
V_116 . V_89 = V_115 [ V_59 ] . V_89 ;
V_27 = F_5 ( & V_116 , V_5 ) ;
V_12 = F_34 ( V_5 -> V_62 -> V_64 , V_27 ) ;
if ( V_12 < 0 )
break;
}
return V_12 ;
}
static int F_45 ( struct V_1 * V_85 ,
struct V_123 * V_124 )
{
static const char * V_125 [ 8 ] = { L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21
} ;
V_124 -> type = V_126 ;
V_124 -> V_51 = 1 ;
V_124 -> V_90 . V_127 . V_128 = 8 ;
if ( V_124 -> V_90 . V_127 . V_129 > 7 )
V_124 -> V_90 . V_127 . V_129 = 7 ;
strcpy ( V_124 -> V_90 . V_127 . V_10 ,
V_125 [ V_124 -> V_90 . V_127 . V_129 ] ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
struct V_130 * V_62 ;
struct V_4 * V_5 ;
struct V_131 * V_132 ;
int V_12 ;
unsigned char V_90 [ 2 ] ;
const int V_17 = 6 ;
const int V_133 = 1 ;
const int V_134 = 2 ;
V_90 [ 0 ] = 0x00 ;
V_90 [ 1 ] = 0x00 ;
V_132 = (struct V_131 * )
V_2 -> V_89 ;
if ( V_132 -> V_135 ) {
V_87 -> V_90 . V_127 . V_129 [ 0 ] = V_132 -> V_136 ;
return 0 ;
}
V_5 = (struct V_4 * ) V_132 -> V_5 ;
if ( F_47 ( ! V_5 ) )
return - V_52 ;
V_62 = (struct V_130 * ) V_5 -> V_62 ;
if ( F_47 ( ! V_62 ) )
return - V_52 ;
V_12 = F_31 ( V_62 -> V_83 ,
F_26 ( V_62 -> V_83 , 0 ) , V_137 ,
V_77 | V_76 | V_75 ,
V_133 << 8 , F_48 ( V_62 ) | ( V_17 << 8 ) ,
V_90 , V_134 ) ;
if ( V_12 < 0 )
return V_12 ;
V_87 -> V_90 . V_127 . V_129 [ 0 ] = V_90 [ 0 ] ;
V_132 -> V_136 = V_90 [ 0 ] ;
V_132 -> V_135 = 1 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
struct V_130 * V_62 ;
struct V_131 * V_132 ;
struct V_4 * V_5 ;
int V_92 , V_138 , V_12 , V_139 ;
unsigned char V_90 [ 2 ] ;
const int V_17 = 6 ;
const int V_133 = 1 ;
const int V_134 = 2 ;
V_92 = 0 ;
V_132 = (struct V_131 * )
V_2 -> V_89 ;
V_138 = V_132 -> V_136 ;
V_139 = V_87 -> V_90 . V_127 . V_129 [ 0 ] ;
V_5 = (struct V_4 * ) V_132 -> V_5 ;
if ( F_47 ( ! V_5 ) )
return - V_52 ;
V_62 = (struct V_130 * ) V_5 -> V_62 ;
if ( F_47 ( ! V_62 ) )
return - V_52 ;
if ( ! V_132 -> V_135 ) {
V_12 = F_31 ( V_62 -> V_83 ,
F_26 ( V_62 -> V_83 , 0 ) , V_137 ,
V_77 | V_76 | V_75 ,
V_133 << 8 , F_48 ( V_62 ) | ( V_17 << 8 ) ,
V_90 , V_134 ) ;
if ( V_12 < 0 )
return V_12 ;
V_138 = V_90 [ 0 ] ;
V_132 -> V_136 = V_138 ;
V_132 -> V_135 = 1 ;
}
if ( V_138 != V_139 ) {
V_90 [ 0 ] = V_139 ;
V_90 [ 1 ] = 0 ;
V_12 = F_31 ( V_62 -> V_83 ,
F_32 ( V_62 -> V_83 , 0 ) , V_140 ,
V_77 | V_76 | V_93 ,
V_133 << 8 , F_48 ( V_62 ) | ( V_17 << 8 ) ,
V_90 , V_134 ) ;
if ( V_12 < 0 )
return V_12 ;
V_132 -> V_136 = V_139 ;
V_132 -> V_135 = 1 ;
V_92 = 1 ;
}
return V_92 ;
}
static int F_50 ( struct V_4 * V_5 )
{
static struct V_114 V_116 = {
. V_66 = V_117 ,
. V_10 = L_22 ,
. V_88 = 0 ,
. V_29 = V_118 ,
. V_121 = F_45 ,
. V_119 = F_46 ,
. V_120 = F_49
} ;
int V_12 ;
struct V_1 * V_2 ;
struct V_131 * V_132 ;
V_132 = F_4 ( sizeof( * V_132 ) , V_15 ) ;
if ( ! V_132 )
return - V_16 ;
V_132 -> V_136 = 0 ;
V_132 -> V_135 = 0 ;
V_132 -> V_5 = V_5 ;
V_116 . V_89 = ( unsigned long ) V_132 ;
V_2 = F_5 ( & V_116 , V_5 -> V_62 ) ;
if ( ! V_2 ) {
F_2 ( V_132 ) ;
return - V_16 ;
}
V_12 = F_34 ( V_5 -> V_62 -> V_64 , V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_51 ( struct V_4 * V_5 )
{
char V_10 [ 64 ] ;
unsigned int V_7 , V_8 ;
int V_141 , V_142 , V_12 ;
const unsigned int V_17 = 5 ;
const int V_9 = V_143 ;
for ( V_142 = 0 ; V_142 < 8 ; V_142 ++ ) {
V_7 = V_142 + 1 ;
for ( V_141 = 0 ; V_141 < 8 ; V_141 ++ ) {
V_8 = 1 << V_141 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_23 ,
V_141 + 1 , V_142 + 1 ) ;
V_12 = F_3 ( V_5 , V_17 , V_7 ,
V_8 , V_9 , V_10 ,
& V_144 ) ;
if ( V_12 < 0 )
return V_12 ;
}
for ( V_141 = 8 ; V_141 < 16 ; V_141 ++ ) {
V_8 = 1 << V_141 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_24 ,
V_141 - 7 , V_142 + 1 ) ;
V_12 = F_3 ( V_5 , V_17 , V_7 ,
V_8 , V_9 , V_10 ,
& V_144 ) ;
if ( V_12 < 0 )
return V_12 ;
}
}
return 0 ;
}
static int F_52 ( struct V_4 * V_5 )
{
static const char V_10 [] = L_25 ;
const unsigned int V_17 = 6 ;
const int V_9 = V_145 ;
const unsigned int V_7 = 2 ;
const unsigned int V_8 = 0 ;
return F_3 ( V_5 , V_17 , V_7 , V_8 , V_9 ,
V_10 , V_144 ) ;
}
static int F_53 ( struct V_4 * V_5 )
{
static const char V_10 [] = L_26 ;
const unsigned int V_17 = 6 ;
const int V_9 = V_143 ;
const unsigned int V_7 = 3 ;
const unsigned int V_8 = 0 ;
return F_3 ( V_5 , V_17 , V_7 , V_8 , V_9 ,
V_10 , V_144 ) ;
}
static int F_54 ( struct V_4 * V_5 )
{
static const char V_10 [] = L_27 ;
const unsigned int V_17 = 6 ;
const int V_9 = V_145 ;
const unsigned int V_7 = 4 ;
const unsigned int V_8 = 0 ;
return F_3 ( V_5 , V_17 , V_7 , V_8 , V_9 ,
V_10 , NULL ) ;
}
static int F_55 ( struct V_4 * V_5 )
{
unsigned int V_8 ;
int V_12 , V_146 ;
char V_10 [ 48 ] ;
const unsigned int V_17 = 7 ;
const int V_9 = V_143 ;
const unsigned int V_7 = 7 ;
for ( V_146 = 0 ; V_146 < 4 ; ++ V_146 ) {
V_8 = 1 << V_146 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_28 , V_146 + 1 ) ;
V_12 = F_3 ( V_5 , V_17 , V_7 ,
V_8 , V_9 , V_10 ,
V_144 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static int F_56 ( struct V_4 * V_5 )
{
unsigned int V_8 ;
int V_12 , V_146 ;
char V_10 [ 48 ] ;
const unsigned int V_17 = 5 ;
const int V_9 = V_143 ;
const unsigned int V_7 = 9 ;
for ( V_146 = 0 ; V_146 < 8 ; ++ V_146 ) {
V_8 = 1 << V_146 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_29 , V_146 + 1 ) ;
V_12 = F_3 ( V_5 , V_17 , V_7 , V_8 ,
V_9 , V_10 ,
V_144 ) ;
if ( V_12 < 0 )
return V_12 ;
}
for ( V_146 = 8 ; V_146 < 16 ; ++ V_146 ) {
V_8 = 1 << V_146 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_30 , V_146 - 7 ) ;
V_12 = F_3 ( V_5 , V_17 , V_7 , V_8 ,
V_9 , V_10 ,
V_144 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static int F_57 ( struct V_4 * V_5 )
{
int V_12 ;
V_12 = F_51 ( V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_50 ( V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_52 ( V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_53 ( V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_54 ( V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_55 ( V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_56 ( V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_58 ( struct V_4 * V_5 )
{
int V_12 ;
V_12 = F_3 ( V_5 , 4 , 1 , 0x0 , V_147 ,
L_31 , NULL ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_5 , 4 , 2 , 0x1 , V_143 ,
L_32 , NULL ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_5 , 4 , 2 , 0x2 , V_143 ,
L_33 , NULL ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_5 , 7 , 1 , 0x0 , V_147 ,
L_34 , NULL ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_5 , 7 , 2 , 0x1 , V_143 ,
L_35 , NULL ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_5 , 7 , 2 , 0x2 , V_143 ,
L_36 , NULL ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_5 , 10 , 1 , 0x0 , V_147 ,
L_37 , NULL ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_5 , 10 , 2 , 0x1 , V_143 ,
L_38 , NULL ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_5 , 10 , 2 , 0x2 , V_143 ,
L_39 , NULL ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
void F_59 ( struct V_130 * V_62 ,
unsigned char V_148 )
{
struct V_4 * V_5 ;
struct V_13 * V_14 ;
int V_6 = 12 ;
F_60 (mixer, &chip->mixer_list, list) {
V_14 = V_5 -> V_149 [ V_6 ] ;
if ( V_14 ) {
F_61 ( V_14 , V_140 ,
V_14 -> V_7 << 8 ,
V_148 ) ;
F_8 ( V_5 , V_6 ) ;
}
break;
}
}
int F_62 ( struct V_4 * V_5 )
{
int V_12 = 0 ;
struct V_97 * V_98 ;
if ( ( V_12 = F_17 ( V_5 ) ) < 0 )
return V_12 ;
switch ( V_5 -> V_62 -> V_61 ) {
case F_30 ( 0x041e , 0x3020 ) :
case F_30 ( 0x041e , 0x3040 ) :
case F_30 ( 0x041e , 0x3042 ) :
case F_30 ( 0x041e , 0x30df ) :
case F_30 ( 0x041e , 0x3048 ) :
V_12 = F_33 ( V_5 ) ;
if ( V_12 < 0 )
break;
if ( ! F_63 ( V_5 -> V_62 -> V_64 , L_40 , & V_98 ) )
F_64 ( V_98 , V_5 ,
F_35 ) ;
break;
case F_30 ( 0x0763 , 0x2080 ) :
case F_30 ( 0x0763 , 0x2081 ) :
V_12 = F_57 ( V_5 ) ;
break;
case F_30 ( 0x0b05 , 0x1739 ) :
case F_30 ( 0x0b05 , 0x1743 ) :
V_12 = F_39 ( V_5 ) ;
break;
case F_30 ( 0x17cc , 0x1011 ) :
V_12 = F_44 ( V_5 ,
V_150 ,
F_18 ( V_150 ) ) ;
break;
case F_30 ( 0x17cc , 0x1021 ) :
V_12 = F_44 ( V_5 ,
V_151 ,
F_18 ( V_151 ) ) ;
break;
case F_30 ( 0x200c , 0x1018 ) :
V_12 = F_58 ( V_5 ) ;
break;
}
return V_12 ;
}
void F_65 ( struct V_4 * V_5 ,
int V_6 )
{
if ( ! V_5 -> V_36 )
return;
switch ( V_6 ) {
case 0 :
V_5 -> V_72 -> V_83 = V_5 -> V_62 -> V_83 ;
F_66 ( V_5 -> V_72 , V_152 ) ;
break;
case 4 :
case 7 :
case 19 :
case 20 :
break;
case 3 :
if ( V_5 -> V_62 -> V_61 == F_30 ( 0x041e , 0x3040 ) ||
V_5 -> V_62 -> V_61 == F_30 ( 0x041e , 0x3048 ) )
F_8 ( V_5 , V_5 -> V_36 -> V_45 ) ;
break;
default:
F_67 ( V_153 L_41 , V_6 ) ;
break;
}
}
