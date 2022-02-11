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
static int F_28 ( struct V_6 * V_7 , T_2 V_19 )
{
T_2 V_4 [ V_50 ] ;
int V_47 ;
V_47 = F_29 ( V_7 , V_19 , V_4 , F_9 ( V_4 ) ) ;
if ( V_47 < 0 )
return V_47 ;
return F_30 ( V_7 , V_19 , V_47 , V_4 ) ;
}
int F_31 ( struct V_6 * V_7 , T_2 V_19 ,
T_2 * V_51 , int V_52 )
{
struct V_45 * V_46 = & V_7 -> V_53 ;
int V_47 ;
T_2 * V_49 ;
bool V_54 = false ;
V_31:
F_2 ( & V_7 -> V_55 ) ;
V_47 = - 1 ;
V_49 = F_26 ( V_46 , V_19 ) ;
if ( V_49 ) {
V_47 = V_49 [ 1 ] ;
if ( V_51 && V_47 > V_52 ) {
F_32 ( V_25 L_39
L_40 ,
V_47 , V_19 ) ;
F_4 ( & V_7 -> V_55 ) ;
return - V_56 ;
}
if ( V_51 && V_47 )
memcpy ( V_51 , V_49 + 2 , V_47 * sizeof( T_2 ) ) ;
}
F_4 ( & V_7 -> V_55 ) ;
if ( V_47 >= 0 )
return V_47 ;
if ( F_33 ( V_54 ) )
return - V_56 ;
V_47 = F_28 ( V_7 , V_19 ) ;
if ( V_47 < 0 )
return V_47 ;
V_54 = true ;
goto V_31;
}
int F_29 ( struct V_6 * V_7 , T_2 V_19 ,
T_2 * V_51 , int V_52 )
{
unsigned int V_22 ;
int V_12 , V_57 , V_58 ;
unsigned int V_59 , V_60 , V_61 ;
unsigned int V_62 ;
T_2 V_63 ;
if ( F_33 ( ! V_51 || V_52 <= 0 ) )
return - V_56 ;
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
V_51 [ 0 ] = V_22 & V_61 ;
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
F_32 ( V_73 L_39
L_41 ,
V_19 , V_12 , V_22 ) ;
return 0 ;
}
V_22 >>= V_59 ;
if ( V_71 ) {
if ( ! V_63 || V_63 >= V_23 ) {
F_32 ( V_73 L_39
L_42 ,
V_63 , V_23 ) ;
continue;
}
for ( V_72 = V_63 + 1 ; V_72 <= V_23 ; V_72 ++ ) {
if ( V_58 >= V_52 ) {
F_32 ( V_25 L_39
L_40 ,
V_58 , V_19 ) ;
return - V_56 ;
}
V_51 [ V_58 ++ ] = V_72 ;
}
} else {
if ( V_58 >= V_52 ) {
F_32 ( V_25 L_39
L_40 ,
V_58 , V_19 ) ;
return - V_56 ;
}
V_51 [ V_58 ++ ] = V_23 ;
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
int F_30 ( struct V_6 * V_7 , T_2 V_19 , int V_47 ,
const T_2 * V_4 )
{
struct V_45 * V_46 = & V_7 -> V_53 ;
T_2 * V_49 ;
int V_12 , V_74 ;
F_2 ( & V_7 -> V_55 ) ;
V_49 = F_26 ( V_46 , V_19 ) ;
if ( V_49 )
* V_49 = - 1 ;
V_74 = V_46 -> V_48 ;
if ( ! F_36 ( V_46 , V_19 ) || ! F_36 ( V_46 , V_47 ) )
goto V_75;
for ( V_12 = 0 ; V_12 < V_47 ; V_12 ++ )
if ( ! F_36 ( V_46 , V_4 [ V_12 ] ) )
goto V_75;
F_4 ( & V_7 -> V_55 ) ;
return 0 ;
V_75:
V_46 -> V_48 = V_74 ;
F_4 ( & V_7 -> V_55 ) ;
return - V_76 ;
}
int F_38 ( struct V_6 * V_7 , T_2 V_77 ,
T_2 V_19 , int V_78 )
{
T_2 V_79 [ V_80 ] ;
int V_12 , V_81 ;
V_81 = F_31 ( V_7 , V_77 , V_79 , F_9 ( V_79 ) ) ;
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
F_32 ( V_25 L_39
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
if ( F_33 ( ! V_107 ) )
return - V_56 ;
if ( F_33 ( ! V_107 -> V_33 . V_34 || ! V_107 -> V_33 . V_35 ) )
return - V_56 ;
if ( V_108 )
* V_108 = NULL ;
V_29 = F_45 ( sizeof( * V_29 ) , V_98 ) ;
if ( V_29 == NULL ) {
F_32 ( V_25 L_45 ) ;
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
F_32 ( V_25 L_47 ,
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
F_32 ( V_25 L_48 ) ;
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
return - V_56 ;
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
F_86 ( V_7 ) ;
F_83 ( V_7 ) ;
#ifdef F_87
F_88 ( & V_7 -> V_171 ) ;
F_48 ( V_7 -> V_29 -> V_90 ) ;
#endif
F_6 ( & V_7 -> V_4 ) ;
F_84 ( & V_7 -> V_172 ) ;
F_84 ( & V_7 -> V_173 ) ;
F_84 ( & V_7 -> V_170 ) ;
F_84 ( & V_7 -> V_53 ) ;
F_84 ( & V_7 -> V_174 ) ;
V_7 -> V_29 -> V_95 [ V_7 -> V_24 ] = NULL ;
if ( V_7 -> V_96 . free )
V_7 -> V_96 . free ( V_7 ) ;
F_66 ( V_7 -> V_125 ) ;
F_89 ( & V_7 -> V_175 ) ;
F_89 ( & V_7 -> V_176 ) ;
F_49 ( V_7 -> V_138 ) ;
F_49 ( V_7 -> V_141 ) ;
F_49 ( V_7 -> V_115 ) ;
F_49 ( V_7 -> V_62 ) ;
F_49 ( V_7 ) ;
}
int F_90 ( struct V_28 * V_29 ,
unsigned int V_177 ,
struct V_6 * * V_178 )
{
struct V_6 * V_7 ;
char V_179 [ 31 ] ;
int V_30 ;
if ( F_33 ( ! V_29 ) )
return - V_56 ;
if ( F_33 ( V_177 > V_180 ) )
return - V_56 ;
if ( V_29 -> V_95 [ V_177 ] ) {
F_32 ( V_25 L_39
L_53 , V_177 ) ;
return - V_181 ;
}
V_7 = F_45 ( sizeof( * V_7 ) , V_98 ) ;
if ( V_7 == NULL ) {
F_32 ( V_25 L_54 ) ;
return - V_76 ;
}
V_7 -> V_29 = V_29 ;
V_7 -> V_24 = V_177 ;
F_59 ( & V_7 -> V_182 ) ;
F_59 ( & V_7 -> V_183 ) ;
F_59 ( & V_7 -> V_55 ) ;
F_91 ( & V_7 -> V_175 , sizeof( struct V_184 ) ) ;
F_91 ( & V_7 -> V_176 , sizeof( struct V_185 ) ) ;
F_92 ( & V_7 -> V_172 , sizeof( struct V_186 ) , 32 ) ;
F_92 ( & V_7 -> V_173 , sizeof( struct V_186 ) , 32 ) ;
F_92 ( & V_7 -> V_159 , sizeof( struct V_156 ) , 16 ) ;
F_92 ( & V_7 -> V_165 , sizeof( struct V_156 ) , 16 ) ;
F_92 ( & V_7 -> V_170 , sizeof( struct V_169 ) , 8 ) ;
F_92 ( & V_7 -> V_53 , sizeof( T_2 ) , 64 ) ;
F_92 ( & V_7 -> V_174 , sizeof( struct V_187 ) , 16 ) ;
#ifdef F_87
F_93 ( & V_7 -> V_188 ) ;
F_94 ( & V_7 -> V_171 , V_189 ) ;
F_7 ( V_7 ) ;
#endif
if ( V_7 -> V_29 -> V_115 ) {
V_7 -> V_115 = F_69 ( V_7 -> V_29 -> V_115 , V_98 ) ;
if ( ! V_7 -> V_115 ) {
F_51 ( V_7 ) ;
return - V_190 ;
}
}
F_3 ( & V_7 -> V_4 , & V_29 -> V_118 ) ;
V_29 -> V_95 [ V_177 ] = V_7 ;
V_7 -> V_129 = F_25 ( V_7 , V_144 ,
V_191 ) ;
if ( V_7 -> V_129 == - 1 )
V_7 -> V_129 = F_25 ( V_7 , V_144 ,
V_191 ) ;
V_7 -> V_192 = F_25 ( V_7 , V_144 ,
V_193 ) ;
V_7 -> V_131 = F_25 ( V_7 , V_144 ,
V_194 ) ;
F_70 ( V_7 ) ;
if ( ! V_7 -> V_127 && ! V_7 -> V_128 ) {
F_95 ( L_55 ) ;
V_30 = - V_190 ;
goto error;
}
V_30 = F_71 ( V_7 , V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ) ;
if ( V_30 < 0 ) {
F_32 ( V_25 L_56 ) ;
goto error;
}
V_30 = F_73 ( V_7 ) ;
if ( V_30 < 0 )
goto error;
if ( ! V_7 -> V_192 ) {
T_2 V_19 = V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ;
V_7 -> V_192 =
F_21 ( V_7 , V_19 , 0 ,
V_195 , 0 ) ;
}
F_96 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_196 ) ;
F_97 ( V_7 ) ;
F_98 ( V_7 ) ;
sprintf ( V_179 , L_57 , V_7 -> V_129 ,
V_7 -> V_192 , V_7 -> V_131 ) ;
F_99 ( V_7 -> V_29 -> V_105 , V_179 ) ;
if ( V_178 )
* V_178 = V_7 ;
return 0 ;
error:
F_51 ( V_7 ) ;
return V_30 ;
}
int F_100 ( struct V_6 * V_7 )
{
int V_30 ;
V_7 -> V_2 = F_63 ( V_7 ) ;
if ( ! V_7 -> V_138 || ! V_7 -> V_141 ) {
V_30 = F_68 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( F_64 ( V_7 ) ) {
V_30 = F_101 ( V_7 ) ;
goto V_197;
}
if ( V_7 -> V_2 && V_7 -> V_2 -> V_198 ) {
V_30 = V_7 -> V_2 -> V_198 ( V_7 ) ;
goto V_197;
}
V_30 = F_101 ( V_7 ) ;
if ( V_30 < 0 )
F_13 ( V_25 L_58 ) ;
V_197:
if ( ! V_30 && V_7 -> V_96 . V_97 )
V_30 = F_44 ( V_7 -> V_29 ) ;
if ( ! V_30 && ( V_7 -> V_127 || ! * V_7 -> V_29 -> V_105 -> V_199 ) )
snprintf ( V_7 -> V_29 -> V_105 -> V_199 ,
sizeof( V_7 -> V_29 -> V_105 -> V_199 ) ,
L_59 , V_7 -> V_138 , V_7 -> V_141 ) ;
return V_30 ;
}
void F_102 ( struct V_6 * V_7 , T_2 V_19 ,
T_1 V_200 ,
int V_201 , int V_202 )
{
struct V_6 * V_135 ;
struct V_169 * V_49 ;
unsigned int V_203 , V_204 ;
int type ;
int V_12 ;
if ( ! V_19 )
return;
F_95 ( L_60
L_61 ,
V_19 , V_200 , V_201 , V_202 ) ;
V_49 = F_85 ( V_7 , V_19 ) ;
if ( ! V_49 )
return;
if ( V_49 -> V_200 != V_200 || V_49 -> V_201 != V_201 ) {
V_203 = F_21 ( V_7 , V_19 , 0 , V_205 , 0 ) ;
V_204 = ( V_200 << 4 ) | V_201 ;
if ( V_203 != V_204 )
F_22 ( V_7 , V_19 , 0 ,
V_206 ,
V_204 ) ;
V_49 -> V_200 = V_200 ;
V_49 -> V_201 = V_201 ;
}
if ( V_49 -> V_207 != V_202 ) {
V_203 = F_21 ( V_7 , V_19 , 0 ,
V_208 , 0 ) ;
if ( V_203 != V_202 ) {
F_103 ( 1 ) ;
F_22 ( V_7 , V_19 , 0 ,
V_209 ,
V_202 ) ;
}
V_49 -> V_207 = V_202 ;
}
V_49 -> V_210 = 1 ;
V_49 -> V_211 = 0 ;
type = F_35 ( F_34 ( V_7 , V_19 ) ) ;
F_55 (c, &codec->bus->codec_list, list) {
for ( V_12 = 0 ; V_12 < V_135 -> V_170 . V_48 ; V_12 ++ ) {
V_49 = F_27 ( & V_135 -> V_170 , V_12 ) ;
if ( ! V_49 -> V_210 && V_49 -> V_200 == V_200 &&
F_35 ( F_34 ( V_135 , V_49 -> V_19 ) ) == type )
V_49 -> V_211 = 1 ;
}
}
}
void F_104 ( struct V_6 * V_7 , T_2 V_19 ,
int V_212 )
{
struct V_169 * V_49 ;
if ( ! V_19 )
return;
if ( V_7 -> V_213 )
V_212 = 1 ;
F_95 ( L_62 , V_19 ) ;
V_49 = F_85 ( V_7 , V_19 ) ;
if ( V_49 ) {
if ( V_212 )
F_105 ( V_7 , V_49 ) ;
else
V_49 -> V_210 = 0 ;
}
}
static void F_105 ( struct V_6 * V_7 ,
struct V_169 * V_214 )
{
T_2 V_19 = V_214 -> V_19 ;
if ( V_214 -> V_200 || V_214 -> V_201 )
F_22 ( V_7 , V_19 , 0 , V_206 , 0 ) ;
if ( V_214 -> V_207 )
F_22 ( V_7 , V_19 , 0 , V_209 , 0
) ;
memset ( V_214 , 0 , sizeof( * V_214 ) ) ;
V_214 -> V_19 = V_19 ;
}
static void F_106 ( struct V_6 * V_7 )
{
struct V_6 * V_135 ;
int V_12 ;
F_55 (c, &codec->bus->codec_list, list) {
for ( V_12 = 0 ; V_12 < V_135 -> V_170 . V_48 ; V_12 ++ ) {
struct V_169 * V_49 ;
V_49 = F_27 ( & V_135 -> V_170 , V_12 ) ;
if ( V_49 -> V_211 )
F_105 ( V_135 , V_49 ) ;
}
}
}
static void F_107 ( struct V_6 * V_7 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_170 . V_48 ; V_12 ++ ) {
struct V_169 * V_49 = F_27 ( & V_7 -> V_170 , V_12 ) ;
if ( V_49 -> V_200 )
F_105 ( V_7 , V_49 ) ;
}
}
static void F_91 ( struct V_215 * V_216 ,
unsigned int V_217 )
{
memset ( V_216 , 0 , sizeof( * V_216 ) ) ;
memset ( V_216 -> V_218 , 0xff , sizeof( V_216 -> V_218 ) ) ;
F_92 ( & V_216 -> V_219 , V_217 , 64 ) ;
}
static void F_89 ( struct V_215 * V_216 )
{
F_84 ( & V_216 -> V_219 ) ;
}
static struct V_185 * F_108 ( struct V_215 * V_216 , T_1 V_220 )
{
T_3 V_221 = V_220 % ( T_3 ) F_9 ( V_216 -> V_218 ) ;
T_3 V_222 = V_216 -> V_218 [ V_221 ] ;
struct V_185 * V_223 ;
while ( V_222 != 0xffff ) {
V_223 = F_27 ( & V_216 -> V_219 , V_222 ) ;
if ( V_223 -> V_220 == V_220 )
return V_223 ;
V_222 = V_223 -> V_224 ;
}
return NULL ;
}
static struct V_185 * F_109 ( struct V_215 * V_216 ,
T_1 V_220 )
{
struct V_185 * V_223 = F_108 ( V_216 , V_220 ) ;
if ( ! V_223 ) {
T_3 V_221 , V_222 ;
V_223 = F_37 ( & V_216 -> V_219 ) ;
if ( ! V_223 )
return NULL ;
V_222 = F_110 ( & V_216 -> V_219 , V_223 ) ;
V_223 -> V_220 = V_220 ;
V_223 -> V_23 = 0 ;
V_221 = V_220 % ( T_3 ) F_9 ( V_216 -> V_218 ) ;
V_223 -> V_224 = V_216 -> V_218 [ V_221 ] ;
V_216 -> V_218 [ V_221 ] = V_222 ;
}
return V_223 ;
}
static inline struct V_184 *
F_111 ( struct V_6 * V_7 , T_1 V_220 )
{
return (struct V_184 * ) F_109 ( & V_7 -> V_175 , V_220 ) ;
}
static int F_112 ( struct V_6 * V_7 , T_1 V_220 , unsigned int V_23 )
{
struct V_184 * V_223 ;
F_2 ( & V_7 -> V_55 ) ;
V_223 = F_111 ( V_7 , V_220 ) ;
if ( ! V_223 ) {
F_4 ( & V_7 -> V_55 ) ;
return - V_56 ;
}
V_223 -> V_225 = V_23 ;
V_223 -> V_226 . V_23 |= V_227 ;
F_4 ( & V_7 -> V_55 ) ;
return 0 ;
}
static unsigned int F_113 ( struct V_6 * V_7 , T_2 V_19 ,
int V_228 )
{
if ( ! ( F_34 ( V_7 , V_19 ) & V_229 ) )
V_19 = V_7 -> V_127 ;
return F_25 ( V_7 , V_19 ,
V_228 == V_230 ?
V_231 : V_232 ) ;
}
T_1 F_114 ( struct V_6 * V_7 , T_2 V_19 , int V_228 )
{
return F_115 ( V_7 , V_19 , V_228 ,
F_116 ( V_19 , V_228 , 0 ) ,
F_113 ) ;
}
int F_117 ( struct V_6 * V_7 , T_2 V_19 , int V_233 ,
unsigned int V_234 )
{
return F_112 ( V_7 , F_116 ( V_19 , V_233 , 0 ) , V_234 ) ;
}
static unsigned int F_118 ( struct V_6 * V_7 , T_2 V_19 ,
int V_233 )
{
return F_25 ( V_7 , V_19 , V_235 ) ;
}
T_1 F_119 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_115 ( V_7 , V_19 , 0 , F_120 ( V_19 ) ,
F_118 ) ;
}
int F_121 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_234 )
{
return F_112 ( V_7 , F_120 ( V_19 ) , V_234 ) ;
}
static struct V_184 *
F_122 ( struct V_6 * V_7 , T_2 V_19 , int V_236 ,
int V_228 , int V_237 )
{
struct V_184 * V_223 ;
unsigned int V_22 , V_23 = 0 ;
bool V_238 = false ;
V_239:
V_223 = F_111 ( V_7 , F_116 ( V_19 , V_228 , V_237 ) ) ;
if ( ! V_223 )
return NULL ;
if ( ! ( V_223 -> V_226 . V_23 & F_123 ( V_236 ) ) ) {
if ( ! V_238 ) {
F_4 ( & V_7 -> V_55 ) ;
V_22 = V_236 ? V_240 : V_241 ;
V_22 |= V_228 == V_230 ?
V_242 : V_243 ;
V_22 |= V_237 ;
V_23 = F_21 ( V_7 , V_19 , 0 ,
V_244 , V_22 ) ;
V_23 &= 0xff ;
V_238 = true ;
F_2 ( & V_7 -> V_55 ) ;
goto V_239;
}
V_223 -> V_245 [ V_236 ] = V_23 ;
V_223 -> V_226 . V_23 |= F_123 ( V_236 ) ;
}
return V_223 ;
}
static void F_124 ( struct V_6 * V_7 , struct V_184 * V_223 ,
T_2 V_19 , int V_236 , int V_228 , int V_237 ,
int V_23 )
{
T_1 V_22 ;
V_22 = V_236 ? V_246 : V_247 ;
V_22 |= V_228 == V_230 ? V_248 : V_249 ;
V_22 |= V_237 << V_250 ;
if ( ( V_23 & V_251 ) && ! ( V_223 -> V_225 & V_252 ) &&
( V_223 -> V_225 & V_253 ) )
;
else
V_22 |= V_23 ;
F_22 ( V_7 , V_19 , 0 , V_254 , V_22 ) ;
}
int F_125 ( struct V_6 * V_7 , T_2 V_19 , int V_236 ,
int V_228 , int V_237 )
{
struct V_184 * V_223 ;
unsigned int V_23 = 0 ;
F_2 ( & V_7 -> V_55 ) ;
V_223 = F_122 ( V_7 , V_19 , V_236 , V_228 , V_237 ) ;
if ( V_223 )
V_23 = V_223 -> V_245 [ V_236 ] ;
F_4 ( & V_7 -> V_55 ) ;
return V_23 ;
}
int F_126 ( struct V_6 * V_7 , T_2 V_19 , int V_236 ,
int V_228 , int V_221 , int V_61 , int V_23 )
{
struct V_184 * V_223 ;
if ( F_33 ( V_61 & ~ 0xff ) )
V_61 &= 0xff ;
V_23 &= V_61 ;
F_2 ( & V_7 -> V_55 ) ;
V_223 = F_122 ( V_7 , V_19 , V_236 , V_228 , V_221 ) ;
if ( ! V_223 ) {
F_4 ( & V_7 -> V_55 ) ;
return 0 ;
}
V_23 |= V_223 -> V_245 [ V_236 ] & ~ V_61 ;
if ( V_223 -> V_245 [ V_236 ] == V_23 ) {
F_4 ( & V_7 -> V_55 ) ;
return 0 ;
}
V_223 -> V_245 [ V_236 ] = V_23 ;
F_4 ( & V_7 -> V_55 ) ;
F_124 ( V_7 , V_223 , V_19 , V_236 , V_228 , V_221 , V_23 ) ;
return 1 ;
}
int F_127 ( struct V_6 * V_7 , T_2 V_19 ,
int V_228 , int V_221 , int V_61 , int V_23 )
{
int V_236 , V_255 = 0 ;
if ( F_33 ( V_61 & ~ 0xff ) )
V_61 &= 0xff ;
for ( V_236 = 0 ; V_236 < 2 ; V_236 ++ )
V_255 |= F_126 ( V_7 , V_19 , V_236 , V_228 ,
V_221 , V_61 , V_23 ) ;
return V_255 ;
}
void F_128 ( struct V_6 * V_7 )
{
struct V_184 * V_256 = V_7 -> V_175 . V_219 . V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_175 . V_219 . V_48 ; V_12 ++ , V_256 ++ ) {
T_1 V_220 = V_256 -> V_226 . V_220 ;
T_2 V_19 ;
unsigned int V_221 , V_233 , V_236 ;
if ( ! V_220 )
continue;
V_19 = V_220 & 0xff ;
V_221 = ( V_220 >> 16 ) & 0xff ;
V_233 = ( V_220 >> 24 ) & 0xff ;
for ( V_236 = 0 ; V_236 < 2 ; V_236 ++ ) {
if ( ! ( V_256 -> V_226 . V_23 & F_123 ( V_236 ) ) )
continue;
F_124 ( V_7 , V_256 , V_19 , V_236 , V_233 , V_221 ,
V_256 -> V_245 [ V_236 ] ) ;
}
}
}
static T_1 F_129 ( struct V_6 * V_7 , T_2 V_19 , int V_233 ,
unsigned int V_257 )
{
T_1 V_234 = F_114 ( V_7 , V_19 , V_233 ) ;
V_234 = ( V_234 & V_258 ) >> V_259 ;
if ( V_257 < V_234 )
V_234 -= V_257 ;
return V_234 ;
}
int F_130 ( struct V_260 * V_261 ,
struct V_262 * V_263 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
T_3 V_19 = F_132 ( V_261 ) ;
T_4 V_264 = F_133 ( V_261 ) ;
int V_233 = F_134 ( V_261 ) ;
unsigned int V_257 = F_135 ( V_261 ) ;
V_263 -> type = V_265 ;
V_263 -> V_266 = V_264 == 3 ? 2 : 1 ;
V_263 -> V_267 . integer . V_268 = 0 ;
V_263 -> V_267 . integer . V_269 = F_129 ( V_7 , V_19 , V_233 , V_257 ) ;
if ( ! V_263 -> V_267 . integer . V_269 ) {
F_13 ( V_73 L_39
L_63 , V_19 ,
V_261 -> V_126 . V_133 ) ;
return - V_56 ;
}
return 0 ;
}
static inline unsigned int
F_136 ( struct V_6 * V_7 , T_2 V_19 ,
int V_236 , int V_233 , int V_221 , unsigned int V_257 )
{
unsigned int V_23 ;
V_23 = F_125 ( V_7 , V_19 , V_236 , V_233 , V_221 ) ;
V_23 &= V_270 ;
if ( V_23 >= V_257 )
V_23 -= V_257 ;
else
V_23 = 0 ;
return V_23 ;
}
static inline int
F_137 ( struct V_6 * V_7 , T_2 V_19 ,
int V_236 , int V_233 , int V_221 , unsigned int V_257 ,
unsigned int V_23 )
{
unsigned int V_271 ;
if ( V_23 > 0 )
V_23 += V_257 ;
V_271 = F_129 ( V_7 , V_19 , V_233 , 0 ) ;
if ( V_23 > V_271 )
V_23 = V_271 ;
return F_126 ( V_7 , V_19 , V_236 , V_233 , V_221 ,
V_270 , V_23 ) ;
}
int F_138 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
T_2 V_19 = F_132 ( V_261 ) ;
int V_264 = F_133 ( V_261 ) ;
int V_233 = F_134 ( V_261 ) ;
int V_221 = F_139 ( V_261 ) ;
unsigned int V_257 = F_135 ( V_261 ) ;
long * V_274 = V_273 -> V_267 . integer . V_267 ;
if ( V_264 & 1 )
* V_274 ++ = F_136 ( V_7 , V_19 , 0 , V_233 , V_221 , V_257 ) ;
if ( V_264 & 2 )
* V_274 = F_136 ( V_7 , V_19 , 1 , V_233 , V_221 , V_257 ) ;
return 0 ;
}
int F_140 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
T_2 V_19 = F_132 ( V_261 ) ;
int V_264 = F_133 ( V_261 ) ;
int V_233 = F_134 ( V_261 ) ;
int V_221 = F_139 ( V_261 ) ;
unsigned int V_257 = F_135 ( V_261 ) ;
long * V_274 = V_273 -> V_267 . integer . V_267 ;
int V_275 = 0 ;
F_15 ( V_7 ) ;
if ( V_264 & 1 ) {
V_275 = F_137 ( V_7 , V_19 , 0 , V_233 , V_221 , V_257 , * V_274 ) ;
V_274 ++ ;
}
if ( V_264 & 2 )
V_275 |= F_137 ( V_7 , V_19 , 1 , V_233 , V_221 , V_257 , * V_274 ) ;
F_18 ( V_7 ) ;
return V_275 ;
}
int F_141 ( struct V_260 * V_261 , int V_276 ,
unsigned int V_277 , unsigned int T_5 * V_278 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
T_2 V_19 = F_132 ( V_261 ) ;
int V_233 = F_134 ( V_261 ) ;
unsigned int V_257 = F_135 ( V_261 ) ;
bool V_279 = F_142 ( V_261 ) ;
T_1 V_234 , V_280 , V_281 ;
if ( V_277 < 4 * sizeof( unsigned int ) )
return - V_76 ;
V_234 = F_114 ( V_7 , V_19 , V_233 ) ;
V_281 = ( V_234 & V_282 ) >> V_283 ;
V_281 = ( V_281 + 1 ) * 25 ;
V_280 = - ( ( V_234 & V_284 ) >> V_285 ) ;
V_280 += V_257 ;
V_280 = ( ( int ) V_280 ) * ( ( int ) V_281 ) ;
if ( V_279 || ( V_234 & V_253 ) )
V_281 |= V_286 ;
if ( F_143 ( V_287 , V_278 ) )
return - V_288 ;
if ( F_143 ( 2 * sizeof( unsigned int ) , V_278 + 1 ) )
return - V_288 ;
if ( F_143 ( V_280 , V_278 + 2 ) )
return - V_288 ;
if ( F_143 ( V_281 , V_278 + 3 ) )
return - V_288 ;
return 0 ;
}
void F_144 ( struct V_6 * V_7 , T_2 V_19 , int V_233 ,
unsigned int * V_289 )
{
T_1 V_234 ;
int V_81 , V_290 ;
V_234 = F_114 ( V_7 , V_19 , V_233 ) ;
V_81 = ( V_234 & V_258 ) >> V_259 ;
V_290 = ( V_234 & V_282 ) >> V_283 ;
V_290 = ( V_290 + 1 ) * 25 ;
V_289 [ 0 ] = V_287 ;
V_289 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_289 [ 2 ] = - V_81 * V_290 ;
V_289 [ 3 ] = V_290 ;
}
static struct V_260 *
F_145 ( struct V_6 * V_7 ,
const char * V_133 , int V_221 )
{
struct V_291 V_126 ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_292 = V_293 ;
V_126 . V_237 = V_221 ;
if ( F_33 ( strlen ( V_133 ) >= sizeof( V_126 . V_133 ) ) )
return NULL ;
strcpy ( V_126 . V_133 , V_133 ) ;
return F_146 ( V_7 -> V_29 -> V_105 , & V_126 ) ;
}
struct V_260 * F_147 ( struct V_6 * V_7 ,
const char * V_133 )
{
return F_145 ( V_7 , V_133 , 0 ) ;
}
static int F_148 ( struct V_6 * V_7 , const char * V_133 )
{
int V_221 ;
for ( V_221 = 0 ; V_221 < 16 ; V_221 ++ ) {
if ( ! F_145 ( V_7 , V_133 , V_221 ) )
return V_221 ;
}
return - V_181 ;
}
int F_149 ( struct V_6 * V_7 , T_2 V_19 ,
struct V_260 * V_294 )
{
int V_30 ;
unsigned short V_295 = 0 ;
struct V_186 * V_296 ;
if ( V_294 -> V_126 . V_297 & V_298 ) {
V_295 |= V_299 ;
if ( V_19 == 0 )
V_19 = F_150 ( V_294 -> V_300 ) ;
}
if ( ( V_294 -> V_126 . V_297 & V_301 ) != 0 && V_19 == 0 )
V_19 = V_294 -> V_126 . V_297 & 0xffff ;
if ( V_294 -> V_126 . V_297 & ( V_301 | V_298 ) )
V_294 -> V_126 . V_297 = 0 ;
V_30 = F_151 ( V_7 -> V_29 -> V_105 , V_294 ) ;
if ( V_30 < 0 )
return V_30 ;
V_296 = F_37 ( & V_7 -> V_172 ) ;
if ( ! V_296 )
return - V_76 ;
V_296 -> V_294 = V_294 ;
V_296 -> V_19 = V_19 ;
V_296 -> V_295 = V_295 ;
return 0 ;
}
int F_152 ( struct V_6 * V_7 , struct V_260 * V_294 ,
unsigned int V_237 , T_2 V_19 )
{
struct V_186 * V_296 ;
if ( V_19 > 0 ) {
V_296 = F_37 ( & V_7 -> V_173 ) ;
if ( ! V_296 )
return - V_76 ;
V_296 -> V_294 = V_294 ;
V_296 -> V_237 = V_237 ;
V_296 -> V_19 = V_19 ;
return 0 ;
}
F_13 ( V_25 L_64 ,
V_294 -> V_126 . V_133 , V_294 -> V_126 . V_237 , V_237 ) ;
return - V_56 ;
}
void F_153 ( struct V_6 * V_7 )
{
int V_12 ;
struct V_186 * V_302 = V_7 -> V_172 . V_4 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_172 . V_48 ; V_12 ++ )
F_154 ( V_7 -> V_29 -> V_105 , V_302 [ V_12 ] . V_294 ) ;
F_84 ( & V_7 -> V_172 ) ;
F_84 ( & V_7 -> V_173 ) ;
}
int F_155 ( struct V_28 * V_29 )
{
struct V_104 * V_105 = V_29 -> V_105 ;
struct V_6 * V_7 ;
F_156 ( & V_105 -> V_303 ) ;
if ( V_105 -> V_103 )
goto V_304;
V_105 -> V_103 = 1 ;
if ( ! F_157 ( & V_105 -> V_305 ) )
goto V_306;
F_55 (codec, &bus->codec_list, list) {
int V_307 ;
for ( V_307 = 0 ; V_307 < V_7 -> V_308 ; V_307 ++ ) {
struct V_309 * V_310 = & V_7 -> V_311 [ V_307 ] ;
if ( ! V_310 -> V_307 )
continue;
if ( V_310 -> V_307 -> V_312 [ 0 ] . V_313 ||
V_310 -> V_307 -> V_312 [ 1 ] . V_313 )
goto V_306;
}
}
F_158 ( & V_105 -> V_303 ) ;
return 0 ;
V_306:
V_105 -> V_103 = 0 ;
V_304:
F_158 ( & V_105 -> V_303 ) ;
return - V_56 ;
}
void F_159 ( struct V_28 * V_29 )
{
struct V_104 * V_105 = V_29 -> V_105 ;
V_105 = V_29 -> V_105 ;
F_156 ( & V_105 -> V_303 ) ;
V_105 -> V_103 = 0 ;
F_158 ( & V_105 -> V_303 ) ;
}
int F_160 ( struct V_6 * V_7 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
struct V_104 * V_105 = V_29 -> V_105 ;
int V_12 ;
if ( F_155 ( V_29 ) < 0 )
return - V_181 ;
#ifdef F_87
F_161 ( & V_7 -> V_171 ) ;
V_7 -> V_314 = 0 ;
V_7 -> V_315 = 0 ;
V_7 -> V_316 = V_317 ;
F_48 ( V_29 -> V_90 ) ;
#endif
F_153 ( V_7 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_308 ; V_12 ++ ) {
if ( V_7 -> V_311 [ V_12 ] . V_307 ) {
F_162 ( V_105 , V_7 -> V_311 [ V_12 ] . V_307 ) ;
F_163 ( V_7 -> V_311 [ V_12 ] . V_101 ,
V_29 -> V_318 ) ;
}
}
if ( V_7 -> V_96 . free )
V_7 -> V_96 . free ( V_7 ) ;
F_86 ( V_7 ) ;
V_7 -> V_319 = NULL ;
V_7 -> V_320 = NULL ;
F_89 ( & V_7 -> V_175 ) ;
F_89 ( & V_7 -> V_176 ) ;
F_91 ( & V_7 -> V_175 , sizeof( struct V_184 ) ) ;
F_91 ( & V_7 -> V_176 , sizeof( struct V_185 ) ) ;
F_84 ( & V_7 -> V_165 ) ;
F_80 ( V_7 ) ;
F_84 ( & V_7 -> V_170 ) ;
F_84 ( & V_7 -> V_174 ) ;
V_7 -> V_308 = 0 ;
V_7 -> V_311 = NULL ;
V_7 -> V_2 = NULL ;
memset ( & V_7 -> V_96 , 0 , sizeof( V_7 -> V_96 ) ) ;
V_7 -> V_321 = NULL ;
V_7 -> V_322 = 0 ;
F_66 ( V_7 -> V_125 ) ;
V_7 -> V_125 = NULL ;
F_159 ( V_29 ) ;
return 0 ;
}
static int F_164 ( struct V_6 * V_7 , const char * const * V_323 ,
const char * V_324 , T_6 V_325 , void * V_326 )
{
struct V_186 * V_302 ;
const char * const * V_327 ;
int V_12 , V_30 ;
V_302 = V_7 -> V_172 . V_4 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_172 . V_48 ; V_12 ++ ) {
struct V_260 * V_328 = V_302 [ V_12 ] . V_294 ;
if ( ! V_328 || ! V_328 -> V_126 . V_133 ||
V_328 -> V_126 . V_292 != V_293 )
continue;
for ( V_327 = V_323 ; * V_327 ; V_327 ++ ) {
char V_329 [ sizeof( V_328 -> V_126 . V_133 ) ] ;
const char * V_133 = * V_327 ;
if ( V_324 ) {
snprintf ( V_329 , sizeof( V_329 ) , L_59 ,
V_133 , V_324 ) ;
V_133 = V_329 ;
}
if ( ! strcmp ( V_328 -> V_126 . V_133 , V_133 ) ) {
V_30 = V_325 ( V_326 , V_328 ) ;
if ( V_30 )
return V_30 ;
break;
}
}
}
return 0 ;
}
static int F_165 ( void * V_326 , struct V_260 * V_328 )
{
return 1 ;
}
static int F_166 ( struct V_260 * V_294 )
{
int V_278 [ 4 ] ;
const int * V_289 = NULL ;
int V_23 = - 1 ;
if ( V_294 -> V_330 [ 0 ] . V_331 & V_332 ) {
T_7 V_333 = F_167 () ;
F_168 ( F_169 () ) ;
if ( ! V_294 -> V_289 . V_135 ( V_294 , 0 , sizeof( V_278 ) , V_278 ) )
V_289 = V_278 ;
F_168 ( V_333 ) ;
} else if ( V_294 -> V_330 [ 0 ] . V_331 & V_334 )
V_289 = V_294 -> V_289 . V_49 ;
if ( V_289 && V_289 [ 0 ] == V_287 )
V_23 = - V_289 [ 2 ] / V_289 [ 3 ] ;
return V_23 ;
}
static int F_170 ( struct V_260 * V_294 , int V_23 )
{
struct V_272 * V_273 ;
V_273 = F_45 ( sizeof( * V_273 ) , V_98 ) ;
if ( ! V_273 )
return - V_76 ;
V_273 -> V_267 . integer . V_267 [ 0 ] = V_23 ;
V_273 -> V_267 . integer . V_267 [ 1 ] = V_23 ;
V_294 -> V_335 ( V_294 , V_273 ) ;
F_49 ( V_273 ) ;
return 0 ;
}
static int F_171 ( void * V_326 , struct V_260 * V_336 )
{
int V_337 = F_166 ( V_336 ) ;
if ( V_337 > 0 )
F_170 ( V_336 , V_337 ) ;
return 0 ;
}
static int F_172 ( void * V_326 , struct V_260 * V_336 )
{
return F_170 ( V_336 , 1 ) ;
}
int F_173 ( struct V_6 * V_7 , char * V_133 ,
unsigned int * V_289 , const char * const * V_323 ,
const char * V_324 , bool V_338 ,
struct V_260 * * V_339 )
{
struct V_260 * V_294 ;
int V_30 ;
if ( V_339 )
* V_339 = NULL ;
V_30 = F_164 ( V_7 , V_323 , V_324 , F_165 , NULL ) ;
if ( V_30 != 1 ) {
F_95 ( L_65 , V_133 ) ;
return 0 ;
}
V_294 = F_174 ( V_133 , V_289 ) ;
if ( ! V_294 )
return - V_76 ;
V_30 = F_149 ( V_7 , 0 , V_294 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_164 ( V_7 , V_323 , V_324 ,
( T_6 ) V_340 , V_294 ) ;
if ( V_30 < 0 )
return V_30 ;
F_170 ( V_294 , 0 ) ;
if ( V_338 )
F_164 ( V_7 , V_323 , V_324 ,
V_289 ? F_171 : F_172 , V_294 ) ;
if ( V_339 )
* V_339 = V_294 ;
return 0 ;
}
static int F_175 ( struct V_260 * V_261 ,
struct V_262 * V_263 )
{
static const char * const V_341 [] = {
L_66 , L_67 , L_68
} ;
unsigned int V_237 ;
V_263 -> type = V_342 ;
V_263 -> V_266 = 1 ;
V_263 -> V_267 . V_343 . V_302 = 3 ;
V_237 = V_263 -> V_267 . V_343 . V_296 ;
if ( V_237 >= 3 )
V_237 = 2 ;
strcpy ( V_263 -> V_267 . V_343 . V_133 , V_341 [ V_237 ] ) ;
return 0 ;
}
static int F_176 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_344 * V_345 = F_131 ( V_261 ) ;
V_273 -> V_267 . V_343 . V_296 [ 0 ] = V_345 -> V_346 ;
return 0 ;
}
static int F_177 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_344 * V_345 = F_131 ( V_261 ) ;
unsigned int V_347 = V_345 -> V_346 ;
V_345 -> V_346 = V_273 -> V_267 . V_343 . V_296 [ 0 ] ;
if ( V_345 -> V_346 > V_348 )
V_345 -> V_346 = V_348 ;
if ( V_347 == V_345 -> V_346 )
return 0 ;
F_178 ( V_345 ) ;
return 1 ;
}
int F_179 ( struct V_6 * V_7 ,
struct V_344 * V_345 ,
bool V_349 )
{
struct V_260 * V_294 ;
if ( ! V_345 -> V_345 || ! V_345 -> V_350 )
return 0 ;
F_180 ( V_345 -> V_350 , V_345 -> V_345 , V_7 ) ;
V_345 -> V_7 = V_7 ;
V_345 -> V_346 = V_348 ;
if ( ! V_349 )
return 0 ;
V_294 = F_181 ( & V_351 , V_345 ) ;
if ( ! V_294 )
return - V_76 ;
return F_149 ( V_7 , 0 , V_294 ) ;
}
void F_178 ( struct V_344 * V_345 )
{
if ( ! V_345 -> V_345 || ! V_345 -> V_7 )
return;
switch ( V_345 -> V_346 ) {
case V_348 :
F_182 ( V_345 -> V_350 ) ;
break;
default:
V_345 -> V_345 ( V_345 -> V_7 , V_345 -> V_346 ) ;
break;
}
}
int F_183 ( struct V_260 * V_261 ,
struct V_262 * V_263 )
{
int V_264 = F_133 ( V_261 ) ;
V_263 -> type = V_352 ;
V_263 -> V_266 = V_264 == 3 ? 2 : 1 ;
V_263 -> V_267 . integer . V_268 = 0 ;
V_263 -> V_267 . integer . V_269 = 1 ;
return 0 ;
}
int F_184 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
T_2 V_19 = F_132 ( V_261 ) ;
int V_264 = F_133 ( V_261 ) ;
int V_233 = F_134 ( V_261 ) ;
int V_221 = F_139 ( V_261 ) ;
long * V_274 = V_273 -> V_267 . integer . V_267 ;
if ( V_264 & 1 )
* V_274 ++ = ( F_125 ( V_7 , V_19 , 0 , V_233 , V_221 ) &
V_251 ) ? 0 : 1 ;
if ( V_264 & 2 )
* V_274 = ( F_125 ( V_7 , V_19 , 1 , V_233 , V_221 ) &
V_251 ) ? 0 : 1 ;
return 0 ;
}
int F_185 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
T_2 V_19 = F_132 ( V_261 ) ;
int V_264 = F_133 ( V_261 ) ;
int V_233 = F_134 ( V_261 ) ;
int V_221 = F_139 ( V_261 ) ;
long * V_274 = V_273 -> V_267 . integer . V_267 ;
int V_275 = 0 ;
F_15 ( V_7 ) ;
if ( V_264 & 1 ) {
V_275 = F_126 ( V_7 , V_19 , 0 , V_233 , V_221 ,
V_251 ,
* V_274 ? 0 : V_251 ) ;
V_274 ++ ;
}
if ( V_264 & 2 )
V_275 |= F_126 ( V_7 , V_19 , 1 , V_233 , V_221 ,
V_251 ,
* V_274 ? 0 : V_251 ) ;
F_186 ( V_7 , V_19 ) ;
F_18 ( V_7 ) ;
return V_275 ;
}
int F_187 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
long * V_274 = V_273 -> V_267 . integer . V_267 ;
F_188 ( V_7 , * V_274 ) ;
return F_185 ( V_261 , V_273 ) ;
}
int F_189 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
unsigned long V_353 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_353 = V_261 -> V_300 ;
V_261 -> V_300 = V_353 & ~ V_354 ;
V_30 = F_184 ( V_261 , V_273 ) ;
V_261 -> V_300 = V_353 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_190 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
unsigned long V_353 ;
int V_12 , V_355 , V_30 = 0 , V_275 = 0 ;
F_2 ( & V_7 -> V_183 ) ;
V_353 = V_261 -> V_300 ;
V_355 = ( V_353 & V_354 ) >> V_356 ;
for ( V_12 = 0 ; V_12 < V_355 ; V_12 ++ ) {
V_261 -> V_300 = ( V_353 & ~ V_354 ) |
( V_12 << V_356 ) ;
V_30 = F_185 ( V_261 , V_273 ) ;
if ( V_30 < 0 )
break;
V_275 |= V_30 ;
}
V_261 -> V_300 = V_353 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 < 0 ? V_30 : V_275 ;
}
int F_191 ( struct V_260 * V_261 ,
struct V_262 * V_263 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
struct V_357 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_357 * ) V_261 -> V_300 ;
V_261 -> V_300 = * V_135 -> V_358 ;
V_30 = V_135 -> V_33 -> V_223 ( V_261 , V_263 ) ;
V_261 -> V_300 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_192 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
struct V_357 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_357 * ) V_261 -> V_300 ;
V_261 -> V_300 = * V_135 -> V_358 ;
V_30 = V_135 -> V_33 -> V_359 ( V_261 , V_273 ) ;
V_261 -> V_300 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_193 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
struct V_357 * V_135 ;
unsigned long * V_360 ;
int V_30 = 0 , V_275 = 0 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_357 * ) V_261 -> V_300 ;
for ( V_360 = V_135 -> V_358 ; * V_360 ; V_360 ++ ) {
V_261 -> V_300 = * V_360 ;
V_30 = V_135 -> V_33 -> V_335 ( V_261 , V_273 ) ;
if ( V_30 < 0 )
break;
V_275 |= V_30 ;
}
V_261 -> V_300 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 < 0 ? V_30 : V_275 ;
}
int F_194 ( struct V_260 * V_261 , int V_276 ,
unsigned int V_277 , unsigned int T_5 * V_289 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
struct V_357 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_357 * ) V_261 -> V_300 ;
V_261 -> V_300 = * V_135 -> V_358 ;
V_30 = V_135 -> V_33 -> V_289 ( V_261 , V_276 , V_277 , V_289 ) ;
V_261 -> V_300 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
static int F_195 ( struct V_260 * V_261 ,
struct V_262 * V_263 )
{
V_263 -> type = V_361 ;
V_263 -> V_266 = 1 ;
return 0 ;
}
static int F_196 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
V_273 -> V_267 . V_362 . V_363 [ 0 ] = V_364 |
V_365 |
V_366 |
V_367 ;
V_273 -> V_267 . V_362 . V_363 [ 1 ] = V_368 |
V_369 ;
return 0 ;
}
static int F_197 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
V_273 -> V_267 . V_362 . V_363 [ 0 ] = V_364 |
V_365 |
V_370 ;
return 0 ;
}
static int F_198 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
int V_221 = V_261 -> V_300 ;
struct V_187 * V_371 ;
F_2 ( & V_7 -> V_182 ) ;
V_371 = F_27 ( & V_7 -> V_174 , V_221 ) ;
V_273 -> V_267 . V_362 . V_363 [ 0 ] = V_371 -> V_363 & 0xff ;
V_273 -> V_267 . V_362 . V_363 [ 1 ] = ( V_371 -> V_363 >> 8 ) & 0xff ;
V_273 -> V_267 . V_362 . V_363 [ 2 ] = ( V_371 -> V_363 >> 16 ) & 0xff ;
V_273 -> V_267 . V_362 . V_363 [ 3 ] = ( V_371 -> V_363 >> 24 ) & 0xff ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
static unsigned short F_199 ( unsigned int V_372 )
{
unsigned short V_23 = 0 ;
if ( V_372 & V_364 )
V_23 |= V_373 ;
if ( V_372 & V_365 )
V_23 |= V_374 ;
if ( V_372 & V_364 ) {
if ( ( V_372 & V_375 ) ==
V_370 )
V_23 |= V_376 ;
} else {
if ( ( V_372 & V_377 ) ==
V_366 )
V_23 |= V_376 ;
if ( ! ( V_372 & V_367 ) )
V_23 |= V_378 ;
if ( V_372 & ( V_369 << 8 ) )
V_23 |= V_379 ;
V_23 |= V_372 & ( V_368 << 8 ) ;
}
return V_23 ;
}
static unsigned int F_200 ( unsigned short V_23 )
{
unsigned int V_372 = 0 ;
if ( V_23 & V_374 )
V_372 |= V_365 ;
if ( V_23 & V_373 )
V_372 |= V_364 ;
if ( V_372 & V_364 ) {
if ( V_372 & V_376 )
V_372 |= V_370 ;
} else {
if ( V_23 & V_376 )
V_372 |= V_366 ;
if ( ! ( V_23 & V_378 ) )
V_372 |= V_367 ;
if ( V_23 & V_379 )
V_372 |= ( V_369 << 8 ) ;
V_372 |= V_23 & ( 0x7f << 8 ) ;
}
return V_372 ;
}
static void F_201 ( struct V_6 * V_7 , T_2 V_19 ,
int V_21 , int V_23 )
{
const T_2 * V_380 ;
F_202 ( V_7 , V_19 , 0 , V_21 , V_23 ) ;
V_380 = V_7 -> V_321 ;
if ( ! V_380 )
return;
for (; * V_380 ; V_380 ++ )
F_202 ( V_7 , * V_380 , 0 , V_21 , V_23 ) ;
}
static inline void F_203 ( struct V_6 * V_7 , T_2 V_19 ,
int V_381 , int V_382 )
{
if ( V_381 != - 1 )
F_201 ( V_7 , V_19 , V_383 , V_381 ) ;
if ( V_382 != - 1 )
F_201 ( V_7 , V_19 , V_384 , V_382 ) ;
}
static int F_204 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
int V_221 = V_261 -> V_300 ;
struct V_187 * V_371 ;
T_2 V_19 ;
unsigned short V_23 ;
int V_275 ;
F_2 ( & V_7 -> V_182 ) ;
V_371 = F_27 ( & V_7 -> V_174 , V_221 ) ;
V_19 = V_371 -> V_19 ;
V_371 -> V_363 = V_273 -> V_267 . V_362 . V_363 [ 0 ] |
( ( unsigned int ) V_273 -> V_267 . V_362 . V_363 [ 1 ] << 8 ) |
( ( unsigned int ) V_273 -> V_267 . V_362 . V_363 [ 2 ] << 16 ) |
( ( unsigned int ) V_273 -> V_267 . V_362 . V_363 [ 3 ] << 24 ) ;
V_23 = F_199 ( V_371 -> V_363 ) ;
V_23 |= V_371 -> V_385 & 1 ;
V_275 = V_371 -> V_385 != V_23 ;
V_371 -> V_385 = V_23 ;
if ( V_275 && V_19 != ( T_3 ) - 1 )
F_203 ( V_7 , V_19 , V_23 & 0xff , ( V_23 >> 8 ) & 0xff ) ;
F_4 ( & V_7 -> V_182 ) ;
return V_275 ;
}
static int F_205 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
int V_221 = V_261 -> V_300 ;
struct V_187 * V_371 ;
F_2 ( & V_7 -> V_182 ) ;
V_371 = F_27 ( & V_7 -> V_174 , V_221 ) ;
V_273 -> V_267 . integer . V_267 [ 0 ] = V_371 -> V_385 & V_386 ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
static inline void F_206 ( struct V_6 * V_7 , T_2 V_19 ,
int V_381 , int V_382 )
{
F_203 ( V_7 , V_19 , V_381 , V_382 ) ;
if ( ( F_34 ( V_7 , V_19 ) & V_387 ) &&
( V_381 & V_386 ) )
F_127 ( V_7 , V_19 , V_230 , 0 ,
V_251 , 0 ) ;
}
static int F_207 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
int V_221 = V_261 -> V_300 ;
struct V_187 * V_371 ;
T_2 V_19 ;
unsigned short V_23 ;
int V_275 ;
F_2 ( & V_7 -> V_182 ) ;
V_371 = F_27 ( & V_7 -> V_174 , V_221 ) ;
V_19 = V_371 -> V_19 ;
V_23 = V_371 -> V_385 & ~ V_386 ;
if ( V_273 -> V_267 . integer . V_267 [ 0 ] )
V_23 |= V_386 ;
V_275 = V_371 -> V_385 != V_23 ;
V_371 -> V_385 = V_23 ;
if ( V_275 && V_19 != ( T_3 ) - 1 )
F_206 ( V_7 , V_19 , V_23 & 0xff , - 1 ) ;
F_4 ( & V_7 -> V_182 ) ;
return V_275 ;
}
int F_208 ( struct V_6 * V_7 ,
T_2 V_388 ,
T_2 V_389 )
{
int V_30 ;
struct V_260 * V_294 ;
struct V_390 * V_391 ;
int V_221 ;
struct V_187 * V_371 ;
V_221 = F_148 ( V_7 , L_69 ) ;
if ( V_221 < 0 ) {
F_13 ( V_25 L_70 ) ;
return - V_181 ;
}
V_371 = F_37 ( & V_7 -> V_174 ) ;
for ( V_391 = V_392 ; V_391 -> V_133 ; V_391 ++ ) {
V_294 = F_181 ( V_391 , V_7 ) ;
if ( ! V_294 )
return - V_76 ;
V_294 -> V_126 . V_237 = V_221 ;
V_294 -> V_300 = V_7 -> V_174 . V_48 - 1 ;
V_30 = F_149 ( V_7 , V_388 , V_294 ) ;
if ( V_30 < 0 )
return V_30 ;
}
V_371 -> V_19 = V_389 ;
V_371 -> V_385 = F_21 ( V_7 , V_389 , 0 ,
V_393 , 0 ) ;
V_371 -> V_363 = F_200 ( V_371 -> V_385 ) ;
return 0 ;
}
struct V_187 * F_209 ( struct V_6 * V_7 ,
T_2 V_19 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_174 . V_48 ; V_12 ++ ) {
struct V_187 * V_371 =
F_27 ( & V_7 -> V_174 , V_12 ) ;
if ( V_371 -> V_19 == V_19 )
return V_371 ;
}
return NULL ;
}
void F_210 ( struct V_6 * V_7 , int V_221 )
{
struct V_187 * V_371 ;
F_2 ( & V_7 -> V_182 ) ;
V_371 = F_27 ( & V_7 -> V_174 , V_221 ) ;
V_371 -> V_19 = ( T_3 ) - 1 ;
F_4 ( & V_7 -> V_182 ) ;
}
void F_211 ( struct V_6 * V_7 , int V_221 , T_2 V_19 )
{
struct V_187 * V_371 ;
unsigned short V_23 ;
F_2 ( & V_7 -> V_182 ) ;
V_371 = F_27 ( & V_7 -> V_174 , V_221 ) ;
if ( V_371 -> V_19 != V_19 ) {
V_371 -> V_19 = V_19 ;
V_23 = V_371 -> V_385 ;
F_206 ( V_7 , V_19 , V_23 & 0xff , ( V_23 >> 8 ) & 0xff ) ;
}
F_4 ( & V_7 -> V_182 ) ;
}
static int F_212 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_394 * V_395 = F_131 ( V_261 ) ;
V_273 -> V_267 . integer . V_267 [ 0 ] = V_395 -> V_396 ;
return 0 ;
}
static int F_213 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_394 * V_395 = F_131 ( V_261 ) ;
V_395 -> V_396 = ! ! V_273 -> V_267 . integer . V_267 [ 0 ] ;
return 0 ;
}
int F_214 ( struct V_6 * V_7 ,
struct V_394 * V_395 )
{
if ( ! V_395 -> V_397 )
return 0 ;
return F_149 ( V_7 , V_395 -> V_397 ,
F_181 ( & V_398 , V_395 ) ) ;
}
static int F_215 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
V_273 -> V_267 . integer . V_267 [ 0 ] = V_7 -> V_399 ;
return 0 ;
}
static int F_216 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
T_2 V_19 = V_261 -> V_300 ;
unsigned int V_23 = ! ! V_273 -> V_267 . integer . V_267 [ 0 ] ;
int V_275 ;
F_2 ( & V_7 -> V_182 ) ;
V_275 = V_7 -> V_399 != V_23 ;
if ( V_275 ) {
V_7 -> V_399 = V_23 ;
F_202 ( V_7 , V_19 , 0 ,
V_383 , V_23 ) ;
}
F_4 ( & V_7 -> V_182 ) ;
return V_275 ;
}
static int F_217 ( struct V_260 * V_261 ,
struct V_272 * V_273 )
{
struct V_6 * V_7 = F_131 ( V_261 ) ;
T_2 V_19 = V_261 -> V_300 ;
unsigned short V_23 ;
unsigned int V_372 ;
V_23 = F_21 ( V_7 , V_19 , 0 , V_393 , 0 ) ;
V_372 = F_200 ( V_23 ) ;
V_273 -> V_267 . V_362 . V_363 [ 0 ] = V_372 ;
V_273 -> V_267 . V_362 . V_363 [ 1 ] = V_372 >> 8 ;
V_273 -> V_267 . V_362 . V_363 [ 2 ] = V_372 >> 16 ;
V_273 -> V_267 . V_362 . V_363 [ 3 ] = V_372 >> 24 ;
return 0 ;
}
int F_218 ( struct V_6 * V_7 , T_2 V_19 )
{
int V_30 ;
struct V_260 * V_294 ;
struct V_390 * V_391 ;
int V_221 ;
V_221 = F_148 ( V_7 , L_71 ) ;
if ( V_221 < 0 ) {
F_13 ( V_25 L_72 ) ;
return - V_181 ;
}
for ( V_391 = V_400 ; V_391 -> V_133 ; V_391 ++ ) {
V_294 = F_181 ( V_391 , V_7 ) ;
if ( ! V_294 )
return - V_76 ;
V_294 -> V_300 = V_19 ;
V_30 = F_149 ( V_7 , V_19 , V_294 ) ;
if ( V_30 < 0 )
return V_30 ;
}
V_7 -> V_399 =
F_21 ( V_7 , V_19 , 0 ,
V_393 , 0 ) &
V_386 ;
return 0 ;
}
int F_202 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 , unsigned int V_21 , unsigned int V_22 )
{
int V_30 = F_22 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
struct V_185 * V_135 ;
T_1 V_220 ;
if ( V_30 < 0 )
return V_30 ;
V_21 = V_21 | ( V_22 >> 8 ) ;
V_22 &= 0xff ;
V_220 = F_219 ( V_19 , V_21 ) ;
F_2 ( & V_7 -> V_29 -> V_32 ) ;
V_135 = F_109 ( & V_7 -> V_176 , V_220 ) ;
if ( V_135 )
V_135 -> V_23 = V_22 ;
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return 0 ;
}
int F_220 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 , unsigned int V_21 , unsigned int V_22 )
{
struct V_185 * V_135 ;
T_1 V_220 ;
V_21 = V_21 | ( V_22 >> 8 ) ;
V_22 &= 0xff ;
V_220 = F_219 ( V_19 , V_21 ) ;
F_2 ( & V_7 -> V_29 -> V_32 ) ;
V_135 = F_108 ( & V_7 -> V_176 , V_220 ) ;
if ( V_135 && V_135 -> V_23 == V_22 ) {
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return 0 ;
}
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return F_202 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
}
void F_221 ( struct V_6 * V_7 )
{
struct V_185 * V_256 = V_7 -> V_176 . V_219 . V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_176 . V_219 . V_48 ; V_12 ++ , V_256 ++ ) {
T_1 V_220 = V_256 -> V_220 ;
if ( ! V_220 )
continue;
F_22 ( V_7 , F_222 ( V_220 ) , 0 ,
F_223 ( V_220 ) , V_256 -> V_23 ) ;
}
}
void F_224 ( struct V_6 * V_7 ,
const struct V_40 * V_41 )
{
for (; V_41 -> V_19 ; V_41 ++ )
F_202 ( V_7 , V_41 -> V_19 , 0 , V_41 -> V_21 ,
V_41 -> V_42 ) ;
}
void F_225 ( struct V_6 * V_7 , T_2 V_401 ,
unsigned int V_402 ,
bool V_403 )
{
T_2 V_19 = V_7 -> V_154 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_153 ; V_12 ++ , V_19 ++ ) {
unsigned int V_62 = F_34 ( V_7 , V_19 ) ;
if ( ! ( V_62 & V_404 ) )
continue;
if ( V_403 && V_402 == V_405 &&
F_35 ( V_62 ) == V_82 &&
( F_119 ( V_7 , V_19 ) & V_406 ) ) {
int V_407 = F_21 ( V_7 , V_19 , 0 ,
V_408 , 0 ) ;
if ( V_407 & 0x02 )
continue;
}
F_22 ( V_7 , V_19 , 0 , V_409 ,
V_402 ) ;
}
if ( V_402 == V_196 ) {
unsigned long V_410 ;
int V_411 ;
V_410 = V_317 + F_226 ( 500 ) ;
do {
V_411 = F_21 ( V_7 , V_401 , 0 ,
V_412 , 0 ) ;
if ( V_411 == V_402 )
break;
F_103 ( 1 ) ;
} while ( F_227 ( V_410 , V_317 ) );
}
}
static void F_96 ( struct V_6 * V_7 , T_2 V_401 ,
unsigned int V_402 )
{
if ( V_7 -> V_96 . V_413 ) {
V_7 -> V_96 . V_413 ( V_7 , V_401 , V_402 ) ;
return;
}
if ( V_402 == V_405 )
F_103 ( 100 ) ;
F_21 ( V_7 , V_401 , 0 , V_409 ,
V_402 ) ;
F_225 ( V_7 , V_401 , V_402 , true ) ;
}
static void F_228 ( struct V_6 * V_7 )
{
if ( V_7 -> V_414 . V_4 )
F_23 ( V_7 , V_7 -> V_414 . V_4 ) ;
}
static inline void F_228 ( struct V_6 * V_7 ) {}
static void F_229 ( struct V_6 * V_7 )
{
if ( V_7 -> V_96 . V_415 )
V_7 -> V_96 . V_415 ( V_7 , V_416 ) ;
F_107 ( V_7 ) ;
F_96 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_405 ) ;
#ifdef F_87
F_88 ( & V_7 -> V_171 ) ;
F_156 ( & V_7 -> V_188 ) ;
F_230 ( V_7 ) ;
F_231 ( V_7 ) ;
V_7 -> V_314 = 0 ;
V_7 -> V_315 = 0 ;
V_7 -> V_316 = V_317 ;
F_158 ( & V_7 -> V_188 ) ;
#endif
}
static void F_232 ( struct V_6 * V_7 )
{
F_7 ( V_7 ) ;
F_96 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_196 ) ;
F_80 ( V_7 ) ;
F_82 ( V_7 ) ;
F_228 ( V_7 ) ;
F_233 ( V_7 ) ;
if ( V_7 -> V_96 . V_417 )
V_7 -> V_96 . V_417 ( V_7 ) ;
else {
if ( V_7 -> V_96 . V_418 )
V_7 -> V_96 . V_418 ( V_7 ) ;
F_128 ( V_7 ) ;
F_221 ( V_7 ) ;
}
F_18 ( V_7 ) ;
}
int F_234 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
int V_30 = F_235 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_73
L_74 , V_7 -> V_24 , V_30 ) ;
V_30 = F_160 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25
L_75 ) ;
return V_30 ;
}
}
}
return 0 ;
}
int F_235 ( struct V_6 * V_7 )
{
int V_30 = 0 ;
F_228 ( V_7 ) ;
if ( V_7 -> V_96 . V_418 )
V_30 = V_7 -> V_96 . V_418 ( V_7 ) ;
if ( ! V_30 && V_7 -> V_96 . V_419 )
V_30 = V_7 -> V_96 . V_419 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
unsigned int F_236 ( unsigned int V_420 ,
unsigned int V_421 ,
unsigned int V_202 ,
unsigned int V_422 ,
unsigned short V_423 )
{
int V_12 ;
unsigned int V_23 = 0 ;
for ( V_12 = 0 ; V_424 [ V_12 ] . V_425 ; V_12 ++ )
if ( V_424 [ V_12 ] . V_425 == V_420 ) {
V_23 = V_424 [ V_12 ] . V_426 ;
break;
}
if ( ! V_424 [ V_12 ] . V_425 ) {
F_95 ( L_76 , V_420 ) ;
return 0 ;
}
if ( V_421 == 0 || V_421 > 8 ) {
F_95 ( L_77 , V_421 ) ;
return 0 ;
}
V_23 |= V_421 - 1 ;
switch ( F_237 ( V_202 ) ) {
case 8 :
V_23 |= V_427 ;
break;
case 16 :
V_23 |= V_428 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_422 >= 32 || V_202 == V_429 )
V_23 |= V_430 ;
else if ( V_422 >= 24 )
V_23 |= V_431 ;
else
V_23 |= V_432 ;
break;
default:
F_95 ( L_78 ,
F_237 ( V_202 ) ) ;
return 0 ;
}
if ( V_423 & V_374 )
V_23 |= V_433 ;
return V_23 ;
}
static unsigned int F_238 ( struct V_6 * V_7 , T_2 V_19 ,
int V_233 )
{
unsigned int V_23 = 0 ;
if ( V_19 != V_7 -> V_127 &&
( F_34 ( V_7 , V_19 ) & V_434 ) )
V_23 = F_25 ( V_7 , V_19 , V_435 ) ;
if ( ! V_23 || V_23 == - 1 )
V_23 = F_25 ( V_7 , V_7 -> V_127 , V_435 ) ;
if ( ! V_23 || V_23 == - 1 )
return 0 ;
return V_23 ;
}
static unsigned int F_239 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_115 ( V_7 , V_19 , 0 , F_240 ( V_19 ) ,
F_238 ) ;
}
static unsigned int F_241 ( struct V_6 * V_7 , T_2 V_19 ,
int V_233 )
{
unsigned int V_312 = F_25 ( V_7 , V_19 , V_436 ) ;
if ( ! V_312 || V_312 == - 1 )
V_312 = F_25 ( V_7 , V_7 -> V_127 , V_436 ) ;
if ( ! V_312 || V_312 == - 1 )
return 0 ;
return V_312 ;
}
static unsigned int F_242 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_115 ( V_7 , V_19 , 0 , F_243 ( V_19 ) ,
F_241 ) ;
}
int F_244 ( struct V_6 * V_7 , T_2 V_19 ,
T_1 * V_437 , T_8 * V_438 , unsigned int * V_439 )
{
unsigned int V_12 , V_23 , V_62 ;
V_62 = F_34 ( V_7 , V_19 ) ;
V_23 = F_239 ( V_7 , V_19 ) ;
if ( V_437 ) {
T_1 V_440 = 0 ;
for ( V_12 = 0 ; V_12 < V_441 ; V_12 ++ ) {
if ( V_23 & ( 1 << V_12 ) )
V_440 |= V_424 [ V_12 ] . V_442 ;
}
if ( V_440 == 0 ) {
F_32 ( V_25 L_79
L_80 ,
V_19 , V_23 ,
( V_62 & V_434 ) ? 1 : 0 ) ;
return - V_70 ;
}
* V_437 = V_440 ;
}
if ( V_438 || V_439 ) {
T_8 V_443 = 0 ;
unsigned int V_312 , V_444 ;
V_312 = F_242 ( V_7 , V_19 ) ;
if ( ! V_312 )
return - V_70 ;
V_444 = 0 ;
if ( V_312 & V_445 ) {
if ( V_23 & V_446 ) {
V_443 |= V_447 ;
V_444 = 8 ;
}
if ( V_23 & V_448 ) {
V_443 |= V_449 ;
V_444 = 16 ;
}
if ( V_62 & V_450 ) {
if ( V_23 & V_451 )
V_443 |= V_452 ;
if ( V_23 & ( V_453 | V_454 ) )
V_443 |= V_455 ;
if ( V_23 & V_454 )
V_444 = 24 ;
else if ( V_23 & V_453 )
V_444 = 20 ;
} else if ( V_23 & ( V_453 | V_454 |
V_451 ) ) {
V_443 |= V_455 ;
if ( V_23 & V_451 )
V_444 = 32 ;
else if ( V_23 & V_454 )
V_444 = 24 ;
else if ( V_23 & V_453 )
V_444 = 20 ;
}
}
#if 0
if (streams & AC_SUPFMT_FLOAT32) {
formats |= SNDRV_PCM_FMTBIT_FLOAT_LE;
if (!bps)
bps = 32;
}
#endif
if ( V_312 == V_456 ) {
V_443 |= V_447 ;
V_444 = 8 ;
}
if ( V_443 == 0 ) {
F_32 ( V_25 L_81
L_82
L_83 ,
V_19 , V_23 ,
( V_62 & V_434 ) ? 1 : 0 ,
V_312 ) ;
return - V_70 ;
}
if ( V_438 )
* V_438 = V_443 ;
if ( V_439 )
* V_439 = V_444 ;
}
return 0 ;
}
int F_245 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_202 )
{
int V_12 ;
unsigned int V_23 = 0 , V_420 , V_457 ;
V_23 = F_239 ( V_7 , V_19 ) ;
if ( ! V_23 )
return 0 ;
V_420 = V_202 & 0xff00 ;
for ( V_12 = 0 ; V_12 < V_441 ; V_12 ++ )
if ( V_424 [ V_12 ] . V_426 == V_420 ) {
if ( V_23 & ( 1 << V_12 ) )
break;
return 0 ;
}
if ( V_12 >= V_441 )
return 0 ;
V_457 = F_242 ( V_7 , V_19 ) ;
if ( ! V_457 )
return 0 ;
if ( V_457 & V_445 ) {
switch ( V_202 & 0xf0 ) {
case 0x00 :
if ( ! ( V_23 & V_446 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_23 & V_448 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_23 & V_453 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_23 & V_454 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_23 & V_451 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_246 ( struct V_458 * V_459 ,
struct V_6 * V_7 ,
struct V_460 * V_461 )
{
return 0 ;
}
static int F_247 ( struct V_458 * V_459 ,
struct V_6 * V_7 ,
unsigned int V_200 ,
unsigned int V_202 ,
struct V_460 * V_461 )
{
F_102 ( V_7 , V_459 -> V_19 , V_200 , 0 , V_202 ) ;
return 0 ;
}
static int F_248 ( struct V_458 * V_459 ,
struct V_6 * V_7 ,
struct V_460 * V_461 )
{
F_249 ( V_7 , V_459 -> V_19 ) ;
return 0 ;
}
static int F_250 ( struct V_6 * V_7 ,
struct V_458 * V_223 )
{
int V_30 ;
if ( V_223 -> V_19 && ( ! V_223 -> V_440 || ! V_223 -> V_443 ) ) {
V_30 = F_244 ( V_7 , V_223 -> V_19 ,
V_223 -> V_440 ? NULL : & V_223 -> V_440 ,
V_223 -> V_443 ? NULL : & V_223 -> V_443 ,
V_223 -> V_422 ? NULL : & V_223 -> V_422 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( V_223 -> V_33 . V_462 == NULL )
V_223 -> V_33 . V_462 = F_246 ;
if ( V_223 -> V_33 . V_463 == NULL )
V_223 -> V_33 . V_463 = F_246 ;
if ( V_223 -> V_33 . V_464 == NULL ) {
if ( F_33 ( ! V_223 -> V_19 ) )
return - V_56 ;
V_223 -> V_33 . V_464 = F_247 ;
}
if ( V_223 -> V_33 . V_465 == NULL ) {
if ( F_33 ( ! V_223 -> V_19 ) )
return - V_56 ;
V_223 -> V_33 . V_465 = F_248 ;
}
return 0 ;
}
int F_251 ( struct V_6 * V_7 ,
struct V_458 * V_459 ,
unsigned int V_457 ,
unsigned int V_202 ,
struct V_460 * V_461 )
{
int V_255 ;
F_2 ( & V_7 -> V_29 -> V_117 ) ;
V_255 = V_459 -> V_33 . V_464 ( V_459 , V_7 , V_457 , V_202 , V_461 ) ;
if ( V_255 >= 0 )
F_106 ( V_7 ) ;
F_4 ( & V_7 -> V_29 -> V_117 ) ;
return V_255 ;
}
void F_252 ( struct V_6 * V_7 ,
struct V_458 * V_459 ,
struct V_460 * V_461 )
{
F_2 ( & V_7 -> V_29 -> V_117 ) ;
V_459 -> V_33 . V_465 ( V_459 , V_7 , V_461 ) ;
F_4 ( & V_7 -> V_29 -> V_117 ) ;
}
static int F_253 ( struct V_28 * V_29 , int type )
{
static int V_466 [ V_467 ] [ 5 ] = {
[ V_468 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_469 ] = { 1 , - 1 } ,
[ V_470 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_471 ] = { 6 , - 1 } ,
} ;
int V_12 ;
if ( type >= V_467 ) {
F_32 ( V_73 L_84 , type ) ;
return - V_56 ;
}
for ( V_12 = 0 ; V_466 [ type ] [ V_12 ] >= 0 ; V_12 ++ )
if ( ! F_254 ( V_466 [ type ] [ V_12 ] , V_29 -> V_318 ) )
return V_466 [ type ] [ V_12 ] ;
for ( V_12 = 10 ; V_12 < 32 ; V_12 ++ ) {
if ( ! F_254 ( V_12 , V_29 -> V_318 ) )
return V_12 ;
}
F_32 ( V_73 L_85 ,
V_472 [ type ] ) ;
return - V_473 ;
}
static int F_255 ( struct V_6 * V_7 , struct V_309 * V_307 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
struct V_458 * V_223 ;
int V_457 , V_30 ;
if ( F_33 ( ! V_307 -> V_133 ) )
return - V_56 ;
for ( V_457 = 0 ; V_457 < 2 ; V_457 ++ ) {
V_223 = & V_307 -> V_457 [ V_457 ] ;
if ( V_223 -> V_474 ) {
V_30 = F_250 ( V_7 , V_223 ) ;
if ( V_30 < 0 )
return V_30 ;
}
}
return V_29 -> V_33 . V_475 ( V_29 , V_7 , V_307 ) ;
}
int F_256 ( struct V_6 * V_7 )
{
unsigned int V_307 ;
int V_30 ;
if ( ! V_7 -> V_308 ) {
if ( ! V_7 -> V_96 . V_476 )
return 0 ;
V_30 = V_7 -> V_96 . V_476 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_86
L_74 , V_7 -> V_24 , V_30 ) ;
V_30 = F_160 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25
L_75 ) ;
return V_30 ;
}
}
}
for ( V_307 = 0 ; V_307 < V_7 -> V_308 ; V_307 ++ ) {
struct V_309 * V_310 = & V_7 -> V_311 [ V_307 ] ;
int V_477 ;
if ( ! V_310 -> V_457 [ 0 ] . V_474 && ! V_310 -> V_457 [ 1 ] . V_474 )
continue;
if ( ! V_310 -> V_307 ) {
V_477 = F_253 ( V_7 -> V_29 , V_310 -> V_478 ) ;
if ( V_477 < 0 )
continue;
V_310 -> V_101 = V_477 ;
V_30 = F_255 ( V_7 , V_310 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_87
L_88 ,
V_477 , V_7 -> V_24 ) ;
continue;
}
}
}
return 0 ;
}
int T_9 F_257 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
int V_30 = F_256 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
}
return 0 ;
}
int F_258 ( struct V_6 * V_7 ,
int V_479 , const char * const * V_480 ,
const struct V_481 * V_123 )
{
if ( V_7 -> V_115 && V_480 ) {
int V_12 ;
for ( V_12 = 0 ; V_12 < V_479 ; V_12 ++ ) {
if ( V_480 [ V_12 ] &&
! strcmp ( V_7 -> V_115 , V_480 [ V_12 ] ) ) {
F_19 ( V_482 L_89
L_90 , V_480 [ V_12 ] ) ;
return V_12 ;
}
}
}
if ( ! V_7 -> V_29 -> V_114 || ! V_123 )
return - 1 ;
V_123 = F_259 ( V_7 -> V_29 -> V_114 , V_123 ) ;
if ( ! V_123 )
return - 1 ;
if ( V_123 -> V_267 >= 0 && V_123 -> V_267 < V_479 ) {
#ifdef F_260
char V_137 [ 10 ] ;
const char * V_483 = NULL ;
if ( V_480 )
V_483 = V_480 [ V_123 -> V_267 ] ;
if ( ! V_483 ) {
sprintf ( V_137 , L_91 , V_123 -> V_267 ) ;
V_483 = V_137 ;
}
F_95 ( V_482 L_92
L_93 ,
V_483 , V_123 -> V_484 , V_123 -> V_297 ,
( V_123 -> V_133 ? V_123 -> V_133 : L_94 ) ) ;
#endif
return V_123 -> V_267 ;
}
return - 1 ;
}
int F_261 ( struct V_6 * V_7 ,
int V_479 , const char * const * V_480 ,
const struct V_481 * V_123 )
{
const struct V_481 * V_214 ;
for ( V_214 = V_123 ; V_214 -> V_484 ; V_214 ++ ) {
unsigned int V_61 = 0xffff0000 | V_214 -> V_485 ;
unsigned int V_126 = ( V_214 -> V_297 | ( V_214 -> V_484 << 16 ) ) & V_61 ;
if ( ( V_7 -> V_192 & V_61 ) == V_126 )
break;
}
if ( ! V_214 -> V_484 )
return - 1 ;
V_123 = V_214 ;
if ( V_123 -> V_267 >= 0 && V_123 -> V_267 < V_479 ) {
#ifdef F_260
char V_137 [ 10 ] ;
const char * V_483 = NULL ;
if ( V_480 )
V_483 = V_480 [ V_123 -> V_267 ] ;
if ( ! V_483 ) {
sprintf ( V_137 , L_91 , V_123 -> V_267 ) ;
V_483 = V_137 ;
}
F_95 ( V_482 L_92
L_93 ,
V_483 , V_123 -> V_484 , V_123 -> V_297 ,
( V_123 -> V_133 ? V_123 -> V_133 : L_94 ) ) ;
#endif
return V_123 -> V_267 ;
}
return - 1 ;
}
int F_262 ( struct V_6 * V_7 ,
const struct V_390 * V_486 )
{
int V_30 ;
for (; V_486 -> V_133 ; V_486 ++ ) {
struct V_260 * V_294 ;
int V_24 = 0 , V_221 = 0 ;
if ( V_486 -> V_292 == - 1 )
continue;
for (; ; ) {
V_294 = F_181 ( V_486 , V_7 ) ;
if ( ! V_294 )
return - V_76 ;
if ( V_24 > 0 )
V_294 -> V_126 . V_101 = V_24 ;
if ( V_221 > 0 )
V_294 -> V_126 . V_237 = V_221 ;
V_30 = F_149 ( V_7 , 0 , V_294 ) ;
if ( ! V_30 )
break;
if ( ! V_24 && V_7 -> V_24 )
V_24 = V_7 -> V_24 ;
else if ( ! V_221 && ! V_486 -> V_237 ) {
V_221 = F_148 ( V_7 ,
V_486 -> V_133 ) ;
if ( V_221 <= 0 )
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
F_156 ( & V_7 -> V_188 ) ;
if ( V_7 -> V_315 > 0 ) {
F_158 ( & V_7 -> V_188 ) ;
return;
}
if ( ! V_7 -> V_314 || V_7 -> V_487 ) {
V_7 -> V_315 = 0 ;
F_158 ( & V_7 -> V_188 ) ;
return;
}
F_158 ( & V_7 -> V_188 ) ;
F_229 ( V_7 ) ;
if ( V_29 -> V_33 . V_488 )
V_29 -> V_33 . V_488 ( V_29 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
F_156 ( & V_7 -> V_188 ) ;
V_7 -> V_487 ++ ;
V_7 -> V_314 = 1 ;
V_7 -> V_316 = V_317 ;
F_158 ( & V_7 -> V_188 ) ;
}
void F_230 ( struct V_6 * V_7 )
{
unsigned long V_489 = V_317 - V_7 -> V_316 ;
if ( V_7 -> V_314 )
V_7 -> V_490 += V_489 ;
else
V_7 -> V_491 += V_489 ;
V_7 -> V_316 += V_489 ;
}
static void F_263 ( struct V_6 * V_7 , bool V_492 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
F_156 ( & V_7 -> V_188 ) ;
V_7 -> V_487 ++ ;
if ( ( V_7 -> V_314 || V_7 -> V_315 > 0 ) &&
! ( V_492 && V_7 -> V_315 < 0 ) ) {
F_158 ( & V_7 -> V_188 ) ;
return;
}
F_158 ( & V_7 -> V_188 ) ;
F_161 ( & V_7 -> V_171 ) ;
F_156 ( & V_7 -> V_188 ) ;
F_264 ( V_7 ) ;
F_230 ( V_7 ) ;
V_7 -> V_314 = 1 ;
V_7 -> V_316 = V_317 ;
V_7 -> V_315 = 1 ;
F_158 ( & V_7 -> V_188 ) ;
if ( V_29 -> V_33 . V_488 )
V_29 -> V_33 . V_488 ( V_29 ) ;
F_232 ( V_7 ) ;
F_156 ( & V_7 -> V_188 ) ;
V_7 -> V_315 = 0 ;
F_158 ( & V_7 -> V_188 ) ;
}
void F_15 ( struct V_6 * V_7 )
{
F_263 ( V_7 , false ) ;
}
void F_265 ( struct V_6 * V_7 )
{
F_263 ( V_7 , true ) ;
}
void F_18 ( struct V_6 * V_7 )
{
F_156 ( & V_7 -> V_188 ) ;
-- V_7 -> V_487 ;
if ( ! V_7 -> V_314 || V_7 -> V_487 || V_7 -> V_315 ) {
F_158 ( & V_7 -> V_188 ) ;
return;
}
if ( V_116 ( V_7 ) ) {
V_7 -> V_315 = - 1 ;
F_266 ( V_7 -> V_29 -> V_90 , & V_7 -> V_171 ,
F_226 ( V_116 ( V_7 ) * 1000 ) ) ;
}
F_158 ( & V_7 -> V_188 ) ;
}
int F_267 ( struct V_6 * V_7 ,
struct V_493 * V_494 ,
T_2 V_19 )
{
const struct V_495 * V_49 ;
int V_236 , V_496 ;
if ( ! V_494 -> V_497 )
return 0 ;
for ( V_49 = V_494 -> V_497 ; V_49 -> V_19 ; V_49 ++ ) {
if ( V_49 -> V_19 == V_19 )
break;
}
if ( ! V_49 -> V_19 )
return 0 ;
for ( V_49 = V_494 -> V_497 ; V_49 -> V_19 ; V_49 ++ ) {
for ( V_236 = 0 ; V_236 < 2 ; V_236 ++ ) {
V_496 = F_125 ( V_7 , V_49 -> V_19 , V_236 , V_49 -> V_233 ,
V_49 -> V_221 ) ;
if ( ! ( V_496 & V_251 ) && V_496 > 0 ) {
if ( ! V_494 -> V_314 ) {
V_494 -> V_314 = 1 ;
F_15 ( V_7 ) ;
}
return 1 ;
}
}
}
if ( V_494 -> V_314 ) {
V_494 -> V_314 = 0 ;
F_18 ( V_7 ) ;
}
return 0 ;
}
int F_268 ( struct V_6 * V_7 ,
struct V_262 * V_263 ,
const struct V_498 * V_499 ,
int V_500 )
{
V_263 -> type = V_342 ;
V_263 -> V_266 = 1 ;
V_263 -> V_267 . V_343 . V_302 = V_500 ;
if ( V_263 -> V_267 . V_343 . V_296 >= V_500 )
V_263 -> V_267 . V_343 . V_296 = V_500 - 1 ;
sprintf ( V_263 -> V_267 . V_343 . V_133 , L_95 ,
V_499 [ V_263 -> V_267 . V_343 . V_296 ] . V_421 ) ;
return 0 ;
}
int F_269 ( struct V_6 * V_7 ,
struct V_272 * V_273 ,
const struct V_498 * V_499 ,
int V_500 ,
int V_501 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_500 ; V_12 ++ ) {
if ( V_501 == V_499 [ V_12 ] . V_421 ) {
V_273 -> V_267 . V_343 . V_296 [ 0 ] = V_12 ;
break;
}
}
return 0 ;
}
int F_270 ( struct V_6 * V_7 ,
struct V_272 * V_273 ,
const struct V_498 * V_499 ,
int V_500 ,
int * V_502 )
{
unsigned int V_503 ;
V_503 = V_273 -> V_267 . V_343 . V_296 [ 0 ] ;
if ( V_503 >= V_500 )
return - V_56 ;
if ( * V_502 == V_499 [ V_503 ] . V_421 )
return 0 ;
* V_502 = V_499 [ V_503 ] . V_421 ;
if ( V_499 [ V_503 ] . V_504 )
F_224 ( V_7 , V_499 [ V_503 ] . V_504 ) ;
return 1 ;
}
int F_271 ( const struct V_505 * V_506 ,
struct V_262 * V_263 )
{
unsigned int V_237 ;
V_263 -> type = V_342 ;
V_263 -> V_266 = 1 ;
V_263 -> V_267 . V_343 . V_302 = V_506 -> V_507 ;
if ( ! V_506 -> V_507 )
return 0 ;
V_237 = V_263 -> V_267 . V_343 . V_296 ;
if ( V_237 >= V_506 -> V_507 )
V_237 = V_506 -> V_507 - 1 ;
strcpy ( V_263 -> V_267 . V_343 . V_133 , V_506 -> V_302 [ V_237 ] . V_508 ) ;
return 0 ;
}
int F_272 ( struct V_6 * V_7 ,
const struct V_505 * V_506 ,
struct V_272 * V_273 ,
T_2 V_19 ,
unsigned int * V_509 )
{
unsigned int V_221 ;
if ( ! V_506 -> V_507 )
return 0 ;
V_221 = V_273 -> V_267 . V_343 . V_296 [ 0 ] ;
if ( V_221 >= V_506 -> V_507 )
V_221 = V_506 -> V_507 - 1 ;
if ( * V_509 == V_221 )
return 0 ;
F_202 ( V_7 , V_19 , 0 , V_510 ,
V_506 -> V_302 [ V_221 ] . V_237 ) ;
* V_509 = V_221 ;
return 1 ;
}
static void F_273 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_200 , unsigned int V_202 )
{
struct V_187 * V_371 = F_209 ( V_7 , V_19 ) ;
if ( V_7 -> V_322 && ( V_371 -> V_385 & V_386 ) )
F_203 ( V_7 , V_19 ,
V_371 -> V_385 & ~ V_386 & 0xff ,
- 1 ) ;
F_102 ( V_7 , V_19 , V_200 , 0 , V_202 ) ;
if ( V_7 -> V_321 ) {
const T_2 * V_380 ;
for ( V_380 = V_7 -> V_321 ; * V_380 ; V_380 ++ )
F_102 ( V_7 , * V_380 , V_200 , 0 ,
V_202 ) ;
}
if ( V_7 -> V_322 && ( V_371 -> V_385 & V_386 ) )
F_203 ( V_7 , V_19 ,
V_371 -> V_385 & 0xff , - 1 ) ;
}
static void F_274 ( struct V_6 * V_7 , T_2 V_19 )
{
F_249 ( V_7 , V_19 ) ;
if ( V_7 -> V_321 ) {
const T_2 * V_380 ;
for ( V_380 = V_7 -> V_321 ; * V_380 ; V_380 ++ )
F_249 ( V_7 , * V_380 ) ;
}
}
void F_275 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
if ( ! V_29 )
return;
F_55 (codec, &bus->codec_list, list) {
if ( F_276 ( V_7 ) &&
V_7 -> V_96 . V_511 )
V_7 -> V_96 . V_511 ( V_7 ) ;
}
}
int F_277 ( struct V_6 * V_7 ,
struct V_394 * V_395 )
{
F_2 ( & V_7 -> V_182 ) ;
if ( V_395 -> V_512 == V_513 )
F_274 ( V_7 , V_395 -> V_397 ) ;
V_395 -> V_512 = V_514 ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_278 ( struct V_6 * V_7 ,
struct V_394 * V_395 ,
unsigned int V_200 ,
unsigned int V_202 ,
struct V_460 * V_461 )
{
F_2 ( & V_7 -> V_182 ) ;
F_273 ( V_7 , V_395 -> V_397 , V_200 , V_202 ) ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_279 ( struct V_6 * V_7 ,
struct V_394 * V_395 )
{
F_2 ( & V_7 -> V_182 ) ;
F_274 ( V_7 , V_395 -> V_397 ) ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_280 ( struct V_6 * V_7 ,
struct V_394 * V_395 )
{
F_2 ( & V_7 -> V_182 ) ;
V_395 -> V_512 = 0 ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_281 ( struct V_6 * V_7 ,
struct V_394 * V_395 ,
struct V_460 * V_461 ,
struct V_458 * V_459 )
{
struct V_515 * V_516 = V_461 -> V_516 ;
V_516 -> V_517 . V_518 = V_395 -> V_501 ;
if ( V_395 -> V_397 ) {
if ( ! V_395 -> V_519 ) {
V_395 -> V_519 = V_459 -> V_440 ;
V_395 -> V_520 = V_459 -> V_443 ;
V_395 -> V_521 = V_459 -> V_422 ;
} else {
V_516 -> V_517 . V_440 = V_395 -> V_519 ;
V_516 -> V_517 . V_443 = V_395 -> V_520 ;
V_459 -> V_422 = V_395 -> V_521 ;
}
if ( ! V_395 -> V_522 ) {
F_244 ( V_7 , V_395 -> V_397 ,
& V_395 -> V_522 ,
& V_395 -> V_523 ,
& V_395 -> V_524 ) ;
}
F_2 ( & V_7 -> V_182 ) ;
if ( V_395 -> V_396 ) {
if ( ( V_516 -> V_517 . V_440 & V_395 -> V_522 ) &&
( V_516 -> V_517 . V_443 & V_395 -> V_523 ) ) {
V_516 -> V_517 . V_440 &= V_395 -> V_522 ;
V_516 -> V_517 . V_443 &= V_395 -> V_523 ;
if ( V_395 -> V_524 < V_459 -> V_422 )
V_459 -> V_422 = V_395 -> V_524 ;
} else {
V_395 -> V_396 = 0 ;
}
}
F_4 ( & V_7 -> V_182 ) ;
}
return F_282 ( V_461 -> V_516 , 0 ,
V_525 , 2 ) ;
}
int F_283 ( struct V_6 * V_7 ,
struct V_394 * V_395 ,
unsigned int V_200 ,
unsigned int V_202 ,
struct V_460 * V_461 )
{
const T_2 * V_173 = V_395 -> V_526 ;
int V_264 = V_461 -> V_516 -> V_421 ;
struct V_187 * V_371 ;
int V_12 ;
F_2 ( & V_7 -> V_182 ) ;
V_371 = F_209 ( V_7 , V_395 -> V_397 ) ;
if ( V_395 -> V_397 && V_395 -> V_396 &&
V_395 -> V_512 != V_514 ) {
if ( V_264 == 2 &&
F_245 ( V_7 , V_395 -> V_397 ,
V_202 ) &&
! ( V_371 -> V_363 & V_365 ) ) {
V_395 -> V_512 = V_513 ;
F_273 ( V_7 , V_395 -> V_397 ,
V_200 , V_202 ) ;
} else {
V_395 -> V_512 = 0 ;
F_274 ( V_7 , V_395 -> V_397 ) ;
}
}
F_4 ( & V_7 -> V_182 ) ;
F_102 ( V_7 , V_173 [ V_527 ] , V_200 ,
0 , V_202 ) ;
if ( ! V_395 -> V_528 &&
V_395 -> V_529 && V_395 -> V_529 != V_173 [ V_527 ] )
F_102 ( V_7 , V_395 -> V_529 , V_200 ,
0 , V_202 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_395 -> V_530 ) ; V_12 ++ )
if ( ! V_395 -> V_528 && V_395 -> V_530 [ V_12 ] )
F_102 ( V_7 ,
V_395 -> V_530 [ V_12 ] ,
V_200 , 0 , V_202 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_395 -> V_531 ) ; V_12 ++ )
if ( ! V_395 -> V_528 && V_395 -> V_531 [ V_12 ] )
F_102 ( V_7 ,
V_395 -> V_531 [ V_12 ] ,
V_200 , 0 , V_202 ) ;
for ( V_12 = 1 ; V_12 < V_395 -> V_532 ; V_12 ++ ) {
if ( V_264 >= ( V_12 + 1 ) * 2 )
F_102 ( V_7 , V_173 [ V_12 ] , V_200 ,
V_12 * 2 , V_202 ) ;
else if ( ! V_395 -> V_528 )
F_102 ( V_7 , V_173 [ V_12 ] , V_200 ,
0 , V_202 ) ;
}
return 0 ;
}
int F_284 ( struct V_6 * V_7 ,
struct V_394 * V_395 )
{
const T_2 * V_173 = V_395 -> V_526 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_395 -> V_532 ; V_12 ++ )
F_249 ( V_7 , V_173 [ V_12 ] ) ;
if ( V_395 -> V_529 )
F_249 ( V_7 , V_395 -> V_529 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_395 -> V_530 ) ; V_12 ++ )
if ( V_395 -> V_530 [ V_12 ] )
F_249 ( V_7 ,
V_395 -> V_530 [ V_12 ] ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_395 -> V_531 ) ; V_12 ++ )
if ( V_395 -> V_531 [ V_12 ] )
F_249 ( V_7 ,
V_395 -> V_531 [ V_12 ] ) ;
F_2 ( & V_7 -> V_182 ) ;
if ( V_395 -> V_397 && V_395 -> V_512 == V_513 ) {
F_274 ( V_7 , V_395 -> V_397 ) ;
V_395 -> V_512 = 0 ;
}
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
unsigned int F_285 ( struct V_6 * V_7 , T_2 V_157 )
{
unsigned int V_533 ;
unsigned int V_203 ;
V_203 = F_21 ( V_7 , V_157 , 0 ,
V_162 , 0 ) ;
V_533 = F_119 ( V_7 , V_157 ) ;
V_533 = ( V_533 & V_534 ) >> V_535 ;
if ( ( V_533 & V_536 ) && V_203 != V_537 )
return V_538 ;
else if ( V_533 & V_539 )
return V_540 ;
else if ( V_533 & V_541 )
return V_542 ;
else if ( V_533 & V_543 )
return V_544 ;
return V_545 ;
}
int F_286 ( struct V_6 * V_7 , T_2 V_157 ,
unsigned int V_23 , bool V_546 )
{
if ( V_23 ) {
unsigned int V_547 = F_119 ( V_7 , V_157 ) ;
if ( V_547 && ( V_23 & V_548 ) ) {
if ( ! ( V_547 & V_549 ) )
V_23 &= ~ ( V_548 | V_550 ) ;
else if ( ( V_23 & V_550 ) &&
! ( V_547 & V_551 ) )
V_23 &= ~ V_550 ;
}
if ( V_547 && ( V_23 & V_552 ) ) {
if ( ! ( V_547 & V_553 ) )
V_23 &= ~ ( V_552 | V_554 ) ;
}
}
if ( V_546 )
return F_220 ( V_7 , V_157 , 0 ,
V_167 , V_23 ) ;
else
return F_22 ( V_7 , V_157 , 0 ,
V_167 , V_23 ) ;
}
int F_287 ( struct V_505 * V_506 , const char * V_508 ,
int V_237 , int * V_555 )
{
int V_12 , V_556 = 0 ;
if ( V_506 -> V_507 >= V_80 ) {
F_19 ( V_25 L_96 ) ;
return - V_56 ;
}
for ( V_12 = 0 ; V_12 < V_506 -> V_507 ; V_12 ++ ) {
if ( ! strncmp ( V_508 , V_506 -> V_302 [ V_12 ] . V_508 , strlen ( V_508 ) ) )
V_556 ++ ;
}
if ( V_555 )
* V_555 = V_556 ;
if ( V_556 > 0 )
snprintf ( V_506 -> V_302 [ V_506 -> V_507 ] . V_508 ,
sizeof( V_506 -> V_302 [ V_506 -> V_507 ] . V_508 ) ,
L_97 , V_508 , V_556 ) ;
else
F_288 ( V_506 -> V_302 [ V_506 -> V_507 ] . V_508 , V_508 ,
sizeof( V_506 -> V_302 [ V_506 -> V_507 ] . V_508 ) ) ;
V_506 -> V_302 [ V_506 -> V_507 ] . V_237 = V_237 ;
V_506 -> V_507 ++ ;
return 0 ;
}
int F_289 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
if ( F_276 ( V_7 ) )
F_229 ( V_7 ) ;
}
return 0 ;
}
int F_290 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
F_232 ( V_7 ) ;
}
return 0 ;
}
void * F_37 ( struct V_45 * V_46 )
{
if ( V_46 -> V_48 >= V_46 -> V_557 ) {
int V_558 = V_46 -> V_557 + V_46 -> V_559 ;
int V_277 = ( V_558 + 1 ) * V_46 -> V_560 ;
int V_561 = V_46 -> V_557 * V_46 -> V_560 ;
void * V_562 ;
if ( F_33 ( V_558 >= 4096 ) )
return NULL ;
V_562 = F_291 ( V_46 -> V_4 , V_277 , V_98 ) ;
if ( ! V_562 )
return NULL ;
memset ( V_562 + V_561 , 0 , V_277 - V_561 ) ;
V_46 -> V_4 = V_562 ;
V_46 -> V_557 = V_558 ;
}
return F_27 ( V_46 , V_46 -> V_48 ++ ) ;
}
void F_84 ( struct V_45 * V_46 )
{
F_49 ( V_46 -> V_4 ) ;
V_46 -> V_48 = 0 ;
V_46 -> V_557 = 0 ;
V_46 -> V_4 = NULL ;
}
void F_292 ( int V_307 , char * V_219 , int V_563 )
{
static unsigned int V_564 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_12 , V_565 ;
for ( V_12 = 0 , V_565 = 0 ; V_12 < F_9 ( V_564 ) ; V_12 ++ )
if ( V_307 & ( V_446 << V_12 ) )
V_565 += snprintf ( V_219 + V_565 , V_563 - V_565 , L_98 , V_564 [ V_12 ] ) ;
V_219 [ V_565 ] = '\0' ;
}
