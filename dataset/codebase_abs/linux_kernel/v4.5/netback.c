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
do {
V_16 = V_2 -> V_24 . V_25 -> V_26 ;
V_17 = V_2 -> V_24 . V_27 ;
if ( V_16 - V_17 >= V_20 )
return true ;
V_2 -> V_24 . V_25 -> V_28 = V_16 + 1 ;
F_14 () ;
} while ( V_2 -> V_24 . V_25 -> V_26 != V_16 );
return false ;
}
void F_15 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
unsigned long V_29 ;
F_16 ( & V_2 -> V_21 . V_30 , V_29 ) ;
F_17 ( & V_2 -> V_21 , V_19 ) ;
V_2 -> V_31 += V_19 -> V_22 ;
if ( V_2 -> V_31 > V_2 -> V_32 )
F_18 ( F_19 ( V_2 -> V_33 -> V_34 , V_2 -> V_35 ) ) ;
F_20 ( & V_2 -> V_21 . V_30 , V_29 ) ;
}
static struct V_18 * F_21 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
F_22 ( & V_2 -> V_21 . V_30 ) ;
V_19 = F_23 ( & V_2 -> V_21 ) ;
if ( V_19 )
V_2 -> V_31 -= V_19 -> V_22 ;
F_24 ( & V_2 -> V_21 . V_30 ) ;
return V_19 ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_21 . V_30 ) ;
if ( V_2 -> V_31 < V_2 -> V_32 )
F_26 ( F_19 ( V_2 -> V_33 -> V_34 , V_2 -> V_35 ) ) ;
F_24 ( & V_2 -> V_21 . V_30 ) ;
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
if ( F_30 ( V_36 , F_31 ( V_19 ) -> V_37 ) )
break;
F_21 ( V_2 ) ;
F_28 ( V_19 ) ;
}
}
static struct V_38 * F_32 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_38 * V_41 ;
struct V_42 V_43 ;
F_33 ( & V_2 -> V_24 , V_2 -> V_24 . V_27 ++ , & V_43 ) ;
V_41 = V_40 -> V_41 + V_40 -> V_44 ++ ;
V_41 -> V_45 = V_46 ;
V_41 -> V_47 = 0 ;
V_41 -> V_48 = 0 ;
V_41 -> V_35 = V_43 . V_35 ;
V_40 -> V_49 = 0 ;
V_40 -> V_50 = V_43 . V_51 ;
return V_41 ;
}
static void F_34 ( unsigned long V_52 ,
unsigned int V_53 ,
unsigned int * V_22 ,
struct V_54 * V_55 )
{
struct V_56 * V_57 ;
struct V_58 * V_59 ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_39 * V_40 = V_55 -> V_40 ;
struct V_60 * V_60 = V_55 -> V_60 ;
F_35 ( V_40 -> V_49 > V_61 ) ;
if ( V_40 -> V_49 == V_61 )
V_55 -> V_41 = F_32 ( V_2 , V_40 ) ;
if ( V_40 -> V_49 + * V_22 > V_61 )
* V_22 = V_61 - V_40 -> V_49 ;
V_57 = V_40 -> V_62 + V_40 -> V_63 ++ ;
V_57 -> V_29 = V_64 ;
V_57 -> V_22 = * V_22 ;
V_59 = V_58 ( V_60 ) ;
if ( V_59 ) {
V_57 -> V_65 . V_66 = V_59 -> V_66 ;
V_57 -> V_65 . V_67 . V_68 = V_59 -> V_51 ;
V_57 -> V_29 |= V_69 ;
} else {
V_57 -> V_65 . V_66 = V_70 ;
V_57 -> V_65 . V_67 . V_71 = V_52 ;
}
V_57 -> V_65 . V_53 = V_53 ;
V_57 -> V_72 . V_66 = V_2 -> V_33 -> V_66 ;
V_57 -> V_72 . V_53 = V_40 -> V_49 ;
V_57 -> V_72 . V_67 . V_68 = V_40 -> V_50 ;
V_40 -> V_49 += * V_22 ;
V_55 -> V_41 -> V_48 += * V_22 ;
if ( V_55 -> V_73 && ( ( 1 << V_55 -> V_45 ) & V_2 -> V_33 -> V_74 ) )
V_2 -> V_24 . V_27 ++ ;
V_55 -> V_73 = 0 ;
}
static void F_36 ( unsigned long V_52 ,
unsigned V_53 ,
unsigned int V_22 ,
void * V_75 )
{
unsigned int V_76 ;
while ( V_22 ) {
V_76 = V_22 ;
F_34 ( V_52 , V_53 , & V_76 , V_75 ) ;
V_53 += V_76 ;
V_22 -= V_76 ;
}
}
static void F_37 ( struct V_1 * V_2 , struct V_18 * V_19 ,
struct V_39 * V_40 ,
struct V_60 * V_60 , unsigned long V_48 ,
unsigned long V_53 , int * V_73 )
{
struct V_54 V_55 = {
. V_2 = V_2 ,
. V_40 = V_40 ,
. V_73 = * V_73 ,
. V_45 = V_46 ,
} ;
unsigned long V_76 ;
if ( F_13 ( V_19 ) ) {
if ( F_38 ( V_19 ) -> V_45 & V_77 )
V_55 . V_45 = V_78 ;
else if ( F_38 ( V_19 ) -> V_45 & V_79 )
V_55 . V_45 = V_80 ;
}
F_35 ( V_48 + V_53 > V_81 << F_39 ( V_60 ) ) ;
V_55 . V_41 = V_40 -> V_41 + V_40 -> V_44 - 1 ;
V_60 += V_53 >> V_82 ;
V_53 &= ~ V_83 ;
while ( V_48 > 0 ) {
F_35 ( V_53 >= V_81 ) ;
V_76 = V_81 - V_53 ;
if ( V_76 > V_48 )
V_76 = V_48 ;
V_55 . V_60 = V_60 ;
F_40 ( V_60 , V_53 , V_76 ,
F_36 ,
& V_55 ) ;
V_48 -= V_76 ;
V_53 = 0 ;
if ( V_48 ) {
F_35 ( ! F_41 ( V_60 ) ) ;
V_60 ++ ;
}
}
* V_73 = V_55 . V_73 ;
}
static int F_42 ( struct V_18 * V_19 ,
struct V_39 * V_40 ,
struct V_1 * V_2 )
{
struct V_84 * V_33 = F_43 ( V_19 -> V_34 ) ;
int V_85 = F_38 ( V_19 ) -> V_85 ;
int V_14 ;
struct V_42 V_43 ;
struct V_38 * V_41 ;
unsigned char * V_75 ;
int V_73 = 1 ;
int V_86 ;
int V_45 ;
V_86 = V_40 -> V_44 ;
V_45 = V_46 ;
if ( F_13 ( V_19 ) ) {
if ( F_38 ( V_19 ) -> V_45 & V_77 )
V_45 = V_78 ;
else if ( F_38 ( V_19 ) -> V_45 & V_79 )
V_45 = V_80 ;
}
if ( ( 1 << V_45 ) & V_33 -> V_87 ) {
F_33 ( & V_2 -> V_24 , V_2 -> V_24 . V_27 ++ , & V_43 ) ;
V_41 = V_40 -> V_41 + V_40 -> V_44 ++ ;
V_41 -> V_45 = V_45 ;
V_41 -> V_47 = F_38 ( V_19 ) -> V_47 ;
V_41 -> V_48 = 0 ;
V_41 -> V_35 = V_43 . V_35 ;
}
F_33 ( & V_2 -> V_24 , V_2 -> V_24 . V_27 ++ , & V_43 ) ;
V_41 = V_40 -> V_41 + V_40 -> V_44 ++ ;
if ( ( 1 << V_45 ) & V_33 -> V_74 ) {
V_41 -> V_45 = V_45 ;
V_41 -> V_47 = F_38 ( V_19 ) -> V_47 ;
} else {
V_41 -> V_45 = V_46 ;
V_41 -> V_47 = 0 ;
}
V_41 -> V_48 = 0 ;
V_41 -> V_35 = V_43 . V_35 ;
V_40 -> V_49 = 0 ;
V_40 -> V_50 = V_43 . V_51 ;
V_75 = V_19 -> V_75 ;
while ( V_75 < F_44 ( V_19 ) ) {
unsigned int V_53 = F_45 ( V_75 ) ;
unsigned int V_22 = V_81 - V_53 ;
if ( V_75 + V_22 > F_44 ( V_19 ) )
V_22 = F_44 ( V_19 ) - V_75 ;
F_37 ( V_2 , V_19 , V_40 ,
F_46 ( V_75 ) , V_22 , V_53 , & V_73 ) ;
V_75 += V_22 ;
}
for ( V_14 = 0 ; V_14 < V_85 ; V_14 ++ ) {
F_37 ( V_2 , V_19 , V_40 ,
F_47 ( & F_38 ( V_19 ) -> V_88 [ V_14 ] ) ,
F_48 ( & F_38 ( V_19 ) -> V_88 [ V_14 ] ) ,
F_38 ( V_19 ) -> V_88 [ V_14 ] . V_13 ,
& V_73 ) ;
}
return V_40 -> V_44 - V_86 ;
}
static int F_49 ( struct V_84 * V_33 , int V_89 ,
struct V_39 * V_40 )
{
struct V_56 * V_90 ;
int V_91 = V_92 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_89 ; V_14 ++ ) {
V_90 = V_40 -> V_62 + V_40 -> V_93 ++ ;
if ( V_90 -> V_91 != V_94 ) {
F_50 ( V_33 -> V_34 ,
L_1 ,
V_90 -> V_91 , V_33 -> V_66 ) ;
V_91 = V_95 ;
}
}
return V_91 ;
}
static void F_51 ( struct V_1 * V_2 , int V_91 ,
struct V_38 * V_41 ,
int V_89 )
{
int V_14 ;
unsigned long V_53 ;
if ( V_89 <= 1 )
return;
V_89 -- ;
for ( V_14 = 0 ; V_14 < V_89 ; V_14 ++ ) {
int V_29 ;
if ( V_14 == V_89 - 1 )
V_29 = 0 ;
else
V_29 = V_96 ;
V_53 = 0 ;
F_52 ( V_2 , V_41 [ V_14 ] . V_35 , V_91 , V_53 ,
V_41 [ V_14 ] . V_48 , V_29 ) ;
}
}
void F_53 ( struct V_1 * V_2 )
{
F_54 ( & V_2 -> V_97 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
T_5 V_91 ;
T_1 V_29 ;
struct V_98 * V_99 ;
struct V_100 V_101 ;
struct V_18 * V_19 ;
F_56 ( V_102 ) ;
int V_103 ;
unsigned long V_53 ;
bool V_104 = false ;
struct V_39 V_40 = {
. V_62 = V_2 -> V_105 ,
. V_41 = V_2 -> V_41 ,
} ;
F_57 ( & V_101 ) ;
while ( F_10 ( V_2 )
&& ( V_19 = F_21 ( V_2 ) ) != NULL ) {
V_2 -> V_106 = V_36 ;
F_31 ( V_19 ) -> V_107 = F_42 ( V_19 , & V_40 , V_2 ) ;
F_17 ( & V_101 , V_19 ) ;
}
F_35 ( V_40 . V_44 > F_58 ( V_2 -> V_41 ) ) ;
if ( ! V_40 . V_63 )
goto V_108;
F_35 ( V_40 . V_63 > V_109 ) ;
F_59 ( V_2 -> V_105 , V_40 . V_63 ) ;
while ( ( V_19 = F_23 ( & V_101 ) ) != NULL ) {
if ( ( 1 << V_2 -> V_41 [ V_40 . V_110 ] . V_45 ) &
V_2 -> V_33 -> V_87 ) {
V_99 = F_60 ( & V_2 -> V_24 ,
V_2 -> V_24 . V_111 ++ ) ;
V_99 -> V_29 = V_112 | V_96 ;
V_99 -> V_53 = V_2 -> V_41 [ V_40 . V_110 ] . V_47 ;
V_99 -> V_35 = V_2 -> V_41 [ V_40 . V_110 ] . V_35 ;
V_99 -> V_91 = F_31 ( V_19 ) -> V_107 ;
V_40 . V_110 ++ ;
F_31 ( V_19 ) -> V_107 -- ;
}
V_2 -> V_113 . V_114 += V_19 -> V_22 ;
V_2 -> V_113 . V_115 ++ ;
V_91 = F_49 ( V_2 -> V_33 ,
F_31 ( V_19 ) -> V_107 ,
& V_40 ) ;
if ( F_31 ( V_19 ) -> V_107 == 1 )
V_29 = 0 ;
else
V_29 = V_96 ;
if ( V_19 -> V_116 == V_117 )
V_29 |= V_118 | V_119 ;
else if ( V_19 -> V_116 == V_120 )
V_29 |= V_119 ;
V_53 = 0 ;
V_99 = F_52 ( V_2 , V_2 -> V_41 [ V_40 . V_110 ] . V_35 ,
V_91 , V_53 ,
V_2 -> V_41 [ V_40 . V_110 ] . V_48 ,
V_29 ) ;
if ( ( 1 << V_2 -> V_41 [ V_40 . V_110 ] . V_45 ) &
V_2 -> V_33 -> V_74 ) {
struct V_121 * V_122 =
(struct V_121 * )
F_60 ( & V_2 -> V_24 ,
V_2 -> V_24 . V_111 ++ ) ;
V_99 -> V_29 |= V_123 ;
V_122 -> V_67 . V_122 . type = V_2 -> V_41 [ V_40 . V_110 ] . V_45 ;
V_122 -> V_67 . V_122 . V_48 = V_2 -> V_41 [ V_40 . V_110 ] . V_47 ;
V_122 -> V_67 . V_122 . V_124 = 0 ;
V_122 -> V_67 . V_122 . V_125 = 0 ;
V_122 -> type = V_126 ;
V_122 -> V_29 = 0 ;
}
F_51 ( V_2 , V_91 ,
V_2 -> V_41 + V_40 . V_110 + 1 ,
F_31 ( V_19 ) -> V_107 ) ;
F_61 ( & V_2 -> V_24 , V_103 ) ;
V_104 |= ! ! V_103 ;
V_40 . V_110 += F_31 ( V_19 ) -> V_107 ;
F_62 ( V_19 ) ;
}
V_108:
if ( V_104 )
F_63 ( V_2 -> V_127 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
int V_128 ;
F_65 ( & V_2 -> V_129 , V_128 ) ;
if ( V_128 )
F_66 ( & V_2 -> V_130 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
unsigned long V_131 , V_132 ;
V_131 = F_68 ( 131072UL , V_2 -> V_133 ) ;
V_132 = V_2 -> V_134 + V_2 -> V_133 ;
if ( V_132 < V_2 -> V_134 )
V_132 = V_135 ;
V_2 -> V_134 = F_69 ( V_132 , V_131 ) ;
}
void F_70 ( unsigned long V_75 )
{
struct V_1 * V_2 = (struct V_1 * ) V_75 ;
F_67 ( V_2 ) ;
F_64 ( V_2 ) ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_136 * V_137 , T_4 V_138 )
{
T_4 V_17 = V_2 -> V_129 . V_27 ;
unsigned long V_29 ;
do {
F_16 ( & V_2 -> V_139 , V_29 ) ;
F_72 ( V_2 , V_137 , V_95 ) ;
F_73 ( V_2 ) ;
F_20 ( & V_2 -> V_139 , V_29 ) ;
if ( V_17 == V_138 )
break;
F_33 ( & V_2 -> V_129 , V_17 ++ , V_137 ) ;
} while ( 1 );
V_2 -> V_129 . V_27 = V_17 ;
}
static void F_74 ( struct V_84 * V_33 )
{
F_75 ( V_33 -> V_34 , L_2 ) ;
V_33 -> V_140 = true ;
if ( V_33 -> V_141 )
F_53 ( & V_33 -> V_141 [ 0 ] ) ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_136 * V_142 ,
struct V_136 * V_137 ,
int V_143 )
{
T_4 V_17 = V_2 -> V_129 . V_27 ;
int V_144 = 0 ;
int V_145 = 0 ;
int V_146 ;
if ( ! ( V_142 -> V_29 & V_147 ) )
return 0 ;
do {
struct V_136 V_148 = { 0 } ;
if ( V_144 >= V_143 ) {
F_75 ( V_2 -> V_33 -> V_34 ,
L_3 ,
V_143 ) ;
F_74 ( V_2 -> V_33 ) ;
return - V_149 ;
}
if ( F_77 ( V_144 >= V_150 ) ) {
F_75 ( V_2 -> V_33 -> V_34 ,
L_4 ,
V_144 , V_150 ) ;
F_74 ( V_2 -> V_33 ) ;
return - V_151 ;
}
if ( ! V_145 && V_144 >= V_152 ) {
if ( F_78 () )
F_50 ( V_2 -> V_33 -> V_34 ,
L_5 ,
V_144 , V_152 ) ;
V_145 = - V_151 ;
}
if ( V_145 )
V_137 = & V_148 ;
F_33 ( & V_2 -> V_129 , V_17 + V_144 , V_137 ) ;
if ( ! V_145 && V_137 -> V_48 > V_142 -> V_48 ) {
if ( F_78 () )
F_50 ( V_2 -> V_33 -> V_34 ,
L_6 ,
V_137 -> V_48 , V_142 -> V_48 ) ;
V_145 = - V_153 ;
}
V_142 -> V_48 -= V_137 -> V_48 ;
V_144 ++ ;
if ( F_77 ( ( V_137 -> V_53 + V_137 -> V_48 ) > V_23 ) ) {
F_75 ( V_2 -> V_33 -> V_34 , L_7 ,
V_137 -> V_53 , V_137 -> V_48 ) ;
F_74 ( V_2 -> V_33 ) ;
return - V_154 ;
}
V_146 = V_137 -> V_29 & V_147 ;
if ( ! V_145 )
V_137 ++ ;
} while ( V_146 );
if ( V_145 ) {
F_71 ( V_2 , V_142 , V_17 + V_144 ) ;
return V_145 ;
}
return V_144 ;
}
static inline void F_79 ( struct V_1 * V_2 ,
T_1 V_7 ,
struct V_136 * V_137 ,
struct V_155 * V_156 )
{
V_2 -> V_157 [ V_156 - V_2 -> V_158 ] = V_2 -> V_4 [ V_7 ] ;
F_80 ( V_156 , F_3 ( V_2 , V_7 ) ,
V_159 | V_160 ,
V_137 -> V_51 , V_2 -> V_33 -> V_66 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_43 , V_137 ,
sizeof( * V_137 ) ) ;
}
static inline struct V_18 * F_81 ( unsigned int V_48 )
{
struct V_18 * V_19 =
F_82 ( V_48 + V_161 + V_162 ,
V_163 | V_164 ) ;
if ( F_77 ( V_19 == NULL ) )
return NULL ;
F_83 ( V_19 , V_161 + V_162 ) ;
F_38 ( V_19 ) -> V_165 = NULL ;
return V_19 ;
}
static struct V_155 * F_84 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_136 * V_137 ,
struct V_155 * V_166 ,
unsigned int V_167 ,
struct V_18 * V_168 )
{
struct V_169 * V_170 = F_38 ( V_19 ) ;
T_2 * V_88 = V_170 -> V_88 ;
T_1 V_7 = F_85 ( V_19 ) -> V_7 ;
int V_171 ;
T_3 V_172 ;
unsigned int V_173 ;
V_173 = V_170 -> V_85 ;
V_171 = ( F_7 ( & V_170 -> V_88 [ 0 ] ) == V_7 ) ;
for ( V_170 -> V_85 = V_171 ; V_170 -> V_85 < V_173 ;
V_170 -> V_85 ++ , V_137 ++ , V_166 ++ ) {
V_172 = F_9 ( V_2 -> V_174 ++ ) ;
V_7 = V_2 -> V_175 [ V_172 ] ;
F_79 ( V_2 , V_7 , V_137 , V_166 ) ;
F_8 ( & V_88 [ V_170 -> V_85 ] , V_7 ) ;
}
if ( V_167 ) {
V_170 = F_38 ( V_168 ) ;
V_88 = V_170 -> V_88 ;
for ( V_170 -> V_85 = 0 ; V_170 -> V_85 < V_167 ;
V_170 -> V_85 ++ , V_137 ++ , V_166 ++ ) {
V_172 = F_9 ( V_2 -> V_174 ++ ) ;
V_7 = V_2 -> V_175 [ V_172 ] ;
F_79 ( V_2 , V_7 , V_137 , V_166 ) ;
F_8 ( & V_88 [ V_170 -> V_85 ] ,
V_7 ) ;
}
F_38 ( V_19 ) -> V_176 = V_168 ;
}
return V_166 ;
}
static inline void F_86 ( struct V_1 * V_2 ,
T_1 V_7 ,
T_6 V_177 )
{
if ( F_77 ( V_2 -> V_178 [ V_7 ] !=
V_179 ) ) {
F_75 ( V_2 -> V_33 -> V_34 ,
L_8 ,
V_7 ) ;
F_87 () ;
}
V_2 -> V_178 [ V_7 ] = V_177 ;
}
static inline void F_88 ( struct V_1 * V_2 ,
T_1 V_7 )
{
if ( F_77 ( V_2 -> V_178 [ V_7 ] ==
V_179 ) ) {
F_75 ( V_2 -> V_33 -> V_34 ,
L_9 ,
V_7 ) ;
F_87 () ;
}
V_2 -> V_178 [ V_7 ] = V_179 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_155 * * V_180 ,
struct V_56 * * V_181 )
{
struct V_155 * V_182 = * V_180 ;
T_1 V_7 = F_85 ( V_19 ) -> V_7 ;
struct V_169 * V_170 = F_38 ( V_19 ) ;
struct V_169 * V_183 = NULL ;
int V_85 = V_170 -> V_85 ;
const bool V_184 = V_85 &&
F_7 ( & V_170 -> V_88 [ 0 ] ) == V_7 ;
int V_14 , V_185 ;
V_185 = ( * V_181 ) -> V_91 ;
if ( F_77 ( V_185 ) ) {
if ( F_78 () )
F_50 ( V_2 -> V_33 -> V_34 ,
L_10 ,
( * V_181 ) -> V_91 ,
V_7 ,
( * V_181 ) -> V_65 . V_67 . V_68 ) ;
if ( ! V_184 )
F_90 ( V_2 , V_7 ,
V_95 ) ;
}
( * V_181 ) ++ ;
V_186:
for ( V_14 = 0 ; V_14 < V_85 ; V_14 ++ , V_182 ++ ) {
int V_187 , V_188 ;
V_7 = F_7 ( & V_170 -> V_88 [ V_14 ] ) ;
V_188 = V_182 -> V_91 ;
if ( F_91 ( ! V_188 ) ) {
F_86 ( V_2 ,
V_7 ,
V_182 -> V_177 ) ;
if ( F_77 ( V_185 ) ) {
F_92 ( V_2 , V_7 ) ;
if ( V_14 == 0 && V_184 )
F_90 ( V_2 , V_7 ,
V_95 ) ;
else
F_90 ( V_2 , V_7 ,
V_92 ) ;
}
continue;
}
if ( F_78 () )
F_50 ( V_2 -> V_33 -> V_34 ,
L_11 ,
V_14 ,
V_182 -> V_91 ,
V_7 ,
V_182 -> V_68 ) ;
F_90 ( V_2 , V_7 , V_95 ) ;
if ( V_185 )
continue;
if ( ! V_184 )
F_90 ( V_2 ,
F_85 ( V_19 ) -> V_7 ,
V_92 ) ;
for ( V_187 = 0 ; V_187 < V_14 ; V_187 ++ ) {
V_7 = F_7 ( & V_170 -> V_88 [ V_187 ] ) ;
F_92 ( V_2 , V_7 ) ;
F_90 ( V_2 , V_7 ,
V_92 ) ;
}
if ( V_183 ) {
for ( V_187 = 0 ; V_187 < V_183 -> V_85 ; V_187 ++ ) {
V_7 = F_7 ( & V_183 -> V_88 [ V_187 ] ) ;
F_92 ( V_2 , V_7 ) ;
F_90 ( V_2 , V_7 ,
V_92 ) ;
}
}
V_185 = V_188 ;
}
if ( F_93 ( V_19 ) && ! V_183 ) {
V_183 = F_38 ( V_19 ) ;
V_170 = F_38 ( F_38 ( V_19 ) -> V_176 ) ;
V_85 = V_170 -> V_85 ;
goto V_186;
}
* V_180 = V_182 ;
return V_185 ;
}
static void F_94 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_169 * V_170 = F_38 ( V_19 ) ;
int V_85 = V_170 -> V_85 ;
int V_14 ;
T_1 V_189 = V_190 ;
for ( V_14 = 0 ; V_14 < V_85 ; V_14 ++ ) {
T_2 * V_12 = V_170 -> V_88 + V_14 ;
struct V_136 * V_137 ;
struct V_60 * V_60 ;
T_1 V_7 ;
V_7 = F_7 ( V_12 ) ;
if ( V_189 == V_190 )
F_38 ( V_19 ) -> V_165 =
& F_95 ( V_2 , V_7 ) ;
else
F_95 ( V_2 , V_189 ) . V_191 =
& F_95 ( V_2 , V_7 ) ;
F_95 ( V_2 , V_7 ) . V_191 = NULL ;
V_189 = V_7 ;
V_137 = & V_2 -> V_9 [ V_7 ] . V_43 ;
V_60 = F_46 ( F_3 ( V_2 , V_7 ) ) ;
F_96 ( V_19 , V_14 , V_60 , V_137 -> V_53 , V_137 -> V_48 ) ;
V_19 -> V_22 += V_137 -> V_48 ;
V_19 -> V_192 += V_137 -> V_48 ;
V_19 -> V_193 += V_137 -> V_48 ;
F_97 ( V_2 -> V_4 [ V_7 ] ) ;
}
}
static int F_98 ( struct V_1 * V_2 ,
struct V_121 * V_194 ,
int V_143 )
{
struct V_121 V_195 ;
T_4 V_17 = V_2 -> V_129 . V_27 ;
do {
if ( F_77 ( V_143 -- <= 0 ) ) {
F_75 ( V_2 -> V_33 -> V_34 , L_12 ) ;
F_74 ( V_2 -> V_33 ) ;
return - V_196 ;
}
F_33 ( & V_2 -> V_129 , V_17 , & V_195 ) ;
if ( F_77 ( ! V_195 . type ||
V_195 . type >= V_197 ) ) {
V_2 -> V_129 . V_27 = ++ V_17 ;
F_75 ( V_2 -> V_33 -> V_34 ,
L_13 , V_195 . type ) ;
F_74 ( V_2 -> V_33 ) ;
return - V_154 ;
}
memcpy ( & V_194 [ V_195 . type - 1 ] , & V_195 , sizeof( V_195 ) ) ;
V_2 -> V_129 . V_27 = ++ V_17 ;
} while ( V_195 . V_29 & V_198 );
return V_143 ;
}
static int F_99 ( struct V_84 * V_33 ,
struct V_18 * V_19 ,
struct V_121 * V_122 )
{
if ( ! V_122 -> V_67 . V_122 . V_48 ) {
F_75 ( V_33 -> V_34 , L_14 ) ;
F_74 ( V_33 ) ;
return - V_154 ;
}
switch ( V_122 -> V_67 . V_122 . type ) {
case V_78 :
F_38 ( V_19 ) -> V_45 = V_77 ;
break;
case V_80 :
F_38 ( V_19 ) -> V_45 = V_79 ;
break;
default:
F_75 ( V_33 -> V_34 , L_15 , V_122 -> V_67 . V_122 . type ) ;
F_74 ( V_33 ) ;
return - V_154 ;
}
F_38 ( V_19 ) -> V_47 = V_122 -> V_67 . V_122 . V_48 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
bool V_199 = false ;
if ( V_19 -> V_116 != V_117 && F_13 ( V_19 ) ) {
V_2 -> V_113 . V_200 ++ ;
V_19 -> V_116 = V_117 ;
V_199 = true ;
}
if ( V_19 -> V_116 != V_117 )
return 0 ;
return F_101 ( V_19 , V_199 ) ;
}
static bool F_102 ( struct V_1 * V_2 , unsigned V_48 )
{
T_7 V_201 = F_103 () ;
T_7 V_202 = V_2 -> V_203 +
F_104 ( V_2 -> V_204 / 1000 ) ;
if ( F_105 ( & V_2 -> V_205 ) )
return true ;
if ( F_106 ( V_201 , V_202 ) ) {
V_2 -> V_203 = V_201 ;
F_67 ( V_2 ) ;
}
if ( V_48 > V_2 -> V_134 ) {
V_2 -> V_205 . V_75 =
( unsigned long ) V_2 ;
F_107 ( & V_2 -> V_205 ,
V_202 ) ;
V_2 -> V_203 = V_202 ;
return true ;
}
return false ;
}
static int F_108 ( struct V_84 * V_33 , const T_8 * V_206 )
{
struct V_207 * V_208 ;
if ( V_33 -> V_209 == V_210 ) {
if ( F_78 () )
F_75 ( V_33 -> V_34 ,
L_16 ) ;
return - V_211 ;
}
V_208 = F_109 ( sizeof( * V_208 ) , V_163 ) ;
if ( ! V_208 )
return - V_212 ;
F_110 ( V_208 -> V_206 , V_206 ) ;
F_111 ( & V_208 -> V_213 , & V_33 -> V_214 ) ;
V_33 -> V_209 ++ ;
return 0 ;
}
static void F_112 ( struct V_84 * V_33 , const T_8 * V_206 )
{
struct V_207 * V_208 ;
F_113 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_114 ( V_206 , V_208 -> V_206 ) ) {
-- V_33 -> V_209 ;
F_115 ( & V_208 -> V_213 ) ;
F_116 ( V_208 , V_215 ) ;
break;
}
}
}
bool F_117 ( struct V_84 * V_33 , const T_8 * V_206 )
{
struct V_207 * V_208 ;
F_118 () ;
F_113 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_114 ( V_206 , V_208 -> V_206 ) ) {
F_119 () ;
return true ;
}
}
F_119 () ;
return false ;
}
void F_120 ( struct V_84 * V_33 )
{
while ( ! F_121 ( & V_33 -> V_214 ) ) {
struct V_207 * V_208 ;
V_208 = F_122 ( & V_33 -> V_214 ,
struct V_207 ,
V_213 ) ;
-- V_33 -> V_209 ;
F_123 ( & V_208 -> V_213 ) ;
F_124 ( V_208 ) ;
}
}
static void F_125 ( struct V_1 * V_2 ,
int V_216 ,
unsigned * V_217 ,
unsigned * V_218 )
{
struct V_155 * V_166 = V_2 -> V_158 ;
struct V_18 * V_19 , * V_168 ;
int V_103 ;
unsigned int V_167 ;
while ( F_126 ( & V_2 -> V_219 ) < V_216 ) {
struct V_136 V_220 ;
struct V_136 V_221 [ V_152 ] ;
struct V_121 V_194 [ V_197 - 1 ] ;
T_1 V_7 ;
T_4 V_3 ;
int V_143 ;
unsigned int V_192 ;
T_3 V_172 ;
if ( V_2 -> V_129 . V_25 -> V_26 - V_2 -> V_129 . V_27 >
V_222 ) {
F_75 ( V_2 -> V_33 -> V_34 ,
L_17
L_18 ,
V_2 -> V_129 . V_25 -> V_26 , V_2 -> V_129 . V_27 ,
V_222 ) ;
F_74 ( V_2 -> V_33 ) ;
break;
}
V_143 = F_127 ( & V_2 -> V_129 ) ;
if ( ! V_143 )
break;
V_3 = V_2 -> V_129 . V_27 ;
F_128 () ;
F_33 ( & V_2 -> V_129 , V_3 , & V_220 ) ;
if ( V_220 . V_48 > V_2 -> V_134 &&
F_102 ( V_2 , V_220 . V_48 ) )
break;
V_2 -> V_134 -= V_220 . V_48 ;
V_143 -- ;
V_2 -> V_129 . V_27 = ++ V_3 ;
memset ( V_194 , 0 , sizeof( V_194 ) ) ;
if ( V_220 . V_29 & V_223 ) {
V_143 = F_98 ( V_2 , V_194 ,
V_143 ) ;
V_3 = V_2 -> V_129 . V_27 ;
if ( F_77 ( V_143 < 0 ) )
break;
}
if ( V_194 [ V_224 - 1 ] . type ) {
struct V_121 * V_195 ;
V_195 = & V_194 [ V_224 - 1 ] ;
V_103 = F_108 ( V_2 -> V_33 , V_195 -> V_67 . V_208 . V_206 ) ;
F_72 ( V_2 , & V_220 ,
( V_103 == 0 ) ?
V_92 :
V_95 ) ;
F_73 ( V_2 ) ;
continue;
}
if ( V_194 [ V_225 - 1 ] . type ) {
struct V_121 * V_195 ;
V_195 = & V_194 [ V_225 - 1 ] ;
F_112 ( V_2 -> V_33 , V_195 -> V_67 . V_208 . V_206 ) ;
F_72 ( V_2 , & V_220 , V_92 ) ;
F_73 ( V_2 ) ;
continue;
}
V_103 = F_76 ( V_2 , & V_220 , V_221 , V_143 ) ;
if ( F_77 ( V_103 < 0 ) )
break;
V_3 += V_103 ;
if ( F_77 ( V_220 . V_48 < V_226 ) ) {
F_50 ( V_2 -> V_33 -> V_34 ,
L_19 , V_220 . V_48 ) ;
F_71 ( V_2 , & V_220 , V_3 ) ;
break;
}
if ( F_77 ( ( V_220 . V_53 + V_220 . V_48 ) > V_23 ) ) {
F_75 ( V_2 -> V_33 -> V_34 ,
L_20 ,
V_220 . V_53 , V_220 . V_48 ,
( unsigned long ) ( V_220 . V_53 & ~ V_227 ) + V_220 . V_48 ) ;
F_74 ( V_2 -> V_33 ) ;
break;
}
V_172 = F_9 ( V_2 -> V_174 ) ;
V_7 = V_2 -> V_175 [ V_172 ] ;
V_192 = ( V_220 . V_48 > V_228 &&
V_103 < V_152 ) ?
V_228 : V_220 . V_48 ;
V_19 = F_81 ( V_192 ) ;
if ( F_77 ( V_19 == NULL ) ) {
F_50 ( V_2 -> V_33 -> V_34 ,
L_21 ) ;
F_71 ( V_2 , & V_220 , V_3 ) ;
break;
}
F_38 ( V_19 ) -> V_85 = V_103 ;
if ( V_192 < V_220 . V_48 )
F_38 ( V_19 ) -> V_85 ++ ;
V_167 = 0 ;
V_168 = NULL ;
if ( F_38 ( V_19 ) -> V_85 > V_229 ) {
V_167 = F_38 ( V_19 ) -> V_85 - V_229 ;
F_35 ( V_167 > V_229 ) ;
F_38 ( V_19 ) -> V_85 = V_229 ;
V_168 = F_81 ( 0 ) ;
if ( F_77 ( V_168 == NULL ) ) {
F_28 ( V_19 ) ;
F_71 ( V_2 , & V_220 , V_3 ) ;
if ( F_78 () )
F_75 ( V_2 -> V_33 -> V_34 ,
L_22 ) ;
break;
}
}
if ( V_194 [ V_126 - 1 ] . type ) {
struct V_121 * V_122 ;
V_122 = & V_194 [ V_126 - 1 ] ;
if ( F_99 ( V_2 -> V_33 , V_19 , V_122 ) ) {
F_28 ( V_19 ) ;
F_28 ( V_168 ) ;
break;
}
}
F_85 ( V_19 ) -> V_7 = V_7 ;
F_129 ( V_19 , V_192 ) ;
V_2 -> V_230 [ * V_217 ] . V_65 . V_67 . V_68 = V_220 . V_51 ;
V_2 -> V_230 [ * V_217 ] . V_65 . V_66 = V_2 -> V_33 -> V_66 ;
V_2 -> V_230 [ * V_217 ] . V_65 . V_53 = V_220 . V_53 ;
V_2 -> V_230 [ * V_217 ] . V_72 . V_67 . V_71 =
F_130 ( V_19 -> V_75 ) ;
V_2 -> V_230 [ * V_217 ] . V_72 . V_66 = V_70 ;
V_2 -> V_230 [ * V_217 ] . V_72 . V_53 =
F_45 ( V_19 -> V_75 ) & ~ V_227 ;
V_2 -> V_230 [ * V_217 ] . V_22 = V_192 ;
V_2 -> V_230 [ * V_217 ] . V_29 = V_69 ;
( * V_217 ) ++ ;
if ( V_192 < V_220 . V_48 ) {
F_8 ( & F_38 ( V_19 ) -> V_88 [ 0 ] ,
V_7 ) ;
F_79 ( V_2 , V_7 , & V_220 , V_166 ) ;
V_166 ++ ;
} else {
F_8 ( & F_38 ( V_19 ) -> V_88 [ 0 ] ,
V_190 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_43 , & V_220 ,
sizeof( V_220 ) ) ;
}
V_2 -> V_174 ++ ;
V_166 = F_84 ( V_2 , V_19 , V_221 , V_166 ,
V_167 , V_168 ) ;
F_17 ( & V_2 -> V_219 , V_19 ) ;
V_2 -> V_129 . V_27 = V_3 ;
if ( ( ( V_166 - V_2 -> V_158 ) >= F_58 ( V_2 -> V_158 ) ) ||
( * V_217 >= F_58 ( V_2 -> V_230 ) ) )
break;
}
( * V_218 ) = V_166 - V_2 -> V_158 ;
return;
}
static int F_131 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
unsigned int V_53 = F_132 ( V_19 ) ;
T_2 V_88 [ V_229 ] ;
int V_14 , V_231 ;
struct V_5 * V_232 ;
struct V_18 * V_168 = F_38 ( V_19 ) -> V_176 ;
V_2 -> V_113 . V_233 += 2 ;
V_2 -> V_113 . V_234 ++ ;
F_94 ( V_2 , V_168 ) ;
V_19 -> V_193 -= V_19 -> V_192 ;
V_19 -> V_22 += V_168 -> V_22 ;
V_19 -> V_192 += V_168 -> V_22 ;
for ( V_14 = 0 ; V_53 < V_19 -> V_22 ; V_14 ++ ) {
struct V_60 * V_60 ;
unsigned int V_22 ;
F_35 ( V_14 >= V_229 ) ;
V_60 = F_133 ( V_163 ) ;
if ( ! V_60 ) {
int V_187 ;
V_19 -> V_193 += V_19 -> V_192 ;
for ( V_187 = 0 ; V_187 < V_14 ; V_187 ++ )
F_134 ( V_88 [ V_187 ] . V_60 . V_235 ) ;
return - V_212 ;
}
if ( V_53 + V_81 < V_19 -> V_22 )
V_22 = V_81 ;
else
V_22 = V_19 -> V_22 - V_53 ;
if ( F_135 ( V_19 , V_53 , F_136 ( V_60 ) , V_22 ) )
F_87 () ;
V_53 += V_22 ;
V_88 [ V_14 ] . V_60 . V_235 = V_60 ;
V_88 [ V_14 ] . V_13 = 0 ;
F_137 ( & V_88 [ V_14 ] , V_22 ) ;
}
F_138 ( V_19 ) ;
F_139 ( V_2 , V_168 ) ;
F_28 ( V_168 ) ;
for ( V_231 = 0 ; V_231 < F_38 ( V_19 ) -> V_85 ; V_231 ++ )
F_140 ( V_19 , V_231 ) ;
V_232 = F_38 ( V_19 ) -> V_165 ;
F_141 ( & V_2 -> V_236 ) ;
V_232 -> V_237 ( V_232 , true ) ;
F_38 ( V_19 ) -> V_165 = NULL ;
memcpy ( F_38 ( V_19 ) -> V_88 , V_88 , V_14 * sizeof( T_2 ) ) ;
F_38 ( V_19 ) -> V_85 = V_14 ;
V_19 -> V_193 += V_14 * V_81 ;
return 0 ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_155 * V_182 = V_2 -> V_158 ;
struct V_56 * V_238 = V_2 -> V_230 ;
struct V_18 * V_19 ;
int V_239 = 0 ;
while ( ( V_19 = F_23 ( & V_2 -> V_219 ) ) != NULL ) {
struct V_136 * V_137 ;
T_1 V_7 ;
unsigned V_192 ;
V_7 = F_85 ( V_19 ) -> V_7 ;
V_137 = & V_2 -> V_9 [ V_7 ] . V_43 ;
if ( F_77 ( F_89 ( V_2 , V_19 , & V_182 , & V_238 ) ) ) {
F_38 ( V_19 ) -> V_85 = 0 ;
if ( F_93 ( V_19 ) ) {
struct V_18 * V_168 =
F_38 ( V_19 ) -> V_176 ;
F_38 ( V_168 ) -> V_85 = 0 ;
}
F_28 ( V_19 ) ;
continue;
}
V_192 = V_19 -> V_22 ;
F_95 ( V_2 , V_7 ) . V_191 = NULL ;
if ( V_192 < V_137 -> V_48 ) {
V_137 -> V_53 += V_192 ;
V_137 -> V_48 -= V_192 ;
} else {
F_90 ( V_2 , V_7 ,
V_92 ) ;
}
if ( V_137 -> V_29 & V_240 )
V_19 -> V_116 = V_117 ;
else if ( V_137 -> V_29 & V_241 )
V_19 -> V_116 = V_120 ;
F_94 ( V_2 , V_19 ) ;
if ( F_77 ( F_93 ( V_19 ) ) ) {
if ( F_131 ( V_2 , V_19 ) ) {
if ( F_78 () )
F_75 ( V_2 -> V_33 -> V_34 ,
L_23 ) ;
F_139 ( V_2 , V_19 ) ;
F_28 ( V_19 ) ;
continue;
}
}
V_19 -> V_34 = V_2 -> V_33 -> V_34 ;
V_19 -> V_242 = F_143 ( V_19 , V_19 -> V_34 ) ;
F_144 ( V_19 ) ;
if ( F_100 ( V_2 , V_19 ) ) {
F_50 ( V_2 -> V_33 -> V_34 ,
L_24 ) ;
if ( F_38 ( V_19 ) -> V_165 )
F_139 ( V_2 , V_19 ) ;
F_28 ( V_19 ) ;
continue;
}
F_145 ( V_19 , 0 ) ;
if ( F_13 ( V_19 ) ) {
int V_243 = F_38 ( V_19 ) -> V_47 ;
int V_244 = F_146 ( V_19 ) -
F_147 ( V_19 ) +
F_148 ( V_19 ) ;
F_38 ( V_19 ) -> V_245 =
F_12 ( V_19 -> V_22 - V_244 , V_243 ) ;
}
V_2 -> V_113 . V_246 += V_19 -> V_22 ;
V_2 -> V_113 . V_247 ++ ;
V_239 ++ ;
if ( F_38 ( V_19 ) -> V_165 ) {
F_139 ( V_2 , V_19 ) ;
V_2 -> V_113 . V_233 ++ ;
}
F_149 ( V_19 ) ;
}
return V_239 ;
}
void F_150 ( struct V_5 * V_6 , bool V_248 )
{
unsigned long V_29 ;
T_3 V_172 ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
F_16 ( & V_2 -> V_249 , V_29 ) ;
do {
T_1 V_7 = V_6 -> V_8 ;
V_6 = (struct V_5 * ) V_6 -> V_191 ;
F_35 ( V_2 -> V_250 - V_2 -> V_251 >=
V_15 ) ;
V_172 = F_9 ( V_2 -> V_250 ) ;
V_2 -> V_252 [ V_172 ] = V_7 ;
F_151 () ;
V_2 -> V_250 ++ ;
} while ( V_6 );
F_20 ( & V_2 -> V_249 , V_29 ) ;
if ( F_91 ( V_248 ) )
V_2 -> V_113 . V_253 ++ ;
else
V_2 -> V_113 . V_254 ++ ;
F_152 ( V_2 ) ;
}
static inline void F_153 ( struct V_1 * V_2 )
{
struct V_255 * V_166 ;
T_3 V_256 , V_257 ;
T_1 V_7 , V_258 [ V_15 ] ;
unsigned int V_14 = 0 ;
V_256 = V_2 -> V_251 ;
V_166 = V_2 -> V_259 ;
do {
V_257 = V_2 -> V_250 ;
F_154 () ;
while ( V_256 != V_257 ) {
F_35 ( V_166 - V_2 -> V_259 >= V_15 ) ;
V_7 =
V_2 -> V_252 [ F_9 ( V_256 ++ ) ] ;
V_258 [ V_166 - V_2 -> V_259 ] =
V_7 ;
V_2 -> V_260 [ V_166 - V_2 -> V_259 ] =
V_2 -> V_4 [ V_7 ] ;
F_155 ( V_166 ,
F_3 ( V_2 , V_7 ) ,
V_159 ,
V_2 -> V_178 [ V_7 ] ) ;
F_88 ( V_2 , V_7 ) ;
++ V_166 ;
}
} while ( V_257 != V_2 -> V_250 );
V_2 -> V_251 = V_256 ;
if ( V_166 - V_2 -> V_259 > 0 ) {
int V_103 ;
V_103 = F_156 ( V_2 -> V_259 ,
NULL ,
V_2 -> V_260 ,
V_166 - V_2 -> V_259 ) ;
if ( V_103 ) {
F_75 ( V_2 -> V_33 -> V_34 , L_25 ,
V_166 - V_2 -> V_259 , V_103 ) ;
for ( V_14 = 0 ; V_14 < V_166 - V_2 -> V_259 ; ++ V_14 ) {
if ( V_166 [ V_14 ] . V_91 != V_94 )
F_75 ( V_2 -> V_33 -> V_34 ,
L_26 ,
V_166 [ V_14 ] . V_261 ,
V_166 [ V_14 ] . V_177 ,
V_166 [ V_14 ] . V_91 ) ;
}
F_87 () ;
}
}
for ( V_14 = 0 ; V_14 < V_166 - V_2 -> V_259 ; ++ V_14 )
F_90 ( V_2 , V_258 [ V_14 ] ,
V_92 ) ;
}
int F_157 ( struct V_1 * V_2 , int V_216 )
{
unsigned V_262 , V_263 = 0 ;
int V_239 , V_103 ;
if ( F_77 ( ! F_158 ( V_2 ) ) )
return 0 ;
F_125 ( V_2 , V_216 , & V_263 , & V_262 ) ;
if ( V_263 == 0 )
return 0 ;
F_59 ( V_2 -> V_230 , V_263 ) ;
if ( V_262 != 0 ) {
V_103 = F_159 ( V_2 -> V_158 ,
NULL ,
V_2 -> V_157 ,
V_262 ) ;
F_35 ( V_103 ) ;
}
V_239 = F_142 ( V_2 ) ;
return V_239 ;
}
static void F_90 ( struct V_1 * V_2 , T_1 V_7 ,
T_8 V_91 )
{
struct V_9 * V_9 ;
T_3 V_172 ;
unsigned long V_29 ;
V_9 = & V_2 -> V_9 [ V_7 ] ;
F_16 ( & V_2 -> V_139 , V_29 ) ;
F_72 ( V_2 , & V_9 -> V_43 , V_91 ) ;
V_172 = F_9 ( V_2 -> V_264 ++ ) ;
V_2 -> V_175 [ V_172 ] = V_7 ;
F_73 ( V_2 ) ;
F_20 ( & V_2 -> V_139 , V_29 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_136 * V_137 ,
T_5 V_265 )
{
T_4 V_14 = V_2 -> V_129 . V_111 ;
struct V_266 * V_99 ;
V_99 = F_60 ( & V_2 -> V_129 , V_14 ) ;
V_99 -> V_35 = V_137 -> V_35 ;
V_99 -> V_91 = V_265 ;
if ( V_137 -> V_29 & V_223 )
F_60 ( & V_2 -> V_129 , ++ V_14 ) -> V_91 = V_267 ;
V_2 -> V_129 . V_111 = ++ V_14 ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_102 ;
F_61 ( & V_2 -> V_129 , V_102 ) ;
if ( V_102 )
F_63 ( V_2 -> V_268 ) ;
}
static struct V_98 * F_52 ( struct V_1 * V_2 ,
T_1 V_35 ,
T_5 V_265 ,
T_1 V_53 ,
T_1 V_48 ,
T_1 V_29 )
{
T_4 V_14 = V_2 -> V_24 . V_111 ;
struct V_98 * V_99 ;
V_99 = F_60 ( & V_2 -> V_24 , V_14 ) ;
V_99 -> V_53 = V_53 ;
V_99 -> V_29 = V_29 ;
V_99 -> V_35 = V_35 ;
V_99 -> V_91 = ( V_269 ) V_48 ;
if ( V_265 < 0 )
V_99 -> V_91 = ( V_269 ) V_265 ;
V_2 -> V_24 . V_111 = ++ V_14 ;
return V_99 ;
}
void F_92 ( struct V_1 * V_2 , T_1 V_7 )
{
int V_103 ;
struct V_255 V_270 ;
F_155 ( & V_270 ,
F_3 ( V_2 , V_7 ) ,
V_159 ,
V_2 -> V_178 [ V_7 ] ) ;
F_88 ( V_2 , V_7 ) ;
V_103 = F_156 ( & V_270 , NULL ,
& V_2 -> V_4 [ V_7 ] , 1 ) ;
if ( V_103 ) {
F_75 ( V_2 -> V_33 -> V_34 ,
L_27 ,
V_103 ,
V_7 ,
V_270 . V_261 ,
V_270 . V_177 ,
V_270 . V_91 ) ;
F_87 () ;
}
}
static inline int F_158 ( struct V_1 * V_2 )
{
if ( F_91 ( F_127 ( & V_2 -> V_129 ) ) )
return 1 ;
return 0 ;
}
static inline bool F_160 ( struct V_1 * V_2 )
{
return V_2 -> V_251 != V_2 -> V_250 ;
}
void F_161 ( struct V_1 * V_2 )
{
if ( V_2 -> V_129 . V_25 )
F_162 ( F_163 ( V_2 -> V_33 ) ,
V_2 -> V_129 . V_25 ) ;
if ( V_2 -> V_24 . V_25 )
F_162 ( F_163 ( V_2 -> V_33 ) ,
V_2 -> V_24 . V_25 ) ;
}
int F_164 ( struct V_1 * V_2 ,
T_9 V_271 ,
T_9 V_272 )
{
void * V_206 ;
struct V_273 * V_274 ;
struct V_275 * V_276 ;
int V_185 = - V_212 ;
V_185 = F_165 ( F_163 ( V_2 -> V_33 ) ,
& V_271 , 1 , & V_206 ) ;
if ( V_185 )
goto V_185;
V_274 = (struct V_273 * ) V_206 ;
F_166 ( & V_2 -> V_129 , V_274 , V_23 ) ;
V_185 = F_165 ( F_163 ( V_2 -> V_33 ) ,
& V_272 , 1 , & V_206 ) ;
if ( V_185 )
goto V_185;
V_276 = (struct V_275 * ) V_206 ;
F_166 ( & V_2 -> V_24 , V_276 , V_23 ) ;
return 0 ;
V_185:
F_161 ( V_2 ) ;
return V_185 ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_84 * V_33 = V_2 -> V_33 ;
V_2 -> V_277 = true ;
F_168 ( & V_33 -> V_30 ) ;
if ( V_33 -> V_278 ++ == 0 ) {
F_169 ( V_33 -> V_34 , L_28 ) ;
F_170 ( V_33 -> V_34 ) ;
}
F_171 ( & V_33 -> V_30 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_84 * V_33 = V_2 -> V_33 ;
V_2 -> V_106 = V_36 ;
V_2 -> V_277 = false ;
F_168 ( & V_33 -> V_30 ) ;
if ( -- V_33 -> V_278 == 0 ) {
F_169 ( V_33 -> V_34 , L_29 ) ;
F_173 ( V_33 -> V_34 ) ;
}
F_171 ( & V_33 -> V_30 ) ;
}
static bool F_174 ( struct V_1 * V_2 )
{
T_4 V_16 , V_17 ;
V_16 = V_2 -> V_24 . V_25 -> V_26 ;
V_17 = V_2 -> V_24 . V_27 ;
return ! V_2 -> V_277 && V_16 - V_17 < 1
&& F_175 ( V_36 ,
V_2 -> V_106 + V_2 -> V_33 -> V_279 ) ;
}
static bool F_176 ( struct V_1 * V_2 )
{
T_4 V_16 , V_17 ;
V_16 = V_2 -> V_24 . V_25 -> V_26 ;
V_17 = V_2 -> V_24 . V_27 ;
return V_2 -> V_277 && V_16 - V_17 >= 1 ;
}
static bool F_177 ( struct V_1 * V_2 )
{
return F_10 ( V_2 )
|| ( V_2 -> V_33 -> V_279 &&
( F_174 ( V_2 )
|| F_176 ( V_2 ) ) )
|| F_178 ()
|| V_2 -> V_33 -> V_140 ;
}
static long F_179 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
long V_280 ;
V_19 = F_11 ( & V_2 -> V_21 ) ;
if ( ! V_19 )
return V_281 ;
V_280 = F_31 ( V_19 ) -> V_37 - V_36 ;
return V_280 < 0 ? 0 : V_280 ;
}
static void F_180 ( struct V_1 * V_2 )
{
F_181 ( V_282 ) ;
if ( F_177 ( V_2 ) )
return;
for (; ; ) {
long V_103 ;
F_182 ( & V_2 -> V_97 , & V_282 , V_283 ) ;
if ( F_177 ( V_2 ) )
break;
V_103 = F_183 ( F_179 ( V_2 ) ) ;
if ( ! V_103 )
break;
}
F_184 ( & V_2 -> V_97 , & V_282 ) ;
}
int F_185 ( void * V_75 )
{
struct V_1 * V_2 = V_75 ;
struct V_84 * V_33 = V_2 -> V_33 ;
if ( ! V_33 -> V_279 )
F_172 ( V_2 ) ;
for (; ; ) {
F_180 ( V_2 ) ;
if ( F_178 () )
break;
if ( F_77 ( V_33 -> V_140 && V_2 -> V_35 == 0 ) ) {
F_186 ( V_33 ) ;
break;
}
if ( ! F_187 ( & V_2 -> V_21 ) )
F_55 ( V_2 ) ;
if ( V_33 -> V_279 ) {
if ( F_174 ( V_2 ) )
F_167 ( V_2 ) ;
else if ( F_176 ( V_2 ) )
F_172 ( V_2 ) ;
}
F_29 ( V_2 ) ;
F_25 ( V_2 ) ;
F_188 () ;
}
F_27 ( V_2 ) ;
return 0 ;
}
static bool F_189 ( struct V_1 * V_2 )
{
return F_178 () &&
! F_190 ( & V_2 -> V_236 ) ;
}
int F_191 ( void * V_75 )
{
struct V_1 * V_2 = V_75 ;
for (; ; ) {
F_192 ( V_2 -> V_284 ,
F_160 ( V_2 ) ||
F_189 ( V_2 ) ) ;
if ( F_189 ( V_2 ) )
break;
F_153 ( V_2 ) ;
F_188 () ;
}
if ( F_160 ( V_2 ) )
F_153 ( V_2 ) ;
return 0 ;
}
static int T_10 F_193 ( void )
{
int V_285 = 0 ;
if ( ! F_194 () )
return - V_286 ;
if ( V_287 == 0 )
V_287 = F_195 () ;
if ( V_150 < V_152 ) {
F_196 ( L_30 ,
V_150 , V_152 ) ;
V_150 = V_152 ;
}
V_285 = F_197 () ;
if ( V_285 )
goto V_288;
#ifdef F_198
V_289 = F_199 ( L_31 , NULL ) ;
if ( F_200 ( V_289 ) )
F_201 ( L_32 ,
F_202 ( V_289 ) ) ;
#endif
return 0 ;
V_288:
return V_285 ;
}
static void T_11 F_203 ( void )
{
#ifdef F_198
if ( ! F_200 ( V_289 ) )
F_204 ( V_289 ) ;
#endif
F_205 () ;
}
