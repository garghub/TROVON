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
F_31 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_5 -> V_64 -> V_96 ) {
V_12 = - V_97 ;
goto V_98;
}
if ( V_5 -> V_64 -> V_63 == F_32 ( 0x041e , 0x3042 ) )
V_12 = F_33 ( V_5 -> V_64 -> V_85 ,
F_34 ( V_5 -> V_64 -> V_85 , 0 ) , 0x24 ,
V_99 | V_100 | V_101 ,
! V_92 , 0 , NULL , 0 ) ;
if ( V_5 -> V_64 -> V_63 == F_32 ( 0x041e , 0x30df ) )
V_12 = F_33 ( V_5 -> V_64 -> V_85 ,
F_34 ( V_5 -> V_64 -> V_85 , 0 ) , 0x24 ,
V_99 | V_100 | V_101 ,
! V_92 , 0 , NULL , 0 ) ;
else
V_12 = F_33 ( V_5 -> V_64 -> V_85 ,
F_34 ( V_5 -> V_64 -> V_85 , 0 ) , 0x24 ,
V_99 | V_100 | V_101 ,
V_92 , V_90 + 2 , NULL , 0 ) ;
V_98:
F_35 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_12 < 0 )
return V_12 ;
V_5 -> V_93 [ V_90 ] = V_92 ;
return V_94 ;
}
static int F_36 ( struct V_4 * V_5 )
{
int V_61 , V_12 ;
for ( V_61 = 0 ; V_61 < F_19 ( V_102 ) ; ++ V_61 ) {
if ( ( V_5 -> V_64 -> V_63 == F_32 ( 0x041e , 0x3042 ) ) && V_61 == 0 )
continue;
if ( ( V_5 -> V_64 -> V_63 == F_32 ( 0x041e , 0x30df ) ) && V_61 == 0 )
continue;
if ( V_61 > 1 &&
( V_5 -> V_64 -> V_63 == F_32 ( 0x041e , 0x3040 ) ||
V_5 -> V_64 -> V_63 == F_32 ( 0x041e , 0x3042 ) ||
V_5 -> V_64 -> V_63 == F_32 ( 0x041e , 0x30df ) ||
V_5 -> V_64 -> V_63 == F_32 ( 0x041e , 0x3048 ) ) )
break;
V_12 = F_37 ( V_5 -> V_64 -> V_66 ,
F_5 ( & V_102 [ V_61 ] , V_5 ) ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_5 -> V_93 [ 1 ] = 1 ;
return 0 ;
}
static void F_38 ( struct V_103 * V_104 ,
struct V_105 * V_106 )
{
static const struct V_107 {
int V_6 ;
const char * V_10 ;
} V_108 [] = {
{ 4 , L_3 } ,
{ 7 , L_4 } ,
{ 19 , L_5 } ,
{ 20 , L_6 } ,
{ - 1 , NULL }
} , V_109 [] = {
{ 4 , L_4 } ,
{ 3 , L_6 } ,
{ 0 , L_7 } ,
{ - 1 , NULL }
} ;
const struct V_107 * V_110 ;
struct V_4 * V_5 = V_104 -> V_3 ;
int V_61 , V_12 ;
V_86 V_52 [ 3 ] ;
F_39 ( V_106 , L_8 , V_5 -> V_64 -> V_66 -> V_67 ) ;
if ( V_5 -> V_64 -> V_63 == F_32 ( 0x041e , 0x3020 ) )
V_110 = V_108 ;
else if ( V_5 -> V_64 -> V_63 == F_32 ( 0x041e , 0x3040 ) ||
V_5 -> V_64 -> V_63 == F_32 ( 0x041e , 0x3048 ) )
V_110 = V_109 ;
else
return;
for ( V_61 = 0 ; V_110 [ V_61 ] . V_10 ; ++ V_61 ) {
F_39 ( V_106 , L_9 , V_110 [ V_61 ] . V_10 ) ;
F_31 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_5 -> V_64 -> V_96 )
V_12 = 0 ;
else
V_12 = F_33 ( V_5 -> V_64 -> V_85 ,
F_27 ( V_5 -> V_64 -> V_85 , 0 ) ,
V_81 , V_77 | V_78 |
V_79 , 0 ,
V_110 [ V_61 ] . V_6 << 8 , V_52 , 3 ) ;
F_35 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_12 == 3 && ( V_52 [ 0 ] == 3 || V_52 [ 0 ] == 6 ) )
F_39 ( V_106 , L_10 , V_52 [ 1 ] , V_52 [ 2 ] ) ;
else
F_39 ( V_106 , L_11 ) ;
}
}
static int F_40 ( struct V_1 * V_87 ,
struct V_88 * V_89 )
{
struct V_4 * V_5 = F_29 ( V_87 ) ;
V_89 -> V_92 . integer . V_92 [ 0 ] = ! ! ( V_5 -> V_111 & 0x02 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_87 ,
struct V_88 * V_89 )
{
struct V_4 * V_5 = F_29 ( V_87 ) ;
V_86 V_112 , V_113 ;
int V_12 , V_94 ;
V_112 = V_5 -> V_111 ;
if ( V_89 -> V_92 . integer . V_92 [ 0 ] )
V_113 = V_112 | 0x02 ;
else
V_113 = V_112 & ~ 0x02 ;
V_94 = V_113 != V_112 ;
F_31 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_5 -> V_64 -> V_96 )
V_12 = - V_97 ;
else
V_12 = F_33 ( V_5 -> V_64 -> V_85 ,
F_34 ( V_5 -> V_64 -> V_85 , 0 ) , 0x08 ,
V_99 | V_100 | V_101 ,
50 , 0 , & V_113 , 1 ) ;
F_35 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_12 < 0 )
return V_12 ;
V_5 -> V_111 = V_113 ;
return V_94 ;
}
static int F_42 ( struct V_4 * V_5 )
{
int V_12 ;
V_12 = F_37 ( V_5 -> V_64 -> V_66 ,
F_5 ( & V_114 , V_5 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_5 -> V_111 = 0x05 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_87 ,
struct V_88 * V_89 )
{
struct V_4 * V_5 = F_29 ( V_87 ) ;
struct V_115 * V_85 = V_5 -> V_64 -> V_85 ;
V_86 V_80 = ( V_87 -> V_91 >> 16 ) & 0xff ;
T_6 V_83 = V_87 -> V_91 & 0xffff ;
V_86 V_116 ;
int V_117 ;
F_31 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_5 -> V_64 -> V_96 )
V_117 = - V_97 ;
else
V_117 = F_44 ( V_85 , F_27 ( V_85 , 0 ) , V_80 ,
V_100 | V_118 | V_77 ,
0 , F_25 ( V_83 ) ,
& V_116 , sizeof( V_116 ) , 1000 ) ;
F_35 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_117 < 0 ) {
F_45 ( V_119
L_12 , V_117 ) ;
return V_117 ;
}
V_89 -> V_92 . integer . V_92 [ 0 ] = V_116 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_87 ,
struct V_88 * V_89 )
{
struct V_4 * V_5 = F_29 ( V_87 ) ;
struct V_115 * V_85 = V_5 -> V_64 -> V_85 ;
V_86 V_80 = ( V_87 -> V_91 >> 16 ) & 0xff ;
T_6 V_83 = V_87 -> V_91 & 0xffff ;
T_6 V_82 = V_89 -> V_92 . integer . V_92 [ 0 ] ;
int V_117 ;
F_31 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_5 -> V_64 -> V_96 )
V_117 = - V_97 ;
else
V_117 = F_44 ( V_85 , F_34 ( V_85 , 0 ) , V_80 ,
V_100 | V_118 | V_99 ,
F_25 ( V_82 ) , F_25 ( V_83 ) ,
NULL , 0 , 1000 ) ;
F_35 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_117 < 0 ) {
F_45 ( V_119
L_13 , V_117 ) ;
return V_117 ;
}
return 0 ;
}
static int F_47 ( struct V_4 * V_5 ,
const struct V_120 * V_121 ,
unsigned int V_53 )
{
int V_61 , V_12 = 0 ;
struct V_120 V_122 = {
. V_68 = V_123 ,
. V_29 = V_124 ,
. V_125 = F_43 ,
. V_126 = F_46 ,
. V_127 = V_128 ,
} ;
for ( V_61 = 0 ; V_61 < V_53 ; V_61 ++ ) {
struct V_1 * V_27 ;
V_122 . V_10 = V_121 [ V_61 ] . V_10 ;
V_122 . V_91 = V_121 [ V_61 ] . V_91 ;
V_27 = F_5 ( & V_122 , V_5 ) ;
V_12 = F_37 ( V_5 -> V_64 -> V_66 , V_27 ) ;
if ( V_12 < 0 )
break;
}
return V_12 ;
}
static int F_48 ( struct V_1 * V_87 ,
struct V_129 * V_130 )
{
static const char * V_131 [ 8 ] = { L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21
} ;
V_130 -> type = V_132 ;
V_130 -> V_53 = 1 ;
V_130 -> V_92 . V_133 . V_134 = 8 ;
if ( V_130 -> V_92 . V_133 . V_135 > 7 )
V_130 -> V_92 . V_133 . V_135 = 7 ;
strcpy ( V_130 -> V_92 . V_133 . V_10 ,
V_131 [ V_130 -> V_92 . V_133 . V_135 ] ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
struct V_136 * V_64 ;
struct V_4 * V_5 ;
struct V_137 * V_138 ;
int V_12 ;
unsigned char V_92 [ 2 ] ;
const int V_17 = 6 ;
const int V_139 = 1 ;
const int V_140 = 2 ;
V_92 [ 0 ] = 0x00 ;
V_92 [ 1 ] = 0x00 ;
V_138 = (struct V_137 * )
V_2 -> V_91 ;
if ( V_138 -> V_141 ) {
V_89 -> V_92 . V_133 . V_135 [ 0 ] = V_138 -> V_142 ;
return 0 ;
}
V_5 = (struct V_4 * ) V_138 -> V_5 ;
if ( F_50 ( ! V_5 ) )
return - V_54 ;
V_64 = (struct V_136 * ) V_5 -> V_64 ;
if ( F_50 ( ! V_64 ) )
return - V_54 ;
F_31 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_5 -> V_64 -> V_96 )
V_12 = - V_97 ;
else
V_12 = F_33 ( V_64 -> V_85 ,
F_27 ( V_64 -> V_85 , 0 ) , V_143 ,
V_79 | V_78 | V_77 ,
V_139 << 8 , F_51 ( V_64 ) | ( V_17 << 8 ) ,
V_92 , V_140 ) ;
F_35 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_12 < 0 )
return V_12 ;
V_89 -> V_92 . V_133 . V_135 [ 0 ] = V_92 [ 0 ] ;
V_138 -> V_142 = V_92 [ 0 ] ;
V_138 -> V_141 = 1 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
struct V_136 * V_64 ;
struct V_137 * V_138 ;
struct V_4 * V_5 ;
int V_94 , V_144 , V_12 , V_145 ;
unsigned char V_92 [ 2 ] ;
const int V_17 = 6 ;
const int V_139 = 1 ;
const int V_140 = 2 ;
V_94 = 0 ;
V_138 = (struct V_137 * )
V_2 -> V_91 ;
V_144 = V_138 -> V_142 ;
V_145 = V_89 -> V_92 . V_133 . V_135 [ 0 ] ;
V_5 = (struct V_4 * ) V_138 -> V_5 ;
if ( F_50 ( ! V_5 ) )
return - V_54 ;
V_64 = (struct V_136 * ) V_5 -> V_64 ;
if ( F_50 ( ! V_64 ) )
return - V_54 ;
if ( ! V_138 -> V_141 ) {
F_31 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_5 -> V_64 -> V_96 )
V_12 = - V_97 ;
else
V_12 = F_33 ( V_64 -> V_85 ,
F_27 ( V_64 -> V_85 , 0 ) , V_143 ,
V_79 | V_78 | V_77 ,
V_139 << 8 , F_51 ( V_64 ) | ( V_17 << 8 ) ,
V_92 , V_140 ) ;
F_35 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_12 < 0 )
return V_12 ;
V_144 = V_92 [ 0 ] ;
V_138 -> V_142 = V_144 ;
V_138 -> V_141 = 1 ;
}
if ( V_144 != V_145 ) {
V_92 [ 0 ] = V_145 ;
V_92 [ 1 ] = 0 ;
F_31 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_5 -> V_64 -> V_96 )
V_12 = - V_97 ;
else
V_12 = F_33 ( V_64 -> V_85 ,
F_34 ( V_64 -> V_85 , 0 ) , V_146 ,
V_79 | V_78 | V_99 ,
V_139 << 8 , F_51 ( V_64 ) | ( V_17 << 8 ) ,
V_92 , V_140 ) ;
F_35 ( & V_5 -> V_64 -> V_95 ) ;
if ( V_12 < 0 )
return V_12 ;
V_138 -> V_142 = V_145 ;
V_138 -> V_141 = 1 ;
V_94 = 1 ;
}
return V_94 ;
}
static int F_53 ( struct V_4 * V_5 )
{
static struct V_120 V_122 = {
. V_68 = V_123 ,
. V_10 = L_22 ,
. V_90 = 0 ,
. V_29 = V_124 ,
. V_127 = F_48 ,
. V_125 = F_49 ,
. V_126 = F_52
} ;
int V_12 ;
struct V_1 * V_2 ;
struct V_137 * V_138 ;
V_138 = F_4 ( sizeof( * V_138 ) , V_15 ) ;
if ( ! V_138 )
return - V_16 ;
V_138 -> V_142 = 0 ;
V_138 -> V_141 = 0 ;
V_138 -> V_5 = V_5 ;
V_122 . V_91 = ( unsigned long ) V_138 ;
V_2 = F_5 ( & V_122 , V_5 -> V_64 ) ;
if ( ! V_2 ) {
F_2 ( V_138 ) ;
return - V_16 ;
}
V_12 = F_37 ( V_5 -> V_64 -> V_66 , V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_54 ( struct V_4 * V_5 )
{
char V_10 [ 64 ] ;
unsigned int V_7 , V_8 ;
int V_147 , V_98 , V_12 ;
const unsigned int V_17 = 5 ;
const int V_9 = V_148 ;
for ( V_98 = 0 ; V_98 < 8 ; V_98 ++ ) {
V_7 = V_98 + 1 ;
for ( V_147 = 0 ; V_147 < 8 ; V_147 ++ ) {
V_8 = 1 << V_147 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_23 ,
V_147 + 1 , V_98 + 1 ) ;
V_12 = F_3 ( V_5 , V_17 , V_7 ,
V_8 , V_9 , V_10 ,
& V_149 ) ;
if ( V_12 < 0 )
return V_12 ;
}
for ( V_147 = 8 ; V_147 < 16 ; V_147 ++ ) {
V_8 = 1 << V_147 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_24 ,
V_147 - 7 , V_98 + 1 ) ;
V_12 = F_3 ( V_5 , V_17 , V_7 ,
V_8 , V_9 , V_10 ,
& V_149 ) ;
if ( V_12 < 0 )
return V_12 ;
}
}
return 0 ;
}
static int F_55 ( struct V_4 * V_5 )
{
static const char V_10 [] = L_25 ;
const unsigned int V_17 = 6 ;
const int V_9 = V_150 ;
const unsigned int V_7 = 2 ;
const unsigned int V_8 = 0 ;
return F_3 ( V_5 , V_17 , V_7 , V_8 , V_9 ,
V_10 , V_149 ) ;
}
static int F_56 ( struct V_4 * V_5 )
{
static const char V_10 [] = L_26 ;
const unsigned int V_17 = 6 ;
const int V_9 = V_148 ;
const unsigned int V_7 = 3 ;
const unsigned int V_8 = 0 ;
return F_3 ( V_5 , V_17 , V_7 , V_8 , V_9 ,
V_10 , V_149 ) ;
}
static int F_57 ( struct V_4 * V_5 )
{
static const char V_10 [] = L_27 ;
const unsigned int V_17 = 6 ;
const int V_9 = V_150 ;
const unsigned int V_7 = 4 ;
const unsigned int V_8 = 0 ;
return F_3 ( V_5 , V_17 , V_7 , V_8 , V_9 ,
V_10 , NULL ) ;
}
static int F_58 ( struct V_4 * V_5 )
{
unsigned int V_8 ;
int V_12 , V_151 ;
char V_10 [ 48 ] ;
const unsigned int V_17 = 7 ;
const int V_9 = V_148 ;
const unsigned int V_7 = 7 ;
for ( V_151 = 0 ; V_151 < 4 ; ++ V_151 ) {
V_8 = 1 << V_151 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_28 , V_151 + 1 ) ;
V_12 = F_3 ( V_5 , V_17 , V_7 ,
V_8 , V_9 , V_10 ,
V_149 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static int F_59 ( struct V_4 * V_5 )
{
unsigned int V_8 ;
int V_12 , V_151 ;
char V_10 [ 48 ] ;
const unsigned int V_17 = 5 ;
const int V_9 = V_148 ;
const unsigned int V_7 = 9 ;
for ( V_151 = 0 ; V_151 < 8 ; ++ V_151 ) {
V_8 = 1 << V_151 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_29 , V_151 + 1 ) ;
V_12 = F_3 ( V_5 , V_17 , V_7 , V_8 ,
V_9 , V_10 ,
V_149 ) ;
if ( V_12 < 0 )
return V_12 ;
}
for ( V_151 = 8 ; V_151 < 16 ; ++ V_151 ) {
V_8 = 1 << V_151 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_30 , V_151 - 7 ) ;
V_12 = F_3 ( V_5 , V_17 , V_7 , V_8 ,
V_9 , V_10 ,
V_149 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static int F_60 ( struct V_4 * V_5 )
{
int V_12 ;
V_12 = F_54 ( V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_53 ( V_5 ) ;
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
V_12 = F_58 ( V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_59 ( V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
void F_61 ( struct V_136 * V_64 ,
unsigned char V_152 )
{
struct V_4 * V_5 ;
struct V_13 * V_14 ;
int V_6 = 12 ;
F_62 (mixer, &chip->mixer_list, list) {
V_14 = V_5 -> V_153 [ V_6 ] ;
if ( V_14 ) {
F_63 ( V_14 , V_146 ,
V_14 -> V_7 << 8 ,
V_152 ) ;
F_9 ( V_5 , V_6 ) ;
}
break;
}
}
int F_64 ( struct V_4 * V_5 )
{
int V_12 = 0 ;
struct V_103 * V_104 ;
if ( ( V_12 = F_18 ( V_5 ) ) < 0 )
return V_12 ;
switch ( V_5 -> V_64 -> V_63 ) {
case F_32 ( 0x041e , 0x3020 ) :
case F_32 ( 0x041e , 0x3040 ) :
case F_32 ( 0x041e , 0x3042 ) :
case F_32 ( 0x041e , 0x30df ) :
case F_32 ( 0x041e , 0x3048 ) :
V_12 = F_36 ( V_5 ) ;
if ( V_12 < 0 )
break;
if ( ! F_65 ( V_5 -> V_64 -> V_66 , L_31 , & V_104 ) )
F_66 ( V_104 , V_5 ,
F_38 ) ;
break;
case F_32 ( 0x0763 , 0x2080 ) :
case F_32 ( 0x0763 , 0x2081 ) :
V_12 = F_60 ( V_5 ) ;
break;
case F_32 ( 0x0b05 , 0x1739 ) :
case F_32 ( 0x0b05 , 0x1743 ) :
V_12 = F_42 ( V_5 ) ;
break;
case F_32 ( 0x17cc , 0x1011 ) :
V_12 = F_47 ( V_5 ,
V_154 ,
F_19 ( V_154 ) ) ;
break;
case F_32 ( 0x17cc , 0x1021 ) :
V_12 = F_47 ( V_5 ,
V_155 ,
F_19 ( V_155 ) ) ;
break;
case F_32 ( 0x200c , 0x1018 ) :
V_12 = F_7 ( V_5 , V_156 ) ;
break;
}
return V_12 ;
}
void F_67 ( struct V_4 * V_5 ,
int V_6 )
{
if ( ! V_5 -> V_38 )
return;
switch ( V_6 ) {
case 0 :
V_5 -> V_74 -> V_85 = V_5 -> V_64 -> V_85 ;
F_68 ( V_5 -> V_74 , V_157 ) ;
break;
case 4 :
case 7 :
case 19 :
case 20 :
break;
case 3 :
if ( V_5 -> V_64 -> V_63 == F_32 ( 0x041e , 0x3040 ) ||
V_5 -> V_64 -> V_63 == F_32 ( 0x041e , 0x3048 ) )
F_9 ( V_5 , V_5 -> V_38 -> V_47 ) ;
break;
default:
F_69 ( V_158 L_32 , V_6 ) ;
break;
}
}
