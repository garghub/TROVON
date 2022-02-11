void F_1 ( struct V_1 * V_1 )
{
struct V_2 T_1 * V_3 = V_1 -> V_3 ;
unsigned long V_4 ;
F_2 ( & V_1 -> V_5 , V_4 ) ;
if ( F_3 ( V_1 ) & V_6 )
F_4 ( & V_3 -> V_7 , 0UL ) ;
F_5 ( & V_1 -> V_5 , V_4 ) ;
}
void F_6 ( struct V_8 * V_9 )
{
struct V_1 * V_1 ;
unsigned long V_4 ;
F_2 ( & V_10 , V_4 ) ;
F_7 (spu, &spu_full_list, full_list) {
if ( V_1 -> V_9 == V_9 )
F_1 ( V_1 ) ;
}
F_5 ( & V_10 , V_4 ) ;
}
static inline void F_8 ( struct V_8 * V_9 )
{
int V_11 = ( V_12 > 1 ) ? V_12 : V_12 + 1 ;
F_9 ( F_10 ( F_11 ( V_9 ) ) , V_11 ) ;
}
void F_12 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
unsigned long V_4 ;
F_2 ( & V_10 , V_4 ) ;
V_1 -> V_9 = V_9 ;
F_5 ( & V_10 , V_4 ) ;
if ( V_9 )
F_8 ( V_9 ) ;
}
int F_13 ( void )
{
return V_13 [ V_14 ] . V_15 != 0 ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_2 T_1 * V_3 = V_1 -> V_3 ;
if ( ! F_15 ( V_16 , & V_1 -> V_4 ) )
F_4 ( & V_3 -> V_17 , V_18 ) ;
else {
F_16 ( V_19 , & V_1 -> V_4 ) ;
F_17 () ;
}
}
static inline void F_18 ( struct V_1 * V_1 , int V_20 , struct V_21 * V_22 )
{
struct V_2 T_1 * V_3 = V_1 -> V_3 ;
F_19 ( L_1 ,
V_23 , V_20 , V_22 -> V_24 , V_22 -> V_25 ) ;
F_4 ( & V_3 -> V_26 , V_20 ) ;
F_4 ( & V_3 -> V_27 , 0 ) ;
F_4 ( & V_3 -> V_28 , V_22 -> V_24 ) ;
F_4 ( & V_3 -> V_27 , V_22 -> V_25 ) ;
}
static int F_20 ( struct V_1 * V_1 , unsigned long V_29 )
{
struct V_21 V_22 ;
int V_30 ;
V_30 = F_21 ( V_1 -> V_9 , V_29 , & V_22 ) ;
if ( V_30 )
return V_30 ;
F_18 ( V_1 , V_1 -> V_31 , & V_22 ) ;
V_1 -> V_31 ++ ;
if ( V_1 -> V_31 >= 8 )
V_1 -> V_31 = 0 ;
F_14 ( V_1 ) ;
V_1 -> V_32 . V_33 ++ ;
return 0 ;
}
static int F_22 ( struct V_1 * V_1 , unsigned long V_29 , T_2 V_34 )
{
int V_30 ;
F_19 ( L_2 , V_23 , V_34 , V_29 ) ;
if ( ( V_34 & V_35 ) &&
( F_23 ( V_29 ) != V_36 ) ) {
F_24 ( & V_1 -> V_5 ) ;
V_30 = F_25 ( V_29 , V_37 , 0x300 ) ;
F_26 ( & V_1 -> V_5 ) ;
if ( ! V_30 ) {
F_14 ( V_1 ) ;
return 0 ;
}
}
V_1 -> V_38 = V_29 ;
V_1 -> V_39 = V_34 ;
V_1 -> V_40 ( V_1 , 1 ) ;
V_1 -> V_38 = 0 ;
V_1 -> V_39 = 0 ;
return 0 ;
}
static void F_27 ( void * V_41 , struct V_21 * V_22 )
{
unsigned long V_29 = ( unsigned long ) V_41 ;
T_2 V_42 ;
if ( F_23 ( V_29 ) == V_43 )
V_42 = V_13 [ V_44 ] . V_45 ;
else
V_42 = V_13 [ V_46 ] . V_45 ;
V_22 -> V_24 = ( F_28 ( V_29 , V_47 ) << V_48 ) |
V_49 | V_42 ;
V_22 -> V_25 = ( V_29 & V_50 ) | V_51 ;
}
static inline int F_29 ( struct V_21 * V_52 , int V_53 ,
void * V_54 )
{
unsigned long V_29 = ( unsigned long ) V_54 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_53 ; V_55 ++ )
if ( ! ( ( V_52 [ V_55 ] . V_25 ^ V_29 ) & V_50 ) )
return 1 ;
return 0 ;
}
void F_30 ( struct V_1 * V_1 , struct V_56 * V_57 ,
void * V_58 , int V_59 )
{
struct V_21 V_52 [ 4 ] ;
int V_55 , V_53 = 0 ;
void * V_60 [] = {
V_57 , ( void * ) V_57 + sizeof( * V_57 ) - 1 ,
V_58 , V_58 + V_59 - 1
} ;
for ( V_55 = 0 ; V_55 < F_31 ( V_60 ) ; V_55 ++ ) {
if ( F_29 ( V_52 , V_53 , V_60 [ V_55 ] ) )
continue;
F_27 ( V_60 [ V_55 ] , & V_52 [ V_53 ] ) ;
V_53 ++ ;
}
F_32 ( & V_1 -> V_5 ) ;
for ( V_55 = 0 ; V_55 < V_53 ; V_55 ++ )
F_18 ( V_1 , V_55 , & V_52 [ V_55 ] ) ;
F_33 ( & V_1 -> V_5 ) ;
}
static T_3
F_34 ( int V_61 , void * V_62 )
{
struct V_1 * V_1 ;
unsigned long V_63 , V_64 ;
V_1 = V_62 ;
F_26 ( & V_1 -> V_5 ) ;
V_64 = F_35 ( V_1 , 0 ) ;
V_63 = F_36 ( V_1 , 0 ) & V_64 ;
V_1 -> V_65 |= V_63 ;
V_1 -> V_66 = F_37 ( V_1 ) ;
V_1 -> V_40 ( V_1 , 0 ) ;
V_1 -> V_65 = 0 ;
V_1 -> V_66 = 0 ;
F_38 ( V_1 , 0 , V_63 ) ;
F_24 ( & V_1 -> V_5 ) ;
return V_67 ;
}
static T_3
F_39 ( int V_61 , void * V_62 )
{
struct V_1 * V_1 ;
unsigned long V_63 , V_64 , V_68 , V_34 ;
V_1 = V_62 ;
F_26 ( & V_1 -> V_5 ) ;
V_64 = F_35 ( V_1 , 1 ) ;
V_63 = F_36 ( V_1 , 1 ) & V_64 ;
V_68 = F_37 ( V_1 ) ;
V_34 = F_40 ( V_1 ) ;
if ( V_63 & V_69 )
F_41 ( V_1 , 0ul ) ;
F_38 ( V_1 , 1 , V_63 ) ;
F_19 ( L_3 , V_23 , V_64 , V_63 ,
V_68 , V_34 ) ;
if ( V_63 & V_70 )
F_20 ( V_1 , V_68 ) ;
if ( V_63 & V_69 )
F_22 ( V_1 , V_68 , V_34 ) ;
if ( V_63 & V_71 )
;
if ( V_63 & V_72 )
;
V_1 -> V_39 = 0 ;
V_1 -> V_38 = 0 ;
F_24 ( & V_1 -> V_5 ) ;
return V_63 ? V_67 : V_73 ;
}
static T_3
F_42 ( int V_61 , void * V_62 )
{
struct V_1 * V_1 ;
unsigned long V_63 ;
unsigned long V_64 ;
const int V_74 =
V_75 | V_76 ;
V_1 = V_62 ;
F_26 ( & V_1 -> V_5 ) ;
V_63 = F_36 ( V_1 , 2 ) ;
V_64 = F_35 ( V_1 , 2 ) ;
V_63 &= V_64 ;
if ( V_63 & V_74 )
F_43 ( V_1 , 2 , ~ ( V_63 & V_74 ) ) ;
F_38 ( V_1 , 2 , V_63 ) ;
F_19 ( L_4 , V_61 , V_63 , V_64 ) ;
if ( V_63 & V_76 )
V_1 -> V_77 ( V_1 ) ;
if ( V_63 & V_78 )
V_1 -> V_40 ( V_1 , 2 ) ;
if ( V_63 & V_79 )
V_1 -> V_40 ( V_1 , 2 ) ;
if ( V_63 & V_80 )
V_1 -> V_81 ( V_1 ) ;
if ( V_63 & V_75 )
V_1 -> V_82 ( V_1 ) ;
V_1 -> V_32 . V_83 ++ ;
F_24 ( & V_1 -> V_5 ) ;
return V_63 ? V_67 : V_73 ;
}
static int F_44 ( struct V_1 * V_1 )
{
int V_30 = 0 ;
if ( V_1 -> V_84 [ 0 ] != V_85 ) {
snprintf ( V_1 -> V_86 , sizeof ( V_1 -> V_86 ) , L_5 ,
V_1 -> V_87 ) ;
V_30 = F_45 ( V_1 -> V_84 [ 0 ] , F_34 ,
0 , V_1 -> V_86 , V_1 ) ;
if ( V_30 )
goto V_88;
}
if ( V_1 -> V_84 [ 1 ] != V_85 ) {
snprintf ( V_1 -> V_89 , sizeof ( V_1 -> V_89 ) , L_6 ,
V_1 -> V_87 ) ;
V_30 = F_45 ( V_1 -> V_84 [ 1 ] , F_39 ,
0 , V_1 -> V_89 , V_1 ) ;
if ( V_30 )
goto V_90;
}
if ( V_1 -> V_84 [ 2 ] != V_85 ) {
snprintf ( V_1 -> V_91 , sizeof ( V_1 -> V_91 ) , L_7 ,
V_1 -> V_87 ) ;
V_30 = F_45 ( V_1 -> V_84 [ 2 ] , F_42 ,
0 , V_1 -> V_91 , V_1 ) ;
if ( V_30 )
goto V_92;
}
return 0 ;
V_92:
if ( V_1 -> V_84 [ 1 ] != V_85 )
F_46 ( V_1 -> V_84 [ 1 ] , V_1 ) ;
V_90:
if ( V_1 -> V_84 [ 0 ] != V_85 )
F_46 ( V_1 -> V_84 [ 0 ] , V_1 ) ;
V_88:
return V_30 ;
}
static void F_47 ( struct V_1 * V_1 )
{
if ( V_1 -> V_84 [ 0 ] != V_85 )
F_46 ( V_1 -> V_84 [ 0 ] , V_1 ) ;
if ( V_1 -> V_84 [ 1 ] != V_85 )
F_46 ( V_1 -> V_84 [ 1 ] , V_1 ) ;
if ( V_1 -> V_84 [ 2 ] != V_85 )
F_46 ( V_1 -> V_84 [ 2 ] , V_1 ) ;
}
void F_48 ( struct V_1 * V_1 )
{
static const struct {
unsigned V_93 ;
unsigned V_94 ;
} V_95 [] = {
{ 0x00 , 1 , } , { 0x01 , 1 , } , { 0x03 , 1 , } , { 0x04 , 1 , } ,
{ 0x18 , 1 , } , { 0x19 , 1 , } , { 0x1b , 1 , } , { 0x1d , 1 , } ,
} , V_96 [] = {
{ 0x00 , 0 , } , { 0x03 , 0 , } , { 0x04 , 0 , } , { 0x15 , 16 , } ,
{ 0x17 , 1 , } , { 0x18 , 0 , } , { 0x19 , 0 , } , { 0x1b , 0 , } ,
{ 0x1c , 1 , } , { 0x1d , 0 , } , { 0x1e , 1 , } ,
} ;
struct V_2 T_1 * V_3 ;
int V_55 ;
V_3 = V_1 -> V_3 ;
for ( V_55 = 0 ; V_55 < F_31 ( V_95 ) ; V_55 ++ ) {
int V_94 ;
F_4 ( & V_3 -> V_97 , V_95 [ V_55 ] . V_93 ) ;
for ( V_94 = 0 ; V_94 < V_95 [ V_55 ] . V_94 ; V_94 ++ )
F_4 ( & V_3 -> V_98 , 0 ) ;
}
for ( V_55 = 0 ; V_55 < F_31 ( V_96 ) ; V_55 ++ ) {
F_4 ( & V_3 -> V_97 , V_96 [ V_55 ] . V_93 ) ;
F_4 ( & V_3 -> V_99 , V_96 [ V_55 ] . V_94 ) ;
}
}
int F_49 ( struct V_100 * V_101 )
{
struct V_1 * V_1 ;
F_50 ( & V_102 ) ;
F_7 (spu, &spu_full_list, full_list)
F_51 ( & V_1 -> V_103 , V_101 ) ;
F_52 ( & V_102 ) ;
return 0 ;
}
int F_53 ( struct V_104 * V_105 )
{
struct V_1 * V_1 ;
int V_106 = 0 ;
F_50 ( & V_102 ) ;
F_7 (spu, &spu_full_list, full_list) {
V_106 = F_54 ( & V_1 -> V_103 . V_107 , V_105 ) ;
if ( V_106 ) {
F_55 ( V_108 L_8 ,
V_23 , V_105 -> V_109 ) ;
F_56 (spu,
&spu_full_list, full_list)
F_57 ( & V_1 -> V_103 . V_107 , V_105 ) ;
break;
}
}
F_52 ( & V_102 ) ;
return V_106 ;
}
void F_58 ( struct V_100 * V_101 )
{
struct V_1 * V_1 ;
F_50 ( & V_102 ) ;
F_7 (spu, &spu_full_list, full_list)
F_59 ( & V_1 -> V_103 , V_101 ) ;
F_52 ( & V_102 ) ;
}
void F_60 ( struct V_104 * V_105 )
{
struct V_1 * V_1 ;
F_50 ( & V_102 ) ;
F_7 (spu, &spu_full_list, full_list)
F_57 ( & V_1 -> V_103 . V_107 , V_105 ) ;
F_52 ( & V_102 ) ;
}
static int F_61 ( struct V_1 * V_1 )
{
int V_30 ;
V_1 -> V_103 . V_110 = V_1 -> V_87 ;
V_1 -> V_103 . V_111 = & V_112 ;
V_30 = F_62 ( & V_1 -> V_103 ) ;
if ( V_30 ) {
F_55 ( V_108 L_9 ,
V_1 -> V_87 ) ;
return V_30 ;
}
F_63 ( & V_1 -> V_103 , V_1 -> V_113 ) ;
return 0 ;
}
static int T_4 F_64 ( void * V_62 )
{
struct V_1 * V_1 ;
int V_30 ;
static int V_87 ;
unsigned long V_4 ;
V_30 = - V_114 ;
V_1 = F_65 ( sizeof ( * V_1 ) , V_115 ) ;
if ( ! V_1 )
goto V_116;
V_1 -> V_117 = V_118 ;
F_66 ( & V_1 -> V_5 ) ;
F_26 ( & V_119 ) ;
V_1 -> V_87 = V_87 ++ ;
F_24 ( & V_119 ) ;
V_30 = F_67 ( V_1 , V_62 ) ;
if ( V_30 )
goto V_120;
F_68 ( V_1 ) ;
F_69 ( V_1 , 0x33 ) ;
V_30 = F_44 ( V_1 ) ;
if ( V_30 )
goto V_121;
V_30 = F_61 ( V_1 ) ;
if ( V_30 )
goto V_122;
F_50 ( & V_123 [ V_1 -> V_113 ] . V_124 ) ;
F_70 ( & V_1 -> V_125 , & V_123 [ V_1 -> V_113 ] . V_126 ) ;
V_123 [ V_1 -> V_113 ] . V_127 ++ ;
F_52 ( & V_123 [ V_1 -> V_113 ] . V_124 ) ;
F_50 ( & V_102 ) ;
F_2 ( & V_10 , V_4 ) ;
F_70 ( & V_1 -> V_128 , & V_129 ) ;
F_5 ( & V_10 , V_4 ) ;
F_52 ( & V_102 ) ;
V_1 -> V_32 . V_130 = V_131 ;
V_1 -> V_32 . V_132 = F_71 () ;
F_72 ( & V_1 -> V_133 ) ;
goto V_116;
V_122:
F_47 ( V_1 ) ;
V_121:
F_73 ( V_1 ) ;
V_120:
F_74 ( V_1 ) ;
V_116:
return V_30 ;
}
static unsigned long long F_75 ( struct V_1 * V_1 ,
enum V_134 V_135 )
{
unsigned long long time = V_1 -> V_32 . V_136 [ V_135 ] ;
if ( V_1 -> V_32 . V_130 == V_135 )
time += F_71 () - V_1 -> V_32 . V_132 ;
return time / V_137 ;
}
static T_5 F_76 ( struct V_138 * V_103 ,
struct V_100 * V_101 , char * V_139 )
{
struct V_1 * V_1 = F_77 ( V_103 , struct V_1 , V_103 ) ;
return sprintf ( V_139 , L_10
L_11 ,
V_140 [ V_1 -> V_32 . V_130 ] ,
F_75 ( V_1 , V_141 ) ,
F_75 ( V_1 , V_142 ) ,
F_75 ( V_1 , V_143 ) ,
F_75 ( V_1 , V_131 ) ,
V_1 -> V_32 . V_144 ,
V_1 -> V_32 . V_145 ,
V_1 -> V_32 . V_33 ,
V_1 -> V_32 . V_146 ,
V_1 -> V_32 . V_147 ,
V_1 -> V_32 . V_148 ,
V_1 -> V_32 . V_83 ,
V_1 -> V_32 . V_149 ) ;
}
static void F_78 ( void )
{
struct V_1 * V_1 ;
int V_55 ;
T_2 V_150 ;
for ( V_55 = 0 ; V_55 < V_151 ; V_55 ++ ) {
if ( ! V_152 [ V_55 ] . V_1 )
continue;
V_1 = V_152 [ V_55 ] . V_1 ;
V_152 [ V_55 ] . V_153 =
F_79 ( & V_1 -> V_154 -> V_155 ) ;
V_152 [ V_55 ] . V_156 =
F_79 ( & V_1 -> V_154 -> V_157 ) ;
V_152 [ V_55 ] . V_158 =
F_79 ( & V_1 -> V_154 -> V_159 ) ;
V_152 [ V_55 ] . V_160 = F_37 ( V_1 ) ;
V_152 [ V_55 ] . V_161 = F_40 ( V_1 ) ;
V_150 = F_3 ( V_1 ) ;
V_152 [ V_55 ] . V_162 = V_150 ;
V_150 &= ~ V_163 ;
F_69 ( V_1 , V_150 ) ;
F_80 ( 200 ) ;
}
}
static void F_81 ( struct V_164 * V_165 )
{
struct V_1 * V_1 ;
int V_30 ;
F_7 (spu, list, full_list) {
if ( F_82 ( V_1 -> V_87 >= V_151 ) )
continue;
V_152 [ V_1 -> V_87 ] . V_1 = V_1 ;
}
V_30 = F_83 ( & F_78 ) ;
if ( V_30 )
F_55 ( V_108 L_12 ) ;
}
static inline void F_81 ( struct V_164 * V_165 )
{
}
static void F_84 ( void )
{
struct V_1 * V_1 ;
F_50 ( & V_102 ) ;
F_7 (spu, &spu_full_list, full_list) {
F_47 ( V_1 ) ;
F_73 ( V_1 ) ;
}
F_52 ( & V_102 ) ;
}
static int T_4 F_85 ( void )
{
int V_55 , V_30 = 0 ;
for ( V_55 = 0 ; V_55 < V_166 ; V_55 ++ ) {
F_86 ( & V_123 [ V_55 ] . V_124 ) ;
F_72 ( & V_123 [ V_55 ] . V_126 ) ;
}
if ( ! V_167 )
goto V_116;
V_30 = F_87 ( & V_112 , NULL ) ;
if ( V_30 )
goto V_116;
V_30 = F_88 ( F_64 ) ;
if ( V_30 < 0 ) {
F_55 ( V_168 L_13 ,
V_23 ) ;
goto V_169;
}
if ( V_30 > 0 )
F_89 ( & V_170 , V_30 ) ;
F_50 ( & V_102 ) ;
F_90 ( & V_129 ) ;
F_81 ( & V_129 ) ;
F_52 ( & V_102 ) ;
F_49 ( & V_171 ) ;
F_91 ( & V_172 ) ;
F_92 () ;
return 0 ;
V_169:
F_93 ( & V_112 ) ;
V_116:
return V_30 ;
}
