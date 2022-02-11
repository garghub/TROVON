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
F_49 ( L_39
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
int F_50 ( struct V_11 * V_12 , T_2 V_80 ,
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
if ( F_50 ( V_12 , V_82 [ V_17 ] , V_24 , V_81 ) >= 0 )
return V_17 ;
}
return - 1 ;
}
static unsigned int F_51 ( struct V_11 * V_12 , T_2 V_24 )
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
int F_52 ( struct V_11 * V_12 , T_2 V_24 ,
T_3 * V_90 , int V_91 )
{
unsigned int V_27 ;
int V_17 , V_92 , V_93 ;
V_27 = F_51 ( V_12 , V_24 ) ;
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
int F_53 ( struct V_6 * V_7 , T_1 V_32 , T_1 V_95 )
{
struct V_96 * V_97 ;
unsigned int V_98 ;
if ( ! V_7 || ! V_7 -> V_99 )
return 0 ;
F_54 ( V_7 , V_32 , V_95 ) ;
V_97 = V_7 -> V_97 ;
if ( ! V_97 )
return 0 ;
V_98 = ( V_97 -> V_98 + 1 ) % V_100 ;
V_97 -> V_98 = V_98 ;
V_98 <<= 1 ;
V_97 -> V_101 [ V_98 ] = V_32 ;
V_97 -> V_101 [ V_98 + 1 ] = V_95 ;
F_55 ( V_7 -> V_99 , & V_97 -> V_102 ) ;
return 0 ;
}
static void F_56 ( struct V_103 * V_102 )
{
struct V_96 * V_97 =
F_57 ( V_102 , struct V_96 , V_102 ) ;
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
static int F_58 ( struct V_6 * V_7 )
{
struct V_96 * V_97 ;
if ( V_7 -> V_97 )
return 0 ;
V_97 = F_59 ( sizeof( * V_97 ) , V_53 ) ;
if ( ! V_97 ) {
F_45 ( V_30 L_39
L_44 ) ;
return - V_54 ;
}
F_60 ( & V_97 -> V_102 , F_56 ) ;
V_97 -> V_7 = V_7 ;
V_7 -> V_97 = V_97 ;
return 0 ;
}
static int F_61 ( struct V_6 * V_7 )
{
struct V_11 * V_12 , * V_78 ;
if ( ! V_7 )
return 0 ;
if ( V_7 -> V_99 )
F_62 ( V_7 -> V_99 ) ;
if ( V_7 -> V_97 )
F_37 ( V_7 -> V_97 ) ;
F_63 (codec, n, &bus->codec_list, list) {
F_64 ( V_12 ) ;
}
if ( V_7 -> V_9 . V_109 )
V_7 -> V_9 . V_109 ( V_7 ) ;
if ( V_7 -> V_99 )
F_65 ( V_7 -> V_99 ) ;
F_37 ( V_7 ) ;
return 0 ;
}
static int F_66 ( struct V_110 * V_111 )
{
struct V_6 * V_7 = V_111 -> V_112 ;
V_7 -> V_113 = 1 ;
return F_61 ( V_7 ) ;
}
static int F_67 ( struct V_110 * V_111 )
{
struct V_6 * V_7 = V_111 -> V_112 ;
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
F_68 ( V_12 ) ;
F_69 ( V_12 ) ;
}
return 0 ;
}
int F_70 ( struct V_114 * V_115 ,
const struct V_116 * V_117 ,
struct V_6 * * V_118 )
{
struct V_6 * V_7 ;
int V_33 ;
static struct V_119 V_120 = {
. V_121 = F_67 ,
. V_122 = F_66 ,
} ;
if ( F_43 ( ! V_117 ) )
return - V_61 ;
if ( F_43 ( ! V_117 -> V_9 . V_38 || ! V_117 -> V_9 . V_40 ) )
return - V_61 ;
if ( V_118 )
* V_118 = NULL ;
V_7 = F_59 ( sizeof( * V_7 ) , V_53 ) ;
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
F_71 ( & V_7 -> V_35 ) ;
F_71 ( & V_7 -> V_127 ) ;
F_72 ( & V_7 -> V_128 ) ;
snprintf ( V_7 -> V_129 , sizeof( V_7 -> V_129 ) ,
L_46 , V_115 -> V_130 ) ;
V_7 -> V_99 = F_73 ( V_7 -> V_129 ) ;
if ( ! V_7 -> V_99 ) {
F_45 ( V_30 L_47 ,
V_7 -> V_129 ) ;
F_37 ( V_7 ) ;
return - V_54 ;
}
V_33 = F_74 ( V_115 , V_131 , V_7 , & V_120 ) ;
if ( V_33 < 0 ) {
F_61 ( V_7 ) ;
return V_33 ;
}
if ( V_118 )
* V_118 = V_7 ;
return 0 ;
}
static const struct V_132 *
F_75 ( struct V_11 * V_12 )
{
struct V_1 * V_133 ;
const struct V_132 * V_2 ;
unsigned int V_134 = 0 ;
if ( F_76 ( V_12 ) )
return NULL ;
V_34:
F_2 ( & V_3 ) ;
F_29 (tbl, &hda_preset_tables, list) {
if ( ! F_77 ( V_133 -> V_135 ) ) {
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
F_78 ( V_133 -> V_135 ) ;
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
F_79 ( V_143 ) ;
V_134 ++ ;
goto V_34;
}
return NULL ;
}
static int F_80 ( struct V_11 * V_12 )
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
V_12 -> V_148 = F_81 ( V_146 , V_53 ) ;
if ( ! V_12 -> V_148 )
return - V_54 ;
V_149:
if ( V_12 -> V_151 )
return 0 ;
if ( V_12 -> V_2 && V_12 -> V_2 -> V_143 )
V_12 -> V_151 = F_81 ( V_12 -> V_2 -> V_143 , V_53 ) ;
else {
sprintf ( V_147 , L_52 , V_12 -> V_139 & 0xffff ) ;
V_12 -> V_151 = F_81 ( V_147 , V_53 ) ;
}
if ( ! V_12 -> V_151 )
return - V_54 ;
return 0 ;
}
static void F_82 ( struct V_11 * V_12 )
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
static int F_83 ( struct V_11 * V_12 , T_2 V_162 )
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
static int F_84 ( struct V_11 * V_12 )
{
int V_17 ;
T_2 V_24 = V_12 -> V_164 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_163 ; V_17 ++ , V_24 ++ ) {
struct V_166 * V_167 ;
unsigned int V_63 = F_47 ( V_12 , V_24 ) ;
unsigned int V_168 = F_48 ( V_63 ) ;
if ( V_168 != V_84 )
continue;
V_167 = F_85 ( & V_12 -> V_169 ) ;
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
static struct V_166 * F_86 ( struct V_11 * V_12 ,
struct V_173 * V_174 ,
T_2 V_24 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_174 -> V_175 ; V_17 ++ ) {
struct V_166 * V_167 = F_87 ( V_174 , V_17 ) ;
if ( V_167 -> V_24 == V_24 )
return V_167 ;
}
return NULL ;
}
int F_88 ( struct V_11 * V_12 , struct V_173 * V_4 ,
T_2 V_24 , unsigned int V_13 )
{
struct V_166 * V_167 ;
V_167 = F_86 ( V_12 , V_4 , V_24 ) ;
if ( ! V_167 ) {
V_167 = F_85 ( V_4 ) ;
if ( ! V_167 )
return - V_54 ;
V_167 -> V_24 = V_24 ;
}
V_167 -> V_13 = V_13 ;
return 0 ;
}
int F_89 ( struct V_11 * V_12 ,
T_2 V_24 , unsigned int V_13 )
{
return F_88 ( V_12 , & V_12 -> V_176 , V_24 , V_13 ) ;
}
unsigned int F_90 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_166 * V_167 ;
#ifdef F_91
{
unsigned int V_13 = 0 ;
F_2 ( & V_12 -> V_177 ) ;
V_167 = F_86 ( V_12 , & V_12 -> V_178 , V_24 ) ;
if ( V_167 )
V_13 = V_167 -> V_13 ;
F_4 ( & V_12 -> V_177 ) ;
if ( V_13 )
return V_13 ;
}
#endif
V_167 = F_86 ( V_12 , & V_12 -> V_176 , V_24 ) ;
if ( V_167 )
return V_167 -> V_13 ;
V_167 = F_86 ( V_12 , & V_12 -> V_169 , V_24 ) ;
if ( V_167 )
return V_167 -> V_13 ;
return 0 ;
}
int F_92 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_28 )
{
struct V_166 * V_167 ;
V_167 = F_86 ( V_12 , & V_12 -> V_169 , V_24 ) ;
if ( ! V_167 )
return - V_61 ;
V_167 -> V_179 = V_28 ;
return 0 ;
}
int F_93 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_166 * V_167 ;
V_167 = F_86 ( V_12 , & V_12 -> V_169 , V_24 ) ;
if ( ! V_167 )
return 0 ;
return V_167 -> V_179 ;
}
void F_94 ( struct V_11 * V_12 )
{
int V_17 ;
if ( V_12 -> V_7 -> V_113 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_169 . V_175 ; V_17 ++ ) {
struct V_166 * V_167 = F_87 ( & V_12 -> V_169 , V_17 ) ;
F_23 ( V_12 , V_167 -> V_24 , 0 ,
V_180 , 0 ) ;
}
V_12 -> V_181 = 1 ;
}
static void F_95 ( struct V_11 * V_12 )
{
int V_17 ;
if ( ! V_12 -> V_181 )
return;
if ( V_12 -> V_7 -> V_113 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_169 . V_175 ; V_17 ++ ) {
struct V_166 * V_167 = F_87 ( & V_12 -> V_169 , V_17 ) ;
F_24 ( V_12 , V_167 -> V_24 , 0 ,
V_180 ,
V_167 -> V_171 ) ;
}
V_12 -> V_181 = 0 ;
}
static void F_96 ( struct V_103 * V_102 )
{
struct V_11 * V_12 =
F_57 ( V_102 , struct V_11 , V_182 . V_102 ) ;
F_97 ( V_12 ) ;
F_98 ( V_12 ) ;
if ( ! V_12 -> V_183 )
return;
F_99 ( V_12 -> V_7 -> V_99 , & V_12 -> V_182 ,
V_12 -> V_183 ) ;
}
static void F_100 ( struct V_11 * V_12 )
{
F_101 ( & V_12 -> V_176 ) ;
#ifdef F_91
F_101 ( & V_12 -> V_178 ) ;
#endif
F_101 ( & V_12 -> V_169 ) ;
}
static struct V_184 *
F_102 ( struct V_11 * V_12 , T_2 V_24 )
{
struct V_184 * V_51 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_185 . V_175 ; V_17 ++ ) {
V_51 = F_87 ( & V_12 -> V_185 , V_17 ) ;
if ( V_51 -> V_24 == V_24 )
return V_51 ;
}
V_51 = F_85 ( & V_12 -> V_185 ) ;
if ( V_51 )
V_51 -> V_24 = V_24 ;
return V_51 ;
}
static void F_64 ( struct V_11 * V_12 )
{
if ( ! V_12 )
return;
F_103 ( & V_12 -> V_182 ) ;
F_104 ( V_12 ) ;
F_100 ( V_12 ) ;
#ifdef F_105
F_106 ( & V_12 -> V_186 ) ;
F_62 ( V_12 -> V_7 -> V_99 ) ;
#endif
F_6 ( & V_12 -> V_4 ) ;
F_101 ( & V_12 -> V_187 ) ;
F_101 ( & V_12 -> V_188 ) ;
F_101 ( & V_12 -> V_185 ) ;
F_101 ( & V_12 -> V_189 ) ;
F_33 ( V_12 ) ;
V_12 -> V_7 -> V_106 [ V_12 -> V_29 ] = NULL ;
if ( V_12 -> V_107 . free )
V_12 -> V_107 . free ( V_12 ) ;
#ifdef F_105
if ( ! V_12 -> V_190 )
F_7 ( V_12 -> V_7 , false ) ;
#endif
F_78 ( V_12 -> V_135 ) ;
F_107 ( & V_12 -> V_191 ) ;
F_107 ( & V_12 -> V_192 ) ;
F_37 ( V_12 -> V_148 ) ;
F_37 ( V_12 -> V_151 ) ;
F_37 ( V_12 -> V_125 ) ;
F_37 ( V_12 -> V_63 ) ;
F_37 ( V_12 ) ;
}
int F_108 ( struct V_6 * V_7 ,
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
V_12 = F_59 ( sizeof( * V_12 ) , V_53 ) ;
if ( V_12 == NULL ) {
F_45 ( V_30 L_54 ) ;
return - V_54 ;
}
V_12 -> V_7 = V_7 ;
V_12 -> V_29 = V_193 ;
F_71 ( & V_12 -> V_199 ) ;
F_71 ( & V_12 -> V_200 ) ;
F_71 ( & V_12 -> V_201 ) ;
F_109 ( & V_12 -> V_191 , sizeof( struct V_202 ) ) ;
F_109 ( & V_12 -> V_192 , sizeof( struct V_203 ) ) ;
F_110 ( & V_12 -> V_187 , sizeof( struct V_204 ) , 32 ) ;
F_110 ( & V_12 -> V_188 , sizeof( struct V_204 ) , 32 ) ;
F_110 ( & V_12 -> V_169 , sizeof( struct V_166 ) , 16 ) ;
F_110 ( & V_12 -> V_176 , sizeof( struct V_166 ) , 16 ) ;
F_110 ( & V_12 -> V_185 , sizeof( struct V_184 ) , 8 ) ;
F_110 ( & V_12 -> V_189 , sizeof( struct V_205 ) , 16 ) ;
F_110 ( & V_12 -> V_206 , sizeof( struct V_207 ) , 16 ) ;
F_110 ( & V_12 -> V_208 , sizeof( struct V_45 * ) , 8 ) ;
F_72 ( & V_12 -> V_56 ) ;
F_111 ( & V_12 -> V_182 , F_96 ) ;
#ifdef F_105
F_112 ( & V_12 -> V_209 ) ;
F_111 ( & V_12 -> V_186 , V_210 ) ;
F_8 ( V_12 ) ;
F_7 ( V_7 , true ) ;
#endif
if ( V_12 -> V_7 -> V_125 ) {
V_12 -> V_125 = F_81 ( V_12 -> V_7 -> V_125 , V_53 ) ;
if ( ! V_12 -> V_125 ) {
F_64 ( V_12 ) ;
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
F_82 ( V_12 ) ;
if ( ! V_12 -> V_137 && ! V_12 -> V_138 ) {
F_49 ( L_55 ) ;
V_33 = - V_211 ;
goto error;
}
V_196 = V_12 -> V_137 ? V_12 -> V_137 : V_12 -> V_138 ;
V_33 = F_83 ( V_12 , V_196 ) ;
if ( V_33 < 0 ) {
F_45 ( V_30 L_56 ) ;
goto error;
}
V_33 = F_84 ( V_12 ) ;
if ( V_33 < 0 )
goto error;
if ( ! V_12 -> V_213 ) {
V_12 -> V_213 =
F_23 ( V_12 , V_196 , 0 ,
V_216 , 0 ) ;
}
#ifdef F_105
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
F_64 ( V_12 ) ;
return V_33 ;
}
int F_118 ( struct V_11 * V_12 )
{
T_2 V_196 ;
int V_33 ;
F_37 ( V_12 -> V_63 ) ;
V_196 = V_12 -> V_137 ? V_12 -> V_137 : V_12 -> V_138 ;
V_33 = F_83 ( V_12 , V_196 ) ;
if ( V_33 < 0 ) {
F_45 ( V_30 L_56 ) ;
return V_33 ;
}
F_101 ( & V_12 -> V_169 ) ;
V_33 = F_84 ( V_12 ) ;
return V_33 ;
}
int F_119 ( struct V_11 * V_12 )
{
int V_33 ;
V_12 -> V_2 = F_75 ( V_12 ) ;
if ( ! V_12 -> V_148 || ! V_12 -> V_151 ) {
V_33 = F_80 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( F_76 ( V_12 ) ) {
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
V_33 = F_58 ( V_12 -> V_7 ) ;
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
F_49 ( L_60
L_61 ,
V_24 , V_226 , V_227 , V_232 ) ;
V_51 = F_102 ( V_12 , V_24 ) ;
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
V_51 = F_87 ( & V_145 -> V_185 , V_17 ) ;
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
F_49 ( L_62 , V_24 ) ;
V_51 = F_102 ( V_12 , V_24 ) ;
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
V_51 = F_87 ( & V_145 -> V_185 , V_17 ) ;
if ( V_51 -> V_238 )
F_126 ( V_145 , V_51 ) ;
}
}
}
static void F_128 ( struct V_11 * V_12 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_185 . V_175 ; V_17 ++ ) {
struct V_184 * V_51 = F_87 ( & V_12 -> V_185 , V_17 ) ;
if ( V_51 -> V_226 )
F_126 ( V_12 , V_51 ) ;
}
}
static void F_109 ( struct V_242 * V_243 ,
unsigned int V_244 )
{
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
memset ( V_243 -> V_245 , 0xff , sizeof( V_243 -> V_245 ) ) ;
F_110 ( & V_243 -> V_246 , V_244 , 64 ) ;
}
static void F_107 ( struct V_242 * V_243 )
{
F_101 ( & V_243 -> V_246 ) ;
}
static struct V_203 * F_129 ( struct V_242 * V_243 , T_1 V_247 )
{
T_4 V_248 = V_247 % ( T_4 ) F_10 ( V_243 -> V_245 ) ;
T_4 V_249 = V_243 -> V_245 [ V_248 ] ;
struct V_203 * V_250 ;
while ( V_249 != 0xffff ) {
V_250 = F_87 ( & V_243 -> V_246 , V_249 ) ;
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
V_250 = F_85 ( & V_243 -> V_246 ) ;
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
V_286 = F_87 ( & V_12 -> V_191 . V_246 , V_17 ) ;
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
V_327 = F_85 ( & V_12 -> V_187 ) ;
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
V_327 = F_85 ( & V_12 -> V_188 ) ;
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
F_101 ( & V_12 -> V_187 ) ;
F_101 ( & V_12 -> V_188 ) ;
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
F_103 ( & V_12 -> V_182 ) ;
#ifdef F_105
F_103 ( & V_12 -> V_186 ) ;
F_62 ( V_7 -> V_99 ) ;
#endif
F_177 ( V_12 ) ;
for ( V_17 = 0 ; V_17 < V_12 -> V_339 ; V_17 ++ ) {
if ( V_12 -> V_342 [ V_17 ] . V_338 ) {
F_184 ( V_115 , V_12 -> V_342 [ V_17 ] . V_338 ) ;
F_185 ( V_12 -> V_342 [ V_17 ] . V_111 ,
V_7 -> V_345 ) ;
}
}
if ( V_12 -> V_107 . free )
V_12 -> V_107 . free ( V_12 ) ;
memset ( & V_12 -> V_107 , 0 , sizeof( V_12 -> V_107 ) ) ;
F_104 ( V_12 ) ;
V_12 -> V_346 = NULL ;
V_12 -> V_347 = NULL ;
F_107 ( & V_12 -> V_191 ) ;
F_107 ( & V_12 -> V_192 ) ;
F_109 ( & V_12 -> V_191 , sizeof( struct V_202 ) ) ;
F_109 ( & V_12 -> V_192 , sizeof( struct V_203 ) ) ;
F_101 ( & V_12 -> V_176 ) ;
F_101 ( & V_12 -> V_185 ) ;
F_101 ( & V_12 -> V_189 ) ;
F_101 ( & V_12 -> V_208 ) ;
V_12 -> V_339 = 0 ;
V_12 -> V_342 = NULL ;
V_12 -> V_2 = NULL ;
V_12 -> V_348 = NULL ;
V_12 -> V_349 = 0 ;
F_78 ( V_12 -> V_135 ) ;
V_12 -> V_135 = NULL ;
F_182 ( V_7 ) ;
return 0 ;
}
static int F_186 ( struct V_11 * V_12 , const char * const * V_350 ,
const char * V_351 , T_6 V_352 , void * V_353 )
{
struct V_204 * V_333 ;
const char * const * V_354 ;
int V_17 , V_33 ;
V_333 = V_12 -> V_187 . V_4 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_187 . V_175 ; V_17 ++ ) {
struct V_290 * V_355 = V_333 [ V_17 ] . V_326 ;
if ( ! V_355 || V_355 -> V_136 . V_323 != V_324 )
continue;
for ( V_354 = V_350 ; * V_354 ; V_354 ++ ) {
char V_356 [ sizeof( V_355 -> V_136 . V_143 ) ] ;
const char * V_143 = * V_354 ;
if ( V_351 ) {
snprintf ( V_356 , sizeof( V_356 ) , L_59 ,
V_143 , V_351 ) ;
V_143 = V_356 ;
}
if ( ! strcmp ( V_355 -> V_136 . V_143 , V_143 ) ) {
V_33 = V_352 ( V_353 , V_355 ) ;
if ( V_33 )
return V_33 ;
break;
}
}
}
return 0 ;
}
static int F_187 ( void * V_353 , struct V_290 * V_355 )
{
return 1 ;
}
static int F_188 ( struct V_290 * V_326 , int * V_357 )
{
int V_308 [ 4 ] ;
const int * V_319 = NULL ;
int V_28 = - 1 ;
if ( V_326 -> V_358 [ 0 ] . V_359 & V_360 ) {
T_7 V_361 = F_189 () ;
F_190 ( F_191 () ) ;
if ( ! V_326 -> V_319 . V_145 ( V_326 , 0 , sizeof( V_308 ) , V_308 ) )
V_319 = V_308 ;
F_190 ( V_361 ) ;
} else if ( V_326 -> V_358 [ 0 ] . V_359 & V_362 )
V_319 = V_326 -> V_319 . V_51 ;
if ( V_319 && V_319 [ 0 ] == V_317 ) {
int V_320 = V_319 [ 3 ] ;
V_320 &= ~ V_316 ;
if ( ! V_320 )
return - 1 ;
if ( * V_357 && * V_357 != V_320 ) {
F_45 ( V_30 L_65 ,
* V_357 , V_320 ) ;
return - 1 ;
}
* V_357 = V_320 ;
V_28 = - V_319 [ 2 ] / V_320 ;
}
return V_28 ;
}
static int F_192 ( struct V_290 * V_326 , int V_28 )
{
struct V_302 * V_303 ;
V_303 = F_59 ( sizeof( * V_303 ) , V_53 ) ;
if ( ! V_303 )
return - V_54 ;
V_303 -> V_297 . integer . V_297 [ 0 ] = V_28 ;
V_303 -> V_297 . integer . V_297 [ 1 ] = V_28 ;
V_326 -> V_363 ( V_326 , V_303 ) ;
F_37 ( V_303 ) ;
return 0 ;
}
static int F_193 ( void * V_353 , struct V_290 * V_364 )
{
int V_365 = F_188 ( V_364 , V_353 ) ;
if ( V_365 > 0 )
F_192 ( V_364 , V_365 ) ;
return 0 ;
}
static int F_194 ( void * V_353 , struct V_290 * V_364 )
{
return F_192 ( V_364 , 1 ) ;
}
int F_195 ( struct V_11 * V_12 , char * V_143 ,
unsigned int * V_319 , const char * const * V_350 ,
const char * V_351 , bool V_366 ,
struct V_290 * * V_367 )
{
struct V_290 * V_326 ;
int V_33 ;
if ( V_367 )
* V_367 = NULL ;
V_33 = F_186 ( V_12 , V_350 , V_351 , F_187 , NULL ) ;
if ( V_33 != 1 ) {
F_49 ( L_66 , V_143 ) ;
return 0 ;
}
V_326 = F_196 ( V_143 , V_319 ) ;
if ( ! V_326 )
return - V_54 ;
V_33 = F_173 ( V_12 , 0 , V_326 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_186 ( V_12 , V_350 , V_351 ,
( T_6 ) V_368 , V_326 ) ;
if ( V_33 < 0 )
return V_33 ;
F_192 ( V_326 , 0 ) ;
if ( V_366 ) {
int V_320 = 0 ;
F_186 ( V_12 , V_350 , V_351 ,
V_319 ? F_193 : F_194 , & V_320 ) ;
}
if ( V_367 )
* V_367 = V_326 ;
return 0 ;
}
static int F_197 ( struct V_290 * V_291 ,
struct V_292 * V_293 )
{
static const char * const V_369 [] = {
L_67 , L_68 , L_69
} ;
unsigned int V_264 ;
V_293 -> type = V_370 ;
V_293 -> V_296 = 1 ;
V_293 -> V_297 . V_371 . V_333 = 3 ;
V_264 = V_293 -> V_297 . V_371 . V_327 ;
if ( V_264 >= 3 )
V_264 = 2 ;
strcpy ( V_293 -> V_297 . V_371 . V_143 , V_369 [ V_264 ] ) ;
return 0 ;
}
static int F_198 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_372 * V_373 = F_155 ( V_291 ) ;
V_303 -> V_297 . V_371 . V_327 [ 0 ] = V_373 -> V_374 ;
return 0 ;
}
static int F_199 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_372 * V_373 = F_155 ( V_291 ) ;
unsigned int V_375 = V_373 -> V_374 ;
V_373 -> V_374 = V_303 -> V_297 . V_371 . V_327 [ 0 ] ;
if ( V_373 -> V_374 > V_376 )
V_373 -> V_374 = V_376 ;
if ( V_375 == V_373 -> V_374 )
return 0 ;
F_200 ( V_373 ) ;
return 1 ;
}
int F_201 ( struct V_11 * V_12 ,
struct V_372 * V_373 ,
bool V_377 )
{
struct V_290 * V_326 ;
if ( ! V_373 -> V_373 || ! V_373 -> V_378 )
return 0 ;
F_202 ( V_373 -> V_378 , V_373 -> V_373 , V_12 ) ;
V_373 -> V_12 = V_12 ;
V_373 -> V_374 = V_376 ;
if ( ! V_377 )
return 0 ;
V_326 = F_203 ( & V_379 , V_373 ) ;
if ( ! V_326 )
return - V_54 ;
return F_173 ( V_12 , 0 , V_326 ) ;
}
void F_200 ( struct V_372 * V_373 )
{
if ( ! V_373 -> V_373 || ! V_373 -> V_12 )
return;
if ( V_373 -> V_12 -> V_7 -> V_113 )
return;
switch ( V_373 -> V_374 ) {
case V_376 :
F_204 ( V_373 -> V_378 ) ;
break;
default:
V_373 -> V_373 ( V_373 -> V_12 , V_373 -> V_374 ) ;
break;
}
}
int F_205 ( struct V_290 * V_291 ,
struct V_292 * V_293 )
{
int V_294 = F_157 ( V_291 ) ;
V_293 -> type = V_380 ;
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
unsigned long V_381 ;
int V_33 ;
F_2 ( & V_12 -> V_200 ) ;
V_381 = V_291 -> V_331 ;
V_291 -> V_331 = V_381 & ~ V_382 ;
V_33 = F_206 ( V_291 , V_303 ) ;
V_291 -> V_331 = V_381 ;
F_4 ( & V_12 -> V_200 ) ;
return V_33 ;
}
int F_210 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
unsigned long V_381 ;
int V_17 , V_383 , V_33 = 0 , V_305 = 0 ;
F_2 ( & V_12 -> V_200 ) ;
V_381 = V_291 -> V_331 ;
V_383 = ( V_381 & V_382 ) >> V_384 ;
for ( V_17 = 0 ; V_17 < V_383 ; V_17 ++ ) {
V_291 -> V_331 = ( V_381 & ~ V_382 ) |
( V_17 << V_384 ) ;
V_33 = F_207 ( V_291 , V_303 ) ;
if ( V_33 < 0 )
break;
V_305 |= V_33 ;
}
V_291 -> V_331 = V_381 ;
F_4 ( & V_12 -> V_200 ) ;
return V_33 < 0 ? V_33 : V_305 ;
}
int F_211 ( struct V_290 * V_291 ,
struct V_292 * V_293 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
struct V_385 * V_145 ;
int V_33 ;
F_2 ( & V_12 -> V_200 ) ;
V_145 = (struct V_385 * ) V_291 -> V_331 ;
V_291 -> V_331 = * V_145 -> V_386 ;
V_33 = V_145 -> V_9 -> V_250 ( V_291 , V_293 ) ;
V_291 -> V_331 = ( long ) V_145 ;
F_4 ( & V_12 -> V_200 ) ;
return V_33 ;
}
int F_212 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
struct V_385 * V_145 ;
int V_33 ;
F_2 ( & V_12 -> V_200 ) ;
V_145 = (struct V_385 * ) V_291 -> V_331 ;
V_291 -> V_331 = * V_145 -> V_386 ;
V_33 = V_145 -> V_9 -> V_387 ( V_291 , V_303 ) ;
V_291 -> V_331 = ( long ) V_145 ;
F_4 ( & V_12 -> V_200 ) ;
return V_33 ;
}
int F_213 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
struct V_385 * V_145 ;
unsigned long * V_388 ;
int V_33 = 0 , V_305 = 0 ;
F_2 ( & V_12 -> V_200 ) ;
V_145 = (struct V_385 * ) V_291 -> V_331 ;
for ( V_388 = V_145 -> V_386 ; * V_388 ; V_388 ++ ) {
V_291 -> V_331 = * V_388 ;
V_33 = V_145 -> V_9 -> V_363 ( V_291 , V_303 ) ;
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
struct V_385 * V_145 ;
int V_33 ;
F_2 ( & V_12 -> V_200 ) ;
V_145 = (struct V_385 * ) V_291 -> V_331 ;
V_291 -> V_331 = * V_145 -> V_386 ;
V_33 = V_145 -> V_9 -> V_319 ( V_291 , V_306 , V_307 , V_319 ) ;
V_291 -> V_331 = ( long ) V_145 ;
F_4 ( & V_12 -> V_200 ) ;
return V_33 ;
}
static int F_215 ( struct V_290 * V_291 ,
struct V_292 * V_293 )
{
V_293 -> type = V_389 ;
V_293 -> V_296 = 1 ;
return 0 ;
}
static int F_216 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
V_303 -> V_297 . V_390 . V_391 [ 0 ] = V_392 |
V_393 |
V_394 |
V_395 ;
V_303 -> V_297 . V_390 . V_391 [ 1 ] = V_396 |
V_397 ;
return 0 ;
}
static int F_217 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
V_303 -> V_297 . V_390 . V_391 [ 0 ] = V_392 |
V_393 |
V_398 ;
return 0 ;
}
static int F_218 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
int V_248 = V_291 -> V_331 ;
struct V_205 * V_399 ;
F_2 ( & V_12 -> V_199 ) ;
V_399 = F_87 ( & V_12 -> V_189 , V_248 ) ;
V_303 -> V_297 . V_390 . V_391 [ 0 ] = V_399 -> V_391 & 0xff ;
V_303 -> V_297 . V_390 . V_391 [ 1 ] = ( V_399 -> V_391 >> 8 ) & 0xff ;
V_303 -> V_297 . V_390 . V_391 [ 2 ] = ( V_399 -> V_391 >> 16 ) & 0xff ;
V_303 -> V_297 . V_390 . V_391 [ 3 ] = ( V_399 -> V_391 >> 24 ) & 0xff ;
F_4 ( & V_12 -> V_199 ) ;
return 0 ;
}
static unsigned short F_219 ( unsigned int V_400 )
{
unsigned short V_28 = 0 ;
if ( V_400 & V_392 )
V_28 |= V_401 ;
if ( V_400 & V_393 )
V_28 |= V_402 ;
if ( V_400 & V_392 ) {
if ( ( V_400 & V_403 ) ==
V_398 )
V_28 |= V_404 ;
} else {
if ( ( V_400 & V_405 ) ==
V_394 )
V_28 |= V_404 ;
if ( ! ( V_400 & V_395 ) )
V_28 |= V_406 ;
if ( V_400 & ( V_397 << 8 ) )
V_28 |= V_407 ;
V_28 |= V_400 & ( V_396 << 8 ) ;
}
return V_28 ;
}
static unsigned int F_220 ( unsigned short V_28 )
{
unsigned int V_400 = 0 ;
if ( V_28 & V_402 )
V_400 |= V_393 ;
if ( V_28 & V_401 )
V_400 |= V_392 ;
if ( V_400 & V_392 ) {
if ( V_28 & V_404 )
V_400 |= V_398 ;
} else {
if ( V_28 & V_404 )
V_400 |= V_394 ;
if ( ! ( V_28 & V_406 ) )
V_400 |= V_395 ;
if ( V_28 & V_407 )
V_400 |= ( V_397 << 8 ) ;
V_400 |= V_28 & ( 0x7f << 8 ) ;
}
return V_400 ;
}
static void F_221 ( struct V_11 * V_12 , T_2 V_24 ,
int V_26 , int V_28 )
{
const T_2 * V_408 ;
F_222 ( V_12 , V_24 , 0 , V_26 , V_28 ) ;
V_408 = V_12 -> V_348 ;
if ( ! V_408 )
return;
for (; * V_408 ; V_408 ++ )
F_222 ( V_12 , * V_408 , 0 , V_26 , V_28 ) ;
}
static inline void F_223 ( struct V_11 * V_12 , T_2 V_24 ,
int V_409 , int V_410 )
{
if ( V_409 != - 1 )
F_221 ( V_12 , V_24 , V_411 , V_409 ) ;
if ( V_410 != - 1 )
F_221 ( V_12 , V_24 , V_412 , V_410 ) ;
}
static int F_224 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
int V_248 = V_291 -> V_331 ;
struct V_205 * V_399 ;
T_2 V_24 ;
unsigned short V_28 ;
int V_305 ;
F_2 ( & V_12 -> V_199 ) ;
V_399 = F_87 ( & V_12 -> V_189 , V_248 ) ;
V_24 = V_399 -> V_24 ;
V_399 -> V_391 = V_303 -> V_297 . V_390 . V_391 [ 0 ] |
( ( unsigned int ) V_303 -> V_297 . V_390 . V_391 [ 1 ] << 8 ) |
( ( unsigned int ) V_303 -> V_297 . V_390 . V_391 [ 2 ] << 16 ) |
( ( unsigned int ) V_303 -> V_297 . V_390 . V_391 [ 3 ] << 24 ) ;
V_28 = F_219 ( V_399 -> V_391 ) ;
V_28 |= V_399 -> V_413 & 1 ;
V_305 = V_399 -> V_413 != V_28 ;
V_399 -> V_413 = V_28 ;
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
struct V_205 * V_399 ;
F_2 ( & V_12 -> V_199 ) ;
V_399 = F_87 ( & V_12 -> V_189 , V_248 ) ;
V_303 -> V_297 . integer . V_297 [ 0 ] = V_399 -> V_413 & V_414 ;
F_4 ( & V_12 -> V_199 ) ;
return 0 ;
}
static inline void F_226 ( struct V_11 * V_12 , T_2 V_24 ,
int V_409 , int V_410 )
{
F_223 ( V_12 , V_24 , V_409 , V_410 ) ;
if ( ( F_47 ( V_12 , V_24 ) & V_415 ) &&
( V_409 & V_414 ) )
F_149 ( V_12 , V_24 , V_257 , 0 ,
V_279 , 0 ) ;
}
static int F_227 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
int V_248 = V_291 -> V_331 ;
struct V_205 * V_399 ;
T_2 V_24 ;
unsigned short V_28 ;
int V_305 ;
F_2 ( & V_12 -> V_199 ) ;
V_399 = F_87 ( & V_12 -> V_189 , V_248 ) ;
V_24 = V_399 -> V_24 ;
V_28 = V_399 -> V_413 & ~ V_414 ;
if ( V_303 -> V_297 . integer . V_297 [ 0 ] )
V_28 |= V_414 ;
V_305 = V_399 -> V_413 != V_28 ;
V_399 -> V_413 = V_28 ;
if ( V_305 && V_24 != ( T_4 ) - 1 )
F_226 ( V_12 , V_24 , V_28 & 0xff , - 1 ) ;
F_4 ( & V_12 -> V_199 ) ;
return V_305 ;
}
int F_228 ( struct V_11 * V_12 ,
T_2 V_416 ,
T_2 V_417 ,
int type )
{
int V_33 ;
struct V_290 * V_326 ;
struct V_418 * V_419 ;
int V_248 = 0 ;
const int V_420 = 16 ;
struct V_205 * V_399 ;
struct V_6 * V_7 = V_12 -> V_7 ;
if ( V_7 -> V_421 == V_422 &&
type == V_423 ) {
V_248 = V_420 ;
} else if ( V_7 -> V_421 == V_423 &&
type == V_422 ) {
for ( V_419 = V_424 ; V_419 -> V_143 ; V_419 ++ ) {
V_326 = F_169 ( V_12 , V_419 -> V_143 , 0 , 0 ) ;
if ( ! V_326 )
break;
V_326 -> V_136 . V_264 = V_420 ;
}
V_7 -> V_421 = V_422 ;
}
if ( ! V_7 -> V_421 )
V_7 -> V_421 = type ;
V_248 = F_172 ( V_12 , L_70 , V_248 ) ;
if ( V_248 < 0 ) {
F_14 ( V_30 L_71 ) ;
return - V_198 ;
}
V_399 = F_85 ( & V_12 -> V_189 ) ;
if ( ! V_399 )
return - V_54 ;
for ( V_419 = V_424 ; V_419 -> V_143 ; V_419 ++ ) {
V_326 = F_203 ( V_419 , V_12 ) ;
if ( ! V_326 )
return - V_54 ;
V_326 -> V_136 . V_264 = V_248 ;
V_326 -> V_331 = V_12 -> V_189 . V_175 - 1 ;
V_33 = F_173 ( V_12 , V_416 , V_326 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_399 -> V_24 = V_417 ;
V_399 -> V_413 = F_23 ( V_12 , V_417 , 0 ,
V_425 , 0 ) ;
V_399 -> V_391 = F_220 ( V_399 -> V_413 ) ;
return 0 ;
}
struct V_205 * F_229 ( struct V_11 * V_12 ,
T_2 V_24 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_189 . V_175 ; V_17 ++ ) {
struct V_205 * V_399 =
F_87 ( & V_12 -> V_189 , V_17 ) ;
if ( V_399 -> V_24 == V_24 )
return V_399 ;
}
return NULL ;
}
void F_230 ( struct V_11 * V_12 , int V_248 )
{
struct V_205 * V_399 ;
F_2 ( & V_12 -> V_199 ) ;
V_399 = F_87 ( & V_12 -> V_189 , V_248 ) ;
V_399 -> V_24 = ( T_4 ) - 1 ;
F_4 ( & V_12 -> V_199 ) ;
}
void F_231 ( struct V_11 * V_12 , int V_248 , T_2 V_24 )
{
struct V_205 * V_399 ;
unsigned short V_28 ;
F_2 ( & V_12 -> V_199 ) ;
V_399 = F_87 ( & V_12 -> V_189 , V_248 ) ;
if ( V_399 -> V_24 != V_24 ) {
V_399 -> V_24 = V_24 ;
V_28 = V_399 -> V_413 ;
F_226 ( V_12 , V_24 , V_28 & 0xff , ( V_28 >> 8 ) & 0xff ) ;
}
F_4 ( & V_12 -> V_199 ) ;
}
static int F_232 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_426 * V_427 = F_155 ( V_291 ) ;
V_303 -> V_297 . integer . V_297 [ 0 ] = V_427 -> V_428 ;
return 0 ;
}
static int F_233 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_426 * V_427 = F_155 ( V_291 ) ;
V_427 -> V_428 = ! ! V_303 -> V_297 . integer . V_297 [ 0 ] ;
return 0 ;
}
int F_234 ( struct V_11 * V_12 ,
struct V_426 * V_427 )
{
struct V_290 * V_326 ;
if ( ! V_427 -> V_429 )
return 0 ;
V_326 = F_203 ( & V_430 , V_427 ) ;
if ( ! V_326 )
return - V_54 ;
return F_173 ( V_12 , V_427 -> V_429 , V_326 ) ;
}
static int F_235 ( struct V_290 * V_291 ,
struct V_302 * V_303 )
{
struct V_11 * V_12 = F_155 ( V_291 ) ;
V_303 -> V_297 . integer . V_297 [ 0 ] = V_12 -> V_431 ;
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
V_305 = V_12 -> V_431 != V_28 ;
if ( V_305 ) {
V_12 -> V_431 = V_28 ;
F_222 ( V_12 , V_24 , 0 ,
V_411 , V_28 ) ;
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
unsigned int V_400 ;
V_28 = F_23 ( V_12 , V_24 , 0 , V_425 , 0 ) ;
V_400 = F_220 ( V_28 ) ;
V_303 -> V_297 . V_390 . V_391 [ 0 ] = V_400 ;
V_303 -> V_297 . V_390 . V_391 [ 1 ] = V_400 >> 8 ;
V_303 -> V_297 . V_390 . V_391 [ 2 ] = V_400 >> 16 ;
V_303 -> V_297 . V_390 . V_391 [ 3 ] = V_400 >> 24 ;
return 0 ;
}
int F_238 ( struct V_11 * V_12 , T_2 V_24 )
{
int V_33 ;
struct V_290 * V_326 ;
struct V_418 * V_419 ;
int V_248 ;
V_248 = F_172 ( V_12 , L_72 , 0 ) ;
if ( V_248 < 0 ) {
F_14 ( V_30 L_73 ) ;
return - V_198 ;
}
for ( V_419 = V_432 ; V_419 -> V_143 ; V_419 ++ ) {
V_326 = F_203 ( V_419 , V_12 ) ;
if ( ! V_326 )
return - V_54 ;
V_326 -> V_331 = V_24 ;
V_33 = F_173 ( V_12 , V_24 , V_326 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_12 -> V_431 =
F_23 ( V_12 , V_24 , 0 ,
V_425 , 0 ) &
V_414 ;
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
V_286 = F_87 ( & V_12 -> V_192 . V_246 , V_17 ) ;
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
unsigned int V_433 )
{
T_2 V_24 = V_12 -> V_164 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_163 ; V_17 ++ , V_24 ++ ) {
unsigned int V_63 = F_47 ( V_12 , V_24 ) ;
unsigned int V_434 = V_433 ;
if ( ! ( V_63 & V_435 ) )
continue;
if ( V_12 -> V_436 ) {
V_434 = V_12 -> V_436 ( V_12 , V_24 , V_433 ) ;
if ( V_434 != V_433 && V_433 == V_437 )
continue;
}
F_24 ( V_12 , V_24 , 0 , V_438 ,
V_434 ) ;
}
}
static bool F_113 ( struct V_11 * V_12 , T_2 V_196 ,
unsigned int V_433 )
{
int V_439 = F_27 ( V_12 , V_196 , V_440 ) ;
if ( V_439 == - 1 )
return false ;
if ( V_439 & V_433 )
return true ;
else
return false ;
}
static unsigned int F_247 ( struct V_11 * V_12 ,
T_2 V_196 ,
unsigned int V_433 )
{
unsigned long V_441 = V_442 + F_248 ( 500 ) ;
unsigned int V_434 , V_443 ;
for (; ; ) {
V_434 = F_23 ( V_12 , V_196 , 0 ,
V_444 , 0 ) ;
if ( V_434 & V_445 )
break;
V_443 = ( V_434 >> 4 ) & 0x0f ;
if ( V_443 == V_433 )
break;
if ( F_249 ( V_442 , V_441 ) )
break;
F_123 ( 1 ) ;
}
return V_434 ;
}
unsigned int F_250 ( struct V_11 * V_12 ,
T_2 V_24 ,
unsigned int V_433 )
{
if ( V_433 == V_437 &&
F_48 ( F_47 ( V_12 , V_24 ) ) == V_84 &&
( F_140 ( V_12 , V_24 ) & V_446 ) ) {
int V_447 = F_23 ( V_12 , V_24 , 0 ,
V_448 , 0 ) ;
if ( V_447 & 0x02 )
return V_222 ;
}
return V_433 ;
}
static unsigned int F_114 ( struct V_11 * V_12 ,
unsigned int V_433 )
{
T_2 V_196 = V_12 -> V_137 ? V_12 -> V_137 : V_12 -> V_138 ;
int V_296 ;
unsigned int V_434 ;
int V_25 = 0 ;
if ( V_433 == V_437 ) {
F_123 ( V_12 -> V_220 ? 10 : 100 ) ;
V_25 = V_36 ;
}
for ( V_296 = 0 ; V_296 < 10 ; V_296 ++ ) {
if ( V_12 -> V_107 . V_449 )
V_12 -> V_107 . V_449 ( V_12 , V_196 ,
V_433 ) ;
else {
F_23 ( V_12 , V_196 , V_25 ,
V_438 ,
V_433 ) ;
F_246 ( V_12 , V_196 , V_433 ) ;
}
V_434 = F_247 ( V_12 , V_196 , V_433 ) ;
if ( ! ( V_434 & V_445 ) )
break;
}
return V_434 ;
}
static void F_251 ( struct V_11 * V_12 )
{
T_2 V_24 = V_12 -> V_164 ;
int V_17 ;
if ( ! V_12 -> V_436 )
return;
for ( V_17 = 0 ; V_17 < V_12 -> V_163 ; V_17 ++ , V_24 ++ ) {
unsigned int V_63 = F_47 ( V_12 , V_24 ) ;
unsigned int V_179 ;
if ( ! ( V_63 & V_435 ) )
continue;
V_179 = V_12 -> V_436 ( V_12 , V_24 , V_222 ) ;
if ( V_179 == V_222 )
continue;
if ( ! F_252 ( V_12 , V_24 , V_179 ) )
F_24 ( V_12 , V_24 , 0 ,
V_438 , V_179 ) ;
}
}
static void F_253 ( struct V_11 * V_12 )
{
if ( V_12 -> V_450 . V_4 )
F_25 ( V_12 , V_12 -> V_450 . V_4 ) ;
}
static inline void F_253 ( struct V_11 * V_12 ) {}
static unsigned int F_254 ( struct V_11 * V_12 , bool V_451 )
{
unsigned int V_434 ;
V_12 -> V_452 = 1 ;
if ( V_12 -> V_107 . V_453 )
V_12 -> V_107 . V_453 ( V_12 ) ;
F_128 ( V_12 ) ;
V_434 = F_114 ( V_12 , V_437 ) ;
if ( ! V_451 )
F_103 ( & V_12 -> V_186 ) ;
F_180 ( & V_12 -> V_209 ) ;
F_255 ( V_12 ) ;
F_256 ( V_12 ) ;
V_12 -> V_454 = 0 ;
V_12 -> V_455 = 0 ;
V_12 -> V_456 = V_442 ;
F_181 ( & V_12 -> V_209 ) ;
V_12 -> V_452 = 0 ;
return V_434 ;
}
static void F_257 ( struct V_11 * V_12 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_192 . V_246 . V_175 ; V_17 ++ ) {
struct V_203 * V_31 ;
V_31 = F_87 ( & V_12 -> V_192 . V_246 , V_17 ) ;
V_31 -> V_238 = 1 ;
}
for ( V_17 = 0 ; V_17 < V_12 -> V_191 . V_246 . V_175 ; V_17 ++ ) {
struct V_202 * V_457 ;
V_457 = F_87 ( & V_12 -> V_191 . V_246 , V_17 ) ;
V_457 -> V_253 . V_238 = 1 ;
}
}
static void F_258 ( struct V_11 * V_12 )
{
V_12 -> V_452 = 1 ;
F_257 ( V_12 ) ;
F_8 ( V_12 ) ;
if ( V_12 -> V_190 ) {
V_12 -> V_190 = 0 ;
F_7 ( V_12 -> V_7 , true ) ;
}
F_114 ( V_12 , V_222 ) ;
F_95 ( V_12 ) ;
F_253 ( V_12 ) ;
F_97 ( V_12 ) ;
if ( V_12 -> V_107 . V_458 )
V_12 -> V_107 . V_458 ( V_12 ) ;
else {
if ( V_12 -> V_107 . V_459 )
V_12 -> V_107 . V_459 ( V_12 ) ;
F_152 ( V_12 ) ;
F_241 ( V_12 ) ;
}
if ( V_12 -> V_183 )
F_96 ( & V_12 -> V_182 . V_102 ) ;
else
F_259 ( V_12 ) ;
V_12 -> V_452 = 0 ;
F_19 ( V_12 ) ;
}
int F_260 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
int V_33 = F_261 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_74
L_75 , V_12 -> V_29 , V_33 ) ;
V_33 = F_183 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30
L_76 ) ;
return V_33 ;
}
}
}
return 0 ;
}
static int F_262 ( struct V_11 * V_12 )
{
int V_17 , V_460 , V_33 ;
for ( V_17 = 0 ; V_17 < V_12 -> V_339 ; V_17 ++ ) {
for ( V_460 = 0 ; V_460 < 2 ; V_460 ++ ) {
struct V_461 * V_338 = V_12 -> V_342 [ V_17 ] . V_338 ;
struct V_462 * V_463 =
& V_12 -> V_342 [ V_17 ] . V_464 [ V_460 ] ;
struct V_465 * V_466 ;
const struct V_467 * V_468 ;
if ( V_12 -> V_342 [ V_17 ] . V_469 )
continue;
if ( ! V_338 || ! V_463 -> V_470 )
continue;
V_468 = V_463 -> V_466 ? V_463 -> V_466 : V_471 ;
V_33 = F_263 ( V_338 , V_460 , V_468 ,
V_463 -> V_472 ,
0 , & V_466 ) ;
if ( V_33 < 0 )
return V_33 ;
V_466 -> V_473 = V_474 ;
}
}
return 0 ;
}
int F_261 ( struct V_11 * V_12 )
{
int V_33 = 0 ;
F_253 ( V_12 ) ;
if ( V_12 -> V_107 . V_459 )
V_33 = V_12 -> V_107 . V_459 ( V_12 ) ;
if ( ! V_33 && V_12 -> V_107 . V_475 )
V_33 = V_12 -> V_107 . V_475 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_262 ( V_12 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_12 -> V_183 )
F_96 ( & V_12 -> V_182 . V_102 ) ;
else
F_259 ( V_12 ) ;
F_251 ( V_12 ) ;
return 0 ;
}
unsigned int F_264 ( unsigned int V_476 ,
unsigned int V_477 ,
unsigned int V_232 ,
unsigned int V_478 ,
unsigned short V_479 )
{
int V_17 ;
unsigned int V_28 = 0 ;
for ( V_17 = 0 ; V_480 [ V_17 ] . V_481 ; V_17 ++ )
if ( V_480 [ V_17 ] . V_481 == V_476 ) {
V_28 = V_480 [ V_17 ] . V_482 ;
break;
}
if ( ! V_480 [ V_17 ] . V_481 ) {
F_49 ( L_77 , V_476 ) ;
return 0 ;
}
if ( V_477 == 0 || V_477 > 8 ) {
F_49 ( L_78 , V_477 ) ;
return 0 ;
}
V_28 |= V_477 - 1 ;
switch ( F_265 ( V_232 ) ) {
case 8 :
V_28 |= V_483 ;
break;
case 16 :
V_28 |= V_484 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_478 >= 32 || V_232 == V_485 )
V_28 |= V_486 ;
else if ( V_478 >= 24 )
V_28 |= V_487 ;
else
V_28 |= V_488 ;
break;
default:
F_49 ( L_79 ,
F_265 ( V_232 ) ) ;
return 0 ;
}
if ( V_479 & V_402 )
V_28 |= V_489 ;
return V_28 ;
}
static unsigned int F_266 ( struct V_11 * V_12 , T_2 V_24 ,
int V_260 )
{
unsigned int V_28 = 0 ;
if ( V_24 != V_12 -> V_137 &&
( F_47 ( V_12 , V_24 ) & V_490 ) )
V_28 = F_27 ( V_12 , V_24 , V_491 ) ;
if ( ! V_28 || V_28 == - 1 )
V_28 = F_27 ( V_12 , V_12 -> V_137 , V_491 ) ;
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
unsigned int V_343 = F_27 ( V_12 , V_24 , V_492 ) ;
if ( ! V_343 || V_343 == - 1 )
V_343 = F_27 ( V_12 , V_12 -> V_137 , V_492 ) ;
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
T_1 * V_493 , T_8 * V_494 , unsigned int * V_495 )
{
unsigned int V_17 , V_28 , V_63 ;
V_63 = F_47 ( V_12 , V_24 ) ;
V_28 = F_267 ( V_12 , V_24 ) ;
if ( V_493 ) {
T_1 V_496 = 0 ;
for ( V_17 = 0 ; V_17 < V_497 ; V_17 ++ ) {
if ( V_28 & ( 1 << V_17 ) )
V_496 |= V_480 [ V_17 ] . V_498 ;
}
if ( V_496 == 0 ) {
F_45 ( V_30 L_80
L_81 ,
V_24 , V_28 ,
( V_63 & V_490 ) ? 1 : 0 ) ;
return - V_76 ;
}
* V_493 = V_496 ;
}
if ( V_494 || V_495 ) {
T_8 V_499 = 0 ;
unsigned int V_343 , V_500 ;
V_343 = F_270 ( V_12 , V_24 ) ;
if ( ! V_343 )
return - V_76 ;
V_500 = 0 ;
if ( V_343 & V_501 ) {
if ( V_28 & V_502 ) {
V_499 |= V_503 ;
V_500 = 8 ;
}
if ( V_28 & V_504 ) {
V_499 |= V_505 ;
V_500 = 16 ;
}
if ( V_63 & V_87 ) {
if ( V_28 & V_506 )
V_499 |= V_507 ;
if ( V_28 & ( V_508 | V_509 ) )
V_499 |= V_510 ;
if ( V_28 & V_509 )
V_500 = 24 ;
else if ( V_28 & V_508 )
V_500 = 20 ;
} else if ( V_28 & ( V_508 | V_509 |
V_506 ) ) {
V_499 |= V_510 ;
if ( V_28 & V_506 )
V_500 = 32 ;
else if ( V_28 & V_509 )
V_500 = 24 ;
else if ( V_28 & V_508 )
V_500 = 20 ;
}
}
#if 0
if (streams & AC_SUPFMT_FLOAT32) {
formats |= SNDRV_PCM_FMTBIT_FLOAT_LE;
if (!bps)
bps = 32;
}
#endif
if ( V_343 == V_511 ) {
V_499 |= V_503 ;
V_500 = 8 ;
}
if ( V_499 == 0 ) {
F_45 ( V_30 L_82
L_83
L_84 ,
V_24 , V_28 ,
( V_63 & V_490 ) ? 1 : 0 ,
V_343 ) ;
return - V_76 ;
}
if ( V_494 )
* V_494 = V_499 ;
if ( V_495 )
* V_495 = V_500 ;
}
return 0 ;
}
int F_273 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_232 )
{
int V_17 ;
unsigned int V_28 = 0 , V_476 , V_464 ;
V_28 = F_267 ( V_12 , V_24 ) ;
if ( ! V_28 )
return 0 ;
V_476 = V_232 & 0xff00 ;
for ( V_17 = 0 ; V_17 < V_497 ; V_17 ++ )
if ( V_480 [ V_17 ] . V_482 == V_476 ) {
if ( V_28 & ( 1 << V_17 ) )
break;
return 0 ;
}
if ( V_17 >= V_497 )
return 0 ;
V_464 = F_270 ( V_12 , V_24 ) ;
if ( ! V_464 )
return 0 ;
if ( V_464 & V_501 ) {
switch ( V_232 & 0xf0 ) {
case 0x00 :
if ( ! ( V_28 & V_502 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_28 & V_504 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_28 & V_508 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_28 & V_509 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_28 & V_506 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_274 ( struct V_462 * V_463 ,
struct V_11 * V_12 ,
struct V_512 * V_513 )
{
return 0 ;
}
static int F_275 ( struct V_462 * V_463 ,
struct V_11 * V_12 ,
unsigned int V_226 ,
unsigned int V_232 ,
struct V_512 * V_513 )
{
F_124 ( V_12 , V_463 -> V_24 , V_226 , 0 , V_232 ) ;
return 0 ;
}
static int F_276 ( struct V_462 * V_463 ,
struct V_11 * V_12 ,
struct V_512 * V_513 )
{
F_277 ( V_12 , V_463 -> V_24 ) ;
return 0 ;
}
static int F_278 ( struct V_11 * V_12 ,
struct V_462 * V_250 )
{
int V_33 ;
if ( V_250 -> V_24 && ( ! V_250 -> V_496 || ! V_250 -> V_499 ) ) {
V_33 = F_272 ( V_12 , V_250 -> V_24 ,
V_250 -> V_496 ? NULL : & V_250 -> V_496 ,
V_250 -> V_499 ? NULL : & V_250 -> V_499 ,
V_250 -> V_478 ? NULL : & V_250 -> V_478 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_250 -> V_9 . V_514 == NULL )
V_250 -> V_9 . V_514 = F_274 ;
if ( V_250 -> V_9 . V_515 == NULL )
V_250 -> V_9 . V_515 = F_274 ;
if ( V_250 -> V_9 . V_516 == NULL ) {
if ( F_43 ( ! V_250 -> V_24 ) )
return - V_61 ;
V_250 -> V_9 . V_516 = F_275 ;
}
if ( V_250 -> V_9 . V_517 == NULL ) {
if ( F_43 ( ! V_250 -> V_24 ) )
return - V_61 ;
V_250 -> V_9 . V_517 = F_276 ;
}
return 0 ;
}
int F_279 ( struct V_11 * V_12 ,
struct V_462 * V_463 ,
unsigned int V_464 ,
unsigned int V_232 ,
struct V_512 * V_513 )
{
int V_285 ;
F_2 ( & V_12 -> V_7 -> V_127 ) ;
V_285 = V_463 -> V_9 . V_516 ( V_463 , V_12 , V_464 , V_232 , V_513 ) ;
if ( V_285 >= 0 )
F_127 ( V_12 ) ;
F_4 ( & V_12 -> V_7 -> V_127 ) ;
return V_285 ;
}
void F_280 ( struct V_11 * V_12 ,
struct V_462 * V_463 ,
struct V_512 * V_513 )
{
F_2 ( & V_12 -> V_7 -> V_127 ) ;
V_463 -> V_9 . V_517 ( V_463 , V_12 , V_513 ) ;
F_4 ( & V_12 -> V_7 -> V_127 ) ;
}
static int F_281 ( struct V_6 * V_7 , unsigned int type )
{
static int V_518 [ V_519 ] [ 5 ] = {
[ V_520 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_423 ] = { 1 , - 1 } ,
[ V_422 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_521 ] = { 6 , - 1 } ,
} ;
int V_17 ;
if ( type >= V_519 ) {
F_45 ( V_79 L_85 , type ) ;
return - V_61 ;
}
for ( V_17 = 0 ; V_518 [ type ] [ V_17 ] >= 0 ; V_17 ++ ) {
#ifndef F_282
if ( V_518 [ type ] [ V_17 ] >= 8 )
break;
#endif
if ( ! F_283 ( V_518 [ type ] [ V_17 ] , V_7 -> V_345 ) )
return V_518 [ type ] [ V_17 ] ;
}
#ifdef F_282
for ( V_17 = 10 ; V_17 < 32 ; V_17 ++ ) {
if ( ! F_283 ( V_17 , V_7 -> V_345 ) )
return V_17 ;
}
#endif
F_45 ( V_79 L_86 ,
V_522 [ type ] ) ;
#ifndef F_282
F_45 ( V_79 L_87 ) ;
#endif
return - V_39 ;
}
static int F_284 ( struct V_11 * V_12 , struct V_340 * V_338 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_462 * V_250 ;
int V_464 , V_33 ;
if ( F_43 ( ! V_338 -> V_143 ) )
return - V_61 ;
for ( V_464 = 0 ; V_464 < 2 ; V_464 ++ ) {
V_250 = & V_338 -> V_464 [ V_464 ] ;
if ( V_250 -> V_470 ) {
V_33 = F_278 ( V_12 , V_250 ) ;
if ( V_33 < 0 )
return V_33 ;
}
}
return V_7 -> V_9 . V_523 ( V_7 , V_12 , V_338 ) ;
}
int F_285 ( struct V_11 * V_12 )
{
unsigned int V_338 ;
int V_33 ;
if ( ! V_12 -> V_339 ) {
if ( ! V_12 -> V_107 . V_524 )
return 0 ;
V_33 = V_12 -> V_107 . V_524 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_88
L_75 , V_12 -> V_29 , V_33 ) ;
V_33 = F_183 ( V_12 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30
L_76 ) ;
return V_33 ;
}
}
}
for ( V_338 = 0 ; V_338 < V_12 -> V_339 ; V_338 ++ ) {
struct V_340 * V_341 = & V_12 -> V_342 [ V_338 ] ;
int V_321 ;
if ( ! V_341 -> V_464 [ 0 ] . V_470 && ! V_341 -> V_464 [ 1 ] . V_470 )
continue;
if ( ! V_341 -> V_338 ) {
V_321 = F_281 ( V_12 -> V_7 , V_341 -> V_525 ) ;
if ( V_321 < 0 )
continue;
V_341 -> V_111 = V_321 ;
V_33 = F_284 ( V_12 , V_341 ) ;
if ( V_33 < 0 ) {
F_14 ( V_30 L_89
L_90 ,
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
int V_526 , const char * const * V_527 ,
const struct V_528 * V_133 )
{
if ( V_12 -> V_125 && V_527 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_526 ; V_17 ++ ) {
if ( V_527 [ V_17 ] &&
! strcmp ( V_12 -> V_125 , V_527 [ V_17 ] ) ) {
F_21 ( V_529 L_91
L_92 , V_527 [ V_17 ] ) ;
return V_17 ;
}
}
}
if ( ! V_12 -> V_7 -> V_124 || ! V_133 )
return - 1 ;
V_133 = F_288 ( V_12 -> V_7 -> V_124 , V_133 ) ;
if ( ! V_133 )
return - 1 ;
if ( V_133 -> V_297 >= 0 && V_133 -> V_297 < V_526 ) {
#ifdef F_289
char V_147 [ 10 ] ;
const char * V_530 = NULL ;
if ( V_527 )
V_530 = V_527 [ V_133 -> V_297 ] ;
if ( ! V_530 ) {
sprintf ( V_147 , L_93 , V_133 -> V_297 ) ;
V_530 = V_147 ;
}
F_49 ( V_529 L_94
L_95 ,
V_530 , V_133 -> V_531 , V_133 -> V_328 ,
( V_133 -> V_143 ? V_133 -> V_143 : L_96 ) ) ;
#endif
return V_133 -> V_297 ;
}
return - 1 ;
}
int F_290 ( struct V_11 * V_12 ,
int V_526 , const char * const * V_527 ,
const struct V_528 * V_133 )
{
const struct V_528 * V_241 ;
for ( V_241 = V_133 ; V_241 -> V_531 ; V_241 ++ ) {
unsigned int V_70 = 0xffff0000 | V_241 -> V_532 ;
unsigned int V_136 = ( V_241 -> V_328 | ( V_241 -> V_531 << 16 ) ) & V_70 ;
if ( ( V_12 -> V_213 & V_70 ) == V_136 )
break;
}
if ( ! V_241 -> V_531 )
return - 1 ;
V_133 = V_241 ;
if ( V_133 -> V_297 >= 0 && V_133 -> V_297 < V_526 ) {
#ifdef F_289
char V_147 [ 10 ] ;
const char * V_530 = NULL ;
if ( V_527 )
V_530 = V_527 [ V_133 -> V_297 ] ;
if ( ! V_530 ) {
sprintf ( V_147 , L_93 , V_133 -> V_297 ) ;
V_530 = V_147 ;
}
F_49 ( V_529 L_94
L_95 ,
V_530 , V_133 -> V_531 , V_133 -> V_328 ,
( V_133 -> V_143 ? V_133 -> V_143 : L_96 ) ) ;
#endif
return V_133 -> V_297 ;
}
return - 1 ;
}
int F_291 ( struct V_11 * V_12 ,
const struct V_418 * V_533 )
{
int V_33 ;
for (; V_533 -> V_143 ; V_533 ++ ) {
struct V_290 * V_326 ;
int V_29 = 0 , V_248 = 0 ;
if ( V_533 -> V_323 == - 1 )
continue;
for (; ; ) {
V_326 = F_203 ( V_533 , V_12 ) ;
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
else if ( ! V_248 && ! V_533 -> V_264 ) {
V_248 = F_172 ( V_12 ,
V_533 -> V_143 , 0 ) ;
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
F_57 ( V_102 , struct V_11 , V_186 . V_102 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
unsigned int V_434 ;
F_180 ( & V_12 -> V_209 ) ;
if ( V_12 -> V_455 > 0 ) {
F_181 ( & V_12 -> V_209 ) ;
return;
}
if ( ! V_12 -> V_454 || V_12 -> V_534 ) {
V_12 -> V_455 = 0 ;
F_181 ( & V_12 -> V_209 ) ;
return;
}
F_181 ( & V_12 -> V_209 ) ;
V_434 = F_254 ( V_12 , true ) ;
if ( ! V_12 -> V_190 &&
! V_7 -> V_219 && ( V_434 & V_535 ) ) {
V_12 -> V_190 = 1 ;
F_7 ( V_7 , false ) ;
}
}
static void F_8 ( struct V_11 * V_12 )
{
F_180 ( & V_12 -> V_209 ) ;
V_12 -> V_534 ++ ;
V_12 -> V_454 = 1 ;
V_12 -> V_456 = V_442 ;
F_181 ( & V_12 -> V_209 ) ;
}
void F_255 ( struct V_11 * V_12 )
{
unsigned long V_536 = V_442 - V_12 -> V_456 ;
if ( V_12 -> V_454 )
V_12 -> V_537 += V_536 ;
else
V_12 -> V_538 += V_536 ;
V_12 -> V_456 += V_536 ;
}
static void F_292 ( struct V_11 * V_12 , bool V_539 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
if ( ( V_12 -> V_454 || V_12 -> V_455 > 0 ) &&
! ( V_539 && V_12 -> V_455 < 0 ) )
return;
F_181 ( & V_12 -> V_209 ) ;
F_103 ( & V_12 -> V_186 ) ;
F_180 ( & V_12 -> V_209 ) ;
if ( V_12 -> V_454 ) {
if ( V_12 -> V_455 < 0 )
V_12 -> V_455 = 0 ;
return;
}
F_293 ( V_12 ) ;
F_255 ( V_12 ) ;
V_12 -> V_454 = 1 ;
V_12 -> V_456 = V_442 ;
V_12 -> V_455 = 1 ;
F_181 ( & V_12 -> V_209 ) ;
if ( V_12 -> V_190 ) {
V_12 -> V_190 = 0 ;
F_7 ( V_7 , true ) ;
}
F_258 ( V_12 ) ;
F_180 ( & V_12 -> V_209 ) ;
V_12 -> V_455 = 0 ;
}
static void F_294 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_454 || V_12 -> V_534 || V_12 -> V_455 )
return;
if ( V_126 ( V_12 ) ) {
V_12 -> V_455 = - 1 ;
F_99 ( V_12 -> V_7 -> V_99 , & V_12 -> V_186 ,
F_248 ( V_126 ( V_12 ) * 1000 ) ) ;
}
}
void F_295 ( struct V_11 * V_12 , int V_536 , bool V_540 )
{
F_180 ( & V_12 -> V_209 ) ;
V_12 -> V_534 += V_536 ;
F_296 ( V_12 ) ;
if ( V_536 > 0 )
F_292 ( V_12 , V_540 ) ;
else
F_294 ( V_12 ) ;
F_181 ( & V_12 -> V_209 ) ;
}
int F_297 ( struct V_11 * V_12 ,
struct V_541 * V_542 ,
T_2 V_24 )
{
const struct V_543 * V_51 ;
int V_263 , V_544 ;
if ( ! V_542 -> V_545 )
return 0 ;
for ( V_51 = V_542 -> V_545 ; V_51 -> V_24 ; V_51 ++ ) {
if ( V_51 -> V_24 == V_24 )
break;
}
if ( ! V_51 -> V_24 )
return 0 ;
for ( V_51 = V_542 -> V_545 ; V_51 -> V_24 ; V_51 ++ ) {
for ( V_263 = 0 ; V_263 < 2 ; V_263 ++ ) {
V_544 = F_146 ( V_12 , V_51 -> V_24 , V_263 , V_51 -> V_260 ,
V_51 -> V_248 ) ;
if ( ! ( V_544 & V_279 ) && V_544 > 0 ) {
if ( ! V_542 -> V_454 ) {
V_542 -> V_454 = 1 ;
F_16 ( V_12 ) ;
}
return 1 ;
}
}
}
if ( V_542 -> V_454 ) {
V_542 -> V_454 = 0 ;
F_19 ( V_12 ) ;
}
return 0 ;
}
int F_298 ( struct V_11 * V_12 ,
struct V_292 * V_293 ,
const struct V_546 * V_547 ,
int V_548 )
{
V_293 -> type = V_370 ;
V_293 -> V_296 = 1 ;
V_293 -> V_297 . V_371 . V_333 = V_548 ;
if ( V_293 -> V_297 . V_371 . V_327 >= V_548 )
V_293 -> V_297 . V_371 . V_327 = V_548 - 1 ;
sprintf ( V_293 -> V_297 . V_371 . V_143 , L_97 ,
V_547 [ V_293 -> V_297 . V_371 . V_327 ] . V_477 ) ;
return 0 ;
}
int F_299 ( struct V_11 * V_12 ,
struct V_302 * V_303 ,
const struct V_546 * V_547 ,
int V_548 ,
int V_549 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_548 ; V_17 ++ ) {
if ( V_549 == V_547 [ V_17 ] . V_477 ) {
V_303 -> V_297 . V_371 . V_327 [ 0 ] = V_17 ;
break;
}
}
return 0 ;
}
int F_300 ( struct V_11 * V_12 ,
struct V_302 * V_303 ,
const struct V_546 * V_547 ,
int V_548 ,
int * V_550 )
{
unsigned int V_551 ;
V_551 = V_303 -> V_297 . V_371 . V_327 [ 0 ] ;
if ( V_551 >= V_548 )
return - V_61 ;
if ( * V_550 == V_547 [ V_551 ] . V_477 )
return 0 ;
* V_550 = V_547 [ V_551 ] . V_477 ;
if ( V_547 [ V_551 ] . V_552 )
F_244 ( V_12 , V_547 [ V_551 ] . V_552 ) ;
return 1 ;
}
int F_301 ( const struct V_553 * V_554 ,
struct V_292 * V_293 )
{
unsigned int V_264 ;
V_293 -> type = V_370 ;
V_293 -> V_296 = 1 ;
V_293 -> V_297 . V_371 . V_333 = V_554 -> V_555 ;
if ( ! V_554 -> V_555 )
return 0 ;
V_264 = V_293 -> V_297 . V_371 . V_327 ;
if ( V_264 >= V_554 -> V_555 )
V_264 = V_554 -> V_555 - 1 ;
strcpy ( V_293 -> V_297 . V_371 . V_143 , V_554 -> V_333 [ V_264 ] . V_556 ) ;
return 0 ;
}
int F_302 ( struct V_11 * V_12 ,
const struct V_553 * V_554 ,
struct V_302 * V_303 ,
T_2 V_24 ,
unsigned int * V_557 )
{
unsigned int V_248 ;
if ( ! V_554 -> V_555 )
return 0 ;
V_248 = V_303 -> V_297 . V_371 . V_327 [ 0 ] ;
if ( V_248 >= V_554 -> V_555 )
V_248 = V_554 -> V_555 - 1 ;
if ( * V_557 == V_248 )
return 0 ;
F_222 ( V_12 , V_24 , 0 , V_558 ,
V_554 -> V_333 [ V_248 ] . V_264 ) ;
* V_557 = V_248 ;
return 1 ;
}
int F_303 ( struct V_290 * V_291 ,
struct V_292 * V_293 ,
int V_555 , const char * const * V_369 )
{
static const char * const V_559 [] = {
L_98 , L_99
} ;
if ( ! V_369 || ! V_555 ) {
V_555 = 2 ;
V_369 = V_559 ;
}
V_293 -> type = V_370 ;
V_293 -> V_296 = 1 ;
V_293 -> V_297 . V_371 . V_333 = V_555 ;
if ( V_293 -> V_297 . V_371 . V_327 >= V_293 -> V_297 . V_371 . V_333 )
V_293 -> V_297 . V_371 . V_327 = V_293 -> V_297 . V_371 . V_333 - 1 ;
strcpy ( V_293 -> V_297 . V_371 . V_143 ,
V_369 [ V_293 -> V_297 . V_371 . V_327 ] ) ;
return 0 ;
}
static void F_304 ( struct V_11 * V_12 , T_2 V_24 ,
unsigned int V_226 , unsigned int V_232 )
{
struct V_205 * V_399 ;
unsigned int V_560 ;
bool V_561 ;
V_399 = F_229 ( V_12 , V_24 ) ;
V_560 = F_23 ( V_12 , V_24 , 0 ,
V_234 , 0 ) ;
V_561 = V_12 -> V_349 &&
( V_399 -> V_413 & V_414 ) &&
V_560 != V_232 ;
if ( V_561 )
F_223 ( V_12 , V_24 ,
V_399 -> V_413 & ~ V_414 & 0xff ,
- 1 ) ;
F_124 ( V_12 , V_24 , V_226 , 0 , V_232 ) ;
if ( V_12 -> V_348 ) {
const T_2 * V_408 ;
for ( V_408 = V_12 -> V_348 ; * V_408 ; V_408 ++ )
F_124 ( V_12 , * V_408 , V_226 , 0 ,
V_232 ) ;
}
if ( V_561 )
F_223 ( V_12 , V_24 ,
V_399 -> V_413 & 0xff , - 1 ) ;
}
static void F_305 ( struct V_11 * V_12 , T_2 V_24 )
{
F_277 ( V_12 , V_24 ) ;
if ( V_12 -> V_348 ) {
const T_2 * V_408 ;
for ( V_408 = V_12 -> V_348 ; * V_408 ; V_408 ++ )
F_277 ( V_12 , * V_408 ) ;
}
}
void F_306 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
if ( ! V_7 )
return;
F_29 (codec, &bus->codec_list, list) {
if ( F_307 ( V_12 ) &&
V_12 -> V_107 . V_562 )
V_12 -> V_107 . V_562 ( V_12 ) ;
}
}
int F_308 ( struct V_11 * V_12 ,
struct V_426 * V_427 )
{
F_2 ( & V_12 -> V_199 ) ;
if ( V_427 -> V_563 == V_564 )
F_305 ( V_12 , V_427 -> V_429 ) ;
V_427 -> V_563 = V_565 ;
F_4 ( & V_12 -> V_199 ) ;
return 0 ;
}
int F_309 ( struct V_11 * V_12 ,
struct V_426 * V_427 ,
unsigned int V_226 ,
unsigned int V_232 ,
struct V_512 * V_513 )
{
F_2 ( & V_12 -> V_199 ) ;
F_304 ( V_12 , V_427 -> V_429 , V_226 , V_232 ) ;
F_4 ( & V_12 -> V_199 ) ;
return 0 ;
}
int F_310 ( struct V_11 * V_12 ,
struct V_426 * V_427 )
{
F_2 ( & V_12 -> V_199 ) ;
F_305 ( V_12 , V_427 -> V_429 ) ;
F_4 ( & V_12 -> V_199 ) ;
return 0 ;
}
int F_311 ( struct V_11 * V_12 ,
struct V_426 * V_427 )
{
F_2 ( & V_12 -> V_199 ) ;
V_427 -> V_563 = 0 ;
F_4 ( & V_12 -> V_199 ) ;
return 0 ;
}
int F_312 ( struct V_11 * V_12 ,
struct V_426 * V_427 ,
struct V_512 * V_513 ,
struct V_462 * V_463 )
{
struct V_566 * V_567 = V_513 -> V_567 ;
V_567 -> V_568 . V_472 = V_427 -> V_549 ;
if ( V_427 -> V_429 ) {
if ( ! V_427 -> V_569 ) {
V_427 -> V_569 = V_463 -> V_496 ;
V_427 -> V_570 = V_463 -> V_499 ;
V_427 -> V_571 = V_463 -> V_478 ;
} else {
V_567 -> V_568 . V_496 = V_427 -> V_569 ;
V_567 -> V_568 . V_499 = V_427 -> V_570 ;
V_463 -> V_478 = V_427 -> V_571 ;
}
if ( ! V_427 -> V_572 ) {
F_272 ( V_12 , V_427 -> V_429 ,
& V_427 -> V_572 ,
& V_427 -> V_573 ,
& V_427 -> V_574 ) ;
}
F_2 ( & V_12 -> V_199 ) ;
if ( V_427 -> V_428 ) {
if ( ( V_567 -> V_568 . V_496 & V_427 -> V_572 ) &&
( V_567 -> V_568 . V_499 & V_427 -> V_573 ) ) {
V_567 -> V_568 . V_496 &= V_427 -> V_572 ;
V_567 -> V_568 . V_499 &= V_427 -> V_573 ;
if ( V_427 -> V_574 < V_463 -> V_478 )
V_463 -> V_478 = V_427 -> V_574 ;
} else {
V_427 -> V_428 = 0 ;
}
}
F_4 ( & V_12 -> V_199 ) ;
}
return F_313 ( V_513 -> V_567 , 0 ,
V_575 , 2 ) ;
}
int F_314 ( struct V_11 * V_12 ,
struct V_426 * V_427 ,
unsigned int V_226 ,
unsigned int V_232 ,
struct V_512 * V_513 )
{
const T_2 * V_188 = V_427 -> V_576 ;
int V_294 = V_513 -> V_567 -> V_477 ;
struct V_205 * V_399 ;
int V_17 ;
F_2 ( & V_12 -> V_199 ) ;
V_399 = F_229 ( V_12 , V_427 -> V_429 ) ;
if ( V_427 -> V_429 && V_427 -> V_428 &&
V_427 -> V_563 != V_565 ) {
if ( V_294 == 2 &&
F_273 ( V_12 , V_427 -> V_429 ,
V_232 ) &&
! ( V_399 -> V_391 & V_393 ) ) {
V_427 -> V_563 = V_564 ;
F_304 ( V_12 , V_427 -> V_429 ,
V_226 , V_232 ) ;
} else {
V_427 -> V_563 = 0 ;
F_305 ( V_12 , V_427 -> V_429 ) ;
}
}
F_4 ( & V_12 -> V_199 ) ;
F_124 ( V_12 , V_188 [ V_577 ] , V_226 ,
0 , V_232 ) ;
if ( ! V_427 -> V_578 &&
V_427 -> V_579 && V_427 -> V_579 != V_188 [ V_577 ] )
F_124 ( V_12 , V_427 -> V_579 , V_226 ,
0 , V_232 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_427 -> V_580 ) ; V_17 ++ )
if ( ! V_427 -> V_578 && V_427 -> V_580 [ V_17 ] )
F_124 ( V_12 ,
V_427 -> V_580 [ V_17 ] ,
V_226 , 0 , V_232 ) ;
for ( V_17 = 1 ; V_17 < V_427 -> V_581 ; V_17 ++ ) {
if ( V_294 >= ( V_17 + 1 ) * 2 )
F_124 ( V_12 , V_188 [ V_17 ] , V_226 ,
V_17 * 2 , V_232 ) ;
else if ( ! V_427 -> V_578 )
F_124 ( V_12 , V_188 [ V_17 ] , V_226 ,
0 , V_232 ) ;
}
for ( V_17 = 0 ; V_17 < F_10 ( V_427 -> V_582 ) ; V_17 ++ ) {
int V_263 = 0 ;
if ( ! V_427 -> V_582 [ V_17 ] )
break;
if ( V_294 >= ( V_17 + 1 ) * 2 )
V_263 = V_17 * 2 ;
else if ( ! V_427 -> V_578 )
break;
F_124 ( V_12 , V_427 -> V_582 [ V_17 ] ,
V_226 , V_263 , V_232 ) ;
}
return 0 ;
}
int F_315 ( struct V_11 * V_12 ,
struct V_426 * V_427 )
{
const T_2 * V_188 = V_427 -> V_576 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_427 -> V_581 ; V_17 ++ )
F_277 ( V_12 , V_188 [ V_17 ] ) ;
if ( V_427 -> V_579 )
F_277 ( V_12 , V_427 -> V_579 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_427 -> V_580 ) ; V_17 ++ )
if ( V_427 -> V_580 [ V_17 ] )
F_277 ( V_12 ,
V_427 -> V_580 [ V_17 ] ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_427 -> V_582 ) ; V_17 ++ )
if ( V_427 -> V_582 [ V_17 ] )
F_277 ( V_12 ,
V_427 -> V_582 [ V_17 ] ) ;
F_2 ( & V_12 -> V_199 ) ;
if ( V_427 -> V_429 && V_427 -> V_563 == V_564 ) {
F_305 ( V_12 , V_427 -> V_429 ) ;
V_427 -> V_563 = 0 ;
}
F_4 ( & V_12 -> V_199 ) ;
return 0 ;
}
unsigned int F_316 ( struct V_11 * V_12 , T_2 V_167 )
{
unsigned int V_583 ;
unsigned int V_228 ;
V_228 = F_23 ( V_12 , V_167 , 0 ,
V_172 , 0 ) ;
V_583 = F_140 ( V_12 , V_167 ) ;
V_583 = ( V_583 & V_584 ) >> V_585 ;
if ( ( V_583 & V_586 ) && V_228 != V_587 )
return V_588 ;
else if ( V_583 & V_589 )
return V_590 ;
else if ( V_583 & V_591 )
return V_592 ;
else if ( V_583 & V_593 )
return V_594 ;
return V_595 ;
}
unsigned int F_317 ( struct V_11 * V_12 ,
T_2 V_167 , unsigned int V_28 )
{
static unsigned int V_596 [] [ 2 ] = {
{ V_592 , V_591 } ,
{ V_588 , V_586 } ,
{ V_590 , V_589 } ,
{ V_594 , V_593 } ,
} ;
unsigned int V_597 ;
if ( ! V_28 )
return 0 ;
V_597 = F_140 ( V_12 , V_167 ) ;
if ( ! V_597 )
return V_28 ;
if ( V_28 & V_598 ) {
if ( ! ( V_597 & V_599 ) )
V_28 &= ~ ( V_598 | V_600 ) ;
else if ( ( V_28 & V_600 ) && ! ( V_597 & V_601 ) )
V_28 &= ~ V_600 ;
}
if ( V_28 & V_602 ) {
if ( ! ( V_597 & V_603 ) )
V_28 &= ~ ( V_602 | V_604 ) ;
else {
unsigned int V_605 , V_606 ;
int V_17 ;
V_605 = ( V_597 & V_584 ) >> V_585 ;
V_606 = V_28 & V_604 ;
for ( V_17 = 0 ; V_17 < F_10 ( V_596 ) ; V_17 ++ ) {
if ( V_606 == V_596 [ V_17 ] [ 0 ] &&
! ( V_605 & V_596 [ V_17 ] [ 1 ] ) ) {
if ( V_17 == F_10 ( V_596 ) - 1 )
V_606 = V_595 ;
else
V_606 = V_596 [ V_17 + 1 ] [ 0 ] ;
}
}
V_28 &= ~ V_604 ;
V_28 |= V_606 ;
}
}
return V_28 ;
}
int F_318 ( struct V_11 * V_12 , T_2 V_167 ,
unsigned int V_28 , bool V_607 )
{
V_28 = F_317 ( V_12 , V_167 , V_28 ) ;
F_92 ( V_12 , V_167 , V_28 ) ;
if ( V_607 )
return F_240 ( V_12 , V_167 , 0 ,
V_180 , V_28 ) ;
else
return F_24 ( V_12 , V_167 , 0 ,
V_180 , V_28 ) ;
}
int F_319 ( struct V_553 * V_554 , const char * V_556 ,
int V_264 , int * V_608 )
{
int V_17 , V_609 = 0 ;
if ( V_554 -> V_555 >= V_610 ) {
F_21 ( V_30 L_100 ) ;
return - V_61 ;
}
for ( V_17 = 0 ; V_17 < V_554 -> V_555 ; V_17 ++ ) {
if ( ! strncmp ( V_556 , V_554 -> V_333 [ V_17 ] . V_556 , strlen ( V_556 ) ) )
V_609 ++ ;
}
if ( V_608 )
* V_608 = V_609 ;
if ( V_609 > 0 )
snprintf ( V_554 -> V_333 [ V_554 -> V_555 ] . V_556 ,
sizeof( V_554 -> V_333 [ V_554 -> V_555 ] . V_556 ) ,
L_101 , V_556 , V_609 ) ;
else
F_320 ( V_554 -> V_333 [ V_554 -> V_555 ] . V_556 , V_556 ,
sizeof( V_554 -> V_333 [ V_554 -> V_555 ] . V_556 ) ) ;
V_554 -> V_333 [ V_554 -> V_555 ] . V_264 = V_264 ;
V_554 -> V_555 ++ ;
return 0 ;
}
int F_321 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
F_29 (codec, &bus->codec_list, list) {
F_103 ( & V_12 -> V_182 ) ;
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
void * F_85 ( struct V_173 * V_174 )
{
if ( F_43 ( ! V_174 -> V_611 ) )
return NULL ;
if ( V_174 -> V_175 >= V_174 -> V_612 ) {
int V_613 = V_174 -> V_612 + V_174 -> V_614 ;
int V_307 = ( V_613 + 1 ) * V_174 -> V_611 ;
void * V_615 ;
if ( F_43 ( V_613 >= 4096 ) )
return NULL ;
V_615 = F_323 ( V_174 -> V_4 , V_307 , V_53 | V_616 ) ;
if ( ! V_615 )
return NULL ;
V_174 -> V_4 = V_615 ;
V_174 -> V_612 = V_613 ;
}
return F_87 ( V_174 , V_174 -> V_175 ++ ) ;
}
void F_101 ( struct V_173 * V_174 )
{
F_37 ( V_174 -> V_4 ) ;
V_174 -> V_175 = 0 ;
V_174 -> V_612 = 0 ;
V_174 -> V_4 = NULL ;
}
void F_324 ( int V_338 , char * V_246 , int V_617 )
{
static unsigned int V_618 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_17 , V_619 ;
for ( V_17 = 0 , V_619 = 0 ; V_17 < F_10 ( V_618 ) ; V_17 ++ )
if ( V_338 & ( V_502 << V_17 ) )
V_619 += snprintf ( V_246 + V_619 , V_617 - V_619 , L_102 , V_618 [ V_17 ] ) ;
V_246 [ V_619 ] = '\0' ;
}
