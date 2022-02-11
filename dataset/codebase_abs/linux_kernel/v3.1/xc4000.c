static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
struct V_5 V_6 = { . V_7 = V_2 -> V_8 . V_7 ,
. V_9 = 0 , . V_3 = V_3 , . V_4 = V_4 } ;
if ( F_2 ( V_2 -> V_8 . V_10 , & V_6 , 1 ) != 1 ) {
if ( V_2 -> V_11 == 0 ) {
F_3 ( V_12 L_1 ,
V_4 ) ;
if ( V_4 == 4 ) {
F_3 ( V_12 L_2 , V_3 [ 0 ] ,
V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] ) ;
}
return - V_13 ;
}
}
return 0 ;
}
static int F_4 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_17 ;
F_5 ( 1 , L_3 , V_18 ) ;
if ( V_15 -> V_19 ) {
V_17 = V_15 -> V_19 ( ( ( V_15 -> V_20 ) && ( V_15 -> V_20 -> V_2 ) ) ?
V_15 -> V_20 -> V_2 :
V_2 -> V_8 . V_10 -> V_21 ,
V_22 ,
V_23 , 0 ) ;
if ( V_17 ) {
F_3 ( V_12 L_4 ) ;
return - V_13 ;
}
} else {
F_3 ( V_12 L_5
L_6 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_25 , T_2 V_26 )
{
T_1 V_3 [ 4 ] ;
int V_27 ;
V_3 [ 0 ] = ( V_25 >> 8 ) & 0xFF ;
V_3 [ 1 ] = V_25 & 0xFF ;
V_3 [ 2 ] = ( V_26 >> 8 ) & 0xFF ;
V_3 [ 3 ] = V_26 & 0xFF ;
V_27 = F_1 ( V_2 , V_3 , 4 ) ;
return V_27 ;
}
static int F_7 ( struct V_14 * V_15 , const T_1 * V_28 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_29 , V_30 , V_27 ;
unsigned int V_4 , V_31 , V_32 ;
T_1 V_3 [ V_33 ] ;
V_32 = 0 ;
while ( ( V_28 [ V_32 ] != 0xFF ) ||
( V_28 [ V_32 + 1 ] != 0xFF ) ) {
V_4 = V_28 [ V_32 ] * 256 + V_28 [ V_32 + 1 ] ;
if ( V_4 == 0x0000 ) {
V_32 += 2 ;
} else if ( V_4 & 0x8000 ) {
F_8 ( V_4 & 0x7FFF ) ;
V_32 += 2 ;
} else {
V_32 += 2 ;
V_3 [ 0 ] = V_28 [ V_32 ] ;
V_3 [ 1 ] = V_28 [ V_32 + 1 ] ;
V_31 = 2 ;
while ( V_31 < V_4 ) {
if ( ( V_4 - V_31 ) > V_33 - 2 )
V_30 =
V_33 ;
else
V_30 = ( V_4 - V_31 + 2 ) ;
for ( V_29 = 2 ; V_29 < V_30 ; V_29 ++ ) {
V_3 [ V_29 ] = V_28 [ V_32 + V_31 +
V_29 - 2 ] ;
}
V_27 = F_1 ( V_2 , V_3 ,
V_30 ) ;
if ( V_27 != 0 )
return V_27 ;
V_31 += V_30 - 2 ;
}
V_32 += V_4 ;
}
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_2 V_34 , T_2 V_35 )
{
int V_17 ;
F_5 ( 1 , L_7 , V_18 , V_34 , V_35 ) ;
F_5 ( 1 , L_8 ,
V_18 ,
V_36 [ V_2 -> V_37 ] . V_38 ) ;
V_2 -> V_11 = 1 ;
V_17 = F_6 ( V_2 , V_39 , V_34 ) ;
if ( V_17 == 0 )
V_17 = F_6 ( V_2 , V_40 , V_35 ) ;
V_2 -> V_11 = 0 ;
return V_17 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_41 )
{
F_5 ( 1 , L_9 , V_18 , V_41 ,
V_41 == V_42 ? L_10 : L_11 ) ;
if ( ( V_41 != V_42 ) && ( V_41 != V_43 ) ) {
V_41 = V_43 ;
F_3 ( V_12
L_12 ,
V_18 ) ;
}
return F_6 ( V_2 , V_44 , V_41 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_3 V_45 )
{
T_2 V_46 ;
F_5 ( 1 , L_13 , V_18 , V_45 ) ;
if ( ( V_45 > V_47 . V_48 . V_49 ) ||
( V_45 < V_47 . V_48 . V_50 ) )
return - V_24 ;
V_46 = ( T_2 ) ( V_45 / 15625 ) ;
return F_6 ( V_2 , V_51 , V_46 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_2 * V_52 )
{
return F_13 ( V_2 , V_53 , V_52 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_3 * V_54 )
{
int V_27 ;
T_2 V_55 ;
T_3 V_56 ;
V_27 = F_13 ( V_2 , V_57 , & V_55 ) ;
if ( V_27 != 0 )
return V_27 ;
V_56 = ( T_3 ) V_55 & 0xFFFFU ;
V_56 = ( V_56 < 0x8000U ? V_56 : 0x10000U - V_56 ) ;
( * V_54 ) = V_56 * 15625 ;
return V_27 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 * V_58 )
{
return F_13 ( V_2 , V_59 , V_58 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
T_1 * V_60 , T_1 * V_61 ,
T_1 * V_62 , T_1 * V_63 )
{
T_2 V_64 ;
int V_27 ;
V_27 = F_13 ( V_2 , V_65 , & V_64 ) ;
if ( V_27 != 0 )
return V_27 ;
( * V_60 ) = ( V_64 >> 12 ) & 0x0F ;
( * V_61 ) = ( V_64 >> 8 ) & 0x0F ;
( * V_62 ) = ( V_64 >> 4 ) & 0x0F ;
( * V_63 ) = V_64 & 0x0F ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_3 * V_66 )
{
T_2 V_55 ;
int V_27 ;
V_27 = F_13 ( V_2 , V_67 , & V_55 ) ;
if ( V_27 != 0 )
return V_27 ;
( * V_66 ) = ( ( V_55 & 0x0fff ) * 763 ) / 100 ;
return V_27 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 * V_68 )
{
return F_13 ( V_2 , V_69 , V_68 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_2 * V_70 )
{
return F_13 ( V_2 , V_71 , V_70 ) ;
}
static T_2 F_20 ( struct V_1 * V_2 )
{
T_2 V_72 = 0 ;
int V_73 = 40 ;
while ( ( V_72 == 0 ) && ( V_73 > 0 ) ) {
F_15 ( V_2 , & V_72 ) ;
if ( V_72 != 1 ) {
F_8 ( 5 ) ;
V_73 -- ;
}
}
return V_72 ;
}
static int F_21 ( struct V_1 * V_2 , T_3 V_45 )
{
int V_74 = 1 ;
int V_27 ;
F_5 ( 1 , L_13 , V_18 , V_45 ) ;
V_2 -> V_11 = 1 ;
V_27 = F_11 ( V_2 , V_45 ) ;
V_2 -> V_11 = 0 ;
if ( V_27 != 0 )
return 0 ;
if ( ( V_2 -> V_75 . type & ( V_76 | V_77 | V_78 | V_79 | V_80 ) ) == 0 ) {
if ( F_20 ( V_2 ) != 1 )
V_74 = 0 ;
}
F_8 ( V_81 ? 100 : 10 ) ;
if ( V_81 )
F_22 ( V_2 ) ;
return V_74 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_82 , T_2 * V_83 )
{
T_1 V_3 [ 2 ] = { V_82 >> 8 , V_82 & 0xff } ;
T_1 V_84 [ 2 ] = { 0 , 0 } ;
struct V_5 V_6 [ 2 ] = {
{ . V_7 = V_2 -> V_8 . V_7 ,
. V_9 = 0 , . V_3 = & V_3 [ 0 ] , . V_4 = 2 } ,
{ . V_7 = V_2 -> V_8 . V_7 ,
. V_9 = V_85 , . V_3 = & V_84 [ 0 ] , . V_4 = 2 } ,
} ;
if ( F_2 ( V_2 -> V_8 . V_10 , V_6 , 2 ) != 2 ) {
F_3 ( V_12 L_14 ) ;
return - V_13 ;
}
* V_83 = ( V_84 [ 0 ] << 8 ) | V_84 [ 1 ] ;
return 0 ;
}
static void F_23 ( unsigned int type , T_2 V_86 )
{
if ( type & V_87 )
F_3 ( V_88 L_15 ) ;
if ( type & V_89 )
F_3 ( V_88 L_16 ) ;
if ( type & V_90 )
F_3 ( V_88 L_17 ) ;
if ( type & V_91 )
F_3 ( V_88 L_18 ) ;
if ( type & V_92 )
F_3 ( V_88 L_19 ) ;
if ( type & V_93 )
F_3 ( V_88 L_20 ) ;
if ( type & V_77 )
F_3 ( V_88 L_21 ) ;
if ( type & V_94 )
F_3 ( V_88 L_22 ) ;
if ( type & V_78 )
F_3 ( V_88 L_23 ) ;
if ( type & V_79 )
F_3 ( V_88 L_24 ) ;
if ( type & V_80 )
F_3 ( V_88 L_25 ) ;
if ( type & V_76 )
F_3 ( V_88 L_26 ) ;
if ( type & V_95 )
F_3 ( V_88 L_27 ) ;
if ( type & V_96 )
F_3 ( V_88 L_28 ) ;
if ( type & V_97 )
F_3 ( V_88 L_29 ) ;
if ( type & V_98 )
F_3 ( V_88 L_30 ) ;
if ( type & V_99 )
F_3 ( V_88 L_31 ) ;
if ( type & IF )
F_3 ( V_88 L_32 ) ;
if ( type & V_100 )
F_3 ( V_88 L_33 ) ;
if ( type & V_101 )
F_3 ( V_88 L_34 ) ;
if ( type & V_102 )
F_3 ( V_88 L_35 ) ;
if ( type & V_103 )
F_3 ( V_88 L_36 ) ;
if ( type & V_104 )
F_3 ( V_88 L_37 ) ;
if ( type & V_105 )
F_3 ( V_88 L_38 ) ;
if ( type & V_106 )
F_3 ( V_88 L_39 ) ;
if ( type & V_107 )
F_3 ( V_88 L_40 ) ;
if ( type & V_108 )
F_3 ( V_88 L_41 ) ;
if ( type & V_109 )
F_3 ( V_88 L_42 ) ;
if ( type & V_110 )
F_3 ( V_88 L_43 ) ;
if ( type & V_111 )
F_3 ( V_88 L_44 ) ;
if ( type & V_112 )
F_3 ( V_88 L_45 , V_86 ) ;
}
static int F_24 ( struct V_14 * V_15 , unsigned int type ,
T_4 * V_113 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_29 , V_114 = - 1 ;
unsigned int V_115 = 255U ;
if ( ! V_2 -> V_116 ) {
F_3 ( V_12 L_46 ) ;
return - V_24 ;
}
if ( ( ( type & ~ V_111 ) == 0 ) && ( * V_113 == 0 ) )
* V_113 = V_117 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_118 ; V_29 ++ ) {
T_4 V_119 =
( V_2 -> V_116 [ V_29 ] . V_113 ^ ( * V_113 ) ) & ( * V_113 ) ;
unsigned int V_120 =
( V_2 -> V_116 [ V_29 ] . type ^ type )
& ( V_121 | V_122 | V_96 | V_97 | V_98 | V_111 ) ;
unsigned int V_123 ;
if ( V_120
& ( V_87 | V_89 | V_76 | V_77 | V_78 | V_79 | V_80 | V_111 ) )
continue;
V_123 = F_25 ( V_119 ) + F_26 ( V_120 ) ;
if ( ! V_123 )
goto V_74;
if ( V_123 < V_115 ) {
V_115 = V_123 ;
V_114 = V_29 ;
}
}
if ( V_114 < 0 ) {
V_29 = - V_124 ;
goto V_17;
}
if ( V_115 > 0U ) {
F_3 ( V_125
L_47
L_48 ,
V_115 , type , ( unsigned long long ) * V_113 ) ;
V_29 = V_114 ;
}
V_74:
* V_113 = V_2 -> V_116 [ V_29 ] . V_113 ;
V_17:
if ( V_81 ) {
F_3 ( V_126 L_49 ,
( V_29 < 0 ) ? L_50 : L_51 ) ;
F_27 ( type ) ;
F_3 ( V_126 L_52 , type , ( unsigned long long ) * V_113 ) ;
}
return V_29 ;
}
static int F_28 ( struct V_14 * V_15 , unsigned int type ,
T_4 * V_113 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_31 , V_127 ;
unsigned char * V_128 ;
V_31 = F_24 ( V_15 , type , V_113 ) ;
if ( V_31 < 0 )
return V_31 ;
V_128 = V_2 -> V_116 [ V_31 ] . V_129 ;
V_2 -> V_11 = 1 ;
V_127 = F_7 ( V_15 , V_128 ) ;
V_2 -> V_11 = 0 ;
return V_127 ;
}
static int F_29 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
const struct V_130 * V_131 = NULL ;
const unsigned char * V_128 , * V_132 ;
int V_127 = 0 ;
int V_133 , V_134 ;
char V_135 [ 33 ] ;
const char * V_136 ;
if ( V_137 [ 0 ] != '\0' )
V_136 = V_137 ;
else
V_136 = V_138 ;
F_5 ( 1 , L_53 , V_136 ) ;
V_127 = F_30 ( & V_131 , V_136 , V_2 -> V_8 . V_10 -> V_139 . V_140 ) ;
if ( V_127 < 0 ) {
if ( V_127 == - V_124 )
F_3 ( V_12 L_54 , V_136 ) ;
else
F_3 ( V_12 L_55 ,
V_127 , V_136 ) ;
return V_127 ;
}
V_128 = V_131 -> V_64 ;
V_132 = V_128 + V_131 -> V_141 ;
if ( V_131 -> V_141 < sizeof( V_135 ) - 1 + 2 + 2 ) {
F_3 ( V_12 L_56 ,
V_136 ) ;
goto V_142;
}
memcpy ( V_135 , V_128 , sizeof( V_135 ) - 1 ) ;
V_135 [ sizeof( V_135 ) - 1 ] = '\0' ;
V_128 += sizeof( V_135 ) - 1 ;
V_2 -> V_143 = F_31 ( V_128 ) ;
V_128 += 2 ;
V_134 = F_31 ( V_128 ) ;
V_128 += 2 ;
F_5 ( 1 , L_57 ,
V_134 , V_136 , V_135 ,
V_2 -> V_143 >> 8 , V_2 -> V_143 & 0xff ) ;
V_2 -> V_116 = F_32 ( sizeof( * V_2 -> V_116 ) * V_134 , V_144 ) ;
if ( V_2 -> V_116 == NULL ) {
F_3 ( V_12 L_58 ) ;
V_127 = - V_145 ;
goto V_146;
}
V_2 -> V_118 = V_134 ;
V_133 = - 1 ;
while ( V_128 < V_132 ) {
T_5 type , V_141 ;
T_4 V_113 ;
T_6 V_86 = 0 ;
V_133 ++ ;
if ( V_133 >= V_134 ) {
F_3 ( V_12 L_59
L_60 ) ;
goto V_142;
}
if ( V_132 - V_128 < sizeof( type ) + sizeof( V_113 ) + sizeof( V_141 ) )
goto V_147;
type = F_33 ( V_128 ) ;
V_128 += sizeof( type ) ;
V_113 = F_34 ( V_128 ) ;
V_128 += sizeof( V_113 ) ;
if ( type & V_112 ) {
V_86 = F_31 ( V_128 ) ;
V_128 += sizeof( V_86 ) ;
if ( V_132 - V_128 < sizeof( V_141 ) )
goto V_147;
}
V_141 = F_33 ( V_128 ) ;
V_128 += sizeof( V_141 ) ;
if ( ! V_141 || V_141 > V_132 - V_128 ) {
F_3 ( V_12 L_61 ,
type , ( unsigned long long ) V_113 ,
( unsigned ) ( V_132 - V_128 ) , V_141 ) ;
goto V_142;
}
V_2 -> V_116 [ V_133 ] . V_129 = F_32 ( V_141 , V_144 ) ;
if ( V_2 -> V_116 [ V_133 ] . V_129 == NULL ) {
F_3 ( V_12 L_58 ) ;
V_127 = - V_145 ;
goto V_146;
}
if ( V_81 ) {
F_3 ( V_126 L_62 ) ;
F_23 ( type , V_86 ) ;
F_3 ( V_126 L_63 ,
type , ( unsigned long long ) V_113 , V_141 ) ;
}
memcpy ( V_2 -> V_116 [ V_133 ] . V_129 , V_128 , V_141 ) ;
V_2 -> V_116 [ V_133 ] . type = type ;
V_2 -> V_116 [ V_133 ] . V_113 = V_113 ;
V_2 -> V_116 [ V_133 ] . V_141 = V_141 ;
V_2 -> V_116 [ V_133 ] . V_86 = V_86 ;
V_128 += V_141 ;
}
if ( V_133 + 1 != V_2 -> V_118 ) {
F_3 ( V_12 L_64 ) ;
goto V_142;
}
goto V_146;
V_147:
F_3 ( V_12 L_65 ) ;
V_142:
V_127 = - V_24 ;
F_3 ( V_12 L_66 ) ;
V_146:
F_35 ( V_131 ) ;
if ( V_127 == 0 )
F_5 ( 1 , L_67 ) ;
return V_127 ;
}
static int F_36 ( struct V_14 * V_15 , unsigned int type ,
T_4 * V_113 , T_6 V_86 , int V_148 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_31 , V_127 ;
unsigned char * V_128 ;
T_1 V_149 [ 13 ] ;
T_1 V_150 [ 5 ] ;
F_5 ( 1 , L_68 , V_18 , V_86 ) ;
if ( ! V_86 ) {
V_31 = F_24 ( V_15 , type , V_113 ) ;
if ( V_31 < 0 )
return V_31 ;
} else {
for ( V_31 = 0 ; V_31 < V_2 -> V_118 ; V_31 ++ ) {
if ( ( V_2 -> V_116 [ V_31 ] . V_86 == V_86 ) &&
( V_2 -> V_116 [ V_31 ] . type & V_112 ) )
break;
}
if ( V_31 == V_2 -> V_118 )
return - V_124 ;
}
V_128 = V_2 -> V_116 [ V_31 ] . V_129 ;
if ( V_2 -> V_116 [ V_31 ] . V_141 != 12 * 16 || V_148 >= 16 )
return - V_24 ;
V_128 += 12 * V_148 ;
if ( V_81 ) {
F_37 ( L_69 ) ;
F_23 ( V_2 -> V_116 [ V_31 ] . type ,
V_2 -> V_116 [ V_31 ] . V_86 ) ;
F_3 ( V_88 L_52 , V_2 -> V_116 [ V_31 ] . type ,
( unsigned long long ) * V_113 ) ;
}
V_149 [ 0 ] = 0x00 ;
memcpy ( & V_149 [ 1 ] , V_128 , 12 ) ;
V_127 = F_6 ( V_2 , V_151 , 0 ) ;
if ( V_127 < 0 ) {
F_3 ( V_12 L_70 ) ;
return - V_152 ;
}
V_127 = F_1 ( V_2 , V_149 , 13 ) ;
if ( V_127 != 0 ) {
F_3 ( V_12 L_71 , V_127 ) ;
}
memset ( V_150 , 0 , sizeof( V_150 ) ) ;
V_150 [ 4 ] = 0x88 ;
F_1 ( V_2 , V_150 , sizeof( V_150 ) ) ;
F_8 ( 10 ) ;
return 0 ;
}
static int F_38 ( struct V_14 * V_15 , unsigned int type ,
T_4 V_153 , T_6 V_86 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_154 V_155 ;
int V_127 = 0 , V_156 = 0 ;
T_2 V_157 ;
T_4 V_158 ;
T_1 V_159 , V_160 , V_161 , V_162 ;
F_5 ( 1 , L_72 , V_18 ) ;
if ( ! V_2 -> V_116 ) {
V_127 = F_29 ( V_15 ) ;
if ( V_127 < 0 )
return V_127 ;
}
V_163:
V_155 . type = type ;
V_155 . V_113 = V_153 ;
V_155 . V_164 = V_153 ;
V_155 . V_165 = V_111 ;
V_155 . V_166 = 0 ;
V_155 . V_86 = V_86 ;
F_5 ( 1 , L_73 ) ;
if ( V_81 ) {
F_27 ( V_155 . type ) ;
F_3 ( V_88 L_74 , V_155 . type ,
( unsigned long long ) V_155 . V_164 ) ;
if ( ! V_86 )
F_3 ( V_88 L_75 ) ;
else
F_3 ( V_88 L_76 , V_155 . V_86 ) ;
F_3 ( V_88 L_77 , V_155 . V_166 ) ;
}
if ( V_2 -> V_75 . type & V_87 ) {
F_5 ( 1 , L_78 ) ;
goto V_167;
}
memset ( & V_2 -> V_75 , 0 , sizeof( V_2 -> V_75 ) ) ;
V_127 = F_4 ( V_15 ) ;
if ( V_127 < 0 )
goto V_168;
V_158 = 0 ;
V_127 = F_28 ( V_15 , V_87 , & V_158 ) ;
if ( V_127 < 0 ) {
F_3 ( V_12 L_79 , V_127 ) ;
goto V_168;
}
F_5 ( 1 , L_80 ) ;
V_127 = F_28 ( V_15 , V_87 | V_89 , & V_158 ) ;
if ( V_127 == - V_124 )
V_127 = F_28 ( V_15 , V_87 | V_89 , & V_158 ) ;
if ( V_127 < 0 && V_127 != - V_124 ) {
F_39 ( L_81 ,
V_127 ) ;
goto V_168;
}
V_167:
if ( V_2 -> V_75 . type == ( V_87 | V_155 . type ) &&
V_2 -> V_75 . V_164 == V_153 ) {
F_5 ( 1 , L_82 ) ;
goto V_169;
}
V_2 -> V_75 . V_165 = 0 ;
V_127 = F_28 ( V_15 , V_155 . type , & V_155 . V_113 ) ;
if ( V_127 < 0 )
goto V_168;
V_169:
if ( V_2 -> V_75 . V_165 == V_155 . V_165 &&
V_2 -> V_75 . V_166 == V_155 . V_166 ) {
F_5 ( 1 , L_83 ) ;
goto V_170;
}
V_127 = F_36 ( V_15 , V_155 . type | V_155 . V_165 , & V_155 . V_113 ,
V_155 . V_86 , V_155 . V_166 ) ;
if ( V_127 != 0 )
F_5 ( 1 , L_84 , V_127 ) ;
V_170:
V_127 = F_13 ( V_2 , V_171 , & V_157 ) ;
if ( F_16 ( V_2 , & V_159 , & V_160 , & V_161 ,
& V_162 ) != 0 ) {
F_3 ( V_12 L_85 ) ;
goto V_168;
}
F_5 ( 1 , L_86
L_87 ,
V_157 , V_159 , V_160 , V_161 , V_162 ) ;
if ( V_2 -> V_143 != ( ( V_161 << 8 ) | V_162 ) ) {
F_3 ( V_125
L_88 ,
V_161 , V_162 ) ;
goto V_168;
}
if ( V_2 -> V_157 == 0 &&
( V_157 == V_172 ||
V_157 == V_173 ) ) {
V_2 -> V_157 = V_157 ;
V_2 -> V_174 = ( V_159 << 8 ) | V_160 ;
} else if ( V_2 -> V_157 == 0 || V_2 -> V_157 != V_157 ||
V_2 -> V_174 != ( ( V_159 << 8 ) | V_160 ) ) {
F_3 ( V_125
L_89
L_90 ) ;
goto V_168;
}
memcpy ( & V_2 -> V_75 , & V_155 , sizeof( V_2 -> V_75 ) ) ;
V_2 -> V_75 . type |= V_87 ;
return 0 ;
V_168:
memset ( & V_2 -> V_75 , 0 , sizeof( V_2 -> V_75 ) ) ;
if ( ! V_156 ) {
F_8 ( 50 ) ;
V_156 = 1 ;
F_5 ( 1 , L_91 ) ;
goto V_163;
}
if ( V_127 == - V_124 )
V_127 = - V_24 ;
return V_127 ;
}
static void F_22 ( struct V_1 * V_2 )
{
T_2 V_52 ;
T_3 V_54 = 0 ;
T_2 V_58 ;
T_3 V_66 = 0 ;
T_2 V_68 ;
T_2 V_70 ;
T_1 V_60 = 0 , V_61 = 0 ;
T_1 V_62 = 0 , V_63 = 0 ;
F_12 ( V_2 , & V_52 ) ;
F_5 ( 1 , L_92 , V_52 ) ;
F_14 ( V_2 , & V_54 ) ;
F_5 ( 1 , L_93 , V_54 ) ;
F_15 ( V_2 , & V_58 ) ;
F_5 ( 1 , L_94 ,
V_58 ) ;
F_16 ( V_2 , & V_60 , & V_61 ,
& V_62 , & V_63 ) ;
F_5 ( 1 , L_95 ,
V_60 , V_61 ,
V_62 , V_63 ) ;
if ( V_2 -> V_37 < V_175 ) {
F_17 ( V_2 , & V_66 ) ;
F_5 ( 1 , L_96 ,
V_66 ) ;
F_18 ( V_2 , & V_68 ) ;
F_5 ( 1 , L_97 , V_68 ) ;
}
F_19 ( V_2 , & V_70 ) ;
F_5 ( 1 , L_98 , V_70 ) ;
}
static int F_40 ( struct V_14 * V_15 ,
struct V_176 * V_177 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned int type ;
int V_17 = - V_13 ;
F_5 ( 1 , L_99 , V_18 , V_177 -> V_178 ) ;
F_41 ( & V_2 -> V_179 ) ;
if ( V_15 -> V_180 . V_48 . type == V_181 ) {
F_5 ( 1 , L_100 , V_18 ) ;
switch ( V_177 -> V_182 . V_183 . V_184 ) {
case V_185 :
case V_186 :
F_5 ( 1 , L_101 , V_18 ) ;
V_2 -> V_41 = V_42 ;
V_2 -> V_45 = V_177 -> V_178 - 1750000 ;
V_2 -> V_187 = V_188 ;
V_2 -> V_37 = V_175 ;
type = V_77 ;
break;
case V_189 :
case V_190 :
case V_191 :
F_5 ( 1 , L_102 , V_18 ) ;
V_2 -> V_41 = V_43 ;
V_2 -> V_45 = V_177 -> V_178 - 1750000 ;
V_2 -> V_187 = V_188 ;
V_2 -> V_37 = V_175 ;
type = V_77 ;
break;
default:
V_17 = - V_24 ;
goto V_168;
}
} else if ( V_15 -> V_180 . V_48 . type == V_192 ) {
F_5 ( 1 , L_103 , V_18 ) ;
switch ( V_177 -> V_182 . V_193 . V_187 ) {
case V_188 :
V_2 -> V_187 = V_188 ;
V_2 -> V_37 = V_175 ;
V_2 -> V_45 = V_177 -> V_178 - 1750000 ;
type = V_77 ;
break;
case V_194 :
V_2 -> V_187 = V_194 ;
V_2 -> V_37 = V_195 ;
V_2 -> V_45 = V_177 -> V_178 - 2250000 ;
type = V_78 ;
break;
case V_196 :
V_2 -> V_187 = V_196 ;
V_2 -> V_37 = V_197 ;
V_2 -> V_45 = V_177 -> V_178 - 2750000 ;
type = V_80 ;
break;
case V_198 :
if ( V_177 -> V_178 < 400000000 ) {
V_2 -> V_187 = V_194 ;
V_2 -> V_45 = V_177 -> V_178 - 2250000 ;
} else {
V_2 -> V_187 = V_196 ;
V_2 -> V_45 = V_177 -> V_178 - 2750000 ;
}
V_2 -> V_37 = V_199 ;
type = V_79 ;
break;
default:
F_3 ( V_12 L_104 ) ;
V_17 = - V_24 ;
goto V_168;
}
V_2 -> V_41 = V_42 ;
} else {
F_3 ( V_12 L_105 ) ;
V_17 = - V_24 ;
goto V_168;
}
F_5 ( 1 , L_106 ,
V_18 , V_2 -> V_45 ) ;
if ( F_38 ( V_15 , type , 0 , V_2 -> V_200 ) != 0 )
goto V_168;
V_17 = F_10 ( V_2 , V_2 -> V_41 ) ;
if ( V_17 != 0 ) {
F_3 ( V_12 L_107 ,
V_2 -> V_41 ) ;
goto V_168;
} else {
T_2 V_34 , V_35 ;
V_34 = V_36 [ V_2 -> V_37 ] . V_34 ;
V_35 = V_36 [ V_2 -> V_37 ] . V_35 ;
if ( type == V_77 && V_2 -> V_143 != 0x0102 )
V_34 |= 0x0001 ;
V_17 = F_9 ( V_2 , V_34 , V_35 ) ;
if ( V_17 != 0 ) {
F_3 ( V_12 L_108 ) ;
}
}
if ( F_6 ( V_2 , V_201 , 0 ) == 0 )
V_17 = 0 ;
if ( V_2 -> V_202 != 0 ) {
if ( F_6 ( V_2 , V_203 ,
( V_2 -> V_143 != 0x0102 ||
V_2 -> V_202 != 134 ?
V_2 -> V_202 : 132 ) ) != 0 )
V_17 = - V_13 ;
}
if ( V_2 -> V_204 != 0 ) {
if ( F_6 ( V_2 , V_205 , 1 ) != 0 )
V_17 = - V_13 ;
}
if ( V_17 != 0 ) {
F_3 ( V_12 L_109 ) ;
}
F_21 ( V_2 , V_2 -> V_45 ) ;
V_17 = 0 ;
V_168:
F_42 ( & V_2 -> V_179 ) ;
return V_17 ;
}
static int F_43 ( struct V_14 * V_15 ,
struct V_206 * V_177 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned int type = 0 ;
int V_17 = - V_13 ;
if ( V_177 -> V_207 == V_208 ) {
F_5 ( 1 , L_110 ,
V_18 , V_177 -> V_178 ) ;
F_41 ( & V_2 -> V_179 ) ;
V_177 -> V_153 = 0 ;
V_2 -> V_45 = V_177 -> V_178 * 125L / 2 ;
if ( V_209 & V_210 ) {
V_2 -> V_37 = V_211 ;
type = V_76 | V_95 ;
} else {
V_2 -> V_37 = V_212 ;
type = V_76 | V_110 ;
}
goto V_213;
}
F_5 ( 1 , L_111 ,
V_18 , V_177 -> V_178 ) ;
F_41 ( & V_2 -> V_179 ) ;
V_2 -> V_45 = V_177 -> V_178 * 62500 ;
V_177 -> V_153 &= V_214 ;
if ( ! V_177 -> V_153 )
V_177 -> V_153 = V_215 ;
if ( V_209 & V_216 )
type = V_98 ;
if ( V_177 -> V_153 & V_217 ) {
V_177 -> V_153 = V_217 ;
if ( V_209 & V_216 ) {
V_2 -> V_37 = V_218 ;
} else if ( V_209 & V_219 ) {
V_177 -> V_153 |= V_220 ;
V_2 -> V_37 = V_221 ;
} else {
V_177 -> V_153 |= V_222 ;
V_2 -> V_37 = V_223 ;
}
goto V_213;
}
if ( V_177 -> V_153 & V_215 ) {
V_177 -> V_153 = V_215 ;
if ( V_209 & V_216 ) {
V_2 -> V_37 = V_224 ;
} else if ( ! ( V_209 & V_219 ) ) {
if ( ! ( V_209 & V_225 ) ) {
V_177 -> V_153 |= V_226 ;
V_2 -> V_37 = V_227 ;
} else {
V_177 -> V_153 |= V_228 ;
V_2 -> V_37 = V_227 ;
}
} else {
if ( ! ( V_209 & V_225 ) ) {
V_177 -> V_153 |= V_229 ;
V_2 -> V_37 = V_230 ;
} else {
V_177 -> V_153 |= V_231 ;
V_2 -> V_37 = V_230 ;
}
}
goto V_213;
}
if ( V_177 -> V_153 & V_232 ) {
V_177 -> V_153 = V_232 | V_233 ;
if ( V_209 & V_216 )
V_2 -> V_37 = V_234 ;
else
V_2 -> V_37 = V_235 ;
goto V_213;
}
if ( V_177 -> V_153 & V_236 ) {
V_177 -> V_153 = V_236 ;
if ( V_209 & V_216 ) {
V_2 -> V_37 = V_237 ;
} else if ( V_209 & V_219 ) {
V_177 -> V_153 |= V_220 ;
V_2 -> V_37 = V_238 ;
} else {
V_177 -> V_153 |= V_233 ;
V_2 -> V_37 = V_239 ;
}
goto V_213;
}
if ( V_177 -> V_153 & V_240 ) {
V_177 -> V_153 = V_240 | V_220 ;
if ( V_209 & V_241 ) {
type = 0 ;
V_2 -> V_37 = V_242 ;
} else if ( V_209 & V_216 ) {
V_2 -> V_37 = V_243 ;
} else if ( V_209 & V_244 ) {
V_177 -> V_153 |= V_245 ;
V_2 -> V_37 = V_246 ;
} else {
V_2 -> V_37 = V_247 ;
}
goto V_213;
}
if ( V_177 -> V_153 & V_248 ) {
type = 0 ;
V_177 -> V_153 = V_248 | V_233 ;
V_2 -> V_37 = V_249 ;
goto V_213;
}
if ( V_177 -> V_153 & V_250 ) {
type = 0 ;
V_177 -> V_153 = V_250 | V_233 ;
V_2 -> V_37 = V_251 ;
goto V_213;
}
V_213:
V_2 -> V_41 = V_43 ;
if ( F_38 ( V_15 , type , V_177 -> V_153 ,
V_36 [ V_2 -> V_37 ] . V_86 ) != 0 )
goto V_168;
V_17 = F_10 ( V_2 , V_2 -> V_41 ) ;
if ( V_17 != 0 ) {
F_3 ( V_12
L_107 ,
V_2 -> V_41 ) ;
goto V_168;
} else {
T_2 V_34 , V_35 ;
V_34 = V_36 [ V_2 -> V_37 ] . V_34 ;
V_35 = V_36 [ V_2 -> V_37 ] . V_35 ;
if ( V_2 -> V_37 < V_230 ) {
if ( type & V_97 )
V_34 &= 0xFF7F ;
} else if ( V_2 -> V_37 < V_235 ) {
if ( V_2 -> V_143 == 0x0102 )
V_34 &= 0xFEFF ;
if ( V_209 & V_225 )
V_34 |= 0x0080 ;
}
V_17 = F_9 ( V_2 , V_34 , V_35 ) ;
if ( V_17 != 0 ) {
F_3 ( V_12 L_108 ) ;
goto V_168;
}
}
if ( F_6 ( V_2 , V_201 , 0 ) == 0 )
V_17 = 0 ;
if ( F_6 ( V_2 , V_203 , 1 ) != 0 )
V_17 = - V_13 ;
if ( V_2 -> V_204 != 0 ) {
if ( F_6 ( V_2 , V_205 , 1 ) != 0 )
V_17 = - V_13 ;
}
if ( V_17 != 0 ) {
F_3 ( V_12 L_109 ) ;
goto V_168;
}
F_21 ( V_2 , V_2 -> V_45 ) ;
V_17 = 0 ;
V_168:
F_42 ( & V_2 -> V_179 ) ;
return V_17 ;
}
static int F_44 ( struct V_14 * V_15 , T_3 * V_252 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
* V_252 = V_2 -> V_45 ;
if ( V_81 ) {
F_41 ( & V_2 -> V_179 ) ;
if ( ( V_2 -> V_75 . type
& ( V_87 | V_76 | V_77 | V_78 | V_79 | V_80 ) ) == V_87 ) {
T_2 V_253 = 0 ;
if ( F_13 ( V_2 , V_254 , & V_253 ) == 0 ) {
F_42 ( & V_2 -> V_179 ) ;
F_5 ( 1 , L_112 ,
V_18 , * V_252 , V_253 ) ;
return 0 ;
}
}
F_42 ( & V_2 -> V_179 ) ;
}
F_5 ( 1 , L_3 , V_18 ) ;
return 0 ;
}
static int F_45 ( struct V_14 * V_15 , T_3 * V_255 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
F_5 ( 1 , L_3 , V_18 ) ;
* V_255 = V_2 -> V_187 ;
return 0 ;
}
static int F_46 ( struct V_14 * V_15 , T_3 * V_256 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
T_2 V_58 = 0 ;
F_41 ( & V_2 -> V_179 ) ;
if ( V_2 -> V_75 . type & V_87 )
F_15 ( V_2 , & V_58 ) ;
* V_256 = ( V_58 == 1 ?
V_257 | V_258 : 0 ) ;
if ( V_2 -> V_75 . type & ( V_77 | V_78 | V_79 | V_80 ) )
* V_256 &= ( ~ V_258 ) ;
F_42 ( & V_2 -> V_179 ) ;
F_5 ( 2 , L_113 , V_18 , V_58 ) ;
return 0 ;
}
static int F_47 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_17 = 0 ;
F_5 ( 1 , L_3 , V_18 ) ;
F_41 ( & V_2 -> V_179 ) ;
if ( ( V_259 == 2 ||
( V_259 == 0 && V_2 -> V_260 != 0 ) ) &&
( V_2 -> V_75 . type & V_87 ) != 0 ) {
V_2 -> V_75 . type = V_261 ;
if ( F_6 ( V_2 , V_262 , 0 ) != 0 ) {
F_3 ( V_12
L_114 ,
V_18 ) ;
V_17 = - V_13 ;
}
F_8 ( 20 ) ;
}
F_42 ( & V_2 -> V_179 ) ;
return V_17 ;
}
static int F_48 ( struct V_14 * V_15 )
{
F_5 ( 1 , L_3 , V_18 ) ;
return 0 ;
}
static int F_49 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
F_5 ( 1 , L_3 , V_18 ) ;
F_41 ( & V_263 ) ;
if ( V_2 )
F_50 ( V_2 ) ;
F_42 ( & V_263 ) ;
V_15 -> V_16 = NULL ;
return 0 ;
}
struct V_14 * F_51 ( struct V_14 * V_15 ,
struct V_264 * V_265 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = NULL ;
int V_268 ;
T_2 V_113 = 0 ;
F_5 ( 1 , L_115 , V_18 ,
V_265 ? F_52 ( V_265 ) : - 1 ,
V_267 ? V_267 -> V_269 : - 1 ) ;
F_41 ( & V_263 ) ;
V_268 = F_53 ( struct V_1 , V_2 ,
V_270 ,
V_265 , V_267 -> V_269 , L_116 ) ;
switch ( V_268 ) {
case 0 :
goto V_168;
break;
case 1 :
V_2 -> V_187 = V_188 ;
V_2 -> V_200 = 4560 ;
V_2 -> V_260 = 0 ;
V_2 -> V_202 = 134 ;
V_2 -> V_204 = 1 ;
F_54 ( & V_2 -> V_179 ) ;
V_15 -> V_16 = V_2 ;
break;
default:
V_15 -> V_16 = V_2 ;
break;
}
if ( V_267 -> V_200 != 0 ) {
V_2 -> V_200 = V_267 -> V_200 ;
V_2 -> V_260 = V_267 -> V_260 ;
V_2 -> V_202 = V_267 -> V_202 ;
V_2 -> V_204 = V_267 -> V_204 ;
}
if ( V_268 == 1 ) {
if ( F_13 ( V_2 , V_171 , & V_113 ) != 0 )
goto V_168;
} else {
V_113 = ( ( V_2 -> V_75 . type & V_87 ) != 0 ?
V_2 -> V_157 : V_271 ) ;
}
switch ( V_113 ) {
case V_172 :
case V_173 :
F_3 ( V_272
L_117 ,
V_267 -> V_269 ) ;
F_3 ( V_272
L_118 ) ;
break;
case V_271 :
F_3 ( V_272
L_117 ,
V_267 -> V_269 ) ;
F_3 ( V_272
L_119 ) ;
break;
default:
F_3 ( V_12
L_120 ,
V_267 -> V_269 , V_113 ) ;
goto V_168;
}
F_42 ( & V_263 ) ;
memcpy ( & V_15 -> V_180 . V_273 , & V_47 ,
sizeof( struct V_274 ) ) ;
if ( V_268 == 1 ) {
int V_17 ;
F_41 ( & V_2 -> V_179 ) ;
V_17 = F_29 ( V_15 ) ;
F_42 ( & V_2 -> V_179 ) ;
if ( V_17 != 0 )
goto V_275;
}
return V_15 ;
V_168:
F_42 ( & V_263 ) ;
V_275:
F_49 ( V_15 ) ;
return NULL ;
}
