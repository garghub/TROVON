int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 == V_4 ;
}
int F_2 ( struct V_1 * V_1 )
{
return ( V_1 -> V_5 & V_6 ) ? 1 : 0 ;
}
static int F_3 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 == V_7 ;
}
int F_4 ( struct V_1 * V_1 , int V_8 )
{
#ifdef F_5
return V_8 >= 0 && V_8 < V_1 -> V_9 ;
#else
return 0 ;
#endif
}
static void F_6 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_1 * V_1 = F_7 ( V_11 -> V_14 ) ;
if ( V_13 -> V_15 )
F_8 ( V_1 -> V_2 , V_13 -> V_16 ,
V_13 -> V_17 , V_18 ) ;
else
F_9 ( V_1 -> V_2 , V_13 -> V_16 ,
V_13 -> V_17 , V_18 ) ;
if ( V_13 -> V_19 )
F_10 ( V_13 -> V_19 ) ;
}
static void F_11 ( struct V_10 * V_11 ,
struct V_20 * V_20 , struct V_12 * V_13 , void * V_21 )
{
F_6 ( V_11 , V_13 ) ;
}
static int F_12 ( struct V_22 * V_14 , struct V_20 * V_20 ,
T_1 type , T_2 V_23 , T_2 V_24 , void * V_21 )
{
struct V_1 * V_1 = F_7 ( V_14 ) ;
F_13 ( & V_1 -> V_25 [ V_23 ] ) ;
F_14 ( & V_1 -> V_11 [ V_23 ] , V_20 ,
V_24 , F_11 ,
V_21 ) ;
if ( F_15 ( F_16 ( V_1 -> V_26 , V_23 ) ) &&
F_17 ( & V_1 -> V_11 [ V_23 ] ) >=
( V_27 + V_28 ) )
F_18 ( V_1 -> V_26 , V_23 ) ;
F_19 ( & V_1 -> V_25 [ V_23 ] ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_1 )
{
unsigned int V_29 ;
T_3 V_30 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ ) {
V_30 = F_21 ( & V_1 -> V_11 [ V_29 ] ) ;
if ( V_30 )
F_22 ( V_1 -> V_26 , L_1 ,
V_29 , V_30 ) ;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
V_30 = F_23 ( & V_1 -> V_33 [ V_29 ] ) ;
if ( V_30 )
F_22 ( V_1 -> V_26 , L_2 ,
V_29 , V_30 ) ;
}
}
static void F_24 ( struct V_1 * V_1 )
{
T_3 V_34 = F_25 ( V_1 -> V_14 ) ;
if ( V_34 != V_1 -> V_34 ) {
F_26 ( V_1 -> V_26 , L_3 ,
V_1 -> V_34 , V_34 ) ;
V_1 -> V_34 = V_34 ;
}
}
static void F_27 ( struct V_1 * V_1 )
{
T_3 V_35 = F_28 ( V_1 -> V_14 ) ;
struct V_36 * V_26 = V_1 -> V_26 ;
if ( V_35 && V_35 != V_1 -> V_37 ) {
V_1 -> V_37 = V_35 ;
if ( F_1 ( V_1 ) || F_3 ( V_1 ) ) {
V_35 = F_29 ( int , V_38 ,
F_30 ( int , V_39 , V_35 ) ) ;
if ( V_35 != V_26 -> V_35 )
F_31 ( & V_1 -> V_40 ) ;
} else {
if ( V_35 < V_26 -> V_35 )
F_32 ( V_26 ,
L_4
L_5 ,
V_26 -> V_35 , V_35 ) ;
}
}
}
static void F_33 ( struct V_1 * V_1 )
{
int V_41 = F_34 ( V_1 -> V_14 ) ;
int V_42 = F_35 ( V_1 -> V_26 ) ;
if ( V_41 && ! V_42 ) {
F_26 ( V_1 -> V_26 , L_6 ) ;
F_36 ( V_1 -> V_26 ) ;
} else if ( ! V_41 && V_42 ) {
F_26 ( V_1 -> V_26 , L_7 ) ;
F_37 ( V_1 -> V_26 ) ;
}
}
static void F_38 ( struct V_1 * V_1 )
{
F_24 ( V_1 ) ;
F_27 ( V_1 ) ;
F_33 ( V_1 ) ;
}
static T_4 F_39 ( int V_43 , void * V_44 )
{
struct V_36 * V_26 = V_44 ;
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_45 = F_41 () ;
unsigned int V_46 = F_42 () ;
unsigned int V_47 = F_43 () ;
T_3 V_48 ;
F_44 ( & V_1 -> V_49 [ V_45 ] ) ;
V_48 = F_45 ( V_1 -> V_50 ) ;
if ( ! V_48 ) {
F_46 ( & V_1 -> V_49 [ V_45 ] ) ;
return V_51 ;
}
if ( F_47 ( V_48 , V_47 ) ) {
F_48 ( & V_1 -> V_49 [ V_47 ] ) ;
F_38 ( V_1 ) ;
}
if ( F_47 ( V_48 , V_46 ) ) {
F_48 ( & V_1 -> V_49 [ V_46 ] ) ;
F_20 ( V_1 ) ;
F_31 ( & V_1 -> V_52 ) ;
return V_53 ;
}
if ( F_47 ( V_48 , V_45 ) ) {
if ( F_49 ( & V_1 -> V_54 [ 0 ] ) )
F_50 ( & V_1 -> V_54 [ 0 ] ) ;
} else {
F_46 ( & V_1 -> V_49 [ V_45 ] ) ;
}
return V_53 ;
}
static T_4 F_51 ( int V_43 , void * V_44 )
{
struct V_1 * V_1 = V_44 ;
F_52 ( & V_1 -> V_54 [ 0 ] ) ;
return V_53 ;
}
static T_4 F_53 ( int V_43 , void * V_44 )
{
struct V_55 * V_54 = V_44 ;
F_52 ( V_54 ) ;
return V_53 ;
}
static T_4 F_54 ( int V_43 , void * V_44 )
{
struct V_1 * V_1 = V_44 ;
unsigned int V_56 ;
unsigned int V_49 ;
unsigned int V_57 = - 1 ;
unsigned int V_58 ;
unsigned int V_59 ;
V_59 = ( T_3 ) V_43 - V_1 -> V_60 [ F_55 ( V_1 , 0 ) ] . V_61 ;
V_56 = F_56 ( V_1 , V_59 ) ;
V_49 = F_55 ( V_1 , V_59 ) ;
V_58 = F_57 ( & V_1 -> V_56 [ V_56 ] ,
V_57 , F_12 , NULL ) ;
F_58 ( & V_1 -> V_49 [ V_49 ] ,
V_58 ,
1 ,
1 ) ;
return V_53 ;
}
static T_4 F_59 ( int V_43 , void * V_44 )
{
struct V_1 * V_1 = V_44 ;
unsigned int V_49 = F_60 ( V_1 ) ;
F_48 ( & V_1 -> V_49 [ V_49 ] ) ;
F_20 ( V_1 ) ;
F_31 ( & V_1 -> V_52 ) ;
return V_53 ;
}
static T_4 F_61 ( int V_43 , void * V_44 )
{
struct V_1 * V_1 = V_44 ;
unsigned int V_49 = F_62 ( V_1 ) ;
F_48 ( & V_1 -> V_49 [ V_49 ] ) ;
F_38 ( V_1 ) ;
return V_53 ;
}
static inline void F_63 ( struct V_1 * V_1 ,
struct V_10 * V_11 , struct V_62 * V_63 ,
unsigned int V_64 , int V_65 )
{
const T_5 * V_66 ;
for ( V_66 = F_64 ( V_63 ) -> V_67 ; V_64 ; V_66 ++ ) {
V_64 -= F_65 ( V_66 ) ;
F_66 ( V_11 , V_63 ,
F_67 ( & V_1 -> V_2 -> V_68 ,
V_66 , 0 , F_65 ( V_66 ) ,
V_69 ) ,
F_65 ( V_66 ) ,
( V_64 == 0 ) ,
V_65 ) ;
}
}
static inline void F_68 ( struct V_1 * V_1 ,
struct V_10 * V_11 , struct V_62 * V_63 ,
int V_70 , unsigned int V_71 , int V_65 )
{
unsigned int V_72 = F_69 ( V_63 ) ;
unsigned int V_64 = V_63 -> V_17 - V_72 ;
int V_73 = ( V_64 == 0 ) ;
F_70 ( V_11 , V_63 ,
F_71 ( V_1 -> V_2 , V_63 -> V_44 ,
V_72 , V_18 ) ,
V_72 ,
V_70 , V_71 ,
V_73 , V_65 ) ;
if ( ! V_73 )
F_63 ( V_1 , V_11 , V_63 , V_64 , V_65 ) ;
}
static inline void F_72 ( struct V_1 * V_1 ,
struct V_10 * V_11 , struct V_62 * V_63 ,
int V_70 , unsigned int V_71 , int V_65 )
{
unsigned int V_72 = F_69 ( V_63 ) ;
unsigned int V_64 = V_63 -> V_17 - V_72 ;
unsigned int V_74 = F_73 ( V_63 ) ;
unsigned int V_75 = V_74 + V_63 -> V_75 ;
int V_73 = ( V_64 == 0 ) ;
F_74 ( V_11 , V_63 ,
F_71 ( V_1 -> V_2 , V_63 -> V_44 ,
V_72 , V_18 ) ,
V_72 ,
V_75 ,
V_74 ,
V_70 , V_71 ,
V_73 , V_65 ) ;
if ( ! V_73 )
F_63 ( V_1 , V_11 , V_63 , V_64 , V_65 ) ;
}
static inline void F_75 ( struct V_1 * V_1 ,
struct V_10 * V_11 , struct V_62 * V_63 , unsigned int V_76 ,
int V_70 , unsigned int V_71 , int V_65 )
{
unsigned int V_77 = F_69 ( V_63 ) ;
unsigned int V_64 = V_63 -> V_17 - V_77 ;
unsigned int V_74 = F_76 ( V_63 ) + F_77 ( V_63 ) ;
int V_73 = ( V_64 == 0 ) ;
unsigned int V_17 ;
T_6 V_16 ;
unsigned int V_78 = 0 ;
T_5 * V_66 ;
if ( V_63 -> V_79 == F_78 ( V_80 ) ) {
F_79 ( V_63 ) -> V_81 = 0 ;
F_80 ( V_63 ) -> V_81 = ~ F_81 ( F_79 ( V_63 ) -> V_82 ,
F_79 ( V_63 ) -> V_83 , 0 , V_84 , 0 ) ;
} else if ( V_63 -> V_79 == F_78 ( V_85 ) ) {
F_80 ( V_63 ) -> V_81 = ~ F_82 ( & F_83 ( V_63 ) -> V_82 ,
& F_83 ( V_63 ) -> V_83 , 0 , V_84 , 0 ) ;
}
while ( V_77 ) {
V_17 = F_84 ( V_77 , ( unsigned int ) V_86 ) ;
V_16 = F_71 ( V_1 -> V_2 , V_63 -> V_44 + V_78 ,
V_17 , V_18 ) ;
F_85 ( V_11 , V_63 ,
V_16 ,
V_17 ,
V_76 , V_74 ,
V_70 , V_71 ,
V_73 && ( V_17 == V_77 ) , V_65 ) ;
V_77 -= V_17 ;
V_78 += V_17 ;
}
if ( V_73 )
return;
for ( V_66 = F_64 ( V_63 ) -> V_67 ; V_64 ; V_66 ++ ) {
V_64 -= F_65 ( V_66 ) ;
V_77 = F_65 ( V_66 ) ;
V_78 = 0 ;
while ( V_77 ) {
V_17 = F_84 ( V_77 ,
( unsigned int ) V_86 ) ;
V_16 = F_67 ( & V_1 -> V_2 -> V_68 , V_66 ,
V_78 , V_17 ,
V_69 ) ;
F_66 ( V_11 , V_63 ,
V_16 ,
V_17 ,
( V_64 == 0 ) &&
( V_17 == V_77 ) ,
V_65 ) ;
V_77 -= V_17 ;
V_78 += V_17 ;
}
}
}
static inline void F_86 ( struct V_1 * V_1 ,
struct V_10 * V_11 , struct V_62 * V_63 )
{
unsigned int V_76 = F_64 ( V_63 ) -> V_87 ;
unsigned int V_71 = 0 ;
int V_70 = 0 ;
int V_65 = 0 ;
if ( F_87 ( V_63 ) ) {
V_70 = 1 ;
V_71 = F_88 ( V_63 ) ;
} else if ( V_1 -> V_88 ) {
V_71 = V_1 -> V_89 ;
V_65 = 1 ;
}
if ( V_76 )
F_75 ( V_1 , V_11 , V_63 , V_76 ,
V_70 , V_71 , V_65 ) ;
else if ( V_63 -> V_90 == V_91 )
F_72 ( V_1 , V_11 , V_63 ,
V_70 , V_71 , V_65 ) ;
else
F_68 ( V_1 , V_11 , V_63 ,
V_70 , V_71 , V_65 ) ;
}
static T_7 F_89 ( struct V_62 * V_63 ,
struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_10 * V_11 ;
unsigned long V_92 ;
unsigned int V_93 ;
if ( V_63 -> V_17 <= 0 ) {
F_10 ( V_63 ) ;
return V_94 ;
}
V_93 = F_90 ( V_63 ) % V_1 -> V_31 ;
V_11 = & V_1 -> V_11 [ V_93 ] ;
if ( F_64 ( V_63 ) -> V_87 == 0 &&
F_64 ( V_63 ) -> V_95 + 1 > V_96 &&
F_91 ( V_63 ) ) {
F_10 ( V_63 ) ;
return V_94 ;
}
F_92 ( & V_1 -> V_25 [ V_93 ] , V_92 ) ;
if ( F_17 ( V_11 ) <
F_64 ( V_63 ) -> V_95 + V_28 ) {
F_93 ( F_16 ( V_26 , V_93 ) ) ;
F_22 ( V_26 , L_8 ) ;
F_94 ( & V_1 -> V_25 [ V_93 ] , V_92 ) ;
return V_97 ;
}
F_86 ( V_1 , V_11 , V_63 ) ;
if ( F_17 ( V_11 ) < V_27 + V_28 )
F_93 ( F_16 ( V_26 , V_93 ) ) ;
F_94 ( & V_1 -> V_25 [ V_93 ] , V_92 ) ;
return V_94 ;
}
static struct V_98 * F_95 ( struct V_36 * V_26 ,
struct V_98 * V_99 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_100 * V_101 ;
F_96 ( V_1 , & V_101 ) ;
V_99 -> V_102 = V_101 -> V_103 . V_104 ;
V_99 -> V_105 = V_101 -> V_103 . V_106 ;
V_99 -> V_107 = V_101 -> V_103 . V_107 ;
V_99 -> V_108 = V_101 -> V_103 . V_109 ;
V_99 -> V_110 = V_101 -> V_111 . V_112 ;
V_99 -> V_113 = V_101 -> V_111 . V_114 ;
V_99 -> V_115 = V_101 -> V_111 . V_115 ;
V_99 -> V_116 = V_101 -> V_111 . V_117 ;
V_99 -> V_118 = V_1 -> V_119 ;
V_99 -> V_120 = V_1 -> V_121 ;
V_99 -> V_122 = V_101 -> V_111 . V_123 + V_101 -> V_111 . V_124 ;
return V_99 ;
}
static int F_97 ( struct V_36 * V_26 , const T_1 * V_125 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
if ( V_1 -> V_126 == V_127 ) {
unsigned int V_126 = F_98 ( V_26 ) ;
F_32 ( V_26 , L_9 ,
V_127 , V_126 ) ;
return - V_128 ;
}
F_99 ( V_1 , V_125 ) ;
V_1 -> V_126 ++ ;
return 0 ;
}
static int F_100 ( struct V_36 * V_26 , const T_1 * V_125 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
F_101 ( V_1 , V_125 ) ;
V_1 -> V_126 -- ;
return 0 ;
}
static int F_102 ( struct V_36 * V_26 , const T_1 * V_129 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
if ( V_1 -> V_130 == V_131 ) {
unsigned int V_130 = F_103 ( V_26 ) ;
F_32 ( V_26 , L_10 ,
V_131 , V_130 ) ;
return - V_128 ;
}
F_99 ( V_1 , V_129 ) ;
V_1 -> V_130 ++ ;
return 0 ;
}
static int F_104 ( struct V_36 * V_26 , const T_1 * V_129 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
F_101 ( V_1 , V_129 ) ;
V_1 -> V_130 -- ;
return 0 ;
}
void F_105 ( struct V_1 * V_1 )
{
struct V_36 * V_26 = V_1 -> V_26 ;
F_106 ( V_26 , NULL ) ;
F_107 ( V_26 , NULL ) ;
V_1 -> V_126 = 0 ;
V_1 -> V_130 = 0 ;
V_1 -> V_92 = 0 ;
}
static int F_108 ( struct V_36 * V_26 , char * V_132 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
if ( F_1 ( V_1 ) || F_3 ( V_1 ) ) {
if ( ! F_109 ( V_132 ) && ! F_110 ( V_132 ) )
return - V_133 ;
} else {
if ( ! F_109 ( V_132 ) )
return - V_133 ;
}
memcpy ( V_26 -> V_134 , V_132 , V_26 -> V_135 ) ;
return 0 ;
}
static int F_111 ( struct V_36 * V_26 , void * V_136 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_137 * V_82 = V_136 ;
char * V_132 = V_82 -> V_138 ;
int V_139 ;
if ( F_112 ( V_1 -> V_26 ) ) {
V_139 = F_113 ( V_1 ) ;
if ( V_139 )
return V_139 ;
}
V_139 = F_108 ( V_26 , V_132 ) ;
if ( V_139 )
return V_139 ;
if ( F_112 ( V_1 -> V_26 ) ) {
V_139 = F_114 ( V_1 ) ;
if ( V_139 )
return V_139 ;
}
return V_139 ;
}
static int F_115 ( struct V_36 * V_26 , void * V_136 )
{
struct V_137 * V_82 = V_136 ;
char * V_132 = V_82 -> V_138 ;
struct V_1 * V_1 = F_40 ( V_26 ) ;
int V_139 ;
V_139 = F_113 ( V_1 ) ;
if ( V_139 )
return V_139 ;
V_139 = F_108 ( V_26 , V_132 ) ;
if ( V_139 )
return V_139 ;
return F_114 ( V_1 ) ;
}
static void F_116 ( struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
int V_140 = 1 ;
int V_116 = ( V_26 -> V_92 & V_141 ) ? 1 : 0 ;
int V_142 = ( V_26 -> V_92 & V_143 ) ? 1 : 0 ;
int V_144 = ( V_26 -> V_92 & V_145 ) ||
F_103 ( V_26 ) > V_131 ;
int V_146 = ( V_26 -> V_92 & V_147 ) ||
F_98 ( V_26 ) > V_127 ;
unsigned int V_92 = V_26 -> V_92 |
( V_146 ? V_147 : 0 ) |
( V_144 ? V_145 : 0 ) ;
if ( V_1 -> V_92 != V_92 ) {
V_1 -> V_92 = V_92 ;
F_117 ( V_1 , V_140 ,
V_116 , V_142 , V_144 , V_146 ) ;
}
if ( ! V_144 ) {
F_118 ( V_26 , F_102 , F_104 ) ;
if ( ! V_146 )
F_119 ( V_26 , F_97 , F_100 ) ;
}
}
static void F_120 ( struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
F_31 ( & V_1 -> V_52 ) ;
}
static int F_121 ( struct V_36 * V_26 , int V_8 , T_1 * V_148 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_149 * V_150 ;
int V_139 ;
F_122 ( V_1 , V_8 , V_150 , & V_139 ) ;
if ( V_139 )
return V_139 ;
if ( F_109 ( V_148 ) || F_110 ( V_148 ) ) {
if ( V_8 == V_151 ) {
memcpy ( V_150 -> V_152 , V_148 , V_153 ) ;
return 0 ;
} else {
F_123 ( V_8 , V_139 , V_1 ,
V_154 , V_148 ) ;
return F_124 ( V_139 ) ;
}
} else
return - V_155 ;
}
static int F_125 ( struct V_36 * V_26 , int V_8 ,
struct V_156 * V_157 [] )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_149 V_158 ;
struct V_149 * V_150 ;
int V_139 = 0 , V_159 = 1 ;
F_122 ( V_1 , V_8 , V_150 , & V_139 ) ;
if ( V_139 )
return V_139 ;
if ( ! V_157 [ V_160 ] )
return - V_161 ;
memcpy ( & V_158 , V_150 , sizeof( * V_1 -> V_150 ) ) ;
memset ( V_150 , 0 , sizeof( * V_1 -> V_150 ) ) ;
V_150 -> V_162 |= V_163 ;
V_150 -> V_164 = F_126 ( V_157 [ V_160 ] ) ;
if ( V_157 [ V_165 ] ) {
V_150 -> V_162 |= V_166 ;
memcpy ( V_150 -> V_167 , F_127 ( V_157 [ V_165 ] ) ,
V_168 ) ;
}
if ( V_157 [ V_169 ] ) {
V_150 -> V_162 |= V_170 ;
memcpy ( V_150 -> V_171 ,
F_127 ( V_157 [ V_169 ] ) , V_172 ) ;
}
if ( V_157 [ V_173 ] ) {
V_150 -> V_162 |= V_174 ;
memcpy ( V_150 -> V_175 ,
F_127 ( V_157 [ V_173 ] ) , V_172 ) ;
}
if ( V_8 == V_151 ) {
if ( ! F_110 ( V_158 . V_152 ) )
memcpy ( V_150 -> V_176 , V_158 . V_152 , V_153 ) ;
if ( F_110 ( V_26 -> V_134 ) )
F_128 ( V_26 ) ;
} else {
F_123 ( V_8 , V_139 , V_1 ,
V_177 , V_150 -> V_176 ) ;
if ( V_139 ) {
F_22 ( V_26 , L_11 , V_8 ) ;
memcpy ( V_150 , & V_158 , sizeof( * V_150 ) ) ;
return F_124 ( V_139 ) ;
}
}
V_139 = F_129 ( V_1 , V_8 , & V_158 , & V_159 ) ;
if ( V_139 ) {
if ( V_159 ) {
memcpy ( V_150 , & V_158 , sizeof( * V_150 ) ) ;
} else {
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
if ( V_8 == V_151 )
memset ( V_26 -> V_134 , 0 , V_153 ) ;
}
} else {
V_150 -> V_162 |= V_178 ;
if ( V_150 -> V_164 == V_179 ) {
memset ( V_150 -> V_176 , 0 , V_153 ) ;
if ( V_8 == V_151 )
memset ( V_26 -> V_134 , 0 , V_153 ) ;
}
}
if ( V_8 == V_151 )
memset ( V_150 -> V_152 , 0 , V_153 ) ;
return V_139 ;
}
static int F_130 ( struct V_36 * V_26 , int V_8 ,
struct V_62 * V_63 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
T_2 V_180 = V_181 ;
struct V_149 * V_150 ;
int V_139 ;
F_122 ( V_1 , V_8 , V_150 , & V_139 ) ;
if ( V_139 )
return V_139 ;
if ( ! ( V_150 -> V_162 & V_178 ) )
return - V_182 ;
V_139 = F_131 ( V_1 , V_8 , V_150 -> V_164 , & V_180 ) ;
if ( V_139 )
return V_139 ;
if ( F_132 ( V_63 , V_160 , V_150 -> V_164 ) ||
F_132 ( V_63 , V_183 , V_180 ) ||
( ( V_150 -> V_162 & V_166 ) &&
F_133 ( V_63 , V_165 , V_168 , V_150 -> V_167 ) ) ||
( ( V_150 -> V_162 & V_170 ) &&
F_133 ( V_63 , V_169 , V_172 ,
V_150 -> V_171 ) ) ||
( ( V_150 -> V_162 & V_174 ) &&
F_133 ( V_63 , V_173 , V_172 , V_150 -> V_175 ) ) )
goto V_184;
return 0 ;
V_184:
return - V_185 ;
}
static void F_134 ( struct V_186 * V_33 , struct V_187 * V_13 )
{
struct V_1 * V_1 = F_7 ( V_33 -> V_14 ) ;
if ( ! V_13 -> V_19 )
return;
F_8 ( V_1 -> V_2 , V_13 -> V_16 ,
V_13 -> V_17 , V_188 ) ;
F_10 ( V_13 -> V_19 ) ;
}
static int F_135 ( struct V_186 * V_33 )
{
struct V_1 * V_1 = F_7 ( V_33 -> V_14 ) ;
struct V_36 * V_26 = V_1 -> V_26 ;
struct V_62 * V_63 ;
unsigned int V_17 = V_26 -> V_35 + V_189 ;
unsigned int V_190 = 0 ;
T_6 V_16 ;
V_63 = F_136 ( V_26 , V_17 ) ;
if ( ! V_63 )
return - V_191 ;
V_16 = F_71 ( V_1 -> V_2 , V_63 -> V_44 ,
V_17 , V_188 ) ;
F_137 ( V_33 , V_63 , V_190 ,
V_16 , V_17 ) ;
return 0 ;
}
static void F_138 ( struct V_192 * V_193 ,
T_3 V_194 )
{
if ( V_195 <= V_194 )
V_193 -> V_196 += V_194 ;
else
V_193 -> V_197 += V_194 ;
}
static void F_139 ( struct V_186 * V_33 ,
struct V_20 * V_20 , struct V_187 * V_13 ,
int V_198 , void * V_21 )
{
struct V_1 * V_1 = F_7 ( V_33 -> V_14 ) ;
struct V_36 * V_26 = V_1 -> V_26 ;
struct V_62 * V_63 ;
struct V_199 * V_56 = & V_1 -> V_56 [ F_140 ( V_1 , V_33 -> V_200 ) ] ;
T_1 type , V_201 , V_73 , V_15 , V_202 , V_203 ;
T_1 V_204 , V_205 , V_206 , V_207 , V_208 ;
T_1 V_209 , V_210 , V_211 , V_212 ;
T_1 V_213 , V_214 , V_215 , V_216 , V_217 , V_218 ;
T_1 V_219 ;
T_2 V_23 , V_24 , V_220 , V_221 , V_222 ;
T_3 V_223 ;
if ( V_198 )
return;
V_63 = V_13 -> V_19 ;
F_141 ( V_63 -> V_44 - V_224 ) ;
F_8 ( V_1 -> V_2 , V_13 -> V_16 ,
V_13 -> V_17 , V_188 ) ;
F_142 ( (struct V_225 * ) V_20 ,
& type , & V_201 , & V_23 , & V_24 ,
& V_202 , & V_204 , & V_73 , & V_15 , & V_217 ,
& V_218 , & V_223 , & V_220 ,
& V_219 , & V_203 , & V_221 , & V_222 ,
& V_205 , & V_206 , & V_207 ,
& V_208 , & V_209 , & V_210 , & V_211 ,
& V_212 , & V_213 , & V_214 , & V_215 ,
& V_216 ) ;
if ( V_219 ) {
if ( ! V_216 ) {
if ( V_220 > 0 )
V_1 -> V_121 ++ ;
else if ( V_220 == 0 )
V_1 -> V_119 ++ ;
}
F_10 ( V_63 ) ;
return;
}
if ( V_73 && V_220 > 0 ) {
F_143 ( V_63 , V_220 ) ;
V_63 -> V_79 = F_144 ( V_63 , V_26 ) ;
F_145 ( V_63 , V_23 ) ;
if ( V_26 -> V_226 & V_227 ) {
F_146 ( V_63 , V_223 ,
( V_217 &
( V_228 |
V_229 |
V_230 ) ) ?
V_231 : V_232 ) ;
}
if ( ( V_26 -> V_226 & V_233 ) && ! V_218 ) {
V_63 -> V_234 = F_147 ( V_222 ) ;
V_63 -> V_90 = V_235 ;
}
if ( V_203 )
F_148 ( V_63 , F_147 ( V_236 ) , V_221 ) ;
if ( V_26 -> V_226 & V_237 )
F_149 ( & V_1 -> V_54 [ V_23 ] , V_63 ) ;
else
F_150 ( V_63 ) ;
if ( V_1 -> V_238 . V_239 )
F_138 ( & V_56 -> V_240 ,
V_220 ) ;
} else {
F_10 ( V_63 ) ;
}
}
static int F_151 ( struct V_22 * V_14 , struct V_20 * V_20 ,
T_1 type , T_2 V_23 , T_2 V_24 , void * V_21 )
{
struct V_1 * V_1 = F_7 ( V_14 ) ;
F_152 ( & V_1 -> V_33 [ V_23 ] , V_20 ,
V_24 , V_241 ,
F_139 , V_21 ) ;
return 0 ;
}
static int F_153 ( struct V_55 * V_54 , int V_242 )
{
struct V_36 * V_26 = V_54 -> V_68 ;
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_243 = F_140 ( V_1 , 0 ) ;
unsigned int V_244 = F_56 ( V_1 , 0 ) ;
unsigned int V_49 = F_41 () ;
unsigned int V_245 = V_242 ;
unsigned int V_57 = - 1 ;
unsigned int V_246 , V_247 = 0 , V_58 ;
int V_139 ;
if ( V_242 > 0 )
V_247 = F_57 ( & V_1 -> V_56 [ V_243 ] ,
V_245 , F_151 , NULL ) ;
V_58 = F_57 ( & V_1 -> V_56 [ V_244 ] ,
V_57 , F_12 , NULL ) ;
V_246 = V_247 + V_58 ;
if ( V_246 > 0 )
F_58 ( & V_1 -> V_49 [ V_49 ] ,
V_246 ,
0 ,
0 ) ;
V_139 = F_154 ( & V_1 -> V_33 [ 0 ] , F_135 ) ;
if ( V_139 )
V_247 = V_245 ;
if ( V_247 < V_245 ) {
F_155 ( V_54 ) ;
F_46 ( & V_1 -> V_49 [ V_49 ] ) ;
}
return V_247 ;
}
static void F_156 ( struct V_1 * V_1 , struct V_186 * V_33 )
{
unsigned int V_49 = F_157 ( V_1 , V_33 -> V_200 ) ;
struct V_199 * V_56 = & V_1 -> V_56 [ F_140 ( V_1 , V_33 -> V_200 ) ] ;
T_3 V_248 = V_56 -> V_249 ;
if ( V_56 -> V_249 != V_56 -> V_250 ) {
F_158 ( & V_1 -> V_49 [ V_49 ] , V_248 ) ;
V_56 -> V_250 = V_56 -> V_249 ;
}
}
static void F_159 ( struct V_1 * V_1 , struct V_186 * V_33 )
{
struct V_251 * V_252 = & V_1 -> V_238 ;
struct V_199 * V_56 = & V_1 -> V_56 [ F_140 ( V_1 , V_33 -> V_200 ) ] ;
struct V_192 * V_240 = & V_56 -> V_240 ;
int V_200 ;
T_3 V_248 ;
T_3 V_253 ;
T_3 V_254 ;
T_8 V_255 ;
T_9 V_256 = F_160 () ;
V_255 = F_161 ( V_256 , V_56 -> V_257 ) ;
if ( V_255 < V_258 )
return;
V_56 -> V_257 = V_256 ;
V_254 = V_240 -> V_196 +
V_240 -> V_197 ;
V_254 <<= 3 ;
V_254 = V_255 > V_259 ? 0 : V_254 / ( T_3 ) V_255 ;
for ( V_200 = 0 ; V_200 < V_260 ; V_200 ++ )
if ( V_254 < V_261 [ V_200 ] . V_262 )
break;
V_253 = ( V_240 -> V_197 >
V_240 -> V_196 << 1 ) ?
V_252 -> V_263 :
V_252 -> V_264 ;
V_248 = V_253 + ( ( V_252 -> V_265 - V_253 ) *
V_261 [ V_200 ] . V_266 / 100 ) ;
V_56 -> V_249 = ( V_248 + V_56 -> V_249 ) >> 1 ;
V_240 -> V_196 = 0 ;
V_240 -> V_197 = 0 ;
}
static int F_162 ( struct V_55 * V_54 , int V_242 )
{
struct V_36 * V_26 = V_54 -> V_68 ;
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_33 = ( V_54 - & V_1 -> V_54 [ 0 ] ) ;
unsigned int V_56 = F_140 ( V_1 , V_33 ) ;
unsigned int V_49 = F_157 ( V_1 , V_33 ) ;
unsigned int V_267 = V_242 ;
unsigned int V_246 = 0 ;
int V_139 ;
if ( V_242 > 0 )
V_246 = F_57 ( & V_1 -> V_56 [ V_56 ] ,
V_267 , F_151 , NULL ) ;
if ( V_246 > 0 )
F_58 ( & V_1 -> V_49 [ V_49 ] ,
V_246 ,
0 ,
0 ) ;
V_139 = F_154 ( & V_1 -> V_33 [ V_33 ] , F_135 ) ;
if ( V_139 )
V_246 = V_267 ;
if ( V_1 -> V_238 . V_239 )
F_159 ( V_1 , & V_1 -> V_33 [ V_33 ] ) ;
if ( V_246 < V_267 ) {
F_155 ( V_54 ) ;
if ( V_1 -> V_238 . V_239 )
F_156 ( V_1 , & V_1 -> V_33 [ V_33 ] ) ;
F_46 ( & V_1 -> V_49 [ V_49 ] ) ;
}
return V_246 ;
}
static void F_163 ( unsigned long V_44 )
{
struct V_1 * V_1 = (struct V_1 * ) V_44 ;
F_38 ( V_1 ) ;
F_164 ( & V_1 -> V_268 ,
F_165 ( V_269 + V_270 ) ) ;
}
static void F_166 ( struct V_1 * V_1 )
{
struct V_36 * V_26 = V_1 -> V_26 ;
unsigned int V_29 ;
switch ( F_167 ( V_1 -> V_14 ) ) {
case V_271 :
F_168 ( V_1 -> V_2 -> V_43 , V_26 ) ;
break;
case V_272 :
F_168 ( V_1 -> V_2 -> V_43 , V_1 ) ;
break;
case V_273 :
for ( V_29 = 0 ; V_29 < F_169 ( V_1 -> V_274 ) ; V_29 ++ )
if ( V_1 -> V_274 [ V_29 ] . V_275 )
F_168 ( V_1 -> V_60 [ V_29 ] . V_61 ,
V_1 -> V_274 [ V_29 ] . V_276 ) ;
break;
default:
break;
}
}
static int F_170 ( struct V_1 * V_1 )
{
struct V_36 * V_26 = V_1 -> V_26 ;
unsigned int V_29 , V_49 ;
int V_139 = 0 ;
switch ( F_167 ( V_1 -> V_14 ) ) {
case V_271 :
V_139 = F_171 ( V_1 -> V_2 -> V_43 , F_39 ,
V_277 , V_26 -> V_167 , V_26 ) ;
break;
case V_272 :
V_139 = F_171 ( V_1 -> V_2 -> V_43 , F_51 ,
0 , V_26 -> V_167 , V_1 ) ;
break;
case V_273 :
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
V_49 = F_157 ( V_1 , V_29 ) ;
snprintf ( V_1 -> V_274 [ V_49 ] . V_278 ,
sizeof( V_1 -> V_274 [ V_49 ] . V_278 ) ,
L_12 , V_26 -> V_167 , V_29 ) ;
V_1 -> V_274 [ V_49 ] . V_279 = F_53 ;
V_1 -> V_274 [ V_49 ] . V_276 = & V_1 -> V_54 [ V_29 ] ;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ ) {
V_49 = F_55 ( V_1 , V_29 ) ;
snprintf ( V_1 -> V_274 [ V_49 ] . V_278 ,
sizeof( V_1 -> V_274 [ V_49 ] . V_278 ) ,
L_13 , V_26 -> V_167 , V_29 ) ;
V_1 -> V_274 [ V_49 ] . V_279 = F_54 ;
V_1 -> V_274 [ V_49 ] . V_276 = V_1 ;
}
V_49 = F_60 ( V_1 ) ;
snprintf ( V_1 -> V_274 [ V_49 ] . V_278 ,
sizeof( V_1 -> V_274 [ V_49 ] . V_278 ) ,
L_14 , V_26 -> V_167 ) ;
V_1 -> V_274 [ V_49 ] . V_279 = F_59 ;
V_1 -> V_274 [ V_49 ] . V_276 = V_1 ;
V_49 = F_62 ( V_1 ) ;
snprintf ( V_1 -> V_274 [ V_49 ] . V_278 ,
sizeof( V_1 -> V_274 [ V_49 ] . V_278 ) ,
L_15 , V_26 -> V_167 ) ;
V_1 -> V_274 [ V_49 ] . V_279 = F_61 ;
V_1 -> V_274 [ V_49 ] . V_276 = V_1 ;
for ( V_29 = 0 ; V_29 < F_169 ( V_1 -> V_274 ) ; V_29 ++ )
V_1 -> V_274 [ V_29 ] . V_275 = 0 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_280 ; V_29 ++ ) {
V_139 = F_171 ( V_1 -> V_60 [ V_29 ] . V_61 ,
V_1 -> V_274 [ V_29 ] . V_279 , 0 ,
V_1 -> V_274 [ V_29 ] . V_278 ,
V_1 -> V_274 [ V_29 ] . V_276 ) ;
if ( V_139 ) {
F_166 ( V_1 ) ;
break;
}
V_1 -> V_274 [ V_29 ] . V_275 = 1 ;
}
break;
default:
break;
}
return V_139 ;
}
static void F_172 ( struct V_1 * V_1 )
{
unsigned int V_29 ;
switch ( F_167 ( V_1 -> V_14 ) ) {
case V_271 :
case V_272 :
F_173 ( V_1 -> V_2 -> V_43 ) ;
break;
case V_273 :
for ( V_29 = 0 ; V_29 < V_1 -> V_280 ; V_29 ++ )
F_173 ( V_1 -> V_60 [ V_29 ] . V_61 ) ;
break;
default:
break;
}
}
static void F_174 ( struct V_1 * V_1 )
{
unsigned int V_281 ;
int V_200 = - 1 ;
struct V_251 * V_252 = & V_1 -> V_238 ;
if ( V_273 != F_167 ( V_1 -> V_14 ) ) {
F_26 ( V_1 -> V_26 , L_16 ) ;
return;
}
V_281 = F_175 ( V_1 -> V_14 ) ;
if ( V_282 < V_281 )
V_200 = V_283 ;
else if ( V_284 < V_281 )
V_200 = V_285 ;
else
V_200 = V_286 ;
V_252 -> V_263 = V_287 [ V_200 ] . V_263 ;
V_252 -> V_264 = V_287 [ V_200 ] . V_264 ;
V_252 -> V_265 = V_288 ;
for ( V_200 = 0 ; V_200 < V_1 -> V_32 ; V_200 ++ )
V_1 -> V_56 [ V_200 ] . V_250 =
V_1 -> V_289 . V_290 ;
V_252 -> V_239 = 1 ;
}
static int F_176 ( struct V_1 * V_1 )
{
int V_139 ;
F_13 ( & V_1 -> V_291 ) ;
switch ( F_167 ( V_1 -> V_14 ) ) {
case V_271 :
V_139 = F_177 ( V_1 -> V_14 ,
F_43 () ) ;
break;
case V_273 :
V_139 = F_177 ( V_1 -> V_14 ,
F_62 ( V_1 ) ) ;
break;
default:
V_139 = F_177 ( V_1 -> V_14 , - 1 ) ;
break;
}
F_19 ( & V_1 -> V_291 ) ;
return V_139 ;
}
static void F_178 ( struct V_1 * V_1 )
{
switch ( F_167 ( V_1 -> V_14 ) ) {
case V_272 :
F_164 ( & V_1 -> V_268 , V_269 ) ;
break;
default:
break;
}
}
static int F_179 ( struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_29 ;
int V_139 ;
V_139 = F_170 ( V_1 ) ;
if ( V_139 ) {
F_22 ( V_26 , L_17 ) ;
return V_139 ;
}
V_139 = F_176 ( V_1 ) ;
if ( V_139 ) {
F_22 ( V_26 ,
L_18 ) ;
goto V_292;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
F_154 ( & V_1 -> V_33 [ V_29 ] , F_135 ) ;
if ( F_180 ( & V_1 -> V_33 [ V_29 ] ) == 0 ) {
F_22 ( V_26 , L_19 ) ;
V_139 = - V_191 ;
goto V_293;
}
}
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ )
F_181 ( & V_1 -> V_11 [ V_29 ] ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_182 ( & V_1 -> V_33 [ V_29 ] ) ;
if ( ! F_1 ( V_1 ) && ! F_3 ( V_1 ) )
F_114 ( V_1 ) ;
F_116 ( V_26 ) ;
F_183 ( V_26 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_184 ( & V_1 -> V_54 [ V_29 ] ) ;
F_185 ( V_1 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_280 ; V_29 ++ )
F_46 ( & V_1 -> V_49 [ V_29 ] ) ;
F_178 ( V_1 ) ;
return 0 ;
V_293:
F_186 ( V_1 ) ;
V_292:
F_166 ( V_1 ) ;
return V_139 ;
}
static int F_187 ( struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_29 ;
int V_139 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_280 ; V_29 ++ ) {
F_44 ( & V_1 -> V_49 [ V_29 ] ) ;
( void ) F_188 ( & V_1 -> V_49 [ V_29 ] ) ;
}
F_172 ( V_1 ) ;
F_189 ( & V_1 -> V_268 ) ;
F_190 ( V_1 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_191 ( & V_1 -> V_54 [ V_29 ] ) ;
F_37 ( V_26 ) ;
F_192 ( V_26 ) ;
if ( ! F_1 ( V_1 ) && ! F_3 ( V_1 ) )
F_113 ( V_1 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ ) {
V_139 = F_193 ( & V_1 -> V_11 [ V_29 ] ) ;
if ( V_139 )
return V_139 ;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
V_139 = F_194 ( & V_1 -> V_33 [ V_29 ] ) ;
if ( V_139 )
return V_139 ;
}
F_186 ( V_1 ) ;
F_166 ( V_1 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ )
F_195 ( & V_1 -> V_11 [ V_29 ] , F_6 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_196 ( & V_1 -> V_33 [ V_29 ] , F_134 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_294 ; V_29 ++ )
F_197 ( & V_1 -> V_56 [ V_29 ] ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_280 ; V_29 ++ )
F_198 ( & V_1 -> V_49 [ V_29 ] ) ;
return 0 ;
}
static int F_199 ( struct V_36 * V_26 , int V_295 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
int V_296 = F_112 ( V_26 ) ;
if ( V_295 < V_38 || V_295 > V_39 )
return - V_155 ;
if ( F_1 ( V_1 ) || F_3 ( V_1 ) )
return - V_161 ;
if ( V_296 )
F_187 ( V_26 ) ;
V_26 -> V_35 = V_295 ;
if ( V_26 -> V_35 > V_1 -> V_37 )
F_32 ( V_26 ,
L_20 ,
V_26 -> V_35 , V_1 -> V_37 ) ;
if ( V_296 )
F_179 ( V_26 ) ;
return 0 ;
}
static void F_200 ( struct V_297 * V_298 )
{
struct V_1 * V_1 = F_201 ( V_298 , struct V_1 , V_40 ) ;
struct V_36 * V_26 = V_1 -> V_26 ;
int V_295 = F_28 ( V_1 -> V_14 ) ;
int V_139 ;
unsigned int V_29 ;
V_295 = F_29 ( int , V_38 , F_30 ( int , V_39 , V_295 ) ) ;
F_202 () ;
F_189 ( & V_1 -> V_268 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_191 ( & V_1 -> V_54 [ V_29 ] ) ;
F_44 ( & V_1 -> V_49 [ 0 ] ) ;
F_172 ( V_1 ) ;
V_139 = F_194 ( & V_1 -> V_33 [ 0 ] ) ;
if ( V_139 ) {
F_203 () ;
F_22 ( V_26 , L_21 ) ;
return;
}
F_196 ( & V_1 -> V_33 [ 0 ] , F_134 ) ;
F_197 ( & V_1 -> V_56 [ 0 ] ) ;
F_198 ( & V_1 -> V_49 [ 0 ] ) ;
V_26 -> V_35 = V_295 ;
F_154 ( & V_1 -> V_33 [ 0 ] , F_135 ) ;
if ( F_180 ( & V_1 -> V_33 [ 0 ] ) == 0 ) {
F_203 () ;
F_22 ( V_26 , L_22 ) ;
return;
}
F_182 ( & V_1 -> V_33 [ 0 ] ) ;
F_184 ( & V_1 -> V_54 [ 0 ] ) ;
F_46 ( & V_1 -> V_49 [ 0 ] ) ;
F_178 ( V_1 ) ;
F_203 () ;
F_26 ( V_26 , L_23 , V_26 -> V_35 ) ;
}
static void F_204 ( struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_22 * V_14 = V_1 -> V_14 ;
unsigned int V_29 , V_49 ;
switch ( F_167 ( V_14 ) ) {
case V_273 :
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
V_49 = F_157 ( V_1 , V_29 ) ;
F_53 ( V_1 -> V_60 [ V_49 ] . V_61 ,
& V_1 -> V_54 [ V_29 ] ) ;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ ) {
V_49 = F_55 ( V_1 , V_29 ) ;
F_54 ( V_1 -> V_60 [ V_49 ] . V_61 , V_1 ) ;
}
break;
case V_272 :
F_51 ( V_1 -> V_2 -> V_43 , V_1 ) ;
break;
case V_271 :
F_39 ( V_1 -> V_2 -> V_43 , V_26 ) ;
break;
default:
break;
}
}
static int F_205 ( struct V_22 * V_14 ,
int (* F_206)( struct V_22 * , int ) ,
int (* F_207)( struct V_22 * , int * ) ,
int V_299 )
{
unsigned long time ;
int V_300 ;
int V_139 ;
F_208 ( F_209 () ) ;
V_139 = F_206 ( V_14 , V_299 ) ;
if ( V_139 )
return V_139 ;
time = V_269 + ( V_301 * 2 ) ;
do {
V_139 = F_207 ( V_14 , & V_300 ) ;
if ( V_139 )
return V_139 ;
if ( V_300 )
return 0 ;
F_210 ( V_301 / 10 ) ;
} while ( F_211 ( time , V_269 ) );
return - V_302 ;
}
static int F_212 ( struct V_1 * V_1 )
{
int V_139 ;
V_139 = F_205 ( V_1 -> V_14 , V_303 ,
V_304 , 0 ) ;
if ( V_139 )
F_213 ( F_214 ( V_1 ) , L_24 ,
V_139 ) ;
return V_139 ;
}
static int F_215 ( struct V_1 * V_1 )
{
int V_139 ;
V_139 = F_205 ( V_1 -> V_14 , V_305 ,
V_306 , 0 ) ;
if ( V_139 )
F_22 ( V_1 -> V_26 , L_25 ,
V_139 ) ;
return V_139 ;
}
static int F_216 ( struct V_1 * V_1 )
{
T_6 V_307 ;
union V_308 * V_309 = NULL ;
union V_308 V_310 = {
. V_311 [ 0 ] . V_312 = { 85 , 67 , 83 , 97 , 119 , 101 , 115 , 111 , 109 , 101 } ,
. V_311 [ 1 ] . V_312 = { 80 , 65 , 76 , 79 , 117 , 110 , 105 , 113 , 117 , 101 } ,
. V_311 [ 2 ] . V_312 = { 76 , 73 , 78 , 85 , 88 , 114 , 111 , 99 , 107 , 115 } ,
. V_311 [ 3 ] . V_312 = { 69 , 78 , 73 , 67 , 105 , 115 , 99 , 111 , 111 , 108 } ,
} ;
int V_139 ;
V_309 = F_217 ( V_1 -> V_2 ,
sizeof( union V_308 ) , & V_307 ) ;
if ( ! V_309 )
return - V_191 ;
memcpy ( V_309 , & V_310 , sizeof( union V_308 ) ) ;
F_13 ( & V_1 -> V_291 ) ;
V_139 = F_218 ( V_1 ,
V_307 ,
sizeof( union V_308 ) ) ;
F_19 ( & V_1 -> V_291 ) ;
F_219 ( V_1 -> V_2 , sizeof( union V_308 ) ,
V_309 , V_307 ) ;
return V_139 ;
}
static int F_220 ( struct V_1 * V_1 , T_1 V_313 )
{
T_6 V_314 ;
union V_315 * V_316 = NULL ;
unsigned int V_29 ;
int V_139 ;
V_316 = F_217 ( V_1 -> V_2 ,
sizeof( union V_315 ) , & V_314 ) ;
if ( ! V_316 )
return - V_191 ;
for ( V_29 = 0 ; V_29 < ( 1 << V_313 ) ; V_29 ++ )
( * V_316 ) . V_317 [ V_29 / 4 ] . V_312 [ V_29 % 4 ] = V_29 % V_1 -> V_32 ;
F_13 ( & V_1 -> V_291 ) ;
V_139 = F_221 ( V_1 ,
V_314 ,
sizeof( union V_315 ) ) ;
F_19 ( & V_1 -> V_291 ) ;
F_219 ( V_1 -> V_2 , sizeof( union V_315 ) ,
V_316 , V_314 ) ;
return V_139 ;
}
static int F_222 ( struct V_1 * V_1 , T_1 V_318 ,
T_1 V_319 , T_1 V_313 , T_1 V_320 , T_1 V_321 )
{
const T_1 V_322 = 0 ;
const T_1 V_323 = 1 ;
int V_139 ;
F_13 ( & V_1 -> V_291 ) ;
V_139 = F_223 ( V_1 ,
V_318 , V_319 ,
V_313 , V_320 ,
V_321 , V_322 ,
V_323 ) ;
F_19 ( & V_1 -> V_291 ) ;
return V_139 ;
}
static int F_224 ( struct V_1 * V_1 )
{
struct V_3 * V_68 = F_214 ( V_1 ) ;
const T_1 V_318 = 0 ;
const T_1 V_319 = V_324 |
V_230 |
V_325 |
V_229 ;
const T_1 V_313 = 7 ;
const T_1 V_320 = 0 ;
T_1 V_321 = F_225 ( V_1 , V_326 ) && ( V_1 -> V_32 > 1 ) ;
if ( V_321 ) {
if ( ! F_216 ( V_1 ) ) {
if ( F_220 ( V_1 , V_313 ) ) {
V_321 = 0 ;
F_226 ( V_68 , L_26
L_27 ) ;
}
} else {
V_321 = 0 ;
F_226 ( V_68 , L_28 ) ;
}
}
return F_222 ( V_1 , V_318 , V_319 ,
V_313 , V_320 , V_321 ) ;
}
static void F_227 ( struct V_297 * V_298 )
{
struct V_1 * V_1 = F_201 ( V_298 , struct V_1 , V_52 ) ;
if ( ! F_112 ( V_1 -> V_26 ) )
return;
F_202 () ;
F_13 ( & V_1 -> V_327 ) ;
F_228 ( V_1 ) ;
F_187 ( V_1 -> V_26 ) ;
F_215 ( V_1 ) ;
F_105 ( V_1 ) ;
F_229 ( V_1 ) ;
F_224 ( V_1 ) ;
F_230 ( V_1 ) ;
F_179 ( V_1 -> V_26 ) ;
F_19 ( & V_1 -> V_327 ) ;
F_231 ( V_328 , V_1 -> V_26 ) ;
F_203 () ;
}
static int F_232 ( struct V_1 * V_1 )
{
unsigned int V_329 = F_30 (unsigned int, enic->rq_count, ENIC_RQ_MAX) ;
unsigned int V_330 = F_30 (unsigned int, enic->wq_count, ENIC_WQ_MAX) ;
unsigned int V_29 ;
F_208 ( F_169 ( V_1 -> V_60 ) < V_329 + V_330 + 2 ) ;
for ( V_29 = 0 ; V_29 < V_329 + V_330 + 2 ; V_29 ++ )
V_1 -> V_60 [ V_29 ] . V_331 = V_29 ;
if ( F_225 ( V_1 , V_326 ) &&
V_1 -> V_289 . V_332 < 1 &&
V_1 -> V_32 >= V_329 &&
V_1 -> V_31 >= V_330 &&
V_1 -> V_294 >= V_329 + V_330 &&
V_1 -> V_280 >= V_329 + V_330 + 2 ) {
if ( F_233 ( V_1 -> V_2 , V_1 -> V_60 ,
V_329 + V_330 + 2 , V_329 + V_330 + 2 ) > 0 ) {
V_1 -> V_32 = V_329 ;
V_1 -> V_31 = V_330 ;
V_1 -> V_294 = V_329 + V_330 ;
V_1 -> V_280 = V_329 + V_330 + 2 ;
F_234 ( V_1 -> V_14 ,
V_273 ) ;
return 0 ;
}
}
if ( V_1 -> V_289 . V_332 < 1 &&
V_1 -> V_32 >= 1 &&
V_1 -> V_31 >= V_330 &&
V_1 -> V_294 >= 1 + V_330 &&
V_1 -> V_280 >= 1 + V_330 + 2 ) {
if ( F_233 ( V_1 -> V_2 , V_1 -> V_60 ,
1 + V_330 + 2 , 1 + V_330 + 2 ) > 0 ) {
V_1 -> V_32 = 1 ;
V_1 -> V_31 = V_330 ;
V_1 -> V_294 = 1 + V_330 ;
V_1 -> V_280 = 1 + V_330 + 2 ;
F_234 ( V_1 -> V_14 ,
V_273 ) ;
return 0 ;
}
}
if ( V_1 -> V_289 . V_332 < 2 &&
V_1 -> V_32 >= 1 &&
V_1 -> V_31 >= 1 &&
V_1 -> V_294 >= 2 &&
V_1 -> V_280 >= 1 &&
! F_235 ( V_1 -> V_2 ) ) {
V_1 -> V_32 = 1 ;
V_1 -> V_31 = 1 ;
V_1 -> V_294 = 2 ;
V_1 -> V_280 = 1 ;
F_234 ( V_1 -> V_14 , V_272 ) ;
return 0 ;
}
if ( V_1 -> V_289 . V_332 < 3 &&
V_1 -> V_32 >= 1 &&
V_1 -> V_31 >= 1 &&
V_1 -> V_294 >= 2 &&
V_1 -> V_280 >= 3 ) {
V_1 -> V_32 = 1 ;
V_1 -> V_31 = 1 ;
V_1 -> V_294 = 2 ;
V_1 -> V_280 = 3 ;
F_234 ( V_1 -> V_14 , V_271 ) ;
return 0 ;
}
F_234 ( V_1 -> V_14 , V_333 ) ;
return - V_155 ;
}
static void F_236 ( struct V_1 * V_1 )
{
switch ( F_167 ( V_1 -> V_14 ) ) {
case V_273 :
F_237 ( V_1 -> V_2 ) ;
break;
case V_272 :
F_238 ( V_1 -> V_2 ) ;
break;
default:
break;
}
F_234 ( V_1 -> V_14 , V_333 ) ;
}
static void F_239 ( struct V_1 * V_1 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_240 ( & V_1 -> V_54 [ V_29 ] ) ;
F_241 ( V_1 ) ;
F_236 ( V_1 ) ;
}
static int F_242 ( struct V_1 * V_1 )
{
struct V_3 * V_68 = F_214 ( V_1 ) ;
struct V_36 * V_26 = V_1 -> V_26 ;
unsigned int V_29 ;
int V_139 ;
V_139 = F_243 ( V_1 ) ;
if ( V_139 ) {
F_226 ( V_68 , L_29
L_30 ) ;
F_244 ( V_1 -> V_14 ) ;
}
V_139 = F_245 ( V_1 ) ;
if ( V_139 ) {
F_213 ( V_68 , L_31 ) ;
return V_139 ;
}
F_246 ( V_1 ) ;
V_139 = F_232 ( V_1 ) ;
if ( V_139 ) {
F_213 ( V_68 , L_32
L_33 ) ;
return V_139 ;
}
V_139 = F_247 ( V_1 ) ;
if ( V_139 ) {
F_213 ( V_68 , L_34 ) ;
goto V_334;
}
F_229 ( V_1 ) ;
V_139 = F_224 ( V_1 ) ;
if ( V_139 ) {
F_213 ( V_68 , L_35 ) ;
goto V_334;
}
switch ( F_167 ( V_1 -> V_14 ) ) {
default:
F_248 ( V_26 , & V_1 -> V_54 [ 0 ] , F_153 , 64 ) ;
break;
case V_273 :
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_248 ( V_26 , & V_1 -> V_54 [ V_29 ] ,
F_162 , 64 ) ;
break;
}
return 0 ;
V_334:
F_236 ( V_1 ) ;
F_241 ( V_1 ) ;
return V_139 ;
}
static void F_249 ( struct V_1 * V_1 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < F_169 ( V_1 -> V_335 ) ; V_29 ++ )
if ( V_1 -> V_335 [ V_29 ] . V_336 )
F_250 ( V_1 -> V_335 [ V_29 ] . V_336 ) ;
}
static int F_251 ( struct V_337 * V_2 , const struct V_338 * V_339 )
{
struct V_3 * V_68 = & V_2 -> V_68 ;
struct V_36 * V_26 ;
struct V_1 * V_1 ;
int V_340 = 0 ;
unsigned int V_29 ;
int V_139 ;
#ifdef F_5
int V_341 = 0 ;
#endif
int V_342 = 1 ;
V_26 = F_252 ( sizeof( struct V_1 ) ,
V_343 , V_344 ) ;
if ( ! V_26 )
return - V_191 ;
F_253 ( V_2 , V_26 ) ;
F_254 ( V_26 , & V_2 -> V_68 ) ;
V_1 = F_40 ( V_26 ) ;
V_1 -> V_26 = V_26 ;
V_1 -> V_2 = V_2 ;
V_139 = F_255 ( V_2 ) ;
if ( V_139 ) {
F_213 ( V_68 , L_36 ) ;
goto V_345;
}
V_139 = F_256 ( V_2 , V_346 ) ;
if ( V_139 ) {
F_213 ( V_68 , L_37 ) ;
goto V_347;
}
F_257 ( V_2 ) ;
V_139 = F_258 ( V_2 , F_259 ( 64 ) ) ;
if ( V_139 ) {
V_139 = F_258 ( V_2 , F_259 ( 32 ) ) ;
if ( V_139 ) {
F_213 ( V_68 , L_38 ) ;
goto V_348;
}
V_139 = F_260 ( V_2 , F_259 ( 32 ) ) ;
if ( V_139 ) {
F_213 ( V_68 , L_39
L_40 , 32 ) ;
goto V_348;
}
} else {
V_139 = F_260 ( V_2 , F_259 ( 64 ) ) ;
if ( V_139 ) {
F_213 ( V_68 , L_39
L_40 , 64 ) ;
goto V_348;
}
V_340 = 1 ;
}
for ( V_29 = 0 ; V_29 < F_169 ( V_1 -> V_335 ) ; V_29 ++ ) {
if ( ! ( F_261 ( V_2 , V_29 ) & V_349 ) )
continue;
V_1 -> V_335 [ V_29 ] . V_17 = F_262 ( V_2 , V_29 ) ;
V_1 -> V_335 [ V_29 ] . V_336 = F_263 ( V_2 , V_29 , V_1 -> V_335 [ V_29 ] . V_17 ) ;
if ( ! V_1 -> V_335 [ V_29 ] . V_336 ) {
F_213 ( V_68 , L_41 , V_29 ) ;
V_139 = - V_350 ;
goto V_351;
}
V_1 -> V_335 [ V_29 ] . V_352 = F_264 ( V_2 , V_29 ) ;
}
V_1 -> V_14 = F_265 ( NULL , V_1 , V_2 , V_1 -> V_335 ,
F_169 ( V_1 -> V_335 ) ) ;
if ( ! V_1 -> V_14 ) {
F_213 ( V_68 , L_42 ) ;
V_139 = - V_350 ;
goto V_351;
}
#ifdef F_5
V_341 = F_266 ( V_2 , V_353 ) ;
if ( V_341 ) {
F_267 ( V_2 , V_341 + V_354 ,
& V_1 -> V_9 ) ;
if ( V_1 -> V_9 ) {
V_139 = F_268 ( V_2 , V_1 -> V_9 ) ;
if ( V_139 ) {
F_213 ( V_68 , L_43
L_44 ,
V_139 ) ;
goto V_355;
}
V_1 -> V_5 |= V_6 ;
V_342 = V_1 -> V_9 ;
}
}
#endif
V_1 -> V_150 = F_269 ( V_342 , sizeof( * V_1 -> V_150 ) , V_356 ) ;
if ( ! V_1 -> V_150 ) {
V_139 = - V_191 ;
goto V_357;
}
V_139 = F_212 ( V_1 ) ;
if ( V_139 ) {
F_213 ( V_68 , L_45 ) ;
goto V_358;
}
F_270 ( & V_1 -> V_291 ) ;
F_270 ( & V_1 -> V_327 ) ;
V_139 = F_230 ( V_1 ) ;
if ( V_139 ) {
F_213 ( V_68 ,
L_46 ) ;
goto V_359;
}
F_37 ( V_26 ) ;
if ( ! F_1 ( V_1 ) ) {
V_139 = F_271 ( V_1 -> V_14 , 0 ) ;
if ( V_139 ) {
F_213 ( V_68 , L_47 ) ;
goto V_359;
}
}
V_139 = F_242 ( V_1 ) ;
if ( V_139 ) {
F_213 ( V_68 , L_48 ) ;
goto V_359;
}
F_272 ( V_26 , V_1 -> V_31 ) ;
F_273 ( V_26 , V_1 -> V_32 ) ;
F_274 ( & V_1 -> V_268 ) ;
V_1 -> V_268 . V_360 = F_163 ;
V_1 -> V_268 . V_44 = ( unsigned long ) V_1 ;
F_174 ( V_1 ) ;
F_275 ( & V_1 -> V_52 , F_227 ) ;
F_275 ( & V_1 -> V_40 , F_200 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ )
F_270 ( & V_1 -> V_25 [ V_29 ] ) ;
V_1 -> V_37 = V_1 -> V_289 . V_35 ;
( void ) F_199 ( V_26 , V_1 -> V_37 ) ;
V_139 = F_108 ( V_26 , V_1 -> V_176 ) ;
if ( V_139 ) {
F_213 ( V_68 , L_49 ) ;
goto V_361;
}
V_1 -> V_362 = V_1 -> V_289 . V_290 ;
V_1 -> V_363 = V_1 -> V_362 ;
if ( F_1 ( V_1 ) || F_3 ( V_1 ) )
V_26 -> V_364 = & V_365 ;
else
V_26 -> V_364 = & V_366 ;
V_26 -> V_367 = 2 * V_301 ;
F_276 ( V_26 ) ;
V_26 -> V_226 |= V_368 | V_369 ;
if ( F_225 ( V_1 , V_370 ) ) {
V_26 -> V_226 &= ~ V_368 ;
V_1 -> V_88 = 1 ;
V_1 -> V_89 = V_1 -> V_289 . V_89 ;
F_277 ( V_68 , L_50 , V_1 -> V_89 ) ;
}
if ( F_225 ( V_1 , V_371 ) )
V_26 -> V_372 |= V_373 | V_374 ;
if ( F_225 ( V_1 , V_375 ) )
V_26 -> V_372 |= V_376 |
V_377 | V_378 ;
if ( F_225 ( V_1 , V_326 ) )
V_26 -> V_372 |= V_227 ;
if ( F_225 ( V_1 , V_379 ) )
V_26 -> V_372 |= V_233 ;
V_26 -> V_226 |= V_26 -> V_372 ;
if ( V_340 )
V_26 -> V_226 |= V_380 ;
V_26 -> V_5 |= V_381 ;
V_139 = F_278 ( V_26 ) ;
if ( V_139 ) {
F_213 ( V_68 , L_51 ) ;
goto V_361;
}
return 0 ;
V_361:
F_239 ( V_1 ) ;
V_359:
F_279 ( V_1 -> V_14 ) ;
V_358:
F_280 ( V_1 -> V_150 ) ;
V_357:
#ifdef F_5
if ( F_2 ( V_1 ) ) {
F_281 ( V_2 ) ;
V_1 -> V_5 &= ~ V_6 ;
}
V_355:
#endif
F_282 ( V_1 -> V_14 ) ;
V_351:
F_249 ( V_1 ) ;
V_348:
F_283 ( V_2 ) ;
V_347:
F_284 ( V_2 ) ;
V_345:
F_285 ( V_26 ) ;
return V_139 ;
}
static void F_286 ( struct V_337 * V_2 )
{
struct V_36 * V_26 = F_287 ( V_2 ) ;
if ( V_26 ) {
struct V_1 * V_1 = F_40 ( V_26 ) ;
F_288 ( & V_1 -> V_52 ) ;
F_288 ( & V_1 -> V_40 ) ;
F_289 ( V_26 ) ;
F_239 ( V_1 ) ;
F_279 ( V_1 -> V_14 ) ;
#ifdef F_5
if ( F_2 ( V_1 ) ) {
F_281 ( V_2 ) ;
V_1 -> V_5 &= ~ V_6 ;
}
#endif
F_280 ( V_1 -> V_150 ) ;
F_282 ( V_1 -> V_14 ) ;
F_249 ( V_1 ) ;
F_283 ( V_2 ) ;
F_284 ( V_2 ) ;
F_285 ( V_26 ) ;
}
}
static int T_10 F_290 ( void )
{
F_291 ( L_52 , V_382 , V_383 ) ;
return F_292 ( & V_384 ) ;
}
static void T_11 F_293 ( void )
{
F_294 ( & V_384 ) ;
}
