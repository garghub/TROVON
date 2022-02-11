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
if ( ( V_12 -> V_29 & ~ 0xf ) || ( V_24 & ~ 0x7f ) ||
( V_26 & ~ 0xfff ) || ( V_27 & ~ 0xffff ) ) {
F_14 ( V_30 L_36 ,
V_12 -> V_29 , V_24 , V_26 , V_27 ) ;
return ~ 0 ;
}
V_28 = ( T_1 ) V_12 -> V_29 << 28 ;
V_28 |= ( T_1 ) V_24 << 20 ;
V_28 |= V_26 << 8 ;
V_28 |= V_27 ;
return V_28 ;
}
static int F_15 ( struct V_11 * V_12 , unsigned int V_31 ,
int V_25 , unsigned int * V_32 )
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
if ( V_25 & V_36 )
V_7 -> V_37 = 1 ;
for (; ; ) {
F_17 ( V_12 , V_31 ) ;
V_33 = V_7 -> V_9 . V_38 ( V_7 , V_31 ) ;
if ( V_33 != - V_39 )
break;
V_7 -> V_9 . V_40 ( V_7 , V_12 -> V_29 ) ;
}
if ( ! V_33 && V_32 ) {
* V_32 = V_7 -> V_9 . V_40 ( V_7 , V_12 -> V_29 ) ;
F_18 ( V_12 , * V_32 ) ;
}
V_7 -> V_37 = 0 ;
F_4 ( & V_7 -> V_35 ) ;
F_19 ( V_12 ) ;
if ( ! F_20 ( V_12 ) && V_32 && * V_32 == - 1 && V_7 -> V_41 ) {
if ( V_7 -> V_42 ) {
F_21 ( L_37
L_38 ) ;
F_22 ( V_7 ) ;
V_7 -> V_9 . V_43 ( V_7 ) ;
}
goto V_34;
}
if ( ! V_33 || F_20 ( V_12 ) )
V_7 -> V_42 = 0 ;
return V_33 ;
}
unsigned int F_23 ( struct V_11 * V_12 , T_2 V_24 ,
int V_25 ,
unsigned int V_26 , unsigned int V_27 )
{
unsigned V_31 = F_13 ( V_12 , V_24 , V_25 , V_26 , V_27 ) ;
unsigned int V_32 ;
if ( F_15 ( V_12 , V_31 , V_25 , & V_32 ) )
return - 1 ;
return V_32 ;
}
int F_24 ( struct V_11 * V_12 , T_2 V_24 , int V_25 ,
unsigned int V_26 , unsigned int V_27 )
{
unsigned int V_31 = F_13 ( V_12 , V_24 , V_25 , V_26 , V_27 ) ;
unsigned int V_32 ;
return F_15 ( V_12 , V_31 , V_25 ,
V_12 -> V_7 -> V_44 ? & V_32 : NULL ) ;
}
void F_25 ( struct V_11 * V_12 , const struct V_45 * V_46 )
{
for (; V_46 -> V_24 ; V_46 ++ )
F_24 ( V_12 , V_46 -> V_24 , 0 , V_46 -> V_26 , V_46 -> V_47 ) ;
}
int F_26 ( struct V_11 * V_12 , T_2 V_24 ,
T_2 * V_48 )
{
unsigned int V_27 ;
V_27 = F_27 ( V_12 , V_24 , V_49 ) ;
if ( V_27 == - 1 )
return 0 ;
* V_48 = ( V_27 >> 16 ) & 0x7fff ;
return ( int ) ( V_27 & 0x7fff ) ;
}
static struct V_50 *
F_28 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_50 * V_51 ;
F_29 (p, &codec->conn_list, list) {
if ( V_51 -> V_24 == V_24 )
return V_51 ;
}
return NULL ;
}
static int F_30 ( struct V_11 * V_12 , T_2 V_24 , int V_52 ,
const T_2 * V_4 )
{
struct V_50 * V_51 ;
V_51 = F_31 ( sizeof( * V_51 ) + V_52 * sizeof( T_2 ) , V_53 ) ;
if ( ! V_51 )
return - V_54 ;
V_51 -> V_52 = V_52 ;
V_51 -> V_24 = V_24 ;
memcpy ( V_51 -> V_55 , V_4 , V_52 * sizeof( T_2 ) ) ;
F_32 ( & V_51 -> V_4 , & V_12 -> V_56 ) ;
return 0 ;
}
static void F_33 ( struct V_11 * V_12 )
{
while ( ! F_34 ( & V_12 -> V_56 ) ) {
struct V_50 * V_51 ;
V_51 = F_35 ( & V_12 -> V_56 , F_36 ( * V_51 ) , V_4 ) ;
F_6 ( & V_51 -> V_4 ) ;
F_37 ( V_51 ) ;
}
}
static int F_38 ( struct V_11 * V_12 , T_2 V_24 )
{
T_2 V_4 [ 32 ] ;
T_2 * V_57 = V_4 ;
int V_52 ;
V_52 = F_39 ( V_12 , V_24 , V_4 , F_10 ( V_4 ) ) ;
if ( V_52 == - V_58 ) {
V_52 = F_40 ( V_12 , V_24 ) ;
V_57 = F_31 ( sizeof( T_2 ) * V_52 , V_53 ) ;
if ( ! V_57 )
return - V_54 ;
V_52 = F_39 ( V_12 , V_24 , V_57 , V_52 ) ;
}
if ( V_52 >= 0 )
V_52 = F_41 ( V_12 , V_24 , V_52 , V_57 ) ;
if ( V_57 != V_4 )
F_37 ( V_57 ) ;
return V_52 ;
}
int F_42 ( struct V_11 * V_12 , T_2 V_24 ,
const T_2 * * V_59 )
{
bool V_60 = false ;
for (; ; ) {
int V_33 ;
const struct V_50 * V_51 ;
V_51 = F_28 ( V_12 , V_24 ) ;
if ( V_51 ) {
if ( V_59 )
* V_59 = V_51 -> V_55 ;
return V_51 -> V_52 ;
}
if ( F_43 ( V_60 ) )
return - V_61 ;
V_33 = F_38 ( V_12 , V_24 ) ;
if ( V_33 < 0 )
return V_33 ;
V_60 = true ;
}
}
int F_44 ( struct V_11 * V_12 , T_2 V_24 ,
T_2 * V_56 , int V_62 )
{
const T_2 * V_4 ;
int V_52 = F_42 ( V_12 , V_24 , & V_4 ) ;
if ( V_52 > 0 && V_56 ) {
if ( V_52 > V_62 ) {
F_45 ( V_30 L_39
L_40 ,
V_52 , V_24 ) ;
return - V_61 ;
}
memcpy ( V_56 , V_4 , V_52 * sizeof( T_2 ) ) ;
}
return V_52 ;
}
static unsigned int F_46 ( struct V_11 * V_12 , T_2 V_24 )
{
unsigned int V_63 = F_47 ( V_12 , V_24 ) ;
unsigned int V_27 ;
if ( ! ( V_63 & V_64 ) &&
F_48 ( V_63 ) != V_65 )
return 0 ;
V_27 = F_27 ( V_12 , V_24 , V_66 ) ;
if ( V_27 == - 1 )
V_27 = 0 ;
return V_27 ;
}
int F_40 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_39 ( V_12 , V_24 , NULL , 0 ) ;
}
int F_39 ( struct V_11 * V_12 , T_2 V_24 ,
T_2 * V_56 , int V_62 )
{
unsigned int V_27 ;
int V_17 , V_67 , V_55 ;
unsigned int V_68 , V_69 , V_70 ;
T_2 V_71 ;
int V_72 = 0 ;
V_27 = F_46 ( V_12 , V_24 ) ;
if ( ! V_27 )
return 0 ;
if ( V_27 & V_73 ) {
V_68 = 16 ;
V_69 = 2 ;
} else {
V_68 = 8 ;
V_69 = 4 ;
}
V_67 = V_27 & V_74 ;
V_70 = ( 1 << ( V_68 - 1 ) ) - 1 ;
if ( ! V_67 )
return 0 ;
if ( V_67 == 1 ) {
V_27 = F_23 ( V_12 , V_24 , 0 ,
V_75 , 0 ) ;
if ( V_27 == - 1 && V_12 -> V_7 -> V_41 )
return - V_76 ;
if ( V_56 )
V_56 [ 0 ] = V_27 & V_70 ;
return 1 ;
}
V_55 = 0 ;
V_71 = 0 ;
for ( V_17 = 0 ; V_17 < V_67 ; V_17 ++ ) {
int V_77 ;
T_2 V_28 , V_78 ;
if ( V_17 % V_69 == 0 ) {
V_27 = F_23 ( V_12 , V_24 , 0 ,
V_75 , V_17 ) ;
if ( V_27 == - 1 && V_12 -> V_7 -> V_41 )
return - V_76 ;
}
V_77 = ! ! ( V_27 & ( 1 << ( V_68 - 1 ) ) ) ;
V_28 = V_27 & V_70 ;
if ( V_28 == 0 && V_72 ++ ) {
F_45 ( V_79 L_39
L_41 ,
V_24 , V_17 , V_27 ) ;
return 0 ;
}
V_27 >>= V_68 ;
if ( V_77 ) {
if ( ! V_71 || V_71 >= V_28 ) {
F_45 ( V_79 L_39
L_42 ,
V_71 , V_28 ) ;
continue;
}
for ( V_78 = V_71 + 1 ; V_78 <= V_28 ; V_78 ++ ) {
if ( V_56 ) {
if ( V_55 >= V_62 )
return - V_58 ;
V_56 [ V_55 ] = V_78 ;
}
V_55 ++ ;
}
} else {
if ( V_56 ) {
if ( V_55 >= V_62 )
return - V_58 ;
V_56 [ V_55 ] = V_28 ;
}
V_55 ++ ;
}
V_71 = V_28 ;
}
return V_55 ;
}
int F_41 ( struct V_11 * V_12 , T_2 V_24 , int V_52 ,
const T_2 * V_4 )
{
struct V_50 * V_51 ;
V_51 = F_28 ( V_12 , V_24 ) ;
if ( V_51 ) {
F_6 ( & V_51 -> V_4 ) ;
F_37 ( V_51 ) ;
}
return F_30 ( V_12 , V_24 , V_52 , V_4 ) ;
}
int F_49 ( struct V_11 * V_12 , T_2 V_80 ,
T_2 V_24 , int V_81 )
{
const T_2 * V_82 ;
int V_17 , V_83 ;
V_83 = F_42 ( V_12 , V_80 , & V_82 ) ;
for ( V_17 = 0 ; V_17 < V_83 ; V_17 ++ )
if ( V_82 [ V_17 ] == V_24 )
return V_17 ;
if ( ! V_81 )
return - 1 ;
if ( V_81 > 10 ) {
F_21 ( L_43 , V_24 ) ;
return - 1 ;
}
V_81 ++ ;
for ( V_17 = 0 ; V_17 < V_83 ; V_17 ++ ) {
unsigned int type = F_48 ( F_47 ( V_12 , V_82 [ V_17 ] ) ) ;
if ( type == V_84 || type == V_85 )
continue;
if ( F_49 ( V_12 , V_82 [ V_17 ] , V_24 , V_81 ) >= 0 )
return V_17 ;
}
return - 1 ;
}
int F_50 ( struct V_6 * V_7 , T_1 V_32 , T_1 V_86 )
{
struct V_87 * V_88 ;
unsigned int V_89 ;
if ( ! V_7 || ! V_7 -> V_90 )
return 0 ;
F_51 ( V_7 , V_32 , V_86 ) ;
V_88 = V_7 -> V_88 ;
if ( ! V_88 )
return 0 ;
V_89 = ( V_88 -> V_89 + 1 ) % V_91 ;
V_88 -> V_89 = V_89 ;
V_89 <<= 1 ;
V_88 -> V_92 [ V_89 ] = V_32 ;
V_88 -> V_92 [ V_89 + 1 ] = V_86 ;
F_52 ( V_7 -> V_90 , & V_88 -> V_93 ) ;
return 0 ;
}
static void F_53 ( struct V_94 * V_93 )
{
struct V_87 * V_88 =
F_54 ( V_93 , struct V_87 , V_93 ) ;
struct V_6 * V_7 = V_88 -> V_7 ;
struct V_11 * V_12 ;
unsigned int V_95 , V_96 , V_32 ;
while ( V_88 -> V_95 != V_88 -> V_89 ) {
V_95 = ( V_88 -> V_95 + 1 ) % V_91 ;
V_88 -> V_95 = V_95 ;
V_95 <<= 1 ;
V_32 = V_88 -> V_92 [ V_95 ] ;
V_96 = V_88 -> V_92 [ V_95 + 1 ] ;
if ( ! ( V_96 & ( 1 << 4 ) ) )
continue;
V_12 = V_7 -> V_97 [ V_96 & 0x0f ] ;
if ( V_12 && V_12 -> V_98 . V_99 )
V_12 -> V_98 . V_99 ( V_12 , V_32 ) ;
}
}
static int F_55 ( struct V_6 * V_7 )
{
struct V_87 * V_88 ;
if ( V_7 -> V_88 )
return 0 ;
V_88 = F_56 ( sizeof( * V_88 ) , V_53 ) ;
if ( ! V_88 ) {
F_45 ( V_30 L_39
L_44 ) ;
return - V_54 ;
}
F_57 ( & V_88 -> V_93 , F_53 ) ;
V_88 -> V_7 = V_7 ;
V_7 -> V_88 = V_88 ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 )
{
struct V_11 * V_12 , * V_78 ;
if ( ! V_7 )
return 0 ;
if ( V_7 -> V_90 )
F_59 ( V_7 -> V_90 ) ;
if ( V_7 -> V_88 )
F_37 ( V_7 -> V_88 ) ;
F_60 (codec, n, &bus->codec_list, list) {
F_61 ( V_12 ) ;
}
if ( V_7 -> V_9 . V_100 )
V_7 -> V_9 . V_100 ( V_7 ) ;
if ( V_7 -> V_90 )
F_62 ( V_7 -> V_90 ) ;
F_37 ( V_7 ) ;
return 0 ;
}
static int F_63 ( struct V_101 * V_102 )
{
struct V_6 * V_7 = V_102 -> V_103 ;
V_7 -> V_104 = 1 ;
return F_58 ( V_7 ) ;
}
static int F_64 ( struct V_101 * V_102 )
{
struct V_6 * V_7 = V_102 -> V_103 ;
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
F_65 ( V_12 ) ;
F_66 ( V_12 ) ;
}
return 0 ;
}
int F_67 ( struct V_105 * V_106 ,
const struct V_107 * V_108 ,
struct V_6 * * V_109 )
{
struct V_6 * V_7 ;
int V_33 ;
static struct V_110 V_111 = {
. V_112 = F_64 ,
. V_113 = F_63 ,
} ;
if ( F_43 ( ! V_108 ) )
return - V_61 ;
if ( F_43 ( ! V_108 -> V_9 . V_38 || ! V_108 -> V_9 . V_40 ) )
return - V_61 ;
if ( V_109 )
* V_109 = NULL ;
V_7 = F_56 ( sizeof( * V_7 ) , V_53 ) ;
if ( V_7 == NULL ) {
F_45 ( V_30 L_45 ) ;
return - V_54 ;
}
V_7 -> V_106 = V_106 ;
V_7 -> V_114 = V_108 -> V_114 ;
V_7 -> V_115 = V_108 -> V_115 ;
V_7 -> V_116 = V_108 -> V_116 ;
V_7 -> V_117 = V_108 -> V_117 ;
V_7 -> V_9 = V_108 -> V_9 ;
F_68 ( & V_7 -> V_35 ) ;
F_68 ( & V_7 -> V_118 ) ;
F_69 ( & V_7 -> V_119 ) ;
snprintf ( V_7 -> V_120 , sizeof( V_7 -> V_120 ) ,
L_46 , V_106 -> V_121 ) ;
V_7 -> V_90 = F_70 ( V_7 -> V_120 ) ;
if ( ! V_7 -> V_90 ) {
F_45 ( V_30 L_47 ,
V_7 -> V_120 ) ;
F_37 ( V_7 ) ;
return - V_54 ;
}
V_33 = F_71 ( V_106 , V_122 , V_7 , & V_111 ) ;
if ( V_33 < 0 ) {
F_58 ( V_7 ) ;
return V_33 ;
}
if ( V_109 )
* V_109 = V_7 ;
return 0 ;
}
static const struct V_123 *
F_72 ( struct V_11 * V_12 )
{
struct V_1 * V_124 ;
const struct V_123 * V_2 ;
unsigned int V_125 = 0 ;
if ( F_73 ( V_12 ) )
return NULL ;
V_34:
F_2 ( & V_3 ) ;
F_29 (tbl, &hda_preset_tables, list) {
if ( ! F_74 ( V_124 -> V_126 ) ) {
F_45 ( V_30 L_48 ) ;
continue;
}
for ( V_2 = V_124 -> V_2 ; V_2 -> V_127 ; V_2 ++ ) {
T_1 V_70 = V_2 -> V_70 ;
if ( V_2 -> V_128 && V_2 -> V_128 != V_12 -> V_128 )
continue;
if ( V_2 -> V_129 && V_2 -> V_129 != V_12 -> V_129 )
continue;
if ( ! V_70 )
V_70 = ~ 0 ;
if ( V_2 -> V_127 == ( V_12 -> V_130 & V_70 ) &&
( ! V_2 -> V_131 ||
V_2 -> V_131 == V_12 -> V_132 ) ) {
F_4 ( & V_3 ) ;
V_12 -> V_126 = V_124 -> V_126 ;
return V_2 ;
}
}
F_75 ( V_124 -> V_126 ) ;
}
F_4 ( & V_3 ) ;
if ( V_125 < V_133 ) {
char V_134 [ 32 ] ;
if ( ! V_125 )
snprintf ( V_134 , sizeof( V_134 ) , L_49 ,
V_12 -> V_130 ) ;
else
snprintf ( V_134 , sizeof( V_134 ) , L_50 ,
( V_12 -> V_130 >> 16 ) & 0xffff ) ;
F_76 ( V_134 ) ;
V_125 ++ ;
goto V_34;
}
return NULL ;
}
static int F_77 ( struct V_11 * V_12 )
{
const struct V_135 * V_136 ;
const char * V_137 = NULL ;
T_3 V_130 = V_12 -> V_130 >> 16 ;
char V_138 [ 16 ] ;
if ( V_12 -> V_139 )
goto V_140;
for ( V_136 = V_141 ; V_136 -> V_127 ; V_136 ++ ) {
if ( V_136 -> V_127 == V_130 ) {
V_137 = V_136 -> V_134 ;
break;
}
}
if ( ! V_137 ) {
sprintf ( V_138 , L_51 , V_130 ) ;
V_137 = V_138 ;
}
V_12 -> V_139 = F_78 ( V_137 , V_53 ) ;
if ( ! V_12 -> V_139 )
return - V_54 ;
V_140:
if ( V_12 -> V_142 )
return 0 ;
if ( V_12 -> V_2 && V_12 -> V_2 -> V_134 )
V_12 -> V_142 = F_78 ( V_12 -> V_2 -> V_134 , V_53 ) ;
else {
sprintf ( V_138 , L_52 , V_12 -> V_130 & 0xffff ) ;
V_12 -> V_142 = F_78 ( V_138 , V_53 ) ;
}
if ( ! V_12 -> V_142 )
return - V_54 ;
return 0 ;
}
static void F_79 ( struct V_11 * V_12 )
{
int V_17 , V_143 , V_144 ;
T_2 V_24 ;
V_143 = F_26 ( V_12 , V_145 , & V_24 ) ;
for ( V_17 = 0 ; V_17 < V_143 ; V_17 ++ , V_24 ++ ) {
V_144 = F_27 ( V_12 , V_24 ,
V_146 ) ;
switch ( V_144 & 0xff ) {
case V_147 :
V_12 -> V_128 = V_24 ;
V_12 -> V_148 = V_144 & 0xff ;
V_12 -> V_149 = ( V_144 >> 8 ) & 1 ;
break;
case V_150 :
V_12 -> V_129 = V_24 ;
V_12 -> V_151 = V_144 & 0xff ;
V_12 -> V_152 = ( V_144 >> 8 ) & 1 ;
break;
default:
break;
}
}
}
static int F_80 ( struct V_11 * V_12 , T_2 V_153 )
{
int V_17 ;
T_2 V_24 ;
V_12 -> V_154 = F_26 ( V_12 , V_153 ,
& V_12 -> V_155 ) ;
V_12 -> V_63 = F_31 ( V_12 -> V_154 * 4 , V_53 ) ;
if ( ! V_12 -> V_63 )
return - V_54 ;
V_24 = V_12 -> V_155 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_154 ; V_17 ++ , V_24 ++ )
V_12 -> V_63 [ V_17 ] = F_27 ( V_12 , V_24 ,
V_156 ) ;
return 0 ;
}
static int F_81 ( struct V_11 * V_12 )
{
int V_17 ;
T_2 V_24 = V_12 -> V_155 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_154 ; V_17 ++ , V_24 ++ ) {
struct V_157 * V_158 ;
unsigned int V_63 = F_47 ( V_12 , V_24 ) ;
unsigned int V_159 = F_48 ( V_63 ) ;
if ( V_159 != V_84 )
continue;
V_158 = F_82 ( & V_12 -> V_160 ) ;
if ( ! V_158 )
return - V_54 ;
V_158 -> V_24 = V_24 ;
V_158 -> V_13 = F_23 ( V_12 , V_24 , 0 ,
V_161 , 0 ) ;
V_158 -> V_162 = F_23 ( V_12 , V_24 , 0 ,
V_163 ,
0 ) ;
}
return 0 ;
}
static struct V_157 * F_83 ( struct V_11 * V_12 ,
struct V_164 * V_165 ,
T_2 V_24 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_165 -> V_166 ; V_17 ++ ) {
struct V_157 * V_158 = F_84 ( V_165 , V_17 ) ;
if ( V_158 -> V_24 == V_24 )
return V_158 ;
}
return NULL ;
}
int F_85 ( struct V_11 * V_12 , struct V_164 * V_4 ,
T_2 V_24 , unsigned int V_13 )
{
struct V_157 * V_158 ;
V_158 = F_83 ( V_12 , V_4 , V_24 ) ;
if ( ! V_158 ) {
V_158 = F_82 ( V_4 ) ;
if ( ! V_158 )
return - V_54 ;
V_158 -> V_24 = V_24 ;
}
V_158 -> V_13 = V_13 ;
return 0 ;
}
int F_86 ( struct V_11 * V_12 ,
T_2 V_24 , unsigned int V_13 )
{
return F_85 ( V_12 , & V_12 -> V_167 , V_24 , V_13 ) ;
}
unsigned int F_87 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_157 * V_158 ;
#ifdef F_88
{
unsigned int V_13 = 0 ;
F_2 ( & V_12 -> V_168 ) ;
V_158 = F_83 ( V_12 , & V_12 -> V_169 , V_24 ) ;
if ( V_158 )
V_13 = V_158 -> V_13 ;
F_4 ( & V_12 -> V_168 ) ;
if ( V_13 )
return V_13 ;
}
#endif
V_158 = F_83 ( V_12 , & V_12 -> V_167 , V_24 ) ;
if ( V_158 )
return V_158 -> V_13 ;
V_158 = F_83 ( V_12 , & V_12 -> V_160 , V_24 ) ;
if ( V_158 )
return V_158 -> V_13 ;
return 0 ;
}
int F_89 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_28 )
{
struct V_157 * V_158 ;
V_158 = F_83 ( V_12 , & V_12 -> V_160 , V_24 ) ;
if ( ! V_158 )
return - V_61 ;
V_158 -> V_170 = V_28 ;
return 0 ;
}
int F_90 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_157 * V_158 ;
V_158 = F_83 ( V_12 , & V_12 -> V_160 , V_24 ) ;
if ( ! V_158 )
return 0 ;
return V_158 -> V_170 ;
}
void F_91 ( struct V_11 * V_12 )
{
int V_17 ;
if ( V_12 -> V_7 -> V_104 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_160 . V_166 ; V_17 ++ ) {
struct V_157 * V_158 = F_84 ( & V_12 -> V_160 , V_17 ) ;
F_23 ( V_12 , V_158 -> V_24 , 0 ,
V_171 , 0 ) ;
}
V_12 -> V_172 = 1 ;
}
static void F_92 ( struct V_11 * V_12 )
{
int V_17 ;
if ( ! V_12 -> V_172 )
return;
if ( V_12 -> V_7 -> V_104 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_160 . V_166 ; V_17 ++ ) {
struct V_157 * V_158 = F_84 ( & V_12 -> V_160 , V_17 ) ;
F_24 ( V_12 , V_158 -> V_24 , 0 ,
V_171 ,
V_158 -> V_162 ) ;
}
V_12 -> V_172 = 0 ;
}
static void F_93 ( struct V_94 * V_93 )
{
struct V_11 * V_12 =
F_54 ( V_93 , struct V_11 , V_173 . V_93 ) ;
if ( ! V_12 -> V_174 )
return;
F_94 ( V_12 ) ;
F_95 ( V_12 ) ;
F_96 ( V_12 -> V_7 -> V_90 , & V_12 -> V_173 ,
V_12 -> V_174 ) ;
}
static void F_97 ( struct V_11 * V_12 )
{
F_98 ( & V_12 -> V_167 ) ;
#ifdef F_88
F_98 ( & V_12 -> V_169 ) ;
#endif
F_98 ( & V_12 -> V_160 ) ;
}
static struct V_175 *
F_99 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_175 * V_51 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_176 . V_166 ; V_17 ++ ) {
V_51 = F_84 ( & V_12 -> V_176 , V_17 ) ;
if ( V_51 -> V_24 == V_24 )
return V_51 ;
}
V_51 = F_82 ( & V_12 -> V_176 ) ;
if ( V_51 )
V_51 -> V_24 = V_24 ;
return V_51 ;
}
static void F_61 ( struct V_11 * V_12 )
{
if ( ! V_12 )
return;
F_100 ( & V_12 -> V_173 ) ;
F_101 ( V_12 ) ;
F_97 ( V_12 ) ;
#ifdef F_102
F_103 ( & V_12 -> V_177 ) ;
F_59 ( V_12 -> V_7 -> V_90 ) ;
#endif
F_6 ( & V_12 -> V_4 ) ;
F_98 ( & V_12 -> V_178 ) ;
F_98 ( & V_12 -> V_179 ) ;
F_98 ( & V_12 -> V_176 ) ;
F_98 ( & V_12 -> V_180 ) ;
F_33 ( V_12 ) ;
V_12 -> V_7 -> V_97 [ V_12 -> V_29 ] = NULL ;
if ( V_12 -> V_98 . free )
V_12 -> V_98 . free ( V_12 ) ;
#ifdef F_102
if ( ! V_12 -> V_181 )
F_7 ( V_12 -> V_7 , false ) ;
#endif
F_75 ( V_12 -> V_126 ) ;
F_104 ( & V_12 -> V_182 ) ;
F_104 ( & V_12 -> V_183 ) ;
F_37 ( V_12 -> V_139 ) ;
F_37 ( V_12 -> V_142 ) ;
F_37 ( V_12 -> V_116 ) ;
F_37 ( V_12 -> V_63 ) ;
F_37 ( V_12 ) ;
}
int F_105 ( struct V_6 * V_7 ,
unsigned int V_184 ,
struct V_11 * * V_185 )
{
struct V_11 * V_12 ;
char V_186 [ 31 ] ;
T_2 V_187 ;
int V_33 ;
if ( F_43 ( ! V_7 ) )
return - V_61 ;
if ( F_43 ( V_184 > V_188 ) )
return - V_61 ;
if ( V_7 -> V_97 [ V_184 ] ) {
F_45 ( V_30 L_39
L_53 , V_184 ) ;
return - V_189 ;
}
V_12 = F_56 ( sizeof( * V_12 ) , V_53 ) ;
if ( V_12 == NULL ) {
F_45 ( V_30 L_54 ) ;
return - V_54 ;
}
V_12 -> V_7 = V_7 ;
V_12 -> V_29 = V_184 ;
F_68 ( & V_12 -> V_190 ) ;
F_68 ( & V_12 -> V_191 ) ;
F_68 ( & V_12 -> V_192 ) ;
F_106 ( & V_12 -> V_182 , sizeof( struct V_193 ) ) ;
F_106 ( & V_12 -> V_183 , sizeof( struct V_194 ) ) ;
F_107 ( & V_12 -> V_178 , sizeof( struct V_195 ) , 32 ) ;
F_107 ( & V_12 -> V_179 , sizeof( struct V_195 ) , 32 ) ;
F_107 ( & V_12 -> V_160 , sizeof( struct V_157 ) , 16 ) ;
F_107 ( & V_12 -> V_167 , sizeof( struct V_157 ) , 16 ) ;
F_107 ( & V_12 -> V_176 , sizeof( struct V_175 ) , 8 ) ;
F_107 ( & V_12 -> V_180 , sizeof( struct V_196 ) , 16 ) ;
F_107 ( & V_12 -> V_197 , sizeof( struct V_198 ) , 16 ) ;
F_107 ( & V_12 -> V_199 , sizeof( struct V_45 * ) , 8 ) ;
F_69 ( & V_12 -> V_56 ) ;
F_108 ( & V_12 -> V_173 , F_93 ) ;
#ifdef F_102
F_109 ( & V_12 -> V_200 ) ;
F_108 ( & V_12 -> V_177 , V_201 ) ;
F_8 ( V_12 ) ;
F_7 ( V_7 , true ) ;
#endif
if ( V_12 -> V_7 -> V_116 ) {
V_12 -> V_116 = F_78 ( V_12 -> V_7 -> V_116 , V_53 ) ;
if ( ! V_12 -> V_116 ) {
F_61 ( V_12 ) ;
return - V_202 ;
}
}
F_3 ( & V_12 -> V_4 , & V_7 -> V_119 ) ;
V_7 -> V_97 [ V_184 ] = V_12 ;
V_12 -> V_130 = F_27 ( V_12 , V_145 ,
V_203 ) ;
if ( V_12 -> V_130 == - 1 )
V_12 -> V_130 = F_27 ( V_12 , V_145 ,
V_203 ) ;
V_12 -> V_204 = F_27 ( V_12 , V_145 ,
V_205 ) ;
V_12 -> V_132 = F_27 ( V_12 , V_145 ,
V_206 ) ;
F_79 ( V_12 ) ;
if ( ! V_12 -> V_128 && ! V_12 -> V_129 ) {
F_110 ( L_55 ) ;
V_33 = - V_202 ;
goto error;
}
V_187 = V_12 -> V_128 ? V_12 -> V_128 : V_12 -> V_129 ;
V_33 = F_80 ( V_12 , V_187 ) ;
if ( V_33 < 0 ) {
F_45 ( V_30 L_56 ) ;
goto error;
}
V_33 = F_81 ( V_12 ) ;
if ( V_33 < 0 )
goto error;
if ( ! V_12 -> V_204 ) {
V_12 -> V_204 =
F_23 ( V_12 , V_187 , 0 ,
V_207 , 0 ) ;
}
#ifdef F_102
V_12 -> V_208 = F_111 ( V_12 , V_187 ,
V_209 ) ;
if ( ! V_12 -> V_208 )
V_7 -> V_210 = 1 ;
#endif
V_12 -> V_211 = F_111 ( V_12 , V_187 ,
V_212 ) ;
F_112 ( V_12 , V_213 ) ;
F_113 ( V_12 ) ;
F_114 ( V_12 ) ;
sprintf ( V_186 , L_57 , V_12 -> V_130 ,
V_12 -> V_204 , V_12 -> V_132 ) ;
F_115 ( V_12 -> V_7 -> V_106 , V_186 ) ;
if ( V_185 )
* V_185 = V_12 ;
return 0 ;
error:
F_61 ( V_12 ) ;
return V_33 ;
}
int F_116 ( struct V_11 * V_12 )
{
T_2 V_187 ;
int V_33 ;
F_37 ( V_12 -> V_63 ) ;
V_187 = V_12 -> V_128 ? V_12 -> V_128 : V_12 -> V_129 ;
V_33 = F_80 ( V_12 , V_187 ) ;
if ( V_33 < 0 ) {
F_45 ( V_30 L_56 ) ;
return V_33 ;
}
F_98 ( & V_12 -> V_160 ) ;
V_33 = F_81 ( V_12 ) ;
return V_33 ;
}
int F_117 ( struct V_11 * V_12 )
{
int V_33 ;
V_12 -> V_2 = F_72 ( V_12 ) ;
if ( ! V_12 -> V_139 || ! V_12 -> V_142 ) {
V_33 = F_77 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( F_73 ( V_12 ) ) {
V_33 = F_118 ( V_12 ) ;
goto V_214;
}
if ( V_12 -> V_2 && V_12 -> V_2 -> V_215 ) {
V_33 = V_12 -> V_2 -> V_215 ( V_12 ) ;
goto V_214;
}
V_33 = F_118 ( V_12 ) ;
if ( V_33 < 0 )
F_14 ( V_30 L_58 ) ;
V_214:
if ( ! V_33 && V_12 -> V_98 . V_99 )
V_33 = F_55 ( V_12 -> V_7 ) ;
if ( ! V_33 && ( V_12 -> V_128 || ! * V_12 -> V_7 -> V_106 -> V_216 ) )
snprintf ( V_12 -> V_7 -> V_106 -> V_216 ,
sizeof( V_12 -> V_7 -> V_106 -> V_216 ) ,
L_59 , V_12 -> V_139 , V_12 -> V_142 ) ;
return V_33 ;
}
static void F_119 ( struct V_11 * V_12 ,
struct V_175 * V_51 , T_2 V_24 ,
T_1 V_217 , int V_218 )
{
unsigned int V_219 , V_220 ;
if ( V_51 -> V_217 != V_217 || V_51 -> V_218 != V_218 ) {
V_219 = F_23 ( V_12 , V_24 , 0 , V_221 , 0 ) ;
V_220 = ( V_217 << 4 ) | V_218 ;
if ( V_219 != V_220 )
F_24 ( V_12 , V_24 , 0 ,
V_222 ,
V_220 ) ;
V_51 -> V_217 = V_217 ;
V_51 -> V_218 = V_218 ;
}
}
static void F_120 ( struct V_11 * V_12 , struct V_175 * V_51 ,
T_2 V_24 , int V_223 )
{
unsigned int V_219 ;
if ( V_51 -> V_224 != V_223 ) {
V_219 = F_23 ( V_12 , V_24 , 0 ,
V_225 , 0 ) ;
if ( V_219 != V_223 ) {
F_121 ( 1 ) ;
F_24 ( V_12 , V_24 , 0 ,
V_226 ,
V_223 ) ;
}
V_51 -> V_224 = V_223 ;
}
}
void F_122 ( struct V_11 * V_12 , T_2 V_24 ,
T_1 V_217 ,
int V_218 , int V_223 )
{
struct V_11 * V_136 ;
struct V_175 * V_51 ;
int type ;
int V_17 ;
if ( ! V_24 )
return;
F_110 ( L_60
L_61 ,
V_24 , V_217 , V_218 , V_223 ) ;
V_51 = F_99 ( V_12 , V_24 ) ;
if ( ! V_51 )
return;
if ( V_12 -> V_227 )
F_120 ( V_12 , V_51 , V_24 , V_223 ) ;
F_119 ( V_12 , V_51 , V_24 , V_217 , V_218 ) ;
if ( ! V_12 -> V_227 )
F_120 ( V_12 , V_51 , V_24 , V_223 ) ;
V_51 -> V_228 = 1 ;
V_51 -> V_229 = 0 ;
type = F_48 ( F_47 ( V_12 , V_24 ) ) ;
F_29 (c, &codec->bus->codec_list, list) {
for ( V_17 = 0 ; V_17 < V_136 -> V_176 . V_166 ; V_17 ++ ) {
V_51 = F_84 ( & V_136 -> V_176 , V_17 ) ;
if ( ! V_51 -> V_228 && V_51 -> V_217 == V_217 &&
F_48 ( F_47 ( V_136 , V_51 -> V_24 ) ) == type )
V_51 -> V_229 = 1 ;
}
}
}
void F_123 ( struct V_11 * V_12 , T_2 V_24 ,
int V_230 )
{
struct V_175 * V_51 ;
if ( ! V_24 )
return;
if ( V_12 -> V_231 )
V_230 = 1 ;
F_110 ( L_62 , V_24 ) ;
V_51 = F_99 ( V_12 , V_24 ) ;
if ( V_51 ) {
if ( V_230 )
F_124 ( V_12 , V_51 ) ;
else
V_51 -> V_228 = 0 ;
}
}
static void F_124 ( struct V_11 * V_12 ,
struct V_175 * V_232 )
{
T_2 V_24 = V_232 -> V_24 ;
if ( V_232 -> V_217 || V_232 -> V_218 )
F_24 ( V_12 , V_24 , 0 , V_222 , 0 ) ;
if ( V_232 -> V_224 )
F_24 ( V_12 , V_24 , 0 , V_226 , 0
) ;
memset ( V_232 , 0 , sizeof( * V_232 ) ) ;
V_232 -> V_24 = V_24 ;
}
static void F_125 ( struct V_11 * V_12 )
{
struct V_11 * V_136 ;
int V_17 ;
F_29 (c, &codec->bus->codec_list, list) {
for ( V_17 = 0 ; V_17 < V_136 -> V_176 . V_166 ; V_17 ++ ) {
struct V_175 * V_51 ;
V_51 = F_84 ( & V_136 -> V_176 , V_17 ) ;
if ( V_51 -> V_229 )
F_124 ( V_136 , V_51 ) ;
}
}
}
static void F_126 ( struct V_11 * V_12 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_176 . V_166 ; V_17 ++ ) {
struct V_175 * V_51 = F_84 ( & V_12 -> V_176 , V_17 ) ;
if ( V_51 -> V_217 )
F_124 ( V_12 , V_51 ) ;
}
}
static void F_106 ( struct V_233 * V_234 ,
unsigned int V_235 )
{
memset ( V_234 , 0 , sizeof( * V_234 ) ) ;
memset ( V_234 -> V_236 , 0xff , sizeof( V_234 -> V_236 ) ) ;
F_107 ( & V_234 -> V_237 , V_235 , 64 ) ;
}
static void F_104 ( struct V_233 * V_234 )
{
F_98 ( & V_234 -> V_237 ) ;
}
static struct V_194 * F_127 ( struct V_233 * V_234 , T_1 V_238 )
{
T_3 V_239 = V_238 % ( T_3 ) F_10 ( V_234 -> V_236 ) ;
T_3 V_240 = V_234 -> V_236 [ V_239 ] ;
struct V_194 * V_241 ;
while ( V_240 != 0xffff ) {
V_241 = F_84 ( & V_234 -> V_237 , V_240 ) ;
if ( V_241 -> V_238 == V_238 )
return V_241 ;
V_240 = V_241 -> V_242 ;
}
return NULL ;
}
static struct V_194 * F_128 ( struct V_233 * V_234 ,
T_1 V_238 )
{
struct V_194 * V_241 = F_127 ( V_234 , V_238 ) ;
if ( ! V_241 ) {
T_3 V_239 , V_240 ;
V_241 = F_82 ( & V_234 -> V_237 ) ;
if ( ! V_241 )
return NULL ;
V_240 = F_129 ( & V_234 -> V_237 , V_241 ) ;
V_241 -> V_238 = V_238 ;
V_241 -> V_28 = 0 ;
V_241 -> V_229 = 0 ;
V_239 = V_238 % ( T_3 ) F_10 ( V_234 -> V_236 ) ;
V_241 -> V_242 = V_234 -> V_236 [ V_239 ] ;
V_234 -> V_236 [ V_239 ] = V_240 ;
}
return V_241 ;
}
static inline struct V_193 *
F_130 ( struct V_11 * V_12 , T_1 V_238 )
{
return (struct V_193 * ) F_128 ( & V_12 -> V_182 , V_238 ) ;
}
static int F_131 ( struct V_11 * V_12 , T_1 V_238 , unsigned int V_28 )
{
struct V_193 * V_241 ;
F_2 ( & V_12 -> V_192 ) ;
V_241 = F_130 ( V_12 , V_238 ) ;
if ( ! V_241 ) {
F_4 ( & V_12 -> V_192 ) ;
return - V_61 ;
}
V_241 -> V_243 = V_28 ;
V_241 -> V_244 . V_28 |= V_245 ;
F_4 ( & V_12 -> V_192 ) ;
return 0 ;
}
static unsigned int F_132 ( struct V_11 * V_12 , T_2 V_24 ,
int V_246 )
{
if ( ! ( F_47 ( V_12 , V_24 ) & V_247 ) )
V_24 = V_12 -> V_128 ;
return F_27 ( V_12 , V_24 ,
V_246 == V_248 ?
V_249 : V_250 ) ;
}
T_1 F_133 ( struct V_11 * V_12 , T_2 V_24 , int V_246 )
{
return F_134 ( V_12 , V_24 , V_246 ,
F_135 ( V_24 , V_246 , 0 ) ,
F_132 ) ;
}
int F_136 ( struct V_11 * V_12 , T_2 V_24 , int V_251 ,
unsigned int V_252 )
{
return F_131 ( V_12 , F_135 ( V_24 , V_251 , 0 ) , V_252 ) ;
}
static unsigned int F_137 ( struct V_11 * V_12 , T_2 V_24 ,
int V_251 )
{
return F_27 ( V_12 , V_24 , V_253 ) ;
}
T_1 F_138 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_134 ( V_12 , V_24 , 0 , F_139 ( V_24 ) ,
F_137 ) ;
}
int F_140 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_252 )
{
return F_131 ( V_12 , F_139 ( V_24 ) , V_252 ) ;
}
static struct V_193 *
F_141 ( struct V_11 * V_12 , T_2 V_24 , int V_254 ,
int V_246 , int V_255 , bool V_256 )
{
struct V_193 * V_241 ;
unsigned int V_27 , V_28 = 0 ;
bool V_257 = false ;
V_258:
V_241 = F_130 ( V_12 , F_135 ( V_24 , V_246 , V_255 ) ) ;
if ( ! V_241 )
return NULL ;
if ( ! ( V_241 -> V_244 . V_28 & F_142 ( V_254 ) ) ) {
if ( ! V_257 ) {
F_4 ( & V_12 -> V_192 ) ;
V_27 = V_254 ? V_259 : V_260 ;
V_27 |= V_246 == V_248 ?
V_261 : V_262 ;
V_27 |= V_255 ;
V_28 = F_23 ( V_12 , V_24 , 0 ,
V_263 , V_27 ) ;
V_28 &= 0xff ;
V_257 = true ;
F_2 ( & V_12 -> V_192 ) ;
goto V_258;
}
V_241 -> V_264 [ V_254 ] = V_28 ;
V_241 -> V_244 . V_28 |= F_142 ( V_254 ) ;
} else if ( V_256 )
return NULL ;
return V_241 ;
}
static void F_143 ( struct V_11 * V_12 , unsigned int V_243 ,
T_2 V_24 , int V_254 , int V_246 , int V_255 ,
int V_28 )
{
T_1 V_27 ;
V_27 = V_254 ? V_265 : V_266 ;
V_27 |= V_246 == V_248 ? V_267 : V_268 ;
V_27 |= V_255 << V_269 ;
if ( ( V_28 & V_270 ) && ! ( V_243 & V_271 ) &&
( V_243 & V_272 ) )
;
else
V_27 |= V_28 ;
F_24 ( V_12 , V_24 , 0 , V_273 , V_27 ) ;
}
int F_144 ( struct V_11 * V_12 , T_2 V_24 , int V_254 ,
int V_246 , int V_255 )
{
struct V_193 * V_241 ;
unsigned int V_28 = 0 ;
F_2 ( & V_12 -> V_192 ) ;
V_241 = F_141 ( V_12 , V_24 , V_254 , V_246 , V_255 , false ) ;
if ( V_241 )
V_28 = V_241 -> V_264 [ V_254 ] ;
F_4 ( & V_12 -> V_192 ) ;
return V_28 ;
}
static int F_145 ( struct V_11 * V_12 , T_2 V_24 , int V_254 ,
int V_246 , int V_239 , int V_70 , int V_28 ,
bool V_256 )
{
struct V_193 * V_241 ;
unsigned int V_252 ;
unsigned int V_274 ;
if ( F_43 ( V_70 & ~ 0xff ) )
V_70 &= 0xff ;
V_28 &= V_70 ;
F_2 ( & V_12 -> V_192 ) ;
V_241 = F_141 ( V_12 , V_24 , V_254 , V_246 , V_239 , V_256 ) ;
if ( ! V_241 ) {
F_4 ( & V_12 -> V_192 ) ;
return 0 ;
}
V_28 |= V_241 -> V_264 [ V_254 ] & ~ V_70 ;
if ( V_241 -> V_264 [ V_254 ] == V_28 ) {
F_4 ( & V_12 -> V_192 ) ;
return 0 ;
}
V_241 -> V_264 [ V_254 ] = V_28 ;
V_274 = V_241 -> V_244 . V_229 = V_12 -> V_275 ;
V_252 = V_241 -> V_243 ;
F_4 ( & V_12 -> V_192 ) ;
if ( ! V_274 )
F_143 ( V_12 , V_252 , V_24 , V_254 , V_246 , V_239 , V_28 ) ;
return 1 ;
}
int F_146 ( struct V_11 * V_12 , T_2 V_24 , int V_254 ,
int V_246 , int V_239 , int V_70 , int V_28 )
{
return F_145 ( V_12 , V_24 , V_254 , V_246 , V_239 , V_70 , V_28 , false ) ;
}
int F_147 ( struct V_11 * V_12 , T_2 V_24 ,
int V_246 , int V_239 , int V_70 , int V_28 )
{
int V_254 , V_276 = 0 ;
if ( F_43 ( V_70 & ~ 0xff ) )
V_70 &= 0xff ;
for ( V_254 = 0 ; V_254 < 2 ; V_254 ++ )
V_276 |= F_146 ( V_12 , V_24 , V_254 , V_246 ,
V_239 , V_70 , V_28 ) ;
return V_276 ;
}
int F_148 ( struct V_11 * V_12 , T_2 V_24 , int V_254 ,
int V_251 , int V_239 , int V_70 , int V_28 )
{
return F_145 ( V_12 , V_24 , V_254 , V_251 , V_239 , V_70 , V_28 , true ) ;
}
int F_149 ( struct V_11 * V_12 , T_2 V_24 ,
int V_251 , int V_239 , int V_70 , int V_28 )
{
int V_254 , V_276 = 0 ;
if ( F_43 ( V_70 & ~ 0xff ) )
V_70 &= 0xff ;
for ( V_254 = 0 ; V_254 < 2 ; V_254 ++ )
V_276 |= F_148 ( V_12 , V_24 , V_254 , V_251 ,
V_239 , V_70 , V_28 ) ;
return V_276 ;
}
void F_150 ( struct V_11 * V_12 )
{
int V_17 ;
F_2 ( & V_12 -> V_192 ) ;
V_12 -> V_275 = 0 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_182 . V_237 . V_166 ; V_17 ++ ) {
struct V_193 * V_277 ;
T_1 V_238 ;
T_2 V_24 ;
unsigned int V_239 , V_251 , V_254 ;
struct V_193 V_241 ;
V_277 = F_84 ( & V_12 -> V_182 . V_237 , V_17 ) ;
if ( ! V_277 -> V_244 . V_229 )
continue;
V_277 -> V_244 . V_229 = 0 ;
V_241 = * V_277 ;
V_238 = V_241 . V_244 . V_238 ;
if ( ! V_238 )
continue;
V_24 = V_238 & 0xff ;
V_239 = ( V_238 >> 16 ) & 0xff ;
V_251 = ( V_238 >> 24 ) & 0xff ;
for ( V_254 = 0 ; V_254 < 2 ; V_254 ++ ) {
if ( ! ( V_241 . V_244 . V_28 & F_142 ( V_254 ) ) )
continue;
F_4 ( & V_12 -> V_192 ) ;
F_143 ( V_12 , V_241 . V_243 , V_24 , V_254 , V_251 , V_239 ,
V_241 . V_264 [ V_254 ] ) ;
F_2 ( & V_12 -> V_192 ) ;
}
}
F_4 ( & V_12 -> V_192 ) ;
}
static T_1 F_151 ( struct V_11 * V_12 , T_2 V_24 , int V_251 ,
unsigned int V_278 )
{
T_1 V_252 = F_133 ( V_12 , V_24 , V_251 ) ;
V_252 = ( V_252 & V_279 ) >> V_280 ;
if ( V_278 < V_252 )
V_252 -= V_278 ;
return V_252 ;
}
int F_152 ( struct V_281 * V_282 ,
struct V_283 * V_284 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
T_3 V_24 = F_154 ( V_282 ) ;
T_4 V_285 = F_155 ( V_282 ) ;
int V_251 = F_156 ( V_282 ) ;
unsigned int V_278 = F_157 ( V_282 ) ;
V_284 -> type = V_286 ;
V_284 -> V_287 = V_285 == 3 ? 2 : 1 ;
V_284 -> V_288 . integer . V_289 = 0 ;
V_284 -> V_288 . integer . V_290 = F_151 ( V_12 , V_24 , V_251 , V_278 ) ;
if ( ! V_284 -> V_288 . integer . V_290 ) {
F_14 ( V_79 L_39
L_63 , V_24 ,
V_282 -> V_127 . V_134 ) ;
return - V_61 ;
}
return 0 ;
}
static inline unsigned int
F_158 ( struct V_11 * V_12 , T_2 V_24 ,
int V_254 , int V_251 , int V_239 , unsigned int V_278 )
{
unsigned int V_28 ;
V_28 = F_144 ( V_12 , V_24 , V_254 , V_251 , V_239 ) ;
V_28 &= V_291 ;
if ( V_28 >= V_278 )
V_28 -= V_278 ;
else
V_28 = 0 ;
return V_28 ;
}
static inline int
F_159 ( struct V_11 * V_12 , T_2 V_24 ,
int V_254 , int V_251 , int V_239 , unsigned int V_278 ,
unsigned int V_28 )
{
unsigned int V_292 ;
if ( V_28 > 0 )
V_28 += V_278 ;
V_292 = F_151 ( V_12 , V_24 , V_251 , 0 ) ;
if ( V_28 > V_292 )
V_28 = V_292 ;
return F_146 ( V_12 , V_24 , V_254 , V_251 , V_239 ,
V_291 , V_28 ) ;
}
int F_160 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
T_2 V_24 = F_154 ( V_282 ) ;
int V_285 = F_155 ( V_282 ) ;
int V_251 = F_156 ( V_282 ) ;
int V_239 = F_161 ( V_282 ) ;
unsigned int V_278 = F_157 ( V_282 ) ;
long * V_295 = V_294 -> V_288 . integer . V_288 ;
if ( V_285 & 1 )
* V_295 ++ = F_158 ( V_12 , V_24 , 0 , V_251 , V_239 , V_278 ) ;
if ( V_285 & 2 )
* V_295 = F_158 ( V_12 , V_24 , 1 , V_251 , V_239 , V_278 ) ;
return 0 ;
}
int F_162 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
T_2 V_24 = F_154 ( V_282 ) ;
int V_285 = F_155 ( V_282 ) ;
int V_251 = F_156 ( V_282 ) ;
int V_239 = F_161 ( V_282 ) ;
unsigned int V_278 = F_157 ( V_282 ) ;
long * V_295 = V_294 -> V_288 . integer . V_288 ;
int V_296 = 0 ;
F_16 ( V_12 ) ;
if ( V_285 & 1 ) {
V_296 = F_159 ( V_12 , V_24 , 0 , V_251 , V_239 , V_278 , * V_295 ) ;
V_295 ++ ;
}
if ( V_285 & 2 )
V_296 |= F_159 ( V_12 , V_24 , 1 , V_251 , V_239 , V_278 , * V_295 ) ;
F_19 ( V_12 ) ;
return V_296 ;
}
int F_163 ( struct V_281 * V_282 , int V_297 ,
unsigned int V_298 , unsigned int T_5 * V_299 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
T_2 V_24 = F_154 ( V_282 ) ;
int V_251 = F_156 ( V_282 ) ;
unsigned int V_278 = F_157 ( V_282 ) ;
bool V_300 = F_164 ( V_282 ) ;
T_1 V_252 , V_301 , V_302 ;
if ( V_298 < 4 * sizeof( unsigned int ) )
return - V_54 ;
V_252 = F_133 ( V_12 , V_24 , V_251 ) ;
V_302 = ( V_252 & V_303 ) >> V_304 ;
V_302 = ( V_302 + 1 ) * 25 ;
V_301 = - ( ( V_252 & V_305 ) >> V_306 ) ;
V_301 += V_278 ;
V_301 = ( ( int ) V_301 ) * ( ( int ) V_302 ) ;
if ( V_300 || ( V_252 & V_272 ) )
V_302 |= V_307 ;
if ( F_165 ( V_308 , V_299 ) )
return - V_309 ;
if ( F_165 ( 2 * sizeof( unsigned int ) , V_299 + 1 ) )
return - V_309 ;
if ( F_165 ( V_301 , V_299 + 2 ) )
return - V_309 ;
if ( F_165 ( V_302 , V_299 + 3 ) )
return - V_309 ;
return 0 ;
}
void F_166 ( struct V_11 * V_12 , T_2 V_24 , int V_251 ,
unsigned int * V_310 )
{
T_1 V_252 ;
int V_83 , V_311 ;
V_252 = F_133 ( V_12 , V_24 , V_251 ) ;
V_83 = ( V_252 & V_279 ) >> V_280 ;
V_311 = ( V_252 & V_303 ) >> V_304 ;
V_311 = ( V_311 + 1 ) * 25 ;
V_310 [ 0 ] = V_308 ;
V_310 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_310 [ 2 ] = - V_83 * V_311 ;
V_310 [ 3 ] = V_311 ;
}
static struct V_281 *
F_167 ( struct V_11 * V_12 , const char * V_134 , int V_312 , int V_239 )
{
struct V_313 V_127 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_314 = V_315 ;
V_127 . V_102 = V_312 ;
V_127 . V_255 = V_239 ;
if ( F_43 ( strlen ( V_134 ) >= sizeof( V_127 . V_134 ) ) )
return NULL ;
strcpy ( V_127 . V_134 , V_134 ) ;
return F_168 ( V_12 -> V_7 -> V_106 , & V_127 ) ;
}
struct V_281 * F_169 ( struct V_11 * V_12 ,
const char * V_134 )
{
return F_167 ( V_12 , V_134 , 0 , 0 ) ;
}
static int F_170 ( struct V_11 * V_12 , const char * V_134 ,
int V_316 )
{
int V_17 , V_239 ;
for ( V_17 = 0 , V_239 = V_316 ; V_17 < 16 ; V_17 ++ , V_239 ++ ) {
if ( ! F_167 ( V_12 , V_134 , 0 , V_239 ) )
return V_239 ;
}
return - V_189 ;
}
int F_171 ( struct V_11 * V_12 , T_2 V_24 ,
struct V_281 * V_317 )
{
int V_33 ;
unsigned short V_25 = 0 ;
struct V_195 * V_318 ;
if ( V_317 -> V_127 . V_319 & V_320 ) {
V_25 |= V_321 ;
if ( V_24 == 0 )
V_24 = F_172 ( V_317 -> V_322 ) ;
}
if ( ( V_317 -> V_127 . V_319 & V_323 ) != 0 && V_24 == 0 )
V_24 = V_317 -> V_127 . V_319 & 0xffff ;
if ( V_317 -> V_127 . V_319 & ( V_323 | V_320 ) )
V_317 -> V_127 . V_319 = 0 ;
V_33 = F_173 ( V_12 -> V_7 -> V_106 , V_317 ) ;
if ( V_33 < 0 )
return V_33 ;
V_318 = F_82 ( & V_12 -> V_178 ) ;
if ( ! V_318 )
return - V_54 ;
V_318 -> V_317 = V_317 ;
V_318 -> V_24 = V_24 ;
V_318 -> V_25 = V_25 ;
return 0 ;
}
int F_174 ( struct V_11 * V_12 , struct V_281 * V_317 ,
unsigned int V_255 , T_2 V_24 )
{
struct V_195 * V_318 ;
if ( V_24 > 0 ) {
V_318 = F_82 ( & V_12 -> V_179 ) ;
if ( ! V_318 )
return - V_54 ;
V_318 -> V_317 = V_317 ;
V_318 -> V_255 = V_255 ;
V_318 -> V_24 = V_24 ;
return 0 ;
}
F_14 ( V_30 L_64 ,
V_317 -> V_127 . V_134 , V_317 -> V_127 . V_255 , V_255 ) ;
return - V_61 ;
}
void F_175 ( struct V_11 * V_12 )
{
int V_17 ;
struct V_195 * V_324 = V_12 -> V_178 . V_4 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_178 . V_166 ; V_17 ++ )
F_176 ( V_12 -> V_7 -> V_106 , V_324 [ V_17 ] . V_317 ) ;
F_98 ( & V_12 -> V_178 ) ;
F_98 ( & V_12 -> V_179 ) ;
}
int F_177 ( struct V_6 * V_7 )
{
struct V_105 * V_106 = V_7 -> V_106 ;
struct V_11 * V_12 ;
F_178 ( & V_106 -> V_325 ) ;
if ( V_106 -> V_104 )
goto V_326;
V_106 -> V_104 = 1 ;
if ( ! F_34 ( & V_106 -> V_327 ) )
goto V_328;
F_29 (codec, &bus->codec_list, list) {
int V_329 ;
for ( V_329 = 0 ; V_329 < V_12 -> V_330 ; V_329 ++ ) {
struct V_331 * V_332 = & V_12 -> V_333 [ V_329 ] ;
if ( ! V_332 -> V_329 )
continue;
if ( V_332 -> V_329 -> V_334 [ 0 ] . V_335 ||
V_332 -> V_329 -> V_334 [ 1 ] . V_335 )
goto V_328;
}
}
F_179 ( & V_106 -> V_325 ) ;
return 0 ;
V_328:
V_106 -> V_104 = 0 ;
V_326:
F_179 ( & V_106 -> V_325 ) ;
return - V_61 ;
}
void F_180 ( struct V_6 * V_7 )
{
struct V_105 * V_106 = V_7 -> V_106 ;
V_106 = V_7 -> V_106 ;
F_178 ( & V_106 -> V_325 ) ;
V_106 -> V_104 = 0 ;
F_179 ( & V_106 -> V_325 ) ;
}
int F_181 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_105 * V_106 = V_7 -> V_106 ;
int V_17 ;
if ( F_177 ( V_7 ) < 0 )
return - V_189 ;
F_100 ( & V_12 -> V_173 ) ;
#ifdef F_102
F_100 ( & V_12 -> V_177 ) ;
V_12 -> V_336 = 0 ;
V_12 -> V_337 = 0 ;
V_12 -> V_338 = V_339 ;
F_59 ( V_7 -> V_90 ) ;
#endif
F_175 ( V_12 ) ;
for ( V_17 = 0 ; V_17 < V_12 -> V_330 ; V_17 ++ ) {
if ( V_12 -> V_333 [ V_17 ] . V_329 ) {
F_182 ( V_106 , V_12 -> V_333 [ V_17 ] . V_329 ) ;
F_183 ( V_12 -> V_333 [ V_17 ] . V_102 ,
V_7 -> V_340 ) ;
}
}
if ( V_12 -> V_98 . free )
V_12 -> V_98 . free ( V_12 ) ;
memset ( & V_12 -> V_98 , 0 , sizeof( V_12 -> V_98 ) ) ;
F_101 ( V_12 ) ;
V_12 -> V_341 = NULL ;
V_12 -> V_342 = NULL ;
F_104 ( & V_12 -> V_182 ) ;
F_104 ( & V_12 -> V_183 ) ;
F_106 ( & V_12 -> V_182 , sizeof( struct V_193 ) ) ;
F_106 ( & V_12 -> V_183 , sizeof( struct V_194 ) ) ;
F_98 ( & V_12 -> V_167 ) ;
F_98 ( & V_12 -> V_176 ) ;
F_98 ( & V_12 -> V_180 ) ;
F_98 ( & V_12 -> V_199 ) ;
V_12 -> V_330 = 0 ;
V_12 -> V_333 = NULL ;
V_12 -> V_2 = NULL ;
V_12 -> V_343 = NULL ;
V_12 -> V_344 = 0 ;
F_75 ( V_12 -> V_126 ) ;
V_12 -> V_126 = NULL ;
F_180 ( V_7 ) ;
return 0 ;
}
static int F_184 ( struct V_11 * V_12 , const char * const * V_345 ,
const char * V_346 , T_6 V_347 , void * V_348 )
{
struct V_195 * V_324 ;
const char * const * V_349 ;
int V_17 , V_33 ;
V_324 = V_12 -> V_178 . V_4 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_178 . V_166 ; V_17 ++ ) {
struct V_281 * V_350 = V_324 [ V_17 ] . V_317 ;
if ( ! V_350 || ! V_350 -> V_127 . V_134 ||
V_350 -> V_127 . V_314 != V_315 )
continue;
for ( V_349 = V_345 ; * V_349 ; V_349 ++ ) {
char V_351 [ sizeof( V_350 -> V_127 . V_134 ) ] ;
const char * V_134 = * V_349 ;
if ( V_346 ) {
snprintf ( V_351 , sizeof( V_351 ) , L_59 ,
V_134 , V_346 ) ;
V_134 = V_351 ;
}
if ( ! strcmp ( V_350 -> V_127 . V_134 , V_134 ) ) {
V_33 = V_347 ( V_348 , V_350 ) ;
if ( V_33 )
return V_33 ;
break;
}
}
}
return 0 ;
}
static int F_185 ( void * V_348 , struct V_281 * V_350 )
{
return 1 ;
}
static int F_186 ( struct V_281 * V_317 )
{
int V_299 [ 4 ] ;
const int * V_310 = NULL ;
int V_28 = - 1 ;
if ( V_317 -> V_352 [ 0 ] . V_353 & V_354 ) {
T_7 V_355 = F_187 () ;
F_188 ( F_189 () ) ;
if ( ! V_317 -> V_310 . V_136 ( V_317 , 0 , sizeof( V_299 ) , V_299 ) )
V_310 = V_299 ;
F_188 ( V_355 ) ;
} else if ( V_317 -> V_352 [ 0 ] . V_353 & V_356 )
V_310 = V_317 -> V_310 . V_51 ;
if ( V_310 && V_310 [ 0 ] == V_308 )
V_28 = - V_310 [ 2 ] / V_310 [ 3 ] ;
return V_28 ;
}
static int F_190 ( struct V_281 * V_317 , int V_28 )
{
struct V_293 * V_294 ;
V_294 = F_56 ( sizeof( * V_294 ) , V_53 ) ;
if ( ! V_294 )
return - V_54 ;
V_294 -> V_288 . integer . V_288 [ 0 ] = V_28 ;
V_294 -> V_288 . integer . V_288 [ 1 ] = V_28 ;
V_317 -> V_357 ( V_317 , V_294 ) ;
F_37 ( V_294 ) ;
return 0 ;
}
static int F_191 ( void * V_348 , struct V_281 * V_358 )
{
int V_359 = F_186 ( V_358 ) ;
if ( V_359 > 0 )
F_190 ( V_358 , V_359 ) ;
return 0 ;
}
static int F_192 ( void * V_348 , struct V_281 * V_358 )
{
return F_190 ( V_358 , 1 ) ;
}
int F_193 ( struct V_11 * V_12 , char * V_134 ,
unsigned int * V_310 , const char * const * V_345 ,
const char * V_346 , bool V_360 ,
struct V_281 * * V_361 )
{
struct V_281 * V_317 ;
int V_33 ;
if ( V_361 )
* V_361 = NULL ;
V_33 = F_184 ( V_12 , V_345 , V_346 , F_185 , NULL ) ;
if ( V_33 != 1 ) {
F_110 ( L_65 , V_134 ) ;
return 0 ;
}
V_317 = F_194 ( V_134 , V_310 ) ;
if ( ! V_317 )
return - V_54 ;
V_33 = F_171 ( V_12 , 0 , V_317 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_184 ( V_12 , V_345 , V_346 ,
( T_6 ) V_362 , V_317 ) ;
if ( V_33 < 0 )
return V_33 ;
F_190 ( V_317 , 0 ) ;
if ( V_360 )
F_184 ( V_12 , V_345 , V_346 ,
V_310 ? F_191 : F_192 , V_317 ) ;
if ( V_361 )
* V_361 = V_317 ;
return 0 ;
}
static int F_195 ( struct V_281 * V_282 ,
struct V_283 * V_284 )
{
static const char * const V_363 [] = {
L_66 , L_67 , L_68
} ;
unsigned int V_255 ;
V_284 -> type = V_364 ;
V_284 -> V_287 = 1 ;
V_284 -> V_288 . V_365 . V_324 = 3 ;
V_255 = V_284 -> V_288 . V_365 . V_318 ;
if ( V_255 >= 3 )
V_255 = 2 ;
strcpy ( V_284 -> V_288 . V_365 . V_134 , V_363 [ V_255 ] ) ;
return 0 ;
}
static int F_196 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_366 * V_367 = F_153 ( V_282 ) ;
V_294 -> V_288 . V_365 . V_318 [ 0 ] = V_367 -> V_368 ;
return 0 ;
}
static int F_197 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_366 * V_367 = F_153 ( V_282 ) ;
unsigned int V_369 = V_367 -> V_368 ;
V_367 -> V_368 = V_294 -> V_288 . V_365 . V_318 [ 0 ] ;
if ( V_367 -> V_368 > V_370 )
V_367 -> V_368 = V_370 ;
if ( V_369 == V_367 -> V_368 )
return 0 ;
F_198 ( V_367 ) ;
return 1 ;
}
int F_199 ( struct V_11 * V_12 ,
struct V_366 * V_367 ,
bool V_371 )
{
struct V_281 * V_317 ;
if ( ! V_367 -> V_367 || ! V_367 -> V_372 )
return 0 ;
F_200 ( V_367 -> V_372 , V_367 -> V_367 , V_12 ) ;
V_367 -> V_12 = V_12 ;
V_367 -> V_368 = V_370 ;
if ( ! V_371 )
return 0 ;
V_317 = F_201 ( & V_373 , V_367 ) ;
if ( ! V_317 )
return - V_54 ;
return F_171 ( V_12 , 0 , V_317 ) ;
}
void F_198 ( struct V_366 * V_367 )
{
if ( ! V_367 -> V_367 || ! V_367 -> V_12 )
return;
if ( V_367 -> V_12 -> V_7 -> V_104 )
return;
switch ( V_367 -> V_368 ) {
case V_370 :
F_202 ( V_367 -> V_372 ) ;
break;
default:
V_367 -> V_367 ( V_367 -> V_12 , V_367 -> V_368 ) ;
break;
}
}
int F_203 ( struct V_281 * V_282 ,
struct V_283 * V_284 )
{
int V_285 = F_155 ( V_282 ) ;
V_284 -> type = V_374 ;
V_284 -> V_287 = V_285 == 3 ? 2 : 1 ;
V_284 -> V_288 . integer . V_289 = 0 ;
V_284 -> V_288 . integer . V_290 = 1 ;
return 0 ;
}
int F_204 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
T_2 V_24 = F_154 ( V_282 ) ;
int V_285 = F_155 ( V_282 ) ;
int V_251 = F_156 ( V_282 ) ;
int V_239 = F_161 ( V_282 ) ;
long * V_295 = V_294 -> V_288 . integer . V_288 ;
if ( V_285 & 1 )
* V_295 ++ = ( F_144 ( V_12 , V_24 , 0 , V_251 , V_239 ) &
V_270 ) ? 0 : 1 ;
if ( V_285 & 2 )
* V_295 = ( F_144 ( V_12 , V_24 , 1 , V_251 , V_239 ) &
V_270 ) ? 0 : 1 ;
return 0 ;
}
int F_205 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
T_2 V_24 = F_154 ( V_282 ) ;
int V_285 = F_155 ( V_282 ) ;
int V_251 = F_156 ( V_282 ) ;
int V_239 = F_161 ( V_282 ) ;
long * V_295 = V_294 -> V_288 . integer . V_288 ;
int V_296 = 0 ;
F_16 ( V_12 ) ;
if ( V_285 & 1 ) {
V_296 = F_146 ( V_12 , V_24 , 0 , V_251 , V_239 ,
V_270 ,
* V_295 ? 0 : V_270 ) ;
V_295 ++ ;
}
if ( V_285 & 2 )
V_296 |= F_146 ( V_12 , V_24 , 1 , V_251 , V_239 ,
V_270 ,
* V_295 ? 0 : V_270 ) ;
F_206 ( V_12 , V_24 ) ;
F_19 ( V_12 ) ;
return V_296 ;
}
int F_207 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
unsigned long V_375 ;
int V_33 ;
F_2 ( & V_12 -> V_191 ) ;
V_375 = V_282 -> V_322 ;
V_282 -> V_322 = V_375 & ~ V_376 ;
V_33 = F_204 ( V_282 , V_294 ) ;
V_282 -> V_322 = V_375 ;
F_4 ( & V_12 -> V_191 ) ;
return V_33 ;
}
int F_208 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
unsigned long V_375 ;
int V_17 , V_377 , V_33 = 0 , V_296 = 0 ;
F_2 ( & V_12 -> V_191 ) ;
V_375 = V_282 -> V_322 ;
V_377 = ( V_375 & V_376 ) >> V_378 ;
for ( V_17 = 0 ; V_17 < V_377 ; V_17 ++ ) {
V_282 -> V_322 = ( V_375 & ~ V_376 ) |
( V_17 << V_378 ) ;
V_33 = F_205 ( V_282 , V_294 ) ;
if ( V_33 < 0 )
break;
V_296 |= V_33 ;
}
V_282 -> V_322 = V_375 ;
F_4 ( & V_12 -> V_191 ) ;
return V_33 < 0 ? V_33 : V_296 ;
}
int F_209 ( struct V_281 * V_282 ,
struct V_283 * V_284 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
struct V_379 * V_136 ;
int V_33 ;
F_2 ( & V_12 -> V_191 ) ;
V_136 = (struct V_379 * ) V_282 -> V_322 ;
V_282 -> V_322 = * V_136 -> V_380 ;
V_33 = V_136 -> V_9 -> V_241 ( V_282 , V_284 ) ;
V_282 -> V_322 = ( long ) V_136 ;
F_4 ( & V_12 -> V_191 ) ;
return V_33 ;
}
int F_210 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
struct V_379 * V_136 ;
int V_33 ;
F_2 ( & V_12 -> V_191 ) ;
V_136 = (struct V_379 * ) V_282 -> V_322 ;
V_282 -> V_322 = * V_136 -> V_380 ;
V_33 = V_136 -> V_9 -> V_381 ( V_282 , V_294 ) ;
V_282 -> V_322 = ( long ) V_136 ;
F_4 ( & V_12 -> V_191 ) ;
return V_33 ;
}
int F_211 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
struct V_379 * V_136 ;
unsigned long * V_382 ;
int V_33 = 0 , V_296 = 0 ;
F_2 ( & V_12 -> V_191 ) ;
V_136 = (struct V_379 * ) V_282 -> V_322 ;
for ( V_382 = V_136 -> V_380 ; * V_382 ; V_382 ++ ) {
V_282 -> V_322 = * V_382 ;
V_33 = V_136 -> V_9 -> V_357 ( V_282 , V_294 ) ;
if ( V_33 < 0 )
break;
V_296 |= V_33 ;
}
V_282 -> V_322 = ( long ) V_136 ;
F_4 ( & V_12 -> V_191 ) ;
return V_33 < 0 ? V_33 : V_296 ;
}
int F_212 ( struct V_281 * V_282 , int V_297 ,
unsigned int V_298 , unsigned int T_5 * V_310 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
struct V_379 * V_136 ;
int V_33 ;
F_2 ( & V_12 -> V_191 ) ;
V_136 = (struct V_379 * ) V_282 -> V_322 ;
V_282 -> V_322 = * V_136 -> V_380 ;
V_33 = V_136 -> V_9 -> V_310 ( V_282 , V_297 , V_298 , V_310 ) ;
V_282 -> V_322 = ( long ) V_136 ;
F_4 ( & V_12 -> V_191 ) ;
return V_33 ;
}
static int F_213 ( struct V_281 * V_282 ,
struct V_283 * V_284 )
{
V_284 -> type = V_383 ;
V_284 -> V_287 = 1 ;
return 0 ;
}
static int F_214 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
V_294 -> V_288 . V_384 . V_385 [ 0 ] = V_386 |
V_387 |
V_388 |
V_389 ;
V_294 -> V_288 . V_384 . V_385 [ 1 ] = V_390 |
V_391 ;
return 0 ;
}
static int F_215 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
V_294 -> V_288 . V_384 . V_385 [ 0 ] = V_386 |
V_387 |
V_392 ;
return 0 ;
}
static int F_216 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
int V_239 = V_282 -> V_322 ;
struct V_196 * V_393 ;
F_2 ( & V_12 -> V_190 ) ;
V_393 = F_84 ( & V_12 -> V_180 , V_239 ) ;
V_294 -> V_288 . V_384 . V_385 [ 0 ] = V_393 -> V_385 & 0xff ;
V_294 -> V_288 . V_384 . V_385 [ 1 ] = ( V_393 -> V_385 >> 8 ) & 0xff ;
V_294 -> V_288 . V_384 . V_385 [ 2 ] = ( V_393 -> V_385 >> 16 ) & 0xff ;
V_294 -> V_288 . V_384 . V_385 [ 3 ] = ( V_393 -> V_385 >> 24 ) & 0xff ;
F_4 ( & V_12 -> V_190 ) ;
return 0 ;
}
static unsigned short F_217 ( unsigned int V_394 )
{
unsigned short V_28 = 0 ;
if ( V_394 & V_386 )
V_28 |= V_395 ;
if ( V_394 & V_387 )
V_28 |= V_396 ;
if ( V_394 & V_386 ) {
if ( ( V_394 & V_397 ) ==
V_392 )
V_28 |= V_398 ;
} else {
if ( ( V_394 & V_399 ) ==
V_388 )
V_28 |= V_398 ;
if ( ! ( V_394 & V_389 ) )
V_28 |= V_400 ;
if ( V_394 & ( V_391 << 8 ) )
V_28 |= V_401 ;
V_28 |= V_394 & ( V_390 << 8 ) ;
}
return V_28 ;
}
static unsigned int F_218 ( unsigned short V_28 )
{
unsigned int V_394 = 0 ;
if ( V_28 & V_396 )
V_394 |= V_387 ;
if ( V_28 & V_395 )
V_394 |= V_386 ;
if ( V_394 & V_386 ) {
if ( V_28 & V_398 )
V_394 |= V_392 ;
} else {
if ( V_28 & V_398 )
V_394 |= V_388 ;
if ( ! ( V_28 & V_400 ) )
V_394 |= V_389 ;
if ( V_28 & V_401 )
V_394 |= ( V_391 << 8 ) ;
V_394 |= V_28 & ( 0x7f << 8 ) ;
}
return V_394 ;
}
static void F_219 ( struct V_11 * V_12 , T_2 V_24 ,
int V_26 , int V_28 )
{
const T_2 * V_402 ;
F_220 ( V_12 , V_24 , 0 , V_26 , V_28 ) ;
V_402 = V_12 -> V_343 ;
if ( ! V_402 )
return;
for (; * V_402 ; V_402 ++ )
F_220 ( V_12 , * V_402 , 0 , V_26 , V_28 ) ;
}
static inline void F_221 ( struct V_11 * V_12 , T_2 V_24 ,
int V_403 , int V_404 )
{
if ( V_403 != - 1 )
F_219 ( V_12 , V_24 , V_405 , V_403 ) ;
if ( V_404 != - 1 )
F_219 ( V_12 , V_24 , V_406 , V_404 ) ;
}
static int F_222 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
int V_239 = V_282 -> V_322 ;
struct V_196 * V_393 ;
T_2 V_24 ;
unsigned short V_28 ;
int V_296 ;
F_2 ( & V_12 -> V_190 ) ;
V_393 = F_84 ( & V_12 -> V_180 , V_239 ) ;
V_24 = V_393 -> V_24 ;
V_393 -> V_385 = V_294 -> V_288 . V_384 . V_385 [ 0 ] |
( ( unsigned int ) V_294 -> V_288 . V_384 . V_385 [ 1 ] << 8 ) |
( ( unsigned int ) V_294 -> V_288 . V_384 . V_385 [ 2 ] << 16 ) |
( ( unsigned int ) V_294 -> V_288 . V_384 . V_385 [ 3 ] << 24 ) ;
V_28 = F_217 ( V_393 -> V_385 ) ;
V_28 |= V_393 -> V_407 & 1 ;
V_296 = V_393 -> V_407 != V_28 ;
V_393 -> V_407 = V_28 ;
if ( V_296 && V_24 != ( T_3 ) - 1 )
F_221 ( V_12 , V_24 , V_28 & 0xff , ( V_28 >> 8 ) & 0xff ) ;
F_4 ( & V_12 -> V_190 ) ;
return V_296 ;
}
static int F_223 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
int V_239 = V_282 -> V_322 ;
struct V_196 * V_393 ;
F_2 ( & V_12 -> V_190 ) ;
V_393 = F_84 ( & V_12 -> V_180 , V_239 ) ;
V_294 -> V_288 . integer . V_288 [ 0 ] = V_393 -> V_407 & V_408 ;
F_4 ( & V_12 -> V_190 ) ;
return 0 ;
}
static inline void F_224 ( struct V_11 * V_12 , T_2 V_24 ,
int V_403 , int V_404 )
{
F_221 ( V_12 , V_24 , V_403 , V_404 ) ;
if ( ( F_47 ( V_12 , V_24 ) & V_409 ) &&
( V_403 & V_408 ) )
F_147 ( V_12 , V_24 , V_248 , 0 ,
V_270 , 0 ) ;
}
static int F_225 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
int V_239 = V_282 -> V_322 ;
struct V_196 * V_393 ;
T_2 V_24 ;
unsigned short V_28 ;
int V_296 ;
F_2 ( & V_12 -> V_190 ) ;
V_393 = F_84 ( & V_12 -> V_180 , V_239 ) ;
V_24 = V_393 -> V_24 ;
V_28 = V_393 -> V_407 & ~ V_408 ;
if ( V_294 -> V_288 . integer . V_288 [ 0 ] )
V_28 |= V_408 ;
V_296 = V_393 -> V_407 != V_28 ;
V_393 -> V_407 = V_28 ;
if ( V_296 && V_24 != ( T_3 ) - 1 )
F_224 ( V_12 , V_24 , V_28 & 0xff , - 1 ) ;
F_4 ( & V_12 -> V_190 ) ;
return V_296 ;
}
int F_226 ( struct V_11 * V_12 ,
T_2 V_410 ,
T_2 V_411 ,
int type )
{
int V_33 ;
struct V_281 * V_317 ;
struct V_412 * V_413 ;
int V_239 = 0 ;
const int V_414 = 16 ;
struct V_196 * V_393 ;
struct V_6 * V_7 = V_12 -> V_7 ;
if ( V_7 -> V_415 == V_416 &&
type == V_417 ) {
V_239 = V_414 ;
} else if ( V_7 -> V_415 == V_417 &&
type == V_416 ) {
for ( V_413 = V_418 ; V_413 -> V_134 ; V_413 ++ ) {
V_317 = F_167 ( V_12 , V_413 -> V_134 , 0 , 0 ) ;
if ( ! V_317 )
break;
V_317 -> V_127 . V_255 = V_414 ;
}
V_7 -> V_415 = V_416 ;
}
if ( ! V_7 -> V_415 )
V_7 -> V_415 = type ;
V_239 = F_170 ( V_12 , L_69 , V_239 ) ;
if ( V_239 < 0 ) {
F_14 ( V_30 L_70 ) ;
return - V_189 ;
}
V_393 = F_82 ( & V_12 -> V_180 ) ;
if ( ! V_393 )
return - V_54 ;
for ( V_413 = V_418 ; V_413 -> V_134 ; V_413 ++ ) {
V_317 = F_201 ( V_413 , V_12 ) ;
if ( ! V_317 )
return - V_54 ;
V_317 -> V_127 . V_255 = V_239 ;
V_317 -> V_322 = V_12 -> V_180 . V_166 - 1 ;
V_33 = F_171 ( V_12 , V_410 , V_317 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_393 -> V_24 = V_411 ;
V_393 -> V_407 = F_23 ( V_12 , V_411 , 0 ,
V_419 , 0 ) ;
V_393 -> V_385 = F_218 ( V_393 -> V_407 ) ;
return 0 ;
}
struct V_196 * F_227 ( struct V_11 * V_12 ,
T_2 V_24 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_180 . V_166 ; V_17 ++ ) {
struct V_196 * V_393 =
F_84 ( & V_12 -> V_180 , V_17 ) ;
if ( V_393 -> V_24 == V_24 )
return V_393 ;
}
return NULL ;
}
void F_228 ( struct V_11 * V_12 , int V_239 )
{
struct V_196 * V_393 ;
F_2 ( & V_12 -> V_190 ) ;
V_393 = F_84 ( & V_12 -> V_180 , V_239 ) ;
V_393 -> V_24 = ( T_3 ) - 1 ;
F_4 ( & V_12 -> V_190 ) ;
}
void F_229 ( struct V_11 * V_12 , int V_239 , T_2 V_24 )
{
struct V_196 * V_393 ;
unsigned short V_28 ;
F_2 ( & V_12 -> V_190 ) ;
V_393 = F_84 ( & V_12 -> V_180 , V_239 ) ;
if ( V_393 -> V_24 != V_24 ) {
V_393 -> V_24 = V_24 ;
V_28 = V_393 -> V_407 ;
F_224 ( V_12 , V_24 , V_28 & 0xff , ( V_28 >> 8 ) & 0xff ) ;
}
F_4 ( & V_12 -> V_190 ) ;
}
static int F_230 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_420 * V_421 = F_153 ( V_282 ) ;
V_294 -> V_288 . integer . V_288 [ 0 ] = V_421 -> V_422 ;
return 0 ;
}
static int F_231 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_420 * V_421 = F_153 ( V_282 ) ;
V_421 -> V_422 = ! ! V_294 -> V_288 . integer . V_288 [ 0 ] ;
return 0 ;
}
int F_232 ( struct V_11 * V_12 ,
struct V_420 * V_421 )
{
struct V_281 * V_317 ;
if ( ! V_421 -> V_423 )
return 0 ;
V_317 = F_201 ( & V_424 , V_421 ) ;
if ( ! V_317 )
return - V_54 ;
return F_171 ( V_12 , V_421 -> V_423 , V_317 ) ;
}
static int F_233 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
V_294 -> V_288 . integer . V_288 [ 0 ] = V_12 -> V_425 ;
return 0 ;
}
static int F_234 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
T_2 V_24 = V_282 -> V_322 ;
unsigned int V_28 = ! ! V_294 -> V_288 . integer . V_288 [ 0 ] ;
int V_296 ;
F_2 ( & V_12 -> V_190 ) ;
V_296 = V_12 -> V_425 != V_28 ;
if ( V_296 ) {
V_12 -> V_425 = V_28 ;
F_220 ( V_12 , V_24 , 0 ,
V_405 , V_28 ) ;
}
F_4 ( & V_12 -> V_190 ) ;
return V_296 ;
}
static int F_235 ( struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_11 * V_12 = F_153 ( V_282 ) ;
T_2 V_24 = V_282 -> V_322 ;
unsigned short V_28 ;
unsigned int V_394 ;
V_28 = F_23 ( V_12 , V_24 , 0 , V_419 , 0 ) ;
V_394 = F_218 ( V_28 ) ;
V_294 -> V_288 . V_384 . V_385 [ 0 ] = V_394 ;
V_294 -> V_288 . V_384 . V_385 [ 1 ] = V_394 >> 8 ;
V_294 -> V_288 . V_384 . V_385 [ 2 ] = V_394 >> 16 ;
V_294 -> V_288 . V_384 . V_385 [ 3 ] = V_394 >> 24 ;
return 0 ;
}
int F_236 ( struct V_11 * V_12 , T_2 V_24 )
{
int V_33 ;
struct V_281 * V_317 ;
struct V_412 * V_413 ;
int V_239 ;
V_239 = F_170 ( V_12 , L_71 , 0 ) ;
if ( V_239 < 0 ) {
F_14 ( V_30 L_72 ) ;
return - V_189 ;
}
for ( V_413 = V_426 ; V_413 -> V_134 ; V_413 ++ ) {
V_317 = F_201 ( V_413 , V_12 ) ;
if ( ! V_317 )
return - V_54 ;
V_317 -> V_322 = V_24 ;
V_33 = F_171 ( V_12 , V_24 , V_317 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_12 -> V_425 =
F_23 ( V_12 , V_24 , 0 ,
V_419 , 0 ) &
V_408 ;
return 0 ;
}
int F_220 ( struct V_11 * V_12 , T_2 V_24 ,
int V_25 , unsigned int V_26 , unsigned int V_27 )
{
int V_33 ;
struct V_194 * V_136 ;
T_1 V_238 ;
unsigned int V_274 ;
V_274 = V_12 -> V_275 ;
if ( ! V_274 ) {
V_33 = F_24 ( V_12 , V_24 , V_25 , V_26 , V_27 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_26 = V_26 | ( V_27 >> 8 ) ;
V_27 &= 0xff ;
V_238 = F_237 ( V_24 , V_26 ) ;
F_2 ( & V_12 -> V_7 -> V_35 ) ;
V_136 = F_128 ( & V_12 -> V_183 , V_238 ) ;
if ( V_136 ) {
V_136 -> V_28 = V_27 ;
V_136 -> V_229 = V_274 ;
}
F_4 ( & V_12 -> V_7 -> V_35 ) ;
return 0 ;
}
int F_238 ( struct V_11 * V_12 , T_2 V_24 ,
int V_25 , unsigned int V_26 , unsigned int V_27 )
{
struct V_194 * V_136 ;
T_1 V_238 ;
V_26 = V_26 | ( V_27 >> 8 ) ;
V_27 &= 0xff ;
V_238 = F_237 ( V_24 , V_26 ) ;
F_2 ( & V_12 -> V_7 -> V_35 ) ;
V_136 = F_127 ( & V_12 -> V_183 , V_238 ) ;
if ( V_136 && V_136 -> V_28 == V_27 ) {
F_4 ( & V_12 -> V_7 -> V_35 ) ;
return 0 ;
}
F_4 ( & V_12 -> V_7 -> V_35 ) ;
return F_220 ( V_12 , V_24 , V_25 , V_26 , V_27 ) ;
}
void F_239 ( struct V_11 * V_12 )
{
int V_17 ;
F_2 ( & V_12 -> V_192 ) ;
V_12 -> V_275 = 0 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_183 . V_237 . V_166 ; V_17 ++ ) {
struct V_194 * V_277 ;
T_1 V_238 ;
V_277 = F_84 ( & V_12 -> V_183 . V_237 , V_17 ) ;
V_238 = V_277 -> V_238 ;
if ( ! V_238 )
continue;
if ( ! V_277 -> V_229 )
continue;
V_277 -> V_229 = 0 ;
F_4 ( & V_12 -> V_192 ) ;
F_24 ( V_12 , F_240 ( V_238 ) , 0 ,
F_241 ( V_238 ) , V_277 -> V_28 ) ;
F_2 ( & V_12 -> V_192 ) ;
}
F_4 ( & V_12 -> V_192 ) ;
}
void F_242 ( struct V_11 * V_12 ,
const struct V_45 * V_46 )
{
for (; V_46 -> V_24 ; V_46 ++ )
F_220 ( V_12 , V_46 -> V_24 , 0 , V_46 -> V_26 ,
V_46 -> V_47 ) ;
}
void F_243 ( struct V_11 * V_12 )
{
F_150 ( V_12 ) ;
F_239 ( V_12 ) ;
}
void F_244 ( struct V_11 * V_12 , T_2 V_187 ,
unsigned int V_427 )
{
T_2 V_24 = V_12 -> V_155 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_154 ; V_17 ++ , V_24 ++ ) {
unsigned int V_63 = F_47 ( V_12 , V_24 ) ;
unsigned int V_428 = V_427 ;
if ( ! ( V_63 & V_429 ) )
continue;
if ( V_12 -> V_430 ) {
V_428 = V_12 -> V_430 ( V_12 , V_24 , V_427 ) ;
if ( V_428 != V_427 && V_427 == V_431 )
continue;
}
F_24 ( V_12 , V_24 , 0 , V_432 ,
V_428 ) ;
}
}
static bool F_111 ( struct V_11 * V_12 , T_2 V_187 ,
unsigned int V_427 )
{
int V_433 = F_27 ( V_12 , V_187 , V_434 ) ;
if ( V_433 == - 1 )
return false ;
if ( V_433 & V_427 )
return true ;
else
return false ;
}
static unsigned int F_245 ( struct V_11 * V_12 ,
T_2 V_187 ,
unsigned int V_427 )
{
unsigned long V_435 = V_339 + F_246 ( 500 ) ;
unsigned int V_428 , V_436 ;
for (; ; ) {
V_428 = F_23 ( V_12 , V_187 , 0 ,
V_437 , 0 ) ;
if ( V_428 & V_438 )
break;
V_436 = ( V_428 >> 4 ) & 0x0f ;
if ( V_436 == V_427 )
break;
if ( F_247 ( V_339 , V_435 ) )
break;
F_121 ( 1 ) ;
}
return V_428 ;
}
unsigned int F_248 ( struct V_11 * V_12 ,
T_2 V_24 ,
unsigned int V_427 )
{
if ( V_427 == V_431 &&
F_48 ( F_47 ( V_12 , V_24 ) ) == V_84 &&
( F_138 ( V_12 , V_24 ) & V_439 ) ) {
int V_440 = F_23 ( V_12 , V_24 , 0 ,
V_441 , 0 ) ;
if ( V_440 & 0x02 )
return V_213 ;
}
return V_427 ;
}
static unsigned int F_112 ( struct V_11 * V_12 ,
unsigned int V_427 )
{
T_2 V_187 = V_12 -> V_128 ? V_12 -> V_128 : V_12 -> V_129 ;
int V_287 ;
unsigned int V_428 ;
int V_25 = 0 ;
if ( V_427 == V_431 ) {
F_121 ( V_12 -> V_211 ? 10 : 100 ) ;
V_25 = V_36 ;
}
for ( V_287 = 0 ; V_287 < 10 ; V_287 ++ ) {
if ( V_12 -> V_98 . V_442 )
V_12 -> V_98 . V_442 ( V_12 , V_187 ,
V_427 ) ;
else {
F_23 ( V_12 , V_187 , V_25 ,
V_432 ,
V_427 ) ;
F_244 ( V_12 , V_187 , V_427 ) ;
}
V_428 = F_245 ( V_12 , V_187 , V_427 ) ;
if ( ! ( V_428 & V_438 ) )
break;
}
return V_428 ;
}
static void F_249 ( struct V_11 * V_12 )
{
T_2 V_24 = V_12 -> V_155 ;
int V_17 ;
if ( ! V_12 -> V_430 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_154 ; V_17 ++ , V_24 ++ ) {
unsigned int V_63 = F_47 ( V_12 , V_24 ) ;
unsigned int V_170 ;
if ( ! ( V_63 & V_429 ) )
continue;
V_170 = V_12 -> V_430 ( V_12 , V_24 , V_213 ) ;
if ( V_170 == V_213 )
continue;
if ( ! F_250 ( V_12 , V_24 , V_170 ) )
F_24 ( V_12 , V_24 , 0 ,
V_432 , V_170 ) ;
}
}
static void F_251 ( struct V_11 * V_12 )
{
if ( V_12 -> V_443 . V_4 )
F_25 ( V_12 , V_12 -> V_443 . V_4 ) ;
}
static inline void F_251 ( struct V_11 * V_12 ) {}
static unsigned int F_252 ( struct V_11 * V_12 , bool V_444 )
{
unsigned int V_428 ;
V_12 -> V_445 = 1 ;
if ( V_12 -> V_98 . V_446 )
V_12 -> V_98 . V_446 ( V_12 ) ;
F_126 ( V_12 ) ;
V_428 = F_112 ( V_12 , V_431 ) ;
if ( ! V_444 )
F_100 ( & V_12 -> V_177 ) ;
F_178 ( & V_12 -> V_200 ) ;
F_253 ( V_12 ) ;
F_254 ( V_12 ) ;
V_12 -> V_336 = 0 ;
V_12 -> V_337 = 0 ;
V_12 -> V_338 = V_339 ;
F_179 ( & V_12 -> V_200 ) ;
V_12 -> V_445 = 0 ;
return V_428 ;
}
static void F_255 ( struct V_11 * V_12 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_183 . V_237 . V_166 ; V_17 ++ ) {
struct V_194 * V_31 ;
V_31 = F_84 ( & V_12 -> V_183 . V_237 , V_17 ) ;
V_31 -> V_229 = 1 ;
}
for ( V_17 = 0 ; V_17 < V_12 -> V_182 . V_237 . V_166 ; V_17 ++ ) {
struct V_193 * V_447 ;
V_447 = F_84 ( & V_12 -> V_182 . V_237 , V_17 ) ;
V_447 -> V_244 . V_229 = 1 ;
}
}
static void F_256 ( struct V_11 * V_12 )
{
V_12 -> V_445 = 1 ;
F_255 ( V_12 ) ;
F_8 ( V_12 ) ;
F_112 ( V_12 , V_213 ) ;
F_92 ( V_12 ) ;
F_251 ( V_12 ) ;
F_94 ( V_12 ) ;
if ( V_12 -> V_98 . V_448 )
V_12 -> V_98 . V_448 ( V_12 ) ;
else {
if ( V_12 -> V_98 . V_449 )
V_12 -> V_98 . V_449 ( V_12 ) ;
F_150 ( V_12 ) ;
F_239 ( V_12 ) ;
}
if ( V_12 -> V_174 )
F_93 ( & V_12 -> V_173 . V_93 ) ;
else
F_257 ( V_12 ) ;
V_12 -> V_445 = 0 ;
F_19 ( V_12 ) ;
}
int F_258 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
int V_33 = F_259 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_73
L_74 , V_12 -> V_29 , V_33 ) ;
V_33 = F_181 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30
L_75 ) ;
return V_33 ;
}
}
}
return 0 ;
}
static int F_260 ( struct V_11 * V_12 )
{
int V_17 , V_450 , V_33 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_330 ; V_17 ++ ) {
for ( V_450 = 0 ; V_450 < 2 ; V_450 ++ ) {
struct V_451 * V_329 = V_12 -> V_333 [ V_17 ] . V_329 ;
struct V_452 * V_453 =
& V_12 -> V_333 [ V_17 ] . V_454 [ V_450 ] ;
struct V_455 * V_456 ;
const struct V_457 * V_458 ;
if ( V_12 -> V_333 [ V_17 ] . V_459 )
continue;
if ( ! V_329 || ! V_453 -> V_460 )
continue;
V_458 = V_453 -> V_456 ? V_453 -> V_456 : V_461 ;
V_33 = F_261 ( V_329 , V_450 , V_458 ,
V_453 -> V_462 ,
0 , & V_456 ) ;
if ( V_33 < 0 )
return V_33 ;
V_456 -> V_463 = V_464 ;
}
}
return 0 ;
}
int F_259 ( struct V_11 * V_12 )
{
int V_33 = 0 ;
F_251 ( V_12 ) ;
if ( V_12 -> V_98 . V_449 )
V_33 = V_12 -> V_98 . V_449 ( V_12 ) ;
if ( ! V_33 && V_12 -> V_98 . V_465 )
V_33 = V_12 -> V_98 . V_465 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_260 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_12 -> V_174 )
F_93 ( & V_12 -> V_173 . V_93 ) ;
else
F_257 ( V_12 ) ;
F_249 ( V_12 ) ;
return 0 ;
}
unsigned int F_262 ( unsigned int V_466 ,
unsigned int V_467 ,
unsigned int V_223 ,
unsigned int V_468 ,
unsigned short V_469 )
{
int V_17 ;
unsigned int V_28 = 0 ;
for ( V_17 = 0 ; V_470 [ V_17 ] . V_471 ; V_17 ++ )
if ( V_470 [ V_17 ] . V_471 == V_466 ) {
V_28 = V_470 [ V_17 ] . V_472 ;
break;
}
if ( ! V_470 [ V_17 ] . V_471 ) {
F_110 ( L_76 , V_466 ) ;
return 0 ;
}
if ( V_467 == 0 || V_467 > 8 ) {
F_110 ( L_77 , V_467 ) ;
return 0 ;
}
V_28 |= V_467 - 1 ;
switch ( F_263 ( V_223 ) ) {
case 8 :
V_28 |= V_473 ;
break;
case 16 :
V_28 |= V_474 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_468 >= 32 || V_223 == V_475 )
V_28 |= V_476 ;
else if ( V_468 >= 24 )
V_28 |= V_477 ;
else
V_28 |= V_478 ;
break;
default:
F_110 ( L_78 ,
F_263 ( V_223 ) ) ;
return 0 ;
}
if ( V_469 & V_396 )
V_28 |= V_479 ;
return V_28 ;
}
static unsigned int F_264 ( struct V_11 * V_12 , T_2 V_24 ,
int V_251 )
{
unsigned int V_28 = 0 ;
if ( V_24 != V_12 -> V_128 &&
( F_47 ( V_12 , V_24 ) & V_480 ) )
V_28 = F_27 ( V_12 , V_24 , V_481 ) ;
if ( ! V_28 || V_28 == - 1 )
V_28 = F_27 ( V_12 , V_12 -> V_128 , V_481 ) ;
if ( ! V_28 || V_28 == - 1 )
return 0 ;
return V_28 ;
}
static unsigned int F_265 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_134 ( V_12 , V_24 , 0 , F_266 ( V_24 ) ,
F_264 ) ;
}
static unsigned int F_267 ( struct V_11 * V_12 , T_2 V_24 ,
int V_251 )
{
unsigned int V_334 = F_27 ( V_12 , V_24 , V_482 ) ;
if ( ! V_334 || V_334 == - 1 )
V_334 = F_27 ( V_12 , V_12 -> V_128 , V_482 ) ;
if ( ! V_334 || V_334 == - 1 )
return 0 ;
return V_334 ;
}
static unsigned int F_268 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_134 ( V_12 , V_24 , 0 , F_269 ( V_24 ) ,
F_267 ) ;
}
int F_270 ( struct V_11 * V_12 , T_2 V_24 ,
T_1 * V_483 , T_8 * V_484 , unsigned int * V_485 )
{
unsigned int V_17 , V_28 , V_63 ;
V_63 = F_47 ( V_12 , V_24 ) ;
V_28 = F_265 ( V_12 , V_24 ) ;
if ( V_483 ) {
T_1 V_486 = 0 ;
for ( V_17 = 0 ; V_17 < V_487 ; V_17 ++ ) {
if ( V_28 & ( 1 << V_17 ) )
V_486 |= V_470 [ V_17 ] . V_488 ;
}
if ( V_486 == 0 ) {
F_45 ( V_30 L_79
L_80 ,
V_24 , V_28 ,
( V_63 & V_480 ) ? 1 : 0 ) ;
return - V_76 ;
}
* V_483 = V_486 ;
}
if ( V_484 || V_485 ) {
T_8 V_489 = 0 ;
unsigned int V_334 , V_490 ;
V_334 = F_268 ( V_12 , V_24 ) ;
if ( ! V_334 )
return - V_76 ;
V_490 = 0 ;
if ( V_334 & V_491 ) {
if ( V_28 & V_492 ) {
V_489 |= V_493 ;
V_490 = 8 ;
}
if ( V_28 & V_494 ) {
V_489 |= V_495 ;
V_490 = 16 ;
}
if ( V_63 & V_496 ) {
if ( V_28 & V_497 )
V_489 |= V_498 ;
if ( V_28 & ( V_499 | V_500 ) )
V_489 |= V_501 ;
if ( V_28 & V_500 )
V_490 = 24 ;
else if ( V_28 & V_499 )
V_490 = 20 ;
} else if ( V_28 & ( V_499 | V_500 |
V_497 ) ) {
V_489 |= V_501 ;
if ( V_28 & V_497 )
V_490 = 32 ;
else if ( V_28 & V_500 )
V_490 = 24 ;
else if ( V_28 & V_499 )
V_490 = 20 ;
}
}
#if 0
if (streams & AC_SUPFMT_FLOAT32) {
formats |= SNDRV_PCM_FMTBIT_FLOAT_LE;
if (!bps)
bps = 32;
}
#endif
if ( V_334 == V_502 ) {
V_489 |= V_493 ;
V_490 = 8 ;
}
if ( V_489 == 0 ) {
F_45 ( V_30 L_81
L_82
L_83 ,
V_24 , V_28 ,
( V_63 & V_480 ) ? 1 : 0 ,
V_334 ) ;
return - V_76 ;
}
if ( V_484 )
* V_484 = V_489 ;
if ( V_485 )
* V_485 = V_490 ;
}
return 0 ;
}
int F_271 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_223 )
{
int V_17 ;
unsigned int V_28 = 0 , V_466 , V_454 ;
V_28 = F_265 ( V_12 , V_24 ) ;
if ( ! V_28 )
return 0 ;
V_466 = V_223 & 0xff00 ;
for ( V_17 = 0 ; V_17 < V_487 ; V_17 ++ )
if ( V_470 [ V_17 ] . V_472 == V_466 ) {
if ( V_28 & ( 1 << V_17 ) )
break;
return 0 ;
}
if ( V_17 >= V_487 )
return 0 ;
V_454 = F_268 ( V_12 , V_24 ) ;
if ( ! V_454 )
return 0 ;
if ( V_454 & V_491 ) {
switch ( V_223 & 0xf0 ) {
case 0x00 :
if ( ! ( V_28 & V_492 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_28 & V_494 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_28 & V_499 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_28 & V_500 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_28 & V_497 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_272 ( struct V_452 * V_453 ,
struct V_11 * V_12 ,
struct V_503 * V_504 )
{
return 0 ;
}
static int F_273 ( struct V_452 * V_453 ,
struct V_11 * V_12 ,
unsigned int V_217 ,
unsigned int V_223 ,
struct V_503 * V_504 )
{
F_122 ( V_12 , V_453 -> V_24 , V_217 , 0 , V_223 ) ;
return 0 ;
}
static int F_274 ( struct V_452 * V_453 ,
struct V_11 * V_12 ,
struct V_503 * V_504 )
{
F_275 ( V_12 , V_453 -> V_24 ) ;
return 0 ;
}
static int F_276 ( struct V_11 * V_12 ,
struct V_452 * V_241 )
{
int V_33 ;
if ( V_241 -> V_24 && ( ! V_241 -> V_486 || ! V_241 -> V_489 ) ) {
V_33 = F_270 ( V_12 , V_241 -> V_24 ,
V_241 -> V_486 ? NULL : & V_241 -> V_486 ,
V_241 -> V_489 ? NULL : & V_241 -> V_489 ,
V_241 -> V_468 ? NULL : & V_241 -> V_468 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_241 -> V_9 . V_505 == NULL )
V_241 -> V_9 . V_505 = F_272 ;
if ( V_241 -> V_9 . V_506 == NULL )
V_241 -> V_9 . V_506 = F_272 ;
if ( V_241 -> V_9 . V_507 == NULL ) {
if ( F_43 ( ! V_241 -> V_24 ) )
return - V_61 ;
V_241 -> V_9 . V_507 = F_273 ;
}
if ( V_241 -> V_9 . V_508 == NULL ) {
if ( F_43 ( ! V_241 -> V_24 ) )
return - V_61 ;
V_241 -> V_9 . V_508 = F_274 ;
}
return 0 ;
}
int F_277 ( struct V_11 * V_12 ,
struct V_452 * V_453 ,
unsigned int V_454 ,
unsigned int V_223 ,
struct V_503 * V_504 )
{
int V_276 ;
F_2 ( & V_12 -> V_7 -> V_118 ) ;
V_276 = V_453 -> V_9 . V_507 ( V_453 , V_12 , V_454 , V_223 , V_504 ) ;
if ( V_276 >= 0 )
F_125 ( V_12 ) ;
F_4 ( & V_12 -> V_7 -> V_118 ) ;
return V_276 ;
}
void F_278 ( struct V_11 * V_12 ,
struct V_452 * V_453 ,
struct V_503 * V_504 )
{
F_2 ( & V_12 -> V_7 -> V_118 ) ;
V_453 -> V_9 . V_508 ( V_453 , V_12 , V_504 ) ;
F_4 ( & V_12 -> V_7 -> V_118 ) ;
}
static int F_279 ( struct V_6 * V_7 , unsigned int type )
{
static int V_509 [ V_510 ] [ 5 ] = {
[ V_511 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_417 ] = { 1 , - 1 } ,
[ V_416 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_512 ] = { 6 , - 1 } ,
} ;
int V_17 ;
if ( type >= V_510 ) {
F_45 ( V_79 L_84 , type ) ;
return - V_61 ;
}
for ( V_17 = 0 ; V_509 [ type ] [ V_17 ] >= 0 ; V_17 ++ ) {
#ifndef F_280
if ( V_509 [ type ] [ V_17 ] >= 8 )
break;
#endif
if ( ! F_281 ( V_509 [ type ] [ V_17 ] , V_7 -> V_340 ) )
return V_509 [ type ] [ V_17 ] ;
}
#ifdef F_280
for ( V_17 = 10 ; V_17 < 32 ; V_17 ++ ) {
if ( ! F_281 ( V_17 , V_7 -> V_340 ) )
return V_17 ;
}
#endif
F_45 ( V_79 L_85 ,
V_513 [ type ] ) ;
#ifndef F_280
F_45 ( V_79 L_86 ) ;
#endif
return - V_39 ;
}
static int F_282 ( struct V_11 * V_12 , struct V_331 * V_329 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_452 * V_241 ;
int V_454 , V_33 ;
if ( F_43 ( ! V_329 -> V_134 ) )
return - V_61 ;
for ( V_454 = 0 ; V_454 < 2 ; V_454 ++ ) {
V_241 = & V_329 -> V_454 [ V_454 ] ;
if ( V_241 -> V_460 ) {
V_33 = F_276 ( V_12 , V_241 ) ;
if ( V_33 < 0 )
return V_33 ;
}
}
return V_7 -> V_9 . V_514 ( V_7 , V_12 , V_329 ) ;
}
int F_283 ( struct V_11 * V_12 )
{
unsigned int V_329 ;
int V_33 ;
if ( ! V_12 -> V_330 ) {
if ( ! V_12 -> V_98 . V_515 )
return 0 ;
V_33 = V_12 -> V_98 . V_515 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_87
L_74 , V_12 -> V_29 , V_33 ) ;
V_33 = F_181 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30
L_75 ) ;
return V_33 ;
}
}
}
for ( V_329 = 0 ; V_329 < V_12 -> V_330 ; V_329 ++ ) {
struct V_331 * V_332 = & V_12 -> V_333 [ V_329 ] ;
int V_312 ;
if ( ! V_332 -> V_454 [ 0 ] . V_460 && ! V_332 -> V_454 [ 1 ] . V_460 )
continue;
if ( ! V_332 -> V_329 ) {
V_312 = F_279 ( V_12 -> V_7 , V_332 -> V_516 ) ;
if ( V_312 < 0 )
continue;
V_332 -> V_102 = V_312 ;
V_33 = F_282 ( V_12 , V_332 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_88
L_89 ,
V_312 , V_12 -> V_29 ) ;
continue;
}
}
}
return 0 ;
}
int F_284 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
int V_33 = F_283 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
}
return 0 ;
}
int F_285 ( struct V_11 * V_12 ,
int V_517 , const char * const * V_518 ,
const struct V_519 * V_124 )
{
if ( V_12 -> V_116 && V_518 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_517 ; V_17 ++ ) {
if ( V_518 [ V_17 ] &&
! strcmp ( V_12 -> V_116 , V_518 [ V_17 ] ) ) {
F_21 ( V_520 L_90
L_91 , V_518 [ V_17 ] ) ;
return V_17 ;
}
}
}
if ( ! V_12 -> V_7 -> V_115 || ! V_124 )
return - 1 ;
V_124 = F_286 ( V_12 -> V_7 -> V_115 , V_124 ) ;
if ( ! V_124 )
return - 1 ;
if ( V_124 -> V_288 >= 0 && V_124 -> V_288 < V_517 ) {
#ifdef F_287
char V_138 [ 10 ] ;
const char * V_521 = NULL ;
if ( V_518 )
V_521 = V_518 [ V_124 -> V_288 ] ;
if ( ! V_521 ) {
sprintf ( V_138 , L_92 , V_124 -> V_288 ) ;
V_521 = V_138 ;
}
F_110 ( V_520 L_93
L_94 ,
V_521 , V_124 -> V_522 , V_124 -> V_319 ,
( V_124 -> V_134 ? V_124 -> V_134 : L_95 ) ) ;
#endif
return V_124 -> V_288 ;
}
return - 1 ;
}
int F_288 ( struct V_11 * V_12 ,
int V_517 , const char * const * V_518 ,
const struct V_519 * V_124 )
{
const struct V_519 * V_232 ;
for ( V_232 = V_124 ; V_232 -> V_522 ; V_232 ++ ) {
unsigned int V_70 = 0xffff0000 | V_232 -> V_523 ;
unsigned int V_127 = ( V_232 -> V_319 | ( V_232 -> V_522 << 16 ) ) & V_70 ;
if ( ( V_12 -> V_204 & V_70 ) == V_127 )
break;
}
if ( ! V_232 -> V_522 )
return - 1 ;
V_124 = V_232 ;
if ( V_124 -> V_288 >= 0 && V_124 -> V_288 < V_517 ) {
#ifdef F_287
char V_138 [ 10 ] ;
const char * V_521 = NULL ;
if ( V_518 )
V_521 = V_518 [ V_124 -> V_288 ] ;
if ( ! V_521 ) {
sprintf ( V_138 , L_92 , V_124 -> V_288 ) ;
V_521 = V_138 ;
}
F_110 ( V_520 L_93
L_94 ,
V_521 , V_124 -> V_522 , V_124 -> V_319 ,
( V_124 -> V_134 ? V_124 -> V_134 : L_95 ) ) ;
#endif
return V_124 -> V_288 ;
}
return - 1 ;
}
int F_289 ( struct V_11 * V_12 ,
const struct V_412 * V_524 )
{
int V_33 ;
for (; V_524 -> V_134 ; V_524 ++ ) {
struct V_281 * V_317 ;
int V_29 = 0 , V_239 = 0 ;
if ( V_524 -> V_314 == - 1 )
continue;
for (; ; ) {
V_317 = F_201 ( V_524 , V_12 ) ;
if ( ! V_317 )
return - V_54 ;
if ( V_29 > 0 )
V_317 -> V_127 . V_102 = V_29 ;
if ( V_239 > 0 )
V_317 -> V_127 . V_255 = V_239 ;
V_33 = F_171 ( V_12 , 0 , V_317 ) ;
if ( ! V_33 )
break;
if ( ! V_29 && V_12 -> V_29 )
V_29 = V_12 -> V_29 ;
else if ( ! V_239 && ! V_524 -> V_255 ) {
V_239 = F_170 ( V_12 ,
V_524 -> V_134 , 0 ) ;
if ( V_239 <= 0 )
return V_33 ;
} else
return V_33 ;
}
}
return 0 ;
}
static void V_201 ( struct V_94 * V_93 )
{
struct V_11 * V_12 =
F_54 ( V_93 , struct V_11 , V_177 . V_93 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
unsigned int V_428 ;
F_178 ( & V_12 -> V_200 ) ;
if ( V_12 -> V_337 > 0 ) {
F_179 ( & V_12 -> V_200 ) ;
return;
}
if ( ! V_12 -> V_336 || V_12 -> V_525 ) {
V_12 -> V_337 = 0 ;
F_179 ( & V_12 -> V_200 ) ;
return;
}
F_179 ( & V_12 -> V_200 ) ;
V_428 = F_252 ( V_12 , true ) ;
V_12 -> V_181 = 0 ;
if ( ! V_7 -> V_210 && ( V_428 & V_526 ) ) {
V_12 -> V_181 = 1 ;
F_7 ( V_7 , false ) ;
}
}
static void F_8 ( struct V_11 * V_12 )
{
F_178 ( & V_12 -> V_200 ) ;
V_12 -> V_525 ++ ;
V_12 -> V_336 = 1 ;
V_12 -> V_338 = V_339 ;
F_179 ( & V_12 -> V_200 ) ;
}
void F_253 ( struct V_11 * V_12 )
{
unsigned long V_527 = V_339 - V_12 -> V_338 ;
if ( V_12 -> V_336 )
V_12 -> V_528 += V_527 ;
else
V_12 -> V_529 += V_527 ;
V_12 -> V_338 += V_527 ;
}
static void F_290 ( struct V_11 * V_12 , bool V_530 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
if ( ( V_12 -> V_336 || V_12 -> V_337 > 0 ) &&
! ( V_530 && V_12 -> V_337 < 0 ) )
return;
F_179 ( & V_12 -> V_200 ) ;
F_100 ( & V_12 -> V_177 ) ;
F_178 ( & V_12 -> V_200 ) ;
if ( V_12 -> V_336 ) {
if ( V_12 -> V_337 < 0 )
V_12 -> V_337 = 0 ;
return;
}
F_291 ( V_12 ) ;
F_253 ( V_12 ) ;
V_12 -> V_336 = 1 ;
V_12 -> V_338 = V_339 ;
V_12 -> V_337 = 1 ;
F_179 ( & V_12 -> V_200 ) ;
if ( V_12 -> V_181 ) {
V_12 -> V_181 = 0 ;
F_7 ( V_7 , true ) ;
}
F_256 ( V_12 ) ;
F_178 ( & V_12 -> V_200 ) ;
V_12 -> V_337 = 0 ;
}
static void F_292 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_336 || V_12 -> V_525 || V_12 -> V_337 )
return;
if ( V_117 ( V_12 ) ) {
V_12 -> V_337 = - 1 ;
F_96 ( V_12 -> V_7 -> V_90 , & V_12 -> V_177 ,
F_246 ( V_117 ( V_12 ) * 1000 ) ) ;
}
}
void F_293 ( struct V_11 * V_12 , int V_527 , bool V_531 )
{
F_178 ( & V_12 -> V_200 ) ;
V_12 -> V_525 += V_527 ;
F_294 ( V_12 ) ;
if ( V_527 > 0 )
F_290 ( V_12 , V_531 ) ;
else
F_292 ( V_12 ) ;
F_179 ( & V_12 -> V_200 ) ;
}
int F_295 ( struct V_11 * V_12 ,
struct V_532 * V_533 ,
T_2 V_24 )
{
const struct V_534 * V_51 ;
int V_254 , V_535 ;
if ( ! V_533 -> V_536 )
return 0 ;
for ( V_51 = V_533 -> V_536 ; V_51 -> V_24 ; V_51 ++ ) {
if ( V_51 -> V_24 == V_24 )
break;
}
if ( ! V_51 -> V_24 )
return 0 ;
for ( V_51 = V_533 -> V_536 ; V_51 -> V_24 ; V_51 ++ ) {
for ( V_254 = 0 ; V_254 < 2 ; V_254 ++ ) {
V_535 = F_144 ( V_12 , V_51 -> V_24 , V_254 , V_51 -> V_251 ,
V_51 -> V_239 ) ;
if ( ! ( V_535 & V_270 ) && V_535 > 0 ) {
if ( ! V_533 -> V_336 ) {
V_533 -> V_336 = 1 ;
F_16 ( V_12 ) ;
}
return 1 ;
}
}
}
if ( V_533 -> V_336 ) {
V_533 -> V_336 = 0 ;
F_19 ( V_12 ) ;
}
return 0 ;
}
int F_296 ( struct V_11 * V_12 ,
struct V_283 * V_284 ,
const struct V_537 * V_538 ,
int V_539 )
{
V_284 -> type = V_364 ;
V_284 -> V_287 = 1 ;
V_284 -> V_288 . V_365 . V_324 = V_539 ;
if ( V_284 -> V_288 . V_365 . V_318 >= V_539 )
V_284 -> V_288 . V_365 . V_318 = V_539 - 1 ;
sprintf ( V_284 -> V_288 . V_365 . V_134 , L_96 ,
V_538 [ V_284 -> V_288 . V_365 . V_318 ] . V_467 ) ;
return 0 ;
}
int F_297 ( struct V_11 * V_12 ,
struct V_293 * V_294 ,
const struct V_537 * V_538 ,
int V_539 ,
int V_540 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_539 ; V_17 ++ ) {
if ( V_540 == V_538 [ V_17 ] . V_467 ) {
V_294 -> V_288 . V_365 . V_318 [ 0 ] = V_17 ;
break;
}
}
return 0 ;
}
int F_298 ( struct V_11 * V_12 ,
struct V_293 * V_294 ,
const struct V_537 * V_538 ,
int V_539 ,
int * V_541 )
{
unsigned int V_542 ;
V_542 = V_294 -> V_288 . V_365 . V_318 [ 0 ] ;
if ( V_542 >= V_539 )
return - V_61 ;
if ( * V_541 == V_538 [ V_542 ] . V_467 )
return 0 ;
* V_541 = V_538 [ V_542 ] . V_467 ;
if ( V_538 [ V_542 ] . V_543 )
F_242 ( V_12 , V_538 [ V_542 ] . V_543 ) ;
return 1 ;
}
int F_299 ( const struct V_544 * V_545 ,
struct V_283 * V_284 )
{
unsigned int V_255 ;
V_284 -> type = V_364 ;
V_284 -> V_287 = 1 ;
V_284 -> V_288 . V_365 . V_324 = V_545 -> V_546 ;
if ( ! V_545 -> V_546 )
return 0 ;
V_255 = V_284 -> V_288 . V_365 . V_318 ;
if ( V_255 >= V_545 -> V_546 )
V_255 = V_545 -> V_546 - 1 ;
strcpy ( V_284 -> V_288 . V_365 . V_134 , V_545 -> V_324 [ V_255 ] . V_547 ) ;
return 0 ;
}
int F_300 ( struct V_11 * V_12 ,
const struct V_544 * V_545 ,
struct V_293 * V_294 ,
T_2 V_24 ,
unsigned int * V_548 )
{
unsigned int V_239 ;
if ( ! V_545 -> V_546 )
return 0 ;
V_239 = V_294 -> V_288 . V_365 . V_318 [ 0 ] ;
if ( V_239 >= V_545 -> V_546 )
V_239 = V_545 -> V_546 - 1 ;
if ( * V_548 == V_239 )
return 0 ;
F_220 ( V_12 , V_24 , 0 , V_549 ,
V_545 -> V_324 [ V_239 ] . V_255 ) ;
* V_548 = V_239 ;
return 1 ;
}
int F_301 ( struct V_281 * V_282 ,
struct V_283 * V_284 ,
int V_546 , const char * const * V_363 )
{
static const char * const V_550 [] = {
L_97 , L_98
} ;
if ( ! V_363 || ! V_546 ) {
V_546 = 2 ;
V_363 = V_550 ;
}
V_284 -> type = V_364 ;
V_284 -> V_287 = 1 ;
V_284 -> V_288 . V_365 . V_324 = V_546 ;
if ( V_284 -> V_288 . V_365 . V_318 >= V_284 -> V_288 . V_365 . V_324 )
V_284 -> V_288 . V_365 . V_318 = V_284 -> V_288 . V_365 . V_324 - 1 ;
strcpy ( V_284 -> V_288 . V_365 . V_134 ,
V_363 [ V_284 -> V_288 . V_365 . V_318 ] ) ;
return 0 ;
}
static void F_302 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_217 , unsigned int V_223 )
{
struct V_196 * V_393 ;
unsigned int V_551 ;
bool V_552 ;
V_393 = F_227 ( V_12 , V_24 ) ;
V_551 = F_23 ( V_12 , V_24 , 0 ,
V_225 , 0 ) ;
V_552 = V_12 -> V_344 &&
( V_393 -> V_407 & V_408 ) &&
V_551 != V_223 ;
if ( V_552 )
F_221 ( V_12 , V_24 ,
V_393 -> V_407 & ~ V_408 & 0xff ,
- 1 ) ;
F_122 ( V_12 , V_24 , V_217 , 0 , V_223 ) ;
if ( V_12 -> V_343 ) {
const T_2 * V_402 ;
for ( V_402 = V_12 -> V_343 ; * V_402 ; V_402 ++ )
F_122 ( V_12 , * V_402 , V_217 , 0 ,
V_223 ) ;
}
if ( V_552 )
F_221 ( V_12 , V_24 ,
V_393 -> V_407 & 0xff , - 1 ) ;
}
static void F_303 ( struct V_11 * V_12 , T_2 V_24 )
{
F_275 ( V_12 , V_24 ) ;
if ( V_12 -> V_343 ) {
const T_2 * V_402 ;
for ( V_402 = V_12 -> V_343 ; * V_402 ; V_402 ++ )
F_275 ( V_12 , * V_402 ) ;
}
}
void F_304 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
if ( ! V_7 )
return;
F_29 (codec, &bus->codec_list, list) {
if ( F_305 ( V_12 ) &&
V_12 -> V_98 . V_553 )
V_12 -> V_98 . V_553 ( V_12 ) ;
}
}
int F_306 ( struct V_11 * V_12 ,
struct V_420 * V_421 )
{
F_2 ( & V_12 -> V_190 ) ;
if ( V_421 -> V_554 == V_555 )
F_303 ( V_12 , V_421 -> V_423 ) ;
V_421 -> V_554 = V_556 ;
F_4 ( & V_12 -> V_190 ) ;
return 0 ;
}
int F_307 ( struct V_11 * V_12 ,
struct V_420 * V_421 ,
unsigned int V_217 ,
unsigned int V_223 ,
struct V_503 * V_504 )
{
F_2 ( & V_12 -> V_190 ) ;
F_302 ( V_12 , V_421 -> V_423 , V_217 , V_223 ) ;
F_4 ( & V_12 -> V_190 ) ;
return 0 ;
}
int F_308 ( struct V_11 * V_12 ,
struct V_420 * V_421 )
{
F_2 ( & V_12 -> V_190 ) ;
F_303 ( V_12 , V_421 -> V_423 ) ;
F_4 ( & V_12 -> V_190 ) ;
return 0 ;
}
int F_309 ( struct V_11 * V_12 ,
struct V_420 * V_421 )
{
F_2 ( & V_12 -> V_190 ) ;
V_421 -> V_554 = 0 ;
F_4 ( & V_12 -> V_190 ) ;
return 0 ;
}
int F_310 ( struct V_11 * V_12 ,
struct V_420 * V_421 ,
struct V_503 * V_504 ,
struct V_452 * V_453 )
{
struct V_557 * V_558 = V_504 -> V_558 ;
V_558 -> V_559 . V_462 = V_421 -> V_540 ;
if ( V_421 -> V_423 ) {
if ( ! V_421 -> V_560 ) {
V_421 -> V_560 = V_453 -> V_486 ;
V_421 -> V_561 = V_453 -> V_489 ;
V_421 -> V_562 = V_453 -> V_468 ;
} else {
V_558 -> V_559 . V_486 = V_421 -> V_560 ;
V_558 -> V_559 . V_489 = V_421 -> V_561 ;
V_453 -> V_468 = V_421 -> V_562 ;
}
if ( ! V_421 -> V_563 ) {
F_270 ( V_12 , V_421 -> V_423 ,
& V_421 -> V_563 ,
& V_421 -> V_564 ,
& V_421 -> V_565 ) ;
}
F_2 ( & V_12 -> V_190 ) ;
if ( V_421 -> V_422 ) {
if ( ( V_558 -> V_559 . V_486 & V_421 -> V_563 ) &&
( V_558 -> V_559 . V_489 & V_421 -> V_564 ) ) {
V_558 -> V_559 . V_486 &= V_421 -> V_563 ;
V_558 -> V_559 . V_489 &= V_421 -> V_564 ;
if ( V_421 -> V_565 < V_453 -> V_468 )
V_453 -> V_468 = V_421 -> V_565 ;
} else {
V_421 -> V_422 = 0 ;
}
}
F_4 ( & V_12 -> V_190 ) ;
}
return F_311 ( V_504 -> V_558 , 0 ,
V_566 , 2 ) ;
}
int F_312 ( struct V_11 * V_12 ,
struct V_420 * V_421 ,
unsigned int V_217 ,
unsigned int V_223 ,
struct V_503 * V_504 )
{
const T_2 * V_179 = V_421 -> V_567 ;
int V_285 = V_504 -> V_558 -> V_467 ;
struct V_196 * V_393 ;
int V_17 ;
F_2 ( & V_12 -> V_190 ) ;
V_393 = F_227 ( V_12 , V_421 -> V_423 ) ;
if ( V_421 -> V_423 && V_421 -> V_422 &&
V_421 -> V_554 != V_556 ) {
if ( V_285 == 2 &&
F_271 ( V_12 , V_421 -> V_423 ,
V_223 ) &&
! ( V_393 -> V_385 & V_387 ) ) {
V_421 -> V_554 = V_555 ;
F_302 ( V_12 , V_421 -> V_423 ,
V_217 , V_223 ) ;
} else {
V_421 -> V_554 = 0 ;
F_303 ( V_12 , V_421 -> V_423 ) ;
}
}
F_4 ( & V_12 -> V_190 ) ;
F_122 ( V_12 , V_179 [ V_568 ] , V_217 ,
0 , V_223 ) ;
if ( ! V_421 -> V_569 &&
V_421 -> V_570 && V_421 -> V_570 != V_179 [ V_568 ] )
F_122 ( V_12 , V_421 -> V_570 , V_217 ,
0 , V_223 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_421 -> V_571 ) ; V_17 ++ )
if ( ! V_421 -> V_569 && V_421 -> V_571 [ V_17 ] )
F_122 ( V_12 ,
V_421 -> V_571 [ V_17 ] ,
V_217 , 0 , V_223 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_421 -> V_572 ) ; V_17 ++ )
if ( ! V_421 -> V_569 && V_421 -> V_572 [ V_17 ] )
F_122 ( V_12 ,
V_421 -> V_572 [ V_17 ] ,
V_217 , 0 , V_223 ) ;
for ( V_17 = 1 ; V_17 < V_421 -> V_573 ; V_17 ++ ) {
if ( V_285 >= ( V_17 + 1 ) * 2 )
F_122 ( V_12 , V_179 [ V_17 ] , V_217 ,
V_17 * 2 , V_223 ) ;
else if ( ! V_421 -> V_569 )
F_122 ( V_12 , V_179 [ V_17 ] , V_217 ,
0 , V_223 ) ;
}
return 0 ;
}
int F_313 ( struct V_11 * V_12 ,
struct V_420 * V_421 )
{
const T_2 * V_179 = V_421 -> V_567 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_421 -> V_573 ; V_17 ++ )
F_275 ( V_12 , V_179 [ V_17 ] ) ;
if ( V_421 -> V_570 )
F_275 ( V_12 , V_421 -> V_570 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_421 -> V_571 ) ; V_17 ++ )
if ( V_421 -> V_571 [ V_17 ] )
F_275 ( V_12 ,
V_421 -> V_571 [ V_17 ] ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_421 -> V_572 ) ; V_17 ++ )
if ( V_421 -> V_572 [ V_17 ] )
F_275 ( V_12 ,
V_421 -> V_572 [ V_17 ] ) ;
F_2 ( & V_12 -> V_190 ) ;
if ( V_421 -> V_423 && V_421 -> V_554 == V_555 ) {
F_303 ( V_12 , V_421 -> V_423 ) ;
V_421 -> V_554 = 0 ;
}
F_4 ( & V_12 -> V_190 ) ;
return 0 ;
}
unsigned int F_314 ( struct V_11 * V_12 , T_2 V_158 )
{
unsigned int V_574 ;
unsigned int V_219 ;
V_219 = F_23 ( V_12 , V_158 , 0 ,
V_163 , 0 ) ;
V_574 = F_138 ( V_12 , V_158 ) ;
V_574 = ( V_574 & V_575 ) >> V_576 ;
if ( ( V_574 & V_577 ) && V_219 != V_578 )
return V_579 ;
else if ( V_574 & V_580 )
return V_581 ;
else if ( V_574 & V_582 )
return V_583 ;
else if ( V_574 & V_584 )
return V_585 ;
return V_586 ;
}
unsigned int F_315 ( struct V_11 * V_12 ,
T_2 V_158 , unsigned int V_28 )
{
static unsigned int V_587 [] [ 2 ] = {
{ V_583 , V_582 } ,
{ V_579 , V_577 } ,
{ V_581 , V_580 } ,
{ V_585 , V_584 } ,
} ;
unsigned int V_588 ;
if ( ! V_28 )
return 0 ;
V_588 = F_138 ( V_12 , V_158 ) ;
if ( ! V_588 )
return V_28 ;
if ( V_28 & V_589 ) {
if ( ! ( V_588 & V_590 ) )
V_28 &= ~ ( V_589 | V_591 ) ;
else if ( ( V_28 & V_591 ) && ! ( V_588 & V_592 ) )
V_28 &= ~ V_591 ;
}
if ( V_28 & V_593 ) {
if ( ! ( V_588 & V_594 ) )
V_28 &= ~ ( V_593 | V_595 ) ;
else {
unsigned int V_596 , V_597 ;
int V_17 ;
V_596 = ( V_588 & V_575 ) >> V_576 ;
V_597 = V_28 & V_595 ;
for ( V_17 = 0 ; V_17 < F_10 ( V_587 ) ; V_17 ++ ) {
if ( V_597 == V_587 [ V_17 ] [ 0 ] &&
! ( V_596 & V_587 [ V_17 ] [ 1 ] ) ) {
if ( V_17 == F_10 ( V_587 ) - 1 )
V_597 = V_586 ;
else
V_597 = V_587 [ V_17 + 1 ] [ 0 ] ;
}
}
V_28 &= ~ V_595 ;
V_28 |= V_597 ;
}
}
return V_28 ;
}
int F_316 ( struct V_11 * V_12 , T_2 V_158 ,
unsigned int V_28 , bool V_598 )
{
V_28 = F_315 ( V_12 , V_158 , V_28 ) ;
F_89 ( V_12 , V_158 , V_28 ) ;
if ( V_598 )
return F_238 ( V_12 , V_158 , 0 ,
V_171 , V_28 ) ;
else
return F_24 ( V_12 , V_158 , 0 ,
V_171 , V_28 ) ;
}
int F_317 ( struct V_544 * V_545 , const char * V_547 ,
int V_255 , int * V_599 )
{
int V_17 , V_600 = 0 ;
if ( V_545 -> V_546 >= V_601 ) {
F_21 ( V_30 L_99 ) ;
return - V_61 ;
}
for ( V_17 = 0 ; V_17 < V_545 -> V_546 ; V_17 ++ ) {
if ( ! strncmp ( V_547 , V_545 -> V_324 [ V_17 ] . V_547 , strlen ( V_547 ) ) )
V_600 ++ ;
}
if ( V_599 )
* V_599 = V_600 ;
if ( V_600 > 0 )
snprintf ( V_545 -> V_324 [ V_545 -> V_546 ] . V_547 ,
sizeof( V_545 -> V_324 [ V_545 -> V_546 ] . V_547 ) ,
L_100 , V_547 , V_600 ) ;
else
F_318 ( V_545 -> V_324 [ V_545 -> V_546 ] . V_547 , V_547 ,
sizeof( V_545 -> V_324 [ V_545 -> V_546 ] . V_547 ) ) ;
V_545 -> V_324 [ V_545 -> V_546 ] . V_255 = V_255 ;
V_545 -> V_546 ++ ;
return 0 ;
}
int F_319 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
F_100 ( & V_12 -> V_173 ) ;
if ( F_305 ( V_12 ) )
F_252 ( V_12 , false ) ;
}
return 0 ;
}
int F_320 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
F_256 ( V_12 ) ;
}
return 0 ;
}
void * F_82 ( struct V_164 * V_165 )
{
if ( F_43 ( ! V_165 -> V_602 ) )
return NULL ;
if ( V_165 -> V_166 >= V_165 -> V_603 ) {
int V_604 = V_165 -> V_603 + V_165 -> V_605 ;
int V_298 = ( V_604 + 1 ) * V_165 -> V_602 ;
void * V_606 ;
if ( F_43 ( V_604 >= 4096 ) )
return NULL ;
V_606 = F_321 ( V_165 -> V_4 , V_298 , V_53 | V_607 ) ;
if ( ! V_606 )
return NULL ;
V_165 -> V_4 = V_606 ;
V_165 -> V_603 = V_604 ;
}
return F_84 ( V_165 , V_165 -> V_166 ++ ) ;
}
void F_98 ( struct V_164 * V_165 )
{
F_37 ( V_165 -> V_4 ) ;
V_165 -> V_166 = 0 ;
V_165 -> V_603 = 0 ;
V_165 -> V_4 = NULL ;
}
void F_322 ( int V_329 , char * V_237 , int V_608 )
{
static unsigned int V_609 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_17 , V_610 ;
for ( V_17 = 0 , V_610 = 0 ; V_17 < F_10 ( V_609 ) ; V_17 ++ )
if ( V_329 & ( V_492 << V_17 ) )
V_610 += snprintf ( V_237 + V_610 , V_608 - V_610 , L_101 , V_609 [ V_17 ] ) ;
V_237 [ V_610 ] = '\0' ;
}
