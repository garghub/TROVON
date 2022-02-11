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
struct V_136 * V_137 ,
unsigned int V_138 , T_4 V_139 )
{
T_4 V_17 = V_2 -> V_129 . V_27 ;
unsigned long V_29 ;
do {
F_16 ( & V_2 -> V_140 , V_29 ) ;
F_72 ( V_2 , V_137 , V_138 , V_95 ) ;
F_73 ( V_2 ) ;
F_20 ( & V_2 -> V_140 , V_29 ) ;
if ( V_17 == V_139 )
break;
F_33 ( & V_2 -> V_129 , V_17 ++ , V_137 ) ;
V_138 = 0 ;
} while ( 1 );
V_2 -> V_129 . V_27 = V_17 ;
}
static void F_74 ( struct V_84 * V_33 )
{
F_75 ( V_33 -> V_34 , L_2 ) ;
V_33 -> V_141 = true ;
if ( V_33 -> V_142 )
F_53 ( & V_33 -> V_142 [ 0 ] ) ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_136 * V_143 ,
unsigned int V_138 ,
struct V_136 * V_137 ,
int V_144 )
{
T_4 V_17 = V_2 -> V_129 . V_27 ;
int V_145 = 0 ;
int V_146 = 0 ;
int V_147 ;
if ( ! ( V_143 -> V_29 & V_148 ) )
return 0 ;
do {
struct V_136 V_149 = { 0 } ;
if ( V_145 >= V_144 ) {
F_75 ( V_2 -> V_33 -> V_34 ,
L_3 ,
V_144 ) ;
F_74 ( V_2 -> V_33 ) ;
return - V_150 ;
}
if ( F_77 ( V_145 >= V_151 ) ) {
F_75 ( V_2 -> V_33 -> V_34 ,
L_4 ,
V_145 , V_151 ) ;
F_74 ( V_2 -> V_33 ) ;
return - V_152 ;
}
if ( ! V_146 && V_145 >= V_153 ) {
if ( F_78 () )
F_50 ( V_2 -> V_33 -> V_34 ,
L_5 ,
V_145 , V_153 ) ;
V_146 = - V_152 ;
}
if ( V_146 )
V_137 = & V_149 ;
F_33 ( & V_2 -> V_129 , V_17 + V_145 , V_137 ) ;
if ( ! V_146 && V_137 -> V_48 > V_143 -> V_48 ) {
if ( F_78 () )
F_50 ( V_2 -> V_33 -> V_34 ,
L_6 ,
V_137 -> V_48 , V_143 -> V_48 ) ;
V_146 = - V_154 ;
}
V_143 -> V_48 -= V_137 -> V_48 ;
V_145 ++ ;
if ( F_77 ( ( V_137 -> V_53 + V_137 -> V_48 ) > V_23 ) ) {
F_75 ( V_2 -> V_33 -> V_34 , L_7 ,
V_137 -> V_53 , V_137 -> V_48 ) ;
F_74 ( V_2 -> V_33 ) ;
return - V_155 ;
}
V_147 = V_137 -> V_29 & V_148 ;
if ( ! V_146 )
V_137 ++ ;
} while ( V_147 );
if ( V_146 ) {
F_71 ( V_2 , V_143 , V_138 , V_17 + V_145 ) ;
return V_146 ;
}
return V_145 ;
}
static inline void F_79 ( struct V_1 * V_2 ,
T_1 V_7 ,
struct V_136 * V_137 ,
unsigned int V_138 ,
struct V_156 * V_157 )
{
V_2 -> V_158 [ V_157 - V_2 -> V_159 ] = V_2 -> V_4 [ V_7 ] ;
F_80 ( V_157 , F_3 ( V_2 , V_7 ) ,
V_160 | V_161 ,
V_137 -> V_51 , V_2 -> V_33 -> V_66 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_43 , V_137 ,
sizeof( * V_137 ) ) ;
V_2 -> V_9 [ V_7 ] . V_138 = V_138 ;
}
static inline struct V_18 * F_81 ( unsigned int V_48 )
{
struct V_18 * V_19 =
F_82 ( V_48 + V_162 + V_163 ,
V_164 | V_165 ) ;
if ( F_77 ( V_19 == NULL ) )
return NULL ;
F_83 ( V_19 , V_162 + V_163 ) ;
F_38 ( V_19 ) -> V_166 = NULL ;
return V_19 ;
}
static struct V_156 * F_84 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_136 * V_137 ,
struct V_156 * V_167 ,
unsigned int V_168 ,
struct V_18 * V_169 )
{
struct V_170 * V_171 = F_38 ( V_19 ) ;
T_2 * V_88 = V_171 -> V_88 ;
T_1 V_7 = F_85 ( V_19 ) -> V_7 ;
int V_172 ;
T_3 V_173 ;
unsigned int V_174 ;
V_174 = V_171 -> V_85 ;
V_172 = ( F_7 ( & V_171 -> V_88 [ 0 ] ) == V_7 ) ;
for ( V_171 -> V_85 = V_172 ; V_171 -> V_85 < V_174 ;
V_171 -> V_85 ++ , V_137 ++ , V_167 ++ ) {
V_173 = F_9 ( V_2 -> V_175 ++ ) ;
V_7 = V_2 -> V_176 [ V_173 ] ;
F_79 ( V_2 , V_7 , V_137 , 0 , V_167 ) ;
F_8 ( & V_88 [ V_171 -> V_85 ] , V_7 ) ;
}
if ( V_168 ) {
V_171 = F_38 ( V_169 ) ;
V_88 = V_171 -> V_88 ;
for ( V_171 -> V_85 = 0 ; V_171 -> V_85 < V_168 ;
V_171 -> V_85 ++ , V_137 ++ , V_167 ++ ) {
V_173 = F_9 ( V_2 -> V_175 ++ ) ;
V_7 = V_2 -> V_176 [ V_173 ] ;
F_79 ( V_2 , V_7 , V_137 , 0 ,
V_167 ) ;
F_8 ( & V_88 [ V_171 -> V_85 ] ,
V_7 ) ;
}
F_38 ( V_19 ) -> V_177 = V_169 ;
}
return V_167 ;
}
static inline void F_86 ( struct V_1 * V_2 ,
T_1 V_7 ,
T_6 V_178 )
{
if ( F_77 ( V_2 -> V_179 [ V_7 ] !=
V_180 ) ) {
F_75 ( V_2 -> V_33 -> V_34 ,
L_8 ,
V_7 ) ;
F_87 () ;
}
V_2 -> V_179 [ V_7 ] = V_178 ;
}
static inline void F_88 ( struct V_1 * V_2 ,
T_1 V_7 )
{
if ( F_77 ( V_2 -> V_179 [ V_7 ] ==
V_180 ) ) {
F_75 ( V_2 -> V_33 -> V_34 ,
L_9 ,
V_7 ) ;
F_87 () ;
}
V_2 -> V_179 [ V_7 ] = V_180 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_156 * * V_181 ,
struct V_56 * * V_182 )
{
struct V_156 * V_183 = * V_181 ;
T_1 V_7 = F_85 ( V_19 ) -> V_7 ;
struct V_170 * V_171 = F_38 ( V_19 ) ;
struct V_170 * V_184 = NULL ;
int V_85 = V_171 -> V_85 ;
const bool V_185 = V_85 &&
F_7 ( & V_171 -> V_88 [ 0 ] ) == V_7 ;
int V_14 , V_186 ;
V_186 = ( * V_182 ) -> V_91 ;
if ( F_77 ( V_186 ) ) {
if ( F_78 () )
F_50 ( V_2 -> V_33 -> V_34 ,
L_10 ,
( * V_182 ) -> V_91 ,
V_7 ,
( * V_182 ) -> V_65 . V_67 . V_68 ) ;
if ( ! V_185 )
F_90 ( V_2 , V_7 ,
V_95 ) ;
}
( * V_182 ) ++ ;
V_187:
for ( V_14 = 0 ; V_14 < V_85 ; V_14 ++ , V_183 ++ ) {
int V_188 , V_189 ;
V_7 = F_7 ( & V_171 -> V_88 [ V_14 ] ) ;
V_189 = V_183 -> V_91 ;
if ( F_91 ( ! V_189 ) ) {
F_86 ( V_2 ,
V_7 ,
V_183 -> V_178 ) ;
if ( F_77 ( V_186 ) ) {
F_92 ( V_2 , V_7 ) ;
if ( V_14 == 0 && V_185 )
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
V_183 -> V_91 ,
V_7 ,
V_183 -> V_68 ) ;
F_90 ( V_2 , V_7 , V_95 ) ;
if ( V_186 )
continue;
if ( ! V_185 )
F_90 ( V_2 ,
F_85 ( V_19 ) -> V_7 ,
V_92 ) ;
for ( V_188 = 0 ; V_188 < V_14 ; V_188 ++ ) {
V_7 = F_7 ( & V_171 -> V_88 [ V_188 ] ) ;
F_92 ( V_2 , V_7 ) ;
F_90 ( V_2 , V_7 ,
V_92 ) ;
}
if ( V_184 ) {
for ( V_188 = 0 ; V_188 < V_184 -> V_85 ; V_188 ++ ) {
V_7 = F_7 ( & V_184 -> V_88 [ V_188 ] ) ;
F_92 ( V_2 , V_7 ) ;
F_90 ( V_2 , V_7 ,
V_92 ) ;
}
}
V_186 = V_189 ;
}
if ( F_93 ( V_19 ) && ! V_184 ) {
V_184 = F_38 ( V_19 ) ;
V_171 = F_38 ( F_38 ( V_19 ) -> V_177 ) ;
V_85 = V_171 -> V_85 ;
goto V_187;
}
* V_181 = V_183 ;
return V_186 ;
}
static void F_94 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_170 * V_171 = F_38 ( V_19 ) ;
int V_85 = V_171 -> V_85 ;
int V_14 ;
T_1 V_190 = V_191 ;
for ( V_14 = 0 ; V_14 < V_85 ; V_14 ++ ) {
T_2 * V_12 = V_171 -> V_88 + V_14 ;
struct V_136 * V_137 ;
struct V_60 * V_60 ;
T_1 V_7 ;
V_7 = F_7 ( V_12 ) ;
if ( V_190 == V_191 )
F_38 ( V_19 ) -> V_166 =
& F_95 ( V_2 , V_7 ) ;
else
F_95 ( V_2 , V_190 ) . V_192 =
& F_95 ( V_2 , V_7 ) ;
F_95 ( V_2 , V_7 ) . V_192 = NULL ;
V_190 = V_7 ;
V_137 = & V_2 -> V_9 [ V_7 ] . V_43 ;
V_60 = F_46 ( F_3 ( V_2 , V_7 ) ) ;
F_96 ( V_19 , V_14 , V_60 , V_137 -> V_53 , V_137 -> V_48 ) ;
V_19 -> V_22 += V_137 -> V_48 ;
V_19 -> V_193 += V_137 -> V_48 ;
V_19 -> V_194 += V_137 -> V_48 ;
F_97 ( V_2 -> V_4 [ V_7 ] ) ;
}
}
static int F_98 ( struct V_1 * V_2 ,
struct V_121 * V_195 ,
unsigned int * V_138 ,
int V_144 )
{
struct V_121 V_196 ;
T_4 V_17 = V_2 -> V_129 . V_27 ;
do {
if ( F_77 ( V_144 -- <= 0 ) ) {
F_75 ( V_2 -> V_33 -> V_34 , L_12 ) ;
F_74 ( V_2 -> V_33 ) ;
return - V_197 ;
}
F_33 ( & V_2 -> V_129 , V_17 , & V_196 ) ;
V_2 -> V_129 . V_27 = ++ V_17 ;
( * V_138 ) ++ ;
if ( F_77 ( ! V_196 . type ||
V_196 . type >= V_198 ) ) {
F_75 ( V_2 -> V_33 -> V_34 ,
L_13 , V_196 . type ) ;
F_74 ( V_2 -> V_33 ) ;
return - V_155 ;
}
memcpy ( & V_195 [ V_196 . type - 1 ] , & V_196 , sizeof( V_196 ) ) ;
} while ( V_196 . V_29 & V_199 );
return V_144 ;
}
static int F_99 ( struct V_84 * V_33 ,
struct V_18 * V_19 ,
struct V_121 * V_122 )
{
if ( ! V_122 -> V_67 . V_122 . V_48 ) {
F_75 ( V_33 -> V_34 , L_14 ) ;
F_74 ( V_33 ) ;
return - V_155 ;
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
return - V_155 ;
}
F_38 ( V_19 ) -> V_47 = V_122 -> V_67 . V_122 . V_48 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
bool V_200 = false ;
if ( V_19 -> V_116 != V_117 && F_13 ( V_19 ) ) {
V_2 -> V_113 . V_201 ++ ;
V_19 -> V_116 = V_117 ;
V_200 = true ;
}
if ( V_19 -> V_116 != V_117 )
return 0 ;
return F_101 ( V_19 , V_200 ) ;
}
static bool F_102 ( struct V_1 * V_2 , unsigned V_48 )
{
T_7 V_202 = F_103 () ;
T_7 V_203 = V_2 -> V_204 +
F_104 ( V_2 -> V_205 / 1000 ) ;
if ( F_105 ( & V_2 -> V_206 ) )
return true ;
if ( F_106 ( V_202 , V_203 ) ) {
V_2 -> V_204 = V_202 ;
F_67 ( V_2 ) ;
}
if ( V_48 > V_2 -> V_134 ) {
V_2 -> V_206 . V_75 =
( unsigned long ) V_2 ;
F_107 ( & V_2 -> V_206 ,
V_203 ) ;
V_2 -> V_204 = V_203 ;
return true ;
}
return false ;
}
static int F_108 ( struct V_84 * V_33 , const T_8 * V_207 )
{
struct V_208 * V_209 ;
if ( V_33 -> V_210 == V_211 ) {
if ( F_78 () )
F_75 ( V_33 -> V_34 ,
L_16 ) ;
return - V_212 ;
}
V_209 = F_109 ( sizeof( * V_209 ) , V_164 ) ;
if ( ! V_209 )
return - V_213 ;
F_110 ( V_209 -> V_207 , V_207 ) ;
F_111 ( & V_209 -> V_214 , & V_33 -> V_215 ) ;
V_33 -> V_210 ++ ;
return 0 ;
}
static void F_112 ( struct V_84 * V_33 , const T_8 * V_207 )
{
struct V_208 * V_209 ;
F_113 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_114 ( V_207 , V_209 -> V_207 ) ) {
-- V_33 -> V_210 ;
F_115 ( & V_209 -> V_214 ) ;
F_116 ( V_209 , V_216 ) ;
break;
}
}
}
bool F_117 ( struct V_84 * V_33 , const T_8 * V_207 )
{
struct V_208 * V_209 ;
F_118 () ;
F_113 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_114 ( V_207 , V_209 -> V_207 ) ) {
F_119 () ;
return true ;
}
}
F_119 () ;
return false ;
}
void F_120 ( struct V_84 * V_33 )
{
while ( ! F_121 ( & V_33 -> V_215 ) ) {
struct V_208 * V_209 ;
V_209 = F_122 ( & V_33 -> V_215 ,
struct V_208 ,
V_214 ) ;
-- V_33 -> V_210 ;
F_123 ( & V_209 -> V_214 ) ;
F_124 ( V_209 ) ;
}
}
static void F_125 ( struct V_1 * V_2 ,
int V_217 ,
unsigned * V_218 ,
unsigned * V_219 )
{
struct V_156 * V_167 = V_2 -> V_159 ;
struct V_18 * V_19 , * V_169 ;
int V_103 ;
unsigned int V_168 ;
while ( F_126 ( & V_2 -> V_220 ) < V_217 ) {
struct V_136 V_221 ;
struct V_136 V_222 [ V_153 ] ;
struct V_121 V_195 [ V_198 - 1 ] ;
unsigned int V_138 ;
T_1 V_7 ;
T_4 V_3 ;
int V_144 ;
unsigned int V_193 ;
T_3 V_173 ;
if ( V_2 -> V_129 . V_25 -> V_26 - V_2 -> V_129 . V_27 >
V_223 ) {
F_75 ( V_2 -> V_33 -> V_34 ,
L_17
L_18 ,
V_2 -> V_129 . V_25 -> V_26 , V_2 -> V_129 . V_27 ,
V_223 ) ;
F_74 ( V_2 -> V_33 ) ;
break;
}
V_144 = F_127 ( & V_2 -> V_129 ) ;
if ( ! V_144 )
break;
V_3 = V_2 -> V_129 . V_27 ;
F_128 () ;
F_33 ( & V_2 -> V_129 , V_3 , & V_221 ) ;
if ( V_221 . V_48 > V_2 -> V_134 &&
F_102 ( V_2 , V_221 . V_48 ) )
break;
V_2 -> V_134 -= V_221 . V_48 ;
V_144 -- ;
V_2 -> V_129 . V_27 = ++ V_3 ;
memset ( V_195 , 0 , sizeof( V_195 ) ) ;
V_138 = 0 ;
if ( V_221 . V_29 & V_224 ) {
V_144 = F_98 ( V_2 , V_195 ,
& V_138 ,
V_144 ) ;
V_3 = V_2 -> V_129 . V_27 ;
if ( F_77 ( V_144 < 0 ) )
break;
}
if ( V_195 [ V_225 - 1 ] . type ) {
struct V_121 * V_196 ;
V_196 = & V_195 [ V_225 - 1 ] ;
V_103 = F_108 ( V_2 -> V_33 , V_196 -> V_67 . V_209 . V_207 ) ;
F_72 ( V_2 , & V_221 , V_138 ,
( V_103 == 0 ) ?
V_92 :
V_95 ) ;
F_73 ( V_2 ) ;
continue;
}
if ( V_195 [ V_226 - 1 ] . type ) {
struct V_121 * V_196 ;
V_196 = & V_195 [ V_226 - 1 ] ;
F_112 ( V_2 -> V_33 , V_196 -> V_67 . V_209 . V_207 ) ;
F_72 ( V_2 , & V_221 , V_138 ,
V_92 ) ;
F_73 ( V_2 ) ;
continue;
}
V_103 = F_76 ( V_2 , & V_221 , V_138 ,
V_222 , V_144 ) ;
if ( F_77 ( V_103 < 0 ) )
break;
V_3 += V_103 ;
if ( F_77 ( V_221 . V_48 < V_227 ) ) {
F_50 ( V_2 -> V_33 -> V_34 ,
L_19 , V_221 . V_48 ) ;
F_71 ( V_2 , & V_221 , V_138 , V_3 ) ;
break;
}
if ( F_77 ( ( V_221 . V_53 + V_221 . V_48 ) > V_23 ) ) {
F_75 ( V_2 -> V_33 -> V_34 ,
L_20 ,
V_221 . V_53 , V_221 . V_48 ,
( unsigned long ) ( V_221 . V_53 & ~ V_228 ) + V_221 . V_48 ) ;
F_74 ( V_2 -> V_33 ) ;
break;
}
V_173 = F_9 ( V_2 -> V_175 ) ;
V_7 = V_2 -> V_176 [ V_173 ] ;
V_193 = ( V_221 . V_48 > V_229 &&
V_103 < V_153 ) ?
V_229 : V_221 . V_48 ;
V_19 = F_81 ( V_193 ) ;
if ( F_77 ( V_19 == NULL ) ) {
F_50 ( V_2 -> V_33 -> V_34 ,
L_21 ) ;
F_71 ( V_2 , & V_221 , V_138 , V_3 ) ;
break;
}
F_38 ( V_19 ) -> V_85 = V_103 ;
if ( V_193 < V_221 . V_48 )
F_38 ( V_19 ) -> V_85 ++ ;
V_168 = 0 ;
V_169 = NULL ;
if ( F_38 ( V_19 ) -> V_85 > V_230 ) {
V_168 = F_38 ( V_19 ) -> V_85 - V_230 ;
F_35 ( V_168 > V_230 ) ;
F_38 ( V_19 ) -> V_85 = V_230 ;
V_169 = F_81 ( 0 ) ;
if ( F_77 ( V_169 == NULL ) ) {
F_28 ( V_19 ) ;
F_71 ( V_2 , & V_221 , V_138 , V_3 ) ;
if ( F_78 () )
F_75 ( V_2 -> V_33 -> V_34 ,
L_22 ) ;
break;
}
}
if ( V_195 [ V_126 - 1 ] . type ) {
struct V_121 * V_122 ;
V_122 = & V_195 [ V_126 - 1 ] ;
if ( F_99 ( V_2 -> V_33 , V_19 , V_122 ) ) {
F_28 ( V_19 ) ;
F_28 ( V_169 ) ;
break;
}
}
F_85 ( V_19 ) -> V_7 = V_7 ;
F_129 ( V_19 , V_193 ) ;
V_2 -> V_231 [ * V_218 ] . V_65 . V_67 . V_68 = V_221 . V_51 ;
V_2 -> V_231 [ * V_218 ] . V_65 . V_66 = V_2 -> V_33 -> V_66 ;
V_2 -> V_231 [ * V_218 ] . V_65 . V_53 = V_221 . V_53 ;
V_2 -> V_231 [ * V_218 ] . V_72 . V_67 . V_71 =
F_130 ( V_19 -> V_75 ) ;
V_2 -> V_231 [ * V_218 ] . V_72 . V_66 = V_70 ;
V_2 -> V_231 [ * V_218 ] . V_72 . V_53 =
F_45 ( V_19 -> V_75 ) & ~ V_228 ;
V_2 -> V_231 [ * V_218 ] . V_22 = V_193 ;
V_2 -> V_231 [ * V_218 ] . V_29 = V_69 ;
( * V_218 ) ++ ;
if ( V_193 < V_221 . V_48 ) {
F_8 ( & F_38 ( V_19 ) -> V_88 [ 0 ] ,
V_7 ) ;
F_79 ( V_2 , V_7 , & V_221 ,
V_138 , V_167 ) ;
V_167 ++ ;
} else {
F_8 ( & F_38 ( V_19 ) -> V_88 [ 0 ] ,
V_191 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_43 ,
& V_221 , sizeof( V_221 ) ) ;
V_2 -> V_9 [ V_7 ] . V_138 =
V_138 ;
}
V_2 -> V_175 ++ ;
V_167 = F_84 ( V_2 , V_19 , V_222 , V_167 ,
V_168 , V_169 ) ;
F_17 ( & V_2 -> V_220 , V_19 ) ;
V_2 -> V_129 . V_27 = V_3 ;
if ( ( ( V_167 - V_2 -> V_159 ) >= F_58 ( V_2 -> V_159 ) ) ||
( * V_218 >= F_58 ( V_2 -> V_231 ) ) )
break;
}
( * V_219 ) = V_167 - V_2 -> V_159 ;
return;
}
static int F_131 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
unsigned int V_53 = F_132 ( V_19 ) ;
T_2 V_88 [ V_230 ] ;
int V_14 , V_232 ;
struct V_5 * V_233 ;
struct V_18 * V_169 = F_38 ( V_19 ) -> V_177 ;
V_2 -> V_113 . V_234 += 2 ;
V_2 -> V_113 . V_235 ++ ;
F_94 ( V_2 , V_169 ) ;
V_19 -> V_194 -= V_19 -> V_193 ;
V_19 -> V_22 += V_169 -> V_22 ;
V_19 -> V_193 += V_169 -> V_22 ;
for ( V_14 = 0 ; V_53 < V_19 -> V_22 ; V_14 ++ ) {
struct V_60 * V_60 ;
unsigned int V_22 ;
F_35 ( V_14 >= V_230 ) ;
V_60 = F_133 ( V_164 ) ;
if ( ! V_60 ) {
int V_188 ;
V_19 -> V_194 += V_19 -> V_193 ;
for ( V_188 = 0 ; V_188 < V_14 ; V_188 ++ )
F_134 ( V_88 [ V_188 ] . V_60 . V_236 ) ;
return - V_213 ;
}
if ( V_53 + V_81 < V_19 -> V_22 )
V_22 = V_81 ;
else
V_22 = V_19 -> V_22 - V_53 ;
if ( F_135 ( V_19 , V_53 , F_136 ( V_60 ) , V_22 ) )
F_87 () ;
V_53 += V_22 ;
V_88 [ V_14 ] . V_60 . V_236 = V_60 ;
V_88 [ V_14 ] . V_13 = 0 ;
F_137 ( & V_88 [ V_14 ] , V_22 ) ;
}
F_138 ( V_19 ) ;
F_139 ( V_2 , V_169 ) ;
F_28 ( V_169 ) ;
for ( V_232 = 0 ; V_232 < F_38 ( V_19 ) -> V_85 ; V_232 ++ )
F_140 ( V_19 , V_232 ) ;
V_233 = F_38 ( V_19 ) -> V_166 ;
F_141 ( & V_2 -> V_237 ) ;
V_233 -> V_238 ( V_233 , true ) ;
F_38 ( V_19 ) -> V_166 = NULL ;
memcpy ( F_38 ( V_19 ) -> V_88 , V_88 , V_14 * sizeof( T_2 ) ) ;
F_38 ( V_19 ) -> V_85 = V_14 ;
V_19 -> V_194 += V_14 * V_81 ;
return 0 ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_156 * V_183 = V_2 -> V_159 ;
struct V_56 * V_239 = V_2 -> V_231 ;
struct V_18 * V_19 ;
int V_240 = 0 ;
while ( ( V_19 = F_23 ( & V_2 -> V_220 ) ) != NULL ) {
struct V_136 * V_137 ;
T_1 V_7 ;
unsigned V_193 ;
V_7 = F_85 ( V_19 ) -> V_7 ;
V_137 = & V_2 -> V_9 [ V_7 ] . V_43 ;
if ( F_77 ( F_89 ( V_2 , V_19 , & V_183 , & V_239 ) ) ) {
F_38 ( V_19 ) -> V_85 = 0 ;
if ( F_93 ( V_19 ) ) {
struct V_18 * V_169 =
F_38 ( V_19 ) -> V_177 ;
F_38 ( V_169 ) -> V_85 = 0 ;
}
F_28 ( V_19 ) ;
continue;
}
V_193 = V_19 -> V_22 ;
F_95 ( V_2 , V_7 ) . V_192 = NULL ;
if ( V_193 < V_137 -> V_48 ) {
V_137 -> V_53 += V_193 ;
V_137 -> V_48 -= V_193 ;
} else {
F_90 ( V_2 , V_7 ,
V_92 ) ;
}
if ( V_137 -> V_29 & V_241 )
V_19 -> V_116 = V_117 ;
else if ( V_137 -> V_29 & V_242 )
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
V_19 -> V_243 = F_143 ( V_19 , V_19 -> V_34 ) ;
F_144 ( V_19 ) ;
if ( F_100 ( V_2 , V_19 ) ) {
F_50 ( V_2 -> V_33 -> V_34 ,
L_24 ) ;
if ( F_38 ( V_19 ) -> V_166 )
F_139 ( V_2 , V_19 ) ;
F_28 ( V_19 ) ;
continue;
}
F_145 ( V_19 , 0 ) ;
if ( F_13 ( V_19 ) ) {
int V_244 = F_38 ( V_19 ) -> V_47 ;
int V_245 = F_146 ( V_19 ) -
F_147 ( V_19 ) +
F_148 ( V_19 ) ;
F_38 ( V_19 ) -> V_246 =
F_12 ( V_19 -> V_22 - V_245 , V_244 ) ;
}
V_2 -> V_113 . V_247 += V_19 -> V_22 ;
V_2 -> V_113 . V_248 ++ ;
V_240 ++ ;
if ( F_38 ( V_19 ) -> V_166 ) {
F_139 ( V_2 , V_19 ) ;
V_2 -> V_113 . V_234 ++ ;
}
F_149 ( V_19 ) ;
}
return V_240 ;
}
void F_150 ( struct V_5 * V_6 , bool V_249 )
{
unsigned long V_29 ;
T_3 V_173 ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
F_16 ( & V_2 -> V_250 , V_29 ) ;
do {
T_1 V_7 = V_6 -> V_8 ;
V_6 = (struct V_5 * ) V_6 -> V_192 ;
F_35 ( V_2 -> V_251 - V_2 -> V_252 >=
V_15 ) ;
V_173 = F_9 ( V_2 -> V_251 ) ;
V_2 -> V_253 [ V_173 ] = V_7 ;
F_151 () ;
V_2 -> V_251 ++ ;
} while ( V_6 );
F_20 ( & V_2 -> V_250 , V_29 ) ;
if ( F_91 ( V_249 ) )
V_2 -> V_113 . V_254 ++ ;
else
V_2 -> V_113 . V_255 ++ ;
F_152 ( V_2 ) ;
}
static inline void F_153 ( struct V_1 * V_2 )
{
struct V_256 * V_167 ;
T_3 V_257 , V_258 ;
T_1 V_7 , V_259 [ V_15 ] ;
unsigned int V_14 = 0 ;
V_257 = V_2 -> V_252 ;
V_167 = V_2 -> V_260 ;
do {
V_258 = V_2 -> V_251 ;
F_154 () ;
while ( V_257 != V_258 ) {
F_35 ( V_167 - V_2 -> V_260 >= V_15 ) ;
V_7 =
V_2 -> V_253 [ F_9 ( V_257 ++ ) ] ;
V_259 [ V_167 - V_2 -> V_260 ] =
V_7 ;
V_2 -> V_261 [ V_167 - V_2 -> V_260 ] =
V_2 -> V_4 [ V_7 ] ;
F_155 ( V_167 ,
F_3 ( V_2 , V_7 ) ,
V_160 ,
V_2 -> V_179 [ V_7 ] ) ;
F_88 ( V_2 , V_7 ) ;
++ V_167 ;
}
} while ( V_258 != V_2 -> V_251 );
V_2 -> V_252 = V_257 ;
if ( V_167 - V_2 -> V_260 > 0 ) {
int V_103 ;
V_103 = F_156 ( V_2 -> V_260 ,
NULL ,
V_2 -> V_261 ,
V_167 - V_2 -> V_260 ) ;
if ( V_103 ) {
F_75 ( V_2 -> V_33 -> V_34 , L_25 ,
V_167 - V_2 -> V_260 , V_103 ) ;
for ( V_14 = 0 ; V_14 < V_167 - V_2 -> V_260 ; ++ V_14 ) {
if ( V_167 [ V_14 ] . V_91 != V_94 )
F_75 ( V_2 -> V_33 -> V_34 ,
L_26 ,
V_167 [ V_14 ] . V_262 ,
V_167 [ V_14 ] . V_178 ,
V_167 [ V_14 ] . V_91 ) ;
}
F_87 () ;
}
}
for ( V_14 = 0 ; V_14 < V_167 - V_2 -> V_260 ; ++ V_14 )
F_90 ( V_2 , V_259 [ V_14 ] ,
V_92 ) ;
}
int F_157 ( struct V_1 * V_2 , int V_217 )
{
unsigned V_263 , V_264 = 0 ;
int V_240 , V_103 ;
if ( F_77 ( ! F_158 ( V_2 ) ) )
return 0 ;
F_125 ( V_2 , V_217 , & V_264 , & V_263 ) ;
if ( V_264 == 0 )
return 0 ;
F_59 ( V_2 -> V_231 , V_264 ) ;
if ( V_263 != 0 ) {
V_103 = F_159 ( V_2 -> V_159 ,
NULL ,
V_2 -> V_158 ,
V_263 ) ;
F_35 ( V_103 ) ;
}
V_240 = F_142 ( V_2 ) ;
return V_240 ;
}
static void F_90 ( struct V_1 * V_2 , T_1 V_7 ,
T_8 V_91 )
{
struct V_9 * V_9 ;
T_3 V_173 ;
unsigned long V_29 ;
V_9 = & V_2 -> V_9 [ V_7 ] ;
F_16 ( & V_2 -> V_140 , V_29 ) ;
F_72 ( V_2 , & V_9 -> V_43 ,
V_9 -> V_138 , V_91 ) ;
V_173 = F_9 ( V_2 -> V_265 ++ ) ;
V_2 -> V_176 [ V_173 ] = V_7 ;
F_73 ( V_2 ) ;
F_20 ( & V_2 -> V_140 , V_29 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_136 * V_137 ,
unsigned int V_138 ,
T_5 V_266 )
{
T_4 V_14 = V_2 -> V_129 . V_111 ;
struct V_267 * V_99 ;
V_99 = F_60 ( & V_2 -> V_129 , V_14 ) ;
V_99 -> V_35 = V_137 -> V_35 ;
V_99 -> V_91 = V_266 ;
while ( V_138 -- != 0 )
F_60 ( & V_2 -> V_129 , ++ V_14 ) -> V_91 = V_268 ;
V_2 -> V_129 . V_111 = ++ V_14 ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_102 ;
F_61 ( & V_2 -> V_129 , V_102 ) ;
if ( V_102 )
F_63 ( V_2 -> V_269 ) ;
}
static struct V_98 * F_52 ( struct V_1 * V_2 ,
T_1 V_35 ,
T_5 V_266 ,
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
V_99 -> V_91 = ( V_270 ) V_48 ;
if ( V_266 < 0 )
V_99 -> V_91 = ( V_270 ) V_266 ;
V_2 -> V_24 . V_111 = ++ V_14 ;
return V_99 ;
}
void F_92 ( struct V_1 * V_2 , T_1 V_7 )
{
int V_103 ;
struct V_256 V_271 ;
F_155 ( & V_271 ,
F_3 ( V_2 , V_7 ) ,
V_160 ,
V_2 -> V_179 [ V_7 ] ) ;
F_88 ( V_2 , V_7 ) ;
V_103 = F_156 ( & V_271 , NULL ,
& V_2 -> V_4 [ V_7 ] , 1 ) ;
if ( V_103 ) {
F_75 ( V_2 -> V_33 -> V_34 ,
L_27 ,
V_103 ,
V_7 ,
V_271 . V_262 ,
V_271 . V_178 ,
V_271 . V_91 ) ;
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
return V_2 -> V_252 != V_2 -> V_251 ;
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
T_9 V_272 ,
T_9 V_273 )
{
void * V_207 ;
struct V_274 * V_275 ;
struct V_276 * V_277 ;
int V_186 = - V_213 ;
V_186 = F_165 ( F_163 ( V_2 -> V_33 ) ,
& V_272 , 1 , & V_207 ) ;
if ( V_186 )
goto V_186;
V_275 = (struct V_274 * ) V_207 ;
F_166 ( & V_2 -> V_129 , V_275 , V_23 ) ;
V_186 = F_165 ( F_163 ( V_2 -> V_33 ) ,
& V_273 , 1 , & V_207 ) ;
if ( V_186 )
goto V_186;
V_277 = (struct V_276 * ) V_207 ;
F_166 ( & V_2 -> V_24 , V_277 , V_23 ) ;
return 0 ;
V_186:
F_161 ( V_2 ) ;
return V_186 ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_84 * V_33 = V_2 -> V_33 ;
V_2 -> V_278 = true ;
F_168 ( & V_33 -> V_30 ) ;
if ( V_33 -> V_279 ++ == 0 ) {
F_169 ( V_33 -> V_34 , L_28 ) ;
F_170 ( V_33 -> V_34 ) ;
}
F_171 ( & V_33 -> V_30 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_84 * V_33 = V_2 -> V_33 ;
V_2 -> V_106 = V_36 ;
V_2 -> V_278 = false ;
F_168 ( & V_33 -> V_30 ) ;
if ( -- V_33 -> V_279 == 0 ) {
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
return ! V_2 -> V_278 && V_16 - V_17 < 1
&& F_175 ( V_36 ,
V_2 -> V_106 + V_2 -> V_33 -> V_280 ) ;
}
static bool F_176 ( struct V_1 * V_2 )
{
T_4 V_16 , V_17 ;
V_16 = V_2 -> V_24 . V_25 -> V_26 ;
V_17 = V_2 -> V_24 . V_27 ;
return V_2 -> V_278 && V_16 - V_17 >= 1 ;
}
static bool F_177 ( struct V_1 * V_2 )
{
return F_10 ( V_2 )
|| ( V_2 -> V_33 -> V_280 &&
( F_174 ( V_2 )
|| F_176 ( V_2 ) ) )
|| F_178 ()
|| V_2 -> V_33 -> V_141 ;
}
static long F_179 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
long V_281 ;
V_19 = F_11 ( & V_2 -> V_21 ) ;
if ( ! V_19 )
return V_282 ;
V_281 = F_31 ( V_19 ) -> V_37 - V_36 ;
return V_281 < 0 ? 0 : V_281 ;
}
static void F_180 ( struct V_1 * V_2 )
{
F_181 ( V_283 ) ;
if ( F_177 ( V_2 ) )
return;
for (; ; ) {
long V_103 ;
F_182 ( & V_2 -> V_97 , & V_283 , V_284 ) ;
if ( F_177 ( V_2 ) )
break;
V_103 = F_183 ( F_179 ( V_2 ) ) ;
if ( ! V_103 )
break;
}
F_184 ( & V_2 -> V_97 , & V_283 ) ;
}
int F_185 ( void * V_75 )
{
struct V_1 * V_2 = V_75 ;
struct V_84 * V_33 = V_2 -> V_33 ;
if ( ! V_33 -> V_280 )
F_172 ( V_2 ) ;
for (; ; ) {
F_180 ( V_2 ) ;
if ( F_178 () )
break;
if ( F_77 ( V_33 -> V_141 && V_2 -> V_35 == 0 ) ) {
F_186 ( V_33 ) ;
break;
}
if ( ! F_187 ( & V_2 -> V_21 ) )
F_55 ( V_2 ) ;
if ( V_33 -> V_280 ) {
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
! F_190 ( & V_2 -> V_237 ) ;
}
int F_191 ( void * V_75 )
{
struct V_1 * V_2 = V_75 ;
for (; ; ) {
F_192 ( V_2 -> V_285 ,
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
int V_286 = 0 ;
if ( ! F_194 () )
return - V_287 ;
if ( V_288 == 0 )
V_288 = F_195 () ;
if ( V_151 < V_153 ) {
F_196 ( L_30 ,
V_151 , V_153 ) ;
V_151 = V_153 ;
}
V_286 = F_197 () ;
if ( V_286 )
goto V_289;
#ifdef F_198
V_290 = F_199 ( L_31 , NULL ) ;
if ( F_200 ( V_290 ) )
F_201 ( L_32 ,
F_202 ( V_290 ) ) ;
#endif
return 0 ;
V_289:
return V_286 ;
}
static void T_11 F_203 ( void )
{
#ifdef F_198
if ( ! F_200 ( V_290 ) )
F_204 ( V_290 ) ;
#endif
F_205 () ;
}
