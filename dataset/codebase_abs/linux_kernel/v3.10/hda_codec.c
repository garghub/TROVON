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
for (; ; ) {
F_17 ( V_12 , V_31 ) ;
V_33 = V_7 -> V_9 . V_36 ( V_7 , V_31 ) ;
if ( V_33 != - V_37 )
break;
V_7 -> V_9 . V_38 ( V_7 , V_12 -> V_29 ) ;
}
if ( ! V_33 && V_32 ) {
* V_32 = V_7 -> V_9 . V_38 ( V_7 , V_12 -> V_29 ) ;
F_18 ( V_12 , * V_32 ) ;
}
F_4 ( & V_7 -> V_35 ) ;
F_19 ( V_12 ) ;
if ( ! F_20 ( V_12 ) && V_32 && * V_32 == - 1 && V_7 -> V_39 ) {
if ( V_7 -> V_40 ) {
F_21 ( L_37
L_38 ) ;
F_22 ( V_7 ) ;
V_7 -> V_9 . V_41 ( V_7 ) ;
}
goto V_34;
}
if ( ! V_33 || F_20 ( V_12 ) )
V_7 -> V_40 = 0 ;
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
V_12 -> V_7 -> V_42 ? & V_32 : NULL ) ;
}
void F_25 ( struct V_11 * V_12 , const struct V_43 * V_44 )
{
for (; V_44 -> V_24 ; V_44 ++ )
F_24 ( V_12 , V_44 -> V_24 , 0 , V_44 -> V_26 , V_44 -> V_45 ) ;
}
int F_26 ( struct V_11 * V_12 , T_2 V_24 ,
T_2 * V_46 )
{
unsigned int V_27 ;
V_27 = F_27 ( V_12 , V_24 , V_47 ) ;
if ( V_27 == - 1 )
return 0 ;
* V_46 = ( V_27 >> 16 ) & 0x7fff ;
return ( int ) ( V_27 & 0x7fff ) ;
}
static struct V_48 *
F_28 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_48 * V_49 ;
F_29 (p, &codec->conn_list, list) {
if ( V_49 -> V_24 == V_24 )
return V_49 ;
}
return NULL ;
}
static int F_30 ( struct V_11 * V_12 , T_2 V_24 , int V_50 ,
const T_2 * V_4 )
{
struct V_48 * V_49 ;
V_49 = F_31 ( sizeof( * V_49 ) + V_50 * sizeof( T_2 ) , V_51 ) ;
if ( ! V_49 )
return - V_52 ;
V_49 -> V_50 = V_50 ;
V_49 -> V_24 = V_24 ;
memcpy ( V_49 -> V_53 , V_4 , V_50 * sizeof( T_2 ) ) ;
F_32 ( & V_49 -> V_4 , & V_12 -> V_54 ) ;
return 0 ;
}
static void F_33 ( struct V_11 * V_12 )
{
while ( ! F_34 ( & V_12 -> V_54 ) ) {
struct V_48 * V_49 ;
V_49 = F_35 ( & V_12 -> V_54 , F_36 ( * V_49 ) , V_4 ) ;
F_6 ( & V_49 -> V_4 ) ;
F_37 ( V_49 ) ;
}
}
static int F_38 ( struct V_11 * V_12 , T_2 V_24 )
{
T_2 V_4 [ 32 ] ;
T_2 * V_55 = V_4 ;
int V_50 ;
V_50 = F_39 ( V_12 , V_24 , V_4 , F_10 ( V_4 ) ) ;
if ( V_50 == - V_56 ) {
V_50 = F_40 ( V_12 , V_24 ) ;
V_55 = F_31 ( sizeof( T_2 ) * V_50 , V_51 ) ;
if ( ! V_55 )
return - V_52 ;
V_50 = F_39 ( V_12 , V_24 , V_55 , V_50 ) ;
}
if ( V_50 >= 0 )
V_50 = F_41 ( V_12 , V_24 , V_50 , V_55 ) ;
if ( V_55 != V_4 )
F_37 ( V_55 ) ;
return V_50 ;
}
int F_42 ( struct V_11 * V_12 , T_2 V_24 ,
const T_2 * * V_57 )
{
bool V_58 = false ;
for (; ; ) {
int V_33 ;
const struct V_48 * V_49 ;
V_49 = F_28 ( V_12 , V_24 ) ;
if ( V_49 ) {
if ( V_57 )
* V_57 = V_49 -> V_53 ;
return V_49 -> V_50 ;
}
if ( F_43 ( V_58 ) )
return - V_59 ;
V_33 = F_38 ( V_12 , V_24 ) ;
if ( V_33 < 0 )
return V_33 ;
V_58 = true ;
}
}
int F_44 ( struct V_11 * V_12 , T_2 V_24 ,
T_2 * V_54 , int V_60 )
{
const T_2 * V_4 ;
int V_50 = F_42 ( V_12 , V_24 , & V_4 ) ;
if ( V_50 > 0 && V_54 ) {
if ( V_50 > V_60 ) {
F_45 ( V_30 L_39
L_40 ,
V_50 , V_24 ) ;
return - V_59 ;
}
memcpy ( V_54 , V_4 , V_50 * sizeof( T_2 ) ) ;
}
return V_50 ;
}
static unsigned int F_46 ( struct V_11 * V_12 , T_2 V_24 )
{
unsigned int V_61 = F_47 ( V_12 , V_24 ) ;
unsigned int V_27 ;
if ( ! ( V_61 & V_62 ) &&
F_48 ( V_61 ) != V_63 )
return 0 ;
V_27 = F_27 ( V_12 , V_24 , V_64 ) ;
if ( V_27 == - 1 )
V_27 = 0 ;
return V_27 ;
}
int F_40 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_39 ( V_12 , V_24 , NULL , 0 ) ;
}
int F_39 ( struct V_11 * V_12 , T_2 V_24 ,
T_2 * V_54 , int V_60 )
{
unsigned int V_27 ;
int V_17 , V_65 , V_53 ;
unsigned int V_66 , V_67 , V_68 ;
T_2 V_69 ;
int V_70 = 0 ;
V_27 = F_46 ( V_12 , V_24 ) ;
if ( ! V_27 )
return 0 ;
if ( V_27 & V_71 ) {
V_66 = 16 ;
V_67 = 2 ;
} else {
V_66 = 8 ;
V_67 = 4 ;
}
V_65 = V_27 & V_72 ;
V_68 = ( 1 << ( V_66 - 1 ) ) - 1 ;
if ( ! V_65 )
return 0 ;
if ( V_65 == 1 ) {
V_27 = F_23 ( V_12 , V_24 , 0 ,
V_73 , 0 ) ;
if ( V_27 == - 1 && V_12 -> V_7 -> V_39 )
return - V_74 ;
if ( V_54 )
V_54 [ 0 ] = V_27 & V_68 ;
return 1 ;
}
V_53 = 0 ;
V_69 = 0 ;
for ( V_17 = 0 ; V_17 < V_65 ; V_17 ++ ) {
int V_75 ;
T_2 V_28 , V_76 ;
if ( V_17 % V_67 == 0 ) {
V_27 = F_23 ( V_12 , V_24 , 0 ,
V_73 , V_17 ) ;
if ( V_27 == - 1 && V_12 -> V_7 -> V_39 )
return - V_74 ;
}
V_75 = ! ! ( V_27 & ( 1 << ( V_66 - 1 ) ) ) ;
V_28 = V_27 & V_68 ;
if ( V_28 == 0 && V_70 ++ ) {
F_45 ( V_77 L_39
L_41 ,
V_24 , V_17 , V_27 ) ;
return 0 ;
}
V_27 >>= V_66 ;
if ( V_75 ) {
if ( ! V_69 || V_69 >= V_28 ) {
F_45 ( V_77 L_39
L_42 ,
V_69 , V_28 ) ;
continue;
}
for ( V_76 = V_69 + 1 ; V_76 <= V_28 ; V_76 ++ ) {
if ( V_54 ) {
if ( V_53 >= V_60 )
return - V_56 ;
V_54 [ V_53 ] = V_76 ;
}
V_53 ++ ;
}
} else {
if ( V_54 ) {
if ( V_53 >= V_60 )
return - V_56 ;
V_54 [ V_53 ] = V_28 ;
}
V_53 ++ ;
}
V_69 = V_28 ;
}
return V_53 ;
}
int F_41 ( struct V_11 * V_12 , T_2 V_24 , int V_50 ,
const T_2 * V_4 )
{
struct V_48 * V_49 ;
V_49 = F_28 ( V_12 , V_24 ) ;
if ( V_49 ) {
F_6 ( & V_49 -> V_4 ) ;
F_37 ( V_49 ) ;
}
return F_30 ( V_12 , V_24 , V_50 , V_4 ) ;
}
int F_49 ( struct V_11 * V_12 , T_2 V_78 ,
T_2 V_24 , int V_79 )
{
const T_2 * V_80 ;
int V_17 , V_81 ;
V_81 = F_42 ( V_12 , V_78 , & V_80 ) ;
for ( V_17 = 0 ; V_17 < V_81 ; V_17 ++ )
if ( V_80 [ V_17 ] == V_24 )
return V_17 ;
if ( ! V_79 )
return - 1 ;
if ( V_79 > 10 ) {
F_21 ( L_43 , V_24 ) ;
return - 1 ;
}
V_79 ++ ;
for ( V_17 = 0 ; V_17 < V_81 ; V_17 ++ ) {
unsigned int type = F_48 ( F_47 ( V_12 , V_80 [ V_17 ] ) ) ;
if ( type == V_82 || type == V_83 )
continue;
if ( F_49 ( V_12 , V_80 [ V_17 ] , V_24 , V_79 ) >= 0 )
return V_17 ;
}
return - 1 ;
}
int F_50 ( struct V_6 * V_7 , T_1 V_32 , T_1 V_84 )
{
struct V_85 * V_86 ;
unsigned int V_87 ;
if ( ! V_7 || ! V_7 -> V_88 )
return 0 ;
F_51 ( V_7 , V_32 , V_84 ) ;
V_86 = V_7 -> V_86 ;
if ( ! V_86 )
return 0 ;
V_87 = ( V_86 -> V_87 + 1 ) % V_89 ;
V_86 -> V_87 = V_87 ;
V_87 <<= 1 ;
V_86 -> V_90 [ V_87 ] = V_32 ;
V_86 -> V_90 [ V_87 + 1 ] = V_84 ;
F_52 ( V_7 -> V_88 , & V_86 -> V_91 ) ;
return 0 ;
}
static void F_53 ( struct V_92 * V_91 )
{
struct V_85 * V_86 =
F_54 ( V_91 , struct V_85 , V_91 ) ;
struct V_6 * V_7 = V_86 -> V_7 ;
struct V_11 * V_12 ;
unsigned int V_93 , V_94 , V_32 ;
while ( V_86 -> V_93 != V_86 -> V_87 ) {
V_93 = ( V_86 -> V_93 + 1 ) % V_89 ;
V_86 -> V_93 = V_93 ;
V_93 <<= 1 ;
V_32 = V_86 -> V_90 [ V_93 ] ;
V_94 = V_86 -> V_90 [ V_93 + 1 ] ;
if ( ! ( V_94 & ( 1 << 4 ) ) )
continue;
V_12 = V_7 -> V_95 [ V_94 & 0x0f ] ;
if ( V_12 && V_12 -> V_96 . V_97 )
V_12 -> V_96 . V_97 ( V_12 , V_32 ) ;
}
}
static int F_55 ( struct V_6 * V_7 )
{
struct V_85 * V_86 ;
if ( V_7 -> V_86 )
return 0 ;
V_86 = F_56 ( sizeof( * V_86 ) , V_51 ) ;
if ( ! V_86 ) {
F_45 ( V_30 L_39
L_44 ) ;
return - V_52 ;
}
F_57 ( & V_86 -> V_91 , F_53 ) ;
V_86 -> V_7 = V_7 ;
V_7 -> V_86 = V_86 ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 )
{
struct V_11 * V_12 , * V_76 ;
if ( ! V_7 )
return 0 ;
if ( V_7 -> V_88 )
F_59 ( V_7 -> V_88 ) ;
if ( V_7 -> V_86 )
F_37 ( V_7 -> V_86 ) ;
F_60 (codec, n, &bus->codec_list, list) {
F_61 ( V_12 ) ;
}
if ( V_7 -> V_9 . V_98 )
V_7 -> V_9 . V_98 ( V_7 ) ;
if ( V_7 -> V_88 )
F_62 ( V_7 -> V_88 ) ;
F_37 ( V_7 ) ;
return 0 ;
}
static int F_63 ( struct V_99 * V_100 )
{
struct V_6 * V_7 = V_100 -> V_101 ;
V_7 -> V_102 = 1 ;
return F_58 ( V_7 ) ;
}
static int F_64 ( struct V_99 * V_100 )
{
struct V_6 * V_7 = V_100 -> V_101 ;
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
F_65 ( V_12 ) ;
F_66 ( V_12 ) ;
}
return 0 ;
}
int F_67 ( struct V_103 * V_104 ,
const struct V_105 * V_106 ,
struct V_6 * * V_107 )
{
struct V_6 * V_7 ;
int V_33 ;
static struct V_108 V_109 = {
. V_110 = F_64 ,
. V_111 = F_63 ,
} ;
if ( F_43 ( ! V_106 ) )
return - V_59 ;
if ( F_43 ( ! V_106 -> V_9 . V_36 || ! V_106 -> V_9 . V_38 ) )
return - V_59 ;
if ( V_107 )
* V_107 = NULL ;
V_7 = F_56 ( sizeof( * V_7 ) , V_51 ) ;
if ( V_7 == NULL ) {
F_45 ( V_30 L_45 ) ;
return - V_52 ;
}
V_7 -> V_104 = V_104 ;
V_7 -> V_112 = V_106 -> V_112 ;
V_7 -> V_113 = V_106 -> V_113 ;
V_7 -> V_114 = V_106 -> V_114 ;
V_7 -> V_115 = V_106 -> V_115 ;
V_7 -> V_9 = V_106 -> V_9 ;
F_68 ( & V_7 -> V_35 ) ;
F_68 ( & V_7 -> V_116 ) ;
F_69 ( & V_7 -> V_117 ) ;
snprintf ( V_7 -> V_118 , sizeof( V_7 -> V_118 ) ,
L_46 , V_104 -> V_119 ) ;
V_7 -> V_88 = F_70 ( V_7 -> V_118 ) ;
if ( ! V_7 -> V_88 ) {
F_45 ( V_30 L_47 ,
V_7 -> V_118 ) ;
F_37 ( V_7 ) ;
return - V_52 ;
}
V_33 = F_71 ( V_104 , V_120 , V_7 , & V_109 ) ;
if ( V_33 < 0 ) {
F_58 ( V_7 ) ;
return V_33 ;
}
if ( V_107 )
* V_107 = V_7 ;
return 0 ;
}
static const struct V_121 *
F_72 ( struct V_11 * V_12 )
{
struct V_1 * V_122 ;
const struct V_121 * V_2 ;
unsigned int V_123 = 0 ;
if ( F_73 ( V_12 ) )
return NULL ;
V_34:
F_2 ( & V_3 ) ;
F_29 (tbl, &hda_preset_tables, list) {
if ( ! F_74 ( V_122 -> V_124 ) ) {
F_45 ( V_30 L_48 ) ;
continue;
}
for ( V_2 = V_122 -> V_2 ; V_2 -> V_125 ; V_2 ++ ) {
T_1 V_68 = V_2 -> V_68 ;
if ( V_2 -> V_126 && V_2 -> V_126 != V_12 -> V_126 )
continue;
if ( V_2 -> V_127 && V_2 -> V_127 != V_12 -> V_127 )
continue;
if ( ! V_68 )
V_68 = ~ 0 ;
if ( V_2 -> V_125 == ( V_12 -> V_128 & V_68 ) &&
( ! V_2 -> V_129 ||
V_2 -> V_129 == V_12 -> V_130 ) ) {
F_4 ( & V_3 ) ;
V_12 -> V_124 = V_122 -> V_124 ;
return V_2 ;
}
}
F_75 ( V_122 -> V_124 ) ;
}
F_4 ( & V_3 ) ;
if ( V_123 < V_131 ) {
char V_132 [ 32 ] ;
if ( ! V_123 )
snprintf ( V_132 , sizeof( V_132 ) , L_49 ,
V_12 -> V_128 ) ;
else
snprintf ( V_132 , sizeof( V_132 ) , L_50 ,
( V_12 -> V_128 >> 16 ) & 0xffff ) ;
F_76 ( V_132 ) ;
V_123 ++ ;
goto V_34;
}
return NULL ;
}
static int F_77 ( struct V_11 * V_12 )
{
const struct V_133 * V_134 ;
const char * V_135 = NULL ;
T_3 V_128 = V_12 -> V_128 >> 16 ;
char V_136 [ 16 ] ;
if ( V_12 -> V_137 )
goto V_138;
for ( V_134 = V_139 ; V_134 -> V_125 ; V_134 ++ ) {
if ( V_134 -> V_125 == V_128 ) {
V_135 = V_134 -> V_132 ;
break;
}
}
if ( ! V_135 ) {
sprintf ( V_136 , L_51 , V_128 ) ;
V_135 = V_136 ;
}
V_12 -> V_137 = F_78 ( V_135 , V_51 ) ;
if ( ! V_12 -> V_137 )
return - V_52 ;
V_138:
if ( V_12 -> V_140 )
return 0 ;
if ( V_12 -> V_2 && V_12 -> V_2 -> V_132 )
V_12 -> V_140 = F_78 ( V_12 -> V_2 -> V_132 , V_51 ) ;
else {
sprintf ( V_136 , L_52 , V_12 -> V_128 & 0xffff ) ;
V_12 -> V_140 = F_78 ( V_136 , V_51 ) ;
}
if ( ! V_12 -> V_140 )
return - V_52 ;
return 0 ;
}
static void F_79 ( struct V_11 * V_12 )
{
int V_17 , V_141 , V_142 ;
T_2 V_24 ;
V_141 = F_26 ( V_12 , V_143 , & V_24 ) ;
for ( V_17 = 0 ; V_17 < V_141 ; V_17 ++ , V_24 ++ ) {
V_142 = F_27 ( V_12 , V_24 ,
V_144 ) ;
switch ( V_142 & 0xff ) {
case V_145 :
V_12 -> V_126 = V_24 ;
V_12 -> V_146 = V_142 & 0xff ;
V_12 -> V_147 = ( V_142 >> 8 ) & 1 ;
break;
case V_148 :
V_12 -> V_127 = V_24 ;
V_12 -> V_149 = V_142 & 0xff ;
V_12 -> V_150 = ( V_142 >> 8 ) & 1 ;
break;
default:
break;
}
}
}
static int F_80 ( struct V_11 * V_12 , T_2 V_151 )
{
int V_17 ;
T_2 V_24 ;
V_12 -> V_152 = F_26 ( V_12 , V_151 ,
& V_12 -> V_153 ) ;
V_12 -> V_61 = F_31 ( V_12 -> V_152 * 4 , V_51 ) ;
if ( ! V_12 -> V_61 )
return - V_52 ;
V_24 = V_12 -> V_153 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_152 ; V_17 ++ , V_24 ++ )
V_12 -> V_61 [ V_17 ] = F_27 ( V_12 , V_24 ,
V_154 ) ;
return 0 ;
}
static int F_81 ( struct V_11 * V_12 )
{
int V_17 ;
T_2 V_24 = V_12 -> V_153 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_152 ; V_17 ++ , V_24 ++ ) {
struct V_155 * V_156 ;
unsigned int V_61 = F_47 ( V_12 , V_24 ) ;
unsigned int V_157 = F_48 ( V_61 ) ;
if ( V_157 != V_82 )
continue;
V_156 = F_82 ( & V_12 -> V_158 ) ;
if ( ! V_156 )
return - V_52 ;
V_156 -> V_24 = V_24 ;
V_156 -> V_13 = F_23 ( V_12 , V_24 , 0 ,
V_159 , 0 ) ;
V_156 -> V_160 = F_23 ( V_12 , V_24 , 0 ,
V_161 ,
0 ) ;
}
return 0 ;
}
static struct V_155 * F_83 ( struct V_11 * V_12 ,
struct V_162 * V_163 ,
T_2 V_24 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_163 -> V_164 ; V_17 ++ ) {
struct V_155 * V_156 = F_84 ( V_163 , V_17 ) ;
if ( V_156 -> V_24 == V_24 )
return V_156 ;
}
return NULL ;
}
int F_85 ( struct V_11 * V_12 , struct V_162 * V_4 ,
T_2 V_24 , unsigned int V_13 )
{
struct V_155 * V_156 ;
V_156 = F_83 ( V_12 , V_4 , V_24 ) ;
if ( ! V_156 ) {
V_156 = F_82 ( V_4 ) ;
if ( ! V_156 )
return - V_52 ;
V_156 -> V_24 = V_24 ;
}
V_156 -> V_13 = V_13 ;
return 0 ;
}
int F_86 ( struct V_11 * V_12 ,
T_2 V_24 , unsigned int V_13 )
{
return F_85 ( V_12 , & V_12 -> V_165 , V_24 , V_13 ) ;
}
unsigned int F_87 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_155 * V_156 ;
#ifdef F_88
{
unsigned int V_13 = 0 ;
F_2 ( & V_12 -> V_166 ) ;
V_156 = F_83 ( V_12 , & V_12 -> V_167 , V_24 ) ;
if ( V_156 )
V_13 = V_156 -> V_13 ;
F_4 ( & V_12 -> V_166 ) ;
if ( V_13 )
return V_13 ;
}
#endif
V_156 = F_83 ( V_12 , & V_12 -> V_165 , V_24 ) ;
if ( V_156 )
return V_156 -> V_13 ;
V_156 = F_83 ( V_12 , & V_12 -> V_158 , V_24 ) ;
if ( V_156 )
return V_156 -> V_13 ;
return 0 ;
}
int F_89 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_28 )
{
struct V_155 * V_156 ;
V_156 = F_83 ( V_12 , & V_12 -> V_158 , V_24 ) ;
if ( ! V_156 )
return - V_59 ;
V_156 -> V_168 = V_28 ;
return 0 ;
}
int F_90 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_155 * V_156 ;
V_156 = F_83 ( V_12 , & V_12 -> V_158 , V_24 ) ;
if ( ! V_156 )
return 0 ;
return V_156 -> V_168 ;
}
void F_91 ( struct V_11 * V_12 )
{
int V_17 ;
if ( V_12 -> V_7 -> V_102 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_158 . V_164 ; V_17 ++ ) {
struct V_155 * V_156 = F_84 ( & V_12 -> V_158 , V_17 ) ;
F_23 ( V_12 , V_156 -> V_24 , 0 ,
V_169 , 0 ) ;
}
V_12 -> V_170 = 1 ;
}
static void F_92 ( struct V_11 * V_12 )
{
int V_17 ;
if ( ! V_12 -> V_170 )
return;
if ( V_12 -> V_7 -> V_102 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_158 . V_164 ; V_17 ++ ) {
struct V_155 * V_156 = F_84 ( & V_12 -> V_158 , V_17 ) ;
F_24 ( V_12 , V_156 -> V_24 , 0 ,
V_169 ,
V_156 -> V_160 ) ;
}
V_12 -> V_170 = 0 ;
}
static void F_93 ( struct V_92 * V_91 )
{
struct V_11 * V_12 =
F_54 ( V_91 , struct V_11 , V_171 . V_91 ) ;
if ( ! V_12 -> V_172 )
return;
F_94 ( V_12 ) ;
F_95 ( V_12 ) ;
F_96 ( V_12 -> V_7 -> V_88 , & V_12 -> V_171 ,
V_12 -> V_172 ) ;
}
static void F_97 ( struct V_11 * V_12 )
{
F_98 ( & V_12 -> V_165 ) ;
#ifdef F_88
F_98 ( & V_12 -> V_167 ) ;
#endif
F_98 ( & V_12 -> V_158 ) ;
}
static struct V_173 *
F_99 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_173 * V_49 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_174 . V_164 ; V_17 ++ ) {
V_49 = F_84 ( & V_12 -> V_174 , V_17 ) ;
if ( V_49 -> V_24 == V_24 )
return V_49 ;
}
V_49 = F_82 ( & V_12 -> V_174 ) ;
if ( V_49 )
V_49 -> V_24 = V_24 ;
return V_49 ;
}
static void F_61 ( struct V_11 * V_12 )
{
if ( ! V_12 )
return;
F_100 ( & V_12 -> V_171 ) ;
F_101 ( V_12 ) ;
F_97 ( V_12 ) ;
#ifdef F_102
F_103 ( & V_12 -> V_175 ) ;
F_59 ( V_12 -> V_7 -> V_88 ) ;
#endif
F_6 ( & V_12 -> V_4 ) ;
F_98 ( & V_12 -> V_176 ) ;
F_98 ( & V_12 -> V_177 ) ;
F_98 ( & V_12 -> V_174 ) ;
F_98 ( & V_12 -> V_178 ) ;
F_33 ( V_12 ) ;
V_12 -> V_7 -> V_95 [ V_12 -> V_29 ] = NULL ;
if ( V_12 -> V_96 . free )
V_12 -> V_96 . free ( V_12 ) ;
#ifdef F_102
if ( ! V_12 -> V_179 )
F_7 ( V_12 -> V_7 , false ) ;
#endif
F_75 ( V_12 -> V_124 ) ;
F_104 ( & V_12 -> V_180 ) ;
F_104 ( & V_12 -> V_181 ) ;
F_37 ( V_12 -> V_137 ) ;
F_37 ( V_12 -> V_140 ) ;
F_37 ( V_12 -> V_114 ) ;
F_37 ( V_12 -> V_61 ) ;
F_37 ( V_12 ) ;
}
int F_105 ( struct V_6 * V_7 ,
unsigned int V_182 ,
struct V_11 * * V_183 )
{
struct V_11 * V_12 ;
char V_184 [ 31 ] ;
T_2 V_185 ;
int V_33 ;
if ( F_43 ( ! V_7 ) )
return - V_59 ;
if ( F_43 ( V_182 > V_186 ) )
return - V_59 ;
if ( V_7 -> V_95 [ V_182 ] ) {
F_45 ( V_30 L_39
L_53 , V_182 ) ;
return - V_187 ;
}
V_12 = F_56 ( sizeof( * V_12 ) , V_51 ) ;
if ( V_12 == NULL ) {
F_45 ( V_30 L_54 ) ;
return - V_52 ;
}
V_12 -> V_7 = V_7 ;
V_12 -> V_29 = V_182 ;
F_68 ( & V_12 -> V_188 ) ;
F_68 ( & V_12 -> V_189 ) ;
F_68 ( & V_12 -> V_190 ) ;
F_106 ( & V_12 -> V_180 , sizeof( struct V_191 ) ) ;
F_106 ( & V_12 -> V_181 , sizeof( struct V_192 ) ) ;
F_107 ( & V_12 -> V_176 , sizeof( struct V_193 ) , 32 ) ;
F_107 ( & V_12 -> V_177 , sizeof( struct V_193 ) , 32 ) ;
F_107 ( & V_12 -> V_158 , sizeof( struct V_155 ) , 16 ) ;
F_107 ( & V_12 -> V_165 , sizeof( struct V_155 ) , 16 ) ;
F_107 ( & V_12 -> V_174 , sizeof( struct V_173 ) , 8 ) ;
F_107 ( & V_12 -> V_178 , sizeof( struct V_194 ) , 16 ) ;
F_107 ( & V_12 -> V_195 , sizeof( struct V_196 ) , 16 ) ;
F_107 ( & V_12 -> V_197 , sizeof( struct V_43 * ) , 8 ) ;
F_69 ( & V_12 -> V_54 ) ;
F_108 ( & V_12 -> V_171 , F_93 ) ;
#ifdef F_102
F_109 ( & V_12 -> V_198 ) ;
F_108 ( & V_12 -> V_175 , V_199 ) ;
F_8 ( V_12 ) ;
F_7 ( V_7 , true ) ;
#endif
if ( V_12 -> V_7 -> V_114 ) {
V_12 -> V_114 = F_78 ( V_12 -> V_7 -> V_114 , V_51 ) ;
if ( ! V_12 -> V_114 ) {
F_61 ( V_12 ) ;
return - V_200 ;
}
}
F_3 ( & V_12 -> V_4 , & V_7 -> V_117 ) ;
V_7 -> V_95 [ V_182 ] = V_12 ;
V_12 -> V_128 = F_27 ( V_12 , V_143 ,
V_201 ) ;
if ( V_12 -> V_128 == - 1 )
V_12 -> V_128 = F_27 ( V_12 , V_143 ,
V_201 ) ;
V_12 -> V_202 = F_27 ( V_12 , V_143 ,
V_203 ) ;
V_12 -> V_130 = F_27 ( V_12 , V_143 ,
V_204 ) ;
F_79 ( V_12 ) ;
if ( ! V_12 -> V_126 && ! V_12 -> V_127 ) {
F_110 ( L_55 ) ;
V_33 = - V_200 ;
goto error;
}
V_185 = V_12 -> V_126 ? V_12 -> V_126 : V_12 -> V_127 ;
V_33 = F_80 ( V_12 , V_185 ) ;
if ( V_33 < 0 ) {
F_45 ( V_30 L_56 ) ;
goto error;
}
V_33 = F_81 ( V_12 ) ;
if ( V_33 < 0 )
goto error;
if ( ! V_12 -> V_202 ) {
V_12 -> V_202 =
F_23 ( V_12 , V_185 , 0 ,
V_205 , 0 ) ;
}
#ifdef F_102
V_12 -> V_206 = F_111 ( V_12 , V_185 ,
V_207 ) ;
if ( ! V_12 -> V_206 )
V_7 -> V_208 = 1 ;
#endif
V_12 -> V_209 = F_111 ( V_12 , V_185 ,
V_210 ) ;
F_112 ( V_12 , V_211 ) ;
F_113 ( V_12 ) ;
F_114 ( V_12 ) ;
sprintf ( V_184 , L_57 , V_12 -> V_128 ,
V_12 -> V_202 , V_12 -> V_130 ) ;
F_115 ( V_12 -> V_7 -> V_104 , V_184 ) ;
if ( V_183 )
* V_183 = V_12 ;
return 0 ;
error:
F_61 ( V_12 ) ;
return V_33 ;
}
int F_116 ( struct V_11 * V_12 )
{
T_2 V_185 ;
int V_33 ;
F_37 ( V_12 -> V_61 ) ;
V_185 = V_12 -> V_126 ? V_12 -> V_126 : V_12 -> V_127 ;
V_33 = F_80 ( V_12 , V_185 ) ;
if ( V_33 < 0 ) {
F_45 ( V_30 L_56 ) ;
return V_33 ;
}
F_98 ( & V_12 -> V_158 ) ;
V_33 = F_81 ( V_12 ) ;
return V_33 ;
}
int F_117 ( struct V_11 * V_12 )
{
int V_33 ;
V_12 -> V_2 = F_72 ( V_12 ) ;
if ( ! V_12 -> V_137 || ! V_12 -> V_140 ) {
V_33 = F_77 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( F_73 ( V_12 ) ) {
V_33 = F_118 ( V_12 ) ;
goto V_212;
}
if ( V_12 -> V_2 && V_12 -> V_2 -> V_213 ) {
V_33 = V_12 -> V_2 -> V_213 ( V_12 ) ;
goto V_212;
}
V_33 = F_118 ( V_12 ) ;
if ( V_33 < 0 )
F_14 ( V_30 L_58 ) ;
V_212:
if ( ! V_33 && V_12 -> V_96 . V_97 )
V_33 = F_55 ( V_12 -> V_7 ) ;
if ( ! V_33 && ( V_12 -> V_126 || ! * V_12 -> V_7 -> V_104 -> V_214 ) )
snprintf ( V_12 -> V_7 -> V_104 -> V_214 ,
sizeof( V_12 -> V_7 -> V_104 -> V_214 ) ,
L_59 , V_12 -> V_137 , V_12 -> V_140 ) ;
return V_33 ;
}
static void F_119 ( struct V_11 * V_12 ,
struct V_173 * V_49 , T_2 V_24 ,
T_1 V_215 , int V_216 )
{
unsigned int V_217 , V_218 ;
if ( V_49 -> V_215 != V_215 || V_49 -> V_216 != V_216 ) {
V_217 = F_23 ( V_12 , V_24 , 0 , V_219 , 0 ) ;
V_218 = ( V_215 << 4 ) | V_216 ;
if ( V_217 != V_218 )
F_24 ( V_12 , V_24 , 0 ,
V_220 ,
V_218 ) ;
V_49 -> V_215 = V_215 ;
V_49 -> V_216 = V_216 ;
}
}
static void F_120 ( struct V_11 * V_12 , struct V_173 * V_49 ,
T_2 V_24 , int V_221 )
{
unsigned int V_217 ;
if ( V_49 -> V_222 != V_221 ) {
V_217 = F_23 ( V_12 , V_24 , 0 ,
V_223 , 0 ) ;
if ( V_217 != V_221 ) {
F_121 ( 1 ) ;
F_24 ( V_12 , V_24 , 0 ,
V_224 ,
V_221 ) ;
}
V_49 -> V_222 = V_221 ;
}
}
void F_122 ( struct V_11 * V_12 , T_2 V_24 ,
T_1 V_215 ,
int V_216 , int V_221 )
{
struct V_11 * V_134 ;
struct V_173 * V_49 ;
int type ;
int V_17 ;
if ( ! V_24 )
return;
F_110 ( L_60
L_61 ,
V_24 , V_215 , V_216 , V_221 ) ;
V_49 = F_99 ( V_12 , V_24 ) ;
if ( ! V_49 )
return;
if ( V_12 -> V_225 )
F_120 ( V_12 , V_49 , V_24 , V_221 ) ;
F_119 ( V_12 , V_49 , V_24 , V_215 , V_216 ) ;
if ( ! V_12 -> V_225 )
F_120 ( V_12 , V_49 , V_24 , V_221 ) ;
V_49 -> V_226 = 1 ;
V_49 -> V_227 = 0 ;
type = F_48 ( F_47 ( V_12 , V_24 ) ) ;
F_29 (c, &codec->bus->codec_list, list) {
for ( V_17 = 0 ; V_17 < V_134 -> V_174 . V_164 ; V_17 ++ ) {
V_49 = F_84 ( & V_134 -> V_174 , V_17 ) ;
if ( ! V_49 -> V_226 && V_49 -> V_215 == V_215 &&
F_48 ( F_47 ( V_134 , V_49 -> V_24 ) ) == type )
V_49 -> V_227 = 1 ;
}
}
}
void F_123 ( struct V_11 * V_12 , T_2 V_24 ,
int V_228 )
{
struct V_173 * V_49 ;
if ( ! V_24 )
return;
if ( V_12 -> V_229 )
V_228 = 1 ;
F_110 ( L_62 , V_24 ) ;
V_49 = F_99 ( V_12 , V_24 ) ;
if ( V_49 ) {
if ( V_228 )
F_124 ( V_12 , V_49 ) ;
else
V_49 -> V_226 = 0 ;
}
}
static void F_124 ( struct V_11 * V_12 ,
struct V_173 * V_230 )
{
T_2 V_24 = V_230 -> V_24 ;
if ( V_230 -> V_215 || V_230 -> V_216 )
F_24 ( V_12 , V_24 , 0 , V_220 , 0 ) ;
if ( V_230 -> V_222 )
F_24 ( V_12 , V_24 , 0 , V_224 , 0
) ;
memset ( V_230 , 0 , sizeof( * V_230 ) ) ;
V_230 -> V_24 = V_24 ;
}
static void F_125 ( struct V_11 * V_12 )
{
struct V_11 * V_134 ;
int V_17 ;
F_29 (c, &codec->bus->codec_list, list) {
for ( V_17 = 0 ; V_17 < V_134 -> V_174 . V_164 ; V_17 ++ ) {
struct V_173 * V_49 ;
V_49 = F_84 ( & V_134 -> V_174 , V_17 ) ;
if ( V_49 -> V_227 )
F_124 ( V_134 , V_49 ) ;
}
}
}
static void F_126 ( struct V_11 * V_12 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_174 . V_164 ; V_17 ++ ) {
struct V_173 * V_49 = F_84 ( & V_12 -> V_174 , V_17 ) ;
if ( V_49 -> V_215 )
F_124 ( V_12 , V_49 ) ;
}
}
static void F_106 ( struct V_231 * V_232 ,
unsigned int V_233 )
{
memset ( V_232 , 0 , sizeof( * V_232 ) ) ;
memset ( V_232 -> V_234 , 0xff , sizeof( V_232 -> V_234 ) ) ;
F_107 ( & V_232 -> V_235 , V_233 , 64 ) ;
}
static void F_104 ( struct V_231 * V_232 )
{
F_98 ( & V_232 -> V_235 ) ;
}
static struct V_192 * F_127 ( struct V_231 * V_232 , T_1 V_236 )
{
T_3 V_237 = V_236 % ( T_3 ) F_10 ( V_232 -> V_234 ) ;
T_3 V_238 = V_232 -> V_234 [ V_237 ] ;
struct V_192 * V_239 ;
while ( V_238 != 0xffff ) {
V_239 = F_84 ( & V_232 -> V_235 , V_238 ) ;
if ( V_239 -> V_236 == V_236 )
return V_239 ;
V_238 = V_239 -> V_240 ;
}
return NULL ;
}
static struct V_192 * F_128 ( struct V_231 * V_232 ,
T_1 V_236 )
{
struct V_192 * V_239 = F_127 ( V_232 , V_236 ) ;
if ( ! V_239 ) {
T_3 V_237 , V_238 ;
V_239 = F_82 ( & V_232 -> V_235 ) ;
if ( ! V_239 )
return NULL ;
V_238 = F_129 ( & V_232 -> V_235 , V_239 ) ;
V_239 -> V_236 = V_236 ;
V_239 -> V_28 = 0 ;
V_239 -> V_227 = 0 ;
V_237 = V_236 % ( T_3 ) F_10 ( V_232 -> V_234 ) ;
V_239 -> V_240 = V_232 -> V_234 [ V_237 ] ;
V_232 -> V_234 [ V_237 ] = V_238 ;
}
return V_239 ;
}
static inline struct V_191 *
F_130 ( struct V_11 * V_12 , T_1 V_236 )
{
return (struct V_191 * ) F_128 ( & V_12 -> V_180 , V_236 ) ;
}
static int F_131 ( struct V_11 * V_12 , T_1 V_236 , unsigned int V_28 )
{
struct V_191 * V_239 ;
F_2 ( & V_12 -> V_190 ) ;
V_239 = F_130 ( V_12 , V_236 ) ;
if ( ! V_239 ) {
F_4 ( & V_12 -> V_190 ) ;
return - V_59 ;
}
V_239 -> V_241 = V_28 ;
V_239 -> V_242 . V_28 |= V_243 ;
F_4 ( & V_12 -> V_190 ) ;
return 0 ;
}
static unsigned int F_132 ( struct V_11 * V_12 , T_2 V_24 ,
int V_244 )
{
if ( ! ( F_47 ( V_12 , V_24 ) & V_245 ) )
V_24 = V_12 -> V_126 ;
return F_27 ( V_12 , V_24 ,
V_244 == V_246 ?
V_247 : V_248 ) ;
}
T_1 F_133 ( struct V_11 * V_12 , T_2 V_24 , int V_244 )
{
return F_134 ( V_12 , V_24 , V_244 ,
F_135 ( V_24 , V_244 , 0 ) ,
F_132 ) ;
}
int F_136 ( struct V_11 * V_12 , T_2 V_24 , int V_249 ,
unsigned int V_250 )
{
return F_131 ( V_12 , F_135 ( V_24 , V_249 , 0 ) , V_250 ) ;
}
static unsigned int F_137 ( struct V_11 * V_12 , T_2 V_24 ,
int V_249 )
{
return F_27 ( V_12 , V_24 , V_251 ) ;
}
T_1 F_138 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_134 ( V_12 , V_24 , 0 , F_139 ( V_24 ) ,
F_137 ) ;
}
int F_140 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_250 )
{
return F_131 ( V_12 , F_139 ( V_24 ) , V_250 ) ;
}
static struct V_191 *
F_141 ( struct V_11 * V_12 , T_2 V_24 , int V_252 ,
int V_244 , int V_253 , bool V_254 )
{
struct V_191 * V_239 ;
unsigned int V_27 , V_28 = 0 ;
bool V_255 = false ;
V_256:
V_239 = F_130 ( V_12 , F_135 ( V_24 , V_244 , V_253 ) ) ;
if ( ! V_239 )
return NULL ;
if ( ! ( V_239 -> V_242 . V_28 & F_142 ( V_252 ) ) ) {
if ( ! V_255 ) {
F_4 ( & V_12 -> V_190 ) ;
V_27 = V_252 ? V_257 : V_258 ;
V_27 |= V_244 == V_246 ?
V_259 : V_260 ;
V_27 |= V_253 ;
V_28 = F_23 ( V_12 , V_24 , 0 ,
V_261 , V_27 ) ;
V_28 &= 0xff ;
V_255 = true ;
F_2 ( & V_12 -> V_190 ) ;
goto V_256;
}
V_239 -> V_262 [ V_252 ] = V_28 ;
V_239 -> V_242 . V_28 |= F_142 ( V_252 ) ;
} else if ( V_254 )
return NULL ;
return V_239 ;
}
static void F_143 ( struct V_11 * V_12 , unsigned int V_241 ,
T_2 V_24 , int V_252 , int V_244 , int V_253 ,
int V_28 )
{
T_1 V_27 ;
V_27 = V_252 ? V_263 : V_264 ;
V_27 |= V_244 == V_246 ? V_265 : V_266 ;
V_27 |= V_253 << V_267 ;
if ( ( V_28 & V_268 ) && ! ( V_241 & V_269 ) &&
( V_241 & V_270 ) )
;
else
V_27 |= V_28 ;
F_24 ( V_12 , V_24 , 0 , V_271 , V_27 ) ;
}
int F_144 ( struct V_11 * V_12 , T_2 V_24 , int V_252 ,
int V_244 , int V_253 )
{
struct V_191 * V_239 ;
unsigned int V_28 = 0 ;
F_2 ( & V_12 -> V_190 ) ;
V_239 = F_141 ( V_12 , V_24 , V_252 , V_244 , V_253 , false ) ;
if ( V_239 )
V_28 = V_239 -> V_262 [ V_252 ] ;
F_4 ( & V_12 -> V_190 ) ;
return V_28 ;
}
static int F_145 ( struct V_11 * V_12 , T_2 V_24 , int V_252 ,
int V_244 , int V_237 , int V_68 , int V_28 ,
bool V_254 )
{
struct V_191 * V_239 ;
unsigned int V_250 ;
unsigned int V_272 ;
if ( F_43 ( V_68 & ~ 0xff ) )
V_68 &= 0xff ;
V_28 &= V_68 ;
F_2 ( & V_12 -> V_190 ) ;
V_239 = F_141 ( V_12 , V_24 , V_252 , V_244 , V_237 , V_254 ) ;
if ( ! V_239 ) {
F_4 ( & V_12 -> V_190 ) ;
return 0 ;
}
V_28 |= V_239 -> V_262 [ V_252 ] & ~ V_68 ;
if ( V_239 -> V_262 [ V_252 ] == V_28 ) {
F_4 ( & V_12 -> V_190 ) ;
return 0 ;
}
V_239 -> V_262 [ V_252 ] = V_28 ;
V_272 = V_239 -> V_242 . V_227 = V_12 -> V_273 ;
V_250 = V_239 -> V_241 ;
F_4 ( & V_12 -> V_190 ) ;
if ( ! V_272 )
F_143 ( V_12 , V_250 , V_24 , V_252 , V_244 , V_237 , V_28 ) ;
return 1 ;
}
int F_146 ( struct V_11 * V_12 , T_2 V_24 , int V_252 ,
int V_244 , int V_237 , int V_68 , int V_28 )
{
return F_145 ( V_12 , V_24 , V_252 , V_244 , V_237 , V_68 , V_28 , false ) ;
}
int F_147 ( struct V_11 * V_12 , T_2 V_24 ,
int V_244 , int V_237 , int V_68 , int V_28 )
{
int V_252 , V_274 = 0 ;
if ( F_43 ( V_68 & ~ 0xff ) )
V_68 &= 0xff ;
for ( V_252 = 0 ; V_252 < 2 ; V_252 ++ )
V_274 |= F_146 ( V_12 , V_24 , V_252 , V_244 ,
V_237 , V_68 , V_28 ) ;
return V_274 ;
}
int F_148 ( struct V_11 * V_12 , T_2 V_24 , int V_252 ,
int V_249 , int V_237 , int V_68 , int V_28 )
{
return F_145 ( V_12 , V_24 , V_252 , V_249 , V_237 , V_68 , V_28 , true ) ;
}
int F_149 ( struct V_11 * V_12 , T_2 V_24 ,
int V_249 , int V_237 , int V_68 , int V_28 )
{
int V_252 , V_274 = 0 ;
if ( F_43 ( V_68 & ~ 0xff ) )
V_68 &= 0xff ;
for ( V_252 = 0 ; V_252 < 2 ; V_252 ++ )
V_274 |= F_148 ( V_12 , V_24 , V_252 , V_249 ,
V_237 , V_68 , V_28 ) ;
return V_274 ;
}
void F_150 ( struct V_11 * V_12 )
{
int V_17 ;
F_2 ( & V_12 -> V_190 ) ;
V_12 -> V_273 = 0 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_180 . V_235 . V_164 ; V_17 ++ ) {
struct V_191 * V_275 ;
T_1 V_236 ;
T_2 V_24 ;
unsigned int V_237 , V_249 , V_252 ;
struct V_191 V_239 ;
V_275 = F_84 ( & V_12 -> V_180 . V_235 , V_17 ) ;
if ( ! V_275 -> V_242 . V_227 )
continue;
V_275 -> V_242 . V_227 = 0 ;
V_239 = * V_275 ;
V_236 = V_239 . V_242 . V_236 ;
if ( ! V_236 )
continue;
V_24 = V_236 & 0xff ;
V_237 = ( V_236 >> 16 ) & 0xff ;
V_249 = ( V_236 >> 24 ) & 0xff ;
for ( V_252 = 0 ; V_252 < 2 ; V_252 ++ ) {
if ( ! ( V_239 . V_242 . V_28 & F_142 ( V_252 ) ) )
continue;
F_4 ( & V_12 -> V_190 ) ;
F_143 ( V_12 , V_239 . V_241 , V_24 , V_252 , V_249 , V_237 ,
V_239 . V_262 [ V_252 ] ) ;
F_2 ( & V_12 -> V_190 ) ;
}
}
F_4 ( & V_12 -> V_190 ) ;
}
static T_1 F_151 ( struct V_11 * V_12 , T_2 V_24 , int V_249 ,
unsigned int V_276 )
{
T_1 V_250 = F_133 ( V_12 , V_24 , V_249 ) ;
V_250 = ( V_250 & V_277 ) >> V_278 ;
if ( V_276 < V_250 )
V_250 -= V_276 ;
return V_250 ;
}
int F_152 ( struct V_279 * V_280 ,
struct V_281 * V_282 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
T_3 V_24 = F_154 ( V_280 ) ;
T_4 V_283 = F_155 ( V_280 ) ;
int V_249 = F_156 ( V_280 ) ;
unsigned int V_276 = F_157 ( V_280 ) ;
V_282 -> type = V_284 ;
V_282 -> V_285 = V_283 == 3 ? 2 : 1 ;
V_282 -> V_286 . integer . V_287 = 0 ;
V_282 -> V_286 . integer . V_288 = F_151 ( V_12 , V_24 , V_249 , V_276 ) ;
if ( ! V_282 -> V_286 . integer . V_288 ) {
F_14 ( V_77 L_39
L_63 , V_24 ,
V_280 -> V_125 . V_132 ) ;
return - V_59 ;
}
return 0 ;
}
static inline unsigned int
F_158 ( struct V_11 * V_12 , T_2 V_24 ,
int V_252 , int V_249 , int V_237 , unsigned int V_276 )
{
unsigned int V_28 ;
V_28 = F_144 ( V_12 , V_24 , V_252 , V_249 , V_237 ) ;
V_28 &= V_289 ;
if ( V_28 >= V_276 )
V_28 -= V_276 ;
else
V_28 = 0 ;
return V_28 ;
}
static inline int
F_159 ( struct V_11 * V_12 , T_2 V_24 ,
int V_252 , int V_249 , int V_237 , unsigned int V_276 ,
unsigned int V_28 )
{
unsigned int V_290 ;
if ( V_28 > 0 )
V_28 += V_276 ;
V_290 = F_151 ( V_12 , V_24 , V_249 , 0 ) ;
if ( V_28 > V_290 )
V_28 = V_290 ;
return F_146 ( V_12 , V_24 , V_252 , V_249 , V_237 ,
V_289 , V_28 ) ;
}
int F_160 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
T_2 V_24 = F_154 ( V_280 ) ;
int V_283 = F_155 ( V_280 ) ;
int V_249 = F_156 ( V_280 ) ;
int V_237 = F_161 ( V_280 ) ;
unsigned int V_276 = F_157 ( V_280 ) ;
long * V_293 = V_292 -> V_286 . integer . V_286 ;
if ( V_283 & 1 )
* V_293 ++ = F_158 ( V_12 , V_24 , 0 , V_249 , V_237 , V_276 ) ;
if ( V_283 & 2 )
* V_293 = F_158 ( V_12 , V_24 , 1 , V_249 , V_237 , V_276 ) ;
return 0 ;
}
int F_162 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
T_2 V_24 = F_154 ( V_280 ) ;
int V_283 = F_155 ( V_280 ) ;
int V_249 = F_156 ( V_280 ) ;
int V_237 = F_161 ( V_280 ) ;
unsigned int V_276 = F_157 ( V_280 ) ;
long * V_293 = V_292 -> V_286 . integer . V_286 ;
int V_294 = 0 ;
F_16 ( V_12 ) ;
if ( V_283 & 1 ) {
V_294 = F_159 ( V_12 , V_24 , 0 , V_249 , V_237 , V_276 , * V_293 ) ;
V_293 ++ ;
}
if ( V_283 & 2 )
V_294 |= F_159 ( V_12 , V_24 , 1 , V_249 , V_237 , V_276 , * V_293 ) ;
F_19 ( V_12 ) ;
return V_294 ;
}
int F_163 ( struct V_279 * V_280 , int V_295 ,
unsigned int V_296 , unsigned int T_5 * V_297 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
T_2 V_24 = F_154 ( V_280 ) ;
int V_249 = F_156 ( V_280 ) ;
unsigned int V_276 = F_157 ( V_280 ) ;
bool V_298 = F_164 ( V_280 ) ;
T_1 V_250 , V_299 , V_300 ;
if ( V_296 < 4 * sizeof( unsigned int ) )
return - V_52 ;
V_250 = F_133 ( V_12 , V_24 , V_249 ) ;
V_300 = ( V_250 & V_301 ) >> V_302 ;
V_300 = ( V_300 + 1 ) * 25 ;
V_299 = - ( ( V_250 & V_303 ) >> V_304 ) ;
V_299 += V_276 ;
V_299 = ( ( int ) V_299 ) * ( ( int ) V_300 ) ;
if ( V_298 || ( V_250 & V_270 ) )
V_300 |= V_305 ;
if ( F_165 ( V_306 , V_297 ) )
return - V_307 ;
if ( F_165 ( 2 * sizeof( unsigned int ) , V_297 + 1 ) )
return - V_307 ;
if ( F_165 ( V_299 , V_297 + 2 ) )
return - V_307 ;
if ( F_165 ( V_300 , V_297 + 3 ) )
return - V_307 ;
return 0 ;
}
void F_166 ( struct V_11 * V_12 , T_2 V_24 , int V_249 ,
unsigned int * V_308 )
{
T_1 V_250 ;
int V_81 , V_309 ;
V_250 = F_133 ( V_12 , V_24 , V_249 ) ;
V_81 = ( V_250 & V_277 ) >> V_278 ;
V_309 = ( V_250 & V_301 ) >> V_302 ;
V_309 = ( V_309 + 1 ) * 25 ;
V_308 [ 0 ] = V_306 ;
V_308 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_308 [ 2 ] = - V_81 * V_309 ;
V_308 [ 3 ] = V_309 ;
}
static struct V_279 *
F_167 ( struct V_11 * V_12 , const char * V_132 , int V_310 , int V_237 )
{
struct V_311 V_125 ;
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
V_125 . V_312 = V_313 ;
V_125 . V_100 = V_310 ;
V_125 . V_253 = V_237 ;
if ( F_43 ( strlen ( V_132 ) >= sizeof( V_125 . V_132 ) ) )
return NULL ;
strcpy ( V_125 . V_132 , V_132 ) ;
return F_168 ( V_12 -> V_7 -> V_104 , & V_125 ) ;
}
struct V_279 * F_169 ( struct V_11 * V_12 ,
const char * V_132 )
{
return F_167 ( V_12 , V_132 , 0 , 0 ) ;
}
static int F_170 ( struct V_11 * V_12 , const char * V_132 ,
int V_314 )
{
int V_17 , V_237 ;
for ( V_17 = 0 , V_237 = V_314 ; V_17 < 16 ; V_17 ++ , V_237 ++ ) {
if ( ! F_167 ( V_12 , V_132 , 0 , V_237 ) )
return V_237 ;
}
return - V_187 ;
}
int F_171 ( struct V_11 * V_12 , T_2 V_24 ,
struct V_279 * V_315 )
{
int V_33 ;
unsigned short V_316 = 0 ;
struct V_193 * V_317 ;
if ( V_315 -> V_125 . V_318 & V_319 ) {
V_316 |= V_320 ;
if ( V_24 == 0 )
V_24 = F_172 ( V_315 -> V_321 ) ;
}
if ( ( V_315 -> V_125 . V_318 & V_322 ) != 0 && V_24 == 0 )
V_24 = V_315 -> V_125 . V_318 & 0xffff ;
if ( V_315 -> V_125 . V_318 & ( V_322 | V_319 ) )
V_315 -> V_125 . V_318 = 0 ;
V_33 = F_173 ( V_12 -> V_7 -> V_104 , V_315 ) ;
if ( V_33 < 0 )
return V_33 ;
V_317 = F_82 ( & V_12 -> V_176 ) ;
if ( ! V_317 )
return - V_52 ;
V_317 -> V_315 = V_315 ;
V_317 -> V_24 = V_24 ;
V_317 -> V_316 = V_316 ;
return 0 ;
}
int F_174 ( struct V_11 * V_12 , struct V_279 * V_315 ,
unsigned int V_253 , T_2 V_24 )
{
struct V_193 * V_317 ;
if ( V_24 > 0 ) {
V_317 = F_82 ( & V_12 -> V_177 ) ;
if ( ! V_317 )
return - V_52 ;
V_317 -> V_315 = V_315 ;
V_317 -> V_253 = V_253 ;
V_317 -> V_24 = V_24 ;
return 0 ;
}
F_14 ( V_30 L_64 ,
V_315 -> V_125 . V_132 , V_315 -> V_125 . V_253 , V_253 ) ;
return - V_59 ;
}
void F_175 ( struct V_11 * V_12 )
{
int V_17 ;
struct V_193 * V_323 = V_12 -> V_176 . V_4 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_176 . V_164 ; V_17 ++ )
F_176 ( V_12 -> V_7 -> V_104 , V_323 [ V_17 ] . V_315 ) ;
F_98 ( & V_12 -> V_176 ) ;
F_98 ( & V_12 -> V_177 ) ;
}
int F_177 ( struct V_6 * V_7 )
{
struct V_103 * V_104 = V_7 -> V_104 ;
struct V_11 * V_12 ;
F_178 ( & V_104 -> V_324 ) ;
if ( V_104 -> V_102 )
goto V_325;
V_104 -> V_102 = 1 ;
if ( ! F_34 ( & V_104 -> V_326 ) )
goto V_327;
F_29 (codec, &bus->codec_list, list) {
int V_328 ;
for ( V_328 = 0 ; V_328 < V_12 -> V_329 ; V_328 ++ ) {
struct V_330 * V_331 = & V_12 -> V_332 [ V_328 ] ;
if ( ! V_331 -> V_328 )
continue;
if ( V_331 -> V_328 -> V_333 [ 0 ] . V_334 ||
V_331 -> V_328 -> V_333 [ 1 ] . V_334 )
goto V_327;
}
}
F_179 ( & V_104 -> V_324 ) ;
return 0 ;
V_327:
V_104 -> V_102 = 0 ;
V_325:
F_179 ( & V_104 -> V_324 ) ;
return - V_59 ;
}
void F_180 ( struct V_6 * V_7 )
{
struct V_103 * V_104 = V_7 -> V_104 ;
V_104 = V_7 -> V_104 ;
F_178 ( & V_104 -> V_324 ) ;
V_104 -> V_102 = 0 ;
F_179 ( & V_104 -> V_324 ) ;
}
int F_181 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_103 * V_104 = V_7 -> V_104 ;
int V_17 ;
if ( F_177 ( V_7 ) < 0 )
return - V_187 ;
F_100 ( & V_12 -> V_171 ) ;
#ifdef F_102
F_100 ( & V_12 -> V_175 ) ;
V_12 -> V_335 = 0 ;
V_12 -> V_336 = 0 ;
V_12 -> V_337 = V_338 ;
F_59 ( V_7 -> V_88 ) ;
#endif
F_175 ( V_12 ) ;
for ( V_17 = 0 ; V_17 < V_12 -> V_329 ; V_17 ++ ) {
if ( V_12 -> V_332 [ V_17 ] . V_328 ) {
F_182 ( V_104 , V_12 -> V_332 [ V_17 ] . V_328 ) ;
F_183 ( V_12 -> V_332 [ V_17 ] . V_100 ,
V_7 -> V_339 ) ;
}
}
if ( V_12 -> V_96 . free )
V_12 -> V_96 . free ( V_12 ) ;
memset ( & V_12 -> V_96 , 0 , sizeof( V_12 -> V_96 ) ) ;
F_101 ( V_12 ) ;
V_12 -> V_340 = NULL ;
V_12 -> V_341 = NULL ;
F_104 ( & V_12 -> V_180 ) ;
F_104 ( & V_12 -> V_181 ) ;
F_106 ( & V_12 -> V_180 , sizeof( struct V_191 ) ) ;
F_106 ( & V_12 -> V_181 , sizeof( struct V_192 ) ) ;
F_98 ( & V_12 -> V_165 ) ;
F_98 ( & V_12 -> V_174 ) ;
F_98 ( & V_12 -> V_178 ) ;
F_98 ( & V_12 -> V_197 ) ;
V_12 -> V_329 = 0 ;
V_12 -> V_332 = NULL ;
V_12 -> V_2 = NULL ;
V_12 -> V_342 = NULL ;
V_12 -> V_343 = 0 ;
F_75 ( V_12 -> V_124 ) ;
V_12 -> V_124 = NULL ;
F_180 ( V_7 ) ;
return 0 ;
}
static int F_184 ( struct V_11 * V_12 , const char * const * V_344 ,
const char * V_345 , T_6 V_346 , void * V_347 )
{
struct V_193 * V_323 ;
const char * const * V_348 ;
int V_17 , V_33 ;
V_323 = V_12 -> V_176 . V_4 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_176 . V_164 ; V_17 ++ ) {
struct V_279 * V_349 = V_323 [ V_17 ] . V_315 ;
if ( ! V_349 || ! V_349 -> V_125 . V_132 ||
V_349 -> V_125 . V_312 != V_313 )
continue;
for ( V_348 = V_344 ; * V_348 ; V_348 ++ ) {
char V_350 [ sizeof( V_349 -> V_125 . V_132 ) ] ;
const char * V_132 = * V_348 ;
if ( V_345 ) {
snprintf ( V_350 , sizeof( V_350 ) , L_59 ,
V_132 , V_345 ) ;
V_132 = V_350 ;
}
if ( ! strcmp ( V_349 -> V_125 . V_132 , V_132 ) ) {
V_33 = V_346 ( V_347 , V_349 ) ;
if ( V_33 )
return V_33 ;
break;
}
}
}
return 0 ;
}
static int F_185 ( void * V_347 , struct V_279 * V_349 )
{
return 1 ;
}
static int F_186 ( struct V_279 * V_315 )
{
int V_297 [ 4 ] ;
const int * V_308 = NULL ;
int V_28 = - 1 ;
if ( V_315 -> V_351 [ 0 ] . V_352 & V_353 ) {
T_7 V_354 = F_187 () ;
F_188 ( F_189 () ) ;
if ( ! V_315 -> V_308 . V_134 ( V_315 , 0 , sizeof( V_297 ) , V_297 ) )
V_308 = V_297 ;
F_188 ( V_354 ) ;
} else if ( V_315 -> V_351 [ 0 ] . V_352 & V_355 )
V_308 = V_315 -> V_308 . V_49 ;
if ( V_308 && V_308 [ 0 ] == V_306 )
V_28 = - V_308 [ 2 ] / V_308 [ 3 ] ;
return V_28 ;
}
static int F_190 ( struct V_279 * V_315 , int V_28 )
{
struct V_291 * V_292 ;
V_292 = F_56 ( sizeof( * V_292 ) , V_51 ) ;
if ( ! V_292 )
return - V_52 ;
V_292 -> V_286 . integer . V_286 [ 0 ] = V_28 ;
V_292 -> V_286 . integer . V_286 [ 1 ] = V_28 ;
V_315 -> V_356 ( V_315 , V_292 ) ;
F_37 ( V_292 ) ;
return 0 ;
}
static int F_191 ( void * V_347 , struct V_279 * V_357 )
{
int V_358 = F_186 ( V_357 ) ;
if ( V_358 > 0 )
F_190 ( V_357 , V_358 ) ;
return 0 ;
}
static int F_192 ( void * V_347 , struct V_279 * V_357 )
{
return F_190 ( V_357 , 1 ) ;
}
int F_193 ( struct V_11 * V_12 , char * V_132 ,
unsigned int * V_308 , const char * const * V_344 ,
const char * V_345 , bool V_359 ,
struct V_279 * * V_360 )
{
struct V_279 * V_315 ;
int V_33 ;
if ( V_360 )
* V_360 = NULL ;
V_33 = F_184 ( V_12 , V_344 , V_345 , F_185 , NULL ) ;
if ( V_33 != 1 ) {
F_110 ( L_65 , V_132 ) ;
return 0 ;
}
V_315 = F_194 ( V_132 , V_308 ) ;
if ( ! V_315 )
return - V_52 ;
V_33 = F_171 ( V_12 , 0 , V_315 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_184 ( V_12 , V_344 , V_345 ,
( T_6 ) V_361 , V_315 ) ;
if ( V_33 < 0 )
return V_33 ;
F_190 ( V_315 , 0 ) ;
if ( V_359 )
F_184 ( V_12 , V_344 , V_345 ,
V_308 ? F_191 : F_192 , V_315 ) ;
if ( V_360 )
* V_360 = V_315 ;
return 0 ;
}
static int F_195 ( struct V_279 * V_280 ,
struct V_281 * V_282 )
{
static const char * const V_362 [] = {
L_66 , L_67 , L_68
} ;
unsigned int V_253 ;
V_282 -> type = V_363 ;
V_282 -> V_285 = 1 ;
V_282 -> V_286 . V_364 . V_323 = 3 ;
V_253 = V_282 -> V_286 . V_364 . V_317 ;
if ( V_253 >= 3 )
V_253 = 2 ;
strcpy ( V_282 -> V_286 . V_364 . V_132 , V_362 [ V_253 ] ) ;
return 0 ;
}
static int F_196 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_365 * V_366 = F_153 ( V_280 ) ;
V_292 -> V_286 . V_364 . V_317 [ 0 ] = V_366 -> V_367 ;
return 0 ;
}
static int F_197 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_365 * V_366 = F_153 ( V_280 ) ;
unsigned int V_368 = V_366 -> V_367 ;
V_366 -> V_367 = V_292 -> V_286 . V_364 . V_317 [ 0 ] ;
if ( V_366 -> V_367 > V_369 )
V_366 -> V_367 = V_369 ;
if ( V_368 == V_366 -> V_367 )
return 0 ;
F_198 ( V_366 ) ;
return 1 ;
}
int F_199 ( struct V_11 * V_12 ,
struct V_365 * V_366 ,
bool V_370 )
{
struct V_279 * V_315 ;
if ( ! V_366 -> V_366 || ! V_366 -> V_371 )
return 0 ;
F_200 ( V_366 -> V_371 , V_366 -> V_366 , V_12 ) ;
V_366 -> V_12 = V_12 ;
V_366 -> V_367 = V_369 ;
if ( ! V_370 )
return 0 ;
V_315 = F_201 ( & V_372 , V_366 ) ;
if ( ! V_315 )
return - V_52 ;
return F_171 ( V_12 , 0 , V_315 ) ;
}
void F_198 ( struct V_365 * V_366 )
{
if ( ! V_366 -> V_366 || ! V_366 -> V_12 )
return;
if ( V_366 -> V_12 -> V_7 -> V_102 )
return;
switch ( V_366 -> V_367 ) {
case V_369 :
F_202 ( V_366 -> V_371 ) ;
break;
default:
V_366 -> V_366 ( V_366 -> V_12 , V_366 -> V_367 ) ;
break;
}
}
int F_203 ( struct V_279 * V_280 ,
struct V_281 * V_282 )
{
int V_283 = F_155 ( V_280 ) ;
V_282 -> type = V_373 ;
V_282 -> V_285 = V_283 == 3 ? 2 : 1 ;
V_282 -> V_286 . integer . V_287 = 0 ;
V_282 -> V_286 . integer . V_288 = 1 ;
return 0 ;
}
int F_204 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
T_2 V_24 = F_154 ( V_280 ) ;
int V_283 = F_155 ( V_280 ) ;
int V_249 = F_156 ( V_280 ) ;
int V_237 = F_161 ( V_280 ) ;
long * V_293 = V_292 -> V_286 . integer . V_286 ;
if ( V_283 & 1 )
* V_293 ++ = ( F_144 ( V_12 , V_24 , 0 , V_249 , V_237 ) &
V_268 ) ? 0 : 1 ;
if ( V_283 & 2 )
* V_293 = ( F_144 ( V_12 , V_24 , 1 , V_249 , V_237 ) &
V_268 ) ? 0 : 1 ;
return 0 ;
}
int F_205 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
T_2 V_24 = F_154 ( V_280 ) ;
int V_283 = F_155 ( V_280 ) ;
int V_249 = F_156 ( V_280 ) ;
int V_237 = F_161 ( V_280 ) ;
long * V_293 = V_292 -> V_286 . integer . V_286 ;
int V_294 = 0 ;
F_16 ( V_12 ) ;
if ( V_283 & 1 ) {
V_294 = F_146 ( V_12 , V_24 , 0 , V_249 , V_237 ,
V_268 ,
* V_293 ? 0 : V_268 ) ;
V_293 ++ ;
}
if ( V_283 & 2 )
V_294 |= F_146 ( V_12 , V_24 , 1 , V_249 , V_237 ,
V_268 ,
* V_293 ? 0 : V_268 ) ;
F_206 ( V_12 , V_24 ) ;
F_19 ( V_12 ) ;
return V_294 ;
}
int F_207 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
unsigned long V_374 ;
int V_33 ;
F_2 ( & V_12 -> V_189 ) ;
V_374 = V_280 -> V_321 ;
V_280 -> V_321 = V_374 & ~ V_375 ;
V_33 = F_204 ( V_280 , V_292 ) ;
V_280 -> V_321 = V_374 ;
F_4 ( & V_12 -> V_189 ) ;
return V_33 ;
}
int F_208 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
unsigned long V_374 ;
int V_17 , V_376 , V_33 = 0 , V_294 = 0 ;
F_2 ( & V_12 -> V_189 ) ;
V_374 = V_280 -> V_321 ;
V_376 = ( V_374 & V_375 ) >> V_377 ;
for ( V_17 = 0 ; V_17 < V_376 ; V_17 ++ ) {
V_280 -> V_321 = ( V_374 & ~ V_375 ) |
( V_17 << V_377 ) ;
V_33 = F_205 ( V_280 , V_292 ) ;
if ( V_33 < 0 )
break;
V_294 |= V_33 ;
}
V_280 -> V_321 = V_374 ;
F_4 ( & V_12 -> V_189 ) ;
return V_33 < 0 ? V_33 : V_294 ;
}
int F_209 ( struct V_279 * V_280 ,
struct V_281 * V_282 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
struct V_378 * V_134 ;
int V_33 ;
F_2 ( & V_12 -> V_189 ) ;
V_134 = (struct V_378 * ) V_280 -> V_321 ;
V_280 -> V_321 = * V_134 -> V_379 ;
V_33 = V_134 -> V_9 -> V_239 ( V_280 , V_282 ) ;
V_280 -> V_321 = ( long ) V_134 ;
F_4 ( & V_12 -> V_189 ) ;
return V_33 ;
}
int F_210 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
struct V_378 * V_134 ;
int V_33 ;
F_2 ( & V_12 -> V_189 ) ;
V_134 = (struct V_378 * ) V_280 -> V_321 ;
V_280 -> V_321 = * V_134 -> V_379 ;
V_33 = V_134 -> V_9 -> V_380 ( V_280 , V_292 ) ;
V_280 -> V_321 = ( long ) V_134 ;
F_4 ( & V_12 -> V_189 ) ;
return V_33 ;
}
int F_211 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
struct V_378 * V_134 ;
unsigned long * V_381 ;
int V_33 = 0 , V_294 = 0 ;
F_2 ( & V_12 -> V_189 ) ;
V_134 = (struct V_378 * ) V_280 -> V_321 ;
for ( V_381 = V_134 -> V_379 ; * V_381 ; V_381 ++ ) {
V_280 -> V_321 = * V_381 ;
V_33 = V_134 -> V_9 -> V_356 ( V_280 , V_292 ) ;
if ( V_33 < 0 )
break;
V_294 |= V_33 ;
}
V_280 -> V_321 = ( long ) V_134 ;
F_4 ( & V_12 -> V_189 ) ;
return V_33 < 0 ? V_33 : V_294 ;
}
int F_212 ( struct V_279 * V_280 , int V_295 ,
unsigned int V_296 , unsigned int T_5 * V_308 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
struct V_378 * V_134 ;
int V_33 ;
F_2 ( & V_12 -> V_189 ) ;
V_134 = (struct V_378 * ) V_280 -> V_321 ;
V_280 -> V_321 = * V_134 -> V_379 ;
V_33 = V_134 -> V_9 -> V_308 ( V_280 , V_295 , V_296 , V_308 ) ;
V_280 -> V_321 = ( long ) V_134 ;
F_4 ( & V_12 -> V_189 ) ;
return V_33 ;
}
static int F_213 ( struct V_279 * V_280 ,
struct V_281 * V_282 )
{
V_282 -> type = V_382 ;
V_282 -> V_285 = 1 ;
return 0 ;
}
static int F_214 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
V_292 -> V_286 . V_383 . V_384 [ 0 ] = V_385 |
V_386 |
V_387 |
V_388 ;
V_292 -> V_286 . V_383 . V_384 [ 1 ] = V_389 |
V_390 ;
return 0 ;
}
static int F_215 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
V_292 -> V_286 . V_383 . V_384 [ 0 ] = V_385 |
V_386 |
V_391 ;
return 0 ;
}
static int F_216 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
int V_237 = V_280 -> V_321 ;
struct V_194 * V_392 ;
F_2 ( & V_12 -> V_188 ) ;
V_392 = F_84 ( & V_12 -> V_178 , V_237 ) ;
V_292 -> V_286 . V_383 . V_384 [ 0 ] = V_392 -> V_384 & 0xff ;
V_292 -> V_286 . V_383 . V_384 [ 1 ] = ( V_392 -> V_384 >> 8 ) & 0xff ;
V_292 -> V_286 . V_383 . V_384 [ 2 ] = ( V_392 -> V_384 >> 16 ) & 0xff ;
V_292 -> V_286 . V_383 . V_384 [ 3 ] = ( V_392 -> V_384 >> 24 ) & 0xff ;
F_4 ( & V_12 -> V_188 ) ;
return 0 ;
}
static unsigned short F_217 ( unsigned int V_393 )
{
unsigned short V_28 = 0 ;
if ( V_393 & V_385 )
V_28 |= V_394 ;
if ( V_393 & V_386 )
V_28 |= V_395 ;
if ( V_393 & V_385 ) {
if ( ( V_393 & V_396 ) ==
V_391 )
V_28 |= V_397 ;
} else {
if ( ( V_393 & V_398 ) ==
V_387 )
V_28 |= V_397 ;
if ( ! ( V_393 & V_388 ) )
V_28 |= V_399 ;
if ( V_393 & ( V_390 << 8 ) )
V_28 |= V_400 ;
V_28 |= V_393 & ( V_389 << 8 ) ;
}
return V_28 ;
}
static unsigned int F_218 ( unsigned short V_28 )
{
unsigned int V_393 = 0 ;
if ( V_28 & V_395 )
V_393 |= V_386 ;
if ( V_28 & V_394 )
V_393 |= V_385 ;
if ( V_393 & V_385 ) {
if ( V_28 & V_397 )
V_393 |= V_391 ;
} else {
if ( V_28 & V_397 )
V_393 |= V_387 ;
if ( ! ( V_28 & V_399 ) )
V_393 |= V_388 ;
if ( V_28 & V_400 )
V_393 |= ( V_390 << 8 ) ;
V_393 |= V_28 & ( 0x7f << 8 ) ;
}
return V_393 ;
}
static void F_219 ( struct V_11 * V_12 , T_2 V_24 ,
int V_26 , int V_28 )
{
const T_2 * V_401 ;
F_220 ( V_12 , V_24 , 0 , V_26 , V_28 ) ;
V_401 = V_12 -> V_342 ;
if ( ! V_401 )
return;
for (; * V_401 ; V_401 ++ )
F_220 ( V_12 , * V_401 , 0 , V_26 , V_28 ) ;
}
static inline void F_221 ( struct V_11 * V_12 , T_2 V_24 ,
int V_402 , int V_403 )
{
if ( V_402 != - 1 )
F_219 ( V_12 , V_24 , V_404 , V_402 ) ;
if ( V_403 != - 1 )
F_219 ( V_12 , V_24 , V_405 , V_403 ) ;
}
static int F_222 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
int V_237 = V_280 -> V_321 ;
struct V_194 * V_392 ;
T_2 V_24 ;
unsigned short V_28 ;
int V_294 ;
F_2 ( & V_12 -> V_188 ) ;
V_392 = F_84 ( & V_12 -> V_178 , V_237 ) ;
V_24 = V_392 -> V_24 ;
V_392 -> V_384 = V_292 -> V_286 . V_383 . V_384 [ 0 ] |
( ( unsigned int ) V_292 -> V_286 . V_383 . V_384 [ 1 ] << 8 ) |
( ( unsigned int ) V_292 -> V_286 . V_383 . V_384 [ 2 ] << 16 ) |
( ( unsigned int ) V_292 -> V_286 . V_383 . V_384 [ 3 ] << 24 ) ;
V_28 = F_217 ( V_392 -> V_384 ) ;
V_28 |= V_392 -> V_406 & 1 ;
V_294 = V_392 -> V_406 != V_28 ;
V_392 -> V_406 = V_28 ;
if ( V_294 && V_24 != ( T_3 ) - 1 )
F_221 ( V_12 , V_24 , V_28 & 0xff , ( V_28 >> 8 ) & 0xff ) ;
F_4 ( & V_12 -> V_188 ) ;
return V_294 ;
}
static int F_223 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
int V_237 = V_280 -> V_321 ;
struct V_194 * V_392 ;
F_2 ( & V_12 -> V_188 ) ;
V_392 = F_84 ( & V_12 -> V_178 , V_237 ) ;
V_292 -> V_286 . integer . V_286 [ 0 ] = V_392 -> V_406 & V_407 ;
F_4 ( & V_12 -> V_188 ) ;
return 0 ;
}
static inline void F_224 ( struct V_11 * V_12 , T_2 V_24 ,
int V_402 , int V_403 )
{
F_221 ( V_12 , V_24 , V_402 , V_403 ) ;
if ( ( F_47 ( V_12 , V_24 ) & V_408 ) &&
( V_402 & V_407 ) )
F_147 ( V_12 , V_24 , V_246 , 0 ,
V_268 , 0 ) ;
}
static int F_225 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
int V_237 = V_280 -> V_321 ;
struct V_194 * V_392 ;
T_2 V_24 ;
unsigned short V_28 ;
int V_294 ;
F_2 ( & V_12 -> V_188 ) ;
V_392 = F_84 ( & V_12 -> V_178 , V_237 ) ;
V_24 = V_392 -> V_24 ;
V_28 = V_392 -> V_406 & ~ V_407 ;
if ( V_292 -> V_286 . integer . V_286 [ 0 ] )
V_28 |= V_407 ;
V_294 = V_392 -> V_406 != V_28 ;
V_392 -> V_406 = V_28 ;
if ( V_294 && V_24 != ( T_3 ) - 1 )
F_224 ( V_12 , V_24 , V_28 & 0xff , - 1 ) ;
F_4 ( & V_12 -> V_188 ) ;
return V_294 ;
}
int F_226 ( struct V_11 * V_12 ,
T_2 V_409 ,
T_2 V_410 ,
int type )
{
int V_33 ;
struct V_279 * V_315 ;
struct V_411 * V_412 ;
int V_237 = 0 ;
const int V_413 = 16 ;
struct V_194 * V_392 ;
struct V_6 * V_7 = V_12 -> V_7 ;
if ( V_7 -> V_414 == V_415 &&
type == V_416 ) {
V_237 = V_413 ;
} else if ( V_7 -> V_414 == V_416 &&
type == V_415 ) {
for ( V_412 = V_417 ; V_412 -> V_132 ; V_412 ++ ) {
V_315 = F_167 ( V_12 , V_412 -> V_132 , 0 , 0 ) ;
if ( ! V_315 )
break;
V_315 -> V_125 . V_253 = V_413 ;
}
V_7 -> V_414 = V_415 ;
}
if ( ! V_7 -> V_414 )
V_7 -> V_414 = type ;
V_237 = F_170 ( V_12 , L_69 , V_237 ) ;
if ( V_237 < 0 ) {
F_14 ( V_30 L_70 ) ;
return - V_187 ;
}
V_392 = F_82 ( & V_12 -> V_178 ) ;
if ( ! V_392 )
return - V_52 ;
for ( V_412 = V_417 ; V_412 -> V_132 ; V_412 ++ ) {
V_315 = F_201 ( V_412 , V_12 ) ;
if ( ! V_315 )
return - V_52 ;
V_315 -> V_125 . V_253 = V_237 ;
V_315 -> V_321 = V_12 -> V_178 . V_164 - 1 ;
V_33 = F_171 ( V_12 , V_409 , V_315 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_392 -> V_24 = V_410 ;
V_392 -> V_406 = F_23 ( V_12 , V_410 , 0 ,
V_418 , 0 ) ;
V_392 -> V_384 = F_218 ( V_392 -> V_406 ) ;
return 0 ;
}
struct V_194 * F_227 ( struct V_11 * V_12 ,
T_2 V_24 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_178 . V_164 ; V_17 ++ ) {
struct V_194 * V_392 =
F_84 ( & V_12 -> V_178 , V_17 ) ;
if ( V_392 -> V_24 == V_24 )
return V_392 ;
}
return NULL ;
}
void F_228 ( struct V_11 * V_12 , int V_237 )
{
struct V_194 * V_392 ;
F_2 ( & V_12 -> V_188 ) ;
V_392 = F_84 ( & V_12 -> V_178 , V_237 ) ;
V_392 -> V_24 = ( T_3 ) - 1 ;
F_4 ( & V_12 -> V_188 ) ;
}
void F_229 ( struct V_11 * V_12 , int V_237 , T_2 V_24 )
{
struct V_194 * V_392 ;
unsigned short V_28 ;
F_2 ( & V_12 -> V_188 ) ;
V_392 = F_84 ( & V_12 -> V_178 , V_237 ) ;
if ( V_392 -> V_24 != V_24 ) {
V_392 -> V_24 = V_24 ;
V_28 = V_392 -> V_406 ;
F_224 ( V_12 , V_24 , V_28 & 0xff , ( V_28 >> 8 ) & 0xff ) ;
}
F_4 ( & V_12 -> V_188 ) ;
}
static int F_230 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_419 * V_420 = F_153 ( V_280 ) ;
V_292 -> V_286 . integer . V_286 [ 0 ] = V_420 -> V_421 ;
return 0 ;
}
static int F_231 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_419 * V_420 = F_153 ( V_280 ) ;
V_420 -> V_421 = ! ! V_292 -> V_286 . integer . V_286 [ 0 ] ;
return 0 ;
}
int F_232 ( struct V_11 * V_12 ,
struct V_419 * V_420 )
{
struct V_279 * V_315 ;
if ( ! V_420 -> V_422 )
return 0 ;
V_315 = F_201 ( & V_423 , V_420 ) ;
if ( ! V_315 )
return - V_52 ;
return F_171 ( V_12 , V_420 -> V_422 , V_315 ) ;
}
static int F_233 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
V_292 -> V_286 . integer . V_286 [ 0 ] = V_12 -> V_424 ;
return 0 ;
}
static int F_234 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
T_2 V_24 = V_280 -> V_321 ;
unsigned int V_28 = ! ! V_292 -> V_286 . integer . V_286 [ 0 ] ;
int V_294 ;
F_2 ( & V_12 -> V_188 ) ;
V_294 = V_12 -> V_424 != V_28 ;
if ( V_294 ) {
V_12 -> V_424 = V_28 ;
F_220 ( V_12 , V_24 , 0 ,
V_404 , V_28 ) ;
}
F_4 ( & V_12 -> V_188 ) ;
return V_294 ;
}
static int F_235 ( struct V_279 * V_280 ,
struct V_291 * V_292 )
{
struct V_11 * V_12 = F_153 ( V_280 ) ;
T_2 V_24 = V_280 -> V_321 ;
unsigned short V_28 ;
unsigned int V_393 ;
V_28 = F_23 ( V_12 , V_24 , 0 , V_418 , 0 ) ;
V_393 = F_218 ( V_28 ) ;
V_292 -> V_286 . V_383 . V_384 [ 0 ] = V_393 ;
V_292 -> V_286 . V_383 . V_384 [ 1 ] = V_393 >> 8 ;
V_292 -> V_286 . V_383 . V_384 [ 2 ] = V_393 >> 16 ;
V_292 -> V_286 . V_383 . V_384 [ 3 ] = V_393 >> 24 ;
return 0 ;
}
int F_236 ( struct V_11 * V_12 , T_2 V_24 )
{
int V_33 ;
struct V_279 * V_315 ;
struct V_411 * V_412 ;
int V_237 ;
V_237 = F_170 ( V_12 , L_71 , 0 ) ;
if ( V_237 < 0 ) {
F_14 ( V_30 L_72 ) ;
return - V_187 ;
}
for ( V_412 = V_425 ; V_412 -> V_132 ; V_412 ++ ) {
V_315 = F_201 ( V_412 , V_12 ) ;
if ( ! V_315 )
return - V_52 ;
V_315 -> V_321 = V_24 ;
V_33 = F_171 ( V_12 , V_24 , V_315 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_12 -> V_424 =
F_23 ( V_12 , V_24 , 0 ,
V_418 , 0 ) &
V_407 ;
return 0 ;
}
int F_220 ( struct V_11 * V_12 , T_2 V_24 ,
int V_25 , unsigned int V_26 , unsigned int V_27 )
{
int V_33 ;
struct V_192 * V_134 ;
T_1 V_236 ;
unsigned int V_272 ;
V_272 = V_12 -> V_273 ;
if ( ! V_272 ) {
V_33 = F_24 ( V_12 , V_24 , V_25 , V_26 , V_27 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_26 = V_26 | ( V_27 >> 8 ) ;
V_27 &= 0xff ;
V_236 = F_237 ( V_24 , V_26 ) ;
F_2 ( & V_12 -> V_7 -> V_35 ) ;
V_134 = F_128 ( & V_12 -> V_181 , V_236 ) ;
if ( V_134 ) {
V_134 -> V_28 = V_27 ;
V_134 -> V_227 = V_272 ;
}
F_4 ( & V_12 -> V_7 -> V_35 ) ;
return 0 ;
}
int F_238 ( struct V_11 * V_12 , T_2 V_24 ,
int V_25 , unsigned int V_26 , unsigned int V_27 )
{
struct V_192 * V_134 ;
T_1 V_236 ;
V_26 = V_26 | ( V_27 >> 8 ) ;
V_27 &= 0xff ;
V_236 = F_237 ( V_24 , V_26 ) ;
F_2 ( & V_12 -> V_7 -> V_35 ) ;
V_134 = F_127 ( & V_12 -> V_181 , V_236 ) ;
if ( V_134 && V_134 -> V_28 == V_27 ) {
F_4 ( & V_12 -> V_7 -> V_35 ) ;
return 0 ;
}
F_4 ( & V_12 -> V_7 -> V_35 ) ;
return F_220 ( V_12 , V_24 , V_25 , V_26 , V_27 ) ;
}
void F_239 ( struct V_11 * V_12 )
{
int V_17 ;
F_2 ( & V_12 -> V_190 ) ;
V_12 -> V_273 = 0 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_181 . V_235 . V_164 ; V_17 ++ ) {
struct V_192 * V_275 ;
T_1 V_236 ;
V_275 = F_84 ( & V_12 -> V_181 . V_235 , V_17 ) ;
V_236 = V_275 -> V_236 ;
if ( ! V_236 )
continue;
if ( ! V_275 -> V_227 )
continue;
V_275 -> V_227 = 0 ;
F_4 ( & V_12 -> V_190 ) ;
F_24 ( V_12 , F_240 ( V_236 ) , 0 ,
F_241 ( V_236 ) , V_275 -> V_28 ) ;
F_2 ( & V_12 -> V_190 ) ;
}
F_4 ( & V_12 -> V_190 ) ;
}
void F_242 ( struct V_11 * V_12 ,
const struct V_43 * V_44 )
{
for (; V_44 -> V_24 ; V_44 ++ )
F_220 ( V_12 , V_44 -> V_24 , 0 , V_44 -> V_26 ,
V_44 -> V_45 ) ;
}
void F_243 ( struct V_11 * V_12 )
{
F_150 ( V_12 ) ;
F_239 ( V_12 ) ;
}
void F_244 ( struct V_11 * V_12 , T_2 V_185 ,
unsigned int V_426 )
{
T_2 V_24 = V_12 -> V_153 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_152 ; V_17 ++ , V_24 ++ ) {
unsigned int V_61 = F_47 ( V_12 , V_24 ) ;
unsigned int V_427 = V_426 ;
if ( ! ( V_61 & V_428 ) )
continue;
if ( V_12 -> V_429 ) {
V_427 = V_12 -> V_429 ( V_12 , V_24 , V_426 ) ;
if ( V_427 != V_426 && V_426 == V_430 )
continue;
}
F_24 ( V_12 , V_24 , 0 , V_431 ,
V_427 ) ;
}
}
static bool F_111 ( struct V_11 * V_12 , T_2 V_185 ,
unsigned int V_426 )
{
int V_432 = F_27 ( V_12 , V_185 , V_433 ) ;
if ( V_432 == - 1 )
return false ;
if ( V_432 & V_426 )
return true ;
else
return false ;
}
static unsigned int F_245 ( struct V_11 * V_12 ,
T_2 V_185 ,
unsigned int V_426 )
{
unsigned long V_434 = V_338 + F_246 ( 500 ) ;
unsigned int V_427 , V_435 ;
for (; ; ) {
V_427 = F_23 ( V_12 , V_185 , 0 ,
V_436 , 0 ) ;
if ( V_427 & V_437 )
break;
V_435 = ( V_427 >> 4 ) & 0x0f ;
if ( V_435 == V_426 )
break;
if ( F_247 ( V_338 , V_434 ) )
break;
F_121 ( 1 ) ;
}
return V_427 ;
}
unsigned int F_248 ( struct V_11 * V_12 ,
T_2 V_24 ,
unsigned int V_426 )
{
if ( V_426 == V_430 &&
F_48 ( F_47 ( V_12 , V_24 ) ) == V_82 &&
( F_138 ( V_12 , V_24 ) & V_438 ) ) {
int V_439 = F_23 ( V_12 , V_24 , 0 ,
V_440 , 0 ) ;
if ( V_439 & 0x02 )
return V_211 ;
}
return V_426 ;
}
static unsigned int F_112 ( struct V_11 * V_12 ,
unsigned int V_426 )
{
T_2 V_185 = V_12 -> V_126 ? V_12 -> V_126 : V_12 -> V_127 ;
int V_285 ;
unsigned int V_427 ;
if ( V_426 == V_430 ) {
F_121 ( V_12 -> V_209 ? 10 : 100 ) ;
}
for ( V_285 = 0 ; V_285 < 10 ; V_285 ++ ) {
if ( V_12 -> V_96 . V_441 )
V_12 -> V_96 . V_441 ( V_12 , V_185 ,
V_426 ) ;
else {
F_23 ( V_12 , V_185 , 0 ,
V_431 ,
V_426 ) ;
F_244 ( V_12 , V_185 , V_426 ) ;
}
V_427 = F_245 ( V_12 , V_185 , V_426 ) ;
if ( ! ( V_427 & V_437 ) )
break;
}
return V_427 ;
}
static void F_249 ( struct V_11 * V_12 )
{
T_2 V_24 = V_12 -> V_153 ;
int V_17 ;
if ( ! V_12 -> V_429 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_152 ; V_17 ++ , V_24 ++ ) {
unsigned int V_61 = F_47 ( V_12 , V_24 ) ;
unsigned int V_168 ;
if ( ! ( V_61 & V_428 ) )
continue;
V_168 = V_12 -> V_429 ( V_12 , V_24 , V_211 ) ;
if ( V_168 == V_211 )
continue;
if ( ! F_250 ( V_12 , V_24 , V_168 ) )
F_24 ( V_12 , V_24 , 0 ,
V_431 , V_168 ) ;
}
}
static void F_251 ( struct V_11 * V_12 )
{
if ( V_12 -> V_442 . V_4 )
F_25 ( V_12 , V_12 -> V_442 . V_4 ) ;
}
static inline void F_251 ( struct V_11 * V_12 ) {}
static unsigned int F_252 ( struct V_11 * V_12 , bool V_443 )
{
unsigned int V_427 ;
V_12 -> V_444 = 1 ;
if ( V_12 -> V_96 . V_445 )
V_12 -> V_96 . V_445 ( V_12 ) ;
F_126 ( V_12 ) ;
V_427 = F_112 ( V_12 , V_430 ) ;
if ( ! V_443 )
F_100 ( & V_12 -> V_175 ) ;
F_178 ( & V_12 -> V_198 ) ;
F_253 ( V_12 ) ;
F_254 ( V_12 ) ;
V_12 -> V_335 = 0 ;
V_12 -> V_336 = 0 ;
V_12 -> V_337 = V_338 ;
F_179 ( & V_12 -> V_198 ) ;
V_12 -> V_444 = 0 ;
return V_427 ;
}
static void F_255 ( struct V_11 * V_12 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_181 . V_235 . V_164 ; V_17 ++ ) {
struct V_192 * V_31 ;
V_31 = F_84 ( & V_12 -> V_181 . V_235 , V_17 ) ;
V_31 -> V_227 = 1 ;
}
for ( V_17 = 0 ; V_17 < V_12 -> V_180 . V_235 . V_164 ; V_17 ++ ) {
struct V_191 * V_446 ;
V_446 = F_84 ( & V_12 -> V_180 . V_235 , V_17 ) ;
V_446 -> V_242 . V_227 = 1 ;
}
}
static void F_256 ( struct V_11 * V_12 )
{
V_12 -> V_444 = 1 ;
F_255 ( V_12 ) ;
F_8 ( V_12 ) ;
F_112 ( V_12 , V_211 ) ;
F_92 ( V_12 ) ;
F_251 ( V_12 ) ;
F_94 ( V_12 ) ;
if ( V_12 -> V_96 . V_447 )
V_12 -> V_96 . V_447 ( V_12 ) ;
else {
if ( V_12 -> V_96 . V_448 )
V_12 -> V_96 . V_448 ( V_12 ) ;
F_150 ( V_12 ) ;
F_239 ( V_12 ) ;
}
if ( V_12 -> V_172 )
F_93 ( & V_12 -> V_171 . V_91 ) ;
else
F_257 ( V_12 ) ;
V_12 -> V_444 = 0 ;
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
int V_17 , V_449 , V_33 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_329 ; V_17 ++ ) {
for ( V_449 = 0 ; V_449 < 2 ; V_449 ++ ) {
struct V_450 * V_328 = V_12 -> V_332 [ V_17 ] . V_328 ;
struct V_451 * V_452 =
& V_12 -> V_332 [ V_17 ] . V_453 [ V_449 ] ;
struct V_454 * V_455 ;
const struct V_456 * V_457 ;
if ( V_12 -> V_332 [ V_17 ] . V_458 )
continue;
if ( ! V_328 || ! V_452 -> V_459 )
continue;
V_457 = V_452 -> V_455 ? V_452 -> V_455 : V_460 ;
V_33 = F_261 ( V_328 , V_449 , V_457 ,
V_452 -> V_461 ,
0 , & V_455 ) ;
if ( V_33 < 0 )
return V_33 ;
V_455 -> V_462 = V_463 ;
}
}
return 0 ;
}
int F_259 ( struct V_11 * V_12 )
{
int V_33 = 0 ;
F_251 ( V_12 ) ;
if ( V_12 -> V_96 . V_448 )
V_33 = V_12 -> V_96 . V_448 ( V_12 ) ;
if ( ! V_33 && V_12 -> V_96 . V_464 )
V_33 = V_12 -> V_96 . V_464 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_260 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_12 -> V_172 )
F_93 ( & V_12 -> V_171 . V_91 ) ;
else
F_257 ( V_12 ) ;
F_249 ( V_12 ) ;
return 0 ;
}
unsigned int F_262 ( unsigned int V_465 ,
unsigned int V_466 ,
unsigned int V_221 ,
unsigned int V_467 ,
unsigned short V_468 )
{
int V_17 ;
unsigned int V_28 = 0 ;
for ( V_17 = 0 ; V_469 [ V_17 ] . V_470 ; V_17 ++ )
if ( V_469 [ V_17 ] . V_470 == V_465 ) {
V_28 = V_469 [ V_17 ] . V_471 ;
break;
}
if ( ! V_469 [ V_17 ] . V_470 ) {
F_110 ( L_76 , V_465 ) ;
return 0 ;
}
if ( V_466 == 0 || V_466 > 8 ) {
F_110 ( L_77 , V_466 ) ;
return 0 ;
}
V_28 |= V_466 - 1 ;
switch ( F_263 ( V_221 ) ) {
case 8 :
V_28 |= V_472 ;
break;
case 16 :
V_28 |= V_473 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_467 >= 32 || V_221 == V_474 )
V_28 |= V_475 ;
else if ( V_467 >= 24 )
V_28 |= V_476 ;
else
V_28 |= V_477 ;
break;
default:
F_110 ( L_78 ,
F_263 ( V_221 ) ) ;
return 0 ;
}
if ( V_468 & V_395 )
V_28 |= V_478 ;
return V_28 ;
}
static unsigned int F_264 ( struct V_11 * V_12 , T_2 V_24 ,
int V_249 )
{
unsigned int V_28 = 0 ;
if ( V_24 != V_12 -> V_126 &&
( F_47 ( V_12 , V_24 ) & V_479 ) )
V_28 = F_27 ( V_12 , V_24 , V_480 ) ;
if ( ! V_28 || V_28 == - 1 )
V_28 = F_27 ( V_12 , V_12 -> V_126 , V_480 ) ;
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
int V_249 )
{
unsigned int V_333 = F_27 ( V_12 , V_24 , V_481 ) ;
if ( ! V_333 || V_333 == - 1 )
V_333 = F_27 ( V_12 , V_12 -> V_126 , V_481 ) ;
if ( ! V_333 || V_333 == - 1 )
return 0 ;
return V_333 ;
}
static unsigned int F_268 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_134 ( V_12 , V_24 , 0 , F_269 ( V_24 ) ,
F_267 ) ;
}
int F_270 ( struct V_11 * V_12 , T_2 V_24 ,
T_1 * V_482 , T_8 * V_483 , unsigned int * V_484 )
{
unsigned int V_17 , V_28 , V_61 ;
V_61 = F_47 ( V_12 , V_24 ) ;
V_28 = F_265 ( V_12 , V_24 ) ;
if ( V_482 ) {
T_1 V_485 = 0 ;
for ( V_17 = 0 ; V_17 < V_486 ; V_17 ++ ) {
if ( V_28 & ( 1 << V_17 ) )
V_485 |= V_469 [ V_17 ] . V_487 ;
}
if ( V_485 == 0 ) {
F_45 ( V_30 L_79
L_80 ,
V_24 , V_28 ,
( V_61 & V_479 ) ? 1 : 0 ) ;
return - V_74 ;
}
* V_482 = V_485 ;
}
if ( V_483 || V_484 ) {
T_8 V_488 = 0 ;
unsigned int V_333 , V_489 ;
V_333 = F_268 ( V_12 , V_24 ) ;
if ( ! V_333 )
return - V_74 ;
V_489 = 0 ;
if ( V_333 & V_490 ) {
if ( V_28 & V_491 ) {
V_488 |= V_492 ;
V_489 = 8 ;
}
if ( V_28 & V_493 ) {
V_488 |= V_494 ;
V_489 = 16 ;
}
if ( V_61 & V_495 ) {
if ( V_28 & V_496 )
V_488 |= V_497 ;
if ( V_28 & ( V_498 | V_499 ) )
V_488 |= V_500 ;
if ( V_28 & V_499 )
V_489 = 24 ;
else if ( V_28 & V_498 )
V_489 = 20 ;
} else if ( V_28 & ( V_498 | V_499 |
V_496 ) ) {
V_488 |= V_500 ;
if ( V_28 & V_496 )
V_489 = 32 ;
else if ( V_28 & V_499 )
V_489 = 24 ;
else if ( V_28 & V_498 )
V_489 = 20 ;
}
}
#if 0
if (streams & AC_SUPFMT_FLOAT32) {
formats |= SNDRV_PCM_FMTBIT_FLOAT_LE;
if (!bps)
bps = 32;
}
#endif
if ( V_333 == V_501 ) {
V_488 |= V_492 ;
V_489 = 8 ;
}
if ( V_488 == 0 ) {
F_45 ( V_30 L_81
L_82
L_83 ,
V_24 , V_28 ,
( V_61 & V_479 ) ? 1 : 0 ,
V_333 ) ;
return - V_74 ;
}
if ( V_483 )
* V_483 = V_488 ;
if ( V_484 )
* V_484 = V_489 ;
}
return 0 ;
}
int F_271 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_221 )
{
int V_17 ;
unsigned int V_28 = 0 , V_465 , V_453 ;
V_28 = F_265 ( V_12 , V_24 ) ;
if ( ! V_28 )
return 0 ;
V_465 = V_221 & 0xff00 ;
for ( V_17 = 0 ; V_17 < V_486 ; V_17 ++ )
if ( V_469 [ V_17 ] . V_471 == V_465 ) {
if ( V_28 & ( 1 << V_17 ) )
break;
return 0 ;
}
if ( V_17 >= V_486 )
return 0 ;
V_453 = F_268 ( V_12 , V_24 ) ;
if ( ! V_453 )
return 0 ;
if ( V_453 & V_490 ) {
switch ( V_221 & 0xf0 ) {
case 0x00 :
if ( ! ( V_28 & V_491 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_28 & V_493 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_28 & V_498 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_28 & V_499 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_28 & V_496 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_272 ( struct V_451 * V_452 ,
struct V_11 * V_12 ,
struct V_502 * V_503 )
{
return 0 ;
}
static int F_273 ( struct V_451 * V_452 ,
struct V_11 * V_12 ,
unsigned int V_215 ,
unsigned int V_221 ,
struct V_502 * V_503 )
{
F_122 ( V_12 , V_452 -> V_24 , V_215 , 0 , V_221 ) ;
return 0 ;
}
static int F_274 ( struct V_451 * V_452 ,
struct V_11 * V_12 ,
struct V_502 * V_503 )
{
F_275 ( V_12 , V_452 -> V_24 ) ;
return 0 ;
}
static int F_276 ( struct V_11 * V_12 ,
struct V_451 * V_239 )
{
int V_33 ;
if ( V_239 -> V_24 && ( ! V_239 -> V_485 || ! V_239 -> V_488 ) ) {
V_33 = F_270 ( V_12 , V_239 -> V_24 ,
V_239 -> V_485 ? NULL : & V_239 -> V_485 ,
V_239 -> V_488 ? NULL : & V_239 -> V_488 ,
V_239 -> V_467 ? NULL : & V_239 -> V_467 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_239 -> V_9 . V_504 == NULL )
V_239 -> V_9 . V_504 = F_272 ;
if ( V_239 -> V_9 . V_505 == NULL )
V_239 -> V_9 . V_505 = F_272 ;
if ( V_239 -> V_9 . V_506 == NULL ) {
if ( F_43 ( ! V_239 -> V_24 ) )
return - V_59 ;
V_239 -> V_9 . V_506 = F_273 ;
}
if ( V_239 -> V_9 . V_507 == NULL ) {
if ( F_43 ( ! V_239 -> V_24 ) )
return - V_59 ;
V_239 -> V_9 . V_507 = F_274 ;
}
return 0 ;
}
int F_277 ( struct V_11 * V_12 ,
struct V_451 * V_452 ,
unsigned int V_453 ,
unsigned int V_221 ,
struct V_502 * V_503 )
{
int V_274 ;
F_2 ( & V_12 -> V_7 -> V_116 ) ;
V_274 = V_452 -> V_9 . V_506 ( V_452 , V_12 , V_453 , V_221 , V_503 ) ;
if ( V_274 >= 0 )
F_125 ( V_12 ) ;
F_4 ( & V_12 -> V_7 -> V_116 ) ;
return V_274 ;
}
void F_278 ( struct V_11 * V_12 ,
struct V_451 * V_452 ,
struct V_502 * V_503 )
{
F_2 ( & V_12 -> V_7 -> V_116 ) ;
V_452 -> V_9 . V_507 ( V_452 , V_12 , V_503 ) ;
F_4 ( & V_12 -> V_7 -> V_116 ) ;
}
static int F_279 ( struct V_6 * V_7 , int type )
{
static int V_508 [ V_509 ] [ 5 ] = {
[ V_510 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_416 ] = { 1 , - 1 } ,
[ V_415 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_511 ] = { 6 , - 1 } ,
} ;
int V_17 ;
if ( type >= V_509 ) {
F_45 ( V_77 L_84 , type ) ;
return - V_59 ;
}
for ( V_17 = 0 ; V_508 [ type ] [ V_17 ] >= 0 ; V_17 ++ )
if ( ! F_280 ( V_508 [ type ] [ V_17 ] , V_7 -> V_339 ) )
return V_508 [ type ] [ V_17 ] ;
for ( V_17 = 10 ; V_17 < 32 ; V_17 ++ ) {
if ( ! F_280 ( V_17 , V_7 -> V_339 ) )
return V_17 ;
}
F_45 ( V_77 L_85 ,
V_512 [ type ] ) ;
return - V_37 ;
}
static int F_281 ( struct V_11 * V_12 , struct V_330 * V_328 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_451 * V_239 ;
int V_453 , V_33 ;
if ( F_43 ( ! V_328 -> V_132 ) )
return - V_59 ;
for ( V_453 = 0 ; V_453 < 2 ; V_453 ++ ) {
V_239 = & V_328 -> V_453 [ V_453 ] ;
if ( V_239 -> V_459 ) {
V_33 = F_276 ( V_12 , V_239 ) ;
if ( V_33 < 0 )
return V_33 ;
}
}
return V_7 -> V_9 . V_513 ( V_7 , V_12 , V_328 ) ;
}
int F_282 ( struct V_11 * V_12 )
{
unsigned int V_328 ;
int V_33 ;
if ( ! V_12 -> V_329 ) {
if ( ! V_12 -> V_96 . V_514 )
return 0 ;
V_33 = V_12 -> V_96 . V_514 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_86
L_74 , V_12 -> V_29 , V_33 ) ;
V_33 = F_181 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30
L_75 ) ;
return V_33 ;
}
}
}
for ( V_328 = 0 ; V_328 < V_12 -> V_329 ; V_328 ++ ) {
struct V_330 * V_331 = & V_12 -> V_332 [ V_328 ] ;
int V_310 ;
if ( ! V_331 -> V_453 [ 0 ] . V_459 && ! V_331 -> V_453 [ 1 ] . V_459 )
continue;
if ( ! V_331 -> V_328 ) {
V_310 = F_279 ( V_12 -> V_7 , V_331 -> V_515 ) ;
if ( V_310 < 0 )
continue;
V_331 -> V_100 = V_310 ;
V_33 = F_281 ( V_12 , V_331 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_87
L_88 ,
V_310 , V_12 -> V_29 ) ;
continue;
}
}
}
return 0 ;
}
int F_283 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
int V_33 = F_282 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
}
return 0 ;
}
int F_284 ( struct V_11 * V_12 ,
int V_516 , const char * const * V_517 ,
const struct V_518 * V_122 )
{
if ( V_12 -> V_114 && V_517 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_516 ; V_17 ++ ) {
if ( V_517 [ V_17 ] &&
! strcmp ( V_12 -> V_114 , V_517 [ V_17 ] ) ) {
F_21 ( V_519 L_89
L_90 , V_517 [ V_17 ] ) ;
return V_17 ;
}
}
}
if ( ! V_12 -> V_7 -> V_113 || ! V_122 )
return - 1 ;
V_122 = F_285 ( V_12 -> V_7 -> V_113 , V_122 ) ;
if ( ! V_122 )
return - 1 ;
if ( V_122 -> V_286 >= 0 && V_122 -> V_286 < V_516 ) {
#ifdef F_286
char V_136 [ 10 ] ;
const char * V_520 = NULL ;
if ( V_517 )
V_520 = V_517 [ V_122 -> V_286 ] ;
if ( ! V_520 ) {
sprintf ( V_136 , L_91 , V_122 -> V_286 ) ;
V_520 = V_136 ;
}
F_110 ( V_519 L_92
L_93 ,
V_520 , V_122 -> V_521 , V_122 -> V_318 ,
( V_122 -> V_132 ? V_122 -> V_132 : L_94 ) ) ;
#endif
return V_122 -> V_286 ;
}
return - 1 ;
}
int F_287 ( struct V_11 * V_12 ,
int V_516 , const char * const * V_517 ,
const struct V_518 * V_122 )
{
const struct V_518 * V_230 ;
for ( V_230 = V_122 ; V_230 -> V_521 ; V_230 ++ ) {
unsigned int V_68 = 0xffff0000 | V_230 -> V_522 ;
unsigned int V_125 = ( V_230 -> V_318 | ( V_230 -> V_521 << 16 ) ) & V_68 ;
if ( ( V_12 -> V_202 & V_68 ) == V_125 )
break;
}
if ( ! V_230 -> V_521 )
return - 1 ;
V_122 = V_230 ;
if ( V_122 -> V_286 >= 0 && V_122 -> V_286 < V_516 ) {
#ifdef F_286
char V_136 [ 10 ] ;
const char * V_520 = NULL ;
if ( V_517 )
V_520 = V_517 [ V_122 -> V_286 ] ;
if ( ! V_520 ) {
sprintf ( V_136 , L_91 , V_122 -> V_286 ) ;
V_520 = V_136 ;
}
F_110 ( V_519 L_92
L_93 ,
V_520 , V_122 -> V_521 , V_122 -> V_318 ,
( V_122 -> V_132 ? V_122 -> V_132 : L_94 ) ) ;
#endif
return V_122 -> V_286 ;
}
return - 1 ;
}
int F_288 ( struct V_11 * V_12 ,
const struct V_411 * V_523 )
{
int V_33 ;
for (; V_523 -> V_132 ; V_523 ++ ) {
struct V_279 * V_315 ;
int V_29 = 0 , V_237 = 0 ;
if ( V_523 -> V_312 == - 1 )
continue;
for (; ; ) {
V_315 = F_201 ( V_523 , V_12 ) ;
if ( ! V_315 )
return - V_52 ;
if ( V_29 > 0 )
V_315 -> V_125 . V_100 = V_29 ;
if ( V_237 > 0 )
V_315 -> V_125 . V_253 = V_237 ;
V_33 = F_171 ( V_12 , 0 , V_315 ) ;
if ( ! V_33 )
break;
if ( ! V_29 && V_12 -> V_29 )
V_29 = V_12 -> V_29 ;
else if ( ! V_237 && ! V_523 -> V_253 ) {
V_237 = F_170 ( V_12 ,
V_523 -> V_132 , 0 ) ;
if ( V_237 <= 0 )
return V_33 ;
} else
return V_33 ;
}
}
return 0 ;
}
static void V_199 ( struct V_92 * V_91 )
{
struct V_11 * V_12 =
F_54 ( V_91 , struct V_11 , V_175 . V_91 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
unsigned int V_427 ;
F_178 ( & V_12 -> V_198 ) ;
if ( V_12 -> V_336 > 0 ) {
F_179 ( & V_12 -> V_198 ) ;
return;
}
if ( ! V_12 -> V_335 || V_12 -> V_524 ) {
V_12 -> V_336 = 0 ;
F_179 ( & V_12 -> V_198 ) ;
return;
}
F_179 ( & V_12 -> V_198 ) ;
V_427 = F_252 ( V_12 , true ) ;
V_12 -> V_179 = 0 ;
if ( ! V_7 -> V_208 && ( V_427 & V_525 ) ) {
V_12 -> V_179 = 1 ;
F_7 ( V_7 , false ) ;
}
}
static void F_8 ( struct V_11 * V_12 )
{
F_178 ( & V_12 -> V_198 ) ;
V_12 -> V_524 ++ ;
V_12 -> V_335 = 1 ;
V_12 -> V_337 = V_338 ;
F_179 ( & V_12 -> V_198 ) ;
}
void F_253 ( struct V_11 * V_12 )
{
unsigned long V_526 = V_338 - V_12 -> V_337 ;
if ( V_12 -> V_335 )
V_12 -> V_527 += V_526 ;
else
V_12 -> V_528 += V_526 ;
V_12 -> V_337 += V_526 ;
}
static void F_289 ( struct V_11 * V_12 , bool V_529 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
if ( ( V_12 -> V_335 || V_12 -> V_336 > 0 ) &&
! ( V_529 && V_12 -> V_336 < 0 ) )
return;
F_179 ( & V_12 -> V_198 ) ;
F_100 ( & V_12 -> V_175 ) ;
F_178 ( & V_12 -> V_198 ) ;
if ( V_12 -> V_335 ) {
if ( V_12 -> V_336 < 0 )
V_12 -> V_336 = 0 ;
return;
}
F_290 ( V_12 ) ;
F_253 ( V_12 ) ;
V_12 -> V_335 = 1 ;
V_12 -> V_337 = V_338 ;
V_12 -> V_336 = 1 ;
F_179 ( & V_12 -> V_198 ) ;
if ( V_12 -> V_179 ) {
V_12 -> V_179 = 0 ;
F_7 ( V_7 , true ) ;
}
F_256 ( V_12 ) ;
F_178 ( & V_12 -> V_198 ) ;
V_12 -> V_336 = 0 ;
}
static void F_291 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_335 || V_12 -> V_524 || V_12 -> V_336 )
return;
if ( V_115 ( V_12 ) ) {
V_12 -> V_336 = - 1 ;
F_96 ( V_12 -> V_7 -> V_88 , & V_12 -> V_175 ,
F_246 ( V_115 ( V_12 ) * 1000 ) ) ;
}
}
void F_292 ( struct V_11 * V_12 , int V_526 , bool V_530 )
{
F_178 ( & V_12 -> V_198 ) ;
V_12 -> V_524 += V_526 ;
F_293 ( V_12 ) ;
if ( V_526 > 0 )
F_289 ( V_12 , V_530 ) ;
else
F_291 ( V_12 ) ;
F_179 ( & V_12 -> V_198 ) ;
}
int F_294 ( struct V_11 * V_12 ,
struct V_531 * V_532 ,
T_2 V_24 )
{
const struct V_533 * V_49 ;
int V_252 , V_534 ;
if ( ! V_532 -> V_535 )
return 0 ;
for ( V_49 = V_532 -> V_535 ; V_49 -> V_24 ; V_49 ++ ) {
if ( V_49 -> V_24 == V_24 )
break;
}
if ( ! V_49 -> V_24 )
return 0 ;
for ( V_49 = V_532 -> V_535 ; V_49 -> V_24 ; V_49 ++ ) {
for ( V_252 = 0 ; V_252 < 2 ; V_252 ++ ) {
V_534 = F_144 ( V_12 , V_49 -> V_24 , V_252 , V_49 -> V_249 ,
V_49 -> V_237 ) ;
if ( ! ( V_534 & V_268 ) && V_534 > 0 ) {
if ( ! V_532 -> V_335 ) {
V_532 -> V_335 = 1 ;
F_16 ( V_12 ) ;
}
return 1 ;
}
}
}
if ( V_532 -> V_335 ) {
V_532 -> V_335 = 0 ;
F_19 ( V_12 ) ;
}
return 0 ;
}
int F_295 ( struct V_11 * V_12 ,
struct V_281 * V_282 ,
const struct V_536 * V_537 ,
int V_538 )
{
V_282 -> type = V_363 ;
V_282 -> V_285 = 1 ;
V_282 -> V_286 . V_364 . V_323 = V_538 ;
if ( V_282 -> V_286 . V_364 . V_317 >= V_538 )
V_282 -> V_286 . V_364 . V_317 = V_538 - 1 ;
sprintf ( V_282 -> V_286 . V_364 . V_132 , L_95 ,
V_537 [ V_282 -> V_286 . V_364 . V_317 ] . V_466 ) ;
return 0 ;
}
int F_296 ( struct V_11 * V_12 ,
struct V_291 * V_292 ,
const struct V_536 * V_537 ,
int V_538 ,
int V_539 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_538 ; V_17 ++ ) {
if ( V_539 == V_537 [ V_17 ] . V_466 ) {
V_292 -> V_286 . V_364 . V_317 [ 0 ] = V_17 ;
break;
}
}
return 0 ;
}
int F_297 ( struct V_11 * V_12 ,
struct V_291 * V_292 ,
const struct V_536 * V_537 ,
int V_538 ,
int * V_540 )
{
unsigned int V_541 ;
V_541 = V_292 -> V_286 . V_364 . V_317 [ 0 ] ;
if ( V_541 >= V_538 )
return - V_59 ;
if ( * V_540 == V_537 [ V_541 ] . V_466 )
return 0 ;
* V_540 = V_537 [ V_541 ] . V_466 ;
if ( V_537 [ V_541 ] . V_542 )
F_242 ( V_12 , V_537 [ V_541 ] . V_542 ) ;
return 1 ;
}
int F_298 ( const struct V_543 * V_544 ,
struct V_281 * V_282 )
{
unsigned int V_253 ;
V_282 -> type = V_363 ;
V_282 -> V_285 = 1 ;
V_282 -> V_286 . V_364 . V_323 = V_544 -> V_545 ;
if ( ! V_544 -> V_545 )
return 0 ;
V_253 = V_282 -> V_286 . V_364 . V_317 ;
if ( V_253 >= V_544 -> V_545 )
V_253 = V_544 -> V_545 - 1 ;
strcpy ( V_282 -> V_286 . V_364 . V_132 , V_544 -> V_323 [ V_253 ] . V_546 ) ;
return 0 ;
}
int F_299 ( struct V_11 * V_12 ,
const struct V_543 * V_544 ,
struct V_291 * V_292 ,
T_2 V_24 ,
unsigned int * V_547 )
{
unsigned int V_237 ;
if ( ! V_544 -> V_545 )
return 0 ;
V_237 = V_292 -> V_286 . V_364 . V_317 [ 0 ] ;
if ( V_237 >= V_544 -> V_545 )
V_237 = V_544 -> V_545 - 1 ;
if ( * V_547 == V_237 )
return 0 ;
F_220 ( V_12 , V_24 , 0 , V_548 ,
V_544 -> V_323 [ V_237 ] . V_253 ) ;
* V_547 = V_237 ;
return 1 ;
}
int F_300 ( struct V_279 * V_280 ,
struct V_281 * V_282 ,
int V_545 , const char * const * V_362 )
{
static const char * const V_549 [] = {
L_96 , L_97
} ;
if ( ! V_362 || ! V_545 ) {
V_545 = 2 ;
V_362 = V_549 ;
}
V_282 -> type = V_363 ;
V_282 -> V_285 = 1 ;
V_282 -> V_286 . V_364 . V_323 = V_545 ;
if ( V_282 -> V_286 . V_364 . V_317 >= V_282 -> V_286 . V_364 . V_323 )
V_282 -> V_286 . V_364 . V_317 = V_282 -> V_286 . V_364 . V_323 - 1 ;
strcpy ( V_282 -> V_286 . V_364 . V_132 ,
V_362 [ V_282 -> V_286 . V_364 . V_317 ] ) ;
return 0 ;
}
static void F_301 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_215 , unsigned int V_221 )
{
struct V_194 * V_392 ;
unsigned int V_550 ;
bool V_551 ;
V_392 = F_227 ( V_12 , V_24 ) ;
V_550 = F_23 ( V_12 , V_24 , 0 ,
V_223 , 0 ) ;
V_551 = V_12 -> V_343 &&
( V_392 -> V_406 & V_407 ) &&
V_550 != V_221 ;
if ( V_551 )
F_221 ( V_12 , V_24 ,
V_392 -> V_406 & ~ V_407 & 0xff ,
- 1 ) ;
F_122 ( V_12 , V_24 , V_215 , 0 , V_221 ) ;
if ( V_12 -> V_342 ) {
const T_2 * V_401 ;
for ( V_401 = V_12 -> V_342 ; * V_401 ; V_401 ++ )
F_122 ( V_12 , * V_401 , V_215 , 0 ,
V_221 ) ;
}
if ( V_551 )
F_221 ( V_12 , V_24 ,
V_392 -> V_406 & 0xff , - 1 ) ;
}
static void F_302 ( struct V_11 * V_12 , T_2 V_24 )
{
F_275 ( V_12 , V_24 ) ;
if ( V_12 -> V_342 ) {
const T_2 * V_401 ;
for ( V_401 = V_12 -> V_342 ; * V_401 ; V_401 ++ )
F_275 ( V_12 , * V_401 ) ;
}
}
void F_303 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
if ( ! V_7 )
return;
F_29 (codec, &bus->codec_list, list) {
if ( F_304 ( V_12 ) &&
V_12 -> V_96 . V_552 )
V_12 -> V_96 . V_552 ( V_12 ) ;
}
}
int F_305 ( struct V_11 * V_12 ,
struct V_419 * V_420 )
{
F_2 ( & V_12 -> V_188 ) ;
if ( V_420 -> V_553 == V_554 )
F_302 ( V_12 , V_420 -> V_422 ) ;
V_420 -> V_553 = V_555 ;
F_4 ( & V_12 -> V_188 ) ;
return 0 ;
}
int F_306 ( struct V_11 * V_12 ,
struct V_419 * V_420 ,
unsigned int V_215 ,
unsigned int V_221 ,
struct V_502 * V_503 )
{
F_2 ( & V_12 -> V_188 ) ;
F_301 ( V_12 , V_420 -> V_422 , V_215 , V_221 ) ;
F_4 ( & V_12 -> V_188 ) ;
return 0 ;
}
int F_307 ( struct V_11 * V_12 ,
struct V_419 * V_420 )
{
F_2 ( & V_12 -> V_188 ) ;
F_302 ( V_12 , V_420 -> V_422 ) ;
F_4 ( & V_12 -> V_188 ) ;
return 0 ;
}
int F_308 ( struct V_11 * V_12 ,
struct V_419 * V_420 )
{
F_2 ( & V_12 -> V_188 ) ;
V_420 -> V_553 = 0 ;
F_4 ( & V_12 -> V_188 ) ;
return 0 ;
}
int F_309 ( struct V_11 * V_12 ,
struct V_419 * V_420 ,
struct V_502 * V_503 ,
struct V_451 * V_452 )
{
struct V_556 * V_557 = V_503 -> V_557 ;
V_557 -> V_558 . V_461 = V_420 -> V_539 ;
if ( V_420 -> V_422 ) {
if ( ! V_420 -> V_559 ) {
V_420 -> V_559 = V_452 -> V_485 ;
V_420 -> V_560 = V_452 -> V_488 ;
V_420 -> V_561 = V_452 -> V_467 ;
} else {
V_557 -> V_558 . V_485 = V_420 -> V_559 ;
V_557 -> V_558 . V_488 = V_420 -> V_560 ;
V_452 -> V_467 = V_420 -> V_561 ;
}
if ( ! V_420 -> V_562 ) {
F_270 ( V_12 , V_420 -> V_422 ,
& V_420 -> V_562 ,
& V_420 -> V_563 ,
& V_420 -> V_564 ) ;
}
F_2 ( & V_12 -> V_188 ) ;
if ( V_420 -> V_421 ) {
if ( ( V_557 -> V_558 . V_485 & V_420 -> V_562 ) &&
( V_557 -> V_558 . V_488 & V_420 -> V_563 ) ) {
V_557 -> V_558 . V_485 &= V_420 -> V_562 ;
V_557 -> V_558 . V_488 &= V_420 -> V_563 ;
if ( V_420 -> V_564 < V_452 -> V_467 )
V_452 -> V_467 = V_420 -> V_564 ;
} else {
V_420 -> V_421 = 0 ;
}
}
F_4 ( & V_12 -> V_188 ) ;
}
return F_310 ( V_503 -> V_557 , 0 ,
V_565 , 2 ) ;
}
int F_311 ( struct V_11 * V_12 ,
struct V_419 * V_420 ,
unsigned int V_215 ,
unsigned int V_221 ,
struct V_502 * V_503 )
{
const T_2 * V_177 = V_420 -> V_566 ;
int V_283 = V_503 -> V_557 -> V_466 ;
struct V_194 * V_392 ;
int V_17 ;
F_2 ( & V_12 -> V_188 ) ;
V_392 = F_227 ( V_12 , V_420 -> V_422 ) ;
if ( V_420 -> V_422 && V_420 -> V_421 &&
V_420 -> V_553 != V_555 ) {
if ( V_283 == 2 &&
F_271 ( V_12 , V_420 -> V_422 ,
V_221 ) &&
! ( V_392 -> V_384 & V_386 ) ) {
V_420 -> V_553 = V_554 ;
F_301 ( V_12 , V_420 -> V_422 ,
V_215 , V_221 ) ;
} else {
V_420 -> V_553 = 0 ;
F_302 ( V_12 , V_420 -> V_422 ) ;
}
}
F_4 ( & V_12 -> V_188 ) ;
F_122 ( V_12 , V_177 [ V_567 ] , V_215 ,
0 , V_221 ) ;
if ( ! V_420 -> V_568 &&
V_420 -> V_569 && V_420 -> V_569 != V_177 [ V_567 ] )
F_122 ( V_12 , V_420 -> V_569 , V_215 ,
0 , V_221 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_420 -> V_570 ) ; V_17 ++ )
if ( ! V_420 -> V_568 && V_420 -> V_570 [ V_17 ] )
F_122 ( V_12 ,
V_420 -> V_570 [ V_17 ] ,
V_215 , 0 , V_221 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_420 -> V_571 ) ; V_17 ++ )
if ( ! V_420 -> V_568 && V_420 -> V_571 [ V_17 ] )
F_122 ( V_12 ,
V_420 -> V_571 [ V_17 ] ,
V_215 , 0 , V_221 ) ;
for ( V_17 = 1 ; V_17 < V_420 -> V_572 ; V_17 ++ ) {
if ( V_283 >= ( V_17 + 1 ) * 2 )
F_122 ( V_12 , V_177 [ V_17 ] , V_215 ,
V_17 * 2 , V_221 ) ;
else if ( ! V_420 -> V_568 )
F_122 ( V_12 , V_177 [ V_17 ] , V_215 ,
0 , V_221 ) ;
}
return 0 ;
}
int F_312 ( struct V_11 * V_12 ,
struct V_419 * V_420 )
{
const T_2 * V_177 = V_420 -> V_566 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_420 -> V_572 ; V_17 ++ )
F_275 ( V_12 , V_177 [ V_17 ] ) ;
if ( V_420 -> V_569 )
F_275 ( V_12 , V_420 -> V_569 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_420 -> V_570 ) ; V_17 ++ )
if ( V_420 -> V_570 [ V_17 ] )
F_275 ( V_12 ,
V_420 -> V_570 [ V_17 ] ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_420 -> V_571 ) ; V_17 ++ )
if ( V_420 -> V_571 [ V_17 ] )
F_275 ( V_12 ,
V_420 -> V_571 [ V_17 ] ) ;
F_2 ( & V_12 -> V_188 ) ;
if ( V_420 -> V_422 && V_420 -> V_553 == V_554 ) {
F_302 ( V_12 , V_420 -> V_422 ) ;
V_420 -> V_553 = 0 ;
}
F_4 ( & V_12 -> V_188 ) ;
return 0 ;
}
unsigned int F_313 ( struct V_11 * V_12 , T_2 V_156 )
{
unsigned int V_573 ;
unsigned int V_217 ;
V_217 = F_23 ( V_12 , V_156 , 0 ,
V_161 , 0 ) ;
V_573 = F_138 ( V_12 , V_156 ) ;
V_573 = ( V_573 & V_574 ) >> V_575 ;
if ( ( V_573 & V_576 ) && V_217 != V_577 )
return V_578 ;
else if ( V_573 & V_579 )
return V_580 ;
else if ( V_573 & V_581 )
return V_582 ;
else if ( V_573 & V_583 )
return V_584 ;
return V_585 ;
}
unsigned int F_314 ( struct V_11 * V_12 ,
T_2 V_156 , unsigned int V_28 )
{
static unsigned int V_586 [] [ 2 ] = {
{ V_582 , V_581 } ,
{ V_578 , V_576 } ,
{ V_580 , V_579 } ,
{ V_584 , V_583 } ,
} ;
unsigned int V_587 ;
if ( ! V_28 )
return 0 ;
V_587 = F_138 ( V_12 , V_156 ) ;
if ( ! V_587 )
return V_28 ;
if ( V_28 & V_588 ) {
if ( ! ( V_587 & V_589 ) )
V_28 &= ~ ( V_588 | V_590 ) ;
else if ( ( V_28 & V_590 ) && ! ( V_587 & V_591 ) )
V_28 &= ~ V_590 ;
}
if ( V_28 & V_592 ) {
if ( ! ( V_587 & V_593 ) )
V_28 &= ~ ( V_592 | V_594 ) ;
else {
unsigned int V_595 , V_596 ;
int V_17 ;
V_595 = ( V_587 & V_574 ) >> V_575 ;
V_596 = V_28 & V_594 ;
for ( V_17 = 0 ; V_17 < F_10 ( V_586 ) ; V_17 ++ ) {
if ( V_596 == V_586 [ V_17 ] [ 0 ] &&
! ( V_595 & V_586 [ V_17 ] [ 1 ] ) ) {
if ( V_17 == F_10 ( V_586 ) - 1 )
V_596 = V_585 ;
else
V_596 = V_586 [ V_17 + 1 ] [ 0 ] ;
}
}
V_28 &= ~ V_594 ;
V_28 |= V_596 ;
}
}
return V_28 ;
}
int F_315 ( struct V_11 * V_12 , T_2 V_156 ,
unsigned int V_28 , bool V_597 )
{
V_28 = F_314 ( V_12 , V_156 , V_28 ) ;
F_89 ( V_12 , V_156 , V_28 ) ;
if ( V_597 )
return F_238 ( V_12 , V_156 , 0 ,
V_169 , V_28 ) ;
else
return F_24 ( V_12 , V_156 , 0 ,
V_169 , V_28 ) ;
}
int F_316 ( struct V_543 * V_544 , const char * V_546 ,
int V_253 , int * V_598 )
{
int V_17 , V_599 = 0 ;
if ( V_544 -> V_545 >= V_600 ) {
F_21 ( V_30 L_98 ) ;
return - V_59 ;
}
for ( V_17 = 0 ; V_17 < V_544 -> V_545 ; V_17 ++ ) {
if ( ! strncmp ( V_546 , V_544 -> V_323 [ V_17 ] . V_546 , strlen ( V_546 ) ) )
V_599 ++ ;
}
if ( V_598 )
* V_598 = V_599 ;
if ( V_599 > 0 )
snprintf ( V_544 -> V_323 [ V_544 -> V_545 ] . V_546 ,
sizeof( V_544 -> V_323 [ V_544 -> V_545 ] . V_546 ) ,
L_99 , V_546 , V_599 ) ;
else
F_317 ( V_544 -> V_323 [ V_544 -> V_545 ] . V_546 , V_546 ,
sizeof( V_544 -> V_323 [ V_544 -> V_545 ] . V_546 ) ) ;
V_544 -> V_323 [ V_544 -> V_545 ] . V_253 = V_253 ;
V_544 -> V_545 ++ ;
return 0 ;
}
int F_318 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
F_100 ( & V_12 -> V_171 ) ;
if ( F_304 ( V_12 ) )
F_252 ( V_12 , false ) ;
}
return 0 ;
}
int F_319 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
F_256 ( V_12 ) ;
}
return 0 ;
}
void * F_82 ( struct V_162 * V_163 )
{
if ( F_43 ( ! V_163 -> V_601 ) )
return NULL ;
if ( V_163 -> V_164 >= V_163 -> V_602 ) {
int V_603 = V_163 -> V_602 + V_163 -> V_604 ;
int V_296 = ( V_603 + 1 ) * V_163 -> V_601 ;
void * V_605 ;
if ( F_43 ( V_603 >= 4096 ) )
return NULL ;
V_605 = F_320 ( V_163 -> V_4 , V_296 , V_51 | V_606 ) ;
if ( ! V_605 )
return NULL ;
V_163 -> V_4 = V_605 ;
V_163 -> V_602 = V_603 ;
}
return F_84 ( V_163 , V_163 -> V_164 ++ ) ;
}
void F_98 ( struct V_162 * V_163 )
{
F_37 ( V_163 -> V_4 ) ;
V_163 -> V_164 = 0 ;
V_163 -> V_602 = 0 ;
V_163 -> V_4 = NULL ;
}
void F_321 ( int V_328 , char * V_235 , int V_607 )
{
static unsigned int V_608 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_17 , V_609 ;
for ( V_17 = 0 , V_609 = 0 ; V_17 < F_10 ( V_608 ) ; V_17 ++ )
if ( V_328 & ( V_491 << V_17 ) )
V_609 += snprintf ( V_235 + V_609 , V_607 - V_609 , L_100 , V_608 [ V_17 ] ) ;
V_235 [ V_609 ] = '\0' ;
}
