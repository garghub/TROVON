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
F_38 ( V_1 ) ;
F_48 ( & V_1 -> V_49 [ V_47 ] ) ;
}
if ( F_47 ( V_48 , V_46 ) ) {
F_48 ( & V_1 -> V_49 [ V_46 ] ) ;
F_20 ( V_1 ) ;
F_31 ( & V_1 -> V_52 ) ;
return V_53 ;
}
if ( F_47 ( V_48 , V_45 ) )
F_49 ( & V_1 -> V_54 [ 0 ] ) ;
else
F_46 ( & V_1 -> V_49 [ V_45 ] ) ;
return V_53 ;
}
static T_4 F_50 ( int V_43 , void * V_44 )
{
struct V_1 * V_1 = V_44 ;
F_49 ( & V_1 -> V_54 [ 0 ] ) ;
return V_53 ;
}
static T_4 F_51 ( int V_43 , void * V_44 )
{
struct V_55 * V_54 = V_44 ;
F_49 ( V_54 ) ;
return V_53 ;
}
static T_4 F_52 ( int V_43 , void * V_44 )
{
struct V_1 * V_1 = V_44 ;
unsigned int V_49 = F_53 ( V_1 ) ;
F_48 ( & V_1 -> V_49 [ V_49 ] ) ;
F_20 ( V_1 ) ;
F_31 ( & V_1 -> V_52 ) ;
return V_53 ;
}
static T_4 F_54 ( int V_43 , void * V_44 )
{
struct V_1 * V_1 = V_44 ;
unsigned int V_49 = F_55 ( V_1 ) ;
F_38 ( V_1 ) ;
F_48 ( & V_1 -> V_49 [ V_49 ] ) ;
return V_53 ;
}
static int F_56 ( struct V_1 * V_1 , struct V_10 * V_11 ,
struct V_56 * V_57 , unsigned int V_58 ,
int V_59 )
{
const T_5 * V_60 ;
T_6 V_16 ;
for ( V_60 = F_57 ( V_57 ) -> V_61 ; V_58 ; V_60 ++ ) {
V_58 -= F_58 ( V_60 ) ;
V_16 = F_59 ( & V_1 -> V_2 -> V_62 , V_60 , 0 ,
F_58 ( V_60 ) ,
V_63 ) ;
if ( F_60 ( F_61 ( V_1 , V_16 ) ) )
return - V_64 ;
F_62 ( V_11 , V_57 , V_16 , F_58 ( V_60 ) ,
( V_58 == 0 ) ,
V_59 ) ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_1 , struct V_10 * V_11 ,
struct V_56 * V_57 , int V_65 ,
unsigned int V_66 , int V_59 )
{
unsigned int V_67 = F_64 ( V_57 ) ;
unsigned int V_58 = V_57 -> V_17 - V_67 ;
int V_68 = ( V_58 == 0 ) ;
T_6 V_16 ;
int V_69 = 0 ;
V_16 = F_65 ( V_1 -> V_2 , V_57 -> V_44 , V_67 ,
V_18 ) ;
if ( F_60 ( F_61 ( V_1 , V_16 ) ) )
return - V_64 ;
F_66 ( V_11 , V_57 , V_16 , V_67 , V_65 ,
V_66 , V_68 , V_59 ) ;
if ( ! V_68 )
V_69 = F_56 ( V_1 , V_11 , V_57 , V_58 , V_59 ) ;
return V_69 ;
}
static int F_67 ( struct V_1 * V_1 , struct V_10 * V_11 ,
struct V_56 * V_57 , int V_65 ,
unsigned int V_66 , int V_59 )
{
unsigned int V_67 = F_64 ( V_57 ) ;
unsigned int V_58 = V_57 -> V_17 - V_67 ;
unsigned int V_70 = F_68 ( V_57 ) ;
unsigned int V_71 = V_70 + V_57 -> V_71 ;
int V_68 = ( V_58 == 0 ) ;
T_6 V_16 ;
int V_69 = 0 ;
V_16 = F_65 ( V_1 -> V_2 , V_57 -> V_44 , V_67 ,
V_18 ) ;
if ( F_60 ( F_61 ( V_1 , V_16 ) ) )
return - V_64 ;
F_69 ( V_11 , V_57 , V_16 , V_67 , V_71 ,
V_70 , V_65 , V_66 , V_68 ,
V_59 ) ;
if ( ! V_68 )
V_69 = F_56 ( V_1 , V_11 , V_57 , V_58 , V_59 ) ;
return V_69 ;
}
static int F_70 ( struct V_1 * V_1 , struct V_10 * V_11 ,
struct V_56 * V_57 , unsigned int V_72 ,
int V_65 , unsigned int V_66 ,
int V_59 )
{
unsigned int V_73 = F_64 ( V_57 ) ;
unsigned int V_58 = V_57 -> V_17 - V_73 ;
unsigned int V_70 = F_71 ( V_57 ) + F_72 ( V_57 ) ;
int V_68 = ( V_58 == 0 ) ;
unsigned int V_17 ;
T_6 V_16 ;
unsigned int V_74 = 0 ;
T_5 * V_60 ;
if ( V_57 -> V_75 == F_73 ( V_76 ) ) {
F_74 ( V_57 ) -> V_77 = 0 ;
F_75 ( V_57 ) -> V_77 = ~ F_76 ( F_74 ( V_57 ) -> V_78 ,
F_74 ( V_57 ) -> V_79 , 0 , V_80 , 0 ) ;
} else if ( V_57 -> V_75 == F_73 ( V_81 ) ) {
F_75 ( V_57 ) -> V_77 = ~ F_77 ( & F_78 ( V_57 ) -> V_78 ,
& F_78 ( V_57 ) -> V_79 , 0 , V_80 , 0 ) ;
}
while ( V_73 ) {
V_17 = F_79 ( V_73 , ( unsigned int ) V_82 ) ;
V_16 = F_65 ( V_1 -> V_2 , V_57 -> V_44 + V_74 , V_17 ,
V_18 ) ;
if ( F_60 ( F_61 ( V_1 , V_16 ) ) )
return - V_64 ;
F_80 ( V_11 , V_57 , V_16 , V_17 , V_72 , V_70 ,
V_65 , V_66 ,
V_68 && ( V_17 == V_73 ) , V_59 ) ;
V_73 -= V_17 ;
V_74 += V_17 ;
}
if ( V_68 )
return 0 ;
for ( V_60 = F_57 ( V_57 ) -> V_61 ; V_58 ; V_60 ++ ) {
V_58 -= F_58 ( V_60 ) ;
V_73 = F_58 ( V_60 ) ;
V_74 = 0 ;
while ( V_73 ) {
V_17 = F_79 ( V_73 ,
( unsigned int ) V_82 ) ;
V_16 = F_59 ( & V_1 -> V_2 -> V_62 , V_60 ,
V_74 , V_17 ,
V_63 ) ;
if ( F_60 ( F_61 ( V_1 , V_16 ) ) )
return - V_64 ;
F_62 ( V_11 , V_57 , V_16 , V_17 ,
( V_58 == 0 ) &&
( V_17 == V_73 ) ,
V_59 ) ;
V_73 -= V_17 ;
V_74 += V_17 ;
}
}
return 0 ;
}
static inline void F_81 ( struct V_1 * V_1 ,
struct V_10 * V_11 , struct V_56 * V_57 )
{
unsigned int V_72 = F_57 ( V_57 ) -> V_83 ;
unsigned int V_66 = 0 ;
int V_65 = 0 ;
int V_59 = 0 ;
int V_69 ;
if ( F_82 ( V_57 ) ) {
V_65 = 1 ;
V_66 = F_83 ( V_57 ) ;
} else if ( V_1 -> V_84 ) {
V_66 = V_1 -> V_85 ;
V_59 = 1 ;
}
if ( V_72 )
V_69 = F_70 ( V_1 , V_11 , V_57 , V_72 ,
V_65 , V_66 ,
V_59 ) ;
else if ( V_57 -> V_86 == V_87 )
V_69 = F_67 ( V_1 , V_11 , V_57 , V_65 ,
V_66 , V_59 ) ;
else
V_69 = F_63 ( V_1 , V_11 , V_57 , V_65 ,
V_66 , V_59 ) ;
if ( F_60 ( V_69 ) ) {
struct V_12 * V_13 ;
V_13 = V_11 -> V_88 -> V_89 ;
while ( ! V_13 -> V_19 && ( V_13 -> V_90 != V_11 -> V_91 ) ) {
F_6 ( V_11 , V_13 ) ;
V_11 -> V_92 . V_93 ++ ;
V_13 = V_13 -> V_89 ;
}
V_11 -> V_88 = V_13 -> V_90 ;
F_84 ( V_57 ) ;
}
}
static T_7 F_85 ( struct V_56 * V_57 ,
struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_10 * V_11 ;
unsigned int V_94 ;
struct V_95 * V_96 ;
if ( V_57 -> V_17 <= 0 ) {
F_10 ( V_57 ) ;
return V_97 ;
}
V_94 = F_86 ( V_57 ) % V_1 -> V_31 ;
V_11 = & V_1 -> V_11 [ V_94 ] ;
V_96 = F_16 ( V_26 , V_94 ) ;
if ( F_57 ( V_57 ) -> V_83 == 0 &&
F_57 ( V_57 ) -> V_98 + 1 > V_99 &&
F_87 ( V_57 ) ) {
F_10 ( V_57 ) ;
return V_97 ;
}
F_13 ( & V_1 -> V_25 [ V_94 ] ) ;
if ( F_17 ( V_11 ) <
F_57 ( V_57 ) -> V_98 + V_28 ) {
F_88 ( V_96 ) ;
F_22 ( V_26 , L_8 ) ;
F_19 ( & V_1 -> V_25 [ V_94 ] ) ;
return V_100 ;
}
F_81 ( V_1 , V_11 , V_57 ) ;
if ( F_17 ( V_11 ) < V_27 + V_28 )
F_88 ( V_96 ) ;
if ( ! V_57 -> V_101 || F_89 ( V_96 ) )
F_90 ( V_11 ) ;
F_19 ( & V_1 -> V_25 [ V_94 ] ) ;
return V_97 ;
}
static struct V_102 * F_91 ( struct V_36 * V_26 ,
struct V_102 * V_103 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_104 * V_105 ;
int V_69 ;
V_69 = F_92 ( V_1 , & V_105 ) ;
if ( V_69 == - V_64 )
return V_103 ;
V_103 -> V_106 = V_105 -> V_107 . V_108 ;
V_103 -> V_109 = V_105 -> V_107 . V_110 ;
V_103 -> V_111 = V_105 -> V_107 . V_111 ;
V_103 -> V_112 = V_105 -> V_107 . V_113 ;
V_103 -> V_114 = V_105 -> V_115 . V_116 ;
V_103 -> V_117 = V_105 -> V_115 . V_118 ;
V_103 -> V_119 = V_105 -> V_115 . V_119 ;
V_103 -> V_120 = V_105 -> V_115 . V_121 ;
V_103 -> V_122 = V_1 -> V_123 ;
V_103 -> V_124 = V_1 -> V_125 ;
V_103 -> V_126 = V_105 -> V_115 . V_127 + V_105 -> V_115 . V_128 ;
return V_103 ;
}
static int F_93 ( struct V_36 * V_26 , const T_1 * V_129 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
if ( V_1 -> V_130 == V_131 ) {
unsigned int V_130 = F_94 ( V_26 ) ;
F_32 ( V_26 , L_9 ,
V_131 , V_130 ) ;
return - V_132 ;
}
F_95 ( V_1 , V_129 ) ;
V_1 -> V_130 ++ ;
return 0 ;
}
static int F_96 ( struct V_36 * V_26 , const T_1 * V_129 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
F_97 ( V_1 , V_129 ) ;
V_1 -> V_130 -- ;
return 0 ;
}
static int F_98 ( struct V_36 * V_26 , const T_1 * V_133 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
if ( V_1 -> V_134 == V_135 ) {
unsigned int V_134 = F_99 ( V_26 ) ;
F_32 ( V_26 , L_10 ,
V_135 , V_134 ) ;
return - V_132 ;
}
F_95 ( V_1 , V_133 ) ;
V_1 -> V_134 ++ ;
return 0 ;
}
static int F_100 ( struct V_36 * V_26 , const T_1 * V_133 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
F_97 ( V_1 , V_133 ) ;
V_1 -> V_134 -- ;
return 0 ;
}
void F_101 ( struct V_1 * V_1 )
{
struct V_36 * V_26 = V_1 -> V_26 ;
F_102 ( V_26 , NULL ) ;
F_103 ( V_26 , NULL ) ;
V_1 -> V_130 = 0 ;
V_1 -> V_134 = 0 ;
V_1 -> V_136 = 0 ;
}
static int F_104 ( struct V_36 * V_26 , char * V_137 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
if ( F_1 ( V_1 ) || F_3 ( V_1 ) ) {
if ( ! F_105 ( V_137 ) && ! F_106 ( V_137 ) )
return - V_138 ;
} else {
if ( ! F_105 ( V_137 ) )
return - V_138 ;
}
memcpy ( V_26 -> V_139 , V_137 , V_26 -> V_140 ) ;
return 0 ;
}
static int F_107 ( struct V_36 * V_26 , void * V_141 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_142 * V_78 = V_141 ;
char * V_137 = V_78 -> V_143 ;
int V_69 ;
if ( F_108 ( V_1 -> V_26 ) ) {
V_69 = F_109 ( V_1 ) ;
if ( V_69 )
return V_69 ;
}
V_69 = F_104 ( V_26 , V_137 ) ;
if ( V_69 )
return V_69 ;
if ( F_108 ( V_1 -> V_26 ) ) {
V_69 = F_110 ( V_1 ) ;
if ( V_69 )
return V_69 ;
}
return V_69 ;
}
static int F_111 ( struct V_36 * V_26 , void * V_141 )
{
struct V_142 * V_78 = V_141 ;
char * V_137 = V_78 -> V_143 ;
struct V_1 * V_1 = F_40 ( V_26 ) ;
int V_69 ;
V_69 = F_109 ( V_1 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_104 ( V_26 , V_137 ) ;
if ( V_69 )
return V_69 ;
return F_110 ( V_1 ) ;
}
static void F_112 ( struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
int V_144 = 1 ;
int V_120 = ( V_26 -> V_136 & V_145 ) ? 1 : 0 ;
int V_146 = ( V_26 -> V_136 & V_147 ) ? 1 : 0 ;
int V_148 = ( V_26 -> V_136 & V_149 ) ||
F_99 ( V_26 ) > V_135 ;
int V_150 = ( V_26 -> V_136 & V_151 ) ||
F_94 ( V_26 ) > V_131 ;
unsigned int V_136 = V_26 -> V_136 |
( V_150 ? V_151 : 0 ) |
( V_148 ? V_149 : 0 ) ;
if ( V_1 -> V_136 != V_136 ) {
V_1 -> V_136 = V_136 ;
F_113 ( V_1 , V_144 ,
V_120 , V_146 , V_148 , V_150 ) ;
}
if ( ! V_148 ) {
F_114 ( V_26 , F_98 , F_100 ) ;
if ( ! V_150 )
F_115 ( V_26 , F_93 , F_96 ) ;
}
}
static void F_116 ( struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
F_31 ( & V_1 -> V_52 ) ;
}
static int F_117 ( struct V_36 * V_26 , int V_8 , T_1 * V_152 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_153 * V_154 ;
int V_69 ;
F_118 ( V_1 , V_8 , V_154 , & V_69 ) ;
if ( V_69 )
return V_69 ;
if ( F_105 ( V_152 ) || F_106 ( V_152 ) ) {
if ( V_8 == V_155 ) {
memcpy ( V_154 -> V_156 , V_152 , V_157 ) ;
return 0 ;
} else {
F_119 ( V_8 , V_69 , V_1 ,
V_158 , V_152 ) ;
return F_120 ( V_69 ) ;
}
} else
return - V_159 ;
}
static int F_121 ( struct V_36 * V_26 , int V_8 ,
struct V_160 * V_161 [] )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_153 V_162 ;
struct V_153 * V_154 ;
int V_69 = 0 , V_163 = 1 ;
F_118 ( V_1 , V_8 , V_154 , & V_69 ) ;
if ( V_69 )
return V_69 ;
if ( ! V_161 [ V_164 ] )
return - V_165 ;
memcpy ( & V_162 , V_154 , sizeof( * V_1 -> V_154 ) ) ;
memset ( V_154 , 0 , sizeof( * V_1 -> V_154 ) ) ;
V_154 -> V_166 |= V_167 ;
V_154 -> V_168 = F_122 ( V_161 [ V_164 ] ) ;
if ( V_161 [ V_169 ] ) {
V_154 -> V_166 |= V_170 ;
memcpy ( V_154 -> V_171 , F_123 ( V_161 [ V_169 ] ) ,
V_172 ) ;
}
if ( V_161 [ V_173 ] ) {
V_154 -> V_166 |= V_174 ;
memcpy ( V_154 -> V_175 ,
F_123 ( V_161 [ V_173 ] ) , V_176 ) ;
}
if ( V_161 [ V_177 ] ) {
V_154 -> V_166 |= V_178 ;
memcpy ( V_154 -> V_179 ,
F_123 ( V_161 [ V_177 ] ) , V_176 ) ;
}
if ( V_8 == V_155 ) {
if ( ! F_106 ( V_162 . V_156 ) )
memcpy ( V_154 -> V_180 , V_162 . V_156 , V_157 ) ;
if ( F_106 ( V_26 -> V_139 ) )
F_124 ( V_26 ) ;
} else {
F_119 ( V_8 , V_69 , V_1 ,
V_181 , V_154 -> V_180 ) ;
if ( V_69 ) {
F_22 ( V_26 , L_11 , V_8 ) ;
memcpy ( V_154 , & V_162 , sizeof( * V_154 ) ) ;
return F_120 ( V_69 ) ;
}
}
V_69 = F_125 ( V_1 , V_8 , & V_162 , & V_163 ) ;
if ( V_69 ) {
if ( V_163 ) {
memcpy ( V_154 , & V_162 , sizeof( * V_154 ) ) ;
} else {
memset ( V_154 , 0 , sizeof( * V_154 ) ) ;
if ( V_8 == V_155 )
F_126 ( V_26 -> V_139 ) ;
}
} else {
V_154 -> V_166 |= V_182 ;
if ( V_154 -> V_168 == V_183 ) {
F_126 ( V_154 -> V_180 ) ;
if ( V_8 == V_155 )
F_126 ( V_26 -> V_139 ) ;
}
}
if ( V_8 == V_155 )
F_126 ( V_154 -> V_156 ) ;
return V_69 ;
}
static int F_127 ( struct V_36 * V_26 , int V_8 ,
struct V_56 * V_57 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
T_2 V_184 = V_185 ;
struct V_153 * V_154 ;
int V_69 ;
F_118 ( V_1 , V_8 , V_154 , & V_69 ) ;
if ( V_69 )
return V_69 ;
if ( ! ( V_154 -> V_166 & V_182 ) )
return - V_186 ;
V_69 = F_128 ( V_1 , V_8 , V_154 -> V_168 , & V_184 ) ;
if ( V_69 )
return V_69 ;
if ( F_129 ( V_57 , V_164 , V_154 -> V_168 ) ||
F_129 ( V_57 , V_187 , V_184 ) ||
( ( V_154 -> V_166 & V_170 ) &&
F_130 ( V_57 , V_169 , V_172 , V_154 -> V_171 ) ) ||
( ( V_154 -> V_166 & V_174 ) &&
F_130 ( V_57 , V_173 , V_176 ,
V_154 -> V_175 ) ) ||
( ( V_154 -> V_166 & V_178 ) &&
F_130 ( V_57 , V_177 , V_176 , V_154 -> V_179 ) ) )
goto V_188;
return 0 ;
V_188:
return - V_189 ;
}
static void F_131 ( struct V_190 * V_33 , struct V_191 * V_13 )
{
struct V_1 * V_1 = F_7 ( V_33 -> V_14 ) ;
if ( ! V_13 -> V_19 )
return;
F_8 ( V_1 -> V_2 , V_13 -> V_16 ,
V_13 -> V_17 , V_192 ) ;
F_10 ( V_13 -> V_19 ) ;
V_13 -> V_19 = NULL ;
}
static int F_132 ( struct V_190 * V_33 )
{
struct V_1 * V_1 = F_7 ( V_33 -> V_14 ) ;
struct V_36 * V_26 = V_1 -> V_26 ;
struct V_56 * V_57 ;
unsigned int V_17 = V_26 -> V_35 + V_193 ;
unsigned int V_194 = 0 ;
T_6 V_16 ;
struct V_191 * V_13 = V_33 -> V_88 ;
if ( V_13 -> V_19 ) {
F_133 ( V_33 , V_13 -> V_19 , V_194 , V_13 -> V_16 ,
V_13 -> V_17 ) ;
return 0 ;
}
V_57 = F_134 ( V_26 , V_17 ) ;
if ( ! V_57 )
return - V_64 ;
V_16 = F_65 ( V_1 -> V_2 , V_57 -> V_44 , V_17 ,
V_192 ) ;
if ( F_60 ( F_61 ( V_1 , V_16 ) ) ) {
F_84 ( V_57 ) ;
return - V_64 ;
}
F_133 ( V_33 , V_57 , V_194 ,
V_16 , V_17 ) ;
return 0 ;
}
static void F_135 ( struct V_195 * V_196 ,
T_3 V_197 )
{
if ( V_198 <= V_197 )
V_196 -> V_199 += V_197 ;
else
V_196 -> V_200 += V_197 ;
}
static bool F_136 ( struct V_36 * V_26 , struct V_56 * * V_57 ,
struct V_191 * V_13 , T_2 V_17 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_56 * V_201 ;
if ( V_17 > V_1 -> V_202 )
return false ;
V_201 = F_134 ( V_26 , V_17 ) ;
if ( ! V_201 )
return false ;
F_137 ( V_1 -> V_2 , V_13 -> V_16 , V_17 ,
V_203 ) ;
memcpy ( V_201 -> V_44 , ( * V_57 ) -> V_44 , V_17 ) ;
* V_57 = V_201 ;
return true ;
}
static void F_138 ( struct V_190 * V_33 ,
struct V_20 * V_20 , struct V_191 * V_13 ,
int V_204 , void * V_21 )
{
struct V_1 * V_1 = F_7 ( V_33 -> V_14 ) ;
struct V_36 * V_26 = V_1 -> V_26 ;
struct V_56 * V_57 ;
struct V_205 * V_206 = & V_1 -> V_206 [ F_139 ( V_1 , V_33 -> V_207 ) ] ;
T_1 type , V_208 , V_68 , V_15 , V_209 , V_210 ;
T_1 V_211 , V_212 , V_213 , V_214 , V_215 ;
T_1 V_216 , V_217 , V_218 , V_219 ;
T_1 V_220 , V_221 , V_222 , V_223 , V_224 , V_225 ;
T_1 V_226 ;
T_2 V_23 , V_24 , V_227 , V_228 , V_229 ;
T_3 V_230 ;
if ( V_204 )
return;
V_57 = V_13 -> V_19 ;
F_140 ( (struct V_231 * ) V_20 ,
& type , & V_208 , & V_23 , & V_24 ,
& V_209 , & V_211 , & V_68 , & V_15 , & V_224 ,
& V_225 , & V_230 , & V_227 ,
& V_226 , & V_210 , & V_228 , & V_229 ,
& V_212 , & V_213 , & V_214 ,
& V_215 , & V_216 , & V_217 , & V_218 ,
& V_219 , & V_220 , & V_221 , & V_222 ,
& V_223 ) ;
if ( V_226 ) {
if ( ! V_223 ) {
if ( V_227 > 0 )
V_1 -> V_125 ++ ;
else if ( V_227 == 0 )
V_1 -> V_123 ++ ;
}
F_8 ( V_1 -> V_2 , V_13 -> V_16 , V_13 -> V_17 ,
V_192 ) ;
F_10 ( V_57 ) ;
V_13 -> V_19 = NULL ;
return;
}
if ( V_68 && V_227 > 0 ) {
if ( ! F_136 ( V_26 , & V_57 , V_13 , V_227 ) ) {
V_13 -> V_19 = NULL ;
F_8 ( V_1 -> V_2 , V_13 -> V_16 , V_13 -> V_17 ,
V_192 ) ;
}
F_141 ( V_57 -> V_44 - V_232 ) ;
F_142 ( V_57 , V_227 ) ;
V_57 -> V_75 = F_143 ( V_57 , V_26 ) ;
F_144 ( V_57 , V_23 ) ;
if ( V_26 -> V_233 & V_234 ) {
F_145 ( V_57 , V_230 ,
( V_224 &
( V_235 |
V_236 |
V_237 ) ) ?
V_238 : V_239 ) ;
}
if ( ( V_26 -> V_233 & V_240 ) && V_216 &&
V_219 )
V_57 -> V_86 = V_241 ;
if ( V_210 )
F_146 ( V_57 , F_147 ( V_242 ) , V_228 ) ;
F_148 ( V_57 , & V_1 -> V_54 [ V_33 -> V_207 ] ) ;
if ( F_149 ( V_33 ) ||
! ( V_26 -> V_233 & V_243 ) )
F_150 ( V_57 ) ;
else
F_151 ( & V_1 -> V_54 [ V_23 ] , V_57 ) ;
if ( V_1 -> V_244 . V_245 )
F_135 ( & V_206 -> V_246 ,
V_227 ) ;
} else {
F_8 ( V_1 -> V_2 , V_13 -> V_16 , V_13 -> V_17 ,
V_192 ) ;
F_10 ( V_57 ) ;
V_13 -> V_19 = NULL ;
}
}
static int F_152 ( struct V_22 * V_14 , struct V_20 * V_20 ,
T_1 type , T_2 V_23 , T_2 V_24 , void * V_21 )
{
struct V_1 * V_1 = F_7 ( V_14 ) ;
F_153 ( & V_1 -> V_33 [ V_23 ] , V_20 ,
V_24 , V_247 ,
F_138 , V_21 ) ;
return 0 ;
}
static int F_154 ( struct V_55 * V_54 , int V_248 )
{
struct V_36 * V_26 = V_54 -> V_62 ;
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_249 = F_139 ( V_1 , 0 ) ;
unsigned int V_250 = F_155 ( V_1 , 0 ) ;
unsigned int V_49 = F_41 () ;
unsigned int V_251 = V_248 ;
unsigned int V_252 = - 1 ;
unsigned int V_253 , V_254 = 0 , V_255 ;
int V_69 ;
V_255 = F_156 ( & V_1 -> V_206 [ V_250 ] , V_252 ,
F_12 , NULL ) ;
if ( ! F_157 ( & V_1 -> V_33 [ V_249 ] ) ) {
if ( V_255 > 0 )
F_158 ( & V_1 -> V_49 [ V_49 ] ,
V_255 ,
0 ,
0 ) ;
return V_248 ;
}
if ( V_248 > 0 )
V_254 = F_156 ( & V_1 -> V_206 [ V_249 ] ,
V_251 , F_152 , NULL ) ;
V_253 = V_254 + V_255 ;
if ( V_253 > 0 )
F_158 ( & V_1 -> V_49 [ V_49 ] ,
V_253 ,
0 ,
0 ) ;
V_69 = F_159 ( & V_1 -> V_33 [ 0 ] , F_132 ) ;
F_160 ( & V_1 -> V_33 [ V_249 ] , V_54 ) ;
if ( V_69 )
V_254 = V_251 ;
if ( V_254 < V_251 ) {
F_161 ( V_54 ) ;
F_46 ( & V_1 -> V_49 [ V_49 ] ) ;
}
return V_254 ;
}
static void F_162 ( struct V_1 * V_1 , struct V_190 * V_33 )
{
unsigned int V_49 = F_163 ( V_1 , V_33 -> V_207 ) ;
struct V_205 * V_206 = & V_1 -> V_206 [ F_139 ( V_1 , V_33 -> V_207 ) ] ;
T_3 V_256 = V_206 -> V_257 ;
if ( V_206 -> V_257 != V_206 -> V_258 ) {
F_164 ( & V_1 -> V_49 [ V_49 ] , V_256 ) ;
V_206 -> V_258 = V_206 -> V_257 ;
}
}
static void F_165 ( struct V_1 * V_1 , struct V_190 * V_33 )
{
struct V_259 * V_260 = & V_1 -> V_244 ;
struct V_205 * V_206 = & V_1 -> V_206 [ F_139 ( V_1 , V_33 -> V_207 ) ] ;
struct V_195 * V_246 = & V_206 -> V_246 ;
int V_207 ;
T_3 V_256 ;
T_3 V_261 ;
T_3 V_262 ;
T_8 V_263 ;
T_9 V_264 = F_166 () ;
V_263 = F_167 ( V_264 , V_206 -> V_265 ) ;
if ( V_263 < V_266 )
return;
V_206 -> V_265 = V_264 ;
V_262 = V_246 -> V_199 +
V_246 -> V_200 ;
V_262 <<= 3 ;
V_262 = V_263 > V_267 ? 0 : V_262 / ( T_3 ) V_263 ;
for ( V_207 = 0 ; V_207 < V_268 ; V_207 ++ )
if ( V_262 < V_269 [ V_207 ] . V_270 )
break;
V_261 = ( V_246 -> V_200 >
V_246 -> V_199 << 1 ) ?
V_260 -> V_271 :
V_260 -> V_272 ;
V_256 = V_261 + ( ( V_260 -> V_273 - V_261 ) *
V_269 [ V_207 ] . V_274 / 100 ) ;
V_206 -> V_257 = ( V_256 + V_206 -> V_257 ) >> 1 ;
V_246 -> V_199 = 0 ;
V_246 -> V_200 = 0 ;
}
static void F_168 ( struct V_1 * V_1 )
{
F_169 ( V_1 -> V_26 -> V_275 ) ;
V_1 -> V_26 -> V_275 = NULL ;
}
static void F_170 ( struct V_1 * V_1 )
{
int V_29 , V_276 ;
if ( F_171 ( V_1 -> V_14 ) == V_277 ) {
V_1 -> V_26 -> V_275 = F_172 ( V_1 -> V_32 ) ;
if ( F_60 ( ! V_1 -> V_26 -> V_275 ) )
return;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
V_276 = F_173 ( V_1 -> V_26 -> V_275 ,
V_1 -> V_278 [ V_29 ] . V_279 ) ;
if ( F_60 ( V_276 ) ) {
F_168 ( V_1 ) ;
return;
}
}
}
}
static void F_168 ( struct V_1 * V_1 )
{
}
static void F_170 ( struct V_1 * V_1 )
{
}
static int F_174 ( struct V_55 * V_54 )
{
struct V_36 * V_26 = V_54 -> V_62 ;
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_33 = ( V_54 - & V_1 -> V_54 [ 0 ] ) ;
unsigned int V_206 = F_139 ( V_1 , V_33 ) ;
unsigned int V_49 = F_163 ( V_1 , V_33 ) ;
unsigned int V_280 = - 1 ;
unsigned int V_253 ;
if ( ! F_175 ( & V_1 -> V_33 [ V_33 ] ) )
return V_281 ;
V_253 = F_156 ( & V_1 -> V_206 [ V_206 ] , V_280 ,
F_152 , NULL ) ;
if ( V_253 > 0 )
F_158 ( & V_1 -> V_49 [ V_49 ] ,
V_253 , 0 , 0 ) ;
F_159 ( & V_1 -> V_33 [ V_33 ] , F_132 ) ;
if ( V_1 -> V_244 . V_245 )
F_165 ( V_1 , & V_1 -> V_33 [ V_33 ] ) ;
F_176 ( & V_1 -> V_33 [ V_33 ] ) ;
return V_253 ;
}
static int F_177 ( struct V_55 * V_54 , int V_248 )
{
struct V_36 * V_26 = V_54 -> V_62 ;
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_282 = ( V_54 - & V_1 -> V_54 [ 0 ] ) - V_1 -> V_32 ;
struct V_10 * V_11 = & V_1 -> V_11 [ V_282 ] ;
unsigned int V_206 ;
unsigned int V_49 ;
unsigned int V_252 = - 1 ;
unsigned int V_255 ;
unsigned int V_283 ;
V_283 = V_11 -> V_207 ;
V_206 = F_155 ( V_1 , V_283 ) ;
V_49 = F_178 ( V_1 , V_283 ) ;
V_255 = F_156 ( & V_1 -> V_206 [ V_206 ] , V_252 ,
F_12 , NULL ) ;
F_158 ( & V_1 -> V_49 [ V_49 ] , V_255 ,
0 ,
1 ) ;
if ( ! V_255 ) {
F_161 ( V_54 ) ;
F_46 ( & V_1 -> V_49 [ V_49 ] ) ;
return 0 ;
}
return V_248 ;
}
static int F_179 ( struct V_55 * V_54 , int V_248 )
{
struct V_36 * V_26 = V_54 -> V_62 ;
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_33 = ( V_54 - & V_1 -> V_54 [ 0 ] ) ;
unsigned int V_206 = F_139 ( V_1 , V_33 ) ;
unsigned int V_49 = F_163 ( V_1 , V_33 ) ;
unsigned int V_280 = V_248 ;
unsigned int V_253 = 0 ;
int V_69 ;
if ( ! F_157 ( & V_1 -> V_33 [ V_33 ] ) )
return V_248 ;
if ( V_248 > 0 )
V_253 = F_156 ( & V_1 -> V_206 [ V_206 ] ,
V_280 , F_152 , NULL ) ;
if ( V_253 > 0 )
F_158 ( & V_1 -> V_49 [ V_49 ] ,
V_253 ,
0 ,
0 ) ;
V_69 = F_159 ( & V_1 -> V_33 [ V_33 ] , F_132 ) ;
if ( V_69 )
V_253 = V_280 ;
if ( V_1 -> V_244 . V_245 )
F_165 ( V_1 , & V_1 -> V_33 [ V_33 ] ) ;
F_160 ( & V_1 -> V_33 [ V_33 ] , V_54 ) ;
if ( V_253 < V_280 ) {
F_161 ( V_54 ) ;
if ( V_1 -> V_244 . V_245 )
F_162 ( V_1 , & V_1 -> V_33 [ V_33 ] ) ;
F_46 ( & V_1 -> V_49 [ V_49 ] ) ;
}
return V_253 ;
}
static void F_180 ( unsigned long V_44 )
{
struct V_1 * V_1 = (struct V_1 * ) V_44 ;
F_38 ( V_1 ) ;
F_181 ( & V_1 -> V_284 ,
F_182 ( V_285 + V_286 ) ) ;
}
static void F_183 ( struct V_1 * V_1 )
{
struct V_36 * V_26 = V_1 -> V_26 ;
unsigned int V_29 ;
F_168 ( V_1 ) ;
switch ( F_171 ( V_1 -> V_14 ) ) {
case V_287 :
F_184 ( V_1 -> V_2 -> V_43 , V_26 ) ;
break;
case V_288 :
F_184 ( V_1 -> V_2 -> V_43 , V_1 ) ;
break;
case V_277 :
for ( V_29 = 0 ; V_29 < F_185 ( V_1 -> V_289 ) ; V_29 ++ )
if ( V_1 -> V_289 [ V_29 ] . V_290 )
F_184 ( V_1 -> V_278 [ V_29 ] . V_279 ,
V_1 -> V_289 [ V_29 ] . V_291 ) ;
break;
default:
break;
}
}
static int F_186 ( struct V_1 * V_1 )
{
struct V_36 * V_26 = V_1 -> V_26 ;
unsigned int V_29 , V_49 ;
int V_69 = 0 ;
F_170 ( V_1 ) ;
switch ( F_171 ( V_1 -> V_14 ) ) {
case V_287 :
V_69 = F_187 ( V_1 -> V_2 -> V_43 , F_39 ,
V_292 , V_26 -> V_171 , V_26 ) ;
break;
case V_288 :
V_69 = F_187 ( V_1 -> V_2 -> V_43 , F_50 ,
0 , V_26 -> V_171 , V_1 ) ;
break;
case V_277 :
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
V_49 = F_163 ( V_1 , V_29 ) ;
snprintf ( V_1 -> V_289 [ V_49 ] . V_293 ,
sizeof( V_1 -> V_289 [ V_49 ] . V_293 ) ,
L_12 , V_26 -> V_171 , V_29 ) ;
V_1 -> V_289 [ V_49 ] . V_294 = F_51 ;
V_1 -> V_289 [ V_49 ] . V_291 = & V_1 -> V_54 [ V_29 ] ;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ ) {
int V_11 = F_155 ( V_1 , V_29 ) ;
V_49 = F_178 ( V_1 , V_29 ) ;
snprintf ( V_1 -> V_289 [ V_49 ] . V_293 ,
sizeof( V_1 -> V_289 [ V_49 ] . V_293 ) ,
L_13 , V_26 -> V_171 , V_29 ) ;
V_1 -> V_289 [ V_49 ] . V_294 = F_51 ;
V_1 -> V_289 [ V_49 ] . V_291 = & V_1 -> V_54 [ V_11 ] ;
}
V_49 = F_53 ( V_1 ) ;
snprintf ( V_1 -> V_289 [ V_49 ] . V_293 ,
sizeof( V_1 -> V_289 [ V_49 ] . V_293 ) ,
L_14 , V_26 -> V_171 ) ;
V_1 -> V_289 [ V_49 ] . V_294 = F_52 ;
V_1 -> V_289 [ V_49 ] . V_291 = V_1 ;
V_49 = F_55 ( V_1 ) ;
snprintf ( V_1 -> V_289 [ V_49 ] . V_293 ,
sizeof( V_1 -> V_289 [ V_49 ] . V_293 ) ,
L_15 , V_26 -> V_171 ) ;
V_1 -> V_289 [ V_49 ] . V_294 = F_54 ;
V_1 -> V_289 [ V_49 ] . V_291 = V_1 ;
for ( V_29 = 0 ; V_29 < F_185 ( V_1 -> V_289 ) ; V_29 ++ )
V_1 -> V_289 [ V_29 ] . V_290 = 0 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_295 ; V_29 ++ ) {
V_69 = F_187 ( V_1 -> V_278 [ V_29 ] . V_279 ,
V_1 -> V_289 [ V_29 ] . V_294 , 0 ,
V_1 -> V_289 [ V_29 ] . V_293 ,
V_1 -> V_289 [ V_29 ] . V_291 ) ;
if ( V_69 ) {
F_183 ( V_1 ) ;
break;
}
V_1 -> V_289 [ V_29 ] . V_290 = 1 ;
}
break;
default:
break;
}
return V_69 ;
}
static void F_188 ( struct V_1 * V_1 )
{
unsigned int V_29 ;
switch ( F_171 ( V_1 -> V_14 ) ) {
case V_287 :
case V_288 :
F_189 ( V_1 -> V_2 -> V_43 ) ;
break;
case V_277 :
for ( V_29 = 0 ; V_29 < V_1 -> V_295 ; V_29 ++ )
F_189 ( V_1 -> V_278 [ V_29 ] . V_279 ) ;
break;
default:
break;
}
}
static void F_190 ( struct V_1 * V_1 )
{
unsigned int V_296 ;
int V_207 = - 1 ;
struct V_259 * V_260 = & V_1 -> V_244 ;
if ( V_277 != F_171 ( V_1 -> V_14 ) ) {
F_26 ( V_1 -> V_26 , L_16 ) ;
return;
}
V_296 = F_191 ( V_1 -> V_14 ) ;
if ( V_297 < V_296 )
V_207 = V_298 ;
else if ( V_299 < V_296 )
V_207 = V_300 ;
else
V_207 = V_301 ;
V_260 -> V_271 = V_302 [ V_207 ] . V_271 ;
V_260 -> V_272 = V_302 [ V_207 ] . V_272 ;
V_260 -> V_273 = V_303 ;
for ( V_207 = 0 ; V_207 < V_1 -> V_32 ; V_207 ++ )
V_1 -> V_206 [ V_207 ] . V_258 =
V_1 -> V_304 . V_305 ;
V_260 -> V_245 = 1 ;
}
static int F_192 ( struct V_1 * V_1 )
{
int V_69 ;
F_193 ( & V_1 -> V_306 ) ;
switch ( F_171 ( V_1 -> V_14 ) ) {
case V_287 :
V_69 = F_194 ( V_1 -> V_14 ,
F_43 () ) ;
break;
case V_277 :
V_69 = F_194 ( V_1 -> V_14 ,
F_55 ( V_1 ) ) ;
break;
default:
V_69 = F_194 ( V_1 -> V_14 , - 1 ) ;
break;
}
F_195 ( & V_1 -> V_306 ) ;
return V_69 ;
}
static void F_196 ( struct V_1 * V_1 )
{
switch ( F_171 ( V_1 -> V_14 ) ) {
case V_288 :
F_181 ( & V_1 -> V_284 , V_285 ) ;
break;
default:
break;
}
}
static int F_197 ( struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_29 ;
int V_69 ;
V_69 = F_186 ( V_1 ) ;
if ( V_69 ) {
F_22 ( V_26 , L_17 ) ;
return V_69 ;
}
V_69 = F_192 ( V_1 ) ;
if ( V_69 ) {
F_22 ( V_26 ,
L_18 ) ;
goto V_307;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
F_159 ( & V_1 -> V_33 [ V_29 ] , F_132 ) ;
if ( F_198 ( & V_1 -> V_33 [ V_29 ] ) == 0 ) {
F_22 ( V_26 , L_19 ) ;
V_69 = - V_64 ;
goto V_308;
}
}
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ )
F_199 ( & V_1 -> V_11 [ V_29 ] ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_200 ( & V_1 -> V_33 [ V_29 ] ) ;
if ( ! F_1 ( V_1 ) && ! F_3 ( V_1 ) )
F_110 ( V_1 ) ;
F_112 ( V_26 ) ;
F_201 ( V_26 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
F_202 ( & V_1 -> V_33 [ V_29 ] ) ;
F_203 ( & V_1 -> V_54 [ V_29 ] ) ;
}
if ( F_171 ( V_1 -> V_14 ) == V_277 )
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ )
F_203 ( & V_1 -> V_54 [ F_155 ( V_1 , V_29 ) ] ) ;
F_204 ( V_1 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_295 ; V_29 ++ )
F_46 ( & V_1 -> V_49 [ V_29 ] ) ;
F_196 ( V_1 ) ;
F_205 ( V_1 ) ;
return 0 ;
V_308:
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_206 ( & V_1 -> V_33 [ V_29 ] , F_131 ) ;
F_207 ( V_1 ) ;
V_307:
F_183 ( V_1 ) ;
return V_69 ;
}
static int F_208 ( struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_29 ;
int V_69 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_295 ; V_29 ++ ) {
F_44 ( & V_1 -> V_49 [ V_29 ] ) ;
( void ) F_209 ( & V_1 -> V_49 [ V_29 ] ) ;
}
F_188 ( V_1 ) ;
F_210 ( & V_1 -> V_284 ) ;
F_211 ( V_1 ) ;
F_212 ( V_1 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
F_213 ( & V_1 -> V_54 [ V_29 ] ) ;
F_214 () ;
while ( ! F_157 ( & V_1 -> V_33 [ V_29 ] ) )
F_215 ( 1 ) ;
F_216 () ;
}
F_37 ( V_26 ) ;
F_217 ( V_26 ) ;
if ( F_171 ( V_1 -> V_14 ) == V_277 )
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ )
F_213 ( & V_1 -> V_54 [ F_155 ( V_1 , V_29 ) ] ) ;
if ( ! F_1 ( V_1 ) && ! F_3 ( V_1 ) )
F_109 ( V_1 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ ) {
V_69 = F_218 ( & V_1 -> V_11 [ V_29 ] ) ;
if ( V_69 )
return V_69 ;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
V_69 = F_219 ( & V_1 -> V_33 [ V_29 ] ) ;
if ( V_69 )
return V_69 ;
}
F_207 ( V_1 ) ;
F_183 ( V_1 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ )
F_220 ( & V_1 -> V_11 [ V_29 ] , F_6 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_206 ( & V_1 -> V_33 [ V_29 ] , F_131 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_309 ; V_29 ++ )
F_221 ( & V_1 -> V_206 [ V_29 ] ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_295 ; V_29 ++ )
F_222 ( & V_1 -> V_49 [ V_29 ] ) ;
return 0 ;
}
static int F_223 ( struct V_36 * V_26 , int V_310 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
int V_311 = F_108 ( V_26 ) ;
if ( V_310 < V_38 || V_310 > V_39 )
return - V_159 ;
if ( F_1 ( V_1 ) || F_3 ( V_1 ) )
return - V_165 ;
if ( V_311 )
F_208 ( V_26 ) ;
V_26 -> V_35 = V_310 ;
if ( V_26 -> V_35 > V_1 -> V_37 )
F_32 ( V_26 ,
L_20 ,
V_26 -> V_35 , V_1 -> V_37 ) ;
if ( V_311 )
F_197 ( V_26 ) ;
return 0 ;
}
static void F_224 ( struct V_312 * V_313 )
{
struct V_1 * V_1 = F_225 ( V_313 , struct V_1 , V_40 ) ;
struct V_36 * V_26 = V_1 -> V_26 ;
int V_310 = F_28 ( V_1 -> V_14 ) ;
int V_69 ;
unsigned int V_29 ;
V_310 = F_29 ( int , V_38 , F_30 ( int , V_39 , V_310 ) ) ;
F_226 () ;
F_210 ( & V_1 -> V_284 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_213 ( & V_1 -> V_54 [ V_29 ] ) ;
F_44 ( & V_1 -> V_49 [ 0 ] ) ;
F_188 ( V_1 ) ;
V_69 = F_219 ( & V_1 -> V_33 [ 0 ] ) ;
if ( V_69 ) {
F_227 () ;
F_22 ( V_26 , L_21 ) ;
return;
}
F_206 ( & V_1 -> V_33 [ 0 ] , F_131 ) ;
F_221 ( & V_1 -> V_206 [ 0 ] ) ;
F_222 ( & V_1 -> V_49 [ 0 ] ) ;
V_26 -> V_35 = V_310 ;
F_159 ( & V_1 -> V_33 [ 0 ] , F_132 ) ;
if ( F_198 ( & V_1 -> V_33 [ 0 ] ) == 0 ) {
F_227 () ;
F_22 ( V_26 , L_22 ) ;
return;
}
F_200 ( & V_1 -> V_33 [ 0 ] ) ;
F_203 ( & V_1 -> V_54 [ 0 ] ) ;
F_46 ( & V_1 -> V_49 [ 0 ] ) ;
F_196 ( V_1 ) ;
F_227 () ;
F_26 ( V_26 , L_23 , V_26 -> V_35 ) ;
}
static void F_228 ( struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_22 * V_14 = V_1 -> V_14 ;
unsigned int V_29 , V_49 ;
switch ( F_171 ( V_14 ) ) {
case V_277 :
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
V_49 = F_163 ( V_1 , V_29 ) ;
F_51 ( V_1 -> V_278 [ V_49 ] . V_279 ,
& V_1 -> V_54 [ V_29 ] ) ;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ ) {
V_49 = F_178 ( V_1 , V_29 ) ;
F_51 ( V_1 -> V_278 [ V_49 ] . V_279 ,
& V_1 -> V_54 [ F_155 ( V_1 , V_29 ) ] ) ;
}
break;
case V_288 :
F_50 ( V_1 -> V_2 -> V_43 , V_1 ) ;
break;
case V_287 :
F_39 ( V_1 -> V_2 -> V_43 , V_26 ) ;
break;
default:
break;
}
}
static int F_229 ( struct V_22 * V_14 ,
int (* F_230)( struct V_22 * , int ) ,
int (* F_231)( struct V_22 * , int * ) ,
int V_314 )
{
unsigned long time ;
int V_315 ;
int V_69 ;
F_232 ( F_233 () ) ;
V_69 = F_230 ( V_14 , V_314 ) ;
if ( V_69 )
return V_69 ;
time = V_285 + ( V_316 * 2 ) ;
do {
V_69 = F_231 ( V_14 , & V_315 ) ;
if ( V_69 )
return V_69 ;
if ( V_315 )
return 0 ;
F_234 ( V_316 / 10 ) ;
} while ( F_235 ( time , V_285 ) );
return - V_317 ;
}
static int F_236 ( struct V_1 * V_1 )
{
int V_69 ;
V_69 = F_229 ( V_1 -> V_14 , V_318 ,
V_319 , 0 ) ;
if ( V_69 )
F_237 ( F_238 ( V_1 ) , L_24 ,
V_69 ) ;
return V_69 ;
}
static int F_239 ( struct V_1 * V_1 )
{
int V_69 ;
V_69 = F_229 ( V_1 -> V_14 , V_320 ,
V_321 , 0 ) ;
if ( V_69 )
F_22 ( V_1 -> V_26 , L_25 ,
V_69 ) ;
return V_69 ;
}
int F_240 ( struct V_1 * V_1 )
{
union V_322 * V_323 ;
T_6 V_324 ;
int V_29 , V_325 , V_326 , V_69 ;
V_323 = F_241 ( V_1 -> V_2 ,
sizeof( union V_322 ) ,
& V_324 ) ;
if ( ! V_323 )
return - V_64 ;
for ( V_29 = 0 ; V_29 < V_327 ; V_29 ++ ) {
V_325 = V_29 / V_328 ;
V_326 = V_29 % V_328 ;
V_323 -> V_329 [ V_325 ] . V_330 [ V_326 ] = V_1 -> V_331 [ V_29 ] ;
}
F_193 ( & V_1 -> V_306 ) ;
V_69 = F_242 ( V_1 ,
V_324 ,
sizeof( union V_322 ) ) ;
F_195 ( & V_1 -> V_306 ) ;
F_243 ( V_1 -> V_2 , sizeof( union V_322 ) ,
V_323 , V_324 ) ;
return V_69 ;
}
static int F_244 ( struct V_1 * V_1 )
{
F_245 ( V_1 -> V_331 , V_327 ) ;
return F_240 ( V_1 ) ;
}
static int F_246 ( struct V_1 * V_1 , T_1 V_332 )
{
T_6 V_333 ;
union V_334 * V_335 = NULL ;
unsigned int V_29 ;
int V_69 ;
V_335 = F_247 ( V_1 -> V_2 ,
sizeof( union V_334 ) , & V_333 ) ;
if ( ! V_335 )
return - V_64 ;
for ( V_29 = 0 ; V_29 < ( 1 << V_332 ) ; V_29 ++ )
( * V_335 ) . V_336 [ V_29 / 4 ] . V_330 [ V_29 % 4 ] = V_29 % V_1 -> V_32 ;
F_193 ( & V_1 -> V_306 ) ;
V_69 = F_248 ( V_1 ,
V_333 ,
sizeof( union V_334 ) ) ;
F_195 ( & V_1 -> V_306 ) ;
F_243 ( V_1 -> V_2 , sizeof( union V_334 ) ,
V_335 , V_333 ) ;
return V_69 ;
}
static int F_249 ( struct V_1 * V_1 , T_1 V_337 ,
T_1 V_338 , T_1 V_332 , T_1 V_339 , T_1 V_340 )
{
const T_1 V_341 = 0 ;
const T_1 V_342 = 1 ;
int V_69 ;
F_193 ( & V_1 -> V_306 ) ;
V_69 = F_250 ( V_1 ,
V_337 , V_338 ,
V_332 , V_339 ,
V_340 , V_341 ,
V_342 ) ;
F_195 ( & V_1 -> V_306 ) ;
return V_69 ;
}
static int F_251 ( struct V_1 * V_1 )
{
struct V_3 * V_62 = F_238 ( V_1 ) ;
const T_1 V_337 = 0 ;
const T_1 V_338 = V_343 |
V_237 |
V_344 |
V_236 ;
const T_1 V_332 = 7 ;
const T_1 V_339 = 0 ;
T_1 V_340 = F_252 ( V_1 , V_345 ) && ( V_1 -> V_32 > 1 ) ;
if ( V_340 ) {
if ( ! F_244 ( V_1 ) ) {
if ( F_246 ( V_1 , V_332 ) ) {
V_340 = 0 ;
F_253 ( V_62 , L_26
L_27 ) ;
}
} else {
V_340 = 0 ;
F_253 ( V_62 , L_28 ) ;
}
}
return F_249 ( V_1 , V_337 , V_338 ,
V_332 , V_339 , V_340 ) ;
}
static void F_254 ( struct V_312 * V_313 )
{
struct V_1 * V_1 = F_225 ( V_313 , struct V_1 , V_52 ) ;
if ( ! F_108 ( V_1 -> V_26 ) )
return;
F_226 () ;
F_13 ( & V_1 -> V_346 ) ;
F_255 ( V_1 ) ;
F_208 ( V_1 -> V_26 ) ;
F_239 ( V_1 ) ;
F_101 ( V_1 ) ;
F_256 ( V_1 ) ;
F_251 ( V_1 ) ;
F_257 ( V_1 ) ;
F_197 ( V_1 -> V_26 ) ;
F_19 ( & V_1 -> V_346 ) ;
F_258 ( V_347 , V_1 -> V_26 ) ;
F_227 () ;
}
static int F_259 ( struct V_1 * V_1 )
{
unsigned int V_348 = F_30 (unsigned int, enic->rq_count, ENIC_RQ_MAX) ;
unsigned int V_349 = F_30 (unsigned int, enic->wq_count, ENIC_WQ_MAX) ;
unsigned int V_29 ;
F_232 ( F_185 ( V_1 -> V_278 ) < V_348 + V_349 + 2 ) ;
for ( V_29 = 0 ; V_29 < V_348 + V_349 + 2 ; V_29 ++ )
V_1 -> V_278 [ V_29 ] . V_350 = V_29 ;
if ( F_252 ( V_1 , V_345 ) &&
V_1 -> V_304 . V_351 < 1 &&
V_1 -> V_32 >= V_348 &&
V_1 -> V_31 >= V_349 &&
V_1 -> V_309 >= V_348 + V_349 &&
V_1 -> V_295 >= V_348 + V_349 + 2 ) {
if ( F_260 ( V_1 -> V_2 , V_1 -> V_278 ,
V_348 + V_349 + 2 , V_348 + V_349 + 2 ) > 0 ) {
V_1 -> V_32 = V_348 ;
V_1 -> V_31 = V_349 ;
V_1 -> V_309 = V_348 + V_349 ;
V_1 -> V_295 = V_348 + V_349 + 2 ;
F_261 ( V_1 -> V_14 ,
V_277 ) ;
return 0 ;
}
}
if ( V_1 -> V_304 . V_351 < 1 &&
V_1 -> V_32 >= 1 &&
V_1 -> V_31 >= V_349 &&
V_1 -> V_309 >= 1 + V_349 &&
V_1 -> V_295 >= 1 + V_349 + 2 ) {
if ( F_260 ( V_1 -> V_2 , V_1 -> V_278 ,
1 + V_349 + 2 , 1 + V_349 + 2 ) > 0 ) {
V_1 -> V_32 = 1 ;
V_1 -> V_31 = V_349 ;
V_1 -> V_309 = 1 + V_349 ;
V_1 -> V_295 = 1 + V_349 + 2 ;
F_261 ( V_1 -> V_14 ,
V_277 ) ;
return 0 ;
}
}
if ( V_1 -> V_304 . V_351 < 2 &&
V_1 -> V_32 >= 1 &&
V_1 -> V_31 >= 1 &&
V_1 -> V_309 >= 2 &&
V_1 -> V_295 >= 1 &&
! F_262 ( V_1 -> V_2 ) ) {
V_1 -> V_32 = 1 ;
V_1 -> V_31 = 1 ;
V_1 -> V_309 = 2 ;
V_1 -> V_295 = 1 ;
F_261 ( V_1 -> V_14 , V_288 ) ;
return 0 ;
}
if ( V_1 -> V_304 . V_351 < 3 &&
V_1 -> V_32 >= 1 &&
V_1 -> V_31 >= 1 &&
V_1 -> V_309 >= 2 &&
V_1 -> V_295 >= 3 ) {
V_1 -> V_32 = 1 ;
V_1 -> V_31 = 1 ;
V_1 -> V_309 = 2 ;
V_1 -> V_295 = 3 ;
F_261 ( V_1 -> V_14 , V_287 ) ;
return 0 ;
}
F_261 ( V_1 -> V_14 , V_352 ) ;
return - V_159 ;
}
static void F_263 ( struct V_1 * V_1 )
{
switch ( F_171 ( V_1 -> V_14 ) ) {
case V_277 :
F_264 ( V_1 -> V_2 ) ;
break;
case V_288 :
F_265 ( V_1 -> V_2 ) ;
break;
default:
break;
}
F_261 ( V_1 -> V_14 , V_352 ) ;
}
static void F_266 ( struct V_1 * V_1 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
F_267 ( & V_1 -> V_54 [ V_29 ] ) ;
F_268 ( & V_1 -> V_54 [ V_29 ] ) ;
}
if ( F_171 ( V_1 -> V_14 ) == V_277 )
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ )
F_268 ( & V_1 -> V_54 [ F_155 ( V_1 , V_29 ) ] ) ;
F_269 ( V_1 ) ;
F_263 ( V_1 ) ;
}
static void F_270 ( struct V_1 * V_1 )
{
if ( F_271 () ) {
F_272 ( F_238 ( V_1 ) , L_29 ) ;
V_1 -> V_32 = 1 ;
V_1 -> V_31 = 1 ;
V_1 -> V_304 . V_353 = V_354 ;
V_1 -> V_304 . V_355 = V_356 ;
V_1 -> V_304 . V_35 = F_30 ( T_2 , 1500 , V_1 -> V_304 . V_35 ) ;
}
}
static int F_273 ( struct V_1 * V_1 )
{
struct V_3 * V_62 = F_238 ( V_1 ) ;
struct V_36 * V_26 = V_1 -> V_26 ;
unsigned int V_29 ;
int V_69 ;
V_69 = F_274 ( V_1 ) ;
if ( V_69 ) {
F_253 ( V_62 , L_30
L_31 ) ;
F_275 ( V_1 -> V_14 ) ;
}
V_69 = F_276 ( V_1 ) ;
if ( V_69 ) {
F_237 ( V_62 , L_32 ) ;
return V_69 ;
}
F_277 ( V_1 ) ;
F_270 ( V_1 ) ;
V_69 = F_259 ( V_1 ) ;
if ( V_69 ) {
F_237 ( V_62 , L_33
L_34 ) ;
return V_69 ;
}
V_69 = F_278 ( V_1 ) ;
if ( V_69 ) {
F_237 ( V_62 , L_35 ) ;
goto V_357;
}
F_256 ( V_1 ) ;
V_69 = F_251 ( V_1 ) ;
if ( V_69 ) {
F_237 ( V_62 , L_36 ) ;
goto V_357;
}
switch ( F_171 ( V_1 -> V_14 ) ) {
default:
F_279 ( V_26 , & V_1 -> V_54 [ 0 ] , F_154 , 64 ) ;
F_280 ( & V_1 -> V_54 [ 0 ] ) ;
break;
case V_277 :
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
F_279 ( V_26 , & V_1 -> V_54 [ V_29 ] ,
F_179 , V_358 ) ;
F_280 ( & V_1 -> V_54 [ V_29 ] ) ;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ )
F_279 ( V_26 , & V_1 -> V_54 [ F_155 ( V_1 , V_29 ) ] ,
F_177 , V_358 ) ;
break;
}
return 0 ;
V_357:
F_263 ( V_1 ) ;
F_269 ( V_1 ) ;
return V_69 ;
}
static void F_281 ( struct V_1 * V_1 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < F_185 ( V_1 -> V_359 ) ; V_29 ++ )
if ( V_1 -> V_359 [ V_29 ] . V_360 )
F_282 ( V_1 -> V_359 [ V_29 ] . V_360 ) ;
}
static int F_283 ( struct V_361 * V_2 , const struct V_362 * V_363 )
{
struct V_3 * V_62 = & V_2 -> V_62 ;
struct V_36 * V_26 ;
struct V_1 * V_1 ;
int V_364 = 0 ;
unsigned int V_29 ;
int V_69 ;
#ifdef F_5
int V_365 = 0 ;
#endif
int V_366 = 1 ;
V_26 = F_284 ( sizeof( struct V_1 ) ,
V_367 , V_368 ) ;
if ( ! V_26 )
return - V_64 ;
F_285 ( V_2 , V_26 ) ;
F_286 ( V_26 , & V_2 -> V_62 ) ;
V_1 = F_40 ( V_26 ) ;
V_1 -> V_26 = V_26 ;
V_1 -> V_2 = V_2 ;
V_69 = F_287 ( V_2 ) ;
if ( V_69 ) {
F_237 ( V_62 , L_37 ) ;
goto V_369;
}
V_69 = F_288 ( V_2 , V_370 ) ;
if ( V_69 ) {
F_237 ( V_62 , L_38 ) ;
goto V_371;
}
F_289 ( V_2 ) ;
V_69 = F_290 ( V_2 , F_291 ( 64 ) ) ;
if ( V_69 ) {
V_69 = F_290 ( V_2 , F_291 ( 32 ) ) ;
if ( V_69 ) {
F_237 ( V_62 , L_39 ) ;
goto V_372;
}
V_69 = F_292 ( V_2 , F_291 ( 32 ) ) ;
if ( V_69 ) {
F_237 ( V_62 , L_40
L_41 , 32 ) ;
goto V_372;
}
} else {
V_69 = F_292 ( V_2 , F_291 ( 64 ) ) ;
if ( V_69 ) {
F_237 ( V_62 , L_40
L_41 , 64 ) ;
goto V_372;
}
V_364 = 1 ;
}
for ( V_29 = 0 ; V_29 < F_185 ( V_1 -> V_359 ) ; V_29 ++ ) {
if ( ! ( F_293 ( V_2 , V_29 ) & V_373 ) )
continue;
V_1 -> V_359 [ V_29 ] . V_17 = F_294 ( V_2 , V_29 ) ;
V_1 -> V_359 [ V_29 ] . V_360 = F_295 ( V_2 , V_29 , V_1 -> V_359 [ V_29 ] . V_17 ) ;
if ( ! V_1 -> V_359 [ V_29 ] . V_360 ) {
F_237 ( V_62 , L_42 , V_29 ) ;
V_69 = - V_374 ;
goto V_375;
}
V_1 -> V_359 [ V_29 ] . V_376 = F_296 ( V_2 , V_29 ) ;
}
V_1 -> V_14 = F_297 ( NULL , V_1 , V_2 , V_1 -> V_359 ,
F_185 ( V_1 -> V_359 ) ) ;
if ( ! V_1 -> V_14 ) {
F_237 ( V_62 , L_43 ) ;
V_69 = - V_374 ;
goto V_375;
}
#ifdef F_5
V_365 = F_298 ( V_2 , V_377 ) ;
if ( V_365 ) {
F_299 ( V_2 , V_365 + V_378 ,
& V_1 -> V_9 ) ;
if ( V_1 -> V_9 ) {
V_69 = F_300 ( V_2 , V_1 -> V_9 ) ;
if ( V_69 ) {
F_237 ( V_62 , L_44
L_45 ,
V_69 ) ;
goto V_379;
}
V_1 -> V_5 |= V_6 ;
V_366 = V_1 -> V_9 ;
}
}
#endif
V_1 -> V_154 = F_301 ( V_366 , sizeof( * V_1 -> V_154 ) , V_380 ) ;
if ( ! V_1 -> V_154 ) {
V_69 = - V_64 ;
goto V_381;
}
V_69 = F_236 ( V_1 ) ;
if ( V_69 ) {
F_237 ( V_62 , L_46 ) ;
goto V_382;
}
F_302 ( & V_1 -> V_306 ) ;
F_302 ( & V_1 -> V_346 ) ;
V_69 = F_257 ( V_1 ) ;
if ( V_69 ) {
F_237 ( V_62 ,
L_47 ) ;
goto V_383;
}
F_37 ( V_26 ) ;
if ( ! F_1 ( V_1 ) ) {
V_69 = F_303 ( V_1 -> V_14 , 0 ) ;
if ( V_69 ) {
F_237 ( V_62 , L_48 ) ;
goto V_383;
}
}
V_69 = F_273 ( V_1 ) ;
if ( V_69 ) {
F_237 ( V_62 , L_49 ) ;
goto V_383;
}
F_304 ( V_26 , V_1 -> V_31 ) ;
F_305 ( V_26 , V_1 -> V_32 ) ;
F_306 ( & V_1 -> V_284 ) ;
V_1 -> V_284 . V_384 = F_180 ;
V_1 -> V_284 . V_44 = ( unsigned long ) V_1 ;
F_190 ( V_1 ) ;
F_307 ( & V_1 -> V_52 , F_254 ) ;
F_307 ( & V_1 -> V_40 , F_224 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ )
F_302 ( & V_1 -> V_25 [ V_29 ] ) ;
V_1 -> V_37 = V_1 -> V_304 . V_35 ;
( void ) F_223 ( V_26 , V_1 -> V_37 ) ;
V_69 = F_104 ( V_26 , V_1 -> V_180 ) ;
if ( V_69 ) {
F_237 ( V_62 , L_50 ) ;
goto V_385;
}
V_1 -> V_386 = V_1 -> V_304 . V_305 ;
V_1 -> V_387 = V_1 -> V_386 ;
if ( F_1 ( V_1 ) || F_3 ( V_1 ) )
V_26 -> V_388 = & V_389 ;
else
V_26 -> V_388 = & V_390 ;
V_26 -> V_391 = 2 * V_316 ;
F_308 ( V_26 ) ;
V_26 -> V_233 |= V_392 | V_393 ;
if ( F_252 ( V_1 , V_394 ) ) {
V_26 -> V_233 &= ~ V_392 ;
V_1 -> V_84 = 1 ;
V_1 -> V_85 = V_1 -> V_304 . V_85 ;
F_272 ( V_62 , L_51 , V_1 -> V_85 ) ;
}
if ( F_252 ( V_1 , V_395 ) )
V_26 -> V_396 |= V_397 | V_398 ;
if ( F_252 ( V_1 , V_399 ) )
V_26 -> V_396 |= V_400 |
V_401 | V_402 ;
if ( F_252 ( V_1 , V_345 ) )
V_26 -> V_396 |= V_234 ;
if ( F_252 ( V_1 , V_403 ) )
V_26 -> V_396 |= V_240 ;
V_26 -> V_233 |= V_26 -> V_396 ;
#ifdef F_309
V_26 -> V_396 |= V_404 ;
#endif
if ( V_364 )
V_26 -> V_233 |= V_405 ;
V_26 -> V_5 |= V_406 ;
V_69 = F_310 ( V_26 ) ;
if ( V_69 ) {
F_237 ( V_62 , L_52 ) ;
goto V_385;
}
V_1 -> V_202 = V_407 ;
return 0 ;
V_385:
F_266 ( V_1 ) ;
V_383:
F_311 ( V_1 -> V_14 ) ;
V_382:
F_312 ( V_1 -> V_154 ) ;
V_381:
#ifdef F_5
if ( F_2 ( V_1 ) ) {
F_313 ( V_2 ) ;
V_1 -> V_5 &= ~ V_6 ;
}
V_379:
#endif
F_314 ( V_1 -> V_14 ) ;
V_375:
F_281 ( V_1 ) ;
V_372:
F_315 ( V_2 ) ;
V_371:
F_316 ( V_2 ) ;
V_369:
F_317 ( V_26 ) ;
return V_69 ;
}
static void F_318 ( struct V_361 * V_2 )
{
struct V_36 * V_26 = F_319 ( V_2 ) ;
if ( V_26 ) {
struct V_1 * V_1 = F_40 ( V_26 ) ;
F_320 ( & V_1 -> V_52 ) ;
F_320 ( & V_1 -> V_40 ) ;
F_321 ( V_26 ) ;
F_266 ( V_1 ) ;
F_311 ( V_1 -> V_14 ) ;
#ifdef F_5
if ( F_2 ( V_1 ) ) {
F_313 ( V_2 ) ;
V_1 -> V_5 &= ~ V_6 ;
}
#endif
F_312 ( V_1 -> V_154 ) ;
F_314 ( V_1 -> V_14 ) ;
F_281 ( V_1 ) ;
F_315 ( V_2 ) ;
F_316 ( V_2 ) ;
F_317 ( V_26 ) ;
}
}
static int T_10 F_322 ( void )
{
F_323 ( L_53 , V_408 , V_409 ) ;
return F_324 ( & V_410 ) ;
}
static void T_11 F_325 ( void )
{
F_326 ( & V_410 ) ;
}
