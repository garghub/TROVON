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
F_62 ( F_63 ( V_111 -> V_45 ) ) ;
F_64 () ;
return V_112 ;
}
void F_65 ( struct F_60 * V_111 , struct V_37 * V_45 )
{
F_66 ( & V_111 -> V_110 , V_113 , V_114 ) ;
V_111 -> V_110 . V_115 = F_60 ;
V_111 -> V_45 = V_45 ;
}
void F_67 ( struct F_60 * V_111 , T_6 V_116 )
{
if ( F_68 ( V_117 ,
& F_69 ( V_111 -> V_45 ) -> V_118 ) )
return;
if ( V_111 -> V_119 == V_116 )
return;
V_111 -> V_119 = V_116 ;
F_70 ( & V_111 -> V_110 ,
F_71 ( V_116 ) ,
V_114 ) ;
}
void F_72 ( struct F_60 * V_111 )
{
F_73 ( & V_111 -> V_110 ) ;
}
static struct V_120 * F_74 ( unsigned int V_121 )
{
unsigned int V_122 = V_121 * sizeof( struct V_120 ) , V_123 ;
struct V_120 * V_124 ;
if ( V_122 <= V_125 )
V_124 = F_35 ( V_122 , V_74 ) ;
else
V_124 = (struct V_120 * )
F_75 ( V_74 , F_76 ( V_122 ) ) ;
if ( V_124 != NULL ) {
for ( V_123 = 0 ; V_123 < V_121 ; V_123 ++ )
F_77 ( & V_124 [ V_123 ] ) ;
}
return V_124 ;
}
static void F_78 ( struct V_120 * V_124 , unsigned int V_121 )
{
unsigned int V_122 = V_121 * sizeof( struct V_120 ) ;
if ( V_122 <= V_125 )
F_37 ( V_124 ) ;
else
F_79 ( ( unsigned long ) V_124 , F_76 ( V_122 ) ) ;
}
void F_80 ( struct V_37 * V_126 , struct V_127 * V_128 )
{
struct V_129 * V_53 ;
struct V_130 * V_9 ;
struct V_120 * V_131 , * V_132 ;
unsigned int V_133 , V_134 , V_135 ;
unsigned int V_123 , V_124 ;
if ( V_128 -> V_136 * 4 <= V_128 -> V_137 * 3 )
return;
V_133 = V_128 -> V_137 * 2 ;
V_134 = V_133 - 1 ;
V_131 = F_74 ( V_133 ) ;
if ( V_131 == NULL )
return;
V_132 = V_128 -> V_138 ;
V_135 = V_128 -> V_137 ;
F_81 ( V_126 ) ;
for ( V_123 = 0 ; V_123 < V_135 ; V_123 ++ ) {
F_82 (cl, next, &ohash[i], hnode) {
V_124 = F_83 ( V_53 -> V_52 , V_134 ) ;
F_84 ( & V_53 -> V_139 , & V_131 [ V_124 ] ) ;
}
}
V_128 -> V_138 = V_131 ;
V_128 -> V_137 = V_133 ;
V_128 -> V_140 = V_134 ;
F_85 ( V_126 ) ;
F_78 ( V_132 , V_135 ) ;
}
int F_86 ( struct V_127 * V_128 )
{
unsigned int V_122 = 4 ;
V_128 -> V_138 = F_74 ( V_122 ) ;
if ( V_128 -> V_138 == NULL )
return - V_91 ;
V_128 -> V_137 = V_122 ;
V_128 -> V_140 = V_122 - 1 ;
V_128 -> V_136 = 0 ;
return 0 ;
}
void F_87 ( struct V_127 * V_128 )
{
F_78 ( V_128 -> V_138 , V_128 -> V_137 ) ;
}
void F_88 ( struct V_127 * V_128 ,
struct V_129 * V_53 )
{
unsigned int V_124 ;
F_89 ( & V_53 -> V_139 ) ;
V_124 = F_83 ( V_53 -> V_52 , V_128 -> V_140 ) ;
F_84 ( & V_53 -> V_139 , & V_128 -> V_138 [ V_124 ] ) ;
V_128 -> V_136 ++ ;
}
void F_90 ( struct V_127 * V_128 ,
struct V_129 * V_53 )
{
F_91 ( & V_53 -> V_139 ) ;
V_128 -> V_136 -- ;
}
static T_2 F_92 ( struct V_48 * V_49 )
{
int V_123 = 0x8000 ;
static T_2 V_141 = F_93 ( 0x80000000U , 0 ) ;
do {
V_141 += F_93 ( 0x10000U , 0 ) ;
if ( V_141 == F_93 ( V_43 , 0 ) )
V_141 = F_93 ( 0x80000000U , 0 ) ;
if ( ! F_24 ( V_49 , V_141 ) )
return V_141 ;
F_94 () ;
} while ( -- V_123 > 0 );
return 0 ;
}
void F_95 ( struct V_37 * V_126 , unsigned int V_121 ,
unsigned int V_31 )
{
const struct V_18 * V_19 ;
unsigned long V_53 ;
T_2 V_142 ;
int V_143 ;
if ( V_121 == 0 && V_31 == 0 )
return;
V_143 = F_96 ( int , V_121 , 0 ) ;
F_61 () ;
while ( ( V_142 = V_126 -> V_42 ) ) {
if ( F_97 ( V_142 ) == F_97 ( V_144 ) )
break;
if ( V_126 -> V_40 & V_145 )
break;
V_126 = F_24 ( F_18 ( V_126 ) , F_97 ( V_142 ) ) ;
if ( V_126 == NULL ) {
F_19 ( V_142 != V_43 ) ;
break;
}
V_19 = V_126 -> V_34 -> V_17 ;
if ( V_19 -> V_146 ) {
V_53 = V_19 -> V_20 ( V_126 , V_142 ) ;
V_19 -> V_146 ( V_126 , V_53 ) ;
V_19 -> V_21 ( V_126 , V_53 ) ;
}
V_126 -> V_3 . V_147 -= V_121 ;
V_126 -> V_148 . V_149 -= V_31 ;
F_98 ( V_126 , V_143 ) ;
}
F_64 () ;
}
static void F_99 ( struct V_150 * V_150 , struct V_96 * V_97 ,
struct V_151 * V_121 , T_2 V_152 ,
struct V_37 * V_153 , struct V_37 * V_154 )
{
if ( V_154 || V_153 )
F_100 ( V_150 , V_97 , V_121 , V_152 , V_153 , V_154 ) ;
if ( V_153 )
F_101 ( V_153 ) ;
}
static int F_102 ( struct V_48 * V_49 , struct V_37 * V_42 ,
struct V_96 * V_97 , struct V_151 * V_121 , T_2 V_52 ,
struct V_37 * V_154 , struct V_37 * V_153 )
{
struct V_37 * V_3 = V_153 ;
struct V_150 * V_150 = F_103 ( V_49 ) ;
int V_28 = 0 ;
if ( V_42 == NULL ) {
unsigned int V_123 , V_155 , V_156 ;
V_156 = 0 ;
V_155 = V_49 -> V_157 ;
if ( ( V_3 && V_3 -> V_40 & V_44 ) ||
( V_154 && V_154 -> V_40 & V_44 ) ) {
V_155 = 1 ;
V_156 = 1 ;
if ( ! F_25 ( V_49 ) )
return - V_29 ;
}
if ( V_49 -> V_40 & V_158 )
F_104 ( V_49 ) ;
if ( V_154 && V_154 -> V_34 -> V_159 )
goto V_160;
for ( V_123 = 0 ; V_123 < V_155 ; V_123 ++ ) {
struct V_161 * V_162 = F_25 ( V_49 ) ;
if ( ! V_156 )
V_162 = F_105 ( V_49 , V_123 ) ;
V_153 = F_106 ( V_162 , V_154 ) ;
if ( V_154 && V_123 > 0 )
F_107 ( & V_154 -> V_73 ) ;
if ( ! V_156 )
F_101 ( V_153 ) ;
}
V_160:
if ( ! V_156 ) {
F_99 ( V_150 , V_97 , V_121 , V_52 ,
V_49 -> V_45 , V_154 ) ;
if ( V_154 && ! V_154 -> V_34 -> V_159 )
F_107 ( & V_154 -> V_73 ) ;
V_49 -> V_45 = V_154 ? : & V_46 ;
if ( V_154 && V_154 -> V_34 -> V_159 )
V_154 -> V_34 -> V_159 ( V_154 ) ;
} else {
F_99 ( V_150 , V_97 , V_121 , V_52 , V_153 , V_154 ) ;
}
if ( V_49 -> V_40 & V_158 )
F_108 ( V_49 ) ;
} else {
const struct V_18 * V_19 = V_42 -> V_34 -> V_17 ;
V_28 = - V_163 ;
if ( V_19 && V_19 -> V_164 ) {
unsigned long V_53 = V_19 -> V_20 ( V_42 , V_52 ) ;
if ( V_53 ) {
V_28 = V_19 -> V_164 ( V_42 , V_53 , V_154 , & V_153 ) ;
V_19 -> V_21 ( V_42 , V_53 ) ;
} else
V_28 = - V_29 ;
}
if ( ! V_28 )
F_99 ( V_150 , V_97 , V_121 , V_52 , V_153 , V_154 ) ;
}
return V_28 ;
}
static struct V_37 *
F_109 ( struct V_48 * V_49 , struct V_161 * V_162 ,
struct V_37 * V_51 , T_2 V_42 , T_2 V_39 ,
struct V_54 * * V_165 , int * V_166 )
{
int V_28 ;
struct V_54 * V_55 = V_165 [ V_167 ] ;
struct V_37 * V_126 ;
struct V_1 * V_34 ;
struct V_78 * V_82 ;
V_34 = F_27 ( V_55 ) ;
#ifdef F_110
if ( V_34 == NULL && V_55 != NULL ) {
char V_30 [ V_168 ] ;
if ( F_111 ( V_30 , V_55 , V_168 ) < V_168 ) {
F_112 () ;
F_13 ( L_1 , V_30 ) ;
F_113 () ;
V_34 = F_27 ( V_55 ) ;
if ( V_34 != NULL ) {
F_14 ( V_34 -> V_33 ) ;
V_28 = - V_169 ;
goto V_170;
}
}
}
#endif
V_28 = - V_29 ;
if ( V_34 == NULL )
goto V_170;
V_126 = F_114 ( V_162 , V_34 ) ;
if ( F_115 ( V_126 ) ) {
V_28 = F_116 ( V_126 ) ;
goto V_171;
}
V_126 -> V_42 = V_42 ;
if ( V_39 == V_144 ) {
V_126 -> V_40 |= V_44 ;
V_39 = F_93 ( V_144 , 0 ) ;
F_117 ( F_118 ( V_126 ) , & V_172 ) ;
} else {
if ( V_39 == 0 ) {
V_39 = F_92 ( V_49 ) ;
V_28 = - V_91 ;
if ( V_39 == 0 )
goto V_173;
}
F_117 ( F_118 ( V_126 ) , & V_174 ) ;
if ( ! F_119 ( V_49 ) )
V_126 -> V_40 |= V_175 ;
}
V_126 -> V_39 = V_39 ;
if ( ! V_34 -> V_176 || ( V_28 = V_34 -> V_176 ( V_126 , V_165 [ V_177 ] ) ) == 0 ) {
if ( F_120 ( V_126 ) ) {
V_126 -> V_178 =
F_121 ( struct V_179 ) ;
if ( ! V_126 -> V_178 )
goto V_180;
V_126 -> V_181 = F_122 ( struct V_182 ) ;
if ( ! V_126 -> V_181 )
goto V_180;
}
if ( V_165 [ V_99 ] ) {
V_82 = F_38 ( V_165 [ V_99 ] ) ;
if ( F_115 ( V_82 ) ) {
V_28 = F_116 ( V_82 ) ;
goto V_180;
}
F_123 ( V_126 -> V_82 , V_82 ) ;
}
if ( V_165 [ V_183 ] ) {
T_7 * V_184 ;
V_28 = - V_163 ;
if ( V_126 -> V_40 & V_185 )
goto V_180;
if ( ( V_126 -> V_42 != V_43 ) &&
! ( V_126 -> V_40 & V_44 ) &&
( ! V_51 || ! ( V_51 -> V_40 & V_185 ) ) )
V_184 = F_124 ( V_126 ) ;
else
V_184 = & V_126 -> V_184 ;
V_28 = F_125 ( & V_126 -> V_186 ,
V_126 -> V_178 ,
& V_126 -> V_187 ,
NULL ,
V_184 ,
V_165 [ V_183 ] ) ;
if ( V_28 )
goto V_180;
}
F_17 ( V_126 ) ;
return V_126 ;
}
V_173:
F_126 ( V_49 ) ;
F_37 ( ( char * ) V_126 - V_126 -> V_188 ) ;
V_171:
F_14 ( V_34 -> V_33 ) ;
V_170:
* V_166 = V_28 ;
return NULL ;
V_180:
F_127 ( V_126 -> V_178 ) ;
F_127 ( V_126 -> V_181 ) ;
F_47 ( F_128 ( V_126 -> V_82 ) ) ;
if ( V_34 -> V_189 )
V_34 -> V_189 ( V_126 ) ;
goto V_173;
}
static int F_129 ( struct V_37 * V_126 , struct V_54 * * V_165 )
{
struct V_78 * V_190 , * V_82 = NULL ;
int V_28 = 0 ;
if ( V_165 [ V_177 ] ) {
if ( V_126 -> V_34 -> V_191 == NULL )
return - V_27 ;
V_28 = V_126 -> V_34 -> V_191 ( V_126 , V_165 [ V_177 ] ) ;
if ( V_28 )
return V_28 ;
}
if ( V_165 [ V_99 ] ) {
V_82 = F_38 ( V_165 [ V_99 ] ) ;
if ( F_115 ( V_82 ) )
return F_116 ( V_82 ) ;
}
V_190 = F_128 ( V_126 -> V_82 ) ;
F_123 ( V_126 -> V_82 , V_82 ) ;
F_47 ( V_190 ) ;
if ( V_165 [ V_183 ] ) {
if ( V_126 -> V_40 & V_185 )
goto V_11;
F_130 ( & V_126 -> V_186 ,
V_126 -> V_178 ,
& V_126 -> V_187 ,
NULL ,
F_124 ( V_126 ) ,
V_165 [ V_183 ] ) ;
}
V_11:
return 0 ;
}
static int F_131 ( struct V_37 * V_3 , struct V_37 * V_51 , int V_192 )
{
struct V_193 V_194 ;
if ( V_3 -> V_34 -> V_17 == NULL )
return 0 ;
V_194 . V_195 . V_196 = V_194 . V_195 . V_160 = V_194 . V_195 . V_197 = 0 ;
V_194 . V_195 . V_198 = V_199 ;
V_194 . V_192 = V_192 ;
V_194 . V_51 = V_51 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_194 . V_195 ) ;
return V_194 . V_195 . V_196 ? - V_200 : 0 ;
}
static int
V_199 ( struct V_37 * V_3 , unsigned long V_53 , struct V_201 * V_195 )
{
struct V_37 * V_23 ;
const struct V_18 * V_19 = V_3 -> V_34 -> V_17 ;
struct V_193 * V_194 = (struct V_193 * ) V_195 ;
V_23 = V_19 -> V_23 ( V_3 , V_53 ) ;
if ( V_23 ) {
if ( V_23 == V_194 -> V_51 || V_194 -> V_192 > 7 )
return - V_200 ;
return F_131 ( V_23 , V_194 -> V_51 , V_194 -> V_192 + 1 ) ;
}
return 0 ;
}
static int F_132 ( struct V_96 * V_97 , struct V_151 * V_121 )
{
struct V_150 * V_150 = F_133 ( V_97 -> V_202 ) ;
struct V_203 * V_204 = F_134 ( V_121 ) ;
struct V_54 * V_165 [ V_205 + 1 ] ;
struct V_48 * V_49 ;
T_2 V_152 ;
struct V_37 * V_3 = NULL ;
struct V_37 * V_51 = NULL ;
int V_28 ;
if ( ( V_121 -> V_206 != V_207 ) &&
! F_135 ( V_97 , V_150 -> V_208 , V_35 ) )
return - V_36 ;
V_28 = F_136 ( V_121 , sizeof( * V_204 ) , V_165 , V_205 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_49 = F_137 ( V_150 , V_204 -> V_209 ) ;
if ( ! V_49 )
return - V_210 ;
V_152 = V_204 -> V_211 ;
if ( V_152 ) {
if ( V_152 != V_43 ) {
if ( F_97 ( V_152 ) != F_97 ( V_144 ) ) {
V_51 = F_24 ( V_49 , F_97 ( V_152 ) ) ;
if ( ! V_51 )
return - V_29 ;
V_3 = F_26 ( V_51 , V_152 ) ;
} else if ( F_25 ( V_49 ) ) {
V_3 = F_25 ( V_49 ) -> V_50 ;
}
} else {
V_3 = V_49 -> V_45 ;
}
if ( ! V_3 )
return - V_29 ;
if ( V_204 -> V_212 && V_3 -> V_39 != V_204 -> V_212 )
return - V_27 ;
} else {
V_3 = F_24 ( V_49 , V_204 -> V_212 ) ;
if ( ! V_3 )
return - V_29 ;
}
if ( V_165 [ V_167 ] && F_28 ( V_165 [ V_167 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_121 -> V_206 == V_213 ) {
if ( ! V_152 )
return - V_27 ;
if ( V_3 -> V_39 == 0 )
return - V_29 ;
V_28 = F_102 ( V_49 , V_51 , V_97 , V_121 , V_152 , NULL , V_3 ) ;
if ( V_28 != 0 )
return V_28 ;
} else {
F_100 ( V_150 , V_97 , V_121 , V_152 , NULL , V_3 ) ;
}
return 0 ;
}
static int F_138 ( struct V_96 * V_97 , struct V_151 * V_121 )
{
struct V_150 * V_150 = F_133 ( V_97 -> V_202 ) ;
struct V_203 * V_204 ;
struct V_54 * V_165 [ V_205 + 1 ] ;
struct V_48 * V_49 ;
T_2 V_152 ;
struct V_37 * V_3 , * V_51 ;
int V_28 ;
if ( ! F_135 ( V_97 , V_150 -> V_208 , V_35 ) )
return - V_36 ;
V_214:
V_28 = F_136 ( V_121 , sizeof( * V_204 ) , V_165 , V_205 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_204 = F_134 ( V_121 ) ;
V_152 = V_204 -> V_211 ;
V_3 = V_51 = NULL ;
V_49 = F_137 ( V_150 , V_204 -> V_209 ) ;
if ( ! V_49 )
return - V_210 ;
if ( V_152 ) {
if ( V_152 != V_43 ) {
if ( V_152 != V_144 ) {
V_51 = F_24 ( V_49 , F_97 ( V_152 ) ) ;
if ( ! V_51 )
return - V_29 ;
V_3 = F_26 ( V_51 , V_152 ) ;
} else if ( F_139 ( V_49 ) ) {
V_3 = F_25 ( V_49 ) -> V_50 ;
}
} else {
V_3 = V_49 -> V_45 ;
}
if ( V_3 && V_3 -> V_39 == 0 )
V_3 = NULL ;
if ( ! V_3 || ! V_204 -> V_212 || V_3 -> V_39 != V_204 -> V_212 ) {
if ( V_204 -> V_212 ) {
if ( V_3 && ! ( V_121 -> V_215 & V_216 ) )
return - V_6 ;
if ( F_140 ( V_204 -> V_212 ) )
return - V_27 ;
V_3 = F_24 ( V_49 , V_204 -> V_212 ) ;
if ( ! V_3 )
goto V_217;
if ( V_121 -> V_215 & V_218 )
return - V_6 ;
if ( V_165 [ V_167 ] && F_28 ( V_165 [ V_167 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_3 == V_51 ||
( V_51 && F_131 ( V_3 , V_51 , 0 ) ) )
return - V_200 ;
F_107 ( & V_3 -> V_73 ) ;
goto V_164;
} else {
if ( ! V_3 )
goto V_217;
if ( ( V_121 -> V_215 & V_219 ) &&
( V_121 -> V_215 & V_216 ) &&
( ( V_121 -> V_215 & V_218 ) ||
( V_165 [ V_167 ] &&
F_28 ( V_165 [ V_167 ] , V_3 -> V_34 -> V_10 ) ) ) )
goto V_217;
}
}
} else {
if ( ! V_204 -> V_212 )
return - V_27 ;
V_3 = F_24 ( V_49 , V_204 -> V_212 ) ;
}
if ( V_3 == NULL )
return - V_29 ;
if ( V_121 -> V_215 & V_218 )
return - V_6 ;
if ( V_165 [ V_167 ] && F_28 ( V_165 [ V_167 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
V_28 = F_129 ( V_3 , V_165 ) ;
if ( V_28 == 0 )
F_100 ( V_150 , V_97 , V_121 , V_152 , NULL , V_3 ) ;
return V_28 ;
V_217:
if ( ! ( V_121 -> V_215 & V_219 ) )
return - V_29 ;
if ( V_152 == V_144 ) {
if ( F_25 ( V_49 ) )
V_3 = F_109 ( V_49 , F_25 ( V_49 ) , V_51 ,
V_204 -> V_211 , V_204 -> V_211 ,
V_165 , & V_28 ) ;
else
V_28 = - V_29 ;
} else {
struct V_161 * V_162 ;
if ( V_51 && V_51 -> V_34 -> V_17 && V_51 -> V_34 -> V_17 -> V_220 )
V_162 = V_51 -> V_34 -> V_17 -> V_220 ( V_51 , V_204 ) ;
else if ( V_51 )
V_162 = V_51 -> V_162 ;
else
V_162 = F_105 ( V_49 , 0 ) ;
V_3 = F_109 ( V_49 , V_162 , V_51 ,
V_204 -> V_211 , V_204 -> V_212 ,
V_165 , & V_28 ) ;
}
if ( V_3 == NULL ) {
if ( V_28 == - V_169 )
goto V_214;
return V_28 ;
}
V_164:
V_28 = F_102 ( V_49 , V_51 , V_97 , V_121 , V_152 , V_3 , NULL ) ;
if ( V_28 ) {
if ( V_3 )
F_101 ( V_3 ) ;
return V_28 ;
}
return 0 ;
}
static int F_141 ( struct V_96 * V_97 , struct V_37 * V_3 , T_2 V_152 ,
T_2 V_221 , T_2 V_222 , T_5 V_40 , int V_223 )
{
struct V_179 T_8 * V_178 = NULL ;
struct V_182 T_8 * V_181 = NULL ;
struct V_203 * V_204 ;
struct V_151 * V_224 ;
unsigned char * V_225 = F_142 ( V_97 ) ;
struct V_226 V_227 ;
struct V_78 * V_82 ;
T_4 V_147 ;
F_94 () ;
V_224 = F_143 ( V_97 , V_221 , V_222 , V_223 , sizeof( * V_204 ) , V_40 ) ;
if ( ! V_224 )
goto V_228;
V_204 = F_134 ( V_224 ) ;
V_204 -> V_229 = V_230 ;
V_204 -> V_231 = 0 ;
V_204 -> V_232 = 0 ;
V_204 -> V_209 = F_18 ( V_3 ) -> V_233 ;
V_204 -> V_211 = V_152 ;
V_204 -> V_212 = V_3 -> V_39 ;
V_204 -> V_234 = F_144 ( & V_3 -> V_73 ) ;
if ( F_145 ( V_97 , V_167 , V_3 -> V_34 -> V_10 ) )
goto V_100;
if ( V_3 -> V_34 -> V_235 && V_3 -> V_34 -> V_235 ( V_3 , V_97 ) < 0 )
goto V_100;
V_147 = V_3 -> V_3 . V_147 ;
V_82 = F_128 ( V_3 -> V_82 ) ;
if ( V_82 && F_50 ( V_97 , V_82 ) < 0 )
goto V_100;
if ( F_146 ( V_97 , V_236 , V_237 , V_238 ,
NULL , & V_227 , V_239 ) < 0 )
goto V_100;
if ( V_3 -> V_34 -> V_240 && V_3 -> V_34 -> V_240 ( V_3 , & V_227 ) < 0 )
goto V_100;
if ( F_120 ( V_3 ) ) {
V_178 = V_3 -> V_178 ;
V_181 = V_3 -> V_181 ;
}
if ( F_147 ( F_124 ( V_3 ) ,
& V_227 , V_178 , & V_3 -> V_186 ) < 0 ||
F_148 ( & V_227 , & V_3 -> V_186 , & V_3 -> V_187 ) < 0 ||
F_149 ( & V_227 , V_181 , & V_3 -> V_148 , V_147 ) < 0 )
goto V_100;
if ( F_150 ( & V_227 ) < 0 )
goto V_100;
V_224 -> V_241 = F_142 ( V_97 ) - V_225 ;
return V_97 -> V_31 ;
V_228:
V_100:
F_151 ( V_97 , V_225 ) ;
return - 1 ;
}
static bool F_152 ( struct V_37 * V_3 )
{
return ( V_3 -> V_40 & V_41 ) ? true : false ;
}
static int F_100 ( struct V_150 * V_150 , struct V_96 * V_242 ,
struct V_151 * V_121 , T_2 V_152 ,
struct V_37 * V_153 , struct V_37 * V_154 )
{
struct V_96 * V_97 ;
T_2 V_221 = V_242 ? F_153 ( V_242 ) . V_221 : 0 ;
V_97 = F_154 ( V_243 , V_74 ) ;
if ( ! V_97 )
return - V_244 ;
if ( V_153 && ! F_152 ( V_153 ) ) {
if ( F_141 ( V_97 , V_153 , V_152 , V_221 , V_121 -> V_245 ,
0 , V_213 ) < 0 )
goto V_170;
}
if ( V_154 && ! F_152 ( V_154 ) ) {
if ( F_141 ( V_97 , V_154 , V_152 , V_221 , V_121 -> V_245 ,
V_153 ? V_216 : 0 , V_246 ) < 0 )
goto V_170;
}
if ( V_97 -> V_31 )
return F_155 ( V_97 , V_150 , V_221 , V_247 ,
V_121 -> V_215 & V_248 ) ;
V_170:
F_156 ( V_97 ) ;
return - V_27 ;
}
static int F_157 ( struct V_37 * V_38 , struct V_96 * V_97 ,
struct V_249 * V_250 ,
int * V_251 , int V_252 )
{
int V_253 = 0 , V_254 = * V_251 ;
struct V_37 * V_3 ;
if ( ! V_38 )
return 0 ;
V_3 = V_38 ;
if ( V_254 < V_252 ) {
V_254 ++ ;
} else {
if ( ! F_152 ( V_3 ) &&
F_141 ( V_97 , V_3 , V_3 -> V_42 , F_153 ( V_250 -> V_97 ) . V_221 ,
V_250 -> V_224 -> V_245 , V_255 , V_246 ) <= 0 )
goto V_256;
V_254 ++ ;
}
F_42 (q, &root->list, list) {
if ( V_254 < V_252 ) {
V_254 ++ ;
continue;
}
if ( ! F_152 ( V_3 ) &&
F_141 ( V_97 , V_3 , V_3 -> V_42 , F_153 ( V_250 -> V_97 ) . V_221 ,
V_250 -> V_224 -> V_245 , V_255 , V_246 ) <= 0 )
goto V_256;
V_254 ++ ;
}
V_11:
* V_251 = V_254 ;
return V_253 ;
V_256:
V_253 = - 1 ;
goto V_11;
}
static int F_158 ( struct V_96 * V_97 , struct V_249 * V_250 )
{
struct V_150 * V_150 = F_133 ( V_97 -> V_202 ) ;
int V_257 , V_254 ;
int V_258 , V_252 ;
struct V_48 * V_49 ;
V_258 = V_250 -> args [ 0 ] ;
V_252 = V_254 = V_250 -> args [ 1 ] ;
V_257 = 0 ;
F_20 () ;
F_159 (net, dev) {
struct V_161 * V_162 ;
if ( V_257 < V_258 )
goto V_259;
if ( V_257 > V_258 )
V_252 = 0 ;
V_254 = 0 ;
if ( F_157 ( V_49 -> V_45 , V_97 , V_250 , & V_254 , V_252 ) < 0 )
goto V_256;
V_162 = F_25 ( V_49 ) ;
if ( V_162 &&
F_157 ( V_162 -> V_50 , V_97 , V_250 ,
& V_254 , V_252 ) < 0 )
goto V_256;
V_259:
V_257 ++ ;
}
V_256:
V_250 -> args [ 0 ] = V_257 ;
V_250 -> args [ 1 ] = V_254 ;
return V_97 -> V_31 ;
}
static int F_160 ( struct V_96 * V_97 , struct V_151 * V_121 )
{
struct V_150 * V_150 = F_133 ( V_97 -> V_202 ) ;
struct V_203 * V_204 = F_134 ( V_121 ) ;
struct V_54 * V_165 [ V_205 + 1 ] ;
struct V_48 * V_49 ;
struct V_37 * V_3 = NULL ;
const struct V_18 * V_19 ;
unsigned long V_53 = 0 ;
unsigned long V_260 ;
T_2 V_221 ;
T_2 V_152 ;
T_2 V_261 ;
int V_28 ;
if ( ( V_121 -> V_206 != V_262 ) &&
! F_135 ( V_97 , V_150 -> V_208 , V_35 ) )
return - V_36 ;
V_28 = F_136 ( V_121 , sizeof( * V_204 ) , V_165 , V_205 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_49 = F_137 ( V_150 , V_204 -> V_209 ) ;
if ( ! V_49 )
return - V_210 ;
V_221 = V_204 -> V_211 ;
V_152 = V_204 -> V_212 ;
V_261 = F_97 ( V_152 ) ;
if ( V_221 != V_43 ) {
T_2 V_263 = F_97 ( V_221 ) ;
if ( V_261 && V_263 ) {
if ( V_261 != V_263 )
return - V_27 ;
} else if ( V_263 ) {
V_261 = V_263 ;
} else if ( V_261 == 0 )
V_261 = V_49 -> V_45 -> V_39 ;
if ( V_221 )
V_221 = F_93 ( V_261 , V_221 ) ;
} else {
if ( V_261 == 0 )
V_261 = V_49 -> V_45 -> V_39 ;
}
V_3 = F_24 ( V_49 , V_261 ) ;
if ( ! V_3 )
return - V_29 ;
V_19 = V_3 -> V_34 -> V_17 ;
if ( V_19 == NULL )
return - V_27 ;
if ( V_152 == 0 ) {
if ( V_221 == V_43 )
V_152 = V_261 ;
} else
V_152 = F_93 ( V_261 , V_152 ) ;
if ( V_152 )
V_53 = V_19 -> V_20 ( V_3 , V_152 ) ;
if ( V_53 == 0 ) {
V_28 = - V_29 ;
if ( V_121 -> V_206 != V_264 ||
! ( V_121 -> V_215 & V_219 ) )
goto V_11;
} else {
switch ( V_121 -> V_206 ) {
case V_264 :
V_28 = - V_6 ;
if ( V_121 -> V_215 & V_218 )
goto V_11;
break;
case V_265 :
V_28 = - V_163 ;
if ( V_19 -> V_266 )
V_28 = V_19 -> V_266 ( V_3 , V_53 ) ;
if ( V_28 == 0 )
F_161 ( V_150 , V_97 , V_121 , V_3 , V_53 , V_265 ) ;
goto V_11;
case V_262 :
V_28 = F_161 ( V_150 , V_97 , V_121 , V_3 , V_53 , V_264 ) ;
goto V_11;
default:
V_28 = - V_27 ;
goto V_11;
}
}
V_260 = V_53 ;
V_28 = - V_163 ;
if ( V_19 -> V_191 )
V_28 = V_19 -> V_191 ( V_3 , V_152 , V_221 , V_165 , & V_260 ) ;
if ( V_28 == 0 )
F_161 ( V_150 , V_97 , V_121 , V_3 , V_260 , V_264 ) ;
V_11:
if ( V_53 )
V_19 -> V_21 ( V_3 , V_53 ) ;
return V_28 ;
}
static int F_162 ( struct V_96 * V_97 , struct V_37 * V_3 ,
unsigned long V_53 ,
T_2 V_221 , T_2 V_222 , T_5 V_40 , int V_223 )
{
struct V_203 * V_204 ;
struct V_151 * V_224 ;
unsigned char * V_225 = F_142 ( V_97 ) ;
struct V_226 V_227 ;
const struct V_18 * V_17 = V_3 -> V_34 -> V_17 ;
F_94 () ;
V_224 = F_143 ( V_97 , V_221 , V_222 , V_223 , sizeof( * V_204 ) , V_40 ) ;
if ( ! V_224 )
goto V_228;
V_204 = F_134 ( V_224 ) ;
V_204 -> V_229 = V_230 ;
V_204 -> V_231 = 0 ;
V_204 -> V_232 = 0 ;
V_204 -> V_209 = F_18 ( V_3 ) -> V_233 ;
V_204 -> V_211 = V_3 -> V_39 ;
V_204 -> V_212 = V_3 -> V_39 ;
V_204 -> V_234 = 0 ;
if ( F_145 ( V_97 , V_167 , V_3 -> V_34 -> V_10 ) )
goto V_100;
if ( V_17 -> V_235 && V_17 -> V_235 ( V_3 , V_53 , V_97 , V_204 ) < 0 )
goto V_100;
if ( F_146 ( V_97 , V_236 , V_237 , V_238 ,
NULL , & V_227 , V_239 ) < 0 )
goto V_100;
if ( V_17 -> V_240 && V_17 -> V_240 ( V_3 , V_53 , & V_227 ) < 0 )
goto V_100;
if ( F_150 ( & V_227 ) < 0 )
goto V_100;
V_224 -> V_241 = F_142 ( V_97 ) - V_225 ;
return V_97 -> V_31 ;
V_228:
V_100:
F_151 ( V_97 , V_225 ) ;
return - 1 ;
}
static int F_161 ( struct V_150 * V_150 , struct V_96 * V_242 ,
struct V_151 * V_121 , struct V_37 * V_3 ,
unsigned long V_53 , int V_223 )
{
struct V_96 * V_97 ;
T_2 V_221 = V_242 ? F_153 ( V_242 ) . V_221 : 0 ;
V_97 = F_154 ( V_243 , V_74 ) ;
if ( ! V_97 )
return - V_244 ;
if ( F_162 ( V_97 , V_3 , V_53 , V_221 , V_121 -> V_245 , 0 , V_223 ) < 0 ) {
F_156 ( V_97 ) ;
return - V_27 ;
}
return F_155 ( V_97 , V_150 , V_221 , V_247 ,
V_121 -> V_215 & V_248 ) ;
}
static int F_163 ( struct V_37 * V_3 , unsigned long V_53 , struct V_201 * V_194 )
{
struct V_267 * V_268 = (struct V_267 * ) V_194 ;
return F_162 ( V_268 -> V_97 , V_3 , V_53 , F_153 ( V_268 -> V_250 -> V_97 ) . V_221 ,
V_268 -> V_250 -> V_224 -> V_245 , V_255 , V_264 ) ;
}
static int F_164 ( struct V_37 * V_3 , struct V_96 * V_97 ,
struct V_203 * V_204 , struct V_249 * V_250 ,
int * V_269 , int V_270 )
{
struct V_267 V_194 ;
if ( F_152 ( V_3 ) ||
* V_269 < V_270 || ! V_3 -> V_34 -> V_17 ||
( V_204 -> V_211 &&
F_97 ( V_204 -> V_211 ) != V_3 -> V_39 ) ) {
( * V_269 ) ++ ;
return 0 ;
}
if ( * V_269 > V_270 )
memset ( & V_250 -> args [ 1 ] , 0 , sizeof( V_250 -> args ) - sizeof( V_250 -> args [ 0 ] ) ) ;
V_194 . V_195 . V_198 = F_163 ;
V_194 . V_97 = V_97 ;
V_194 . V_250 = V_250 ;
V_194 . V_195 . V_196 = 0 ;
V_194 . V_195 . V_160 = V_250 -> args [ 1 ] ;
V_194 . V_195 . V_197 = 0 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_194 . V_195 ) ;
V_250 -> args [ 1 ] = V_194 . V_195 . V_197 ;
if ( V_194 . V_195 . V_196 )
return - 1 ;
( * V_269 ) ++ ;
return 0 ;
}
static int F_165 ( struct V_37 * V_38 , struct V_96 * V_97 ,
struct V_203 * V_204 , struct V_249 * V_250 ,
int * V_269 , int V_270 )
{
struct V_37 * V_3 ;
if ( ! V_38 )
return 0 ;
if ( F_164 ( V_38 , V_97 , V_204 , V_250 , V_269 , V_270 ) < 0 )
return - 1 ;
F_42 (q, &root->list, list) {
if ( F_164 ( V_3 , V_97 , V_204 , V_250 , V_269 , V_270 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_166 ( struct V_96 * V_97 , struct V_249 * V_250 )
{
struct V_203 * V_204 = F_134 ( V_250 -> V_224 ) ;
struct V_150 * V_150 = F_133 ( V_97 -> V_202 ) ;
struct V_161 * V_162 ;
struct V_48 * V_49 ;
int V_271 , V_270 ;
if ( V_241 ( V_250 -> V_224 ) < sizeof( * V_204 ) )
return 0 ;
V_49 = F_167 ( V_150 , V_204 -> V_209 ) ;
if ( ! V_49 )
return 0 ;
V_270 = V_250 -> args [ 0 ] ;
V_271 = 0 ;
if ( F_165 ( V_49 -> V_45 , V_97 , V_204 , V_250 , & V_271 , V_270 ) < 0 )
goto V_256;
V_162 = F_25 ( V_49 ) ;
if ( V_162 &&
F_165 ( V_162 -> V_50 , V_97 , V_204 , V_250 ,
& V_271 , V_270 ) < 0 )
goto V_256;
V_256:
V_250 -> args [ 0 ] = V_271 ;
F_126 ( V_49 ) ;
return V_97 -> V_31 ;
}
int F_168 ( struct V_96 * V_97 , const struct V_272 * V_273 ,
struct V_274 * V_275 , bool V_276 )
{
T_9 V_277 = F_169 ( V_97 ) ;
#ifdef F_170
const struct V_272 * V_278 = V_273 ;
int V_279 = 0 ;
V_280:
#endif
for (; V_273 ; V_273 = F_171 ( V_273 -> V_9 ) ) {
int V_28 ;
if ( V_273 -> V_277 != V_277 &&
V_273 -> V_277 != F_172 ( V_281 ) )
continue;
V_28 = V_273 -> V_282 ( V_97 , V_273 , V_275 ) ;
#ifdef F_170
if ( F_55 ( V_28 == V_283 && ! V_276 ) )
goto V_284;
#endif
if ( V_28 >= 0 )
return V_28 ;
}
return V_285 ;
#ifdef F_170
V_284:
if ( F_55 ( V_279 ++ >= V_286 ) ) {
F_173 ( L_5 ,
V_273 -> V_3 -> V_34 -> V_10 , V_273 -> V_287 & 0xffff ,
F_174 ( V_273 -> V_277 ) ) ;
return V_288 ;
}
V_273 = V_278 ;
V_277 = F_169 ( V_97 ) ;
goto V_280;
#endif
}
bool F_175 ( struct V_272 * V_273 , bool V_289 )
{
if ( V_273 -> V_34 -> V_189 ( V_273 , V_289 ) ) {
F_14 ( V_273 -> V_34 -> V_33 ) ;
F_176 ( V_273 , V_95 ) ;
return true ;
}
return false ;
}
void F_177 ( struct V_272 T_10 * * V_290 )
{
struct V_272 * V_273 ;
while ( ( V_273 = F_128 ( * V_290 ) ) != NULL ) {
F_178 ( * V_290 , V_273 -> V_9 ) ;
F_175 ( V_273 , true ) ;
}
}
static int F_179 ( struct V_291 * V_222 , void * V_292 )
{
F_180 ( V_222 , L_6 ,
( T_2 ) V_293 , ( T_2 ) F_181 ( 1 ) ,
1000000 ,
( T_2 ) V_294 / V_295 ) ;
return 0 ;
}
static int F_182 ( struct V_296 * V_296 , struct V_297 * V_297 )
{
return F_183 ( V_297 , F_179 , NULL ) ;
}
static int T_11 F_184 ( struct V_150 * V_150 )
{
struct V_298 * V_299 ;
V_299 = F_185 ( L_7 , 0 , V_150 -> V_300 , & V_301 ) ;
if ( V_299 == NULL )
return - V_91 ;
return 0 ;
}
static void T_12 F_186 ( struct V_150 * V_150 )
{
F_187 ( L_7 , V_150 -> V_300 ) ;
}
static int T_11 F_184 ( struct V_150 * V_150 )
{
return 0 ;
}
static void T_12 F_186 ( struct V_150 * V_150 )
{
}
static int T_13 F_188 ( void )
{
int V_28 ;
V_28 = F_189 ( & V_302 ) ;
if ( V_28 ) {
F_190 ( L_8
L_9 ) ;
return V_28 ;
}
F_1 ( & V_303 ) ;
F_1 ( & V_304 ) ;
F_1 ( & V_305 ) ;
F_1 ( & V_306 ) ;
F_1 ( & V_307 ) ;
F_1 ( & V_308 ) ;
F_191 ( V_309 , V_246 , F_138 , NULL , NULL ) ;
F_191 ( V_309 , V_213 , F_132 , NULL , NULL ) ;
F_191 ( V_309 , V_207 , F_132 , F_158 , NULL ) ;
F_191 ( V_309 , V_264 , F_160 , NULL , NULL ) ;
F_191 ( V_309 , V_265 , F_160 , NULL , NULL ) ;
F_191 ( V_309 , V_262 , F_160 , F_166 , NULL ) ;
return 0 ;
}
