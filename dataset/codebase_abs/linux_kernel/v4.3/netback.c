static inline unsigned long F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_2 ( V_2 -> V_4 [ V_3 ] ) ;
}
static inline unsigned long F_3 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return ( unsigned long ) F_4 ( F_1 ( V_2 , V_3 ) ) ;
}
static inline struct V_1 * F_5 ( const struct V_5 * V_6 )
{
T_1 V_7 = V_6 -> V_8 ;
struct V_9 * V_10 =
F_6 ( V_6 , struct V_9 , V_11 ) ;
return F_6 ( V_10 - V_7 ,
struct V_1 ,
V_9 [ 0 ] ) ;
}
static T_1 F_7 ( T_2 * V_12 )
{
return ( T_1 ) V_12 -> V_13 ;
}
static void F_8 ( T_2 * V_12 , T_1 V_7 )
{
V_12 -> V_13 = V_7 ;
}
static inline T_3 F_9 ( unsigned V_14 )
{
return V_14 & ( V_15 - 1 ) ;
}
static int F_10 ( struct V_16 * V_17 )
{
if ( V_17 -> V_18 )
return F_11 ( V_17 -> V_19 -> V_20 , V_21 ) + 1 ;
else
return F_11 ( V_17 -> V_19 -> V_22 , V_21 ) ;
}
static bool F_12 ( struct V_1 * V_2 )
{
T_4 V_23 , V_24 ;
int V_25 ;
V_25 = F_10 ( V_2 -> V_17 ) ;
do {
V_23 = V_2 -> V_26 . V_27 -> V_28 ;
V_24 = V_2 -> V_26 . V_29 ;
if ( V_23 - V_24 >= V_25 )
return true ;
V_2 -> V_26 . V_27 -> V_30 = V_23 + 1 ;
F_13 () ;
} while ( V_2 -> V_26 . V_27 -> V_28 != V_23 );
return false ;
}
void F_14 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
unsigned long V_33 ;
F_15 ( & V_2 -> V_34 . V_35 , V_33 ) ;
F_16 ( & V_2 -> V_34 , V_32 ) ;
V_2 -> V_36 += V_32 -> V_37 ;
if ( V_2 -> V_36 > V_2 -> V_38 )
F_17 ( F_18 ( V_2 -> V_17 -> V_19 , V_2 -> V_39 ) ) ;
F_19 ( & V_2 -> V_34 . V_35 , V_33 ) ;
}
static struct V_31 * F_20 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
F_21 ( & V_2 -> V_34 . V_35 ) ;
V_32 = F_22 ( & V_2 -> V_34 ) ;
if ( V_32 )
V_2 -> V_36 -= V_32 -> V_37 ;
F_23 ( & V_2 -> V_34 . V_35 ) ;
return V_32 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_34 . V_35 ) ;
if ( V_2 -> V_36 < V_2 -> V_38 )
F_25 ( F_18 ( V_2 -> V_17 -> V_19 , V_2 -> V_39 ) ) ;
F_23 ( & V_2 -> V_34 . V_35 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
while ( ( V_32 = F_20 ( V_2 ) ) != NULL )
F_27 ( V_32 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
for(; ; ) {
V_32 = F_29 ( & V_2 -> V_34 ) ;
if ( ! V_32 )
break;
if ( F_30 ( V_40 , F_31 ( V_32 ) -> V_41 ) )
break;
F_20 ( V_2 ) ;
F_27 ( V_32 ) ;
}
}
static struct V_42 * F_32 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_42 * V_45 ;
struct V_46 * V_47 ;
V_47 = F_33 ( & V_2 -> V_26 , V_2 -> V_26 . V_29 ++ ) ;
V_45 = V_44 -> V_45 + V_44 -> V_48 ++ ;
V_45 -> V_49 = V_50 ;
V_45 -> V_51 = 0 ;
V_45 -> V_52 = 0 ;
V_45 -> V_39 = V_47 -> V_39 ;
V_44 -> V_53 = 0 ;
V_44 -> V_54 = V_47 -> V_55 ;
return V_45 ;
}
static void F_34 ( struct V_1 * V_2 , struct V_31 * V_32 ,
struct V_43 * V_44 ,
struct V_56 * V_56 , unsigned long V_52 ,
unsigned long V_57 , int * V_58 )
{
struct V_59 * V_60 ;
struct V_42 * V_45 ;
unsigned long V_61 ;
int V_49 = V_50 ;
F_35 ( V_52 + V_57 > V_21 << F_36 ( V_56 ) ) ;
V_45 = V_44 -> V_45 + V_44 -> V_48 - 1 ;
V_56 += V_57 >> V_62 ;
V_57 &= ~ V_63 ;
while ( V_52 > 0 ) {
struct V_64 * V_65 ;
F_35 ( V_57 >= V_21 ) ;
F_35 ( V_44 -> V_53 > V_66 ) ;
if ( V_44 -> V_53 == V_66 )
V_45 = F_32 ( V_2 , V_44 ) ;
V_61 = V_21 - V_57 ;
if ( V_61 > V_52 )
V_61 = V_52 ;
if ( V_44 -> V_53 + V_61 > V_66 )
V_61 = V_66 - V_44 -> V_53 ;
V_60 = V_44 -> V_67 + V_44 -> V_68 ++ ;
V_60 -> V_33 = V_69 ;
V_60 -> V_37 = V_61 ;
V_65 = V_64 ( V_56 ) ;
if ( V_65 ) {
V_60 -> V_70 . V_71 = V_65 -> V_71 ;
V_60 -> V_70 . V_72 . V_73 = V_65 -> V_55 ;
V_60 -> V_33 |= V_74 ;
} else {
V_60 -> V_70 . V_71 = V_75 ;
V_60 -> V_70 . V_72 . V_76 =
F_37 ( F_38 ( V_56 ) ) ;
}
V_60 -> V_70 . V_57 = V_57 ;
V_60 -> V_77 . V_71 = V_2 -> V_17 -> V_71 ;
V_60 -> V_77 . V_57 = V_44 -> V_53 ;
V_60 -> V_77 . V_72 . V_73 = V_44 -> V_54 ;
V_44 -> V_53 += V_61 ;
V_45 -> V_52 += V_61 ;
V_57 += V_61 ;
V_52 -= V_61 ;
if ( V_57 == V_21 && V_52 ) {
F_35 ( ! F_39 ( V_56 ) ) ;
V_56 ++ ;
V_57 = 0 ;
}
if ( F_40 ( V_32 ) ) {
if ( F_41 ( V_32 ) -> V_49 & V_78 )
V_49 = V_79 ;
else if ( F_41 ( V_32 ) -> V_49 & V_80 )
V_49 = V_81 ;
}
if ( * V_58 && ( ( 1 << V_49 ) & V_2 -> V_17 -> V_18 ) )
V_2 -> V_26 . V_29 ++ ;
* V_58 = 0 ;
}
}
static int F_42 ( struct V_31 * V_32 ,
struct V_43 * V_44 ,
struct V_1 * V_2 )
{
struct V_16 * V_17 = F_43 ( V_32 -> V_19 ) ;
int V_82 = F_41 ( V_32 ) -> V_82 ;
int V_14 ;
struct V_46 * V_47 ;
struct V_42 * V_45 ;
unsigned char * V_83 ;
int V_58 = 1 ;
int V_84 ;
int V_49 ;
V_84 = V_44 -> V_48 ;
V_49 = V_50 ;
if ( F_40 ( V_32 ) ) {
if ( F_41 ( V_32 ) -> V_49 & V_78 )
V_49 = V_79 ;
else if ( F_41 ( V_32 ) -> V_49 & V_80 )
V_49 = V_81 ;
}
if ( ( 1 << V_49 ) & V_17 -> V_85 ) {
V_47 = F_33 ( & V_2 -> V_26 , V_2 -> V_26 . V_29 ++ ) ;
V_45 = V_44 -> V_45 + V_44 -> V_48 ++ ;
V_45 -> V_49 = V_49 ;
V_45 -> V_51 = F_41 ( V_32 ) -> V_51 ;
V_45 -> V_52 = 0 ;
V_45 -> V_39 = V_47 -> V_39 ;
}
V_47 = F_33 ( & V_2 -> V_26 , V_2 -> V_26 . V_29 ++ ) ;
V_45 = V_44 -> V_45 + V_44 -> V_48 ++ ;
if ( ( 1 << V_49 ) & V_17 -> V_18 ) {
V_45 -> V_49 = V_49 ;
V_45 -> V_51 = F_41 ( V_32 ) -> V_51 ;
} else {
V_45 -> V_49 = V_50 ;
V_45 -> V_51 = 0 ;
}
V_45 -> V_52 = 0 ;
V_45 -> V_39 = V_47 -> V_39 ;
V_44 -> V_53 = 0 ;
V_44 -> V_54 = V_47 -> V_55 ;
V_83 = V_32 -> V_83 ;
while ( V_83 < F_44 ( V_32 ) ) {
unsigned int V_57 = F_45 ( V_83 ) ;
unsigned int V_37 = V_21 - V_57 ;
if ( V_83 + V_37 > F_44 ( V_32 ) )
V_37 = F_44 ( V_32 ) - V_83 ;
F_34 ( V_2 , V_32 , V_44 ,
F_46 ( V_83 ) , V_37 , V_57 , & V_58 ) ;
V_83 += V_37 ;
}
for ( V_14 = 0 ; V_14 < V_82 ; V_14 ++ ) {
F_34 ( V_2 , V_32 , V_44 ,
F_47 ( & F_41 ( V_32 ) -> V_86 [ V_14 ] ) ,
F_48 ( & F_41 ( V_32 ) -> V_86 [ V_14 ] ) ,
F_41 ( V_32 ) -> V_86 [ V_14 ] . V_13 ,
& V_58 ) ;
}
return V_44 -> V_48 - V_84 ;
}
static int F_49 ( struct V_16 * V_17 , int V_87 ,
struct V_43 * V_44 )
{
struct V_59 * V_88 ;
int V_89 = V_90 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_87 ; V_14 ++ ) {
V_88 = V_44 -> V_67 + V_44 -> V_91 ++ ;
if ( V_88 -> V_89 != V_92 ) {
F_50 ( V_17 -> V_19 ,
L_1 ,
V_88 -> V_89 , V_17 -> V_71 ) ;
V_89 = V_93 ;
}
}
return V_89 ;
}
static void F_51 ( struct V_1 * V_2 , int V_89 ,
struct V_42 * V_45 ,
int V_87 )
{
int V_14 ;
unsigned long V_57 ;
if ( V_87 <= 1 )
return;
V_87 -- ;
for ( V_14 = 0 ; V_14 < V_87 ; V_14 ++ ) {
int V_33 ;
if ( V_14 == V_87 - 1 )
V_33 = 0 ;
else
V_33 = V_94 ;
V_57 = 0 ;
F_52 ( V_2 , V_45 [ V_14 ] . V_39 , V_89 , V_57 ,
V_45 [ V_14 ] . V_52 , V_33 ) ;
}
}
void F_53 ( struct V_1 * V_2 )
{
F_54 ( & V_2 -> V_95 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
T_5 V_89 ;
T_1 V_33 ;
struct V_96 * V_97 ;
struct V_98 V_99 ;
struct V_31 * V_32 ;
F_56 ( V_100 ) ;
int V_101 ;
unsigned long V_57 ;
bool V_102 = false ;
struct V_43 V_44 = {
. V_67 = V_2 -> V_103 ,
. V_45 = V_2 -> V_45 ,
} ;
F_57 ( & V_99 ) ;
while ( F_12 ( V_2 )
&& ( V_32 = F_20 ( V_2 ) ) != NULL ) {
V_2 -> V_104 = V_40 ;
F_31 ( V_32 ) -> V_105 = F_42 ( V_32 , & V_44 , V_2 ) ;
F_16 ( & V_99 , V_32 ) ;
}
F_35 ( V_44 . V_48 > F_58 ( V_2 -> V_45 ) ) ;
if ( ! V_44 . V_68 )
goto V_106;
F_35 ( V_44 . V_68 > V_107 ) ;
F_59 ( V_2 -> V_103 , V_44 . V_68 ) ;
while ( ( V_32 = F_22 ( & V_99 ) ) != NULL ) {
if ( ( 1 << V_2 -> V_45 [ V_44 . V_108 ] . V_49 ) &
V_2 -> V_17 -> V_85 ) {
V_97 = F_60 ( & V_2 -> V_26 ,
V_2 -> V_26 . V_109 ++ ) ;
V_97 -> V_33 = V_110 | V_94 ;
V_97 -> V_57 = V_2 -> V_45 [ V_44 . V_108 ] . V_51 ;
V_97 -> V_39 = V_2 -> V_45 [ V_44 . V_108 ] . V_39 ;
V_97 -> V_89 = F_31 ( V_32 ) -> V_105 ;
V_44 . V_108 ++ ;
F_31 ( V_32 ) -> V_105 -- ;
}
V_2 -> V_111 . V_112 += V_32 -> V_37 ;
V_2 -> V_111 . V_113 ++ ;
V_89 = F_49 ( V_2 -> V_17 ,
F_31 ( V_32 ) -> V_105 ,
& V_44 ) ;
if ( F_31 ( V_32 ) -> V_105 == 1 )
V_33 = 0 ;
else
V_33 = V_94 ;
if ( V_32 -> V_114 == V_115 )
V_33 |= V_116 | V_117 ;
else if ( V_32 -> V_114 == V_118 )
V_33 |= V_117 ;
V_57 = 0 ;
V_97 = F_52 ( V_2 , V_2 -> V_45 [ V_44 . V_108 ] . V_39 ,
V_89 , V_57 ,
V_2 -> V_45 [ V_44 . V_108 ] . V_52 ,
V_33 ) ;
if ( ( 1 << V_2 -> V_45 [ V_44 . V_108 ] . V_49 ) &
V_2 -> V_17 -> V_18 ) {
struct V_119 * V_120 =
(struct V_119 * )
F_60 ( & V_2 -> V_26 ,
V_2 -> V_26 . V_109 ++ ) ;
V_97 -> V_33 |= V_121 ;
V_120 -> V_72 . V_120 . type = V_2 -> V_45 [ V_44 . V_108 ] . V_49 ;
V_120 -> V_72 . V_120 . V_52 = V_2 -> V_45 [ V_44 . V_108 ] . V_51 ;
V_120 -> V_72 . V_120 . V_122 = 0 ;
V_120 -> V_72 . V_120 . V_123 = 0 ;
V_120 -> type = V_124 ;
V_120 -> V_33 = 0 ;
}
F_51 ( V_2 , V_89 ,
V_2 -> V_45 + V_44 . V_108 + 1 ,
F_31 ( V_32 ) -> V_105 ) ;
F_61 ( & V_2 -> V_26 , V_101 ) ;
V_102 |= ! ! V_101 ;
V_44 . V_108 += F_31 ( V_32 ) -> V_105 ;
F_62 ( V_32 ) ;
}
V_106:
if ( V_102 )
F_63 ( V_2 -> V_125 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
int V_126 ;
F_65 ( & V_2 -> V_127 , V_126 ) ;
if ( V_126 )
F_66 ( & V_2 -> V_128 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
unsigned long V_129 , V_130 ;
V_129 = F_33 ( & V_2 -> V_127 , V_2 -> V_127 . V_29 ) -> V_52 ;
V_129 = F_68 ( V_129 , 131072UL ) ;
V_129 = F_69 ( V_129 , V_2 -> V_131 ) ;
V_130 = V_2 -> V_132 + V_2 -> V_131 ;
if ( V_130 < V_2 -> V_132 )
V_130 = V_133 ;
V_2 -> V_132 = F_68 ( V_130 , V_129 ) ;
}
void F_70 ( unsigned long V_83 )
{
struct V_1 * V_2 = (struct V_1 * ) V_83 ;
F_67 ( V_2 ) ;
F_64 ( V_2 ) ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_134 * V_135 , T_4 V_136 )
{
T_4 V_24 = V_2 -> V_127 . V_29 ;
unsigned long V_33 ;
do {
F_15 ( & V_2 -> V_137 , V_33 ) ;
F_72 ( V_2 , V_135 , V_93 ) ;
F_73 ( V_2 ) ;
F_19 ( & V_2 -> V_137 , V_33 ) ;
if ( V_24 == V_136 )
break;
V_135 = F_33 ( & V_2 -> V_127 , V_24 ++ ) ;
} while ( 1 );
V_2 -> V_127 . V_29 = V_24 ;
}
static void F_74 ( struct V_16 * V_17 )
{
F_75 ( V_17 -> V_19 , L_2 ) ;
V_17 -> V_138 = true ;
if ( V_17 -> V_139 )
F_53 ( & V_17 -> V_139 [ 0 ] ) ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_134 * V_140 ,
struct V_134 * V_135 ,
int V_141 )
{
T_4 V_24 = V_2 -> V_127 . V_29 ;
int V_142 = 0 ;
int V_143 = 0 ;
int V_144 ;
if ( ! ( V_140 -> V_33 & V_145 ) )
return 0 ;
do {
struct V_134 V_146 = { 0 } ;
if ( V_142 >= V_141 ) {
F_75 ( V_2 -> V_17 -> V_19 ,
L_3 ,
V_141 ) ;
F_74 ( V_2 -> V_17 ) ;
return - V_147 ;
}
if ( F_77 ( V_142 >= V_148 ) ) {
F_75 ( V_2 -> V_17 -> V_19 ,
L_4 ,
V_142 , V_148 ) ;
F_74 ( V_2 -> V_17 ) ;
return - V_149 ;
}
if ( ! V_143 && V_142 >= V_150 ) {
if ( F_78 () )
F_50 ( V_2 -> V_17 -> V_19 ,
L_5 ,
V_142 , V_150 ) ;
V_143 = - V_149 ;
}
if ( V_143 )
V_135 = & V_146 ;
memcpy ( V_135 , F_33 ( & V_2 -> V_127 , V_24 + V_142 ) ,
sizeof( * V_135 ) ) ;
if ( ! V_143 && V_135 -> V_52 > V_140 -> V_52 ) {
if ( F_78 () )
F_50 ( V_2 -> V_17 -> V_19 ,
L_6 ,
V_135 -> V_52 , V_140 -> V_52 ) ;
V_143 = - V_151 ;
}
V_140 -> V_52 -= V_135 -> V_52 ;
V_142 ++ ;
if ( F_77 ( ( V_135 -> V_57 + V_135 -> V_52 ) > V_21 ) ) {
F_75 ( V_2 -> V_17 -> V_19 , L_7 ,
V_135 -> V_57 , V_135 -> V_52 ) ;
F_74 ( V_2 -> V_17 ) ;
return - V_152 ;
}
V_144 = V_135 -> V_33 & V_145 ;
if ( ! V_143 )
V_135 ++ ;
} while ( V_144 );
if ( V_143 ) {
F_71 ( V_2 , V_140 , V_24 + V_142 ) ;
return V_143 ;
}
return V_142 ;
}
static inline void F_79 ( struct V_1 * V_2 ,
T_1 V_7 ,
struct V_134 * V_135 ,
struct V_153 * V_154 )
{
V_2 -> V_155 [ V_154 - V_2 -> V_156 ] = V_2 -> V_4 [ V_7 ] ;
F_80 ( V_154 , F_3 ( V_2 , V_7 ) ,
V_157 | V_158 ,
V_135 -> V_55 , V_2 -> V_17 -> V_71 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_47 , V_135 ,
sizeof( * V_135 ) ) ;
}
static inline struct V_31 * F_81 ( unsigned int V_52 )
{
struct V_31 * V_32 =
F_82 ( V_52 + V_159 + V_160 ,
V_161 | V_162 ) ;
if ( F_77 ( V_32 == NULL ) )
return NULL ;
F_83 ( V_32 , V_159 + V_160 ) ;
F_41 ( V_32 ) -> V_163 = NULL ;
return V_32 ;
}
static struct V_153 * F_84 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_134 * V_135 ,
struct V_153 * V_164 ,
unsigned int V_165 ,
struct V_31 * V_166 )
{
struct V_167 * V_168 = F_41 ( V_32 ) ;
T_2 * V_86 = V_168 -> V_86 ;
T_1 V_7 = F_85 ( V_32 ) -> V_7 ;
int V_169 ;
T_3 V_170 ;
unsigned int V_171 ;
V_171 = V_168 -> V_82 ;
V_169 = ( F_7 ( & V_168 -> V_86 [ 0 ] ) == V_7 ) ;
for ( V_168 -> V_82 = V_169 ; V_168 -> V_82 < V_171 ;
V_168 -> V_82 ++ , V_135 ++ , V_164 ++ ) {
V_170 = F_9 ( V_2 -> V_172 ++ ) ;
V_7 = V_2 -> V_173 [ V_170 ] ;
F_79 ( V_2 , V_7 , V_135 , V_164 ) ;
F_8 ( & V_86 [ V_168 -> V_82 ] , V_7 ) ;
}
if ( V_165 ) {
V_168 = F_41 ( V_166 ) ;
V_86 = V_168 -> V_86 ;
for ( V_168 -> V_82 = 0 ; V_168 -> V_82 < V_165 ;
V_168 -> V_82 ++ , V_135 ++ , V_164 ++ ) {
V_170 = F_9 ( V_2 -> V_172 ++ ) ;
V_7 = V_2 -> V_173 [ V_170 ] ;
F_79 ( V_2 , V_7 , V_135 , V_164 ) ;
F_8 ( & V_86 [ V_168 -> V_82 ] ,
V_7 ) ;
}
F_41 ( V_32 ) -> V_174 = V_166 ;
}
return V_164 ;
}
static inline void F_86 ( struct V_1 * V_2 ,
T_1 V_7 ,
T_6 V_175 )
{
if ( F_77 ( V_2 -> V_176 [ V_7 ] !=
V_177 ) ) {
F_75 ( V_2 -> V_17 -> V_19 ,
L_8 ,
V_7 ) ;
F_87 () ;
}
V_2 -> V_176 [ V_7 ] = V_175 ;
}
static inline void F_88 ( struct V_1 * V_2 ,
T_1 V_7 )
{
if ( F_77 ( V_2 -> V_176 [ V_7 ] ==
V_177 ) ) {
F_75 ( V_2 -> V_17 -> V_19 ,
L_9 ,
V_7 ) ;
F_87 () ;
}
V_2 -> V_176 [ V_7 ] = V_177 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_153 * * V_178 ,
struct V_59 * * V_179 )
{
struct V_153 * V_180 = * V_178 ;
T_1 V_7 = F_85 ( V_32 ) -> V_7 ;
struct V_167 * V_168 = F_41 ( V_32 ) ;
struct V_167 * V_181 = NULL ;
int V_82 = V_168 -> V_82 ;
const bool V_182 = V_82 &&
F_7 ( & V_168 -> V_86 [ 0 ] ) == V_7 ;
int V_14 , V_183 ;
V_183 = ( * V_179 ) -> V_89 ;
if ( F_77 ( V_183 ) ) {
if ( F_78 () )
F_50 ( V_2 -> V_17 -> V_19 ,
L_10 ,
( * V_179 ) -> V_89 ,
V_7 ,
( * V_179 ) -> V_70 . V_72 . V_73 ) ;
if ( ! V_182 )
F_90 ( V_2 , V_7 ,
V_93 ) ;
}
( * V_179 ) ++ ;
V_184:
for ( V_14 = 0 ; V_14 < V_82 ; V_14 ++ , V_180 ++ ) {
int V_185 , V_186 ;
V_7 = F_7 ( & V_168 -> V_86 [ V_14 ] ) ;
V_186 = V_180 -> V_89 ;
if ( F_91 ( ! V_186 ) ) {
F_86 ( V_2 ,
V_7 ,
V_180 -> V_175 ) ;
if ( F_77 ( V_183 ) ) {
F_92 ( V_2 , V_7 ) ;
if ( V_14 == 0 && V_182 )
F_90 ( V_2 , V_7 ,
V_93 ) ;
else
F_90 ( V_2 , V_7 ,
V_90 ) ;
}
continue;
}
if ( F_78 () )
F_50 ( V_2 -> V_17 -> V_19 ,
L_11 ,
V_14 ,
V_180 -> V_89 ,
V_7 ,
V_180 -> V_73 ) ;
F_90 ( V_2 , V_7 , V_93 ) ;
if ( V_183 )
continue;
if ( ! V_182 )
F_90 ( V_2 ,
F_85 ( V_32 ) -> V_7 ,
V_90 ) ;
for ( V_185 = 0 ; V_185 < V_14 ; V_185 ++ ) {
V_7 = F_7 ( & V_168 -> V_86 [ V_185 ] ) ;
F_92 ( V_2 , V_7 ) ;
F_90 ( V_2 , V_7 ,
V_90 ) ;
}
if ( V_181 ) {
for ( V_185 = 0 ; V_185 < V_181 -> V_82 ; V_185 ++ ) {
V_7 = F_7 ( & V_181 -> V_86 [ V_185 ] ) ;
F_92 ( V_2 , V_7 ) ;
F_90 ( V_2 , V_7 ,
V_90 ) ;
}
}
V_183 = V_186 ;
}
if ( F_93 ( V_32 ) && ! V_181 ) {
V_181 = F_41 ( V_32 ) ;
V_168 = F_41 ( F_41 ( V_32 ) -> V_174 ) ;
V_82 = V_168 -> V_82 ;
goto V_184;
}
* V_178 = V_180 ;
return V_183 ;
}
static void F_94 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_167 * V_168 = F_41 ( V_32 ) ;
int V_82 = V_168 -> V_82 ;
int V_14 ;
T_1 V_187 = V_188 ;
for ( V_14 = 0 ; V_14 < V_82 ; V_14 ++ ) {
T_2 * V_12 = V_168 -> V_86 + V_14 ;
struct V_134 * V_135 ;
struct V_56 * V_56 ;
T_1 V_7 ;
V_7 = F_7 ( V_12 ) ;
if ( V_187 == V_188 )
F_41 ( V_32 ) -> V_163 =
& F_95 ( V_2 , V_7 ) ;
else
F_95 ( V_2 , V_187 ) . V_189 =
& F_95 ( V_2 , V_7 ) ;
F_95 ( V_2 , V_7 ) . V_189 = NULL ;
V_187 = V_7 ;
V_135 = & V_2 -> V_9 [ V_7 ] . V_47 ;
V_56 = F_46 ( F_3 ( V_2 , V_7 ) ) ;
F_96 ( V_32 , V_14 , V_56 , V_135 -> V_57 , V_135 -> V_52 ) ;
V_32 -> V_37 += V_135 -> V_52 ;
V_32 -> V_190 += V_135 -> V_52 ;
V_32 -> V_191 += V_135 -> V_52 ;
F_97 ( V_2 -> V_4 [ V_7 ] ) ;
}
}
static int F_98 ( struct V_1 * V_2 ,
struct V_119 * V_192 ,
int V_141 )
{
struct V_119 V_193 ;
T_4 V_24 = V_2 -> V_127 . V_29 ;
do {
if ( F_77 ( V_141 -- <= 0 ) ) {
F_75 ( V_2 -> V_17 -> V_19 , L_12 ) ;
F_74 ( V_2 -> V_17 ) ;
return - V_194 ;
}
memcpy ( & V_193 , F_33 ( & V_2 -> V_127 , V_24 ) ,
sizeof( V_193 ) ) ;
if ( F_77 ( ! V_193 . type ||
V_193 . type >= V_195 ) ) {
V_2 -> V_127 . V_29 = ++ V_24 ;
F_75 ( V_2 -> V_17 -> V_19 ,
L_13 , V_193 . type ) ;
F_74 ( V_2 -> V_17 ) ;
return - V_152 ;
}
memcpy ( & V_192 [ V_193 . type - 1 ] , & V_193 , sizeof( V_193 ) ) ;
V_2 -> V_127 . V_29 = ++ V_24 ;
} while ( V_193 . V_33 & V_196 );
return V_141 ;
}
static int F_99 ( struct V_16 * V_17 ,
struct V_31 * V_32 ,
struct V_119 * V_120 )
{
if ( ! V_120 -> V_72 . V_120 . V_52 ) {
F_75 ( V_17 -> V_19 , L_14 ) ;
F_74 ( V_17 ) ;
return - V_152 ;
}
switch ( V_120 -> V_72 . V_120 . type ) {
case V_79 :
F_41 ( V_32 ) -> V_49 = V_78 ;
break;
case V_81 :
F_41 ( V_32 ) -> V_49 = V_80 ;
break;
default:
F_75 ( V_17 -> V_19 , L_15 , V_120 -> V_72 . V_120 . type ) ;
F_74 ( V_17 ) ;
return - V_152 ;
}
F_41 ( V_32 ) -> V_51 = V_120 -> V_72 . V_120 . V_52 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
bool V_197 = false ;
if ( V_32 -> V_114 != V_115 && F_40 ( V_32 ) ) {
V_2 -> V_111 . V_198 ++ ;
V_32 -> V_114 = V_115 ;
V_197 = true ;
}
if ( V_32 -> V_114 != V_115 )
return 0 ;
return F_101 ( V_32 , V_197 ) ;
}
static bool F_102 ( struct V_1 * V_2 , unsigned V_52 )
{
T_7 V_199 = F_103 () ;
T_7 V_200 = V_2 -> V_201 +
F_104 ( V_2 -> V_202 / 1000 ) ;
if ( F_105 ( & V_2 -> V_203 ) )
return true ;
if ( F_106 ( V_199 , V_200 ) ) {
V_2 -> V_201 = V_199 ;
F_67 ( V_2 ) ;
}
if ( V_52 > V_2 -> V_132 ) {
V_2 -> V_203 . V_83 =
( unsigned long ) V_2 ;
F_107 ( & V_2 -> V_203 ,
V_200 ) ;
V_2 -> V_201 = V_200 ;
return true ;
}
return false ;
}
static int F_108 ( struct V_16 * V_17 , const T_8 * V_204 )
{
struct V_205 * V_206 ;
if ( V_17 -> V_207 == V_208 ) {
if ( F_78 () )
F_75 ( V_17 -> V_19 ,
L_16 ) ;
return - V_209 ;
}
V_206 = F_109 ( sizeof( * V_206 ) , V_161 ) ;
if ( ! V_206 )
return - V_210 ;
F_110 ( V_206 -> V_204 , V_204 ) ;
F_111 ( & V_206 -> V_211 , & V_17 -> V_212 ) ;
V_17 -> V_207 ++ ;
return 0 ;
}
static void F_112 ( struct V_16 * V_17 , const T_8 * V_204 )
{
struct V_205 * V_206 ;
F_113 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_114 ( V_204 , V_206 -> V_204 ) ) {
-- V_17 -> V_207 ;
F_115 ( & V_206 -> V_211 ) ;
F_116 ( V_206 , V_213 ) ;
break;
}
}
}
bool F_117 ( struct V_16 * V_17 , const T_8 * V_204 )
{
struct V_205 * V_206 ;
F_118 () ;
F_113 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_114 ( V_204 , V_206 -> V_204 ) ) {
F_119 () ;
return true ;
}
}
F_119 () ;
return false ;
}
void F_120 ( struct V_16 * V_17 )
{
while ( ! F_121 ( & V_17 -> V_212 ) ) {
struct V_205 * V_206 ;
V_206 = F_122 ( & V_17 -> V_212 ,
struct V_205 ,
V_211 ) ;
-- V_17 -> V_207 ;
F_123 ( & V_206 -> V_211 ) ;
F_124 ( V_206 ) ;
}
}
static void F_125 ( struct V_1 * V_2 ,
int V_214 ,
unsigned * V_215 ,
unsigned * V_216 )
{
struct V_153 * V_164 = V_2 -> V_156 ;
struct V_31 * V_32 , * V_166 ;
int V_101 ;
unsigned int V_165 ;
while ( F_126 ( & V_2 -> V_217 ) < V_214 ) {
struct V_134 V_218 ;
struct V_134 V_219 [ V_150 ] ;
struct V_119 V_192 [ V_195 - 1 ] ;
T_1 V_7 ;
T_4 V_3 ;
int V_141 ;
unsigned int V_190 ;
T_3 V_170 ;
if ( V_2 -> V_127 . V_27 -> V_28 - V_2 -> V_127 . V_29 >
V_220 ) {
F_75 ( V_2 -> V_17 -> V_19 ,
L_17
L_18 ,
V_2 -> V_127 . V_27 -> V_28 , V_2 -> V_127 . V_29 ,
V_220 ) ;
F_74 ( V_2 -> V_17 ) ;
break;
}
V_141 = F_127 ( & V_2 -> V_127 ) ;
if ( ! V_141 )
break;
V_3 = V_2 -> V_127 . V_29 ;
F_128 () ;
memcpy ( & V_218 , F_33 ( & V_2 -> V_127 , V_3 ) , sizeof( V_218 ) ) ;
if ( V_218 . V_52 > V_2 -> V_132 &&
F_102 ( V_2 , V_218 . V_52 ) )
break;
V_2 -> V_132 -= V_218 . V_52 ;
V_141 -- ;
V_2 -> V_127 . V_29 = ++ V_3 ;
memset ( V_192 , 0 , sizeof( V_192 ) ) ;
if ( V_218 . V_33 & V_221 ) {
V_141 = F_98 ( V_2 , V_192 ,
V_141 ) ;
V_3 = V_2 -> V_127 . V_29 ;
if ( F_77 ( V_141 < 0 ) )
break;
}
if ( V_192 [ V_222 - 1 ] . type ) {
struct V_119 * V_193 ;
V_193 = & V_192 [ V_222 - 1 ] ;
V_101 = F_108 ( V_2 -> V_17 , V_193 -> V_72 . V_206 . V_204 ) ;
F_72 ( V_2 , & V_218 ,
( V_101 == 0 ) ?
V_90 :
V_93 ) ;
F_73 ( V_2 ) ;
continue;
}
if ( V_192 [ V_223 - 1 ] . type ) {
struct V_119 * V_193 ;
V_193 = & V_192 [ V_223 - 1 ] ;
F_112 ( V_2 -> V_17 , V_193 -> V_72 . V_206 . V_204 ) ;
F_72 ( V_2 , & V_218 , V_90 ) ;
F_73 ( V_2 ) ;
continue;
}
V_101 = F_76 ( V_2 , & V_218 , V_219 , V_141 ) ;
if ( F_77 ( V_101 < 0 ) )
break;
V_3 += V_101 ;
if ( F_77 ( V_218 . V_52 < V_224 ) ) {
F_50 ( V_2 -> V_17 -> V_19 ,
L_19 , V_218 . V_52 ) ;
F_71 ( V_2 , & V_218 , V_3 ) ;
break;
}
if ( F_77 ( ( V_218 . V_57 + V_218 . V_52 ) > V_21 ) ) {
F_75 ( V_2 -> V_17 -> V_19 ,
L_20 ,
V_218 . V_57 , V_218 . V_52 ,
( unsigned long ) ( V_218 . V_57 & ~ V_63 ) + V_218 . V_52 ) ;
F_74 ( V_2 -> V_17 ) ;
break;
}
V_170 = F_9 ( V_2 -> V_172 ) ;
V_7 = V_2 -> V_173 [ V_170 ] ;
V_190 = ( V_218 . V_52 > V_225 &&
V_101 < V_150 ) ?
V_225 : V_218 . V_52 ;
V_32 = F_81 ( V_190 ) ;
if ( F_77 ( V_32 == NULL ) ) {
F_50 ( V_2 -> V_17 -> V_19 ,
L_21 ) ;
F_71 ( V_2 , & V_218 , V_3 ) ;
break;
}
F_41 ( V_32 ) -> V_82 = V_101 ;
if ( V_190 < V_218 . V_52 )
F_41 ( V_32 ) -> V_82 ++ ;
V_165 = 0 ;
V_166 = NULL ;
if ( F_41 ( V_32 ) -> V_82 > V_226 ) {
V_165 = F_41 ( V_32 ) -> V_82 - V_226 ;
F_35 ( V_165 > V_226 ) ;
F_41 ( V_32 ) -> V_82 = V_226 ;
V_166 = F_81 ( 0 ) ;
if ( F_77 ( V_166 == NULL ) ) {
F_27 ( V_32 ) ;
F_71 ( V_2 , & V_218 , V_3 ) ;
if ( F_78 () )
F_75 ( V_2 -> V_17 -> V_19 ,
L_22 ) ;
break;
}
}
if ( V_192 [ V_124 - 1 ] . type ) {
struct V_119 * V_120 ;
V_120 = & V_192 [ V_124 - 1 ] ;
if ( F_99 ( V_2 -> V_17 , V_32 , V_120 ) ) {
F_27 ( V_32 ) ;
F_27 ( V_166 ) ;
break;
}
}
F_85 ( V_32 ) -> V_7 = V_7 ;
F_129 ( V_32 , V_190 ) ;
V_2 -> V_227 [ * V_215 ] . V_70 . V_72 . V_73 = V_218 . V_55 ;
V_2 -> V_227 [ * V_215 ] . V_70 . V_71 = V_2 -> V_17 -> V_71 ;
V_2 -> V_227 [ * V_215 ] . V_70 . V_57 = V_218 . V_57 ;
V_2 -> V_227 [ * V_215 ] . V_77 . V_72 . V_76 =
F_37 ( V_32 -> V_83 ) ;
V_2 -> V_227 [ * V_215 ] . V_77 . V_71 = V_75 ;
V_2 -> V_227 [ * V_215 ] . V_77 . V_57 =
F_45 ( V_32 -> V_83 ) ;
V_2 -> V_227 [ * V_215 ] . V_37 = V_190 ;
V_2 -> V_227 [ * V_215 ] . V_33 = V_74 ;
( * V_215 ) ++ ;
if ( V_190 < V_218 . V_52 ) {
F_8 ( & F_41 ( V_32 ) -> V_86 [ 0 ] ,
V_7 ) ;
F_79 ( V_2 , V_7 , & V_218 , V_164 ) ;
V_164 ++ ;
} else {
F_8 ( & F_41 ( V_32 ) -> V_86 [ 0 ] ,
V_188 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_47 , & V_218 ,
sizeof( V_218 ) ) ;
}
V_2 -> V_172 ++ ;
V_164 = F_84 ( V_2 , V_32 , V_219 , V_164 ,
V_165 , V_166 ) ;
F_16 ( & V_2 -> V_217 , V_32 ) ;
V_2 -> V_127 . V_29 = V_3 ;
if ( ( ( V_164 - V_2 -> V_156 ) >= F_58 ( V_2 -> V_156 ) ) ||
( * V_215 >= F_58 ( V_2 -> V_227 ) ) )
break;
}
( * V_216 ) = V_164 - V_2 -> V_156 ;
return;
}
static int F_130 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
unsigned int V_57 = F_131 ( V_32 ) ;
T_2 V_86 [ V_226 ] ;
int V_14 , V_228 ;
struct V_5 * V_229 ;
struct V_31 * V_166 = F_41 ( V_32 ) -> V_174 ;
V_2 -> V_111 . V_230 += 2 ;
V_2 -> V_111 . V_231 ++ ;
F_94 ( V_2 , V_166 ) ;
V_32 -> V_191 -= V_32 -> V_190 ;
V_32 -> V_37 += V_166 -> V_37 ;
V_32 -> V_190 += V_166 -> V_37 ;
for ( V_14 = 0 ; V_57 < V_32 -> V_37 ; V_14 ++ ) {
struct V_56 * V_56 ;
unsigned int V_37 ;
F_35 ( V_14 >= V_226 ) ;
V_56 = F_132 ( V_161 ) ;
if ( ! V_56 ) {
int V_185 ;
V_32 -> V_191 += V_32 -> V_190 ;
for ( V_185 = 0 ; V_185 < V_14 ; V_185 ++ )
F_133 ( V_86 [ V_185 ] . V_56 . V_232 ) ;
return - V_210 ;
}
if ( V_57 + V_21 < V_32 -> V_37 )
V_37 = V_21 ;
else
V_37 = V_32 -> V_37 - V_57 ;
if ( F_134 ( V_32 , V_57 , F_38 ( V_56 ) , V_37 ) )
F_87 () ;
V_57 += V_37 ;
V_86 [ V_14 ] . V_56 . V_232 = V_56 ;
V_86 [ V_14 ] . V_13 = 0 ;
F_135 ( & V_86 [ V_14 ] , V_37 ) ;
}
F_136 ( V_32 ) ;
F_137 ( V_2 , V_166 ) ;
F_27 ( V_166 ) ;
for ( V_228 = 0 ; V_228 < F_41 ( V_32 ) -> V_82 ; V_228 ++ )
F_138 ( V_32 , V_228 ) ;
V_229 = F_41 ( V_32 ) -> V_163 ;
F_139 ( & V_2 -> V_233 ) ;
V_229 -> V_234 ( V_229 , true ) ;
F_41 ( V_32 ) -> V_163 = NULL ;
memcpy ( F_41 ( V_32 ) -> V_86 , V_86 , V_14 * sizeof( T_2 ) ) ;
F_41 ( V_32 ) -> V_82 = V_14 ;
V_32 -> V_191 += V_14 * V_21 ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 )
{
struct V_153 * V_180 = V_2 -> V_156 ;
struct V_59 * V_235 = V_2 -> V_227 ;
struct V_31 * V_32 ;
int V_236 = 0 ;
while ( ( V_32 = F_22 ( & V_2 -> V_217 ) ) != NULL ) {
struct V_134 * V_135 ;
T_1 V_7 ;
unsigned V_190 ;
V_7 = F_85 ( V_32 ) -> V_7 ;
V_135 = & V_2 -> V_9 [ V_7 ] . V_47 ;
if ( F_77 ( F_89 ( V_2 , V_32 , & V_180 , & V_235 ) ) ) {
F_41 ( V_32 ) -> V_82 = 0 ;
if ( F_93 ( V_32 ) ) {
struct V_31 * V_166 =
F_41 ( V_32 ) -> V_174 ;
F_41 ( V_166 ) -> V_82 = 0 ;
}
F_27 ( V_32 ) ;
continue;
}
V_190 = V_32 -> V_37 ;
F_95 ( V_2 , V_7 ) . V_189 = NULL ;
if ( V_190 < V_135 -> V_52 ) {
V_135 -> V_57 += V_190 ;
V_135 -> V_52 -= V_190 ;
} else {
F_90 ( V_2 , V_7 ,
V_90 ) ;
}
if ( V_135 -> V_33 & V_237 )
V_32 -> V_114 = V_115 ;
else if ( V_135 -> V_33 & V_238 )
V_32 -> V_114 = V_118 ;
F_94 ( V_2 , V_32 ) ;
if ( F_77 ( F_93 ( V_32 ) ) ) {
if ( F_130 ( V_2 , V_32 ) ) {
if ( F_78 () )
F_75 ( V_2 -> V_17 -> V_19 ,
L_23 ) ;
F_137 ( V_2 , V_32 ) ;
F_27 ( V_32 ) ;
continue;
}
}
V_32 -> V_19 = V_2 -> V_17 -> V_19 ;
V_32 -> V_239 = F_141 ( V_32 , V_32 -> V_19 ) ;
F_142 ( V_32 ) ;
if ( F_100 ( V_2 , V_32 ) ) {
F_50 ( V_2 -> V_17 -> V_19 ,
L_24 ) ;
if ( F_41 ( V_32 ) -> V_163 )
F_137 ( V_2 , V_32 ) ;
F_27 ( V_32 ) ;
continue;
}
F_143 ( V_32 , 0 ) ;
if ( F_40 ( V_32 ) ) {
int V_240 = F_41 ( V_32 ) -> V_51 ;
int V_241 = F_144 ( V_32 ) -
F_145 ( V_32 ) +
F_146 ( V_32 ) ;
F_41 ( V_32 ) -> V_242 =
F_11 ( V_32 -> V_37 - V_241 , V_240 ) ;
}
V_2 -> V_111 . V_243 += V_32 -> V_37 ;
V_2 -> V_111 . V_244 ++ ;
V_236 ++ ;
if ( F_41 ( V_32 ) -> V_163 ) {
F_137 ( V_2 , V_32 ) ;
V_2 -> V_111 . V_230 ++ ;
}
F_147 ( V_32 ) ;
}
return V_236 ;
}
void F_148 ( struct V_5 * V_6 , bool V_245 )
{
unsigned long V_33 ;
T_3 V_170 ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
F_15 ( & V_2 -> V_246 , V_33 ) ;
do {
T_1 V_7 = V_6 -> V_8 ;
V_6 = (struct V_5 * ) V_6 -> V_189 ;
F_35 ( V_2 -> V_247 - V_2 -> V_248 >=
V_15 ) ;
V_170 = F_9 ( V_2 -> V_247 ) ;
V_2 -> V_249 [ V_170 ] = V_7 ;
F_149 () ;
V_2 -> V_247 ++ ;
} while ( V_6 );
F_19 ( & V_2 -> V_246 , V_33 ) ;
if ( F_91 ( V_245 ) )
V_2 -> V_111 . V_250 ++ ;
else
V_2 -> V_111 . V_251 ++ ;
F_150 ( V_2 ) ;
}
static inline void F_151 ( struct V_1 * V_2 )
{
struct V_252 * V_164 ;
T_3 V_253 , V_254 ;
T_1 V_7 , V_255 [ V_15 ] ;
unsigned int V_14 = 0 ;
V_253 = V_2 -> V_248 ;
V_164 = V_2 -> V_256 ;
do {
V_254 = V_2 -> V_247 ;
F_152 () ;
while ( V_253 != V_254 ) {
F_35 ( V_164 - V_2 -> V_256 >= V_15 ) ;
V_7 =
V_2 -> V_249 [ F_9 ( V_253 ++ ) ] ;
V_255 [ V_164 - V_2 -> V_256 ] =
V_7 ;
V_2 -> V_257 [ V_164 - V_2 -> V_256 ] =
V_2 -> V_4 [ V_7 ] ;
F_153 ( V_164 ,
F_3 ( V_2 , V_7 ) ,
V_157 ,
V_2 -> V_176 [ V_7 ] ) ;
F_88 ( V_2 , V_7 ) ;
++ V_164 ;
}
} while ( V_254 != V_2 -> V_247 );
V_2 -> V_248 = V_253 ;
if ( V_164 - V_2 -> V_256 > 0 ) {
int V_101 ;
V_101 = F_154 ( V_2 -> V_256 ,
NULL ,
V_2 -> V_257 ,
V_164 - V_2 -> V_256 ) ;
if ( V_101 ) {
F_75 ( V_2 -> V_17 -> V_19 , L_25 ,
V_164 - V_2 -> V_256 , V_101 ) ;
for ( V_14 = 0 ; V_14 < V_164 - V_2 -> V_256 ; ++ V_14 ) {
if ( V_164 [ V_14 ] . V_89 != V_92 )
F_75 ( V_2 -> V_17 -> V_19 ,
L_26 ,
V_164 [ V_14 ] . V_258 ,
V_164 [ V_14 ] . V_175 ,
V_164 [ V_14 ] . V_89 ) ;
}
F_87 () ;
}
}
for ( V_14 = 0 ; V_14 < V_164 - V_2 -> V_256 ; ++ V_14 )
F_90 ( V_2 , V_255 [ V_14 ] ,
V_90 ) ;
}
int F_155 ( struct V_1 * V_2 , int V_214 )
{
unsigned V_259 , V_260 = 0 ;
int V_236 , V_101 ;
if ( F_77 ( ! F_156 ( V_2 ) ) )
return 0 ;
F_125 ( V_2 , V_214 , & V_260 , & V_259 ) ;
if ( V_260 == 0 )
return 0 ;
F_59 ( V_2 -> V_227 , V_260 ) ;
if ( V_259 != 0 ) {
V_101 = F_157 ( V_2 -> V_156 ,
NULL ,
V_2 -> V_155 ,
V_259 ) ;
F_35 ( V_101 ) ;
}
V_236 = F_140 ( V_2 ) ;
return V_236 ;
}
static void F_90 ( struct V_1 * V_2 , T_1 V_7 ,
T_8 V_89 )
{
struct V_9 * V_9 ;
T_3 V_170 ;
unsigned long V_33 ;
V_9 = & V_2 -> V_9 [ V_7 ] ;
F_15 ( & V_2 -> V_137 , V_33 ) ;
F_72 ( V_2 , & V_9 -> V_47 , V_89 ) ;
V_170 = F_9 ( V_2 -> V_261 ++ ) ;
V_2 -> V_173 [ V_170 ] = V_7 ;
F_73 ( V_2 ) ;
F_19 ( & V_2 -> V_137 , V_33 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_134 * V_135 ,
T_5 V_262 )
{
T_4 V_14 = V_2 -> V_127 . V_109 ;
struct V_263 * V_97 ;
V_97 = F_60 ( & V_2 -> V_127 , V_14 ) ;
V_97 -> V_39 = V_135 -> V_39 ;
V_97 -> V_89 = V_262 ;
if ( V_135 -> V_33 & V_221 )
F_60 ( & V_2 -> V_127 , ++ V_14 ) -> V_89 = V_264 ;
V_2 -> V_127 . V_109 = ++ V_14 ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_100 ;
F_61 ( & V_2 -> V_127 , V_100 ) ;
if ( V_100 )
F_63 ( V_2 -> V_265 ) ;
}
static struct V_96 * F_52 ( struct V_1 * V_2 ,
T_1 V_39 ,
T_5 V_262 ,
T_1 V_57 ,
T_1 V_52 ,
T_1 V_33 )
{
T_4 V_14 = V_2 -> V_26 . V_109 ;
struct V_96 * V_97 ;
V_97 = F_60 ( & V_2 -> V_26 , V_14 ) ;
V_97 -> V_57 = V_57 ;
V_97 -> V_33 = V_33 ;
V_97 -> V_39 = V_39 ;
V_97 -> V_89 = ( V_266 ) V_52 ;
if ( V_262 < 0 )
V_97 -> V_89 = ( V_266 ) V_262 ;
V_2 -> V_26 . V_109 = ++ V_14 ;
return V_97 ;
}
void F_92 ( struct V_1 * V_2 , T_1 V_7 )
{
int V_101 ;
struct V_252 V_267 ;
F_153 ( & V_267 ,
F_3 ( V_2 , V_7 ) ,
V_157 ,
V_2 -> V_176 [ V_7 ] ) ;
F_88 ( V_2 , V_7 ) ;
V_101 = F_154 ( & V_267 , NULL ,
& V_2 -> V_4 [ V_7 ] , 1 ) ;
if ( V_101 ) {
F_75 ( V_2 -> V_17 -> V_19 ,
L_27 ,
V_101 ,
V_7 ,
V_267 . V_258 ,
V_267 . V_175 ,
V_267 . V_89 ) ;
F_87 () ;
}
}
static inline int F_156 ( struct V_1 * V_2 )
{
if ( F_91 ( F_127 ( & V_2 -> V_127 ) ) )
return 1 ;
return 0 ;
}
static inline bool F_158 ( struct V_1 * V_2 )
{
return V_2 -> V_248 != V_2 -> V_247 ;
}
void F_159 ( struct V_1 * V_2 )
{
if ( V_2 -> V_127 . V_27 )
F_160 ( F_161 ( V_2 -> V_17 ) ,
V_2 -> V_127 . V_27 ) ;
if ( V_2 -> V_26 . V_27 )
F_160 ( F_161 ( V_2 -> V_17 ) ,
V_2 -> V_26 . V_27 ) ;
}
int F_162 ( struct V_1 * V_2 ,
T_9 V_268 ,
T_9 V_269 )
{
void * V_204 ;
struct V_270 * V_271 ;
struct V_272 * V_273 ;
int V_183 = - V_210 ;
V_183 = F_163 ( F_161 ( V_2 -> V_17 ) ,
& V_268 , 1 , & V_204 ) ;
if ( V_183 )
goto V_183;
V_271 = (struct V_270 * ) V_204 ;
F_164 ( & V_2 -> V_127 , V_271 , V_21 ) ;
V_183 = F_163 ( F_161 ( V_2 -> V_17 ) ,
& V_269 , 1 , & V_204 ) ;
if ( V_183 )
goto V_183;
V_273 = (struct V_272 * ) V_204 ;
F_164 ( & V_2 -> V_26 , V_273 , V_21 ) ;
return 0 ;
V_183:
F_159 ( V_2 ) ;
return V_183 ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
V_2 -> V_274 = true ;
F_166 ( & V_17 -> V_35 ) ;
if ( V_17 -> V_275 ++ == 0 ) {
F_167 ( V_17 -> V_19 , L_28 ) ;
F_168 ( V_17 -> V_19 ) ;
}
F_169 ( & V_17 -> V_35 ) ;
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
V_2 -> V_104 = V_40 ;
V_2 -> V_274 = false ;
F_166 ( & V_17 -> V_35 ) ;
if ( -- V_17 -> V_275 == 0 ) {
F_167 ( V_17 -> V_19 , L_29 ) ;
F_171 ( V_17 -> V_19 ) ;
}
F_169 ( & V_17 -> V_35 ) ;
}
static bool F_172 ( struct V_1 * V_2 )
{
T_4 V_23 , V_24 ;
V_23 = V_2 -> V_26 . V_27 -> V_28 ;
V_24 = V_2 -> V_26 . V_29 ;
return ! V_2 -> V_274 && V_23 - V_24 < 1
&& F_173 ( V_40 ,
V_2 -> V_104 + V_2 -> V_17 -> V_276 ) ;
}
static bool F_174 ( struct V_1 * V_2 )
{
T_4 V_23 , V_24 ;
V_23 = V_2 -> V_26 . V_27 -> V_28 ;
V_24 = V_2 -> V_26 . V_29 ;
return V_2 -> V_274 && V_23 - V_24 >= 1 ;
}
static bool F_175 ( struct V_1 * V_2 )
{
return ( ! F_176 ( & V_2 -> V_34 )
&& F_12 ( V_2 ) )
|| ( V_2 -> V_17 -> V_276 &&
( F_172 ( V_2 )
|| F_174 ( V_2 ) ) )
|| F_177 ()
|| V_2 -> V_17 -> V_138 ;
}
static long F_178 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
long V_277 ;
V_32 = F_29 ( & V_2 -> V_34 ) ;
if ( ! V_32 )
return V_278 ;
V_277 = F_31 ( V_32 ) -> V_41 - V_40 ;
return V_277 < 0 ? 0 : V_277 ;
}
static void F_179 ( struct V_1 * V_2 )
{
F_180 ( V_279 ) ;
if ( F_175 ( V_2 ) )
return;
for (; ; ) {
long V_101 ;
F_181 ( & V_2 -> V_95 , & V_279 , V_280 ) ;
if ( F_175 ( V_2 ) )
break;
V_101 = F_182 ( F_178 ( V_2 ) ) ;
if ( ! V_101 )
break;
}
F_183 ( & V_2 -> V_95 , & V_279 ) ;
}
int F_184 ( void * V_83 )
{
struct V_1 * V_2 = V_83 ;
struct V_16 * V_17 = V_2 -> V_17 ;
if ( ! V_17 -> V_276 )
F_170 ( V_2 ) ;
for (; ; ) {
F_179 ( V_2 ) ;
if ( F_177 () )
break;
if ( F_77 ( V_17 -> V_138 && V_2 -> V_39 == 0 ) ) {
F_185 ( V_17 ) ;
break;
}
if ( ! F_176 ( & V_2 -> V_34 ) )
F_55 ( V_2 ) ;
if ( V_17 -> V_276 ) {
if ( F_172 ( V_2 ) )
F_165 ( V_2 ) ;
else if ( F_174 ( V_2 ) )
F_170 ( V_2 ) ;
}
F_28 ( V_2 ) ;
F_24 ( V_2 ) ;
F_186 () ;
}
F_26 ( V_2 ) ;
return 0 ;
}
static bool F_187 ( struct V_1 * V_2 )
{
return F_177 () &&
! F_188 ( & V_2 -> V_233 ) ;
}
int F_189 ( void * V_83 )
{
struct V_1 * V_2 = V_83 ;
for (; ; ) {
F_190 ( V_2 -> V_281 ,
F_158 ( V_2 ) ||
F_187 ( V_2 ) ) ;
if ( F_187 ( V_2 ) )
break;
F_151 ( V_2 ) ;
F_186 () ;
}
if ( F_158 ( V_2 ) )
F_151 ( V_2 ) ;
return 0 ;
}
static int T_10 F_191 ( void )
{
int V_282 = 0 ;
if ( ! F_192 () )
return - V_283 ;
if ( V_284 == 0 )
V_284 = F_193 () ;
if ( V_148 < V_150 ) {
F_194 ( L_30 ,
V_148 , V_150 ) ;
V_148 = V_150 ;
}
V_282 = F_195 () ;
if ( V_282 )
goto V_285;
#ifdef F_196
V_286 = F_197 ( L_31 , NULL ) ;
if ( F_198 ( V_286 ) )
F_199 ( L_32 ,
F_200 ( V_286 ) ) ;
#endif
return 0 ;
V_285:
return V_282 ;
}
static void T_11 F_201 ( void )
{
#ifdef F_196
if ( ! F_198 ( V_286 ) )
F_202 ( V_286 ) ;
#endif
F_203 () ;
}
