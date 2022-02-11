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
struct V_8 * V_9 = V_1 -> V_9 ;
struct V_21 V_22 ;
int V_30 ;
F_19 ( L_2 , V_23 ) ;
V_22 . V_25 = ( V_29 & V_31 ) | V_32 ;
switch( F_21 ( V_29 ) ) {
case V_33 :
#ifdef F_22
V_30 = F_23 ( V_9 , V_29 ) ;
#else
V_30 = V_9 -> V_34 . V_35 ;
#endif
V_22 . V_24 = ( F_24 ( V_9 -> V_34 . V_36 , V_29 , V_37 )
<< V_38 ) | V_39 ;
break;
case V_40 :
if ( V_29 < V_41 )
V_30 = V_42 ;
else
V_30 = V_43 ;
V_22 . V_24 = ( F_25 ( V_29 , V_37 )
<< V_38 ) | V_44 ;
break;
case V_45 :
V_30 = V_46 ;
V_22 . V_24 = ( F_25 ( V_29 , V_37 )
<< V_38 ) | V_44 ;
break;
default:
F_19 ( L_3 , V_29 ) ;
return 1 ;
}
V_22 . V_24 |= V_13 [ V_30 ] . V_47 ;
F_18 ( V_1 , V_1 -> V_48 , & V_22 ) ;
V_1 -> V_48 ++ ;
if ( V_1 -> V_48 >= 8 )
V_1 -> V_48 = 0 ;
F_14 ( V_1 ) ;
V_1 -> V_49 . V_50 ++ ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 , unsigned long V_29 , T_2 V_51 )
{
int V_52 ;
F_19 ( L_4 , V_23 , V_51 , V_29 ) ;
if ( ( V_51 & V_53 ) &&
( F_21 ( V_29 ) != V_33 ) ) {
F_27 ( & V_1 -> V_5 ) ;
V_52 = F_28 ( V_29 , V_54 , 0x300 ) ;
F_29 ( & V_1 -> V_5 ) ;
if ( ! V_52 ) {
F_14 ( V_1 ) ;
return 0 ;
}
}
V_1 -> V_55 = V_29 ;
V_1 -> V_56 = V_51 ;
V_1 -> V_57 ( V_1 , 1 ) ;
V_1 -> V_55 = 0 ;
V_1 -> V_56 = 0 ;
return 0 ;
}
static void F_30 ( void * V_58 , struct V_21 * V_22 )
{
unsigned long V_29 = ( unsigned long ) V_58 ;
T_2 V_59 ;
if ( F_21 ( V_29 ) == V_45 )
V_59 = V_13 [ V_46 ] . V_47 ;
else
V_59 = V_13 [ V_60 ] . V_47 ;
V_22 -> V_24 = ( F_25 ( V_29 , V_37 ) << V_38 ) |
V_44 | V_59 ;
V_22 -> V_25 = ( V_29 & V_31 ) | V_32 ;
}
static inline int F_31 ( struct V_21 * V_61 , int V_62 ,
void * V_63 )
{
unsigned long V_29 = ( unsigned long ) V_63 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ )
if ( ! ( ( V_61 [ V_64 ] . V_25 ^ V_29 ) & V_31 ) )
return 1 ;
return 0 ;
}
void F_32 ( struct V_1 * V_1 , struct V_65 * V_66 ,
void * V_67 , int V_68 )
{
struct V_21 V_61 [ 4 ] ;
int V_64 , V_62 = 0 ;
void * V_69 [] = {
V_66 , ( void * ) V_66 + sizeof( * V_66 ) - 1 ,
V_67 , V_67 + V_68 - 1
} ;
for ( V_64 = 0 ; V_64 < F_33 ( V_69 ) ; V_64 ++ ) {
if ( F_31 ( V_61 , V_62 , V_69 [ V_64 ] ) )
continue;
F_30 ( V_69 [ V_64 ] , & V_61 [ V_62 ] ) ;
V_62 ++ ;
}
F_34 ( & V_1 -> V_5 ) ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ )
F_18 ( V_1 , V_64 , & V_61 [ V_64 ] ) ;
F_35 ( & V_1 -> V_5 ) ;
}
static T_3
F_36 ( int V_70 , void * V_71 )
{
struct V_1 * V_1 ;
unsigned long V_72 , V_73 ;
V_1 = V_71 ;
F_29 ( & V_1 -> V_5 ) ;
V_73 = F_37 ( V_1 , 0 ) ;
V_72 = F_38 ( V_1 , 0 ) & V_73 ;
V_1 -> V_74 |= V_72 ;
V_1 -> V_75 = F_39 ( V_1 ) ;
V_1 -> V_57 ( V_1 , 0 ) ;
V_1 -> V_74 = 0 ;
V_1 -> V_75 = 0 ;
F_40 ( V_1 , 0 , V_72 ) ;
F_27 ( & V_1 -> V_5 ) ;
return V_76 ;
}
static T_3
F_41 ( int V_70 , void * V_71 )
{
struct V_1 * V_1 ;
unsigned long V_72 , V_73 , V_77 , V_51 ;
V_1 = V_71 ;
F_29 ( & V_1 -> V_5 ) ;
V_73 = F_37 ( V_1 , 1 ) ;
V_72 = F_38 ( V_1 , 1 ) & V_73 ;
V_77 = F_39 ( V_1 ) ;
V_51 = F_42 ( V_1 ) ;
if ( V_72 & V_78 )
F_43 ( V_1 , 0ul ) ;
F_40 ( V_1 , 1 , V_72 ) ;
F_19 ( L_5 , V_23 , V_73 , V_72 ,
V_77 , V_51 ) ;
if ( V_72 & V_79 )
F_20 ( V_1 , V_77 ) ;
if ( V_72 & V_78 )
F_26 ( V_1 , V_77 , V_51 ) ;
if ( V_72 & V_80 )
;
if ( V_72 & V_81 )
;
V_1 -> V_56 = 0 ;
V_1 -> V_55 = 0 ;
F_27 ( & V_1 -> V_5 ) ;
return V_72 ? V_76 : V_82 ;
}
static T_3
F_44 ( int V_70 , void * V_71 )
{
struct V_1 * V_1 ;
unsigned long V_72 ;
unsigned long V_73 ;
const int V_83 =
V_84 | V_85 ;
V_1 = V_71 ;
F_29 ( & V_1 -> V_5 ) ;
V_72 = F_38 ( V_1 , 2 ) ;
V_73 = F_37 ( V_1 , 2 ) ;
V_72 &= V_73 ;
if ( V_72 & V_83 )
F_45 ( V_1 , 2 , ~ ( V_72 & V_83 ) ) ;
F_40 ( V_1 , 2 , V_72 ) ;
F_19 ( L_6 , V_70 , V_72 , V_73 ) ;
if ( V_72 & V_85 )
V_1 -> V_86 ( V_1 ) ;
if ( V_72 & V_87 )
V_1 -> V_57 ( V_1 , 2 ) ;
if ( V_72 & V_88 )
V_1 -> V_57 ( V_1 , 2 ) ;
if ( V_72 & V_89 )
V_1 -> V_90 ( V_1 ) ;
if ( V_72 & V_84 )
V_1 -> V_91 ( V_1 ) ;
V_1 -> V_49 . V_92 ++ ;
F_27 ( & V_1 -> V_5 ) ;
return V_72 ? V_76 : V_82 ;
}
static int F_46 ( struct V_1 * V_1 )
{
int V_52 = 0 ;
if ( V_1 -> V_93 [ 0 ] != V_94 ) {
snprintf ( V_1 -> V_95 , sizeof ( V_1 -> V_95 ) , L_7 ,
V_1 -> V_96 ) ;
V_52 = F_47 ( V_1 -> V_93 [ 0 ] , F_36 ,
V_97 ,
V_1 -> V_95 , V_1 ) ;
if ( V_52 )
goto V_98;
}
if ( V_1 -> V_93 [ 1 ] != V_94 ) {
snprintf ( V_1 -> V_99 , sizeof ( V_1 -> V_99 ) , L_8 ,
V_1 -> V_96 ) ;
V_52 = F_47 ( V_1 -> V_93 [ 1 ] , F_41 ,
V_97 ,
V_1 -> V_99 , V_1 ) ;
if ( V_52 )
goto V_100;
}
if ( V_1 -> V_93 [ 2 ] != V_94 ) {
snprintf ( V_1 -> V_101 , sizeof ( V_1 -> V_101 ) , L_9 ,
V_1 -> V_96 ) ;
V_52 = F_47 ( V_1 -> V_93 [ 2 ] , F_44 ,
V_97 ,
V_1 -> V_101 , V_1 ) ;
if ( V_52 )
goto V_102;
}
return 0 ;
V_102:
if ( V_1 -> V_93 [ 1 ] != V_94 )
F_48 ( V_1 -> V_93 [ 1 ] , V_1 ) ;
V_100:
if ( V_1 -> V_93 [ 0 ] != V_94 )
F_48 ( V_1 -> V_93 [ 0 ] , V_1 ) ;
V_98:
return V_52 ;
}
static void F_49 ( struct V_1 * V_1 )
{
if ( V_1 -> V_93 [ 0 ] != V_94 )
F_48 ( V_1 -> V_93 [ 0 ] , V_1 ) ;
if ( V_1 -> V_93 [ 1 ] != V_94 )
F_48 ( V_1 -> V_93 [ 1 ] , V_1 ) ;
if ( V_1 -> V_93 [ 2 ] != V_94 )
F_48 ( V_1 -> V_93 [ 2 ] , V_1 ) ;
}
void F_50 ( struct V_1 * V_1 )
{
static const struct {
unsigned V_103 ;
unsigned V_104 ;
} V_105 [] = {
{ 0x00 , 1 , } , { 0x01 , 1 , } , { 0x03 , 1 , } , { 0x04 , 1 , } ,
{ 0x18 , 1 , } , { 0x19 , 1 , } , { 0x1b , 1 , } , { 0x1d , 1 , } ,
} , V_106 [] = {
{ 0x00 , 0 , } , { 0x03 , 0 , } , { 0x04 , 0 , } , { 0x15 , 16 , } ,
{ 0x17 , 1 , } , { 0x18 , 0 , } , { 0x19 , 0 , } , { 0x1b , 0 , } ,
{ 0x1c , 1 , } , { 0x1d , 0 , } , { 0x1e , 1 , } ,
} ;
struct V_2 T_1 * V_3 ;
int V_64 ;
V_3 = V_1 -> V_3 ;
for ( V_64 = 0 ; V_64 < F_33 ( V_105 ) ; V_64 ++ ) {
int V_104 ;
F_4 ( & V_3 -> V_107 , V_105 [ V_64 ] . V_103 ) ;
for ( V_104 = 0 ; V_104 < V_105 [ V_64 ] . V_104 ; V_104 ++ )
F_4 ( & V_3 -> V_108 , 0 ) ;
}
for ( V_64 = 0 ; V_64 < F_33 ( V_106 ) ; V_64 ++ ) {
F_4 ( & V_3 -> V_107 , V_106 [ V_64 ] . V_103 ) ;
F_4 ( & V_3 -> V_109 , V_106 [ V_64 ] . V_104 ) ;
}
}
int F_51 ( struct V_110 * V_111 )
{
struct V_1 * V_1 ;
F_52 ( & V_112 ) ;
F_7 (spu, &spu_full_list, full_list)
F_53 ( & V_1 -> V_113 , V_111 ) ;
F_54 ( & V_112 ) ;
return 0 ;
}
int F_55 ( struct V_114 * V_115 )
{
struct V_1 * V_1 ;
int V_116 = 0 ;
F_52 ( & V_112 ) ;
F_7 (spu, &spu_full_list, full_list) {
V_116 = F_56 ( & V_1 -> V_113 . V_117 , V_115 ) ;
if ( V_116 ) {
F_57 ( V_118 L_10 ,
V_23 , V_115 -> V_119 ) ;
F_58 (spu,
&spu_full_list, full_list)
F_59 ( & V_1 -> V_113 . V_117 , V_115 ) ;
break;
}
}
F_54 ( & V_112 ) ;
return V_116 ;
}
void F_60 ( struct V_110 * V_111 )
{
struct V_1 * V_1 ;
F_52 ( & V_112 ) ;
F_7 (spu, &spu_full_list, full_list)
F_61 ( & V_1 -> V_113 , V_111 ) ;
F_54 ( & V_112 ) ;
}
void F_62 ( struct V_114 * V_115 )
{
struct V_1 * V_1 ;
F_52 ( & V_112 ) ;
F_7 (spu, &spu_full_list, full_list)
F_59 ( & V_1 -> V_113 . V_117 , V_115 ) ;
F_54 ( & V_112 ) ;
}
static int F_63 ( struct V_1 * V_1 )
{
int V_52 ;
V_1 -> V_113 . V_36 = V_1 -> V_96 ;
V_1 -> V_113 . V_120 = & V_121 ;
V_52 = F_64 ( & V_1 -> V_113 ) ;
if ( V_52 ) {
F_57 ( V_118 L_11 ,
V_1 -> V_96 ) ;
return V_52 ;
}
F_65 ( & V_1 -> V_113 , V_1 -> V_122 ) ;
return 0 ;
}
static int T_4 F_66 ( void * V_71 )
{
struct V_1 * V_1 ;
int V_52 ;
static int V_96 ;
unsigned long V_4 ;
struct V_123 V_124 ;
V_52 = - V_125 ;
V_1 = F_67 ( sizeof ( * V_1 ) , V_126 ) ;
if ( ! V_1 )
goto V_127;
V_1 -> V_128 = V_129 ;
F_68 ( & V_1 -> V_5 ) ;
F_29 ( & V_130 ) ;
V_1 -> V_96 = V_96 ++ ;
F_27 ( & V_130 ) ;
V_52 = F_69 ( V_1 , V_71 ) ;
if ( V_52 )
goto V_131;
F_70 ( V_1 ) ;
F_71 ( V_1 , 0x33 ) ;
V_52 = F_46 ( V_1 ) ;
if ( V_52 )
goto V_132;
V_52 = F_63 ( V_1 ) ;
if ( V_52 )
goto V_133;
F_52 ( & V_134 [ V_1 -> V_122 ] . V_135 ) ;
F_72 ( & V_1 -> V_136 , & V_134 [ V_1 -> V_122 ] . V_137 ) ;
V_134 [ V_1 -> V_122 ] . V_138 ++ ;
F_54 ( & V_134 [ V_1 -> V_122 ] . V_135 ) ;
F_52 ( & V_112 ) ;
F_2 ( & V_10 , V_4 ) ;
F_72 ( & V_1 -> V_139 , & V_140 ) ;
F_5 ( & V_10 , V_4 ) ;
F_54 ( & V_112 ) ;
V_1 -> V_49 . V_141 = V_142 ;
F_73 ( & V_124 ) ;
V_1 -> V_49 . V_143 = F_74 ( & V_124 ) ;
F_75 ( & V_1 -> V_144 ) ;
goto V_127;
V_133:
F_49 ( V_1 ) ;
V_132:
F_76 ( V_1 ) ;
V_131:
F_77 ( V_1 ) ;
V_127:
return V_52 ;
}
static unsigned long long F_78 ( struct V_1 * V_1 ,
enum V_145 V_146 )
{
struct V_123 V_124 ;
unsigned long long time = V_1 -> V_49 . V_147 [ V_146 ] ;
if ( V_1 -> V_49 . V_141 == V_146 ) {
F_73 ( & V_124 ) ;
time += F_74 ( & V_124 ) - V_1 -> V_49 . V_143 ;
}
return time / V_148 ;
}
static T_5 F_79 ( struct V_149 * V_113 ,
struct V_110 * V_111 , char * V_150 )
{
struct V_1 * V_1 = F_80 ( V_113 , struct V_1 , V_113 ) ;
return sprintf ( V_150 , L_12
L_13 ,
V_151 [ V_1 -> V_49 . V_141 ] ,
F_78 ( V_1 , V_152 ) ,
F_78 ( V_1 , V_153 ) ,
F_78 ( V_1 , V_154 ) ,
F_78 ( V_1 , V_142 ) ,
V_1 -> V_49 . V_155 ,
V_1 -> V_49 . V_156 ,
V_1 -> V_49 . V_50 ,
V_1 -> V_49 . V_157 ,
V_1 -> V_49 . V_158 ,
V_1 -> V_49 . V_159 ,
V_1 -> V_49 . V_92 ,
V_1 -> V_49 . V_160 ) ;
}
static void F_81 ( void )
{
struct V_1 * V_1 ;
int V_64 ;
T_2 V_161 ;
for ( V_64 = 0 ; V_64 < V_162 ; V_64 ++ ) {
if ( ! V_163 [ V_64 ] . V_1 )
continue;
V_1 = V_163 [ V_64 ] . V_1 ;
V_163 [ V_64 ] . V_164 =
F_82 ( & V_1 -> V_165 -> V_166 ) ;
V_163 [ V_64 ] . V_167 =
F_82 ( & V_1 -> V_165 -> V_168 ) ;
V_163 [ V_64 ] . V_169 =
F_82 ( & V_1 -> V_165 -> V_170 ) ;
V_163 [ V_64 ] . V_171 = F_39 ( V_1 ) ;
V_163 [ V_64 ] . V_172 = F_42 ( V_1 ) ;
V_161 = F_3 ( V_1 ) ;
V_163 [ V_64 ] . V_173 = V_161 ;
V_161 &= ~ V_174 ;
F_71 ( V_1 , V_161 ) ;
F_83 ( 200 ) ;
}
}
static void F_84 ( struct V_175 * V_176 )
{
struct V_1 * V_1 ;
int V_52 ;
F_7 (spu, list, full_list) {
if ( F_85 ( V_1 -> V_96 >= V_162 ) )
continue;
V_163 [ V_1 -> V_96 ] . V_1 = V_1 ;
}
V_52 = F_86 ( & F_81 ) ;
if ( V_52 )
F_57 ( V_118 L_14 ) ;
}
static inline void F_84 ( struct V_175 * V_176 )
{
}
static void F_87 ( void )
{
struct V_1 * V_1 ;
F_52 ( & V_112 ) ;
F_7 (spu, &spu_full_list, full_list) {
F_49 ( V_1 ) ;
F_76 ( V_1 ) ;
}
F_54 ( & V_112 ) ;
}
static int T_4 F_88 ( void )
{
int V_64 , V_52 = 0 ;
for ( V_64 = 0 ; V_64 < V_177 ; V_64 ++ ) {
F_89 ( & V_134 [ V_64 ] . V_135 ) ;
F_75 ( & V_134 [ V_64 ] . V_137 ) ;
}
if ( ! V_178 )
goto V_127;
V_52 = F_90 ( & V_121 ) ;
if ( V_52 )
goto V_127;
V_52 = F_91 ( F_66 ) ;
if ( V_52 < 0 ) {
F_57 ( V_179 L_15 ,
V_23 ) ;
goto V_180;
}
if ( V_52 > 0 )
F_92 ( & V_181 , V_52 ) ;
F_52 ( & V_112 ) ;
F_93 ( & V_140 ) ;
F_84 ( & V_140 ) ;
F_54 ( & V_112 ) ;
F_51 ( & V_182 ) ;
F_94 ( & V_183 ) ;
F_95 () ;
return 0 ;
V_180:
F_96 ( & V_121 ) ;
V_127:
return V_52 ;
}
