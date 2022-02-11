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
struct V_23 * V_24 = F_10 () ;
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
L_8 ,
F_5 ( V_4 ) ,
F_13 ( V_4 , V_21 ) ,
F_19 ( V_22 , V_21 ) ,
V_30 , V_31 ,
F_20 ( V_24 , V_29 -> V_34 ) ,
F_20 ( V_24 , V_29 -> V_35 ) ,
F_20 ( V_24 , V_29 -> V_36 ) ,
F_20 ( V_24 , V_29 -> V_37 ) ,
F_21 ( V_24 , V_29 -> V_38 ) ,
F_21 ( V_24 , V_29 -> V_39 ) ,
F_21 ( V_24 , V_29 -> V_40 ) ,
F_21 ( V_24 , V_29 -> V_41 ) ) ;
F_22 ( V_4 ) ;
if ( V_4 -> V_42 )
V_28 = F_23 ( V_4 -> V_42 ) ;
F_18 ( V_2 ,
L_9
L_10 ,
V_28 ? V_28 -> V_43 : 0 ) ;
F_24 () ;
V_25 = V_29 -> V_25 ;
F_25 ( V_4 ) ;
for ( V_26 = 0 ; V_26 < F_26 ( V_25 -> V_44 , V_45 ) ; V_26 ++ )
F_18 ( V_2 , L_11 ,
F_21 ( V_24 , F_27 ( V_25 , V_26 ) ) ) ;
F_28 ( V_29 ) ;
F_4 ( V_2 , '\n' ) ;
}
static void F_29 ( struct V_1 * V_2 , const char * V_46 ,
T_2 * V_47 )
{
int V_5 ;
F_3 ( V_2 , V_46 ) ;
V_5 = V_48 ;
do {
int V_49 = 0 ;
V_5 -= 4 ;
if ( F_30 ( V_47 , V_5 + 1 ) ) V_49 |= 1 ;
if ( F_30 ( V_47 , V_5 + 2 ) ) V_49 |= 2 ;
if ( F_30 ( V_47 , V_5 + 3 ) ) V_49 |= 4 ;
if ( F_30 ( V_47 , V_5 + 4 ) ) V_49 |= 8 ;
F_18 ( V_2 , L_12 , V_49 ) ;
} while ( V_5 >= 4 );
F_4 ( V_2 , '\n' ) ;
}
static void F_31 ( struct V_3 * V_4 , T_2 * V_50 ,
T_2 * V_51 )
{
struct V_52 * V_53 ;
int V_5 ;
V_53 = V_4 -> V_54 -> V_55 ;
for ( V_5 = 1 ; V_5 <= V_48 ; ++ V_5 , ++ V_53 ) {
if ( V_53 -> V_56 . V_57 == V_58 )
F_32 ( V_50 , V_5 ) ;
else if ( V_53 -> V_56 . V_57 != V_59 )
F_32 ( V_51 , V_5 ) ;
}
}
static inline void F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_60 ;
T_2 V_61 , V_62 , V_63 , V_64 , V_65 ;
int V_66 = 0 ;
unsigned long V_67 = 0 ;
unsigned long V_68 = 0 ;
F_34 ( & V_61 ) ;
F_34 ( & V_62 ) ;
F_34 ( & V_63 ) ;
F_34 ( & V_64 ) ;
F_34 ( & V_65 ) ;
if ( F_35 ( V_4 , & V_60 ) ) {
V_61 = V_4 -> V_61 . signal ;
V_62 = V_4 -> signal -> V_69 . signal ;
V_63 = V_4 -> V_63 ;
F_31 ( V_4 , & V_64 , & V_65 ) ;
V_66 = F_36 ( V_4 ) ;
F_11 () ;
V_67 = F_37 ( & F_38 ( V_4 ) -> V_70 -> V_71 ) ;
F_24 () ;
V_68 = F_39 ( V_4 , V_72 ) ;
F_40 ( V_4 , & V_60 ) ;
}
F_18 ( V_2 , L_13 , V_66 ) ;
F_18 ( V_2 , L_14 , V_67 , V_68 ) ;
F_29 ( V_2 , L_15 , & V_61 ) ;
F_29 ( V_2 , L_16 , & V_62 ) ;
F_29 ( V_2 , L_17 , & V_63 ) ;
F_29 ( V_2 , L_18 , & V_64 ) ;
F_29 ( V_2 , L_19 , & V_65 ) ;
}
static void F_41 ( struct V_1 * V_2 , const char * V_46 ,
T_3 * V_73 )
{
unsigned V_74 ;
F_3 ( V_2 , V_46 ) ;
F_42 (__capi) {
F_18 ( V_2 , L_20 ,
V_73 -> V_75 [ ( V_76 - 1 ) - V_74 ] ) ;
}
F_4 ( V_2 , '\n' ) ;
}
static inline void F_43 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_29 * V_29 ;
T_3 V_77 , V_78 , V_79 , V_80 ;
F_11 () ;
V_29 = F_38 ( V_4 ) ;
V_77 = V_29 -> V_77 ;
V_78 = V_29 -> V_78 ;
V_79 = V_29 -> V_79 ;
V_80 = V_29 -> V_80 ;
F_24 () ;
F_41 ( V_2 , L_21 , & V_77 ) ;
F_41 ( V_2 , L_22 , & V_78 ) ;
F_41 ( V_2 , L_23 , & V_79 ) ;
F_41 ( V_2 , L_24 , & V_80 ) ;
}
static inline void F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_18 ( V_2 , L_25
L_26 ,
V_4 -> V_81 ,
V_4 -> V_82 ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_3 * V_83 )
{
F_3 ( V_2 , L_27 ) ;
F_46 ( V_2 , & V_83 -> V_84 ) ;
F_4 ( V_2 , '\n' ) ;
F_3 ( V_2 , L_28 ) ;
F_47 ( V_2 , & V_83 -> V_84 ) ;
F_4 ( V_2 , '\n' ) ;
}
int F_48 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_83 )
{
struct V_85 * V_86 = F_49 ( V_83 ) ;
F_1 ( V_2 , V_83 ) ;
F_9 ( V_2 , V_21 , V_22 , V_83 ) ;
if ( V_86 ) {
F_50 ( V_2 , V_86 ) ;
F_51 ( V_86 ) ;
}
F_33 ( V_2 , V_83 ) ;
F_43 ( V_2 , V_83 ) ;
F_45 ( V_2 , V_83 ) ;
F_52 ( V_2 , V_83 ) ;
F_44 ( V_2 , V_83 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_83 , int V_87 )
{
unsigned long V_88 , V_89 , V_90 , V_91 = ~ 0UL ;
int V_92 , V_93 ;
int V_94 = - 1 , V_95 = 0 ;
T_2 V_96 , V_97 ;
char V_15 ;
T_1 V_30 = 0 , V_98 = - 1 , V_99 = - 1 ;
int V_66 = 0 ;
int V_100 ;
struct V_85 * V_86 ;
unsigned long long V_101 ;
unsigned long V_102 = 0 , V_103 = 0 ;
unsigned long V_104 = 0 , V_105 = 0 ;
T_4 V_106 , V_107 , V_108 , V_109 ;
T_4 V_110 , V_111 ;
unsigned long V_112 = 0 ;
char V_9 [ sizeof( V_83 -> V_10 ) ] ;
unsigned long V_60 ;
V_15 = * F_5 ( V_83 ) ;
V_88 = V_89 = V_90 = 0 ;
V_100 = F_54 ( V_83 , V_113 | V_114 ) ;
V_86 = F_49 ( V_83 ) ;
if ( V_86 ) {
V_88 = F_55 ( V_86 ) ;
if ( V_100 ) {
V_89 = F_56 ( V_83 ) ;
V_90 = F_57 ( V_83 ) ;
}
}
F_2 ( V_9 , V_83 ) ;
F_34 ( & V_96 ) ;
F_34 ( & V_97 ) ;
V_106 = V_107 = V_108 = V_109 = 0 ;
V_110 = V_111 = 0 ;
if ( F_35 ( V_83 , & V_60 ) ) {
struct V_115 * V_116 = V_83 -> signal ;
if ( V_116 -> V_117 ) {
struct V_22 * V_118 = F_58 ( V_116 -> V_117 ) ;
V_94 = F_19 ( V_118 , V_21 ) ;
F_59 ( V_118 ) ;
V_95 = F_60 ( F_61 ( V_116 -> V_117 ) ) ;
}
V_66 = F_36 ( V_83 ) ;
F_31 ( V_83 , & V_96 , & V_97 ) ;
V_102 = V_116 -> V_102 ;
V_103 = V_116 -> V_103 ;
V_106 = V_116 -> V_106 ;
V_107 = V_116 -> V_107 ;
V_110 = V_116 -> V_110 ;
V_112 = F_62 ( V_116 -> V_119 [ V_120 ] . V_121 ) ;
if ( V_87 ) {
struct V_3 * V_122 = V_83 ;
do {
V_104 += V_122 -> V_104 ;
V_105 += V_122 -> V_105 ;
V_111 += V_122 -> V_111 ;
V_122 = F_63 ( V_122 ) ;
} while ( V_122 != V_83 );
V_104 += V_116 -> V_104 ;
V_105 += V_116 -> V_105 ;
F_64 ( V_83 , & V_108 , & V_109 ) ;
V_111 += V_116 -> V_111 ;
}
V_99 = F_65 ( V_83 , V_21 ) ;
V_30 = F_13 ( V_83 -> V_32 , V_21 ) ;
V_98 = F_66 ( V_83 , V_21 ) ;
F_40 ( V_83 , & V_60 ) ;
}
if ( V_100 && ( ! V_87 || V_66 < 2 ) )
V_91 = F_67 ( V_83 ) ;
if ( ! V_87 ) {
V_104 = V_83 -> V_104 ;
V_105 = V_83 -> V_105 ;
F_68 ( V_83 , & V_108 , & V_109 ) ;
V_111 = V_83 -> V_111 ;
}
V_92 = F_69 ( V_83 ) ;
V_93 = F_70 ( V_83 ) ;
V_101 =
( unsigned long long ) V_83 -> V_123 . V_124 * V_125
+ V_83 -> V_123 . V_126 ;
V_101 = F_71 ( V_101 ) ;
F_18 ( V_2 , L_29 , F_19 ( V_22 , V_21 ) , V_9 , V_15 ) ;
F_72 ( V_2 , ' ' , V_30 ) ;
F_72 ( V_2 , ' ' , V_98 ) ;
F_72 ( V_2 , ' ' , V_99 ) ;
F_72 ( V_2 , ' ' , V_95 ) ;
F_72 ( V_2 , ' ' , V_94 ) ;
F_73 ( V_2 , ' ' , V_83 -> V_60 ) ;
F_73 ( V_2 , ' ' , V_104 ) ;
F_73 ( V_2 , ' ' , V_102 ) ;
F_73 ( V_2 , ' ' , V_105 ) ;
F_73 ( V_2 , ' ' , V_103 ) ;
F_73 ( V_2 , ' ' , F_74 ( V_108 ) ) ;
F_73 ( V_2 , ' ' , F_74 ( V_109 ) ) ;
F_72 ( V_2 , ' ' , F_74 ( V_106 ) ) ;
F_72 ( V_2 , ' ' , F_74 ( V_107 ) ) ;
F_72 ( V_2 , ' ' , V_92 ) ;
F_72 ( V_2 , ' ' , V_93 ) ;
F_72 ( V_2 , ' ' , V_66 ) ;
F_73 ( V_2 , ' ' , 0 ) ;
F_73 ( V_2 , ' ' , V_101 ) ;
F_73 ( V_2 , ' ' , V_88 ) ;
F_73 ( V_2 , ' ' , V_86 ? F_75 ( V_86 ) : 0 ) ;
F_73 ( V_2 , ' ' , V_112 ) ;
F_73 ( V_2 , ' ' , V_86 ? ( V_100 ? V_86 -> V_127 : 1 ) : 0 ) ;
F_73 ( V_2 , ' ' , V_86 ? ( V_100 ? V_86 -> V_128 : 1 ) : 0 ) ;
F_73 ( V_2 , ' ' , ( V_100 && V_86 ) ? V_86 -> V_129 : 0 ) ;
F_73 ( V_2 , ' ' , V_90 ) ;
F_73 ( V_2 , ' ' , V_89 ) ;
F_73 ( V_2 , ' ' , V_83 -> V_61 . signal . V_116 [ 0 ] & 0x7fffffffUL ) ;
F_73 ( V_2 , ' ' , V_83 -> V_63 . V_116 [ 0 ] & 0x7fffffffUL ) ;
F_73 ( V_2 , ' ' , V_96 . V_116 [ 0 ] & 0x7fffffffUL ) ;
F_73 ( V_2 , ' ' , V_97 . V_116 [ 0 ] & 0x7fffffffUL ) ;
F_73 ( V_2 , ' ' , V_91 ) ;
F_73 ( V_2 , ' ' , 0 ) ;
F_73 ( V_2 , ' ' , 0 ) ;
F_72 ( V_2 , ' ' , V_83 -> V_130 ) ;
F_72 ( V_2 , ' ' , F_76 ( V_83 ) ) ;
F_73 ( V_2 , ' ' , V_83 -> V_131 ) ;
F_73 ( V_2 , ' ' , V_83 -> V_132 ) ;
F_73 ( V_2 , ' ' , F_77 ( V_83 ) ) ;
F_73 ( V_2 , ' ' , F_74 ( V_111 ) ) ;
F_72 ( V_2 , ' ' , F_74 ( V_110 ) ) ;
if ( V_86 && V_100 ) {
F_73 ( V_2 , ' ' , V_86 -> V_133 ) ;
F_73 ( V_2 , ' ' , V_86 -> V_134 ) ;
F_73 ( V_2 , ' ' , V_86 -> V_135 ) ;
F_73 ( V_2 , ' ' , V_86 -> V_136 ) ;
F_73 ( V_2 , ' ' , V_86 -> V_137 ) ;
F_73 ( V_2 , ' ' , V_86 -> V_138 ) ;
F_73 ( V_2 , ' ' , V_86 -> V_139 ) ;
} else
F_18 ( V_2 , L_30 ) ;
if ( V_100 )
F_72 ( V_2 , ' ' , V_83 -> V_140 ) ;
else
F_72 ( V_2 , ' ' , 0 ) ;
F_4 ( V_2 , '\n' ) ;
if ( V_86 )
F_51 ( V_86 ) ;
return 0 ;
}
int F_78 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_83 )
{
return F_53 ( V_2 , V_21 , V_22 , V_83 , 0 ) ;
}
int F_79 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_83 )
{
return F_53 ( V_2 , V_21 , V_22 , V_83 , 1 ) ;
}
int F_80 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_83 )
{
unsigned long V_11 = 0 , V_141 = 0 , V_142 = 0 , V_143 = 0 , V_144 = 0 ;
struct V_85 * V_86 = F_49 ( V_83 ) ;
if ( V_86 ) {
V_11 = F_81 ( V_86 , & V_142 , & V_143 , & V_144 , & V_141 ) ;
F_51 ( V_86 ) ;
}
F_73 ( V_2 , 0 , V_11 ) ;
F_73 ( V_2 , ' ' , V_141 ) ;
F_73 ( V_2 , ' ' , V_142 ) ;
F_73 ( V_2 , ' ' , V_143 ) ;
F_73 ( V_2 , ' ' , 0 ) ;
F_73 ( V_2 , ' ' , V_144 ) ;
F_73 ( V_2 , ' ' , 0 ) ;
F_4 ( V_2 , '\n' ) ;
return 0 ;
}
static struct V_22 *
F_82 ( struct V_145 * V_145 , struct V_22 * V_146 , T_5 V_147 )
{
struct V_3 * V_148 , * V_83 ;
struct V_22 * V_22 = NULL ;
F_83 ( & V_149 ) ;
V_148 = F_84 ( F_85 ( V_145 ) , V_150 ) ;
if ( ! V_148 )
goto V_151;
if ( V_146 ) {
V_83 = F_84 ( V_146 , V_150 ) ;
if ( V_83 && V_83 -> V_32 == V_148 &&
! ( F_86 ( & V_83 -> V_152 ) ) ) {
if ( F_87 ( & V_83 -> V_152 , & V_148 -> V_153 ) )
goto V_151;
V_83 = F_88 ( & V_83 -> V_152 ,
struct V_3 , V_152 ) ;
V_22 = F_89 ( F_90 ( V_83 ) ) ;
goto V_151;
}
}
F_91 (task, &start->children, sibling) {
if ( V_147 -- == 0 ) {
V_22 = F_89 ( F_90 ( V_83 ) ) ;
break;
}
}
V_151:
F_92 ( & V_149 ) ;
return V_22 ;
}
static int F_93 ( struct V_1 * V_154 , void * V_155 )
{
struct V_145 * V_145 = V_154 -> V_156 ;
T_1 V_22 ;
V_22 = F_19 ( V_155 , V_145 -> V_157 -> V_158 ) ;
return F_18 ( V_154 , L_11 , V_22 ) ;
}
static void * F_94 ( struct V_1 * V_154 , T_5 * V_147 )
{
return F_82 ( V_154 -> V_156 , NULL , * V_147 ) ;
}
static void * F_95 ( struct V_1 * V_154 , void * V_155 , T_5 * V_147 )
{
struct V_22 * V_22 ;
V_22 = F_82 ( V_154 -> V_156 , V_155 , * V_147 + 1 ) ;
F_59 ( V_155 ) ;
++ * V_147 ;
return V_22 ;
}
static void F_96 ( struct V_1 * V_154 , void * V_155 )
{
F_59 ( V_155 ) ;
}
static int F_97 ( struct V_145 * V_145 , struct V_159 * V_159 )
{
struct V_1 * V_2 ;
int V_160 ;
V_160 = F_98 ( V_159 , & V_161 ) ;
if ( V_160 )
return V_160 ;
V_2 = V_159 -> V_162 ;
V_2 -> V_156 = V_145 ;
return V_160 ;
}
int F_99 ( struct V_145 * V_145 , struct V_159 * V_159 )
{
F_100 ( V_145 , V_159 ) ;
return 0 ;
}
