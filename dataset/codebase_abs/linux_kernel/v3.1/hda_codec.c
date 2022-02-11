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
V_30 = V_29 -> V_33 . V_34 ( V_29 , V_26 ) ;
if ( ! V_30 && V_27 )
* V_27 = V_29 -> V_33 . V_35 ( V_29 , V_7 -> V_24 ) ;
F_4 ( & V_29 -> V_32 ) ;
F_16 ( V_7 ) ;
if ( V_27 && * V_27 == - 1 && V_29 -> V_36 ) {
if ( V_29 -> V_37 ) {
F_17 ( L_37
L_38 ) ;
V_29 -> V_33 . V_38 ( V_29 ) ;
}
goto V_31;
}
if ( ! V_30 )
V_29 -> V_37 = 0 ;
return V_30 ;
}
unsigned int F_18 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 ,
unsigned int V_21 , unsigned int V_22 )
{
unsigned V_26 = F_12 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
unsigned int V_27 ;
if ( F_14 ( V_7 , V_26 , & V_27 ) )
return - 1 ;
return V_27 ;
}
int F_19 ( struct V_6 * V_7 , T_2 V_19 , int V_20 ,
unsigned int V_21 , unsigned int V_22 )
{
unsigned int V_26 = F_12 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
unsigned int V_27 ;
return F_14 ( V_7 , V_26 ,
V_7 -> V_29 -> V_39 ? & V_27 : NULL ) ;
}
void F_20 ( struct V_6 * V_7 , const struct V_40 * V_41 )
{
for (; V_41 -> V_19 ; V_41 ++ )
F_19 ( V_7 , V_41 -> V_19 , 0 , V_41 -> V_21 , V_41 -> V_42 ) ;
}
int F_21 ( struct V_6 * V_7 , T_2 V_19 ,
T_2 * V_43 )
{
unsigned int V_22 ;
V_22 = F_22 ( V_7 , V_19 , V_44 ) ;
if ( V_22 == - 1 )
return 0 ;
* V_43 = ( V_22 >> 16 ) & 0x7fff ;
return ( int ) ( V_22 & 0x7fff ) ;
}
static T_2 * F_23 ( struct V_45 * V_46 , T_2 V_19 )
{
int V_12 , V_47 ;
for ( V_12 = 0 ; V_12 < V_46 -> V_48 ; ) {
T_2 * V_49 = F_24 ( V_46 , V_12 ) ;
if ( V_19 == * V_49 )
return V_49 ;
V_47 = V_49 [ 1 ] ;
V_12 += V_47 + 2 ;
}
return NULL ;
}
int F_25 ( struct V_6 * V_7 , T_2 V_19 ,
const T_2 * * V_50 )
{
struct V_45 * V_46 = & V_7 -> V_51 ;
int V_47 , V_30 ;
T_2 V_4 [ V_52 ] ;
T_2 * V_49 ;
bool V_53 = false ;
V_31:
V_49 = F_23 ( V_46 , V_19 ) ;
if ( V_49 ) {
if ( V_50 )
* V_50 = V_49 + 2 ;
return V_49 [ 1 ] ;
}
if ( F_26 ( V_53 ) )
return - V_54 ;
V_47 = F_27 ( V_7 , V_19 , V_4 , V_52 ) ;
if ( V_47 < 0 )
return V_47 ;
V_30 = F_28 ( V_7 , V_19 , V_47 , V_4 ) ;
if ( V_30 < 0 )
return V_30 ;
V_53 = true ;
goto V_31;
}
int F_29 ( struct V_6 * V_7 , T_2 V_19 ,
T_2 * V_55 , int V_56 )
{
const T_2 * V_4 ;
int V_47 = F_25 ( V_7 , V_19 , & V_4 ) ;
if ( V_47 <= 0 )
return V_47 ;
if ( V_47 > V_56 ) {
F_30 ( V_25 L_39
L_40 ,
V_47 , V_19 ) ;
return - V_54 ;
}
memcpy ( V_55 , V_4 , V_47 * sizeof( T_2 ) ) ;
return V_47 ;
}
int F_27 ( struct V_6 * V_7 , T_2 V_19 ,
T_2 * V_55 , int V_56 )
{
unsigned int V_22 ;
int V_12 , V_57 , V_58 ;
unsigned int V_59 , V_60 , V_61 ;
unsigned int V_62 ;
T_2 V_63 ;
if ( F_26 ( ! V_55 || V_56 <= 0 ) )
return - V_54 ;
V_62 = F_31 ( V_7 , V_19 ) ;
if ( ! ( V_62 & V_64 ) &&
F_32 ( V_62 ) != V_65 )
return 0 ;
V_22 = F_22 ( V_7 , V_19 , V_66 ) ;
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
V_22 = F_18 ( V_7 , V_19 , 0 ,
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
V_22 = F_18 ( V_7 , V_19 , 0 ,
V_69 , V_12 ) ;
if ( V_22 == - 1 && V_7 -> V_29 -> V_36 )
return - V_70 ;
}
V_71 = ! ! ( V_22 & ( 1 << ( V_59 - 1 ) ) ) ;
V_23 = V_22 & V_61 ;
if ( V_23 == 0 ) {
F_30 ( V_73 L_39
L_41 ,
V_19 , V_12 , V_22 ) ;
return 0 ;
}
V_22 >>= V_59 ;
if ( V_71 ) {
if ( ! V_63 || V_63 >= V_23 ) {
F_30 ( V_73 L_39
L_42 ,
V_63 , V_23 ) ;
continue;
}
for ( V_72 = V_63 + 1 ; V_72 <= V_23 ; V_72 ++ ) {
if ( V_58 >= V_56 ) {
F_30 ( V_25 L_39
L_40 ,
V_58 , V_19 ) ;
return - V_54 ;
}
V_55 [ V_58 ++ ] = V_72 ;
}
} else {
if ( V_58 >= V_56 ) {
F_30 ( V_25 L_39
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
static bool F_33 ( struct V_45 * V_46 , T_2 V_19 )
{
T_2 * V_49 = F_34 ( V_46 ) ;
if ( ! V_49 )
return false ;
* V_49 = V_19 ;
return true ;
}
int F_28 ( struct V_6 * V_7 , T_2 V_19 , int V_47 ,
const T_2 * V_4 )
{
struct V_45 * V_46 = & V_7 -> V_51 ;
T_2 * V_49 ;
int V_12 , V_74 ;
V_49 = F_23 ( V_46 , V_19 ) ;
if ( V_49 )
* V_49 = - 1 ;
V_74 = V_46 -> V_48 ;
if ( ! F_33 ( V_46 , V_19 ) || ! F_33 ( V_46 , V_47 ) )
goto V_75;
for ( V_12 = 0 ; V_12 < V_47 ; V_12 ++ )
if ( ! F_33 ( V_46 , V_4 [ V_12 ] ) )
goto V_75;
return 0 ;
V_75:
V_46 -> V_48 = V_74 ;
return - V_76 ;
}
int F_35 ( struct V_6 * V_7 , T_2 V_77 ,
T_2 V_19 , int V_78 )
{
T_2 V_79 [ V_80 ] ;
int V_12 , V_81 ;
V_81 = F_29 ( V_7 , V_77 , V_79 , F_9 ( V_79 ) ) ;
for ( V_12 = 0 ; V_12 < V_81 ; V_12 ++ )
if ( V_79 [ V_12 ] == V_19 )
return V_12 ;
if ( ! V_78 )
return - 1 ;
if ( V_78 > 5 ) {
F_17 ( L_43 , V_19 ) ;
return - 1 ;
}
V_78 ++ ;
for ( V_12 = 0 ; V_12 < V_81 ; V_12 ++ ) {
unsigned int type = F_32 ( F_31 ( V_7 , V_79 [ V_12 ] ) ) ;
if ( type == V_82 || type == V_83 )
continue;
if ( F_35 ( V_7 , V_79 [ V_12 ] , V_19 , V_78 ) >= 0 )
return V_12 ;
}
return - 1 ;
}
int F_36 ( struct V_28 * V_29 , T_1 V_27 , T_1 V_84 )
{
struct V_85 * V_86 ;
unsigned int V_87 ;
V_86 = V_29 -> V_86 ;
if ( ! V_86 )
return 0 ;
V_87 = ( V_86 -> V_87 + 1 ) % V_88 ;
V_86 -> V_87 = V_87 ;
V_87 <<= 1 ;
V_86 -> V_89 [ V_87 ] = V_27 ;
V_86 -> V_89 [ V_87 + 1 ] = V_84 ;
F_37 ( V_29 -> V_90 , & V_86 -> V_91 ) ;
return 0 ;
}
static void F_38 ( struct V_92 * V_91 )
{
struct V_85 * V_86 =
F_39 ( V_91 , struct V_85 , V_91 ) ;
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
static int F_40 ( struct V_28 * V_29 )
{
struct V_85 * V_86 ;
if ( V_29 -> V_86 )
return 0 ;
V_86 = F_41 ( sizeof( * V_86 ) , V_98 ) ;
if ( ! V_86 ) {
F_30 ( V_25 L_39
L_44 ) ;
return - V_76 ;
}
F_42 ( & V_86 -> V_91 , F_38 ) ;
V_86 -> V_29 = V_29 ;
V_29 -> V_86 = V_86 ;
return 0 ;
}
static int F_43 ( struct V_28 * V_29 )
{
struct V_6 * V_7 , * V_72 ;
if ( ! V_29 )
return 0 ;
if ( V_29 -> V_90 )
F_44 ( V_29 -> V_90 ) ;
if ( V_29 -> V_86 )
F_45 ( V_29 -> V_86 ) ;
F_46 (codec, n, &bus->codec_list, list) {
F_47 ( V_7 ) ;
}
if ( V_29 -> V_33 . V_99 )
V_29 -> V_33 . V_99 ( V_29 ) ;
if ( V_29 -> V_90 )
F_48 ( V_29 -> V_90 ) ;
F_45 ( V_29 ) ;
return 0 ;
}
static int F_49 ( struct V_100 * V_101 )
{
struct V_28 * V_29 = V_101 -> V_102 ;
V_29 -> V_103 = 1 ;
return F_43 ( V_29 ) ;
}
static int F_50 ( struct V_100 * V_101 )
{
struct V_28 * V_29 = V_101 -> V_102 ;
struct V_6 * V_7 ;
F_51 (codec, &bus->codec_list, list) {
F_52 ( V_7 ) ;
F_53 ( V_7 ) ;
}
return 0 ;
}
int F_54 ( struct V_104 * V_105 ,
const struct V_106 * V_107 ,
struct V_28 * * V_108 )
{
struct V_28 * V_29 ;
int V_30 ;
static struct V_109 V_110 = {
. V_111 = F_50 ,
. V_112 = F_49 ,
} ;
if ( F_26 ( ! V_107 ) )
return - V_54 ;
if ( F_26 ( ! V_107 -> V_33 . V_34 || ! V_107 -> V_33 . V_35 ) )
return - V_54 ;
if ( V_108 )
* V_108 = NULL ;
V_29 = F_41 ( sizeof( * V_29 ) , V_98 ) ;
if ( V_29 == NULL ) {
F_30 ( V_25 L_45 ) ;
return - V_76 ;
}
V_29 -> V_105 = V_105 ;
V_29 -> V_113 = V_107 -> V_113 ;
V_29 -> V_114 = V_107 -> V_114 ;
V_29 -> V_115 = V_107 -> V_115 ;
V_29 -> V_116 = V_107 -> V_116 ;
V_29 -> V_33 = V_107 -> V_33 ;
F_55 ( & V_29 -> V_32 ) ;
F_55 ( & V_29 -> V_117 ) ;
F_56 ( & V_29 -> V_118 ) ;
snprintf ( V_29 -> V_119 , sizeof( V_29 -> V_119 ) ,
L_46 , V_105 -> V_120 ) ;
V_29 -> V_90 = F_57 ( V_29 -> V_119 ) ;
if ( ! V_29 -> V_90 ) {
F_30 ( V_25 L_47 ,
V_29 -> V_119 ) ;
F_45 ( V_29 ) ;
return - V_76 ;
}
V_30 = F_58 ( V_105 , V_121 , V_29 , & V_110 ) ;
if ( V_30 < 0 ) {
F_43 ( V_29 ) ;
return V_30 ;
}
if ( V_108 )
* V_108 = V_29 ;
return 0 ;
}
static const struct V_122 *
F_59 ( struct V_6 * V_7 )
{
struct V_1 * V_123 ;
const struct V_122 * V_2 ;
int V_124 = 0 ;
if ( F_60 ( V_7 ) )
return NULL ;
V_31:
F_2 ( & V_3 ) ;
F_51 (tbl, &hda_preset_tables, list) {
if ( ! F_61 ( V_123 -> V_125 ) ) {
F_30 ( V_25 L_48 ) ;
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
F_62 ( V_123 -> V_125 ) ;
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
F_63 ( V_133 ) ;
V_124 ++ ;
goto V_31;
}
return NULL ;
}
static int F_64 ( struct V_6 * V_7 )
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
V_7 -> V_138 = F_65 ( V_136 , V_98 ) ;
if ( ! V_7 -> V_138 )
return - V_76 ;
V_139:
if ( V_7 -> V_141 )
return 0 ;
if ( V_7 -> V_2 && V_7 -> V_2 -> V_133 )
V_7 -> V_141 = F_65 ( V_7 -> V_2 -> V_133 , V_98 ) ;
else {
sprintf ( V_137 , L_52 , V_7 -> V_129 & 0xffff ) ;
V_7 -> V_141 = F_65 ( V_137 , V_98 ) ;
}
if ( ! V_7 -> V_141 )
return - V_76 ;
return 0 ;
}
static void F_66 ( struct V_6 * V_7 )
{
int V_12 , V_142 , V_143 ;
T_2 V_19 ;
V_142 = F_21 ( V_7 , V_144 , & V_19 ) ;
for ( V_12 = 0 ; V_12 < V_142 ; V_12 ++ , V_19 ++ ) {
V_143 = F_22 ( V_7 , V_19 ,
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
static int F_67 ( struct V_6 * V_7 , T_2 V_152 )
{
int V_12 ;
T_2 V_19 ;
V_7 -> V_153 = F_21 ( V_7 , V_152 ,
& V_7 -> V_154 ) ;
V_7 -> V_62 = F_68 ( V_7 -> V_153 * 4 , V_98 ) ;
if ( ! V_7 -> V_62 )
return - V_76 ;
V_19 = V_7 -> V_154 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_153 ; V_12 ++ , V_19 ++ )
V_7 -> V_62 [ V_12 ] = F_22 ( V_7 , V_19 ,
V_155 ) ;
return 0 ;
}
static int F_69 ( struct V_6 * V_7 )
{
int V_12 ;
T_2 V_19 = V_7 -> V_154 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_153 ; V_12 ++ , V_19 ++ ) {
struct V_156 * V_157 ;
unsigned int V_62 = F_31 ( V_7 , V_19 ) ;
unsigned int V_158 = F_32 ( V_62 ) ;
if ( V_158 != V_82 )
continue;
V_157 = F_34 ( & V_7 -> V_159 ) ;
if ( ! V_157 )
return - V_76 ;
V_157 -> V_19 = V_19 ;
V_157 -> V_8 = F_18 ( V_7 , V_19 , 0 ,
V_160 , 0 ) ;
V_157 -> V_161 = F_18 ( V_7 , V_19 , 0 ,
V_162 ,
0 ) ;
}
return 0 ;
}
static struct V_156 * F_70 ( struct V_6 * V_7 ,
struct V_45 * V_46 ,
T_2 V_19 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_46 -> V_48 ; V_12 ++ ) {
struct V_156 * V_157 = F_24 ( V_46 , V_12 ) ;
if ( V_157 -> V_19 == V_19 )
return V_157 ;
}
return NULL ;
}
static void F_71 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_8 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ ) {
F_19 ( V_7 , V_19 , 0 ,
V_163 + V_12 ,
V_8 & 0xff ) ;
V_8 >>= 8 ;
}
}
int F_72 ( struct V_6 * V_7 , struct V_45 * V_4 ,
T_2 V_19 , unsigned int V_8 )
{
struct V_156 * V_157 ;
unsigned int V_164 ;
if ( F_32 ( F_31 ( V_7 , V_19 ) ) != V_82 )
return - V_54 ;
V_164 = F_73 ( V_7 , V_19 ) ;
V_157 = F_70 ( V_7 , V_4 , V_19 ) ;
if ( ! V_157 ) {
V_157 = F_34 ( V_4 ) ;
if ( ! V_157 )
return - V_76 ;
V_157 -> V_19 = V_19 ;
}
V_157 -> V_8 = V_8 ;
V_8 = F_73 ( V_7 , V_19 ) ;
if ( V_164 != V_8 )
F_71 ( V_7 , V_19 , V_8 ) ;
return 0 ;
}
int F_74 ( struct V_6 * V_7 ,
T_2 V_19 , unsigned int V_8 )
{
return F_72 ( V_7 , & V_7 -> V_165 , V_19 , V_8 ) ;
}
unsigned int F_73 ( struct V_6 * V_7 , T_2 V_19 )
{
struct V_156 * V_157 ;
#ifdef F_75
V_157 = F_70 ( V_7 , & V_7 -> V_166 , V_19 ) ;
if ( V_157 )
return V_157 -> V_8 ;
#endif
V_157 = F_70 ( V_7 , & V_7 -> V_165 , V_19 ) ;
if ( V_157 )
return V_157 -> V_8 ;
V_157 = F_70 ( V_7 , & V_7 -> V_159 , V_19 ) ;
if ( V_157 )
return V_157 -> V_8 ;
return 0 ;
}
static void F_76 ( struct V_6 * V_7 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_159 . V_48 ; V_12 ++ ) {
struct V_156 * V_157 = F_24 ( & V_7 -> V_159 , V_12 ) ;
F_71 ( V_7 , V_157 -> V_19 ,
F_73 ( V_7 , V_157 -> V_19 ) ) ;
}
}
void F_77 ( struct V_6 * V_7 )
{
int V_12 ;
if ( V_7 -> V_29 -> V_103 )
return;
for ( V_12 = 0 ; V_12 < V_7 -> V_159 . V_48 ; V_12 ++ ) {
struct V_156 * V_157 = F_24 ( & V_7 -> V_159 , V_12 ) ;
F_18 ( V_7 , V_157 -> V_19 , 0 ,
V_167 , 0 ) ;
}
V_7 -> V_168 = 1 ;
}
static void F_78 ( struct V_6 * V_7 )
{
int V_12 ;
if ( ! V_7 -> V_168 )
return;
if ( V_7 -> V_29 -> V_103 )
return;
for ( V_12 = 0 ; V_12 < V_7 -> V_159 . V_48 ; V_12 ++ ) {
struct V_156 * V_157 = F_24 ( & V_7 -> V_159 , V_12 ) ;
F_19 ( V_7 , V_157 -> V_19 , 0 ,
V_167 ,
V_157 -> V_161 ) ;
}
V_7 -> V_168 = 0 ;
}
static void F_79 ( struct V_6 * V_7 )
{
F_80 ( & V_7 -> V_165 ) ;
#ifdef F_75
F_80 ( & V_7 -> V_166 ) ;
#endif
F_76 ( V_7 ) ;
F_80 ( & V_7 -> V_159 ) ;
}
static struct V_169 *
F_81 ( struct V_6 * V_7 , T_2 V_19 )
{
struct V_169 * V_49 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_170 . V_48 ; V_12 ++ ) {
V_49 = F_24 ( & V_7 -> V_170 , V_12 ) ;
if ( V_49 -> V_19 == V_19 )
return V_49 ;
}
V_49 = F_34 ( & V_7 -> V_170 ) ;
if ( V_49 )
V_49 -> V_19 = V_19 ;
return V_49 ;
}
static void F_47 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_79 ( V_7 ) ;
#ifdef F_82
F_83 ( & V_7 -> V_171 ) ;
F_44 ( V_7 -> V_29 -> V_90 ) ;
#endif
F_6 ( & V_7 -> V_4 ) ;
F_80 ( & V_7 -> V_172 ) ;
F_80 ( & V_7 -> V_173 ) ;
F_80 ( & V_7 -> V_51 ) ;
F_80 ( & V_7 -> V_174 ) ;
V_7 -> V_29 -> V_95 [ V_7 -> V_24 ] = NULL ;
if ( V_7 -> V_96 . free )
V_7 -> V_96 . free ( V_7 ) ;
F_62 ( V_7 -> V_125 ) ;
F_84 ( & V_7 -> V_175 ) ;
F_84 ( & V_7 -> V_176 ) ;
F_45 ( V_7 -> V_138 ) ;
F_45 ( V_7 -> V_141 ) ;
F_45 ( V_7 -> V_115 ) ;
F_45 ( V_7 -> V_62 ) ;
F_45 ( V_7 ) ;
}
int F_85 ( struct V_28 * V_29 ,
unsigned int V_177 ,
struct V_6 * * V_178 )
{
struct V_6 * V_7 ;
char V_179 [ 31 ] ;
int V_30 ;
if ( F_26 ( ! V_29 ) )
return - V_54 ;
if ( F_26 ( V_177 > V_180 ) )
return - V_54 ;
if ( V_29 -> V_95 [ V_177 ] ) {
F_30 ( V_25 L_39
L_53 , V_177 ) ;
return - V_181 ;
}
V_7 = F_41 ( sizeof( * V_7 ) , V_98 ) ;
if ( V_7 == NULL ) {
F_30 ( V_25 L_54 ) ;
return - V_76 ;
}
V_7 -> V_29 = V_29 ;
V_7 -> V_24 = V_177 ;
F_55 ( & V_7 -> V_182 ) ;
F_55 ( & V_7 -> V_183 ) ;
F_86 ( & V_7 -> V_175 , sizeof( struct V_184 ) ) ;
F_86 ( & V_7 -> V_176 , sizeof( struct V_185 ) ) ;
F_87 ( & V_7 -> V_172 , sizeof( struct V_186 ) , 32 ) ;
F_87 ( & V_7 -> V_173 , sizeof( struct V_186 ) , 32 ) ;
F_87 ( & V_7 -> V_159 , sizeof( struct V_156 ) , 16 ) ;
F_87 ( & V_7 -> V_165 , sizeof( struct V_156 ) , 16 ) ;
F_87 ( & V_7 -> V_170 , sizeof( struct V_169 ) , 8 ) ;
F_87 ( & V_7 -> V_51 , sizeof( T_2 ) , 64 ) ;
F_87 ( & V_7 -> V_174 , sizeof( struct V_187 ) , 16 ) ;
if ( V_7 -> V_29 -> V_115 ) {
V_7 -> V_115 = F_65 ( V_7 -> V_29 -> V_115 , V_98 ) ;
if ( ! V_7 -> V_115 ) {
F_47 ( V_7 ) ;
return - V_188 ;
}
}
#ifdef F_82
F_88 ( & V_7 -> V_171 , V_189 ) ;
F_7 ( V_7 ) ;
#endif
F_3 ( & V_7 -> V_4 , & V_29 -> V_118 ) ;
V_29 -> V_95 [ V_177 ] = V_7 ;
V_7 -> V_129 = F_22 ( V_7 , V_144 ,
V_190 ) ;
if ( V_7 -> V_129 == - 1 )
V_7 -> V_129 = F_22 ( V_7 , V_144 ,
V_190 ) ;
V_7 -> V_191 = F_22 ( V_7 , V_144 ,
V_192 ) ;
V_7 -> V_131 = F_22 ( V_7 , V_144 ,
V_193 ) ;
F_66 ( V_7 ) ;
if ( ! V_7 -> V_127 && ! V_7 -> V_128 ) {
F_89 ( L_55 ) ;
V_30 = - V_188 ;
goto error;
}
V_30 = F_67 ( V_7 , V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ) ;
if ( V_30 < 0 ) {
F_30 ( V_25 L_56 ) ;
goto error;
}
V_30 = F_69 ( V_7 ) ;
if ( V_30 < 0 )
goto error;
if ( ! V_7 -> V_191 ) {
T_2 V_19 = V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ;
V_7 -> V_191 =
F_18 ( V_7 , V_19 , 0 ,
V_194 , 0 ) ;
}
F_90 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_195 ) ;
F_91 ( V_7 ) ;
F_92 ( V_7 ) ;
sprintf ( V_179 , L_57 , V_7 -> V_129 ,
V_7 -> V_191 , V_7 -> V_131 ) ;
F_93 ( V_7 -> V_29 -> V_105 , V_179 ) ;
if ( V_178 )
* V_178 = V_7 ;
return 0 ;
error:
F_47 ( V_7 ) ;
return V_30 ;
}
int F_94 ( struct V_6 * V_7 )
{
int V_30 ;
V_7 -> V_2 = F_59 ( V_7 ) ;
if ( ! V_7 -> V_138 || ! V_7 -> V_141 ) {
V_30 = F_64 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( F_60 ( V_7 ) ) {
V_30 = F_95 ( V_7 ) ;
goto V_196;
}
if ( V_7 -> V_2 && V_7 -> V_2 -> V_197 ) {
V_30 = V_7 -> V_2 -> V_197 ( V_7 ) ;
goto V_196;
}
V_30 = F_95 ( V_7 ) ;
if ( V_30 < 0 )
F_13 ( V_25 L_58 ) ;
V_196:
if ( ! V_30 && V_7 -> V_96 . V_97 )
V_30 = F_40 ( V_7 -> V_29 ) ;
if ( ! V_30 && ( V_7 -> V_127 || ! * V_7 -> V_29 -> V_105 -> V_198 ) )
snprintf ( V_7 -> V_29 -> V_105 -> V_198 ,
sizeof( V_7 -> V_29 -> V_105 -> V_198 ) ,
L_59 , V_7 -> V_138 , V_7 -> V_141 ) ;
return V_30 ;
}
void F_96 ( struct V_6 * V_7 , T_2 V_19 ,
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
F_89 ( L_60
L_61 ,
V_19 , V_199 , V_200 , V_201 ) ;
V_49 = F_81 ( V_7 , V_19 ) ;
if ( ! V_49 )
return;
if ( V_49 -> V_199 != V_199 || V_49 -> V_200 != V_200 ) {
V_202 = F_18 ( V_7 , V_19 , 0 , V_204 , 0 ) ;
V_203 = ( V_199 << 4 ) | V_200 ;
if ( V_202 != V_203 )
F_19 ( V_7 , V_19 , 0 ,
V_205 ,
V_203 ) ;
V_49 -> V_199 = V_199 ;
V_49 -> V_200 = V_200 ;
}
if ( V_49 -> V_206 != V_201 ) {
V_202 = F_18 ( V_7 , V_19 , 0 ,
V_207 , 0 ) ;
if ( V_202 != V_201 ) {
F_97 ( 1 ) ;
F_19 ( V_7 , V_19 , 0 ,
V_208 ,
V_201 ) ;
}
V_49 -> V_206 = V_201 ;
}
V_49 -> V_209 = 1 ;
V_49 -> V_210 = 0 ;
type = F_32 ( F_31 ( V_7 , V_19 ) ) ;
F_51 (c, &codec->bus->codec_list, list) {
for ( V_12 = 0 ; V_12 < V_135 -> V_170 . V_48 ; V_12 ++ ) {
V_49 = F_24 ( & V_135 -> V_170 , V_12 ) ;
if ( ! V_49 -> V_209 && V_49 -> V_199 == V_199 &&
F_32 ( F_31 ( V_7 , V_49 -> V_19 ) ) == type )
V_49 -> V_210 = 1 ;
}
}
}
void F_98 ( struct V_6 * V_7 , T_2 V_19 ,
int V_211 )
{
struct V_169 * V_49 ;
if ( ! V_19 )
return;
if ( V_7 -> V_212 )
V_211 = 1 ;
F_89 ( L_62 , V_19 ) ;
V_49 = F_81 ( V_7 , V_19 ) ;
if ( V_49 ) {
if ( V_211 )
F_99 ( V_7 , V_49 ) ;
else
V_49 -> V_209 = 0 ;
}
}
static void F_99 ( struct V_6 * V_7 ,
struct V_169 * V_213 )
{
T_2 V_19 = V_213 -> V_19 ;
F_19 ( V_7 , V_19 , 0 , V_205 , 0 ) ;
F_19 ( V_7 , V_19 , 0 , V_208 , 0 ) ;
memset ( V_213 , 0 , sizeof( * V_213 ) ) ;
V_213 -> V_19 = V_19 ;
}
static void F_100 ( struct V_6 * V_7 )
{
struct V_6 * V_135 ;
int V_12 ;
F_51 (c, &codec->bus->codec_list, list) {
for ( V_12 = 0 ; V_12 < V_135 -> V_170 . V_48 ; V_12 ++ ) {
struct V_169 * V_49 ;
V_49 = F_24 ( & V_135 -> V_170 , V_12 ) ;
if ( V_49 -> V_210 )
F_99 ( V_135 , V_49 ) ;
}
}
}
static void F_101 ( struct V_6 * V_7 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_170 . V_48 ; V_12 ++ ) {
struct V_169 * V_49 = F_24 ( & V_7 -> V_170 , V_12 ) ;
if ( V_49 -> V_199 )
F_99 ( V_7 , V_49 ) ;
}
}
static void F_86 ( struct V_214 * V_215 ,
unsigned int V_216 )
{
memset ( V_215 , 0 , sizeof( * V_215 ) ) ;
memset ( V_215 -> V_217 , 0xff , sizeof( V_215 -> V_217 ) ) ;
F_87 ( & V_215 -> V_218 , V_216 , 64 ) ;
}
static void F_84 ( struct V_214 * V_215 )
{
F_80 ( & V_215 -> V_218 ) ;
}
static struct V_185 * F_102 ( struct V_214 * V_215 , T_1 V_219 )
{
T_3 V_220 = V_219 % ( T_3 ) F_9 ( V_215 -> V_217 ) ;
T_3 V_221 = V_215 -> V_217 [ V_220 ] ;
struct V_185 * V_222 ;
while ( V_221 != 0xffff ) {
V_222 = F_24 ( & V_215 -> V_218 , V_221 ) ;
if ( V_222 -> V_219 == V_219 )
return V_222 ;
V_221 = V_222 -> V_223 ;
}
return NULL ;
}
static struct V_185 * F_103 ( struct V_214 * V_215 ,
T_1 V_219 )
{
struct V_185 * V_222 = F_102 ( V_215 , V_219 ) ;
if ( ! V_222 ) {
T_3 V_220 , V_221 ;
V_222 = F_34 ( & V_215 -> V_218 ) ;
if ( ! V_222 )
return NULL ;
V_221 = F_104 ( & V_215 -> V_218 , V_222 ) ;
V_222 -> V_219 = V_219 ;
V_222 -> V_23 = 0 ;
V_220 = V_219 % ( T_3 ) F_9 ( V_215 -> V_217 ) ;
V_222 -> V_223 = V_215 -> V_217 [ V_220 ] ;
V_215 -> V_217 [ V_220 ] = V_221 ;
}
return V_222 ;
}
static inline struct V_184 *
F_105 ( struct V_6 * V_7 , T_1 V_219 )
{
return (struct V_184 * ) F_103 ( & V_7 -> V_175 , V_219 ) ;
}
T_1 F_106 ( struct V_6 * V_7 , T_2 V_19 , int V_224 )
{
struct V_184 * V_222 ;
V_222 = F_105 ( V_7 , F_107 ( V_19 , V_224 , 0 ) ) ;
if ( ! V_222 )
return 0 ;
if ( ! ( V_222 -> V_225 . V_23 & V_226 ) ) {
if ( ! ( F_31 ( V_7 , V_19 ) & V_227 ) )
V_19 = V_7 -> V_127 ;
V_222 -> V_228 = F_22 ( V_7 , V_19 ,
V_224 == V_229 ?
V_230 :
V_231 ) ;
if ( V_222 -> V_228 )
V_222 -> V_225 . V_23 |= V_226 ;
}
return V_222 -> V_228 ;
}
int F_108 ( struct V_6 * V_7 , T_2 V_19 , int V_232 ,
unsigned int V_233 )
{
struct V_184 * V_222 ;
V_222 = F_105 ( V_7 , F_107 ( V_19 , V_232 , 0 ) ) ;
if ( ! V_222 )
return - V_54 ;
V_222 -> V_228 = V_233 ;
V_222 -> V_225 . V_23 |= V_226 ;
return 0 ;
}
static unsigned int F_109 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_22 ( V_7 , V_19 , V_234 ) ;
}
T_1 F_110 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_111 ( V_7 , V_19 , F_112 ( V_19 ) ,
F_109 ) ;
}
T_1 F_113 ( struct V_6 * V_7 , T_2 V_19 )
{
T_1 V_235 ;
if ( ! V_7 -> V_236 ) {
V_235 = F_110 ( V_7 , V_19 ) ;
if ( V_235 & V_237 )
F_18 ( V_7 , V_19 , 0 ,
V_238 , 0 ) ;
}
return F_18 ( V_7 , V_19 , 0 ,
V_239 , 0 ) ;
}
int F_114 ( struct V_6 * V_7 , T_2 V_19 )
{
T_1 V_240 = F_113 ( V_7 , V_19 ) ;
return ! ! ( V_240 & V_241 ) ;
}
static unsigned int F_115 ( struct V_6 * V_7 ,
struct V_184 * V_222 , T_2 V_19 ,
int V_242 , int V_224 , int V_243 )
{
T_1 V_23 , V_22 ;
if ( V_222 -> V_225 . V_23 & F_116 ( V_242 ) )
return V_222 -> V_244 [ V_242 ] ;
V_22 = V_242 ? V_245 : V_246 ;
V_22 |= V_224 == V_229 ? V_247 : V_248 ;
V_22 |= V_243 ;
V_23 = F_18 ( V_7 , V_19 , 0 ,
V_249 , V_22 ) ;
V_222 -> V_244 [ V_242 ] = V_23 & 0xff ;
V_222 -> V_225 . V_23 |= F_116 ( V_242 ) ;
return V_222 -> V_244 [ V_242 ] ;
}
static void F_117 ( struct V_6 * V_7 , struct V_184 * V_222 ,
T_2 V_19 , int V_242 , int V_224 , int V_243 ,
int V_23 )
{
T_1 V_22 ;
V_22 = V_242 ? V_250 : V_251 ;
V_22 |= V_224 == V_229 ? V_252 : V_253 ;
V_22 |= V_243 << V_254 ;
V_22 |= V_23 ;
F_19 ( V_7 , V_19 , 0 , V_255 , V_22 ) ;
V_222 -> V_244 [ V_242 ] = V_23 ;
}
int F_118 ( struct V_6 * V_7 , T_2 V_19 , int V_242 ,
int V_224 , int V_243 )
{
struct V_184 * V_222 ;
V_222 = F_105 ( V_7 , F_107 ( V_19 , V_224 , V_243 ) ) ;
if ( ! V_222 )
return 0 ;
return F_115 ( V_7 , V_222 , V_19 , V_242 , V_224 , V_243 ) ;
}
int F_119 ( struct V_6 * V_7 , T_2 V_19 , int V_242 ,
int V_224 , int V_220 , int V_61 , int V_23 )
{
struct V_184 * V_222 ;
V_222 = F_105 ( V_7 , F_107 ( V_19 , V_224 , V_220 ) ) ;
if ( ! V_222 )
return 0 ;
if ( F_26 ( V_61 & ~ 0xff ) )
V_61 &= 0xff ;
V_23 &= V_61 ;
V_23 |= F_115 ( V_7 , V_222 , V_19 , V_242 , V_224 , V_220 ) & ~ V_61 ;
if ( V_222 -> V_244 [ V_242 ] == V_23 )
return 0 ;
F_117 ( V_7 , V_222 , V_19 , V_242 , V_224 , V_220 , V_23 ) ;
return 1 ;
}
int F_120 ( struct V_6 * V_7 , T_2 V_19 ,
int V_224 , int V_220 , int V_61 , int V_23 )
{
int V_242 , V_256 = 0 ;
if ( F_26 ( V_61 & ~ 0xff ) )
V_61 &= 0xff ;
for ( V_242 = 0 ; V_242 < 2 ; V_242 ++ )
V_256 |= F_119 ( V_7 , V_19 , V_242 , V_224 ,
V_220 , V_61 , V_23 ) ;
return V_256 ;
}
void F_121 ( struct V_6 * V_7 )
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
if ( ! ( V_257 -> V_225 . V_23 & F_116 ( V_242 ) ) )
continue;
F_117 ( V_7 , V_257 , V_19 , V_242 , V_232 , V_220 ,
V_257 -> V_244 [ V_242 ] ) ;
}
}
}
static T_1 F_122 ( struct V_6 * V_7 , T_2 V_19 , int V_232 ,
unsigned int V_258 )
{
T_1 V_233 = F_106 ( V_7 , V_19 , V_232 ) ;
V_233 = ( V_233 & V_259 ) >> V_260 ;
if ( V_258 < V_233 )
V_233 -= V_258 ;
return V_233 ;
}
int F_123 ( struct V_261 * V_262 ,
struct V_263 * V_264 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
T_3 V_19 = F_125 ( V_262 ) ;
T_4 V_265 = F_126 ( V_262 ) ;
int V_232 = F_127 ( V_262 ) ;
unsigned int V_258 = F_128 ( V_262 ) ;
V_264 -> type = V_266 ;
V_264 -> V_267 = V_265 == 3 ? 2 : 1 ;
V_264 -> V_268 . integer . V_269 = 0 ;
V_264 -> V_268 . integer . V_270 = F_122 ( V_7 , V_19 , V_232 , V_258 ) ;
if ( ! V_264 -> V_268 . integer . V_270 ) {
F_13 ( V_73 L_39
L_63 , V_19 ,
V_262 -> V_126 . V_133 ) ;
return - V_54 ;
}
return 0 ;
}
static inline unsigned int
F_129 ( struct V_6 * V_7 , T_2 V_19 ,
int V_242 , int V_232 , int V_220 , unsigned int V_258 )
{
unsigned int V_23 ;
V_23 = F_118 ( V_7 , V_19 , V_242 , V_232 , V_220 ) ;
V_23 &= V_271 ;
if ( V_23 >= V_258 )
V_23 -= V_258 ;
else
V_23 = 0 ;
return V_23 ;
}
static inline int
F_130 ( struct V_6 * V_7 , T_2 V_19 ,
int V_242 , int V_232 , int V_220 , unsigned int V_258 ,
unsigned int V_23 )
{
unsigned int V_272 ;
if ( V_23 > 0 )
V_23 += V_258 ;
V_272 = F_122 ( V_7 , V_19 , V_232 , 0 ) ;
if ( V_23 > V_272 )
V_23 = V_272 ;
return F_119 ( V_7 , V_19 , V_242 , V_232 , V_220 ,
V_271 , V_23 ) ;
}
int F_131 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
T_2 V_19 = F_125 ( V_262 ) ;
int V_265 = F_126 ( V_262 ) ;
int V_232 = F_127 ( V_262 ) ;
int V_220 = F_132 ( V_262 ) ;
unsigned int V_258 = F_128 ( V_262 ) ;
long * V_275 = V_274 -> V_268 . integer . V_268 ;
if ( V_265 & 1 )
* V_275 ++ = F_129 ( V_7 , V_19 , 0 , V_232 , V_220 , V_258 ) ;
if ( V_265 & 2 )
* V_275 = F_129 ( V_7 , V_19 , 1 , V_232 , V_220 , V_258 ) ;
return 0 ;
}
int F_133 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
T_2 V_19 = F_125 ( V_262 ) ;
int V_265 = F_126 ( V_262 ) ;
int V_232 = F_127 ( V_262 ) ;
int V_220 = F_132 ( V_262 ) ;
unsigned int V_258 = F_128 ( V_262 ) ;
long * V_275 = V_274 -> V_268 . integer . V_268 ;
int V_276 = 0 ;
F_15 ( V_7 ) ;
if ( V_265 & 1 ) {
V_276 = F_130 ( V_7 , V_19 , 0 , V_232 , V_220 , V_258 , * V_275 ) ;
V_275 ++ ;
}
if ( V_265 & 2 )
V_276 |= F_130 ( V_7 , V_19 , 1 , V_232 , V_220 , V_258 , * V_275 ) ;
F_16 ( V_7 ) ;
return V_276 ;
}
int F_134 ( struct V_261 * V_262 , int V_277 ,
unsigned int V_278 , unsigned int T_5 * V_279 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
T_2 V_19 = F_125 ( V_262 ) ;
int V_232 = F_127 ( V_262 ) ;
unsigned int V_258 = F_128 ( V_262 ) ;
bool V_280 = F_135 ( V_262 ) ;
T_1 V_233 , V_281 , V_282 ;
if ( V_278 < 4 * sizeof( unsigned int ) )
return - V_76 ;
V_233 = F_106 ( V_7 , V_19 , V_232 ) ;
V_282 = ( V_233 & V_283 ) >> V_284 ;
V_282 = ( V_282 + 1 ) * 25 ;
V_281 = - ( ( V_233 & V_285 ) >> V_286 ) ;
V_281 += V_258 ;
V_281 = ( ( int ) V_281 ) * ( ( int ) V_282 ) ;
if ( V_280 )
V_282 |= V_287 ;
if ( F_136 ( V_288 , V_279 ) )
return - V_289 ;
if ( F_136 ( 2 * sizeof( unsigned int ) , V_279 + 1 ) )
return - V_289 ;
if ( F_136 ( V_281 , V_279 + 2 ) )
return - V_289 ;
if ( F_136 ( V_282 , V_279 + 3 ) )
return - V_289 ;
return 0 ;
}
void F_137 ( struct V_6 * V_7 , T_2 V_19 , int V_232 ,
unsigned int * V_290 )
{
T_1 V_233 ;
int V_81 , V_291 ;
V_233 = F_106 ( V_7 , V_19 , V_232 ) ;
V_81 = ( V_233 & V_259 ) >> V_260 ;
V_291 = ( V_233 & V_283 ) >> V_284 ;
V_291 = ( V_291 + 1 ) * 25 ;
V_290 [ 0 ] = V_288 ;
V_290 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_290 [ 2 ] = - V_81 * V_291 ;
V_290 [ 3 ] = V_291 ;
}
static struct V_261 *
F_138 ( struct V_6 * V_7 ,
const char * V_133 , int V_220 )
{
struct V_292 V_126 ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_293 = V_294 ;
V_126 . V_243 = V_220 ;
if ( F_26 ( strlen ( V_133 ) >= sizeof( V_126 . V_133 ) ) )
return NULL ;
strcpy ( V_126 . V_133 , V_133 ) ;
return F_139 ( V_7 -> V_29 -> V_105 , & V_126 ) ;
}
struct V_261 * F_140 ( struct V_6 * V_7 ,
const char * V_133 )
{
return F_138 ( V_7 , V_133 , 0 ) ;
}
static int F_141 ( struct V_6 * V_7 , const char * V_133 )
{
int V_220 ;
for ( V_220 = 0 ; V_220 < 16 ; V_220 ++ ) {
if ( ! F_138 ( V_7 , V_133 , V_220 ) )
return V_220 ;
}
return - V_181 ;
}
int F_142 ( struct V_6 * V_7 , T_2 V_19 ,
struct V_261 * V_295 )
{
int V_30 ;
unsigned short V_296 = 0 ;
struct V_186 * V_297 ;
if ( V_295 -> V_126 . V_298 & V_299 ) {
V_296 |= V_300 ;
if ( V_19 == 0 )
V_19 = F_143 ( V_295 -> V_301 ) ;
}
if ( ( V_295 -> V_126 . V_298 & V_302 ) != 0 && V_19 == 0 )
V_19 = V_295 -> V_126 . V_298 & 0xffff ;
if ( V_295 -> V_126 . V_298 & ( V_302 | V_299 ) )
V_295 -> V_126 . V_298 = 0 ;
V_30 = F_144 ( V_7 -> V_29 -> V_105 , V_295 ) ;
if ( V_30 < 0 )
return V_30 ;
V_297 = F_34 ( & V_7 -> V_172 ) ;
if ( ! V_297 )
return - V_76 ;
V_297 -> V_295 = V_295 ;
V_297 -> V_19 = V_19 ;
V_297 -> V_296 = V_296 ;
return 0 ;
}
int F_145 ( struct V_6 * V_7 , struct V_261 * V_295 ,
unsigned int V_243 , T_2 V_19 )
{
struct V_186 * V_297 ;
if ( V_19 > 0 ) {
V_297 = F_34 ( & V_7 -> V_173 ) ;
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
void F_146 ( struct V_6 * V_7 )
{
int V_12 ;
struct V_186 * V_303 = V_7 -> V_172 . V_4 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_172 . V_48 ; V_12 ++ )
F_147 ( V_7 -> V_29 -> V_105 , V_303 [ V_12 ] . V_295 ) ;
F_80 ( & V_7 -> V_172 ) ;
F_80 ( & V_7 -> V_173 ) ;
}
static int F_148 ( struct V_104 * V_105 )
{
F_149 ( & V_105 -> V_304 ) ;
if ( V_105 -> V_103 ) {
F_150 ( & V_105 -> V_304 ) ;
return - V_54 ;
}
V_105 -> V_103 = 1 ;
F_150 ( & V_105 -> V_304 ) ;
return 0 ;
}
static void F_151 ( struct V_104 * V_105 )
{
F_149 ( & V_105 -> V_304 ) ;
V_105 -> V_103 = 0 ;
F_150 ( & V_105 -> V_304 ) ;
}
int F_152 ( struct V_6 * V_7 )
{
struct V_104 * V_105 = V_7 -> V_29 -> V_105 ;
int V_12 , V_305 ;
if ( F_148 ( V_105 ) < 0 )
return - V_181 ;
if ( ! F_153 ( & V_105 -> V_306 ) ) {
F_151 ( V_105 ) ;
return - V_181 ;
}
for ( V_305 = 0 ; V_305 < V_7 -> V_307 ; V_305 ++ ) {
struct V_308 * V_309 = & V_7 -> V_310 [ V_305 ] ;
if ( ! V_309 -> V_305 )
continue;
if ( V_309 -> V_305 -> V_311 [ 0 ] . V_312 ||
V_309 -> V_305 -> V_311 [ 1 ] . V_312 ) {
F_151 ( V_105 ) ;
return - V_181 ;
}
}
#ifdef F_82
F_83 ( & V_7 -> V_171 ) ;
F_44 ( V_7 -> V_29 -> V_90 ) ;
#endif
F_146 ( V_7 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_307 ; V_12 ++ ) {
if ( V_7 -> V_310 [ V_12 ] . V_305 ) {
F_154 ( V_105 , V_7 -> V_310 [ V_12 ] . V_305 ) ;
F_155 ( V_7 -> V_310 [ V_12 ] . V_101 ,
V_7 -> V_29 -> V_313 ) ;
}
}
if ( V_7 -> V_96 . free )
V_7 -> V_96 . free ( V_7 ) ;
V_7 -> V_314 = NULL ;
V_7 -> V_315 = NULL ;
F_84 ( & V_7 -> V_175 ) ;
F_84 ( & V_7 -> V_176 ) ;
F_86 ( & V_7 -> V_175 , sizeof( struct V_184 ) ) ;
F_86 ( & V_7 -> V_176 , sizeof( struct V_185 ) ) ;
F_80 ( & V_7 -> V_165 ) ;
F_76 ( V_7 ) ;
V_7 -> V_307 = 0 ;
V_7 -> V_310 = NULL ;
V_7 -> V_2 = NULL ;
memset ( & V_7 -> V_96 , 0 , sizeof( V_7 -> V_96 ) ) ;
V_7 -> V_316 = NULL ;
V_7 -> V_317 = 0 ;
F_62 ( V_7 -> V_125 ) ;
V_7 -> V_125 = NULL ;
F_151 ( V_105 ) ;
return 0 ;
}
int F_156 ( struct V_6 * V_7 , char * V_133 ,
unsigned int * V_290 , const char * const * V_318 )
{
struct V_261 * V_295 ;
const char * const * V_319 ;
int V_30 ;
for ( V_319 = V_318 ; * V_319 && ! F_140 ( V_7 , * V_319 ) ; V_319 ++ )
;
if ( ! * V_319 ) {
F_89 ( L_65 , V_133 ) ;
return 0 ;
}
V_295 = F_157 ( V_133 , V_290 ) ;
if ( ! V_295 )
return - V_76 ;
V_30 = F_142 ( V_7 , 0 , V_295 ) ;
if ( V_30 < 0 )
return V_30 ;
for ( V_319 = V_318 ; * V_319 ; V_319 ++ ) {
struct V_261 * V_320 ;
int V_12 = 0 ;
for (; ; ) {
V_320 = F_138 ( V_7 , * V_319 , V_12 ) ;
if ( ! V_320 ) {
if ( ! V_12 )
F_89 ( L_66
L_67 , * V_319 ) ;
break;
}
V_30 = F_158 ( V_295 , V_320 ) ;
if ( V_30 < 0 )
return V_30 ;
V_12 ++ ;
}
}
return 0 ;
}
int F_159 ( struct V_261 * V_262 ,
struct V_263 * V_264 )
{
int V_265 = F_126 ( V_262 ) ;
V_264 -> type = V_321 ;
V_264 -> V_267 = V_265 == 3 ? 2 : 1 ;
V_264 -> V_268 . integer . V_269 = 0 ;
V_264 -> V_268 . integer . V_270 = 1 ;
return 0 ;
}
int F_160 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
T_2 V_19 = F_125 ( V_262 ) ;
int V_265 = F_126 ( V_262 ) ;
int V_232 = F_127 ( V_262 ) ;
int V_220 = F_132 ( V_262 ) ;
long * V_275 = V_274 -> V_268 . integer . V_268 ;
if ( V_265 & 1 )
* V_275 ++ = ( F_118 ( V_7 , V_19 , 0 , V_232 , V_220 ) &
V_322 ) ? 0 : 1 ;
if ( V_265 & 2 )
* V_275 = ( F_118 ( V_7 , V_19 , 1 , V_232 , V_220 ) &
V_322 ) ? 0 : 1 ;
return 0 ;
}
int F_161 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
T_2 V_19 = F_125 ( V_262 ) ;
int V_265 = F_126 ( V_262 ) ;
int V_232 = F_127 ( V_262 ) ;
int V_220 = F_132 ( V_262 ) ;
long * V_275 = V_274 -> V_268 . integer . V_268 ;
int V_276 = 0 ;
F_15 ( V_7 ) ;
if ( V_265 & 1 ) {
V_276 = F_119 ( V_7 , V_19 , 0 , V_232 , V_220 ,
V_322 ,
* V_275 ? 0 : V_322 ) ;
V_275 ++ ;
}
if ( V_265 & 2 )
V_276 |= F_119 ( V_7 , V_19 , 1 , V_232 , V_220 ,
V_322 ,
* V_275 ? 0 : V_322 ) ;
F_162 ( V_7 , V_19 ) ;
F_16 ( V_7 ) ;
return V_276 ;
}
int F_163 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
long * V_275 = V_274 -> V_268 . integer . V_268 ;
F_164 ( V_7 , * V_275 ) ;
return F_161 ( V_262 , V_274 ) ;
}
int F_165 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
unsigned long V_323 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_323 = V_262 -> V_301 ;
V_262 -> V_301 = V_323 & ~ V_324 ;
V_30 = F_160 ( V_262 , V_274 ) ;
V_262 -> V_301 = V_323 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_166 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
unsigned long V_323 ;
int V_12 , V_325 , V_30 = 0 , V_276 = 0 ;
F_2 ( & V_7 -> V_183 ) ;
V_323 = V_262 -> V_301 ;
V_325 = ( V_323 & V_324 ) >> V_326 ;
for ( V_12 = 0 ; V_12 < V_325 ; V_12 ++ ) {
V_262 -> V_301 = ( V_323 & ~ V_324 ) |
( V_12 << V_326 ) ;
V_30 = F_161 ( V_262 , V_274 ) ;
if ( V_30 < 0 )
break;
V_276 |= V_30 ;
}
V_262 -> V_301 = V_323 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 < 0 ? V_30 : V_276 ;
}
int F_167 ( struct V_261 * V_262 ,
struct V_263 * V_264 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
struct V_327 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_327 * ) V_262 -> V_301 ;
V_262 -> V_301 = * V_135 -> V_328 ;
V_30 = V_135 -> V_33 -> V_222 ( V_262 , V_264 ) ;
V_262 -> V_301 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_168 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
struct V_327 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_327 * ) V_262 -> V_301 ;
V_262 -> V_301 = * V_135 -> V_328 ;
V_30 = V_135 -> V_33 -> V_329 ( V_262 , V_274 ) ;
V_262 -> V_301 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_169 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
struct V_327 * V_135 ;
unsigned long * V_330 ;
int V_30 = 0 , V_276 = 0 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_327 * ) V_262 -> V_301 ;
for ( V_330 = V_135 -> V_328 ; * V_330 ; V_330 ++ ) {
V_262 -> V_301 = * V_330 ;
V_30 = V_135 -> V_33 -> V_331 ( V_262 , V_274 ) ;
if ( V_30 < 0 )
break;
V_276 |= V_30 ;
}
V_262 -> V_301 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 < 0 ? V_30 : V_276 ;
}
int F_170 ( struct V_261 * V_262 , int V_277 ,
unsigned int V_278 , unsigned int T_5 * V_290 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
struct V_327 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_327 * ) V_262 -> V_301 ;
V_262 -> V_301 = * V_135 -> V_328 ;
V_30 = V_135 -> V_33 -> V_290 ( V_262 , V_277 , V_278 , V_290 ) ;
V_262 -> V_301 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
static int F_171 ( struct V_261 * V_262 ,
struct V_263 * V_264 )
{
V_264 -> type = V_332 ;
V_264 -> V_267 = 1 ;
return 0 ;
}
static int F_172 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
V_274 -> V_268 . V_333 . V_334 [ 0 ] = V_335 |
V_336 |
V_337 |
V_338 ;
V_274 -> V_268 . V_333 . V_334 [ 1 ] = V_339 |
V_340 ;
return 0 ;
}
static int F_173 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
V_274 -> V_268 . V_333 . V_334 [ 0 ] = V_335 |
V_336 |
V_341 ;
return 0 ;
}
static int F_174 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
int V_220 = V_262 -> V_301 ;
struct V_187 * V_342 = F_24 ( & V_7 -> V_174 , V_220 ) ;
V_274 -> V_268 . V_333 . V_334 [ 0 ] = V_342 -> V_334 & 0xff ;
V_274 -> V_268 . V_333 . V_334 [ 1 ] = ( V_342 -> V_334 >> 8 ) & 0xff ;
V_274 -> V_268 . V_333 . V_334 [ 2 ] = ( V_342 -> V_334 >> 16 ) & 0xff ;
V_274 -> V_268 . V_333 . V_334 [ 3 ] = ( V_342 -> V_334 >> 24 ) & 0xff ;
return 0 ;
}
static unsigned short F_175 ( unsigned int V_343 )
{
unsigned short V_23 = 0 ;
if ( V_343 & V_335 )
V_23 |= V_344 ;
if ( V_343 & V_336 )
V_23 |= V_345 ;
if ( V_343 & V_335 ) {
if ( ( V_343 & V_346 ) ==
V_341 )
V_23 |= V_347 ;
} else {
if ( ( V_343 & V_348 ) ==
V_337 )
V_23 |= V_347 ;
if ( ! ( V_343 & V_338 ) )
V_23 |= V_349 ;
if ( V_343 & ( V_340 << 8 ) )
V_23 |= V_350 ;
V_23 |= V_343 & ( V_339 << 8 ) ;
}
return V_23 ;
}
static unsigned int F_176 ( unsigned short V_23 )
{
unsigned int V_343 = 0 ;
if ( V_23 & V_345 )
V_343 |= V_336 ;
if ( V_23 & V_344 )
V_343 |= V_335 ;
if ( V_343 & V_335 ) {
if ( V_343 & V_347 )
V_343 |= V_341 ;
} else {
if ( V_23 & V_347 )
V_343 |= V_337 ;
if ( ! ( V_23 & V_349 ) )
V_343 |= V_338 ;
if ( V_23 & V_350 )
V_343 |= ( V_340 << 8 ) ;
V_343 |= V_23 & ( 0x7f << 8 ) ;
}
return V_343 ;
}
static void F_177 ( struct V_6 * V_7 , T_2 V_19 ,
int V_21 , int V_23 )
{
const T_2 * V_351 ;
F_178 ( V_7 , V_19 , 0 , V_21 , V_23 ) ;
V_351 = V_7 -> V_316 ;
if ( ! V_351 )
return;
for (; * V_351 ; V_351 ++ )
F_178 ( V_7 , * V_351 , 0 , V_21 , V_23 ) ;
}
static inline void F_179 ( struct V_6 * V_7 , T_2 V_19 ,
int V_352 , int V_353 )
{
if ( V_352 != - 1 )
F_177 ( V_7 , V_19 , V_354 , V_352 ) ;
if ( V_353 != - 1 )
F_177 ( V_7 , V_19 , V_355 , V_353 ) ;
}
static int F_180 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
int V_220 = V_262 -> V_301 ;
struct V_187 * V_342 = F_24 ( & V_7 -> V_174 , V_220 ) ;
T_2 V_19 = V_342 -> V_19 ;
unsigned short V_23 ;
int V_276 ;
F_2 ( & V_7 -> V_182 ) ;
V_342 -> V_334 = V_274 -> V_268 . V_333 . V_334 [ 0 ] |
( ( unsigned int ) V_274 -> V_268 . V_333 . V_334 [ 1 ] << 8 ) |
( ( unsigned int ) V_274 -> V_268 . V_333 . V_334 [ 2 ] << 16 ) |
( ( unsigned int ) V_274 -> V_268 . V_333 . V_334 [ 3 ] << 24 ) ;
V_23 = F_175 ( V_342 -> V_334 ) ;
V_23 |= V_342 -> V_356 & 1 ;
V_276 = V_342 -> V_356 != V_23 ;
V_342 -> V_356 = V_23 ;
if ( V_276 && V_19 != ( T_3 ) - 1 )
F_179 ( V_7 , V_19 , V_23 & 0xff , ( V_23 >> 8 ) & 0xff ) ;
F_4 ( & V_7 -> V_182 ) ;
return V_276 ;
}
static int F_181 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
int V_220 = V_262 -> V_301 ;
struct V_187 * V_342 = F_24 ( & V_7 -> V_174 , V_220 ) ;
V_274 -> V_268 . integer . V_268 [ 0 ] = V_342 -> V_356 & V_357 ;
return 0 ;
}
static inline void F_182 ( struct V_6 * V_7 , T_2 V_19 ,
int V_352 , int V_353 )
{
F_179 ( V_7 , V_19 , V_352 , V_353 ) ;
if ( ( F_31 ( V_7 , V_19 ) & V_358 ) &&
( V_352 & V_357 ) )
F_120 ( V_7 , V_19 , V_229 , 0 ,
V_322 , 0 ) ;
}
static int F_183 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
int V_220 = V_262 -> V_301 ;
struct V_187 * V_342 = F_24 ( & V_7 -> V_174 , V_220 ) ;
T_2 V_19 = V_342 -> V_19 ;
unsigned short V_23 ;
int V_276 ;
F_2 ( & V_7 -> V_182 ) ;
V_23 = V_342 -> V_356 & ~ V_357 ;
if ( V_274 -> V_268 . integer . V_268 [ 0 ] )
V_23 |= V_357 ;
V_276 = V_342 -> V_356 != V_23 ;
V_342 -> V_356 = V_23 ;
if ( V_276 && V_19 != ( T_3 ) - 1 )
F_182 ( V_7 , V_19 , V_23 & 0xff , - 1 ) ;
F_4 ( & V_7 -> V_182 ) ;
return V_276 ;
}
int F_184 ( struct V_6 * V_7 ,
T_2 V_359 ,
T_2 V_360 )
{
int V_30 ;
struct V_261 * V_295 ;
struct V_361 * V_362 ;
int V_220 ;
struct V_187 * V_342 ;
V_220 = F_141 ( V_7 , L_68 ) ;
if ( V_220 < 0 ) {
F_13 ( V_25 L_69 ) ;
return - V_181 ;
}
V_342 = F_34 ( & V_7 -> V_174 ) ;
for ( V_362 = V_363 ; V_362 -> V_133 ; V_362 ++ ) {
V_295 = F_185 ( V_362 , V_7 ) ;
if ( ! V_295 )
return - V_76 ;
V_295 -> V_126 . V_243 = V_220 ;
V_295 -> V_301 = V_7 -> V_174 . V_48 - 1 ;
V_30 = F_142 ( V_7 , V_359 , V_295 ) ;
if ( V_30 < 0 )
return V_30 ;
}
V_342 -> V_19 = V_360 ;
V_342 -> V_356 = F_18 ( V_7 , V_360 , 0 ,
V_364 , 0 ) ;
V_342 -> V_334 = F_176 ( V_342 -> V_356 ) ;
return 0 ;
}
struct V_187 * F_186 ( struct V_6 * V_7 ,
T_2 V_19 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_174 . V_48 ; V_12 ++ ) {
struct V_187 * V_342 =
F_24 ( & V_7 -> V_174 , V_12 ) ;
if ( V_342 -> V_19 == V_19 )
return V_342 ;
}
return NULL ;
}
void F_187 ( struct V_6 * V_7 , int V_220 )
{
struct V_187 * V_342 = F_24 ( & V_7 -> V_174 , V_220 ) ;
F_2 ( & V_7 -> V_182 ) ;
V_342 -> V_19 = ( T_3 ) - 1 ;
F_4 ( & V_7 -> V_182 ) ;
}
void F_188 ( struct V_6 * V_7 , int V_220 , T_2 V_19 )
{
struct V_187 * V_342 = F_24 ( & V_7 -> V_174 , V_220 ) ;
unsigned short V_23 ;
F_2 ( & V_7 -> V_182 ) ;
if ( V_342 -> V_19 != V_19 ) {
V_342 -> V_19 = V_19 ;
V_23 = V_342 -> V_356 ;
F_182 ( V_7 , V_19 , V_23 & 0xff , ( V_23 >> 8 ) & 0xff ) ;
}
F_4 ( & V_7 -> V_182 ) ;
}
static int F_189 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_365 * V_366 = F_124 ( V_262 ) ;
V_274 -> V_268 . integer . V_268 [ 0 ] = V_366 -> V_367 ;
return 0 ;
}
static int F_190 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_365 * V_366 = F_124 ( V_262 ) ;
V_366 -> V_367 = ! ! V_274 -> V_268 . integer . V_268 [ 0 ] ;
return 0 ;
}
int F_191 ( struct V_6 * V_7 ,
struct V_365 * V_366 )
{
if ( ! V_366 -> V_368 )
return 0 ;
return F_142 ( V_7 , V_366 -> V_368 ,
F_185 ( & V_369 , V_366 ) ) ;
}
static int F_192 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
V_274 -> V_268 . integer . V_268 [ 0 ] = V_7 -> V_370 ;
return 0 ;
}
static int F_193 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
T_2 V_19 = V_262 -> V_301 ;
unsigned int V_23 = ! ! V_274 -> V_268 . integer . V_268 [ 0 ] ;
int V_276 ;
F_2 ( & V_7 -> V_182 ) ;
V_276 = V_7 -> V_370 != V_23 ;
if ( V_276 ) {
V_7 -> V_370 = V_23 ;
F_178 ( V_7 , V_19 , 0 ,
V_354 , V_23 ) ;
}
F_4 ( & V_7 -> V_182 ) ;
return V_276 ;
}
static int F_194 ( struct V_261 * V_262 ,
struct V_273 * V_274 )
{
struct V_6 * V_7 = F_124 ( V_262 ) ;
T_2 V_19 = V_262 -> V_301 ;
unsigned short V_23 ;
unsigned int V_343 ;
V_23 = F_18 ( V_7 , V_19 , 0 , V_364 , 0 ) ;
V_343 = F_176 ( V_23 ) ;
V_274 -> V_268 . V_333 . V_334 [ 0 ] = V_343 ;
V_274 -> V_268 . V_333 . V_334 [ 1 ] = V_343 >> 8 ;
V_274 -> V_268 . V_333 . V_334 [ 2 ] = V_343 >> 16 ;
V_274 -> V_268 . V_333 . V_334 [ 3 ] = V_343 >> 24 ;
return 0 ;
}
int F_195 ( struct V_6 * V_7 , T_2 V_19 )
{
int V_30 ;
struct V_261 * V_295 ;
struct V_361 * V_362 ;
int V_220 ;
V_220 = F_141 ( V_7 , L_70 ) ;
if ( V_220 < 0 ) {
F_13 ( V_25 L_71 ) ;
return - V_181 ;
}
for ( V_362 = V_371 ; V_362 -> V_133 ; V_362 ++ ) {
V_295 = F_185 ( V_362 , V_7 ) ;
if ( ! V_295 )
return - V_76 ;
V_295 -> V_301 = V_19 ;
V_30 = F_142 ( V_7 , V_19 , V_295 ) ;
if ( V_30 < 0 )
return V_30 ;
}
V_7 -> V_370 =
F_18 ( V_7 , V_19 , 0 ,
V_364 , 0 ) &
V_357 ;
return 0 ;
}
int F_178 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 , unsigned int V_21 , unsigned int V_22 )
{
int V_30 = F_19 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
struct V_185 * V_135 ;
T_1 V_219 ;
if ( V_30 < 0 )
return V_30 ;
V_21 = V_21 | ( V_22 >> 8 ) ;
V_22 &= 0xff ;
V_219 = F_196 ( V_19 , V_21 ) ;
F_2 ( & V_7 -> V_29 -> V_32 ) ;
V_135 = F_103 ( & V_7 -> V_176 , V_219 ) ;
if ( V_135 )
V_135 -> V_23 = V_22 ;
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return 0 ;
}
int F_197 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 , unsigned int V_21 , unsigned int V_22 )
{
struct V_185 * V_135 ;
T_1 V_219 ;
V_21 = V_21 | ( V_22 >> 8 ) ;
V_22 &= 0xff ;
V_219 = F_196 ( V_19 , V_21 ) ;
F_2 ( & V_7 -> V_29 -> V_32 ) ;
V_135 = F_102 ( & V_7 -> V_176 , V_219 ) ;
if ( V_135 && V_135 -> V_23 == V_22 ) {
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return 0 ;
}
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return F_178 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
}
void F_198 ( struct V_6 * V_7 )
{
struct V_185 * V_257 = V_7 -> V_176 . V_218 . V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_176 . V_218 . V_48 ; V_12 ++ , V_257 ++ ) {
T_1 V_219 = V_257 -> V_219 ;
if ( ! V_219 )
continue;
F_19 ( V_7 , F_199 ( V_219 ) , 0 ,
F_200 ( V_219 ) , V_257 -> V_23 ) ;
}
}
void F_201 ( struct V_6 * V_7 ,
const struct V_40 * V_41 )
{
for (; V_41 -> V_19 ; V_41 ++ )
F_178 ( V_7 , V_41 -> V_19 , 0 , V_41 -> V_21 ,
V_41 -> V_42 ) ;
}
void F_202 ( struct V_6 * V_7 , T_2 V_372 ,
unsigned int V_373 ,
bool V_374 )
{
T_2 V_19 = V_7 -> V_154 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_153 ; V_12 ++ , V_19 ++ ) {
unsigned int V_62 = F_31 ( V_7 , V_19 ) ;
if ( ! ( V_62 & V_375 ) )
continue;
if ( V_374 && V_373 == V_376 &&
F_32 ( V_62 ) == V_82 &&
( F_110 ( V_7 , V_19 ) & V_377 ) ) {
int V_378 = F_18 ( V_7 , V_19 , 0 ,
V_379 , 0 ) ;
if ( V_378 & 0x02 )
continue;
}
F_19 ( V_7 , V_19 , 0 , V_380 ,
V_373 ) ;
}
if ( V_373 == V_195 ) {
unsigned long V_381 ;
int V_382 ;
V_381 = V_383 + F_203 ( 500 ) ;
do {
V_382 = F_18 ( V_7 , V_372 , 0 ,
V_384 , 0 ) ;
if ( V_382 == V_373 )
break;
F_97 ( 1 ) ;
} while ( F_204 ( V_381 , V_383 ) );
}
}
static void F_90 ( struct V_6 * V_7 , T_2 V_372 ,
unsigned int V_373 )
{
if ( V_7 -> V_96 . V_385 ) {
V_7 -> V_96 . V_385 ( V_7 , V_372 , V_373 ) ;
return;
}
if ( V_373 == V_376 )
F_97 ( 100 ) ;
F_18 ( V_7 , V_372 , 0 , V_380 ,
V_373 ) ;
F_202 ( V_7 , V_372 , V_373 , true ) ;
}
static void F_205 ( struct V_6 * V_7 )
{
if ( V_7 -> V_386 . V_4 )
F_20 ( V_7 , V_7 -> V_386 . V_4 ) ;
}
static inline void F_205 ( struct V_6 * V_7 ) {}
static void F_206 ( struct V_6 * V_7 )
{
if ( V_7 -> V_96 . V_387 )
V_7 -> V_96 . V_387 ( V_7 , V_388 ) ;
F_101 ( V_7 ) ;
F_90 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_376 ) ;
#ifdef F_82
F_207 ( V_7 ) ;
F_83 ( & V_7 -> V_171 ) ;
V_7 -> V_389 = 0 ;
V_7 -> V_390 = 0 ;
V_7 -> V_391 = V_383 ;
#endif
}
static void F_208 ( struct V_6 * V_7 )
{
F_90 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_195 ) ;
F_76 ( V_7 ) ;
F_78 ( V_7 ) ;
F_205 ( V_7 ) ;
if ( V_7 -> V_96 . V_392 )
V_7 -> V_96 . V_392 ( V_7 ) ;
else {
if ( V_7 -> V_96 . V_393 )
V_7 -> V_96 . V_393 ( V_7 ) ;
F_121 ( V_7 ) ;
F_198 ( V_7 ) ;
}
}
int F_209 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_51 (codec, &bus->codec_list, list) {
int V_30 = F_210 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_72
L_73 , V_7 -> V_24 , V_30 ) ;
V_30 = F_152 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25
L_74 ) ;
return V_30 ;
}
}
}
return 0 ;
}
int F_210 ( struct V_6 * V_7 )
{
int V_30 = 0 ;
F_205 ( V_7 ) ;
if ( V_7 -> V_96 . V_393 )
V_30 = V_7 -> V_96 . V_393 ( V_7 ) ;
if ( ! V_30 && V_7 -> V_96 . V_394 )
V_30 = V_7 -> V_96 . V_394 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
unsigned int F_211 ( unsigned int V_395 ,
unsigned int V_396 ,
unsigned int V_201 ,
unsigned int V_397 ,
unsigned short V_398 )
{
int V_12 ;
unsigned int V_23 = 0 ;
for ( V_12 = 0 ; V_399 [ V_12 ] . V_400 ; V_12 ++ )
if ( V_399 [ V_12 ] . V_400 == V_395 ) {
V_23 = V_399 [ V_12 ] . V_401 ;
break;
}
if ( ! V_399 [ V_12 ] . V_400 ) {
F_89 ( L_75 , V_395 ) ;
return 0 ;
}
if ( V_396 == 0 || V_396 > 8 ) {
F_89 ( L_76 , V_396 ) ;
return 0 ;
}
V_23 |= V_396 - 1 ;
switch ( F_212 ( V_201 ) ) {
case 8 :
V_23 |= V_402 ;
break;
case 16 :
V_23 |= V_403 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_397 >= 32 || V_201 == V_404 )
V_23 |= V_405 ;
else if ( V_397 >= 24 )
V_23 |= V_406 ;
else
V_23 |= V_407 ;
break;
default:
F_89 ( L_77 ,
F_212 ( V_201 ) ) ;
return 0 ;
}
if ( V_398 & V_345 )
V_23 |= V_408 ;
return V_23 ;
}
static unsigned int F_213 ( struct V_6 * V_7 , T_2 V_19 )
{
unsigned int V_23 = 0 ;
if ( V_19 != V_7 -> V_127 &&
( F_31 ( V_7 , V_19 ) & V_409 ) )
V_23 = F_22 ( V_7 , V_19 , V_410 ) ;
if ( ! V_23 || V_23 == - 1 )
V_23 = F_22 ( V_7 , V_7 -> V_127 , V_410 ) ;
if ( ! V_23 || V_23 == - 1 )
return 0 ;
return V_23 ;
}
static unsigned int F_214 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_111 ( V_7 , V_19 , F_215 ( V_19 ) ,
F_213 ) ;
}
static unsigned int F_216 ( struct V_6 * V_7 , T_2 V_19 )
{
unsigned int V_311 = F_22 ( V_7 , V_19 , V_411 ) ;
if ( ! V_311 || V_311 == - 1 )
V_311 = F_22 ( V_7 , V_7 -> V_127 , V_411 ) ;
if ( ! V_311 || V_311 == - 1 )
return 0 ;
return V_311 ;
}
static unsigned int F_217 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_111 ( V_7 , V_19 , F_218 ( V_19 ) ,
F_216 ) ;
}
int F_219 ( struct V_6 * V_7 , T_2 V_19 ,
T_1 * V_412 , T_6 * V_413 , unsigned int * V_414 )
{
unsigned int V_12 , V_23 , V_62 ;
V_62 = F_31 ( V_7 , V_19 ) ;
V_23 = F_214 ( V_7 , V_19 ) ;
if ( V_412 ) {
T_1 V_415 = 0 ;
for ( V_12 = 0 ; V_12 < V_416 ; V_12 ++ ) {
if ( V_23 & ( 1 << V_12 ) )
V_415 |= V_399 [ V_12 ] . V_417 ;
}
if ( V_415 == 0 ) {
F_30 ( V_25 L_78
L_79 ,
V_19 , V_23 ,
( V_62 & V_409 ) ? 1 : 0 ) ;
return - V_70 ;
}
* V_412 = V_415 ;
}
if ( V_413 || V_414 ) {
T_6 V_418 = 0 ;
unsigned int V_311 , V_419 ;
V_311 = F_217 ( V_7 , V_19 ) ;
if ( ! V_311 )
return - V_70 ;
V_419 = 0 ;
if ( V_311 & V_420 ) {
if ( V_23 & V_421 ) {
V_418 |= V_422 ;
V_419 = 8 ;
}
if ( V_23 & V_423 ) {
V_418 |= V_424 ;
V_419 = 16 ;
}
if ( V_62 & V_425 ) {
if ( V_23 & V_426 )
V_418 |= V_427 ;
if ( V_23 & ( V_428 | V_429 ) )
V_418 |= V_430 ;
if ( V_23 & V_429 )
V_419 = 24 ;
else if ( V_23 & V_428 )
V_419 = 20 ;
} else if ( V_23 & ( V_428 | V_429 |
V_426 ) ) {
V_418 |= V_430 ;
if ( V_23 & V_426 )
V_419 = 32 ;
else if ( V_23 & V_429 )
V_419 = 24 ;
else if ( V_23 & V_428 )
V_419 = 20 ;
}
}
if ( V_311 & V_431 ) {
V_418 |= V_432 ;
if ( ! V_419 )
V_419 = 32 ;
}
if ( V_311 == V_433 ) {
V_418 |= V_422 ;
V_419 = 8 ;
}
if ( V_418 == 0 ) {
F_30 ( V_25 L_80
L_81
L_82 ,
V_19 , V_23 ,
( V_62 & V_409 ) ? 1 : 0 ,
V_311 ) ;
return - V_70 ;
}
if ( V_413 )
* V_413 = V_418 ;
if ( V_414 )
* V_414 = V_419 ;
}
return 0 ;
}
int F_220 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_201 )
{
int V_12 ;
unsigned int V_23 = 0 , V_395 , V_434 ;
V_23 = F_214 ( V_7 , V_19 ) ;
if ( ! V_23 )
return 0 ;
V_395 = V_201 & 0xff00 ;
for ( V_12 = 0 ; V_12 < V_416 ; V_12 ++ )
if ( V_399 [ V_12 ] . V_401 == V_395 ) {
if ( V_23 & ( 1 << V_12 ) )
break;
return 0 ;
}
if ( V_12 >= V_416 )
return 0 ;
V_434 = F_217 ( V_7 , V_19 ) ;
if ( ! V_434 )
return 0 ;
if ( V_434 & V_420 ) {
switch ( V_201 & 0xf0 ) {
case 0x00 :
if ( ! ( V_23 & V_421 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_23 & V_423 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_23 & V_428 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_23 & V_429 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_23 & V_426 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_221 ( struct V_435 * V_436 ,
struct V_6 * V_7 ,
struct V_437 * V_438 )
{
return 0 ;
}
static int F_222 ( struct V_435 * V_436 ,
struct V_6 * V_7 ,
unsigned int V_199 ,
unsigned int V_201 ,
struct V_437 * V_438 )
{
F_96 ( V_7 , V_436 -> V_19 , V_199 , 0 , V_201 ) ;
return 0 ;
}
static int F_223 ( struct V_435 * V_436 ,
struct V_6 * V_7 ,
struct V_437 * V_438 )
{
F_224 ( V_7 , V_436 -> V_19 ) ;
return 0 ;
}
static int F_225 ( struct V_6 * V_7 ,
struct V_435 * V_222 )
{
int V_30 ;
if ( V_222 -> V_19 && ( ! V_222 -> V_415 || ! V_222 -> V_418 ) ) {
V_30 = F_219 ( V_7 , V_222 -> V_19 ,
V_222 -> V_415 ? NULL : & V_222 -> V_415 ,
V_222 -> V_418 ? NULL : & V_222 -> V_418 ,
V_222 -> V_397 ? NULL : & V_222 -> V_397 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( V_222 -> V_33 . V_439 == NULL )
V_222 -> V_33 . V_439 = F_221 ;
if ( V_222 -> V_33 . V_440 == NULL )
V_222 -> V_33 . V_440 = F_221 ;
if ( V_222 -> V_33 . V_441 == NULL ) {
if ( F_26 ( ! V_222 -> V_19 ) )
return - V_54 ;
V_222 -> V_33 . V_441 = F_222 ;
}
if ( V_222 -> V_33 . V_442 == NULL ) {
if ( F_26 ( ! V_222 -> V_19 ) )
return - V_54 ;
V_222 -> V_33 . V_442 = F_223 ;
}
return 0 ;
}
int F_226 ( struct V_6 * V_7 ,
struct V_435 * V_436 ,
unsigned int V_434 ,
unsigned int V_201 ,
struct V_437 * V_438 )
{
int V_256 ;
F_2 ( & V_7 -> V_29 -> V_117 ) ;
V_256 = V_436 -> V_33 . V_441 ( V_436 , V_7 , V_434 , V_201 , V_438 ) ;
if ( V_256 >= 0 )
F_100 ( V_7 ) ;
F_4 ( & V_7 -> V_29 -> V_117 ) ;
return V_256 ;
}
void F_227 ( struct V_6 * V_7 ,
struct V_435 * V_436 ,
struct V_437 * V_438 )
{
F_2 ( & V_7 -> V_29 -> V_117 ) ;
V_436 -> V_33 . V_442 ( V_436 , V_7 , V_438 ) ;
F_4 ( & V_7 -> V_29 -> V_117 ) ;
}
static int F_228 ( struct V_28 * V_29 , int type )
{
static int V_443 [ V_444 ] [ 5 ] = {
[ V_445 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_446 ] = { 1 , - 1 } ,
[ V_447 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_448 ] = { 6 , - 1 } ,
} ;
int V_12 ;
if ( type >= V_444 ) {
F_30 ( V_73 L_83 , type ) ;
return - V_54 ;
}
for ( V_12 = 0 ; V_443 [ type ] [ V_12 ] >= 0 ; V_12 ++ )
if ( ! F_229 ( V_443 [ type ] [ V_12 ] , V_29 -> V_313 ) )
return V_443 [ type ] [ V_12 ] ;
F_30 ( V_73 L_84 ,
V_449 [ type ] ) ;
return - V_450 ;
}
static int F_230 ( struct V_6 * V_7 , struct V_308 * V_305 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
struct V_435 * V_222 ;
int V_434 , V_30 ;
if ( F_26 ( ! V_305 -> V_133 ) )
return - V_54 ;
for ( V_434 = 0 ; V_434 < 2 ; V_434 ++ ) {
V_222 = & V_305 -> V_434 [ V_434 ] ;
if ( V_222 -> V_451 ) {
V_30 = F_225 ( V_7 , V_222 ) ;
if ( V_30 < 0 )
return V_30 ;
}
}
return V_29 -> V_33 . V_452 ( V_29 , V_7 , V_305 ) ;
}
int F_231 ( struct V_6 * V_7 )
{
unsigned int V_305 ;
int V_30 ;
if ( ! V_7 -> V_307 ) {
if ( ! V_7 -> V_96 . V_453 )
return 0 ;
V_30 = V_7 -> V_96 . V_453 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_85
L_73 , V_7 -> V_24 , V_30 ) ;
V_30 = F_152 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25
L_74 ) ;
return V_30 ;
}
}
}
for ( V_305 = 0 ; V_305 < V_7 -> V_307 ; V_305 ++ ) {
struct V_308 * V_309 = & V_7 -> V_310 [ V_305 ] ;
int V_454 ;
if ( ! V_309 -> V_434 [ 0 ] . V_451 && ! V_309 -> V_434 [ 1 ] . V_451 )
continue;
if ( ! V_309 -> V_305 ) {
V_454 = F_228 ( V_7 -> V_29 , V_309 -> V_455 ) ;
if ( V_454 < 0 )
continue;
V_309 -> V_101 = V_454 ;
V_30 = F_230 ( V_7 , V_309 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_86
L_87 ,
V_454 , V_7 -> V_24 ) ;
continue;
}
}
}
return 0 ;
}
int T_7 F_232 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_51 (codec, &bus->codec_list, list) {
int V_30 = F_231 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
}
return 0 ;
}
int F_233 ( struct V_6 * V_7 ,
int V_456 , const char * const * V_457 ,
const struct V_458 * V_123 )
{
if ( V_7 -> V_115 && V_457 ) {
int V_12 ;
for ( V_12 = 0 ; V_12 < V_456 ; V_12 ++ ) {
if ( V_457 [ V_12 ] &&
! strcmp ( V_7 -> V_115 , V_457 [ V_12 ] ) ) {
F_17 ( V_459 L_88
L_89 , V_457 [ V_12 ] ) ;
return V_12 ;
}
}
}
if ( ! V_7 -> V_29 -> V_114 || ! V_123 )
return - 1 ;
V_123 = F_234 ( V_7 -> V_29 -> V_114 , V_123 ) ;
if ( ! V_123 )
return - 1 ;
if ( V_123 -> V_268 >= 0 && V_123 -> V_268 < V_456 ) {
#ifdef F_235
char V_137 [ 10 ] ;
const char * V_460 = NULL ;
if ( V_457 )
V_460 = V_457 [ V_123 -> V_268 ] ;
if ( ! V_460 ) {
sprintf ( V_137 , L_90 , V_123 -> V_268 ) ;
V_460 = V_137 ;
}
F_89 ( V_459 L_91
L_92 ,
V_460 , V_123 -> V_461 , V_123 -> V_298 ,
( V_123 -> V_133 ? V_123 -> V_133 : L_93 ) ) ;
#endif
return V_123 -> V_268 ;
}
return - 1 ;
}
int F_236 ( struct V_6 * V_7 ,
int V_456 , const char * const * V_457 ,
const struct V_458 * V_123 )
{
const struct V_458 * V_213 ;
for ( V_213 = V_123 ; V_213 -> V_461 ; V_213 ++ ) {
unsigned long V_462 = ( V_213 -> V_298 ) | ( V_213 -> V_461 << 16 ) ;
if ( V_462 == V_7 -> V_191 )
break;
}
if ( ! V_213 -> V_461 )
return - 1 ;
V_123 = V_213 ;
if ( V_123 -> V_268 >= 0 && V_123 -> V_268 < V_456 ) {
#ifdef F_235
char V_137 [ 10 ] ;
const char * V_460 = NULL ;
if ( V_457 )
V_460 = V_457 [ V_123 -> V_268 ] ;
if ( ! V_460 ) {
sprintf ( V_137 , L_90 , V_123 -> V_268 ) ;
V_460 = V_137 ;
}
F_89 ( V_459 L_91
L_92 ,
V_460 , V_123 -> V_461 , V_123 -> V_298 ,
( V_123 -> V_133 ? V_123 -> V_133 : L_93 ) ) ;
#endif
return V_123 -> V_268 ;
}
return - 1 ;
}
int F_237 ( struct V_6 * V_7 ,
const struct V_361 * V_463 )
{
int V_30 ;
for (; V_463 -> V_133 ; V_463 ++ ) {
struct V_261 * V_295 ;
int V_24 = 0 , V_220 = 0 ;
if ( V_463 -> V_293 == - 1 )
continue;
for (; ; ) {
V_295 = F_185 ( V_463 , V_7 ) ;
if ( ! V_295 )
return - V_76 ;
if ( V_24 > 0 )
V_295 -> V_126 . V_101 = V_24 ;
if ( V_220 > 0 )
V_295 -> V_126 . V_243 = V_220 ;
V_30 = F_142 ( V_7 , 0 , V_295 ) ;
if ( ! V_30 )
break;
if ( ! V_24 && V_7 -> V_24 )
V_24 = V_7 -> V_24 ;
else if ( ! V_220 && ! V_463 -> V_243 ) {
V_220 = F_141 ( V_7 ,
V_463 -> V_133 ) ;
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
F_39 ( V_91 , struct V_6 , V_171 . V_91 ) ;
struct V_28 * V_29 = V_7 -> V_29 ;
if ( ! V_7 -> V_389 || V_7 -> V_464 ) {
V_7 -> V_390 = 0 ;
return;
}
F_206 ( V_7 ) ;
if ( V_29 -> V_33 . V_465 )
V_29 -> V_33 . V_465 ( V_29 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
V_7 -> V_464 ++ ;
V_7 -> V_389 = 1 ;
V_7 -> V_391 = V_383 ;
}
void F_207 ( struct V_6 * V_7 )
{
unsigned long V_466 = V_383 - V_7 -> V_391 ;
if ( V_7 -> V_389 )
V_7 -> V_467 += V_466 ;
else
V_7 -> V_468 += V_466 ;
V_7 -> V_391 += V_466 ;
}
void F_15 ( struct V_6 * V_7 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
V_7 -> V_464 ++ ;
if ( V_7 -> V_389 || V_7 -> V_390 )
return;
F_207 ( V_7 ) ;
V_7 -> V_389 = 1 ;
V_7 -> V_391 = V_383 ;
if ( V_29 -> V_33 . V_465 )
V_29 -> V_33 . V_465 ( V_29 ) ;
F_208 ( V_7 ) ;
F_83 ( & V_7 -> V_171 ) ;
V_7 -> V_390 = 0 ;
}
void F_16 ( struct V_6 * V_7 )
{
-- V_7 -> V_464 ;
if ( ! V_7 -> V_389 || V_7 -> V_464 || V_7 -> V_390 )
return;
if ( V_116 ( V_7 ) ) {
V_7 -> V_390 = 1 ;
F_238 ( V_7 -> V_29 -> V_90 , & V_7 -> V_171 ,
F_203 ( V_116 ( V_7 ) * 1000 ) ) ;
}
}
int F_239 ( struct V_6 * V_7 ,
struct V_469 * V_470 ,
T_2 V_19 )
{
const struct V_471 * V_49 ;
int V_242 , V_472 ;
if ( ! V_470 -> V_473 )
return 0 ;
for ( V_49 = V_470 -> V_473 ; V_49 -> V_19 ; V_49 ++ ) {
if ( V_49 -> V_19 == V_19 )
break;
}
if ( ! V_49 -> V_19 )
return 0 ;
for ( V_49 = V_470 -> V_473 ; V_49 -> V_19 ; V_49 ++ ) {
for ( V_242 = 0 ; V_242 < 2 ; V_242 ++ ) {
V_472 = F_118 ( V_7 , V_49 -> V_19 , V_242 , V_49 -> V_232 ,
V_49 -> V_220 ) ;
if ( ! ( V_472 & V_322 ) && V_472 > 0 ) {
if ( ! V_470 -> V_389 ) {
V_470 -> V_389 = 1 ;
F_15 ( V_7 ) ;
}
return 1 ;
}
}
}
if ( V_470 -> V_389 ) {
V_470 -> V_389 = 0 ;
F_16 ( V_7 ) ;
}
return 0 ;
}
int F_240 ( struct V_6 * V_7 ,
struct V_263 * V_264 ,
const struct V_474 * V_475 ,
int V_476 )
{
V_264 -> type = V_477 ;
V_264 -> V_267 = 1 ;
V_264 -> V_268 . V_478 . V_303 = V_476 ;
if ( V_264 -> V_268 . V_478 . V_297 >= V_476 )
V_264 -> V_268 . V_478 . V_297 = V_476 - 1 ;
sprintf ( V_264 -> V_268 . V_478 . V_133 , L_94 ,
V_475 [ V_264 -> V_268 . V_478 . V_297 ] . V_396 ) ;
return 0 ;
}
int F_241 ( struct V_6 * V_7 ,
struct V_273 * V_274 ,
const struct V_474 * V_475 ,
int V_476 ,
int V_479 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_476 ; V_12 ++ ) {
if ( V_479 == V_475 [ V_12 ] . V_396 ) {
V_274 -> V_268 . V_478 . V_297 [ 0 ] = V_12 ;
break;
}
}
return 0 ;
}
int F_242 ( struct V_6 * V_7 ,
struct V_273 * V_274 ,
const struct V_474 * V_475 ,
int V_476 ,
int * V_480 )
{
unsigned int V_481 ;
V_481 = V_274 -> V_268 . V_478 . V_297 [ 0 ] ;
if ( V_481 >= V_476 )
return - V_54 ;
if ( * V_480 == V_475 [ V_481 ] . V_396 )
return 0 ;
* V_480 = V_475 [ V_481 ] . V_396 ;
if ( V_475 [ V_481 ] . V_482 )
F_201 ( V_7 , V_475 [ V_481 ] . V_482 ) ;
return 1 ;
}
int F_243 ( const struct V_483 * V_484 ,
struct V_263 * V_264 )
{
unsigned int V_243 ;
V_264 -> type = V_477 ;
V_264 -> V_267 = 1 ;
V_264 -> V_268 . V_478 . V_303 = V_484 -> V_485 ;
if ( ! V_484 -> V_485 )
return 0 ;
V_243 = V_264 -> V_268 . V_478 . V_297 ;
if ( V_243 >= V_484 -> V_485 )
V_243 = V_484 -> V_485 - 1 ;
strcpy ( V_264 -> V_268 . V_478 . V_133 , V_484 -> V_303 [ V_243 ] . V_486 ) ;
return 0 ;
}
int F_244 ( struct V_6 * V_7 ,
const struct V_483 * V_484 ,
struct V_273 * V_274 ,
T_2 V_19 ,
unsigned int * V_487 )
{
unsigned int V_220 ;
if ( ! V_484 -> V_485 )
return 0 ;
V_220 = V_274 -> V_268 . V_478 . V_297 [ 0 ] ;
if ( V_220 >= V_484 -> V_485 )
V_220 = V_484 -> V_485 - 1 ;
if ( * V_487 == V_220 )
return 0 ;
F_178 ( V_7 , V_19 , 0 , V_488 ,
V_484 -> V_303 [ V_220 ] . V_243 ) ;
* V_487 = V_220 ;
return 1 ;
}
static void F_245 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_199 , unsigned int V_201 )
{
struct V_187 * V_342 = F_186 ( V_7 , V_19 ) ;
if ( V_7 -> V_317 && ( V_342 -> V_356 & V_357 ) )
F_179 ( V_7 , V_19 ,
V_342 -> V_356 & ~ V_357 & 0xff ,
- 1 ) ;
F_96 ( V_7 , V_19 , V_199 , 0 , V_201 ) ;
if ( V_7 -> V_316 ) {
const T_2 * V_351 ;
for ( V_351 = V_7 -> V_316 ; * V_351 ; V_351 ++ )
F_96 ( V_7 , * V_351 , V_199 , 0 ,
V_201 ) ;
}
if ( V_7 -> V_317 && ( V_342 -> V_356 & V_357 ) )
F_179 ( V_7 , V_19 ,
V_342 -> V_356 & 0xff , - 1 ) ;
}
static void F_246 ( struct V_6 * V_7 , T_2 V_19 )
{
F_224 ( V_7 , V_19 ) ;
if ( V_7 -> V_316 ) {
const T_2 * V_351 ;
for ( V_351 = V_7 -> V_316 ; * V_351 ; V_351 ++ )
F_224 ( V_7 , * V_351 ) ;
}
}
void F_247 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
if ( ! V_29 )
return;
F_51 (codec, &bus->codec_list, list) {
if ( F_248 ( V_7 ) &&
V_7 -> V_96 . V_489 )
V_7 -> V_96 . V_489 ( V_7 ) ;
}
}
int F_249 ( struct V_6 * V_7 ,
struct V_365 * V_366 )
{
F_2 ( & V_7 -> V_182 ) ;
if ( V_366 -> V_490 == V_491 )
F_246 ( V_7 , V_366 -> V_368 ) ;
V_366 -> V_490 = V_492 ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_250 ( struct V_6 * V_7 ,
struct V_365 * V_366 ,
unsigned int V_199 ,
unsigned int V_201 ,
struct V_437 * V_438 )
{
F_2 ( & V_7 -> V_182 ) ;
F_245 ( V_7 , V_366 -> V_368 , V_199 , V_201 ) ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_251 ( struct V_6 * V_7 ,
struct V_365 * V_366 )
{
F_2 ( & V_7 -> V_182 ) ;
F_246 ( V_7 , V_366 -> V_368 ) ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_252 ( struct V_6 * V_7 ,
struct V_365 * V_366 )
{
F_2 ( & V_7 -> V_182 ) ;
V_366 -> V_490 = 0 ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_253 ( struct V_6 * V_7 ,
struct V_365 * V_366 ,
struct V_437 * V_438 ,
struct V_435 * V_436 )
{
struct V_493 * V_494 = V_438 -> V_494 ;
V_494 -> V_495 . V_496 = V_366 -> V_479 ;
if ( V_366 -> V_368 ) {
if ( ! V_366 -> V_497 ) {
V_366 -> V_497 = V_436 -> V_415 ;
V_366 -> V_498 = V_436 -> V_418 ;
V_366 -> V_499 = V_436 -> V_397 ;
} else {
V_494 -> V_495 . V_415 = V_366 -> V_497 ;
V_494 -> V_495 . V_418 = V_366 -> V_498 ;
V_436 -> V_397 = V_366 -> V_499 ;
}
if ( ! V_366 -> V_500 ) {
F_219 ( V_7 , V_366 -> V_368 ,
& V_366 -> V_500 ,
& V_366 -> V_501 ,
& V_366 -> V_502 ) ;
}
F_2 ( & V_7 -> V_182 ) ;
if ( V_366 -> V_367 ) {
if ( ( V_494 -> V_495 . V_415 & V_366 -> V_500 ) &&
( V_494 -> V_495 . V_418 & V_366 -> V_501 ) ) {
V_494 -> V_495 . V_415 &= V_366 -> V_500 ;
V_494 -> V_495 . V_418 &= V_366 -> V_501 ;
if ( V_366 -> V_502 < V_436 -> V_397 )
V_436 -> V_397 = V_366 -> V_502 ;
} else {
V_366 -> V_367 = 0 ;
}
}
F_4 ( & V_7 -> V_182 ) ;
}
return F_254 ( V_438 -> V_494 , 0 ,
V_503 , 2 ) ;
}
int F_255 ( struct V_6 * V_7 ,
struct V_365 * V_366 ,
unsigned int V_199 ,
unsigned int V_201 ,
struct V_437 * V_438 )
{
const T_2 * V_173 = V_366 -> V_504 ;
int V_265 = V_438 -> V_494 -> V_396 ;
struct V_187 * V_342 =
F_186 ( V_7 , V_366 -> V_368 ) ;
int V_12 ;
F_2 ( & V_7 -> V_182 ) ;
if ( V_366 -> V_368 && V_366 -> V_367 &&
V_366 -> V_490 != V_492 ) {
if ( V_265 == 2 &&
F_220 ( V_7 , V_366 -> V_368 ,
V_201 ) &&
! ( V_342 -> V_334 & V_336 ) ) {
V_366 -> V_490 = V_491 ;
F_245 ( V_7 , V_366 -> V_368 ,
V_199 , V_201 ) ;
} else {
V_366 -> V_490 = 0 ;
F_246 ( V_7 , V_366 -> V_368 ) ;
}
}
F_4 ( & V_7 -> V_182 ) ;
F_96 ( V_7 , V_173 [ V_505 ] , V_199 ,
0 , V_201 ) ;
if ( ! V_366 -> V_506 &&
V_366 -> V_507 && V_366 -> V_507 != V_173 [ V_505 ] )
F_96 ( V_7 , V_366 -> V_507 , V_199 ,
0 , V_201 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_366 -> V_508 ) ; V_12 ++ )
if ( ! V_366 -> V_506 && V_366 -> V_508 [ V_12 ] )
F_96 ( V_7 ,
V_366 -> V_508 [ V_12 ] ,
V_199 , 0 , V_201 ) ;
for ( V_12 = 1 ; V_12 < V_366 -> V_509 ; V_12 ++ ) {
if ( V_265 >= ( V_12 + 1 ) * 2 )
F_96 ( V_7 , V_173 [ V_12 ] , V_199 ,
V_12 * 2 , V_201 ) ;
else if ( ! V_366 -> V_506 )
F_96 ( V_7 , V_173 [ V_12 ] , V_199 ,
0 , V_201 ) ;
}
return 0 ;
}
int F_256 ( struct V_6 * V_7 ,
struct V_365 * V_366 )
{
const T_2 * V_173 = V_366 -> V_504 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_366 -> V_509 ; V_12 ++ )
F_224 ( V_7 , V_173 [ V_12 ] ) ;
if ( V_366 -> V_507 )
F_224 ( V_7 , V_366 -> V_507 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_366 -> V_508 ) ; V_12 ++ )
if ( V_366 -> V_508 [ V_12 ] )
F_224 ( V_7 ,
V_366 -> V_508 [ V_12 ] ) ;
F_2 ( & V_7 -> V_182 ) ;
if ( V_366 -> V_368 && V_366 -> V_490 == V_491 ) {
F_246 ( V_7 , V_366 -> V_368 ) ;
V_366 -> V_490 = 0 ;
}
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
static int F_257 ( T_2 V_19 , const T_2 * V_4 )
{
for (; * V_4 ; V_4 ++ )
if ( * V_4 == V_19 )
return 1 ;
return 0 ;
}
static void F_258 ( T_2 * V_510 , short * V_511 ,
int V_512 )
{
int V_12 , V_513 ;
short V_41 ;
T_2 V_19 ;
for ( V_12 = 0 ; V_12 < V_512 ; V_12 ++ ) {
for ( V_513 = V_12 + 1 ; V_513 < V_512 ; V_513 ++ ) {
if ( V_511 [ V_12 ] > V_511 [ V_513 ] ) {
V_41 = V_511 [ V_12 ] ;
V_511 [ V_12 ] = V_511 [ V_513 ] ;
V_511 [ V_513 ] = V_41 ;
V_19 = V_510 [ V_12 ] ;
V_510 [ V_12 ] = V_510 [ V_513 ] ;
V_510 [ V_513 ] = V_19 ;
}
}
}
}
static void F_259 ( struct V_514 * V_8 , T_2 V_19 ,
int type )
{
if ( V_8 -> V_515 < V_516 ) {
V_8 -> V_517 [ V_8 -> V_515 ] . V_157 = V_19 ;
V_8 -> V_517 [ V_8 -> V_515 ] . type = type ;
V_8 -> V_515 ++ ;
}
}
static void F_260 ( struct V_514 * V_8 )
{
int V_12 , V_513 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_515 ; V_12 ++ ) {
for ( V_513 = V_12 + 1 ; V_513 < V_8 -> V_515 ; V_513 ++ ) {
if ( V_8 -> V_517 [ V_12 ] . type > V_8 -> V_517 [ V_513 ] . type ) {
struct V_518 V_137 ;
V_137 = V_8 -> V_517 [ V_12 ] ;
V_8 -> V_517 [ V_12 ] = V_8 -> V_517 [ V_513 ] ;
V_8 -> V_517 [ V_513 ] = V_137 ;
}
}
}
}
int F_261 ( struct V_6 * V_7 ,
struct V_514 * V_8 ,
const T_2 * V_519 )
{
T_2 V_19 , V_520 ;
short V_41 , V_521 , V_522 ;
short V_523 [ F_9 ( V_8 -> V_524 ) ] ;
short V_525 [ F_9 ( V_8 -> V_526 ) ] ;
short V_527 [ F_9 ( V_8 -> V_528 ) ] ;
int V_12 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
memset ( V_523 , 0 , sizeof( V_523 ) ) ;
memset ( V_525 , 0 , sizeof( V_525 ) ) ;
memset ( V_527 , 0 , sizeof( V_527 ) ) ;
V_521 = V_522 = 0 ;
V_520 = V_7 -> V_154 + V_7 -> V_153 ;
for ( V_19 = V_7 -> V_154 ; V_19 < V_520 ; V_19 ++ ) {
unsigned int V_529 = F_31 ( V_7 , V_19 ) ;
unsigned int V_158 = F_32 ( V_529 ) ;
unsigned int V_530 ;
short V_531 , V_532 , V_79 , V_454 ;
if ( V_158 != V_82 )
continue;
if ( V_519 && F_257 ( V_19 , V_519 ) )
continue;
V_530 = F_73 ( V_7 , V_19 ) ;
V_79 = F_262 ( V_530 ) ;
if ( V_79 == V_533 )
continue;
V_532 = F_263 ( V_530 ) ;
V_454 = F_264 ( V_530 ) ;
if ( V_454 == V_534 ) {
if ( V_79 == V_535 )
V_454 = V_536 ;
}
switch ( V_454 ) {
case V_534 :
V_41 = F_265 ( V_530 ) ;
V_531 = F_266 ( V_530 ) ;
if ( ! ( V_529 & V_537 ) )
if ( ! V_8 -> V_538 )
V_8 -> V_538 = V_19 ;
if ( ! V_531 )
continue;
if ( ! V_521 )
V_521 = V_531 ;
else if ( V_521 != V_531 )
continue;
if ( V_8 -> V_539 >= F_9 ( V_8 -> V_524 ) )
continue;
V_8 -> V_524 [ V_8 -> V_539 ] = V_19 ;
V_523 [ V_8 -> V_539 ] = V_41 ;
V_8 -> V_539 ++ ;
break;
case V_536 :
V_41 = F_265 ( V_530 ) ;
V_531 = F_266 ( V_530 ) ;
if ( ! V_531 )
continue;
if ( ! V_522 )
V_522 = V_531 ;
else if ( V_522 != V_531 )
continue;
if ( V_8 -> V_540 >= F_9 ( V_8 -> V_526 ) )
continue;
V_8 -> V_526 [ V_8 -> V_540 ] = V_19 ;
V_525 [ V_8 -> V_540 ] = V_41 ;
V_8 -> V_540 ++ ;
break;
case V_541 :
V_41 = F_265 ( V_530 ) ;
V_531 = F_266 ( V_530 ) ;
if ( V_8 -> V_542 >= F_9 ( V_8 -> V_528 ) )
continue;
V_8 -> V_528 [ V_8 -> V_542 ] = V_19 ;
V_527 [ V_8 -> V_542 ] = ( V_531 << 4 ) | V_41 ;
V_8 -> V_542 ++ ;
break;
case V_543 :
F_259 ( V_8 , V_19 , V_544 ) ;
break;
case V_545 :
F_259 ( V_8 , V_19 , V_546 ) ;
break;
case V_547 :
F_259 ( V_8 , V_19 , V_548 ) ;
break;
case V_549 :
F_259 ( V_8 , V_19 , V_550 ) ;
break;
case V_551 :
case V_552 :
if ( V_8 -> V_553 >= F_9 ( V_8 -> V_554 ) )
continue;
V_8 -> V_554 [ V_8 -> V_553 ] = V_19 ;
V_8 -> V_555 [ V_8 -> V_553 ] =
( V_532 == V_556 ) ?
V_447 : V_446 ;
V_8 -> V_553 ++ ;
break;
case V_557 :
case V_558 :
V_8 -> V_559 = V_19 ;
if ( V_532 == V_556 )
V_8 -> V_560 = V_447 ;
else
V_8 -> V_560 = V_446 ;
break;
}
}
if ( ! V_8 -> V_539 && V_8 -> V_542 > 1 ) {
int V_12 = 0 ;
while ( V_12 < V_8 -> V_542 ) {
if ( ( V_527 [ V_12 ] & 0x0f ) == 0x0f ) {
V_12 ++ ;
continue;
}
V_8 -> V_524 [ V_8 -> V_539 ] = V_8 -> V_528 [ V_12 ] ;
V_523 [ V_8 -> V_539 ] = V_527 [ V_12 ] ;
V_8 -> V_539 ++ ;
V_8 -> V_542 -- ;
memmove ( V_8 -> V_528 + V_12 , V_8 -> V_528 + V_12 + 1 ,
sizeof( V_8 -> V_528 [ 0 ] ) * ( V_8 -> V_542 - V_12 ) ) ;
memmove ( V_527 + V_12 , V_527 + V_12 + 1 ,
sizeof( V_527 [ 0 ] ) * ( V_8 -> V_542 - V_12 ) ) ;
}
memset ( V_8 -> V_528 + V_8 -> V_542 , 0 ,
sizeof( T_2 ) * ( V_561 - V_8 -> V_542 ) ) ;
if ( ! V_8 -> V_542 )
V_8 -> V_562 = V_563 ;
}
F_258 ( V_8 -> V_524 , V_523 ,
V_8 -> V_539 ) ;
F_258 ( V_8 -> V_526 , V_525 ,
V_8 -> V_540 ) ;
F_258 ( V_8 -> V_528 , V_527 ,
V_8 -> V_542 ) ;
if ( ! V_8 -> V_539 ) {
if ( V_8 -> V_540 ) {
V_8 -> V_539 = V_8 -> V_540 ;
memcpy ( V_8 -> V_524 , V_8 -> V_526 ,
sizeof( V_8 -> V_526 ) ) ;
V_8 -> V_540 = 0 ;
memset ( V_8 -> V_526 , 0 , sizeof( V_8 -> V_526 ) ) ;
V_8 -> V_562 = V_564 ;
} else if ( V_8 -> V_542 ) {
V_8 -> V_539 = V_8 -> V_542 ;
memcpy ( V_8 -> V_524 , V_8 -> V_528 ,
sizeof( V_8 -> V_528 ) ) ;
V_8 -> V_542 = 0 ;
memset ( V_8 -> V_528 , 0 , sizeof( V_8 -> V_528 ) ) ;
V_8 -> V_562 = V_563 ;
}
}
switch ( V_8 -> V_539 ) {
case 3 :
case 4 :
V_19 = V_8 -> V_524 [ 1 ] ;
V_8 -> V_524 [ 1 ] = V_8 -> V_524 [ 2 ] ;
V_8 -> V_524 [ 2 ] = V_19 ;
break;
}
F_260 ( V_8 ) ;
F_17 ( L_95 ,
V_8 -> V_539 , V_8 -> V_524 [ 0 ] , V_8 -> V_524 [ 1 ] ,
V_8 -> V_524 [ 2 ] , V_8 -> V_524 [ 3 ] ,
V_8 -> V_524 [ 4 ] ,
V_8 -> V_562 == V_563 ? L_96 :
( V_8 -> V_562 == V_564 ?
L_97 : L_98 ) ) ;
F_17 ( L_99 ,
V_8 -> V_540 , V_8 -> V_526 [ 0 ] ,
V_8 -> V_526 [ 1 ] , V_8 -> V_526 [ 2 ] ,
V_8 -> V_526 [ 3 ] , V_8 -> V_526 [ 4 ] ) ;
F_17 ( L_100 ,
V_8 -> V_542 , V_8 -> V_528 [ 0 ] ,
V_8 -> V_528 [ 1 ] , V_8 -> V_528 [ 2 ] ,
V_8 -> V_528 [ 3 ] , V_8 -> V_528 [ 4 ] ) ;
F_17 ( L_101 , V_8 -> V_538 ) ;
if ( V_8 -> V_553 )
F_17 ( L_102 ,
V_8 -> V_554 [ 0 ] , V_8 -> V_554 [ 1 ] ) ;
F_17 ( L_103 ) ;
for ( V_12 = 0 ; V_12 < V_8 -> V_515 ; V_12 ++ ) {
F_17 ( L_104 ,
F_267 ( V_7 , V_8 , V_12 ) ,
V_8 -> V_517 [ V_12 ] . V_157 ) ;
}
F_17 ( L_105 ) ;
if ( V_8 -> V_559 )
F_17 ( L_106 , V_8 -> V_559 ) ;
return 0 ;
}
int F_268 ( unsigned int V_530 )
{
unsigned int V_532 = F_263 ( V_530 ) ;
unsigned int V_79 = F_262 ( V_530 ) ;
if ( V_79 == V_533 )
return V_565 ;
if ( V_79 == V_535 || V_79 == V_566 )
return V_567 ;
if ( ( V_532 & 0x30 ) == V_568 )
return V_567 ;
if ( ( V_532 & 0x30 ) == V_569 )
return V_570 ;
if ( V_532 == V_571 )
return V_572 ;
if ( V_532 == V_573 )
return V_574 ;
return V_575 ;
}
const char * F_269 ( struct V_6 * V_7 , T_2 V_157 ,
int V_576 )
{
unsigned int V_530 ;
static const char * const V_577 [] = {
L_107 , L_108 , L_30 , L_109 , L_110 ,
} ;
int V_578 ;
V_530 = F_73 ( V_7 , V_157 ) ;
switch ( F_264 ( V_530 ) ) {
case V_543 :
if ( ! V_576 )
return L_30 ;
V_578 = F_268 ( V_530 ) ;
if ( ! V_578 )
return L_111 ;
return V_577 [ V_578 - 1 ] ;
case V_545 :
if ( ! V_576 )
return L_112 ;
V_578 = F_268 ( V_530 ) ;
if ( ! V_578 )
return L_111 ;
if ( V_578 == V_570 )
return L_113 ;
return L_112 ;
case V_549 :
return L_29 ;
case V_547 :
return L_23 ;
case V_557 :
return L_32 ;
case V_558 :
return L_114 ;
default:
return L_115 ;
}
}
static int F_270 ( struct V_6 * V_7 ,
const struct V_514 * V_8 ,
int V_579 )
{
unsigned int V_580 ;
int V_12 , V_578 , V_581 ;
V_580 = F_73 ( V_7 , V_8 -> V_517 [ V_579 ] . V_157 ) ;
V_578 = F_268 ( V_580 ) ;
if ( V_578 <= V_575 )
return 1 ;
V_578 = 0 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_515 ; V_12 ++ ) {
V_580 = F_73 ( V_7 , V_8 -> V_517 [ V_12 ] . V_157 ) ;
V_581 = F_268 ( V_580 ) ;
if ( V_581 >= V_575 ) {
if ( V_578 && V_578 != V_581 )
return 1 ;
V_578 = V_581 ;
}
}
return 0 ;
}
const char * F_267 ( struct V_6 * V_7 ,
const struct V_514 * V_8 ,
int V_579 )
{
int type = V_8 -> V_517 [ V_579 ] . type ;
int V_582 = 0 ;
if ( ( V_579 > 0 && V_8 -> V_517 [ V_579 - 1 ] . type == type ) ||
( V_579 < V_8 -> V_515 - 1 && V_8 -> V_517 [ V_579 + 1 ] . type == type ) )
V_582 = 1 ;
if ( V_582 && type == V_544 )
V_582 &= F_270 ( V_7 , V_8 , V_579 ) ;
return F_269 ( V_7 , V_8 -> V_517 [ V_579 ] . V_157 ,
V_582 ) ;
}
int F_271 ( struct V_483 * V_484 , const char * V_486 ,
int V_243 , int * V_583 )
{
int V_12 , V_584 = 0 ;
if ( V_484 -> V_485 >= V_80 ) {
F_17 ( V_25 L_116 ) ;
return - V_54 ;
}
for ( V_12 = 0 ; V_12 < V_484 -> V_485 ; V_12 ++ ) {
if ( ! strncmp ( V_486 , V_484 -> V_303 [ V_12 ] . V_486 , strlen ( V_486 ) ) )
V_584 ++ ;
}
if ( V_583 )
* V_583 = V_584 ;
if ( V_584 > 0 )
snprintf ( V_484 -> V_303 [ V_484 -> V_485 ] . V_486 ,
sizeof( V_484 -> V_303 [ V_484 -> V_485 ] . V_486 ) ,
L_117 , V_486 , V_584 ) ;
else
F_272 ( V_484 -> V_303 [ V_484 -> V_485 ] . V_486 , V_486 ,
sizeof( V_484 -> V_303 [ V_484 -> V_485 ] . V_486 ) ) ;
V_484 -> V_303 [ V_484 -> V_485 ] . V_243 = V_243 ;
V_484 -> V_485 ++ ;
return 0 ;
}
int F_273 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_51 (codec, &bus->codec_list, list) {
if ( F_248 ( V_7 ) )
F_206 ( V_7 ) ;
if ( V_7 -> V_96 . V_585 )
V_7 -> V_96 . V_585 ( V_7 ) ;
}
return 0 ;
}
int F_274 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_51 (codec, &bus->codec_list, list) {
if ( V_7 -> V_96 . V_586 )
V_7 -> V_96 . V_586 ( V_7 ) ;
if ( F_275 ( V_7 ) )
F_208 ( V_7 ) ;
}
return 0 ;
}
void * F_34 ( struct V_45 * V_46 )
{
if ( V_46 -> V_48 >= V_46 -> V_587 ) {
int V_588 = V_46 -> V_587 + V_46 -> V_589 ;
int V_278 = ( V_588 + 1 ) * V_46 -> V_590 ;
int V_591 = V_46 -> V_587 * V_46 -> V_590 ;
void * V_592 ;
if ( F_26 ( V_588 >= 4096 ) )
return NULL ;
V_592 = F_276 ( V_46 -> V_4 , V_278 , V_98 ) ;
if ( ! V_592 )
return NULL ;
memset ( V_592 + V_591 , 0 , V_278 - V_591 ) ;
V_46 -> V_4 = V_592 ;
V_46 -> V_587 = V_588 ;
}
return F_24 ( V_46 , V_46 -> V_48 ++ ) ;
}
void F_80 ( struct V_45 * V_46 )
{
F_45 ( V_46 -> V_4 ) ;
V_46 -> V_48 = 0 ;
V_46 -> V_587 = 0 ;
V_46 -> V_4 = NULL ;
}
void F_277 ( int V_305 , char * V_218 , int V_593 )
{
static unsigned int V_415 [] = {
8000 , 11025 , 16000 , 22050 , 32000 , 44100 , 48000 , 88200 ,
96000 , 176400 , 192000 , 384000
} ;
int V_12 , V_513 ;
for ( V_12 = 0 , V_513 = 0 ; V_12 < F_9 ( V_415 ) ; V_12 ++ )
if ( V_305 & ( 1 << V_12 ) )
V_513 += snprintf ( V_218 + V_513 , V_593 - V_513 , L_118 , V_415 [ V_12 ] ) ;
V_218 [ V_513 ] = '\0' ;
}
void F_278 ( int V_305 , char * V_218 , int V_593 )
{
static unsigned int V_594 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_12 , V_513 ;
for ( V_12 = 0 , V_513 = 0 ; V_12 < F_9 ( V_594 ) ; V_12 ++ )
if ( V_305 & ( V_421 << V_12 ) )
V_513 += snprintf ( V_218 + V_513 , V_593 - V_513 , L_118 , V_594 [ V_12 ] ) ;
V_218 [ V_513 ] = '\0' ;
}
static const char * F_279 ( struct V_6 * V_7 , T_2 V_19 ,
int type )
{
switch ( type ) {
case V_595 :
return L_119 ;
case V_596 :
return L_30 ;
case V_597 :
return L_120 ;
case V_598 :
return L_121 ;
case V_599 :
return L_122 ;
default:
return L_115 ;
}
}
static void F_280 ( struct V_600 * V_601 )
{
struct V_602 * V_603 = V_601 -> V_113 ;
V_603 -> V_19 = 0 ;
V_603 -> V_601 = NULL ;
}
int F_281 ( struct V_6 * V_7 , T_2 V_19 , int type ,
const char * V_133 )
{
struct V_602 * V_601 ;
int V_30 ;
F_87 ( & V_7 -> V_603 , sizeof( * V_601 ) , 32 ) ;
V_601 = F_34 ( & V_7 -> V_603 ) ;
if ( ! V_601 )
return - V_76 ;
V_601 -> V_19 = V_19 ;
V_601 -> type = type ;
if ( ! V_133 )
V_133 = F_279 ( V_7 , V_19 , type ) ;
V_30 = F_282 ( V_7 -> V_29 -> V_105 , V_133 , type , & V_601 -> V_601 ) ;
if ( V_30 < 0 ) {
V_601 -> V_19 = 0 ;
return V_30 ;
}
V_601 -> V_601 -> V_113 = V_601 ;
V_601 -> V_601 -> V_99 = F_280 ;
return 0 ;
}
void F_283 ( struct V_6 * V_7 , T_2 V_19 )
{
struct V_602 * V_603 = V_7 -> V_603 . V_4 ;
int V_12 ;
if ( ! V_603 )
return;
for ( V_12 = 0 ; V_12 < V_7 -> V_603 . V_48 ; V_12 ++ , V_603 ++ ) {
unsigned int V_604 ;
unsigned int V_605 ;
int type ;
if ( V_603 -> V_19 != V_19 )
continue;
V_605 = F_114 ( V_7 , V_19 ) ;
type = V_603 -> type ;
if ( type == ( V_595 | V_597 ) ) {
V_604 = F_18 ( V_7 , V_19 , 0 ,
V_162 , 0 ) ;
type = ( V_604 & V_606 ) ?
V_595 : V_597 ;
}
F_284 ( V_603 -> V_601 , V_605 ? type : 0 ) ;
}
}
void F_285 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_29 -> V_103 && V_7 -> V_603 . V_4 ) {
struct V_602 * V_603 = V_7 -> V_603 . V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_603 . V_48 ; V_12 ++ , V_603 ++ ) {
if ( V_603 -> V_601 )
F_154 ( V_7 -> V_29 -> V_105 , V_603 -> V_601 ) ;
}
}
F_80 ( & V_7 -> V_603 ) ;
}
