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
F_20 () ;
F_21 ( & V_3 -> V_47 , & V_38 -> V_47 ) ;
}
}
void F_22 ( struct V_37 * V_3 )
{
if ( ( V_3 -> V_42 != V_43 ) && ! ( V_3 -> V_40 & V_44 ) ) {
F_20 () ;
F_23 ( & V_3 -> V_47 ) ;
}
}
struct V_37 * F_24 ( struct V_48 * V_49 , T_2 V_39 )
{
struct V_37 * V_3 ;
V_3 = F_15 ( V_49 -> V_45 , V_39 ) ;
if ( V_3 )
goto V_11;
if ( F_25 ( V_49 ) )
V_3 = F_15 (
F_25 ( V_49 ) -> V_50 ,
V_39 ) ;
V_11:
return V_3 ;
}
static struct V_37 * F_26 ( struct V_37 * V_51 , T_2 V_52 )
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
static struct V_1 * F_27 ( struct V_54 * V_55 )
{
struct V_1 * V_3 = NULL ;
if ( V_55 ) {
F_6 ( & V_7 ) ;
for ( V_3 = V_8 ; V_3 ; V_3 = V_3 -> V_9 ) {
if ( F_28 ( V_55 , V_3 -> V_10 ) == 0 ) {
if ( ! F_10 ( V_3 -> V_33 ) )
V_3 = NULL ;
break;
}
}
F_8 ( & V_7 ) ;
}
return V_3 ;
}
static T_3 F_29 ( struct V_56 * V_57 , T_4 * V_58 )
{
int V_59 = F_30 ( V_57 -> V_60 , 48 ) ;
int V_61 = F_30 ( V_59 + 1 , 48 ) ;
int V_62 = V_59 >> V_57 -> V_63 ;
int V_64 = ( V_61 >> V_57 -> V_63 ) - 1 ;
if ( ( V_57 -> V_65 > ( 100000000 / 8 ) ) || ( V_58 [ 0 ] == 0 ) ) {
F_31 ( L_2 ) ;
return V_66 ;
}
if ( ( V_64 > V_62 ) && ( V_64 < 256 )
&& ( V_58 [ V_62 ] == V_58 [ V_64 ] ) ) {
F_31 ( L_3 ,
V_62 , V_64 , V_58 [ V_64 ] ) ;
return V_67 ;
}
return V_66 ;
}
struct V_68 * F_32 ( struct V_56 * V_57 , struct V_54 * V_69 )
{
struct V_68 * V_58 ;
if ( V_69 == NULL || V_57 -> V_65 == 0 || V_57 -> V_63 == 0 ||
F_33 ( V_69 ) != V_70 )
return NULL ;
for ( V_58 = V_71 ; V_58 ; V_58 = V_58 -> V_9 ) {
if ( ! memcmp ( & V_58 -> V_65 , V_57 , sizeof( struct V_56 ) ) &&
! memcmp ( & V_58 -> V_72 , F_34 ( V_69 ) , 1024 ) ) {
V_58 -> V_73 ++ ;
return V_58 ;
}
}
V_58 = F_35 ( sizeof( * V_58 ) , V_74 ) ;
if ( V_58 ) {
V_58 -> V_65 = * V_57 ;
V_58 -> V_73 = 1 ;
memcpy ( V_58 -> V_72 , F_34 ( V_69 ) , 1024 ) ;
if ( V_57 -> V_75 == V_76 )
V_57 -> V_75 = F_29 ( V_57 , V_58 -> V_72 ) ;
V_58 -> V_9 = V_71 ;
V_71 = V_58 ;
}
return V_58 ;
}
void F_36 ( struct V_68 * V_69 )
{
struct V_68 * V_58 , * * V_77 ;
if ( ! V_69 || -- V_69 -> V_73 )
return;
for ( V_77 = & V_71 ;
( V_58 = * V_77 ) != NULL ;
V_77 = & V_58 -> V_9 ) {
if ( V_58 == V_69 ) {
* V_77 = V_58 -> V_9 ;
F_37 ( V_58 ) ;
return;
}
}
}
static struct V_78 * F_38 ( struct V_54 * V_79 )
{
struct V_54 * V_80 [ V_81 + 1 ] ;
struct V_78 * V_82 ;
struct V_83 * V_84 ;
unsigned int V_85 = 0 ;
T_5 * V_69 = NULL ;
int V_28 ;
V_28 = F_39 ( V_80 , V_81 , V_79 , V_86 ) ;
if ( V_28 < 0 )
return F_40 ( V_28 ) ;
if ( ! V_80 [ V_87 ] )
return F_40 ( - V_27 ) ;
V_84 = F_34 ( V_80 [ V_87 ] ) ;
if ( V_84 -> V_85 > 0 ) {
if ( ! V_80 [ V_88 ] )
return F_40 ( - V_27 ) ;
V_69 = F_34 ( V_80 [ V_88 ] ) ;
V_85 = F_33 ( V_80 [ V_88 ] ) / sizeof( T_5 ) ;
}
if ( V_85 != V_84 -> V_85 || ( ! V_69 && V_85 > 0 ) )
return F_40 ( - V_27 ) ;
F_41 ( & V_89 ) ;
F_42 (stab, &qdisc_stab_list, list) {
if ( memcmp ( & V_82 -> V_90 , V_84 , sizeof( * V_84 ) ) )
continue;
if ( V_85 > 0 && memcmp ( V_82 -> V_72 , V_69 , V_85 * sizeof( T_5 ) ) )
continue;
V_82 -> V_73 ++ ;
F_43 ( & V_89 ) ;
return V_82 ;
}
F_43 ( & V_89 ) ;
V_82 = F_35 ( sizeof( * V_82 ) + V_85 * sizeof( T_5 ) , V_74 ) ;
if ( ! V_82 )
return F_40 ( - V_91 ) ;
V_82 -> V_73 = 1 ;
V_82 -> V_90 = * V_84 ;
if ( V_85 > 0 )
memcpy ( V_82 -> V_72 , V_69 , V_85 * sizeof( T_5 ) ) ;
F_41 ( & V_89 ) ;
F_44 ( & V_82 -> V_47 , & V_92 ) ;
F_43 ( & V_89 ) ;
return V_82 ;
}
static void F_45 ( struct V_93 * V_94 )
{
F_37 ( F_46 ( V_94 , struct V_78 , V_95 ) ) ;
}
void F_47 ( struct V_78 * V_69 )
{
if ( ! V_69 )
return;
F_41 ( & V_89 ) ;
if ( -- V_69 -> V_73 == 0 ) {
F_48 ( & V_69 -> V_47 ) ;
F_49 ( & V_69 -> V_95 , F_45 ) ;
}
F_43 ( & V_89 ) ;
}
static int F_50 ( struct V_96 * V_97 , struct V_78 * V_82 )
{
struct V_54 * V_98 ;
V_98 = F_51 ( V_97 , V_99 ) ;
if ( V_98 == NULL )
goto V_100;
if ( F_52 ( V_97 , V_87 , sizeof( V_82 -> V_90 ) , & V_82 -> V_90 ) )
goto V_100;
F_53 ( V_97 , V_98 ) ;
return V_97 -> V_31 ;
V_100:
return - 1 ;
}
void F_54 ( struct V_96 * V_97 , const struct V_78 * V_82 )
{
int V_101 , V_102 ;
V_101 = V_97 -> V_31 + V_82 -> V_90 . V_103 ;
if ( F_55 ( ! V_82 -> V_90 . V_85 ) )
goto V_11;
V_102 = V_101 + V_82 -> V_90 . V_104 ;
if ( F_55 ( V_102 < 0 ) )
V_102 = 0 ;
V_102 >>= V_82 -> V_90 . V_63 ;
if ( F_56 ( V_102 < V_82 -> V_90 . V_85 ) )
V_101 = V_82 -> V_72 [ V_102 ] ;
else
V_101 = V_82 -> V_72 [ V_82 -> V_90 . V_85 - 1 ] *
( V_102 / V_82 -> V_90 . V_85 ) +
V_82 -> V_72 [ V_102 % V_82 -> V_90 . V_85 ] ;
V_101 <<= V_82 -> V_90 . V_105 ;
V_11:
if ( F_55 ( V_101 < 1 ) )
V_101 = 1 ;
F_57 ( V_97 ) -> V_101 = V_101 ;
}
void F_58 ( const char * V_106 , struct V_37 * V_45 )
{
if ( ! ( V_45 -> V_40 & V_107 ) ) {
F_59 ( L_4 ,
V_106 , V_45 -> V_34 -> V_10 , V_45 -> V_39 >> 16 ) ;
V_45 -> V_40 |= V_107 ;
}
}
static enum V_108 F_60 ( struct V_109 * V_110 )
{
struct F_60 * V_111 = F_46 ( V_110 , struct F_60 ,
V_110 ) ;
F_61 () ;
F_62 ( V_111 -> V_45 ) ;
F_63 ( F_64 ( V_111 -> V_45 ) ) ;
F_65 () ;
return V_112 ;
}
void F_66 ( struct F_60 * V_111 , struct V_37 * V_45 )
{
F_67 ( & V_111 -> V_110 , V_113 , V_114 ) ;
V_111 -> V_110 . V_115 = F_60 ;
V_111 -> V_45 = V_45 ;
}
void F_68 ( struct F_60 * V_111 , T_6 V_116 , bool V_117 )
{
if ( F_69 ( V_118 ,
& F_70 ( V_111 -> V_45 ) -> V_119 ) )
return;
if ( V_117 )
F_71 ( V_111 -> V_45 ) ;
if ( V_111 -> V_120 == V_116 )
return;
V_111 -> V_120 = V_116 ;
F_72 ( & V_111 -> V_110 ,
F_73 ( V_116 ) ,
V_114 ) ;
}
void F_74 ( struct F_60 * V_111 )
{
F_75 ( & V_111 -> V_110 ) ;
F_62 ( V_111 -> V_45 ) ;
}
static struct V_121 * F_76 ( unsigned int V_122 )
{
unsigned int V_123 = V_122 * sizeof( struct V_121 ) , V_124 ;
struct V_121 * V_125 ;
if ( V_123 <= V_126 )
V_125 = F_35 ( V_123 , V_74 ) ;
else
V_125 = (struct V_121 * )
F_77 ( V_74 , F_78 ( V_123 ) ) ;
if ( V_125 != NULL ) {
for ( V_124 = 0 ; V_124 < V_122 ; V_124 ++ )
F_79 ( & V_125 [ V_124 ] ) ;
}
return V_125 ;
}
static void F_80 ( struct V_121 * V_125 , unsigned int V_122 )
{
unsigned int V_123 = V_122 * sizeof( struct V_121 ) ;
if ( V_123 <= V_126 )
F_37 ( V_125 ) ;
else
F_81 ( ( unsigned long ) V_125 , F_78 ( V_123 ) ) ;
}
void F_82 ( struct V_37 * V_127 , struct V_128 * V_129 )
{
struct V_130 * V_53 ;
struct V_131 * V_9 ;
struct V_121 * V_132 , * V_133 ;
unsigned int V_134 , V_135 , V_136 ;
unsigned int V_124 , V_125 ;
if ( V_129 -> V_137 * 4 <= V_129 -> V_138 * 3 )
return;
V_134 = V_129 -> V_138 * 2 ;
V_135 = V_134 - 1 ;
V_132 = F_76 ( V_134 ) ;
if ( V_132 == NULL )
return;
V_133 = V_129 -> V_139 ;
V_136 = V_129 -> V_138 ;
F_83 ( V_127 ) ;
for ( V_124 = 0 ; V_124 < V_136 ; V_124 ++ ) {
F_84 (cl, next, &ohash[i], hnode) {
V_125 = F_85 ( V_53 -> V_52 , V_135 ) ;
F_86 ( & V_53 -> V_140 , & V_132 [ V_125 ] ) ;
}
}
V_129 -> V_139 = V_132 ;
V_129 -> V_138 = V_134 ;
V_129 -> V_141 = V_135 ;
F_87 ( V_127 ) ;
F_80 ( V_133 , V_136 ) ;
}
int F_88 ( struct V_128 * V_129 )
{
unsigned int V_123 = 4 ;
V_129 -> V_139 = F_76 ( V_123 ) ;
if ( V_129 -> V_139 == NULL )
return - V_91 ;
V_129 -> V_138 = V_123 ;
V_129 -> V_141 = V_123 - 1 ;
V_129 -> V_137 = 0 ;
return 0 ;
}
void F_89 ( struct V_128 * V_129 )
{
F_80 ( V_129 -> V_139 , V_129 -> V_138 ) ;
}
void F_90 ( struct V_128 * V_129 ,
struct V_130 * V_53 )
{
unsigned int V_125 ;
F_91 ( & V_53 -> V_140 ) ;
V_125 = F_85 ( V_53 -> V_52 , V_129 -> V_141 ) ;
F_86 ( & V_53 -> V_140 , & V_129 -> V_139 [ V_125 ] ) ;
V_129 -> V_137 ++ ;
}
void F_92 ( struct V_128 * V_129 ,
struct V_130 * V_53 )
{
F_93 ( & V_53 -> V_140 ) ;
V_129 -> V_137 -- ;
}
static T_2 F_94 ( struct V_48 * V_49 )
{
int V_124 = 0x8000 ;
static T_2 V_142 = F_95 ( 0x80000000U , 0 ) ;
do {
V_142 += F_95 ( 0x10000U , 0 ) ;
if ( V_142 == F_95 ( V_43 , 0 ) )
V_142 = F_95 ( 0x80000000U , 0 ) ;
if ( ! F_24 ( V_49 , V_142 ) )
return V_142 ;
F_96 () ;
} while ( -- V_124 > 0 );
return 0 ;
}
void F_97 ( struct V_37 * V_127 , unsigned int V_122 ,
unsigned int V_31 )
{
const struct V_18 * V_19 ;
unsigned long V_53 ;
T_2 V_143 ;
int V_144 ;
if ( V_122 == 0 && V_31 == 0 )
return;
V_144 = F_98 ( int , V_122 , 0 ) ;
F_61 () ;
while ( ( V_143 = V_127 -> V_42 ) ) {
if ( F_99 ( V_143 ) == F_99 ( V_145 ) )
break;
if ( V_127 -> V_40 & V_146 )
break;
V_127 = F_24 ( F_18 ( V_127 ) , F_99 ( V_143 ) ) ;
if ( V_127 == NULL ) {
F_19 ( V_143 != V_43 ) ;
break;
}
V_19 = V_127 -> V_34 -> V_17 ;
if ( V_19 -> V_147 ) {
V_53 = V_19 -> V_20 ( V_127 , V_143 ) ;
V_19 -> V_147 ( V_127 , V_53 ) ;
V_19 -> V_21 ( V_127 , V_53 ) ;
}
V_127 -> V_3 . V_148 -= V_122 ;
V_127 -> V_149 . V_150 -= V_31 ;
F_100 ( V_127 , V_144 ) ;
}
F_65 () ;
}
static void F_101 ( struct V_151 * V_151 , struct V_96 * V_97 ,
struct V_152 * V_122 , T_2 V_153 ,
struct V_37 * V_154 , struct V_37 * V_155 )
{
if ( V_155 || V_154 )
F_102 ( V_151 , V_97 , V_122 , V_153 , V_154 , V_155 ) ;
if ( V_154 )
F_103 ( V_154 ) ;
}
static int F_104 ( struct V_48 * V_49 , struct V_37 * V_42 ,
struct V_96 * V_97 , struct V_152 * V_122 , T_2 V_52 ,
struct V_37 * V_155 , struct V_37 * V_154 )
{
struct V_37 * V_3 = V_154 ;
struct V_151 * V_151 = F_105 ( V_49 ) ;
int V_28 = 0 ;
if ( V_42 == NULL ) {
unsigned int V_124 , V_156 , V_157 ;
V_157 = 0 ;
V_156 = V_49 -> V_158 ;
if ( ( V_3 && V_3 -> V_40 & V_44 ) ||
( V_155 && V_155 -> V_40 & V_44 ) ) {
V_156 = 1 ;
V_157 = 1 ;
if ( ! F_25 ( V_49 ) )
return - V_29 ;
}
if ( V_49 -> V_40 & V_159 )
F_106 ( V_49 ) ;
if ( V_155 && V_155 -> V_34 -> V_160 )
goto V_161;
for ( V_124 = 0 ; V_124 < V_156 ; V_124 ++ ) {
struct V_162 * V_163 = F_25 ( V_49 ) ;
if ( ! V_157 )
V_163 = F_107 ( V_49 , V_124 ) ;
V_154 = F_108 ( V_163 , V_155 ) ;
if ( V_155 && V_124 > 0 )
F_109 ( & V_155 -> V_73 ) ;
if ( ! V_157 )
F_103 ( V_154 ) ;
}
V_161:
if ( ! V_157 ) {
F_101 ( V_151 , V_97 , V_122 , V_52 ,
V_49 -> V_45 , V_155 ) ;
if ( V_155 && ! V_155 -> V_34 -> V_160 )
F_109 ( & V_155 -> V_73 ) ;
V_49 -> V_45 = V_155 ? : & V_46 ;
if ( V_155 && V_155 -> V_34 -> V_160 )
V_155 -> V_34 -> V_160 ( V_155 ) ;
} else {
F_101 ( V_151 , V_97 , V_122 , V_52 , V_154 , V_155 ) ;
}
if ( V_49 -> V_40 & V_159 )
F_110 ( V_49 ) ;
} else {
const struct V_18 * V_19 = V_42 -> V_34 -> V_17 ;
V_28 = - V_164 ;
if ( V_19 && V_19 -> V_165 ) {
unsigned long V_53 = V_19 -> V_20 ( V_42 , V_52 ) ;
if ( V_53 ) {
V_28 = V_19 -> V_165 ( V_42 , V_53 , V_155 , & V_154 ) ;
V_19 -> V_21 ( V_42 , V_53 ) ;
} else
V_28 = - V_29 ;
}
if ( ! V_28 )
F_101 ( V_151 , V_97 , V_122 , V_52 , V_154 , V_155 ) ;
}
return V_28 ;
}
static struct V_37 *
F_111 ( struct V_48 * V_49 , struct V_162 * V_163 ,
struct V_37 * V_51 , T_2 V_42 , T_2 V_39 ,
struct V_54 * * V_166 , int * V_167 )
{
int V_28 ;
struct V_54 * V_55 = V_166 [ V_168 ] ;
struct V_37 * V_127 ;
struct V_1 * V_34 ;
struct V_78 * V_82 ;
V_34 = F_27 ( V_55 ) ;
#ifdef F_112
if ( V_34 == NULL && V_55 != NULL ) {
char V_30 [ V_169 ] ;
if ( F_113 ( V_30 , V_55 , V_169 ) < V_169 ) {
F_114 () ;
F_13 ( L_1 , V_30 ) ;
F_115 () ;
V_34 = F_27 ( V_55 ) ;
if ( V_34 != NULL ) {
F_14 ( V_34 -> V_33 ) ;
V_28 = - V_170 ;
goto V_171;
}
}
}
#endif
V_28 = - V_29 ;
if ( V_34 == NULL )
goto V_171;
V_127 = F_116 ( V_163 , V_34 ) ;
if ( F_117 ( V_127 ) ) {
V_28 = F_118 ( V_127 ) ;
goto V_172;
}
V_127 -> V_42 = V_42 ;
if ( V_39 == V_145 ) {
V_127 -> V_40 |= V_44 ;
V_39 = F_95 ( V_145 , 0 ) ;
F_119 ( F_120 ( V_127 ) , & V_173 ) ;
} else {
if ( V_39 == 0 ) {
V_39 = F_94 ( V_49 ) ;
V_28 = - V_91 ;
if ( V_39 == 0 )
goto V_174;
}
F_119 ( F_120 ( V_127 ) , & V_175 ) ;
if ( ! F_121 ( V_49 ) )
V_127 -> V_40 |= V_176 ;
}
V_127 -> V_39 = V_39 ;
if ( ! V_34 -> V_177 || ( V_28 = V_34 -> V_177 ( V_127 , V_166 [ V_178 ] ) ) == 0 ) {
if ( F_122 ( V_127 ) ) {
V_127 -> V_179 =
F_123 ( struct V_180 ) ;
if ( ! V_127 -> V_179 )
goto V_181;
V_127 -> V_182 = F_124 ( struct V_183 ) ;
if ( ! V_127 -> V_182 )
goto V_181;
}
if ( V_166 [ V_99 ] ) {
V_82 = F_38 ( V_166 [ V_99 ] ) ;
if ( F_117 ( V_82 ) ) {
V_28 = F_118 ( V_82 ) ;
goto V_181;
}
F_125 ( V_127 -> V_82 , V_82 ) ;
}
if ( V_166 [ V_184 ] ) {
T_7 * V_185 ;
V_28 = - V_164 ;
if ( V_127 -> V_40 & V_186 )
goto V_181;
if ( ( V_127 -> V_42 != V_43 ) &&
! ( V_127 -> V_40 & V_44 ) &&
( ! V_51 || ! ( V_51 -> V_40 & V_186 ) ) )
V_185 = F_126 ( V_127 ) ;
else
V_185 = F_120 ( V_127 ) ;
V_28 = F_127 ( & V_127 -> V_187 ,
V_127 -> V_179 ,
& V_127 -> V_188 ,
V_185 ,
V_166 [ V_184 ] ) ;
if ( V_28 )
goto V_181;
}
F_17 ( V_127 ) ;
return V_127 ;
}
V_174:
F_128 ( V_49 ) ;
F_37 ( ( char * ) V_127 - V_127 -> V_189 ) ;
V_172:
F_14 ( V_34 -> V_33 ) ;
V_171:
* V_167 = V_28 ;
return NULL ;
V_181:
F_129 ( V_127 -> V_179 ) ;
F_129 ( V_127 -> V_182 ) ;
F_47 ( F_130 ( V_127 -> V_82 ) ) ;
if ( V_34 -> V_190 )
V_34 -> V_190 ( V_127 ) ;
goto V_174;
}
static int F_131 ( struct V_37 * V_127 , struct V_54 * * V_166 )
{
struct V_78 * V_191 , * V_82 = NULL ;
int V_28 = 0 ;
if ( V_166 [ V_178 ] ) {
if ( V_127 -> V_34 -> V_192 == NULL )
return - V_27 ;
V_28 = V_127 -> V_34 -> V_192 ( V_127 , V_166 [ V_178 ] ) ;
if ( V_28 )
return V_28 ;
}
if ( V_166 [ V_99 ] ) {
V_82 = F_38 ( V_166 [ V_99 ] ) ;
if ( F_117 ( V_82 ) )
return F_118 ( V_82 ) ;
}
V_191 = F_130 ( V_127 -> V_82 ) ;
F_125 ( V_127 -> V_82 , V_82 ) ;
F_47 ( V_191 ) ;
if ( V_166 [ V_184 ] ) {
if ( V_127 -> V_40 & V_186 )
goto V_11;
F_132 ( & V_127 -> V_187 ,
V_127 -> V_179 ,
& V_127 -> V_188 ,
F_126 ( V_127 ) ,
V_166 [ V_184 ] ) ;
}
V_11:
return 0 ;
}
static int F_133 ( struct V_37 * V_3 , struct V_37 * V_51 , int V_193 )
{
struct V_194 V_195 ;
if ( V_3 -> V_34 -> V_17 == NULL )
return 0 ;
V_195 . V_196 . V_197 = V_195 . V_196 . V_161 = V_195 . V_196 . V_198 = 0 ;
V_195 . V_196 . V_199 = V_200 ;
V_195 . V_193 = V_193 ;
V_195 . V_51 = V_51 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_195 . V_196 ) ;
return V_195 . V_196 . V_197 ? - V_201 : 0 ;
}
static int
V_200 ( struct V_37 * V_3 , unsigned long V_53 , struct V_202 * V_196 )
{
struct V_37 * V_23 ;
const struct V_18 * V_19 = V_3 -> V_34 -> V_17 ;
struct V_194 * V_195 = (struct V_194 * ) V_196 ;
V_23 = V_19 -> V_23 ( V_3 , V_53 ) ;
if ( V_23 ) {
if ( V_23 == V_195 -> V_51 || V_195 -> V_193 > 7 )
return - V_201 ;
return F_133 ( V_23 , V_195 -> V_51 , V_195 -> V_193 + 1 ) ;
}
return 0 ;
}
static int F_134 ( struct V_96 * V_97 , struct V_152 * V_122 )
{
struct V_151 * V_151 = F_135 ( V_97 -> V_203 ) ;
struct V_204 * V_205 = F_136 ( V_122 ) ;
struct V_54 * V_166 [ V_206 + 1 ] ;
struct V_48 * V_49 ;
T_2 V_153 ;
struct V_37 * V_3 = NULL ;
struct V_37 * V_51 = NULL ;
int V_28 ;
if ( ( V_122 -> V_207 != V_208 ) &&
! F_137 ( V_97 , V_151 -> V_209 , V_35 ) )
return - V_36 ;
V_28 = F_138 ( V_122 , sizeof( * V_205 ) , V_166 , V_206 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_49 = F_139 ( V_151 , V_205 -> V_210 ) ;
if ( ! V_49 )
return - V_211 ;
V_153 = V_205 -> V_212 ;
if ( V_153 ) {
if ( V_153 != V_43 ) {
if ( F_99 ( V_153 ) != F_99 ( V_145 ) ) {
V_51 = F_24 ( V_49 , F_99 ( V_153 ) ) ;
if ( ! V_51 )
return - V_29 ;
V_3 = F_26 ( V_51 , V_153 ) ;
} else if ( F_25 ( V_49 ) ) {
V_3 = F_25 ( V_49 ) -> V_50 ;
}
} else {
V_3 = V_49 -> V_45 ;
}
if ( ! V_3 )
return - V_29 ;
if ( V_205 -> V_213 && V_3 -> V_39 != V_205 -> V_213 )
return - V_27 ;
} else {
V_3 = F_24 ( V_49 , V_205 -> V_213 ) ;
if ( ! V_3 )
return - V_29 ;
}
if ( V_166 [ V_168 ] && F_28 ( V_166 [ V_168 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_122 -> V_207 == V_214 ) {
if ( ! V_153 )
return - V_27 ;
if ( V_3 -> V_39 == 0 )
return - V_29 ;
V_28 = F_104 ( V_49 , V_51 , V_97 , V_122 , V_153 , NULL , V_3 ) ;
if ( V_28 != 0 )
return V_28 ;
} else {
F_102 ( V_151 , V_97 , V_122 , V_153 , NULL , V_3 ) ;
}
return 0 ;
}
static int F_140 ( struct V_96 * V_97 , struct V_152 * V_122 )
{
struct V_151 * V_151 = F_135 ( V_97 -> V_203 ) ;
struct V_204 * V_205 ;
struct V_54 * V_166 [ V_206 + 1 ] ;
struct V_48 * V_49 ;
T_2 V_153 ;
struct V_37 * V_3 , * V_51 ;
int V_28 ;
if ( ! F_137 ( V_97 , V_151 -> V_209 , V_35 ) )
return - V_36 ;
V_215:
V_28 = F_138 ( V_122 , sizeof( * V_205 ) , V_166 , V_206 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_205 = F_136 ( V_122 ) ;
V_153 = V_205 -> V_212 ;
V_3 = V_51 = NULL ;
V_49 = F_139 ( V_151 , V_205 -> V_210 ) ;
if ( ! V_49 )
return - V_211 ;
if ( V_153 ) {
if ( V_153 != V_43 ) {
if ( V_153 != V_145 ) {
V_51 = F_24 ( V_49 , F_99 ( V_153 ) ) ;
if ( ! V_51 )
return - V_29 ;
V_3 = F_26 ( V_51 , V_153 ) ;
} else if ( F_141 ( V_49 ) ) {
V_3 = F_25 ( V_49 ) -> V_50 ;
}
} else {
V_3 = V_49 -> V_45 ;
}
if ( V_3 && V_3 -> V_39 == 0 )
V_3 = NULL ;
if ( ! V_3 || ! V_205 -> V_213 || V_3 -> V_39 != V_205 -> V_213 ) {
if ( V_205 -> V_213 ) {
if ( V_3 && ! ( V_122 -> V_216 & V_217 ) )
return - V_6 ;
if ( F_142 ( V_205 -> V_213 ) )
return - V_27 ;
V_3 = F_24 ( V_49 , V_205 -> V_213 ) ;
if ( ! V_3 )
goto V_218;
if ( V_122 -> V_216 & V_219 )
return - V_6 ;
if ( V_166 [ V_168 ] && F_28 ( V_166 [ V_168 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_3 == V_51 ||
( V_51 && F_133 ( V_3 , V_51 , 0 ) ) )
return - V_201 ;
F_109 ( & V_3 -> V_73 ) ;
goto V_165;
} else {
if ( ! V_3 )
goto V_218;
if ( ( V_122 -> V_216 & V_220 ) &&
( V_122 -> V_216 & V_217 ) &&
( ( V_122 -> V_216 & V_219 ) ||
( V_166 [ V_168 ] &&
F_28 ( V_166 [ V_168 ] , V_3 -> V_34 -> V_10 ) ) ) )
goto V_218;
}
}
} else {
if ( ! V_205 -> V_213 )
return - V_27 ;
V_3 = F_24 ( V_49 , V_205 -> V_213 ) ;
}
if ( V_3 == NULL )
return - V_29 ;
if ( V_122 -> V_216 & V_219 )
return - V_6 ;
if ( V_166 [ V_168 ] && F_28 ( V_166 [ V_168 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
V_28 = F_131 ( V_3 , V_166 ) ;
if ( V_28 == 0 )
F_102 ( V_151 , V_97 , V_122 , V_153 , NULL , V_3 ) ;
return V_28 ;
V_218:
if ( ! ( V_122 -> V_216 & V_220 ) )
return - V_29 ;
if ( V_153 == V_145 ) {
if ( F_25 ( V_49 ) )
V_3 = F_111 ( V_49 , F_25 ( V_49 ) , V_51 ,
V_205 -> V_212 , V_205 -> V_212 ,
V_166 , & V_28 ) ;
else
V_28 = - V_29 ;
} else {
struct V_162 * V_163 ;
if ( V_51 && V_51 -> V_34 -> V_17 && V_51 -> V_34 -> V_17 -> V_221 )
V_163 = V_51 -> V_34 -> V_17 -> V_221 ( V_51 , V_205 ) ;
else if ( V_51 )
V_163 = V_51 -> V_163 ;
else
V_163 = F_107 ( V_49 , 0 ) ;
V_3 = F_111 ( V_49 , V_163 , V_51 ,
V_205 -> V_212 , V_205 -> V_213 ,
V_166 , & V_28 ) ;
}
if ( V_3 == NULL ) {
if ( V_28 == - V_170 )
goto V_215;
return V_28 ;
}
V_165:
V_28 = F_104 ( V_49 , V_51 , V_97 , V_122 , V_153 , V_3 , NULL ) ;
if ( V_28 ) {
if ( V_3 )
F_103 ( V_3 ) ;
return V_28 ;
}
return 0 ;
}
static int F_143 ( struct V_96 * V_97 , struct V_37 * V_3 , T_2 V_153 ,
T_2 V_222 , T_2 V_223 , T_5 V_40 , int V_224 )
{
struct V_180 T_8 * V_179 = NULL ;
struct V_183 T_8 * V_182 = NULL ;
struct V_204 * V_205 ;
struct V_152 * V_225 ;
unsigned char * V_226 = F_144 ( V_97 ) ;
struct V_227 V_228 ;
struct V_78 * V_82 ;
T_4 V_148 ;
F_96 () ;
V_225 = F_145 ( V_97 , V_222 , V_223 , V_224 , sizeof( * V_205 ) , V_40 ) ;
if ( ! V_225 )
goto V_229;
V_205 = F_136 ( V_225 ) ;
V_205 -> V_230 = V_231 ;
V_205 -> V_232 = 0 ;
V_205 -> V_233 = 0 ;
V_205 -> V_210 = F_18 ( V_3 ) -> V_234 ;
V_205 -> V_212 = V_153 ;
V_205 -> V_213 = V_3 -> V_39 ;
V_205 -> V_235 = F_146 ( & V_3 -> V_73 ) ;
if ( F_147 ( V_97 , V_168 , V_3 -> V_34 -> V_10 ) )
goto V_100;
if ( V_3 -> V_34 -> V_236 && V_3 -> V_34 -> V_236 ( V_3 , V_97 ) < 0 )
goto V_100;
V_148 = V_3 -> V_3 . V_148 ;
V_82 = F_130 ( V_3 -> V_82 ) ;
if ( V_82 && F_50 ( V_97 , V_82 ) < 0 )
goto V_100;
if ( F_148 ( V_97 , V_237 , V_238 , V_239 ,
F_126 ( V_3 ) , & V_228 ,
V_240 ) < 0 )
goto V_100;
if ( V_3 -> V_34 -> V_241 && V_3 -> V_34 -> V_241 ( V_3 , & V_228 ) < 0 )
goto V_100;
if ( F_122 ( V_3 ) ) {
V_179 = V_3 -> V_179 ;
V_182 = V_3 -> V_182 ;
}
if ( F_149 ( & V_228 , V_179 , & V_3 -> V_187 ) < 0 ||
F_150 ( & V_228 , & V_3 -> V_187 , & V_3 -> V_188 ) < 0 ||
F_151 ( & V_228 , V_182 , & V_3 -> V_149 , V_148 ) < 0 )
goto V_100;
if ( F_152 ( & V_228 ) < 0 )
goto V_100;
V_225 -> V_242 = F_144 ( V_97 ) - V_226 ;
return V_97 -> V_31 ;
V_229:
V_100:
F_153 ( V_97 , V_226 ) ;
return - 1 ;
}
static bool F_154 ( struct V_37 * V_3 )
{
return ( V_3 -> V_40 & V_41 ) ? true : false ;
}
static int F_102 ( struct V_151 * V_151 , struct V_96 * V_243 ,
struct V_152 * V_122 , T_2 V_153 ,
struct V_37 * V_154 , struct V_37 * V_155 )
{
struct V_96 * V_97 ;
T_2 V_222 = V_243 ? F_155 ( V_243 ) . V_222 : 0 ;
V_97 = F_156 ( V_244 , V_74 ) ;
if ( ! V_97 )
return - V_245 ;
if ( V_154 && ! F_154 ( V_154 ) ) {
if ( F_143 ( V_97 , V_154 , V_153 , V_222 , V_122 -> V_246 ,
0 , V_214 ) < 0 )
goto V_171;
}
if ( V_155 && ! F_154 ( V_155 ) ) {
if ( F_143 ( V_97 , V_155 , V_153 , V_222 , V_122 -> V_246 ,
V_154 ? V_217 : 0 , V_247 ) < 0 )
goto V_171;
}
if ( V_97 -> V_31 )
return F_157 ( V_97 , V_151 , V_222 , V_248 ,
V_122 -> V_216 & V_249 ) ;
V_171:
F_158 ( V_97 ) ;
return - V_27 ;
}
static int F_159 ( struct V_37 * V_38 , struct V_96 * V_97 ,
struct V_250 * V_251 ,
int * V_252 , int V_253 )
{
int V_254 = 0 , V_255 = * V_252 ;
struct V_37 * V_3 ;
if ( ! V_38 )
return 0 ;
V_3 = V_38 ;
if ( V_255 < V_253 ) {
V_255 ++ ;
} else {
if ( ! F_154 ( V_3 ) &&
F_143 ( V_97 , V_3 , V_3 -> V_42 , F_155 ( V_251 -> V_97 ) . V_222 ,
V_251 -> V_225 -> V_246 , V_256 , V_247 ) <= 0 )
goto V_257;
V_255 ++ ;
}
F_42 (q, &root->list, list) {
if ( V_255 < V_253 ) {
V_255 ++ ;
continue;
}
if ( ! F_154 ( V_3 ) &&
F_143 ( V_97 , V_3 , V_3 -> V_42 , F_155 ( V_251 -> V_97 ) . V_222 ,
V_251 -> V_225 -> V_246 , V_256 , V_247 ) <= 0 )
goto V_257;
V_255 ++ ;
}
V_11:
* V_252 = V_255 ;
return V_254 ;
V_257:
V_254 = - 1 ;
goto V_11;
}
static int F_160 ( struct V_96 * V_97 , struct V_250 * V_251 )
{
struct V_151 * V_151 = F_135 ( V_97 -> V_203 ) ;
int V_258 , V_255 ;
int V_259 , V_253 ;
struct V_48 * V_49 ;
V_259 = V_251 -> args [ 0 ] ;
V_253 = V_255 = V_251 -> args [ 1 ] ;
V_258 = 0 ;
F_20 () ;
F_161 (net, dev) {
struct V_162 * V_163 ;
if ( V_258 < V_259 )
goto V_260;
if ( V_258 > V_259 )
V_253 = 0 ;
V_255 = 0 ;
if ( F_159 ( V_49 -> V_45 , V_97 , V_251 , & V_255 , V_253 ) < 0 )
goto V_257;
V_163 = F_25 ( V_49 ) ;
if ( V_163 &&
F_159 ( V_163 -> V_50 , V_97 , V_251 ,
& V_255 , V_253 ) < 0 )
goto V_257;
V_260:
V_258 ++ ;
}
V_257:
V_251 -> args [ 0 ] = V_258 ;
V_251 -> args [ 1 ] = V_255 ;
return V_97 -> V_31 ;
}
static int F_162 ( struct V_96 * V_97 , struct V_152 * V_122 )
{
struct V_151 * V_151 = F_135 ( V_97 -> V_203 ) ;
struct V_204 * V_205 = F_136 ( V_122 ) ;
struct V_54 * V_166 [ V_206 + 1 ] ;
struct V_48 * V_49 ;
struct V_37 * V_3 = NULL ;
const struct V_18 * V_19 ;
unsigned long V_53 = 0 ;
unsigned long V_261 ;
T_2 V_222 ;
T_2 V_153 ;
T_2 V_262 ;
int V_28 ;
if ( ( V_122 -> V_207 != V_263 ) &&
! F_137 ( V_97 , V_151 -> V_209 , V_35 ) )
return - V_36 ;
V_28 = F_138 ( V_122 , sizeof( * V_205 ) , V_166 , V_206 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_49 = F_139 ( V_151 , V_205 -> V_210 ) ;
if ( ! V_49 )
return - V_211 ;
V_222 = V_205 -> V_212 ;
V_153 = V_205 -> V_213 ;
V_262 = F_99 ( V_153 ) ;
if ( V_222 != V_43 ) {
T_2 V_264 = F_99 ( V_222 ) ;
if ( V_262 && V_264 ) {
if ( V_262 != V_264 )
return - V_27 ;
} else if ( V_264 ) {
V_262 = V_264 ;
} else if ( V_262 == 0 )
V_262 = V_49 -> V_45 -> V_39 ;
if ( V_222 )
V_222 = F_95 ( V_262 , V_222 ) ;
} else {
if ( V_262 == 0 )
V_262 = V_49 -> V_45 -> V_39 ;
}
V_3 = F_24 ( V_49 , V_262 ) ;
if ( ! V_3 )
return - V_29 ;
V_19 = V_3 -> V_34 -> V_17 ;
if ( V_19 == NULL )
return - V_27 ;
if ( V_153 == 0 ) {
if ( V_222 == V_43 )
V_153 = V_262 ;
} else
V_153 = F_95 ( V_262 , V_153 ) ;
if ( V_153 )
V_53 = V_19 -> V_20 ( V_3 , V_153 ) ;
if ( V_53 == 0 ) {
V_28 = - V_29 ;
if ( V_122 -> V_207 != V_265 ||
! ( V_122 -> V_216 & V_220 ) )
goto V_11;
} else {
switch ( V_122 -> V_207 ) {
case V_265 :
V_28 = - V_6 ;
if ( V_122 -> V_216 & V_219 )
goto V_11;
break;
case V_266 :
V_28 = - V_164 ;
if ( V_19 -> V_267 )
V_28 = V_19 -> V_267 ( V_3 , V_53 ) ;
if ( V_28 == 0 )
F_163 ( V_151 , V_97 , V_122 , V_3 , V_53 , V_266 ) ;
goto V_11;
case V_263 :
V_28 = F_163 ( V_151 , V_97 , V_122 , V_3 , V_53 , V_265 ) ;
goto V_11;
default:
V_28 = - V_27 ;
goto V_11;
}
}
V_261 = V_53 ;
V_28 = - V_164 ;
if ( V_19 -> V_192 )
V_28 = V_19 -> V_192 ( V_3 , V_153 , V_222 , V_166 , & V_261 ) ;
if ( V_28 == 0 )
F_163 ( V_151 , V_97 , V_122 , V_3 , V_261 , V_265 ) ;
V_11:
if ( V_53 )
V_19 -> V_21 ( V_3 , V_53 ) ;
return V_28 ;
}
static int F_164 ( struct V_96 * V_97 , struct V_37 * V_3 ,
unsigned long V_53 ,
T_2 V_222 , T_2 V_223 , T_5 V_40 , int V_224 )
{
struct V_204 * V_205 ;
struct V_152 * V_225 ;
unsigned char * V_226 = F_144 ( V_97 ) ;
struct V_227 V_228 ;
const struct V_18 * V_17 = V_3 -> V_34 -> V_17 ;
F_96 () ;
V_225 = F_145 ( V_97 , V_222 , V_223 , V_224 , sizeof( * V_205 ) , V_40 ) ;
if ( ! V_225 )
goto V_229;
V_205 = F_136 ( V_225 ) ;
V_205 -> V_230 = V_231 ;
V_205 -> V_232 = 0 ;
V_205 -> V_233 = 0 ;
V_205 -> V_210 = F_18 ( V_3 ) -> V_234 ;
V_205 -> V_212 = V_3 -> V_39 ;
V_205 -> V_213 = V_3 -> V_39 ;
V_205 -> V_235 = 0 ;
if ( F_147 ( V_97 , V_168 , V_3 -> V_34 -> V_10 ) )
goto V_100;
if ( V_17 -> V_236 && V_17 -> V_236 ( V_3 , V_53 , V_97 , V_205 ) < 0 )
goto V_100;
if ( F_148 ( V_97 , V_237 , V_238 , V_239 ,
F_126 ( V_3 ) , & V_228 ,
V_240 ) < 0 )
goto V_100;
if ( V_17 -> V_241 && V_17 -> V_241 ( V_3 , V_53 , & V_228 ) < 0 )
goto V_100;
if ( F_152 ( & V_228 ) < 0 )
goto V_100;
V_225 -> V_242 = F_144 ( V_97 ) - V_226 ;
return V_97 -> V_31 ;
V_229:
V_100:
F_153 ( V_97 , V_226 ) ;
return - 1 ;
}
static int F_163 ( struct V_151 * V_151 , struct V_96 * V_243 ,
struct V_152 * V_122 , struct V_37 * V_3 ,
unsigned long V_53 , int V_224 )
{
struct V_96 * V_97 ;
T_2 V_222 = V_243 ? F_155 ( V_243 ) . V_222 : 0 ;
V_97 = F_156 ( V_244 , V_74 ) ;
if ( ! V_97 )
return - V_245 ;
if ( F_164 ( V_97 , V_3 , V_53 , V_222 , V_122 -> V_246 , 0 , V_224 ) < 0 ) {
F_158 ( V_97 ) ;
return - V_27 ;
}
return F_157 ( V_97 , V_151 , V_222 , V_248 ,
V_122 -> V_216 & V_249 ) ;
}
static int F_165 ( struct V_37 * V_3 , unsigned long V_53 , struct V_202 * V_195 )
{
struct V_268 * V_269 = (struct V_268 * ) V_195 ;
return F_164 ( V_269 -> V_97 , V_3 , V_53 , F_155 ( V_269 -> V_251 -> V_97 ) . V_222 ,
V_269 -> V_251 -> V_225 -> V_246 , V_256 , V_265 ) ;
}
static int F_166 ( struct V_37 * V_3 , struct V_96 * V_97 ,
struct V_204 * V_205 , struct V_250 * V_251 ,
int * V_270 , int V_271 )
{
struct V_268 V_195 ;
if ( F_154 ( V_3 ) ||
* V_270 < V_271 || ! V_3 -> V_34 -> V_17 ||
( V_205 -> V_212 &&
F_99 ( V_205 -> V_212 ) != V_3 -> V_39 ) ) {
( * V_270 ) ++ ;
return 0 ;
}
if ( * V_270 > V_271 )
memset ( & V_251 -> args [ 1 ] , 0 , sizeof( V_251 -> args ) - sizeof( V_251 -> args [ 0 ] ) ) ;
V_195 . V_196 . V_199 = F_165 ;
V_195 . V_97 = V_97 ;
V_195 . V_251 = V_251 ;
V_195 . V_196 . V_197 = 0 ;
V_195 . V_196 . V_161 = V_251 -> args [ 1 ] ;
V_195 . V_196 . V_198 = 0 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_195 . V_196 ) ;
V_251 -> args [ 1 ] = V_195 . V_196 . V_198 ;
if ( V_195 . V_196 . V_197 )
return - 1 ;
( * V_270 ) ++ ;
return 0 ;
}
static int F_167 ( struct V_37 * V_38 , struct V_96 * V_97 ,
struct V_204 * V_205 , struct V_250 * V_251 ,
int * V_270 , int V_271 )
{
struct V_37 * V_3 ;
if ( ! V_38 )
return 0 ;
if ( F_166 ( V_38 , V_97 , V_205 , V_251 , V_270 , V_271 ) < 0 )
return - 1 ;
F_42 (q, &root->list, list) {
if ( F_166 ( V_3 , V_97 , V_205 , V_251 , V_270 , V_271 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_168 ( struct V_96 * V_97 , struct V_250 * V_251 )
{
struct V_204 * V_205 = F_136 ( V_251 -> V_225 ) ;
struct V_151 * V_151 = F_135 ( V_97 -> V_203 ) ;
struct V_162 * V_163 ;
struct V_48 * V_49 ;
int V_272 , V_271 ;
if ( V_242 ( V_251 -> V_225 ) < sizeof( * V_205 ) )
return 0 ;
V_49 = F_169 ( V_151 , V_205 -> V_210 ) ;
if ( ! V_49 )
return 0 ;
V_271 = V_251 -> args [ 0 ] ;
V_272 = 0 ;
if ( F_167 ( V_49 -> V_45 , V_97 , V_205 , V_251 , & V_272 , V_271 ) < 0 )
goto V_257;
V_163 = F_25 ( V_49 ) ;
if ( V_163 &&
F_167 ( V_163 -> V_50 , V_97 , V_205 , V_251 ,
& V_272 , V_271 ) < 0 )
goto V_257;
V_257:
V_251 -> args [ 0 ] = V_272 ;
F_128 ( V_49 ) ;
return V_97 -> V_31 ;
}
int F_170 ( struct V_96 * V_97 , const struct V_273 * V_274 ,
struct V_275 * V_276 , bool V_277 )
{
T_9 V_278 = F_171 ( V_97 ) ;
#ifdef F_172
const struct V_273 * V_279 = V_274 ;
int V_280 = 0 ;
V_281:
#endif
for (; V_274 ; V_274 = F_173 ( V_274 -> V_9 ) ) {
int V_28 ;
if ( V_274 -> V_278 != V_278 &&
V_274 -> V_278 != F_174 ( V_282 ) )
continue;
V_28 = V_274 -> V_283 ( V_97 , V_274 , V_276 ) ;
#ifdef F_172
if ( F_55 ( V_28 == V_284 && ! V_277 ) )
goto V_285;
#endif
if ( V_28 >= 0 )
return V_28 ;
}
return V_286 ;
#ifdef F_172
V_285:
if ( F_55 ( V_280 ++ >= V_287 ) ) {
F_175 ( L_5 ,
V_274 -> V_3 -> V_34 -> V_10 , V_274 -> V_288 & 0xffff ,
F_176 ( V_274 -> V_278 ) ) ;
return V_289 ;
}
V_274 = V_279 ;
V_278 = F_171 ( V_97 ) ;
goto V_281;
#endif
}
bool F_177 ( struct V_273 * V_274 , bool V_290 )
{
if ( V_274 -> V_34 -> V_190 ( V_274 , V_290 ) ) {
F_14 ( V_274 -> V_34 -> V_33 ) ;
F_178 ( V_274 , V_95 ) ;
return true ;
}
return false ;
}
void F_179 ( struct V_273 T_10 * * V_291 )
{
struct V_273 * V_274 ;
while ( ( V_274 = F_130 ( * V_291 ) ) != NULL ) {
F_180 ( * V_291 , V_274 -> V_9 ) ;
F_177 ( V_274 , true ) ;
}
}
static int F_181 ( struct V_292 * V_223 , void * V_293 )
{
F_182 ( V_223 , L_6 ,
( T_2 ) V_294 , ( T_2 ) F_183 ( 1 ) ,
1000000 ,
( T_2 ) V_295 / V_296 ) ;
return 0 ;
}
static int F_184 ( struct V_297 * V_297 , struct V_298 * V_298 )
{
return F_185 ( V_298 , F_181 , NULL ) ;
}
static int T_11 F_186 ( struct V_151 * V_151 )
{
struct V_299 * V_300 ;
V_300 = F_187 ( L_7 , 0 , V_151 -> V_301 , & V_302 ) ;
if ( V_300 == NULL )
return - V_91 ;
return 0 ;
}
static void T_12 F_188 ( struct V_151 * V_151 )
{
F_189 ( L_7 , V_151 -> V_301 ) ;
}
static int T_11 F_186 ( struct V_151 * V_151 )
{
return 0 ;
}
static void T_12 F_188 ( struct V_151 * V_151 )
{
}
static int T_13 F_190 ( void )
{
int V_28 ;
V_28 = F_191 ( & V_303 ) ;
if ( V_28 ) {
F_192 ( L_8
L_9 ) ;
return V_28 ;
}
F_1 ( & V_304 ) ;
F_1 ( & V_305 ) ;
F_1 ( & V_306 ) ;
F_1 ( & V_307 ) ;
F_1 ( & V_308 ) ;
F_1 ( & V_309 ) ;
F_193 ( V_310 , V_247 , F_140 , NULL , NULL ) ;
F_193 ( V_310 , V_214 , F_134 , NULL , NULL ) ;
F_193 ( V_310 , V_208 , F_134 , F_160 , NULL ) ;
F_193 ( V_310 , V_265 , F_162 , NULL , NULL ) ;
F_193 ( V_310 , V_266 , F_162 , NULL , NULL ) ;
F_193 ( V_310 , V_263 , F_162 , F_168 , NULL ) ;
return 0 ;
}
