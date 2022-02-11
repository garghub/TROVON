int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 , * * V_4 ;
int V_5 = - V_6 ;
F_2 ( & V_7 ) ;
for ( V_4 = & V_8 ; ( V_3 = * V_4 ) != NULL ; V_4 = & V_3 -> V_9 )
if ( ! strcmp ( V_2 -> V_10 , V_3 -> V_10 ) )
goto V_11;
if ( V_2 -> V_12 == NULL )
V_2 -> V_12 = V_13 . V_12 ;
if ( V_2 -> V_14 == NULL ) {
if ( V_2 -> V_15 == NULL )
V_2 -> V_14 = V_13 . V_14 ;
else
goto V_16;
}
if ( V_2 -> V_15 == NULL )
V_2 -> V_15 = V_13 . V_15 ;
if ( V_2 -> V_17 ) {
const struct V_18 * V_19 = V_2 -> V_17 ;
if ( ! ( V_19 -> V_20 && V_19 -> V_21 && V_19 -> V_22 && V_19 -> V_23 ) )
goto V_16;
if ( V_19 -> V_24 && ! ( V_19 -> V_25 && V_19 -> V_26 ) )
goto V_16;
}
V_2 -> V_9 = NULL ;
* V_4 = V_2 ;
V_5 = 0 ;
V_11:
F_3 ( & V_7 ) ;
return V_5 ;
V_16:
V_5 = - V_27 ;
goto V_11;
}
int F_4 ( struct V_1 * V_2 )
{
struct V_1 * V_3 , * * V_4 ;
int V_28 = - V_29 ;
F_2 ( & V_7 ) ;
for ( V_4 = & V_8 ; ( V_3 = * V_4 ) != NULL ; V_4 = & V_3 -> V_9 )
if ( V_3 == V_2 )
break;
if ( V_3 ) {
* V_4 = V_3 -> V_9 ;
V_3 -> V_9 = NULL ;
V_28 = 0 ;
}
F_3 ( & V_7 ) ;
return V_28 ;
}
void F_5 ( char * V_30 , T_1 V_31 )
{
F_6 ( & V_7 ) ;
F_7 ( V_30 , V_32 -> V_10 , V_31 ) ;
F_8 ( & V_7 ) ;
}
static struct V_1 * F_9 ( const char * V_30 )
{
struct V_1 * V_3 = NULL ;
for ( V_3 = V_8 ; V_3 ; V_3 = V_3 -> V_9 ) {
if ( ! strcmp ( V_30 , V_3 -> V_10 ) ) {
if ( ! F_10 ( V_3 -> V_33 ) )
V_3 = NULL ;
break;
}
}
return V_3 ;
}
int F_11 ( const char * V_30 )
{
const struct V_1 * V_34 ;
if ( ! F_12 ( V_35 ) )
return - V_36 ;
F_2 ( & V_7 ) ;
V_34 = F_9 ( V_30 ) ;
if ( ! V_34 ) {
F_3 ( & V_7 ) ;
F_13 ( L_1 , V_30 ) ;
F_2 ( & V_7 ) ;
V_34 = F_9 ( V_30 ) ;
}
if ( V_34 ) {
F_14 ( V_32 -> V_33 ) ;
V_32 = V_34 ;
}
F_3 ( & V_7 ) ;
return V_34 ? 0 : - V_29 ;
}
static struct V_37 * F_15 ( struct V_37 * V_38 , T_2 V_39 )
{
struct V_37 * V_3 ;
if ( ! ( V_38 -> V_40 & V_41 ) &&
V_38 -> V_39 == V_39 )
return V_38 ;
F_16 (q, &root->list, list) {
if ( V_3 -> V_39 == V_39 )
return V_3 ;
}
return NULL ;
}
void F_17 ( struct V_37 * V_3 )
{
if ( ( V_3 -> V_42 != V_43 ) && ! ( V_3 -> V_40 & V_44 ) ) {
struct V_37 * V_38 = F_18 ( V_3 ) -> V_45 ;
F_19 ( V_38 == & V_46 ) ;
F_20 ( & V_3 -> V_47 , & V_38 -> V_47 ) ;
}
}
void F_21 ( struct V_37 * V_3 )
{
if ( ( V_3 -> V_42 != V_43 ) && ! ( V_3 -> V_40 & V_44 ) )
F_22 ( & V_3 -> V_47 ) ;
}
struct V_37 * F_23 ( struct V_48 * V_49 , T_2 V_39 )
{
struct V_37 * V_3 ;
V_3 = F_15 ( V_49 -> V_45 , V_39 ) ;
if ( V_3 )
goto V_11;
if ( F_24 ( V_49 ) )
V_3 = F_15 (
F_24 ( V_49 ) -> V_50 ,
V_39 ) ;
V_11:
return V_3 ;
}
static struct V_37 * F_25 ( struct V_37 * V_51 , T_2 V_52 )
{
unsigned long V_53 ;
struct V_37 * V_23 ;
const struct V_18 * V_19 = V_51 -> V_34 -> V_17 ;
if ( V_19 == NULL )
return NULL ;
V_53 = V_19 -> V_20 ( V_51 , V_52 ) ;
if ( V_53 == 0 )
return NULL ;
V_23 = V_19 -> V_23 ( V_51 , V_53 ) ;
V_19 -> V_21 ( V_51 , V_53 ) ;
return V_23 ;
}
static struct V_1 * F_26 ( struct V_54 * V_55 )
{
struct V_1 * V_3 = NULL ;
if ( V_55 ) {
F_6 ( & V_7 ) ;
for ( V_3 = V_8 ; V_3 ; V_3 = V_3 -> V_9 ) {
if ( F_27 ( V_55 , V_3 -> V_10 ) == 0 ) {
if ( ! F_10 ( V_3 -> V_33 ) )
V_3 = NULL ;
break;
}
}
F_8 ( & V_7 ) ;
}
return V_3 ;
}
static T_3 F_28 ( struct V_56 * V_57 , T_4 * V_58 )
{
int V_59 = F_29 ( V_57 -> V_60 , 48 ) ;
int V_61 = F_29 ( V_59 + 1 , 48 ) ;
int V_62 = V_59 >> V_57 -> V_63 ;
int V_64 = ( V_61 >> V_57 -> V_63 ) - 1 ;
if ( ( V_57 -> V_65 > ( 100000000 / 8 ) ) || ( V_58 [ 0 ] == 0 ) ) {
F_30 ( L_2 ) ;
return V_66 ;
}
if ( ( V_64 > V_62 ) && ( V_64 < 256 )
&& ( V_58 [ V_62 ] == V_58 [ V_64 ] ) ) {
F_30 ( L_3 ,
V_62 , V_64 , V_58 [ V_64 ] ) ;
return V_67 ;
}
return V_66 ;
}
struct V_68 * F_31 ( struct V_56 * V_57 , struct V_54 * V_69 )
{
struct V_68 * V_58 ;
if ( V_69 == NULL || V_57 -> V_65 == 0 || V_57 -> V_63 == 0 ||
F_32 ( V_69 ) != V_70 )
return NULL ;
for ( V_58 = V_71 ; V_58 ; V_58 = V_58 -> V_9 ) {
if ( ! memcmp ( & V_58 -> V_65 , V_57 , sizeof( struct V_56 ) ) &&
! memcmp ( & V_58 -> V_72 , F_33 ( V_69 ) , 1024 ) ) {
V_58 -> V_73 ++ ;
return V_58 ;
}
}
V_58 = F_34 ( sizeof( * V_58 ) , V_74 ) ;
if ( V_58 ) {
V_58 -> V_65 = * V_57 ;
V_58 -> V_73 = 1 ;
memcpy ( V_58 -> V_72 , F_33 ( V_69 ) , 1024 ) ;
if ( V_57 -> V_75 == V_76 )
V_57 -> V_75 = F_28 ( V_57 , V_58 -> V_72 ) ;
V_58 -> V_9 = V_71 ;
V_71 = V_58 ;
}
return V_58 ;
}
void F_35 ( struct V_68 * V_69 )
{
struct V_68 * V_58 , * * V_77 ;
if ( ! V_69 || -- V_69 -> V_73 )
return;
for ( V_77 = & V_71 ;
( V_58 = * V_77 ) != NULL ;
V_77 = & V_58 -> V_9 ) {
if ( V_58 == V_69 ) {
* V_77 = V_58 -> V_9 ;
F_36 ( V_58 ) ;
return;
}
}
}
static struct V_78 * F_37 ( struct V_54 * V_79 )
{
struct V_54 * V_80 [ V_81 + 1 ] ;
struct V_78 * V_82 ;
struct V_83 * V_84 ;
unsigned int V_85 = 0 ;
T_5 * V_69 = NULL ;
int V_28 ;
V_28 = F_38 ( V_80 , V_81 , V_79 , V_86 ) ;
if ( V_28 < 0 )
return F_39 ( V_28 ) ;
if ( ! V_80 [ V_87 ] )
return F_39 ( - V_27 ) ;
V_84 = F_33 ( V_80 [ V_87 ] ) ;
if ( V_84 -> V_85 > 0 ) {
if ( ! V_80 [ V_88 ] )
return F_39 ( - V_27 ) ;
V_69 = F_33 ( V_80 [ V_88 ] ) ;
V_85 = F_32 ( V_80 [ V_88 ] ) / sizeof( T_5 ) ;
}
if ( V_85 != V_84 -> V_85 || ( ! V_69 && V_85 > 0 ) )
return F_39 ( - V_27 ) ;
F_40 ( & V_89 ) ;
F_16 (stab, &qdisc_stab_list, list) {
if ( memcmp ( & V_82 -> V_90 , V_84 , sizeof( * V_84 ) ) )
continue;
if ( V_85 > 0 && memcmp ( V_82 -> V_72 , V_69 , V_85 * sizeof( T_5 ) ) )
continue;
V_82 -> V_73 ++ ;
F_41 ( & V_89 ) ;
return V_82 ;
}
F_41 ( & V_89 ) ;
V_82 = F_34 ( sizeof( * V_82 ) + V_85 * sizeof( T_5 ) , V_74 ) ;
if ( ! V_82 )
return F_39 ( - V_91 ) ;
V_82 -> V_73 = 1 ;
V_82 -> V_90 = * V_84 ;
if ( V_85 > 0 )
memcpy ( V_82 -> V_72 , V_69 , V_85 * sizeof( T_5 ) ) ;
F_40 ( & V_89 ) ;
F_20 ( & V_82 -> V_47 , & V_92 ) ;
F_41 ( & V_89 ) ;
return V_82 ;
}
static void F_42 ( struct V_93 * V_94 )
{
F_36 ( F_43 ( V_94 , struct V_78 , V_95 ) ) ;
}
void F_44 ( struct V_78 * V_69 )
{
if ( ! V_69 )
return;
F_40 ( & V_89 ) ;
if ( -- V_69 -> V_73 == 0 ) {
F_22 ( & V_69 -> V_47 ) ;
F_45 ( & V_69 -> V_95 , F_42 ) ;
}
F_41 ( & V_89 ) ;
}
static int F_46 ( struct V_96 * V_97 , struct V_78 * V_82 )
{
struct V_54 * V_98 ;
V_98 = F_47 ( V_97 , V_99 ) ;
if ( V_98 == NULL )
goto V_100;
if ( F_48 ( V_97 , V_87 , sizeof( V_82 -> V_90 ) , & V_82 -> V_90 ) )
goto V_100;
F_49 ( V_97 , V_98 ) ;
return V_97 -> V_31 ;
V_100:
return - 1 ;
}
void F_50 ( struct V_96 * V_97 , const struct V_78 * V_82 )
{
int V_101 , V_102 ;
V_101 = V_97 -> V_31 + V_82 -> V_90 . V_103 ;
if ( F_51 ( ! V_82 -> V_90 . V_85 ) )
goto V_11;
V_102 = V_101 + V_82 -> V_90 . V_104 ;
if ( F_51 ( V_102 < 0 ) )
V_102 = 0 ;
V_102 >>= V_82 -> V_90 . V_63 ;
if ( F_52 ( V_102 < V_82 -> V_90 . V_85 ) )
V_101 = V_82 -> V_72 [ V_102 ] ;
else
V_101 = V_82 -> V_72 [ V_82 -> V_90 . V_85 - 1 ] *
( V_102 / V_82 -> V_90 . V_85 ) +
V_82 -> V_72 [ V_102 % V_82 -> V_90 . V_85 ] ;
V_101 <<= V_82 -> V_90 . V_105 ;
V_11:
if ( F_51 ( V_101 < 1 ) )
V_101 = 1 ;
F_53 ( V_97 ) -> V_101 = V_101 ;
}
void F_54 ( const char * V_106 , struct V_37 * V_45 )
{
if ( ! ( V_45 -> V_40 & V_107 ) ) {
F_55 ( L_4 ,
V_106 , V_45 -> V_34 -> V_10 , V_45 -> V_39 >> 16 ) ;
V_45 -> V_40 |= V_107 ;
}
}
static enum V_108 F_56 ( struct V_109 * V_110 )
{
struct F_56 * V_111 = F_43 ( V_110 , struct F_56 ,
V_110 ) ;
F_57 ( V_111 -> V_45 ) ;
F_58 ( F_59 ( V_111 -> V_45 ) ) ;
return V_112 ;
}
void F_60 ( struct F_56 * V_111 , struct V_37 * V_45 )
{
F_61 ( & V_111 -> V_110 , V_113 , V_114 ) ;
V_111 -> V_110 . V_115 = F_56 ;
V_111 -> V_45 = V_45 ;
}
void F_62 ( struct F_56 * V_111 , T_6 V_116 )
{
if ( F_63 ( V_117 ,
& F_64 ( V_111 -> V_45 ) -> V_118 ) )
return;
F_65 ( V_111 -> V_45 ) ;
F_66 ( & V_111 -> V_110 ,
F_67 ( V_116 ) ,
V_114 ) ;
}
void F_68 ( struct F_56 * V_111 )
{
F_69 ( & V_111 -> V_110 ) ;
F_57 ( V_111 -> V_45 ) ;
}
static struct V_119 * F_70 ( unsigned int V_120 )
{
unsigned int V_121 = V_120 * sizeof( struct V_119 ) , V_122 ;
struct V_119 * V_123 ;
if ( V_121 <= V_124 )
V_123 = F_34 ( V_121 , V_74 ) ;
else
V_123 = (struct V_119 * )
F_71 ( V_74 , F_72 ( V_121 ) ) ;
if ( V_123 != NULL ) {
for ( V_122 = 0 ; V_122 < V_120 ; V_122 ++ )
F_73 ( & V_123 [ V_122 ] ) ;
}
return V_123 ;
}
static void F_74 ( struct V_119 * V_123 , unsigned int V_120 )
{
unsigned int V_121 = V_120 * sizeof( struct V_119 ) ;
if ( V_121 <= V_124 )
F_36 ( V_123 ) ;
else
F_75 ( ( unsigned long ) V_123 , F_72 ( V_121 ) ) ;
}
void F_76 ( struct V_37 * V_125 , struct V_126 * V_127 )
{
struct V_128 * V_53 ;
struct V_129 * V_9 ;
struct V_119 * V_130 , * V_131 ;
unsigned int V_132 , V_133 , V_134 ;
unsigned int V_122 , V_123 ;
if ( V_127 -> V_135 * 4 <= V_127 -> V_136 * 3 )
return;
V_132 = V_127 -> V_136 * 2 ;
V_133 = V_132 - 1 ;
V_130 = F_70 ( V_132 ) ;
if ( V_130 == NULL )
return;
V_131 = V_127 -> V_137 ;
V_134 = V_127 -> V_136 ;
F_77 ( V_125 ) ;
for ( V_122 = 0 ; V_122 < V_134 ; V_122 ++ ) {
F_78 (cl, next, &ohash[i], hnode) {
V_123 = F_79 ( V_53 -> V_52 , V_133 ) ;
F_80 ( & V_53 -> V_138 , & V_130 [ V_123 ] ) ;
}
}
V_127 -> V_137 = V_130 ;
V_127 -> V_136 = V_132 ;
V_127 -> V_139 = V_133 ;
F_81 ( V_125 ) ;
F_74 ( V_131 , V_134 ) ;
}
int F_82 ( struct V_126 * V_127 )
{
unsigned int V_121 = 4 ;
V_127 -> V_137 = F_70 ( V_121 ) ;
if ( V_127 -> V_137 == NULL )
return - V_91 ;
V_127 -> V_136 = V_121 ;
V_127 -> V_139 = V_121 - 1 ;
V_127 -> V_135 = 0 ;
return 0 ;
}
void F_83 ( struct V_126 * V_127 )
{
F_74 ( V_127 -> V_137 , V_127 -> V_136 ) ;
}
void F_84 ( struct V_126 * V_127 ,
struct V_128 * V_53 )
{
unsigned int V_123 ;
F_85 ( & V_53 -> V_138 ) ;
V_123 = F_79 ( V_53 -> V_52 , V_127 -> V_139 ) ;
F_80 ( & V_53 -> V_138 , & V_127 -> V_137 [ V_123 ] ) ;
V_127 -> V_135 ++ ;
}
void F_86 ( struct V_126 * V_127 ,
struct V_128 * V_53 )
{
F_87 ( & V_53 -> V_138 ) ;
V_127 -> V_135 -- ;
}
static T_2 F_88 ( struct V_48 * V_49 )
{
int V_122 = 0x8000 ;
static T_2 V_140 = F_89 ( 0x80000000U , 0 ) ;
do {
V_140 += F_89 ( 0x10000U , 0 ) ;
if ( V_140 == F_89 ( V_43 , 0 ) )
V_140 = F_89 ( 0x80000000U , 0 ) ;
if ( ! F_23 ( V_49 , V_140 ) )
return V_140 ;
F_90 () ;
} while ( -- V_122 > 0 );
return 0 ;
}
void F_91 ( struct V_37 * V_125 , unsigned int V_120 )
{
const struct V_18 * V_19 ;
unsigned long V_53 ;
T_2 V_141 ;
int V_142 ;
if ( V_120 == 0 )
return;
V_142 = F_92 ( int , V_120 , 0 ) ;
while ( ( V_141 = V_125 -> V_42 ) ) {
if ( F_93 ( V_141 ) == F_93 ( V_143 ) )
return;
V_125 = F_23 ( F_18 ( V_125 ) , F_93 ( V_141 ) ) ;
if ( V_125 == NULL ) {
F_94 ( V_141 != V_43 ) ;
return;
}
V_19 = V_125 -> V_34 -> V_17 ;
if ( V_19 -> V_144 ) {
V_53 = V_19 -> V_20 ( V_125 , V_141 ) ;
V_19 -> V_144 ( V_125 , V_53 ) ;
V_19 -> V_21 ( V_125 , V_53 ) ;
}
V_125 -> V_3 . V_145 -= V_120 ;
V_125 -> V_146 . V_142 += V_142 ;
}
}
static void F_95 ( struct V_147 * V_147 , struct V_96 * V_97 ,
struct V_148 * V_120 , T_2 V_149 ,
struct V_37 * V_150 , struct V_37 * V_151 )
{
if ( V_151 || V_150 )
F_96 ( V_147 , V_97 , V_120 , V_149 , V_150 , V_151 ) ;
if ( V_150 )
F_97 ( V_150 ) ;
}
static int F_98 ( struct V_48 * V_49 , struct V_37 * V_42 ,
struct V_96 * V_97 , struct V_148 * V_120 , T_2 V_52 ,
struct V_37 * V_151 , struct V_37 * V_150 )
{
struct V_37 * V_3 = V_150 ;
struct V_147 * V_147 = F_99 ( V_49 ) ;
int V_28 = 0 ;
if ( V_42 == NULL ) {
unsigned int V_122 , V_152 , V_153 ;
V_153 = 0 ;
V_152 = V_49 -> V_154 ;
if ( ( V_3 && V_3 -> V_40 & V_44 ) ||
( V_151 && V_151 -> V_40 & V_44 ) ) {
V_152 = 1 ;
V_153 = 1 ;
if ( ! F_24 ( V_49 ) )
return - V_29 ;
}
if ( V_49 -> V_40 & V_155 )
F_100 ( V_49 ) ;
if ( V_151 && V_151 -> V_34 -> V_156 ) {
V_151 -> V_34 -> V_156 ( V_151 ) ;
V_152 = 0 ;
}
for ( V_122 = 0 ; V_122 < V_152 ; V_122 ++ ) {
struct V_157 * V_158 = F_24 ( V_49 ) ;
if ( ! V_153 )
V_158 = F_101 ( V_49 , V_122 ) ;
V_150 = F_102 ( V_158 , V_151 ) ;
if ( V_151 && V_122 > 0 )
F_103 ( & V_151 -> V_73 ) ;
if ( ! V_153 )
F_97 ( V_150 ) ;
}
if ( ! V_153 ) {
F_95 ( V_147 , V_97 , V_120 , V_52 ,
V_49 -> V_45 , V_151 ) ;
if ( V_151 && ! V_151 -> V_34 -> V_156 )
F_103 ( & V_151 -> V_73 ) ;
V_49 -> V_45 = V_151 ? : & V_46 ;
} else {
F_95 ( V_147 , V_97 , V_120 , V_52 , V_150 , V_151 ) ;
}
if ( V_49 -> V_40 & V_155 )
F_104 ( V_49 ) ;
} else {
const struct V_18 * V_19 = V_42 -> V_34 -> V_17 ;
V_28 = - V_159 ;
if ( V_19 && V_19 -> V_160 ) {
unsigned long V_53 = V_19 -> V_20 ( V_42 , V_52 ) ;
if ( V_53 ) {
V_28 = V_19 -> V_160 ( V_42 , V_53 , V_151 , & V_150 ) ;
V_19 -> V_21 ( V_42 , V_53 ) ;
} else
V_28 = - V_29 ;
}
if ( ! V_28 )
F_95 ( V_147 , V_97 , V_120 , V_52 , V_150 , V_151 ) ;
}
return V_28 ;
}
static struct V_37 *
F_105 ( struct V_48 * V_49 , struct V_157 * V_158 ,
struct V_37 * V_51 , T_2 V_42 , T_2 V_39 ,
struct V_54 * * V_161 , int * V_162 )
{
int V_28 ;
struct V_54 * V_55 = V_161 [ V_163 ] ;
struct V_37 * V_125 ;
struct V_1 * V_34 ;
struct V_78 * V_82 ;
V_34 = F_26 ( V_55 ) ;
#ifdef F_106
if ( V_34 == NULL && V_55 != NULL ) {
char V_30 [ V_164 ] ;
if ( F_107 ( V_30 , V_55 , V_164 ) < V_164 ) {
F_108 () ;
F_13 ( L_1 , V_30 ) ;
F_109 () ;
V_34 = F_26 ( V_55 ) ;
if ( V_34 != NULL ) {
F_14 ( V_34 -> V_33 ) ;
V_28 = - V_165 ;
goto V_166;
}
}
}
#endif
V_28 = - V_29 ;
if ( V_34 == NULL )
goto V_166;
V_125 = F_110 ( V_158 , V_34 ) ;
if ( F_111 ( V_125 ) ) {
V_28 = F_112 ( V_125 ) ;
goto V_167;
}
V_125 -> V_42 = V_42 ;
if ( V_39 == V_143 ) {
V_125 -> V_40 |= V_44 ;
V_39 = F_89 ( V_143 , 0 ) ;
F_113 ( F_114 ( V_125 ) , & V_168 ) ;
} else {
if ( V_39 == 0 ) {
V_39 = F_88 ( V_49 ) ;
V_28 = - V_91 ;
if ( V_39 == 0 )
goto V_169;
}
F_113 ( F_114 ( V_125 ) , & V_170 ) ;
if ( ! F_115 ( V_49 ) )
V_125 -> V_40 |= V_171 ;
}
V_125 -> V_39 = V_39 ;
if ( ! V_34 -> V_172 || ( V_28 = V_34 -> V_172 ( V_125 , V_161 [ V_173 ] ) ) == 0 ) {
if ( V_161 [ V_99 ] ) {
V_82 = F_37 ( V_161 [ V_99 ] ) ;
if ( F_111 ( V_82 ) ) {
V_28 = F_112 ( V_82 ) ;
goto V_174;
}
F_116 ( V_125 -> V_82 , V_82 ) ;
}
if ( V_161 [ V_175 ] ) {
T_7 * V_176 ;
V_28 = - V_159 ;
if ( V_125 -> V_40 & V_177 )
goto V_174;
if ( ( V_125 -> V_42 != V_43 ) &&
! ( V_125 -> V_40 & V_44 ) &&
( ! V_51 || ! ( V_51 -> V_40 & V_177 ) ) )
V_176 = F_117 ( V_125 ) ;
else
V_176 = F_114 ( V_125 ) ;
V_28 = F_118 ( & V_125 -> V_178 , & V_125 -> V_179 ,
V_176 , V_161 [ V_175 ] ) ;
if ( V_28 )
goto V_174;
}
F_17 ( V_125 ) ;
return V_125 ;
}
V_169:
F_119 ( V_49 ) ;
F_36 ( ( char * ) V_125 - V_125 -> V_180 ) ;
V_167:
F_14 ( V_34 -> V_33 ) ;
V_166:
* V_162 = V_28 ;
return NULL ;
V_174:
F_44 ( F_120 ( V_125 -> V_82 ) ) ;
if ( V_34 -> V_181 )
V_34 -> V_181 ( V_125 ) ;
goto V_169;
}
static int F_121 ( struct V_37 * V_125 , struct V_54 * * V_161 )
{
struct V_78 * V_182 , * V_82 = NULL ;
int V_28 = 0 ;
if ( V_161 [ V_173 ] ) {
if ( V_125 -> V_34 -> V_183 == NULL )
return - V_27 ;
V_28 = V_125 -> V_34 -> V_183 ( V_125 , V_161 [ V_173 ] ) ;
if ( V_28 )
return V_28 ;
}
if ( V_161 [ V_99 ] ) {
V_82 = F_37 ( V_161 [ V_99 ] ) ;
if ( F_111 ( V_82 ) )
return F_112 ( V_82 ) ;
}
V_182 = F_120 ( V_125 -> V_82 ) ;
F_116 ( V_125 -> V_82 , V_82 ) ;
F_44 ( V_182 ) ;
if ( V_161 [ V_175 ] ) {
if ( V_125 -> V_40 & V_177 )
goto V_11;
F_122 ( & V_125 -> V_178 , & V_125 -> V_179 ,
F_117 ( V_125 ) ,
V_161 [ V_175 ] ) ;
}
V_11:
return 0 ;
}
static int F_123 ( struct V_37 * V_3 , struct V_37 * V_51 , int V_184 )
{
struct V_185 V_186 ;
if ( V_3 -> V_34 -> V_17 == NULL )
return 0 ;
V_186 . V_187 . V_188 = V_186 . V_187 . V_189 = V_186 . V_187 . V_190 = 0 ;
V_186 . V_187 . V_191 = V_192 ;
V_186 . V_184 = V_184 ;
V_186 . V_51 = V_51 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_186 . V_187 ) ;
return V_186 . V_187 . V_188 ? - V_193 : 0 ;
}
static int
V_192 ( struct V_37 * V_3 , unsigned long V_53 , struct V_194 * V_187 )
{
struct V_37 * V_23 ;
const struct V_18 * V_19 = V_3 -> V_34 -> V_17 ;
struct V_185 * V_186 = (struct V_185 * ) V_187 ;
V_23 = V_19 -> V_23 ( V_3 , V_53 ) ;
if ( V_23 ) {
if ( V_23 == V_186 -> V_51 || V_186 -> V_184 > 7 )
return - V_193 ;
return F_123 ( V_23 , V_186 -> V_51 , V_186 -> V_184 + 1 ) ;
}
return 0 ;
}
static int F_124 ( struct V_96 * V_97 , struct V_148 * V_120 )
{
struct V_147 * V_147 = F_125 ( V_97 -> V_195 ) ;
struct V_196 * V_197 = F_126 ( V_120 ) ;
struct V_54 * V_161 [ V_198 + 1 ] ;
struct V_48 * V_49 ;
T_2 V_149 ;
struct V_37 * V_3 = NULL ;
struct V_37 * V_51 = NULL ;
int V_28 ;
if ( ( V_120 -> V_199 != V_200 ) &&
! F_127 ( V_97 , V_147 -> V_201 , V_35 ) )
return - V_36 ;
V_28 = F_128 ( V_120 , sizeof( * V_197 ) , V_161 , V_198 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_49 = F_129 ( V_147 , V_197 -> V_202 ) ;
if ( ! V_49 )
return - V_203 ;
V_149 = V_197 -> V_204 ;
if ( V_149 ) {
if ( V_149 != V_43 ) {
if ( F_93 ( V_149 ) != F_93 ( V_143 ) ) {
V_51 = F_23 ( V_49 , F_93 ( V_149 ) ) ;
if ( ! V_51 )
return - V_29 ;
V_3 = F_25 ( V_51 , V_149 ) ;
} else if ( F_24 ( V_49 ) ) {
V_3 = F_24 ( V_49 ) -> V_50 ;
}
} else {
V_3 = V_49 -> V_45 ;
}
if ( ! V_3 )
return - V_29 ;
if ( V_197 -> V_205 && V_3 -> V_39 != V_197 -> V_205 )
return - V_27 ;
} else {
V_3 = F_23 ( V_49 , V_197 -> V_205 ) ;
if ( ! V_3 )
return - V_29 ;
}
if ( V_161 [ V_163 ] && F_27 ( V_161 [ V_163 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_120 -> V_199 == V_206 ) {
if ( ! V_149 )
return - V_27 ;
if ( V_3 -> V_39 == 0 )
return - V_29 ;
V_28 = F_98 ( V_49 , V_51 , V_97 , V_120 , V_149 , NULL , V_3 ) ;
if ( V_28 != 0 )
return V_28 ;
} else {
F_96 ( V_147 , V_97 , V_120 , V_149 , NULL , V_3 ) ;
}
return 0 ;
}
static int F_130 ( struct V_96 * V_97 , struct V_148 * V_120 )
{
struct V_147 * V_147 = F_125 ( V_97 -> V_195 ) ;
struct V_196 * V_197 ;
struct V_54 * V_161 [ V_198 + 1 ] ;
struct V_48 * V_49 ;
T_2 V_149 ;
struct V_37 * V_3 , * V_51 ;
int V_28 ;
if ( ! F_127 ( V_97 , V_147 -> V_201 , V_35 ) )
return - V_36 ;
V_207:
V_28 = F_128 ( V_120 , sizeof( * V_197 ) , V_161 , V_198 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_197 = F_126 ( V_120 ) ;
V_149 = V_197 -> V_204 ;
V_3 = V_51 = NULL ;
V_49 = F_129 ( V_147 , V_197 -> V_202 ) ;
if ( ! V_49 )
return - V_203 ;
if ( V_149 ) {
if ( V_149 != V_43 ) {
if ( V_149 != V_143 ) {
V_51 = F_23 ( V_49 , F_93 ( V_149 ) ) ;
if ( ! V_51 )
return - V_29 ;
V_3 = F_25 ( V_51 , V_149 ) ;
} else if ( F_131 ( V_49 ) ) {
V_3 = F_24 ( V_49 ) -> V_50 ;
}
} else {
V_3 = V_49 -> V_45 ;
}
if ( V_3 && V_3 -> V_39 == 0 )
V_3 = NULL ;
if ( ! V_3 || ! V_197 -> V_205 || V_3 -> V_39 != V_197 -> V_205 ) {
if ( V_197 -> V_205 ) {
if ( V_3 && ! ( V_120 -> V_208 & V_209 ) )
return - V_6 ;
if ( F_132 ( V_197 -> V_205 ) )
return - V_27 ;
V_3 = F_23 ( V_49 , V_197 -> V_205 ) ;
if ( ! V_3 )
goto V_210;
if ( V_120 -> V_208 & V_211 )
return - V_6 ;
if ( V_161 [ V_163 ] && F_27 ( V_161 [ V_163 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_3 == V_51 ||
( V_51 && F_123 ( V_3 , V_51 , 0 ) ) )
return - V_193 ;
F_103 ( & V_3 -> V_73 ) ;
goto V_160;
} else {
if ( ! V_3 )
goto V_210;
if ( ( V_120 -> V_208 & V_212 ) &&
( V_120 -> V_208 & V_209 ) &&
( ( V_120 -> V_208 & V_211 ) ||
( V_161 [ V_163 ] &&
F_27 ( V_161 [ V_163 ] , V_3 -> V_34 -> V_10 ) ) ) )
goto V_210;
}
}
} else {
if ( ! V_197 -> V_205 )
return - V_27 ;
V_3 = F_23 ( V_49 , V_197 -> V_205 ) ;
}
if ( V_3 == NULL )
return - V_29 ;
if ( V_120 -> V_208 & V_211 )
return - V_6 ;
if ( V_161 [ V_163 ] && F_27 ( V_161 [ V_163 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
V_28 = F_121 ( V_3 , V_161 ) ;
if ( V_28 == 0 )
F_96 ( V_147 , V_97 , V_120 , V_149 , NULL , V_3 ) ;
return V_28 ;
V_210:
if ( ! ( V_120 -> V_208 & V_212 ) )
return - V_29 ;
if ( V_149 == V_143 ) {
if ( F_24 ( V_49 ) )
V_3 = F_105 ( V_49 , F_24 ( V_49 ) , V_51 ,
V_197 -> V_204 , V_197 -> V_204 ,
V_161 , & V_28 ) ;
else
V_28 = - V_29 ;
} else {
struct V_157 * V_158 ;
if ( V_51 && V_51 -> V_34 -> V_17 && V_51 -> V_34 -> V_17 -> V_213 )
V_158 = V_51 -> V_34 -> V_17 -> V_213 ( V_51 , V_197 ) ;
else if ( V_51 )
V_158 = V_51 -> V_158 ;
else
V_158 = F_101 ( V_49 , 0 ) ;
V_3 = F_105 ( V_49 , V_158 , V_51 ,
V_197 -> V_204 , V_197 -> V_205 ,
V_161 , & V_28 ) ;
}
if ( V_3 == NULL ) {
if ( V_28 == - V_165 )
goto V_207;
return V_28 ;
}
V_160:
V_28 = F_98 ( V_49 , V_51 , V_97 , V_120 , V_149 , V_3 , NULL ) ;
if ( V_28 ) {
if ( V_3 )
F_97 ( V_3 ) ;
return V_28 ;
}
return 0 ;
}
static int F_133 ( struct V_96 * V_97 , struct V_37 * V_3 , T_2 V_149 ,
T_2 V_214 , T_2 V_215 , T_5 V_40 , int V_216 )
{
struct V_196 * V_197 ;
struct V_148 * V_217 ;
unsigned char * V_218 = F_134 ( V_97 ) ;
struct V_219 V_220 ;
struct V_78 * V_82 ;
F_90 () ;
V_217 = F_135 ( V_97 , V_214 , V_215 , V_216 , sizeof( * V_197 ) , V_40 ) ;
if ( ! V_217 )
goto V_221;
V_197 = F_126 ( V_217 ) ;
V_197 -> V_222 = V_223 ;
V_197 -> V_224 = 0 ;
V_197 -> V_225 = 0 ;
V_197 -> V_202 = F_18 ( V_3 ) -> V_226 ;
V_197 -> V_204 = V_149 ;
V_197 -> V_205 = V_3 -> V_39 ;
V_197 -> V_227 = F_136 ( & V_3 -> V_73 ) ;
if ( F_137 ( V_97 , V_163 , V_3 -> V_34 -> V_10 ) )
goto V_100;
if ( V_3 -> V_34 -> V_228 && V_3 -> V_34 -> V_228 ( V_3 , V_97 ) < 0 )
goto V_100;
V_3 -> V_146 . V_145 = V_3 -> V_3 . V_145 ;
V_82 = F_120 ( V_3 -> V_82 ) ;
if ( V_82 && F_46 ( V_97 , V_82 ) < 0 )
goto V_100;
if ( F_138 ( V_97 , V_229 , V_230 , V_231 ,
F_117 ( V_3 ) , & V_220 ) < 0 )
goto V_100;
if ( V_3 -> V_34 -> V_232 && V_3 -> V_34 -> V_232 ( V_3 , & V_220 ) < 0 )
goto V_100;
if ( F_139 ( & V_220 , & V_3 -> V_178 ) < 0 ||
F_140 ( & V_220 , & V_3 -> V_178 , & V_3 -> V_179 ) < 0 ||
F_141 ( & V_220 , & V_3 -> V_146 ) < 0 )
goto V_100;
if ( F_142 ( & V_220 ) < 0 )
goto V_100;
V_217 -> V_233 = F_134 ( V_97 ) - V_218 ;
return V_97 -> V_31 ;
V_221:
V_100:
F_143 ( V_97 , V_218 ) ;
return - 1 ;
}
static bool F_144 ( struct V_37 * V_3 )
{
return ( V_3 -> V_40 & V_41 ) ? true : false ;
}
static int F_96 ( struct V_147 * V_147 , struct V_96 * V_234 ,
struct V_148 * V_120 , T_2 V_149 ,
struct V_37 * V_150 , struct V_37 * V_151 )
{
struct V_96 * V_97 ;
T_2 V_214 = V_234 ? F_145 ( V_234 ) . V_214 : 0 ;
V_97 = F_146 ( V_235 , V_74 ) ;
if ( ! V_97 )
return - V_236 ;
if ( V_150 && ! F_144 ( V_150 ) ) {
if ( F_133 ( V_97 , V_150 , V_149 , V_214 , V_120 -> V_237 ,
0 , V_206 ) < 0 )
goto V_166;
}
if ( V_151 && ! F_144 ( V_151 ) ) {
if ( F_133 ( V_97 , V_151 , V_149 , V_214 , V_120 -> V_237 ,
V_150 ? V_209 : 0 , V_238 ) < 0 )
goto V_166;
}
if ( V_97 -> V_31 )
return F_147 ( V_97 , V_147 , V_214 , V_239 ,
V_120 -> V_208 & V_240 ) ;
V_166:
F_148 ( V_97 ) ;
return - V_27 ;
}
static int F_149 ( struct V_37 * V_38 , struct V_96 * V_97 ,
struct V_241 * V_242 ,
int * V_243 , int V_244 )
{
int V_245 = 0 , V_246 = * V_243 ;
struct V_37 * V_3 ;
if ( ! V_38 )
return 0 ;
V_3 = V_38 ;
if ( V_246 < V_244 ) {
V_246 ++ ;
} else {
if ( ! F_144 ( V_3 ) &&
F_133 ( V_97 , V_3 , V_3 -> V_42 , F_145 ( V_242 -> V_97 ) . V_214 ,
V_242 -> V_217 -> V_237 , V_247 , V_238 ) <= 0 )
goto V_248;
V_246 ++ ;
}
F_16 (q, &root->list, list) {
if ( V_246 < V_244 ) {
V_246 ++ ;
continue;
}
if ( ! F_144 ( V_3 ) &&
F_133 ( V_97 , V_3 , V_3 -> V_42 , F_145 ( V_242 -> V_97 ) . V_214 ,
V_242 -> V_217 -> V_237 , V_247 , V_238 ) <= 0 )
goto V_248;
V_246 ++ ;
}
V_11:
* V_243 = V_246 ;
return V_245 ;
V_248:
V_245 = - 1 ;
goto V_11;
}
static int F_150 ( struct V_96 * V_97 , struct V_241 * V_242 )
{
struct V_147 * V_147 = F_125 ( V_97 -> V_195 ) ;
int V_249 , V_246 ;
int V_250 , V_244 ;
struct V_48 * V_49 ;
V_250 = V_242 -> args [ 0 ] ;
V_244 = V_246 = V_242 -> args [ 1 ] ;
V_249 = 0 ;
F_151 () ;
F_152 (net, dev) {
struct V_157 * V_158 ;
if ( V_249 < V_250 )
goto V_251;
if ( V_249 > V_250 )
V_244 = 0 ;
V_246 = 0 ;
if ( F_149 ( V_49 -> V_45 , V_97 , V_242 , & V_246 , V_244 ) < 0 )
goto V_248;
V_158 = F_24 ( V_49 ) ;
if ( V_158 &&
F_149 ( V_158 -> V_50 , V_97 , V_242 ,
& V_246 , V_244 ) < 0 )
goto V_248;
V_251:
V_249 ++ ;
}
V_248:
V_242 -> args [ 0 ] = V_249 ;
V_242 -> args [ 1 ] = V_246 ;
return V_97 -> V_31 ;
}
static int F_153 ( struct V_96 * V_97 , struct V_148 * V_120 )
{
struct V_147 * V_147 = F_125 ( V_97 -> V_195 ) ;
struct V_196 * V_197 = F_126 ( V_120 ) ;
struct V_54 * V_161 [ V_198 + 1 ] ;
struct V_48 * V_49 ;
struct V_37 * V_3 = NULL ;
const struct V_18 * V_19 ;
unsigned long V_53 = 0 ;
unsigned long V_252 ;
T_2 V_214 ;
T_2 V_149 ;
T_2 V_253 ;
int V_28 ;
if ( ( V_120 -> V_199 != V_254 ) &&
! F_127 ( V_97 , V_147 -> V_201 , V_35 ) )
return - V_36 ;
V_28 = F_128 ( V_120 , sizeof( * V_197 ) , V_161 , V_198 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_49 = F_129 ( V_147 , V_197 -> V_202 ) ;
if ( ! V_49 )
return - V_203 ;
V_214 = V_197 -> V_204 ;
V_149 = V_197 -> V_205 ;
V_253 = F_93 ( V_149 ) ;
if ( V_214 != V_43 ) {
T_2 V_255 = F_93 ( V_214 ) ;
if ( V_253 && V_255 ) {
if ( V_253 != V_255 )
return - V_27 ;
} else if ( V_255 ) {
V_253 = V_255 ;
} else if ( V_253 == 0 )
V_253 = V_49 -> V_45 -> V_39 ;
if ( V_214 )
V_214 = F_89 ( V_253 , V_214 ) ;
} else {
if ( V_253 == 0 )
V_253 = V_49 -> V_45 -> V_39 ;
}
V_3 = F_23 ( V_49 , V_253 ) ;
if ( ! V_3 )
return - V_29 ;
V_19 = V_3 -> V_34 -> V_17 ;
if ( V_19 == NULL )
return - V_27 ;
if ( V_149 == 0 ) {
if ( V_214 == V_43 )
V_149 = V_253 ;
} else
V_149 = F_89 ( V_253 , V_149 ) ;
if ( V_149 )
V_53 = V_19 -> V_20 ( V_3 , V_149 ) ;
if ( V_53 == 0 ) {
V_28 = - V_29 ;
if ( V_120 -> V_199 != V_256 ||
! ( V_120 -> V_208 & V_212 ) )
goto V_11;
} else {
switch ( V_120 -> V_199 ) {
case V_256 :
V_28 = - V_6 ;
if ( V_120 -> V_208 & V_211 )
goto V_11;
break;
case V_257 :
V_28 = - V_159 ;
if ( V_19 -> V_258 )
V_28 = V_19 -> V_258 ( V_3 , V_53 ) ;
if ( V_28 == 0 )
F_154 ( V_147 , V_97 , V_120 , V_3 , V_53 , V_257 ) ;
goto V_11;
case V_254 :
V_28 = F_154 ( V_147 , V_97 , V_120 , V_3 , V_53 , V_256 ) ;
goto V_11;
default:
V_28 = - V_27 ;
goto V_11;
}
}
V_252 = V_53 ;
V_28 = - V_159 ;
if ( V_19 -> V_183 )
V_28 = V_19 -> V_183 ( V_3 , V_149 , V_214 , V_161 , & V_252 ) ;
if ( V_28 == 0 )
F_154 ( V_147 , V_97 , V_120 , V_3 , V_252 , V_256 ) ;
V_11:
if ( V_53 )
V_19 -> V_21 ( V_3 , V_53 ) ;
return V_28 ;
}
static int F_155 ( struct V_96 * V_97 , struct V_37 * V_3 ,
unsigned long V_53 ,
T_2 V_214 , T_2 V_215 , T_5 V_40 , int V_216 )
{
struct V_196 * V_197 ;
struct V_148 * V_217 ;
unsigned char * V_218 = F_134 ( V_97 ) ;
struct V_219 V_220 ;
const struct V_18 * V_17 = V_3 -> V_34 -> V_17 ;
F_90 () ;
V_217 = F_135 ( V_97 , V_214 , V_215 , V_216 , sizeof( * V_197 ) , V_40 ) ;
if ( ! V_217 )
goto V_221;
V_197 = F_126 ( V_217 ) ;
V_197 -> V_222 = V_223 ;
V_197 -> V_224 = 0 ;
V_197 -> V_225 = 0 ;
V_197 -> V_202 = F_18 ( V_3 ) -> V_226 ;
V_197 -> V_204 = V_3 -> V_39 ;
V_197 -> V_205 = V_3 -> V_39 ;
V_197 -> V_227 = 0 ;
if ( F_137 ( V_97 , V_163 , V_3 -> V_34 -> V_10 ) )
goto V_100;
if ( V_17 -> V_228 && V_17 -> V_228 ( V_3 , V_53 , V_97 , V_197 ) < 0 )
goto V_100;
if ( F_138 ( V_97 , V_229 , V_230 , V_231 ,
F_117 ( V_3 ) , & V_220 ) < 0 )
goto V_100;
if ( V_17 -> V_232 && V_17 -> V_232 ( V_3 , V_53 , & V_220 ) < 0 )
goto V_100;
if ( F_142 ( & V_220 ) < 0 )
goto V_100;
V_217 -> V_233 = F_134 ( V_97 ) - V_218 ;
return V_97 -> V_31 ;
V_221:
V_100:
F_143 ( V_97 , V_218 ) ;
return - 1 ;
}
static int F_154 ( struct V_147 * V_147 , struct V_96 * V_234 ,
struct V_148 * V_120 , struct V_37 * V_3 ,
unsigned long V_53 , int V_216 )
{
struct V_96 * V_97 ;
T_2 V_214 = V_234 ? F_145 ( V_234 ) . V_214 : 0 ;
V_97 = F_146 ( V_235 , V_74 ) ;
if ( ! V_97 )
return - V_236 ;
if ( F_155 ( V_97 , V_3 , V_53 , V_214 , V_120 -> V_237 , 0 , V_216 ) < 0 ) {
F_148 ( V_97 ) ;
return - V_27 ;
}
return F_147 ( V_97 , V_147 , V_214 , V_239 ,
V_120 -> V_208 & V_240 ) ;
}
static int F_156 ( struct V_37 * V_3 , unsigned long V_53 , struct V_194 * V_186 )
{
struct V_259 * V_260 = (struct V_259 * ) V_186 ;
return F_155 ( V_260 -> V_97 , V_3 , V_53 , F_145 ( V_260 -> V_242 -> V_97 ) . V_214 ,
V_260 -> V_242 -> V_217 -> V_237 , V_247 , V_256 ) ;
}
static int F_157 ( struct V_37 * V_3 , struct V_96 * V_97 ,
struct V_196 * V_197 , struct V_241 * V_242 ,
int * V_261 , int V_262 )
{
struct V_259 V_186 ;
if ( F_144 ( V_3 ) ||
* V_261 < V_262 || ! V_3 -> V_34 -> V_17 ||
( V_197 -> V_204 &&
F_93 ( V_197 -> V_204 ) != V_3 -> V_39 ) ) {
( * V_261 ) ++ ;
return 0 ;
}
if ( * V_261 > V_262 )
memset ( & V_242 -> args [ 1 ] , 0 , sizeof( V_242 -> args ) - sizeof( V_242 -> args [ 0 ] ) ) ;
V_186 . V_187 . V_191 = F_156 ;
V_186 . V_97 = V_97 ;
V_186 . V_242 = V_242 ;
V_186 . V_187 . V_188 = 0 ;
V_186 . V_187 . V_189 = V_242 -> args [ 1 ] ;
V_186 . V_187 . V_190 = 0 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_186 . V_187 ) ;
V_242 -> args [ 1 ] = V_186 . V_187 . V_190 ;
if ( V_186 . V_187 . V_188 )
return - 1 ;
( * V_261 ) ++ ;
return 0 ;
}
static int F_158 ( struct V_37 * V_38 , struct V_96 * V_97 ,
struct V_196 * V_197 , struct V_241 * V_242 ,
int * V_261 , int V_262 )
{
struct V_37 * V_3 ;
if ( ! V_38 )
return 0 ;
if ( F_157 ( V_38 , V_97 , V_197 , V_242 , V_261 , V_262 ) < 0 )
return - 1 ;
F_16 (q, &root->list, list) {
if ( F_157 ( V_3 , V_97 , V_197 , V_242 , V_261 , V_262 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_159 ( struct V_96 * V_97 , struct V_241 * V_242 )
{
struct V_196 * V_197 = F_126 ( V_242 -> V_217 ) ;
struct V_147 * V_147 = F_125 ( V_97 -> V_195 ) ;
struct V_157 * V_158 ;
struct V_48 * V_49 ;
int V_263 , V_262 ;
if ( V_233 ( V_242 -> V_217 ) < sizeof( * V_197 ) )
return 0 ;
V_49 = F_160 ( V_147 , V_197 -> V_202 ) ;
if ( ! V_49 )
return 0 ;
V_262 = V_242 -> args [ 0 ] ;
V_263 = 0 ;
if ( F_158 ( V_49 -> V_45 , V_97 , V_197 , V_242 , & V_263 , V_262 ) < 0 )
goto V_248;
V_158 = F_24 ( V_49 ) ;
if ( V_158 &&
F_158 ( V_158 -> V_50 , V_97 , V_197 , V_242 ,
& V_263 , V_262 ) < 0 )
goto V_248;
V_248:
V_242 -> args [ 0 ] = V_263 ;
F_119 ( V_49 ) ;
return V_97 -> V_31 ;
}
int F_161 ( struct V_96 * V_97 , const struct V_264 * V_265 ,
struct V_266 * V_267 )
{
T_8 V_268 = V_97 -> V_268 ;
int V_28 ;
for (; V_265 ; V_265 = V_265 -> V_9 ) {
if ( V_265 -> V_268 != V_268 &&
V_265 -> V_268 != F_162 ( V_269 ) )
continue;
V_28 = V_265 -> V_270 ( V_97 , V_265 , V_267 ) ;
if ( V_28 >= 0 ) {
#ifdef F_163
if ( V_28 != V_271 && V_97 -> V_272 )
V_97 -> V_272 = F_164 ( V_97 -> V_272 , 0 ) ;
#endif
return V_28 ;
}
}
return - 1 ;
}
int F_165 ( struct V_96 * V_97 , const struct V_264 * V_265 ,
struct V_266 * V_267 )
{
int V_28 = 0 ;
#ifdef F_163
const struct V_264 * V_273 = V_265 ;
V_274:
#endif
V_28 = F_161 ( V_97 , V_265 , V_267 ) ;
#ifdef F_163
if ( V_28 == V_271 ) {
T_2 V_275 = F_166 ( V_97 -> V_272 ) ;
V_265 = V_273 ;
if ( V_275 ++ >= V_276 ) {
F_167 ( L_5 ,
V_265 -> V_3 -> V_34 -> V_10 ,
V_265 -> V_277 & 0xffff ,
F_168 ( V_265 -> V_268 ) ) ;
return V_278 ;
}
V_97 -> V_272 = F_164 ( V_97 -> V_272 , V_275 ) ;
goto V_274;
}
#endif
return V_28 ;
}
void F_169 ( struct V_264 * V_265 )
{
V_265 -> V_34 -> V_181 ( V_265 ) ;
F_14 ( V_265 -> V_34 -> V_33 ) ;
F_36 ( V_265 ) ;
}
void F_170 ( struct V_264 * * V_279 )
{
struct V_264 * V_265 ;
while ( ( V_265 = * V_279 ) != NULL ) {
* V_279 = V_265 -> V_9 ;
F_169 ( V_265 ) ;
}
}
static int F_171 ( struct V_280 * V_215 , void * V_281 )
{
struct V_282 V_283 ;
F_172 ( V_113 , & V_283 ) ;
F_173 ( V_215 , L_6 ,
( T_2 ) V_284 , ( T_2 ) F_174 ( 1 ) ,
1000000 ,
( T_2 ) V_285 / ( T_2 ) F_175 ( F_176 ( V_283 ) ) ) ;
return 0 ;
}
static int F_177 ( struct V_286 * V_286 , struct V_287 * V_287 )
{
return F_178 ( V_287 , F_171 , NULL ) ;
}
static int T_9 F_179 ( struct V_147 * V_147 )
{
struct V_288 * V_289 ;
V_289 = F_180 ( L_7 , 0 , V_147 -> V_290 , & V_291 ) ;
if ( V_289 == NULL )
return - V_91 ;
return 0 ;
}
static void T_10 F_181 ( struct V_147 * V_147 )
{
F_182 ( L_7 , V_147 -> V_290 ) ;
}
static int T_9 F_179 ( struct V_147 * V_147 )
{
return 0 ;
}
static void T_10 F_181 ( struct V_147 * V_147 )
{
}
static int T_11 F_183 ( void )
{
int V_28 ;
V_28 = F_184 ( & V_292 ) ;
if ( V_28 ) {
F_185 ( L_8
L_9 ) ;
return V_28 ;
}
F_1 ( & V_293 ) ;
F_1 ( & V_294 ) ;
F_1 ( & V_295 ) ;
F_1 ( & V_296 ) ;
F_1 ( & V_297 ) ;
F_186 ( V_298 , V_238 , F_130 , NULL , NULL ) ;
F_186 ( V_298 , V_206 , F_124 , NULL , NULL ) ;
F_186 ( V_298 , V_200 , F_124 , F_150 , NULL ) ;
F_186 ( V_298 , V_256 , F_153 , NULL , NULL ) ;
F_186 ( V_298 , V_257 , F_153 , NULL , NULL ) ;
F_186 ( V_298 , V_254 , F_153 , F_159 , NULL ) ;
return 0 ;
}
