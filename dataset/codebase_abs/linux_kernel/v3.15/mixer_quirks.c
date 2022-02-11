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
struct V_112 * V_113 )
{
static const char * V_114 [ 2 ] = { L_12 ,
L_13
} ;
V_113 -> type = V_115 ;
V_113 -> V_54 = 1 ;
V_113 -> V_93 . V_116 . V_117 = 2 ;
if ( V_113 -> V_93 . V_116 . V_118 > 1 )
V_113 -> V_93 . V_116 . V_118 = 1 ;
strcpy ( V_113 -> V_93 . V_116 . V_11 ,
V_114 [ V_113 -> V_93 . V_116 . V_118 ] ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_88 ,
struct V_89 * V_90 )
{
V_90 -> V_93 . V_116 . V_118 [ 0 ] = V_88 -> V_92 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_88 ,
struct V_89 * V_90 )
{
struct V_4 * V_5 = F_30 ( V_88 ) ;
unsigned int V_93 = V_90 -> V_93 . V_116 . V_118 [ 0 ] ;
int V_13 , V_95 ;
unsigned char V_53 [ 2 ] ;
if ( V_93 > 1 )
return - V_55 ;
V_53 [ 0 ] = 0x01 ;
V_53 [ 1 ] = V_93 ? 0x02 : 0x01 ;
V_95 = V_93 != V_88 -> V_92 ;
F_32 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_5 -> V_65 -> V_97 ) {
V_13 = - V_98 ;
goto V_99;
}
V_13 = F_34 ( V_5 -> V_65 -> V_86 ,
F_35 ( V_5 -> V_65 -> V_86 , 0 ) , V_119 ,
V_80 | V_79 | V_100 ,
0x0400 , 0x0e00 , V_53 , 2 ) ;
V_99:
F_36 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_13 < 0 )
return V_13 ;
V_88 -> V_92 = V_93 ;
return V_95 ;
}
static int F_44 ( struct V_4 * V_5 )
{
int V_62 , V_13 ;
for ( V_62 = 0 ; V_62 < F_20 ( V_120 ) ; ++ V_62 ) {
V_13 = F_38 ( V_5 -> V_65 -> V_67 ,
F_5 ( & V_120 [ V_62 ] , V_5 ) ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_88 ,
struct V_89 * V_90 )
{
struct V_4 * V_5 = F_30 ( V_88 ) ;
V_90 -> V_93 . integer . V_93 [ 0 ] = ! ! ( V_5 -> V_121 & 0x02 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_88 ,
struct V_89 * V_90 )
{
struct V_4 * V_5 = F_30 ( V_88 ) ;
V_87 V_122 , V_123 ;
int V_13 , V_95 ;
V_122 = V_5 -> V_121 ;
if ( V_90 -> V_93 . integer . V_93 [ 0 ] )
V_123 = V_122 | 0x02 ;
else
V_123 = V_122 & ~ 0x02 ;
V_95 = V_123 != V_122 ;
F_32 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_5 -> V_65 -> V_97 )
V_13 = - V_98 ;
else
V_13 = F_34 ( V_5 -> V_65 -> V_86 ,
F_35 ( V_5 -> V_65 -> V_86 , 0 ) , 0x08 ,
V_100 | V_101 | V_102 ,
50 , 0 , & V_123 , 1 ) ;
F_36 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_13 < 0 )
return V_13 ;
V_5 -> V_121 = V_123 ;
return V_95 ;
}
static int F_47 ( struct V_4 * V_5 )
{
int V_13 ;
V_13 = F_38 ( V_5 -> V_65 -> V_67 ,
F_5 ( & V_124 , V_5 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_5 -> V_121 = 0x05 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_88 ,
struct V_89 * V_90 )
{
struct V_4 * V_5 = F_30 ( V_88 ) ;
struct V_125 * V_86 = V_5 -> V_65 -> V_86 ;
V_87 V_81 = ( V_88 -> V_92 >> 16 ) & 0xff ;
T_6 V_84 = V_88 -> V_92 & 0xffff ;
V_87 V_126 ;
int V_127 ;
F_32 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_5 -> V_65 -> V_97 )
V_127 = - V_98 ;
else
V_127 = F_49 ( V_86 , F_28 ( V_86 , 0 ) , V_81 ,
V_101 | V_128 | V_78 ,
0 , V_84 ,
& V_126 , sizeof( V_126 ) , 1000 ) ;
F_36 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_127 < 0 ) {
F_50 ( & V_86 -> V_86 ,
L_14 , V_127 ) ;
return V_127 ;
}
V_90 -> V_93 . integer . V_93 [ 0 ] = V_126 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_88 ,
struct V_89 * V_90 )
{
struct V_4 * V_5 = F_30 ( V_88 ) ;
struct V_125 * V_86 = V_5 -> V_65 -> V_86 ;
V_87 V_81 = ( V_88 -> V_92 >> 16 ) & 0xff ;
T_6 V_84 = V_88 -> V_92 & 0xffff ;
T_6 V_83 = V_90 -> V_93 . integer . V_93 [ 0 ] ;
int V_127 ;
F_32 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_5 -> V_65 -> V_97 )
V_127 = - V_98 ;
else
V_127 = F_49 ( V_86 , F_35 ( V_86 , 0 ) , V_81 ,
V_101 | V_128 | V_100 ,
V_83 , V_84 ,
NULL , 0 , 1000 ) ;
F_36 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_127 < 0 ) {
F_50 ( & V_86 -> V_86 ,
L_15 , V_127 ) ;
return V_127 ;
}
return 0 ;
}
static int F_52 ( struct V_4 * V_5 ,
const struct V_129 * V_130 ,
unsigned int V_54 )
{
int V_62 , V_13 = 0 ;
struct V_129 V_131 = {
. V_69 = V_132 ,
. V_30 = V_133 ,
. V_134 = F_48 ,
. V_135 = F_51 ,
. V_136 = V_137 ,
} ;
for ( V_62 = 0 ; V_62 < V_54 ; V_62 ++ ) {
struct V_1 * V_28 ;
V_131 . V_11 = V_130 [ V_62 ] . V_11 ;
V_131 . V_92 = V_130 [ V_62 ] . V_92 ;
V_28 = F_5 ( & V_131 , V_5 ) ;
V_13 = F_38 ( V_5 -> V_65 -> V_67 , V_28 ) ;
if ( V_13 < 0 )
break;
}
return V_13 ;
}
static int F_53 ( struct V_1 * V_88 ,
struct V_112 * V_113 )
{
static const char * V_114 [ 8 ] = { L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
L_22 ,
L_23
} ;
V_113 -> type = V_115 ;
V_113 -> V_54 = 1 ;
V_113 -> V_93 . V_116 . V_117 = 8 ;
if ( V_113 -> V_93 . V_116 . V_118 > 7 )
V_113 -> V_93 . V_116 . V_118 = 7 ;
strcpy ( V_113 -> V_93 . V_116 . V_11 ,
V_114 [ V_113 -> V_93 . V_116 . V_118 ] ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
struct V_138 * V_65 ;
struct V_4 * V_5 ;
struct V_139 * V_140 ;
int V_13 ;
unsigned char V_93 [ 2 ] ;
int V_18 , V_141 ;
const int V_142 = 2 ;
V_93 [ 0 ] = 0x00 ;
V_93 [ 1 ] = 0x00 ;
V_140 = (struct V_139 * )
V_2 -> V_92 ;
if ( V_140 -> V_143 ) {
V_90 -> V_93 . V_116 . V_118 [ 0 ] = V_140 -> V_144 ;
return 0 ;
}
V_5 = (struct V_4 * ) V_140 -> V_5 ;
if ( F_55 ( ! V_5 ) )
return - V_55 ;
V_65 = (struct V_138 * ) V_5 -> V_65 ;
if ( F_55 ( ! V_65 ) )
return - V_55 ;
V_18 = V_140 -> V_145 ;
V_141 = V_140 -> V_141 ;
F_32 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_5 -> V_65 -> V_97 )
V_13 = - V_98 ;
else
V_13 = F_34 ( V_65 -> V_86 ,
F_28 ( V_65 -> V_86 , 0 ) , V_146 ,
V_80 | V_79 | V_78 ,
V_141 << 8 , F_56 ( V_65 ) | ( V_18 << 8 ) ,
V_93 , V_142 ) ;
F_36 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_13 < 0 )
return V_13 ;
V_90 -> V_93 . V_116 . V_118 [ 0 ] = V_93 [ 0 ] ;
V_140 -> V_144 = V_93 [ 0 ] ;
V_140 -> V_143 = 1 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
struct V_138 * V_65 ;
struct V_139 * V_140 ;
struct V_4 * V_5 ;
int V_95 , V_147 , V_13 , V_148 ;
unsigned char V_93 [ 2 ] ;
int V_18 , V_141 ;
const int V_142 = 2 ;
V_95 = 0 ;
V_140 = (struct V_139 * )
V_2 -> V_92 ;
V_147 = V_140 -> V_144 ;
V_148 = V_90 -> V_93 . V_116 . V_118 [ 0 ] ;
V_5 = (struct V_4 * ) V_140 -> V_5 ;
if ( F_55 ( ! V_5 ) )
return - V_55 ;
V_65 = (struct V_138 * ) V_5 -> V_65 ;
if ( F_55 ( ! V_65 ) )
return - V_55 ;
V_18 = V_140 -> V_145 ;
V_141 = V_140 -> V_141 ;
if ( ! V_140 -> V_143 ) {
F_32 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_5 -> V_65 -> V_97 )
V_13 = - V_98 ;
else
V_13 = F_34 ( V_65 -> V_86 ,
F_28 ( V_65 -> V_86 , 0 ) , V_146 ,
V_80 | V_79 | V_78 ,
V_141 << 8 , F_56 ( V_65 ) | ( V_18 << 8 ) ,
V_93 , V_142 ) ;
F_36 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_13 < 0 )
return V_13 ;
V_147 = V_93 [ 0 ] ;
V_140 -> V_144 = V_147 ;
V_140 -> V_143 = 1 ;
}
if ( V_147 != V_148 ) {
V_93 [ 0 ] = V_148 ;
V_93 [ 1 ] = 0 ;
F_32 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_5 -> V_65 -> V_97 )
V_13 = - V_98 ;
else
V_13 = F_34 ( V_65 -> V_86 ,
F_35 ( V_65 -> V_86 , 0 ) , V_119 ,
V_80 | V_79 | V_100 ,
V_141 << 8 , F_56 ( V_65 ) | ( V_18 << 8 ) ,
V_93 , V_142 ) ;
F_36 ( & V_5 -> V_65 -> V_96 ) ;
if ( V_13 < 0 )
return V_13 ;
V_140 -> V_144 = V_148 ;
V_140 -> V_143 = 1 ;
V_95 = 1 ;
}
return V_95 ;
}
static int F_58 ( struct V_4 * V_5 ,
int V_141 , int V_145 )
{
static struct V_129 V_131 = {
. V_69 = V_132 ,
. V_11 = L_24 ,
. V_91 = 0 ,
. V_30 = V_133 ,
. V_136 = F_53 ,
. V_134 = F_54 ,
. V_135 = F_57
} ;
int V_13 ;
struct V_1 * V_2 ;
struct V_139 * V_140 ;
V_140 = F_4 ( sizeof( * V_140 ) , V_16 ) ;
if ( ! V_140 )
return - V_17 ;
V_140 -> V_144 = 0 ;
V_140 -> V_143 = 0 ;
V_140 -> V_5 = V_5 ;
V_140 -> V_145 = V_145 ;
V_140 -> V_141 = V_141 ;
V_131 . V_92 = ( unsigned long ) V_140 ;
V_2 = F_5 ( & V_131 , V_5 -> V_65 ) ;
if ( ! V_2 ) {
F_2 ( V_140 ) ;
return - V_17 ;
}
V_13 = F_38 ( V_5 -> V_65 -> V_67 , V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_59 ( struct V_4 * V_5 )
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
L_25 ,
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
L_26 ,
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
static int F_60 ( struct V_4 * V_5 )
{
static const char V_11 [] = L_27 ;
const unsigned int V_18 = 6 ;
const int V_9 = V_152 ;
const unsigned int V_7 = 2 ;
const unsigned int V_8 = 0 ;
return F_7 ( V_5 , V_18 , V_7 , V_8 , V_9 ,
V_11 , V_151 ) ;
}
static int F_61 ( struct V_4 * V_5 )
{
static const char V_11 [] = L_28 ;
const unsigned int V_18 = 6 ;
const int V_9 = V_150 ;
const unsigned int V_7 = 3 ;
const unsigned int V_8 = 0 ;
return F_7 ( V_5 , V_18 , V_7 , V_8 , V_9 ,
V_11 , V_151 ) ;
}
static int F_62 ( struct V_4 * V_5 )
{
static const char V_11 [] = L_29 ;
const unsigned int V_18 = 6 ;
const int V_9 = V_152 ;
const unsigned int V_7 = 4 ;
const unsigned int V_8 = 0 ;
return F_7 ( V_5 , V_18 , V_7 , V_8 , V_9 ,
V_11 , NULL ) ;
}
static int F_63 ( struct V_4 * V_5 )
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
L_30 , V_153 + 1 ) ;
V_13 = F_7 ( V_5 , V_18 , V_7 ,
V_8 , V_9 , V_11 ,
V_151 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_64 ( struct V_4 * V_5 )
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
L_31 , V_153 + 1 ) ;
V_13 = F_7 ( V_5 , V_18 , V_7 , V_8 ,
V_9 , V_11 ,
V_151 ) ;
if ( V_13 < 0 )
return V_13 ;
}
for ( V_153 = 8 ; V_153 < 16 ; ++ V_153 ) {
V_8 = 1 << V_153 ;
snprintf ( V_11 , sizeof( V_11 ) ,
L_32 , V_153 - 7 ) ;
V_13 = F_7 ( V_5 , V_18 , V_7 , V_8 ,
V_9 , V_11 ,
V_151 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_65 ( struct V_4 * V_5 )
{
int V_13 ;
V_13 = F_59 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_58 ( V_5 , 1 , 6 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_60 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_61 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_62 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_63 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_64 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
void F_66 ( struct V_138 * V_65 ,
unsigned char V_154 )
{
struct V_4 * V_5 ;
struct V_14 * V_15 ;
int V_6 = 12 ;
F_67 (mixer, &chip->mixer_list, list) {
V_15 = V_5 -> V_155 [ V_6 ] ;
if ( V_15 ) {
F_68 ( V_15 , V_119 ,
V_15 -> V_7 << 8 ,
V_154 ) ;
F_10 ( V_5 , V_6 ) ;
}
break;
}
}
static int F_69 ( struct V_4 * V_5 )
{
char V_11 [ 64 ] ;
unsigned int V_8 , V_45 ;
int V_99 , V_156 , V_13 ;
int V_157 = 0 ;
int V_158 = 0 ;
const unsigned int V_18 = 0x40 ;
const int V_9 = V_150 ;
const int V_7 = 1 ;
switch ( V_5 -> V_65 -> V_64 ) {
case F_33 ( 0x0763 , 0x2030 ) :
V_157 = 6 ;
V_158 = 4 ;
break;
case F_33 ( 0x0763 , 0x2031 ) :
V_157 = 8 ;
V_158 = 6 ;
break;
}
for ( V_156 = 0 ; V_156 < V_157 + V_158 ; V_156 ++ ) {
for ( V_99 = 0 ; V_99 < V_157 ; V_99 ++ ) {
if ( V_156 < V_157 ) {
snprintf ( V_11 , sizeof( V_11 ) ,
L_33 ,
V_156 + 1 , V_99 + 1 ) ;
} else {
snprintf ( V_11 , sizeof( V_11 ) ,
L_34 ,
V_156 - V_157 + 1 , V_99 + 1 ) ;
}
V_8 = ( V_99 == 0 ) ? 0 : 1 << ( V_99 - 1 ) ;
V_45 = V_156 * V_157 ;
V_13 = F_3 ( V_5 , V_18 , V_7 ,
V_8 , V_9 , V_45 , V_11 ,
& V_151 ) ;
if ( V_13 < 0 )
return V_13 ;
}
}
return 0 ;
}
static int F_70 ( struct V_4 * V_5 )
{
static const char V_11 [] = L_27 ;
const unsigned int V_18 = 0x43 ;
const int V_9 = V_152 ;
const unsigned int V_7 = 3 ;
const unsigned int V_8 = 0 ;
return F_7 ( V_5 , V_18 , V_7 , V_8 , V_9 ,
V_11 , V_151 ) ;
}
static int F_71 ( struct V_4 * V_5 )
{
static const char V_11 [] = L_28 ;
const unsigned int V_18 = 0x43 ;
const int V_9 = V_150 ;
const unsigned int V_7 = 4 ;
const unsigned int V_8 = 0 ;
return F_7 ( V_5 , V_18 , V_7 , V_8 , V_9 ,
V_11 , V_151 ) ;
}
static int F_72 ( struct V_4 * V_5 )
{
static const char V_11 [] = L_29 ;
const unsigned int V_18 = 0x43 ;
const int V_9 = V_152 ;
const unsigned int V_7 = 5 ;
const unsigned int V_8 = 0 ;
return F_7 ( V_5 , V_18 , V_7 , V_8 , V_9 ,
V_11 , NULL ) ;
}
static int F_73 ( struct V_4 * V_5 )
{
char V_11 [ 64 ] ;
unsigned int V_8 ;
int V_156 , V_13 ;
int V_157 = 0 ;
int V_158 = 0 ;
const unsigned int V_18 = 0x42 ;
const int V_9 = V_150 ;
const int V_7 = 1 ;
switch ( V_5 -> V_65 -> V_64 ) {
case F_33 ( 0x0763 , 0x2030 ) :
V_157 = 6 ;
V_158 = 4 ;
break;
case F_33 ( 0x0763 , 0x2031 ) :
V_157 = 8 ;
V_158 = 6 ;
break;
}
for ( V_156 = 0 ; V_156 < V_157 + V_158 ; V_156 ++ ) {
if ( V_156 < V_157 ) {
snprintf ( V_11 , sizeof( V_11 ) ,
L_35 ,
V_156 + 1 ) ;
} else {
snprintf ( V_11 , sizeof( V_11 ) ,
L_36 ,
V_156 - V_157 + 1 ) ;
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
static int F_74 ( struct V_4 * V_5 )
{
char V_11 [ 64 ] ;
unsigned int V_8 ;
int V_156 , V_13 ;
int V_157 = 0 ;
int V_45 = 0 ;
const unsigned int V_18 = 0x40 ;
const int V_9 = V_150 ;
const int V_7 = 1 ;
switch ( V_5 -> V_65 -> V_64 ) {
case F_33 ( 0x0763 , 0x2030 ) :
V_157 = 6 ;
V_45 = 0x3c ;
break;
case F_33 ( 0x0763 , 0x2031 ) :
V_157 = 8 ;
V_45 = 0x70 ;
break;
}
for ( V_156 = 0 ; V_156 < V_157 ; V_156 ++ ) {
snprintf ( V_11 , sizeof( V_11 ) ,
L_37 ,
V_156 + 1 ) ;
V_8 = ( V_156 == 0 ) ? 0 :
1 << ( V_156 + ( V_156 % 2 ) * V_157 - 1 ) ;
V_13 = F_3 ( V_5 , V_18 , V_7 ,
V_8 , V_9 , V_45 , V_11 ,
& V_151 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_75 ( struct V_4 * V_5 )
{
int V_13 ;
V_13 = F_69 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_73 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_74 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_58 ( V_5 , 2 , 0x43 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_70 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_71 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_72 ( V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_76 ( struct V_1 * V_88 ,
struct V_112 * V_113 )
{
V_113 -> type = V_159 ;
V_113 -> V_54 = 1 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_88 ,
struct V_89 * V_90 )
{
struct V_4 * V_5 = F_30 ( V_88 ) ;
int V_13 ;
struct V_160 * V_69 ;
struct V_161 * V_162 ;
unsigned int V_163 ;
unsigned char V_164 [ 3 ] ;
int V_165 ;
V_90 -> V_93 . V_166 . V_41 [ 0 ] = V_88 -> V_92 & 0xff ;
V_90 -> V_93 . V_166 . V_41 [ 1 ] = ( V_88 -> V_92 >> 8 ) & 0xff ;
V_90 -> V_93 . V_166 . V_41 [ 2 ] = 0x00 ;
V_69 = F_78 ( V_5 -> V_65 -> V_86 , 1 ) ;
V_162 = & V_69 -> V_167 [ 1 ] ;
V_163 = F_79 ( V_162 , 0 ) -> V_168 ;
V_13 = F_34 ( V_5 -> V_65 -> V_86 ,
F_28 ( V_5 -> V_65 -> V_86 , 0 ) ,
V_146 ,
V_79 | V_169 | V_78 ,
V_170 << 8 ,
V_163 ,
V_164 ,
sizeof( V_164 ) ) ;
if ( V_13 < 0 )
goto V_171;
V_165 = V_164 [ 0 ] | ( V_164 [ 1 ] << 8 ) | ( V_164 [ 2 ] << 16 ) ;
V_90 -> V_93 . V_166 . V_41 [ 3 ] = ( V_165 == 48000 ) ?
V_172 : V_173 ;
V_13 = 0 ;
V_171:
return V_13 ;
}
static int F_80 ( struct V_1 * V_88 ,
struct V_89 * V_90 )
{
struct V_4 * V_5 = F_30 ( V_88 ) ;
int V_13 ;
V_87 V_174 ;
unsigned long V_175 = V_88 -> V_92 ;
V_174 = ( ( V_90 -> V_93 . V_166 . V_41 [ 1 ] & 0x0f ) << 4 ) |
( V_90 -> V_93 . V_166 . V_41 [ 0 ] & 0x0f ) ;
V_13 = F_34 ( V_5 -> V_65 -> V_86 ,
F_35 ( V_5 -> V_65 -> V_86 , 0 ) ,
V_119 ,
V_100 | V_101 | V_102 ,
V_174 ,
2 ,
NULL ,
0 ) ;
if ( V_13 < 0 )
goto V_171;
V_88 -> V_92 &= 0xfffff0f0 ;
V_88 -> V_92 |= ( V_90 -> V_93 . V_166 . V_41 [ 1 ] & 0x0f ) << 8 ;
V_88 -> V_92 |= ( V_90 -> V_93 . V_166 . V_41 [ 0 ] & 0x0f ) ;
V_174 = ( V_90 -> V_93 . V_166 . V_41 [ 0 ] & V_176 ) ?
0xa0 : 0x20 ;
V_174 |= ( V_90 -> V_93 . V_166 . V_41 [ 1 ] >> 4 ) & 0x0f ;
V_13 = F_34 ( V_5 -> V_65 -> V_86 ,
F_35 ( V_5 -> V_65 -> V_86 , 0 ) ,
V_119 ,
V_100 | V_101 | V_102 ,
V_174 ,
3 ,
NULL ,
0 ) ;
if ( V_13 < 0 )
goto V_171;
V_88 -> V_92 &= 0xffff0fff ;
V_88 -> V_92 |= ( V_90 -> V_93 . V_166 . V_41 [ 1 ] & 0xf0 ) << 8 ;
V_13 = ( V_175 != V_88 -> V_92 ) ;
V_171:
return V_13 ;
}
static int F_81 ( struct V_1 * V_88 ,
struct V_89 * V_90 )
{
V_90 -> V_93 . V_166 . V_41 [ 0 ] = 0x0f ;
V_90 -> V_93 . V_166 . V_41 [ 1 ] = 0xff ;
V_90 -> V_93 . V_166 . V_41 [ 2 ] = 0x00 ;
V_90 -> V_93 . V_166 . V_41 [ 3 ] = 0x00 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_88 ,
struct V_89 * V_90 )
{
V_90 -> V_93 . integer . V_93 [ 0 ] = ! ( V_88 -> V_92 & 0x02 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_88 ,
struct V_89 * V_90 )
{
struct V_4 * V_5 = F_30 ( V_88 ) ;
int V_13 ;
V_87 V_174 = V_90 -> V_93 . integer . V_93 [ 0 ] ? 0x28 : 0x2a ;
V_13 = F_34 ( V_5 -> V_65 -> V_86 ,
F_35 ( V_5 -> V_65 -> V_86 , 0 ) ,
V_119 ,
V_100 | V_101 | V_102 ,
V_174 ,
9 ,
NULL ,
0 ) ;
if ( ! V_13 ) {
V_13 = ( V_174 != ( V_88 -> V_92 & 0x0ff ) ) ;
if ( V_13 )
V_88 -> V_92 = V_174 ;
}
return V_13 ;
}
static int F_84 ( struct V_4 * V_5 )
{
int V_13 , V_62 ;
for ( V_62 = 0 ; V_62 < F_20 ( V_177 ) ; ++ V_62 ) {
V_13 = F_38 ( V_5 -> V_65 -> V_67 ,
F_5 ( & V_177 [ V_62 ] , V_5 ) ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
int F_85 ( struct V_4 * V_5 )
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
if ( ! F_86 ( V_5 -> V_65 -> V_67 , L_38 , & V_105 ) )
F_87 ( V_105 , V_5 ,
F_39 ) ;
break;
case F_33 ( 0x041e , 0x3f19 ) :
V_13 = F_44 ( V_5 ) ;
if ( V_13 < 0 )
break;
break;
case F_33 ( 0x0763 , 0x2030 ) :
case F_33 ( 0x0763 , 0x2031 ) :
V_13 = F_75 ( V_5 ) ;
break;
case F_33 ( 0x0763 , 0x2080 ) :
case F_33 ( 0x0763 , 0x2081 ) :
V_13 = F_65 ( V_5 ) ;
break;
case F_33 ( 0x0b05 , 0x1739 ) :
case F_33 ( 0x0b05 , 0x1743 ) :
case F_33 ( 0x0b05 , 0x17a0 ) :
V_13 = F_47 ( V_5 ) ;
break;
case F_33 ( 0x0d8c , 0x0103 ) :
V_13 = F_84 ( V_5 ) ;
break;
case F_33 ( 0x17cc , 0x1011 ) :
V_13 = F_52 ( V_5 ,
V_178 ,
F_20 ( V_178 ) ) ;
break;
case F_33 ( 0x17cc , 0x1021 ) :
V_13 = F_52 ( V_5 ,
V_179 ,
F_20 ( V_179 ) ) ;
break;
case F_33 ( 0x200c , 0x1018 ) :
V_13 = F_8 ( V_5 , V_180 ) ;
break;
}
return V_13 ;
}
void F_88 ( struct V_4 * V_5 ,
int V_6 )
{
if ( ! V_5 -> V_39 )
return;
switch ( V_6 ) {
case 0 :
V_5 -> V_75 -> V_86 = V_5 -> V_65 -> V_86 ;
F_89 ( V_5 -> V_75 , V_181 ) ;
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
F_90 ( V_5 -> V_65 , L_39 , V_6 ) ;
break;
}
}
