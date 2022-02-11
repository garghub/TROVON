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
F_14 ( V_7 , L_36 ,
V_7 -> V_30 , V_25 , V_27 , V_28 ) ;
return ~ 0 ;
}
V_29 = ( T_1 ) V_7 -> V_30 << 28 ;
V_29 |= ( T_1 ) V_25 << 20 ;
V_29 |= V_27 << 8 ;
V_29 |= V_28 ;
return V_29 ;
}
static int F_15 ( struct V_6 * V_7 , unsigned int V_31 ,
int V_26 , unsigned int * V_32 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
int V_33 ;
if ( V_31 == ~ 0 )
return - 1 ;
if ( V_32 )
* V_32 = - 1 ;
V_34:
F_16 ( V_7 ) ;
F_2 ( & V_10 -> V_35 ) ;
if ( V_26 & V_36 )
V_10 -> V_37 = 1 ;
for (; ; ) {
F_17 ( V_7 , V_31 ) ;
V_33 = V_10 -> V_12 . V_38 ( V_10 , V_31 ) ;
if ( V_33 != - V_39 )
break;
V_10 -> V_12 . V_40 ( V_10 , V_7 -> V_30 ) ;
}
if ( ! V_33 && V_32 ) {
* V_32 = V_10 -> V_12 . V_40 ( V_10 , V_7 -> V_30 ) ;
F_18 ( V_7 , * V_32 ) ;
}
V_10 -> V_37 = 0 ;
F_4 ( & V_10 -> V_35 ) ;
F_19 ( V_7 ) ;
if ( ! F_20 ( V_7 ) && V_32 && * V_32 == - 1 && V_10 -> V_41 ) {
if ( V_10 -> V_42 ) {
F_21 ( V_7 ,
L_37 ) ;
F_22 ( V_10 ) ;
V_10 -> V_12 . V_43 ( V_10 ) ;
}
goto V_34;
}
if ( ! V_33 || F_20 ( V_7 ) )
V_10 -> V_42 = 0 ;
return V_33 ;
}
unsigned int F_23 ( struct V_6 * V_7 , T_2 V_25 ,
int V_26 ,
unsigned int V_27 , unsigned int V_28 )
{
unsigned V_31 = F_13 ( V_7 , V_25 , V_26 , V_27 , V_28 ) ;
unsigned int V_32 ;
if ( F_15 ( V_7 , V_31 , V_26 , & V_32 ) )
return - 1 ;
return V_32 ;
}
int F_24 ( struct V_6 * V_7 , T_2 V_25 , int V_26 ,
unsigned int V_27 , unsigned int V_28 )
{
unsigned int V_31 = F_13 ( V_7 , V_25 , V_26 , V_27 , V_28 ) ;
unsigned int V_32 ;
return F_15 ( V_7 , V_31 , V_26 ,
V_7 -> V_10 -> V_44 ? & V_32 : NULL ) ;
}
void F_25 ( struct V_6 * V_7 , const struct V_45 * V_46 )
{
for (; V_46 -> V_25 ; V_46 ++ )
F_24 ( V_7 , V_46 -> V_25 , 0 , V_46 -> V_27 , V_46 -> V_47 ) ;
}
int F_26 ( struct V_6 * V_7 , T_2 V_25 ,
T_2 * V_48 )
{
unsigned int V_28 ;
V_28 = F_27 ( V_7 , V_25 , V_49 ) ;
if ( V_28 == - 1 )
return 0 ;
* V_48 = ( V_28 >> 16 ) & 0x7fff ;
return ( int ) ( V_28 & 0x7fff ) ;
}
static struct V_50 *
F_28 ( struct V_6 * V_7 , T_2 V_25 )
{
struct V_50 * V_51 ;
F_29 (p, &codec->conn_list, list) {
if ( V_51 -> V_25 == V_25 )
return V_51 ;
}
return NULL ;
}
static int F_30 ( struct V_6 * V_7 , T_2 V_25 , int V_52 ,
const T_2 * V_4 )
{
struct V_50 * V_51 ;
V_51 = F_31 ( sizeof( * V_51 ) + V_52 * sizeof( T_2 ) , V_53 ) ;
if ( ! V_51 )
return - V_54 ;
V_51 -> V_52 = V_52 ;
V_51 -> V_25 = V_25 ;
memcpy ( V_51 -> V_55 , V_4 , V_52 * sizeof( T_2 ) ) ;
F_32 ( & V_51 -> V_4 , & V_7 -> V_56 ) ;
return 0 ;
}
static void F_33 ( struct V_6 * V_7 )
{
while ( ! F_34 ( & V_7 -> V_56 ) ) {
struct V_50 * V_51 ;
V_51 = F_35 ( & V_7 -> V_56 , F_36 ( * V_51 ) , V_4 ) ;
F_6 ( & V_51 -> V_4 ) ;
F_37 ( V_51 ) ;
}
}
static int F_38 ( struct V_6 * V_7 , T_2 V_25 )
{
T_2 V_4 [ 32 ] ;
T_2 * V_57 = V_4 ;
int V_52 ;
V_52 = F_39 ( V_7 , V_25 , V_4 , F_10 ( V_4 ) ) ;
if ( V_52 == - V_58 ) {
V_52 = F_40 ( V_7 , V_25 ) ;
V_57 = F_31 ( sizeof( T_2 ) * V_52 , V_53 ) ;
if ( ! V_57 )
return - V_54 ;
V_52 = F_39 ( V_7 , V_25 , V_57 , V_52 ) ;
}
if ( V_52 >= 0 )
V_52 = F_41 ( V_7 , V_25 , V_52 , V_57 ) ;
if ( V_57 != V_4 )
F_37 ( V_57 ) ;
return V_52 ;
}
int F_42 ( struct V_6 * V_7 , T_2 V_25 ,
const T_2 * * V_59 )
{
bool V_60 = false ;
for (; ; ) {
int V_33 ;
const struct V_50 * V_51 ;
V_51 = F_28 ( V_7 , V_25 ) ;
if ( V_51 ) {
if ( V_59 )
* V_59 = V_51 -> V_55 ;
return V_51 -> V_52 ;
}
if ( F_43 ( V_60 ) )
return - V_61 ;
V_33 = F_38 ( V_7 , V_25 ) ;
if ( V_33 < 0 )
return V_33 ;
V_60 = true ;
}
}
int F_44 ( struct V_6 * V_7 , T_2 V_25 ,
T_2 * V_56 , int V_62 )
{
const T_2 * V_4 ;
int V_52 = F_42 ( V_7 , V_25 , & V_4 ) ;
if ( V_52 > 0 && V_56 ) {
if ( V_52 > V_62 ) {
F_14 ( V_7 , L_38 ,
V_52 , V_25 ) ;
return - V_61 ;
}
memcpy ( V_56 , V_4 , V_52 * sizeof( T_2 ) ) ;
}
return V_52 ;
}
static unsigned int F_45 ( struct V_6 * V_7 , T_2 V_25 )
{
unsigned int V_63 = F_46 ( V_7 , V_25 ) ;
unsigned int V_28 ;
if ( ! ( V_63 & V_64 ) &&
F_47 ( V_63 ) != V_65 )
return 0 ;
V_28 = F_27 ( V_7 , V_25 , V_66 ) ;
if ( V_28 == - 1 )
V_28 = 0 ;
return V_28 ;
}
int F_40 ( struct V_6 * V_7 , T_2 V_25 )
{
return F_39 ( V_7 , V_25 , NULL , 0 ) ;
}
int F_39 ( struct V_6 * V_7 , T_2 V_25 ,
T_2 * V_56 , int V_62 )
{
unsigned int V_28 ;
int V_18 , V_67 , V_55 ;
unsigned int V_68 , V_69 , V_70 ;
T_2 V_71 ;
int V_72 = 0 ;
V_28 = F_45 ( V_7 , V_25 ) ;
if ( ! V_28 )
return 0 ;
if ( V_28 & V_73 ) {
V_68 = 16 ;
V_69 = 2 ;
} else {
V_68 = 8 ;
V_69 = 4 ;
}
V_67 = V_28 & V_74 ;
V_70 = ( 1 << ( V_68 - 1 ) ) - 1 ;
if ( ! V_67 )
return 0 ;
if ( V_67 == 1 ) {
V_28 = F_23 ( V_7 , V_25 , 0 ,
V_75 , 0 ) ;
if ( V_28 == - 1 && V_7 -> V_10 -> V_41 )
return - V_76 ;
if ( V_56 )
V_56 [ 0 ] = V_28 & V_70 ;
return 1 ;
}
V_55 = 0 ;
V_71 = 0 ;
for ( V_18 = 0 ; V_18 < V_67 ; V_18 ++ ) {
int V_77 ;
T_2 V_29 , V_78 ;
if ( V_18 % V_69 == 0 ) {
V_28 = F_23 ( V_7 , V_25 , 0 ,
V_75 , V_18 ) ;
if ( V_28 == - 1 && V_7 -> V_10 -> V_41 )
return - V_76 ;
}
V_77 = ! ! ( V_28 & ( 1 << ( V_68 - 1 ) ) ) ;
V_29 = V_28 & V_70 ;
if ( V_29 == 0 && V_72 ++ ) {
F_21 ( V_7 ,
L_39 ,
V_25 , V_18 , V_28 ) ;
return 0 ;
}
V_28 >>= V_68 ;
if ( V_77 ) {
if ( ! V_71 || V_71 >= V_29 ) {
F_48 ( V_7 ,
L_40 ,
V_71 , V_29 ) ;
continue;
}
for ( V_78 = V_71 + 1 ; V_78 <= V_29 ; V_78 ++ ) {
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
V_56 [ V_55 ] = V_29 ;
}
V_55 ++ ;
}
V_71 = V_29 ;
}
return V_55 ;
}
int F_41 ( struct V_6 * V_7 , T_2 V_25 , int V_52 ,
const T_2 * V_4 )
{
struct V_50 * V_51 ;
V_51 = F_28 ( V_7 , V_25 ) ;
if ( V_51 ) {
F_6 ( & V_51 -> V_4 ) ;
F_37 ( V_51 ) ;
}
return F_30 ( V_7 , V_25 , V_52 , V_4 ) ;
}
int F_49 ( struct V_6 * V_7 , T_2 V_79 ,
T_2 V_25 , int V_80 )
{
const T_2 * V_81 ;
int V_18 , V_82 ;
V_82 = F_42 ( V_7 , V_79 , & V_81 ) ;
for ( V_18 = 0 ; V_18 < V_82 ; V_18 ++ )
if ( V_81 [ V_18 ] == V_25 )
return V_18 ;
if ( ! V_80 )
return - 1 ;
if ( V_80 > 10 ) {
F_21 ( V_7 , L_41 , V_25 ) ;
return - 1 ;
}
V_80 ++ ;
for ( V_18 = 0 ; V_18 < V_82 ; V_18 ++ ) {
unsigned int type = F_47 ( F_46 ( V_7 , V_81 [ V_18 ] ) ) ;
if ( type == V_83 || type == V_84 )
continue;
if ( F_49 ( V_7 , V_81 [ V_18 ] , V_25 , V_80 ) >= 0 )
return V_18 ;
}
return - 1 ;
}
static unsigned int F_50 ( struct V_6 * V_7 , T_2 V_25 )
{
unsigned int V_63 = F_46 ( V_7 , V_25 ) ;
unsigned int V_28 ;
if ( ! V_7 -> V_85 || ! ( V_63 & V_86 ) ||
F_47 ( V_63 ) != V_83 )
return 0 ;
V_28 = F_27 ( V_7 , V_25 , V_87 ) ;
if ( V_28 == - 1 && V_7 -> V_10 -> V_41 )
V_28 = 0 ;
return V_28 & V_88 ;
}
int F_51 ( struct V_6 * V_7 , T_2 V_25 ,
T_3 * V_89 , int V_90 )
{
unsigned int V_28 ;
int V_18 , V_91 , V_92 ;
V_28 = F_50 ( V_7 , V_25 ) ;
if ( ! V_28 )
return 0 ;
V_91 = V_28 + 1 ;
V_91 = V_91 < V_90 ? V_91 : V_90 ;
V_92 = 0 ;
while ( V_92 < V_91 ) {
V_28 = F_23 ( V_7 , V_25 , 0 ,
V_93 , V_92 ) ;
if ( V_28 == - 1 && V_7 -> V_10 -> V_41 )
break;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
V_89 [ V_92 ] = ( T_3 ) V_28 ;
V_28 >>= 4 ;
V_92 ++ ;
if ( V_92 >= V_91 )
break;
}
}
return V_92 ;
}
int F_52 ( struct V_9 * V_10 , T_1 V_32 , T_1 V_94 )
{
struct V_95 * V_96 ;
unsigned int V_97 ;
if ( ! V_10 || ! V_10 -> V_98 )
return 0 ;
F_53 ( V_10 , V_32 , V_94 ) ;
V_96 = V_10 -> V_96 ;
if ( ! V_96 )
return 0 ;
V_97 = ( V_96 -> V_97 + 1 ) % V_99 ;
V_96 -> V_97 = V_97 ;
V_97 <<= 1 ;
V_96 -> V_100 [ V_97 ] = V_32 ;
V_96 -> V_100 [ V_97 + 1 ] = V_94 ;
F_54 ( V_10 -> V_98 , & V_96 -> V_101 ) ;
return 0 ;
}
static void F_55 ( struct V_102 * V_101 )
{
struct V_95 * V_96 =
F_56 ( V_101 , struct V_95 , V_101 ) ;
struct V_9 * V_10 = V_96 -> V_10 ;
struct V_6 * V_7 ;
unsigned int V_103 , V_104 , V_32 ;
while ( V_96 -> V_103 != V_96 -> V_97 ) {
V_103 = ( V_96 -> V_103 + 1 ) % V_99 ;
V_96 -> V_103 = V_103 ;
V_103 <<= 1 ;
V_32 = V_96 -> V_100 [ V_103 ] ;
V_104 = V_96 -> V_100 [ V_103 + 1 ] ;
if ( ! ( V_104 & ( 1 << 4 ) ) )
continue;
V_7 = V_10 -> V_105 [ V_104 & 0x0f ] ;
if ( V_7 && V_7 -> V_106 . V_107 )
V_7 -> V_106 . V_107 ( V_7 , V_32 ) ;
}
}
static int F_57 ( struct V_9 * V_10 )
{
struct V_95 * V_96 ;
if ( V_10 -> V_96 )
return 0 ;
V_96 = F_58 ( sizeof( * V_96 ) , V_53 ) ;
if ( ! V_96 ) {
F_59 ( V_10 -> V_108 -> V_109 , L_42 ) ;
return - V_54 ;
}
F_60 ( & V_96 -> V_101 , F_55 ) ;
V_96 -> V_10 = V_10 ;
V_10 -> V_96 = V_96 ;
return 0 ;
}
static void F_61 ( struct V_9 * V_10 )
{
if ( ! V_10 )
return;
F_62 ( ! F_34 ( & V_10 -> V_110 ) ) ;
if ( V_10 -> V_98 )
F_63 ( V_10 -> V_98 ) ;
if ( V_10 -> V_96 )
F_37 ( V_10 -> V_96 ) ;
if ( V_10 -> V_12 . V_111 )
V_10 -> V_12 . V_111 ( V_10 ) ;
if ( V_10 -> V_98 )
F_64 ( V_10 -> V_98 ) ;
F_37 ( V_10 ) ;
}
static int F_65 ( struct V_112 * V_113 )
{
F_61 ( V_113 -> V_114 ) ;
return 0 ;
}
static int F_66 ( struct V_112 * V_113 )
{
struct V_9 * V_10 = V_113 -> V_114 ;
V_10 -> V_115 = 1 ;
return 0 ;
}
int F_67 ( struct V_116 * V_108 ,
const struct V_117 * V_118 ,
struct V_9 * * V_119 )
{
struct V_9 * V_10 ;
int V_33 ;
static struct V_120 V_121 = {
. V_122 = F_66 ,
. V_123 = F_65 ,
} ;
if ( F_43 ( ! V_118 ) )
return - V_61 ;
if ( F_43 ( ! V_118 -> V_12 . V_38 || ! V_118 -> V_12 . V_40 ) )
return - V_61 ;
if ( V_119 )
* V_119 = NULL ;
V_10 = F_58 ( sizeof( * V_10 ) , V_53 ) ;
if ( V_10 == NULL ) {
F_59 ( V_108 -> V_109 , L_43 ) ;
return - V_54 ;
}
V_10 -> V_108 = V_108 ;
V_10 -> V_124 = V_118 -> V_124 ;
V_10 -> V_125 = V_118 -> V_125 ;
V_10 -> V_126 = V_118 -> V_126 ;
V_10 -> V_127 = V_118 -> V_127 ;
V_10 -> V_12 = V_118 -> V_12 ;
F_68 ( & V_10 -> V_35 ) ;
F_68 ( & V_10 -> V_128 ) ;
F_69 ( & V_10 -> V_110 ) ;
snprintf ( V_10 -> V_129 , sizeof( V_10 -> V_129 ) ,
L_44 , V_108 -> V_130 ) ;
V_10 -> V_98 = F_70 ( V_10 -> V_129 ) ;
if ( ! V_10 -> V_98 ) {
F_59 ( V_108 -> V_109 , L_45 ,
V_10 -> V_129 ) ;
F_37 ( V_10 ) ;
return - V_54 ;
}
V_33 = F_71 ( V_108 , V_131 , V_10 , & V_121 ) ;
if ( V_33 < 0 ) {
F_61 ( V_10 ) ;
return V_33 ;
}
if ( V_119 )
* V_119 = V_10 ;
return 0 ;
}
static const struct V_132 *
F_72 ( struct V_6 * V_7 )
{
struct V_1 * V_133 ;
const struct V_132 * V_2 ;
unsigned int V_134 = 0 ;
V_34:
F_2 ( & V_3 ) ;
F_29 (tbl, &hda_preset_tables, list) {
if ( ! F_73 ( V_133 -> V_135 ) ) {
F_14 ( V_7 , L_46 ) ;
continue;
}
for ( V_2 = V_133 -> V_2 ; V_2 -> V_136 ; V_2 ++ ) {
T_1 V_70 = V_2 -> V_70 ;
if ( V_2 -> V_137 && V_2 -> V_137 != V_7 -> V_137 )
continue;
if ( V_2 -> V_138 && V_2 -> V_138 != V_7 -> V_138 )
continue;
if ( ! V_70 )
V_70 = ~ 0 ;
if ( V_2 -> V_136 == ( V_7 -> V_139 & V_70 ) &&
( ! V_2 -> V_140 ||
V_2 -> V_140 == V_7 -> V_141 ) ) {
F_4 ( & V_3 ) ;
V_7 -> V_135 = V_133 -> V_135 ;
return V_2 ;
}
}
F_74 ( V_133 -> V_135 ) ;
}
F_4 ( & V_3 ) ;
if ( V_134 < V_142 ) {
char V_143 [ 32 ] ;
if ( ! V_134 )
snprintf ( V_143 , sizeof( V_143 ) , L_47 ,
V_7 -> V_139 ) ;
else
snprintf ( V_143 , sizeof( V_143 ) , L_48 ,
( V_7 -> V_139 >> 16 ) & 0xffff ) ;
F_75 ( V_143 ) ;
V_134 ++ ;
goto V_34;
}
return NULL ;
}
static int F_76 ( struct V_6 * V_7 )
{
const struct V_144 * V_145 ;
const char * V_146 = NULL ;
T_4 V_139 = V_7 -> V_139 >> 16 ;
char V_147 [ 16 ] ;
if ( V_7 -> V_148 )
goto V_149;
for ( V_145 = V_150 ; V_145 -> V_136 ; V_145 ++ ) {
if ( V_145 -> V_136 == V_139 ) {
V_146 = V_145 -> V_143 ;
break;
}
}
if ( ! V_146 ) {
sprintf ( V_147 , L_49 , V_139 ) ;
V_146 = V_147 ;
}
V_7 -> V_148 = F_77 ( V_146 , V_53 ) ;
if ( ! V_7 -> V_148 )
return - V_54 ;
V_149:
if ( V_7 -> V_151 )
return 0 ;
if ( V_7 -> V_2 && V_7 -> V_2 -> V_143 )
V_7 -> V_151 = F_77 ( V_7 -> V_2 -> V_143 , V_53 ) ;
else {
sprintf ( V_147 , L_50 , V_7 -> V_139 & 0xffff ) ;
V_7 -> V_151 = F_77 ( V_147 , V_53 ) ;
}
if ( ! V_7 -> V_151 )
return - V_54 ;
return 0 ;
}
static void F_78 ( struct V_6 * V_7 )
{
int V_18 , V_152 , V_153 ;
T_2 V_25 ;
V_152 = F_26 ( V_7 , V_154 , & V_25 ) ;
for ( V_18 = 0 ; V_18 < V_152 ; V_18 ++ , V_25 ++ ) {
V_153 = F_27 ( V_7 , V_25 ,
V_155 ) ;
switch ( V_153 & 0xff ) {
case V_156 :
V_7 -> V_137 = V_25 ;
V_7 -> V_157 = V_153 & 0xff ;
V_7 -> V_158 = ( V_153 >> 8 ) & 1 ;
break;
case V_159 :
V_7 -> V_138 = V_25 ;
V_7 -> V_160 = V_153 & 0xff ;
V_7 -> V_161 = ( V_153 >> 8 ) & 1 ;
break;
default:
break;
}
}
}
static int F_79 ( struct V_6 * V_7 , T_2 V_162 )
{
int V_18 ;
T_2 V_25 ;
V_7 -> V_163 = F_26 ( V_7 , V_162 ,
& V_7 -> V_164 ) ;
V_7 -> V_63 = F_31 ( V_7 -> V_163 * 4 , V_53 ) ;
if ( ! V_7 -> V_63 )
return - V_54 ;
V_25 = V_7 -> V_164 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_163 ; V_18 ++ , V_25 ++ )
V_7 -> V_63 [ V_18 ] = F_27 ( V_7 , V_25 ,
V_165 ) ;
return 0 ;
}
static int F_80 ( struct V_6 * V_7 )
{
int V_18 ;
T_2 V_25 = V_7 -> V_164 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_163 ; V_18 ++ , V_25 ++ ) {
struct V_166 * V_167 ;
unsigned int V_63 = F_46 ( V_7 , V_25 ) ;
unsigned int V_168 = F_47 ( V_63 ) ;
if ( V_168 != V_83 )
continue;
V_167 = F_81 ( & V_7 -> V_169 ) ;
if ( ! V_167 )
return - V_54 ;
V_167 -> V_25 = V_25 ;
V_167 -> V_14 = F_23 ( V_7 , V_25 , 0 ,
V_170 , 0 ) ;
V_167 -> V_171 = F_23 ( V_7 , V_25 , 0 ,
V_172 ,
0 ) ;
}
return 0 ;
}
static struct V_166 * F_82 ( struct V_6 * V_7 ,
struct V_173 * V_174 ,
T_2 V_25 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_174 -> V_175 ; V_18 ++ ) {
struct V_166 * V_167 = F_83 ( V_174 , V_18 ) ;
if ( V_167 -> V_25 == V_25 )
return V_167 ;
}
return NULL ;
}
int F_84 ( struct V_6 * V_7 , struct V_173 * V_4 ,
T_2 V_25 , unsigned int V_14 )
{
struct V_166 * V_167 ;
V_167 = F_82 ( V_7 , V_4 , V_25 ) ;
if ( ! V_167 ) {
V_167 = F_81 ( V_4 ) ;
if ( ! V_167 )
return - V_54 ;
V_167 -> V_25 = V_25 ;
}
V_167 -> V_14 = V_14 ;
return 0 ;
}
int F_85 ( struct V_6 * V_7 ,
T_2 V_25 , unsigned int V_14 )
{
return F_84 ( V_7 , & V_7 -> V_176 , V_25 , V_14 ) ;
}
unsigned int F_86 ( struct V_6 * V_7 , T_2 V_25 )
{
struct V_166 * V_167 ;
#ifdef F_87
{
unsigned int V_14 = 0 ;
F_2 ( & V_7 -> V_177 ) ;
V_167 = F_82 ( V_7 , & V_7 -> V_178 , V_25 ) ;
if ( V_167 )
V_14 = V_167 -> V_14 ;
F_4 ( & V_7 -> V_177 ) ;
if ( V_14 )
return V_14 ;
}
#endif
V_167 = F_82 ( V_7 , & V_7 -> V_176 , V_25 ) ;
if ( V_167 )
return V_167 -> V_14 ;
V_167 = F_82 ( V_7 , & V_7 -> V_169 , V_25 ) ;
if ( V_167 )
return V_167 -> V_14 ;
return 0 ;
}
int F_88 ( struct V_6 * V_7 , T_2 V_25 ,
unsigned int V_29 )
{
struct V_166 * V_167 ;
V_167 = F_82 ( V_7 , & V_7 -> V_169 , V_25 ) ;
if ( ! V_167 )
return - V_61 ;
V_167 -> V_179 = V_29 ;
return 0 ;
}
int F_89 ( struct V_6 * V_7 , T_2 V_25 )
{
struct V_166 * V_167 ;
V_167 = F_82 ( V_7 , & V_7 -> V_169 , V_25 ) ;
if ( ! V_167 )
return 0 ;
return V_167 -> V_179 ;
}
void F_90 ( struct V_6 * V_7 )
{
int V_18 ;
if ( V_7 -> V_10 -> V_115 )
return;
for ( V_18 = 0 ; V_18 < V_7 -> V_169 . V_175 ; V_18 ++ ) {
struct V_166 * V_167 = F_83 ( & V_7 -> V_169 , V_18 ) ;
F_23 ( V_7 , V_167 -> V_25 , 0 ,
V_180 , 0 ) ;
}
V_7 -> V_181 = 1 ;
}
static void F_91 ( struct V_6 * V_7 )
{
int V_18 ;
if ( ! V_7 -> V_181 )
return;
if ( V_7 -> V_10 -> V_115 )
return;
for ( V_18 = 0 ; V_18 < V_7 -> V_169 . V_175 ; V_18 ++ ) {
struct V_166 * V_167 = F_83 ( & V_7 -> V_169 , V_18 ) ;
F_24 ( V_7 , V_167 -> V_25 , 0 ,
V_180 ,
V_167 -> V_171 ) ;
}
V_7 -> V_181 = 0 ;
}
static void F_92 ( struct V_102 * V_101 )
{
struct V_6 * V_7 =
F_56 ( V_101 , struct V_6 , V_182 . V_101 ) ;
F_93 ( V_7 ) ;
F_94 ( V_7 ) ;
if ( ! V_7 -> V_183 )
return;
F_95 ( V_7 -> V_10 -> V_98 , & V_7 -> V_182 ,
V_7 -> V_183 ) ;
}
static void F_96 ( struct V_6 * V_7 )
{
F_97 ( & V_7 -> V_176 ) ;
#ifdef F_87
F_97 ( & V_7 -> V_178 ) ;
#endif
F_97 ( & V_7 -> V_169 ) ;
}
static struct V_184 *
F_98 ( struct V_6 * V_7 , T_2 V_25 )
{
struct V_184 * V_51 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_185 . V_175 ; V_18 ++ ) {
V_51 = F_83 ( & V_7 -> V_185 , V_18 ) ;
if ( V_51 -> V_25 == V_25 )
return V_51 ;
}
V_51 = F_81 ( & V_7 -> V_185 ) ;
if ( V_51 )
V_51 -> V_25 = V_25 ;
return V_51 ;
}
static void F_99 ( struct V_6 * V_7 )
{
if ( V_7 -> V_186 )
F_100 ( V_7 -> V_186 ) ;
V_7 -> V_186 = NULL ;
}
static void F_101 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_102 ( & V_7 -> V_182 ) ;
F_103 ( V_7 ) ;
F_96 ( V_7 ) ;
#ifdef F_104
F_105 ( & V_7 -> V_187 ) ;
F_63 ( V_7 -> V_10 -> V_98 ) ;
#endif
F_6 ( & V_7 -> V_4 ) ;
F_97 ( & V_7 -> V_188 ) ;
F_97 ( & V_7 -> V_189 ) ;
F_97 ( & V_7 -> V_185 ) ;
F_97 ( & V_7 -> V_190 ) ;
F_33 ( V_7 ) ;
V_7 -> V_10 -> V_105 [ V_7 -> V_30 ] = NULL ;
if ( V_7 -> V_106 . free )
V_7 -> V_106 . free ( V_7 ) ;
F_7 ( V_7 , false ) ;
F_106 ( V_7 ) ;
F_99 ( V_7 ) ;
F_74 ( V_7 -> V_135 ) ;
F_107 ( & V_7 -> V_191 ) ;
F_107 ( & V_7 -> V_192 ) ;
F_37 ( V_7 -> V_148 ) ;
F_37 ( V_7 -> V_151 ) ;
F_37 ( V_7 -> V_126 ) ;
F_37 ( V_7 -> V_63 ) ;
V_7 -> V_10 -> V_193 -- ;
F_108 ( & V_7 -> V_109 ) ;
}
static int F_109 ( struct V_112 * V_113 )
{
struct V_6 * V_7 = V_113 -> V_114 ;
int V_33 = F_110 ( & V_7 -> V_109 ) ;
if ( V_33 < 0 )
return V_33 ;
F_111 ( V_7 ) ;
return 0 ;
}
static int F_112 ( struct V_112 * V_113 )
{
struct V_6 * V_7 = V_113 -> V_114 ;
F_113 ( V_7 ) ;
F_114 ( & V_7 -> V_109 ) ;
return 0 ;
}
static int F_115 ( struct V_112 * V_113 )
{
F_101 ( V_113 -> V_114 ) ;
return 0 ;
}
static void F_116 ( struct V_113 * V_109 )
{
F_37 ( F_56 ( V_109 , struct V_6 , V_109 ) ) ;
}
int F_117 ( struct V_9 * V_10 ,
unsigned int V_194 ,
struct V_6 * * V_195 )
{
struct V_6 * V_7 ;
char V_196 [ 31 ] ;
T_2 V_197 ;
int V_33 ;
static struct V_120 V_121 = {
. V_198 = F_109 ,
. V_122 = F_112 ,
. V_123 = F_115 ,
} ;
if ( F_43 ( ! V_10 ) )
return - V_61 ;
if ( F_43 ( V_194 > V_199 ) )
return - V_61 ;
if ( V_10 -> V_105 [ V_194 ] ) {
F_59 ( V_10 -> V_108 -> V_109 ,
L_51 ,
V_194 ) ;
return - V_200 ;
}
V_7 = F_58 ( sizeof( * V_7 ) , V_53 ) ;
if ( V_7 == NULL ) {
F_59 ( V_10 -> V_108 -> V_109 , L_52 ) ;
return - V_54 ;
}
F_118 ( & V_7 -> V_109 ) ;
V_7 -> V_109 . V_201 = & V_10 -> V_108 -> V_202 ;
V_7 -> V_109 . V_203 = V_204 ;
V_7 -> V_109 . V_205 = F_116 ;
V_7 -> V_109 . V_206 = V_207 ;
F_119 ( & V_7 -> V_109 , L_53 , V_10 -> V_108 -> V_130 ,
V_194 ) ;
F_120 ( & V_7 -> V_109 , V_7 ) ;
V_7 -> V_10 = V_10 ;
V_7 -> V_30 = V_194 ;
F_68 ( & V_7 -> V_208 ) ;
F_68 ( & V_7 -> V_209 ) ;
F_68 ( & V_7 -> V_210 ) ;
F_121 ( & V_7 -> V_191 , sizeof( struct V_211 ) ) ;
F_121 ( & V_7 -> V_192 , sizeof( struct V_212 ) ) ;
F_122 ( & V_7 -> V_188 , sizeof( struct V_213 ) , 32 ) ;
F_122 ( & V_7 -> V_189 , sizeof( struct V_213 ) , 32 ) ;
F_122 ( & V_7 -> V_169 , sizeof( struct V_166 ) , 16 ) ;
F_122 ( & V_7 -> V_176 , sizeof( struct V_166 ) , 16 ) ;
F_122 ( & V_7 -> V_185 , sizeof( struct V_184 ) , 8 ) ;
F_122 ( & V_7 -> V_190 , sizeof( struct V_214 ) , 16 ) ;
F_122 ( & V_7 -> V_215 , sizeof( struct V_216 ) , 16 ) ;
F_122 ( & V_7 -> V_217 , sizeof( struct V_45 * ) , 8 ) ;
F_69 ( & V_7 -> V_56 ) ;
F_123 ( & V_7 -> V_182 , F_92 ) ;
V_7 -> V_218 = - 1 ;
V_7 -> V_219 = V_220 ;
#ifdef F_104
F_124 ( & V_7 -> V_221 ) ;
F_123 ( & V_7 -> V_187 , V_222 ) ;
F_8 ( V_7 ) ;
#endif
F_125 ( V_7 ) ;
if ( V_7 -> V_10 -> V_126 ) {
V_7 -> V_126 = F_77 ( V_7 -> V_10 -> V_126 , V_53 ) ;
if ( ! V_7 -> V_126 ) {
V_33 = - V_223 ;
goto error;
}
}
F_3 ( & V_7 -> V_4 , & V_10 -> V_110 ) ;
V_10 -> V_193 ++ ;
V_10 -> V_105 [ V_194 ] = V_7 ;
V_7 -> V_139 = F_27 ( V_7 , V_154 ,
V_224 ) ;
if ( V_7 -> V_139 == - 1 )
V_7 -> V_139 = F_27 ( V_7 , V_154 ,
V_224 ) ;
V_7 -> V_225 = F_27 ( V_7 , V_154 ,
V_226 ) ;
V_7 -> V_141 = F_27 ( V_7 , V_154 ,
V_227 ) ;
F_78 ( V_7 ) ;
if ( ! V_7 -> V_137 && ! V_7 -> V_138 ) {
F_59 ( V_10 -> V_108 -> V_109 , L_54 ) ;
V_33 = - V_223 ;
goto error;
}
V_197 = V_7 -> V_137 ? V_7 -> V_137 : V_7 -> V_138 ;
V_33 = F_79 ( V_7 , V_197 ) ;
if ( V_33 < 0 ) {
F_59 ( V_10 -> V_108 -> V_109 , L_55 ) ;
goto error;
}
V_33 = F_80 ( V_7 ) ;
if ( V_33 < 0 )
goto error;
if ( ! V_7 -> V_225 ) {
V_7 -> V_225 =
F_23 ( V_7 , V_197 , 0 ,
V_228 , 0 ) ;
}
#ifdef F_104
V_7 -> V_229 = F_126 ( V_7 , V_197 ,
V_230 ) ;
#endif
V_7 -> V_231 = F_126 ( V_7 , V_197 ,
V_232 ) ;
#ifdef F_104
if ( ! V_7 -> V_229 || ! V_7 -> V_231 )
V_10 -> V_233 = 1 ;
#endif
F_127 ( V_7 , V_234 ) ;
F_128 ( V_7 ) ;
F_129 ( V_7 ) ;
sprintf ( V_196 , L_56 , V_7 -> V_139 ,
V_7 -> V_225 , V_7 -> V_141 ) ;
F_130 ( V_7 -> V_10 -> V_108 , V_196 ) ;
V_33 = F_71 ( V_10 -> V_108 , V_235 , V_7 , & V_121 ) ;
if ( V_33 < 0 )
goto error;
if ( V_195 )
* V_195 = V_7 ;
return 0 ;
error:
F_101 ( V_7 ) ;
return V_33 ;
}
int F_131 ( struct V_6 * V_7 )
{
T_2 V_197 ;
int V_33 ;
F_37 ( V_7 -> V_63 ) ;
V_197 = V_7 -> V_137 ? V_7 -> V_137 : V_7 -> V_138 ;
V_33 = F_79 ( V_7 , V_197 ) ;
if ( V_33 < 0 ) {
F_14 ( V_7 , L_55 ) ;
return V_33 ;
}
F_97 ( & V_7 -> V_169 ) ;
V_33 = F_80 ( V_7 ) ;
return V_33 ;
}
static bool F_132 ( struct V_6 * V_7 )
{
T_2 V_25 = V_7 -> V_164 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_163 ; V_18 ++ , V_25 ++ ) {
unsigned int V_63 = F_46 ( V_7 , V_25 ) ;
switch ( F_47 ( V_63 ) ) {
case V_236 :
return false ;
case V_84 :
if ( ! ( V_63 & V_86 ) )
return false ;
break;
}
}
return true ;
}
int F_133 ( struct V_6 * V_7 )
{
int (* F_134)( struct V_6 * ) = NULL ;
int V_33 ;
V_7 -> V_2 = F_72 ( V_7 ) ;
if ( ! V_7 -> V_148 || ! V_7 -> V_151 ) {
V_33 = F_76 ( V_7 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( ! F_135 ( V_7 ) && V_7 -> V_2 )
F_134 = V_7 -> V_2 -> F_134 ;
if ( ! F_134 ) {
F_99 ( V_7 ) ;
if ( F_132 ( V_7 ) ) {
#if F_136 ( V_237 )
F_134 = F_137 ( V_7 , V_238 ) ;
#elif F_138 ( V_237 )
F_134 = V_238 ;
#endif
}
if ( ! F_134 ) {
#if F_136 ( V_239 )
F_134 = F_137 ( V_7 , V_240 ) ;
#elif F_138 ( V_239 )
F_134 = V_240 ;
#endif
}
if ( ! F_134 ) {
F_14 ( V_7 , L_57 ) ;
return - V_223 ;
}
}
V_33 = F_134 ( V_7 ) ;
if ( V_33 < 0 ) {
F_99 ( V_7 ) ;
return V_33 ;
}
if ( V_7 -> V_106 . V_107 ) {
V_33 = F_57 ( V_7 -> V_10 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_7 -> V_137 || ! * V_7 -> V_10 -> V_108 -> V_241 )
snprintf ( V_7 -> V_10 -> V_108 -> V_241 ,
sizeof( V_7 -> V_10 -> V_108 -> V_241 ) ,
L_58 , V_7 -> V_148 , V_7 -> V_151 ) ;
return 0 ;
}
static void F_139 ( struct V_6 * V_7 ,
struct V_184 * V_51 , T_2 V_25 ,
T_1 V_242 , int V_243 )
{
unsigned int V_244 , V_245 ;
if ( V_51 -> V_242 != V_242 || V_51 -> V_243 != V_243 ) {
V_244 = F_23 ( V_7 , V_25 , 0 , V_246 , 0 ) ;
V_245 = ( V_242 << 4 ) | V_243 ;
if ( V_244 != V_245 )
F_24 ( V_7 , V_25 , 0 ,
V_247 ,
V_245 ) ;
V_51 -> V_242 = V_242 ;
V_51 -> V_243 = V_243 ;
}
}
static void F_140 ( struct V_6 * V_7 , struct V_184 * V_51 ,
T_2 V_25 , int V_248 )
{
unsigned int V_244 ;
if ( V_51 -> V_249 != V_248 ) {
V_244 = F_23 ( V_7 , V_25 , 0 ,
V_250 , 0 ) ;
if ( V_244 != V_248 ) {
F_141 ( 1 ) ;
F_24 ( V_7 , V_25 , 0 ,
V_251 ,
V_248 ) ;
}
V_51 -> V_249 = V_248 ;
}
}
void F_142 ( struct V_6 * V_7 , T_2 V_25 ,
T_1 V_242 ,
int V_243 , int V_248 )
{
struct V_6 * V_145 ;
struct V_184 * V_51 ;
int type ;
int V_18 ;
if ( ! V_25 )
return;
F_21 ( V_7 ,
L_59 ,
V_25 , V_242 , V_243 , V_248 ) ;
V_51 = F_98 ( V_7 , V_25 ) ;
if ( ! V_51 )
return;
if ( V_7 -> V_252 )
F_140 ( V_7 , V_51 , V_25 , V_248 ) ;
F_139 ( V_7 , V_51 , V_25 , V_242 , V_243 ) ;
if ( ! V_7 -> V_252 )
F_140 ( V_7 , V_51 , V_25 , V_248 ) ;
V_51 -> V_253 = 1 ;
V_51 -> V_254 = 0 ;
type = F_47 ( F_46 ( V_7 , V_25 ) ) ;
F_29 (c, &codec->bus->codec_list, list) {
for ( V_18 = 0 ; V_18 < V_145 -> V_185 . V_175 ; V_18 ++ ) {
V_51 = F_83 ( & V_145 -> V_185 , V_18 ) ;
if ( ! V_51 -> V_253 && V_51 -> V_242 == V_242 &&
F_47 ( F_46 ( V_145 , V_51 -> V_25 ) ) == type )
V_51 -> V_254 = 1 ;
}
}
}
void F_143 ( struct V_6 * V_7 , T_2 V_25 ,
int V_255 )
{
struct V_184 * V_51 ;
if ( ! V_25 )
return;
if ( V_7 -> V_256 )
V_255 = 1 ;
F_21 ( V_7 , L_60 , V_25 ) ;
V_51 = F_98 ( V_7 , V_25 ) ;
if ( V_51 ) {
if ( V_255 )
F_144 ( V_7 , V_51 ) ;
else
V_51 -> V_253 = 0 ;
}
}
static void F_144 ( struct V_6 * V_7 ,
struct V_184 * V_257 )
{
T_2 V_25 = V_257 -> V_25 ;
if ( V_257 -> V_242 || V_257 -> V_243 )
F_24 ( V_7 , V_25 , 0 , V_247 , 0 ) ;
if ( V_257 -> V_249 )
F_24 ( V_7 , V_25 , 0 , V_251 , 0
) ;
memset ( V_257 , 0 , sizeof( * V_257 ) ) ;
V_257 -> V_25 = V_25 ;
}
static void F_145 ( struct V_6 * V_7 )
{
struct V_6 * V_145 ;
int V_18 ;
F_29 (c, &codec->bus->codec_list, list) {
for ( V_18 = 0 ; V_18 < V_145 -> V_185 . V_175 ; V_18 ++ ) {
struct V_184 * V_51 ;
V_51 = F_83 ( & V_145 -> V_185 , V_18 ) ;
if ( V_51 -> V_254 )
F_144 ( V_145 , V_51 ) ;
}
}
}
static void F_146 ( struct V_6 * V_7 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_185 . V_175 ; V_18 ++ ) {
struct V_184 * V_51 = F_83 ( & V_7 -> V_185 , V_18 ) ;
if ( V_51 -> V_242 )
F_144 ( V_7 , V_51 ) ;
}
}
static void F_121 ( struct V_258 * V_259 ,
unsigned int V_260 )
{
memset ( V_259 , 0 , sizeof( * V_259 ) ) ;
memset ( V_259 -> V_261 , 0xff , sizeof( V_259 -> V_261 ) ) ;
F_122 ( & V_259 -> V_262 , V_260 , 64 ) ;
}
static void F_107 ( struct V_258 * V_259 )
{
F_97 ( & V_259 -> V_262 ) ;
}
static struct V_212 * F_147 ( struct V_258 * V_259 , T_1 V_263 )
{
T_4 V_264 = V_263 % ( T_4 ) F_10 ( V_259 -> V_261 ) ;
T_4 V_265 = V_259 -> V_261 [ V_264 ] ;
struct V_212 * V_266 ;
while ( V_265 != 0xffff ) {
V_266 = F_83 ( & V_259 -> V_262 , V_265 ) ;
if ( V_266 -> V_263 == V_263 )
return V_266 ;
V_265 = V_266 -> V_267 ;
}
return NULL ;
}
static struct V_212 * F_148 ( struct V_258 * V_259 ,
T_1 V_263 )
{
struct V_212 * V_266 = F_147 ( V_259 , V_263 ) ;
if ( ! V_266 ) {
T_4 V_264 , V_265 ;
V_266 = F_81 ( & V_259 -> V_262 ) ;
if ( ! V_266 )
return NULL ;
V_265 = F_149 ( & V_259 -> V_262 , V_266 ) ;
V_266 -> V_263 = V_263 ;
V_266 -> V_29 = 0 ;
V_266 -> V_254 = 0 ;
V_264 = V_263 % ( T_4 ) F_10 ( V_259 -> V_261 ) ;
V_266 -> V_267 = V_259 -> V_261 [ V_264 ] ;
V_259 -> V_261 [ V_264 ] = V_265 ;
}
return V_266 ;
}
static inline struct V_211 *
F_150 ( struct V_6 * V_7 , T_1 V_263 )
{
return (struct V_211 * ) F_148 ( & V_7 -> V_191 , V_263 ) ;
}
static int F_151 ( struct V_6 * V_7 , T_1 V_263 , unsigned int V_29 )
{
struct V_211 * V_266 ;
F_2 ( & V_7 -> V_210 ) ;
V_266 = F_150 ( V_7 , V_263 ) ;
if ( ! V_266 ) {
F_4 ( & V_7 -> V_210 ) ;
return - V_61 ;
}
V_266 -> V_268 = V_29 ;
V_266 -> V_269 . V_29 |= V_270 ;
F_4 ( & V_7 -> V_210 ) ;
return 0 ;
}
static unsigned int F_152 ( struct V_6 * V_7 , T_2 V_25 ,
int V_271 )
{
if ( ! ( F_46 ( V_7 , V_25 ) & V_272 ) )
V_25 = V_7 -> V_137 ;
return F_27 ( V_7 , V_25 ,
V_271 == V_273 ?
V_274 : V_275 ) ;
}
T_1 F_153 ( struct V_6 * V_7 , T_2 V_25 , int V_271 )
{
return F_154 ( V_7 , V_25 , V_271 ,
F_155 ( V_25 , V_271 , 0 ) ,
F_152 ) ;
}
int F_156 ( struct V_6 * V_7 , T_2 V_25 , int V_276 ,
unsigned int V_277 )
{
return F_151 ( V_7 , F_155 ( V_25 , V_276 , 0 ) , V_277 ) ;
}
static unsigned int F_157 ( struct V_6 * V_7 , T_2 V_25 ,
int V_276 )
{
return F_27 ( V_7 , V_25 , V_278 ) ;
}
T_1 F_158 ( struct V_6 * V_7 , T_2 V_25 )
{
return F_154 ( V_7 , V_25 , 0 , F_159 ( V_25 ) ,
F_157 ) ;
}
int F_160 ( struct V_6 * V_7 , T_2 V_25 ,
unsigned int V_277 )
{
return F_151 ( V_7 , F_159 ( V_25 ) , V_277 ) ;
}
static struct V_211 *
F_161 ( struct V_6 * V_7 , T_2 V_25 , int V_279 ,
int V_271 , int V_280 , bool V_281 )
{
struct V_211 * V_266 ;
unsigned int V_28 , V_29 = 0 ;
bool V_282 = false ;
V_283:
V_266 = F_150 ( V_7 , F_155 ( V_25 , V_271 , V_280 ) ) ;
if ( ! V_266 )
return NULL ;
if ( ! ( V_266 -> V_269 . V_29 & F_162 ( V_279 ) ) ) {
if ( ! V_282 ) {
F_4 ( & V_7 -> V_210 ) ;
V_28 = V_279 ? V_284 : V_285 ;
V_28 |= V_271 == V_273 ?
V_286 : V_287 ;
V_28 |= V_280 ;
V_29 = F_23 ( V_7 , V_25 , 0 ,
V_288 , V_28 ) ;
V_29 &= 0xff ;
V_282 = true ;
F_2 ( & V_7 -> V_210 ) ;
goto V_283;
}
V_266 -> V_289 [ V_279 ] = V_29 ;
V_266 -> V_269 . V_29 |= F_162 ( V_279 ) ;
} else if ( V_281 )
return NULL ;
return V_266 ;
}
static void F_163 ( struct V_6 * V_7 , unsigned int V_268 ,
T_2 V_25 , int V_279 , int V_271 , int V_280 ,
int V_29 )
{
T_1 V_28 ;
V_28 = V_279 ? V_290 : V_291 ;
V_28 |= V_271 == V_273 ? V_292 : V_293 ;
V_28 |= V_280 << V_294 ;
if ( ( V_29 & V_295 ) && ! ( V_268 & V_296 ) &&
( V_268 & V_297 ) )
;
else
V_28 |= V_29 ;
F_24 ( V_7 , V_25 , 0 , V_298 , V_28 ) ;
}
int F_164 ( struct V_6 * V_7 , T_2 V_25 , int V_279 ,
int V_271 , int V_280 )
{
struct V_211 * V_266 ;
unsigned int V_29 = 0 ;
F_2 ( & V_7 -> V_210 ) ;
V_266 = F_161 ( V_7 , V_25 , V_279 , V_271 , V_280 , false ) ;
if ( V_266 )
V_29 = V_266 -> V_289 [ V_279 ] ;
F_4 ( & V_7 -> V_210 ) ;
return V_29 ;
}
static int F_165 ( struct V_6 * V_7 , T_2 V_25 , int V_279 ,
int V_271 , int V_264 , int V_70 , int V_29 ,
bool V_281 )
{
struct V_211 * V_266 ;
unsigned int V_277 ;
unsigned int V_299 ;
if ( F_43 ( V_70 & ~ 0xff ) )
V_70 &= 0xff ;
V_29 &= V_70 ;
F_2 ( & V_7 -> V_210 ) ;
V_266 = F_161 ( V_7 , V_25 , V_279 , V_271 , V_264 , V_281 ) ;
if ( ! V_266 ) {
F_4 ( & V_7 -> V_210 ) ;
return 0 ;
}
V_29 |= V_266 -> V_289 [ V_279 ] & ~ V_70 ;
if ( V_266 -> V_289 [ V_279 ] == V_29 ) {
F_4 ( & V_7 -> V_210 ) ;
return 0 ;
}
V_266 -> V_289 [ V_279 ] = V_29 ;
V_299 = V_266 -> V_269 . V_254 = V_7 -> V_300 ;
V_277 = V_266 -> V_268 ;
F_4 ( & V_7 -> V_210 ) ;
if ( ! V_299 )
F_163 ( V_7 , V_277 , V_25 , V_279 , V_271 , V_264 , V_29 ) ;
return 1 ;
}
int F_166 ( struct V_6 * V_7 , T_2 V_25 , int V_279 ,
int V_271 , int V_264 , int V_70 , int V_29 )
{
return F_165 ( V_7 , V_25 , V_279 , V_271 , V_264 , V_70 , V_29 , false ) ;
}
int F_167 ( struct V_6 * V_7 , T_2 V_25 ,
int V_271 , int V_264 , int V_70 , int V_29 )
{
int V_279 , V_301 = 0 ;
if ( F_43 ( V_70 & ~ 0xff ) )
V_70 &= 0xff ;
for ( V_279 = 0 ; V_279 < 2 ; V_279 ++ )
V_301 |= F_166 ( V_7 , V_25 , V_279 , V_271 ,
V_264 , V_70 , V_29 ) ;
return V_301 ;
}
int F_168 ( struct V_6 * V_7 , T_2 V_25 , int V_279 ,
int V_276 , int V_264 , int V_70 , int V_29 )
{
return F_165 ( V_7 , V_25 , V_279 , V_276 , V_264 , V_70 , V_29 , true ) ;
}
int F_169 ( struct V_6 * V_7 , T_2 V_25 ,
int V_276 , int V_264 , int V_70 , int V_29 )
{
int V_279 , V_301 = 0 ;
if ( F_43 ( V_70 & ~ 0xff ) )
V_70 &= 0xff ;
for ( V_279 = 0 ; V_279 < 2 ; V_279 ++ )
V_301 |= F_168 ( V_7 , V_25 , V_279 , V_276 ,
V_264 , V_70 , V_29 ) ;
return V_301 ;
}
void F_170 ( struct V_6 * V_7 )
{
int V_18 ;
F_2 ( & V_7 -> V_210 ) ;
V_7 -> V_300 = 0 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_191 . V_262 . V_175 ; V_18 ++ ) {
struct V_211 * V_302 ;
T_1 V_263 ;
T_2 V_25 ;
unsigned int V_264 , V_276 , V_279 ;
struct V_211 V_266 ;
V_302 = F_83 ( & V_7 -> V_191 . V_262 , V_18 ) ;
if ( ! V_302 -> V_269 . V_254 )
continue;
V_302 -> V_269 . V_254 = 0 ;
V_266 = * V_302 ;
V_263 = V_266 . V_269 . V_263 ;
if ( ! V_263 )
continue;
V_25 = V_263 & 0xff ;
V_264 = ( V_263 >> 16 ) & 0xff ;
V_276 = ( V_263 >> 24 ) & 0xff ;
for ( V_279 = 0 ; V_279 < 2 ; V_279 ++ ) {
if ( ! ( V_266 . V_269 . V_29 & F_162 ( V_279 ) ) )
continue;
F_4 ( & V_7 -> V_210 ) ;
F_163 ( V_7 , V_266 . V_268 , V_25 , V_279 , V_276 , V_264 ,
V_266 . V_289 [ V_279 ] ) ;
F_2 ( & V_7 -> V_210 ) ;
}
}
F_4 ( & V_7 -> V_210 ) ;
}
static T_1 F_171 ( struct V_6 * V_7 , T_2 V_25 , int V_276 ,
unsigned int V_303 )
{
T_1 V_277 = F_153 ( V_7 , V_25 , V_276 ) ;
V_277 = ( V_277 & V_304 ) >> V_305 ;
if ( V_303 < V_277 )
V_277 -= V_303 ;
return V_277 ;
}
int F_172 ( struct V_306 * V_307 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
T_4 V_25 = F_174 ( V_307 ) ;
T_3 V_310 = F_175 ( V_307 ) ;
int V_276 = F_176 ( V_307 ) ;
unsigned int V_303 = F_177 ( V_307 ) ;
V_309 -> type = V_311 ;
V_309 -> V_312 = V_310 == 3 ? 2 : 1 ;
V_309 -> V_313 . integer . V_314 = 0 ;
V_309 -> V_313 . integer . V_315 = F_171 ( V_7 , V_25 , V_276 , V_303 ) ;
if ( ! V_309 -> V_313 . integer . V_315 ) {
F_48 ( V_7 ,
L_61 ,
V_25 , V_307 -> V_136 . V_143 ) ;
return - V_61 ;
}
return 0 ;
}
static inline unsigned int
F_178 ( struct V_6 * V_7 , T_2 V_25 ,
int V_279 , int V_276 , int V_264 , unsigned int V_303 )
{
unsigned int V_29 ;
V_29 = F_164 ( V_7 , V_25 , V_279 , V_276 , V_264 ) ;
V_29 &= V_316 ;
if ( V_29 >= V_303 )
V_29 -= V_303 ;
else
V_29 = 0 ;
return V_29 ;
}
static inline int
F_179 ( struct V_6 * V_7 , T_2 V_25 ,
int V_279 , int V_276 , int V_264 , unsigned int V_303 ,
unsigned int V_29 )
{
unsigned int V_317 ;
if ( V_29 > 0 )
V_29 += V_303 ;
V_317 = F_171 ( V_7 , V_25 , V_276 , 0 ) ;
if ( V_29 > V_317 )
V_29 = V_317 ;
return F_166 ( V_7 , V_25 , V_279 , V_276 , V_264 ,
V_316 , V_29 ) ;
}
int F_180 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
T_2 V_25 = F_174 ( V_307 ) ;
int V_310 = F_175 ( V_307 ) ;
int V_276 = F_176 ( V_307 ) ;
int V_264 = F_181 ( V_307 ) ;
unsigned int V_303 = F_177 ( V_307 ) ;
long * V_320 = V_319 -> V_313 . integer . V_313 ;
if ( V_310 & 1 )
* V_320 ++ = F_178 ( V_7 , V_25 , 0 , V_276 , V_264 , V_303 ) ;
if ( V_310 & 2 )
* V_320 = F_178 ( V_7 , V_25 , 1 , V_276 , V_264 , V_303 ) ;
return 0 ;
}
int F_182 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
T_2 V_25 = F_174 ( V_307 ) ;
int V_310 = F_175 ( V_307 ) ;
int V_276 = F_176 ( V_307 ) ;
int V_264 = F_181 ( V_307 ) ;
unsigned int V_303 = F_177 ( V_307 ) ;
long * V_320 = V_319 -> V_313 . integer . V_313 ;
int V_321 = 0 ;
F_16 ( V_7 ) ;
if ( V_310 & 1 ) {
V_321 = F_179 ( V_7 , V_25 , 0 , V_276 , V_264 , V_303 , * V_320 ) ;
V_320 ++ ;
}
if ( V_310 & 2 )
V_321 |= F_179 ( V_7 , V_25 , 1 , V_276 , V_264 , V_303 , * V_320 ) ;
F_19 ( V_7 ) ;
return V_321 ;
}
int F_183 ( struct V_306 * V_307 , int V_322 ,
unsigned int V_323 , unsigned int T_5 * V_324 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
T_2 V_25 = F_174 ( V_307 ) ;
int V_276 = F_176 ( V_307 ) ;
unsigned int V_303 = F_177 ( V_307 ) ;
bool V_325 = F_184 ( V_307 ) ;
T_1 V_277 , V_326 , V_327 ;
if ( V_323 < 4 * sizeof( unsigned int ) )
return - V_54 ;
V_277 = F_153 ( V_7 , V_25 , V_276 ) ;
V_327 = ( V_277 & V_328 ) >> V_329 ;
V_327 = ( V_327 + 1 ) * 25 ;
V_326 = - ( ( V_277 & V_330 ) >> V_331 ) ;
V_326 += V_303 ;
V_326 = ( ( int ) V_326 ) * ( ( int ) V_327 ) ;
if ( V_325 || ( V_277 & V_297 ) )
V_327 |= V_332 ;
if ( F_185 ( V_333 , V_324 ) )
return - V_334 ;
if ( F_185 ( 2 * sizeof( unsigned int ) , V_324 + 1 ) )
return - V_334 ;
if ( F_185 ( V_326 , V_324 + 2 ) )
return - V_334 ;
if ( F_185 ( V_327 , V_324 + 3 ) )
return - V_334 ;
return 0 ;
}
void F_186 ( struct V_6 * V_7 , T_2 V_25 , int V_276 ,
unsigned int * V_335 )
{
T_1 V_277 ;
int V_82 , V_336 ;
V_277 = F_153 ( V_7 , V_25 , V_276 ) ;
V_82 = ( V_277 & V_304 ) >> V_305 ;
V_336 = ( V_277 & V_328 ) >> V_329 ;
V_336 = ( V_336 + 1 ) * 25 ;
V_335 [ 0 ] = V_333 ;
V_335 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_335 [ 2 ] = - V_82 * V_336 ;
V_335 [ 3 ] = V_336 ;
}
static struct V_306 *
F_187 ( struct V_6 * V_7 , const char * V_143 , int V_109 , int V_264 )
{
struct V_337 V_136 ;
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_338 = V_339 ;
V_136 . V_113 = V_109 ;
V_136 . V_280 = V_264 ;
if ( F_43 ( strlen ( V_143 ) >= sizeof( V_136 . V_143 ) ) )
return NULL ;
strcpy ( V_136 . V_143 , V_143 ) ;
return F_188 ( V_7 -> V_10 -> V_108 , & V_136 ) ;
}
struct V_306 * F_189 ( struct V_6 * V_7 ,
const char * V_143 )
{
return F_187 ( V_7 , V_143 , 0 , 0 ) ;
}
static int F_190 ( struct V_6 * V_7 , const char * V_143 ,
int V_340 )
{
int V_18 , V_264 ;
for ( V_18 = 0 , V_264 = V_340 ; V_18 < 16 ; V_18 ++ , V_264 ++ ) {
if ( ! F_187 ( V_7 , V_143 , 0 , V_264 ) )
return V_264 ;
}
return - V_200 ;
}
int F_191 ( struct V_6 * V_7 , T_2 V_25 ,
struct V_306 * V_341 )
{
int V_33 ;
unsigned short V_26 = 0 ;
struct V_213 * V_342 ;
if ( V_341 -> V_136 . V_343 & V_344 ) {
V_26 |= V_345 ;
if ( V_25 == 0 )
V_25 = F_192 ( V_341 -> V_346 ) ;
}
if ( ( V_341 -> V_136 . V_343 & V_347 ) != 0 && V_25 == 0 )
V_25 = V_341 -> V_136 . V_343 & 0xffff ;
if ( V_341 -> V_136 . V_343 & ( V_347 | V_344 ) )
V_341 -> V_136 . V_343 = 0 ;
V_33 = F_193 ( V_7 -> V_10 -> V_108 , V_341 ) ;
if ( V_33 < 0 )
return V_33 ;
V_342 = F_81 ( & V_7 -> V_188 ) ;
if ( ! V_342 )
return - V_54 ;
V_342 -> V_341 = V_341 ;
V_342 -> V_25 = V_25 ;
V_342 -> V_26 = V_26 ;
return 0 ;
}
int F_194 ( struct V_6 * V_7 , struct V_306 * V_341 ,
unsigned int V_280 , T_2 V_25 )
{
struct V_213 * V_342 ;
if ( V_25 > 0 ) {
V_342 = F_81 ( & V_7 -> V_189 ) ;
if ( ! V_342 )
return - V_54 ;
V_342 -> V_341 = V_341 ;
V_342 -> V_280 = V_280 ;
V_342 -> V_25 = V_25 ;
return 0 ;
}
F_14 ( V_7 , L_62 ,
V_341 -> V_136 . V_143 , V_341 -> V_136 . V_280 , V_280 ) ;
return - V_61 ;
}
void F_195 ( struct V_6 * V_7 )
{
int V_18 ;
struct V_213 * V_348 = V_7 -> V_188 . V_4 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_188 . V_175 ; V_18 ++ )
F_196 ( V_7 -> V_10 -> V_108 , V_348 [ V_18 ] . V_341 ) ;
F_97 ( & V_7 -> V_188 ) ;
F_97 ( & V_7 -> V_189 ) ;
}
int F_197 ( struct V_9 * V_10 )
{
struct V_116 * V_108 = V_10 -> V_108 ;
struct V_6 * V_7 ;
F_198 ( & V_108 -> V_349 ) ;
if ( V_108 -> V_115 )
goto V_350;
V_108 -> V_115 = 1 ;
if ( ! F_34 ( & V_108 -> V_351 ) )
goto V_352;
F_29 (codec, &bus->codec_list, list) {
int V_353 ;
for ( V_353 = 0 ; V_353 < V_7 -> V_354 ; V_353 ++ ) {
struct V_355 * V_356 = & V_7 -> V_357 [ V_353 ] ;
if ( ! V_356 -> V_353 )
continue;
if ( V_356 -> V_353 -> V_358 [ 0 ] . V_359 ||
V_356 -> V_353 -> V_358 [ 1 ] . V_359 )
goto V_352;
}
}
F_199 ( & V_108 -> V_349 ) ;
return 0 ;
V_352:
V_108 -> V_115 = 0 ;
V_350:
F_199 ( & V_108 -> V_349 ) ;
return - V_61 ;
}
void F_200 ( struct V_9 * V_10 )
{
struct V_116 * V_108 = V_10 -> V_108 ;
V_108 = V_10 -> V_108 ;
F_198 ( & V_108 -> V_349 ) ;
V_108 -> V_115 = 0 ;
F_199 ( & V_108 -> V_349 ) ;
}
int F_201 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_116 * V_108 = V_10 -> V_108 ;
int V_18 ;
if ( F_197 ( V_10 ) < 0 )
return - V_200 ;
F_102 ( & V_7 -> V_182 ) ;
#ifdef F_104
F_102 ( & V_7 -> V_187 ) ;
F_63 ( V_10 -> V_98 ) ;
#endif
F_195 ( V_7 ) ;
for ( V_18 = 0 ; V_18 < V_7 -> V_354 ; V_18 ++ ) {
if ( V_7 -> V_357 [ V_18 ] . V_353 ) {
F_202 ( V_108 , V_7 -> V_357 [ V_18 ] . V_353 ) ;
F_203 ( V_7 -> V_357 [ V_18 ] . V_113 ,
V_10 -> V_360 ) ;
}
}
F_113 ( V_7 ) ;
if ( V_7 -> V_106 . free )
V_7 -> V_106 . free ( V_7 ) ;
memset ( & V_7 -> V_106 , 0 , sizeof( V_7 -> V_106 ) ) ;
F_103 ( V_7 ) ;
V_7 -> V_361 = NULL ;
V_7 -> V_362 = NULL ;
F_107 ( & V_7 -> V_191 ) ;
F_107 ( & V_7 -> V_192 ) ;
F_121 ( & V_7 -> V_191 , sizeof( struct V_211 ) ) ;
F_121 ( & V_7 -> V_192 , sizeof( struct V_212 ) ) ;
F_97 ( & V_7 -> V_176 ) ;
F_97 ( & V_7 -> V_185 ) ;
F_97 ( & V_7 -> V_190 ) ;
F_97 ( & V_7 -> V_217 ) ;
V_7 -> V_354 = 0 ;
V_7 -> V_357 = NULL ;
V_7 -> V_2 = NULL ;
V_7 -> V_363 = NULL ;
V_7 -> V_364 = 0 ;
F_99 ( V_7 ) ;
F_74 ( V_7 -> V_135 ) ;
V_7 -> V_135 = NULL ;
F_200 ( V_10 ) ;
return 0 ;
}
static int F_204 ( struct V_6 * V_7 , const char * const * V_365 ,
const char * V_366 , T_6 V_367 , void * V_368 )
{
struct V_213 * V_348 ;
const char * const * V_369 ;
int V_18 , V_33 ;
V_348 = V_7 -> V_188 . V_4 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_188 . V_175 ; V_18 ++ ) {
struct V_306 * V_370 = V_348 [ V_18 ] . V_341 ;
if ( ! V_370 || V_370 -> V_136 . V_338 != V_339 )
continue;
for ( V_369 = V_365 ; * V_369 ; V_369 ++ ) {
char V_371 [ sizeof( V_370 -> V_136 . V_143 ) ] ;
const char * V_143 = * V_369 ;
if ( V_366 ) {
snprintf ( V_371 , sizeof( V_371 ) , L_58 ,
V_143 , V_366 ) ;
V_143 = V_371 ;
}
if ( ! strcmp ( V_370 -> V_136 . V_143 , V_143 ) ) {
V_33 = V_367 ( V_7 , V_368 , V_370 ) ;
if ( V_33 )
return V_33 ;
break;
}
}
}
return 0 ;
}
static int F_205 ( struct V_6 * V_7 ,
void * V_368 , struct V_306 * V_370 )
{
return 1 ;
}
static int F_206 ( struct V_6 * V_7 ,
struct V_306 * V_341 , int * V_372 )
{
int V_324 [ 4 ] ;
const int * V_335 = NULL ;
int V_29 = - 1 ;
if ( V_341 -> V_373 [ 0 ] . V_374 & V_375 ) {
T_7 V_376 = F_207 () ;
F_208 ( F_209 () ) ;
if ( ! V_341 -> V_335 . V_145 ( V_341 , 0 , sizeof( V_324 ) , V_324 ) )
V_335 = V_324 ;
F_208 ( V_376 ) ;
} else if ( V_341 -> V_373 [ 0 ] . V_374 & V_377 )
V_335 = V_341 -> V_335 . V_51 ;
if ( V_335 && V_335 [ 0 ] == V_333 ) {
int V_336 = V_335 [ 3 ] ;
V_336 &= ~ V_332 ;
if ( ! V_336 )
return - 1 ;
if ( * V_372 && * V_372 != V_336 ) {
F_14 ( V_7 , L_63 ,
- * V_372 , V_336 ) ;
return - 1 ;
}
* V_372 = V_336 ;
V_29 = - V_335 [ 2 ] / V_336 ;
}
return V_29 ;
}
static int F_210 ( struct V_306 * V_341 , int V_29 )
{
struct V_318 * V_319 ;
V_319 = F_58 ( sizeof( * V_319 ) , V_53 ) ;
if ( ! V_319 )
return - V_54 ;
V_319 -> V_313 . integer . V_313 [ 0 ] = V_29 ;
V_319 -> V_313 . integer . V_313 [ 1 ] = V_29 ;
V_341 -> V_378 ( V_341 , V_319 ) ;
F_37 ( V_319 ) ;
return 0 ;
}
static int F_211 ( struct V_6 * V_7 ,
void * V_368 , struct V_306 * V_379 )
{
int V_380 = F_206 ( V_7 , V_379 , V_368 ) ;
if ( V_380 > 0 )
F_210 ( V_379 , V_380 ) ;
return 0 ;
}
static int F_212 ( struct V_6 * V_7 ,
void * V_368 , struct V_306 * V_379 )
{
return F_210 ( V_379 , 1 ) ;
}
static int F_213 ( struct V_6 * V_7 ,
void * V_368 , struct V_306 * V_379 )
{
return F_214 ( V_368 , V_379 ) ;
}
int F_215 ( struct V_6 * V_7 , char * V_143 ,
unsigned int * V_335 , const char * const * V_365 ,
const char * V_366 , bool V_381 ,
struct V_306 * * V_382 )
{
struct V_306 * V_341 ;
int V_33 ;
if ( V_382 )
* V_382 = NULL ;
V_33 = F_204 ( V_7 , V_365 , V_366 , F_205 , NULL ) ;
if ( V_33 != 1 ) {
F_21 ( V_7 , L_64 , V_143 ) ;
return 0 ;
}
V_341 = F_216 ( V_143 , V_335 ) ;
if ( ! V_341 )
return - V_54 ;
V_33 = F_191 ( V_7 , 0 , V_341 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_204 ( V_7 , V_365 , V_366 , F_213 , V_341 ) ;
if ( V_33 < 0 )
return V_33 ;
F_210 ( V_341 , 0 ) ;
if ( V_381 ) {
int V_336 = 0 ;
F_204 ( V_7 , V_365 , V_366 ,
V_335 ? F_211 : F_212 , & V_336 ) ;
}
if ( V_382 )
* V_382 = V_341 ;
return 0 ;
}
static int F_217 ( struct V_306 * V_307 ,
struct V_308 * V_309 )
{
static const char * const V_383 [] = {
L_65 , L_66 , L_67
} ;
unsigned int V_280 ;
V_309 -> type = V_384 ;
V_309 -> V_312 = 1 ;
V_309 -> V_313 . V_385 . V_348 = 3 ;
V_280 = V_309 -> V_313 . V_385 . V_342 ;
if ( V_280 >= 3 )
V_280 = 2 ;
strcpy ( V_309 -> V_313 . V_385 . V_143 , V_383 [ V_280 ] ) ;
return 0 ;
}
static int F_218 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_386 * V_387 = F_173 ( V_307 ) ;
V_319 -> V_313 . V_385 . V_342 [ 0 ] = V_387 -> V_388 ;
return 0 ;
}
static int F_219 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_386 * V_387 = F_173 ( V_307 ) ;
unsigned int V_389 = V_387 -> V_388 ;
V_387 -> V_388 = V_319 -> V_313 . V_385 . V_342 [ 0 ] ;
if ( V_387 -> V_388 > V_390 )
V_387 -> V_388 = V_390 ;
if ( V_389 == V_387 -> V_388 )
return 0 ;
F_220 ( V_387 ) ;
return 1 ;
}
int F_221 ( struct V_6 * V_7 ,
struct V_386 * V_387 ,
bool V_391 )
{
struct V_306 * V_341 ;
if ( ! V_387 -> V_387 || ! V_387 -> V_392 )
return 0 ;
F_222 ( V_387 -> V_392 , V_387 -> V_387 , V_7 ) ;
V_387 -> V_7 = V_7 ;
V_387 -> V_388 = V_390 ;
if ( ! V_391 )
return 0 ;
V_341 = F_223 ( & V_393 , V_387 ) ;
if ( ! V_341 )
return - V_54 ;
return F_191 ( V_7 , 0 , V_341 ) ;
}
void F_220 ( struct V_386 * V_387 )
{
if ( ! V_387 -> V_387 || ! V_387 -> V_7 )
return;
if ( V_387 -> V_7 -> V_10 -> V_115 )
return;
switch ( V_387 -> V_388 ) {
case V_390 :
F_224 ( V_387 -> V_392 ) ;
break;
default:
V_387 -> V_387 ( V_387 -> V_7 , V_387 -> V_388 ) ;
break;
}
}
int F_225 ( struct V_306 * V_307 ,
struct V_308 * V_309 )
{
int V_310 = F_175 ( V_307 ) ;
V_309 -> type = V_394 ;
V_309 -> V_312 = V_310 == 3 ? 2 : 1 ;
V_309 -> V_313 . integer . V_314 = 0 ;
V_309 -> V_313 . integer . V_315 = 1 ;
return 0 ;
}
int F_226 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
T_2 V_25 = F_174 ( V_307 ) ;
int V_310 = F_175 ( V_307 ) ;
int V_276 = F_176 ( V_307 ) ;
int V_264 = F_181 ( V_307 ) ;
long * V_320 = V_319 -> V_313 . integer . V_313 ;
if ( V_310 & 1 )
* V_320 ++ = ( F_164 ( V_7 , V_25 , 0 , V_276 , V_264 ) &
V_295 ) ? 0 : 1 ;
if ( V_310 & 2 )
* V_320 = ( F_164 ( V_7 , V_25 , 1 , V_276 , V_264 ) &
V_295 ) ? 0 : 1 ;
return 0 ;
}
int F_227 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
T_2 V_25 = F_174 ( V_307 ) ;
int V_310 = F_175 ( V_307 ) ;
int V_276 = F_176 ( V_307 ) ;
int V_264 = F_181 ( V_307 ) ;
long * V_320 = V_319 -> V_313 . integer . V_313 ;
int V_321 = 0 ;
F_16 ( V_7 ) ;
if ( V_310 & 1 ) {
V_321 = F_166 ( V_7 , V_25 , 0 , V_276 , V_264 ,
V_295 ,
* V_320 ? 0 : V_295 ) ;
V_320 ++ ;
}
if ( V_310 & 2 )
V_321 |= F_166 ( V_7 , V_25 , 1 , V_276 , V_264 ,
V_295 ,
* V_320 ? 0 : V_295 ) ;
F_228 ( V_7 , V_25 ) ;
F_19 ( V_7 ) ;
return V_321 ;
}
int F_229 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
unsigned long V_395 ;
int V_33 ;
F_2 ( & V_7 -> V_209 ) ;
V_395 = V_307 -> V_346 ;
V_307 -> V_346 = V_395 & ~ V_396 ;
V_33 = F_226 ( V_307 , V_319 ) ;
V_307 -> V_346 = V_395 ;
F_4 ( & V_7 -> V_209 ) ;
return V_33 ;
}
int F_230 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
unsigned long V_395 ;
int V_18 , V_397 , V_33 = 0 , V_321 = 0 ;
F_2 ( & V_7 -> V_209 ) ;
V_395 = V_307 -> V_346 ;
V_397 = ( V_395 & V_396 ) >> V_398 ;
for ( V_18 = 0 ; V_18 < V_397 ; V_18 ++ ) {
V_307 -> V_346 = ( V_395 & ~ V_396 ) |
( V_18 << V_398 ) ;
V_33 = F_227 ( V_307 , V_319 ) ;
if ( V_33 < 0 )
break;
V_321 |= V_33 ;
}
V_307 -> V_346 = V_395 ;
F_4 ( & V_7 -> V_209 ) ;
return V_33 < 0 ? V_33 : V_321 ;
}
int F_231 ( struct V_306 * V_307 ,
struct V_308 * V_309 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
struct V_399 * V_145 ;
int V_33 ;
F_2 ( & V_7 -> V_209 ) ;
V_145 = (struct V_399 * ) V_307 -> V_346 ;
V_307 -> V_346 = * V_145 -> V_400 ;
V_33 = V_145 -> V_12 -> V_266 ( V_307 , V_309 ) ;
V_307 -> V_346 = ( long ) V_145 ;
F_4 ( & V_7 -> V_209 ) ;
return V_33 ;
}
int F_232 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
struct V_399 * V_145 ;
int V_33 ;
F_2 ( & V_7 -> V_209 ) ;
V_145 = (struct V_399 * ) V_307 -> V_346 ;
V_307 -> V_346 = * V_145 -> V_400 ;
V_33 = V_145 -> V_12 -> V_401 ( V_307 , V_319 ) ;
V_307 -> V_346 = ( long ) V_145 ;
F_4 ( & V_7 -> V_209 ) ;
return V_33 ;
}
int F_233 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
struct V_399 * V_145 ;
unsigned long * V_402 ;
int V_33 = 0 , V_321 = 0 ;
F_2 ( & V_7 -> V_209 ) ;
V_145 = (struct V_399 * ) V_307 -> V_346 ;
for ( V_402 = V_145 -> V_400 ; * V_402 ; V_402 ++ ) {
V_307 -> V_346 = * V_402 ;
V_33 = V_145 -> V_12 -> V_378 ( V_307 , V_319 ) ;
if ( V_33 < 0 )
break;
V_321 |= V_33 ;
}
V_307 -> V_346 = ( long ) V_145 ;
F_4 ( & V_7 -> V_209 ) ;
return V_33 < 0 ? V_33 : V_321 ;
}
int F_234 ( struct V_306 * V_307 , int V_322 ,
unsigned int V_323 , unsigned int T_5 * V_335 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
struct V_399 * V_145 ;
int V_33 ;
F_2 ( & V_7 -> V_209 ) ;
V_145 = (struct V_399 * ) V_307 -> V_346 ;
V_307 -> V_346 = * V_145 -> V_400 ;
V_33 = V_145 -> V_12 -> V_335 ( V_307 , V_322 , V_323 , V_335 ) ;
V_307 -> V_346 = ( long ) V_145 ;
F_4 ( & V_7 -> V_209 ) ;
return V_33 ;
}
static int F_235 ( struct V_306 * V_307 ,
struct V_308 * V_309 )
{
V_309 -> type = V_403 ;
V_309 -> V_312 = 1 ;
return 0 ;
}
static int F_236 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
V_319 -> V_313 . V_404 . V_405 [ 0 ] = V_406 |
V_407 |
V_408 |
V_409 ;
V_319 -> V_313 . V_404 . V_405 [ 1 ] = V_410 |
V_411 ;
return 0 ;
}
static int F_237 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
V_319 -> V_313 . V_404 . V_405 [ 0 ] = V_406 |
V_407 |
V_412 ;
return 0 ;
}
static int F_238 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
int V_264 = V_307 -> V_346 ;
struct V_214 * V_413 ;
F_2 ( & V_7 -> V_208 ) ;
V_413 = F_83 ( & V_7 -> V_190 , V_264 ) ;
V_319 -> V_313 . V_404 . V_405 [ 0 ] = V_413 -> V_405 & 0xff ;
V_319 -> V_313 . V_404 . V_405 [ 1 ] = ( V_413 -> V_405 >> 8 ) & 0xff ;
V_319 -> V_313 . V_404 . V_405 [ 2 ] = ( V_413 -> V_405 >> 16 ) & 0xff ;
V_319 -> V_313 . V_404 . V_405 [ 3 ] = ( V_413 -> V_405 >> 24 ) & 0xff ;
F_4 ( & V_7 -> V_208 ) ;
return 0 ;
}
static unsigned short F_239 ( unsigned int V_414 )
{
unsigned short V_29 = 0 ;
if ( V_414 & V_406 )
V_29 |= V_415 ;
if ( V_414 & V_407 )
V_29 |= V_416 ;
if ( V_414 & V_406 ) {
if ( ( V_414 & V_417 ) ==
V_412 )
V_29 |= V_418 ;
} else {
if ( ( V_414 & V_419 ) ==
V_408 )
V_29 |= V_418 ;
if ( ! ( V_414 & V_409 ) )
V_29 |= V_420 ;
if ( V_414 & ( V_411 << 8 ) )
V_29 |= V_421 ;
V_29 |= V_414 & ( V_410 << 8 ) ;
}
return V_29 ;
}
static unsigned int F_240 ( unsigned short V_29 )
{
unsigned int V_414 = 0 ;
if ( V_29 & V_416 )
V_414 |= V_407 ;
if ( V_29 & V_415 )
V_414 |= V_406 ;
if ( V_414 & V_406 ) {
if ( V_29 & V_418 )
V_414 |= V_412 ;
} else {
if ( V_29 & V_418 )
V_414 |= V_408 ;
if ( ! ( V_29 & V_420 ) )
V_414 |= V_409 ;
if ( V_29 & V_421 )
V_414 |= ( V_411 << 8 ) ;
V_414 |= V_29 & ( 0x7f << 8 ) ;
}
return V_414 ;
}
static void F_241 ( struct V_6 * V_7 , T_2 V_25 ,
int V_27 , int V_29 )
{
const T_2 * V_422 ;
F_242 ( V_7 , V_25 , 0 , V_27 , V_29 ) ;
V_422 = V_7 -> V_363 ;
if ( ! V_422 )
return;
for (; * V_422 ; V_422 ++ )
F_242 ( V_7 , * V_422 , 0 , V_27 , V_29 ) ;
}
static inline void F_243 ( struct V_6 * V_7 , T_2 V_25 ,
int V_423 , int V_424 )
{
if ( V_423 != - 1 )
F_241 ( V_7 , V_25 , V_425 , V_423 ) ;
if ( V_424 != - 1 )
F_241 ( V_7 , V_25 , V_426 , V_424 ) ;
}
static int F_244 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
int V_264 = V_307 -> V_346 ;
struct V_214 * V_413 ;
T_2 V_25 ;
unsigned short V_29 ;
int V_321 ;
F_2 ( & V_7 -> V_208 ) ;
V_413 = F_83 ( & V_7 -> V_190 , V_264 ) ;
V_25 = V_413 -> V_25 ;
V_413 -> V_405 = V_319 -> V_313 . V_404 . V_405 [ 0 ] |
( ( unsigned int ) V_319 -> V_313 . V_404 . V_405 [ 1 ] << 8 ) |
( ( unsigned int ) V_319 -> V_313 . V_404 . V_405 [ 2 ] << 16 ) |
( ( unsigned int ) V_319 -> V_313 . V_404 . V_405 [ 3 ] << 24 ) ;
V_29 = F_239 ( V_413 -> V_405 ) ;
V_29 |= V_413 -> V_427 & 1 ;
V_321 = V_413 -> V_427 != V_29 ;
V_413 -> V_427 = V_29 ;
if ( V_321 && V_25 != ( T_4 ) - 1 )
F_243 ( V_7 , V_25 , V_29 & 0xff , ( V_29 >> 8 ) & 0xff ) ;
F_4 ( & V_7 -> V_208 ) ;
return V_321 ;
}
static int F_245 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
int V_264 = V_307 -> V_346 ;
struct V_214 * V_413 ;
F_2 ( & V_7 -> V_208 ) ;
V_413 = F_83 ( & V_7 -> V_190 , V_264 ) ;
V_319 -> V_313 . integer . V_313 [ 0 ] = V_413 -> V_427 & V_428 ;
F_4 ( & V_7 -> V_208 ) ;
return 0 ;
}
static inline void F_246 ( struct V_6 * V_7 , T_2 V_25 ,
int V_423 , int V_424 )
{
F_243 ( V_7 , V_25 , V_423 , V_424 ) ;
if ( ( F_46 ( V_7 , V_25 ) & V_429 ) &&
( V_423 & V_428 ) )
F_167 ( V_7 , V_25 , V_273 , 0 ,
V_295 , 0 ) ;
}
static int F_247 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
int V_264 = V_307 -> V_346 ;
struct V_214 * V_413 ;
T_2 V_25 ;
unsigned short V_29 ;
int V_321 ;
F_2 ( & V_7 -> V_208 ) ;
V_413 = F_83 ( & V_7 -> V_190 , V_264 ) ;
V_25 = V_413 -> V_25 ;
V_29 = V_413 -> V_427 & ~ V_428 ;
if ( V_319 -> V_313 . integer . V_313 [ 0 ] )
V_29 |= V_428 ;
V_321 = V_413 -> V_427 != V_29 ;
V_413 -> V_427 = V_29 ;
if ( V_321 && V_25 != ( T_4 ) - 1 )
F_246 ( V_7 , V_25 , V_29 & 0xff , - 1 ) ;
F_4 ( & V_7 -> V_208 ) ;
return V_321 ;
}
int F_248 ( struct V_6 * V_7 ,
T_2 V_430 ,
T_2 V_431 ,
int type )
{
int V_33 ;
struct V_306 * V_341 ;
struct V_432 * V_433 ;
int V_264 = 0 ;
const int V_434 = 16 ;
struct V_214 * V_413 ;
struct V_9 * V_10 = V_7 -> V_10 ;
if ( V_10 -> V_435 == V_436 &&
type == V_437 ) {
V_264 = V_434 ;
} else if ( V_10 -> V_435 == V_437 &&
type == V_436 ) {
for ( V_433 = V_438 ; V_433 -> V_143 ; V_433 ++ ) {
V_341 = F_187 ( V_7 , V_433 -> V_143 , 0 , 0 ) ;
if ( ! V_341 )
break;
V_341 -> V_136 . V_280 = V_434 ;
}
V_10 -> V_435 = V_436 ;
}
if ( ! V_10 -> V_435 )
V_10 -> V_435 = type ;
V_264 = F_190 ( V_7 , L_68 , V_264 ) ;
if ( V_264 < 0 ) {
F_14 ( V_7 , L_69 ) ;
return - V_200 ;
}
V_413 = F_81 ( & V_7 -> V_190 ) ;
if ( ! V_413 )
return - V_54 ;
for ( V_433 = V_438 ; V_433 -> V_143 ; V_433 ++ ) {
V_341 = F_223 ( V_433 , V_7 ) ;
if ( ! V_341 )
return - V_54 ;
V_341 -> V_136 . V_280 = V_264 ;
V_341 -> V_346 = V_7 -> V_190 . V_175 - 1 ;
V_33 = F_191 ( V_7 , V_430 , V_341 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_413 -> V_25 = V_431 ;
V_413 -> V_427 = F_23 ( V_7 , V_431 , 0 ,
V_439 , 0 ) ;
V_413 -> V_405 = F_240 ( V_413 -> V_427 ) ;
return 0 ;
}
struct V_214 * F_249 ( struct V_6 * V_7 ,
T_2 V_25 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_190 . V_175 ; V_18 ++ ) {
struct V_214 * V_413 =
F_83 ( & V_7 -> V_190 , V_18 ) ;
if ( V_413 -> V_25 == V_25 )
return V_413 ;
}
return NULL ;
}
void F_250 ( struct V_6 * V_7 , int V_264 )
{
struct V_214 * V_413 ;
F_2 ( & V_7 -> V_208 ) ;
V_413 = F_83 ( & V_7 -> V_190 , V_264 ) ;
V_413 -> V_25 = ( T_4 ) - 1 ;
F_4 ( & V_7 -> V_208 ) ;
}
void F_251 ( struct V_6 * V_7 , int V_264 , T_2 V_25 )
{
struct V_214 * V_413 ;
unsigned short V_29 ;
F_2 ( & V_7 -> V_208 ) ;
V_413 = F_83 ( & V_7 -> V_190 , V_264 ) ;
if ( V_413 -> V_25 != V_25 ) {
V_413 -> V_25 = V_25 ;
V_29 = V_413 -> V_427 ;
F_246 ( V_7 , V_25 , V_29 & 0xff , ( V_29 >> 8 ) & 0xff ) ;
}
F_4 ( & V_7 -> V_208 ) ;
}
static int F_252 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_440 * V_441 = F_173 ( V_307 ) ;
V_319 -> V_313 . integer . V_313 [ 0 ] = V_441 -> V_442 ;
return 0 ;
}
static int F_253 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_440 * V_441 = F_173 ( V_307 ) ;
V_441 -> V_442 = ! ! V_319 -> V_313 . integer . V_313 [ 0 ] ;
return 0 ;
}
int F_254 ( struct V_6 * V_7 ,
struct V_440 * V_441 )
{
struct V_306 * V_341 ;
if ( ! V_441 -> V_443 )
return 0 ;
V_341 = F_223 ( & V_444 , V_441 ) ;
if ( ! V_341 )
return - V_54 ;
return F_191 ( V_7 , V_441 -> V_443 , V_341 ) ;
}
static int F_255 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
V_319 -> V_313 . integer . V_313 [ 0 ] = V_7 -> V_445 ;
return 0 ;
}
static int F_256 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
T_2 V_25 = V_307 -> V_346 ;
unsigned int V_29 = ! ! V_319 -> V_313 . integer . V_313 [ 0 ] ;
int V_321 ;
F_2 ( & V_7 -> V_208 ) ;
V_321 = V_7 -> V_445 != V_29 ;
if ( V_321 ) {
V_7 -> V_445 = V_29 ;
F_242 ( V_7 , V_25 , 0 ,
V_425 , V_29 ) ;
}
F_4 ( & V_7 -> V_208 ) ;
return V_321 ;
}
static int F_257 ( struct V_306 * V_307 ,
struct V_318 * V_319 )
{
struct V_6 * V_7 = F_173 ( V_307 ) ;
T_2 V_25 = V_307 -> V_346 ;
unsigned short V_29 ;
unsigned int V_414 ;
V_29 = F_23 ( V_7 , V_25 , 0 , V_439 , 0 ) ;
V_414 = F_240 ( V_29 ) ;
V_319 -> V_313 . V_404 . V_405 [ 0 ] = V_414 ;
V_319 -> V_313 . V_404 . V_405 [ 1 ] = V_414 >> 8 ;
V_319 -> V_313 . V_404 . V_405 [ 2 ] = V_414 >> 16 ;
V_319 -> V_313 . V_404 . V_405 [ 3 ] = V_414 >> 24 ;
return 0 ;
}
int F_258 ( struct V_6 * V_7 , T_2 V_25 )
{
int V_33 ;
struct V_306 * V_341 ;
struct V_432 * V_433 ;
int V_264 ;
V_264 = F_190 ( V_7 , L_70 , 0 ) ;
if ( V_264 < 0 ) {
F_14 ( V_7 , L_71 ) ;
return - V_200 ;
}
for ( V_433 = V_446 ; V_433 -> V_143 ; V_433 ++ ) {
V_341 = F_223 ( V_433 , V_7 ) ;
if ( ! V_341 )
return - V_54 ;
V_341 -> V_346 = V_25 ;
V_33 = F_191 ( V_7 , V_25 , V_341 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_7 -> V_445 =
F_23 ( V_7 , V_25 , 0 ,
V_439 , 0 ) &
V_428 ;
return 0 ;
}
int F_242 ( struct V_6 * V_7 , T_2 V_25 ,
int V_26 , unsigned int V_27 , unsigned int V_28 )
{
int V_33 ;
struct V_212 * V_145 ;
T_1 V_263 ;
unsigned int V_299 ;
V_299 = V_7 -> V_300 ;
if ( ! V_299 ) {
V_33 = F_24 ( V_7 , V_25 , V_26 , V_27 , V_28 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_27 = V_27 | ( V_28 >> 8 ) ;
V_28 &= 0xff ;
V_263 = F_259 ( V_25 , V_27 ) ;
F_2 ( & V_7 -> V_10 -> V_35 ) ;
V_145 = F_148 ( & V_7 -> V_192 , V_263 ) ;
if ( V_145 ) {
V_145 -> V_29 = V_28 ;
V_145 -> V_254 = V_299 ;
}
F_4 ( & V_7 -> V_10 -> V_35 ) ;
return 0 ;
}
int F_260 ( struct V_6 * V_7 , T_2 V_25 ,
int V_26 , unsigned int V_27 , unsigned int V_28 )
{
struct V_212 * V_145 ;
T_1 V_263 ;
V_27 = V_27 | ( V_28 >> 8 ) ;
V_28 &= 0xff ;
V_263 = F_259 ( V_25 , V_27 ) ;
F_2 ( & V_7 -> V_10 -> V_35 ) ;
V_145 = F_147 ( & V_7 -> V_192 , V_263 ) ;
if ( V_145 && V_145 -> V_29 == V_28 ) {
F_4 ( & V_7 -> V_10 -> V_35 ) ;
return 0 ;
}
F_4 ( & V_7 -> V_10 -> V_35 ) ;
return F_242 ( V_7 , V_25 , V_26 , V_27 , V_28 ) ;
}
void F_261 ( struct V_6 * V_7 )
{
int V_18 ;
F_2 ( & V_7 -> V_210 ) ;
V_7 -> V_300 = 0 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_192 . V_262 . V_175 ; V_18 ++ ) {
struct V_212 * V_302 ;
T_1 V_263 ;
V_302 = F_83 ( & V_7 -> V_192 . V_262 , V_18 ) ;
V_263 = V_302 -> V_263 ;
if ( ! V_263 )
continue;
if ( ! V_302 -> V_254 )
continue;
V_302 -> V_254 = 0 ;
F_4 ( & V_7 -> V_210 ) ;
F_24 ( V_7 , F_262 ( V_263 ) , 0 ,
F_263 ( V_263 ) , V_302 -> V_29 ) ;
F_2 ( & V_7 -> V_210 ) ;
}
F_4 ( & V_7 -> V_210 ) ;
}
void F_264 ( struct V_6 * V_7 ,
const struct V_45 * V_46 )
{
for (; V_46 -> V_25 ; V_46 ++ )
F_242 ( V_7 , V_46 -> V_25 , 0 , V_46 -> V_27 ,
V_46 -> V_47 ) ;
}
void F_265 ( struct V_6 * V_7 )
{
F_170 ( V_7 ) ;
F_261 ( V_7 ) ;
}
void F_266 ( struct V_6 * V_7 , T_2 V_197 ,
unsigned int V_447 )
{
T_2 V_25 = V_7 -> V_164 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_163 ; V_18 ++ , V_25 ++ ) {
unsigned int V_63 = F_46 ( V_7 , V_25 ) ;
unsigned int V_448 = V_447 ;
if ( ! ( V_63 & V_449 ) )
continue;
if ( V_7 -> V_450 ) {
V_448 = V_7 -> V_450 ( V_7 , V_25 , V_447 ) ;
if ( V_448 != V_447 && V_447 == V_451 )
continue;
}
F_24 ( V_7 , V_25 , 0 , V_452 ,
V_448 ) ;
}
}
static bool F_126 ( struct V_6 * V_7 , T_2 V_197 ,
unsigned int V_447 )
{
int V_453 = F_27 ( V_7 , V_197 , V_454 ) ;
if ( V_453 == - 1 )
return false ;
if ( V_453 & V_447 )
return true ;
else
return false ;
}
static unsigned int F_267 ( struct V_6 * V_7 ,
T_2 V_197 ,
unsigned int V_447 )
{
unsigned long V_455 = V_456 + F_268 ( 500 ) ;
unsigned int V_448 , V_457 ;
for (; ; ) {
V_448 = F_23 ( V_7 , V_197 , 0 ,
V_458 , 0 ) ;
if ( V_448 & V_459 )
break;
V_457 = ( V_448 >> 4 ) & 0x0f ;
if ( V_457 == V_447 )
break;
if ( F_269 ( V_456 , V_455 ) )
break;
F_141 ( 1 ) ;
}
return V_448 ;
}
unsigned int F_270 ( struct V_6 * V_7 ,
T_2 V_25 ,
unsigned int V_447 )
{
if ( V_25 == V_7 -> V_137 || V_25 == V_7 -> V_138 )
return V_447 ;
if ( V_447 == V_451 &&
F_47 ( F_46 ( V_7 , V_25 ) ) == V_83 &&
( F_158 ( V_7 , V_25 ) & V_460 ) ) {
int V_461 = F_23 ( V_7 , V_25 , 0 ,
V_462 , 0 ) ;
if ( V_461 & 0x02 )
return V_234 ;
}
return V_447 ;
}
static unsigned int F_127 ( struct V_6 * V_7 ,
unsigned int V_447 )
{
T_2 V_197 = V_7 -> V_137 ? V_7 -> V_137 : V_7 -> V_138 ;
int V_312 ;
unsigned int V_448 ;
int V_26 = 0 ;
if ( V_447 == V_451 ) {
if ( V_7 -> V_218 < 0 )
F_141 ( V_7 -> V_231 ? 10 : 100 ) ;
else if ( V_7 -> V_218 > 0 )
F_141 ( V_7 -> V_218 ) ;
V_26 = V_36 ;
}
for ( V_312 = 0 ; V_312 < 10 ; V_312 ++ ) {
if ( V_7 -> V_106 . V_463 )
V_7 -> V_106 . V_463 ( V_7 , V_197 ,
V_447 ) ;
else {
V_448 = V_447 ;
if ( V_7 -> V_450 )
V_448 = V_7 -> V_450 ( V_7 , V_197 , V_448 ) ;
if ( V_448 == V_447 || V_447 != V_451 )
F_23 ( V_7 , V_197 , V_26 ,
V_452 ,
V_448 ) ;
F_266 ( V_7 , V_197 , V_447 ) ;
}
V_448 = F_267 ( V_7 , V_197 , V_447 ) ;
if ( ! ( V_448 & V_459 ) )
break;
}
return V_448 ;
}
static void F_271 ( struct V_6 * V_7 )
{
T_2 V_25 = V_7 -> V_164 ;
int V_18 ;
if ( ! V_7 -> V_450 )
return;
for ( V_18 = 0 ; V_18 < V_7 -> V_163 ; V_18 ++ , V_25 ++ ) {
unsigned int V_63 = F_46 ( V_7 , V_25 ) ;
unsigned int V_179 ;
if ( ! ( V_63 & V_449 ) )
continue;
V_179 = V_7 -> V_450 ( V_7 , V_25 , V_234 ) ;
if ( V_179 == V_234 )
continue;
if ( ! F_272 ( V_7 , V_25 , V_179 ) )
F_24 ( V_7 , V_25 , 0 ,
V_452 , V_179 ) ;
}
}
static void F_273 ( struct V_6 * V_7 )
{
if ( V_7 -> V_464 . V_4 )
F_25 ( V_7 , V_7 -> V_464 . V_4 ) ;
}
static inline void F_273 ( struct V_6 * V_7 ) {}
static unsigned int F_274 ( struct V_6 * V_7 , bool V_465 )
{
unsigned int V_448 ;
V_7 -> V_466 = 1 ;
if ( V_7 -> V_106 . V_467 )
V_7 -> V_106 . V_467 ( V_7 ) ;
F_146 ( V_7 ) ;
V_448 = F_127 ( V_7 , V_451 ) ;
if ( ! V_465 )
F_102 ( & V_7 -> V_187 ) ;
F_198 ( & V_7 -> V_221 ) ;
F_275 ( V_7 ) ;
F_276 ( V_7 ) ;
V_7 -> V_468 = 0 ;
V_7 -> V_469 = 0 ;
V_7 -> V_470 = V_456 ;
F_199 ( & V_7 -> V_221 ) ;
V_7 -> V_466 = 0 ;
return V_448 ;
}
static void F_277 ( struct V_6 * V_7 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_192 . V_262 . V_175 ; V_18 ++ ) {
struct V_212 * V_31 ;
V_31 = F_83 ( & V_7 -> V_192 . V_262 , V_18 ) ;
V_31 -> V_254 = 1 ;
}
for ( V_18 = 0 ; V_18 < V_7 -> V_191 . V_262 . V_175 ; V_18 ++ ) {
struct V_211 * V_471 ;
V_471 = F_83 ( & V_7 -> V_191 . V_262 , V_18 ) ;
V_471 -> V_269 . V_254 = 1 ;
}
}
static void F_278 ( struct V_6 * V_7 )
{
V_7 -> V_466 = 1 ;
F_277 ( V_7 ) ;
F_8 ( V_7 ) ;
F_127 ( V_7 , V_234 ) ;
F_91 ( V_7 ) ;
F_273 ( V_7 ) ;
F_93 ( V_7 ) ;
if ( V_7 -> V_106 . V_472 )
V_7 -> V_106 . V_472 ( V_7 ) ;
else {
if ( V_7 -> V_106 . V_473 )
V_7 -> V_106 . V_473 ( V_7 ) ;
F_170 ( V_7 ) ;
F_261 ( V_7 ) ;
}
if ( V_7 -> V_183 )
F_92 ( & V_7 -> V_182 . V_101 ) ;
else
F_279 ( V_7 ) ;
V_7 -> V_466 = 0 ;
F_19 ( V_7 ) ;
}
int F_280 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_29 (codec, &bus->codec_list, list) {
int V_33 = F_281 ( V_7 ) ;
if ( V_33 < 0 ) {
F_14 ( V_7 ,
L_72 ,
V_7 -> V_30 , V_33 ) ;
V_33 = F_201 ( V_7 ) ;
if ( V_33 < 0 ) {
F_14 ( V_7 ,
L_73 ) ;
return V_33 ;
}
}
}
return 0 ;
}
static int F_282 ( struct V_6 * V_7 )
{
int V_18 , V_474 , V_33 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_354 ; V_18 ++ ) {
for ( V_474 = 0 ; V_474 < 2 ; V_474 ++ ) {
struct V_475 * V_353 = V_7 -> V_357 [ V_18 ] . V_353 ;
struct V_476 * V_477 =
& V_7 -> V_357 [ V_18 ] . V_478 [ V_474 ] ;
struct V_479 * V_480 ;
const struct V_481 * V_482 ;
if ( V_7 -> V_357 [ V_18 ] . V_483 )
continue;
if ( ! V_353 || ! V_477 -> V_484 )
continue;
V_482 = V_477 -> V_480 ? V_477 -> V_480 : V_485 ;
V_33 = F_283 ( V_353 , V_474 , V_482 ,
V_477 -> V_486 ,
0 , & V_480 ) ;
if ( V_33 < 0 )
return V_33 ;
V_480 -> V_487 = V_488 ;
}
}
return 0 ;
}
int F_281 ( struct V_6 * V_7 )
{
int V_33 = 0 ;
F_273 ( V_7 ) ;
if ( V_7 -> V_106 . V_473 )
V_33 = V_7 -> V_106 . V_473 ( V_7 ) ;
if ( ! V_33 && V_7 -> V_106 . V_489 )
V_33 = V_7 -> V_106 . V_489 ( V_7 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_282 ( V_7 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_7 -> V_183 )
F_92 ( & V_7 -> V_182 . V_101 ) ;
else
F_279 ( V_7 ) ;
F_271 ( V_7 ) ;
return 0 ;
}
unsigned int F_284 ( struct V_6 * V_7 ,
unsigned int V_490 ,
unsigned int V_491 ,
unsigned int V_248 ,
unsigned int V_492 ,
unsigned short V_493 )
{
int V_18 ;
unsigned int V_29 = 0 ;
for ( V_18 = 0 ; V_494 [ V_18 ] . V_495 ; V_18 ++ )
if ( V_494 [ V_18 ] . V_495 == V_490 ) {
V_29 = V_494 [ V_18 ] . V_496 ;
break;
}
if ( ! V_494 [ V_18 ] . V_495 ) {
F_21 ( V_7 , L_74 , V_490 ) ;
return 0 ;
}
if ( V_491 == 0 || V_491 > 8 ) {
F_21 ( V_7 , L_75 , V_491 ) ;
return 0 ;
}
V_29 |= V_491 - 1 ;
switch ( F_285 ( V_248 ) ) {
case 8 :
V_29 |= V_497 ;
break;
case 16 :
V_29 |= V_498 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_492 >= 32 || V_248 == V_499 )
V_29 |= V_500 ;
else if ( V_492 >= 24 )
V_29 |= V_501 ;
else
V_29 |= V_502 ;
break;
default:
F_21 ( V_7 , L_76 ,
F_285 ( V_248 ) ) ;
return 0 ;
}
if ( V_493 & V_416 )
V_29 |= V_503 ;
return V_29 ;
}
static unsigned int F_286 ( struct V_6 * V_7 , T_2 V_25 ,
int V_276 )
{
unsigned int V_29 = 0 ;
if ( V_25 != V_7 -> V_137 &&
( F_46 ( V_7 , V_25 ) & V_504 ) )
V_29 = F_27 ( V_7 , V_25 , V_505 ) ;
if ( ! V_29 || V_29 == - 1 )
V_29 = F_27 ( V_7 , V_7 -> V_137 , V_505 ) ;
if ( ! V_29 || V_29 == - 1 )
return 0 ;
return V_29 ;
}
static unsigned int F_287 ( struct V_6 * V_7 , T_2 V_25 )
{
return F_154 ( V_7 , V_25 , 0 , F_288 ( V_25 ) ,
F_286 ) ;
}
static unsigned int F_289 ( struct V_6 * V_7 , T_2 V_25 ,
int V_276 )
{
unsigned int V_358 = F_27 ( V_7 , V_25 , V_506 ) ;
if ( ! V_358 || V_358 == - 1 )
V_358 = F_27 ( V_7 , V_7 -> V_137 , V_506 ) ;
if ( ! V_358 || V_358 == - 1 )
return 0 ;
return V_358 ;
}
static unsigned int F_290 ( struct V_6 * V_7 , T_2 V_25 )
{
return F_154 ( V_7 , V_25 , 0 , F_291 ( V_25 ) ,
F_289 ) ;
}
int F_292 ( struct V_6 * V_7 , T_2 V_25 ,
T_1 * V_507 , T_8 * V_508 , unsigned int * V_509 )
{
unsigned int V_18 , V_29 , V_63 ;
V_63 = F_46 ( V_7 , V_25 ) ;
V_29 = F_287 ( V_7 , V_25 ) ;
if ( V_507 ) {
T_1 V_510 = 0 ;
for ( V_18 = 0 ; V_18 < V_511 ; V_18 ++ ) {
if ( V_29 & ( 1 << V_18 ) )
V_510 |= V_494 [ V_18 ] . V_512 ;
}
if ( V_510 == 0 ) {
F_14 ( V_7 ,
L_77 ,
V_25 , V_29 ,
( V_63 & V_504 ) ? 1 : 0 ) ;
return - V_76 ;
}
* V_507 = V_510 ;
}
if ( V_508 || V_509 ) {
T_8 V_513 = 0 ;
unsigned int V_358 , V_514 ;
V_358 = F_290 ( V_7 , V_25 ) ;
if ( ! V_358 )
return - V_76 ;
V_514 = 0 ;
if ( V_358 & V_515 ) {
if ( V_29 & V_516 ) {
V_513 |= V_517 ;
V_514 = 8 ;
}
if ( V_29 & V_518 ) {
V_513 |= V_519 ;
V_514 = 16 ;
}
if ( V_63 & V_86 ) {
if ( V_29 & V_520 )
V_513 |= V_521 ;
if ( V_29 & ( V_522 | V_523 ) )
V_513 |= V_524 ;
if ( V_29 & V_523 )
V_514 = 24 ;
else if ( V_29 & V_522 )
V_514 = 20 ;
} else if ( V_29 & ( V_522 | V_523 |
V_520 ) ) {
V_513 |= V_524 ;
if ( V_29 & V_520 )
V_514 = 32 ;
else if ( V_29 & V_523 )
V_514 = 24 ;
else if ( V_29 & V_522 )
V_514 = 20 ;
}
}
#if 0
if (streams & AC_SUPFMT_FLOAT32) {
formats |= SNDRV_PCM_FMTBIT_FLOAT_LE;
if (!bps)
bps = 32;
}
#endif
if ( V_358 == V_525 ) {
V_513 |= V_517 ;
V_514 = 8 ;
}
if ( V_513 == 0 ) {
F_14 ( V_7 ,
L_78 ,
V_25 , V_29 ,
( V_63 & V_504 ) ? 1 : 0 ,
V_358 ) ;
return - V_76 ;
}
if ( V_508 )
* V_508 = V_513 ;
if ( V_509 )
* V_509 = V_514 ;
}
return 0 ;
}
int F_293 ( struct V_6 * V_7 , T_2 V_25 ,
unsigned int V_248 )
{
int V_18 ;
unsigned int V_29 = 0 , V_490 , V_478 ;
V_29 = F_287 ( V_7 , V_25 ) ;
if ( ! V_29 )
return 0 ;
V_490 = V_248 & 0xff00 ;
for ( V_18 = 0 ; V_18 < V_511 ; V_18 ++ )
if ( V_494 [ V_18 ] . V_496 == V_490 ) {
if ( V_29 & ( 1 << V_18 ) )
break;
return 0 ;
}
if ( V_18 >= V_511 )
return 0 ;
V_478 = F_290 ( V_7 , V_25 ) ;
if ( ! V_478 )
return 0 ;
if ( V_478 & V_515 ) {
switch ( V_248 & 0xf0 ) {
case 0x00 :
if ( ! ( V_29 & V_516 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_29 & V_518 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_29 & V_522 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_29 & V_523 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_29 & V_520 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_294 ( struct V_476 * V_477 ,
struct V_6 * V_7 ,
struct V_526 * V_527 )
{
return 0 ;
}
static int F_295 ( struct V_476 * V_477 ,
struct V_6 * V_7 ,
unsigned int V_242 ,
unsigned int V_248 ,
struct V_526 * V_527 )
{
F_142 ( V_7 , V_477 -> V_25 , V_242 , 0 , V_248 ) ;
return 0 ;
}
static int F_296 ( struct V_476 * V_477 ,
struct V_6 * V_7 ,
struct V_526 * V_527 )
{
F_297 ( V_7 , V_477 -> V_25 ) ;
return 0 ;
}
static int F_298 ( struct V_6 * V_7 ,
struct V_476 * V_266 )
{
int V_33 ;
if ( V_266 -> V_25 && ( ! V_266 -> V_510 || ! V_266 -> V_513 ) ) {
V_33 = F_292 ( V_7 , V_266 -> V_25 ,
V_266 -> V_510 ? NULL : & V_266 -> V_510 ,
V_266 -> V_513 ? NULL : & V_266 -> V_513 ,
V_266 -> V_492 ? NULL : & V_266 -> V_492 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_266 -> V_12 . V_528 == NULL )
V_266 -> V_12 . V_528 = F_294 ;
if ( V_266 -> V_12 . V_529 == NULL )
V_266 -> V_12 . V_529 = F_294 ;
if ( V_266 -> V_12 . V_530 == NULL ) {
if ( F_43 ( ! V_266 -> V_25 ) )
return - V_61 ;
V_266 -> V_12 . V_530 = F_295 ;
}
if ( V_266 -> V_12 . V_531 == NULL ) {
if ( F_43 ( ! V_266 -> V_25 ) )
return - V_61 ;
V_266 -> V_12 . V_531 = F_296 ;
}
return 0 ;
}
int F_299 ( struct V_6 * V_7 ,
struct V_476 * V_477 ,
unsigned int V_478 ,
unsigned int V_248 ,
struct V_526 * V_527 )
{
int V_301 ;
F_2 ( & V_7 -> V_10 -> V_128 ) ;
V_301 = V_477 -> V_12 . V_530 ( V_477 , V_7 , V_478 , V_248 , V_527 ) ;
if ( V_301 >= 0 )
F_145 ( V_7 ) ;
F_4 ( & V_7 -> V_10 -> V_128 ) ;
return V_301 ;
}
void F_300 ( struct V_6 * V_7 ,
struct V_476 * V_477 ,
struct V_526 * V_527 )
{
F_2 ( & V_7 -> V_10 -> V_128 ) ;
V_477 -> V_12 . V_531 ( V_477 , V_7 , V_527 ) ;
F_4 ( & V_7 -> V_10 -> V_128 ) ;
}
static int F_301 ( struct V_9 * V_10 , unsigned int type )
{
static int V_532 [ V_533 ] [ 5 ] = {
[ V_534 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_437 ] = { 1 , - 1 } ,
[ V_436 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_535 ] = { 6 , - 1 } ,
} ;
int V_18 ;
if ( type >= V_533 ) {
F_59 ( V_10 -> V_108 -> V_109 , L_79 , type ) ;
return - V_61 ;
}
for ( V_18 = 0 ; V_532 [ type ] [ V_18 ] >= 0 ; V_18 ++ ) {
#ifndef F_302
if ( V_532 [ type ] [ V_18 ] >= 8 )
break;
#endif
if ( ! F_303 ( V_532 [ type ] [ V_18 ] , V_10 -> V_360 ) )
return V_532 [ type ] [ V_18 ] ;
}
#ifdef F_302
for ( V_18 = 10 ; V_18 < 32 ; V_18 ++ ) {
if ( ! F_303 ( V_18 , V_10 -> V_360 ) )
return V_18 ;
}
#endif
F_304 ( V_10 -> V_108 -> V_109 , L_80 ,
V_536 [ type ] ) ;
#ifndef F_302
F_304 ( V_10 -> V_108 -> V_109 ,
L_81 ) ;
#endif
return - V_39 ;
}
static int F_305 ( struct V_6 * V_7 , struct V_355 * V_353 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_476 * V_266 ;
int V_478 , V_33 ;
if ( F_43 ( ! V_353 -> V_143 ) )
return - V_61 ;
for ( V_478 = 0 ; V_478 < 2 ; V_478 ++ ) {
V_266 = & V_353 -> V_478 [ V_478 ] ;
if ( V_266 -> V_484 ) {
V_33 = F_298 ( V_7 , V_266 ) ;
if ( V_33 < 0 )
return V_33 ;
}
}
return V_10 -> V_12 . V_537 ( V_10 , V_7 , V_353 ) ;
}
int F_306 ( struct V_6 * V_7 )
{
unsigned int V_353 ;
int V_33 ;
if ( ! V_7 -> V_354 ) {
if ( ! V_7 -> V_106 . V_538 )
return 0 ;
V_33 = V_7 -> V_106 . V_538 ( V_7 ) ;
if ( V_33 < 0 ) {
F_14 ( V_7 ,
L_82 ,
V_7 -> V_30 , V_33 ) ;
V_33 = F_201 ( V_7 ) ;
if ( V_33 < 0 ) {
F_14 ( V_7 ,
L_73 ) ;
return V_33 ;
}
}
}
for ( V_353 = 0 ; V_353 < V_7 -> V_354 ; V_353 ++ ) {
struct V_355 * V_356 = & V_7 -> V_357 [ V_353 ] ;
int V_109 ;
if ( ! V_356 -> V_478 [ 0 ] . V_484 && ! V_356 -> V_478 [ 1 ] . V_484 )
continue;
if ( ! V_356 -> V_353 ) {
V_109 = F_301 ( V_7 -> V_10 , V_356 -> V_539 ) ;
if ( V_109 < 0 )
continue;
V_356 -> V_113 = V_109 ;
V_33 = F_305 ( V_7 , V_356 ) ;
if ( V_33 < 0 ) {
F_14 ( V_7 ,
L_83 ,
V_109 , V_7 -> V_30 ) ;
continue;
}
}
}
return 0 ;
}
int F_307 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_29 (codec, &bus->codec_list, list) {
int V_33 = F_306 ( V_7 ) ;
if ( V_33 < 0 )
return V_33 ;
}
return 0 ;
}
int F_308 ( struct V_6 * V_7 ,
int V_540 , const char * const * V_541 ,
const struct V_542 * V_133 )
{
if ( V_7 -> V_126 && V_541 ) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_540 ; V_18 ++ ) {
if ( V_541 [ V_18 ] &&
! strcmp ( V_7 -> V_126 , V_541 [ V_18 ] ) ) {
F_309 ( V_7 , L_84 ,
V_541 [ V_18 ] ) ;
return V_18 ;
}
}
}
if ( ! V_7 -> V_10 -> V_125 || ! V_133 )
return - 1 ;
V_133 = F_310 ( V_7 -> V_10 -> V_125 , V_133 ) ;
if ( ! V_133 )
return - 1 ;
if ( V_133 -> V_313 >= 0 && V_133 -> V_313 < V_540 ) {
#ifdef F_311
char V_147 [ 10 ] ;
const char * V_543 = NULL ;
if ( V_541 )
V_543 = V_541 [ V_133 -> V_313 ] ;
if ( ! V_543 ) {
sprintf ( V_147 , L_85 , V_133 -> V_313 ) ;
V_543 = V_147 ;
}
F_309 ( V_7 , L_86 ,
V_543 , V_133 -> V_544 , V_133 -> V_343 ,
( V_133 -> V_143 ? V_133 -> V_143 : L_87 ) ) ;
#endif
return V_133 -> V_313 ;
}
return - 1 ;
}
int F_312 ( struct V_6 * V_7 ,
int V_540 , const char * const * V_541 ,
const struct V_542 * V_133 )
{
const struct V_542 * V_257 ;
for ( V_257 = V_133 ; V_257 -> V_544 ; V_257 ++ ) {
unsigned int V_70 = 0xffff0000 | V_257 -> V_545 ;
unsigned int V_136 = ( V_257 -> V_343 | ( V_257 -> V_544 << 16 ) ) & V_70 ;
if ( ( V_7 -> V_225 & V_70 ) == V_136 )
break;
}
if ( ! V_257 -> V_544 )
return - 1 ;
V_133 = V_257 ;
if ( V_133 -> V_313 >= 0 && V_133 -> V_313 < V_540 ) {
#ifdef F_311
char V_147 [ 10 ] ;
const char * V_543 = NULL ;
if ( V_541 )
V_543 = V_541 [ V_133 -> V_313 ] ;
if ( ! V_543 ) {
sprintf ( V_147 , L_85 , V_133 -> V_313 ) ;
V_543 = V_147 ;
}
F_309 ( V_7 , L_86 ,
V_543 , V_133 -> V_544 , V_133 -> V_343 ,
( V_133 -> V_143 ? V_133 -> V_143 : L_87 ) ) ;
#endif
return V_133 -> V_313 ;
}
return - 1 ;
}
int F_313 ( struct V_6 * V_7 ,
const struct V_432 * V_546 )
{
int V_33 ;
for (; V_546 -> V_143 ; V_546 ++ ) {
struct V_306 * V_341 ;
int V_30 = 0 , V_264 = 0 ;
if ( V_546 -> V_338 == - 1 )
continue;
for (; ; ) {
V_341 = F_223 ( V_546 , V_7 ) ;
if ( ! V_341 )
return - V_54 ;
if ( V_30 > 0 )
V_341 -> V_136 . V_113 = V_30 ;
if ( V_264 > 0 )
V_341 -> V_136 . V_280 = V_264 ;
V_33 = F_191 ( V_7 , 0 , V_341 ) ;
if ( ! V_33 )
break;
if ( ! V_30 && V_7 -> V_30 )
V_30 = V_7 -> V_30 ;
else if ( ! V_264 && ! V_546 -> V_280 ) {
V_264 = F_190 ( V_7 ,
V_546 -> V_143 , 0 ) ;
if ( V_264 <= 0 )
return V_33 ;
} else
return V_33 ;
}
}
return 0 ;
}
static void V_222 ( struct V_102 * V_101 )
{
struct V_6 * V_7 =
F_56 ( V_101 , struct V_6 , V_187 . V_101 ) ;
struct V_9 * V_10 = V_7 -> V_10 ;
unsigned int V_448 ;
F_198 ( & V_7 -> V_221 ) ;
if ( V_7 -> V_469 > 0 ) {
F_199 ( & V_7 -> V_221 ) ;
return;
}
if ( ! V_7 -> V_468 || V_7 -> V_547 ) {
V_7 -> V_469 = 0 ;
F_199 ( & V_7 -> V_221 ) ;
return;
}
F_199 ( & V_7 -> V_221 ) ;
V_448 = F_274 ( V_7 , true ) ;
if ( ! V_10 -> V_233 && ( V_448 & V_548 ) )
F_7 ( V_7 , false ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
F_198 ( & V_7 -> V_221 ) ;
V_7 -> V_547 ++ ;
V_7 -> V_468 = 1 ;
V_7 -> V_470 = V_456 ;
F_199 ( & V_7 -> V_221 ) ;
F_7 ( V_7 , true ) ;
}
void F_275 ( struct V_6 * V_7 )
{
unsigned long V_549 = V_456 - V_7 -> V_470 ;
if ( V_7 -> V_468 )
V_7 -> V_550 += V_549 ;
else
V_7 -> V_551 += V_549 ;
V_7 -> V_470 += V_549 ;
}
static void F_314 ( struct V_6 * V_7 , bool V_552 )
{
if ( ( V_7 -> V_468 || V_7 -> V_469 > 0 ) &&
! ( V_552 && V_7 -> V_469 < 0 ) )
return;
F_199 ( & V_7 -> V_221 ) ;
F_102 ( & V_7 -> V_187 ) ;
F_198 ( & V_7 -> V_221 ) ;
if ( V_7 -> V_468 ) {
if ( V_7 -> V_469 < 0 )
V_7 -> V_469 = 0 ;
return;
}
F_315 ( V_7 ) ;
F_275 ( V_7 ) ;
V_7 -> V_468 = 1 ;
V_7 -> V_470 = V_456 ;
V_7 -> V_469 = 1 ;
F_199 ( & V_7 -> V_221 ) ;
F_278 ( V_7 ) ;
F_198 ( & V_7 -> V_221 ) ;
V_7 -> V_469 = 0 ;
}
static void F_316 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_468 || V_7 -> V_547 || V_7 -> V_469 )
return;
if ( V_127 ( V_7 ) ) {
V_7 -> V_469 = - 1 ;
F_95 ( V_7 -> V_10 -> V_98 , & V_7 -> V_187 ,
F_268 ( V_127 ( V_7 ) * 1000 ) ) ;
}
}
void F_317 ( struct V_6 * V_7 , int V_549 , bool V_553 )
{
F_198 ( & V_7 -> V_221 ) ;
V_7 -> V_547 += V_549 ;
F_318 ( V_7 ) ;
if ( V_549 > 0 )
F_314 ( V_7 , V_553 ) ;
else
F_316 ( V_7 ) ;
F_199 ( & V_7 -> V_221 ) ;
}
int F_319 ( struct V_6 * V_7 ,
struct V_554 * V_555 ,
T_2 V_25 )
{
const struct V_556 * V_51 ;
int V_279 , V_557 ;
if ( ! V_555 -> V_558 )
return 0 ;
for ( V_51 = V_555 -> V_558 ; V_51 -> V_25 ; V_51 ++ ) {
if ( V_51 -> V_25 == V_25 )
break;
}
if ( ! V_51 -> V_25 )
return 0 ;
for ( V_51 = V_555 -> V_558 ; V_51 -> V_25 ; V_51 ++ ) {
for ( V_279 = 0 ; V_279 < 2 ; V_279 ++ ) {
V_557 = F_164 ( V_7 , V_51 -> V_25 , V_279 , V_51 -> V_276 ,
V_51 -> V_264 ) ;
if ( ! ( V_557 & V_295 ) && V_557 > 0 ) {
if ( ! V_555 -> V_468 ) {
V_555 -> V_468 = 1 ;
F_16 ( V_7 ) ;
}
return 1 ;
}
}
}
if ( V_555 -> V_468 ) {
V_555 -> V_468 = 0 ;
F_19 ( V_7 ) ;
}
return 0 ;
}
int F_320 ( struct V_6 * V_7 ,
struct V_308 * V_309 ,
const struct V_559 * V_560 ,
int V_561 )
{
V_309 -> type = V_384 ;
V_309 -> V_312 = 1 ;
V_309 -> V_313 . V_385 . V_348 = V_561 ;
if ( V_309 -> V_313 . V_385 . V_342 >= V_561 )
V_309 -> V_313 . V_385 . V_342 = V_561 - 1 ;
sprintf ( V_309 -> V_313 . V_385 . V_143 , L_88 ,
V_560 [ V_309 -> V_313 . V_385 . V_342 ] . V_491 ) ;
return 0 ;
}
int F_321 ( struct V_6 * V_7 ,
struct V_318 * V_319 ,
const struct V_559 * V_560 ,
int V_561 ,
int V_562 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_561 ; V_18 ++ ) {
if ( V_562 == V_560 [ V_18 ] . V_491 ) {
V_319 -> V_313 . V_385 . V_342 [ 0 ] = V_18 ;
break;
}
}
return 0 ;
}
int F_322 ( struct V_6 * V_7 ,
struct V_318 * V_319 ,
const struct V_559 * V_560 ,
int V_561 ,
int * V_563 )
{
unsigned int V_564 ;
V_564 = V_319 -> V_313 . V_385 . V_342 [ 0 ] ;
if ( V_564 >= V_561 )
return - V_61 ;
if ( * V_563 == V_560 [ V_564 ] . V_491 )
return 0 ;
* V_563 = V_560 [ V_564 ] . V_491 ;
if ( V_560 [ V_564 ] . V_565 )
F_264 ( V_7 , V_560 [ V_564 ] . V_565 ) ;
return 1 ;
}
int F_323 ( const struct V_566 * V_567 ,
struct V_308 * V_309 )
{
unsigned int V_280 ;
V_309 -> type = V_384 ;
V_309 -> V_312 = 1 ;
V_309 -> V_313 . V_385 . V_348 = V_567 -> V_568 ;
if ( ! V_567 -> V_568 )
return 0 ;
V_280 = V_309 -> V_313 . V_385 . V_342 ;
if ( V_280 >= V_567 -> V_568 )
V_280 = V_567 -> V_568 - 1 ;
strcpy ( V_309 -> V_313 . V_385 . V_143 , V_567 -> V_348 [ V_280 ] . V_569 ) ;
return 0 ;
}
int F_324 ( struct V_6 * V_7 ,
const struct V_566 * V_567 ,
struct V_318 * V_319 ,
T_2 V_25 ,
unsigned int * V_570 )
{
unsigned int V_264 ;
if ( ! V_567 -> V_568 )
return 0 ;
V_264 = V_319 -> V_313 . V_385 . V_342 [ 0 ] ;
if ( V_264 >= V_567 -> V_568 )
V_264 = V_567 -> V_568 - 1 ;
if ( * V_570 == V_264 )
return 0 ;
F_242 ( V_7 , V_25 , 0 , V_571 ,
V_567 -> V_348 [ V_264 ] . V_280 ) ;
* V_570 = V_264 ;
return 1 ;
}
int F_325 ( struct V_306 * V_307 ,
struct V_308 * V_309 ,
int V_568 , const char * const * V_383 )
{
static const char * const V_572 [] = {
L_89 , L_90
} ;
if ( ! V_383 || ! V_568 ) {
V_568 = 2 ;
V_383 = V_572 ;
}
V_309 -> type = V_384 ;
V_309 -> V_312 = 1 ;
V_309 -> V_313 . V_385 . V_348 = V_568 ;
if ( V_309 -> V_313 . V_385 . V_342 >= V_309 -> V_313 . V_385 . V_348 )
V_309 -> V_313 . V_385 . V_342 = V_309 -> V_313 . V_385 . V_348 - 1 ;
strcpy ( V_309 -> V_313 . V_385 . V_143 ,
V_383 [ V_309 -> V_313 . V_385 . V_342 ] ) ;
return 0 ;
}
static void F_326 ( struct V_6 * V_7 , T_2 V_25 ,
unsigned int V_242 , unsigned int V_248 )
{
struct V_214 * V_413 ;
unsigned int V_573 ;
bool V_574 ;
V_413 = F_249 ( V_7 , V_25 ) ;
V_573 = F_23 ( V_7 , V_25 , 0 ,
V_250 , 0 ) ;
V_574 = V_7 -> V_364 &&
( V_413 -> V_427 & V_428 ) &&
V_573 != V_248 ;
if ( V_574 )
F_243 ( V_7 , V_25 ,
V_413 -> V_427 & ~ V_428 & 0xff ,
- 1 ) ;
F_142 ( V_7 , V_25 , V_242 , 0 , V_248 ) ;
if ( V_7 -> V_363 ) {
const T_2 * V_422 ;
for ( V_422 = V_7 -> V_363 ; * V_422 ; V_422 ++ )
F_142 ( V_7 , * V_422 , V_242 , 0 ,
V_248 ) ;
}
if ( V_574 )
F_243 ( V_7 , V_25 ,
V_413 -> V_427 & 0xff , - 1 ) ;
}
static void F_327 ( struct V_6 * V_7 , T_2 V_25 )
{
F_297 ( V_7 , V_25 ) ;
if ( V_7 -> V_363 ) {
const T_2 * V_422 ;
for ( V_422 = V_7 -> V_363 ; * V_422 ; V_422 ++ )
F_297 ( V_7 , * V_422 ) ;
}
}
void F_328 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
if ( ! V_10 )
return;
F_29 (codec, &bus->codec_list, list) {
if ( F_329 ( V_7 ) &&
V_7 -> V_106 . V_575 )
V_7 -> V_106 . V_575 ( V_7 ) ;
}
}
int F_330 ( struct V_6 * V_7 ,
struct V_440 * V_441 )
{
F_2 ( & V_7 -> V_208 ) ;
if ( V_441 -> V_576 == V_577 )
F_327 ( V_7 , V_441 -> V_443 ) ;
V_441 -> V_576 = V_578 ;
F_4 ( & V_7 -> V_208 ) ;
return 0 ;
}
int F_331 ( struct V_6 * V_7 ,
struct V_440 * V_441 ,
unsigned int V_242 ,
unsigned int V_248 ,
struct V_526 * V_527 )
{
F_2 ( & V_7 -> V_208 ) ;
F_326 ( V_7 , V_441 -> V_443 , V_242 , V_248 ) ;
F_4 ( & V_7 -> V_208 ) ;
return 0 ;
}
int F_332 ( struct V_6 * V_7 ,
struct V_440 * V_441 )
{
F_2 ( & V_7 -> V_208 ) ;
F_327 ( V_7 , V_441 -> V_443 ) ;
F_4 ( & V_7 -> V_208 ) ;
return 0 ;
}
int F_333 ( struct V_6 * V_7 ,
struct V_440 * V_441 )
{
F_2 ( & V_7 -> V_208 ) ;
V_441 -> V_576 = 0 ;
F_4 ( & V_7 -> V_208 ) ;
return 0 ;
}
int F_334 ( struct V_6 * V_7 ,
struct V_440 * V_441 ,
struct V_526 * V_527 ,
struct V_476 * V_477 )
{
struct V_579 * V_580 = V_527 -> V_580 ;
V_580 -> V_581 . V_486 = V_441 -> V_562 ;
if ( V_441 -> V_443 ) {
if ( ! V_441 -> V_582 ) {
V_441 -> V_582 = V_477 -> V_510 ;
V_441 -> V_583 = V_477 -> V_513 ;
V_441 -> V_584 = V_477 -> V_492 ;
} else {
V_580 -> V_581 . V_510 = V_441 -> V_582 ;
V_580 -> V_581 . V_513 = V_441 -> V_583 ;
V_477 -> V_492 = V_441 -> V_584 ;
}
if ( ! V_441 -> V_585 ) {
F_292 ( V_7 , V_441 -> V_443 ,
& V_441 -> V_585 ,
& V_441 -> V_586 ,
& V_441 -> V_587 ) ;
}
F_2 ( & V_7 -> V_208 ) ;
if ( V_441 -> V_442 ) {
if ( ( V_580 -> V_581 . V_510 & V_441 -> V_585 ) &&
( V_580 -> V_581 . V_513 & V_441 -> V_586 ) ) {
V_580 -> V_581 . V_510 &= V_441 -> V_585 ;
V_580 -> V_581 . V_513 &= V_441 -> V_586 ;
if ( V_441 -> V_587 < V_477 -> V_492 )
V_477 -> V_492 = V_441 -> V_587 ;
} else {
V_441 -> V_442 = 0 ;
}
}
F_4 ( & V_7 -> V_208 ) ;
}
return F_335 ( V_527 -> V_580 , 0 ,
V_588 , 2 ) ;
}
int F_336 ( struct V_6 * V_7 ,
struct V_440 * V_441 ,
unsigned int V_242 ,
unsigned int V_248 ,
struct V_526 * V_527 )
{
const T_2 * V_189 = V_441 -> V_589 ;
int V_310 = V_527 -> V_580 -> V_491 ;
struct V_214 * V_413 ;
int V_18 ;
F_2 ( & V_7 -> V_208 ) ;
V_413 = F_249 ( V_7 , V_441 -> V_443 ) ;
if ( V_441 -> V_443 && V_441 -> V_442 &&
V_441 -> V_576 != V_578 ) {
if ( V_310 == 2 &&
F_293 ( V_7 , V_441 -> V_443 ,
V_248 ) &&
! ( V_413 -> V_405 & V_407 ) ) {
V_441 -> V_576 = V_577 ;
F_326 ( V_7 , V_441 -> V_443 ,
V_242 , V_248 ) ;
} else {
V_441 -> V_576 = 0 ;
F_327 ( V_7 , V_441 -> V_443 ) ;
}
}
F_4 ( & V_7 -> V_208 ) ;
F_142 ( V_7 , V_189 [ V_590 ] , V_242 ,
0 , V_248 ) ;
if ( ! V_441 -> V_591 &&
V_441 -> V_592 && V_441 -> V_592 != V_189 [ V_590 ] )
F_142 ( V_7 , V_441 -> V_592 , V_242 ,
0 , V_248 ) ;
for ( V_18 = 0 ; V_18 < F_10 ( V_441 -> V_593 ) ; V_18 ++ )
if ( ! V_441 -> V_591 && V_441 -> V_593 [ V_18 ] )
F_142 ( V_7 ,
V_441 -> V_593 [ V_18 ] ,
V_242 , 0 , V_248 ) ;
for ( V_18 = 1 ; V_18 < V_441 -> V_594 ; V_18 ++ ) {
if ( V_310 >= ( V_18 + 1 ) * 2 )
F_142 ( V_7 , V_189 [ V_18 ] , V_242 ,
V_18 * 2 , V_248 ) ;
else if ( ! V_441 -> V_591 )
F_142 ( V_7 , V_189 [ V_18 ] , V_242 ,
0 , V_248 ) ;
}
for ( V_18 = 0 ; V_18 < F_10 ( V_441 -> V_595 ) ; V_18 ++ ) {
int V_279 = 0 ;
if ( ! V_441 -> V_595 [ V_18 ] )
break;
if ( V_310 >= ( V_18 + 1 ) * 2 )
V_279 = V_18 * 2 ;
else if ( ! V_441 -> V_591 )
break;
F_142 ( V_7 , V_441 -> V_595 [ V_18 ] ,
V_242 , V_279 , V_248 ) ;
}
return 0 ;
}
int F_337 ( struct V_6 * V_7 ,
struct V_440 * V_441 )
{
const T_2 * V_189 = V_441 -> V_589 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_441 -> V_594 ; V_18 ++ )
F_297 ( V_7 , V_189 [ V_18 ] ) ;
if ( V_441 -> V_592 )
F_297 ( V_7 , V_441 -> V_592 ) ;
for ( V_18 = 0 ; V_18 < F_10 ( V_441 -> V_593 ) ; V_18 ++ )
if ( V_441 -> V_593 [ V_18 ] )
F_297 ( V_7 ,
V_441 -> V_593 [ V_18 ] ) ;
for ( V_18 = 0 ; V_18 < F_10 ( V_441 -> V_595 ) ; V_18 ++ )
if ( V_441 -> V_595 [ V_18 ] )
F_297 ( V_7 ,
V_441 -> V_595 [ V_18 ] ) ;
F_2 ( & V_7 -> V_208 ) ;
if ( V_441 -> V_443 && V_441 -> V_576 == V_577 ) {
F_327 ( V_7 , V_441 -> V_443 ) ;
V_441 -> V_576 = 0 ;
}
F_4 ( & V_7 -> V_208 ) ;
return 0 ;
}
unsigned int F_338 ( struct V_6 * V_7 , T_2 V_167 )
{
unsigned int V_596 ;
unsigned int V_244 ;
V_244 = F_23 ( V_7 , V_167 , 0 ,
V_172 , 0 ) ;
V_596 = F_158 ( V_7 , V_167 ) ;
V_596 = ( V_596 & V_597 ) >> V_598 ;
if ( ( V_596 & V_599 ) && V_244 != V_600 )
return V_601 ;
else if ( V_596 & V_602 )
return V_603 ;
else if ( V_596 & V_604 )
return V_605 ;
else if ( V_596 & V_606 )
return V_607 ;
return V_608 ;
}
unsigned int F_339 ( struct V_6 * V_7 ,
T_2 V_167 , unsigned int V_29 )
{
static unsigned int V_609 [] [ 2 ] = {
{ V_605 , V_604 } ,
{ V_601 , V_599 } ,
{ V_603 , V_602 } ,
{ V_607 , V_606 } ,
} ;
unsigned int V_610 ;
if ( ! V_29 )
return 0 ;
V_610 = F_158 ( V_7 , V_167 ) ;
if ( ! V_610 )
return V_29 ;
if ( V_29 & V_611 ) {
if ( ! ( V_610 & V_612 ) )
V_29 &= ~ ( V_611 | V_613 ) ;
else if ( ( V_29 & V_613 ) && ! ( V_610 & V_614 ) )
V_29 &= ~ V_613 ;
}
if ( V_29 & V_615 ) {
if ( ! ( V_610 & V_616 ) )
V_29 &= ~ ( V_615 | V_617 ) ;
else {
unsigned int V_618 , V_619 ;
int V_18 ;
V_618 = ( V_610 & V_597 ) >> V_598 ;
V_619 = V_29 & V_617 ;
for ( V_18 = 0 ; V_18 < F_10 ( V_609 ) ; V_18 ++ ) {
if ( V_619 == V_609 [ V_18 ] [ 0 ] &&
! ( V_618 & V_609 [ V_18 ] [ 1 ] ) ) {
if ( V_18 == F_10 ( V_609 ) - 1 )
V_619 = V_608 ;
else
V_619 = V_609 [ V_18 + 1 ] [ 0 ] ;
}
}
V_29 &= ~ V_617 ;
V_29 |= V_619 ;
}
}
return V_29 ;
}
int F_340 ( struct V_6 * V_7 , T_2 V_167 ,
unsigned int V_29 , bool V_620 )
{
V_29 = F_339 ( V_7 , V_167 , V_29 ) ;
F_88 ( V_7 , V_167 , V_29 ) ;
if ( V_620 )
return F_260 ( V_7 , V_167 , 0 ,
V_180 , V_29 ) ;
else
return F_24 ( V_7 , V_167 , 0 ,
V_180 , V_29 ) ;
}
int F_341 ( struct V_6 * V_7 ,
struct V_566 * V_567 , const char * V_569 ,
int V_280 , int * V_621 )
{
int V_18 , V_622 = 0 ;
if ( V_567 -> V_568 >= V_623 ) {
F_14 ( V_7 , L_91 ) ;
return - V_61 ;
}
for ( V_18 = 0 ; V_18 < V_567 -> V_568 ; V_18 ++ ) {
if ( ! strncmp ( V_569 , V_567 -> V_348 [ V_18 ] . V_569 , strlen ( V_569 ) ) )
V_622 ++ ;
}
if ( V_621 )
* V_621 = V_622 ;
if ( V_622 > 0 )
snprintf ( V_567 -> V_348 [ V_567 -> V_568 ] . V_569 ,
sizeof( V_567 -> V_348 [ V_567 -> V_568 ] . V_569 ) ,
L_92 , V_569 , V_622 ) ;
else
F_342 ( V_567 -> V_348 [ V_567 -> V_568 ] . V_569 , V_569 ,
sizeof( V_567 -> V_348 [ V_567 -> V_568 ] . V_569 ) ) ;
V_567 -> V_348 [ V_567 -> V_568 ] . V_280 = V_280 ;
V_567 -> V_568 ++ ;
return 0 ;
}
static void F_343 ( void * V_368 , T_9 V_624 )
{
F_274 ( V_368 , false ) ;
}
static void F_344 ( void * V_368 , T_9 V_624 )
{
F_278 ( V_368 ) ;
}
int F_345 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_346 ( V_625 ) ;
F_29 (codec, &bus->codec_list, list) {
F_102 ( & V_7 -> V_182 ) ;
if ( F_329 ( V_7 ) ) {
if ( V_10 -> V_193 > 1 )
F_347 ( F_343 , V_7 ,
& V_625 ) ;
else
F_274 ( V_7 , false ) ;
}
}
if ( V_10 -> V_193 > 1 )
F_348 ( & V_625 ) ;
return 0 ;
}
int F_349 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_346 ( V_625 ) ;
F_29 (codec, &bus->codec_list, list) {
if ( V_10 -> V_193 > 1 )
F_347 ( F_344 , V_7 , & V_625 ) ;
else
F_278 ( V_7 ) ;
}
if ( V_10 -> V_193 > 1 )
F_348 ( & V_625 ) ;
return 0 ;
}
void * F_81 ( struct V_173 * V_174 )
{
if ( F_43 ( ! V_174 -> V_626 ) )
return NULL ;
if ( V_174 -> V_175 >= V_174 -> V_627 ) {
int V_628 = V_174 -> V_627 + V_174 -> V_629 ;
int V_323 = ( V_628 + 1 ) * V_174 -> V_626 ;
void * V_630 ;
if ( F_43 ( V_628 >= 4096 ) )
return NULL ;
V_630 = F_350 ( V_174 -> V_4 , V_323 , V_53 | V_631 ) ;
if ( ! V_630 )
return NULL ;
V_174 -> V_4 = V_630 ;
V_174 -> V_627 = V_628 ;
}
return F_83 ( V_174 , V_174 -> V_175 ++ ) ;
}
void F_97 ( struct V_173 * V_174 )
{
F_37 ( V_174 -> V_4 ) ;
V_174 -> V_175 = 0 ;
V_174 -> V_627 = 0 ;
V_174 -> V_4 = NULL ;
}
void F_351 ( int V_353 , char * V_262 , int V_632 )
{
static unsigned int V_633 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_18 , V_634 ;
for ( V_18 = 0 , V_634 = 0 ; V_18 < F_10 ( V_633 ) ; V_18 ++ )
if ( V_353 & ( V_516 << V_18 ) )
V_634 += snprintf ( V_262 + V_634 , V_632 - V_634 , L_93 , V_633 [ V_18 ] ) ;
V_262 [ V_634 ] = '\0' ;
}
