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
V_7 -> V_196 = F_96 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_197 ) ;
F_97 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_198 ) ;
F_98 ( V_7 ) ;
F_99 ( V_7 ) ;
sprintf ( V_179 , L_57 , V_7 -> V_129 ,
V_7 -> V_192 , V_7 -> V_131 ) ;
F_100 ( V_7 -> V_29 -> V_105 , V_179 ) ;
if ( V_178 )
* V_178 = V_7 ;
return 0 ;
error:
F_51 ( V_7 ) ;
return V_30 ;
}
int F_101 ( struct V_6 * V_7 )
{
int V_30 ;
V_7 -> V_2 = F_63 ( V_7 ) ;
if ( ! V_7 -> V_138 || ! V_7 -> V_141 ) {
V_30 = F_68 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( F_64 ( V_7 ) ) {
V_30 = F_102 ( V_7 ) ;
goto V_199;
}
if ( V_7 -> V_2 && V_7 -> V_2 -> V_200 ) {
V_30 = V_7 -> V_2 -> V_200 ( V_7 ) ;
goto V_199;
}
V_30 = F_102 ( V_7 ) ;
if ( V_30 < 0 )
F_13 ( V_25 L_58 ) ;
V_199:
if ( ! V_30 && V_7 -> V_96 . V_97 )
V_30 = F_44 ( V_7 -> V_29 ) ;
if ( ! V_30 && ( V_7 -> V_127 || ! * V_7 -> V_29 -> V_105 -> V_201 ) )
snprintf ( V_7 -> V_29 -> V_105 -> V_201 ,
sizeof( V_7 -> V_29 -> V_105 -> V_201 ) ,
L_59 , V_7 -> V_138 , V_7 -> V_141 ) ;
return V_30 ;
}
static void F_103 ( struct V_6 * V_7 ,
struct V_169 * V_49 , T_2 V_19 ,
T_1 V_202 , int V_203 )
{
unsigned int V_204 , V_205 ;
if ( V_49 -> V_202 != V_202 || V_49 -> V_203 != V_203 ) {
V_204 = F_21 ( V_7 , V_19 , 0 , V_206 , 0 ) ;
V_205 = ( V_202 << 4 ) | V_203 ;
if ( V_204 != V_205 )
F_22 ( V_7 , V_19 , 0 ,
V_207 ,
V_205 ) ;
V_49 -> V_202 = V_202 ;
V_49 -> V_203 = V_203 ;
}
}
static void F_104 ( struct V_6 * V_7 , struct V_169 * V_49 ,
T_2 V_19 , int V_208 )
{
unsigned int V_204 ;
if ( V_49 -> V_209 != V_208 ) {
V_204 = F_21 ( V_7 , V_19 , 0 ,
V_210 , 0 ) ;
if ( V_204 != V_208 ) {
F_105 ( 1 ) ;
F_22 ( V_7 , V_19 , 0 ,
V_211 ,
V_208 ) ;
}
V_49 -> V_209 = V_208 ;
}
}
void F_106 ( struct V_6 * V_7 , T_2 V_19 ,
T_1 V_202 ,
int V_203 , int V_208 )
{
struct V_6 * V_135 ;
struct V_169 * V_49 ;
int type ;
int V_12 ;
if ( ! V_19 )
return;
F_95 ( L_60
L_61 ,
V_19 , V_202 , V_203 , V_208 ) ;
V_49 = F_85 ( V_7 , V_19 ) ;
if ( ! V_49 )
return;
if ( V_7 -> V_212 )
F_104 ( V_7 , V_49 , V_19 , V_208 ) ;
F_103 ( V_7 , V_49 , V_19 , V_202 , V_203 ) ;
if ( ! V_7 -> V_212 )
F_104 ( V_7 , V_49 , V_19 , V_208 ) ;
V_49 -> V_213 = 1 ;
V_49 -> V_214 = 0 ;
type = F_35 ( F_34 ( V_7 , V_19 ) ) ;
F_55 (c, &codec->bus->codec_list, list) {
for ( V_12 = 0 ; V_12 < V_135 -> V_170 . V_48 ; V_12 ++ ) {
V_49 = F_27 ( & V_135 -> V_170 , V_12 ) ;
if ( ! V_49 -> V_213 && V_49 -> V_202 == V_202 &&
F_35 ( F_34 ( V_135 , V_49 -> V_19 ) ) == type )
V_49 -> V_214 = 1 ;
}
}
}
void F_107 ( struct V_6 * V_7 , T_2 V_19 ,
int V_215 )
{
struct V_169 * V_49 ;
if ( ! V_19 )
return;
if ( V_7 -> V_216 )
V_215 = 1 ;
F_95 ( L_62 , V_19 ) ;
V_49 = F_85 ( V_7 , V_19 ) ;
if ( V_49 ) {
if ( V_215 )
F_108 ( V_7 , V_49 ) ;
else
V_49 -> V_213 = 0 ;
}
}
static void F_108 ( struct V_6 * V_7 ,
struct V_169 * V_217 )
{
T_2 V_19 = V_217 -> V_19 ;
if ( V_217 -> V_202 || V_217 -> V_203 )
F_22 ( V_7 , V_19 , 0 , V_207 , 0 ) ;
if ( V_217 -> V_209 )
F_22 ( V_7 , V_19 , 0 , V_211 , 0
) ;
memset ( V_217 , 0 , sizeof( * V_217 ) ) ;
V_217 -> V_19 = V_19 ;
}
static void F_109 ( struct V_6 * V_7 )
{
struct V_6 * V_135 ;
int V_12 ;
F_55 (c, &codec->bus->codec_list, list) {
for ( V_12 = 0 ; V_12 < V_135 -> V_170 . V_48 ; V_12 ++ ) {
struct V_169 * V_49 ;
V_49 = F_27 ( & V_135 -> V_170 , V_12 ) ;
if ( V_49 -> V_214 )
F_108 ( V_135 , V_49 ) ;
}
}
}
static void F_110 ( struct V_6 * V_7 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_170 . V_48 ; V_12 ++ ) {
struct V_169 * V_49 = F_27 ( & V_7 -> V_170 , V_12 ) ;
if ( V_49 -> V_202 )
F_108 ( V_7 , V_49 ) ;
}
}
static void F_91 ( struct V_218 * V_219 ,
unsigned int V_220 )
{
memset ( V_219 , 0 , sizeof( * V_219 ) ) ;
memset ( V_219 -> V_221 , 0xff , sizeof( V_219 -> V_221 ) ) ;
F_92 ( & V_219 -> V_222 , V_220 , 64 ) ;
}
static void F_89 ( struct V_218 * V_219 )
{
F_84 ( & V_219 -> V_222 ) ;
}
static struct V_185 * F_111 ( struct V_218 * V_219 , T_1 V_223 )
{
T_3 V_224 = V_223 % ( T_3 ) F_9 ( V_219 -> V_221 ) ;
T_3 V_225 = V_219 -> V_221 [ V_224 ] ;
struct V_185 * V_226 ;
while ( V_225 != 0xffff ) {
V_226 = F_27 ( & V_219 -> V_222 , V_225 ) ;
if ( V_226 -> V_223 == V_223 )
return V_226 ;
V_225 = V_226 -> V_227 ;
}
return NULL ;
}
static struct V_185 * F_112 ( struct V_218 * V_219 ,
T_1 V_223 )
{
struct V_185 * V_226 = F_111 ( V_219 , V_223 ) ;
if ( ! V_226 ) {
T_3 V_224 , V_225 ;
V_226 = F_37 ( & V_219 -> V_222 ) ;
if ( ! V_226 )
return NULL ;
V_225 = F_113 ( & V_219 -> V_222 , V_226 ) ;
V_226 -> V_223 = V_223 ;
V_226 -> V_23 = 0 ;
V_224 = V_223 % ( T_3 ) F_9 ( V_219 -> V_221 ) ;
V_226 -> V_227 = V_219 -> V_221 [ V_224 ] ;
V_219 -> V_221 [ V_224 ] = V_225 ;
}
return V_226 ;
}
static inline struct V_184 *
F_114 ( struct V_6 * V_7 , T_1 V_223 )
{
return (struct V_184 * ) F_112 ( & V_7 -> V_175 , V_223 ) ;
}
static int F_115 ( struct V_6 * V_7 , T_1 V_223 , unsigned int V_23 )
{
struct V_184 * V_226 ;
F_2 ( & V_7 -> V_55 ) ;
V_226 = F_114 ( V_7 , V_223 ) ;
if ( ! V_226 ) {
F_4 ( & V_7 -> V_55 ) ;
return - V_56 ;
}
V_226 -> V_228 = V_23 ;
V_226 -> V_229 . V_23 |= V_230 ;
F_4 ( & V_7 -> V_55 ) ;
return 0 ;
}
static unsigned int F_116 ( struct V_6 * V_7 , T_2 V_19 ,
int V_231 )
{
if ( ! ( F_34 ( V_7 , V_19 ) & V_232 ) )
V_19 = V_7 -> V_127 ;
return F_25 ( V_7 , V_19 ,
V_231 == V_233 ?
V_234 : V_235 ) ;
}
T_1 F_117 ( struct V_6 * V_7 , T_2 V_19 , int V_231 )
{
return F_118 ( V_7 , V_19 , V_231 ,
F_119 ( V_19 , V_231 , 0 ) ,
F_116 ) ;
}
int F_120 ( struct V_6 * V_7 , T_2 V_19 , int V_236 ,
unsigned int V_237 )
{
return F_115 ( V_7 , F_119 ( V_19 , V_236 , 0 ) , V_237 ) ;
}
static unsigned int F_121 ( struct V_6 * V_7 , T_2 V_19 ,
int V_236 )
{
return F_25 ( V_7 , V_19 , V_238 ) ;
}
T_1 F_122 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_118 ( V_7 , V_19 , 0 , F_123 ( V_19 ) ,
F_121 ) ;
}
int F_124 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_237 )
{
return F_115 ( V_7 , F_123 ( V_19 ) , V_237 ) ;
}
static struct V_184 *
F_125 ( struct V_6 * V_7 , T_2 V_19 , int V_239 ,
int V_231 , int V_240 )
{
struct V_184 * V_226 ;
unsigned int V_22 , V_23 = 0 ;
bool V_241 = false ;
V_242:
V_226 = F_114 ( V_7 , F_119 ( V_19 , V_231 , V_240 ) ) ;
if ( ! V_226 )
return NULL ;
if ( ! ( V_226 -> V_229 . V_23 & F_126 ( V_239 ) ) ) {
if ( ! V_241 ) {
F_4 ( & V_7 -> V_55 ) ;
V_22 = V_239 ? V_243 : V_244 ;
V_22 |= V_231 == V_233 ?
V_245 : V_246 ;
V_22 |= V_240 ;
V_23 = F_21 ( V_7 , V_19 , 0 ,
V_247 , V_22 ) ;
V_23 &= 0xff ;
V_241 = true ;
F_2 ( & V_7 -> V_55 ) ;
goto V_242;
}
V_226 -> V_248 [ V_239 ] = V_23 ;
V_226 -> V_229 . V_23 |= F_126 ( V_239 ) ;
}
return V_226 ;
}
static void F_127 ( struct V_6 * V_7 , struct V_184 * V_226 ,
T_2 V_19 , int V_239 , int V_231 , int V_240 ,
int V_23 )
{
T_1 V_22 ;
V_22 = V_239 ? V_249 : V_250 ;
V_22 |= V_231 == V_233 ? V_251 : V_252 ;
V_22 |= V_240 << V_253 ;
if ( ( V_23 & V_254 ) && ! ( V_226 -> V_228 & V_255 ) &&
( V_226 -> V_228 & V_256 ) )
;
else
V_22 |= V_23 ;
F_22 ( V_7 , V_19 , 0 , V_257 , V_22 ) ;
}
int F_128 ( struct V_6 * V_7 , T_2 V_19 , int V_239 ,
int V_231 , int V_240 )
{
struct V_184 * V_226 ;
unsigned int V_23 = 0 ;
F_2 ( & V_7 -> V_55 ) ;
V_226 = F_125 ( V_7 , V_19 , V_239 , V_231 , V_240 ) ;
if ( V_226 )
V_23 = V_226 -> V_248 [ V_239 ] ;
F_4 ( & V_7 -> V_55 ) ;
return V_23 ;
}
int F_129 ( struct V_6 * V_7 , T_2 V_19 , int V_239 ,
int V_231 , int V_224 , int V_61 , int V_23 )
{
struct V_184 * V_226 ;
if ( F_33 ( V_61 & ~ 0xff ) )
V_61 &= 0xff ;
V_23 &= V_61 ;
F_2 ( & V_7 -> V_55 ) ;
V_226 = F_125 ( V_7 , V_19 , V_239 , V_231 , V_224 ) ;
if ( ! V_226 ) {
F_4 ( & V_7 -> V_55 ) ;
return 0 ;
}
V_23 |= V_226 -> V_248 [ V_239 ] & ~ V_61 ;
if ( V_226 -> V_248 [ V_239 ] == V_23 ) {
F_4 ( & V_7 -> V_55 ) ;
return 0 ;
}
V_226 -> V_248 [ V_239 ] = V_23 ;
F_4 ( & V_7 -> V_55 ) ;
F_127 ( V_7 , V_226 , V_19 , V_239 , V_231 , V_224 , V_23 ) ;
return 1 ;
}
int F_130 ( struct V_6 * V_7 , T_2 V_19 ,
int V_231 , int V_224 , int V_61 , int V_23 )
{
int V_239 , V_258 = 0 ;
if ( F_33 ( V_61 & ~ 0xff ) )
V_61 &= 0xff ;
for ( V_239 = 0 ; V_239 < 2 ; V_239 ++ )
V_258 |= F_129 ( V_7 , V_19 , V_239 , V_231 ,
V_224 , V_61 , V_23 ) ;
return V_258 ;
}
void F_131 ( struct V_6 * V_7 )
{
struct V_184 * V_259 = V_7 -> V_175 . V_222 . V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_175 . V_222 . V_48 ; V_12 ++ , V_259 ++ ) {
T_1 V_223 = V_259 -> V_229 . V_223 ;
T_2 V_19 ;
unsigned int V_224 , V_236 , V_239 ;
if ( ! V_223 )
continue;
V_19 = V_223 & 0xff ;
V_224 = ( V_223 >> 16 ) & 0xff ;
V_236 = ( V_223 >> 24 ) & 0xff ;
for ( V_239 = 0 ; V_239 < 2 ; V_239 ++ ) {
if ( ! ( V_259 -> V_229 . V_23 & F_126 ( V_239 ) ) )
continue;
F_127 ( V_7 , V_259 , V_19 , V_239 , V_236 , V_224 ,
V_259 -> V_248 [ V_239 ] ) ;
}
}
}
static T_1 F_132 ( struct V_6 * V_7 , T_2 V_19 , int V_236 ,
unsigned int V_260 )
{
T_1 V_237 = F_117 ( V_7 , V_19 , V_236 ) ;
V_237 = ( V_237 & V_261 ) >> V_262 ;
if ( V_260 < V_237 )
V_237 -= V_260 ;
return V_237 ;
}
int F_133 ( struct V_263 * V_264 ,
struct V_265 * V_266 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
T_3 V_19 = F_135 ( V_264 ) ;
T_4 V_267 = F_136 ( V_264 ) ;
int V_236 = F_137 ( V_264 ) ;
unsigned int V_260 = F_138 ( V_264 ) ;
V_266 -> type = V_268 ;
V_266 -> V_269 = V_267 == 3 ? 2 : 1 ;
V_266 -> V_270 . integer . V_271 = 0 ;
V_266 -> V_270 . integer . V_272 = F_132 ( V_7 , V_19 , V_236 , V_260 ) ;
if ( ! V_266 -> V_270 . integer . V_272 ) {
F_13 ( V_73 L_39
L_63 , V_19 ,
V_264 -> V_126 . V_133 ) ;
return - V_56 ;
}
return 0 ;
}
static inline unsigned int
F_139 ( struct V_6 * V_7 , T_2 V_19 ,
int V_239 , int V_236 , int V_224 , unsigned int V_260 )
{
unsigned int V_23 ;
V_23 = F_128 ( V_7 , V_19 , V_239 , V_236 , V_224 ) ;
V_23 &= V_273 ;
if ( V_23 >= V_260 )
V_23 -= V_260 ;
else
V_23 = 0 ;
return V_23 ;
}
static inline int
F_140 ( struct V_6 * V_7 , T_2 V_19 ,
int V_239 , int V_236 , int V_224 , unsigned int V_260 ,
unsigned int V_23 )
{
unsigned int V_274 ;
if ( V_23 > 0 )
V_23 += V_260 ;
V_274 = F_132 ( V_7 , V_19 , V_236 , 0 ) ;
if ( V_23 > V_274 )
V_23 = V_274 ;
return F_129 ( V_7 , V_19 , V_239 , V_236 , V_224 ,
V_273 , V_23 ) ;
}
int F_141 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
T_2 V_19 = F_135 ( V_264 ) ;
int V_267 = F_136 ( V_264 ) ;
int V_236 = F_137 ( V_264 ) ;
int V_224 = F_142 ( V_264 ) ;
unsigned int V_260 = F_138 ( V_264 ) ;
long * V_277 = V_276 -> V_270 . integer . V_270 ;
if ( V_267 & 1 )
* V_277 ++ = F_139 ( V_7 , V_19 , 0 , V_236 , V_224 , V_260 ) ;
if ( V_267 & 2 )
* V_277 = F_139 ( V_7 , V_19 , 1 , V_236 , V_224 , V_260 ) ;
return 0 ;
}
int F_143 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
T_2 V_19 = F_135 ( V_264 ) ;
int V_267 = F_136 ( V_264 ) ;
int V_236 = F_137 ( V_264 ) ;
int V_224 = F_142 ( V_264 ) ;
unsigned int V_260 = F_138 ( V_264 ) ;
long * V_277 = V_276 -> V_270 . integer . V_270 ;
int V_278 = 0 ;
F_15 ( V_7 ) ;
if ( V_267 & 1 ) {
V_278 = F_140 ( V_7 , V_19 , 0 , V_236 , V_224 , V_260 , * V_277 ) ;
V_277 ++ ;
}
if ( V_267 & 2 )
V_278 |= F_140 ( V_7 , V_19 , 1 , V_236 , V_224 , V_260 , * V_277 ) ;
F_18 ( V_7 ) ;
return V_278 ;
}
int F_144 ( struct V_263 * V_264 , int V_279 ,
unsigned int V_280 , unsigned int T_5 * V_281 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
T_2 V_19 = F_135 ( V_264 ) ;
int V_236 = F_137 ( V_264 ) ;
unsigned int V_260 = F_138 ( V_264 ) ;
bool V_282 = F_145 ( V_264 ) ;
T_1 V_237 , V_283 , V_284 ;
if ( V_280 < 4 * sizeof( unsigned int ) )
return - V_76 ;
V_237 = F_117 ( V_7 , V_19 , V_236 ) ;
V_284 = ( V_237 & V_285 ) >> V_286 ;
V_284 = ( V_284 + 1 ) * 25 ;
V_283 = - ( ( V_237 & V_287 ) >> V_288 ) ;
V_283 += V_260 ;
V_283 = ( ( int ) V_283 ) * ( ( int ) V_284 ) ;
if ( V_282 || ( V_237 & V_256 ) )
V_284 |= V_289 ;
if ( F_146 ( V_290 , V_281 ) )
return - V_291 ;
if ( F_146 ( 2 * sizeof( unsigned int ) , V_281 + 1 ) )
return - V_291 ;
if ( F_146 ( V_283 , V_281 + 2 ) )
return - V_291 ;
if ( F_146 ( V_284 , V_281 + 3 ) )
return - V_291 ;
return 0 ;
}
void F_147 ( struct V_6 * V_7 , T_2 V_19 , int V_236 ,
unsigned int * V_292 )
{
T_1 V_237 ;
int V_81 , V_293 ;
V_237 = F_117 ( V_7 , V_19 , V_236 ) ;
V_81 = ( V_237 & V_261 ) >> V_262 ;
V_293 = ( V_237 & V_285 ) >> V_286 ;
V_293 = ( V_293 + 1 ) * 25 ;
V_292 [ 0 ] = V_290 ;
V_292 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_292 [ 2 ] = - V_81 * V_293 ;
V_292 [ 3 ] = V_293 ;
}
static struct V_263 *
F_148 ( struct V_6 * V_7 ,
const char * V_133 , int V_224 )
{
struct V_294 V_126 ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_295 = V_296 ;
V_126 . V_240 = V_224 ;
if ( F_33 ( strlen ( V_133 ) >= sizeof( V_126 . V_133 ) ) )
return NULL ;
strcpy ( V_126 . V_133 , V_133 ) ;
return F_149 ( V_7 -> V_29 -> V_105 , & V_126 ) ;
}
struct V_263 * F_150 ( struct V_6 * V_7 ,
const char * V_133 )
{
return F_148 ( V_7 , V_133 , 0 ) ;
}
static int F_151 ( struct V_6 * V_7 , const char * V_133 )
{
int V_224 ;
for ( V_224 = 0 ; V_224 < 16 ; V_224 ++ ) {
if ( ! F_148 ( V_7 , V_133 , V_224 ) )
return V_224 ;
}
return - V_181 ;
}
int F_152 ( struct V_6 * V_7 , T_2 V_19 ,
struct V_263 * V_297 )
{
int V_30 ;
unsigned short V_298 = 0 ;
struct V_186 * V_299 ;
if ( V_297 -> V_126 . V_300 & V_301 ) {
V_298 |= V_302 ;
if ( V_19 == 0 )
V_19 = F_153 ( V_297 -> V_303 ) ;
}
if ( ( V_297 -> V_126 . V_300 & V_304 ) != 0 && V_19 == 0 )
V_19 = V_297 -> V_126 . V_300 & 0xffff ;
if ( V_297 -> V_126 . V_300 & ( V_304 | V_301 ) )
V_297 -> V_126 . V_300 = 0 ;
V_30 = F_154 ( V_7 -> V_29 -> V_105 , V_297 ) ;
if ( V_30 < 0 )
return V_30 ;
V_299 = F_37 ( & V_7 -> V_172 ) ;
if ( ! V_299 )
return - V_76 ;
V_299 -> V_297 = V_297 ;
V_299 -> V_19 = V_19 ;
V_299 -> V_298 = V_298 ;
return 0 ;
}
int F_155 ( struct V_6 * V_7 , struct V_263 * V_297 ,
unsigned int V_240 , T_2 V_19 )
{
struct V_186 * V_299 ;
if ( V_19 > 0 ) {
V_299 = F_37 ( & V_7 -> V_173 ) ;
if ( ! V_299 )
return - V_76 ;
V_299 -> V_297 = V_297 ;
V_299 -> V_240 = V_240 ;
V_299 -> V_19 = V_19 ;
return 0 ;
}
F_13 ( V_25 L_64 ,
V_297 -> V_126 . V_133 , V_297 -> V_126 . V_240 , V_240 ) ;
return - V_56 ;
}
void F_156 ( struct V_6 * V_7 )
{
int V_12 ;
struct V_186 * V_305 = V_7 -> V_172 . V_4 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_172 . V_48 ; V_12 ++ )
F_157 ( V_7 -> V_29 -> V_105 , V_305 [ V_12 ] . V_297 ) ;
F_84 ( & V_7 -> V_172 ) ;
F_84 ( & V_7 -> V_173 ) ;
}
int F_158 ( struct V_28 * V_29 )
{
struct V_104 * V_105 = V_29 -> V_105 ;
struct V_6 * V_7 ;
F_159 ( & V_105 -> V_306 ) ;
if ( V_105 -> V_103 )
goto V_307;
V_105 -> V_103 = 1 ;
if ( ! F_160 ( & V_105 -> V_308 ) )
goto V_309;
F_55 (codec, &bus->codec_list, list) {
int V_310 ;
for ( V_310 = 0 ; V_310 < V_7 -> V_311 ; V_310 ++ ) {
struct V_312 * V_313 = & V_7 -> V_314 [ V_310 ] ;
if ( ! V_313 -> V_310 )
continue;
if ( V_313 -> V_310 -> V_315 [ 0 ] . V_316 ||
V_313 -> V_310 -> V_315 [ 1 ] . V_316 )
goto V_309;
}
}
F_161 ( & V_105 -> V_306 ) ;
return 0 ;
V_309:
V_105 -> V_103 = 0 ;
V_307:
F_161 ( & V_105 -> V_306 ) ;
return - V_56 ;
}
void F_162 ( struct V_28 * V_29 )
{
struct V_104 * V_105 = V_29 -> V_105 ;
V_105 = V_29 -> V_105 ;
F_159 ( & V_105 -> V_306 ) ;
V_105 -> V_103 = 0 ;
F_161 ( & V_105 -> V_306 ) ;
}
int F_163 ( struct V_6 * V_7 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
struct V_104 * V_105 = V_29 -> V_105 ;
int V_12 ;
if ( F_158 ( V_29 ) < 0 )
return - V_181 ;
#ifdef F_87
F_164 ( & V_7 -> V_171 ) ;
V_7 -> V_317 = 0 ;
V_7 -> V_318 = 0 ;
V_7 -> V_319 = V_320 ;
F_48 ( V_29 -> V_90 ) ;
#endif
F_156 ( V_7 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_311 ; V_12 ++ ) {
if ( V_7 -> V_314 [ V_12 ] . V_310 ) {
F_165 ( V_105 , V_7 -> V_314 [ V_12 ] . V_310 ) ;
F_166 ( V_7 -> V_314 [ V_12 ] . V_101 ,
V_29 -> V_321 ) ;
}
}
if ( V_7 -> V_96 . free )
V_7 -> V_96 . free ( V_7 ) ;
memset ( & V_7 -> V_96 , 0 , sizeof( V_7 -> V_96 ) ) ;
F_86 ( V_7 ) ;
V_7 -> V_322 = NULL ;
V_7 -> V_323 = NULL ;
F_89 ( & V_7 -> V_175 ) ;
F_89 ( & V_7 -> V_176 ) ;
F_91 ( & V_7 -> V_175 , sizeof( struct V_184 ) ) ;
F_91 ( & V_7 -> V_176 , sizeof( struct V_185 ) ) ;
F_84 ( & V_7 -> V_165 ) ;
F_80 ( V_7 ) ;
F_84 ( & V_7 -> V_170 ) ;
F_84 ( & V_7 -> V_174 ) ;
V_7 -> V_311 = 0 ;
V_7 -> V_314 = NULL ;
V_7 -> V_2 = NULL ;
V_7 -> V_324 = NULL ;
V_7 -> V_325 = 0 ;
F_66 ( V_7 -> V_125 ) ;
V_7 -> V_125 = NULL ;
F_162 ( V_29 ) ;
return 0 ;
}
static int F_167 ( struct V_6 * V_7 , const char * const * V_326 ,
const char * V_327 , T_6 V_328 , void * V_329 )
{
struct V_186 * V_305 ;
const char * const * V_330 ;
int V_12 , V_30 ;
V_305 = V_7 -> V_172 . V_4 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_172 . V_48 ; V_12 ++ ) {
struct V_263 * V_331 = V_305 [ V_12 ] . V_297 ;
if ( ! V_331 || ! V_331 -> V_126 . V_133 ||
V_331 -> V_126 . V_295 != V_296 )
continue;
for ( V_330 = V_326 ; * V_330 ; V_330 ++ ) {
char V_332 [ sizeof( V_331 -> V_126 . V_133 ) ] ;
const char * V_133 = * V_330 ;
if ( V_327 ) {
snprintf ( V_332 , sizeof( V_332 ) , L_59 ,
V_133 , V_327 ) ;
V_133 = V_332 ;
}
if ( ! strcmp ( V_331 -> V_126 . V_133 , V_133 ) ) {
V_30 = V_328 ( V_329 , V_331 ) ;
if ( V_30 )
return V_30 ;
break;
}
}
}
return 0 ;
}
static int F_168 ( void * V_329 , struct V_263 * V_331 )
{
return 1 ;
}
static int F_169 ( struct V_263 * V_297 )
{
int V_281 [ 4 ] ;
const int * V_292 = NULL ;
int V_23 = - 1 ;
if ( V_297 -> V_333 [ 0 ] . V_334 & V_335 ) {
T_7 V_336 = F_170 () ;
F_171 ( F_172 () ) ;
if ( ! V_297 -> V_292 . V_135 ( V_297 , 0 , sizeof( V_281 ) , V_281 ) )
V_292 = V_281 ;
F_171 ( V_336 ) ;
} else if ( V_297 -> V_333 [ 0 ] . V_334 & V_337 )
V_292 = V_297 -> V_292 . V_49 ;
if ( V_292 && V_292 [ 0 ] == V_290 )
V_23 = - V_292 [ 2 ] / V_292 [ 3 ] ;
return V_23 ;
}
static int F_173 ( struct V_263 * V_297 , int V_23 )
{
struct V_275 * V_276 ;
V_276 = F_45 ( sizeof( * V_276 ) , V_98 ) ;
if ( ! V_276 )
return - V_76 ;
V_276 -> V_270 . integer . V_270 [ 0 ] = V_23 ;
V_276 -> V_270 . integer . V_270 [ 1 ] = V_23 ;
V_297 -> V_338 ( V_297 , V_276 ) ;
F_49 ( V_276 ) ;
return 0 ;
}
static int F_174 ( void * V_329 , struct V_263 * V_339 )
{
int V_340 = F_169 ( V_339 ) ;
if ( V_340 > 0 )
F_173 ( V_339 , V_340 ) ;
return 0 ;
}
static int F_175 ( void * V_329 , struct V_263 * V_339 )
{
return F_173 ( V_339 , 1 ) ;
}
int F_176 ( struct V_6 * V_7 , char * V_133 ,
unsigned int * V_292 , const char * const * V_326 ,
const char * V_327 , bool V_341 ,
struct V_263 * * V_342 )
{
struct V_263 * V_297 ;
int V_30 ;
if ( V_342 )
* V_342 = NULL ;
V_30 = F_167 ( V_7 , V_326 , V_327 , F_168 , NULL ) ;
if ( V_30 != 1 ) {
F_95 ( L_65 , V_133 ) ;
return 0 ;
}
V_297 = F_177 ( V_133 , V_292 ) ;
if ( ! V_297 )
return - V_76 ;
V_30 = F_152 ( V_7 , 0 , V_297 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_167 ( V_7 , V_326 , V_327 ,
( T_6 ) V_343 , V_297 ) ;
if ( V_30 < 0 )
return V_30 ;
F_173 ( V_297 , 0 ) ;
if ( V_341 )
F_167 ( V_7 , V_326 , V_327 ,
V_292 ? F_174 : F_175 , V_297 ) ;
if ( V_342 )
* V_342 = V_297 ;
return 0 ;
}
static int F_178 ( struct V_263 * V_264 ,
struct V_265 * V_266 )
{
static const char * const V_344 [] = {
L_66 , L_67 , L_68
} ;
unsigned int V_240 ;
V_266 -> type = V_345 ;
V_266 -> V_269 = 1 ;
V_266 -> V_270 . V_346 . V_305 = 3 ;
V_240 = V_266 -> V_270 . V_346 . V_299 ;
if ( V_240 >= 3 )
V_240 = 2 ;
strcpy ( V_266 -> V_270 . V_346 . V_133 , V_344 [ V_240 ] ) ;
return 0 ;
}
static int F_179 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_347 * V_348 = F_134 ( V_264 ) ;
V_276 -> V_270 . V_346 . V_299 [ 0 ] = V_348 -> V_349 ;
return 0 ;
}
static int F_180 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_347 * V_348 = F_134 ( V_264 ) ;
unsigned int V_350 = V_348 -> V_349 ;
V_348 -> V_349 = V_276 -> V_270 . V_346 . V_299 [ 0 ] ;
if ( V_348 -> V_349 > V_351 )
V_348 -> V_349 = V_351 ;
if ( V_350 == V_348 -> V_349 )
return 0 ;
F_181 ( V_348 ) ;
return 1 ;
}
int F_182 ( struct V_6 * V_7 ,
struct V_347 * V_348 ,
bool V_352 )
{
struct V_263 * V_297 ;
if ( ! V_348 -> V_348 || ! V_348 -> V_353 )
return 0 ;
F_183 ( V_348 -> V_353 , V_348 -> V_348 , V_7 ) ;
V_348 -> V_7 = V_7 ;
V_348 -> V_349 = V_351 ;
if ( ! V_352 )
return 0 ;
V_297 = F_184 ( & V_354 , V_348 ) ;
if ( ! V_297 )
return - V_76 ;
return F_152 ( V_7 , 0 , V_297 ) ;
}
void F_181 ( struct V_347 * V_348 )
{
if ( ! V_348 -> V_348 || ! V_348 -> V_7 )
return;
switch ( V_348 -> V_349 ) {
case V_351 :
F_185 ( V_348 -> V_353 ) ;
break;
default:
V_348 -> V_348 ( V_348 -> V_7 , V_348 -> V_349 ) ;
break;
}
}
int F_186 ( struct V_263 * V_264 ,
struct V_265 * V_266 )
{
int V_267 = F_136 ( V_264 ) ;
V_266 -> type = V_355 ;
V_266 -> V_269 = V_267 == 3 ? 2 : 1 ;
V_266 -> V_270 . integer . V_271 = 0 ;
V_266 -> V_270 . integer . V_272 = 1 ;
return 0 ;
}
int F_187 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
T_2 V_19 = F_135 ( V_264 ) ;
int V_267 = F_136 ( V_264 ) ;
int V_236 = F_137 ( V_264 ) ;
int V_224 = F_142 ( V_264 ) ;
long * V_277 = V_276 -> V_270 . integer . V_270 ;
if ( V_267 & 1 )
* V_277 ++ = ( F_128 ( V_7 , V_19 , 0 , V_236 , V_224 ) &
V_254 ) ? 0 : 1 ;
if ( V_267 & 2 )
* V_277 = ( F_128 ( V_7 , V_19 , 1 , V_236 , V_224 ) &
V_254 ) ? 0 : 1 ;
return 0 ;
}
int F_188 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
T_2 V_19 = F_135 ( V_264 ) ;
int V_267 = F_136 ( V_264 ) ;
int V_236 = F_137 ( V_264 ) ;
int V_224 = F_142 ( V_264 ) ;
long * V_277 = V_276 -> V_270 . integer . V_270 ;
int V_278 = 0 ;
F_15 ( V_7 ) ;
if ( V_267 & 1 ) {
V_278 = F_129 ( V_7 , V_19 , 0 , V_236 , V_224 ,
V_254 ,
* V_277 ? 0 : V_254 ) ;
V_277 ++ ;
}
if ( V_267 & 2 )
V_278 |= F_129 ( V_7 , V_19 , 1 , V_236 , V_224 ,
V_254 ,
* V_277 ? 0 : V_254 ) ;
F_189 ( V_7 , V_19 ) ;
F_18 ( V_7 ) ;
return V_278 ;
}
int F_190 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
unsigned long V_356 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_356 = V_264 -> V_303 ;
V_264 -> V_303 = V_356 & ~ V_357 ;
V_30 = F_187 ( V_264 , V_276 ) ;
V_264 -> V_303 = V_356 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_191 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
unsigned long V_356 ;
int V_12 , V_358 , V_30 = 0 , V_278 = 0 ;
F_2 ( & V_7 -> V_183 ) ;
V_356 = V_264 -> V_303 ;
V_358 = ( V_356 & V_357 ) >> V_359 ;
for ( V_12 = 0 ; V_12 < V_358 ; V_12 ++ ) {
V_264 -> V_303 = ( V_356 & ~ V_357 ) |
( V_12 << V_359 ) ;
V_30 = F_188 ( V_264 , V_276 ) ;
if ( V_30 < 0 )
break;
V_278 |= V_30 ;
}
V_264 -> V_303 = V_356 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 < 0 ? V_30 : V_278 ;
}
int F_192 ( struct V_263 * V_264 ,
struct V_265 * V_266 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
struct V_360 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_360 * ) V_264 -> V_303 ;
V_264 -> V_303 = * V_135 -> V_361 ;
V_30 = V_135 -> V_33 -> V_226 ( V_264 , V_266 ) ;
V_264 -> V_303 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_193 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
struct V_360 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_360 * ) V_264 -> V_303 ;
V_264 -> V_303 = * V_135 -> V_361 ;
V_30 = V_135 -> V_33 -> V_362 ( V_264 , V_276 ) ;
V_264 -> V_303 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
int F_194 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
struct V_360 * V_135 ;
unsigned long * V_363 ;
int V_30 = 0 , V_278 = 0 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_360 * ) V_264 -> V_303 ;
for ( V_363 = V_135 -> V_361 ; * V_363 ; V_363 ++ ) {
V_264 -> V_303 = * V_363 ;
V_30 = V_135 -> V_33 -> V_338 ( V_264 , V_276 ) ;
if ( V_30 < 0 )
break;
V_278 |= V_30 ;
}
V_264 -> V_303 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 < 0 ? V_30 : V_278 ;
}
int F_195 ( struct V_263 * V_264 , int V_279 ,
unsigned int V_280 , unsigned int T_5 * V_292 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
struct V_360 * V_135 ;
int V_30 ;
F_2 ( & V_7 -> V_183 ) ;
V_135 = (struct V_360 * ) V_264 -> V_303 ;
V_264 -> V_303 = * V_135 -> V_361 ;
V_30 = V_135 -> V_33 -> V_292 ( V_264 , V_279 , V_280 , V_292 ) ;
V_264 -> V_303 = ( long ) V_135 ;
F_4 ( & V_7 -> V_183 ) ;
return V_30 ;
}
static int F_196 ( struct V_263 * V_264 ,
struct V_265 * V_266 )
{
V_266 -> type = V_364 ;
V_266 -> V_269 = 1 ;
return 0 ;
}
static int F_197 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
V_276 -> V_270 . V_365 . V_366 [ 0 ] = V_367 |
V_368 |
V_369 |
V_370 ;
V_276 -> V_270 . V_365 . V_366 [ 1 ] = V_371 |
V_372 ;
return 0 ;
}
static int F_198 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
V_276 -> V_270 . V_365 . V_366 [ 0 ] = V_367 |
V_368 |
V_373 ;
return 0 ;
}
static int F_199 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
int V_224 = V_264 -> V_303 ;
struct V_187 * V_374 ;
F_2 ( & V_7 -> V_182 ) ;
V_374 = F_27 ( & V_7 -> V_174 , V_224 ) ;
V_276 -> V_270 . V_365 . V_366 [ 0 ] = V_374 -> V_366 & 0xff ;
V_276 -> V_270 . V_365 . V_366 [ 1 ] = ( V_374 -> V_366 >> 8 ) & 0xff ;
V_276 -> V_270 . V_365 . V_366 [ 2 ] = ( V_374 -> V_366 >> 16 ) & 0xff ;
V_276 -> V_270 . V_365 . V_366 [ 3 ] = ( V_374 -> V_366 >> 24 ) & 0xff ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
static unsigned short F_200 ( unsigned int V_375 )
{
unsigned short V_23 = 0 ;
if ( V_375 & V_367 )
V_23 |= V_376 ;
if ( V_375 & V_368 )
V_23 |= V_377 ;
if ( V_375 & V_367 ) {
if ( ( V_375 & V_378 ) ==
V_373 )
V_23 |= V_379 ;
} else {
if ( ( V_375 & V_380 ) ==
V_369 )
V_23 |= V_379 ;
if ( ! ( V_375 & V_370 ) )
V_23 |= V_381 ;
if ( V_375 & ( V_372 << 8 ) )
V_23 |= V_382 ;
V_23 |= V_375 & ( V_371 << 8 ) ;
}
return V_23 ;
}
static unsigned int F_201 ( unsigned short V_23 )
{
unsigned int V_375 = 0 ;
if ( V_23 & V_377 )
V_375 |= V_368 ;
if ( V_23 & V_376 )
V_375 |= V_367 ;
if ( V_375 & V_367 ) {
if ( V_375 & V_379 )
V_375 |= V_373 ;
} else {
if ( V_23 & V_379 )
V_375 |= V_369 ;
if ( ! ( V_23 & V_381 ) )
V_375 |= V_370 ;
if ( V_23 & V_382 )
V_375 |= ( V_372 << 8 ) ;
V_375 |= V_23 & ( 0x7f << 8 ) ;
}
return V_375 ;
}
static void F_202 ( struct V_6 * V_7 , T_2 V_19 ,
int V_21 , int V_23 )
{
const T_2 * V_383 ;
F_203 ( V_7 , V_19 , 0 , V_21 , V_23 ) ;
V_383 = V_7 -> V_324 ;
if ( ! V_383 )
return;
for (; * V_383 ; V_383 ++ )
F_203 ( V_7 , * V_383 , 0 , V_21 , V_23 ) ;
}
static inline void F_204 ( struct V_6 * V_7 , T_2 V_19 ,
int V_384 , int V_385 )
{
if ( V_384 != - 1 )
F_202 ( V_7 , V_19 , V_386 , V_384 ) ;
if ( V_385 != - 1 )
F_202 ( V_7 , V_19 , V_387 , V_385 ) ;
}
static int F_205 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
int V_224 = V_264 -> V_303 ;
struct V_187 * V_374 ;
T_2 V_19 ;
unsigned short V_23 ;
int V_278 ;
F_2 ( & V_7 -> V_182 ) ;
V_374 = F_27 ( & V_7 -> V_174 , V_224 ) ;
V_19 = V_374 -> V_19 ;
V_374 -> V_366 = V_276 -> V_270 . V_365 . V_366 [ 0 ] |
( ( unsigned int ) V_276 -> V_270 . V_365 . V_366 [ 1 ] << 8 ) |
( ( unsigned int ) V_276 -> V_270 . V_365 . V_366 [ 2 ] << 16 ) |
( ( unsigned int ) V_276 -> V_270 . V_365 . V_366 [ 3 ] << 24 ) ;
V_23 = F_200 ( V_374 -> V_366 ) ;
V_23 |= V_374 -> V_388 & 1 ;
V_278 = V_374 -> V_388 != V_23 ;
V_374 -> V_388 = V_23 ;
if ( V_278 && V_19 != ( T_3 ) - 1 )
F_204 ( V_7 , V_19 , V_23 & 0xff , ( V_23 >> 8 ) & 0xff ) ;
F_4 ( & V_7 -> V_182 ) ;
return V_278 ;
}
static int F_206 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
int V_224 = V_264 -> V_303 ;
struct V_187 * V_374 ;
F_2 ( & V_7 -> V_182 ) ;
V_374 = F_27 ( & V_7 -> V_174 , V_224 ) ;
V_276 -> V_270 . integer . V_270 [ 0 ] = V_374 -> V_388 & V_389 ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
static inline void F_207 ( struct V_6 * V_7 , T_2 V_19 ,
int V_384 , int V_385 )
{
F_204 ( V_7 , V_19 , V_384 , V_385 ) ;
if ( ( F_34 ( V_7 , V_19 ) & V_390 ) &&
( V_384 & V_389 ) )
F_130 ( V_7 , V_19 , V_233 , 0 ,
V_254 , 0 ) ;
}
static int F_208 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
int V_224 = V_264 -> V_303 ;
struct V_187 * V_374 ;
T_2 V_19 ;
unsigned short V_23 ;
int V_278 ;
F_2 ( & V_7 -> V_182 ) ;
V_374 = F_27 ( & V_7 -> V_174 , V_224 ) ;
V_19 = V_374 -> V_19 ;
V_23 = V_374 -> V_388 & ~ V_389 ;
if ( V_276 -> V_270 . integer . V_270 [ 0 ] )
V_23 |= V_389 ;
V_278 = V_374 -> V_388 != V_23 ;
V_374 -> V_388 = V_23 ;
if ( V_278 && V_19 != ( T_3 ) - 1 )
F_207 ( V_7 , V_19 , V_23 & 0xff , - 1 ) ;
F_4 ( & V_7 -> V_182 ) ;
return V_278 ;
}
int F_209 ( struct V_6 * V_7 ,
T_2 V_391 ,
T_2 V_392 )
{
int V_30 ;
struct V_263 * V_297 ;
struct V_393 * V_394 ;
int V_224 ;
struct V_187 * V_374 ;
V_224 = F_151 ( V_7 , L_69 ) ;
if ( V_224 < 0 ) {
F_13 ( V_25 L_70 ) ;
return - V_181 ;
}
V_374 = F_37 ( & V_7 -> V_174 ) ;
for ( V_394 = V_395 ; V_394 -> V_133 ; V_394 ++ ) {
V_297 = F_184 ( V_394 , V_7 ) ;
if ( ! V_297 )
return - V_76 ;
V_297 -> V_126 . V_240 = V_224 ;
V_297 -> V_303 = V_7 -> V_174 . V_48 - 1 ;
V_30 = F_152 ( V_7 , V_391 , V_297 ) ;
if ( V_30 < 0 )
return V_30 ;
}
V_374 -> V_19 = V_392 ;
V_374 -> V_388 = F_21 ( V_7 , V_392 , 0 ,
V_396 , 0 ) ;
V_374 -> V_366 = F_201 ( V_374 -> V_388 ) ;
return 0 ;
}
struct V_187 * F_210 ( struct V_6 * V_7 ,
T_2 V_19 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_174 . V_48 ; V_12 ++ ) {
struct V_187 * V_374 =
F_27 ( & V_7 -> V_174 , V_12 ) ;
if ( V_374 -> V_19 == V_19 )
return V_374 ;
}
return NULL ;
}
void F_211 ( struct V_6 * V_7 , int V_224 )
{
struct V_187 * V_374 ;
F_2 ( & V_7 -> V_182 ) ;
V_374 = F_27 ( & V_7 -> V_174 , V_224 ) ;
V_374 -> V_19 = ( T_3 ) - 1 ;
F_4 ( & V_7 -> V_182 ) ;
}
void F_212 ( struct V_6 * V_7 , int V_224 , T_2 V_19 )
{
struct V_187 * V_374 ;
unsigned short V_23 ;
F_2 ( & V_7 -> V_182 ) ;
V_374 = F_27 ( & V_7 -> V_174 , V_224 ) ;
if ( V_374 -> V_19 != V_19 ) {
V_374 -> V_19 = V_19 ;
V_23 = V_374 -> V_388 ;
F_207 ( V_7 , V_19 , V_23 & 0xff , ( V_23 >> 8 ) & 0xff ) ;
}
F_4 ( & V_7 -> V_182 ) ;
}
static int F_213 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_397 * V_398 = F_134 ( V_264 ) ;
V_276 -> V_270 . integer . V_270 [ 0 ] = V_398 -> V_399 ;
return 0 ;
}
static int F_214 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_397 * V_398 = F_134 ( V_264 ) ;
V_398 -> V_399 = ! ! V_276 -> V_270 . integer . V_270 [ 0 ] ;
return 0 ;
}
int F_215 ( struct V_6 * V_7 ,
struct V_397 * V_398 )
{
if ( ! V_398 -> V_400 )
return 0 ;
return F_152 ( V_7 , V_398 -> V_400 ,
F_184 ( & V_401 , V_398 ) ) ;
}
static int F_216 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
V_276 -> V_270 . integer . V_270 [ 0 ] = V_7 -> V_402 ;
return 0 ;
}
static int F_217 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
T_2 V_19 = V_264 -> V_303 ;
unsigned int V_23 = ! ! V_276 -> V_270 . integer . V_270 [ 0 ] ;
int V_278 ;
F_2 ( & V_7 -> V_182 ) ;
V_278 = V_7 -> V_402 != V_23 ;
if ( V_278 ) {
V_7 -> V_402 = V_23 ;
F_203 ( V_7 , V_19 , 0 ,
V_386 , V_23 ) ;
}
F_4 ( & V_7 -> V_182 ) ;
return V_278 ;
}
static int F_218 ( struct V_263 * V_264 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_134 ( V_264 ) ;
T_2 V_19 = V_264 -> V_303 ;
unsigned short V_23 ;
unsigned int V_375 ;
V_23 = F_21 ( V_7 , V_19 , 0 , V_396 , 0 ) ;
V_375 = F_201 ( V_23 ) ;
V_276 -> V_270 . V_365 . V_366 [ 0 ] = V_375 ;
V_276 -> V_270 . V_365 . V_366 [ 1 ] = V_375 >> 8 ;
V_276 -> V_270 . V_365 . V_366 [ 2 ] = V_375 >> 16 ;
V_276 -> V_270 . V_365 . V_366 [ 3 ] = V_375 >> 24 ;
return 0 ;
}
int F_219 ( struct V_6 * V_7 , T_2 V_19 )
{
int V_30 ;
struct V_263 * V_297 ;
struct V_393 * V_394 ;
int V_224 ;
V_224 = F_151 ( V_7 , L_71 ) ;
if ( V_224 < 0 ) {
F_13 ( V_25 L_72 ) ;
return - V_181 ;
}
for ( V_394 = V_403 ; V_394 -> V_133 ; V_394 ++ ) {
V_297 = F_184 ( V_394 , V_7 ) ;
if ( ! V_297 )
return - V_76 ;
V_297 -> V_303 = V_19 ;
V_30 = F_152 ( V_7 , V_19 , V_297 ) ;
if ( V_30 < 0 )
return V_30 ;
}
V_7 -> V_402 =
F_21 ( V_7 , V_19 , 0 ,
V_396 , 0 ) &
V_389 ;
return 0 ;
}
int F_203 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 , unsigned int V_21 , unsigned int V_22 )
{
int V_30 = F_22 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
struct V_185 * V_135 ;
T_1 V_223 ;
if ( V_30 < 0 )
return V_30 ;
V_21 = V_21 | ( V_22 >> 8 ) ;
V_22 &= 0xff ;
V_223 = F_220 ( V_19 , V_21 ) ;
F_2 ( & V_7 -> V_29 -> V_32 ) ;
V_135 = F_112 ( & V_7 -> V_176 , V_223 ) ;
if ( V_135 )
V_135 -> V_23 = V_22 ;
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return 0 ;
}
int F_221 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 , unsigned int V_21 , unsigned int V_22 )
{
struct V_185 * V_135 ;
T_1 V_223 ;
V_21 = V_21 | ( V_22 >> 8 ) ;
V_22 &= 0xff ;
V_223 = F_220 ( V_19 , V_21 ) ;
F_2 ( & V_7 -> V_29 -> V_32 ) ;
V_135 = F_111 ( & V_7 -> V_176 , V_223 ) ;
if ( V_135 && V_135 -> V_23 == V_22 ) {
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return 0 ;
}
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return F_203 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
}
void F_222 ( struct V_6 * V_7 )
{
struct V_185 * V_259 = V_7 -> V_176 . V_222 . V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_176 . V_222 . V_48 ; V_12 ++ , V_259 ++ ) {
T_1 V_223 = V_259 -> V_223 ;
if ( ! V_223 )
continue;
F_22 ( V_7 , F_223 ( V_223 ) , 0 ,
F_224 ( V_223 ) , V_259 -> V_23 ) ;
}
}
void F_225 ( struct V_6 * V_7 ,
const struct V_40 * V_41 )
{
for (; V_41 -> V_19 ; V_41 ++ )
F_203 ( V_7 , V_41 -> V_19 , 0 , V_41 -> V_21 ,
V_41 -> V_42 ) ;
}
void F_226 ( struct V_6 * V_7 , T_2 V_404 ,
unsigned int V_405 ,
bool V_406 )
{
T_2 V_19 = V_7 -> V_154 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_153 ; V_12 ++ , V_19 ++ ) {
unsigned int V_62 = F_34 ( V_7 , V_19 ) ;
if ( ! ( V_62 & V_407 ) )
continue;
if ( V_406 && V_405 == V_408 &&
F_35 ( V_62 ) == V_82 &&
( F_122 ( V_7 , V_19 ) & V_409 ) ) {
int V_410 = F_21 ( V_7 , V_19 , 0 ,
V_411 , 0 ) ;
if ( V_410 & 0x02 )
continue;
}
F_22 ( V_7 , V_19 , 0 , V_412 ,
V_405 ) ;
}
if ( V_405 == V_198 ) {
unsigned long V_413 ;
int V_414 ;
V_413 = V_320 + F_227 ( 500 ) ;
do {
V_414 = F_21 ( V_7 , V_404 , 0 ,
V_415 , 0 ) ;
if ( V_414 == V_405 )
break;
F_105 ( 1 ) ;
} while ( F_228 ( V_413 , V_320 ) );
}
}
static bool F_96 ( struct V_6 * V_7 , T_2 V_404 ,
unsigned int V_405 )
{
int V_416 = F_25 ( V_7 , V_404 , V_417 ) ;
if ( V_416 == - 1 )
return false ;
if ( V_416 & V_405 )
return true ;
else
return false ;
}
static void F_97 ( struct V_6 * V_7 , T_2 V_404 ,
unsigned int V_405 )
{
int V_269 ;
unsigned int V_414 ;
if ( V_7 -> V_96 . V_418 ) {
V_7 -> V_96 . V_418 ( V_7 , V_404 , V_405 ) ;
return;
}
if ( V_405 == V_408 ) {
F_105 ( V_7 -> V_196 ? 10 : 100 ) ;
}
for ( V_269 = 0 ; V_269 < 10 ; V_269 ++ ) {
F_21 ( V_7 , V_404 , 0 , V_412 ,
V_405 ) ;
F_226 ( V_7 , V_404 , V_405 , true ) ;
V_414 = F_21 ( V_7 , V_404 , 0 ,
V_415 , 0 ) ;
if ( ! ( V_414 & V_419 ) )
break;
}
}
static void F_229 ( struct V_6 * V_7 )
{
if ( V_7 -> V_420 . V_4 )
F_23 ( V_7 , V_7 -> V_420 . V_4 ) ;
}
static inline void F_229 ( struct V_6 * V_7 ) {}
static void F_230 ( struct V_6 * V_7 )
{
if ( V_7 -> V_96 . V_421 )
V_7 -> V_96 . V_421 ( V_7 ) ;
F_110 ( V_7 ) ;
F_97 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_408 ) ;
#ifdef F_87
F_88 ( & V_7 -> V_171 ) ;
F_159 ( & V_7 -> V_188 ) ;
F_231 ( V_7 ) ;
F_232 ( V_7 ) ;
V_7 -> V_317 = 0 ;
V_7 -> V_318 = 0 ;
V_7 -> V_319 = V_320 ;
F_161 ( & V_7 -> V_188 ) ;
#endif
}
static void F_233 ( struct V_6 * V_7 )
{
F_7 ( V_7 ) ;
F_97 ( V_7 ,
V_7 -> V_127 ? V_7 -> V_127 : V_7 -> V_128 ,
V_198 ) ;
F_80 ( V_7 ) ;
F_82 ( V_7 ) ;
F_229 ( V_7 ) ;
F_234 ( V_7 ) ;
if ( V_7 -> V_96 . V_422 )
V_7 -> V_96 . V_422 ( V_7 ) ;
else {
if ( V_7 -> V_96 . V_423 )
V_7 -> V_96 . V_423 ( V_7 ) ;
F_131 ( V_7 ) ;
F_222 ( V_7 ) ;
}
F_18 ( V_7 ) ;
}
int F_235 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
int V_30 = F_236 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_73
L_74 , V_7 -> V_24 , V_30 ) ;
V_30 = F_163 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25
L_75 ) ;
return V_30 ;
}
}
}
return 0 ;
}
int F_236 ( struct V_6 * V_7 )
{
int V_30 = 0 ;
F_229 ( V_7 ) ;
if ( V_7 -> V_96 . V_423 )
V_30 = V_7 -> V_96 . V_423 ( V_7 ) ;
if ( ! V_30 && V_7 -> V_96 . V_424 )
V_30 = V_7 -> V_96 . V_424 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
unsigned int F_237 ( unsigned int V_425 ,
unsigned int V_426 ,
unsigned int V_208 ,
unsigned int V_427 ,
unsigned short V_428 )
{
int V_12 ;
unsigned int V_23 = 0 ;
for ( V_12 = 0 ; V_429 [ V_12 ] . V_430 ; V_12 ++ )
if ( V_429 [ V_12 ] . V_430 == V_425 ) {
V_23 = V_429 [ V_12 ] . V_431 ;
break;
}
if ( ! V_429 [ V_12 ] . V_430 ) {
F_95 ( L_76 , V_425 ) ;
return 0 ;
}
if ( V_426 == 0 || V_426 > 8 ) {
F_95 ( L_77 , V_426 ) ;
return 0 ;
}
V_23 |= V_426 - 1 ;
switch ( F_238 ( V_208 ) ) {
case 8 :
V_23 |= V_432 ;
break;
case 16 :
V_23 |= V_433 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_427 >= 32 || V_208 == V_434 )
V_23 |= V_435 ;
else if ( V_427 >= 24 )
V_23 |= V_436 ;
else
V_23 |= V_437 ;
break;
default:
F_95 ( L_78 ,
F_238 ( V_208 ) ) ;
return 0 ;
}
if ( V_428 & V_377 )
V_23 |= V_438 ;
return V_23 ;
}
static unsigned int F_239 ( struct V_6 * V_7 , T_2 V_19 ,
int V_236 )
{
unsigned int V_23 = 0 ;
if ( V_19 != V_7 -> V_127 &&
( F_34 ( V_7 , V_19 ) & V_439 ) )
V_23 = F_25 ( V_7 , V_19 , V_440 ) ;
if ( ! V_23 || V_23 == - 1 )
V_23 = F_25 ( V_7 , V_7 -> V_127 , V_440 ) ;
if ( ! V_23 || V_23 == - 1 )
return 0 ;
return V_23 ;
}
static unsigned int F_240 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_118 ( V_7 , V_19 , 0 , F_241 ( V_19 ) ,
F_239 ) ;
}
static unsigned int F_242 ( struct V_6 * V_7 , T_2 V_19 ,
int V_236 )
{
unsigned int V_315 = F_25 ( V_7 , V_19 , V_441 ) ;
if ( ! V_315 || V_315 == - 1 )
V_315 = F_25 ( V_7 , V_7 -> V_127 , V_441 ) ;
if ( ! V_315 || V_315 == - 1 )
return 0 ;
return V_315 ;
}
static unsigned int F_243 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_118 ( V_7 , V_19 , 0 , F_244 ( V_19 ) ,
F_242 ) ;
}
int F_245 ( struct V_6 * V_7 , T_2 V_19 ,
T_1 * V_442 , T_8 * V_443 , unsigned int * V_444 )
{
unsigned int V_12 , V_23 , V_62 ;
V_62 = F_34 ( V_7 , V_19 ) ;
V_23 = F_240 ( V_7 , V_19 ) ;
if ( V_442 ) {
T_1 V_445 = 0 ;
for ( V_12 = 0 ; V_12 < V_446 ; V_12 ++ ) {
if ( V_23 & ( 1 << V_12 ) )
V_445 |= V_429 [ V_12 ] . V_447 ;
}
if ( V_445 == 0 ) {
F_32 ( V_25 L_79
L_80 ,
V_19 , V_23 ,
( V_62 & V_439 ) ? 1 : 0 ) ;
return - V_70 ;
}
* V_442 = V_445 ;
}
if ( V_443 || V_444 ) {
T_8 V_448 = 0 ;
unsigned int V_315 , V_449 ;
V_315 = F_243 ( V_7 , V_19 ) ;
if ( ! V_315 )
return - V_70 ;
V_449 = 0 ;
if ( V_315 & V_450 ) {
if ( V_23 & V_451 ) {
V_448 |= V_452 ;
V_449 = 8 ;
}
if ( V_23 & V_453 ) {
V_448 |= V_454 ;
V_449 = 16 ;
}
if ( V_62 & V_455 ) {
if ( V_23 & V_456 )
V_448 |= V_457 ;
if ( V_23 & ( V_458 | V_459 ) )
V_448 |= V_460 ;
if ( V_23 & V_459 )
V_449 = 24 ;
else if ( V_23 & V_458 )
V_449 = 20 ;
} else if ( V_23 & ( V_458 | V_459 |
V_456 ) ) {
V_448 |= V_460 ;
if ( V_23 & V_456 )
V_449 = 32 ;
else if ( V_23 & V_459 )
V_449 = 24 ;
else if ( V_23 & V_458 )
V_449 = 20 ;
}
}
#if 0
if (streams & AC_SUPFMT_FLOAT32) {
formats |= SNDRV_PCM_FMTBIT_FLOAT_LE;
if (!bps)
bps = 32;
}
#endif
if ( V_315 == V_461 ) {
V_448 |= V_452 ;
V_449 = 8 ;
}
if ( V_448 == 0 ) {
F_32 ( V_25 L_81
L_82
L_83 ,
V_19 , V_23 ,
( V_62 & V_439 ) ? 1 : 0 ,
V_315 ) ;
return - V_70 ;
}
if ( V_443 )
* V_443 = V_448 ;
if ( V_444 )
* V_444 = V_449 ;
}
return 0 ;
}
int F_246 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_208 )
{
int V_12 ;
unsigned int V_23 = 0 , V_425 , V_462 ;
V_23 = F_240 ( V_7 , V_19 ) ;
if ( ! V_23 )
return 0 ;
V_425 = V_208 & 0xff00 ;
for ( V_12 = 0 ; V_12 < V_446 ; V_12 ++ )
if ( V_429 [ V_12 ] . V_431 == V_425 ) {
if ( V_23 & ( 1 << V_12 ) )
break;
return 0 ;
}
if ( V_12 >= V_446 )
return 0 ;
V_462 = F_243 ( V_7 , V_19 ) ;
if ( ! V_462 )
return 0 ;
if ( V_462 & V_450 ) {
switch ( V_208 & 0xf0 ) {
case 0x00 :
if ( ! ( V_23 & V_451 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_23 & V_453 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_23 & V_458 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_23 & V_459 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_23 & V_456 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_247 ( struct V_463 * V_464 ,
struct V_6 * V_7 ,
struct V_465 * V_466 )
{
return 0 ;
}
static int F_248 ( struct V_463 * V_464 ,
struct V_6 * V_7 ,
unsigned int V_202 ,
unsigned int V_208 ,
struct V_465 * V_466 )
{
F_106 ( V_7 , V_464 -> V_19 , V_202 , 0 , V_208 ) ;
return 0 ;
}
static int F_249 ( struct V_463 * V_464 ,
struct V_6 * V_7 ,
struct V_465 * V_466 )
{
F_250 ( V_7 , V_464 -> V_19 ) ;
return 0 ;
}
static int F_251 ( struct V_6 * V_7 ,
struct V_463 * V_226 )
{
int V_30 ;
if ( V_226 -> V_19 && ( ! V_226 -> V_445 || ! V_226 -> V_448 ) ) {
V_30 = F_245 ( V_7 , V_226 -> V_19 ,
V_226 -> V_445 ? NULL : & V_226 -> V_445 ,
V_226 -> V_448 ? NULL : & V_226 -> V_448 ,
V_226 -> V_427 ? NULL : & V_226 -> V_427 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( V_226 -> V_33 . V_467 == NULL )
V_226 -> V_33 . V_467 = F_247 ;
if ( V_226 -> V_33 . V_468 == NULL )
V_226 -> V_33 . V_468 = F_247 ;
if ( V_226 -> V_33 . V_469 == NULL ) {
if ( F_33 ( ! V_226 -> V_19 ) )
return - V_56 ;
V_226 -> V_33 . V_469 = F_248 ;
}
if ( V_226 -> V_33 . V_470 == NULL ) {
if ( F_33 ( ! V_226 -> V_19 ) )
return - V_56 ;
V_226 -> V_33 . V_470 = F_249 ;
}
return 0 ;
}
int F_252 ( struct V_6 * V_7 ,
struct V_463 * V_464 ,
unsigned int V_462 ,
unsigned int V_208 ,
struct V_465 * V_466 )
{
int V_258 ;
F_2 ( & V_7 -> V_29 -> V_117 ) ;
V_258 = V_464 -> V_33 . V_469 ( V_464 , V_7 , V_462 , V_208 , V_466 ) ;
if ( V_258 >= 0 )
F_109 ( V_7 ) ;
F_4 ( & V_7 -> V_29 -> V_117 ) ;
return V_258 ;
}
void F_253 ( struct V_6 * V_7 ,
struct V_463 * V_464 ,
struct V_465 * V_466 )
{
F_2 ( & V_7 -> V_29 -> V_117 ) ;
V_464 -> V_33 . V_470 ( V_464 , V_7 , V_466 ) ;
F_4 ( & V_7 -> V_29 -> V_117 ) ;
}
static int F_254 ( struct V_28 * V_29 , int type )
{
static int V_471 [ V_472 ] [ 5 ] = {
[ V_473 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_474 ] = { 1 , - 1 } ,
[ V_475 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_476 ] = { 6 , - 1 } ,
} ;
int V_12 ;
if ( type >= V_472 ) {
F_32 ( V_73 L_84 , type ) ;
return - V_56 ;
}
for ( V_12 = 0 ; V_471 [ type ] [ V_12 ] >= 0 ; V_12 ++ )
if ( ! F_255 ( V_471 [ type ] [ V_12 ] , V_29 -> V_321 ) )
return V_471 [ type ] [ V_12 ] ;
for ( V_12 = 10 ; V_12 < 32 ; V_12 ++ ) {
if ( ! F_255 ( V_12 , V_29 -> V_321 ) )
return V_12 ;
}
F_32 ( V_73 L_85 ,
V_477 [ type ] ) ;
return - V_478 ;
}
static int F_256 ( struct V_6 * V_7 , struct V_312 * V_310 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
struct V_463 * V_226 ;
int V_462 , V_30 ;
if ( F_33 ( ! V_310 -> V_133 ) )
return - V_56 ;
for ( V_462 = 0 ; V_462 < 2 ; V_462 ++ ) {
V_226 = & V_310 -> V_462 [ V_462 ] ;
if ( V_226 -> V_479 ) {
V_30 = F_251 ( V_7 , V_226 ) ;
if ( V_30 < 0 )
return V_30 ;
}
}
return V_29 -> V_33 . V_480 ( V_29 , V_7 , V_310 ) ;
}
int F_257 ( struct V_6 * V_7 )
{
unsigned int V_310 ;
int V_30 ;
if ( ! V_7 -> V_311 ) {
if ( ! V_7 -> V_96 . V_481 )
return 0 ;
V_30 = V_7 -> V_96 . V_481 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_86
L_74 , V_7 -> V_24 , V_30 ) ;
V_30 = F_163 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25
L_75 ) ;
return V_30 ;
}
}
}
for ( V_310 = 0 ; V_310 < V_7 -> V_311 ; V_310 ++ ) {
struct V_312 * V_313 = & V_7 -> V_314 [ V_310 ] ;
int V_482 ;
if ( ! V_313 -> V_462 [ 0 ] . V_479 && ! V_313 -> V_462 [ 1 ] . V_479 )
continue;
if ( ! V_313 -> V_310 ) {
V_482 = F_254 ( V_7 -> V_29 , V_313 -> V_483 ) ;
if ( V_482 < 0 )
continue;
V_313 -> V_101 = V_482 ;
V_30 = F_256 ( V_7 , V_313 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_87
L_88 ,
V_482 , V_7 -> V_24 ) ;
continue;
}
}
}
return 0 ;
}
int T_9 F_258 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
int V_30 = F_257 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
}
return 0 ;
}
int F_259 ( struct V_6 * V_7 ,
int V_484 , const char * const * V_485 ,
const struct V_486 * V_123 )
{
if ( V_7 -> V_115 && V_485 ) {
int V_12 ;
for ( V_12 = 0 ; V_12 < V_484 ; V_12 ++ ) {
if ( V_485 [ V_12 ] &&
! strcmp ( V_7 -> V_115 , V_485 [ V_12 ] ) ) {
F_19 ( V_487 L_89
L_90 , V_485 [ V_12 ] ) ;
return V_12 ;
}
}
}
if ( ! V_7 -> V_29 -> V_114 || ! V_123 )
return - 1 ;
V_123 = F_260 ( V_7 -> V_29 -> V_114 , V_123 ) ;
if ( ! V_123 )
return - 1 ;
if ( V_123 -> V_270 >= 0 && V_123 -> V_270 < V_484 ) {
#ifdef F_261
char V_137 [ 10 ] ;
const char * V_488 = NULL ;
if ( V_485 )
V_488 = V_485 [ V_123 -> V_270 ] ;
if ( ! V_488 ) {
sprintf ( V_137 , L_91 , V_123 -> V_270 ) ;
V_488 = V_137 ;
}
F_95 ( V_487 L_92
L_93 ,
V_488 , V_123 -> V_489 , V_123 -> V_300 ,
( V_123 -> V_133 ? V_123 -> V_133 : L_94 ) ) ;
#endif
return V_123 -> V_270 ;
}
return - 1 ;
}
int F_262 ( struct V_6 * V_7 ,
int V_484 , const char * const * V_485 ,
const struct V_486 * V_123 )
{
const struct V_486 * V_217 ;
for ( V_217 = V_123 ; V_217 -> V_489 ; V_217 ++ ) {
unsigned int V_61 = 0xffff0000 | V_217 -> V_490 ;
unsigned int V_126 = ( V_217 -> V_300 | ( V_217 -> V_489 << 16 ) ) & V_61 ;
if ( ( V_7 -> V_192 & V_61 ) == V_126 )
break;
}
if ( ! V_217 -> V_489 )
return - 1 ;
V_123 = V_217 ;
if ( V_123 -> V_270 >= 0 && V_123 -> V_270 < V_484 ) {
#ifdef F_261
char V_137 [ 10 ] ;
const char * V_488 = NULL ;
if ( V_485 )
V_488 = V_485 [ V_123 -> V_270 ] ;
if ( ! V_488 ) {
sprintf ( V_137 , L_91 , V_123 -> V_270 ) ;
V_488 = V_137 ;
}
F_95 ( V_487 L_92
L_93 ,
V_488 , V_123 -> V_489 , V_123 -> V_300 ,
( V_123 -> V_133 ? V_123 -> V_133 : L_94 ) ) ;
#endif
return V_123 -> V_270 ;
}
return - 1 ;
}
int F_263 ( struct V_6 * V_7 ,
const struct V_393 * V_491 )
{
int V_30 ;
for (; V_491 -> V_133 ; V_491 ++ ) {
struct V_263 * V_297 ;
int V_24 = 0 , V_224 = 0 ;
if ( V_491 -> V_295 == - 1 )
continue;
for (; ; ) {
V_297 = F_184 ( V_491 , V_7 ) ;
if ( ! V_297 )
return - V_76 ;
if ( V_24 > 0 )
V_297 -> V_126 . V_101 = V_24 ;
if ( V_224 > 0 )
V_297 -> V_126 . V_240 = V_224 ;
V_30 = F_152 ( V_7 , 0 , V_297 ) ;
if ( ! V_30 )
break;
if ( ! V_24 && V_7 -> V_24 )
V_24 = V_7 -> V_24 ;
else if ( ! V_224 && ! V_491 -> V_240 ) {
V_224 = F_151 ( V_7 ,
V_491 -> V_133 ) ;
if ( V_224 <= 0 )
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
F_159 ( & V_7 -> V_188 ) ;
if ( V_7 -> V_318 > 0 ) {
F_161 ( & V_7 -> V_188 ) ;
return;
}
if ( ! V_7 -> V_317 || V_7 -> V_492 ) {
V_7 -> V_318 = 0 ;
F_161 ( & V_7 -> V_188 ) ;
return;
}
F_161 ( & V_7 -> V_188 ) ;
F_230 ( V_7 ) ;
if ( V_29 -> V_33 . V_493 )
V_29 -> V_33 . V_493 ( V_29 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
F_159 ( & V_7 -> V_188 ) ;
V_7 -> V_492 ++ ;
V_7 -> V_317 = 1 ;
V_7 -> V_319 = V_320 ;
F_161 ( & V_7 -> V_188 ) ;
}
void F_231 ( struct V_6 * V_7 )
{
unsigned long V_494 = V_320 - V_7 -> V_319 ;
if ( V_7 -> V_317 )
V_7 -> V_495 += V_494 ;
else
V_7 -> V_496 += V_494 ;
V_7 -> V_319 += V_494 ;
}
static void F_264 ( struct V_6 * V_7 , bool V_497 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
F_159 ( & V_7 -> V_188 ) ;
V_7 -> V_492 ++ ;
if ( ( V_7 -> V_317 || V_7 -> V_318 > 0 ) &&
! ( V_497 && V_7 -> V_318 < 0 ) ) {
F_161 ( & V_7 -> V_188 ) ;
return;
}
F_161 ( & V_7 -> V_188 ) ;
F_164 ( & V_7 -> V_171 ) ;
F_159 ( & V_7 -> V_188 ) ;
if ( V_7 -> V_317 ) {
if ( V_7 -> V_318 < 0 )
V_7 -> V_318 = 0 ;
F_161 ( & V_7 -> V_188 ) ;
return;
}
F_265 ( V_7 ) ;
F_231 ( V_7 ) ;
V_7 -> V_317 = 1 ;
V_7 -> V_319 = V_320 ;
V_7 -> V_318 = 1 ;
F_161 ( & V_7 -> V_188 ) ;
if ( V_29 -> V_33 . V_493 )
V_29 -> V_33 . V_493 ( V_29 ) ;
F_233 ( V_7 ) ;
F_159 ( & V_7 -> V_188 ) ;
V_7 -> V_318 = 0 ;
F_161 ( & V_7 -> V_188 ) ;
}
void F_15 ( struct V_6 * V_7 )
{
F_264 ( V_7 , false ) ;
}
void F_266 ( struct V_6 * V_7 )
{
F_264 ( V_7 , true ) ;
}
void F_18 ( struct V_6 * V_7 )
{
F_159 ( & V_7 -> V_188 ) ;
-- V_7 -> V_492 ;
if ( ! V_7 -> V_317 || V_7 -> V_492 || V_7 -> V_318 ) {
F_161 ( & V_7 -> V_188 ) ;
return;
}
if ( V_116 ( V_7 ) ) {
V_7 -> V_318 = - 1 ;
F_267 ( V_7 -> V_29 -> V_90 , & V_7 -> V_171 ,
F_227 ( V_116 ( V_7 ) * 1000 ) ) ;
}
F_161 ( & V_7 -> V_188 ) ;
}
int F_268 ( struct V_6 * V_7 ,
struct V_498 * V_499 ,
T_2 V_19 )
{
const struct V_500 * V_49 ;
int V_239 , V_501 ;
if ( ! V_499 -> V_502 )
return 0 ;
for ( V_49 = V_499 -> V_502 ; V_49 -> V_19 ; V_49 ++ ) {
if ( V_49 -> V_19 == V_19 )
break;
}
if ( ! V_49 -> V_19 )
return 0 ;
for ( V_49 = V_499 -> V_502 ; V_49 -> V_19 ; V_49 ++ ) {
for ( V_239 = 0 ; V_239 < 2 ; V_239 ++ ) {
V_501 = F_128 ( V_7 , V_49 -> V_19 , V_239 , V_49 -> V_236 ,
V_49 -> V_224 ) ;
if ( ! ( V_501 & V_254 ) && V_501 > 0 ) {
if ( ! V_499 -> V_317 ) {
V_499 -> V_317 = 1 ;
F_15 ( V_7 ) ;
}
return 1 ;
}
}
}
if ( V_499 -> V_317 ) {
V_499 -> V_317 = 0 ;
F_18 ( V_7 ) ;
}
return 0 ;
}
int F_269 ( struct V_6 * V_7 ,
struct V_265 * V_266 ,
const struct V_503 * V_504 ,
int V_505 )
{
V_266 -> type = V_345 ;
V_266 -> V_269 = 1 ;
V_266 -> V_270 . V_346 . V_305 = V_505 ;
if ( V_266 -> V_270 . V_346 . V_299 >= V_505 )
V_266 -> V_270 . V_346 . V_299 = V_505 - 1 ;
sprintf ( V_266 -> V_270 . V_346 . V_133 , L_95 ,
V_504 [ V_266 -> V_270 . V_346 . V_299 ] . V_426 ) ;
return 0 ;
}
int F_270 ( struct V_6 * V_7 ,
struct V_275 * V_276 ,
const struct V_503 * V_504 ,
int V_505 ,
int V_506 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_505 ; V_12 ++ ) {
if ( V_506 == V_504 [ V_12 ] . V_426 ) {
V_276 -> V_270 . V_346 . V_299 [ 0 ] = V_12 ;
break;
}
}
return 0 ;
}
int F_271 ( struct V_6 * V_7 ,
struct V_275 * V_276 ,
const struct V_503 * V_504 ,
int V_505 ,
int * V_507 )
{
unsigned int V_508 ;
V_508 = V_276 -> V_270 . V_346 . V_299 [ 0 ] ;
if ( V_508 >= V_505 )
return - V_56 ;
if ( * V_507 == V_504 [ V_508 ] . V_426 )
return 0 ;
* V_507 = V_504 [ V_508 ] . V_426 ;
if ( V_504 [ V_508 ] . V_509 )
F_225 ( V_7 , V_504 [ V_508 ] . V_509 ) ;
return 1 ;
}
int F_272 ( const struct V_510 * V_511 ,
struct V_265 * V_266 )
{
unsigned int V_240 ;
V_266 -> type = V_345 ;
V_266 -> V_269 = 1 ;
V_266 -> V_270 . V_346 . V_305 = V_511 -> V_512 ;
if ( ! V_511 -> V_512 )
return 0 ;
V_240 = V_266 -> V_270 . V_346 . V_299 ;
if ( V_240 >= V_511 -> V_512 )
V_240 = V_511 -> V_512 - 1 ;
strcpy ( V_266 -> V_270 . V_346 . V_133 , V_511 -> V_305 [ V_240 ] . V_513 ) ;
return 0 ;
}
int F_273 ( struct V_6 * V_7 ,
const struct V_510 * V_511 ,
struct V_275 * V_276 ,
T_2 V_19 ,
unsigned int * V_514 )
{
unsigned int V_224 ;
if ( ! V_511 -> V_512 )
return 0 ;
V_224 = V_276 -> V_270 . V_346 . V_299 [ 0 ] ;
if ( V_224 >= V_511 -> V_512 )
V_224 = V_511 -> V_512 - 1 ;
if ( * V_514 == V_224 )
return 0 ;
F_203 ( V_7 , V_19 , 0 , V_515 ,
V_511 -> V_305 [ V_224 ] . V_240 ) ;
* V_514 = V_224 ;
return 1 ;
}
static void F_274 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_202 , unsigned int V_208 )
{
struct V_187 * V_374 = F_210 ( V_7 , V_19 ) ;
if ( V_7 -> V_325 && ( V_374 -> V_388 & V_389 ) )
F_204 ( V_7 , V_19 ,
V_374 -> V_388 & ~ V_389 & 0xff ,
- 1 ) ;
F_106 ( V_7 , V_19 , V_202 , 0 , V_208 ) ;
if ( V_7 -> V_324 ) {
const T_2 * V_383 ;
for ( V_383 = V_7 -> V_324 ; * V_383 ; V_383 ++ )
F_106 ( V_7 , * V_383 , V_202 , 0 ,
V_208 ) ;
}
if ( V_7 -> V_325 && ( V_374 -> V_388 & V_389 ) )
F_204 ( V_7 , V_19 ,
V_374 -> V_388 & 0xff , - 1 ) ;
}
static void F_275 ( struct V_6 * V_7 , T_2 V_19 )
{
F_250 ( V_7 , V_19 ) ;
if ( V_7 -> V_324 ) {
const T_2 * V_383 ;
for ( V_383 = V_7 -> V_324 ; * V_383 ; V_383 ++ )
F_250 ( V_7 , * V_383 ) ;
}
}
void F_276 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
if ( ! V_29 )
return;
F_55 (codec, &bus->codec_list, list) {
if ( F_277 ( V_7 ) &&
V_7 -> V_96 . V_516 )
V_7 -> V_96 . V_516 ( V_7 ) ;
}
}
int F_278 ( struct V_6 * V_7 ,
struct V_397 * V_398 )
{
F_2 ( & V_7 -> V_182 ) ;
if ( V_398 -> V_517 == V_518 )
F_275 ( V_7 , V_398 -> V_400 ) ;
V_398 -> V_517 = V_519 ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_279 ( struct V_6 * V_7 ,
struct V_397 * V_398 ,
unsigned int V_202 ,
unsigned int V_208 ,
struct V_465 * V_466 )
{
F_2 ( & V_7 -> V_182 ) ;
F_274 ( V_7 , V_398 -> V_400 , V_202 , V_208 ) ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_280 ( struct V_6 * V_7 ,
struct V_397 * V_398 )
{
F_2 ( & V_7 -> V_182 ) ;
F_275 ( V_7 , V_398 -> V_400 ) ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_281 ( struct V_6 * V_7 ,
struct V_397 * V_398 )
{
F_2 ( & V_7 -> V_182 ) ;
V_398 -> V_517 = 0 ;
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
int F_282 ( struct V_6 * V_7 ,
struct V_397 * V_398 ,
struct V_465 * V_466 ,
struct V_463 * V_464 )
{
struct V_520 * V_521 = V_466 -> V_521 ;
V_521 -> V_522 . V_523 = V_398 -> V_506 ;
if ( V_398 -> V_400 ) {
if ( ! V_398 -> V_524 ) {
V_398 -> V_524 = V_464 -> V_445 ;
V_398 -> V_525 = V_464 -> V_448 ;
V_398 -> V_526 = V_464 -> V_427 ;
} else {
V_521 -> V_522 . V_445 = V_398 -> V_524 ;
V_521 -> V_522 . V_448 = V_398 -> V_525 ;
V_464 -> V_427 = V_398 -> V_526 ;
}
if ( ! V_398 -> V_527 ) {
F_245 ( V_7 , V_398 -> V_400 ,
& V_398 -> V_527 ,
& V_398 -> V_528 ,
& V_398 -> V_529 ) ;
}
F_2 ( & V_7 -> V_182 ) ;
if ( V_398 -> V_399 ) {
if ( ( V_521 -> V_522 . V_445 & V_398 -> V_527 ) &&
( V_521 -> V_522 . V_448 & V_398 -> V_528 ) ) {
V_521 -> V_522 . V_445 &= V_398 -> V_527 ;
V_521 -> V_522 . V_448 &= V_398 -> V_528 ;
if ( V_398 -> V_529 < V_464 -> V_427 )
V_464 -> V_427 = V_398 -> V_529 ;
} else {
V_398 -> V_399 = 0 ;
}
}
F_4 ( & V_7 -> V_182 ) ;
}
return F_283 ( V_466 -> V_521 , 0 ,
V_530 , 2 ) ;
}
int F_284 ( struct V_6 * V_7 ,
struct V_397 * V_398 ,
unsigned int V_202 ,
unsigned int V_208 ,
struct V_465 * V_466 )
{
const T_2 * V_173 = V_398 -> V_531 ;
int V_267 = V_466 -> V_521 -> V_426 ;
struct V_187 * V_374 ;
int V_12 ;
F_2 ( & V_7 -> V_182 ) ;
V_374 = F_210 ( V_7 , V_398 -> V_400 ) ;
if ( V_398 -> V_400 && V_398 -> V_399 &&
V_398 -> V_517 != V_519 ) {
if ( V_267 == 2 &&
F_246 ( V_7 , V_398 -> V_400 ,
V_208 ) &&
! ( V_374 -> V_366 & V_368 ) ) {
V_398 -> V_517 = V_518 ;
F_274 ( V_7 , V_398 -> V_400 ,
V_202 , V_208 ) ;
} else {
V_398 -> V_517 = 0 ;
F_275 ( V_7 , V_398 -> V_400 ) ;
}
}
F_4 ( & V_7 -> V_182 ) ;
F_106 ( V_7 , V_173 [ V_532 ] , V_202 ,
0 , V_208 ) ;
if ( ! V_398 -> V_533 &&
V_398 -> V_534 && V_398 -> V_534 != V_173 [ V_532 ] )
F_106 ( V_7 , V_398 -> V_534 , V_202 ,
0 , V_208 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_398 -> V_535 ) ; V_12 ++ )
if ( ! V_398 -> V_533 && V_398 -> V_535 [ V_12 ] )
F_106 ( V_7 ,
V_398 -> V_535 [ V_12 ] ,
V_202 , 0 , V_208 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_398 -> V_536 ) ; V_12 ++ )
if ( ! V_398 -> V_533 && V_398 -> V_536 [ V_12 ] )
F_106 ( V_7 ,
V_398 -> V_536 [ V_12 ] ,
V_202 , 0 , V_208 ) ;
for ( V_12 = 1 ; V_12 < V_398 -> V_537 ; V_12 ++ ) {
if ( V_267 >= ( V_12 + 1 ) * 2 )
F_106 ( V_7 , V_173 [ V_12 ] , V_202 ,
V_12 * 2 , V_208 ) ;
else if ( ! V_398 -> V_533 )
F_106 ( V_7 , V_173 [ V_12 ] , V_202 ,
0 , V_208 ) ;
}
return 0 ;
}
int F_285 ( struct V_6 * V_7 ,
struct V_397 * V_398 )
{
const T_2 * V_173 = V_398 -> V_531 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_398 -> V_537 ; V_12 ++ )
F_250 ( V_7 , V_173 [ V_12 ] ) ;
if ( V_398 -> V_534 )
F_250 ( V_7 , V_398 -> V_534 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_398 -> V_535 ) ; V_12 ++ )
if ( V_398 -> V_535 [ V_12 ] )
F_250 ( V_7 ,
V_398 -> V_535 [ V_12 ] ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_398 -> V_536 ) ; V_12 ++ )
if ( V_398 -> V_536 [ V_12 ] )
F_250 ( V_7 ,
V_398 -> V_536 [ V_12 ] ) ;
F_2 ( & V_7 -> V_182 ) ;
if ( V_398 -> V_400 && V_398 -> V_517 == V_518 ) {
F_275 ( V_7 , V_398 -> V_400 ) ;
V_398 -> V_517 = 0 ;
}
F_4 ( & V_7 -> V_182 ) ;
return 0 ;
}
unsigned int F_286 ( struct V_6 * V_7 , T_2 V_157 )
{
unsigned int V_538 ;
unsigned int V_204 ;
V_204 = F_21 ( V_7 , V_157 , 0 ,
V_162 , 0 ) ;
V_538 = F_122 ( V_7 , V_157 ) ;
V_538 = ( V_538 & V_539 ) >> V_540 ;
if ( ( V_538 & V_541 ) && V_204 != V_542 )
return V_543 ;
else if ( V_538 & V_544 )
return V_545 ;
else if ( V_538 & V_546 )
return V_547 ;
else if ( V_538 & V_548 )
return V_549 ;
return V_550 ;
}
int F_287 ( struct V_6 * V_7 , T_2 V_157 ,
unsigned int V_23 , bool V_551 )
{
if ( V_23 ) {
unsigned int V_552 = F_122 ( V_7 , V_157 ) ;
if ( V_552 && ( V_23 & V_553 ) ) {
if ( ! ( V_552 & V_554 ) )
V_23 &= ~ ( V_553 | V_555 ) ;
else if ( ( V_23 & V_555 ) &&
! ( V_552 & V_556 ) )
V_23 &= ~ V_555 ;
}
if ( V_552 && ( V_23 & V_557 ) ) {
if ( ! ( V_552 & V_558 ) )
V_23 &= ~ ( V_557 | V_559 ) ;
}
}
if ( V_551 )
return F_221 ( V_7 , V_157 , 0 ,
V_167 , V_23 ) ;
else
return F_22 ( V_7 , V_157 , 0 ,
V_167 , V_23 ) ;
}
int F_288 ( struct V_510 * V_511 , const char * V_513 ,
int V_240 , int * V_560 )
{
int V_12 , V_561 = 0 ;
if ( V_511 -> V_512 >= V_80 ) {
F_19 ( V_25 L_96 ) ;
return - V_56 ;
}
for ( V_12 = 0 ; V_12 < V_511 -> V_512 ; V_12 ++ ) {
if ( ! strncmp ( V_513 , V_511 -> V_305 [ V_12 ] . V_513 , strlen ( V_513 ) ) )
V_561 ++ ;
}
if ( V_560 )
* V_560 = V_561 ;
if ( V_561 > 0 )
snprintf ( V_511 -> V_305 [ V_511 -> V_512 ] . V_513 ,
sizeof( V_511 -> V_305 [ V_511 -> V_512 ] . V_513 ) ,
L_97 , V_513 , V_561 ) ;
else
F_289 ( V_511 -> V_305 [ V_511 -> V_512 ] . V_513 , V_513 ,
sizeof( V_511 -> V_305 [ V_511 -> V_512 ] . V_513 ) ) ;
V_511 -> V_305 [ V_511 -> V_512 ] . V_240 = V_240 ;
V_511 -> V_512 ++ ;
return 0 ;
}
int F_290 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
if ( F_277 ( V_7 ) )
F_230 ( V_7 ) ;
}
return 0 ;
}
int F_291 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_55 (codec, &bus->codec_list, list) {
F_233 ( V_7 ) ;
}
return 0 ;
}
void * F_37 ( struct V_45 * V_46 )
{
if ( V_46 -> V_48 >= V_46 -> V_562 ) {
int V_563 = V_46 -> V_562 + V_46 -> V_564 ;
int V_280 = ( V_563 + 1 ) * V_46 -> V_565 ;
int V_566 = V_46 -> V_562 * V_46 -> V_565 ;
void * V_567 ;
if ( F_33 ( V_563 >= 4096 ) )
return NULL ;
V_567 = F_292 ( V_46 -> V_4 , V_280 , V_98 ) ;
if ( ! V_567 )
return NULL ;
memset ( V_567 + V_566 , 0 , V_280 - V_566 ) ;
V_46 -> V_4 = V_567 ;
V_46 -> V_562 = V_563 ;
}
return F_27 ( V_46 , V_46 -> V_48 ++ ) ;
}
void F_84 ( struct V_45 * V_46 )
{
F_49 ( V_46 -> V_4 ) ;
V_46 -> V_48 = 0 ;
V_46 -> V_562 = 0 ;
V_46 -> V_4 = NULL ;
}
void F_293 ( int V_310 , char * V_222 , int V_568 )
{
static unsigned int V_569 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_12 , V_570 ;
for ( V_12 = 0 , V_570 = 0 ; V_12 < F_9 ( V_569 ) ; V_12 ++ )
if ( V_310 & ( V_451 << V_12 ) )
V_570 += snprintf ( V_222 + V_570 , V_568 - V_570 , L_98 , V_569 [ V_12 ] ) ;
V_222 [ V_570 ] = '\0' ;
}
