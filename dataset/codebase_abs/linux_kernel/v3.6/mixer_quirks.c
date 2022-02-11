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
static int F_7 ( struct V_4 * V_5 ,
struct V_32 * V_33 )
{
int V_12 ;
while ( V_33 -> V_10 != NULL ) {
V_12 = F_3 ( V_5 , V_33 -> V_6 , V_33 -> V_7 ,
V_33 -> V_8 , V_33 -> V_9 , V_33 -> V_10 , V_33 -> V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
V_33 ++ ;
}
return 0 ;
}
static void F_8 ( struct V_34 * V_34 )
{
struct V_4 * V_5 = V_34 -> V_35 ;
const struct V_36 * V_37 = V_5 -> V_38 ;
T_2 V_39 ;
if ( V_34 -> V_40 < 0 || V_34 -> V_41 < V_37 -> V_42 )
return;
V_39 = V_5 -> V_43 [ V_37 -> V_44 ] ;
if ( V_37 -> V_45 == 2 )
V_39 |= V_5 -> V_43 [ V_37 -> V_44 + 1 ] << 8 ;
if ( V_39 == V_37 -> V_46 )
F_9 ( V_5 , V_37 -> V_47 ) ;
V_5 -> V_48 = V_39 ;
F_10 () ;
F_11 ( & V_5 -> V_49 ) ;
}
static long F_12 ( struct V_50 * V_51 , char T_3 * V_52 ,
long V_53 , T_4 * V_44 )
{
struct V_4 * V_5 = V_51 -> V_3 ;
int V_12 ;
T_2 V_48 ;
if ( V_53 != 1 && V_53 != 4 )
return - V_54 ;
V_12 = F_13 ( V_5 -> V_49 ,
( V_48 = F_14 ( & V_5 -> V_48 , 0 ) ) != 0 ) ;
if ( V_12 == 0 ) {
if ( V_53 == 1 )
V_12 = F_15 ( V_48 , V_52 ) ;
else
V_12 = F_15 ( V_48 , ( T_2 T_3 * ) V_52 ) ;
}
return V_12 < 0 ? V_12 : V_53 ;
}
static unsigned int F_16 ( struct V_50 * V_51 , struct V_55 * V_55 ,
T_5 * V_56 )
{
struct V_4 * V_5 = V_51 -> V_3 ;
F_17 ( V_55 , & V_5 -> V_49 , V_56 ) ;
return V_5 -> V_48 ? V_57 | V_58 : 0 ;
}
static int F_18 ( struct V_4 * V_5 )
{
struct V_50 * V_59 ;
int V_12 , V_60 , V_61 ;
for ( V_61 = 0 ; V_61 < F_19 ( V_62 ) ; ++ V_61 )
if ( V_62 [ V_61 ] . V_63 == V_5 -> V_64 -> V_63 )
break;
if ( V_61 >= F_19 ( V_62 ) )
return 0 ;
V_5 -> V_38 = & V_62 [ V_61 ] ;
V_60 = V_5 -> V_38 -> V_65 ;
F_20 ( & V_5 -> V_49 ) ;
V_12 = F_21 ( V_5 -> V_64 -> V_66 , L_1 , 0 , & V_59 ) ;
if ( V_12 < 0 )
return V_12 ;
snprintf ( V_59 -> V_10 , sizeof( V_59 -> V_10 ) ,
L_2 , V_5 -> V_64 -> V_66 -> V_67 ) ;
V_59 -> V_68 = V_69 ;
V_59 -> V_3 = V_5 ;
V_59 -> V_70 . V_71 = F_12 ;
V_59 -> V_70 . V_72 = F_16 ;
V_59 -> V_73 = 1 ;
V_5 -> V_74 = F_22 ( 0 , V_15 ) ;
if ( ! V_5 -> V_74 )
return - V_16 ;
V_5 -> V_75 = F_23 ( sizeof( * V_5 -> V_75 ) , V_15 ) ;
if ( ! V_5 -> V_75 ) {
F_24 ( V_5 -> V_74 ) ;
V_5 -> V_74 = NULL ;
return - V_16 ;
}
V_5 -> V_75 -> V_76 =
V_77 | V_78 | V_79 ;
V_5 -> V_75 -> V_80 = V_81 ;
V_5 -> V_75 -> V_82 = F_25 ( 0 ) ;
V_5 -> V_75 -> V_83 = F_25 ( 0 ) ;
V_5 -> V_75 -> V_84 = F_25 ( V_60 ) ;
F_26 ( V_5 -> V_74 , V_5 -> V_64 -> V_85 ,
F_27 ( V_5 -> V_64 -> V_85 , 0 ) ,
( V_86 * ) V_5 -> V_75 , V_5 -> V_43 , V_60 ,
F_8 , V_5 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_87 , struct V_88 * V_89 )
{
struct V_4 * V_5 = F_29 ( V_87 ) ;
int V_90 = V_87 -> V_91 ;
V_89 -> V_92 . integer . V_92 [ 0 ] = V_5 -> V_93 [ V_90 ] ;
return 0 ;
}
static int F_30 ( struct V_1 * V_87 , struct V_88 * V_89 )
{
struct V_4 * V_5 = F_29 ( V_87 ) ;
int V_90 = V_87 -> V_91 ;
int V_92 = V_89 -> V_92 . integer . V_92 [ 0 ] ;
int V_12 , V_94 ;
if ( V_92 > 1 )
return - V_54 ;
V_94 = V_92 != V_5 -> V_93 [ V_90 ] ;
if ( V_5 -> V_64 -> V_63 == F_31 ( 0x041e , 0x3042 ) )
V_12 = F_32 ( V_5 -> V_64 -> V_85 ,
F_33 ( V_5 -> V_64 -> V_85 , 0 ) , 0x24 ,
V_95 | V_96 | V_97 ,
! V_92 , 0 , NULL , 0 ) ;
if ( V_5 -> V_64 -> V_63 == F_31 ( 0x041e , 0x30df ) )
V_12 = F_32 ( V_5 -> V_64 -> V_85 ,
F_33 ( V_5 -> V_64 -> V_85 , 0 ) , 0x24 ,
V_95 | V_96 | V_97 ,
! V_92 , 0 , NULL , 0 ) ;
else
V_12 = F_32 ( V_5 -> V_64 -> V_85 ,
F_33 ( V_5 -> V_64 -> V_85 , 0 ) , 0x24 ,
V_95 | V_96 | V_97 ,
V_92 , V_90 + 2 , NULL , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_5 -> V_93 [ V_90 ] = V_92 ;
return V_94 ;
}
static int F_34 ( struct V_4 * V_5 )
{
int V_61 , V_12 ;
for ( V_61 = 0 ; V_61 < F_19 ( V_98 ) ; ++ V_61 ) {
if ( ( V_5 -> V_64 -> V_63 == F_31 ( 0x041e , 0x3042 ) ) && V_61 == 0 )
continue;
if ( ( V_5 -> V_64 -> V_63 == F_31 ( 0x041e , 0x30df ) ) && V_61 == 0 )
continue;
if ( V_61 > 1 &&
( V_5 -> V_64 -> V_63 == F_31 ( 0x041e , 0x3040 ) ||
V_5 -> V_64 -> V_63 == F_31 ( 0x041e , 0x3042 ) ||
V_5 -> V_64 -> V_63 == F_31 ( 0x041e , 0x30df ) ||
V_5 -> V_64 -> V_63 == F_31 ( 0x041e , 0x3048 ) ) )
break;
V_12 = F_35 ( V_5 -> V_64 -> V_66 ,
F_5 ( & V_98 [ V_61 ] , V_5 ) ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_5 -> V_93 [ 1 ] = 1 ;
return 0 ;
}
static void F_36 ( struct V_99 * V_100 ,
struct V_101 * V_102 )
{
static const struct V_103 {
int V_6 ;
const char * V_10 ;
} V_104 [] = {
{ 4 , L_3 } ,
{ 7 , L_4 } ,
{ 19 , L_5 } ,
{ 20 , L_6 } ,
{ - 1 , NULL }
} , V_105 [] = {
{ 4 , L_4 } ,
{ 3 , L_6 } ,
{ 0 , L_7 } ,
{ - 1 , NULL }
} ;
const struct V_103 * V_106 ;
struct V_4 * V_5 = V_100 -> V_3 ;
int V_61 , V_12 ;
V_86 V_52 [ 3 ] ;
F_37 ( V_102 , L_8 , V_5 -> V_64 -> V_66 -> V_67 ) ;
if ( V_5 -> V_64 -> V_63 == F_31 ( 0x041e , 0x3020 ) )
V_106 = V_104 ;
else if ( V_5 -> V_64 -> V_63 == F_31 ( 0x041e , 0x3040 ) ||
V_5 -> V_64 -> V_63 == F_31 ( 0x041e , 0x3048 ) )
V_106 = V_105 ;
else
return;
for ( V_61 = 0 ; V_106 [ V_61 ] . V_10 ; ++ V_61 ) {
F_37 ( V_102 , L_9 , V_106 [ V_61 ] . V_10 ) ;
V_12 = F_32 ( V_5 -> V_64 -> V_85 ,
F_27 ( V_5 -> V_64 -> V_85 , 0 ) ,
V_81 , V_77 | V_78 |
V_79 , 0 ,
V_106 [ V_61 ] . V_6 << 8 , V_52 , 3 ) ;
if ( V_12 == 3 && ( V_52 [ 0 ] == 3 || V_52 [ 0 ] == 6 ) )
F_37 ( V_102 , L_10 , V_52 [ 1 ] , V_52 [ 2 ] ) ;
else
F_37 ( V_102 , L_11 ) ;
}
}
static int F_38 ( struct V_1 * V_87 ,
struct V_88 * V_89 )
{
struct V_4 * V_5 = F_29 ( V_87 ) ;
V_89 -> V_92 . integer . V_92 [ 0 ] = ! ! ( V_5 -> V_107 & 0x02 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_87 ,
struct V_88 * V_89 )
{
struct V_4 * V_5 = F_29 ( V_87 ) ;
V_86 V_108 , V_109 ;
int V_12 , V_94 ;
V_108 = V_5 -> V_107 ;
if ( V_89 -> V_92 . integer . V_92 [ 0 ] )
V_109 = V_108 | 0x02 ;
else
V_109 = V_108 & ~ 0x02 ;
V_94 = V_109 != V_108 ;
V_12 = F_32 ( V_5 -> V_64 -> V_85 ,
F_33 ( V_5 -> V_64 -> V_85 , 0 ) , 0x08 ,
V_95 | V_96 | V_97 ,
50 , 0 , & V_109 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_5 -> V_107 = V_109 ;
return V_94 ;
}
static int F_40 ( struct V_4 * V_5 )
{
int V_12 ;
V_12 = F_35 ( V_5 -> V_64 -> V_66 ,
F_5 ( & V_110 , V_5 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_5 -> V_107 = 0x05 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_87 ,
struct V_88 * V_89 )
{
struct V_4 * V_5 = F_29 ( V_87 ) ;
struct V_111 * V_85 = V_5 -> V_64 -> V_85 ;
V_86 V_80 = ( V_87 -> V_91 >> 16 ) & 0xff ;
T_6 V_83 = V_87 -> V_91 & 0xffff ;
V_86 V_112 ;
int V_113 = F_42 ( V_85 , F_27 ( V_85 , 0 ) , V_80 ,
V_96 | V_114 | V_77 ,
0 , F_25 ( V_83 ) ,
& V_112 , sizeof( V_112 ) , 1000 ) ;
if ( V_113 < 0 ) {
F_43 ( V_115
L_12 , V_113 ) ;
return V_113 ;
}
V_89 -> V_92 . integer . V_92 [ 0 ] = V_112 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_87 ,
struct V_88 * V_89 )
{
struct V_4 * V_5 = F_29 ( V_87 ) ;
struct V_111 * V_85 = V_5 -> V_64 -> V_85 ;
V_86 V_80 = ( V_87 -> V_91 >> 16 ) & 0xff ;
T_6 V_83 = V_87 -> V_91 & 0xffff ;
T_6 V_82 = V_89 -> V_92 . integer . V_92 [ 0 ] ;
int V_113 = F_42 ( V_85 , F_33 ( V_85 , 0 ) , V_80 ,
V_96 | V_114 | V_95 ,
F_25 ( V_82 ) , F_25 ( V_83 ) ,
NULL , 0 , 1000 ) ;
if ( V_113 < 0 ) {
F_43 ( V_115
L_13 , V_113 ) ;
return V_113 ;
}
return 0 ;
}
static int F_45 ( struct V_4 * V_5 ,
const struct V_116 * V_117 ,
unsigned int V_53 )
{
int V_61 , V_12 = 0 ;
struct V_116 V_118 = {
. V_68 = V_119 ,
. V_29 = V_120 ,
. V_121 = F_41 ,
. V_122 = F_44 ,
. V_123 = V_124 ,
} ;
for ( V_61 = 0 ; V_61 < V_53 ; V_61 ++ ) {
struct V_1 * V_27 ;
V_118 . V_10 = V_117 [ V_61 ] . V_10 ;
V_118 . V_91 = V_117 [ V_61 ] . V_91 ;
V_27 = F_5 ( & V_118 , V_5 ) ;
V_12 = F_35 ( V_5 -> V_64 -> V_66 , V_27 ) ;
if ( V_12 < 0 )
break;
}
return V_12 ;
}
static int F_46 ( struct V_1 * V_87 ,
struct V_125 * V_126 )
{
static const char * V_127 [ 8 ] = { L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21
} ;
V_126 -> type = V_128 ;
V_126 -> V_53 = 1 ;
V_126 -> V_92 . V_129 . V_130 = 8 ;
if ( V_126 -> V_92 . V_129 . V_131 > 7 )
V_126 -> V_92 . V_129 . V_131 = 7 ;
strcpy ( V_126 -> V_92 . V_129 . V_10 ,
V_127 [ V_126 -> V_92 . V_129 . V_131 ] ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
struct V_132 * V_64 ;
struct V_4 * V_5 ;
struct V_133 * V_134 ;
int V_12 ;
unsigned char V_92 [ 2 ] ;
const int V_17 = 6 ;
const int V_135 = 1 ;
const int V_136 = 2 ;
V_92 [ 0 ] = 0x00 ;
V_92 [ 1 ] = 0x00 ;
V_134 = (struct V_133 * )
V_2 -> V_91 ;
if ( V_134 -> V_137 ) {
V_89 -> V_92 . V_129 . V_131 [ 0 ] = V_134 -> V_138 ;
return 0 ;
}
V_5 = (struct V_4 * ) V_134 -> V_5 ;
if ( F_48 ( ! V_5 ) )
return - V_54 ;
V_64 = (struct V_132 * ) V_5 -> V_64 ;
if ( F_48 ( ! V_64 ) )
return - V_54 ;
V_12 = F_32 ( V_64 -> V_85 ,
F_27 ( V_64 -> V_85 , 0 ) , V_139 ,
V_79 | V_78 | V_77 ,
V_135 << 8 , F_49 ( V_64 ) | ( V_17 << 8 ) ,
V_92 , V_136 ) ;
if ( V_12 < 0 )
return V_12 ;
V_89 -> V_92 . V_129 . V_131 [ 0 ] = V_92 [ 0 ] ;
V_134 -> V_138 = V_92 [ 0 ] ;
V_134 -> V_137 = 1 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
struct V_132 * V_64 ;
struct V_133 * V_134 ;
struct V_4 * V_5 ;
int V_94 , V_140 , V_12 , V_141 ;
unsigned char V_92 [ 2 ] ;
const int V_17 = 6 ;
const int V_135 = 1 ;
const int V_136 = 2 ;
V_94 = 0 ;
V_134 = (struct V_133 * )
V_2 -> V_91 ;
V_140 = V_134 -> V_138 ;
V_141 = V_89 -> V_92 . V_129 . V_131 [ 0 ] ;
V_5 = (struct V_4 * ) V_134 -> V_5 ;
if ( F_48 ( ! V_5 ) )
return - V_54 ;
V_64 = (struct V_132 * ) V_5 -> V_64 ;
if ( F_48 ( ! V_64 ) )
return - V_54 ;
if ( ! V_134 -> V_137 ) {
V_12 = F_32 ( V_64 -> V_85 ,
F_27 ( V_64 -> V_85 , 0 ) , V_139 ,
V_79 | V_78 | V_77 ,
V_135 << 8 , F_49 ( V_64 ) | ( V_17 << 8 ) ,
V_92 , V_136 ) ;
if ( V_12 < 0 )
return V_12 ;
V_140 = V_92 [ 0 ] ;
V_134 -> V_138 = V_140 ;
V_134 -> V_137 = 1 ;
}
if ( V_140 != V_141 ) {
V_92 [ 0 ] = V_141 ;
V_92 [ 1 ] = 0 ;
V_12 = F_32 ( V_64 -> V_85 ,
F_33 ( V_64 -> V_85 , 0 ) , V_142 ,
V_79 | V_78 | V_95 ,
V_135 << 8 , F_49 ( V_64 ) | ( V_17 << 8 ) ,
V_92 , V_136 ) ;
if ( V_12 < 0 )
return V_12 ;
V_134 -> V_138 = V_141 ;
V_134 -> V_137 = 1 ;
V_94 = 1 ;
}
return V_94 ;
}
static int F_51 ( struct V_4 * V_5 )
{
static struct V_116 V_118 = {
. V_68 = V_119 ,
. V_10 = L_22 ,
. V_90 = 0 ,
. V_29 = V_120 ,
. V_123 = F_46 ,
. V_121 = F_47 ,
. V_122 = F_50
} ;
int V_12 ;
struct V_1 * V_2 ;
struct V_133 * V_134 ;
V_134 = F_4 ( sizeof( * V_134 ) , V_15 ) ;
if ( ! V_134 )
return - V_16 ;
V_134 -> V_138 = 0 ;
V_134 -> V_137 = 0 ;
V_134 -> V_5 = V_5 ;
V_118 . V_91 = ( unsigned long ) V_134 ;
V_2 = F_5 ( & V_118 , V_5 -> V_64 ) ;
if ( ! V_2 ) {
F_2 ( V_134 ) ;
return - V_16 ;
}
V_12 = F_35 ( V_5 -> V_64 -> V_66 , V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_52 ( struct V_4 * V_5 )
{
char V_10 [ 64 ] ;
unsigned int V_7 , V_8 ;
int V_143 , V_144 , V_12 ;
const unsigned int V_17 = 5 ;
const int V_9 = V_145 ;
for ( V_144 = 0 ; V_144 < 8 ; V_144 ++ ) {
V_7 = V_144 + 1 ;
for ( V_143 = 0 ; V_143 < 8 ; V_143 ++ ) {
V_8 = 1 << V_143 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_23 ,
V_143 + 1 , V_144 + 1 ) ;
V_12 = F_3 ( V_5 , V_17 , V_7 ,
V_8 , V_9 , V_10 ,
& V_146 ) ;
if ( V_12 < 0 )
return V_12 ;
}
for ( V_143 = 8 ; V_143 < 16 ; V_143 ++ ) {
V_8 = 1 << V_143 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_24 ,
V_143 - 7 , V_144 + 1 ) ;
V_12 = F_3 ( V_5 , V_17 , V_7 ,
V_8 , V_9 , V_10 ,
& V_146 ) ;
if ( V_12 < 0 )
return V_12 ;
}
}
return 0 ;
}
static int F_53 ( struct V_4 * V_5 )
{
static const char V_10 [] = L_25 ;
const unsigned int V_17 = 6 ;
const int V_9 = V_147 ;
const unsigned int V_7 = 2 ;
const unsigned int V_8 = 0 ;
return F_3 ( V_5 , V_17 , V_7 , V_8 , V_9 ,
V_10 , V_146 ) ;
}
static int F_54 ( struct V_4 * V_5 )
{
static const char V_10 [] = L_26 ;
const unsigned int V_17 = 6 ;
const int V_9 = V_145 ;
const unsigned int V_7 = 3 ;
const unsigned int V_8 = 0 ;
return F_3 ( V_5 , V_17 , V_7 , V_8 , V_9 ,
V_10 , V_146 ) ;
}
static int F_55 ( struct V_4 * V_5 )
{
static const char V_10 [] = L_27 ;
const unsigned int V_17 = 6 ;
const int V_9 = V_147 ;
const unsigned int V_7 = 4 ;
const unsigned int V_8 = 0 ;
return F_3 ( V_5 , V_17 , V_7 , V_8 , V_9 ,
V_10 , NULL ) ;
}
static int F_56 ( struct V_4 * V_5 )
{
unsigned int V_8 ;
int V_12 , V_148 ;
char V_10 [ 48 ] ;
const unsigned int V_17 = 7 ;
const int V_9 = V_145 ;
const unsigned int V_7 = 7 ;
for ( V_148 = 0 ; V_148 < 4 ; ++ V_148 ) {
V_8 = 1 << V_148 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_28 , V_148 + 1 ) ;
V_12 = F_3 ( V_5 , V_17 , V_7 ,
V_8 , V_9 , V_10 ,
V_146 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static int F_57 ( struct V_4 * V_5 )
{
unsigned int V_8 ;
int V_12 , V_148 ;
char V_10 [ 48 ] ;
const unsigned int V_17 = 5 ;
const int V_9 = V_145 ;
const unsigned int V_7 = 9 ;
for ( V_148 = 0 ; V_148 < 8 ; ++ V_148 ) {
V_8 = 1 << V_148 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_29 , V_148 + 1 ) ;
V_12 = F_3 ( V_5 , V_17 , V_7 , V_8 ,
V_9 , V_10 ,
V_146 ) ;
if ( V_12 < 0 )
return V_12 ;
}
for ( V_148 = 8 ; V_148 < 16 ; ++ V_148 ) {
V_8 = 1 << V_148 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_30 , V_148 - 7 ) ;
V_12 = F_3 ( V_5 , V_17 , V_7 , V_8 ,
V_9 , V_10 ,
V_146 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static int F_58 ( struct V_4 * V_5 )
{
int V_12 ;
V_12 = F_52 ( V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_51 ( V_5 ) ;
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
V_12 = F_57 ( V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
void F_59 ( struct V_132 * V_64 ,
unsigned char V_149 )
{
struct V_4 * V_5 ;
struct V_13 * V_14 ;
int V_6 = 12 ;
F_60 (mixer, &chip->mixer_list, list) {
V_14 = V_5 -> V_150 [ V_6 ] ;
if ( V_14 ) {
F_61 ( V_14 , V_142 ,
V_14 -> V_7 << 8 ,
V_149 ) ;
F_9 ( V_5 , V_6 ) ;
}
break;
}
}
int F_62 ( struct V_4 * V_5 )
{
int V_12 = 0 ;
struct V_99 * V_100 ;
if ( ( V_12 = F_18 ( V_5 ) ) < 0 )
return V_12 ;
switch ( V_5 -> V_64 -> V_63 ) {
case F_31 ( 0x041e , 0x3020 ) :
case F_31 ( 0x041e , 0x3040 ) :
case F_31 ( 0x041e , 0x3042 ) :
case F_31 ( 0x041e , 0x30df ) :
case F_31 ( 0x041e , 0x3048 ) :
V_12 = F_34 ( V_5 ) ;
if ( V_12 < 0 )
break;
if ( ! F_63 ( V_5 -> V_64 -> V_66 , L_31 , & V_100 ) )
F_64 ( V_100 , V_5 ,
F_36 ) ;
break;
case F_31 ( 0x0763 , 0x2080 ) :
case F_31 ( 0x0763 , 0x2081 ) :
V_12 = F_58 ( V_5 ) ;
break;
case F_31 ( 0x0b05 , 0x1739 ) :
case F_31 ( 0x0b05 , 0x1743 ) :
V_12 = F_40 ( V_5 ) ;
break;
case F_31 ( 0x17cc , 0x1011 ) :
V_12 = F_45 ( V_5 ,
V_151 ,
F_19 ( V_151 ) ) ;
break;
case F_31 ( 0x17cc , 0x1021 ) :
V_12 = F_45 ( V_5 ,
V_152 ,
F_19 ( V_152 ) ) ;
break;
case F_31 ( 0x200c , 0x1018 ) :
V_12 = F_7 ( V_5 , V_153 ) ;
break;
}
return V_12 ;
}
void F_65 ( struct V_4 * V_5 ,
int V_6 )
{
if ( ! V_5 -> V_38 )
return;
switch ( V_6 ) {
case 0 :
V_5 -> V_74 -> V_85 = V_5 -> V_64 -> V_85 ;
F_66 ( V_5 -> V_74 , V_154 ) ;
break;
case 4 :
case 7 :
case 19 :
case 20 :
break;
case 3 :
if ( V_5 -> V_64 -> V_63 == F_31 ( 0x041e , 0x3040 ) ||
V_5 -> V_64 -> V_63 == F_31 ( 0x041e , 0x3048 ) )
F_9 ( V_5 , V_5 -> V_38 -> V_47 ) ;
break;
default:
F_67 ( V_155 L_32 , V_6 ) ;
break;
}
}
