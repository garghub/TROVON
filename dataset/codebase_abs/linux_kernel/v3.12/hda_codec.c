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
static unsigned int F_50 ( struct V_11 * V_12 , T_2 V_24 )
{
unsigned int V_63 = F_47 ( V_12 , V_24 ) ;
unsigned int V_27 ;
if ( ! V_12 -> V_86 || ! ( V_63 & V_87 ) ||
F_48 ( V_63 ) != V_84 )
return 0 ;
V_27 = F_27 ( V_12 , V_24 , V_88 ) ;
if ( V_27 == - 1 && V_12 -> V_7 -> V_41 )
V_27 = 0 ;
return V_27 & V_89 ;
}
int F_51 ( struct V_11 * V_12 , T_2 V_24 ,
T_3 * V_90 , int V_91 )
{
unsigned int V_27 ;
int V_17 , V_92 , V_93 ;
V_27 = F_50 ( V_12 , V_24 ) ;
if ( ! V_27 )
return 0 ;
V_92 = V_27 + 1 ;
V_92 = V_92 < V_91 ? V_92 : V_91 ;
V_93 = 0 ;
while ( V_93 < V_92 ) {
V_27 = F_23 ( V_12 , V_24 , 0 ,
V_94 , V_93 ) ;
if ( V_27 == - 1 && V_12 -> V_7 -> V_41 )
break;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
V_90 [ V_93 ] = ( T_3 ) V_27 ;
V_27 >>= 4 ;
V_93 ++ ;
if ( V_93 >= V_92 )
break;
}
}
return V_93 ;
}
int F_52 ( struct V_6 * V_7 , T_1 V_32 , T_1 V_95 )
{
struct V_96 * V_97 ;
unsigned int V_98 ;
if ( ! V_7 || ! V_7 -> V_99 )
return 0 ;
F_53 ( V_7 , V_32 , V_95 ) ;
V_97 = V_7 -> V_97 ;
if ( ! V_97 )
return 0 ;
V_98 = ( V_97 -> V_98 + 1 ) % V_100 ;
V_97 -> V_98 = V_98 ;
V_98 <<= 1 ;
V_97 -> V_101 [ V_98 ] = V_32 ;
V_97 -> V_101 [ V_98 + 1 ] = V_95 ;
F_54 ( V_7 -> V_99 , & V_97 -> V_102 ) ;
return 0 ;
}
static void F_55 ( struct V_103 * V_102 )
{
struct V_96 * V_97 =
F_56 ( V_102 , struct V_96 , V_102 ) ;
struct V_6 * V_7 = V_97 -> V_7 ;
struct V_11 * V_12 ;
unsigned int V_104 , V_105 , V_32 ;
while ( V_97 -> V_104 != V_97 -> V_98 ) {
V_104 = ( V_97 -> V_104 + 1 ) % V_100 ;
V_97 -> V_104 = V_104 ;
V_104 <<= 1 ;
V_32 = V_97 -> V_101 [ V_104 ] ;
V_105 = V_97 -> V_101 [ V_104 + 1 ] ;
if ( ! ( V_105 & ( 1 << 4 ) ) )
continue;
V_12 = V_7 -> V_106 [ V_105 & 0x0f ] ;
if ( V_12 && V_12 -> V_107 . V_108 )
V_12 -> V_107 . V_108 ( V_12 , V_32 ) ;
}
}
static int F_57 ( struct V_6 * V_7 )
{
struct V_96 * V_97 ;
if ( V_7 -> V_97 )
return 0 ;
V_97 = F_58 ( sizeof( * V_97 ) , V_53 ) ;
if ( ! V_97 ) {
F_45 ( V_30 L_39
L_44 ) ;
return - V_54 ;
}
F_59 ( & V_97 -> V_102 , F_55 ) ;
V_97 -> V_7 = V_7 ;
V_7 -> V_97 = V_97 ;
return 0 ;
}
static int F_60 ( struct V_6 * V_7 )
{
struct V_11 * V_12 , * V_78 ;
if ( ! V_7 )
return 0 ;
if ( V_7 -> V_99 )
F_61 ( V_7 -> V_99 ) ;
if ( V_7 -> V_97 )
F_37 ( V_7 -> V_97 ) ;
F_62 (codec, n, &bus->codec_list, list) {
F_63 ( V_12 ) ;
}
if ( V_7 -> V_9 . V_109 )
V_7 -> V_9 . V_109 ( V_7 ) ;
if ( V_7 -> V_99 )
F_64 ( V_7 -> V_99 ) ;
F_37 ( V_7 ) ;
return 0 ;
}
static int F_65 ( struct V_110 * V_111 )
{
struct V_6 * V_7 = V_111 -> V_112 ;
V_7 -> V_113 = 1 ;
return F_60 ( V_7 ) ;
}
static int F_66 ( struct V_110 * V_111 )
{
struct V_6 * V_7 = V_111 -> V_112 ;
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
F_67 ( V_12 ) ;
F_68 ( V_12 ) ;
}
return 0 ;
}
int F_69 ( struct V_114 * V_115 ,
const struct V_116 * V_117 ,
struct V_6 * * V_118 )
{
struct V_6 * V_7 ;
int V_33 ;
static struct V_119 V_120 = {
. V_121 = F_66 ,
. V_122 = F_65 ,
} ;
if ( F_43 ( ! V_117 ) )
return - V_61 ;
if ( F_43 ( ! V_117 -> V_9 . V_38 || ! V_117 -> V_9 . V_40 ) )
return - V_61 ;
if ( V_118 )
* V_118 = NULL ;
V_7 = F_58 ( sizeof( * V_7 ) , V_53 ) ;
if ( V_7 == NULL ) {
F_45 ( V_30 L_45 ) ;
return - V_54 ;
}
V_7 -> V_115 = V_115 ;
V_7 -> V_123 = V_117 -> V_123 ;
V_7 -> V_124 = V_117 -> V_124 ;
V_7 -> V_125 = V_117 -> V_125 ;
V_7 -> V_126 = V_117 -> V_126 ;
V_7 -> V_9 = V_117 -> V_9 ;
F_70 ( & V_7 -> V_35 ) ;
F_70 ( & V_7 -> V_127 ) ;
F_71 ( & V_7 -> V_128 ) ;
snprintf ( V_7 -> V_129 , sizeof( V_7 -> V_129 ) ,
L_46 , V_115 -> V_130 ) ;
V_7 -> V_99 = F_72 ( V_7 -> V_129 ) ;
if ( ! V_7 -> V_99 ) {
F_45 ( V_30 L_47 ,
V_7 -> V_129 ) ;
F_37 ( V_7 ) ;
return - V_54 ;
}
V_33 = F_73 ( V_115 , V_131 , V_7 , & V_120 ) ;
if ( V_33 < 0 ) {
F_60 ( V_7 ) ;
return V_33 ;
}
if ( V_118 )
* V_118 = V_7 ;
return 0 ;
}
static const struct V_132 *
F_74 ( struct V_11 * V_12 )
{
struct V_1 * V_133 ;
const struct V_132 * V_2 ;
unsigned int V_134 = 0 ;
if ( F_75 ( V_12 ) )
return NULL ;
V_34:
F_2 ( & V_3 ) ;
F_29 (tbl, &hda_preset_tables, list) {
if ( ! F_76 ( V_133 -> V_135 ) ) {
F_45 ( V_30 L_48 ) ;
continue;
}
for ( V_2 = V_133 -> V_2 ; V_2 -> V_136 ; V_2 ++ ) {
T_1 V_70 = V_2 -> V_70 ;
if ( V_2 -> V_137 && V_2 -> V_137 != V_12 -> V_137 )
continue;
if ( V_2 -> V_138 && V_2 -> V_138 != V_12 -> V_138 )
continue;
if ( ! V_70 )
V_70 = ~ 0 ;
if ( V_2 -> V_136 == ( V_12 -> V_139 & V_70 ) &&
( ! V_2 -> V_140 ||
V_2 -> V_140 == V_12 -> V_141 ) ) {
F_4 ( & V_3 ) ;
V_12 -> V_135 = V_133 -> V_135 ;
return V_2 ;
}
}
F_77 ( V_133 -> V_135 ) ;
}
F_4 ( & V_3 ) ;
if ( V_134 < V_142 ) {
char V_143 [ 32 ] ;
if ( ! V_134 )
snprintf ( V_143 , sizeof( V_143 ) , L_49 ,
V_12 -> V_139 ) ;
else
snprintf ( V_143 , sizeof( V_143 ) , L_50 ,
( V_12 -> V_139 >> 16 ) & 0xffff ) ;
F_78 ( V_143 ) ;
V_134 ++ ;
goto V_34;
}
return NULL ;
}
static int F_79 ( struct V_11 * V_12 )
{
const struct V_144 * V_145 ;
const char * V_146 = NULL ;
T_4 V_139 = V_12 -> V_139 >> 16 ;
char V_147 [ 16 ] ;
if ( V_12 -> V_148 )
goto V_149;
for ( V_145 = V_150 ; V_145 -> V_136 ; V_145 ++ ) {
if ( V_145 -> V_136 == V_139 ) {
V_146 = V_145 -> V_143 ;
break;
}
}
if ( ! V_146 ) {
sprintf ( V_147 , L_51 , V_139 ) ;
V_146 = V_147 ;
}
V_12 -> V_148 = F_80 ( V_146 , V_53 ) ;
if ( ! V_12 -> V_148 )
return - V_54 ;
V_149:
if ( V_12 -> V_151 )
return 0 ;
if ( V_12 -> V_2 && V_12 -> V_2 -> V_143 )
V_12 -> V_151 = F_80 ( V_12 -> V_2 -> V_143 , V_53 ) ;
else {
sprintf ( V_147 , L_52 , V_12 -> V_139 & 0xffff ) ;
V_12 -> V_151 = F_80 ( V_147 , V_53 ) ;
}
if ( ! V_12 -> V_151 )
return - V_54 ;
return 0 ;
}
static void F_81 ( struct V_11 * V_12 )
{
int V_17 , V_152 , V_153 ;
T_2 V_24 ;
V_152 = F_26 ( V_12 , V_154 , & V_24 ) ;
for ( V_17 = 0 ; V_17 < V_152 ; V_17 ++ , V_24 ++ ) {
V_153 = F_27 ( V_12 , V_24 ,
V_155 ) ;
switch ( V_153 & 0xff ) {
case V_156 :
V_12 -> V_137 = V_24 ;
V_12 -> V_157 = V_153 & 0xff ;
V_12 -> V_158 = ( V_153 >> 8 ) & 1 ;
break;
case V_159 :
V_12 -> V_138 = V_24 ;
V_12 -> V_160 = V_153 & 0xff ;
V_12 -> V_161 = ( V_153 >> 8 ) & 1 ;
break;
default:
break;
}
}
}
static int F_82 ( struct V_11 * V_12 , T_2 V_162 )
{
int V_17 ;
T_2 V_24 ;
V_12 -> V_163 = F_26 ( V_12 , V_162 ,
& V_12 -> V_164 ) ;
V_12 -> V_63 = F_31 ( V_12 -> V_163 * 4 , V_53 ) ;
if ( ! V_12 -> V_63 )
return - V_54 ;
V_24 = V_12 -> V_164 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_163 ; V_17 ++ , V_24 ++ )
V_12 -> V_63 [ V_17 ] = F_27 ( V_12 , V_24 ,
V_165 ) ;
return 0 ;
}
static int F_83 ( struct V_11 * V_12 )
{
int V_17 ;
T_2 V_24 = V_12 -> V_164 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_163 ; V_17 ++ , V_24 ++ ) {
struct V_166 * V_167 ;
unsigned int V_63 = F_47 ( V_12 , V_24 ) ;
unsigned int V_168 = F_48 ( V_63 ) ;
if ( V_168 != V_84 )
continue;
V_167 = F_84 ( & V_12 -> V_169 ) ;
if ( ! V_167 )
return - V_54 ;
V_167 -> V_24 = V_24 ;
V_167 -> V_13 = F_23 ( V_12 , V_24 , 0 ,
V_170 , 0 ) ;
V_167 -> V_171 = F_23 ( V_12 , V_24 , 0 ,
V_172 ,
0 ) ;
}
return 0 ;
}
static struct V_166 * F_85 ( struct V_11 * V_12 ,
struct V_173 * V_174 ,
T_2 V_24 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_174 -> V_175 ; V_17 ++ ) {
struct V_166 * V_167 = F_86 ( V_174 , V_17 ) ;
if ( V_167 -> V_24 == V_24 )
return V_167 ;
}
return NULL ;
}
int F_87 ( struct V_11 * V_12 , struct V_173 * V_4 ,
T_2 V_24 , unsigned int V_13 )
{
struct V_166 * V_167 ;
V_167 = F_85 ( V_12 , V_4 , V_24 ) ;
if ( ! V_167 ) {
V_167 = F_84 ( V_4 ) ;
if ( ! V_167 )
return - V_54 ;
V_167 -> V_24 = V_24 ;
}
V_167 -> V_13 = V_13 ;
return 0 ;
}
int F_88 ( struct V_11 * V_12 ,
T_2 V_24 , unsigned int V_13 )
{
return F_87 ( V_12 , & V_12 -> V_176 , V_24 , V_13 ) ;
}
unsigned int F_89 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_166 * V_167 ;
#ifdef F_90
{
unsigned int V_13 = 0 ;
F_2 ( & V_12 -> V_177 ) ;
V_167 = F_85 ( V_12 , & V_12 -> V_178 , V_24 ) ;
if ( V_167 )
V_13 = V_167 -> V_13 ;
F_4 ( & V_12 -> V_177 ) ;
if ( V_13 )
return V_13 ;
}
#endif
V_167 = F_85 ( V_12 , & V_12 -> V_176 , V_24 ) ;
if ( V_167 )
return V_167 -> V_13 ;
V_167 = F_85 ( V_12 , & V_12 -> V_169 , V_24 ) ;
if ( V_167 )
return V_167 -> V_13 ;
return 0 ;
}
int F_91 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_28 )
{
struct V_166 * V_167 ;
V_167 = F_85 ( V_12 , & V_12 -> V_169 , V_24 ) ;
if ( ! V_167 )
return - V_61 ;
V_167 -> V_179 = V_28 ;
return 0 ;
}
int F_92 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_166 * V_167 ;
V_167 = F_85 ( V_12 , & V_12 -> V_169 , V_24 ) ;
if ( ! V_167 )
return 0 ;
return V_167 -> V_179 ;
}
void F_93 ( struct V_11 * V_12 )
{
int V_17 ;
if ( V_12 -> V_7 -> V_113 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_169 . V_175 ; V_17 ++ ) {
struct V_166 * V_167 = F_86 ( & V_12 -> V_169 , V_17 ) ;
F_23 ( V_12 , V_167 -> V_24 , 0 ,
V_180 , 0 ) ;
}
V_12 -> V_181 = 1 ;
}
static void F_94 ( struct V_11 * V_12 )
{
int V_17 ;
if ( ! V_12 -> V_181 )
return;
if ( V_12 -> V_7 -> V_113 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_169 . V_175 ; V_17 ++ ) {
struct V_166 * V_167 = F_86 ( & V_12 -> V_169 , V_17 ) ;
F_24 ( V_12 , V_167 -> V_24 , 0 ,
V_180 ,
V_167 -> V_171 ) ;
}
V_12 -> V_181 = 0 ;
}
static void F_95 ( struct V_103 * V_102 )
{
struct V_11 * V_12 =
F_56 ( V_102 , struct V_11 , V_182 . V_102 ) ;
F_96 ( V_12 ) ;
F_97 ( V_12 ) ;
if ( ! V_12 -> V_183 )
return;
F_98 ( V_12 -> V_7 -> V_99 , & V_12 -> V_182 ,
V_12 -> V_183 ) ;
}
static void F_99 ( struct V_11 * V_12 )
{
F_100 ( & V_12 -> V_176 ) ;
#ifdef F_90
F_100 ( & V_12 -> V_178 ) ;
#endif
F_100 ( & V_12 -> V_169 ) ;
}
static struct V_184 *
F_101 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_184 * V_51 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_185 . V_175 ; V_17 ++ ) {
V_51 = F_86 ( & V_12 -> V_185 , V_17 ) ;
if ( V_51 -> V_24 == V_24 )
return V_51 ;
}
V_51 = F_84 ( & V_12 -> V_185 ) ;
if ( V_51 )
V_51 -> V_24 = V_24 ;
return V_51 ;
}
static void F_63 ( struct V_11 * V_12 )
{
if ( ! V_12 )
return;
F_102 ( & V_12 -> V_182 ) ;
F_103 ( V_12 ) ;
F_99 ( V_12 ) ;
#ifdef F_104
F_105 ( & V_12 -> V_186 ) ;
F_61 ( V_12 -> V_7 -> V_99 ) ;
#endif
F_6 ( & V_12 -> V_4 ) ;
F_100 ( & V_12 -> V_187 ) ;
F_100 ( & V_12 -> V_188 ) ;
F_100 ( & V_12 -> V_185 ) ;
F_100 ( & V_12 -> V_189 ) ;
F_33 ( V_12 ) ;
V_12 -> V_7 -> V_106 [ V_12 -> V_29 ] = NULL ;
if ( V_12 -> V_107 . free )
V_12 -> V_107 . free ( V_12 ) ;
#ifdef F_104
if ( ! V_12 -> V_190 )
F_7 ( V_12 -> V_7 , false ) ;
#endif
F_77 ( V_12 -> V_135 ) ;
F_106 ( & V_12 -> V_191 ) ;
F_106 ( & V_12 -> V_192 ) ;
F_37 ( V_12 -> V_148 ) ;
F_37 ( V_12 -> V_151 ) ;
F_37 ( V_12 -> V_125 ) ;
F_37 ( V_12 -> V_63 ) ;
F_37 ( V_12 ) ;
}
int F_107 ( struct V_6 * V_7 ,
unsigned int V_193 ,
struct V_11 * * V_194 )
{
struct V_11 * V_12 ;
char V_195 [ 31 ] ;
T_2 V_196 ;
int V_33 ;
if ( F_43 ( ! V_7 ) )
return - V_61 ;
if ( F_43 ( V_193 > V_197 ) )
return - V_61 ;
if ( V_7 -> V_106 [ V_193 ] ) {
F_45 ( V_30 L_39
L_53 , V_193 ) ;
return - V_198 ;
}
V_12 = F_58 ( sizeof( * V_12 ) , V_53 ) ;
if ( V_12 == NULL ) {
F_45 ( V_30 L_54 ) ;
return - V_54 ;
}
V_12 -> V_7 = V_7 ;
V_12 -> V_29 = V_193 ;
F_70 ( & V_12 -> V_199 ) ;
F_70 ( & V_12 -> V_200 ) ;
F_70 ( & V_12 -> V_201 ) ;
F_108 ( & V_12 -> V_191 , sizeof( struct V_202 ) ) ;
F_108 ( & V_12 -> V_192 , sizeof( struct V_203 ) ) ;
F_109 ( & V_12 -> V_187 , sizeof( struct V_204 ) , 32 ) ;
F_109 ( & V_12 -> V_188 , sizeof( struct V_204 ) , 32 ) ;
F_109 ( & V_12 -> V_169 , sizeof( struct V_166 ) , 16 ) ;
F_109 ( & V_12 -> V_176 , sizeof( struct V_166 ) , 16 ) ;
F_109 ( & V_12 -> V_185 , sizeof( struct V_184 ) , 8 ) ;
F_109 ( & V_12 -> V_189 , sizeof( struct V_205 ) , 16 ) ;
F_109 ( & V_12 -> V_206 , sizeof( struct V_207 ) , 16 ) ;
F_109 ( & V_12 -> V_208 , sizeof( struct V_45 * ) , 8 ) ;
F_71 ( & V_12 -> V_56 ) ;
F_110 ( & V_12 -> V_182 , F_95 ) ;
#ifdef F_104
F_111 ( & V_12 -> V_209 ) ;
F_110 ( & V_12 -> V_186 , V_210 ) ;
F_8 ( V_12 ) ;
F_7 ( V_7 , true ) ;
#endif
if ( V_12 -> V_7 -> V_125 ) {
V_12 -> V_125 = F_80 ( V_12 -> V_7 -> V_125 , V_53 ) ;
if ( ! V_12 -> V_125 ) {
F_63 ( V_12 ) ;
return - V_211 ;
}
}
F_3 ( & V_12 -> V_4 , & V_7 -> V_128 ) ;
V_7 -> V_106 [ V_193 ] = V_12 ;
V_12 -> V_139 = F_27 ( V_12 , V_154 ,
V_212 ) ;
if ( V_12 -> V_139 == - 1 )
V_12 -> V_139 = F_27 ( V_12 , V_154 ,
V_212 ) ;
V_12 -> V_213 = F_27 ( V_12 , V_154 ,
V_214 ) ;
V_12 -> V_141 = F_27 ( V_12 , V_154 ,
V_215 ) ;
F_81 ( V_12 ) ;
if ( ! V_12 -> V_137 && ! V_12 -> V_138 ) {
F_112 ( L_55 ) ;
V_33 = - V_211 ;
goto error;
}
V_196 = V_12 -> V_137 ? V_12 -> V_137 : V_12 -> V_138 ;
V_33 = F_82 ( V_12 , V_196 ) ;
if ( V_33 < 0 ) {
F_45 ( V_30 L_56 ) ;
goto error;
}
V_33 = F_83 ( V_12 ) ;
if ( V_33 < 0 )
goto error;
if ( ! V_12 -> V_213 ) {
V_12 -> V_213 =
F_23 ( V_12 , V_196 , 0 ,
V_216 , 0 ) ;
}
#ifdef F_104
V_12 -> V_217 = F_113 ( V_12 , V_196 ,
V_218 ) ;
if ( ! V_12 -> V_217 )
V_7 -> V_219 = 1 ;
#endif
V_12 -> V_220 = F_113 ( V_12 , V_196 ,
V_221 ) ;
F_114 ( V_12 , V_222 ) ;
F_115 ( V_12 ) ;
F_116 ( V_12 ) ;
sprintf ( V_195 , L_57 , V_12 -> V_139 ,
V_12 -> V_213 , V_12 -> V_141 ) ;
F_117 ( V_12 -> V_7 -> V_115 , V_195 ) ;
if ( V_194 )
* V_194 = V_12 ;
return 0 ;
error:
F_63 ( V_12 ) ;
return V_33 ;
}
int F_118 ( struct V_11 * V_12 )
{
T_2 V_196 ;
int V_33 ;
F_37 ( V_12 -> V_63 ) ;
V_196 = V_12 -> V_137 ? V_12 -> V_137 : V_12 -> V_138 ;
V_33 = F_82 ( V_12 , V_196 ) ;
if ( V_33 < 0 ) {
F_45 ( V_30 L_56 ) ;
return V_33 ;
}
F_100 ( & V_12 -> V_169 ) ;
V_33 = F_83 ( V_12 ) ;
return V_33 ;
}
int F_119 ( struct V_11 * V_12 )
{
int V_33 ;
V_12 -> V_2 = F_74 ( V_12 ) ;
if ( ! V_12 -> V_148 || ! V_12 -> V_151 ) {
V_33 = F_79 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( F_75 ( V_12 ) ) {
V_33 = F_120 ( V_12 ) ;
goto V_223;
}
if ( V_12 -> V_2 && V_12 -> V_2 -> V_224 ) {
V_33 = V_12 -> V_2 -> V_224 ( V_12 ) ;
goto V_223;
}
V_33 = F_120 ( V_12 ) ;
if ( V_33 < 0 )
F_14 ( V_30 L_58 ) ;
V_223:
if ( ! V_33 && V_12 -> V_107 . V_108 )
V_33 = F_57 ( V_12 -> V_7 ) ;
if ( ! V_33 && ( V_12 -> V_137 || ! * V_12 -> V_7 -> V_115 -> V_225 ) )
snprintf ( V_12 -> V_7 -> V_115 -> V_225 ,
sizeof( V_12 -> V_7 -> V_115 -> V_225 ) ,
L_59 , V_12 -> V_148 , V_12 -> V_151 ) ;
return V_33 ;
}
static void F_121 ( struct V_11 * V_12 ,
struct V_184 * V_51 , T_2 V_24 ,
T_1 V_226 , int V_227 )
{
unsigned int V_228 , V_229 ;
if ( V_51 -> V_226 != V_226 || V_51 -> V_227 != V_227 ) {
V_228 = F_23 ( V_12 , V_24 , 0 , V_230 , 0 ) ;
V_229 = ( V_226 << 4 ) | V_227 ;
if ( V_228 != V_229 )
F_24 ( V_12 , V_24 , 0 ,
V_231 ,
V_229 ) ;
V_51 -> V_226 = V_226 ;
V_51 -> V_227 = V_227 ;
}
}
static void F_122 ( struct V_11 * V_12 , struct V_184 * V_51 ,
T_2 V_24 , int V_232 )
{
unsigned int V_228 ;
if ( V_51 -> V_233 != V_232 ) {
V_228 = F_23 ( V_12 , V_24 , 0 ,
V_234 , 0 ) ;
if ( V_228 != V_232 ) {
F_123 ( 1 ) ;
F_24 ( V_12 , V_24 , 0 ,
V_235 ,
V_232 ) ;
}
V_51 -> V_233 = V_232 ;
}
}
void F_124 ( struct V_11 * V_12 , T_2 V_24 ,
T_1 V_226 ,
int V_227 , int V_232 )
{
struct V_11 * V_145 ;
struct V_184 * V_51 ;
int type ;
int V_17 ;
if ( ! V_24 )
return;
F_112 ( L_60
L_61 ,
V_24 , V_226 , V_227 , V_232 ) ;
V_51 = F_101 ( V_12 , V_24 ) ;
if ( ! V_51 )
return;
if ( V_12 -> V_236 )
F_122 ( V_12 , V_51 , V_24 , V_232 ) ;
F_121 ( V_12 , V_51 , V_24 , V_226 , V_227 ) ;
if ( ! V_12 -> V_236 )
F_122 ( V_12 , V_51 , V_24 , V_232 ) ;
V_51 -> V_237 = 1 ;
V_51 -> V_238 = 0 ;
type = F_48 ( F_47 ( V_12 , V_24 ) ) ;
F_29 (c, &codec->bus->codec_list, list) {
for ( V_17 = 0 ; V_17 < V_145 -> V_185 . V_175 ; V_17 ++ ) {
V_51 = F_86 ( & V_145 -> V_185 , V_17 ) ;
if ( ! V_51 -> V_237 && V_51 -> V_226 == V_226 &&
F_48 ( F_47 ( V_145 , V_51 -> V_24 ) ) == type )
V_51 -> V_238 = 1 ;
}
}
}
void F_125 ( struct V_11 * V_12 , T_2 V_24 ,
int V_239 )
{
struct V_184 * V_51 ;
if ( ! V_24 )
return;
if ( V_12 -> V_240 )
V_239 = 1 ;
F_112 ( L_62 , V_24 ) ;
V_51 = F_101 ( V_12 , V_24 ) ;
if ( V_51 ) {
if ( V_239 )
F_126 ( V_12 , V_51 ) ;
else
V_51 -> V_237 = 0 ;
}
}
static void F_126 ( struct V_11 * V_12 ,
struct V_184 * V_241 )
{
T_2 V_24 = V_241 -> V_24 ;
if ( V_241 -> V_226 || V_241 -> V_227 )
F_24 ( V_12 , V_24 , 0 , V_231 , 0 ) ;
if ( V_241 -> V_233 )
F_24 ( V_12 , V_24 , 0 , V_235 , 0
) ;
memset ( V_241 , 0 , sizeof( * V_241 ) ) ;
V_241 -> V_24 = V_24 ;
}
static void F_127 ( struct V_11 * V_12 )
{
struct V_11 * V_145 ;
int V_17 ;
F_29 (c, &codec->bus->codec_list, list) {
for ( V_17 = 0 ; V_17 < V_145 -> V_185 . V_175 ; V_17 ++ ) {
struct V_184 * V_51 ;
V_51 = F_86 ( & V_145 -> V_185 , V_17 ) ;
if ( V_51 -> V_238 )
F_126 ( V_145 , V_51 ) ;
}
}
}
static void F_128 ( struct V_11 * V_12 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_185 . V_175 ; V_17 ++ ) {
struct V_184 * V_51 = F_86 ( & V_12 -> V_185 , V_17 ) ;
if ( V_51 -> V_226 )
F_126 ( V_12 , V_51 ) ;
}
}
static void F_108 ( struct V_242 * V_243 ,
unsigned int V_244 )
{
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
memset ( V_243 -> V_245 , 0xff , sizeof( V_243 -> V_245 ) ) ;
F_109 ( & V_243 -> V_246 , V_244 , 64 ) ;
}
static void F_106 ( struct V_242 * V_243 )
{
F_100 ( & V_243 -> V_246 ) ;
}
static struct V_203 * F_129 ( struct V_242 * V_243 , T_1 V_247 )
{
T_4 V_248 = V_247 % ( T_4 ) F_10 ( V_243 -> V_245 ) ;
T_4 V_249 = V_243 -> V_245 [ V_248 ] ;
struct V_203 * V_250 ;
while ( V_249 != 0xffff ) {
V_250 = F_86 ( & V_243 -> V_246 , V_249 ) ;
if ( V_250 -> V_247 == V_247 )
return V_250 ;
V_249 = V_250 -> V_251 ;
}
return NULL ;
}
static struct V_203 * F_130 ( struct V_242 * V_243 ,
T_1 V_247 )
{
struct V_203 * V_250 = F_129 ( V_243 , V_247 ) ;
if ( ! V_250 ) {
T_4 V_248 , V_249 ;
V_250 = F_84 ( & V_243 -> V_246 ) ;
if ( ! V_250 )
return NULL ;
V_249 = F_131 ( & V_243 -> V_246 , V_250 ) ;
V_250 -> V_247 = V_247 ;
V_250 -> V_28 = 0 ;
V_250 -> V_238 = 0 ;
V_248 = V_247 % ( T_4 ) F_10 ( V_243 -> V_245 ) ;
V_250 -> V_251 = V_243 -> V_245 [ V_248 ] ;
V_243 -> V_245 [ V_248 ] = V_249 ;
}
return V_250 ;
}
static inline struct V_202 *
F_132 ( struct V_11 * V_12 , T_1 V_247 )
{
return (struct V_202 * ) F_130 ( & V_12 -> V_191 , V_247 ) ;
}
static int F_133 ( struct V_11 * V_12 , T_1 V_247 , unsigned int V_28 )
{
struct V_202 * V_250 ;
F_2 ( & V_12 -> V_201 ) ;
V_250 = F_132 ( V_12 , V_247 ) ;
if ( ! V_250 ) {
F_4 ( & V_12 -> V_201 ) ;
return - V_61 ;
}
V_250 -> V_252 = V_28 ;
V_250 -> V_253 . V_28 |= V_254 ;
F_4 ( & V_12 -> V_201 ) ;
return 0 ;
}
static unsigned int F_134 ( struct V_11 * V_12 , T_2 V_24 ,
int V_255 )
{
if ( ! ( F_47 ( V_12 , V_24 ) & V_256 ) )
V_24 = V_12 -> V_137 ;
return F_27 ( V_12 , V_24 ,
V_255 == V_257 ?
V_258 : V_259 ) ;
}
T_1 F_135 ( struct V_11 * V_12 , T_2 V_24 , int V_255 )
{
return F_136 ( V_12 , V_24 , V_255 ,
F_137 ( V_24 , V_255 , 0 ) ,
F_134 ) ;
}
int F_138 ( struct V_11 * V_12 , T_2 V_24 , int V_260 ,
unsigned int V_261 )
{
return F_133 ( V_12 , F_137 ( V_24 , V_260 , 0 ) , V_261 ) ;
}
static unsigned int F_139 ( struct V_11 * V_12 , T_2 V_24 ,
int V_260 )
{
return F_27 ( V_12 , V_24 , V_262 ) ;
}
T_1 F_140 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_136 ( V_12 , V_24 , 0 , F_141 ( V_24 ) ,
F_139 ) ;
}
int F_142 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_261 )
{
return F_133 ( V_12 , F_141 ( V_24 ) , V_261 ) ;
}
static struct V_202 *
F_143 ( struct V_11 * V_12 , T_2 V_24 , int V_263 ,
int V_255 , int V_264 , bool V_265 )
{
struct V_202 * V_250 ;
unsigned int V_27 , V_28 = 0 ;
bool V_266 = false ;
V_267:
V_250 = F_132 ( V_12 , F_137 ( V_24 , V_255 , V_264 ) ) ;
if ( ! V_250 )
return NULL ;
if ( ! ( V_250 -> V_253 . V_28 & F_144 ( V_263 ) ) ) {
if ( ! V_266 ) {
F_4 ( & V_12 -> V_201 ) ;
V_27 = V_263 ? V_268 : V_269 ;
V_27 |= V_255 == V_257 ?
V_270 : V_271 ;
V_27 |= V_264 ;
V_28 = F_23 ( V_12 , V_24 , 0 ,
V_272 , V_27 ) ;
V_28 &= 0xff ;
V_266 = true ;
F_2 ( & V_12 -> V_201 ) ;
goto V_267;
}
V_250 -> V_273 [ V_263 ] = V_28 ;
V_250 -> V_253 . V_28 |= F_144 ( V_263 ) ;
} else if ( V_265 )
return NULL ;
return V_250 ;
}
static void F_145 ( struct V_11 * V_12 , unsigned int V_252 ,
T_2 V_24 , int V_263 , int V_255 , int V_264 ,
int V_28 )
{
T_1 V_27 ;
V_27 = V_263 ? V_274 : V_275 ;
V_27 |= V_255 == V_257 ? V_276 : V_277 ;
V_27 |= V_264 << V_278 ;
if ( ( V_28 & V_279 ) && ! ( V_252 & V_280 ) &&
( V_252 & V_281 ) )
;
else
V_27 |= V_28 ;
F_24 ( V_12 , V_24 , 0 , V_282 , V_27 ) ;
}
int F_146 ( struct V_11 * V_12 , T_2 V_24 , int V_263 ,
int V_255 , int V_264 )
{
struct V_202 * V_250 ;
unsigned int V_28 = 0 ;
F_2 ( & V_12 -> V_201 ) ;
V_250 = F_143 ( V_12 , V_24 , V_263 , V_255 , V_264 , false ) ;
if ( V_250 )
V_28 = V_250 -> V_273 [ V_263 ] ;
F_4 ( & V_12 -> V_201 ) ;
return V_28 ;
}
static int F_147 ( struct V_11 * V_12 , T_2 V_24 , int V_263 ,
int V_255 , int V_248 , int V_70 , int V_28 ,
bool V_265 )
{
struct V_202 * V_250 ;
unsigned int V_261 ;
unsigned int V_283 ;
if ( F_43 ( V_70 & ~ 0xff ) )
V_70 &= 0xff ;
V_28 &= V_70 ;
F_2 ( & V_12 -> V_201 ) ;
V_250 = F_143 ( V_12 , V_24 , V_263 , V_255 , V_248 , V_265 ) ;
if ( ! V_250 ) {
F_4 ( & V_12 -> V_201 ) ;
return 0 ;
}
V_28 |= V_250 -> V_273 [ V_263 ] & ~ V_70 ;
if ( V_250 -> V_273 [ V_263 ] == V_28 ) {
F_4 ( & V_12 -> V_201 ) ;
return 0 ;
}
V_250 -> V_273 [ V_263 ] = V_28 ;
V_283 = V_250 -> V_253 . V_238 = V_12 -> V_284 ;
V_261 = V_250 -> V_252 ;
F_4 ( & V_12 -> V_201 ) ;
if ( ! V_283 )
F_145 ( V_12 , V_261 , V_24 , V_263 , V_255 , V_248 , V_28 ) ;
return 1 ;
}
int F_148 ( struct V_11 * V_12 , T_2 V_24 , int V_263 ,
int V_255 , int V_248 , int V_70 , int V_28 )
{
return F_147 ( V_12 , V_24 , V_263 , V_255 , V_248 , V_70 , V_28 , false ) ;
}
int F_149 ( struct V_11 * V_12 , T_2 V_24 ,
int V_255 , int V_248 , int V_70 , int V_28 )
{
int V_263 , V_285 = 0 ;
if ( F_43 ( V_70 & ~ 0xff ) )
V_70 &= 0xff ;
for ( V_263 = 0 ; V_263 < 2 ; V_263 ++ )
V_285 |= F_148 ( V_12 , V_24 , V_263 , V_255 ,
V_248 , V_70 , V_28 ) ;
return V_285 ;
}
int F_150 ( struct V_11 * V_12 , T_2 V_24 , int V_263 ,
int V_260 , int V_248 , int V_70 , int V_28 )
{
return F_147 ( V_12 , V_24 , V_263 , V_260 , V_248 , V_70 , V_28 , true ) ;
}
int F_151 ( struct V_11 * V_12 , T_2 V_24 ,
int V_260 , int V_248 , int V_70 , int V_28 )
{
int V_263 , V_285 = 0 ;
if ( F_43 ( V_70 & ~ 0xff ) )
V_70 &= 0xff ;
for ( V_263 = 0 ; V_263 < 2 ; V_263 ++ )
V_285 |= F_150 ( V_12 , V_24 , V_263 , V_260 ,
V_248 , V_70 , V_28 ) ;
return V_285 ;
}
void F_152 ( struct V_11 * V_12 )
{
int V_17 ;
F_2 ( & V_12 -> V_201 ) ;
V_12 -> V_284 = 0 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_191 . V_246 . V_175 ; V_17 ++ ) {
struct V_202 * V_286 ;
T_1 V_247 ;
T_2 V_24 ;
unsigned int V_248 , V_260 , V_263 ;
struct V_202 V_250 ;
V_286 = F_86 ( & V_12 -> V_191 . V_246 , V_17 ) ;
if ( ! V_286 -> V_253 . V_238 )
continue;
V_286 -> V_253 . V_238 = 0 ;
V_250 = * V_286 ;
V_247 = V_250 . V_253 . V_247 ;
if ( ! V_247 )
continue;
V_24 = V_247 & 0xff ;
V_248 = ( V_247 >> 16 ) & 0xff ;
V_260 = ( V_247 >> 24 ) & 0xff ;
for ( V_263 = 0 ; V_263 < 2 ; V_263 ++ ) {
if ( ! ( V_250 . V_253 . V_28 & F_144 ( V_263 ) ) )
continue;
F_4 ( & V_12 -> V_201 ) ;
F_145 ( V_12 , V_250 . V_252 , V_24 , V_263 , V_260 , V_248 ,
V_250 . V_273 [ V_263 ] ) ;
F_2 ( & V_12 -> V_201 ) ;
}
}
F_4 ( & V_12 -> V_201 ) ;
}
static T_1 F_153 ( struct V_11 * V_12 , T_2 V_24 , int V_260 ,
unsigned int V_287 )
{
T_1 V_261 = F_135 ( V_12 , V_24 , V_260 ) ;
V_261 = ( V_261 & V_288 ) >> V_289 ;
if ( V_287 < V_261 )
V_261 -= V_287 ;
return V_261 ;
}
int F_154 ( struct V_290 * V_291 ,
struct V_292 * V_293 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
T_4 V_24 = F_156 ( V_291 ) ;
T_3 V_294 = F_157 ( V_291 ) ;
int V_260 = F_158 ( V_291 ) ;
unsigned int V_287 = F_159 ( V_291 ) ;
V_293 -> type = V_295 ;
V_293 -> V_296 = V_294 == 3 ? 2 : 1 ;
V_293 -> V_297 . integer . V_298 = 0 ;
V_293 -> V_297 . integer . V_299 = F_153 ( V_12 , V_24 , V_260 , V_287 ) ;
if ( ! V_293 -> V_297 . integer . V_299 ) {
F_14 ( V_79 L_39
L_63 , V_24 ,
V_291 -> V_136 . V_143 ) ;
return - V_61 ;
}
return 0 ;
}
static inline unsigned int
F_160 ( struct V_11 * V_12 , T_2 V_24 ,
int V_263 , int V_260 , int V_248 , unsigned int V_287 )
{
unsigned int V_28 ;
V_28 = F_146 ( V_12 , V_24 , V_263 , V_260 , V_248 ) ;
V_28 &= V_300 ;
if ( V_28 >= V_287 )
V_28 -= V_287 ;
else
V_28 = 0 ;
return V_28 ;
}
static inline int
F_161 ( struct V_11 * V_12 , T_2 V_24 ,
int V_263 , int V_260 , int V_248 , unsigned int V_287 ,
unsigned int V_28 )
{
unsigned int V_301 ;
if ( V_28 > 0 )
V_28 += V_287 ;
V_301 = F_153 ( V_12 , V_24 , V_260 , 0 ) ;
if ( V_28 > V_301 )
V_28 = V_301 ;
return F_148 ( V_12 , V_24 , V_263 , V_260 , V_248 ,
V_300 , V_28 ) ;
}
int F_162 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
T_2 V_24 = F_156 ( V_291 ) ;
int V_294 = F_157 ( V_291 ) ;
int V_260 = F_158 ( V_291 ) ;
int V_248 = F_163 ( V_291 ) ;
unsigned int V_287 = F_159 ( V_291 ) ;
long * V_304 = V_303 -> V_297 . integer . V_297 ;
if ( V_294 & 1 )
* V_304 ++ = F_160 ( V_12 , V_24 , 0 , V_260 , V_248 , V_287 ) ;
if ( V_294 & 2 )
* V_304 = F_160 ( V_12 , V_24 , 1 , V_260 , V_248 , V_287 ) ;
return 0 ;
}
int F_164 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
T_2 V_24 = F_156 ( V_291 ) ;
int V_294 = F_157 ( V_291 ) ;
int V_260 = F_158 ( V_291 ) ;
int V_248 = F_163 ( V_291 ) ;
unsigned int V_287 = F_159 ( V_291 ) ;
long * V_304 = V_303 -> V_297 . integer . V_297 ;
int V_305 = 0 ;
F_16 ( V_12 ) ;
if ( V_294 & 1 ) {
V_305 = F_161 ( V_12 , V_24 , 0 , V_260 , V_248 , V_287 , * V_304 ) ;
V_304 ++ ;
}
if ( V_294 & 2 )
V_305 |= F_161 ( V_12 , V_24 , 1 , V_260 , V_248 , V_287 , * V_304 ) ;
F_19 ( V_12 ) ;
return V_305 ;
}
int F_165 ( struct V_290 * V_291 , int V_306 ,
unsigned int V_307 , unsigned int T_5 * V_308 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
T_2 V_24 = F_156 ( V_291 ) ;
int V_260 = F_158 ( V_291 ) ;
unsigned int V_287 = F_159 ( V_291 ) ;
bool V_309 = F_166 ( V_291 ) ;
T_1 V_261 , V_310 , V_311 ;
if ( V_307 < 4 * sizeof( unsigned int ) )
return - V_54 ;
V_261 = F_135 ( V_12 , V_24 , V_260 ) ;
V_311 = ( V_261 & V_312 ) >> V_313 ;
V_311 = ( V_311 + 1 ) * 25 ;
V_310 = - ( ( V_261 & V_314 ) >> V_315 ) ;
V_310 += V_287 ;
V_310 = ( ( int ) V_310 ) * ( ( int ) V_311 ) ;
if ( V_309 || ( V_261 & V_281 ) )
V_311 |= V_316 ;
if ( F_167 ( V_317 , V_308 ) )
return - V_318 ;
if ( F_167 ( 2 * sizeof( unsigned int ) , V_308 + 1 ) )
return - V_318 ;
if ( F_167 ( V_310 , V_308 + 2 ) )
return - V_318 ;
if ( F_167 ( V_311 , V_308 + 3 ) )
return - V_318 ;
return 0 ;
}
void F_168 ( struct V_11 * V_12 , T_2 V_24 , int V_260 ,
unsigned int * V_319 )
{
T_1 V_261 ;
int V_83 , V_320 ;
V_261 = F_135 ( V_12 , V_24 , V_260 ) ;
V_83 = ( V_261 & V_288 ) >> V_289 ;
V_320 = ( V_261 & V_312 ) >> V_313 ;
V_320 = ( V_320 + 1 ) * 25 ;
V_319 [ 0 ] = V_317 ;
V_319 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_319 [ 2 ] = - V_83 * V_320 ;
V_319 [ 3 ] = V_320 ;
}
static struct V_290 *
F_169 ( struct V_11 * V_12 , const char * V_143 , int V_321 , int V_248 )
{
struct V_322 V_136 ;
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_323 = V_324 ;
V_136 . V_111 = V_321 ;
V_136 . V_264 = V_248 ;
if ( F_43 ( strlen ( V_143 ) >= sizeof( V_136 . V_143 ) ) )
return NULL ;
strcpy ( V_136 . V_143 , V_143 ) ;
return F_170 ( V_12 -> V_7 -> V_115 , & V_136 ) ;
}
struct V_290 * F_171 ( struct V_11 * V_12 ,
const char * V_143 )
{
return F_169 ( V_12 , V_143 , 0 , 0 ) ;
}
static int F_172 ( struct V_11 * V_12 , const char * V_143 ,
int V_325 )
{
int V_17 , V_248 ;
for ( V_17 = 0 , V_248 = V_325 ; V_17 < 16 ; V_17 ++ , V_248 ++ ) {
if ( ! F_169 ( V_12 , V_143 , 0 , V_248 ) )
return V_248 ;
}
return - V_198 ;
}
int F_173 ( struct V_11 * V_12 , T_2 V_24 ,
struct V_290 * V_326 )
{
int V_33 ;
unsigned short V_25 = 0 ;
struct V_204 * V_327 ;
if ( V_326 -> V_136 . V_328 & V_329 ) {
V_25 |= V_330 ;
if ( V_24 == 0 )
V_24 = F_174 ( V_326 -> V_331 ) ;
}
if ( ( V_326 -> V_136 . V_328 & V_332 ) != 0 && V_24 == 0 )
V_24 = V_326 -> V_136 . V_328 & 0xffff ;
if ( V_326 -> V_136 . V_328 & ( V_332 | V_329 ) )
V_326 -> V_136 . V_328 = 0 ;
V_33 = F_175 ( V_12 -> V_7 -> V_115 , V_326 ) ;
if ( V_33 < 0 )
return V_33 ;
V_327 = F_84 ( & V_12 -> V_187 ) ;
if ( ! V_327 )
return - V_54 ;
V_327 -> V_326 = V_326 ;
V_327 -> V_24 = V_24 ;
V_327 -> V_25 = V_25 ;
return 0 ;
}
int F_176 ( struct V_11 * V_12 , struct V_290 * V_326 ,
unsigned int V_264 , T_2 V_24 )
{
struct V_204 * V_327 ;
if ( V_24 > 0 ) {
V_327 = F_84 ( & V_12 -> V_188 ) ;
if ( ! V_327 )
return - V_54 ;
V_327 -> V_326 = V_326 ;
V_327 -> V_264 = V_264 ;
V_327 -> V_24 = V_24 ;
return 0 ;
}
F_14 ( V_30 L_64 ,
V_326 -> V_136 . V_143 , V_326 -> V_136 . V_264 , V_264 ) ;
return - V_61 ;
}
void F_177 ( struct V_11 * V_12 )
{
int V_17 ;
struct V_204 * V_333 = V_12 -> V_187 . V_4 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_187 . V_175 ; V_17 ++ )
F_178 ( V_12 -> V_7 -> V_115 , V_333 [ V_17 ] . V_326 ) ;
F_100 ( & V_12 -> V_187 ) ;
F_100 ( & V_12 -> V_188 ) ;
}
int F_179 ( struct V_6 * V_7 )
{
struct V_114 * V_115 = V_7 -> V_115 ;
struct V_11 * V_12 ;
F_180 ( & V_115 -> V_334 ) ;
if ( V_115 -> V_113 )
goto V_335;
V_115 -> V_113 = 1 ;
if ( ! F_34 ( & V_115 -> V_336 ) )
goto V_337;
F_29 (codec, &bus->codec_list, list) {
int V_338 ;
for ( V_338 = 0 ; V_338 < V_12 -> V_339 ; V_338 ++ ) {
struct V_340 * V_341 = & V_12 -> V_342 [ V_338 ] ;
if ( ! V_341 -> V_338 )
continue;
if ( V_341 -> V_338 -> V_343 [ 0 ] . V_344 ||
V_341 -> V_338 -> V_343 [ 1 ] . V_344 )
goto V_337;
}
}
F_181 ( & V_115 -> V_334 ) ;
return 0 ;
V_337:
V_115 -> V_113 = 0 ;
V_335:
F_181 ( & V_115 -> V_334 ) ;
return - V_61 ;
}
void F_182 ( struct V_6 * V_7 )
{
struct V_114 * V_115 = V_7 -> V_115 ;
V_115 = V_7 -> V_115 ;
F_180 ( & V_115 -> V_334 ) ;
V_115 -> V_113 = 0 ;
F_181 ( & V_115 -> V_334 ) ;
}
int F_183 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_114 * V_115 = V_7 -> V_115 ;
int V_17 ;
if ( F_179 ( V_7 ) < 0 )
return - V_198 ;
F_102 ( & V_12 -> V_182 ) ;
#ifdef F_104
F_102 ( & V_12 -> V_186 ) ;
V_12 -> V_345 = 0 ;
V_12 -> V_346 = 0 ;
V_12 -> V_347 = V_348 ;
F_61 ( V_7 -> V_99 ) ;
#endif
F_177 ( V_12 ) ;
for ( V_17 = 0 ; V_17 < V_12 -> V_339 ; V_17 ++ ) {
if ( V_12 -> V_342 [ V_17 ] . V_338 ) {
F_184 ( V_115 , V_12 -> V_342 [ V_17 ] . V_338 ) ;
F_185 ( V_12 -> V_342 [ V_17 ] . V_111 ,
V_7 -> V_349 ) ;
}
}
if ( V_12 -> V_107 . free )
V_12 -> V_107 . free ( V_12 ) ;
memset ( & V_12 -> V_107 , 0 , sizeof( V_12 -> V_107 ) ) ;
F_103 ( V_12 ) ;
V_12 -> V_350 = NULL ;
V_12 -> V_351 = NULL ;
F_106 ( & V_12 -> V_191 ) ;
F_106 ( & V_12 -> V_192 ) ;
F_108 ( & V_12 -> V_191 , sizeof( struct V_202 ) ) ;
F_108 ( & V_12 -> V_192 , sizeof( struct V_203 ) ) ;
F_100 ( & V_12 -> V_176 ) ;
F_100 ( & V_12 -> V_185 ) ;
F_100 ( & V_12 -> V_189 ) ;
F_100 ( & V_12 -> V_208 ) ;
V_12 -> V_339 = 0 ;
V_12 -> V_342 = NULL ;
V_12 -> V_2 = NULL ;
V_12 -> V_352 = NULL ;
V_12 -> V_353 = 0 ;
F_77 ( V_12 -> V_135 ) ;
V_12 -> V_135 = NULL ;
F_182 ( V_7 ) ;
return 0 ;
}
static int F_186 ( struct V_11 * V_12 , const char * const * V_354 ,
const char * V_355 , T_6 V_356 , void * V_357 )
{
struct V_204 * V_333 ;
const char * const * V_358 ;
int V_17 , V_33 ;
V_333 = V_12 -> V_187 . V_4 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_187 . V_175 ; V_17 ++ ) {
struct V_290 * V_359 = V_333 [ V_17 ] . V_326 ;
if ( ! V_359 || ! V_359 -> V_136 . V_143 ||
V_359 -> V_136 . V_323 != V_324 )
continue;
for ( V_358 = V_354 ; * V_358 ; V_358 ++ ) {
char V_360 [ sizeof( V_359 -> V_136 . V_143 ) ] ;
const char * V_143 = * V_358 ;
if ( V_355 ) {
snprintf ( V_360 , sizeof( V_360 ) , L_59 ,
V_143 , V_355 ) ;
V_143 = V_360 ;
}
if ( ! strcmp ( V_359 -> V_136 . V_143 , V_143 ) ) {
V_33 = V_356 ( V_357 , V_359 ) ;
if ( V_33 )
return V_33 ;
break;
}
}
}
return 0 ;
}
static int F_187 ( void * V_357 , struct V_290 * V_359 )
{
return 1 ;
}
static int F_188 ( struct V_290 * V_326 )
{
int V_308 [ 4 ] ;
const int * V_319 = NULL ;
int V_28 = - 1 ;
if ( V_326 -> V_361 [ 0 ] . V_362 & V_363 ) {
T_7 V_364 = F_189 () ;
F_190 ( F_191 () ) ;
if ( ! V_326 -> V_319 . V_145 ( V_326 , 0 , sizeof( V_308 ) , V_308 ) )
V_319 = V_308 ;
F_190 ( V_364 ) ;
} else if ( V_326 -> V_361 [ 0 ] . V_362 & V_365 )
V_319 = V_326 -> V_319 . V_51 ;
if ( V_319 && V_319 [ 0 ] == V_317 )
V_28 = - V_319 [ 2 ] / V_319 [ 3 ] ;
return V_28 ;
}
static int F_192 ( struct V_290 * V_326 , int V_28 )
{
struct V_302 * V_303 ;
V_303 = F_58 ( sizeof( * V_303 ) , V_53 ) ;
if ( ! V_303 )
return - V_54 ;
V_303 -> V_297 . integer . V_297 [ 0 ] = V_28 ;
V_303 -> V_297 . integer . V_297 [ 1 ] = V_28 ;
V_326 -> V_366 ( V_326 , V_303 ) ;
F_37 ( V_303 ) ;
return 0 ;
}
static int F_193 ( void * V_357 , struct V_290 * V_367 )
{
int V_368 = F_188 ( V_367 ) ;
if ( V_368 > 0 )
F_192 ( V_367 , V_368 ) ;
return 0 ;
}
static int F_194 ( void * V_357 , struct V_290 * V_367 )
{
return F_192 ( V_367 , 1 ) ;
}
int F_195 ( struct V_11 * V_12 , char * V_143 ,
unsigned int * V_319 , const char * const * V_354 ,
const char * V_355 , bool V_369 ,
struct V_290 * * V_370 )
{
struct V_290 * V_326 ;
int V_33 ;
if ( V_370 )
* V_370 = NULL ;
V_33 = F_186 ( V_12 , V_354 , V_355 , F_187 , NULL ) ;
if ( V_33 != 1 ) {
F_112 ( L_65 , V_143 ) ;
return 0 ;
}
V_326 = F_196 ( V_143 , V_319 ) ;
if ( ! V_326 )
return - V_54 ;
V_33 = F_173 ( V_12 , 0 , V_326 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_186 ( V_12 , V_354 , V_355 ,
( T_6 ) V_371 , V_326 ) ;
if ( V_33 < 0 )
return V_33 ;
F_192 ( V_326 , 0 ) ;
if ( V_369 )
F_186 ( V_12 , V_354 , V_355 ,
V_319 ? F_193 : F_194 , V_326 ) ;
if ( V_370 )
* V_370 = V_326 ;
return 0 ;
}
static int F_197 ( struct V_290 * V_291 ,
struct V_292 * V_293 )
{
static const char * const V_372 [] = {
L_66 , L_67 , L_68
} ;
unsigned int V_264 ;
V_293 -> type = V_373 ;
V_293 -> V_296 = 1 ;
V_293 -> V_297 . V_374 . V_333 = 3 ;
V_264 = V_293 -> V_297 . V_374 . V_327 ;
if ( V_264 >= 3 )
V_264 = 2 ;
strcpy ( V_293 -> V_297 . V_374 . V_143 , V_372 [ V_264 ] ) ;
return 0 ;
}
static int F_198 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_375 * V_376 = F_155 ( V_291 ) ;
V_303 -> V_297 . V_374 . V_327 [ 0 ] = V_376 -> V_377 ;
return 0 ;
}
static int F_199 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_375 * V_376 = F_155 ( V_291 ) ;
unsigned int V_378 = V_376 -> V_377 ;
V_376 -> V_377 = V_303 -> V_297 . V_374 . V_327 [ 0 ] ;
if ( V_376 -> V_377 > V_379 )
V_376 -> V_377 = V_379 ;
if ( V_378 == V_376 -> V_377 )
return 0 ;
F_200 ( V_376 ) ;
return 1 ;
}
int F_201 ( struct V_11 * V_12 ,
struct V_375 * V_376 ,
bool V_380 )
{
struct V_290 * V_326 ;
if ( ! V_376 -> V_376 || ! V_376 -> V_381 )
return 0 ;
F_202 ( V_376 -> V_381 , V_376 -> V_376 , V_12 ) ;
V_376 -> V_12 = V_12 ;
V_376 -> V_377 = V_379 ;
if ( ! V_380 )
return 0 ;
V_326 = F_203 ( & V_382 , V_376 ) ;
if ( ! V_326 )
return - V_54 ;
return F_173 ( V_12 , 0 , V_326 ) ;
}
void F_200 ( struct V_375 * V_376 )
{
if ( ! V_376 -> V_376 || ! V_376 -> V_12 )
return;
if ( V_376 -> V_12 -> V_7 -> V_113 )
return;
switch ( V_376 -> V_377 ) {
case V_379 :
F_204 ( V_376 -> V_381 ) ;
break;
default:
V_376 -> V_376 ( V_376 -> V_12 , V_376 -> V_377 ) ;
break;
}
}
int F_205 ( struct V_290 * V_291 ,
struct V_292 * V_293 )
{
int V_294 = F_157 ( V_291 ) ;
V_293 -> type = V_383 ;
V_293 -> V_296 = V_294 == 3 ? 2 : 1 ;
V_293 -> V_297 . integer . V_298 = 0 ;
V_293 -> V_297 . integer . V_299 = 1 ;
return 0 ;
}
int F_206 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
T_2 V_24 = F_156 ( V_291 ) ;
int V_294 = F_157 ( V_291 ) ;
int V_260 = F_158 ( V_291 ) ;
int V_248 = F_163 ( V_291 ) ;
long * V_304 = V_303 -> V_297 . integer . V_297 ;
if ( V_294 & 1 )
* V_304 ++ = ( F_146 ( V_12 , V_24 , 0 , V_260 , V_248 ) &
V_279 ) ? 0 : 1 ;
if ( V_294 & 2 )
* V_304 = ( F_146 ( V_12 , V_24 , 1 , V_260 , V_248 ) &
V_279 ) ? 0 : 1 ;
return 0 ;
}
int F_207 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
T_2 V_24 = F_156 ( V_291 ) ;
int V_294 = F_157 ( V_291 ) ;
int V_260 = F_158 ( V_291 ) ;
int V_248 = F_163 ( V_291 ) ;
long * V_304 = V_303 -> V_297 . integer . V_297 ;
int V_305 = 0 ;
F_16 ( V_12 ) ;
if ( V_294 & 1 ) {
V_305 = F_148 ( V_12 , V_24 , 0 , V_260 , V_248 ,
V_279 ,
* V_304 ? 0 : V_279 ) ;
V_304 ++ ;
}
if ( V_294 & 2 )
V_305 |= F_148 ( V_12 , V_24 , 1 , V_260 , V_248 ,
V_279 ,
* V_304 ? 0 : V_279 ) ;
F_208 ( V_12 , V_24 ) ;
F_19 ( V_12 ) ;
return V_305 ;
}
int F_209 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
unsigned long V_384 ;
int V_33 ;
F_2 ( & V_12 -> V_200 ) ;
V_384 = V_291 -> V_331 ;
V_291 -> V_331 = V_384 & ~ V_385 ;
V_33 = F_206 ( V_291 , V_303 ) ;
V_291 -> V_331 = V_384 ;
F_4 ( & V_12 -> V_200 ) ;
return V_33 ;
}
int F_210 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
unsigned long V_384 ;
int V_17 , V_386 , V_33 = 0 , V_305 = 0 ;
F_2 ( & V_12 -> V_200 ) ;
V_384 = V_291 -> V_331 ;
V_386 = ( V_384 & V_385 ) >> V_387 ;
for ( V_17 = 0 ; V_17 < V_386 ; V_17 ++ ) {
V_291 -> V_331 = ( V_384 & ~ V_385 ) |
( V_17 << V_387 ) ;
V_33 = F_207 ( V_291 , V_303 ) ;
if ( V_33 < 0 )
break;
V_305 |= V_33 ;
}
V_291 -> V_331 = V_384 ;
F_4 ( & V_12 -> V_200 ) ;
return V_33 < 0 ? V_33 : V_305 ;
}
int F_211 ( struct V_290 * V_291 ,
struct V_292 * V_293 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
struct V_388 * V_145 ;
int V_33 ;
F_2 ( & V_12 -> V_200 ) ;
V_145 = (struct V_388 * ) V_291 -> V_331 ;
V_291 -> V_331 = * V_145 -> V_389 ;
V_33 = V_145 -> V_9 -> V_250 ( V_291 , V_293 ) ;
V_291 -> V_331 = ( long ) V_145 ;
F_4 ( & V_12 -> V_200 ) ;
return V_33 ;
}
int F_212 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
struct V_388 * V_145 ;
int V_33 ;
F_2 ( & V_12 -> V_200 ) ;
V_145 = (struct V_388 * ) V_291 -> V_331 ;
V_291 -> V_331 = * V_145 -> V_389 ;
V_33 = V_145 -> V_9 -> V_390 ( V_291 , V_303 ) ;
V_291 -> V_331 = ( long ) V_145 ;
F_4 ( & V_12 -> V_200 ) ;
return V_33 ;
}
int F_213 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
struct V_388 * V_145 ;
unsigned long * V_391 ;
int V_33 = 0 , V_305 = 0 ;
F_2 ( & V_12 -> V_200 ) ;
V_145 = (struct V_388 * ) V_291 -> V_331 ;
for ( V_391 = V_145 -> V_389 ; * V_391 ; V_391 ++ ) {
V_291 -> V_331 = * V_391 ;
V_33 = V_145 -> V_9 -> V_366 ( V_291 , V_303 ) ;
if ( V_33 < 0 )
break;
V_305 |= V_33 ;
}
V_291 -> V_331 = ( long ) V_145 ;
F_4 ( & V_12 -> V_200 ) ;
return V_33 < 0 ? V_33 : V_305 ;
}
int F_214 ( struct V_290 * V_291 , int V_306 ,
unsigned int V_307 , unsigned int T_5 * V_319 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
struct V_388 * V_145 ;
int V_33 ;
F_2 ( & V_12 -> V_200 ) ;
V_145 = (struct V_388 * ) V_291 -> V_331 ;
V_291 -> V_331 = * V_145 -> V_389 ;
V_33 = V_145 -> V_9 -> V_319 ( V_291 , V_306 , V_307 , V_319 ) ;
V_291 -> V_331 = ( long ) V_145 ;
F_4 ( & V_12 -> V_200 ) ;
return V_33 ;
}
static int F_215 ( struct V_290 * V_291 ,
struct V_292 * V_293 )
{
V_293 -> type = V_392 ;
V_293 -> V_296 = 1 ;
return 0 ;
}
static int F_216 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
V_303 -> V_297 . V_393 . V_394 [ 0 ] = V_395 |
V_396 |
V_397 |
V_398 ;
V_303 -> V_297 . V_393 . V_394 [ 1 ] = V_399 |
V_400 ;
return 0 ;
}
static int F_217 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
V_303 -> V_297 . V_393 . V_394 [ 0 ] = V_395 |
V_396 |
V_401 ;
return 0 ;
}
static int F_218 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
int V_248 = V_291 -> V_331 ;
struct V_205 * V_402 ;
F_2 ( & V_12 -> V_199 ) ;
V_402 = F_86 ( & V_12 -> V_189 , V_248 ) ;
V_303 -> V_297 . V_393 . V_394 [ 0 ] = V_402 -> V_394 & 0xff ;
V_303 -> V_297 . V_393 . V_394 [ 1 ] = ( V_402 -> V_394 >> 8 ) & 0xff ;
V_303 -> V_297 . V_393 . V_394 [ 2 ] = ( V_402 -> V_394 >> 16 ) & 0xff ;
V_303 -> V_297 . V_393 . V_394 [ 3 ] = ( V_402 -> V_394 >> 24 ) & 0xff ;
F_4 ( & V_12 -> V_199 ) ;
return 0 ;
}
static unsigned short F_219 ( unsigned int V_403 )
{
unsigned short V_28 = 0 ;
if ( V_403 & V_395 )
V_28 |= V_404 ;
if ( V_403 & V_396 )
V_28 |= V_405 ;
if ( V_403 & V_395 ) {
if ( ( V_403 & V_406 ) ==
V_401 )
V_28 |= V_407 ;
} else {
if ( ( V_403 & V_408 ) ==
V_397 )
V_28 |= V_407 ;
if ( ! ( V_403 & V_398 ) )
V_28 |= V_409 ;
if ( V_403 & ( V_400 << 8 ) )
V_28 |= V_410 ;
V_28 |= V_403 & ( V_399 << 8 ) ;
}
return V_28 ;
}
static unsigned int F_220 ( unsigned short V_28 )
{
unsigned int V_403 = 0 ;
if ( V_28 & V_405 )
V_403 |= V_396 ;
if ( V_28 & V_404 )
V_403 |= V_395 ;
if ( V_403 & V_395 ) {
if ( V_28 & V_407 )
V_403 |= V_401 ;
} else {
if ( V_28 & V_407 )
V_403 |= V_397 ;
if ( ! ( V_28 & V_409 ) )
V_403 |= V_398 ;
if ( V_28 & V_410 )
V_403 |= ( V_400 << 8 ) ;
V_403 |= V_28 & ( 0x7f << 8 ) ;
}
return V_403 ;
}
static void F_221 ( struct V_11 * V_12 , T_2 V_24 ,
int V_26 , int V_28 )
{
const T_2 * V_411 ;
F_222 ( V_12 , V_24 , 0 , V_26 , V_28 ) ;
V_411 = V_12 -> V_352 ;
if ( ! V_411 )
return;
for (; * V_411 ; V_411 ++ )
F_222 ( V_12 , * V_411 , 0 , V_26 , V_28 ) ;
}
static inline void F_223 ( struct V_11 * V_12 , T_2 V_24 ,
int V_412 , int V_413 )
{
if ( V_412 != - 1 )
F_221 ( V_12 , V_24 , V_414 , V_412 ) ;
if ( V_413 != - 1 )
F_221 ( V_12 , V_24 , V_415 , V_413 ) ;
}
static int F_224 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
int V_248 = V_291 -> V_331 ;
struct V_205 * V_402 ;
T_2 V_24 ;
unsigned short V_28 ;
int V_305 ;
F_2 ( & V_12 -> V_199 ) ;
V_402 = F_86 ( & V_12 -> V_189 , V_248 ) ;
V_24 = V_402 -> V_24 ;
V_402 -> V_394 = V_303 -> V_297 . V_393 . V_394 [ 0 ] |
( ( unsigned int ) V_303 -> V_297 . V_393 . V_394 [ 1 ] << 8 ) |
( ( unsigned int ) V_303 -> V_297 . V_393 . V_394 [ 2 ] << 16 ) |
( ( unsigned int ) V_303 -> V_297 . V_393 . V_394 [ 3 ] << 24 ) ;
V_28 = F_219 ( V_402 -> V_394 ) ;
V_28 |= V_402 -> V_416 & 1 ;
V_305 = V_402 -> V_416 != V_28 ;
V_402 -> V_416 = V_28 ;
if ( V_305 && V_24 != ( T_4 ) - 1 )
F_223 ( V_12 , V_24 , V_28 & 0xff , ( V_28 >> 8 ) & 0xff ) ;
F_4 ( & V_12 -> V_199 ) ;
return V_305 ;
}
static int F_225 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
int V_248 = V_291 -> V_331 ;
struct V_205 * V_402 ;
F_2 ( & V_12 -> V_199 ) ;
V_402 = F_86 ( & V_12 -> V_189 , V_248 ) ;
V_303 -> V_297 . integer . V_297 [ 0 ] = V_402 -> V_416 & V_417 ;
F_4 ( & V_12 -> V_199 ) ;
return 0 ;
}
static inline void F_226 ( struct V_11 * V_12 , T_2 V_24 ,
int V_412 , int V_413 )
{
F_223 ( V_12 , V_24 , V_412 , V_413 ) ;
if ( ( F_47 ( V_12 , V_24 ) & V_418 ) &&
( V_412 & V_417 ) )
F_149 ( V_12 , V_24 , V_257 , 0 ,
V_279 , 0 ) ;
}
static int F_227 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
int V_248 = V_291 -> V_331 ;
struct V_205 * V_402 ;
T_2 V_24 ;
unsigned short V_28 ;
int V_305 ;
F_2 ( & V_12 -> V_199 ) ;
V_402 = F_86 ( & V_12 -> V_189 , V_248 ) ;
V_24 = V_402 -> V_24 ;
V_28 = V_402 -> V_416 & ~ V_417 ;
if ( V_303 -> V_297 . integer . V_297 [ 0 ] )
V_28 |= V_417 ;
V_305 = V_402 -> V_416 != V_28 ;
V_402 -> V_416 = V_28 ;
if ( V_305 && V_24 != ( T_4 ) - 1 )
F_226 ( V_12 , V_24 , V_28 & 0xff , - 1 ) ;
F_4 ( & V_12 -> V_199 ) ;
return V_305 ;
}
int F_228 ( struct V_11 * V_12 ,
T_2 V_419 ,
T_2 V_420 ,
int type )
{
int V_33 ;
struct V_290 * V_326 ;
struct V_421 * V_422 ;
int V_248 = 0 ;
const int V_423 = 16 ;
struct V_205 * V_402 ;
struct V_6 * V_7 = V_12 -> V_7 ;
if ( V_7 -> V_424 == V_425 &&
type == V_426 ) {
V_248 = V_423 ;
} else if ( V_7 -> V_424 == V_426 &&
type == V_425 ) {
for ( V_422 = V_427 ; V_422 -> V_143 ; V_422 ++ ) {
V_326 = F_169 ( V_12 , V_422 -> V_143 , 0 , 0 ) ;
if ( ! V_326 )
break;
V_326 -> V_136 . V_264 = V_423 ;
}
V_7 -> V_424 = V_425 ;
}
if ( ! V_7 -> V_424 )
V_7 -> V_424 = type ;
V_248 = F_172 ( V_12 , L_69 , V_248 ) ;
if ( V_248 < 0 ) {
F_14 ( V_30 L_70 ) ;
return - V_198 ;
}
V_402 = F_84 ( & V_12 -> V_189 ) ;
if ( ! V_402 )
return - V_54 ;
for ( V_422 = V_427 ; V_422 -> V_143 ; V_422 ++ ) {
V_326 = F_203 ( V_422 , V_12 ) ;
if ( ! V_326 )
return - V_54 ;
V_326 -> V_136 . V_264 = V_248 ;
V_326 -> V_331 = V_12 -> V_189 . V_175 - 1 ;
V_33 = F_173 ( V_12 , V_419 , V_326 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_402 -> V_24 = V_420 ;
V_402 -> V_416 = F_23 ( V_12 , V_420 , 0 ,
V_428 , 0 ) ;
V_402 -> V_394 = F_220 ( V_402 -> V_416 ) ;
return 0 ;
}
struct V_205 * F_229 ( struct V_11 * V_12 ,
T_2 V_24 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_189 . V_175 ; V_17 ++ ) {
struct V_205 * V_402 =
F_86 ( & V_12 -> V_189 , V_17 ) ;
if ( V_402 -> V_24 == V_24 )
return V_402 ;
}
return NULL ;
}
void F_230 ( struct V_11 * V_12 , int V_248 )
{
struct V_205 * V_402 ;
F_2 ( & V_12 -> V_199 ) ;
V_402 = F_86 ( & V_12 -> V_189 , V_248 ) ;
V_402 -> V_24 = ( T_4 ) - 1 ;
F_4 ( & V_12 -> V_199 ) ;
}
void F_231 ( struct V_11 * V_12 , int V_248 , T_2 V_24 )
{
struct V_205 * V_402 ;
unsigned short V_28 ;
F_2 ( & V_12 -> V_199 ) ;
V_402 = F_86 ( & V_12 -> V_189 , V_248 ) ;
if ( V_402 -> V_24 != V_24 ) {
V_402 -> V_24 = V_24 ;
V_28 = V_402 -> V_416 ;
F_226 ( V_12 , V_24 , V_28 & 0xff , ( V_28 >> 8 ) & 0xff ) ;
}
F_4 ( & V_12 -> V_199 ) ;
}
static int F_232 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_429 * V_430 = F_155 ( V_291 ) ;
V_303 -> V_297 . integer . V_297 [ 0 ] = V_430 -> V_431 ;
return 0 ;
}
static int F_233 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_429 * V_430 = F_155 ( V_291 ) ;
V_430 -> V_431 = ! ! V_303 -> V_297 . integer . V_297 [ 0 ] ;
return 0 ;
}
int F_234 ( struct V_11 * V_12 ,
struct V_429 * V_430 )
{
struct V_290 * V_326 ;
if ( ! V_430 -> V_432 )
return 0 ;
V_326 = F_203 ( & V_433 , V_430 ) ;
if ( ! V_326 )
return - V_54 ;
return F_173 ( V_12 , V_430 -> V_432 , V_326 ) ;
}
static int F_235 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
V_303 -> V_297 . integer . V_297 [ 0 ] = V_12 -> V_434 ;
return 0 ;
}
static int F_236 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
T_2 V_24 = V_291 -> V_331 ;
unsigned int V_28 = ! ! V_303 -> V_297 . integer . V_297 [ 0 ] ;
int V_305 ;
F_2 ( & V_12 -> V_199 ) ;
V_305 = V_12 -> V_434 != V_28 ;
if ( V_305 ) {
V_12 -> V_434 = V_28 ;
F_222 ( V_12 , V_24 , 0 ,
V_414 , V_28 ) ;
}
F_4 ( & V_12 -> V_199 ) ;
return V_305 ;
}
static int F_237 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
T_2 V_24 = V_291 -> V_331 ;
unsigned short V_28 ;
unsigned int V_403 ;
V_28 = F_23 ( V_12 , V_24 , 0 , V_428 , 0 ) ;
V_403 = F_220 ( V_28 ) ;
V_303 -> V_297 . V_393 . V_394 [ 0 ] = V_403 ;
V_303 -> V_297 . V_393 . V_394 [ 1 ] = V_403 >> 8 ;
V_303 -> V_297 . V_393 . V_394 [ 2 ] = V_403 >> 16 ;
V_303 -> V_297 . V_393 . V_394 [ 3 ] = V_403 >> 24 ;
return 0 ;
}
int F_238 ( struct V_11 * V_12 , T_2 V_24 )
{
int V_33 ;
struct V_290 * V_326 ;
struct V_421 * V_422 ;
int V_248 ;
V_248 = F_172 ( V_12 , L_71 , 0 ) ;
if ( V_248 < 0 ) {
F_14 ( V_30 L_72 ) ;
return - V_198 ;
}
for ( V_422 = V_435 ; V_422 -> V_143 ; V_422 ++ ) {
V_326 = F_203 ( V_422 , V_12 ) ;
if ( ! V_326 )
return - V_54 ;
V_326 -> V_331 = V_24 ;
V_33 = F_173 ( V_12 , V_24 , V_326 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_12 -> V_434 =
F_23 ( V_12 , V_24 , 0 ,
V_428 , 0 ) &
V_417 ;
return 0 ;
}
int F_222 ( struct V_11 * V_12 , T_2 V_24 ,
int V_25 , unsigned int V_26 , unsigned int V_27 )
{
int V_33 ;
struct V_203 * V_145 ;
T_1 V_247 ;
unsigned int V_283 ;
V_283 = V_12 -> V_284 ;
if ( ! V_283 ) {
V_33 = F_24 ( V_12 , V_24 , V_25 , V_26 , V_27 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_26 = V_26 | ( V_27 >> 8 ) ;
V_27 &= 0xff ;
V_247 = F_239 ( V_24 , V_26 ) ;
F_2 ( & V_12 -> V_7 -> V_35 ) ;
V_145 = F_130 ( & V_12 -> V_192 , V_247 ) ;
if ( V_145 ) {
V_145 -> V_28 = V_27 ;
V_145 -> V_238 = V_283 ;
}
F_4 ( & V_12 -> V_7 -> V_35 ) ;
return 0 ;
}
int F_240 ( struct V_11 * V_12 , T_2 V_24 ,
int V_25 , unsigned int V_26 , unsigned int V_27 )
{
struct V_203 * V_145 ;
T_1 V_247 ;
V_26 = V_26 | ( V_27 >> 8 ) ;
V_27 &= 0xff ;
V_247 = F_239 ( V_24 , V_26 ) ;
F_2 ( & V_12 -> V_7 -> V_35 ) ;
V_145 = F_129 ( & V_12 -> V_192 , V_247 ) ;
if ( V_145 && V_145 -> V_28 == V_27 ) {
F_4 ( & V_12 -> V_7 -> V_35 ) ;
return 0 ;
}
F_4 ( & V_12 -> V_7 -> V_35 ) ;
return F_222 ( V_12 , V_24 , V_25 , V_26 , V_27 ) ;
}
void F_241 ( struct V_11 * V_12 )
{
int V_17 ;
F_2 ( & V_12 -> V_201 ) ;
V_12 -> V_284 = 0 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_192 . V_246 . V_175 ; V_17 ++ ) {
struct V_203 * V_286 ;
T_1 V_247 ;
V_286 = F_86 ( & V_12 -> V_192 . V_246 , V_17 ) ;
V_247 = V_286 -> V_247 ;
if ( ! V_247 )
continue;
if ( ! V_286 -> V_238 )
continue;
V_286 -> V_238 = 0 ;
F_4 ( & V_12 -> V_201 ) ;
F_24 ( V_12 , F_242 ( V_247 ) , 0 ,
F_243 ( V_247 ) , V_286 -> V_28 ) ;
F_2 ( & V_12 -> V_201 ) ;
}
F_4 ( & V_12 -> V_201 ) ;
}
void F_244 ( struct V_11 * V_12 ,
const struct V_45 * V_46 )
{
for (; V_46 -> V_24 ; V_46 ++ )
F_222 ( V_12 , V_46 -> V_24 , 0 , V_46 -> V_26 ,
V_46 -> V_47 ) ;
}
void F_245 ( struct V_11 * V_12 )
{
F_152 ( V_12 ) ;
F_241 ( V_12 ) ;
}
void F_246 ( struct V_11 * V_12 , T_2 V_196 ,
unsigned int V_436 )
{
T_2 V_24 = V_12 -> V_164 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_163 ; V_17 ++ , V_24 ++ ) {
unsigned int V_63 = F_47 ( V_12 , V_24 ) ;
unsigned int V_437 = V_436 ;
if ( ! ( V_63 & V_438 ) )
continue;
if ( V_12 -> V_439 ) {
V_437 = V_12 -> V_439 ( V_12 , V_24 , V_436 ) ;
if ( V_437 != V_436 && V_436 == V_440 )
continue;
}
F_24 ( V_12 , V_24 , 0 , V_441 ,
V_437 ) ;
}
}
static bool F_113 ( struct V_11 * V_12 , T_2 V_196 ,
unsigned int V_436 )
{
int V_442 = F_27 ( V_12 , V_196 , V_443 ) ;
if ( V_442 == - 1 )
return false ;
if ( V_442 & V_436 )
return true ;
else
return false ;
}
static unsigned int F_247 ( struct V_11 * V_12 ,
T_2 V_196 ,
unsigned int V_436 )
{
unsigned long V_444 = V_348 + F_248 ( 500 ) ;
unsigned int V_437 , V_445 ;
for (; ; ) {
V_437 = F_23 ( V_12 , V_196 , 0 ,
V_446 , 0 ) ;
if ( V_437 & V_447 )
break;
V_445 = ( V_437 >> 4 ) & 0x0f ;
if ( V_445 == V_436 )
break;
if ( F_249 ( V_348 , V_444 ) )
break;
F_123 ( 1 ) ;
}
return V_437 ;
}
unsigned int F_250 ( struct V_11 * V_12 ,
T_2 V_24 ,
unsigned int V_436 )
{
if ( V_436 == V_440 &&
F_48 ( F_47 ( V_12 , V_24 ) ) == V_84 &&
( F_140 ( V_12 , V_24 ) & V_448 ) ) {
int V_449 = F_23 ( V_12 , V_24 , 0 ,
V_450 , 0 ) ;
if ( V_449 & 0x02 )
return V_222 ;
}
return V_436 ;
}
static unsigned int F_114 ( struct V_11 * V_12 ,
unsigned int V_436 )
{
T_2 V_196 = V_12 -> V_137 ? V_12 -> V_137 : V_12 -> V_138 ;
int V_296 ;
unsigned int V_437 ;
int V_25 = 0 ;
if ( V_436 == V_440 ) {
F_123 ( V_12 -> V_220 ? 10 : 100 ) ;
V_25 = V_36 ;
}
for ( V_296 = 0 ; V_296 < 10 ; V_296 ++ ) {
if ( V_12 -> V_107 . V_451 )
V_12 -> V_107 . V_451 ( V_12 , V_196 ,
V_436 ) ;
else {
F_23 ( V_12 , V_196 , V_25 ,
V_441 ,
V_436 ) ;
F_246 ( V_12 , V_196 , V_436 ) ;
}
V_437 = F_247 ( V_12 , V_196 , V_436 ) ;
if ( ! ( V_437 & V_447 ) )
break;
}
return V_437 ;
}
static void F_251 ( struct V_11 * V_12 )
{
T_2 V_24 = V_12 -> V_164 ;
int V_17 ;
if ( ! V_12 -> V_439 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_163 ; V_17 ++ , V_24 ++ ) {
unsigned int V_63 = F_47 ( V_12 , V_24 ) ;
unsigned int V_179 ;
if ( ! ( V_63 & V_438 ) )
continue;
V_179 = V_12 -> V_439 ( V_12 , V_24 , V_222 ) ;
if ( V_179 == V_222 )
continue;
if ( ! F_252 ( V_12 , V_24 , V_179 ) )
F_24 ( V_12 , V_24 , 0 ,
V_441 , V_179 ) ;
}
}
static void F_253 ( struct V_11 * V_12 )
{
if ( V_12 -> V_452 . V_4 )
F_25 ( V_12 , V_12 -> V_452 . V_4 ) ;
}
static inline void F_253 ( struct V_11 * V_12 ) {}
static unsigned int F_254 ( struct V_11 * V_12 , bool V_453 )
{
unsigned int V_437 ;
V_12 -> V_454 = 1 ;
if ( V_12 -> V_107 . V_455 )
V_12 -> V_107 . V_455 ( V_12 ) ;
F_128 ( V_12 ) ;
V_437 = F_114 ( V_12 , V_440 ) ;
if ( ! V_453 )
F_102 ( & V_12 -> V_186 ) ;
F_180 ( & V_12 -> V_209 ) ;
F_255 ( V_12 ) ;
F_256 ( V_12 ) ;
V_12 -> V_345 = 0 ;
V_12 -> V_346 = 0 ;
V_12 -> V_347 = V_348 ;
F_181 ( & V_12 -> V_209 ) ;
V_12 -> V_454 = 0 ;
return V_437 ;
}
static void F_257 ( struct V_11 * V_12 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_192 . V_246 . V_175 ; V_17 ++ ) {
struct V_203 * V_31 ;
V_31 = F_86 ( & V_12 -> V_192 . V_246 , V_17 ) ;
V_31 -> V_238 = 1 ;
}
for ( V_17 = 0 ; V_17 < V_12 -> V_191 . V_246 . V_175 ; V_17 ++ ) {
struct V_202 * V_456 ;
V_456 = F_86 ( & V_12 -> V_191 . V_246 , V_17 ) ;
V_456 -> V_253 . V_238 = 1 ;
}
}
static void F_258 ( struct V_11 * V_12 )
{
V_12 -> V_454 = 1 ;
F_257 ( V_12 ) ;
F_8 ( V_12 ) ;
F_114 ( V_12 , V_222 ) ;
F_94 ( V_12 ) ;
F_253 ( V_12 ) ;
F_96 ( V_12 ) ;
if ( V_12 -> V_107 . V_457 )
V_12 -> V_107 . V_457 ( V_12 ) ;
else {
if ( V_12 -> V_107 . V_458 )
V_12 -> V_107 . V_458 ( V_12 ) ;
F_152 ( V_12 ) ;
F_241 ( V_12 ) ;
}
if ( V_12 -> V_183 )
F_95 ( & V_12 -> V_182 . V_102 ) ;
else
F_259 ( V_12 ) ;
V_12 -> V_454 = 0 ;
F_19 ( V_12 ) ;
}
int F_260 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
int V_33 = F_261 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_73
L_74 , V_12 -> V_29 , V_33 ) ;
V_33 = F_183 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30
L_75 ) ;
return V_33 ;
}
}
}
return 0 ;
}
static int F_262 ( struct V_11 * V_12 )
{
int V_17 , V_459 , V_33 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_339 ; V_17 ++ ) {
for ( V_459 = 0 ; V_459 < 2 ; V_459 ++ ) {
struct V_460 * V_338 = V_12 -> V_342 [ V_17 ] . V_338 ;
struct V_461 * V_462 =
& V_12 -> V_342 [ V_17 ] . V_463 [ V_459 ] ;
struct V_464 * V_465 ;
const struct V_466 * V_467 ;
if ( V_12 -> V_342 [ V_17 ] . V_468 )
continue;
if ( ! V_338 || ! V_462 -> V_469 )
continue;
V_467 = V_462 -> V_465 ? V_462 -> V_465 : V_470 ;
V_33 = F_263 ( V_338 , V_459 , V_467 ,
V_462 -> V_471 ,
0 , & V_465 ) ;
if ( V_33 < 0 )
return V_33 ;
V_465 -> V_472 = V_473 ;
}
}
return 0 ;
}
int F_261 ( struct V_11 * V_12 )
{
int V_33 = 0 ;
F_253 ( V_12 ) ;
if ( V_12 -> V_107 . V_458 )
V_33 = V_12 -> V_107 . V_458 ( V_12 ) ;
if ( ! V_33 && V_12 -> V_107 . V_474 )
V_33 = V_12 -> V_107 . V_474 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_262 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_12 -> V_183 )
F_95 ( & V_12 -> V_182 . V_102 ) ;
else
F_259 ( V_12 ) ;
F_251 ( V_12 ) ;
return 0 ;
}
unsigned int F_264 ( unsigned int V_475 ,
unsigned int V_476 ,
unsigned int V_232 ,
unsigned int V_477 ,
unsigned short V_478 )
{
int V_17 ;
unsigned int V_28 = 0 ;
for ( V_17 = 0 ; V_479 [ V_17 ] . V_480 ; V_17 ++ )
if ( V_479 [ V_17 ] . V_480 == V_475 ) {
V_28 = V_479 [ V_17 ] . V_481 ;
break;
}
if ( ! V_479 [ V_17 ] . V_480 ) {
F_112 ( L_76 , V_475 ) ;
return 0 ;
}
if ( V_476 == 0 || V_476 > 8 ) {
F_112 ( L_77 , V_476 ) ;
return 0 ;
}
V_28 |= V_476 - 1 ;
switch ( F_265 ( V_232 ) ) {
case 8 :
V_28 |= V_482 ;
break;
case 16 :
V_28 |= V_483 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_477 >= 32 || V_232 == V_484 )
V_28 |= V_485 ;
else if ( V_477 >= 24 )
V_28 |= V_486 ;
else
V_28 |= V_487 ;
break;
default:
F_112 ( L_78 ,
F_265 ( V_232 ) ) ;
return 0 ;
}
if ( V_478 & V_405 )
V_28 |= V_488 ;
return V_28 ;
}
static unsigned int F_266 ( struct V_11 * V_12 , T_2 V_24 ,
int V_260 )
{
unsigned int V_28 = 0 ;
if ( V_24 != V_12 -> V_137 &&
( F_47 ( V_12 , V_24 ) & V_489 ) )
V_28 = F_27 ( V_12 , V_24 , V_490 ) ;
if ( ! V_28 || V_28 == - 1 )
V_28 = F_27 ( V_12 , V_12 -> V_137 , V_490 ) ;
if ( ! V_28 || V_28 == - 1 )
return 0 ;
return V_28 ;
}
static unsigned int F_267 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_136 ( V_12 , V_24 , 0 , F_268 ( V_24 ) ,
F_266 ) ;
}
static unsigned int F_269 ( struct V_11 * V_12 , T_2 V_24 ,
int V_260 )
{
unsigned int V_343 = F_27 ( V_12 , V_24 , V_491 ) ;
if ( ! V_343 || V_343 == - 1 )
V_343 = F_27 ( V_12 , V_12 -> V_137 , V_491 ) ;
if ( ! V_343 || V_343 == - 1 )
return 0 ;
return V_343 ;
}
static unsigned int F_270 ( struct V_11 * V_12 , T_2 V_24 )
{
return F_136 ( V_12 , V_24 , 0 , F_271 ( V_24 ) ,
F_269 ) ;
}
int F_272 ( struct V_11 * V_12 , T_2 V_24 ,
T_1 * V_492 , T_8 * V_493 , unsigned int * V_494 )
{
unsigned int V_17 , V_28 , V_63 ;
V_63 = F_47 ( V_12 , V_24 ) ;
V_28 = F_267 ( V_12 , V_24 ) ;
if ( V_492 ) {
T_1 V_495 = 0 ;
for ( V_17 = 0 ; V_17 < V_496 ; V_17 ++ ) {
if ( V_28 & ( 1 << V_17 ) )
V_495 |= V_479 [ V_17 ] . V_497 ;
}
if ( V_495 == 0 ) {
F_45 ( V_30 L_79
L_80 ,
V_24 , V_28 ,
( V_63 & V_489 ) ? 1 : 0 ) ;
return - V_76 ;
}
* V_492 = V_495 ;
}
if ( V_493 || V_494 ) {
T_8 V_498 = 0 ;
unsigned int V_343 , V_499 ;
V_343 = F_270 ( V_12 , V_24 ) ;
if ( ! V_343 )
return - V_76 ;
V_499 = 0 ;
if ( V_343 & V_500 ) {
if ( V_28 & V_501 ) {
V_498 |= V_502 ;
V_499 = 8 ;
}
if ( V_28 & V_503 ) {
V_498 |= V_504 ;
V_499 = 16 ;
}
if ( V_63 & V_87 ) {
if ( V_28 & V_505 )
V_498 |= V_506 ;
if ( V_28 & ( V_507 | V_508 ) )
V_498 |= V_509 ;
if ( V_28 & V_508 )
V_499 = 24 ;
else if ( V_28 & V_507 )
V_499 = 20 ;
} else if ( V_28 & ( V_507 | V_508 |
V_505 ) ) {
V_498 |= V_509 ;
if ( V_28 & V_505 )
V_499 = 32 ;
else if ( V_28 & V_508 )
V_499 = 24 ;
else if ( V_28 & V_507 )
V_499 = 20 ;
}
}
#if 0
if (streams & AC_SUPFMT_FLOAT32) {
formats |= SNDRV_PCM_FMTBIT_FLOAT_LE;
if (!bps)
bps = 32;
}
#endif
if ( V_343 == V_510 ) {
V_498 |= V_502 ;
V_499 = 8 ;
}
if ( V_498 == 0 ) {
F_45 ( V_30 L_81
L_82
L_83 ,
V_24 , V_28 ,
( V_63 & V_489 ) ? 1 : 0 ,
V_343 ) ;
return - V_76 ;
}
if ( V_493 )
* V_493 = V_498 ;
if ( V_494 )
* V_494 = V_499 ;
}
return 0 ;
}
int F_273 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_232 )
{
int V_17 ;
unsigned int V_28 = 0 , V_475 , V_463 ;
V_28 = F_267 ( V_12 , V_24 ) ;
if ( ! V_28 )
return 0 ;
V_475 = V_232 & 0xff00 ;
for ( V_17 = 0 ; V_17 < V_496 ; V_17 ++ )
if ( V_479 [ V_17 ] . V_481 == V_475 ) {
if ( V_28 & ( 1 << V_17 ) )
break;
return 0 ;
}
if ( V_17 >= V_496 )
return 0 ;
V_463 = F_270 ( V_12 , V_24 ) ;
if ( ! V_463 )
return 0 ;
if ( V_463 & V_500 ) {
switch ( V_232 & 0xf0 ) {
case 0x00 :
if ( ! ( V_28 & V_501 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_28 & V_503 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_28 & V_507 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_28 & V_508 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_28 & V_505 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_274 ( struct V_461 * V_462 ,
struct V_11 * V_12 ,
struct V_511 * V_512 )
{
return 0 ;
}
static int F_275 ( struct V_461 * V_462 ,
struct V_11 * V_12 ,
unsigned int V_226 ,
unsigned int V_232 ,
struct V_511 * V_512 )
{
F_124 ( V_12 , V_462 -> V_24 , V_226 , 0 , V_232 ) ;
return 0 ;
}
static int F_276 ( struct V_461 * V_462 ,
struct V_11 * V_12 ,
struct V_511 * V_512 )
{
F_277 ( V_12 , V_462 -> V_24 ) ;
return 0 ;
}
static int F_278 ( struct V_11 * V_12 ,
struct V_461 * V_250 )
{
int V_33 ;
if ( V_250 -> V_24 && ( ! V_250 -> V_495 || ! V_250 -> V_498 ) ) {
V_33 = F_272 ( V_12 , V_250 -> V_24 ,
V_250 -> V_495 ? NULL : & V_250 -> V_495 ,
V_250 -> V_498 ? NULL : & V_250 -> V_498 ,
V_250 -> V_477 ? NULL : & V_250 -> V_477 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_250 -> V_9 . V_513 == NULL )
V_250 -> V_9 . V_513 = F_274 ;
if ( V_250 -> V_9 . V_514 == NULL )
V_250 -> V_9 . V_514 = F_274 ;
if ( V_250 -> V_9 . V_515 == NULL ) {
if ( F_43 ( ! V_250 -> V_24 ) )
return - V_61 ;
V_250 -> V_9 . V_515 = F_275 ;
}
if ( V_250 -> V_9 . V_516 == NULL ) {
if ( F_43 ( ! V_250 -> V_24 ) )
return - V_61 ;
V_250 -> V_9 . V_516 = F_276 ;
}
return 0 ;
}
int F_279 ( struct V_11 * V_12 ,
struct V_461 * V_462 ,
unsigned int V_463 ,
unsigned int V_232 ,
struct V_511 * V_512 )
{
int V_285 ;
F_2 ( & V_12 -> V_7 -> V_127 ) ;
V_285 = V_462 -> V_9 . V_515 ( V_462 , V_12 , V_463 , V_232 , V_512 ) ;
if ( V_285 >= 0 )
F_127 ( V_12 ) ;
F_4 ( & V_12 -> V_7 -> V_127 ) ;
return V_285 ;
}
void F_280 ( struct V_11 * V_12 ,
struct V_461 * V_462 ,
struct V_511 * V_512 )
{
F_2 ( & V_12 -> V_7 -> V_127 ) ;
V_462 -> V_9 . V_516 ( V_462 , V_12 , V_512 ) ;
F_4 ( & V_12 -> V_7 -> V_127 ) ;
}
static int F_281 ( struct V_6 * V_7 , unsigned int type )
{
static int V_517 [ V_518 ] [ 5 ] = {
[ V_519 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_426 ] = { 1 , - 1 } ,
[ V_425 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_520 ] = { 6 , - 1 } ,
} ;
int V_17 ;
if ( type >= V_518 ) {
F_45 ( V_79 L_84 , type ) ;
return - V_61 ;
}
for ( V_17 = 0 ; V_517 [ type ] [ V_17 ] >= 0 ; V_17 ++ ) {
#ifndef F_282
if ( V_517 [ type ] [ V_17 ] >= 8 )
break;
#endif
if ( ! F_283 ( V_517 [ type ] [ V_17 ] , V_7 -> V_349 ) )
return V_517 [ type ] [ V_17 ] ;
}
#ifdef F_282
for ( V_17 = 10 ; V_17 < 32 ; V_17 ++ ) {
if ( ! F_283 ( V_17 , V_7 -> V_349 ) )
return V_17 ;
}
#endif
F_45 ( V_79 L_85 ,
V_521 [ type ] ) ;
#ifndef F_282
F_45 ( V_79 L_86 ) ;
#endif
return - V_39 ;
}
static int F_284 ( struct V_11 * V_12 , struct V_340 * V_338 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_461 * V_250 ;
int V_463 , V_33 ;
if ( F_43 ( ! V_338 -> V_143 ) )
return - V_61 ;
for ( V_463 = 0 ; V_463 < 2 ; V_463 ++ ) {
V_250 = & V_338 -> V_463 [ V_463 ] ;
if ( V_250 -> V_469 ) {
V_33 = F_278 ( V_12 , V_250 ) ;
if ( V_33 < 0 )
return V_33 ;
}
}
return V_7 -> V_9 . V_522 ( V_7 , V_12 , V_338 ) ;
}
int F_285 ( struct V_11 * V_12 )
{
unsigned int V_338 ;
int V_33 ;
if ( ! V_12 -> V_339 ) {
if ( ! V_12 -> V_107 . V_523 )
return 0 ;
V_33 = V_12 -> V_107 . V_523 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_87
L_74 , V_12 -> V_29 , V_33 ) ;
V_33 = F_183 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30
L_75 ) ;
return V_33 ;
}
}
}
for ( V_338 = 0 ; V_338 < V_12 -> V_339 ; V_338 ++ ) {
struct V_340 * V_341 = & V_12 -> V_342 [ V_338 ] ;
int V_321 ;
if ( ! V_341 -> V_463 [ 0 ] . V_469 && ! V_341 -> V_463 [ 1 ] . V_469 )
continue;
if ( ! V_341 -> V_338 ) {
V_321 = F_281 ( V_12 -> V_7 , V_341 -> V_524 ) ;
if ( V_321 < 0 )
continue;
V_341 -> V_111 = V_321 ;
V_33 = F_284 ( V_12 , V_341 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_88
L_89 ,
V_321 , V_12 -> V_29 ) ;
continue;
}
}
}
return 0 ;
}
int F_286 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
int V_33 = F_285 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
}
return 0 ;
}
int F_287 ( struct V_11 * V_12 ,
int V_525 , const char * const * V_526 ,
const struct V_527 * V_133 )
{
if ( V_12 -> V_125 && V_526 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_525 ; V_17 ++ ) {
if ( V_526 [ V_17 ] &&
! strcmp ( V_12 -> V_125 , V_526 [ V_17 ] ) ) {
F_21 ( V_528 L_90
L_91 , V_526 [ V_17 ] ) ;
return V_17 ;
}
}
}
if ( ! V_12 -> V_7 -> V_124 || ! V_133 )
return - 1 ;
V_133 = F_288 ( V_12 -> V_7 -> V_124 , V_133 ) ;
if ( ! V_133 )
return - 1 ;
if ( V_133 -> V_297 >= 0 && V_133 -> V_297 < V_525 ) {
#ifdef F_289
char V_147 [ 10 ] ;
const char * V_529 = NULL ;
if ( V_526 )
V_529 = V_526 [ V_133 -> V_297 ] ;
if ( ! V_529 ) {
sprintf ( V_147 , L_92 , V_133 -> V_297 ) ;
V_529 = V_147 ;
}
F_112 ( V_528 L_93
L_94 ,
V_529 , V_133 -> V_530 , V_133 -> V_328 ,
( V_133 -> V_143 ? V_133 -> V_143 : L_95 ) ) ;
#endif
return V_133 -> V_297 ;
}
return - 1 ;
}
int F_290 ( struct V_11 * V_12 ,
int V_525 , const char * const * V_526 ,
const struct V_527 * V_133 )
{
const struct V_527 * V_241 ;
for ( V_241 = V_133 ; V_241 -> V_530 ; V_241 ++ ) {
unsigned int V_70 = 0xffff0000 | V_241 -> V_531 ;
unsigned int V_136 = ( V_241 -> V_328 | ( V_241 -> V_530 << 16 ) ) & V_70 ;
if ( ( V_12 -> V_213 & V_70 ) == V_136 )
break;
}
if ( ! V_241 -> V_530 )
return - 1 ;
V_133 = V_241 ;
if ( V_133 -> V_297 >= 0 && V_133 -> V_297 < V_525 ) {
#ifdef F_289
char V_147 [ 10 ] ;
const char * V_529 = NULL ;
if ( V_526 )
V_529 = V_526 [ V_133 -> V_297 ] ;
if ( ! V_529 ) {
sprintf ( V_147 , L_92 , V_133 -> V_297 ) ;
V_529 = V_147 ;
}
F_112 ( V_528 L_93
L_94 ,
V_529 , V_133 -> V_530 , V_133 -> V_328 ,
( V_133 -> V_143 ? V_133 -> V_143 : L_95 ) ) ;
#endif
return V_133 -> V_297 ;
}
return - 1 ;
}
int F_291 ( struct V_11 * V_12 ,
const struct V_421 * V_532 )
{
int V_33 ;
for (; V_532 -> V_143 ; V_532 ++ ) {
struct V_290 * V_326 ;
int V_29 = 0 , V_248 = 0 ;
if ( V_532 -> V_323 == - 1 )
continue;
for (; ; ) {
V_326 = F_203 ( V_532 , V_12 ) ;
if ( ! V_326 )
return - V_54 ;
if ( V_29 > 0 )
V_326 -> V_136 . V_111 = V_29 ;
if ( V_248 > 0 )
V_326 -> V_136 . V_264 = V_248 ;
V_33 = F_173 ( V_12 , 0 , V_326 ) ;
if ( ! V_33 )
break;
if ( ! V_29 && V_12 -> V_29 )
V_29 = V_12 -> V_29 ;
else if ( ! V_248 && ! V_532 -> V_264 ) {
V_248 = F_172 ( V_12 ,
V_532 -> V_143 , 0 ) ;
if ( V_248 <= 0 )
return V_33 ;
} else
return V_33 ;
}
}
return 0 ;
}
static void V_210 ( struct V_103 * V_102 )
{
struct V_11 * V_12 =
F_56 ( V_102 , struct V_11 , V_186 . V_102 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
unsigned int V_437 ;
F_180 ( & V_12 -> V_209 ) ;
if ( V_12 -> V_346 > 0 ) {
F_181 ( & V_12 -> V_209 ) ;
return;
}
if ( ! V_12 -> V_345 || V_12 -> V_533 ) {
V_12 -> V_346 = 0 ;
F_181 ( & V_12 -> V_209 ) ;
return;
}
F_181 ( & V_12 -> V_209 ) ;
V_437 = F_254 ( V_12 , true ) ;
if ( ! V_12 -> V_190 &&
! V_7 -> V_219 && ( V_437 & V_534 ) ) {
V_12 -> V_190 = 1 ;
F_7 ( V_7 , false ) ;
}
}
static void F_8 ( struct V_11 * V_12 )
{
F_180 ( & V_12 -> V_209 ) ;
V_12 -> V_533 ++ ;
V_12 -> V_345 = 1 ;
V_12 -> V_347 = V_348 ;
F_181 ( & V_12 -> V_209 ) ;
}
void F_255 ( struct V_11 * V_12 )
{
unsigned long V_535 = V_348 - V_12 -> V_347 ;
if ( V_12 -> V_345 )
V_12 -> V_536 += V_535 ;
else
V_12 -> V_537 += V_535 ;
V_12 -> V_347 += V_535 ;
}
static void F_292 ( struct V_11 * V_12 , bool V_538 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
if ( ( V_12 -> V_345 || V_12 -> V_346 > 0 ) &&
! ( V_538 && V_12 -> V_346 < 0 ) )
return;
F_181 ( & V_12 -> V_209 ) ;
F_102 ( & V_12 -> V_186 ) ;
F_180 ( & V_12 -> V_209 ) ;
if ( V_12 -> V_345 ) {
if ( V_12 -> V_346 < 0 )
V_12 -> V_346 = 0 ;
return;
}
F_293 ( V_12 ) ;
F_255 ( V_12 ) ;
V_12 -> V_345 = 1 ;
V_12 -> V_347 = V_348 ;
V_12 -> V_346 = 1 ;
F_181 ( & V_12 -> V_209 ) ;
if ( V_12 -> V_190 ) {
V_12 -> V_190 = 0 ;
F_7 ( V_7 , true ) ;
}
F_258 ( V_12 ) ;
F_180 ( & V_12 -> V_209 ) ;
V_12 -> V_346 = 0 ;
}
static void F_294 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_345 || V_12 -> V_533 || V_12 -> V_346 )
return;
if ( V_126 ( V_12 ) ) {
V_12 -> V_346 = - 1 ;
F_98 ( V_12 -> V_7 -> V_99 , & V_12 -> V_186 ,
F_248 ( V_126 ( V_12 ) * 1000 ) ) ;
}
}
void F_295 ( struct V_11 * V_12 , int V_535 , bool V_539 )
{
F_180 ( & V_12 -> V_209 ) ;
V_12 -> V_533 += V_535 ;
F_296 ( V_12 ) ;
if ( V_535 > 0 )
F_292 ( V_12 , V_539 ) ;
else
F_294 ( V_12 ) ;
F_181 ( & V_12 -> V_209 ) ;
}
int F_297 ( struct V_11 * V_12 ,
struct V_540 * V_541 ,
T_2 V_24 )
{
const struct V_542 * V_51 ;
int V_263 , V_543 ;
if ( ! V_541 -> V_544 )
return 0 ;
for ( V_51 = V_541 -> V_544 ; V_51 -> V_24 ; V_51 ++ ) {
if ( V_51 -> V_24 == V_24 )
break;
}
if ( ! V_51 -> V_24 )
return 0 ;
for ( V_51 = V_541 -> V_544 ; V_51 -> V_24 ; V_51 ++ ) {
for ( V_263 = 0 ; V_263 < 2 ; V_263 ++ ) {
V_543 = F_146 ( V_12 , V_51 -> V_24 , V_263 , V_51 -> V_260 ,
V_51 -> V_248 ) ;
if ( ! ( V_543 & V_279 ) && V_543 > 0 ) {
if ( ! V_541 -> V_345 ) {
V_541 -> V_345 = 1 ;
F_16 ( V_12 ) ;
}
return 1 ;
}
}
}
if ( V_541 -> V_345 ) {
V_541 -> V_345 = 0 ;
F_19 ( V_12 ) ;
}
return 0 ;
}
int F_298 ( struct V_11 * V_12 ,
struct V_292 * V_293 ,
const struct V_545 * V_546 ,
int V_547 )
{
V_293 -> type = V_373 ;
V_293 -> V_296 = 1 ;
V_293 -> V_297 . V_374 . V_333 = V_547 ;
if ( V_293 -> V_297 . V_374 . V_327 >= V_547 )
V_293 -> V_297 . V_374 . V_327 = V_547 - 1 ;
sprintf ( V_293 -> V_297 . V_374 . V_143 , L_96 ,
V_546 [ V_293 -> V_297 . V_374 . V_327 ] . V_476 ) ;
return 0 ;
}
int F_299 ( struct V_11 * V_12 ,
struct V_302 * V_303 ,
const struct V_545 * V_546 ,
int V_547 ,
int V_548 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_547 ; V_17 ++ ) {
if ( V_548 == V_546 [ V_17 ] . V_476 ) {
V_303 -> V_297 . V_374 . V_327 [ 0 ] = V_17 ;
break;
}
}
return 0 ;
}
int F_300 ( struct V_11 * V_12 ,
struct V_302 * V_303 ,
const struct V_545 * V_546 ,
int V_547 ,
int * V_549 )
{
unsigned int V_550 ;
V_550 = V_303 -> V_297 . V_374 . V_327 [ 0 ] ;
if ( V_550 >= V_547 )
return - V_61 ;
if ( * V_549 == V_546 [ V_550 ] . V_476 )
return 0 ;
* V_549 = V_546 [ V_550 ] . V_476 ;
if ( V_546 [ V_550 ] . V_551 )
F_244 ( V_12 , V_546 [ V_550 ] . V_551 ) ;
return 1 ;
}
int F_301 ( const struct V_552 * V_553 ,
struct V_292 * V_293 )
{
unsigned int V_264 ;
V_293 -> type = V_373 ;
V_293 -> V_296 = 1 ;
V_293 -> V_297 . V_374 . V_333 = V_553 -> V_554 ;
if ( ! V_553 -> V_554 )
return 0 ;
V_264 = V_293 -> V_297 . V_374 . V_327 ;
if ( V_264 >= V_553 -> V_554 )
V_264 = V_553 -> V_554 - 1 ;
strcpy ( V_293 -> V_297 . V_374 . V_143 , V_553 -> V_333 [ V_264 ] . V_555 ) ;
return 0 ;
}
int F_302 ( struct V_11 * V_12 ,
const struct V_552 * V_553 ,
struct V_302 * V_303 ,
T_2 V_24 ,
unsigned int * V_556 )
{
unsigned int V_248 ;
if ( ! V_553 -> V_554 )
return 0 ;
V_248 = V_303 -> V_297 . V_374 . V_327 [ 0 ] ;
if ( V_248 >= V_553 -> V_554 )
V_248 = V_553 -> V_554 - 1 ;
if ( * V_556 == V_248 )
return 0 ;
F_222 ( V_12 , V_24 , 0 , V_557 ,
V_553 -> V_333 [ V_248 ] . V_264 ) ;
* V_556 = V_248 ;
return 1 ;
}
int F_303 ( struct V_290 * V_291 ,
struct V_292 * V_293 ,
int V_554 , const char * const * V_372 )
{
static const char * const V_558 [] = {
L_97 , L_98
} ;
if ( ! V_372 || ! V_554 ) {
V_554 = 2 ;
V_372 = V_558 ;
}
V_293 -> type = V_373 ;
V_293 -> V_296 = 1 ;
V_293 -> V_297 . V_374 . V_333 = V_554 ;
if ( V_293 -> V_297 . V_374 . V_327 >= V_293 -> V_297 . V_374 . V_333 )
V_293 -> V_297 . V_374 . V_327 = V_293 -> V_297 . V_374 . V_333 - 1 ;
strcpy ( V_293 -> V_297 . V_374 . V_143 ,
V_372 [ V_293 -> V_297 . V_374 . V_327 ] ) ;
return 0 ;
}
static void F_304 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_226 , unsigned int V_232 )
{
struct V_205 * V_402 ;
unsigned int V_559 ;
bool V_560 ;
V_402 = F_229 ( V_12 , V_24 ) ;
V_559 = F_23 ( V_12 , V_24 , 0 ,
V_234 , 0 ) ;
V_560 = V_12 -> V_353 &&
( V_402 -> V_416 & V_417 ) &&
V_559 != V_232 ;
if ( V_560 )
F_223 ( V_12 , V_24 ,
V_402 -> V_416 & ~ V_417 & 0xff ,
- 1 ) ;
F_124 ( V_12 , V_24 , V_226 , 0 , V_232 ) ;
if ( V_12 -> V_352 ) {
const T_2 * V_411 ;
for ( V_411 = V_12 -> V_352 ; * V_411 ; V_411 ++ )
F_124 ( V_12 , * V_411 , V_226 , 0 ,
V_232 ) ;
}
if ( V_560 )
F_223 ( V_12 , V_24 ,
V_402 -> V_416 & 0xff , - 1 ) ;
}
static void F_305 ( struct V_11 * V_12 , T_2 V_24 )
{
F_277 ( V_12 , V_24 ) ;
if ( V_12 -> V_352 ) {
const T_2 * V_411 ;
for ( V_411 = V_12 -> V_352 ; * V_411 ; V_411 ++ )
F_277 ( V_12 , * V_411 ) ;
}
}
void F_306 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
if ( ! V_7 )
return;
F_29 (codec, &bus->codec_list, list) {
if ( F_307 ( V_12 ) &&
V_12 -> V_107 . V_561 )
V_12 -> V_107 . V_561 ( V_12 ) ;
}
}
int F_308 ( struct V_11 * V_12 ,
struct V_429 * V_430 )
{
F_2 ( & V_12 -> V_199 ) ;
if ( V_430 -> V_562 == V_563 )
F_305 ( V_12 , V_430 -> V_432 ) ;
V_430 -> V_562 = V_564 ;
F_4 ( & V_12 -> V_199 ) ;
return 0 ;
}
int F_309 ( struct V_11 * V_12 ,
struct V_429 * V_430 ,
unsigned int V_226 ,
unsigned int V_232 ,
struct V_511 * V_512 )
{
F_2 ( & V_12 -> V_199 ) ;
F_304 ( V_12 , V_430 -> V_432 , V_226 , V_232 ) ;
F_4 ( & V_12 -> V_199 ) ;
return 0 ;
}
int F_310 ( struct V_11 * V_12 ,
struct V_429 * V_430 )
{
F_2 ( & V_12 -> V_199 ) ;
F_305 ( V_12 , V_430 -> V_432 ) ;
F_4 ( & V_12 -> V_199 ) ;
return 0 ;
}
int F_311 ( struct V_11 * V_12 ,
struct V_429 * V_430 )
{
F_2 ( & V_12 -> V_199 ) ;
V_430 -> V_562 = 0 ;
F_4 ( & V_12 -> V_199 ) ;
return 0 ;
}
int F_312 ( struct V_11 * V_12 ,
struct V_429 * V_430 ,
struct V_511 * V_512 ,
struct V_461 * V_462 )
{
struct V_565 * V_566 = V_512 -> V_566 ;
V_566 -> V_567 . V_471 = V_430 -> V_548 ;
if ( V_430 -> V_432 ) {
if ( ! V_430 -> V_568 ) {
V_430 -> V_568 = V_462 -> V_495 ;
V_430 -> V_569 = V_462 -> V_498 ;
V_430 -> V_570 = V_462 -> V_477 ;
} else {
V_566 -> V_567 . V_495 = V_430 -> V_568 ;
V_566 -> V_567 . V_498 = V_430 -> V_569 ;
V_462 -> V_477 = V_430 -> V_570 ;
}
if ( ! V_430 -> V_571 ) {
F_272 ( V_12 , V_430 -> V_432 ,
& V_430 -> V_571 ,
& V_430 -> V_572 ,
& V_430 -> V_573 ) ;
}
F_2 ( & V_12 -> V_199 ) ;
if ( V_430 -> V_431 ) {
if ( ( V_566 -> V_567 . V_495 & V_430 -> V_571 ) &&
( V_566 -> V_567 . V_498 & V_430 -> V_572 ) ) {
V_566 -> V_567 . V_495 &= V_430 -> V_571 ;
V_566 -> V_567 . V_498 &= V_430 -> V_572 ;
if ( V_430 -> V_573 < V_462 -> V_477 )
V_462 -> V_477 = V_430 -> V_573 ;
} else {
V_430 -> V_431 = 0 ;
}
}
F_4 ( & V_12 -> V_199 ) ;
}
return F_313 ( V_512 -> V_566 , 0 ,
V_574 , 2 ) ;
}
int F_314 ( struct V_11 * V_12 ,
struct V_429 * V_430 ,
unsigned int V_226 ,
unsigned int V_232 ,
struct V_511 * V_512 )
{
const T_2 * V_188 = V_430 -> V_575 ;
int V_294 = V_512 -> V_566 -> V_476 ;
struct V_205 * V_402 ;
int V_17 ;
F_2 ( & V_12 -> V_199 ) ;
V_402 = F_229 ( V_12 , V_430 -> V_432 ) ;
if ( V_430 -> V_432 && V_430 -> V_431 &&
V_430 -> V_562 != V_564 ) {
if ( V_294 == 2 &&
F_273 ( V_12 , V_430 -> V_432 ,
V_232 ) &&
! ( V_402 -> V_394 & V_396 ) ) {
V_430 -> V_562 = V_563 ;
F_304 ( V_12 , V_430 -> V_432 ,
V_226 , V_232 ) ;
} else {
V_430 -> V_562 = 0 ;
F_305 ( V_12 , V_430 -> V_432 ) ;
}
}
F_4 ( & V_12 -> V_199 ) ;
F_124 ( V_12 , V_188 [ V_576 ] , V_226 ,
0 , V_232 ) ;
if ( ! V_430 -> V_577 &&
V_430 -> V_578 && V_430 -> V_578 != V_188 [ V_576 ] )
F_124 ( V_12 , V_430 -> V_578 , V_226 ,
0 , V_232 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_430 -> V_579 ) ; V_17 ++ )
if ( ! V_430 -> V_577 && V_430 -> V_579 [ V_17 ] )
F_124 ( V_12 ,
V_430 -> V_579 [ V_17 ] ,
V_226 , 0 , V_232 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_430 -> V_580 ) ; V_17 ++ )
if ( ! V_430 -> V_577 && V_430 -> V_580 [ V_17 ] )
F_124 ( V_12 ,
V_430 -> V_580 [ V_17 ] ,
V_226 , 0 , V_232 ) ;
for ( V_17 = 1 ; V_17 < V_430 -> V_581 ; V_17 ++ ) {
if ( V_294 >= ( V_17 + 1 ) * 2 )
F_124 ( V_12 , V_188 [ V_17 ] , V_226 ,
V_17 * 2 , V_232 ) ;
else if ( ! V_430 -> V_577 )
F_124 ( V_12 , V_188 [ V_17 ] , V_226 ,
0 , V_232 ) ;
}
return 0 ;
}
int F_315 ( struct V_11 * V_12 ,
struct V_429 * V_430 )
{
const T_2 * V_188 = V_430 -> V_575 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_430 -> V_581 ; V_17 ++ )
F_277 ( V_12 , V_188 [ V_17 ] ) ;
if ( V_430 -> V_578 )
F_277 ( V_12 , V_430 -> V_578 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_430 -> V_579 ) ; V_17 ++ )
if ( V_430 -> V_579 [ V_17 ] )
F_277 ( V_12 ,
V_430 -> V_579 [ V_17 ] ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_430 -> V_580 ) ; V_17 ++ )
if ( V_430 -> V_580 [ V_17 ] )
F_277 ( V_12 ,
V_430 -> V_580 [ V_17 ] ) ;
F_2 ( & V_12 -> V_199 ) ;
if ( V_430 -> V_432 && V_430 -> V_562 == V_563 ) {
F_305 ( V_12 , V_430 -> V_432 ) ;
V_430 -> V_562 = 0 ;
}
F_4 ( & V_12 -> V_199 ) ;
return 0 ;
}
unsigned int F_316 ( struct V_11 * V_12 , T_2 V_167 )
{
unsigned int V_582 ;
unsigned int V_228 ;
V_228 = F_23 ( V_12 , V_167 , 0 ,
V_172 , 0 ) ;
V_582 = F_140 ( V_12 , V_167 ) ;
V_582 = ( V_582 & V_583 ) >> V_584 ;
if ( ( V_582 & V_585 ) && V_228 != V_586 )
return V_587 ;
else if ( V_582 & V_588 )
return V_589 ;
else if ( V_582 & V_590 )
return V_591 ;
else if ( V_582 & V_592 )
return V_593 ;
return V_594 ;
}
unsigned int F_317 ( struct V_11 * V_12 ,
T_2 V_167 , unsigned int V_28 )
{
static unsigned int V_595 [] [ 2 ] = {
{ V_591 , V_590 } ,
{ V_587 , V_585 } ,
{ V_589 , V_588 } ,
{ V_593 , V_592 } ,
} ;
unsigned int V_596 ;
if ( ! V_28 )
return 0 ;
V_596 = F_140 ( V_12 , V_167 ) ;
if ( ! V_596 )
return V_28 ;
if ( V_28 & V_597 ) {
if ( ! ( V_596 & V_598 ) )
V_28 &= ~ ( V_597 | V_599 ) ;
else if ( ( V_28 & V_599 ) && ! ( V_596 & V_600 ) )
V_28 &= ~ V_599 ;
}
if ( V_28 & V_601 ) {
if ( ! ( V_596 & V_602 ) )
V_28 &= ~ ( V_601 | V_603 ) ;
else {
unsigned int V_604 , V_605 ;
int V_17 ;
V_604 = ( V_596 & V_583 ) >> V_584 ;
V_605 = V_28 & V_603 ;
for ( V_17 = 0 ; V_17 < F_10 ( V_595 ) ; V_17 ++ ) {
if ( V_605 == V_595 [ V_17 ] [ 0 ] &&
! ( V_604 & V_595 [ V_17 ] [ 1 ] ) ) {
if ( V_17 == F_10 ( V_595 ) - 1 )
V_605 = V_594 ;
else
V_605 = V_595 [ V_17 + 1 ] [ 0 ] ;
}
}
V_28 &= ~ V_603 ;
V_28 |= V_605 ;
}
}
return V_28 ;
}
int F_318 ( struct V_11 * V_12 , T_2 V_167 ,
unsigned int V_28 , bool V_606 )
{
V_28 = F_317 ( V_12 , V_167 , V_28 ) ;
F_91 ( V_12 , V_167 , V_28 ) ;
if ( V_606 )
return F_240 ( V_12 , V_167 , 0 ,
V_180 , V_28 ) ;
else
return F_24 ( V_12 , V_167 , 0 ,
V_180 , V_28 ) ;
}
int F_319 ( struct V_552 * V_553 , const char * V_555 ,
int V_264 , int * V_607 )
{
int V_17 , V_608 = 0 ;
if ( V_553 -> V_554 >= V_609 ) {
F_21 ( V_30 L_99 ) ;
return - V_61 ;
}
for ( V_17 = 0 ; V_17 < V_553 -> V_554 ; V_17 ++ ) {
if ( ! strncmp ( V_555 , V_553 -> V_333 [ V_17 ] . V_555 , strlen ( V_555 ) ) )
V_608 ++ ;
}
if ( V_607 )
* V_607 = V_608 ;
if ( V_608 > 0 )
snprintf ( V_553 -> V_333 [ V_553 -> V_554 ] . V_555 ,
sizeof( V_553 -> V_333 [ V_553 -> V_554 ] . V_555 ) ,
L_100 , V_555 , V_608 ) ;
else
F_320 ( V_553 -> V_333 [ V_553 -> V_554 ] . V_555 , V_555 ,
sizeof( V_553 -> V_333 [ V_553 -> V_554 ] . V_555 ) ) ;
V_553 -> V_333 [ V_553 -> V_554 ] . V_264 = V_264 ;
V_553 -> V_554 ++ ;
return 0 ;
}
int F_321 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
F_102 ( & V_12 -> V_182 ) ;
if ( F_307 ( V_12 ) )
F_254 ( V_12 , false ) ;
}
return 0 ;
}
int F_322 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
F_258 ( V_12 ) ;
}
return 0 ;
}
void * F_84 ( struct V_173 * V_174 )
{
if ( F_43 ( ! V_174 -> V_610 ) )
return NULL ;
if ( V_174 -> V_175 >= V_174 -> V_611 ) {
int V_612 = V_174 -> V_611 + V_174 -> V_613 ;
int V_307 = ( V_612 + 1 ) * V_174 -> V_610 ;
void * V_614 ;
if ( F_43 ( V_612 >= 4096 ) )
return NULL ;
V_614 = F_323 ( V_174 -> V_4 , V_307 , V_53 | V_615 ) ;
if ( ! V_614 )
return NULL ;
V_174 -> V_4 = V_614 ;
V_174 -> V_611 = V_612 ;
}
return F_86 ( V_174 , V_174 -> V_175 ++ ) ;
}
void F_100 ( struct V_173 * V_174 )
{
F_37 ( V_174 -> V_4 ) ;
V_174 -> V_175 = 0 ;
V_174 -> V_611 = 0 ;
V_174 -> V_4 = NULL ;
}
void F_324 ( int V_338 , char * V_246 , int V_616 )
{
static unsigned int V_617 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_17 , V_618 ;
for ( V_17 = 0 , V_618 = 0 ; V_17 < F_10 ( V_617 ) ; V_17 ++ )
if ( V_338 & ( V_501 << V_17 ) )
V_618 += snprintf ( V_246 + V_618 , V_616 - V_618 , L_101 , V_617 [ V_17 ] ) ;
V_246 [ V_618 ] = '\0' ;
}
