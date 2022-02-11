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
struct V_50 * F_20 ( struct V_51 * V_52 , struct V_47 * V_53 )
{
struct V_50 * V_54 ;
for ( V_54 = V_55 ; V_54 ; V_54 = V_54 -> V_9 ) {
if ( memcmp ( & V_54 -> V_56 , V_52 , sizeof( struct V_51 ) ) == 0 ) {
V_54 -> V_57 ++ ;
return V_54 ;
}
}
if ( V_53 == NULL || V_52 -> V_56 == 0 || V_52 -> V_58 == 0 ||
F_21 ( V_53 ) != V_59 )
return NULL ;
V_54 = F_22 ( sizeof( * V_54 ) , V_60 ) ;
if ( V_54 ) {
V_54 -> V_56 = * V_52 ;
V_54 -> V_57 = 1 ;
memcpy ( V_54 -> V_61 , F_23 ( V_53 ) , 1024 ) ;
V_54 -> V_9 = V_55 ;
V_55 = V_54 ;
}
return V_54 ;
}
void F_24 ( struct V_50 * V_53 )
{
struct V_50 * V_54 , * * V_62 ;
if ( ! V_53 || -- V_53 -> V_57 )
return;
for ( V_62 = & V_55 ;
( V_54 = * V_62 ) != NULL ;
V_62 = & V_54 -> V_9 ) {
if ( V_54 == V_53 ) {
* V_62 = V_54 -> V_9 ;
F_25 ( V_54 ) ;
return;
}
}
}
static struct V_63 * F_26 ( struct V_47 * V_64 )
{
struct V_47 * V_65 [ V_66 + 1 ] ;
struct V_63 * V_67 ;
struct V_68 * V_69 ;
unsigned int V_70 = 0 ;
T_2 * V_53 = NULL ;
int V_28 ;
V_28 = F_27 ( V_65 , V_66 , V_64 , V_71 ) ;
if ( V_28 < 0 )
return F_28 ( V_28 ) ;
if ( ! V_65 [ V_72 ] )
return F_28 ( - V_27 ) ;
V_69 = F_23 ( V_65 [ V_72 ] ) ;
if ( V_69 -> V_70 > 0 ) {
if ( ! V_65 [ V_73 ] )
return F_28 ( - V_27 ) ;
V_53 = F_23 ( V_65 [ V_73 ] ) ;
V_70 = F_21 ( V_65 [ V_73 ] ) / sizeof( T_2 ) ;
}
if ( V_70 != V_69 -> V_70 || ( ! V_53 && V_70 > 0 ) )
return F_28 ( - V_27 ) ;
F_29 ( & V_74 ) ;
F_6 (stab, &qdisc_stab_list, list) {
if ( memcmp ( & V_67 -> V_75 , V_69 , sizeof( * V_69 ) ) )
continue;
if ( V_70 > 0 && memcmp ( V_67 -> V_61 , V_53 , V_70 * sizeof( T_2 ) ) )
continue;
V_67 -> V_57 ++ ;
F_30 ( & V_74 ) ;
return V_67 ;
}
F_30 ( & V_74 ) ;
V_67 = F_22 ( sizeof( * V_67 ) + V_70 * sizeof( T_2 ) , V_60 ) ;
if ( ! V_67 )
return F_28 ( - V_76 ) ;
V_67 -> V_57 = 1 ;
V_67 -> V_75 = * V_69 ;
if ( V_70 > 0 )
memcpy ( V_67 -> V_61 , V_53 , V_70 * sizeof( T_2 ) ) ;
F_29 ( & V_74 ) ;
F_8 ( & V_67 -> V_38 , & V_77 ) ;
F_30 ( & V_74 ) ;
return V_67 ;
}
static void F_31 ( struct V_78 * V_79 )
{
F_25 ( F_32 ( V_79 , struct V_63 , V_80 ) ) ;
}
void F_33 ( struct V_63 * V_53 )
{
if ( ! V_53 )
return;
F_29 ( & V_74 ) ;
if ( -- V_53 -> V_57 == 0 ) {
F_11 ( & V_53 -> V_38 ) ;
F_34 ( & V_53 -> V_80 , F_31 ) ;
}
F_30 ( & V_74 ) ;
}
static int F_35 ( struct V_81 * V_82 , struct V_63 * V_67 )
{
struct V_47 * V_83 ;
V_83 = F_36 ( V_82 , V_84 ) ;
if ( V_83 == NULL )
goto V_85;
if ( F_37 ( V_82 , V_72 , sizeof( V_67 -> V_75 ) , & V_67 -> V_75 ) )
goto V_85;
F_38 ( V_82 , V_83 ) ;
return V_82 -> V_86 ;
V_85:
return - 1 ;
}
void F_39 ( struct V_81 * V_82 , const struct V_63 * V_67 )
{
int V_87 , V_88 ;
V_87 = V_82 -> V_86 + V_67 -> V_75 . V_89 ;
if ( F_40 ( ! V_67 -> V_75 . V_70 ) )
goto V_11;
V_88 = V_87 + V_67 -> V_75 . V_90 ;
if ( F_40 ( V_88 < 0 ) )
V_88 = 0 ;
V_88 >>= V_67 -> V_75 . V_58 ;
if ( F_41 ( V_88 < V_67 -> V_75 . V_70 ) )
V_87 = V_67 -> V_61 [ V_88 ] ;
else
V_87 = V_67 -> V_61 [ V_67 -> V_75 . V_70 - 1 ] *
( V_88 / V_67 -> V_75 . V_70 ) +
V_67 -> V_61 [ V_88 % V_67 -> V_75 . V_70 ] ;
V_87 <<= V_67 -> V_75 . V_91 ;
V_11:
if ( F_40 ( V_87 < 1 ) )
V_87 = 1 ;
F_42 ( V_82 ) -> V_87 = V_87 ;
}
void F_43 ( char * V_92 , struct V_30 * V_39 )
{
if ( ! ( V_39 -> V_33 & V_93 ) ) {
F_44 ( L_1 ,
V_92 , V_39 -> V_46 -> V_10 , V_39 -> V_32 >> 16 ) ;
V_39 -> V_33 |= V_93 ;
}
}
static enum V_94 F_45 ( struct V_95 * V_96 )
{
struct F_45 * V_97 = F_32 ( V_96 , struct F_45 ,
V_96 ) ;
F_46 ( V_97 -> V_39 ) ;
F_47 ( F_48 ( V_97 -> V_39 ) ) ;
return V_98 ;
}
void F_49 ( struct F_45 * V_97 , struct V_30 * V_39 )
{
F_50 ( & V_97 -> V_96 , V_99 , V_100 ) ;
V_97 -> V_96 . V_101 = F_45 ;
V_97 -> V_39 = V_39 ;
}
void F_51 ( struct F_45 * V_97 , T_3 V_102 )
{
T_4 time ;
if ( F_52 ( V_103 ,
& F_53 ( V_97 -> V_39 ) -> V_104 ) )
return;
F_54 ( V_97 -> V_39 ) ;
time = F_55 ( 0 , 0 ) ;
time = F_56 ( time , F_57 ( V_102 ) ) ;
F_58 ( & V_97 -> V_96 , time , V_100 ) ;
}
void F_59 ( struct F_45 * V_97 )
{
F_60 ( & V_97 -> V_96 ) ;
F_46 ( V_97 -> V_39 ) ;
}
static struct V_105 * F_61 ( unsigned int V_106 )
{
unsigned int V_107 = V_106 * sizeof( struct V_105 ) , V_108 ;
struct V_105 * V_109 ;
if ( V_107 <= V_110 )
V_109 = F_22 ( V_107 , V_60 ) ;
else
V_109 = (struct V_105 * )
F_62 ( V_60 , F_63 ( V_107 ) ) ;
if ( V_109 != NULL ) {
for ( V_108 = 0 ; V_108 < V_106 ; V_108 ++ )
F_64 ( & V_109 [ V_108 ] ) ;
}
return V_109 ;
}
static void F_65 ( struct V_105 * V_109 , unsigned int V_106 )
{
unsigned int V_107 = V_106 * sizeof( struct V_105 ) ;
if ( V_107 <= V_110 )
F_25 ( V_109 ) ;
else
F_66 ( ( unsigned long ) V_109 , F_63 ( V_107 ) ) ;
}
void F_67 ( struct V_30 * V_111 , struct V_112 * V_113 )
{
struct V_114 * V_45 ;
struct V_115 * V_106 , * V_9 ;
struct V_105 * V_116 , * V_117 ;
unsigned int V_118 , V_119 , V_120 ;
unsigned int V_108 , V_109 ;
if ( V_113 -> V_121 * 4 <= V_113 -> V_122 * 3 )
return;
V_118 = V_113 -> V_122 * 2 ;
V_119 = V_118 - 1 ;
V_116 = F_61 ( V_118 ) ;
if ( V_116 == NULL )
return;
V_117 = V_113 -> V_123 ;
V_120 = V_113 -> V_122 ;
F_68 ( V_111 ) ;
for ( V_108 = 0 ; V_108 < V_120 ; V_108 ++ ) {
F_69 (cl, n, next, &ohash[i], hnode) {
V_109 = F_70 ( V_45 -> V_44 , V_119 ) ;
F_71 ( & V_45 -> V_124 , & V_116 [ V_109 ] ) ;
}
}
V_113 -> V_123 = V_116 ;
V_113 -> V_122 = V_118 ;
V_113 -> V_125 = V_119 ;
F_72 ( V_111 ) ;
F_65 ( V_117 , V_120 ) ;
}
int F_73 ( struct V_112 * V_113 )
{
unsigned int V_107 = 4 ;
V_113 -> V_123 = F_61 ( V_107 ) ;
if ( V_113 -> V_123 == NULL )
return - V_76 ;
V_113 -> V_122 = V_107 ;
V_113 -> V_125 = V_107 - 1 ;
V_113 -> V_121 = 0 ;
return 0 ;
}
void F_74 ( struct V_112 * V_113 )
{
F_65 ( V_113 -> V_123 , V_113 -> V_122 ) ;
}
void F_75 ( struct V_112 * V_113 ,
struct V_114 * V_45 )
{
unsigned int V_109 ;
F_76 ( & V_45 -> V_124 ) ;
V_109 = F_70 ( V_45 -> V_44 , V_113 -> V_125 ) ;
F_71 ( & V_45 -> V_124 , & V_113 -> V_123 [ V_109 ] ) ;
V_113 -> V_121 ++ ;
}
void F_77 ( struct V_112 * V_113 ,
struct V_114 * V_45 )
{
F_78 ( & V_45 -> V_124 ) ;
V_113 -> V_121 -- ;
}
static T_1 F_79 ( struct V_40 * V_41 )
{
int V_108 = 0x8000 ;
static T_1 V_126 = F_80 ( 0x80000000U , 0 ) ;
do {
V_126 += F_80 ( 0x10000U , 0 ) ;
if ( V_126 == F_80 ( V_36 , 0 ) )
V_126 = F_80 ( 0x80000000U , 0 ) ;
if ( ! F_12 ( V_41 , V_126 ) )
return V_126 ;
F_81 () ;
} while ( -- V_108 > 0 );
return 0 ;
}
void F_82 ( struct V_30 * V_111 , unsigned int V_106 )
{
const struct V_18 * V_19 ;
unsigned long V_45 ;
T_1 V_127 ;
if ( V_106 == 0 )
return;
while ( ( V_127 = V_111 -> V_35 ) ) {
if ( F_83 ( V_127 ) == F_83 ( V_128 ) )
return;
V_111 = F_12 ( F_9 ( V_111 ) , F_83 ( V_127 ) ) ;
if ( V_111 == NULL ) {
F_84 ( V_127 != V_36 ) ;
return;
}
V_19 = V_111 -> V_46 -> V_17 ;
if ( V_19 -> V_129 ) {
V_45 = V_19 -> V_20 ( V_111 , V_127 ) ;
V_19 -> V_129 ( V_111 , V_45 ) ;
V_19 -> V_21 ( V_111 , V_45 ) ;
}
V_111 -> V_3 . V_130 -= V_106 ;
}
}
static void F_85 ( struct V_131 * V_131 , struct V_81 * V_82 ,
struct V_132 * V_106 , T_1 V_133 ,
struct V_30 * V_134 , struct V_30 * V_135 )
{
if ( V_135 || V_134 )
F_86 ( V_131 , V_82 , V_106 , V_133 , V_134 , V_135 ) ;
if ( V_134 )
F_87 ( V_134 ) ;
}
static int F_88 ( struct V_40 * V_41 , struct V_30 * V_35 ,
struct V_81 * V_82 , struct V_132 * V_106 , T_1 V_44 ,
struct V_30 * V_135 , struct V_30 * V_134 )
{
struct V_30 * V_3 = V_134 ;
struct V_131 * V_131 = F_89 ( V_41 ) ;
int V_28 = 0 ;
if ( V_35 == NULL ) {
unsigned int V_108 , V_136 , V_137 ;
V_137 = 0 ;
V_136 = V_41 -> V_138 ;
if ( ( V_3 && V_3 -> V_33 & V_37 ) ||
( V_135 && V_135 -> V_33 & V_37 ) ) {
V_136 = 1 ;
V_137 = 1 ;
if ( ! F_13 ( V_41 ) )
return - V_29 ;
}
if ( V_41 -> V_33 & V_139 )
F_90 ( V_41 ) ;
if ( V_135 && V_135 -> V_46 -> V_140 ) {
V_135 -> V_46 -> V_140 ( V_135 ) ;
V_136 = 0 ;
}
for ( V_108 = 0 ; V_108 < V_136 ; V_108 ++ ) {
struct V_141 * V_142 = F_13 ( V_41 ) ;
if ( ! V_137 )
V_142 = F_91 ( V_41 , V_108 ) ;
V_134 = F_92 ( V_142 , V_135 ) ;
if ( V_135 && V_108 > 0 )
F_93 ( & V_135 -> V_57 ) ;
if ( ! V_137 )
F_87 ( V_134 ) ;
}
if ( ! V_137 ) {
F_85 ( V_131 , V_82 , V_106 , V_44 ,
V_41 -> V_39 , V_135 ) ;
if ( V_135 && ! V_135 -> V_46 -> V_140 )
F_93 ( & V_135 -> V_57 ) ;
V_41 -> V_39 = V_135 ? : & V_143 ;
} else {
F_85 ( V_131 , V_82 , V_106 , V_44 , V_134 , V_135 ) ;
}
if ( V_41 -> V_33 & V_139 )
F_94 ( V_41 ) ;
} else {
const struct V_18 * V_19 = V_35 -> V_46 -> V_17 ;
V_28 = - V_144 ;
if ( V_19 && V_19 -> V_145 ) {
unsigned long V_45 = V_19 -> V_20 ( V_35 , V_44 ) ;
if ( V_45 ) {
V_28 = V_19 -> V_145 ( V_35 , V_45 , V_135 , & V_134 ) ;
V_19 -> V_21 ( V_35 , V_45 ) ;
} else
V_28 = - V_29 ;
}
if ( ! V_28 )
F_85 ( V_131 , V_82 , V_106 , V_44 , V_134 , V_135 ) ;
}
return V_28 ;
}
static struct V_30 *
F_95 ( struct V_40 * V_41 , struct V_141 * V_142 ,
struct V_30 * V_43 , T_1 V_35 , T_1 V_32 ,
struct V_47 * * V_146 , int * V_147 )
{
int V_28 ;
struct V_47 * V_48 = V_146 [ V_148 ] ;
struct V_30 * V_111 ;
struct V_1 * V_46 ;
struct V_63 * V_67 ;
V_46 = F_15 ( V_48 ) ;
#ifdef F_96
if ( V_46 == NULL && V_48 != NULL ) {
char V_149 [ V_150 ] ;
if ( F_97 ( V_149 , V_48 , V_150 ) < V_150 ) {
F_98 () ;
F_99 ( L_2 , V_149 ) ;
F_100 () ;
V_46 = F_15 ( V_48 ) ;
if ( V_46 != NULL ) {
F_101 ( V_46 -> V_49 ) ;
V_28 = - V_151 ;
goto V_152;
}
}
}
#endif
V_28 = - V_29 ;
if ( V_46 == NULL )
goto V_152;
V_111 = F_102 ( V_142 , V_46 ) ;
if ( F_103 ( V_111 ) ) {
V_28 = F_104 ( V_111 ) ;
goto V_153;
}
V_111 -> V_35 = V_35 ;
if ( V_32 == V_128 ) {
V_111 -> V_33 |= V_37 ;
V_32 = F_80 ( V_128 , 0 ) ;
F_105 ( F_106 ( V_111 ) , & V_154 ) ;
} else {
if ( V_32 == 0 ) {
V_32 = F_79 ( V_41 ) ;
V_28 = - V_76 ;
if ( V_32 == 0 )
goto V_155;
}
F_105 ( F_106 ( V_111 ) , & V_156 ) ;
}
V_111 -> V_32 = V_32 ;
if ( ! V_46 -> V_157 || ( V_28 = V_46 -> V_157 ( V_111 , V_146 [ V_158 ] ) ) == 0 ) {
if ( V_146 [ V_84 ] ) {
V_67 = F_26 ( V_146 [ V_84 ] ) ;
if ( F_103 ( V_67 ) ) {
V_28 = F_104 ( V_67 ) ;
goto V_159;
}
F_107 ( V_111 -> V_67 , V_67 ) ;
}
if ( V_146 [ V_160 ] ) {
T_5 * V_161 ;
V_28 = - V_144 ;
if ( V_111 -> V_33 & V_162 )
goto V_159;
if ( ( V_111 -> V_35 != V_36 ) &&
! ( V_111 -> V_33 & V_37 ) &&
( ! V_43 || ! ( V_43 -> V_33 & V_162 ) ) )
V_161 = F_108 ( V_111 ) ;
else
V_161 = F_106 ( V_111 ) ;
V_28 = F_109 ( & V_111 -> V_163 , & V_111 -> V_164 ,
V_161 , V_146 [ V_160 ] ) ;
if ( V_28 )
goto V_159;
}
F_7 ( V_111 ) ;
return V_111 ;
}
V_155:
F_110 ( V_41 ) ;
F_25 ( ( char * ) V_111 - V_111 -> V_165 ) ;
V_153:
F_101 ( V_46 -> V_49 ) ;
V_152:
* V_147 = V_28 ;
return NULL ;
V_159:
F_33 ( F_111 ( V_111 -> V_67 ) ) ;
if ( V_46 -> V_166 )
V_46 -> V_166 ( V_111 ) ;
goto V_155;
}
static int F_112 ( struct V_30 * V_111 , struct V_47 * * V_146 )
{
struct V_63 * V_167 , * V_67 = NULL ;
int V_28 = 0 ;
if ( V_146 [ V_158 ] ) {
if ( V_111 -> V_46 -> V_168 == NULL )
return - V_27 ;
V_28 = V_111 -> V_46 -> V_168 ( V_111 , V_146 [ V_158 ] ) ;
if ( V_28 )
return V_28 ;
}
if ( V_146 [ V_84 ] ) {
V_67 = F_26 ( V_146 [ V_84 ] ) ;
if ( F_103 ( V_67 ) )
return F_104 ( V_67 ) ;
}
V_167 = F_111 ( V_111 -> V_67 ) ;
F_107 ( V_111 -> V_67 , V_67 ) ;
F_33 ( V_167 ) ;
if ( V_146 [ V_160 ] ) {
if ( V_111 -> V_33 & V_162 )
goto V_11;
F_113 ( & V_111 -> V_163 , & V_111 -> V_164 ,
F_108 ( V_111 ) ,
V_146 [ V_160 ] ) ;
}
V_11:
return 0 ;
}
static int F_114 ( struct V_30 * V_3 , struct V_30 * V_43 , int V_169 )
{
struct V_170 V_171 ;
if ( V_3 -> V_46 -> V_17 == NULL )
return 0 ;
V_171 . V_172 . V_173 = V_171 . V_172 . V_174 = V_171 . V_172 . V_175 = 0 ;
V_171 . V_172 . V_176 = V_177 ;
V_171 . V_169 = V_169 ;
V_171 . V_43 = V_43 ;
V_3 -> V_46 -> V_17 -> V_22 ( V_3 , & V_171 . V_172 ) ;
return V_171 . V_172 . V_173 ? - V_178 : 0 ;
}
static int
V_177 ( struct V_30 * V_3 , unsigned long V_45 , struct V_179 * V_172 )
{
struct V_30 * V_23 ;
const struct V_18 * V_19 = V_3 -> V_46 -> V_17 ;
struct V_170 * V_171 = (struct V_170 * ) V_172 ;
V_23 = V_19 -> V_23 ( V_3 , V_45 ) ;
if ( V_23 ) {
if ( V_23 == V_171 -> V_43 || V_171 -> V_169 > 7 )
return - V_178 ;
return F_114 ( V_23 , V_171 -> V_43 , V_171 -> V_169 + 1 ) ;
}
return 0 ;
}
static int F_115 ( struct V_81 * V_82 , struct V_132 * V_106 , void * V_171 )
{
struct V_131 * V_131 = F_116 ( V_82 -> V_180 ) ;
struct V_181 * V_182 = F_117 ( V_106 ) ;
struct V_47 * V_146 [ V_183 + 1 ] ;
struct V_40 * V_41 ;
T_1 V_133 = V_182 -> V_184 ;
struct V_30 * V_3 = NULL ;
struct V_30 * V_43 = NULL ;
int V_28 ;
V_41 = F_118 ( V_131 , V_182 -> V_185 ) ;
if ( ! V_41 )
return - V_186 ;
V_28 = F_119 ( V_106 , sizeof( * V_182 ) , V_146 , V_183 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_133 ) {
if ( V_133 != V_36 ) {
if ( F_83 ( V_133 ) != F_83 ( V_128 ) ) {
V_43 = F_12 ( V_41 , F_83 ( V_133 ) ) ;
if ( ! V_43 )
return - V_29 ;
V_3 = F_14 ( V_43 , V_133 ) ;
} else if ( F_13 ( V_41 ) ) {
V_3 = F_13 ( V_41 ) -> V_42 ;
}
} else {
V_3 = V_41 -> V_39 ;
}
if ( ! V_3 )
return - V_29 ;
if ( V_182 -> V_187 && V_3 -> V_32 != V_182 -> V_187 )
return - V_27 ;
} else {
V_3 = F_12 ( V_41 , V_182 -> V_187 ) ;
if ( ! V_3 )
return - V_29 ;
}
if ( V_146 [ V_148 ] && F_17 ( V_146 [ V_148 ] , V_3 -> V_46 -> V_10 ) )
return - V_27 ;
if ( V_106 -> V_188 == V_189 ) {
if ( ! V_133 )
return - V_27 ;
if ( V_3 -> V_32 == 0 )
return - V_29 ;
V_28 = F_88 ( V_41 , V_43 , V_82 , V_106 , V_133 , NULL , V_3 ) ;
if ( V_28 != 0 )
return V_28 ;
} else {
F_86 ( V_131 , V_82 , V_106 , V_133 , NULL , V_3 ) ;
}
return 0 ;
}
static int F_120 ( struct V_81 * V_82 , struct V_132 * V_106 , void * V_171 )
{
struct V_131 * V_131 = F_116 ( V_82 -> V_180 ) ;
struct V_181 * V_182 ;
struct V_47 * V_146 [ V_183 + 1 ] ;
struct V_40 * V_41 ;
T_1 V_133 ;
struct V_30 * V_3 , * V_43 ;
int V_28 ;
V_190:
V_182 = F_117 ( V_106 ) ;
V_133 = V_182 -> V_184 ;
V_3 = V_43 = NULL ;
V_41 = F_118 ( V_131 , V_182 -> V_185 ) ;
if ( ! V_41 )
return - V_186 ;
V_28 = F_119 ( V_106 , sizeof( * V_182 ) , V_146 , V_183 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_133 ) {
if ( V_133 != V_36 ) {
if ( V_133 != V_128 ) {
V_43 = F_12 ( V_41 , F_83 ( V_133 ) ) ;
if ( ! V_43 )
return - V_29 ;
V_3 = F_14 ( V_43 , V_133 ) ;
} else if ( F_121 ( V_41 ) ) {
V_3 = F_13 ( V_41 ) -> V_42 ;
}
} else {
V_3 = V_41 -> V_39 ;
}
if ( V_3 && V_3 -> V_32 == 0 )
V_3 = NULL ;
if ( ! V_3 || ! V_182 -> V_187 || V_3 -> V_32 != V_182 -> V_187 ) {
if ( V_182 -> V_187 ) {
if ( V_3 && ! ( V_106 -> V_191 & V_192 ) )
return - V_6 ;
if ( F_122 ( V_182 -> V_187 ) )
return - V_27 ;
V_3 = F_12 ( V_41 , V_182 -> V_187 ) ;
if ( ! V_3 )
goto V_193;
if ( V_106 -> V_191 & V_194 )
return - V_6 ;
if ( V_146 [ V_148 ] && F_17 ( V_146 [ V_148 ] , V_3 -> V_46 -> V_10 ) )
return - V_27 ;
if ( V_3 == V_43 ||
( V_43 && F_114 ( V_3 , V_43 , 0 ) ) )
return - V_178 ;
F_93 ( & V_3 -> V_57 ) ;
goto V_145;
} else {
if ( ! V_3 )
goto V_193;
if ( ( V_106 -> V_191 & V_195 ) &&
( V_106 -> V_191 & V_192 ) &&
( ( V_106 -> V_191 & V_194 ) ||
( V_146 [ V_148 ] &&
F_17 ( V_146 [ V_148 ] , V_3 -> V_46 -> V_10 ) ) ) )
goto V_193;
}
}
} else {
if ( ! V_182 -> V_187 )
return - V_27 ;
V_3 = F_12 ( V_41 , V_182 -> V_187 ) ;
}
if ( V_3 == NULL )
return - V_29 ;
if ( V_106 -> V_191 & V_194 )
return - V_6 ;
if ( V_146 [ V_148 ] && F_17 ( V_146 [ V_148 ] , V_3 -> V_46 -> V_10 ) )
return - V_27 ;
V_28 = F_112 ( V_3 , V_146 ) ;
if ( V_28 == 0 )
F_86 ( V_131 , V_82 , V_106 , V_133 , NULL , V_3 ) ;
return V_28 ;
V_193:
if ( ! ( V_106 -> V_191 & V_195 ) )
return - V_29 ;
if ( V_133 == V_128 ) {
if ( F_13 ( V_41 ) )
V_3 = F_95 ( V_41 , F_13 ( V_41 ) , V_43 ,
V_182 -> V_184 , V_182 -> V_184 ,
V_146 , & V_28 ) ;
else
V_28 = - V_29 ;
} else {
struct V_141 * V_142 ;
if ( V_43 && V_43 -> V_46 -> V_17 && V_43 -> V_46 -> V_17 -> V_196 )
V_142 = V_43 -> V_46 -> V_17 -> V_196 ( V_43 , V_182 ) ;
else if ( V_43 )
V_142 = V_43 -> V_142 ;
else
V_142 = F_91 ( V_41 , 0 ) ;
V_3 = F_95 ( V_41 , V_142 , V_43 ,
V_182 -> V_184 , V_182 -> V_187 ,
V_146 , & V_28 ) ;
}
if ( V_3 == NULL ) {
if ( V_28 == - V_151 )
goto V_190;
return V_28 ;
}
V_145:
V_28 = F_88 ( V_41 , V_43 , V_82 , V_106 , V_133 , V_3 , NULL ) ;
if ( V_28 ) {
if ( V_3 )
F_87 ( V_3 ) ;
return V_28 ;
}
return 0 ;
}
static int F_123 ( struct V_81 * V_82 , struct V_30 * V_3 , T_1 V_133 ,
T_1 V_197 , T_1 V_198 , T_2 V_33 , int V_199 )
{
struct V_181 * V_182 ;
struct V_132 * V_200 ;
unsigned char * V_201 = F_124 ( V_82 ) ;
struct V_202 V_203 ;
struct V_63 * V_67 ;
V_200 = F_125 ( V_82 , V_197 , V_198 , V_199 , sizeof( * V_182 ) , V_33 ) ;
V_182 = F_117 ( V_200 ) ;
V_182 -> V_204 = V_205 ;
V_182 -> V_206 = 0 ;
V_182 -> V_207 = 0 ;
V_182 -> V_185 = F_9 ( V_3 ) -> V_208 ;
V_182 -> V_184 = V_133 ;
V_182 -> V_187 = V_3 -> V_32 ;
V_182 -> V_209 = F_126 ( & V_3 -> V_57 ) ;
if ( F_127 ( V_82 , V_148 , V_3 -> V_46 -> V_10 ) )
goto V_85;
if ( V_3 -> V_46 -> V_210 && V_3 -> V_46 -> V_210 ( V_3 , V_82 ) < 0 )
goto V_85;
V_3 -> V_211 . V_130 = V_3 -> V_3 . V_130 ;
V_67 = F_111 ( V_3 -> V_67 ) ;
if ( V_67 && F_35 ( V_82 , V_67 ) < 0 )
goto V_85;
if ( F_128 ( V_82 , V_212 , V_213 , V_214 ,
F_108 ( V_3 ) , & V_203 ) < 0 )
goto V_85;
if ( V_3 -> V_46 -> V_215 && V_3 -> V_46 -> V_215 ( V_3 , & V_203 ) < 0 )
goto V_85;
if ( F_129 ( & V_203 , & V_3 -> V_163 ) < 0 ||
F_130 ( & V_203 , & V_3 -> V_163 , & V_3 -> V_164 ) < 0 ||
F_131 ( & V_203 , & V_3 -> V_211 ) < 0 )
goto V_85;
if ( F_132 ( & V_203 ) < 0 )
goto V_85;
V_200 -> V_216 = F_124 ( V_82 ) - V_201 ;
return V_82 -> V_86 ;
V_217:
V_85:
F_133 ( V_82 , V_201 ) ;
return - 1 ;
}
static bool F_134 ( struct V_30 * V_3 )
{
return ( V_3 -> V_33 & V_34 ) ? true : false ;
}
static int F_86 ( struct V_131 * V_131 , struct V_81 * V_218 ,
struct V_132 * V_106 , T_1 V_133 ,
struct V_30 * V_134 , struct V_30 * V_135 )
{
struct V_81 * V_82 ;
T_1 V_197 = V_218 ? F_135 ( V_218 ) . V_197 : 0 ;
V_82 = F_136 ( V_219 , V_60 ) ;
if ( ! V_82 )
return - V_220 ;
if ( V_134 && ! F_134 ( V_134 ) ) {
if ( F_123 ( V_82 , V_134 , V_133 , V_197 , V_106 -> V_221 ,
0 , V_189 ) < 0 )
goto V_152;
}
if ( V_135 && ! F_134 ( V_135 ) ) {
if ( F_123 ( V_82 , V_135 , V_133 , V_197 , V_106 -> V_221 ,
V_134 ? V_192 : 0 , V_222 ) < 0 )
goto V_152;
}
if ( V_82 -> V_86 )
return F_137 ( V_82 , V_131 , V_197 , V_223 ,
V_106 -> V_191 & V_224 ) ;
V_152:
F_138 ( V_82 ) ;
return - V_27 ;
}
static int F_139 ( struct V_30 * V_31 , struct V_81 * V_82 ,
struct V_225 * V_226 ,
int * V_227 , int V_228 )
{
int V_229 = 0 , V_230 = * V_227 ;
struct V_30 * V_3 ;
if ( ! V_31 )
return 0 ;
V_3 = V_31 ;
if ( V_230 < V_228 ) {
V_230 ++ ;
} else {
if ( ! F_134 ( V_3 ) &&
F_123 ( V_82 , V_3 , V_3 -> V_35 , F_135 ( V_226 -> V_82 ) . V_197 ,
V_226 -> V_200 -> V_221 , V_231 , V_222 ) <= 0 )
goto V_232;
V_230 ++ ;
}
F_6 (q, &root->list, list) {
if ( V_230 < V_228 ) {
V_230 ++ ;
continue;
}
if ( ! F_134 ( V_3 ) &&
F_123 ( V_82 , V_3 , V_3 -> V_35 , F_135 ( V_226 -> V_82 ) . V_197 ,
V_226 -> V_200 -> V_221 , V_231 , V_222 ) <= 0 )
goto V_232;
V_230 ++ ;
}
V_11:
* V_227 = V_230 ;
return V_229 ;
V_232:
V_229 = - 1 ;
goto V_11;
}
static int F_140 ( struct V_81 * V_82 , struct V_225 * V_226 )
{
struct V_131 * V_131 = F_116 ( V_82 -> V_180 ) ;
int V_233 , V_230 ;
int V_234 , V_228 ;
struct V_40 * V_41 ;
V_234 = V_226 -> args [ 0 ] ;
V_228 = V_230 = V_226 -> args [ 1 ] ;
F_141 () ;
V_233 = 0 ;
F_142 (net, dev) {
struct V_141 * V_142 ;
if ( V_233 < V_234 )
goto V_235;
if ( V_233 > V_234 )
V_228 = 0 ;
V_230 = 0 ;
if ( F_139 ( V_41 -> V_39 , V_82 , V_226 , & V_230 , V_228 ) < 0 )
goto V_232;
V_142 = F_13 ( V_41 ) ;
if ( V_142 &&
F_139 ( V_142 -> V_42 , V_82 , V_226 ,
& V_230 , V_228 ) < 0 )
goto V_232;
V_235:
V_233 ++ ;
}
V_232:
F_143 () ;
V_226 -> args [ 0 ] = V_233 ;
V_226 -> args [ 1 ] = V_230 ;
return V_82 -> V_86 ;
}
static int F_144 ( struct V_81 * V_82 , struct V_132 * V_106 , void * V_171 )
{
struct V_131 * V_131 = F_116 ( V_82 -> V_180 ) ;
struct V_181 * V_182 = F_117 ( V_106 ) ;
struct V_47 * V_146 [ V_183 + 1 ] ;
struct V_40 * V_41 ;
struct V_30 * V_3 = NULL ;
const struct V_18 * V_19 ;
unsigned long V_45 = 0 ;
unsigned long V_236 ;
T_1 V_197 = V_182 -> V_184 ;
T_1 V_133 = V_182 -> V_187 ;
T_1 V_237 = F_83 ( V_133 ) ;
int V_28 ;
V_41 = F_118 ( V_131 , V_182 -> V_185 ) ;
if ( ! V_41 )
return - V_186 ;
V_28 = F_119 ( V_106 , sizeof( * V_182 ) , V_146 , V_183 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_197 != V_36 ) {
T_1 V_238 = F_83 ( V_197 ) ;
if ( V_237 && V_238 ) {
if ( V_237 != V_238 )
return - V_27 ;
} else if ( V_238 ) {
V_237 = V_238 ;
} else if ( V_237 == 0 )
V_237 = V_41 -> V_39 -> V_32 ;
if ( V_197 )
V_197 = F_80 ( V_237 , V_197 ) ;
} else {
if ( V_237 == 0 )
V_237 = V_41 -> V_39 -> V_32 ;
}
V_3 = F_12 ( V_41 , V_237 ) ;
if ( ! V_3 )
return - V_29 ;
V_19 = V_3 -> V_46 -> V_17 ;
if ( V_19 == NULL )
return - V_27 ;
if ( V_133 == 0 ) {
if ( V_197 == V_36 )
V_133 = V_237 ;
} else
V_133 = F_80 ( V_237 , V_133 ) ;
if ( V_133 )
V_45 = V_19 -> V_20 ( V_3 , V_133 ) ;
if ( V_45 == 0 ) {
V_28 = - V_29 ;
if ( V_106 -> V_188 != V_239 ||
! ( V_106 -> V_191 & V_195 ) )
goto V_11;
} else {
switch ( V_106 -> V_188 ) {
case V_239 :
V_28 = - V_6 ;
if ( V_106 -> V_191 & V_194 )
goto V_11;
break;
case V_240 :
V_28 = - V_144 ;
if ( V_19 -> V_241 )
V_28 = V_19 -> V_241 ( V_3 , V_45 ) ;
if ( V_28 == 0 )
F_145 ( V_131 , V_82 , V_106 , V_3 , V_45 , V_240 ) ;
goto V_11;
case V_242 :
V_28 = F_145 ( V_131 , V_82 , V_106 , V_3 , V_45 , V_239 ) ;
goto V_11;
default:
V_28 = - V_27 ;
goto V_11;
}
}
V_236 = V_45 ;
V_28 = - V_144 ;
if ( V_19 -> V_168 )
V_28 = V_19 -> V_168 ( V_3 , V_133 , V_197 , V_146 , & V_236 ) ;
if ( V_28 == 0 )
F_145 ( V_131 , V_82 , V_106 , V_3 , V_236 , V_239 ) ;
V_11:
if ( V_45 )
V_19 -> V_21 ( V_3 , V_45 ) ;
return V_28 ;
}
static int F_146 ( struct V_81 * V_82 , struct V_30 * V_3 ,
unsigned long V_45 ,
T_1 V_197 , T_1 V_198 , T_2 V_33 , int V_199 )
{
struct V_181 * V_182 ;
struct V_132 * V_200 ;
unsigned char * V_201 = F_124 ( V_82 ) ;
struct V_202 V_203 ;
const struct V_18 * V_17 = V_3 -> V_46 -> V_17 ;
V_200 = F_125 ( V_82 , V_197 , V_198 , V_199 , sizeof( * V_182 ) , V_33 ) ;
V_182 = F_117 ( V_200 ) ;
V_182 -> V_204 = V_205 ;
V_182 -> V_206 = 0 ;
V_182 -> V_207 = 0 ;
V_182 -> V_185 = F_9 ( V_3 ) -> V_208 ;
V_182 -> V_184 = V_3 -> V_32 ;
V_182 -> V_187 = V_3 -> V_32 ;
V_182 -> V_209 = 0 ;
if ( F_127 ( V_82 , V_148 , V_3 -> V_46 -> V_10 ) )
goto V_85;
if ( V_17 -> V_210 && V_17 -> V_210 ( V_3 , V_45 , V_82 , V_182 ) < 0 )
goto V_85;
if ( F_128 ( V_82 , V_212 , V_213 , V_214 ,
F_108 ( V_3 ) , & V_203 ) < 0 )
goto V_85;
if ( V_17 -> V_215 && V_17 -> V_215 ( V_3 , V_45 , & V_203 ) < 0 )
goto V_85;
if ( F_132 ( & V_203 ) < 0 )
goto V_85;
V_200 -> V_216 = F_124 ( V_82 ) - V_201 ;
return V_82 -> V_86 ;
V_217:
V_85:
F_133 ( V_82 , V_201 ) ;
return - 1 ;
}
static int F_145 ( struct V_131 * V_131 , struct V_81 * V_218 ,
struct V_132 * V_106 , struct V_30 * V_3 ,
unsigned long V_45 , int V_199 )
{
struct V_81 * V_82 ;
T_1 V_197 = V_218 ? F_135 ( V_218 ) . V_197 : 0 ;
V_82 = F_136 ( V_219 , V_60 ) ;
if ( ! V_82 )
return - V_220 ;
if ( F_146 ( V_82 , V_3 , V_45 , V_197 , V_106 -> V_221 , 0 , V_199 ) < 0 ) {
F_138 ( V_82 ) ;
return - V_27 ;
}
return F_137 ( V_82 , V_131 , V_197 , V_223 ,
V_106 -> V_191 & V_224 ) ;
}
static int F_147 ( struct V_30 * V_3 , unsigned long V_45 , struct V_179 * V_171 )
{
struct V_243 * V_244 = (struct V_243 * ) V_171 ;
return F_146 ( V_244 -> V_82 , V_3 , V_45 , F_135 ( V_244 -> V_226 -> V_82 ) . V_197 ,
V_244 -> V_226 -> V_200 -> V_221 , V_231 , V_239 ) ;
}
static int F_148 ( struct V_30 * V_3 , struct V_81 * V_82 ,
struct V_181 * V_182 , struct V_225 * V_226 ,
int * V_245 , int V_246 )
{
struct V_243 V_171 ;
if ( F_134 ( V_3 ) ||
* V_245 < V_246 || ! V_3 -> V_46 -> V_17 ||
( V_182 -> V_184 &&
F_83 ( V_182 -> V_184 ) != V_3 -> V_32 ) ) {
( * V_245 ) ++ ;
return 0 ;
}
if ( * V_245 > V_246 )
memset ( & V_226 -> args [ 1 ] , 0 , sizeof( V_226 -> args ) - sizeof( V_226 -> args [ 0 ] ) ) ;
V_171 . V_172 . V_176 = F_147 ;
V_171 . V_82 = V_82 ;
V_171 . V_226 = V_226 ;
V_171 . V_172 . V_173 = 0 ;
V_171 . V_172 . V_174 = V_226 -> args [ 1 ] ;
V_171 . V_172 . V_175 = 0 ;
V_3 -> V_46 -> V_17 -> V_22 ( V_3 , & V_171 . V_172 ) ;
V_226 -> args [ 1 ] = V_171 . V_172 . V_175 ;
if ( V_171 . V_172 . V_173 )
return - 1 ;
( * V_245 ) ++ ;
return 0 ;
}
static int F_149 ( struct V_30 * V_31 , struct V_81 * V_82 ,
struct V_181 * V_182 , struct V_225 * V_226 ,
int * V_245 , int V_246 )
{
struct V_30 * V_3 ;
if ( ! V_31 )
return 0 ;
if ( F_148 ( V_31 , V_82 , V_182 , V_226 , V_245 , V_246 ) < 0 )
return - 1 ;
F_6 (q, &root->list, list) {
if ( F_148 ( V_3 , V_82 , V_182 , V_226 , V_245 , V_246 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_150 ( struct V_81 * V_82 , struct V_225 * V_226 )
{
struct V_181 * V_182 = (struct V_181 * ) F_117 ( V_226 -> V_200 ) ;
struct V_131 * V_131 = F_116 ( V_82 -> V_180 ) ;
struct V_141 * V_142 ;
struct V_40 * V_41 ;
int V_247 , V_246 ;
if ( V_226 -> V_200 -> V_216 < F_151 ( sizeof( * V_182 ) ) )
return 0 ;
V_41 = F_152 ( V_131 , V_182 -> V_185 ) ;
if ( ! V_41 )
return 0 ;
V_246 = V_226 -> args [ 0 ] ;
V_247 = 0 ;
if ( F_149 ( V_41 -> V_39 , V_82 , V_182 , V_226 , & V_247 , V_246 ) < 0 )
goto V_232;
V_142 = F_13 ( V_41 ) ;
if ( V_142 &&
F_149 ( V_142 -> V_42 , V_82 , V_182 , V_226 ,
& V_247 , V_246 ) < 0 )
goto V_232;
V_232:
V_226 -> args [ 0 ] = V_247 ;
F_110 ( V_41 ) ;
return V_82 -> V_86 ;
}
int F_153 ( struct V_81 * V_82 , const struct V_248 * V_249 ,
struct V_250 * V_251 )
{
T_6 V_252 = V_82 -> V_252 ;
int V_28 ;
for (; V_249 ; V_249 = V_249 -> V_9 ) {
if ( V_249 -> V_252 != V_252 &&
V_249 -> V_252 != F_154 ( V_253 ) )
continue;
V_28 = V_249 -> V_254 ( V_82 , V_249 , V_251 ) ;
if ( V_28 >= 0 ) {
#ifdef F_155
if ( V_28 != V_255 && V_82 -> V_256 )
V_82 -> V_256 = F_156 ( V_82 -> V_256 , 0 ) ;
#endif
return V_28 ;
}
}
return - 1 ;
}
int F_157 ( struct V_81 * V_82 , const struct V_248 * V_249 ,
struct V_250 * V_251 )
{
int V_28 = 0 ;
#ifdef F_155
const struct V_248 * V_257 = V_249 ;
V_258:
#endif
V_28 = F_153 ( V_82 , V_249 , V_251 ) ;
#ifdef F_155
if ( V_28 == V_255 ) {
T_1 V_259 = F_158 ( V_82 -> V_256 ) ;
V_249 = V_257 ;
if ( V_259 ++ >= V_260 ) {
F_159 ( L_3 ,
V_249 -> V_3 -> V_46 -> V_10 ,
V_249 -> V_261 & 0xffff ,
F_160 ( V_249 -> V_252 ) ) ;
return V_262 ;
}
V_82 -> V_256 = F_156 ( V_82 -> V_256 , V_259 ) ;
goto V_258;
}
#endif
return V_28 ;
}
void F_161 ( struct V_248 * V_249 )
{
V_249 -> V_46 -> V_166 ( V_249 ) ;
F_101 ( V_249 -> V_46 -> V_49 ) ;
F_25 ( V_249 ) ;
}
void F_162 ( struct V_248 * * V_263 )
{
struct V_248 * V_249 ;
while ( ( V_249 = * V_263 ) != NULL ) {
* V_263 = V_249 -> V_9 ;
F_161 ( V_249 ) ;
}
}
static int F_163 ( struct V_264 * V_198 , void * V_265 )
{
struct V_266 V_267 ;
F_164 ( V_99 , & V_267 ) ;
F_165 ( V_198 , L_4 ,
( T_1 ) V_268 , ( T_1 ) F_57 ( 1 ) ,
1000000 ,
( T_1 ) V_269 / ( T_1 ) F_166 ( F_167 ( V_267 ) ) ) ;
return 0 ;
}
static int F_168 ( struct V_270 * V_270 , struct V_271 * V_271 )
{
return F_169 ( V_271 , F_163 , NULL ) ;
}
static int T_7 F_170 ( struct V_131 * V_131 )
{
struct V_272 * V_273 ;
V_273 = F_171 ( V_131 , L_5 , 0 , & V_274 ) ;
if ( V_273 == NULL )
return - V_76 ;
return 0 ;
}
static void T_8 F_172 ( struct V_131 * V_131 )
{
F_173 ( V_131 , L_5 ) ;
}
static int T_7 F_170 ( struct V_131 * V_131 )
{
return 0 ;
}
static void T_8 F_172 ( struct V_131 * V_131 )
{
}
static int T_9 F_174 ( void )
{
int V_28 ;
V_28 = F_175 ( & V_275 ) ;
if ( V_28 ) {
F_176 ( L_6
L_7 ) ;
return V_28 ;
}
F_1 ( & V_276 ) ;
F_1 ( & V_277 ) ;
F_1 ( & V_278 ) ;
F_1 ( & V_279 ) ;
F_177 ( V_280 , V_222 , F_120 , NULL , NULL ) ;
F_177 ( V_280 , V_189 , F_115 , NULL , NULL ) ;
F_177 ( V_280 , V_281 , F_115 , F_140 , NULL ) ;
F_177 ( V_280 , V_239 , F_144 , NULL , NULL ) ;
F_177 ( V_280 , V_240 , F_144 , NULL , NULL ) ;
F_177 ( V_280 , V_242 , F_144 , F_150 , NULL ) ;
return 0 ;
}
