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
unsigned int V_10 ,
const char * V_11 ,
T_1 * V_12 )
{
int V_13 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
V_15 = F_4 ( sizeof( * V_15 ) , V_16 ) ;
if ( ! V_15 )
return - V_17 ;
V_15 -> V_18 = V_6 ;
V_15 -> V_5 = V_5 ;
V_15 -> V_9 = V_9 ;
V_15 -> V_19 = 1 ;
V_15 -> V_7 = V_7 ;
V_15 -> V_8 = V_8 ;
V_15 -> V_10 = V_10 ;
V_15 -> V_20 = 0 ;
V_15 -> V_21 = 1 ;
V_15 -> V_22 = 0 ;
V_15 -> V_23 = 0 ;
V_15 -> V_24 = 0 ;
V_2 = F_5 ( V_25 , V_15 ) ;
if ( ! V_2 ) {
F_2 ( V_15 ) ;
return - V_17 ;
}
snprintf ( V_2 -> V_18 . V_11 , sizeof( V_2 -> V_18 . V_11 ) , V_11 ) ;
V_2 -> V_26 = F_1 ;
if ( V_12 ) {
V_2 -> V_27 . V_28 = V_12 ;
V_2 -> V_29 [ 0 ] . V_30 |=
V_31 |
V_32 ;
}
V_13 = F_6 ( V_5 , V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 ,
unsigned int V_6 ,
unsigned int V_7 ,
unsigned int V_8 ,
int V_9 ,
const char * V_11 ,
T_1 * V_12 )
{
return F_3 ( V_5 , V_6 , V_7 , V_8 ,
V_9 , 0 , V_11 , V_12 ) ;
}
static int F_8 ( struct V_4 * V_5 ,
struct V_33 * V_34 )
{
int V_13 ;
while ( V_34 -> V_11 != NULL ) {
V_13 = F_7 ( V_5 , V_34 -> V_6 , V_34 -> V_7 ,
V_34 -> V_8 , V_34 -> V_9 , V_34 -> V_11 , V_34 -> V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
V_34 ++ ;
}
return 0 ;
}
static void F_9 ( struct V_35 * V_35 )
{
struct V_4 * V_5 = V_35 -> V_36 ;
const struct V_37 * V_38 = V_5 -> V_39 ;
T_2 V_40 ;
if ( V_35 -> V_41 < 0 || V_35 -> V_42 < V_38 -> V_43 )
return;
V_40 = V_5 -> V_44 [ V_38 -> V_45 ] ;
if ( V_38 -> V_46 == 2 )
V_40 |= V_5 -> V_44 [ V_38 -> V_45 + 1 ] << 8 ;
if ( V_40 == V_38 -> V_47 )
F_10 ( V_5 , V_38 -> V_48 ) ;
V_5 -> V_49 = V_40 ;
F_11 () ;
F_12 ( & V_5 -> V_50 ) ;
}
static long F_13 ( struct V_51 * V_52 , char T_3 * V_53 ,
long V_54 , T_4 * V_45 )
{
struct V_4 * V_5 = V_52 -> V_3 ;
int V_13 ;
T_2 V_49 ;
if ( V_54 != 1 && V_54 != 4 )
return - V_55 ;
V_13 = F_14 ( V_5 -> V_50 ,
( V_49 = F_15 ( & V_5 -> V_49 , 0 ) ) != 0 ) ;
if ( V_13 == 0 ) {
if ( V_54 == 1 )
V_13 = F_16 ( V_49 , V_53 ) ;
else
V_13 = F_16 ( V_49 , ( T_2 T_3 * ) V_53 ) ;
}
return V_13 < 0 ? V_13 : V_54 ;
}
static unsigned int F_17 ( struct V_51 * V_52 , struct V_56 * V_56 ,
T_5 * V_57 )
{
struct V_4 * V_5 = V_52 -> V_3 ;
F_18 ( V_56 , & V_5 -> V_50 , V_57 ) ;
return V_5 -> V_49 ? V_58 | V_59 : 0 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_51 * V_60 ;
int V_13 , V_61 , V_62 ;
for ( V_62 = 0 ; V_62 < F_20 ( V_63 ) ; ++ V_62 )
if ( V_63 [ V_62 ] . V_64 == V_5 -> V_65 -> V_64 )
break;
if ( V_62 >= F_20 ( V_63 ) )
return 0 ;
V_5 -> V_39 = & V_63 [ V_62 ] ;
V_61 = V_5 -> V_39 -> V_66 ;
F_21 ( & V_5 -> V_50 ) ;
V_13 = F_22 ( V_5 -> V_65 -> V_67 , L_1 , 0 , & V_60 ) ;
if ( V_13 < 0 )
return V_13 ;
snprintf ( V_60 -> V_11 , sizeof( V_60 -> V_11 ) ,
L_2 , V_5 -> V_65 -> V_67 -> V_68 ) ;
V_60 -> V_69 = V_70 ;
V_60 -> V_3 = V_5 ;
V_60 -> V_71 . V_72 = F_13 ;
V_60 -> V_71 . V_73 = F_17 ;
V_60 -> V_74 = 1 ;
V_5 -> V_75 = F_23 ( 0 , V_16 ) ;
if ( ! V_5 -> V_75 )
return - V_17 ;
V_5 -> V_76 = F_24 ( sizeof( * V_5 -> V_76 ) , V_16 ) ;
if ( ! V_5 -> V_76 ) {
F_25 ( V_5 -> V_75 ) ;
V_5 -> V_75 = NULL ;
return - V_17 ;
}
V_5 -> V_76 -> V_77 =
V_78 | V_79 | V_80 ;
V_5 -> V_76 -> V_81 = V_82 ;
V_5 -> V_76 -> V_83 = F_26 ( 0 ) ;
V_5 -> V_76 -> V_84 = F_26 ( 0 ) ;
V_5 -> V_76 -> V_85 = F_26 ( V_61 ) ;
F_27 ( V_5 -> V_75 , V_5 -> V_65 -> V_86 ,
F_28 ( V_5 -> V_65 -> V_86 , 0 ) ,
( V_87 * ) V_5 -> V_76 , V_5 -> V_44 , V_61 ,
F_9 , V_5 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_88 , struct V_89 * V_90 )
{
struct V_4 * V_5 = F_30 ( V_88 ) ;
int V_91 = V_88 -> V_92 ;
V_90 -> V_93 . integer . V_93 [ 0 ] = V_5 -> V_94 [ V_91 ] ;
return 0 ;
}
static int F_31 ( struct V_1 * V_88 , struct V_89 * V_90 )
{
struct V_4 * V_5 = F_30 ( V_88 ) ;
int V_91 = V_88 -> V_92 ;
int V_93 = V_90 -> V_93 . integer . V_93 [ 0 ] ;
int V_13 , V_95 ;
if ( V_93 > 1 )
return - V_55 ;
V_95 = V_93 != V_5 -> V_94 [ V_91 ] ;
F_32 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_5 -> V_65 -> V_97 ) {
V_13 = - V_98 ;
goto V_99;
}
if ( V_5 -> V_65 -> V_64 == F_33 ( 0x041e , 0x3042 ) )
V_13 = F_34 ( V_5 -> V_65 -> V_86 ,
F_35 ( V_5 -> V_65 -> V_86 , 0 ) , 0x24 ,
V_100 | V_101 | V_102 ,
! V_93 , 0 , NULL , 0 ) ;
if ( V_5 -> V_65 -> V_64 == F_33 ( 0x041e , 0x30df ) )
V_13 = F_34 ( V_5 -> V_65 -> V_86 ,
F_35 ( V_5 -> V_65 -> V_86 , 0 ) , 0x24 ,
V_100 | V_101 | V_102 ,
! V_93 , 0 , NULL , 0 ) ;
else
V_13 = F_34 ( V_5 -> V_65 -> V_86 ,
F_35 ( V_5 -> V_65 -> V_86 , 0 ) , 0x24 ,
V_100 | V_101 | V_102 ,
V_93 , V_91 + 2 , NULL , 0 ) ;
V_99:
F_36 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_13 < 0 )
return V_13 ;
V_5 -> V_94 [ V_91 ] = V_93 ;
return V_95 ;
}
static int F_37 ( struct V_4 * V_5 )
{
int V_62 , V_13 ;
for ( V_62 = 0 ; V_62 < F_20 ( V_103 ) ; ++ V_62 ) {
if ( ( V_5 -> V_65 -> V_64 == F_33 ( 0x041e , 0x3042 ) ) && V_62 == 0 )
continue;
if ( ( V_5 -> V_65 -> V_64 == F_33 ( 0x041e , 0x30df ) ) && V_62 == 0 )
continue;
if ( V_62 > 1 &&
( V_5 -> V_65 -> V_64 == F_33 ( 0x041e , 0x3040 ) ||
V_5 -> V_65 -> V_64 == F_33 ( 0x041e , 0x3042 ) ||
V_5 -> V_65 -> V_64 == F_33 ( 0x041e , 0x30df ) ||
V_5 -> V_65 -> V_64 == F_33 ( 0x041e , 0x3048 ) ) )
break;
V_13 = F_38 ( V_5 -> V_65 -> V_67 ,
F_5 ( & V_103 [ V_62 ] , V_5 ) ) ;
if ( V_13 < 0 )
return V_13 ;
}
V_5 -> V_94 [ 1 ] = 1 ;
return 0 ;
}
static void F_39 ( struct V_104 * V_105 ,
struct V_106 * V_107 )
{
static const struct V_108 {
int V_6 ;
const char * V_11 ;
} V_109 [] = {
{ 4 , L_3 } ,
{ 7 , L_4 } ,
{ 19 , L_5 } ,
{ 20 , L_6 } ,
{ - 1 , NULL }
} , V_110 [] = {
{ 4 , L_4 } ,
{ 3 , L_6 } ,
{ 0 , L_7 } ,
{ - 1 , NULL }
} ;
const struct V_108 * V_111 ;
struct V_4 * V_5 = V_105 -> V_3 ;
int V_62 , V_13 ;
V_87 V_53 [ 3 ] ;
F_40 ( V_107 , L_8 , V_5 -> V_65 -> V_67 -> V_68 ) ;
if ( V_5 -> V_65 -> V_64 == F_33 ( 0x041e , 0x3020 ) )
V_111 = V_109 ;
else if ( V_5 -> V_65 -> V_64 == F_33 ( 0x041e , 0x3040 ) ||
V_5 -> V_65 -> V_64 == F_33 ( 0x041e , 0x3048 ) )
V_111 = V_110 ;
else
return;
for ( V_62 = 0 ; V_111 [ V_62 ] . V_11 ; ++ V_62 ) {
F_40 ( V_107 , L_9 , V_111 [ V_62 ] . V_11 ) ;
F_32 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_5 -> V_65 -> V_97 )
V_13 = 0 ;
else
V_13 = F_34 ( V_5 -> V_65 -> V_86 ,
F_28 ( V_5 -> V_65 -> V_86 , 0 ) ,
V_82 , V_78 | V_79 |
V_80 , 0 ,
V_111 [ V_62 ] . V_6 << 8 , V_53 , 3 ) ;
F_36 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_13 == 3 && ( V_53 [ 0 ] == 3 || V_53 [ 0 ] == 6 ) )
F_40 ( V_107 , L_10 , V_53 [ 1 ] , V_53 [ 2 ] ) ;
else
F_40 ( V_107 , L_11 ) ;
}
}
static int F_41 ( struct V_1 * V_88 ,
struct V_89 * V_90 )
{
struct V_4 * V_5 = F_30 ( V_88 ) ;
V_90 -> V_93 . integer . V_93 [ 0 ] = ! ! ( V_5 -> V_112 & 0x02 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_88 ,
struct V_89 * V_90 )
{
struct V_4 * V_5 = F_30 ( V_88 ) ;
V_87 V_113 , V_114 ;
int V_13 , V_95 ;
V_113 = V_5 -> V_112 ;
if ( V_90 -> V_93 . integer . V_93 [ 0 ] )
V_114 = V_113 | 0x02 ;
else
V_114 = V_113 & ~ 0x02 ;
V_95 = V_114 != V_113 ;
F_32 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_5 -> V_65 -> V_97 )
V_13 = - V_98 ;
else
V_13 = F_34 ( V_5 -> V_65 -> V_86 ,
F_35 ( V_5 -> V_65 -> V_86 , 0 ) , 0x08 ,
V_100 | V_101 | V_102 ,
50 , 0 , & V_114 , 1 ) ;
F_36 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_13 < 0 )
return V_13 ;
V_5 -> V_112 = V_114 ;
return V_95 ;
}
static int F_43 ( struct V_4 * V_5 )
{
int V_13 ;
V_13 = F_38 ( V_5 -> V_65 -> V_67 ,
F_5 ( & V_115 , V_5 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_5 -> V_112 = 0x05 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_88 ,
struct V_89 * V_90 )
{
struct V_4 * V_5 = F_30 ( V_88 ) ;
struct V_116 * V_86 = V_5 -> V_65 -> V_86 ;
V_87 V_81 = ( V_88 -> V_92 >> 16 ) & 0xff ;
T_6 V_84 = V_88 -> V_92 & 0xffff ;
V_87 V_117 ;
int V_118 ;
F_32 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_5 -> V_65 -> V_97 )
V_118 = - V_98 ;
else
V_118 = F_45 ( V_86 , F_28 ( V_86 , 0 ) , V_81 ,
V_101 | V_119 | V_78 ,
0 , F_26 ( V_84 ) ,
& V_117 , sizeof( V_117 ) , 1000 ) ;
F_36 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_118 < 0 ) {
F_46 ( V_120
L_12 , V_118 ) ;
return V_118 ;
}
V_90 -> V_93 . integer . V_93 [ 0 ] = V_117 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_88 ,
struct V_89 * V_90 )
{
struct V_4 * V_5 = F_30 ( V_88 ) ;
struct V_116 * V_86 = V_5 -> V_65 -> V_86 ;
V_87 V_81 = ( V_88 -> V_92 >> 16 ) & 0xff ;
T_6 V_84 = V_88 -> V_92 & 0xffff ;
T_6 V_83 = V_90 -> V_93 . integer . V_93 [ 0 ] ;
int V_118 ;
F_32 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_5 -> V_65 -> V_97 )
V_118 = - V_98 ;
else
V_118 = F_45 ( V_86 , F_35 ( V_86 , 0 ) , V_81 ,
V_101 | V_119 | V_100 ,
F_26 ( V_83 ) , F_26 ( V_84 ) ,
NULL , 0 , 1000 ) ;
F_36 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_118 < 0 ) {
F_46 ( V_120
L_13 , V_118 ) ;
return V_118 ;
}
return 0 ;
}
static int F_48 ( struct V_4 * V_5 ,
const struct V_121 * V_122 ,
unsigned int V_54 )
{
int V_62 , V_13 = 0 ;
struct V_121 V_123 = {
. V_69 = V_124 ,
. V_30 = V_125 ,
. V_126 = F_44 ,
. V_127 = F_47 ,
. V_128 = V_129 ,
} ;
for ( V_62 = 0 ; V_62 < V_54 ; V_62 ++ ) {
struct V_1 * V_28 ;
V_123 . V_11 = V_122 [ V_62 ] . V_11 ;
V_123 . V_92 = V_122 [ V_62 ] . V_92 ;
V_28 = F_5 ( & V_123 , V_5 ) ;
V_13 = F_38 ( V_5 -> V_65 -> V_67 , V_28 ) ;
if ( V_13 < 0 )
break;
}
return V_13 ;
}
static int F_49 ( struct V_1 * V_88 ,
struct V_130 * V_131 )
{
static const char * V_132 [ 8 ] = { L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21
} ;
V_131 -> type = V_133 ;
V_131 -> V_54 = 1 ;
V_131 -> V_93 . V_134 . V_135 = 8 ;
if ( V_131 -> V_93 . V_134 . V_136 > 7 )
V_131 -> V_93 . V_134 . V_136 = 7 ;
strcpy ( V_131 -> V_93 . V_134 . V_11 ,
V_132 [ V_131 -> V_93 . V_134 . V_136 ] ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
struct V_137 * V_65 ;
struct V_4 * V_5 ;
struct V_138 * V_139 ;
int V_13 ;
unsigned char V_93 [ 2 ] ;
int V_18 , V_140 ;
const int V_141 = 2 ;
V_93 [ 0 ] = 0x00 ;
V_93 [ 1 ] = 0x00 ;
V_139 = (struct V_138 * )
V_2 -> V_92 ;
if ( V_139 -> V_142 ) {
V_90 -> V_93 . V_134 . V_136 [ 0 ] = V_139 -> V_143 ;
return 0 ;
}
V_5 = (struct V_4 * ) V_139 -> V_5 ;
if ( F_51 ( ! V_5 ) )
return - V_55 ;
V_65 = (struct V_137 * ) V_5 -> V_65 ;
if ( F_51 ( ! V_65 ) )
return - V_55 ;
V_18 = V_139 -> V_144 ;
V_140 = V_139 -> V_140 ;
F_32 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_5 -> V_65 -> V_97 )
V_13 = - V_98 ;
else
V_13 = F_34 ( V_65 -> V_86 ,
F_28 ( V_65 -> V_86 , 0 ) , V_145 ,
V_80 | V_79 | V_78 ,
V_140 << 8 , F_52 ( V_65 ) | ( V_18 << 8 ) ,
V_93 , V_141 ) ;
F_36 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_13 < 0 )
return V_13 ;
V_90 -> V_93 . V_134 . V_136 [ 0 ] = V_93 [ 0 ] ;
V_139 -> V_143 = V_93 [ 0 ] ;
V_139 -> V_142 = 1 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
struct V_137 * V_65 ;
struct V_138 * V_139 ;
struct V_4 * V_5 ;
int V_95 , V_146 , V_13 , V_147 ;
unsigned char V_93 [ 2 ] ;
int V_18 , V_140 ;
const int V_141 = 2 ;
V_95 = 0 ;
V_139 = (struct V_138 * )
V_2 -> V_92 ;
V_146 = V_139 -> V_143 ;
V_147 = V_90 -> V_93 . V_134 . V_136 [ 0 ] ;
V_5 = (struct V_4 * ) V_139 -> V_5 ;
if ( F_51 ( ! V_5 ) )
return - V_55 ;
V_65 = (struct V_137 * ) V_5 -> V_65 ;
if ( F_51 ( ! V_65 ) )
return - V_55 ;
V_18 = V_139 -> V_144 ;
V_140 = V_139 -> V_140 ;
if ( ! V_139 -> V_142 ) {
F_32 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_5 -> V_65 -> V_97 )
V_13 = - V_98 ;
else
V_13 = F_34 ( V_65 -> V_86 ,
F_28 ( V_65 -> V_86 , 0 ) , V_145 ,
V_80 | V_79 | V_78 ,
V_140 << 8 , F_52 ( V_65 ) | ( V_18 << 8 ) ,
V_93 , V_141 ) ;
F_36 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_13 < 0 )
return V_13 ;
V_146 = V_93 [ 0 ] ;
V_139 -> V_143 = V_146 ;
V_139 -> V_142 = 1 ;
}
if ( V_146 != V_147 ) {
V_93 [ 0 ] = V_147 ;
V_93 [ 1 ] = 0 ;
F_32 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_5 -> V_65 -> V_97 )
V_13 = - V_98 ;
else
V_13 = F_34 ( V_65 -> V_86 ,
F_35 ( V_65 -> V_86 , 0 ) , V_148 ,
V_80 | V_79 | V_100 ,
V_140 << 8 , F_52 ( V_65 ) | ( V_18 << 8 ) ,
V_93 , V_141 ) ;
F_36 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_13 < 0 )
return V_13 ;
V_139 -> V_143 = V_147 ;
V_139 -> V_142 = 1 ;
V_95 = 1 ;
}
return V_95 ;
}
static int F_54 ( struct V_4 * V_5 ,
int V_140 , int V_144 )
{
static struct V_121 V_123 = {
. V_69 = V_124 ,
. V_11 = L_22 ,
. V_91 = 0 ,
. V_30 = V_125 ,
. V_128 = F_49 ,
. V_126 = F_50 ,
. V_127 = F_53
} ;
int V_13 ;
struct V_1 * V_2 ;
struct V_138 * V_139 ;
V_139 = F_4 ( sizeof( * V_139 ) , V_16 ) ;
if ( ! V_139 )
return - V_17 ;
V_139 -> V_143 = 0 ;
V_139 -> V_142 = 0 ;
V_139 -> V_5 = V_5 ;
V_139 -> V_144 = V_144 ;
V_139 -> V_140 = V_140 ;
V_123 . V_92 = ( unsigned long ) V_139 ;
V_2 = F_5 ( & V_123 , V_5 -> V_65 ) ;
if ( ! V_2 ) {
F_2 ( V_139 ) ;
return - V_17 ;
}
V_13 = F_38 ( V_5 -> V_65 -> V_67 , V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_55 ( struct V_4 * V_5 )
{
char V_11 [ 64 ] ;
unsigned int V_7 , V_8 ;
int V_149 , V_99 , V_13 ;
const unsigned int V_18 = 5 ;
const int V_9 = V_150 ;
for ( V_99 = 0 ; V_99 < 8 ; V_99 ++ ) {
V_7 = V_99 + 1 ;
for ( V_149 = 0 ; V_149 < 8 ; V_149 ++ ) {
V_8 = 1 << V_149 ;
snprintf ( V_11 , sizeof( V_11 ) ,
L_23 ,
V_149 + 1 , V_99 + 1 ) ;
V_13 = F_7 ( V_5 , V_18 , V_7 ,
V_8 , V_9 , V_11 ,
& V_151 ) ;
if ( V_13 < 0 )
return V_13 ;
}
for ( V_149 = 8 ; V_149 < 16 ; V_149 ++ ) {
V_8 = 1 << V_149 ;
snprintf ( V_11 , sizeof( V_11 ) ,
L_24 ,
V_149 - 7 , V_99 + 1 ) ;
V_13 = F_7 ( V_5 , V_18 , V_7 ,
V_8 , V_9 , V_11 ,
& V_151 ) ;
if ( V_13 < 0 )
return V_13 ;
}
}
return 0 ;
}
static int F_56 ( struct V_4 * V_5 )
{
static const char V_11 [] = L_25 ;
const unsigned int V_18 = 6 ;
const int V_9 = V_152 ;
const unsigned int V_7 = 2 ;
const unsigned int V_8 = 0 ;
return F_7 ( V_5 , V_18 , V_7 , V_8 , V_9 ,
V_11 , V_151 ) ;
}
static int F_57 ( struct V_4 * V_5 )
{
static const char V_11 [] = L_26 ;
const unsigned int V_18 = 6 ;
const int V_9 = V_150 ;
const unsigned int V_7 = 3 ;
const unsigned int V_8 = 0 ;
return F_7 ( V_5 , V_18 , V_7 , V_8 , V_9 ,
V_11 , V_151 ) ;
}
static int F_58 ( struct V_4 * V_5 )
{
static const char V_11 [] = L_27 ;
const unsigned int V_18 = 6 ;
const int V_9 = V_152 ;
const unsigned int V_7 = 4 ;
const unsigned int V_8 = 0 ;
return F_7 ( V_5 , V_18 , V_7 , V_8 , V_9 ,
V_11 , NULL ) ;
}
static int F_59 ( struct V_4 * V_5 )
{
unsigned int V_8 ;
int V_13 , V_153 ;
char V_11 [ 48 ] ;
const unsigned int V_18 = 7 ;
const int V_9 = V_150 ;
const unsigned int V_7 = 7 ;
for ( V_153 = 0 ; V_153 < 4 ; ++ V_153 ) {
V_8 = 1 << V_153 ;
snprintf ( V_11 , sizeof( V_11 ) ,
L_28 , V_153 + 1 ) ;
V_13 = F_7 ( V_5 , V_18 , V_7 ,
V_8 , V_9 , V_11 ,
V_151 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_60 ( struct V_4 * V_5 )
{
unsigned int V_8 ;
int V_13 , V_153 ;
char V_11 [ 48 ] ;
const unsigned int V_18 = 5 ;
const int V_9 = V_150 ;
const unsigned int V_7 = 9 ;
for ( V_153 = 0 ; V_153 < 8 ; ++ V_153 ) {
V_8 = 1 << V_153 ;
snprintf ( V_11 , sizeof( V_11 ) ,
L_29 , V_153 + 1 ) ;
V_13 = F_7 ( V_5 , V_18 , V_7 , V_8 ,
V_9 , V_11 ,
V_151 ) ;
if ( V_13 < 0 )
return V_13 ;
}
for ( V_153 = 8 ; V_153 < 16 ; ++ V_153 ) {
V_8 = 1 << V_153 ;
snprintf ( V_11 , sizeof( V_11 ) ,
L_30 , V_153 - 7 ) ;
V_13 = F_7 ( V_5 , V_18 , V_7 , V_8 ,
V_9 , V_11 ,
V_151 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_61 ( struct V_4 * V_5 )
{
int V_13 ;
V_13 = F_55 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_54 ( V_5 , 1 , 6 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_56 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_57 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_58 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_59 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_60 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
void F_62 ( struct V_137 * V_65 ,
unsigned char V_154 )
{
struct V_4 * V_5 ;
struct V_14 * V_15 ;
int V_6 = 12 ;
F_63 (mixer, &chip->mixer_list, list) {
V_15 = V_5 -> V_155 [ V_6 ] ;
if ( V_15 ) {
F_64 ( V_15 , V_148 ,
V_15 -> V_7 << 8 ,
V_154 ) ;
F_10 ( V_5 , V_6 ) ;
}
break;
}
}
static int F_65 ( struct V_4 * V_5 )
{
char V_11 [ 64 ] ;
unsigned int V_8 , V_45 ;
int V_99 , V_156 , V_13 ;
const unsigned int V_18 = 0x40 ;
const int V_9 = V_150 ;
const int V_7 = 1 ;
for ( V_156 = 0 ; V_156 < 10 ; V_156 ++ ) {
for ( V_99 = 0 ; V_99 < 6 ; V_99 ++ ) {
if ( V_156 < 6 ) {
snprintf ( V_11 , sizeof( V_11 ) ,
L_31 ,
V_156 + 1 , V_99 + 1 ) ;
} else {
snprintf ( V_11 , sizeof( V_11 ) ,
L_32 ,
V_156 - 5 , V_99 + 1 ) ;
}
V_8 = ( V_99 == 0 ) ? 0 : 1 << ( V_99 - 1 ) ;
V_45 = V_156 * 6 ;
V_13 = F_3 ( V_5 , V_18 , V_7 ,
V_8 , V_9 , V_45 , V_11 ,
& V_151 ) ;
if ( V_13 < 0 )
return V_13 ;
}
}
return 0 ;
}
static int F_66 ( struct V_4 * V_5 )
{
static const char V_11 [] = L_25 ;
const unsigned int V_18 = 0x43 ;
const int V_9 = V_152 ;
const unsigned int V_7 = 3 ;
const unsigned int V_8 = 0 ;
return F_7 ( V_5 , V_18 , V_7 , V_8 , V_9 ,
V_11 , V_151 ) ;
}
static int F_67 ( struct V_4 * V_5 )
{
static const char V_11 [] = L_26 ;
const unsigned int V_18 = 0x43 ;
const int V_9 = V_150 ;
const unsigned int V_7 = 4 ;
const unsigned int V_8 = 0 ;
return F_7 ( V_5 , V_18 , V_7 , V_8 , V_9 ,
V_11 , V_151 ) ;
}
static int F_68 ( struct V_4 * V_5 )
{
static const char V_11 [] = L_27 ;
const unsigned int V_18 = 0x43 ;
const int V_9 = V_152 ;
const unsigned int V_7 = 5 ;
const unsigned int V_8 = 0 ;
return F_7 ( V_5 , V_18 , V_7 , V_8 , V_9 ,
V_11 , NULL ) ;
}
static int F_69 ( struct V_4 * V_5 )
{
char V_11 [ 64 ] ;
unsigned int V_8 ;
int V_156 , V_13 ;
const unsigned int V_18 = 0x42 ;
const int V_9 = V_150 ;
const int V_7 = 1 ;
for ( V_156 = 0 ; V_156 < 10 ; V_156 ++ ) {
if ( V_156 < 6 ) {
snprintf ( V_11 , sizeof( V_11 ) ,
L_33 ,
V_156 + 1 ) ;
} else {
snprintf ( V_11 , sizeof( V_11 ) ,
L_34 ,
V_156 - 5 ) ;
}
V_8 = ( V_156 == 0 ) ? 0 : 1 << ( V_156 - 1 ) ;
V_13 = F_7 ( V_5 , V_18 , V_7 ,
V_8 , V_9 , V_11 ,
& V_151 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_70 ( struct V_4 * V_5 )
{
char V_11 [ 64 ] ;
unsigned int V_8 ;
int V_156 , V_13 ;
const unsigned int V_18 = 0x40 ;
const int V_9 = V_150 ;
const int V_7 = 1 ;
const int V_157 [ 6 ] = { 0 , 7 , 2 , 9 , 4 , 0xb } ;
const unsigned int V_45 = 0x3c ;
for ( V_156 = 0 ; V_156 < 6 ; V_156 ++ ) {
snprintf ( V_11 , sizeof( V_11 ) ,
L_35 ,
V_156 + 1 ) ;
V_8 = ( V_157 [ V_156 ] == 0 ) ? 0 : 1 << ( V_157 [ V_156 ] - 1 ) ;
V_13 = F_3 ( V_5 , V_18 , V_7 ,
V_8 , V_9 , V_45 , V_11 ,
& V_151 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_71 ( struct V_4 * V_5 )
{
int V_13 ;
V_13 = F_65 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_69 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_70 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_54 ( V_5 , 2 , 0x43 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_66 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_67 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_68 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
int F_72 ( struct V_4 * V_5 )
{
int V_13 = 0 ;
struct V_104 * V_105 ;
if ( ( V_13 = F_19 ( V_5 ) ) < 0 )
return V_13 ;
switch ( V_5 -> V_65 -> V_64 ) {
case F_33 ( 0x041e , 0x3020 ) :
case F_33 ( 0x041e , 0x3040 ) :
case F_33 ( 0x041e , 0x3042 ) :
case F_33 ( 0x041e , 0x30df ) :
case F_33 ( 0x041e , 0x3048 ) :
V_13 = F_37 ( V_5 ) ;
if ( V_13 < 0 )
break;
if ( ! F_73 ( V_5 -> V_65 -> V_67 , L_36 , & V_105 ) )
F_74 ( V_105 , V_5 ,
F_39 ) ;
break;
case F_33 ( 0x0763 , 0x2030 ) :
V_13 = F_71 ( V_5 ) ;
break;
case F_33 ( 0x0763 , 0x2080 ) :
case F_33 ( 0x0763 , 0x2081 ) :
V_13 = F_61 ( V_5 ) ;
break;
case F_33 ( 0x0b05 , 0x1739 ) :
case F_33 ( 0x0b05 , 0x1743 ) :
case F_33 ( 0x0b05 , 0x17a0 ) :
V_13 = F_43 ( V_5 ) ;
break;
case F_33 ( 0x17cc , 0x1011 ) :
V_13 = F_48 ( V_5 ,
V_158 ,
F_20 ( V_158 ) ) ;
break;
case F_33 ( 0x17cc , 0x1021 ) :
V_13 = F_48 ( V_5 ,
V_159 ,
F_20 ( V_159 ) ) ;
break;
case F_33 ( 0x200c , 0x1018 ) :
V_13 = F_8 ( V_5 , V_160 ) ;
break;
}
return V_13 ;
}
void F_75 ( struct V_4 * V_5 ,
int V_6 )
{
if ( ! V_5 -> V_39 )
return;
switch ( V_6 ) {
case 0 :
V_5 -> V_75 -> V_86 = V_5 -> V_65 -> V_86 ;
F_76 ( V_5 -> V_75 , V_161 ) ;
break;
case 4 :
case 7 :
case 19 :
case 20 :
break;
case 3 :
if ( V_5 -> V_65 -> V_64 == F_33 ( 0x041e , 0x3040 ) ||
V_5 -> V_65 -> V_64 == F_33 ( 0x041e , 0x3048 ) )
F_10 ( V_5 , V_5 -> V_39 -> V_48 ) ;
break;
default:
F_77 ( V_162 L_37 , V_6 ) ;
break;
}
}
