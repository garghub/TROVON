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
F_72 ( & V_111 -> V_110 ,
F_73 ( V_116 ) ,
V_114 ) ;
}
void F_74 ( struct F_60 * V_111 )
{
F_75 ( & V_111 -> V_110 ) ;
F_62 ( V_111 -> V_45 ) ;
}
static struct V_120 * F_76 ( unsigned int V_121 )
{
unsigned int V_122 = V_121 * sizeof( struct V_120 ) , V_123 ;
struct V_120 * V_124 ;
if ( V_122 <= V_125 )
V_124 = F_35 ( V_122 , V_74 ) ;
else
V_124 = (struct V_120 * )
F_77 ( V_74 , F_78 ( V_122 ) ) ;
if ( V_124 != NULL ) {
for ( V_123 = 0 ; V_123 < V_121 ; V_123 ++ )
F_79 ( & V_124 [ V_123 ] ) ;
}
return V_124 ;
}
static void F_80 ( struct V_120 * V_124 , unsigned int V_121 )
{
unsigned int V_122 = V_121 * sizeof( struct V_120 ) ;
if ( V_122 <= V_125 )
F_37 ( V_124 ) ;
else
F_81 ( ( unsigned long ) V_124 , F_78 ( V_122 ) ) ;
}
void F_82 ( struct V_37 * V_126 , struct V_127 * V_128 )
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
V_131 = F_76 ( V_133 ) ;
if ( V_131 == NULL )
return;
V_132 = V_128 -> V_138 ;
V_135 = V_128 -> V_137 ;
F_83 ( V_126 ) ;
for ( V_123 = 0 ; V_123 < V_135 ; V_123 ++ ) {
F_84 (cl, next, &ohash[i], hnode) {
V_124 = F_85 ( V_53 -> V_52 , V_134 ) ;
F_86 ( & V_53 -> V_139 , & V_131 [ V_124 ] ) ;
}
}
V_128 -> V_138 = V_131 ;
V_128 -> V_137 = V_133 ;
V_128 -> V_140 = V_134 ;
F_87 ( V_126 ) ;
F_80 ( V_132 , V_135 ) ;
}
int F_88 ( struct V_127 * V_128 )
{
unsigned int V_122 = 4 ;
V_128 -> V_138 = F_76 ( V_122 ) ;
if ( V_128 -> V_138 == NULL )
return - V_91 ;
V_128 -> V_137 = V_122 ;
V_128 -> V_140 = V_122 - 1 ;
V_128 -> V_136 = 0 ;
return 0 ;
}
void F_89 ( struct V_127 * V_128 )
{
F_80 ( V_128 -> V_138 , V_128 -> V_137 ) ;
}
void F_90 ( struct V_127 * V_128 ,
struct V_129 * V_53 )
{
unsigned int V_124 ;
F_91 ( & V_53 -> V_139 ) ;
V_124 = F_85 ( V_53 -> V_52 , V_128 -> V_140 ) ;
F_86 ( & V_53 -> V_139 , & V_128 -> V_138 [ V_124 ] ) ;
V_128 -> V_136 ++ ;
}
void F_92 ( struct V_127 * V_128 ,
struct V_129 * V_53 )
{
F_93 ( & V_53 -> V_139 ) ;
V_128 -> V_136 -- ;
}
static T_2 F_94 ( struct V_48 * V_49 )
{
int V_123 = 0x8000 ;
static T_2 V_141 = F_95 ( 0x80000000U , 0 ) ;
do {
V_141 += F_95 ( 0x10000U , 0 ) ;
if ( V_141 == F_95 ( V_43 , 0 ) )
V_141 = F_95 ( 0x80000000U , 0 ) ;
if ( ! F_24 ( V_49 , V_141 ) )
return V_141 ;
F_96 () ;
} while ( -- V_123 > 0 );
return 0 ;
}
void F_97 ( struct V_37 * V_126 , unsigned int V_121 )
{
const struct V_18 * V_19 ;
unsigned long V_53 ;
T_2 V_142 ;
int V_143 ;
if ( V_121 == 0 )
return;
V_143 = F_98 ( int , V_121 , 0 ) ;
F_61 () ;
while ( ( V_142 = V_126 -> V_42 ) ) {
if ( F_99 ( V_142 ) == F_99 ( V_144 ) )
break;
if ( V_126 -> V_40 & V_145 )
break;
V_126 = F_24 ( F_18 ( V_126 ) , F_99 ( V_142 ) ) ;
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
F_100 ( V_126 , V_143 ) ;
}
F_65 () ;
}
static void F_101 ( struct V_148 * V_148 , struct V_96 * V_97 ,
struct V_149 * V_121 , T_2 V_150 ,
struct V_37 * V_151 , struct V_37 * V_152 )
{
if ( V_152 || V_151 )
F_102 ( V_148 , V_97 , V_121 , V_150 , V_151 , V_152 ) ;
if ( V_151 )
F_103 ( V_151 ) ;
}
static int F_104 ( struct V_48 * V_49 , struct V_37 * V_42 ,
struct V_96 * V_97 , struct V_149 * V_121 , T_2 V_52 ,
struct V_37 * V_152 , struct V_37 * V_151 )
{
struct V_37 * V_3 = V_151 ;
struct V_148 * V_148 = F_105 ( V_49 ) ;
int V_28 = 0 ;
if ( V_42 == NULL ) {
unsigned int V_123 , V_153 , V_154 ;
V_154 = 0 ;
V_153 = V_49 -> V_155 ;
if ( ( V_3 && V_3 -> V_40 & V_44 ) ||
( V_152 && V_152 -> V_40 & V_44 ) ) {
V_153 = 1 ;
V_154 = 1 ;
if ( ! F_25 ( V_49 ) )
return - V_29 ;
}
if ( V_49 -> V_40 & V_156 )
F_106 ( V_49 ) ;
if ( V_152 && V_152 -> V_34 -> V_157 )
goto V_158;
for ( V_123 = 0 ; V_123 < V_153 ; V_123 ++ ) {
struct V_159 * V_160 = F_25 ( V_49 ) ;
if ( ! V_154 )
V_160 = F_107 ( V_49 , V_123 ) ;
V_151 = F_108 ( V_160 , V_152 ) ;
if ( V_152 && V_123 > 0 )
F_109 ( & V_152 -> V_73 ) ;
if ( ! V_154 )
F_103 ( V_151 ) ;
}
V_158:
if ( ! V_154 ) {
F_101 ( V_148 , V_97 , V_121 , V_52 ,
V_49 -> V_45 , V_152 ) ;
if ( V_152 && ! V_152 -> V_34 -> V_157 )
F_109 ( & V_152 -> V_73 ) ;
V_49 -> V_45 = V_152 ? : & V_46 ;
if ( V_152 && V_152 -> V_34 -> V_157 )
V_152 -> V_34 -> V_157 ( V_152 ) ;
} else {
F_101 ( V_148 , V_97 , V_121 , V_52 , V_151 , V_152 ) ;
}
if ( V_49 -> V_40 & V_156 )
F_110 ( V_49 ) ;
} else {
const struct V_18 * V_19 = V_42 -> V_34 -> V_17 ;
V_28 = - V_161 ;
if ( V_19 && V_19 -> V_162 ) {
unsigned long V_53 = V_19 -> V_20 ( V_42 , V_52 ) ;
if ( V_53 ) {
V_28 = V_19 -> V_162 ( V_42 , V_53 , V_152 , & V_151 ) ;
V_19 -> V_21 ( V_42 , V_53 ) ;
} else
V_28 = - V_29 ;
}
if ( ! V_28 )
F_101 ( V_148 , V_97 , V_121 , V_52 , V_151 , V_152 ) ;
}
return V_28 ;
}
static struct V_37 *
F_111 ( struct V_48 * V_49 , struct V_159 * V_160 ,
struct V_37 * V_51 , T_2 V_42 , T_2 V_39 ,
struct V_54 * * V_163 , int * V_164 )
{
int V_28 ;
struct V_54 * V_55 = V_163 [ V_165 ] ;
struct V_37 * V_126 ;
struct V_1 * V_34 ;
struct V_78 * V_82 ;
V_34 = F_27 ( V_55 ) ;
#ifdef F_112
if ( V_34 == NULL && V_55 != NULL ) {
char V_30 [ V_166 ] ;
if ( F_113 ( V_30 , V_55 , V_166 ) < V_166 ) {
F_114 () ;
F_13 ( L_1 , V_30 ) ;
F_115 () ;
V_34 = F_27 ( V_55 ) ;
if ( V_34 != NULL ) {
F_14 ( V_34 -> V_33 ) ;
V_28 = - V_167 ;
goto V_168;
}
}
}
#endif
V_28 = - V_29 ;
if ( V_34 == NULL )
goto V_168;
V_126 = F_116 ( V_160 , V_34 ) ;
if ( F_117 ( V_126 ) ) {
V_28 = F_118 ( V_126 ) ;
goto V_169;
}
V_126 -> V_42 = V_42 ;
if ( V_39 == V_144 ) {
V_126 -> V_40 |= V_44 ;
V_39 = F_95 ( V_144 , 0 ) ;
F_119 ( F_120 ( V_126 ) , & V_170 ) ;
} else {
if ( V_39 == 0 ) {
V_39 = F_94 ( V_49 ) ;
V_28 = - V_91 ;
if ( V_39 == 0 )
goto V_171;
}
F_119 ( F_120 ( V_126 ) , & V_172 ) ;
if ( ! F_121 ( V_49 ) )
V_126 -> V_40 |= V_173 ;
}
V_126 -> V_39 = V_39 ;
if ( ! V_34 -> V_174 || ( V_28 = V_34 -> V_174 ( V_126 , V_163 [ V_175 ] ) ) == 0 ) {
if ( F_122 ( V_126 ) ) {
V_126 -> V_176 =
F_123 ( struct V_177 ) ;
if ( ! V_126 -> V_176 )
goto V_178;
V_126 -> V_179 = F_124 ( struct V_180 ) ;
if ( ! V_126 -> V_179 )
goto V_178;
}
if ( V_163 [ V_99 ] ) {
V_82 = F_38 ( V_163 [ V_99 ] ) ;
if ( F_117 ( V_82 ) ) {
V_28 = F_118 ( V_82 ) ;
goto V_178;
}
F_125 ( V_126 -> V_82 , V_82 ) ;
}
if ( V_163 [ V_181 ] ) {
T_7 * V_182 ;
V_28 = - V_161 ;
if ( V_126 -> V_40 & V_183 )
goto V_178;
if ( ( V_126 -> V_42 != V_43 ) &&
! ( V_126 -> V_40 & V_44 ) &&
( ! V_51 || ! ( V_51 -> V_40 & V_183 ) ) )
V_182 = F_126 ( V_126 ) ;
else
V_182 = F_120 ( V_126 ) ;
V_28 = F_127 ( & V_126 -> V_184 ,
V_126 -> V_176 ,
& V_126 -> V_185 ,
V_182 ,
V_163 [ V_181 ] ) ;
if ( V_28 )
goto V_178;
}
F_17 ( V_126 ) ;
return V_126 ;
}
V_171:
F_128 ( V_49 ) ;
F_37 ( ( char * ) V_126 - V_126 -> V_186 ) ;
V_169:
F_14 ( V_34 -> V_33 ) ;
V_168:
* V_164 = V_28 ;
return NULL ;
V_178:
F_129 ( V_126 -> V_176 ) ;
F_129 ( V_126 -> V_179 ) ;
F_47 ( F_130 ( V_126 -> V_82 ) ) ;
if ( V_34 -> V_187 )
V_34 -> V_187 ( V_126 ) ;
goto V_171;
}
static int F_131 ( struct V_37 * V_126 , struct V_54 * * V_163 )
{
struct V_78 * V_188 , * V_82 = NULL ;
int V_28 = 0 ;
if ( V_163 [ V_175 ] ) {
if ( V_126 -> V_34 -> V_189 == NULL )
return - V_27 ;
V_28 = V_126 -> V_34 -> V_189 ( V_126 , V_163 [ V_175 ] ) ;
if ( V_28 )
return V_28 ;
}
if ( V_163 [ V_99 ] ) {
V_82 = F_38 ( V_163 [ V_99 ] ) ;
if ( F_117 ( V_82 ) )
return F_118 ( V_82 ) ;
}
V_188 = F_130 ( V_126 -> V_82 ) ;
F_125 ( V_126 -> V_82 , V_82 ) ;
F_47 ( V_188 ) ;
if ( V_163 [ V_181 ] ) {
if ( V_126 -> V_40 & V_183 )
goto V_11;
F_132 ( & V_126 -> V_184 ,
V_126 -> V_176 ,
& V_126 -> V_185 ,
F_126 ( V_126 ) ,
V_163 [ V_181 ] ) ;
}
V_11:
return 0 ;
}
static int F_133 ( struct V_37 * V_3 , struct V_37 * V_51 , int V_190 )
{
struct V_191 V_192 ;
if ( V_3 -> V_34 -> V_17 == NULL )
return 0 ;
V_192 . V_193 . V_194 = V_192 . V_193 . V_158 = V_192 . V_193 . V_195 = 0 ;
V_192 . V_193 . V_196 = V_197 ;
V_192 . V_190 = V_190 ;
V_192 . V_51 = V_51 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_192 . V_193 ) ;
return V_192 . V_193 . V_194 ? - V_198 : 0 ;
}
static int
V_197 ( struct V_37 * V_3 , unsigned long V_53 , struct V_199 * V_193 )
{
struct V_37 * V_23 ;
const struct V_18 * V_19 = V_3 -> V_34 -> V_17 ;
struct V_191 * V_192 = (struct V_191 * ) V_193 ;
V_23 = V_19 -> V_23 ( V_3 , V_53 ) ;
if ( V_23 ) {
if ( V_23 == V_192 -> V_51 || V_192 -> V_190 > 7 )
return - V_198 ;
return F_133 ( V_23 , V_192 -> V_51 , V_192 -> V_190 + 1 ) ;
}
return 0 ;
}
static int F_134 ( struct V_96 * V_97 , struct V_149 * V_121 )
{
struct V_148 * V_148 = F_135 ( V_97 -> V_200 ) ;
struct V_201 * V_202 = F_136 ( V_121 ) ;
struct V_54 * V_163 [ V_203 + 1 ] ;
struct V_48 * V_49 ;
T_2 V_150 ;
struct V_37 * V_3 = NULL ;
struct V_37 * V_51 = NULL ;
int V_28 ;
if ( ( V_121 -> V_204 != V_205 ) &&
! F_137 ( V_97 , V_148 -> V_206 , V_35 ) )
return - V_36 ;
V_28 = F_138 ( V_121 , sizeof( * V_202 ) , V_163 , V_203 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_49 = F_139 ( V_148 , V_202 -> V_207 ) ;
if ( ! V_49 )
return - V_208 ;
V_150 = V_202 -> V_209 ;
if ( V_150 ) {
if ( V_150 != V_43 ) {
if ( F_99 ( V_150 ) != F_99 ( V_144 ) ) {
V_51 = F_24 ( V_49 , F_99 ( V_150 ) ) ;
if ( ! V_51 )
return - V_29 ;
V_3 = F_26 ( V_51 , V_150 ) ;
} else if ( F_25 ( V_49 ) ) {
V_3 = F_25 ( V_49 ) -> V_50 ;
}
} else {
V_3 = V_49 -> V_45 ;
}
if ( ! V_3 )
return - V_29 ;
if ( V_202 -> V_210 && V_3 -> V_39 != V_202 -> V_210 )
return - V_27 ;
} else {
V_3 = F_24 ( V_49 , V_202 -> V_210 ) ;
if ( ! V_3 )
return - V_29 ;
}
if ( V_163 [ V_165 ] && F_28 ( V_163 [ V_165 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_121 -> V_204 == V_211 ) {
if ( ! V_150 )
return - V_27 ;
if ( V_3 -> V_39 == 0 )
return - V_29 ;
V_28 = F_104 ( V_49 , V_51 , V_97 , V_121 , V_150 , NULL , V_3 ) ;
if ( V_28 != 0 )
return V_28 ;
} else {
F_102 ( V_148 , V_97 , V_121 , V_150 , NULL , V_3 ) ;
}
return 0 ;
}
static int F_140 ( struct V_96 * V_97 , struct V_149 * V_121 )
{
struct V_148 * V_148 = F_135 ( V_97 -> V_200 ) ;
struct V_201 * V_202 ;
struct V_54 * V_163 [ V_203 + 1 ] ;
struct V_48 * V_49 ;
T_2 V_150 ;
struct V_37 * V_3 , * V_51 ;
int V_28 ;
if ( ! F_137 ( V_97 , V_148 -> V_206 , V_35 ) )
return - V_36 ;
V_212:
V_28 = F_138 ( V_121 , sizeof( * V_202 ) , V_163 , V_203 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_202 = F_136 ( V_121 ) ;
V_150 = V_202 -> V_209 ;
V_3 = V_51 = NULL ;
V_49 = F_139 ( V_148 , V_202 -> V_207 ) ;
if ( ! V_49 )
return - V_208 ;
if ( V_150 ) {
if ( V_150 != V_43 ) {
if ( V_150 != V_144 ) {
V_51 = F_24 ( V_49 , F_99 ( V_150 ) ) ;
if ( ! V_51 )
return - V_29 ;
V_3 = F_26 ( V_51 , V_150 ) ;
} else if ( F_141 ( V_49 ) ) {
V_3 = F_25 ( V_49 ) -> V_50 ;
}
} else {
V_3 = V_49 -> V_45 ;
}
if ( V_3 && V_3 -> V_39 == 0 )
V_3 = NULL ;
if ( ! V_3 || ! V_202 -> V_210 || V_3 -> V_39 != V_202 -> V_210 ) {
if ( V_202 -> V_210 ) {
if ( V_3 && ! ( V_121 -> V_213 & V_214 ) )
return - V_6 ;
if ( F_142 ( V_202 -> V_210 ) )
return - V_27 ;
V_3 = F_24 ( V_49 , V_202 -> V_210 ) ;
if ( ! V_3 )
goto V_215;
if ( V_121 -> V_213 & V_216 )
return - V_6 ;
if ( V_163 [ V_165 ] && F_28 ( V_163 [ V_165 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_3 == V_51 ||
( V_51 && F_133 ( V_3 , V_51 , 0 ) ) )
return - V_198 ;
F_109 ( & V_3 -> V_73 ) ;
goto V_162;
} else {
if ( ! V_3 )
goto V_215;
if ( ( V_121 -> V_213 & V_217 ) &&
( V_121 -> V_213 & V_214 ) &&
( ( V_121 -> V_213 & V_216 ) ||
( V_163 [ V_165 ] &&
F_28 ( V_163 [ V_165 ] , V_3 -> V_34 -> V_10 ) ) ) )
goto V_215;
}
}
} else {
if ( ! V_202 -> V_210 )
return - V_27 ;
V_3 = F_24 ( V_49 , V_202 -> V_210 ) ;
}
if ( V_3 == NULL )
return - V_29 ;
if ( V_121 -> V_213 & V_216 )
return - V_6 ;
if ( V_163 [ V_165 ] && F_28 ( V_163 [ V_165 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
V_28 = F_131 ( V_3 , V_163 ) ;
if ( V_28 == 0 )
F_102 ( V_148 , V_97 , V_121 , V_150 , NULL , V_3 ) ;
return V_28 ;
V_215:
if ( ! ( V_121 -> V_213 & V_217 ) )
return - V_29 ;
if ( V_150 == V_144 ) {
if ( F_25 ( V_49 ) )
V_3 = F_111 ( V_49 , F_25 ( V_49 ) , V_51 ,
V_202 -> V_209 , V_202 -> V_209 ,
V_163 , & V_28 ) ;
else
V_28 = - V_29 ;
} else {
struct V_159 * V_160 ;
if ( V_51 && V_51 -> V_34 -> V_17 && V_51 -> V_34 -> V_17 -> V_218 )
V_160 = V_51 -> V_34 -> V_17 -> V_218 ( V_51 , V_202 ) ;
else if ( V_51 )
V_160 = V_51 -> V_160 ;
else
V_160 = F_107 ( V_49 , 0 ) ;
V_3 = F_111 ( V_49 , V_160 , V_51 ,
V_202 -> V_209 , V_202 -> V_210 ,
V_163 , & V_28 ) ;
}
if ( V_3 == NULL ) {
if ( V_28 == - V_167 )
goto V_212;
return V_28 ;
}
V_162:
V_28 = F_104 ( V_49 , V_51 , V_97 , V_121 , V_150 , V_3 , NULL ) ;
if ( V_28 ) {
if ( V_3 )
F_103 ( V_3 ) ;
return V_28 ;
}
return 0 ;
}
static int F_143 ( struct V_96 * V_97 , struct V_37 * V_3 , T_2 V_150 ,
T_2 V_219 , T_2 V_220 , T_5 V_40 , int V_221 )
{
struct V_177 T_8 * V_176 = NULL ;
struct V_180 T_8 * V_179 = NULL ;
struct V_201 * V_202 ;
struct V_149 * V_222 ;
unsigned char * V_223 = F_144 ( V_97 ) ;
struct V_224 V_225 ;
struct V_78 * V_82 ;
T_4 V_147 ;
F_96 () ;
V_222 = F_145 ( V_97 , V_219 , V_220 , V_221 , sizeof( * V_202 ) , V_40 ) ;
if ( ! V_222 )
goto V_226;
V_202 = F_136 ( V_222 ) ;
V_202 -> V_227 = V_228 ;
V_202 -> V_229 = 0 ;
V_202 -> V_230 = 0 ;
V_202 -> V_207 = F_18 ( V_3 ) -> V_231 ;
V_202 -> V_209 = V_150 ;
V_202 -> V_210 = V_3 -> V_39 ;
V_202 -> V_232 = F_146 ( & V_3 -> V_73 ) ;
if ( F_147 ( V_97 , V_165 , V_3 -> V_34 -> V_10 ) )
goto V_100;
if ( V_3 -> V_34 -> V_233 && V_3 -> V_34 -> V_233 ( V_3 , V_97 ) < 0 )
goto V_100;
V_147 = V_3 -> V_3 . V_147 ;
V_82 = F_130 ( V_3 -> V_82 ) ;
if ( V_82 && F_50 ( V_97 , V_82 ) < 0 )
goto V_100;
if ( F_148 ( V_97 , V_234 , V_235 , V_236 ,
F_126 ( V_3 ) , & V_225 ) < 0 )
goto V_100;
if ( V_3 -> V_34 -> V_237 && V_3 -> V_34 -> V_237 ( V_3 , & V_225 ) < 0 )
goto V_100;
if ( F_122 ( V_3 ) ) {
V_176 = V_3 -> V_176 ;
V_179 = V_3 -> V_179 ;
}
if ( F_149 ( & V_225 , V_176 , & V_3 -> V_184 ) < 0 ||
F_150 ( & V_225 , & V_3 -> V_184 , & V_3 -> V_185 ) < 0 ||
F_151 ( & V_225 , V_179 , & V_3 -> V_238 , V_147 ) < 0 )
goto V_100;
if ( F_152 ( & V_225 ) < 0 )
goto V_100;
V_222 -> V_239 = F_144 ( V_97 ) - V_223 ;
return V_97 -> V_31 ;
V_226:
V_100:
F_153 ( V_97 , V_223 ) ;
return - 1 ;
}
static bool F_154 ( struct V_37 * V_3 )
{
return ( V_3 -> V_40 & V_41 ) ? true : false ;
}
static int F_102 ( struct V_148 * V_148 , struct V_96 * V_240 ,
struct V_149 * V_121 , T_2 V_150 ,
struct V_37 * V_151 , struct V_37 * V_152 )
{
struct V_96 * V_97 ;
T_2 V_219 = V_240 ? F_155 ( V_240 ) . V_219 : 0 ;
V_97 = F_156 ( V_241 , V_74 ) ;
if ( ! V_97 )
return - V_242 ;
if ( V_151 && ! F_154 ( V_151 ) ) {
if ( F_143 ( V_97 , V_151 , V_150 , V_219 , V_121 -> V_243 ,
0 , V_211 ) < 0 )
goto V_168;
}
if ( V_152 && ! F_154 ( V_152 ) ) {
if ( F_143 ( V_97 , V_152 , V_150 , V_219 , V_121 -> V_243 ,
V_151 ? V_214 : 0 , V_244 ) < 0 )
goto V_168;
}
if ( V_97 -> V_31 )
return F_157 ( V_97 , V_148 , V_219 , V_245 ,
V_121 -> V_213 & V_246 ) ;
V_168:
F_158 ( V_97 ) ;
return - V_27 ;
}
static int F_159 ( struct V_37 * V_38 , struct V_96 * V_97 ,
struct V_247 * V_248 ,
int * V_249 , int V_250 )
{
int V_251 = 0 , V_252 = * V_249 ;
struct V_37 * V_3 ;
if ( ! V_38 )
return 0 ;
V_3 = V_38 ;
if ( V_252 < V_250 ) {
V_252 ++ ;
} else {
if ( ! F_154 ( V_3 ) &&
F_143 ( V_97 , V_3 , V_3 -> V_42 , F_155 ( V_248 -> V_97 ) . V_219 ,
V_248 -> V_222 -> V_243 , V_253 , V_244 ) <= 0 )
goto V_254;
V_252 ++ ;
}
F_42 (q, &root->list, list) {
if ( V_252 < V_250 ) {
V_252 ++ ;
continue;
}
if ( ! F_154 ( V_3 ) &&
F_143 ( V_97 , V_3 , V_3 -> V_42 , F_155 ( V_248 -> V_97 ) . V_219 ,
V_248 -> V_222 -> V_243 , V_253 , V_244 ) <= 0 )
goto V_254;
V_252 ++ ;
}
V_11:
* V_249 = V_252 ;
return V_251 ;
V_254:
V_251 = - 1 ;
goto V_11;
}
static int F_160 ( struct V_96 * V_97 , struct V_247 * V_248 )
{
struct V_148 * V_148 = F_135 ( V_97 -> V_200 ) ;
int V_255 , V_252 ;
int V_256 , V_250 ;
struct V_48 * V_49 ;
V_256 = V_248 -> args [ 0 ] ;
V_250 = V_252 = V_248 -> args [ 1 ] ;
V_255 = 0 ;
F_20 () ;
F_161 (net, dev) {
struct V_159 * V_160 ;
if ( V_255 < V_256 )
goto V_257;
if ( V_255 > V_256 )
V_250 = 0 ;
V_252 = 0 ;
if ( F_159 ( V_49 -> V_45 , V_97 , V_248 , & V_252 , V_250 ) < 0 )
goto V_254;
V_160 = F_25 ( V_49 ) ;
if ( V_160 &&
F_159 ( V_160 -> V_50 , V_97 , V_248 ,
& V_252 , V_250 ) < 0 )
goto V_254;
V_257:
V_255 ++ ;
}
V_254:
V_248 -> args [ 0 ] = V_255 ;
V_248 -> args [ 1 ] = V_252 ;
return V_97 -> V_31 ;
}
static int F_162 ( struct V_96 * V_97 , struct V_149 * V_121 )
{
struct V_148 * V_148 = F_135 ( V_97 -> V_200 ) ;
struct V_201 * V_202 = F_136 ( V_121 ) ;
struct V_54 * V_163 [ V_203 + 1 ] ;
struct V_48 * V_49 ;
struct V_37 * V_3 = NULL ;
const struct V_18 * V_19 ;
unsigned long V_53 = 0 ;
unsigned long V_258 ;
T_2 V_219 ;
T_2 V_150 ;
T_2 V_259 ;
int V_28 ;
if ( ( V_121 -> V_204 != V_260 ) &&
! F_137 ( V_97 , V_148 -> V_206 , V_35 ) )
return - V_36 ;
V_28 = F_138 ( V_121 , sizeof( * V_202 ) , V_163 , V_203 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_49 = F_139 ( V_148 , V_202 -> V_207 ) ;
if ( ! V_49 )
return - V_208 ;
V_219 = V_202 -> V_209 ;
V_150 = V_202 -> V_210 ;
V_259 = F_99 ( V_150 ) ;
if ( V_219 != V_43 ) {
T_2 V_261 = F_99 ( V_219 ) ;
if ( V_259 && V_261 ) {
if ( V_259 != V_261 )
return - V_27 ;
} else if ( V_261 ) {
V_259 = V_261 ;
} else if ( V_259 == 0 )
V_259 = V_49 -> V_45 -> V_39 ;
if ( V_219 )
V_219 = F_95 ( V_259 , V_219 ) ;
} else {
if ( V_259 == 0 )
V_259 = V_49 -> V_45 -> V_39 ;
}
V_3 = F_24 ( V_49 , V_259 ) ;
if ( ! V_3 )
return - V_29 ;
V_19 = V_3 -> V_34 -> V_17 ;
if ( V_19 == NULL )
return - V_27 ;
if ( V_150 == 0 ) {
if ( V_219 == V_43 )
V_150 = V_259 ;
} else
V_150 = F_95 ( V_259 , V_150 ) ;
if ( V_150 )
V_53 = V_19 -> V_20 ( V_3 , V_150 ) ;
if ( V_53 == 0 ) {
V_28 = - V_29 ;
if ( V_121 -> V_204 != V_262 ||
! ( V_121 -> V_213 & V_217 ) )
goto V_11;
} else {
switch ( V_121 -> V_204 ) {
case V_262 :
V_28 = - V_6 ;
if ( V_121 -> V_213 & V_216 )
goto V_11;
break;
case V_263 :
V_28 = - V_161 ;
if ( V_19 -> V_264 )
V_28 = V_19 -> V_264 ( V_3 , V_53 ) ;
if ( V_28 == 0 )
F_163 ( V_148 , V_97 , V_121 , V_3 , V_53 , V_263 ) ;
goto V_11;
case V_260 :
V_28 = F_163 ( V_148 , V_97 , V_121 , V_3 , V_53 , V_262 ) ;
goto V_11;
default:
V_28 = - V_27 ;
goto V_11;
}
}
V_258 = V_53 ;
V_28 = - V_161 ;
if ( V_19 -> V_189 )
V_28 = V_19 -> V_189 ( V_3 , V_150 , V_219 , V_163 , & V_258 ) ;
if ( V_28 == 0 )
F_163 ( V_148 , V_97 , V_121 , V_3 , V_258 , V_262 ) ;
V_11:
if ( V_53 )
V_19 -> V_21 ( V_3 , V_53 ) ;
return V_28 ;
}
static int F_164 ( struct V_96 * V_97 , struct V_37 * V_3 ,
unsigned long V_53 ,
T_2 V_219 , T_2 V_220 , T_5 V_40 , int V_221 )
{
struct V_201 * V_202 ;
struct V_149 * V_222 ;
unsigned char * V_223 = F_144 ( V_97 ) ;
struct V_224 V_225 ;
const struct V_18 * V_17 = V_3 -> V_34 -> V_17 ;
F_96 () ;
V_222 = F_145 ( V_97 , V_219 , V_220 , V_221 , sizeof( * V_202 ) , V_40 ) ;
if ( ! V_222 )
goto V_226;
V_202 = F_136 ( V_222 ) ;
V_202 -> V_227 = V_228 ;
V_202 -> V_229 = 0 ;
V_202 -> V_230 = 0 ;
V_202 -> V_207 = F_18 ( V_3 ) -> V_231 ;
V_202 -> V_209 = V_3 -> V_39 ;
V_202 -> V_210 = V_3 -> V_39 ;
V_202 -> V_232 = 0 ;
if ( F_147 ( V_97 , V_165 , V_3 -> V_34 -> V_10 ) )
goto V_100;
if ( V_17 -> V_233 && V_17 -> V_233 ( V_3 , V_53 , V_97 , V_202 ) < 0 )
goto V_100;
if ( F_148 ( V_97 , V_234 , V_235 , V_236 ,
F_126 ( V_3 ) , & V_225 ) < 0 )
goto V_100;
if ( V_17 -> V_237 && V_17 -> V_237 ( V_3 , V_53 , & V_225 ) < 0 )
goto V_100;
if ( F_152 ( & V_225 ) < 0 )
goto V_100;
V_222 -> V_239 = F_144 ( V_97 ) - V_223 ;
return V_97 -> V_31 ;
V_226:
V_100:
F_153 ( V_97 , V_223 ) ;
return - 1 ;
}
static int F_163 ( struct V_148 * V_148 , struct V_96 * V_240 ,
struct V_149 * V_121 , struct V_37 * V_3 ,
unsigned long V_53 , int V_221 )
{
struct V_96 * V_97 ;
T_2 V_219 = V_240 ? F_155 ( V_240 ) . V_219 : 0 ;
V_97 = F_156 ( V_241 , V_74 ) ;
if ( ! V_97 )
return - V_242 ;
if ( F_164 ( V_97 , V_3 , V_53 , V_219 , V_121 -> V_243 , 0 , V_221 ) < 0 ) {
F_158 ( V_97 ) ;
return - V_27 ;
}
return F_157 ( V_97 , V_148 , V_219 , V_245 ,
V_121 -> V_213 & V_246 ) ;
}
static int F_165 ( struct V_37 * V_3 , unsigned long V_53 , struct V_199 * V_192 )
{
struct V_265 * V_266 = (struct V_265 * ) V_192 ;
return F_164 ( V_266 -> V_97 , V_3 , V_53 , F_155 ( V_266 -> V_248 -> V_97 ) . V_219 ,
V_266 -> V_248 -> V_222 -> V_243 , V_253 , V_262 ) ;
}
static int F_166 ( struct V_37 * V_3 , struct V_96 * V_97 ,
struct V_201 * V_202 , struct V_247 * V_248 ,
int * V_267 , int V_268 )
{
struct V_265 V_192 ;
if ( F_154 ( V_3 ) ||
* V_267 < V_268 || ! V_3 -> V_34 -> V_17 ||
( V_202 -> V_209 &&
F_99 ( V_202 -> V_209 ) != V_3 -> V_39 ) ) {
( * V_267 ) ++ ;
return 0 ;
}
if ( * V_267 > V_268 )
memset ( & V_248 -> args [ 1 ] , 0 , sizeof( V_248 -> args ) - sizeof( V_248 -> args [ 0 ] ) ) ;
V_192 . V_193 . V_196 = F_165 ;
V_192 . V_97 = V_97 ;
V_192 . V_248 = V_248 ;
V_192 . V_193 . V_194 = 0 ;
V_192 . V_193 . V_158 = V_248 -> args [ 1 ] ;
V_192 . V_193 . V_195 = 0 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_192 . V_193 ) ;
V_248 -> args [ 1 ] = V_192 . V_193 . V_195 ;
if ( V_192 . V_193 . V_194 )
return - 1 ;
( * V_267 ) ++ ;
return 0 ;
}
static int F_167 ( struct V_37 * V_38 , struct V_96 * V_97 ,
struct V_201 * V_202 , struct V_247 * V_248 ,
int * V_267 , int V_268 )
{
struct V_37 * V_3 ;
if ( ! V_38 )
return 0 ;
if ( F_166 ( V_38 , V_97 , V_202 , V_248 , V_267 , V_268 ) < 0 )
return - 1 ;
F_42 (q, &root->list, list) {
if ( F_166 ( V_3 , V_97 , V_202 , V_248 , V_267 , V_268 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_168 ( struct V_96 * V_97 , struct V_247 * V_248 )
{
struct V_201 * V_202 = F_136 ( V_248 -> V_222 ) ;
struct V_148 * V_148 = F_135 ( V_97 -> V_200 ) ;
struct V_159 * V_160 ;
struct V_48 * V_49 ;
int V_269 , V_268 ;
if ( V_239 ( V_248 -> V_222 ) < sizeof( * V_202 ) )
return 0 ;
V_49 = F_169 ( V_148 , V_202 -> V_207 ) ;
if ( ! V_49 )
return 0 ;
V_268 = V_248 -> args [ 0 ] ;
V_269 = 0 ;
if ( F_167 ( V_49 -> V_45 , V_97 , V_202 , V_248 , & V_269 , V_268 ) < 0 )
goto V_254;
V_160 = F_25 ( V_49 ) ;
if ( V_160 &&
F_167 ( V_160 -> V_50 , V_97 , V_202 , V_248 ,
& V_269 , V_268 ) < 0 )
goto V_254;
V_254:
V_248 -> args [ 0 ] = V_269 ;
F_128 ( V_49 ) ;
return V_97 -> V_31 ;
}
int F_170 ( struct V_96 * V_97 , const struct V_270 * V_271 ,
struct V_272 * V_273 , bool V_274 )
{
T_9 V_275 = F_171 ( V_97 ) ;
#ifdef F_172
const struct V_270 * V_276 = V_271 ;
int V_277 = 0 ;
V_278:
#endif
for (; V_271 ; V_271 = F_173 ( V_271 -> V_9 ) ) {
int V_28 ;
if ( V_271 -> V_275 != V_275 &&
V_271 -> V_275 != F_174 ( V_279 ) )
continue;
V_28 = V_271 -> V_280 ( V_97 , V_271 , V_273 ) ;
#ifdef F_172
if ( F_55 ( V_28 == V_281 && ! V_274 ) )
goto V_282;
#endif
if ( V_28 >= 0 )
return V_28 ;
}
return - 1 ;
#ifdef F_172
V_282:
if ( F_55 ( V_277 ++ >= V_283 ) ) {
F_175 ( L_5 ,
V_271 -> V_3 -> V_34 -> V_10 , V_271 -> V_284 & 0xffff ,
F_176 ( V_271 -> V_275 ) ) ;
return V_285 ;
}
V_271 = V_276 ;
V_275 = F_171 ( V_97 ) ;
goto V_278;
#endif
}
bool F_177 ( struct V_270 * V_271 , bool V_286 )
{
if ( V_271 -> V_34 -> V_187 ( V_271 , V_286 ) ) {
F_14 ( V_271 -> V_34 -> V_33 ) ;
F_178 ( V_271 , V_95 ) ;
return true ;
}
return false ;
}
void F_179 ( struct V_270 T_10 * * V_287 )
{
struct V_270 * V_271 ;
while ( ( V_271 = F_130 ( * V_287 ) ) != NULL ) {
F_180 ( * V_287 , V_271 -> V_9 ) ;
F_177 ( V_271 , true ) ;
}
}
static int F_181 ( struct V_288 * V_220 , void * V_289 )
{
F_182 ( V_220 , L_6 ,
( T_2 ) V_290 , ( T_2 ) F_183 ( 1 ) ,
1000000 ,
( T_2 ) V_291 / V_292 ) ;
return 0 ;
}
static int F_184 ( struct V_293 * V_293 , struct V_294 * V_294 )
{
return F_185 ( V_294 , F_181 , NULL ) ;
}
static int T_11 F_186 ( struct V_148 * V_148 )
{
struct V_295 * V_296 ;
V_296 = F_187 ( L_7 , 0 , V_148 -> V_297 , & V_298 ) ;
if ( V_296 == NULL )
return - V_91 ;
return 0 ;
}
static void T_12 F_188 ( struct V_148 * V_148 )
{
F_189 ( L_7 , V_148 -> V_297 ) ;
}
static int T_11 F_186 ( struct V_148 * V_148 )
{
return 0 ;
}
static void T_12 F_188 ( struct V_148 * V_148 )
{
}
static int T_13 F_190 ( void )
{
int V_28 ;
V_28 = F_191 ( & V_299 ) ;
if ( V_28 ) {
F_192 ( L_8
L_9 ) ;
return V_28 ;
}
F_1 ( & V_300 ) ;
F_1 ( & V_301 ) ;
F_1 ( & V_302 ) ;
F_1 ( & V_303 ) ;
F_1 ( & V_304 ) ;
F_1 ( & V_305 ) ;
F_193 ( V_306 , V_244 , F_140 , NULL , NULL ) ;
F_193 ( V_306 , V_211 , F_134 , NULL , NULL ) ;
F_193 ( V_306 , V_205 , F_134 , F_160 , NULL ) ;
F_193 ( V_306 , V_262 , F_162 , NULL , NULL ) ;
F_193 ( V_306 , V_263 , F_162 , NULL , NULL ) ;
F_193 ( V_306 , V_260 , F_162 , F_168 , NULL ) ;
return 0 ;
}
