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
F_41 ( & V_90 ) ;
F_42 (stab, &qdisc_stab_list, list) {
if ( memcmp ( & V_83 -> V_91 , V_85 , sizeof( * V_85 ) ) )
continue;
if ( V_86 > 0 && memcmp ( V_83 -> V_73 , V_70 , V_86 * sizeof( T_5 ) ) )
continue;
V_83 -> V_74 ++ ;
F_43 ( & V_90 ) ;
return V_83 ;
}
F_43 ( & V_90 ) ;
V_83 = F_35 ( sizeof( * V_83 ) + V_86 * sizeof( T_5 ) , V_75 ) ;
if ( ! V_83 )
return F_40 ( - V_92 ) ;
V_83 -> V_74 = 1 ;
V_83 -> V_91 = * V_85 ;
if ( V_86 > 0 )
memcpy ( V_83 -> V_73 , V_70 , V_86 * sizeof( T_5 ) ) ;
F_41 ( & V_90 ) ;
F_44 ( & V_83 -> V_93 , & V_94 ) ;
F_43 ( & V_90 ) ;
return V_83 ;
}
static void F_45 ( struct V_95 * V_96 )
{
F_37 ( F_46 ( V_96 , struct V_79 , V_97 ) ) ;
}
void F_47 ( struct V_79 * V_70 )
{
if ( ! V_70 )
return;
F_41 ( & V_90 ) ;
if ( -- V_70 -> V_74 == 0 ) {
F_48 ( & V_70 -> V_93 ) ;
F_49 ( & V_70 -> V_97 , F_45 ) ;
}
F_43 ( & V_90 ) ;
}
static int F_50 ( struct V_98 * V_99 , struct V_79 * V_83 )
{
struct V_55 * V_100 ;
V_100 = F_51 ( V_99 , V_101 ) ;
if ( V_100 == NULL )
goto V_102;
if ( F_52 ( V_99 , V_88 , sizeof( V_83 -> V_91 ) , & V_83 -> V_91 ) )
goto V_102;
F_53 ( V_99 , V_100 ) ;
return V_99 -> V_31 ;
V_102:
return - 1 ;
}
void F_54 ( struct V_98 * V_99 ,
const struct V_79 * V_83 )
{
int V_103 , V_104 ;
V_103 = V_99 -> V_31 + V_83 -> V_91 . V_105 ;
if ( F_55 ( ! V_83 -> V_91 . V_86 ) )
goto V_11;
V_104 = V_103 + V_83 -> V_91 . V_106 ;
if ( F_55 ( V_104 < 0 ) )
V_104 = 0 ;
V_104 >>= V_83 -> V_91 . V_64 ;
if ( F_56 ( V_104 < V_83 -> V_91 . V_86 ) )
V_103 = V_83 -> V_73 [ V_104 ] ;
else
V_103 = V_83 -> V_73 [ V_83 -> V_91 . V_86 - 1 ] *
( V_104 / V_83 -> V_91 . V_86 ) +
V_83 -> V_73 [ V_104 % V_83 -> V_91 . V_86 ] ;
V_103 <<= V_83 -> V_91 . V_107 ;
V_11:
if ( F_55 ( V_103 < 1 ) )
V_103 = 1 ;
F_57 ( V_99 ) -> V_103 = V_103 ;
}
void F_58 ( const char * V_108 , struct V_37 * V_45 )
{
if ( ! ( V_45 -> V_40 & V_109 ) ) {
F_59 ( L_4 ,
V_108 , V_45 -> V_34 -> V_10 , V_45 -> V_39 >> 16 ) ;
V_45 -> V_40 |= V_109 ;
}
}
static enum V_110 F_60 ( struct V_111 * V_112 )
{
struct F_60 * V_113 = F_46 ( V_112 , struct F_60 ,
V_112 ) ;
F_61 () ;
F_62 ( F_63 ( V_113 -> V_45 ) ) ;
F_64 () ;
return V_114 ;
}
void F_65 ( struct F_60 * V_113 , struct V_37 * V_45 )
{
F_66 ( & V_113 -> V_112 , V_115 , V_116 ) ;
V_113 -> V_112 . V_117 = F_60 ;
V_113 -> V_45 = V_45 ;
}
void F_67 ( struct F_60 * V_113 , T_6 V_118 )
{
if ( F_68 ( V_119 ,
& F_69 ( V_113 -> V_45 ) -> V_120 ) )
return;
if ( V_113 -> V_121 == V_118 )
return;
V_113 -> V_121 = V_118 ;
F_70 ( & V_113 -> V_112 ,
F_71 ( V_118 ) ,
V_116 ) ;
}
void F_72 ( struct F_60 * V_113 )
{
F_73 ( & V_113 -> V_112 ) ;
}
static struct V_122 * F_74 ( unsigned int V_123 )
{
unsigned int V_124 = V_123 * sizeof( struct V_122 ) , V_125 ;
struct V_122 * V_126 ;
if ( V_124 <= V_127 )
V_126 = F_35 ( V_124 , V_75 ) ;
else
V_126 = (struct V_122 * )
F_75 ( V_75 , F_76 ( V_124 ) ) ;
if ( V_126 != NULL ) {
for ( V_125 = 0 ; V_125 < V_123 ; V_125 ++ )
F_77 ( & V_126 [ V_125 ] ) ;
}
return V_126 ;
}
static void F_78 ( struct V_122 * V_126 , unsigned int V_123 )
{
unsigned int V_124 = V_123 * sizeof( struct V_122 ) ;
if ( V_124 <= V_127 )
F_37 ( V_126 ) ;
else
F_79 ( ( unsigned long ) V_126 , F_76 ( V_124 ) ) ;
}
void F_80 ( struct V_37 * V_128 , struct V_129 * V_130 )
{
struct V_131 * V_54 ;
struct V_132 * V_9 ;
struct V_122 * V_133 , * V_134 ;
unsigned int V_135 , V_136 , V_137 ;
unsigned int V_125 , V_126 ;
if ( V_130 -> V_138 * 4 <= V_130 -> V_139 * 3 )
return;
V_135 = V_130 -> V_139 * 2 ;
V_136 = V_135 - 1 ;
V_133 = F_74 ( V_135 ) ;
if ( V_133 == NULL )
return;
V_134 = V_130 -> V_48 ;
V_137 = V_130 -> V_139 ;
F_81 ( V_128 ) ;
for ( V_125 = 0 ; V_125 < V_137 ; V_125 ++ ) {
F_82 (cl, next, &ohash[i], hnode) {
V_126 = F_83 ( V_54 -> V_53 , V_136 ) ;
F_84 ( & V_54 -> V_140 , & V_133 [ V_126 ] ) ;
}
}
V_130 -> V_48 = V_133 ;
V_130 -> V_139 = V_135 ;
V_130 -> V_141 = V_136 ;
F_85 ( V_128 ) ;
F_78 ( V_134 , V_137 ) ;
}
int F_86 ( struct V_129 * V_130 )
{
unsigned int V_124 = 4 ;
V_130 -> V_48 = F_74 ( V_124 ) ;
if ( V_130 -> V_48 == NULL )
return - V_92 ;
V_130 -> V_139 = V_124 ;
V_130 -> V_141 = V_124 - 1 ;
V_130 -> V_138 = 0 ;
return 0 ;
}
void F_87 ( struct V_129 * V_130 )
{
F_78 ( V_130 -> V_48 , V_130 -> V_139 ) ;
}
void F_88 ( struct V_129 * V_130 ,
struct V_131 * V_54 )
{
unsigned int V_126 ;
F_89 ( & V_54 -> V_140 ) ;
V_126 = F_83 ( V_54 -> V_53 , V_130 -> V_141 ) ;
F_84 ( & V_54 -> V_140 , & V_130 -> V_48 [ V_126 ] ) ;
V_130 -> V_138 ++ ;
}
void F_90 ( struct V_129 * V_130 ,
struct V_131 * V_54 )
{
F_91 ( & V_54 -> V_140 ) ;
V_130 -> V_138 -- ;
}
static T_2 F_92 ( struct V_49 * V_50 )
{
int V_125 = 0x8000 ;
static T_2 V_142 = F_93 ( 0x80000000U , 0 ) ;
do {
V_142 += F_93 ( 0x10000U , 0 ) ;
if ( V_142 == F_93 ( V_43 , 0 ) )
V_142 = F_93 ( 0x80000000U , 0 ) ;
if ( ! F_24 ( V_50 , V_142 ) )
return V_142 ;
F_94 () ;
} while ( -- V_125 > 0 );
return 0 ;
}
void F_95 ( struct V_37 * V_128 , unsigned int V_123 ,
unsigned int V_31 )
{
const struct V_18 * V_19 ;
unsigned long V_54 ;
T_2 V_143 ;
int V_144 ;
if ( V_123 == 0 && V_31 == 0 )
return;
V_144 = F_96 ( int , V_123 , 0 ) ;
F_61 () ;
while ( ( V_143 = V_128 -> V_42 ) ) {
if ( F_97 ( V_143 ) == F_97 ( V_145 ) )
break;
if ( V_128 -> V_40 & V_146 )
break;
V_128 = F_24 ( F_16 ( V_128 ) , F_97 ( V_143 ) ) ;
if ( V_128 == NULL ) {
F_19 ( V_143 != V_43 ) ;
break;
}
V_19 = V_128 -> V_34 -> V_17 ;
if ( V_19 -> V_147 ) {
V_54 = V_19 -> V_20 ( V_128 , V_143 ) ;
V_19 -> V_147 ( V_128 , V_54 ) ;
V_19 -> V_21 ( V_128 , V_54 ) ;
}
V_128 -> V_3 . V_148 -= V_123 ;
V_128 -> V_149 . V_150 -= V_31 ;
F_98 ( V_128 , V_144 ) ;
}
F_64 () ;
}
static void F_99 ( struct V_151 * V_151 , struct V_98 * V_99 ,
struct V_152 * V_123 , T_2 V_153 ,
struct V_37 * V_154 , struct V_37 * V_155 )
{
if ( V_155 || V_154 )
F_100 ( V_151 , V_99 , V_123 , V_153 , V_154 , V_155 ) ;
if ( V_154 )
F_101 ( V_154 ) ;
}
static int F_102 ( struct V_49 * V_50 , struct V_37 * V_42 ,
struct V_98 * V_99 , struct V_152 * V_123 , T_2 V_53 ,
struct V_37 * V_155 , struct V_37 * V_154 )
{
struct V_37 * V_3 = V_154 ;
struct V_151 * V_151 = F_103 ( V_50 ) ;
int V_28 = 0 ;
if ( V_42 == NULL ) {
unsigned int V_125 , V_156 , V_157 ;
V_157 = 0 ;
V_156 = V_50 -> V_158 ;
if ( ( V_3 && V_3 -> V_40 & V_44 ) ||
( V_155 && V_155 -> V_40 & V_44 ) ) {
V_156 = 1 ;
V_157 = 1 ;
if ( ! F_25 ( V_50 ) )
return - V_29 ;
}
if ( V_50 -> V_40 & V_159 )
F_104 ( V_50 ) ;
if ( V_155 && V_155 -> V_34 -> V_160 )
goto V_161;
for ( V_125 = 0 ; V_125 < V_156 ; V_125 ++ ) {
struct V_162 * V_163 = F_25 ( V_50 ) ;
if ( ! V_157 )
V_163 = F_105 ( V_50 , V_125 ) ;
V_154 = F_106 ( V_163 , V_155 ) ;
if ( V_155 && V_125 > 0 )
F_107 ( & V_155 -> V_74 ) ;
if ( ! V_157 )
F_101 ( V_154 ) ;
}
V_161:
if ( ! V_157 ) {
F_99 ( V_151 , V_99 , V_123 , V_53 ,
V_50 -> V_45 , V_155 ) ;
if ( V_155 && ! V_155 -> V_34 -> V_160 )
F_107 ( & V_155 -> V_74 ) ;
V_50 -> V_45 = V_155 ? : & V_46 ;
if ( V_155 && V_155 -> V_34 -> V_160 )
V_155 -> V_34 -> V_160 ( V_155 ) ;
} else {
F_99 ( V_151 , V_99 , V_123 , V_53 , V_154 , V_155 ) ;
}
if ( V_50 -> V_40 & V_159 )
F_108 ( V_50 ) ;
} else {
const struct V_18 * V_19 = V_42 -> V_34 -> V_17 ;
V_28 = - V_164 ;
if ( V_19 && V_19 -> V_165 ) {
unsigned long V_54 = V_19 -> V_20 ( V_42 , V_53 ) ;
if ( V_54 ) {
V_28 = V_19 -> V_165 ( V_42 , V_54 , V_155 , & V_154 ) ;
V_19 -> V_21 ( V_42 , V_54 ) ;
} else
V_28 = - V_29 ;
}
if ( ! V_28 )
F_99 ( V_151 , V_99 , V_123 , V_53 , V_154 , V_155 ) ;
}
return V_28 ;
}
static struct V_37 * F_109 ( struct V_49 * V_50 ,
struct V_162 * V_163 ,
struct V_37 * V_52 , T_2 V_42 , T_2 V_39 ,
struct V_55 * * V_166 , int * V_167 )
{
int V_28 ;
struct V_55 * V_56 = V_166 [ V_168 ] ;
struct V_37 * V_128 ;
struct V_1 * V_34 ;
struct V_79 * V_83 ;
V_34 = F_27 ( V_56 ) ;
#ifdef F_110
if ( V_34 == NULL && V_56 != NULL ) {
char V_30 [ V_169 ] ;
if ( F_111 ( V_30 , V_56 , V_169 ) < V_169 ) {
F_112 () ;
F_13 ( L_1 , V_30 ) ;
F_113 () ;
V_34 = F_27 ( V_56 ) ;
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
V_128 = F_114 ( V_163 , V_34 ) ;
if ( F_115 ( V_128 ) ) {
V_28 = F_116 ( V_128 ) ;
goto V_172;
}
V_128 -> V_42 = V_42 ;
if ( V_39 == V_145 ) {
V_128 -> V_40 |= V_44 ;
V_39 = F_93 ( V_145 , 0 ) ;
F_117 ( F_118 ( V_128 ) , & V_173 ) ;
} else {
if ( V_39 == 0 ) {
V_39 = F_92 ( V_50 ) ;
V_28 = - V_92 ;
if ( V_39 == 0 )
goto V_174;
}
F_117 ( F_118 ( V_128 ) , & V_175 ) ;
if ( ! F_119 ( V_50 ) )
V_128 -> V_40 |= V_176 ;
}
V_128 -> V_39 = V_39 ;
if ( ( V_50 -> V_177 & V_178 ) && ( V_50 -> V_179 == 0 ) ) {
V_50 -> V_179 = V_180 ;
F_120 ( V_50 , L_5 ) ;
}
if ( ! V_34 -> V_181 || ( V_28 = V_34 -> V_181 ( V_128 , V_166 [ V_182 ] ) ) == 0 ) {
if ( F_121 ( V_128 ) ) {
V_128 -> V_183 =
F_122 ( struct V_184 ) ;
if ( ! V_128 -> V_183 )
goto V_185;
V_128 -> V_186 = F_123 ( struct V_187 ) ;
if ( ! V_128 -> V_186 )
goto V_185;
}
if ( V_166 [ V_101 ] ) {
V_83 = F_38 ( V_166 [ V_101 ] ) ;
if ( F_115 ( V_83 ) ) {
V_28 = F_116 ( V_83 ) ;
goto V_185;
}
F_124 ( V_128 -> V_83 , V_83 ) ;
}
if ( V_166 [ V_188 ] ) {
T_7 * V_189 ;
V_28 = - V_164 ;
if ( V_128 -> V_40 & V_190 )
goto V_185;
if ( ( V_128 -> V_42 != V_43 ) &&
! ( V_128 -> V_40 & V_44 ) &&
( ! V_52 || ! ( V_52 -> V_40 & V_190 ) ) )
V_189 = F_125 ( V_128 ) ;
else
V_189 = & V_128 -> V_189 ;
V_28 = F_126 ( & V_128 -> V_191 ,
V_128 -> V_183 ,
& V_128 -> V_192 ,
NULL ,
V_189 ,
V_166 [ V_188 ] ) ;
if ( V_28 )
goto V_185;
}
F_18 ( V_128 ) ;
return V_128 ;
}
V_174:
F_127 ( V_50 ) ;
F_37 ( ( char * ) V_128 - V_128 -> V_193 ) ;
V_172:
F_14 ( V_34 -> V_33 ) ;
V_171:
* V_167 = V_28 ;
return NULL ;
V_185:
F_128 ( V_128 -> V_183 ) ;
F_128 ( V_128 -> V_186 ) ;
F_47 ( F_129 ( V_128 -> V_83 ) ) ;
if ( V_34 -> V_194 )
V_34 -> V_194 ( V_128 ) ;
goto V_174;
}
static int F_130 ( struct V_37 * V_128 , struct V_55 * * V_166 )
{
struct V_79 * V_195 , * V_83 = NULL ;
int V_28 = 0 ;
if ( V_166 [ V_182 ] ) {
if ( V_128 -> V_34 -> V_196 == NULL )
return - V_27 ;
V_28 = V_128 -> V_34 -> V_196 ( V_128 , V_166 [ V_182 ] ) ;
if ( V_28 )
return V_28 ;
}
if ( V_166 [ V_101 ] ) {
V_83 = F_38 ( V_166 [ V_101 ] ) ;
if ( F_115 ( V_83 ) )
return F_116 ( V_83 ) ;
}
V_195 = F_129 ( V_128 -> V_83 ) ;
F_124 ( V_128 -> V_83 , V_83 ) ;
F_47 ( V_195 ) ;
if ( V_166 [ V_188 ] ) {
if ( V_128 -> V_40 & V_190 )
goto V_11;
F_131 ( & V_128 -> V_191 ,
V_128 -> V_183 ,
& V_128 -> V_192 ,
NULL ,
F_125 ( V_128 ) ,
V_166 [ V_188 ] ) ;
}
V_11:
return 0 ;
}
static int F_132 ( struct V_37 * V_3 , struct V_37 * V_52 , int V_197 )
{
struct V_198 V_199 ;
if ( V_3 -> V_34 -> V_17 == NULL )
return 0 ;
V_199 . V_200 . V_201 = V_199 . V_200 . V_161 = V_199 . V_200 . V_202 = 0 ;
V_199 . V_200 . V_203 = V_204 ;
V_199 . V_197 = V_197 ;
V_199 . V_52 = V_52 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_199 . V_200 ) ;
return V_199 . V_200 . V_201 ? - V_205 : 0 ;
}
static int
V_204 ( struct V_37 * V_3 , unsigned long V_54 , struct V_206 * V_200 )
{
struct V_37 * V_23 ;
const struct V_18 * V_19 = V_3 -> V_34 -> V_17 ;
struct V_198 * V_199 = (struct V_198 * ) V_200 ;
V_23 = V_19 -> V_23 ( V_3 , V_54 ) ;
if ( V_23 ) {
if ( V_23 == V_199 -> V_52 || V_199 -> V_197 > 7 )
return - V_205 ;
return F_132 ( V_23 , V_199 -> V_52 , V_199 -> V_197 + 1 ) ;
}
return 0 ;
}
static int F_133 ( struct V_98 * V_99 , struct V_152 * V_123 )
{
struct V_151 * V_151 = F_134 ( V_99 -> V_207 ) ;
struct V_208 * V_209 = F_135 ( V_123 ) ;
struct V_55 * V_166 [ V_210 + 1 ] ;
struct V_49 * V_50 ;
T_2 V_153 ;
struct V_37 * V_3 = NULL ;
struct V_37 * V_52 = NULL ;
int V_28 ;
if ( ( V_123 -> V_211 != V_212 ) &&
! F_136 ( V_99 , V_151 -> V_213 , V_35 ) )
return - V_36 ;
V_28 = F_137 ( V_123 , sizeof( * V_209 ) , V_166 , V_210 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_50 = F_138 ( V_151 , V_209 -> V_214 ) ;
if ( ! V_50 )
return - V_215 ;
V_153 = V_209 -> V_216 ;
if ( V_153 ) {
if ( V_153 != V_43 ) {
if ( F_97 ( V_153 ) != F_97 ( V_145 ) ) {
V_52 = F_24 ( V_50 , F_97 ( V_153 ) ) ;
if ( ! V_52 )
return - V_29 ;
V_3 = F_26 ( V_52 , V_153 ) ;
} else if ( F_25 ( V_50 ) ) {
V_3 = F_25 ( V_50 ) -> V_51 ;
}
} else {
V_3 = V_50 -> V_45 ;
}
if ( ! V_3 )
return - V_29 ;
if ( V_209 -> V_217 && V_3 -> V_39 != V_209 -> V_217 )
return - V_27 ;
} else {
V_3 = F_24 ( V_50 , V_209 -> V_217 ) ;
if ( ! V_3 )
return - V_29 ;
}
if ( V_166 [ V_168 ] && F_28 ( V_166 [ V_168 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_123 -> V_211 == V_218 ) {
if ( ! V_153 )
return - V_27 ;
if ( V_3 -> V_39 == 0 )
return - V_29 ;
V_28 = F_102 ( V_50 , V_52 , V_99 , V_123 , V_153 , NULL , V_3 ) ;
if ( V_28 != 0 )
return V_28 ;
} else {
F_100 ( V_151 , V_99 , V_123 , V_153 , NULL , V_3 ) ;
}
return 0 ;
}
static int F_139 ( struct V_98 * V_99 , struct V_152 * V_123 )
{
struct V_151 * V_151 = F_134 ( V_99 -> V_207 ) ;
struct V_208 * V_209 ;
struct V_55 * V_166 [ V_210 + 1 ] ;
struct V_49 * V_50 ;
T_2 V_153 ;
struct V_37 * V_3 , * V_52 ;
int V_28 ;
if ( ! F_136 ( V_99 , V_151 -> V_213 , V_35 ) )
return - V_36 ;
V_219:
V_28 = F_137 ( V_123 , sizeof( * V_209 ) , V_166 , V_210 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_209 = F_135 ( V_123 ) ;
V_153 = V_209 -> V_216 ;
V_3 = V_52 = NULL ;
V_50 = F_138 ( V_151 , V_209 -> V_214 ) ;
if ( ! V_50 )
return - V_215 ;
if ( V_153 ) {
if ( V_153 != V_43 ) {
if ( V_153 != V_145 ) {
V_52 = F_24 ( V_50 , F_97 ( V_153 ) ) ;
if ( ! V_52 )
return - V_29 ;
V_3 = F_26 ( V_52 , V_153 ) ;
} else if ( F_140 ( V_50 ) ) {
V_3 = F_25 ( V_50 ) -> V_51 ;
}
} else {
V_3 = V_50 -> V_45 ;
}
if ( V_3 && V_3 -> V_39 == 0 )
V_3 = NULL ;
if ( ! V_3 || ! V_209 -> V_217 || V_3 -> V_39 != V_209 -> V_217 ) {
if ( V_209 -> V_217 ) {
if ( V_3 && ! ( V_123 -> V_220 & V_221 ) )
return - V_6 ;
if ( F_141 ( V_209 -> V_217 ) )
return - V_27 ;
V_3 = F_24 ( V_50 , V_209 -> V_217 ) ;
if ( ! V_3 )
goto V_222;
if ( V_123 -> V_220 & V_223 )
return - V_6 ;
if ( V_166 [ V_168 ] && F_28 ( V_166 [ V_168 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_3 == V_52 ||
( V_52 && F_132 ( V_3 , V_52 , 0 ) ) )
return - V_205 ;
F_107 ( & V_3 -> V_74 ) ;
goto V_165;
} else {
if ( ! V_3 )
goto V_222;
if ( ( V_123 -> V_220 & V_224 ) &&
( V_123 -> V_220 & V_221 ) &&
( ( V_123 -> V_220 & V_223 ) ||
( V_166 [ V_168 ] &&
F_28 ( V_166 [ V_168 ] , V_3 -> V_34 -> V_10 ) ) ) )
goto V_222;
}
}
} else {
if ( ! V_209 -> V_217 )
return - V_27 ;
V_3 = F_24 ( V_50 , V_209 -> V_217 ) ;
}
if ( V_3 == NULL )
return - V_29 ;
if ( V_123 -> V_220 & V_223 )
return - V_6 ;
if ( V_166 [ V_168 ] && F_28 ( V_166 [ V_168 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
V_28 = F_130 ( V_3 , V_166 ) ;
if ( V_28 == 0 )
F_100 ( V_151 , V_99 , V_123 , V_153 , NULL , V_3 ) ;
return V_28 ;
V_222:
if ( ! ( V_123 -> V_220 & V_224 ) )
return - V_29 ;
if ( V_153 == V_145 ) {
if ( F_25 ( V_50 ) )
V_3 = F_109 ( V_50 , F_25 ( V_50 ) , V_52 ,
V_209 -> V_216 , V_209 -> V_216 ,
V_166 , & V_28 ) ;
else
V_28 = - V_29 ;
} else {
struct V_162 * V_163 ;
if ( V_52 && V_52 -> V_34 -> V_17 && V_52 -> V_34 -> V_17 -> V_225 )
V_163 = V_52 -> V_34 -> V_17 -> V_225 ( V_52 , V_209 ) ;
else if ( V_52 )
V_163 = V_52 -> V_163 ;
else
V_163 = F_105 ( V_50 , 0 ) ;
V_3 = F_109 ( V_50 , V_163 , V_52 ,
V_209 -> V_216 , V_209 -> V_217 ,
V_166 , & V_28 ) ;
}
if ( V_3 == NULL ) {
if ( V_28 == - V_170 )
goto V_219;
return V_28 ;
}
V_165:
V_28 = F_102 ( V_50 , V_52 , V_99 , V_123 , V_153 , V_3 , NULL ) ;
if ( V_28 ) {
if ( V_3 )
F_101 ( V_3 ) ;
return V_28 ;
}
return 0 ;
}
static int F_142 ( struct V_98 * V_99 , struct V_37 * V_3 , T_2 V_153 ,
T_2 V_226 , T_2 V_227 , T_5 V_40 , int V_228 )
{
struct V_184 T_8 * V_183 = NULL ;
struct V_187 T_8 * V_186 = NULL ;
struct V_208 * V_209 ;
struct V_152 * V_229 ;
unsigned char * V_230 = F_143 ( V_99 ) ;
struct V_231 V_232 ;
struct V_79 * V_83 ;
T_4 V_148 ;
F_94 () ;
V_229 = F_144 ( V_99 , V_226 , V_227 , V_228 , sizeof( * V_209 ) , V_40 ) ;
if ( ! V_229 )
goto V_233;
V_209 = F_135 ( V_229 ) ;
V_209 -> V_234 = V_235 ;
V_209 -> V_236 = 0 ;
V_209 -> V_237 = 0 ;
V_209 -> V_214 = F_16 ( V_3 ) -> V_238 ;
V_209 -> V_216 = V_153 ;
V_209 -> V_217 = V_3 -> V_39 ;
V_209 -> V_239 = F_145 ( & V_3 -> V_74 ) ;
if ( F_146 ( V_99 , V_168 , V_3 -> V_34 -> V_10 ) )
goto V_102;
if ( V_3 -> V_34 -> V_240 && V_3 -> V_34 -> V_240 ( V_3 , V_99 ) < 0 )
goto V_102;
V_148 = V_3 -> V_3 . V_148 ;
V_83 = F_129 ( V_3 -> V_83 ) ;
if ( V_83 && F_50 ( V_99 , V_83 ) < 0 )
goto V_102;
if ( F_147 ( V_99 , V_241 , V_242 , V_243 ,
NULL , & V_232 , V_244 ) < 0 )
goto V_102;
if ( V_3 -> V_34 -> V_245 && V_3 -> V_34 -> V_245 ( V_3 , & V_232 ) < 0 )
goto V_102;
if ( F_121 ( V_3 ) ) {
V_183 = V_3 -> V_183 ;
V_186 = V_3 -> V_186 ;
}
if ( F_148 ( F_125 ( V_3 ) ,
& V_232 , V_183 , & V_3 -> V_191 ) < 0 ||
F_149 ( & V_232 , & V_3 -> V_192 ) < 0 ||
F_150 ( & V_232 , V_186 , & V_3 -> V_149 , V_148 ) < 0 )
goto V_102;
if ( F_151 ( & V_232 ) < 0 )
goto V_102;
V_229 -> V_246 = F_143 ( V_99 ) - V_230 ;
return V_99 -> V_31 ;
V_233:
V_102:
F_152 ( V_99 , V_230 ) ;
return - 1 ;
}
static bool F_153 ( struct V_37 * V_3 )
{
return ( V_3 -> V_40 & V_41 ) ? true : false ;
}
static int F_100 ( struct V_151 * V_151 , struct V_98 * V_247 ,
struct V_152 * V_123 , T_2 V_153 ,
struct V_37 * V_154 , struct V_37 * V_155 )
{
struct V_98 * V_99 ;
T_2 V_226 = V_247 ? F_154 ( V_247 ) . V_226 : 0 ;
V_99 = F_155 ( V_248 , V_75 ) ;
if ( ! V_99 )
return - V_249 ;
if ( V_154 && ! F_153 ( V_154 ) ) {
if ( F_142 ( V_99 , V_154 , V_153 , V_226 , V_123 -> V_250 ,
0 , V_218 ) < 0 )
goto V_171;
}
if ( V_155 && ! F_153 ( V_155 ) ) {
if ( F_142 ( V_99 , V_155 , V_153 , V_226 , V_123 -> V_250 ,
V_154 ? V_221 : 0 , V_251 ) < 0 )
goto V_171;
}
if ( V_99 -> V_31 )
return F_156 ( V_99 , V_151 , V_226 , V_252 ,
V_123 -> V_220 & V_253 ) ;
V_171:
F_157 ( V_99 ) ;
return - V_27 ;
}
static int F_158 ( struct V_37 * V_38 , struct V_98 * V_99 ,
struct V_254 * V_255 ,
int * V_256 , int V_257 , bool V_258 )
{
int V_259 = 0 , V_260 = * V_256 ;
struct V_37 * V_3 ;
int V_230 ;
if ( ! V_38 )
return 0 ;
V_3 = V_38 ;
if ( V_260 < V_257 ) {
V_260 ++ ;
} else {
if ( ! F_153 ( V_3 ) &&
F_142 ( V_99 , V_3 , V_3 -> V_42 , F_154 ( V_255 -> V_99 ) . V_226 ,
V_255 -> V_229 -> V_250 , V_261 ,
V_251 ) <= 0 )
goto V_262;
V_260 ++ ;
}
if ( ! F_16 ( V_38 ) || ! V_258 )
goto V_11;
F_159 (qdisc_dev(root)->qdisc_hash, b, q, hash) {
if ( V_260 < V_257 ) {
V_260 ++ ;
continue;
}
if ( ! F_153 ( V_3 ) &&
F_142 ( V_99 , V_3 , V_3 -> V_42 , F_154 ( V_255 -> V_99 ) . V_226 ,
V_255 -> V_229 -> V_250 , V_261 ,
V_251 ) <= 0 )
goto V_262;
V_260 ++ ;
}
V_11:
* V_256 = V_260 ;
return V_259 ;
V_262:
V_259 = - 1 ;
goto V_11;
}
static int F_160 ( struct V_98 * V_99 , struct V_254 * V_255 )
{
struct V_151 * V_151 = F_134 ( V_99 -> V_207 ) ;
int V_263 , V_260 ;
int V_264 , V_257 ;
struct V_49 * V_50 ;
V_264 = V_255 -> args [ 0 ] ;
V_257 = V_260 = V_255 -> args [ 1 ] ;
V_263 = 0 ;
F_20 () ;
F_161 (net, dev) {
struct V_162 * V_163 ;
if ( V_263 < V_264 )
goto V_265;
if ( V_263 > V_264 )
V_257 = 0 ;
V_260 = 0 ;
if ( F_158 ( V_50 -> V_45 , V_99 , V_255 , & V_260 , V_257 ,
true ) < 0 )
goto V_262;
V_163 = F_25 ( V_50 ) ;
if ( V_163 &&
F_158 ( V_163 -> V_51 , V_99 , V_255 ,
& V_260 , V_257 , false ) < 0 )
goto V_262;
V_265:
V_263 ++ ;
}
V_262:
V_255 -> args [ 0 ] = V_263 ;
V_255 -> args [ 1 ] = V_260 ;
return V_99 -> V_31 ;
}
static int F_162 ( struct V_98 * V_99 , struct V_152 * V_123 )
{
struct V_151 * V_151 = F_134 ( V_99 -> V_207 ) ;
struct V_208 * V_209 = F_135 ( V_123 ) ;
struct V_55 * V_166 [ V_210 + 1 ] ;
struct V_49 * V_50 ;
struct V_37 * V_3 = NULL ;
const struct V_18 * V_19 ;
unsigned long V_54 = 0 ;
unsigned long V_266 ;
T_2 V_226 ;
T_2 V_153 ;
T_2 V_267 ;
int V_28 ;
if ( ( V_123 -> V_211 != V_268 ) &&
! F_136 ( V_99 , V_151 -> V_213 , V_35 ) )
return - V_36 ;
V_28 = F_137 ( V_123 , sizeof( * V_209 ) , V_166 , V_210 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_50 = F_138 ( V_151 , V_209 -> V_214 ) ;
if ( ! V_50 )
return - V_215 ;
V_226 = V_209 -> V_216 ;
V_153 = V_209 -> V_217 ;
V_267 = F_97 ( V_153 ) ;
if ( V_226 != V_43 ) {
T_2 V_269 = F_97 ( V_226 ) ;
if ( V_267 && V_269 ) {
if ( V_267 != V_269 )
return - V_27 ;
} else if ( V_269 ) {
V_267 = V_269 ;
} else if ( V_267 == 0 )
V_267 = V_50 -> V_45 -> V_39 ;
if ( V_226 )
V_226 = F_93 ( V_267 , V_226 ) ;
} else {
if ( V_267 == 0 )
V_267 = V_50 -> V_45 -> V_39 ;
}
V_3 = F_24 ( V_50 , V_267 ) ;
if ( ! V_3 )
return - V_29 ;
V_19 = V_3 -> V_34 -> V_17 ;
if ( V_19 == NULL )
return - V_27 ;
if ( V_153 == 0 ) {
if ( V_226 == V_43 )
V_153 = V_267 ;
} else
V_153 = F_93 ( V_267 , V_153 ) ;
if ( V_153 )
V_54 = V_19 -> V_20 ( V_3 , V_153 ) ;
if ( V_54 == 0 ) {
V_28 = - V_29 ;
if ( V_123 -> V_211 != V_270 ||
! ( V_123 -> V_220 & V_224 ) )
goto V_11;
} else {
switch ( V_123 -> V_211 ) {
case V_270 :
V_28 = - V_6 ;
if ( V_123 -> V_220 & V_223 )
goto V_11;
break;
case V_271 :
V_28 = - V_164 ;
if ( V_19 -> V_272 )
V_28 = V_19 -> V_272 ( V_3 , V_54 ) ;
if ( V_28 == 0 )
F_163 ( V_151 , V_99 , V_123 , V_3 , V_54 ,
V_271 ) ;
goto V_11;
case V_268 :
V_28 = F_163 ( V_151 , V_99 , V_123 , V_3 , V_54 , V_270 ) ;
goto V_11;
default:
V_28 = - V_27 ;
goto V_11;
}
}
V_266 = V_54 ;
V_28 = - V_164 ;
if ( V_19 -> V_196 )
V_28 = V_19 -> V_196 ( V_3 , V_153 , V_226 , V_166 , & V_266 ) ;
if ( V_28 == 0 )
F_163 ( V_151 , V_99 , V_123 , V_3 , V_266 , V_270 ) ;
V_11:
if ( V_54 )
V_19 -> V_21 ( V_3 , V_54 ) ;
return V_28 ;
}
static int F_164 ( struct V_98 * V_99 , struct V_37 * V_3 ,
unsigned long V_54 ,
T_2 V_226 , T_2 V_227 , T_5 V_40 , int V_228 )
{
struct V_208 * V_209 ;
struct V_152 * V_229 ;
unsigned char * V_230 = F_143 ( V_99 ) ;
struct V_231 V_232 ;
const struct V_18 * V_17 = V_3 -> V_34 -> V_17 ;
F_94 () ;
V_229 = F_144 ( V_99 , V_226 , V_227 , V_228 , sizeof( * V_209 ) , V_40 ) ;
if ( ! V_229 )
goto V_233;
V_209 = F_135 ( V_229 ) ;
V_209 -> V_234 = V_235 ;
V_209 -> V_236 = 0 ;
V_209 -> V_237 = 0 ;
V_209 -> V_214 = F_16 ( V_3 ) -> V_238 ;
V_209 -> V_216 = V_3 -> V_39 ;
V_209 -> V_217 = V_3 -> V_39 ;
V_209 -> V_239 = 0 ;
if ( F_146 ( V_99 , V_168 , V_3 -> V_34 -> V_10 ) )
goto V_102;
if ( V_17 -> V_240 && V_17 -> V_240 ( V_3 , V_54 , V_99 , V_209 ) < 0 )
goto V_102;
if ( F_147 ( V_99 , V_241 , V_242 , V_243 ,
NULL , & V_232 , V_244 ) < 0 )
goto V_102;
if ( V_17 -> V_245 && V_17 -> V_245 ( V_3 , V_54 , & V_232 ) < 0 )
goto V_102;
if ( F_151 ( & V_232 ) < 0 )
goto V_102;
V_229 -> V_246 = F_143 ( V_99 ) - V_230 ;
return V_99 -> V_31 ;
V_233:
V_102:
F_152 ( V_99 , V_230 ) ;
return - 1 ;
}
static int F_163 ( struct V_151 * V_151 , struct V_98 * V_247 ,
struct V_152 * V_123 , struct V_37 * V_3 ,
unsigned long V_54 , int V_228 )
{
struct V_98 * V_99 ;
T_2 V_226 = V_247 ? F_154 ( V_247 ) . V_226 : 0 ;
V_99 = F_155 ( V_248 , V_75 ) ;
if ( ! V_99 )
return - V_249 ;
if ( F_164 ( V_99 , V_3 , V_54 , V_226 , V_123 -> V_250 , 0 , V_228 ) < 0 ) {
F_157 ( V_99 ) ;
return - V_27 ;
}
return F_156 ( V_99 , V_151 , V_226 , V_252 ,
V_123 -> V_220 & V_253 ) ;
}
static int F_165 ( struct V_37 * V_3 , unsigned long V_54 ,
struct V_206 * V_199 )
{
struct V_273 * V_274 = (struct V_273 * ) V_199 ;
return F_164 ( V_274 -> V_99 , V_3 , V_54 , F_154 ( V_274 -> V_255 -> V_99 ) . V_226 ,
V_274 -> V_255 -> V_229 -> V_250 , V_261 ,
V_270 ) ;
}
static int F_166 ( struct V_37 * V_3 , struct V_98 * V_99 ,
struct V_208 * V_209 , struct V_254 * V_255 ,
int * V_275 , int V_276 )
{
struct V_273 V_199 ;
if ( F_153 ( V_3 ) ||
* V_275 < V_276 || ! V_3 -> V_34 -> V_17 ||
( V_209 -> V_216 &&
F_97 ( V_209 -> V_216 ) != V_3 -> V_39 ) ) {
( * V_275 ) ++ ;
return 0 ;
}
if ( * V_275 > V_276 )
memset ( & V_255 -> args [ 1 ] , 0 , sizeof( V_255 -> args ) - sizeof( V_255 -> args [ 0 ] ) ) ;
V_199 . V_200 . V_203 = F_165 ;
V_199 . V_99 = V_99 ;
V_199 . V_255 = V_255 ;
V_199 . V_200 . V_201 = 0 ;
V_199 . V_200 . V_161 = V_255 -> args [ 1 ] ;
V_199 . V_200 . V_202 = 0 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_199 . V_200 ) ;
V_255 -> args [ 1 ] = V_199 . V_200 . V_202 ;
if ( V_199 . V_200 . V_201 )
return - 1 ;
( * V_275 ) ++ ;
return 0 ;
}
static int F_167 ( struct V_37 * V_38 , struct V_98 * V_99 ,
struct V_208 * V_209 , struct V_254 * V_255 ,
int * V_275 , int V_276 )
{
struct V_37 * V_3 ;
int V_230 ;
if ( ! V_38 )
return 0 ;
if ( F_166 ( V_38 , V_99 , V_209 , V_255 , V_275 , V_276 ) < 0 )
return - 1 ;
if ( ! F_16 ( V_38 ) )
return 0 ;
F_159 (qdisc_dev(root)->qdisc_hash, b, q, hash) {
if ( F_166 ( V_3 , V_99 , V_209 , V_255 , V_275 , V_276 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_168 ( struct V_98 * V_99 , struct V_254 * V_255 )
{
struct V_208 * V_209 = F_135 ( V_255 -> V_229 ) ;
struct V_151 * V_151 = F_134 ( V_99 -> V_207 ) ;
struct V_162 * V_163 ;
struct V_49 * V_50 ;
int V_277 , V_276 ;
if ( V_246 ( V_255 -> V_229 ) < sizeof( * V_209 ) )
return 0 ;
V_50 = F_169 ( V_151 , V_209 -> V_214 ) ;
if ( ! V_50 )
return 0 ;
V_276 = V_255 -> args [ 0 ] ;
V_277 = 0 ;
if ( F_167 ( V_50 -> V_45 , V_99 , V_209 , V_255 , & V_277 , V_276 ) < 0 )
goto V_262;
V_163 = F_25 ( V_50 ) ;
if ( V_163 &&
F_167 ( V_163 -> V_51 , V_99 , V_209 , V_255 ,
& V_277 , V_276 ) < 0 )
goto V_262;
V_262:
V_255 -> args [ 0 ] = V_277 ;
F_127 ( V_50 ) ;
return V_99 -> V_31 ;
}
int F_170 ( struct V_98 * V_99 , const struct V_278 * V_279 ,
struct V_280 * V_281 , bool V_282 )
{
T_9 V_283 = F_171 ( V_99 ) ;
#ifdef F_172
const struct V_278 * V_284 = V_279 ;
int V_285 = 0 ;
V_286:
#endif
for (; V_279 ; V_279 = F_173 ( V_279 -> V_9 ) ) {
int V_28 ;
if ( V_279 -> V_283 != V_283 &&
V_279 -> V_283 != F_174 ( V_287 ) )
continue;
V_28 = V_279 -> V_288 ( V_99 , V_279 , V_281 ) ;
#ifdef F_172
if ( F_55 ( V_28 == V_289 && ! V_282 ) )
goto V_290;
#endif
if ( V_28 >= 0 )
return V_28 ;
}
return V_291 ;
#ifdef F_172
V_290:
if ( F_55 ( V_285 ++ >= V_292 ) ) {
F_175 ( L_6 ,
V_279 -> V_3 -> V_34 -> V_10 , V_279 -> V_293 & 0xffff ,
F_176 ( V_279 -> V_283 ) ) ;
return V_294 ;
}
V_279 = V_284 ;
V_283 = F_171 ( V_99 ) ;
goto V_286;
#endif
}
bool F_177 ( struct V_278 * V_279 , bool V_295 )
{
if ( V_279 -> V_34 -> V_194 ( V_279 , V_295 ) ) {
F_14 ( V_279 -> V_34 -> V_33 ) ;
F_178 ( V_279 , V_97 ) ;
return true ;
}
return false ;
}
void F_179 ( struct V_278 T_10 * * V_296 )
{
struct V_278 * V_279 ;
while ( ( V_279 = F_129 ( * V_296 ) ) != NULL ) {
F_180 ( * V_296 , V_279 -> V_9 ) ;
F_177 ( V_279 , true ) ;
}
}
static int F_181 ( struct V_297 * V_227 , void * V_298 )
{
F_182 ( V_227 , L_7 ,
( T_2 ) V_299 , ( T_2 ) F_183 ( 1 ) ,
1000000 ,
( T_2 ) V_300 / V_301 ) ;
return 0 ;
}
static int F_184 ( struct V_302 * V_302 , struct V_303 * V_303 )
{
return F_185 ( V_303 , F_181 , NULL ) ;
}
static int T_11 F_186 ( struct V_151 * V_151 )
{
struct V_304 * V_305 ;
V_305 = F_187 ( L_8 , 0 , V_151 -> V_306 , & V_307 ) ;
if ( V_305 == NULL )
return - V_92 ;
return 0 ;
}
static void T_12 F_188 ( struct V_151 * V_151 )
{
F_189 ( L_8 , V_151 -> V_306 ) ;
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
V_28 = F_191 ( & V_308 ) ;
if ( V_28 ) {
F_192 ( L_9
L_10 ) ;
return V_28 ;
}
F_1 ( & V_309 ) ;
F_1 ( & V_310 ) ;
F_1 ( & V_311 ) ;
F_1 ( & V_312 ) ;
F_1 ( & V_313 ) ;
F_1 ( & V_314 ) ;
F_193 ( V_315 , V_251 , F_139 , NULL , NULL ) ;
F_193 ( V_315 , V_218 , F_133 , NULL , NULL ) ;
F_193 ( V_315 , V_212 , F_133 , F_160 ,
NULL ) ;
F_193 ( V_315 , V_270 , F_162 , NULL , NULL ) ;
F_193 ( V_315 , V_271 , F_162 , NULL , NULL ) ;
F_193 ( V_315 , V_268 , F_162 , F_168 ,
NULL ) ;
return 0 ;
}
