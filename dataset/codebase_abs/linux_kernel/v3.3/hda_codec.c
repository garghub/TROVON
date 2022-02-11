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
F_35 ( F_34 ( V_135 , V_49 -> V_19 ) ) == type )
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
static unsigned int F_118 ( struct V_6 * V_7 ,
struct V_184 * V_222 , T_2 V_19 ,
int V_235 , int V_224 , int V_236 )
{
T_1 V_23 , V_22 ;
if ( V_222 -> V_225 . V_23 & F_119 ( V_235 ) )
return V_222 -> V_237 [ V_235 ] ;
V_22 = V_235 ? V_238 : V_239 ;
V_22 |= V_224 == V_229 ? V_240 : V_241 ;
V_22 |= V_236 ;
V_23 = F_21 ( V_7 , V_19 , 0 ,
V_242 , V_22 ) ;
V_222 -> V_237 [ V_235 ] = V_23 & 0xff ;
V_222 -> V_225 . V_23 |= F_119 ( V_235 ) ;
return V_222 -> V_237 [ V_235 ] ;
}
static void F_120 ( struct V_6 * V_7 , struct V_184 * V_222 ,
T_2 V_19 , int V_235 , int V_224 , int V_236 ,
int V_23 )
{
T_1 V_22 ;
V_22 = V_235 ? V_243 : V_244 ;
V_22 |= V_224 == V_229 ? V_245 : V_246 ;
V_22 |= V_236 << V_247 ;
if ( ( V_23 & V_248 ) && ! ( V_222 -> V_228 & V_249 ) &&
( V_222 -> V_228 & V_250 ) )
;
else
V_22 |= V_23 ;
F_22 ( V_7 , V_19 , 0 , V_251 , V_22 ) ;
V_222 -> V_237 [ V_235 ] = V_23 ;
}
int F_121 ( struct V_6 * V_7 , T_2 V_19 , int V_235 ,
int V_224 , int V_236 )
{
struct V_184 * V_222 ;
V_222 = F_109 ( V_7 , F_111 ( V_19 , V_224 , V_236 ) ) ;
if ( ! V_222 )
return 0 ;
return F_118 ( V_7 , V_222 , V_19 , V_235 , V_224 , V_236 ) ;
}
int F_122 ( struct V_6 * V_7 , T_2 V_19 , int V_235 ,
int V_224 , int V_220 , int V_61 , int V_23 )
{
struct V_184 * V_222 ;
V_222 = F_109 ( V_7 , F_111 ( V_19 , V_224 , V_220 ) ) ;
if ( ! V_222 )
return 0 ;
if ( F_29 ( V_61 & ~ 0xff ) )
V_61 &= 0xff ;
V_23 &= V_61 ;
V_23 |= F_118 ( V_7 , V_222 , V_19 , V_235 , V_224 , V_220 ) & ~ V_61 ;
if ( V_222 -> V_237 [ V_235 ] == V_23 )
return 0 ;
F_120 ( V_7 , V_222 , V_19 , V_235 , V_224 , V_220 , V_23 ) ;
return 1 ;
}
int F_123 ( struct V_6 * V_7 , T_2 V_19 ,
int V_224 , int V_220 , int V_61 , int V_23 )
{
int V_235 , V_252 = 0 ;
if ( F_29 ( V_61 & ~ 0xff ) )
V_61 &= 0xff ;
for ( V_235 = 0 ; V_235 < 2 ; V_235 ++ )
V_252 |= F_122 ( V_7 , V_19 , V_235 , V_224 ,
V_220 , V_61 , V_23 ) ;
return V_252 ;
}
void F_124 ( struct V_6 * V_7 )
{
struct V_184 * V_253 = V_7 -> V_175 . V_218 . V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_175 . V_218 . V_48 ; V_12 ++ , V_253 ++ ) {
T_1 V_219 = V_253 -> V_225 . V_219 ;
T_2 V_19 ;
unsigned int V_220 , V_232 , V_235 ;
if ( ! V_219 )
continue;
V_19 = V_219 & 0xff ;
V_220 = ( V_219 >> 16 ) & 0xff ;
V_232 = ( V_219 >> 24 ) & 0xff ;
for ( V_235 = 0 ; V_235 < 2 ; V_235 ++ ) {
if ( ! ( V_253 -> V_225 . V_23 & F_119 ( V_235 ) ) )
continue;
F_120 ( V_7 , V_253 , V_19 , V_235 , V_232 , V_220 ,
V_253 -> V_237 [ V_235 ] ) ;
}
}
}
static T_1 F_125 ( struct V_6 * V_7 , T_2 V_19 , int V_232 ,
unsigned int V_254 )
{
T_1 V_233 = F_110 ( V_7 , V_19 , V_232 ) ;
V_233 = ( V_233 & V_255 ) >> V_256 ;
if ( V_254 < V_233 )
V_233 -= V_254 ;
return V_233 ;
}
int F_126 ( struct V_257 * V_258 ,
struct V_259 * V_260 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
T_3 V_19 = F_128 ( V_258 ) ;
T_4 V_261 = F_129 ( V_258 ) ;
int V_232 = F_130 ( V_258 ) ;
unsigned int V_254 = F_131 ( V_258 ) ;
V_260 -> type = V_262 ;
V_260 -> V_263 = V_261 == 3 ? 2 : 1 ;
V_260 -> V_264 . integer . V_265 = 0 ;
V_260 -> V_264 . integer . V_266 = F_125 ( V_7 , V_19 , V_232 , V_254 ) ;
if ( ! V_260 -> V_264 . integer . V_266 ) {
F_13 ( V_73 L_39
L_63 , V_19 ,
V_258 -> V_126 . V_133 ) ;
return - V_54 ;
}
return 0 ;
}
static inline unsigned int
F_132 ( struct V_6 * V_7 , T_2 V_19 ,
int V_235 , int V_232 , int V_220 , unsigned int V_254 )
{
unsigned int V_23 ;
V_23 = F_121 ( V_7 , V_19 , V_235 , V_232 , V_220 ) ;
V_23 &= V_267 ;
if ( V_23 >= V_254 )
V_23 -= V_254 ;
else
V_23 = 0 ;
return V_23 ;
}
static inline int
F_133 ( struct V_6 * V_7 , T_2 V_19 ,
int V_235 , int V_232 , int V_220 , unsigned int V_254 ,
unsigned int V_23 )
{
unsigned int V_268 ;
if ( V_23 > 0 )
V_23 += V_254 ;
V_268 = F_125 ( V_7 , V_19 , V_232 , 0 ) ;
if ( V_23 > V_268 )
V_23 = V_268 ;
return F_122 ( V_7 , V_19 , V_235 , V_232 , V_220 ,
V_267 , V_23 ) ;
}
int F_134 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
T_2 V_19 = F_128 ( V_258 ) ;
int V_261 = F_129 ( V_258 ) ;
int V_232 = F_130 ( V_258 ) ;
int V_220 = F_135 ( V_258 ) ;
unsigned int V_254 = F_131 ( V_258 ) ;
long * V_271 = V_270 -> V_264 . integer . V_264 ;
if ( V_261 & 1 )
* V_271 ++ = F_132 ( V_7 , V_19 , 0 , V_232 , V_220 , V_254 ) ;
if ( V_261 & 2 )
* V_271 = F_132 ( V_7 , V_19 , 1 , V_232 , V_220 , V_254 ) ;
return 0 ;
}
int F_136 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
T_2 V_19 = F_128 ( V_258 ) ;
int V_261 = F_129 ( V_258 ) ;
int V_232 = F_130 ( V_258 ) ;
int V_220 = F_135 ( V_258 ) ;
unsigned int V_254 = F_131 ( V_258 ) ;
long * V_271 = V_270 -> V_264 . integer . V_264 ;
int V_272 = 0 ;
F_15 ( V_7 ) ;
if ( V_261 & 1 ) {
V_272 = F_133 ( V_7 , V_19 , 0 , V_232 , V_220 , V_254 , * V_271 ) ;
V_271 ++ ;
}
if ( V_261 & 2 )
V_272 |= F_133 ( V_7 , V_19 , 1 , V_232 , V_220 , V_254 , * V_271 ) ;
F_18 ( V_7 ) ;
return V_272 ;
}
int F_137 ( struct V_257 * V_258 , int V_273 ,
unsigned int V_274 , unsigned int T_5 * V_275 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
T_2 V_19 = F_128 ( V_258 ) ;
int V_232 = F_130 ( V_258 ) ;
unsigned int V_254 = F_131 ( V_258 ) ;
bool V_276 = F_138 ( V_258 ) ;
T_1 V_233 , V_277 , V_278 ;
if ( V_274 < 4 * sizeof( unsigned int ) )
return - V_76 ;
V_233 = F_110 ( V_7 , V_19 , V_232 ) ;
V_278 = ( V_233 & V_279 ) >> V_280 ;
V_278 = ( V_278 + 1 ) * 25 ;
V_277 = - ( ( V_233 & V_281 ) >> V_282 ) ;
V_277 += V_254 ;
V_277 = ( ( int ) V_277 ) * ( ( int ) V_278 ) ;
if ( V_276 || ( V_233 & V_250 ) )
V_278 |= V_283 ;
if ( F_139 ( V_284 , V_275 ) )
return - V_285 ;
if ( F_139 ( 2 * sizeof( unsigned int ) , V_275 + 1 ) )
return - V_285 ;
if ( F_139 ( V_277 , V_275 + 2 ) )
return - V_285 ;
if ( F_139 ( V_278 , V_275 + 3 ) )
return - V_285 ;
return 0 ;
}
void F_140 ( struct V_6 * V_7 , T_2 V_19 , int V_232 ,
unsigned int * V_286 )
{
T_1 V_233 ;
int V_81 , V_287 ;
V_233 = F_110 ( V_7 , V_19 , V_232 ) ;
V_81 = ( V_233 & V_255 ) >> V_256 ;
V_287 = ( V_233 & V_279 ) >> V_280 ;
V_287 = ( V_287 + 1 ) * 25 ;
V_286 [ 0 ] = V_284 ;
V_286 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_286 [ 2 ] = - V_81 * V_287 ;
V_286 [ 3 ] = V_287 ;
}
static struct V_257 *
F_141 ( struct V_6 * V_7 ,
const char * V_133 , int V_220 )
{
struct V_288 V_126 ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_289 = V_290 ;
V_126 . V_236 = V_220 ;
if ( F_29 ( strlen ( V_133 ) >= sizeof( V_126 . V_133 ) ) )
return NULL ;
strcpy ( V_126 . V_133 , V_133 ) ;
return F_142 ( V_7 -> V_29 -> V_105 , & V_126 ) ;
}
struct V_257 * F_143 ( struct V_6 * V_7 ,
const char * V_133 )
{
return F_141 ( V_7 , V_133 , 0 ) ;
}
static int F_144 ( struct V_6 * V_7 , const char * V_133 )
{
int V_220 ;
for ( V_220 = 0 ; V_220 < 16 ; V_220 ++ ) {
if ( ! F_141 ( V_7 , V_133 , V_220 ) )
return V_220 ;
}
return - V_181 ;
}
int F_145 ( struct V_6 * V_7 , T_2 V_19 ,
struct V_257 * V_291 )
{
int V_30 ;
unsigned short V_292 = 0 ;
struct V_186 * V_293 ;
if ( V_291 -> V_126 . V_294 & V_295 ) {
V_292 |= V_296 ;
if ( V_19 == 0 )
V_19 = F_146 ( V_291 -> V_297 ) ;
}
if ( ( V_291 -> V_126 . V_294 & V_298 ) != 0 && V_19 == 0 )
V_19 = V_291 -> V_126 . V_294 & 0xffff ;
if ( V_291 -> V_126 . V_294 & ( V_298 | V_295 ) )
V_291 -> V_126 . V_294 = 0 ;
V_30 = F_147 ( V_7 -> V_29 -> V_105 , V_291 ) ;
if ( V_30 < 0 )
return V_30 ;
V_293 = F_37 ( & V_7 -> V_172 ) ;
if ( ! V_293 )
return - V_76 ;
V_293 -> V_291 = V_291 ;
V_293 -> V_19 = V_19 ;
V_293 -> V_292 = V_292 ;
return 0 ;
}
int F_148 ( struct V_6 * V_7 , struct V_257 * V_291 ,
unsigned int V_236 , T_2 V_19 )
{
struct V_186 * V_293 ;
if ( V_19 > 0 ) {
V_293 = F_37 ( & V_7 -> V_173 ) ;
if ( ! V_293 )
return - V_76 ;
V_293 -> V_291 = V_291 ;
V_293 -> V_236 = V_236 ;
V_293 -> V_19 = V_19 ;
return 0 ;
}
F_13 ( V_25 L_64 ,
V_291 -> V_126 . V_133 , V_291 -> V_126 . V_236 , V_236 ) ;
return - V_54 ;
}
void F_149 ( struct V_6 * V_7 )
{
int V_12 ;
struct V_186 * V_299 = V_7 -> V_172 . V_4 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_172 . V_48 ; V_12 ++ )
F_150 ( V_7 -> V_29 -> V_105 , V_299 [ V_12 ] . V_291 ) ;
F_84 ( & V_7 -> V_172 ) ;
F_84 ( & V_7 -> V_173 ) ;
}
static int F_151 ( struct V_104 * V_105 )
{
F_152 ( & V_105 -> V_300 ) ;
if ( V_105 -> V_103 ) {
F_153 ( & V_105 -> V_300 ) ;
return - V_54 ;
}
V_105 -> V_103 = 1 ;
F_153 ( & V_105 -> V_300 ) ;
return 0 ;
}
static void F_154 ( struct V_104 * V_105 )
{
F_152 ( & V_105 -> V_300 ) ;
V_105 -> V_103 = 0 ;
F_153 ( & V_105 -> V_300 ) ;
}
int F_155 ( struct V_6 * V_7 )
{
struct V_104 * V_105 = V_7 -> V_29 -> V_105 ;
int V_12 , V_301 ;
if ( F_151 ( V_105 ) < 0 )
return - V_181 ;
if ( ! F_156 ( & V_105 -> V_302 ) ) {
F_154 ( V_105 ) ;
return - V_181 ;
}
for ( V_301 = 0 ; V_301 < V_7 -> V_303 ; V_301 ++ ) {
struct V_304 * V_305 = & V_7 -> V_306 [ V_301 ] ;
if ( ! V_305 -> V_301 )
continue;
if ( V_305 -> V_301 -> V_307 [ 0 ] . V_308 ||
V_305 -> V_301 -> V_307 [ 1 ] . V_308 ) {
F_154 ( V_105 ) ;
return - V_181 ;
}
}
#ifdef F_86
F_87 ( & V_7 -> V_171 ) ;
F_48 ( V_7 -> V_29 -> V_90 ) ;
#endif
F_149 ( V_7 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_303 ; V_12 ++ ) {
if ( V_7 -> V_306 [ V_12 ] . V_301 ) {
F_157 ( V_105 , V_7 -> V_306 [ V_12 ] . V_301 ) ;
F_158 ( V_7 -> V_306 [ V_12 ] . V_101 ,
V_7 -> V_29 -> V_309 ) ;
}
}
if ( V_7 -> V_96 . free )
V_7 -> V_96 . free ( V_7 ) ;
F_159 ( V_7 ) ;
V_7 -> V_310 = NULL ;
V_7 -> V_311 = NULL ;
F_88 ( & V_7 -> V_175 ) ;
F_88 ( & V_7 -> V_176 ) ;
F_90 ( & V_7 -> V_175 , sizeof( struct V_184 ) ) ;
F_90 ( & V_7 -> V_176 , sizeof( struct V_185 ) ) ;
F_84 ( & V_7 -> V_165 ) ;
F_80 ( V_7 ) ;
V_7 -> V_303 = 0 ;
V_7 -> V_306 = NULL ;
V_7 -> V_2 = NULL ;
memset ( & V_7 -> V_96 , 0 , sizeof( V_7 -> V_96 ) ) ;
V_7 -> V_312 = NULL ;
V_7 -> V_313 = 0 ;
F_66 ( V_7 -> V_125 ) ;
V_7 -> V_125 = NULL ;
F_154 ( V_105 ) ;
return 0 ;
}
static int F_160 ( struct V_6 * V_7 , const char * const * V_314 ,
T_6 V_315 , void * V_316 )
{
struct V_186 * V_299 ;
const char * const * V_317 ;
int V_12 , V_30 ;
V_299 = V_7 -> V_172 . V_4 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_172 . V_48 ; V_12 ++ ) {
struct V_257 * V_318 = V_299 [ V_12 ] . V_291 ;
if ( ! V_318 || ! V_318 -> V_126 . V_133 ||
V_318 -> V_126 . V_289 != V_290 )
continue;
for ( V_317 = V_314 ; * V_317 ; V_317 ++ ) {
if ( ! strcmp ( V_318 -> V_126 . V_133 , * V_317 ) ) {
V_30 = V_315 ( V_316 , V_318 ) ;
if ( V_30 )
return V_30 ;
break;
}
}
}
return 0 ;
}
static int F_161 ( void * V_316 , struct V_257 * V_318 )
{
return 1 ;
}
int F_162 ( struct V_6 * V_7 , char * V_133 ,
unsigned int * V_286 , const char * const * V_314 )
{
struct V_257 * V_291 ;
int V_30 ;
V_30 = F_160 ( V_7 , V_314 , F_161 , NULL ) ;
if ( V_30 != 1 ) {
F_93 ( L_65 , V_133 ) ;
return 0 ;
}
V_291 = F_163 ( V_133 , V_286 ) ;
if ( ! V_291 )
return - V_76 ;
V_30 = F_145 ( V_7 , 0 , V_291 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_160 ( V_7 , V_314 , ( T_6 ) V_319 ,
V_291 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
int F_164 ( struct V_257 * V_258 ,
struct V_259 * V_260 )
{
int V_261 = F_129 ( V_258 ) ;
V_260 -> type = V_320 ;
V_260 -> V_263 = V_261 == 3 ? 2 : 1 ;
V_260 -> V_264 . integer . V_265 = 0 ;
V_260 -> V_264 . integer . V_266 = 1 ;
return 0 ;
}
int F_165 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
T_2 V_19 = F_128 ( V_258 ) ;
int V_261 = F_129 ( V_258 ) ;
int V_232 = F_130 ( V_258 ) ;
int V_220 = F_135 ( V_258 ) ;
long * V_271 = V_270 -> V_264 . integer . V_264 ;
if ( V_261 & 1 )
* V_271 ++ = ( F_121 ( V_7 , V_19 , 0 , V_232 , V_220 ) &
V_248 ) ? 0 : 1 ;
if ( V_261 & 2 )
* V_271 = ( F_121 ( V_7 , V_19 , 1 , V_232 , V_220 ) &
V_248 ) ? 0 : 1 ;
return 0 ;
}
int F_166 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
T_2 V_19 = F_128 ( V_258 ) ;
int V_261 = F_129 ( V_258 ) ;
int V_232 = F_130 ( V_258 ) ;
int V_220 = F_135 ( V_258 ) ;
long * V_271 = V_270 -> V_264 . integer . V_264 ;
int V_272 = 0 ;
F_15 ( V_7 ) ;
if ( V_261 & 1 ) {
V_272 = F_122 ( V_7 , V_19 , 0 , V_232 , V_220 ,
V_248 ,
* V_271 ? 0 : V_248 ) ;
V_271 ++ ;
}
if ( V_261 & 2 )
V_272 |= F_122 ( V_7 , V_19 , 1 , V_232 , V_220 ,
V_248 ,
* V_271 ? 0 : V_248 ) ;
F_167 ( V_7 , V_19 ) ;
F_18 ( V_7 ) ;
return V_272 ;
}
int F_168 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
long * V_271 = V_270 -> V_264 . integer . V_264 ;
F_169 ( V_7 , * V_271 ) ;
return F_166 ( V_258 , V_270 ) ;
}
int F_170 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
unsigned long V_321 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_321 = V_258 -> V_297 ;
V_258 -> V_297 = V_321 & ~ V_322 ;
V_30 = F_165 ( V_258 , V_270 ) ;
V_258 -> V_297 = V_321 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_171 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
unsigned long V_321 ;
int V_12 , V_323 , V_30 = 0 , V_272 = 0 ;
F_2 ( & V_7 -> V_183 ) ;
V_321 = V_258 -> V_297 ;
V_323 = ( V_321 & V_322 ) >> V_324 ;
for ( V_12 = 0 ; V_12 < V_323 ; V_12 ++ ) {
V_258 -> V_297 = ( V_321 & ~ V_322 ) |
( V_12 << V_324 ) ;
V_30 = F_166 ( V_258 , V_270 ) ;
if ( V_30 < 0 )
break;
V_272 |= V_30 ;
}
V_258 -> V_297 = V_321 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 < 0 ? V_30 : V_272 ;
}
int F_172 ( struct V_257 * V_258 ,
struct V_259 * V_260 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
struct V_325 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_325 * ) V_258 -> V_297 ;
V_258 -> V_297 = * V_135 -> V_326 ;
V_30 = V_135 -> V_33 -> V_222 ( V_258 , V_260 ) ;
V_258 -> V_297 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_173 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
struct V_325 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_325 * ) V_258 -> V_297 ;
V_258 -> V_297 = * V_135 -> V_326 ;
V_30 = V_135 -> V_33 -> V_327 ( V_258 , V_270 ) ;
V_258 -> V_297 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_174 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
struct V_325 * V_135 ;
unsigned long * V_328 ;
int V_30 = 0 , V_272 = 0 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_325 * ) V_258 -> V_297 ;
for ( V_328 = V_135 -> V_326 ; * V_328 ; V_328 ++ ) {
V_258 -> V_297 = * V_328 ;
V_30 = V_135 -> V_33 -> V_329 ( V_258 , V_270 ) ;
if ( V_30 < 0 )
break;
V_272 |= V_30 ;
}
V_258 -> V_297 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 < 0 ? V_30 : V_272 ;
}
int F_175 ( struct V_257 * V_258 , int V_273 ,
unsigned int V_274 , unsigned int T_5 * V_286 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
struct V_325 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_325 * ) V_258 -> V_297 ;
V_258 -> V_297 = * V_135 -> V_326 ;
V_30 = V_135 -> V_33 -> V_286 ( V_258 , V_273 , V_274 , V_286 ) ;
V_258 -> V_297 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
static int F_176 ( struct V_257 * V_258 ,
struct V_259 * V_260 )
{
V_260 -> type = V_330 ;
V_260 -> V_263 = 1 ;
return 0 ;
}
static int F_177 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
V_270 -> V_264 . V_331 . V_332 [ 0 ] = V_333 |
V_334 |
V_335 |
V_336 ;
V_270 -> V_264 . V_331 . V_332 [ 1 ] = V_337 |
V_338 ;
return 0 ;
}
static int F_178 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
V_270 -> V_264 . V_331 . V_332 [ 0 ] = V_333 |
V_334 |
V_339 ;
return 0 ;
}
static int F_179 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
int V_220 = V_258 -> V_297 ;
struct V_187 * V_340 = F_27 ( & V_7 -> V_174 , V_220 ) ;
V_270 -> V_264 . V_331 . V_332 [ 0 ] = V_340 -> V_332 & 0xff ;
V_270 -> V_264 . V_331 . V_332 [ 1 ] = ( V_340 -> V_332 >> 8 ) & 0xff ;
V_270 -> V_264 . V_331 . V_332 [ 2 ] = ( V_340 -> V_332 >> 16 ) & 0xff ;
V_270 -> V_264 . V_331 . V_332 [ 3 ] = ( V_340 -> V_332 >> 24 ) & 0xff ;
return 0 ;
}
static unsigned short F_180 ( unsigned int V_341 )
{
unsigned short V_23 = 0 ;
if ( V_341 & V_333 )
V_23 |= V_342 ;
if ( V_341 & V_334 )
V_23 |= V_343 ;
if ( V_341 & V_333 ) {
if ( ( V_341 & V_344 ) ==
V_339 )
V_23 |= V_345 ;
} else {
if ( ( V_341 & V_346 ) ==
V_335 )
V_23 |= V_345 ;
if ( ! ( V_341 & V_336 ) )
V_23 |= V_347 ;
if ( V_341 & ( V_338 << 8 ) )
V_23 |= V_348 ;
V_23 |= V_341 & ( V_337 << 8 ) ;
}
return V_23 ;
}
static unsigned int F_181 ( unsigned short V_23 )
{
unsigned int V_341 = 0 ;
if ( V_23 & V_343 )
V_341 |= V_334 ;
if ( V_23 & V_342 )
V_341 |= V_333 ;
if ( V_341 & V_333 ) {
if ( V_341 & V_345 )
V_341 |= V_339 ;
} else {
if ( V_23 & V_345 )
V_341 |= V_335 ;
if ( ! ( V_23 & V_347 ) )
V_341 |= V_336 ;
if ( V_23 & V_348 )
V_341 |= ( V_338 << 8 ) ;
V_341 |= V_23 & ( 0x7f << 8 ) ;
}
return V_341 ;
}
static void F_182 ( struct V_6 * V_7 , T_2 V_19 ,
int V_21 , int V_23 )
{
const T_2 * V_349 ;
F_183 ( V_7 , V_19 , 0 , V_21 , V_23 ) ;
V_349 = V_7 -> V_312 ;
if ( ! V_349 )
return;
for (; * V_349 ; V_349 ++ )
F_183 ( V_7 , * V_349 , 0 , V_21 , V_23 ) ;
}
static inline void F_184 ( struct V_6 * V_7 , T_2 V_19 ,
int V_350 , int V_351 )
{
if ( V_350 != - 1 )
F_182 ( V_7 , V_19 , V_352 , V_350 ) ;
if ( V_351 != - 1 )
F_182 ( V_7 , V_19 , V_353 , V_351 ) ;
}
static int F_185 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
int V_220 = V_258 -> V_297 ;
struct V_187 * V_340 = F_27 ( & V_7 -> V_174 , V_220 ) ;
T_2 V_19 = V_340 -> V_19 ;
unsigned short V_23 ;
int V_272 ;
F_2 ( & V_7 -> V_182 ) ;
V_340 -> V_332 = V_270 -> V_264 . V_331 . V_332 [ 0 ] |
( ( unsigned int ) V_270 -> V_264 . V_331 . V_332 [ 1 ] << 8 ) |
( ( unsigned int ) V_270 -> V_264 . V_331 . V_332 [ 2 ] << 16 ) |
( ( unsigned int ) V_270 -> V_264 . V_331 . V_332 [ 3 ] << 24 ) ;
V_23 = F_180 ( V_340 -> V_332 ) ;
V_23 |= V_340 -> V_354 & 1 ;
V_272 = V_340 -> V_354 != V_23 ;
V_340 -> V_354 = V_23 ;
if ( V_272 && V_19 != ( T_3 ) - 1 )
F_184 ( V_7 , V_19 , V_23 & 0xff , ( V_23 >> 8 ) & 0xff ) ;
F_4 ( & V_7 -> V_182 ) ;
return V_272 ;
}
static int F_186 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
int V_220 = V_258 -> V_297 ;
struct V_187 * V_340 = F_27 ( & V_7 -> V_174 , V_220 ) ;
V_270 -> V_264 . integer . V_264 [ 0 ] = V_340 -> V_354 & V_355 ;
return 0 ;
}
static inline void F_187 ( struct V_6 * V_7 , T_2 V_19 ,
int V_350 , int V_351 )
{
F_184 ( V_7 , V_19 , V_350 , V_351 ) ;
if ( ( F_34 ( V_7 , V_19 ) & V_356 ) &&
( V_350 & V_355 ) )
F_123 ( V_7 , V_19 , V_229 , 0 ,
V_248 , 0 ) ;
}
static int F_188 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
int V_220 = V_258 -> V_297 ;
struct V_187 * V_340 = F_27 ( & V_7 -> V_174 , V_220 ) ;
T_2 V_19 = V_340 -> V_19 ;
unsigned short V_23 ;
int V_272 ;
F_2 ( & V_7 -> V_182 ) ;
V_23 = V_340 -> V_354 & ~ V_355 ;
if ( V_270 -> V_264 . integer . V_264 [ 0 ] )
V_23 |= V_355 ;
V_272 = V_340 -> V_354 != V_23 ;
V_340 -> V_354 = V_23 ;
if ( V_272 && V_19 != ( T_3 ) - 1 )
F_187 ( V_7 , V_19 , V_23 & 0xff , - 1 ) ;
F_4 ( & V_7 -> V_182 ) ;
return V_272 ;
}
int F_189 ( struct V_6 * V_7 ,
T_2 V_357 ,
T_2 V_358 )
{
int V_30 ;
struct V_257 * V_291 ;
struct V_359 * V_360 ;
int V_220 ;
struct V_187 * V_340 ;
V_220 = F_144 ( V_7 , L_66 ) ;
if ( V_220 < 0 ) {
F_13 ( V_25 L_67 ) ;
return - V_181 ;
}
V_340 = F_37 ( & V_7 -> V_174 ) ;
for ( V_360 = V_361 ; V_360 -> V_133 ; V_360 ++ ) {
V_291 = F_190 ( V_360 , V_7 ) ;
if ( ! V_291 )
return - V_76 ;
V_291 -> V_126 . V_236 = V_220 ;
V_291 -> V_297 = V_7 -> V_174 . V_48 - 1 ;
V_30 = F_145 ( V_7 , V_357 , V_291 ) ;
if ( V_30 < 0 )
return V_30 ;
}
V_340 -> V_19 = V_358 ;
V_340 -> V_354 = F_21 ( V_7 , V_358 , 0 ,
V_362 , 0 ) ;
V_340 -> V_332 = F_181 ( V_340 -> V_354 ) ;
return 0 ;
}
struct V_187 * F_191 ( struct V_6 * V_7 ,
T_2 V_19 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_174 . V_48 ; V_12 ++ ) {
struct V_187 * V_340 =
F_27 ( & V_7 -> V_174 , V_12 ) ;
if ( V_340 -> V_19 == V_19 )
return V_340 ;
}
return NULL ;
}
void F_192 ( struct V_6 * V_7 , int V_220 )
{
struct V_187 * V_340 = F_27 ( & V_7 -> V_174 , V_220 ) ;
F_2 ( & V_7 -> V_182 ) ;
V_340 -> V_19 = ( T_3 ) - 1 ;
F_4 ( & V_7 -> V_182 ) ;
}
void F_193 ( struct V_6 * V_7 , int V_220 , T_2 V_19 )
{
struct V_187 * V_340 = F_27 ( & V_7 -> V_174 , V_220 ) ;
unsigned short V_23 ;
F_2 ( & V_7 -> V_182 ) ;
if ( V_340 -> V_19 != V_19 ) {
V_340 -> V_19 = V_19 ;
V_23 = V_340 -> V_354 ;
F_187 ( V_7 , V_19 , V_23 & 0xff , ( V_23 >> 8 ) & 0xff ) ;
}
F_4 ( & V_7 -> V_182 ) ;
}
static int F_194 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_363 * V_364 = F_127 ( V_258 ) ;
V_270 -> V_264 . integer . V_264 [ 0 ] = V_364 -> V_365 ;
return 0 ;
}
static int F_195 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_363 * V_364 = F_127 ( V_258 ) ;
V_364 -> V_365 = ! ! V_270 -> V_264 . integer . V_264 [ 0 ] ;
return 0 ;
}
int F_196 ( struct V_6 * V_7 ,
struct V_363 * V_364 )
{
if ( ! V_364 -> V_366 )
return 0 ;
return F_145 ( V_7 , V_364 -> V_366 ,
F_190 ( & V_367 , V_364 ) ) ;
}
static int F_197 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
V_270 -> V_264 . integer . V_264 [ 0 ] = V_7 -> V_368 ;
return 0 ;
}
static int F_198 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
T_2 V_19 = V_258 -> V_297 ;
unsigned int V_23 = ! ! V_270 -> V_264 . integer . V_264 [ 0 ] ;
int V_272 ;
F_2 ( & V_7 -> V_182 ) ;
V_272 = V_7 -> V_368 != V_23 ;
if ( V_272 ) {
V_7 -> V_368 = V_23 ;
F_183 ( V_7 , V_19 , 0 ,
V_352 , V_23 ) ;
}
F_4 ( & V_7 -> V_182 ) ;
return V_272 ;
}
static int F_199 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
T_2 V_19 = V_258 -> V_297 ;
unsigned short V_23 ;
unsigned int V_341 ;
V_23 = F_21 ( V_7 , V_19 , 0 , V_362 , 0 ) ;
V_341 = F_181 ( V_23 ) ;
V_270 -> V_264 . V_331 . V_332 [ 0 ] = V_341 ;
V_270 -> V_264 . V_331 . V_332 [ 1 ] = V_341 >> 8 ;
V_270 -> V_264 . V_331 . V_332 [ 2 ] = V_341 >> 16 ;
V_270 -> V_264 . V_331 . V_332 [ 3 ] = V_341 >> 24 ;
return 0 ;
}
int F_200 ( struct V_6 * V_7 , T_2 V_19 )
{
int V_30 ;
struct V_257 * V_291 ;
struct V_359 * V_360 ;
int V_220 ;
V_220 = F_144 ( V_7 , L_68 ) ;
if ( V_220 < 0 ) {
F_13 ( V_25 L_69 ) ;
return - V_181 ;
}
for ( V_360 = V_369 ; V_360 -> V_133 ; V_360 ++ ) {
V_291 = F_190 ( V_360 , V_7 ) ;
if ( ! V_291 )
return - V_76 ;
V_291 -> V_297 = V_19 ;
V_30 = F_145 ( V_7 , V_19 , V_291 ) ;
if ( V_30 < 0 )
return V_30 ;
}
V_7 -> V_368 =
F_21 ( V_7 , V_19 , 0 ,
V_362 , 0 ) &
V_355 ;
return 0 ;
}
int F_183 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 , unsigned int V_21 , unsigned int V_22 )
{
int V_30 = F_22 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
struct V_185 * V_135 ;
T_1 V_219 ;
if ( V_30 < 0 )
return V_30 ;
V_21 = V_21 | ( V_22 >> 8 ) ;
V_22 &= 0xff ;
V_219 = F_201 ( V_19 , V_21 ) ;
F_2 ( & V_7 -> V_29 -> V_32 ) ;
V_135 = F_107 ( & V_7 -> V_176 , V_219 ) ;
if ( V_135 )
V_135 -> V_23 = V_22 ;
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return 0 ;
}
int F_202 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 , unsigned int V_21 , unsigned int V_22 )
{
struct V_185 * V_135 ;
T_1 V_219 ;
V_21 = V_21 | ( V_22 >> 8 ) ;
V_22 &= 0xff ;
V_219 = F_201 ( V_19 , V_21 ) ;
F_2 ( & V_7 -> V_29 -> V_32 ) ;
V_135 = F_106 ( & V_7 -> V_176 , V_219 ) ;
if ( V_135 && V_135 -> V_23 == V_22 ) {
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return 0 ;
}
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return F_183 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
}
void F_203 ( struct V_6 * V_7 )
{
struct V_185 * V_253 = V_7 -> V_176 . V_218 . V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_176 . V_218 . V_48 ; V_12 ++ , V_253 ++ ) {
T_1 V_219 = V_253 -> V_219 ;
if ( ! V_219 )
continue;
F_22 ( V_7 , F_204 ( V_219 ) , 0 ,
F_205 ( V_219 ) , V_253 -> V_23 ) ;
}
}
void F_206 ( struct V_6 * V_7 ,
const struct V_40 * V_41 )
{
for (; V_41 -> V_19 ; V_41 ++ )
F_183 ( V_7 , V_41 -> V_19 , 0 , V_41 -> V_21 ,
V_41 -> V_42 ) ;
}
void F_207 ( struct V_6 * V_7 , T_2 V_370 ,
unsigned int V_371 ,
bool V_372 )
{
T_2 V_19 = V_7 -> V_154 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_153 ; V_12 ++ , V_19 ++ ) {
unsigned int V_62 = F_34 ( V_7 , V_19 ) ;
if ( ! ( V_62 & V_373 ) )
continue;
if ( V_372 && V_371 == V_374 &&
F_35 ( V_62 ) == V_82 &&
( F_114 ( V_7 , V_19 ) & V_375 ) ) {
int V_376 = F_21 ( V_7 , V_19 , 0 ,
V_377 , 0 ) ;
if ( V_376 & 0x02 )
continue;
}
F_22 ( V_7 , V_19 , 0 , V_378 ,
V_371 ) ;
}
if ( V_371 == V_195 ) {
unsigned long V_379 ;
int V_380 ;
V_379 = V_381 + F_208 ( 500 ) ;
do {
V_380 = F_21 ( V_7 , V_370 , 0 ,
V_382 , 0 ) ;
if ( V_380 == V_371 )
break;
F_101 ( 1 ) ;
} while ( F_209 ( V_379 , V_381 ) );
}
}
static void F_94 ( struct V_6 * V_7 , T_2 V_370 ,
unsigned int V_371 )
{
if ( V_7 -> V_96 . V_383 ) {
V_7 -> V_96 . V_383 ( V_7 , V_370 , V_371 ) ;
return;
}
if ( V_371 == V_374 )
F_101 ( 100 ) ;
F_21 ( V_7 , V_370 , 0 , V_378 ,
V_371 ) ;
F_207 ( V_7 , V_370 , V_371 , true ) ;
}
static void F_210 ( struct V_6 * V_7 )
{
if ( V_7 -> V_384 . V_4 )
F_23 ( V_7 , V_7 -> V_384 . V_4 ) ;
}
static inline void F_210 ( struct V_6 * V_7 ) {}
static void F_211 ( struct V_6 * V_7 )
{
if ( V_7 -> V_96 . V_385 )
V_7 -> V_96 . V_385 ( V_7 , V_386 ) ;
F_105 ( V_7 ) ;
F_94 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_374 ) ;
#ifdef F_86
F_212 ( V_7 ) ;
F_87 ( & V_7 -> V_171 ) ;
V_7 -> V_387 = 0 ;
V_7 -> V_388 = 0 ;
V_7 -> V_389 = V_381 ;
#endif
}
static void F_213 ( struct V_6 * V_7 )
{
F_94 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_195 ) ;
F_80 ( V_7 ) ;
F_82 ( V_7 ) ;
F_210 ( V_7 ) ;
F_214 ( V_7 ) ;
if ( V_7 -> V_96 . V_390 )
V_7 -> V_96 . V_390 ( V_7 ) ;
else {
if ( V_7 -> V_96 . V_391 )
V_7 -> V_96 . V_391 ( V_7 ) ;
F_124 ( V_7 ) ;
F_203 ( V_7 ) ;
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
V_30 = F_155 ( V_7 ) ;
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
F_210 ( V_7 ) ;
if ( V_7 -> V_96 . V_391 )
V_30 = V_7 -> V_96 . V_391 ( V_7 ) ;
if ( ! V_30 && V_7 -> V_96 . V_392 )
V_30 = V_7 -> V_96 . V_392 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
unsigned int F_217 ( unsigned int V_393 ,
unsigned int V_394 ,
unsigned int V_201 ,
unsigned int V_395 ,
unsigned short V_396 )
{
int V_12 ;
unsigned int V_23 = 0 ;
for ( V_12 = 0 ; V_397 [ V_12 ] . V_398 ; V_12 ++ )
if ( V_397 [ V_12 ] . V_398 == V_393 ) {
V_23 = V_397 [ V_12 ] . V_399 ;
break;
}
if ( ! V_397 [ V_12 ] . V_398 ) {
F_93 ( L_73 , V_393 ) ;
return 0 ;
}
if ( V_394 == 0 || V_394 > 8 ) {
F_93 ( L_74 , V_394 ) ;
return 0 ;
}
V_23 |= V_394 - 1 ;
switch ( F_218 ( V_201 ) ) {
case 8 :
V_23 |= V_400 ;
break;
case 16 :
V_23 |= V_401 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_395 >= 32 || V_201 == V_402 )
V_23 |= V_403 ;
else if ( V_395 >= 24 )
V_23 |= V_404 ;
else
V_23 |= V_405 ;
break;
default:
F_93 ( L_75 ,
F_218 ( V_201 ) ) ;
return 0 ;
}
if ( V_396 & V_343 )
V_23 |= V_406 ;
return V_23 ;
}
static unsigned int F_219 ( struct V_6 * V_7 , T_2 V_19 )
{
unsigned int V_23 = 0 ;
if ( V_19 != V_7 -> V_127 &&
( F_34 ( V_7 , V_19 ) & V_407 ) )
V_23 = F_25 ( V_7 , V_19 , V_408 ) ;
if ( ! V_23 || V_23 == - 1 )
V_23 = F_25 ( V_7 , V_7 -> V_127 , V_408 ) ;
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
unsigned int V_307 = F_25 ( V_7 , V_19 , V_409 ) ;
if ( ! V_307 || V_307 == - 1 )
V_307 = F_25 ( V_7 , V_7 -> V_127 , V_409 ) ;
if ( ! V_307 || V_307 == - 1 )
return 0 ;
return V_307 ;
}
static unsigned int F_223 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_115 ( V_7 , V_19 , F_224 ( V_19 ) ,
F_222 ) ;
}
int F_225 ( struct V_6 * V_7 , T_2 V_19 ,
T_1 * V_410 , T_7 * V_411 , unsigned int * V_412 )
{
unsigned int V_12 , V_23 , V_62 ;
V_62 = F_34 ( V_7 , V_19 ) ;
V_23 = F_220 ( V_7 , V_19 ) ;
if ( V_410 ) {
T_1 V_413 = 0 ;
for ( V_12 = 0 ; V_12 < V_414 ; V_12 ++ ) {
if ( V_23 & ( 1 << V_12 ) )
V_413 |= V_397 [ V_12 ] . V_415 ;
}
if ( V_413 == 0 ) {
F_33 ( V_25 L_76
L_77 ,
V_19 , V_23 ,
( V_62 & V_407 ) ? 1 : 0 ) ;
return - V_70 ;
}
* V_410 = V_413 ;
}
if ( V_411 || V_412 ) {
T_7 V_416 = 0 ;
unsigned int V_307 , V_417 ;
V_307 = F_223 ( V_7 , V_19 ) ;
if ( ! V_307 )
return - V_70 ;
V_417 = 0 ;
if ( V_307 & V_418 ) {
if ( V_23 & V_419 ) {
V_416 |= V_420 ;
V_417 = 8 ;
}
if ( V_23 & V_421 ) {
V_416 |= V_422 ;
V_417 = 16 ;
}
if ( V_62 & V_423 ) {
if ( V_23 & V_424 )
V_416 |= V_425 ;
if ( V_23 & ( V_426 | V_427 ) )
V_416 |= V_428 ;
if ( V_23 & V_427 )
V_417 = 24 ;
else if ( V_23 & V_426 )
V_417 = 20 ;
} else if ( V_23 & ( V_426 | V_427 |
V_424 ) ) {
V_416 |= V_428 ;
if ( V_23 & V_424 )
V_417 = 32 ;
else if ( V_23 & V_427 )
V_417 = 24 ;
else if ( V_23 & V_426 )
V_417 = 20 ;
}
}
if ( V_307 & V_429 ) {
V_416 |= V_430 ;
if ( ! V_417 )
V_417 = 32 ;
}
if ( V_307 == V_431 ) {
V_416 |= V_420 ;
V_417 = 8 ;
}
if ( V_416 == 0 ) {
F_33 ( V_25 L_78
L_79
L_80 ,
V_19 , V_23 ,
( V_62 & V_407 ) ? 1 : 0 ,
V_307 ) ;
return - V_70 ;
}
if ( V_411 )
* V_411 = V_416 ;
if ( V_412 )
* V_412 = V_417 ;
}
return 0 ;
}
int F_226 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_201 )
{
int V_12 ;
unsigned int V_23 = 0 , V_393 , V_432 ;
V_23 = F_220 ( V_7 , V_19 ) ;
if ( ! V_23 )
return 0 ;
V_393 = V_201 & 0xff00 ;
for ( V_12 = 0 ; V_12 < V_414 ; V_12 ++ )
if ( V_397 [ V_12 ] . V_399 == V_393 ) {
if ( V_23 & ( 1 << V_12 ) )
break;
return 0 ;
}
if ( V_12 >= V_414 )
return 0 ;
V_432 = F_223 ( V_7 , V_19 ) ;
if ( ! V_432 )
return 0 ;
if ( V_432 & V_418 ) {
switch ( V_201 & 0xf0 ) {
case 0x00 :
if ( ! ( V_23 & V_419 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_23 & V_421 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_23 & V_426 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_23 & V_427 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_23 & V_424 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_227 ( struct V_433 * V_434 ,
struct V_6 * V_7 ,
struct V_435 * V_436 )
{
return 0 ;
}
static int F_228 ( struct V_433 * V_434 ,
struct V_6 * V_7 ,
unsigned int V_199 ,
unsigned int V_201 ,
struct V_435 * V_436 )
{
F_100 ( V_7 , V_434 -> V_19 , V_199 , 0 , V_201 ) ;
return 0 ;
}
static int F_229 ( struct V_433 * V_434 ,
struct V_6 * V_7 ,
struct V_435 * V_436 )
{
F_230 ( V_7 , V_434 -> V_19 ) ;
return 0 ;
}
static int F_231 ( struct V_6 * V_7 ,
struct V_433 * V_222 )
{
int V_30 ;
if ( V_222 -> V_19 && ( ! V_222 -> V_413 || ! V_222 -> V_416 ) ) {
V_30 = F_225 ( V_7 , V_222 -> V_19 ,
V_222 -> V_413 ? NULL : & V_222 -> V_413 ,
V_222 -> V_416 ? NULL : & V_222 -> V_416 ,
V_222 -> V_395 ? NULL : & V_222 -> V_395 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( V_222 -> V_33 . V_437 == NULL )
V_222 -> V_33 . V_437 = F_227 ;
if ( V_222 -> V_33 . V_438 == NULL )
V_222 -> V_33 . V_438 = F_227 ;
if ( V_222 -> V_33 . V_439 == NULL ) {
if ( F_29 ( ! V_222 -> V_19 ) )
return - V_54 ;
V_222 -> V_33 . V_439 = F_228 ;
}
if ( V_222 -> V_33 . V_440 == NULL ) {
if ( F_29 ( ! V_222 -> V_19 ) )
return - V_54 ;
V_222 -> V_33 . V_440 = F_229 ;
}
return 0 ;
}
int F_232 ( struct V_6 * V_7 ,
struct V_433 * V_434 ,
unsigned int V_432 ,
unsigned int V_201 ,
struct V_435 * V_436 )
{
int V_252 ;
F_2 ( & V_7 -> V_29 -> V_117 ) ;
V_252 = V_434 -> V_33 . V_439 ( V_434 , V_7 , V_432 , V_201 , V_436 ) ;
if ( V_252 >= 0 )
F_104 ( V_7 ) ;
F_4 ( & V_7 -> V_29 -> V_117 ) ;
return V_252 ;
}
void F_233 ( struct V_6 * V_7 ,
struct V_433 * V_434 ,
struct V_435 * V_436 )
{
F_2 ( & V_7 -> V_29 -> V_117 ) ;
V_434 -> V_33 . V_440 ( V_434 , V_7 , V_436 ) ;
F_4 ( & V_7 -> V_29 -> V_117 ) ;
}
static int F_234 ( struct V_28 * V_29 , int type )
{
static int V_441 [ V_442 ] [ 5 ] = {
[ V_443 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_444 ] = { 1 , - 1 } ,
[ V_445 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_446 ] = { 6 , - 1 } ,
} ;
int V_12 ;
if ( type >= V_442 ) {
F_33 ( V_73 L_81 , type ) ;
return - V_54 ;
}
for ( V_12 = 0 ; V_441 [ type ] [ V_12 ] >= 0 ; V_12 ++ )
if ( ! F_235 ( V_441 [ type ] [ V_12 ] , V_29 -> V_309 ) )
return V_441 [ type ] [ V_12 ] ;
for ( V_12 = 10 ; V_12 < 32 ; V_12 ++ ) {
if ( ! F_235 ( V_12 , V_29 -> V_309 ) )
return V_12 ;
}
F_33 ( V_73 L_82 ,
V_447 [ type ] ) ;
return - V_448 ;
}
static int F_236 ( struct V_6 * V_7 , struct V_304 * V_301 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
struct V_433 * V_222 ;
int V_432 , V_30 ;
if ( F_29 ( ! V_301 -> V_133 ) )
return - V_54 ;
for ( V_432 = 0 ; V_432 < 2 ; V_432 ++ ) {
V_222 = & V_301 -> V_432 [ V_432 ] ;
if ( V_222 -> V_449 ) {
V_30 = F_231 ( V_7 , V_222 ) ;
if ( V_30 < 0 )
return V_30 ;
}
}
return V_29 -> V_33 . V_450 ( V_29 , V_7 , V_301 ) ;
}
int F_237 ( struct V_6 * V_7 )
{
unsigned int V_301 ;
int V_30 ;
if ( ! V_7 -> V_303 ) {
if ( ! V_7 -> V_96 . V_451 )
return 0 ;
V_30 = V_7 -> V_96 . V_451 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_83
L_71 , V_7 -> V_24 , V_30 ) ;
V_30 = F_155 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25
L_72 ) ;
return V_30 ;
}
}
}
for ( V_301 = 0 ; V_301 < V_7 -> V_303 ; V_301 ++ ) {
struct V_304 * V_305 = & V_7 -> V_306 [ V_301 ] ;
int V_452 ;
if ( ! V_305 -> V_432 [ 0 ] . V_449 && ! V_305 -> V_432 [ 1 ] . V_449 )
continue;
if ( ! V_305 -> V_301 ) {
V_452 = F_234 ( V_7 -> V_29 , V_305 -> V_453 ) ;
if ( V_452 < 0 )
continue;
V_305 -> V_101 = V_452 ;
V_30 = F_236 ( V_7 , V_305 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_84
L_85 ,
V_452 , V_7 -> V_24 ) ;
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
int V_454 , const char * const * V_455 ,
const struct V_456 * V_123 )
{
if ( V_7 -> V_115 && V_455 ) {
int V_12 ;
for ( V_12 = 0 ; V_12 < V_454 ; V_12 ++ ) {
if ( V_455 [ V_12 ] &&
! strcmp ( V_7 -> V_115 , V_455 [ V_12 ] ) ) {
F_19 ( V_457 L_86
L_87 , V_455 [ V_12 ] ) ;
return V_12 ;
}
}
}
if ( ! V_7 -> V_29 -> V_114 || ! V_123 )
return - 1 ;
V_123 = F_240 ( V_7 -> V_29 -> V_114 , V_123 ) ;
if ( ! V_123 )
return - 1 ;
if ( V_123 -> V_264 >= 0 && V_123 -> V_264 < V_454 ) {
#ifdef F_241
char V_137 [ 10 ] ;
const char * V_458 = NULL ;
if ( V_455 )
V_458 = V_455 [ V_123 -> V_264 ] ;
if ( ! V_458 ) {
sprintf ( V_137 , L_88 , V_123 -> V_264 ) ;
V_458 = V_137 ;
}
F_93 ( V_457 L_89
L_90 ,
V_458 , V_123 -> V_459 , V_123 -> V_294 ,
( V_123 -> V_133 ? V_123 -> V_133 : L_91 ) ) ;
#endif
return V_123 -> V_264 ;
}
return - 1 ;
}
int F_242 ( struct V_6 * V_7 ,
int V_454 , const char * const * V_455 ,
const struct V_456 * V_123 )
{
const struct V_456 * V_213 ;
for ( V_213 = V_123 ; V_213 -> V_459 ; V_213 ++ ) {
unsigned int V_61 = 0xffff0000 | V_213 -> V_460 ;
unsigned int V_126 = ( V_213 -> V_294 | ( V_213 -> V_459 << 16 ) ) & V_61 ;
if ( ( V_7 -> V_191 & V_61 ) == V_126 )
break;
}
if ( ! V_213 -> V_459 )
return - 1 ;
V_123 = V_213 ;
if ( V_123 -> V_264 >= 0 && V_123 -> V_264 < V_454 ) {
#ifdef F_241
char V_137 [ 10 ] ;
const char * V_458 = NULL ;
if ( V_455 )
V_458 = V_455 [ V_123 -> V_264 ] ;
if ( ! V_458 ) {
sprintf ( V_137 , L_88 , V_123 -> V_264 ) ;
V_458 = V_137 ;
}
F_93 ( V_457 L_89
L_90 ,
V_458 , V_123 -> V_459 , V_123 -> V_294 ,
( V_123 -> V_133 ? V_123 -> V_133 : L_91 ) ) ;
#endif
return V_123 -> V_264 ;
}
return - 1 ;
}
int F_243 ( struct V_6 * V_7 ,
const struct V_359 * V_461 )
{
int V_30 ;
for (; V_461 -> V_133 ; V_461 ++ ) {
struct V_257 * V_291 ;
int V_24 = 0 , V_220 = 0 ;
if ( V_461 -> V_289 == - 1 )
continue;
for (; ; ) {
V_291 = F_190 ( V_461 , V_7 ) ;
if ( ! V_291 )
return - V_76 ;
if ( V_24 > 0 )
V_291 -> V_126 . V_101 = V_24 ;
if ( V_220 > 0 )
V_291 -> V_126 . V_236 = V_220 ;
V_30 = F_145 ( V_7 , 0 , V_291 ) ;
if ( ! V_30 )
break;
if ( ! V_24 && V_7 -> V_24 )
V_24 = V_7 -> V_24 ;
else if ( ! V_220 && ! V_461 -> V_236 ) {
V_220 = F_144 ( V_7 ,
V_461 -> V_133 ) ;
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
if ( ! V_7 -> V_387 || V_7 -> V_462 ) {
V_7 -> V_388 = 0 ;
return;
}
F_244 ( V_7 ) ;
F_211 ( V_7 ) ;
if ( V_29 -> V_33 . V_463 )
V_29 -> V_33 . V_463 ( V_29 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
V_7 -> V_462 ++ ;
V_7 -> V_387 = 1 ;
V_7 -> V_389 = V_381 ;
}
void F_212 ( struct V_6 * V_7 )
{
unsigned long V_464 = V_381 - V_7 -> V_389 ;
if ( V_7 -> V_387 )
V_7 -> V_465 += V_464 ;
else
V_7 -> V_466 += V_464 ;
V_7 -> V_389 += V_464 ;
}
void F_15 ( struct V_6 * V_7 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
V_7 -> V_462 ++ ;
if ( V_7 -> V_387 || V_7 -> V_388 )
return;
F_245 ( V_7 ) ;
F_212 ( V_7 ) ;
V_7 -> V_387 = 1 ;
V_7 -> V_389 = V_381 ;
if ( V_29 -> V_33 . V_463 )
V_29 -> V_33 . V_463 ( V_29 ) ;
F_213 ( V_7 ) ;
F_87 ( & V_7 -> V_171 ) ;
V_7 -> V_388 = 0 ;
}
void F_18 ( struct V_6 * V_7 )
{
-- V_7 -> V_462 ;
if ( ! V_7 -> V_387 || V_7 -> V_462 || V_7 -> V_388 )
return;
if ( V_116 ( V_7 ) ) {
V_7 -> V_388 = 1 ;
F_246 ( V_7 -> V_29 -> V_90 , & V_7 -> V_171 ,
F_208 ( V_116 ( V_7 ) * 1000 ) ) ;
}
}
int F_247 ( struct V_6 * V_7 ,
struct V_467 * V_468 ,
T_2 V_19 )
{
const struct V_469 * V_49 ;
int V_235 , V_470 ;
if ( ! V_468 -> V_471 )
return 0 ;
for ( V_49 = V_468 -> V_471 ; V_49 -> V_19 ; V_49 ++ ) {
if ( V_49 -> V_19 == V_19 )
break;
}
if ( ! V_49 -> V_19 )
return 0 ;
for ( V_49 = V_468 -> V_471 ; V_49 -> V_19 ; V_49 ++ ) {
for ( V_235 = 0 ; V_235 < 2 ; V_235 ++ ) {
V_470 = F_121 ( V_7 , V_49 -> V_19 , V_235 , V_49 -> V_232 ,
V_49 -> V_220 ) ;
if ( ! ( V_470 & V_248 ) && V_470 > 0 ) {
if ( ! V_468 -> V_387 ) {
V_468 -> V_387 = 1 ;
F_15 ( V_7 ) ;
}
return 1 ;
}
}
}
if ( V_468 -> V_387 ) {
V_468 -> V_387 = 0 ;
F_18 ( V_7 ) ;
}
return 0 ;
}
int F_248 ( struct V_6 * V_7 ,
struct V_259 * V_260 ,
const struct V_472 * V_473 ,
int V_474 )
{
V_260 -> type = V_475 ;
V_260 -> V_263 = 1 ;
V_260 -> V_264 . V_476 . V_299 = V_474 ;
if ( V_260 -> V_264 . V_476 . V_293 >= V_474 )
V_260 -> V_264 . V_476 . V_293 = V_474 - 1 ;
sprintf ( V_260 -> V_264 . V_476 . V_133 , L_92 ,
V_473 [ V_260 -> V_264 . V_476 . V_293 ] . V_394 ) ;
return 0 ;
}
int F_249 ( struct V_6 * V_7 ,
struct V_269 * V_270 ,
const struct V_472 * V_473 ,
int V_474 ,
int V_477 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_474 ; V_12 ++ ) {
if ( V_477 == V_473 [ V_12 ] . V_394 ) {
V_270 -> V_264 . V_476 . V_293 [ 0 ] = V_12 ;
break;
}
}
return 0 ;
}
int F_250 ( struct V_6 * V_7 ,
struct V_269 * V_270 ,
const struct V_472 * V_473 ,
int V_474 ,
int * V_478 )
{
unsigned int V_479 ;
V_479 = V_270 -> V_264 . V_476 . V_293 [ 0 ] ;
if ( V_479 >= V_474 )
return - V_54 ;
if ( * V_478 == V_473 [ V_479 ] . V_394 )
return 0 ;
* V_478 = V_473 [ V_479 ] . V_394 ;
if ( V_473 [ V_479 ] . V_480 )
F_206 ( V_7 , V_473 [ V_479 ] . V_480 ) ;
return 1 ;
}
int F_251 ( const struct V_481 * V_482 ,
struct V_259 * V_260 )
{
unsigned int V_236 ;
V_260 -> type = V_475 ;
V_260 -> V_263 = 1 ;
V_260 -> V_264 . V_476 . V_299 = V_482 -> V_483 ;
if ( ! V_482 -> V_483 )
return 0 ;
V_236 = V_260 -> V_264 . V_476 . V_293 ;
if ( V_236 >= V_482 -> V_483 )
V_236 = V_482 -> V_483 - 1 ;
strcpy ( V_260 -> V_264 . V_476 . V_133 , V_482 -> V_299 [ V_236 ] . V_484 ) ;
return 0 ;
}
int F_252 ( struct V_6 * V_7 ,
const struct V_481 * V_482 ,
struct V_269 * V_270 ,
T_2 V_19 ,
unsigned int * V_485 )
{
unsigned int V_220 ;
if ( ! V_482 -> V_483 )
return 0 ;
V_220 = V_270 -> V_264 . V_476 . V_293 [ 0 ] ;
if ( V_220 >= V_482 -> V_483 )
V_220 = V_482 -> V_483 - 1 ;
if ( * V_485 == V_220 )
return 0 ;
F_183 ( V_7 , V_19 , 0 , V_486 ,
V_482 -> V_299 [ V_220 ] . V_236 ) ;
* V_485 = V_220 ;
return 1 ;
}
static void F_253 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_199 , unsigned int V_201 )
{
struct V_187 * V_340 = F_191 ( V_7 , V_19 ) ;
if ( V_7 -> V_313 && ( V_340 -> V_354 & V_355 ) )
F_184 ( V_7 , V_19 ,
V_340 -> V_354 & ~ V_355 & 0xff ,
- 1 ) ;
F_100 ( V_7 , V_19 , V_199 , 0 , V_201 ) ;
if ( V_7 -> V_312 ) {
const T_2 * V_349 ;
for ( V_349 = V_7 -> V_312 ; * V_349 ; V_349 ++ )
F_100 ( V_7 , * V_349 , V_199 , 0 ,
V_201 ) ;
}
if ( V_7 -> V_313 && ( V_340 -> V_354 & V_355 ) )
F_184 ( V_7 , V_19 ,
V_340 -> V_354 & 0xff , - 1 ) ;
}
static void F_254 ( struct V_6 * V_7 , T_2 V_19 )
{
F_230 ( V_7 , V_19 ) ;
if ( V_7 -> V_312 ) {
const T_2 * V_349 ;
for ( V_349 = V_7 -> V_312 ; * V_349 ; V_349 ++ )
F_230 ( V_7 , * V_349 ) ;
}
}
void F_255 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
if ( ! V_29 )
return;
F_55 (codec, &bus->codec_list, list) {
if ( F_256 ( V_7 ) &&
V_7 -> V_96 . V_487 )
V_7 -> V_96 . V_487 ( V_7 ) ;
}
}
int F_257 ( struct V_6 * V_7 ,
struct V_363 * V_364 )
{
F_2 ( & V_7 -> V_182 ) ;
if ( V_364 -> V_488 == V_489 )
F_254 ( V_7 , V_364 -> V_366 ) ;
V_364 -> V_488 = V_490 ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_258 ( struct V_6 * V_7 ,
struct V_363 * V_364 ,
unsigned int V_199 ,
unsigned int V_201 ,
struct V_435 * V_436 )
{
F_2 ( & V_7 -> V_182 ) ;
F_253 ( V_7 , V_364 -> V_366 , V_199 , V_201 ) ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_259 ( struct V_6 * V_7 ,
struct V_363 * V_364 )
{
F_2 ( & V_7 -> V_182 ) ;
F_254 ( V_7 , V_364 -> V_366 ) ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_260 ( struct V_6 * V_7 ,
struct V_363 * V_364 )
{
F_2 ( & V_7 -> V_182 ) ;
V_364 -> V_488 = 0 ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_261 ( struct V_6 * V_7 ,
struct V_363 * V_364 ,
struct V_435 * V_436 ,
struct V_433 * V_434 )
{
struct V_491 * V_492 = V_436 -> V_492 ;
V_492 -> V_493 . V_494 = V_364 -> V_477 ;
if ( V_364 -> V_366 ) {
if ( ! V_364 -> V_495 ) {
V_364 -> V_495 = V_434 -> V_413 ;
V_364 -> V_496 = V_434 -> V_416 ;
V_364 -> V_497 = V_434 -> V_395 ;
} else {
V_492 -> V_493 . V_413 = V_364 -> V_495 ;
V_492 -> V_493 . V_416 = V_364 -> V_496 ;
V_434 -> V_395 = V_364 -> V_497 ;
}
if ( ! V_364 -> V_498 ) {
F_225 ( V_7 , V_364 -> V_366 ,
& V_364 -> V_498 ,
& V_364 -> V_499 ,
& V_364 -> V_500 ) ;
}
F_2 ( & V_7 -> V_182 ) ;
if ( V_364 -> V_365 ) {
if ( ( V_492 -> V_493 . V_413 & V_364 -> V_498 ) &&
( V_492 -> V_493 . V_416 & V_364 -> V_499 ) ) {
V_492 -> V_493 . V_413 &= V_364 -> V_498 ;
V_492 -> V_493 . V_416 &= V_364 -> V_499 ;
if ( V_364 -> V_500 < V_434 -> V_395 )
V_434 -> V_395 = V_364 -> V_500 ;
} else {
V_364 -> V_365 = 0 ;
}
}
F_4 ( & V_7 -> V_182 ) ;
}
return F_262 ( V_436 -> V_492 , 0 ,
V_501 , 2 ) ;
}
int F_263 ( struct V_6 * V_7 ,
struct V_363 * V_364 ,
unsigned int V_199 ,
unsigned int V_201 ,
struct V_435 * V_436 )
{
const T_2 * V_173 = V_364 -> V_502 ;
int V_261 = V_436 -> V_492 -> V_394 ;
struct V_187 * V_340 =
F_191 ( V_7 , V_364 -> V_366 ) ;
int V_12 ;
F_2 ( & V_7 -> V_182 ) ;
if ( V_364 -> V_366 && V_364 -> V_365 &&
V_364 -> V_488 != V_490 ) {
if ( V_261 == 2 &&
F_226 ( V_7 , V_364 -> V_366 ,
V_201 ) &&
! ( V_340 -> V_332 & V_334 ) ) {
V_364 -> V_488 = V_489 ;
F_253 ( V_7 , V_364 -> V_366 ,
V_199 , V_201 ) ;
} else {
V_364 -> V_488 = 0 ;
F_254 ( V_7 , V_364 -> V_366 ) ;
}
}
F_4 ( & V_7 -> V_182 ) ;
F_100 ( V_7 , V_173 [ V_503 ] , V_199 ,
0 , V_201 ) ;
if ( ! V_364 -> V_504 &&
V_364 -> V_505 && V_364 -> V_505 != V_173 [ V_503 ] )
F_100 ( V_7 , V_364 -> V_505 , V_199 ,
0 , V_201 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_364 -> V_506 ) ; V_12 ++ )
if ( ! V_364 -> V_504 && V_364 -> V_506 [ V_12 ] )
F_100 ( V_7 ,
V_364 -> V_506 [ V_12 ] ,
V_199 , 0 , V_201 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_364 -> V_507 ) ; V_12 ++ )
if ( ! V_364 -> V_504 && V_364 -> V_507 [ V_12 ] )
F_100 ( V_7 ,
V_364 -> V_507 [ V_12 ] ,
V_199 , 0 , V_201 ) ;
for ( V_12 = 1 ; V_12 < V_364 -> V_508 ; V_12 ++ ) {
if ( V_261 >= ( V_12 + 1 ) * 2 )
F_100 ( V_7 , V_173 [ V_12 ] , V_199 ,
V_12 * 2 , V_201 ) ;
else if ( ! V_364 -> V_504 )
F_100 ( V_7 , V_173 [ V_12 ] , V_199 ,
0 , V_201 ) ;
}
return 0 ;
}
int F_264 ( struct V_6 * V_7 ,
struct V_363 * V_364 )
{
const T_2 * V_173 = V_364 -> V_502 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_364 -> V_508 ; V_12 ++ )
F_230 ( V_7 , V_173 [ V_12 ] ) ;
if ( V_364 -> V_505 )
F_230 ( V_7 , V_364 -> V_505 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_364 -> V_506 ) ; V_12 ++ )
if ( V_364 -> V_506 [ V_12 ] )
F_230 ( V_7 ,
V_364 -> V_506 [ V_12 ] ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_364 -> V_507 ) ; V_12 ++ )
if ( V_364 -> V_507 [ V_12 ] )
F_230 ( V_7 ,
V_364 -> V_507 [ V_12 ] ) ;
F_2 ( & V_7 -> V_182 ) ;
if ( V_364 -> V_366 && V_364 -> V_488 == V_489 ) {
F_254 ( V_7 , V_364 -> V_366 ) ;
V_364 -> V_488 = 0 ;
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
static void F_266 ( T_2 * V_509 , short * V_510 ,
int V_511 )
{
int V_12 , V_512 ;
short V_41 ;
T_2 V_19 ;
for ( V_12 = 0 ; V_12 < V_511 ; V_12 ++ ) {
for ( V_512 = V_12 + 1 ; V_512 < V_511 ; V_512 ++ ) {
if ( V_510 [ V_12 ] > V_510 [ V_512 ] ) {
V_41 = V_510 [ V_12 ] ;
V_510 [ V_12 ] = V_510 [ V_512 ] ;
V_510 [ V_512 ] = V_41 ;
V_19 = V_509 [ V_12 ] ;
V_509 [ V_12 ] = V_509 [ V_512 ] ;
V_509 [ V_512 ] = V_19 ;
}
}
}
}
static void F_267 ( struct V_513 * V_8 , T_2 V_19 ,
int type )
{
if ( V_8 -> V_514 < V_515 ) {
V_8 -> V_516 [ V_8 -> V_514 ] . V_157 = V_19 ;
V_8 -> V_516 [ V_8 -> V_514 ] . type = type ;
V_8 -> V_514 ++ ;
}
}
static void F_268 ( struct V_513 * V_8 )
{
int V_12 , V_512 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_514 ; V_12 ++ ) {
for ( V_512 = V_12 + 1 ; V_512 < V_8 -> V_514 ; V_512 ++ ) {
if ( V_8 -> V_516 [ V_12 ] . type > V_8 -> V_516 [ V_512 ] . type ) {
struct V_517 V_137 ;
V_137 = V_8 -> V_516 [ V_12 ] ;
V_8 -> V_516 [ V_12 ] = V_8 -> V_516 [ V_512 ] ;
V_8 -> V_516 [ V_512 ] = V_137 ;
}
}
}
}
static void F_269 ( unsigned int V_81 , T_2 * V_509 )
{
T_2 V_19 ;
switch ( V_81 ) {
case 3 :
case 4 :
V_19 = V_509 [ 1 ] ;
V_509 [ 1 ] = V_509 [ 2 ] ;
V_509 [ 2 ] = V_19 ;
break;
}
}
int F_270 ( struct V_6 * V_7 ,
struct V_513 * V_8 ,
const T_2 * V_518 ,
unsigned int V_519 )
{
T_2 V_19 , V_520 ;
short V_41 , V_521 ;
short V_522 [ F_9 ( V_8 -> V_523 ) ] ;
short V_524 [ F_9 ( V_8 -> V_525 ) ] ;
short V_526 [ F_9 ( V_8 -> V_527 ) ] ;
int V_12 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
memset ( V_522 , 0 , sizeof( V_522 ) ) ;
memset ( V_524 , 0 , sizeof( V_524 ) ) ;
memset ( V_526 , 0 , sizeof( V_526 ) ) ;
V_521 = 0 ;
V_7 -> V_528 = true ;
V_520 = V_7 -> V_154 + V_7 -> V_153 ;
for ( V_19 = V_7 -> V_154 ; V_19 < V_520 ; V_19 ++ ) {
unsigned int V_529 = F_34 ( V_7 , V_19 ) ;
unsigned int V_158 = F_35 ( V_529 ) ;
unsigned int V_530 ;
short V_531 , V_532 , V_79 , V_452 ;
if ( V_158 != V_82 )
continue;
if ( V_518 && F_265 ( V_19 , V_518 ) )
continue;
V_530 = F_77 ( V_7 , V_19 ) ;
if ( ! ( F_271 ( F_77 ( V_7 , V_19 ) ) &
V_533 ) )
V_7 -> V_528 = false ;
V_79 = F_272 ( V_530 ) ;
if ( V_79 == V_534 )
continue;
V_532 = F_273 ( V_530 ) ;
V_452 = F_274 ( V_530 ) ;
if ( V_452 == V_535 ) {
if ( V_79 == V_536 )
V_452 = V_537 ;
}
switch ( V_452 ) {
case V_535 :
V_41 = F_275 ( V_530 ) ;
V_531 = F_276 ( V_530 ) ;
if ( ! ( V_529 & V_538 ) )
if ( ! V_8 -> V_539 )
V_8 -> V_539 = V_19 ;
if ( ! V_531 )
continue;
if ( ! V_521 )
V_521 = V_531 ;
else if ( V_521 != V_531 )
continue;
if ( V_8 -> V_540 >= F_9 ( V_8 -> V_523 ) )
continue;
V_8 -> V_523 [ V_8 -> V_540 ] = V_19 ;
V_522 [ V_8 -> V_540 ] = V_41 ;
V_8 -> V_540 ++ ;
break;
case V_537 :
V_41 = F_275 ( V_530 ) ;
V_531 = F_276 ( V_530 ) ;
if ( V_8 -> V_541 >= F_9 ( V_8 -> V_525 ) )
continue;
V_8 -> V_525 [ V_8 -> V_541 ] = V_19 ;
V_524 [ V_8 -> V_541 ] = ( V_531 << 4 ) | V_41 ;
V_8 -> V_541 ++ ;
break;
case V_542 :
V_41 = F_275 ( V_530 ) ;
V_531 = F_276 ( V_530 ) ;
if ( V_8 -> V_543 >= F_9 ( V_8 -> V_527 ) )
continue;
V_8 -> V_527 [ V_8 -> V_543 ] = V_19 ;
V_526 [ V_8 -> V_543 ] = ( V_531 << 4 ) | V_41 ;
V_8 -> V_543 ++ ;
break;
case V_544 :
F_267 ( V_8 , V_19 , V_545 ) ;
break;
case V_546 :
F_267 ( V_8 , V_19 , V_547 ) ;
break;
case V_548 :
F_267 ( V_8 , V_19 , V_549 ) ;
break;
case V_550 :
F_267 ( V_8 , V_19 , V_551 ) ;
break;
case V_552 :
case V_553 :
if ( V_8 -> V_554 >= F_9 ( V_8 -> V_555 ) )
continue;
V_8 -> V_555 [ V_8 -> V_554 ] = V_19 ;
V_8 -> V_556 [ V_8 -> V_554 ] =
( V_532 == V_557 ) ?
V_445 : V_444 ;
V_8 -> V_554 ++ ;
break;
case V_558 :
case V_559 :
V_8 -> V_560 = V_19 ;
if ( V_532 == V_557 )
V_8 -> V_561 = V_445 ;
else
V_8 -> V_561 = V_444 ;
break;
}
}
if ( ! V_8 -> V_540 && V_8 -> V_543 > 1 &&
! ( V_519 & V_562 ) ) {
int V_12 = 0 ;
while ( V_12 < V_8 -> V_543 ) {
if ( ( V_526 [ V_12 ] & 0x0f ) == 0x0f ) {
V_12 ++ ;
continue;
}
V_8 -> V_523 [ V_8 -> V_540 ] = V_8 -> V_527 [ V_12 ] ;
V_522 [ V_8 -> V_540 ] = V_526 [ V_12 ] ;
V_8 -> V_540 ++ ;
V_8 -> V_543 -- ;
memmove ( V_8 -> V_527 + V_12 , V_8 -> V_527 + V_12 + 1 ,
sizeof( V_8 -> V_527 [ 0 ] ) * ( V_8 -> V_543 - V_12 ) ) ;
memmove ( V_526 + V_12 , V_526 + V_12 + 1 ,
sizeof( V_526 [ 0 ] ) * ( V_8 -> V_543 - V_12 ) ) ;
}
memset ( V_8 -> V_527 + V_8 -> V_543 , 0 ,
sizeof( T_2 ) * ( V_563 - V_8 -> V_543 ) ) ;
if ( ! V_8 -> V_543 )
V_8 -> V_564 = V_565 ;
}
F_266 ( V_8 -> V_523 , V_522 ,
V_8 -> V_540 ) ;
F_266 ( V_8 -> V_525 , V_524 ,
V_8 -> V_541 ) ;
F_266 ( V_8 -> V_527 , V_526 ,
V_8 -> V_543 ) ;
if ( ! V_8 -> V_540 &&
! ( V_519 & V_566 ) ) {
if ( V_8 -> V_541 ) {
V_8 -> V_540 = V_8 -> V_541 ;
memcpy ( V_8 -> V_523 , V_8 -> V_525 ,
sizeof( V_8 -> V_525 ) ) ;
V_8 -> V_541 = 0 ;
memset ( V_8 -> V_525 , 0 , sizeof( V_8 -> V_525 ) ) ;
V_8 -> V_564 = V_567 ;
} else if ( V_8 -> V_543 ) {
V_8 -> V_540 = V_8 -> V_543 ;
memcpy ( V_8 -> V_523 , V_8 -> V_527 ,
sizeof( V_8 -> V_527 ) ) ;
V_8 -> V_543 = 0 ;
memset ( V_8 -> V_527 , 0 , sizeof( V_8 -> V_527 ) ) ;
V_8 -> V_564 = V_565 ;
}
}
F_269 ( V_8 -> V_540 , V_8 -> V_523 ) ;
F_269 ( V_8 -> V_543 , V_8 -> V_527 ) ;
F_269 ( V_8 -> V_541 , V_8 -> V_525 ) ;
F_268 ( V_8 ) ;
F_19 ( L_93 ,
V_8 -> V_540 , V_8 -> V_523 [ 0 ] , V_8 -> V_523 [ 1 ] ,
V_8 -> V_523 [ 2 ] , V_8 -> V_523 [ 3 ] ,
V_8 -> V_523 [ 4 ] ,
V_8 -> V_564 == V_565 ? L_94 :
( V_8 -> V_564 == V_567 ?
L_95 : L_96 ) ) ;
F_19 ( L_97 ,
V_8 -> V_541 , V_8 -> V_525 [ 0 ] ,
V_8 -> V_525 [ 1 ] , V_8 -> V_525 [ 2 ] ,
V_8 -> V_525 [ 3 ] , V_8 -> V_525 [ 4 ] ) ;
F_19 ( L_98 ,
V_8 -> V_543 , V_8 -> V_527 [ 0 ] ,
V_8 -> V_527 [ 1 ] , V_8 -> V_527 [ 2 ] ,
V_8 -> V_527 [ 3 ] , V_8 -> V_527 [ 4 ] ) ;
F_19 ( L_99 , V_8 -> V_539 ) ;
if ( V_8 -> V_554 )
F_19 ( L_100 ,
V_8 -> V_555 [ 0 ] , V_8 -> V_555 [ 1 ] ) ;
F_19 ( L_101 ) ;
for ( V_12 = 0 ; V_12 < V_8 -> V_514 ; V_12 ++ ) {
F_19 ( L_102 ,
F_277 ( V_7 , V_8 , V_12 ) ,
V_8 -> V_516 [ V_12 ] . V_157 ) ;
}
F_19 ( L_103 ) ;
if ( V_8 -> V_560 )
F_19 ( L_104 , V_8 -> V_560 ) ;
return 0 ;
}
int F_278 ( unsigned int V_530 )
{
unsigned int V_532 = F_273 ( V_530 ) ;
unsigned int V_79 = F_272 ( V_530 ) ;
if ( V_79 == V_534 )
return V_568 ;
if ( V_79 == V_536 || V_79 == V_569 )
return V_570 ;
if ( ( V_532 & 0x30 ) == V_571 )
return V_570 ;
if ( ( V_532 & 0x30 ) == V_572 )
return V_573 ;
if ( V_532 == V_574 )
return V_575 ;
if ( V_532 == V_576 )
return V_577 ;
return V_578 ;
}
static const char * F_279 ( struct V_6 * V_7 ,
T_2 V_157 , bool V_579 )
{
unsigned int V_530 ;
static const char * const V_580 [] = {
L_105 , L_106 , L_30 , L_107 , L_108 ,
} ;
int V_581 ;
V_530 = F_77 ( V_7 , V_157 ) ;
switch ( F_274 ( V_530 ) ) {
case V_544 :
if ( ! V_579 )
return L_30 ;
V_581 = F_278 ( V_530 ) ;
if ( ! V_581 )
return L_109 ;
return V_580 [ V_581 - 1 ] ;
case V_546 :
if ( ! V_579 )
return L_110 ;
V_581 = F_278 ( V_530 ) ;
if ( ! V_581 )
return L_109 ;
if ( V_581 == V_573 )
return L_111 ;
return L_110 ;
case V_550 :
return L_29 ;
case V_548 :
return L_23 ;
case V_558 :
return L_32 ;
case V_559 :
return L_112 ;
default:
return L_113 ;
}
}
static int F_280 ( struct V_6 * V_7 ,
const struct V_513 * V_8 ,
int V_582 )
{
unsigned int V_583 ;
int V_12 , V_581 , V_584 ;
V_583 = F_77 ( V_7 , V_8 -> V_516 [ V_582 ] . V_157 ) ;
V_581 = F_278 ( V_583 ) ;
if ( V_581 <= V_578 )
return 1 ;
V_581 = 0 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_514 ; V_12 ++ ) {
V_583 = F_77 ( V_7 , V_8 -> V_516 [ V_12 ] . V_157 ) ;
V_584 = F_278 ( V_583 ) ;
if ( V_584 >= V_578 ) {
if ( V_581 && V_581 != V_584 )
return 1 ;
V_581 = V_584 ;
}
}
return 0 ;
}
const char * F_277 ( struct V_6 * V_7 ,
const struct V_513 * V_8 ,
int V_582 )
{
int type = V_8 -> V_516 [ V_582 ] . type ;
int V_585 = 0 ;
if ( ( V_582 > 0 && V_8 -> V_516 [ V_582 - 1 ] . type == type ) ||
( V_582 < V_8 -> V_514 - 1 && V_8 -> V_516 [ V_582 + 1 ] . type == type ) )
V_585 = 1 ;
if ( V_585 && type == V_545 )
V_585 &= F_280 ( V_7 , V_8 , V_582 ) ;
return F_279 ( V_7 , V_8 -> V_516 [ V_582 ] . V_157 ,
V_585 ) ;
}
static int F_281 ( T_2 V_19 , const T_2 * V_4 , int V_81 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_81 ; V_12 ++ )
if ( V_4 [ V_12 ] == V_19 )
return V_12 ;
return - 1 ;
}
static const char * F_282 ( T_2 V_19 , const T_2 * V_509 ,
int V_511 , int * V_586 )
{
static const char * const V_587 [] = {
L_114 , L_115 , L_116 , L_117
} ;
int V_12 ;
V_12 = F_281 ( V_19 , V_509 , V_511 ) ;
if ( V_12 < 0 )
return NULL ;
if ( V_511 == 1 )
return L_118 ;
if ( V_511 > F_9 ( V_587 ) ) {
if ( V_586 )
* V_586 = V_12 ;
return L_118 ;
}
return V_587 [ V_12 ] ;
}
static int F_283 ( struct V_6 * V_7 , T_2 V_19 ,
const struct V_513 * V_8 ,
const char * V_133 , char * V_484 , int V_588 ,
int * V_586 )
{
unsigned int V_530 = F_77 ( V_7 , V_19 ) ;
int V_581 = F_278 ( V_530 ) ;
const char * V_589 = L_118 , * V_590 = L_118 ;
if ( ! strcmp ( V_133 , L_20 ) && V_581 == V_570 )
V_133 = L_21 ;
switch ( V_581 ) {
case V_573 :
V_589 = L_119 ;
break;
case V_577 :
V_589 = L_120 ;
break;
}
if ( V_8 ) {
V_590 = F_282 ( V_19 , V_8 -> V_523 , V_8 -> V_540 ,
V_586 ) ;
if ( ! V_590 )
V_590 = F_282 ( V_19 , V_8 -> V_525 , V_8 -> V_541 ,
V_586 ) ;
if ( ! V_590 ) {
int V_220 = F_281 ( V_19 , V_8 -> V_527 ,
V_8 -> V_543 ) ;
if ( V_220 >= 0 )
* V_586 = V_220 ;
V_590 = L_118 ;
}
}
snprintf ( V_484 , V_588 , L_121 , V_589 , V_133 , V_590 ) ;
return 1 ;
}
int F_284 ( struct V_6 * V_7 , T_2 V_19 ,
const struct V_513 * V_8 ,
char * V_484 , int V_588 , int * V_586 )
{
unsigned int V_530 = F_77 ( V_7 , V_19 ) ;
const char * V_133 = NULL ;
int V_12 ;
if ( V_586 )
* V_586 = 0 ;
if ( F_272 ( V_530 ) == V_534 )
return 0 ;
switch ( F_274 ( V_530 ) ) {
case V_535 :
return F_283 ( V_7 , V_19 , V_8 , L_20 ,
V_484 , V_588 , V_586 ) ;
case V_537 :
return F_283 ( V_7 , V_19 , V_8 , L_21 ,
V_484 , V_588 , V_586 ) ;
case V_542 :
return F_283 ( V_7 , V_19 , V_8 , L_122 ,
V_484 , V_588 , V_586 ) ;
case V_552 :
case V_553 :
if ( F_273 ( V_530 ) == V_557 )
V_133 = L_11 ;
else
V_133 = L_123 ;
if ( V_8 && V_586 ) {
V_12 = F_281 ( V_19 , V_8 -> V_555 ,
V_8 -> V_554 ) ;
if ( V_12 >= 0 )
* V_586 = V_12 ;
}
break;
default:
if ( V_8 ) {
for ( V_12 = 0 ; V_12 < V_8 -> V_514 ; V_12 ++ ) {
if ( V_8 -> V_516 [ V_12 ] . V_157 != V_19 )
continue;
V_133 = F_277 ( V_7 , V_8 , V_12 ) ;
if ( V_133 )
break;
}
}
if ( ! V_133 )
V_133 = F_279 ( V_7 , V_19 , true ) ;
break;
}
if ( ! V_133 )
return 0 ;
F_285 ( V_484 , V_133 , V_588 ) ;
return 1 ;
}
int F_286 ( struct V_481 * V_482 , const char * V_484 ,
int V_236 , int * V_591 )
{
int V_12 , V_592 = 0 ;
if ( V_482 -> V_483 >= V_80 ) {
F_19 ( V_25 L_124 ) ;
return - V_54 ;
}
for ( V_12 = 0 ; V_12 < V_482 -> V_483 ; V_12 ++ ) {
if ( ! strncmp ( V_484 , V_482 -> V_299 [ V_12 ] . V_484 , strlen ( V_484 ) ) )
V_592 ++ ;
}
if ( V_591 )
* V_591 = V_592 ;
if ( V_592 > 0 )
snprintf ( V_482 -> V_299 [ V_482 -> V_483 ] . V_484 ,
sizeof( V_482 -> V_299 [ V_482 -> V_483 ] . V_484 ) ,
L_125 , V_484 , V_592 ) ;
else
F_285 ( V_482 -> V_299 [ V_482 -> V_483 ] . V_484 , V_484 ,
sizeof( V_482 -> V_299 [ V_482 -> V_483 ] . V_484 ) ) ;
V_482 -> V_299 [ V_482 -> V_483 ] . V_236 = V_236 ;
V_482 -> V_483 ++ ;
return 0 ;
}
int F_287 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
if ( F_256 ( V_7 ) )
F_211 ( V_7 ) ;
if ( V_7 -> V_96 . V_593 )
V_7 -> V_96 . V_593 ( V_7 ) ;
}
return 0 ;
}
int F_288 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
if ( V_7 -> V_96 . V_594 )
V_7 -> V_96 . V_594 ( V_7 ) ;
if ( F_289 ( V_7 ) )
F_213 ( V_7 ) ;
}
return 0 ;
}
void * F_37 ( struct V_45 * V_46 )
{
if ( V_46 -> V_48 >= V_46 -> V_595 ) {
int V_596 = V_46 -> V_595 + V_46 -> V_597 ;
int V_274 = ( V_596 + 1 ) * V_46 -> V_598 ;
int V_599 = V_46 -> V_595 * V_46 -> V_598 ;
void * V_600 ;
if ( F_29 ( V_596 >= 4096 ) )
return NULL ;
V_600 = F_290 ( V_46 -> V_4 , V_274 , V_98 ) ;
if ( ! V_600 )
return NULL ;
memset ( V_600 + V_599 , 0 , V_274 - V_599 ) ;
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
void F_291 ( int V_301 , char * V_218 , int V_601 )
{
static unsigned int V_602 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_12 , V_512 ;
for ( V_12 = 0 , V_512 = 0 ; V_12 < F_9 ( V_602 ) ; V_12 ++ )
if ( V_301 & ( V_419 << V_12 ) )
V_512 += snprintf ( V_218 + V_512 , V_601 - V_512 , L_126 , V_602 [ V_12 ] ) ;
V_218 [ V_512 ] = '\0' ;
}
