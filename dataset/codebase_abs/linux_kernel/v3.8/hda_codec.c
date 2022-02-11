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
int F_77 ( struct V_11 * V_12 , struct V_47 * V_4 ,
T_2 V_24 , unsigned int V_13 )
{
struct V_158 * V_159 ;
if ( F_37 ( F_36 ( V_12 , V_24 ) ) != V_84 )
return - V_58 ;
V_159 = F_76 ( V_12 , V_4 , V_24 ) ;
if ( ! V_159 ) {
V_159 = F_39 ( V_4 ) ;
if ( ! V_159 )
return - V_78 ;
V_159 -> V_24 = V_24 ;
}
V_159 -> V_13 = V_13 ;
return 0 ;
}
int F_78 ( struct V_11 * V_12 ,
T_2 V_24 , unsigned int V_13 )
{
return F_77 ( V_12 , & V_12 -> V_165 , V_24 , V_13 ) ;
}
unsigned int F_79 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_158 * V_159 ;
#ifdef F_80
V_159 = F_76 ( V_12 , & V_12 -> V_166 , V_24 ) ;
if ( V_159 )
return V_159 -> V_13 ;
#endif
V_159 = F_76 ( V_12 , & V_12 -> V_165 , V_24 ) ;
if ( V_159 )
return V_159 -> V_13 ;
V_159 = F_76 ( V_12 , & V_12 -> V_161 , V_24 ) ;
if ( V_159 )
return V_159 -> V_13 ;
return 0 ;
}
void F_81 ( struct V_11 * V_12 )
{
int V_17 ;
if ( V_12 -> V_7 -> V_105 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_161 . V_50 ; V_17 ++ ) {
struct V_158 * V_159 = F_29 ( & V_12 -> V_161 , V_17 ) ;
F_23 ( V_12 , V_159 -> V_24 , 0 ,
V_167 , 0 ) ;
}
V_12 -> V_168 = 1 ;
}
static void F_82 ( struct V_11 * V_12 )
{
int V_17 ;
if ( ! V_12 -> V_168 )
return;
if ( V_12 -> V_7 -> V_105 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_161 . V_50 ; V_17 ++ ) {
struct V_158 * V_159 = F_29 ( & V_12 -> V_161 , V_17 ) ;
F_24 ( V_12 , V_159 -> V_24 , 0 ,
V_167 ,
V_159 -> V_163 ) ;
}
V_12 -> V_168 = 0 ;
}
static void F_83 ( struct V_94 * V_93 )
{
struct V_11 * V_12 =
F_45 ( V_93 , struct V_11 , V_169 . V_93 ) ;
if ( ! V_12 -> V_170 )
return;
F_84 ( V_12 ) ;
F_85 ( V_12 ) ;
F_86 ( V_12 -> V_7 -> V_92 , & V_12 -> V_169 ,
V_12 -> V_170 ) ;
}
static void F_87 ( struct V_11 * V_12 )
{
F_88 ( & V_12 -> V_165 ) ;
#ifdef F_80
F_88 ( & V_12 -> V_166 ) ;
#endif
F_88 ( & V_12 -> V_161 ) ;
}
static struct V_171 *
F_89 ( struct V_11 * V_12 , T_2 V_24 )
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
F_90 ( & V_12 -> V_169 ) ;
F_91 ( V_12 ) ;
F_87 ( V_12 ) ;
#ifdef F_92
F_93 ( & V_12 -> V_173 ) ;
F_50 ( V_12 -> V_7 -> V_92 ) ;
#endif
F_6 ( & V_12 -> V_4 ) ;
F_88 ( & V_12 -> V_174 ) ;
F_88 ( & V_12 -> V_175 ) ;
F_88 ( & V_12 -> V_172 ) ;
F_88 ( & V_12 -> V_55 ) ;
F_88 ( & V_12 -> V_176 ) ;
V_12 -> V_7 -> V_97 [ V_12 -> V_29 ] = NULL ;
if ( V_12 -> V_98 . free )
V_12 -> V_98 . free ( V_12 ) ;
#ifdef F_92
if ( ! V_12 -> V_177 )
F_7 ( V_12 -> V_7 , false ) ;
#endif
F_68 ( V_12 -> V_127 ) ;
F_94 ( & V_12 -> V_178 ) ;
F_94 ( & V_12 -> V_179 ) ;
F_51 ( V_12 -> V_140 ) ;
F_51 ( V_12 -> V_143 ) ;
F_51 ( V_12 -> V_117 ) ;
F_51 ( V_12 -> V_64 ) ;
F_51 ( V_12 ) ;
}
int F_95 ( struct V_6 * V_7 ,
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
F_96 ( & V_12 -> V_178 , sizeof( struct V_188 ) ) ;
F_96 ( & V_12 -> V_179 , sizeof( struct V_189 ) ) ;
F_97 ( & V_12 -> V_174 , sizeof( struct V_190 ) , 32 ) ;
F_97 ( & V_12 -> V_175 , sizeof( struct V_190 ) , 32 ) ;
F_97 ( & V_12 -> V_161 , sizeof( struct V_158 ) , 16 ) ;
F_97 ( & V_12 -> V_165 , sizeof( struct V_158 ) , 16 ) ;
F_97 ( & V_12 -> V_172 , sizeof( struct V_171 ) , 8 ) ;
F_97 ( & V_12 -> V_55 , sizeof( T_2 ) , 64 ) ;
F_97 ( & V_12 -> V_176 , sizeof( struct V_191 ) , 16 ) ;
F_97 ( & V_12 -> V_192 , sizeof( struct V_193 ) , 16 ) ;
F_98 ( & V_12 -> V_169 , F_83 ) ;
#ifdef F_92
F_99 ( & V_12 -> V_194 ) ;
F_98 ( & V_12 -> V_173 , V_195 ) ;
F_8 ( V_12 ) ;
F_7 ( V_7 , true ) ;
#endif
if ( V_12 -> V_7 -> V_117 ) {
V_12 -> V_117 = F_71 ( V_12 -> V_7 -> V_117 , V_100 ) ;
if ( ! V_12 -> V_117 ) {
F_53 ( V_12 ) ;
return - V_196 ;
}
}
F_3 ( & V_12 -> V_4 , & V_7 -> V_120 ) ;
V_7 -> V_97 [ V_180 ] = V_12 ;
V_12 -> V_131 = F_27 ( V_12 , V_146 ,
V_197 ) ;
if ( V_12 -> V_131 == - 1 )
V_12 -> V_131 = F_27 ( V_12 , V_146 ,
V_197 ) ;
V_12 -> V_198 = F_27 ( V_12 , V_146 ,
V_199 ) ;
V_12 -> V_133 = F_27 ( V_12 , V_146 ,
V_200 ) ;
F_72 ( V_12 ) ;
if ( ! V_12 -> V_129 && ! V_12 -> V_130 ) {
F_100 ( L_55 ) ;
V_33 = - V_196 ;
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
if ( ! V_12 -> V_198 ) {
V_12 -> V_198 =
F_23 ( V_12 , V_183 , 0 ,
V_201 , 0 ) ;
}
#ifdef F_92
V_12 -> V_202 = F_101 ( V_12 , V_183 ,
V_203 ) ;
if ( ! V_12 -> V_202 )
V_7 -> V_204 = 1 ;
#endif
V_12 -> V_205 = F_101 ( V_12 , V_183 ,
V_206 ) ;
F_102 ( V_12 , V_207 ) ;
F_103 ( V_12 ) ;
F_104 ( V_12 ) ;
sprintf ( V_182 , L_57 , V_12 -> V_131 ,
V_12 -> V_198 , V_12 -> V_133 ) ;
F_105 ( V_12 -> V_7 -> V_107 , V_182 ) ;
if ( V_181 )
* V_181 = V_12 ;
return 0 ;
error:
F_53 ( V_12 ) ;
return V_33 ;
}
int F_106 ( struct V_11 * V_12 )
{
int V_33 ;
V_12 -> V_2 = F_65 ( V_12 ) ;
if ( ! V_12 -> V_140 || ! V_12 -> V_143 ) {
V_33 = F_70 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( F_66 ( V_12 ) ) {
V_33 = F_107 ( V_12 ) ;
goto V_208;
}
if ( V_12 -> V_2 && V_12 -> V_2 -> V_209 ) {
V_33 = V_12 -> V_2 -> V_209 ( V_12 ) ;
goto V_208;
}
V_33 = F_107 ( V_12 ) ;
if ( V_33 < 0 )
F_14 ( V_30 L_58 ) ;
V_208:
if ( ! V_33 && V_12 -> V_98 . V_99 )
V_33 = F_46 ( V_12 -> V_7 ) ;
if ( ! V_33 && ( V_12 -> V_129 || ! * V_12 -> V_7 -> V_107 -> V_210 ) )
snprintf ( V_12 -> V_7 -> V_107 -> V_210 ,
sizeof( V_12 -> V_7 -> V_107 -> V_210 ) ,
L_59 , V_12 -> V_140 , V_12 -> V_143 ) ;
return V_33 ;
}
static void F_108 ( struct V_11 * V_12 ,
struct V_171 * V_51 , T_2 V_24 ,
T_1 V_211 , int V_212 )
{
unsigned int V_213 , V_214 ;
if ( V_51 -> V_211 != V_211 || V_51 -> V_212 != V_212 ) {
V_213 = F_23 ( V_12 , V_24 , 0 , V_215 , 0 ) ;
V_214 = ( V_211 << 4 ) | V_212 ;
if ( V_213 != V_214 )
F_24 ( V_12 , V_24 , 0 ,
V_216 ,
V_214 ) ;
V_51 -> V_211 = V_211 ;
V_51 -> V_212 = V_212 ;
}
}
static void F_109 ( struct V_11 * V_12 , struct V_171 * V_51 ,
T_2 V_24 , int V_217 )
{
unsigned int V_213 ;
if ( V_51 -> V_218 != V_217 ) {
V_213 = F_23 ( V_12 , V_24 , 0 ,
V_219 , 0 ) ;
if ( V_213 != V_217 ) {
F_110 ( 1 ) ;
F_24 ( V_12 , V_24 , 0 ,
V_220 ,
V_217 ) ;
}
V_51 -> V_218 = V_217 ;
}
}
void F_111 ( struct V_11 * V_12 , T_2 V_24 ,
T_1 V_211 ,
int V_212 , int V_217 )
{
struct V_11 * V_137 ;
struct V_171 * V_51 ;
int type ;
int V_17 ;
if ( ! V_24 )
return;
F_100 ( L_60
L_61 ,
V_24 , V_211 , V_212 , V_217 ) ;
V_51 = F_89 ( V_12 , V_24 ) ;
if ( ! V_51 )
return;
if ( V_12 -> V_221 )
F_109 ( V_12 , V_51 , V_24 , V_217 ) ;
F_108 ( V_12 , V_51 , V_24 , V_211 , V_212 ) ;
if ( ! V_12 -> V_221 )
F_109 ( V_12 , V_51 , V_24 , V_217 ) ;
V_51 -> V_222 = 1 ;
V_51 -> V_223 = 0 ;
type = F_37 ( F_36 ( V_12 , V_24 ) ) ;
F_57 (c, &codec->bus->codec_list, list) {
for ( V_17 = 0 ; V_17 < V_137 -> V_172 . V_50 ; V_17 ++ ) {
V_51 = F_29 ( & V_137 -> V_172 , V_17 ) ;
if ( ! V_51 -> V_222 && V_51 -> V_211 == V_211 &&
F_37 ( F_36 ( V_137 , V_51 -> V_24 ) ) == type )
V_51 -> V_223 = 1 ;
}
}
}
void F_112 ( struct V_11 * V_12 , T_2 V_24 ,
int V_224 )
{
struct V_171 * V_51 ;
if ( ! V_24 )
return;
if ( V_12 -> V_225 )
V_224 = 1 ;
F_100 ( L_62 , V_24 ) ;
V_51 = F_89 ( V_12 , V_24 ) ;
if ( V_51 ) {
if ( V_224 )
F_113 ( V_12 , V_51 ) ;
else
V_51 -> V_222 = 0 ;
}
}
static void F_113 ( struct V_11 * V_12 ,
struct V_171 * V_226 )
{
T_2 V_24 = V_226 -> V_24 ;
if ( V_226 -> V_211 || V_226 -> V_212 )
F_24 ( V_12 , V_24 , 0 , V_216 , 0 ) ;
if ( V_226 -> V_218 )
F_24 ( V_12 , V_24 , 0 , V_220 , 0
) ;
memset ( V_226 , 0 , sizeof( * V_226 ) ) ;
V_226 -> V_24 = V_24 ;
}
static void F_114 ( struct V_11 * V_12 )
{
struct V_11 * V_137 ;
int V_17 ;
F_57 (c, &codec->bus->codec_list, list) {
for ( V_17 = 0 ; V_17 < V_137 -> V_172 . V_50 ; V_17 ++ ) {
struct V_171 * V_51 ;
V_51 = F_29 ( & V_137 -> V_172 , V_17 ) ;
if ( V_51 -> V_223 )
F_113 ( V_137 , V_51 ) ;
}
}
}
static void F_115 ( struct V_11 * V_12 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_172 . V_50 ; V_17 ++ ) {
struct V_171 * V_51 = F_29 ( & V_12 -> V_172 , V_17 ) ;
if ( V_51 -> V_211 )
F_113 ( V_12 , V_51 ) ;
}
}
static void F_96 ( struct V_227 * V_228 ,
unsigned int V_229 )
{
memset ( V_228 , 0 , sizeof( * V_228 ) ) ;
memset ( V_228 -> V_230 , 0xff , sizeof( V_228 -> V_230 ) ) ;
F_97 ( & V_228 -> V_231 , V_229 , 64 ) ;
}
static void F_94 ( struct V_227 * V_228 )
{
F_88 ( & V_228 -> V_231 ) ;
}
static struct V_189 * F_116 ( struct V_227 * V_228 , T_1 V_232 )
{
T_3 V_233 = V_232 % ( T_3 ) F_10 ( V_228 -> V_230 ) ;
T_3 V_234 = V_228 -> V_230 [ V_233 ] ;
struct V_189 * V_235 ;
while ( V_234 != 0xffff ) {
V_235 = F_29 ( & V_228 -> V_231 , V_234 ) ;
if ( V_235 -> V_232 == V_232 )
return V_235 ;
V_234 = V_235 -> V_236 ;
}
return NULL ;
}
static struct V_189 * F_117 ( struct V_227 * V_228 ,
T_1 V_232 )
{
struct V_189 * V_235 = F_116 ( V_228 , V_232 ) ;
if ( ! V_235 ) {
T_3 V_233 , V_234 ;
V_235 = F_39 ( & V_228 -> V_231 ) ;
if ( ! V_235 )
return NULL ;
V_234 = F_118 ( & V_228 -> V_231 , V_235 ) ;
V_235 -> V_232 = V_232 ;
V_235 -> V_28 = 0 ;
V_233 = V_232 % ( T_3 ) F_10 ( V_228 -> V_230 ) ;
V_235 -> V_236 = V_228 -> V_230 [ V_233 ] ;
V_228 -> V_230 [ V_233 ] = V_234 ;
}
return V_235 ;
}
static inline struct V_188 *
F_119 ( struct V_11 * V_12 , T_1 V_232 )
{
return (struct V_188 * ) F_117 ( & V_12 -> V_178 , V_232 ) ;
}
static int F_120 ( struct V_11 * V_12 , T_1 V_232 , unsigned int V_28 )
{
struct V_188 * V_235 ;
F_2 ( & V_12 -> V_57 ) ;
V_235 = F_119 ( V_12 , V_232 ) ;
if ( ! V_235 ) {
F_4 ( & V_12 -> V_57 ) ;
return - V_58 ;
}
V_235 -> V_237 = V_28 ;
V_235 -> V_238 . V_28 |= V_239 ;
F_4 ( & V_12 -> V_57 ) ;
return 0 ;
}
static unsigned int F_121 ( struct V_11 * V_12 , T_2 V_24 ,
int V_240 )
{
if ( ! ( F_36 ( V_12 , V_24 ) & V_241 ) )
V_24 = V_12 -> V_129 ;
return F_27 ( V_12 , V_24 ,
V_240 == V_242 ?
V_243 : V_244 ) ;
}
T_1 F_122 ( struct V_11 * V_12 , T_2 V_24 , int V_240 )
{
return F_123 ( V_12 , V_24 , V_240 ,
F_124 ( V_24 , V_240 , 0 ) ,
F_121 ) ;
}
int F_125 ( struct V_11 * V_12 , T_2 V_24 , int V_245 ,
unsigned int V_246 )
{
return F_120 ( V_12 , F_124 ( V_24 , V_245 , 0 ) , V_246 ) ;
}
static unsigned int F_126 ( struct V_11 * V_12 , T_2 V_24 ,
int V_245 )
{
return F_27 ( V_12 , V_24 , V_247 ) ;
}
T_1 F_127 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_123 ( V_12 , V_24 , 0 , F_128 ( V_24 ) ,
F_126 ) ;
}
int F_129 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_246 )
{
return F_120 ( V_12 , F_128 ( V_24 ) , V_246 ) ;
}
static struct V_188 *
F_130 ( struct V_11 * V_12 , T_2 V_24 , int V_248 ,
int V_240 , int V_249 )
{
struct V_188 * V_235 ;
unsigned int V_27 , V_28 = 0 ;
bool V_250 = false ;
V_251:
V_235 = F_119 ( V_12 , F_124 ( V_24 , V_240 , V_249 ) ) ;
if ( ! V_235 )
return NULL ;
if ( ! ( V_235 -> V_238 . V_28 & F_131 ( V_248 ) ) ) {
if ( ! V_250 ) {
F_4 ( & V_12 -> V_57 ) ;
V_27 = V_248 ? V_252 : V_253 ;
V_27 |= V_240 == V_242 ?
V_254 : V_255 ;
V_27 |= V_249 ;
V_28 = F_23 ( V_12 , V_24 , 0 ,
V_256 , V_27 ) ;
V_28 &= 0xff ;
V_250 = true ;
F_2 ( & V_12 -> V_57 ) ;
goto V_251;
}
V_235 -> V_257 [ V_248 ] = V_28 ;
V_235 -> V_238 . V_28 |= F_131 ( V_248 ) ;
}
return V_235 ;
}
static void F_132 ( struct V_11 * V_12 , struct V_188 * V_235 ,
T_2 V_24 , int V_248 , int V_240 , int V_249 ,
int V_28 )
{
T_1 V_27 ;
V_27 = V_248 ? V_258 : V_259 ;
V_27 |= V_240 == V_242 ? V_260 : V_261 ;
V_27 |= V_249 << V_262 ;
if ( ( V_28 & V_263 ) && ! ( V_235 -> V_237 & V_264 ) &&
( V_235 -> V_237 & V_265 ) )
;
else
V_27 |= V_28 ;
F_24 ( V_12 , V_24 , 0 , V_266 , V_27 ) ;
}
int F_133 ( struct V_11 * V_12 , T_2 V_24 , int V_248 ,
int V_240 , int V_249 )
{
struct V_188 * V_235 ;
unsigned int V_28 = 0 ;
F_2 ( & V_12 -> V_57 ) ;
V_235 = F_130 ( V_12 , V_24 , V_248 , V_240 , V_249 ) ;
if ( V_235 )
V_28 = V_235 -> V_257 [ V_248 ] ;
F_4 ( & V_12 -> V_57 ) ;
return V_28 ;
}
int F_134 ( struct V_11 * V_12 , T_2 V_24 , int V_248 ,
int V_240 , int V_233 , int V_63 , int V_28 )
{
struct V_188 * V_235 ;
if ( F_35 ( V_63 & ~ 0xff ) )
V_63 &= 0xff ;
V_28 &= V_63 ;
F_2 ( & V_12 -> V_57 ) ;
V_235 = F_130 ( V_12 , V_24 , V_248 , V_240 , V_233 ) ;
if ( ! V_235 ) {
F_4 ( & V_12 -> V_57 ) ;
return 0 ;
}
V_28 |= V_235 -> V_257 [ V_248 ] & ~ V_63 ;
if ( V_235 -> V_257 [ V_248 ] == V_28 ) {
F_4 ( & V_12 -> V_57 ) ;
return 0 ;
}
V_235 -> V_257 [ V_248 ] = V_28 ;
F_4 ( & V_12 -> V_57 ) ;
F_132 ( V_12 , V_235 , V_24 , V_248 , V_240 , V_233 , V_28 ) ;
return 1 ;
}
int F_135 ( struct V_11 * V_12 , T_2 V_24 ,
int V_240 , int V_233 , int V_63 , int V_28 )
{
int V_248 , V_267 = 0 ;
if ( F_35 ( V_63 & ~ 0xff ) )
V_63 &= 0xff ;
for ( V_248 = 0 ; V_248 < 2 ; V_248 ++ )
V_267 |= F_134 ( V_12 , V_24 , V_248 , V_240 ,
V_233 , V_63 , V_28 ) ;
return V_267 ;
}
void F_136 ( struct V_11 * V_12 )
{
struct V_188 * V_268 = V_12 -> V_178 . V_231 . V_4 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_178 . V_231 . V_50 ; V_17 ++ , V_268 ++ ) {
T_1 V_232 = V_268 -> V_238 . V_232 ;
T_2 V_24 ;
unsigned int V_233 , V_245 , V_248 ;
if ( ! V_232 )
continue;
V_24 = V_232 & 0xff ;
V_233 = ( V_232 >> 16 ) & 0xff ;
V_245 = ( V_232 >> 24 ) & 0xff ;
for ( V_248 = 0 ; V_248 < 2 ; V_248 ++ ) {
if ( ! ( V_268 -> V_238 . V_28 & F_131 ( V_248 ) ) )
continue;
F_132 ( V_12 , V_268 , V_24 , V_248 , V_245 , V_233 ,
V_268 -> V_257 [ V_248 ] ) ;
}
}
}
static T_1 F_137 ( struct V_11 * V_12 , T_2 V_24 , int V_245 ,
unsigned int V_269 )
{
T_1 V_246 = F_122 ( V_12 , V_24 , V_245 ) ;
V_246 = ( V_246 & V_270 ) >> V_271 ;
if ( V_269 < V_246 )
V_246 -= V_269 ;
return V_246 ;
}
int F_138 ( struct V_272 * V_273 ,
struct V_274 * V_275 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
T_3 V_24 = F_140 ( V_273 ) ;
T_4 V_276 = F_141 ( V_273 ) ;
int V_245 = F_142 ( V_273 ) ;
unsigned int V_269 = F_143 ( V_273 ) ;
V_275 -> type = V_277 ;
V_275 -> V_278 = V_276 == 3 ? 2 : 1 ;
V_275 -> V_279 . integer . V_280 = 0 ;
V_275 -> V_279 . integer . V_281 = F_137 ( V_12 , V_24 , V_245 , V_269 ) ;
if ( ! V_275 -> V_279 . integer . V_281 ) {
F_14 ( V_75 L_39
L_63 , V_24 ,
V_273 -> V_128 . V_135 ) ;
return - V_58 ;
}
return 0 ;
}
static inline unsigned int
F_144 ( struct V_11 * V_12 , T_2 V_24 ,
int V_248 , int V_245 , int V_233 , unsigned int V_269 )
{
unsigned int V_28 ;
V_28 = F_133 ( V_12 , V_24 , V_248 , V_245 , V_233 ) ;
V_28 &= V_282 ;
if ( V_28 >= V_269 )
V_28 -= V_269 ;
else
V_28 = 0 ;
return V_28 ;
}
static inline int
F_145 ( struct V_11 * V_12 , T_2 V_24 ,
int V_248 , int V_245 , int V_233 , unsigned int V_269 ,
unsigned int V_28 )
{
unsigned int V_283 ;
if ( V_28 > 0 )
V_28 += V_269 ;
V_283 = F_137 ( V_12 , V_24 , V_245 , 0 ) ;
if ( V_28 > V_283 )
V_28 = V_283 ;
return F_134 ( V_12 , V_24 , V_248 , V_245 , V_233 ,
V_282 , V_28 ) ;
}
int F_146 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
T_2 V_24 = F_140 ( V_273 ) ;
int V_276 = F_141 ( V_273 ) ;
int V_245 = F_142 ( V_273 ) ;
int V_233 = F_147 ( V_273 ) ;
unsigned int V_269 = F_143 ( V_273 ) ;
long * V_286 = V_285 -> V_279 . integer . V_279 ;
if ( V_276 & 1 )
* V_286 ++ = F_144 ( V_12 , V_24 , 0 , V_245 , V_233 , V_269 ) ;
if ( V_276 & 2 )
* V_286 = F_144 ( V_12 , V_24 , 1 , V_245 , V_233 , V_269 ) ;
return 0 ;
}
int F_148 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
T_2 V_24 = F_140 ( V_273 ) ;
int V_276 = F_141 ( V_273 ) ;
int V_245 = F_142 ( V_273 ) ;
int V_233 = F_147 ( V_273 ) ;
unsigned int V_269 = F_143 ( V_273 ) ;
long * V_286 = V_285 -> V_279 . integer . V_279 ;
int V_287 = 0 ;
F_16 ( V_12 ) ;
if ( V_276 & 1 ) {
V_287 = F_145 ( V_12 , V_24 , 0 , V_245 , V_233 , V_269 , * V_286 ) ;
V_286 ++ ;
}
if ( V_276 & 2 )
V_287 |= F_145 ( V_12 , V_24 , 1 , V_245 , V_233 , V_269 , * V_286 ) ;
F_19 ( V_12 ) ;
return V_287 ;
}
int F_149 ( struct V_272 * V_273 , int V_288 ,
unsigned int V_289 , unsigned int T_5 * V_290 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
T_2 V_24 = F_140 ( V_273 ) ;
int V_245 = F_142 ( V_273 ) ;
unsigned int V_269 = F_143 ( V_273 ) ;
bool V_291 = F_150 ( V_273 ) ;
T_1 V_246 , V_292 , V_293 ;
if ( V_289 < 4 * sizeof( unsigned int ) )
return - V_78 ;
V_246 = F_122 ( V_12 , V_24 , V_245 ) ;
V_293 = ( V_246 & V_294 ) >> V_295 ;
V_293 = ( V_293 + 1 ) * 25 ;
V_292 = - ( ( V_246 & V_296 ) >> V_297 ) ;
V_292 += V_269 ;
V_292 = ( ( int ) V_292 ) * ( ( int ) V_293 ) ;
if ( V_291 || ( V_246 & V_265 ) )
V_293 |= V_298 ;
if ( F_151 ( V_299 , V_290 ) )
return - V_300 ;
if ( F_151 ( 2 * sizeof( unsigned int ) , V_290 + 1 ) )
return - V_300 ;
if ( F_151 ( V_292 , V_290 + 2 ) )
return - V_300 ;
if ( F_151 ( V_293 , V_290 + 3 ) )
return - V_300 ;
return 0 ;
}
void F_152 ( struct V_11 * V_12 , T_2 V_24 , int V_245 ,
unsigned int * V_301 )
{
T_1 V_246 ;
int V_83 , V_302 ;
V_246 = F_122 ( V_12 , V_24 , V_245 ) ;
V_83 = ( V_246 & V_270 ) >> V_271 ;
V_302 = ( V_246 & V_294 ) >> V_295 ;
V_302 = ( V_302 + 1 ) * 25 ;
V_301 [ 0 ] = V_299 ;
V_301 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_301 [ 2 ] = - V_83 * V_302 ;
V_301 [ 3 ] = V_302 ;
}
static struct V_272 *
F_153 ( struct V_11 * V_12 , const char * V_135 , int V_303 , int V_233 )
{
struct V_304 V_128 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_305 = V_306 ;
V_128 . V_103 = V_303 ;
V_128 . V_249 = V_233 ;
if ( F_35 ( strlen ( V_135 ) >= sizeof( V_128 . V_135 ) ) )
return NULL ;
strcpy ( V_128 . V_135 , V_135 ) ;
return F_154 ( V_12 -> V_7 -> V_107 , & V_128 ) ;
}
struct V_272 * F_155 ( struct V_11 * V_12 ,
const char * V_135 )
{
return F_153 ( V_12 , V_135 , 0 , 0 ) ;
}
static int F_156 ( struct V_11 * V_12 , const char * V_135 ,
int V_303 )
{
int V_233 ;
for ( V_233 = 0 ; V_233 < 16 ; V_233 ++ ) {
if ( ! F_153 ( V_12 , V_135 , V_303 , V_233 ) )
return V_233 ;
}
return - V_185 ;
}
int F_157 ( struct V_11 * V_12 , T_2 V_24 ,
struct V_272 * V_307 )
{
int V_33 ;
unsigned short V_308 = 0 ;
struct V_190 * V_309 ;
if ( V_307 -> V_128 . V_310 & V_311 ) {
V_308 |= V_312 ;
if ( V_24 == 0 )
V_24 = F_158 ( V_307 -> V_313 ) ;
}
if ( ( V_307 -> V_128 . V_310 & V_314 ) != 0 && V_24 == 0 )
V_24 = V_307 -> V_128 . V_310 & 0xffff ;
if ( V_307 -> V_128 . V_310 & ( V_314 | V_311 ) )
V_307 -> V_128 . V_310 = 0 ;
V_33 = F_159 ( V_12 -> V_7 -> V_107 , V_307 ) ;
if ( V_33 < 0 )
return V_33 ;
V_309 = F_39 ( & V_12 -> V_174 ) ;
if ( ! V_309 )
return - V_78 ;
V_309 -> V_307 = V_307 ;
V_309 -> V_24 = V_24 ;
V_309 -> V_308 = V_308 ;
return 0 ;
}
int F_160 ( struct V_11 * V_12 , struct V_272 * V_307 ,
unsigned int V_249 , T_2 V_24 )
{
struct V_190 * V_309 ;
if ( V_24 > 0 ) {
V_309 = F_39 ( & V_12 -> V_175 ) ;
if ( ! V_309 )
return - V_78 ;
V_309 -> V_307 = V_307 ;
V_309 -> V_249 = V_249 ;
V_309 -> V_24 = V_24 ;
return 0 ;
}
F_14 ( V_30 L_64 ,
V_307 -> V_128 . V_135 , V_307 -> V_128 . V_249 , V_249 ) ;
return - V_58 ;
}
void F_161 ( struct V_11 * V_12 )
{
int V_17 ;
struct V_190 * V_315 = V_12 -> V_174 . V_4 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_174 . V_50 ; V_17 ++ )
F_162 ( V_12 -> V_7 -> V_107 , V_315 [ V_17 ] . V_307 ) ;
F_88 ( & V_12 -> V_174 ) ;
F_88 ( & V_12 -> V_175 ) ;
}
int F_163 ( struct V_6 * V_7 )
{
struct V_106 * V_107 = V_7 -> V_107 ;
struct V_11 * V_12 ;
F_164 ( & V_107 -> V_316 ) ;
if ( V_107 -> V_105 )
goto V_317;
V_107 -> V_105 = 1 ;
if ( ! F_165 ( & V_107 -> V_318 ) )
goto V_319;
F_57 (codec, &bus->codec_list, list) {
int V_320 ;
for ( V_320 = 0 ; V_320 < V_12 -> V_321 ; V_320 ++ ) {
struct V_322 * V_323 = & V_12 -> V_324 [ V_320 ] ;
if ( ! V_323 -> V_320 )
continue;
if ( V_323 -> V_320 -> V_325 [ 0 ] . V_326 ||
V_323 -> V_320 -> V_325 [ 1 ] . V_326 )
goto V_319;
}
}
F_166 ( & V_107 -> V_316 ) ;
return 0 ;
V_319:
V_107 -> V_105 = 0 ;
V_317:
F_166 ( & V_107 -> V_316 ) ;
return - V_58 ;
}
void F_167 ( struct V_6 * V_7 )
{
struct V_106 * V_107 = V_7 -> V_107 ;
V_107 = V_7 -> V_107 ;
F_164 ( & V_107 -> V_316 ) ;
V_107 -> V_105 = 0 ;
F_166 ( & V_107 -> V_316 ) ;
}
int F_168 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_106 * V_107 = V_7 -> V_107 ;
int V_17 ;
if ( F_163 ( V_7 ) < 0 )
return - V_185 ;
F_90 ( & V_12 -> V_169 ) ;
#ifdef F_92
F_90 ( & V_12 -> V_173 ) ;
V_12 -> V_327 = 0 ;
V_12 -> V_328 = 0 ;
V_12 -> V_329 = V_330 ;
F_50 ( V_7 -> V_92 ) ;
#endif
F_161 ( V_12 ) ;
for ( V_17 = 0 ; V_17 < V_12 -> V_321 ; V_17 ++ ) {
if ( V_12 -> V_324 [ V_17 ] . V_320 ) {
F_169 ( V_107 , V_12 -> V_324 [ V_17 ] . V_320 ) ;
F_170 ( V_12 -> V_324 [ V_17 ] . V_103 ,
V_7 -> V_331 ) ;
}
}
if ( V_12 -> V_98 . free )
V_12 -> V_98 . free ( V_12 ) ;
memset ( & V_12 -> V_98 , 0 , sizeof( V_12 -> V_98 ) ) ;
F_91 ( V_12 ) ;
V_12 -> V_332 = NULL ;
V_12 -> V_333 = NULL ;
F_94 ( & V_12 -> V_178 ) ;
F_94 ( & V_12 -> V_179 ) ;
F_96 ( & V_12 -> V_178 , sizeof( struct V_188 ) ) ;
F_96 ( & V_12 -> V_179 , sizeof( struct V_189 ) ) ;
F_88 ( & V_12 -> V_165 ) ;
F_88 ( & V_12 -> V_172 ) ;
F_88 ( & V_12 -> V_176 ) ;
V_12 -> V_321 = 0 ;
V_12 -> V_324 = NULL ;
V_12 -> V_2 = NULL ;
V_12 -> V_334 = NULL ;
V_12 -> V_335 = 0 ;
F_68 ( V_12 -> V_127 ) ;
V_12 -> V_127 = NULL ;
F_167 ( V_7 ) ;
return 0 ;
}
static int F_171 ( struct V_11 * V_12 , const char * const * V_336 ,
const char * V_337 , T_6 V_338 , void * V_339 )
{
struct V_190 * V_315 ;
const char * const * V_340 ;
int V_17 , V_33 ;
V_315 = V_12 -> V_174 . V_4 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_174 . V_50 ; V_17 ++ ) {
struct V_272 * V_341 = V_315 [ V_17 ] . V_307 ;
if ( ! V_341 || ! V_341 -> V_128 . V_135 ||
V_341 -> V_128 . V_305 != V_306 )
continue;
for ( V_340 = V_336 ; * V_340 ; V_340 ++ ) {
char V_342 [ sizeof( V_341 -> V_128 . V_135 ) ] ;
const char * V_135 = * V_340 ;
if ( V_337 ) {
snprintf ( V_342 , sizeof( V_342 ) , L_59 ,
V_135 , V_337 ) ;
V_135 = V_342 ;
}
if ( ! strcmp ( V_341 -> V_128 . V_135 , V_135 ) ) {
V_33 = V_338 ( V_339 , V_341 ) ;
if ( V_33 )
return V_33 ;
break;
}
}
}
return 0 ;
}
static int F_172 ( void * V_339 , struct V_272 * V_341 )
{
return 1 ;
}
static int F_173 ( struct V_272 * V_307 )
{
int V_290 [ 4 ] ;
const int * V_301 = NULL ;
int V_28 = - 1 ;
if ( V_307 -> V_343 [ 0 ] . V_344 & V_345 ) {
T_7 V_346 = F_174 () ;
F_175 ( F_176 () ) ;
if ( ! V_307 -> V_301 . V_137 ( V_307 , 0 , sizeof( V_290 ) , V_290 ) )
V_301 = V_290 ;
F_175 ( V_346 ) ;
} else if ( V_307 -> V_343 [ 0 ] . V_344 & V_347 )
V_301 = V_307 -> V_301 . V_51 ;
if ( V_301 && V_301 [ 0 ] == V_299 )
V_28 = - V_301 [ 2 ] / V_301 [ 3 ] ;
return V_28 ;
}
static int F_177 ( struct V_272 * V_307 , int V_28 )
{
struct V_284 * V_285 ;
V_285 = F_47 ( sizeof( * V_285 ) , V_100 ) ;
if ( ! V_285 )
return - V_78 ;
V_285 -> V_279 . integer . V_279 [ 0 ] = V_28 ;
V_285 -> V_279 . integer . V_279 [ 1 ] = V_28 ;
V_307 -> V_348 ( V_307 , V_285 ) ;
F_51 ( V_285 ) ;
return 0 ;
}
static int F_178 ( void * V_339 , struct V_272 * V_349 )
{
int V_350 = F_173 ( V_349 ) ;
if ( V_350 > 0 )
F_177 ( V_349 , V_350 ) ;
return 0 ;
}
static int F_179 ( void * V_339 , struct V_272 * V_349 )
{
return F_177 ( V_349 , 1 ) ;
}
int F_180 ( struct V_11 * V_12 , char * V_135 ,
unsigned int * V_301 , const char * const * V_336 ,
const char * V_337 , bool V_351 ,
struct V_272 * * V_352 )
{
struct V_272 * V_307 ;
int V_33 ;
if ( V_352 )
* V_352 = NULL ;
V_33 = F_171 ( V_12 , V_336 , V_337 , F_172 , NULL ) ;
if ( V_33 != 1 ) {
F_100 ( L_65 , V_135 ) ;
return 0 ;
}
V_307 = F_181 ( V_135 , V_301 ) ;
if ( ! V_307 )
return - V_78 ;
V_33 = F_157 ( V_12 , 0 , V_307 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_171 ( V_12 , V_336 , V_337 ,
( T_6 ) V_353 , V_307 ) ;
if ( V_33 < 0 )
return V_33 ;
F_177 ( V_307 , 0 ) ;
if ( V_351 )
F_171 ( V_12 , V_336 , V_337 ,
V_301 ? F_178 : F_179 , V_307 ) ;
if ( V_352 )
* V_352 = V_307 ;
return 0 ;
}
static int F_182 ( struct V_272 * V_273 ,
struct V_274 * V_275 )
{
static const char * const V_354 [] = {
L_66 , L_67 , L_68
} ;
unsigned int V_249 ;
V_275 -> type = V_355 ;
V_275 -> V_278 = 1 ;
V_275 -> V_279 . V_356 . V_315 = 3 ;
V_249 = V_275 -> V_279 . V_356 . V_309 ;
if ( V_249 >= 3 )
V_249 = 2 ;
strcpy ( V_275 -> V_279 . V_356 . V_135 , V_354 [ V_249 ] ) ;
return 0 ;
}
static int F_183 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_357 * V_358 = F_139 ( V_273 ) ;
V_285 -> V_279 . V_356 . V_309 [ 0 ] = V_358 -> V_359 ;
return 0 ;
}
static int F_184 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_357 * V_358 = F_139 ( V_273 ) ;
unsigned int V_360 = V_358 -> V_359 ;
V_358 -> V_359 = V_285 -> V_279 . V_356 . V_309 [ 0 ] ;
if ( V_358 -> V_359 > V_361 )
V_358 -> V_359 = V_361 ;
if ( V_360 == V_358 -> V_359 )
return 0 ;
F_185 ( V_358 ) ;
return 1 ;
}
int F_186 ( struct V_11 * V_12 ,
struct V_357 * V_358 ,
bool V_362 )
{
struct V_272 * V_307 ;
if ( ! V_358 -> V_358 || ! V_358 -> V_363 )
return 0 ;
F_187 ( V_358 -> V_363 , V_358 -> V_358 , V_12 ) ;
V_358 -> V_12 = V_12 ;
V_358 -> V_359 = V_361 ;
if ( ! V_362 )
return 0 ;
V_307 = F_188 ( & V_364 , V_358 ) ;
if ( ! V_307 )
return - V_78 ;
return F_157 ( V_12 , 0 , V_307 ) ;
}
void F_185 ( struct V_357 * V_358 )
{
if ( ! V_358 -> V_358 || ! V_358 -> V_12 )
return;
switch ( V_358 -> V_359 ) {
case V_361 :
F_189 ( V_358 -> V_363 ) ;
break;
default:
V_358 -> V_358 ( V_358 -> V_12 , V_358 -> V_359 ) ;
break;
}
}
int F_190 ( struct V_272 * V_273 ,
struct V_274 * V_275 )
{
int V_276 = F_141 ( V_273 ) ;
V_275 -> type = V_365 ;
V_275 -> V_278 = V_276 == 3 ? 2 : 1 ;
V_275 -> V_279 . integer . V_280 = 0 ;
V_275 -> V_279 . integer . V_281 = 1 ;
return 0 ;
}
int F_191 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
T_2 V_24 = F_140 ( V_273 ) ;
int V_276 = F_141 ( V_273 ) ;
int V_245 = F_142 ( V_273 ) ;
int V_233 = F_147 ( V_273 ) ;
long * V_286 = V_285 -> V_279 . integer . V_279 ;
if ( V_276 & 1 )
* V_286 ++ = ( F_133 ( V_12 , V_24 , 0 , V_245 , V_233 ) &
V_263 ) ? 0 : 1 ;
if ( V_276 & 2 )
* V_286 = ( F_133 ( V_12 , V_24 , 1 , V_245 , V_233 ) &
V_263 ) ? 0 : 1 ;
return 0 ;
}
int F_192 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
T_2 V_24 = F_140 ( V_273 ) ;
int V_276 = F_141 ( V_273 ) ;
int V_245 = F_142 ( V_273 ) ;
int V_233 = F_147 ( V_273 ) ;
long * V_286 = V_285 -> V_279 . integer . V_279 ;
int V_287 = 0 ;
F_16 ( V_12 ) ;
if ( V_276 & 1 ) {
V_287 = F_134 ( V_12 , V_24 , 0 , V_245 , V_233 ,
V_263 ,
* V_286 ? 0 : V_263 ) ;
V_286 ++ ;
}
if ( V_276 & 2 )
V_287 |= F_134 ( V_12 , V_24 , 1 , V_245 , V_233 ,
V_263 ,
* V_286 ? 0 : V_263 ) ;
F_193 ( V_12 , V_24 ) ;
F_19 ( V_12 ) ;
return V_287 ;
}
int F_194 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
unsigned long V_366 ;
int V_33 ;
F_2 ( & V_12 -> V_187 ) ;
V_366 = V_273 -> V_313 ;
V_273 -> V_313 = V_366 & ~ V_367 ;
V_33 = F_191 ( V_273 , V_285 ) ;
V_273 -> V_313 = V_366 ;
F_4 ( & V_12 -> V_187 ) ;
return V_33 ;
}
int F_195 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
unsigned long V_366 ;
int V_17 , V_368 , V_33 = 0 , V_287 = 0 ;
F_2 ( & V_12 -> V_187 ) ;
V_366 = V_273 -> V_313 ;
V_368 = ( V_366 & V_367 ) >> V_369 ;
for ( V_17 = 0 ; V_17 < V_368 ; V_17 ++ ) {
V_273 -> V_313 = ( V_366 & ~ V_367 ) |
( V_17 << V_369 ) ;
V_33 = F_192 ( V_273 , V_285 ) ;
if ( V_33 < 0 )
break;
V_287 |= V_33 ;
}
V_273 -> V_313 = V_366 ;
F_4 ( & V_12 -> V_187 ) ;
return V_33 < 0 ? V_33 : V_287 ;
}
int F_196 ( struct V_272 * V_273 ,
struct V_274 * V_275 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
struct V_370 * V_137 ;
int V_33 ;
F_2 ( & V_12 -> V_187 ) ;
V_137 = (struct V_370 * ) V_273 -> V_313 ;
V_273 -> V_313 = * V_137 -> V_371 ;
V_33 = V_137 -> V_9 -> V_235 ( V_273 , V_275 ) ;
V_273 -> V_313 = ( long ) V_137 ;
F_4 ( & V_12 -> V_187 ) ;
return V_33 ;
}
int F_197 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
struct V_370 * V_137 ;
int V_33 ;
F_2 ( & V_12 -> V_187 ) ;
V_137 = (struct V_370 * ) V_273 -> V_313 ;
V_273 -> V_313 = * V_137 -> V_371 ;
V_33 = V_137 -> V_9 -> V_372 ( V_273 , V_285 ) ;
V_273 -> V_313 = ( long ) V_137 ;
F_4 ( & V_12 -> V_187 ) ;
return V_33 ;
}
int F_198 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
struct V_370 * V_137 ;
unsigned long * V_373 ;
int V_33 = 0 , V_287 = 0 ;
F_2 ( & V_12 -> V_187 ) ;
V_137 = (struct V_370 * ) V_273 -> V_313 ;
for ( V_373 = V_137 -> V_371 ; * V_373 ; V_373 ++ ) {
V_273 -> V_313 = * V_373 ;
V_33 = V_137 -> V_9 -> V_348 ( V_273 , V_285 ) ;
if ( V_33 < 0 )
break;
V_287 |= V_33 ;
}
V_273 -> V_313 = ( long ) V_137 ;
F_4 ( & V_12 -> V_187 ) ;
return V_33 < 0 ? V_33 : V_287 ;
}
int F_199 ( struct V_272 * V_273 , int V_288 ,
unsigned int V_289 , unsigned int T_5 * V_301 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
struct V_370 * V_137 ;
int V_33 ;
F_2 ( & V_12 -> V_187 ) ;
V_137 = (struct V_370 * ) V_273 -> V_313 ;
V_273 -> V_313 = * V_137 -> V_371 ;
V_33 = V_137 -> V_9 -> V_301 ( V_273 , V_288 , V_289 , V_301 ) ;
V_273 -> V_313 = ( long ) V_137 ;
F_4 ( & V_12 -> V_187 ) ;
return V_33 ;
}
static int F_200 ( struct V_272 * V_273 ,
struct V_274 * V_275 )
{
V_275 -> type = V_374 ;
V_275 -> V_278 = 1 ;
return 0 ;
}
static int F_201 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
V_285 -> V_279 . V_375 . V_376 [ 0 ] = V_377 |
V_378 |
V_379 |
V_380 ;
V_285 -> V_279 . V_375 . V_376 [ 1 ] = V_381 |
V_382 ;
return 0 ;
}
static int F_202 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
V_285 -> V_279 . V_375 . V_376 [ 0 ] = V_377 |
V_378 |
V_383 ;
return 0 ;
}
static int F_203 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
int V_233 = V_273 -> V_313 ;
struct V_191 * V_384 ;
F_2 ( & V_12 -> V_186 ) ;
V_384 = F_29 ( & V_12 -> V_176 , V_233 ) ;
V_285 -> V_279 . V_375 . V_376 [ 0 ] = V_384 -> V_376 & 0xff ;
V_285 -> V_279 . V_375 . V_376 [ 1 ] = ( V_384 -> V_376 >> 8 ) & 0xff ;
V_285 -> V_279 . V_375 . V_376 [ 2 ] = ( V_384 -> V_376 >> 16 ) & 0xff ;
V_285 -> V_279 . V_375 . V_376 [ 3 ] = ( V_384 -> V_376 >> 24 ) & 0xff ;
F_4 ( & V_12 -> V_186 ) ;
return 0 ;
}
static unsigned short F_204 ( unsigned int V_385 )
{
unsigned short V_28 = 0 ;
if ( V_385 & V_377 )
V_28 |= V_386 ;
if ( V_385 & V_378 )
V_28 |= V_387 ;
if ( V_385 & V_377 ) {
if ( ( V_385 & V_388 ) ==
V_383 )
V_28 |= V_389 ;
} else {
if ( ( V_385 & V_390 ) ==
V_379 )
V_28 |= V_389 ;
if ( ! ( V_385 & V_380 ) )
V_28 |= V_391 ;
if ( V_385 & ( V_382 << 8 ) )
V_28 |= V_392 ;
V_28 |= V_385 & ( V_381 << 8 ) ;
}
return V_28 ;
}
static unsigned int F_205 ( unsigned short V_28 )
{
unsigned int V_385 = 0 ;
if ( V_28 & V_387 )
V_385 |= V_378 ;
if ( V_28 & V_386 )
V_385 |= V_377 ;
if ( V_385 & V_377 ) {
if ( V_385 & V_389 )
V_385 |= V_383 ;
} else {
if ( V_28 & V_389 )
V_385 |= V_379 ;
if ( ! ( V_28 & V_391 ) )
V_385 |= V_380 ;
if ( V_28 & V_392 )
V_385 |= ( V_382 << 8 ) ;
V_385 |= V_28 & ( 0x7f << 8 ) ;
}
return V_385 ;
}
static void F_206 ( struct V_11 * V_12 , T_2 V_24 ,
int V_26 , int V_28 )
{
const T_2 * V_393 ;
F_207 ( V_12 , V_24 , 0 , V_26 , V_28 ) ;
V_393 = V_12 -> V_334 ;
if ( ! V_393 )
return;
for (; * V_393 ; V_393 ++ )
F_207 ( V_12 , * V_393 , 0 , V_26 , V_28 ) ;
}
static inline void F_208 ( struct V_11 * V_12 , T_2 V_24 ,
int V_394 , int V_395 )
{
if ( V_394 != - 1 )
F_206 ( V_12 , V_24 , V_396 , V_394 ) ;
if ( V_395 != - 1 )
F_206 ( V_12 , V_24 , V_397 , V_395 ) ;
}
static int F_209 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
int V_233 = V_273 -> V_313 ;
struct V_191 * V_384 ;
T_2 V_24 ;
unsigned short V_28 ;
int V_287 ;
F_2 ( & V_12 -> V_186 ) ;
V_384 = F_29 ( & V_12 -> V_176 , V_233 ) ;
V_24 = V_384 -> V_24 ;
V_384 -> V_376 = V_285 -> V_279 . V_375 . V_376 [ 0 ] |
( ( unsigned int ) V_285 -> V_279 . V_375 . V_376 [ 1 ] << 8 ) |
( ( unsigned int ) V_285 -> V_279 . V_375 . V_376 [ 2 ] << 16 ) |
( ( unsigned int ) V_285 -> V_279 . V_375 . V_376 [ 3 ] << 24 ) ;
V_28 = F_204 ( V_384 -> V_376 ) ;
V_28 |= V_384 -> V_398 & 1 ;
V_287 = V_384 -> V_398 != V_28 ;
V_384 -> V_398 = V_28 ;
if ( V_287 && V_24 != ( T_3 ) - 1 )
F_208 ( V_12 , V_24 , V_28 & 0xff , ( V_28 >> 8 ) & 0xff ) ;
F_4 ( & V_12 -> V_186 ) ;
return V_287 ;
}
static int F_210 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
int V_233 = V_273 -> V_313 ;
struct V_191 * V_384 ;
F_2 ( & V_12 -> V_186 ) ;
V_384 = F_29 ( & V_12 -> V_176 , V_233 ) ;
V_285 -> V_279 . integer . V_279 [ 0 ] = V_384 -> V_398 & V_399 ;
F_4 ( & V_12 -> V_186 ) ;
return 0 ;
}
static inline void F_211 ( struct V_11 * V_12 , T_2 V_24 ,
int V_394 , int V_395 )
{
F_208 ( V_12 , V_24 , V_394 , V_395 ) ;
if ( ( F_36 ( V_12 , V_24 ) & V_400 ) &&
( V_394 & V_399 ) )
F_135 ( V_12 , V_24 , V_242 , 0 ,
V_263 , 0 ) ;
}
static int F_212 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
int V_233 = V_273 -> V_313 ;
struct V_191 * V_384 ;
T_2 V_24 ;
unsigned short V_28 ;
int V_287 ;
F_2 ( & V_12 -> V_186 ) ;
V_384 = F_29 ( & V_12 -> V_176 , V_233 ) ;
V_24 = V_384 -> V_24 ;
V_28 = V_384 -> V_398 & ~ V_399 ;
if ( V_285 -> V_279 . integer . V_279 [ 0 ] )
V_28 |= V_399 ;
V_287 = V_384 -> V_398 != V_28 ;
V_384 -> V_398 = V_28 ;
if ( V_287 && V_24 != ( T_3 ) - 1 )
F_211 ( V_12 , V_24 , V_28 & 0xff , - 1 ) ;
F_4 ( & V_12 -> V_186 ) ;
return V_287 ;
}
int F_213 ( struct V_11 * V_12 ,
T_2 V_401 ,
T_2 V_402 ,
int type )
{
int V_33 ;
struct V_272 * V_307 ;
struct V_403 * V_404 ;
int V_233 , V_303 = 0 ;
const int V_405 = 1 ;
struct V_191 * V_384 ;
if ( V_12 -> V_406 == V_407 &&
type == V_408 ) {
V_303 = V_405 ;
} else if ( V_12 -> V_406 == V_408 &&
type == V_407 ) {
for ( V_233 = 0 ; V_233 < V_12 -> V_176 . V_50 ; V_233 ++ ) {
V_384 = F_29 ( & V_12 -> V_176 , V_233 ) ;
for ( V_404 = V_409 ; V_404 -> V_135 ; V_404 ++ ) {
V_307 = F_153 ( V_12 , V_404 -> V_135 , 0 , V_233 ) ;
if ( ! V_307 )
break;
V_307 -> V_128 . V_103 = V_405 ;
}
}
V_12 -> V_406 = V_407 ;
}
if ( ! V_12 -> V_406 )
V_12 -> V_406 = type ;
V_233 = F_156 ( V_12 , L_69 , V_303 ) ;
if ( V_233 < 0 ) {
F_14 ( V_30 L_70 ) ;
return - V_185 ;
}
V_384 = F_39 ( & V_12 -> V_176 ) ;
for ( V_404 = V_409 ; V_404 -> V_135 ; V_404 ++ ) {
V_307 = F_188 ( V_404 , V_12 ) ;
if ( ! V_307 )
return - V_78 ;
V_307 -> V_128 . V_103 = V_303 ;
V_307 -> V_128 . V_249 = V_233 ;
V_307 -> V_313 = V_12 -> V_176 . V_50 - 1 ;
V_33 = F_157 ( V_12 , V_401 , V_307 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_384 -> V_24 = V_402 ;
V_384 -> V_398 = F_23 ( V_12 , V_402 , 0 ,
V_410 , 0 ) ;
V_384 -> V_376 = F_205 ( V_384 -> V_398 ) ;
return 0 ;
}
struct V_191 * F_214 ( struct V_11 * V_12 ,
T_2 V_24 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_176 . V_50 ; V_17 ++ ) {
struct V_191 * V_384 =
F_29 ( & V_12 -> V_176 , V_17 ) ;
if ( V_384 -> V_24 == V_24 )
return V_384 ;
}
return NULL ;
}
void F_215 ( struct V_11 * V_12 , int V_233 )
{
struct V_191 * V_384 ;
F_2 ( & V_12 -> V_186 ) ;
V_384 = F_29 ( & V_12 -> V_176 , V_233 ) ;
V_384 -> V_24 = ( T_3 ) - 1 ;
F_4 ( & V_12 -> V_186 ) ;
}
void F_216 ( struct V_11 * V_12 , int V_233 , T_2 V_24 )
{
struct V_191 * V_384 ;
unsigned short V_28 ;
F_2 ( & V_12 -> V_186 ) ;
V_384 = F_29 ( & V_12 -> V_176 , V_233 ) ;
if ( V_384 -> V_24 != V_24 ) {
V_384 -> V_24 = V_24 ;
V_28 = V_384 -> V_398 ;
F_211 ( V_12 , V_24 , V_28 & 0xff , ( V_28 >> 8 ) & 0xff ) ;
}
F_4 ( & V_12 -> V_186 ) ;
}
static int F_217 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_411 * V_412 = F_139 ( V_273 ) ;
V_285 -> V_279 . integer . V_279 [ 0 ] = V_412 -> V_413 ;
return 0 ;
}
static int F_218 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_411 * V_412 = F_139 ( V_273 ) ;
V_412 -> V_413 = ! ! V_285 -> V_279 . integer . V_279 [ 0 ] ;
return 0 ;
}
int F_219 ( struct V_11 * V_12 ,
struct V_411 * V_412 )
{
if ( ! V_412 -> V_414 )
return 0 ;
return F_157 ( V_12 , V_412 -> V_414 ,
F_188 ( & V_415 , V_412 ) ) ;
}
static int F_220 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
V_285 -> V_279 . integer . V_279 [ 0 ] = V_12 -> V_416 ;
return 0 ;
}
static int F_221 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
T_2 V_24 = V_273 -> V_313 ;
unsigned int V_28 = ! ! V_285 -> V_279 . integer . V_279 [ 0 ] ;
int V_287 ;
F_2 ( & V_12 -> V_186 ) ;
V_287 = V_12 -> V_416 != V_28 ;
if ( V_287 ) {
V_12 -> V_416 = V_28 ;
F_207 ( V_12 , V_24 , 0 ,
V_396 , V_28 ) ;
}
F_4 ( & V_12 -> V_186 ) ;
return V_287 ;
}
static int F_222 ( struct V_272 * V_273 ,
struct V_284 * V_285 )
{
struct V_11 * V_12 = F_139 ( V_273 ) ;
T_2 V_24 = V_273 -> V_313 ;
unsigned short V_28 ;
unsigned int V_385 ;
V_28 = F_23 ( V_12 , V_24 , 0 , V_410 , 0 ) ;
V_385 = F_205 ( V_28 ) ;
V_285 -> V_279 . V_375 . V_376 [ 0 ] = V_385 ;
V_285 -> V_279 . V_375 . V_376 [ 1 ] = V_385 >> 8 ;
V_285 -> V_279 . V_375 . V_376 [ 2 ] = V_385 >> 16 ;
V_285 -> V_279 . V_375 . V_376 [ 3 ] = V_385 >> 24 ;
return 0 ;
}
int F_223 ( struct V_11 * V_12 , T_2 V_24 )
{
int V_33 ;
struct V_272 * V_307 ;
struct V_403 * V_404 ;
int V_233 ;
V_233 = F_156 ( V_12 , L_71 , 0 ) ;
if ( V_233 < 0 ) {
F_14 ( V_30 L_72 ) ;
return - V_185 ;
}
for ( V_404 = V_417 ; V_404 -> V_135 ; V_404 ++ ) {
V_307 = F_188 ( V_404 , V_12 ) ;
if ( ! V_307 )
return - V_78 ;
V_307 -> V_313 = V_24 ;
V_33 = F_157 ( V_12 , V_24 , V_307 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_12 -> V_416 =
F_23 ( V_12 , V_24 , 0 ,
V_410 , 0 ) &
V_399 ;
return 0 ;
}
int F_207 ( struct V_11 * V_12 , T_2 V_24 ,
int V_25 , unsigned int V_26 , unsigned int V_27 )
{
int V_33 = F_24 ( V_12 , V_24 , V_25 , V_26 , V_27 ) ;
struct V_189 * V_137 ;
T_1 V_232 ;
if ( V_33 < 0 )
return V_33 ;
V_26 = V_26 | ( V_27 >> 8 ) ;
V_27 &= 0xff ;
V_232 = F_224 ( V_24 , V_26 ) ;
F_2 ( & V_12 -> V_7 -> V_35 ) ;
V_137 = F_117 ( & V_12 -> V_179 , V_232 ) ;
if ( V_137 )
V_137 -> V_28 = V_27 ;
F_4 ( & V_12 -> V_7 -> V_35 ) ;
return 0 ;
}
int F_225 ( struct V_11 * V_12 , T_2 V_24 ,
int V_25 , unsigned int V_26 , unsigned int V_27 )
{
struct V_189 * V_137 ;
T_1 V_232 ;
V_26 = V_26 | ( V_27 >> 8 ) ;
V_27 &= 0xff ;
V_232 = F_224 ( V_24 , V_26 ) ;
F_2 ( & V_12 -> V_7 -> V_35 ) ;
V_137 = F_116 ( & V_12 -> V_179 , V_232 ) ;
if ( V_137 && V_137 -> V_28 == V_27 ) {
F_4 ( & V_12 -> V_7 -> V_35 ) ;
return 0 ;
}
F_4 ( & V_12 -> V_7 -> V_35 ) ;
return F_207 ( V_12 , V_24 , V_25 , V_26 , V_27 ) ;
}
void F_226 ( struct V_11 * V_12 )
{
struct V_189 * V_268 = V_12 -> V_179 . V_231 . V_4 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_179 . V_231 . V_50 ; V_17 ++ , V_268 ++ ) {
T_1 V_232 = V_268 -> V_232 ;
if ( ! V_232 )
continue;
F_24 ( V_12 , F_227 ( V_232 ) , 0 ,
F_228 ( V_232 ) , V_268 -> V_28 ) ;
}
}
void F_229 ( struct V_11 * V_12 ,
const struct V_42 * V_43 )
{
for (; V_43 -> V_24 ; V_43 ++ )
F_207 ( V_12 , V_43 -> V_24 , 0 , V_43 -> V_26 ,
V_43 -> V_44 ) ;
}
void F_230 ( struct V_11 * V_12 , T_2 V_183 ,
unsigned int V_418 ,
bool V_419 )
{
T_2 V_24 = V_12 -> V_156 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_155 ; V_17 ++ , V_24 ++ ) {
unsigned int V_64 = F_36 ( V_12 , V_24 ) ;
if ( ! ( V_64 & V_420 ) )
continue;
if ( V_419 && V_418 == V_421 &&
F_37 ( V_64 ) == V_84 &&
( F_127 ( V_12 , V_24 ) & V_422 ) ) {
int V_423 = F_23 ( V_12 , V_24 , 0 ,
V_424 , 0 ) ;
if ( V_423 & 0x02 )
continue;
}
F_24 ( V_12 , V_24 , 0 , V_425 ,
V_418 ) ;
}
}
static bool F_101 ( struct V_11 * V_12 , T_2 V_183 ,
unsigned int V_418 )
{
int V_426 = F_27 ( V_12 , V_183 , V_427 ) ;
if ( V_426 == - 1 )
return false ;
if ( V_426 & V_418 )
return true ;
else
return false ;
}
static unsigned int F_231 ( struct V_11 * V_12 ,
T_2 V_183 ,
unsigned int V_418 )
{
unsigned long V_428 = V_330 + F_232 ( 500 ) ;
unsigned int V_429 , V_430 ;
for (; ; ) {
V_429 = F_23 ( V_12 , V_183 , 0 ,
V_431 , 0 ) ;
if ( V_429 & V_432 )
break;
V_430 = ( V_429 >> 4 ) & 0x0f ;
if ( V_430 == V_418 )
break;
if ( F_233 ( V_330 , V_428 ) )
break;
F_110 ( 1 ) ;
}
return V_429 ;
}
static unsigned int F_102 ( struct V_11 * V_12 ,
unsigned int V_418 )
{
T_2 V_183 = V_12 -> V_129 ? V_12 -> V_129 : V_12 -> V_130 ;
int V_278 ;
unsigned int V_429 ;
if ( V_418 == V_421 ) {
F_110 ( V_12 -> V_205 ? 10 : 100 ) ;
}
for ( V_278 = 0 ; V_278 < 10 ; V_278 ++ ) {
if ( V_12 -> V_98 . V_433 )
V_12 -> V_98 . V_433 ( V_12 , V_183 ,
V_418 ) ;
else {
F_23 ( V_12 , V_183 , 0 ,
V_425 ,
V_418 ) ;
F_230 ( V_12 , V_183 , V_418 ,
true ) ;
}
V_429 = F_231 ( V_12 , V_183 , V_418 ) ;
if ( ! ( V_429 & V_432 ) )
break;
}
return V_429 ;
}
static void F_234 ( struct V_11 * V_12 )
{
if ( V_12 -> V_434 . V_4 )
F_25 ( V_12 , V_12 -> V_434 . V_4 ) ;
}
static inline void F_234 ( struct V_11 * V_12 ) {}
static unsigned int F_235 ( struct V_11 * V_12 , bool V_435 )
{
unsigned int V_429 ;
V_12 -> V_436 = 1 ;
if ( V_12 -> V_98 . V_437 )
V_12 -> V_98 . V_437 ( V_12 ) ;
F_115 ( V_12 ) ;
V_429 = F_102 ( V_12 , V_421 ) ;
if ( ! V_435 )
F_90 ( & V_12 -> V_173 ) ;
F_164 ( & V_12 -> V_194 ) ;
F_236 ( V_12 ) ;
F_237 ( V_12 ) ;
V_12 -> V_327 = 0 ;
V_12 -> V_328 = 0 ;
V_12 -> V_329 = V_330 ;
F_166 ( & V_12 -> V_194 ) ;
V_12 -> V_436 = 0 ;
return V_429 ;
}
static void F_238 ( struct V_11 * V_12 )
{
V_12 -> V_436 = 1 ;
F_8 ( V_12 ) ;
F_102 ( V_12 , V_207 ) ;
F_82 ( V_12 ) ;
F_234 ( V_12 ) ;
F_84 ( V_12 ) ;
if ( V_12 -> V_98 . V_438 )
V_12 -> V_98 . V_438 ( V_12 ) ;
else {
if ( V_12 -> V_98 . V_439 )
V_12 -> V_98 . V_439 ( V_12 ) ;
F_136 ( V_12 ) ;
F_226 ( V_12 ) ;
}
if ( V_12 -> V_170 )
F_83 ( & V_12 -> V_169 . V_93 ) ;
else
F_239 ( V_12 ) ;
V_12 -> V_436 = 0 ;
F_19 ( V_12 ) ;
}
int F_240 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_57 (codec, &bus->codec_list, list) {
int V_33 = F_241 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_73
L_74 , V_12 -> V_29 , V_33 ) ;
V_33 = F_168 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30
L_75 ) ;
return V_33 ;
}
}
}
return 0 ;
}
static int F_242 ( struct V_11 * V_12 )
{
int V_17 , V_440 , V_33 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_321 ; V_17 ++ ) {
for ( V_440 = 0 ; V_440 < 2 ; V_440 ++ ) {
struct V_441 * V_320 = V_12 -> V_324 [ V_17 ] . V_320 ;
struct V_442 * V_443 =
& V_12 -> V_324 [ V_17 ] . V_444 [ V_440 ] ;
struct V_445 * V_446 ;
const struct V_447 * V_448 ;
if ( V_12 -> V_324 [ V_17 ] . V_449 )
continue;
if ( ! V_320 || ! V_443 -> V_450 )
continue;
V_448 = V_443 -> V_446 ? V_443 -> V_446 : V_451 ;
V_33 = F_243 ( V_320 , V_440 , V_448 ,
V_443 -> V_452 ,
0 , & V_446 ) ;
if ( V_33 < 0 )
return V_33 ;
V_446 -> V_453 = V_454 ;
}
}
return 0 ;
}
int F_241 ( struct V_11 * V_12 )
{
int V_33 = 0 ;
F_234 ( V_12 ) ;
if ( V_12 -> V_98 . V_439 )
V_33 = V_12 -> V_98 . V_439 ( V_12 ) ;
if ( ! V_33 && V_12 -> V_98 . V_455 )
V_33 = V_12 -> V_98 . V_455 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_242 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_12 -> V_170 )
F_83 ( & V_12 -> V_169 . V_93 ) ;
else
F_239 ( V_12 ) ;
return 0 ;
}
unsigned int F_244 ( unsigned int V_456 ,
unsigned int V_457 ,
unsigned int V_217 ,
unsigned int V_458 ,
unsigned short V_459 )
{
int V_17 ;
unsigned int V_28 = 0 ;
for ( V_17 = 0 ; V_460 [ V_17 ] . V_461 ; V_17 ++ )
if ( V_460 [ V_17 ] . V_461 == V_456 ) {
V_28 = V_460 [ V_17 ] . V_462 ;
break;
}
if ( ! V_460 [ V_17 ] . V_461 ) {
F_100 ( L_76 , V_456 ) ;
return 0 ;
}
if ( V_457 == 0 || V_457 > 8 ) {
F_100 ( L_77 , V_457 ) ;
return 0 ;
}
V_28 |= V_457 - 1 ;
switch ( F_245 ( V_217 ) ) {
case 8 :
V_28 |= V_463 ;
break;
case 16 :
V_28 |= V_464 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_458 >= 32 || V_217 == V_465 )
V_28 |= V_466 ;
else if ( V_458 >= 24 )
V_28 |= V_467 ;
else
V_28 |= V_468 ;
break;
default:
F_100 ( L_78 ,
F_245 ( V_217 ) ) ;
return 0 ;
}
if ( V_459 & V_387 )
V_28 |= V_469 ;
return V_28 ;
}
static unsigned int F_246 ( struct V_11 * V_12 , T_2 V_24 ,
int V_245 )
{
unsigned int V_28 = 0 ;
if ( V_24 != V_12 -> V_129 &&
( F_36 ( V_12 , V_24 ) & V_470 ) )
V_28 = F_27 ( V_12 , V_24 , V_471 ) ;
if ( ! V_28 || V_28 == - 1 )
V_28 = F_27 ( V_12 , V_12 -> V_129 , V_471 ) ;
if ( ! V_28 || V_28 == - 1 )
return 0 ;
return V_28 ;
}
static unsigned int F_247 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_123 ( V_12 , V_24 , 0 , F_248 ( V_24 ) ,
F_246 ) ;
}
static unsigned int F_249 ( struct V_11 * V_12 , T_2 V_24 ,
int V_245 )
{
unsigned int V_325 = F_27 ( V_12 , V_24 , V_472 ) ;
if ( ! V_325 || V_325 == - 1 )
V_325 = F_27 ( V_12 , V_12 -> V_129 , V_472 ) ;
if ( ! V_325 || V_325 == - 1 )
return 0 ;
return V_325 ;
}
static unsigned int F_250 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_123 ( V_12 , V_24 , 0 , F_251 ( V_24 ) ,
F_249 ) ;
}
int F_252 ( struct V_11 * V_12 , T_2 V_24 ,
T_1 * V_473 , T_8 * V_474 , unsigned int * V_475 )
{
unsigned int V_17 , V_28 , V_64 ;
V_64 = F_36 ( V_12 , V_24 ) ;
V_28 = F_247 ( V_12 , V_24 ) ;
if ( V_473 ) {
T_1 V_476 = 0 ;
for ( V_17 = 0 ; V_17 < V_477 ; V_17 ++ ) {
if ( V_28 & ( 1 << V_17 ) )
V_476 |= V_460 [ V_17 ] . V_478 ;
}
if ( V_476 == 0 ) {
F_34 ( V_30 L_79
L_80 ,
V_24 , V_28 ,
( V_64 & V_470 ) ? 1 : 0 ) ;
return - V_72 ;
}
* V_473 = V_476 ;
}
if ( V_474 || V_475 ) {
T_8 V_479 = 0 ;
unsigned int V_325 , V_480 ;
V_325 = F_250 ( V_12 , V_24 ) ;
if ( ! V_325 )
return - V_72 ;
V_480 = 0 ;
if ( V_325 & V_481 ) {
if ( V_28 & V_482 ) {
V_479 |= V_483 ;
V_480 = 8 ;
}
if ( V_28 & V_484 ) {
V_479 |= V_485 ;
V_480 = 16 ;
}
if ( V_64 & V_486 ) {
if ( V_28 & V_487 )
V_479 |= V_488 ;
if ( V_28 & ( V_489 | V_490 ) )
V_479 |= V_491 ;
if ( V_28 & V_490 )
V_480 = 24 ;
else if ( V_28 & V_489 )
V_480 = 20 ;
} else if ( V_28 & ( V_489 | V_490 |
V_487 ) ) {
V_479 |= V_491 ;
if ( V_28 & V_487 )
V_480 = 32 ;
else if ( V_28 & V_490 )
V_480 = 24 ;
else if ( V_28 & V_489 )
V_480 = 20 ;
}
}
#if 0
if (streams & AC_SUPFMT_FLOAT32) {
formats |= SNDRV_PCM_FMTBIT_FLOAT_LE;
if (!bps)
bps = 32;
}
#endif
if ( V_325 == V_492 ) {
V_479 |= V_483 ;
V_480 = 8 ;
}
if ( V_479 == 0 ) {
F_34 ( V_30 L_81
L_82
L_83 ,
V_24 , V_28 ,
( V_64 & V_470 ) ? 1 : 0 ,
V_325 ) ;
return - V_72 ;
}
if ( V_474 )
* V_474 = V_479 ;
if ( V_475 )
* V_475 = V_480 ;
}
return 0 ;
}
int F_253 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_217 )
{
int V_17 ;
unsigned int V_28 = 0 , V_456 , V_444 ;
V_28 = F_247 ( V_12 , V_24 ) ;
if ( ! V_28 )
return 0 ;
V_456 = V_217 & 0xff00 ;
for ( V_17 = 0 ; V_17 < V_477 ; V_17 ++ )
if ( V_460 [ V_17 ] . V_462 == V_456 ) {
if ( V_28 & ( 1 << V_17 ) )
break;
return 0 ;
}
if ( V_17 >= V_477 )
return 0 ;
V_444 = F_250 ( V_12 , V_24 ) ;
if ( ! V_444 )
return 0 ;
if ( V_444 & V_481 ) {
switch ( V_217 & 0xf0 ) {
case 0x00 :
if ( ! ( V_28 & V_482 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_28 & V_484 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_28 & V_489 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_28 & V_490 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_28 & V_487 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_254 ( struct V_442 * V_443 ,
struct V_11 * V_12 ,
struct V_493 * V_494 )
{
return 0 ;
}
static int F_255 ( struct V_442 * V_443 ,
struct V_11 * V_12 ,
unsigned int V_211 ,
unsigned int V_217 ,
struct V_493 * V_494 )
{
F_111 ( V_12 , V_443 -> V_24 , V_211 , 0 , V_217 ) ;
return 0 ;
}
static int F_256 ( struct V_442 * V_443 ,
struct V_11 * V_12 ,
struct V_493 * V_494 )
{
F_257 ( V_12 , V_443 -> V_24 ) ;
return 0 ;
}
static int F_258 ( struct V_11 * V_12 ,
struct V_442 * V_235 )
{
int V_33 ;
if ( V_235 -> V_24 && ( ! V_235 -> V_476 || ! V_235 -> V_479 ) ) {
V_33 = F_252 ( V_12 , V_235 -> V_24 ,
V_235 -> V_476 ? NULL : & V_235 -> V_476 ,
V_235 -> V_479 ? NULL : & V_235 -> V_479 ,
V_235 -> V_458 ? NULL : & V_235 -> V_458 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_235 -> V_9 . V_495 == NULL )
V_235 -> V_9 . V_495 = F_254 ;
if ( V_235 -> V_9 . V_496 == NULL )
V_235 -> V_9 . V_496 = F_254 ;
if ( V_235 -> V_9 . V_497 == NULL ) {
if ( F_35 ( ! V_235 -> V_24 ) )
return - V_58 ;
V_235 -> V_9 . V_497 = F_255 ;
}
if ( V_235 -> V_9 . V_498 == NULL ) {
if ( F_35 ( ! V_235 -> V_24 ) )
return - V_58 ;
V_235 -> V_9 . V_498 = F_256 ;
}
return 0 ;
}
int F_259 ( struct V_11 * V_12 ,
struct V_442 * V_443 ,
unsigned int V_444 ,
unsigned int V_217 ,
struct V_493 * V_494 )
{
int V_267 ;
F_2 ( & V_12 -> V_7 -> V_119 ) ;
V_267 = V_443 -> V_9 . V_497 ( V_443 , V_12 , V_444 , V_217 , V_494 ) ;
if ( V_267 >= 0 )
F_114 ( V_12 ) ;
F_4 ( & V_12 -> V_7 -> V_119 ) ;
return V_267 ;
}
void F_260 ( struct V_11 * V_12 ,
struct V_442 * V_443 ,
struct V_493 * V_494 )
{
F_2 ( & V_12 -> V_7 -> V_119 ) ;
V_443 -> V_9 . V_498 ( V_443 , V_12 , V_494 ) ;
F_4 ( & V_12 -> V_7 -> V_119 ) ;
}
static int F_261 ( struct V_6 * V_7 , int type )
{
static int V_499 [ V_500 ] [ 5 ] = {
[ V_501 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_408 ] = { 1 , - 1 } ,
[ V_407 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_502 ] = { 6 , - 1 } ,
} ;
int V_17 ;
if ( type >= V_500 ) {
F_34 ( V_75 L_84 , type ) ;
return - V_58 ;
}
for ( V_17 = 0 ; V_499 [ type ] [ V_17 ] >= 0 ; V_17 ++ )
if ( ! F_262 ( V_499 [ type ] [ V_17 ] , V_7 -> V_331 ) )
return V_499 [ type ] [ V_17 ] ;
for ( V_17 = 10 ; V_17 < 32 ; V_17 ++ ) {
if ( ! F_262 ( V_17 , V_7 -> V_331 ) )
return V_17 ;
}
F_34 ( V_75 L_85 ,
V_503 [ type ] ) ;
return - V_504 ;
}
static int F_263 ( struct V_11 * V_12 , struct V_322 * V_320 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_442 * V_235 ;
int V_444 , V_33 ;
if ( F_35 ( ! V_320 -> V_135 ) )
return - V_58 ;
for ( V_444 = 0 ; V_444 < 2 ; V_444 ++ ) {
V_235 = & V_320 -> V_444 [ V_444 ] ;
if ( V_235 -> V_450 ) {
V_33 = F_258 ( V_12 , V_235 ) ;
if ( V_33 < 0 )
return V_33 ;
}
}
return V_7 -> V_9 . V_505 ( V_7 , V_12 , V_320 ) ;
}
int F_264 ( struct V_11 * V_12 )
{
unsigned int V_320 ;
int V_33 ;
if ( ! V_12 -> V_321 ) {
if ( ! V_12 -> V_98 . V_506 )
return 0 ;
V_33 = V_12 -> V_98 . V_506 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_86
L_74 , V_12 -> V_29 , V_33 ) ;
V_33 = F_168 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30
L_75 ) ;
return V_33 ;
}
}
}
for ( V_320 = 0 ; V_320 < V_12 -> V_321 ; V_320 ++ ) {
struct V_322 * V_323 = & V_12 -> V_324 [ V_320 ] ;
int V_303 ;
if ( ! V_323 -> V_444 [ 0 ] . V_450 && ! V_323 -> V_444 [ 1 ] . V_450 )
continue;
if ( ! V_323 -> V_320 ) {
V_303 = F_261 ( V_12 -> V_7 , V_323 -> V_507 ) ;
if ( V_303 < 0 )
continue;
V_323 -> V_103 = V_303 ;
V_33 = F_263 ( V_12 , V_323 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_87
L_88 ,
V_303 , V_12 -> V_29 ) ;
continue;
}
}
}
return 0 ;
}
int F_265 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_57 (codec, &bus->codec_list, list) {
int V_33 = F_264 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
}
return 0 ;
}
int F_266 ( struct V_11 * V_12 ,
int V_508 , const char * const * V_509 ,
const struct V_510 * V_125 )
{
if ( V_12 -> V_117 && V_509 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_508 ; V_17 ++ ) {
if ( V_509 [ V_17 ] &&
! strcmp ( V_12 -> V_117 , V_509 [ V_17 ] ) ) {
F_21 ( V_511 L_89
L_90 , V_509 [ V_17 ] ) ;
return V_17 ;
}
}
}
if ( ! V_12 -> V_7 -> V_116 || ! V_125 )
return - 1 ;
V_125 = F_267 ( V_12 -> V_7 -> V_116 , V_125 ) ;
if ( ! V_125 )
return - 1 ;
if ( V_125 -> V_279 >= 0 && V_125 -> V_279 < V_508 ) {
#ifdef F_268
char V_139 [ 10 ] ;
const char * V_512 = NULL ;
if ( V_509 )
V_512 = V_509 [ V_125 -> V_279 ] ;
if ( ! V_512 ) {
sprintf ( V_139 , L_91 , V_125 -> V_279 ) ;
V_512 = V_139 ;
}
F_100 ( V_511 L_92
L_93 ,
V_512 , V_125 -> V_513 , V_125 -> V_310 ,
( V_125 -> V_135 ? V_125 -> V_135 : L_94 ) ) ;
#endif
return V_125 -> V_279 ;
}
return - 1 ;
}
int F_269 ( struct V_11 * V_12 ,
int V_508 , const char * const * V_509 ,
const struct V_510 * V_125 )
{
const struct V_510 * V_226 ;
for ( V_226 = V_125 ; V_226 -> V_513 ; V_226 ++ ) {
unsigned int V_63 = 0xffff0000 | V_226 -> V_514 ;
unsigned int V_128 = ( V_226 -> V_310 | ( V_226 -> V_513 << 16 ) ) & V_63 ;
if ( ( V_12 -> V_198 & V_63 ) == V_128 )
break;
}
if ( ! V_226 -> V_513 )
return - 1 ;
V_125 = V_226 ;
if ( V_125 -> V_279 >= 0 && V_125 -> V_279 < V_508 ) {
#ifdef F_268
char V_139 [ 10 ] ;
const char * V_512 = NULL ;
if ( V_509 )
V_512 = V_509 [ V_125 -> V_279 ] ;
if ( ! V_512 ) {
sprintf ( V_139 , L_91 , V_125 -> V_279 ) ;
V_512 = V_139 ;
}
F_100 ( V_511 L_92
L_93 ,
V_512 , V_125 -> V_513 , V_125 -> V_310 ,
( V_125 -> V_135 ? V_125 -> V_135 : L_94 ) ) ;
#endif
return V_125 -> V_279 ;
}
return - 1 ;
}
int F_270 ( struct V_11 * V_12 ,
const struct V_403 * V_515 )
{
int V_33 ;
for (; V_515 -> V_135 ; V_515 ++ ) {
struct V_272 * V_307 ;
int V_29 = 0 , V_233 = 0 ;
if ( V_515 -> V_305 == - 1 )
continue;
for (; ; ) {
V_307 = F_188 ( V_515 , V_12 ) ;
if ( ! V_307 )
return - V_78 ;
if ( V_29 > 0 )
V_307 -> V_128 . V_103 = V_29 ;
if ( V_233 > 0 )
V_307 -> V_128 . V_249 = V_233 ;
V_33 = F_157 ( V_12 , 0 , V_307 ) ;
if ( ! V_33 )
break;
if ( ! V_29 && V_12 -> V_29 )
V_29 = V_12 -> V_29 ;
else if ( ! V_233 && ! V_515 -> V_249 ) {
V_233 = F_156 ( V_12 ,
V_515 -> V_135 , 0 ) ;
if ( V_233 <= 0 )
return V_33 ;
} else
return V_33 ;
}
}
return 0 ;
}
static void V_195 ( struct V_94 * V_93 )
{
struct V_11 * V_12 =
F_45 ( V_93 , struct V_11 , V_173 . V_93 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
unsigned int V_429 ;
F_164 ( & V_12 -> V_194 ) ;
if ( V_12 -> V_328 > 0 ) {
F_166 ( & V_12 -> V_194 ) ;
return;
}
if ( ! V_12 -> V_327 || V_12 -> V_516 ) {
V_12 -> V_328 = 0 ;
F_166 ( & V_12 -> V_194 ) ;
return;
}
F_166 ( & V_12 -> V_194 ) ;
V_429 = F_235 ( V_12 , true ) ;
V_12 -> V_177 = 0 ;
if ( ! V_7 -> V_204 && ( V_429 & V_517 ) ) {
V_12 -> V_177 = 1 ;
F_7 ( V_7 , false ) ;
}
}
static void F_8 ( struct V_11 * V_12 )
{
F_164 ( & V_12 -> V_194 ) ;
V_12 -> V_516 ++ ;
V_12 -> V_327 = 1 ;
V_12 -> V_329 = V_330 ;
F_166 ( & V_12 -> V_194 ) ;
}
void F_236 ( struct V_11 * V_12 )
{
unsigned long V_518 = V_330 - V_12 -> V_329 ;
if ( V_12 -> V_327 )
V_12 -> V_519 += V_518 ;
else
V_12 -> V_520 += V_518 ;
V_12 -> V_329 += V_518 ;
}
static void F_271 ( struct V_11 * V_12 , bool V_521 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
if ( ( V_12 -> V_327 || V_12 -> V_328 > 0 ) &&
! ( V_521 && V_12 -> V_328 < 0 ) )
return;
F_166 ( & V_12 -> V_194 ) ;
F_90 ( & V_12 -> V_173 ) ;
F_164 ( & V_12 -> V_194 ) ;
if ( V_12 -> V_327 ) {
if ( V_12 -> V_328 < 0 )
V_12 -> V_328 = 0 ;
return;
}
F_272 ( V_12 ) ;
F_236 ( V_12 ) ;
V_12 -> V_327 = 1 ;
V_12 -> V_329 = V_330 ;
V_12 -> V_328 = 1 ;
F_166 ( & V_12 -> V_194 ) ;
if ( V_12 -> V_177 ) {
V_12 -> V_177 = 0 ;
F_7 ( V_7 , true ) ;
}
F_238 ( V_12 ) ;
F_164 ( & V_12 -> V_194 ) ;
V_12 -> V_328 = 0 ;
}
static void F_273 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_327 || V_12 -> V_516 || V_12 -> V_328 )
return;
if ( V_118 ( V_12 ) ) {
V_12 -> V_328 = - 1 ;
F_86 ( V_12 -> V_7 -> V_92 , & V_12 -> V_173 ,
F_232 ( V_118 ( V_12 ) * 1000 ) ) ;
}
}
void F_274 ( struct V_11 * V_12 , int V_518 , bool V_522 )
{
F_164 ( & V_12 -> V_194 ) ;
V_12 -> V_516 += V_518 ;
F_275 ( V_12 ) ;
if ( V_518 > 0 )
F_271 ( V_12 , V_522 ) ;
else
F_273 ( V_12 ) ;
F_166 ( & V_12 -> V_194 ) ;
}
int F_276 ( struct V_11 * V_12 ,
struct V_523 * V_524 ,
T_2 V_24 )
{
const struct V_525 * V_51 ;
int V_248 , V_526 ;
if ( ! V_524 -> V_527 )
return 0 ;
for ( V_51 = V_524 -> V_527 ; V_51 -> V_24 ; V_51 ++ ) {
if ( V_51 -> V_24 == V_24 )
break;
}
if ( ! V_51 -> V_24 )
return 0 ;
for ( V_51 = V_524 -> V_527 ; V_51 -> V_24 ; V_51 ++ ) {
for ( V_248 = 0 ; V_248 < 2 ; V_248 ++ ) {
V_526 = F_133 ( V_12 , V_51 -> V_24 , V_248 , V_51 -> V_245 ,
V_51 -> V_233 ) ;
if ( ! ( V_526 & V_263 ) && V_526 > 0 ) {
if ( ! V_524 -> V_327 ) {
V_524 -> V_327 = 1 ;
F_16 ( V_12 ) ;
}
return 1 ;
}
}
}
if ( V_524 -> V_327 ) {
V_524 -> V_327 = 0 ;
F_19 ( V_12 ) ;
}
return 0 ;
}
int F_277 ( struct V_11 * V_12 ,
struct V_274 * V_275 ,
const struct V_528 * V_529 ,
int V_530 )
{
V_275 -> type = V_355 ;
V_275 -> V_278 = 1 ;
V_275 -> V_279 . V_356 . V_315 = V_530 ;
if ( V_275 -> V_279 . V_356 . V_309 >= V_530 )
V_275 -> V_279 . V_356 . V_309 = V_530 - 1 ;
sprintf ( V_275 -> V_279 . V_356 . V_135 , L_95 ,
V_529 [ V_275 -> V_279 . V_356 . V_309 ] . V_457 ) ;
return 0 ;
}
int F_278 ( struct V_11 * V_12 ,
struct V_284 * V_285 ,
const struct V_528 * V_529 ,
int V_530 ,
int V_531 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_530 ; V_17 ++ ) {
if ( V_531 == V_529 [ V_17 ] . V_457 ) {
V_285 -> V_279 . V_356 . V_309 [ 0 ] = V_17 ;
break;
}
}
return 0 ;
}
int F_279 ( struct V_11 * V_12 ,
struct V_284 * V_285 ,
const struct V_528 * V_529 ,
int V_530 ,
int * V_532 )
{
unsigned int V_533 ;
V_533 = V_285 -> V_279 . V_356 . V_309 [ 0 ] ;
if ( V_533 >= V_530 )
return - V_58 ;
if ( * V_532 == V_529 [ V_533 ] . V_457 )
return 0 ;
* V_532 = V_529 [ V_533 ] . V_457 ;
if ( V_529 [ V_533 ] . V_534 )
F_229 ( V_12 , V_529 [ V_533 ] . V_534 ) ;
return 1 ;
}
int F_280 ( const struct V_535 * V_536 ,
struct V_274 * V_275 )
{
unsigned int V_249 ;
V_275 -> type = V_355 ;
V_275 -> V_278 = 1 ;
V_275 -> V_279 . V_356 . V_315 = V_536 -> V_537 ;
if ( ! V_536 -> V_537 )
return 0 ;
V_249 = V_275 -> V_279 . V_356 . V_309 ;
if ( V_249 >= V_536 -> V_537 )
V_249 = V_536 -> V_537 - 1 ;
strcpy ( V_275 -> V_279 . V_356 . V_135 , V_536 -> V_315 [ V_249 ] . V_538 ) ;
return 0 ;
}
int F_281 ( struct V_11 * V_12 ,
const struct V_535 * V_536 ,
struct V_284 * V_285 ,
T_2 V_24 ,
unsigned int * V_539 )
{
unsigned int V_233 ;
if ( ! V_536 -> V_537 )
return 0 ;
V_233 = V_285 -> V_279 . V_356 . V_309 [ 0 ] ;
if ( V_233 >= V_536 -> V_537 )
V_233 = V_536 -> V_537 - 1 ;
if ( * V_539 == V_233 )
return 0 ;
F_207 ( V_12 , V_24 , 0 , V_540 ,
V_536 -> V_315 [ V_233 ] . V_249 ) ;
* V_539 = V_233 ;
return 1 ;
}
int F_282 ( struct V_272 * V_273 ,
struct V_274 * V_275 ,
int V_537 , const char * const * V_354 )
{
static const char * const V_541 [] = {
L_96 , L_97
} ;
if ( ! V_354 || ! V_537 ) {
V_537 = 2 ;
V_354 = V_541 ;
}
V_275 -> type = V_355 ;
V_275 -> V_278 = 1 ;
V_275 -> V_279 . V_356 . V_315 = V_537 ;
if ( V_275 -> V_279 . V_356 . V_309 >= V_275 -> V_279 . V_356 . V_315 )
V_275 -> V_279 . V_356 . V_309 = V_275 -> V_279 . V_356 . V_315 - 1 ;
strcpy ( V_275 -> V_279 . V_356 . V_135 ,
V_354 [ V_275 -> V_279 . V_356 . V_309 ] ) ;
return 0 ;
}
static void F_283 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_211 , unsigned int V_217 )
{
struct V_191 * V_384 ;
unsigned int V_542 ;
bool V_543 ;
V_384 = F_214 ( V_12 , V_24 ) ;
V_542 = F_23 ( V_12 , V_24 , 0 ,
V_219 , 0 ) ;
V_543 = V_12 -> V_335 &&
( V_384 -> V_398 & V_399 ) &&
V_542 != V_217 ;
if ( V_543 )
F_208 ( V_12 , V_24 ,
V_384 -> V_398 & ~ V_399 & 0xff ,
- 1 ) ;
F_111 ( V_12 , V_24 , V_211 , 0 , V_217 ) ;
if ( V_12 -> V_334 ) {
const T_2 * V_393 ;
for ( V_393 = V_12 -> V_334 ; * V_393 ; V_393 ++ )
F_111 ( V_12 , * V_393 , V_211 , 0 ,
V_217 ) ;
}
if ( V_543 )
F_208 ( V_12 , V_24 ,
V_384 -> V_398 & 0xff , - 1 ) ;
}
static void F_284 ( struct V_11 * V_12 , T_2 V_24 )
{
F_257 ( V_12 , V_24 ) ;
if ( V_12 -> V_334 ) {
const T_2 * V_393 ;
for ( V_393 = V_12 -> V_334 ; * V_393 ; V_393 ++ )
F_257 ( V_12 , * V_393 ) ;
}
}
void F_285 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
if ( ! V_7 )
return;
F_57 (codec, &bus->codec_list, list) {
if ( F_286 ( V_12 ) &&
V_12 -> V_98 . V_544 )
V_12 -> V_98 . V_544 ( V_12 ) ;
}
}
int F_287 ( struct V_11 * V_12 ,
struct V_411 * V_412 )
{
F_2 ( & V_12 -> V_186 ) ;
if ( V_412 -> V_545 == V_546 )
F_284 ( V_12 , V_412 -> V_414 ) ;
V_412 -> V_545 = V_547 ;
F_4 ( & V_12 -> V_186 ) ;
return 0 ;
}
int F_288 ( struct V_11 * V_12 ,
struct V_411 * V_412 ,
unsigned int V_211 ,
unsigned int V_217 ,
struct V_493 * V_494 )
{
F_2 ( & V_12 -> V_186 ) ;
F_283 ( V_12 , V_412 -> V_414 , V_211 , V_217 ) ;
F_4 ( & V_12 -> V_186 ) ;
return 0 ;
}
int F_289 ( struct V_11 * V_12 ,
struct V_411 * V_412 )
{
F_2 ( & V_12 -> V_186 ) ;
F_284 ( V_12 , V_412 -> V_414 ) ;
F_4 ( & V_12 -> V_186 ) ;
return 0 ;
}
int F_290 ( struct V_11 * V_12 ,
struct V_411 * V_412 )
{
F_2 ( & V_12 -> V_186 ) ;
V_412 -> V_545 = 0 ;
F_4 ( & V_12 -> V_186 ) ;
return 0 ;
}
int F_291 ( struct V_11 * V_12 ,
struct V_411 * V_412 ,
struct V_493 * V_494 ,
struct V_442 * V_443 )
{
struct V_548 * V_549 = V_494 -> V_549 ;
V_549 -> V_550 . V_452 = V_412 -> V_531 ;
if ( V_412 -> V_414 ) {
if ( ! V_412 -> V_551 ) {
V_412 -> V_551 = V_443 -> V_476 ;
V_412 -> V_552 = V_443 -> V_479 ;
V_412 -> V_553 = V_443 -> V_458 ;
} else {
V_549 -> V_550 . V_476 = V_412 -> V_551 ;
V_549 -> V_550 . V_479 = V_412 -> V_552 ;
V_443 -> V_458 = V_412 -> V_553 ;
}
if ( ! V_412 -> V_554 ) {
F_252 ( V_12 , V_412 -> V_414 ,
& V_412 -> V_554 ,
& V_412 -> V_555 ,
& V_412 -> V_556 ) ;
}
F_2 ( & V_12 -> V_186 ) ;
if ( V_412 -> V_413 ) {
if ( ( V_549 -> V_550 . V_476 & V_412 -> V_554 ) &&
( V_549 -> V_550 . V_479 & V_412 -> V_555 ) ) {
V_549 -> V_550 . V_476 &= V_412 -> V_554 ;
V_549 -> V_550 . V_479 &= V_412 -> V_555 ;
if ( V_412 -> V_556 < V_443 -> V_458 )
V_443 -> V_458 = V_412 -> V_556 ;
} else {
V_412 -> V_413 = 0 ;
}
}
F_4 ( & V_12 -> V_186 ) ;
}
return F_292 ( V_494 -> V_549 , 0 ,
V_557 , 2 ) ;
}
int F_293 ( struct V_11 * V_12 ,
struct V_411 * V_412 ,
unsigned int V_211 ,
unsigned int V_217 ,
struct V_493 * V_494 )
{
const T_2 * V_175 = V_412 -> V_558 ;
int V_276 = V_494 -> V_549 -> V_457 ;
struct V_191 * V_384 ;
int V_17 ;
F_2 ( & V_12 -> V_186 ) ;
V_384 = F_214 ( V_12 , V_412 -> V_414 ) ;
if ( V_412 -> V_414 && V_412 -> V_413 &&
V_412 -> V_545 != V_547 ) {
if ( V_276 == 2 &&
F_253 ( V_12 , V_412 -> V_414 ,
V_217 ) &&
! ( V_384 -> V_376 & V_378 ) ) {
V_412 -> V_545 = V_546 ;
F_283 ( V_12 , V_412 -> V_414 ,
V_211 , V_217 ) ;
} else {
V_412 -> V_545 = 0 ;
F_284 ( V_12 , V_412 -> V_414 ) ;
}
}
F_4 ( & V_12 -> V_186 ) ;
F_111 ( V_12 , V_175 [ V_559 ] , V_211 ,
0 , V_217 ) ;
if ( ! V_412 -> V_560 &&
V_412 -> V_561 && V_412 -> V_561 != V_175 [ V_559 ] )
F_111 ( V_12 , V_412 -> V_561 , V_211 ,
0 , V_217 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_412 -> V_562 ) ; V_17 ++ )
if ( ! V_412 -> V_560 && V_412 -> V_562 [ V_17 ] )
F_111 ( V_12 ,
V_412 -> V_562 [ V_17 ] ,
V_211 , 0 , V_217 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_412 -> V_563 ) ; V_17 ++ )
if ( ! V_412 -> V_560 && V_412 -> V_563 [ V_17 ] )
F_111 ( V_12 ,
V_412 -> V_563 [ V_17 ] ,
V_211 , 0 , V_217 ) ;
for ( V_17 = 1 ; V_17 < V_412 -> V_564 ; V_17 ++ ) {
if ( V_276 >= ( V_17 + 1 ) * 2 )
F_111 ( V_12 , V_175 [ V_17 ] , V_211 ,
V_17 * 2 , V_217 ) ;
else if ( ! V_412 -> V_560 )
F_111 ( V_12 , V_175 [ V_17 ] , V_211 ,
0 , V_217 ) ;
}
return 0 ;
}
int F_294 ( struct V_11 * V_12 ,
struct V_411 * V_412 )
{
const T_2 * V_175 = V_412 -> V_558 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_412 -> V_564 ; V_17 ++ )
F_257 ( V_12 , V_175 [ V_17 ] ) ;
if ( V_412 -> V_561 )
F_257 ( V_12 , V_412 -> V_561 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_412 -> V_562 ) ; V_17 ++ )
if ( V_412 -> V_562 [ V_17 ] )
F_257 ( V_12 ,
V_412 -> V_562 [ V_17 ] ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_412 -> V_563 ) ; V_17 ++ )
if ( V_412 -> V_563 [ V_17 ] )
F_257 ( V_12 ,
V_412 -> V_563 [ V_17 ] ) ;
F_2 ( & V_12 -> V_186 ) ;
if ( V_412 -> V_414 && V_412 -> V_545 == V_546 ) {
F_284 ( V_12 , V_412 -> V_414 ) ;
V_412 -> V_545 = 0 ;
}
F_4 ( & V_12 -> V_186 ) ;
return 0 ;
}
unsigned int F_295 ( struct V_11 * V_12 , T_2 V_159 )
{
unsigned int V_565 ;
unsigned int V_213 ;
V_213 = F_23 ( V_12 , V_159 , 0 ,
V_164 , 0 ) ;
V_565 = F_127 ( V_12 , V_159 ) ;
V_565 = ( V_565 & V_566 ) >> V_567 ;
if ( ( V_565 & V_568 ) && V_213 != V_569 )
return V_570 ;
else if ( V_565 & V_571 )
return V_572 ;
else if ( V_565 & V_573 )
return V_574 ;
else if ( V_565 & V_575 )
return V_576 ;
return V_577 ;
}
int F_296 ( struct V_11 * V_12 , T_2 V_159 ,
unsigned int V_28 , bool V_578 )
{
if ( V_28 ) {
unsigned int V_579 = F_127 ( V_12 , V_159 ) ;
if ( V_579 && ( V_28 & V_580 ) ) {
if ( ! ( V_579 & V_581 ) )
V_28 &= ~ ( V_580 | V_582 ) ;
else if ( ( V_28 & V_582 ) &&
! ( V_579 & V_583 ) )
V_28 &= ~ V_582 ;
}
if ( V_579 && ( V_28 & V_584 ) ) {
if ( ! ( V_579 & V_585 ) )
V_28 &= ~ ( V_584 | V_586 ) ;
}
}
if ( V_578 )
return F_225 ( V_12 , V_159 , 0 ,
V_167 , V_28 ) ;
else
return F_24 ( V_12 , V_159 , 0 ,
V_167 , V_28 ) ;
}
int F_297 ( struct V_535 * V_536 , const char * V_538 ,
int V_249 , int * V_587 )
{
int V_17 , V_588 = 0 ;
if ( V_536 -> V_537 >= V_82 ) {
F_21 ( V_30 L_98 ) ;
return - V_58 ;
}
for ( V_17 = 0 ; V_17 < V_536 -> V_537 ; V_17 ++ ) {
if ( ! strncmp ( V_538 , V_536 -> V_315 [ V_17 ] . V_538 , strlen ( V_538 ) ) )
V_588 ++ ;
}
if ( V_587 )
* V_587 = V_588 ;
if ( V_588 > 0 )
snprintf ( V_536 -> V_315 [ V_536 -> V_537 ] . V_538 ,
sizeof( V_536 -> V_315 [ V_536 -> V_537 ] . V_538 ) ,
L_99 , V_538 , V_588 ) ;
else
F_298 ( V_536 -> V_315 [ V_536 -> V_537 ] . V_538 , V_538 ,
sizeof( V_536 -> V_315 [ V_536 -> V_537 ] . V_538 ) ) ;
V_536 -> V_315 [ V_536 -> V_537 ] . V_249 = V_249 ;
V_536 -> V_537 ++ ;
return 0 ;
}
int F_299 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_57 (codec, &bus->codec_list, list) {
F_90 ( & V_12 -> V_169 ) ;
if ( F_286 ( V_12 ) )
F_235 ( V_12 , false ) ;
}
return 0 ;
}
int F_300 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_57 (codec, &bus->codec_list, list) {
F_238 ( V_12 ) ;
}
return 0 ;
}
void * F_39 ( struct V_47 * V_48 )
{
if ( F_35 ( ! V_48 -> V_589 ) )
return NULL ;
if ( V_48 -> V_50 >= V_48 -> V_590 ) {
int V_591 = V_48 -> V_590 + V_48 -> V_592 ;
int V_289 = ( V_591 + 1 ) * V_48 -> V_589 ;
int V_593 = V_48 -> V_590 * V_48 -> V_589 ;
void * V_594 ;
if ( F_35 ( V_591 >= 4096 ) )
return NULL ;
V_594 = F_301 ( V_48 -> V_4 , V_289 , V_100 ) ;
if ( ! V_594 )
return NULL ;
memset ( V_594 + V_593 , 0 , V_289 - V_593 ) ;
V_48 -> V_4 = V_594 ;
V_48 -> V_590 = V_591 ;
}
return F_29 ( V_48 , V_48 -> V_50 ++ ) ;
}
void F_88 ( struct V_47 * V_48 )
{
F_51 ( V_48 -> V_4 ) ;
V_48 -> V_50 = 0 ;
V_48 -> V_590 = 0 ;
V_48 -> V_4 = NULL ;
}
void F_302 ( int V_320 , char * V_231 , int V_595 )
{
static unsigned int V_596 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_17 , V_597 ;
for ( V_17 = 0 , V_597 = 0 ; V_17 < F_10 ( V_596 ) ; V_17 ++ )
if ( V_320 & ( V_482 << V_17 ) )
V_597 += snprintf ( V_231 + V_597 , V_595 - V_597 , L_100 , V_596 [ V_17 ] ) ;
V_231 [ V_597 ] = '\0' ;
}
