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
if ( ! F_16 ( V_38 ) )
return ( V_38 -> V_39 == V_39 ? V_38 : NULL ) ;
if ( ! ( V_38 -> V_40 & V_41 ) &&
V_38 -> V_39 == V_39 )
return V_38 ;
F_17 (qdisc_dev(root)->qdisc_hash, q, hash, handle) {
if ( V_3 -> V_39 == V_39 )
return V_3 ;
}
return NULL ;
}
void F_18 ( struct V_37 * V_3 )
{
if ( ( V_3 -> V_42 != V_43 ) && ! ( V_3 -> V_40 & V_44 ) ) {
struct V_37 * V_38 = F_16 ( V_3 ) -> V_45 ;
F_19 ( V_38 == & V_46 ) ;
F_20 () ;
F_21 ( F_16 ( V_3 ) -> V_47 , & V_3 -> V_48 , V_3 -> V_39 ) ;
}
}
void F_22 ( struct V_37 * V_3 )
{
if ( ( V_3 -> V_42 != V_43 ) && ! ( V_3 -> V_40 & V_44 ) ) {
F_20 () ;
F_23 ( & V_3 -> V_48 ) ;
}
}
struct V_37 * F_24 ( struct V_49 * V_50 , T_2 V_39 )
{
struct V_37 * V_3 ;
V_3 = F_15 ( V_50 -> V_45 , V_39 ) ;
if ( V_3 )
goto V_11;
if ( F_25 ( V_50 ) )
V_3 = F_15 (
F_25 ( V_50 ) -> V_51 ,
V_39 ) ;
V_11:
return V_3 ;
}
static struct V_37 * F_26 ( struct V_37 * V_52 , T_2 V_53 )
{
unsigned long V_54 ;
struct V_37 * V_23 ;
const struct V_18 * V_19 = V_52 -> V_34 -> V_17 ;
if ( V_19 == NULL )
return NULL ;
V_54 = V_19 -> V_20 ( V_52 , V_53 ) ;
if ( V_54 == 0 )
return NULL ;
V_23 = V_19 -> V_23 ( V_52 , V_54 ) ;
V_19 -> V_21 ( V_52 , V_54 ) ;
return V_23 ;
}
static struct V_1 * F_27 ( struct V_55 * V_56 )
{
struct V_1 * V_3 = NULL ;
if ( V_56 ) {
F_6 ( & V_7 ) ;
for ( V_3 = V_8 ; V_3 ; V_3 = V_3 -> V_9 ) {
if ( F_28 ( V_56 , V_3 -> V_10 ) == 0 ) {
if ( ! F_10 ( V_3 -> V_33 ) )
V_3 = NULL ;
break;
}
}
F_8 ( & V_7 ) ;
}
return V_3 ;
}
static T_3 F_29 ( struct V_57 * V_58 , T_4 * V_59 )
{
int V_60 = F_30 ( V_58 -> V_61 , 48 ) ;
int V_62 = F_30 ( V_60 + 1 , 48 ) ;
int V_63 = V_60 >> V_58 -> V_64 ;
int V_65 = ( V_62 >> V_58 -> V_64 ) - 1 ;
if ( ( V_58 -> V_66 > ( 100000000 / 8 ) ) || ( V_59 [ 0 ] == 0 ) ) {
F_31 ( L_2 ) ;
return V_67 ;
}
if ( ( V_65 > V_63 ) && ( V_65 < 256 )
&& ( V_59 [ V_63 ] == V_59 [ V_65 ] ) ) {
F_31 ( L_3 ,
V_63 , V_65 , V_59 [ V_65 ] ) ;
return V_68 ;
}
return V_67 ;
}
struct V_69 * F_32 ( struct V_57 * V_58 ,
struct V_55 * V_70 )
{
struct V_69 * V_59 ;
if ( V_70 == NULL || V_58 -> V_66 == 0 || V_58 -> V_64 == 0 ||
F_33 ( V_70 ) != V_71 )
return NULL ;
for ( V_59 = V_72 ; V_59 ; V_59 = V_59 -> V_9 ) {
if ( ! memcmp ( & V_59 -> V_66 , V_58 , sizeof( struct V_57 ) ) &&
! memcmp ( & V_59 -> V_73 , F_34 ( V_70 ) , 1024 ) ) {
V_59 -> V_74 ++ ;
return V_59 ;
}
}
V_59 = F_35 ( sizeof( * V_59 ) , V_75 ) ;
if ( V_59 ) {
V_59 -> V_66 = * V_58 ;
V_59 -> V_74 = 1 ;
memcpy ( V_59 -> V_73 , F_34 ( V_70 ) , 1024 ) ;
if ( V_58 -> V_76 == V_77 )
V_58 -> V_76 = F_29 ( V_58 , V_59 -> V_73 ) ;
V_59 -> V_9 = V_72 ;
V_72 = V_59 ;
}
return V_59 ;
}
void F_36 ( struct V_69 * V_70 )
{
struct V_69 * V_59 , * * V_78 ;
if ( ! V_70 || -- V_70 -> V_74 )
return;
for ( V_78 = & V_72 ;
( V_59 = * V_78 ) != NULL ;
V_78 = & V_59 -> V_9 ) {
if ( V_59 == V_70 ) {
* V_78 = V_59 -> V_9 ;
F_37 ( V_59 ) ;
return;
}
}
}
static struct V_79 * F_38 ( struct V_55 * V_80 )
{
struct V_55 * V_81 [ V_82 + 1 ] ;
struct V_79 * V_83 ;
struct V_84 * V_85 ;
unsigned int V_86 = 0 ;
T_5 * V_70 = NULL ;
int V_28 ;
V_28 = F_39 ( V_81 , V_82 , V_80 , V_87 ) ;
if ( V_28 < 0 )
return F_40 ( V_28 ) ;
if ( ! V_81 [ V_88 ] )
return F_40 ( - V_27 ) ;
V_85 = F_34 ( V_81 [ V_88 ] ) ;
if ( V_85 -> V_86 > 0 ) {
if ( ! V_81 [ V_89 ] )
return F_40 ( - V_27 ) ;
V_70 = F_34 ( V_81 [ V_89 ] ) ;
V_86 = F_33 ( V_81 [ V_89 ] ) / sizeof( T_5 ) ;
}
if ( V_86 != V_85 -> V_86 || ( ! V_70 && V_86 > 0 ) )
return F_40 ( - V_27 ) ;
F_41 (stab, &qdisc_stab_list, list) {
if ( memcmp ( & V_83 -> V_90 , V_85 , sizeof( * V_85 ) ) )
continue;
if ( V_86 > 0 && memcmp ( V_83 -> V_73 , V_70 , V_86 * sizeof( T_5 ) ) )
continue;
V_83 -> V_74 ++ ;
return V_83 ;
}
V_83 = F_35 ( sizeof( * V_83 ) + V_86 * sizeof( T_5 ) , V_75 ) ;
if ( ! V_83 )
return F_40 ( - V_91 ) ;
V_83 -> V_74 = 1 ;
V_83 -> V_90 = * V_85 ;
if ( V_86 > 0 )
memcpy ( V_83 -> V_73 , V_70 , V_86 * sizeof( T_5 ) ) ;
F_42 ( & V_83 -> V_92 , & V_93 ) ;
return V_83 ;
}
static void F_43 ( struct V_94 * V_95 )
{
F_37 ( F_44 ( V_95 , struct V_79 , V_96 ) ) ;
}
void F_45 ( struct V_79 * V_70 )
{
if ( ! V_70 )
return;
if ( -- V_70 -> V_74 == 0 ) {
F_46 ( & V_70 -> V_92 ) ;
F_47 ( & V_70 -> V_96 , F_43 ) ;
}
}
static int F_48 ( struct V_97 * V_98 , struct V_79 * V_83 )
{
struct V_55 * V_99 ;
V_99 = F_49 ( V_98 , V_100 ) ;
if ( V_99 == NULL )
goto V_101;
if ( F_50 ( V_98 , V_88 , sizeof( V_83 -> V_90 ) , & V_83 -> V_90 ) )
goto V_101;
F_51 ( V_98 , V_99 ) ;
return V_98 -> V_31 ;
V_101:
return - 1 ;
}
void F_52 ( struct V_97 * V_98 ,
const struct V_79 * V_83 )
{
int V_102 , V_103 ;
V_102 = V_98 -> V_31 + V_83 -> V_90 . V_104 ;
if ( F_53 ( ! V_83 -> V_90 . V_86 ) )
goto V_11;
V_103 = V_102 + V_83 -> V_90 . V_105 ;
if ( F_53 ( V_103 < 0 ) )
V_103 = 0 ;
V_103 >>= V_83 -> V_90 . V_64 ;
if ( F_54 ( V_103 < V_83 -> V_90 . V_86 ) )
V_102 = V_83 -> V_73 [ V_103 ] ;
else
V_102 = V_83 -> V_73 [ V_83 -> V_90 . V_86 - 1 ] *
( V_103 / V_83 -> V_90 . V_86 ) +
V_83 -> V_73 [ V_103 % V_83 -> V_90 . V_86 ] ;
V_102 <<= V_83 -> V_90 . V_106 ;
V_11:
if ( F_53 ( V_102 < 1 ) )
V_102 = 1 ;
F_55 ( V_98 ) -> V_102 = V_102 ;
}
void F_56 ( const char * V_107 , struct V_37 * V_45 )
{
if ( ! ( V_45 -> V_40 & V_108 ) ) {
F_57 ( L_4 ,
V_107 , V_45 -> V_34 -> V_10 , V_45 -> V_39 >> 16 ) ;
V_45 -> V_40 |= V_108 ;
}
}
static enum V_109 F_58 ( struct V_110 * V_111 )
{
struct F_58 * V_112 = F_44 ( V_111 , struct F_58 ,
V_111 ) ;
F_59 () ;
F_60 ( F_61 ( V_112 -> V_45 ) ) ;
F_62 () ;
return V_113 ;
}
void F_63 ( struct F_58 * V_112 , struct V_37 * V_45 )
{
F_64 ( & V_112 -> V_111 , V_114 , V_115 ) ;
V_112 -> V_111 . V_116 = F_58 ;
V_112 -> V_45 = V_45 ;
}
void F_65 ( struct F_58 * V_112 , T_6 V_117 )
{
if ( F_66 ( V_118 ,
& F_67 ( V_112 -> V_45 ) -> V_119 ) )
return;
if ( V_112 -> V_120 == V_117 )
return;
V_112 -> V_120 = V_117 ;
F_68 ( & V_112 -> V_111 ,
F_69 ( V_117 ) ,
V_115 ) ;
}
void F_70 ( struct F_58 * V_112 )
{
F_71 ( & V_112 -> V_111 ) ;
}
static struct V_121 * F_72 ( unsigned int V_122 )
{
unsigned int V_123 = V_122 * sizeof( struct V_121 ) , V_124 ;
struct V_121 * V_125 ;
if ( V_123 <= V_126 )
V_125 = F_35 ( V_123 , V_75 ) ;
else
V_125 = (struct V_121 * )
F_73 ( V_75 , F_74 ( V_123 ) ) ;
if ( V_125 != NULL ) {
for ( V_124 = 0 ; V_124 < V_122 ; V_124 ++ )
F_75 ( & V_125 [ V_124 ] ) ;
}
return V_125 ;
}
static void F_76 ( struct V_121 * V_125 , unsigned int V_122 )
{
unsigned int V_123 = V_122 * sizeof( struct V_121 ) ;
if ( V_123 <= V_126 )
F_37 ( V_125 ) ;
else
F_77 ( ( unsigned long ) V_125 , F_74 ( V_123 ) ) ;
}
void F_78 ( struct V_37 * V_127 , struct V_128 * V_129 )
{
struct V_130 * V_54 ;
struct V_131 * V_9 ;
struct V_121 * V_132 , * V_133 ;
unsigned int V_134 , V_135 , V_136 ;
unsigned int V_124 , V_125 ;
if ( V_129 -> V_137 * 4 <= V_129 -> V_138 * 3 )
return;
V_134 = V_129 -> V_138 * 2 ;
V_135 = V_134 - 1 ;
V_132 = F_72 ( V_134 ) ;
if ( V_132 == NULL )
return;
V_133 = V_129 -> V_48 ;
V_136 = V_129 -> V_138 ;
F_79 ( V_127 ) ;
for ( V_124 = 0 ; V_124 < V_136 ; V_124 ++ ) {
F_80 (cl, next, &ohash[i], hnode) {
V_125 = F_81 ( V_54 -> V_53 , V_135 ) ;
F_82 ( & V_54 -> V_139 , & V_132 [ V_125 ] ) ;
}
}
V_129 -> V_48 = V_132 ;
V_129 -> V_138 = V_134 ;
V_129 -> V_140 = V_135 ;
F_83 ( V_127 ) ;
F_76 ( V_133 , V_136 ) ;
}
int F_84 ( struct V_128 * V_129 )
{
unsigned int V_123 = 4 ;
V_129 -> V_48 = F_72 ( V_123 ) ;
if ( V_129 -> V_48 == NULL )
return - V_91 ;
V_129 -> V_138 = V_123 ;
V_129 -> V_140 = V_123 - 1 ;
V_129 -> V_137 = 0 ;
return 0 ;
}
void F_85 ( struct V_128 * V_129 )
{
F_76 ( V_129 -> V_48 , V_129 -> V_138 ) ;
}
void F_86 ( struct V_128 * V_129 ,
struct V_130 * V_54 )
{
unsigned int V_125 ;
F_87 ( & V_54 -> V_139 ) ;
V_125 = F_81 ( V_54 -> V_53 , V_129 -> V_140 ) ;
F_82 ( & V_54 -> V_139 , & V_129 -> V_48 [ V_125 ] ) ;
V_129 -> V_137 ++ ;
}
void F_88 ( struct V_128 * V_129 ,
struct V_130 * V_54 )
{
F_89 ( & V_54 -> V_139 ) ;
V_129 -> V_137 -- ;
}
static T_2 F_90 ( struct V_49 * V_50 )
{
int V_124 = 0x8000 ;
static T_2 V_141 = F_91 ( 0x80000000U , 0 ) ;
do {
V_141 += F_91 ( 0x10000U , 0 ) ;
if ( V_141 == F_91 ( V_43 , 0 ) )
V_141 = F_91 ( 0x80000000U , 0 ) ;
if ( ! F_24 ( V_50 , V_141 ) )
return V_141 ;
F_92 () ;
} while ( -- V_124 > 0 );
return 0 ;
}
void F_93 ( struct V_37 * V_127 , unsigned int V_122 ,
unsigned int V_31 )
{
const struct V_18 * V_19 ;
unsigned long V_54 ;
T_2 V_142 ;
int V_143 ;
if ( V_122 == 0 && V_31 == 0 )
return;
V_143 = F_94 ( int , V_122 , 0 ) ;
F_59 () ;
while ( ( V_142 = V_127 -> V_42 ) ) {
if ( F_95 ( V_142 ) == F_95 ( V_144 ) )
break;
if ( V_127 -> V_40 & V_145 )
break;
V_127 = F_24 ( F_16 ( V_127 ) , F_95 ( V_142 ) ) ;
if ( V_127 == NULL ) {
F_19 ( V_142 != V_43 ) ;
break;
}
V_19 = V_127 -> V_34 -> V_17 ;
if ( V_19 -> V_146 ) {
V_54 = V_19 -> V_20 ( V_127 , V_142 ) ;
V_19 -> V_146 ( V_127 , V_54 ) ;
V_19 -> V_21 ( V_127 , V_54 ) ;
}
V_127 -> V_3 . V_147 -= V_122 ;
V_127 -> V_148 . V_149 -= V_31 ;
F_96 ( V_127 , V_143 ) ;
}
F_62 () ;
}
static void F_97 ( struct V_150 * V_150 , struct V_97 * V_98 ,
struct V_151 * V_122 , T_2 V_152 ,
struct V_37 * V_153 , struct V_37 * V_154 )
{
if ( V_154 || V_153 )
F_98 ( V_150 , V_98 , V_122 , V_152 , V_153 , V_154 ) ;
if ( V_153 )
F_99 ( V_153 ) ;
}
static int F_100 ( struct V_49 * V_50 , struct V_37 * V_42 ,
struct V_97 * V_98 , struct V_151 * V_122 , T_2 V_53 ,
struct V_37 * V_154 , struct V_37 * V_153 )
{
struct V_37 * V_3 = V_153 ;
struct V_150 * V_150 = F_101 ( V_50 ) ;
int V_28 = 0 ;
if ( V_42 == NULL ) {
unsigned int V_124 , V_155 , V_156 ;
V_156 = 0 ;
V_155 = V_50 -> V_157 ;
if ( ( V_3 && V_3 -> V_40 & V_44 ) ||
( V_154 && V_154 -> V_40 & V_44 ) ) {
V_155 = 1 ;
V_156 = 1 ;
if ( ! F_25 ( V_50 ) )
return - V_29 ;
}
if ( V_50 -> V_40 & V_158 )
F_102 ( V_50 ) ;
if ( V_154 && V_154 -> V_34 -> V_159 )
goto V_160;
for ( V_124 = 0 ; V_124 < V_155 ; V_124 ++ ) {
struct V_161 * V_162 = F_25 ( V_50 ) ;
if ( ! V_156 )
V_162 = F_103 ( V_50 , V_124 ) ;
V_153 = F_104 ( V_162 , V_154 ) ;
if ( V_154 && V_124 > 0 )
F_105 ( & V_154 -> V_74 ) ;
if ( ! V_156 )
F_99 ( V_153 ) ;
}
V_160:
if ( ! V_156 ) {
F_97 ( V_150 , V_98 , V_122 , V_53 ,
V_50 -> V_45 , V_154 ) ;
if ( V_154 && ! V_154 -> V_34 -> V_159 )
F_105 ( & V_154 -> V_74 ) ;
V_50 -> V_45 = V_154 ? : & V_46 ;
if ( V_154 && V_154 -> V_34 -> V_159 )
V_154 -> V_34 -> V_159 ( V_154 ) ;
} else {
F_97 ( V_150 , V_98 , V_122 , V_53 , V_153 , V_154 ) ;
}
if ( V_50 -> V_40 & V_158 )
F_106 ( V_50 ) ;
} else {
const struct V_18 * V_19 = V_42 -> V_34 -> V_17 ;
V_28 = - V_163 ;
if ( V_19 && V_19 -> V_164 ) {
unsigned long V_54 = V_19 -> V_20 ( V_42 , V_53 ) ;
if ( V_54 ) {
V_28 = V_19 -> V_164 ( V_42 , V_54 , V_154 , & V_153 ) ;
V_19 -> V_21 ( V_42 , V_54 ) ;
} else
V_28 = - V_29 ;
}
if ( ! V_28 )
F_97 ( V_150 , V_98 , V_122 , V_53 , V_153 , V_154 ) ;
}
return V_28 ;
}
static struct V_37 * F_107 ( struct V_49 * V_50 ,
struct V_161 * V_162 ,
struct V_37 * V_52 , T_2 V_42 , T_2 V_39 ,
struct V_55 * * V_165 , int * V_166 )
{
int V_28 ;
struct V_55 * V_56 = V_165 [ V_167 ] ;
struct V_37 * V_127 ;
struct V_1 * V_34 ;
struct V_79 * V_83 ;
V_34 = F_27 ( V_56 ) ;
#ifdef F_108
if ( V_34 == NULL && V_56 != NULL ) {
char V_30 [ V_168 ] ;
if ( F_109 ( V_30 , V_56 , V_168 ) < V_168 ) {
F_110 () ;
F_13 ( L_1 , V_30 ) ;
F_111 () ;
V_34 = F_27 ( V_56 ) ;
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
V_127 = F_112 ( V_162 , V_34 ) ;
if ( F_113 ( V_127 ) ) {
V_28 = F_114 ( V_127 ) ;
goto V_171;
}
V_127 -> V_42 = V_42 ;
if ( V_39 == V_144 ) {
V_127 -> V_40 |= V_44 ;
V_39 = F_91 ( V_144 , 0 ) ;
F_115 ( F_116 ( V_127 ) , & V_172 ) ;
} else {
if ( V_39 == 0 ) {
V_39 = F_90 ( V_50 ) ;
V_28 = - V_91 ;
if ( V_39 == 0 )
goto V_173;
}
F_115 ( F_116 ( V_127 ) , & V_174 ) ;
if ( ! F_117 ( V_50 ) )
V_127 -> V_40 |= V_175 ;
}
V_127 -> V_39 = V_39 ;
if ( ( V_50 -> V_176 & V_177 ) && ( V_50 -> V_178 == 0 ) ) {
V_50 -> V_178 = V_179 ;
F_118 ( V_50 , L_5 ) ;
}
if ( ! V_34 -> V_180 || ( V_28 = V_34 -> V_180 ( V_127 , V_165 [ V_181 ] ) ) == 0 ) {
if ( F_119 ( V_127 ) ) {
V_127 -> V_182 =
F_120 ( struct V_183 ) ;
if ( ! V_127 -> V_182 )
goto V_184;
V_127 -> V_185 = F_121 ( struct V_186 ) ;
if ( ! V_127 -> V_185 )
goto V_184;
}
if ( V_165 [ V_100 ] ) {
V_83 = F_38 ( V_165 [ V_100 ] ) ;
if ( F_113 ( V_83 ) ) {
V_28 = F_114 ( V_83 ) ;
goto V_184;
}
F_122 ( V_127 -> V_83 , V_83 ) ;
}
if ( V_165 [ V_187 ] ) {
T_7 * V_188 ;
V_28 = - V_163 ;
if ( V_127 -> V_40 & V_189 )
goto V_184;
if ( ( V_127 -> V_42 != V_43 ) &&
! ( V_127 -> V_40 & V_44 ) &&
( ! V_52 || ! ( V_52 -> V_40 & V_189 ) ) )
V_188 = F_123 ( V_127 ) ;
else
V_188 = & V_127 -> V_188 ;
V_28 = F_124 ( & V_127 -> V_190 ,
V_127 -> V_182 ,
& V_127 -> V_191 ,
NULL ,
V_188 ,
V_165 [ V_187 ] ) ;
if ( V_28 )
goto V_184;
}
F_18 ( V_127 ) ;
return V_127 ;
}
V_34 -> V_192 ( V_127 ) ;
V_173:
F_125 ( V_50 ) ;
F_37 ( ( char * ) V_127 - V_127 -> V_193 ) ;
V_171:
F_14 ( V_34 -> V_33 ) ;
V_170:
* V_166 = V_28 ;
return NULL ;
V_184:
F_126 ( V_127 -> V_182 ) ;
F_126 ( V_127 -> V_185 ) ;
F_45 ( F_127 ( V_127 -> V_83 ) ) ;
if ( V_34 -> V_192 )
V_34 -> V_192 ( V_127 ) ;
goto V_173;
}
static int F_128 ( struct V_37 * V_127 , struct V_55 * * V_165 )
{
struct V_79 * V_194 , * V_83 = NULL ;
int V_28 = 0 ;
if ( V_165 [ V_181 ] ) {
if ( V_127 -> V_34 -> V_195 == NULL )
return - V_27 ;
V_28 = V_127 -> V_34 -> V_195 ( V_127 , V_165 [ V_181 ] ) ;
if ( V_28 )
return V_28 ;
}
if ( V_165 [ V_100 ] ) {
V_83 = F_38 ( V_165 [ V_100 ] ) ;
if ( F_113 ( V_83 ) )
return F_114 ( V_83 ) ;
}
V_194 = F_127 ( V_127 -> V_83 ) ;
F_122 ( V_127 -> V_83 , V_83 ) ;
F_45 ( V_194 ) ;
if ( V_165 [ V_187 ] ) {
if ( V_127 -> V_40 & V_189 )
goto V_11;
F_129 ( & V_127 -> V_190 ,
V_127 -> V_182 ,
& V_127 -> V_191 ,
NULL ,
F_123 ( V_127 ) ,
V_165 [ V_187 ] ) ;
}
V_11:
return 0 ;
}
static int F_130 ( struct V_37 * V_3 , struct V_37 * V_52 , int V_196 )
{
struct V_197 V_198 ;
if ( V_3 -> V_34 -> V_17 == NULL )
return 0 ;
V_198 . V_199 . V_200 = V_198 . V_199 . V_160 = V_198 . V_199 . V_201 = 0 ;
V_198 . V_199 . V_202 = V_203 ;
V_198 . V_196 = V_196 ;
V_198 . V_52 = V_52 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_198 . V_199 ) ;
return V_198 . V_199 . V_200 ? - V_204 : 0 ;
}
static int
V_203 ( struct V_37 * V_3 , unsigned long V_54 , struct V_205 * V_199 )
{
struct V_37 * V_23 ;
const struct V_18 * V_19 = V_3 -> V_34 -> V_17 ;
struct V_197 * V_198 = (struct V_197 * ) V_199 ;
V_23 = V_19 -> V_23 ( V_3 , V_54 ) ;
if ( V_23 ) {
if ( V_23 == V_198 -> V_52 || V_198 -> V_196 > 7 )
return - V_204 ;
return F_130 ( V_23 , V_198 -> V_52 , V_198 -> V_196 + 1 ) ;
}
return 0 ;
}
static int F_131 ( struct V_97 * V_98 , struct V_151 * V_122 )
{
struct V_150 * V_150 = F_132 ( V_98 -> V_206 ) ;
struct V_207 * V_208 = F_133 ( V_122 ) ;
struct V_55 * V_165 [ V_209 + 1 ] ;
struct V_49 * V_50 ;
T_2 V_152 ;
struct V_37 * V_3 = NULL ;
struct V_37 * V_52 = NULL ;
int V_28 ;
if ( ( V_122 -> V_210 != V_211 ) &&
! F_134 ( V_98 , V_150 -> V_212 , V_35 ) )
return - V_36 ;
V_28 = F_135 ( V_122 , sizeof( * V_208 ) , V_165 , V_209 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_50 = F_136 ( V_150 , V_208 -> V_213 ) ;
if ( ! V_50 )
return - V_214 ;
V_152 = V_208 -> V_215 ;
if ( V_152 ) {
if ( V_152 != V_43 ) {
if ( F_95 ( V_152 ) != F_95 ( V_144 ) ) {
V_52 = F_24 ( V_50 , F_95 ( V_152 ) ) ;
if ( ! V_52 )
return - V_29 ;
V_3 = F_26 ( V_52 , V_152 ) ;
} else if ( F_25 ( V_50 ) ) {
V_3 = F_25 ( V_50 ) -> V_51 ;
}
} else {
V_3 = V_50 -> V_45 ;
}
if ( ! V_3 )
return - V_29 ;
if ( V_208 -> V_216 && V_3 -> V_39 != V_208 -> V_216 )
return - V_27 ;
} else {
V_3 = F_24 ( V_50 , V_208 -> V_216 ) ;
if ( ! V_3 )
return - V_29 ;
}
if ( V_165 [ V_167 ] && F_28 ( V_165 [ V_167 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_122 -> V_210 == V_217 ) {
if ( ! V_152 )
return - V_27 ;
if ( V_3 -> V_39 == 0 )
return - V_29 ;
V_28 = F_100 ( V_50 , V_52 , V_98 , V_122 , V_152 , NULL , V_3 ) ;
if ( V_28 != 0 )
return V_28 ;
} else {
F_98 ( V_150 , V_98 , V_122 , V_152 , NULL , V_3 ) ;
}
return 0 ;
}
static int F_137 ( struct V_97 * V_98 , struct V_151 * V_122 )
{
struct V_150 * V_150 = F_132 ( V_98 -> V_206 ) ;
struct V_207 * V_208 ;
struct V_55 * V_165 [ V_209 + 1 ] ;
struct V_49 * V_50 ;
T_2 V_152 ;
struct V_37 * V_3 , * V_52 ;
int V_28 ;
if ( ! F_134 ( V_98 , V_150 -> V_212 , V_35 ) )
return - V_36 ;
V_218:
V_28 = F_135 ( V_122 , sizeof( * V_208 ) , V_165 , V_209 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_208 = F_133 ( V_122 ) ;
V_152 = V_208 -> V_215 ;
V_3 = V_52 = NULL ;
V_50 = F_136 ( V_150 , V_208 -> V_213 ) ;
if ( ! V_50 )
return - V_214 ;
if ( V_152 ) {
if ( V_152 != V_43 ) {
if ( V_152 != V_144 ) {
V_52 = F_24 ( V_50 , F_95 ( V_152 ) ) ;
if ( ! V_52 )
return - V_29 ;
V_3 = F_26 ( V_52 , V_152 ) ;
} else if ( F_138 ( V_50 ) ) {
V_3 = F_25 ( V_50 ) -> V_51 ;
}
} else {
V_3 = V_50 -> V_45 ;
}
if ( V_3 && V_3 -> V_39 == 0 )
V_3 = NULL ;
if ( ! V_3 || ! V_208 -> V_216 || V_3 -> V_39 != V_208 -> V_216 ) {
if ( V_208 -> V_216 ) {
if ( V_3 && ! ( V_122 -> V_219 & V_220 ) )
return - V_6 ;
if ( F_139 ( V_208 -> V_216 ) )
return - V_27 ;
V_3 = F_24 ( V_50 , V_208 -> V_216 ) ;
if ( ! V_3 )
goto V_221;
if ( V_122 -> V_219 & V_222 )
return - V_6 ;
if ( V_165 [ V_167 ] && F_28 ( V_165 [ V_167 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_3 == V_52 ||
( V_52 && F_130 ( V_3 , V_52 , 0 ) ) )
return - V_204 ;
F_105 ( & V_3 -> V_74 ) ;
goto V_164;
} else {
if ( ! V_3 )
goto V_221;
if ( ( V_122 -> V_219 & V_223 ) &&
( V_122 -> V_219 & V_220 ) &&
( ( V_122 -> V_219 & V_222 ) ||
( V_165 [ V_167 ] &&
F_28 ( V_165 [ V_167 ] , V_3 -> V_34 -> V_10 ) ) ) )
goto V_221;
}
}
} else {
if ( ! V_208 -> V_216 )
return - V_27 ;
V_3 = F_24 ( V_50 , V_208 -> V_216 ) ;
}
if ( V_3 == NULL )
return - V_29 ;
if ( V_122 -> V_219 & V_222 )
return - V_6 ;
if ( V_165 [ V_167 ] && F_28 ( V_165 [ V_167 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
V_28 = F_128 ( V_3 , V_165 ) ;
if ( V_28 == 0 )
F_98 ( V_150 , V_98 , V_122 , V_152 , NULL , V_3 ) ;
return V_28 ;
V_221:
if ( ! ( V_122 -> V_219 & V_223 ) )
return - V_29 ;
if ( V_152 == V_144 ) {
if ( F_25 ( V_50 ) )
V_3 = F_107 ( V_50 , F_25 ( V_50 ) , V_52 ,
V_208 -> V_215 , V_208 -> V_215 ,
V_165 , & V_28 ) ;
else
V_28 = - V_29 ;
} else {
struct V_161 * V_162 ;
if ( V_52 && V_52 -> V_34 -> V_17 && V_52 -> V_34 -> V_17 -> V_224 )
V_162 = V_52 -> V_34 -> V_17 -> V_224 ( V_52 , V_208 ) ;
else if ( V_52 )
V_162 = V_52 -> V_162 ;
else
V_162 = F_103 ( V_50 , 0 ) ;
V_3 = F_107 ( V_50 , V_162 , V_52 ,
V_208 -> V_215 , V_208 -> V_216 ,
V_165 , & V_28 ) ;
}
if ( V_3 == NULL ) {
if ( V_28 == - V_169 )
goto V_218;
return V_28 ;
}
V_164:
V_28 = F_100 ( V_50 , V_52 , V_98 , V_122 , V_152 , V_3 , NULL ) ;
if ( V_28 ) {
if ( V_3 )
F_99 ( V_3 ) ;
return V_28 ;
}
return 0 ;
}
static int F_140 ( struct V_97 * V_98 , struct V_37 * V_3 , T_2 V_152 ,
T_2 V_225 , T_2 V_226 , T_5 V_40 , int V_227 )
{
struct V_183 T_8 * V_182 = NULL ;
struct V_186 T_8 * V_185 = NULL ;
struct V_207 * V_208 ;
struct V_151 * V_228 ;
unsigned char * V_229 = F_141 ( V_98 ) ;
struct V_230 V_231 ;
struct V_79 * V_83 ;
T_4 V_147 ;
F_92 () ;
V_228 = F_142 ( V_98 , V_225 , V_226 , V_227 , sizeof( * V_208 ) , V_40 ) ;
if ( ! V_228 )
goto V_232;
V_208 = F_133 ( V_228 ) ;
V_208 -> V_233 = V_234 ;
V_208 -> V_235 = 0 ;
V_208 -> V_236 = 0 ;
V_208 -> V_213 = F_16 ( V_3 ) -> V_237 ;
V_208 -> V_215 = V_152 ;
V_208 -> V_216 = V_3 -> V_39 ;
V_208 -> V_238 = F_143 ( & V_3 -> V_74 ) ;
if ( F_144 ( V_98 , V_167 , V_3 -> V_34 -> V_10 ) )
goto V_101;
if ( V_3 -> V_34 -> V_239 && V_3 -> V_34 -> V_239 ( V_3 , V_98 ) < 0 )
goto V_101;
V_147 = V_3 -> V_3 . V_147 ;
V_83 = F_127 ( V_3 -> V_83 ) ;
if ( V_83 && F_48 ( V_98 , V_83 ) < 0 )
goto V_101;
if ( F_145 ( V_98 , V_240 , V_241 , V_242 ,
NULL , & V_231 , V_243 ) < 0 )
goto V_101;
if ( V_3 -> V_34 -> V_244 && V_3 -> V_34 -> V_244 ( V_3 , & V_231 ) < 0 )
goto V_101;
if ( F_119 ( V_3 ) ) {
V_182 = V_3 -> V_182 ;
V_185 = V_3 -> V_185 ;
}
if ( F_146 ( F_123 ( V_3 ) ,
& V_231 , V_182 , & V_3 -> V_190 ) < 0 ||
F_147 ( & V_231 , & V_3 -> V_191 ) < 0 ||
F_148 ( & V_231 , V_185 , & V_3 -> V_148 , V_147 ) < 0 )
goto V_101;
if ( F_149 ( & V_231 ) < 0 )
goto V_101;
V_228 -> V_245 = F_141 ( V_98 ) - V_229 ;
return V_98 -> V_31 ;
V_232:
V_101:
F_150 ( V_98 , V_229 ) ;
return - 1 ;
}
static bool F_151 ( struct V_37 * V_3 )
{
return ( V_3 -> V_40 & V_41 ) ? true : false ;
}
static int F_98 ( struct V_150 * V_150 , struct V_97 * V_246 ,
struct V_151 * V_122 , T_2 V_152 ,
struct V_37 * V_153 , struct V_37 * V_154 )
{
struct V_97 * V_98 ;
T_2 V_225 = V_246 ? F_152 ( V_246 ) . V_225 : 0 ;
V_98 = F_153 ( V_247 , V_75 ) ;
if ( ! V_98 )
return - V_248 ;
if ( V_153 && ! F_151 ( V_153 ) ) {
if ( F_140 ( V_98 , V_153 , V_152 , V_225 , V_122 -> V_249 ,
0 , V_217 ) < 0 )
goto V_170;
}
if ( V_154 && ! F_151 ( V_154 ) ) {
if ( F_140 ( V_98 , V_154 , V_152 , V_225 , V_122 -> V_249 ,
V_153 ? V_220 : 0 , V_250 ) < 0 )
goto V_170;
}
if ( V_98 -> V_31 )
return F_154 ( V_98 , V_150 , V_225 , V_251 ,
V_122 -> V_219 & V_252 ) ;
V_170:
F_155 ( V_98 ) ;
return - V_27 ;
}
static int F_156 ( struct V_37 * V_38 , struct V_97 * V_98 ,
struct V_253 * V_254 ,
int * V_255 , int V_256 , bool V_257 )
{
int V_258 = 0 , V_259 = * V_255 ;
struct V_37 * V_3 ;
int V_229 ;
if ( ! V_38 )
return 0 ;
V_3 = V_38 ;
if ( V_259 < V_256 ) {
V_259 ++ ;
} else {
if ( ! F_151 ( V_3 ) &&
F_140 ( V_98 , V_3 , V_3 -> V_42 , F_152 ( V_254 -> V_98 ) . V_225 ,
V_254 -> V_228 -> V_249 , V_260 ,
V_250 ) <= 0 )
goto V_261;
V_259 ++ ;
}
if ( ! F_16 ( V_38 ) || ! V_257 )
goto V_11;
F_157 (qdisc_dev(root)->qdisc_hash, b, q, hash) {
if ( V_259 < V_256 ) {
V_259 ++ ;
continue;
}
if ( ! F_151 ( V_3 ) &&
F_140 ( V_98 , V_3 , V_3 -> V_42 , F_152 ( V_254 -> V_98 ) . V_225 ,
V_254 -> V_228 -> V_249 , V_260 ,
V_250 ) <= 0 )
goto V_261;
V_259 ++ ;
}
V_11:
* V_255 = V_259 ;
return V_258 ;
V_261:
V_258 = - 1 ;
goto V_11;
}
static int F_158 ( struct V_97 * V_98 , struct V_253 * V_254 )
{
struct V_150 * V_150 = F_132 ( V_98 -> V_206 ) ;
int V_262 , V_259 ;
int V_263 , V_256 ;
struct V_49 * V_50 ;
V_263 = V_254 -> args [ 0 ] ;
V_256 = V_259 = V_254 -> args [ 1 ] ;
V_262 = 0 ;
F_20 () ;
F_159 (net, dev) {
struct V_161 * V_162 ;
if ( V_262 < V_263 )
goto V_264;
if ( V_262 > V_263 )
V_256 = 0 ;
V_259 = 0 ;
if ( F_156 ( V_50 -> V_45 , V_98 , V_254 , & V_259 , V_256 ,
true ) < 0 )
goto V_261;
V_162 = F_25 ( V_50 ) ;
if ( V_162 &&
F_156 ( V_162 -> V_51 , V_98 , V_254 ,
& V_259 , V_256 , false ) < 0 )
goto V_261;
V_264:
V_262 ++ ;
}
V_261:
V_254 -> args [ 0 ] = V_262 ;
V_254 -> args [ 1 ] = V_259 ;
return V_98 -> V_31 ;
}
static int F_160 ( struct V_97 * V_98 , struct V_151 * V_122 )
{
struct V_150 * V_150 = F_132 ( V_98 -> V_206 ) ;
struct V_207 * V_208 = F_133 ( V_122 ) ;
struct V_55 * V_165 [ V_209 + 1 ] ;
struct V_49 * V_50 ;
struct V_37 * V_3 = NULL ;
const struct V_18 * V_19 ;
unsigned long V_54 = 0 ;
unsigned long V_265 ;
T_2 V_225 ;
T_2 V_152 ;
T_2 V_266 ;
int V_28 ;
if ( ( V_122 -> V_210 != V_267 ) &&
! F_134 ( V_98 , V_150 -> V_212 , V_35 ) )
return - V_36 ;
V_28 = F_135 ( V_122 , sizeof( * V_208 ) , V_165 , V_209 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_50 = F_136 ( V_150 , V_208 -> V_213 ) ;
if ( ! V_50 )
return - V_214 ;
V_225 = V_208 -> V_215 ;
V_152 = V_208 -> V_216 ;
V_266 = F_95 ( V_152 ) ;
if ( V_225 != V_43 ) {
T_2 V_268 = F_95 ( V_225 ) ;
if ( V_266 && V_268 ) {
if ( V_266 != V_268 )
return - V_27 ;
} else if ( V_268 ) {
V_266 = V_268 ;
} else if ( V_266 == 0 )
V_266 = V_50 -> V_45 -> V_39 ;
if ( V_225 )
V_225 = F_91 ( V_266 , V_225 ) ;
} else {
if ( V_266 == 0 )
V_266 = V_50 -> V_45 -> V_39 ;
}
V_3 = F_24 ( V_50 , V_266 ) ;
if ( ! V_3 )
return - V_29 ;
V_19 = V_3 -> V_34 -> V_17 ;
if ( V_19 == NULL )
return - V_27 ;
if ( V_152 == 0 ) {
if ( V_225 == V_43 )
V_152 = V_266 ;
} else
V_152 = F_91 ( V_266 , V_152 ) ;
if ( V_152 )
V_54 = V_19 -> V_20 ( V_3 , V_152 ) ;
if ( V_54 == 0 ) {
V_28 = - V_29 ;
if ( V_122 -> V_210 != V_269 ||
! ( V_122 -> V_219 & V_223 ) )
goto V_11;
} else {
switch ( V_122 -> V_210 ) {
case V_269 :
V_28 = - V_6 ;
if ( V_122 -> V_219 & V_222 )
goto V_11;
break;
case V_270 :
V_28 = - V_163 ;
if ( V_19 -> V_271 )
V_28 = V_19 -> V_271 ( V_3 , V_54 ) ;
if ( V_28 == 0 )
F_161 ( V_150 , V_98 , V_122 , V_3 , V_54 ,
V_270 ) ;
goto V_11;
case V_267 :
V_28 = F_161 ( V_150 , V_98 , V_122 , V_3 , V_54 , V_269 ) ;
goto V_11;
default:
V_28 = - V_27 ;
goto V_11;
}
}
V_265 = V_54 ;
V_28 = - V_163 ;
if ( V_19 -> V_195 )
V_28 = V_19 -> V_195 ( V_3 , V_152 , V_225 , V_165 , & V_265 ) ;
if ( V_28 == 0 )
F_161 ( V_150 , V_98 , V_122 , V_3 , V_265 , V_269 ) ;
V_11:
if ( V_54 )
V_19 -> V_21 ( V_3 , V_54 ) ;
return V_28 ;
}
static int F_162 ( struct V_97 * V_98 , struct V_37 * V_3 ,
unsigned long V_54 ,
T_2 V_225 , T_2 V_226 , T_5 V_40 , int V_227 )
{
struct V_207 * V_208 ;
struct V_151 * V_228 ;
unsigned char * V_229 = F_141 ( V_98 ) ;
struct V_230 V_231 ;
const struct V_18 * V_17 = V_3 -> V_34 -> V_17 ;
F_92 () ;
V_228 = F_142 ( V_98 , V_225 , V_226 , V_227 , sizeof( * V_208 ) , V_40 ) ;
if ( ! V_228 )
goto V_232;
V_208 = F_133 ( V_228 ) ;
V_208 -> V_233 = V_234 ;
V_208 -> V_235 = 0 ;
V_208 -> V_236 = 0 ;
V_208 -> V_213 = F_16 ( V_3 ) -> V_237 ;
V_208 -> V_215 = V_3 -> V_39 ;
V_208 -> V_216 = V_3 -> V_39 ;
V_208 -> V_238 = 0 ;
if ( F_144 ( V_98 , V_167 , V_3 -> V_34 -> V_10 ) )
goto V_101;
if ( V_17 -> V_239 && V_17 -> V_239 ( V_3 , V_54 , V_98 , V_208 ) < 0 )
goto V_101;
if ( F_145 ( V_98 , V_240 , V_241 , V_242 ,
NULL , & V_231 , V_243 ) < 0 )
goto V_101;
if ( V_17 -> V_244 && V_17 -> V_244 ( V_3 , V_54 , & V_231 ) < 0 )
goto V_101;
if ( F_149 ( & V_231 ) < 0 )
goto V_101;
V_228 -> V_245 = F_141 ( V_98 ) - V_229 ;
return V_98 -> V_31 ;
V_232:
V_101:
F_150 ( V_98 , V_229 ) ;
return - 1 ;
}
static int F_161 ( struct V_150 * V_150 , struct V_97 * V_246 ,
struct V_151 * V_122 , struct V_37 * V_3 ,
unsigned long V_54 , int V_227 )
{
struct V_97 * V_98 ;
T_2 V_225 = V_246 ? F_152 ( V_246 ) . V_225 : 0 ;
V_98 = F_153 ( V_247 , V_75 ) ;
if ( ! V_98 )
return - V_248 ;
if ( F_162 ( V_98 , V_3 , V_54 , V_225 , V_122 -> V_249 , 0 , V_227 ) < 0 ) {
F_155 ( V_98 ) ;
return - V_27 ;
}
return F_154 ( V_98 , V_150 , V_225 , V_251 ,
V_122 -> V_219 & V_252 ) ;
}
static int F_163 ( struct V_37 * V_3 , unsigned long V_54 ,
struct V_205 * V_198 )
{
struct V_272 * V_273 = (struct V_272 * ) V_198 ;
return F_162 ( V_273 -> V_98 , V_3 , V_54 , F_152 ( V_273 -> V_254 -> V_98 ) . V_225 ,
V_273 -> V_254 -> V_228 -> V_249 , V_260 ,
V_269 ) ;
}
static int F_164 ( struct V_37 * V_3 , struct V_97 * V_98 ,
struct V_207 * V_208 , struct V_253 * V_254 ,
int * V_274 , int V_275 )
{
struct V_272 V_198 ;
if ( F_151 ( V_3 ) ||
* V_274 < V_275 || ! V_3 -> V_34 -> V_17 ||
( V_208 -> V_215 &&
F_95 ( V_208 -> V_215 ) != V_3 -> V_39 ) ) {
( * V_274 ) ++ ;
return 0 ;
}
if ( * V_274 > V_275 )
memset ( & V_254 -> args [ 1 ] , 0 , sizeof( V_254 -> args ) - sizeof( V_254 -> args [ 0 ] ) ) ;
V_198 . V_199 . V_202 = F_163 ;
V_198 . V_98 = V_98 ;
V_198 . V_254 = V_254 ;
V_198 . V_199 . V_200 = 0 ;
V_198 . V_199 . V_160 = V_254 -> args [ 1 ] ;
V_198 . V_199 . V_201 = 0 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_198 . V_199 ) ;
V_254 -> args [ 1 ] = V_198 . V_199 . V_201 ;
if ( V_198 . V_199 . V_200 )
return - 1 ;
( * V_274 ) ++ ;
return 0 ;
}
static int F_165 ( struct V_37 * V_38 , struct V_97 * V_98 ,
struct V_207 * V_208 , struct V_253 * V_254 ,
int * V_274 , int V_275 )
{
struct V_37 * V_3 ;
int V_229 ;
if ( ! V_38 )
return 0 ;
if ( F_164 ( V_38 , V_98 , V_208 , V_254 , V_274 , V_275 ) < 0 )
return - 1 ;
if ( ! F_16 ( V_38 ) )
return 0 ;
F_157 (qdisc_dev(root)->qdisc_hash, b, q, hash) {
if ( F_164 ( V_3 , V_98 , V_208 , V_254 , V_274 , V_275 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_166 ( struct V_97 * V_98 , struct V_253 * V_254 )
{
struct V_207 * V_208 = F_133 ( V_254 -> V_228 ) ;
struct V_150 * V_150 = F_132 ( V_98 -> V_206 ) ;
struct V_161 * V_162 ;
struct V_49 * V_50 ;
int V_276 , V_275 ;
if ( V_245 ( V_254 -> V_228 ) < sizeof( * V_208 ) )
return 0 ;
V_50 = F_167 ( V_150 , V_208 -> V_213 ) ;
if ( ! V_50 )
return 0 ;
V_275 = V_254 -> args [ 0 ] ;
V_276 = 0 ;
if ( F_165 ( V_50 -> V_45 , V_98 , V_208 , V_254 , & V_276 , V_275 ) < 0 )
goto V_261;
V_162 = F_25 ( V_50 ) ;
if ( V_162 &&
F_165 ( V_162 -> V_51 , V_98 , V_208 , V_254 ,
& V_276 , V_275 ) < 0 )
goto V_261;
V_261:
V_254 -> args [ 0 ] = V_276 ;
F_125 ( V_50 ) ;
return V_98 -> V_31 ;
}
int F_168 ( struct V_97 * V_98 , const struct V_277 * V_278 ,
struct V_279 * V_280 , bool V_281 )
{
T_9 V_282 = F_169 ( V_98 ) ;
#ifdef F_170
const int V_283 = 4 ;
const struct V_277 * V_284 = V_278 ;
int V_285 = 0 ;
V_286:
#endif
for (; V_278 ; V_278 = F_171 ( V_278 -> V_9 ) ) {
int V_28 ;
if ( V_278 -> V_282 != V_282 &&
V_278 -> V_282 != F_172 ( V_287 ) )
continue;
V_28 = V_278 -> V_288 ( V_98 , V_278 , V_280 ) ;
#ifdef F_170
if ( F_53 ( V_28 == V_289 && ! V_281 ) )
goto V_290;
#endif
if ( V_28 >= 0 )
return V_28 ;
}
return V_291 ;
#ifdef F_170
V_290:
if ( F_53 ( V_285 ++ >= V_283 ) ) {
F_173 ( L_6 ,
V_278 -> V_3 -> V_34 -> V_10 , V_278 -> V_292 & 0xffff ,
F_174 ( V_278 -> V_282 ) ) ;
return V_293 ;
}
V_278 = V_284 ;
V_282 = F_169 ( V_98 ) ;
goto V_286;
#endif
}
static int F_175 ( struct V_294 * V_226 , void * V_295 )
{
F_176 ( V_226 , L_7 ,
( T_2 ) V_296 , ( T_2 ) F_177 ( 1 ) ,
1000000 ,
( T_2 ) V_297 / V_298 ) ;
return 0 ;
}
static int F_178 ( struct V_299 * V_299 , struct V_300 * V_300 )
{
return F_179 ( V_300 , F_175 , NULL ) ;
}
static int T_10 F_180 ( struct V_150 * V_150 )
{
struct V_301 * V_302 ;
V_302 = F_181 ( L_8 , 0 , V_150 -> V_303 , & V_304 ) ;
if ( V_302 == NULL )
return - V_91 ;
return 0 ;
}
static void T_11 F_182 ( struct V_150 * V_150 )
{
F_183 ( L_8 , V_150 -> V_303 ) ;
}
static int T_10 F_180 ( struct V_150 * V_150 )
{
return 0 ;
}
static void T_11 F_182 ( struct V_150 * V_150 )
{
}
static int T_12 F_184 ( void )
{
int V_28 ;
V_28 = F_185 ( & V_305 ) ;
if ( V_28 ) {
F_186 ( L_9
L_10 ) ;
return V_28 ;
}
F_1 ( & V_306 ) ;
F_1 ( & V_307 ) ;
F_1 ( & V_308 ) ;
F_1 ( & V_309 ) ;
F_1 ( & V_310 ) ;
F_1 ( & V_311 ) ;
F_187 ( V_312 , V_250 , F_137 , NULL , NULL ) ;
F_187 ( V_312 , V_217 , F_131 , NULL , NULL ) ;
F_187 ( V_312 , V_211 , F_131 , F_158 ,
NULL ) ;
F_187 ( V_312 , V_269 , F_160 , NULL , NULL ) ;
F_187 ( V_312 , V_270 , F_160 , NULL , NULL ) ;
F_187 ( V_312 , V_267 , F_160 , F_166 ,
NULL ) ;
return 0 ;
}
