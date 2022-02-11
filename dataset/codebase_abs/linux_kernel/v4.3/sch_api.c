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
F_57 () ;
F_58 ( V_111 -> V_45 ) ;
F_59 ( F_60 ( V_111 -> V_45 ) ) ;
F_61 () ;
return V_112 ;
}
void F_62 ( struct F_56 * V_111 , struct V_37 * V_45 )
{
F_63 ( & V_111 -> V_110 , V_113 , V_114 ) ;
V_111 -> V_110 . V_115 = F_56 ;
V_111 -> V_45 = V_45 ;
}
void F_64 ( struct F_56 * V_111 , T_6 V_116 , bool V_117 )
{
if ( F_65 ( V_118 ,
& F_66 ( V_111 -> V_45 ) -> V_119 ) )
return;
if ( V_117 )
F_67 ( V_111 -> V_45 ) ;
F_68 ( & V_111 -> V_110 ,
F_69 ( V_116 ) ,
V_114 ) ;
}
void F_70 ( struct F_56 * V_111 )
{
F_71 ( & V_111 -> V_110 ) ;
F_58 ( V_111 -> V_45 ) ;
}
static struct V_120 * F_72 ( unsigned int V_121 )
{
unsigned int V_122 = V_121 * sizeof( struct V_120 ) , V_123 ;
struct V_120 * V_124 ;
if ( V_122 <= V_125 )
V_124 = F_34 ( V_122 , V_74 ) ;
else
V_124 = (struct V_120 * )
F_73 ( V_74 , F_74 ( V_122 ) ) ;
if ( V_124 != NULL ) {
for ( V_123 = 0 ; V_123 < V_121 ; V_123 ++ )
F_75 ( & V_124 [ V_123 ] ) ;
}
return V_124 ;
}
static void F_76 ( struct V_120 * V_124 , unsigned int V_121 )
{
unsigned int V_122 = V_121 * sizeof( struct V_120 ) ;
if ( V_122 <= V_125 )
F_36 ( V_124 ) ;
else
F_77 ( ( unsigned long ) V_124 , F_74 ( V_122 ) ) ;
}
void F_78 ( struct V_37 * V_126 , struct V_127 * V_128 )
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
V_131 = F_72 ( V_133 ) ;
if ( V_131 == NULL )
return;
V_132 = V_128 -> V_138 ;
V_135 = V_128 -> V_137 ;
F_79 ( V_126 ) ;
for ( V_123 = 0 ; V_123 < V_135 ; V_123 ++ ) {
F_80 (cl, next, &ohash[i], hnode) {
V_124 = F_81 ( V_53 -> V_52 , V_134 ) ;
F_82 ( & V_53 -> V_139 , & V_131 [ V_124 ] ) ;
}
}
V_128 -> V_138 = V_131 ;
V_128 -> V_137 = V_133 ;
V_128 -> V_140 = V_134 ;
F_83 ( V_126 ) ;
F_76 ( V_132 , V_135 ) ;
}
int F_84 ( struct V_127 * V_128 )
{
unsigned int V_122 = 4 ;
V_128 -> V_138 = F_72 ( V_122 ) ;
if ( V_128 -> V_138 == NULL )
return - V_91 ;
V_128 -> V_137 = V_122 ;
V_128 -> V_140 = V_122 - 1 ;
V_128 -> V_136 = 0 ;
return 0 ;
}
void F_85 ( struct V_127 * V_128 )
{
F_76 ( V_128 -> V_138 , V_128 -> V_137 ) ;
}
void F_86 ( struct V_127 * V_128 ,
struct V_129 * V_53 )
{
unsigned int V_124 ;
F_87 ( & V_53 -> V_139 ) ;
V_124 = F_81 ( V_53 -> V_52 , V_128 -> V_140 ) ;
F_82 ( & V_53 -> V_139 , & V_128 -> V_138 [ V_124 ] ) ;
V_128 -> V_136 ++ ;
}
void F_88 ( struct V_127 * V_128 ,
struct V_129 * V_53 )
{
F_89 ( & V_53 -> V_139 ) ;
V_128 -> V_136 -- ;
}
static T_2 F_90 ( struct V_48 * V_49 )
{
int V_123 = 0x8000 ;
static T_2 V_141 = F_91 ( 0x80000000U , 0 ) ;
do {
V_141 += F_91 ( 0x10000U , 0 ) ;
if ( V_141 == F_91 ( V_43 , 0 ) )
V_141 = F_91 ( 0x80000000U , 0 ) ;
if ( ! F_23 ( V_49 , V_141 ) )
return V_141 ;
F_92 () ;
} while ( -- V_123 > 0 );
return 0 ;
}
void F_93 ( struct V_37 * V_126 , unsigned int V_121 )
{
const struct V_18 * V_19 ;
unsigned long V_53 ;
T_2 V_142 ;
int V_143 ;
if ( V_121 == 0 )
return;
V_143 = F_94 ( int , V_121 , 0 ) ;
while ( ( V_142 = V_126 -> V_42 ) ) {
if ( F_95 ( V_142 ) == F_95 ( V_144 ) )
return;
V_126 = F_23 ( F_18 ( V_126 ) , F_95 ( V_142 ) ) ;
if ( V_126 == NULL ) {
F_96 ( V_142 != V_43 ) ;
return;
}
V_19 = V_126 -> V_34 -> V_17 ;
if ( V_19 -> V_145 ) {
V_53 = V_19 -> V_20 ( V_126 , V_142 ) ;
V_19 -> V_145 ( V_126 , V_53 ) ;
V_19 -> V_21 ( V_126 , V_53 ) ;
}
V_126 -> V_3 . V_146 -= V_121 ;
F_97 ( V_126 , V_143 ) ;
}
}
static void F_98 ( struct V_147 * V_147 , struct V_96 * V_97 ,
struct V_148 * V_121 , T_2 V_149 ,
struct V_37 * V_150 , struct V_37 * V_151 )
{
if ( V_151 || V_150 )
F_99 ( V_147 , V_97 , V_121 , V_149 , V_150 , V_151 ) ;
if ( V_150 )
F_100 ( V_150 ) ;
}
static int F_101 ( struct V_48 * V_49 , struct V_37 * V_42 ,
struct V_96 * V_97 , struct V_148 * V_121 , T_2 V_52 ,
struct V_37 * V_151 , struct V_37 * V_150 )
{
struct V_37 * V_3 = V_150 ;
struct V_147 * V_147 = F_102 ( V_49 ) ;
int V_28 = 0 ;
if ( V_42 == NULL ) {
unsigned int V_123 , V_152 , V_153 ;
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
F_103 ( V_49 ) ;
if ( V_151 && V_151 -> V_34 -> V_156 )
goto V_157;
for ( V_123 = 0 ; V_123 < V_152 ; V_123 ++ ) {
struct V_158 * V_159 = F_24 ( V_49 ) ;
if ( ! V_153 )
V_159 = F_104 ( V_49 , V_123 ) ;
V_150 = F_105 ( V_159 , V_151 ) ;
if ( V_151 && V_123 > 0 )
F_106 ( & V_151 -> V_73 ) ;
if ( ! V_153 )
F_100 ( V_150 ) ;
}
V_157:
if ( ! V_153 ) {
F_98 ( V_147 , V_97 , V_121 , V_52 ,
V_49 -> V_45 , V_151 ) ;
if ( V_151 && ! V_151 -> V_34 -> V_156 )
F_106 ( & V_151 -> V_73 ) ;
V_49 -> V_45 = V_151 ? : & V_46 ;
if ( V_151 && V_151 -> V_34 -> V_156 )
V_151 -> V_34 -> V_156 ( V_151 ) ;
} else {
F_98 ( V_147 , V_97 , V_121 , V_52 , V_150 , V_151 ) ;
}
if ( V_49 -> V_40 & V_155 )
F_107 ( V_49 ) ;
} else {
const struct V_18 * V_19 = V_42 -> V_34 -> V_17 ;
V_28 = - V_160 ;
if ( V_19 && V_19 -> V_161 ) {
unsigned long V_53 = V_19 -> V_20 ( V_42 , V_52 ) ;
if ( V_53 ) {
V_28 = V_19 -> V_161 ( V_42 , V_53 , V_151 , & V_150 ) ;
V_19 -> V_21 ( V_42 , V_53 ) ;
} else
V_28 = - V_29 ;
}
if ( ! V_28 )
F_98 ( V_147 , V_97 , V_121 , V_52 , V_150 , V_151 ) ;
}
return V_28 ;
}
static struct V_37 *
F_108 ( struct V_48 * V_49 , struct V_158 * V_159 ,
struct V_37 * V_51 , T_2 V_42 , T_2 V_39 ,
struct V_54 * * V_162 , int * V_163 )
{
int V_28 ;
struct V_54 * V_55 = V_162 [ V_164 ] ;
struct V_37 * V_126 ;
struct V_1 * V_34 ;
struct V_78 * V_82 ;
V_34 = F_26 ( V_55 ) ;
#ifdef F_109
if ( V_34 == NULL && V_55 != NULL ) {
char V_30 [ V_165 ] ;
if ( F_110 ( V_30 , V_55 , V_165 ) < V_165 ) {
F_111 () ;
F_13 ( L_1 , V_30 ) ;
F_112 () ;
V_34 = F_26 ( V_55 ) ;
if ( V_34 != NULL ) {
F_14 ( V_34 -> V_33 ) ;
V_28 = - V_166 ;
goto V_167;
}
}
}
#endif
V_28 = - V_29 ;
if ( V_34 == NULL )
goto V_167;
V_126 = F_113 ( V_159 , V_34 ) ;
if ( F_114 ( V_126 ) ) {
V_28 = F_115 ( V_126 ) ;
goto V_168;
}
V_126 -> V_42 = V_42 ;
if ( V_39 == V_144 ) {
V_126 -> V_40 |= V_44 ;
V_39 = F_91 ( V_144 , 0 ) ;
F_116 ( F_117 ( V_126 ) , & V_169 ) ;
} else {
if ( V_39 == 0 ) {
V_39 = F_90 ( V_49 ) ;
V_28 = - V_91 ;
if ( V_39 == 0 )
goto V_170;
}
F_116 ( F_117 ( V_126 ) , & V_171 ) ;
if ( ! F_118 ( V_49 ) )
V_126 -> V_40 |= V_172 ;
}
V_126 -> V_39 = V_39 ;
if ( ! V_34 -> V_173 || ( V_28 = V_34 -> V_173 ( V_126 , V_162 [ V_174 ] ) ) == 0 ) {
if ( F_119 ( V_126 ) ) {
V_126 -> V_175 =
F_120 ( struct V_176 ) ;
if ( ! V_126 -> V_175 )
goto V_177;
V_126 -> V_178 = F_121 ( struct V_179 ) ;
if ( ! V_126 -> V_178 )
goto V_177;
}
if ( V_162 [ V_99 ] ) {
V_82 = F_37 ( V_162 [ V_99 ] ) ;
if ( F_114 ( V_82 ) ) {
V_28 = F_115 ( V_82 ) ;
goto V_177;
}
F_122 ( V_126 -> V_82 , V_82 ) ;
}
if ( V_162 [ V_180 ] ) {
T_7 * V_181 ;
V_28 = - V_160 ;
if ( V_126 -> V_40 & V_182 )
goto V_177;
if ( ( V_126 -> V_42 != V_43 ) &&
! ( V_126 -> V_40 & V_44 ) &&
( ! V_51 || ! ( V_51 -> V_40 & V_182 ) ) )
V_181 = F_123 ( V_126 ) ;
else
V_181 = F_117 ( V_126 ) ;
V_28 = F_124 ( & V_126 -> V_183 ,
V_126 -> V_175 ,
& V_126 -> V_184 ,
V_181 ,
V_162 [ V_180 ] ) ;
if ( V_28 )
goto V_177;
}
F_17 ( V_126 ) ;
return V_126 ;
}
V_170:
F_125 ( V_49 ) ;
F_36 ( ( char * ) V_126 - V_126 -> V_185 ) ;
V_168:
F_14 ( V_34 -> V_33 ) ;
V_167:
* V_163 = V_28 ;
return NULL ;
V_177:
F_126 ( V_126 -> V_175 ) ;
F_126 ( V_126 -> V_178 ) ;
F_44 ( F_127 ( V_126 -> V_82 ) ) ;
if ( V_34 -> V_186 )
V_34 -> V_186 ( V_126 ) ;
goto V_170;
}
static int F_128 ( struct V_37 * V_126 , struct V_54 * * V_162 )
{
struct V_78 * V_187 , * V_82 = NULL ;
int V_28 = 0 ;
if ( V_162 [ V_174 ] ) {
if ( V_126 -> V_34 -> V_188 == NULL )
return - V_27 ;
V_28 = V_126 -> V_34 -> V_188 ( V_126 , V_162 [ V_174 ] ) ;
if ( V_28 )
return V_28 ;
}
if ( V_162 [ V_99 ] ) {
V_82 = F_37 ( V_162 [ V_99 ] ) ;
if ( F_114 ( V_82 ) )
return F_115 ( V_82 ) ;
}
V_187 = F_127 ( V_126 -> V_82 ) ;
F_122 ( V_126 -> V_82 , V_82 ) ;
F_44 ( V_187 ) ;
if ( V_162 [ V_180 ] ) {
if ( V_126 -> V_40 & V_182 )
goto V_11;
F_129 ( & V_126 -> V_183 ,
V_126 -> V_175 ,
& V_126 -> V_184 ,
F_123 ( V_126 ) ,
V_162 [ V_180 ] ) ;
}
V_11:
return 0 ;
}
static int F_130 ( struct V_37 * V_3 , struct V_37 * V_51 , int V_189 )
{
struct V_190 V_191 ;
if ( V_3 -> V_34 -> V_17 == NULL )
return 0 ;
V_191 . V_192 . V_193 = V_191 . V_192 . V_157 = V_191 . V_192 . V_194 = 0 ;
V_191 . V_192 . V_195 = V_196 ;
V_191 . V_189 = V_189 ;
V_191 . V_51 = V_51 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_191 . V_192 ) ;
return V_191 . V_192 . V_193 ? - V_197 : 0 ;
}
static int
V_196 ( struct V_37 * V_3 , unsigned long V_53 , struct V_198 * V_192 )
{
struct V_37 * V_23 ;
const struct V_18 * V_19 = V_3 -> V_34 -> V_17 ;
struct V_190 * V_191 = (struct V_190 * ) V_192 ;
V_23 = V_19 -> V_23 ( V_3 , V_53 ) ;
if ( V_23 ) {
if ( V_23 == V_191 -> V_51 || V_191 -> V_189 > 7 )
return - V_197 ;
return F_130 ( V_23 , V_191 -> V_51 , V_191 -> V_189 + 1 ) ;
}
return 0 ;
}
static int F_131 ( struct V_96 * V_97 , struct V_148 * V_121 )
{
struct V_147 * V_147 = F_132 ( V_97 -> V_199 ) ;
struct V_200 * V_201 = F_133 ( V_121 ) ;
struct V_54 * V_162 [ V_202 + 1 ] ;
struct V_48 * V_49 ;
T_2 V_149 ;
struct V_37 * V_3 = NULL ;
struct V_37 * V_51 = NULL ;
int V_28 ;
if ( ( V_121 -> V_203 != V_204 ) &&
! F_134 ( V_97 , V_147 -> V_205 , V_35 ) )
return - V_36 ;
V_28 = F_135 ( V_121 , sizeof( * V_201 ) , V_162 , V_202 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_49 = F_136 ( V_147 , V_201 -> V_206 ) ;
if ( ! V_49 )
return - V_207 ;
V_149 = V_201 -> V_208 ;
if ( V_149 ) {
if ( V_149 != V_43 ) {
if ( F_95 ( V_149 ) != F_95 ( V_144 ) ) {
V_51 = F_23 ( V_49 , F_95 ( V_149 ) ) ;
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
if ( V_201 -> V_209 && V_3 -> V_39 != V_201 -> V_209 )
return - V_27 ;
} else {
V_3 = F_23 ( V_49 , V_201 -> V_209 ) ;
if ( ! V_3 )
return - V_29 ;
}
if ( V_162 [ V_164 ] && F_27 ( V_162 [ V_164 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_121 -> V_203 == V_210 ) {
if ( ! V_149 )
return - V_27 ;
if ( V_3 -> V_39 == 0 )
return - V_29 ;
V_28 = F_101 ( V_49 , V_51 , V_97 , V_121 , V_149 , NULL , V_3 ) ;
if ( V_28 != 0 )
return V_28 ;
} else {
F_99 ( V_147 , V_97 , V_121 , V_149 , NULL , V_3 ) ;
}
return 0 ;
}
static int F_137 ( struct V_96 * V_97 , struct V_148 * V_121 )
{
struct V_147 * V_147 = F_132 ( V_97 -> V_199 ) ;
struct V_200 * V_201 ;
struct V_54 * V_162 [ V_202 + 1 ] ;
struct V_48 * V_49 ;
T_2 V_149 ;
struct V_37 * V_3 , * V_51 ;
int V_28 ;
if ( ! F_134 ( V_97 , V_147 -> V_205 , V_35 ) )
return - V_36 ;
V_211:
V_28 = F_135 ( V_121 , sizeof( * V_201 ) , V_162 , V_202 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_201 = F_133 ( V_121 ) ;
V_149 = V_201 -> V_208 ;
V_3 = V_51 = NULL ;
V_49 = F_136 ( V_147 , V_201 -> V_206 ) ;
if ( ! V_49 )
return - V_207 ;
if ( V_149 ) {
if ( V_149 != V_43 ) {
if ( V_149 != V_144 ) {
V_51 = F_23 ( V_49 , F_95 ( V_149 ) ) ;
if ( ! V_51 )
return - V_29 ;
V_3 = F_25 ( V_51 , V_149 ) ;
} else if ( F_138 ( V_49 ) ) {
V_3 = F_24 ( V_49 ) -> V_50 ;
}
} else {
V_3 = V_49 -> V_45 ;
}
if ( V_3 && V_3 -> V_39 == 0 )
V_3 = NULL ;
if ( ! V_3 || ! V_201 -> V_209 || V_3 -> V_39 != V_201 -> V_209 ) {
if ( V_201 -> V_209 ) {
if ( V_3 && ! ( V_121 -> V_212 & V_213 ) )
return - V_6 ;
if ( F_139 ( V_201 -> V_209 ) )
return - V_27 ;
V_3 = F_23 ( V_49 , V_201 -> V_209 ) ;
if ( ! V_3 )
goto V_214;
if ( V_121 -> V_212 & V_215 )
return - V_6 ;
if ( V_162 [ V_164 ] && F_27 ( V_162 [ V_164 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_3 == V_51 ||
( V_51 && F_130 ( V_3 , V_51 , 0 ) ) )
return - V_197 ;
F_106 ( & V_3 -> V_73 ) ;
goto V_161;
} else {
if ( ! V_3 )
goto V_214;
if ( ( V_121 -> V_212 & V_216 ) &&
( V_121 -> V_212 & V_213 ) &&
( ( V_121 -> V_212 & V_215 ) ||
( V_162 [ V_164 ] &&
F_27 ( V_162 [ V_164 ] , V_3 -> V_34 -> V_10 ) ) ) )
goto V_214;
}
}
} else {
if ( ! V_201 -> V_209 )
return - V_27 ;
V_3 = F_23 ( V_49 , V_201 -> V_209 ) ;
}
if ( V_3 == NULL )
return - V_29 ;
if ( V_121 -> V_212 & V_215 )
return - V_6 ;
if ( V_162 [ V_164 ] && F_27 ( V_162 [ V_164 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
V_28 = F_128 ( V_3 , V_162 ) ;
if ( V_28 == 0 )
F_99 ( V_147 , V_97 , V_121 , V_149 , NULL , V_3 ) ;
return V_28 ;
V_214:
if ( ! ( V_121 -> V_212 & V_216 ) )
return - V_29 ;
if ( V_149 == V_144 ) {
if ( F_24 ( V_49 ) )
V_3 = F_108 ( V_49 , F_24 ( V_49 ) , V_51 ,
V_201 -> V_208 , V_201 -> V_208 ,
V_162 , & V_28 ) ;
else
V_28 = - V_29 ;
} else {
struct V_158 * V_159 ;
if ( V_51 && V_51 -> V_34 -> V_17 && V_51 -> V_34 -> V_17 -> V_217 )
V_159 = V_51 -> V_34 -> V_17 -> V_217 ( V_51 , V_201 ) ;
else if ( V_51 )
V_159 = V_51 -> V_159 ;
else
V_159 = F_104 ( V_49 , 0 ) ;
V_3 = F_108 ( V_49 , V_159 , V_51 ,
V_201 -> V_208 , V_201 -> V_209 ,
V_162 , & V_28 ) ;
}
if ( V_3 == NULL ) {
if ( V_28 == - V_166 )
goto V_211;
return V_28 ;
}
V_161:
V_28 = F_101 ( V_49 , V_51 , V_97 , V_121 , V_149 , V_3 , NULL ) ;
if ( V_28 ) {
if ( V_3 )
F_100 ( V_3 ) ;
return V_28 ;
}
return 0 ;
}
static int F_140 ( struct V_96 * V_97 , struct V_37 * V_3 , T_2 V_149 ,
T_2 V_218 , T_2 V_219 , T_5 V_40 , int V_220 )
{
struct V_176 T_8 * V_175 = NULL ;
struct V_179 T_8 * V_178 = NULL ;
struct V_200 * V_201 ;
struct V_148 * V_221 ;
unsigned char * V_222 = F_141 ( V_97 ) ;
struct V_223 V_224 ;
struct V_78 * V_82 ;
T_4 V_146 ;
F_92 () ;
V_221 = F_142 ( V_97 , V_218 , V_219 , V_220 , sizeof( * V_201 ) , V_40 ) ;
if ( ! V_221 )
goto V_225;
V_201 = F_133 ( V_221 ) ;
V_201 -> V_226 = V_227 ;
V_201 -> V_228 = 0 ;
V_201 -> V_229 = 0 ;
V_201 -> V_206 = F_18 ( V_3 ) -> V_230 ;
V_201 -> V_208 = V_149 ;
V_201 -> V_209 = V_3 -> V_39 ;
V_201 -> V_231 = F_143 ( & V_3 -> V_73 ) ;
if ( F_144 ( V_97 , V_164 , V_3 -> V_34 -> V_10 ) )
goto V_100;
if ( V_3 -> V_34 -> V_232 && V_3 -> V_34 -> V_232 ( V_3 , V_97 ) < 0 )
goto V_100;
V_146 = V_3 -> V_3 . V_146 ;
V_82 = F_127 ( V_3 -> V_82 ) ;
if ( V_82 && F_46 ( V_97 , V_82 ) < 0 )
goto V_100;
if ( F_145 ( V_97 , V_233 , V_234 , V_235 ,
F_123 ( V_3 ) , & V_224 ) < 0 )
goto V_100;
if ( V_3 -> V_34 -> V_236 && V_3 -> V_34 -> V_236 ( V_3 , & V_224 ) < 0 )
goto V_100;
if ( F_119 ( V_3 ) ) {
V_175 = V_3 -> V_175 ;
V_178 = V_3 -> V_178 ;
}
if ( F_146 ( & V_224 , V_175 , & V_3 -> V_183 ) < 0 ||
F_147 ( & V_224 , & V_3 -> V_183 , & V_3 -> V_184 ) < 0 ||
F_148 ( & V_224 , V_178 , & V_3 -> V_237 , V_146 ) < 0 )
goto V_100;
if ( F_149 ( & V_224 ) < 0 )
goto V_100;
V_221 -> V_238 = F_141 ( V_97 ) - V_222 ;
return V_97 -> V_31 ;
V_225:
V_100:
F_150 ( V_97 , V_222 ) ;
return - 1 ;
}
static bool F_151 ( struct V_37 * V_3 )
{
return ( V_3 -> V_40 & V_41 ) ? true : false ;
}
static int F_99 ( struct V_147 * V_147 , struct V_96 * V_239 ,
struct V_148 * V_121 , T_2 V_149 ,
struct V_37 * V_150 , struct V_37 * V_151 )
{
struct V_96 * V_97 ;
T_2 V_218 = V_239 ? F_152 ( V_239 ) . V_218 : 0 ;
V_97 = F_153 ( V_240 , V_74 ) ;
if ( ! V_97 )
return - V_241 ;
if ( V_150 && ! F_151 ( V_150 ) ) {
if ( F_140 ( V_97 , V_150 , V_149 , V_218 , V_121 -> V_242 ,
0 , V_210 ) < 0 )
goto V_167;
}
if ( V_151 && ! F_151 ( V_151 ) ) {
if ( F_140 ( V_97 , V_151 , V_149 , V_218 , V_121 -> V_242 ,
V_150 ? V_213 : 0 , V_243 ) < 0 )
goto V_167;
}
if ( V_97 -> V_31 )
return F_154 ( V_97 , V_147 , V_218 , V_244 ,
V_121 -> V_212 & V_245 ) ;
V_167:
F_155 ( V_97 ) ;
return - V_27 ;
}
static int F_156 ( struct V_37 * V_38 , struct V_96 * V_97 ,
struct V_246 * V_247 ,
int * V_248 , int V_249 )
{
int V_250 = 0 , V_251 = * V_248 ;
struct V_37 * V_3 ;
if ( ! V_38 )
return 0 ;
V_3 = V_38 ;
if ( V_251 < V_249 ) {
V_251 ++ ;
} else {
if ( ! F_151 ( V_3 ) &&
F_140 ( V_97 , V_3 , V_3 -> V_42 , F_152 ( V_247 -> V_97 ) . V_218 ,
V_247 -> V_221 -> V_242 , V_252 , V_243 ) <= 0 )
goto V_253;
V_251 ++ ;
}
F_16 (q, &root->list, list) {
if ( V_251 < V_249 ) {
V_251 ++ ;
continue;
}
if ( ! F_151 ( V_3 ) &&
F_140 ( V_97 , V_3 , V_3 -> V_42 , F_152 ( V_247 -> V_97 ) . V_218 ,
V_247 -> V_221 -> V_242 , V_252 , V_243 ) <= 0 )
goto V_253;
V_251 ++ ;
}
V_11:
* V_248 = V_251 ;
return V_250 ;
V_253:
V_250 = - 1 ;
goto V_11;
}
static int F_157 ( struct V_96 * V_97 , struct V_246 * V_247 )
{
struct V_147 * V_147 = F_132 ( V_97 -> V_199 ) ;
int V_254 , V_251 ;
int V_255 , V_249 ;
struct V_48 * V_49 ;
V_255 = V_247 -> args [ 0 ] ;
V_249 = V_251 = V_247 -> args [ 1 ] ;
V_254 = 0 ;
F_158 () ;
F_159 (net, dev) {
struct V_158 * V_159 ;
if ( V_254 < V_255 )
goto V_256;
if ( V_254 > V_255 )
V_249 = 0 ;
V_251 = 0 ;
if ( F_156 ( V_49 -> V_45 , V_97 , V_247 , & V_251 , V_249 ) < 0 )
goto V_253;
V_159 = F_24 ( V_49 ) ;
if ( V_159 &&
F_156 ( V_159 -> V_50 , V_97 , V_247 ,
& V_251 , V_249 ) < 0 )
goto V_253;
V_256:
V_254 ++ ;
}
V_253:
V_247 -> args [ 0 ] = V_254 ;
V_247 -> args [ 1 ] = V_251 ;
return V_97 -> V_31 ;
}
static int F_160 ( struct V_96 * V_97 , struct V_148 * V_121 )
{
struct V_147 * V_147 = F_132 ( V_97 -> V_199 ) ;
struct V_200 * V_201 = F_133 ( V_121 ) ;
struct V_54 * V_162 [ V_202 + 1 ] ;
struct V_48 * V_49 ;
struct V_37 * V_3 = NULL ;
const struct V_18 * V_19 ;
unsigned long V_53 = 0 ;
unsigned long V_257 ;
T_2 V_218 ;
T_2 V_149 ;
T_2 V_258 ;
int V_28 ;
if ( ( V_121 -> V_203 != V_259 ) &&
! F_134 ( V_97 , V_147 -> V_205 , V_35 ) )
return - V_36 ;
V_28 = F_135 ( V_121 , sizeof( * V_201 ) , V_162 , V_202 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_49 = F_136 ( V_147 , V_201 -> V_206 ) ;
if ( ! V_49 )
return - V_207 ;
V_218 = V_201 -> V_208 ;
V_149 = V_201 -> V_209 ;
V_258 = F_95 ( V_149 ) ;
if ( V_218 != V_43 ) {
T_2 V_260 = F_95 ( V_218 ) ;
if ( V_258 && V_260 ) {
if ( V_258 != V_260 )
return - V_27 ;
} else if ( V_260 ) {
V_258 = V_260 ;
} else if ( V_258 == 0 )
V_258 = V_49 -> V_45 -> V_39 ;
if ( V_218 )
V_218 = F_91 ( V_258 , V_218 ) ;
} else {
if ( V_258 == 0 )
V_258 = V_49 -> V_45 -> V_39 ;
}
V_3 = F_23 ( V_49 , V_258 ) ;
if ( ! V_3 )
return - V_29 ;
V_19 = V_3 -> V_34 -> V_17 ;
if ( V_19 == NULL )
return - V_27 ;
if ( V_149 == 0 ) {
if ( V_218 == V_43 )
V_149 = V_258 ;
} else
V_149 = F_91 ( V_258 , V_149 ) ;
if ( V_149 )
V_53 = V_19 -> V_20 ( V_3 , V_149 ) ;
if ( V_53 == 0 ) {
V_28 = - V_29 ;
if ( V_121 -> V_203 != V_261 ||
! ( V_121 -> V_212 & V_216 ) )
goto V_11;
} else {
switch ( V_121 -> V_203 ) {
case V_261 :
V_28 = - V_6 ;
if ( V_121 -> V_212 & V_215 )
goto V_11;
break;
case V_262 :
V_28 = - V_160 ;
if ( V_19 -> V_263 )
V_28 = V_19 -> V_263 ( V_3 , V_53 ) ;
if ( V_28 == 0 )
F_161 ( V_147 , V_97 , V_121 , V_3 , V_53 , V_262 ) ;
goto V_11;
case V_259 :
V_28 = F_161 ( V_147 , V_97 , V_121 , V_3 , V_53 , V_261 ) ;
goto V_11;
default:
V_28 = - V_27 ;
goto V_11;
}
}
V_257 = V_53 ;
V_28 = - V_160 ;
if ( V_19 -> V_188 )
V_28 = V_19 -> V_188 ( V_3 , V_149 , V_218 , V_162 , & V_257 ) ;
if ( V_28 == 0 )
F_161 ( V_147 , V_97 , V_121 , V_3 , V_257 , V_261 ) ;
V_11:
if ( V_53 )
V_19 -> V_21 ( V_3 , V_53 ) ;
return V_28 ;
}
static int F_162 ( struct V_96 * V_97 , struct V_37 * V_3 ,
unsigned long V_53 ,
T_2 V_218 , T_2 V_219 , T_5 V_40 , int V_220 )
{
struct V_200 * V_201 ;
struct V_148 * V_221 ;
unsigned char * V_222 = F_141 ( V_97 ) ;
struct V_223 V_224 ;
const struct V_18 * V_17 = V_3 -> V_34 -> V_17 ;
F_92 () ;
V_221 = F_142 ( V_97 , V_218 , V_219 , V_220 , sizeof( * V_201 ) , V_40 ) ;
if ( ! V_221 )
goto V_225;
V_201 = F_133 ( V_221 ) ;
V_201 -> V_226 = V_227 ;
V_201 -> V_228 = 0 ;
V_201 -> V_229 = 0 ;
V_201 -> V_206 = F_18 ( V_3 ) -> V_230 ;
V_201 -> V_208 = V_3 -> V_39 ;
V_201 -> V_209 = V_3 -> V_39 ;
V_201 -> V_231 = 0 ;
if ( F_144 ( V_97 , V_164 , V_3 -> V_34 -> V_10 ) )
goto V_100;
if ( V_17 -> V_232 && V_17 -> V_232 ( V_3 , V_53 , V_97 , V_201 ) < 0 )
goto V_100;
if ( F_145 ( V_97 , V_233 , V_234 , V_235 ,
F_123 ( V_3 ) , & V_224 ) < 0 )
goto V_100;
if ( V_17 -> V_236 && V_17 -> V_236 ( V_3 , V_53 , & V_224 ) < 0 )
goto V_100;
if ( F_149 ( & V_224 ) < 0 )
goto V_100;
V_221 -> V_238 = F_141 ( V_97 ) - V_222 ;
return V_97 -> V_31 ;
V_225:
V_100:
F_150 ( V_97 , V_222 ) ;
return - 1 ;
}
static int F_161 ( struct V_147 * V_147 , struct V_96 * V_239 ,
struct V_148 * V_121 , struct V_37 * V_3 ,
unsigned long V_53 , int V_220 )
{
struct V_96 * V_97 ;
T_2 V_218 = V_239 ? F_152 ( V_239 ) . V_218 : 0 ;
V_97 = F_153 ( V_240 , V_74 ) ;
if ( ! V_97 )
return - V_241 ;
if ( F_162 ( V_97 , V_3 , V_53 , V_218 , V_121 -> V_242 , 0 , V_220 ) < 0 ) {
F_155 ( V_97 ) ;
return - V_27 ;
}
return F_154 ( V_97 , V_147 , V_218 , V_244 ,
V_121 -> V_212 & V_245 ) ;
}
static int F_163 ( struct V_37 * V_3 , unsigned long V_53 , struct V_198 * V_191 )
{
struct V_264 * V_265 = (struct V_264 * ) V_191 ;
return F_162 ( V_265 -> V_97 , V_3 , V_53 , F_152 ( V_265 -> V_247 -> V_97 ) . V_218 ,
V_265 -> V_247 -> V_221 -> V_242 , V_252 , V_261 ) ;
}
static int F_164 ( struct V_37 * V_3 , struct V_96 * V_97 ,
struct V_200 * V_201 , struct V_246 * V_247 ,
int * V_266 , int V_267 )
{
struct V_264 V_191 ;
if ( F_151 ( V_3 ) ||
* V_266 < V_267 || ! V_3 -> V_34 -> V_17 ||
( V_201 -> V_208 &&
F_95 ( V_201 -> V_208 ) != V_3 -> V_39 ) ) {
( * V_266 ) ++ ;
return 0 ;
}
if ( * V_266 > V_267 )
memset ( & V_247 -> args [ 1 ] , 0 , sizeof( V_247 -> args ) - sizeof( V_247 -> args [ 0 ] ) ) ;
V_191 . V_192 . V_195 = F_163 ;
V_191 . V_97 = V_97 ;
V_191 . V_247 = V_247 ;
V_191 . V_192 . V_193 = 0 ;
V_191 . V_192 . V_157 = V_247 -> args [ 1 ] ;
V_191 . V_192 . V_194 = 0 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_191 . V_192 ) ;
V_247 -> args [ 1 ] = V_191 . V_192 . V_194 ;
if ( V_191 . V_192 . V_193 )
return - 1 ;
( * V_266 ) ++ ;
return 0 ;
}
static int F_165 ( struct V_37 * V_38 , struct V_96 * V_97 ,
struct V_200 * V_201 , struct V_246 * V_247 ,
int * V_266 , int V_267 )
{
struct V_37 * V_3 ;
if ( ! V_38 )
return 0 ;
if ( F_164 ( V_38 , V_97 , V_201 , V_247 , V_266 , V_267 ) < 0 )
return - 1 ;
F_16 (q, &root->list, list) {
if ( F_164 ( V_3 , V_97 , V_201 , V_247 , V_266 , V_267 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_166 ( struct V_96 * V_97 , struct V_246 * V_247 )
{
struct V_200 * V_201 = F_133 ( V_247 -> V_221 ) ;
struct V_147 * V_147 = F_132 ( V_97 -> V_199 ) ;
struct V_158 * V_159 ;
struct V_48 * V_49 ;
int V_268 , V_267 ;
if ( V_238 ( V_247 -> V_221 ) < sizeof( * V_201 ) )
return 0 ;
V_49 = F_167 ( V_147 , V_201 -> V_206 ) ;
if ( ! V_49 )
return 0 ;
V_267 = V_247 -> args [ 0 ] ;
V_268 = 0 ;
if ( F_165 ( V_49 -> V_45 , V_97 , V_201 , V_247 , & V_268 , V_267 ) < 0 )
goto V_253;
V_159 = F_24 ( V_49 ) ;
if ( V_159 &&
F_165 ( V_159 -> V_50 , V_97 , V_201 , V_247 ,
& V_268 , V_267 ) < 0 )
goto V_253;
V_253:
V_247 -> args [ 0 ] = V_268 ;
F_125 ( V_49 ) ;
return V_97 -> V_31 ;
}
int F_168 ( struct V_96 * V_97 , const struct V_269 * V_270 ,
struct V_271 * V_272 , bool V_273 )
{
T_9 V_274 = F_169 ( V_97 ) ;
#ifdef F_170
const struct V_269 * V_275 = V_270 ;
int V_276 = 0 ;
V_277:
#endif
for (; V_270 ; V_270 = F_171 ( V_270 -> V_9 ) ) {
int V_28 ;
if ( V_270 -> V_274 != V_274 &&
V_270 -> V_274 != F_172 ( V_278 ) )
continue;
V_28 = V_270 -> V_279 ( V_97 , V_270 , V_272 ) ;
#ifdef F_170
if ( F_51 ( V_28 == V_280 && ! V_273 ) )
goto V_281;
#endif
if ( V_28 >= 0 )
return V_28 ;
}
return - 1 ;
#ifdef F_170
V_281:
if ( F_51 ( V_276 ++ >= V_282 ) ) {
F_173 ( L_5 ,
V_270 -> V_3 -> V_34 -> V_10 , V_270 -> V_283 & 0xffff ,
F_174 ( V_270 -> V_274 ) ) ;
return V_284 ;
}
V_270 = V_275 ;
goto V_277;
#endif
}
bool F_175 ( struct V_269 * V_270 , bool V_285 )
{
if ( V_270 -> V_34 -> V_186 ( V_270 , V_285 ) ) {
F_14 ( V_270 -> V_34 -> V_33 ) ;
F_176 ( V_270 , V_95 ) ;
return true ;
}
return false ;
}
void F_177 ( struct V_269 T_10 * * V_286 )
{
struct V_269 * V_270 ;
while ( ( V_270 = F_127 ( * V_286 ) ) != NULL ) {
F_178 ( * V_286 , V_270 -> V_9 ) ;
F_175 ( V_270 , true ) ;
}
}
static int F_179 ( struct V_287 * V_219 , void * V_288 )
{
F_180 ( V_219 , L_6 ,
( T_2 ) V_289 , ( T_2 ) F_181 ( 1 ) ,
1000000 ,
( T_2 ) V_290 / V_291 ) ;
return 0 ;
}
static int F_182 ( struct V_292 * V_292 , struct V_293 * V_293 )
{
return F_183 ( V_293 , F_179 , NULL ) ;
}
static int T_11 F_184 ( struct V_147 * V_147 )
{
struct V_294 * V_295 ;
V_295 = F_185 ( L_7 , 0 , V_147 -> V_296 , & V_297 ) ;
if ( V_295 == NULL )
return - V_91 ;
return 0 ;
}
static void T_12 F_186 ( struct V_147 * V_147 )
{
F_187 ( L_7 , V_147 -> V_296 ) ;
}
static int T_11 F_184 ( struct V_147 * V_147 )
{
return 0 ;
}
static void T_12 F_186 ( struct V_147 * V_147 )
{
}
static int T_13 F_188 ( void )
{
int V_28 ;
V_28 = F_189 ( & V_298 ) ;
if ( V_28 ) {
F_190 ( L_8
L_9 ) ;
return V_28 ;
}
F_1 ( & V_299 ) ;
F_1 ( & V_300 ) ;
F_1 ( & V_301 ) ;
F_1 ( & V_302 ) ;
F_1 ( & V_303 ) ;
F_1 ( & V_304 ) ;
F_191 ( V_305 , V_243 , F_137 , NULL , NULL ) ;
F_191 ( V_305 , V_210 , F_131 , NULL , NULL ) ;
F_191 ( V_305 , V_204 , F_131 , F_157 , NULL ) ;
F_191 ( V_305 , V_261 , F_160 , NULL , NULL ) ;
F_191 ( V_305 , V_262 , F_160 , NULL , NULL ) ;
F_191 ( V_305 , V_259 , F_160 , F_166 , NULL ) ;
return 0 ;
}
