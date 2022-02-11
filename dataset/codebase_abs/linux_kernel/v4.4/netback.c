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
struct V_46 V_47 ;
F_33 ( & V_2 -> V_26 , V_2 -> V_26 . V_29 ++ , & V_47 ) ;
V_45 = V_44 -> V_45 + V_44 -> V_48 ++ ;
V_45 -> V_49 = V_50 ;
V_45 -> V_51 = 0 ;
V_45 -> V_52 = 0 ;
V_45 -> V_39 = V_47 . V_39 ;
V_44 -> V_53 = 0 ;
V_44 -> V_54 = V_47 . V_55 ;
return V_45 ;
}
static void F_34 ( unsigned long V_56 ,
unsigned int V_57 ,
unsigned int * V_37 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 ;
struct V_62 * V_63 ;
struct V_1 * V_2 = V_59 -> V_2 ;
struct V_43 * V_44 = V_59 -> V_44 ;
struct V_64 * V_64 = V_59 -> V_64 ;
F_35 ( V_44 -> V_53 > V_65 ) ;
if ( V_44 -> V_53 == V_65 )
V_59 -> V_45 = F_32 ( V_2 , V_44 ) ;
if ( V_44 -> V_53 + * V_37 > V_65 )
* V_37 = V_65 - V_44 -> V_53 ;
V_61 = V_44 -> V_66 + V_44 -> V_67 ++ ;
V_61 -> V_33 = V_68 ;
V_61 -> V_37 = * V_37 ;
V_63 = V_62 ( V_64 ) ;
if ( V_63 ) {
V_61 -> V_69 . V_70 = V_63 -> V_70 ;
V_61 -> V_69 . V_71 . V_72 = V_63 -> V_55 ;
V_61 -> V_33 |= V_73 ;
} else {
V_61 -> V_69 . V_70 = V_74 ;
V_61 -> V_69 . V_71 . V_75 = V_56 ;
}
V_61 -> V_69 . V_57 = V_57 ;
V_61 -> V_76 . V_70 = V_2 -> V_17 -> V_70 ;
V_61 -> V_76 . V_57 = V_44 -> V_53 ;
V_61 -> V_76 . V_71 . V_72 = V_44 -> V_54 ;
V_44 -> V_53 += * V_37 ;
V_59 -> V_45 -> V_52 += * V_37 ;
if ( V_59 -> V_77 && ( ( 1 << V_59 -> V_49 ) & V_2 -> V_17 -> V_18 ) )
V_2 -> V_26 . V_29 ++ ;
V_59 -> V_77 = 0 ;
}
static void F_36 ( unsigned long V_56 ,
unsigned V_57 ,
unsigned int V_37 ,
void * V_78 )
{
unsigned int V_79 ;
while ( V_37 ) {
V_79 = V_37 ;
F_34 ( V_56 , V_57 , & V_79 , V_78 ) ;
V_57 += V_79 ;
V_37 -= V_79 ;
}
}
static void F_37 ( struct V_1 * V_2 , struct V_31 * V_32 ,
struct V_43 * V_44 ,
struct V_64 * V_64 , unsigned long V_52 ,
unsigned long V_57 , int * V_77 )
{
struct V_58 V_59 = {
. V_2 = V_2 ,
. V_44 = V_44 ,
. V_77 = * V_77 ,
. V_49 = V_50 ,
} ;
unsigned long V_79 ;
if ( F_38 ( V_32 ) ) {
if ( F_39 ( V_32 ) -> V_49 & V_80 )
V_59 . V_49 = V_81 ;
else if ( F_39 ( V_32 ) -> V_49 & V_82 )
V_59 . V_49 = V_83 ;
}
F_35 ( V_52 + V_57 > V_84 << F_40 ( V_64 ) ) ;
V_59 . V_45 = V_44 -> V_45 + V_44 -> V_48 - 1 ;
V_64 += V_57 >> V_85 ;
V_57 &= ~ V_86 ;
while ( V_52 > 0 ) {
F_35 ( V_57 >= V_84 ) ;
V_79 = V_84 - V_57 ;
if ( V_79 > V_52 )
V_79 = V_52 ;
V_59 . V_64 = V_64 ;
F_41 ( V_64 , V_57 , V_79 ,
F_36 ,
& V_59 ) ;
V_52 -= V_79 ;
V_57 = 0 ;
if ( V_52 ) {
F_35 ( ! F_42 ( V_64 ) ) ;
V_64 ++ ;
}
}
* V_77 = V_59 . V_77 ;
}
static int F_43 ( struct V_31 * V_32 ,
struct V_43 * V_44 ,
struct V_1 * V_2 )
{
struct V_16 * V_17 = F_44 ( V_32 -> V_19 ) ;
int V_87 = F_39 ( V_32 ) -> V_87 ;
int V_14 ;
struct V_46 V_47 ;
struct V_42 * V_45 ;
unsigned char * V_78 ;
int V_77 = 1 ;
int V_88 ;
int V_49 ;
V_88 = V_44 -> V_48 ;
V_49 = V_50 ;
if ( F_38 ( V_32 ) ) {
if ( F_39 ( V_32 ) -> V_49 & V_80 )
V_49 = V_81 ;
else if ( F_39 ( V_32 ) -> V_49 & V_82 )
V_49 = V_83 ;
}
if ( ( 1 << V_49 ) & V_17 -> V_89 ) {
F_33 ( & V_2 -> V_26 , V_2 -> V_26 . V_29 ++ , & V_47 ) ;
V_45 = V_44 -> V_45 + V_44 -> V_48 ++ ;
V_45 -> V_49 = V_49 ;
V_45 -> V_51 = F_39 ( V_32 ) -> V_51 ;
V_45 -> V_52 = 0 ;
V_45 -> V_39 = V_47 . V_39 ;
}
F_33 ( & V_2 -> V_26 , V_2 -> V_26 . V_29 ++ , & V_47 ) ;
V_45 = V_44 -> V_45 + V_44 -> V_48 ++ ;
if ( ( 1 << V_49 ) & V_17 -> V_18 ) {
V_45 -> V_49 = V_49 ;
V_45 -> V_51 = F_39 ( V_32 ) -> V_51 ;
} else {
V_45 -> V_49 = V_50 ;
V_45 -> V_51 = 0 ;
}
V_45 -> V_52 = 0 ;
V_45 -> V_39 = V_47 . V_39 ;
V_44 -> V_53 = 0 ;
V_44 -> V_54 = V_47 . V_55 ;
V_78 = V_32 -> V_78 ;
while ( V_78 < F_45 ( V_32 ) ) {
unsigned int V_57 = F_46 ( V_78 ) ;
unsigned int V_37 = V_84 - V_57 ;
if ( V_78 + V_37 > F_45 ( V_32 ) )
V_37 = F_45 ( V_32 ) - V_78 ;
F_37 ( V_2 , V_32 , V_44 ,
F_47 ( V_78 ) , V_37 , V_57 , & V_77 ) ;
V_78 += V_37 ;
}
for ( V_14 = 0 ; V_14 < V_87 ; V_14 ++ ) {
F_37 ( V_2 , V_32 , V_44 ,
F_48 ( & F_39 ( V_32 ) -> V_90 [ V_14 ] ) ,
F_49 ( & F_39 ( V_32 ) -> V_90 [ V_14 ] ) ,
F_39 ( V_32 ) -> V_90 [ V_14 ] . V_13 ,
& V_77 ) ;
}
return V_44 -> V_48 - V_88 ;
}
static int F_50 ( struct V_16 * V_17 , int V_91 ,
struct V_43 * V_44 )
{
struct V_60 * V_92 ;
int V_93 = V_94 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_91 ; V_14 ++ ) {
V_92 = V_44 -> V_66 + V_44 -> V_95 ++ ;
if ( V_92 -> V_93 != V_96 ) {
F_51 ( V_17 -> V_19 ,
L_1 ,
V_92 -> V_93 , V_17 -> V_70 ) ;
V_93 = V_97 ;
}
}
return V_93 ;
}
static void F_52 ( struct V_1 * V_2 , int V_93 ,
struct V_42 * V_45 ,
int V_91 )
{
int V_14 ;
unsigned long V_57 ;
if ( V_91 <= 1 )
return;
V_91 -- ;
for ( V_14 = 0 ; V_14 < V_91 ; V_14 ++ ) {
int V_33 ;
if ( V_14 == V_91 - 1 )
V_33 = 0 ;
else
V_33 = V_98 ;
V_57 = 0 ;
F_53 ( V_2 , V_45 [ V_14 ] . V_39 , V_93 , V_57 ,
V_45 [ V_14 ] . V_52 , V_33 ) ;
}
}
void F_54 ( struct V_1 * V_2 )
{
F_55 ( & V_2 -> V_99 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
T_5 V_93 ;
T_1 V_33 ;
struct V_100 * V_101 ;
struct V_102 V_103 ;
struct V_31 * V_32 ;
F_57 ( V_104 ) ;
int V_105 ;
unsigned long V_57 ;
bool V_106 = false ;
struct V_43 V_44 = {
. V_66 = V_2 -> V_107 ,
. V_45 = V_2 -> V_45 ,
} ;
F_58 ( & V_103 ) ;
while ( F_12 ( V_2 )
&& ( V_32 = F_20 ( V_2 ) ) != NULL ) {
V_2 -> V_108 = V_40 ;
F_31 ( V_32 ) -> V_109 = F_43 ( V_32 , & V_44 , V_2 ) ;
F_16 ( & V_103 , V_32 ) ;
}
F_35 ( V_44 . V_48 > F_59 ( V_2 -> V_45 ) ) ;
if ( ! V_44 . V_67 )
goto V_110;
F_35 ( V_44 . V_67 > V_111 ) ;
F_60 ( V_2 -> V_107 , V_44 . V_67 ) ;
while ( ( V_32 = F_22 ( & V_103 ) ) != NULL ) {
if ( ( 1 << V_2 -> V_45 [ V_44 . V_112 ] . V_49 ) &
V_2 -> V_17 -> V_89 ) {
V_101 = F_61 ( & V_2 -> V_26 ,
V_2 -> V_26 . V_113 ++ ) ;
V_101 -> V_33 = V_114 | V_98 ;
V_101 -> V_57 = V_2 -> V_45 [ V_44 . V_112 ] . V_51 ;
V_101 -> V_39 = V_2 -> V_45 [ V_44 . V_112 ] . V_39 ;
V_101 -> V_93 = F_31 ( V_32 ) -> V_109 ;
V_44 . V_112 ++ ;
F_31 ( V_32 ) -> V_109 -- ;
}
V_2 -> V_115 . V_116 += V_32 -> V_37 ;
V_2 -> V_115 . V_117 ++ ;
V_93 = F_50 ( V_2 -> V_17 ,
F_31 ( V_32 ) -> V_109 ,
& V_44 ) ;
if ( F_31 ( V_32 ) -> V_109 == 1 )
V_33 = 0 ;
else
V_33 = V_98 ;
if ( V_32 -> V_118 == V_119 )
V_33 |= V_120 | V_121 ;
else if ( V_32 -> V_118 == V_122 )
V_33 |= V_121 ;
V_57 = 0 ;
V_101 = F_53 ( V_2 , V_2 -> V_45 [ V_44 . V_112 ] . V_39 ,
V_93 , V_57 ,
V_2 -> V_45 [ V_44 . V_112 ] . V_52 ,
V_33 ) ;
if ( ( 1 << V_2 -> V_45 [ V_44 . V_112 ] . V_49 ) &
V_2 -> V_17 -> V_18 ) {
struct V_123 * V_124 =
(struct V_123 * )
F_61 ( & V_2 -> V_26 ,
V_2 -> V_26 . V_113 ++ ) ;
V_101 -> V_33 |= V_125 ;
V_124 -> V_71 . V_124 . type = V_2 -> V_45 [ V_44 . V_112 ] . V_49 ;
V_124 -> V_71 . V_124 . V_52 = V_2 -> V_45 [ V_44 . V_112 ] . V_51 ;
V_124 -> V_71 . V_124 . V_126 = 0 ;
V_124 -> V_71 . V_124 . V_127 = 0 ;
V_124 -> type = V_128 ;
V_124 -> V_33 = 0 ;
}
F_52 ( V_2 , V_93 ,
V_2 -> V_45 + V_44 . V_112 + 1 ,
F_31 ( V_32 ) -> V_109 ) ;
F_62 ( & V_2 -> V_26 , V_105 ) ;
V_106 |= ! ! V_105 ;
V_44 . V_112 += F_31 ( V_32 ) -> V_109 ;
F_63 ( V_32 ) ;
}
V_110:
if ( V_106 )
F_64 ( V_2 -> V_129 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
int V_130 ;
F_66 ( & V_2 -> V_131 , V_130 ) ;
if ( V_130 )
F_67 ( & V_2 -> V_132 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
unsigned long V_133 , V_134 ;
V_133 = F_69 ( 131072UL , V_2 -> V_135 ) ;
V_134 = V_2 -> V_136 + V_2 -> V_135 ;
if ( V_134 < V_2 -> V_136 )
V_134 = V_137 ;
V_2 -> V_136 = F_70 ( V_134 , V_133 ) ;
}
void F_71 ( unsigned long V_78 )
{
struct V_1 * V_2 = (struct V_1 * ) V_78 ;
F_68 ( V_2 ) ;
F_65 ( V_2 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_138 * V_139 , T_4 V_140 )
{
T_4 V_24 = V_2 -> V_131 . V_29 ;
unsigned long V_33 ;
do {
F_15 ( & V_2 -> V_141 , V_33 ) ;
F_73 ( V_2 , V_139 , V_97 ) ;
F_74 ( V_2 ) ;
F_19 ( & V_2 -> V_141 , V_33 ) ;
if ( V_24 == V_140 )
break;
F_33 ( & V_2 -> V_131 , V_24 ++ , V_139 ) ;
} while ( 1 );
V_2 -> V_131 . V_29 = V_24 ;
}
static void F_75 ( struct V_16 * V_17 )
{
F_76 ( V_17 -> V_19 , L_2 ) ;
V_17 -> V_142 = true ;
if ( V_17 -> V_143 )
F_54 ( & V_17 -> V_143 [ 0 ] ) ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_138 * V_144 ,
struct V_138 * V_139 ,
int V_145 )
{
T_4 V_24 = V_2 -> V_131 . V_29 ;
int V_146 = 0 ;
int V_147 = 0 ;
int V_148 ;
if ( ! ( V_144 -> V_33 & V_149 ) )
return 0 ;
do {
struct V_138 V_150 = { 0 } ;
if ( V_146 >= V_145 ) {
F_76 ( V_2 -> V_17 -> V_19 ,
L_3 ,
V_145 ) ;
F_75 ( V_2 -> V_17 ) ;
return - V_151 ;
}
if ( F_78 ( V_146 >= V_152 ) ) {
F_76 ( V_2 -> V_17 -> V_19 ,
L_4 ,
V_146 , V_152 ) ;
F_75 ( V_2 -> V_17 ) ;
return - V_153 ;
}
if ( ! V_147 && V_146 >= V_154 ) {
if ( F_79 () )
F_51 ( V_2 -> V_17 -> V_19 ,
L_5 ,
V_146 , V_154 ) ;
V_147 = - V_153 ;
}
if ( V_147 )
V_139 = & V_150 ;
F_33 ( & V_2 -> V_131 , V_24 + V_146 , V_139 ) ;
if ( ! V_147 && V_139 -> V_52 > V_144 -> V_52 ) {
if ( F_79 () )
F_51 ( V_2 -> V_17 -> V_19 ,
L_6 ,
V_139 -> V_52 , V_144 -> V_52 ) ;
V_147 = - V_155 ;
}
V_144 -> V_52 -= V_139 -> V_52 ;
V_146 ++ ;
if ( F_78 ( ( V_139 -> V_57 + V_139 -> V_52 ) > V_21 ) ) {
F_76 ( V_2 -> V_17 -> V_19 , L_7 ,
V_139 -> V_57 , V_139 -> V_52 ) ;
F_75 ( V_2 -> V_17 ) ;
return - V_156 ;
}
V_148 = V_139 -> V_33 & V_149 ;
if ( ! V_147 )
V_139 ++ ;
} while ( V_148 );
if ( V_147 ) {
F_72 ( V_2 , V_144 , V_24 + V_146 ) ;
return V_147 ;
}
return V_146 ;
}
static inline void F_80 ( struct V_1 * V_2 ,
T_1 V_7 ,
struct V_138 * V_139 ,
struct V_157 * V_158 )
{
V_2 -> V_159 [ V_158 - V_2 -> V_160 ] = V_2 -> V_4 [ V_7 ] ;
F_81 ( V_158 , F_3 ( V_2 , V_7 ) ,
V_161 | V_162 ,
V_139 -> V_55 , V_2 -> V_17 -> V_70 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_47 , V_139 ,
sizeof( * V_139 ) ) ;
}
static inline struct V_31 * F_82 ( unsigned int V_52 )
{
struct V_31 * V_32 =
F_83 ( V_52 + V_163 + V_164 ,
V_165 | V_166 ) ;
if ( F_78 ( V_32 == NULL ) )
return NULL ;
F_84 ( V_32 , V_163 + V_164 ) ;
F_39 ( V_32 ) -> V_167 = NULL ;
return V_32 ;
}
static struct V_157 * F_85 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_138 * V_139 ,
struct V_157 * V_168 ,
unsigned int V_169 ,
struct V_31 * V_170 )
{
struct V_171 * V_172 = F_39 ( V_32 ) ;
T_2 * V_90 = V_172 -> V_90 ;
T_1 V_7 = F_86 ( V_32 ) -> V_7 ;
int V_173 ;
T_3 V_174 ;
unsigned int V_175 ;
V_175 = V_172 -> V_87 ;
V_173 = ( F_7 ( & V_172 -> V_90 [ 0 ] ) == V_7 ) ;
for ( V_172 -> V_87 = V_173 ; V_172 -> V_87 < V_175 ;
V_172 -> V_87 ++ , V_139 ++ , V_168 ++ ) {
V_174 = F_9 ( V_2 -> V_176 ++ ) ;
V_7 = V_2 -> V_177 [ V_174 ] ;
F_80 ( V_2 , V_7 , V_139 , V_168 ) ;
F_8 ( & V_90 [ V_172 -> V_87 ] , V_7 ) ;
}
if ( V_169 ) {
V_172 = F_39 ( V_170 ) ;
V_90 = V_172 -> V_90 ;
for ( V_172 -> V_87 = 0 ; V_172 -> V_87 < V_169 ;
V_172 -> V_87 ++ , V_139 ++ , V_168 ++ ) {
V_174 = F_9 ( V_2 -> V_176 ++ ) ;
V_7 = V_2 -> V_177 [ V_174 ] ;
F_80 ( V_2 , V_7 , V_139 , V_168 ) ;
F_8 ( & V_90 [ V_172 -> V_87 ] ,
V_7 ) ;
}
F_39 ( V_32 ) -> V_178 = V_170 ;
}
return V_168 ;
}
static inline void F_87 ( struct V_1 * V_2 ,
T_1 V_7 ,
T_6 V_179 )
{
if ( F_78 ( V_2 -> V_180 [ V_7 ] !=
V_181 ) ) {
F_76 ( V_2 -> V_17 -> V_19 ,
L_8 ,
V_7 ) ;
F_88 () ;
}
V_2 -> V_180 [ V_7 ] = V_179 ;
}
static inline void F_89 ( struct V_1 * V_2 ,
T_1 V_7 )
{
if ( F_78 ( V_2 -> V_180 [ V_7 ] ==
V_181 ) ) {
F_76 ( V_2 -> V_17 -> V_19 ,
L_9 ,
V_7 ) ;
F_88 () ;
}
V_2 -> V_180 [ V_7 ] = V_181 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_157 * * V_182 ,
struct V_60 * * V_183 )
{
struct V_157 * V_184 = * V_182 ;
T_1 V_7 = F_86 ( V_32 ) -> V_7 ;
struct V_171 * V_172 = F_39 ( V_32 ) ;
struct V_171 * V_185 = NULL ;
int V_87 = V_172 -> V_87 ;
const bool V_186 = V_87 &&
F_7 ( & V_172 -> V_90 [ 0 ] ) == V_7 ;
int V_14 , V_187 ;
V_187 = ( * V_183 ) -> V_93 ;
if ( F_78 ( V_187 ) ) {
if ( F_79 () )
F_51 ( V_2 -> V_17 -> V_19 ,
L_10 ,
( * V_183 ) -> V_93 ,
V_7 ,
( * V_183 ) -> V_69 . V_71 . V_72 ) ;
if ( ! V_186 )
F_91 ( V_2 , V_7 ,
V_97 ) ;
}
( * V_183 ) ++ ;
V_188:
for ( V_14 = 0 ; V_14 < V_87 ; V_14 ++ , V_184 ++ ) {
int V_189 , V_190 ;
V_7 = F_7 ( & V_172 -> V_90 [ V_14 ] ) ;
V_190 = V_184 -> V_93 ;
if ( F_92 ( ! V_190 ) ) {
F_87 ( V_2 ,
V_7 ,
V_184 -> V_179 ) ;
if ( F_78 ( V_187 ) ) {
F_93 ( V_2 , V_7 ) ;
if ( V_14 == 0 && V_186 )
F_91 ( V_2 , V_7 ,
V_97 ) ;
else
F_91 ( V_2 , V_7 ,
V_94 ) ;
}
continue;
}
if ( F_79 () )
F_51 ( V_2 -> V_17 -> V_19 ,
L_11 ,
V_14 ,
V_184 -> V_93 ,
V_7 ,
V_184 -> V_72 ) ;
F_91 ( V_2 , V_7 , V_97 ) ;
if ( V_187 )
continue;
if ( ! V_186 )
F_91 ( V_2 ,
F_86 ( V_32 ) -> V_7 ,
V_94 ) ;
for ( V_189 = 0 ; V_189 < V_14 ; V_189 ++ ) {
V_7 = F_7 ( & V_172 -> V_90 [ V_189 ] ) ;
F_93 ( V_2 , V_7 ) ;
F_91 ( V_2 , V_7 ,
V_94 ) ;
}
if ( V_185 ) {
for ( V_189 = 0 ; V_189 < V_185 -> V_87 ; V_189 ++ ) {
V_7 = F_7 ( & V_185 -> V_90 [ V_189 ] ) ;
F_93 ( V_2 , V_7 ) ;
F_91 ( V_2 , V_7 ,
V_94 ) ;
}
}
V_187 = V_190 ;
}
if ( F_94 ( V_32 ) && ! V_185 ) {
V_185 = F_39 ( V_32 ) ;
V_172 = F_39 ( F_39 ( V_32 ) -> V_178 ) ;
V_87 = V_172 -> V_87 ;
goto V_188;
}
* V_182 = V_184 ;
return V_187 ;
}
static void F_95 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_171 * V_172 = F_39 ( V_32 ) ;
int V_87 = V_172 -> V_87 ;
int V_14 ;
T_1 V_191 = V_192 ;
for ( V_14 = 0 ; V_14 < V_87 ; V_14 ++ ) {
T_2 * V_12 = V_172 -> V_90 + V_14 ;
struct V_138 * V_139 ;
struct V_64 * V_64 ;
T_1 V_7 ;
V_7 = F_7 ( V_12 ) ;
if ( V_191 == V_192 )
F_39 ( V_32 ) -> V_167 =
& F_96 ( V_2 , V_7 ) ;
else
F_96 ( V_2 , V_191 ) . V_193 =
& F_96 ( V_2 , V_7 ) ;
F_96 ( V_2 , V_7 ) . V_193 = NULL ;
V_191 = V_7 ;
V_139 = & V_2 -> V_9 [ V_7 ] . V_47 ;
V_64 = F_47 ( F_3 ( V_2 , V_7 ) ) ;
F_97 ( V_32 , V_14 , V_64 , V_139 -> V_57 , V_139 -> V_52 ) ;
V_32 -> V_37 += V_139 -> V_52 ;
V_32 -> V_194 += V_139 -> V_52 ;
V_32 -> V_195 += V_139 -> V_52 ;
F_98 ( V_2 -> V_4 [ V_7 ] ) ;
}
}
static int F_99 ( struct V_1 * V_2 ,
struct V_123 * V_196 ,
int V_145 )
{
struct V_123 V_197 ;
T_4 V_24 = V_2 -> V_131 . V_29 ;
do {
if ( F_78 ( V_145 -- <= 0 ) ) {
F_76 ( V_2 -> V_17 -> V_19 , L_12 ) ;
F_75 ( V_2 -> V_17 ) ;
return - V_198 ;
}
F_33 ( & V_2 -> V_131 , V_24 , & V_197 ) ;
if ( F_78 ( ! V_197 . type ||
V_197 . type >= V_199 ) ) {
V_2 -> V_131 . V_29 = ++ V_24 ;
F_76 ( V_2 -> V_17 -> V_19 ,
L_13 , V_197 . type ) ;
F_75 ( V_2 -> V_17 ) ;
return - V_156 ;
}
memcpy ( & V_196 [ V_197 . type - 1 ] , & V_197 , sizeof( V_197 ) ) ;
V_2 -> V_131 . V_29 = ++ V_24 ;
} while ( V_197 . V_33 & V_200 );
return V_145 ;
}
static int F_100 ( struct V_16 * V_17 ,
struct V_31 * V_32 ,
struct V_123 * V_124 )
{
if ( ! V_124 -> V_71 . V_124 . V_52 ) {
F_76 ( V_17 -> V_19 , L_14 ) ;
F_75 ( V_17 ) ;
return - V_156 ;
}
switch ( V_124 -> V_71 . V_124 . type ) {
case V_81 :
F_39 ( V_32 ) -> V_49 = V_80 ;
break;
case V_83 :
F_39 ( V_32 ) -> V_49 = V_82 ;
break;
default:
F_76 ( V_17 -> V_19 , L_15 , V_124 -> V_71 . V_124 . type ) ;
F_75 ( V_17 ) ;
return - V_156 ;
}
F_39 ( V_32 ) -> V_51 = V_124 -> V_71 . V_124 . V_52 ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
bool V_201 = false ;
if ( V_32 -> V_118 != V_119 && F_38 ( V_32 ) ) {
V_2 -> V_115 . V_202 ++ ;
V_32 -> V_118 = V_119 ;
V_201 = true ;
}
if ( V_32 -> V_118 != V_119 )
return 0 ;
return F_102 ( V_32 , V_201 ) ;
}
static bool F_103 ( struct V_1 * V_2 , unsigned V_52 )
{
T_7 V_203 = F_104 () ;
T_7 V_204 = V_2 -> V_205 +
F_105 ( V_2 -> V_206 / 1000 ) ;
if ( F_106 ( & V_2 -> V_207 ) )
return true ;
if ( F_107 ( V_203 , V_204 ) ) {
V_2 -> V_205 = V_203 ;
F_68 ( V_2 ) ;
}
if ( V_52 > V_2 -> V_136 ) {
V_2 -> V_207 . V_78 =
( unsigned long ) V_2 ;
F_108 ( & V_2 -> V_207 ,
V_204 ) ;
V_2 -> V_205 = V_204 ;
return true ;
}
return false ;
}
static int F_109 ( struct V_16 * V_17 , const T_8 * V_208 )
{
struct V_209 * V_210 ;
if ( V_17 -> V_211 == V_212 ) {
if ( F_79 () )
F_76 ( V_17 -> V_19 ,
L_16 ) ;
return - V_213 ;
}
V_210 = F_110 ( sizeof( * V_210 ) , V_165 ) ;
if ( ! V_210 )
return - V_214 ;
F_111 ( V_210 -> V_208 , V_208 ) ;
F_112 ( & V_210 -> V_215 , & V_17 -> V_216 ) ;
V_17 -> V_211 ++ ;
return 0 ;
}
static void F_113 ( struct V_16 * V_17 , const T_8 * V_208 )
{
struct V_209 * V_210 ;
F_114 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_115 ( V_208 , V_210 -> V_208 ) ) {
-- V_17 -> V_211 ;
F_116 ( & V_210 -> V_215 ) ;
F_117 ( V_210 , V_217 ) ;
break;
}
}
}
bool F_118 ( struct V_16 * V_17 , const T_8 * V_208 )
{
struct V_209 * V_210 ;
F_119 () ;
F_114 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_115 ( V_208 , V_210 -> V_208 ) ) {
F_120 () ;
return true ;
}
}
F_120 () ;
return false ;
}
void F_121 ( struct V_16 * V_17 )
{
while ( ! F_122 ( & V_17 -> V_216 ) ) {
struct V_209 * V_210 ;
V_210 = F_123 ( & V_17 -> V_216 ,
struct V_209 ,
V_215 ) ;
-- V_17 -> V_211 ;
F_124 ( & V_210 -> V_215 ) ;
F_125 ( V_210 ) ;
}
}
static void F_126 ( struct V_1 * V_2 ,
int V_218 ,
unsigned * V_219 ,
unsigned * V_220 )
{
struct V_157 * V_168 = V_2 -> V_160 ;
struct V_31 * V_32 , * V_170 ;
int V_105 ;
unsigned int V_169 ;
while ( F_127 ( & V_2 -> V_221 ) < V_218 ) {
struct V_138 V_222 ;
struct V_138 V_223 [ V_154 ] ;
struct V_123 V_196 [ V_199 - 1 ] ;
T_1 V_7 ;
T_4 V_3 ;
int V_145 ;
unsigned int V_194 ;
T_3 V_174 ;
if ( V_2 -> V_131 . V_27 -> V_28 - V_2 -> V_131 . V_29 >
V_224 ) {
F_76 ( V_2 -> V_17 -> V_19 ,
L_17
L_18 ,
V_2 -> V_131 . V_27 -> V_28 , V_2 -> V_131 . V_29 ,
V_224 ) ;
F_75 ( V_2 -> V_17 ) ;
break;
}
V_145 = F_128 ( & V_2 -> V_131 ) ;
if ( ! V_145 )
break;
V_3 = V_2 -> V_131 . V_29 ;
F_129 () ;
F_33 ( & V_2 -> V_131 , V_3 , & V_222 ) ;
if ( V_222 . V_52 > V_2 -> V_136 &&
F_103 ( V_2 , V_222 . V_52 ) )
break;
V_2 -> V_136 -= V_222 . V_52 ;
V_145 -- ;
V_2 -> V_131 . V_29 = ++ V_3 ;
memset ( V_196 , 0 , sizeof( V_196 ) ) ;
if ( V_222 . V_33 & V_225 ) {
V_145 = F_99 ( V_2 , V_196 ,
V_145 ) ;
V_3 = V_2 -> V_131 . V_29 ;
if ( F_78 ( V_145 < 0 ) )
break;
}
if ( V_196 [ V_226 - 1 ] . type ) {
struct V_123 * V_197 ;
V_197 = & V_196 [ V_226 - 1 ] ;
V_105 = F_109 ( V_2 -> V_17 , V_197 -> V_71 . V_210 . V_208 ) ;
F_73 ( V_2 , & V_222 ,
( V_105 == 0 ) ?
V_94 :
V_97 ) ;
F_74 ( V_2 ) ;
continue;
}
if ( V_196 [ V_227 - 1 ] . type ) {
struct V_123 * V_197 ;
V_197 = & V_196 [ V_227 - 1 ] ;
F_113 ( V_2 -> V_17 , V_197 -> V_71 . V_210 . V_208 ) ;
F_73 ( V_2 , & V_222 , V_94 ) ;
F_74 ( V_2 ) ;
continue;
}
V_105 = F_77 ( V_2 , & V_222 , V_223 , V_145 ) ;
if ( F_78 ( V_105 < 0 ) )
break;
V_3 += V_105 ;
if ( F_78 ( V_222 . V_52 < V_228 ) ) {
F_51 ( V_2 -> V_17 -> V_19 ,
L_19 , V_222 . V_52 ) ;
F_72 ( V_2 , & V_222 , V_3 ) ;
break;
}
if ( F_78 ( ( V_222 . V_57 + V_222 . V_52 ) > V_21 ) ) {
F_76 ( V_2 -> V_17 -> V_19 ,
L_20 ,
V_222 . V_57 , V_222 . V_52 ,
( unsigned long ) ( V_222 . V_57 & ~ V_229 ) + V_222 . V_52 ) ;
F_75 ( V_2 -> V_17 ) ;
break;
}
V_174 = F_9 ( V_2 -> V_176 ) ;
V_7 = V_2 -> V_177 [ V_174 ] ;
V_194 = ( V_222 . V_52 > V_230 &&
V_105 < V_154 ) ?
V_230 : V_222 . V_52 ;
V_32 = F_82 ( V_194 ) ;
if ( F_78 ( V_32 == NULL ) ) {
F_51 ( V_2 -> V_17 -> V_19 ,
L_21 ) ;
F_72 ( V_2 , & V_222 , V_3 ) ;
break;
}
F_39 ( V_32 ) -> V_87 = V_105 ;
if ( V_194 < V_222 . V_52 )
F_39 ( V_32 ) -> V_87 ++ ;
V_169 = 0 ;
V_170 = NULL ;
if ( F_39 ( V_32 ) -> V_87 > V_231 ) {
V_169 = F_39 ( V_32 ) -> V_87 - V_231 ;
F_35 ( V_169 > V_231 ) ;
F_39 ( V_32 ) -> V_87 = V_231 ;
V_170 = F_82 ( 0 ) ;
if ( F_78 ( V_170 == NULL ) ) {
F_27 ( V_32 ) ;
F_72 ( V_2 , & V_222 , V_3 ) ;
if ( F_79 () )
F_76 ( V_2 -> V_17 -> V_19 ,
L_22 ) ;
break;
}
}
if ( V_196 [ V_128 - 1 ] . type ) {
struct V_123 * V_124 ;
V_124 = & V_196 [ V_128 - 1 ] ;
if ( F_100 ( V_2 -> V_17 , V_32 , V_124 ) ) {
F_27 ( V_32 ) ;
F_27 ( V_170 ) ;
break;
}
}
F_86 ( V_32 ) -> V_7 = V_7 ;
F_130 ( V_32 , V_194 ) ;
V_2 -> V_232 [ * V_219 ] . V_69 . V_71 . V_72 = V_222 . V_55 ;
V_2 -> V_232 [ * V_219 ] . V_69 . V_70 = V_2 -> V_17 -> V_70 ;
V_2 -> V_232 [ * V_219 ] . V_69 . V_57 = V_222 . V_57 ;
V_2 -> V_232 [ * V_219 ] . V_76 . V_71 . V_75 =
F_131 ( V_32 -> V_78 ) ;
V_2 -> V_232 [ * V_219 ] . V_76 . V_70 = V_74 ;
V_2 -> V_232 [ * V_219 ] . V_76 . V_57 =
F_46 ( V_32 -> V_78 ) & ~ V_229 ;
V_2 -> V_232 [ * V_219 ] . V_37 = V_194 ;
V_2 -> V_232 [ * V_219 ] . V_33 = V_73 ;
( * V_219 ) ++ ;
if ( V_194 < V_222 . V_52 ) {
F_8 ( & F_39 ( V_32 ) -> V_90 [ 0 ] ,
V_7 ) ;
F_80 ( V_2 , V_7 , & V_222 , V_168 ) ;
V_168 ++ ;
} else {
F_8 ( & F_39 ( V_32 ) -> V_90 [ 0 ] ,
V_192 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_47 , & V_222 ,
sizeof( V_222 ) ) ;
}
V_2 -> V_176 ++ ;
V_168 = F_85 ( V_2 , V_32 , V_223 , V_168 ,
V_169 , V_170 ) ;
F_16 ( & V_2 -> V_221 , V_32 ) ;
V_2 -> V_131 . V_29 = V_3 ;
if ( ( ( V_168 - V_2 -> V_160 ) >= F_59 ( V_2 -> V_160 ) ) ||
( * V_219 >= F_59 ( V_2 -> V_232 ) ) )
break;
}
( * V_220 ) = V_168 - V_2 -> V_160 ;
return;
}
static int F_132 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
unsigned int V_57 = F_133 ( V_32 ) ;
T_2 V_90 [ V_231 ] ;
int V_14 , V_233 ;
struct V_5 * V_234 ;
struct V_31 * V_170 = F_39 ( V_32 ) -> V_178 ;
V_2 -> V_115 . V_235 += 2 ;
V_2 -> V_115 . V_236 ++ ;
F_95 ( V_2 , V_170 ) ;
V_32 -> V_195 -= V_32 -> V_194 ;
V_32 -> V_37 += V_170 -> V_37 ;
V_32 -> V_194 += V_170 -> V_37 ;
for ( V_14 = 0 ; V_57 < V_32 -> V_37 ; V_14 ++ ) {
struct V_64 * V_64 ;
unsigned int V_37 ;
F_35 ( V_14 >= V_231 ) ;
V_64 = F_134 ( V_165 ) ;
if ( ! V_64 ) {
int V_189 ;
V_32 -> V_195 += V_32 -> V_194 ;
for ( V_189 = 0 ; V_189 < V_14 ; V_189 ++ )
F_135 ( V_90 [ V_189 ] . V_64 . V_237 ) ;
return - V_214 ;
}
if ( V_57 + V_84 < V_32 -> V_37 )
V_37 = V_84 ;
else
V_37 = V_32 -> V_37 - V_57 ;
if ( F_136 ( V_32 , V_57 , F_137 ( V_64 ) , V_37 ) )
F_88 () ;
V_57 += V_37 ;
V_90 [ V_14 ] . V_64 . V_237 = V_64 ;
V_90 [ V_14 ] . V_13 = 0 ;
F_138 ( & V_90 [ V_14 ] , V_37 ) ;
}
F_139 ( V_32 ) ;
F_140 ( V_2 , V_170 ) ;
F_27 ( V_170 ) ;
for ( V_233 = 0 ; V_233 < F_39 ( V_32 ) -> V_87 ; V_233 ++ )
F_141 ( V_32 , V_233 ) ;
V_234 = F_39 ( V_32 ) -> V_167 ;
F_142 ( & V_2 -> V_238 ) ;
V_234 -> V_239 ( V_234 , true ) ;
F_39 ( V_32 ) -> V_167 = NULL ;
memcpy ( F_39 ( V_32 ) -> V_90 , V_90 , V_14 * sizeof( T_2 ) ) ;
F_39 ( V_32 ) -> V_87 = V_14 ;
V_32 -> V_195 += V_14 * V_84 ;
return 0 ;
}
static int F_143 ( struct V_1 * V_2 )
{
struct V_157 * V_184 = V_2 -> V_160 ;
struct V_60 * V_240 = V_2 -> V_232 ;
struct V_31 * V_32 ;
int V_241 = 0 ;
while ( ( V_32 = F_22 ( & V_2 -> V_221 ) ) != NULL ) {
struct V_138 * V_139 ;
T_1 V_7 ;
unsigned V_194 ;
V_7 = F_86 ( V_32 ) -> V_7 ;
V_139 = & V_2 -> V_9 [ V_7 ] . V_47 ;
if ( F_78 ( F_90 ( V_2 , V_32 , & V_184 , & V_240 ) ) ) {
F_39 ( V_32 ) -> V_87 = 0 ;
if ( F_94 ( V_32 ) ) {
struct V_31 * V_170 =
F_39 ( V_32 ) -> V_178 ;
F_39 ( V_170 ) -> V_87 = 0 ;
}
F_27 ( V_32 ) ;
continue;
}
V_194 = V_32 -> V_37 ;
F_96 ( V_2 , V_7 ) . V_193 = NULL ;
if ( V_194 < V_139 -> V_52 ) {
V_139 -> V_57 += V_194 ;
V_139 -> V_52 -= V_194 ;
} else {
F_91 ( V_2 , V_7 ,
V_94 ) ;
}
if ( V_139 -> V_33 & V_242 )
V_32 -> V_118 = V_119 ;
else if ( V_139 -> V_33 & V_243 )
V_32 -> V_118 = V_122 ;
F_95 ( V_2 , V_32 ) ;
if ( F_78 ( F_94 ( V_32 ) ) ) {
if ( F_132 ( V_2 , V_32 ) ) {
if ( F_79 () )
F_76 ( V_2 -> V_17 -> V_19 ,
L_23 ) ;
F_140 ( V_2 , V_32 ) ;
F_27 ( V_32 ) ;
continue;
}
}
V_32 -> V_19 = V_2 -> V_17 -> V_19 ;
V_32 -> V_244 = F_144 ( V_32 , V_32 -> V_19 ) ;
F_145 ( V_32 ) ;
if ( F_101 ( V_2 , V_32 ) ) {
F_51 ( V_2 -> V_17 -> V_19 ,
L_24 ) ;
if ( F_39 ( V_32 ) -> V_167 )
F_140 ( V_2 , V_32 ) ;
F_27 ( V_32 ) ;
continue;
}
F_146 ( V_32 , 0 ) ;
if ( F_38 ( V_32 ) ) {
int V_245 = F_39 ( V_32 ) -> V_51 ;
int V_246 = F_147 ( V_32 ) -
F_148 ( V_32 ) +
F_149 ( V_32 ) ;
F_39 ( V_32 ) -> V_247 =
F_11 ( V_32 -> V_37 - V_246 , V_245 ) ;
}
V_2 -> V_115 . V_248 += V_32 -> V_37 ;
V_2 -> V_115 . V_249 ++ ;
V_241 ++ ;
if ( F_39 ( V_32 ) -> V_167 ) {
F_140 ( V_2 , V_32 ) ;
V_2 -> V_115 . V_235 ++ ;
}
F_150 ( V_32 ) ;
}
return V_241 ;
}
void F_151 ( struct V_5 * V_6 , bool V_250 )
{
unsigned long V_33 ;
T_3 V_174 ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
F_15 ( & V_2 -> V_251 , V_33 ) ;
do {
T_1 V_7 = V_6 -> V_8 ;
V_6 = (struct V_5 * ) V_6 -> V_193 ;
F_35 ( V_2 -> V_252 - V_2 -> V_253 >=
V_15 ) ;
V_174 = F_9 ( V_2 -> V_252 ) ;
V_2 -> V_254 [ V_174 ] = V_7 ;
F_152 () ;
V_2 -> V_252 ++ ;
} while ( V_6 );
F_19 ( & V_2 -> V_251 , V_33 ) ;
if ( F_92 ( V_250 ) )
V_2 -> V_115 . V_255 ++ ;
else
V_2 -> V_115 . V_256 ++ ;
F_153 ( V_2 ) ;
}
static inline void F_154 ( struct V_1 * V_2 )
{
struct V_257 * V_168 ;
T_3 V_258 , V_259 ;
T_1 V_7 , V_260 [ V_15 ] ;
unsigned int V_14 = 0 ;
V_258 = V_2 -> V_253 ;
V_168 = V_2 -> V_261 ;
do {
V_259 = V_2 -> V_252 ;
F_155 () ;
while ( V_258 != V_259 ) {
F_35 ( V_168 - V_2 -> V_261 >= V_15 ) ;
V_7 =
V_2 -> V_254 [ F_9 ( V_258 ++ ) ] ;
V_260 [ V_168 - V_2 -> V_261 ] =
V_7 ;
V_2 -> V_262 [ V_168 - V_2 -> V_261 ] =
V_2 -> V_4 [ V_7 ] ;
F_156 ( V_168 ,
F_3 ( V_2 , V_7 ) ,
V_161 ,
V_2 -> V_180 [ V_7 ] ) ;
F_89 ( V_2 , V_7 ) ;
++ V_168 ;
}
} while ( V_259 != V_2 -> V_252 );
V_2 -> V_253 = V_258 ;
if ( V_168 - V_2 -> V_261 > 0 ) {
int V_105 ;
V_105 = F_157 ( V_2 -> V_261 ,
NULL ,
V_2 -> V_262 ,
V_168 - V_2 -> V_261 ) ;
if ( V_105 ) {
F_76 ( V_2 -> V_17 -> V_19 , L_25 ,
V_168 - V_2 -> V_261 , V_105 ) ;
for ( V_14 = 0 ; V_14 < V_168 - V_2 -> V_261 ; ++ V_14 ) {
if ( V_168 [ V_14 ] . V_93 != V_96 )
F_76 ( V_2 -> V_17 -> V_19 ,
L_26 ,
V_168 [ V_14 ] . V_263 ,
V_168 [ V_14 ] . V_179 ,
V_168 [ V_14 ] . V_93 ) ;
}
F_88 () ;
}
}
for ( V_14 = 0 ; V_14 < V_168 - V_2 -> V_261 ; ++ V_14 )
F_91 ( V_2 , V_260 [ V_14 ] ,
V_94 ) ;
}
int F_158 ( struct V_1 * V_2 , int V_218 )
{
unsigned V_264 , V_265 = 0 ;
int V_241 , V_105 ;
if ( F_78 ( ! F_159 ( V_2 ) ) )
return 0 ;
F_126 ( V_2 , V_218 , & V_265 , & V_264 ) ;
if ( V_265 == 0 )
return 0 ;
F_60 ( V_2 -> V_232 , V_265 ) ;
if ( V_264 != 0 ) {
V_105 = F_160 ( V_2 -> V_160 ,
NULL ,
V_2 -> V_159 ,
V_264 ) ;
F_35 ( V_105 ) ;
}
V_241 = F_143 ( V_2 ) ;
return V_241 ;
}
static void F_91 ( struct V_1 * V_2 , T_1 V_7 ,
T_8 V_93 )
{
struct V_9 * V_9 ;
T_3 V_174 ;
unsigned long V_33 ;
V_9 = & V_2 -> V_9 [ V_7 ] ;
F_15 ( & V_2 -> V_141 , V_33 ) ;
F_73 ( V_2 , & V_9 -> V_47 , V_93 ) ;
V_174 = F_9 ( V_2 -> V_266 ++ ) ;
V_2 -> V_177 [ V_174 ] = V_7 ;
F_74 ( V_2 ) ;
F_19 ( & V_2 -> V_141 , V_33 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_138 * V_139 ,
T_5 V_267 )
{
T_4 V_14 = V_2 -> V_131 . V_113 ;
struct V_268 * V_101 ;
V_101 = F_61 ( & V_2 -> V_131 , V_14 ) ;
V_101 -> V_39 = V_139 -> V_39 ;
V_101 -> V_93 = V_267 ;
if ( V_139 -> V_33 & V_225 )
F_61 ( & V_2 -> V_131 , ++ V_14 ) -> V_93 = V_269 ;
V_2 -> V_131 . V_113 = ++ V_14 ;
}
static void F_74 ( struct V_1 * V_2 )
{
int V_104 ;
F_62 ( & V_2 -> V_131 , V_104 ) ;
if ( V_104 )
F_64 ( V_2 -> V_270 ) ;
}
static struct V_100 * F_53 ( struct V_1 * V_2 ,
T_1 V_39 ,
T_5 V_267 ,
T_1 V_57 ,
T_1 V_52 ,
T_1 V_33 )
{
T_4 V_14 = V_2 -> V_26 . V_113 ;
struct V_100 * V_101 ;
V_101 = F_61 ( & V_2 -> V_26 , V_14 ) ;
V_101 -> V_57 = V_57 ;
V_101 -> V_33 = V_33 ;
V_101 -> V_39 = V_39 ;
V_101 -> V_93 = ( V_271 ) V_52 ;
if ( V_267 < 0 )
V_101 -> V_93 = ( V_271 ) V_267 ;
V_2 -> V_26 . V_113 = ++ V_14 ;
return V_101 ;
}
void F_93 ( struct V_1 * V_2 , T_1 V_7 )
{
int V_105 ;
struct V_257 V_272 ;
F_156 ( & V_272 ,
F_3 ( V_2 , V_7 ) ,
V_161 ,
V_2 -> V_180 [ V_7 ] ) ;
F_89 ( V_2 , V_7 ) ;
V_105 = F_157 ( & V_272 , NULL ,
& V_2 -> V_4 [ V_7 ] , 1 ) ;
if ( V_105 ) {
F_76 ( V_2 -> V_17 -> V_19 ,
L_27 ,
V_105 ,
V_7 ,
V_272 . V_263 ,
V_272 . V_179 ,
V_272 . V_93 ) ;
F_88 () ;
}
}
static inline int F_159 ( struct V_1 * V_2 )
{
if ( F_92 ( F_128 ( & V_2 -> V_131 ) ) )
return 1 ;
return 0 ;
}
static inline bool F_161 ( struct V_1 * V_2 )
{
return V_2 -> V_253 != V_2 -> V_252 ;
}
void F_162 ( struct V_1 * V_2 )
{
if ( V_2 -> V_131 . V_27 )
F_163 ( F_164 ( V_2 -> V_17 ) ,
V_2 -> V_131 . V_27 ) ;
if ( V_2 -> V_26 . V_27 )
F_163 ( F_164 ( V_2 -> V_17 ) ,
V_2 -> V_26 . V_27 ) ;
}
int F_165 ( struct V_1 * V_2 ,
T_9 V_273 ,
T_9 V_274 )
{
void * V_208 ;
struct V_275 * V_276 ;
struct V_277 * V_278 ;
int V_187 = - V_214 ;
V_187 = F_166 ( F_164 ( V_2 -> V_17 ) ,
& V_273 , 1 , & V_208 ) ;
if ( V_187 )
goto V_187;
V_276 = (struct V_275 * ) V_208 ;
F_167 ( & V_2 -> V_131 , V_276 , V_21 ) ;
V_187 = F_166 ( F_164 ( V_2 -> V_17 ) ,
& V_274 , 1 , & V_208 ) ;
if ( V_187 )
goto V_187;
V_278 = (struct V_277 * ) V_208 ;
F_167 ( & V_2 -> V_26 , V_278 , V_21 ) ;
return 0 ;
V_187:
F_162 ( V_2 ) ;
return V_187 ;
}
static void F_168 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
V_2 -> V_279 = true ;
F_169 ( & V_17 -> V_35 ) ;
if ( V_17 -> V_280 ++ == 0 ) {
F_170 ( V_17 -> V_19 , L_28 ) ;
F_171 ( V_17 -> V_19 ) ;
}
F_172 ( & V_17 -> V_35 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
V_2 -> V_108 = V_40 ;
V_2 -> V_279 = false ;
F_169 ( & V_17 -> V_35 ) ;
if ( -- V_17 -> V_280 == 0 ) {
F_170 ( V_17 -> V_19 , L_29 ) ;
F_174 ( V_17 -> V_19 ) ;
}
F_172 ( & V_17 -> V_35 ) ;
}
static bool F_175 ( struct V_1 * V_2 )
{
T_4 V_23 , V_24 ;
V_23 = V_2 -> V_26 . V_27 -> V_28 ;
V_24 = V_2 -> V_26 . V_29 ;
return ! V_2 -> V_279 && V_23 - V_24 < 1
&& F_176 ( V_40 ,
V_2 -> V_108 + V_2 -> V_17 -> V_281 ) ;
}
static bool F_177 ( struct V_1 * V_2 )
{
T_4 V_23 , V_24 ;
V_23 = V_2 -> V_26 . V_27 -> V_28 ;
V_24 = V_2 -> V_26 . V_29 ;
return V_2 -> V_279 && V_23 - V_24 >= 1 ;
}
static bool F_178 ( struct V_1 * V_2 )
{
return ( ! F_179 ( & V_2 -> V_34 )
&& F_12 ( V_2 ) )
|| ( V_2 -> V_17 -> V_281 &&
( F_175 ( V_2 )
|| F_177 ( V_2 ) ) )
|| F_180 ()
|| V_2 -> V_17 -> V_142 ;
}
static long F_181 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
long V_282 ;
V_32 = F_29 ( & V_2 -> V_34 ) ;
if ( ! V_32 )
return V_283 ;
V_282 = F_31 ( V_32 ) -> V_41 - V_40 ;
return V_282 < 0 ? 0 : V_282 ;
}
static void F_182 ( struct V_1 * V_2 )
{
F_183 ( V_284 ) ;
if ( F_178 ( V_2 ) )
return;
for (; ; ) {
long V_105 ;
F_184 ( & V_2 -> V_99 , & V_284 , V_285 ) ;
if ( F_178 ( V_2 ) )
break;
V_105 = F_185 ( F_181 ( V_2 ) ) ;
if ( ! V_105 )
break;
}
F_186 ( & V_2 -> V_99 , & V_284 ) ;
}
int F_187 ( void * V_78 )
{
struct V_1 * V_2 = V_78 ;
struct V_16 * V_17 = V_2 -> V_17 ;
if ( ! V_17 -> V_281 )
F_173 ( V_2 ) ;
for (; ; ) {
F_182 ( V_2 ) ;
if ( F_180 () )
break;
if ( F_78 ( V_17 -> V_142 && V_2 -> V_39 == 0 ) ) {
F_188 ( V_17 ) ;
break;
}
if ( ! F_179 ( & V_2 -> V_34 ) )
F_56 ( V_2 ) ;
if ( V_17 -> V_281 ) {
if ( F_175 ( V_2 ) )
F_168 ( V_2 ) ;
else if ( F_177 ( V_2 ) )
F_173 ( V_2 ) ;
}
F_28 ( V_2 ) ;
F_24 ( V_2 ) ;
F_189 () ;
}
F_26 ( V_2 ) ;
return 0 ;
}
static bool F_190 ( struct V_1 * V_2 )
{
return F_180 () &&
! F_191 ( & V_2 -> V_238 ) ;
}
int F_192 ( void * V_78 )
{
struct V_1 * V_2 = V_78 ;
for (; ; ) {
F_193 ( V_2 -> V_286 ,
F_161 ( V_2 ) ||
F_190 ( V_2 ) ) ;
if ( F_190 ( V_2 ) )
break;
F_154 ( V_2 ) ;
F_189 () ;
}
if ( F_161 ( V_2 ) )
F_154 ( V_2 ) ;
return 0 ;
}
static int T_10 F_194 ( void )
{
int V_287 = 0 ;
if ( ! F_195 () )
return - V_288 ;
if ( V_289 == 0 )
V_289 = F_196 () ;
if ( V_152 < V_154 ) {
F_197 ( L_30 ,
V_152 , V_154 ) ;
V_152 = V_154 ;
}
V_287 = F_198 () ;
if ( V_287 )
goto V_290;
#ifdef F_199
V_291 = F_200 ( L_31 , NULL ) ;
if ( F_201 ( V_291 ) )
F_202 ( L_32 ,
F_203 ( V_291 ) ) ;
#endif
return 0 ;
V_290:
return V_287 ;
}
static void T_11 F_204 ( void )
{
#ifdef F_199
if ( ! F_201 ( V_291 ) )
F_205 ( V_291 ) ;
#endif
F_206 () ;
}
