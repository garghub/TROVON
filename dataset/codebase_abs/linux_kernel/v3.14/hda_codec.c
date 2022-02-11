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
static void F_7 ( struct V_6 * V_7 , bool V_8 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
if ( ( V_8 && V_7 -> V_11 ) ||
( ! V_8 && ! V_7 -> V_11 ) )
return;
if ( V_10 -> V_12 . V_13 )
V_10 -> V_12 . V_13 ( V_10 , V_8 ) ;
V_7 -> V_11 = V_8 ;
}
static inline void F_8 ( struct V_6 * V_7 ) {}
const char * F_9 ( T_1 V_14 )
{
static char * V_15 [ 7 ] = {
L_1 , L_2 , L_3 , L_4 , L_5 , L_6 , L_7 ,
} ;
static unsigned char V_16 [] = {
0x07 , 0x08 ,
0x17 , 0x18 , 0x19 ,
0x37 , 0x38
} ;
static char * V_17 [] = {
L_8 , L_9 ,
L_10 , L_11 , L_12 ,
L_13 , L_14
} ;
int V_18 ;
V_14 = ( V_14 & V_19 ) >> V_20 ;
if ( ( V_14 & 0x0f ) < 7 )
return V_15 [ V_14 & 0x0f ] ;
for ( V_18 = 0 ; V_18 < F_10 ( V_16 ) ; V_18 ++ ) {
if ( V_14 == V_16 [ V_18 ] )
return V_17 [ V_18 ] ;
}
return L_15 ;
}
const char * F_11 ( T_1 V_14 )
{
static char * V_21 [ 4 ] = { L_16 , L_17 , L_18 , L_19 } ;
return V_21 [ ( V_14 >> ( V_20 + 4 ) ) & 3 ] ;
}
const char * F_12 ( T_1 V_14 )
{
static char * V_22 [ 16 ] = {
L_20 , L_21 , L_22 , L_23 ,
L_24 , L_25 , L_26 , L_27 ,
L_28 , L_29 , L_30 , L_31 ,
L_32 , L_33 , L_34 , L_35
} ;
return V_22 [ ( V_14 & V_23 )
>> V_24 ] ;
}
static inline unsigned int
F_13 ( struct V_6 * V_7 , T_2 V_25 , int V_26 ,
unsigned int V_27 , unsigned int V_28 )
{
T_1 V_29 ;
if ( ( V_7 -> V_30 & ~ 0xf ) || ( V_25 & ~ 0x7f ) ||
( V_27 & ~ 0xfff ) || ( V_28 & ~ 0xffff ) ) {
F_14 ( V_31 L_36 ,
V_7 -> V_30 , V_25 , V_27 , V_28 ) ;
return ~ 0 ;
}
V_29 = ( T_1 ) V_7 -> V_30 << 28 ;
V_29 |= ( T_1 ) V_25 << 20 ;
V_29 |= V_27 << 8 ;
V_29 |= V_28 ;
return V_29 ;
}
static int F_15 ( struct V_6 * V_7 , unsigned int V_32 ,
int V_26 , unsigned int * V_33 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
int V_34 ;
if ( V_32 == ~ 0 )
return - 1 ;
if ( V_33 )
* V_33 = - 1 ;
V_35:
F_16 ( V_7 ) ;
F_2 ( & V_10 -> V_36 ) ;
if ( V_26 & V_37 )
V_10 -> V_38 = 1 ;
for (; ; ) {
F_17 ( V_7 , V_32 ) ;
V_34 = V_10 -> V_12 . V_39 ( V_10 , V_32 ) ;
if ( V_34 != - V_40 )
break;
V_10 -> V_12 . V_41 ( V_10 , V_7 -> V_30 ) ;
}
if ( ! V_34 && V_33 ) {
* V_33 = V_10 -> V_12 . V_41 ( V_10 , V_7 -> V_30 ) ;
F_18 ( V_7 , * V_33 ) ;
}
V_10 -> V_38 = 0 ;
F_4 ( & V_10 -> V_36 ) ;
F_19 ( V_7 ) ;
if ( ! F_20 ( V_7 ) && V_33 && * V_33 == - 1 && V_10 -> V_42 ) {
if ( V_10 -> V_43 ) {
F_21 ( L_37
L_38 ) ;
F_22 ( V_10 ) ;
V_10 -> V_12 . V_44 ( V_10 ) ;
}
goto V_35;
}
if ( ! V_34 || F_20 ( V_7 ) )
V_10 -> V_43 = 0 ;
return V_34 ;
}
unsigned int F_23 ( struct V_6 * V_7 , T_2 V_25 ,
int V_26 ,
unsigned int V_27 , unsigned int V_28 )
{
unsigned V_32 = F_13 ( V_7 , V_25 , V_26 , V_27 , V_28 ) ;
unsigned int V_33 ;
if ( F_15 ( V_7 , V_32 , V_26 , & V_33 ) )
return - 1 ;
return V_33 ;
}
int F_24 ( struct V_6 * V_7 , T_2 V_25 , int V_26 ,
unsigned int V_27 , unsigned int V_28 )
{
unsigned int V_32 = F_13 ( V_7 , V_25 , V_26 , V_27 , V_28 ) ;
unsigned int V_33 ;
return F_15 ( V_7 , V_32 , V_26 ,
V_7 -> V_10 -> V_45 ? & V_33 : NULL ) ;
}
void F_25 ( struct V_6 * V_7 , const struct V_46 * V_47 )
{
for (; V_47 -> V_25 ; V_47 ++ )
F_24 ( V_7 , V_47 -> V_25 , 0 , V_47 -> V_27 , V_47 -> V_48 ) ;
}
int F_26 ( struct V_6 * V_7 , T_2 V_25 ,
T_2 * V_49 )
{
unsigned int V_28 ;
V_28 = F_27 ( V_7 , V_25 , V_50 ) ;
if ( V_28 == - 1 )
return 0 ;
* V_49 = ( V_28 >> 16 ) & 0x7fff ;
return ( int ) ( V_28 & 0x7fff ) ;
}
static struct V_51 *
F_28 ( struct V_6 * V_7 , T_2 V_25 )
{
struct V_51 * V_52 ;
F_29 (p, &codec->conn_list, list) {
if ( V_52 -> V_25 == V_25 )
return V_52 ;
}
return NULL ;
}
static int F_30 ( struct V_6 * V_7 , T_2 V_25 , int V_53 ,
const T_2 * V_4 )
{
struct V_51 * V_52 ;
V_52 = F_31 ( sizeof( * V_52 ) + V_53 * sizeof( T_2 ) , V_54 ) ;
if ( ! V_52 )
return - V_55 ;
V_52 -> V_53 = V_53 ;
V_52 -> V_25 = V_25 ;
memcpy ( V_52 -> V_56 , V_4 , V_53 * sizeof( T_2 ) ) ;
F_32 ( & V_52 -> V_4 , & V_7 -> V_57 ) ;
return 0 ;
}
static void F_33 ( struct V_6 * V_7 )
{
while ( ! F_34 ( & V_7 -> V_57 ) ) {
struct V_51 * V_52 ;
V_52 = F_35 ( & V_7 -> V_57 , F_36 ( * V_52 ) , V_4 ) ;
F_6 ( & V_52 -> V_4 ) ;
F_37 ( V_52 ) ;
}
}
static int F_38 ( struct V_6 * V_7 , T_2 V_25 )
{
T_2 V_4 [ 32 ] ;
T_2 * V_58 = V_4 ;
int V_53 ;
V_53 = F_39 ( V_7 , V_25 , V_4 , F_10 ( V_4 ) ) ;
if ( V_53 == - V_59 ) {
V_53 = F_40 ( V_7 , V_25 ) ;
V_58 = F_31 ( sizeof( T_2 ) * V_53 , V_54 ) ;
if ( ! V_58 )
return - V_55 ;
V_53 = F_39 ( V_7 , V_25 , V_58 , V_53 ) ;
}
if ( V_53 >= 0 )
V_53 = F_41 ( V_7 , V_25 , V_53 , V_58 ) ;
if ( V_58 != V_4 )
F_37 ( V_58 ) ;
return V_53 ;
}
int F_42 ( struct V_6 * V_7 , T_2 V_25 ,
const T_2 * * V_60 )
{
bool V_61 = false ;
for (; ; ) {
int V_34 ;
const struct V_51 * V_52 ;
V_52 = F_28 ( V_7 , V_25 ) ;
if ( V_52 ) {
if ( V_60 )
* V_60 = V_52 -> V_56 ;
return V_52 -> V_53 ;
}
if ( F_43 ( V_61 ) )
return - V_62 ;
V_34 = F_38 ( V_7 , V_25 ) ;
if ( V_34 < 0 )
return V_34 ;
V_61 = true ;
}
}
int F_44 ( struct V_6 * V_7 , T_2 V_25 ,
T_2 * V_57 , int V_63 )
{
const T_2 * V_4 ;
int V_53 = F_42 ( V_7 , V_25 , & V_4 ) ;
if ( V_53 > 0 && V_57 ) {
if ( V_53 > V_63 ) {
F_45 ( V_31 L_39
L_40 ,
V_53 , V_25 ) ;
return - V_62 ;
}
memcpy ( V_57 , V_4 , V_53 * sizeof( T_2 ) ) ;
}
return V_53 ;
}
static unsigned int F_46 ( struct V_6 * V_7 , T_2 V_25 )
{
unsigned int V_64 = F_47 ( V_7 , V_25 ) ;
unsigned int V_28 ;
if ( ! ( V_64 & V_65 ) &&
F_48 ( V_64 ) != V_66 )
return 0 ;
V_28 = F_27 ( V_7 , V_25 , V_67 ) ;
if ( V_28 == - 1 )
V_28 = 0 ;
return V_28 ;
}
int F_40 ( struct V_6 * V_7 , T_2 V_25 )
{
return F_39 ( V_7 , V_25 , NULL , 0 ) ;
}
int F_39 ( struct V_6 * V_7 , T_2 V_25 ,
T_2 * V_57 , int V_63 )
{
unsigned int V_28 ;
int V_18 , V_68 , V_56 ;
unsigned int V_69 , V_70 , V_71 ;
T_2 V_72 ;
int V_73 = 0 ;
V_28 = F_46 ( V_7 , V_25 ) ;
if ( ! V_28 )
return 0 ;
if ( V_28 & V_74 ) {
V_69 = 16 ;
V_70 = 2 ;
} else {
V_69 = 8 ;
V_70 = 4 ;
}
V_68 = V_28 & V_75 ;
V_71 = ( 1 << ( V_69 - 1 ) ) - 1 ;
if ( ! V_68 )
return 0 ;
if ( V_68 == 1 ) {
V_28 = F_23 ( V_7 , V_25 , 0 ,
V_76 , 0 ) ;
if ( V_28 == - 1 && V_7 -> V_10 -> V_42 )
return - V_77 ;
if ( V_57 )
V_57 [ 0 ] = V_28 & V_71 ;
return 1 ;
}
V_56 = 0 ;
V_72 = 0 ;
for ( V_18 = 0 ; V_18 < V_68 ; V_18 ++ ) {
int V_78 ;
T_2 V_29 , V_79 ;
if ( V_18 % V_70 == 0 ) {
V_28 = F_23 ( V_7 , V_25 , 0 ,
V_76 , V_18 ) ;
if ( V_28 == - 1 && V_7 -> V_10 -> V_42 )
return - V_77 ;
}
V_78 = ! ! ( V_28 & ( 1 << ( V_69 - 1 ) ) ) ;
V_29 = V_28 & V_71 ;
if ( V_29 == 0 && V_73 ++ ) {
F_49 ( L_39
L_41 ,
V_25 , V_18 , V_28 ) ;
return 0 ;
}
V_28 >>= V_69 ;
if ( V_78 ) {
if ( ! V_72 || V_72 >= V_29 ) {
F_45 ( V_80 L_39
L_42 ,
V_72 , V_29 ) ;
continue;
}
for ( V_79 = V_72 + 1 ; V_79 <= V_29 ; V_79 ++ ) {
if ( V_57 ) {
if ( V_56 >= V_63 )
return - V_59 ;
V_57 [ V_56 ] = V_79 ;
}
V_56 ++ ;
}
} else {
if ( V_57 ) {
if ( V_56 >= V_63 )
return - V_59 ;
V_57 [ V_56 ] = V_29 ;
}
V_56 ++ ;
}
V_72 = V_29 ;
}
return V_56 ;
}
int F_41 ( struct V_6 * V_7 , T_2 V_25 , int V_53 ,
const T_2 * V_4 )
{
struct V_51 * V_52 ;
V_52 = F_28 ( V_7 , V_25 ) ;
if ( V_52 ) {
F_6 ( & V_52 -> V_4 ) ;
F_37 ( V_52 ) ;
}
return F_30 ( V_7 , V_25 , V_53 , V_4 ) ;
}
int F_50 ( struct V_6 * V_7 , T_2 V_81 ,
T_2 V_25 , int V_82 )
{
const T_2 * V_83 ;
int V_18 , V_84 ;
V_84 = F_42 ( V_7 , V_81 , & V_83 ) ;
for ( V_18 = 0 ; V_18 < V_84 ; V_18 ++ )
if ( V_83 [ V_18 ] == V_25 )
return V_18 ;
if ( ! V_82 )
return - 1 ;
if ( V_82 > 10 ) {
F_21 ( L_43 , V_25 ) ;
return - 1 ;
}
V_82 ++ ;
for ( V_18 = 0 ; V_18 < V_84 ; V_18 ++ ) {
unsigned int type = F_48 ( F_47 ( V_7 , V_83 [ V_18 ] ) ) ;
if ( type == V_85 || type == V_86 )
continue;
if ( F_50 ( V_7 , V_83 [ V_18 ] , V_25 , V_82 ) >= 0 )
return V_18 ;
}
return - 1 ;
}
static unsigned int F_51 ( struct V_6 * V_7 , T_2 V_25 )
{
unsigned int V_64 = F_47 ( V_7 , V_25 ) ;
unsigned int V_28 ;
if ( ! V_7 -> V_87 || ! ( V_64 & V_88 ) ||
F_48 ( V_64 ) != V_85 )
return 0 ;
V_28 = F_27 ( V_7 , V_25 , V_89 ) ;
if ( V_28 == - 1 && V_7 -> V_10 -> V_42 )
V_28 = 0 ;
return V_28 & V_90 ;
}
int F_52 ( struct V_6 * V_7 , T_2 V_25 ,
T_3 * V_91 , int V_92 )
{
unsigned int V_28 ;
int V_18 , V_93 , V_94 ;
V_28 = F_51 ( V_7 , V_25 ) ;
if ( ! V_28 )
return 0 ;
V_93 = V_28 + 1 ;
V_93 = V_93 < V_92 ? V_93 : V_92 ;
V_94 = 0 ;
while ( V_94 < V_93 ) {
V_28 = F_23 ( V_7 , V_25 , 0 ,
V_95 , V_94 ) ;
if ( V_28 == - 1 && V_7 -> V_10 -> V_42 )
break;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
V_91 [ V_94 ] = ( T_3 ) V_28 ;
V_28 >>= 4 ;
V_94 ++ ;
if ( V_94 >= V_93 )
break;
}
}
return V_94 ;
}
int F_53 ( struct V_9 * V_10 , T_1 V_33 , T_1 V_96 )
{
struct V_97 * V_98 ;
unsigned int V_99 ;
if ( ! V_10 || ! V_10 -> V_100 )
return 0 ;
F_54 ( V_10 , V_33 , V_96 ) ;
V_98 = V_10 -> V_98 ;
if ( ! V_98 )
return 0 ;
V_99 = ( V_98 -> V_99 + 1 ) % V_101 ;
V_98 -> V_99 = V_99 ;
V_99 <<= 1 ;
V_98 -> V_102 [ V_99 ] = V_33 ;
V_98 -> V_102 [ V_99 + 1 ] = V_96 ;
F_55 ( V_10 -> V_100 , & V_98 -> V_103 ) ;
return 0 ;
}
static void F_56 ( struct V_104 * V_103 )
{
struct V_97 * V_98 =
F_57 ( V_103 , struct V_97 , V_103 ) ;
struct V_9 * V_10 = V_98 -> V_10 ;
struct V_6 * V_7 ;
unsigned int V_105 , V_106 , V_33 ;
while ( V_98 -> V_105 != V_98 -> V_99 ) {
V_105 = ( V_98 -> V_105 + 1 ) % V_101 ;
V_98 -> V_105 = V_105 ;
V_105 <<= 1 ;
V_33 = V_98 -> V_102 [ V_105 ] ;
V_106 = V_98 -> V_102 [ V_105 + 1 ] ;
if ( ! ( V_106 & ( 1 << 4 ) ) )
continue;
V_7 = V_10 -> V_107 [ V_106 & 0x0f ] ;
if ( V_7 && V_7 -> V_108 . V_109 )
V_7 -> V_108 . V_109 ( V_7 , V_33 ) ;
}
}
static int F_58 ( struct V_9 * V_10 )
{
struct V_97 * V_98 ;
if ( V_10 -> V_98 )
return 0 ;
V_98 = F_59 ( sizeof( * V_98 ) , V_54 ) ;
if ( ! V_98 ) {
F_45 ( V_31 L_39
L_44 ) ;
return - V_55 ;
}
F_60 ( & V_98 -> V_103 , F_56 ) ;
V_98 -> V_10 = V_10 ;
V_10 -> V_98 = V_98 ;
return 0 ;
}
static int F_61 ( struct V_9 * V_10 )
{
struct V_6 * V_7 , * V_79 ;
if ( ! V_10 )
return 0 ;
if ( V_10 -> V_100 )
F_62 ( V_10 -> V_100 ) ;
if ( V_10 -> V_98 )
F_37 ( V_10 -> V_98 ) ;
F_63 (codec, n, &bus->codec_list, list) {
F_64 ( V_7 ) ;
}
if ( V_10 -> V_12 . V_110 )
V_10 -> V_12 . V_110 ( V_10 ) ;
if ( V_10 -> V_100 )
F_65 ( V_10 -> V_100 ) ;
F_37 ( V_10 ) ;
return 0 ;
}
static int F_66 ( struct V_111 * V_112 )
{
struct V_9 * V_10 = V_112 -> V_113 ;
V_10 -> V_114 = 1 ;
return F_61 ( V_10 ) ;
}
static int F_67 ( struct V_111 * V_112 )
{
struct V_9 * V_10 = V_112 -> V_113 ;
struct V_6 * V_7 ;
F_29 (codec, &bus->codec_list, list) {
F_68 ( V_7 ) ;
F_69 ( V_7 ) ;
}
return 0 ;
}
int F_70 ( struct V_115 * V_116 ,
const struct V_117 * V_118 ,
struct V_9 * * V_119 )
{
struct V_9 * V_10 ;
int V_34 ;
static struct V_120 V_121 = {
. V_122 = F_67 ,
. V_123 = F_66 ,
} ;
if ( F_43 ( ! V_118 ) )
return - V_62 ;
if ( F_43 ( ! V_118 -> V_12 . V_39 || ! V_118 -> V_12 . V_41 ) )
return - V_62 ;
if ( V_119 )
* V_119 = NULL ;
V_10 = F_59 ( sizeof( * V_10 ) , V_54 ) ;
if ( V_10 == NULL ) {
F_45 ( V_31 L_45 ) ;
return - V_55 ;
}
V_10 -> V_116 = V_116 ;
V_10 -> V_124 = V_118 -> V_124 ;
V_10 -> V_125 = V_118 -> V_125 ;
V_10 -> V_126 = V_118 -> V_126 ;
V_10 -> V_127 = V_118 -> V_127 ;
V_10 -> V_12 = V_118 -> V_12 ;
F_71 ( & V_10 -> V_36 ) ;
F_71 ( & V_10 -> V_128 ) ;
F_72 ( & V_10 -> V_129 ) ;
snprintf ( V_10 -> V_130 , sizeof( V_10 -> V_130 ) ,
L_46 , V_116 -> V_131 ) ;
V_10 -> V_100 = F_73 ( V_10 -> V_130 ) ;
if ( ! V_10 -> V_100 ) {
F_45 ( V_31 L_47 ,
V_10 -> V_130 ) ;
F_37 ( V_10 ) ;
return - V_55 ;
}
V_34 = F_74 ( V_116 , V_132 , V_10 , & V_121 ) ;
if ( V_34 < 0 ) {
F_61 ( V_10 ) ;
return V_34 ;
}
if ( V_119 )
* V_119 = V_10 ;
return 0 ;
}
static const struct V_133 *
F_75 ( struct V_6 * V_7 )
{
struct V_1 * V_134 ;
const struct V_133 * V_2 ;
unsigned int V_135 = 0 ;
V_35:
F_2 ( & V_3 ) ;
F_29 (tbl, &hda_preset_tables, list) {
if ( ! F_76 ( V_134 -> V_136 ) ) {
F_45 ( V_31 L_48 ) ;
continue;
}
for ( V_2 = V_134 -> V_2 ; V_2 -> V_137 ; V_2 ++ ) {
T_1 V_71 = V_2 -> V_71 ;
if ( V_2 -> V_138 && V_2 -> V_138 != V_7 -> V_138 )
continue;
if ( V_2 -> V_139 && V_2 -> V_139 != V_7 -> V_139 )
continue;
if ( ! V_71 )
V_71 = ~ 0 ;
if ( V_2 -> V_137 == ( V_7 -> V_140 & V_71 ) &&
( ! V_2 -> V_141 ||
V_2 -> V_141 == V_7 -> V_142 ) ) {
F_4 ( & V_3 ) ;
V_7 -> V_136 = V_134 -> V_136 ;
return V_2 ;
}
}
F_77 ( V_134 -> V_136 ) ;
}
F_4 ( & V_3 ) ;
if ( V_135 < V_143 ) {
char V_144 [ 32 ] ;
if ( ! V_135 )
snprintf ( V_144 , sizeof( V_144 ) , L_49 ,
V_7 -> V_140 ) ;
else
snprintf ( V_144 , sizeof( V_144 ) , L_50 ,
( V_7 -> V_140 >> 16 ) & 0xffff ) ;
F_78 ( V_144 ) ;
V_135 ++ ;
goto V_35;
}
return NULL ;
}
static int F_79 ( struct V_6 * V_7 )
{
const struct V_145 * V_146 ;
const char * V_147 = NULL ;
T_4 V_140 = V_7 -> V_140 >> 16 ;
char V_148 [ 16 ] ;
if ( V_7 -> V_149 )
goto V_150;
for ( V_146 = V_151 ; V_146 -> V_137 ; V_146 ++ ) {
if ( V_146 -> V_137 == V_140 ) {
V_147 = V_146 -> V_144 ;
break;
}
}
if ( ! V_147 ) {
sprintf ( V_148 , L_51 , V_140 ) ;
V_147 = V_148 ;
}
V_7 -> V_149 = F_80 ( V_147 , V_54 ) ;
if ( ! V_7 -> V_149 )
return - V_55 ;
V_150:
if ( V_7 -> V_152 )
return 0 ;
if ( V_7 -> V_2 && V_7 -> V_2 -> V_144 )
V_7 -> V_152 = F_80 ( V_7 -> V_2 -> V_144 , V_54 ) ;
else {
sprintf ( V_148 , L_52 , V_7 -> V_140 & 0xffff ) ;
V_7 -> V_152 = F_80 ( V_148 , V_54 ) ;
}
if ( ! V_7 -> V_152 )
return - V_55 ;
return 0 ;
}
static void F_81 ( struct V_6 * V_7 )
{
int V_18 , V_153 , V_154 ;
T_2 V_25 ;
V_153 = F_26 ( V_7 , V_155 , & V_25 ) ;
for ( V_18 = 0 ; V_18 < V_153 ; V_18 ++ , V_25 ++ ) {
V_154 = F_27 ( V_7 , V_25 ,
V_156 ) ;
switch ( V_154 & 0xff ) {
case V_157 :
V_7 -> V_138 = V_25 ;
V_7 -> V_158 = V_154 & 0xff ;
V_7 -> V_159 = ( V_154 >> 8 ) & 1 ;
break;
case V_160 :
V_7 -> V_139 = V_25 ;
V_7 -> V_161 = V_154 & 0xff ;
V_7 -> V_162 = ( V_154 >> 8 ) & 1 ;
break;
default:
break;
}
}
}
static int F_82 ( struct V_6 * V_7 , T_2 V_163 )
{
int V_18 ;
T_2 V_25 ;
V_7 -> V_164 = F_26 ( V_7 , V_163 ,
& V_7 -> V_165 ) ;
V_7 -> V_64 = F_31 ( V_7 -> V_164 * 4 , V_54 ) ;
if ( ! V_7 -> V_64 )
return - V_55 ;
V_25 = V_7 -> V_165 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_164 ; V_18 ++ , V_25 ++ )
V_7 -> V_64 [ V_18 ] = F_27 ( V_7 , V_25 ,
V_166 ) ;
return 0 ;
}
static int F_83 ( struct V_6 * V_7 )
{
int V_18 ;
T_2 V_25 = V_7 -> V_165 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_164 ; V_18 ++ , V_25 ++ ) {
struct V_167 * V_168 ;
unsigned int V_64 = F_47 ( V_7 , V_25 ) ;
unsigned int V_169 = F_48 ( V_64 ) ;
if ( V_169 != V_85 )
continue;
V_168 = F_84 ( & V_7 -> V_170 ) ;
if ( ! V_168 )
return - V_55 ;
V_168 -> V_25 = V_25 ;
V_168 -> V_14 = F_23 ( V_7 , V_25 , 0 ,
V_171 , 0 ) ;
V_168 -> V_172 = F_23 ( V_7 , V_25 , 0 ,
V_173 ,
0 ) ;
}
return 0 ;
}
static struct V_167 * F_85 ( struct V_6 * V_7 ,
struct V_174 * V_175 ,
T_2 V_25 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_175 -> V_176 ; V_18 ++ ) {
struct V_167 * V_168 = F_86 ( V_175 , V_18 ) ;
if ( V_168 -> V_25 == V_25 )
return V_168 ;
}
return NULL ;
}
int F_87 ( struct V_6 * V_7 , struct V_174 * V_4 ,
T_2 V_25 , unsigned int V_14 )
{
struct V_167 * V_168 ;
V_168 = F_85 ( V_7 , V_4 , V_25 ) ;
if ( ! V_168 ) {
V_168 = F_84 ( V_4 ) ;
if ( ! V_168 )
return - V_55 ;
V_168 -> V_25 = V_25 ;
}
V_168 -> V_14 = V_14 ;
return 0 ;
}
int F_88 ( struct V_6 * V_7 ,
T_2 V_25 , unsigned int V_14 )
{
return F_87 ( V_7 , & V_7 -> V_177 , V_25 , V_14 ) ;
}
unsigned int F_89 ( struct V_6 * V_7 , T_2 V_25 )
{
struct V_167 * V_168 ;
#ifdef F_90
{
unsigned int V_14 = 0 ;
F_2 ( & V_7 -> V_178 ) ;
V_168 = F_85 ( V_7 , & V_7 -> V_179 , V_25 ) ;
if ( V_168 )
V_14 = V_168 -> V_14 ;
F_4 ( & V_7 -> V_178 ) ;
if ( V_14 )
return V_14 ;
}
#endif
V_168 = F_85 ( V_7 , & V_7 -> V_177 , V_25 ) ;
if ( V_168 )
return V_168 -> V_14 ;
V_168 = F_85 ( V_7 , & V_7 -> V_170 , V_25 ) ;
if ( V_168 )
return V_168 -> V_14 ;
return 0 ;
}
int F_91 ( struct V_6 * V_7 , T_2 V_25 ,
unsigned int V_29 )
{
struct V_167 * V_168 ;
V_168 = F_85 ( V_7 , & V_7 -> V_170 , V_25 ) ;
if ( ! V_168 )
return - V_62 ;
V_168 -> V_180 = V_29 ;
return 0 ;
}
int F_92 ( struct V_6 * V_7 , T_2 V_25 )
{
struct V_167 * V_168 ;
V_168 = F_85 ( V_7 , & V_7 -> V_170 , V_25 ) ;
if ( ! V_168 )
return 0 ;
return V_168 -> V_180 ;
}
void F_93 ( struct V_6 * V_7 )
{
int V_18 ;
if ( V_7 -> V_10 -> V_114 )
return;
for ( V_18 = 0 ; V_18 < V_7 -> V_170 . V_176 ; V_18 ++ ) {
struct V_167 * V_168 = F_86 ( & V_7 -> V_170 , V_18 ) ;
F_23 ( V_7 , V_168 -> V_25 , 0 ,
V_181 , 0 ) ;
}
V_7 -> V_182 = 1 ;
}
static void F_94 ( struct V_6 * V_7 )
{
int V_18 ;
if ( ! V_7 -> V_182 )
return;
if ( V_7 -> V_10 -> V_114 )
return;
for ( V_18 = 0 ; V_18 < V_7 -> V_170 . V_176 ; V_18 ++ ) {
struct V_167 * V_168 = F_86 ( & V_7 -> V_170 , V_18 ) ;
F_24 ( V_7 , V_168 -> V_25 , 0 ,
V_181 ,
V_168 -> V_172 ) ;
}
V_7 -> V_182 = 0 ;
}
static void F_95 ( struct V_104 * V_103 )
{
struct V_6 * V_7 =
F_57 ( V_103 , struct V_6 , V_183 . V_103 ) ;
F_96 ( V_7 ) ;
F_97 ( V_7 ) ;
if ( ! V_7 -> V_184 )
return;
F_98 ( V_7 -> V_10 -> V_100 , & V_7 -> V_183 ,
V_7 -> V_184 ) ;
}
static void F_99 ( struct V_6 * V_7 )
{
F_100 ( & V_7 -> V_177 ) ;
#ifdef F_90
F_100 ( & V_7 -> V_179 ) ;
#endif
F_100 ( & V_7 -> V_170 ) ;
}
static struct V_185 *
F_101 ( struct V_6 * V_7 , T_2 V_25 )
{
struct V_185 * V_52 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_186 . V_176 ; V_18 ++ ) {
V_52 = F_86 ( & V_7 -> V_186 , V_18 ) ;
if ( V_52 -> V_25 == V_25 )
return V_52 ;
}
V_52 = F_84 ( & V_7 -> V_186 ) ;
if ( V_52 )
V_52 -> V_25 = V_25 ;
return V_52 ;
}
static void F_102 ( struct V_6 * V_7 )
{
if ( V_7 -> V_187 )
F_103 ( V_7 -> V_187 ) ;
V_7 -> V_187 = NULL ;
}
static void F_64 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_104 ( & V_7 -> V_183 ) ;
F_105 ( V_7 ) ;
F_99 ( V_7 ) ;
#ifdef F_106
F_107 ( & V_7 -> V_188 ) ;
F_62 ( V_7 -> V_10 -> V_100 ) ;
#endif
F_6 ( & V_7 -> V_4 ) ;
F_100 ( & V_7 -> V_189 ) ;
F_100 ( & V_7 -> V_190 ) ;
F_100 ( & V_7 -> V_186 ) ;
F_100 ( & V_7 -> V_191 ) ;
F_33 ( V_7 ) ;
V_7 -> V_10 -> V_107 [ V_7 -> V_30 ] = NULL ;
if ( V_7 -> V_108 . free )
V_7 -> V_108 . free ( V_7 ) ;
F_7 ( V_7 , false ) ;
F_102 ( V_7 ) ;
F_77 ( V_7 -> V_136 ) ;
F_108 ( & V_7 -> V_192 ) ;
F_108 ( & V_7 -> V_193 ) ;
F_37 ( V_7 -> V_149 ) ;
F_37 ( V_7 -> V_152 ) ;
F_37 ( V_7 -> V_126 ) ;
F_37 ( V_7 -> V_64 ) ;
V_7 -> V_10 -> V_194 -- ;
F_37 ( V_7 ) ;
}
int F_109 ( struct V_9 * V_10 ,
unsigned int V_195 ,
struct V_6 * * V_196 )
{
struct V_6 * V_7 ;
char V_197 [ 31 ] ;
T_2 V_198 ;
int V_34 ;
if ( F_43 ( ! V_10 ) )
return - V_62 ;
if ( F_43 ( V_195 > V_199 ) )
return - V_62 ;
if ( V_10 -> V_107 [ V_195 ] ) {
F_45 ( V_31 L_39
L_53 , V_195 ) ;
return - V_200 ;
}
V_7 = F_59 ( sizeof( * V_7 ) , V_54 ) ;
if ( V_7 == NULL ) {
F_45 ( V_31 L_54 ) ;
return - V_55 ;
}
V_7 -> V_10 = V_10 ;
V_7 -> V_30 = V_195 ;
F_71 ( & V_7 -> V_201 ) ;
F_71 ( & V_7 -> V_202 ) ;
F_71 ( & V_7 -> V_203 ) ;
F_110 ( & V_7 -> V_192 , sizeof( struct V_204 ) ) ;
F_110 ( & V_7 -> V_193 , sizeof( struct V_205 ) ) ;
F_111 ( & V_7 -> V_189 , sizeof( struct V_206 ) , 32 ) ;
F_111 ( & V_7 -> V_190 , sizeof( struct V_206 ) , 32 ) ;
F_111 ( & V_7 -> V_170 , sizeof( struct V_167 ) , 16 ) ;
F_111 ( & V_7 -> V_177 , sizeof( struct V_167 ) , 16 ) ;
F_111 ( & V_7 -> V_186 , sizeof( struct V_185 ) , 8 ) ;
F_111 ( & V_7 -> V_191 , sizeof( struct V_207 ) , 16 ) ;
F_111 ( & V_7 -> V_208 , sizeof( struct V_209 ) , 16 ) ;
F_111 ( & V_7 -> V_210 , sizeof( struct V_46 * ) , 8 ) ;
F_72 ( & V_7 -> V_57 ) ;
F_112 ( & V_7 -> V_183 , F_95 ) ;
V_7 -> V_211 = - 1 ;
#ifdef F_106
F_113 ( & V_7 -> V_212 ) ;
F_112 ( & V_7 -> V_188 , V_213 ) ;
F_8 ( V_7 ) ;
#endif
if ( V_7 -> V_10 -> V_126 ) {
V_7 -> V_126 = F_80 ( V_7 -> V_10 -> V_126 , V_54 ) ;
if ( ! V_7 -> V_126 ) {
F_64 ( V_7 ) ;
return - V_214 ;
}
}
F_3 ( & V_7 -> V_4 , & V_10 -> V_129 ) ;
V_10 -> V_194 ++ ;
V_10 -> V_107 [ V_195 ] = V_7 ;
V_7 -> V_140 = F_27 ( V_7 , V_155 ,
V_215 ) ;
if ( V_7 -> V_140 == - 1 )
V_7 -> V_140 = F_27 ( V_7 , V_155 ,
V_215 ) ;
V_7 -> V_216 = F_27 ( V_7 , V_155 ,
V_217 ) ;
V_7 -> V_142 = F_27 ( V_7 , V_155 ,
V_218 ) ;
F_81 ( V_7 ) ;
if ( ! V_7 -> V_138 && ! V_7 -> V_139 ) {
F_49 ( L_55 ) ;
V_34 = - V_214 ;
goto error;
}
V_198 = V_7 -> V_138 ? V_7 -> V_138 : V_7 -> V_139 ;
V_34 = F_82 ( V_7 , V_198 ) ;
if ( V_34 < 0 ) {
F_45 ( V_31 L_56 ) ;
goto error;
}
V_34 = F_83 ( V_7 ) ;
if ( V_34 < 0 )
goto error;
if ( ! V_7 -> V_216 ) {
V_7 -> V_216 =
F_23 ( V_7 , V_198 , 0 ,
V_219 , 0 ) ;
}
#ifdef F_106
V_7 -> V_220 = F_114 ( V_7 , V_198 ,
V_221 ) ;
#endif
V_7 -> V_222 = F_114 ( V_7 , V_198 ,
V_223 ) ;
#ifdef F_106
if ( ! V_7 -> V_220 || ! V_7 -> V_222 )
V_10 -> V_224 = 1 ;
#endif
F_115 ( V_7 , V_225 ) ;
F_116 ( V_7 ) ;
F_117 ( V_7 ) ;
sprintf ( V_197 , L_57 , V_7 -> V_140 ,
V_7 -> V_216 , V_7 -> V_142 ) ;
F_118 ( V_7 -> V_10 -> V_116 , V_197 ) ;
if ( V_196 )
* V_196 = V_7 ;
return 0 ;
error:
F_64 ( V_7 ) ;
return V_34 ;
}
int F_119 ( struct V_6 * V_7 )
{
T_2 V_198 ;
int V_34 ;
F_37 ( V_7 -> V_64 ) ;
V_198 = V_7 -> V_138 ? V_7 -> V_138 : V_7 -> V_139 ;
V_34 = F_82 ( V_7 , V_198 ) ;
if ( V_34 < 0 ) {
F_45 ( V_31 L_56 ) ;
return V_34 ;
}
F_100 ( & V_7 -> V_170 ) ;
V_34 = F_83 ( V_7 ) ;
return V_34 ;
}
static bool F_120 ( struct V_6 * V_7 )
{
T_2 V_25 = V_7 -> V_165 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_164 ; V_18 ++ , V_25 ++ ) {
unsigned int V_64 = F_47 ( V_7 , V_25 ) ;
switch ( F_48 ( V_64 ) ) {
case V_226 :
return false ;
case V_86 :
if ( ! ( V_64 & V_88 ) )
return false ;
break;
}
}
return true ;
}
int F_121 ( struct V_6 * V_7 )
{
int (* F_122)( struct V_6 * ) = NULL ;
int V_34 ;
V_7 -> V_2 = F_75 ( V_7 ) ;
if ( ! V_7 -> V_149 || ! V_7 -> V_152 ) {
V_34 = F_79 ( V_7 ) ;
if ( V_34 < 0 )
return V_34 ;
}
if ( ! F_123 ( V_7 ) && V_7 -> V_2 )
F_122 = V_7 -> V_2 -> F_122 ;
if ( ! F_122 ) {
F_102 ( V_7 ) ;
if ( F_120 ( V_7 ) ) {
#if F_124 ( V_227 )
F_122 = F_125 ( V_7 , V_228 ) ;
#elif F_126 ( V_227 )
F_122 = V_228 ;
#endif
}
if ( ! F_122 ) {
#if F_124 ( V_229 )
F_122 = F_125 ( V_7 , V_230 ) ;
#elif F_126 ( V_229 )
F_122 = V_230 ;
#endif
}
if ( ! F_122 ) {
F_14 ( V_31 L_58 ) ;
return - V_214 ;
}
}
V_34 = F_122 ( V_7 ) ;
if ( V_34 < 0 ) {
F_102 ( V_7 ) ;
return V_34 ;
}
if ( V_7 -> V_108 . V_109 ) {
V_34 = F_58 ( V_7 -> V_10 ) ;
if ( V_34 < 0 )
return V_34 ;
}
if ( V_7 -> V_138 || ! * V_7 -> V_10 -> V_116 -> V_231 )
snprintf ( V_7 -> V_10 -> V_116 -> V_231 ,
sizeof( V_7 -> V_10 -> V_116 -> V_231 ) ,
L_59 , V_7 -> V_149 , V_7 -> V_152 ) ;
return 0 ;
}
static void F_127 ( struct V_6 * V_7 ,
struct V_185 * V_52 , T_2 V_25 ,
T_1 V_232 , int V_233 )
{
unsigned int V_234 , V_235 ;
if ( V_52 -> V_232 != V_232 || V_52 -> V_233 != V_233 ) {
V_234 = F_23 ( V_7 , V_25 , 0 , V_236 , 0 ) ;
V_235 = ( V_232 << 4 ) | V_233 ;
if ( V_234 != V_235 )
F_24 ( V_7 , V_25 , 0 ,
V_237 ,
V_235 ) ;
V_52 -> V_232 = V_232 ;
V_52 -> V_233 = V_233 ;
}
}
static void F_128 ( struct V_6 * V_7 , struct V_185 * V_52 ,
T_2 V_25 , int V_238 )
{
unsigned int V_234 ;
if ( V_52 -> V_239 != V_238 ) {
V_234 = F_23 ( V_7 , V_25 , 0 ,
V_240 , 0 ) ;
if ( V_234 != V_238 ) {
F_129 ( 1 ) ;
F_24 ( V_7 , V_25 , 0 ,
V_241 ,
V_238 ) ;
}
V_52 -> V_239 = V_238 ;
}
}
void F_130 ( struct V_6 * V_7 , T_2 V_25 ,
T_1 V_232 ,
int V_233 , int V_238 )
{
struct V_6 * V_146 ;
struct V_185 * V_52 ;
int type ;
int V_18 ;
if ( ! V_25 )
return;
F_49 ( L_60
L_61 ,
V_25 , V_232 , V_233 , V_238 ) ;
V_52 = F_101 ( V_7 , V_25 ) ;
if ( ! V_52 )
return;
if ( V_7 -> V_242 )
F_128 ( V_7 , V_52 , V_25 , V_238 ) ;
F_127 ( V_7 , V_52 , V_25 , V_232 , V_233 ) ;
if ( ! V_7 -> V_242 )
F_128 ( V_7 , V_52 , V_25 , V_238 ) ;
V_52 -> V_243 = 1 ;
V_52 -> V_244 = 0 ;
type = F_48 ( F_47 ( V_7 , V_25 ) ) ;
F_29 (c, &codec->bus->codec_list, list) {
for ( V_18 = 0 ; V_18 < V_146 -> V_186 . V_176 ; V_18 ++ ) {
V_52 = F_86 ( & V_146 -> V_186 , V_18 ) ;
if ( ! V_52 -> V_243 && V_52 -> V_232 == V_232 &&
F_48 ( F_47 ( V_146 , V_52 -> V_25 ) ) == type )
V_52 -> V_244 = 1 ;
}
}
}
void F_131 ( struct V_6 * V_7 , T_2 V_25 ,
int V_245 )
{
struct V_185 * V_52 ;
if ( ! V_25 )
return;
if ( V_7 -> V_246 )
V_245 = 1 ;
F_49 ( L_62 , V_25 ) ;
V_52 = F_101 ( V_7 , V_25 ) ;
if ( V_52 ) {
if ( V_245 )
F_132 ( V_7 , V_52 ) ;
else
V_52 -> V_243 = 0 ;
}
}
static void F_132 ( struct V_6 * V_7 ,
struct V_185 * V_247 )
{
T_2 V_25 = V_247 -> V_25 ;
if ( V_247 -> V_232 || V_247 -> V_233 )
F_24 ( V_7 , V_25 , 0 , V_237 , 0 ) ;
if ( V_247 -> V_239 )
F_24 ( V_7 , V_25 , 0 , V_241 , 0
) ;
memset ( V_247 , 0 , sizeof( * V_247 ) ) ;
V_247 -> V_25 = V_25 ;
}
static void F_133 ( struct V_6 * V_7 )
{
struct V_6 * V_146 ;
int V_18 ;
F_29 (c, &codec->bus->codec_list, list) {
for ( V_18 = 0 ; V_18 < V_146 -> V_186 . V_176 ; V_18 ++ ) {
struct V_185 * V_52 ;
V_52 = F_86 ( & V_146 -> V_186 , V_18 ) ;
if ( V_52 -> V_244 )
F_132 ( V_146 , V_52 ) ;
}
}
}
static void F_134 ( struct V_6 * V_7 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_186 . V_176 ; V_18 ++ ) {
struct V_185 * V_52 = F_86 ( & V_7 -> V_186 , V_18 ) ;
if ( V_52 -> V_232 )
F_132 ( V_7 , V_52 ) ;
}
}
static void F_110 ( struct V_248 * V_249 ,
unsigned int V_250 )
{
memset ( V_249 , 0 , sizeof( * V_249 ) ) ;
memset ( V_249 -> V_251 , 0xff , sizeof( V_249 -> V_251 ) ) ;
F_111 ( & V_249 -> V_252 , V_250 , 64 ) ;
}
static void F_108 ( struct V_248 * V_249 )
{
F_100 ( & V_249 -> V_252 ) ;
}
static struct V_205 * F_135 ( struct V_248 * V_249 , T_1 V_253 )
{
T_4 V_254 = V_253 % ( T_4 ) F_10 ( V_249 -> V_251 ) ;
T_4 V_255 = V_249 -> V_251 [ V_254 ] ;
struct V_205 * V_256 ;
while ( V_255 != 0xffff ) {
V_256 = F_86 ( & V_249 -> V_252 , V_255 ) ;
if ( V_256 -> V_253 == V_253 )
return V_256 ;
V_255 = V_256 -> V_257 ;
}
return NULL ;
}
static struct V_205 * F_136 ( struct V_248 * V_249 ,
T_1 V_253 )
{
struct V_205 * V_256 = F_135 ( V_249 , V_253 ) ;
if ( ! V_256 ) {
T_4 V_254 , V_255 ;
V_256 = F_84 ( & V_249 -> V_252 ) ;
if ( ! V_256 )
return NULL ;
V_255 = F_137 ( & V_249 -> V_252 , V_256 ) ;
V_256 -> V_253 = V_253 ;
V_256 -> V_29 = 0 ;
V_256 -> V_244 = 0 ;
V_254 = V_253 % ( T_4 ) F_10 ( V_249 -> V_251 ) ;
V_256 -> V_257 = V_249 -> V_251 [ V_254 ] ;
V_249 -> V_251 [ V_254 ] = V_255 ;
}
return V_256 ;
}
static inline struct V_204 *
F_138 ( struct V_6 * V_7 , T_1 V_253 )
{
return (struct V_204 * ) F_136 ( & V_7 -> V_192 , V_253 ) ;
}
static int F_139 ( struct V_6 * V_7 , T_1 V_253 , unsigned int V_29 )
{
struct V_204 * V_256 ;
F_2 ( & V_7 -> V_203 ) ;
V_256 = F_138 ( V_7 , V_253 ) ;
if ( ! V_256 ) {
F_4 ( & V_7 -> V_203 ) ;
return - V_62 ;
}
V_256 -> V_258 = V_29 ;
V_256 -> V_259 . V_29 |= V_260 ;
F_4 ( & V_7 -> V_203 ) ;
return 0 ;
}
static unsigned int F_140 ( struct V_6 * V_7 , T_2 V_25 ,
int V_261 )
{
if ( ! ( F_47 ( V_7 , V_25 ) & V_262 ) )
V_25 = V_7 -> V_138 ;
return F_27 ( V_7 , V_25 ,
V_261 == V_263 ?
V_264 : V_265 ) ;
}
T_1 F_141 ( struct V_6 * V_7 , T_2 V_25 , int V_261 )
{
return F_142 ( V_7 , V_25 , V_261 ,
F_143 ( V_25 , V_261 , 0 ) ,
F_140 ) ;
}
int F_144 ( struct V_6 * V_7 , T_2 V_25 , int V_266 ,
unsigned int V_267 )
{
return F_139 ( V_7 , F_143 ( V_25 , V_266 , 0 ) , V_267 ) ;
}
static unsigned int F_145 ( struct V_6 * V_7 , T_2 V_25 ,
int V_266 )
{
return F_27 ( V_7 , V_25 , V_268 ) ;
}
T_1 F_146 ( struct V_6 * V_7 , T_2 V_25 )
{
return F_142 ( V_7 , V_25 , 0 , F_147 ( V_25 ) ,
F_145 ) ;
}
int F_148 ( struct V_6 * V_7 , T_2 V_25 ,
unsigned int V_267 )
{
return F_139 ( V_7 , F_147 ( V_25 ) , V_267 ) ;
}
static struct V_204 *
F_149 ( struct V_6 * V_7 , T_2 V_25 , int V_269 ,
int V_261 , int V_270 , bool V_271 )
{
struct V_204 * V_256 ;
unsigned int V_28 , V_29 = 0 ;
bool V_272 = false ;
V_273:
V_256 = F_138 ( V_7 , F_143 ( V_25 , V_261 , V_270 ) ) ;
if ( ! V_256 )
return NULL ;
if ( ! ( V_256 -> V_259 . V_29 & F_150 ( V_269 ) ) ) {
if ( ! V_272 ) {
F_4 ( & V_7 -> V_203 ) ;
V_28 = V_269 ? V_274 : V_275 ;
V_28 |= V_261 == V_263 ?
V_276 : V_277 ;
V_28 |= V_270 ;
V_29 = F_23 ( V_7 , V_25 , 0 ,
V_278 , V_28 ) ;
V_29 &= 0xff ;
V_272 = true ;
F_2 ( & V_7 -> V_203 ) ;
goto V_273;
}
V_256 -> V_279 [ V_269 ] = V_29 ;
V_256 -> V_259 . V_29 |= F_150 ( V_269 ) ;
} else if ( V_271 )
return NULL ;
return V_256 ;
}
static void F_151 ( struct V_6 * V_7 , unsigned int V_258 ,
T_2 V_25 , int V_269 , int V_261 , int V_270 ,
int V_29 )
{
T_1 V_28 ;
V_28 = V_269 ? V_280 : V_281 ;
V_28 |= V_261 == V_263 ? V_282 : V_283 ;
V_28 |= V_270 << V_284 ;
if ( ( V_29 & V_285 ) && ! ( V_258 & V_286 ) &&
( V_258 & V_287 ) )
;
else
V_28 |= V_29 ;
F_24 ( V_7 , V_25 , 0 , V_288 , V_28 ) ;
}
int F_152 ( struct V_6 * V_7 , T_2 V_25 , int V_269 ,
int V_261 , int V_270 )
{
struct V_204 * V_256 ;
unsigned int V_29 = 0 ;
F_2 ( & V_7 -> V_203 ) ;
V_256 = F_149 ( V_7 , V_25 , V_269 , V_261 , V_270 , false ) ;
if ( V_256 )
V_29 = V_256 -> V_279 [ V_269 ] ;
F_4 ( & V_7 -> V_203 ) ;
return V_29 ;
}
static int F_153 ( struct V_6 * V_7 , T_2 V_25 , int V_269 ,
int V_261 , int V_254 , int V_71 , int V_29 ,
bool V_271 )
{
struct V_204 * V_256 ;
unsigned int V_267 ;
unsigned int V_289 ;
if ( F_43 ( V_71 & ~ 0xff ) )
V_71 &= 0xff ;
V_29 &= V_71 ;
F_2 ( & V_7 -> V_203 ) ;
V_256 = F_149 ( V_7 , V_25 , V_269 , V_261 , V_254 , V_271 ) ;
if ( ! V_256 ) {
F_4 ( & V_7 -> V_203 ) ;
return 0 ;
}
V_29 |= V_256 -> V_279 [ V_269 ] & ~ V_71 ;
if ( V_256 -> V_279 [ V_269 ] == V_29 ) {
F_4 ( & V_7 -> V_203 ) ;
return 0 ;
}
V_256 -> V_279 [ V_269 ] = V_29 ;
V_289 = V_256 -> V_259 . V_244 = V_7 -> V_290 ;
V_267 = V_256 -> V_258 ;
F_4 ( & V_7 -> V_203 ) ;
if ( ! V_289 )
F_151 ( V_7 , V_267 , V_25 , V_269 , V_261 , V_254 , V_29 ) ;
return 1 ;
}
int F_154 ( struct V_6 * V_7 , T_2 V_25 , int V_269 ,
int V_261 , int V_254 , int V_71 , int V_29 )
{
return F_153 ( V_7 , V_25 , V_269 , V_261 , V_254 , V_71 , V_29 , false ) ;
}
int F_155 ( struct V_6 * V_7 , T_2 V_25 ,
int V_261 , int V_254 , int V_71 , int V_29 )
{
int V_269 , V_291 = 0 ;
if ( F_43 ( V_71 & ~ 0xff ) )
V_71 &= 0xff ;
for ( V_269 = 0 ; V_269 < 2 ; V_269 ++ )
V_291 |= F_154 ( V_7 , V_25 , V_269 , V_261 ,
V_254 , V_71 , V_29 ) ;
return V_291 ;
}
int F_156 ( struct V_6 * V_7 , T_2 V_25 , int V_269 ,
int V_266 , int V_254 , int V_71 , int V_29 )
{
return F_153 ( V_7 , V_25 , V_269 , V_266 , V_254 , V_71 , V_29 , true ) ;
}
int F_157 ( struct V_6 * V_7 , T_2 V_25 ,
int V_266 , int V_254 , int V_71 , int V_29 )
{
int V_269 , V_291 = 0 ;
if ( F_43 ( V_71 & ~ 0xff ) )
V_71 &= 0xff ;
for ( V_269 = 0 ; V_269 < 2 ; V_269 ++ )
V_291 |= F_156 ( V_7 , V_25 , V_269 , V_266 ,
V_254 , V_71 , V_29 ) ;
return V_291 ;
}
void F_158 ( struct V_6 * V_7 )
{
int V_18 ;
F_2 ( & V_7 -> V_203 ) ;
V_7 -> V_290 = 0 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_192 . V_252 . V_176 ; V_18 ++ ) {
struct V_204 * V_292 ;
T_1 V_253 ;
T_2 V_25 ;
unsigned int V_254 , V_266 , V_269 ;
struct V_204 V_256 ;
V_292 = F_86 ( & V_7 -> V_192 . V_252 , V_18 ) ;
if ( ! V_292 -> V_259 . V_244 )
continue;
V_292 -> V_259 . V_244 = 0 ;
V_256 = * V_292 ;
V_253 = V_256 . V_259 . V_253 ;
if ( ! V_253 )
continue;
V_25 = V_253 & 0xff ;
V_254 = ( V_253 >> 16 ) & 0xff ;
V_266 = ( V_253 >> 24 ) & 0xff ;
for ( V_269 = 0 ; V_269 < 2 ; V_269 ++ ) {
if ( ! ( V_256 . V_259 . V_29 & F_150 ( V_269 ) ) )
continue;
F_4 ( & V_7 -> V_203 ) ;
F_151 ( V_7 , V_256 . V_258 , V_25 , V_269 , V_266 , V_254 ,
V_256 . V_279 [ V_269 ] ) ;
F_2 ( & V_7 -> V_203 ) ;
}
}
F_4 ( & V_7 -> V_203 ) ;
}
static T_1 F_159 ( struct V_6 * V_7 , T_2 V_25 , int V_266 ,
unsigned int V_293 )
{
T_1 V_267 = F_141 ( V_7 , V_25 , V_266 ) ;
V_267 = ( V_267 & V_294 ) >> V_295 ;
if ( V_293 < V_267 )
V_267 -= V_293 ;
return V_267 ;
}
int F_160 ( struct V_296 * V_297 ,
struct V_298 * V_299 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
T_4 V_25 = F_162 ( V_297 ) ;
T_3 V_300 = F_163 ( V_297 ) ;
int V_266 = F_164 ( V_297 ) ;
unsigned int V_293 = F_165 ( V_297 ) ;
V_299 -> type = V_301 ;
V_299 -> V_302 = V_300 == 3 ? 2 : 1 ;
V_299 -> V_303 . integer . V_304 = 0 ;
V_299 -> V_303 . integer . V_305 = F_159 ( V_7 , V_25 , V_266 , V_293 ) ;
if ( ! V_299 -> V_303 . integer . V_305 ) {
F_14 ( V_80 L_39
L_63 , V_25 ,
V_297 -> V_137 . V_144 ) ;
return - V_62 ;
}
return 0 ;
}
static inline unsigned int
F_166 ( struct V_6 * V_7 , T_2 V_25 ,
int V_269 , int V_266 , int V_254 , unsigned int V_293 )
{
unsigned int V_29 ;
V_29 = F_152 ( V_7 , V_25 , V_269 , V_266 , V_254 ) ;
V_29 &= V_306 ;
if ( V_29 >= V_293 )
V_29 -= V_293 ;
else
V_29 = 0 ;
return V_29 ;
}
static inline int
F_167 ( struct V_6 * V_7 , T_2 V_25 ,
int V_269 , int V_266 , int V_254 , unsigned int V_293 ,
unsigned int V_29 )
{
unsigned int V_307 ;
if ( V_29 > 0 )
V_29 += V_293 ;
V_307 = F_159 ( V_7 , V_25 , V_266 , 0 ) ;
if ( V_29 > V_307 )
V_29 = V_307 ;
return F_154 ( V_7 , V_25 , V_269 , V_266 , V_254 ,
V_306 , V_29 ) ;
}
int F_168 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
T_2 V_25 = F_162 ( V_297 ) ;
int V_300 = F_163 ( V_297 ) ;
int V_266 = F_164 ( V_297 ) ;
int V_254 = F_169 ( V_297 ) ;
unsigned int V_293 = F_165 ( V_297 ) ;
long * V_310 = V_309 -> V_303 . integer . V_303 ;
if ( V_300 & 1 )
* V_310 ++ = F_166 ( V_7 , V_25 , 0 , V_266 , V_254 , V_293 ) ;
if ( V_300 & 2 )
* V_310 = F_166 ( V_7 , V_25 , 1 , V_266 , V_254 , V_293 ) ;
return 0 ;
}
int F_170 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
T_2 V_25 = F_162 ( V_297 ) ;
int V_300 = F_163 ( V_297 ) ;
int V_266 = F_164 ( V_297 ) ;
int V_254 = F_169 ( V_297 ) ;
unsigned int V_293 = F_165 ( V_297 ) ;
long * V_310 = V_309 -> V_303 . integer . V_303 ;
int V_311 = 0 ;
F_16 ( V_7 ) ;
if ( V_300 & 1 ) {
V_311 = F_167 ( V_7 , V_25 , 0 , V_266 , V_254 , V_293 , * V_310 ) ;
V_310 ++ ;
}
if ( V_300 & 2 )
V_311 |= F_167 ( V_7 , V_25 , 1 , V_266 , V_254 , V_293 , * V_310 ) ;
F_19 ( V_7 ) ;
return V_311 ;
}
int F_171 ( struct V_296 * V_297 , int V_312 ,
unsigned int V_313 , unsigned int T_5 * V_314 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
T_2 V_25 = F_162 ( V_297 ) ;
int V_266 = F_164 ( V_297 ) ;
unsigned int V_293 = F_165 ( V_297 ) ;
bool V_315 = F_172 ( V_297 ) ;
T_1 V_267 , V_316 , V_317 ;
if ( V_313 < 4 * sizeof( unsigned int ) )
return - V_55 ;
V_267 = F_141 ( V_7 , V_25 , V_266 ) ;
V_317 = ( V_267 & V_318 ) >> V_319 ;
V_317 = ( V_317 + 1 ) * 25 ;
V_316 = - ( ( V_267 & V_320 ) >> V_321 ) ;
V_316 += V_293 ;
V_316 = ( ( int ) V_316 ) * ( ( int ) V_317 ) ;
if ( V_315 || ( V_267 & V_287 ) )
V_317 |= V_322 ;
if ( F_173 ( V_323 , V_314 ) )
return - V_324 ;
if ( F_173 ( 2 * sizeof( unsigned int ) , V_314 + 1 ) )
return - V_324 ;
if ( F_173 ( V_316 , V_314 + 2 ) )
return - V_324 ;
if ( F_173 ( V_317 , V_314 + 3 ) )
return - V_324 ;
return 0 ;
}
void F_174 ( struct V_6 * V_7 , T_2 V_25 , int V_266 ,
unsigned int * V_325 )
{
T_1 V_267 ;
int V_84 , V_326 ;
V_267 = F_141 ( V_7 , V_25 , V_266 ) ;
V_84 = ( V_267 & V_294 ) >> V_295 ;
V_326 = ( V_267 & V_318 ) >> V_319 ;
V_326 = ( V_326 + 1 ) * 25 ;
V_325 [ 0 ] = V_323 ;
V_325 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_325 [ 2 ] = - V_84 * V_326 ;
V_325 [ 3 ] = V_326 ;
}
static struct V_296 *
F_175 ( struct V_6 * V_7 , const char * V_144 , int V_327 , int V_254 )
{
struct V_328 V_137 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_329 = V_330 ;
V_137 . V_112 = V_327 ;
V_137 . V_270 = V_254 ;
if ( F_43 ( strlen ( V_144 ) >= sizeof( V_137 . V_144 ) ) )
return NULL ;
strcpy ( V_137 . V_144 , V_144 ) ;
return F_176 ( V_7 -> V_10 -> V_116 , & V_137 ) ;
}
struct V_296 * F_177 ( struct V_6 * V_7 ,
const char * V_144 )
{
return F_175 ( V_7 , V_144 , 0 , 0 ) ;
}
static int F_178 ( struct V_6 * V_7 , const char * V_144 ,
int V_331 )
{
int V_18 , V_254 ;
for ( V_18 = 0 , V_254 = V_331 ; V_18 < 16 ; V_18 ++ , V_254 ++ ) {
if ( ! F_175 ( V_7 , V_144 , 0 , V_254 ) )
return V_254 ;
}
return - V_200 ;
}
int F_179 ( struct V_6 * V_7 , T_2 V_25 ,
struct V_296 * V_332 )
{
int V_34 ;
unsigned short V_26 = 0 ;
struct V_206 * V_333 ;
if ( V_332 -> V_137 . V_334 & V_335 ) {
V_26 |= V_336 ;
if ( V_25 == 0 )
V_25 = F_180 ( V_332 -> V_337 ) ;
}
if ( ( V_332 -> V_137 . V_334 & V_338 ) != 0 && V_25 == 0 )
V_25 = V_332 -> V_137 . V_334 & 0xffff ;
if ( V_332 -> V_137 . V_334 & ( V_338 | V_335 ) )
V_332 -> V_137 . V_334 = 0 ;
V_34 = F_181 ( V_7 -> V_10 -> V_116 , V_332 ) ;
if ( V_34 < 0 )
return V_34 ;
V_333 = F_84 ( & V_7 -> V_189 ) ;
if ( ! V_333 )
return - V_55 ;
V_333 -> V_332 = V_332 ;
V_333 -> V_25 = V_25 ;
V_333 -> V_26 = V_26 ;
return 0 ;
}
int F_182 ( struct V_6 * V_7 , struct V_296 * V_332 ,
unsigned int V_270 , T_2 V_25 )
{
struct V_206 * V_333 ;
if ( V_25 > 0 ) {
V_333 = F_84 ( & V_7 -> V_190 ) ;
if ( ! V_333 )
return - V_55 ;
V_333 -> V_332 = V_332 ;
V_333 -> V_270 = V_270 ;
V_333 -> V_25 = V_25 ;
return 0 ;
}
F_14 ( V_31 L_64 ,
V_332 -> V_137 . V_144 , V_332 -> V_137 . V_270 , V_270 ) ;
return - V_62 ;
}
void F_183 ( struct V_6 * V_7 )
{
int V_18 ;
struct V_206 * V_339 = V_7 -> V_189 . V_4 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_189 . V_176 ; V_18 ++ )
F_184 ( V_7 -> V_10 -> V_116 , V_339 [ V_18 ] . V_332 ) ;
F_100 ( & V_7 -> V_189 ) ;
F_100 ( & V_7 -> V_190 ) ;
}
int F_185 ( struct V_9 * V_10 )
{
struct V_115 * V_116 = V_10 -> V_116 ;
struct V_6 * V_7 ;
F_186 ( & V_116 -> V_340 ) ;
if ( V_116 -> V_114 )
goto V_341;
V_116 -> V_114 = 1 ;
if ( ! F_34 ( & V_116 -> V_342 ) )
goto V_343;
F_29 (codec, &bus->codec_list, list) {
int V_344 ;
for ( V_344 = 0 ; V_344 < V_7 -> V_345 ; V_344 ++ ) {
struct V_346 * V_347 = & V_7 -> V_348 [ V_344 ] ;
if ( ! V_347 -> V_344 )
continue;
if ( V_347 -> V_344 -> V_349 [ 0 ] . V_350 ||
V_347 -> V_344 -> V_349 [ 1 ] . V_350 )
goto V_343;
}
}
F_187 ( & V_116 -> V_340 ) ;
return 0 ;
V_343:
V_116 -> V_114 = 0 ;
V_341:
F_187 ( & V_116 -> V_340 ) ;
return - V_62 ;
}
void F_188 ( struct V_9 * V_10 )
{
struct V_115 * V_116 = V_10 -> V_116 ;
V_116 = V_10 -> V_116 ;
F_186 ( & V_116 -> V_340 ) ;
V_116 -> V_114 = 0 ;
F_187 ( & V_116 -> V_340 ) ;
}
int F_189 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_115 * V_116 = V_10 -> V_116 ;
int V_18 ;
if ( F_185 ( V_10 ) < 0 )
return - V_200 ;
F_104 ( & V_7 -> V_183 ) ;
#ifdef F_106
F_104 ( & V_7 -> V_188 ) ;
F_62 ( V_10 -> V_100 ) ;
#endif
F_183 ( V_7 ) ;
for ( V_18 = 0 ; V_18 < V_7 -> V_345 ; V_18 ++ ) {
if ( V_7 -> V_348 [ V_18 ] . V_344 ) {
F_190 ( V_116 , V_7 -> V_348 [ V_18 ] . V_344 ) ;
F_191 ( V_7 -> V_348 [ V_18 ] . V_112 ,
V_10 -> V_351 ) ;
}
}
if ( V_7 -> V_108 . free )
V_7 -> V_108 . free ( V_7 ) ;
memset ( & V_7 -> V_108 , 0 , sizeof( V_7 -> V_108 ) ) ;
F_105 ( V_7 ) ;
V_7 -> V_352 = NULL ;
V_7 -> V_353 = NULL ;
F_108 ( & V_7 -> V_192 ) ;
F_108 ( & V_7 -> V_193 ) ;
F_110 ( & V_7 -> V_192 , sizeof( struct V_204 ) ) ;
F_110 ( & V_7 -> V_193 , sizeof( struct V_205 ) ) ;
F_100 ( & V_7 -> V_177 ) ;
F_100 ( & V_7 -> V_186 ) ;
F_100 ( & V_7 -> V_191 ) ;
F_100 ( & V_7 -> V_210 ) ;
V_7 -> V_345 = 0 ;
V_7 -> V_348 = NULL ;
V_7 -> V_2 = NULL ;
V_7 -> V_354 = NULL ;
V_7 -> V_355 = 0 ;
F_102 ( V_7 ) ;
F_77 ( V_7 -> V_136 ) ;
V_7 -> V_136 = NULL ;
F_188 ( V_10 ) ;
return 0 ;
}
static int F_192 ( struct V_6 * V_7 , const char * const * V_356 ,
const char * V_357 , T_6 V_358 , void * V_359 )
{
struct V_206 * V_339 ;
const char * const * V_360 ;
int V_18 , V_34 ;
V_339 = V_7 -> V_189 . V_4 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_189 . V_176 ; V_18 ++ ) {
struct V_296 * V_361 = V_339 [ V_18 ] . V_332 ;
if ( ! V_361 || V_361 -> V_137 . V_329 != V_330 )
continue;
for ( V_360 = V_356 ; * V_360 ; V_360 ++ ) {
char V_362 [ sizeof( V_361 -> V_137 . V_144 ) ] ;
const char * V_144 = * V_360 ;
if ( V_357 ) {
snprintf ( V_362 , sizeof( V_362 ) , L_59 ,
V_144 , V_357 ) ;
V_144 = V_362 ;
}
if ( ! strcmp ( V_361 -> V_137 . V_144 , V_144 ) ) {
V_34 = V_358 ( V_359 , V_361 ) ;
if ( V_34 )
return V_34 ;
break;
}
}
}
return 0 ;
}
static int F_193 ( void * V_359 , struct V_296 * V_361 )
{
return 1 ;
}
static int F_194 ( struct V_296 * V_332 , int * V_363 )
{
int V_314 [ 4 ] ;
const int * V_325 = NULL ;
int V_29 = - 1 ;
if ( V_332 -> V_364 [ 0 ] . V_365 & V_366 ) {
T_7 V_367 = F_195 () ;
F_196 ( F_197 () ) ;
if ( ! V_332 -> V_325 . V_146 ( V_332 , 0 , sizeof( V_314 ) , V_314 ) )
V_325 = V_314 ;
F_196 ( V_367 ) ;
} else if ( V_332 -> V_364 [ 0 ] . V_365 & V_368 )
V_325 = V_332 -> V_325 . V_52 ;
if ( V_325 && V_325 [ 0 ] == V_323 ) {
int V_326 = V_325 [ 3 ] ;
V_326 &= ~ V_322 ;
if ( ! V_326 )
return - 1 ;
if ( * V_363 && * V_363 != V_326 ) {
F_45 ( V_31 L_65 ,
* V_363 , V_326 ) ;
return - 1 ;
}
* V_363 = V_326 ;
V_29 = - V_325 [ 2 ] / V_326 ;
}
return V_29 ;
}
static int F_198 ( struct V_296 * V_332 , int V_29 )
{
struct V_308 * V_309 ;
V_309 = F_59 ( sizeof( * V_309 ) , V_54 ) ;
if ( ! V_309 )
return - V_55 ;
V_309 -> V_303 . integer . V_303 [ 0 ] = V_29 ;
V_309 -> V_303 . integer . V_303 [ 1 ] = V_29 ;
V_332 -> V_369 ( V_332 , V_309 ) ;
F_37 ( V_309 ) ;
return 0 ;
}
static int F_199 ( void * V_359 , struct V_296 * V_370 )
{
int V_371 = F_194 ( V_370 , V_359 ) ;
if ( V_371 > 0 )
F_198 ( V_370 , V_371 ) ;
return 0 ;
}
static int F_200 ( void * V_359 , struct V_296 * V_370 )
{
return F_198 ( V_370 , 1 ) ;
}
int F_201 ( struct V_6 * V_7 , char * V_144 ,
unsigned int * V_325 , const char * const * V_356 ,
const char * V_357 , bool V_372 ,
struct V_296 * * V_373 )
{
struct V_296 * V_332 ;
int V_34 ;
if ( V_373 )
* V_373 = NULL ;
V_34 = F_192 ( V_7 , V_356 , V_357 , F_193 , NULL ) ;
if ( V_34 != 1 ) {
F_49 ( L_66 , V_144 ) ;
return 0 ;
}
V_332 = F_202 ( V_144 , V_325 ) ;
if ( ! V_332 )
return - V_55 ;
V_34 = F_179 ( V_7 , 0 , V_332 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_192 ( V_7 , V_356 , V_357 ,
( T_6 ) V_374 , V_332 ) ;
if ( V_34 < 0 )
return V_34 ;
F_198 ( V_332 , 0 ) ;
if ( V_372 ) {
int V_326 = 0 ;
F_192 ( V_7 , V_356 , V_357 ,
V_325 ? F_199 : F_200 , & V_326 ) ;
}
if ( V_373 )
* V_373 = V_332 ;
return 0 ;
}
static int F_203 ( struct V_296 * V_297 ,
struct V_298 * V_299 )
{
static const char * const V_375 [] = {
L_67 , L_68 , L_69
} ;
unsigned int V_270 ;
V_299 -> type = V_376 ;
V_299 -> V_302 = 1 ;
V_299 -> V_303 . V_377 . V_339 = 3 ;
V_270 = V_299 -> V_303 . V_377 . V_333 ;
if ( V_270 >= 3 )
V_270 = 2 ;
strcpy ( V_299 -> V_303 . V_377 . V_144 , V_375 [ V_270 ] ) ;
return 0 ;
}
static int F_204 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_378 * V_379 = F_161 ( V_297 ) ;
V_309 -> V_303 . V_377 . V_333 [ 0 ] = V_379 -> V_380 ;
return 0 ;
}
static int F_205 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_378 * V_379 = F_161 ( V_297 ) ;
unsigned int V_381 = V_379 -> V_380 ;
V_379 -> V_380 = V_309 -> V_303 . V_377 . V_333 [ 0 ] ;
if ( V_379 -> V_380 > V_382 )
V_379 -> V_380 = V_382 ;
if ( V_381 == V_379 -> V_380 )
return 0 ;
F_206 ( V_379 ) ;
return 1 ;
}
int F_207 ( struct V_6 * V_7 ,
struct V_378 * V_379 ,
bool V_383 )
{
struct V_296 * V_332 ;
if ( ! V_379 -> V_379 || ! V_379 -> V_384 )
return 0 ;
F_208 ( V_379 -> V_384 , V_379 -> V_379 , V_7 ) ;
V_379 -> V_7 = V_7 ;
V_379 -> V_380 = V_382 ;
if ( ! V_383 )
return 0 ;
V_332 = F_209 ( & V_385 , V_379 ) ;
if ( ! V_332 )
return - V_55 ;
return F_179 ( V_7 , 0 , V_332 ) ;
}
void F_206 ( struct V_378 * V_379 )
{
if ( ! V_379 -> V_379 || ! V_379 -> V_7 )
return;
if ( V_379 -> V_7 -> V_10 -> V_114 )
return;
switch ( V_379 -> V_380 ) {
case V_382 :
F_210 ( V_379 -> V_384 ) ;
break;
default:
V_379 -> V_379 ( V_379 -> V_7 , V_379 -> V_380 ) ;
break;
}
}
int F_211 ( struct V_296 * V_297 ,
struct V_298 * V_299 )
{
int V_300 = F_163 ( V_297 ) ;
V_299 -> type = V_386 ;
V_299 -> V_302 = V_300 == 3 ? 2 : 1 ;
V_299 -> V_303 . integer . V_304 = 0 ;
V_299 -> V_303 . integer . V_305 = 1 ;
return 0 ;
}
int F_212 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
T_2 V_25 = F_162 ( V_297 ) ;
int V_300 = F_163 ( V_297 ) ;
int V_266 = F_164 ( V_297 ) ;
int V_254 = F_169 ( V_297 ) ;
long * V_310 = V_309 -> V_303 . integer . V_303 ;
if ( V_300 & 1 )
* V_310 ++ = ( F_152 ( V_7 , V_25 , 0 , V_266 , V_254 ) &
V_285 ) ? 0 : 1 ;
if ( V_300 & 2 )
* V_310 = ( F_152 ( V_7 , V_25 , 1 , V_266 , V_254 ) &
V_285 ) ? 0 : 1 ;
return 0 ;
}
int F_213 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
T_2 V_25 = F_162 ( V_297 ) ;
int V_300 = F_163 ( V_297 ) ;
int V_266 = F_164 ( V_297 ) ;
int V_254 = F_169 ( V_297 ) ;
long * V_310 = V_309 -> V_303 . integer . V_303 ;
int V_311 = 0 ;
F_16 ( V_7 ) ;
if ( V_300 & 1 ) {
V_311 = F_154 ( V_7 , V_25 , 0 , V_266 , V_254 ,
V_285 ,
* V_310 ? 0 : V_285 ) ;
V_310 ++ ;
}
if ( V_300 & 2 )
V_311 |= F_154 ( V_7 , V_25 , 1 , V_266 , V_254 ,
V_285 ,
* V_310 ? 0 : V_285 ) ;
F_214 ( V_7 , V_25 ) ;
F_19 ( V_7 ) ;
return V_311 ;
}
int F_215 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
unsigned long V_387 ;
int V_34 ;
F_2 ( & V_7 -> V_202 ) ;
V_387 = V_297 -> V_337 ;
V_297 -> V_337 = V_387 & ~ V_388 ;
V_34 = F_212 ( V_297 , V_309 ) ;
V_297 -> V_337 = V_387 ;
F_4 ( & V_7 -> V_202 ) ;
return V_34 ;
}
int F_216 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
unsigned long V_387 ;
int V_18 , V_389 , V_34 = 0 , V_311 = 0 ;
F_2 ( & V_7 -> V_202 ) ;
V_387 = V_297 -> V_337 ;
V_389 = ( V_387 & V_388 ) >> V_390 ;
for ( V_18 = 0 ; V_18 < V_389 ; V_18 ++ ) {
V_297 -> V_337 = ( V_387 & ~ V_388 ) |
( V_18 << V_390 ) ;
V_34 = F_213 ( V_297 , V_309 ) ;
if ( V_34 < 0 )
break;
V_311 |= V_34 ;
}
V_297 -> V_337 = V_387 ;
F_4 ( & V_7 -> V_202 ) ;
return V_34 < 0 ? V_34 : V_311 ;
}
int F_217 ( struct V_296 * V_297 ,
struct V_298 * V_299 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
struct V_391 * V_146 ;
int V_34 ;
F_2 ( & V_7 -> V_202 ) ;
V_146 = (struct V_391 * ) V_297 -> V_337 ;
V_297 -> V_337 = * V_146 -> V_392 ;
V_34 = V_146 -> V_12 -> V_256 ( V_297 , V_299 ) ;
V_297 -> V_337 = ( long ) V_146 ;
F_4 ( & V_7 -> V_202 ) ;
return V_34 ;
}
int F_218 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
struct V_391 * V_146 ;
int V_34 ;
F_2 ( & V_7 -> V_202 ) ;
V_146 = (struct V_391 * ) V_297 -> V_337 ;
V_297 -> V_337 = * V_146 -> V_392 ;
V_34 = V_146 -> V_12 -> V_393 ( V_297 , V_309 ) ;
V_297 -> V_337 = ( long ) V_146 ;
F_4 ( & V_7 -> V_202 ) ;
return V_34 ;
}
int F_219 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
struct V_391 * V_146 ;
unsigned long * V_394 ;
int V_34 = 0 , V_311 = 0 ;
F_2 ( & V_7 -> V_202 ) ;
V_146 = (struct V_391 * ) V_297 -> V_337 ;
for ( V_394 = V_146 -> V_392 ; * V_394 ; V_394 ++ ) {
V_297 -> V_337 = * V_394 ;
V_34 = V_146 -> V_12 -> V_369 ( V_297 , V_309 ) ;
if ( V_34 < 0 )
break;
V_311 |= V_34 ;
}
V_297 -> V_337 = ( long ) V_146 ;
F_4 ( & V_7 -> V_202 ) ;
return V_34 < 0 ? V_34 : V_311 ;
}
int F_220 ( struct V_296 * V_297 , int V_312 ,
unsigned int V_313 , unsigned int T_5 * V_325 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
struct V_391 * V_146 ;
int V_34 ;
F_2 ( & V_7 -> V_202 ) ;
V_146 = (struct V_391 * ) V_297 -> V_337 ;
V_297 -> V_337 = * V_146 -> V_392 ;
V_34 = V_146 -> V_12 -> V_325 ( V_297 , V_312 , V_313 , V_325 ) ;
V_297 -> V_337 = ( long ) V_146 ;
F_4 ( & V_7 -> V_202 ) ;
return V_34 ;
}
static int F_221 ( struct V_296 * V_297 ,
struct V_298 * V_299 )
{
V_299 -> type = V_395 ;
V_299 -> V_302 = 1 ;
return 0 ;
}
static int F_222 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
V_309 -> V_303 . V_396 . V_397 [ 0 ] = V_398 |
V_399 |
V_400 |
V_401 ;
V_309 -> V_303 . V_396 . V_397 [ 1 ] = V_402 |
V_403 ;
return 0 ;
}
static int F_223 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
V_309 -> V_303 . V_396 . V_397 [ 0 ] = V_398 |
V_399 |
V_404 ;
return 0 ;
}
static int F_224 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
int V_254 = V_297 -> V_337 ;
struct V_207 * V_405 ;
F_2 ( & V_7 -> V_201 ) ;
V_405 = F_86 ( & V_7 -> V_191 , V_254 ) ;
V_309 -> V_303 . V_396 . V_397 [ 0 ] = V_405 -> V_397 & 0xff ;
V_309 -> V_303 . V_396 . V_397 [ 1 ] = ( V_405 -> V_397 >> 8 ) & 0xff ;
V_309 -> V_303 . V_396 . V_397 [ 2 ] = ( V_405 -> V_397 >> 16 ) & 0xff ;
V_309 -> V_303 . V_396 . V_397 [ 3 ] = ( V_405 -> V_397 >> 24 ) & 0xff ;
F_4 ( & V_7 -> V_201 ) ;
return 0 ;
}
static unsigned short F_225 ( unsigned int V_406 )
{
unsigned short V_29 = 0 ;
if ( V_406 & V_398 )
V_29 |= V_407 ;
if ( V_406 & V_399 )
V_29 |= V_408 ;
if ( V_406 & V_398 ) {
if ( ( V_406 & V_409 ) ==
V_404 )
V_29 |= V_410 ;
} else {
if ( ( V_406 & V_411 ) ==
V_400 )
V_29 |= V_410 ;
if ( ! ( V_406 & V_401 ) )
V_29 |= V_412 ;
if ( V_406 & ( V_403 << 8 ) )
V_29 |= V_413 ;
V_29 |= V_406 & ( V_402 << 8 ) ;
}
return V_29 ;
}
static unsigned int F_226 ( unsigned short V_29 )
{
unsigned int V_406 = 0 ;
if ( V_29 & V_408 )
V_406 |= V_399 ;
if ( V_29 & V_407 )
V_406 |= V_398 ;
if ( V_406 & V_398 ) {
if ( V_29 & V_410 )
V_406 |= V_404 ;
} else {
if ( V_29 & V_410 )
V_406 |= V_400 ;
if ( ! ( V_29 & V_412 ) )
V_406 |= V_401 ;
if ( V_29 & V_413 )
V_406 |= ( V_403 << 8 ) ;
V_406 |= V_29 & ( 0x7f << 8 ) ;
}
return V_406 ;
}
static void F_227 ( struct V_6 * V_7 , T_2 V_25 ,
int V_27 , int V_29 )
{
const T_2 * V_414 ;
F_228 ( V_7 , V_25 , 0 , V_27 , V_29 ) ;
V_414 = V_7 -> V_354 ;
if ( ! V_414 )
return;
for (; * V_414 ; V_414 ++ )
F_228 ( V_7 , * V_414 , 0 , V_27 , V_29 ) ;
}
static inline void F_229 ( struct V_6 * V_7 , T_2 V_25 ,
int V_415 , int V_416 )
{
if ( V_415 != - 1 )
F_227 ( V_7 , V_25 , V_417 , V_415 ) ;
if ( V_416 != - 1 )
F_227 ( V_7 , V_25 , V_418 , V_416 ) ;
}
static int F_230 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
int V_254 = V_297 -> V_337 ;
struct V_207 * V_405 ;
T_2 V_25 ;
unsigned short V_29 ;
int V_311 ;
F_2 ( & V_7 -> V_201 ) ;
V_405 = F_86 ( & V_7 -> V_191 , V_254 ) ;
V_25 = V_405 -> V_25 ;
V_405 -> V_397 = V_309 -> V_303 . V_396 . V_397 [ 0 ] |
( ( unsigned int ) V_309 -> V_303 . V_396 . V_397 [ 1 ] << 8 ) |
( ( unsigned int ) V_309 -> V_303 . V_396 . V_397 [ 2 ] << 16 ) |
( ( unsigned int ) V_309 -> V_303 . V_396 . V_397 [ 3 ] << 24 ) ;
V_29 = F_225 ( V_405 -> V_397 ) ;
V_29 |= V_405 -> V_419 & 1 ;
V_311 = V_405 -> V_419 != V_29 ;
V_405 -> V_419 = V_29 ;
if ( V_311 && V_25 != ( T_4 ) - 1 )
F_229 ( V_7 , V_25 , V_29 & 0xff , ( V_29 >> 8 ) & 0xff ) ;
F_4 ( & V_7 -> V_201 ) ;
return V_311 ;
}
static int F_231 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
int V_254 = V_297 -> V_337 ;
struct V_207 * V_405 ;
F_2 ( & V_7 -> V_201 ) ;
V_405 = F_86 ( & V_7 -> V_191 , V_254 ) ;
V_309 -> V_303 . integer . V_303 [ 0 ] = V_405 -> V_419 & V_420 ;
F_4 ( & V_7 -> V_201 ) ;
return 0 ;
}
static inline void F_232 ( struct V_6 * V_7 , T_2 V_25 ,
int V_415 , int V_416 )
{
F_229 ( V_7 , V_25 , V_415 , V_416 ) ;
if ( ( F_47 ( V_7 , V_25 ) & V_421 ) &&
( V_415 & V_420 ) )
F_155 ( V_7 , V_25 , V_263 , 0 ,
V_285 , 0 ) ;
}
static int F_233 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
int V_254 = V_297 -> V_337 ;
struct V_207 * V_405 ;
T_2 V_25 ;
unsigned short V_29 ;
int V_311 ;
F_2 ( & V_7 -> V_201 ) ;
V_405 = F_86 ( & V_7 -> V_191 , V_254 ) ;
V_25 = V_405 -> V_25 ;
V_29 = V_405 -> V_419 & ~ V_420 ;
if ( V_309 -> V_303 . integer . V_303 [ 0 ] )
V_29 |= V_420 ;
V_311 = V_405 -> V_419 != V_29 ;
V_405 -> V_419 = V_29 ;
if ( V_311 && V_25 != ( T_4 ) - 1 )
F_232 ( V_7 , V_25 , V_29 & 0xff , - 1 ) ;
F_4 ( & V_7 -> V_201 ) ;
return V_311 ;
}
int F_234 ( struct V_6 * V_7 ,
T_2 V_422 ,
T_2 V_423 ,
int type )
{
int V_34 ;
struct V_296 * V_332 ;
struct V_424 * V_425 ;
int V_254 = 0 ;
const int V_426 = 16 ;
struct V_207 * V_405 ;
struct V_9 * V_10 = V_7 -> V_10 ;
if ( V_10 -> V_427 == V_428 &&
type == V_429 ) {
V_254 = V_426 ;
} else if ( V_10 -> V_427 == V_429 &&
type == V_428 ) {
for ( V_425 = V_430 ; V_425 -> V_144 ; V_425 ++ ) {
V_332 = F_175 ( V_7 , V_425 -> V_144 , 0 , 0 ) ;
if ( ! V_332 )
break;
V_332 -> V_137 . V_270 = V_426 ;
}
V_10 -> V_427 = V_428 ;
}
if ( ! V_10 -> V_427 )
V_10 -> V_427 = type ;
V_254 = F_178 ( V_7 , L_70 , V_254 ) ;
if ( V_254 < 0 ) {
F_14 ( V_31 L_71 ) ;
return - V_200 ;
}
V_405 = F_84 ( & V_7 -> V_191 ) ;
if ( ! V_405 )
return - V_55 ;
for ( V_425 = V_430 ; V_425 -> V_144 ; V_425 ++ ) {
V_332 = F_209 ( V_425 , V_7 ) ;
if ( ! V_332 )
return - V_55 ;
V_332 -> V_137 . V_270 = V_254 ;
V_332 -> V_337 = V_7 -> V_191 . V_176 - 1 ;
V_34 = F_179 ( V_7 , V_422 , V_332 ) ;
if ( V_34 < 0 )
return V_34 ;
}
V_405 -> V_25 = V_423 ;
V_405 -> V_419 = F_23 ( V_7 , V_423 , 0 ,
V_431 , 0 ) ;
V_405 -> V_397 = F_226 ( V_405 -> V_419 ) ;
return 0 ;
}
struct V_207 * F_235 ( struct V_6 * V_7 ,
T_2 V_25 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_191 . V_176 ; V_18 ++ ) {
struct V_207 * V_405 =
F_86 ( & V_7 -> V_191 , V_18 ) ;
if ( V_405 -> V_25 == V_25 )
return V_405 ;
}
return NULL ;
}
void F_236 ( struct V_6 * V_7 , int V_254 )
{
struct V_207 * V_405 ;
F_2 ( & V_7 -> V_201 ) ;
V_405 = F_86 ( & V_7 -> V_191 , V_254 ) ;
V_405 -> V_25 = ( T_4 ) - 1 ;
F_4 ( & V_7 -> V_201 ) ;
}
void F_237 ( struct V_6 * V_7 , int V_254 , T_2 V_25 )
{
struct V_207 * V_405 ;
unsigned short V_29 ;
F_2 ( & V_7 -> V_201 ) ;
V_405 = F_86 ( & V_7 -> V_191 , V_254 ) ;
if ( V_405 -> V_25 != V_25 ) {
V_405 -> V_25 = V_25 ;
V_29 = V_405 -> V_419 ;
F_232 ( V_7 , V_25 , V_29 & 0xff , ( V_29 >> 8 ) & 0xff ) ;
}
F_4 ( & V_7 -> V_201 ) ;
}
static int F_238 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_432 * V_433 = F_161 ( V_297 ) ;
V_309 -> V_303 . integer . V_303 [ 0 ] = V_433 -> V_434 ;
return 0 ;
}
static int F_239 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_432 * V_433 = F_161 ( V_297 ) ;
V_433 -> V_434 = ! ! V_309 -> V_303 . integer . V_303 [ 0 ] ;
return 0 ;
}
int F_240 ( struct V_6 * V_7 ,
struct V_432 * V_433 )
{
struct V_296 * V_332 ;
if ( ! V_433 -> V_435 )
return 0 ;
V_332 = F_209 ( & V_436 , V_433 ) ;
if ( ! V_332 )
return - V_55 ;
return F_179 ( V_7 , V_433 -> V_435 , V_332 ) ;
}
static int F_241 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
V_309 -> V_303 . integer . V_303 [ 0 ] = V_7 -> V_437 ;
return 0 ;
}
static int F_242 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
T_2 V_25 = V_297 -> V_337 ;
unsigned int V_29 = ! ! V_309 -> V_303 . integer . V_303 [ 0 ] ;
int V_311 ;
F_2 ( & V_7 -> V_201 ) ;
V_311 = V_7 -> V_437 != V_29 ;
if ( V_311 ) {
V_7 -> V_437 = V_29 ;
F_228 ( V_7 , V_25 , 0 ,
V_417 , V_29 ) ;
}
F_4 ( & V_7 -> V_201 ) ;
return V_311 ;
}
static int F_243 ( struct V_296 * V_297 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_161 ( V_297 ) ;
T_2 V_25 = V_297 -> V_337 ;
unsigned short V_29 ;
unsigned int V_406 ;
V_29 = F_23 ( V_7 , V_25 , 0 , V_431 , 0 ) ;
V_406 = F_226 ( V_29 ) ;
V_309 -> V_303 . V_396 . V_397 [ 0 ] = V_406 ;
V_309 -> V_303 . V_396 . V_397 [ 1 ] = V_406 >> 8 ;
V_309 -> V_303 . V_396 . V_397 [ 2 ] = V_406 >> 16 ;
V_309 -> V_303 . V_396 . V_397 [ 3 ] = V_406 >> 24 ;
return 0 ;
}
int F_244 ( struct V_6 * V_7 , T_2 V_25 )
{
int V_34 ;
struct V_296 * V_332 ;
struct V_424 * V_425 ;
int V_254 ;
V_254 = F_178 ( V_7 , L_72 , 0 ) ;
if ( V_254 < 0 ) {
F_14 ( V_31 L_73 ) ;
return - V_200 ;
}
for ( V_425 = V_438 ; V_425 -> V_144 ; V_425 ++ ) {
V_332 = F_209 ( V_425 , V_7 ) ;
if ( ! V_332 )
return - V_55 ;
V_332 -> V_337 = V_25 ;
V_34 = F_179 ( V_7 , V_25 , V_332 ) ;
if ( V_34 < 0 )
return V_34 ;
}
V_7 -> V_437 =
F_23 ( V_7 , V_25 , 0 ,
V_431 , 0 ) &
V_420 ;
return 0 ;
}
int F_228 ( struct V_6 * V_7 , T_2 V_25 ,
int V_26 , unsigned int V_27 , unsigned int V_28 )
{
int V_34 ;
struct V_205 * V_146 ;
T_1 V_253 ;
unsigned int V_289 ;
V_289 = V_7 -> V_290 ;
if ( ! V_289 ) {
V_34 = F_24 ( V_7 , V_25 , V_26 , V_27 , V_28 ) ;
if ( V_34 < 0 )
return V_34 ;
}
V_27 = V_27 | ( V_28 >> 8 ) ;
V_28 &= 0xff ;
V_253 = F_245 ( V_25 , V_27 ) ;
F_2 ( & V_7 -> V_10 -> V_36 ) ;
V_146 = F_136 ( & V_7 -> V_193 , V_253 ) ;
if ( V_146 ) {
V_146 -> V_29 = V_28 ;
V_146 -> V_244 = V_289 ;
}
F_4 ( & V_7 -> V_10 -> V_36 ) ;
return 0 ;
}
int F_246 ( struct V_6 * V_7 , T_2 V_25 ,
int V_26 , unsigned int V_27 , unsigned int V_28 )
{
struct V_205 * V_146 ;
T_1 V_253 ;
V_27 = V_27 | ( V_28 >> 8 ) ;
V_28 &= 0xff ;
V_253 = F_245 ( V_25 , V_27 ) ;
F_2 ( & V_7 -> V_10 -> V_36 ) ;
V_146 = F_135 ( & V_7 -> V_193 , V_253 ) ;
if ( V_146 && V_146 -> V_29 == V_28 ) {
F_4 ( & V_7 -> V_10 -> V_36 ) ;
return 0 ;
}
F_4 ( & V_7 -> V_10 -> V_36 ) ;
return F_228 ( V_7 , V_25 , V_26 , V_27 , V_28 ) ;
}
void F_247 ( struct V_6 * V_7 )
{
int V_18 ;
F_2 ( & V_7 -> V_203 ) ;
V_7 -> V_290 = 0 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_193 . V_252 . V_176 ; V_18 ++ ) {
struct V_205 * V_292 ;
T_1 V_253 ;
V_292 = F_86 ( & V_7 -> V_193 . V_252 , V_18 ) ;
V_253 = V_292 -> V_253 ;
if ( ! V_253 )
continue;
if ( ! V_292 -> V_244 )
continue;
V_292 -> V_244 = 0 ;
F_4 ( & V_7 -> V_203 ) ;
F_24 ( V_7 , F_248 ( V_253 ) , 0 ,
F_249 ( V_253 ) , V_292 -> V_29 ) ;
F_2 ( & V_7 -> V_203 ) ;
}
F_4 ( & V_7 -> V_203 ) ;
}
void F_250 ( struct V_6 * V_7 ,
const struct V_46 * V_47 )
{
for (; V_47 -> V_25 ; V_47 ++ )
F_228 ( V_7 , V_47 -> V_25 , 0 , V_47 -> V_27 ,
V_47 -> V_48 ) ;
}
void F_251 ( struct V_6 * V_7 )
{
F_158 ( V_7 ) ;
F_247 ( V_7 ) ;
}
void F_252 ( struct V_6 * V_7 , T_2 V_198 ,
unsigned int V_439 )
{
T_2 V_25 = V_7 -> V_165 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_164 ; V_18 ++ , V_25 ++ ) {
unsigned int V_64 = F_47 ( V_7 , V_25 ) ;
unsigned int V_440 = V_439 ;
if ( ! ( V_64 & V_441 ) )
continue;
if ( V_7 -> V_442 ) {
V_440 = V_7 -> V_442 ( V_7 , V_25 , V_439 ) ;
if ( V_440 != V_439 && V_439 == V_443 )
continue;
}
F_24 ( V_7 , V_25 , 0 , V_444 ,
V_440 ) ;
}
}
static bool F_114 ( struct V_6 * V_7 , T_2 V_198 ,
unsigned int V_439 )
{
int V_445 = F_27 ( V_7 , V_198 , V_446 ) ;
if ( V_445 == - 1 )
return false ;
if ( V_445 & V_439 )
return true ;
else
return false ;
}
static unsigned int F_253 ( struct V_6 * V_7 ,
T_2 V_198 ,
unsigned int V_439 )
{
unsigned long V_447 = V_448 + F_254 ( 500 ) ;
unsigned int V_440 , V_449 ;
for (; ; ) {
V_440 = F_23 ( V_7 , V_198 , 0 ,
V_450 , 0 ) ;
if ( V_440 & V_451 )
break;
V_449 = ( V_440 >> 4 ) & 0x0f ;
if ( V_449 == V_439 )
break;
if ( F_255 ( V_448 , V_447 ) )
break;
F_129 ( 1 ) ;
}
return V_440 ;
}
unsigned int F_256 ( struct V_6 * V_7 ,
T_2 V_25 ,
unsigned int V_439 )
{
if ( V_25 == V_7 -> V_138 || V_25 == V_7 -> V_139 )
return V_439 ;
if ( V_439 == V_443 &&
F_48 ( F_47 ( V_7 , V_25 ) ) == V_85 &&
( F_146 ( V_7 , V_25 ) & V_452 ) ) {
int V_453 = F_23 ( V_7 , V_25 , 0 ,
V_454 , 0 ) ;
if ( V_453 & 0x02 )
return V_225 ;
}
return V_439 ;
}
static unsigned int F_115 ( struct V_6 * V_7 ,
unsigned int V_439 )
{
T_2 V_198 = V_7 -> V_138 ? V_7 -> V_138 : V_7 -> V_139 ;
int V_302 ;
unsigned int V_440 ;
int V_26 = 0 ;
if ( V_439 == V_443 ) {
if ( V_7 -> V_211 < 0 )
F_129 ( V_7 -> V_222 ? 10 : 100 ) ;
else if ( V_7 -> V_211 > 0 )
F_129 ( V_7 -> V_211 ) ;
V_26 = V_37 ;
}
for ( V_302 = 0 ; V_302 < 10 ; V_302 ++ ) {
if ( V_7 -> V_108 . V_455 )
V_7 -> V_108 . V_455 ( V_7 , V_198 ,
V_439 ) ;
else {
V_440 = V_439 ;
if ( V_7 -> V_442 )
V_440 = V_7 -> V_442 ( V_7 , V_198 , V_440 ) ;
if ( V_440 == V_439 || V_439 != V_443 )
F_23 ( V_7 , V_198 , V_26 ,
V_444 ,
V_440 ) ;
F_252 ( V_7 , V_198 , V_439 ) ;
}
V_440 = F_253 ( V_7 , V_198 , V_439 ) ;
if ( ! ( V_440 & V_451 ) )
break;
}
return V_440 ;
}
static void F_257 ( struct V_6 * V_7 )
{
T_2 V_25 = V_7 -> V_165 ;
int V_18 ;
if ( ! V_7 -> V_442 )
return;
for ( V_18 = 0 ; V_18 < V_7 -> V_164 ; V_18 ++ , V_25 ++ ) {
unsigned int V_64 = F_47 ( V_7 , V_25 ) ;
unsigned int V_180 ;
if ( ! ( V_64 & V_441 ) )
continue;
V_180 = V_7 -> V_442 ( V_7 , V_25 , V_225 ) ;
if ( V_180 == V_225 )
continue;
if ( ! F_258 ( V_7 , V_25 , V_180 ) )
F_24 ( V_7 , V_25 , 0 ,
V_444 , V_180 ) ;
}
}
static void F_259 ( struct V_6 * V_7 )
{
if ( V_7 -> V_456 . V_4 )
F_25 ( V_7 , V_7 -> V_456 . V_4 ) ;
}
static inline void F_259 ( struct V_6 * V_7 ) {}
static unsigned int F_260 ( struct V_6 * V_7 , bool V_457 )
{
unsigned int V_440 ;
V_7 -> V_458 = 1 ;
if ( V_7 -> V_108 . V_459 )
V_7 -> V_108 . V_459 ( V_7 ) ;
F_134 ( V_7 ) ;
V_440 = F_115 ( V_7 , V_443 ) ;
if ( ! V_457 )
F_104 ( & V_7 -> V_188 ) ;
F_186 ( & V_7 -> V_212 ) ;
F_261 ( V_7 ) ;
F_262 ( V_7 ) ;
V_7 -> V_460 = 0 ;
V_7 -> V_461 = 0 ;
V_7 -> V_462 = V_448 ;
F_187 ( & V_7 -> V_212 ) ;
V_7 -> V_458 = 0 ;
return V_440 ;
}
static void F_263 ( struct V_6 * V_7 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_193 . V_252 . V_176 ; V_18 ++ ) {
struct V_205 * V_32 ;
V_32 = F_86 ( & V_7 -> V_193 . V_252 , V_18 ) ;
V_32 -> V_244 = 1 ;
}
for ( V_18 = 0 ; V_18 < V_7 -> V_192 . V_252 . V_176 ; V_18 ++ ) {
struct V_204 * V_463 ;
V_463 = F_86 ( & V_7 -> V_192 . V_252 , V_18 ) ;
V_463 -> V_259 . V_244 = 1 ;
}
}
static void F_264 ( struct V_6 * V_7 )
{
V_7 -> V_458 = 1 ;
F_263 ( V_7 ) ;
F_8 ( V_7 ) ;
F_115 ( V_7 , V_225 ) ;
F_94 ( V_7 ) ;
F_259 ( V_7 ) ;
F_96 ( V_7 ) ;
if ( V_7 -> V_108 . V_464 )
V_7 -> V_108 . V_464 ( V_7 ) ;
else {
if ( V_7 -> V_108 . V_465 )
V_7 -> V_108 . V_465 ( V_7 ) ;
F_158 ( V_7 ) ;
F_247 ( V_7 ) ;
}
if ( V_7 -> V_184 )
F_95 ( & V_7 -> V_183 . V_103 ) ;
else
F_265 ( V_7 ) ;
V_7 -> V_458 = 0 ;
F_19 ( V_7 ) ;
}
int F_266 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_29 (codec, &bus->codec_list, list) {
int V_34 = F_267 ( V_7 ) ;
if ( V_34 < 0 ) {
F_14 ( V_31 L_74
L_75 , V_7 -> V_30 , V_34 ) ;
V_34 = F_189 ( V_7 ) ;
if ( V_34 < 0 ) {
F_14 ( V_31
L_76 ) ;
return V_34 ;
}
}
}
return 0 ;
}
static int F_268 ( struct V_6 * V_7 )
{
int V_18 , V_466 , V_34 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_345 ; V_18 ++ ) {
for ( V_466 = 0 ; V_466 < 2 ; V_466 ++ ) {
struct V_467 * V_344 = V_7 -> V_348 [ V_18 ] . V_344 ;
struct V_468 * V_469 =
& V_7 -> V_348 [ V_18 ] . V_470 [ V_466 ] ;
struct V_471 * V_472 ;
const struct V_473 * V_474 ;
if ( V_7 -> V_348 [ V_18 ] . V_475 )
continue;
if ( ! V_344 || ! V_469 -> V_476 )
continue;
V_474 = V_469 -> V_472 ? V_469 -> V_472 : V_477 ;
V_34 = F_269 ( V_344 , V_466 , V_474 ,
V_469 -> V_478 ,
0 , & V_472 ) ;
if ( V_34 < 0 )
return V_34 ;
V_472 -> V_479 = V_480 ;
}
}
return 0 ;
}
int F_267 ( struct V_6 * V_7 )
{
int V_34 = 0 ;
F_259 ( V_7 ) ;
if ( V_7 -> V_108 . V_465 )
V_34 = V_7 -> V_108 . V_465 ( V_7 ) ;
if ( ! V_34 && V_7 -> V_108 . V_481 )
V_34 = V_7 -> V_108 . V_481 ( V_7 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_268 ( V_7 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_7 -> V_184 )
F_95 ( & V_7 -> V_183 . V_103 ) ;
else
F_265 ( V_7 ) ;
F_257 ( V_7 ) ;
return 0 ;
}
unsigned int F_270 ( unsigned int V_482 ,
unsigned int V_483 ,
unsigned int V_238 ,
unsigned int V_484 ,
unsigned short V_485 )
{
int V_18 ;
unsigned int V_29 = 0 ;
for ( V_18 = 0 ; V_486 [ V_18 ] . V_487 ; V_18 ++ )
if ( V_486 [ V_18 ] . V_487 == V_482 ) {
V_29 = V_486 [ V_18 ] . V_488 ;
break;
}
if ( ! V_486 [ V_18 ] . V_487 ) {
F_49 ( L_77 , V_482 ) ;
return 0 ;
}
if ( V_483 == 0 || V_483 > 8 ) {
F_49 ( L_78 , V_483 ) ;
return 0 ;
}
V_29 |= V_483 - 1 ;
switch ( F_271 ( V_238 ) ) {
case 8 :
V_29 |= V_489 ;
break;
case 16 :
V_29 |= V_490 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_484 >= 32 || V_238 == V_491 )
V_29 |= V_492 ;
else if ( V_484 >= 24 )
V_29 |= V_493 ;
else
V_29 |= V_494 ;
break;
default:
F_49 ( L_79 ,
F_271 ( V_238 ) ) ;
return 0 ;
}
if ( V_485 & V_408 )
V_29 |= V_495 ;
return V_29 ;
}
static unsigned int F_272 ( struct V_6 * V_7 , T_2 V_25 ,
int V_266 )
{
unsigned int V_29 = 0 ;
if ( V_25 != V_7 -> V_138 &&
( F_47 ( V_7 , V_25 ) & V_496 ) )
V_29 = F_27 ( V_7 , V_25 , V_497 ) ;
if ( ! V_29 || V_29 == - 1 )
V_29 = F_27 ( V_7 , V_7 -> V_138 , V_497 ) ;
if ( ! V_29 || V_29 == - 1 )
return 0 ;
return V_29 ;
}
static unsigned int F_273 ( struct V_6 * V_7 , T_2 V_25 )
{
return F_142 ( V_7 , V_25 , 0 , F_274 ( V_25 ) ,
F_272 ) ;
}
static unsigned int F_275 ( struct V_6 * V_7 , T_2 V_25 ,
int V_266 )
{
unsigned int V_349 = F_27 ( V_7 , V_25 , V_498 ) ;
if ( ! V_349 || V_349 == - 1 )
V_349 = F_27 ( V_7 , V_7 -> V_138 , V_498 ) ;
if ( ! V_349 || V_349 == - 1 )
return 0 ;
return V_349 ;
}
static unsigned int F_276 ( struct V_6 * V_7 , T_2 V_25 )
{
return F_142 ( V_7 , V_25 , 0 , F_277 ( V_25 ) ,
F_275 ) ;
}
int F_278 ( struct V_6 * V_7 , T_2 V_25 ,
T_1 * V_499 , T_8 * V_500 , unsigned int * V_501 )
{
unsigned int V_18 , V_29 , V_64 ;
V_64 = F_47 ( V_7 , V_25 ) ;
V_29 = F_273 ( V_7 , V_25 ) ;
if ( V_499 ) {
T_1 V_502 = 0 ;
for ( V_18 = 0 ; V_18 < V_503 ; V_18 ++ ) {
if ( V_29 & ( 1 << V_18 ) )
V_502 |= V_486 [ V_18 ] . V_504 ;
}
if ( V_502 == 0 ) {
F_45 ( V_31 L_80
L_81 ,
V_25 , V_29 ,
( V_64 & V_496 ) ? 1 : 0 ) ;
return - V_77 ;
}
* V_499 = V_502 ;
}
if ( V_500 || V_501 ) {
T_8 V_505 = 0 ;
unsigned int V_349 , V_506 ;
V_349 = F_276 ( V_7 , V_25 ) ;
if ( ! V_349 )
return - V_77 ;
V_506 = 0 ;
if ( V_349 & V_507 ) {
if ( V_29 & V_508 ) {
V_505 |= V_509 ;
V_506 = 8 ;
}
if ( V_29 & V_510 ) {
V_505 |= V_511 ;
V_506 = 16 ;
}
if ( V_64 & V_88 ) {
if ( V_29 & V_512 )
V_505 |= V_513 ;
if ( V_29 & ( V_514 | V_515 ) )
V_505 |= V_516 ;
if ( V_29 & V_515 )
V_506 = 24 ;
else if ( V_29 & V_514 )
V_506 = 20 ;
} else if ( V_29 & ( V_514 | V_515 |
V_512 ) ) {
V_505 |= V_516 ;
if ( V_29 & V_512 )
V_506 = 32 ;
else if ( V_29 & V_515 )
V_506 = 24 ;
else if ( V_29 & V_514 )
V_506 = 20 ;
}
}
#if 0
if (streams & AC_SUPFMT_FLOAT32) {
formats |= SNDRV_PCM_FMTBIT_FLOAT_LE;
if (!bps)
bps = 32;
}
#endif
if ( V_349 == V_517 ) {
V_505 |= V_509 ;
V_506 = 8 ;
}
if ( V_505 == 0 ) {
F_45 ( V_31 L_82
L_83
L_84 ,
V_25 , V_29 ,
( V_64 & V_496 ) ? 1 : 0 ,
V_349 ) ;
return - V_77 ;
}
if ( V_500 )
* V_500 = V_505 ;
if ( V_501 )
* V_501 = V_506 ;
}
return 0 ;
}
int F_279 ( struct V_6 * V_7 , T_2 V_25 ,
unsigned int V_238 )
{
int V_18 ;
unsigned int V_29 = 0 , V_482 , V_470 ;
V_29 = F_273 ( V_7 , V_25 ) ;
if ( ! V_29 )
return 0 ;
V_482 = V_238 & 0xff00 ;
for ( V_18 = 0 ; V_18 < V_503 ; V_18 ++ )
if ( V_486 [ V_18 ] . V_488 == V_482 ) {
if ( V_29 & ( 1 << V_18 ) )
break;
return 0 ;
}
if ( V_18 >= V_503 )
return 0 ;
V_470 = F_276 ( V_7 , V_25 ) ;
if ( ! V_470 )
return 0 ;
if ( V_470 & V_507 ) {
switch ( V_238 & 0xf0 ) {
case 0x00 :
if ( ! ( V_29 & V_508 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_29 & V_510 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_29 & V_514 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_29 & V_515 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_29 & V_512 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_280 ( struct V_468 * V_469 ,
struct V_6 * V_7 ,
struct V_518 * V_519 )
{
return 0 ;
}
static int F_281 ( struct V_468 * V_469 ,
struct V_6 * V_7 ,
unsigned int V_232 ,
unsigned int V_238 ,
struct V_518 * V_519 )
{
F_130 ( V_7 , V_469 -> V_25 , V_232 , 0 , V_238 ) ;
return 0 ;
}
static int F_282 ( struct V_468 * V_469 ,
struct V_6 * V_7 ,
struct V_518 * V_519 )
{
F_283 ( V_7 , V_469 -> V_25 ) ;
return 0 ;
}
static int F_284 ( struct V_6 * V_7 ,
struct V_468 * V_256 )
{
int V_34 ;
if ( V_256 -> V_25 && ( ! V_256 -> V_502 || ! V_256 -> V_505 ) ) {
V_34 = F_278 ( V_7 , V_256 -> V_25 ,
V_256 -> V_502 ? NULL : & V_256 -> V_502 ,
V_256 -> V_505 ? NULL : & V_256 -> V_505 ,
V_256 -> V_484 ? NULL : & V_256 -> V_484 ) ;
if ( V_34 < 0 )
return V_34 ;
}
if ( V_256 -> V_12 . V_520 == NULL )
V_256 -> V_12 . V_520 = F_280 ;
if ( V_256 -> V_12 . V_521 == NULL )
V_256 -> V_12 . V_521 = F_280 ;
if ( V_256 -> V_12 . V_522 == NULL ) {
if ( F_43 ( ! V_256 -> V_25 ) )
return - V_62 ;
V_256 -> V_12 . V_522 = F_281 ;
}
if ( V_256 -> V_12 . V_523 == NULL ) {
if ( F_43 ( ! V_256 -> V_25 ) )
return - V_62 ;
V_256 -> V_12 . V_523 = F_282 ;
}
return 0 ;
}
int F_285 ( struct V_6 * V_7 ,
struct V_468 * V_469 ,
unsigned int V_470 ,
unsigned int V_238 ,
struct V_518 * V_519 )
{
int V_291 ;
F_2 ( & V_7 -> V_10 -> V_128 ) ;
V_291 = V_469 -> V_12 . V_522 ( V_469 , V_7 , V_470 , V_238 , V_519 ) ;
if ( V_291 >= 0 )
F_133 ( V_7 ) ;
F_4 ( & V_7 -> V_10 -> V_128 ) ;
return V_291 ;
}
void F_286 ( struct V_6 * V_7 ,
struct V_468 * V_469 ,
struct V_518 * V_519 )
{
F_2 ( & V_7 -> V_10 -> V_128 ) ;
V_469 -> V_12 . V_523 ( V_469 , V_7 , V_519 ) ;
F_4 ( & V_7 -> V_10 -> V_128 ) ;
}
static int F_287 ( struct V_9 * V_10 , unsigned int type )
{
static int V_524 [ V_525 ] [ 5 ] = {
[ V_526 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_429 ] = { 1 , - 1 } ,
[ V_428 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_527 ] = { 6 , - 1 } ,
} ;
int V_18 ;
if ( type >= V_525 ) {
F_45 ( V_80 L_85 , type ) ;
return - V_62 ;
}
for ( V_18 = 0 ; V_524 [ type ] [ V_18 ] >= 0 ; V_18 ++ ) {
#ifndef F_288
if ( V_524 [ type ] [ V_18 ] >= 8 )
break;
#endif
if ( ! F_289 ( V_524 [ type ] [ V_18 ] , V_10 -> V_351 ) )
return V_524 [ type ] [ V_18 ] ;
}
#ifdef F_288
for ( V_18 = 10 ; V_18 < 32 ; V_18 ++ ) {
if ( ! F_289 ( V_18 , V_10 -> V_351 ) )
return V_18 ;
}
#endif
F_45 ( V_80 L_86 ,
V_528 [ type ] ) ;
#ifndef F_288
F_45 ( V_80 L_87 ) ;
#endif
return - V_40 ;
}
static int F_290 ( struct V_6 * V_7 , struct V_346 * V_344 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_468 * V_256 ;
int V_470 , V_34 ;
if ( F_43 ( ! V_344 -> V_144 ) )
return - V_62 ;
for ( V_470 = 0 ; V_470 < 2 ; V_470 ++ ) {
V_256 = & V_344 -> V_470 [ V_470 ] ;
if ( V_256 -> V_476 ) {
V_34 = F_284 ( V_7 , V_256 ) ;
if ( V_34 < 0 )
return V_34 ;
}
}
return V_10 -> V_12 . V_529 ( V_10 , V_7 , V_344 ) ;
}
int F_291 ( struct V_6 * V_7 )
{
unsigned int V_344 ;
int V_34 ;
if ( ! V_7 -> V_345 ) {
if ( ! V_7 -> V_108 . V_530 )
return 0 ;
V_34 = V_7 -> V_108 . V_530 ( V_7 ) ;
if ( V_34 < 0 ) {
F_14 ( V_31 L_88
L_75 , V_7 -> V_30 , V_34 ) ;
V_34 = F_189 ( V_7 ) ;
if ( V_34 < 0 ) {
F_14 ( V_31
L_76 ) ;
return V_34 ;
}
}
}
for ( V_344 = 0 ; V_344 < V_7 -> V_345 ; V_344 ++ ) {
struct V_346 * V_347 = & V_7 -> V_348 [ V_344 ] ;
int V_327 ;
if ( ! V_347 -> V_470 [ 0 ] . V_476 && ! V_347 -> V_470 [ 1 ] . V_476 )
continue;
if ( ! V_347 -> V_344 ) {
V_327 = F_287 ( V_7 -> V_10 , V_347 -> V_531 ) ;
if ( V_327 < 0 )
continue;
V_347 -> V_112 = V_327 ;
V_34 = F_290 ( V_7 , V_347 ) ;
if ( V_34 < 0 ) {
F_14 ( V_31 L_89
L_90 ,
V_327 , V_7 -> V_30 ) ;
continue;
}
}
}
return 0 ;
}
int F_292 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_29 (codec, &bus->codec_list, list) {
int V_34 = F_291 ( V_7 ) ;
if ( V_34 < 0 )
return V_34 ;
}
return 0 ;
}
int F_293 ( struct V_6 * V_7 ,
int V_532 , const char * const * V_533 ,
const struct V_534 * V_134 )
{
if ( V_7 -> V_126 && V_533 ) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_532 ; V_18 ++ ) {
if ( V_533 [ V_18 ] &&
! strcmp ( V_7 -> V_126 , V_533 [ V_18 ] ) ) {
F_21 ( V_535 L_91
L_92 , V_533 [ V_18 ] ) ;
return V_18 ;
}
}
}
if ( ! V_7 -> V_10 -> V_125 || ! V_134 )
return - 1 ;
V_134 = F_294 ( V_7 -> V_10 -> V_125 , V_134 ) ;
if ( ! V_134 )
return - 1 ;
if ( V_134 -> V_303 >= 0 && V_134 -> V_303 < V_532 ) {
#ifdef F_295
char V_148 [ 10 ] ;
const char * V_536 = NULL ;
if ( V_533 )
V_536 = V_533 [ V_134 -> V_303 ] ;
if ( ! V_536 ) {
sprintf ( V_148 , L_93 , V_134 -> V_303 ) ;
V_536 = V_148 ;
}
F_49 ( V_535 L_94
L_95 ,
V_536 , V_134 -> V_537 , V_134 -> V_334 ,
( V_134 -> V_144 ? V_134 -> V_144 : L_96 ) ) ;
#endif
return V_134 -> V_303 ;
}
return - 1 ;
}
int F_296 ( struct V_6 * V_7 ,
int V_532 , const char * const * V_533 ,
const struct V_534 * V_134 )
{
const struct V_534 * V_247 ;
for ( V_247 = V_134 ; V_247 -> V_537 ; V_247 ++ ) {
unsigned int V_71 = 0xffff0000 | V_247 -> V_538 ;
unsigned int V_137 = ( V_247 -> V_334 | ( V_247 -> V_537 << 16 ) ) & V_71 ;
if ( ( V_7 -> V_216 & V_71 ) == V_137 )
break;
}
if ( ! V_247 -> V_537 )
return - 1 ;
V_134 = V_247 ;
if ( V_134 -> V_303 >= 0 && V_134 -> V_303 < V_532 ) {
#ifdef F_295
char V_148 [ 10 ] ;
const char * V_536 = NULL ;
if ( V_533 )
V_536 = V_533 [ V_134 -> V_303 ] ;
if ( ! V_536 ) {
sprintf ( V_148 , L_93 , V_134 -> V_303 ) ;
V_536 = V_148 ;
}
F_49 ( V_535 L_94
L_95 ,
V_536 , V_134 -> V_537 , V_134 -> V_334 ,
( V_134 -> V_144 ? V_134 -> V_144 : L_96 ) ) ;
#endif
return V_134 -> V_303 ;
}
return - 1 ;
}
int F_297 ( struct V_6 * V_7 ,
const struct V_424 * V_539 )
{
int V_34 ;
for (; V_539 -> V_144 ; V_539 ++ ) {
struct V_296 * V_332 ;
int V_30 = 0 , V_254 = 0 ;
if ( V_539 -> V_329 == - 1 )
continue;
for (; ; ) {
V_332 = F_209 ( V_539 , V_7 ) ;
if ( ! V_332 )
return - V_55 ;
if ( V_30 > 0 )
V_332 -> V_137 . V_112 = V_30 ;
if ( V_254 > 0 )
V_332 -> V_137 . V_270 = V_254 ;
V_34 = F_179 ( V_7 , 0 , V_332 ) ;
if ( ! V_34 )
break;
if ( ! V_30 && V_7 -> V_30 )
V_30 = V_7 -> V_30 ;
else if ( ! V_254 && ! V_539 -> V_270 ) {
V_254 = F_178 ( V_7 ,
V_539 -> V_144 , 0 ) ;
if ( V_254 <= 0 )
return V_34 ;
} else
return V_34 ;
}
}
return 0 ;
}
static void V_213 ( struct V_104 * V_103 )
{
struct V_6 * V_7 =
F_57 ( V_103 , struct V_6 , V_188 . V_103 ) ;
struct V_9 * V_10 = V_7 -> V_10 ;
unsigned int V_440 ;
F_186 ( & V_7 -> V_212 ) ;
if ( V_7 -> V_461 > 0 ) {
F_187 ( & V_7 -> V_212 ) ;
return;
}
if ( ! V_7 -> V_460 || V_7 -> V_540 ) {
V_7 -> V_461 = 0 ;
F_187 ( & V_7 -> V_212 ) ;
return;
}
F_187 ( & V_7 -> V_212 ) ;
V_440 = F_260 ( V_7 , true ) ;
if ( ! V_10 -> V_224 && ( V_440 & V_541 ) )
F_7 ( V_7 , false ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
F_186 ( & V_7 -> V_212 ) ;
V_7 -> V_540 ++ ;
V_7 -> V_460 = 1 ;
V_7 -> V_462 = V_448 ;
F_187 ( & V_7 -> V_212 ) ;
F_7 ( V_7 , true ) ;
}
void F_261 ( struct V_6 * V_7 )
{
unsigned long V_542 = V_448 - V_7 -> V_462 ;
if ( V_7 -> V_460 )
V_7 -> V_543 += V_542 ;
else
V_7 -> V_544 += V_542 ;
V_7 -> V_462 += V_542 ;
}
static void F_298 ( struct V_6 * V_7 , bool V_545 )
{
if ( ( V_7 -> V_460 || V_7 -> V_461 > 0 ) &&
! ( V_545 && V_7 -> V_461 < 0 ) )
return;
F_187 ( & V_7 -> V_212 ) ;
F_104 ( & V_7 -> V_188 ) ;
F_186 ( & V_7 -> V_212 ) ;
if ( V_7 -> V_460 ) {
if ( V_7 -> V_461 < 0 )
V_7 -> V_461 = 0 ;
return;
}
F_299 ( V_7 ) ;
F_261 ( V_7 ) ;
V_7 -> V_460 = 1 ;
V_7 -> V_462 = V_448 ;
V_7 -> V_461 = 1 ;
F_187 ( & V_7 -> V_212 ) ;
F_264 ( V_7 ) ;
F_186 ( & V_7 -> V_212 ) ;
V_7 -> V_461 = 0 ;
}
static void F_300 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_460 || V_7 -> V_540 || V_7 -> V_461 )
return;
if ( V_127 ( V_7 ) ) {
V_7 -> V_461 = - 1 ;
F_98 ( V_7 -> V_10 -> V_100 , & V_7 -> V_188 ,
F_254 ( V_127 ( V_7 ) * 1000 ) ) ;
}
}
void F_301 ( struct V_6 * V_7 , int V_542 , bool V_546 )
{
F_186 ( & V_7 -> V_212 ) ;
V_7 -> V_540 += V_542 ;
F_302 ( V_7 ) ;
if ( V_542 > 0 )
F_298 ( V_7 , V_546 ) ;
else
F_300 ( V_7 ) ;
F_187 ( & V_7 -> V_212 ) ;
}
int F_303 ( struct V_6 * V_7 ,
struct V_547 * V_548 ,
T_2 V_25 )
{
const struct V_549 * V_52 ;
int V_269 , V_550 ;
if ( ! V_548 -> V_551 )
return 0 ;
for ( V_52 = V_548 -> V_551 ; V_52 -> V_25 ; V_52 ++ ) {
if ( V_52 -> V_25 == V_25 )
break;
}
if ( ! V_52 -> V_25 )
return 0 ;
for ( V_52 = V_548 -> V_551 ; V_52 -> V_25 ; V_52 ++ ) {
for ( V_269 = 0 ; V_269 < 2 ; V_269 ++ ) {
V_550 = F_152 ( V_7 , V_52 -> V_25 , V_269 , V_52 -> V_266 ,
V_52 -> V_254 ) ;
if ( ! ( V_550 & V_285 ) && V_550 > 0 ) {
if ( ! V_548 -> V_460 ) {
V_548 -> V_460 = 1 ;
F_16 ( V_7 ) ;
}
return 1 ;
}
}
}
if ( V_548 -> V_460 ) {
V_548 -> V_460 = 0 ;
F_19 ( V_7 ) ;
}
return 0 ;
}
int F_304 ( struct V_6 * V_7 ,
struct V_298 * V_299 ,
const struct V_552 * V_553 ,
int V_554 )
{
V_299 -> type = V_376 ;
V_299 -> V_302 = 1 ;
V_299 -> V_303 . V_377 . V_339 = V_554 ;
if ( V_299 -> V_303 . V_377 . V_333 >= V_554 )
V_299 -> V_303 . V_377 . V_333 = V_554 - 1 ;
sprintf ( V_299 -> V_303 . V_377 . V_144 , L_97 ,
V_553 [ V_299 -> V_303 . V_377 . V_333 ] . V_483 ) ;
return 0 ;
}
int F_305 ( struct V_6 * V_7 ,
struct V_308 * V_309 ,
const struct V_552 * V_553 ,
int V_554 ,
int V_555 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_554 ; V_18 ++ ) {
if ( V_555 == V_553 [ V_18 ] . V_483 ) {
V_309 -> V_303 . V_377 . V_333 [ 0 ] = V_18 ;
break;
}
}
return 0 ;
}
int F_306 ( struct V_6 * V_7 ,
struct V_308 * V_309 ,
const struct V_552 * V_553 ,
int V_554 ,
int * V_556 )
{
unsigned int V_557 ;
V_557 = V_309 -> V_303 . V_377 . V_333 [ 0 ] ;
if ( V_557 >= V_554 )
return - V_62 ;
if ( * V_556 == V_553 [ V_557 ] . V_483 )
return 0 ;
* V_556 = V_553 [ V_557 ] . V_483 ;
if ( V_553 [ V_557 ] . V_558 )
F_250 ( V_7 , V_553 [ V_557 ] . V_558 ) ;
return 1 ;
}
int F_307 ( const struct V_559 * V_560 ,
struct V_298 * V_299 )
{
unsigned int V_270 ;
V_299 -> type = V_376 ;
V_299 -> V_302 = 1 ;
V_299 -> V_303 . V_377 . V_339 = V_560 -> V_561 ;
if ( ! V_560 -> V_561 )
return 0 ;
V_270 = V_299 -> V_303 . V_377 . V_333 ;
if ( V_270 >= V_560 -> V_561 )
V_270 = V_560 -> V_561 - 1 ;
strcpy ( V_299 -> V_303 . V_377 . V_144 , V_560 -> V_339 [ V_270 ] . V_562 ) ;
return 0 ;
}
int F_308 ( struct V_6 * V_7 ,
const struct V_559 * V_560 ,
struct V_308 * V_309 ,
T_2 V_25 ,
unsigned int * V_563 )
{
unsigned int V_254 ;
if ( ! V_560 -> V_561 )
return 0 ;
V_254 = V_309 -> V_303 . V_377 . V_333 [ 0 ] ;
if ( V_254 >= V_560 -> V_561 )
V_254 = V_560 -> V_561 - 1 ;
if ( * V_563 == V_254 )
return 0 ;
F_228 ( V_7 , V_25 , 0 , V_564 ,
V_560 -> V_339 [ V_254 ] . V_270 ) ;
* V_563 = V_254 ;
return 1 ;
}
int F_309 ( struct V_296 * V_297 ,
struct V_298 * V_299 ,
int V_561 , const char * const * V_375 )
{
static const char * const V_565 [] = {
L_98 , L_99
} ;
if ( ! V_375 || ! V_561 ) {
V_561 = 2 ;
V_375 = V_565 ;
}
V_299 -> type = V_376 ;
V_299 -> V_302 = 1 ;
V_299 -> V_303 . V_377 . V_339 = V_561 ;
if ( V_299 -> V_303 . V_377 . V_333 >= V_299 -> V_303 . V_377 . V_339 )
V_299 -> V_303 . V_377 . V_333 = V_299 -> V_303 . V_377 . V_339 - 1 ;
strcpy ( V_299 -> V_303 . V_377 . V_144 ,
V_375 [ V_299 -> V_303 . V_377 . V_333 ] ) ;
return 0 ;
}
static void F_310 ( struct V_6 * V_7 , T_2 V_25 ,
unsigned int V_232 , unsigned int V_238 )
{
struct V_207 * V_405 ;
unsigned int V_566 ;
bool V_567 ;
V_405 = F_235 ( V_7 , V_25 ) ;
V_566 = F_23 ( V_7 , V_25 , 0 ,
V_240 , 0 ) ;
V_567 = V_7 -> V_355 &&
( V_405 -> V_419 & V_420 ) &&
V_566 != V_238 ;
if ( V_567 )
F_229 ( V_7 , V_25 ,
V_405 -> V_419 & ~ V_420 & 0xff ,
- 1 ) ;
F_130 ( V_7 , V_25 , V_232 , 0 , V_238 ) ;
if ( V_7 -> V_354 ) {
const T_2 * V_414 ;
for ( V_414 = V_7 -> V_354 ; * V_414 ; V_414 ++ )
F_130 ( V_7 , * V_414 , V_232 , 0 ,
V_238 ) ;
}
if ( V_567 )
F_229 ( V_7 , V_25 ,
V_405 -> V_419 & 0xff , - 1 ) ;
}
static void F_311 ( struct V_6 * V_7 , T_2 V_25 )
{
F_283 ( V_7 , V_25 ) ;
if ( V_7 -> V_354 ) {
const T_2 * V_414 ;
for ( V_414 = V_7 -> V_354 ; * V_414 ; V_414 ++ )
F_283 ( V_7 , * V_414 ) ;
}
}
void F_312 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
if ( ! V_10 )
return;
F_29 (codec, &bus->codec_list, list) {
if ( F_313 ( V_7 ) &&
V_7 -> V_108 . V_568 )
V_7 -> V_108 . V_568 ( V_7 ) ;
}
}
int F_314 ( struct V_6 * V_7 ,
struct V_432 * V_433 )
{
F_2 ( & V_7 -> V_201 ) ;
if ( V_433 -> V_569 == V_570 )
F_311 ( V_7 , V_433 -> V_435 ) ;
V_433 -> V_569 = V_571 ;
F_4 ( & V_7 -> V_201 ) ;
return 0 ;
}
int F_315 ( struct V_6 * V_7 ,
struct V_432 * V_433 ,
unsigned int V_232 ,
unsigned int V_238 ,
struct V_518 * V_519 )
{
F_2 ( & V_7 -> V_201 ) ;
F_310 ( V_7 , V_433 -> V_435 , V_232 , V_238 ) ;
F_4 ( & V_7 -> V_201 ) ;
return 0 ;
}
int F_316 ( struct V_6 * V_7 ,
struct V_432 * V_433 )
{
F_2 ( & V_7 -> V_201 ) ;
F_311 ( V_7 , V_433 -> V_435 ) ;
F_4 ( & V_7 -> V_201 ) ;
return 0 ;
}
int F_317 ( struct V_6 * V_7 ,
struct V_432 * V_433 )
{
F_2 ( & V_7 -> V_201 ) ;
V_433 -> V_569 = 0 ;
F_4 ( & V_7 -> V_201 ) ;
return 0 ;
}
int F_318 ( struct V_6 * V_7 ,
struct V_432 * V_433 ,
struct V_518 * V_519 ,
struct V_468 * V_469 )
{
struct V_572 * V_573 = V_519 -> V_573 ;
V_573 -> V_574 . V_478 = V_433 -> V_555 ;
if ( V_433 -> V_435 ) {
if ( ! V_433 -> V_575 ) {
V_433 -> V_575 = V_469 -> V_502 ;
V_433 -> V_576 = V_469 -> V_505 ;
V_433 -> V_577 = V_469 -> V_484 ;
} else {
V_573 -> V_574 . V_502 = V_433 -> V_575 ;
V_573 -> V_574 . V_505 = V_433 -> V_576 ;
V_469 -> V_484 = V_433 -> V_577 ;
}
if ( ! V_433 -> V_578 ) {
F_278 ( V_7 , V_433 -> V_435 ,
& V_433 -> V_578 ,
& V_433 -> V_579 ,
& V_433 -> V_580 ) ;
}
F_2 ( & V_7 -> V_201 ) ;
if ( V_433 -> V_434 ) {
if ( ( V_573 -> V_574 . V_502 & V_433 -> V_578 ) &&
( V_573 -> V_574 . V_505 & V_433 -> V_579 ) ) {
V_573 -> V_574 . V_502 &= V_433 -> V_578 ;
V_573 -> V_574 . V_505 &= V_433 -> V_579 ;
if ( V_433 -> V_580 < V_469 -> V_484 )
V_469 -> V_484 = V_433 -> V_580 ;
} else {
V_433 -> V_434 = 0 ;
}
}
F_4 ( & V_7 -> V_201 ) ;
}
return F_319 ( V_519 -> V_573 , 0 ,
V_581 , 2 ) ;
}
int F_320 ( struct V_6 * V_7 ,
struct V_432 * V_433 ,
unsigned int V_232 ,
unsigned int V_238 ,
struct V_518 * V_519 )
{
const T_2 * V_190 = V_433 -> V_582 ;
int V_300 = V_519 -> V_573 -> V_483 ;
struct V_207 * V_405 ;
int V_18 ;
F_2 ( & V_7 -> V_201 ) ;
V_405 = F_235 ( V_7 , V_433 -> V_435 ) ;
if ( V_433 -> V_435 && V_433 -> V_434 &&
V_433 -> V_569 != V_571 ) {
if ( V_300 == 2 &&
F_279 ( V_7 , V_433 -> V_435 ,
V_238 ) &&
! ( V_405 -> V_397 & V_399 ) ) {
V_433 -> V_569 = V_570 ;
F_310 ( V_7 , V_433 -> V_435 ,
V_232 , V_238 ) ;
} else {
V_433 -> V_569 = 0 ;
F_311 ( V_7 , V_433 -> V_435 ) ;
}
}
F_4 ( & V_7 -> V_201 ) ;
F_130 ( V_7 , V_190 [ V_583 ] , V_232 ,
0 , V_238 ) ;
if ( ! V_433 -> V_584 &&
V_433 -> V_585 && V_433 -> V_585 != V_190 [ V_583 ] )
F_130 ( V_7 , V_433 -> V_585 , V_232 ,
0 , V_238 ) ;
for ( V_18 = 0 ; V_18 < F_10 ( V_433 -> V_586 ) ; V_18 ++ )
if ( ! V_433 -> V_584 && V_433 -> V_586 [ V_18 ] )
F_130 ( V_7 ,
V_433 -> V_586 [ V_18 ] ,
V_232 , 0 , V_238 ) ;
for ( V_18 = 1 ; V_18 < V_433 -> V_587 ; V_18 ++ ) {
if ( V_300 >= ( V_18 + 1 ) * 2 )
F_130 ( V_7 , V_190 [ V_18 ] , V_232 ,
V_18 * 2 , V_238 ) ;
else if ( ! V_433 -> V_584 )
F_130 ( V_7 , V_190 [ V_18 ] , V_232 ,
0 , V_238 ) ;
}
for ( V_18 = 0 ; V_18 < F_10 ( V_433 -> V_588 ) ; V_18 ++ ) {
int V_269 = 0 ;
if ( ! V_433 -> V_588 [ V_18 ] )
break;
if ( V_300 >= ( V_18 + 1 ) * 2 )
V_269 = V_18 * 2 ;
else if ( ! V_433 -> V_584 )
break;
F_130 ( V_7 , V_433 -> V_588 [ V_18 ] ,
V_232 , V_269 , V_238 ) ;
}
return 0 ;
}
int F_321 ( struct V_6 * V_7 ,
struct V_432 * V_433 )
{
const T_2 * V_190 = V_433 -> V_582 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_433 -> V_587 ; V_18 ++ )
F_283 ( V_7 , V_190 [ V_18 ] ) ;
if ( V_433 -> V_585 )
F_283 ( V_7 , V_433 -> V_585 ) ;
for ( V_18 = 0 ; V_18 < F_10 ( V_433 -> V_586 ) ; V_18 ++ )
if ( V_433 -> V_586 [ V_18 ] )
F_283 ( V_7 ,
V_433 -> V_586 [ V_18 ] ) ;
for ( V_18 = 0 ; V_18 < F_10 ( V_433 -> V_588 ) ; V_18 ++ )
if ( V_433 -> V_588 [ V_18 ] )
F_283 ( V_7 ,
V_433 -> V_588 [ V_18 ] ) ;
F_2 ( & V_7 -> V_201 ) ;
if ( V_433 -> V_435 && V_433 -> V_569 == V_570 ) {
F_311 ( V_7 , V_433 -> V_435 ) ;
V_433 -> V_569 = 0 ;
}
F_4 ( & V_7 -> V_201 ) ;
return 0 ;
}
unsigned int F_322 ( struct V_6 * V_7 , T_2 V_168 )
{
unsigned int V_589 ;
unsigned int V_234 ;
V_234 = F_23 ( V_7 , V_168 , 0 ,
V_173 , 0 ) ;
V_589 = F_146 ( V_7 , V_168 ) ;
V_589 = ( V_589 & V_590 ) >> V_591 ;
if ( ( V_589 & V_592 ) && V_234 != V_593 )
return V_594 ;
else if ( V_589 & V_595 )
return V_596 ;
else if ( V_589 & V_597 )
return V_598 ;
else if ( V_589 & V_599 )
return V_600 ;
return V_601 ;
}
unsigned int F_323 ( struct V_6 * V_7 ,
T_2 V_168 , unsigned int V_29 )
{
static unsigned int V_602 [] [ 2 ] = {
{ V_598 , V_597 } ,
{ V_594 , V_592 } ,
{ V_596 , V_595 } ,
{ V_600 , V_599 } ,
} ;
unsigned int V_603 ;
if ( ! V_29 )
return 0 ;
V_603 = F_146 ( V_7 , V_168 ) ;
if ( ! V_603 )
return V_29 ;
if ( V_29 & V_604 ) {
if ( ! ( V_603 & V_605 ) )
V_29 &= ~ ( V_604 | V_606 ) ;
else if ( ( V_29 & V_606 ) && ! ( V_603 & V_607 ) )
V_29 &= ~ V_606 ;
}
if ( V_29 & V_608 ) {
if ( ! ( V_603 & V_609 ) )
V_29 &= ~ ( V_608 | V_610 ) ;
else {
unsigned int V_611 , V_612 ;
int V_18 ;
V_611 = ( V_603 & V_590 ) >> V_591 ;
V_612 = V_29 & V_610 ;
for ( V_18 = 0 ; V_18 < F_10 ( V_602 ) ; V_18 ++ ) {
if ( V_612 == V_602 [ V_18 ] [ 0 ] &&
! ( V_611 & V_602 [ V_18 ] [ 1 ] ) ) {
if ( V_18 == F_10 ( V_602 ) - 1 )
V_612 = V_601 ;
else
V_612 = V_602 [ V_18 + 1 ] [ 0 ] ;
}
}
V_29 &= ~ V_610 ;
V_29 |= V_612 ;
}
}
return V_29 ;
}
int F_324 ( struct V_6 * V_7 , T_2 V_168 ,
unsigned int V_29 , bool V_613 )
{
V_29 = F_323 ( V_7 , V_168 , V_29 ) ;
F_91 ( V_7 , V_168 , V_29 ) ;
if ( V_613 )
return F_246 ( V_7 , V_168 , 0 ,
V_181 , V_29 ) ;
else
return F_24 ( V_7 , V_168 , 0 ,
V_181 , V_29 ) ;
}
int F_325 ( struct V_559 * V_560 , const char * V_562 ,
int V_270 , int * V_614 )
{
int V_18 , V_615 = 0 ;
if ( V_560 -> V_561 >= V_616 ) {
F_21 ( V_31 L_100 ) ;
return - V_62 ;
}
for ( V_18 = 0 ; V_18 < V_560 -> V_561 ; V_18 ++ ) {
if ( ! strncmp ( V_562 , V_560 -> V_339 [ V_18 ] . V_562 , strlen ( V_562 ) ) )
V_615 ++ ;
}
if ( V_614 )
* V_614 = V_615 ;
if ( V_615 > 0 )
snprintf ( V_560 -> V_339 [ V_560 -> V_561 ] . V_562 ,
sizeof( V_560 -> V_339 [ V_560 -> V_561 ] . V_562 ) ,
L_101 , V_562 , V_615 ) ;
else
F_326 ( V_560 -> V_339 [ V_560 -> V_561 ] . V_562 , V_562 ,
sizeof( V_560 -> V_339 [ V_560 -> V_561 ] . V_562 ) ) ;
V_560 -> V_339 [ V_560 -> V_561 ] . V_270 = V_270 ;
V_560 -> V_561 ++ ;
return 0 ;
}
static void F_327 ( void * V_359 , T_9 V_617 )
{
F_260 ( V_359 , false ) ;
}
static void F_328 ( void * V_359 , T_9 V_617 )
{
F_264 ( V_359 ) ;
}
int F_329 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_330 ( V_618 ) ;
F_29 (codec, &bus->codec_list, list) {
F_104 ( & V_7 -> V_183 ) ;
if ( F_313 ( V_7 ) ) {
if ( V_10 -> V_194 > 1 )
F_331 ( F_327 , V_7 ,
& V_618 ) ;
else
F_260 ( V_7 , false ) ;
}
}
if ( V_10 -> V_194 > 1 )
F_332 ( & V_618 ) ;
return 0 ;
}
int F_333 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_330 ( V_618 ) ;
F_29 (codec, &bus->codec_list, list) {
if ( V_10 -> V_194 > 1 )
F_331 ( F_328 , V_7 , & V_618 ) ;
else
F_264 ( V_7 ) ;
}
if ( V_10 -> V_194 > 1 )
F_332 ( & V_618 ) ;
return 0 ;
}
void * F_84 ( struct V_174 * V_175 )
{
if ( F_43 ( ! V_175 -> V_619 ) )
return NULL ;
if ( V_175 -> V_176 >= V_175 -> V_620 ) {
int V_621 = V_175 -> V_620 + V_175 -> V_622 ;
int V_313 = ( V_621 + 1 ) * V_175 -> V_619 ;
void * V_623 ;
if ( F_43 ( V_621 >= 4096 ) )
return NULL ;
V_623 = F_334 ( V_175 -> V_4 , V_313 , V_54 | V_624 ) ;
if ( ! V_623 )
return NULL ;
V_175 -> V_4 = V_623 ;
V_175 -> V_620 = V_621 ;
}
return F_86 ( V_175 , V_175 -> V_176 ++ ) ;
}
void F_100 ( struct V_174 * V_175 )
{
F_37 ( V_175 -> V_4 ) ;
V_175 -> V_176 = 0 ;
V_175 -> V_620 = 0 ;
V_175 -> V_4 = NULL ;
}
void F_335 ( int V_344 , char * V_252 , int V_625 )
{
static unsigned int V_626 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_18 , V_627 ;
for ( V_18 = 0 , V_627 = 0 ; V_18 < F_10 ( V_626 ) ; V_18 ++ )
if ( V_344 & ( V_508 << V_18 ) )
V_627 += snprintf ( V_252 + V_627 , V_625 - V_627 , L_102 , V_626 [ V_18 ] ) ;
V_252 [ V_627 ] = '\0' ;
}
