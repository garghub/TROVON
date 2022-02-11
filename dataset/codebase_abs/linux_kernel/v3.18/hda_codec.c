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
bool F_156 ( struct V_6 * V_7 , T_2 V_25 ,
int V_276 , unsigned int V_277 )
{
if ( ! V_25 )
return false ;
if ( F_46 ( V_7 , V_25 ) & ( 1 << ( V_276 + 1 ) ) )
if ( F_153 ( V_7 , V_25 , V_276 ) & V_277 )
return true ;
return false ;
}
int F_157 ( struct V_6 * V_7 , T_2 V_25 , int V_276 ,
unsigned int V_278 )
{
return F_151 ( V_7 , F_155 ( V_25 , V_276 , 0 ) , V_278 ) ;
}
static unsigned int F_158 ( struct V_6 * V_7 , T_2 V_25 ,
int V_276 )
{
return F_27 ( V_7 , V_25 , V_279 ) ;
}
T_1 F_159 ( struct V_6 * V_7 , T_2 V_25 )
{
return F_154 ( V_7 , V_25 , 0 , F_160 ( V_25 ) ,
F_158 ) ;
}
int F_161 ( struct V_6 * V_7 , T_2 V_25 ,
unsigned int V_278 )
{
return F_151 ( V_7 , F_160 ( V_25 ) , V_278 ) ;
}
static struct V_211 *
F_162 ( struct V_6 * V_7 , T_2 V_25 , int V_280 ,
int V_271 , int V_281 , bool V_282 )
{
struct V_211 * V_266 ;
unsigned int V_28 , V_29 = 0 ;
bool V_283 = false ;
V_284:
V_266 = F_150 ( V_7 , F_155 ( V_25 , V_271 , V_281 ) ) ;
if ( ! V_266 )
return NULL ;
if ( ! ( V_266 -> V_269 . V_29 & F_163 ( V_280 ) ) ) {
if ( ! V_283 ) {
F_4 ( & V_7 -> V_210 ) ;
V_28 = V_280 ? V_285 : V_286 ;
V_28 |= V_271 == V_273 ?
V_287 : V_288 ;
V_28 |= V_281 ;
V_29 = F_23 ( V_7 , V_25 , 0 ,
V_289 , V_28 ) ;
V_29 &= 0xff ;
V_283 = true ;
F_2 ( & V_7 -> V_210 ) ;
goto V_284;
}
V_266 -> V_290 [ V_280 ] = V_29 ;
V_266 -> V_269 . V_29 |= F_163 ( V_280 ) ;
} else if ( V_282 )
return NULL ;
return V_266 ;
}
static void F_164 ( struct V_6 * V_7 , unsigned int V_268 ,
T_2 V_25 , int V_280 , int V_271 , int V_281 ,
int V_29 )
{
T_1 V_28 ;
V_28 = V_280 ? V_291 : V_292 ;
V_28 |= V_271 == V_273 ? V_293 : V_294 ;
V_28 |= V_281 << V_295 ;
if ( ( V_29 & V_296 ) && ! ( V_268 & V_297 ) &&
( V_268 & V_298 ) )
;
else
V_28 |= V_29 ;
F_24 ( V_7 , V_25 , 0 , V_299 , V_28 ) ;
}
int F_165 ( struct V_6 * V_7 , T_2 V_25 , int V_280 ,
int V_271 , int V_281 )
{
struct V_211 * V_266 ;
unsigned int V_29 = 0 ;
F_2 ( & V_7 -> V_210 ) ;
V_266 = F_162 ( V_7 , V_25 , V_280 , V_271 , V_281 , false ) ;
if ( V_266 )
V_29 = V_266 -> V_290 [ V_280 ] ;
F_4 ( & V_7 -> V_210 ) ;
return V_29 ;
}
static int F_166 ( struct V_6 * V_7 , T_2 V_25 , int V_280 ,
int V_271 , int V_264 , int V_70 , int V_29 ,
bool V_282 )
{
struct V_211 * V_266 ;
unsigned int V_278 ;
unsigned int V_300 ;
if ( F_43 ( V_70 & ~ 0xff ) )
V_70 &= 0xff ;
V_29 &= V_70 ;
F_2 ( & V_7 -> V_210 ) ;
V_266 = F_162 ( V_7 , V_25 , V_280 , V_271 , V_264 , V_282 ) ;
if ( ! V_266 ) {
F_4 ( & V_7 -> V_210 ) ;
return 0 ;
}
V_29 |= V_266 -> V_290 [ V_280 ] & ~ V_70 ;
if ( V_266 -> V_290 [ V_280 ] == V_29 ) {
F_4 ( & V_7 -> V_210 ) ;
return 0 ;
}
V_266 -> V_290 [ V_280 ] = V_29 ;
V_300 = V_266 -> V_269 . V_254 = V_7 -> V_301 ;
V_278 = V_266 -> V_268 ;
F_4 ( & V_7 -> V_210 ) ;
if ( ! V_300 )
F_164 ( V_7 , V_278 , V_25 , V_280 , V_271 , V_264 , V_29 ) ;
return 1 ;
}
int F_167 ( struct V_6 * V_7 , T_2 V_25 , int V_280 ,
int V_271 , int V_264 , int V_70 , int V_29 )
{
return F_166 ( V_7 , V_25 , V_280 , V_271 , V_264 , V_70 , V_29 , false ) ;
}
int F_168 ( struct V_6 * V_7 , T_2 V_25 ,
int V_271 , int V_264 , int V_70 , int V_29 )
{
int V_280 , V_302 = 0 ;
if ( F_43 ( V_70 & ~ 0xff ) )
V_70 &= 0xff ;
for ( V_280 = 0 ; V_280 < 2 ; V_280 ++ )
V_302 |= F_167 ( V_7 , V_25 , V_280 , V_271 ,
V_264 , V_70 , V_29 ) ;
return V_302 ;
}
int F_169 ( struct V_6 * V_7 , T_2 V_25 , int V_280 ,
int V_276 , int V_264 , int V_70 , int V_29 )
{
return F_166 ( V_7 , V_25 , V_280 , V_276 , V_264 , V_70 , V_29 , true ) ;
}
int F_170 ( struct V_6 * V_7 , T_2 V_25 ,
int V_276 , int V_264 , int V_70 , int V_29 )
{
int V_280 , V_302 = 0 ;
if ( F_43 ( V_70 & ~ 0xff ) )
V_70 &= 0xff ;
for ( V_280 = 0 ; V_280 < 2 ; V_280 ++ )
V_302 |= F_169 ( V_7 , V_25 , V_280 , V_276 ,
V_264 , V_70 , V_29 ) ;
return V_302 ;
}
void F_171 ( struct V_6 * V_7 )
{
int V_18 ;
F_2 ( & V_7 -> V_210 ) ;
V_7 -> V_301 = 0 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_191 . V_262 . V_175 ; V_18 ++ ) {
struct V_211 * V_303 ;
T_1 V_263 ;
T_2 V_25 ;
unsigned int V_264 , V_276 , V_280 ;
struct V_211 V_266 ;
V_303 = F_83 ( & V_7 -> V_191 . V_262 , V_18 ) ;
if ( ! V_303 -> V_269 . V_254 )
continue;
V_303 -> V_269 . V_254 = 0 ;
V_266 = * V_303 ;
V_263 = V_266 . V_269 . V_263 ;
if ( ! V_263 )
continue;
V_25 = V_263 & 0xff ;
V_264 = ( V_263 >> 16 ) & 0xff ;
V_276 = ( V_263 >> 24 ) & 0xff ;
for ( V_280 = 0 ; V_280 < 2 ; V_280 ++ ) {
if ( ! ( V_266 . V_269 . V_29 & F_163 ( V_280 ) ) )
continue;
F_4 ( & V_7 -> V_210 ) ;
F_164 ( V_7 , V_266 . V_268 , V_25 , V_280 , V_276 , V_264 ,
V_266 . V_290 [ V_280 ] ) ;
F_2 ( & V_7 -> V_210 ) ;
}
}
F_4 ( & V_7 -> V_210 ) ;
}
static T_1 F_172 ( struct V_6 * V_7 , T_2 V_25 , int V_276 ,
unsigned int V_304 )
{
T_1 V_278 = F_153 ( V_7 , V_25 , V_276 ) ;
V_278 = ( V_278 & V_305 ) >> V_306 ;
if ( V_304 < V_278 )
V_278 -= V_304 ;
return V_278 ;
}
int F_173 ( struct V_307 * V_308 ,
struct V_309 * V_310 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
T_4 V_25 = F_175 ( V_308 ) ;
T_3 V_311 = F_176 ( V_308 ) ;
int V_276 = F_177 ( V_308 ) ;
unsigned int V_304 = F_178 ( V_308 ) ;
V_310 -> type = V_312 ;
V_310 -> V_313 = V_311 == 3 ? 2 : 1 ;
V_310 -> V_314 . integer . V_315 = 0 ;
V_310 -> V_314 . integer . V_316 = F_172 ( V_7 , V_25 , V_276 , V_304 ) ;
if ( ! V_310 -> V_314 . integer . V_316 ) {
F_48 ( V_7 ,
L_61 ,
V_25 , V_308 -> V_136 . V_143 ) ;
return - V_61 ;
}
return 0 ;
}
static inline unsigned int
F_179 ( struct V_6 * V_7 , T_2 V_25 ,
int V_280 , int V_276 , int V_264 , unsigned int V_304 )
{
unsigned int V_29 ;
V_29 = F_165 ( V_7 , V_25 , V_280 , V_276 , V_264 ) ;
V_29 &= V_317 ;
if ( V_29 >= V_304 )
V_29 -= V_304 ;
else
V_29 = 0 ;
return V_29 ;
}
static inline int
F_180 ( struct V_6 * V_7 , T_2 V_25 ,
int V_280 , int V_276 , int V_264 , unsigned int V_304 ,
unsigned int V_29 )
{
unsigned int V_318 ;
if ( V_29 > 0 )
V_29 += V_304 ;
V_318 = F_172 ( V_7 , V_25 , V_276 , 0 ) ;
if ( V_29 > V_318 )
V_29 = V_318 ;
return F_167 ( V_7 , V_25 , V_280 , V_276 , V_264 ,
V_317 , V_29 ) ;
}
int F_181 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
T_2 V_25 = F_175 ( V_308 ) ;
int V_311 = F_176 ( V_308 ) ;
int V_276 = F_177 ( V_308 ) ;
int V_264 = F_182 ( V_308 ) ;
unsigned int V_304 = F_178 ( V_308 ) ;
long * V_321 = V_320 -> V_314 . integer . V_314 ;
if ( V_311 & 1 )
* V_321 ++ = F_179 ( V_7 , V_25 , 0 , V_276 , V_264 , V_304 ) ;
if ( V_311 & 2 )
* V_321 = F_179 ( V_7 , V_25 , 1 , V_276 , V_264 , V_304 ) ;
return 0 ;
}
int F_183 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
T_2 V_25 = F_175 ( V_308 ) ;
int V_311 = F_176 ( V_308 ) ;
int V_276 = F_177 ( V_308 ) ;
int V_264 = F_182 ( V_308 ) ;
unsigned int V_304 = F_178 ( V_308 ) ;
long * V_321 = V_320 -> V_314 . integer . V_314 ;
int V_322 = 0 ;
F_16 ( V_7 ) ;
if ( V_311 & 1 ) {
V_322 = F_180 ( V_7 , V_25 , 0 , V_276 , V_264 , V_304 , * V_321 ) ;
V_321 ++ ;
}
if ( V_311 & 2 )
V_322 |= F_180 ( V_7 , V_25 , 1 , V_276 , V_264 , V_304 , * V_321 ) ;
F_19 ( V_7 ) ;
return V_322 ;
}
int F_184 ( struct V_307 * V_308 , int V_323 ,
unsigned int V_324 , unsigned int T_5 * V_325 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
T_2 V_25 = F_175 ( V_308 ) ;
int V_276 = F_177 ( V_308 ) ;
unsigned int V_304 = F_178 ( V_308 ) ;
bool V_326 = F_185 ( V_308 ) ;
T_1 V_278 , V_327 , V_328 ;
if ( V_324 < 4 * sizeof( unsigned int ) )
return - V_54 ;
V_278 = F_153 ( V_7 , V_25 , V_276 ) ;
V_328 = ( V_278 & V_329 ) >> V_330 ;
V_328 = ( V_328 + 1 ) * 25 ;
V_327 = - ( ( V_278 & V_331 ) >> V_332 ) ;
V_327 += V_304 ;
V_327 = ( ( int ) V_327 ) * ( ( int ) V_328 ) ;
if ( V_326 || ( V_278 & V_298 ) )
V_328 |= V_333 ;
if ( F_186 ( V_334 , V_325 ) )
return - V_335 ;
if ( F_186 ( 2 * sizeof( unsigned int ) , V_325 + 1 ) )
return - V_335 ;
if ( F_186 ( V_327 , V_325 + 2 ) )
return - V_335 ;
if ( F_186 ( V_328 , V_325 + 3 ) )
return - V_335 ;
return 0 ;
}
void F_187 ( struct V_6 * V_7 , T_2 V_25 , int V_276 ,
unsigned int * V_336 )
{
T_1 V_278 ;
int V_82 , V_337 ;
V_278 = F_153 ( V_7 , V_25 , V_276 ) ;
V_82 = ( V_278 & V_305 ) >> V_306 ;
V_337 = ( V_278 & V_329 ) >> V_330 ;
V_337 = ( V_337 + 1 ) * 25 ;
V_336 [ 0 ] = V_334 ;
V_336 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_336 [ 2 ] = - V_82 * V_337 ;
V_336 [ 3 ] = V_337 ;
}
static struct V_307 *
F_188 ( struct V_6 * V_7 , const char * V_143 , int V_109 , int V_264 )
{
struct V_338 V_136 ;
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_339 = V_340 ;
V_136 . V_113 = V_109 ;
V_136 . V_281 = V_264 ;
if ( F_43 ( strlen ( V_143 ) >= sizeof( V_136 . V_143 ) ) )
return NULL ;
strcpy ( V_136 . V_143 , V_143 ) ;
return F_189 ( V_7 -> V_10 -> V_108 , & V_136 ) ;
}
struct V_307 * F_190 ( struct V_6 * V_7 ,
const char * V_143 )
{
return F_188 ( V_7 , V_143 , 0 , 0 ) ;
}
static int F_191 ( struct V_6 * V_7 , const char * V_143 ,
int V_341 )
{
int V_18 , V_264 ;
for ( V_18 = 0 , V_264 = V_341 ; V_18 < 16 ; V_18 ++ , V_264 ++ ) {
if ( ! F_188 ( V_7 , V_143 , 0 , V_264 ) )
return V_264 ;
}
return - V_200 ;
}
int F_192 ( struct V_6 * V_7 , T_2 V_25 ,
struct V_307 * V_342 )
{
int V_33 ;
unsigned short V_26 = 0 ;
struct V_213 * V_343 ;
if ( V_342 -> V_136 . V_344 & V_345 ) {
V_26 |= V_346 ;
if ( V_25 == 0 )
V_25 = F_193 ( V_342 -> V_347 ) ;
}
if ( ( V_342 -> V_136 . V_344 & V_348 ) != 0 && V_25 == 0 )
V_25 = V_342 -> V_136 . V_344 & 0xffff ;
if ( V_342 -> V_136 . V_344 & ( V_348 | V_345 ) )
V_342 -> V_136 . V_344 = 0 ;
V_33 = F_194 ( V_7 -> V_10 -> V_108 , V_342 ) ;
if ( V_33 < 0 )
return V_33 ;
V_343 = F_81 ( & V_7 -> V_188 ) ;
if ( ! V_343 )
return - V_54 ;
V_343 -> V_342 = V_342 ;
V_343 -> V_25 = V_25 ;
V_343 -> V_26 = V_26 ;
return 0 ;
}
int F_195 ( struct V_6 * V_7 , struct V_307 * V_342 ,
unsigned int V_281 , T_2 V_25 )
{
struct V_213 * V_343 ;
if ( V_25 > 0 ) {
V_343 = F_81 ( & V_7 -> V_189 ) ;
if ( ! V_343 )
return - V_54 ;
V_343 -> V_342 = V_342 ;
V_343 -> V_281 = V_281 ;
V_343 -> V_25 = V_25 ;
return 0 ;
}
F_14 ( V_7 , L_62 ,
V_342 -> V_136 . V_143 , V_342 -> V_136 . V_281 , V_281 ) ;
return - V_61 ;
}
void F_196 ( struct V_6 * V_7 )
{
int V_18 ;
struct V_213 * V_349 = V_7 -> V_188 . V_4 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_188 . V_175 ; V_18 ++ )
F_197 ( V_7 -> V_10 -> V_108 , V_349 [ V_18 ] . V_342 ) ;
F_97 ( & V_7 -> V_188 ) ;
F_97 ( & V_7 -> V_189 ) ;
}
int F_198 ( struct V_9 * V_10 )
{
struct V_116 * V_108 = V_10 -> V_108 ;
struct V_6 * V_7 ;
F_199 ( & V_108 -> V_350 ) ;
if ( V_108 -> V_115 )
goto V_351;
V_108 -> V_115 = 1 ;
if ( ! F_34 ( & V_108 -> V_352 ) )
goto V_353;
F_29 (codec, &bus->codec_list, list) {
int V_354 ;
for ( V_354 = 0 ; V_354 < V_7 -> V_355 ; V_354 ++ ) {
struct V_356 * V_357 = & V_7 -> V_358 [ V_354 ] ;
if ( ! V_357 -> V_354 )
continue;
if ( V_357 -> V_354 -> V_359 [ 0 ] . V_360 ||
V_357 -> V_354 -> V_359 [ 1 ] . V_360 )
goto V_353;
}
}
F_200 ( & V_108 -> V_350 ) ;
return 0 ;
V_353:
V_108 -> V_115 = 0 ;
V_351:
F_200 ( & V_108 -> V_350 ) ;
return - V_61 ;
}
void F_201 ( struct V_9 * V_10 )
{
struct V_116 * V_108 = V_10 -> V_108 ;
V_108 = V_10 -> V_108 ;
F_199 ( & V_108 -> V_350 ) ;
V_108 -> V_115 = 0 ;
F_200 ( & V_108 -> V_350 ) ;
}
int F_202 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_116 * V_108 = V_10 -> V_108 ;
int V_18 ;
if ( F_198 ( V_10 ) < 0 )
return - V_200 ;
F_102 ( & V_7 -> V_182 ) ;
#ifdef F_104
F_102 ( & V_7 -> V_187 ) ;
F_63 ( V_10 -> V_98 ) ;
#endif
F_196 ( V_7 ) ;
for ( V_18 = 0 ; V_18 < V_7 -> V_355 ; V_18 ++ ) {
if ( V_7 -> V_358 [ V_18 ] . V_354 ) {
F_203 ( V_108 , V_7 -> V_358 [ V_18 ] . V_354 ) ;
F_204 ( V_7 -> V_358 [ V_18 ] . V_113 ,
V_10 -> V_361 ) ;
}
}
F_113 ( V_7 ) ;
if ( V_7 -> V_106 . free )
V_7 -> V_106 . free ( V_7 ) ;
memset ( & V_7 -> V_106 , 0 , sizeof( V_7 -> V_106 ) ) ;
F_103 ( V_7 ) ;
V_7 -> V_362 = NULL ;
V_7 -> V_363 = NULL ;
F_107 ( & V_7 -> V_191 ) ;
F_107 ( & V_7 -> V_192 ) ;
F_121 ( & V_7 -> V_191 , sizeof( struct V_211 ) ) ;
F_121 ( & V_7 -> V_192 , sizeof( struct V_212 ) ) ;
F_97 ( & V_7 -> V_176 ) ;
F_97 ( & V_7 -> V_185 ) ;
F_97 ( & V_7 -> V_190 ) ;
F_97 ( & V_7 -> V_217 ) ;
V_7 -> V_355 = 0 ;
V_7 -> V_358 = NULL ;
V_7 -> V_2 = NULL ;
V_7 -> V_364 = NULL ;
V_7 -> V_365 = 0 ;
F_99 ( V_7 ) ;
F_74 ( V_7 -> V_135 ) ;
V_7 -> V_135 = NULL ;
F_201 ( V_10 ) ;
return 0 ;
}
static int F_205 ( struct V_6 * V_7 , const char * const * V_366 ,
const char * V_367 , T_6 V_368 , void * V_369 )
{
struct V_213 * V_349 ;
const char * const * V_370 ;
int V_18 , V_33 ;
V_349 = V_7 -> V_188 . V_4 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_188 . V_175 ; V_18 ++ ) {
struct V_307 * V_371 = V_349 [ V_18 ] . V_342 ;
if ( ! V_371 || V_371 -> V_136 . V_339 != V_340 )
continue;
for ( V_370 = V_366 ; * V_370 ; V_370 ++ ) {
char V_372 [ sizeof( V_371 -> V_136 . V_143 ) ] ;
const char * V_143 = * V_370 ;
if ( V_367 ) {
snprintf ( V_372 , sizeof( V_372 ) , L_58 ,
V_143 , V_367 ) ;
V_143 = V_372 ;
}
if ( ! strcmp ( V_371 -> V_136 . V_143 , V_143 ) ) {
V_33 = V_368 ( V_7 , V_369 , V_371 ) ;
if ( V_33 )
return V_33 ;
break;
}
}
}
return 0 ;
}
static int F_206 ( struct V_6 * V_7 ,
void * V_369 , struct V_307 * V_371 )
{
return 1 ;
}
static int F_207 ( struct V_6 * V_7 ,
struct V_307 * V_342 , int * V_373 )
{
int V_325 [ 4 ] ;
const int * V_336 = NULL ;
int V_29 = - 1 ;
if ( V_342 -> V_374 [ 0 ] . V_375 & V_376 ) {
T_7 V_377 = F_208 () ;
F_209 ( F_210 () ) ;
if ( ! V_342 -> V_336 . V_145 ( V_342 , 0 , sizeof( V_325 ) , V_325 ) )
V_336 = V_325 ;
F_209 ( V_377 ) ;
} else if ( V_342 -> V_374 [ 0 ] . V_375 & V_378 )
V_336 = V_342 -> V_336 . V_51 ;
if ( V_336 && V_336 [ 0 ] == V_334 ) {
int V_337 = V_336 [ 3 ] ;
V_337 &= ~ V_333 ;
if ( ! V_337 )
return - 1 ;
if ( * V_373 && * V_373 != V_337 ) {
F_14 ( V_7 , L_63 ,
- * V_373 , V_337 ) ;
return - 1 ;
}
* V_373 = V_337 ;
V_29 = - V_336 [ 2 ] / V_337 ;
}
return V_29 ;
}
static int F_211 ( struct V_307 * V_342 , int V_29 )
{
struct V_319 * V_320 ;
V_320 = F_58 ( sizeof( * V_320 ) , V_53 ) ;
if ( ! V_320 )
return - V_54 ;
V_320 -> V_314 . integer . V_314 [ 0 ] = V_29 ;
V_320 -> V_314 . integer . V_314 [ 1 ] = V_29 ;
V_342 -> V_379 ( V_342 , V_320 ) ;
F_37 ( V_320 ) ;
return 0 ;
}
static int F_212 ( struct V_6 * V_7 ,
void * V_369 , struct V_307 * V_380 )
{
int V_381 = F_207 ( V_7 , V_380 , V_369 ) ;
if ( V_381 > 0 )
F_211 ( V_380 , V_381 ) ;
return 0 ;
}
static int F_213 ( struct V_6 * V_7 ,
void * V_369 , struct V_307 * V_380 )
{
return F_211 ( V_380 , 1 ) ;
}
static int F_214 ( struct V_6 * V_7 ,
void * V_369 , struct V_307 * V_380 )
{
return F_215 ( V_369 , V_380 ) ;
}
int F_216 ( struct V_6 * V_7 , char * V_143 ,
unsigned int * V_336 , const char * const * V_366 ,
const char * V_367 , bool V_382 ,
struct V_307 * * V_383 )
{
struct V_307 * V_342 ;
int V_33 ;
if ( V_383 )
* V_383 = NULL ;
V_33 = F_205 ( V_7 , V_366 , V_367 , F_206 , NULL ) ;
if ( V_33 != 1 ) {
F_21 ( V_7 , L_64 , V_143 ) ;
return 0 ;
}
V_342 = F_217 ( V_143 , V_336 ) ;
if ( ! V_342 )
return - V_54 ;
V_33 = F_192 ( V_7 , 0 , V_342 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_205 ( V_7 , V_366 , V_367 , F_214 , V_342 ) ;
if ( V_33 < 0 )
return V_33 ;
F_211 ( V_342 , 0 ) ;
if ( V_382 ) {
int V_337 = 0 ;
F_205 ( V_7 , V_366 , V_367 ,
V_336 ? F_212 : F_213 , & V_337 ) ;
}
if ( V_383 )
* V_383 = V_342 ;
return 0 ;
}
static int F_218 ( struct V_307 * V_308 ,
struct V_309 * V_310 )
{
static const char * const V_384 [] = {
L_65 , L_66 , L_67
} ;
unsigned int V_281 ;
V_310 -> type = V_385 ;
V_310 -> V_313 = 1 ;
V_310 -> V_314 . V_386 . V_349 = 3 ;
V_281 = V_310 -> V_314 . V_386 . V_343 ;
if ( V_281 >= 3 )
V_281 = 2 ;
strcpy ( V_310 -> V_314 . V_386 . V_143 , V_384 [ V_281 ] ) ;
return 0 ;
}
static int F_219 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_387 * V_388 = F_174 ( V_308 ) ;
V_320 -> V_314 . V_386 . V_343 [ 0 ] = V_388 -> V_389 ;
return 0 ;
}
static int F_220 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_387 * V_388 = F_174 ( V_308 ) ;
unsigned int V_390 = V_388 -> V_389 ;
V_388 -> V_389 = V_320 -> V_314 . V_386 . V_343 [ 0 ] ;
if ( V_388 -> V_389 > V_391 )
V_388 -> V_389 = V_391 ;
if ( V_390 == V_388 -> V_389 )
return 0 ;
F_221 ( V_388 ) ;
return 1 ;
}
int F_222 ( struct V_6 * V_7 ,
struct V_387 * V_388 ,
bool V_392 )
{
struct V_307 * V_342 ;
if ( ! V_388 -> V_388 || ! V_388 -> V_393 )
return 0 ;
F_223 ( V_388 -> V_393 , V_388 -> V_388 , V_7 ) ;
V_388 -> V_7 = V_7 ;
V_388 -> V_389 = V_391 ;
if ( ! V_392 )
return 0 ;
V_342 = F_224 ( & V_394 , V_388 ) ;
if ( ! V_342 )
return - V_54 ;
return F_192 ( V_7 , 0 , V_342 ) ;
}
void F_221 ( struct V_387 * V_388 )
{
if ( ! V_388 -> V_388 || ! V_388 -> V_7 )
return;
if ( V_388 -> V_7 -> V_10 -> V_115 )
return;
switch ( V_388 -> V_389 ) {
case V_391 :
F_225 ( V_388 -> V_393 ) ;
break;
default:
V_388 -> V_388 ( V_388 -> V_7 , V_388 -> V_389 ) ;
break;
}
}
int F_226 ( struct V_307 * V_308 ,
struct V_309 * V_310 )
{
int V_311 = F_176 ( V_308 ) ;
V_310 -> type = V_395 ;
V_310 -> V_313 = V_311 == 3 ? 2 : 1 ;
V_310 -> V_314 . integer . V_315 = 0 ;
V_310 -> V_314 . integer . V_316 = 1 ;
return 0 ;
}
int F_227 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
T_2 V_25 = F_175 ( V_308 ) ;
int V_311 = F_176 ( V_308 ) ;
int V_276 = F_177 ( V_308 ) ;
int V_264 = F_182 ( V_308 ) ;
long * V_321 = V_320 -> V_314 . integer . V_314 ;
if ( V_311 & 1 )
* V_321 ++ = ( F_165 ( V_7 , V_25 , 0 , V_276 , V_264 ) &
V_296 ) ? 0 : 1 ;
if ( V_311 & 2 )
* V_321 = ( F_165 ( V_7 , V_25 , 1 , V_276 , V_264 ) &
V_296 ) ? 0 : 1 ;
return 0 ;
}
int F_228 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
T_2 V_25 = F_175 ( V_308 ) ;
int V_311 = F_176 ( V_308 ) ;
int V_276 = F_177 ( V_308 ) ;
int V_264 = F_182 ( V_308 ) ;
long * V_321 = V_320 -> V_314 . integer . V_314 ;
int V_322 = 0 ;
F_16 ( V_7 ) ;
if ( V_311 & 1 ) {
V_322 = F_167 ( V_7 , V_25 , 0 , V_276 , V_264 ,
V_296 ,
* V_321 ? 0 : V_296 ) ;
V_321 ++ ;
}
if ( V_311 & 2 )
V_322 |= F_167 ( V_7 , V_25 , 1 , V_276 , V_264 ,
V_296 ,
* V_321 ? 0 : V_296 ) ;
F_229 ( V_7 , V_25 ) ;
F_19 ( V_7 ) ;
return V_322 ;
}
int F_230 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
unsigned long V_396 ;
int V_33 ;
F_2 ( & V_7 -> V_209 ) ;
V_396 = V_308 -> V_347 ;
V_308 -> V_347 = V_396 & ~ V_397 ;
V_33 = F_227 ( V_308 , V_320 ) ;
V_308 -> V_347 = V_396 ;
F_4 ( & V_7 -> V_209 ) ;
return V_33 ;
}
int F_231 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
unsigned long V_396 ;
int V_18 , V_398 , V_33 = 0 , V_322 = 0 ;
F_2 ( & V_7 -> V_209 ) ;
V_396 = V_308 -> V_347 ;
V_398 = ( V_396 & V_397 ) >> V_399 ;
for ( V_18 = 0 ; V_18 < V_398 ; V_18 ++ ) {
V_308 -> V_347 = ( V_396 & ~ V_397 ) |
( V_18 << V_399 ) ;
V_33 = F_228 ( V_308 , V_320 ) ;
if ( V_33 < 0 )
break;
V_322 |= V_33 ;
}
V_308 -> V_347 = V_396 ;
F_4 ( & V_7 -> V_209 ) ;
return V_33 < 0 ? V_33 : V_322 ;
}
int F_232 ( struct V_307 * V_308 ,
struct V_309 * V_310 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
struct V_400 * V_145 ;
int V_33 ;
F_2 ( & V_7 -> V_209 ) ;
V_145 = (struct V_400 * ) V_308 -> V_347 ;
V_308 -> V_347 = * V_145 -> V_401 ;
V_33 = V_145 -> V_12 -> V_266 ( V_308 , V_310 ) ;
V_308 -> V_347 = ( long ) V_145 ;
F_4 ( & V_7 -> V_209 ) ;
return V_33 ;
}
int F_233 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
struct V_400 * V_145 ;
int V_33 ;
F_2 ( & V_7 -> V_209 ) ;
V_145 = (struct V_400 * ) V_308 -> V_347 ;
V_308 -> V_347 = * V_145 -> V_401 ;
V_33 = V_145 -> V_12 -> V_402 ( V_308 , V_320 ) ;
V_308 -> V_347 = ( long ) V_145 ;
F_4 ( & V_7 -> V_209 ) ;
return V_33 ;
}
int F_234 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
struct V_400 * V_145 ;
unsigned long * V_403 ;
int V_33 = 0 , V_322 = 0 ;
F_2 ( & V_7 -> V_209 ) ;
V_145 = (struct V_400 * ) V_308 -> V_347 ;
for ( V_403 = V_145 -> V_401 ; * V_403 ; V_403 ++ ) {
V_308 -> V_347 = * V_403 ;
V_33 = V_145 -> V_12 -> V_379 ( V_308 , V_320 ) ;
if ( V_33 < 0 )
break;
V_322 |= V_33 ;
}
V_308 -> V_347 = ( long ) V_145 ;
F_4 ( & V_7 -> V_209 ) ;
return V_33 < 0 ? V_33 : V_322 ;
}
int F_235 ( struct V_307 * V_308 , int V_323 ,
unsigned int V_324 , unsigned int T_5 * V_336 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
struct V_400 * V_145 ;
int V_33 ;
F_2 ( & V_7 -> V_209 ) ;
V_145 = (struct V_400 * ) V_308 -> V_347 ;
V_308 -> V_347 = * V_145 -> V_401 ;
V_33 = V_145 -> V_12 -> V_336 ( V_308 , V_323 , V_324 , V_336 ) ;
V_308 -> V_347 = ( long ) V_145 ;
F_4 ( & V_7 -> V_209 ) ;
return V_33 ;
}
static int F_236 ( struct V_307 * V_308 ,
struct V_309 * V_310 )
{
V_310 -> type = V_404 ;
V_310 -> V_313 = 1 ;
return 0 ;
}
static int F_237 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
V_320 -> V_314 . V_405 . V_406 [ 0 ] = V_407 |
V_408 |
V_409 |
V_410 ;
V_320 -> V_314 . V_405 . V_406 [ 1 ] = V_411 |
V_412 ;
return 0 ;
}
static int F_238 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
V_320 -> V_314 . V_405 . V_406 [ 0 ] = V_407 |
V_408 |
V_413 ;
return 0 ;
}
static int F_239 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
int V_264 = V_308 -> V_347 ;
struct V_214 * V_414 ;
F_2 ( & V_7 -> V_208 ) ;
V_414 = F_83 ( & V_7 -> V_190 , V_264 ) ;
V_320 -> V_314 . V_405 . V_406 [ 0 ] = V_414 -> V_406 & 0xff ;
V_320 -> V_314 . V_405 . V_406 [ 1 ] = ( V_414 -> V_406 >> 8 ) & 0xff ;
V_320 -> V_314 . V_405 . V_406 [ 2 ] = ( V_414 -> V_406 >> 16 ) & 0xff ;
V_320 -> V_314 . V_405 . V_406 [ 3 ] = ( V_414 -> V_406 >> 24 ) & 0xff ;
F_4 ( & V_7 -> V_208 ) ;
return 0 ;
}
static unsigned short F_240 ( unsigned int V_415 )
{
unsigned short V_29 = 0 ;
if ( V_415 & V_407 )
V_29 |= V_416 ;
if ( V_415 & V_408 )
V_29 |= V_417 ;
if ( V_415 & V_407 ) {
if ( ( V_415 & V_418 ) ==
V_413 )
V_29 |= V_419 ;
} else {
if ( ( V_415 & V_420 ) ==
V_409 )
V_29 |= V_419 ;
if ( ! ( V_415 & V_410 ) )
V_29 |= V_421 ;
if ( V_415 & ( V_412 << 8 ) )
V_29 |= V_422 ;
V_29 |= V_415 & ( V_411 << 8 ) ;
}
return V_29 ;
}
static unsigned int F_241 ( unsigned short V_29 )
{
unsigned int V_415 = 0 ;
if ( V_29 & V_417 )
V_415 |= V_408 ;
if ( V_29 & V_416 )
V_415 |= V_407 ;
if ( V_415 & V_407 ) {
if ( V_29 & V_419 )
V_415 |= V_413 ;
} else {
if ( V_29 & V_419 )
V_415 |= V_409 ;
if ( ! ( V_29 & V_421 ) )
V_415 |= V_410 ;
if ( V_29 & V_422 )
V_415 |= ( V_412 << 8 ) ;
V_415 |= V_29 & ( 0x7f << 8 ) ;
}
return V_415 ;
}
static void F_242 ( struct V_6 * V_7 , T_2 V_25 ,
int V_27 , int V_29 )
{
const T_2 * V_423 ;
F_243 ( V_7 , V_25 , 0 , V_27 , V_29 ) ;
V_423 = V_7 -> V_364 ;
if ( ! V_423 )
return;
for (; * V_423 ; V_423 ++ )
F_243 ( V_7 , * V_423 , 0 , V_27 , V_29 ) ;
}
static inline void F_244 ( struct V_6 * V_7 , T_2 V_25 ,
int V_424 , int V_425 )
{
if ( V_424 != - 1 )
F_242 ( V_7 , V_25 , V_426 , V_424 ) ;
if ( V_425 != - 1 )
F_242 ( V_7 , V_25 , V_427 , V_425 ) ;
}
static int F_245 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
int V_264 = V_308 -> V_347 ;
struct V_214 * V_414 ;
T_2 V_25 ;
unsigned short V_29 ;
int V_322 ;
F_2 ( & V_7 -> V_208 ) ;
V_414 = F_83 ( & V_7 -> V_190 , V_264 ) ;
V_25 = V_414 -> V_25 ;
V_414 -> V_406 = V_320 -> V_314 . V_405 . V_406 [ 0 ] |
( ( unsigned int ) V_320 -> V_314 . V_405 . V_406 [ 1 ] << 8 ) |
( ( unsigned int ) V_320 -> V_314 . V_405 . V_406 [ 2 ] << 16 ) |
( ( unsigned int ) V_320 -> V_314 . V_405 . V_406 [ 3 ] << 24 ) ;
V_29 = F_240 ( V_414 -> V_406 ) ;
V_29 |= V_414 -> V_428 & 1 ;
V_322 = V_414 -> V_428 != V_29 ;
V_414 -> V_428 = V_29 ;
if ( V_322 && V_25 != ( T_4 ) - 1 )
F_244 ( V_7 , V_25 , V_29 & 0xff , ( V_29 >> 8 ) & 0xff ) ;
F_4 ( & V_7 -> V_208 ) ;
return V_322 ;
}
static int F_246 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
int V_264 = V_308 -> V_347 ;
struct V_214 * V_414 ;
F_2 ( & V_7 -> V_208 ) ;
V_414 = F_83 ( & V_7 -> V_190 , V_264 ) ;
V_320 -> V_314 . integer . V_314 [ 0 ] = V_414 -> V_428 & V_429 ;
F_4 ( & V_7 -> V_208 ) ;
return 0 ;
}
static inline void F_247 ( struct V_6 * V_7 , T_2 V_25 ,
int V_424 , int V_425 )
{
F_244 ( V_7 , V_25 , V_424 , V_425 ) ;
if ( ( F_46 ( V_7 , V_25 ) & V_430 ) &&
( V_424 & V_429 ) )
F_168 ( V_7 , V_25 , V_273 , 0 ,
V_296 , 0 ) ;
}
static int F_248 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
int V_264 = V_308 -> V_347 ;
struct V_214 * V_414 ;
T_2 V_25 ;
unsigned short V_29 ;
int V_322 ;
F_2 ( & V_7 -> V_208 ) ;
V_414 = F_83 ( & V_7 -> V_190 , V_264 ) ;
V_25 = V_414 -> V_25 ;
V_29 = V_414 -> V_428 & ~ V_429 ;
if ( V_320 -> V_314 . integer . V_314 [ 0 ] )
V_29 |= V_429 ;
V_322 = V_414 -> V_428 != V_29 ;
V_414 -> V_428 = V_29 ;
if ( V_322 && V_25 != ( T_4 ) - 1 )
F_247 ( V_7 , V_25 , V_29 & 0xff , - 1 ) ;
F_4 ( & V_7 -> V_208 ) ;
return V_322 ;
}
int F_249 ( struct V_6 * V_7 ,
T_2 V_431 ,
T_2 V_432 ,
int type )
{
int V_33 ;
struct V_307 * V_342 ;
struct V_433 * V_434 ;
int V_264 = 0 ;
const int V_435 = 16 ;
struct V_214 * V_414 ;
struct V_9 * V_10 = V_7 -> V_10 ;
if ( V_10 -> V_436 == V_437 &&
type == V_438 ) {
V_264 = V_435 ;
} else if ( V_10 -> V_436 == V_438 &&
type == V_437 ) {
for ( V_434 = V_439 ; V_434 -> V_143 ; V_434 ++ ) {
V_342 = F_188 ( V_7 , V_434 -> V_143 , 0 , 0 ) ;
if ( ! V_342 )
break;
V_342 -> V_136 . V_281 = V_435 ;
}
V_10 -> V_436 = V_437 ;
}
if ( ! V_10 -> V_436 )
V_10 -> V_436 = type ;
V_264 = F_191 ( V_7 , L_68 , V_264 ) ;
if ( V_264 < 0 ) {
F_14 ( V_7 , L_69 ) ;
return - V_200 ;
}
V_414 = F_81 ( & V_7 -> V_190 ) ;
if ( ! V_414 )
return - V_54 ;
for ( V_434 = V_439 ; V_434 -> V_143 ; V_434 ++ ) {
V_342 = F_224 ( V_434 , V_7 ) ;
if ( ! V_342 )
return - V_54 ;
V_342 -> V_136 . V_281 = V_264 ;
V_342 -> V_347 = V_7 -> V_190 . V_175 - 1 ;
V_33 = F_192 ( V_7 , V_431 , V_342 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_414 -> V_25 = V_432 ;
V_414 -> V_428 = F_23 ( V_7 , V_432 , 0 ,
V_440 , 0 ) ;
V_414 -> V_406 = F_241 ( V_414 -> V_428 ) ;
return 0 ;
}
struct V_214 * F_250 ( struct V_6 * V_7 ,
T_2 V_25 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_190 . V_175 ; V_18 ++ ) {
struct V_214 * V_414 =
F_83 ( & V_7 -> V_190 , V_18 ) ;
if ( V_414 -> V_25 == V_25 )
return V_414 ;
}
return NULL ;
}
void F_251 ( struct V_6 * V_7 , int V_264 )
{
struct V_214 * V_414 ;
F_2 ( & V_7 -> V_208 ) ;
V_414 = F_83 ( & V_7 -> V_190 , V_264 ) ;
V_414 -> V_25 = ( T_4 ) - 1 ;
F_4 ( & V_7 -> V_208 ) ;
}
void F_252 ( struct V_6 * V_7 , int V_264 , T_2 V_25 )
{
struct V_214 * V_414 ;
unsigned short V_29 ;
F_2 ( & V_7 -> V_208 ) ;
V_414 = F_83 ( & V_7 -> V_190 , V_264 ) ;
if ( V_414 -> V_25 != V_25 ) {
V_414 -> V_25 = V_25 ;
V_29 = V_414 -> V_428 ;
F_247 ( V_7 , V_25 , V_29 & 0xff , ( V_29 >> 8 ) & 0xff ) ;
}
F_4 ( & V_7 -> V_208 ) ;
}
static int F_253 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_441 * V_442 = F_174 ( V_308 ) ;
V_320 -> V_314 . integer . V_314 [ 0 ] = V_442 -> V_443 ;
return 0 ;
}
static int F_254 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_441 * V_442 = F_174 ( V_308 ) ;
V_442 -> V_443 = ! ! V_320 -> V_314 . integer . V_314 [ 0 ] ;
return 0 ;
}
int F_255 ( struct V_6 * V_7 ,
struct V_441 * V_442 )
{
struct V_307 * V_342 ;
if ( ! V_442 -> V_444 )
return 0 ;
V_342 = F_224 ( & V_445 , V_442 ) ;
if ( ! V_342 )
return - V_54 ;
return F_192 ( V_7 , V_442 -> V_444 , V_342 ) ;
}
static int F_256 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
V_320 -> V_314 . integer . V_314 [ 0 ] = V_7 -> V_446 ;
return 0 ;
}
static int F_257 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
T_2 V_25 = V_308 -> V_347 ;
unsigned int V_29 = ! ! V_320 -> V_314 . integer . V_314 [ 0 ] ;
int V_322 ;
F_2 ( & V_7 -> V_208 ) ;
V_322 = V_7 -> V_446 != V_29 ;
if ( V_322 ) {
V_7 -> V_446 = V_29 ;
F_243 ( V_7 , V_25 , 0 ,
V_426 , V_29 ) ;
}
F_4 ( & V_7 -> V_208 ) ;
return V_322 ;
}
static int F_258 ( struct V_307 * V_308 ,
struct V_319 * V_320 )
{
struct V_6 * V_7 = F_174 ( V_308 ) ;
T_2 V_25 = V_308 -> V_347 ;
unsigned short V_29 ;
unsigned int V_415 ;
V_29 = F_23 ( V_7 , V_25 , 0 , V_440 , 0 ) ;
V_415 = F_241 ( V_29 ) ;
V_320 -> V_314 . V_405 . V_406 [ 0 ] = V_415 ;
V_320 -> V_314 . V_405 . V_406 [ 1 ] = V_415 >> 8 ;
V_320 -> V_314 . V_405 . V_406 [ 2 ] = V_415 >> 16 ;
V_320 -> V_314 . V_405 . V_406 [ 3 ] = V_415 >> 24 ;
return 0 ;
}
int F_259 ( struct V_6 * V_7 , T_2 V_25 )
{
int V_33 ;
struct V_307 * V_342 ;
struct V_433 * V_434 ;
int V_264 ;
V_264 = F_191 ( V_7 , L_70 , 0 ) ;
if ( V_264 < 0 ) {
F_14 ( V_7 , L_71 ) ;
return - V_200 ;
}
for ( V_434 = V_447 ; V_434 -> V_143 ; V_434 ++ ) {
V_342 = F_224 ( V_434 , V_7 ) ;
if ( ! V_342 )
return - V_54 ;
V_342 -> V_347 = V_25 ;
V_33 = F_192 ( V_7 , V_25 , V_342 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_7 -> V_446 =
F_23 ( V_7 , V_25 , 0 ,
V_440 , 0 ) &
V_429 ;
return 0 ;
}
int F_243 ( struct V_6 * V_7 , T_2 V_25 ,
int V_26 , unsigned int V_27 , unsigned int V_28 )
{
int V_33 ;
struct V_212 * V_145 ;
T_1 V_263 ;
unsigned int V_300 ;
V_300 = V_7 -> V_301 ;
if ( ! V_300 ) {
V_33 = F_24 ( V_7 , V_25 , V_26 , V_27 , V_28 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_27 = V_27 | ( V_28 >> 8 ) ;
V_28 &= 0xff ;
V_263 = F_260 ( V_25 , V_27 ) ;
F_2 ( & V_7 -> V_10 -> V_35 ) ;
V_145 = F_148 ( & V_7 -> V_192 , V_263 ) ;
if ( V_145 ) {
V_145 -> V_29 = V_28 ;
V_145 -> V_254 = V_300 ;
}
F_4 ( & V_7 -> V_10 -> V_35 ) ;
return 0 ;
}
int F_261 ( struct V_6 * V_7 , T_2 V_25 ,
int V_26 , unsigned int V_27 , unsigned int V_28 )
{
struct V_212 * V_145 ;
T_1 V_263 ;
V_27 = V_27 | ( V_28 >> 8 ) ;
V_28 &= 0xff ;
V_263 = F_260 ( V_25 , V_27 ) ;
F_2 ( & V_7 -> V_10 -> V_35 ) ;
V_145 = F_147 ( & V_7 -> V_192 , V_263 ) ;
if ( V_145 && V_145 -> V_29 == V_28 ) {
F_4 ( & V_7 -> V_10 -> V_35 ) ;
return 0 ;
}
F_4 ( & V_7 -> V_10 -> V_35 ) ;
return F_243 ( V_7 , V_25 , V_26 , V_27 , V_28 ) ;
}
void F_262 ( struct V_6 * V_7 )
{
int V_18 ;
F_2 ( & V_7 -> V_210 ) ;
V_7 -> V_301 = 0 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_192 . V_262 . V_175 ; V_18 ++ ) {
struct V_212 * V_303 ;
T_1 V_263 ;
V_303 = F_83 ( & V_7 -> V_192 . V_262 , V_18 ) ;
V_263 = V_303 -> V_263 ;
if ( ! V_263 )
continue;
if ( ! V_303 -> V_254 )
continue;
V_303 -> V_254 = 0 ;
F_4 ( & V_7 -> V_210 ) ;
F_24 ( V_7 , F_263 ( V_263 ) , 0 ,
F_264 ( V_263 ) , V_303 -> V_29 ) ;
F_2 ( & V_7 -> V_210 ) ;
}
F_4 ( & V_7 -> V_210 ) ;
}
void F_265 ( struct V_6 * V_7 ,
const struct V_45 * V_46 )
{
for (; V_46 -> V_25 ; V_46 ++ )
F_243 ( V_7 , V_46 -> V_25 , 0 , V_46 -> V_27 ,
V_46 -> V_47 ) ;
}
void F_266 ( struct V_6 * V_7 )
{
F_171 ( V_7 ) ;
F_262 ( V_7 ) ;
}
void F_267 ( struct V_6 * V_7 , T_2 V_197 ,
unsigned int V_448 )
{
T_2 V_25 = V_7 -> V_164 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_163 ; V_18 ++ , V_25 ++ ) {
unsigned int V_63 = F_46 ( V_7 , V_25 ) ;
unsigned int V_449 = V_448 ;
if ( ! ( V_63 & V_450 ) )
continue;
if ( V_7 -> V_451 ) {
V_449 = V_7 -> V_451 ( V_7 , V_25 , V_448 ) ;
if ( V_449 != V_448 && V_448 == V_452 )
continue;
}
F_24 ( V_7 , V_25 , 0 , V_453 ,
V_449 ) ;
}
}
static bool F_126 ( struct V_6 * V_7 , T_2 V_197 ,
unsigned int V_448 )
{
int V_454 = F_27 ( V_7 , V_197 , V_455 ) ;
if ( V_454 == - 1 )
return false ;
if ( V_454 & V_448 )
return true ;
else
return false ;
}
static unsigned int F_268 ( struct V_6 * V_7 ,
T_2 V_197 ,
unsigned int V_448 )
{
unsigned long V_456 = V_457 + F_269 ( 500 ) ;
unsigned int V_449 , V_458 ;
for (; ; ) {
V_449 = F_23 ( V_7 , V_197 , 0 ,
V_459 , 0 ) ;
if ( V_449 & V_460 )
break;
V_458 = ( V_449 >> 4 ) & 0x0f ;
if ( V_458 == V_448 )
break;
if ( F_270 ( V_457 , V_456 ) )
break;
F_141 ( 1 ) ;
}
return V_449 ;
}
unsigned int F_271 ( struct V_6 * V_7 ,
T_2 V_25 ,
unsigned int V_448 )
{
if ( V_25 == V_7 -> V_137 || V_25 == V_7 -> V_138 )
return V_448 ;
if ( V_448 == V_452 &&
F_47 ( F_46 ( V_7 , V_25 ) ) == V_83 &&
( F_159 ( V_7 , V_25 ) & V_461 ) ) {
int V_462 = F_23 ( V_7 , V_25 , 0 ,
V_463 , 0 ) ;
if ( V_462 & 0x02 )
return V_234 ;
}
return V_448 ;
}
static unsigned int F_127 ( struct V_6 * V_7 ,
unsigned int V_448 )
{
T_2 V_197 = V_7 -> V_137 ? V_7 -> V_137 : V_7 -> V_138 ;
int V_313 ;
unsigned int V_449 ;
int V_26 = 0 ;
if ( V_448 == V_452 ) {
if ( V_7 -> V_218 < 0 )
F_141 ( V_7 -> V_231 ? 10 : 100 ) ;
else if ( V_7 -> V_218 > 0 )
F_141 ( V_7 -> V_218 ) ;
V_26 = V_36 ;
}
for ( V_313 = 0 ; V_313 < 10 ; V_313 ++ ) {
if ( V_7 -> V_106 . V_464 )
V_7 -> V_106 . V_464 ( V_7 , V_197 ,
V_448 ) ;
else {
V_449 = V_448 ;
if ( V_7 -> V_451 )
V_449 = V_7 -> V_451 ( V_7 , V_197 , V_449 ) ;
if ( V_449 == V_448 || V_448 != V_452 )
F_23 ( V_7 , V_197 , V_26 ,
V_453 ,
V_449 ) ;
F_267 ( V_7 , V_197 , V_448 ) ;
}
V_449 = F_268 ( V_7 , V_197 , V_448 ) ;
if ( ! ( V_449 & V_460 ) )
break;
}
return V_449 ;
}
static void F_272 ( struct V_6 * V_7 )
{
T_2 V_25 = V_7 -> V_164 ;
int V_18 ;
if ( ! V_7 -> V_451 )
return;
for ( V_18 = 0 ; V_18 < V_7 -> V_163 ; V_18 ++ , V_25 ++ ) {
unsigned int V_63 = F_46 ( V_7 , V_25 ) ;
unsigned int V_179 ;
if ( ! ( V_63 & V_450 ) )
continue;
V_179 = V_7 -> V_451 ( V_7 , V_25 , V_234 ) ;
if ( V_179 == V_234 )
continue;
if ( ! F_273 ( V_7 , V_25 , V_179 ) )
F_24 ( V_7 , V_25 , 0 ,
V_453 , V_179 ) ;
}
}
static void F_274 ( struct V_6 * V_7 )
{
if ( V_7 -> V_465 . V_4 )
F_25 ( V_7 , V_7 -> V_465 . V_4 ) ;
}
static inline void F_274 ( struct V_6 * V_7 ) {}
static unsigned int F_275 ( struct V_6 * V_7 , bool V_466 )
{
unsigned int V_449 ;
V_7 -> V_467 = 1 ;
if ( V_7 -> V_106 . V_468 )
V_7 -> V_106 . V_468 ( V_7 ) ;
F_146 ( V_7 ) ;
V_449 = F_127 ( V_7 , V_452 ) ;
if ( ! V_466 )
F_102 ( & V_7 -> V_187 ) ;
F_199 ( & V_7 -> V_221 ) ;
F_276 ( V_7 ) ;
F_277 ( V_7 ) ;
V_7 -> V_469 = 0 ;
V_7 -> V_470 = 0 ;
V_7 -> V_471 = V_457 ;
F_200 ( & V_7 -> V_221 ) ;
V_7 -> V_467 = 0 ;
return V_449 ;
}
static void F_278 ( struct V_6 * V_7 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_192 . V_262 . V_175 ; V_18 ++ ) {
struct V_212 * V_31 ;
V_31 = F_83 ( & V_7 -> V_192 . V_262 , V_18 ) ;
V_31 -> V_254 = 1 ;
}
for ( V_18 = 0 ; V_18 < V_7 -> V_191 . V_262 . V_175 ; V_18 ++ ) {
struct V_211 * V_472 ;
V_472 = F_83 ( & V_7 -> V_191 . V_262 , V_18 ) ;
V_472 -> V_269 . V_254 = 1 ;
}
}
static void F_279 ( struct V_6 * V_7 )
{
V_7 -> V_467 = 1 ;
F_278 ( V_7 ) ;
F_8 ( V_7 ) ;
F_127 ( V_7 , V_234 ) ;
F_91 ( V_7 ) ;
F_274 ( V_7 ) ;
F_93 ( V_7 ) ;
if ( V_7 -> V_106 . V_473 )
V_7 -> V_106 . V_473 ( V_7 ) ;
else {
if ( V_7 -> V_106 . V_474 )
V_7 -> V_106 . V_474 ( V_7 ) ;
F_171 ( V_7 ) ;
F_262 ( V_7 ) ;
}
if ( V_7 -> V_183 )
F_92 ( & V_7 -> V_182 . V_101 ) ;
else
F_280 ( V_7 ) ;
V_7 -> V_467 = 0 ;
F_19 ( V_7 ) ;
}
int F_281 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_29 (codec, &bus->codec_list, list) {
int V_33 = F_282 ( V_7 ) ;
if ( V_33 < 0 ) {
F_14 ( V_7 ,
L_72 ,
V_7 -> V_30 , V_33 ) ;
V_33 = F_202 ( V_7 ) ;
if ( V_33 < 0 ) {
F_14 ( V_7 ,
L_73 ) ;
return V_33 ;
}
}
}
return 0 ;
}
static int F_283 ( struct V_6 * V_7 )
{
int V_18 , V_475 , V_33 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_355 ; V_18 ++ ) {
for ( V_475 = 0 ; V_475 < 2 ; V_475 ++ ) {
struct V_476 * V_354 = V_7 -> V_358 [ V_18 ] . V_354 ;
struct V_477 * V_478 =
& V_7 -> V_358 [ V_18 ] . V_479 [ V_475 ] ;
struct V_480 * V_481 ;
const struct V_482 * V_483 ;
if ( V_7 -> V_358 [ V_18 ] . V_484 )
continue;
if ( ! V_354 || ! V_478 -> V_485 )
continue;
V_483 = V_478 -> V_481 ? V_478 -> V_481 : V_486 ;
V_33 = F_284 ( V_354 , V_475 , V_483 ,
V_478 -> V_487 ,
0 , & V_481 ) ;
if ( V_33 < 0 )
return V_33 ;
V_481 -> V_488 = V_489 ;
}
}
return 0 ;
}
int F_282 ( struct V_6 * V_7 )
{
int V_33 = 0 ;
F_274 ( V_7 ) ;
if ( V_7 -> V_106 . V_474 )
V_33 = V_7 -> V_106 . V_474 ( V_7 ) ;
if ( ! V_33 && V_7 -> V_106 . V_490 )
V_33 = V_7 -> V_106 . V_490 ( V_7 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_283 ( V_7 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_7 -> V_183 )
F_92 ( & V_7 -> V_182 . V_101 ) ;
else
F_280 ( V_7 ) ;
F_272 ( V_7 ) ;
return 0 ;
}
unsigned int F_285 ( struct V_6 * V_7 ,
unsigned int V_491 ,
unsigned int V_492 ,
unsigned int V_248 ,
unsigned int V_493 ,
unsigned short V_494 )
{
int V_18 ;
unsigned int V_29 = 0 ;
for ( V_18 = 0 ; V_495 [ V_18 ] . V_496 ; V_18 ++ )
if ( V_495 [ V_18 ] . V_496 == V_491 ) {
V_29 = V_495 [ V_18 ] . V_497 ;
break;
}
if ( ! V_495 [ V_18 ] . V_496 ) {
F_21 ( V_7 , L_74 , V_491 ) ;
return 0 ;
}
if ( V_492 == 0 || V_492 > 8 ) {
F_21 ( V_7 , L_75 , V_492 ) ;
return 0 ;
}
V_29 |= V_492 - 1 ;
switch ( F_286 ( V_248 ) ) {
case 8 :
V_29 |= V_498 ;
break;
case 16 :
V_29 |= V_499 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_493 >= 32 || V_248 == V_500 )
V_29 |= V_501 ;
else if ( V_493 >= 24 )
V_29 |= V_502 ;
else
V_29 |= V_503 ;
break;
default:
F_21 ( V_7 , L_76 ,
F_286 ( V_248 ) ) ;
return 0 ;
}
if ( V_494 & V_417 )
V_29 |= V_504 ;
return V_29 ;
}
static unsigned int F_287 ( struct V_6 * V_7 , T_2 V_25 ,
int V_276 )
{
unsigned int V_29 = 0 ;
if ( V_25 != V_7 -> V_137 &&
( F_46 ( V_7 , V_25 ) & V_505 ) )
V_29 = F_27 ( V_7 , V_25 , V_506 ) ;
if ( ! V_29 || V_29 == - 1 )
V_29 = F_27 ( V_7 , V_7 -> V_137 , V_506 ) ;
if ( ! V_29 || V_29 == - 1 )
return 0 ;
return V_29 ;
}
static unsigned int F_288 ( struct V_6 * V_7 , T_2 V_25 )
{
return F_154 ( V_7 , V_25 , 0 , F_289 ( V_25 ) ,
F_287 ) ;
}
static unsigned int F_290 ( struct V_6 * V_7 , T_2 V_25 ,
int V_276 )
{
unsigned int V_359 = F_27 ( V_7 , V_25 , V_507 ) ;
if ( ! V_359 || V_359 == - 1 )
V_359 = F_27 ( V_7 , V_7 -> V_137 , V_507 ) ;
if ( ! V_359 || V_359 == - 1 )
return 0 ;
return V_359 ;
}
static unsigned int F_291 ( struct V_6 * V_7 , T_2 V_25 )
{
return F_154 ( V_7 , V_25 , 0 , F_292 ( V_25 ) ,
F_290 ) ;
}
int F_293 ( struct V_6 * V_7 , T_2 V_25 ,
T_1 * V_508 , T_8 * V_509 , unsigned int * V_510 )
{
unsigned int V_18 , V_29 , V_63 ;
V_63 = F_46 ( V_7 , V_25 ) ;
V_29 = F_288 ( V_7 , V_25 ) ;
if ( V_508 ) {
T_1 V_511 = 0 ;
for ( V_18 = 0 ; V_18 < V_512 ; V_18 ++ ) {
if ( V_29 & ( 1 << V_18 ) )
V_511 |= V_495 [ V_18 ] . V_513 ;
}
if ( V_511 == 0 ) {
F_14 ( V_7 ,
L_77 ,
V_25 , V_29 ,
( V_63 & V_505 ) ? 1 : 0 ) ;
return - V_76 ;
}
* V_508 = V_511 ;
}
if ( V_509 || V_510 ) {
T_8 V_514 = 0 ;
unsigned int V_359 , V_515 ;
V_359 = F_291 ( V_7 , V_25 ) ;
if ( ! V_359 )
return - V_76 ;
V_515 = 0 ;
if ( V_359 & V_516 ) {
if ( V_29 & V_517 ) {
V_514 |= V_518 ;
V_515 = 8 ;
}
if ( V_29 & V_519 ) {
V_514 |= V_520 ;
V_515 = 16 ;
}
if ( V_63 & V_86 ) {
if ( V_29 & V_521 )
V_514 |= V_522 ;
if ( V_29 & ( V_523 | V_524 ) )
V_514 |= V_525 ;
if ( V_29 & V_524 )
V_515 = 24 ;
else if ( V_29 & V_523 )
V_515 = 20 ;
} else if ( V_29 & ( V_523 | V_524 |
V_521 ) ) {
V_514 |= V_525 ;
if ( V_29 & V_521 )
V_515 = 32 ;
else if ( V_29 & V_524 )
V_515 = 24 ;
else if ( V_29 & V_523 )
V_515 = 20 ;
}
}
#if 0
if (streams & AC_SUPFMT_FLOAT32) {
formats |= SNDRV_PCM_FMTBIT_FLOAT_LE;
if (!bps)
bps = 32;
}
#endif
if ( V_359 == V_526 ) {
V_514 |= V_518 ;
V_515 = 8 ;
}
if ( V_514 == 0 ) {
F_14 ( V_7 ,
L_78 ,
V_25 , V_29 ,
( V_63 & V_505 ) ? 1 : 0 ,
V_359 ) ;
return - V_76 ;
}
if ( V_509 )
* V_509 = V_514 ;
if ( V_510 )
* V_510 = V_515 ;
}
return 0 ;
}
int F_294 ( struct V_6 * V_7 , T_2 V_25 ,
unsigned int V_248 )
{
int V_18 ;
unsigned int V_29 = 0 , V_491 , V_479 ;
V_29 = F_288 ( V_7 , V_25 ) ;
if ( ! V_29 )
return 0 ;
V_491 = V_248 & 0xff00 ;
for ( V_18 = 0 ; V_18 < V_512 ; V_18 ++ )
if ( V_495 [ V_18 ] . V_497 == V_491 ) {
if ( V_29 & ( 1 << V_18 ) )
break;
return 0 ;
}
if ( V_18 >= V_512 )
return 0 ;
V_479 = F_291 ( V_7 , V_25 ) ;
if ( ! V_479 )
return 0 ;
if ( V_479 & V_516 ) {
switch ( V_248 & 0xf0 ) {
case 0x00 :
if ( ! ( V_29 & V_517 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_29 & V_519 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_29 & V_523 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_29 & V_524 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_29 & V_521 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_295 ( struct V_477 * V_478 ,
struct V_6 * V_7 ,
struct V_527 * V_528 )
{
return 0 ;
}
static int F_296 ( struct V_477 * V_478 ,
struct V_6 * V_7 ,
unsigned int V_242 ,
unsigned int V_248 ,
struct V_527 * V_528 )
{
F_142 ( V_7 , V_478 -> V_25 , V_242 , 0 , V_248 ) ;
return 0 ;
}
static int F_297 ( struct V_477 * V_478 ,
struct V_6 * V_7 ,
struct V_527 * V_528 )
{
F_298 ( V_7 , V_478 -> V_25 ) ;
return 0 ;
}
static int F_299 ( struct V_6 * V_7 ,
struct V_477 * V_266 )
{
int V_33 ;
if ( V_266 -> V_25 && ( ! V_266 -> V_511 || ! V_266 -> V_514 ) ) {
V_33 = F_293 ( V_7 , V_266 -> V_25 ,
V_266 -> V_511 ? NULL : & V_266 -> V_511 ,
V_266 -> V_514 ? NULL : & V_266 -> V_514 ,
V_266 -> V_493 ? NULL : & V_266 -> V_493 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_266 -> V_12 . V_529 == NULL )
V_266 -> V_12 . V_529 = F_295 ;
if ( V_266 -> V_12 . V_530 == NULL )
V_266 -> V_12 . V_530 = F_295 ;
if ( V_266 -> V_12 . V_531 == NULL ) {
if ( F_43 ( ! V_266 -> V_25 ) )
return - V_61 ;
V_266 -> V_12 . V_531 = F_296 ;
}
if ( V_266 -> V_12 . V_532 == NULL ) {
if ( F_43 ( ! V_266 -> V_25 ) )
return - V_61 ;
V_266 -> V_12 . V_532 = F_297 ;
}
return 0 ;
}
int F_300 ( struct V_6 * V_7 ,
struct V_477 * V_478 ,
unsigned int V_479 ,
unsigned int V_248 ,
struct V_527 * V_528 )
{
int V_302 ;
F_2 ( & V_7 -> V_10 -> V_128 ) ;
V_302 = V_478 -> V_12 . V_531 ( V_478 , V_7 , V_479 , V_248 , V_528 ) ;
if ( V_302 >= 0 )
F_145 ( V_7 ) ;
F_4 ( & V_7 -> V_10 -> V_128 ) ;
return V_302 ;
}
void F_301 ( struct V_6 * V_7 ,
struct V_477 * V_478 ,
struct V_527 * V_528 )
{
F_2 ( & V_7 -> V_10 -> V_128 ) ;
V_478 -> V_12 . V_532 ( V_478 , V_7 , V_528 ) ;
F_4 ( & V_7 -> V_10 -> V_128 ) ;
}
static int F_302 ( struct V_9 * V_10 , unsigned int type )
{
static int V_533 [ V_534 ] [ 5 ] = {
[ V_535 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_438 ] = { 1 , - 1 } ,
[ V_437 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_536 ] = { 6 , - 1 } ,
} ;
int V_18 ;
if ( type >= V_534 ) {
F_59 ( V_10 -> V_108 -> V_109 , L_79 , type ) ;
return - V_61 ;
}
for ( V_18 = 0 ; V_533 [ type ] [ V_18 ] >= 0 ; V_18 ++ ) {
#ifndef F_303
if ( V_533 [ type ] [ V_18 ] >= 8 )
break;
#endif
if ( ! F_304 ( V_533 [ type ] [ V_18 ] , V_10 -> V_361 ) )
return V_533 [ type ] [ V_18 ] ;
}
#ifdef F_303
for ( V_18 = 10 ; V_18 < 32 ; V_18 ++ ) {
if ( ! F_304 ( V_18 , V_10 -> V_361 ) )
return V_18 ;
}
#endif
F_305 ( V_10 -> V_108 -> V_109 , L_80 ,
V_537 [ type ] ) ;
#ifndef F_303
F_305 ( V_10 -> V_108 -> V_109 ,
L_81 ) ;
#endif
return - V_39 ;
}
static int F_306 ( struct V_6 * V_7 , struct V_356 * V_354 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_477 * V_266 ;
int V_479 , V_33 ;
if ( F_43 ( ! V_354 -> V_143 ) )
return - V_61 ;
for ( V_479 = 0 ; V_479 < 2 ; V_479 ++ ) {
V_266 = & V_354 -> V_479 [ V_479 ] ;
if ( V_266 -> V_485 ) {
V_33 = F_299 ( V_7 , V_266 ) ;
if ( V_33 < 0 )
return V_33 ;
}
}
return V_10 -> V_12 . V_538 ( V_10 , V_7 , V_354 ) ;
}
int F_307 ( struct V_6 * V_7 )
{
unsigned int V_354 ;
int V_33 ;
if ( ! V_7 -> V_355 ) {
if ( ! V_7 -> V_106 . V_539 )
return 0 ;
V_33 = V_7 -> V_106 . V_539 ( V_7 ) ;
if ( V_33 < 0 ) {
F_14 ( V_7 ,
L_82 ,
V_7 -> V_30 , V_33 ) ;
V_33 = F_202 ( V_7 ) ;
if ( V_33 < 0 ) {
F_14 ( V_7 ,
L_73 ) ;
return V_33 ;
}
}
}
for ( V_354 = 0 ; V_354 < V_7 -> V_355 ; V_354 ++ ) {
struct V_356 * V_357 = & V_7 -> V_358 [ V_354 ] ;
int V_109 ;
if ( ! V_357 -> V_479 [ 0 ] . V_485 && ! V_357 -> V_479 [ 1 ] . V_485 )
continue;
if ( ! V_357 -> V_354 ) {
V_109 = F_302 ( V_7 -> V_10 , V_357 -> V_540 ) ;
if ( V_109 < 0 )
continue;
V_357 -> V_113 = V_109 ;
V_33 = F_306 ( V_7 , V_357 ) ;
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
int F_308 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_29 (codec, &bus->codec_list, list) {
int V_33 = F_307 ( V_7 ) ;
if ( V_33 < 0 )
return V_33 ;
}
return 0 ;
}
int F_309 ( struct V_6 * V_7 ,
const struct V_433 * V_541 )
{
int V_33 ;
for (; V_541 -> V_143 ; V_541 ++ ) {
struct V_307 * V_342 ;
int V_30 = 0 , V_264 = 0 ;
if ( V_541 -> V_339 == - 1 )
continue;
for (; ; ) {
V_342 = F_224 ( V_541 , V_7 ) ;
if ( ! V_342 )
return - V_54 ;
if ( V_30 > 0 )
V_342 -> V_136 . V_113 = V_30 ;
if ( V_264 > 0 )
V_342 -> V_136 . V_281 = V_264 ;
V_33 = F_192 ( V_7 , 0 , V_342 ) ;
if ( ! V_33 )
break;
if ( ! V_30 && V_7 -> V_30 )
V_30 = V_7 -> V_30 ;
else if ( ! V_264 && ! V_541 -> V_281 ) {
V_264 = F_191 ( V_7 ,
V_541 -> V_143 , 0 ) ;
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
unsigned int V_449 ;
F_199 ( & V_7 -> V_221 ) ;
if ( V_7 -> V_470 > 0 ) {
F_200 ( & V_7 -> V_221 ) ;
return;
}
if ( ! V_7 -> V_469 || V_7 -> V_542 ) {
V_7 -> V_470 = 0 ;
F_200 ( & V_7 -> V_221 ) ;
return;
}
F_200 ( & V_7 -> V_221 ) ;
V_449 = F_275 ( V_7 , true ) ;
if ( ! V_10 -> V_233 && ( V_449 & V_543 ) )
F_7 ( V_7 , false ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
F_199 ( & V_7 -> V_221 ) ;
V_7 -> V_542 ++ ;
V_7 -> V_469 = 1 ;
V_7 -> V_471 = V_457 ;
F_200 ( & V_7 -> V_221 ) ;
F_7 ( V_7 , true ) ;
}
void F_276 ( struct V_6 * V_7 )
{
unsigned long V_544 = V_457 - V_7 -> V_471 ;
if ( V_7 -> V_469 )
V_7 -> V_545 += V_544 ;
else
V_7 -> V_546 += V_544 ;
V_7 -> V_471 += V_544 ;
}
static void F_310 ( struct V_6 * V_7 , bool V_547 )
{
if ( ( V_7 -> V_469 || V_7 -> V_470 > 0 ) &&
! ( V_547 && V_7 -> V_470 < 0 ) )
return;
F_200 ( & V_7 -> V_221 ) ;
F_102 ( & V_7 -> V_187 ) ;
F_199 ( & V_7 -> V_221 ) ;
if ( V_7 -> V_469 ) {
if ( V_7 -> V_470 < 0 )
V_7 -> V_470 = 0 ;
return;
}
F_311 ( V_7 ) ;
F_276 ( V_7 ) ;
V_7 -> V_469 = 1 ;
V_7 -> V_471 = V_457 ;
V_7 -> V_470 = 1 ;
F_200 ( & V_7 -> V_221 ) ;
F_279 ( V_7 ) ;
F_199 ( & V_7 -> V_221 ) ;
V_7 -> V_470 = 0 ;
}
static void F_312 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_469 || V_7 -> V_542 || V_7 -> V_470 )
return;
if ( V_127 ( V_7 ) ) {
V_7 -> V_470 = - 1 ;
F_95 ( V_7 -> V_10 -> V_98 , & V_7 -> V_187 ,
F_269 ( V_127 ( V_7 ) * 1000 ) ) ;
}
}
void F_313 ( struct V_6 * V_7 , int V_544 , bool V_548 )
{
F_199 ( & V_7 -> V_221 ) ;
V_7 -> V_542 += V_544 ;
F_314 ( V_7 ) ;
if ( V_544 > 0 )
F_310 ( V_7 , V_548 ) ;
else
F_312 ( V_7 ) ;
F_200 ( & V_7 -> V_221 ) ;
}
int F_315 ( struct V_6 * V_7 ,
struct V_549 * V_550 ,
T_2 V_25 )
{
const struct V_551 * V_51 ;
int V_280 , V_552 ;
if ( ! V_550 -> V_553 )
return 0 ;
for ( V_51 = V_550 -> V_553 ; V_51 -> V_25 ; V_51 ++ ) {
if ( V_51 -> V_25 == V_25 )
break;
}
if ( ! V_51 -> V_25 )
return 0 ;
for ( V_51 = V_550 -> V_553 ; V_51 -> V_25 ; V_51 ++ ) {
for ( V_280 = 0 ; V_280 < 2 ; V_280 ++ ) {
V_552 = F_165 ( V_7 , V_51 -> V_25 , V_280 , V_51 -> V_276 ,
V_51 -> V_264 ) ;
if ( ! ( V_552 & V_296 ) && V_552 > 0 ) {
if ( ! V_550 -> V_469 ) {
V_550 -> V_469 = 1 ;
F_16 ( V_7 ) ;
}
return 1 ;
}
}
}
if ( V_550 -> V_469 ) {
V_550 -> V_469 = 0 ;
F_19 ( V_7 ) ;
}
return 0 ;
}
int F_316 ( struct V_6 * V_7 ,
struct V_309 * V_310 ,
const struct V_554 * V_555 ,
int V_556 )
{
V_310 -> type = V_385 ;
V_310 -> V_313 = 1 ;
V_310 -> V_314 . V_386 . V_349 = V_556 ;
if ( V_310 -> V_314 . V_386 . V_343 >= V_556 )
V_310 -> V_314 . V_386 . V_343 = V_556 - 1 ;
sprintf ( V_310 -> V_314 . V_386 . V_143 , L_84 ,
V_555 [ V_310 -> V_314 . V_386 . V_343 ] . V_492 ) ;
return 0 ;
}
int F_317 ( struct V_6 * V_7 ,
struct V_319 * V_320 ,
const struct V_554 * V_555 ,
int V_556 ,
int V_557 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_556 ; V_18 ++ ) {
if ( V_557 == V_555 [ V_18 ] . V_492 ) {
V_320 -> V_314 . V_386 . V_343 [ 0 ] = V_18 ;
break;
}
}
return 0 ;
}
int F_318 ( struct V_6 * V_7 ,
struct V_319 * V_320 ,
const struct V_554 * V_555 ,
int V_556 ,
int * V_558 )
{
unsigned int V_559 ;
V_559 = V_320 -> V_314 . V_386 . V_343 [ 0 ] ;
if ( V_559 >= V_556 )
return - V_61 ;
if ( * V_558 == V_555 [ V_559 ] . V_492 )
return 0 ;
* V_558 = V_555 [ V_559 ] . V_492 ;
if ( V_555 [ V_559 ] . V_560 )
F_265 ( V_7 , V_555 [ V_559 ] . V_560 ) ;
return 1 ;
}
int F_319 ( const struct V_561 * V_562 ,
struct V_309 * V_310 )
{
unsigned int V_281 ;
V_310 -> type = V_385 ;
V_310 -> V_313 = 1 ;
V_310 -> V_314 . V_386 . V_349 = V_562 -> V_563 ;
if ( ! V_562 -> V_563 )
return 0 ;
V_281 = V_310 -> V_314 . V_386 . V_343 ;
if ( V_281 >= V_562 -> V_563 )
V_281 = V_562 -> V_563 - 1 ;
strcpy ( V_310 -> V_314 . V_386 . V_143 , V_562 -> V_349 [ V_281 ] . V_564 ) ;
return 0 ;
}
int F_320 ( struct V_6 * V_7 ,
const struct V_561 * V_562 ,
struct V_319 * V_320 ,
T_2 V_25 ,
unsigned int * V_565 )
{
unsigned int V_264 ;
if ( ! V_562 -> V_563 )
return 0 ;
V_264 = V_320 -> V_314 . V_386 . V_343 [ 0 ] ;
if ( V_264 >= V_562 -> V_563 )
V_264 = V_562 -> V_563 - 1 ;
if ( * V_565 == V_264 )
return 0 ;
F_243 ( V_7 , V_25 , 0 , V_566 ,
V_562 -> V_349 [ V_264 ] . V_281 ) ;
* V_565 = V_264 ;
return 1 ;
}
int F_321 ( struct V_307 * V_308 ,
struct V_309 * V_310 ,
int V_563 , const char * const * V_384 )
{
static const char * const V_567 [] = {
L_85 , L_86
} ;
if ( ! V_384 || ! V_563 ) {
V_563 = 2 ;
V_384 = V_567 ;
}
V_310 -> type = V_385 ;
V_310 -> V_313 = 1 ;
V_310 -> V_314 . V_386 . V_349 = V_563 ;
if ( V_310 -> V_314 . V_386 . V_343 >= V_310 -> V_314 . V_386 . V_349 )
V_310 -> V_314 . V_386 . V_343 = V_310 -> V_314 . V_386 . V_349 - 1 ;
strcpy ( V_310 -> V_314 . V_386 . V_143 ,
V_384 [ V_310 -> V_314 . V_386 . V_343 ] ) ;
return 0 ;
}
static void F_322 ( struct V_6 * V_7 , T_2 V_25 ,
unsigned int V_242 , unsigned int V_248 )
{
struct V_214 * V_414 ;
unsigned int V_568 ;
bool V_569 ;
V_414 = F_250 ( V_7 , V_25 ) ;
V_568 = F_23 ( V_7 , V_25 , 0 ,
V_250 , 0 ) ;
V_569 = V_7 -> V_365 &&
( V_414 -> V_428 & V_429 ) &&
V_568 != V_248 ;
if ( V_569 )
F_244 ( V_7 , V_25 ,
V_414 -> V_428 & ~ V_429 & 0xff ,
- 1 ) ;
F_142 ( V_7 , V_25 , V_242 , 0 , V_248 ) ;
if ( V_7 -> V_364 ) {
const T_2 * V_423 ;
for ( V_423 = V_7 -> V_364 ; * V_423 ; V_423 ++ )
F_142 ( V_7 , * V_423 , V_242 , 0 ,
V_248 ) ;
}
if ( V_569 )
F_244 ( V_7 , V_25 ,
V_414 -> V_428 & 0xff , - 1 ) ;
}
static void F_323 ( struct V_6 * V_7 , T_2 V_25 )
{
F_298 ( V_7 , V_25 ) ;
if ( V_7 -> V_364 ) {
const T_2 * V_423 ;
for ( V_423 = V_7 -> V_364 ; * V_423 ; V_423 ++ )
F_298 ( V_7 , * V_423 ) ;
}
}
void F_324 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
if ( ! V_10 )
return;
F_29 (codec, &bus->codec_list, list) {
if ( F_325 ( V_7 ) &&
V_7 -> V_106 . V_570 )
V_7 -> V_106 . V_570 ( V_7 ) ;
}
}
int F_326 ( struct V_6 * V_7 ,
struct V_441 * V_442 )
{
F_2 ( & V_7 -> V_208 ) ;
if ( V_442 -> V_571 == V_572 )
F_323 ( V_7 , V_442 -> V_444 ) ;
V_442 -> V_571 = V_573 ;
F_4 ( & V_7 -> V_208 ) ;
return 0 ;
}
int F_327 ( struct V_6 * V_7 ,
struct V_441 * V_442 ,
unsigned int V_242 ,
unsigned int V_248 ,
struct V_527 * V_528 )
{
F_2 ( & V_7 -> V_208 ) ;
F_322 ( V_7 , V_442 -> V_444 , V_242 , V_248 ) ;
F_4 ( & V_7 -> V_208 ) ;
return 0 ;
}
int F_328 ( struct V_6 * V_7 ,
struct V_441 * V_442 )
{
F_2 ( & V_7 -> V_208 ) ;
F_323 ( V_7 , V_442 -> V_444 ) ;
F_4 ( & V_7 -> V_208 ) ;
return 0 ;
}
int F_329 ( struct V_6 * V_7 ,
struct V_441 * V_442 )
{
F_2 ( & V_7 -> V_208 ) ;
V_442 -> V_571 = 0 ;
F_4 ( & V_7 -> V_208 ) ;
return 0 ;
}
int F_330 ( struct V_6 * V_7 ,
struct V_441 * V_442 ,
struct V_527 * V_528 ,
struct V_477 * V_478 )
{
struct V_574 * V_575 = V_528 -> V_575 ;
V_575 -> V_576 . V_487 = V_442 -> V_557 ;
if ( V_442 -> V_444 ) {
if ( ! V_442 -> V_577 ) {
V_442 -> V_577 = V_478 -> V_511 ;
V_442 -> V_578 = V_478 -> V_514 ;
V_442 -> V_579 = V_478 -> V_493 ;
} else {
V_575 -> V_576 . V_511 = V_442 -> V_577 ;
V_575 -> V_576 . V_514 = V_442 -> V_578 ;
V_478 -> V_493 = V_442 -> V_579 ;
}
if ( ! V_442 -> V_580 ) {
F_293 ( V_7 , V_442 -> V_444 ,
& V_442 -> V_580 ,
& V_442 -> V_581 ,
& V_442 -> V_582 ) ;
}
F_2 ( & V_7 -> V_208 ) ;
if ( V_442 -> V_443 ) {
if ( ( V_575 -> V_576 . V_511 & V_442 -> V_580 ) &&
( V_575 -> V_576 . V_514 & V_442 -> V_581 ) ) {
V_575 -> V_576 . V_511 &= V_442 -> V_580 ;
V_575 -> V_576 . V_514 &= V_442 -> V_581 ;
if ( V_442 -> V_582 < V_478 -> V_493 )
V_478 -> V_493 = V_442 -> V_582 ;
} else {
V_442 -> V_443 = 0 ;
}
}
F_4 ( & V_7 -> V_208 ) ;
}
return F_331 ( V_528 -> V_575 , 0 ,
V_583 , 2 ) ;
}
int F_332 ( struct V_6 * V_7 ,
struct V_441 * V_442 ,
unsigned int V_242 ,
unsigned int V_248 ,
struct V_527 * V_528 )
{
const T_2 * V_189 = V_442 -> V_584 ;
int V_311 = V_528 -> V_575 -> V_492 ;
struct V_214 * V_414 ;
int V_18 ;
F_2 ( & V_7 -> V_208 ) ;
V_414 = F_250 ( V_7 , V_442 -> V_444 ) ;
if ( V_442 -> V_444 && V_442 -> V_443 &&
V_442 -> V_571 != V_573 ) {
if ( V_311 == 2 &&
F_294 ( V_7 , V_442 -> V_444 ,
V_248 ) &&
! ( V_414 -> V_406 & V_408 ) ) {
V_442 -> V_571 = V_572 ;
F_322 ( V_7 , V_442 -> V_444 ,
V_242 , V_248 ) ;
} else {
V_442 -> V_571 = 0 ;
F_323 ( V_7 , V_442 -> V_444 ) ;
}
}
F_4 ( & V_7 -> V_208 ) ;
F_142 ( V_7 , V_189 [ V_585 ] , V_242 ,
0 , V_248 ) ;
if ( ! V_442 -> V_586 &&
V_442 -> V_587 && V_442 -> V_587 != V_189 [ V_585 ] )
F_142 ( V_7 , V_442 -> V_587 , V_242 ,
0 , V_248 ) ;
for ( V_18 = 0 ; V_18 < F_10 ( V_442 -> V_588 ) ; V_18 ++ )
if ( ! V_442 -> V_586 && V_442 -> V_588 [ V_18 ] )
F_142 ( V_7 ,
V_442 -> V_588 [ V_18 ] ,
V_242 , 0 , V_248 ) ;
for ( V_18 = 1 ; V_18 < V_442 -> V_589 ; V_18 ++ ) {
if ( V_311 >= ( V_18 + 1 ) * 2 )
F_142 ( V_7 , V_189 [ V_18 ] , V_242 ,
V_18 * 2 , V_248 ) ;
else if ( ! V_442 -> V_586 )
F_142 ( V_7 , V_189 [ V_18 ] , V_242 ,
0 , V_248 ) ;
}
for ( V_18 = 0 ; V_18 < F_10 ( V_442 -> V_590 ) ; V_18 ++ ) {
int V_280 = 0 ;
if ( ! V_442 -> V_590 [ V_18 ] )
break;
if ( V_311 >= ( V_18 + 1 ) * 2 )
V_280 = V_18 * 2 ;
else if ( ! V_442 -> V_586 )
break;
F_142 ( V_7 , V_442 -> V_590 [ V_18 ] ,
V_242 , V_280 , V_248 ) ;
}
return 0 ;
}
int F_333 ( struct V_6 * V_7 ,
struct V_441 * V_442 )
{
const T_2 * V_189 = V_442 -> V_584 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_442 -> V_589 ; V_18 ++ )
F_298 ( V_7 , V_189 [ V_18 ] ) ;
if ( V_442 -> V_587 )
F_298 ( V_7 , V_442 -> V_587 ) ;
for ( V_18 = 0 ; V_18 < F_10 ( V_442 -> V_588 ) ; V_18 ++ )
if ( V_442 -> V_588 [ V_18 ] )
F_298 ( V_7 ,
V_442 -> V_588 [ V_18 ] ) ;
for ( V_18 = 0 ; V_18 < F_10 ( V_442 -> V_590 ) ; V_18 ++ )
if ( V_442 -> V_590 [ V_18 ] )
F_298 ( V_7 ,
V_442 -> V_590 [ V_18 ] ) ;
F_2 ( & V_7 -> V_208 ) ;
if ( V_442 -> V_444 && V_442 -> V_571 == V_572 ) {
F_323 ( V_7 , V_442 -> V_444 ) ;
V_442 -> V_571 = 0 ;
}
F_4 ( & V_7 -> V_208 ) ;
return 0 ;
}
unsigned int F_334 ( struct V_6 * V_7 , T_2 V_167 )
{
unsigned int V_591 ;
unsigned int V_244 ;
V_244 = F_23 ( V_7 , V_167 , 0 ,
V_172 , 0 ) ;
V_591 = F_159 ( V_7 , V_167 ) ;
V_591 = ( V_591 & V_592 ) >> V_593 ;
if ( ( V_591 & V_594 ) && V_244 != V_595 )
return V_596 ;
else if ( V_591 & V_597 )
return V_598 ;
else if ( V_591 & V_599 )
return V_600 ;
else if ( V_591 & V_601 )
return V_602 ;
return V_603 ;
}
unsigned int F_335 ( struct V_6 * V_7 ,
T_2 V_167 , unsigned int V_29 )
{
static unsigned int V_604 [] [ 2 ] = {
{ V_600 , V_599 } ,
{ V_596 , V_594 } ,
{ V_598 , V_597 } ,
{ V_602 , V_601 } ,
} ;
unsigned int V_605 ;
if ( ! V_29 )
return 0 ;
V_605 = F_159 ( V_7 , V_167 ) ;
if ( ! V_605 )
return V_29 ;
if ( V_29 & V_606 ) {
if ( ! ( V_605 & V_607 ) )
V_29 &= ~ ( V_606 | V_608 ) ;
else if ( ( V_29 & V_608 ) && ! ( V_605 & V_609 ) )
V_29 &= ~ V_608 ;
}
if ( V_29 & V_610 ) {
if ( ! ( V_605 & V_611 ) )
V_29 &= ~ ( V_610 | V_612 ) ;
else {
unsigned int V_613 , V_614 ;
int V_18 ;
V_613 = ( V_605 & V_592 ) >> V_593 ;
V_614 = V_29 & V_612 ;
for ( V_18 = 0 ; V_18 < F_10 ( V_604 ) ; V_18 ++ ) {
if ( V_614 == V_604 [ V_18 ] [ 0 ] &&
! ( V_613 & V_604 [ V_18 ] [ 1 ] ) ) {
if ( V_18 == F_10 ( V_604 ) - 1 )
V_614 = V_603 ;
else
V_614 = V_604 [ V_18 + 1 ] [ 0 ] ;
}
}
V_29 &= ~ V_612 ;
V_29 |= V_614 ;
}
}
return V_29 ;
}
int F_336 ( struct V_6 * V_7 , T_2 V_167 ,
unsigned int V_29 , bool V_615 )
{
V_29 = F_335 ( V_7 , V_167 , V_29 ) ;
F_88 ( V_7 , V_167 , V_29 ) ;
if ( V_615 )
return F_261 ( V_7 , V_167 , 0 ,
V_180 , V_29 ) ;
else
return F_24 ( V_7 , V_167 , 0 ,
V_180 , V_29 ) ;
}
int F_337 ( struct V_6 * V_7 ,
struct V_561 * V_562 , const char * V_564 ,
int V_281 , int * V_616 )
{
int V_18 , V_617 = 0 ;
if ( V_562 -> V_563 >= V_618 ) {
F_14 ( V_7 , L_87 ) ;
return - V_61 ;
}
for ( V_18 = 0 ; V_18 < V_562 -> V_563 ; V_18 ++ ) {
if ( ! strncmp ( V_564 , V_562 -> V_349 [ V_18 ] . V_564 , strlen ( V_564 ) ) )
V_617 ++ ;
}
if ( V_616 )
* V_616 = V_617 ;
if ( V_617 > 0 )
snprintf ( V_562 -> V_349 [ V_562 -> V_563 ] . V_564 ,
sizeof( V_562 -> V_349 [ V_562 -> V_563 ] . V_564 ) ,
L_88 , V_564 , V_617 ) ;
else
F_338 ( V_562 -> V_349 [ V_562 -> V_563 ] . V_564 , V_564 ,
sizeof( V_562 -> V_349 [ V_562 -> V_563 ] . V_564 ) ) ;
V_562 -> V_349 [ V_562 -> V_563 ] . V_281 = V_281 ;
V_562 -> V_563 ++ ;
return 0 ;
}
static void F_339 ( void * V_369 , T_9 V_619 )
{
F_275 ( V_369 , false ) ;
}
static void F_340 ( void * V_369 , T_9 V_619 )
{
F_279 ( V_369 ) ;
}
int F_341 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_342 ( V_620 ) ;
F_29 (codec, &bus->codec_list, list) {
F_102 ( & V_7 -> V_182 ) ;
if ( F_325 ( V_7 ) ) {
if ( V_10 -> V_193 > 1 )
F_343 ( F_339 , V_7 ,
& V_620 ) ;
else
F_275 ( V_7 , false ) ;
}
}
if ( V_10 -> V_193 > 1 )
F_344 ( & V_620 ) ;
return 0 ;
}
int F_345 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_342 ( V_620 ) ;
F_29 (codec, &bus->codec_list, list) {
if ( V_10 -> V_193 > 1 )
F_343 ( F_340 , V_7 , & V_620 ) ;
else
F_279 ( V_7 ) ;
}
if ( V_10 -> V_193 > 1 )
F_344 ( & V_620 ) ;
return 0 ;
}
void * F_81 ( struct V_173 * V_174 )
{
if ( F_43 ( ! V_174 -> V_621 ) )
return NULL ;
if ( V_174 -> V_175 >= V_174 -> V_622 ) {
int V_623 = V_174 -> V_622 + V_174 -> V_624 ;
int V_324 = ( V_623 + 1 ) * V_174 -> V_621 ;
void * V_625 ;
if ( F_43 ( V_623 >= 4096 ) )
return NULL ;
V_625 = F_346 ( V_174 -> V_4 , V_324 , V_53 | V_626 ) ;
if ( ! V_625 )
return NULL ;
V_174 -> V_4 = V_625 ;
V_174 -> V_622 = V_623 ;
}
return F_83 ( V_174 , V_174 -> V_175 ++ ) ;
}
void F_97 ( struct V_173 * V_174 )
{
F_37 ( V_174 -> V_4 ) ;
V_174 -> V_175 = 0 ;
V_174 -> V_622 = 0 ;
V_174 -> V_4 = NULL ;
}
void F_347 ( int V_354 , char * V_262 , int V_627 )
{
static unsigned int V_277 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_18 , V_628 ;
for ( V_18 = 0 , V_628 = 0 ; V_18 < F_10 ( V_277 ) ; V_18 ++ )
if ( V_354 & ( V_517 << V_18 ) )
V_628 += snprintf ( V_262 + V_628 , V_627 - V_628 , L_89 , V_277 [ V_18 ] ) ;
V_262 [ V_628 ] = '\0' ;
}
