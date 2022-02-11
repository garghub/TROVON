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
static inline void F_7 ( struct V_6 * V_7 , bool V_8 )
{
if ( V_7 -> V_9 . V_10 )
V_7 -> V_9 . V_10 ( V_7 , V_8 ) ;
}
static inline void F_8 ( struct V_11 * V_12 ) {}
const char * F_9 ( T_1 V_13 )
{
static char * V_14 [ 7 ] = {
L_1 , L_2 , L_3 , L_4 , L_5 , L_6 , L_7 ,
} ;
static unsigned char V_15 [] = {
0x07 , 0x08 ,
0x17 , 0x18 , 0x19 ,
0x37 , 0x38
} ;
static char * V_16 [] = {
L_8 , L_9 ,
L_10 , L_11 , L_12 ,
L_13 , L_14
} ;
int V_17 ;
V_13 = ( V_13 & V_18 ) >> V_19 ;
if ( ( V_13 & 0x0f ) < 7 )
return V_14 [ V_13 & 0x0f ] ;
for ( V_17 = 0 ; V_17 < F_10 ( V_15 ) ; V_17 ++ ) {
if ( V_13 == V_15 [ V_17 ] )
return V_16 [ V_17 ] ;
}
return L_15 ;
}
const char * F_11 ( T_1 V_13 )
{
static char * V_20 [ 4 ] = { L_16 , L_17 , L_18 , L_19 } ;
return V_20 [ ( V_13 >> ( V_19 + 4 ) ) & 3 ] ;
}
const char * F_12 ( T_1 V_13 )
{
static char * V_21 [ 16 ] = {
L_20 , L_21 , L_22 , L_23 ,
L_24 , L_25 , L_26 , L_27 ,
L_28 , L_29 , L_30 , L_31 ,
L_32 , L_33 , L_34 , L_35
} ;
return V_21 [ ( V_13 & V_22 )
>> V_23 ] ;
}
static inline unsigned int
F_13 ( struct V_11 * V_12 , T_2 V_24 , int V_25 ,
unsigned int V_26 , unsigned int V_27 )
{
T_1 V_28 ;
if ( ( V_12 -> V_29 & ~ 0xf ) || ( V_25 & ~ 1 ) || ( V_24 & ~ 0x7f ) ||
( V_26 & ~ 0xfff ) || ( V_27 & ~ 0xffff ) ) {
F_14 ( V_30 L_36 ,
V_12 -> V_29 , V_25 , V_24 , V_26 , V_27 ) ;
return ~ 0 ;
}
V_28 = ( T_1 ) V_12 -> V_29 << 28 ;
V_28 |= ( T_1 ) V_25 << 27 ;
V_28 |= ( T_1 ) V_24 << 20 ;
V_28 |= V_26 << 8 ;
V_28 |= V_27 ;
return V_28 ;
}
static int F_15 ( struct V_11 * V_12 , unsigned int V_31 ,
unsigned int * V_32 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
int V_33 ;
if ( V_31 == ~ 0 )
return - 1 ;
if ( V_32 )
* V_32 = - 1 ;
V_34:
F_16 ( V_12 ) ;
F_2 ( & V_7 -> V_35 ) ;
F_17 ( V_12 , V_31 ) ;
V_33 = V_7 -> V_9 . V_36 ( V_7 , V_31 ) ;
if ( ! V_33 && V_32 ) {
* V_32 = V_7 -> V_9 . V_37 ( V_7 , V_12 -> V_29 ) ;
F_18 ( V_12 , * V_32 ) ;
}
F_4 ( & V_7 -> V_35 ) ;
F_19 ( V_12 ) ;
if ( ! F_20 ( V_12 ) && V_32 && * V_32 == - 1 && V_7 -> V_38 ) {
if ( V_7 -> V_39 ) {
F_21 ( L_37
L_38 ) ;
F_22 ( V_7 ) ;
V_7 -> V_9 . V_40 ( V_7 ) ;
}
goto V_34;
}
if ( ! V_33 || F_20 ( V_12 ) )
V_7 -> V_39 = 0 ;
return V_33 ;
}
unsigned int F_23 ( struct V_11 * V_12 , T_2 V_24 ,
int V_25 ,
unsigned int V_26 , unsigned int V_27 )
{
unsigned V_31 = F_13 ( V_12 , V_24 , V_25 , V_26 , V_27 ) ;
unsigned int V_32 ;
if ( F_15 ( V_12 , V_31 , & V_32 ) )
return - 1 ;
return V_32 ;
}
int F_24 ( struct V_11 * V_12 , T_2 V_24 , int V_25 ,
unsigned int V_26 , unsigned int V_27 )
{
unsigned int V_31 = F_13 ( V_12 , V_24 , V_25 , V_26 , V_27 ) ;
unsigned int V_32 ;
return F_15 ( V_12 , V_31 ,
V_12 -> V_7 -> V_41 ? & V_32 : NULL ) ;
}
void F_25 ( struct V_11 * V_12 , const struct V_42 * V_43 )
{
for (; V_43 -> V_24 ; V_43 ++ )
F_24 ( V_12 , V_43 -> V_24 , 0 , V_43 -> V_26 , V_43 -> V_44 ) ;
}
int F_26 ( struct V_11 * V_12 , T_2 V_24 ,
T_2 * V_45 )
{
unsigned int V_27 ;
V_27 = F_27 ( V_12 , V_24 , V_46 ) ;
if ( V_27 == - 1 )
return 0 ;
* V_45 = ( V_27 >> 16 ) & 0x7fff ;
return ( int ) ( V_27 & 0x7fff ) ;
}
static T_2 * F_28 ( struct V_47 * V_48 , T_2 V_24 )
{
int V_17 , V_49 ;
for ( V_17 = 0 ; V_17 < V_48 -> V_50 ; ) {
T_2 * V_51 = F_29 ( V_48 , V_17 ) ;
if ( V_24 == * V_51 )
return V_51 ;
V_49 = V_51 [ 1 ] ;
V_17 += V_49 + 2 ;
}
return NULL ;
}
static int F_30 ( struct V_11 * V_12 , T_2 V_24 )
{
T_2 V_4 [ V_52 ] ;
int V_49 ;
V_49 = F_31 ( V_12 , V_24 , V_4 , F_10 ( V_4 ) ) ;
if ( V_49 < 0 )
return V_49 ;
return F_32 ( V_12 , V_24 , V_49 , V_4 ) ;
}
int F_33 ( struct V_11 * V_12 , T_2 V_24 ,
T_2 * V_53 , int V_54 )
{
struct V_47 * V_48 = & V_12 -> V_55 ;
int V_49 ;
T_2 * V_51 ;
bool V_56 = false ;
V_34:
F_2 ( & V_12 -> V_57 ) ;
V_49 = - 1 ;
V_51 = F_28 ( V_48 , V_24 ) ;
if ( V_51 ) {
V_49 = V_51 [ 1 ] ;
if ( V_53 && V_49 > V_54 ) {
F_34 ( V_30 L_39
L_40 ,
V_49 , V_24 ) ;
F_4 ( & V_12 -> V_57 ) ;
return - V_58 ;
}
if ( V_53 && V_49 )
memcpy ( V_53 , V_51 + 2 , V_49 * sizeof( T_2 ) ) ;
}
F_4 ( & V_12 -> V_57 ) ;
if ( V_49 >= 0 )
return V_49 ;
if ( F_35 ( V_56 ) )
return - V_58 ;
V_49 = F_30 ( V_12 , V_24 ) ;
if ( V_49 < 0 )
return V_49 ;
V_56 = true ;
goto V_34;
}
int F_31 ( struct V_11 * V_12 , T_2 V_24 ,
T_2 * V_53 , int V_54 )
{
unsigned int V_27 ;
int V_17 , V_59 , V_60 ;
unsigned int V_61 , V_62 , V_63 ;
unsigned int V_64 ;
T_2 V_65 ;
if ( F_35 ( ! V_53 || V_54 <= 0 ) )
return - V_58 ;
V_64 = F_36 ( V_12 , V_24 ) ;
if ( ! ( V_64 & V_66 ) &&
F_37 ( V_64 ) != V_67 )
return 0 ;
V_27 = F_27 ( V_12 , V_24 , V_68 ) ;
if ( V_27 & V_69 ) {
V_61 = 16 ;
V_62 = 2 ;
} else {
V_61 = 8 ;
V_62 = 4 ;
}
V_59 = V_27 & V_70 ;
V_63 = ( 1 << ( V_61 - 1 ) ) - 1 ;
if ( ! V_59 )
return 0 ;
if ( V_59 == 1 ) {
V_27 = F_23 ( V_12 , V_24 , 0 ,
V_71 , 0 ) ;
if ( V_27 == - 1 && V_12 -> V_7 -> V_38 )
return - V_72 ;
V_53 [ 0 ] = V_27 & V_63 ;
return 1 ;
}
V_60 = 0 ;
V_65 = 0 ;
for ( V_17 = 0 ; V_17 < V_59 ; V_17 ++ ) {
int V_73 ;
T_2 V_28 , V_74 ;
if ( V_17 % V_62 == 0 ) {
V_27 = F_23 ( V_12 , V_24 , 0 ,
V_71 , V_17 ) ;
if ( V_27 == - 1 && V_12 -> V_7 -> V_38 )
return - V_72 ;
}
V_73 = ! ! ( V_27 & ( 1 << ( V_61 - 1 ) ) ) ;
V_28 = V_27 & V_63 ;
if ( V_28 == 0 ) {
F_34 ( V_75 L_39
L_41 ,
V_24 , V_17 , V_27 ) ;
return 0 ;
}
V_27 >>= V_61 ;
if ( V_73 ) {
if ( ! V_65 || V_65 >= V_28 ) {
F_34 ( V_75 L_39
L_42 ,
V_65 , V_28 ) ;
continue;
}
for ( V_74 = V_65 + 1 ; V_74 <= V_28 ; V_74 ++ ) {
if ( V_60 >= V_54 ) {
F_34 ( V_30 L_39
L_40 ,
V_60 , V_24 ) ;
return - V_58 ;
}
V_53 [ V_60 ++ ] = V_74 ;
}
} else {
if ( V_60 >= V_54 ) {
F_34 ( V_30 L_39
L_40 ,
V_60 , V_24 ) ;
return - V_58 ;
}
V_53 [ V_60 ++ ] = V_28 ;
}
V_65 = V_28 ;
}
return V_60 ;
}
static bool F_38 ( struct V_47 * V_48 , T_2 V_24 )
{
T_2 * V_51 = F_39 ( V_48 ) ;
if ( ! V_51 )
return false ;
* V_51 = V_24 ;
return true ;
}
int F_32 ( struct V_11 * V_12 , T_2 V_24 , int V_49 ,
const T_2 * V_4 )
{
struct V_47 * V_48 = & V_12 -> V_55 ;
T_2 * V_51 ;
int V_17 , V_76 ;
F_2 ( & V_12 -> V_57 ) ;
V_51 = F_28 ( V_48 , V_24 ) ;
if ( V_51 )
* V_51 = - 1 ;
V_76 = V_48 -> V_50 ;
if ( ! F_38 ( V_48 , V_24 ) || ! F_38 ( V_48 , V_49 ) )
goto V_77;
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ )
if ( ! F_38 ( V_48 , V_4 [ V_17 ] ) )
goto V_77;
F_4 ( & V_12 -> V_57 ) ;
return 0 ;
V_77:
V_48 -> V_50 = V_76 ;
F_4 ( & V_12 -> V_57 ) ;
return - V_78 ;
}
int F_40 ( struct V_11 * V_12 , T_2 V_79 ,
T_2 V_24 , int V_80 )
{
T_2 V_81 [ V_82 ] ;
int V_17 , V_83 ;
V_83 = F_33 ( V_12 , V_79 , V_81 , F_10 ( V_81 ) ) ;
for ( V_17 = 0 ; V_17 < V_83 ; V_17 ++ )
if ( V_81 [ V_17 ] == V_24 )
return V_17 ;
if ( ! V_80 )
return - 1 ;
if ( V_80 > 5 ) {
F_21 ( L_43 , V_24 ) ;
return - 1 ;
}
V_80 ++ ;
for ( V_17 = 0 ; V_17 < V_83 ; V_17 ++ ) {
unsigned int type = F_37 ( F_36 ( V_12 , V_81 [ V_17 ] ) ) ;
if ( type == V_84 || type == V_85 )
continue;
if ( F_40 ( V_12 , V_81 [ V_17 ] , V_24 , V_80 ) >= 0 )
return V_17 ;
}
return - 1 ;
}
int F_41 ( struct V_6 * V_7 , T_1 V_32 , T_1 V_86 )
{
struct V_87 * V_88 ;
unsigned int V_89 ;
F_42 ( V_7 , V_32 , V_86 ) ;
V_88 = V_7 -> V_88 ;
if ( ! V_88 )
return 0 ;
V_89 = ( V_88 -> V_89 + 1 ) % V_90 ;
V_88 -> V_89 = V_89 ;
V_89 <<= 1 ;
V_88 -> V_91 [ V_89 ] = V_32 ;
V_88 -> V_91 [ V_89 + 1 ] = V_86 ;
F_43 ( V_7 -> V_92 , & V_88 -> V_93 ) ;
return 0 ;
}
static void F_44 ( struct V_94 * V_93 )
{
struct V_87 * V_88 =
F_45 ( V_93 , struct V_87 , V_93 ) ;
struct V_6 * V_7 = V_88 -> V_7 ;
struct V_11 * V_12 ;
unsigned int V_95 , V_96 , V_32 ;
while ( V_88 -> V_95 != V_88 -> V_89 ) {
V_95 = ( V_88 -> V_95 + 1 ) % V_90 ;
V_88 -> V_95 = V_95 ;
V_95 <<= 1 ;
V_32 = V_88 -> V_91 [ V_95 ] ;
V_96 = V_88 -> V_91 [ V_95 + 1 ] ;
if ( ! ( V_96 & ( 1 << 4 ) ) )
continue;
V_12 = V_7 -> V_97 [ V_96 & 0x0f ] ;
if ( V_12 && V_12 -> V_98 . V_99 )
V_12 -> V_98 . V_99 ( V_12 , V_32 ) ;
}
}
static int F_46 ( struct V_6 * V_7 )
{
struct V_87 * V_88 ;
if ( V_7 -> V_88 )
return 0 ;
V_88 = F_47 ( sizeof( * V_88 ) , V_100 ) ;
if ( ! V_88 ) {
F_34 ( V_30 L_39
L_44 ) ;
return - V_78 ;
}
F_48 ( & V_88 -> V_93 , F_44 ) ;
V_88 -> V_7 = V_7 ;
V_7 -> V_88 = V_88 ;
return 0 ;
}
static int F_49 ( struct V_6 * V_7 )
{
struct V_11 * V_12 , * V_74 ;
if ( ! V_7 )
return 0 ;
if ( V_7 -> V_92 )
F_50 ( V_7 -> V_92 ) ;
if ( V_7 -> V_88 )
F_51 ( V_7 -> V_88 ) ;
F_52 (codec, n, &bus->codec_list, list) {
F_53 ( V_12 ) ;
}
if ( V_7 -> V_9 . V_101 )
V_7 -> V_9 . V_101 ( V_7 ) ;
if ( V_7 -> V_92 )
F_54 ( V_7 -> V_92 ) ;
F_51 ( V_7 ) ;
return 0 ;
}
static int F_55 ( struct V_102 * V_103 )
{
struct V_6 * V_7 = V_103 -> V_104 ;
V_7 -> V_105 = 1 ;
return F_49 ( V_7 ) ;
}
static int F_56 ( struct V_102 * V_103 )
{
struct V_6 * V_7 = V_103 -> V_104 ;
struct V_11 * V_12 ;
F_57 (codec, &bus->codec_list, list) {
F_58 ( V_12 ) ;
F_59 ( V_12 ) ;
}
return 0 ;
}
int F_60 ( struct V_106 * V_107 ,
const struct V_108 * V_109 ,
struct V_6 * * V_110 )
{
struct V_6 * V_7 ;
int V_33 ;
static struct V_111 V_112 = {
. V_113 = F_56 ,
. V_114 = F_55 ,
} ;
if ( F_35 ( ! V_109 ) )
return - V_58 ;
if ( F_35 ( ! V_109 -> V_9 . V_36 || ! V_109 -> V_9 . V_37 ) )
return - V_58 ;
if ( V_110 )
* V_110 = NULL ;
V_7 = F_47 ( sizeof( * V_7 ) , V_100 ) ;
if ( V_7 == NULL ) {
F_34 ( V_30 L_45 ) ;
return - V_78 ;
}
V_7 -> V_107 = V_107 ;
V_7 -> V_115 = V_109 -> V_115 ;
V_7 -> V_116 = V_109 -> V_116 ;
V_7 -> V_117 = V_109 -> V_117 ;
V_7 -> V_118 = V_109 -> V_118 ;
V_7 -> V_9 = V_109 -> V_9 ;
F_61 ( & V_7 -> V_35 ) ;
F_61 ( & V_7 -> V_119 ) ;
F_62 ( & V_7 -> V_120 ) ;
snprintf ( V_7 -> V_121 , sizeof( V_7 -> V_121 ) ,
L_46 , V_107 -> V_122 ) ;
V_7 -> V_92 = F_63 ( V_7 -> V_121 ) ;
if ( ! V_7 -> V_92 ) {
F_34 ( V_30 L_47 ,
V_7 -> V_121 ) ;
F_51 ( V_7 ) ;
return - V_78 ;
}
V_33 = F_64 ( V_107 , V_123 , V_7 , & V_112 ) ;
if ( V_33 < 0 ) {
F_49 ( V_7 ) ;
return V_33 ;
}
if ( V_110 )
* V_110 = V_7 ;
return 0 ;
}
static const struct V_124 *
F_65 ( struct V_11 * V_12 )
{
struct V_1 * V_125 ;
const struct V_124 * V_2 ;
unsigned int V_126 = 0 ;
if ( F_66 ( V_12 ) )
return NULL ;
V_34:
F_2 ( & V_3 ) ;
F_57 (tbl, &hda_preset_tables, list) {
if ( ! F_67 ( V_125 -> V_127 ) ) {
F_34 ( V_30 L_48 ) ;
continue;
}
for ( V_2 = V_125 -> V_2 ; V_2 -> V_128 ; V_2 ++ ) {
T_1 V_63 = V_2 -> V_63 ;
if ( V_2 -> V_129 && V_2 -> V_129 != V_12 -> V_129 )
continue;
if ( V_2 -> V_130 && V_2 -> V_130 != V_12 -> V_130 )
continue;
if ( ! V_63 )
V_63 = ~ 0 ;
if ( V_2 -> V_128 == ( V_12 -> V_131 & V_63 ) &&
( ! V_2 -> V_132 ||
V_2 -> V_132 == V_12 -> V_133 ) ) {
F_4 ( & V_3 ) ;
V_12 -> V_127 = V_125 -> V_127 ;
return V_2 ;
}
}
F_68 ( V_125 -> V_127 ) ;
}
F_4 ( & V_3 ) ;
if ( V_126 < V_134 ) {
char V_135 [ 32 ] ;
if ( ! V_126 )
snprintf ( V_135 , sizeof( V_135 ) , L_49 ,
V_12 -> V_131 ) ;
else
snprintf ( V_135 , sizeof( V_135 ) , L_50 ,
( V_12 -> V_131 >> 16 ) & 0xffff ) ;
F_69 ( V_135 ) ;
V_126 ++ ;
goto V_34;
}
return NULL ;
}
static int F_70 ( struct V_11 * V_12 )
{
const struct V_136 * V_137 ;
const char * V_138 = NULL ;
T_3 V_131 = V_12 -> V_131 >> 16 ;
char V_139 [ 16 ] ;
if ( V_12 -> V_140 )
goto V_141;
for ( V_137 = V_142 ; V_137 -> V_128 ; V_137 ++ ) {
if ( V_137 -> V_128 == V_131 ) {
V_138 = V_137 -> V_135 ;
break;
}
}
if ( ! V_138 ) {
sprintf ( V_139 , L_51 , V_131 ) ;
V_138 = V_139 ;
}
V_12 -> V_140 = F_71 ( V_138 , V_100 ) ;
if ( ! V_12 -> V_140 )
return - V_78 ;
V_141:
if ( V_12 -> V_143 )
return 0 ;
if ( V_12 -> V_2 && V_12 -> V_2 -> V_135 )
V_12 -> V_143 = F_71 ( V_12 -> V_2 -> V_135 , V_100 ) ;
else {
sprintf ( V_139 , L_52 , V_12 -> V_131 & 0xffff ) ;
V_12 -> V_143 = F_71 ( V_139 , V_100 ) ;
}
if ( ! V_12 -> V_143 )
return - V_78 ;
return 0 ;
}
static void F_72 ( struct V_11 * V_12 )
{
int V_17 , V_144 , V_145 ;
T_2 V_24 ;
V_144 = F_26 ( V_12 , V_146 , & V_24 ) ;
for ( V_17 = 0 ; V_17 < V_144 ; V_17 ++ , V_24 ++ ) {
V_145 = F_27 ( V_12 , V_24 ,
V_147 ) ;
switch ( V_145 & 0xff ) {
case V_148 :
V_12 -> V_129 = V_24 ;
V_12 -> V_149 = V_145 & 0xff ;
V_12 -> V_150 = ( V_145 >> 8 ) & 1 ;
break;
case V_151 :
V_12 -> V_130 = V_24 ;
V_12 -> V_152 = V_145 & 0xff ;
V_12 -> V_153 = ( V_145 >> 8 ) & 1 ;
break;
default:
break;
}
}
}
static int F_73 ( struct V_11 * V_12 , T_2 V_154 )
{
int V_17 ;
T_2 V_24 ;
V_12 -> V_155 = F_26 ( V_12 , V_154 ,
& V_12 -> V_156 ) ;
V_12 -> V_64 = F_74 ( V_12 -> V_155 * 4 , V_100 ) ;
if ( ! V_12 -> V_64 )
return - V_78 ;
V_24 = V_12 -> V_156 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_155 ; V_17 ++ , V_24 ++ )
V_12 -> V_64 [ V_17 ] = F_27 ( V_12 , V_24 ,
V_157 ) ;
return 0 ;
}
static int F_75 ( struct V_11 * V_12 )
{
int V_17 ;
T_2 V_24 = V_12 -> V_156 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_155 ; V_17 ++ , V_24 ++ ) {
struct V_158 * V_159 ;
unsigned int V_64 = F_36 ( V_12 , V_24 ) ;
unsigned int V_160 = F_37 ( V_64 ) ;
if ( V_160 != V_84 )
continue;
V_159 = F_39 ( & V_12 -> V_161 ) ;
if ( ! V_159 )
return - V_78 ;
V_159 -> V_24 = V_24 ;
V_159 -> V_13 = F_23 ( V_12 , V_24 , 0 ,
V_162 , 0 ) ;
V_159 -> V_163 = F_23 ( V_12 , V_24 , 0 ,
V_164 ,
0 ) ;
}
return 0 ;
}
static struct V_158 * F_76 ( struct V_11 * V_12 ,
struct V_47 * V_48 ,
T_2 V_24 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_48 -> V_50 ; V_17 ++ ) {
struct V_158 * V_159 = F_29 ( V_48 , V_17 ) ;
if ( V_159 -> V_24 == V_24 )
return V_159 ;
}
return NULL ;
}
static void F_77 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_13 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ ) {
F_24 ( V_12 , V_24 , 0 ,
V_165 + V_17 ,
V_13 & 0xff ) ;
V_13 >>= 8 ;
}
}
int F_78 ( struct V_11 * V_12 , struct V_47 * V_4 ,
T_2 V_24 , unsigned int V_13 )
{
struct V_158 * V_159 ;
unsigned int V_166 ;
if ( F_37 ( F_36 ( V_12 , V_24 ) ) != V_84 )
return - V_58 ;
V_166 = F_79 ( V_12 , V_24 ) ;
V_159 = F_76 ( V_12 , V_4 , V_24 ) ;
if ( ! V_159 ) {
V_159 = F_39 ( V_4 ) ;
if ( ! V_159 )
return - V_78 ;
V_159 -> V_24 = V_24 ;
}
V_159 -> V_13 = V_13 ;
V_13 = F_79 ( V_12 , V_24 ) ;
if ( V_166 != V_13 )
F_77 ( V_12 , V_24 , V_13 ) ;
return 0 ;
}
int F_80 ( struct V_11 * V_12 ,
T_2 V_24 , unsigned int V_13 )
{
return F_78 ( V_12 , & V_12 -> V_167 , V_24 , V_13 ) ;
}
unsigned int F_79 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_158 * V_159 ;
#ifdef F_81
V_159 = F_76 ( V_12 , & V_12 -> V_168 , V_24 ) ;
if ( V_159 )
return V_159 -> V_13 ;
#endif
V_159 = F_76 ( V_12 , & V_12 -> V_167 , V_24 ) ;
if ( V_159 )
return V_159 -> V_13 ;
V_159 = F_76 ( V_12 , & V_12 -> V_161 , V_24 ) ;
if ( V_159 )
return V_159 -> V_13 ;
return 0 ;
}
static void F_82 ( struct V_11 * V_12 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_161 . V_50 ; V_17 ++ ) {
struct V_158 * V_159 = F_29 ( & V_12 -> V_161 , V_17 ) ;
F_77 ( V_12 , V_159 -> V_24 ,
F_79 ( V_12 , V_159 -> V_24 ) ) ;
}
}
void F_83 ( struct V_11 * V_12 )
{
int V_17 ;
if ( V_12 -> V_7 -> V_105 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_161 . V_50 ; V_17 ++ ) {
struct V_158 * V_159 = F_29 ( & V_12 -> V_161 , V_17 ) ;
F_23 ( V_12 , V_159 -> V_24 , 0 ,
V_169 , 0 ) ;
}
V_12 -> V_170 = 1 ;
}
static void F_84 ( struct V_11 * V_12 )
{
int V_17 ;
if ( ! V_12 -> V_170 )
return;
if ( V_12 -> V_7 -> V_105 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_161 . V_50 ; V_17 ++ ) {
struct V_158 * V_159 = F_29 ( & V_12 -> V_161 , V_17 ) ;
F_24 ( V_12 , V_159 -> V_24 , 0 ,
V_169 ,
V_159 -> V_163 ) ;
}
V_12 -> V_170 = 0 ;
}
static void F_85 ( struct V_11 * V_12 )
{
F_86 ( & V_12 -> V_167 ) ;
#ifdef F_81
F_86 ( & V_12 -> V_168 ) ;
#endif
F_82 ( V_12 ) ;
F_86 ( & V_12 -> V_161 ) ;
}
static struct V_171 *
F_87 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_171 * V_51 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_172 . V_50 ; V_17 ++ ) {
V_51 = F_29 ( & V_12 -> V_172 , V_17 ) ;
if ( V_51 -> V_24 == V_24 )
return V_51 ;
}
V_51 = F_39 ( & V_12 -> V_172 ) ;
if ( V_51 )
V_51 -> V_24 = V_24 ;
return V_51 ;
}
static void F_53 ( struct V_11 * V_12 )
{
if ( ! V_12 )
return;
F_88 ( V_12 ) ;
F_85 ( V_12 ) ;
#ifdef F_89
F_90 ( & V_12 -> V_173 ) ;
F_50 ( V_12 -> V_7 -> V_92 ) ;
#endif
F_6 ( & V_12 -> V_4 ) ;
F_86 ( & V_12 -> V_174 ) ;
F_86 ( & V_12 -> V_175 ) ;
F_86 ( & V_12 -> V_172 ) ;
F_86 ( & V_12 -> V_55 ) ;
F_86 ( & V_12 -> V_176 ) ;
V_12 -> V_7 -> V_97 [ V_12 -> V_29 ] = NULL ;
if ( V_12 -> V_98 . free )
V_12 -> V_98 . free ( V_12 ) ;
#ifdef F_89
if ( ! V_12 -> V_177 )
F_7 ( V_12 -> V_7 , false ) ;
#endif
F_68 ( V_12 -> V_127 ) ;
F_91 ( & V_12 -> V_178 ) ;
F_91 ( & V_12 -> V_179 ) ;
F_51 ( V_12 -> V_140 ) ;
F_51 ( V_12 -> V_143 ) ;
F_51 ( V_12 -> V_117 ) ;
F_51 ( V_12 -> V_64 ) ;
F_51 ( V_12 ) ;
}
int F_92 ( struct V_6 * V_7 ,
unsigned int V_180 ,
struct V_11 * * V_181 )
{
struct V_11 * V_12 ;
char V_182 [ 31 ] ;
T_2 V_183 ;
int V_33 ;
if ( F_35 ( ! V_7 ) )
return - V_58 ;
if ( F_35 ( V_180 > V_184 ) )
return - V_58 ;
if ( V_7 -> V_97 [ V_180 ] ) {
F_34 ( V_30 L_39
L_53 , V_180 ) ;
return - V_185 ;
}
V_12 = F_47 ( sizeof( * V_12 ) , V_100 ) ;
if ( V_12 == NULL ) {
F_34 ( V_30 L_54 ) ;
return - V_78 ;
}
V_12 -> V_7 = V_7 ;
V_12 -> V_29 = V_180 ;
F_61 ( & V_12 -> V_186 ) ;
F_61 ( & V_12 -> V_187 ) ;
F_61 ( & V_12 -> V_57 ) ;
F_93 ( & V_12 -> V_178 , sizeof( struct V_188 ) ) ;
F_93 ( & V_12 -> V_179 , sizeof( struct V_189 ) ) ;
F_94 ( & V_12 -> V_174 , sizeof( struct V_190 ) , 32 ) ;
F_94 ( & V_12 -> V_175 , sizeof( struct V_190 ) , 32 ) ;
F_94 ( & V_12 -> V_161 , sizeof( struct V_158 ) , 16 ) ;
F_94 ( & V_12 -> V_167 , sizeof( struct V_158 ) , 16 ) ;
F_94 ( & V_12 -> V_172 , sizeof( struct V_171 ) , 8 ) ;
F_94 ( & V_12 -> V_55 , sizeof( T_2 ) , 64 ) ;
F_94 ( & V_12 -> V_176 , sizeof( struct V_191 ) , 16 ) ;
#ifdef F_89
F_95 ( & V_12 -> V_192 ) ;
F_96 ( & V_12 -> V_173 , V_193 ) ;
F_8 ( V_12 ) ;
F_7 ( V_7 , true ) ;
#endif
if ( V_12 -> V_7 -> V_117 ) {
V_12 -> V_117 = F_71 ( V_12 -> V_7 -> V_117 , V_100 ) ;
if ( ! V_12 -> V_117 ) {
F_53 ( V_12 ) ;
return - V_194 ;
}
}
F_3 ( & V_12 -> V_4 , & V_7 -> V_120 ) ;
V_7 -> V_97 [ V_180 ] = V_12 ;
V_12 -> V_131 = F_27 ( V_12 , V_146 ,
V_195 ) ;
if ( V_12 -> V_131 == - 1 )
V_12 -> V_131 = F_27 ( V_12 , V_146 ,
V_195 ) ;
V_12 -> V_196 = F_27 ( V_12 , V_146 ,
V_197 ) ;
V_12 -> V_133 = F_27 ( V_12 , V_146 ,
V_198 ) ;
F_72 ( V_12 ) ;
if ( ! V_12 -> V_129 && ! V_12 -> V_130 ) {
F_97 ( L_55 ) ;
V_33 = - V_194 ;
goto error;
}
V_183 = V_12 -> V_129 ? V_12 -> V_129 : V_12 -> V_130 ;
V_33 = F_73 ( V_12 , V_183 ) ;
if ( V_33 < 0 ) {
F_34 ( V_30 L_56 ) ;
goto error;
}
V_33 = F_75 ( V_12 ) ;
if ( V_33 < 0 )
goto error;
if ( ! V_12 -> V_196 ) {
V_12 -> V_196 =
F_23 ( V_12 , V_183 , 0 ,
V_199 , 0 ) ;
}
#ifdef F_89
V_12 -> V_200 = F_98 ( V_12 , V_183 ,
V_201 ) ;
if ( ! V_12 -> V_200 )
V_7 -> V_202 = 1 ;
#endif
V_12 -> V_203 = F_98 ( V_12 , V_183 ,
V_204 ) ;
F_99 ( V_12 , V_205 ) ;
F_100 ( V_12 ) ;
F_101 ( V_12 ) ;
sprintf ( V_182 , L_57 , V_12 -> V_131 ,
V_12 -> V_196 , V_12 -> V_133 ) ;
F_102 ( V_12 -> V_7 -> V_107 , V_182 ) ;
if ( V_181 )
* V_181 = V_12 ;
return 0 ;
error:
F_53 ( V_12 ) ;
return V_33 ;
}
int F_103 ( struct V_11 * V_12 )
{
int V_33 ;
V_12 -> V_2 = F_65 ( V_12 ) ;
if ( ! V_12 -> V_140 || ! V_12 -> V_143 ) {
V_33 = F_70 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( F_66 ( V_12 ) ) {
V_33 = F_104 ( V_12 ) ;
goto V_206;
}
if ( V_12 -> V_2 && V_12 -> V_2 -> V_207 ) {
V_33 = V_12 -> V_2 -> V_207 ( V_12 ) ;
goto V_206;
}
V_33 = F_104 ( V_12 ) ;
if ( V_33 < 0 )
F_14 ( V_30 L_58 ) ;
V_206:
if ( ! V_33 && V_12 -> V_98 . V_99 )
V_33 = F_46 ( V_12 -> V_7 ) ;
if ( ! V_33 && ( V_12 -> V_129 || ! * V_12 -> V_7 -> V_107 -> V_208 ) )
snprintf ( V_12 -> V_7 -> V_107 -> V_208 ,
sizeof( V_12 -> V_7 -> V_107 -> V_208 ) ,
L_59 , V_12 -> V_140 , V_12 -> V_143 ) ;
return V_33 ;
}
static void F_105 ( struct V_11 * V_12 ,
struct V_171 * V_51 , T_2 V_24 ,
T_1 V_209 , int V_210 )
{
unsigned int V_211 , V_212 ;
if ( V_51 -> V_209 != V_209 || V_51 -> V_210 != V_210 ) {
V_211 = F_23 ( V_12 , V_24 , 0 , V_213 , 0 ) ;
V_212 = ( V_209 << 4 ) | V_210 ;
if ( V_211 != V_212 )
F_24 ( V_12 , V_24 , 0 ,
V_214 ,
V_212 ) ;
V_51 -> V_209 = V_209 ;
V_51 -> V_210 = V_210 ;
}
}
static void F_106 ( struct V_11 * V_12 , struct V_171 * V_51 ,
T_2 V_24 , int V_215 )
{
unsigned int V_211 ;
if ( V_51 -> V_216 != V_215 ) {
V_211 = F_23 ( V_12 , V_24 , 0 ,
V_217 , 0 ) ;
if ( V_211 != V_215 ) {
F_107 ( 1 ) ;
F_24 ( V_12 , V_24 , 0 ,
V_218 ,
V_215 ) ;
}
V_51 -> V_216 = V_215 ;
}
}
void F_108 ( struct V_11 * V_12 , T_2 V_24 ,
T_1 V_209 ,
int V_210 , int V_215 )
{
struct V_11 * V_137 ;
struct V_171 * V_51 ;
int type ;
int V_17 ;
if ( ! V_24 )
return;
F_97 ( L_60
L_61 ,
V_24 , V_209 , V_210 , V_215 ) ;
V_51 = F_87 ( V_12 , V_24 ) ;
if ( ! V_51 )
return;
if ( V_12 -> V_219 )
F_106 ( V_12 , V_51 , V_24 , V_215 ) ;
F_105 ( V_12 , V_51 , V_24 , V_209 , V_210 ) ;
if ( ! V_12 -> V_219 )
F_106 ( V_12 , V_51 , V_24 , V_215 ) ;
V_51 -> V_220 = 1 ;
V_51 -> V_221 = 0 ;
type = F_37 ( F_36 ( V_12 , V_24 ) ) ;
F_57 (c, &codec->bus->codec_list, list) {
for ( V_17 = 0 ; V_17 < V_137 -> V_172 . V_50 ; V_17 ++ ) {
V_51 = F_29 ( & V_137 -> V_172 , V_17 ) ;
if ( ! V_51 -> V_220 && V_51 -> V_209 == V_209 &&
F_37 ( F_36 ( V_137 , V_51 -> V_24 ) ) == type )
V_51 -> V_221 = 1 ;
}
}
}
void F_109 ( struct V_11 * V_12 , T_2 V_24 ,
int V_222 )
{
struct V_171 * V_51 ;
if ( ! V_24 )
return;
if ( V_12 -> V_223 )
V_222 = 1 ;
F_97 ( L_62 , V_24 ) ;
V_51 = F_87 ( V_12 , V_24 ) ;
if ( V_51 ) {
if ( V_222 )
F_110 ( V_12 , V_51 ) ;
else
V_51 -> V_220 = 0 ;
}
}
static void F_110 ( struct V_11 * V_12 ,
struct V_171 * V_224 )
{
T_2 V_24 = V_224 -> V_24 ;
if ( V_224 -> V_209 || V_224 -> V_210 )
F_24 ( V_12 , V_24 , 0 , V_214 , 0 ) ;
if ( V_224 -> V_216 )
F_24 ( V_12 , V_24 , 0 , V_218 , 0
) ;
memset ( V_224 , 0 , sizeof( * V_224 ) ) ;
V_224 -> V_24 = V_24 ;
}
static void F_111 ( struct V_11 * V_12 )
{
struct V_11 * V_137 ;
int V_17 ;
F_57 (c, &codec->bus->codec_list, list) {
for ( V_17 = 0 ; V_17 < V_137 -> V_172 . V_50 ; V_17 ++ ) {
struct V_171 * V_51 ;
V_51 = F_29 ( & V_137 -> V_172 , V_17 ) ;
if ( V_51 -> V_221 )
F_110 ( V_137 , V_51 ) ;
}
}
}
static void F_112 ( struct V_11 * V_12 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_172 . V_50 ; V_17 ++ ) {
struct V_171 * V_51 = F_29 ( & V_12 -> V_172 , V_17 ) ;
if ( V_51 -> V_209 )
F_110 ( V_12 , V_51 ) ;
}
}
static void F_93 ( struct V_225 * V_226 ,
unsigned int V_227 )
{
memset ( V_226 , 0 , sizeof( * V_226 ) ) ;
memset ( V_226 -> V_228 , 0xff , sizeof( V_226 -> V_228 ) ) ;
F_94 ( & V_226 -> V_229 , V_227 , 64 ) ;
}
static void F_91 ( struct V_225 * V_226 )
{
F_86 ( & V_226 -> V_229 ) ;
}
static struct V_189 * F_113 ( struct V_225 * V_226 , T_1 V_230 )
{
T_3 V_231 = V_230 % ( T_3 ) F_10 ( V_226 -> V_228 ) ;
T_3 V_232 = V_226 -> V_228 [ V_231 ] ;
struct V_189 * V_233 ;
while ( V_232 != 0xffff ) {
V_233 = F_29 ( & V_226 -> V_229 , V_232 ) ;
if ( V_233 -> V_230 == V_230 )
return V_233 ;
V_232 = V_233 -> V_234 ;
}
return NULL ;
}
static struct V_189 * F_114 ( struct V_225 * V_226 ,
T_1 V_230 )
{
struct V_189 * V_233 = F_113 ( V_226 , V_230 ) ;
if ( ! V_233 ) {
T_3 V_231 , V_232 ;
V_233 = F_39 ( & V_226 -> V_229 ) ;
if ( ! V_233 )
return NULL ;
V_232 = F_115 ( & V_226 -> V_229 , V_233 ) ;
V_233 -> V_230 = V_230 ;
V_233 -> V_28 = 0 ;
V_231 = V_230 % ( T_3 ) F_10 ( V_226 -> V_228 ) ;
V_233 -> V_234 = V_226 -> V_228 [ V_231 ] ;
V_226 -> V_228 [ V_231 ] = V_232 ;
}
return V_233 ;
}
static inline struct V_188 *
F_116 ( struct V_11 * V_12 , T_1 V_230 )
{
return (struct V_188 * ) F_114 ( & V_12 -> V_178 , V_230 ) ;
}
static int F_117 ( struct V_11 * V_12 , T_1 V_230 , unsigned int V_28 )
{
struct V_188 * V_233 ;
F_2 ( & V_12 -> V_57 ) ;
V_233 = F_116 ( V_12 , V_230 ) ;
if ( ! V_233 ) {
F_4 ( & V_12 -> V_57 ) ;
return - V_58 ;
}
V_233 -> V_235 = V_28 ;
V_233 -> V_236 . V_28 |= V_237 ;
F_4 ( & V_12 -> V_57 ) ;
return 0 ;
}
static unsigned int F_118 ( struct V_11 * V_12 , T_2 V_24 ,
int V_238 )
{
if ( ! ( F_36 ( V_12 , V_24 ) & V_239 ) )
V_24 = V_12 -> V_129 ;
return F_27 ( V_12 , V_24 ,
V_238 == V_240 ?
V_241 : V_242 ) ;
}
T_1 F_119 ( struct V_11 * V_12 , T_2 V_24 , int V_238 )
{
return F_120 ( V_12 , V_24 , V_238 ,
F_121 ( V_24 , V_238 , 0 ) ,
F_118 ) ;
}
int F_122 ( struct V_11 * V_12 , T_2 V_24 , int V_243 ,
unsigned int V_244 )
{
return F_117 ( V_12 , F_121 ( V_24 , V_243 , 0 ) , V_244 ) ;
}
static unsigned int F_123 ( struct V_11 * V_12 , T_2 V_24 ,
int V_243 )
{
return F_27 ( V_12 , V_24 , V_245 ) ;
}
T_1 F_124 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_120 ( V_12 , V_24 , 0 , F_125 ( V_24 ) ,
F_123 ) ;
}
int F_126 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_244 )
{
return F_117 ( V_12 , F_125 ( V_24 ) , V_244 ) ;
}
static struct V_188 *
F_127 ( struct V_11 * V_12 , T_2 V_24 , int V_246 ,
int V_238 , int V_247 )
{
struct V_188 * V_233 ;
unsigned int V_27 , V_28 = 0 ;
bool V_248 = false ;
V_249:
V_233 = F_116 ( V_12 , F_121 ( V_24 , V_238 , V_247 ) ) ;
if ( ! V_233 )
return NULL ;
if ( ! ( V_233 -> V_236 . V_28 & F_128 ( V_246 ) ) ) {
if ( ! V_248 ) {
F_4 ( & V_12 -> V_57 ) ;
V_27 = V_246 ? V_250 : V_251 ;
V_27 |= V_238 == V_240 ?
V_252 : V_253 ;
V_27 |= V_247 ;
V_28 = F_23 ( V_12 , V_24 , 0 ,
V_254 , V_27 ) ;
V_28 &= 0xff ;
V_248 = true ;
F_2 ( & V_12 -> V_57 ) ;
goto V_249;
}
V_233 -> V_255 [ V_246 ] = V_28 ;
V_233 -> V_236 . V_28 |= F_128 ( V_246 ) ;
}
return V_233 ;
}
static void F_129 ( struct V_11 * V_12 , struct V_188 * V_233 ,
T_2 V_24 , int V_246 , int V_238 , int V_247 ,
int V_28 )
{
T_1 V_27 ;
V_27 = V_246 ? V_256 : V_257 ;
V_27 |= V_238 == V_240 ? V_258 : V_259 ;
V_27 |= V_247 << V_260 ;
if ( ( V_28 & V_261 ) && ! ( V_233 -> V_235 & V_262 ) &&
( V_233 -> V_235 & V_263 ) )
;
else
V_27 |= V_28 ;
F_24 ( V_12 , V_24 , 0 , V_264 , V_27 ) ;
}
int F_130 ( struct V_11 * V_12 , T_2 V_24 , int V_246 ,
int V_238 , int V_247 )
{
struct V_188 * V_233 ;
unsigned int V_28 = 0 ;
F_2 ( & V_12 -> V_57 ) ;
V_233 = F_127 ( V_12 , V_24 , V_246 , V_238 , V_247 ) ;
if ( V_233 )
V_28 = V_233 -> V_255 [ V_246 ] ;
F_4 ( & V_12 -> V_57 ) ;
return V_28 ;
}
int F_131 ( struct V_11 * V_12 , T_2 V_24 , int V_246 ,
int V_238 , int V_231 , int V_63 , int V_28 )
{
struct V_188 * V_233 ;
if ( F_35 ( V_63 & ~ 0xff ) )
V_63 &= 0xff ;
V_28 &= V_63 ;
F_2 ( & V_12 -> V_57 ) ;
V_233 = F_127 ( V_12 , V_24 , V_246 , V_238 , V_231 ) ;
if ( ! V_233 ) {
F_4 ( & V_12 -> V_57 ) ;
return 0 ;
}
V_28 |= V_233 -> V_255 [ V_246 ] & ~ V_63 ;
if ( V_233 -> V_255 [ V_246 ] == V_28 ) {
F_4 ( & V_12 -> V_57 ) ;
return 0 ;
}
V_233 -> V_255 [ V_246 ] = V_28 ;
F_4 ( & V_12 -> V_57 ) ;
F_129 ( V_12 , V_233 , V_24 , V_246 , V_238 , V_231 , V_28 ) ;
return 1 ;
}
int F_132 ( struct V_11 * V_12 , T_2 V_24 ,
int V_238 , int V_231 , int V_63 , int V_28 )
{
int V_246 , V_265 = 0 ;
if ( F_35 ( V_63 & ~ 0xff ) )
V_63 &= 0xff ;
for ( V_246 = 0 ; V_246 < 2 ; V_246 ++ )
V_265 |= F_131 ( V_12 , V_24 , V_246 , V_238 ,
V_231 , V_63 , V_28 ) ;
return V_265 ;
}
void F_133 ( struct V_11 * V_12 )
{
struct V_188 * V_266 = V_12 -> V_178 . V_229 . V_4 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_178 . V_229 . V_50 ; V_17 ++ , V_266 ++ ) {
T_1 V_230 = V_266 -> V_236 . V_230 ;
T_2 V_24 ;
unsigned int V_231 , V_243 , V_246 ;
if ( ! V_230 )
continue;
V_24 = V_230 & 0xff ;
V_231 = ( V_230 >> 16 ) & 0xff ;
V_243 = ( V_230 >> 24 ) & 0xff ;
for ( V_246 = 0 ; V_246 < 2 ; V_246 ++ ) {
if ( ! ( V_266 -> V_236 . V_28 & F_128 ( V_246 ) ) )
continue;
F_129 ( V_12 , V_266 , V_24 , V_246 , V_243 , V_231 ,
V_266 -> V_255 [ V_246 ] ) ;
}
}
}
static T_1 F_134 ( struct V_11 * V_12 , T_2 V_24 , int V_243 ,
unsigned int V_267 )
{
T_1 V_244 = F_119 ( V_12 , V_24 , V_243 ) ;
V_244 = ( V_244 & V_268 ) >> V_269 ;
if ( V_267 < V_244 )
V_244 -= V_267 ;
return V_244 ;
}
int F_135 ( struct V_270 * V_271 ,
struct V_272 * V_273 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
T_3 V_24 = F_137 ( V_271 ) ;
T_4 V_274 = F_138 ( V_271 ) ;
int V_243 = F_139 ( V_271 ) ;
unsigned int V_267 = F_140 ( V_271 ) ;
V_273 -> type = V_275 ;
V_273 -> V_276 = V_274 == 3 ? 2 : 1 ;
V_273 -> V_277 . integer . V_278 = 0 ;
V_273 -> V_277 . integer . V_279 = F_134 ( V_12 , V_24 , V_243 , V_267 ) ;
if ( ! V_273 -> V_277 . integer . V_279 ) {
F_14 ( V_75 L_39
L_63 , V_24 ,
V_271 -> V_128 . V_135 ) ;
return - V_58 ;
}
return 0 ;
}
static inline unsigned int
F_141 ( struct V_11 * V_12 , T_2 V_24 ,
int V_246 , int V_243 , int V_231 , unsigned int V_267 )
{
unsigned int V_28 ;
V_28 = F_130 ( V_12 , V_24 , V_246 , V_243 , V_231 ) ;
V_28 &= V_280 ;
if ( V_28 >= V_267 )
V_28 -= V_267 ;
else
V_28 = 0 ;
return V_28 ;
}
static inline int
F_142 ( struct V_11 * V_12 , T_2 V_24 ,
int V_246 , int V_243 , int V_231 , unsigned int V_267 ,
unsigned int V_28 )
{
unsigned int V_281 ;
if ( V_28 > 0 )
V_28 += V_267 ;
V_281 = F_134 ( V_12 , V_24 , V_243 , 0 ) ;
if ( V_28 > V_281 )
V_28 = V_281 ;
return F_131 ( V_12 , V_24 , V_246 , V_243 , V_231 ,
V_280 , V_28 ) ;
}
int F_143 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
T_2 V_24 = F_137 ( V_271 ) ;
int V_274 = F_138 ( V_271 ) ;
int V_243 = F_139 ( V_271 ) ;
int V_231 = F_144 ( V_271 ) ;
unsigned int V_267 = F_140 ( V_271 ) ;
long * V_284 = V_283 -> V_277 . integer . V_277 ;
if ( V_274 & 1 )
* V_284 ++ = F_141 ( V_12 , V_24 , 0 , V_243 , V_231 , V_267 ) ;
if ( V_274 & 2 )
* V_284 = F_141 ( V_12 , V_24 , 1 , V_243 , V_231 , V_267 ) ;
return 0 ;
}
int F_145 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
T_2 V_24 = F_137 ( V_271 ) ;
int V_274 = F_138 ( V_271 ) ;
int V_243 = F_139 ( V_271 ) ;
int V_231 = F_144 ( V_271 ) ;
unsigned int V_267 = F_140 ( V_271 ) ;
long * V_284 = V_283 -> V_277 . integer . V_277 ;
int V_285 = 0 ;
F_16 ( V_12 ) ;
if ( V_274 & 1 ) {
V_285 = F_142 ( V_12 , V_24 , 0 , V_243 , V_231 , V_267 , * V_284 ) ;
V_284 ++ ;
}
if ( V_274 & 2 )
V_285 |= F_142 ( V_12 , V_24 , 1 , V_243 , V_231 , V_267 , * V_284 ) ;
F_19 ( V_12 ) ;
return V_285 ;
}
int F_146 ( struct V_270 * V_271 , int V_286 ,
unsigned int V_287 , unsigned int T_5 * V_288 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
T_2 V_24 = F_137 ( V_271 ) ;
int V_243 = F_139 ( V_271 ) ;
unsigned int V_267 = F_140 ( V_271 ) ;
bool V_289 = F_147 ( V_271 ) ;
T_1 V_244 , V_290 , V_291 ;
if ( V_287 < 4 * sizeof( unsigned int ) )
return - V_78 ;
V_244 = F_119 ( V_12 , V_24 , V_243 ) ;
V_291 = ( V_244 & V_292 ) >> V_293 ;
V_291 = ( V_291 + 1 ) * 25 ;
V_290 = - ( ( V_244 & V_294 ) >> V_295 ) ;
V_290 += V_267 ;
V_290 = ( ( int ) V_290 ) * ( ( int ) V_291 ) ;
if ( V_289 || ( V_244 & V_263 ) )
V_291 |= V_296 ;
if ( F_148 ( V_297 , V_288 ) )
return - V_298 ;
if ( F_148 ( 2 * sizeof( unsigned int ) , V_288 + 1 ) )
return - V_298 ;
if ( F_148 ( V_290 , V_288 + 2 ) )
return - V_298 ;
if ( F_148 ( V_291 , V_288 + 3 ) )
return - V_298 ;
return 0 ;
}
void F_149 ( struct V_11 * V_12 , T_2 V_24 , int V_243 ,
unsigned int * V_299 )
{
T_1 V_244 ;
int V_83 , V_300 ;
V_244 = F_119 ( V_12 , V_24 , V_243 ) ;
V_83 = ( V_244 & V_268 ) >> V_269 ;
V_300 = ( V_244 & V_292 ) >> V_293 ;
V_300 = ( V_300 + 1 ) * 25 ;
V_299 [ 0 ] = V_297 ;
V_299 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_299 [ 2 ] = - V_83 * V_300 ;
V_299 [ 3 ] = V_300 ;
}
static struct V_270 *
F_150 ( struct V_11 * V_12 ,
const char * V_135 , int V_231 )
{
struct V_301 V_128 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_302 = V_303 ;
V_128 . V_247 = V_231 ;
if ( F_35 ( strlen ( V_135 ) >= sizeof( V_128 . V_135 ) ) )
return NULL ;
strcpy ( V_128 . V_135 , V_135 ) ;
return F_151 ( V_12 -> V_7 -> V_107 , & V_128 ) ;
}
struct V_270 * F_152 ( struct V_11 * V_12 ,
const char * V_135 )
{
return F_150 ( V_12 , V_135 , 0 ) ;
}
static int F_153 ( struct V_11 * V_12 , const char * V_135 )
{
int V_231 ;
for ( V_231 = 0 ; V_231 < 16 ; V_231 ++ ) {
if ( ! F_150 ( V_12 , V_135 , V_231 ) )
return V_231 ;
}
return - V_185 ;
}
int F_154 ( struct V_11 * V_12 , T_2 V_24 ,
struct V_270 * V_304 )
{
int V_33 ;
unsigned short V_305 = 0 ;
struct V_190 * V_306 ;
if ( V_304 -> V_128 . V_307 & V_308 ) {
V_305 |= V_309 ;
if ( V_24 == 0 )
V_24 = F_155 ( V_304 -> V_310 ) ;
}
if ( ( V_304 -> V_128 . V_307 & V_311 ) != 0 && V_24 == 0 )
V_24 = V_304 -> V_128 . V_307 & 0xffff ;
if ( V_304 -> V_128 . V_307 & ( V_311 | V_308 ) )
V_304 -> V_128 . V_307 = 0 ;
V_33 = F_156 ( V_12 -> V_7 -> V_107 , V_304 ) ;
if ( V_33 < 0 )
return V_33 ;
V_306 = F_39 ( & V_12 -> V_174 ) ;
if ( ! V_306 )
return - V_78 ;
V_306 -> V_304 = V_304 ;
V_306 -> V_24 = V_24 ;
V_306 -> V_305 = V_305 ;
return 0 ;
}
int F_157 ( struct V_11 * V_12 , struct V_270 * V_304 ,
unsigned int V_247 , T_2 V_24 )
{
struct V_190 * V_306 ;
if ( V_24 > 0 ) {
V_306 = F_39 ( & V_12 -> V_175 ) ;
if ( ! V_306 )
return - V_78 ;
V_306 -> V_304 = V_304 ;
V_306 -> V_247 = V_247 ;
V_306 -> V_24 = V_24 ;
return 0 ;
}
F_14 ( V_30 L_64 ,
V_304 -> V_128 . V_135 , V_304 -> V_128 . V_247 , V_247 ) ;
return - V_58 ;
}
void F_158 ( struct V_11 * V_12 )
{
int V_17 ;
struct V_190 * V_312 = V_12 -> V_174 . V_4 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_174 . V_50 ; V_17 ++ )
F_159 ( V_12 -> V_7 -> V_107 , V_312 [ V_17 ] . V_304 ) ;
F_86 ( & V_12 -> V_174 ) ;
F_86 ( & V_12 -> V_175 ) ;
}
int F_160 ( struct V_6 * V_7 )
{
struct V_106 * V_107 = V_7 -> V_107 ;
struct V_11 * V_12 ;
F_161 ( & V_107 -> V_313 ) ;
if ( V_107 -> V_105 )
goto V_314;
V_107 -> V_105 = 1 ;
if ( ! F_162 ( & V_107 -> V_315 ) )
goto V_316;
F_57 (codec, &bus->codec_list, list) {
int V_317 ;
for ( V_317 = 0 ; V_317 < V_12 -> V_318 ; V_317 ++ ) {
struct V_319 * V_320 = & V_12 -> V_321 [ V_317 ] ;
if ( ! V_320 -> V_317 )
continue;
if ( V_320 -> V_317 -> V_322 [ 0 ] . V_323 ||
V_320 -> V_317 -> V_322 [ 1 ] . V_323 )
goto V_316;
}
}
F_163 ( & V_107 -> V_313 ) ;
return 0 ;
V_316:
V_107 -> V_105 = 0 ;
V_314:
F_163 ( & V_107 -> V_313 ) ;
return - V_58 ;
}
void F_164 ( struct V_6 * V_7 )
{
struct V_106 * V_107 = V_7 -> V_107 ;
V_107 = V_7 -> V_107 ;
F_161 ( & V_107 -> V_313 ) ;
V_107 -> V_105 = 0 ;
F_163 ( & V_107 -> V_313 ) ;
}
int F_165 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_106 * V_107 = V_7 -> V_107 ;
int V_17 ;
if ( F_160 ( V_7 ) < 0 )
return - V_185 ;
#ifdef F_89
F_166 ( & V_12 -> V_173 ) ;
V_12 -> V_324 = 0 ;
V_12 -> V_325 = 0 ;
V_12 -> V_326 = V_327 ;
F_50 ( V_7 -> V_92 ) ;
#endif
F_158 ( V_12 ) ;
for ( V_17 = 0 ; V_17 < V_12 -> V_318 ; V_17 ++ ) {
if ( V_12 -> V_321 [ V_17 ] . V_317 ) {
F_167 ( V_107 , V_12 -> V_321 [ V_17 ] . V_317 ) ;
F_168 ( V_12 -> V_321 [ V_17 ] . V_103 ,
V_7 -> V_328 ) ;
}
}
if ( V_12 -> V_98 . free )
V_12 -> V_98 . free ( V_12 ) ;
memset ( & V_12 -> V_98 , 0 , sizeof( V_12 -> V_98 ) ) ;
F_88 ( V_12 ) ;
V_12 -> V_329 = NULL ;
V_12 -> V_330 = NULL ;
F_91 ( & V_12 -> V_178 ) ;
F_91 ( & V_12 -> V_179 ) ;
F_93 ( & V_12 -> V_178 , sizeof( struct V_188 ) ) ;
F_93 ( & V_12 -> V_179 , sizeof( struct V_189 ) ) ;
F_86 ( & V_12 -> V_167 ) ;
F_82 ( V_12 ) ;
F_86 ( & V_12 -> V_172 ) ;
F_86 ( & V_12 -> V_176 ) ;
V_12 -> V_318 = 0 ;
V_12 -> V_321 = NULL ;
V_12 -> V_2 = NULL ;
V_12 -> V_331 = NULL ;
V_12 -> V_332 = 0 ;
F_68 ( V_12 -> V_127 ) ;
V_12 -> V_127 = NULL ;
F_164 ( V_7 ) ;
return 0 ;
}
static int F_169 ( struct V_11 * V_12 , const char * const * V_333 ,
const char * V_334 , T_6 V_335 , void * V_336 )
{
struct V_190 * V_312 ;
const char * const * V_337 ;
int V_17 , V_33 ;
V_312 = V_12 -> V_174 . V_4 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_174 . V_50 ; V_17 ++ ) {
struct V_270 * V_338 = V_312 [ V_17 ] . V_304 ;
if ( ! V_338 || ! V_338 -> V_128 . V_135 ||
V_338 -> V_128 . V_302 != V_303 )
continue;
for ( V_337 = V_333 ; * V_337 ; V_337 ++ ) {
char V_339 [ sizeof( V_338 -> V_128 . V_135 ) ] ;
const char * V_135 = * V_337 ;
if ( V_334 ) {
snprintf ( V_339 , sizeof( V_339 ) , L_59 ,
V_135 , V_334 ) ;
V_135 = V_339 ;
}
if ( ! strcmp ( V_338 -> V_128 . V_135 , V_135 ) ) {
V_33 = V_335 ( V_336 , V_338 ) ;
if ( V_33 )
return V_33 ;
break;
}
}
}
return 0 ;
}
static int F_170 ( void * V_336 , struct V_270 * V_338 )
{
return 1 ;
}
static int F_171 ( struct V_270 * V_304 )
{
int V_288 [ 4 ] ;
const int * V_299 = NULL ;
int V_28 = - 1 ;
if ( V_304 -> V_340 [ 0 ] . V_341 & V_342 ) {
T_7 V_343 = F_172 () ;
F_173 ( F_174 () ) ;
if ( ! V_304 -> V_299 . V_137 ( V_304 , 0 , sizeof( V_288 ) , V_288 ) )
V_299 = V_288 ;
F_173 ( V_343 ) ;
} else if ( V_304 -> V_340 [ 0 ] . V_341 & V_344 )
V_299 = V_304 -> V_299 . V_51 ;
if ( V_299 && V_299 [ 0 ] == V_297 )
V_28 = - V_299 [ 2 ] / V_299 [ 3 ] ;
return V_28 ;
}
static int F_175 ( struct V_270 * V_304 , int V_28 )
{
struct V_282 * V_283 ;
V_283 = F_47 ( sizeof( * V_283 ) , V_100 ) ;
if ( ! V_283 )
return - V_78 ;
V_283 -> V_277 . integer . V_277 [ 0 ] = V_28 ;
V_283 -> V_277 . integer . V_277 [ 1 ] = V_28 ;
V_304 -> V_345 ( V_304 , V_283 ) ;
F_51 ( V_283 ) ;
return 0 ;
}
static int F_176 ( void * V_336 , struct V_270 * V_346 )
{
int V_347 = F_171 ( V_346 ) ;
if ( V_347 > 0 )
F_175 ( V_346 , V_347 ) ;
return 0 ;
}
static int F_177 ( void * V_336 , struct V_270 * V_346 )
{
return F_175 ( V_346 , 1 ) ;
}
int F_178 ( struct V_11 * V_12 , char * V_135 ,
unsigned int * V_299 , const char * const * V_333 ,
const char * V_334 , bool V_348 ,
struct V_270 * * V_349 )
{
struct V_270 * V_304 ;
int V_33 ;
if ( V_349 )
* V_349 = NULL ;
V_33 = F_169 ( V_12 , V_333 , V_334 , F_170 , NULL ) ;
if ( V_33 != 1 ) {
F_97 ( L_65 , V_135 ) ;
return 0 ;
}
V_304 = F_179 ( V_135 , V_299 ) ;
if ( ! V_304 )
return - V_78 ;
V_33 = F_154 ( V_12 , 0 , V_304 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_169 ( V_12 , V_333 , V_334 ,
( T_6 ) V_350 , V_304 ) ;
if ( V_33 < 0 )
return V_33 ;
F_175 ( V_304 , 0 ) ;
if ( V_348 )
F_169 ( V_12 , V_333 , V_334 ,
V_299 ? F_176 : F_177 , V_304 ) ;
if ( V_349 )
* V_349 = V_304 ;
return 0 ;
}
static int F_180 ( struct V_270 * V_271 ,
struct V_272 * V_273 )
{
static const char * const V_351 [] = {
L_66 , L_67 , L_68
} ;
unsigned int V_247 ;
V_273 -> type = V_352 ;
V_273 -> V_276 = 1 ;
V_273 -> V_277 . V_353 . V_312 = 3 ;
V_247 = V_273 -> V_277 . V_353 . V_306 ;
if ( V_247 >= 3 )
V_247 = 2 ;
strcpy ( V_273 -> V_277 . V_353 . V_135 , V_351 [ V_247 ] ) ;
return 0 ;
}
static int F_181 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_354 * V_355 = F_136 ( V_271 ) ;
V_283 -> V_277 . V_353 . V_306 [ 0 ] = V_355 -> V_356 ;
return 0 ;
}
static int F_182 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_354 * V_355 = F_136 ( V_271 ) ;
unsigned int V_357 = V_355 -> V_356 ;
V_355 -> V_356 = V_283 -> V_277 . V_353 . V_306 [ 0 ] ;
if ( V_355 -> V_356 > V_358 )
V_355 -> V_356 = V_358 ;
if ( V_357 == V_355 -> V_356 )
return 0 ;
F_183 ( V_355 ) ;
return 1 ;
}
int F_184 ( struct V_11 * V_12 ,
struct V_354 * V_355 ,
bool V_359 )
{
struct V_270 * V_304 ;
if ( ! V_355 -> V_355 || ! V_355 -> V_360 )
return 0 ;
F_185 ( V_355 -> V_360 , V_355 -> V_355 , V_12 ) ;
V_355 -> V_12 = V_12 ;
V_355 -> V_356 = V_358 ;
if ( ! V_359 )
return 0 ;
V_304 = F_186 ( & V_361 , V_355 ) ;
if ( ! V_304 )
return - V_78 ;
return F_154 ( V_12 , 0 , V_304 ) ;
}
void F_183 ( struct V_354 * V_355 )
{
if ( ! V_355 -> V_355 || ! V_355 -> V_12 )
return;
switch ( V_355 -> V_356 ) {
case V_358 :
F_187 ( V_355 -> V_360 ) ;
break;
default:
V_355 -> V_355 ( V_355 -> V_12 , V_355 -> V_356 ) ;
break;
}
}
int F_188 ( struct V_270 * V_271 ,
struct V_272 * V_273 )
{
int V_274 = F_138 ( V_271 ) ;
V_273 -> type = V_362 ;
V_273 -> V_276 = V_274 == 3 ? 2 : 1 ;
V_273 -> V_277 . integer . V_278 = 0 ;
V_273 -> V_277 . integer . V_279 = 1 ;
return 0 ;
}
int F_189 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
T_2 V_24 = F_137 ( V_271 ) ;
int V_274 = F_138 ( V_271 ) ;
int V_243 = F_139 ( V_271 ) ;
int V_231 = F_144 ( V_271 ) ;
long * V_284 = V_283 -> V_277 . integer . V_277 ;
if ( V_274 & 1 )
* V_284 ++ = ( F_130 ( V_12 , V_24 , 0 , V_243 , V_231 ) &
V_261 ) ? 0 : 1 ;
if ( V_274 & 2 )
* V_284 = ( F_130 ( V_12 , V_24 , 1 , V_243 , V_231 ) &
V_261 ) ? 0 : 1 ;
return 0 ;
}
int F_190 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
T_2 V_24 = F_137 ( V_271 ) ;
int V_274 = F_138 ( V_271 ) ;
int V_243 = F_139 ( V_271 ) ;
int V_231 = F_144 ( V_271 ) ;
long * V_284 = V_283 -> V_277 . integer . V_277 ;
int V_285 = 0 ;
F_16 ( V_12 ) ;
if ( V_274 & 1 ) {
V_285 = F_131 ( V_12 , V_24 , 0 , V_243 , V_231 ,
V_261 ,
* V_284 ? 0 : V_261 ) ;
V_284 ++ ;
}
if ( V_274 & 2 )
V_285 |= F_131 ( V_12 , V_24 , 1 , V_243 , V_231 ,
V_261 ,
* V_284 ? 0 : V_261 ) ;
F_191 ( V_12 , V_24 ) ;
F_19 ( V_12 ) ;
return V_285 ;
}
int F_192 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
unsigned long V_363 ;
int V_33 ;
F_2 ( & V_12 -> V_187 ) ;
V_363 = V_271 -> V_310 ;
V_271 -> V_310 = V_363 & ~ V_364 ;
V_33 = F_189 ( V_271 , V_283 ) ;
V_271 -> V_310 = V_363 ;
F_4 ( & V_12 -> V_187 ) ;
return V_33 ;
}
int F_193 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
unsigned long V_363 ;
int V_17 , V_365 , V_33 = 0 , V_285 = 0 ;
F_2 ( & V_12 -> V_187 ) ;
V_363 = V_271 -> V_310 ;
V_365 = ( V_363 & V_364 ) >> V_366 ;
for ( V_17 = 0 ; V_17 < V_365 ; V_17 ++ ) {
V_271 -> V_310 = ( V_363 & ~ V_364 ) |
( V_17 << V_366 ) ;
V_33 = F_190 ( V_271 , V_283 ) ;
if ( V_33 < 0 )
break;
V_285 |= V_33 ;
}
V_271 -> V_310 = V_363 ;
F_4 ( & V_12 -> V_187 ) ;
return V_33 < 0 ? V_33 : V_285 ;
}
int F_194 ( struct V_270 * V_271 ,
struct V_272 * V_273 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
struct V_367 * V_137 ;
int V_33 ;
F_2 ( & V_12 -> V_187 ) ;
V_137 = (struct V_367 * ) V_271 -> V_310 ;
V_271 -> V_310 = * V_137 -> V_368 ;
V_33 = V_137 -> V_9 -> V_233 ( V_271 , V_273 ) ;
V_271 -> V_310 = ( long ) V_137 ;
F_4 ( & V_12 -> V_187 ) ;
return V_33 ;
}
int F_195 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
struct V_367 * V_137 ;
int V_33 ;
F_2 ( & V_12 -> V_187 ) ;
V_137 = (struct V_367 * ) V_271 -> V_310 ;
V_271 -> V_310 = * V_137 -> V_368 ;
V_33 = V_137 -> V_9 -> V_369 ( V_271 , V_283 ) ;
V_271 -> V_310 = ( long ) V_137 ;
F_4 ( & V_12 -> V_187 ) ;
return V_33 ;
}
int F_196 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
struct V_367 * V_137 ;
unsigned long * V_370 ;
int V_33 = 0 , V_285 = 0 ;
F_2 ( & V_12 -> V_187 ) ;
V_137 = (struct V_367 * ) V_271 -> V_310 ;
for ( V_370 = V_137 -> V_368 ; * V_370 ; V_370 ++ ) {
V_271 -> V_310 = * V_370 ;
V_33 = V_137 -> V_9 -> V_345 ( V_271 , V_283 ) ;
if ( V_33 < 0 )
break;
V_285 |= V_33 ;
}
V_271 -> V_310 = ( long ) V_137 ;
F_4 ( & V_12 -> V_187 ) ;
return V_33 < 0 ? V_33 : V_285 ;
}
int F_197 ( struct V_270 * V_271 , int V_286 ,
unsigned int V_287 , unsigned int T_5 * V_299 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
struct V_367 * V_137 ;
int V_33 ;
F_2 ( & V_12 -> V_187 ) ;
V_137 = (struct V_367 * ) V_271 -> V_310 ;
V_271 -> V_310 = * V_137 -> V_368 ;
V_33 = V_137 -> V_9 -> V_299 ( V_271 , V_286 , V_287 , V_299 ) ;
V_271 -> V_310 = ( long ) V_137 ;
F_4 ( & V_12 -> V_187 ) ;
return V_33 ;
}
static int F_198 ( struct V_270 * V_271 ,
struct V_272 * V_273 )
{
V_273 -> type = V_371 ;
V_273 -> V_276 = 1 ;
return 0 ;
}
static int F_199 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
V_283 -> V_277 . V_372 . V_373 [ 0 ] = V_374 |
V_375 |
V_376 |
V_377 ;
V_283 -> V_277 . V_372 . V_373 [ 1 ] = V_378 |
V_379 ;
return 0 ;
}
static int F_200 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
V_283 -> V_277 . V_372 . V_373 [ 0 ] = V_374 |
V_375 |
V_380 ;
return 0 ;
}
static int F_201 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
int V_231 = V_271 -> V_310 ;
struct V_191 * V_381 ;
F_2 ( & V_12 -> V_186 ) ;
V_381 = F_29 ( & V_12 -> V_176 , V_231 ) ;
V_283 -> V_277 . V_372 . V_373 [ 0 ] = V_381 -> V_373 & 0xff ;
V_283 -> V_277 . V_372 . V_373 [ 1 ] = ( V_381 -> V_373 >> 8 ) & 0xff ;
V_283 -> V_277 . V_372 . V_373 [ 2 ] = ( V_381 -> V_373 >> 16 ) & 0xff ;
V_283 -> V_277 . V_372 . V_373 [ 3 ] = ( V_381 -> V_373 >> 24 ) & 0xff ;
F_4 ( & V_12 -> V_186 ) ;
return 0 ;
}
static unsigned short F_202 ( unsigned int V_382 )
{
unsigned short V_28 = 0 ;
if ( V_382 & V_374 )
V_28 |= V_383 ;
if ( V_382 & V_375 )
V_28 |= V_384 ;
if ( V_382 & V_374 ) {
if ( ( V_382 & V_385 ) ==
V_380 )
V_28 |= V_386 ;
} else {
if ( ( V_382 & V_387 ) ==
V_376 )
V_28 |= V_386 ;
if ( ! ( V_382 & V_377 ) )
V_28 |= V_388 ;
if ( V_382 & ( V_379 << 8 ) )
V_28 |= V_389 ;
V_28 |= V_382 & ( V_378 << 8 ) ;
}
return V_28 ;
}
static unsigned int F_203 ( unsigned short V_28 )
{
unsigned int V_382 = 0 ;
if ( V_28 & V_384 )
V_382 |= V_375 ;
if ( V_28 & V_383 )
V_382 |= V_374 ;
if ( V_382 & V_374 ) {
if ( V_382 & V_386 )
V_382 |= V_380 ;
} else {
if ( V_28 & V_386 )
V_382 |= V_376 ;
if ( ! ( V_28 & V_388 ) )
V_382 |= V_377 ;
if ( V_28 & V_389 )
V_382 |= ( V_379 << 8 ) ;
V_382 |= V_28 & ( 0x7f << 8 ) ;
}
return V_382 ;
}
static void F_204 ( struct V_11 * V_12 , T_2 V_24 ,
int V_26 , int V_28 )
{
const T_2 * V_390 ;
F_205 ( V_12 , V_24 , 0 , V_26 , V_28 ) ;
V_390 = V_12 -> V_331 ;
if ( ! V_390 )
return;
for (; * V_390 ; V_390 ++ )
F_205 ( V_12 , * V_390 , 0 , V_26 , V_28 ) ;
}
static inline void F_206 ( struct V_11 * V_12 , T_2 V_24 ,
int V_391 , int V_392 )
{
if ( V_391 != - 1 )
F_204 ( V_12 , V_24 , V_393 , V_391 ) ;
if ( V_392 != - 1 )
F_204 ( V_12 , V_24 , V_394 , V_392 ) ;
}
static int F_207 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
int V_231 = V_271 -> V_310 ;
struct V_191 * V_381 ;
T_2 V_24 ;
unsigned short V_28 ;
int V_285 ;
F_2 ( & V_12 -> V_186 ) ;
V_381 = F_29 ( & V_12 -> V_176 , V_231 ) ;
V_24 = V_381 -> V_24 ;
V_381 -> V_373 = V_283 -> V_277 . V_372 . V_373 [ 0 ] |
( ( unsigned int ) V_283 -> V_277 . V_372 . V_373 [ 1 ] << 8 ) |
( ( unsigned int ) V_283 -> V_277 . V_372 . V_373 [ 2 ] << 16 ) |
( ( unsigned int ) V_283 -> V_277 . V_372 . V_373 [ 3 ] << 24 ) ;
V_28 = F_202 ( V_381 -> V_373 ) ;
V_28 |= V_381 -> V_395 & 1 ;
V_285 = V_381 -> V_395 != V_28 ;
V_381 -> V_395 = V_28 ;
if ( V_285 && V_24 != ( T_3 ) - 1 )
F_206 ( V_12 , V_24 , V_28 & 0xff , ( V_28 >> 8 ) & 0xff ) ;
F_4 ( & V_12 -> V_186 ) ;
return V_285 ;
}
static int F_208 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
int V_231 = V_271 -> V_310 ;
struct V_191 * V_381 ;
F_2 ( & V_12 -> V_186 ) ;
V_381 = F_29 ( & V_12 -> V_176 , V_231 ) ;
V_283 -> V_277 . integer . V_277 [ 0 ] = V_381 -> V_395 & V_396 ;
F_4 ( & V_12 -> V_186 ) ;
return 0 ;
}
static inline void F_209 ( struct V_11 * V_12 , T_2 V_24 ,
int V_391 , int V_392 )
{
F_206 ( V_12 , V_24 , V_391 , V_392 ) ;
if ( ( F_36 ( V_12 , V_24 ) & V_397 ) &&
( V_391 & V_396 ) )
F_132 ( V_12 , V_24 , V_240 , 0 ,
V_261 , 0 ) ;
}
static int F_210 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
int V_231 = V_271 -> V_310 ;
struct V_191 * V_381 ;
T_2 V_24 ;
unsigned short V_28 ;
int V_285 ;
F_2 ( & V_12 -> V_186 ) ;
V_381 = F_29 ( & V_12 -> V_176 , V_231 ) ;
V_24 = V_381 -> V_24 ;
V_28 = V_381 -> V_395 & ~ V_396 ;
if ( V_283 -> V_277 . integer . V_277 [ 0 ] )
V_28 |= V_396 ;
V_285 = V_381 -> V_395 != V_28 ;
V_381 -> V_395 = V_28 ;
if ( V_285 && V_24 != ( T_3 ) - 1 )
F_209 ( V_12 , V_24 , V_28 & 0xff , - 1 ) ;
F_4 ( & V_12 -> V_186 ) ;
return V_285 ;
}
int F_211 ( struct V_11 * V_12 ,
T_2 V_398 ,
T_2 V_399 )
{
int V_33 ;
struct V_270 * V_304 ;
struct V_400 * V_401 ;
int V_231 ;
struct V_191 * V_381 ;
V_231 = F_153 ( V_12 , L_69 ) ;
if ( V_231 < 0 ) {
F_14 ( V_30 L_70 ) ;
return - V_185 ;
}
V_381 = F_39 ( & V_12 -> V_176 ) ;
for ( V_401 = V_402 ; V_401 -> V_135 ; V_401 ++ ) {
V_304 = F_186 ( V_401 , V_12 ) ;
if ( ! V_304 )
return - V_78 ;
V_304 -> V_128 . V_247 = V_231 ;
V_304 -> V_310 = V_12 -> V_176 . V_50 - 1 ;
V_33 = F_154 ( V_12 , V_398 , V_304 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_381 -> V_24 = V_399 ;
V_381 -> V_395 = F_23 ( V_12 , V_399 , 0 ,
V_403 , 0 ) ;
V_381 -> V_373 = F_203 ( V_381 -> V_395 ) ;
return 0 ;
}
struct V_191 * F_212 ( struct V_11 * V_12 ,
T_2 V_24 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_176 . V_50 ; V_17 ++ ) {
struct V_191 * V_381 =
F_29 ( & V_12 -> V_176 , V_17 ) ;
if ( V_381 -> V_24 == V_24 )
return V_381 ;
}
return NULL ;
}
void F_213 ( struct V_11 * V_12 , int V_231 )
{
struct V_191 * V_381 ;
F_2 ( & V_12 -> V_186 ) ;
V_381 = F_29 ( & V_12 -> V_176 , V_231 ) ;
V_381 -> V_24 = ( T_3 ) - 1 ;
F_4 ( & V_12 -> V_186 ) ;
}
void F_214 ( struct V_11 * V_12 , int V_231 , T_2 V_24 )
{
struct V_191 * V_381 ;
unsigned short V_28 ;
F_2 ( & V_12 -> V_186 ) ;
V_381 = F_29 ( & V_12 -> V_176 , V_231 ) ;
if ( V_381 -> V_24 != V_24 ) {
V_381 -> V_24 = V_24 ;
V_28 = V_381 -> V_395 ;
F_209 ( V_12 , V_24 , V_28 & 0xff , ( V_28 >> 8 ) & 0xff ) ;
}
F_4 ( & V_12 -> V_186 ) ;
}
static int F_215 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_404 * V_405 = F_136 ( V_271 ) ;
V_283 -> V_277 . integer . V_277 [ 0 ] = V_405 -> V_406 ;
return 0 ;
}
static int F_216 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_404 * V_405 = F_136 ( V_271 ) ;
V_405 -> V_406 = ! ! V_283 -> V_277 . integer . V_277 [ 0 ] ;
return 0 ;
}
int F_217 ( struct V_11 * V_12 ,
struct V_404 * V_405 )
{
if ( ! V_405 -> V_407 )
return 0 ;
return F_154 ( V_12 , V_405 -> V_407 ,
F_186 ( & V_408 , V_405 ) ) ;
}
static int F_218 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
V_283 -> V_277 . integer . V_277 [ 0 ] = V_12 -> V_409 ;
return 0 ;
}
static int F_219 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
T_2 V_24 = V_271 -> V_310 ;
unsigned int V_28 = ! ! V_283 -> V_277 . integer . V_277 [ 0 ] ;
int V_285 ;
F_2 ( & V_12 -> V_186 ) ;
V_285 = V_12 -> V_409 != V_28 ;
if ( V_285 ) {
V_12 -> V_409 = V_28 ;
F_205 ( V_12 , V_24 , 0 ,
V_393 , V_28 ) ;
}
F_4 ( & V_12 -> V_186 ) ;
return V_285 ;
}
static int F_220 ( struct V_270 * V_271 ,
struct V_282 * V_283 )
{
struct V_11 * V_12 = F_136 ( V_271 ) ;
T_2 V_24 = V_271 -> V_310 ;
unsigned short V_28 ;
unsigned int V_382 ;
V_28 = F_23 ( V_12 , V_24 , 0 , V_403 , 0 ) ;
V_382 = F_203 ( V_28 ) ;
V_283 -> V_277 . V_372 . V_373 [ 0 ] = V_382 ;
V_283 -> V_277 . V_372 . V_373 [ 1 ] = V_382 >> 8 ;
V_283 -> V_277 . V_372 . V_373 [ 2 ] = V_382 >> 16 ;
V_283 -> V_277 . V_372 . V_373 [ 3 ] = V_382 >> 24 ;
return 0 ;
}
int F_221 ( struct V_11 * V_12 , T_2 V_24 )
{
int V_33 ;
struct V_270 * V_304 ;
struct V_400 * V_401 ;
int V_231 ;
V_231 = F_153 ( V_12 , L_71 ) ;
if ( V_231 < 0 ) {
F_14 ( V_30 L_72 ) ;
return - V_185 ;
}
for ( V_401 = V_410 ; V_401 -> V_135 ; V_401 ++ ) {
V_304 = F_186 ( V_401 , V_12 ) ;
if ( ! V_304 )
return - V_78 ;
V_304 -> V_310 = V_24 ;
V_33 = F_154 ( V_12 , V_24 , V_304 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_12 -> V_409 =
F_23 ( V_12 , V_24 , 0 ,
V_403 , 0 ) &
V_396 ;
return 0 ;
}
int F_205 ( struct V_11 * V_12 , T_2 V_24 ,
int V_25 , unsigned int V_26 , unsigned int V_27 )
{
int V_33 = F_24 ( V_12 , V_24 , V_25 , V_26 , V_27 ) ;
struct V_189 * V_137 ;
T_1 V_230 ;
if ( V_33 < 0 )
return V_33 ;
V_26 = V_26 | ( V_27 >> 8 ) ;
V_27 &= 0xff ;
V_230 = F_222 ( V_24 , V_26 ) ;
F_2 ( & V_12 -> V_7 -> V_35 ) ;
V_137 = F_114 ( & V_12 -> V_179 , V_230 ) ;
if ( V_137 )
V_137 -> V_28 = V_27 ;
F_4 ( & V_12 -> V_7 -> V_35 ) ;
return 0 ;
}
int F_223 ( struct V_11 * V_12 , T_2 V_24 ,
int V_25 , unsigned int V_26 , unsigned int V_27 )
{
struct V_189 * V_137 ;
T_1 V_230 ;
V_26 = V_26 | ( V_27 >> 8 ) ;
V_27 &= 0xff ;
V_230 = F_222 ( V_24 , V_26 ) ;
F_2 ( & V_12 -> V_7 -> V_35 ) ;
V_137 = F_113 ( & V_12 -> V_179 , V_230 ) ;
if ( V_137 && V_137 -> V_28 == V_27 ) {
F_4 ( & V_12 -> V_7 -> V_35 ) ;
return 0 ;
}
F_4 ( & V_12 -> V_7 -> V_35 ) ;
return F_205 ( V_12 , V_24 , V_25 , V_26 , V_27 ) ;
}
void F_224 ( struct V_11 * V_12 )
{
struct V_189 * V_266 = V_12 -> V_179 . V_229 . V_4 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_179 . V_229 . V_50 ; V_17 ++ , V_266 ++ ) {
T_1 V_230 = V_266 -> V_230 ;
if ( ! V_230 )
continue;
F_24 ( V_12 , F_225 ( V_230 ) , 0 ,
F_226 ( V_230 ) , V_266 -> V_28 ) ;
}
}
void F_227 ( struct V_11 * V_12 ,
const struct V_42 * V_43 )
{
for (; V_43 -> V_24 ; V_43 ++ )
F_205 ( V_12 , V_43 -> V_24 , 0 , V_43 -> V_26 ,
V_43 -> V_44 ) ;
}
void F_228 ( struct V_11 * V_12 , T_2 V_183 ,
unsigned int V_411 ,
bool V_412 )
{
T_2 V_24 = V_12 -> V_156 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_155 ; V_17 ++ , V_24 ++ ) {
unsigned int V_64 = F_36 ( V_12 , V_24 ) ;
if ( ! ( V_64 & V_413 ) )
continue;
if ( V_412 && V_411 == V_414 &&
F_37 ( V_64 ) == V_84 &&
( F_124 ( V_12 , V_24 ) & V_415 ) ) {
int V_416 = F_23 ( V_12 , V_24 , 0 ,
V_417 , 0 ) ;
if ( V_416 & 0x02 )
continue;
}
F_24 ( V_12 , V_24 , 0 , V_418 ,
V_411 ) ;
}
}
static bool F_98 ( struct V_11 * V_12 , T_2 V_183 ,
unsigned int V_411 )
{
int V_419 = F_27 ( V_12 , V_183 , V_420 ) ;
if ( V_419 == - 1 )
return false ;
if ( V_419 & V_411 )
return true ;
else
return false ;
}
static unsigned int F_229 ( struct V_11 * V_12 ,
T_2 V_183 ,
unsigned int V_411 )
{
unsigned long V_421 = V_327 + F_230 ( 500 ) ;
unsigned int V_422 , V_423 ;
for (; ; ) {
V_422 = F_23 ( V_12 , V_183 , 0 ,
V_424 , 0 ) ;
if ( V_422 & V_425 )
break;
V_423 = ( V_422 >> 4 ) & 0x0f ;
if ( V_423 == V_411 )
break;
if ( F_231 ( V_327 , V_421 ) )
break;
F_107 ( 1 ) ;
}
return V_422 ;
}
static unsigned int F_99 ( struct V_11 * V_12 ,
unsigned int V_411 )
{
T_2 V_183 = V_12 -> V_129 ? V_12 -> V_129 : V_12 -> V_130 ;
int V_276 ;
unsigned int V_422 ;
if ( V_411 == V_414 ) {
F_107 ( V_12 -> V_203 ? 10 : 100 ) ;
}
for ( V_276 = 0 ; V_276 < 10 ; V_276 ++ ) {
if ( V_12 -> V_98 . V_426 )
V_12 -> V_98 . V_426 ( V_12 , V_183 ,
V_411 ) ;
else {
F_23 ( V_12 , V_183 , 0 ,
V_418 ,
V_411 ) ;
F_228 ( V_12 , V_183 , V_411 ,
true ) ;
}
V_422 = F_229 ( V_12 , V_183 , V_411 ) ;
if ( ! ( V_422 & V_425 ) )
break;
}
return V_422 ;
}
static void F_232 ( struct V_11 * V_12 )
{
if ( V_12 -> V_427 . V_4 )
F_25 ( V_12 , V_12 -> V_427 . V_4 ) ;
}
static inline void F_232 ( struct V_11 * V_12 ) {}
static unsigned int F_233 ( struct V_11 * V_12 , bool V_428 )
{
unsigned int V_422 ;
V_12 -> V_429 = 1 ;
if ( V_12 -> V_98 . V_430 )
V_12 -> V_98 . V_430 ( V_12 ) ;
F_112 ( V_12 ) ;
V_422 = F_99 ( V_12 , V_414 ) ;
if ( ! V_428 )
F_166 ( & V_12 -> V_173 ) ;
F_161 ( & V_12 -> V_192 ) ;
F_234 ( V_12 ) ;
F_235 ( V_12 ) ;
V_12 -> V_324 = 0 ;
V_12 -> V_325 = 0 ;
V_12 -> V_326 = V_327 ;
F_163 ( & V_12 -> V_192 ) ;
V_12 -> V_429 = 0 ;
return V_422 ;
}
static void F_236 ( struct V_11 * V_12 )
{
V_12 -> V_429 = 1 ;
F_8 ( V_12 ) ;
F_99 ( V_12 , V_205 ) ;
F_82 ( V_12 ) ;
F_84 ( V_12 ) ;
F_232 ( V_12 ) ;
F_237 ( V_12 ) ;
if ( V_12 -> V_98 . V_431 )
V_12 -> V_98 . V_431 ( V_12 ) ;
else {
if ( V_12 -> V_98 . V_432 )
V_12 -> V_98 . V_432 ( V_12 ) ;
F_133 ( V_12 ) ;
F_224 ( V_12 ) ;
}
F_238 ( V_12 ) ;
V_12 -> V_429 = 0 ;
F_19 ( V_12 ) ;
}
int F_239 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_57 (codec, &bus->codec_list, list) {
int V_33 = F_240 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_73
L_74 , V_12 -> V_29 , V_33 ) ;
V_33 = F_165 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30
L_75 ) ;
return V_33 ;
}
}
}
return 0 ;
}
static int F_241 ( struct V_11 * V_12 )
{
int V_17 , V_433 , V_33 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_318 ; V_17 ++ ) {
for ( V_433 = 0 ; V_433 < 2 ; V_433 ++ ) {
struct V_434 * V_317 = V_12 -> V_321 [ V_17 ] . V_317 ;
struct V_435 * V_436 =
& V_12 -> V_321 [ V_17 ] . V_437 [ V_433 ] ;
struct V_438 * V_439 ;
if ( V_12 -> V_321 [ V_17 ] . V_440 )
continue;
if ( ! V_317 || ! V_436 -> V_441 )
continue;
V_33 = F_242 ( V_317 , V_433 ,
V_442 ,
V_436 -> V_443 ,
0 , & V_439 ) ;
if ( V_33 < 0 )
return V_33 ;
V_439 -> V_444 = V_445 ;
}
}
return 0 ;
}
int F_240 ( struct V_11 * V_12 )
{
int V_33 = 0 ;
F_232 ( V_12 ) ;
if ( V_12 -> V_98 . V_432 )
V_33 = V_12 -> V_98 . V_432 ( V_12 ) ;
if ( ! V_33 && V_12 -> V_98 . V_446 )
V_33 = V_12 -> V_98 . V_446 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_241 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
F_238 ( V_12 ) ;
return 0 ;
}
unsigned int F_243 ( unsigned int V_447 ,
unsigned int V_448 ,
unsigned int V_215 ,
unsigned int V_449 ,
unsigned short V_450 )
{
int V_17 ;
unsigned int V_28 = 0 ;
for ( V_17 = 0 ; V_451 [ V_17 ] . V_452 ; V_17 ++ )
if ( V_451 [ V_17 ] . V_452 == V_447 ) {
V_28 = V_451 [ V_17 ] . V_453 ;
break;
}
if ( ! V_451 [ V_17 ] . V_452 ) {
F_97 ( L_76 , V_447 ) ;
return 0 ;
}
if ( V_448 == 0 || V_448 > 8 ) {
F_97 ( L_77 , V_448 ) ;
return 0 ;
}
V_28 |= V_448 - 1 ;
switch ( F_244 ( V_215 ) ) {
case 8 :
V_28 |= V_454 ;
break;
case 16 :
V_28 |= V_455 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_449 >= 32 || V_215 == V_456 )
V_28 |= V_457 ;
else if ( V_449 >= 24 )
V_28 |= V_458 ;
else
V_28 |= V_459 ;
break;
default:
F_97 ( L_78 ,
F_244 ( V_215 ) ) ;
return 0 ;
}
if ( V_450 & V_384 )
V_28 |= V_460 ;
return V_28 ;
}
static unsigned int F_245 ( struct V_11 * V_12 , T_2 V_24 ,
int V_243 )
{
unsigned int V_28 = 0 ;
if ( V_24 != V_12 -> V_129 &&
( F_36 ( V_12 , V_24 ) & V_461 ) )
V_28 = F_27 ( V_12 , V_24 , V_462 ) ;
if ( ! V_28 || V_28 == - 1 )
V_28 = F_27 ( V_12 , V_12 -> V_129 , V_462 ) ;
if ( ! V_28 || V_28 == - 1 )
return 0 ;
return V_28 ;
}
static unsigned int F_246 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_120 ( V_12 , V_24 , 0 , F_247 ( V_24 ) ,
F_245 ) ;
}
static unsigned int F_248 ( struct V_11 * V_12 , T_2 V_24 ,
int V_243 )
{
unsigned int V_322 = F_27 ( V_12 , V_24 , V_463 ) ;
if ( ! V_322 || V_322 == - 1 )
V_322 = F_27 ( V_12 , V_12 -> V_129 , V_463 ) ;
if ( ! V_322 || V_322 == - 1 )
return 0 ;
return V_322 ;
}
static unsigned int F_249 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_120 ( V_12 , V_24 , 0 , F_250 ( V_24 ) ,
F_248 ) ;
}
int F_251 ( struct V_11 * V_12 , T_2 V_24 ,
T_1 * V_464 , T_8 * V_465 , unsigned int * V_466 )
{
unsigned int V_17 , V_28 , V_64 ;
V_64 = F_36 ( V_12 , V_24 ) ;
V_28 = F_246 ( V_12 , V_24 ) ;
if ( V_464 ) {
T_1 V_467 = 0 ;
for ( V_17 = 0 ; V_17 < V_468 ; V_17 ++ ) {
if ( V_28 & ( 1 << V_17 ) )
V_467 |= V_451 [ V_17 ] . V_469 ;
}
if ( V_467 == 0 ) {
F_34 ( V_30 L_79
L_80 ,
V_24 , V_28 ,
( V_64 & V_461 ) ? 1 : 0 ) ;
return - V_72 ;
}
* V_464 = V_467 ;
}
if ( V_465 || V_466 ) {
T_8 V_470 = 0 ;
unsigned int V_322 , V_471 ;
V_322 = F_249 ( V_12 , V_24 ) ;
if ( ! V_322 )
return - V_72 ;
V_471 = 0 ;
if ( V_322 & V_472 ) {
if ( V_28 & V_473 ) {
V_470 |= V_474 ;
V_471 = 8 ;
}
if ( V_28 & V_475 ) {
V_470 |= V_476 ;
V_471 = 16 ;
}
if ( V_64 & V_477 ) {
if ( V_28 & V_478 )
V_470 |= V_479 ;
if ( V_28 & ( V_480 | V_481 ) )
V_470 |= V_482 ;
if ( V_28 & V_481 )
V_471 = 24 ;
else if ( V_28 & V_480 )
V_471 = 20 ;
} else if ( V_28 & ( V_480 | V_481 |
V_478 ) ) {
V_470 |= V_482 ;
if ( V_28 & V_478 )
V_471 = 32 ;
else if ( V_28 & V_481 )
V_471 = 24 ;
else if ( V_28 & V_480 )
V_471 = 20 ;
}
}
#if 0
if (streams & AC_SUPFMT_FLOAT32) {
formats |= SNDRV_PCM_FMTBIT_FLOAT_LE;
if (!bps)
bps = 32;
}
#endif
if ( V_322 == V_483 ) {
V_470 |= V_474 ;
V_471 = 8 ;
}
if ( V_470 == 0 ) {
F_34 ( V_30 L_81
L_82
L_83 ,
V_24 , V_28 ,
( V_64 & V_461 ) ? 1 : 0 ,
V_322 ) ;
return - V_72 ;
}
if ( V_465 )
* V_465 = V_470 ;
if ( V_466 )
* V_466 = V_471 ;
}
return 0 ;
}
int F_252 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_215 )
{
int V_17 ;
unsigned int V_28 = 0 , V_447 , V_437 ;
V_28 = F_246 ( V_12 , V_24 ) ;
if ( ! V_28 )
return 0 ;
V_447 = V_215 & 0xff00 ;
for ( V_17 = 0 ; V_17 < V_468 ; V_17 ++ )
if ( V_451 [ V_17 ] . V_453 == V_447 ) {
if ( V_28 & ( 1 << V_17 ) )
break;
return 0 ;
}
if ( V_17 >= V_468 )
return 0 ;
V_437 = F_249 ( V_12 , V_24 ) ;
if ( ! V_437 )
return 0 ;
if ( V_437 & V_472 ) {
switch ( V_215 & 0xf0 ) {
case 0x00 :
if ( ! ( V_28 & V_473 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_28 & V_475 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_28 & V_480 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_28 & V_481 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_28 & V_478 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_253 ( struct V_435 * V_436 ,
struct V_11 * V_12 ,
struct V_484 * V_485 )
{
return 0 ;
}
static int F_254 ( struct V_435 * V_436 ,
struct V_11 * V_12 ,
unsigned int V_209 ,
unsigned int V_215 ,
struct V_484 * V_485 )
{
F_108 ( V_12 , V_436 -> V_24 , V_209 , 0 , V_215 ) ;
return 0 ;
}
static int F_255 ( struct V_435 * V_436 ,
struct V_11 * V_12 ,
struct V_484 * V_485 )
{
F_256 ( V_12 , V_436 -> V_24 ) ;
return 0 ;
}
static int F_257 ( struct V_11 * V_12 ,
struct V_435 * V_233 )
{
int V_33 ;
if ( V_233 -> V_24 && ( ! V_233 -> V_467 || ! V_233 -> V_470 ) ) {
V_33 = F_251 ( V_12 , V_233 -> V_24 ,
V_233 -> V_467 ? NULL : & V_233 -> V_467 ,
V_233 -> V_470 ? NULL : & V_233 -> V_470 ,
V_233 -> V_449 ? NULL : & V_233 -> V_449 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_233 -> V_9 . V_486 == NULL )
V_233 -> V_9 . V_486 = F_253 ;
if ( V_233 -> V_9 . V_487 == NULL )
V_233 -> V_9 . V_487 = F_253 ;
if ( V_233 -> V_9 . V_488 == NULL ) {
if ( F_35 ( ! V_233 -> V_24 ) )
return - V_58 ;
V_233 -> V_9 . V_488 = F_254 ;
}
if ( V_233 -> V_9 . V_489 == NULL ) {
if ( F_35 ( ! V_233 -> V_24 ) )
return - V_58 ;
V_233 -> V_9 . V_489 = F_255 ;
}
return 0 ;
}
int F_258 ( struct V_11 * V_12 ,
struct V_435 * V_436 ,
unsigned int V_437 ,
unsigned int V_215 ,
struct V_484 * V_485 )
{
int V_265 ;
F_2 ( & V_12 -> V_7 -> V_119 ) ;
V_265 = V_436 -> V_9 . V_488 ( V_436 , V_12 , V_437 , V_215 , V_485 ) ;
if ( V_265 >= 0 )
F_111 ( V_12 ) ;
F_4 ( & V_12 -> V_7 -> V_119 ) ;
return V_265 ;
}
void F_259 ( struct V_11 * V_12 ,
struct V_435 * V_436 ,
struct V_484 * V_485 )
{
F_2 ( & V_12 -> V_7 -> V_119 ) ;
V_436 -> V_9 . V_489 ( V_436 , V_12 , V_485 ) ;
F_4 ( & V_12 -> V_7 -> V_119 ) ;
}
static int F_260 ( struct V_6 * V_7 , int type )
{
static int V_490 [ V_491 ] [ 5 ] = {
[ V_492 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_493 ] = { 1 , - 1 } ,
[ V_494 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_495 ] = { 6 , - 1 } ,
} ;
int V_17 ;
if ( type >= V_491 ) {
F_34 ( V_75 L_84 , type ) ;
return - V_58 ;
}
for ( V_17 = 0 ; V_490 [ type ] [ V_17 ] >= 0 ; V_17 ++ )
if ( ! F_261 ( V_490 [ type ] [ V_17 ] , V_7 -> V_328 ) )
return V_490 [ type ] [ V_17 ] ;
for ( V_17 = 10 ; V_17 < 32 ; V_17 ++ ) {
if ( ! F_261 ( V_17 , V_7 -> V_328 ) )
return V_17 ;
}
F_34 ( V_75 L_85 ,
V_496 [ type ] ) ;
return - V_497 ;
}
static int F_262 ( struct V_11 * V_12 , struct V_319 * V_317 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_435 * V_233 ;
int V_437 , V_33 ;
if ( F_35 ( ! V_317 -> V_135 ) )
return - V_58 ;
for ( V_437 = 0 ; V_437 < 2 ; V_437 ++ ) {
V_233 = & V_317 -> V_437 [ V_437 ] ;
if ( V_233 -> V_441 ) {
V_33 = F_257 ( V_12 , V_233 ) ;
if ( V_33 < 0 )
return V_33 ;
}
}
return V_7 -> V_9 . V_498 ( V_7 , V_12 , V_317 ) ;
}
int F_263 ( struct V_11 * V_12 )
{
unsigned int V_317 ;
int V_33 ;
if ( ! V_12 -> V_318 ) {
if ( ! V_12 -> V_98 . V_499 )
return 0 ;
V_33 = V_12 -> V_98 . V_499 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_86
L_74 , V_12 -> V_29 , V_33 ) ;
V_33 = F_165 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30
L_75 ) ;
return V_33 ;
}
}
}
for ( V_317 = 0 ; V_317 < V_12 -> V_318 ; V_317 ++ ) {
struct V_319 * V_320 = & V_12 -> V_321 [ V_317 ] ;
int V_500 ;
if ( ! V_320 -> V_437 [ 0 ] . V_441 && ! V_320 -> V_437 [ 1 ] . V_441 )
continue;
if ( ! V_320 -> V_317 ) {
V_500 = F_260 ( V_12 -> V_7 , V_320 -> V_501 ) ;
if ( V_500 < 0 )
continue;
V_320 -> V_103 = V_500 ;
V_33 = F_262 ( V_12 , V_320 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_87
L_88 ,
V_500 , V_12 -> V_29 ) ;
continue;
}
}
}
return 0 ;
}
int F_264 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_57 (codec, &bus->codec_list, list) {
int V_33 = F_263 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
}
return 0 ;
}
int F_265 ( struct V_11 * V_12 ,
int V_502 , const char * const * V_503 ,
const struct V_504 * V_125 )
{
if ( V_12 -> V_117 && V_503 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_502 ; V_17 ++ ) {
if ( V_503 [ V_17 ] &&
! strcmp ( V_12 -> V_117 , V_503 [ V_17 ] ) ) {
F_21 ( V_505 L_89
L_90 , V_503 [ V_17 ] ) ;
return V_17 ;
}
}
}
if ( ! V_12 -> V_7 -> V_116 || ! V_125 )
return - 1 ;
V_125 = F_266 ( V_12 -> V_7 -> V_116 , V_125 ) ;
if ( ! V_125 )
return - 1 ;
if ( V_125 -> V_277 >= 0 && V_125 -> V_277 < V_502 ) {
#ifdef F_267
char V_139 [ 10 ] ;
const char * V_506 = NULL ;
if ( V_503 )
V_506 = V_503 [ V_125 -> V_277 ] ;
if ( ! V_506 ) {
sprintf ( V_139 , L_91 , V_125 -> V_277 ) ;
V_506 = V_139 ;
}
F_97 ( V_505 L_92
L_93 ,
V_506 , V_125 -> V_507 , V_125 -> V_307 ,
( V_125 -> V_135 ? V_125 -> V_135 : L_94 ) ) ;
#endif
return V_125 -> V_277 ;
}
return - 1 ;
}
int F_268 ( struct V_11 * V_12 ,
int V_502 , const char * const * V_503 ,
const struct V_504 * V_125 )
{
const struct V_504 * V_224 ;
for ( V_224 = V_125 ; V_224 -> V_507 ; V_224 ++ ) {
unsigned int V_63 = 0xffff0000 | V_224 -> V_508 ;
unsigned int V_128 = ( V_224 -> V_307 | ( V_224 -> V_507 << 16 ) ) & V_63 ;
if ( ( V_12 -> V_196 & V_63 ) == V_128 )
break;
}
if ( ! V_224 -> V_507 )
return - 1 ;
V_125 = V_224 ;
if ( V_125 -> V_277 >= 0 && V_125 -> V_277 < V_502 ) {
#ifdef F_267
char V_139 [ 10 ] ;
const char * V_506 = NULL ;
if ( V_503 )
V_506 = V_503 [ V_125 -> V_277 ] ;
if ( ! V_506 ) {
sprintf ( V_139 , L_91 , V_125 -> V_277 ) ;
V_506 = V_139 ;
}
F_97 ( V_505 L_92
L_93 ,
V_506 , V_125 -> V_507 , V_125 -> V_307 ,
( V_125 -> V_135 ? V_125 -> V_135 : L_94 ) ) ;
#endif
return V_125 -> V_277 ;
}
return - 1 ;
}
int F_269 ( struct V_11 * V_12 ,
const struct V_400 * V_509 )
{
int V_33 ;
for (; V_509 -> V_135 ; V_509 ++ ) {
struct V_270 * V_304 ;
int V_29 = 0 , V_231 = 0 ;
if ( V_509 -> V_302 == - 1 )
continue;
for (; ; ) {
V_304 = F_186 ( V_509 , V_12 ) ;
if ( ! V_304 )
return - V_78 ;
if ( V_29 > 0 )
V_304 -> V_128 . V_103 = V_29 ;
if ( V_231 > 0 )
V_304 -> V_128 . V_247 = V_231 ;
V_33 = F_154 ( V_12 , 0 , V_304 ) ;
if ( ! V_33 )
break;
if ( ! V_29 && V_12 -> V_29 )
V_29 = V_12 -> V_29 ;
else if ( ! V_231 && ! V_509 -> V_247 ) {
V_231 = F_153 ( V_12 ,
V_509 -> V_135 ) ;
if ( V_231 <= 0 )
return V_33 ;
} else
return V_33 ;
}
}
return 0 ;
}
static void V_193 ( struct V_94 * V_93 )
{
struct V_11 * V_12 =
F_45 ( V_93 , struct V_11 , V_173 . V_93 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
unsigned int V_422 ;
F_161 ( & V_12 -> V_192 ) ;
if ( V_12 -> V_325 > 0 ) {
F_163 ( & V_12 -> V_192 ) ;
return;
}
if ( ! V_12 -> V_324 || V_12 -> V_510 ) {
V_12 -> V_325 = 0 ;
F_163 ( & V_12 -> V_192 ) ;
return;
}
F_163 ( & V_12 -> V_192 ) ;
V_422 = F_233 ( V_12 , true ) ;
V_12 -> V_177 = 0 ;
if ( ! V_7 -> V_202 && ( V_422 & V_511 ) ) {
V_12 -> V_177 = 1 ;
F_7 ( V_7 , false ) ;
}
}
static void F_8 ( struct V_11 * V_12 )
{
F_161 ( & V_12 -> V_192 ) ;
V_12 -> V_510 ++ ;
V_12 -> V_324 = 1 ;
V_12 -> V_326 = V_327 ;
F_163 ( & V_12 -> V_192 ) ;
}
void F_234 ( struct V_11 * V_12 )
{
unsigned long V_512 = V_327 - V_12 -> V_326 ;
if ( V_12 -> V_324 )
V_12 -> V_513 += V_512 ;
else
V_12 -> V_514 += V_512 ;
V_12 -> V_326 += V_512 ;
}
static void F_270 ( struct V_11 * V_12 , bool V_515 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
if ( ( V_12 -> V_324 || V_12 -> V_325 > 0 ) &&
! ( V_515 && V_12 -> V_325 < 0 ) )
return;
F_163 ( & V_12 -> V_192 ) ;
F_166 ( & V_12 -> V_173 ) ;
F_161 ( & V_12 -> V_192 ) ;
if ( V_12 -> V_324 ) {
if ( V_12 -> V_325 < 0 )
V_12 -> V_325 = 0 ;
return;
}
F_271 ( V_12 ) ;
F_234 ( V_12 ) ;
V_12 -> V_324 = 1 ;
V_12 -> V_326 = V_327 ;
V_12 -> V_325 = 1 ;
F_163 ( & V_12 -> V_192 ) ;
if ( V_12 -> V_177 ) {
V_12 -> V_177 = 0 ;
F_7 ( V_7 , true ) ;
}
F_236 ( V_12 ) ;
F_161 ( & V_12 -> V_192 ) ;
V_12 -> V_325 = 0 ;
}
static void F_272 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_324 || V_12 -> V_510 || V_12 -> V_325 )
return;
if ( V_118 ( V_12 ) ) {
V_12 -> V_325 = - 1 ;
F_273 ( V_12 -> V_7 -> V_92 , & V_12 -> V_173 ,
F_230 ( V_118 ( V_12 ) * 1000 ) ) ;
}
}
void F_274 ( struct V_11 * V_12 , int V_512 , bool V_516 )
{
F_161 ( & V_12 -> V_192 ) ;
V_12 -> V_510 += V_512 ;
F_275 ( V_12 ) ;
if ( V_512 > 0 )
F_270 ( V_12 , V_516 ) ;
else
F_272 ( V_12 ) ;
F_163 ( & V_12 -> V_192 ) ;
}
int F_276 ( struct V_11 * V_12 ,
struct V_517 * V_518 ,
T_2 V_24 )
{
const struct V_519 * V_51 ;
int V_246 , V_520 ;
if ( ! V_518 -> V_521 )
return 0 ;
for ( V_51 = V_518 -> V_521 ; V_51 -> V_24 ; V_51 ++ ) {
if ( V_51 -> V_24 == V_24 )
break;
}
if ( ! V_51 -> V_24 )
return 0 ;
for ( V_51 = V_518 -> V_521 ; V_51 -> V_24 ; V_51 ++ ) {
for ( V_246 = 0 ; V_246 < 2 ; V_246 ++ ) {
V_520 = F_130 ( V_12 , V_51 -> V_24 , V_246 , V_51 -> V_243 ,
V_51 -> V_231 ) ;
if ( ! ( V_520 & V_261 ) && V_520 > 0 ) {
if ( ! V_518 -> V_324 ) {
V_518 -> V_324 = 1 ;
F_16 ( V_12 ) ;
}
return 1 ;
}
}
}
if ( V_518 -> V_324 ) {
V_518 -> V_324 = 0 ;
F_19 ( V_12 ) ;
}
return 0 ;
}
int F_277 ( struct V_11 * V_12 ,
struct V_272 * V_273 ,
const struct V_522 * V_523 ,
int V_524 )
{
V_273 -> type = V_352 ;
V_273 -> V_276 = 1 ;
V_273 -> V_277 . V_353 . V_312 = V_524 ;
if ( V_273 -> V_277 . V_353 . V_306 >= V_524 )
V_273 -> V_277 . V_353 . V_306 = V_524 - 1 ;
sprintf ( V_273 -> V_277 . V_353 . V_135 , L_95 ,
V_523 [ V_273 -> V_277 . V_353 . V_306 ] . V_448 ) ;
return 0 ;
}
int F_278 ( struct V_11 * V_12 ,
struct V_282 * V_283 ,
const struct V_522 * V_523 ,
int V_524 ,
int V_525 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_524 ; V_17 ++ ) {
if ( V_525 == V_523 [ V_17 ] . V_448 ) {
V_283 -> V_277 . V_353 . V_306 [ 0 ] = V_17 ;
break;
}
}
return 0 ;
}
int F_279 ( struct V_11 * V_12 ,
struct V_282 * V_283 ,
const struct V_522 * V_523 ,
int V_524 ,
int * V_526 )
{
unsigned int V_527 ;
V_527 = V_283 -> V_277 . V_353 . V_306 [ 0 ] ;
if ( V_527 >= V_524 )
return - V_58 ;
if ( * V_526 == V_523 [ V_527 ] . V_448 )
return 0 ;
* V_526 = V_523 [ V_527 ] . V_448 ;
if ( V_523 [ V_527 ] . V_528 )
F_227 ( V_12 , V_523 [ V_527 ] . V_528 ) ;
return 1 ;
}
int F_280 ( const struct V_529 * V_530 ,
struct V_272 * V_273 )
{
unsigned int V_247 ;
V_273 -> type = V_352 ;
V_273 -> V_276 = 1 ;
V_273 -> V_277 . V_353 . V_312 = V_530 -> V_531 ;
if ( ! V_530 -> V_531 )
return 0 ;
V_247 = V_273 -> V_277 . V_353 . V_306 ;
if ( V_247 >= V_530 -> V_531 )
V_247 = V_530 -> V_531 - 1 ;
strcpy ( V_273 -> V_277 . V_353 . V_135 , V_530 -> V_312 [ V_247 ] . V_532 ) ;
return 0 ;
}
int F_281 ( struct V_11 * V_12 ,
const struct V_529 * V_530 ,
struct V_282 * V_283 ,
T_2 V_24 ,
unsigned int * V_533 )
{
unsigned int V_231 ;
if ( ! V_530 -> V_531 )
return 0 ;
V_231 = V_283 -> V_277 . V_353 . V_306 [ 0 ] ;
if ( V_231 >= V_530 -> V_531 )
V_231 = V_530 -> V_531 - 1 ;
if ( * V_533 == V_231 )
return 0 ;
F_205 ( V_12 , V_24 , 0 , V_534 ,
V_530 -> V_312 [ V_231 ] . V_247 ) ;
* V_533 = V_231 ;
return 1 ;
}
static void F_282 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_209 , unsigned int V_215 )
{
struct V_191 * V_381 = F_212 ( V_12 , V_24 ) ;
if ( V_12 -> V_332 && ( V_381 -> V_395 & V_396 ) )
F_206 ( V_12 , V_24 ,
V_381 -> V_395 & ~ V_396 & 0xff ,
- 1 ) ;
F_108 ( V_12 , V_24 , V_209 , 0 , V_215 ) ;
if ( V_12 -> V_331 ) {
const T_2 * V_390 ;
for ( V_390 = V_12 -> V_331 ; * V_390 ; V_390 ++ )
F_108 ( V_12 , * V_390 , V_209 , 0 ,
V_215 ) ;
}
if ( V_12 -> V_332 && ( V_381 -> V_395 & V_396 ) )
F_206 ( V_12 , V_24 ,
V_381 -> V_395 & 0xff , - 1 ) ;
}
static void F_283 ( struct V_11 * V_12 , T_2 V_24 )
{
F_256 ( V_12 , V_24 ) ;
if ( V_12 -> V_331 ) {
const T_2 * V_390 ;
for ( V_390 = V_12 -> V_331 ; * V_390 ; V_390 ++ )
F_256 ( V_12 , * V_390 ) ;
}
}
void F_284 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
if ( ! V_7 )
return;
F_57 (codec, &bus->codec_list, list) {
if ( F_285 ( V_12 ) &&
V_12 -> V_98 . V_535 )
V_12 -> V_98 . V_535 ( V_12 ) ;
}
}
int F_286 ( struct V_11 * V_12 ,
struct V_404 * V_405 )
{
F_2 ( & V_12 -> V_186 ) ;
if ( V_405 -> V_536 == V_537 )
F_283 ( V_12 , V_405 -> V_407 ) ;
V_405 -> V_536 = V_538 ;
F_4 ( & V_12 -> V_186 ) ;
return 0 ;
}
int F_287 ( struct V_11 * V_12 ,
struct V_404 * V_405 ,
unsigned int V_209 ,
unsigned int V_215 ,
struct V_484 * V_485 )
{
F_2 ( & V_12 -> V_186 ) ;
F_282 ( V_12 , V_405 -> V_407 , V_209 , V_215 ) ;
F_4 ( & V_12 -> V_186 ) ;
return 0 ;
}
int F_288 ( struct V_11 * V_12 ,
struct V_404 * V_405 )
{
F_2 ( & V_12 -> V_186 ) ;
F_283 ( V_12 , V_405 -> V_407 ) ;
F_4 ( & V_12 -> V_186 ) ;
return 0 ;
}
int F_289 ( struct V_11 * V_12 ,
struct V_404 * V_405 )
{
F_2 ( & V_12 -> V_186 ) ;
V_405 -> V_536 = 0 ;
F_4 ( & V_12 -> V_186 ) ;
return 0 ;
}
int F_290 ( struct V_11 * V_12 ,
struct V_404 * V_405 ,
struct V_484 * V_485 ,
struct V_435 * V_436 )
{
struct V_539 * V_540 = V_485 -> V_540 ;
V_540 -> V_541 . V_443 = V_405 -> V_525 ;
if ( V_405 -> V_407 ) {
if ( ! V_405 -> V_542 ) {
V_405 -> V_542 = V_436 -> V_467 ;
V_405 -> V_543 = V_436 -> V_470 ;
V_405 -> V_544 = V_436 -> V_449 ;
} else {
V_540 -> V_541 . V_467 = V_405 -> V_542 ;
V_540 -> V_541 . V_470 = V_405 -> V_543 ;
V_436 -> V_449 = V_405 -> V_544 ;
}
if ( ! V_405 -> V_545 ) {
F_251 ( V_12 , V_405 -> V_407 ,
& V_405 -> V_545 ,
& V_405 -> V_546 ,
& V_405 -> V_547 ) ;
}
F_2 ( & V_12 -> V_186 ) ;
if ( V_405 -> V_406 ) {
if ( ( V_540 -> V_541 . V_467 & V_405 -> V_545 ) &&
( V_540 -> V_541 . V_470 & V_405 -> V_546 ) ) {
V_540 -> V_541 . V_467 &= V_405 -> V_545 ;
V_540 -> V_541 . V_470 &= V_405 -> V_546 ;
if ( V_405 -> V_547 < V_436 -> V_449 )
V_436 -> V_449 = V_405 -> V_547 ;
} else {
V_405 -> V_406 = 0 ;
}
}
F_4 ( & V_12 -> V_186 ) ;
}
return F_291 ( V_485 -> V_540 , 0 ,
V_548 , 2 ) ;
}
int F_292 ( struct V_11 * V_12 ,
struct V_404 * V_405 ,
unsigned int V_209 ,
unsigned int V_215 ,
struct V_484 * V_485 )
{
const T_2 * V_175 = V_405 -> V_549 ;
int V_274 = V_485 -> V_540 -> V_448 ;
struct V_191 * V_381 ;
int V_17 ;
F_2 ( & V_12 -> V_186 ) ;
V_381 = F_212 ( V_12 , V_405 -> V_407 ) ;
if ( V_405 -> V_407 && V_405 -> V_406 &&
V_405 -> V_536 != V_538 ) {
if ( V_274 == 2 &&
F_252 ( V_12 , V_405 -> V_407 ,
V_215 ) &&
! ( V_381 -> V_373 & V_375 ) ) {
V_405 -> V_536 = V_537 ;
F_282 ( V_12 , V_405 -> V_407 ,
V_209 , V_215 ) ;
} else {
V_405 -> V_536 = 0 ;
F_283 ( V_12 , V_405 -> V_407 ) ;
}
}
F_4 ( & V_12 -> V_186 ) ;
F_108 ( V_12 , V_175 [ V_550 ] , V_209 ,
0 , V_215 ) ;
if ( ! V_405 -> V_551 &&
V_405 -> V_552 && V_405 -> V_552 != V_175 [ V_550 ] )
F_108 ( V_12 , V_405 -> V_552 , V_209 ,
0 , V_215 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_405 -> V_553 ) ; V_17 ++ )
if ( ! V_405 -> V_551 && V_405 -> V_553 [ V_17 ] )
F_108 ( V_12 ,
V_405 -> V_553 [ V_17 ] ,
V_209 , 0 , V_215 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_405 -> V_554 ) ; V_17 ++ )
if ( ! V_405 -> V_551 && V_405 -> V_554 [ V_17 ] )
F_108 ( V_12 ,
V_405 -> V_554 [ V_17 ] ,
V_209 , 0 , V_215 ) ;
for ( V_17 = 1 ; V_17 < V_405 -> V_555 ; V_17 ++ ) {
if ( V_274 >= ( V_17 + 1 ) * 2 )
F_108 ( V_12 , V_175 [ V_17 ] , V_209 ,
V_17 * 2 , V_215 ) ;
else if ( ! V_405 -> V_551 )
F_108 ( V_12 , V_175 [ V_17 ] , V_209 ,
0 , V_215 ) ;
}
return 0 ;
}
int F_293 ( struct V_11 * V_12 ,
struct V_404 * V_405 )
{
const T_2 * V_175 = V_405 -> V_549 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_405 -> V_555 ; V_17 ++ )
F_256 ( V_12 , V_175 [ V_17 ] ) ;
if ( V_405 -> V_552 )
F_256 ( V_12 , V_405 -> V_552 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_405 -> V_553 ) ; V_17 ++ )
if ( V_405 -> V_553 [ V_17 ] )
F_256 ( V_12 ,
V_405 -> V_553 [ V_17 ] ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_405 -> V_554 ) ; V_17 ++ )
if ( V_405 -> V_554 [ V_17 ] )
F_256 ( V_12 ,
V_405 -> V_554 [ V_17 ] ) ;
F_2 ( & V_12 -> V_186 ) ;
if ( V_405 -> V_407 && V_405 -> V_536 == V_537 ) {
F_283 ( V_12 , V_405 -> V_407 ) ;
V_405 -> V_536 = 0 ;
}
F_4 ( & V_12 -> V_186 ) ;
return 0 ;
}
unsigned int F_294 ( struct V_11 * V_12 , T_2 V_159 )
{
unsigned int V_556 ;
unsigned int V_211 ;
V_211 = F_23 ( V_12 , V_159 , 0 ,
V_164 , 0 ) ;
V_556 = F_124 ( V_12 , V_159 ) ;
V_556 = ( V_556 & V_557 ) >> V_558 ;
if ( ( V_556 & V_559 ) && V_211 != V_560 )
return V_561 ;
else if ( V_556 & V_562 )
return V_563 ;
else if ( V_556 & V_564 )
return V_565 ;
else if ( V_556 & V_566 )
return V_567 ;
return V_568 ;
}
int F_295 ( struct V_11 * V_12 , T_2 V_159 ,
unsigned int V_28 , bool V_569 )
{
if ( V_28 ) {
unsigned int V_570 = F_124 ( V_12 , V_159 ) ;
if ( V_570 && ( V_28 & V_571 ) ) {
if ( ! ( V_570 & V_572 ) )
V_28 &= ~ ( V_571 | V_573 ) ;
else if ( ( V_28 & V_573 ) &&
! ( V_570 & V_574 ) )
V_28 &= ~ V_573 ;
}
if ( V_570 && ( V_28 & V_575 ) ) {
if ( ! ( V_570 & V_576 ) )
V_28 &= ~ ( V_575 | V_577 ) ;
}
}
if ( V_569 )
return F_223 ( V_12 , V_159 , 0 ,
V_169 , V_28 ) ;
else
return F_24 ( V_12 , V_159 , 0 ,
V_169 , V_28 ) ;
}
int F_296 ( struct V_529 * V_530 , const char * V_532 ,
int V_247 , int * V_578 )
{
int V_17 , V_579 = 0 ;
if ( V_530 -> V_531 >= V_82 ) {
F_21 ( V_30 L_96 ) ;
return - V_58 ;
}
for ( V_17 = 0 ; V_17 < V_530 -> V_531 ; V_17 ++ ) {
if ( ! strncmp ( V_532 , V_530 -> V_312 [ V_17 ] . V_532 , strlen ( V_532 ) ) )
V_579 ++ ;
}
if ( V_578 )
* V_578 = V_579 ;
if ( V_579 > 0 )
snprintf ( V_530 -> V_312 [ V_530 -> V_531 ] . V_532 ,
sizeof( V_530 -> V_312 [ V_530 -> V_531 ] . V_532 ) ,
L_97 , V_532 , V_579 ) ;
else
F_297 ( V_530 -> V_312 [ V_530 -> V_531 ] . V_532 , V_532 ,
sizeof( V_530 -> V_312 [ V_530 -> V_531 ] . V_532 ) ) ;
V_530 -> V_312 [ V_530 -> V_531 ] . V_247 = V_247 ;
V_530 -> V_531 ++ ;
return 0 ;
}
int F_298 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_57 (codec, &bus->codec_list, list) {
if ( F_285 ( V_12 ) )
F_233 ( V_12 , false ) ;
}
return 0 ;
}
int F_299 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_57 (codec, &bus->codec_list, list) {
F_236 ( V_12 ) ;
}
return 0 ;
}
void * F_39 ( struct V_47 * V_48 )
{
if ( F_35 ( ! V_48 -> V_580 ) )
return NULL ;
if ( V_48 -> V_50 >= V_48 -> V_581 ) {
int V_582 = V_48 -> V_581 + V_48 -> V_583 ;
int V_287 = ( V_582 + 1 ) * V_48 -> V_580 ;
int V_584 = V_48 -> V_581 * V_48 -> V_580 ;
void * V_585 ;
if ( F_35 ( V_582 >= 4096 ) )
return NULL ;
V_585 = F_300 ( V_48 -> V_4 , V_287 , V_100 ) ;
if ( ! V_585 )
return NULL ;
memset ( V_585 + V_584 , 0 , V_287 - V_584 ) ;
V_48 -> V_4 = V_585 ;
V_48 -> V_581 = V_582 ;
}
return F_29 ( V_48 , V_48 -> V_50 ++ ) ;
}
void F_86 ( struct V_47 * V_48 )
{
F_51 ( V_48 -> V_4 ) ;
V_48 -> V_50 = 0 ;
V_48 -> V_581 = 0 ;
V_48 -> V_4 = NULL ;
}
void F_301 ( int V_317 , char * V_229 , int V_586 )
{
static unsigned int V_587 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_17 , V_588 ;
for ( V_17 = 0 , V_588 = 0 ; V_17 < F_10 ( V_587 ) ; V_17 ++ )
if ( V_317 & ( V_473 << V_17 ) )
V_588 += snprintf ( V_229 + V_588 , V_586 - V_588 , L_98 , V_587 [ V_17 ] ) ;
V_229 [ V_588 ] = '\0' ;
}
