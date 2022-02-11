static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
char * V_6 , * V_7 ;
char * V_8 ;
char V_9 [ sizeof( V_4 -> V_10 ) ] ;
F_2 ( V_9 , V_4 ) ;
F_3 ( V_2 , L_1 ) ;
V_7 = V_2 -> V_6 + V_2 -> V_11 ;
V_6 = V_2 -> V_6 + V_2 -> V_12 ;
V_8 = V_9 ;
V_5 = sizeof( V_9 ) ;
while ( V_5 && ( V_6 < V_7 ) ) {
unsigned char V_13 = * V_8 ;
V_8 ++ ;
V_5 -- ;
* V_6 = V_13 ;
if ( ! V_13 )
break;
if ( V_13 == '\\' ) {
V_6 ++ ;
if ( V_6 < V_7 )
* V_6 ++ = V_13 ;
continue;
}
if ( V_13 == '\n' ) {
* V_6 ++ = '\\' ;
if ( V_6 < V_7 )
* V_6 ++ = 'n' ;
continue;
}
V_6 ++ ;
}
V_2 -> V_12 = V_6 - V_2 -> V_6 ;
F_4 ( V_2 , '\n' ) ;
}
static inline const char * F_5 ( struct V_3 * V_14 )
{
unsigned int V_15 = ( V_14 -> V_15 & V_16 ) | V_14 -> V_17 ;
const char * const * V_4 = & V_18 [ 0 ] ;
F_6 ( 1 + F_7 ( V_19 ) != F_8 ( V_18 ) ) ;
while ( V_15 ) {
V_4 ++ ;
V_15 >>= 1 ;
}
return * V_4 ;
}
static inline void F_9 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_4 )
{
struct V_23 * V_24 = F_10 ( V_2 ) ;
struct V_25 * V_25 ;
int V_26 ;
struct V_27 * V_28 = NULL ;
const struct V_29 * V_29 ;
T_1 V_30 , V_31 ;
F_11 () ;
V_30 = F_12 ( V_4 ) ?
F_13 ( F_14 ( V_4 -> V_32 ) , V_21 ) : 0 ;
V_31 = 0 ;
if ( F_12 ( V_4 ) ) {
struct V_3 * V_33 = F_15 ( V_4 ) ;
if ( V_33 )
V_31 = F_16 ( V_33 , V_21 ) ;
}
V_29 = F_17 ( V_4 ) ;
F_18 ( V_2 ,
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9 ,
F_5 ( V_4 ) ,
F_13 ( V_4 , V_21 ) ,
F_19 ( V_4 ) ,
F_20 ( V_22 , V_21 ) ,
V_30 , V_31 ,
F_21 ( V_24 , V_29 -> V_34 ) ,
F_21 ( V_24 , V_29 -> V_35 ) ,
F_21 ( V_24 , V_29 -> V_36 ) ,
F_21 ( V_24 , V_29 -> V_37 ) ,
F_22 ( V_24 , V_29 -> V_38 ) ,
F_22 ( V_24 , V_29 -> V_39 ) ,
F_22 ( V_24 , V_29 -> V_40 ) ,
F_22 ( V_24 , V_29 -> V_41 ) ) ;
F_23 ( V_4 ) ;
if ( V_4 -> V_42 )
V_28 = F_24 ( V_4 -> V_42 ) ;
F_18 ( V_2 ,
L_10
L_11 ,
V_28 ? V_28 -> V_43 : 0 ) ;
F_25 () ;
V_25 = V_29 -> V_25 ;
F_26 ( V_4 ) ;
for ( V_26 = 0 ; V_26 < V_25 -> V_44 ; V_26 ++ )
F_18 ( V_2 , L_12 ,
F_22 ( V_24 , F_27 ( V_25 , V_26 ) ) ) ;
F_28 ( V_29 ) ;
F_4 ( V_2 , '\n' ) ;
}
void F_29 ( struct V_1 * V_2 , const char * V_45 ,
T_2 * V_46 )
{
int V_5 ;
F_3 ( V_2 , V_45 ) ;
V_5 = V_47 ;
do {
int V_48 = 0 ;
V_5 -= 4 ;
if ( F_30 ( V_46 , V_5 + 1 ) ) V_48 |= 1 ;
if ( F_30 ( V_46 , V_5 + 2 ) ) V_48 |= 2 ;
if ( F_30 ( V_46 , V_5 + 3 ) ) V_48 |= 4 ;
if ( F_30 ( V_46 , V_5 + 4 ) ) V_48 |= 8 ;
F_18 ( V_2 , L_13 , V_48 ) ;
} while ( V_5 >= 4 );
F_4 ( V_2 , '\n' ) ;
}
static void F_31 ( struct V_3 * V_4 , T_2 * V_49 ,
T_2 * V_50 )
{
struct V_51 * V_52 ;
int V_5 ;
V_52 = V_4 -> V_53 -> V_54 ;
for ( V_5 = 1 ; V_5 <= V_47 ; ++ V_5 , ++ V_52 ) {
if ( V_52 -> V_55 . V_56 == V_57 )
F_32 ( V_49 , V_5 ) ;
else if ( V_52 -> V_55 . V_56 != V_58 )
F_32 ( V_50 , V_5 ) ;
}
}
static inline void F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_59 ;
T_2 V_60 , V_61 , V_62 , V_63 , V_64 ;
int V_65 = 0 ;
unsigned long V_66 = 0 ;
unsigned long V_67 = 0 ;
F_34 ( & V_60 ) ;
F_34 ( & V_61 ) ;
F_34 ( & V_62 ) ;
F_34 ( & V_63 ) ;
F_34 ( & V_64 ) ;
if ( F_35 ( V_4 , & V_59 ) ) {
V_60 = V_4 -> V_60 . signal ;
V_61 = V_4 -> signal -> V_68 . signal ;
V_62 = V_4 -> V_62 ;
F_31 ( V_4 , & V_63 , & V_64 ) ;
V_65 = F_36 ( V_4 ) ;
F_11 () ;
V_66 = F_37 ( & F_38 ( V_4 ) -> V_69 -> V_70 ) ;
F_25 () ;
V_67 = F_39 ( V_4 , V_71 ) ;
F_40 ( V_4 , & V_59 ) ;
}
F_18 ( V_2 , L_14 , V_65 ) ;
F_18 ( V_2 , L_15 , V_66 , V_67 ) ;
F_29 ( V_2 , L_16 , & V_60 ) ;
F_29 ( V_2 , L_17 , & V_61 ) ;
F_29 ( V_2 , L_18 , & V_62 ) ;
F_29 ( V_2 , L_19 , & V_63 ) ;
F_29 ( V_2 , L_20 , & V_64 ) ;
}
static void F_41 ( struct V_1 * V_2 , const char * V_45 ,
T_3 * V_72 )
{
unsigned V_73 ;
F_3 ( V_2 , V_45 ) ;
F_42 (__capi) {
F_18 ( V_2 , L_21 ,
V_72 -> V_74 [ ( V_75 - 1 ) - V_73 ] ) ;
}
F_4 ( V_2 , '\n' ) ;
}
static inline void F_43 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_29 * V_29 ;
T_3 V_76 , V_77 , V_78 , V_79 ;
F_11 () ;
V_29 = F_38 ( V_4 ) ;
V_76 = V_29 -> V_76 ;
V_77 = V_29 -> V_77 ;
V_78 = V_29 -> V_78 ;
V_79 = V_29 -> V_79 ;
F_25 () ;
F_44 ( V_76 ) ;
F_44 ( V_77 ) ;
F_44 ( V_78 ) ;
F_44 ( V_79 ) ;
F_41 ( V_2 , L_22 , & V_76 ) ;
F_41 ( V_2 , L_23 , & V_77 ) ;
F_41 ( V_2 , L_24 , & V_78 ) ;
F_41 ( V_2 , L_25 , & V_79 ) ;
}
static inline void F_45 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#ifdef F_46
F_18 ( V_2 , L_26 , V_4 -> V_80 . V_81 ) ;
#endif
}
static inline void F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_18 ( V_2 , L_27
L_28 ,
V_4 -> V_82 ,
V_4 -> V_83 ) ;
}
static void F_48 ( struct V_1 * V_2 , struct V_3 * V_84 )
{
F_3 ( V_2 , L_29 ) ;
F_49 ( V_2 , & V_84 -> V_85 ) ;
F_4 ( V_2 , '\n' ) ;
F_3 ( V_2 , L_30 ) ;
F_50 ( V_2 , & V_84 -> V_85 ) ;
F_4 ( V_2 , '\n' ) ;
}
int F_51 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_84 )
{
struct V_86 * V_87 = F_52 ( V_84 ) ;
F_1 ( V_2 , V_84 ) ;
F_9 ( V_2 , V_21 , V_22 , V_84 ) ;
if ( V_87 ) {
F_53 ( V_2 , V_87 ) ;
F_54 ( V_87 ) ;
}
F_33 ( V_2 , V_84 ) ;
F_43 ( V_2 , V_84 ) ;
F_45 ( V_2 , V_84 ) ;
F_48 ( V_2 , V_84 ) ;
F_55 ( V_2 , V_84 ) ;
F_47 ( V_2 , V_84 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_84 , int V_88 )
{
unsigned long V_89 , V_90 , V_91 , V_92 = ~ 0UL ;
int V_93 , V_94 ;
int V_95 = - 1 , V_96 = 0 ;
T_2 V_97 , V_98 ;
char V_15 ;
T_1 V_30 = 0 , V_99 = - 1 , V_100 = - 1 ;
int V_65 = 0 ;
int V_101 ;
struct V_86 * V_87 ;
unsigned long long V_102 ;
unsigned long V_103 = 0 , V_104 = 0 ;
unsigned long V_105 = 0 , V_106 = 0 ;
T_4 V_107 , V_108 , V_109 , V_110 ;
T_4 V_111 , V_112 ;
unsigned long V_113 = 0 ;
char V_9 [ sizeof( V_84 -> V_10 ) ] ;
unsigned long V_59 ;
V_15 = * F_5 ( V_84 ) ;
V_89 = V_90 = V_91 = 0 ;
V_101 = F_57 ( V_84 , V_114 | V_115 ) ;
V_87 = F_52 ( V_84 ) ;
if ( V_87 ) {
V_89 = F_58 ( V_87 ) ;
if ( V_101 ) {
V_90 = F_59 ( V_84 ) ;
V_91 = F_60 ( V_84 ) ;
}
}
F_2 ( V_9 , V_84 ) ;
F_34 ( & V_97 ) ;
F_34 ( & V_98 ) ;
V_107 = V_108 = V_109 = V_110 = 0 ;
V_111 = V_112 = 0 ;
if ( F_35 ( V_84 , & V_59 ) ) {
struct V_116 * V_117 = V_84 -> signal ;
if ( V_117 -> V_118 ) {
struct V_22 * V_119 = F_61 ( V_117 -> V_118 ) ;
V_95 = F_20 ( V_119 , V_21 ) ;
F_62 ( V_119 ) ;
V_96 = F_63 ( F_64 ( V_117 -> V_118 ) ) ;
}
V_65 = F_36 ( V_84 ) ;
F_31 ( V_84 , & V_97 , & V_98 ) ;
V_103 = V_117 -> V_103 ;
V_104 = V_117 -> V_104 ;
V_107 = V_117 -> V_107 ;
V_108 = V_117 -> V_108 ;
V_111 = V_117 -> V_111 ;
V_113 = F_65 ( V_117 -> V_120 [ V_121 ] . V_122 ) ;
if ( V_88 ) {
struct V_3 * V_123 = V_84 ;
do {
V_105 += V_123 -> V_105 ;
V_106 += V_123 -> V_106 ;
V_112 += F_66 ( V_123 ) ;
V_123 = F_67 ( V_123 ) ;
} while ( V_123 != V_84 );
V_105 += V_117 -> V_105 ;
V_106 += V_117 -> V_106 ;
F_68 ( V_84 , & V_109 , & V_110 ) ;
V_112 += V_117 -> V_112 ;
}
V_100 = F_69 ( V_84 , V_21 ) ;
V_30 = F_13 ( V_84 -> V_32 , V_21 ) ;
V_99 = F_70 ( V_84 , V_21 ) ;
F_40 ( V_84 , & V_59 ) ;
}
if ( V_101 && ( ! V_88 || V_65 < 2 ) )
V_92 = F_71 ( V_84 ) ;
if ( ! V_88 ) {
V_105 = V_84 -> V_105 ;
V_106 = V_84 -> V_106 ;
F_72 ( V_84 , & V_109 , & V_110 ) ;
V_112 = F_66 ( V_84 ) ;
}
V_93 = F_73 ( V_84 ) ;
V_94 = F_74 ( V_84 ) ;
V_102 =
( unsigned long long ) V_84 -> V_124 . V_125 * V_126
+ V_84 -> V_124 . V_127 ;
V_102 = F_75 ( V_102 ) ;
F_18 ( V_2 , L_31 , F_20 ( V_22 , V_21 ) , V_9 , V_15 ) ;
F_76 ( V_2 , ' ' , V_30 ) ;
F_76 ( V_2 , ' ' , V_99 ) ;
F_76 ( V_2 , ' ' , V_100 ) ;
F_76 ( V_2 , ' ' , V_96 ) ;
F_76 ( V_2 , ' ' , V_95 ) ;
F_77 ( V_2 , ' ' , V_84 -> V_59 ) ;
F_77 ( V_2 , ' ' , V_105 ) ;
F_77 ( V_2 , ' ' , V_103 ) ;
F_77 ( V_2 , ' ' , V_106 ) ;
F_77 ( V_2 , ' ' , V_104 ) ;
F_77 ( V_2 , ' ' , F_78 ( V_109 ) ) ;
F_77 ( V_2 , ' ' , F_78 ( V_110 ) ) ;
F_76 ( V_2 , ' ' , F_78 ( V_107 ) ) ;
F_76 ( V_2 , ' ' , F_78 ( V_108 ) ) ;
F_76 ( V_2 , ' ' , V_93 ) ;
F_76 ( V_2 , ' ' , V_94 ) ;
F_76 ( V_2 , ' ' , V_65 ) ;
F_77 ( V_2 , ' ' , 0 ) ;
F_77 ( V_2 , ' ' , V_102 ) ;
F_77 ( V_2 , ' ' , V_89 ) ;
F_77 ( V_2 , ' ' , V_87 ? F_79 ( V_87 ) : 0 ) ;
F_77 ( V_2 , ' ' , V_113 ) ;
F_77 ( V_2 , ' ' , V_87 ? ( V_101 ? V_87 -> V_128 : 1 ) : 0 ) ;
F_77 ( V_2 , ' ' , V_87 ? ( V_101 ? V_87 -> V_129 : 1 ) : 0 ) ;
F_77 ( V_2 , ' ' , ( V_101 && V_87 ) ? V_87 -> V_130 : 0 ) ;
F_77 ( V_2 , ' ' , V_91 ) ;
F_77 ( V_2 , ' ' , V_90 ) ;
F_77 ( V_2 , ' ' , V_84 -> V_60 . signal . V_117 [ 0 ] & 0x7fffffffUL ) ;
F_77 ( V_2 , ' ' , V_84 -> V_62 . V_117 [ 0 ] & 0x7fffffffUL ) ;
F_77 ( V_2 , ' ' , V_97 . V_117 [ 0 ] & 0x7fffffffUL ) ;
F_77 ( V_2 , ' ' , V_98 . V_117 [ 0 ] & 0x7fffffffUL ) ;
F_77 ( V_2 , ' ' , V_92 ) ;
F_77 ( V_2 , ' ' , 0 ) ;
F_77 ( V_2 , ' ' , 0 ) ;
F_76 ( V_2 , ' ' , V_84 -> V_131 ) ;
F_76 ( V_2 , ' ' , F_80 ( V_84 ) ) ;
F_77 ( V_2 , ' ' , V_84 -> V_132 ) ;
F_77 ( V_2 , ' ' , V_84 -> V_133 ) ;
F_77 ( V_2 , ' ' , F_81 ( V_84 ) ) ;
F_77 ( V_2 , ' ' , F_78 ( V_112 ) ) ;
F_76 ( V_2 , ' ' , F_78 ( V_111 ) ) ;
if ( V_87 && V_101 ) {
F_77 ( V_2 , ' ' , V_87 -> V_134 ) ;
F_77 ( V_2 , ' ' , V_87 -> V_135 ) ;
F_77 ( V_2 , ' ' , V_87 -> V_136 ) ;
F_77 ( V_2 , ' ' , V_87 -> V_137 ) ;
F_77 ( V_2 , ' ' , V_87 -> V_138 ) ;
F_77 ( V_2 , ' ' , V_87 -> V_139 ) ;
F_77 ( V_2 , ' ' , V_87 -> V_140 ) ;
} else
F_18 ( V_2 , L_32 ) ;
if ( V_101 )
F_76 ( V_2 , ' ' , V_84 -> V_141 ) ;
else
F_76 ( V_2 , ' ' , 0 ) ;
F_4 ( V_2 , '\n' ) ;
if ( V_87 )
F_54 ( V_87 ) ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_84 )
{
return F_56 ( V_2 , V_21 , V_22 , V_84 , 0 ) ;
}
int F_83 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_84 )
{
return F_56 ( V_2 , V_21 , V_22 , V_84 , 1 ) ;
}
int F_84 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_84 )
{
unsigned long V_11 = 0 , V_142 = 0 , V_143 = 0 , V_144 = 0 , V_145 = 0 ;
struct V_86 * V_87 = F_52 ( V_84 ) ;
if ( V_87 ) {
V_11 = F_85 ( V_87 , & V_143 , & V_144 , & V_145 , & V_142 ) ;
F_54 ( V_87 ) ;
}
F_77 ( V_2 , 0 , V_11 ) ;
F_77 ( V_2 , ' ' , V_142 ) ;
F_77 ( V_2 , ' ' , V_143 ) ;
F_77 ( V_2 , ' ' , V_144 ) ;
F_77 ( V_2 , ' ' , 0 ) ;
F_77 ( V_2 , ' ' , V_145 ) ;
F_77 ( V_2 , ' ' , 0 ) ;
F_4 ( V_2 , '\n' ) ;
return 0 ;
}
static struct V_22 *
F_86 ( struct V_146 * V_146 , struct V_22 * V_147 , T_5 V_148 )
{
struct V_3 * V_149 , * V_84 ;
struct V_22 * V_22 = NULL ;
F_87 ( & V_150 ) ;
V_149 = F_88 ( F_89 ( V_146 ) , V_151 ) ;
if ( ! V_149 )
goto V_152;
if ( V_147 ) {
V_84 = F_88 ( V_147 , V_151 ) ;
if ( V_84 && V_84 -> V_32 == V_149 &&
! ( F_90 ( & V_84 -> V_153 ) ) ) {
if ( F_91 ( & V_84 -> V_153 , & V_149 -> V_154 ) )
goto V_152;
V_84 = F_92 ( & V_84 -> V_153 ,
struct V_3 , V_153 ) ;
V_22 = F_93 ( F_94 ( V_84 ) ) ;
goto V_152;
}
}
F_95 (task, &start->children, sibling) {
if ( V_148 -- == 0 ) {
V_22 = F_93 ( F_94 ( V_84 ) ) ;
break;
}
}
V_152:
F_96 ( & V_150 ) ;
return V_22 ;
}
static int F_97 ( struct V_1 * V_155 , void * V_156 )
{
struct V_146 * V_146 = V_155 -> V_157 ;
T_1 V_22 ;
V_22 = F_20 ( V_156 , V_146 -> V_158 -> V_159 ) ;
return F_18 ( V_155 , L_12 , V_22 ) ;
}
static void * F_98 ( struct V_1 * V_155 , T_5 * V_148 )
{
return F_86 ( V_155 -> V_157 , NULL , * V_148 ) ;
}
static void * F_99 ( struct V_1 * V_155 , void * V_156 , T_5 * V_148 )
{
struct V_22 * V_22 ;
V_22 = F_86 ( V_155 -> V_157 , V_156 , * V_148 + 1 ) ;
F_62 ( V_156 ) ;
++ * V_148 ;
return V_22 ;
}
static void F_100 ( struct V_1 * V_155 , void * V_156 )
{
F_62 ( V_156 ) ;
}
static int F_101 ( struct V_146 * V_146 , struct V_160 * V_160 )
{
struct V_1 * V_2 ;
int V_161 ;
V_161 = F_102 ( V_160 , & V_162 ) ;
if ( V_161 )
return V_161 ;
V_2 = V_160 -> V_163 ;
V_2 -> V_157 = V_146 ;
return V_161 ;
}
int F_103 ( struct V_146 * V_146 , struct V_160 * V_160 )
{
F_104 ( V_146 , V_160 ) ;
return 0 ;
}
