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
const char * V_315 , T_6 V_316 , void * V_317 )
{
struct V_186 * V_299 ;
const char * const * V_318 ;
int V_12 , V_30 ;
V_299 = V_7 -> V_172 . V_4 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_172 . V_48 ; V_12 ++ ) {
struct V_257 * V_319 = V_299 [ V_12 ] . V_291 ;
if ( ! V_319 || ! V_319 -> V_126 . V_133 ||
V_319 -> V_126 . V_289 != V_290 )
continue;
for ( V_318 = V_314 ; * V_318 ; V_318 ++ ) {
char V_320 [ sizeof( V_319 -> V_126 . V_133 ) ] ;
const char * V_133 = * V_318 ;
if ( V_315 ) {
snprintf ( V_320 , sizeof( V_320 ) , L_59 ,
V_133 , V_315 ) ;
V_133 = V_320 ;
}
if ( ! strcmp ( V_319 -> V_126 . V_133 , V_133 ) ) {
V_30 = V_316 ( V_317 , V_319 ) ;
if ( V_30 )
return V_30 ;
break;
}
}
}
return 0 ;
}
static int F_161 ( void * V_317 , struct V_257 * V_319 )
{
return 1 ;
}
static int F_162 ( struct V_257 * V_291 )
{
int V_275 [ 4 ] ;
const int * V_286 = NULL ;
int V_23 = - 1 ;
if ( V_291 -> V_321 [ 0 ] . V_322 & V_323 ) {
T_7 V_324 = F_163 () ;
F_164 ( F_165 () ) ;
if ( ! V_291 -> V_286 . V_135 ( V_291 , 0 , sizeof( V_275 ) , V_275 ) )
V_286 = V_275 ;
F_164 ( V_324 ) ;
} else if ( V_291 -> V_321 [ 0 ] . V_322 & V_325 )
V_286 = V_291 -> V_286 . V_49 ;
if ( V_286 && V_286 [ 0 ] == V_284 )
V_23 = - V_286 [ 2 ] / V_286 [ 3 ] ;
return V_23 ;
}
static int F_166 ( struct V_257 * V_291 , int V_23 )
{
struct V_269 * V_270 ;
V_270 = F_45 ( sizeof( * V_270 ) , V_98 ) ;
if ( ! V_270 )
return - V_76 ;
V_270 -> V_264 . integer . V_264 [ 0 ] = V_23 ;
V_270 -> V_264 . integer . V_264 [ 1 ] = V_23 ;
V_291 -> V_326 ( V_291 , V_270 ) ;
F_49 ( V_270 ) ;
return 0 ;
}
static int F_167 ( void * V_317 , struct V_257 * V_327 )
{
int V_328 = F_162 ( V_327 ) ;
if ( V_328 > 0 )
F_166 ( V_327 , V_328 ) ;
return 0 ;
}
static int F_168 ( void * V_317 , struct V_257 * V_327 )
{
return F_166 ( V_327 , 1 ) ;
}
int F_169 ( struct V_6 * V_7 , char * V_133 ,
unsigned int * V_286 , const char * const * V_314 ,
const char * V_315 , bool V_329 ,
struct V_257 * * V_330 )
{
struct V_257 * V_291 ;
int V_30 ;
if ( V_330 )
* V_330 = NULL ;
V_30 = F_160 ( V_7 , V_314 , V_315 , F_161 , NULL ) ;
if ( V_30 != 1 ) {
F_93 ( L_65 , V_133 ) ;
return 0 ;
}
V_291 = F_170 ( V_133 , V_286 ) ;
if ( ! V_291 )
return - V_76 ;
V_30 = F_145 ( V_7 , 0 , V_291 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_160 ( V_7 , V_314 , V_315 ,
( T_6 ) V_331 , V_291 ) ;
if ( V_30 < 0 )
return V_30 ;
F_166 ( V_291 , 0 ) ;
if ( V_329 )
F_160 ( V_7 , V_314 , V_315 ,
V_286 ? F_167 : F_168 , V_291 ) ;
if ( V_330 )
* V_330 = V_291 ;
return 0 ;
}
static int F_171 ( struct V_257 * V_258 ,
struct V_259 * V_260 )
{
static const char * const V_332 [] = {
L_66 , L_67 , L_68
} ;
unsigned int V_236 ;
V_260 -> type = V_333 ;
V_260 -> V_263 = 1 ;
V_260 -> V_264 . V_334 . V_299 = 3 ;
V_236 = V_260 -> V_264 . V_334 . V_293 ;
if ( V_236 >= 3 )
V_236 = 2 ;
strcpy ( V_260 -> V_264 . V_334 . V_133 , V_332 [ V_236 ] ) ;
return 0 ;
}
static int F_172 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_335 * V_336 = F_127 ( V_258 ) ;
V_270 -> V_264 . V_334 . V_293 [ 0 ] = V_336 -> V_337 ;
return 0 ;
}
static int F_173 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_335 * V_336 = F_127 ( V_258 ) ;
unsigned int V_338 = V_336 -> V_337 ;
V_336 -> V_337 = V_270 -> V_264 . V_334 . V_293 [ 0 ] ;
if ( V_336 -> V_337 > V_339 )
V_336 -> V_337 = V_339 ;
if ( V_338 == V_336 -> V_337 )
return 0 ;
F_174 ( V_336 ) ;
return 1 ;
}
int F_175 ( struct V_6 * V_7 ,
struct V_335 * V_336 ,
bool V_340 )
{
struct V_257 * V_291 ;
if ( ! V_336 -> V_336 || ! V_336 -> V_341 )
return 0 ;
F_176 ( V_336 -> V_341 , V_336 -> V_336 , V_7 ) ;
V_336 -> V_7 = V_7 ;
V_336 -> V_337 = V_339 ;
if ( ! V_340 )
return 0 ;
V_291 = F_177 ( & V_342 , V_336 ) ;
if ( ! V_291 )
return - V_76 ;
return F_145 ( V_7 , 0 , V_291 ) ;
}
void F_174 ( struct V_335 * V_336 )
{
if ( ! V_336 -> V_336 || ! V_336 -> V_7 )
return;
switch ( V_336 -> V_337 ) {
case V_339 :
F_178 ( V_336 -> V_341 ) ;
break;
default:
V_336 -> V_336 ( V_336 -> V_7 , V_336 -> V_337 ) ;
break;
}
}
int F_179 ( struct V_257 * V_258 ,
struct V_259 * V_260 )
{
int V_261 = F_129 ( V_258 ) ;
V_260 -> type = V_343 ;
V_260 -> V_263 = V_261 == 3 ? 2 : 1 ;
V_260 -> V_264 . integer . V_265 = 0 ;
V_260 -> V_264 . integer . V_266 = 1 ;
return 0 ;
}
int F_180 ( struct V_257 * V_258 ,
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
int F_181 ( struct V_257 * V_258 ,
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
F_182 ( V_7 , V_19 ) ;
F_18 ( V_7 ) ;
return V_272 ;
}
int F_183 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
long * V_271 = V_270 -> V_264 . integer . V_264 ;
F_184 ( V_7 , * V_271 ) ;
return F_181 ( V_258 , V_270 ) ;
}
int F_185 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
unsigned long V_344 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_344 = V_258 -> V_297 ;
V_258 -> V_297 = V_344 & ~ V_345 ;
V_30 = F_180 ( V_258 , V_270 ) ;
V_258 -> V_297 = V_344 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_186 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
unsigned long V_344 ;
int V_12 , V_346 , V_30 = 0 , V_272 = 0 ;
F_2 ( & V_7 -> V_183 ) ;
V_344 = V_258 -> V_297 ;
V_346 = ( V_344 & V_345 ) >> V_347 ;
for ( V_12 = 0 ; V_12 < V_346 ; V_12 ++ ) {
V_258 -> V_297 = ( V_344 & ~ V_345 ) |
( V_12 << V_347 ) ;
V_30 = F_181 ( V_258 , V_270 ) ;
if ( V_30 < 0 )
break;
V_272 |= V_30 ;
}
V_258 -> V_297 = V_344 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 < 0 ? V_30 : V_272 ;
}
int F_187 ( struct V_257 * V_258 ,
struct V_259 * V_260 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
struct V_348 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_348 * ) V_258 -> V_297 ;
V_258 -> V_297 = * V_135 -> V_349 ;
V_30 = V_135 -> V_33 -> V_222 ( V_258 , V_260 ) ;
V_258 -> V_297 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_188 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
struct V_348 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_348 * ) V_258 -> V_297 ;
V_258 -> V_297 = * V_135 -> V_349 ;
V_30 = V_135 -> V_33 -> V_350 ( V_258 , V_270 ) ;
V_258 -> V_297 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_189 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
struct V_348 * V_135 ;
unsigned long * V_351 ;
int V_30 = 0 , V_272 = 0 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_348 * ) V_258 -> V_297 ;
for ( V_351 = V_135 -> V_349 ; * V_351 ; V_351 ++ ) {
V_258 -> V_297 = * V_351 ;
V_30 = V_135 -> V_33 -> V_326 ( V_258 , V_270 ) ;
if ( V_30 < 0 )
break;
V_272 |= V_30 ;
}
V_258 -> V_297 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 < 0 ? V_30 : V_272 ;
}
int F_190 ( struct V_257 * V_258 , int V_273 ,
unsigned int V_274 , unsigned int T_5 * V_286 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
struct V_348 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_348 * ) V_258 -> V_297 ;
V_258 -> V_297 = * V_135 -> V_349 ;
V_30 = V_135 -> V_33 -> V_286 ( V_258 , V_273 , V_274 , V_286 ) ;
V_258 -> V_297 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
static int F_191 ( struct V_257 * V_258 ,
struct V_259 * V_260 )
{
V_260 -> type = V_352 ;
V_260 -> V_263 = 1 ;
return 0 ;
}
static int F_192 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
V_270 -> V_264 . V_353 . V_354 [ 0 ] = V_355 |
V_356 |
V_357 |
V_358 ;
V_270 -> V_264 . V_353 . V_354 [ 1 ] = V_359 |
V_360 ;
return 0 ;
}
static int F_193 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
V_270 -> V_264 . V_353 . V_354 [ 0 ] = V_355 |
V_356 |
V_361 ;
return 0 ;
}
static int F_194 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
int V_220 = V_258 -> V_297 ;
struct V_187 * V_362 = F_27 ( & V_7 -> V_174 , V_220 ) ;
V_270 -> V_264 . V_353 . V_354 [ 0 ] = V_362 -> V_354 & 0xff ;
V_270 -> V_264 . V_353 . V_354 [ 1 ] = ( V_362 -> V_354 >> 8 ) & 0xff ;
V_270 -> V_264 . V_353 . V_354 [ 2 ] = ( V_362 -> V_354 >> 16 ) & 0xff ;
V_270 -> V_264 . V_353 . V_354 [ 3 ] = ( V_362 -> V_354 >> 24 ) & 0xff ;
return 0 ;
}
static unsigned short F_195 ( unsigned int V_363 )
{
unsigned short V_23 = 0 ;
if ( V_363 & V_355 )
V_23 |= V_364 ;
if ( V_363 & V_356 )
V_23 |= V_365 ;
if ( V_363 & V_355 ) {
if ( ( V_363 & V_366 ) ==
V_361 )
V_23 |= V_367 ;
} else {
if ( ( V_363 & V_368 ) ==
V_357 )
V_23 |= V_367 ;
if ( ! ( V_363 & V_358 ) )
V_23 |= V_369 ;
if ( V_363 & ( V_360 << 8 ) )
V_23 |= V_370 ;
V_23 |= V_363 & ( V_359 << 8 ) ;
}
return V_23 ;
}
static unsigned int F_196 ( unsigned short V_23 )
{
unsigned int V_363 = 0 ;
if ( V_23 & V_365 )
V_363 |= V_356 ;
if ( V_23 & V_364 )
V_363 |= V_355 ;
if ( V_363 & V_355 ) {
if ( V_363 & V_367 )
V_363 |= V_361 ;
} else {
if ( V_23 & V_367 )
V_363 |= V_357 ;
if ( ! ( V_23 & V_369 ) )
V_363 |= V_358 ;
if ( V_23 & V_370 )
V_363 |= ( V_360 << 8 ) ;
V_363 |= V_23 & ( 0x7f << 8 ) ;
}
return V_363 ;
}
static void F_197 ( struct V_6 * V_7 , T_2 V_19 ,
int V_21 , int V_23 )
{
const T_2 * V_371 ;
F_198 ( V_7 , V_19 , 0 , V_21 , V_23 ) ;
V_371 = V_7 -> V_312 ;
if ( ! V_371 )
return;
for (; * V_371 ; V_371 ++ )
F_198 ( V_7 , * V_371 , 0 , V_21 , V_23 ) ;
}
static inline void F_199 ( struct V_6 * V_7 , T_2 V_19 ,
int V_372 , int V_373 )
{
if ( V_372 != - 1 )
F_197 ( V_7 , V_19 , V_374 , V_372 ) ;
if ( V_373 != - 1 )
F_197 ( V_7 , V_19 , V_375 , V_373 ) ;
}
static int F_200 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
int V_220 = V_258 -> V_297 ;
struct V_187 * V_362 = F_27 ( & V_7 -> V_174 , V_220 ) ;
T_2 V_19 = V_362 -> V_19 ;
unsigned short V_23 ;
int V_272 ;
F_2 ( & V_7 -> V_182 ) ;
V_362 -> V_354 = V_270 -> V_264 . V_353 . V_354 [ 0 ] |
( ( unsigned int ) V_270 -> V_264 . V_353 . V_354 [ 1 ] << 8 ) |
( ( unsigned int ) V_270 -> V_264 . V_353 . V_354 [ 2 ] << 16 ) |
( ( unsigned int ) V_270 -> V_264 . V_353 . V_354 [ 3 ] << 24 ) ;
V_23 = F_195 ( V_362 -> V_354 ) ;
V_23 |= V_362 -> V_376 & 1 ;
V_272 = V_362 -> V_376 != V_23 ;
V_362 -> V_376 = V_23 ;
if ( V_272 && V_19 != ( T_3 ) - 1 )
F_199 ( V_7 , V_19 , V_23 & 0xff , ( V_23 >> 8 ) & 0xff ) ;
F_4 ( & V_7 -> V_182 ) ;
return V_272 ;
}
static int F_201 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
int V_220 = V_258 -> V_297 ;
struct V_187 * V_362 = F_27 ( & V_7 -> V_174 , V_220 ) ;
V_270 -> V_264 . integer . V_264 [ 0 ] = V_362 -> V_376 & V_377 ;
return 0 ;
}
static inline void F_202 ( struct V_6 * V_7 , T_2 V_19 ,
int V_372 , int V_373 )
{
F_199 ( V_7 , V_19 , V_372 , V_373 ) ;
if ( ( F_34 ( V_7 , V_19 ) & V_378 ) &&
( V_372 & V_377 ) )
F_123 ( V_7 , V_19 , V_229 , 0 ,
V_248 , 0 ) ;
}
static int F_203 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
int V_220 = V_258 -> V_297 ;
struct V_187 * V_362 = F_27 ( & V_7 -> V_174 , V_220 ) ;
T_2 V_19 = V_362 -> V_19 ;
unsigned short V_23 ;
int V_272 ;
F_2 ( & V_7 -> V_182 ) ;
V_23 = V_362 -> V_376 & ~ V_377 ;
if ( V_270 -> V_264 . integer . V_264 [ 0 ] )
V_23 |= V_377 ;
V_272 = V_362 -> V_376 != V_23 ;
V_362 -> V_376 = V_23 ;
if ( V_272 && V_19 != ( T_3 ) - 1 )
F_202 ( V_7 , V_19 , V_23 & 0xff , - 1 ) ;
F_4 ( & V_7 -> V_182 ) ;
return V_272 ;
}
int F_204 ( struct V_6 * V_7 ,
T_2 V_379 ,
T_2 V_380 )
{
int V_30 ;
struct V_257 * V_291 ;
struct V_381 * V_382 ;
int V_220 ;
struct V_187 * V_362 ;
V_220 = F_144 ( V_7 , L_69 ) ;
if ( V_220 < 0 ) {
F_13 ( V_25 L_70 ) ;
return - V_181 ;
}
V_362 = F_37 ( & V_7 -> V_174 ) ;
for ( V_382 = V_383 ; V_382 -> V_133 ; V_382 ++ ) {
V_291 = F_177 ( V_382 , V_7 ) ;
if ( ! V_291 )
return - V_76 ;
V_291 -> V_126 . V_236 = V_220 ;
V_291 -> V_297 = V_7 -> V_174 . V_48 - 1 ;
V_30 = F_145 ( V_7 , V_379 , V_291 ) ;
if ( V_30 < 0 )
return V_30 ;
}
V_362 -> V_19 = V_380 ;
V_362 -> V_376 = F_21 ( V_7 , V_380 , 0 ,
V_384 , 0 ) ;
V_362 -> V_354 = F_196 ( V_362 -> V_376 ) ;
return 0 ;
}
struct V_187 * F_205 ( struct V_6 * V_7 ,
T_2 V_19 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_174 . V_48 ; V_12 ++ ) {
struct V_187 * V_362 =
F_27 ( & V_7 -> V_174 , V_12 ) ;
if ( V_362 -> V_19 == V_19 )
return V_362 ;
}
return NULL ;
}
void F_206 ( struct V_6 * V_7 , int V_220 )
{
struct V_187 * V_362 = F_27 ( & V_7 -> V_174 , V_220 ) ;
F_2 ( & V_7 -> V_182 ) ;
V_362 -> V_19 = ( T_3 ) - 1 ;
F_4 ( & V_7 -> V_182 ) ;
}
void F_207 ( struct V_6 * V_7 , int V_220 , T_2 V_19 )
{
struct V_187 * V_362 = F_27 ( & V_7 -> V_174 , V_220 ) ;
unsigned short V_23 ;
F_2 ( & V_7 -> V_182 ) ;
if ( V_362 -> V_19 != V_19 ) {
V_362 -> V_19 = V_19 ;
V_23 = V_362 -> V_376 ;
F_202 ( V_7 , V_19 , V_23 & 0xff , ( V_23 >> 8 ) & 0xff ) ;
}
F_4 ( & V_7 -> V_182 ) ;
}
static int F_208 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_385 * V_386 = F_127 ( V_258 ) ;
V_270 -> V_264 . integer . V_264 [ 0 ] = V_386 -> V_387 ;
return 0 ;
}
static int F_209 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_385 * V_386 = F_127 ( V_258 ) ;
V_386 -> V_387 = ! ! V_270 -> V_264 . integer . V_264 [ 0 ] ;
return 0 ;
}
int F_210 ( struct V_6 * V_7 ,
struct V_385 * V_386 )
{
if ( ! V_386 -> V_388 )
return 0 ;
return F_145 ( V_7 , V_386 -> V_388 ,
F_177 ( & V_389 , V_386 ) ) ;
}
static int F_211 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
V_270 -> V_264 . integer . V_264 [ 0 ] = V_7 -> V_390 ;
return 0 ;
}
static int F_212 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
T_2 V_19 = V_258 -> V_297 ;
unsigned int V_23 = ! ! V_270 -> V_264 . integer . V_264 [ 0 ] ;
int V_272 ;
F_2 ( & V_7 -> V_182 ) ;
V_272 = V_7 -> V_390 != V_23 ;
if ( V_272 ) {
V_7 -> V_390 = V_23 ;
F_198 ( V_7 , V_19 , 0 ,
V_374 , V_23 ) ;
}
F_4 ( & V_7 -> V_182 ) ;
return V_272 ;
}
static int F_213 ( struct V_257 * V_258 ,
struct V_269 * V_270 )
{
struct V_6 * V_7 = F_127 ( V_258 ) ;
T_2 V_19 = V_258 -> V_297 ;
unsigned short V_23 ;
unsigned int V_363 ;
V_23 = F_21 ( V_7 , V_19 , 0 , V_384 , 0 ) ;
V_363 = F_196 ( V_23 ) ;
V_270 -> V_264 . V_353 . V_354 [ 0 ] = V_363 ;
V_270 -> V_264 . V_353 . V_354 [ 1 ] = V_363 >> 8 ;
V_270 -> V_264 . V_353 . V_354 [ 2 ] = V_363 >> 16 ;
V_270 -> V_264 . V_353 . V_354 [ 3 ] = V_363 >> 24 ;
return 0 ;
}
int F_214 ( struct V_6 * V_7 , T_2 V_19 )
{
int V_30 ;
struct V_257 * V_291 ;
struct V_381 * V_382 ;
int V_220 ;
V_220 = F_144 ( V_7 , L_71 ) ;
if ( V_220 < 0 ) {
F_13 ( V_25 L_72 ) ;
return - V_181 ;
}
for ( V_382 = V_391 ; V_382 -> V_133 ; V_382 ++ ) {
V_291 = F_177 ( V_382 , V_7 ) ;
if ( ! V_291 )
return - V_76 ;
V_291 -> V_297 = V_19 ;
V_30 = F_145 ( V_7 , V_19 , V_291 ) ;
if ( V_30 < 0 )
return V_30 ;
}
V_7 -> V_390 =
F_21 ( V_7 , V_19 , 0 ,
V_384 , 0 ) &
V_377 ;
return 0 ;
}
int F_198 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 , unsigned int V_21 , unsigned int V_22 )
{
int V_30 = F_22 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
struct V_185 * V_135 ;
T_1 V_219 ;
if ( V_30 < 0 )
return V_30 ;
V_21 = V_21 | ( V_22 >> 8 ) ;
V_22 &= 0xff ;
V_219 = F_215 ( V_19 , V_21 ) ;
F_2 ( & V_7 -> V_29 -> V_32 ) ;
V_135 = F_107 ( & V_7 -> V_176 , V_219 ) ;
if ( V_135 )
V_135 -> V_23 = V_22 ;
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return 0 ;
}
int F_216 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 , unsigned int V_21 , unsigned int V_22 )
{
struct V_185 * V_135 ;
T_1 V_219 ;
V_21 = V_21 | ( V_22 >> 8 ) ;
V_22 &= 0xff ;
V_219 = F_215 ( V_19 , V_21 ) ;
F_2 ( & V_7 -> V_29 -> V_32 ) ;
V_135 = F_106 ( & V_7 -> V_176 , V_219 ) ;
if ( V_135 && V_135 -> V_23 == V_22 ) {
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return 0 ;
}
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return F_198 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
}
void F_217 ( struct V_6 * V_7 )
{
struct V_185 * V_253 = V_7 -> V_176 . V_218 . V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_176 . V_218 . V_48 ; V_12 ++ , V_253 ++ ) {
T_1 V_219 = V_253 -> V_219 ;
if ( ! V_219 )
continue;
F_22 ( V_7 , F_218 ( V_219 ) , 0 ,
F_219 ( V_219 ) , V_253 -> V_23 ) ;
}
}
void F_220 ( struct V_6 * V_7 ,
const struct V_40 * V_41 )
{
for (; V_41 -> V_19 ; V_41 ++ )
F_198 ( V_7 , V_41 -> V_19 , 0 , V_41 -> V_21 ,
V_41 -> V_42 ) ;
}
void F_221 ( struct V_6 * V_7 , T_2 V_392 ,
unsigned int V_393 ,
bool V_394 )
{
T_2 V_19 = V_7 -> V_154 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_153 ; V_12 ++ , V_19 ++ ) {
unsigned int V_62 = F_34 ( V_7 , V_19 ) ;
if ( ! ( V_62 & V_395 ) )
continue;
if ( V_394 && V_393 == V_396 &&
F_35 ( V_62 ) == V_82 &&
( F_114 ( V_7 , V_19 ) & V_397 ) ) {
int V_398 = F_21 ( V_7 , V_19 , 0 ,
V_399 , 0 ) ;
if ( V_398 & 0x02 )
continue;
}
F_22 ( V_7 , V_19 , 0 , V_400 ,
V_393 ) ;
}
if ( V_393 == V_195 ) {
unsigned long V_401 ;
int V_402 ;
V_401 = V_403 + F_222 ( 500 ) ;
do {
V_402 = F_21 ( V_7 , V_392 , 0 ,
V_404 , 0 ) ;
if ( V_402 == V_393 )
break;
F_101 ( 1 ) ;
} while ( F_223 ( V_401 , V_403 ) );
}
}
static void F_94 ( struct V_6 * V_7 , T_2 V_392 ,
unsigned int V_393 )
{
if ( V_7 -> V_96 . V_405 ) {
V_7 -> V_96 . V_405 ( V_7 , V_392 , V_393 ) ;
return;
}
if ( V_393 == V_396 )
F_101 ( 100 ) ;
F_21 ( V_7 , V_392 , 0 , V_400 ,
V_393 ) ;
F_221 ( V_7 , V_392 , V_393 , true ) ;
}
static void F_224 ( struct V_6 * V_7 )
{
if ( V_7 -> V_406 . V_4 )
F_23 ( V_7 , V_7 -> V_406 . V_4 ) ;
}
static inline void F_224 ( struct V_6 * V_7 ) {}
static void F_225 ( struct V_6 * V_7 )
{
if ( V_7 -> V_96 . V_407 )
V_7 -> V_96 . V_407 ( V_7 , V_408 ) ;
F_105 ( V_7 ) ;
F_94 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_396 ) ;
#ifdef F_86
F_226 ( V_7 ) ;
F_87 ( & V_7 -> V_171 ) ;
V_7 -> V_409 = 0 ;
V_7 -> V_410 = 0 ;
V_7 -> V_411 = V_403 ;
#endif
}
static void F_227 ( struct V_6 * V_7 )
{
F_94 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_195 ) ;
F_80 ( V_7 ) ;
F_82 ( V_7 ) ;
F_224 ( V_7 ) ;
F_228 ( V_7 ) ;
if ( V_7 -> V_96 . V_412 )
V_7 -> V_96 . V_412 ( V_7 ) ;
else {
if ( V_7 -> V_96 . V_413 )
V_7 -> V_96 . V_413 ( V_7 ) ;
F_124 ( V_7 ) ;
F_217 ( V_7 ) ;
}
}
int F_229 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
int V_30 = F_230 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_73
L_74 , V_7 -> V_24 , V_30 ) ;
V_30 = F_155 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25
L_75 ) ;
return V_30 ;
}
}
}
return 0 ;
}
int F_230 ( struct V_6 * V_7 )
{
int V_30 = 0 ;
F_224 ( V_7 ) ;
if ( V_7 -> V_96 . V_413 )
V_30 = V_7 -> V_96 . V_413 ( V_7 ) ;
if ( ! V_30 && V_7 -> V_96 . V_414 )
V_30 = V_7 -> V_96 . V_414 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
unsigned int F_231 ( unsigned int V_415 ,
unsigned int V_416 ,
unsigned int V_201 ,
unsigned int V_417 ,
unsigned short V_418 )
{
int V_12 ;
unsigned int V_23 = 0 ;
for ( V_12 = 0 ; V_419 [ V_12 ] . V_420 ; V_12 ++ )
if ( V_419 [ V_12 ] . V_420 == V_415 ) {
V_23 = V_419 [ V_12 ] . V_421 ;
break;
}
if ( ! V_419 [ V_12 ] . V_420 ) {
F_93 ( L_76 , V_415 ) ;
return 0 ;
}
if ( V_416 == 0 || V_416 > 8 ) {
F_93 ( L_77 , V_416 ) ;
return 0 ;
}
V_23 |= V_416 - 1 ;
switch ( F_232 ( V_201 ) ) {
case 8 :
V_23 |= V_422 ;
break;
case 16 :
V_23 |= V_423 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_417 >= 32 || V_201 == V_424 )
V_23 |= V_425 ;
else if ( V_417 >= 24 )
V_23 |= V_426 ;
else
V_23 |= V_427 ;
break;
default:
F_93 ( L_78 ,
F_232 ( V_201 ) ) ;
return 0 ;
}
if ( V_418 & V_365 )
V_23 |= V_428 ;
return V_23 ;
}
static unsigned int F_233 ( struct V_6 * V_7 , T_2 V_19 )
{
unsigned int V_23 = 0 ;
if ( V_19 != V_7 -> V_127 &&
( F_34 ( V_7 , V_19 ) & V_429 ) )
V_23 = F_25 ( V_7 , V_19 , V_430 ) ;
if ( ! V_23 || V_23 == - 1 )
V_23 = F_25 ( V_7 , V_7 -> V_127 , V_430 ) ;
if ( ! V_23 || V_23 == - 1 )
return 0 ;
return V_23 ;
}
static unsigned int F_234 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_115 ( V_7 , V_19 , F_235 ( V_19 ) ,
F_233 ) ;
}
static unsigned int F_236 ( struct V_6 * V_7 , T_2 V_19 )
{
unsigned int V_307 = F_25 ( V_7 , V_19 , V_431 ) ;
if ( ! V_307 || V_307 == - 1 )
V_307 = F_25 ( V_7 , V_7 -> V_127 , V_431 ) ;
if ( ! V_307 || V_307 == - 1 )
return 0 ;
return V_307 ;
}
static unsigned int F_237 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_115 ( V_7 , V_19 , F_238 ( V_19 ) ,
F_236 ) ;
}
int F_239 ( struct V_6 * V_7 , T_2 V_19 ,
T_1 * V_432 , T_8 * V_433 , unsigned int * V_434 )
{
unsigned int V_12 , V_23 , V_62 ;
V_62 = F_34 ( V_7 , V_19 ) ;
V_23 = F_234 ( V_7 , V_19 ) ;
if ( V_432 ) {
T_1 V_435 = 0 ;
for ( V_12 = 0 ; V_12 < V_436 ; V_12 ++ ) {
if ( V_23 & ( 1 << V_12 ) )
V_435 |= V_419 [ V_12 ] . V_437 ;
}
if ( V_435 == 0 ) {
F_33 ( V_25 L_79
L_80 ,
V_19 , V_23 ,
( V_62 & V_429 ) ? 1 : 0 ) ;
return - V_70 ;
}
* V_432 = V_435 ;
}
if ( V_433 || V_434 ) {
T_8 V_438 = 0 ;
unsigned int V_307 , V_439 ;
V_307 = F_237 ( V_7 , V_19 ) ;
if ( ! V_307 )
return - V_70 ;
V_439 = 0 ;
if ( V_307 & V_440 ) {
if ( V_23 & V_441 ) {
V_438 |= V_442 ;
V_439 = 8 ;
}
if ( V_23 & V_443 ) {
V_438 |= V_444 ;
V_439 = 16 ;
}
if ( V_62 & V_445 ) {
if ( V_23 & V_446 )
V_438 |= V_447 ;
if ( V_23 & ( V_448 | V_449 ) )
V_438 |= V_450 ;
if ( V_23 & V_449 )
V_439 = 24 ;
else if ( V_23 & V_448 )
V_439 = 20 ;
} else if ( V_23 & ( V_448 | V_449 |
V_446 ) ) {
V_438 |= V_450 ;
if ( V_23 & V_446 )
V_439 = 32 ;
else if ( V_23 & V_449 )
V_439 = 24 ;
else if ( V_23 & V_448 )
V_439 = 20 ;
}
}
if ( V_307 & V_451 ) {
V_438 |= V_452 ;
if ( ! V_439 )
V_439 = 32 ;
}
if ( V_307 == V_453 ) {
V_438 |= V_442 ;
V_439 = 8 ;
}
if ( V_438 == 0 ) {
F_33 ( V_25 L_81
L_82
L_83 ,
V_19 , V_23 ,
( V_62 & V_429 ) ? 1 : 0 ,
V_307 ) ;
return - V_70 ;
}
if ( V_433 )
* V_433 = V_438 ;
if ( V_434 )
* V_434 = V_439 ;
}
return 0 ;
}
int F_240 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_201 )
{
int V_12 ;
unsigned int V_23 = 0 , V_415 , V_454 ;
V_23 = F_234 ( V_7 , V_19 ) ;
if ( ! V_23 )
return 0 ;
V_415 = V_201 & 0xff00 ;
for ( V_12 = 0 ; V_12 < V_436 ; V_12 ++ )
if ( V_419 [ V_12 ] . V_421 == V_415 ) {
if ( V_23 & ( 1 << V_12 ) )
break;
return 0 ;
}
if ( V_12 >= V_436 )
return 0 ;
V_454 = F_237 ( V_7 , V_19 ) ;
if ( ! V_454 )
return 0 ;
if ( V_454 & V_440 ) {
switch ( V_201 & 0xf0 ) {
case 0x00 :
if ( ! ( V_23 & V_441 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_23 & V_443 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_23 & V_448 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_23 & V_449 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_23 & V_446 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_241 ( struct V_455 * V_456 ,
struct V_6 * V_7 ,
struct V_457 * V_458 )
{
return 0 ;
}
static int F_242 ( struct V_455 * V_456 ,
struct V_6 * V_7 ,
unsigned int V_199 ,
unsigned int V_201 ,
struct V_457 * V_458 )
{
F_100 ( V_7 , V_456 -> V_19 , V_199 , 0 , V_201 ) ;
return 0 ;
}
static int F_243 ( struct V_455 * V_456 ,
struct V_6 * V_7 ,
struct V_457 * V_458 )
{
F_244 ( V_7 , V_456 -> V_19 ) ;
return 0 ;
}
static int F_245 ( struct V_6 * V_7 ,
struct V_455 * V_222 )
{
int V_30 ;
if ( V_222 -> V_19 && ( ! V_222 -> V_435 || ! V_222 -> V_438 ) ) {
V_30 = F_239 ( V_7 , V_222 -> V_19 ,
V_222 -> V_435 ? NULL : & V_222 -> V_435 ,
V_222 -> V_438 ? NULL : & V_222 -> V_438 ,
V_222 -> V_417 ? NULL : & V_222 -> V_417 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( V_222 -> V_33 . V_459 == NULL )
V_222 -> V_33 . V_459 = F_241 ;
if ( V_222 -> V_33 . V_460 == NULL )
V_222 -> V_33 . V_460 = F_241 ;
if ( V_222 -> V_33 . V_461 == NULL ) {
if ( F_29 ( ! V_222 -> V_19 ) )
return - V_54 ;
V_222 -> V_33 . V_461 = F_242 ;
}
if ( V_222 -> V_33 . V_462 == NULL ) {
if ( F_29 ( ! V_222 -> V_19 ) )
return - V_54 ;
V_222 -> V_33 . V_462 = F_243 ;
}
return 0 ;
}
int F_246 ( struct V_6 * V_7 ,
struct V_455 * V_456 ,
unsigned int V_454 ,
unsigned int V_201 ,
struct V_457 * V_458 )
{
int V_252 ;
F_2 ( & V_7 -> V_29 -> V_117 ) ;
V_252 = V_456 -> V_33 . V_461 ( V_456 , V_7 , V_454 , V_201 , V_458 ) ;
if ( V_252 >= 0 )
F_104 ( V_7 ) ;
F_4 ( & V_7 -> V_29 -> V_117 ) ;
return V_252 ;
}
void F_247 ( struct V_6 * V_7 ,
struct V_455 * V_456 ,
struct V_457 * V_458 )
{
F_2 ( & V_7 -> V_29 -> V_117 ) ;
V_456 -> V_33 . V_462 ( V_456 , V_7 , V_458 ) ;
F_4 ( & V_7 -> V_29 -> V_117 ) ;
}
static int F_248 ( struct V_28 * V_29 , int type )
{
static int V_463 [ V_464 ] [ 5 ] = {
[ V_465 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_466 ] = { 1 , - 1 } ,
[ V_467 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_468 ] = { 6 , - 1 } ,
} ;
int V_12 ;
if ( type >= V_464 ) {
F_33 ( V_73 L_84 , type ) ;
return - V_54 ;
}
for ( V_12 = 0 ; V_463 [ type ] [ V_12 ] >= 0 ; V_12 ++ )
if ( ! F_249 ( V_463 [ type ] [ V_12 ] , V_29 -> V_309 ) )
return V_463 [ type ] [ V_12 ] ;
for ( V_12 = 10 ; V_12 < 32 ; V_12 ++ ) {
if ( ! F_249 ( V_12 , V_29 -> V_309 ) )
return V_12 ;
}
F_33 ( V_73 L_85 ,
V_469 [ type ] ) ;
return - V_470 ;
}
static int F_250 ( struct V_6 * V_7 , struct V_304 * V_301 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
struct V_455 * V_222 ;
int V_454 , V_30 ;
if ( F_29 ( ! V_301 -> V_133 ) )
return - V_54 ;
for ( V_454 = 0 ; V_454 < 2 ; V_454 ++ ) {
V_222 = & V_301 -> V_454 [ V_454 ] ;
if ( V_222 -> V_471 ) {
V_30 = F_245 ( V_7 , V_222 ) ;
if ( V_30 < 0 )
return V_30 ;
}
}
return V_29 -> V_33 . V_472 ( V_29 , V_7 , V_301 ) ;
}
int F_251 ( struct V_6 * V_7 )
{
unsigned int V_301 ;
int V_30 ;
if ( ! V_7 -> V_303 ) {
if ( ! V_7 -> V_96 . V_473 )
return 0 ;
V_30 = V_7 -> V_96 . V_473 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_86
L_74 , V_7 -> V_24 , V_30 ) ;
V_30 = F_155 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25
L_75 ) ;
return V_30 ;
}
}
}
for ( V_301 = 0 ; V_301 < V_7 -> V_303 ; V_301 ++ ) {
struct V_304 * V_305 = & V_7 -> V_306 [ V_301 ] ;
int V_474 ;
if ( ! V_305 -> V_454 [ 0 ] . V_471 && ! V_305 -> V_454 [ 1 ] . V_471 )
continue;
if ( ! V_305 -> V_301 ) {
V_474 = F_248 ( V_7 -> V_29 , V_305 -> V_475 ) ;
if ( V_474 < 0 )
continue;
V_305 -> V_101 = V_474 ;
V_30 = F_250 ( V_7 , V_305 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_87
L_88 ,
V_474 , V_7 -> V_24 ) ;
continue;
}
}
}
return 0 ;
}
int T_9 F_252 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
int V_30 = F_251 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
}
return 0 ;
}
int F_253 ( struct V_6 * V_7 ,
int V_476 , const char * const * V_477 ,
const struct V_478 * V_123 )
{
if ( V_7 -> V_115 && V_477 ) {
int V_12 ;
for ( V_12 = 0 ; V_12 < V_476 ; V_12 ++ ) {
if ( V_477 [ V_12 ] &&
! strcmp ( V_7 -> V_115 , V_477 [ V_12 ] ) ) {
F_19 ( V_479 L_89
L_90 , V_477 [ V_12 ] ) ;
return V_12 ;
}
}
}
if ( ! V_7 -> V_29 -> V_114 || ! V_123 )
return - 1 ;
V_123 = F_254 ( V_7 -> V_29 -> V_114 , V_123 ) ;
if ( ! V_123 )
return - 1 ;
if ( V_123 -> V_264 >= 0 && V_123 -> V_264 < V_476 ) {
#ifdef F_255
char V_137 [ 10 ] ;
const char * V_480 = NULL ;
if ( V_477 )
V_480 = V_477 [ V_123 -> V_264 ] ;
if ( ! V_480 ) {
sprintf ( V_137 , L_91 , V_123 -> V_264 ) ;
V_480 = V_137 ;
}
F_93 ( V_479 L_92
L_93 ,
V_480 , V_123 -> V_481 , V_123 -> V_294 ,
( V_123 -> V_133 ? V_123 -> V_133 : L_94 ) ) ;
#endif
return V_123 -> V_264 ;
}
return - 1 ;
}
int F_256 ( struct V_6 * V_7 ,
int V_476 , const char * const * V_477 ,
const struct V_478 * V_123 )
{
const struct V_478 * V_213 ;
for ( V_213 = V_123 ; V_213 -> V_481 ; V_213 ++ ) {
unsigned int V_61 = 0xffff0000 | V_213 -> V_482 ;
unsigned int V_126 = ( V_213 -> V_294 | ( V_213 -> V_481 << 16 ) ) & V_61 ;
if ( ( V_7 -> V_191 & V_61 ) == V_126 )
break;
}
if ( ! V_213 -> V_481 )
return - 1 ;
V_123 = V_213 ;
if ( V_123 -> V_264 >= 0 && V_123 -> V_264 < V_476 ) {
#ifdef F_255
char V_137 [ 10 ] ;
const char * V_480 = NULL ;
if ( V_477 )
V_480 = V_477 [ V_123 -> V_264 ] ;
if ( ! V_480 ) {
sprintf ( V_137 , L_91 , V_123 -> V_264 ) ;
V_480 = V_137 ;
}
F_93 ( V_479 L_92
L_93 ,
V_480 , V_123 -> V_481 , V_123 -> V_294 ,
( V_123 -> V_133 ? V_123 -> V_133 : L_94 ) ) ;
#endif
return V_123 -> V_264 ;
}
return - 1 ;
}
int F_257 ( struct V_6 * V_7 ,
const struct V_381 * V_483 )
{
int V_30 ;
for (; V_483 -> V_133 ; V_483 ++ ) {
struct V_257 * V_291 ;
int V_24 = 0 , V_220 = 0 ;
if ( V_483 -> V_289 == - 1 )
continue;
for (; ; ) {
V_291 = F_177 ( V_483 , V_7 ) ;
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
else if ( ! V_220 && ! V_483 -> V_236 ) {
V_220 = F_144 ( V_7 ,
V_483 -> V_133 ) ;
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
if ( ! V_7 -> V_409 || V_7 -> V_484 ) {
V_7 -> V_410 = 0 ;
return;
}
F_258 ( V_7 ) ;
F_225 ( V_7 ) ;
if ( V_29 -> V_33 . V_485 )
V_29 -> V_33 . V_485 ( V_29 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
V_7 -> V_484 ++ ;
V_7 -> V_409 = 1 ;
V_7 -> V_411 = V_403 ;
}
void F_226 ( struct V_6 * V_7 )
{
unsigned long V_486 = V_403 - V_7 -> V_411 ;
if ( V_7 -> V_409 )
V_7 -> V_487 += V_486 ;
else
V_7 -> V_488 += V_486 ;
V_7 -> V_411 += V_486 ;
}
void F_15 ( struct V_6 * V_7 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
V_7 -> V_484 ++ ;
if ( V_7 -> V_409 || V_7 -> V_410 )
return;
F_259 ( V_7 ) ;
F_226 ( V_7 ) ;
V_7 -> V_409 = 1 ;
V_7 -> V_411 = V_403 ;
if ( V_29 -> V_33 . V_485 )
V_29 -> V_33 . V_485 ( V_29 ) ;
F_227 ( V_7 ) ;
F_87 ( & V_7 -> V_171 ) ;
V_7 -> V_410 = 0 ;
}
void F_18 ( struct V_6 * V_7 )
{
-- V_7 -> V_484 ;
if ( ! V_7 -> V_409 || V_7 -> V_484 || V_7 -> V_410 )
return;
if ( V_116 ( V_7 ) ) {
V_7 -> V_410 = 1 ;
F_260 ( V_7 -> V_29 -> V_90 , & V_7 -> V_171 ,
F_222 ( V_116 ( V_7 ) * 1000 ) ) ;
}
}
int F_261 ( struct V_6 * V_7 ,
struct V_489 * V_490 ,
T_2 V_19 )
{
const struct V_491 * V_49 ;
int V_235 , V_492 ;
if ( ! V_490 -> V_493 )
return 0 ;
for ( V_49 = V_490 -> V_493 ; V_49 -> V_19 ; V_49 ++ ) {
if ( V_49 -> V_19 == V_19 )
break;
}
if ( ! V_49 -> V_19 )
return 0 ;
for ( V_49 = V_490 -> V_493 ; V_49 -> V_19 ; V_49 ++ ) {
for ( V_235 = 0 ; V_235 < 2 ; V_235 ++ ) {
V_492 = F_121 ( V_7 , V_49 -> V_19 , V_235 , V_49 -> V_232 ,
V_49 -> V_220 ) ;
if ( ! ( V_492 & V_248 ) && V_492 > 0 ) {
if ( ! V_490 -> V_409 ) {
V_490 -> V_409 = 1 ;
F_15 ( V_7 ) ;
}
return 1 ;
}
}
}
if ( V_490 -> V_409 ) {
V_490 -> V_409 = 0 ;
F_18 ( V_7 ) ;
}
return 0 ;
}
int F_262 ( struct V_6 * V_7 ,
struct V_259 * V_260 ,
const struct V_494 * V_495 ,
int V_496 )
{
V_260 -> type = V_333 ;
V_260 -> V_263 = 1 ;
V_260 -> V_264 . V_334 . V_299 = V_496 ;
if ( V_260 -> V_264 . V_334 . V_293 >= V_496 )
V_260 -> V_264 . V_334 . V_293 = V_496 - 1 ;
sprintf ( V_260 -> V_264 . V_334 . V_133 , L_95 ,
V_495 [ V_260 -> V_264 . V_334 . V_293 ] . V_416 ) ;
return 0 ;
}
int F_263 ( struct V_6 * V_7 ,
struct V_269 * V_270 ,
const struct V_494 * V_495 ,
int V_496 ,
int V_497 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_496 ; V_12 ++ ) {
if ( V_497 == V_495 [ V_12 ] . V_416 ) {
V_270 -> V_264 . V_334 . V_293 [ 0 ] = V_12 ;
break;
}
}
return 0 ;
}
int F_264 ( struct V_6 * V_7 ,
struct V_269 * V_270 ,
const struct V_494 * V_495 ,
int V_496 ,
int * V_498 )
{
unsigned int V_499 ;
V_499 = V_270 -> V_264 . V_334 . V_293 [ 0 ] ;
if ( V_499 >= V_496 )
return - V_54 ;
if ( * V_498 == V_495 [ V_499 ] . V_416 )
return 0 ;
* V_498 = V_495 [ V_499 ] . V_416 ;
if ( V_495 [ V_499 ] . V_500 )
F_220 ( V_7 , V_495 [ V_499 ] . V_500 ) ;
return 1 ;
}
int F_265 ( const struct V_501 * V_502 ,
struct V_259 * V_260 )
{
unsigned int V_236 ;
V_260 -> type = V_333 ;
V_260 -> V_263 = 1 ;
V_260 -> V_264 . V_334 . V_299 = V_502 -> V_503 ;
if ( ! V_502 -> V_503 )
return 0 ;
V_236 = V_260 -> V_264 . V_334 . V_293 ;
if ( V_236 >= V_502 -> V_503 )
V_236 = V_502 -> V_503 - 1 ;
strcpy ( V_260 -> V_264 . V_334 . V_133 , V_502 -> V_299 [ V_236 ] . V_504 ) ;
return 0 ;
}
int F_266 ( struct V_6 * V_7 ,
const struct V_501 * V_502 ,
struct V_269 * V_270 ,
T_2 V_19 ,
unsigned int * V_505 )
{
unsigned int V_220 ;
if ( ! V_502 -> V_503 )
return 0 ;
V_220 = V_270 -> V_264 . V_334 . V_293 [ 0 ] ;
if ( V_220 >= V_502 -> V_503 )
V_220 = V_502 -> V_503 - 1 ;
if ( * V_505 == V_220 )
return 0 ;
F_198 ( V_7 , V_19 , 0 , V_506 ,
V_502 -> V_299 [ V_220 ] . V_236 ) ;
* V_505 = V_220 ;
return 1 ;
}
static void F_267 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_199 , unsigned int V_201 )
{
struct V_187 * V_362 = F_205 ( V_7 , V_19 ) ;
if ( V_7 -> V_313 && ( V_362 -> V_376 & V_377 ) )
F_199 ( V_7 , V_19 ,
V_362 -> V_376 & ~ V_377 & 0xff ,
- 1 ) ;
F_100 ( V_7 , V_19 , V_199 , 0 , V_201 ) ;
if ( V_7 -> V_312 ) {
const T_2 * V_371 ;
for ( V_371 = V_7 -> V_312 ; * V_371 ; V_371 ++ )
F_100 ( V_7 , * V_371 , V_199 , 0 ,
V_201 ) ;
}
if ( V_7 -> V_313 && ( V_362 -> V_376 & V_377 ) )
F_199 ( V_7 , V_19 ,
V_362 -> V_376 & 0xff , - 1 ) ;
}
static void F_268 ( struct V_6 * V_7 , T_2 V_19 )
{
F_244 ( V_7 , V_19 ) ;
if ( V_7 -> V_312 ) {
const T_2 * V_371 ;
for ( V_371 = V_7 -> V_312 ; * V_371 ; V_371 ++ )
F_244 ( V_7 , * V_371 ) ;
}
}
void F_269 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
if ( ! V_29 )
return;
F_55 (codec, &bus->codec_list, list) {
if ( F_270 ( V_7 ) &&
V_7 -> V_96 . V_507 )
V_7 -> V_96 . V_507 ( V_7 ) ;
}
}
int F_271 ( struct V_6 * V_7 ,
struct V_385 * V_386 )
{
F_2 ( & V_7 -> V_182 ) ;
if ( V_386 -> V_508 == V_509 )
F_268 ( V_7 , V_386 -> V_388 ) ;
V_386 -> V_508 = V_510 ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_272 ( struct V_6 * V_7 ,
struct V_385 * V_386 ,
unsigned int V_199 ,
unsigned int V_201 ,
struct V_457 * V_458 )
{
F_2 ( & V_7 -> V_182 ) ;
F_267 ( V_7 , V_386 -> V_388 , V_199 , V_201 ) ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_273 ( struct V_6 * V_7 ,
struct V_385 * V_386 )
{
F_2 ( & V_7 -> V_182 ) ;
F_268 ( V_7 , V_386 -> V_388 ) ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_274 ( struct V_6 * V_7 ,
struct V_385 * V_386 )
{
F_2 ( & V_7 -> V_182 ) ;
V_386 -> V_508 = 0 ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_275 ( struct V_6 * V_7 ,
struct V_385 * V_386 ,
struct V_457 * V_458 ,
struct V_455 * V_456 )
{
struct V_511 * V_512 = V_458 -> V_512 ;
V_512 -> V_513 . V_514 = V_386 -> V_497 ;
if ( V_386 -> V_388 ) {
if ( ! V_386 -> V_515 ) {
V_386 -> V_515 = V_456 -> V_435 ;
V_386 -> V_516 = V_456 -> V_438 ;
V_386 -> V_517 = V_456 -> V_417 ;
} else {
V_512 -> V_513 . V_435 = V_386 -> V_515 ;
V_512 -> V_513 . V_438 = V_386 -> V_516 ;
V_456 -> V_417 = V_386 -> V_517 ;
}
if ( ! V_386 -> V_518 ) {
F_239 ( V_7 , V_386 -> V_388 ,
& V_386 -> V_518 ,
& V_386 -> V_519 ,
& V_386 -> V_520 ) ;
}
F_2 ( & V_7 -> V_182 ) ;
if ( V_386 -> V_387 ) {
if ( ( V_512 -> V_513 . V_435 & V_386 -> V_518 ) &&
( V_512 -> V_513 . V_438 & V_386 -> V_519 ) ) {
V_512 -> V_513 . V_435 &= V_386 -> V_518 ;
V_512 -> V_513 . V_438 &= V_386 -> V_519 ;
if ( V_386 -> V_520 < V_456 -> V_417 )
V_456 -> V_417 = V_386 -> V_520 ;
} else {
V_386 -> V_387 = 0 ;
}
}
F_4 ( & V_7 -> V_182 ) ;
}
return F_276 ( V_458 -> V_512 , 0 ,
V_521 , 2 ) ;
}
int F_277 ( struct V_6 * V_7 ,
struct V_385 * V_386 ,
unsigned int V_199 ,
unsigned int V_201 ,
struct V_457 * V_458 )
{
const T_2 * V_173 = V_386 -> V_522 ;
int V_261 = V_458 -> V_512 -> V_416 ;
struct V_187 * V_362 =
F_205 ( V_7 , V_386 -> V_388 ) ;
int V_12 ;
F_2 ( & V_7 -> V_182 ) ;
if ( V_386 -> V_388 && V_386 -> V_387 &&
V_386 -> V_508 != V_510 ) {
if ( V_261 == 2 &&
F_240 ( V_7 , V_386 -> V_388 ,
V_201 ) &&
! ( V_362 -> V_354 & V_356 ) ) {
V_386 -> V_508 = V_509 ;
F_267 ( V_7 , V_386 -> V_388 ,
V_199 , V_201 ) ;
} else {
V_386 -> V_508 = 0 ;
F_268 ( V_7 , V_386 -> V_388 ) ;
}
}
F_4 ( & V_7 -> V_182 ) ;
F_100 ( V_7 , V_173 [ V_523 ] , V_199 ,
0 , V_201 ) ;
if ( ! V_386 -> V_524 &&
V_386 -> V_525 && V_386 -> V_525 != V_173 [ V_523 ] )
F_100 ( V_7 , V_386 -> V_525 , V_199 ,
0 , V_201 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_386 -> V_526 ) ; V_12 ++ )
if ( ! V_386 -> V_524 && V_386 -> V_526 [ V_12 ] )
F_100 ( V_7 ,
V_386 -> V_526 [ V_12 ] ,
V_199 , 0 , V_201 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_386 -> V_527 ) ; V_12 ++ )
if ( ! V_386 -> V_524 && V_386 -> V_527 [ V_12 ] )
F_100 ( V_7 ,
V_386 -> V_527 [ V_12 ] ,
V_199 , 0 , V_201 ) ;
for ( V_12 = 1 ; V_12 < V_386 -> V_528 ; V_12 ++ ) {
if ( V_261 >= ( V_12 + 1 ) * 2 )
F_100 ( V_7 , V_173 [ V_12 ] , V_199 ,
V_12 * 2 , V_201 ) ;
else if ( ! V_386 -> V_524 )
F_100 ( V_7 , V_173 [ V_12 ] , V_199 ,
0 , V_201 ) ;
}
return 0 ;
}
int F_278 ( struct V_6 * V_7 ,
struct V_385 * V_386 )
{
const T_2 * V_173 = V_386 -> V_522 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_386 -> V_528 ; V_12 ++ )
F_244 ( V_7 , V_173 [ V_12 ] ) ;
if ( V_386 -> V_525 )
F_244 ( V_7 , V_386 -> V_525 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_386 -> V_526 ) ; V_12 ++ )
if ( V_386 -> V_526 [ V_12 ] )
F_244 ( V_7 ,
V_386 -> V_526 [ V_12 ] ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_386 -> V_527 ) ; V_12 ++ )
if ( V_386 -> V_527 [ V_12 ] )
F_244 ( V_7 ,
V_386 -> V_527 [ V_12 ] ) ;
F_2 ( & V_7 -> V_182 ) ;
if ( V_386 -> V_388 && V_386 -> V_508 == V_509 ) {
F_268 ( V_7 , V_386 -> V_388 ) ;
V_386 -> V_508 = 0 ;
}
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
static int F_279 ( T_2 V_19 , const T_2 * V_4 )
{
for (; * V_4 ; V_4 ++ )
if ( * V_4 == V_19 )
return 1 ;
return 0 ;
}
static void F_280 ( T_2 * V_529 , short * V_530 ,
int V_531 )
{
int V_12 , V_532 ;
short V_41 ;
T_2 V_19 ;
for ( V_12 = 0 ; V_12 < V_531 ; V_12 ++ ) {
for ( V_532 = V_12 + 1 ; V_532 < V_531 ; V_532 ++ ) {
if ( V_530 [ V_12 ] > V_530 [ V_532 ] ) {
V_41 = V_530 [ V_12 ] ;
V_530 [ V_12 ] = V_530 [ V_532 ] ;
V_530 [ V_532 ] = V_41 ;
V_19 = V_529 [ V_12 ] ;
V_529 [ V_12 ] = V_529 [ V_532 ] ;
V_529 [ V_532 ] = V_19 ;
}
}
}
}
static void F_281 ( struct V_533 * V_8 , T_2 V_19 ,
int type )
{
if ( V_8 -> V_534 < V_535 ) {
V_8 -> V_536 [ V_8 -> V_534 ] . V_157 = V_19 ;
V_8 -> V_536 [ V_8 -> V_534 ] . type = type ;
V_8 -> V_534 ++ ;
}
}
static void F_282 ( struct V_533 * V_8 )
{
int V_12 , V_532 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_534 ; V_12 ++ ) {
for ( V_532 = V_12 + 1 ; V_532 < V_8 -> V_534 ; V_532 ++ ) {
if ( V_8 -> V_536 [ V_12 ] . type > V_8 -> V_536 [ V_532 ] . type ) {
struct V_537 V_137 ;
V_137 = V_8 -> V_536 [ V_12 ] ;
V_8 -> V_536 [ V_12 ] = V_8 -> V_536 [ V_532 ] ;
V_8 -> V_536 [ V_532 ] = V_137 ;
}
}
}
}
static void F_283 ( unsigned int V_81 , T_2 * V_529 )
{
T_2 V_19 ;
switch ( V_81 ) {
case 3 :
case 4 :
V_19 = V_529 [ 1 ] ;
V_529 [ 1 ] = V_529 [ 2 ] ;
V_529 [ 2 ] = V_19 ;
break;
}
}
int F_284 ( struct V_6 * V_7 ,
struct V_533 * V_8 ,
const T_2 * V_538 ,
unsigned int V_539 )
{
T_2 V_19 , V_540 ;
short V_41 , V_541 ;
short V_542 [ F_9 ( V_8 -> V_543 ) ] ;
short V_544 [ F_9 ( V_8 -> V_545 ) ] ;
short V_546 [ F_9 ( V_8 -> V_547 ) ] ;
int V_12 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
memset ( V_542 , 0 , sizeof( V_542 ) ) ;
memset ( V_544 , 0 , sizeof( V_544 ) ) ;
memset ( V_546 , 0 , sizeof( V_546 ) ) ;
V_541 = 0 ;
V_7 -> V_548 = true ;
V_540 = V_7 -> V_154 + V_7 -> V_153 ;
for ( V_19 = V_7 -> V_154 ; V_19 < V_540 ; V_19 ++ ) {
unsigned int V_549 = F_34 ( V_7 , V_19 ) ;
unsigned int V_158 = F_35 ( V_549 ) ;
unsigned int V_550 ;
short V_551 , V_552 , V_79 , V_474 ;
if ( V_158 != V_82 )
continue;
if ( V_538 && F_279 ( V_19 , V_538 ) )
continue;
V_550 = F_77 ( V_7 , V_19 ) ;
if ( ! ( F_285 ( F_77 ( V_7 , V_19 ) ) &
V_553 ) )
V_7 -> V_548 = false ;
V_79 = F_286 ( V_550 ) ;
if ( V_79 == V_554 )
continue;
V_552 = F_287 ( V_550 ) ;
V_474 = F_288 ( V_550 ) ;
if ( V_474 == V_555 ) {
if ( V_79 == V_556 )
V_474 = V_557 ;
}
switch ( V_474 ) {
case V_555 :
V_41 = F_289 ( V_550 ) ;
V_551 = F_290 ( V_550 ) ;
if ( ! ( V_549 & V_558 ) )
if ( ! V_8 -> V_559 )
V_8 -> V_559 = V_19 ;
if ( ! V_551 )
continue;
if ( ! V_541 )
V_541 = V_551 ;
else if ( V_541 != V_551 )
continue;
if ( V_8 -> V_560 >= F_9 ( V_8 -> V_543 ) )
continue;
V_8 -> V_543 [ V_8 -> V_560 ] = V_19 ;
V_542 [ V_8 -> V_560 ] = V_41 ;
V_8 -> V_560 ++ ;
break;
case V_557 :
V_41 = F_289 ( V_550 ) ;
V_551 = F_290 ( V_550 ) ;
if ( V_8 -> V_561 >= F_9 ( V_8 -> V_545 ) )
continue;
V_8 -> V_545 [ V_8 -> V_561 ] = V_19 ;
V_544 [ V_8 -> V_561 ] = ( V_551 << 4 ) | V_41 ;
V_8 -> V_561 ++ ;
break;
case V_562 :
V_41 = F_289 ( V_550 ) ;
V_551 = F_290 ( V_550 ) ;
if ( V_8 -> V_563 >= F_9 ( V_8 -> V_547 ) )
continue;
V_8 -> V_547 [ V_8 -> V_563 ] = V_19 ;
V_546 [ V_8 -> V_563 ] = ( V_551 << 4 ) | V_41 ;
V_8 -> V_563 ++ ;
break;
case V_564 :
F_281 ( V_8 , V_19 , V_565 ) ;
break;
case V_566 :
F_281 ( V_8 , V_19 , V_567 ) ;
break;
case V_568 :
F_281 ( V_8 , V_19 , V_569 ) ;
break;
case V_570 :
F_281 ( V_8 , V_19 , V_571 ) ;
break;
case V_572 :
case V_573 :
if ( V_8 -> V_574 >= F_9 ( V_8 -> V_575 ) )
continue;
V_8 -> V_575 [ V_8 -> V_574 ] = V_19 ;
V_8 -> V_576 [ V_8 -> V_574 ] =
( V_552 == V_577 ) ?
V_467 : V_466 ;
V_8 -> V_574 ++ ;
break;
case V_578 :
case V_579 :
V_8 -> V_580 = V_19 ;
if ( V_552 == V_577 )
V_8 -> V_581 = V_467 ;
else
V_8 -> V_581 = V_466 ;
break;
}
}
if ( ! V_8 -> V_560 && V_8 -> V_563 > 1 &&
! ( V_539 & V_582 ) ) {
int V_12 = 0 ;
while ( V_12 < V_8 -> V_563 ) {
if ( ( V_546 [ V_12 ] & 0x0f ) == 0x0f ) {
V_12 ++ ;
continue;
}
V_8 -> V_543 [ V_8 -> V_560 ] = V_8 -> V_547 [ V_12 ] ;
V_542 [ V_8 -> V_560 ] = V_546 [ V_12 ] ;
V_8 -> V_560 ++ ;
V_8 -> V_563 -- ;
memmove ( V_8 -> V_547 + V_12 , V_8 -> V_547 + V_12 + 1 ,
sizeof( V_8 -> V_547 [ 0 ] ) * ( V_8 -> V_563 - V_12 ) ) ;
memmove ( V_546 + V_12 , V_546 + V_12 + 1 ,
sizeof( V_546 [ 0 ] ) * ( V_8 -> V_563 - V_12 ) ) ;
}
memset ( V_8 -> V_547 + V_8 -> V_563 , 0 ,
sizeof( T_2 ) * ( V_583 - V_8 -> V_563 ) ) ;
if ( ! V_8 -> V_563 )
V_8 -> V_584 = V_585 ;
}
F_280 ( V_8 -> V_543 , V_542 ,
V_8 -> V_560 ) ;
F_280 ( V_8 -> V_545 , V_544 ,
V_8 -> V_561 ) ;
F_280 ( V_8 -> V_547 , V_546 ,
V_8 -> V_563 ) ;
if ( ! V_8 -> V_560 &&
! ( V_539 & V_586 ) ) {
if ( V_8 -> V_561 ) {
V_8 -> V_560 = V_8 -> V_561 ;
memcpy ( V_8 -> V_543 , V_8 -> V_545 ,
sizeof( V_8 -> V_545 ) ) ;
V_8 -> V_561 = 0 ;
memset ( V_8 -> V_545 , 0 , sizeof( V_8 -> V_545 ) ) ;
V_8 -> V_584 = V_587 ;
} else if ( V_8 -> V_563 ) {
V_8 -> V_560 = V_8 -> V_563 ;
memcpy ( V_8 -> V_543 , V_8 -> V_547 ,
sizeof( V_8 -> V_547 ) ) ;
V_8 -> V_563 = 0 ;
memset ( V_8 -> V_547 , 0 , sizeof( V_8 -> V_547 ) ) ;
V_8 -> V_584 = V_585 ;
}
}
F_283 ( V_8 -> V_560 , V_8 -> V_543 ) ;
F_283 ( V_8 -> V_563 , V_8 -> V_547 ) ;
F_283 ( V_8 -> V_561 , V_8 -> V_545 ) ;
F_282 ( V_8 ) ;
F_19 ( L_96 ,
V_8 -> V_560 , V_8 -> V_543 [ 0 ] , V_8 -> V_543 [ 1 ] ,
V_8 -> V_543 [ 2 ] , V_8 -> V_543 [ 3 ] ,
V_8 -> V_543 [ 4 ] ,
V_8 -> V_584 == V_585 ? L_97 :
( V_8 -> V_584 == V_587 ?
L_98 : L_99 ) ) ;
F_19 ( L_100 ,
V_8 -> V_561 , V_8 -> V_545 [ 0 ] ,
V_8 -> V_545 [ 1 ] , V_8 -> V_545 [ 2 ] ,
V_8 -> V_545 [ 3 ] , V_8 -> V_545 [ 4 ] ) ;
F_19 ( L_101 ,
V_8 -> V_563 , V_8 -> V_547 [ 0 ] ,
V_8 -> V_547 [ 1 ] , V_8 -> V_547 [ 2 ] ,
V_8 -> V_547 [ 3 ] , V_8 -> V_547 [ 4 ] ) ;
F_19 ( L_102 , V_8 -> V_559 ) ;
if ( V_8 -> V_574 )
F_19 ( L_103 ,
V_8 -> V_575 [ 0 ] , V_8 -> V_575 [ 1 ] ) ;
F_19 ( L_104 ) ;
for ( V_12 = 0 ; V_12 < V_8 -> V_534 ; V_12 ++ ) {
F_19 ( L_105 ,
F_291 ( V_7 , V_8 , V_12 ) ,
V_8 -> V_536 [ V_12 ] . V_157 ) ;
}
F_19 ( L_106 ) ;
if ( V_8 -> V_580 )
F_19 ( L_107 , V_8 -> V_580 ) ;
return 0 ;
}
int F_292 ( unsigned int V_550 )
{
unsigned int V_552 = F_287 ( V_550 ) ;
unsigned int V_79 = F_286 ( V_550 ) ;
if ( V_79 == V_554 )
return V_588 ;
if ( V_79 == V_556 || V_79 == V_589 )
return V_590 ;
if ( ( V_552 & 0x30 ) == V_591 )
return V_590 ;
if ( ( V_552 & 0x30 ) == V_592 )
return V_593 ;
if ( V_552 == V_594 )
return V_595 ;
if ( V_552 == V_596 )
return V_597 ;
return V_598 ;
}
static const char * F_293 ( struct V_6 * V_7 ,
T_2 V_157 , bool V_599 )
{
unsigned int V_550 ;
static const char * const V_600 [] = {
L_108 , L_109 , L_30 , L_110 , L_111 ,
} ;
int V_601 ;
V_550 = F_77 ( V_7 , V_157 ) ;
switch ( F_288 ( V_550 ) ) {
case V_564 :
if ( ! V_599 )
return L_30 ;
V_601 = F_292 ( V_550 ) ;
if ( ! V_601 )
return L_112 ;
return V_600 [ V_601 - 1 ] ;
case V_566 :
if ( ! V_599 )
return L_113 ;
V_601 = F_292 ( V_550 ) ;
if ( ! V_601 )
return L_112 ;
if ( V_601 == V_593 )
return L_114 ;
return L_113 ;
case V_570 :
return L_29 ;
case V_568 :
return L_23 ;
case V_578 :
return L_32 ;
case V_579 :
return L_115 ;
default:
return L_116 ;
}
}
static int F_294 ( struct V_6 * V_7 ,
const struct V_533 * V_8 ,
int V_602 )
{
unsigned int V_603 ;
int V_12 , V_601 , V_604 ;
V_603 = F_77 ( V_7 , V_8 -> V_536 [ V_602 ] . V_157 ) ;
V_601 = F_292 ( V_603 ) ;
if ( V_601 <= V_598 )
return 1 ;
V_601 = 0 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_534 ; V_12 ++ ) {
V_603 = F_77 ( V_7 , V_8 -> V_536 [ V_12 ] . V_157 ) ;
V_604 = F_292 ( V_603 ) ;
if ( V_604 >= V_598 ) {
if ( V_601 && V_601 != V_604 )
return 1 ;
V_601 = V_604 ;
}
}
return 0 ;
}
const char * F_291 ( struct V_6 * V_7 ,
const struct V_533 * V_8 ,
int V_602 )
{
int type = V_8 -> V_536 [ V_602 ] . type ;
int V_605 = 0 ;
if ( ( V_602 > 0 && V_8 -> V_536 [ V_602 - 1 ] . type == type ) ||
( V_602 < V_8 -> V_534 - 1 && V_8 -> V_536 [ V_602 + 1 ] . type == type ) )
V_605 = 1 ;
if ( V_605 && type == V_565 )
V_605 &= F_294 ( V_7 , V_8 , V_602 ) ;
return F_293 ( V_7 , V_8 -> V_536 [ V_602 ] . V_157 ,
V_605 ) ;
}
static int F_295 ( T_2 V_19 , const T_2 * V_4 , int V_81 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_81 ; V_12 ++ )
if ( V_4 [ V_12 ] == V_19 )
return V_12 ;
return - 1 ;
}
static const char * F_296 ( T_2 V_19 , const T_2 * V_529 ,
int V_531 , int * V_606 )
{
static const char * const V_607 [] = {
L_117 , L_118 , L_119 , L_120
} ;
int V_12 ;
V_12 = F_295 ( V_19 , V_529 , V_531 ) ;
if ( V_12 < 0 )
return NULL ;
if ( V_531 == 1 )
return L_121 ;
if ( V_531 > F_9 ( V_607 ) ) {
if ( V_606 )
* V_606 = V_12 ;
return L_121 ;
}
return V_607 [ V_12 ] ;
}
static int F_297 ( struct V_6 * V_7 , T_2 V_19 ,
const struct V_533 * V_8 ,
const char * V_133 , char * V_504 , int V_608 ,
int * V_606 )
{
unsigned int V_550 = F_77 ( V_7 , V_19 ) ;
int V_601 = F_292 ( V_550 ) ;
const char * V_609 = L_121 , * V_610 = L_121 ;
if ( ! strcmp ( V_133 , L_20 ) && V_601 == V_590 )
V_133 = L_21 ;
switch ( V_601 ) {
case V_593 :
V_609 = L_122 ;
break;
case V_597 :
V_609 = L_123 ;
break;
}
if ( V_8 ) {
V_610 = F_296 ( V_19 , V_8 -> V_543 , V_8 -> V_560 ,
V_606 ) ;
if ( ! V_610 )
V_610 = F_296 ( V_19 , V_8 -> V_545 , V_8 -> V_561 ,
V_606 ) ;
if ( ! V_610 ) {
int V_220 = F_295 ( V_19 , V_8 -> V_547 ,
V_8 -> V_563 ) ;
if ( V_220 >= 0 )
* V_606 = V_220 ;
V_610 = L_121 ;
}
}
snprintf ( V_504 , V_608 , L_124 , V_609 , V_133 , V_610 ) ;
return 1 ;
}
int F_298 ( struct V_6 * V_7 , T_2 V_19 ,
const struct V_533 * V_8 ,
char * V_504 , int V_608 , int * V_606 )
{
unsigned int V_550 = F_77 ( V_7 , V_19 ) ;
const char * V_133 = NULL ;
int V_12 ;
if ( V_606 )
* V_606 = 0 ;
if ( F_286 ( V_550 ) == V_554 )
return 0 ;
switch ( F_288 ( V_550 ) ) {
case V_555 :
return F_297 ( V_7 , V_19 , V_8 , L_20 ,
V_504 , V_608 , V_606 ) ;
case V_557 :
return F_297 ( V_7 , V_19 , V_8 , L_21 ,
V_504 , V_608 , V_606 ) ;
case V_562 :
return F_297 ( V_7 , V_19 , V_8 , L_125 ,
V_504 , V_608 , V_606 ) ;
case V_572 :
case V_573 :
if ( F_287 ( V_550 ) == V_577 )
V_133 = L_11 ;
else
V_133 = L_126 ;
if ( V_8 && V_606 ) {
V_12 = F_295 ( V_19 , V_8 -> V_575 ,
V_8 -> V_574 ) ;
if ( V_12 >= 0 )
* V_606 = V_12 ;
}
break;
default:
if ( V_8 ) {
for ( V_12 = 0 ; V_12 < V_8 -> V_534 ; V_12 ++ ) {
if ( V_8 -> V_536 [ V_12 ] . V_157 != V_19 )
continue;
V_133 = F_291 ( V_7 , V_8 , V_12 ) ;
if ( V_133 )
break;
}
}
if ( ! V_133 )
V_133 = F_293 ( V_7 , V_19 , true ) ;
break;
}
if ( ! V_133 )
return 0 ;
F_299 ( V_504 , V_133 , V_608 ) ;
return 1 ;
}
int F_300 ( struct V_501 * V_502 , const char * V_504 ,
int V_236 , int * V_611 )
{
int V_12 , V_612 = 0 ;
if ( V_502 -> V_503 >= V_80 ) {
F_19 ( V_25 L_127 ) ;
return - V_54 ;
}
for ( V_12 = 0 ; V_12 < V_502 -> V_503 ; V_12 ++ ) {
if ( ! strncmp ( V_504 , V_502 -> V_299 [ V_12 ] . V_504 , strlen ( V_504 ) ) )
V_612 ++ ;
}
if ( V_611 )
* V_611 = V_612 ;
if ( V_612 > 0 )
snprintf ( V_502 -> V_299 [ V_502 -> V_503 ] . V_504 ,
sizeof( V_502 -> V_299 [ V_502 -> V_503 ] . V_504 ) ,
L_128 , V_504 , V_612 ) ;
else
F_299 ( V_502 -> V_299 [ V_502 -> V_503 ] . V_504 , V_504 ,
sizeof( V_502 -> V_299 [ V_502 -> V_503 ] . V_504 ) ) ;
V_502 -> V_299 [ V_502 -> V_503 ] . V_236 = V_236 ;
V_502 -> V_503 ++ ;
return 0 ;
}
int F_301 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
if ( F_270 ( V_7 ) )
F_225 ( V_7 ) ;
if ( V_7 -> V_96 . V_613 )
V_7 -> V_96 . V_613 ( V_7 ) ;
}
return 0 ;
}
int F_302 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
if ( V_7 -> V_96 . V_614 )
V_7 -> V_96 . V_614 ( V_7 ) ;
if ( F_303 ( V_7 ) )
F_227 ( V_7 ) ;
}
return 0 ;
}
void * F_37 ( struct V_45 * V_46 )
{
if ( V_46 -> V_48 >= V_46 -> V_615 ) {
int V_616 = V_46 -> V_615 + V_46 -> V_617 ;
int V_274 = ( V_616 + 1 ) * V_46 -> V_618 ;
int V_619 = V_46 -> V_615 * V_46 -> V_618 ;
void * V_620 ;
if ( F_29 ( V_616 >= 4096 ) )
return NULL ;
V_620 = F_304 ( V_46 -> V_4 , V_274 , V_98 ) ;
if ( ! V_620 )
return NULL ;
memset ( V_620 + V_619 , 0 , V_274 - V_619 ) ;
V_46 -> V_4 = V_620 ;
V_46 -> V_615 = V_616 ;
}
return F_27 ( V_46 , V_46 -> V_48 ++ ) ;
}
void F_84 ( struct V_45 * V_46 )
{
F_49 ( V_46 -> V_4 ) ;
V_46 -> V_48 = 0 ;
V_46 -> V_615 = 0 ;
V_46 -> V_4 = NULL ;
}
void F_305 ( int V_301 , char * V_218 , int V_621 )
{
static unsigned int V_622 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_12 , V_532 ;
for ( V_12 = 0 , V_532 = 0 ; V_12 < F_9 ( V_622 ) ; V_12 ++ )
if ( V_301 & ( V_441 << V_12 ) )
V_532 += snprintf ( V_218 + V_532 , V_621 - V_532 , L_129 , V_622 [ V_12 ] ) ;
V_218 [ V_532 ] = '\0' ;
}
