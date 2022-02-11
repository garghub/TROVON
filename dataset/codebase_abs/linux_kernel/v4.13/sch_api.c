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
F_20 () ;
F_21 ( F_17 ( V_3 ) -> V_47 , & V_3 -> V_48 , V_3 -> V_40 ) ;
if ( V_43 )
V_3 -> V_41 |= V_49 ;
}
}
void F_22 ( struct V_38 * V_3 )
{
if ( ( V_3 -> V_44 != V_45 ) && ! ( V_3 -> V_41 & V_46 ) ) {
F_20 () ;
F_23 ( & V_3 -> V_48 ) ;
}
}
struct V_38 * F_24 ( struct V_50 * V_51 , T_3 V_40 )
{
struct V_38 * V_3 ;
V_3 = F_16 ( V_51 -> V_52 , V_40 ) ;
if ( V_3 )
goto V_11;
if ( F_25 ( V_51 ) )
V_3 = F_16 (
F_25 ( V_51 ) -> V_53 ,
V_40 ) ;
V_11:
return V_3 ;
}
static struct V_38 * F_26 ( struct V_38 * V_54 , T_3 V_55 )
{
unsigned long V_56 ;
struct V_38 * V_23 ;
const struct V_18 * V_19 = V_54 -> V_34 -> V_17 ;
if ( V_19 == NULL )
return NULL ;
V_56 = V_19 -> V_20 ( V_54 , V_55 ) ;
if ( V_56 == 0 )
return NULL ;
V_23 = V_19 -> V_23 ( V_54 , V_56 ) ;
V_19 -> V_21 ( V_54 , V_56 ) ;
return V_23 ;
}
static struct V_1 * F_27 ( struct V_57 * V_58 )
{
struct V_1 * V_3 = NULL ;
if ( V_58 ) {
F_6 ( & V_7 ) ;
for ( V_3 = V_8 ; V_3 ; V_3 = V_3 -> V_9 ) {
if ( F_28 ( V_58 , V_3 -> V_10 ) == 0 ) {
if ( ! F_10 ( V_3 -> V_33 ) )
V_3 = NULL ;
break;
}
}
F_8 ( & V_7 ) ;
}
return V_3 ;
}
static T_4 F_29 ( struct V_59 * V_60 , T_5 * V_61 )
{
int V_62 = F_30 ( V_60 -> V_63 , 48 ) ;
int V_64 = F_30 ( V_62 + 1 , 48 ) ;
int V_65 = V_62 >> V_60 -> V_66 ;
int V_67 = ( V_64 >> V_60 -> V_66 ) - 1 ;
if ( ( V_60 -> V_68 > ( 100000000 / 8 ) ) || ( V_61 [ 0 ] == 0 ) ) {
F_31 ( L_2 ) ;
return V_69 ;
}
if ( ( V_67 > V_65 ) && ( V_67 < 256 )
&& ( V_61 [ V_65 ] == V_61 [ V_67 ] ) ) {
F_31 ( L_3 ,
V_65 , V_67 , V_61 [ V_67 ] ) ;
return V_70 ;
}
return V_69 ;
}
struct V_71 * F_32 ( struct V_59 * V_60 ,
struct V_57 * V_72 )
{
struct V_71 * V_61 ;
if ( V_72 == NULL || V_60 -> V_68 == 0 || V_60 -> V_66 == 0 ||
F_33 ( V_72 ) != V_73 )
return NULL ;
for ( V_61 = V_74 ; V_61 ; V_61 = V_61 -> V_9 ) {
if ( ! memcmp ( & V_61 -> V_68 , V_60 , sizeof( struct V_59 ) ) &&
! memcmp ( & V_61 -> V_75 , F_34 ( V_72 ) , 1024 ) ) {
V_61 -> V_76 ++ ;
return V_61 ;
}
}
V_61 = F_35 ( sizeof( * V_61 ) , V_77 ) ;
if ( V_61 ) {
V_61 -> V_68 = * V_60 ;
V_61 -> V_76 = 1 ;
memcpy ( V_61 -> V_75 , F_34 ( V_72 ) , 1024 ) ;
if ( V_60 -> V_78 == V_79 )
V_60 -> V_78 = F_29 ( V_60 , V_61 -> V_75 ) ;
V_61 -> V_9 = V_74 ;
V_74 = V_61 ;
}
return V_61 ;
}
void F_36 ( struct V_71 * V_72 )
{
struct V_71 * V_61 , * * V_80 ;
if ( ! V_72 || -- V_72 -> V_76 )
return;
for ( V_80 = & V_74 ;
( V_61 = * V_80 ) != NULL ;
V_80 = & V_61 -> V_9 ) {
if ( V_61 == V_72 ) {
* V_80 = V_61 -> V_9 ;
F_37 ( V_61 ) ;
return;
}
}
}
static struct V_81 * F_38 ( struct V_57 * V_82 )
{
struct V_57 * V_83 [ V_84 + 1 ] ;
struct V_81 * V_85 ;
struct V_86 * V_87 ;
unsigned int V_88 = 0 ;
T_6 * V_72 = NULL ;
int V_28 ;
V_28 = F_39 ( V_83 , V_84 , V_82 , V_89 , NULL ) ;
if ( V_28 < 0 )
return F_40 ( V_28 ) ;
if ( ! V_83 [ V_90 ] )
return F_40 ( - V_27 ) ;
V_87 = F_34 ( V_83 [ V_90 ] ) ;
if ( V_87 -> V_88 > 0 ) {
if ( ! V_83 [ V_91 ] )
return F_40 ( - V_27 ) ;
V_72 = F_34 ( V_83 [ V_91 ] ) ;
V_88 = F_33 ( V_83 [ V_91 ] ) / sizeof( T_6 ) ;
}
if ( V_88 != V_87 -> V_88 || ( ! V_72 && V_88 > 0 ) )
return F_40 ( - V_27 ) ;
F_41 (stab, &qdisc_stab_list, list) {
if ( memcmp ( & V_85 -> V_92 , V_87 , sizeof( * V_87 ) ) )
continue;
if ( V_88 > 0 && memcmp ( V_85 -> V_75 , V_72 , V_88 * sizeof( T_6 ) ) )
continue;
V_85 -> V_76 ++ ;
return V_85 ;
}
V_85 = F_35 ( sizeof( * V_85 ) + V_88 * sizeof( T_6 ) , V_77 ) ;
if ( ! V_85 )
return F_40 ( - V_93 ) ;
V_85 -> V_76 = 1 ;
V_85 -> V_92 = * V_87 ;
if ( V_88 > 0 )
memcpy ( V_85 -> V_75 , V_72 , V_88 * sizeof( T_6 ) ) ;
F_42 ( & V_85 -> V_94 , & V_95 ) ;
return V_85 ;
}
static void F_43 ( struct V_96 * V_97 )
{
F_37 ( F_44 ( V_97 , struct V_81 , V_98 ) ) ;
}
void F_45 ( struct V_81 * V_72 )
{
if ( ! V_72 )
return;
if ( -- V_72 -> V_76 == 0 ) {
F_46 ( & V_72 -> V_94 ) ;
F_47 ( & V_72 -> V_98 , F_43 ) ;
}
}
static int F_48 ( struct V_99 * V_100 , struct V_81 * V_85 )
{
struct V_57 * V_101 ;
V_101 = F_49 ( V_100 , V_102 ) ;
if ( V_101 == NULL )
goto V_103;
if ( F_50 ( V_100 , V_90 , sizeof( V_85 -> V_92 ) , & V_85 -> V_92 ) )
goto V_103;
F_51 ( V_100 , V_101 ) ;
return V_100 -> V_31 ;
V_103:
return - 1 ;
}
void F_52 ( struct V_99 * V_100 ,
const struct V_81 * V_85 )
{
int V_104 , V_105 ;
V_104 = V_100 -> V_31 + V_85 -> V_92 . V_106 ;
if ( F_53 ( ! V_85 -> V_92 . V_88 ) )
goto V_11;
V_105 = V_104 + V_85 -> V_92 . V_107 ;
if ( F_53 ( V_105 < 0 ) )
V_105 = 0 ;
V_105 >>= V_85 -> V_92 . V_66 ;
if ( F_54 ( V_105 < V_85 -> V_92 . V_88 ) )
V_104 = V_85 -> V_75 [ V_105 ] ;
else
V_104 = V_85 -> V_75 [ V_85 -> V_92 . V_88 - 1 ] *
( V_105 / V_85 -> V_92 . V_88 ) +
V_85 -> V_75 [ V_105 % V_85 -> V_92 . V_88 ] ;
V_104 <<= V_85 -> V_92 . V_108 ;
V_11:
if ( F_53 ( V_104 < 1 ) )
V_104 = 1 ;
F_55 ( V_100 ) -> V_104 = V_104 ;
}
void F_56 ( const char * V_109 , struct V_38 * V_52 )
{
if ( ! ( V_52 -> V_41 & V_110 ) ) {
F_57 ( L_4 ,
V_109 , V_52 -> V_34 -> V_10 , V_52 -> V_40 >> 16 ) ;
V_52 -> V_41 |= V_110 ;
}
}
static enum V_111 F_58 ( struct V_112 * V_113 )
{
struct F_58 * V_114 = F_44 ( V_113 , struct F_58 ,
V_113 ) ;
F_59 () ;
F_60 ( F_61 ( V_114 -> V_52 ) ) ;
F_62 () ;
return V_115 ;
}
void F_63 ( struct F_58 * V_114 , struct V_38 * V_52 )
{
F_64 ( & V_114 -> V_113 , V_116 , V_117 ) ;
V_114 -> V_113 . V_118 = F_58 ;
V_114 -> V_52 = V_52 ;
}
void F_65 ( struct F_58 * V_114 , T_7 V_119 )
{
if ( F_66 ( V_120 ,
& F_67 ( V_114 -> V_52 ) -> V_121 ) )
return;
if ( V_114 -> V_122 == V_119 )
return;
V_114 -> V_122 = V_119 ;
F_68 ( & V_114 -> V_113 ,
F_69 ( V_119 ) ,
V_117 ) ;
}
void F_70 ( struct F_58 * V_114 )
{
F_71 ( & V_114 -> V_113 ) ;
}
static struct V_123 * F_72 ( unsigned int V_124 )
{
unsigned int V_125 = V_124 * sizeof( struct V_123 ) , V_126 ;
struct V_123 * V_127 ;
if ( V_125 <= V_128 )
V_127 = F_35 ( V_125 , V_77 ) ;
else
V_127 = (struct V_123 * )
F_73 ( V_77 , F_74 ( V_125 ) ) ;
if ( V_127 != NULL ) {
for ( V_126 = 0 ; V_126 < V_124 ; V_126 ++ )
F_75 ( & V_127 [ V_126 ] ) ;
}
return V_127 ;
}
static void F_76 ( struct V_123 * V_127 , unsigned int V_124 )
{
unsigned int V_125 = V_124 * sizeof( struct V_123 ) ;
if ( V_125 <= V_128 )
F_37 ( V_127 ) ;
else
F_77 ( ( unsigned long ) V_127 , F_74 ( V_125 ) ) ;
}
void F_78 ( struct V_38 * V_129 , struct V_130 * V_131 )
{
struct V_132 * V_56 ;
struct V_133 * V_9 ;
struct V_123 * V_134 , * V_135 ;
unsigned int V_136 , V_137 , V_138 ;
unsigned int V_126 , V_127 ;
if ( V_131 -> V_139 * 4 <= V_131 -> V_140 * 3 )
return;
V_136 = V_131 -> V_140 * 2 ;
V_137 = V_136 - 1 ;
V_134 = F_72 ( V_136 ) ;
if ( V_134 == NULL )
return;
V_135 = V_131 -> V_48 ;
V_138 = V_131 -> V_140 ;
F_79 ( V_129 ) ;
for ( V_126 = 0 ; V_126 < V_138 ; V_126 ++ ) {
F_80 (cl, next, &ohash[i], hnode) {
V_127 = F_81 ( V_56 -> V_55 , V_137 ) ;
F_82 ( & V_56 -> V_141 , & V_134 [ V_127 ] ) ;
}
}
V_131 -> V_48 = V_134 ;
V_131 -> V_140 = V_136 ;
V_131 -> V_142 = V_137 ;
F_83 ( V_129 ) ;
F_76 ( V_135 , V_138 ) ;
}
int F_84 ( struct V_130 * V_131 )
{
unsigned int V_125 = 4 ;
V_131 -> V_48 = F_72 ( V_125 ) ;
if ( V_131 -> V_48 == NULL )
return - V_93 ;
V_131 -> V_140 = V_125 ;
V_131 -> V_142 = V_125 - 1 ;
V_131 -> V_139 = 0 ;
return 0 ;
}
void F_85 ( struct V_130 * V_131 )
{
F_76 ( V_131 -> V_48 , V_131 -> V_140 ) ;
}
void F_86 ( struct V_130 * V_131 ,
struct V_132 * V_56 )
{
unsigned int V_127 ;
F_87 ( & V_56 -> V_141 ) ;
V_127 = F_81 ( V_56 -> V_55 , V_131 -> V_142 ) ;
F_82 ( & V_56 -> V_141 , & V_131 -> V_48 [ V_127 ] ) ;
V_131 -> V_139 ++ ;
}
void F_88 ( struct V_130 * V_131 ,
struct V_132 * V_56 )
{
F_89 ( & V_56 -> V_141 ) ;
V_131 -> V_139 -- ;
}
static T_3 F_90 ( struct V_50 * V_51 )
{
int V_126 = 0x8000 ;
static T_3 V_143 = F_91 ( 0x80000000U , 0 ) ;
do {
V_143 += F_91 ( 0x10000U , 0 ) ;
if ( V_143 == F_91 ( V_45 , 0 ) )
V_143 = F_91 ( 0x80000000U , 0 ) ;
if ( ! F_24 ( V_51 , V_143 ) )
return V_143 ;
F_92 () ;
} while ( -- V_126 > 0 );
return 0 ;
}
void F_93 ( struct V_38 * V_129 , unsigned int V_124 ,
unsigned int V_31 )
{
const struct V_18 * V_19 ;
unsigned long V_56 ;
T_3 V_144 ;
int V_145 ;
if ( V_124 == 0 && V_31 == 0 )
return;
V_145 = F_94 ( int , V_124 , 0 ) ;
F_59 () ;
while ( ( V_144 = V_129 -> V_44 ) ) {
if ( F_95 ( V_144 ) == F_95 ( V_146 ) )
break;
if ( V_129 -> V_41 & V_147 )
break;
V_129 = F_24 ( F_17 ( V_129 ) , F_95 ( V_144 ) ) ;
if ( V_129 == NULL ) {
F_96 ( V_144 != V_45 ) ;
break;
}
V_19 = V_129 -> V_34 -> V_17 ;
if ( V_19 -> V_148 ) {
V_56 = V_19 -> V_20 ( V_129 , V_144 ) ;
V_19 -> V_148 ( V_129 , V_56 ) ;
V_19 -> V_21 ( V_129 , V_56 ) ;
}
V_129 -> V_3 . V_149 -= V_124 ;
V_129 -> V_150 . V_151 -= V_31 ;
F_97 ( V_129 , V_145 ) ;
}
F_62 () ;
}
static void F_98 ( struct V_152 * V_152 , struct V_99 * V_100 ,
struct V_153 * V_124 , T_3 V_154 ,
struct V_38 * V_155 , struct V_38 * V_156 )
{
if ( V_156 || V_155 )
F_99 ( V_152 , V_100 , V_124 , V_154 , V_155 , V_156 ) ;
if ( V_155 )
F_100 ( V_155 ) ;
}
static int F_101 ( struct V_50 * V_51 , struct V_38 * V_44 ,
struct V_99 * V_100 , struct V_153 * V_124 , T_3 V_55 ,
struct V_38 * V_156 , struct V_38 * V_155 )
{
struct V_38 * V_3 = V_155 ;
struct V_152 * V_152 = F_102 ( V_51 ) ;
int V_28 = 0 ;
if ( V_44 == NULL ) {
unsigned int V_126 , V_157 , V_158 ;
V_158 = 0 ;
V_157 = V_51 -> V_159 ;
if ( ( V_3 && V_3 -> V_41 & V_46 ) ||
( V_156 && V_156 -> V_41 & V_46 ) ) {
V_157 = 1 ;
V_158 = 1 ;
if ( ! F_25 ( V_51 ) )
return - V_29 ;
}
if ( V_51 -> V_41 & V_160 )
F_103 ( V_51 ) ;
if ( V_156 && V_156 -> V_34 -> V_161 )
goto V_162;
for ( V_126 = 0 ; V_126 < V_157 ; V_126 ++ ) {
struct V_163 * V_164 = F_25 ( V_51 ) ;
if ( ! V_158 )
V_164 = F_104 ( V_51 , V_126 ) ;
V_155 = F_105 ( V_164 , V_156 ) ;
if ( V_156 && V_126 > 0 )
F_106 ( V_156 ) ;
if ( ! V_158 )
F_100 ( V_155 ) ;
}
V_162:
if ( ! V_158 ) {
F_98 ( V_152 , V_100 , V_124 , V_55 ,
V_51 -> V_52 , V_156 ) ;
if ( V_156 && ! V_156 -> V_34 -> V_161 )
F_106 ( V_156 ) ;
V_51 -> V_52 = V_156 ? : & V_165 ;
if ( V_156 && V_156 -> V_34 -> V_161 )
V_156 -> V_34 -> V_161 ( V_156 ) ;
} else {
F_98 ( V_152 , V_100 , V_124 , V_55 , V_155 , V_156 ) ;
}
if ( V_51 -> V_41 & V_160 )
F_107 ( V_51 ) ;
} else {
const struct V_18 * V_19 = V_44 -> V_34 -> V_17 ;
V_28 = - V_166 ;
if ( V_19 && V_19 -> V_167 ) {
unsigned long V_56 = V_19 -> V_20 ( V_44 , V_55 ) ;
if ( V_56 ) {
V_28 = V_19 -> V_167 ( V_44 , V_56 , V_156 , & V_155 ) ;
V_19 -> V_21 ( V_44 , V_56 ) ;
} else
V_28 = - V_29 ;
}
if ( ! V_28 )
F_98 ( V_152 , V_100 , V_124 , V_55 , V_155 , V_156 ) ;
}
return V_28 ;
}
static struct V_38 * F_108 ( struct V_50 * V_51 ,
struct V_163 * V_164 ,
struct V_38 * V_54 , T_3 V_44 , T_3 V_40 ,
struct V_57 * * V_168 , int * V_169 )
{
int V_28 ;
struct V_57 * V_58 = V_168 [ V_170 ] ;
struct V_38 * V_129 ;
struct V_1 * V_34 ;
struct V_81 * V_85 ;
V_34 = F_27 ( V_58 ) ;
#ifdef F_109
if ( V_34 == NULL && V_58 != NULL ) {
char V_30 [ V_171 ] ;
if ( F_110 ( V_30 , V_58 , V_171 ) < V_171 ) {
F_111 () ;
F_13 ( L_1 , V_30 ) ;
F_112 () ;
V_34 = F_27 ( V_58 ) ;
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
V_129 = F_113 ( V_164 , V_34 ) ;
if ( F_114 ( V_129 ) ) {
V_28 = F_115 ( V_129 ) ;
goto V_174;
}
V_129 -> V_44 = V_44 ;
if ( V_40 == V_146 ) {
V_129 -> V_41 |= V_46 ;
V_40 = F_91 ( V_146 , 0 ) ;
F_116 ( F_117 ( V_129 ) , & V_175 ) ;
} else {
if ( V_40 == 0 ) {
V_40 = F_90 ( V_51 ) ;
V_28 = - V_93 ;
if ( V_40 == 0 )
goto V_176;
}
F_116 ( F_117 ( V_129 ) , & V_177 ) ;
if ( ! F_118 ( V_51 ) )
V_129 -> V_41 |= V_178 ;
}
V_129 -> V_40 = V_40 ;
if ( ( V_51 -> V_179 & V_180 ) && ( V_51 -> V_181 == 0 ) ) {
V_51 -> V_181 = V_182 ;
F_119 ( V_51 , L_5 ) ;
}
if ( ! V_34 -> V_183 || ( V_28 = V_34 -> V_183 ( V_129 , V_168 [ V_184 ] ) ) == 0 ) {
if ( F_120 ( V_129 ) ) {
V_129 -> V_185 =
F_121 ( struct V_186 ) ;
if ( ! V_129 -> V_185 )
goto V_187;
V_129 -> V_188 = F_122 ( struct V_189 ) ;
if ( ! V_129 -> V_188 )
goto V_187;
}
if ( V_168 [ V_102 ] ) {
V_85 = F_38 ( V_168 [ V_102 ] ) ;
if ( F_114 ( V_85 ) ) {
V_28 = F_115 ( V_85 ) ;
goto V_187;
}
F_123 ( V_129 -> V_85 , V_85 ) ;
}
if ( V_168 [ V_190 ] ) {
T_8 * V_191 ;
V_28 = - V_166 ;
if ( V_129 -> V_41 & V_192 )
goto V_187;
if ( ( V_129 -> V_44 != V_45 ) &&
! ( V_129 -> V_41 & V_46 ) &&
( ! V_54 || ! ( V_54 -> V_41 & V_192 ) ) )
V_191 = F_124 ( V_129 ) ;
else
V_191 = & V_129 -> V_191 ;
V_28 = F_125 ( & V_129 -> V_193 ,
V_129 -> V_185 ,
& V_129 -> V_194 ,
NULL ,
V_191 ,
V_168 [ V_190 ] ) ;
if ( V_28 )
goto V_187;
}
F_19 ( V_129 , false ) ;
return V_129 ;
}
if ( V_34 -> V_195 )
V_34 -> V_195 ( V_129 ) ;
V_176:
F_126 ( V_51 ) ;
F_37 ( ( char * ) V_129 - V_129 -> V_196 ) ;
V_174:
F_14 ( V_34 -> V_33 ) ;
V_173:
* V_169 = V_28 ;
return NULL ;
V_187:
F_127 ( V_129 -> V_185 ) ;
F_127 ( V_129 -> V_188 ) ;
F_45 ( F_128 ( V_129 -> V_85 ) ) ;
if ( V_34 -> V_195 )
V_34 -> V_195 ( V_129 ) ;
goto V_176;
}
static int F_129 ( struct V_38 * V_129 , struct V_57 * * V_168 )
{
struct V_81 * V_197 , * V_85 = NULL ;
int V_28 = 0 ;
if ( V_168 [ V_184 ] ) {
if ( V_129 -> V_34 -> V_198 == NULL )
return - V_27 ;
V_28 = V_129 -> V_34 -> V_198 ( V_129 , V_168 [ V_184 ] ) ;
if ( V_28 )
return V_28 ;
}
if ( V_168 [ V_102 ] ) {
V_85 = F_38 ( V_168 [ V_102 ] ) ;
if ( F_114 ( V_85 ) )
return F_115 ( V_85 ) ;
}
V_197 = F_128 ( V_129 -> V_85 ) ;
F_123 ( V_129 -> V_85 , V_85 ) ;
F_45 ( V_197 ) ;
if ( V_168 [ V_190 ] ) {
if ( V_129 -> V_41 & V_192 )
goto V_11;
F_130 ( & V_129 -> V_193 ,
V_129 -> V_185 ,
& V_129 -> V_194 ,
NULL ,
F_124 ( V_129 ) ,
V_168 [ V_190 ] ) ;
}
V_11:
return 0 ;
}
static int F_131 ( struct V_38 * V_3 , struct V_38 * V_54 , int V_199 )
{
struct V_200 V_201 ;
if ( V_3 -> V_34 -> V_17 == NULL )
return 0 ;
V_201 . V_202 . V_203 = V_201 . V_202 . V_162 = V_201 . V_202 . V_204 = 0 ;
V_201 . V_202 . V_205 = V_206 ;
V_201 . V_199 = V_199 ;
V_201 . V_54 = V_54 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_201 . V_202 ) ;
return V_201 . V_202 . V_203 ? - V_207 : 0 ;
}
static int
V_206 ( struct V_38 * V_3 , unsigned long V_56 , struct V_208 * V_202 )
{
struct V_38 * V_23 ;
const struct V_18 * V_19 = V_3 -> V_34 -> V_17 ;
struct V_200 * V_201 = (struct V_200 * ) V_202 ;
V_23 = V_19 -> V_23 ( V_3 , V_56 ) ;
if ( V_23 ) {
if ( V_23 == V_201 -> V_54 || V_201 -> V_199 > 7 )
return - V_207 ;
return F_131 ( V_23 , V_201 -> V_54 , V_201 -> V_199 + 1 ) ;
}
return 0 ;
}
static int F_132 ( struct V_99 * V_100 , struct V_153 * V_124 ,
struct V_209 * V_210 )
{
struct V_152 * V_152 = F_133 ( V_100 -> V_211 ) ;
struct V_212 * V_213 = F_134 ( V_124 ) ;
struct V_57 * V_168 [ V_214 + 1 ] ;
struct V_50 * V_51 ;
T_3 V_154 ;
struct V_38 * V_3 = NULL ;
struct V_38 * V_54 = NULL ;
int V_28 ;
if ( ( V_124 -> V_215 != V_216 ) &&
! F_135 ( V_100 , V_152 -> V_217 , V_35 ) )
return - V_36 ;
V_28 = F_136 ( V_124 , sizeof( * V_213 ) , V_168 , V_214 , NULL , V_210 ) ;
if ( V_28 < 0 )
return V_28 ;
V_51 = F_137 ( V_152 , V_213 -> V_218 ) ;
if ( ! V_51 )
return - V_219 ;
V_154 = V_213 -> V_220 ;
if ( V_154 ) {
if ( V_154 != V_45 ) {
if ( F_95 ( V_154 ) != F_95 ( V_146 ) ) {
V_54 = F_24 ( V_51 , F_95 ( V_154 ) ) ;
if ( ! V_54 )
return - V_29 ;
V_3 = F_26 ( V_54 , V_154 ) ;
} else if ( F_25 ( V_51 ) ) {
V_3 = F_25 ( V_51 ) -> V_53 ;
}
} else {
V_3 = V_51 -> V_52 ;
}
if ( ! V_3 )
return - V_29 ;
if ( V_213 -> V_221 && V_3 -> V_40 != V_213 -> V_221 )
return - V_27 ;
} else {
V_3 = F_24 ( V_51 , V_213 -> V_221 ) ;
if ( ! V_3 )
return - V_29 ;
}
if ( V_168 [ V_170 ] && F_28 ( V_168 [ V_170 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_124 -> V_215 == V_222 ) {
if ( ! V_154 )
return - V_27 ;
if ( V_3 -> V_40 == 0 )
return - V_29 ;
V_28 = F_101 ( V_51 , V_54 , V_100 , V_124 , V_154 , NULL , V_3 ) ;
if ( V_28 != 0 )
return V_28 ;
} else {
F_99 ( V_152 , V_100 , V_124 , V_154 , NULL , V_3 ) ;
}
return 0 ;
}
static int F_138 ( struct V_99 * V_100 , struct V_153 * V_124 ,
struct V_209 * V_210 )
{
struct V_152 * V_152 = F_133 ( V_100 -> V_211 ) ;
struct V_212 * V_213 ;
struct V_57 * V_168 [ V_214 + 1 ] ;
struct V_50 * V_51 ;
T_3 V_154 ;
struct V_38 * V_3 , * V_54 ;
int V_28 ;
if ( ! F_135 ( V_100 , V_152 -> V_217 , V_35 ) )
return - V_36 ;
V_223:
V_28 = F_136 ( V_124 , sizeof( * V_213 ) , V_168 , V_214 , NULL , V_210 ) ;
if ( V_28 < 0 )
return V_28 ;
V_213 = F_134 ( V_124 ) ;
V_154 = V_213 -> V_220 ;
V_3 = V_54 = NULL ;
V_51 = F_137 ( V_152 , V_213 -> V_218 ) ;
if ( ! V_51 )
return - V_219 ;
if ( V_154 ) {
if ( V_154 != V_45 ) {
if ( V_154 != V_146 ) {
V_54 = F_24 ( V_51 , F_95 ( V_154 ) ) ;
if ( ! V_54 )
return - V_29 ;
V_3 = F_26 ( V_54 , V_154 ) ;
} else if ( F_139 ( V_51 ) ) {
V_3 = F_25 ( V_51 ) -> V_53 ;
}
} else {
V_3 = V_51 -> V_52 ;
}
if ( V_3 && V_3 -> V_40 == 0 )
V_3 = NULL ;
if ( ! V_3 || ! V_213 -> V_221 || V_3 -> V_40 != V_213 -> V_221 ) {
if ( V_213 -> V_221 ) {
if ( V_3 && ! ( V_124 -> V_224 & V_225 ) )
return - V_6 ;
if ( F_140 ( V_213 -> V_221 ) )
return - V_27 ;
V_3 = F_24 ( V_51 , V_213 -> V_221 ) ;
if ( ! V_3 )
goto V_226;
if ( V_124 -> V_224 & V_227 )
return - V_6 ;
if ( V_168 [ V_170 ] && F_28 ( V_168 [ V_170 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
if ( V_3 == V_54 ||
( V_54 && F_131 ( V_3 , V_54 , 0 ) ) )
return - V_207 ;
F_106 ( V_3 ) ;
goto V_167;
} else {
if ( ! V_3 )
goto V_226;
if ( ( V_124 -> V_224 & V_228 ) &&
( V_124 -> V_224 & V_225 ) &&
( ( V_124 -> V_224 & V_227 ) ||
( V_168 [ V_170 ] &&
F_28 ( V_168 [ V_170 ] , V_3 -> V_34 -> V_10 ) ) ) )
goto V_226;
}
}
} else {
if ( ! V_213 -> V_221 )
return - V_27 ;
V_3 = F_24 ( V_51 , V_213 -> V_221 ) ;
}
if ( V_3 == NULL )
return - V_29 ;
if ( V_124 -> V_224 & V_227 )
return - V_6 ;
if ( V_168 [ V_170 ] && F_28 ( V_168 [ V_170 ] , V_3 -> V_34 -> V_10 ) )
return - V_27 ;
V_28 = F_129 ( V_3 , V_168 ) ;
if ( V_28 == 0 )
F_99 ( V_152 , V_100 , V_124 , V_154 , NULL , V_3 ) ;
return V_28 ;
V_226:
if ( ! ( V_124 -> V_224 & V_228 ) )
return - V_29 ;
if ( V_154 == V_146 ) {
if ( F_25 ( V_51 ) )
V_3 = F_108 ( V_51 , F_25 ( V_51 ) , V_54 ,
V_213 -> V_220 , V_213 -> V_220 ,
V_168 , & V_28 ) ;
else
V_28 = - V_29 ;
} else {
struct V_163 * V_164 ;
if ( V_54 && V_54 -> V_34 -> V_17 && V_54 -> V_34 -> V_17 -> V_229 )
V_164 = V_54 -> V_34 -> V_17 -> V_229 ( V_54 , V_213 ) ;
else if ( V_54 )
V_164 = V_54 -> V_164 ;
else
V_164 = F_104 ( V_51 , 0 ) ;
V_3 = F_108 ( V_51 , V_164 , V_54 ,
V_213 -> V_220 , V_213 -> V_221 ,
V_168 , & V_28 ) ;
}
if ( V_3 == NULL ) {
if ( V_28 == - V_172 )
goto V_223;
return V_28 ;
}
V_167:
V_28 = F_101 ( V_51 , V_54 , V_100 , V_124 , V_154 , V_3 , NULL ) ;
if ( V_28 ) {
if ( V_3 )
F_100 ( V_3 ) ;
return V_28 ;
}
return 0 ;
}
static int F_141 ( struct V_99 * V_100 , struct V_38 * V_3 , T_3 V_154 ,
T_3 V_230 , T_3 V_231 , T_6 V_41 , int V_232 )
{
struct V_186 T_9 * V_185 = NULL ;
struct V_189 T_9 * V_188 = NULL ;
struct V_212 * V_213 ;
struct V_153 * V_233 ;
unsigned char * V_234 = F_142 ( V_100 ) ;
struct V_235 V_236 ;
struct V_81 * V_85 ;
T_5 V_149 ;
F_92 () ;
V_233 = F_143 ( V_100 , V_230 , V_231 , V_232 , sizeof( * V_213 ) , V_41 ) ;
if ( ! V_233 )
goto V_237;
V_213 = F_134 ( V_233 ) ;
V_213 -> V_238 = V_239 ;
V_213 -> V_240 = 0 ;
V_213 -> V_241 = 0 ;
V_213 -> V_218 = F_17 ( V_3 ) -> V_242 ;
V_213 -> V_220 = V_154 ;
V_213 -> V_221 = V_3 -> V_40 ;
V_213 -> V_243 = F_144 ( & V_3 -> V_76 ) ;
if ( F_145 ( V_100 , V_170 , V_3 -> V_34 -> V_10 ) )
goto V_103;
if ( V_3 -> V_34 -> V_244 && V_3 -> V_34 -> V_244 ( V_3 , V_100 ) < 0 )
goto V_103;
V_149 = V_3 -> V_3 . V_149 ;
V_85 = F_128 ( V_3 -> V_85 ) ;
if ( V_85 && F_48 ( V_100 , V_85 ) < 0 )
goto V_103;
if ( F_146 ( V_100 , V_245 , V_246 , V_247 ,
NULL , & V_236 , V_248 ) < 0 )
goto V_103;
if ( V_3 -> V_34 -> V_249 && V_3 -> V_34 -> V_249 ( V_3 , & V_236 ) < 0 )
goto V_103;
if ( F_120 ( V_3 ) ) {
V_185 = V_3 -> V_185 ;
V_188 = V_3 -> V_188 ;
}
if ( F_147 ( F_124 ( V_3 ) ,
& V_236 , V_185 , & V_3 -> V_193 ) < 0 ||
F_148 ( & V_236 , & V_3 -> V_194 ) < 0 ||
F_149 ( & V_236 , V_188 , & V_3 -> V_150 , V_149 ) < 0 )
goto V_103;
if ( F_150 ( & V_236 ) < 0 )
goto V_103;
V_233 -> V_250 = F_142 ( V_100 ) - V_234 ;
return V_100 -> V_31 ;
V_237:
V_103:
F_151 ( V_100 , V_234 ) ;
return - 1 ;
}
static bool F_152 ( struct V_38 * V_3 , bool V_251 )
{
if ( V_3 -> V_41 & V_42 )
return true ;
if ( ( V_3 -> V_41 & V_49 ) && ! V_251 )
return true ;
return false ;
}
static int F_99 ( struct V_152 * V_152 , struct V_99 * V_252 ,
struct V_153 * V_124 , T_3 V_154 ,
struct V_38 * V_155 , struct V_38 * V_156 )
{
struct V_99 * V_100 ;
T_3 V_230 = V_252 ? F_153 ( V_252 ) . V_230 : 0 ;
V_100 = F_154 ( V_253 , V_77 ) ;
if ( ! V_100 )
return - V_254 ;
if ( V_155 && ! F_152 ( V_155 , false ) ) {
if ( F_141 ( V_100 , V_155 , V_154 , V_230 , V_124 -> V_255 ,
0 , V_222 ) < 0 )
goto V_173;
}
if ( V_156 && ! F_152 ( V_156 , false ) ) {
if ( F_141 ( V_100 , V_156 , V_154 , V_230 , V_124 -> V_255 ,
V_155 ? V_225 : 0 , V_256 ) < 0 )
goto V_173;
}
if ( V_100 -> V_31 )
return F_155 ( V_100 , V_152 , V_230 , V_257 ,
V_124 -> V_224 & V_258 ) ;
V_173:
F_156 ( V_100 ) ;
return - V_27 ;
}
static int F_157 ( struct V_38 * V_39 , struct V_99 * V_100 ,
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
F_141 ( V_100 , V_3 , V_3 -> V_44 , F_153 ( V_260 -> V_100 ) . V_230 ,
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
F_141 ( V_100 , V_3 , V_3 -> V_44 , F_153 ( V_260 -> V_100 ) . V_230 ,
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
static int F_159 ( struct V_99 * V_100 , struct V_259 * V_260 )
{
struct V_152 * V_152 = F_133 ( V_100 -> V_211 ) ;
int V_268 , V_265 ;
int V_269 , V_262 ;
struct V_50 * V_51 ;
const struct V_153 * V_233 = V_260 -> V_233 ;
struct V_212 * V_213 = F_134 ( V_233 ) ;
struct V_57 * V_168 [ V_214 + 1 ] ;
int V_28 ;
V_269 = V_260 -> args [ 0 ] ;
V_262 = V_265 = V_260 -> args [ 1 ] ;
V_268 = 0 ;
F_20 () ;
V_28 = F_136 ( V_233 , sizeof( * V_213 ) , V_168 , V_214 , NULL , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
F_160 (net, dev) {
struct V_163 * V_164 ;
if ( V_268 < V_269 )
goto V_270;
if ( V_268 > V_269 )
V_262 = 0 ;
V_265 = 0 ;
if ( F_157 ( V_51 -> V_52 , V_100 , V_260 , & V_265 , V_262 ,
true , V_168 [ V_271 ] ) < 0 )
goto V_267;
V_164 = F_25 ( V_51 ) ;
if ( V_164 &&
F_157 ( V_164 -> V_53 , V_100 , V_260 ,
& V_265 , V_262 , false ,
V_168 [ V_271 ] ) < 0 )
goto V_267;
V_270:
V_268 ++ ;
}
V_267:
V_260 -> args [ 0 ] = V_268 ;
V_260 -> args [ 1 ] = V_265 ;
return V_100 -> V_31 ;
}
static int F_161 ( struct V_99 * V_100 , struct V_153 * V_124 ,
struct V_209 * V_210 )
{
struct V_152 * V_152 = F_133 ( V_100 -> V_211 ) ;
struct V_212 * V_213 = F_134 ( V_124 ) ;
struct V_57 * V_168 [ V_214 + 1 ] ;
struct V_50 * V_51 ;
struct V_38 * V_3 = NULL ;
const struct V_18 * V_19 ;
unsigned long V_56 = 0 ;
unsigned long V_272 ;
T_3 V_230 ;
T_3 V_154 ;
T_3 V_273 ;
int V_28 ;
if ( ( V_124 -> V_215 != V_274 ) &&
! F_135 ( V_100 , V_152 -> V_217 , V_35 ) )
return - V_36 ;
V_28 = F_136 ( V_124 , sizeof( * V_213 ) , V_168 , V_214 , NULL , V_210 ) ;
if ( V_28 < 0 )
return V_28 ;
V_51 = F_137 ( V_152 , V_213 -> V_218 ) ;
if ( ! V_51 )
return - V_219 ;
V_230 = V_213 -> V_220 ;
V_154 = V_213 -> V_221 ;
V_273 = F_95 ( V_154 ) ;
if ( V_230 != V_45 ) {
T_3 V_275 = F_95 ( V_230 ) ;
if ( V_273 && V_275 ) {
if ( V_273 != V_275 )
return - V_27 ;
} else if ( V_275 ) {
V_273 = V_275 ;
} else if ( V_273 == 0 )
V_273 = V_51 -> V_52 -> V_40 ;
if ( V_230 )
V_230 = F_91 ( V_273 , V_230 ) ;
} else {
if ( V_273 == 0 )
V_273 = V_51 -> V_52 -> V_40 ;
}
V_3 = F_24 ( V_51 , V_273 ) ;
if ( ! V_3 )
return - V_29 ;
V_19 = V_3 -> V_34 -> V_17 ;
if ( V_19 == NULL )
return - V_27 ;
if ( V_154 == 0 ) {
if ( V_230 == V_45 )
V_154 = V_273 ;
} else
V_154 = F_91 ( V_273 , V_154 ) ;
if ( V_154 )
V_56 = V_19 -> V_20 ( V_3 , V_154 ) ;
if ( V_56 == 0 ) {
V_28 = - V_29 ;
if ( V_124 -> V_215 != V_276 ||
! ( V_124 -> V_224 & V_228 ) )
goto V_11;
} else {
switch ( V_124 -> V_215 ) {
case V_276 :
V_28 = - V_6 ;
if ( V_124 -> V_224 & V_227 )
goto V_11;
break;
case V_277 :
V_28 = - V_166 ;
if ( V_19 -> V_278 )
V_28 = V_19 -> V_278 ( V_3 , V_56 ) ;
if ( V_28 == 0 )
F_162 ( V_152 , V_100 , V_124 , V_3 , V_56 ,
V_277 ) ;
goto V_11;
case V_274 :
V_28 = F_162 ( V_152 , V_100 , V_124 , V_3 , V_56 , V_276 ) ;
goto V_11;
default:
V_28 = - V_27 ;
goto V_11;
}
}
V_272 = V_56 ;
V_28 = - V_166 ;
if ( V_19 -> V_198 )
V_28 = V_19 -> V_198 ( V_3 , V_154 , V_230 , V_168 , & V_272 ) ;
if ( V_28 == 0 )
F_162 ( V_152 , V_100 , V_124 , V_3 , V_272 , V_276 ) ;
V_11:
if ( V_56 )
V_19 -> V_21 ( V_3 , V_56 ) ;
return V_28 ;
}
static int F_163 ( struct V_99 * V_100 , struct V_38 * V_3 ,
unsigned long V_56 ,
T_3 V_230 , T_3 V_231 , T_6 V_41 , int V_232 )
{
struct V_212 * V_213 ;
struct V_153 * V_233 ;
unsigned char * V_234 = F_142 ( V_100 ) ;
struct V_235 V_236 ;
const struct V_18 * V_17 = V_3 -> V_34 -> V_17 ;
F_92 () ;
V_233 = F_143 ( V_100 , V_230 , V_231 , V_232 , sizeof( * V_213 ) , V_41 ) ;
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
if ( F_145 ( V_100 , V_170 , V_3 -> V_34 -> V_10 ) )
goto V_103;
if ( V_17 -> V_244 && V_17 -> V_244 ( V_3 , V_56 , V_100 , V_213 ) < 0 )
goto V_103;
if ( F_146 ( V_100 , V_245 , V_246 , V_247 ,
NULL , & V_236 , V_248 ) < 0 )
goto V_103;
if ( V_17 -> V_249 && V_17 -> V_249 ( V_3 , V_56 , & V_236 ) < 0 )
goto V_103;
if ( F_150 ( & V_236 ) < 0 )
goto V_103;
V_233 -> V_250 = F_142 ( V_100 ) - V_234 ;
return V_100 -> V_31 ;
V_237:
V_103:
F_151 ( V_100 , V_234 ) ;
return - 1 ;
}
static int F_162 ( struct V_152 * V_152 , struct V_99 * V_252 ,
struct V_153 * V_124 , struct V_38 * V_3 ,
unsigned long V_56 , int V_232 )
{
struct V_99 * V_100 ;
T_3 V_230 = V_252 ? F_153 ( V_252 ) . V_230 : 0 ;
V_100 = F_154 ( V_253 , V_77 ) ;
if ( ! V_100 )
return - V_254 ;
if ( F_163 ( V_100 , V_3 , V_56 , V_230 , V_124 -> V_255 , 0 , V_232 ) < 0 ) {
F_156 ( V_100 ) ;
return - V_27 ;
}
return F_155 ( V_100 , V_152 , V_230 , V_257 ,
V_124 -> V_224 & V_258 ) ;
}
static int F_164 ( struct V_38 * V_3 , unsigned long V_56 ,
struct V_208 * V_201 )
{
struct V_279 * V_280 = (struct V_279 * ) V_201 ;
return F_163 ( V_280 -> V_100 , V_3 , V_56 , F_153 ( V_280 -> V_260 -> V_100 ) . V_230 ,
V_280 -> V_260 -> V_233 -> V_255 , V_266 ,
V_276 ) ;
}
static int F_165 ( struct V_38 * V_3 , struct V_99 * V_100 ,
struct V_212 * V_213 , struct V_259 * V_260 ,
int * V_281 , int V_282 )
{
struct V_279 V_201 ;
if ( F_152 ( V_3 , false ) ||
* V_281 < V_282 || ! V_3 -> V_34 -> V_17 ||
( V_213 -> V_220 &&
F_95 ( V_213 -> V_220 ) != V_3 -> V_40 ) ) {
( * V_281 ) ++ ;
return 0 ;
}
if ( * V_281 > V_282 )
memset ( & V_260 -> args [ 1 ] , 0 , sizeof( V_260 -> args ) - sizeof( V_260 -> args [ 0 ] ) ) ;
V_201 . V_202 . V_205 = F_164 ;
V_201 . V_100 = V_100 ;
V_201 . V_260 = V_260 ;
V_201 . V_202 . V_203 = 0 ;
V_201 . V_202 . V_162 = V_260 -> args [ 1 ] ;
V_201 . V_202 . V_204 = 0 ;
V_3 -> V_34 -> V_17 -> V_22 ( V_3 , & V_201 . V_202 ) ;
V_260 -> args [ 1 ] = V_201 . V_202 . V_204 ;
if ( V_201 . V_202 . V_203 )
return - 1 ;
( * V_281 ) ++ ;
return 0 ;
}
static int F_166 ( struct V_38 * V_39 , struct V_99 * V_100 ,
struct V_212 * V_213 , struct V_259 * V_260 ,
int * V_281 , int V_282 )
{
struct V_38 * V_3 ;
int V_234 ;
if ( ! V_39 )
return 0 ;
if ( F_165 ( V_39 , V_100 , V_213 , V_260 , V_281 , V_282 ) < 0 )
return - 1 ;
if ( ! F_17 ( V_39 ) )
return 0 ;
if ( V_213 -> V_220 ) {
V_3 = F_16 ( V_39 , F_95 ( V_213 -> V_220 ) ) ;
if ( V_3 && F_165 ( V_3 , V_100 , V_213 , V_260 , V_281 , V_282 ) < 0 )
return - 1 ;
return 0 ;
}
F_158 (qdisc_dev(root)->qdisc_hash, b, q, hash) {
if ( F_165 ( V_3 , V_100 , V_213 , V_260 , V_281 , V_282 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_167 ( struct V_99 * V_100 , struct V_259 * V_260 )
{
struct V_212 * V_213 = F_134 ( V_260 -> V_233 ) ;
struct V_152 * V_152 = F_133 ( V_100 -> V_211 ) ;
struct V_163 * V_164 ;
struct V_50 * V_51 ;
int V_283 , V_282 ;
if ( V_250 ( V_260 -> V_233 ) < sizeof( * V_213 ) )
return 0 ;
V_51 = F_168 ( V_152 , V_213 -> V_218 ) ;
if ( ! V_51 )
return 0 ;
V_282 = V_260 -> args [ 0 ] ;
V_283 = 0 ;
if ( F_166 ( V_51 -> V_52 , V_100 , V_213 , V_260 , & V_283 , V_282 ) < 0 )
goto V_267;
V_164 = F_25 ( V_51 ) ;
if ( V_164 &&
F_166 ( V_164 -> V_53 , V_100 , V_213 , V_260 ,
& V_283 , V_282 ) < 0 )
goto V_267;
V_267:
V_260 -> args [ 0 ] = V_283 ;
F_126 ( V_51 ) ;
return V_100 -> V_31 ;
}
static int F_169 ( struct V_284 * V_231 , void * V_285 )
{
F_170 ( V_231 , L_6 ,
( T_3 ) V_286 , ( T_3 ) F_171 ( 1 ) ,
1000000 ,
( T_3 ) V_287 / V_288 ) ;
return 0 ;
}
static int F_172 ( struct V_289 * V_289 , struct V_290 * V_290 )
{
return F_173 ( V_290 , F_169 , NULL ) ;
}
static int T_10 F_174 ( struct V_152 * V_152 )
{
struct V_291 * V_292 ;
V_292 = F_175 ( L_7 , 0 , V_152 -> V_293 , & V_294 ) ;
if ( V_292 == NULL )
return - V_93 ;
return 0 ;
}
static void T_11 F_176 ( struct V_152 * V_152 )
{
F_177 ( L_7 , V_152 -> V_293 ) ;
}
static int T_10 F_174 ( struct V_152 * V_152 )
{
return 0 ;
}
static void T_11 F_176 ( struct V_152 * V_152 )
{
}
static int T_2 F_178 ( void )
{
int V_28 ;
V_28 = F_179 ( & V_295 ) ;
if ( V_28 ) {
F_180 ( L_8
L_9 ) ;
return V_28 ;
}
F_1 ( & V_296 ) ;
F_1 ( & V_297 ) ;
F_1 ( & V_298 ) ;
F_1 ( & V_299 ) ;
F_1 ( & V_300 ) ;
F_1 ( & V_301 ) ;
F_181 ( V_302 , V_256 , F_138 , NULL , NULL ) ;
F_181 ( V_302 , V_222 , F_132 , NULL , NULL ) ;
F_181 ( V_302 , V_216 , F_132 , F_159 ,
NULL ) ;
F_181 ( V_302 , V_276 , F_161 , NULL , NULL ) ;
F_181 ( V_302 , V_277 , F_161 , NULL , NULL ) ;
F_181 ( V_302 , V_274 , F_161 , F_167 ,
NULL ) ;
return 0 ;
}
