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
static int T_2 F_15 ( void )
{
return F_11 ( V_37 ) ;
}
static struct V_38 * F_16 ( struct V_38 * V_39 , T_3 V_40 )
{
struct V_38 * V_3 ;
if ( ! F_17 ( V_39 ) )
return ( V_39 -> V_40 == V_40 ? V_39 : NULL ) ;
if ( ! ( V_39 -> V_41 & V_42 ) &&
V_39 -> V_40 == V_40 )
return V_39 ;
F_18 (qdisc_dev(root)->qdisc_hash, q, hash, handle) {
if ( V_3 -> V_40 == V_40 )
return V_3 ;
}
return NULL ;
}
void F_19 ( struct V_38 * V_3 , bool V_43 )
{
if ( ( V_3 -> V_44 != V_45 ) && ! ( V_3 -> V_41 & V_46 ) ) {
struct V_38 * V_39 = F_17 ( V_3 ) -> V_47 ;
F_20 ( V_39 == & V_48 ) ;
F_21 () ;
F_22 ( F_17 ( V_3 ) -> V_49 , & V_3 -> V_50 , V_3 -> V_40 ) ;
if ( V_43 )
V_3 -> V_41 |= V_51 ;
}
}
void F_23 ( struct V_38 * V_3 )
{
if ( ( V_3 -> V_44 != V_45 ) && ! ( V_3 -> V_41 & V_46 ) ) {
F_21 () ;
F_24 ( & V_3 -> V_50 ) ;
}
}
struct V_38 * F_25 ( struct V_52 * V_53 , T_3 V_40 )
{
struct V_38 * V_3 ;
V_3 = F_16 ( V_53 -> V_47 , V_40 ) ;
if ( V_3 )
goto V_11;
if ( F_26 ( V_53 ) )
V_3 = F_16 (
F_26 ( V_53 ) -> V_54 ,
V_40 ) ;
V_11:
return V_3 ;
}
static struct V_38 * F_27 ( struct V_38 * V_55 , T_3 V_56 )
{
unsigned long V_57 ;
struct V_38 * V_23 ;
const struct V_18 * V_19 = V_55 -> V_34 -> V_17 ;
if ( V_19 == NULL )
return NULL ;
V_57 = V_19 -> V_20 ( V_55 , V_56 ) ;
if ( V_57 == 0 )
return NULL ;
V_23 = V_19 -> V_23 ( V_55 , V_57 ) ;
V_19 -> V_21 ( V_55 , V_57 ) ;
return V_23 ;
}
static struct V_1 * F_28 ( struct V_58 * V_59 )
{
struct V_1 * V_3 = NULL ;
if ( V_59 ) {
F_6 ( & V_7 ) ;
for ( V_3 = V_8 ; V_3 ; V_3 = V_3 -> V_9 ) {
if ( F_29 ( V_59 , V_3 -> V_10 ) == 0 ) {
if ( ! F_10 ( V_3 -> V_33 ) )
V_3 = NULL ;
break;
}
}
F_8 ( & V_7 ) ;
}
return V_3 ;
}
static T_4 F_30 ( struct V_60 * V_61 , T_5 * V_62 )
{
int V_63 = F_31 ( V_61 -> V_64 , 48 ) ;
int V_65 = F_31 ( V_63 + 1 , 48 ) ;
int V_66 = V_63 >> V_61 -> V_67 ;
int V_68 = ( V_65 >> V_61 -> V_67 ) - 1 ;
if ( ( V_61 -> V_69 > ( 100000000 / 8 ) ) || ( V_62 [ 0 ] == 0 ) ) {
F_32 ( L_2 ) ;
return V_70 ;
}
if ( ( V_68 > V_66 ) && ( V_68 < 256 )
&& ( V_62 [ V_66 ] == V_62 [ V_68 ] ) ) {
F_32 ( L_3 ,
V_66 , V_68 , V_62 [ V_68 ] ) ;
return V_71 ;
}
return V_70 ;
}
struct V_72 * F_33 ( struct V_60 * V_61 ,
struct V_58 * V_73 )
{
struct V_72 * V_62 ;
if ( V_73 == NULL || V_61 -> V_69 == 0 || V_61 -> V_67 == 0 ||
F_34 ( V_73 ) != V_74 )
return NULL ;
for ( V_62 = V_75 ; V_62 ; V_62 = V_62 -> V_9 ) {
if ( ! memcmp ( & V_62 -> V_69 , V_61 , sizeof( struct V_60 ) ) &&
! memcmp ( & V_62 -> V_76 , F_35 ( V_73 ) , 1024 ) ) {
V_62 -> V_77 ++ ;
return V_62 ;
}
}
V_62 = F_36 ( sizeof( * V_62 ) , V_78 ) ;
if ( V_62 ) {
V_62 -> V_69 = * V_61 ;
V_62 -> V_77 = 1 ;
memcpy ( V_62 -> V_76 , F_35 ( V_73 ) , 1024 ) ;
if ( V_61 -> V_79 == V_80 )
V_61 -> V_79 = F_30 ( V_61 , V_62 -> V_76 ) ;
V_62 -> V_9 = V_75 ;
V_75 = V_62 ;
}
return V_62 ;
}
void F_37 ( struct V_72 * V_73 )
{
struct V_72 * V_62 , * * V_81 ;
if ( ! V_73 || -- V_73 -> V_77 )
return;
for ( V_81 = & V_75 ;
( V_62 = * V_81 ) != NULL ;
V_81 = & V_62 -> V_9 ) {
if ( V_62 == V_73 ) {
* V_81 = V_62 -> V_9 ;
F_38 ( V_62 ) ;
return;
}
}
}
static struct V_82 * F_39 ( struct V_58 * V_83 )
{
struct V_58 * V_84 [ V_85 + 1 ] ;
struct V_82 * V_86 ;
struct V_87 * V_88 ;
unsigned int V_89 = 0 ;
T_6 * V_73 = NULL ;
int V_28 ;
V_28 = F_40 ( V_84 , V_85 , V_83 , V_90 , NULL ) ;
if ( V_28 < 0 )
return F_41 ( V_28 ) ;
if ( ! V_84 [ V_91 ] )
return F_41 ( - V_27 ) ;
V_88 = F_35 ( V_84 [ V_91 ] ) ;
if ( V_88 -> V_89 > 0 ) {
if ( ! V_84 [ V_92 ] )
return F_41 ( - V_27 ) ;
V_73 = F_35 ( V_84 [ V_92 ] ) ;
V_89 = F_34 ( V_84 [ V_92 ] ) / sizeof( T_6 ) ;
}
if ( V_89 != V_88 -> V_89 || ( ! V_73 && V_89 > 0 ) )
return F_41 ( - V_27 ) ;
F_42 (stab, &qdisc_stab_list, list) {
if ( memcmp ( & V_86 -> V_93 , V_88 , sizeof( * V_88 ) ) )
continue;
if ( V_89 > 0 && memcmp ( V_86 -> V_76 , V_73 , V_89 * sizeof( T_6 ) ) )
continue;
V_86 -> V_77 ++ ;
return V_86 ;
}
V_86 = F_36 ( sizeof( * V_86 ) + V_89 * sizeof( T_6 ) , V_78 ) ;
if ( ! V_86 )
return F_41 ( - V_94 ) ;
V_86 -> V_77 = 1 ;
V_86 -> V_93 = * V_88 ;
if ( V_89 > 0 )
memcpy ( V_86 -> V_76 , V_73 , V_89 * sizeof( T_6 ) ) ;
F_43 ( & V_86 -> V_95 , & V_96 ) ;
return V_86 ;
}
static void F_44 ( struct V_97 * V_98 )
{
F_38 ( F_45 ( V_98 , struct V_82 , V_99 ) ) ;
}
void F_46 ( struct V_82 * V_73 )
{
if ( ! V_73 )
return;
if ( -- V_73 -> V_77 == 0 ) {
F_47 ( & V_73 -> V_95 ) ;
F_48 ( & V_73 -> V_99 , F_44 ) ;
}
}
static int F_49 ( struct V_100 * V_101 , struct V_82 * V_86 )
{
struct V_58 * V_102 ;
V_102 = F_50 ( V_101 , V_103 ) ;
if ( V_102 == NULL )
goto V_104;
if ( F_51 ( V_101 , V_91 , sizeof( V_86 -> V_93 ) , & V_86 -> V_93 ) )
goto V_104;
F_52 ( V_101 , V_102 ) ;
return V_101 -> V_31 ;
V_104:
return - 1 ;
}
void F_53 ( struct V_100 * V_101 ,
const struct V_82 * V_86 )
{
int V_105 , V_106 ;
V_105 = V_101 -> V_31 + V_86 -> V_93 . V_107 ;
if ( F_54 ( ! V_86 -> V_93 . V_89 ) )
goto V_11;
V_106 = V_105 + V_86 -> V_93 . V_108 ;
if ( F_54 ( V_106 < 0 ) )
V_106 = 0 ;
V_106 >>= V_86 -> V_93 . V_67 ;
if ( F_55 ( V_106 < V_86 -> V_93 . V_89 ) )
V_105 = V_86 -> V_76 [ V_106 ] ;
else
V_105 = V_86 -> V_76 [ V_86 -> V_93 . V_89 - 1 ] *
( V_106 / V_86 -> V_93 . V_89 ) +
V_86 -> V_76 [ V_106 % V_86 -> V_93 . V_89 ] ;
V_105 <<= V_86 -> V_93 . V_109 ;
V_11:
if ( F_54 ( V_105 < 1 ) )
V_105 = 1 ;
F_56 ( V_101 ) -> V_105 = V_105 ;
}
void F_57 ( const char * V_110 , struct V_38 * V_47 )
{
if ( ! ( V_47 -> V_41 & V_111 ) ) {
F_58 ( L_4 ,
V_110 , V_47 -> V_34 -> V_10 , V_47 -> V_40 >> 16 ) ;
V_47 -> V_41 |= V_111 ;
}
}
static enum V_112 F_59 ( struct V_113 * V_114 )
{
struct F_59 * V_115 = F_45 ( V_114 , struct F_59 ,
V_114 ) ;
F_60 () ;
F_61 ( F_62 ( V_115 -> V_47 ) ) ;
F_63 () ;
return V_116 ;
}
void F_64 ( struct F_59 * V_115 , struct V_38 * V_47 )
{
F_65 ( & V_115 -> V_114 , V_117 , V_118 ) ;
V_115 -> V_114 . V_119 = F_59 ;
V_115 -> V_47 = V_47 ;
}
void F_66 ( struct F_59 * V_115 , T_7 V_120 )
{
if ( F_67 ( V_121 ,
& F_68 ( V_115 -> V_47 ) -> V_122 ) )
return;
if ( V_115 -> V_123 == V_120 )
return;
V_115 -> V_123 = V_120 ;
F_69 ( & V_115 -> V_114 ,
F_70 ( V_120 ) ,
V_118 ) ;
}
void F_71 ( struct F_59 * V_115 )
{
F_72 ( & V_115 -> V_114 ) ;
}
static struct V_124 * F_73 ( unsigned int V_125 )
{
unsigned int V_126 = V_125 * sizeof( struct V_124 ) , V_127 ;
struct V_124 * V_128 ;
if ( V_126 <= V_129 )
V_128 = F_36 ( V_126 , V_78 ) ;
else
V_128 = (struct V_124 * )
F_74 ( V_78 , F_75 ( V_126 ) ) ;
if ( V_128 != NULL ) {
for ( V_127 = 0 ; V_127 < V_125 ; V_127 ++ )
F_76 ( & V_128 [ V_127 ] ) ;
}
return V_128 ;
}
static void F_77 ( struct V_124 * V_128 , unsigned int V_125 )
{
unsigned int V_126 = V_125 * sizeof( struct V_124 ) ;
if ( V_126 <= V_129 )
F_38 ( V_128 ) ;
else
F_78 ( ( unsigned long ) V_128 , F_75 ( V_126 ) ) ;
}
void F_79 ( struct V_38 * V_130 , struct V_131 * V_132 )
{
struct V_133 * V_57 ;
struct V_134 * V_9 ;
struct V_124 * V_135 , * V_136 ;
unsigned int V_137 , V_138 , V_139 ;
unsigned int V_127 , V_128 ;
if ( V_132 -> V_140 * 4 <= V_132 -> V_141 * 3 )
return;
V_137 = V_132 -> V_141 * 2 ;
V_138 = V_137 - 1 ;
V_135 = F_73 ( V_137 ) ;
if ( V_135 == NULL )
return;
V_136 = V_132 -> V_50 ;
V_139 = V_132 -> V_141 ;
F_80 ( V_130 ) ;
for ( V_127 = 0 ; V_127 < V_139 ; V_127 ++ ) {
F_81 (cl, next, &ohash[i], hnode) {
V_128 = F_82 ( V_57 -> V_56 , V_138 ) ;
F_83 ( & V_57 -> V_142 , & V_135 [ V_128 ] ) ;
}
}
V_132 -> V_50 = V_135 ;
V_132 -> V_141 = V_137 ;
V_132 -> V_143 = V_138 ;
F_84 ( V_130 ) ;
F_77 ( V_136 , V_139 ) ;
}
int F_85 ( struct V_131 * V_132 )
{
unsigned int V_126 = 4 ;
V_132 -> V_50 = F_73 ( V_126 ) ;
if ( V_132 -> V_50 == NULL )
return - V_94 ;
V_132 -> V_141 = V_126 ;
V_132 -> V_143 = V_126 - 1 ;
V_132 -> V_140 = 0 ;
return 0 ;
}
void F_86 ( struct V_131 * V_132 )
{
F_77 ( V_132 -> V_50 , V_132 -> V_141 ) ;
}
void F_87 ( struct V_131 * V_132 ,
struct V_133 * V_57 )
{
unsigned int V_128 ;
F_88 ( & V_57 -> V_142 ) ;
V_128 = F_82 ( V_57 -> V_56 , V_132 -> V_143 ) ;
F_83 ( & V_57 -> V_142 , & V_132 -> V_50 [ V_128 ] ) ;
V_132 -> V_140 ++ ;
}
void F_89 ( struct V_131 * V_132 ,
struct V_133 * V_57 )
{
F_90 ( & V_57 -> V_142 ) ;
V_132 -> V_140 -- ;
}
static T_3 F_91 ( struct V_52 * V_53 )
{
int V_127 = 0x8000 ;
static T_3 V_144 = F_92 ( 0x80000000U , 0 ) ;
do {
V_144 += F_92 ( 0x10000U , 0 ) ;
if ( V_144 == F_92 ( V_45 , 0 ) )
V_144 = F_92 ( 0x80000000U , 0 ) ;
if ( ! F_25 ( V_53 , V_144 ) )
return V_144 ;
F_93 () ;
} while ( -- V_127 > 0 );
return 0 ;
}
void F_94 ( struct V_38 * V_130 , unsigned int V_125 ,
unsigned int V_31 )
{
const struct V_18 * V_19 ;
unsigned long V_57 ;
T_3 V_145 ;
int V_146 ;
if ( V_125 == 0 && V_31 == 0 )
return;
V_146 = F_95 ( int , V_125 , 0 ) ;
F_60 () ;
while ( ( V_145 = V_130 -> V_44 ) ) {
if ( F_96 ( V_145 ) == F_96 ( V_147 ) )
break;
if ( V_130 -> V_41 & V_148 )
break;
V_130 = F_25 ( F_17 ( V_130 ) , F_96 ( V_145 ) ) ;
if ( V_130 == NULL ) {
F_20 ( V_145 != V_45 ) ;
break;
}
V_19 = V_130 -> V_34 -> V_17 ;
if ( V_19 -> V_149 ) {
V_57 = V_19 -> V_20 ( V_130 , V_145 ) ;
V_19 -> V_149 ( V_130 , V_57 ) ;
V_19 -> V_21 ( V_130 , V_57 ) ;
}
V_130 -> V_3 . V_150 -= V_125 ;
V_130 -> V_151 . V_152 -= V_31 ;
F_97 ( V_130 , V_146 ) ;
}
F_63 () ;
}
static void F_98 ( struct V_153 * V_153 , struct V_100 * V_101 ,
struct V_154 * V_125 , T_3 V_155 ,
struct V_38 * V_156 , struct V_38 * V_157 )
{
if ( V_157 || V_156 )
F_99 ( V_153 , V_101 , V_125 , V_155 , V_156 , V_157 ) ;
if ( V_156 )
F_100 ( V_156 ) ;
}
static int F_101 ( struct V_52 * V_53 , struct V_38 * V_44 ,
struct V_100 * V_101 , struct V_154 * V_125 , T_3 V_56 ,
struct V_38 * V_157 , struct V_38 * V_156 )
{
struct V_38 * V_3 = V_156 ;
struct V_153 * V_153 = F_102 ( V_53 ) ;
int V_28 = 0 ;
if ( V_44 == NULL ) {
unsigned int V_127 , V_158 , V_159 ;
V_159 = 0 ;
V_158 = V_53 -> V_160 ;
if ( ( V_3 && V_3 -> V_41 & V_46 ) ||
( V_157 && V_157 -> V_41 & V_46 ) ) {
V_158 = 1 ;
V_159 = 1 ;
if ( ! F_26 ( V_53 ) )
return - V_29 ;
}
if ( V_53 -> V_41 & V_161 )
F_103 ( V_53 ) ;
if ( V_157 && V_157 -> V_34 -> V_162 )
goto V_163;
for ( V_127 = 0 ; V_127 < V_158 ; V_127 ++ ) {
struct V_164 * V_165 = F_26 ( V_53 ) ;
if ( ! V_159 )
V_165 = F_104 ( V_53 , V_127 ) ;
V_156 = F_105 ( V_165 , V_157 ) ;
if ( V_157 && V_127 > 0 )
F_106 ( & V_157 -> V_77 ) ;
if ( ! V_159 )
F_100 ( V_156 ) ;
}
V_163:
if ( ! V_159 ) {
F_98 ( V_153 , V_101 , V_125 , V_56 ,
V_53 -> V_47 , V_157 ) ;
if ( V_157 && ! V_157 -> V_34 -> V_162 )
F_106 ( & V_157 -> V_77 ) ;
V_53 -> V_47 = V_157 ? : & V_48 ;
if ( V_157 && V_157 -> V_34 -> V_162 )
V_157 -> V_34 -> V_162 ( V_157 ) ;
} else {
F_98 ( V_153 , V_101 , V_125 , V_56 , V_156 , V_157 ) ;
}
if ( V_53 -> V_41 & V_161 )
F_107 ( V_53 ) ;
} else {
const struct V_18 * V_19 = V_44 -> V_34 -> V_17 ;
V_28 = - V_166 ;
if ( V_19 && V_19 -> V_167 ) {
unsigned long V_57 = V_19 -> V_20 ( V_44 , V_56 ) ;
if ( V_57 ) {
V_28 = V_19 -> V_167 ( V_44 , V_57 , V_157 , & V_156 ) ;
V_19 -> V_21 ( V_44 , V_57 ) ;
} else
V_28 = - V_29 ;
}
if ( ! V_28 )
F_98 ( V_153 , V_101 , V_125 , V_56 , V_156 , V_157 ) ;
}
return V_28 ;
}
static struct V_38 * F_108 ( struct V_52 * V_53 ,
struct V_164 * V_165 ,
struct V_38 * V_55 , T_3 V_44 , T_3 V_40 ,
struct V_58 * * V_168 , int * V_169 )
{
int V_28 ;
struct V_58 * V_59 = V_168 [ V_170 ] ;
struct V_38 * V_130 ;
struct V_1 * V_34 ;
struct V_82 * V_86 ;
V_34 = F_28 ( V_59 ) ;
#ifdef F_109
if ( V_34 == NULL && V_59 != NULL ) {
char V_30 [ V_171 ] ;
if ( F_110 ( V_30 , V_59 , V_171 ) < V_171 ) {
F_111 () ;
F_13 ( L_1 , V_30 ) ;
F_112 () ;
V_34 = F_28 ( V_59 ) ;
if ( V_34 != NULL ) {
F_14 ( V_34 -> V_33 ) ;
V_28 = - V_172 ;
goto V_173;
}
}
}
#endif
V_28 = - V_29 ;
if ( V_34 == NULL )
goto V_173;
V_130 = F_113 ( V_165 , V_34 ) ;
if ( F_114 ( V_130 ) ) {
V_28 = F_115 ( V_130 ) ;
goto V_174;
}
V_130 -> V_44 = V_44 ;
if ( V_40 == V_147 ) {
V_130 -> V_41 |= V_46 ;
V_40 = F_92 ( V_147 , 0 ) ;
F_116 ( F_117 ( V_130 ) , & V_175 ) ;
} else {
if ( V_40 == 0 ) {
V_40 = F_91 ( V_53 ) ;
V_28 = - V_94 ;
if ( V_40 == 0 )
goto V_176;
}
F_116 ( F_117 ( V_130 ) , & V_177 ) ;
if ( ! F_118 ( V_53 ) )
V_130 -> V_41 |= V_178 ;
}
V_130 -> V_40 = V_40 ;
if ( ( V_53 -> V_179 & V_180 ) && ( V_53 -> V_181 == 0 ) ) {
V_53 -> V_181 = V_182 ;
F_119 ( V_53 , L_5 ) ;
}
if ( ! V_34 -> V_183 || ( V_28 = V_34 -> V_183 ( V_130 , V_168 [ V_184 ] ) ) == 0 ) {
if ( F_120 ( V_130 ) ) {
V_130 -> V_185 =
F_121 ( struct V_186 ) ;
if ( ! V_130 -> V_185 )
goto V_187;
V_130 -> V_188 = F_122 ( struct V_189 ) ;
if ( ! V_130 -> V_188 )
goto V_187;
}
if ( V_168 [ V_103 ] ) {
V_86 = F_39 ( V_168 [ V_103 ] ) ;
if ( F_114 ( V_86 ) ) {
V_28 = F_115 ( V_86 ) ;
goto V_187;
}
F_123 ( V_130 -> V_86 , V_86 ) ;
}
if ( V_168 [ V_190 ] ) {
T_8 * V_191 ;
V_28 = - V_166 ;
if ( V_130 -> V_41 & V_192 )
goto V_187;
if ( ( V_130 -> V_44 != V_45 ) &&
! ( V_130 -> V_41 & V_46 ) &&
( ! V_55 || ! ( V_55 -> V_41 & V_192 ) ) )
V_191 = F_124 ( V_130 ) ;
else
V_191 = & V_130 -> V_191 ;
V_28 = F_125 ( & V_130 -> V_193 ,
V_130 -> V_185 ,
& V_130 -> V_194 ,
NULL ,
V_191 ,
V_168 [ V_190 ] ) ;
if ( V_28 )
goto V_187;
}
F_19 ( V_130 , false ) ;
return V_130 ;
}
if ( V_34 -> V_195 )
V_34 -> V_195 ( V_130 ) ;
V_176:
F_126 ( V_53 ) ;
F_38 ( ( char * ) V_130 - V_130 -> V_196 ) ;
V_174:
F_14 ( V_34 -> V_33 ) ;
V_173:
* V_169 = V_28 ;
return NULL ;
V_187:
F_127 ( V_130 -> V_185 ) ;
F_127 ( V_130 -> V_188 ) ;
F_46 ( F_128 ( V_130 -> V_86 ) ) ;
if ( V_34 -> V_195 )
V_34 -> V_195 ( V_130 ) ;
goto V_176;
}
static int F_129 ( struct V_38 * V_130 , struct V_58 * * V_168 )
{
struct V_82 * V_197 , * V_86 = NULL ;
int V_28 = 0 ;
if ( V_168 [ V_184 ] ) {
if ( V_130 -> V_34 -> V_198 == NULL )
return - V_27 ;
V_28 = V_130 -> V_34 -> V_198 ( V_130 , V_168 [ V_184 ] ) ;
if ( V_28 )
return V_28 ;
}
if ( V_168 [ V_103 ] ) {
V_86 = F_39 ( V_168 [ V_103 ] ) ;
if ( F_114 ( V_86 ) )
return F_115 ( V_86 ) ;
}
V_197 = F_128 ( V_130 -> V_86 ) ;
F_123 ( V_130 -> V_86 , V_86 ) ;
F_46 ( V_197 ) ;
if ( V_168 [ V_190 ] ) {
if ( V_130 -> V_41 & V_192 )
goto V_11;
F_130 ( & V_130 -> V_193 ,
V_130 -> V_185 ,
& V_130 -> V_194 ,
NULL ,
F_124 ( V_130 ) ,
V_168 [ V_190 ] ) ;
}
V_11:
return 0 ;
}
static int F_131 ( struct V_38 * V_3 , struct V_38 * V_55 , int V_199 )
{
struct V_200 V_201 ;
if ( V_3 -> V_34 -> V_17 == NULL )
return 0 ;
V_201 . V_202 . V_203 = V_201 . V_202 . V_163 = V_201 . V_202 . V_204 = 0 ;
V_201 . V_202 . V_205 = V_206 ;
V_201 . V_199 = V_199 ;
V_201 . V_55 = V_55 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_201 . V_202 ) ;
return V_201 . V_202 . V_203 ? - V_207 : 0 ;
}
static int
V_206 ( struct V_38 * V_3 , unsigned long V_57 , struct V_208 * V_202 )
{
struct V_38 * V_23 ;
const struct V_18 * V_19 = V_3 -> V_34 -> V_17 ;
struct V_200 * V_201 = (struct V_200 * ) V_202 ;
V_23 = V_19 -> V_23 ( V_3 , V_57 ) ;
if ( V_23 ) {
if ( V_23 == V_201 -> V_55 || V_201 -> V_199 > 7 )
return - V_207 ;
return F_131 ( V_23 , V_201 -> V_55 , V_201 -> V_199 + 1 ) ;
}
return 0 ;
}
static int F_132 ( struct V_100 * V_101 , struct V_154 * V_125 ,
struct V_209 * V_210 )
{
struct V_153 * V_153 = F_133 ( V_101 -> V_211 ) ;
struct V_212 * V_213 = F_134 ( V_125 ) ;
struct V_58 * V_168 [ V_214 + 1 ] ;
struct V_52 * V_53 ;
T_3 V_155 ;
struct V_38 * V_3 = NULL ;
struct V_38 * V_55 = NULL ;
int V_28 ;
if ( ( V_125 -> V_215 != V_216 ) &&
! F_135 ( V_101 , V_153 -> V_217 , V_35 ) )
return - V_36 ;
V_28 = F_136 ( V_125 , sizeof( * V_213 ) , V_168 , V_214 , NULL , V_210 ) ;
if ( V_28 < 0 )
return V_28 ;
V_53 = F_137 ( V_153 , V_213 -> V_218 ) ;
if ( ! V_53 )
return - V_219 ;
V_155 = V_213 -> V_220 ;
if ( V_155 ) {
if ( V_155 != V_45 ) {
if ( F_96 ( V_155 ) != F_96 ( V_147 ) ) {
V_55 = F_25 ( V_53 , F_96 ( V_155 ) ) ;
if ( ! V_55 )
return - V_29 ;
V_3 = F_27 ( V_55 , V_155 ) ;
} else if ( F_26 ( V_53 ) ) {
V_3 = F_26 ( V_53 ) -> V_54 ;
}
} else {
V_3 = V_53 -> V_47 ;
}
if ( ! V_3 )
return - V_29 ;
if ( V_213 -> V_221 && V_3 -> V_40 != V_213 -> V_221 )
return - V_27 ;
} else {
V_3 = F_25 ( V_53 , V_213 -> V_221 ) ;
if ( ! V_3 )
return - V_29 ;
}
if ( V_168 [ V_170 ] && F_29 ( V_168 [ V_170 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_125 -> V_215 == V_222 ) {
if ( ! V_155 )
return - V_27 ;
if ( V_3 -> V_40 == 0 )
return - V_29 ;
V_28 = F_101 ( V_53 , V_55 , V_101 , V_125 , V_155 , NULL , V_3 ) ;
if ( V_28 != 0 )
return V_28 ;
} else {
F_99 ( V_153 , V_101 , V_125 , V_155 , NULL , V_3 ) ;
}
return 0 ;
}
static int F_138 ( struct V_100 * V_101 , struct V_154 * V_125 ,
struct V_209 * V_210 )
{
struct V_153 * V_153 = F_133 ( V_101 -> V_211 ) ;
struct V_212 * V_213 ;
struct V_58 * V_168 [ V_214 + 1 ] ;
struct V_52 * V_53 ;
T_3 V_155 ;
struct V_38 * V_3 , * V_55 ;
int V_28 ;
if ( ! F_135 ( V_101 , V_153 -> V_217 , V_35 ) )
return - V_36 ;
V_223:
V_28 = F_136 ( V_125 , sizeof( * V_213 ) , V_168 , V_214 , NULL , V_210 ) ;
if ( V_28 < 0 )
return V_28 ;
V_213 = F_134 ( V_125 ) ;
V_155 = V_213 -> V_220 ;
V_3 = V_55 = NULL ;
V_53 = F_137 ( V_153 , V_213 -> V_218 ) ;
if ( ! V_53 )
return - V_219 ;
if ( V_155 ) {
if ( V_155 != V_45 ) {
if ( V_155 != V_147 ) {
V_55 = F_25 ( V_53 , F_96 ( V_155 ) ) ;
if ( ! V_55 )
return - V_29 ;
V_3 = F_27 ( V_55 , V_155 ) ;
} else if ( F_139 ( V_53 ) ) {
V_3 = F_26 ( V_53 ) -> V_54 ;
}
} else {
V_3 = V_53 -> V_47 ;
}
if ( V_3 && V_3 -> V_40 == 0 )
V_3 = NULL ;
if ( ! V_3 || ! V_213 -> V_221 || V_3 -> V_40 != V_213 -> V_221 ) {
if ( V_213 -> V_221 ) {
if ( V_3 && ! ( V_125 -> V_224 & V_225 ) )
return - V_6 ;
if ( F_140 ( V_213 -> V_221 ) )
return - V_27 ;
V_3 = F_25 ( V_53 , V_213 -> V_221 ) ;
if ( ! V_3 )
goto V_226;
if ( V_125 -> V_224 & V_227 )
return - V_6 ;
if ( V_168 [ V_170 ] && F_29 ( V_168 [ V_170 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_3 == V_55 ||
( V_55 && F_131 ( V_3 , V_55 , 0 ) ) )
return - V_207 ;
F_106 ( & V_3 -> V_77 ) ;
goto V_167;
} else {
if ( ! V_3 )
goto V_226;
if ( ( V_125 -> V_224 & V_228 ) &&
( V_125 -> V_224 & V_225 ) &&
( ( V_125 -> V_224 & V_227 ) ||
( V_168 [ V_170 ] &&
F_29 ( V_168 [ V_170 ] , V_3 -> V_34 -> V_10 ) ) ) )
goto V_226;
}
}
} else {
if ( ! V_213 -> V_221 )
return - V_27 ;
V_3 = F_25 ( V_53 , V_213 -> V_221 ) ;
}
if ( V_3 == NULL )
return - V_29 ;
if ( V_125 -> V_224 & V_227 )
return - V_6 ;
if ( V_168 [ V_170 ] && F_29 ( V_168 [ V_170 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
V_28 = F_129 ( V_3 , V_168 ) ;
if ( V_28 == 0 )
F_99 ( V_153 , V_101 , V_125 , V_155 , NULL , V_3 ) ;
return V_28 ;
V_226:
if ( ! ( V_125 -> V_224 & V_228 ) )
return - V_29 ;
if ( V_155 == V_147 ) {
if ( F_26 ( V_53 ) )
V_3 = F_108 ( V_53 , F_26 ( V_53 ) , V_55 ,
V_213 -> V_220 , V_213 -> V_220 ,
V_168 , & V_28 ) ;
else
V_28 = - V_29 ;
} else {
struct V_164 * V_165 ;
if ( V_55 && V_55 -> V_34 -> V_17 && V_55 -> V_34 -> V_17 -> V_229 )
V_165 = V_55 -> V_34 -> V_17 -> V_229 ( V_55 , V_213 ) ;
else if ( V_55 )
V_165 = V_55 -> V_165 ;
else
V_165 = F_104 ( V_53 , 0 ) ;
V_3 = F_108 ( V_53 , V_165 , V_55 ,
V_213 -> V_220 , V_213 -> V_221 ,
V_168 , & V_28 ) ;
}
if ( V_3 == NULL ) {
if ( V_28 == - V_172 )
goto V_223;
return V_28 ;
}
V_167:
V_28 = F_101 ( V_53 , V_55 , V_101 , V_125 , V_155 , V_3 , NULL ) ;
if ( V_28 ) {
if ( V_3 )
F_100 ( V_3 ) ;
return V_28 ;
}
return 0 ;
}
static int F_141 ( struct V_100 * V_101 , struct V_38 * V_3 , T_3 V_155 ,
T_3 V_230 , T_3 V_231 , T_6 V_41 , int V_232 )
{
struct V_186 T_9 * V_185 = NULL ;
struct V_189 T_9 * V_188 = NULL ;
struct V_212 * V_213 ;
struct V_154 * V_233 ;
unsigned char * V_234 = F_142 ( V_101 ) ;
struct V_235 V_236 ;
struct V_82 * V_86 ;
T_5 V_150 ;
F_93 () ;
V_233 = F_143 ( V_101 , V_230 , V_231 , V_232 , sizeof( * V_213 ) , V_41 ) ;
if ( ! V_233 )
goto V_237;
V_213 = F_134 ( V_233 ) ;
V_213 -> V_238 = V_239 ;
V_213 -> V_240 = 0 ;
V_213 -> V_241 = 0 ;
V_213 -> V_218 = F_17 ( V_3 ) -> V_242 ;
V_213 -> V_220 = V_155 ;
V_213 -> V_221 = V_3 -> V_40 ;
V_213 -> V_243 = F_144 ( & V_3 -> V_77 ) ;
if ( F_145 ( V_101 , V_170 , V_3 -> V_34 -> V_10 ) )
goto V_104;
if ( V_3 -> V_34 -> V_244 && V_3 -> V_34 -> V_244 ( V_3 , V_101 ) < 0 )
goto V_104;
V_150 = V_3 -> V_3 . V_150 ;
V_86 = F_128 ( V_3 -> V_86 ) ;
if ( V_86 && F_49 ( V_101 , V_86 ) < 0 )
goto V_104;
if ( F_146 ( V_101 , V_245 , V_246 , V_247 ,
NULL , & V_236 , V_248 ) < 0 )
goto V_104;
if ( V_3 -> V_34 -> V_249 && V_3 -> V_34 -> V_249 ( V_3 , & V_236 ) < 0 )
goto V_104;
if ( F_120 ( V_3 ) ) {
V_185 = V_3 -> V_185 ;
V_188 = V_3 -> V_188 ;
}
if ( F_147 ( F_124 ( V_3 ) ,
& V_236 , V_185 , & V_3 -> V_193 ) < 0 ||
F_148 ( & V_236 , & V_3 -> V_194 ) < 0 ||
F_149 ( & V_236 , V_188 , & V_3 -> V_151 , V_150 ) < 0 )
goto V_104;
if ( F_150 ( & V_236 ) < 0 )
goto V_104;
V_233 -> V_250 = F_142 ( V_101 ) - V_234 ;
return V_101 -> V_31 ;
V_237:
V_104:
F_151 ( V_101 , V_234 ) ;
return - 1 ;
}
static bool F_152 ( struct V_38 * V_3 , bool V_251 )
{
if ( V_3 -> V_41 & V_42 )
return true ;
if ( ( V_3 -> V_41 & V_51 ) && ! V_251 )
return true ;
return false ;
}
static int F_99 ( struct V_153 * V_153 , struct V_100 * V_252 ,
struct V_154 * V_125 , T_3 V_155 ,
struct V_38 * V_156 , struct V_38 * V_157 )
{
struct V_100 * V_101 ;
T_3 V_230 = V_252 ? F_153 ( V_252 ) . V_230 : 0 ;
V_101 = F_154 ( V_253 , V_78 ) ;
if ( ! V_101 )
return - V_254 ;
if ( V_156 && ! F_152 ( V_156 , false ) ) {
if ( F_141 ( V_101 , V_156 , V_155 , V_230 , V_125 -> V_255 ,
0 , V_222 ) < 0 )
goto V_173;
}
if ( V_157 && ! F_152 ( V_157 , false ) ) {
if ( F_141 ( V_101 , V_157 , V_155 , V_230 , V_125 -> V_255 ,
V_156 ? V_225 : 0 , V_256 ) < 0 )
goto V_173;
}
if ( V_101 -> V_31 )
return F_155 ( V_101 , V_153 , V_230 , V_257 ,
V_125 -> V_224 & V_258 ) ;
V_173:
F_156 ( V_101 ) ;
return - V_27 ;
}
static int F_157 ( struct V_38 * V_39 , struct V_100 * V_101 ,
struct V_259 * V_260 ,
int * V_261 , int V_262 , bool V_263 ,
bool V_251 )
{
int V_264 = 0 , V_265 = * V_261 ;
struct V_38 * V_3 ;
int V_234 ;
if ( ! V_39 )
return 0 ;
V_3 = V_39 ;
if ( V_265 < V_262 ) {
V_265 ++ ;
} else {
if ( ! F_152 ( V_3 , V_251 ) &&
F_141 ( V_101 , V_3 , V_3 -> V_44 , F_153 ( V_260 -> V_101 ) . V_230 ,
V_260 -> V_233 -> V_255 , V_266 ,
V_256 ) <= 0 )
goto V_267;
V_265 ++ ;
}
if ( ! F_17 ( V_39 ) || ! V_263 )
goto V_11;
F_158 (qdisc_dev(root)->qdisc_hash, b, q, hash) {
if ( V_265 < V_262 ) {
V_265 ++ ;
continue;
}
if ( ! F_152 ( V_3 , V_251 ) &&
F_141 ( V_101 , V_3 , V_3 -> V_44 , F_153 ( V_260 -> V_101 ) . V_230 ,
V_260 -> V_233 -> V_255 , V_266 ,
V_256 ) <= 0 )
goto V_267;
V_265 ++ ;
}
V_11:
* V_261 = V_265 ;
return V_264 ;
V_267:
V_264 = - 1 ;
goto V_11;
}
static int F_159 ( struct V_100 * V_101 , struct V_259 * V_260 )
{
struct V_153 * V_153 = F_133 ( V_101 -> V_211 ) ;
int V_268 , V_265 ;
int V_269 , V_262 ;
struct V_52 * V_53 ;
const struct V_154 * V_233 = V_260 -> V_233 ;
struct V_212 * V_213 = F_134 ( V_233 ) ;
struct V_58 * V_168 [ V_214 + 1 ] ;
int V_28 ;
V_269 = V_260 -> args [ 0 ] ;
V_262 = V_265 = V_260 -> args [ 1 ] ;
V_268 = 0 ;
F_21 () ;
V_28 = F_136 ( V_233 , sizeof( * V_213 ) , V_168 , V_214 , NULL , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
F_160 (net, dev) {
struct V_164 * V_165 ;
if ( V_268 < V_269 )
goto V_270;
if ( V_268 > V_269 )
V_262 = 0 ;
V_265 = 0 ;
if ( F_157 ( V_53 -> V_47 , V_101 , V_260 , & V_265 , V_262 ,
true , V_168 [ V_271 ] ) < 0 )
goto V_267;
V_165 = F_26 ( V_53 ) ;
if ( V_165 &&
F_157 ( V_165 -> V_54 , V_101 , V_260 ,
& V_265 , V_262 , false ,
V_168 [ V_271 ] ) < 0 )
goto V_267;
V_270:
V_268 ++ ;
}
V_267:
V_260 -> args [ 0 ] = V_268 ;
V_260 -> args [ 1 ] = V_265 ;
return V_101 -> V_31 ;
}
static int F_161 ( struct V_100 * V_101 , struct V_154 * V_125 ,
struct V_209 * V_210 )
{
struct V_153 * V_153 = F_133 ( V_101 -> V_211 ) ;
struct V_212 * V_213 = F_134 ( V_125 ) ;
struct V_58 * V_168 [ V_214 + 1 ] ;
struct V_52 * V_53 ;
struct V_38 * V_3 = NULL ;
const struct V_18 * V_19 ;
unsigned long V_57 = 0 ;
unsigned long V_272 ;
T_3 V_230 ;
T_3 V_155 ;
T_3 V_273 ;
int V_28 ;
if ( ( V_125 -> V_215 != V_274 ) &&
! F_135 ( V_101 , V_153 -> V_217 , V_35 ) )
return - V_36 ;
V_28 = F_136 ( V_125 , sizeof( * V_213 ) , V_168 , V_214 , NULL , V_210 ) ;
if ( V_28 < 0 )
return V_28 ;
V_53 = F_137 ( V_153 , V_213 -> V_218 ) ;
if ( ! V_53 )
return - V_219 ;
V_230 = V_213 -> V_220 ;
V_155 = V_213 -> V_221 ;
V_273 = F_96 ( V_155 ) ;
if ( V_230 != V_45 ) {
T_3 V_275 = F_96 ( V_230 ) ;
if ( V_273 && V_275 ) {
if ( V_273 != V_275 )
return - V_27 ;
} else if ( V_275 ) {
V_273 = V_275 ;
} else if ( V_273 == 0 )
V_273 = V_53 -> V_47 -> V_40 ;
if ( V_230 )
V_230 = F_92 ( V_273 , V_230 ) ;
} else {
if ( V_273 == 0 )
V_273 = V_53 -> V_47 -> V_40 ;
}
V_3 = F_25 ( V_53 , V_273 ) ;
if ( ! V_3 )
return - V_29 ;
V_19 = V_3 -> V_34 -> V_17 ;
if ( V_19 == NULL )
return - V_27 ;
if ( V_155 == 0 ) {
if ( V_230 == V_45 )
V_155 = V_273 ;
} else
V_155 = F_92 ( V_273 , V_155 ) ;
if ( V_155 )
V_57 = V_19 -> V_20 ( V_3 , V_155 ) ;
if ( V_57 == 0 ) {
V_28 = - V_29 ;
if ( V_125 -> V_215 != V_276 ||
! ( V_125 -> V_224 & V_228 ) )
goto V_11;
} else {
switch ( V_125 -> V_215 ) {
case V_276 :
V_28 = - V_6 ;
if ( V_125 -> V_224 & V_227 )
goto V_11;
break;
case V_277 :
V_28 = - V_166 ;
if ( V_19 -> V_278 )
V_28 = V_19 -> V_278 ( V_3 , V_57 ) ;
if ( V_28 == 0 )
F_162 ( V_153 , V_101 , V_125 , V_3 , V_57 ,
V_277 ) ;
goto V_11;
case V_274 :
V_28 = F_162 ( V_153 , V_101 , V_125 , V_3 , V_57 , V_276 ) ;
goto V_11;
default:
V_28 = - V_27 ;
goto V_11;
}
}
V_272 = V_57 ;
V_28 = - V_166 ;
if ( V_19 -> V_198 )
V_28 = V_19 -> V_198 ( V_3 , V_155 , V_230 , V_168 , & V_272 ) ;
if ( V_28 == 0 )
F_162 ( V_153 , V_101 , V_125 , V_3 , V_272 , V_276 ) ;
V_11:
if ( V_57 )
V_19 -> V_21 ( V_3 , V_57 ) ;
return V_28 ;
}
static int F_163 ( struct V_100 * V_101 , struct V_38 * V_3 ,
unsigned long V_57 ,
T_3 V_230 , T_3 V_231 , T_6 V_41 , int V_232 )
{
struct V_212 * V_213 ;
struct V_154 * V_233 ;
unsigned char * V_234 = F_142 ( V_101 ) ;
struct V_235 V_236 ;
const struct V_18 * V_17 = V_3 -> V_34 -> V_17 ;
F_93 () ;
V_233 = F_143 ( V_101 , V_230 , V_231 , V_232 , sizeof( * V_213 ) , V_41 ) ;
if ( ! V_233 )
goto V_237;
V_213 = F_134 ( V_233 ) ;
V_213 -> V_238 = V_239 ;
V_213 -> V_240 = 0 ;
V_213 -> V_241 = 0 ;
V_213 -> V_218 = F_17 ( V_3 ) -> V_242 ;
V_213 -> V_220 = V_3 -> V_40 ;
V_213 -> V_221 = V_3 -> V_40 ;
V_213 -> V_243 = 0 ;
if ( F_145 ( V_101 , V_170 , V_3 -> V_34 -> V_10 ) )
goto V_104;
if ( V_17 -> V_244 && V_17 -> V_244 ( V_3 , V_57 , V_101 , V_213 ) < 0 )
goto V_104;
if ( F_146 ( V_101 , V_245 , V_246 , V_247 ,
NULL , & V_236 , V_248 ) < 0 )
goto V_104;
if ( V_17 -> V_249 && V_17 -> V_249 ( V_3 , V_57 , & V_236 ) < 0 )
goto V_104;
if ( F_150 ( & V_236 ) < 0 )
goto V_104;
V_233 -> V_250 = F_142 ( V_101 ) - V_234 ;
return V_101 -> V_31 ;
V_237:
V_104:
F_151 ( V_101 , V_234 ) ;
return - 1 ;
}
static int F_162 ( struct V_153 * V_153 , struct V_100 * V_252 ,
struct V_154 * V_125 , struct V_38 * V_3 ,
unsigned long V_57 , int V_232 )
{
struct V_100 * V_101 ;
T_3 V_230 = V_252 ? F_153 ( V_252 ) . V_230 : 0 ;
V_101 = F_154 ( V_253 , V_78 ) ;
if ( ! V_101 )
return - V_254 ;
if ( F_163 ( V_101 , V_3 , V_57 , V_230 , V_125 -> V_255 , 0 , V_232 ) < 0 ) {
F_156 ( V_101 ) ;
return - V_27 ;
}
return F_155 ( V_101 , V_153 , V_230 , V_257 ,
V_125 -> V_224 & V_258 ) ;
}
static int F_164 ( struct V_38 * V_3 , unsigned long V_57 ,
struct V_208 * V_201 )
{
struct V_279 * V_280 = (struct V_279 * ) V_201 ;
return F_163 ( V_280 -> V_101 , V_3 , V_57 , F_153 ( V_280 -> V_260 -> V_101 ) . V_230 ,
V_280 -> V_260 -> V_233 -> V_255 , V_266 ,
V_276 ) ;
}
static int F_165 ( struct V_38 * V_3 , struct V_100 * V_101 ,
struct V_212 * V_213 , struct V_259 * V_260 ,
int * V_281 , int V_282 )
{
struct V_279 V_201 ;
if ( F_152 ( V_3 , false ) ||
* V_281 < V_282 || ! V_3 -> V_34 -> V_17 ||
( V_213 -> V_220 &&
F_96 ( V_213 -> V_220 ) != V_3 -> V_40 ) ) {
( * V_281 ) ++ ;
return 0 ;
}
if ( * V_281 > V_282 )
memset ( & V_260 -> args [ 1 ] , 0 , sizeof( V_260 -> args ) - sizeof( V_260 -> args [ 0 ] ) ) ;
V_201 . V_202 . V_205 = F_164 ;
V_201 . V_101 = V_101 ;
V_201 . V_260 = V_260 ;
V_201 . V_202 . V_203 = 0 ;
V_201 . V_202 . V_163 = V_260 -> args [ 1 ] ;
V_201 . V_202 . V_204 = 0 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_201 . V_202 ) ;
V_260 -> args [ 1 ] = V_201 . V_202 . V_204 ;
if ( V_201 . V_202 . V_203 )
return - 1 ;
( * V_281 ) ++ ;
return 0 ;
}
static int F_166 ( struct V_38 * V_39 , struct V_100 * V_101 ,
struct V_212 * V_213 , struct V_259 * V_260 ,
int * V_281 , int V_282 )
{
struct V_38 * V_3 ;
int V_234 ;
if ( ! V_39 )
return 0 ;
if ( F_165 ( V_39 , V_101 , V_213 , V_260 , V_281 , V_282 ) < 0 )
return - 1 ;
if ( ! F_17 ( V_39 ) )
return 0 ;
if ( V_213 -> V_220 ) {
V_3 = F_16 ( V_39 , F_96 ( V_213 -> V_220 ) ) ;
if ( V_3 && F_165 ( V_3 , V_101 , V_213 , V_260 , V_281 , V_282 ) < 0 )
return - 1 ;
return 0 ;
}
F_158 (qdisc_dev(root)->qdisc_hash, b, q, hash) {
if ( F_165 ( V_3 , V_101 , V_213 , V_260 , V_281 , V_282 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_167 ( struct V_100 * V_101 , struct V_259 * V_260 )
{
struct V_212 * V_213 = F_134 ( V_260 -> V_233 ) ;
struct V_153 * V_153 = F_133 ( V_101 -> V_211 ) ;
struct V_164 * V_165 ;
struct V_52 * V_53 ;
int V_283 , V_282 ;
if ( V_250 ( V_260 -> V_233 ) < sizeof( * V_213 ) )
return 0 ;
V_53 = F_168 ( V_153 , V_213 -> V_218 ) ;
if ( ! V_53 )
return 0 ;
V_282 = V_260 -> args [ 0 ] ;
V_283 = 0 ;
if ( F_166 ( V_53 -> V_47 , V_101 , V_213 , V_260 , & V_283 , V_282 ) < 0 )
goto V_267;
V_165 = F_26 ( V_53 ) ;
if ( V_165 &&
F_166 ( V_165 -> V_54 , V_101 , V_213 , V_260 ,
& V_283 , V_282 ) < 0 )
goto V_267;
V_267:
V_260 -> args [ 0 ] = V_283 ;
F_126 ( V_53 ) ;
return V_101 -> V_31 ;
}
int F_169 ( struct V_100 * V_101 , const struct V_284 * V_285 ,
struct V_286 * V_287 , bool V_288 )
{
T_10 V_289 = F_170 ( V_101 ) ;
#ifdef F_171
const int V_290 = 4 ;
const struct V_284 * V_291 = V_285 ;
int V_292 = 0 ;
V_293:
#endif
for (; V_285 ; V_285 = F_172 ( V_285 -> V_9 ) ) {
int V_28 ;
if ( V_285 -> V_289 != V_289 &&
V_285 -> V_289 != F_173 ( V_294 ) )
continue;
V_28 = V_285 -> V_295 ( V_101 , V_285 , V_287 ) ;
#ifdef F_171
if ( F_54 ( V_28 == V_296 && ! V_288 ) )
goto V_297;
#endif
if ( V_28 >= 0 )
return V_28 ;
}
return V_298 ;
#ifdef F_171
V_297:
if ( F_54 ( V_292 ++ >= V_290 ) ) {
F_174 ( L_6 ,
V_285 -> V_3 -> V_34 -> V_10 , V_285 -> V_299 & 0xffff ,
F_175 ( V_285 -> V_289 ) ) ;
return V_300 ;
}
V_285 = V_291 ;
V_289 = F_170 ( V_101 ) ;
goto V_293;
#endif
}
static int F_176 ( struct V_301 * V_231 , void * V_302 )
{
F_177 ( V_231 , L_7 ,
( T_3 ) V_303 , ( T_3 ) F_178 ( 1 ) ,
1000000 ,
( T_3 ) V_304 / V_305 ) ;
return 0 ;
}
static int F_179 ( struct V_306 * V_306 , struct V_307 * V_307 )
{
return F_180 ( V_307 , F_176 , NULL ) ;
}
static int T_11 F_181 ( struct V_153 * V_153 )
{
struct V_308 * V_309 ;
V_309 = F_182 ( L_8 , 0 , V_153 -> V_310 , & V_311 ) ;
if ( V_309 == NULL )
return - V_94 ;
return 0 ;
}
static void T_12 F_183 ( struct V_153 * V_153 )
{
F_184 ( L_8 , V_153 -> V_310 ) ;
}
static int T_11 F_181 ( struct V_153 * V_153 )
{
return 0 ;
}
static void T_12 F_183 ( struct V_153 * V_153 )
{
}
static int T_2 F_185 ( void )
{
int V_28 ;
V_28 = F_186 ( & V_312 ) ;
if ( V_28 ) {
F_187 ( L_9
L_10 ) ;
return V_28 ;
}
F_1 ( & V_313 ) ;
F_1 ( & V_314 ) ;
F_1 ( & V_315 ) ;
F_1 ( & V_316 ) ;
F_1 ( & V_317 ) ;
F_1 ( & V_318 ) ;
F_188 ( V_319 , V_256 , F_138 , NULL , NULL ) ;
F_188 ( V_319 , V_222 , F_132 , NULL , NULL ) ;
F_188 ( V_319 , V_216 , F_132 , F_159 ,
NULL ) ;
F_188 ( V_319 , V_276 , F_161 , NULL , NULL ) ;
F_188 ( V_319 , V_277 , F_161 , NULL , NULL ) ;
F_188 ( V_319 , V_274 , F_161 , F_167 ,
NULL ) ;
return 0 ;
}
