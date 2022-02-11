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
V_30 = F_25 ( V_29 ,
V_37 | V_38 | V_39 ,
0x300 , V_34 ) ;
F_26 ( & V_1 -> V_5 ) ;
if ( ! V_30 ) {
F_14 ( V_1 ) ;
return 0 ;
}
}
V_1 -> V_40 = V_29 ;
V_1 -> V_41 = V_34 ;
V_1 -> V_42 ( V_1 , 1 ) ;
V_1 -> V_40 = 0 ;
V_1 -> V_41 = 0 ;
return 0 ;
}
static void F_27 ( void * V_43 , struct V_21 * V_22 )
{
unsigned long V_29 = ( unsigned long ) V_43 ;
T_2 V_44 ;
if ( F_23 ( V_29 ) == V_45 )
V_44 = V_13 [ V_46 ] . V_47 ;
else
V_44 = V_13 [ V_48 ] . V_47 ;
V_22 -> V_24 = ( F_28 ( V_29 , V_49 ) << V_50 ) |
V_51 | V_44 ;
V_22 -> V_25 = ( V_29 & V_52 ) | V_53 ;
}
static inline int F_29 ( struct V_21 * V_54 , int V_55 ,
void * V_56 )
{
unsigned long V_29 = ( unsigned long ) V_56 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_55 ; V_57 ++ )
if ( ! ( ( V_54 [ V_57 ] . V_25 ^ V_29 ) & V_52 ) )
return 1 ;
return 0 ;
}
void F_30 ( struct V_1 * V_1 , struct V_58 * V_59 ,
void * V_60 , int V_61 )
{
struct V_21 V_54 [ 4 ] ;
int V_57 , V_55 = 0 ;
void * V_62 [] = {
V_59 , ( void * ) V_59 + sizeof( * V_59 ) - 1 ,
V_60 , V_60 + V_61 - 1
} ;
for ( V_57 = 0 ; V_57 < F_31 ( V_62 ) ; V_57 ++ ) {
if ( F_29 ( V_54 , V_55 , V_62 [ V_57 ] ) )
continue;
F_27 ( V_62 [ V_57 ] , & V_54 [ V_55 ] ) ;
V_55 ++ ;
}
F_32 ( & V_1 -> V_5 ) ;
for ( V_57 = 0 ; V_57 < V_55 ; V_57 ++ )
F_18 ( V_1 , V_57 , & V_54 [ V_57 ] ) ;
F_33 ( & V_1 -> V_5 ) ;
}
static T_3
F_34 ( int V_63 , void * V_64 )
{
struct V_1 * V_1 ;
unsigned long V_65 , V_66 ;
V_1 = V_64 ;
F_26 ( & V_1 -> V_5 ) ;
V_66 = F_35 ( V_1 , 0 ) ;
V_65 = F_36 ( V_1 , 0 ) & V_66 ;
V_1 -> V_67 |= V_65 ;
V_1 -> V_68 = F_37 ( V_1 ) ;
V_1 -> V_42 ( V_1 , 0 ) ;
V_1 -> V_67 = 0 ;
V_1 -> V_68 = 0 ;
F_38 ( V_1 , 0 , V_65 ) ;
F_24 ( & V_1 -> V_5 ) ;
return V_69 ;
}
static T_3
F_39 ( int V_63 , void * V_64 )
{
struct V_1 * V_1 ;
unsigned long V_65 , V_66 , V_70 , V_34 ;
V_1 = V_64 ;
F_26 ( & V_1 -> V_5 ) ;
V_66 = F_35 ( V_1 , 1 ) ;
V_65 = F_36 ( V_1 , 1 ) & V_66 ;
V_70 = F_37 ( V_1 ) ;
V_34 = F_40 ( V_1 ) ;
if ( V_65 & V_71 )
F_41 ( V_1 , 0ul ) ;
F_38 ( V_1 , 1 , V_65 ) ;
F_19 ( L_3 , V_23 , V_66 , V_65 ,
V_70 , V_34 ) ;
if ( V_65 & V_72 )
F_20 ( V_1 , V_70 ) ;
if ( V_65 & V_71 )
F_22 ( V_1 , V_70 , V_34 ) ;
if ( V_65 & V_73 )
;
if ( V_65 & V_74 )
;
V_1 -> V_41 = 0 ;
V_1 -> V_40 = 0 ;
F_24 ( & V_1 -> V_5 ) ;
return V_65 ? V_69 : V_75 ;
}
static T_3
F_42 ( int V_63 , void * V_64 )
{
struct V_1 * V_1 ;
unsigned long V_65 ;
unsigned long V_66 ;
const int V_76 =
V_77 | V_78 ;
V_1 = V_64 ;
F_26 ( & V_1 -> V_5 ) ;
V_65 = F_36 ( V_1 , 2 ) ;
V_66 = F_35 ( V_1 , 2 ) ;
V_65 &= V_66 ;
if ( V_65 & V_76 )
F_43 ( V_1 , 2 , ~ ( V_65 & V_76 ) ) ;
F_38 ( V_1 , 2 , V_65 ) ;
F_19 ( L_4 , V_63 , V_65 , V_66 ) ;
if ( V_65 & V_78 )
V_1 -> V_79 ( V_1 ) ;
if ( V_65 & V_80 )
V_1 -> V_42 ( V_1 , 2 ) ;
if ( V_65 & V_81 )
V_1 -> V_42 ( V_1 , 2 ) ;
if ( V_65 & V_82 )
V_1 -> V_83 ( V_1 ) ;
if ( V_65 & V_77 )
V_1 -> V_84 ( V_1 ) ;
V_1 -> V_32 . V_85 ++ ;
F_24 ( & V_1 -> V_5 ) ;
return V_65 ? V_69 : V_75 ;
}
static int F_44 ( struct V_1 * V_1 )
{
int V_30 = 0 ;
if ( V_1 -> V_86 [ 0 ] ) {
snprintf ( V_1 -> V_87 , sizeof ( V_1 -> V_87 ) , L_5 ,
V_1 -> V_88 ) ;
V_30 = F_45 ( V_1 -> V_86 [ 0 ] , F_34 ,
0 , V_1 -> V_87 , V_1 ) ;
if ( V_30 )
goto V_89;
}
if ( V_1 -> V_86 [ 1 ] ) {
snprintf ( V_1 -> V_90 , sizeof ( V_1 -> V_90 ) , L_6 ,
V_1 -> V_88 ) ;
V_30 = F_45 ( V_1 -> V_86 [ 1 ] , F_39 ,
0 , V_1 -> V_90 , V_1 ) ;
if ( V_30 )
goto V_91;
}
if ( V_1 -> V_86 [ 2 ] ) {
snprintf ( V_1 -> V_92 , sizeof ( V_1 -> V_92 ) , L_7 ,
V_1 -> V_88 ) ;
V_30 = F_45 ( V_1 -> V_86 [ 2 ] , F_42 ,
0 , V_1 -> V_92 , V_1 ) ;
if ( V_30 )
goto V_93;
}
return 0 ;
V_93:
if ( V_1 -> V_86 [ 1 ] )
F_46 ( V_1 -> V_86 [ 1 ] , V_1 ) ;
V_91:
if ( V_1 -> V_86 [ 0 ] )
F_46 ( V_1 -> V_86 [ 0 ] , V_1 ) ;
V_89:
return V_30 ;
}
static void F_47 ( struct V_1 * V_1 )
{
if ( V_1 -> V_86 [ 0 ] )
F_46 ( V_1 -> V_86 [ 0 ] , V_1 ) ;
if ( V_1 -> V_86 [ 1 ] )
F_46 ( V_1 -> V_86 [ 1 ] , V_1 ) ;
if ( V_1 -> V_86 [ 2 ] )
F_46 ( V_1 -> V_86 [ 2 ] , V_1 ) ;
}
void F_48 ( struct V_1 * V_1 )
{
static const struct {
unsigned V_94 ;
unsigned V_95 ;
} V_96 [] = {
{ 0x00 , 1 , } , { 0x01 , 1 , } , { 0x03 , 1 , } , { 0x04 , 1 , } ,
{ 0x18 , 1 , } , { 0x19 , 1 , } , { 0x1b , 1 , } , { 0x1d , 1 , } ,
} , V_97 [] = {
{ 0x00 , 0 , } , { 0x03 , 0 , } , { 0x04 , 0 , } , { 0x15 , 16 , } ,
{ 0x17 , 1 , } , { 0x18 , 0 , } , { 0x19 , 0 , } , { 0x1b , 0 , } ,
{ 0x1c , 1 , } , { 0x1d , 0 , } , { 0x1e , 1 , } ,
} ;
struct V_2 T_1 * V_3 ;
int V_57 ;
V_3 = V_1 -> V_3 ;
for ( V_57 = 0 ; V_57 < F_31 ( V_96 ) ; V_57 ++ ) {
int V_95 ;
F_4 ( & V_3 -> V_98 , V_96 [ V_57 ] . V_94 ) ;
for ( V_95 = 0 ; V_95 < V_96 [ V_57 ] . V_95 ; V_95 ++ )
F_4 ( & V_3 -> V_99 , 0 ) ;
}
for ( V_57 = 0 ; V_57 < F_31 ( V_97 ) ; V_57 ++ ) {
F_4 ( & V_3 -> V_98 , V_97 [ V_57 ] . V_94 ) ;
F_4 ( & V_3 -> V_100 , V_97 [ V_57 ] . V_95 ) ;
}
}
int F_49 ( struct V_101 * V_102 )
{
struct V_1 * V_1 ;
F_50 ( & V_103 ) ;
F_7 (spu, &spu_full_list, full_list)
F_51 ( & V_1 -> V_104 , V_102 ) ;
F_52 ( & V_103 ) ;
return 0 ;
}
int F_53 ( struct V_105 * V_106 )
{
struct V_1 * V_1 ;
int V_107 = 0 ;
F_50 ( & V_103 ) ;
F_7 (spu, &spu_full_list, full_list) {
V_107 = F_54 ( & V_1 -> V_104 . V_108 , V_106 ) ;
if ( V_107 ) {
F_55 ( V_109 L_8 ,
V_23 , V_106 -> V_110 ) ;
F_56 (spu,
&spu_full_list, full_list)
F_57 ( & V_1 -> V_104 . V_108 , V_106 ) ;
break;
}
}
F_52 ( & V_103 ) ;
return V_107 ;
}
void F_58 ( struct V_101 * V_102 )
{
struct V_1 * V_1 ;
F_50 ( & V_103 ) ;
F_7 (spu, &spu_full_list, full_list)
F_59 ( & V_1 -> V_104 , V_102 ) ;
F_52 ( & V_103 ) ;
}
void F_60 ( struct V_105 * V_106 )
{
struct V_1 * V_1 ;
F_50 ( & V_103 ) ;
F_7 (spu, &spu_full_list, full_list)
F_57 ( & V_1 -> V_104 . V_108 , V_106 ) ;
F_52 ( & V_103 ) ;
}
static int F_61 ( struct V_1 * V_1 )
{
int V_30 ;
V_1 -> V_104 . V_111 = V_1 -> V_88 ;
V_1 -> V_104 . V_112 = & V_113 ;
V_30 = F_62 ( & V_1 -> V_104 ) ;
if ( V_30 ) {
F_55 ( V_109 L_9 ,
V_1 -> V_88 ) ;
return V_30 ;
}
F_63 ( & V_1 -> V_104 , V_1 -> V_114 ) ;
return 0 ;
}
static int T_4 F_64 ( void * V_64 )
{
struct V_1 * V_1 ;
int V_30 ;
static int V_88 ;
unsigned long V_4 ;
V_30 = - V_115 ;
V_1 = F_65 ( sizeof ( * V_1 ) , V_116 ) ;
if ( ! V_1 )
goto V_117;
V_1 -> V_118 = V_119 ;
F_66 ( & V_1 -> V_5 ) ;
F_26 ( & V_120 ) ;
V_1 -> V_88 = V_88 ++ ;
F_24 ( & V_120 ) ;
V_30 = F_67 ( V_1 , V_64 ) ;
if ( V_30 )
goto V_121;
F_68 ( V_1 ) ;
F_69 ( V_1 , 0x33 ) ;
V_30 = F_44 ( V_1 ) ;
if ( V_30 )
goto V_122;
V_30 = F_61 ( V_1 ) ;
if ( V_30 )
goto V_123;
F_50 ( & V_124 [ V_1 -> V_114 ] . V_125 ) ;
F_70 ( & V_1 -> V_126 , & V_124 [ V_1 -> V_114 ] . V_127 ) ;
V_124 [ V_1 -> V_114 ] . V_128 ++ ;
F_52 ( & V_124 [ V_1 -> V_114 ] . V_125 ) ;
F_50 ( & V_103 ) ;
F_2 ( & V_10 , V_4 ) ;
F_70 ( & V_1 -> V_129 , & V_130 ) ;
F_5 ( & V_10 , V_4 ) ;
F_52 ( & V_103 ) ;
V_1 -> V_32 . V_131 = V_132 ;
V_1 -> V_32 . V_133 = F_71 () ;
F_72 ( & V_1 -> V_134 ) ;
goto V_117;
V_123:
F_47 ( V_1 ) ;
V_122:
F_73 ( V_1 ) ;
V_121:
F_74 ( V_1 ) ;
V_117:
return V_30 ;
}
static unsigned long long F_75 ( struct V_1 * V_1 ,
enum V_135 V_136 )
{
unsigned long long time = V_1 -> V_32 . V_137 [ V_136 ] ;
if ( V_1 -> V_32 . V_131 == V_136 )
time += F_71 () - V_1 -> V_32 . V_133 ;
return time / V_138 ;
}
static T_5 F_76 ( struct V_139 * V_104 ,
struct V_101 * V_102 , char * V_140 )
{
struct V_1 * V_1 = F_77 ( V_104 , struct V_1 , V_104 ) ;
return sprintf ( V_140 , L_10
L_11 ,
V_141 [ V_1 -> V_32 . V_131 ] ,
F_75 ( V_1 , V_142 ) ,
F_75 ( V_1 , V_143 ) ,
F_75 ( V_1 , V_144 ) ,
F_75 ( V_1 , V_132 ) ,
V_1 -> V_32 . V_145 ,
V_1 -> V_32 . V_146 ,
V_1 -> V_32 . V_33 ,
V_1 -> V_32 . V_147 ,
V_1 -> V_32 . V_148 ,
V_1 -> V_32 . V_149 ,
V_1 -> V_32 . V_85 ,
V_1 -> V_32 . V_150 ) ;
}
static void F_78 ( void )
{
struct V_1 * V_1 ;
int V_57 ;
T_2 V_151 ;
for ( V_57 = 0 ; V_57 < V_152 ; V_57 ++ ) {
if ( ! V_153 [ V_57 ] . V_1 )
continue;
V_1 = V_153 [ V_57 ] . V_1 ;
V_153 [ V_57 ] . V_154 =
F_79 ( & V_1 -> V_155 -> V_156 ) ;
V_153 [ V_57 ] . V_157 =
F_79 ( & V_1 -> V_155 -> V_158 ) ;
V_153 [ V_57 ] . V_159 =
F_79 ( & V_1 -> V_155 -> V_160 ) ;
V_153 [ V_57 ] . V_161 = F_37 ( V_1 ) ;
V_153 [ V_57 ] . V_162 = F_40 ( V_1 ) ;
V_151 = F_3 ( V_1 ) ;
V_153 [ V_57 ] . V_163 = V_151 ;
V_151 &= ~ V_164 ;
F_69 ( V_1 , V_151 ) ;
F_80 ( 200 ) ;
}
}
static void F_81 ( struct V_165 * V_166 )
{
struct V_1 * V_1 ;
int V_30 ;
F_7 (spu, list, full_list) {
if ( F_82 ( V_1 -> V_88 >= V_152 ) )
continue;
V_153 [ V_1 -> V_88 ] . V_1 = V_1 ;
}
V_30 = F_83 ( & F_78 ) ;
if ( V_30 )
F_55 ( V_109 L_12 ) ;
}
static inline void F_81 ( struct V_165 * V_166 )
{
}
static void F_84 ( void )
{
struct V_1 * V_1 ;
F_50 ( & V_103 ) ;
F_7 (spu, &spu_full_list, full_list) {
F_47 ( V_1 ) ;
F_73 ( V_1 ) ;
}
F_52 ( & V_103 ) ;
}
static int T_4 F_85 ( void )
{
int V_57 , V_30 = 0 ;
for ( V_57 = 0 ; V_57 < V_167 ; V_57 ++ ) {
F_86 ( & V_124 [ V_57 ] . V_125 ) ;
F_72 ( & V_124 [ V_57 ] . V_127 ) ;
}
if ( ! V_168 )
goto V_117;
V_30 = F_87 ( & V_113 , NULL ) ;
if ( V_30 )
goto V_117;
V_30 = F_88 ( F_64 ) ;
if ( V_30 < 0 ) {
F_55 ( V_169 L_13 ,
V_23 ) ;
goto V_170;
}
if ( V_30 > 0 )
F_89 ( & V_171 , V_30 ) ;
F_50 ( & V_103 ) ;
F_90 ( & V_130 ) ;
F_81 ( & V_130 ) ;
F_52 ( & V_103 ) ;
F_49 ( & V_172 ) ;
F_91 ( & V_173 ) ;
F_92 () ;
return 0 ;
V_170:
F_93 ( & V_113 ) ;
V_117:
return V_30 ;
}
