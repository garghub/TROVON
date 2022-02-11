int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
static inline void F_7 ( struct V_6 * V_7 ) {}
const char * F_8 ( T_1 V_8 )
{
static char * V_9 [ 7 ] = {
L_1 , L_2 , L_3 , L_4 , L_5 , L_6 , L_7 ,
} ;
static unsigned char V_10 [] = {
0x07 , 0x08 ,
0x17 , 0x18 , 0x19 ,
0x37 , 0x38
} ;
static char * V_11 [] = {
L_8 , L_9 ,
L_10 , L_11 , L_12 ,
L_13 , L_14
} ;
int V_12 ;
V_8 = ( V_8 & V_13 ) >> V_14 ;
if ( ( V_8 & 0x0f ) < 7 )
return V_9 [ V_8 & 0x0f ] ;
for ( V_12 = 0 ; V_12 < F_9 ( V_10 ) ; V_12 ++ ) {
if ( V_8 == V_10 [ V_12 ] )
return V_11 [ V_12 ] ;
}
return L_15 ;
}
const char * F_10 ( T_1 V_8 )
{
static char * V_15 [ 4 ] = { L_16 , L_17 , L_18 , L_19 } ;
return V_15 [ ( V_8 >> ( V_14 + 4 ) ) & 3 ] ;
}
const char * F_11 ( T_1 V_8 )
{
static char * V_16 [ 16 ] = {
L_20 , L_21 , L_22 , L_23 ,
L_24 , L_25 , L_26 , L_27 ,
L_28 , L_29 , L_30 , L_31 ,
L_32 , L_33 , L_34 , L_35
} ;
return V_16 [ ( V_8 & V_17 )
>> V_18 ] ;
}
static inline unsigned int
F_12 ( struct V_6 * V_7 , T_2 V_19 , int V_20 ,
unsigned int V_21 , unsigned int V_22 )
{
T_1 V_23 ;
if ( ( V_7 -> V_24 & ~ 0xf ) || ( V_20 & ~ 1 ) || ( V_19 & ~ 0x7f ) ||
( V_21 & ~ 0xfff ) || ( V_22 & ~ 0xffff ) ) {
F_13 ( V_25 L_36 ,
V_7 -> V_24 , V_20 , V_19 , V_21 , V_22 ) ;
return ~ 0 ;
}
V_23 = ( T_1 ) V_7 -> V_24 << 28 ;
V_23 |= ( T_1 ) V_20 << 27 ;
V_23 |= ( T_1 ) V_19 << 20 ;
V_23 |= V_21 << 8 ;
V_23 |= V_22 ;
return V_23 ;
}
static int F_14 ( struct V_6 * V_7 , unsigned int V_26 ,
unsigned int * V_27 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
int V_30 ;
if ( V_26 == ~ 0 )
return - 1 ;
if ( V_27 )
* V_27 = - 1 ;
V_31:
F_15 ( V_7 ) ;
F_2 ( & V_29 -> V_32 ) ;
F_16 ( V_7 , V_26 ) ;
V_30 = V_29 -> V_33 . V_34 ( V_29 , V_26 ) ;
if ( ! V_30 && V_27 ) {
* V_27 = V_29 -> V_33 . V_35 ( V_29 , V_7 -> V_24 ) ;
F_17 ( V_7 , * V_27 ) ;
}
F_4 ( & V_29 -> V_32 ) ;
F_18 ( V_7 ) ;
if ( V_27 && * V_27 == - 1 && V_29 -> V_36 ) {
if ( V_29 -> V_37 ) {
F_19 ( L_37
L_38 ) ;
F_20 ( V_29 ) ;
V_29 -> V_33 . V_38 ( V_29 ) ;
}
goto V_31;
}
if ( ! V_30 )
V_29 -> V_37 = 0 ;
return V_30 ;
}
unsigned int F_21 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 ,
unsigned int V_21 , unsigned int V_22 )
{
unsigned V_26 = F_12 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
unsigned int V_27 ;
if ( F_14 ( V_7 , V_26 , & V_27 ) )
return - 1 ;
return V_27 ;
}
int F_22 ( struct V_6 * V_7 , T_2 V_19 , int V_20 ,
unsigned int V_21 , unsigned int V_22 )
{
unsigned int V_26 = F_12 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
unsigned int V_27 ;
return F_14 ( V_7 , V_26 ,
V_7 -> V_29 -> V_39 ? & V_27 : NULL ) ;
}
void F_23 ( struct V_6 * V_7 , const struct V_40 * V_41 )
{
for (; V_41 -> V_19 ; V_41 ++ )
F_22 ( V_7 , V_41 -> V_19 , 0 , V_41 -> V_21 , V_41 -> V_42 ) ;
}
int F_24 ( struct V_6 * V_7 , T_2 V_19 ,
T_2 * V_43 )
{
unsigned int V_22 ;
V_22 = F_25 ( V_7 , V_19 , V_44 ) ;
if ( V_22 == - 1 )
return 0 ;
* V_43 = ( V_22 >> 16 ) & 0x7fff ;
return ( int ) ( V_22 & 0x7fff ) ;
}
static T_2 * F_26 ( struct V_45 * V_46 , T_2 V_19 )
{
int V_12 , V_47 ;
for ( V_12 = 0 ; V_12 < V_46 -> V_48 ; ) {
T_2 * V_49 = F_27 ( V_46 , V_12 ) ;
if ( V_19 == * V_49 )
return V_49 ;
V_47 = V_49 [ 1 ] ;
V_12 += V_47 + 2 ;
}
return NULL ;
}
int F_28 ( struct V_6 * V_7 , T_2 V_19 ,
const T_2 * * V_50 )
{
struct V_45 * V_46 = & V_7 -> V_51 ;
int V_47 , V_30 ;
T_2 V_4 [ V_52 ] ;
T_2 * V_49 ;
bool V_53 = false ;
V_31:
V_49 = F_26 ( V_46 , V_19 ) ;
if ( V_49 ) {
if ( V_50 )
* V_50 = V_49 + 2 ;
return V_49 [ 1 ] ;
}
if ( F_29 ( V_53 ) )
return - V_54 ;
V_47 = F_30 ( V_7 , V_19 , V_4 , V_52 ) ;
if ( V_47 < 0 )
return V_47 ;
V_30 = F_31 ( V_7 , V_19 , V_47 , V_4 ) ;
if ( V_30 < 0 )
return V_30 ;
V_53 = true ;
goto V_31;
}
int F_32 ( struct V_6 * V_7 , T_2 V_19 ,
T_2 * V_55 , int V_56 )
{
const T_2 * V_4 ;
int V_47 = F_28 ( V_7 , V_19 , & V_4 ) ;
if ( V_47 <= 0 )
return V_47 ;
if ( V_47 > V_56 ) {
F_33 ( V_25 L_39
L_40 ,
V_47 , V_19 ) ;
return - V_54 ;
}
memcpy ( V_55 , V_4 , V_47 * sizeof( T_2 ) ) ;
return V_47 ;
}
int F_30 ( struct V_6 * V_7 , T_2 V_19 ,
T_2 * V_55 , int V_56 )
{
unsigned int V_22 ;
int V_12 , V_57 , V_58 ;
unsigned int V_59 , V_60 , V_61 ;
unsigned int V_62 ;
T_2 V_63 ;
if ( F_29 ( ! V_55 || V_56 <= 0 ) )
return - V_54 ;
V_62 = F_34 ( V_7 , V_19 ) ;
if ( ! ( V_62 & V_64 ) &&
F_35 ( V_62 ) != V_65 )
return 0 ;
V_22 = F_25 ( V_7 , V_19 , V_66 ) ;
if ( V_22 & V_67 ) {
V_59 = 16 ;
V_60 = 2 ;
} else {
V_59 = 8 ;
V_60 = 4 ;
}
V_57 = V_22 & V_68 ;
V_61 = ( 1 << ( V_59 - 1 ) ) - 1 ;
if ( ! V_57 )
return 0 ;
if ( V_57 == 1 ) {
V_22 = F_21 ( V_7 , V_19 , 0 ,
V_69 , 0 ) ;
if ( V_22 == - 1 && V_7 -> V_29 -> V_36 )
return - V_70 ;
V_55 [ 0 ] = V_22 & V_61 ;
return 1 ;
}
V_58 = 0 ;
V_63 = 0 ;
for ( V_12 = 0 ; V_12 < V_57 ; V_12 ++ ) {
int V_71 ;
T_2 V_23 , V_72 ;
if ( V_12 % V_60 == 0 ) {
V_22 = F_21 ( V_7 , V_19 , 0 ,
V_69 , V_12 ) ;
if ( V_22 == - 1 && V_7 -> V_29 -> V_36 )
return - V_70 ;
}
V_71 = ! ! ( V_22 & ( 1 << ( V_59 - 1 ) ) ) ;
V_23 = V_22 & V_61 ;
if ( V_23 == 0 ) {
F_33 ( V_73 L_39
L_41 ,
V_19 , V_12 , V_22 ) ;
return 0 ;
}
V_22 >>= V_59 ;
if ( V_71 ) {
if ( ! V_63 || V_63 >= V_23 ) {
F_33 ( V_73 L_39
L_42 ,
V_63 , V_23 ) ;
continue;
}
for ( V_72 = V_63 + 1 ; V_72 <= V_23 ; V_72 ++ ) {
if ( V_58 >= V_56 ) {
F_33 ( V_25 L_39
L_40 ,
V_58 , V_19 ) ;
return - V_54 ;
}
V_55 [ V_58 ++ ] = V_72 ;
}
} else {
if ( V_58 >= V_56 ) {
F_33 ( V_25 L_39
L_40 ,
V_58 , V_19 ) ;
return - V_54 ;
}
V_55 [ V_58 ++ ] = V_23 ;
}
V_63 = V_23 ;
}
return V_58 ;
}
static bool F_36 ( struct V_45 * V_46 , T_2 V_19 )
{
T_2 * V_49 = F_37 ( V_46 ) ;
if ( ! V_49 )
return false ;
* V_49 = V_19 ;
return true ;
}
int F_31 ( struct V_6 * V_7 , T_2 V_19 , int V_47 ,
const T_2 * V_4 )
{
struct V_45 * V_46 = & V_7 -> V_51 ;
T_2 * V_49 ;
int V_12 , V_74 ;
V_49 = F_26 ( V_46 , V_19 ) ;
if ( V_49 )
* V_49 = - 1 ;
V_74 = V_46 -> V_48 ;
if ( ! F_36 ( V_46 , V_19 ) || ! F_36 ( V_46 , V_47 ) )
goto V_75;
for ( V_12 = 0 ; V_12 < V_47 ; V_12 ++ )
if ( ! F_36 ( V_46 , V_4 [ V_12 ] ) )
goto V_75;
return 0 ;
V_75:
V_46 -> V_48 = V_74 ;
return - V_76 ;
}
int F_38 ( struct V_6 * V_7 , T_2 V_77 ,
T_2 V_19 , int V_78 )
{
T_2 V_79 [ V_80 ] ;
int V_12 , V_81 ;
V_81 = F_32 ( V_7 , V_77 , V_79 , F_9 ( V_79 ) ) ;
for ( V_12 = 0 ; V_12 < V_81 ; V_12 ++ )
if ( V_79 [ V_12 ] == V_19 )
return V_12 ;
if ( ! V_78 )
return - 1 ;
if ( V_78 > 5 ) {
F_19 ( L_43 , V_19 ) ;
return - 1 ;
}
V_78 ++ ;
for ( V_12 = 0 ; V_12 < V_81 ; V_12 ++ ) {
unsigned int type = F_35 ( F_34 ( V_7 , V_79 [ V_12 ] ) ) ;
if ( type == V_82 || type == V_83 )
continue;
if ( F_38 ( V_7 , V_79 [ V_12 ] , V_19 , V_78 ) >= 0 )
return V_12 ;
}
return - 1 ;
}
int F_39 ( struct V_28 * V_29 , T_1 V_27 , T_1 V_84 )
{
struct V_85 * V_86 ;
unsigned int V_87 ;
F_40 ( V_29 , V_27 , V_84 ) ;
V_86 = V_29 -> V_86 ;
if ( ! V_86 )
return 0 ;
V_87 = ( V_86 -> V_87 + 1 ) % V_88 ;
V_86 -> V_87 = V_87 ;
V_87 <<= 1 ;
V_86 -> V_89 [ V_87 ] = V_27 ;
V_86 -> V_89 [ V_87 + 1 ] = V_84 ;
F_41 ( V_29 -> V_90 , & V_86 -> V_91 ) ;
return 0 ;
}
static void F_42 ( struct V_92 * V_91 )
{
struct V_85 * V_86 =
F_43 ( V_91 , struct V_85 , V_91 ) ;
struct V_28 * V_29 = V_86 -> V_29 ;
struct V_6 * V_7 ;
unsigned int V_93 , V_94 , V_27 ;
while ( V_86 -> V_93 != V_86 -> V_87 ) {
V_93 = ( V_86 -> V_93 + 1 ) % V_88 ;
V_86 -> V_93 = V_93 ;
V_93 <<= 1 ;
V_27 = V_86 -> V_89 [ V_93 ] ;
V_94 = V_86 -> V_89 [ V_93 + 1 ] ;
if ( ! ( V_94 & ( 1 << 4 ) ) )
continue;
V_7 = V_29 -> V_95 [ V_94 & 0x0f ] ;
if ( V_7 && V_7 -> V_96 . V_97 )
V_7 -> V_96 . V_97 ( V_7 , V_27 ) ;
}
}
static int F_44 ( struct V_28 * V_29 )
{
struct V_85 * V_86 ;
if ( V_29 -> V_86 )
return 0 ;
V_86 = F_45 ( sizeof( * V_86 ) , V_98 ) ;
if ( ! V_86 ) {
F_33 ( V_25 L_39
L_44 ) ;
return - V_76 ;
}
F_46 ( & V_86 -> V_91 , F_42 ) ;
V_86 -> V_29 = V_29 ;
V_29 -> V_86 = V_86 ;
return 0 ;
}
static int F_47 ( struct V_28 * V_29 )
{
struct V_6 * V_7 , * V_72 ;
if ( ! V_29 )
return 0 ;
if ( V_29 -> V_90 )
F_48 ( V_29 -> V_90 ) ;
if ( V_29 -> V_86 )
F_49 ( V_29 -> V_86 ) ;
F_50 (codec, n, &bus->codec_list, list) {
F_51 ( V_7 ) ;
}
if ( V_29 -> V_33 . V_99 )
V_29 -> V_33 . V_99 ( V_29 ) ;
if ( V_29 -> V_90 )
F_52 ( V_29 -> V_90 ) ;
F_49 ( V_29 ) ;
return 0 ;
}
static int F_53 ( struct V_100 * V_101 )
{
struct V_28 * V_29 = V_101 -> V_102 ;
V_29 -> V_103 = 1 ;
return F_47 ( V_29 ) ;
}
static int F_54 ( struct V_100 * V_101 )
{
struct V_28 * V_29 = V_101 -> V_102 ;
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
F_56 ( V_7 ) ;
F_57 ( V_7 ) ;
}
return 0 ;
}
int F_58 ( struct V_104 * V_105 ,
const struct V_106 * V_107 ,
struct V_28 * * V_108 )
{
struct V_28 * V_29 ;
int V_30 ;
static struct V_109 V_110 = {
. V_111 = F_54 ,
. V_112 = F_53 ,
} ;
if ( F_29 ( ! V_107 ) )
return - V_54 ;
if ( F_29 ( ! V_107 -> V_33 . V_34 || ! V_107 -> V_33 . V_35 ) )
return - V_54 ;
if ( V_108 )
* V_108 = NULL ;
V_29 = F_45 ( sizeof( * V_29 ) , V_98 ) ;
if ( V_29 == NULL ) {
F_33 ( V_25 L_45 ) ;
return - V_76 ;
}
V_29 -> V_105 = V_105 ;
V_29 -> V_113 = V_107 -> V_113 ;
V_29 -> V_114 = V_107 -> V_114 ;
V_29 -> V_115 = V_107 -> V_115 ;
V_29 -> V_116 = V_107 -> V_116 ;
V_29 -> V_33 = V_107 -> V_33 ;
F_59 ( & V_29 -> V_32 ) ;
F_59 ( & V_29 -> V_117 ) ;
F_60 ( & V_29 -> V_118 ) ;
snprintf ( V_29 -> V_119 , sizeof( V_29 -> V_119 ) ,
L_46 , V_105 -> V_120 ) ;
V_29 -> V_90 = F_61 ( V_29 -> V_119 ) ;
if ( ! V_29 -> V_90 ) {
F_33 ( V_25 L_47 ,
V_29 -> V_119 ) ;
F_49 ( V_29 ) ;
return - V_76 ;
}
V_30 = F_62 ( V_105 , V_121 , V_29 , & V_110 ) ;
if ( V_30 < 0 ) {
F_47 ( V_29 ) ;
return V_30 ;
}
if ( V_108 )
* V_108 = V_29 ;
return 0 ;
}
static const struct V_122 *
F_63 ( struct V_6 * V_7 )
{
struct V_1 * V_123 ;
const struct V_122 * V_2 ;
int V_124 = 0 ;
if ( F_64 ( V_7 ) )
return NULL ;
V_31:
F_2 ( & V_3 ) ;
F_55 (tbl, &hda_preset_tables, list) {
if ( ! F_65 ( V_123 -> V_125 ) ) {
F_33 ( V_25 L_48 ) ;
continue;
}
for ( V_2 = V_123 -> V_2 ; V_2 -> V_126 ; V_2 ++ ) {
T_1 V_61 = V_2 -> V_61 ;
if ( V_2 -> V_127 && V_2 -> V_127 != V_7 -> V_127 )
continue;
if ( V_2 -> V_128 && V_2 -> V_128 != V_7 -> V_128 )
continue;
if ( ! V_61 )
V_61 = ~ 0 ;
if ( V_2 -> V_126 == ( V_7 -> V_129 & V_61 ) &&
( ! V_2 -> V_130 ||
V_2 -> V_130 == V_7 -> V_131 ) ) {
F_4 ( & V_3 ) ;
V_7 -> V_125 = V_123 -> V_125 ;
return V_2 ;
}
}
F_66 ( V_123 -> V_125 ) ;
}
F_4 ( & V_3 ) ;
if ( V_124 < V_132 ) {
char V_133 [ 32 ] ;
if ( ! V_124 )
snprintf ( V_133 , sizeof( V_133 ) , L_49 ,
V_7 -> V_129 ) ;
else
snprintf ( V_133 , sizeof( V_133 ) , L_50 ,
( V_7 -> V_129 >> 16 ) & 0xffff ) ;
F_67 ( V_133 ) ;
V_124 ++ ;
goto V_31;
}
return NULL ;
}
static int F_68 ( struct V_6 * V_7 )
{
const struct V_134 * V_135 ;
const char * V_136 = NULL ;
T_3 V_129 = V_7 -> V_129 >> 16 ;
char V_137 [ 16 ] ;
if ( V_7 -> V_138 )
goto V_139;
for ( V_135 = V_140 ; V_135 -> V_126 ; V_135 ++ ) {
if ( V_135 -> V_126 == V_129 ) {
V_136 = V_135 -> V_133 ;
break;
}
}
if ( ! V_136 ) {
sprintf ( V_137 , L_51 , V_129 ) ;
V_136 = V_137 ;
}
V_7 -> V_138 = F_69 ( V_136 , V_98 ) ;
if ( ! V_7 -> V_138 )
return - V_76 ;
V_139:
if ( V_7 -> V_141 )
return 0 ;
if ( V_7 -> V_2 && V_7 -> V_2 -> V_133 )
V_7 -> V_141 = F_69 ( V_7 -> V_2 -> V_133 , V_98 ) ;
else {
sprintf ( V_137 , L_52 , V_7 -> V_129 & 0xffff ) ;
V_7 -> V_141 = F_69 ( V_137 , V_98 ) ;
}
if ( ! V_7 -> V_141 )
return - V_76 ;
return 0 ;
}
static void F_70 ( struct V_6 * V_7 )
{
int V_12 , V_142 , V_143 ;
T_2 V_19 ;
V_142 = F_24 ( V_7 , V_144 , & V_19 ) ;
for ( V_12 = 0 ; V_12 < V_142 ; V_12 ++ , V_19 ++ ) {
V_143 = F_25 ( V_7 , V_19 ,
V_145 ) ;
switch ( V_143 & 0xff ) {
case V_146 :
V_7 -> V_127 = V_19 ;
V_7 -> V_147 = V_143 & 0xff ;
V_7 -> V_148 = ( V_143 >> 8 ) & 1 ;
break;
case V_149 :
V_7 -> V_128 = V_19 ;
V_7 -> V_150 = V_143 & 0xff ;
V_7 -> V_151 = ( V_143 >> 8 ) & 1 ;
break;
default:
break;
}
}
}
static int F_71 ( struct V_6 * V_7 , T_2 V_152 )
{
int V_12 ;
T_2 V_19 ;
V_7 -> V_153 = F_24 ( V_7 , V_152 ,
& V_7 -> V_154 ) ;
V_7 -> V_62 = F_72 ( V_7 -> V_153 * 4 , V_98 ) ;
if ( ! V_7 -> V_62 )
return - V_76 ;
V_19 = V_7 -> V_154 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_153 ; V_12 ++ , V_19 ++ )
V_7 -> V_62 [ V_12 ] = F_25 ( V_7 , V_19 ,
V_155 ) ;
return 0 ;
}
static int F_73 ( struct V_6 * V_7 )
{
int V_12 ;
T_2 V_19 = V_7 -> V_154 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_153 ; V_12 ++ , V_19 ++ ) {
struct V_156 * V_157 ;
unsigned int V_62 = F_34 ( V_7 , V_19 ) ;
unsigned int V_158 = F_35 ( V_62 ) ;
if ( V_158 != V_82 )
continue;
V_157 = F_37 ( & V_7 -> V_159 ) ;
if ( ! V_157 )
return - V_76 ;
V_157 -> V_19 = V_19 ;
V_157 -> V_8 = F_21 ( V_7 , V_19 , 0 ,
V_160 , 0 ) ;
V_157 -> V_161 = F_21 ( V_7 , V_19 , 0 ,
V_162 ,
0 ) ;
}
return 0 ;
}
static struct V_156 * F_74 ( struct V_6 * V_7 ,
struct V_45 * V_46 ,
T_2 V_19 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_46 -> V_48 ; V_12 ++ ) {
struct V_156 * V_157 = F_27 ( V_46 , V_12 ) ;
if ( V_157 -> V_19 == V_19 )
return V_157 ;
}
return NULL ;
}
static void F_75 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_8 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ ) {
F_22 ( V_7 , V_19 , 0 ,
V_163 + V_12 ,
V_8 & 0xff ) ;
V_8 >>= 8 ;
}
}
int F_76 ( struct V_6 * V_7 , struct V_45 * V_4 ,
T_2 V_19 , unsigned int V_8 )
{
struct V_156 * V_157 ;
unsigned int V_164 ;
if ( F_35 ( F_34 ( V_7 , V_19 ) ) != V_82 )
return - V_54 ;
V_164 = F_77 ( V_7 , V_19 ) ;
V_157 = F_74 ( V_7 , V_4 , V_19 ) ;
if ( ! V_157 ) {
V_157 = F_37 ( V_4 ) ;
if ( ! V_157 )
return - V_76 ;
V_157 -> V_19 = V_19 ;
}
V_157 -> V_8 = V_8 ;
V_8 = F_77 ( V_7 , V_19 ) ;
if ( V_164 != V_8 )
F_75 ( V_7 , V_19 , V_8 ) ;
return 0 ;
}
int F_78 ( struct V_6 * V_7 ,
T_2 V_19 , unsigned int V_8 )
{
return F_76 ( V_7 , & V_7 -> V_165 , V_19 , V_8 ) ;
}
unsigned int F_77 ( struct V_6 * V_7 , T_2 V_19 )
{
struct V_156 * V_157 ;
#ifdef F_79
V_157 = F_74 ( V_7 , & V_7 -> V_166 , V_19 ) ;
if ( V_157 )
return V_157 -> V_8 ;
#endif
V_157 = F_74 ( V_7 , & V_7 -> V_165 , V_19 ) ;
if ( V_157 )
return V_157 -> V_8 ;
V_157 = F_74 ( V_7 , & V_7 -> V_159 , V_19 ) ;
if ( V_157 )
return V_157 -> V_8 ;
return 0 ;
}
static void F_80 ( struct V_6 * V_7 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_159 . V_48 ; V_12 ++ ) {
struct V_156 * V_157 = F_27 ( & V_7 -> V_159 , V_12 ) ;
F_75 ( V_7 , V_157 -> V_19 ,
F_77 ( V_7 , V_157 -> V_19 ) ) ;
}
}
void F_81 ( struct V_6 * V_7 )
{
int V_12 ;
if ( V_7 -> V_29 -> V_103 )
return;
for ( V_12 = 0 ; V_12 < V_7 -> V_159 . V_48 ; V_12 ++ ) {
struct V_156 * V_157 = F_27 ( & V_7 -> V_159 , V_12 ) ;
F_21 ( V_7 , V_157 -> V_19 , 0 ,
V_167 , 0 ) ;
}
V_7 -> V_168 = 1 ;
}
static void F_82 ( struct V_6 * V_7 )
{
int V_12 ;
if ( ! V_7 -> V_168 )
return;
if ( V_7 -> V_29 -> V_103 )
return;
for ( V_12 = 0 ; V_12 < V_7 -> V_159 . V_48 ; V_12 ++ ) {
struct V_156 * V_157 = F_27 ( & V_7 -> V_159 , V_12 ) ;
F_22 ( V_7 , V_157 -> V_19 , 0 ,
V_167 ,
V_157 -> V_161 ) ;
}
V_7 -> V_168 = 0 ;
}
static void F_83 ( struct V_6 * V_7 )
{
F_84 ( & V_7 -> V_165 ) ;
#ifdef F_79
F_84 ( & V_7 -> V_166 ) ;
#endif
F_80 ( V_7 ) ;
F_84 ( & V_7 -> V_159 ) ;
}
static struct V_169 *
F_85 ( struct V_6 * V_7 , T_2 V_19 )
{
struct V_169 * V_49 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_170 . V_48 ; V_12 ++ ) {
V_49 = F_27 ( & V_7 -> V_170 , V_12 ) ;
if ( V_49 -> V_19 == V_19 )
return V_49 ;
}
V_49 = F_37 ( & V_7 -> V_170 ) ;
if ( V_49 )
V_49 -> V_19 = V_19 ;
return V_49 ;
}
static void F_51 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_83 ( V_7 ) ;
#ifdef F_86
F_87 ( & V_7 -> V_171 ) ;
F_48 ( V_7 -> V_29 -> V_90 ) ;
#endif
F_6 ( & V_7 -> V_4 ) ;
F_84 ( & V_7 -> V_172 ) ;
F_84 ( & V_7 -> V_173 ) ;
F_84 ( & V_7 -> V_51 ) ;
F_84 ( & V_7 -> V_174 ) ;
V_7 -> V_29 -> V_95 [ V_7 -> V_24 ] = NULL ;
if ( V_7 -> V_96 . free )
V_7 -> V_96 . free ( V_7 ) ;
F_66 ( V_7 -> V_125 ) ;
F_88 ( & V_7 -> V_175 ) ;
F_88 ( & V_7 -> V_176 ) ;
F_49 ( V_7 -> V_138 ) ;
F_49 ( V_7 -> V_141 ) ;
F_49 ( V_7 -> V_115 ) ;
F_49 ( V_7 -> V_62 ) ;
F_49 ( V_7 ) ;
}
int F_89 ( struct V_28 * V_29 ,
unsigned int V_177 ,
struct V_6 * * V_178 )
{
struct V_6 * V_7 ;
char V_179 [ 31 ] ;
int V_30 ;
if ( F_29 ( ! V_29 ) )
return - V_54 ;
if ( F_29 ( V_177 > V_180 ) )
return - V_54 ;
if ( V_29 -> V_95 [ V_177 ] ) {
F_33 ( V_25 L_39
L_53 , V_177 ) ;
return - V_181 ;
}
V_7 = F_45 ( sizeof( * V_7 ) , V_98 ) ;
if ( V_7 == NULL ) {
F_33 ( V_25 L_54 ) ;
return - V_76 ;
}
V_7 -> V_29 = V_29 ;
V_7 -> V_24 = V_177 ;
F_59 ( & V_7 -> V_182 ) ;
F_59 ( & V_7 -> V_183 ) ;
F_90 ( & V_7 -> V_175 , sizeof( struct V_184 ) ) ;
F_90 ( & V_7 -> V_176 , sizeof( struct V_185 ) ) ;
F_91 ( & V_7 -> V_172 , sizeof( struct V_186 ) , 32 ) ;
F_91 ( & V_7 -> V_173 , sizeof( struct V_186 ) , 32 ) ;
F_91 ( & V_7 -> V_159 , sizeof( struct V_156 ) , 16 ) ;
F_91 ( & V_7 -> V_165 , sizeof( struct V_156 ) , 16 ) ;
F_91 ( & V_7 -> V_170 , sizeof( struct V_169 ) , 8 ) ;
F_91 ( & V_7 -> V_51 , sizeof( T_2 ) , 64 ) ;
F_91 ( & V_7 -> V_174 , sizeof( struct V_187 ) , 16 ) ;
if ( V_7 -> V_29 -> V_115 ) {
V_7 -> V_115 = F_69 ( V_7 -> V_29 -> V_115 , V_98 ) ;
if ( ! V_7 -> V_115 ) {
F_51 ( V_7 ) ;
return - V_188 ;
}
}
#ifdef F_86
F_92 ( & V_7 -> V_171 , V_189 ) ;
F_7 ( V_7 ) ;
#endif
F_3 ( & V_7 -> V_4 , & V_29 -> V_118 ) ;
V_29 -> V_95 [ V_177 ] = V_7 ;
V_7 -> V_129 = F_25 ( V_7 , V_144 ,
V_190 ) ;
if ( V_7 -> V_129 == - 1 )
V_7 -> V_129 = F_25 ( V_7 , V_144 ,
V_190 ) ;
V_7 -> V_191 = F_25 ( V_7 , V_144 ,
V_192 ) ;
V_7 -> V_131 = F_25 ( V_7 , V_144 ,
V_193 ) ;
F_70 ( V_7 ) ;
if ( ! V_7 -> V_127 && ! V_7 -> V_128 ) {
F_93 ( L_55 ) ;
V_30 = - V_188 ;
goto error;
}
V_30 = F_71 ( V_7 , V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ) ;
if ( V_30 < 0 ) {
F_33 ( V_25 L_56 ) ;
goto error;
}
V_30 = F_73 ( V_7 ) ;
if ( V_30 < 0 )
goto error;
if ( ! V_7 -> V_191 ) {
T_2 V_19 = V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ;
V_7 -> V_191 =
F_21 ( V_7 , V_19 , 0 ,
V_194 , 0 ) ;
}
F_94 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_195 ) ;
F_95 ( V_7 ) ;
F_96 ( V_7 ) ;
sprintf ( V_179 , L_57 , V_7 -> V_129 ,
V_7 -> V_191 , V_7 -> V_131 ) ;
F_97 ( V_7 -> V_29 -> V_105 , V_179 ) ;
if ( V_178 )
* V_178 = V_7 ;
return 0 ;
error:
F_51 ( V_7 ) ;
return V_30 ;
}
int F_98 ( struct V_6 * V_7 )
{
int V_30 ;
V_7 -> V_2 = F_63 ( V_7 ) ;
if ( ! V_7 -> V_138 || ! V_7 -> V_141 ) {
V_30 = F_68 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( F_64 ( V_7 ) ) {
V_30 = F_99 ( V_7 ) ;
goto V_196;
}
if ( V_7 -> V_2 && V_7 -> V_2 -> V_197 ) {
V_30 = V_7 -> V_2 -> V_197 ( V_7 ) ;
goto V_196;
}
V_30 = F_99 ( V_7 ) ;
if ( V_30 < 0 )
F_13 ( V_25 L_58 ) ;
V_196:
if ( ! V_30 && V_7 -> V_96 . V_97 )
V_30 = F_44 ( V_7 -> V_29 ) ;
if ( ! V_30 && ( V_7 -> V_127 || ! * V_7 -> V_29 -> V_105 -> V_198 ) )
snprintf ( V_7 -> V_29 -> V_105 -> V_198 ,
sizeof( V_7 -> V_29 -> V_105 -> V_198 ) ,
L_59 , V_7 -> V_138 , V_7 -> V_141 ) ;
return V_30 ;
}
void F_100 ( struct V_6 * V_7 , T_2 V_19 ,
T_1 V_199 ,
int V_200 , int V_201 )
{
struct V_6 * V_135 ;
struct V_169 * V_49 ;
unsigned int V_202 , V_203 ;
int type ;
int V_12 ;
if ( ! V_19 )
return;
F_93 ( L_60
L_61 ,
V_19 , V_199 , V_200 , V_201 ) ;
V_49 = F_85 ( V_7 , V_19 ) ;
if ( ! V_49 )
return;
if ( V_49 -> V_199 != V_199 || V_49 -> V_200 != V_200 ) {
V_202 = F_21 ( V_7 , V_19 , 0 , V_204 , 0 ) ;
V_203 = ( V_199 << 4 ) | V_200 ;
if ( V_202 != V_203 )
F_22 ( V_7 , V_19 , 0 ,
V_205 ,
V_203 ) ;
V_49 -> V_199 = V_199 ;
V_49 -> V_200 = V_200 ;
}
if ( V_49 -> V_206 != V_201 ) {
V_202 = F_21 ( V_7 , V_19 , 0 ,
V_207 , 0 ) ;
if ( V_202 != V_201 ) {
F_101 ( 1 ) ;
F_22 ( V_7 , V_19 , 0 ,
V_208 ,
V_201 ) ;
}
V_49 -> V_206 = V_201 ;
}
V_49 -> V_209 = 1 ;
V_49 -> V_210 = 0 ;
type = F_35 ( F_34 ( V_7 , V_19 ) ) ;
F_55 (c, &codec->bus->codec_list, list) {
for ( V_12 = 0 ; V_12 < V_135 -> V_170 . V_48 ; V_12 ++ ) {
V_49 = F_27 ( & V_135 -> V_170 , V_12 ) ;
if ( ! V_49 -> V_209 && V_49 -> V_199 == V_199 &&
F_35 ( F_34 ( V_7 , V_49 -> V_19 ) ) == type )
V_49 -> V_210 = 1 ;
}
}
}
void F_102 ( struct V_6 * V_7 , T_2 V_19 ,
int V_211 )
{
struct V_169 * V_49 ;
if ( ! V_19 )
return;
if ( V_7 -> V_212 )
V_211 = 1 ;
F_93 ( L_62 , V_19 ) ;
V_49 = F_85 ( V_7 , V_19 ) ;
if ( V_49 ) {
if ( V_211 )
F_103 ( V_7 , V_49 ) ;
else
V_49 -> V_209 = 0 ;
}
}
static void F_103 ( struct V_6 * V_7 ,
struct V_169 * V_213 )
{
T_2 V_19 = V_213 -> V_19 ;
if ( V_213 -> V_199 || V_213 -> V_200 )
F_22 ( V_7 , V_19 , 0 , V_205 , 0 ) ;
if ( V_213 -> V_206 )
F_22 ( V_7 , V_19 , 0 , V_208 , 0
) ;
memset ( V_213 , 0 , sizeof( * V_213 ) ) ;
V_213 -> V_19 = V_19 ;
}
static void F_104 ( struct V_6 * V_7 )
{
struct V_6 * V_135 ;
int V_12 ;
F_55 (c, &codec->bus->codec_list, list) {
for ( V_12 = 0 ; V_12 < V_135 -> V_170 . V_48 ; V_12 ++ ) {
struct V_169 * V_49 ;
V_49 = F_27 ( & V_135 -> V_170 , V_12 ) ;
if ( V_49 -> V_210 )
F_103 ( V_135 , V_49 ) ;
}
}
}
static void F_105 ( struct V_6 * V_7 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_170 . V_48 ; V_12 ++ ) {
struct V_169 * V_49 = F_27 ( & V_7 -> V_170 , V_12 ) ;
if ( V_49 -> V_199 )
F_103 ( V_7 , V_49 ) ;
}
}
static void F_90 ( struct V_214 * V_215 ,
unsigned int V_216 )
{
memset ( V_215 , 0 , sizeof( * V_215 ) ) ;
memset ( V_215 -> V_217 , 0xff , sizeof( V_215 -> V_217 ) ) ;
F_91 ( & V_215 -> V_218 , V_216 , 64 ) ;
}
static void F_88 ( struct V_214 * V_215 )
{
F_84 ( & V_215 -> V_218 ) ;
}
static struct V_185 * F_106 ( struct V_214 * V_215 , T_1 V_219 )
{
T_3 V_220 = V_219 % ( T_3 ) F_9 ( V_215 -> V_217 ) ;
T_3 V_221 = V_215 -> V_217 [ V_220 ] ;
struct V_185 * V_222 ;
while ( V_221 != 0xffff ) {
V_222 = F_27 ( & V_215 -> V_218 , V_221 ) ;
if ( V_222 -> V_219 == V_219 )
return V_222 ;
V_221 = V_222 -> V_223 ;
}
return NULL ;
}
static struct V_185 * F_107 ( struct V_214 * V_215 ,
T_1 V_219 )
{
struct V_185 * V_222 = F_106 ( V_215 , V_219 ) ;
if ( ! V_222 ) {
T_3 V_220 , V_221 ;
V_222 = F_37 ( & V_215 -> V_218 ) ;
if ( ! V_222 )
return NULL ;
V_221 = F_108 ( & V_215 -> V_218 , V_222 ) ;
V_222 -> V_219 = V_219 ;
V_222 -> V_23 = 0 ;
V_220 = V_219 % ( T_3 ) F_9 ( V_215 -> V_217 ) ;
V_222 -> V_223 = V_215 -> V_217 [ V_220 ] ;
V_215 -> V_217 [ V_220 ] = V_221 ;
}
return V_222 ;
}
static inline struct V_184 *
F_109 ( struct V_6 * V_7 , T_1 V_219 )
{
return (struct V_184 * ) F_107 ( & V_7 -> V_175 , V_219 ) ;
}
T_1 F_110 ( struct V_6 * V_7 , T_2 V_19 , int V_224 )
{
struct V_184 * V_222 ;
V_222 = F_109 ( V_7 , F_111 ( V_19 , V_224 , 0 ) ) ;
if ( ! V_222 )
return 0 ;
if ( ! ( V_222 -> V_225 . V_23 & V_226 ) ) {
if ( ! ( F_34 ( V_7 , V_19 ) & V_227 ) )
V_19 = V_7 -> V_127 ;
V_222 -> V_228 = F_25 ( V_7 , V_19 ,
V_224 == V_229 ?
V_230 :
V_231 ) ;
if ( V_222 -> V_228 )
V_222 -> V_225 . V_23 |= V_226 ;
}
return V_222 -> V_228 ;
}
int F_112 ( struct V_6 * V_7 , T_2 V_19 , int V_232 ,
unsigned int V_233 )
{
struct V_184 * V_222 ;
V_222 = F_109 ( V_7 , F_111 ( V_19 , V_232 , 0 ) ) ;
if ( ! V_222 )
return - V_54 ;
V_222 -> V_228 = V_233 ;
V_222 -> V_225 . V_23 |= V_226 ;
return 0 ;
}
static unsigned int F_113 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_25 ( V_7 , V_19 , V_234 ) ;
}
T_1 F_114 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_115 ( V_7 , V_19 , F_116 ( V_19 ) ,
F_113 ) ;
}
int F_117 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_233 )
{
struct V_184 * V_222 ;
V_222 = F_109 ( V_7 , F_116 ( V_19 ) ) ;
if ( ! V_222 )
return - V_76 ;
V_222 -> V_228 = V_233 ;
V_222 -> V_225 . V_23 |= V_226 ;
return 0 ;
}
T_1 F_118 ( struct V_6 * V_7 , T_2 V_19 )
{
T_1 V_235 ;
if ( ! V_7 -> V_236 ) {
V_235 = F_114 ( V_7 , V_19 ) ;
if ( V_235 & V_237 )
F_21 ( V_7 , V_19 , 0 ,
V_238 , 0 ) ;
}
return F_21 ( V_7 , V_19 , 0 ,
V_239 , 0 ) ;
}
int F_119 ( struct V_6 * V_7 , T_2 V_19 )
{
T_1 V_240 = F_118 ( V_7 , V_19 ) ;
return ! ! ( V_240 & V_241 ) ;
}
static unsigned int F_120 ( struct V_6 * V_7 ,
struct V_184 * V_222 , T_2 V_19 ,
int V_242 , int V_224 , int V_243 )
{
T_1 V_23 , V_22 ;
if ( V_222 -> V_225 . V_23 & F_121 ( V_242 ) )
return V_222 -> V_244 [ V_242 ] ;
V_22 = V_242 ? V_245 : V_246 ;
V_22 |= V_224 == V_229 ? V_247 : V_248 ;
V_22 |= V_243 ;
V_23 = F_21 ( V_7 , V_19 , 0 ,
V_249 , V_22 ) ;
V_222 -> V_244 [ V_242 ] = V_23 & 0xff ;
V_222 -> V_225 . V_23 |= F_121 ( V_242 ) ;
return V_222 -> V_244 [ V_242 ] ;
}
static void F_122 ( struct V_6 * V_7 , struct V_184 * V_222 ,
T_2 V_19 , int V_242 , int V_224 , int V_243 ,
int V_23 )
{
T_1 V_22 ;
V_22 = V_242 ? V_250 : V_251 ;
V_22 |= V_224 == V_229 ? V_252 : V_253 ;
V_22 |= V_243 << V_254 ;
V_22 |= V_23 ;
F_22 ( V_7 , V_19 , 0 , V_255 , V_22 ) ;
V_222 -> V_244 [ V_242 ] = V_23 ;
}
int F_123 ( struct V_6 * V_7 , T_2 V_19 , int V_242 ,
int V_224 , int V_243 )
{
struct V_184 * V_222 ;
V_222 = F_109 ( V_7 , F_111 ( V_19 , V_224 , V_243 ) ) ;
if ( ! V_222 )
return 0 ;
return F_120 ( V_7 , V_222 , V_19 , V_242 , V_224 , V_243 ) ;
}
int F_124 ( struct V_6 * V_7 , T_2 V_19 , int V_242 ,
int V_224 , int V_220 , int V_61 , int V_23 )
{
struct V_184 * V_222 ;
V_222 = F_109 ( V_7 , F_111 ( V_19 , V_224 , V_220 ) ) ;
if ( ! V_222 )
return 0 ;
if ( F_29 ( V_61 & ~ 0xff ) )
V_61 &= 0xff ;
V_23 &= V_61 ;
V_23 |= F_120 ( V_7 , V_222 , V_19 , V_242 , V_224 , V_220 ) & ~ V_61 ;
if ( V_222 -> V_244 [ V_242 ] == V_23 )
return 0 ;
F_122 ( V_7 , V_222 , V_19 , V_242 , V_224 , V_220 , V_23 ) ;
return 1 ;
}
int F_125 ( struct V_6 * V_7 , T_2 V_19 ,
int V_224 , int V_220 , int V_61 , int V_23 )
{
int V_242 , V_256 = 0 ;
if ( F_29 ( V_61 & ~ 0xff ) )
V_61 &= 0xff ;
for ( V_242 = 0 ; V_242 < 2 ; V_242 ++ )
V_256 |= F_124 ( V_7 , V_19 , V_242 , V_224 ,
V_220 , V_61 , V_23 ) ;
return V_256 ;
}
void F_126 ( struct V_6 * V_7 )
{
struct V_184 * V_257 = V_7 -> V_175 . V_218 . V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_175 . V_218 . V_48 ; V_12 ++ , V_257 ++ ) {
T_1 V_219 = V_257 -> V_225 . V_219 ;
T_2 V_19 ;
unsigned int V_220 , V_232 , V_242 ;
if ( ! V_219 )
continue;
V_19 = V_219 & 0xff ;
V_220 = ( V_219 >> 16 ) & 0xff ;
V_232 = ( V_219 >> 24 ) & 0xff ;
for ( V_242 = 0 ; V_242 < 2 ; V_242 ++ ) {
if ( ! ( V_257 -> V_225 . V_23 & F_121 ( V_242 ) ) )
continue;
F_122 ( V_7 , V_257 , V_19 , V_242 , V_232 , V_220 ,
V_257 -> V_244 [ V_242 ] ) ;
}
}
}
static T_1 F_127 ( struct V_6 * V_7 , T_2 V_19 , int V_232 ,
unsigned int V_258 )
{
T_1 V_233 = F_110 ( V_7 , V_19 , V_232 ) ;
V_233 = ( V_233 & V_259 ) >> V_260 ;
if ( V_258 < V_233 )
V_233 -= V_258 ;
return V_233 ;
}
int F_128 ( struct V_261 * V_262 ,
struct V_263 * V_264 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
T_3 V_19 = F_130 ( V_262 ) ;
T_4 V_265 = F_131 ( V_262 ) ;
int V_232 = F_132 ( V_262 ) ;
unsigned int V_258 = F_133 ( V_262 ) ;
V_264 -> type = V_266 ;
V_264 -> V_267 = V_265 == 3 ? 2 : 1 ;
V_264 -> V_268 . integer . V_269 = 0 ;
V_264 -> V_268 . integer . V_270 = F_127 ( V_7 , V_19 , V_232 , V_258 ) ;
if ( ! V_264 -> V_268 . integer . V_270 ) {
F_13 ( V_73 L_39
L_63 , V_19 ,
V_262 -> V_126 . V_133 ) ;
return - V_54 ;
}
return 0 ;
}
static inline unsigned int
F_134 ( struct V_6 * V_7 , T_2 V_19 ,
int V_242 , int V_232 , int V_220 , unsigned int V_258 )
{
unsigned int V_23 ;
V_23 = F_123 ( V_7 , V_19 , V_242 , V_232 , V_220 ) ;
V_23 &= V_271 ;
if ( V_23 >= V_258 )
V_23 -= V_258 ;
else
V_23 = 0 ;
return V_23 ;
}
static inline int
F_135 ( struct V_6 * V_7 , T_2 V_19 ,
int V_242 , int V_232 , int V_220 , unsigned int V_258 ,
unsigned int V_23 )
{
unsigned int V_272 ;
if ( V_23 > 0 )
V_23 += V_258 ;
V_272 = F_127 ( V_7 , V_19 , V_232 , 0 ) ;
if ( V_23 > V_272 )
V_23 = V_272 ;
return F_124 ( V_7 , V_19 , V_242 , V_232 , V_220 ,
V_271 , V_23 ) ;
}
int F_136 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
T_2 V_19 = F_130 ( V_262 ) ;
int V_265 = F_131 ( V_262 ) ;
int V_232 = F_132 ( V_262 ) ;
int V_220 = F_137 ( V_262 ) ;
unsigned int V_258 = F_133 ( V_262 ) ;
long * V_275 = V_274 -> V_268 . integer . V_268 ;
if ( V_265 & 1 )
* V_275 ++ = F_134 ( V_7 , V_19 , 0 , V_232 , V_220 , V_258 ) ;
if ( V_265 & 2 )
* V_275 = F_134 ( V_7 , V_19 , 1 , V_232 , V_220 , V_258 ) ;
return 0 ;
}
int F_138 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
T_2 V_19 = F_130 ( V_262 ) ;
int V_265 = F_131 ( V_262 ) ;
int V_232 = F_132 ( V_262 ) ;
int V_220 = F_137 ( V_262 ) ;
unsigned int V_258 = F_133 ( V_262 ) ;
long * V_275 = V_274 -> V_268 . integer . V_268 ;
int V_276 = 0 ;
F_15 ( V_7 ) ;
if ( V_265 & 1 ) {
V_276 = F_135 ( V_7 , V_19 , 0 , V_232 , V_220 , V_258 , * V_275 ) ;
V_275 ++ ;
}
if ( V_265 & 2 )
V_276 |= F_135 ( V_7 , V_19 , 1 , V_232 , V_220 , V_258 , * V_275 ) ;
F_18 ( V_7 ) ;
return V_276 ;
}
int F_139 ( struct V_261 * V_262 , int V_277 ,
unsigned int V_278 , unsigned int T_5 * V_279 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
T_2 V_19 = F_130 ( V_262 ) ;
int V_232 = F_132 ( V_262 ) ;
unsigned int V_258 = F_133 ( V_262 ) ;
bool V_280 = F_140 ( V_262 ) ;
T_1 V_233 , V_281 , V_282 ;
if ( V_278 < 4 * sizeof( unsigned int ) )
return - V_76 ;
V_233 = F_110 ( V_7 , V_19 , V_232 ) ;
V_282 = ( V_233 & V_283 ) >> V_284 ;
V_282 = ( V_282 + 1 ) * 25 ;
V_281 = - ( ( V_233 & V_285 ) >> V_286 ) ;
V_281 += V_258 ;
V_281 = ( ( int ) V_281 ) * ( ( int ) V_282 ) ;
if ( V_280 )
V_282 |= V_287 ;
if ( F_141 ( V_288 , V_279 ) )
return - V_289 ;
if ( F_141 ( 2 * sizeof( unsigned int ) , V_279 + 1 ) )
return - V_289 ;
if ( F_141 ( V_281 , V_279 + 2 ) )
return - V_289 ;
if ( F_141 ( V_282 , V_279 + 3 ) )
return - V_289 ;
return 0 ;
}
void F_142 ( struct V_6 * V_7 , T_2 V_19 , int V_232 ,
unsigned int * V_290 )
{
T_1 V_233 ;
int V_81 , V_291 ;
V_233 = F_110 ( V_7 , V_19 , V_232 ) ;
V_81 = ( V_233 & V_259 ) >> V_260 ;
V_291 = ( V_233 & V_283 ) >> V_284 ;
V_291 = ( V_291 + 1 ) * 25 ;
V_290 [ 0 ] = V_288 ;
V_290 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_290 [ 2 ] = - V_81 * V_291 ;
V_290 [ 3 ] = V_291 ;
}
static struct V_261 *
F_143 ( struct V_6 * V_7 ,
const char * V_133 , int V_220 )
{
struct V_292 V_126 ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_293 = V_294 ;
V_126 . V_243 = V_220 ;
if ( F_29 ( strlen ( V_133 ) >= sizeof( V_126 . V_133 ) ) )
return NULL ;
strcpy ( V_126 . V_133 , V_133 ) ;
return F_144 ( V_7 -> V_29 -> V_105 , & V_126 ) ;
}
struct V_261 * F_145 ( struct V_6 * V_7 ,
const char * V_133 )
{
return F_143 ( V_7 , V_133 , 0 ) ;
}
static int F_146 ( struct V_6 * V_7 , const char * V_133 )
{
int V_220 ;
for ( V_220 = 0 ; V_220 < 16 ; V_220 ++ ) {
if ( ! F_143 ( V_7 , V_133 , V_220 ) )
return V_220 ;
}
return - V_181 ;
}
int F_147 ( struct V_6 * V_7 , T_2 V_19 ,
struct V_261 * V_295 )
{
int V_30 ;
unsigned short V_296 = 0 ;
struct V_186 * V_297 ;
if ( V_295 -> V_126 . V_298 & V_299 ) {
V_296 |= V_300 ;
if ( V_19 == 0 )
V_19 = F_148 ( V_295 -> V_301 ) ;
}
if ( ( V_295 -> V_126 . V_298 & V_302 ) != 0 && V_19 == 0 )
V_19 = V_295 -> V_126 . V_298 & 0xffff ;
if ( V_295 -> V_126 . V_298 & ( V_302 | V_299 ) )
V_295 -> V_126 . V_298 = 0 ;
V_30 = F_149 ( V_7 -> V_29 -> V_105 , V_295 ) ;
if ( V_30 < 0 )
return V_30 ;
V_297 = F_37 ( & V_7 -> V_172 ) ;
if ( ! V_297 )
return - V_76 ;
V_297 -> V_295 = V_295 ;
V_297 -> V_19 = V_19 ;
V_297 -> V_296 = V_296 ;
return 0 ;
}
int F_150 ( struct V_6 * V_7 , struct V_261 * V_295 ,
unsigned int V_243 , T_2 V_19 )
{
struct V_186 * V_297 ;
if ( V_19 > 0 ) {
V_297 = F_37 ( & V_7 -> V_173 ) ;
if ( ! V_297 )
return - V_76 ;
V_297 -> V_295 = V_295 ;
V_297 -> V_243 = V_243 ;
V_297 -> V_19 = V_19 ;
return 0 ;
}
F_13 ( V_25 L_64 ,
V_295 -> V_126 . V_133 , V_295 -> V_126 . V_243 , V_243 ) ;
return - V_54 ;
}
void F_151 ( struct V_6 * V_7 )
{
int V_12 ;
struct V_186 * V_303 = V_7 -> V_172 . V_4 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_172 . V_48 ; V_12 ++ )
F_152 ( V_7 -> V_29 -> V_105 , V_303 [ V_12 ] . V_295 ) ;
F_84 ( & V_7 -> V_172 ) ;
F_84 ( & V_7 -> V_173 ) ;
}
static int F_153 ( struct V_104 * V_105 )
{
F_154 ( & V_105 -> V_304 ) ;
if ( V_105 -> V_103 ) {
F_155 ( & V_105 -> V_304 ) ;
return - V_54 ;
}
V_105 -> V_103 = 1 ;
F_155 ( & V_105 -> V_304 ) ;
return 0 ;
}
static void F_156 ( struct V_104 * V_105 )
{
F_154 ( & V_105 -> V_304 ) ;
V_105 -> V_103 = 0 ;
F_155 ( & V_105 -> V_304 ) ;
}
int F_157 ( struct V_6 * V_7 )
{
struct V_104 * V_105 = V_7 -> V_29 -> V_105 ;
int V_12 , V_305 ;
if ( F_153 ( V_105 ) < 0 )
return - V_181 ;
if ( ! F_158 ( & V_105 -> V_306 ) ) {
F_156 ( V_105 ) ;
return - V_181 ;
}
for ( V_305 = 0 ; V_305 < V_7 -> V_307 ; V_305 ++ ) {
struct V_308 * V_309 = & V_7 -> V_310 [ V_305 ] ;
if ( ! V_309 -> V_305 )
continue;
if ( V_309 -> V_305 -> V_311 [ 0 ] . V_312 ||
V_309 -> V_305 -> V_311 [ 1 ] . V_312 ) {
F_156 ( V_105 ) ;
return - V_181 ;
}
}
#ifdef F_86
F_87 ( & V_7 -> V_171 ) ;
F_48 ( V_7 -> V_29 -> V_90 ) ;
#endif
F_151 ( V_7 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_307 ; V_12 ++ ) {
if ( V_7 -> V_310 [ V_12 ] . V_305 ) {
F_159 ( V_105 , V_7 -> V_310 [ V_12 ] . V_305 ) ;
F_160 ( V_7 -> V_310 [ V_12 ] . V_101 ,
V_7 -> V_29 -> V_313 ) ;
}
}
if ( V_7 -> V_96 . free )
V_7 -> V_96 . free ( V_7 ) ;
V_7 -> V_314 = NULL ;
V_7 -> V_315 = NULL ;
F_88 ( & V_7 -> V_175 ) ;
F_88 ( & V_7 -> V_176 ) ;
F_90 ( & V_7 -> V_175 , sizeof( struct V_184 ) ) ;
F_90 ( & V_7 -> V_176 , sizeof( struct V_185 ) ) ;
F_84 ( & V_7 -> V_165 ) ;
F_80 ( V_7 ) ;
V_7 -> V_307 = 0 ;
V_7 -> V_310 = NULL ;
V_7 -> V_2 = NULL ;
memset ( & V_7 -> V_96 , 0 , sizeof( V_7 -> V_96 ) ) ;
V_7 -> V_316 = NULL ;
V_7 -> V_317 = 0 ;
F_66 ( V_7 -> V_125 ) ;
V_7 -> V_125 = NULL ;
F_156 ( V_105 ) ;
return 0 ;
}
static int F_161 ( struct V_6 * V_7 , const char * const * V_318 ,
T_6 V_319 , void * V_320 )
{
struct V_186 * V_303 ;
const char * const * V_321 ;
int V_12 , V_30 ;
V_303 = V_7 -> V_172 . V_4 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_172 . V_48 ; V_12 ++ ) {
struct V_261 * V_322 = V_303 [ V_12 ] . V_295 ;
if ( ! V_322 || ! V_322 -> V_126 . V_133 ||
V_322 -> V_126 . V_293 != V_294 )
continue;
for ( V_321 = V_318 ; * V_321 ; V_321 ++ ) {
if ( ! strcmp ( V_322 -> V_126 . V_133 , * V_321 ) ) {
V_30 = V_319 ( V_320 , V_322 ) ;
if ( V_30 )
return V_30 ;
break;
}
}
}
return 0 ;
}
static int F_162 ( void * V_320 , struct V_261 * V_322 )
{
return 1 ;
}
int F_163 ( struct V_6 * V_7 , char * V_133 ,
unsigned int * V_290 , const char * const * V_318 )
{
struct V_261 * V_295 ;
int V_30 ;
V_30 = F_161 ( V_7 , V_318 , F_162 , NULL ) ;
if ( V_30 != 1 ) {
F_93 ( L_65 , V_133 ) ;
return 0 ;
}
V_295 = F_164 ( V_133 , V_290 ) ;
if ( ! V_295 )
return - V_76 ;
V_30 = F_147 ( V_7 , 0 , V_295 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_161 ( V_7 , V_318 , ( T_6 ) V_323 ,
V_295 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
int F_165 ( struct V_261 * V_262 ,
struct V_263 * V_264 )
{
int V_265 = F_131 ( V_262 ) ;
V_264 -> type = V_324 ;
V_264 -> V_267 = V_265 == 3 ? 2 : 1 ;
V_264 -> V_268 . integer . V_269 = 0 ;
V_264 -> V_268 . integer . V_270 = 1 ;
return 0 ;
}
int F_166 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
T_2 V_19 = F_130 ( V_262 ) ;
int V_265 = F_131 ( V_262 ) ;
int V_232 = F_132 ( V_262 ) ;
int V_220 = F_137 ( V_262 ) ;
long * V_275 = V_274 -> V_268 . integer . V_268 ;
if ( V_265 & 1 )
* V_275 ++ = ( F_123 ( V_7 , V_19 , 0 , V_232 , V_220 ) &
V_325 ) ? 0 : 1 ;
if ( V_265 & 2 )
* V_275 = ( F_123 ( V_7 , V_19 , 1 , V_232 , V_220 ) &
V_325 ) ? 0 : 1 ;
return 0 ;
}
int F_167 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
T_2 V_19 = F_130 ( V_262 ) ;
int V_265 = F_131 ( V_262 ) ;
int V_232 = F_132 ( V_262 ) ;
int V_220 = F_137 ( V_262 ) ;
long * V_275 = V_274 -> V_268 . integer . V_268 ;
int V_276 = 0 ;
F_15 ( V_7 ) ;
if ( V_265 & 1 ) {
V_276 = F_124 ( V_7 , V_19 , 0 , V_232 , V_220 ,
V_325 ,
* V_275 ? 0 : V_325 ) ;
V_275 ++ ;
}
if ( V_265 & 2 )
V_276 |= F_124 ( V_7 , V_19 , 1 , V_232 , V_220 ,
V_325 ,
* V_275 ? 0 : V_325 ) ;
F_168 ( V_7 , V_19 ) ;
F_18 ( V_7 ) ;
return V_276 ;
}
int F_169 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
long * V_275 = V_274 -> V_268 . integer . V_268 ;
F_170 ( V_7 , * V_275 ) ;
return F_167 ( V_262 , V_274 ) ;
}
int F_171 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
unsigned long V_326 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_326 = V_262 -> V_301 ;
V_262 -> V_301 = V_326 & ~ V_327 ;
V_30 = F_166 ( V_262 , V_274 ) ;
V_262 -> V_301 = V_326 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_172 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
unsigned long V_326 ;
int V_12 , V_328 , V_30 = 0 , V_276 = 0 ;
F_2 ( & V_7 -> V_183 ) ;
V_326 = V_262 -> V_301 ;
V_328 = ( V_326 & V_327 ) >> V_329 ;
for ( V_12 = 0 ; V_12 < V_328 ; V_12 ++ ) {
V_262 -> V_301 = ( V_326 & ~ V_327 ) |
( V_12 << V_329 ) ;
V_30 = F_167 ( V_262 , V_274 ) ;
if ( V_30 < 0 )
break;
V_276 |= V_30 ;
}
V_262 -> V_301 = V_326 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 < 0 ? V_30 : V_276 ;
}
int F_173 ( struct V_261 * V_262 ,
struct V_263 * V_264 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
struct V_330 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_330 * ) V_262 -> V_301 ;
V_262 -> V_301 = * V_135 -> V_331 ;
V_30 = V_135 -> V_33 -> V_222 ( V_262 , V_264 ) ;
V_262 -> V_301 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_174 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
struct V_330 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_330 * ) V_262 -> V_301 ;
V_262 -> V_301 = * V_135 -> V_331 ;
V_30 = V_135 -> V_33 -> V_332 ( V_262 , V_274 ) ;
V_262 -> V_301 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_175 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
struct V_330 * V_135 ;
unsigned long * V_333 ;
int V_30 = 0 , V_276 = 0 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_330 * ) V_262 -> V_301 ;
for ( V_333 = V_135 -> V_331 ; * V_333 ; V_333 ++ ) {
V_262 -> V_301 = * V_333 ;
V_30 = V_135 -> V_33 -> V_334 ( V_262 , V_274 ) ;
if ( V_30 < 0 )
break;
V_276 |= V_30 ;
}
V_262 -> V_301 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 < 0 ? V_30 : V_276 ;
}
int F_176 ( struct V_261 * V_262 , int V_277 ,
unsigned int V_278 , unsigned int T_5 * V_290 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
struct V_330 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_330 * ) V_262 -> V_301 ;
V_262 -> V_301 = * V_135 -> V_331 ;
V_30 = V_135 -> V_33 -> V_290 ( V_262 , V_277 , V_278 , V_290 ) ;
V_262 -> V_301 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
static int F_177 ( struct V_261 * V_262 ,
struct V_263 * V_264 )
{
V_264 -> type = V_335 ;
V_264 -> V_267 = 1 ;
return 0 ;
}
static int F_178 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
V_274 -> V_268 . V_336 . V_337 [ 0 ] = V_338 |
V_339 |
V_340 |
V_341 ;
V_274 -> V_268 . V_336 . V_337 [ 1 ] = V_342 |
V_343 ;
return 0 ;
}
static int F_179 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
V_274 -> V_268 . V_336 . V_337 [ 0 ] = V_338 |
V_339 |
V_344 ;
return 0 ;
}
static int F_180 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
int V_220 = V_262 -> V_301 ;
struct V_187 * V_345 = F_27 ( & V_7 -> V_174 , V_220 ) ;
V_274 -> V_268 . V_336 . V_337 [ 0 ] = V_345 -> V_337 & 0xff ;
V_274 -> V_268 . V_336 . V_337 [ 1 ] = ( V_345 -> V_337 >> 8 ) & 0xff ;
V_274 -> V_268 . V_336 . V_337 [ 2 ] = ( V_345 -> V_337 >> 16 ) & 0xff ;
V_274 -> V_268 . V_336 . V_337 [ 3 ] = ( V_345 -> V_337 >> 24 ) & 0xff ;
return 0 ;
}
static unsigned short F_181 ( unsigned int V_346 )
{
unsigned short V_23 = 0 ;
if ( V_346 & V_338 )
V_23 |= V_347 ;
if ( V_346 & V_339 )
V_23 |= V_348 ;
if ( V_346 & V_338 ) {
if ( ( V_346 & V_349 ) ==
V_344 )
V_23 |= V_350 ;
} else {
if ( ( V_346 & V_351 ) ==
V_340 )
V_23 |= V_350 ;
if ( ! ( V_346 & V_341 ) )
V_23 |= V_352 ;
if ( V_346 & ( V_343 << 8 ) )
V_23 |= V_353 ;
V_23 |= V_346 & ( V_342 << 8 ) ;
}
return V_23 ;
}
static unsigned int F_182 ( unsigned short V_23 )
{
unsigned int V_346 = 0 ;
if ( V_23 & V_348 )
V_346 |= V_339 ;
if ( V_23 & V_347 )
V_346 |= V_338 ;
if ( V_346 & V_338 ) {
if ( V_346 & V_350 )
V_346 |= V_344 ;
} else {
if ( V_23 & V_350 )
V_346 |= V_340 ;
if ( ! ( V_23 & V_352 ) )
V_346 |= V_341 ;
if ( V_23 & V_353 )
V_346 |= ( V_343 << 8 ) ;
V_346 |= V_23 & ( 0x7f << 8 ) ;
}
return V_346 ;
}
static void F_183 ( struct V_6 * V_7 , T_2 V_19 ,
int V_21 , int V_23 )
{
const T_2 * V_354 ;
F_184 ( V_7 , V_19 , 0 , V_21 , V_23 ) ;
V_354 = V_7 -> V_316 ;
if ( ! V_354 )
return;
for (; * V_354 ; V_354 ++ )
F_184 ( V_7 , * V_354 , 0 , V_21 , V_23 ) ;
}
static inline void F_185 ( struct V_6 * V_7 , T_2 V_19 ,
int V_355 , int V_356 )
{
if ( V_355 != - 1 )
F_183 ( V_7 , V_19 , V_357 , V_355 ) ;
if ( V_356 != - 1 )
F_183 ( V_7 , V_19 , V_358 , V_356 ) ;
}
static int F_186 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
int V_220 = V_262 -> V_301 ;
struct V_187 * V_345 = F_27 ( & V_7 -> V_174 , V_220 ) ;
T_2 V_19 = V_345 -> V_19 ;
unsigned short V_23 ;
int V_276 ;
F_2 ( & V_7 -> V_182 ) ;
V_345 -> V_337 = V_274 -> V_268 . V_336 . V_337 [ 0 ] |
( ( unsigned int ) V_274 -> V_268 . V_336 . V_337 [ 1 ] << 8 ) |
( ( unsigned int ) V_274 -> V_268 . V_336 . V_337 [ 2 ] << 16 ) |
( ( unsigned int ) V_274 -> V_268 . V_336 . V_337 [ 3 ] << 24 ) ;
V_23 = F_181 ( V_345 -> V_337 ) ;
V_23 |= V_345 -> V_359 & 1 ;
V_276 = V_345 -> V_359 != V_23 ;
V_345 -> V_359 = V_23 ;
if ( V_276 && V_19 != ( T_3 ) - 1 )
F_185 ( V_7 , V_19 , V_23 & 0xff , ( V_23 >> 8 ) & 0xff ) ;
F_4 ( & V_7 -> V_182 ) ;
return V_276 ;
}
static int F_187 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
int V_220 = V_262 -> V_301 ;
struct V_187 * V_345 = F_27 ( & V_7 -> V_174 , V_220 ) ;
V_274 -> V_268 . integer . V_268 [ 0 ] = V_345 -> V_359 & V_360 ;
return 0 ;
}
static inline void F_188 ( struct V_6 * V_7 , T_2 V_19 ,
int V_355 , int V_356 )
{
F_185 ( V_7 , V_19 , V_355 , V_356 ) ;
if ( ( F_34 ( V_7 , V_19 ) & V_361 ) &&
( V_355 & V_360 ) )
F_125 ( V_7 , V_19 , V_229 , 0 ,
V_325 , 0 ) ;
}
static int F_189 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
int V_220 = V_262 -> V_301 ;
struct V_187 * V_345 = F_27 ( & V_7 -> V_174 , V_220 ) ;
T_2 V_19 = V_345 -> V_19 ;
unsigned short V_23 ;
int V_276 ;
F_2 ( & V_7 -> V_182 ) ;
V_23 = V_345 -> V_359 & ~ V_360 ;
if ( V_274 -> V_268 . integer . V_268 [ 0 ] )
V_23 |= V_360 ;
V_276 = V_345 -> V_359 != V_23 ;
V_345 -> V_359 = V_23 ;
if ( V_276 && V_19 != ( T_3 ) - 1 )
F_188 ( V_7 , V_19 , V_23 & 0xff , - 1 ) ;
F_4 ( & V_7 -> V_182 ) ;
return V_276 ;
}
int F_190 ( struct V_6 * V_7 ,
T_2 V_362 ,
T_2 V_363 )
{
int V_30 ;
struct V_261 * V_295 ;
struct V_364 * V_365 ;
int V_220 ;
struct V_187 * V_345 ;
V_220 = F_146 ( V_7 , L_66 ) ;
if ( V_220 < 0 ) {
F_13 ( V_25 L_67 ) ;
return - V_181 ;
}
V_345 = F_37 ( & V_7 -> V_174 ) ;
for ( V_365 = V_366 ; V_365 -> V_133 ; V_365 ++ ) {
V_295 = F_191 ( V_365 , V_7 ) ;
if ( ! V_295 )
return - V_76 ;
V_295 -> V_126 . V_243 = V_220 ;
V_295 -> V_301 = V_7 -> V_174 . V_48 - 1 ;
V_30 = F_147 ( V_7 , V_362 , V_295 ) ;
if ( V_30 < 0 )
return V_30 ;
}
V_345 -> V_19 = V_363 ;
V_345 -> V_359 = F_21 ( V_7 , V_363 , 0 ,
V_367 , 0 ) ;
V_345 -> V_337 = F_182 ( V_345 -> V_359 ) ;
return 0 ;
}
struct V_187 * F_192 ( struct V_6 * V_7 ,
T_2 V_19 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_174 . V_48 ; V_12 ++ ) {
struct V_187 * V_345 =
F_27 ( & V_7 -> V_174 , V_12 ) ;
if ( V_345 -> V_19 == V_19 )
return V_345 ;
}
return NULL ;
}
void F_193 ( struct V_6 * V_7 , int V_220 )
{
struct V_187 * V_345 = F_27 ( & V_7 -> V_174 , V_220 ) ;
F_2 ( & V_7 -> V_182 ) ;
V_345 -> V_19 = ( T_3 ) - 1 ;
F_4 ( & V_7 -> V_182 ) ;
}
void F_194 ( struct V_6 * V_7 , int V_220 , T_2 V_19 )
{
struct V_187 * V_345 = F_27 ( & V_7 -> V_174 , V_220 ) ;
unsigned short V_23 ;
F_2 ( & V_7 -> V_182 ) ;
if ( V_345 -> V_19 != V_19 ) {
V_345 -> V_19 = V_19 ;
V_23 = V_345 -> V_359 ;
F_188 ( V_7 , V_19 , V_23 & 0xff , ( V_23 >> 8 ) & 0xff ) ;
}
F_4 ( & V_7 -> V_182 ) ;
}
static int F_195 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_368 * V_369 = F_129 ( V_262 ) ;
V_274 -> V_268 . integer . V_268 [ 0 ] = V_369 -> V_370 ;
return 0 ;
}
static int F_196 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_368 * V_369 = F_129 ( V_262 ) ;
V_369 -> V_370 = ! ! V_274 -> V_268 . integer . V_268 [ 0 ] ;
return 0 ;
}
int F_197 ( struct V_6 * V_7 ,
struct V_368 * V_369 )
{
if ( ! V_369 -> V_371 )
return 0 ;
return F_147 ( V_7 , V_369 -> V_371 ,
F_191 ( & V_372 , V_369 ) ) ;
}
static int F_198 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
V_274 -> V_268 . integer . V_268 [ 0 ] = V_7 -> V_373 ;
return 0 ;
}
static int F_199 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
T_2 V_19 = V_262 -> V_301 ;
unsigned int V_23 = ! ! V_274 -> V_268 . integer . V_268 [ 0 ] ;
int V_276 ;
F_2 ( & V_7 -> V_182 ) ;
V_276 = V_7 -> V_373 != V_23 ;
if ( V_276 ) {
V_7 -> V_373 = V_23 ;
F_184 ( V_7 , V_19 , 0 ,
V_357 , V_23 ) ;
}
F_4 ( & V_7 -> V_182 ) ;
return V_276 ;
}
static int F_200 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_129 ( V_262 ) ;
T_2 V_19 = V_262 -> V_301 ;
unsigned short V_23 ;
unsigned int V_346 ;
V_23 = F_21 ( V_7 , V_19 , 0 , V_367 , 0 ) ;
V_346 = F_182 ( V_23 ) ;
V_274 -> V_268 . V_336 . V_337 [ 0 ] = V_346 ;
V_274 -> V_268 . V_336 . V_337 [ 1 ] = V_346 >> 8 ;
V_274 -> V_268 . V_336 . V_337 [ 2 ] = V_346 >> 16 ;
V_274 -> V_268 . V_336 . V_337 [ 3 ] = V_346 >> 24 ;
return 0 ;
}
int F_201 ( struct V_6 * V_7 , T_2 V_19 )
{
int V_30 ;
struct V_261 * V_295 ;
struct V_364 * V_365 ;
int V_220 ;
V_220 = F_146 ( V_7 , L_68 ) ;
if ( V_220 < 0 ) {
F_13 ( V_25 L_69 ) ;
return - V_181 ;
}
for ( V_365 = V_374 ; V_365 -> V_133 ; V_365 ++ ) {
V_295 = F_191 ( V_365 , V_7 ) ;
if ( ! V_295 )
return - V_76 ;
V_295 -> V_301 = V_19 ;
V_30 = F_147 ( V_7 , V_19 , V_295 ) ;
if ( V_30 < 0 )
return V_30 ;
}
V_7 -> V_373 =
F_21 ( V_7 , V_19 , 0 ,
V_367 , 0 ) &
V_360 ;
return 0 ;
}
int F_184 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 , unsigned int V_21 , unsigned int V_22 )
{
int V_30 = F_22 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
struct V_185 * V_135 ;
T_1 V_219 ;
if ( V_30 < 0 )
return V_30 ;
V_21 = V_21 | ( V_22 >> 8 ) ;
V_22 &= 0xff ;
V_219 = F_202 ( V_19 , V_21 ) ;
F_2 ( & V_7 -> V_29 -> V_32 ) ;
V_135 = F_107 ( & V_7 -> V_176 , V_219 ) ;
if ( V_135 )
V_135 -> V_23 = V_22 ;
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return 0 ;
}
int F_203 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 , unsigned int V_21 , unsigned int V_22 )
{
struct V_185 * V_135 ;
T_1 V_219 ;
V_21 = V_21 | ( V_22 >> 8 ) ;
V_22 &= 0xff ;
V_219 = F_202 ( V_19 , V_21 ) ;
F_2 ( & V_7 -> V_29 -> V_32 ) ;
V_135 = F_106 ( & V_7 -> V_176 , V_219 ) ;
if ( V_135 && V_135 -> V_23 == V_22 ) {
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return 0 ;
}
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return F_184 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
}
void F_204 ( struct V_6 * V_7 )
{
struct V_185 * V_257 = V_7 -> V_176 . V_218 . V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_176 . V_218 . V_48 ; V_12 ++ , V_257 ++ ) {
T_1 V_219 = V_257 -> V_219 ;
if ( ! V_219 )
continue;
F_22 ( V_7 , F_205 ( V_219 ) , 0 ,
F_206 ( V_219 ) , V_257 -> V_23 ) ;
}
}
void F_207 ( struct V_6 * V_7 ,
const struct V_40 * V_41 )
{
for (; V_41 -> V_19 ; V_41 ++ )
F_184 ( V_7 , V_41 -> V_19 , 0 , V_41 -> V_21 ,
V_41 -> V_42 ) ;
}
void F_208 ( struct V_6 * V_7 , T_2 V_375 ,
unsigned int V_376 ,
bool V_377 )
{
T_2 V_19 = V_7 -> V_154 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_153 ; V_12 ++ , V_19 ++ ) {
unsigned int V_62 = F_34 ( V_7 , V_19 ) ;
if ( ! ( V_62 & V_378 ) )
continue;
if ( V_377 && V_376 == V_379 &&
F_35 ( V_62 ) == V_82 &&
( F_114 ( V_7 , V_19 ) & V_380 ) ) {
int V_381 = F_21 ( V_7 , V_19 , 0 ,
V_382 , 0 ) ;
if ( V_381 & 0x02 )
continue;
}
F_22 ( V_7 , V_19 , 0 , V_383 ,
V_376 ) ;
}
if ( V_376 == V_195 ) {
unsigned long V_384 ;
int V_385 ;
V_384 = V_386 + F_209 ( 500 ) ;
do {
V_385 = F_21 ( V_7 , V_375 , 0 ,
V_387 , 0 ) ;
if ( V_385 == V_376 )
break;
F_101 ( 1 ) ;
} while ( F_210 ( V_384 , V_386 ) );
}
}
static void F_94 ( struct V_6 * V_7 , T_2 V_375 ,
unsigned int V_376 )
{
if ( V_7 -> V_96 . V_388 ) {
V_7 -> V_96 . V_388 ( V_7 , V_375 , V_376 ) ;
return;
}
if ( V_376 == V_379 )
F_101 ( 100 ) ;
F_21 ( V_7 , V_375 , 0 , V_383 ,
V_376 ) ;
F_208 ( V_7 , V_375 , V_376 , true ) ;
}
static void F_211 ( struct V_6 * V_7 )
{
if ( V_7 -> V_389 . V_4 )
F_23 ( V_7 , V_7 -> V_389 . V_4 ) ;
}
static inline void F_211 ( struct V_6 * V_7 ) {}
static void F_212 ( struct V_6 * V_7 )
{
if ( V_7 -> V_96 . V_390 )
V_7 -> V_96 . V_390 ( V_7 , V_391 ) ;
F_105 ( V_7 ) ;
F_94 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_379 ) ;
#ifdef F_86
F_213 ( V_7 ) ;
F_87 ( & V_7 -> V_171 ) ;
V_7 -> V_392 = 0 ;
V_7 -> V_393 = 0 ;
V_7 -> V_394 = V_386 ;
#endif
}
static void F_214 ( struct V_6 * V_7 )
{
F_94 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_195 ) ;
F_80 ( V_7 ) ;
F_82 ( V_7 ) ;
F_211 ( V_7 ) ;
if ( V_7 -> V_96 . V_395 )
V_7 -> V_96 . V_395 ( V_7 ) ;
else {
if ( V_7 -> V_96 . V_396 )
V_7 -> V_96 . V_396 ( V_7 ) ;
F_126 ( V_7 ) ;
F_204 ( V_7 ) ;
}
}
int F_215 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
int V_30 = F_216 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_70
L_71 , V_7 -> V_24 , V_30 ) ;
V_30 = F_157 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25
L_72 ) ;
return V_30 ;
}
}
}
return 0 ;
}
int F_216 ( struct V_6 * V_7 )
{
int V_30 = 0 ;
F_211 ( V_7 ) ;
if ( V_7 -> V_96 . V_396 )
V_30 = V_7 -> V_96 . V_396 ( V_7 ) ;
if ( ! V_30 && V_7 -> V_96 . V_397 )
V_30 = V_7 -> V_96 . V_397 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
unsigned int F_217 ( unsigned int V_398 ,
unsigned int V_399 ,
unsigned int V_201 ,
unsigned int V_400 ,
unsigned short V_401 )
{
int V_12 ;
unsigned int V_23 = 0 ;
for ( V_12 = 0 ; V_402 [ V_12 ] . V_403 ; V_12 ++ )
if ( V_402 [ V_12 ] . V_403 == V_398 ) {
V_23 = V_402 [ V_12 ] . V_404 ;
break;
}
if ( ! V_402 [ V_12 ] . V_403 ) {
F_93 ( L_73 , V_398 ) ;
return 0 ;
}
if ( V_399 == 0 || V_399 > 8 ) {
F_93 ( L_74 , V_399 ) ;
return 0 ;
}
V_23 |= V_399 - 1 ;
switch ( F_218 ( V_201 ) ) {
case 8 :
V_23 |= V_405 ;
break;
case 16 :
V_23 |= V_406 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_400 >= 32 || V_201 == V_407 )
V_23 |= V_408 ;
else if ( V_400 >= 24 )
V_23 |= V_409 ;
else
V_23 |= V_410 ;
break;
default:
F_93 ( L_75 ,
F_218 ( V_201 ) ) ;
return 0 ;
}
if ( V_401 & V_348 )
V_23 |= V_411 ;
return V_23 ;
}
static unsigned int F_219 ( struct V_6 * V_7 , T_2 V_19 )
{
unsigned int V_23 = 0 ;
if ( V_19 != V_7 -> V_127 &&
( F_34 ( V_7 , V_19 ) & V_412 ) )
V_23 = F_25 ( V_7 , V_19 , V_413 ) ;
if ( ! V_23 || V_23 == - 1 )
V_23 = F_25 ( V_7 , V_7 -> V_127 , V_413 ) ;
if ( ! V_23 || V_23 == - 1 )
return 0 ;
return V_23 ;
}
static unsigned int F_220 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_115 ( V_7 , V_19 , F_221 ( V_19 ) ,
F_219 ) ;
}
static unsigned int F_222 ( struct V_6 * V_7 , T_2 V_19 )
{
unsigned int V_311 = F_25 ( V_7 , V_19 , V_414 ) ;
if ( ! V_311 || V_311 == - 1 )
V_311 = F_25 ( V_7 , V_7 -> V_127 , V_414 ) ;
if ( ! V_311 || V_311 == - 1 )
return 0 ;
return V_311 ;
}
static unsigned int F_223 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_115 ( V_7 , V_19 , F_224 ( V_19 ) ,
F_222 ) ;
}
int F_225 ( struct V_6 * V_7 , T_2 V_19 ,
T_1 * V_415 , T_7 * V_416 , unsigned int * V_417 )
{
unsigned int V_12 , V_23 , V_62 ;
V_62 = F_34 ( V_7 , V_19 ) ;
V_23 = F_220 ( V_7 , V_19 ) ;
if ( V_415 ) {
T_1 V_418 = 0 ;
for ( V_12 = 0 ; V_12 < V_419 ; V_12 ++ ) {
if ( V_23 & ( 1 << V_12 ) )
V_418 |= V_402 [ V_12 ] . V_420 ;
}
if ( V_418 == 0 ) {
F_33 ( V_25 L_76
L_77 ,
V_19 , V_23 ,
( V_62 & V_412 ) ? 1 : 0 ) ;
return - V_70 ;
}
* V_415 = V_418 ;
}
if ( V_416 || V_417 ) {
T_7 V_421 = 0 ;
unsigned int V_311 , V_422 ;
V_311 = F_223 ( V_7 , V_19 ) ;
if ( ! V_311 )
return - V_70 ;
V_422 = 0 ;
if ( V_311 & V_423 ) {
if ( V_23 & V_424 ) {
V_421 |= V_425 ;
V_422 = 8 ;
}
if ( V_23 & V_426 ) {
V_421 |= V_427 ;
V_422 = 16 ;
}
if ( V_62 & V_428 ) {
if ( V_23 & V_429 )
V_421 |= V_430 ;
if ( V_23 & ( V_431 | V_432 ) )
V_421 |= V_433 ;
if ( V_23 & V_432 )
V_422 = 24 ;
else if ( V_23 & V_431 )
V_422 = 20 ;
} else if ( V_23 & ( V_431 | V_432 |
V_429 ) ) {
V_421 |= V_433 ;
if ( V_23 & V_429 )
V_422 = 32 ;
else if ( V_23 & V_432 )
V_422 = 24 ;
else if ( V_23 & V_431 )
V_422 = 20 ;
}
}
if ( V_311 & V_434 ) {
V_421 |= V_435 ;
if ( ! V_422 )
V_422 = 32 ;
}
if ( V_311 == V_436 ) {
V_421 |= V_425 ;
V_422 = 8 ;
}
if ( V_421 == 0 ) {
F_33 ( V_25 L_78
L_79
L_80 ,
V_19 , V_23 ,
( V_62 & V_412 ) ? 1 : 0 ,
V_311 ) ;
return - V_70 ;
}
if ( V_416 )
* V_416 = V_421 ;
if ( V_417 )
* V_417 = V_422 ;
}
return 0 ;
}
int F_226 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_201 )
{
int V_12 ;
unsigned int V_23 = 0 , V_398 , V_437 ;
V_23 = F_220 ( V_7 , V_19 ) ;
if ( ! V_23 )
return 0 ;
V_398 = V_201 & 0xff00 ;
for ( V_12 = 0 ; V_12 < V_419 ; V_12 ++ )
if ( V_402 [ V_12 ] . V_404 == V_398 ) {
if ( V_23 & ( 1 << V_12 ) )
break;
return 0 ;
}
if ( V_12 >= V_419 )
return 0 ;
V_437 = F_223 ( V_7 , V_19 ) ;
if ( ! V_437 )
return 0 ;
if ( V_437 & V_423 ) {
switch ( V_201 & 0xf0 ) {
case 0x00 :
if ( ! ( V_23 & V_424 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_23 & V_426 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_23 & V_431 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_23 & V_432 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_23 & V_429 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_227 ( struct V_438 * V_439 ,
struct V_6 * V_7 ,
struct V_440 * V_441 )
{
return 0 ;
}
static int F_228 ( struct V_438 * V_439 ,
struct V_6 * V_7 ,
unsigned int V_199 ,
unsigned int V_201 ,
struct V_440 * V_441 )
{
F_100 ( V_7 , V_439 -> V_19 , V_199 , 0 , V_201 ) ;
return 0 ;
}
static int F_229 ( struct V_438 * V_439 ,
struct V_6 * V_7 ,
struct V_440 * V_441 )
{
F_230 ( V_7 , V_439 -> V_19 ) ;
return 0 ;
}
static int F_231 ( struct V_6 * V_7 ,
struct V_438 * V_222 )
{
int V_30 ;
if ( V_222 -> V_19 && ( ! V_222 -> V_418 || ! V_222 -> V_421 ) ) {
V_30 = F_225 ( V_7 , V_222 -> V_19 ,
V_222 -> V_418 ? NULL : & V_222 -> V_418 ,
V_222 -> V_421 ? NULL : & V_222 -> V_421 ,
V_222 -> V_400 ? NULL : & V_222 -> V_400 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( V_222 -> V_33 . V_442 == NULL )
V_222 -> V_33 . V_442 = F_227 ;
if ( V_222 -> V_33 . V_443 == NULL )
V_222 -> V_33 . V_443 = F_227 ;
if ( V_222 -> V_33 . V_444 == NULL ) {
if ( F_29 ( ! V_222 -> V_19 ) )
return - V_54 ;
V_222 -> V_33 . V_444 = F_228 ;
}
if ( V_222 -> V_33 . V_445 == NULL ) {
if ( F_29 ( ! V_222 -> V_19 ) )
return - V_54 ;
V_222 -> V_33 . V_445 = F_229 ;
}
return 0 ;
}
int F_232 ( struct V_6 * V_7 ,
struct V_438 * V_439 ,
unsigned int V_437 ,
unsigned int V_201 ,
struct V_440 * V_441 )
{
int V_256 ;
F_2 ( & V_7 -> V_29 -> V_117 ) ;
V_256 = V_439 -> V_33 . V_444 ( V_439 , V_7 , V_437 , V_201 , V_441 ) ;
if ( V_256 >= 0 )
F_104 ( V_7 ) ;
F_4 ( & V_7 -> V_29 -> V_117 ) ;
return V_256 ;
}
void F_233 ( struct V_6 * V_7 ,
struct V_438 * V_439 ,
struct V_440 * V_441 )
{
F_2 ( & V_7 -> V_29 -> V_117 ) ;
V_439 -> V_33 . V_445 ( V_439 , V_7 , V_441 ) ;
F_4 ( & V_7 -> V_29 -> V_117 ) ;
}
static int F_234 ( struct V_28 * V_29 , int type )
{
static int V_446 [ V_447 ] [ 5 ] = {
[ V_448 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_449 ] = { 1 , - 1 } ,
[ V_450 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_451 ] = { 6 , - 1 } ,
} ;
int V_12 ;
if ( type >= V_447 ) {
F_33 ( V_73 L_81 , type ) ;
return - V_54 ;
}
for ( V_12 = 0 ; V_446 [ type ] [ V_12 ] >= 0 ; V_12 ++ )
if ( ! F_235 ( V_446 [ type ] [ V_12 ] , V_29 -> V_313 ) )
return V_446 [ type ] [ V_12 ] ;
F_33 ( V_73 L_82 ,
V_452 [ type ] ) ;
return - V_453 ;
}
static int F_236 ( struct V_6 * V_7 , struct V_308 * V_305 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
struct V_438 * V_222 ;
int V_437 , V_30 ;
if ( F_29 ( ! V_305 -> V_133 ) )
return - V_54 ;
for ( V_437 = 0 ; V_437 < 2 ; V_437 ++ ) {
V_222 = & V_305 -> V_437 [ V_437 ] ;
if ( V_222 -> V_454 ) {
V_30 = F_231 ( V_7 , V_222 ) ;
if ( V_30 < 0 )
return V_30 ;
}
}
return V_29 -> V_33 . V_455 ( V_29 , V_7 , V_305 ) ;
}
int F_237 ( struct V_6 * V_7 )
{
unsigned int V_305 ;
int V_30 ;
if ( ! V_7 -> V_307 ) {
if ( ! V_7 -> V_96 . V_456 )
return 0 ;
V_30 = V_7 -> V_96 . V_456 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_83
L_71 , V_7 -> V_24 , V_30 ) ;
V_30 = F_157 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25
L_72 ) ;
return V_30 ;
}
}
}
for ( V_305 = 0 ; V_305 < V_7 -> V_307 ; V_305 ++ ) {
struct V_308 * V_309 = & V_7 -> V_310 [ V_305 ] ;
int V_457 ;
if ( ! V_309 -> V_437 [ 0 ] . V_454 && ! V_309 -> V_437 [ 1 ] . V_454 )
continue;
if ( ! V_309 -> V_305 ) {
V_457 = F_234 ( V_7 -> V_29 , V_309 -> V_458 ) ;
if ( V_457 < 0 )
continue;
V_309 -> V_101 = V_457 ;
V_30 = F_236 ( V_7 , V_309 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_84
L_85 ,
V_457 , V_7 -> V_24 ) ;
continue;
}
}
}
return 0 ;
}
int T_8 F_238 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
int V_30 = F_237 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
}
return 0 ;
}
int F_239 ( struct V_6 * V_7 ,
int V_459 , const char * const * V_460 ,
const struct V_461 * V_123 )
{
if ( V_7 -> V_115 && V_460 ) {
int V_12 ;
for ( V_12 = 0 ; V_12 < V_459 ; V_12 ++ ) {
if ( V_460 [ V_12 ] &&
! strcmp ( V_7 -> V_115 , V_460 [ V_12 ] ) ) {
F_19 ( V_462 L_86
L_87 , V_460 [ V_12 ] ) ;
return V_12 ;
}
}
}
if ( ! V_7 -> V_29 -> V_114 || ! V_123 )
return - 1 ;
V_123 = F_240 ( V_7 -> V_29 -> V_114 , V_123 ) ;
if ( ! V_123 )
return - 1 ;
if ( V_123 -> V_268 >= 0 && V_123 -> V_268 < V_459 ) {
#ifdef F_241
char V_137 [ 10 ] ;
const char * V_463 = NULL ;
if ( V_460 )
V_463 = V_460 [ V_123 -> V_268 ] ;
if ( ! V_463 ) {
sprintf ( V_137 , L_88 , V_123 -> V_268 ) ;
V_463 = V_137 ;
}
F_93 ( V_462 L_89
L_90 ,
V_463 , V_123 -> V_464 , V_123 -> V_298 ,
( V_123 -> V_133 ? V_123 -> V_133 : L_91 ) ) ;
#endif
return V_123 -> V_268 ;
}
return - 1 ;
}
int F_242 ( struct V_6 * V_7 ,
int V_459 , const char * const * V_460 ,
const struct V_461 * V_123 )
{
const struct V_461 * V_213 ;
for ( V_213 = V_123 ; V_213 -> V_464 ; V_213 ++ ) {
unsigned int V_61 = 0xffff0000 | V_213 -> V_465 ;
unsigned int V_126 = ( V_213 -> V_298 | ( V_213 -> V_464 << 16 ) ) & V_61 ;
if ( ( V_7 -> V_191 & V_61 ) == V_126 )
break;
}
if ( ! V_213 -> V_464 )
return - 1 ;
V_123 = V_213 ;
if ( V_123 -> V_268 >= 0 && V_123 -> V_268 < V_459 ) {
#ifdef F_241
char V_137 [ 10 ] ;
const char * V_463 = NULL ;
if ( V_460 )
V_463 = V_460 [ V_123 -> V_268 ] ;
if ( ! V_463 ) {
sprintf ( V_137 , L_88 , V_123 -> V_268 ) ;
V_463 = V_137 ;
}
F_93 ( V_462 L_89
L_90 ,
V_463 , V_123 -> V_464 , V_123 -> V_298 ,
( V_123 -> V_133 ? V_123 -> V_133 : L_91 ) ) ;
#endif
return V_123 -> V_268 ;
}
return - 1 ;
}
int F_243 ( struct V_6 * V_7 ,
const struct V_364 * V_466 )
{
int V_30 ;
for (; V_466 -> V_133 ; V_466 ++ ) {
struct V_261 * V_295 ;
int V_24 = 0 , V_220 = 0 ;
if ( V_466 -> V_293 == - 1 )
continue;
for (; ; ) {
V_295 = F_191 ( V_466 , V_7 ) ;
if ( ! V_295 )
return - V_76 ;
if ( V_24 > 0 )
V_295 -> V_126 . V_101 = V_24 ;
if ( V_220 > 0 )
V_295 -> V_126 . V_243 = V_220 ;
V_30 = F_147 ( V_7 , 0 , V_295 ) ;
if ( ! V_30 )
break;
if ( ! V_24 && V_7 -> V_24 )
V_24 = V_7 -> V_24 ;
else if ( ! V_220 && ! V_466 -> V_243 ) {
V_220 = F_146 ( V_7 ,
V_466 -> V_133 ) ;
if ( V_220 <= 0 )
return V_30 ;
} else
return V_30 ;
}
}
return 0 ;
}
static void V_189 ( struct V_92 * V_91 )
{
struct V_6 * V_7 =
F_43 ( V_91 , struct V_6 , V_171 . V_91 ) ;
struct V_28 * V_29 = V_7 -> V_29 ;
if ( ! V_7 -> V_392 || V_7 -> V_467 ) {
V_7 -> V_393 = 0 ;
return;
}
F_244 ( V_7 ) ;
F_212 ( V_7 ) ;
if ( V_29 -> V_33 . V_468 )
V_29 -> V_33 . V_468 ( V_29 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
V_7 -> V_467 ++ ;
V_7 -> V_392 = 1 ;
V_7 -> V_394 = V_386 ;
}
void F_213 ( struct V_6 * V_7 )
{
unsigned long V_469 = V_386 - V_7 -> V_394 ;
if ( V_7 -> V_392 )
V_7 -> V_470 += V_469 ;
else
V_7 -> V_471 += V_469 ;
V_7 -> V_394 += V_469 ;
}
void F_15 ( struct V_6 * V_7 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
V_7 -> V_467 ++ ;
if ( V_7 -> V_392 || V_7 -> V_393 )
return;
F_245 ( V_7 ) ;
F_213 ( V_7 ) ;
V_7 -> V_392 = 1 ;
V_7 -> V_394 = V_386 ;
if ( V_29 -> V_33 . V_468 )
V_29 -> V_33 . V_468 ( V_29 ) ;
F_214 ( V_7 ) ;
F_87 ( & V_7 -> V_171 ) ;
V_7 -> V_393 = 0 ;
}
void F_18 ( struct V_6 * V_7 )
{
-- V_7 -> V_467 ;
if ( ! V_7 -> V_392 || V_7 -> V_467 || V_7 -> V_393 )
return;
if ( V_116 ( V_7 ) ) {
V_7 -> V_393 = 1 ;
F_246 ( V_7 -> V_29 -> V_90 , & V_7 -> V_171 ,
F_209 ( V_116 ( V_7 ) * 1000 ) ) ;
}
}
int F_247 ( struct V_6 * V_7 ,
struct V_472 * V_473 ,
T_2 V_19 )
{
const struct V_474 * V_49 ;
int V_242 , V_475 ;
if ( ! V_473 -> V_476 )
return 0 ;
for ( V_49 = V_473 -> V_476 ; V_49 -> V_19 ; V_49 ++ ) {
if ( V_49 -> V_19 == V_19 )
break;
}
if ( ! V_49 -> V_19 )
return 0 ;
for ( V_49 = V_473 -> V_476 ; V_49 -> V_19 ; V_49 ++ ) {
for ( V_242 = 0 ; V_242 < 2 ; V_242 ++ ) {
V_475 = F_123 ( V_7 , V_49 -> V_19 , V_242 , V_49 -> V_232 ,
V_49 -> V_220 ) ;
if ( ! ( V_475 & V_325 ) && V_475 > 0 ) {
if ( ! V_473 -> V_392 ) {
V_473 -> V_392 = 1 ;
F_15 ( V_7 ) ;
}
return 1 ;
}
}
}
if ( V_473 -> V_392 ) {
V_473 -> V_392 = 0 ;
F_18 ( V_7 ) ;
}
return 0 ;
}
int F_248 ( struct V_6 * V_7 ,
struct V_263 * V_264 ,
const struct V_477 * V_478 ,
int V_479 )
{
V_264 -> type = V_480 ;
V_264 -> V_267 = 1 ;
V_264 -> V_268 . V_481 . V_303 = V_479 ;
if ( V_264 -> V_268 . V_481 . V_297 >= V_479 )
V_264 -> V_268 . V_481 . V_297 = V_479 - 1 ;
sprintf ( V_264 -> V_268 . V_481 . V_133 , L_92 ,
V_478 [ V_264 -> V_268 . V_481 . V_297 ] . V_399 ) ;
return 0 ;
}
int F_249 ( struct V_6 * V_7 ,
struct V_273 * V_274 ,
const struct V_477 * V_478 ,
int V_479 ,
int V_482 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_479 ; V_12 ++ ) {
if ( V_482 == V_478 [ V_12 ] . V_399 ) {
V_274 -> V_268 . V_481 . V_297 [ 0 ] = V_12 ;
break;
}
}
return 0 ;
}
int F_250 ( struct V_6 * V_7 ,
struct V_273 * V_274 ,
const struct V_477 * V_478 ,
int V_479 ,
int * V_483 )
{
unsigned int V_484 ;
V_484 = V_274 -> V_268 . V_481 . V_297 [ 0 ] ;
if ( V_484 >= V_479 )
return - V_54 ;
if ( * V_483 == V_478 [ V_484 ] . V_399 )
return 0 ;
* V_483 = V_478 [ V_484 ] . V_399 ;
if ( V_478 [ V_484 ] . V_485 )
F_207 ( V_7 , V_478 [ V_484 ] . V_485 ) ;
return 1 ;
}
int F_251 ( const struct V_486 * V_487 ,
struct V_263 * V_264 )
{
unsigned int V_243 ;
V_264 -> type = V_480 ;
V_264 -> V_267 = 1 ;
V_264 -> V_268 . V_481 . V_303 = V_487 -> V_488 ;
if ( ! V_487 -> V_488 )
return 0 ;
V_243 = V_264 -> V_268 . V_481 . V_297 ;
if ( V_243 >= V_487 -> V_488 )
V_243 = V_487 -> V_488 - 1 ;
strcpy ( V_264 -> V_268 . V_481 . V_133 , V_487 -> V_303 [ V_243 ] . V_489 ) ;
return 0 ;
}
int F_252 ( struct V_6 * V_7 ,
const struct V_486 * V_487 ,
struct V_273 * V_274 ,
T_2 V_19 ,
unsigned int * V_490 )
{
unsigned int V_220 ;
if ( ! V_487 -> V_488 )
return 0 ;
V_220 = V_274 -> V_268 . V_481 . V_297 [ 0 ] ;
if ( V_220 >= V_487 -> V_488 )
V_220 = V_487 -> V_488 - 1 ;
if ( * V_490 == V_220 )
return 0 ;
F_184 ( V_7 , V_19 , 0 , V_491 ,
V_487 -> V_303 [ V_220 ] . V_243 ) ;
* V_490 = V_220 ;
return 1 ;
}
static void F_253 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_199 , unsigned int V_201 )
{
struct V_187 * V_345 = F_192 ( V_7 , V_19 ) ;
if ( V_7 -> V_317 && ( V_345 -> V_359 & V_360 ) )
F_185 ( V_7 , V_19 ,
V_345 -> V_359 & ~ V_360 & 0xff ,
- 1 ) ;
F_100 ( V_7 , V_19 , V_199 , 0 , V_201 ) ;
if ( V_7 -> V_316 ) {
const T_2 * V_354 ;
for ( V_354 = V_7 -> V_316 ; * V_354 ; V_354 ++ )
F_100 ( V_7 , * V_354 , V_199 , 0 ,
V_201 ) ;
}
if ( V_7 -> V_317 && ( V_345 -> V_359 & V_360 ) )
F_185 ( V_7 , V_19 ,
V_345 -> V_359 & 0xff , - 1 ) ;
}
static void F_254 ( struct V_6 * V_7 , T_2 V_19 )
{
F_230 ( V_7 , V_19 ) ;
if ( V_7 -> V_316 ) {
const T_2 * V_354 ;
for ( V_354 = V_7 -> V_316 ; * V_354 ; V_354 ++ )
F_230 ( V_7 , * V_354 ) ;
}
}
void F_255 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
if ( ! V_29 )
return;
F_55 (codec, &bus->codec_list, list) {
if ( F_256 ( V_7 ) &&
V_7 -> V_96 . V_492 )
V_7 -> V_96 . V_492 ( V_7 ) ;
}
}
int F_257 ( struct V_6 * V_7 ,
struct V_368 * V_369 )
{
F_2 ( & V_7 -> V_182 ) ;
if ( V_369 -> V_493 == V_494 )
F_254 ( V_7 , V_369 -> V_371 ) ;
V_369 -> V_493 = V_495 ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_258 ( struct V_6 * V_7 ,
struct V_368 * V_369 ,
unsigned int V_199 ,
unsigned int V_201 ,
struct V_440 * V_441 )
{
F_2 ( & V_7 -> V_182 ) ;
F_253 ( V_7 , V_369 -> V_371 , V_199 , V_201 ) ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_259 ( struct V_6 * V_7 ,
struct V_368 * V_369 )
{
F_2 ( & V_7 -> V_182 ) ;
F_254 ( V_7 , V_369 -> V_371 ) ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_260 ( struct V_6 * V_7 ,
struct V_368 * V_369 )
{
F_2 ( & V_7 -> V_182 ) ;
V_369 -> V_493 = 0 ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_261 ( struct V_6 * V_7 ,
struct V_368 * V_369 ,
struct V_440 * V_441 ,
struct V_438 * V_439 )
{
struct V_496 * V_497 = V_441 -> V_497 ;
V_497 -> V_498 . V_499 = V_369 -> V_482 ;
if ( V_369 -> V_371 ) {
if ( ! V_369 -> V_500 ) {
V_369 -> V_500 = V_439 -> V_418 ;
V_369 -> V_501 = V_439 -> V_421 ;
V_369 -> V_502 = V_439 -> V_400 ;
} else {
V_497 -> V_498 . V_418 = V_369 -> V_500 ;
V_497 -> V_498 . V_421 = V_369 -> V_501 ;
V_439 -> V_400 = V_369 -> V_502 ;
}
if ( ! V_369 -> V_503 ) {
F_225 ( V_7 , V_369 -> V_371 ,
& V_369 -> V_503 ,
& V_369 -> V_504 ,
& V_369 -> V_505 ) ;
}
F_2 ( & V_7 -> V_182 ) ;
if ( V_369 -> V_370 ) {
if ( ( V_497 -> V_498 . V_418 & V_369 -> V_503 ) &&
( V_497 -> V_498 . V_421 & V_369 -> V_504 ) ) {
V_497 -> V_498 . V_418 &= V_369 -> V_503 ;
V_497 -> V_498 . V_421 &= V_369 -> V_504 ;
if ( V_369 -> V_505 < V_439 -> V_400 )
V_439 -> V_400 = V_369 -> V_505 ;
} else {
V_369 -> V_370 = 0 ;
}
}
F_4 ( & V_7 -> V_182 ) ;
}
return F_262 ( V_441 -> V_497 , 0 ,
V_506 , 2 ) ;
}
int F_263 ( struct V_6 * V_7 ,
struct V_368 * V_369 ,
unsigned int V_199 ,
unsigned int V_201 ,
struct V_440 * V_441 )
{
const T_2 * V_173 = V_369 -> V_507 ;
int V_265 = V_441 -> V_497 -> V_399 ;
struct V_187 * V_345 =
F_192 ( V_7 , V_369 -> V_371 ) ;
int V_12 ;
F_2 ( & V_7 -> V_182 ) ;
if ( V_369 -> V_371 && V_369 -> V_370 &&
V_369 -> V_493 != V_495 ) {
if ( V_265 == 2 &&
F_226 ( V_7 , V_369 -> V_371 ,
V_201 ) &&
! ( V_345 -> V_337 & V_339 ) ) {
V_369 -> V_493 = V_494 ;
F_253 ( V_7 , V_369 -> V_371 ,
V_199 , V_201 ) ;
} else {
V_369 -> V_493 = 0 ;
F_254 ( V_7 , V_369 -> V_371 ) ;
}
}
F_4 ( & V_7 -> V_182 ) ;
F_100 ( V_7 , V_173 [ V_508 ] , V_199 ,
0 , V_201 ) ;
if ( ! V_369 -> V_509 &&
V_369 -> V_510 && V_369 -> V_510 != V_173 [ V_508 ] )
F_100 ( V_7 , V_369 -> V_510 , V_199 ,
0 , V_201 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_369 -> V_511 ) ; V_12 ++ )
if ( ! V_369 -> V_509 && V_369 -> V_511 [ V_12 ] )
F_100 ( V_7 ,
V_369 -> V_511 [ V_12 ] ,
V_199 , 0 , V_201 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_369 -> V_512 ) ; V_12 ++ )
if ( ! V_369 -> V_509 && V_369 -> V_512 [ V_12 ] )
F_100 ( V_7 ,
V_369 -> V_512 [ V_12 ] ,
V_199 , 0 , V_201 ) ;
for ( V_12 = 1 ; V_12 < V_369 -> V_513 ; V_12 ++ ) {
if ( V_265 >= ( V_12 + 1 ) * 2 )
F_100 ( V_7 , V_173 [ V_12 ] , V_199 ,
V_12 * 2 , V_201 ) ;
else if ( ! V_369 -> V_509 )
F_100 ( V_7 , V_173 [ V_12 ] , V_199 ,
0 , V_201 ) ;
}
return 0 ;
}
int F_264 ( struct V_6 * V_7 ,
struct V_368 * V_369 )
{
const T_2 * V_173 = V_369 -> V_507 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_369 -> V_513 ; V_12 ++ )
F_230 ( V_7 , V_173 [ V_12 ] ) ;
if ( V_369 -> V_510 )
F_230 ( V_7 , V_369 -> V_510 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_369 -> V_511 ) ; V_12 ++ )
if ( V_369 -> V_511 [ V_12 ] )
F_230 ( V_7 ,
V_369 -> V_511 [ V_12 ] ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_369 -> V_512 ) ; V_12 ++ )
if ( V_369 -> V_512 [ V_12 ] )
F_230 ( V_7 ,
V_369 -> V_512 [ V_12 ] ) ;
F_2 ( & V_7 -> V_182 ) ;
if ( V_369 -> V_371 && V_369 -> V_493 == V_494 ) {
F_254 ( V_7 , V_369 -> V_371 ) ;
V_369 -> V_493 = 0 ;
}
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
static int F_265 ( T_2 V_19 , const T_2 * V_4 )
{
for (; * V_4 ; V_4 ++ )
if ( * V_4 == V_19 )
return 1 ;
return 0 ;
}
static void F_266 ( T_2 * V_514 , short * V_515 ,
int V_516 )
{
int V_12 , V_517 ;
short V_41 ;
T_2 V_19 ;
for ( V_12 = 0 ; V_12 < V_516 ; V_12 ++ ) {
for ( V_517 = V_12 + 1 ; V_517 < V_516 ; V_517 ++ ) {
if ( V_515 [ V_12 ] > V_515 [ V_517 ] ) {
V_41 = V_515 [ V_12 ] ;
V_515 [ V_12 ] = V_515 [ V_517 ] ;
V_515 [ V_517 ] = V_41 ;
V_19 = V_514 [ V_12 ] ;
V_514 [ V_12 ] = V_514 [ V_517 ] ;
V_514 [ V_517 ] = V_19 ;
}
}
}
}
static void F_267 ( struct V_518 * V_8 , T_2 V_19 ,
int type )
{
if ( V_8 -> V_519 < V_520 ) {
V_8 -> V_521 [ V_8 -> V_519 ] . V_157 = V_19 ;
V_8 -> V_521 [ V_8 -> V_519 ] . type = type ;
V_8 -> V_519 ++ ;
}
}
static void F_268 ( struct V_518 * V_8 )
{
int V_12 , V_517 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_519 ; V_12 ++ ) {
for ( V_517 = V_12 + 1 ; V_517 < V_8 -> V_519 ; V_517 ++ ) {
if ( V_8 -> V_521 [ V_12 ] . type > V_8 -> V_521 [ V_517 ] . type ) {
struct V_522 V_137 ;
V_137 = V_8 -> V_521 [ V_12 ] ;
V_8 -> V_521 [ V_12 ] = V_8 -> V_521 [ V_517 ] ;
V_8 -> V_521 [ V_517 ] = V_137 ;
}
}
}
}
static void F_269 ( unsigned int V_81 , T_2 * V_514 )
{
T_2 V_19 ;
switch ( V_81 ) {
case 3 :
case 4 :
V_19 = V_514 [ 1 ] ;
V_514 [ 1 ] = V_514 [ 2 ] ;
V_514 [ 2 ] = V_19 ;
break;
}
}
int F_270 ( struct V_6 * V_7 ,
struct V_518 * V_8 ,
const T_2 * V_523 ,
unsigned int V_524 )
{
T_2 V_19 , V_525 ;
short V_41 , V_526 ;
short V_527 [ F_9 ( V_8 -> V_528 ) ] ;
short V_529 [ F_9 ( V_8 -> V_530 ) ] ;
short V_531 [ F_9 ( V_8 -> V_532 ) ] ;
int V_12 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
memset ( V_527 , 0 , sizeof( V_527 ) ) ;
memset ( V_529 , 0 , sizeof( V_529 ) ) ;
memset ( V_531 , 0 , sizeof( V_531 ) ) ;
V_526 = 0 ;
V_7 -> V_533 = true ;
V_525 = V_7 -> V_154 + V_7 -> V_153 ;
for ( V_19 = V_7 -> V_154 ; V_19 < V_525 ; V_19 ++ ) {
unsigned int V_534 = F_34 ( V_7 , V_19 ) ;
unsigned int V_158 = F_35 ( V_534 ) ;
unsigned int V_535 ;
short V_536 , V_537 , V_79 , V_457 ;
if ( V_158 != V_82 )
continue;
if ( V_523 && F_265 ( V_19 , V_523 ) )
continue;
V_535 = F_77 ( V_7 , V_19 ) ;
if ( ! ( F_271 ( F_77 ( V_7 , V_19 ) ) &
V_538 ) )
V_7 -> V_533 = false ;
V_79 = F_272 ( V_535 ) ;
if ( V_79 == V_539 )
continue;
V_537 = F_273 ( V_535 ) ;
V_457 = F_274 ( V_535 ) ;
if ( V_457 == V_540 ) {
if ( V_79 == V_541 )
V_457 = V_542 ;
}
switch ( V_457 ) {
case V_540 :
V_41 = F_275 ( V_535 ) ;
V_536 = F_276 ( V_535 ) ;
if ( ! ( V_534 & V_543 ) )
if ( ! V_8 -> V_544 )
V_8 -> V_544 = V_19 ;
if ( ! V_536 )
continue;
if ( ! V_526 )
V_526 = V_536 ;
else if ( V_526 != V_536 )
continue;
if ( V_8 -> V_545 >= F_9 ( V_8 -> V_528 ) )
continue;
V_8 -> V_528 [ V_8 -> V_545 ] = V_19 ;
V_527 [ V_8 -> V_545 ] = V_41 ;
V_8 -> V_545 ++ ;
break;
case V_542 :
V_41 = F_275 ( V_535 ) ;
V_536 = F_276 ( V_535 ) ;
if ( V_8 -> V_546 >= F_9 ( V_8 -> V_530 ) )
continue;
V_8 -> V_530 [ V_8 -> V_546 ] = V_19 ;
V_529 [ V_8 -> V_546 ] = ( V_536 << 4 ) | V_41 ;
V_8 -> V_546 ++ ;
break;
case V_547 :
V_41 = F_275 ( V_535 ) ;
V_536 = F_276 ( V_535 ) ;
if ( V_8 -> V_548 >= F_9 ( V_8 -> V_532 ) )
continue;
V_8 -> V_532 [ V_8 -> V_548 ] = V_19 ;
V_531 [ V_8 -> V_548 ] = ( V_536 << 4 ) | V_41 ;
V_8 -> V_548 ++ ;
break;
case V_549 :
F_267 ( V_8 , V_19 , V_550 ) ;
break;
case V_551 :
F_267 ( V_8 , V_19 , V_552 ) ;
break;
case V_553 :
F_267 ( V_8 , V_19 , V_554 ) ;
break;
case V_555 :
F_267 ( V_8 , V_19 , V_556 ) ;
break;
case V_557 :
case V_558 :
if ( V_8 -> V_559 >= F_9 ( V_8 -> V_560 ) )
continue;
V_8 -> V_560 [ V_8 -> V_559 ] = V_19 ;
V_8 -> V_561 [ V_8 -> V_559 ] =
( V_537 == V_562 ) ?
V_450 : V_449 ;
V_8 -> V_559 ++ ;
break;
case V_563 :
case V_564 :
V_8 -> V_565 = V_19 ;
if ( V_537 == V_562 )
V_8 -> V_566 = V_450 ;
else
V_8 -> V_566 = V_449 ;
break;
}
}
if ( ! V_8 -> V_545 && V_8 -> V_548 > 1 &&
! ( V_524 & V_567 ) ) {
int V_12 = 0 ;
while ( V_12 < V_8 -> V_548 ) {
if ( ( V_531 [ V_12 ] & 0x0f ) == 0x0f ) {
V_12 ++ ;
continue;
}
V_8 -> V_528 [ V_8 -> V_545 ] = V_8 -> V_532 [ V_12 ] ;
V_527 [ V_8 -> V_545 ] = V_531 [ V_12 ] ;
V_8 -> V_545 ++ ;
V_8 -> V_548 -- ;
memmove ( V_8 -> V_532 + V_12 , V_8 -> V_532 + V_12 + 1 ,
sizeof( V_8 -> V_532 [ 0 ] ) * ( V_8 -> V_548 - V_12 ) ) ;
memmove ( V_531 + V_12 , V_531 + V_12 + 1 ,
sizeof( V_531 [ 0 ] ) * ( V_8 -> V_548 - V_12 ) ) ;
}
memset ( V_8 -> V_532 + V_8 -> V_548 , 0 ,
sizeof( T_2 ) * ( V_568 - V_8 -> V_548 ) ) ;
if ( ! V_8 -> V_548 )
V_8 -> V_569 = V_570 ;
}
F_266 ( V_8 -> V_528 , V_527 ,
V_8 -> V_545 ) ;
F_266 ( V_8 -> V_530 , V_529 ,
V_8 -> V_546 ) ;
F_266 ( V_8 -> V_532 , V_531 ,
V_8 -> V_548 ) ;
if ( ! V_8 -> V_545 &&
! ( V_524 & V_571 ) ) {
if ( V_8 -> V_546 ) {
V_8 -> V_545 = V_8 -> V_546 ;
memcpy ( V_8 -> V_528 , V_8 -> V_530 ,
sizeof( V_8 -> V_530 ) ) ;
V_8 -> V_546 = 0 ;
memset ( V_8 -> V_530 , 0 , sizeof( V_8 -> V_530 ) ) ;
V_8 -> V_569 = V_572 ;
} else if ( V_8 -> V_548 ) {
V_8 -> V_545 = V_8 -> V_548 ;
memcpy ( V_8 -> V_528 , V_8 -> V_532 ,
sizeof( V_8 -> V_532 ) ) ;
V_8 -> V_548 = 0 ;
memset ( V_8 -> V_532 , 0 , sizeof( V_8 -> V_532 ) ) ;
V_8 -> V_569 = V_570 ;
}
}
F_269 ( V_8 -> V_545 , V_8 -> V_528 ) ;
F_269 ( V_8 -> V_548 , V_8 -> V_532 ) ;
F_269 ( V_8 -> V_546 , V_8 -> V_530 ) ;
F_268 ( V_8 ) ;
F_19 ( L_93 ,
V_8 -> V_545 , V_8 -> V_528 [ 0 ] , V_8 -> V_528 [ 1 ] ,
V_8 -> V_528 [ 2 ] , V_8 -> V_528 [ 3 ] ,
V_8 -> V_528 [ 4 ] ,
V_8 -> V_569 == V_570 ? L_94 :
( V_8 -> V_569 == V_572 ?
L_95 : L_96 ) ) ;
F_19 ( L_97 ,
V_8 -> V_546 , V_8 -> V_530 [ 0 ] ,
V_8 -> V_530 [ 1 ] , V_8 -> V_530 [ 2 ] ,
V_8 -> V_530 [ 3 ] , V_8 -> V_530 [ 4 ] ) ;
F_19 ( L_98 ,
V_8 -> V_548 , V_8 -> V_532 [ 0 ] ,
V_8 -> V_532 [ 1 ] , V_8 -> V_532 [ 2 ] ,
V_8 -> V_532 [ 3 ] , V_8 -> V_532 [ 4 ] ) ;
F_19 ( L_99 , V_8 -> V_544 ) ;
if ( V_8 -> V_559 )
F_19 ( L_100 ,
V_8 -> V_560 [ 0 ] , V_8 -> V_560 [ 1 ] ) ;
F_19 ( L_101 ) ;
for ( V_12 = 0 ; V_12 < V_8 -> V_519 ; V_12 ++ ) {
F_19 ( L_102 ,
F_277 ( V_7 , V_8 , V_12 ) ,
V_8 -> V_521 [ V_12 ] . V_157 ) ;
}
F_19 ( L_103 ) ;
if ( V_8 -> V_565 )
F_19 ( L_104 , V_8 -> V_565 ) ;
return 0 ;
}
int F_278 ( unsigned int V_535 )
{
unsigned int V_537 = F_273 ( V_535 ) ;
unsigned int V_79 = F_272 ( V_535 ) ;
if ( V_79 == V_539 )
return V_573 ;
if ( V_79 == V_541 || V_79 == V_574 )
return V_575 ;
if ( ( V_537 & 0x30 ) == V_576 )
return V_575 ;
if ( ( V_537 & 0x30 ) == V_577 )
return V_578 ;
if ( V_537 == V_579 )
return V_580 ;
if ( V_537 == V_581 )
return V_582 ;
return V_583 ;
}
const char * F_279 ( struct V_6 * V_7 , T_2 V_157 ,
int V_584 )
{
unsigned int V_535 ;
static const char * const V_585 [] = {
L_105 , L_106 , L_30 , L_107 , L_108 ,
} ;
int V_586 ;
V_535 = F_77 ( V_7 , V_157 ) ;
switch ( F_274 ( V_535 ) ) {
case V_549 :
if ( ! V_584 )
return L_30 ;
V_586 = F_278 ( V_535 ) ;
if ( ! V_586 )
return L_109 ;
return V_585 [ V_586 - 1 ] ;
case V_551 :
if ( ! V_584 )
return L_110 ;
V_586 = F_278 ( V_535 ) ;
if ( ! V_586 )
return L_109 ;
if ( V_586 == V_578 )
return L_111 ;
return L_110 ;
case V_555 :
return L_29 ;
case V_553 :
return L_23 ;
case V_563 :
return L_32 ;
case V_564 :
return L_112 ;
default:
return L_113 ;
}
}
static int F_280 ( struct V_6 * V_7 ,
const struct V_518 * V_8 ,
int V_587 )
{
unsigned int V_588 ;
int V_12 , V_586 , V_589 ;
V_588 = F_77 ( V_7 , V_8 -> V_521 [ V_587 ] . V_157 ) ;
V_586 = F_278 ( V_588 ) ;
if ( V_586 <= V_583 )
return 1 ;
V_586 = 0 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_519 ; V_12 ++ ) {
V_588 = F_77 ( V_7 , V_8 -> V_521 [ V_12 ] . V_157 ) ;
V_589 = F_278 ( V_588 ) ;
if ( V_589 >= V_583 ) {
if ( V_586 && V_586 != V_589 )
return 1 ;
V_586 = V_589 ;
}
}
return 0 ;
}
const char * F_277 ( struct V_6 * V_7 ,
const struct V_518 * V_8 ,
int V_587 )
{
int type = V_8 -> V_521 [ V_587 ] . type ;
int V_590 = 0 ;
if ( ( V_587 > 0 && V_8 -> V_521 [ V_587 - 1 ] . type == type ) ||
( V_587 < V_8 -> V_519 - 1 && V_8 -> V_521 [ V_587 + 1 ] . type == type ) )
V_590 = 1 ;
if ( V_590 && type == V_550 )
V_590 &= F_280 ( V_7 , V_8 , V_587 ) ;
return F_279 ( V_7 , V_8 -> V_521 [ V_587 ] . V_157 ,
V_590 ) ;
}
int F_281 ( struct V_486 * V_487 , const char * V_489 ,
int V_243 , int * V_591 )
{
int V_12 , V_592 = 0 ;
if ( V_487 -> V_488 >= V_80 ) {
F_19 ( V_25 L_114 ) ;
return - V_54 ;
}
for ( V_12 = 0 ; V_12 < V_487 -> V_488 ; V_12 ++ ) {
if ( ! strncmp ( V_489 , V_487 -> V_303 [ V_12 ] . V_489 , strlen ( V_489 ) ) )
V_592 ++ ;
}
if ( V_591 )
* V_591 = V_592 ;
if ( V_592 > 0 )
snprintf ( V_487 -> V_303 [ V_487 -> V_488 ] . V_489 ,
sizeof( V_487 -> V_303 [ V_487 -> V_488 ] . V_489 ) ,
L_115 , V_489 , V_592 ) ;
else
F_282 ( V_487 -> V_303 [ V_487 -> V_488 ] . V_489 , V_489 ,
sizeof( V_487 -> V_303 [ V_487 -> V_488 ] . V_489 ) ) ;
V_487 -> V_303 [ V_487 -> V_488 ] . V_243 = V_243 ;
V_487 -> V_488 ++ ;
return 0 ;
}
int F_283 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
if ( F_256 ( V_7 ) )
F_212 ( V_7 ) ;
if ( V_7 -> V_96 . V_593 )
V_7 -> V_96 . V_593 ( V_7 ) ;
}
return 0 ;
}
int F_284 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
if ( V_7 -> V_96 . V_594 )
V_7 -> V_96 . V_594 ( V_7 ) ;
if ( F_285 ( V_7 ) )
F_214 ( V_7 ) ;
}
return 0 ;
}
void * F_37 ( struct V_45 * V_46 )
{
if ( V_46 -> V_48 >= V_46 -> V_595 ) {
int V_596 = V_46 -> V_595 + V_46 -> V_597 ;
int V_278 = ( V_596 + 1 ) * V_46 -> V_598 ;
int V_599 = V_46 -> V_595 * V_46 -> V_598 ;
void * V_600 ;
if ( F_29 ( V_596 >= 4096 ) )
return NULL ;
V_600 = F_286 ( V_46 -> V_4 , V_278 , V_98 ) ;
if ( ! V_600 )
return NULL ;
memset ( V_600 + V_599 , 0 , V_278 - V_599 ) ;
V_46 -> V_4 = V_600 ;
V_46 -> V_595 = V_596 ;
}
return F_27 ( V_46 , V_46 -> V_48 ++ ) ;
}
void F_84 ( struct V_45 * V_46 )
{
F_49 ( V_46 -> V_4 ) ;
V_46 -> V_48 = 0 ;
V_46 -> V_595 = 0 ;
V_46 -> V_4 = NULL ;
}
void F_287 ( int V_305 , char * V_218 , int V_601 )
{
static unsigned int V_602 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_12 , V_517 ;
for ( V_12 = 0 , V_517 = 0 ; V_12 < F_9 ( V_602 ) ; V_12 ++ )
if ( V_305 & ( V_424 << V_12 ) )
V_517 += snprintf ( V_218 + V_517 , V_601 - V_517 , L_116 , V_602 [ V_12 ] ) ;
V_218 [ V_517 ] = '\0' ;
}
static const char * F_288 ( struct V_6 * V_7 , T_2 V_19 ,
int type )
{
switch ( type ) {
case V_603 :
return L_117 ;
case V_604 :
return L_30 ;
case V_605 :
return L_118 ;
case V_606 :
return L_119 ;
case V_607 :
return L_120 ;
case V_608 :
return L_121 ;
default:
return L_113 ;
}
}
static void F_289 ( struct V_609 * V_610 )
{
struct V_611 * V_612 = V_610 -> V_113 ;
V_612 -> V_19 = 0 ;
V_612 -> V_610 = NULL ;
}
int F_290 ( struct V_6 * V_7 , T_2 V_19 , int type ,
const char * V_133 )
{
struct V_611 * V_610 ;
int V_30 ;
F_91 ( & V_7 -> V_612 , sizeof( * V_610 ) , 32 ) ;
V_610 = F_37 ( & V_7 -> V_612 ) ;
if ( ! V_610 )
return - V_76 ;
V_610 -> V_19 = V_19 ;
V_610 -> type = type ;
if ( ! V_133 )
V_133 = F_288 ( V_7 , V_19 , type ) ;
V_30 = F_291 ( V_7 -> V_29 -> V_105 , V_133 , type , & V_610 -> V_610 ) ;
if ( V_30 < 0 ) {
V_610 -> V_19 = 0 ;
return V_30 ;
}
V_610 -> V_610 -> V_113 = V_610 ;
V_610 -> V_610 -> V_99 = F_289 ;
return 0 ;
}
void F_292 ( struct V_6 * V_7 , T_2 V_19 )
{
struct V_611 * V_612 = V_7 -> V_612 . V_4 ;
int V_12 ;
if ( ! V_612 )
return;
for ( V_12 = 0 ; V_12 < V_7 -> V_612 . V_48 ; V_12 ++ , V_612 ++ ) {
unsigned int V_613 ;
unsigned int V_614 ;
int type ;
if ( V_612 -> V_19 != V_19 )
continue;
V_614 = F_119 ( V_7 , V_19 ) ;
type = V_612 -> type ;
if ( type == ( V_603 | V_605 ) ) {
V_613 = F_21 ( V_7 , V_19 , 0 ,
V_162 , 0 ) ;
type = ( V_613 & V_615 ) ?
V_603 : V_605 ;
}
F_293 ( V_612 -> V_610 , V_614 ? type : 0 ) ;
}
}
void F_294 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_29 -> V_103 && V_7 -> V_612 . V_4 ) {
struct V_611 * V_612 = V_7 -> V_612 . V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_612 . V_48 ; V_12 ++ , V_612 ++ ) {
if ( V_612 -> V_610 )
F_159 ( V_7 -> V_29 -> V_105 , V_612 -> V_610 ) ;
}
}
F_84 ( & V_7 -> V_612 ) ;
}
