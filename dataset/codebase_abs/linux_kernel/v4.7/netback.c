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
static bool F_10 ( struct V_1 * V_2 )
{
T_4 V_16 , V_17 ;
struct V_18 * V_19 ;
int V_20 ;
V_19 = F_11 ( & V_2 -> V_21 ) ;
if ( ! V_19 )
return false ;
V_20 = F_12 ( V_19 -> V_22 , V_23 ) ;
if ( F_13 ( V_19 ) )
V_20 ++ ;
if ( V_19 -> V_24 )
V_20 ++ ;
do {
V_16 = V_2 -> V_25 . V_26 -> V_27 ;
V_17 = V_2 -> V_25 . V_28 ;
if ( V_16 - V_17 >= V_20 )
return true ;
V_2 -> V_25 . V_26 -> V_29 = V_16 + 1 ;
F_14 () ;
} while ( V_2 -> V_25 . V_26 -> V_27 != V_16 );
return false ;
}
void F_15 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
unsigned long V_30 ;
F_16 ( & V_2 -> V_21 . V_31 , V_30 ) ;
F_17 ( & V_2 -> V_21 , V_19 ) ;
V_2 -> V_32 += V_19 -> V_22 ;
if ( V_2 -> V_32 > V_2 -> V_33 )
F_18 ( F_19 ( V_2 -> V_34 -> V_35 , V_2 -> V_36 ) ) ;
F_20 ( & V_2 -> V_21 . V_31 , V_30 ) ;
}
static struct V_18 * F_21 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
F_22 ( & V_2 -> V_21 . V_31 ) ;
V_19 = F_23 ( & V_2 -> V_21 ) ;
if ( V_19 )
V_2 -> V_32 -= V_19 -> V_22 ;
F_24 ( & V_2 -> V_21 . V_31 ) ;
return V_19 ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_21 . V_31 ) ;
if ( V_2 -> V_32 < V_2 -> V_33 )
F_26 ( F_19 ( V_2 -> V_34 -> V_35 , V_2 -> V_36 ) ) ;
F_24 ( & V_2 -> V_21 . V_31 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
while ( ( V_19 = F_21 ( V_2 ) ) != NULL )
F_28 ( V_19 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
for(; ; ) {
V_19 = F_11 ( & V_2 -> V_21 ) ;
if ( ! V_19 )
break;
if ( F_30 ( V_37 , F_31 ( V_19 ) -> V_38 ) )
break;
F_21 ( V_2 ) ;
F_28 ( V_19 ) ;
}
}
static struct V_39 * F_32 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_39 * V_42 ;
struct V_43 V_44 ;
F_33 ( & V_2 -> V_25 , V_2 -> V_25 . V_28 ++ , & V_44 ) ;
V_42 = V_41 -> V_42 + V_41 -> V_45 ++ ;
V_42 -> V_46 = V_47 ;
V_42 -> V_48 = 0 ;
V_42 -> V_49 = 0 ;
V_42 -> V_36 = V_44 . V_36 ;
V_41 -> V_50 = 0 ;
V_41 -> V_51 = V_44 . V_52 ;
return V_42 ;
}
static void F_34 ( unsigned long V_53 ,
unsigned int V_54 ,
unsigned int * V_22 ,
struct V_55 * V_56 )
{
struct V_57 * V_58 ;
struct V_59 * V_60 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_40 * V_41 = V_56 -> V_41 ;
struct V_61 * V_61 = V_56 -> V_61 ;
F_35 ( V_41 -> V_50 > V_62 ) ;
if ( V_41 -> V_50 == V_62 )
V_56 -> V_42 = F_32 ( V_2 , V_41 ) ;
if ( V_41 -> V_50 + * V_22 > V_62 )
* V_22 = V_62 - V_41 -> V_50 ;
V_58 = V_41 -> V_63 + V_41 -> V_64 ++ ;
V_58 -> V_30 = V_65 ;
V_58 -> V_22 = * V_22 ;
V_60 = V_59 ( V_61 ) ;
if ( V_60 ) {
V_58 -> V_66 . V_67 = V_60 -> V_67 ;
V_58 -> V_66 . V_68 . V_69 = V_60 -> V_52 ;
V_58 -> V_30 |= V_70 ;
} else {
V_58 -> V_66 . V_67 = V_71 ;
V_58 -> V_66 . V_68 . V_72 = V_53 ;
}
V_58 -> V_66 . V_54 = V_54 ;
V_58 -> V_73 . V_67 = V_2 -> V_34 -> V_67 ;
V_58 -> V_73 . V_54 = V_41 -> V_50 ;
V_58 -> V_73 . V_68 . V_69 = V_41 -> V_51 ;
V_41 -> V_50 += * V_22 ;
V_56 -> V_42 -> V_49 += * V_22 ;
if ( ! V_56 -> V_74 )
return;
if ( ( 1 << V_56 -> V_46 ) & V_2 -> V_34 -> V_75 )
V_2 -> V_25 . V_28 ++ ;
if ( V_56 -> V_76 )
V_2 -> V_25 . V_28 ++ ;
V_56 -> V_74 = 0 ;
}
static void F_36 ( unsigned long V_53 ,
unsigned V_54 ,
unsigned int V_22 ,
void * V_77 )
{
unsigned int V_78 ;
while ( V_22 ) {
V_78 = V_22 ;
F_34 ( V_53 , V_54 , & V_78 , V_77 ) ;
V_54 += V_78 ;
V_22 -= V_78 ;
}
}
static void F_37 ( struct V_1 * V_2 , struct V_18 * V_19 ,
struct V_40 * V_41 ,
struct V_61 * V_61 , unsigned long V_49 ,
unsigned long V_54 , int * V_74 )
{
struct V_55 V_56 = {
. V_2 = V_2 ,
. V_41 = V_41 ,
. V_74 = * V_74 ,
. V_46 = V_47 ,
. V_76 = V_19 -> V_24 ,
} ;
unsigned long V_78 ;
if ( F_13 ( V_19 ) ) {
if ( F_38 ( V_19 ) -> V_46 & V_79 )
V_56 . V_46 = V_80 ;
else if ( F_38 ( V_19 ) -> V_46 & V_81 )
V_56 . V_46 = V_82 ;
}
F_35 ( V_49 + V_54 > V_83 << F_39 ( V_61 ) ) ;
V_56 . V_42 = V_41 -> V_42 + V_41 -> V_45 - 1 ;
V_61 += V_54 >> V_84 ;
V_54 &= ~ V_85 ;
while ( V_49 > 0 ) {
F_35 ( V_54 >= V_83 ) ;
V_78 = V_83 - V_54 ;
if ( V_78 > V_49 )
V_78 = V_49 ;
V_56 . V_61 = V_61 ;
F_40 ( V_61 , V_54 , V_78 ,
F_36 ,
& V_56 ) ;
V_49 -= V_78 ;
V_54 = 0 ;
if ( V_49 ) {
F_35 ( ! F_41 ( V_61 ) ) ;
V_61 ++ ;
}
}
* V_74 = V_56 . V_74 ;
}
static int F_42 ( struct V_18 * V_19 ,
struct V_40 * V_41 ,
struct V_1 * V_2 )
{
struct V_86 * V_34 = F_43 ( V_19 -> V_35 ) ;
int V_87 = F_38 ( V_19 ) -> V_87 ;
int V_14 ;
struct V_43 V_44 ;
struct V_39 * V_42 ;
unsigned char * V_77 ;
int V_74 = 1 ;
int V_88 ;
int V_46 ;
V_88 = V_41 -> V_45 ;
V_46 = V_47 ;
if ( F_13 ( V_19 ) ) {
if ( F_38 ( V_19 ) -> V_46 & V_79 )
V_46 = V_80 ;
else if ( F_38 ( V_19 ) -> V_46 & V_81 )
V_46 = V_82 ;
}
if ( ( 1 << V_46 ) & V_34 -> V_89 ) {
F_33 ( & V_2 -> V_25 , V_2 -> V_25 . V_28 ++ , & V_44 ) ;
V_42 = V_41 -> V_42 + V_41 -> V_45 ++ ;
V_42 -> V_46 = V_46 ;
V_42 -> V_48 = F_38 ( V_19 ) -> V_48 ;
V_42 -> V_49 = 0 ;
V_42 -> V_36 = V_44 . V_36 ;
}
F_33 ( & V_2 -> V_25 , V_2 -> V_25 . V_28 ++ , & V_44 ) ;
V_42 = V_41 -> V_42 + V_41 -> V_45 ++ ;
if ( ( 1 << V_46 ) & V_34 -> V_75 ) {
V_42 -> V_46 = V_46 ;
V_42 -> V_48 = F_38 ( V_19 ) -> V_48 ;
} else {
V_42 -> V_46 = V_47 ;
V_42 -> V_48 = 0 ;
}
V_42 -> V_49 = 0 ;
V_42 -> V_36 = V_44 . V_36 ;
V_41 -> V_50 = 0 ;
V_41 -> V_51 = V_44 . V_52 ;
V_77 = V_19 -> V_77 ;
while ( V_77 < F_44 ( V_19 ) ) {
unsigned int V_54 = F_45 ( V_77 ) ;
unsigned int V_22 = V_83 - V_54 ;
if ( V_77 + V_22 > F_44 ( V_19 ) )
V_22 = F_44 ( V_19 ) - V_77 ;
F_37 ( V_2 , V_19 , V_41 ,
F_46 ( V_77 ) , V_22 , V_54 , & V_74 ) ;
V_77 += V_22 ;
}
for ( V_14 = 0 ; V_14 < V_87 ; V_14 ++ ) {
F_37 ( V_2 , V_19 , V_41 ,
F_47 ( & F_38 ( V_19 ) -> V_90 [ V_14 ] ) ,
F_48 ( & F_38 ( V_19 ) -> V_90 [ V_14 ] ) ,
F_38 ( V_19 ) -> V_90 [ V_14 ] . V_13 ,
& V_74 ) ;
}
return V_41 -> V_45 - V_88 ;
}
static int F_49 ( struct V_86 * V_34 , int V_91 ,
struct V_40 * V_41 )
{
struct V_57 * V_92 ;
int V_93 = V_94 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_91 ; V_14 ++ ) {
V_92 = V_41 -> V_63 + V_41 -> V_95 ++ ;
if ( V_92 -> V_93 != V_96 ) {
F_50 ( V_34 -> V_35 ,
L_1 ,
V_92 -> V_93 , V_34 -> V_67 ) ;
V_93 = V_97 ;
}
}
return V_93 ;
}
static void F_51 ( struct V_1 * V_2 , int V_93 ,
struct V_39 * V_42 ,
int V_91 )
{
int V_14 ;
unsigned long V_54 ;
if ( V_91 <= 1 )
return;
V_91 -- ;
for ( V_14 = 0 ; V_14 < V_91 ; V_14 ++ ) {
int V_30 ;
if ( V_14 == V_91 - 1 )
V_30 = 0 ;
else
V_30 = V_98 ;
V_54 = 0 ;
F_52 ( V_2 , V_42 [ V_14 ] . V_36 , V_93 , V_54 ,
V_42 [ V_14 ] . V_49 , V_30 ) ;
}
}
void F_53 ( struct V_1 * V_2 )
{
F_54 ( & V_2 -> V_99 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_86 * V_34 = V_2 -> V_34 ;
T_5 V_93 ;
T_1 V_30 ;
struct V_100 * V_101 ;
struct V_102 V_103 ;
struct V_18 * V_19 ;
F_56 ( V_104 ) ;
int V_105 ;
unsigned long V_54 ;
bool V_106 = false ;
struct V_40 V_41 = {
. V_63 = V_2 -> V_107 ,
. V_42 = V_2 -> V_42 ,
} ;
F_57 ( & V_103 ) ;
while ( F_10 ( V_2 )
&& ( V_19 = F_21 ( V_2 ) ) != NULL ) {
V_2 -> V_108 = V_37 ;
F_31 ( V_19 ) -> V_109 = F_42 ( V_19 , & V_41 , V_2 ) ;
F_17 ( & V_103 , V_19 ) ;
}
F_35 ( V_41 . V_45 > F_58 ( V_2 -> V_42 ) ) ;
if ( ! V_41 . V_64 )
goto V_110;
F_35 ( V_41 . V_64 > V_111 ) ;
F_59 ( V_2 -> V_107 , V_41 . V_64 ) ;
while ( ( V_19 = F_23 ( & V_103 ) ) != NULL ) {
struct V_112 * V_113 = NULL ;
if ( ( 1 << V_2 -> V_42 [ V_41 . V_114 ] . V_46 ) &
V_34 -> V_89 ) {
V_101 = F_60 ( & V_2 -> V_25 ,
V_2 -> V_25 . V_115 ++ ) ;
V_101 -> V_30 = V_116 | V_98 ;
V_101 -> V_54 = V_2 -> V_42 [ V_41 . V_114 ] . V_48 ;
V_101 -> V_36 = V_2 -> V_42 [ V_41 . V_114 ] . V_36 ;
V_101 -> V_93 = F_31 ( V_19 ) -> V_109 ;
V_41 . V_114 ++ ;
F_31 ( V_19 ) -> V_109 -- ;
}
V_2 -> V_117 . V_118 += V_19 -> V_22 ;
V_2 -> V_117 . V_119 ++ ;
V_93 = F_49 ( V_34 ,
F_31 ( V_19 ) -> V_109 ,
& V_41 ) ;
if ( F_31 ( V_19 ) -> V_109 == 1 )
V_30 = 0 ;
else
V_30 = V_98 ;
if ( V_19 -> V_120 == V_121 )
V_30 |= V_122 | V_123 ;
else if ( V_19 -> V_120 == V_124 )
V_30 |= V_123 ;
V_54 = 0 ;
V_101 = F_52 ( V_2 , V_2 -> V_42 [ V_41 . V_114 ] . V_36 ,
V_93 , V_54 ,
V_2 -> V_42 [ V_41 . V_114 ] . V_49 ,
V_30 ) ;
if ( ( 1 << V_2 -> V_42 [ V_41 . V_114 ] . V_46 ) &
V_34 -> V_75 ) {
V_113 = (struct V_112 * )
F_60 ( & V_2 -> V_25 ,
V_2 -> V_25 . V_115 ++ ) ;
V_101 -> V_30 |= V_125 ;
V_113 -> V_68 . V_126 . type = V_2 -> V_42 [ V_41 . V_114 ] . V_46 ;
V_113 -> V_68 . V_126 . V_49 = V_2 -> V_42 [ V_41 . V_114 ] . V_48 ;
V_113 -> V_68 . V_126 . V_127 = 0 ;
V_113 -> V_68 . V_126 . V_128 = 0 ;
V_113 -> type = V_129 ;
V_113 -> V_30 = 0 ;
}
if ( V_19 -> V_24 ) {
if ( V_101 -> V_30 & V_125 )
V_113 -> V_30 |= V_130 ;
else
V_101 -> V_30 |= V_125 ;
V_113 = (struct V_112 * )
F_60 ( & V_2 -> V_25 ,
V_2 -> V_25 . V_115 ++ ) ;
V_113 -> V_68 . V_131 . V_132 =
V_133 ;
if ( V_19 -> V_134 )
V_113 -> V_68 . V_131 . type =
V_19 -> V_135 == F_61 ( V_136 ) ?
V_137 :
V_138 ;
else
V_113 -> V_68 . V_131 . type =
V_19 -> V_135 == F_61 ( V_136 ) ?
V_139 :
V_140 ;
* ( V_141 * ) V_113 -> V_68 . V_131 . V_142 =
F_62 ( V_19 ) ;
V_113 -> type = V_143 ;
V_113 -> V_30 = 0 ;
}
F_51 ( V_2 , V_93 ,
V_2 -> V_42 + V_41 . V_114 + 1 ,
F_31 ( V_19 ) -> V_109 ) ;
F_63 ( & V_2 -> V_25 , V_105 ) ;
V_106 |= ! ! V_105 ;
V_41 . V_114 += F_31 ( V_19 ) -> V_109 ;
F_64 ( V_19 ) ;
}
V_110:
if ( V_106 )
F_65 ( V_2 -> V_144 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
int V_145 ;
F_67 ( & V_2 -> V_146 , V_145 ) ;
if ( V_145 )
F_68 ( & V_2 -> V_147 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
unsigned long V_148 , V_149 ;
V_148 = F_70 ( 131072UL , V_2 -> V_150 ) ;
V_149 = V_2 -> V_151 + V_2 -> V_150 ;
if ( V_149 < V_2 -> V_151 )
V_149 = V_152 ;
V_2 -> V_151 = F_71 ( V_149 , V_148 ) ;
}
void F_72 ( unsigned long V_77 )
{
struct V_1 * V_2 = (struct V_1 * ) V_77 ;
F_69 ( V_2 ) ;
F_66 ( V_2 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_153 * V_154 ,
unsigned int V_155 , T_4 V_156 )
{
T_4 V_17 = V_2 -> V_146 . V_28 ;
unsigned long V_30 ;
do {
F_16 ( & V_2 -> V_157 , V_30 ) ;
F_74 ( V_2 , V_154 , V_155 , V_97 ) ;
F_75 ( V_2 ) ;
F_20 ( & V_2 -> V_157 , V_30 ) ;
if ( V_17 == V_156 )
break;
F_33 ( & V_2 -> V_146 , V_17 ++ , V_154 ) ;
V_155 = 0 ;
} while ( 1 );
V_2 -> V_146 . V_28 = V_17 ;
}
static void F_76 ( struct V_86 * V_34 )
{
F_77 ( V_34 -> V_35 , L_2 ) ;
V_34 -> V_158 = true ;
if ( V_34 -> V_159 )
F_53 ( & V_34 -> V_159 [ 0 ] ) ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_153 * V_160 ,
unsigned int V_155 ,
struct V_153 * V_154 ,
int V_161 )
{
T_4 V_17 = V_2 -> V_146 . V_28 ;
int V_162 = 0 ;
int V_163 = 0 ;
int V_164 ;
if ( ! ( V_160 -> V_30 & V_165 ) )
return 0 ;
do {
struct V_153 V_166 = { 0 } ;
if ( V_162 >= V_161 ) {
F_77 ( V_2 -> V_34 -> V_35 ,
L_3 ,
V_161 ) ;
F_76 ( V_2 -> V_34 ) ;
return - V_167 ;
}
if ( F_79 ( V_162 >= V_168 ) ) {
F_77 ( V_2 -> V_34 -> V_35 ,
L_4 ,
V_162 , V_168 ) ;
F_76 ( V_2 -> V_34 ) ;
return - V_169 ;
}
if ( ! V_163 && V_162 >= V_170 ) {
if ( F_80 () )
F_50 ( V_2 -> V_34 -> V_35 ,
L_5 ,
V_162 , V_170 ) ;
V_163 = - V_169 ;
}
if ( V_163 )
V_154 = & V_166 ;
F_33 ( & V_2 -> V_146 , V_17 + V_162 , V_154 ) ;
if ( ! V_163 && V_154 -> V_49 > V_160 -> V_49 ) {
if ( F_80 () )
F_50 ( V_2 -> V_34 -> V_35 ,
L_6 ,
V_154 -> V_49 , V_160 -> V_49 ) ;
V_163 = - V_171 ;
}
V_160 -> V_49 -= V_154 -> V_49 ;
V_162 ++ ;
if ( F_79 ( ( V_154 -> V_54 + V_154 -> V_49 ) > V_23 ) ) {
F_77 ( V_2 -> V_34 -> V_35 , L_7 ,
V_154 -> V_54 , V_154 -> V_49 ) ;
F_76 ( V_2 -> V_34 ) ;
return - V_172 ;
}
V_164 = V_154 -> V_30 & V_165 ;
if ( ! V_163 )
V_154 ++ ;
} while ( V_164 );
if ( V_163 ) {
F_73 ( V_2 , V_160 , V_155 , V_17 + V_162 ) ;
return V_163 ;
}
return V_162 ;
}
static inline void F_81 ( struct V_1 * V_2 ,
T_1 V_7 ,
struct V_153 * V_154 ,
unsigned int V_155 ,
struct V_173 * V_174 )
{
V_2 -> V_175 [ V_174 - V_2 -> V_176 ] = V_2 -> V_4 [ V_7 ] ;
F_82 ( V_174 , F_3 ( V_2 , V_7 ) ,
V_177 | V_178 ,
V_154 -> V_52 , V_2 -> V_34 -> V_67 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_44 , V_154 ,
sizeof( * V_154 ) ) ;
V_2 -> V_9 [ V_7 ] . V_155 = V_155 ;
}
static inline struct V_18 * F_83 ( unsigned int V_49 )
{
struct V_18 * V_19 =
F_84 ( V_49 + V_179 + V_180 ,
V_181 | V_182 ) ;
if ( F_79 ( V_19 == NULL ) )
return NULL ;
F_85 ( V_19 , V_179 + V_180 ) ;
F_38 ( V_19 ) -> V_183 = NULL ;
return V_19 ;
}
static struct V_173 * F_86 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_153 * V_154 ,
struct V_173 * V_184 ,
unsigned int V_185 ,
struct V_18 * V_186 )
{
struct V_187 * V_188 = F_38 ( V_19 ) ;
T_2 * V_90 = V_188 -> V_90 ;
T_1 V_7 = F_87 ( V_19 ) -> V_7 ;
int V_189 ;
T_3 V_190 ;
unsigned int V_191 ;
V_191 = V_188 -> V_87 ;
V_189 = ( F_7 ( & V_188 -> V_90 [ 0 ] ) == V_7 ) ;
for ( V_188 -> V_87 = V_189 ; V_188 -> V_87 < V_191 ;
V_188 -> V_87 ++ , V_154 ++ , V_184 ++ ) {
V_190 = F_9 ( V_2 -> V_192 ++ ) ;
V_7 = V_2 -> V_193 [ V_190 ] ;
F_81 ( V_2 , V_7 , V_154 , 0 , V_184 ) ;
F_8 ( & V_90 [ V_188 -> V_87 ] , V_7 ) ;
}
if ( V_185 ) {
V_188 = F_38 ( V_186 ) ;
V_90 = V_188 -> V_90 ;
for ( V_188 -> V_87 = 0 ; V_188 -> V_87 < V_185 ;
V_188 -> V_87 ++ , V_154 ++ , V_184 ++ ) {
V_190 = F_9 ( V_2 -> V_192 ++ ) ;
V_7 = V_2 -> V_193 [ V_190 ] ;
F_81 ( V_2 , V_7 , V_154 , 0 ,
V_184 ) ;
F_8 ( & V_90 [ V_188 -> V_87 ] ,
V_7 ) ;
}
F_38 ( V_19 ) -> V_194 = V_186 ;
}
return V_184 ;
}
static inline void F_88 ( struct V_1 * V_2 ,
T_1 V_7 ,
T_6 V_195 )
{
if ( F_79 ( V_2 -> V_196 [ V_7 ] !=
V_197 ) ) {
F_77 ( V_2 -> V_34 -> V_35 ,
L_8 ,
V_7 ) ;
F_89 () ;
}
V_2 -> V_196 [ V_7 ] = V_195 ;
}
static inline void F_90 ( struct V_1 * V_2 ,
T_1 V_7 )
{
if ( F_79 ( V_2 -> V_196 [ V_7 ] ==
V_197 ) ) {
F_77 ( V_2 -> V_34 -> V_35 ,
L_9 ,
V_7 ) ;
F_89 () ;
}
V_2 -> V_196 [ V_7 ] = V_197 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_173 * * V_198 ,
struct V_57 * * V_199 )
{
struct V_173 * V_200 = * V_198 ;
T_1 V_7 = F_87 ( V_19 ) -> V_7 ;
struct V_187 * V_188 = F_38 ( V_19 ) ;
struct V_187 * V_201 = NULL ;
int V_87 = V_188 -> V_87 ;
const bool V_202 = V_87 &&
F_7 ( & V_188 -> V_90 [ 0 ] ) == V_7 ;
int V_14 , V_203 ;
V_203 = ( * V_199 ) -> V_93 ;
if ( F_79 ( V_203 ) ) {
if ( F_80 () )
F_50 ( V_2 -> V_34 -> V_35 ,
L_10 ,
( * V_199 ) -> V_93 ,
V_7 ,
( * V_199 ) -> V_66 . V_68 . V_69 ) ;
if ( ! V_202 )
F_92 ( V_2 , V_7 ,
V_97 ) ;
}
( * V_199 ) ++ ;
V_204:
for ( V_14 = 0 ; V_14 < V_87 ; V_14 ++ , V_200 ++ ) {
int V_205 , V_206 ;
V_7 = F_7 ( & V_188 -> V_90 [ V_14 ] ) ;
V_206 = V_200 -> V_93 ;
if ( F_93 ( ! V_206 ) ) {
F_88 ( V_2 ,
V_7 ,
V_200 -> V_195 ) ;
if ( F_79 ( V_203 ) ) {
F_94 ( V_2 , V_7 ) ;
if ( V_14 == 0 && V_202 )
F_92 ( V_2 , V_7 ,
V_97 ) ;
else
F_92 ( V_2 , V_7 ,
V_94 ) ;
}
continue;
}
if ( F_80 () )
F_50 ( V_2 -> V_34 -> V_35 ,
L_11 ,
V_14 ,
V_200 -> V_93 ,
V_7 ,
V_200 -> V_69 ) ;
F_92 ( V_2 , V_7 , V_97 ) ;
if ( V_203 )
continue;
if ( ! V_202 )
F_92 ( V_2 ,
F_87 ( V_19 ) -> V_7 ,
V_94 ) ;
for ( V_205 = 0 ; V_205 < V_14 ; V_205 ++ ) {
V_7 = F_7 ( & V_188 -> V_90 [ V_205 ] ) ;
F_94 ( V_2 , V_7 ) ;
F_92 ( V_2 , V_7 ,
V_94 ) ;
}
if ( V_201 ) {
for ( V_205 = 0 ; V_205 < V_201 -> V_87 ; V_205 ++ ) {
V_7 = F_7 ( & V_201 -> V_90 [ V_205 ] ) ;
F_94 ( V_2 , V_7 ) ;
F_92 ( V_2 , V_7 ,
V_94 ) ;
}
}
V_203 = V_206 ;
}
if ( F_95 ( V_19 ) && ! V_201 ) {
V_201 = F_38 ( V_19 ) ;
V_188 = F_38 ( F_38 ( V_19 ) -> V_194 ) ;
V_87 = V_188 -> V_87 ;
goto V_204;
}
* V_198 = V_200 ;
return V_203 ;
}
static void F_96 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_187 * V_188 = F_38 ( V_19 ) ;
int V_87 = V_188 -> V_87 ;
int V_14 ;
T_1 V_207 = V_208 ;
for ( V_14 = 0 ; V_14 < V_87 ; V_14 ++ ) {
T_2 * V_12 = V_188 -> V_90 + V_14 ;
struct V_153 * V_154 ;
struct V_61 * V_61 ;
T_1 V_7 ;
V_7 = F_7 ( V_12 ) ;
if ( V_207 == V_208 )
F_38 ( V_19 ) -> V_183 =
& F_97 ( V_2 , V_7 ) ;
else
F_97 ( V_2 , V_207 ) . V_209 =
& F_97 ( V_2 , V_7 ) ;
F_97 ( V_2 , V_7 ) . V_209 = NULL ;
V_207 = V_7 ;
V_154 = & V_2 -> V_9 [ V_7 ] . V_44 ;
V_61 = F_46 ( F_3 ( V_2 , V_7 ) ) ;
F_98 ( V_19 , V_14 , V_61 , V_154 -> V_54 , V_154 -> V_49 ) ;
V_19 -> V_22 += V_154 -> V_49 ;
V_19 -> V_210 += V_154 -> V_49 ;
V_19 -> V_211 += V_154 -> V_49 ;
F_99 ( V_2 -> V_4 [ V_7 ] ) ;
}
}
static int F_100 ( struct V_1 * V_2 ,
struct V_112 * V_212 ,
unsigned int * V_155 ,
int V_161 )
{
struct V_112 V_113 ;
T_4 V_17 = V_2 -> V_146 . V_28 ;
do {
if ( F_79 ( V_161 -- <= 0 ) ) {
F_77 ( V_2 -> V_34 -> V_35 , L_12 ) ;
F_76 ( V_2 -> V_34 ) ;
return - V_213 ;
}
F_33 ( & V_2 -> V_146 , V_17 , & V_113 ) ;
V_2 -> V_146 . V_28 = ++ V_17 ;
( * V_155 ) ++ ;
if ( F_79 ( ! V_113 . type ||
V_113 . type >= V_214 ) ) {
F_77 ( V_2 -> V_34 -> V_35 ,
L_13 , V_113 . type ) ;
F_76 ( V_2 -> V_34 ) ;
return - V_172 ;
}
memcpy ( & V_212 [ V_113 . type - 1 ] , & V_113 , sizeof( V_113 ) ) ;
} while ( V_113 . V_30 & V_130 );
return V_161 ;
}
static int F_101 ( struct V_86 * V_34 ,
struct V_18 * V_19 ,
struct V_112 * V_126 )
{
if ( ! V_126 -> V_68 . V_126 . V_49 ) {
F_77 ( V_34 -> V_35 , L_14 ) ;
F_76 ( V_34 ) ;
return - V_172 ;
}
switch ( V_126 -> V_68 . V_126 . type ) {
case V_80 :
F_38 ( V_19 ) -> V_46 = V_79 ;
break;
case V_82 :
F_38 ( V_19 ) -> V_46 = V_81 ;
break;
default:
F_77 ( V_34 -> V_35 , L_15 , V_126 -> V_68 . V_126 . type ) ;
F_76 ( V_34 ) ;
return - V_172 ;
}
F_38 ( V_19 ) -> V_48 = V_126 -> V_68 . V_126 . V_49 ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
bool V_215 = false ;
if ( V_19 -> V_120 != V_121 && F_13 ( V_19 ) ) {
V_2 -> V_117 . V_216 ++ ;
V_19 -> V_120 = V_121 ;
V_215 = true ;
}
if ( V_19 -> V_120 != V_121 )
return 0 ;
return F_103 ( V_19 , V_215 ) ;
}
static bool F_104 ( struct V_1 * V_2 , unsigned V_49 )
{
T_7 V_217 = F_105 () ;
T_7 V_218 = V_2 -> V_219 +
F_106 ( V_2 -> V_220 / 1000 ) ;
if ( F_107 ( & V_2 -> V_221 ) )
return true ;
if ( F_108 ( V_217 , V_218 ) ) {
V_2 -> V_219 = V_217 ;
F_69 ( V_2 ) ;
}
if ( V_49 > V_2 -> V_151 ) {
V_2 -> V_221 . V_77 =
( unsigned long ) V_2 ;
F_109 ( & V_2 -> V_221 ,
V_218 ) ;
V_2 -> V_219 = V_218 ;
return true ;
}
return false ;
}
static int F_110 ( struct V_86 * V_34 , const T_8 * V_222 )
{
struct V_223 * V_224 ;
if ( V_34 -> V_225 == V_226 ) {
if ( F_80 () )
F_77 ( V_34 -> V_35 ,
L_16 ) ;
return - V_227 ;
}
V_224 = F_111 ( sizeof( * V_224 ) , V_181 ) ;
if ( ! V_224 )
return - V_228 ;
F_112 ( V_224 -> V_222 , V_222 ) ;
F_113 ( & V_224 -> V_229 , & V_34 -> V_230 ) ;
V_34 -> V_225 ++ ;
return 0 ;
}
static void F_114 ( struct V_86 * V_34 , const T_8 * V_222 )
{
struct V_223 * V_224 ;
F_115 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_116 ( V_222 , V_224 -> V_222 ) ) {
-- V_34 -> V_225 ;
F_117 ( & V_224 -> V_229 ) ;
F_118 ( V_224 , V_231 ) ;
break;
}
}
}
bool F_119 ( struct V_86 * V_34 , const T_8 * V_222 )
{
struct V_223 * V_224 ;
F_120 () ;
F_115 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_116 ( V_222 , V_224 -> V_222 ) ) {
F_121 () ;
return true ;
}
}
F_121 () ;
return false ;
}
void F_122 ( struct V_86 * V_34 )
{
while ( ! F_123 ( & V_34 -> V_230 ) ) {
struct V_223 * V_224 ;
V_224 = F_124 ( & V_34 -> V_230 ,
struct V_223 ,
V_229 ) ;
-- V_34 -> V_225 ;
F_125 ( & V_224 -> V_229 ) ;
F_126 ( V_224 ) ;
}
}
static void F_127 ( struct V_1 * V_2 ,
int V_232 ,
unsigned * V_233 ,
unsigned * V_234 )
{
struct V_173 * V_184 = V_2 -> V_176 ;
struct V_18 * V_19 , * V_186 ;
int V_105 ;
unsigned int V_185 ;
while ( F_128 ( & V_2 -> V_235 ) < V_232 ) {
struct V_153 V_236 ;
struct V_153 V_237 [ V_170 ] ;
struct V_112 V_212 [ V_214 - 1 ] ;
unsigned int V_155 ;
T_1 V_7 ;
T_4 V_3 ;
int V_161 ;
unsigned int V_210 ;
T_3 V_190 ;
if ( V_2 -> V_146 . V_26 -> V_27 - V_2 -> V_146 . V_28 >
V_238 ) {
F_77 ( V_2 -> V_34 -> V_35 ,
L_17
L_18 ,
V_2 -> V_146 . V_26 -> V_27 , V_2 -> V_146 . V_28 ,
V_238 ) ;
F_76 ( V_2 -> V_34 ) ;
break;
}
V_161 = F_129 ( & V_2 -> V_146 ) ;
if ( ! V_161 )
break;
V_3 = V_2 -> V_146 . V_28 ;
F_130 () ;
F_33 ( & V_2 -> V_146 , V_3 , & V_236 ) ;
if ( V_236 . V_49 > V_2 -> V_151 &&
F_104 ( V_2 , V_236 . V_49 ) )
break;
V_2 -> V_151 -= V_236 . V_49 ;
V_161 -- ;
V_2 -> V_146 . V_28 = ++ V_3 ;
memset ( V_212 , 0 , sizeof( V_212 ) ) ;
V_155 = 0 ;
if ( V_236 . V_30 & V_239 ) {
V_161 = F_100 ( V_2 , V_212 ,
& V_155 ,
V_161 ) ;
V_3 = V_2 -> V_146 . V_28 ;
if ( F_79 ( V_161 < 0 ) )
break;
}
if ( V_212 [ V_240 - 1 ] . type ) {
struct V_112 * V_113 ;
V_113 = & V_212 [ V_240 - 1 ] ;
V_105 = F_110 ( V_2 -> V_34 , V_113 -> V_68 . V_224 . V_222 ) ;
F_74 ( V_2 , & V_236 , V_155 ,
( V_105 == 0 ) ?
V_94 :
V_97 ) ;
F_75 ( V_2 ) ;
continue;
}
if ( V_212 [ V_241 - 1 ] . type ) {
struct V_112 * V_113 ;
V_113 = & V_212 [ V_241 - 1 ] ;
F_114 ( V_2 -> V_34 , V_113 -> V_68 . V_224 . V_222 ) ;
F_74 ( V_2 , & V_236 , V_155 ,
V_94 ) ;
F_75 ( V_2 ) ;
continue;
}
V_105 = F_78 ( V_2 , & V_236 , V_155 ,
V_237 , V_161 ) ;
if ( F_79 ( V_105 < 0 ) )
break;
V_3 += V_105 ;
if ( F_79 ( V_236 . V_49 < V_242 ) ) {
F_50 ( V_2 -> V_34 -> V_35 ,
L_19 , V_236 . V_49 ) ;
F_73 ( V_2 , & V_236 , V_155 , V_3 ) ;
break;
}
if ( F_79 ( ( V_236 . V_54 + V_236 . V_49 ) > V_23 ) ) {
F_77 ( V_2 -> V_34 -> V_35 ,
L_20 ,
V_236 . V_54 , V_236 . V_49 ,
( unsigned long ) ( V_236 . V_54 & ~ V_243 ) + V_236 . V_49 ) ;
F_76 ( V_2 -> V_34 ) ;
break;
}
V_190 = F_9 ( V_2 -> V_192 ) ;
V_7 = V_2 -> V_193 [ V_190 ] ;
V_210 = ( V_236 . V_49 > V_244 &&
V_105 < V_170 ) ?
V_244 : V_236 . V_49 ;
V_19 = F_83 ( V_210 ) ;
if ( F_79 ( V_19 == NULL ) ) {
F_50 ( V_2 -> V_34 -> V_35 ,
L_21 ) ;
F_73 ( V_2 , & V_236 , V_155 , V_3 ) ;
break;
}
F_38 ( V_19 ) -> V_87 = V_105 ;
if ( V_210 < V_236 . V_49 )
F_38 ( V_19 ) -> V_87 ++ ;
V_185 = 0 ;
V_186 = NULL ;
if ( F_38 ( V_19 ) -> V_87 > V_245 ) {
V_185 = F_38 ( V_19 ) -> V_87 - V_245 ;
F_35 ( V_185 > V_245 ) ;
F_38 ( V_19 ) -> V_87 = V_245 ;
V_186 = F_83 ( 0 ) ;
if ( F_79 ( V_186 == NULL ) ) {
F_28 ( V_19 ) ;
F_73 ( V_2 , & V_236 , V_155 , V_3 ) ;
if ( F_80 () )
F_77 ( V_2 -> V_34 -> V_35 ,
L_22 ) ;
break;
}
}
if ( V_212 [ V_129 - 1 ] . type ) {
struct V_112 * V_126 ;
V_126 = & V_212 [ V_129 - 1 ] ;
if ( F_101 ( V_2 -> V_34 , V_19 , V_126 ) ) {
F_28 ( V_19 ) ;
F_28 ( V_186 ) ;
break;
}
}
if ( V_212 [ V_143 - 1 ] . type ) {
struct V_112 * V_113 ;
enum V_246 type = V_247 ;
V_113 = & V_212 [ V_143 - 1 ] ;
switch ( V_113 -> V_68 . V_131 . type ) {
case V_139 :
case V_140 :
type = V_248 ;
break;
case V_137 :
case V_138 :
type = V_249 ;
break;
default:
break;
}
if ( type != V_247 )
F_131 ( V_19 ,
* ( V_250 * ) V_113 -> V_68 . V_131 . V_142 ,
type ) ;
}
F_87 ( V_19 ) -> V_7 = V_7 ;
F_132 ( V_19 , V_210 ) ;
V_2 -> V_251 [ * V_233 ] . V_66 . V_68 . V_69 = V_236 . V_52 ;
V_2 -> V_251 [ * V_233 ] . V_66 . V_67 = V_2 -> V_34 -> V_67 ;
V_2 -> V_251 [ * V_233 ] . V_66 . V_54 = V_236 . V_54 ;
V_2 -> V_251 [ * V_233 ] . V_73 . V_68 . V_72 =
F_133 ( V_19 -> V_77 ) ;
V_2 -> V_251 [ * V_233 ] . V_73 . V_67 = V_71 ;
V_2 -> V_251 [ * V_233 ] . V_73 . V_54 =
F_45 ( V_19 -> V_77 ) & ~ V_243 ;
V_2 -> V_251 [ * V_233 ] . V_22 = V_210 ;
V_2 -> V_251 [ * V_233 ] . V_30 = V_70 ;
( * V_233 ) ++ ;
if ( V_210 < V_236 . V_49 ) {
F_8 ( & F_38 ( V_19 ) -> V_90 [ 0 ] ,
V_7 ) ;
F_81 ( V_2 , V_7 , & V_236 ,
V_155 , V_184 ) ;
V_184 ++ ;
} else {
F_8 ( & F_38 ( V_19 ) -> V_90 [ 0 ] ,
V_208 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_44 ,
& V_236 , sizeof( V_236 ) ) ;
V_2 -> V_9 [ V_7 ] . V_155 =
V_155 ;
}
V_2 -> V_192 ++ ;
V_184 = F_86 ( V_2 , V_19 , V_237 , V_184 ,
V_185 , V_186 ) ;
F_17 ( & V_2 -> V_235 , V_19 ) ;
V_2 -> V_146 . V_28 = V_3 ;
if ( ( ( V_184 - V_2 -> V_176 ) >= F_58 ( V_2 -> V_176 ) ) ||
( * V_233 >= F_58 ( V_2 -> V_251 ) ) )
break;
}
( * V_234 ) = V_184 - V_2 -> V_176 ;
return;
}
static int F_134 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
unsigned int V_54 = F_135 ( V_19 ) ;
T_2 V_90 [ V_245 ] ;
int V_14 , V_252 ;
struct V_5 * V_253 ;
struct V_18 * V_186 = F_38 ( V_19 ) -> V_194 ;
V_2 -> V_117 . V_254 += 2 ;
V_2 -> V_117 . V_255 ++ ;
F_96 ( V_2 , V_186 ) ;
V_19 -> V_211 -= V_19 -> V_210 ;
V_19 -> V_22 += V_186 -> V_22 ;
V_19 -> V_210 += V_186 -> V_22 ;
for ( V_14 = 0 ; V_54 < V_19 -> V_22 ; V_14 ++ ) {
struct V_61 * V_61 ;
unsigned int V_22 ;
F_35 ( V_14 >= V_245 ) ;
V_61 = F_136 ( V_181 ) ;
if ( ! V_61 ) {
int V_205 ;
V_19 -> V_211 += V_19 -> V_210 ;
for ( V_205 = 0 ; V_205 < V_14 ; V_205 ++ )
F_137 ( V_90 [ V_205 ] . V_61 . V_256 ) ;
return - V_228 ;
}
if ( V_54 + V_83 < V_19 -> V_22 )
V_22 = V_83 ;
else
V_22 = V_19 -> V_22 - V_54 ;
if ( F_138 ( V_19 , V_54 , F_139 ( V_61 ) , V_22 ) )
F_89 () ;
V_54 += V_22 ;
V_90 [ V_14 ] . V_61 . V_256 = V_61 ;
V_90 [ V_14 ] . V_13 = 0 ;
F_140 ( & V_90 [ V_14 ] , V_22 ) ;
}
F_141 ( V_19 ) ;
F_142 ( V_2 , V_186 ) ;
F_28 ( V_186 ) ;
for ( V_252 = 0 ; V_252 < F_38 ( V_19 ) -> V_87 ; V_252 ++ )
F_143 ( V_19 , V_252 ) ;
V_253 = F_38 ( V_19 ) -> V_183 ;
F_144 ( & V_2 -> V_257 ) ;
V_253 -> V_258 ( V_253 , true ) ;
F_38 ( V_19 ) -> V_183 = NULL ;
memcpy ( F_38 ( V_19 ) -> V_90 , V_90 , V_14 * sizeof( T_2 ) ) ;
F_38 ( V_19 ) -> V_87 = V_14 ;
V_19 -> V_211 += V_14 * V_83 ;
return 0 ;
}
static int F_145 ( struct V_1 * V_2 )
{
struct V_173 * V_200 = V_2 -> V_176 ;
struct V_57 * V_259 = V_2 -> V_251 ;
struct V_18 * V_19 ;
int V_260 = 0 ;
while ( ( V_19 = F_23 ( & V_2 -> V_235 ) ) != NULL ) {
struct V_153 * V_154 ;
T_1 V_7 ;
unsigned V_210 ;
V_7 = F_87 ( V_19 ) -> V_7 ;
V_154 = & V_2 -> V_9 [ V_7 ] . V_44 ;
if ( F_79 ( F_91 ( V_2 , V_19 , & V_200 , & V_259 ) ) ) {
F_38 ( V_19 ) -> V_87 = 0 ;
if ( F_95 ( V_19 ) ) {
struct V_18 * V_186 =
F_38 ( V_19 ) -> V_194 ;
F_38 ( V_186 ) -> V_87 = 0 ;
}
F_28 ( V_19 ) ;
continue;
}
V_210 = V_19 -> V_22 ;
F_97 ( V_2 , V_7 ) . V_209 = NULL ;
if ( V_210 < V_154 -> V_49 ) {
V_154 -> V_54 += V_210 ;
V_154 -> V_49 -= V_210 ;
} else {
F_92 ( V_2 , V_7 ,
V_94 ) ;
}
if ( V_154 -> V_30 & V_261 )
V_19 -> V_120 = V_121 ;
else if ( V_154 -> V_30 & V_262 )
V_19 -> V_120 = V_124 ;
F_96 ( V_2 , V_19 ) ;
if ( F_79 ( F_95 ( V_19 ) ) ) {
if ( F_134 ( V_2 , V_19 ) ) {
if ( F_80 () )
F_77 ( V_2 -> V_34 -> V_35 ,
L_23 ) ;
F_142 ( V_2 , V_19 ) ;
F_28 ( V_19 ) ;
continue;
}
}
V_19 -> V_35 = V_2 -> V_34 -> V_35 ;
V_19 -> V_135 = F_146 ( V_19 , V_19 -> V_35 ) ;
F_147 ( V_19 ) ;
if ( F_102 ( V_2 , V_19 ) ) {
F_50 ( V_2 -> V_34 -> V_35 ,
L_24 ) ;
if ( F_38 ( V_19 ) -> V_183 )
F_142 ( V_2 , V_19 ) ;
F_28 ( V_19 ) ;
continue;
}
F_148 ( V_19 , 0 ) ;
if ( F_13 ( V_19 ) ) {
int V_263 = F_38 ( V_19 ) -> V_48 ;
int V_264 = F_149 ( V_19 ) -
F_150 ( V_19 ) +
F_151 ( V_19 ) ;
F_38 ( V_19 ) -> V_265 =
F_12 ( V_19 -> V_22 - V_264 , V_263 ) ;
}
V_2 -> V_117 . V_266 += V_19 -> V_22 ;
V_2 -> V_117 . V_267 ++ ;
V_260 ++ ;
if ( F_38 ( V_19 ) -> V_183 ) {
F_142 ( V_2 , V_19 ) ;
V_2 -> V_117 . V_254 ++ ;
}
F_152 ( V_19 ) ;
}
return V_260 ;
}
void F_153 ( struct V_5 * V_6 , bool V_268 )
{
unsigned long V_30 ;
T_3 V_190 ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
F_16 ( & V_2 -> V_269 , V_30 ) ;
do {
T_1 V_7 = V_6 -> V_8 ;
V_6 = (struct V_5 * ) V_6 -> V_209 ;
F_35 ( V_2 -> V_270 - V_2 -> V_271 >=
V_15 ) ;
V_190 = F_9 ( V_2 -> V_270 ) ;
V_2 -> V_272 [ V_190 ] = V_7 ;
F_154 () ;
V_2 -> V_270 ++ ;
} while ( V_6 );
F_20 ( & V_2 -> V_269 , V_30 ) ;
if ( F_93 ( V_268 ) )
V_2 -> V_117 . V_273 ++ ;
else
V_2 -> V_117 . V_274 ++ ;
F_155 ( V_2 ) ;
}
static inline void F_156 ( struct V_1 * V_2 )
{
struct V_275 * V_184 ;
T_3 V_276 , V_277 ;
T_1 V_7 , V_278 [ V_15 ] ;
unsigned int V_14 = 0 ;
V_276 = V_2 -> V_271 ;
V_184 = V_2 -> V_279 ;
do {
V_277 = V_2 -> V_270 ;
F_157 () ;
while ( V_276 != V_277 ) {
F_35 ( V_184 - V_2 -> V_279 >= V_15 ) ;
V_7 =
V_2 -> V_272 [ F_9 ( V_276 ++ ) ] ;
V_278 [ V_184 - V_2 -> V_279 ] =
V_7 ;
V_2 -> V_280 [ V_184 - V_2 -> V_279 ] =
V_2 -> V_4 [ V_7 ] ;
F_158 ( V_184 ,
F_3 ( V_2 , V_7 ) ,
V_177 ,
V_2 -> V_196 [ V_7 ] ) ;
F_90 ( V_2 , V_7 ) ;
++ V_184 ;
}
} while ( V_277 != V_2 -> V_270 );
V_2 -> V_271 = V_276 ;
if ( V_184 - V_2 -> V_279 > 0 ) {
int V_105 ;
V_105 = F_159 ( V_2 -> V_279 ,
NULL ,
V_2 -> V_280 ,
V_184 - V_2 -> V_279 ) ;
if ( V_105 ) {
F_77 ( V_2 -> V_34 -> V_35 , L_25 ,
V_184 - V_2 -> V_279 , V_105 ) ;
for ( V_14 = 0 ; V_14 < V_184 - V_2 -> V_279 ; ++ V_14 ) {
if ( V_184 [ V_14 ] . V_93 != V_96 )
F_77 ( V_2 -> V_34 -> V_35 ,
L_26 ,
V_184 [ V_14 ] . V_281 ,
V_184 [ V_14 ] . V_195 ,
V_184 [ V_14 ] . V_93 ) ;
}
F_89 () ;
}
}
for ( V_14 = 0 ; V_14 < V_184 - V_2 -> V_279 ; ++ V_14 )
F_92 ( V_2 , V_278 [ V_14 ] ,
V_94 ) ;
}
int F_160 ( struct V_1 * V_2 , int V_232 )
{
unsigned V_282 , V_283 = 0 ;
int V_260 , V_105 ;
if ( F_79 ( ! F_161 ( V_2 ) ) )
return 0 ;
F_127 ( V_2 , V_232 , & V_283 , & V_282 ) ;
if ( V_283 == 0 )
return 0 ;
F_59 ( V_2 -> V_251 , V_283 ) ;
if ( V_282 != 0 ) {
V_105 = F_162 ( V_2 -> V_176 ,
NULL ,
V_2 -> V_175 ,
V_282 ) ;
F_35 ( V_105 ) ;
}
V_260 = F_145 ( V_2 ) ;
return V_260 ;
}
static void F_92 ( struct V_1 * V_2 , T_1 V_7 ,
T_8 V_93 )
{
struct V_9 * V_9 ;
T_3 V_190 ;
unsigned long V_30 ;
V_9 = & V_2 -> V_9 [ V_7 ] ;
F_16 ( & V_2 -> V_157 , V_30 ) ;
F_74 ( V_2 , & V_9 -> V_44 ,
V_9 -> V_155 , V_93 ) ;
V_190 = F_9 ( V_2 -> V_284 ++ ) ;
V_2 -> V_193 [ V_190 ] = V_7 ;
F_75 ( V_2 ) ;
F_20 ( & V_2 -> V_157 , V_30 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_153 * V_154 ,
unsigned int V_155 ,
T_5 V_285 )
{
T_4 V_14 = V_2 -> V_146 . V_115 ;
struct V_286 * V_101 ;
V_101 = F_60 ( & V_2 -> V_146 , V_14 ) ;
V_101 -> V_36 = V_154 -> V_36 ;
V_101 -> V_93 = V_285 ;
while ( V_155 -- != 0 )
F_60 ( & V_2 -> V_146 , ++ V_14 ) -> V_93 = V_287 ;
V_2 -> V_146 . V_115 = ++ V_14 ;
}
static void F_75 ( struct V_1 * V_2 )
{
int V_104 ;
F_63 ( & V_2 -> V_146 , V_104 ) ;
if ( V_104 )
F_65 ( V_2 -> V_288 ) ;
}
static struct V_100 * F_52 ( struct V_1 * V_2 ,
T_1 V_36 ,
T_5 V_285 ,
T_1 V_54 ,
T_1 V_49 ,
T_1 V_30 )
{
T_4 V_14 = V_2 -> V_25 . V_115 ;
struct V_100 * V_101 ;
V_101 = F_60 ( & V_2 -> V_25 , V_14 ) ;
V_101 -> V_54 = V_54 ;
V_101 -> V_30 = V_30 ;
V_101 -> V_36 = V_36 ;
V_101 -> V_93 = ( V_289 ) V_49 ;
if ( V_285 < 0 )
V_101 -> V_93 = ( V_289 ) V_285 ;
V_2 -> V_25 . V_115 = ++ V_14 ;
return V_101 ;
}
void F_94 ( struct V_1 * V_2 , T_1 V_7 )
{
int V_105 ;
struct V_275 V_290 ;
F_158 ( & V_290 ,
F_3 ( V_2 , V_7 ) ,
V_177 ,
V_2 -> V_196 [ V_7 ] ) ;
F_90 ( V_2 , V_7 ) ;
V_105 = F_159 ( & V_290 , NULL ,
& V_2 -> V_4 [ V_7 ] , 1 ) ;
if ( V_105 ) {
F_77 ( V_2 -> V_34 -> V_35 ,
L_27 ,
V_105 ,
V_7 ,
V_290 . V_281 ,
V_290 . V_195 ,
V_290 . V_93 ) ;
F_89 () ;
}
}
static inline int F_161 ( struct V_1 * V_2 )
{
if ( F_93 ( F_129 ( & V_2 -> V_146 ) ) )
return 1 ;
return 0 ;
}
static inline bool F_163 ( struct V_1 * V_2 )
{
return V_2 -> V_271 != V_2 -> V_270 ;
}
void F_164 ( struct V_1 * V_2 )
{
if ( V_2 -> V_146 . V_26 )
F_165 ( F_166 ( V_2 -> V_34 ) ,
V_2 -> V_146 . V_26 ) ;
if ( V_2 -> V_25 . V_26 )
F_165 ( F_166 ( V_2 -> V_34 ) ,
V_2 -> V_25 . V_26 ) ;
}
int F_167 ( struct V_1 * V_2 ,
T_9 V_291 ,
T_9 V_292 )
{
void * V_222 ;
struct V_293 * V_294 ;
struct V_295 * V_296 ;
int V_203 = - V_228 ;
V_203 = F_168 ( F_166 ( V_2 -> V_34 ) ,
& V_291 , 1 , & V_222 ) ;
if ( V_203 )
goto V_203;
V_294 = (struct V_293 * ) V_222 ;
F_169 ( & V_2 -> V_146 , V_294 , V_23 ) ;
V_203 = F_168 ( F_166 ( V_2 -> V_34 ) ,
& V_292 , 1 , & V_222 ) ;
if ( V_203 )
goto V_203;
V_296 = (struct V_295 * ) V_222 ;
F_169 ( & V_2 -> V_25 , V_296 , V_23 ) ;
return 0 ;
V_203:
F_164 ( V_2 ) ;
return V_203 ;
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_86 * V_34 = V_2 -> V_34 ;
V_2 -> V_297 = true ;
F_171 ( & V_34 -> V_31 ) ;
if ( V_34 -> V_298 ++ == 0 ) {
F_172 ( V_34 -> V_35 , L_28 ) ;
F_173 ( V_34 -> V_35 ) ;
}
F_174 ( & V_34 -> V_31 ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_86 * V_34 = V_2 -> V_34 ;
V_2 -> V_108 = V_37 ;
V_2 -> V_297 = false ;
F_171 ( & V_34 -> V_31 ) ;
if ( -- V_34 -> V_298 == 0 ) {
F_172 ( V_34 -> V_35 , L_29 ) ;
F_176 ( V_34 -> V_35 ) ;
}
F_174 ( & V_34 -> V_31 ) ;
}
static bool F_177 ( struct V_1 * V_2 )
{
T_4 V_16 , V_17 ;
V_16 = V_2 -> V_25 . V_26 -> V_27 ;
V_17 = V_2 -> V_25 . V_28 ;
return ! V_2 -> V_297 && V_16 - V_17 < 1
&& F_178 ( V_37 ,
V_2 -> V_108 + V_2 -> V_34 -> V_299 ) ;
}
static bool F_179 ( struct V_1 * V_2 )
{
T_4 V_16 , V_17 ;
V_16 = V_2 -> V_25 . V_26 -> V_27 ;
V_17 = V_2 -> V_25 . V_28 ;
return V_2 -> V_297 && V_16 - V_17 >= 1 ;
}
static bool F_180 ( struct V_1 * V_2 )
{
return F_10 ( V_2 )
|| ( V_2 -> V_34 -> V_299 &&
( F_177 ( V_2 )
|| F_179 ( V_2 ) ) )
|| F_181 ()
|| V_2 -> V_34 -> V_158 ;
}
static long F_182 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
long V_300 ;
V_19 = F_11 ( & V_2 -> V_21 ) ;
if ( ! V_19 )
return V_301 ;
V_300 = F_31 ( V_19 ) -> V_38 - V_37 ;
return V_300 < 0 ? 0 : V_300 ;
}
static void F_183 ( struct V_1 * V_2 )
{
F_184 ( V_302 ) ;
if ( F_180 ( V_2 ) )
return;
for (; ; ) {
long V_105 ;
F_185 ( & V_2 -> V_99 , & V_302 , V_303 ) ;
if ( F_180 ( V_2 ) )
break;
V_105 = F_186 ( F_182 ( V_2 ) ) ;
if ( ! V_105 )
break;
}
F_187 ( & V_2 -> V_99 , & V_302 ) ;
}
int F_188 ( void * V_77 )
{
struct V_1 * V_2 = V_77 ;
struct V_86 * V_34 = V_2 -> V_34 ;
if ( ! V_34 -> V_299 )
F_175 ( V_2 ) ;
for (; ; ) {
F_183 ( V_2 ) ;
if ( F_181 () )
break;
if ( F_79 ( V_34 -> V_158 && V_2 -> V_36 == 0 ) ) {
F_189 ( V_34 ) ;
break;
}
if ( ! F_190 ( & V_2 -> V_21 ) )
F_55 ( V_2 ) ;
if ( V_34 -> V_299 ) {
if ( F_177 ( V_2 ) )
F_170 ( V_2 ) ;
else if ( F_179 ( V_2 ) )
F_175 ( V_2 ) ;
}
F_29 ( V_2 ) ;
F_25 ( V_2 ) ;
F_191 () ;
}
F_27 ( V_2 ) ;
return 0 ;
}
static bool F_192 ( struct V_1 * V_2 )
{
return F_181 () &&
! F_193 ( & V_2 -> V_257 ) ;
}
int F_194 ( void * V_77 )
{
struct V_1 * V_2 = V_77 ;
for (; ; ) {
F_195 ( V_2 -> V_304 ,
F_163 ( V_2 ) ||
F_192 ( V_2 ) ) ;
if ( F_192 ( V_2 ) )
break;
F_156 ( V_2 ) ;
F_191 () ;
}
if ( F_163 ( V_2 ) )
F_156 ( V_2 ) ;
return 0 ;
}
static void F_196 ( struct V_86 * V_34 ,
const struct V_305 * V_44 ,
V_250 V_93 , V_250 V_77 )
{
T_4 V_3 = V_34 -> V_306 . V_115 ;
struct V_307 V_308 = {
. V_36 = V_44 -> V_36 ,
. type = V_44 -> type ,
. V_93 = V_93 ,
. V_77 = V_77 ,
} ;
* F_60 ( & V_34 -> V_306 , V_3 ) = V_308 ;
V_34 -> V_306 . V_115 = ++ V_3 ;
}
static void F_197 ( struct V_86 * V_34 )
{
int V_104 ;
F_63 ( & V_34 -> V_306 , V_104 ) ;
if ( V_104 )
F_65 ( V_34 -> V_309 ) ;
}
static void F_198 ( struct V_86 * V_34 ,
const struct V_305 * V_44 )
{
V_250 V_93 = V_310 ;
V_250 V_77 = 0 ;
switch ( V_44 -> type ) {
case V_311 :
V_93 = F_199 ( V_34 , V_44 -> V_77 [ 0 ] ) ;
break;
case V_312 :
V_93 = F_200 ( V_34 , & V_77 ) ;
break;
case V_313 :
V_93 = F_201 ( V_34 , V_44 -> V_77 [ 0 ] ) ;
break;
case V_314 :
V_93 = F_202 ( V_34 , V_44 -> V_77 [ 0 ] ,
V_44 -> V_77 [ 1 ] ) ;
break;
case V_315 :
V_93 = V_316 ;
V_77 = V_317 ;
break;
case V_318 :
V_93 = F_203 ( V_34 ,
V_44 -> V_77 [ 0 ] ) ;
break;
case V_319 :
V_93 = F_204 ( V_34 , V_44 -> V_77 [ 0 ] ,
V_44 -> V_77 [ 1 ] ,
V_44 -> V_77 [ 2 ] ) ;
break;
default:
break;
}
F_196 ( V_34 , V_44 , V_93 , V_77 ) ;
F_197 ( V_34 ) ;
}
static void F_205 ( struct V_86 * V_34 )
{
for (; ; ) {
T_4 V_27 , V_28 ;
V_27 = V_34 -> V_306 . V_26 -> V_27 ;
V_28 = V_34 -> V_306 . V_28 ;
F_130 () ;
if ( V_28 == V_27 )
break;
while ( V_28 != V_27 ) {
struct V_305 V_44 ;
F_33 ( & V_34 -> V_306 , V_28 , & V_44 ) ;
V_28 ++ ;
F_198 ( V_34 , & V_44 ) ;
}
V_34 -> V_306 . V_28 = V_28 ;
V_34 -> V_306 . V_26 -> V_29 = V_28 + 1 ;
}
}
static bool F_206 ( struct V_86 * V_34 )
{
if ( F_93 ( F_129 ( & V_34 -> V_306 ) ) )
return 1 ;
return 0 ;
}
int F_207 ( void * V_77 )
{
struct V_86 * V_34 = V_77 ;
for (; ; ) {
F_195 ( V_34 -> V_320 ,
F_206 ( V_34 ) ||
F_181 () ) ;
if ( F_181 () )
break;
while ( F_206 ( V_34 ) )
F_205 ( V_34 ) ;
F_191 () ;
}
return 0 ;
}
static int T_10 F_208 ( void )
{
int V_321 = 0 ;
if ( ! F_209 () )
return - V_322 ;
if ( V_323 == 0 )
V_323 = F_210 () ;
if ( V_168 < V_170 ) {
F_211 ( L_30 ,
V_168 , V_170 ) ;
V_168 = V_170 ;
}
V_321 = F_212 () ;
if ( V_321 )
goto V_324;
#ifdef F_213
V_325 = F_214 ( L_31 , NULL ) ;
if ( F_215 ( V_325 ) )
F_216 ( L_32 ,
F_217 ( V_325 ) ) ;
#endif
return 0 ;
V_324:
return V_321 ;
}
static void T_11 F_218 ( void )
{
#ifdef F_213
if ( ! F_215 ( V_325 ) )
F_219 ( V_325 ) ;
#endif
F_220 () ;
}
