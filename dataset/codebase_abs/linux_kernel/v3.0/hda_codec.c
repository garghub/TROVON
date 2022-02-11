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
F_14 ( V_7 , V_26 , & V_27 ) ;
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
int F_23 ( struct V_6 * V_7 , T_2 V_19 ,
T_2 * V_45 , int V_46 )
{
struct V_47 * V_48 = & V_7 -> V_49 ;
int V_12 , V_50 , V_51 ;
T_2 V_4 [ V_52 ] ;
for ( V_12 = 0 ; V_12 < V_48 -> V_53 ; ) {
T_2 * V_54 = F_24 ( V_48 , V_12 ) ;
V_50 = V_54 [ 1 ] ;
if ( V_19 == * V_54 )
return F_25 ( V_19 , V_45 , V_46 ,
V_54 + 2 , V_50 ) ;
V_12 += V_50 + 2 ;
}
V_50 = F_26 ( V_7 , V_19 , V_4 , V_52 ) ;
if ( V_50 < 0 )
return V_50 ;
V_51 = V_48 -> V_53 ;
if ( ! F_27 ( V_48 , V_19 ) || ! F_27 ( V_48 , V_50 ) )
goto V_55;
for ( V_12 = 0 ; V_12 < V_50 ; V_12 ++ )
if ( ! F_27 ( V_48 , V_4 [ V_12 ] ) )
goto V_55;
return F_25 ( V_19 , V_45 , V_46 , V_4 , V_50 ) ;
V_55:
V_48 -> V_53 = V_51 ;
return - V_56 ;
}
static int F_26 ( struct V_6 * V_7 , T_2 V_19 ,
T_2 * V_45 , int V_46 )
{
unsigned int V_22 ;
int V_12 , V_57 , V_58 ;
unsigned int V_59 , V_60 , V_61 ;
unsigned int V_62 ;
T_2 V_63 ;
if ( F_28 ( ! V_45 || V_46 <= 0 ) )
return - V_64 ;
V_62 = F_29 ( V_7 , V_19 ) ;
if ( ! ( V_62 & V_65 ) &&
F_30 ( V_62 ) != V_66 ) {
F_31 ( V_67 L_39
L_40 , V_19 ) ;
return - V_64 ;
}
V_22 = F_22 ( V_7 , V_19 , V_68 ) ;
if ( V_22 & V_69 ) {
V_59 = 16 ;
V_60 = 2 ;
} else {
V_59 = 8 ;
V_60 = 4 ;
}
V_57 = V_22 & V_70 ;
V_61 = ( 1 << ( V_59 - 1 ) ) - 1 ;
if ( ! V_57 )
return 0 ;
if ( V_57 == 1 ) {
V_22 = F_18 ( V_7 , V_19 , 0 ,
V_71 , 0 ) ;
if ( V_22 == - 1 && V_7 -> V_29 -> V_36 )
return - V_72 ;
V_45 [ 0 ] = V_22 & V_61 ;
return 1 ;
}
V_58 = 0 ;
V_63 = 0 ;
for ( V_12 = 0 ; V_12 < V_57 ; V_12 ++ ) {
int V_73 ;
T_2 V_23 , V_74 ;
if ( V_12 % V_60 == 0 ) {
V_22 = F_18 ( V_7 , V_19 , 0 ,
V_71 , V_12 ) ;
if ( V_22 == - 1 && V_7 -> V_29 -> V_36 )
return - V_72 ;
}
V_73 = ! ! ( V_22 & ( 1 << ( V_59 - 1 ) ) ) ;
V_23 = V_22 & V_61 ;
if ( V_23 == 0 ) {
F_31 ( V_67 L_39
L_41 ,
V_19 , V_12 , V_22 ) ;
return 0 ;
}
V_22 >>= V_59 ;
if ( V_73 ) {
if ( ! V_63 || V_63 >= V_23 ) {
F_31 ( V_67 L_39
L_42 ,
V_63 , V_23 ) ;
continue;
}
for ( V_74 = V_63 + 1 ; V_74 <= V_23 ; V_74 ++ ) {
if ( V_58 >= V_46 ) {
F_31 ( V_25 L_39
L_43 ,
V_58 , V_19 ) ;
return - V_64 ;
}
V_45 [ V_58 ++ ] = V_74 ;
}
} else {
if ( V_58 >= V_46 ) {
F_31 ( V_25 L_39
L_43 ,
V_58 , V_19 ) ;
return - V_64 ;
}
V_45 [ V_58 ++ ] = V_23 ;
}
V_63 = V_23 ;
}
return V_58 ;
}
static bool F_27 ( struct V_47 * V_48 , T_2 V_19 )
{
T_2 * V_54 = F_32 ( V_48 ) ;
if ( ! V_54 )
return false ;
* V_54 = V_19 ;
return true ;
}
static int F_25 ( T_2 V_19 , T_2 * V_75 , int V_76 ,
T_2 * V_77 , int V_50 )
{
if ( V_50 > V_76 ) {
F_31 ( V_25 L_39
L_43 ,
V_50 , V_19 ) ;
return - V_64 ;
}
memcpy ( V_75 , V_77 , V_50 * sizeof( T_2 ) ) ;
return V_50 ;
}
int F_33 ( struct V_28 * V_29 , T_1 V_27 , T_1 V_78 )
{
struct V_79 * V_80 ;
unsigned int V_81 ;
V_80 = V_29 -> V_80 ;
if ( ! V_80 )
return 0 ;
V_81 = ( V_80 -> V_81 + 1 ) % V_82 ;
V_80 -> V_81 = V_81 ;
V_81 <<= 1 ;
V_80 -> V_83 [ V_81 ] = V_27 ;
V_80 -> V_83 [ V_81 + 1 ] = V_78 ;
F_34 ( V_29 -> V_84 , & V_80 -> V_85 ) ;
return 0 ;
}
static void F_35 ( struct V_86 * V_85 )
{
struct V_79 * V_80 =
F_36 ( V_85 , struct V_79 , V_85 ) ;
struct V_28 * V_29 = V_80 -> V_29 ;
struct V_6 * V_7 ;
unsigned int V_87 , V_88 , V_27 ;
while ( V_80 -> V_87 != V_80 -> V_81 ) {
V_87 = ( V_80 -> V_87 + 1 ) % V_82 ;
V_80 -> V_87 = V_87 ;
V_87 <<= 1 ;
V_27 = V_80 -> V_83 [ V_87 ] ;
V_88 = V_80 -> V_83 [ V_87 + 1 ] ;
if ( ! ( V_88 & ( 1 << 4 ) ) )
continue;
V_7 = V_29 -> V_89 [ V_88 & 0x0f ] ;
if ( V_7 && V_7 -> V_90 . V_91 )
V_7 -> V_90 . V_91 ( V_7 , V_27 ) ;
}
}
static int F_37 ( struct V_28 * V_29 )
{
struct V_79 * V_80 ;
if ( V_29 -> V_80 )
return 0 ;
V_80 = F_38 ( sizeof( * V_80 ) , V_92 ) ;
if ( ! V_80 ) {
F_31 ( V_25 L_39
L_44 ) ;
return - V_56 ;
}
F_39 ( & V_80 -> V_85 , F_35 ) ;
V_80 -> V_29 = V_29 ;
V_29 -> V_80 = V_80 ;
return 0 ;
}
static int F_40 ( struct V_28 * V_29 )
{
struct V_6 * V_7 , * V_74 ;
if ( ! V_29 )
return 0 ;
if ( V_29 -> V_84 )
F_41 ( V_29 -> V_84 ) ;
if ( V_29 -> V_80 )
F_42 ( V_29 -> V_80 ) ;
F_43 (codec, n, &bus->codec_list, list) {
F_44 ( V_7 ) ;
}
if ( V_29 -> V_33 . V_93 )
V_29 -> V_33 . V_93 ( V_29 ) ;
if ( V_29 -> V_84 )
F_45 ( V_29 -> V_84 ) ;
F_42 ( V_29 ) ;
return 0 ;
}
static int F_46 ( struct V_94 * V_95 )
{
struct V_28 * V_29 = V_95 -> V_96 ;
V_29 -> V_97 = 1 ;
return F_40 ( V_29 ) ;
}
static int F_47 ( struct V_94 * V_95 )
{
struct V_28 * V_29 = V_95 -> V_96 ;
struct V_6 * V_7 ;
F_48 (codec, &bus->codec_list, list) {
F_49 ( V_7 ) ;
F_50 ( V_7 ) ;
}
return 0 ;
}
int F_51 ( struct V_98 * V_99 ,
const struct V_100 * V_101 ,
struct V_28 * * V_102 )
{
struct V_28 * V_29 ;
int V_30 ;
static struct V_103 V_104 = {
. V_105 = F_47 ,
. V_106 = F_46 ,
} ;
if ( F_28 ( ! V_101 ) )
return - V_64 ;
if ( F_28 ( ! V_101 -> V_33 . V_34 || ! V_101 -> V_33 . V_35 ) )
return - V_64 ;
if ( V_102 )
* V_102 = NULL ;
V_29 = F_38 ( sizeof( * V_29 ) , V_92 ) ;
if ( V_29 == NULL ) {
F_31 ( V_25 L_45 ) ;
return - V_56 ;
}
V_29 -> V_99 = V_99 ;
V_29 -> V_107 = V_101 -> V_107 ;
V_29 -> V_108 = V_101 -> V_108 ;
V_29 -> V_109 = V_101 -> V_109 ;
V_29 -> V_110 = V_101 -> V_110 ;
V_29 -> V_33 = V_101 -> V_33 ;
F_52 ( & V_29 -> V_32 ) ;
F_52 ( & V_29 -> V_111 ) ;
F_53 ( & V_29 -> V_112 ) ;
snprintf ( V_29 -> V_113 , sizeof( V_29 -> V_113 ) ,
L_46 , V_99 -> V_114 ) ;
V_29 -> V_84 = F_54 ( V_29 -> V_113 ) ;
if ( ! V_29 -> V_84 ) {
F_31 ( V_25 L_47 ,
V_29 -> V_113 ) ;
F_42 ( V_29 ) ;
return - V_56 ;
}
V_30 = F_55 ( V_99 , V_115 , V_29 , & V_104 ) ;
if ( V_30 < 0 ) {
F_40 ( V_29 ) ;
return V_30 ;
}
if ( V_102 )
* V_102 = V_29 ;
return 0 ;
}
static const struct V_116 *
F_56 ( struct V_6 * V_7 )
{
struct V_1 * V_117 ;
const struct V_116 * V_2 ;
int V_118 = 0 ;
if ( F_57 ( V_7 ) )
return NULL ;
V_31:
F_2 ( & V_3 ) ;
F_48 (tbl, &hda_preset_tables, list) {
if ( ! F_58 ( V_117 -> V_119 ) ) {
F_31 ( V_25 L_48 ) ;
continue;
}
for ( V_2 = V_117 -> V_2 ; V_2 -> V_120 ; V_2 ++ ) {
T_1 V_61 = V_2 -> V_61 ;
if ( V_2 -> V_121 && V_2 -> V_121 != V_7 -> V_121 )
continue;
if ( V_2 -> V_122 && V_2 -> V_122 != V_7 -> V_122 )
continue;
if ( ! V_61 )
V_61 = ~ 0 ;
if ( V_2 -> V_120 == ( V_7 -> V_123 & V_61 ) &&
( ! V_2 -> V_124 ||
V_2 -> V_124 == V_7 -> V_125 ) ) {
F_4 ( & V_3 ) ;
V_7 -> V_119 = V_117 -> V_119 ;
return V_2 ;
}
}
F_59 ( V_117 -> V_119 ) ;
}
F_4 ( & V_3 ) ;
if ( V_118 < V_126 ) {
char V_127 [ 32 ] ;
if ( ! V_118 )
snprintf ( V_127 , sizeof( V_127 ) , L_49 ,
V_7 -> V_123 ) ;
else
snprintf ( V_127 , sizeof( V_127 ) , L_50 ,
( V_7 -> V_123 >> 16 ) & 0xffff ) ;
F_60 ( V_127 ) ;
V_118 ++ ;
goto V_31;
}
return NULL ;
}
static int F_61 ( struct V_6 * V_7 )
{
const struct V_128 * V_129 ;
const char * V_130 = NULL ;
T_3 V_123 = V_7 -> V_123 >> 16 ;
char V_131 [ 16 ] ;
if ( V_7 -> V_132 )
goto V_133;
for ( V_129 = V_134 ; V_129 -> V_120 ; V_129 ++ ) {
if ( V_129 -> V_120 == V_123 ) {
V_130 = V_129 -> V_127 ;
break;
}
}
if ( ! V_130 ) {
sprintf ( V_131 , L_51 , V_123 ) ;
V_130 = V_131 ;
}
V_7 -> V_132 = F_62 ( V_130 , V_92 ) ;
if ( ! V_7 -> V_132 )
return - V_56 ;
V_133:
if ( V_7 -> V_135 )
return 0 ;
if ( V_7 -> V_2 && V_7 -> V_2 -> V_127 )
V_7 -> V_135 = F_62 ( V_7 -> V_2 -> V_127 , V_92 ) ;
else {
sprintf ( V_131 , L_52 , V_7 -> V_123 & 0xffff ) ;
V_7 -> V_135 = F_62 ( V_131 , V_92 ) ;
}
if ( ! V_7 -> V_135 )
return - V_56 ;
return 0 ;
}
static void F_63 ( struct V_6 * V_7 )
{
int V_12 , V_136 , V_137 ;
T_2 V_19 ;
V_136 = F_21 ( V_7 , V_138 , & V_19 ) ;
for ( V_12 = 0 ; V_12 < V_136 ; V_12 ++ , V_19 ++ ) {
V_137 = F_22 ( V_7 , V_19 ,
V_139 ) ;
switch ( V_137 & 0xff ) {
case V_140 :
V_7 -> V_121 = V_19 ;
V_7 -> V_141 = V_137 & 0xff ;
V_7 -> V_142 = ( V_137 >> 8 ) & 1 ;
break;
case V_143 :
V_7 -> V_122 = V_19 ;
V_7 -> V_144 = V_137 & 0xff ;
V_7 -> V_145 = ( V_137 >> 8 ) & 1 ;
break;
default:
break;
}
}
}
static int F_64 ( struct V_6 * V_7 , T_2 V_146 )
{
int V_12 ;
T_2 V_19 ;
V_7 -> V_147 = F_21 ( V_7 , V_146 ,
& V_7 -> V_148 ) ;
V_7 -> V_62 = F_65 ( V_7 -> V_147 * 4 , V_92 ) ;
if ( ! V_7 -> V_62 )
return - V_56 ;
V_19 = V_7 -> V_148 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_147 ; V_12 ++ , V_19 ++ )
V_7 -> V_62 [ V_12 ] = F_22 ( V_7 , V_19 ,
V_149 ) ;
return 0 ;
}
static int F_66 ( struct V_6 * V_7 )
{
int V_12 ;
T_2 V_19 = V_7 -> V_148 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_147 ; V_12 ++ , V_19 ++ ) {
struct V_150 * V_151 ;
unsigned int V_62 = F_29 ( V_7 , V_19 ) ;
unsigned int V_152 = F_30 ( V_62 ) ;
if ( V_152 != V_153 )
continue;
V_151 = F_32 ( & V_7 -> V_154 ) ;
if ( ! V_151 )
return - V_56 ;
V_151 -> V_19 = V_19 ;
V_151 -> V_8 = F_18 ( V_7 , V_19 , 0 ,
V_155 , 0 ) ;
V_151 -> V_156 = F_18 ( V_7 , V_19 , 0 ,
V_157 ,
0 ) ;
}
return 0 ;
}
static struct V_150 * F_67 ( struct V_6 * V_7 ,
struct V_47 * V_48 ,
T_2 V_19 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_48 -> V_53 ; V_12 ++ ) {
struct V_150 * V_151 = F_24 ( V_48 , V_12 ) ;
if ( V_151 -> V_19 == V_19 )
return V_151 ;
}
return NULL ;
}
static void F_68 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_8 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ ) {
F_19 ( V_7 , V_19 , 0 ,
V_158 + V_12 ,
V_8 & 0xff ) ;
V_8 >>= 8 ;
}
}
int F_69 ( struct V_6 * V_7 , struct V_47 * V_4 ,
T_2 V_19 , unsigned int V_8 )
{
struct V_150 * V_151 ;
unsigned int V_159 ;
if ( F_30 ( F_29 ( V_7 , V_19 ) ) != V_153 )
return - V_64 ;
V_159 = F_70 ( V_7 , V_19 ) ;
V_151 = F_67 ( V_7 , V_4 , V_19 ) ;
if ( ! V_151 ) {
V_151 = F_32 ( V_4 ) ;
if ( ! V_151 )
return - V_56 ;
V_151 -> V_19 = V_19 ;
}
V_151 -> V_8 = V_8 ;
V_8 = F_70 ( V_7 , V_19 ) ;
if ( V_159 != V_8 )
F_68 ( V_7 , V_19 , V_8 ) ;
return 0 ;
}
int F_71 ( struct V_6 * V_7 ,
T_2 V_19 , unsigned int V_8 )
{
return F_69 ( V_7 , & V_7 -> V_160 , V_19 , V_8 ) ;
}
unsigned int F_70 ( struct V_6 * V_7 , T_2 V_19 )
{
struct V_150 * V_151 ;
#ifdef F_72
V_151 = F_67 ( V_7 , & V_7 -> V_161 , V_19 ) ;
if ( V_151 )
return V_151 -> V_8 ;
#endif
V_151 = F_67 ( V_7 , & V_7 -> V_160 , V_19 ) ;
if ( V_151 )
return V_151 -> V_8 ;
V_151 = F_67 ( V_7 , & V_7 -> V_154 , V_19 ) ;
if ( V_151 )
return V_151 -> V_8 ;
return 0 ;
}
static void F_73 ( struct V_6 * V_7 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_154 . V_53 ; V_12 ++ ) {
struct V_150 * V_151 = F_24 ( & V_7 -> V_154 , V_12 ) ;
F_68 ( V_7 , V_151 -> V_19 ,
F_70 ( V_7 , V_151 -> V_19 ) ) ;
}
}
void F_74 ( struct V_6 * V_7 )
{
int V_12 ;
if ( V_7 -> V_29 -> V_97 )
return;
for ( V_12 = 0 ; V_12 < V_7 -> V_154 . V_53 ; V_12 ++ ) {
struct V_150 * V_151 = F_24 ( & V_7 -> V_154 , V_12 ) ;
F_18 ( V_7 , V_151 -> V_19 , 0 ,
V_162 , 0 ) ;
}
V_7 -> V_163 = 1 ;
}
static void F_75 ( struct V_6 * V_7 )
{
int V_12 ;
if ( ! V_7 -> V_163 )
return;
if ( V_7 -> V_29 -> V_97 )
return;
for ( V_12 = 0 ; V_12 < V_7 -> V_154 . V_53 ; V_12 ++ ) {
struct V_150 * V_151 = F_24 ( & V_7 -> V_154 , V_12 ) ;
F_19 ( V_7 , V_151 -> V_19 , 0 ,
V_162 ,
V_151 -> V_156 ) ;
}
V_7 -> V_163 = 0 ;
}
static void F_76 ( struct V_6 * V_7 )
{
F_77 ( & V_7 -> V_160 ) ;
#ifdef F_72
F_77 ( & V_7 -> V_161 ) ;
#endif
F_73 ( V_7 ) ;
F_77 ( & V_7 -> V_154 ) ;
}
static struct V_164 *
F_78 ( struct V_6 * V_7 , T_2 V_19 )
{
struct V_164 * V_54 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_165 . V_53 ; V_12 ++ ) {
V_54 = F_24 ( & V_7 -> V_165 , V_12 ) ;
if ( V_54 -> V_19 == V_19 )
return V_54 ;
}
V_54 = F_32 ( & V_7 -> V_165 ) ;
if ( V_54 )
V_54 -> V_19 = V_19 ;
return V_54 ;
}
static void F_44 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_76 ( V_7 ) ;
#ifdef F_79
F_80 ( & V_7 -> V_166 ) ;
F_41 ( V_7 -> V_29 -> V_84 ) ;
#endif
F_6 ( & V_7 -> V_4 ) ;
F_77 ( & V_7 -> V_167 ) ;
F_77 ( & V_7 -> V_168 ) ;
F_77 ( & V_7 -> V_49 ) ;
V_7 -> V_29 -> V_89 [ V_7 -> V_24 ] = NULL ;
if ( V_7 -> V_90 . free )
V_7 -> V_90 . free ( V_7 ) ;
F_59 ( V_7 -> V_119 ) ;
F_81 ( & V_7 -> V_169 ) ;
F_81 ( & V_7 -> V_170 ) ;
F_42 ( V_7 -> V_132 ) ;
F_42 ( V_7 -> V_135 ) ;
F_42 ( V_7 -> V_109 ) ;
F_42 ( V_7 -> V_62 ) ;
F_42 ( V_7 ) ;
}
int F_82 ( struct V_28 * V_29 ,
unsigned int V_171 ,
struct V_6 * * V_172 )
{
struct V_6 * V_7 ;
char V_173 [ 31 ] ;
int V_30 ;
if ( F_28 ( ! V_29 ) )
return - V_64 ;
if ( F_28 ( V_171 > V_174 ) )
return - V_64 ;
if ( V_29 -> V_89 [ V_171 ] ) {
F_31 ( V_25 L_39
L_53 , V_171 ) ;
return - V_175 ;
}
V_7 = F_38 ( sizeof( * V_7 ) , V_92 ) ;
if ( V_7 == NULL ) {
F_31 ( V_25 L_54 ) ;
return - V_56 ;
}
V_7 -> V_29 = V_29 ;
V_7 -> V_24 = V_171 ;
F_52 ( & V_7 -> V_176 ) ;
F_52 ( & V_7 -> V_177 ) ;
F_83 ( & V_7 -> V_169 , sizeof( struct V_178 ) ) ;
F_83 ( & V_7 -> V_170 , sizeof( struct V_179 ) ) ;
F_84 ( & V_7 -> V_167 , sizeof( struct V_180 ) , 32 ) ;
F_84 ( & V_7 -> V_168 , sizeof( struct V_180 ) , 32 ) ;
F_84 ( & V_7 -> V_154 , sizeof( struct V_150 ) , 16 ) ;
F_84 ( & V_7 -> V_160 , sizeof( struct V_150 ) , 16 ) ;
F_84 ( & V_7 -> V_165 , sizeof( struct V_164 ) , 8 ) ;
F_84 ( & V_7 -> V_49 , sizeof( T_2 ) , 64 ) ;
if ( V_7 -> V_29 -> V_109 ) {
V_7 -> V_109 = F_62 ( V_7 -> V_29 -> V_109 , V_92 ) ;
if ( ! V_7 -> V_109 ) {
F_44 ( V_7 ) ;
return - V_181 ;
}
}
#ifdef F_79
F_85 ( & V_7 -> V_166 , V_182 ) ;
F_7 ( V_7 ) ;
#endif
F_3 ( & V_7 -> V_4 , & V_29 -> V_112 ) ;
V_29 -> V_89 [ V_171 ] = V_7 ;
V_7 -> V_123 = F_22 ( V_7 , V_138 ,
V_183 ) ;
if ( V_7 -> V_123 == - 1 )
V_7 -> V_123 = F_22 ( V_7 , V_138 ,
V_183 ) ;
V_7 -> V_184 = F_22 ( V_7 , V_138 ,
V_185 ) ;
V_7 -> V_125 = F_22 ( V_7 , V_138 ,
V_186 ) ;
F_63 ( V_7 ) ;
if ( ! V_7 -> V_121 && ! V_7 -> V_122 ) {
F_86 ( L_55 ) ;
V_30 = - V_181 ;
goto error;
}
V_30 = F_64 ( V_7 , V_7 -> V_121 ? V_7 -> V_121 : V_7 -> V_122 ) ;
if ( V_30 < 0 ) {
F_31 ( V_25 L_56 ) ;
goto error;
}
V_30 = F_66 ( V_7 ) ;
if ( V_30 < 0 )
goto error;
if ( ! V_7 -> V_184 ) {
T_2 V_19 = V_7 -> V_121 ? V_7 -> V_121 : V_7 -> V_122 ;
V_7 -> V_184 =
F_18 ( V_7 , V_19 , 0 ,
V_187 , 0 ) ;
}
F_87 ( V_7 ,
V_7 -> V_121 ? V_7 -> V_121 : V_7 -> V_122 ,
V_188 ) ;
F_88 ( V_7 ) ;
F_89 ( V_7 ) ;
sprintf ( V_173 , L_57 , V_7 -> V_123 ,
V_7 -> V_184 , V_7 -> V_125 ) ;
F_90 ( V_7 -> V_29 -> V_99 , V_173 ) ;
if ( V_172 )
* V_172 = V_7 ;
return 0 ;
error:
F_44 ( V_7 ) ;
return V_30 ;
}
int F_91 ( struct V_6 * V_7 )
{
int V_30 ;
V_7 -> V_2 = F_56 ( V_7 ) ;
if ( ! V_7 -> V_132 || ! V_7 -> V_135 ) {
V_30 = F_61 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( F_57 ( V_7 ) ) {
V_30 = F_92 ( V_7 ) ;
goto V_189;
}
if ( V_7 -> V_2 && V_7 -> V_2 -> V_190 ) {
V_30 = V_7 -> V_2 -> V_190 ( V_7 ) ;
goto V_189;
}
V_30 = F_92 ( V_7 ) ;
if ( V_30 < 0 )
F_13 ( V_25 L_58 ) ;
V_189:
if ( ! V_30 && V_7 -> V_90 . V_91 )
V_30 = F_37 ( V_7 -> V_29 ) ;
if ( ! V_30 && ( V_7 -> V_121 || ! * V_7 -> V_29 -> V_99 -> V_191 ) )
snprintf ( V_7 -> V_29 -> V_99 -> V_191 ,
sizeof( V_7 -> V_29 -> V_99 -> V_191 ) ,
L_59 , V_7 -> V_132 , V_7 -> V_135 ) ;
return V_30 ;
}
void F_93 ( struct V_6 * V_7 , T_2 V_19 ,
T_1 V_192 ,
int V_193 , int V_194 )
{
struct V_6 * V_129 ;
struct V_164 * V_54 ;
unsigned int V_195 , V_196 ;
int type ;
int V_12 ;
if ( ! V_19 )
return;
F_86 ( L_60
L_61 ,
V_19 , V_192 , V_193 , V_194 ) ;
V_54 = F_78 ( V_7 , V_19 ) ;
if ( ! V_54 )
return;
if ( V_54 -> V_192 != V_192 || V_54 -> V_193 != V_193 ) {
V_195 = F_18 ( V_7 , V_19 , 0 , V_197 , 0 ) ;
V_196 = ( V_192 << 4 ) | V_193 ;
if ( V_195 != V_196 )
F_19 ( V_7 , V_19 , 0 ,
V_198 ,
V_196 ) ;
V_54 -> V_192 = V_192 ;
V_54 -> V_193 = V_193 ;
}
if ( V_54 -> V_199 != V_194 ) {
V_195 = F_18 ( V_7 , V_19 , 0 ,
V_200 , 0 ) ;
if ( V_195 != V_194 ) {
F_94 ( 1 ) ;
F_19 ( V_7 , V_19 , 0 ,
V_201 ,
V_194 ) ;
}
V_54 -> V_199 = V_194 ;
}
V_54 -> V_202 = 1 ;
V_54 -> V_203 = 0 ;
type = F_30 ( F_29 ( V_7 , V_19 ) ) ;
F_48 (c, &codec->bus->codec_list, list) {
for ( V_12 = 0 ; V_12 < V_129 -> V_165 . V_53 ; V_12 ++ ) {
V_54 = F_24 ( & V_129 -> V_165 , V_12 ) ;
if ( ! V_54 -> V_202 && V_54 -> V_192 == V_192 &&
F_30 ( F_29 ( V_7 , V_54 -> V_19 ) ) == type )
V_54 -> V_203 = 1 ;
}
}
}
void F_95 ( struct V_6 * V_7 , T_2 V_19 ,
int V_204 )
{
struct V_164 * V_54 ;
if ( ! V_19 )
return;
if ( V_7 -> V_205 )
V_204 = 1 ;
F_86 ( L_62 , V_19 ) ;
V_54 = F_78 ( V_7 , V_19 ) ;
if ( V_54 ) {
if ( V_204 )
F_96 ( V_7 , V_54 ) ;
else
V_54 -> V_202 = 0 ;
}
}
static void F_96 ( struct V_6 * V_7 ,
struct V_164 * V_206 )
{
T_2 V_19 = V_206 -> V_19 ;
F_19 ( V_7 , V_19 , 0 , V_198 , 0 ) ;
F_19 ( V_7 , V_19 , 0 , V_201 , 0 ) ;
memset ( V_206 , 0 , sizeof( * V_206 ) ) ;
V_206 -> V_19 = V_19 ;
}
static void F_97 ( struct V_6 * V_7 )
{
struct V_6 * V_129 ;
int V_12 ;
F_48 (c, &codec->bus->codec_list, list) {
for ( V_12 = 0 ; V_12 < V_129 -> V_165 . V_53 ; V_12 ++ ) {
struct V_164 * V_54 ;
V_54 = F_24 ( & V_129 -> V_165 , V_12 ) ;
if ( V_54 -> V_203 )
F_96 ( V_129 , V_54 ) ;
}
}
}
static void F_98 ( struct V_6 * V_7 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_165 . V_53 ; V_12 ++ ) {
struct V_164 * V_54 = F_24 ( & V_7 -> V_165 , V_12 ) ;
if ( V_54 -> V_192 )
F_96 ( V_7 , V_54 ) ;
}
}
static void F_83 ( struct V_207 * V_208 ,
unsigned int V_209 )
{
memset ( V_208 , 0 , sizeof( * V_208 ) ) ;
memset ( V_208 -> V_210 , 0xff , sizeof( V_208 -> V_210 ) ) ;
F_84 ( & V_208 -> V_211 , V_209 , 64 ) ;
}
static void F_81 ( struct V_207 * V_208 )
{
F_77 ( & V_208 -> V_211 ) ;
}
static struct V_179 * F_99 ( struct V_207 * V_208 , T_1 V_212 )
{
T_3 V_213 = V_212 % ( T_3 ) F_9 ( V_208 -> V_210 ) ;
T_3 V_214 = V_208 -> V_210 [ V_213 ] ;
struct V_179 * V_215 ;
while ( V_214 != 0xffff ) {
V_215 = F_24 ( & V_208 -> V_211 , V_214 ) ;
if ( V_215 -> V_212 == V_212 )
return V_215 ;
V_214 = V_215 -> V_216 ;
}
return NULL ;
}
static struct V_179 * F_100 ( struct V_207 * V_208 ,
T_1 V_212 )
{
struct V_179 * V_215 = F_99 ( V_208 , V_212 ) ;
if ( ! V_215 ) {
T_3 V_213 , V_214 ;
V_215 = F_32 ( & V_208 -> V_211 ) ;
if ( ! V_215 )
return NULL ;
V_214 = F_101 ( & V_208 -> V_211 , V_215 ) ;
V_215 -> V_212 = V_212 ;
V_215 -> V_23 = 0 ;
V_213 = V_212 % ( T_3 ) F_9 ( V_208 -> V_210 ) ;
V_215 -> V_216 = V_208 -> V_210 [ V_213 ] ;
V_208 -> V_210 [ V_213 ] = V_214 ;
}
return V_215 ;
}
static inline struct V_178 *
F_102 ( struct V_6 * V_7 , T_1 V_212 )
{
return (struct V_178 * ) F_100 ( & V_7 -> V_169 , V_212 ) ;
}
T_1 F_103 ( struct V_6 * V_7 , T_2 V_19 , int V_217 )
{
struct V_178 * V_215 ;
V_215 = F_102 ( V_7 , F_104 ( V_19 , V_217 , 0 ) ) ;
if ( ! V_215 )
return 0 ;
if ( ! ( V_215 -> V_218 . V_23 & V_219 ) ) {
if ( ! ( F_29 ( V_7 , V_19 ) & V_220 ) )
V_19 = V_7 -> V_121 ;
V_215 -> V_221 = F_22 ( V_7 , V_19 ,
V_217 == V_222 ?
V_223 :
V_224 ) ;
if ( V_215 -> V_221 )
V_215 -> V_218 . V_23 |= V_219 ;
}
return V_215 -> V_221 ;
}
int F_105 ( struct V_6 * V_7 , T_2 V_19 , int V_225 ,
unsigned int V_226 )
{
struct V_178 * V_215 ;
V_215 = F_102 ( V_7 , F_104 ( V_19 , V_225 , 0 ) ) ;
if ( ! V_215 )
return - V_64 ;
V_215 -> V_221 = V_226 ;
V_215 -> V_218 . V_23 |= V_219 ;
return 0 ;
}
static unsigned int F_106 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_22 ( V_7 , V_19 , V_227 ) ;
}
T_1 F_107 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_108 ( V_7 , V_19 , F_109 ( V_19 ) ,
F_106 ) ;
}
T_1 F_110 ( struct V_6 * V_7 , T_2 V_19 )
{
T_1 V_228 ;
if ( ! V_7 -> V_229 ) {
V_228 = F_107 ( V_7 , V_19 ) ;
if ( V_228 & V_230 )
F_18 ( V_7 , V_19 , 0 ,
V_231 , 0 ) ;
}
return F_18 ( V_7 , V_19 , 0 ,
V_232 , 0 ) ;
}
int F_111 ( struct V_6 * V_7 , T_2 V_19 )
{
T_1 V_233 = F_110 ( V_7 , V_19 ) ;
return ! ! ( V_233 & V_234 ) ;
}
static unsigned int F_112 ( struct V_6 * V_7 ,
struct V_178 * V_215 , T_2 V_19 ,
int V_235 , int V_217 , int V_236 )
{
T_1 V_23 , V_22 ;
if ( V_215 -> V_218 . V_23 & F_113 ( V_235 ) )
return V_215 -> V_237 [ V_235 ] ;
V_22 = V_235 ? V_238 : V_239 ;
V_22 |= V_217 == V_222 ? V_240 : V_241 ;
V_22 |= V_236 ;
V_23 = F_18 ( V_7 , V_19 , 0 ,
V_242 , V_22 ) ;
V_215 -> V_237 [ V_235 ] = V_23 & 0xff ;
V_215 -> V_218 . V_23 |= F_113 ( V_235 ) ;
return V_215 -> V_237 [ V_235 ] ;
}
static void F_114 ( struct V_6 * V_7 , struct V_178 * V_215 ,
T_2 V_19 , int V_235 , int V_217 , int V_236 ,
int V_23 )
{
T_1 V_22 ;
V_22 = V_235 ? V_243 : V_244 ;
V_22 |= V_217 == V_222 ? V_245 : V_246 ;
V_22 |= V_236 << V_247 ;
V_22 |= V_23 ;
F_19 ( V_7 , V_19 , 0 , V_248 , V_22 ) ;
V_215 -> V_237 [ V_235 ] = V_23 ;
}
int F_115 ( struct V_6 * V_7 , T_2 V_19 , int V_235 ,
int V_217 , int V_236 )
{
struct V_178 * V_215 ;
V_215 = F_102 ( V_7 , F_104 ( V_19 , V_217 , V_236 ) ) ;
if ( ! V_215 )
return 0 ;
return F_112 ( V_7 , V_215 , V_19 , V_235 , V_217 , V_236 ) ;
}
int F_116 ( struct V_6 * V_7 , T_2 V_19 , int V_235 ,
int V_217 , int V_213 , int V_61 , int V_23 )
{
struct V_178 * V_215 ;
V_215 = F_102 ( V_7 , F_104 ( V_19 , V_217 , V_213 ) ) ;
if ( ! V_215 )
return 0 ;
if ( F_28 ( V_61 & ~ 0xff ) )
V_61 &= 0xff ;
V_23 &= V_61 ;
V_23 |= F_112 ( V_7 , V_215 , V_19 , V_235 , V_217 , V_213 ) & ~ V_61 ;
if ( V_215 -> V_237 [ V_235 ] == V_23 )
return 0 ;
F_114 ( V_7 , V_215 , V_19 , V_235 , V_217 , V_213 , V_23 ) ;
return 1 ;
}
int F_117 ( struct V_6 * V_7 , T_2 V_19 ,
int V_217 , int V_213 , int V_61 , int V_23 )
{
int V_235 , V_249 = 0 ;
if ( F_28 ( V_61 & ~ 0xff ) )
V_61 &= 0xff ;
for ( V_235 = 0 ; V_235 < 2 ; V_235 ++ )
V_249 |= F_116 ( V_7 , V_19 , V_235 , V_217 ,
V_213 , V_61 , V_23 ) ;
return V_249 ;
}
void F_118 ( struct V_6 * V_7 )
{
struct V_178 * V_250 = V_7 -> V_169 . V_211 . V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_169 . V_211 . V_53 ; V_12 ++ , V_250 ++ ) {
T_1 V_212 = V_250 -> V_218 . V_212 ;
T_2 V_19 ;
unsigned int V_213 , V_225 , V_235 ;
if ( ! V_212 )
continue;
V_19 = V_212 & 0xff ;
V_213 = ( V_212 >> 16 ) & 0xff ;
V_225 = ( V_212 >> 24 ) & 0xff ;
for ( V_235 = 0 ; V_235 < 2 ; V_235 ++ ) {
if ( ! ( V_250 -> V_218 . V_23 & F_113 ( V_235 ) ) )
continue;
F_114 ( V_7 , V_250 , V_19 , V_235 , V_225 , V_213 ,
V_250 -> V_237 [ V_235 ] ) ;
}
}
}
static T_1 F_119 ( struct V_6 * V_7 , T_2 V_19 , int V_225 ,
unsigned int V_251 )
{
T_1 V_226 = F_103 ( V_7 , V_19 , V_225 ) ;
V_226 = ( V_226 & V_252 ) >> V_253 ;
if ( V_251 < V_226 )
V_226 -= V_251 ;
return V_226 ;
}
int F_120 ( struct V_254 * V_255 ,
struct V_256 * V_257 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
T_3 V_19 = F_122 ( V_255 ) ;
T_4 V_258 = F_123 ( V_255 ) ;
int V_225 = F_124 ( V_255 ) ;
unsigned int V_251 = F_125 ( V_255 ) ;
V_257 -> type = V_259 ;
V_257 -> V_260 = V_258 == 3 ? 2 : 1 ;
V_257 -> V_261 . integer . V_262 = 0 ;
V_257 -> V_261 . integer . V_263 = F_119 ( V_7 , V_19 , V_225 , V_251 ) ;
if ( ! V_257 -> V_261 . integer . V_263 ) {
F_13 ( V_67 L_39
L_63 , V_19 ,
V_255 -> V_120 . V_127 ) ;
return - V_64 ;
}
return 0 ;
}
static inline unsigned int
F_126 ( struct V_6 * V_7 , T_2 V_19 ,
int V_235 , int V_225 , int V_213 , unsigned int V_251 )
{
unsigned int V_23 ;
V_23 = F_115 ( V_7 , V_19 , V_235 , V_225 , V_213 ) ;
V_23 &= V_264 ;
if ( V_23 >= V_251 )
V_23 -= V_251 ;
else
V_23 = 0 ;
return V_23 ;
}
static inline int
F_127 ( struct V_6 * V_7 , T_2 V_19 ,
int V_235 , int V_225 , int V_213 , unsigned int V_251 ,
unsigned int V_23 )
{
unsigned int V_265 ;
if ( V_23 > 0 )
V_23 += V_251 ;
V_265 = F_119 ( V_7 , V_19 , V_225 , 0 ) ;
if ( V_23 > V_265 )
V_23 = V_265 ;
return F_116 ( V_7 , V_19 , V_235 , V_225 , V_213 ,
V_264 , V_23 ) ;
}
int F_128 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
T_2 V_19 = F_122 ( V_255 ) ;
int V_258 = F_123 ( V_255 ) ;
int V_225 = F_124 ( V_255 ) ;
int V_213 = F_129 ( V_255 ) ;
unsigned int V_251 = F_125 ( V_255 ) ;
long * V_268 = V_267 -> V_261 . integer . V_261 ;
if ( V_258 & 1 )
* V_268 ++ = F_126 ( V_7 , V_19 , 0 , V_225 , V_213 , V_251 ) ;
if ( V_258 & 2 )
* V_268 = F_126 ( V_7 , V_19 , 1 , V_225 , V_213 , V_251 ) ;
return 0 ;
}
int F_130 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
T_2 V_19 = F_122 ( V_255 ) ;
int V_258 = F_123 ( V_255 ) ;
int V_225 = F_124 ( V_255 ) ;
int V_213 = F_129 ( V_255 ) ;
unsigned int V_251 = F_125 ( V_255 ) ;
long * V_268 = V_267 -> V_261 . integer . V_261 ;
int V_269 = 0 ;
F_15 ( V_7 ) ;
if ( V_258 & 1 ) {
V_269 = F_127 ( V_7 , V_19 , 0 , V_225 , V_213 , V_251 , * V_268 ) ;
V_268 ++ ;
}
if ( V_258 & 2 )
V_269 |= F_127 ( V_7 , V_19 , 1 , V_225 , V_213 , V_251 , * V_268 ) ;
F_16 ( V_7 ) ;
return V_269 ;
}
int F_131 ( struct V_254 * V_255 , int V_270 ,
unsigned int V_271 , unsigned int T_5 * V_272 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
T_2 V_19 = F_122 ( V_255 ) ;
int V_225 = F_124 ( V_255 ) ;
unsigned int V_251 = F_125 ( V_255 ) ;
bool V_273 = F_132 ( V_255 ) ;
T_1 V_226 , V_274 , V_275 ;
if ( V_271 < 4 * sizeof( unsigned int ) )
return - V_56 ;
V_226 = F_103 ( V_7 , V_19 , V_225 ) ;
V_275 = ( V_226 & V_276 ) >> V_277 ;
V_275 = ( V_275 + 1 ) * 25 ;
V_274 = - ( ( V_226 & V_278 ) >> V_279 ) ;
V_274 += V_251 ;
V_274 = ( ( int ) V_274 ) * ( ( int ) V_275 ) ;
if ( V_273 )
V_275 |= V_280 ;
if ( F_133 ( V_281 , V_272 ) )
return - V_282 ;
if ( F_133 ( 2 * sizeof( unsigned int ) , V_272 + 1 ) )
return - V_282 ;
if ( F_133 ( V_274 , V_272 + 2 ) )
return - V_282 ;
if ( F_133 ( V_275 , V_272 + 3 ) )
return - V_282 ;
return 0 ;
}
void F_134 ( struct V_6 * V_7 , T_2 V_19 , int V_225 ,
unsigned int * V_283 )
{
T_1 V_226 ;
int V_284 , V_285 ;
V_226 = F_103 ( V_7 , V_19 , V_225 ) ;
V_284 = ( V_226 & V_252 ) >> V_253 ;
V_285 = ( V_226 & V_276 ) >> V_277 ;
V_285 = ( V_285 + 1 ) * 25 ;
V_283 [ 0 ] = V_281 ;
V_283 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_283 [ 2 ] = - V_284 * V_285 ;
V_283 [ 3 ] = V_285 ;
}
static struct V_254 *
F_135 ( struct V_6 * V_7 ,
const char * V_127 , int V_213 )
{
struct V_286 V_120 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_287 = V_288 ;
V_120 . V_236 = V_213 ;
if ( F_28 ( strlen ( V_127 ) >= sizeof( V_120 . V_127 ) ) )
return NULL ;
strcpy ( V_120 . V_127 , V_127 ) ;
return F_136 ( V_7 -> V_29 -> V_99 , & V_120 ) ;
}
struct V_254 * F_137 ( struct V_6 * V_7 ,
const char * V_127 )
{
return F_135 ( V_7 , V_127 , 0 ) ;
}
static int F_138 ( struct V_6 * V_7 , const char * V_127 )
{
int V_213 ;
for ( V_213 = 0 ; V_213 < 16 ; V_213 ++ ) {
if ( ! F_135 ( V_7 , V_127 , V_213 ) )
return V_213 ;
}
return - V_175 ;
}
int F_139 ( struct V_6 * V_7 , T_2 V_19 ,
struct V_254 * V_289 )
{
int V_30 ;
unsigned short V_290 = 0 ;
struct V_180 * V_291 ;
if ( V_289 -> V_120 . V_292 & V_293 ) {
V_290 |= V_294 ;
if ( V_19 == 0 )
V_19 = F_140 ( V_289 -> V_295 ) ;
}
if ( ( V_289 -> V_120 . V_292 & V_296 ) != 0 && V_19 == 0 )
V_19 = V_289 -> V_120 . V_292 & 0xffff ;
if ( V_289 -> V_120 . V_292 & ( V_296 | V_293 ) )
V_289 -> V_120 . V_292 = 0 ;
V_30 = F_141 ( V_7 -> V_29 -> V_99 , V_289 ) ;
if ( V_30 < 0 )
return V_30 ;
V_291 = F_32 ( & V_7 -> V_167 ) ;
if ( ! V_291 )
return - V_56 ;
V_291 -> V_289 = V_289 ;
V_291 -> V_19 = V_19 ;
V_291 -> V_290 = V_290 ;
return 0 ;
}
int F_142 ( struct V_6 * V_7 , struct V_254 * V_289 ,
unsigned int V_236 , T_2 V_19 )
{
struct V_180 * V_291 ;
if ( V_19 > 0 ) {
V_291 = F_32 ( & V_7 -> V_168 ) ;
if ( ! V_291 )
return - V_56 ;
V_291 -> V_289 = V_289 ;
V_291 -> V_236 = V_236 ;
V_291 -> V_19 = V_19 ;
return 0 ;
}
F_13 ( V_25 L_64 ,
V_289 -> V_120 . V_127 , V_289 -> V_120 . V_236 , V_236 ) ;
return - V_64 ;
}
void F_143 ( struct V_6 * V_7 )
{
int V_12 ;
struct V_180 * V_297 = V_7 -> V_167 . V_4 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_167 . V_53 ; V_12 ++ )
F_144 ( V_7 -> V_29 -> V_99 , V_297 [ V_12 ] . V_289 ) ;
F_77 ( & V_7 -> V_167 ) ;
F_77 ( & V_7 -> V_168 ) ;
}
static int F_145 ( struct V_98 * V_99 )
{
F_146 ( & V_99 -> V_298 ) ;
if ( V_99 -> V_97 ) {
F_147 ( & V_99 -> V_298 ) ;
return - V_64 ;
}
V_99 -> V_97 = 1 ;
F_147 ( & V_99 -> V_298 ) ;
return 0 ;
}
static void F_148 ( struct V_98 * V_99 )
{
F_146 ( & V_99 -> V_298 ) ;
V_99 -> V_97 = 0 ;
F_147 ( & V_99 -> V_298 ) ;
}
int F_149 ( struct V_6 * V_7 )
{
struct V_98 * V_99 = V_7 -> V_29 -> V_99 ;
int V_12 , V_299 ;
if ( F_145 ( V_99 ) < 0 )
return - V_175 ;
if ( ! F_150 ( & V_99 -> V_300 ) ) {
F_148 ( V_99 ) ;
return - V_175 ;
}
for ( V_299 = 0 ; V_299 < V_7 -> V_301 ; V_299 ++ ) {
struct V_302 * V_303 = & V_7 -> V_304 [ V_299 ] ;
if ( ! V_303 -> V_299 )
continue;
if ( V_303 -> V_299 -> V_305 [ 0 ] . V_306 ||
V_303 -> V_299 -> V_305 [ 1 ] . V_306 ) {
F_148 ( V_99 ) ;
return - V_175 ;
}
}
#ifdef F_79
F_80 ( & V_7 -> V_166 ) ;
F_41 ( V_7 -> V_29 -> V_84 ) ;
#endif
F_143 ( V_7 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_301 ; V_12 ++ ) {
if ( V_7 -> V_304 [ V_12 ] . V_299 ) {
F_151 ( V_99 , V_7 -> V_304 [ V_12 ] . V_299 ) ;
F_152 ( V_7 -> V_304 [ V_12 ] . V_95 ,
V_7 -> V_29 -> V_307 ) ;
}
}
if ( V_7 -> V_90 . free )
V_7 -> V_90 . free ( V_7 ) ;
V_7 -> V_308 = NULL ;
V_7 -> V_309 = NULL ;
F_81 ( & V_7 -> V_169 ) ;
F_81 ( & V_7 -> V_170 ) ;
F_83 ( & V_7 -> V_169 , sizeof( struct V_178 ) ) ;
F_83 ( & V_7 -> V_170 , sizeof( struct V_179 ) ) ;
F_77 ( & V_7 -> V_160 ) ;
F_73 ( V_7 ) ;
V_7 -> V_301 = 0 ;
V_7 -> V_304 = NULL ;
V_7 -> V_2 = NULL ;
memset ( & V_7 -> V_90 , 0 , sizeof( V_7 -> V_90 ) ) ;
V_7 -> V_310 = NULL ;
V_7 -> V_311 = 0 ;
F_59 ( V_7 -> V_119 ) ;
V_7 -> V_119 = NULL ;
F_148 ( V_99 ) ;
return 0 ;
}
int F_153 ( struct V_6 * V_7 , char * V_127 ,
unsigned int * V_283 , const char * const * V_312 )
{
struct V_254 * V_289 ;
const char * const * V_313 ;
int V_30 ;
for ( V_313 = V_312 ; * V_313 && ! F_137 ( V_7 , * V_313 ) ; V_313 ++ )
;
if ( ! * V_313 ) {
F_86 ( L_65 , V_127 ) ;
return 0 ;
}
V_289 = F_154 ( V_127 , V_283 ) ;
if ( ! V_289 )
return - V_56 ;
V_30 = F_139 ( V_7 , 0 , V_289 ) ;
if ( V_30 < 0 )
return V_30 ;
for ( V_313 = V_312 ; * V_313 ; V_313 ++ ) {
struct V_254 * V_314 ;
int V_12 = 0 ;
for (; ; ) {
V_314 = F_135 ( V_7 , * V_313 , V_12 ) ;
if ( ! V_314 ) {
if ( ! V_12 )
F_86 ( L_66
L_67 , * V_313 ) ;
break;
}
V_30 = F_155 ( V_289 , V_314 ) ;
if ( V_30 < 0 )
return V_30 ;
V_12 ++ ;
}
}
return 0 ;
}
int F_156 ( struct V_254 * V_255 ,
struct V_256 * V_257 )
{
int V_258 = F_123 ( V_255 ) ;
V_257 -> type = V_315 ;
V_257 -> V_260 = V_258 == 3 ? 2 : 1 ;
V_257 -> V_261 . integer . V_262 = 0 ;
V_257 -> V_261 . integer . V_263 = 1 ;
return 0 ;
}
int F_157 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
T_2 V_19 = F_122 ( V_255 ) ;
int V_258 = F_123 ( V_255 ) ;
int V_225 = F_124 ( V_255 ) ;
int V_213 = F_129 ( V_255 ) ;
long * V_268 = V_267 -> V_261 . integer . V_261 ;
if ( V_258 & 1 )
* V_268 ++ = ( F_115 ( V_7 , V_19 , 0 , V_225 , V_213 ) &
V_316 ) ? 0 : 1 ;
if ( V_258 & 2 )
* V_268 = ( F_115 ( V_7 , V_19 , 1 , V_225 , V_213 ) &
V_316 ) ? 0 : 1 ;
return 0 ;
}
int F_158 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
T_2 V_19 = F_122 ( V_255 ) ;
int V_258 = F_123 ( V_255 ) ;
int V_225 = F_124 ( V_255 ) ;
int V_213 = F_129 ( V_255 ) ;
long * V_268 = V_267 -> V_261 . integer . V_261 ;
int V_269 = 0 ;
F_15 ( V_7 ) ;
if ( V_258 & 1 ) {
V_269 = F_116 ( V_7 , V_19 , 0 , V_225 , V_213 ,
V_316 ,
* V_268 ? 0 : V_316 ) ;
V_268 ++ ;
}
if ( V_258 & 2 )
V_269 |= F_116 ( V_7 , V_19 , 1 , V_225 , V_213 ,
V_316 ,
* V_268 ? 0 : V_316 ) ;
F_159 ( V_7 , V_19 ) ;
F_16 ( V_7 ) ;
return V_269 ;
}
int F_160 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
long * V_268 = V_267 -> V_261 . integer . V_261 ;
F_161 ( V_7 , * V_268 ) ;
return F_158 ( V_255 , V_267 ) ;
}
int F_162 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
unsigned long V_317 ;
int V_30 ;
F_2 ( & V_7 -> V_177 ) ;
V_317 = V_255 -> V_295 ;
V_255 -> V_295 = V_317 & ~ V_318 ;
V_30 = F_157 ( V_255 , V_267 ) ;
V_255 -> V_295 = V_317 ;
F_4 ( & V_7 -> V_177 ) ;
return V_30 ;
}
int F_163 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
unsigned long V_317 ;
int V_12 , V_319 , V_30 = 0 , V_269 = 0 ;
F_2 ( & V_7 -> V_177 ) ;
V_317 = V_255 -> V_295 ;
V_319 = ( V_317 & V_318 ) >> V_320 ;
for ( V_12 = 0 ; V_12 < V_319 ; V_12 ++ ) {
V_255 -> V_295 = ( V_317 & ~ V_318 ) |
( V_12 << V_320 ) ;
V_30 = F_158 ( V_255 , V_267 ) ;
if ( V_30 < 0 )
break;
V_269 |= V_30 ;
}
V_255 -> V_295 = V_317 ;
F_4 ( & V_7 -> V_177 ) ;
return V_30 < 0 ? V_30 : V_269 ;
}
int F_164 ( struct V_254 * V_255 ,
struct V_256 * V_257 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
struct V_321 * V_129 ;
int V_30 ;
F_2 ( & V_7 -> V_177 ) ;
V_129 = (struct V_321 * ) V_255 -> V_295 ;
V_255 -> V_295 = * V_129 -> V_322 ;
V_30 = V_129 -> V_33 -> V_215 ( V_255 , V_257 ) ;
V_255 -> V_295 = ( long ) V_129 ;
F_4 ( & V_7 -> V_177 ) ;
return V_30 ;
}
int F_165 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
struct V_321 * V_129 ;
int V_30 ;
F_2 ( & V_7 -> V_177 ) ;
V_129 = (struct V_321 * ) V_255 -> V_295 ;
V_255 -> V_295 = * V_129 -> V_322 ;
V_30 = V_129 -> V_33 -> V_323 ( V_255 , V_267 ) ;
V_255 -> V_295 = ( long ) V_129 ;
F_4 ( & V_7 -> V_177 ) ;
return V_30 ;
}
int F_166 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
struct V_321 * V_129 ;
unsigned long * V_324 ;
int V_30 = 0 , V_269 = 0 ;
F_2 ( & V_7 -> V_177 ) ;
V_129 = (struct V_321 * ) V_255 -> V_295 ;
for ( V_324 = V_129 -> V_322 ; * V_324 ; V_324 ++ ) {
V_255 -> V_295 = * V_324 ;
V_30 = V_129 -> V_33 -> V_325 ( V_255 , V_267 ) ;
if ( V_30 < 0 )
break;
V_269 |= V_30 ;
}
V_255 -> V_295 = ( long ) V_129 ;
F_4 ( & V_7 -> V_177 ) ;
return V_30 < 0 ? V_30 : V_269 ;
}
int F_167 ( struct V_254 * V_255 , int V_270 ,
unsigned int V_271 , unsigned int T_5 * V_283 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
struct V_321 * V_129 ;
int V_30 ;
F_2 ( & V_7 -> V_177 ) ;
V_129 = (struct V_321 * ) V_255 -> V_295 ;
V_255 -> V_295 = * V_129 -> V_322 ;
V_30 = V_129 -> V_33 -> V_283 ( V_255 , V_270 , V_271 , V_283 ) ;
V_255 -> V_295 = ( long ) V_129 ;
F_4 ( & V_7 -> V_177 ) ;
return V_30 ;
}
static int F_168 ( struct V_254 * V_255 ,
struct V_256 * V_257 )
{
V_257 -> type = V_326 ;
V_257 -> V_260 = 1 ;
return 0 ;
}
static int F_169 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
V_267 -> V_261 . V_327 . V_328 [ 0 ] = V_329 |
V_330 |
V_331 |
V_332 ;
V_267 -> V_261 . V_327 . V_328 [ 1 ] = V_333 |
V_334 ;
return 0 ;
}
static int F_170 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
V_267 -> V_261 . V_327 . V_328 [ 0 ] = V_329 |
V_330 |
V_335 ;
return 0 ;
}
static int F_171 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
V_267 -> V_261 . V_327 . V_328 [ 0 ] = V_7 -> V_336 & 0xff ;
V_267 -> V_261 . V_327 . V_328 [ 1 ] = ( V_7 -> V_336 >> 8 ) & 0xff ;
V_267 -> V_261 . V_327 . V_328 [ 2 ] = ( V_7 -> V_336 >> 16 ) & 0xff ;
V_267 -> V_261 . V_327 . V_328 [ 3 ] = ( V_7 -> V_336 >> 24 ) & 0xff ;
return 0 ;
}
static unsigned short F_172 ( unsigned int V_337 )
{
unsigned short V_23 = 0 ;
if ( V_337 & V_329 )
V_23 |= V_338 ;
if ( V_337 & V_330 )
V_23 |= V_339 ;
if ( V_337 & V_329 ) {
if ( ( V_337 & V_340 ) ==
V_335 )
V_23 |= V_341 ;
} else {
if ( ( V_337 & V_342 ) ==
V_331 )
V_23 |= V_341 ;
if ( ! ( V_337 & V_332 ) )
V_23 |= V_343 ;
if ( V_337 & ( V_334 << 8 ) )
V_23 |= V_344 ;
V_23 |= V_337 & ( V_333 << 8 ) ;
}
return V_23 ;
}
static unsigned int F_173 ( unsigned short V_23 )
{
unsigned int V_337 = 0 ;
if ( V_23 & V_339 )
V_337 |= V_330 ;
if ( V_23 & V_338 )
V_337 |= V_329 ;
if ( V_337 & V_329 ) {
if ( V_337 & V_341 )
V_337 |= V_335 ;
} else {
if ( V_23 & V_341 )
V_337 |= V_331 ;
if ( ! ( V_23 & V_343 ) )
V_337 |= V_332 ;
if ( V_23 & V_344 )
V_337 |= ( V_334 << 8 ) ;
V_337 |= V_23 & ( 0x7f << 8 ) ;
}
return V_337 ;
}
static void F_174 ( struct V_6 * V_7 , T_2 V_19 ,
int V_21 , int V_23 )
{
const T_2 * V_345 ;
F_175 ( V_7 , V_19 , 0 , V_21 , V_23 ) ;
V_345 = V_7 -> V_310 ;
if ( ! V_345 )
return;
for (; * V_345 ; V_345 ++ )
F_175 ( V_7 , * V_345 , 0 , V_21 , V_23 ) ;
}
static inline void F_176 ( struct V_6 * V_7 , T_2 V_19 ,
int V_346 , int V_347 )
{
if ( V_346 != - 1 )
F_174 ( V_7 , V_19 , V_348 , V_346 ) ;
if ( V_347 != - 1 )
F_174 ( V_7 , V_19 , V_349 , V_347 ) ;
}
static int F_177 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
T_2 V_19 = V_255 -> V_295 ;
unsigned short V_23 ;
int V_269 ;
F_2 ( & V_7 -> V_176 ) ;
V_7 -> V_336 = V_267 -> V_261 . V_327 . V_328 [ 0 ] |
( ( unsigned int ) V_267 -> V_261 . V_327 . V_328 [ 1 ] << 8 ) |
( ( unsigned int ) V_267 -> V_261 . V_327 . V_328 [ 2 ] << 16 ) |
( ( unsigned int ) V_267 -> V_261 . V_327 . V_328 [ 3 ] << 24 ) ;
V_23 = F_172 ( V_7 -> V_336 ) ;
V_23 |= V_7 -> V_350 & 1 ;
V_269 = V_7 -> V_350 != V_23 ;
V_7 -> V_350 = V_23 ;
if ( V_269 )
F_176 ( V_7 , V_19 , V_23 & 0xff , ( V_23 >> 8 ) & 0xff ) ;
F_4 ( & V_7 -> V_176 ) ;
return V_269 ;
}
static int F_178 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
V_267 -> V_261 . integer . V_261 [ 0 ] = V_7 -> V_350 & V_351 ;
return 0 ;
}
static int F_179 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
T_2 V_19 = V_255 -> V_295 ;
unsigned short V_23 ;
int V_269 ;
F_2 ( & V_7 -> V_176 ) ;
V_23 = V_7 -> V_350 & ~ V_351 ;
if ( V_267 -> V_261 . integer . V_261 [ 0 ] )
V_23 |= V_351 ;
V_269 = V_7 -> V_350 != V_23 ;
if ( V_269 ) {
V_7 -> V_350 = V_23 ;
F_176 ( V_7 , V_19 , V_23 & 0xff , - 1 ) ;
if ( ( F_29 ( V_7 , V_19 ) & V_352 ) &&
( V_23 & V_351 ) )
F_117 ( V_7 , V_19 , V_222 , 0 ,
V_316 , 0 ) ;
}
F_4 ( & V_7 -> V_176 ) ;
return V_269 ;
}
int F_180 ( struct V_6 * V_7 , T_2 V_19 )
{
int V_30 ;
struct V_254 * V_289 ;
struct V_353 * V_354 ;
int V_213 ;
V_213 = F_138 ( V_7 , L_68 ) ;
if ( V_213 < 0 ) {
F_13 ( V_25 L_69 ) ;
return - V_175 ;
}
for ( V_354 = V_355 ; V_354 -> V_127 ; V_354 ++ ) {
V_289 = F_181 ( V_354 , V_7 ) ;
if ( ! V_289 )
return - V_56 ;
V_289 -> V_120 . V_236 = V_213 ;
V_289 -> V_295 = V_19 ;
V_30 = F_139 ( V_7 , V_19 , V_289 ) ;
if ( V_30 < 0 )
return V_30 ;
}
V_7 -> V_350 =
F_18 ( V_7 , V_19 , 0 ,
V_356 , 0 ) ;
V_7 -> V_336 = F_173 ( V_7 -> V_350 ) ;
return 0 ;
}
static int F_182 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_357 * V_358 = F_121 ( V_255 ) ;
V_267 -> V_261 . integer . V_261 [ 0 ] = V_358 -> V_359 ;
return 0 ;
}
static int F_183 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_357 * V_358 = F_121 ( V_255 ) ;
V_358 -> V_359 = ! ! V_267 -> V_261 . integer . V_261 [ 0 ] ;
return 0 ;
}
int F_184 ( struct V_6 * V_7 ,
struct V_357 * V_358 )
{
if ( ! V_358 -> V_360 )
return 0 ;
return F_139 ( V_7 , V_358 -> V_360 ,
F_181 ( & V_361 , V_358 ) ) ;
}
static int F_185 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
V_267 -> V_261 . integer . V_261 [ 0 ] = V_7 -> V_362 ;
return 0 ;
}
static int F_186 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
T_2 V_19 = V_255 -> V_295 ;
unsigned int V_23 = ! ! V_267 -> V_261 . integer . V_261 [ 0 ] ;
int V_269 ;
F_2 ( & V_7 -> V_176 ) ;
V_269 = V_7 -> V_362 != V_23 ;
if ( V_269 ) {
V_7 -> V_362 = V_23 ;
F_175 ( V_7 , V_19 , 0 ,
V_348 , V_23 ) ;
}
F_4 ( & V_7 -> V_176 ) ;
return V_269 ;
}
static int F_187 ( struct V_254 * V_255 ,
struct V_266 * V_267 )
{
struct V_6 * V_7 = F_121 ( V_255 ) ;
T_2 V_19 = V_255 -> V_295 ;
unsigned short V_23 ;
unsigned int V_337 ;
V_23 = F_18 ( V_7 , V_19 , 0 , V_356 , 0 ) ;
V_337 = F_173 ( V_23 ) ;
V_267 -> V_261 . V_327 . V_328 [ 0 ] = V_337 ;
V_267 -> V_261 . V_327 . V_328 [ 1 ] = V_337 >> 8 ;
V_267 -> V_261 . V_327 . V_328 [ 2 ] = V_337 >> 16 ;
V_267 -> V_261 . V_327 . V_328 [ 3 ] = V_337 >> 24 ;
return 0 ;
}
int F_188 ( struct V_6 * V_7 , T_2 V_19 )
{
int V_30 ;
struct V_254 * V_289 ;
struct V_353 * V_354 ;
int V_213 ;
V_213 = F_138 ( V_7 , L_70 ) ;
if ( V_213 < 0 ) {
F_13 ( V_25 L_71 ) ;
return - V_175 ;
}
for ( V_354 = V_363 ; V_354 -> V_127 ; V_354 ++ ) {
V_289 = F_181 ( V_354 , V_7 ) ;
if ( ! V_289 )
return - V_56 ;
V_289 -> V_295 = V_19 ;
V_30 = F_139 ( V_7 , V_19 , V_289 ) ;
if ( V_30 < 0 )
return V_30 ;
}
V_7 -> V_362 =
F_18 ( V_7 , V_19 , 0 ,
V_356 , 0 ) &
V_351 ;
return 0 ;
}
int F_175 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 , unsigned int V_21 , unsigned int V_22 )
{
int V_30 = F_19 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
struct V_179 * V_129 ;
T_1 V_212 ;
if ( V_30 < 0 )
return V_30 ;
V_21 = V_21 | ( V_22 >> 8 ) ;
V_22 &= 0xff ;
V_212 = F_189 ( V_19 , V_21 ) ;
F_2 ( & V_7 -> V_29 -> V_32 ) ;
V_129 = F_100 ( & V_7 -> V_170 , V_212 ) ;
if ( V_129 )
V_129 -> V_23 = V_22 ;
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return 0 ;
}
int F_190 ( struct V_6 * V_7 , T_2 V_19 ,
int V_20 , unsigned int V_21 , unsigned int V_22 )
{
struct V_179 * V_129 ;
T_1 V_212 ;
V_21 = V_21 | ( V_22 >> 8 ) ;
V_22 &= 0xff ;
V_212 = F_189 ( V_19 , V_21 ) ;
F_2 ( & V_7 -> V_29 -> V_32 ) ;
V_129 = F_99 ( & V_7 -> V_170 , V_212 ) ;
if ( V_129 && V_129 -> V_23 == V_22 ) {
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return 0 ;
}
F_4 ( & V_7 -> V_29 -> V_32 ) ;
return F_175 ( V_7 , V_19 , V_20 , V_21 , V_22 ) ;
}
void F_191 ( struct V_6 * V_7 )
{
struct V_179 * V_250 = V_7 -> V_170 . V_211 . V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_170 . V_211 . V_53 ; V_12 ++ , V_250 ++ ) {
T_1 V_212 = V_250 -> V_212 ;
if ( ! V_212 )
continue;
F_19 ( V_7 , F_192 ( V_212 ) , 0 ,
F_193 ( V_212 ) , V_250 -> V_23 ) ;
}
}
void F_194 ( struct V_6 * V_7 ,
const struct V_40 * V_41 )
{
for (; V_41 -> V_19 ; V_41 ++ )
F_175 ( V_7 , V_41 -> V_19 , 0 , V_41 -> V_21 ,
V_41 -> V_42 ) ;
}
static void F_87 ( struct V_6 * V_7 , T_2 V_364 ,
unsigned int V_365 )
{
T_2 V_19 ;
int V_12 ;
if ( V_365 == V_366 )
F_94 ( 100 ) ;
F_18 ( V_7 , V_364 , 0 , V_367 ,
V_365 ) ;
if ( V_365 == V_188 &&
( V_7 -> V_123 & 0xffff0000 ) == 0x14f10000 )
F_94 ( 10 ) ;
V_19 = V_7 -> V_148 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_147 ; V_12 ++ , V_19 ++ ) {
unsigned int V_62 = F_29 ( V_7 , V_19 ) ;
if ( V_62 & V_368 ) {
unsigned int V_152 = F_30 ( V_62 ) ;
if ( V_365 == V_366 &&
V_152 == V_153 ) {
unsigned int V_228 ;
V_228 = F_107 ( V_7 , V_19 ) ;
if ( V_228 & V_369 ) {
int V_370 = F_18 ( V_7 ,
V_19 , 0 ,
V_371 , 0 ) ;
V_370 &= 0x02 ;
if ( V_370 )
continue;
}
}
F_19 ( V_7 , V_19 , 0 ,
V_367 ,
V_365 ) ;
}
}
if ( V_365 == V_188 ) {
unsigned long V_372 ;
int V_373 ;
V_372 = V_374 + F_195 ( 500 ) ;
do {
V_373 = F_18 ( V_7 , V_364 , 0 ,
V_375 , 0 ) ;
if ( V_373 == V_365 )
break;
F_94 ( 1 ) ;
} while ( F_196 ( V_372 , V_374 ) );
}
}
static void F_197 ( struct V_6 * V_7 )
{
if ( V_7 -> V_376 . V_4 )
F_20 ( V_7 , V_7 -> V_376 . V_4 ) ;
}
static inline void F_197 ( struct V_6 * V_7 ) {}
static void F_198 ( struct V_6 * V_7 )
{
if ( V_7 -> V_90 . V_377 )
V_7 -> V_90 . V_377 ( V_7 , V_378 ) ;
F_98 ( V_7 ) ;
F_87 ( V_7 ,
V_7 -> V_121 ? V_7 -> V_121 : V_7 -> V_122 ,
V_366 ) ;
#ifdef F_79
F_199 ( V_7 ) ;
F_80 ( & V_7 -> V_166 ) ;
V_7 -> V_379 = 0 ;
V_7 -> V_380 = 0 ;
V_7 -> V_381 = V_374 ;
#endif
}
static void F_200 ( struct V_6 * V_7 )
{
F_87 ( V_7 ,
V_7 -> V_121 ? V_7 -> V_121 : V_7 -> V_122 ,
V_188 ) ;
F_73 ( V_7 ) ;
F_75 ( V_7 ) ;
F_197 ( V_7 ) ;
if ( V_7 -> V_90 . V_382 )
V_7 -> V_90 . V_382 ( V_7 ) ;
else {
if ( V_7 -> V_90 . V_383 )
V_7 -> V_90 . V_383 ( V_7 ) ;
F_118 ( V_7 ) ;
F_191 ( V_7 ) ;
}
}
int F_201 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_48 (codec, &bus->codec_list, list) {
int V_30 = F_202 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_72
L_73 , V_7 -> V_24 , V_30 ) ;
V_30 = F_149 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25
L_74 ) ;
return V_30 ;
}
}
}
return 0 ;
}
int F_202 ( struct V_6 * V_7 )
{
int V_30 = 0 ;
F_197 ( V_7 ) ;
if ( V_7 -> V_90 . V_383 )
V_30 = V_7 -> V_90 . V_383 ( V_7 ) ;
if ( ! V_30 && V_7 -> V_90 . V_384 )
V_30 = V_7 -> V_90 . V_384 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
unsigned int F_203 ( unsigned int V_385 ,
unsigned int V_386 ,
unsigned int V_194 ,
unsigned int V_387 ,
unsigned short V_350 )
{
int V_12 ;
unsigned int V_23 = 0 ;
for ( V_12 = 0 ; V_388 [ V_12 ] . V_389 ; V_12 ++ )
if ( V_388 [ V_12 ] . V_389 == V_385 ) {
V_23 = V_388 [ V_12 ] . V_390 ;
break;
}
if ( ! V_388 [ V_12 ] . V_389 ) {
F_86 ( L_75 , V_385 ) ;
return 0 ;
}
if ( V_386 == 0 || V_386 > 8 ) {
F_86 ( L_76 , V_386 ) ;
return 0 ;
}
V_23 |= V_386 - 1 ;
switch ( F_204 ( V_194 ) ) {
case 8 :
V_23 |= V_391 ;
break;
case 16 :
V_23 |= V_392 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_387 >= 32 || V_194 == V_393 )
V_23 |= V_394 ;
else if ( V_387 >= 24 )
V_23 |= V_395 ;
else
V_23 |= V_396 ;
break;
default:
F_86 ( L_77 ,
F_204 ( V_194 ) ) ;
return 0 ;
}
if ( V_350 & V_339 )
V_23 |= V_397 ;
return V_23 ;
}
static unsigned int F_205 ( struct V_6 * V_7 , T_2 V_19 )
{
unsigned int V_23 = 0 ;
if ( V_19 != V_7 -> V_121 &&
( F_29 ( V_7 , V_19 ) & V_398 ) )
V_23 = F_22 ( V_7 , V_19 , V_399 ) ;
if ( ! V_23 || V_23 == - 1 )
V_23 = F_22 ( V_7 , V_7 -> V_121 , V_399 ) ;
if ( ! V_23 || V_23 == - 1 )
return 0 ;
return V_23 ;
}
static unsigned int F_206 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_108 ( V_7 , V_19 , F_207 ( V_19 ) ,
F_205 ) ;
}
static unsigned int F_208 ( struct V_6 * V_7 , T_2 V_19 )
{
unsigned int V_305 = F_22 ( V_7 , V_19 , V_400 ) ;
if ( ! V_305 || V_305 == - 1 )
V_305 = F_22 ( V_7 , V_7 -> V_121 , V_400 ) ;
if ( ! V_305 || V_305 == - 1 )
return 0 ;
return V_305 ;
}
static unsigned int F_209 ( struct V_6 * V_7 , T_2 V_19 )
{
return F_108 ( V_7 , V_19 , F_210 ( V_19 ) ,
F_208 ) ;
}
static int F_211 ( struct V_6 * V_7 , T_2 V_19 ,
T_1 * V_401 , T_6 * V_402 , unsigned int * V_403 )
{
unsigned int V_12 , V_23 , V_62 ;
V_62 = F_29 ( V_7 , V_19 ) ;
V_23 = F_206 ( V_7 , V_19 ) ;
if ( V_401 ) {
T_1 V_404 = 0 ;
for ( V_12 = 0 ; V_12 < V_405 ; V_12 ++ ) {
if ( V_23 & ( 1 << V_12 ) )
V_404 |= V_388 [ V_12 ] . V_406 ;
}
if ( V_404 == 0 ) {
F_31 ( V_25 L_78
L_79 ,
V_19 , V_23 ,
( V_62 & V_398 ) ? 1 : 0 ) ;
return - V_72 ;
}
* V_401 = V_404 ;
}
if ( V_402 || V_403 ) {
T_6 V_407 = 0 ;
unsigned int V_305 , V_408 ;
V_305 = F_209 ( V_7 , V_19 ) ;
if ( ! V_305 )
return - V_72 ;
V_408 = 0 ;
if ( V_305 & V_409 ) {
if ( V_23 & V_410 ) {
V_407 |= V_411 ;
V_408 = 8 ;
}
if ( V_23 & V_412 ) {
V_407 |= V_413 ;
V_408 = 16 ;
}
if ( V_62 & V_414 ) {
if ( V_23 & V_415 )
V_407 |= V_416 ;
if ( V_23 & ( V_417 | V_418 ) )
V_407 |= V_419 ;
if ( V_23 & V_418 )
V_408 = 24 ;
else if ( V_23 & V_417 )
V_408 = 20 ;
} else if ( V_23 & ( V_417 | V_418 |
V_415 ) ) {
V_407 |= V_419 ;
if ( V_23 & V_415 )
V_408 = 32 ;
else if ( V_23 & V_418 )
V_408 = 24 ;
else if ( V_23 & V_417 )
V_408 = 20 ;
}
}
if ( V_305 & V_420 ) {
V_407 |= V_421 ;
if ( ! V_408 )
V_408 = 32 ;
}
if ( V_305 == V_422 ) {
V_407 |= V_411 ;
V_408 = 8 ;
}
if ( V_407 == 0 ) {
F_31 ( V_25 L_80
L_81
L_82 ,
V_19 , V_23 ,
( V_62 & V_398 ) ? 1 : 0 ,
V_305 ) ;
return - V_72 ;
}
if ( V_402 )
* V_402 = V_407 ;
if ( V_403 )
* V_403 = V_408 ;
}
return 0 ;
}
int F_212 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_194 )
{
int V_12 ;
unsigned int V_23 = 0 , V_385 , V_423 ;
V_23 = F_206 ( V_7 , V_19 ) ;
if ( ! V_23 )
return 0 ;
V_385 = V_194 & 0xff00 ;
for ( V_12 = 0 ; V_12 < V_405 ; V_12 ++ )
if ( V_388 [ V_12 ] . V_390 == V_385 ) {
if ( V_23 & ( 1 << V_12 ) )
break;
return 0 ;
}
if ( V_12 >= V_405 )
return 0 ;
V_423 = F_209 ( V_7 , V_19 ) ;
if ( ! V_423 )
return 0 ;
if ( V_423 & V_409 ) {
switch ( V_194 & 0xf0 ) {
case 0x00 :
if ( ! ( V_23 & V_410 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_23 & V_412 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_23 & V_417 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_23 & V_418 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_23 & V_415 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_213 ( struct V_424 * V_425 ,
struct V_6 * V_7 ,
struct V_426 * V_427 )
{
return 0 ;
}
static int F_214 ( struct V_424 * V_425 ,
struct V_6 * V_7 ,
unsigned int V_192 ,
unsigned int V_194 ,
struct V_426 * V_427 )
{
F_93 ( V_7 , V_425 -> V_19 , V_192 , 0 , V_194 ) ;
return 0 ;
}
static int F_215 ( struct V_424 * V_425 ,
struct V_6 * V_7 ,
struct V_426 * V_427 )
{
F_216 ( V_7 , V_425 -> V_19 ) ;
return 0 ;
}
static int F_217 ( struct V_6 * V_7 ,
struct V_424 * V_215 )
{
int V_30 ;
if ( V_215 -> V_19 && ( ! V_215 -> V_404 || ! V_215 -> V_407 ) ) {
V_30 = F_211 ( V_7 , V_215 -> V_19 ,
V_215 -> V_404 ? NULL : & V_215 -> V_404 ,
V_215 -> V_407 ? NULL : & V_215 -> V_407 ,
V_215 -> V_387 ? NULL : & V_215 -> V_387 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( V_215 -> V_33 . V_428 == NULL )
V_215 -> V_33 . V_428 = F_213 ;
if ( V_215 -> V_33 . V_429 == NULL )
V_215 -> V_33 . V_429 = F_213 ;
if ( V_215 -> V_33 . V_430 == NULL ) {
if ( F_28 ( ! V_215 -> V_19 ) )
return - V_64 ;
V_215 -> V_33 . V_430 = F_214 ;
}
if ( V_215 -> V_33 . V_431 == NULL ) {
if ( F_28 ( ! V_215 -> V_19 ) )
return - V_64 ;
V_215 -> V_33 . V_431 = F_215 ;
}
return 0 ;
}
int F_218 ( struct V_6 * V_7 ,
struct V_424 * V_425 ,
unsigned int V_423 ,
unsigned int V_194 ,
struct V_426 * V_427 )
{
int V_249 ;
F_2 ( & V_7 -> V_29 -> V_111 ) ;
V_249 = V_425 -> V_33 . V_430 ( V_425 , V_7 , V_423 , V_194 , V_427 ) ;
if ( V_249 >= 0 )
F_97 ( V_7 ) ;
F_4 ( & V_7 -> V_29 -> V_111 ) ;
return V_249 ;
}
void F_219 ( struct V_6 * V_7 ,
struct V_424 * V_425 ,
struct V_426 * V_427 )
{
F_2 ( & V_7 -> V_29 -> V_111 ) ;
V_425 -> V_33 . V_431 ( V_425 , V_7 , V_427 ) ;
F_4 ( & V_7 -> V_29 -> V_111 ) ;
}
static int F_220 ( struct V_28 * V_29 , int type )
{
static int V_432 [ V_433 ] [ 5 ] = {
[ V_434 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_435 ] = { 1 , - 1 } ,
[ V_436 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_437 ] = { 6 , - 1 } ,
} ;
int V_12 ;
if ( type >= V_433 ) {
F_31 ( V_67 L_83 , type ) ;
return - V_64 ;
}
for ( V_12 = 0 ; V_432 [ type ] [ V_12 ] >= 0 ; V_12 ++ )
if ( ! F_221 ( V_432 [ type ] [ V_12 ] , V_29 -> V_307 ) )
return V_432 [ type ] [ V_12 ] ;
F_31 ( V_67 L_84 ,
V_438 [ type ] ) ;
return - V_439 ;
}
static int F_222 ( struct V_6 * V_7 , struct V_302 * V_299 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
struct V_424 * V_215 ;
int V_423 , V_30 ;
if ( F_28 ( ! V_299 -> V_127 ) )
return - V_64 ;
for ( V_423 = 0 ; V_423 < 2 ; V_423 ++ ) {
V_215 = & V_299 -> V_423 [ V_423 ] ;
if ( V_215 -> V_440 ) {
V_30 = F_217 ( V_7 , V_215 ) ;
if ( V_30 < 0 )
return V_30 ;
}
}
return V_29 -> V_33 . V_441 ( V_29 , V_7 , V_299 ) ;
}
int F_223 ( struct V_6 * V_7 )
{
unsigned int V_299 ;
int V_30 ;
if ( ! V_7 -> V_301 ) {
if ( ! V_7 -> V_90 . V_442 )
return 0 ;
V_30 = V_7 -> V_90 . V_442 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_85
L_73 , V_7 -> V_24 , V_30 ) ;
V_30 = F_149 ( V_7 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25
L_74 ) ;
return V_30 ;
}
}
}
for ( V_299 = 0 ; V_299 < V_7 -> V_301 ; V_299 ++ ) {
struct V_302 * V_303 = & V_7 -> V_304 [ V_299 ] ;
int V_443 ;
if ( ! V_303 -> V_423 [ 0 ] . V_440 && ! V_303 -> V_423 [ 1 ] . V_440 )
continue;
if ( ! V_303 -> V_299 ) {
V_443 = F_220 ( V_7 -> V_29 , V_303 -> V_444 ) ;
if ( V_443 < 0 )
continue;
V_303 -> V_95 = V_443 ;
V_30 = F_222 ( V_7 , V_303 ) ;
if ( V_30 < 0 ) {
F_13 ( V_25 L_86
L_87 ,
V_443 , V_7 -> V_24 ) ;
continue;
}
}
}
return 0 ;
}
int T_7 F_224 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_48 (codec, &bus->codec_list, list) {
int V_30 = F_223 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
}
return 0 ;
}
int F_225 ( struct V_6 * V_7 ,
int V_445 , const char * const * V_446 ,
const struct V_447 * V_117 )
{
if ( V_7 -> V_109 && V_446 ) {
int V_12 ;
for ( V_12 = 0 ; V_12 < V_445 ; V_12 ++ ) {
if ( V_446 [ V_12 ] &&
! strcmp ( V_7 -> V_109 , V_446 [ V_12 ] ) ) {
F_17 ( V_448 L_88
L_89 , V_446 [ V_12 ] ) ;
return V_12 ;
}
}
}
if ( ! V_7 -> V_29 -> V_108 || ! V_117 )
return - 1 ;
V_117 = F_226 ( V_7 -> V_29 -> V_108 , V_117 ) ;
if ( ! V_117 )
return - 1 ;
if ( V_117 -> V_261 >= 0 && V_117 -> V_261 < V_445 ) {
#ifdef F_227
char V_131 [ 10 ] ;
const char * V_449 = NULL ;
if ( V_446 )
V_449 = V_446 [ V_117 -> V_261 ] ;
if ( ! V_449 ) {
sprintf ( V_131 , L_90 , V_117 -> V_261 ) ;
V_449 = V_131 ;
}
F_86 ( V_448 L_91
L_92 ,
V_449 , V_117 -> V_450 , V_117 -> V_292 ,
( V_117 -> V_127 ? V_117 -> V_127 : L_93 ) ) ;
#endif
return V_117 -> V_261 ;
}
return - 1 ;
}
int F_228 ( struct V_6 * V_7 ,
int V_445 , const char * const * V_446 ,
const struct V_447 * V_117 )
{
const struct V_447 * V_206 ;
for ( V_206 = V_117 ; V_206 -> V_450 ; V_206 ++ ) {
unsigned long V_451 = ( V_206 -> V_292 ) | ( V_206 -> V_450 << 16 ) ;
if ( V_451 == V_7 -> V_184 )
break;
}
if ( ! V_206 -> V_450 )
return - 1 ;
V_117 = V_206 ;
if ( V_117 -> V_261 >= 0 && V_117 -> V_261 < V_445 ) {
#ifdef F_227
char V_131 [ 10 ] ;
const char * V_449 = NULL ;
if ( V_446 )
V_449 = V_446 [ V_117 -> V_261 ] ;
if ( ! V_449 ) {
sprintf ( V_131 , L_90 , V_117 -> V_261 ) ;
V_449 = V_131 ;
}
F_86 ( V_448 L_91
L_92 ,
V_449 , V_117 -> V_450 , V_117 -> V_292 ,
( V_117 -> V_127 ? V_117 -> V_127 : L_93 ) ) ;
#endif
return V_117 -> V_261 ;
}
return - 1 ;
}
int F_229 ( struct V_6 * V_7 ,
const struct V_353 * V_452 )
{
int V_30 ;
for (; V_452 -> V_127 ; V_452 ++ ) {
struct V_254 * V_289 ;
int V_24 = 0 , V_213 = 0 ;
if ( V_452 -> V_287 == - 1 )
continue;
for (; ; ) {
V_289 = F_181 ( V_452 , V_7 ) ;
if ( ! V_289 )
return - V_56 ;
if ( V_24 > 0 )
V_289 -> V_120 . V_95 = V_24 ;
if ( V_213 > 0 )
V_289 -> V_120 . V_236 = V_213 ;
V_30 = F_139 ( V_7 , 0 , V_289 ) ;
if ( ! V_30 )
break;
if ( ! V_24 && V_7 -> V_24 )
V_24 = V_7 -> V_24 ;
else if ( ! V_213 && ! V_452 -> V_236 ) {
V_213 = F_138 ( V_7 ,
V_452 -> V_127 ) ;
if ( V_213 <= 0 )
return V_30 ;
} else
return V_30 ;
}
}
return 0 ;
}
static void V_182 ( struct V_86 * V_85 )
{
struct V_6 * V_7 =
F_36 ( V_85 , struct V_6 , V_166 . V_85 ) ;
struct V_28 * V_29 = V_7 -> V_29 ;
if ( ! V_7 -> V_379 || V_7 -> V_453 ) {
V_7 -> V_380 = 0 ;
return;
}
F_198 ( V_7 ) ;
if ( V_29 -> V_33 . V_454 )
V_29 -> V_33 . V_454 ( V_29 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
V_7 -> V_453 ++ ;
V_7 -> V_379 = 1 ;
V_7 -> V_381 = V_374 ;
}
void F_199 ( struct V_6 * V_7 )
{
unsigned long V_455 = V_374 - V_7 -> V_381 ;
if ( V_7 -> V_379 )
V_7 -> V_456 += V_455 ;
else
V_7 -> V_457 += V_455 ;
V_7 -> V_381 += V_455 ;
}
void F_15 ( struct V_6 * V_7 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
V_7 -> V_453 ++ ;
if ( V_7 -> V_379 || V_7 -> V_380 )
return;
F_199 ( V_7 ) ;
V_7 -> V_379 = 1 ;
V_7 -> V_381 = V_374 ;
if ( V_29 -> V_33 . V_454 )
V_29 -> V_33 . V_454 ( V_29 ) ;
F_200 ( V_7 ) ;
F_80 ( & V_7 -> V_166 ) ;
V_7 -> V_380 = 0 ;
}
void F_16 ( struct V_6 * V_7 )
{
-- V_7 -> V_453 ;
if ( ! V_7 -> V_379 || V_7 -> V_453 || V_7 -> V_380 )
return;
if ( V_110 ( V_7 ) ) {
V_7 -> V_380 = 1 ;
F_230 ( V_7 -> V_29 -> V_84 , & V_7 -> V_166 ,
F_195 ( V_110 ( V_7 ) * 1000 ) ) ;
}
}
int F_231 ( struct V_6 * V_7 ,
struct V_458 * V_459 ,
T_2 V_19 )
{
const struct V_460 * V_54 ;
int V_235 , V_461 ;
if ( ! V_459 -> V_462 )
return 0 ;
for ( V_54 = V_459 -> V_462 ; V_54 -> V_19 ; V_54 ++ ) {
if ( V_54 -> V_19 == V_19 )
break;
}
if ( ! V_54 -> V_19 )
return 0 ;
for ( V_54 = V_459 -> V_462 ; V_54 -> V_19 ; V_54 ++ ) {
for ( V_235 = 0 ; V_235 < 2 ; V_235 ++ ) {
V_461 = F_115 ( V_7 , V_54 -> V_19 , V_235 , V_54 -> V_225 ,
V_54 -> V_213 ) ;
if ( ! ( V_461 & V_316 ) && V_461 > 0 ) {
if ( ! V_459 -> V_379 ) {
V_459 -> V_379 = 1 ;
F_15 ( V_7 ) ;
}
return 1 ;
}
}
}
if ( V_459 -> V_379 ) {
V_459 -> V_379 = 0 ;
F_16 ( V_7 ) ;
}
return 0 ;
}
int F_232 ( struct V_6 * V_7 ,
struct V_256 * V_257 ,
const struct V_463 * V_464 ,
int V_465 )
{
V_257 -> type = V_466 ;
V_257 -> V_260 = 1 ;
V_257 -> V_261 . V_467 . V_297 = V_465 ;
if ( V_257 -> V_261 . V_467 . V_291 >= V_465 )
V_257 -> V_261 . V_467 . V_291 = V_465 - 1 ;
sprintf ( V_257 -> V_261 . V_467 . V_127 , L_94 ,
V_464 [ V_257 -> V_261 . V_467 . V_291 ] . V_386 ) ;
return 0 ;
}
int F_233 ( struct V_6 * V_7 ,
struct V_266 * V_267 ,
const struct V_463 * V_464 ,
int V_465 ,
int V_468 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_465 ; V_12 ++ ) {
if ( V_468 == V_464 [ V_12 ] . V_386 ) {
V_267 -> V_261 . V_467 . V_291 [ 0 ] = V_12 ;
break;
}
}
return 0 ;
}
int F_234 ( struct V_6 * V_7 ,
struct V_266 * V_267 ,
const struct V_463 * V_464 ,
int V_465 ,
int * V_469 )
{
unsigned int V_470 ;
V_470 = V_267 -> V_261 . V_467 . V_291 [ 0 ] ;
if ( V_470 >= V_465 )
return - V_64 ;
if ( * V_469 == V_464 [ V_470 ] . V_386 )
return 0 ;
* V_469 = V_464 [ V_470 ] . V_386 ;
if ( V_464 [ V_470 ] . V_471 )
F_194 ( V_7 , V_464 [ V_470 ] . V_471 ) ;
return 1 ;
}
int F_235 ( const struct V_472 * V_473 ,
struct V_256 * V_257 )
{
unsigned int V_236 ;
V_257 -> type = V_466 ;
V_257 -> V_260 = 1 ;
V_257 -> V_261 . V_467 . V_297 = V_473 -> V_474 ;
if ( ! V_473 -> V_474 )
return 0 ;
V_236 = V_257 -> V_261 . V_467 . V_291 ;
if ( V_236 >= V_473 -> V_474 )
V_236 = V_473 -> V_474 - 1 ;
strcpy ( V_257 -> V_261 . V_467 . V_127 , V_473 -> V_297 [ V_236 ] . V_475 ) ;
return 0 ;
}
int F_236 ( struct V_6 * V_7 ,
const struct V_472 * V_473 ,
struct V_266 * V_267 ,
T_2 V_19 ,
unsigned int * V_476 )
{
unsigned int V_213 ;
if ( ! V_473 -> V_474 )
return 0 ;
V_213 = V_267 -> V_261 . V_467 . V_291 [ 0 ] ;
if ( V_213 >= V_473 -> V_474 )
V_213 = V_473 -> V_474 - 1 ;
if ( * V_476 == V_213 )
return 0 ;
F_175 ( V_7 , V_19 , 0 , V_477 ,
V_473 -> V_297 [ V_213 ] . V_236 ) ;
* V_476 = V_213 ;
return 1 ;
}
static void F_237 ( struct V_6 * V_7 , T_2 V_19 ,
unsigned int V_192 , unsigned int V_194 )
{
if ( V_7 -> V_311 && ( V_7 -> V_350 & V_351 ) )
F_176 ( V_7 , V_19 ,
V_7 -> V_350 & ~ V_351 & 0xff ,
- 1 ) ;
F_93 ( V_7 , V_19 , V_192 , 0 , V_194 ) ;
if ( V_7 -> V_310 ) {
const T_2 * V_345 ;
for ( V_345 = V_7 -> V_310 ; * V_345 ; V_345 ++ )
F_93 ( V_7 , * V_345 , V_192 , 0 ,
V_194 ) ;
}
if ( V_7 -> V_311 && ( V_7 -> V_350 & V_351 ) )
F_176 ( V_7 , V_19 ,
V_7 -> V_350 & 0xff , - 1 ) ;
}
static void F_238 ( struct V_6 * V_7 , T_2 V_19 )
{
F_216 ( V_7 , V_19 ) ;
if ( V_7 -> V_310 ) {
const T_2 * V_345 ;
for ( V_345 = V_7 -> V_310 ; * V_345 ; V_345 ++ )
F_216 ( V_7 , * V_345 ) ;
}
}
void F_239 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
if ( ! V_29 )
return;
F_48 (codec, &bus->codec_list, list) {
#ifdef F_79
if ( ! V_7 -> V_379 )
continue;
#endif
if ( V_7 -> V_90 . V_478 )
V_7 -> V_90 . V_478 ( V_7 ) ;
}
}
int F_240 ( struct V_6 * V_7 ,
struct V_357 * V_358 )
{
F_2 ( & V_7 -> V_176 ) ;
if ( V_358 -> V_479 == V_480 )
F_238 ( V_7 , V_358 -> V_360 ) ;
V_358 -> V_479 = V_481 ;
F_4 ( & V_7 -> V_176 ) ;
return 0 ;
}
int F_241 ( struct V_6 * V_7 ,
struct V_357 * V_358 ,
unsigned int V_192 ,
unsigned int V_194 ,
struct V_426 * V_427 )
{
F_2 ( & V_7 -> V_176 ) ;
F_237 ( V_7 , V_358 -> V_360 , V_192 , V_194 ) ;
F_4 ( & V_7 -> V_176 ) ;
return 0 ;
}
int F_242 ( struct V_6 * V_7 ,
struct V_357 * V_358 )
{
F_2 ( & V_7 -> V_176 ) ;
F_238 ( V_7 , V_358 -> V_360 ) ;
F_4 ( & V_7 -> V_176 ) ;
return 0 ;
}
int F_243 ( struct V_6 * V_7 ,
struct V_357 * V_358 )
{
F_2 ( & V_7 -> V_176 ) ;
V_358 -> V_479 = 0 ;
F_4 ( & V_7 -> V_176 ) ;
return 0 ;
}
int F_244 ( struct V_6 * V_7 ,
struct V_357 * V_358 ,
struct V_426 * V_427 ,
struct V_424 * V_425 )
{
struct V_482 * V_483 = V_427 -> V_483 ;
V_483 -> V_484 . V_485 = V_358 -> V_468 ;
if ( V_358 -> V_360 ) {
if ( ! V_358 -> V_486 ) {
V_358 -> V_486 = V_425 -> V_404 ;
V_358 -> V_487 = V_425 -> V_407 ;
V_358 -> V_488 = V_425 -> V_387 ;
} else {
V_483 -> V_484 . V_404 = V_358 -> V_486 ;
V_483 -> V_484 . V_407 = V_358 -> V_487 ;
V_425 -> V_387 = V_358 -> V_488 ;
}
if ( ! V_358 -> V_489 ) {
F_211 ( V_7 , V_358 -> V_360 ,
& V_358 -> V_489 ,
& V_358 -> V_490 ,
& V_358 -> V_491 ) ;
}
F_2 ( & V_7 -> V_176 ) ;
if ( V_358 -> V_359 ) {
if ( ( V_483 -> V_484 . V_404 & V_358 -> V_489 ) &&
( V_483 -> V_484 . V_407 & V_358 -> V_490 ) ) {
V_483 -> V_484 . V_404 &= V_358 -> V_489 ;
V_483 -> V_484 . V_407 &= V_358 -> V_490 ;
if ( V_358 -> V_491 < V_425 -> V_387 )
V_425 -> V_387 = V_358 -> V_491 ;
} else {
V_358 -> V_359 = 0 ;
}
}
F_4 ( & V_7 -> V_176 ) ;
}
return F_245 ( V_427 -> V_483 , 0 ,
V_492 , 2 ) ;
}
int F_246 ( struct V_6 * V_7 ,
struct V_357 * V_358 ,
unsigned int V_192 ,
unsigned int V_194 ,
struct V_426 * V_427 )
{
const T_2 * V_168 = V_358 -> V_493 ;
int V_258 = V_427 -> V_483 -> V_386 ;
int V_12 ;
F_2 ( & V_7 -> V_176 ) ;
if ( V_358 -> V_360 && V_358 -> V_359 &&
V_358 -> V_479 != V_481 ) {
if ( V_258 == 2 &&
F_212 ( V_7 , V_358 -> V_360 ,
V_194 ) &&
! ( V_7 -> V_336 & V_330 ) ) {
V_358 -> V_479 = V_480 ;
F_237 ( V_7 , V_358 -> V_360 ,
V_192 , V_194 ) ;
} else {
V_358 -> V_479 = 0 ;
F_238 ( V_7 , V_358 -> V_360 ) ;
}
}
F_4 ( & V_7 -> V_176 ) ;
F_93 ( V_7 , V_168 [ V_494 ] , V_192 ,
0 , V_194 ) ;
if ( ! V_358 -> V_495 &&
V_358 -> V_496 && V_358 -> V_496 != V_168 [ V_494 ] )
F_93 ( V_7 , V_358 -> V_496 , V_192 ,
0 , V_194 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_358 -> V_497 ) ; V_12 ++ )
if ( ! V_358 -> V_495 && V_358 -> V_497 [ V_12 ] )
F_93 ( V_7 ,
V_358 -> V_497 [ V_12 ] ,
V_192 , 0 , V_194 ) ;
for ( V_12 = 1 ; V_12 < V_358 -> V_498 ; V_12 ++ ) {
if ( V_258 >= ( V_12 + 1 ) * 2 )
F_93 ( V_7 , V_168 [ V_12 ] , V_192 ,
V_12 * 2 , V_194 ) ;
else if ( ! V_358 -> V_495 )
F_93 ( V_7 , V_168 [ V_12 ] , V_192 ,
0 , V_194 ) ;
}
return 0 ;
}
int F_247 ( struct V_6 * V_7 ,
struct V_357 * V_358 )
{
const T_2 * V_168 = V_358 -> V_493 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_358 -> V_498 ; V_12 ++ )
F_216 ( V_7 , V_168 [ V_12 ] ) ;
if ( V_358 -> V_496 )
F_216 ( V_7 , V_358 -> V_496 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( V_358 -> V_497 ) ; V_12 ++ )
if ( V_358 -> V_497 [ V_12 ] )
F_216 ( V_7 ,
V_358 -> V_497 [ V_12 ] ) ;
F_2 ( & V_7 -> V_176 ) ;
if ( V_358 -> V_360 && V_358 -> V_479 == V_480 ) {
F_238 ( V_7 , V_358 -> V_360 ) ;
V_358 -> V_479 = 0 ;
}
F_4 ( & V_7 -> V_176 ) ;
return 0 ;
}
static int F_248 ( T_2 V_19 , const T_2 * V_4 )
{
for (; * V_4 ; V_4 ++ )
if ( * V_4 == V_19 )
return 1 ;
return 0 ;
}
static void F_249 ( T_2 * V_499 , short * V_500 ,
int V_501 )
{
int V_12 , V_502 ;
short V_41 ;
T_2 V_19 ;
for ( V_12 = 0 ; V_12 < V_501 ; V_12 ++ ) {
for ( V_502 = V_12 + 1 ; V_502 < V_501 ; V_502 ++ ) {
if ( V_500 [ V_12 ] > V_500 [ V_502 ] ) {
V_41 = V_500 [ V_12 ] ;
V_500 [ V_12 ] = V_500 [ V_502 ] ;
V_500 [ V_502 ] = V_41 ;
V_19 = V_499 [ V_12 ] ;
V_499 [ V_12 ] = V_499 [ V_502 ] ;
V_499 [ V_502 ] = V_19 ;
}
}
}
}
static void F_250 ( struct V_503 * V_8 , T_2 V_19 ,
int type )
{
if ( V_8 -> V_504 < V_505 ) {
V_8 -> V_506 [ V_8 -> V_504 ] . V_151 = V_19 ;
V_8 -> V_506 [ V_8 -> V_504 ] . type = type ;
V_8 -> V_504 ++ ;
}
}
static void F_251 ( struct V_503 * V_8 )
{
int V_12 , V_502 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_504 ; V_12 ++ ) {
for ( V_502 = V_12 + 1 ; V_502 < V_8 -> V_504 ; V_502 ++ ) {
if ( V_8 -> V_506 [ V_12 ] . type > V_8 -> V_506 [ V_502 ] . type ) {
struct V_507 V_131 ;
V_131 = V_8 -> V_506 [ V_12 ] ;
V_8 -> V_506 [ V_12 ] = V_8 -> V_506 [ V_502 ] ;
V_8 -> V_506 [ V_502 ] = V_131 ;
}
}
}
}
int F_252 ( struct V_6 * V_7 ,
struct V_503 * V_8 ,
const T_2 * V_508 )
{
T_2 V_19 , V_509 ;
short V_41 , V_510 , V_511 ;
short V_512 [ F_9 ( V_8 -> V_513 ) ] ;
short V_514 [ F_9 ( V_8 -> V_515 ) ] ;
short V_516 [ F_9 ( V_8 -> V_517 ) ] ;
int V_12 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
memset ( V_512 , 0 , sizeof( V_512 ) ) ;
memset ( V_514 , 0 , sizeof( V_514 ) ) ;
memset ( V_516 , 0 , sizeof( V_516 ) ) ;
V_510 = V_511 = 0 ;
V_509 = V_7 -> V_148 + V_7 -> V_147 ;
for ( V_19 = V_7 -> V_148 ; V_19 < V_509 ; V_19 ++ ) {
unsigned int V_518 = F_29 ( V_7 , V_19 ) ;
unsigned int V_152 = F_30 ( V_518 ) ;
unsigned int V_519 ;
short V_520 , V_521 ;
if ( V_152 != V_153 )
continue;
if ( V_508 && F_248 ( V_19 , V_508 ) )
continue;
V_519 = F_70 ( V_7 , V_19 ) ;
if ( F_253 ( V_519 ) == V_522 )
continue;
V_521 = F_254 ( V_519 ) ;
switch ( F_255 ( V_519 ) ) {
case V_523 :
V_41 = F_256 ( V_519 ) ;
V_520 = F_257 ( V_519 ) ;
if ( ! ( V_518 & V_524 ) )
if ( ! V_8 -> V_525 )
V_8 -> V_525 = V_19 ;
if ( ! V_520 )
continue;
if ( ! V_510 )
V_510 = V_520 ;
else if ( V_510 != V_520 )
continue;
if ( V_8 -> V_526 >= F_9 ( V_8 -> V_513 ) )
continue;
V_8 -> V_513 [ V_8 -> V_526 ] = V_19 ;
V_512 [ V_8 -> V_526 ] = V_41 ;
V_8 -> V_526 ++ ;
break;
case V_527 :
V_41 = F_256 ( V_519 ) ;
V_520 = F_257 ( V_519 ) ;
if ( ! V_520 )
continue;
if ( ! V_511 )
V_511 = V_520 ;
else if ( V_511 != V_520 )
continue;
if ( V_8 -> V_528 >= F_9 ( V_8 -> V_515 ) )
continue;
V_8 -> V_515 [ V_8 -> V_528 ] = V_19 ;
V_514 [ V_8 -> V_528 ] = V_41 ;
V_8 -> V_528 ++ ;
break;
case V_529 :
V_41 = F_256 ( V_519 ) ;
V_520 = F_257 ( V_519 ) ;
if ( V_8 -> V_530 >= F_9 ( V_8 -> V_517 ) )
continue;
V_8 -> V_517 [ V_8 -> V_530 ] = V_19 ;
V_516 [ V_8 -> V_530 ] = ( V_520 << 4 ) | V_41 ;
V_8 -> V_530 ++ ;
break;
case V_531 :
F_250 ( V_8 , V_19 , V_532 ) ;
break;
case V_533 :
F_250 ( V_8 , V_19 , V_534 ) ;
break;
case V_535 :
F_250 ( V_8 , V_19 , V_536 ) ;
break;
case V_537 :
F_250 ( V_8 , V_19 , V_538 ) ;
break;
case V_539 :
case V_540 :
if ( V_8 -> V_541 >= F_9 ( V_8 -> V_542 ) )
continue;
V_8 -> V_542 [ V_8 -> V_541 ] = V_19 ;
V_8 -> V_543 [ V_8 -> V_541 ] =
( V_521 == V_544 ) ?
V_436 : V_435 ;
V_8 -> V_541 ++ ;
break;
case V_545 :
case V_546 :
V_8 -> V_547 = V_19 ;
if ( V_521 == V_544 )
V_8 -> V_548 = V_436 ;
else
V_8 -> V_548 = V_435 ;
break;
}
}
if ( ! V_8 -> V_526 && V_8 -> V_530 > 1 ) {
int V_12 = 0 ;
while ( V_12 < V_8 -> V_530 ) {
if ( ( V_516 [ V_12 ] & 0x0f ) == 0x0f ) {
V_12 ++ ;
continue;
}
V_8 -> V_513 [ V_8 -> V_526 ] = V_8 -> V_517 [ V_12 ] ;
V_512 [ V_8 -> V_526 ] = V_516 [ V_12 ] ;
V_8 -> V_526 ++ ;
V_8 -> V_530 -- ;
memmove ( V_8 -> V_517 + V_12 , V_8 -> V_517 + V_12 + 1 ,
sizeof( V_8 -> V_517 [ 0 ] ) * ( V_8 -> V_530 - V_12 ) ) ;
memmove ( V_516 + V_12 , V_516 + V_12 + 1 ,
sizeof( V_516 [ 0 ] ) * ( V_8 -> V_530 - V_12 ) ) ;
}
memset ( V_8 -> V_517 + V_8 -> V_530 , 0 ,
sizeof( T_2 ) * ( V_549 - V_8 -> V_530 ) ) ;
if ( ! V_8 -> V_530 )
V_8 -> V_550 = V_551 ;
}
F_249 ( V_8 -> V_513 , V_512 ,
V_8 -> V_526 ) ;
F_249 ( V_8 -> V_515 , V_514 ,
V_8 -> V_528 ) ;
F_249 ( V_8 -> V_517 , V_516 ,
V_8 -> V_530 ) ;
if ( ! V_8 -> V_526 ) {
if ( V_8 -> V_528 ) {
V_8 -> V_526 = V_8 -> V_528 ;
memcpy ( V_8 -> V_513 , V_8 -> V_515 ,
sizeof( V_8 -> V_515 ) ) ;
V_8 -> V_528 = 0 ;
memset ( V_8 -> V_515 , 0 , sizeof( V_8 -> V_515 ) ) ;
V_8 -> V_550 = V_552 ;
} else if ( V_8 -> V_530 ) {
V_8 -> V_526 = V_8 -> V_530 ;
memcpy ( V_8 -> V_513 , V_8 -> V_517 ,
sizeof( V_8 -> V_517 ) ) ;
V_8 -> V_530 = 0 ;
memset ( V_8 -> V_517 , 0 , sizeof( V_8 -> V_517 ) ) ;
V_8 -> V_550 = V_551 ;
}
}
switch ( V_8 -> V_526 ) {
case 3 :
case 4 :
V_19 = V_8 -> V_513 [ 1 ] ;
V_8 -> V_513 [ 1 ] = V_8 -> V_513 [ 2 ] ;
V_8 -> V_513 [ 2 ] = V_19 ;
break;
}
F_251 ( V_8 ) ;
F_17 ( L_95 ,
V_8 -> V_526 , V_8 -> V_513 [ 0 ] , V_8 -> V_513 [ 1 ] ,
V_8 -> V_513 [ 2 ] , V_8 -> V_513 [ 3 ] ,
V_8 -> V_513 [ 4 ] ,
V_8 -> V_550 == V_551 ? L_96 :
( V_8 -> V_550 == V_552 ?
L_97 : L_98 ) ) ;
F_17 ( L_99 ,
V_8 -> V_528 , V_8 -> V_515 [ 0 ] ,
V_8 -> V_515 [ 1 ] , V_8 -> V_515 [ 2 ] ,
V_8 -> V_515 [ 3 ] , V_8 -> V_515 [ 4 ] ) ;
F_17 ( L_100 ,
V_8 -> V_530 , V_8 -> V_517 [ 0 ] ,
V_8 -> V_517 [ 1 ] , V_8 -> V_517 [ 2 ] ,
V_8 -> V_517 [ 3 ] , V_8 -> V_517 [ 4 ] ) ;
F_17 ( L_101 , V_8 -> V_525 ) ;
if ( V_8 -> V_541 )
F_17 ( L_102 ,
V_8 -> V_542 [ 0 ] , V_8 -> V_542 [ 1 ] ) ;
F_17 ( L_103 ) ;
for ( V_12 = 0 ; V_12 < V_8 -> V_504 ; V_12 ++ ) {
F_17 ( L_104 ,
F_258 ( V_7 , V_8 , V_12 ) ,
V_8 -> V_506 [ V_12 ] . V_151 ) ;
}
F_17 ( L_105 ) ;
if ( V_8 -> V_547 )
F_17 ( L_106 , V_8 -> V_547 ) ;
return 0 ;
}
int F_259 ( unsigned int V_519 )
{
unsigned int V_521 = F_254 ( V_519 ) ;
unsigned int V_553 = F_253 ( V_519 ) ;
if ( V_553 == V_522 )
return V_554 ;
if ( V_553 == V_555 || V_553 == V_556 )
return V_557 ;
if ( ( V_521 & 0x30 ) == V_558 )
return V_557 ;
if ( ( V_521 & 0x30 ) == V_559 )
return V_560 ;
if ( V_521 == V_561 )
return V_562 ;
if ( V_521 == V_563 )
return V_564 ;
return V_565 ;
}
const char * F_260 ( struct V_6 * V_7 , T_2 V_151 ,
int V_566 )
{
unsigned int V_519 ;
static const char * const V_567 [] = {
L_107 , L_108 , L_30 , L_109 , L_110 ,
} ;
int V_568 ;
V_519 = F_70 ( V_7 , V_151 ) ;
switch ( F_255 ( V_519 ) ) {
case V_531 :
if ( ! V_566 )
return L_30 ;
V_568 = F_259 ( V_519 ) ;
if ( ! V_568 )
return L_111 ;
return V_567 [ V_568 - 1 ] ;
case V_533 :
if ( ! V_566 )
return L_112 ;
V_568 = F_259 ( V_519 ) ;
if ( ! V_568 )
return L_111 ;
if ( V_568 == V_560 )
return L_113 ;
return L_112 ;
case V_537 :
return L_29 ;
case V_535 :
return L_23 ;
case V_545 :
return L_32 ;
case V_546 :
return L_114 ;
default:
return L_115 ;
}
}
static int F_261 ( struct V_6 * V_7 ,
const struct V_503 * V_8 ,
int V_569 )
{
unsigned int V_570 ;
int V_12 , V_568 , V_571 ;
V_570 = F_70 ( V_7 , V_8 -> V_506 [ V_569 ] . V_151 ) ;
V_568 = F_259 ( V_570 ) ;
if ( V_568 <= V_565 )
return 1 ;
V_568 = 0 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_504 ; V_12 ++ ) {
V_570 = F_70 ( V_7 , V_8 -> V_506 [ V_12 ] . V_151 ) ;
V_571 = F_259 ( V_570 ) ;
if ( V_571 >= V_565 ) {
if ( V_568 && V_568 != V_571 )
return 1 ;
V_568 = V_571 ;
}
}
return 0 ;
}
const char * F_258 ( struct V_6 * V_7 ,
const struct V_503 * V_8 ,
int V_569 )
{
int type = V_8 -> V_506 [ V_569 ] . type ;
int V_572 = 0 ;
if ( ( V_569 > 0 && V_8 -> V_506 [ V_569 - 1 ] . type == type ) ||
( V_569 < V_8 -> V_504 - 1 && V_8 -> V_506 [ V_569 + 1 ] . type == type ) )
V_572 = 1 ;
if ( V_572 && type == V_532 )
V_572 &= F_261 ( V_7 , V_8 , V_569 ) ;
return F_260 ( V_7 , V_8 -> V_506 [ V_569 ] . V_151 ,
V_572 ) ;
}
int F_262 ( struct V_472 * V_473 , const char * V_475 ,
int V_236 , int * V_573 )
{
int V_12 , V_574 = 0 ;
if ( V_473 -> V_474 >= V_575 ) {
F_17 ( V_25 L_116 ) ;
return - V_64 ;
}
for ( V_12 = 0 ; V_12 < V_473 -> V_474 ; V_12 ++ ) {
if ( ! strncmp ( V_475 , V_473 -> V_297 [ V_12 ] . V_475 , strlen ( V_475 ) ) )
V_574 ++ ;
}
if ( V_573 )
* V_573 = V_574 ;
if ( V_574 > 0 )
snprintf ( V_473 -> V_297 [ V_473 -> V_474 ] . V_475 ,
sizeof( V_473 -> V_297 [ V_473 -> V_474 ] . V_475 ) ,
L_117 , V_475 , V_574 ) ;
else
F_263 ( V_473 -> V_297 [ V_473 -> V_474 ] . V_475 , V_475 ,
sizeof( V_473 -> V_297 [ V_473 -> V_474 ] . V_475 ) ) ;
V_473 -> V_297 [ V_473 -> V_474 ] . V_236 = V_236 ;
V_473 -> V_474 ++ ;
return 0 ;
}
int F_264 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_48 (codec, &bus->codec_list, list) {
#ifdef F_79
if ( ! V_7 -> V_379 )
continue;
#endif
F_198 ( V_7 ) ;
}
return 0 ;
}
int F_265 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_48 (codec, &bus->codec_list, list) {
if ( F_266 ( V_7 ) )
F_200 ( V_7 ) ;
}
return 0 ;
}
void * F_32 ( struct V_47 * V_48 )
{
if ( V_48 -> V_53 >= V_48 -> V_576 ) {
int V_577 = V_48 -> V_576 + V_48 -> V_578 ;
void * V_579 ;
if ( F_28 ( V_577 >= 4096 ) )
return NULL ;
V_579 = F_267 ( V_577 + 1 , V_48 -> V_580 , V_92 ) ;
if ( ! V_579 )
return NULL ;
if ( V_48 -> V_4 ) {
memcpy ( V_579 , V_48 -> V_4 ,
V_48 -> V_580 * V_48 -> V_576 ) ;
F_42 ( V_48 -> V_4 ) ;
}
V_48 -> V_4 = V_579 ;
V_48 -> V_576 = V_577 ;
}
return F_24 ( V_48 , V_48 -> V_53 ++ ) ;
}
void F_77 ( struct V_47 * V_48 )
{
F_42 ( V_48 -> V_4 ) ;
V_48 -> V_53 = 0 ;
V_48 -> V_576 = 0 ;
V_48 -> V_4 = NULL ;
}
void F_268 ( int V_299 , char * V_211 , int V_581 )
{
static unsigned int V_404 [] = {
8000 , 11025 , 16000 , 22050 , 32000 , 44100 , 48000 , 88200 ,
96000 , 176400 , 192000 , 384000
} ;
int V_12 , V_502 ;
for ( V_12 = 0 , V_502 = 0 ; V_12 < F_9 ( V_404 ) ; V_12 ++ )
if ( V_299 & ( 1 << V_12 ) )
V_502 += snprintf ( V_211 + V_502 , V_581 - V_502 , L_118 , V_404 [ V_12 ] ) ;
V_211 [ V_502 ] = '\0' ;
}
void F_269 ( int V_299 , char * V_211 , int V_581 )
{
static unsigned int V_582 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_12 , V_502 ;
for ( V_12 = 0 , V_502 = 0 ; V_12 < F_9 ( V_582 ) ; V_12 ++ )
if ( V_299 & ( V_410 << V_12 ) )
V_502 += snprintf ( V_211 + V_502 , V_581 - V_502 , L_118 , V_582 [ V_12 ] ) ;
V_211 [ V_502 ] = '\0' ;
}
static const char * F_270 ( struct V_6 * V_7 , T_2 V_19 ,
int type )
{
switch ( type ) {
case V_583 :
return L_119 ;
case V_584 :
return L_30 ;
case V_585 :
return L_120 ;
case V_586 :
return L_121 ;
case V_587 :
return L_122 ;
default:
return L_115 ;
}
}
static void F_271 ( struct V_588 * V_589 )
{
struct V_590 * V_591 = V_589 -> V_107 ;
V_591 -> V_19 = 0 ;
V_591 -> V_589 = NULL ;
}
int F_272 ( struct V_6 * V_7 , T_2 V_19 , int type ,
const char * V_127 )
{
struct V_590 * V_589 ;
int V_30 ;
F_84 ( & V_7 -> V_591 , sizeof( * V_589 ) , 32 ) ;
V_589 = F_32 ( & V_7 -> V_591 ) ;
if ( ! V_589 )
return - V_56 ;
V_589 -> V_19 = V_19 ;
V_589 -> type = type ;
if ( ! V_127 )
V_127 = F_270 ( V_7 , V_19 , type ) ;
V_30 = F_273 ( V_7 -> V_29 -> V_99 , V_127 , type , & V_589 -> V_589 ) ;
if ( V_30 < 0 ) {
V_589 -> V_19 = 0 ;
return V_30 ;
}
V_589 -> V_589 -> V_107 = V_589 ;
V_589 -> V_589 -> V_93 = F_271 ;
return 0 ;
}
void F_274 ( struct V_6 * V_7 , T_2 V_19 )
{
struct V_590 * V_591 = V_7 -> V_591 . V_4 ;
int V_12 ;
if ( ! V_591 )
return;
for ( V_12 = 0 ; V_12 < V_7 -> V_591 . V_53 ; V_12 ++ , V_591 ++ ) {
unsigned int V_592 ;
unsigned int V_593 ;
int type ;
if ( V_591 -> V_19 != V_19 )
continue;
V_593 = F_111 ( V_7 , V_19 ) ;
type = V_591 -> type ;
if ( type == ( V_583 | V_585 ) ) {
V_592 = F_18 ( V_7 , V_19 , 0 ,
V_157 , 0 ) ;
type = ( V_592 & V_594 ) ?
V_583 : V_585 ;
}
F_275 ( V_591 -> V_589 , V_593 ? type : 0 ) ;
}
}
void F_276 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_29 -> V_97 && V_7 -> V_591 . V_4 ) {
struct V_590 * V_591 = V_7 -> V_591 . V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_591 . V_53 ; V_12 ++ , V_591 ++ ) {
if ( V_591 -> V_589 )
F_151 ( V_7 -> V_29 -> V_99 , V_591 -> V_589 ) ;
}
}
F_77 ( & V_7 -> V_591 ) ;
}
