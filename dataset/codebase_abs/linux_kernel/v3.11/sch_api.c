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
static struct V_30 * F_5 ( struct V_30 * V_31 , T_1 V_32 )
{
struct V_30 * V_3 ;
if ( ! ( V_31 -> V_33 & V_34 ) &&
V_31 -> V_32 == V_32 )
return V_31 ;
F_6 (q, &root->list, list) {
if ( V_3 -> V_32 == V_32 )
return V_3 ;
}
return NULL ;
}
static void F_7 ( struct V_30 * V_3 )
{
if ( ( V_3 -> V_35 != V_36 ) && ! ( V_3 -> V_33 & V_37 ) )
F_8 ( & V_3 -> V_38 , & F_9 ( V_3 ) -> V_39 -> V_38 ) ;
}
void F_10 ( struct V_30 * V_3 )
{
if ( ( V_3 -> V_35 != V_36 ) && ! ( V_3 -> V_33 & V_37 ) )
F_11 ( & V_3 -> V_38 ) ;
}
struct V_30 * F_12 ( struct V_40 * V_41 , T_1 V_32 )
{
struct V_30 * V_3 ;
V_3 = F_5 ( V_41 -> V_39 , V_32 ) ;
if ( V_3 )
goto V_11;
if ( F_13 ( V_41 ) )
V_3 = F_5 (
F_13 ( V_41 ) -> V_42 ,
V_32 ) ;
V_11:
return V_3 ;
}
static struct V_30 * F_14 ( struct V_30 * V_43 , T_1 V_44 )
{
unsigned long V_45 ;
struct V_30 * V_23 ;
const struct V_18 * V_19 = V_43 -> V_46 -> V_17 ;
if ( V_19 == NULL )
return NULL ;
V_45 = V_19 -> V_20 ( V_43 , V_44 ) ;
if ( V_45 == 0 )
return NULL ;
V_23 = V_19 -> V_23 ( V_43 , V_45 ) ;
V_19 -> V_21 ( V_43 , V_45 ) ;
return V_23 ;
}
static struct V_1 * F_15 ( struct V_47 * V_48 )
{
struct V_1 * V_3 = NULL ;
if ( V_48 ) {
F_16 ( & V_7 ) ;
for ( V_3 = V_8 ; V_3 ; V_3 = V_3 -> V_9 ) {
if ( F_17 ( V_48 , V_3 -> V_10 ) == 0 ) {
if ( ! F_18 ( V_3 -> V_49 ) )
V_3 = NULL ;
break;
}
}
F_19 ( & V_7 ) ;
}
return V_3 ;
}
static T_2 F_20 ( struct V_50 * V_51 , T_3 * V_52 )
{
int V_53 = F_21 ( V_51 -> V_54 , 48 ) ;
int V_55 = F_21 ( V_53 + 1 , 48 ) ;
int V_56 = V_53 >> V_51 -> V_57 ;
int V_58 = ( V_55 >> V_51 -> V_57 ) - 1 ;
if ( ( V_51 -> V_59 > ( 100000000 / 8 ) ) || ( V_52 [ 0 ] == 0 ) ) {
F_22 ( L_1 ) ;
return V_60 ;
}
if ( ( V_58 > V_56 ) && ( V_58 < 256 )
&& ( V_52 [ V_56 ] == V_52 [ V_58 ] ) ) {
F_22 ( L_2 ,
V_56 , V_58 , V_52 [ V_58 ] ) ;
return V_61 ;
}
return V_60 ;
}
struct V_62 * F_23 ( struct V_50 * V_51 , struct V_47 * V_63 )
{
struct V_62 * V_52 ;
if ( V_63 == NULL || V_51 -> V_59 == 0 || V_51 -> V_57 == 0 ||
F_24 ( V_63 ) != V_64 )
return NULL ;
for ( V_52 = V_65 ; V_52 ; V_52 = V_52 -> V_9 ) {
if ( ! memcmp ( & V_52 -> V_59 , V_51 , sizeof( struct V_50 ) ) &&
! memcmp ( & V_52 -> V_66 , F_25 ( V_63 ) , 1024 ) ) {
V_52 -> V_67 ++ ;
return V_52 ;
}
}
V_52 = F_26 ( sizeof( * V_52 ) , V_68 ) ;
if ( V_52 ) {
V_52 -> V_59 = * V_51 ;
V_52 -> V_67 = 1 ;
memcpy ( V_52 -> V_66 , F_25 ( V_63 ) , 1024 ) ;
if ( V_51 -> V_69 == V_70 )
V_51 -> V_69 = F_20 ( V_51 , V_52 -> V_66 ) ;
V_52 -> V_9 = V_65 ;
V_65 = V_52 ;
}
return V_52 ;
}
void F_27 ( struct V_62 * V_63 )
{
struct V_62 * V_52 , * * V_71 ;
if ( ! V_63 || -- V_63 -> V_67 )
return;
for ( V_71 = & V_65 ;
( V_52 = * V_71 ) != NULL ;
V_71 = & V_52 -> V_9 ) {
if ( V_52 == V_63 ) {
* V_71 = V_52 -> V_9 ;
F_28 ( V_52 ) ;
return;
}
}
}
static struct V_72 * F_29 ( struct V_47 * V_73 )
{
struct V_47 * V_74 [ V_75 + 1 ] ;
struct V_72 * V_76 ;
struct V_77 * V_78 ;
unsigned int V_79 = 0 ;
T_4 * V_63 = NULL ;
int V_28 ;
V_28 = F_30 ( V_74 , V_75 , V_73 , V_80 ) ;
if ( V_28 < 0 )
return F_31 ( V_28 ) ;
if ( ! V_74 [ V_81 ] )
return F_31 ( - V_27 ) ;
V_78 = F_25 ( V_74 [ V_81 ] ) ;
if ( V_78 -> V_79 > 0 ) {
if ( ! V_74 [ V_82 ] )
return F_31 ( - V_27 ) ;
V_63 = F_25 ( V_74 [ V_82 ] ) ;
V_79 = F_24 ( V_74 [ V_82 ] ) / sizeof( T_4 ) ;
}
if ( V_79 != V_78 -> V_79 || ( ! V_63 && V_79 > 0 ) )
return F_31 ( - V_27 ) ;
F_32 ( & V_83 ) ;
F_6 (stab, &qdisc_stab_list, list) {
if ( memcmp ( & V_76 -> V_84 , V_78 , sizeof( * V_78 ) ) )
continue;
if ( V_79 > 0 && memcmp ( V_76 -> V_66 , V_63 , V_79 * sizeof( T_4 ) ) )
continue;
V_76 -> V_67 ++ ;
F_33 ( & V_83 ) ;
return V_76 ;
}
F_33 ( & V_83 ) ;
V_76 = F_26 ( sizeof( * V_76 ) + V_79 * sizeof( T_4 ) , V_68 ) ;
if ( ! V_76 )
return F_31 ( - V_85 ) ;
V_76 -> V_67 = 1 ;
V_76 -> V_84 = * V_78 ;
if ( V_79 > 0 )
memcpy ( V_76 -> V_66 , V_63 , V_79 * sizeof( T_4 ) ) ;
F_32 ( & V_83 ) ;
F_8 ( & V_76 -> V_38 , & V_86 ) ;
F_33 ( & V_83 ) ;
return V_76 ;
}
static void F_34 ( struct V_87 * V_88 )
{
F_28 ( F_35 ( V_88 , struct V_72 , V_89 ) ) ;
}
void F_36 ( struct V_72 * V_63 )
{
if ( ! V_63 )
return;
F_32 ( & V_83 ) ;
if ( -- V_63 -> V_67 == 0 ) {
F_11 ( & V_63 -> V_38 ) ;
F_37 ( & V_63 -> V_89 , F_34 ) ;
}
F_33 ( & V_83 ) ;
}
static int F_38 ( struct V_90 * V_91 , struct V_72 * V_76 )
{
struct V_47 * V_92 ;
V_92 = F_39 ( V_91 , V_93 ) ;
if ( V_92 == NULL )
goto V_94;
if ( F_40 ( V_91 , V_81 , sizeof( V_76 -> V_84 ) , & V_76 -> V_84 ) )
goto V_94;
F_41 ( V_91 , V_92 ) ;
return V_91 -> V_95 ;
V_94:
return - 1 ;
}
void F_42 ( struct V_90 * V_91 , const struct V_72 * V_76 )
{
int V_96 , V_97 ;
V_96 = V_91 -> V_95 + V_76 -> V_84 . V_98 ;
if ( F_43 ( ! V_76 -> V_84 . V_79 ) )
goto V_11;
V_97 = V_96 + V_76 -> V_84 . V_99 ;
if ( F_43 ( V_97 < 0 ) )
V_97 = 0 ;
V_97 >>= V_76 -> V_84 . V_57 ;
if ( F_44 ( V_97 < V_76 -> V_84 . V_79 ) )
V_96 = V_76 -> V_66 [ V_97 ] ;
else
V_96 = V_76 -> V_66 [ V_76 -> V_84 . V_79 - 1 ] *
( V_97 / V_76 -> V_84 . V_79 ) +
V_76 -> V_66 [ V_97 % V_76 -> V_84 . V_79 ] ;
V_96 <<= V_76 -> V_84 . V_100 ;
V_11:
if ( F_43 ( V_96 < 1 ) )
V_96 = 1 ;
F_45 ( V_91 ) -> V_96 = V_96 ;
}
void F_46 ( char * V_101 , struct V_30 * V_39 )
{
if ( ! ( V_39 -> V_33 & V_102 ) ) {
F_47 ( L_3 ,
V_101 , V_39 -> V_46 -> V_10 , V_39 -> V_32 >> 16 ) ;
V_39 -> V_33 |= V_102 ;
}
}
static enum V_103 F_48 ( struct V_104 * V_105 )
{
struct F_48 * V_106 = F_35 ( V_105 , struct F_48 ,
V_105 ) ;
F_49 ( V_106 -> V_39 ) ;
F_50 ( F_51 ( V_106 -> V_39 ) ) ;
return V_107 ;
}
void F_52 ( struct F_48 * V_106 , struct V_30 * V_39 )
{
F_53 ( & V_106 -> V_105 , V_108 , V_109 ) ;
V_106 -> V_105 . V_110 = F_48 ;
V_106 -> V_39 = V_39 ;
}
void F_54 ( struct F_48 * V_106 , T_5 V_111 )
{
if ( F_55 ( V_112 ,
& F_56 ( V_106 -> V_39 ) -> V_113 ) )
return;
F_57 ( V_106 -> V_39 ) ;
F_58 ( & V_106 -> V_105 ,
F_59 ( V_111 ) ,
V_109 ) ;
}
void F_60 ( struct F_48 * V_106 )
{
F_61 ( & V_106 -> V_105 ) ;
F_49 ( V_106 -> V_39 ) ;
}
static struct V_114 * F_62 ( unsigned int V_115 )
{
unsigned int V_116 = V_115 * sizeof( struct V_114 ) , V_117 ;
struct V_114 * V_118 ;
if ( V_116 <= V_119 )
V_118 = F_26 ( V_116 , V_68 ) ;
else
V_118 = (struct V_114 * )
F_63 ( V_68 , F_64 ( V_116 ) ) ;
if ( V_118 != NULL ) {
for ( V_117 = 0 ; V_117 < V_115 ; V_117 ++ )
F_65 ( & V_118 [ V_117 ] ) ;
}
return V_118 ;
}
static void F_66 ( struct V_114 * V_118 , unsigned int V_115 )
{
unsigned int V_116 = V_115 * sizeof( struct V_114 ) ;
if ( V_116 <= V_119 )
F_28 ( V_118 ) ;
else
F_67 ( ( unsigned long ) V_118 , F_64 ( V_116 ) ) ;
}
void F_68 ( struct V_30 * V_120 , struct V_121 * V_122 )
{
struct V_123 * V_45 ;
struct V_124 * V_9 ;
struct V_114 * V_125 , * V_126 ;
unsigned int V_127 , V_128 , V_129 ;
unsigned int V_117 , V_118 ;
if ( V_122 -> V_130 * 4 <= V_122 -> V_131 * 3 )
return;
V_127 = V_122 -> V_131 * 2 ;
V_128 = V_127 - 1 ;
V_125 = F_62 ( V_127 ) ;
if ( V_125 == NULL )
return;
V_126 = V_122 -> V_132 ;
V_129 = V_122 -> V_131 ;
F_69 ( V_120 ) ;
for ( V_117 = 0 ; V_117 < V_129 ; V_117 ++ ) {
F_70 (cl, next, &ohash[i], hnode) {
V_118 = F_71 ( V_45 -> V_44 , V_128 ) ;
F_72 ( & V_45 -> V_133 , & V_125 [ V_118 ] ) ;
}
}
V_122 -> V_132 = V_125 ;
V_122 -> V_131 = V_127 ;
V_122 -> V_134 = V_128 ;
F_73 ( V_120 ) ;
F_66 ( V_126 , V_129 ) ;
}
int F_74 ( struct V_121 * V_122 )
{
unsigned int V_116 = 4 ;
V_122 -> V_132 = F_62 ( V_116 ) ;
if ( V_122 -> V_132 == NULL )
return - V_85 ;
V_122 -> V_131 = V_116 ;
V_122 -> V_134 = V_116 - 1 ;
V_122 -> V_130 = 0 ;
return 0 ;
}
void F_75 ( struct V_121 * V_122 )
{
F_66 ( V_122 -> V_132 , V_122 -> V_131 ) ;
}
void F_76 ( struct V_121 * V_122 ,
struct V_123 * V_45 )
{
unsigned int V_118 ;
F_77 ( & V_45 -> V_133 ) ;
V_118 = F_71 ( V_45 -> V_44 , V_122 -> V_134 ) ;
F_72 ( & V_45 -> V_133 , & V_122 -> V_132 [ V_118 ] ) ;
V_122 -> V_130 ++ ;
}
void F_78 ( struct V_121 * V_122 ,
struct V_123 * V_45 )
{
F_79 ( & V_45 -> V_133 ) ;
V_122 -> V_130 -- ;
}
static T_1 F_80 ( struct V_40 * V_41 )
{
int V_117 = 0x8000 ;
static T_1 V_135 = F_81 ( 0x80000000U , 0 ) ;
do {
V_135 += F_81 ( 0x10000U , 0 ) ;
if ( V_135 == F_81 ( V_36 , 0 ) )
V_135 = F_81 ( 0x80000000U , 0 ) ;
if ( ! F_12 ( V_41 , V_135 ) )
return V_135 ;
F_82 () ;
} while ( -- V_117 > 0 );
return 0 ;
}
void F_83 ( struct V_30 * V_120 , unsigned int V_115 )
{
const struct V_18 * V_19 ;
unsigned long V_45 ;
T_1 V_136 ;
if ( V_115 == 0 )
return;
while ( ( V_136 = V_120 -> V_35 ) ) {
if ( F_84 ( V_136 ) == F_84 ( V_137 ) )
return;
V_120 = F_12 ( F_9 ( V_120 ) , F_84 ( V_136 ) ) ;
if ( V_120 == NULL ) {
F_85 ( V_136 != V_36 ) ;
return;
}
V_19 = V_120 -> V_46 -> V_17 ;
if ( V_19 -> V_138 ) {
V_45 = V_19 -> V_20 ( V_120 , V_136 ) ;
V_19 -> V_138 ( V_120 , V_45 ) ;
V_19 -> V_21 ( V_120 , V_45 ) ;
}
V_120 -> V_3 . V_139 -= V_115 ;
}
}
static void F_86 ( struct V_140 * V_140 , struct V_90 * V_91 ,
struct V_141 * V_115 , T_1 V_142 ,
struct V_30 * V_143 , struct V_30 * V_144 )
{
if ( V_144 || V_143 )
F_87 ( V_140 , V_91 , V_115 , V_142 , V_143 , V_144 ) ;
if ( V_143 )
F_88 ( V_143 ) ;
}
static int F_89 ( struct V_40 * V_41 , struct V_30 * V_35 ,
struct V_90 * V_91 , struct V_141 * V_115 , T_1 V_44 ,
struct V_30 * V_144 , struct V_30 * V_143 )
{
struct V_30 * V_3 = V_143 ;
struct V_140 * V_140 = F_90 ( V_41 ) ;
int V_28 = 0 ;
if ( V_35 == NULL ) {
unsigned int V_117 , V_145 , V_146 ;
V_146 = 0 ;
V_145 = V_41 -> V_147 ;
if ( ( V_3 && V_3 -> V_33 & V_37 ) ||
( V_144 && V_144 -> V_33 & V_37 ) ) {
V_145 = 1 ;
V_146 = 1 ;
if ( ! F_13 ( V_41 ) )
return - V_29 ;
}
if ( V_41 -> V_33 & V_148 )
F_91 ( V_41 ) ;
if ( V_144 && V_144 -> V_46 -> V_149 ) {
V_144 -> V_46 -> V_149 ( V_144 ) ;
V_145 = 0 ;
}
for ( V_117 = 0 ; V_117 < V_145 ; V_117 ++ ) {
struct V_150 * V_151 = F_13 ( V_41 ) ;
if ( ! V_146 )
V_151 = F_92 ( V_41 , V_117 ) ;
V_143 = F_93 ( V_151 , V_144 ) ;
if ( V_144 && V_117 > 0 )
F_94 ( & V_144 -> V_67 ) ;
if ( ! V_146 )
F_88 ( V_143 ) ;
}
if ( ! V_146 ) {
F_86 ( V_140 , V_91 , V_115 , V_44 ,
V_41 -> V_39 , V_144 ) ;
if ( V_144 && ! V_144 -> V_46 -> V_149 )
F_94 ( & V_144 -> V_67 ) ;
V_41 -> V_39 = V_144 ? : & V_152 ;
} else {
F_86 ( V_140 , V_91 , V_115 , V_44 , V_143 , V_144 ) ;
}
if ( V_41 -> V_33 & V_148 )
F_95 ( V_41 ) ;
} else {
const struct V_18 * V_19 = V_35 -> V_46 -> V_17 ;
V_28 = - V_153 ;
if ( V_19 && V_19 -> V_154 ) {
unsigned long V_45 = V_19 -> V_20 ( V_35 , V_44 ) ;
if ( V_45 ) {
V_28 = V_19 -> V_154 ( V_35 , V_45 , V_144 , & V_143 ) ;
V_19 -> V_21 ( V_35 , V_45 ) ;
} else
V_28 = - V_29 ;
}
if ( ! V_28 )
F_86 ( V_140 , V_91 , V_115 , V_44 , V_143 , V_144 ) ;
}
return V_28 ;
}
static struct V_30 *
F_96 ( struct V_40 * V_41 , struct V_150 * V_151 ,
struct V_30 * V_43 , T_1 V_35 , T_1 V_32 ,
struct V_47 * * V_155 , int * V_156 )
{
int V_28 ;
struct V_47 * V_48 = V_155 [ V_157 ] ;
struct V_30 * V_120 ;
struct V_1 * V_46 ;
struct V_72 * V_76 ;
V_46 = F_15 ( V_48 ) ;
#ifdef F_97
if ( V_46 == NULL && V_48 != NULL ) {
char V_158 [ V_159 ] ;
if ( F_98 ( V_158 , V_48 , V_159 ) < V_159 ) {
F_99 () ;
F_100 ( L_4 , V_158 ) ;
F_101 () ;
V_46 = F_15 ( V_48 ) ;
if ( V_46 != NULL ) {
F_102 ( V_46 -> V_49 ) ;
V_28 = - V_160 ;
goto V_161;
}
}
}
#endif
V_28 = - V_29 ;
if ( V_46 == NULL )
goto V_161;
V_120 = F_103 ( V_151 , V_46 ) ;
if ( F_104 ( V_120 ) ) {
V_28 = F_105 ( V_120 ) ;
goto V_162;
}
V_120 -> V_35 = V_35 ;
if ( V_32 == V_137 ) {
V_120 -> V_33 |= V_37 ;
V_32 = F_81 ( V_137 , 0 ) ;
F_106 ( F_107 ( V_120 ) , & V_163 ) ;
} else {
if ( V_32 == 0 ) {
V_32 = F_80 ( V_41 ) ;
V_28 = - V_85 ;
if ( V_32 == 0 )
goto V_164;
}
F_106 ( F_107 ( V_120 ) , & V_165 ) ;
if ( ! F_108 ( V_41 ) )
V_120 -> V_33 |= V_166 ;
}
V_120 -> V_32 = V_32 ;
if ( ! V_46 -> V_167 || ( V_28 = V_46 -> V_167 ( V_120 , V_155 [ V_168 ] ) ) == 0 ) {
if ( V_155 [ V_93 ] ) {
V_76 = F_29 ( V_155 [ V_93 ] ) ;
if ( F_104 ( V_76 ) ) {
V_28 = F_105 ( V_76 ) ;
goto V_169;
}
F_109 ( V_120 -> V_76 , V_76 ) ;
}
if ( V_155 [ V_170 ] ) {
T_6 * V_171 ;
V_28 = - V_153 ;
if ( V_120 -> V_33 & V_172 )
goto V_169;
if ( ( V_120 -> V_35 != V_36 ) &&
! ( V_120 -> V_33 & V_37 ) &&
( ! V_43 || ! ( V_43 -> V_33 & V_172 ) ) )
V_171 = F_110 ( V_120 ) ;
else
V_171 = F_107 ( V_120 ) ;
V_28 = F_111 ( & V_120 -> V_173 , & V_120 -> V_174 ,
V_171 , V_155 [ V_170 ] ) ;
if ( V_28 )
goto V_169;
}
F_7 ( V_120 ) ;
return V_120 ;
}
V_164:
F_112 ( V_41 ) ;
F_28 ( ( char * ) V_120 - V_120 -> V_175 ) ;
V_162:
F_102 ( V_46 -> V_49 ) ;
V_161:
* V_156 = V_28 ;
return NULL ;
V_169:
F_36 ( F_113 ( V_120 -> V_76 ) ) ;
if ( V_46 -> V_176 )
V_46 -> V_176 ( V_120 ) ;
goto V_164;
}
static int F_114 ( struct V_30 * V_120 , struct V_47 * * V_155 )
{
struct V_72 * V_177 , * V_76 = NULL ;
int V_28 = 0 ;
if ( V_155 [ V_168 ] ) {
if ( V_120 -> V_46 -> V_178 == NULL )
return - V_27 ;
V_28 = V_120 -> V_46 -> V_178 ( V_120 , V_155 [ V_168 ] ) ;
if ( V_28 )
return V_28 ;
}
if ( V_155 [ V_93 ] ) {
V_76 = F_29 ( V_155 [ V_93 ] ) ;
if ( F_104 ( V_76 ) )
return F_105 ( V_76 ) ;
}
V_177 = F_113 ( V_120 -> V_76 ) ;
F_109 ( V_120 -> V_76 , V_76 ) ;
F_36 ( V_177 ) ;
if ( V_155 [ V_170 ] ) {
if ( V_120 -> V_33 & V_172 )
goto V_11;
F_115 ( & V_120 -> V_173 , & V_120 -> V_174 ,
F_110 ( V_120 ) ,
V_155 [ V_170 ] ) ;
}
V_11:
return 0 ;
}
static int F_116 ( struct V_30 * V_3 , struct V_30 * V_43 , int V_179 )
{
struct V_180 V_181 ;
if ( V_3 -> V_46 -> V_17 == NULL )
return 0 ;
V_181 . V_182 . V_183 = V_181 . V_182 . V_184 = V_181 . V_182 . V_185 = 0 ;
V_181 . V_182 . V_186 = V_187 ;
V_181 . V_179 = V_179 ;
V_181 . V_43 = V_43 ;
V_3 -> V_46 -> V_17 -> V_22 ( V_3 , & V_181 . V_182 ) ;
return V_181 . V_182 . V_183 ? - V_188 : 0 ;
}
static int
V_187 ( struct V_30 * V_3 , unsigned long V_45 , struct V_189 * V_182 )
{
struct V_30 * V_23 ;
const struct V_18 * V_19 = V_3 -> V_46 -> V_17 ;
struct V_180 * V_181 = (struct V_180 * ) V_182 ;
V_23 = V_19 -> V_23 ( V_3 , V_45 ) ;
if ( V_23 ) {
if ( V_23 == V_181 -> V_43 || V_181 -> V_179 > 7 )
return - V_188 ;
return F_116 ( V_23 , V_181 -> V_43 , V_181 -> V_179 + 1 ) ;
}
return 0 ;
}
static int F_117 ( struct V_90 * V_91 , struct V_141 * V_115 )
{
struct V_140 * V_140 = F_118 ( V_91 -> V_190 ) ;
struct V_191 * V_192 = F_119 ( V_115 ) ;
struct V_47 * V_155 [ V_193 + 1 ] ;
struct V_40 * V_41 ;
T_1 V_142 ;
struct V_30 * V_3 = NULL ;
struct V_30 * V_43 = NULL ;
int V_28 ;
if ( ( V_115 -> V_194 != V_195 ) && ! F_120 ( V_196 ) )
return - V_197 ;
V_28 = F_121 ( V_115 , sizeof( * V_192 ) , V_155 , V_193 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_41 = F_122 ( V_140 , V_192 -> V_198 ) ;
if ( ! V_41 )
return - V_199 ;
V_142 = V_192 -> V_200 ;
if ( V_142 ) {
if ( V_142 != V_36 ) {
if ( F_84 ( V_142 ) != F_84 ( V_137 ) ) {
V_43 = F_12 ( V_41 , F_84 ( V_142 ) ) ;
if ( ! V_43 )
return - V_29 ;
V_3 = F_14 ( V_43 , V_142 ) ;
} else if ( F_13 ( V_41 ) ) {
V_3 = F_13 ( V_41 ) -> V_42 ;
}
} else {
V_3 = V_41 -> V_39 ;
}
if ( ! V_3 )
return - V_29 ;
if ( V_192 -> V_201 && V_3 -> V_32 != V_192 -> V_201 )
return - V_27 ;
} else {
V_3 = F_12 ( V_41 , V_192 -> V_201 ) ;
if ( ! V_3 )
return - V_29 ;
}
if ( V_155 [ V_157 ] && F_17 ( V_155 [ V_157 ] , V_3 -> V_46 -> V_10 ) )
return - V_27 ;
if ( V_115 -> V_194 == V_202 ) {
if ( ! V_142 )
return - V_27 ;
if ( V_3 -> V_32 == 0 )
return - V_29 ;
V_28 = F_89 ( V_41 , V_43 , V_91 , V_115 , V_142 , NULL , V_3 ) ;
if ( V_28 != 0 )
return V_28 ;
} else {
F_87 ( V_140 , V_91 , V_115 , V_142 , NULL , V_3 ) ;
}
return 0 ;
}
static int F_123 ( struct V_90 * V_91 , struct V_141 * V_115 )
{
struct V_140 * V_140 = F_118 ( V_91 -> V_190 ) ;
struct V_191 * V_192 ;
struct V_47 * V_155 [ V_193 + 1 ] ;
struct V_40 * V_41 ;
T_1 V_142 ;
struct V_30 * V_3 , * V_43 ;
int V_28 ;
if ( ! F_120 ( V_196 ) )
return - V_197 ;
V_203:
V_28 = F_121 ( V_115 , sizeof( * V_192 ) , V_155 , V_193 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_192 = F_119 ( V_115 ) ;
V_142 = V_192 -> V_200 ;
V_3 = V_43 = NULL ;
V_41 = F_122 ( V_140 , V_192 -> V_198 ) ;
if ( ! V_41 )
return - V_199 ;
if ( V_142 ) {
if ( V_142 != V_36 ) {
if ( V_142 != V_137 ) {
V_43 = F_12 ( V_41 , F_84 ( V_142 ) ) ;
if ( ! V_43 )
return - V_29 ;
V_3 = F_14 ( V_43 , V_142 ) ;
} else if ( F_124 ( V_41 ) ) {
V_3 = F_13 ( V_41 ) -> V_42 ;
}
} else {
V_3 = V_41 -> V_39 ;
}
if ( V_3 && V_3 -> V_32 == 0 )
V_3 = NULL ;
if ( ! V_3 || ! V_192 -> V_201 || V_3 -> V_32 != V_192 -> V_201 ) {
if ( V_192 -> V_201 ) {
if ( V_3 && ! ( V_115 -> V_204 & V_205 ) )
return - V_6 ;
if ( F_125 ( V_192 -> V_201 ) )
return - V_27 ;
V_3 = F_12 ( V_41 , V_192 -> V_201 ) ;
if ( ! V_3 )
goto V_206;
if ( V_115 -> V_204 & V_207 )
return - V_6 ;
if ( V_155 [ V_157 ] && F_17 ( V_155 [ V_157 ] , V_3 -> V_46 -> V_10 ) )
return - V_27 ;
if ( V_3 == V_43 ||
( V_43 && F_116 ( V_3 , V_43 , 0 ) ) )
return - V_188 ;
F_94 ( & V_3 -> V_67 ) ;
goto V_154;
} else {
if ( ! V_3 )
goto V_206;
if ( ( V_115 -> V_204 & V_208 ) &&
( V_115 -> V_204 & V_205 ) &&
( ( V_115 -> V_204 & V_207 ) ||
( V_155 [ V_157 ] &&
F_17 ( V_155 [ V_157 ] , V_3 -> V_46 -> V_10 ) ) ) )
goto V_206;
}
}
} else {
if ( ! V_192 -> V_201 )
return - V_27 ;
V_3 = F_12 ( V_41 , V_192 -> V_201 ) ;
}
if ( V_3 == NULL )
return - V_29 ;
if ( V_115 -> V_204 & V_207 )
return - V_6 ;
if ( V_155 [ V_157 ] && F_17 ( V_155 [ V_157 ] , V_3 -> V_46 -> V_10 ) )
return - V_27 ;
V_28 = F_114 ( V_3 , V_155 ) ;
if ( V_28 == 0 )
F_87 ( V_140 , V_91 , V_115 , V_142 , NULL , V_3 ) ;
return V_28 ;
V_206:
if ( ! ( V_115 -> V_204 & V_208 ) )
return - V_29 ;
if ( V_142 == V_137 ) {
if ( F_13 ( V_41 ) )
V_3 = F_96 ( V_41 , F_13 ( V_41 ) , V_43 ,
V_192 -> V_200 , V_192 -> V_200 ,
V_155 , & V_28 ) ;
else
V_28 = - V_29 ;
} else {
struct V_150 * V_151 ;
if ( V_43 && V_43 -> V_46 -> V_17 && V_43 -> V_46 -> V_17 -> V_209 )
V_151 = V_43 -> V_46 -> V_17 -> V_209 ( V_43 , V_192 ) ;
else if ( V_43 )
V_151 = V_43 -> V_151 ;
else
V_151 = F_92 ( V_41 , 0 ) ;
V_3 = F_96 ( V_41 , V_151 , V_43 ,
V_192 -> V_200 , V_192 -> V_201 ,
V_155 , & V_28 ) ;
}
if ( V_3 == NULL ) {
if ( V_28 == - V_160 )
goto V_203;
return V_28 ;
}
V_154:
V_28 = F_89 ( V_41 , V_43 , V_91 , V_115 , V_142 , V_3 , NULL ) ;
if ( V_28 ) {
if ( V_3 )
F_88 ( V_3 ) ;
return V_28 ;
}
return 0 ;
}
static int F_126 ( struct V_90 * V_91 , struct V_30 * V_3 , T_1 V_142 ,
T_1 V_210 , T_1 V_211 , T_4 V_33 , int V_212 )
{
struct V_191 * V_192 ;
struct V_141 * V_213 ;
unsigned char * V_214 = F_127 ( V_91 ) ;
struct V_215 V_216 ;
struct V_72 * V_76 ;
V_213 = F_128 ( V_91 , V_210 , V_211 , V_212 , sizeof( * V_192 ) , V_33 ) ;
if ( ! V_213 )
goto V_217;
V_192 = F_119 ( V_213 ) ;
V_192 -> V_218 = V_219 ;
V_192 -> V_220 = 0 ;
V_192 -> V_221 = 0 ;
V_192 -> V_198 = F_9 ( V_3 ) -> V_222 ;
V_192 -> V_200 = V_142 ;
V_192 -> V_201 = V_3 -> V_32 ;
V_192 -> V_223 = F_129 ( & V_3 -> V_67 ) ;
if ( F_130 ( V_91 , V_157 , V_3 -> V_46 -> V_10 ) )
goto V_94;
if ( V_3 -> V_46 -> V_224 && V_3 -> V_46 -> V_224 ( V_3 , V_91 ) < 0 )
goto V_94;
V_3 -> V_225 . V_139 = V_3 -> V_3 . V_139 ;
V_76 = F_113 ( V_3 -> V_76 ) ;
if ( V_76 && F_38 ( V_91 , V_76 ) < 0 )
goto V_94;
if ( F_131 ( V_91 , V_226 , V_227 , V_228 ,
F_110 ( V_3 ) , & V_216 ) < 0 )
goto V_94;
if ( V_3 -> V_46 -> V_229 && V_3 -> V_46 -> V_229 ( V_3 , & V_216 ) < 0 )
goto V_94;
if ( F_132 ( & V_216 , & V_3 -> V_173 ) < 0 ||
F_133 ( & V_216 , & V_3 -> V_173 , & V_3 -> V_174 ) < 0 ||
F_134 ( & V_216 , & V_3 -> V_225 ) < 0 )
goto V_94;
if ( F_135 ( & V_216 ) < 0 )
goto V_94;
V_213 -> V_230 = F_127 ( V_91 ) - V_214 ;
return V_91 -> V_95 ;
V_217:
V_94:
F_136 ( V_91 , V_214 ) ;
return - 1 ;
}
static bool F_137 ( struct V_30 * V_3 )
{
return ( V_3 -> V_33 & V_34 ) ? true : false ;
}
static int F_87 ( struct V_140 * V_140 , struct V_90 * V_231 ,
struct V_141 * V_115 , T_1 V_142 ,
struct V_30 * V_143 , struct V_30 * V_144 )
{
struct V_90 * V_91 ;
T_1 V_210 = V_231 ? F_138 ( V_231 ) . V_210 : 0 ;
V_91 = F_139 ( V_232 , V_68 ) ;
if ( ! V_91 )
return - V_233 ;
if ( V_143 && ! F_137 ( V_143 ) ) {
if ( F_126 ( V_91 , V_143 , V_142 , V_210 , V_115 -> V_234 ,
0 , V_202 ) < 0 )
goto V_161;
}
if ( V_144 && ! F_137 ( V_144 ) ) {
if ( F_126 ( V_91 , V_144 , V_142 , V_210 , V_115 -> V_234 ,
V_143 ? V_205 : 0 , V_235 ) < 0 )
goto V_161;
}
if ( V_91 -> V_95 )
return F_140 ( V_91 , V_140 , V_210 , V_236 ,
V_115 -> V_204 & V_237 ) ;
V_161:
F_141 ( V_91 ) ;
return - V_27 ;
}
static int F_142 ( struct V_30 * V_31 , struct V_90 * V_91 ,
struct V_238 * V_239 ,
int * V_240 , int V_241 )
{
int V_242 = 0 , V_243 = * V_240 ;
struct V_30 * V_3 ;
if ( ! V_31 )
return 0 ;
V_3 = V_31 ;
if ( V_243 < V_241 ) {
V_243 ++ ;
} else {
if ( ! F_137 ( V_3 ) &&
F_126 ( V_91 , V_3 , V_3 -> V_35 , F_138 ( V_239 -> V_91 ) . V_210 ,
V_239 -> V_213 -> V_234 , V_244 , V_235 ) <= 0 )
goto V_245;
V_243 ++ ;
}
F_6 (q, &root->list, list) {
if ( V_243 < V_241 ) {
V_243 ++ ;
continue;
}
if ( ! F_137 ( V_3 ) &&
F_126 ( V_91 , V_3 , V_3 -> V_35 , F_138 ( V_239 -> V_91 ) . V_210 ,
V_239 -> V_213 -> V_234 , V_244 , V_235 ) <= 0 )
goto V_245;
V_243 ++ ;
}
V_11:
* V_240 = V_243 ;
return V_242 ;
V_245:
V_242 = - 1 ;
goto V_11;
}
static int F_143 ( struct V_90 * V_91 , struct V_238 * V_239 )
{
struct V_140 * V_140 = F_118 ( V_91 -> V_190 ) ;
int V_246 , V_243 ;
int V_247 , V_241 ;
struct V_40 * V_41 ;
V_247 = V_239 -> args [ 0 ] ;
V_241 = V_243 = V_239 -> args [ 1 ] ;
F_144 () ;
V_246 = 0 ;
F_145 (net, dev) {
struct V_150 * V_151 ;
if ( V_246 < V_247 )
goto V_248;
if ( V_246 > V_247 )
V_241 = 0 ;
V_243 = 0 ;
if ( F_142 ( V_41 -> V_39 , V_91 , V_239 , & V_243 , V_241 ) < 0 )
goto V_245;
V_151 = F_13 ( V_41 ) ;
if ( V_151 &&
F_142 ( V_151 -> V_42 , V_91 , V_239 ,
& V_243 , V_241 ) < 0 )
goto V_245;
V_248:
V_246 ++ ;
}
V_245:
F_146 () ;
V_239 -> args [ 0 ] = V_246 ;
V_239 -> args [ 1 ] = V_243 ;
return V_91 -> V_95 ;
}
static int F_147 ( struct V_90 * V_91 , struct V_141 * V_115 )
{
struct V_140 * V_140 = F_118 ( V_91 -> V_190 ) ;
struct V_191 * V_192 = F_119 ( V_115 ) ;
struct V_47 * V_155 [ V_193 + 1 ] ;
struct V_40 * V_41 ;
struct V_30 * V_3 = NULL ;
const struct V_18 * V_19 ;
unsigned long V_45 = 0 ;
unsigned long V_249 ;
T_1 V_210 ;
T_1 V_142 ;
T_1 V_250 ;
int V_28 ;
if ( ( V_115 -> V_194 != V_251 ) && ! F_120 ( V_196 ) )
return - V_197 ;
V_28 = F_121 ( V_115 , sizeof( * V_192 ) , V_155 , V_193 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_41 = F_122 ( V_140 , V_192 -> V_198 ) ;
if ( ! V_41 )
return - V_199 ;
V_210 = V_192 -> V_200 ;
V_142 = V_192 -> V_201 ;
V_250 = F_84 ( V_142 ) ;
if ( V_210 != V_36 ) {
T_1 V_252 = F_84 ( V_210 ) ;
if ( V_250 && V_252 ) {
if ( V_250 != V_252 )
return - V_27 ;
} else if ( V_252 ) {
V_250 = V_252 ;
} else if ( V_250 == 0 )
V_250 = V_41 -> V_39 -> V_32 ;
if ( V_210 )
V_210 = F_81 ( V_250 , V_210 ) ;
} else {
if ( V_250 == 0 )
V_250 = V_41 -> V_39 -> V_32 ;
}
V_3 = F_12 ( V_41 , V_250 ) ;
if ( ! V_3 )
return - V_29 ;
V_19 = V_3 -> V_46 -> V_17 ;
if ( V_19 == NULL )
return - V_27 ;
if ( V_142 == 0 ) {
if ( V_210 == V_36 )
V_142 = V_250 ;
} else
V_142 = F_81 ( V_250 , V_142 ) ;
if ( V_142 )
V_45 = V_19 -> V_20 ( V_3 , V_142 ) ;
if ( V_45 == 0 ) {
V_28 = - V_29 ;
if ( V_115 -> V_194 != V_253 ||
! ( V_115 -> V_204 & V_208 ) )
goto V_11;
} else {
switch ( V_115 -> V_194 ) {
case V_253 :
V_28 = - V_6 ;
if ( V_115 -> V_204 & V_207 )
goto V_11;
break;
case V_254 :
V_28 = - V_153 ;
if ( V_19 -> V_255 )
V_28 = V_19 -> V_255 ( V_3 , V_45 ) ;
if ( V_28 == 0 )
F_148 ( V_140 , V_91 , V_115 , V_3 , V_45 , V_254 ) ;
goto V_11;
case V_251 :
V_28 = F_148 ( V_140 , V_91 , V_115 , V_3 , V_45 , V_253 ) ;
goto V_11;
default:
V_28 = - V_27 ;
goto V_11;
}
}
V_249 = V_45 ;
V_28 = - V_153 ;
if ( V_19 -> V_178 )
V_28 = V_19 -> V_178 ( V_3 , V_142 , V_210 , V_155 , & V_249 ) ;
if ( V_28 == 0 )
F_148 ( V_140 , V_91 , V_115 , V_3 , V_249 , V_253 ) ;
V_11:
if ( V_45 )
V_19 -> V_21 ( V_3 , V_45 ) ;
return V_28 ;
}
static int F_149 ( struct V_90 * V_91 , struct V_30 * V_3 ,
unsigned long V_45 ,
T_1 V_210 , T_1 V_211 , T_4 V_33 , int V_212 )
{
struct V_191 * V_192 ;
struct V_141 * V_213 ;
unsigned char * V_214 = F_127 ( V_91 ) ;
struct V_215 V_216 ;
const struct V_18 * V_17 = V_3 -> V_46 -> V_17 ;
V_213 = F_128 ( V_91 , V_210 , V_211 , V_212 , sizeof( * V_192 ) , V_33 ) ;
if ( ! V_213 )
goto V_217;
V_192 = F_119 ( V_213 ) ;
V_192 -> V_218 = V_219 ;
V_192 -> V_220 = 0 ;
V_192 -> V_221 = 0 ;
V_192 -> V_198 = F_9 ( V_3 ) -> V_222 ;
V_192 -> V_200 = V_3 -> V_32 ;
V_192 -> V_201 = V_3 -> V_32 ;
V_192 -> V_223 = 0 ;
if ( F_130 ( V_91 , V_157 , V_3 -> V_46 -> V_10 ) )
goto V_94;
if ( V_17 -> V_224 && V_17 -> V_224 ( V_3 , V_45 , V_91 , V_192 ) < 0 )
goto V_94;
if ( F_131 ( V_91 , V_226 , V_227 , V_228 ,
F_110 ( V_3 ) , & V_216 ) < 0 )
goto V_94;
if ( V_17 -> V_229 && V_17 -> V_229 ( V_3 , V_45 , & V_216 ) < 0 )
goto V_94;
if ( F_135 ( & V_216 ) < 0 )
goto V_94;
V_213 -> V_230 = F_127 ( V_91 ) - V_214 ;
return V_91 -> V_95 ;
V_217:
V_94:
F_136 ( V_91 , V_214 ) ;
return - 1 ;
}
static int F_148 ( struct V_140 * V_140 , struct V_90 * V_231 ,
struct V_141 * V_115 , struct V_30 * V_3 ,
unsigned long V_45 , int V_212 )
{
struct V_90 * V_91 ;
T_1 V_210 = V_231 ? F_138 ( V_231 ) . V_210 : 0 ;
V_91 = F_139 ( V_232 , V_68 ) ;
if ( ! V_91 )
return - V_233 ;
if ( F_149 ( V_91 , V_3 , V_45 , V_210 , V_115 -> V_234 , 0 , V_212 ) < 0 ) {
F_141 ( V_91 ) ;
return - V_27 ;
}
return F_140 ( V_91 , V_140 , V_210 , V_236 ,
V_115 -> V_204 & V_237 ) ;
}
static int F_150 ( struct V_30 * V_3 , unsigned long V_45 , struct V_189 * V_181 )
{
struct V_256 * V_257 = (struct V_256 * ) V_181 ;
return F_149 ( V_257 -> V_91 , V_3 , V_45 , F_138 ( V_257 -> V_239 -> V_91 ) . V_210 ,
V_257 -> V_239 -> V_213 -> V_234 , V_244 , V_253 ) ;
}
static int F_151 ( struct V_30 * V_3 , struct V_90 * V_91 ,
struct V_191 * V_192 , struct V_238 * V_239 ,
int * V_258 , int V_259 )
{
struct V_256 V_181 ;
if ( F_137 ( V_3 ) ||
* V_258 < V_259 || ! V_3 -> V_46 -> V_17 ||
( V_192 -> V_200 &&
F_84 ( V_192 -> V_200 ) != V_3 -> V_32 ) ) {
( * V_258 ) ++ ;
return 0 ;
}
if ( * V_258 > V_259 )
memset ( & V_239 -> args [ 1 ] , 0 , sizeof( V_239 -> args ) - sizeof( V_239 -> args [ 0 ] ) ) ;
V_181 . V_182 . V_186 = F_150 ;
V_181 . V_91 = V_91 ;
V_181 . V_239 = V_239 ;
V_181 . V_182 . V_183 = 0 ;
V_181 . V_182 . V_184 = V_239 -> args [ 1 ] ;
V_181 . V_182 . V_185 = 0 ;
V_3 -> V_46 -> V_17 -> V_22 ( V_3 , & V_181 . V_182 ) ;
V_239 -> args [ 1 ] = V_181 . V_182 . V_185 ;
if ( V_181 . V_182 . V_183 )
return - 1 ;
( * V_258 ) ++ ;
return 0 ;
}
static int F_152 ( struct V_30 * V_31 , struct V_90 * V_91 ,
struct V_191 * V_192 , struct V_238 * V_239 ,
int * V_258 , int V_259 )
{
struct V_30 * V_3 ;
if ( ! V_31 )
return 0 ;
if ( F_151 ( V_31 , V_91 , V_192 , V_239 , V_258 , V_259 ) < 0 )
return - 1 ;
F_6 (q, &root->list, list) {
if ( F_151 ( V_3 , V_91 , V_192 , V_239 , V_258 , V_259 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_153 ( struct V_90 * V_91 , struct V_238 * V_239 )
{
struct V_191 * V_192 = F_119 ( V_239 -> V_213 ) ;
struct V_140 * V_140 = F_118 ( V_91 -> V_190 ) ;
struct V_150 * V_151 ;
struct V_40 * V_41 ;
int V_260 , V_259 ;
if ( V_230 ( V_239 -> V_213 ) < sizeof( * V_192 ) )
return 0 ;
V_41 = F_154 ( V_140 , V_192 -> V_198 ) ;
if ( ! V_41 )
return 0 ;
V_259 = V_239 -> args [ 0 ] ;
V_260 = 0 ;
if ( F_152 ( V_41 -> V_39 , V_91 , V_192 , V_239 , & V_260 , V_259 ) < 0 )
goto V_245;
V_151 = F_13 ( V_41 ) ;
if ( V_151 &&
F_152 ( V_151 -> V_42 , V_91 , V_192 , V_239 ,
& V_260 , V_259 ) < 0 )
goto V_245;
V_245:
V_239 -> args [ 0 ] = V_260 ;
F_112 ( V_41 ) ;
return V_91 -> V_95 ;
}
int F_155 ( struct V_90 * V_91 , const struct V_261 * V_262 ,
struct V_263 * V_264 )
{
T_7 V_265 = V_91 -> V_265 ;
int V_28 ;
for (; V_262 ; V_262 = V_262 -> V_9 ) {
if ( V_262 -> V_265 != V_265 &&
V_262 -> V_265 != F_156 ( V_266 ) )
continue;
V_28 = V_262 -> V_267 ( V_91 , V_262 , V_264 ) ;
if ( V_28 >= 0 ) {
#ifdef F_157
if ( V_28 != V_268 && V_91 -> V_269 )
V_91 -> V_269 = F_158 ( V_91 -> V_269 , 0 ) ;
#endif
return V_28 ;
}
}
return - 1 ;
}
int F_159 ( struct V_90 * V_91 , const struct V_261 * V_262 ,
struct V_263 * V_264 )
{
int V_28 = 0 ;
#ifdef F_157
const struct V_261 * V_270 = V_262 ;
V_271:
#endif
V_28 = F_155 ( V_91 , V_262 , V_264 ) ;
#ifdef F_157
if ( V_28 == V_268 ) {
T_1 V_272 = F_160 ( V_91 -> V_269 ) ;
V_262 = V_270 ;
if ( V_272 ++ >= V_273 ) {
F_161 ( L_5 ,
V_262 -> V_3 -> V_46 -> V_10 ,
V_262 -> V_274 & 0xffff ,
F_162 ( V_262 -> V_265 ) ) ;
return V_275 ;
}
V_91 -> V_269 = F_158 ( V_91 -> V_269 , V_272 ) ;
goto V_271;
}
#endif
return V_28 ;
}
void F_163 ( struct V_261 * V_262 )
{
V_262 -> V_46 -> V_176 ( V_262 ) ;
F_102 ( V_262 -> V_46 -> V_49 ) ;
F_28 ( V_262 ) ;
}
void F_164 ( struct V_261 * * V_276 )
{
struct V_261 * V_262 ;
while ( ( V_262 = * V_276 ) != NULL ) {
* V_276 = V_262 -> V_9 ;
F_163 ( V_262 ) ;
}
}
static int F_165 ( struct V_277 * V_211 , void * V_278 )
{
struct V_279 V_280 ;
F_166 ( V_108 , & V_280 ) ;
F_167 ( V_211 , L_6 ,
( T_1 ) V_281 , ( T_1 ) F_168 ( 1 ) ,
1000000 ,
( T_1 ) V_282 / ( T_1 ) F_169 ( F_170 ( V_280 ) ) ) ;
return 0 ;
}
static int F_171 ( struct V_283 * V_283 , struct V_284 * V_284 )
{
return F_172 ( V_284 , F_165 , NULL ) ;
}
static int T_8 F_173 ( struct V_140 * V_140 )
{
struct V_285 * V_286 ;
V_286 = F_174 ( L_7 , 0 , V_140 -> V_287 , & V_288 ) ;
if ( V_286 == NULL )
return - V_85 ;
return 0 ;
}
static void T_9 F_175 ( struct V_140 * V_140 )
{
F_176 ( L_7 , V_140 -> V_287 ) ;
}
static int T_8 F_173 ( struct V_140 * V_140 )
{
return 0 ;
}
static void T_9 F_175 ( struct V_140 * V_140 )
{
}
static int T_10 F_177 ( void )
{
int V_28 ;
V_28 = F_178 ( & V_289 ) ;
if ( V_28 ) {
F_179 ( L_8
L_9 ) ;
return V_28 ;
}
F_1 ( & V_290 ) ;
F_1 ( & V_291 ) ;
F_1 ( & V_292 ) ;
F_1 ( & V_293 ) ;
F_180 ( V_294 , V_235 , F_123 , NULL , NULL ) ;
F_180 ( V_294 , V_202 , F_117 , NULL , NULL ) ;
F_180 ( V_294 , V_195 , F_117 , F_143 , NULL ) ;
F_180 ( V_294 , V_253 , F_147 , NULL , NULL ) ;
F_180 ( V_294 , V_254 , F_147 , NULL , NULL ) ;
F_180 ( V_294 , V_251 , F_147 , F_153 , NULL ) ;
return 0 ;
}
