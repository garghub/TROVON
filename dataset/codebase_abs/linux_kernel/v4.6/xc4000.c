static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
struct V_5 V_6 = { . V_7 = V_2 -> V_8 . V_7 ,
. V_9 = 0 , . V_3 = V_3 , . V_4 = V_4 } ;
if ( F_2 ( V_2 -> V_8 . V_10 , & V_6 , 1 ) != 1 ) {
if ( V_2 -> V_11 == 0 ) {
F_3 ( V_12 L_1 ,
V_4 ) ;
if ( V_4 == 4 ) {
F_3 ( V_12 L_2 , 4 , V_3 ) ;
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
static int F_20 ( struct V_1 * V_2 , T_2 * signal )
{
return F_13 ( V_2 , V_72 , signal ) ;
}
static int F_21 ( struct V_1 * V_2 , T_2 * V_73 )
{
return F_13 ( V_2 , V_74 , V_73 ) ;
}
static T_2 F_22 ( struct V_1 * V_2 )
{
T_2 V_75 = 0 ;
int V_76 = 40 ;
while ( ( V_75 == 0 ) && ( V_76 > 0 ) ) {
F_15 ( V_2 , & V_75 ) ;
if ( V_75 != 1 ) {
F_8 ( 5 ) ;
V_76 -- ;
}
}
return V_75 ;
}
static int F_23 ( struct V_1 * V_2 , T_3 V_45 )
{
int V_77 = 1 ;
int V_27 ;
F_5 ( 1 , L_13 , V_18 , V_45 ) ;
V_2 -> V_11 = 1 ;
V_27 = F_11 ( V_2 , V_45 ) ;
V_2 -> V_11 = 0 ;
if ( V_27 != 0 )
return 0 ;
if ( ( V_2 -> V_78 . type & ( V_79 | V_80 | V_81 | V_82 | V_83 ) ) == 0 ) {
if ( F_22 ( V_2 ) != 1 )
V_77 = 0 ;
}
F_8 ( V_84 ? 100 : 10 ) ;
if ( V_84 )
F_24 ( V_2 ) ;
return V_77 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_85 , T_2 * V_86 )
{
T_1 V_3 [ 2 ] = { V_85 >> 8 , V_85 & 0xff } ;
T_1 V_87 [ 2 ] = { 0 , 0 } ;
struct V_5 V_6 [ 2 ] = {
{ . V_7 = V_2 -> V_8 . V_7 ,
. V_9 = 0 , . V_3 = & V_3 [ 0 ] , . V_4 = 2 } ,
{ . V_7 = V_2 -> V_8 . V_7 ,
. V_9 = V_88 , . V_3 = & V_87 [ 0 ] , . V_4 = 2 } ,
} ;
if ( F_2 ( V_2 -> V_8 . V_10 , V_6 , 2 ) != 2 ) {
F_3 ( V_12 L_14 ) ;
return - V_13 ;
}
* V_86 = ( V_87 [ 0 ] << 8 ) | V_87 [ 1 ] ;
return 0 ;
}
static void F_25 ( unsigned int type , T_2 V_89 )
{
if ( type & V_90 )
F_3 ( V_91 L_15 ) ;
if ( type & V_92 )
F_3 ( V_91 L_16 ) ;
if ( type & V_93 )
F_3 ( V_91 L_17 ) ;
if ( type & V_94 )
F_3 ( V_91 L_18 ) ;
if ( type & V_95 )
F_3 ( V_91 L_19 ) ;
if ( type & V_96 )
F_3 ( V_91 L_20 ) ;
if ( type & V_80 )
F_3 ( V_91 L_21 ) ;
if ( type & V_97 )
F_3 ( V_91 L_22 ) ;
if ( type & V_81 )
F_3 ( V_91 L_23 ) ;
if ( type & V_82 )
F_3 ( V_91 L_24 ) ;
if ( type & V_83 )
F_3 ( V_91 L_25 ) ;
if ( type & V_79 )
F_3 ( V_91 L_26 ) ;
if ( type & V_98 )
F_3 ( V_91 L_27 ) ;
if ( type & V_99 )
F_3 ( V_91 L_28 ) ;
if ( type & V_100 )
F_3 ( V_91 L_29 ) ;
if ( type & V_101 )
F_3 ( V_91 L_30 ) ;
if ( type & V_102 )
F_3 ( V_91 L_31 ) ;
if ( type & IF )
F_3 ( V_91 L_32 ) ;
if ( type & V_103 )
F_3 ( V_91 L_33 ) ;
if ( type & V_104 )
F_3 ( V_91 L_34 ) ;
if ( type & V_105 )
F_3 ( V_91 L_35 ) ;
if ( type & V_106 )
F_3 ( V_91 L_36 ) ;
if ( type & V_107 )
F_3 ( V_91 L_37 ) ;
if ( type & V_108 )
F_3 ( V_91 L_38 ) ;
if ( type & V_109 )
F_3 ( V_91 L_39 ) ;
if ( type & V_110 )
F_3 ( V_91 L_40 ) ;
if ( type & V_111 )
F_3 ( V_91 L_41 ) ;
if ( type & V_112 )
F_3 ( V_91 L_42 ) ;
if ( type & V_113 )
F_3 ( V_91 L_43 ) ;
if ( type & V_114 )
F_3 ( V_91 L_44 ) ;
if ( type & V_115 )
F_3 ( V_91 L_45 , V_89 ) ;
}
static int F_26 ( struct V_14 * V_15 , unsigned int type ,
T_4 * V_116 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_29 , V_117 = - 1 ;
unsigned int V_118 = 255U ;
if ( ! V_2 -> V_119 ) {
F_3 ( V_12 L_46 ) ;
return - V_24 ;
}
if ( ( ( type & ~ V_114 ) == 0 ) && ( * V_116 == 0 ) )
* V_116 = V_120 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_121 ; V_29 ++ ) {
T_4 V_122 =
( V_2 -> V_119 [ V_29 ] . V_116 ^ ( * V_116 ) ) & ( * V_116 ) ;
unsigned int V_123 =
( V_2 -> V_119 [ V_29 ] . type ^ type )
& ( V_124 | V_125 | V_99 | V_100 | V_101 | V_114 ) ;
unsigned int V_126 ;
if ( V_123
& ( V_90 | V_92 | V_79 | V_80 | V_81 | V_82 | V_83 | V_114 ) )
continue;
V_126 = F_27 ( V_122 ) + F_28 ( V_123 ) ;
if ( ! V_126 )
goto V_77;
if ( V_126 < V_118 ) {
V_118 = V_126 ;
V_117 = V_29 ;
}
}
if ( V_117 < 0 ) {
V_29 = - V_127 ;
goto V_17;
}
if ( V_118 > 0U ) {
F_3 ( V_128
L_47
L_48 ,
V_118 , type , ( unsigned long long ) * V_116 ) ;
V_29 = V_117 ;
}
V_77:
* V_116 = V_2 -> V_119 [ V_29 ] . V_116 ;
V_17:
if ( V_84 ) {
F_3 ( V_129 L_49 ,
( V_29 < 0 ) ? L_50 : L_51 ) ;
F_29 ( type ) ;
F_3 ( V_129 L_52 , type , ( unsigned long long ) * V_116 ) ;
}
return V_29 ;
}
static int F_30 ( struct V_14 * V_15 , unsigned int type ,
T_4 * V_116 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_31 , V_130 ;
unsigned char * V_131 ;
V_31 = F_26 ( V_15 , type , V_116 ) ;
if ( V_31 < 0 )
return V_31 ;
V_131 = V_2 -> V_119 [ V_31 ] . V_132 ;
V_2 -> V_11 = 1 ;
V_130 = F_7 ( V_15 , V_131 ) ;
V_2 -> V_11 = 0 ;
return V_130 ;
}
static int F_31 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
const struct V_133 * V_134 = NULL ;
const unsigned char * V_131 , * V_135 ;
int V_130 = 0 ;
int V_136 , V_137 ;
char V_138 [ 33 ] ;
const char * V_139 ;
if ( V_140 [ 0 ] != '\0' ) {
V_139 = V_140 ;
F_5 ( 1 , L_53 , V_139 ) ;
V_130 = F_32 ( & V_134 , V_139 ,
V_2 -> V_8 . V_10 -> V_141 . V_142 ) ;
} else {
V_139 = V_143 ;
F_5 ( 1 , L_54 , V_139 ) ;
V_130 = F_32 ( & V_134 , V_139 ,
V_2 -> V_8 . V_10 -> V_141 . V_142 ) ;
if ( V_130 == - V_127 ) {
V_139 = V_144 ;
F_5 ( 1 , L_54 , V_139 ) ;
V_130 = F_32 ( & V_134 , V_139 ,
V_2 -> V_8 . V_10 -> V_141 . V_142 ) ;
}
}
if ( V_130 < 0 ) {
if ( V_130 == - V_127 )
F_3 ( V_12 L_55 , V_139 ) ;
else
F_3 ( V_12 L_56 ,
V_130 , V_139 ) ;
return V_130 ;
}
F_5 ( 1 , L_57 , V_139 ) ;
V_131 = V_134 -> V_64 ;
V_135 = V_131 + V_134 -> V_145 ;
if ( V_134 -> V_145 < sizeof( V_138 ) - 1 + 2 + 2 ) {
F_3 ( V_12 L_58 ,
V_139 ) ;
goto V_146;
}
memcpy ( V_138 , V_131 , sizeof( V_138 ) - 1 ) ;
V_138 [ sizeof( V_138 ) - 1 ] = '\0' ;
V_131 += sizeof( V_138 ) - 1 ;
V_2 -> V_147 = F_33 ( V_131 ) ;
V_131 += 2 ;
V_137 = F_33 ( V_131 ) ;
V_131 += 2 ;
F_5 ( 1 , L_59 ,
V_137 , V_139 , V_138 ,
V_2 -> V_147 >> 8 , V_2 -> V_147 & 0xff ) ;
V_2 -> V_119 = F_34 ( V_137 , sizeof( * V_2 -> V_119 ) , V_148 ) ;
if ( V_2 -> V_119 == NULL ) {
F_3 ( V_12 L_60 ) ;
V_130 = - V_149 ;
goto V_150;
}
V_2 -> V_121 = V_137 ;
V_136 = - 1 ;
while ( V_131 < V_135 ) {
T_5 type , V_145 ;
T_4 V_116 ;
T_6 V_89 = 0 ;
V_136 ++ ;
if ( V_136 >= V_137 ) {
F_3 ( V_12 L_61
L_62 ) ;
goto V_146;
}
if ( V_135 - V_131 < sizeof( type ) + sizeof( V_116 ) + sizeof( V_145 ) )
goto V_151;
type = F_35 ( V_131 ) ;
V_131 += sizeof( type ) ;
V_116 = F_36 ( V_131 ) ;
V_131 += sizeof( V_116 ) ;
if ( type & V_115 ) {
V_89 = F_33 ( V_131 ) ;
V_131 += sizeof( V_89 ) ;
if ( V_135 - V_131 < sizeof( V_145 ) )
goto V_151;
}
V_145 = F_35 ( V_131 ) ;
V_131 += sizeof( V_145 ) ;
if ( ! V_145 || V_145 > V_135 - V_131 ) {
F_3 ( V_12 L_63 ,
type , ( unsigned long long ) V_116 ,
( unsigned ) ( V_135 - V_131 ) , V_145 ) ;
goto V_146;
}
V_2 -> V_119 [ V_136 ] . V_132 = F_37 ( V_145 , V_148 ) ;
if ( V_2 -> V_119 [ V_136 ] . V_132 == NULL ) {
F_3 ( V_12 L_60 ) ;
V_130 = - V_149 ;
goto V_150;
}
if ( V_84 ) {
F_3 ( V_129 L_64 ) ;
F_25 ( type , V_89 ) ;
F_3 ( V_129 L_65 ,
type , ( unsigned long long ) V_116 , V_145 ) ;
}
memcpy ( V_2 -> V_119 [ V_136 ] . V_132 , V_131 , V_145 ) ;
V_2 -> V_119 [ V_136 ] . type = type ;
V_2 -> V_119 [ V_136 ] . V_116 = V_116 ;
V_2 -> V_119 [ V_136 ] . V_145 = V_145 ;
V_2 -> V_119 [ V_136 ] . V_89 = V_89 ;
V_131 += V_145 ;
}
if ( V_136 + 1 != V_2 -> V_121 ) {
F_3 ( V_12 L_66 ) ;
goto V_146;
}
goto V_150;
V_151:
F_3 ( V_12 L_67 ) ;
V_146:
V_130 = - V_24 ;
F_3 ( V_12 L_68 ) ;
V_150:
F_38 ( V_134 ) ;
if ( V_130 == 0 )
F_5 ( 1 , L_69 ) ;
return V_130 ;
}
static int F_39 ( struct V_14 * V_15 , unsigned int type ,
T_4 * V_116 , T_6 V_89 , int V_152 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_31 , V_130 ;
unsigned char * V_131 ;
T_1 V_153 [ 13 ] ;
T_1 V_154 [ 5 ] ;
F_5 ( 1 , L_70 , V_18 , V_89 ) ;
if ( ! V_89 ) {
V_31 = F_26 ( V_15 , type , V_116 ) ;
if ( V_31 < 0 )
return V_31 ;
} else {
for ( V_31 = 0 ; V_31 < V_2 -> V_121 ; V_31 ++ ) {
if ( ( V_2 -> V_119 [ V_31 ] . V_89 == V_89 ) &&
( V_2 -> V_119 [ V_31 ] . type & V_115 ) )
break;
}
if ( V_31 == V_2 -> V_121 )
return - V_127 ;
}
V_131 = V_2 -> V_119 [ V_31 ] . V_132 ;
if ( V_2 -> V_119 [ V_31 ] . V_145 != 12 * 16 || V_152 >= 16 )
return - V_24 ;
V_131 += 12 * V_152 ;
if ( V_84 ) {
F_40 ( L_71 ) ;
F_25 ( V_2 -> V_119 [ V_31 ] . type ,
V_2 -> V_119 [ V_31 ] . V_89 ) ;
F_3 ( V_91 L_52 , V_2 -> V_119 [ V_31 ] . type ,
( unsigned long long ) * V_116 ) ;
}
V_153 [ 0 ] = 0x00 ;
memcpy ( & V_153 [ 1 ] , V_131 , 12 ) ;
V_130 = F_6 ( V_2 , V_155 , 0 ) ;
if ( V_130 < 0 ) {
F_3 ( V_12 L_72 ) ;
return - V_156 ;
}
V_130 = F_1 ( V_2 , V_153 , 13 ) ;
if ( V_130 != 0 ) {
F_3 ( V_12 L_73 , V_130 ) ;
}
memset ( V_154 , 0 , sizeof( V_154 ) ) ;
V_154 [ 4 ] = 0x88 ;
F_1 ( V_2 , V_154 , sizeof( V_154 ) ) ;
F_8 ( 10 ) ;
return 0 ;
}
static int F_41 ( struct V_14 * V_15 , unsigned int type ,
T_4 V_157 , T_6 V_89 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_158 V_159 ;
int V_130 = 0 , V_160 = 0 ;
T_2 V_161 ;
T_4 V_162 ;
T_1 V_163 = 0 , V_164 = 0 , V_165 = 0 , V_166 = 0 ;
F_5 ( 1 , L_74 , V_18 ) ;
if ( ! V_2 -> V_119 ) {
V_130 = F_31 ( V_15 ) ;
if ( V_130 < 0 )
return V_130 ;
}
V_167:
V_159 . type = type ;
V_159 . V_116 = V_157 ;
V_159 . V_168 = V_157 ;
V_159 . V_169 = V_114 ;
V_159 . V_170 = 0 ;
V_159 . V_89 = V_89 ;
F_5 ( 1 , L_75 ) ;
if ( V_84 ) {
F_29 ( V_159 . type ) ;
F_3 ( V_91 L_76 , V_159 . type ,
( unsigned long long ) V_159 . V_168 ) ;
if ( ! V_89 )
F_3 ( V_91 L_77 ) ;
else
F_3 ( V_91 L_78 , V_159 . V_89 ) ;
F_3 ( V_91 L_79 , V_159 . V_170 ) ;
}
if ( V_2 -> V_78 . type & V_90 ) {
F_5 ( 1 , L_80 ) ;
goto V_171;
}
memset ( & V_2 -> V_78 , 0 , sizeof( V_2 -> V_78 ) ) ;
V_130 = F_4 ( V_15 ) ;
if ( V_130 < 0 )
goto V_172;
V_162 = 0 ;
V_130 = F_30 ( V_15 , V_90 , & V_162 ) ;
if ( V_130 < 0 ) {
F_3 ( V_12 L_81 , V_130 ) ;
goto V_172;
}
F_5 ( 1 , L_82 ) ;
V_130 = F_30 ( V_15 , V_90 | V_92 , & V_162 ) ;
if ( V_130 == - V_127 )
V_130 = F_30 ( V_15 , V_90 | V_92 , & V_162 ) ;
if ( V_130 < 0 && V_130 != - V_127 ) {
F_42 ( L_83 ,
V_130 ) ;
goto V_172;
}
V_171:
if ( V_2 -> V_78 . type == ( V_90 | V_159 . type ) &&
V_2 -> V_78 . V_168 == V_157 ) {
F_5 ( 1 , L_84 ) ;
goto V_173;
}
V_2 -> V_78 . V_169 = 0 ;
V_130 = F_30 ( V_15 , V_159 . type , & V_159 . V_116 ) ;
if ( V_130 < 0 )
goto V_172;
V_173:
if ( V_2 -> V_78 . V_169 == V_159 . V_169 &&
V_2 -> V_78 . V_170 == V_159 . V_170 ) {
F_5 ( 1 , L_85 ) ;
goto V_174;
}
V_130 = F_39 ( V_15 , V_159 . type | V_159 . V_169 , & V_159 . V_116 ,
V_159 . V_89 , V_159 . V_170 ) ;
if ( V_130 != 0 )
F_5 ( 1 , L_86 , V_130 ) ;
V_174:
V_130 = F_13 ( V_2 , V_175 , & V_161 ) ;
if ( F_16 ( V_2 , & V_163 , & V_164 , & V_165 ,
& V_166 ) != 0 ) {
F_3 ( V_12 L_87 ) ;
goto V_172;
}
F_5 ( 1 , L_88
L_89 ,
V_161 , V_163 , V_164 , V_165 , V_166 ) ;
if ( V_2 -> V_147 != ( ( V_165 << 8 ) | V_166 ) ) {
F_3 ( V_128
L_90 ,
V_165 , V_166 ) ;
goto V_172;
}
if ( V_2 -> V_161 == 0 &&
( V_161 == V_176 ||
V_161 == V_177 ) ) {
V_2 -> V_161 = V_161 ;
V_2 -> V_178 = ( V_163 << 8 ) | V_164 ;
} else if ( V_2 -> V_161 == 0 || V_2 -> V_161 != V_161 ||
V_2 -> V_178 != ( ( V_163 << 8 ) | V_164 ) ) {
F_3 ( V_128
L_91
L_92 ) ;
goto V_172;
}
V_2 -> V_78 = V_159 ;
V_2 -> V_78 . type |= V_90 ;
return 0 ;
V_172:
memset ( & V_2 -> V_78 , 0 , sizeof( V_2 -> V_78 ) ) ;
if ( ! V_160 ) {
F_8 ( 50 ) ;
V_160 = 1 ;
F_5 ( 1 , L_93 ) ;
goto V_167;
}
if ( V_130 == - V_127 )
V_130 = - V_24 ;
return V_130 ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_2 V_52 ;
T_3 V_54 = 0 ;
T_2 V_58 ;
T_3 V_66 = 0 ;
T_2 V_68 ;
T_2 V_70 ;
T_2 signal = 0 ;
T_2 V_73 = 0 ;
T_1 V_60 = 0 , V_61 = 0 ;
T_1 V_62 = 0 , V_63 = 0 ;
F_12 ( V_2 , & V_52 ) ;
F_5 ( 1 , L_94 , V_52 ) ;
F_14 ( V_2 , & V_54 ) ;
F_5 ( 1 , L_95 , V_54 ) ;
F_15 ( V_2 , & V_58 ) ;
F_5 ( 1 , L_96 ,
V_58 ) ;
F_16 ( V_2 , & V_60 , & V_61 ,
& V_62 , & V_63 ) ;
F_5 ( 1 , L_97 ,
V_60 , V_61 ,
V_62 , V_63 ) ;
if ( V_2 -> V_37 < V_179 ) {
F_17 ( V_2 , & V_66 ) ;
F_5 ( 1 , L_98 ,
V_66 ) ;
F_18 ( V_2 , & V_68 ) ;
F_5 ( 1 , L_99 , V_68 ) ;
}
F_19 ( V_2 , & V_70 ) ;
F_5 ( 1 , L_100 , V_70 ) ;
F_20 ( V_2 , & signal ) ;
F_5 ( 1 , L_101 , signal >> 8 , signal ) ;
F_21 ( V_2 , & V_73 ) ;
F_5 ( 1 , L_102 , V_73 >> 8 , V_73 ) ;
}
static int F_43 ( struct V_14 * V_15 )
{
struct V_180 * V_181 = & V_15 -> V_182 ;
T_3 V_183 = V_181 -> V_184 ;
T_3 V_185 = V_181 -> V_186 ;
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned int type ;
int V_17 = - V_13 ;
F_5 ( 1 , L_103 , V_18 , V_181 -> V_187 ) ;
F_44 ( & V_2 -> V_188 ) ;
switch ( V_183 ) {
case V_189 :
F_5 ( 1 , L_104 , V_18 ) ;
V_2 -> V_41 = V_42 ;
V_2 -> V_190 = 1750000 ;
V_2 -> V_37 = V_179 ;
type = V_80 ;
break;
case V_191 :
F_5 ( 1 , L_105 , V_18 ) ;
V_2 -> V_41 = V_43 ;
V_2 -> V_190 = 1750000 ;
V_2 -> V_37 = V_179 ;
type = V_80 ;
break;
case V_192 :
case V_193 :
F_5 ( 1 , L_106 , V_18 ) ;
if ( V_185 == 0 ) {
if ( V_181 -> V_187 < 400000000 ) {
V_2 -> V_190 = 2250000 ;
} else {
V_2 -> V_190 = 2750000 ;
}
V_2 -> V_37 = V_194 ;
type = V_82 ;
} else if ( V_185 <= 6000000 ) {
V_2 -> V_37 = V_179 ;
V_2 -> V_190 = 1750000 ;
type = V_80 ;
} else if ( V_185 <= 7000000 ) {
V_2 -> V_37 = V_195 ;
V_2 -> V_190 = 2250000 ;
type = V_81 ;
} else {
V_2 -> V_37 = V_196 ;
V_2 -> V_190 = 2750000 ;
type = V_83 ;
}
V_2 -> V_41 = V_42 ;
break;
default:
F_3 ( V_12 L_107 ) ;
V_17 = - V_24 ;
goto V_172;
}
V_2 -> V_45 = V_181 -> V_187 - V_2 -> V_190 ;
F_5 ( 1 , L_108 ,
V_18 , V_2 -> V_45 ) ;
if ( F_41 ( V_15 , type , 0 , V_2 -> V_197 ) != 0 )
goto V_172;
V_2 -> V_198 = V_181 -> V_186 ;
V_17 = F_10 ( V_2 , V_2 -> V_41 ) ;
if ( V_17 != 0 ) {
F_3 ( V_12 L_109 ,
V_2 -> V_41 ) ;
goto V_172;
} else {
T_2 V_34 , V_35 ;
V_34 = V_36 [ V_2 -> V_37 ] . V_34 ;
V_35 = V_36 [ V_2 -> V_37 ] . V_35 ;
if ( type == V_80 && V_2 -> V_147 != 0x0102 )
V_34 |= 0x0001 ;
V_17 = F_9 ( V_2 , V_34 , V_35 ) ;
if ( V_17 != 0 ) {
F_3 ( V_12 L_110 ) ;
}
}
if ( F_6 ( V_2 , V_199 , 0 ) == 0 )
V_17 = 0 ;
if ( V_2 -> V_200 != 0 ) {
if ( F_6 ( V_2 , V_201 ,
( V_2 -> V_147 != 0x0102 ||
V_2 -> V_200 != 134 ?
V_2 -> V_200 : 132 ) ) != 0 )
V_17 = - V_13 ;
}
if ( V_2 -> V_202 != 0 ) {
if ( F_6 ( V_2 , V_203 , 1 ) != 0 )
V_17 = - V_13 ;
}
if ( V_17 != 0 ) {
F_3 ( V_12 L_111 ) ;
}
F_23 ( V_2 , V_2 -> V_45 ) ;
V_17 = 0 ;
V_172:
F_45 ( & V_2 -> V_188 ) ;
return V_17 ;
}
static int F_46 ( struct V_14 * V_15 ,
struct V_204 * V_205 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned int type = 0 ;
int V_17 = - V_13 ;
if ( V_205 -> V_206 == V_207 ) {
F_5 ( 1 , L_112 ,
V_18 , V_205 -> V_187 ) ;
F_44 ( & V_2 -> V_188 ) ;
V_205 -> V_157 = 0 ;
V_2 -> V_45 = V_205 -> V_187 * 125L / 2 ;
if ( V_208 & V_209 ) {
V_2 -> V_37 = V_210 ;
type = V_79 | V_98 ;
} else {
V_2 -> V_37 = V_211 ;
type = V_79 | V_113 ;
}
goto V_212;
}
F_5 ( 1 , L_113 ,
V_18 , V_205 -> V_187 ) ;
F_44 ( & V_2 -> V_188 ) ;
V_2 -> V_45 = V_205 -> V_187 * 62500 ;
V_205 -> V_157 &= V_213 ;
if ( ! V_205 -> V_157 )
V_205 -> V_157 = V_214 ;
if ( V_208 & V_215 )
type = V_101 ;
if ( V_205 -> V_157 & V_216 ) {
V_205 -> V_157 = V_216 ;
if ( V_208 & V_215 ) {
V_2 -> V_37 = V_217 ;
} else if ( V_208 & V_218 ) {
V_205 -> V_157 |= V_219 ;
V_2 -> V_37 = V_220 ;
} else {
V_205 -> V_157 |= V_221 ;
V_2 -> V_37 = V_222 ;
}
goto V_212;
}
if ( V_205 -> V_157 & V_214 ) {
V_205 -> V_157 = V_214 ;
if ( V_208 & V_215 ) {
V_2 -> V_37 = V_223 ;
} else if ( ! ( V_208 & V_218 ) ) {
if ( ! ( V_208 & V_224 ) ) {
V_205 -> V_157 |= V_225 ;
V_2 -> V_37 = V_226 ;
} else {
V_205 -> V_157 |= V_227 ;
V_2 -> V_37 = V_226 ;
}
} else {
if ( ! ( V_208 & V_224 ) ) {
V_205 -> V_157 |= V_228 ;
V_2 -> V_37 = V_229 ;
} else {
V_205 -> V_157 |= V_230 ;
V_2 -> V_37 = V_229 ;
}
}
goto V_212;
}
if ( V_205 -> V_157 & V_231 ) {
V_205 -> V_157 = V_231 | V_232 ;
if ( V_208 & V_215 )
V_2 -> V_37 = V_233 ;
else
V_2 -> V_37 = V_234 ;
goto V_212;
}
if ( V_205 -> V_157 & V_235 ) {
V_205 -> V_157 = V_235 ;
if ( V_208 & V_215 ) {
V_2 -> V_37 = V_236 ;
} else if ( V_208 & V_218 ) {
V_205 -> V_157 |= V_219 ;
V_2 -> V_37 = V_237 ;
} else {
V_205 -> V_157 |= V_232 ;
V_2 -> V_37 = V_238 ;
}
goto V_212;
}
if ( V_205 -> V_157 & V_239 ) {
V_205 -> V_157 = V_239 | V_219 ;
if ( V_208 & V_240 ) {
type = 0 ;
V_2 -> V_37 = V_241 ;
} else if ( V_208 & V_215 ) {
V_2 -> V_37 = V_242 ;
} else if ( V_208 & V_243 ) {
V_205 -> V_157 |= V_244 ;
V_2 -> V_37 = V_245 ;
} else {
V_2 -> V_37 = V_246 ;
}
goto V_212;
}
if ( V_205 -> V_157 & V_247 ) {
type = 0 ;
V_205 -> V_157 = V_247 | V_232 ;
V_2 -> V_37 = V_248 ;
goto V_212;
}
if ( V_205 -> V_157 & V_249 ) {
type = 0 ;
V_205 -> V_157 = V_249 | V_232 ;
V_2 -> V_37 = V_250 ;
goto V_212;
}
V_212:
V_2 -> V_41 = V_43 ;
if ( F_41 ( V_15 , type , V_205 -> V_157 ,
V_36 [ V_2 -> V_37 ] . V_89 ) != 0 )
goto V_172;
V_17 = F_10 ( V_2 , V_2 -> V_41 ) ;
if ( V_17 != 0 ) {
F_3 ( V_12
L_109 ,
V_2 -> V_41 ) ;
goto V_172;
} else {
T_2 V_34 , V_35 ;
V_34 = V_36 [ V_2 -> V_37 ] . V_34 ;
V_35 = V_36 [ V_2 -> V_37 ] . V_35 ;
if ( V_2 -> V_37 < V_229 ) {
if ( type & V_100 )
V_34 &= 0xFF7F ;
} else if ( V_2 -> V_37 < V_234 ) {
if ( V_2 -> V_147 == 0x0102 )
V_34 &= 0xFEFF ;
if ( V_208 & V_224 )
V_34 |= 0x0080 ;
}
V_17 = F_9 ( V_2 , V_34 , V_35 ) ;
if ( V_17 != 0 ) {
F_3 ( V_12 L_110 ) ;
goto V_172;
}
}
if ( F_6 ( V_2 , V_199 , 0 ) == 0 )
V_17 = 0 ;
if ( F_6 ( V_2 , V_201 , 1 ) != 0 )
V_17 = - V_13 ;
if ( V_2 -> V_202 != 0 ) {
if ( F_6 ( V_2 , V_203 , 1 ) != 0 )
V_17 = - V_13 ;
}
if ( V_17 != 0 ) {
F_3 ( V_12 L_111 ) ;
goto V_172;
}
F_23 ( V_2 , V_2 -> V_45 ) ;
V_17 = 0 ;
V_172:
F_45 ( & V_2 -> V_188 ) ;
return V_17 ;
}
static int F_47 ( struct V_14 * V_15 , T_2 * V_251 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
T_2 V_252 = 0 ;
int V_130 ;
F_44 ( & V_2 -> V_188 ) ;
V_130 = F_13 ( V_2 , V_72 , & V_252 ) ;
F_45 ( & V_2 -> V_188 ) ;
if ( V_130 < 0 )
goto V_17;
F_48 ( L_114 , V_252 >> 8 , V_252 ) ;
if ( ( V_2 -> V_37 == V_179 ) ||
( V_2 -> V_37 == V_195 ) ||
( V_2 -> V_37 == V_194 ) ||
( V_2 -> V_37 == V_196 ) )
goto V_253;
F_44 ( & V_2 -> V_188 ) ;
V_130 = F_13 ( V_2 , V_74 , & V_252 ) ;
F_45 ( & V_2 -> V_188 ) ;
F_48 ( L_115 , V_252 >> 8 , V_252 ) ;
if ( V_252 >= 0x2000 ) {
V_252 = 0 ;
} else {
V_252 = ( ~ V_252 << 3 ) & 0xffff ;
}
goto V_17;
V_253:
if ( V_252 <= 0x3200 ) {
V_252 = 0xffff ;
} else if ( V_252 >= 0x713A ) {
V_252 = 0 ;
} else {
V_252 = ~ ( V_252 - 0x3200 ) << 2 ;
}
V_17:
* V_251 = V_252 ;
return V_130 ;
}
static int F_49 ( struct V_14 * V_15 , T_3 * V_254 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
* V_254 = V_2 -> V_45 + V_2 -> V_190 ;
if ( V_84 ) {
F_44 ( & V_2 -> V_188 ) ;
if ( ( V_2 -> V_78 . type
& ( V_90 | V_79 | V_80 | V_81 | V_82 | V_83 ) ) == V_90 ) {
T_2 V_255 = 0 ;
if ( F_13 ( V_2 , V_256 , & V_255 ) == 0 ) {
F_45 ( & V_2 -> V_188 ) ;
F_5 ( 1 , L_116 ,
V_18 , * V_254 , V_255 ) ;
return 0 ;
}
}
F_45 ( & V_2 -> V_188 ) ;
}
F_5 ( 1 , L_3 , V_18 ) ;
return 0 ;
}
static int F_50 ( struct V_14 * V_15 , T_3 * V_185 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
F_5 ( 1 , L_3 , V_18 ) ;
* V_185 = V_2 -> V_198 ;
return 0 ;
}
static int F_51 ( struct V_14 * V_15 , T_3 * V_257 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
T_2 V_58 = 0 ;
F_44 ( & V_2 -> V_188 ) ;
if ( V_2 -> V_78 . type & V_90 )
F_15 ( V_2 , & V_58 ) ;
* V_257 = ( V_58 == 1 ?
V_258 | V_259 : 0 ) ;
if ( V_2 -> V_78 . type & ( V_80 | V_81 | V_82 | V_83 ) )
* V_257 &= ( ~ V_259 ) ;
F_45 ( & V_2 -> V_188 ) ;
F_5 ( 2 , L_117 , V_18 , V_58 ) ;
return 0 ;
}
static int F_52 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_17 = 0 ;
F_5 ( 1 , L_3 , V_18 ) ;
F_44 ( & V_2 -> V_188 ) ;
if ( ( V_260 == 2 ||
( V_260 == 0 && V_2 -> V_261 != 0 ) ) &&
( V_2 -> V_78 . type & V_90 ) != 0 ) {
V_2 -> V_78 . type = V_262 ;
if ( F_6 ( V_2 , V_263 , 0 ) != 0 ) {
F_3 ( V_12
L_118 ,
V_18 ) ;
V_17 = - V_13 ;
}
F_8 ( 20 ) ;
}
F_45 ( & V_2 -> V_188 ) ;
return V_17 ;
}
static int F_53 ( struct V_14 * V_15 )
{
F_5 ( 1 , L_3 , V_18 ) ;
return 0 ;
}
static int F_54 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
F_5 ( 1 , L_3 , V_18 ) ;
F_44 ( & V_264 ) ;
if ( V_2 )
F_55 ( V_2 ) ;
F_45 ( & V_264 ) ;
V_15 -> V_16 = NULL ;
return 0 ;
}
struct V_14 * F_56 ( struct V_14 * V_15 ,
struct V_265 * V_266 ,
struct V_267 * V_268 )
{
struct V_1 * V_2 = NULL ;
int V_269 ;
T_2 V_116 = 0 ;
F_5 ( 1 , L_119 , V_18 ,
V_266 ? F_57 ( V_266 ) : - 1 ,
V_268 ? V_268 -> V_270 : - 1 ) ;
F_44 ( & V_264 ) ;
V_269 = F_58 ( struct V_1 , V_2 ,
V_271 ,
V_266 , V_268 -> V_270 , L_120 ) ;
switch ( V_269 ) {
case 0 :
goto V_172;
case 1 :
V_2 -> V_198 = 6000000 ;
V_2 -> V_197 = 4560 ;
V_2 -> V_261 = 0 ;
V_2 -> V_200 = 134 ;
V_2 -> V_202 = 1 ;
F_59 ( & V_2 -> V_188 ) ;
V_15 -> V_16 = V_2 ;
break;
default:
V_15 -> V_16 = V_2 ;
break;
}
if ( V_268 -> V_197 != 0 ) {
V_2 -> V_197 = V_268 -> V_197 ;
V_2 -> V_261 = V_268 -> V_261 ;
V_2 -> V_200 = V_268 -> V_200 ;
V_2 -> V_202 = V_268 -> V_202 ;
}
if ( V_269 == 1 ) {
if ( F_13 ( V_2 , V_175 , & V_116 ) != 0 )
goto V_172;
} else {
V_116 = ( ( V_2 -> V_78 . type & V_90 ) != 0 ?
V_2 -> V_161 : V_272 ) ;
}
switch ( V_116 ) {
case V_176 :
case V_177 :
F_3 ( V_273
L_121 ,
V_268 -> V_270 ) ;
F_3 ( V_273
L_122 ) ;
break;
case V_272 :
F_3 ( V_273
L_121 ,
V_268 -> V_270 ) ;
F_3 ( V_273
L_123 ) ;
break;
default:
F_3 ( V_12
L_124 ,
V_268 -> V_270 , V_116 ) ;
goto V_172;
}
F_45 ( & V_264 ) ;
memcpy ( & V_15 -> V_274 . V_275 , & V_47 ,
sizeof( struct V_276 ) ) ;
if ( V_269 == 1 ) {
int V_17 ;
F_44 ( & V_2 -> V_188 ) ;
V_17 = F_31 ( V_15 ) ;
F_45 ( & V_2 -> V_188 ) ;
if ( V_17 != 0 )
goto V_277;
}
return V_15 ;
V_172:
F_45 ( & V_264 ) ;
V_277:
F_54 ( V_15 ) ;
return NULL ;
}
