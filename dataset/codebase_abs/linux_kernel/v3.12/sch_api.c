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
static void F_17 ( struct V_37 * V_3 )
{
if ( ( V_3 -> V_42 != V_43 ) && ! ( V_3 -> V_40 & V_44 ) )
F_18 ( & V_3 -> V_45 , & F_19 ( V_3 ) -> V_46 -> V_45 ) ;
}
void F_20 ( struct V_37 * V_3 )
{
if ( ( V_3 -> V_42 != V_43 ) && ! ( V_3 -> V_40 & V_44 ) )
F_21 ( & V_3 -> V_45 ) ;
}
struct V_37 * F_22 ( struct V_47 * V_48 , T_2 V_39 )
{
struct V_37 * V_3 ;
V_3 = F_15 ( V_48 -> V_46 , V_39 ) ;
if ( V_3 )
goto V_11;
if ( F_23 ( V_48 ) )
V_3 = F_15 (
F_23 ( V_48 ) -> V_49 ,
V_39 ) ;
V_11:
return V_3 ;
}
static struct V_37 * F_24 ( struct V_37 * V_50 , T_2 V_51 )
{
unsigned long V_52 ;
struct V_37 * V_23 ;
const struct V_18 * V_19 = V_50 -> V_34 -> V_17 ;
if ( V_19 == NULL )
return NULL ;
V_52 = V_19 -> V_20 ( V_50 , V_51 ) ;
if ( V_52 == 0 )
return NULL ;
V_23 = V_19 -> V_23 ( V_50 , V_52 ) ;
V_19 -> V_21 ( V_50 , V_52 ) ;
return V_23 ;
}
static struct V_1 * F_25 ( struct V_53 * V_54 )
{
struct V_1 * V_3 = NULL ;
if ( V_54 ) {
F_6 ( & V_7 ) ;
for ( V_3 = V_8 ; V_3 ; V_3 = V_3 -> V_9 ) {
if ( F_26 ( V_54 , V_3 -> V_10 ) == 0 ) {
if ( ! F_10 ( V_3 -> V_33 ) )
V_3 = NULL ;
break;
}
}
F_8 ( & V_7 ) ;
}
return V_3 ;
}
static T_3 F_27 ( struct V_55 * V_56 , T_4 * V_57 )
{
int V_58 = F_28 ( V_56 -> V_59 , 48 ) ;
int V_60 = F_28 ( V_58 + 1 , 48 ) ;
int V_61 = V_58 >> V_56 -> V_62 ;
int V_63 = ( V_60 >> V_56 -> V_62 ) - 1 ;
if ( ( V_56 -> V_64 > ( 100000000 / 8 ) ) || ( V_57 [ 0 ] == 0 ) ) {
F_29 ( L_2 ) ;
return V_65 ;
}
if ( ( V_63 > V_61 ) && ( V_63 < 256 )
&& ( V_57 [ V_61 ] == V_57 [ V_63 ] ) ) {
F_29 ( L_3 ,
V_61 , V_63 , V_57 [ V_63 ] ) ;
return V_66 ;
}
return V_65 ;
}
struct V_67 * F_30 ( struct V_55 * V_56 , struct V_53 * V_68 )
{
struct V_67 * V_57 ;
if ( V_68 == NULL || V_56 -> V_64 == 0 || V_56 -> V_62 == 0 ||
F_31 ( V_68 ) != V_69 )
return NULL ;
for ( V_57 = V_70 ; V_57 ; V_57 = V_57 -> V_9 ) {
if ( ! memcmp ( & V_57 -> V_64 , V_56 , sizeof( struct V_55 ) ) &&
! memcmp ( & V_57 -> V_71 , F_32 ( V_68 ) , 1024 ) ) {
V_57 -> V_72 ++ ;
return V_57 ;
}
}
V_57 = F_33 ( sizeof( * V_57 ) , V_73 ) ;
if ( V_57 ) {
V_57 -> V_64 = * V_56 ;
V_57 -> V_72 = 1 ;
memcpy ( V_57 -> V_71 , F_32 ( V_68 ) , 1024 ) ;
if ( V_56 -> V_74 == V_75 )
V_56 -> V_74 = F_27 ( V_56 , V_57 -> V_71 ) ;
V_57 -> V_9 = V_70 ;
V_70 = V_57 ;
}
return V_57 ;
}
void F_34 ( struct V_67 * V_68 )
{
struct V_67 * V_57 , * * V_76 ;
if ( ! V_68 || -- V_68 -> V_72 )
return;
for ( V_76 = & V_70 ;
( V_57 = * V_76 ) != NULL ;
V_76 = & V_57 -> V_9 ) {
if ( V_57 == V_68 ) {
* V_76 = V_57 -> V_9 ;
F_35 ( V_57 ) ;
return;
}
}
}
static struct V_77 * F_36 ( struct V_53 * V_78 )
{
struct V_53 * V_79 [ V_80 + 1 ] ;
struct V_77 * V_81 ;
struct V_82 * V_83 ;
unsigned int V_84 = 0 ;
T_5 * V_68 = NULL ;
int V_28 ;
V_28 = F_37 ( V_79 , V_80 , V_78 , V_85 ) ;
if ( V_28 < 0 )
return F_38 ( V_28 ) ;
if ( ! V_79 [ V_86 ] )
return F_38 ( - V_27 ) ;
V_83 = F_32 ( V_79 [ V_86 ] ) ;
if ( V_83 -> V_84 > 0 ) {
if ( ! V_79 [ V_87 ] )
return F_38 ( - V_27 ) ;
V_68 = F_32 ( V_79 [ V_87 ] ) ;
V_84 = F_31 ( V_79 [ V_87 ] ) / sizeof( T_5 ) ;
}
if ( V_84 != V_83 -> V_84 || ( ! V_68 && V_84 > 0 ) )
return F_38 ( - V_27 ) ;
F_39 ( & V_88 ) ;
F_16 (stab, &qdisc_stab_list, list) {
if ( memcmp ( & V_81 -> V_89 , V_83 , sizeof( * V_83 ) ) )
continue;
if ( V_84 > 0 && memcmp ( V_81 -> V_71 , V_68 , V_84 * sizeof( T_5 ) ) )
continue;
V_81 -> V_72 ++ ;
F_40 ( & V_88 ) ;
return V_81 ;
}
F_40 ( & V_88 ) ;
V_81 = F_33 ( sizeof( * V_81 ) + V_84 * sizeof( T_5 ) , V_73 ) ;
if ( ! V_81 )
return F_38 ( - V_90 ) ;
V_81 -> V_72 = 1 ;
V_81 -> V_89 = * V_83 ;
if ( V_84 > 0 )
memcpy ( V_81 -> V_71 , V_68 , V_84 * sizeof( T_5 ) ) ;
F_39 ( & V_88 ) ;
F_18 ( & V_81 -> V_45 , & V_91 ) ;
F_40 ( & V_88 ) ;
return V_81 ;
}
static void F_41 ( struct V_92 * V_93 )
{
F_35 ( F_42 ( V_93 , struct V_77 , V_94 ) ) ;
}
void F_43 ( struct V_77 * V_68 )
{
if ( ! V_68 )
return;
F_39 ( & V_88 ) ;
if ( -- V_68 -> V_72 == 0 ) {
F_21 ( & V_68 -> V_45 ) ;
F_44 ( & V_68 -> V_94 , F_41 ) ;
}
F_40 ( & V_88 ) ;
}
static int F_45 ( struct V_95 * V_96 , struct V_77 * V_81 )
{
struct V_53 * V_97 ;
V_97 = F_46 ( V_96 , V_98 ) ;
if ( V_97 == NULL )
goto V_99;
if ( F_47 ( V_96 , V_86 , sizeof( V_81 -> V_89 ) , & V_81 -> V_89 ) )
goto V_99;
F_48 ( V_96 , V_97 ) ;
return V_96 -> V_31 ;
V_99:
return - 1 ;
}
void F_49 ( struct V_95 * V_96 , const struct V_77 * V_81 )
{
int V_100 , V_101 ;
V_100 = V_96 -> V_31 + V_81 -> V_89 . V_102 ;
if ( F_50 ( ! V_81 -> V_89 . V_84 ) )
goto V_11;
V_101 = V_100 + V_81 -> V_89 . V_103 ;
if ( F_50 ( V_101 < 0 ) )
V_101 = 0 ;
V_101 >>= V_81 -> V_89 . V_62 ;
if ( F_51 ( V_101 < V_81 -> V_89 . V_84 ) )
V_100 = V_81 -> V_71 [ V_101 ] ;
else
V_100 = V_81 -> V_71 [ V_81 -> V_89 . V_84 - 1 ] *
( V_101 / V_81 -> V_89 . V_84 ) +
V_81 -> V_71 [ V_101 % V_81 -> V_89 . V_84 ] ;
V_100 <<= V_81 -> V_89 . V_104 ;
V_11:
if ( F_50 ( V_100 < 1 ) )
V_100 = 1 ;
F_52 ( V_96 ) -> V_100 = V_100 ;
}
void F_53 ( char * V_105 , struct V_37 * V_46 )
{
if ( ! ( V_46 -> V_40 & V_106 ) ) {
F_54 ( L_4 ,
V_105 , V_46 -> V_34 -> V_10 , V_46 -> V_39 >> 16 ) ;
V_46 -> V_40 |= V_106 ;
}
}
static enum V_107 F_55 ( struct V_108 * V_109 )
{
struct F_55 * V_110 = F_42 ( V_109 , struct F_55 ,
V_109 ) ;
F_56 ( V_110 -> V_46 ) ;
F_57 ( F_58 ( V_110 -> V_46 ) ) ;
return V_111 ;
}
void F_59 ( struct F_55 * V_110 , struct V_37 * V_46 )
{
F_60 ( & V_110 -> V_109 , V_112 , V_113 ) ;
V_110 -> V_109 . V_114 = F_55 ;
V_110 -> V_46 = V_46 ;
}
void F_61 ( struct F_55 * V_110 , T_6 V_115 )
{
if ( F_62 ( V_116 ,
& F_63 ( V_110 -> V_46 ) -> V_117 ) )
return;
F_64 ( V_110 -> V_46 ) ;
F_65 ( & V_110 -> V_109 ,
F_66 ( V_115 ) ,
V_113 ) ;
}
void F_67 ( struct F_55 * V_110 )
{
F_68 ( & V_110 -> V_109 ) ;
F_56 ( V_110 -> V_46 ) ;
}
static struct V_118 * F_69 ( unsigned int V_119 )
{
unsigned int V_120 = V_119 * sizeof( struct V_118 ) , V_121 ;
struct V_118 * V_122 ;
if ( V_120 <= V_123 )
V_122 = F_33 ( V_120 , V_73 ) ;
else
V_122 = (struct V_118 * )
F_70 ( V_73 , F_71 ( V_120 ) ) ;
if ( V_122 != NULL ) {
for ( V_121 = 0 ; V_121 < V_119 ; V_121 ++ )
F_72 ( & V_122 [ V_121 ] ) ;
}
return V_122 ;
}
static void F_73 ( struct V_118 * V_122 , unsigned int V_119 )
{
unsigned int V_120 = V_119 * sizeof( struct V_118 ) ;
if ( V_120 <= V_123 )
F_35 ( V_122 ) ;
else
F_74 ( ( unsigned long ) V_122 , F_71 ( V_120 ) ) ;
}
void F_75 ( struct V_37 * V_124 , struct V_125 * V_126 )
{
struct V_127 * V_52 ;
struct V_128 * V_9 ;
struct V_118 * V_129 , * V_130 ;
unsigned int V_131 , V_132 , V_133 ;
unsigned int V_121 , V_122 ;
if ( V_126 -> V_134 * 4 <= V_126 -> V_135 * 3 )
return;
V_131 = V_126 -> V_135 * 2 ;
V_132 = V_131 - 1 ;
V_129 = F_69 ( V_131 ) ;
if ( V_129 == NULL )
return;
V_130 = V_126 -> V_136 ;
V_133 = V_126 -> V_135 ;
F_76 ( V_124 ) ;
for ( V_121 = 0 ; V_121 < V_133 ; V_121 ++ ) {
F_77 (cl, next, &ohash[i], hnode) {
V_122 = F_78 ( V_52 -> V_51 , V_132 ) ;
F_79 ( & V_52 -> V_137 , & V_129 [ V_122 ] ) ;
}
}
V_126 -> V_136 = V_129 ;
V_126 -> V_135 = V_131 ;
V_126 -> V_138 = V_132 ;
F_80 ( V_124 ) ;
F_73 ( V_130 , V_133 ) ;
}
int F_81 ( struct V_125 * V_126 )
{
unsigned int V_120 = 4 ;
V_126 -> V_136 = F_69 ( V_120 ) ;
if ( V_126 -> V_136 == NULL )
return - V_90 ;
V_126 -> V_135 = V_120 ;
V_126 -> V_138 = V_120 - 1 ;
V_126 -> V_134 = 0 ;
return 0 ;
}
void F_82 ( struct V_125 * V_126 )
{
F_73 ( V_126 -> V_136 , V_126 -> V_135 ) ;
}
void F_83 ( struct V_125 * V_126 ,
struct V_127 * V_52 )
{
unsigned int V_122 ;
F_84 ( & V_52 -> V_137 ) ;
V_122 = F_78 ( V_52 -> V_51 , V_126 -> V_138 ) ;
F_79 ( & V_52 -> V_137 , & V_126 -> V_136 [ V_122 ] ) ;
V_126 -> V_134 ++ ;
}
void F_85 ( struct V_125 * V_126 ,
struct V_127 * V_52 )
{
F_86 ( & V_52 -> V_137 ) ;
V_126 -> V_134 -- ;
}
static T_2 F_87 ( struct V_47 * V_48 )
{
int V_121 = 0x8000 ;
static T_2 V_139 = F_88 ( 0x80000000U , 0 ) ;
do {
V_139 += F_88 ( 0x10000U , 0 ) ;
if ( V_139 == F_88 ( V_43 , 0 ) )
V_139 = F_88 ( 0x80000000U , 0 ) ;
if ( ! F_22 ( V_48 , V_139 ) )
return V_139 ;
F_89 () ;
} while ( -- V_121 > 0 );
return 0 ;
}
void F_90 ( struct V_37 * V_124 , unsigned int V_119 )
{
const struct V_18 * V_19 ;
unsigned long V_52 ;
T_2 V_140 ;
if ( V_119 == 0 )
return;
while ( ( V_140 = V_124 -> V_42 ) ) {
if ( F_91 ( V_140 ) == F_91 ( V_141 ) )
return;
V_124 = F_22 ( F_19 ( V_124 ) , F_91 ( V_140 ) ) ;
if ( V_124 == NULL ) {
F_92 ( V_140 != V_43 ) ;
return;
}
V_19 = V_124 -> V_34 -> V_17 ;
if ( V_19 -> V_142 ) {
V_52 = V_19 -> V_20 ( V_124 , V_140 ) ;
V_19 -> V_142 ( V_124 , V_52 ) ;
V_19 -> V_21 ( V_124 , V_52 ) ;
}
V_124 -> V_3 . V_143 -= V_119 ;
}
}
static void F_93 ( struct V_144 * V_144 , struct V_95 * V_96 ,
struct V_145 * V_119 , T_2 V_146 ,
struct V_37 * V_147 , struct V_37 * V_148 )
{
if ( V_148 || V_147 )
F_94 ( V_144 , V_96 , V_119 , V_146 , V_147 , V_148 ) ;
if ( V_147 )
F_95 ( V_147 ) ;
}
static int F_96 ( struct V_47 * V_48 , struct V_37 * V_42 ,
struct V_95 * V_96 , struct V_145 * V_119 , T_2 V_51 ,
struct V_37 * V_148 , struct V_37 * V_147 )
{
struct V_37 * V_3 = V_147 ;
struct V_144 * V_144 = F_97 ( V_48 ) ;
int V_28 = 0 ;
if ( V_42 == NULL ) {
unsigned int V_121 , V_149 , V_150 ;
V_150 = 0 ;
V_149 = V_48 -> V_151 ;
if ( ( V_3 && V_3 -> V_40 & V_44 ) ||
( V_148 && V_148 -> V_40 & V_44 ) ) {
V_149 = 1 ;
V_150 = 1 ;
if ( ! F_23 ( V_48 ) )
return - V_29 ;
}
if ( V_48 -> V_40 & V_152 )
F_98 ( V_48 ) ;
if ( V_148 && V_148 -> V_34 -> V_153 ) {
V_148 -> V_34 -> V_153 ( V_148 ) ;
V_149 = 0 ;
}
for ( V_121 = 0 ; V_121 < V_149 ; V_121 ++ ) {
struct V_154 * V_155 = F_23 ( V_48 ) ;
if ( ! V_150 )
V_155 = F_99 ( V_48 , V_121 ) ;
V_147 = F_100 ( V_155 , V_148 ) ;
if ( V_148 && V_121 > 0 )
F_101 ( & V_148 -> V_72 ) ;
if ( ! V_150 )
F_95 ( V_147 ) ;
}
if ( ! V_150 ) {
F_93 ( V_144 , V_96 , V_119 , V_51 ,
V_48 -> V_46 , V_148 ) ;
if ( V_148 && ! V_148 -> V_34 -> V_153 )
F_101 ( & V_148 -> V_72 ) ;
V_48 -> V_46 = V_148 ? : & V_156 ;
} else {
F_93 ( V_144 , V_96 , V_119 , V_51 , V_147 , V_148 ) ;
}
if ( V_48 -> V_40 & V_152 )
F_102 ( V_48 ) ;
} else {
const struct V_18 * V_19 = V_42 -> V_34 -> V_17 ;
V_28 = - V_157 ;
if ( V_19 && V_19 -> V_158 ) {
unsigned long V_52 = V_19 -> V_20 ( V_42 , V_51 ) ;
if ( V_52 ) {
V_28 = V_19 -> V_158 ( V_42 , V_52 , V_148 , & V_147 ) ;
V_19 -> V_21 ( V_42 , V_52 ) ;
} else
V_28 = - V_29 ;
}
if ( ! V_28 )
F_93 ( V_144 , V_96 , V_119 , V_51 , V_147 , V_148 ) ;
}
return V_28 ;
}
static struct V_37 *
F_103 ( struct V_47 * V_48 , struct V_154 * V_155 ,
struct V_37 * V_50 , T_2 V_42 , T_2 V_39 ,
struct V_53 * * V_159 , int * V_160 )
{
int V_28 ;
struct V_53 * V_54 = V_159 [ V_161 ] ;
struct V_37 * V_124 ;
struct V_1 * V_34 ;
struct V_77 * V_81 ;
V_34 = F_25 ( V_54 ) ;
#ifdef F_104
if ( V_34 == NULL && V_54 != NULL ) {
char V_30 [ V_162 ] ;
if ( F_105 ( V_30 , V_54 , V_162 ) < V_162 ) {
F_106 () ;
F_13 ( L_1 , V_30 ) ;
F_107 () ;
V_34 = F_25 ( V_54 ) ;
if ( V_34 != NULL ) {
F_14 ( V_34 -> V_33 ) ;
V_28 = - V_163 ;
goto V_164;
}
}
}
#endif
V_28 = - V_29 ;
if ( V_34 == NULL )
goto V_164;
V_124 = F_108 ( V_155 , V_34 ) ;
if ( F_109 ( V_124 ) ) {
V_28 = F_110 ( V_124 ) ;
goto V_165;
}
V_124 -> V_42 = V_42 ;
if ( V_39 == V_141 ) {
V_124 -> V_40 |= V_44 ;
V_39 = F_88 ( V_141 , 0 ) ;
F_111 ( F_112 ( V_124 ) , & V_166 ) ;
} else {
if ( V_39 == 0 ) {
V_39 = F_87 ( V_48 ) ;
V_28 = - V_90 ;
if ( V_39 == 0 )
goto V_167;
}
F_111 ( F_112 ( V_124 ) , & V_168 ) ;
if ( ! F_113 ( V_48 ) )
V_124 -> V_40 |= V_169 ;
}
V_124 -> V_39 = V_39 ;
if ( ! V_34 -> V_170 || ( V_28 = V_34 -> V_170 ( V_124 , V_159 [ V_171 ] ) ) == 0 ) {
if ( V_159 [ V_98 ] ) {
V_81 = F_36 ( V_159 [ V_98 ] ) ;
if ( F_109 ( V_81 ) ) {
V_28 = F_110 ( V_81 ) ;
goto V_172;
}
F_114 ( V_124 -> V_81 , V_81 ) ;
}
if ( V_159 [ V_173 ] ) {
T_7 * V_174 ;
V_28 = - V_157 ;
if ( V_124 -> V_40 & V_175 )
goto V_172;
if ( ( V_124 -> V_42 != V_43 ) &&
! ( V_124 -> V_40 & V_44 ) &&
( ! V_50 || ! ( V_50 -> V_40 & V_175 ) ) )
V_174 = F_115 ( V_124 ) ;
else
V_174 = F_112 ( V_124 ) ;
V_28 = F_116 ( & V_124 -> V_176 , & V_124 -> V_177 ,
V_174 , V_159 [ V_173 ] ) ;
if ( V_28 )
goto V_172;
}
F_17 ( V_124 ) ;
return V_124 ;
}
V_167:
F_117 ( V_48 ) ;
F_35 ( ( char * ) V_124 - V_124 -> V_178 ) ;
V_165:
F_14 ( V_34 -> V_33 ) ;
V_164:
* V_160 = V_28 ;
return NULL ;
V_172:
F_43 ( F_118 ( V_124 -> V_81 ) ) ;
if ( V_34 -> V_179 )
V_34 -> V_179 ( V_124 ) ;
goto V_167;
}
static int F_119 ( struct V_37 * V_124 , struct V_53 * * V_159 )
{
struct V_77 * V_180 , * V_81 = NULL ;
int V_28 = 0 ;
if ( V_159 [ V_171 ] ) {
if ( V_124 -> V_34 -> V_181 == NULL )
return - V_27 ;
V_28 = V_124 -> V_34 -> V_181 ( V_124 , V_159 [ V_171 ] ) ;
if ( V_28 )
return V_28 ;
}
if ( V_159 [ V_98 ] ) {
V_81 = F_36 ( V_159 [ V_98 ] ) ;
if ( F_109 ( V_81 ) )
return F_110 ( V_81 ) ;
}
V_180 = F_118 ( V_124 -> V_81 ) ;
F_114 ( V_124 -> V_81 , V_81 ) ;
F_43 ( V_180 ) ;
if ( V_159 [ V_173 ] ) {
if ( V_124 -> V_40 & V_175 )
goto V_11;
F_120 ( & V_124 -> V_176 , & V_124 -> V_177 ,
F_115 ( V_124 ) ,
V_159 [ V_173 ] ) ;
}
V_11:
return 0 ;
}
static int F_121 ( struct V_37 * V_3 , struct V_37 * V_50 , int V_182 )
{
struct V_183 V_184 ;
if ( V_3 -> V_34 -> V_17 == NULL )
return 0 ;
V_184 . V_185 . V_186 = V_184 . V_185 . V_187 = V_184 . V_185 . V_188 = 0 ;
V_184 . V_185 . V_189 = V_190 ;
V_184 . V_182 = V_182 ;
V_184 . V_50 = V_50 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_184 . V_185 ) ;
return V_184 . V_185 . V_186 ? - V_191 : 0 ;
}
static int
V_190 ( struct V_37 * V_3 , unsigned long V_52 , struct V_192 * V_185 )
{
struct V_37 * V_23 ;
const struct V_18 * V_19 = V_3 -> V_34 -> V_17 ;
struct V_183 * V_184 = (struct V_183 * ) V_185 ;
V_23 = V_19 -> V_23 ( V_3 , V_52 ) ;
if ( V_23 ) {
if ( V_23 == V_184 -> V_50 || V_184 -> V_182 > 7 )
return - V_191 ;
return F_121 ( V_23 , V_184 -> V_50 , V_184 -> V_182 + 1 ) ;
}
return 0 ;
}
static int F_122 ( struct V_95 * V_96 , struct V_145 * V_119 )
{
struct V_144 * V_144 = F_123 ( V_96 -> V_193 ) ;
struct V_194 * V_195 = F_124 ( V_119 ) ;
struct V_53 * V_159 [ V_196 + 1 ] ;
struct V_47 * V_48 ;
T_2 V_146 ;
struct V_37 * V_3 = NULL ;
struct V_37 * V_50 = NULL ;
int V_28 ;
if ( ( V_119 -> V_197 != V_198 ) && ! F_12 ( V_35 ) )
return - V_36 ;
V_28 = F_125 ( V_119 , sizeof( * V_195 ) , V_159 , V_196 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_48 = F_126 ( V_144 , V_195 -> V_199 ) ;
if ( ! V_48 )
return - V_200 ;
V_146 = V_195 -> V_201 ;
if ( V_146 ) {
if ( V_146 != V_43 ) {
if ( F_91 ( V_146 ) != F_91 ( V_141 ) ) {
V_50 = F_22 ( V_48 , F_91 ( V_146 ) ) ;
if ( ! V_50 )
return - V_29 ;
V_3 = F_24 ( V_50 , V_146 ) ;
} else if ( F_23 ( V_48 ) ) {
V_3 = F_23 ( V_48 ) -> V_49 ;
}
} else {
V_3 = V_48 -> V_46 ;
}
if ( ! V_3 )
return - V_29 ;
if ( V_195 -> V_202 && V_3 -> V_39 != V_195 -> V_202 )
return - V_27 ;
} else {
V_3 = F_22 ( V_48 , V_195 -> V_202 ) ;
if ( ! V_3 )
return - V_29 ;
}
if ( V_159 [ V_161 ] && F_26 ( V_159 [ V_161 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_119 -> V_197 == V_203 ) {
if ( ! V_146 )
return - V_27 ;
if ( V_3 -> V_39 == 0 )
return - V_29 ;
V_28 = F_96 ( V_48 , V_50 , V_96 , V_119 , V_146 , NULL , V_3 ) ;
if ( V_28 != 0 )
return V_28 ;
} else {
F_94 ( V_144 , V_96 , V_119 , V_146 , NULL , V_3 ) ;
}
return 0 ;
}
static int F_127 ( struct V_95 * V_96 , struct V_145 * V_119 )
{
struct V_144 * V_144 = F_123 ( V_96 -> V_193 ) ;
struct V_194 * V_195 ;
struct V_53 * V_159 [ V_196 + 1 ] ;
struct V_47 * V_48 ;
T_2 V_146 ;
struct V_37 * V_3 , * V_50 ;
int V_28 ;
if ( ! F_12 ( V_35 ) )
return - V_36 ;
V_204:
V_28 = F_125 ( V_119 , sizeof( * V_195 ) , V_159 , V_196 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_195 = F_124 ( V_119 ) ;
V_146 = V_195 -> V_201 ;
V_3 = V_50 = NULL ;
V_48 = F_126 ( V_144 , V_195 -> V_199 ) ;
if ( ! V_48 )
return - V_200 ;
if ( V_146 ) {
if ( V_146 != V_43 ) {
if ( V_146 != V_141 ) {
V_50 = F_22 ( V_48 , F_91 ( V_146 ) ) ;
if ( ! V_50 )
return - V_29 ;
V_3 = F_24 ( V_50 , V_146 ) ;
} else if ( F_128 ( V_48 ) ) {
V_3 = F_23 ( V_48 ) -> V_49 ;
}
} else {
V_3 = V_48 -> V_46 ;
}
if ( V_3 && V_3 -> V_39 == 0 )
V_3 = NULL ;
if ( ! V_3 || ! V_195 -> V_202 || V_3 -> V_39 != V_195 -> V_202 ) {
if ( V_195 -> V_202 ) {
if ( V_3 && ! ( V_119 -> V_205 & V_206 ) )
return - V_6 ;
if ( F_129 ( V_195 -> V_202 ) )
return - V_27 ;
V_3 = F_22 ( V_48 , V_195 -> V_202 ) ;
if ( ! V_3 )
goto V_207;
if ( V_119 -> V_205 & V_208 )
return - V_6 ;
if ( V_159 [ V_161 ] && F_26 ( V_159 [ V_161 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_3 == V_50 ||
( V_50 && F_121 ( V_3 , V_50 , 0 ) ) )
return - V_191 ;
F_101 ( & V_3 -> V_72 ) ;
goto V_158;
} else {
if ( ! V_3 )
goto V_207;
if ( ( V_119 -> V_205 & V_209 ) &&
( V_119 -> V_205 & V_206 ) &&
( ( V_119 -> V_205 & V_208 ) ||
( V_159 [ V_161 ] &&
F_26 ( V_159 [ V_161 ] , V_3 -> V_34 -> V_10 ) ) ) )
goto V_207;
}
}
} else {
if ( ! V_195 -> V_202 )
return - V_27 ;
V_3 = F_22 ( V_48 , V_195 -> V_202 ) ;
}
if ( V_3 == NULL )
return - V_29 ;
if ( V_119 -> V_205 & V_208 )
return - V_6 ;
if ( V_159 [ V_161 ] && F_26 ( V_159 [ V_161 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
V_28 = F_119 ( V_3 , V_159 ) ;
if ( V_28 == 0 )
F_94 ( V_144 , V_96 , V_119 , V_146 , NULL , V_3 ) ;
return V_28 ;
V_207:
if ( ! ( V_119 -> V_205 & V_209 ) )
return - V_29 ;
if ( V_146 == V_141 ) {
if ( F_23 ( V_48 ) )
V_3 = F_103 ( V_48 , F_23 ( V_48 ) , V_50 ,
V_195 -> V_201 , V_195 -> V_201 ,
V_159 , & V_28 ) ;
else
V_28 = - V_29 ;
} else {
struct V_154 * V_155 ;
if ( V_50 && V_50 -> V_34 -> V_17 && V_50 -> V_34 -> V_17 -> V_210 )
V_155 = V_50 -> V_34 -> V_17 -> V_210 ( V_50 , V_195 ) ;
else if ( V_50 )
V_155 = V_50 -> V_155 ;
else
V_155 = F_99 ( V_48 , 0 ) ;
V_3 = F_103 ( V_48 , V_155 , V_50 ,
V_195 -> V_201 , V_195 -> V_202 ,
V_159 , & V_28 ) ;
}
if ( V_3 == NULL ) {
if ( V_28 == - V_163 )
goto V_204;
return V_28 ;
}
V_158:
V_28 = F_96 ( V_48 , V_50 , V_96 , V_119 , V_146 , V_3 , NULL ) ;
if ( V_28 ) {
if ( V_3 )
F_95 ( V_3 ) ;
return V_28 ;
}
return 0 ;
}
static int F_130 ( struct V_95 * V_96 , struct V_37 * V_3 , T_2 V_146 ,
T_2 V_211 , T_2 V_212 , T_5 V_40 , int V_213 )
{
struct V_194 * V_195 ;
struct V_145 * V_214 ;
unsigned char * V_215 = F_131 ( V_96 ) ;
struct V_216 V_217 ;
struct V_77 * V_81 ;
V_214 = F_132 ( V_96 , V_211 , V_212 , V_213 , sizeof( * V_195 ) , V_40 ) ;
if ( ! V_214 )
goto V_218;
V_195 = F_124 ( V_214 ) ;
V_195 -> V_219 = V_220 ;
V_195 -> V_221 = 0 ;
V_195 -> V_222 = 0 ;
V_195 -> V_199 = F_19 ( V_3 ) -> V_223 ;
V_195 -> V_201 = V_146 ;
V_195 -> V_202 = V_3 -> V_39 ;
V_195 -> V_224 = F_133 ( & V_3 -> V_72 ) ;
if ( F_134 ( V_96 , V_161 , V_3 -> V_34 -> V_10 ) )
goto V_99;
if ( V_3 -> V_34 -> V_225 && V_3 -> V_34 -> V_225 ( V_3 , V_96 ) < 0 )
goto V_99;
V_3 -> V_226 . V_143 = V_3 -> V_3 . V_143 ;
V_81 = F_118 ( V_3 -> V_81 ) ;
if ( V_81 && F_45 ( V_96 , V_81 ) < 0 )
goto V_99;
if ( F_135 ( V_96 , V_227 , V_228 , V_229 ,
F_115 ( V_3 ) , & V_217 ) < 0 )
goto V_99;
if ( V_3 -> V_34 -> V_230 && V_3 -> V_34 -> V_230 ( V_3 , & V_217 ) < 0 )
goto V_99;
if ( F_136 ( & V_217 , & V_3 -> V_176 ) < 0 ||
F_137 ( & V_217 , & V_3 -> V_176 , & V_3 -> V_177 ) < 0 ||
F_138 ( & V_217 , & V_3 -> V_226 ) < 0 )
goto V_99;
if ( F_139 ( & V_217 ) < 0 )
goto V_99;
V_214 -> V_231 = F_131 ( V_96 ) - V_215 ;
return V_96 -> V_31 ;
V_218:
V_99:
F_140 ( V_96 , V_215 ) ;
return - 1 ;
}
static bool F_141 ( struct V_37 * V_3 )
{
return ( V_3 -> V_40 & V_41 ) ? true : false ;
}
static int F_94 ( struct V_144 * V_144 , struct V_95 * V_232 ,
struct V_145 * V_119 , T_2 V_146 ,
struct V_37 * V_147 , struct V_37 * V_148 )
{
struct V_95 * V_96 ;
T_2 V_211 = V_232 ? F_142 ( V_232 ) . V_211 : 0 ;
V_96 = F_143 ( V_233 , V_73 ) ;
if ( ! V_96 )
return - V_234 ;
if ( V_147 && ! F_141 ( V_147 ) ) {
if ( F_130 ( V_96 , V_147 , V_146 , V_211 , V_119 -> V_235 ,
0 , V_203 ) < 0 )
goto V_164;
}
if ( V_148 && ! F_141 ( V_148 ) ) {
if ( F_130 ( V_96 , V_148 , V_146 , V_211 , V_119 -> V_235 ,
V_147 ? V_206 : 0 , V_236 ) < 0 )
goto V_164;
}
if ( V_96 -> V_31 )
return F_144 ( V_96 , V_144 , V_211 , V_237 ,
V_119 -> V_205 & V_238 ) ;
V_164:
F_145 ( V_96 ) ;
return - V_27 ;
}
static int F_146 ( struct V_37 * V_38 , struct V_95 * V_96 ,
struct V_239 * V_240 ,
int * V_241 , int V_242 )
{
int V_243 = 0 , V_244 = * V_241 ;
struct V_37 * V_3 ;
if ( ! V_38 )
return 0 ;
V_3 = V_38 ;
if ( V_244 < V_242 ) {
V_244 ++ ;
} else {
if ( ! F_141 ( V_3 ) &&
F_130 ( V_96 , V_3 , V_3 -> V_42 , F_142 ( V_240 -> V_96 ) . V_211 ,
V_240 -> V_214 -> V_235 , V_245 , V_236 ) <= 0 )
goto V_246;
V_244 ++ ;
}
F_16 (q, &root->list, list) {
if ( V_244 < V_242 ) {
V_244 ++ ;
continue;
}
if ( ! F_141 ( V_3 ) &&
F_130 ( V_96 , V_3 , V_3 -> V_42 , F_142 ( V_240 -> V_96 ) . V_211 ,
V_240 -> V_214 -> V_235 , V_245 , V_236 ) <= 0 )
goto V_246;
V_244 ++ ;
}
V_11:
* V_241 = V_244 ;
return V_243 ;
V_246:
V_243 = - 1 ;
goto V_11;
}
static int F_147 ( struct V_95 * V_96 , struct V_239 * V_240 )
{
struct V_144 * V_144 = F_123 ( V_96 -> V_193 ) ;
int V_247 , V_244 ;
int V_248 , V_242 ;
struct V_47 * V_48 ;
V_248 = V_240 -> args [ 0 ] ;
V_242 = V_244 = V_240 -> args [ 1 ] ;
F_148 () ;
V_247 = 0 ;
F_149 (net, dev) {
struct V_154 * V_155 ;
if ( V_247 < V_248 )
goto V_249;
if ( V_247 > V_248 )
V_242 = 0 ;
V_244 = 0 ;
if ( F_146 ( V_48 -> V_46 , V_96 , V_240 , & V_244 , V_242 ) < 0 )
goto V_246;
V_155 = F_23 ( V_48 ) ;
if ( V_155 &&
F_146 ( V_155 -> V_49 , V_96 , V_240 ,
& V_244 , V_242 ) < 0 )
goto V_246;
V_249:
V_247 ++ ;
}
V_246:
F_150 () ;
V_240 -> args [ 0 ] = V_247 ;
V_240 -> args [ 1 ] = V_244 ;
return V_96 -> V_31 ;
}
static int F_151 ( struct V_95 * V_96 , struct V_145 * V_119 )
{
struct V_144 * V_144 = F_123 ( V_96 -> V_193 ) ;
struct V_194 * V_195 = F_124 ( V_119 ) ;
struct V_53 * V_159 [ V_196 + 1 ] ;
struct V_47 * V_48 ;
struct V_37 * V_3 = NULL ;
const struct V_18 * V_19 ;
unsigned long V_52 = 0 ;
unsigned long V_250 ;
T_2 V_211 ;
T_2 V_146 ;
T_2 V_251 ;
int V_28 ;
if ( ( V_119 -> V_197 != V_252 ) && ! F_12 ( V_35 ) )
return - V_36 ;
V_28 = F_125 ( V_119 , sizeof( * V_195 ) , V_159 , V_196 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_48 = F_126 ( V_144 , V_195 -> V_199 ) ;
if ( ! V_48 )
return - V_200 ;
V_211 = V_195 -> V_201 ;
V_146 = V_195 -> V_202 ;
V_251 = F_91 ( V_146 ) ;
if ( V_211 != V_43 ) {
T_2 V_253 = F_91 ( V_211 ) ;
if ( V_251 && V_253 ) {
if ( V_251 != V_253 )
return - V_27 ;
} else if ( V_253 ) {
V_251 = V_253 ;
} else if ( V_251 == 0 )
V_251 = V_48 -> V_46 -> V_39 ;
if ( V_211 )
V_211 = F_88 ( V_251 , V_211 ) ;
} else {
if ( V_251 == 0 )
V_251 = V_48 -> V_46 -> V_39 ;
}
V_3 = F_22 ( V_48 , V_251 ) ;
if ( ! V_3 )
return - V_29 ;
V_19 = V_3 -> V_34 -> V_17 ;
if ( V_19 == NULL )
return - V_27 ;
if ( V_146 == 0 ) {
if ( V_211 == V_43 )
V_146 = V_251 ;
} else
V_146 = F_88 ( V_251 , V_146 ) ;
if ( V_146 )
V_52 = V_19 -> V_20 ( V_3 , V_146 ) ;
if ( V_52 == 0 ) {
V_28 = - V_29 ;
if ( V_119 -> V_197 != V_254 ||
! ( V_119 -> V_205 & V_209 ) )
goto V_11;
} else {
switch ( V_119 -> V_197 ) {
case V_254 :
V_28 = - V_6 ;
if ( V_119 -> V_205 & V_208 )
goto V_11;
break;
case V_255 :
V_28 = - V_157 ;
if ( V_19 -> V_256 )
V_28 = V_19 -> V_256 ( V_3 , V_52 ) ;
if ( V_28 == 0 )
F_152 ( V_144 , V_96 , V_119 , V_3 , V_52 , V_255 ) ;
goto V_11;
case V_252 :
V_28 = F_152 ( V_144 , V_96 , V_119 , V_3 , V_52 , V_254 ) ;
goto V_11;
default:
V_28 = - V_27 ;
goto V_11;
}
}
V_250 = V_52 ;
V_28 = - V_157 ;
if ( V_19 -> V_181 )
V_28 = V_19 -> V_181 ( V_3 , V_146 , V_211 , V_159 , & V_250 ) ;
if ( V_28 == 0 )
F_152 ( V_144 , V_96 , V_119 , V_3 , V_250 , V_254 ) ;
V_11:
if ( V_52 )
V_19 -> V_21 ( V_3 , V_52 ) ;
return V_28 ;
}
static int F_153 ( struct V_95 * V_96 , struct V_37 * V_3 ,
unsigned long V_52 ,
T_2 V_211 , T_2 V_212 , T_5 V_40 , int V_213 )
{
struct V_194 * V_195 ;
struct V_145 * V_214 ;
unsigned char * V_215 = F_131 ( V_96 ) ;
struct V_216 V_217 ;
const struct V_18 * V_17 = V_3 -> V_34 -> V_17 ;
V_214 = F_132 ( V_96 , V_211 , V_212 , V_213 , sizeof( * V_195 ) , V_40 ) ;
if ( ! V_214 )
goto V_218;
V_195 = F_124 ( V_214 ) ;
V_195 -> V_219 = V_220 ;
V_195 -> V_221 = 0 ;
V_195 -> V_222 = 0 ;
V_195 -> V_199 = F_19 ( V_3 ) -> V_223 ;
V_195 -> V_201 = V_3 -> V_39 ;
V_195 -> V_202 = V_3 -> V_39 ;
V_195 -> V_224 = 0 ;
if ( F_134 ( V_96 , V_161 , V_3 -> V_34 -> V_10 ) )
goto V_99;
if ( V_17 -> V_225 && V_17 -> V_225 ( V_3 , V_52 , V_96 , V_195 ) < 0 )
goto V_99;
if ( F_135 ( V_96 , V_227 , V_228 , V_229 ,
F_115 ( V_3 ) , & V_217 ) < 0 )
goto V_99;
if ( V_17 -> V_230 && V_17 -> V_230 ( V_3 , V_52 , & V_217 ) < 0 )
goto V_99;
if ( F_139 ( & V_217 ) < 0 )
goto V_99;
V_214 -> V_231 = F_131 ( V_96 ) - V_215 ;
return V_96 -> V_31 ;
V_218:
V_99:
F_140 ( V_96 , V_215 ) ;
return - 1 ;
}
static int F_152 ( struct V_144 * V_144 , struct V_95 * V_232 ,
struct V_145 * V_119 , struct V_37 * V_3 ,
unsigned long V_52 , int V_213 )
{
struct V_95 * V_96 ;
T_2 V_211 = V_232 ? F_142 ( V_232 ) . V_211 : 0 ;
V_96 = F_143 ( V_233 , V_73 ) ;
if ( ! V_96 )
return - V_234 ;
if ( F_153 ( V_96 , V_3 , V_52 , V_211 , V_119 -> V_235 , 0 , V_213 ) < 0 ) {
F_145 ( V_96 ) ;
return - V_27 ;
}
return F_144 ( V_96 , V_144 , V_211 , V_237 ,
V_119 -> V_205 & V_238 ) ;
}
static int F_154 ( struct V_37 * V_3 , unsigned long V_52 , struct V_192 * V_184 )
{
struct V_257 * V_258 = (struct V_257 * ) V_184 ;
return F_153 ( V_258 -> V_96 , V_3 , V_52 , F_142 ( V_258 -> V_240 -> V_96 ) . V_211 ,
V_258 -> V_240 -> V_214 -> V_235 , V_245 , V_254 ) ;
}
static int F_155 ( struct V_37 * V_3 , struct V_95 * V_96 ,
struct V_194 * V_195 , struct V_239 * V_240 ,
int * V_259 , int V_260 )
{
struct V_257 V_184 ;
if ( F_141 ( V_3 ) ||
* V_259 < V_260 || ! V_3 -> V_34 -> V_17 ||
( V_195 -> V_201 &&
F_91 ( V_195 -> V_201 ) != V_3 -> V_39 ) ) {
( * V_259 ) ++ ;
return 0 ;
}
if ( * V_259 > V_260 )
memset ( & V_240 -> args [ 1 ] , 0 , sizeof( V_240 -> args ) - sizeof( V_240 -> args [ 0 ] ) ) ;
V_184 . V_185 . V_189 = F_154 ;
V_184 . V_96 = V_96 ;
V_184 . V_240 = V_240 ;
V_184 . V_185 . V_186 = 0 ;
V_184 . V_185 . V_187 = V_240 -> args [ 1 ] ;
V_184 . V_185 . V_188 = 0 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_184 . V_185 ) ;
V_240 -> args [ 1 ] = V_184 . V_185 . V_188 ;
if ( V_184 . V_185 . V_186 )
return - 1 ;
( * V_259 ) ++ ;
return 0 ;
}
static int F_156 ( struct V_37 * V_38 , struct V_95 * V_96 ,
struct V_194 * V_195 , struct V_239 * V_240 ,
int * V_259 , int V_260 )
{
struct V_37 * V_3 ;
if ( ! V_38 )
return 0 ;
if ( F_155 ( V_38 , V_96 , V_195 , V_240 , V_259 , V_260 ) < 0 )
return - 1 ;
F_16 (q, &root->list, list) {
if ( F_155 ( V_3 , V_96 , V_195 , V_240 , V_259 , V_260 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_157 ( struct V_95 * V_96 , struct V_239 * V_240 )
{
struct V_194 * V_195 = F_124 ( V_240 -> V_214 ) ;
struct V_144 * V_144 = F_123 ( V_96 -> V_193 ) ;
struct V_154 * V_155 ;
struct V_47 * V_48 ;
int V_261 , V_260 ;
if ( V_231 ( V_240 -> V_214 ) < sizeof( * V_195 ) )
return 0 ;
V_48 = F_158 ( V_144 , V_195 -> V_199 ) ;
if ( ! V_48 )
return 0 ;
V_260 = V_240 -> args [ 0 ] ;
V_261 = 0 ;
if ( F_156 ( V_48 -> V_46 , V_96 , V_195 , V_240 , & V_261 , V_260 ) < 0 )
goto V_246;
V_155 = F_23 ( V_48 ) ;
if ( V_155 &&
F_156 ( V_155 -> V_49 , V_96 , V_195 , V_240 ,
& V_261 , V_260 ) < 0 )
goto V_246;
V_246:
V_240 -> args [ 0 ] = V_261 ;
F_117 ( V_48 ) ;
return V_96 -> V_31 ;
}
int F_159 ( struct V_95 * V_96 , const struct V_262 * V_263 ,
struct V_264 * V_265 )
{
T_8 V_266 = V_96 -> V_266 ;
int V_28 ;
for (; V_263 ; V_263 = V_263 -> V_9 ) {
if ( V_263 -> V_266 != V_266 &&
V_263 -> V_266 != F_160 ( V_267 ) )
continue;
V_28 = V_263 -> V_268 ( V_96 , V_263 , V_265 ) ;
if ( V_28 >= 0 ) {
#ifdef F_161
if ( V_28 != V_269 && V_96 -> V_270 )
V_96 -> V_270 = F_162 ( V_96 -> V_270 , 0 ) ;
#endif
return V_28 ;
}
}
return - 1 ;
}
int F_163 ( struct V_95 * V_96 , const struct V_262 * V_263 ,
struct V_264 * V_265 )
{
int V_28 = 0 ;
#ifdef F_161
const struct V_262 * V_271 = V_263 ;
V_272:
#endif
V_28 = F_159 ( V_96 , V_263 , V_265 ) ;
#ifdef F_161
if ( V_28 == V_269 ) {
T_2 V_273 = F_164 ( V_96 -> V_270 ) ;
V_263 = V_271 ;
if ( V_273 ++ >= V_274 ) {
F_165 ( L_5 ,
V_263 -> V_3 -> V_34 -> V_10 ,
V_263 -> V_275 & 0xffff ,
F_166 ( V_263 -> V_266 ) ) ;
return V_276 ;
}
V_96 -> V_270 = F_162 ( V_96 -> V_270 , V_273 ) ;
goto V_272;
}
#endif
return V_28 ;
}
void F_167 ( struct V_262 * V_263 )
{
V_263 -> V_34 -> V_179 ( V_263 ) ;
F_14 ( V_263 -> V_34 -> V_33 ) ;
F_35 ( V_263 ) ;
}
void F_168 ( struct V_262 * * V_277 )
{
struct V_262 * V_263 ;
while ( ( V_263 = * V_277 ) != NULL ) {
* V_277 = V_263 -> V_9 ;
F_167 ( V_263 ) ;
}
}
static int F_169 ( struct V_278 * V_212 , void * V_279 )
{
struct V_280 V_281 ;
F_170 ( V_112 , & V_281 ) ;
F_171 ( V_212 , L_6 ,
( T_2 ) V_282 , ( T_2 ) F_172 ( 1 ) ,
1000000 ,
( T_2 ) V_283 / ( T_2 ) F_173 ( F_174 ( V_281 ) ) ) ;
return 0 ;
}
static int F_175 ( struct V_284 * V_284 , struct V_285 * V_285 )
{
return F_176 ( V_285 , F_169 , NULL ) ;
}
static int T_9 F_177 ( struct V_144 * V_144 )
{
struct V_286 * V_287 ;
V_287 = F_178 ( L_7 , 0 , V_144 -> V_288 , & V_289 ) ;
if ( V_287 == NULL )
return - V_90 ;
return 0 ;
}
static void T_10 F_179 ( struct V_144 * V_144 )
{
F_180 ( L_7 , V_144 -> V_288 ) ;
}
static int T_9 F_177 ( struct V_144 * V_144 )
{
return 0 ;
}
static void T_10 F_179 ( struct V_144 * V_144 )
{
}
static int T_11 F_181 ( void )
{
int V_28 ;
V_28 = F_182 ( & V_290 ) ;
if ( V_28 ) {
F_183 ( L_8
L_9 ) ;
return V_28 ;
}
F_1 ( & V_291 ) ;
F_1 ( & V_292 ) ;
F_1 ( & V_293 ) ;
F_1 ( & V_294 ) ;
F_1 ( & V_295 ) ;
F_184 ( V_296 , V_236 , F_127 , NULL , NULL ) ;
F_184 ( V_296 , V_203 , F_122 , NULL , NULL ) ;
F_184 ( V_296 , V_198 , F_122 , F_147 , NULL ) ;
F_184 ( V_296 , V_254 , F_151 , NULL , NULL ) ;
F_184 ( V_296 , V_255 , F_151 , NULL , NULL ) ;
F_184 ( V_296 , V_252 , F_151 , F_157 , NULL ) ;
return 0 ;
}
