static int F_1 ( T_1 * V_1 )
{
unsigned int V_2 ;
V_2 = ( unsigned int ) F_2 ( V_1 , 1 , 0 ) ;
if ( V_2 <= ( unsigned int ) V_3 )
return ( int ) V_2 ;
F_3 ( V_1 ) ;
return - V_4 ;
}
static int F_4 ( T_1 * V_1 )
{
int V_2 ;
V_2 = F_5 ( V_1 ) ;
if ( V_2 >= 0 )
return V_2 ;
F_6 ( V_1 ) ;
return - V_4 ;
}
static void F_7 ( struct V_5 * V_6 )
{
}
static int F_8 ( struct V_7 * V_8 , T_2 V_9 )
{
struct V_10 * V_11 = V_8 -> V_12 -> V_13 ;
bool V_14 = false ;
if ( ( V_9 & V_15 ) && V_11 -> V_16 . V_17 )
return - V_18 ;
F_9 ( & V_11 -> V_19 ) ;
if ( F_10 ( V_20 , & V_11 -> V_21 ) )
V_14 = true ;
else
V_11 -> V_22 ++ ;
F_11 ( & V_11 -> V_19 ) ;
if ( V_14 )
return - V_23 ;
F_12 ( & V_24 , V_25 ) ;
( void ) F_13 ( & V_11 -> V_6 ) ;
F_14 ( V_8 , V_11 -> V_16 . V_17 ) ;
F_15 ( & V_24 ) ;
return 0 ;
}
static void F_16 ( struct V_26 * V_27 , T_2 V_9 )
{
struct V_10 * V_11 = V_27 -> V_13 ;
unsigned long V_28 ;
F_9 ( & V_11 -> V_19 ) ;
V_28 = V_11 -> V_22 -- ;
F_11 ( & V_11 -> V_19 ) ;
F_17 ( V_28 > 0 ) ;
F_12 ( & V_24 , V_25 ) ;
F_18 ( & V_11 -> V_6 ) ;
F_15 ( & V_24 ) ;
}
static struct V_29 * F_19 ( struct V_30 * V_31 )
{
struct V_29 * V_32 ;
int V_33 = - V_34 ;
F_20 ( L_1 , V_35 ) ;
V_32 = F_21 ( sizeof( struct V_29 ) , V_36 ) ;
if ( ! V_32 )
goto V_37;
F_22 ( & V_32 -> V_38 ) ;
F_23 ( & V_32 -> V_39 ) ;
F_12 ( & V_24 , V_25 ) ;
V_32 -> V_40 = F_24 ( V_31 , V_32 , 0 , 0 ) ;
if ( F_25 ( V_32 -> V_40 ) )
goto V_41;
V_31 = NULL ;
V_33 = F_26 ( V_32 -> V_40 ) ;
if ( V_33 < 0 )
goto V_42;
F_27 ( & V_43 ) ;
F_28 ( & V_32 -> V_39 , & V_44 ) ;
F_29 ( & V_43 ) ;
F_15 ( & V_24 ) ;
F_20 ( L_2 , V_35 , V_32 ) ;
return V_32 ;
V_42:
F_30 ( V_32 -> V_40 ) ;
V_41:
F_15 ( & V_24 ) ;
F_31 ( V_32 ) ;
V_37:
if ( V_31 )
F_32 ( V_31 ) ;
F_20 ( L_3 , V_35 , V_33 ) ;
return F_33 ( V_33 ) ;
}
static struct V_29 * F_34 ( struct V_29 * V_32 )
{
F_35 ( & V_32 -> V_38 ) ;
return V_32 ;
}
static struct V_29 * F_36 ( struct V_30 * V_31 )
{
struct V_29 * V_45 ;
bool V_46 = false ;
if ( V_31 -> V_21 & V_47 )
return NULL ;
F_27 ( & V_43 ) ;
F_37 (client_node, &rbd_client_list, node) {
if ( ! F_38 ( V_31 , V_45 -> V_40 ) ) {
F_34 ( V_45 ) ;
V_46 = true ;
break;
}
}
F_29 ( & V_43 ) ;
return V_46 ? V_45 : NULL ;
}
static int F_39 ( char * V_48 , void * V_49 )
{
struct V_50 * V_51 = V_49 ;
T_3 V_52 [ V_53 ] ;
int V_54 , V_55 , V_33 ;
V_54 = F_40 ( V_48 , V_56 , V_52 ) ;
if ( V_54 < 0 )
return - V_4 ;
if ( V_54 < V_57 ) {
V_33 = F_41 ( & V_52 [ 0 ] , & V_55 ) ;
if ( V_33 < 0 ) {
F_42 ( L_4
L_5 , V_48 ) ;
return V_33 ;
}
F_20 ( L_6 , V_54 , V_55 ) ;
} else if ( V_54 > V_57 && V_54 < V_58 ) {
F_20 ( L_7 , V_54 ,
V_52 [ 0 ] . V_59 ) ;
} else if ( V_54 > V_58 && V_54 < V_60 ) {
F_20 ( L_8 , V_54 ) ;
} else {
F_20 ( L_9 , V_54 ) ;
}
switch ( V_54 ) {
case V_61 :
V_51 -> V_17 = true ;
break;
case V_62 :
V_51 -> V_17 = false ;
break;
default:
F_17 ( false ) ;
break;
}
return 0 ;
}
static struct V_29 * F_43 ( struct V_30 * V_31 )
{
struct V_29 * V_32 ;
V_32 = F_36 ( V_31 ) ;
if ( V_32 )
F_32 ( V_31 ) ;
else
V_32 = F_19 ( V_31 ) ;
return V_32 ;
}
static void F_44 ( struct V_38 * V_38 )
{
struct V_29 * V_32 = F_45 ( V_38 , struct V_29 , V_38 ) ;
F_20 ( L_2 , V_35 , V_32 ) ;
F_27 ( & V_43 ) ;
F_46 ( & V_32 -> V_39 ) ;
F_29 ( & V_43 ) ;
F_30 ( V_32 -> V_40 ) ;
F_31 ( V_32 ) ;
}
static void F_47 ( struct V_29 * V_32 )
{
if ( V_32 )
F_48 ( & V_32 -> V_38 , F_44 ) ;
}
static bool F_49 ( T_4 V_63 )
{
return V_63 == 1 || V_63 == 2 ;
}
static bool F_50 ( struct V_64 * V_65 )
{
T_5 V_66 ;
T_4 V_67 ;
if ( memcmp ( & V_65 -> V_68 , V_69 , sizeof ( V_69 ) ) )
return false ;
if ( V_65 -> V_70 . V_71 < V_72 )
return false ;
if ( V_65 -> V_70 . V_71 > 8 * sizeof ( int ) - 1 )
return false ;
V_67 = F_51 ( V_65 -> V_67 ) ;
V_66 = V_73 - sizeof ( struct V_74 ) ;
if ( V_67 > V_66 / sizeof ( V_75 ) )
return false ;
V_66 -= V_67 * sizeof ( V_75 ) ;
if ( ( V_76 ) V_66 < F_52 ( V_65 -> V_77 ) )
return false ;
return true ;
}
static int F_53 ( struct V_10 * V_11 ,
struct V_64 * V_65 )
{
struct V_78 * V_79 = & V_11 -> V_79 ;
bool V_80 = V_79 -> V_81 == NULL ;
struct V_74 * V_82 ;
char * V_81 = NULL ;
char * V_83 = NULL ;
V_76 * V_84 = NULL ;
T_4 V_67 ;
T_5 V_66 ;
int V_33 = - V_34 ;
T_4 V_85 ;
if ( V_80 ) {
T_5 V_86 ;
V_86 = F_54 ( V_65 -> V_81 ,
sizeof ( V_65 -> V_81 ) ) ;
V_81 = F_21 ( V_86 + 1 , V_36 ) ;
if ( ! V_81 )
return - V_34 ;
memcpy ( V_81 , V_65 -> V_81 , V_86 ) ;
V_81 [ V_86 ] = '\0' ;
}
V_67 = F_51 ( V_65 -> V_67 ) ;
V_82 = F_55 ( V_67 , V_36 ) ;
if ( ! V_82 )
goto V_42;
V_82 -> V_87 = F_52 ( V_65 -> V_88 ) ;
if ( V_67 ) {
struct V_89 * V_90 ;
V_76 V_77 = F_52 ( V_65 -> V_77 ) ;
if ( V_77 > ( V_76 ) V_73 )
goto V_91;
V_83 = F_21 ( V_77 , V_36 ) ;
if ( ! V_83 )
goto V_42;
V_66 = V_67 * sizeof ( * V_79 -> V_84 ) ;
V_84 = F_21 ( V_66 , V_36 ) ;
if ( ! V_84 )
goto V_42;
memcpy ( V_83 , & V_65 -> V_90 [ V_67 ] , V_77 ) ;
V_90 = V_65 -> V_90 ;
for ( V_85 = 0 ; V_85 < V_67 ; V_85 ++ ) {
V_82 -> V_90 [ V_85 ] = F_52 ( V_90 [ V_85 ] . V_92 ) ;
V_84 [ V_85 ] = F_52 ( V_90 [ V_85 ] . V_93 ) ;
}
}
F_56 ( & V_11 -> V_94 ) ;
if ( V_80 ) {
V_79 -> V_81 = V_81 ;
V_79 -> V_95 = V_65 -> V_70 . V_71 ;
V_79 -> V_96 = V_65 -> V_70 . V_96 ;
V_79 -> V_97 = V_65 -> V_70 . V_97 ;
V_79 -> V_98 = 0 ;
V_79 -> V_99 = 0 ;
V_79 -> V_100 = 0 ;
} else {
F_57 ( V_79 -> V_82 ) ;
F_31 ( V_79 -> V_83 ) ;
F_31 ( V_79 -> V_84 ) ;
}
V_79 -> V_93 = F_52 ( V_65 -> V_93 ) ;
V_79 -> V_82 = V_82 ;
V_79 -> V_83 = V_83 ;
V_79 -> V_84 = V_84 ;
if ( V_11 -> V_101 -> V_102 == V_103 || V_80 )
if ( V_11 -> V_16 . V_66 != V_79 -> V_93 )
V_11 -> V_16 . V_66 = V_79 -> V_93 ;
F_58 ( & V_11 -> V_94 ) ;
return 0 ;
V_91:
V_33 = - V_104 ;
V_42:
F_31 ( V_84 ) ;
F_31 ( V_83 ) ;
F_57 ( V_82 ) ;
F_31 ( V_81 ) ;
return V_33 ;
}
static const char * F_59 ( struct V_10 * V_11 , T_4 V_105 )
{
const char * V_106 ;
F_17 ( V_105 < V_11 -> V_79 . V_82 -> V_107 ) ;
V_106 = V_11 -> V_79 . V_83 ;
while ( V_105 -- )
V_106 += strlen ( V_106 ) + 1 ;
return F_60 ( V_106 , V_36 ) ;
}
static int F_61 ( const void * V_108 , const void * V_109 )
{
V_76 V_110 = * ( V_76 * ) V_108 ;
V_76 V_111 = * ( V_76 * ) V_109 ;
if ( V_110 < V_111 )
return 1 ;
return V_110 == V_111 ? 0 : - 1 ;
}
static T_4 F_62 ( struct V_10 * V_11 , V_76 V_102 )
{
struct V_74 * V_82 = V_11 -> V_79 . V_82 ;
V_76 * V_46 ;
V_46 = bsearch ( & V_102 , & V_82 -> V_90 , V_82 -> V_107 ,
sizeof ( V_102 ) , F_61 ) ;
return V_46 ? ( T_4 ) ( V_46 - & V_82 -> V_90 [ 0 ] ) : V_112 ;
}
static const char * F_63 ( struct V_10 * V_11 ,
V_76 V_102 )
{
T_4 V_105 ;
V_105 = F_62 ( V_11 , V_102 ) ;
if ( V_105 == V_112 )
return NULL ;
return F_59 ( V_11 , V_105 ) ;
}
static const char * F_64 ( struct V_10 * V_11 , V_76 V_102 )
{
if ( V_102 == V_103 )
return V_113 ;
F_17 ( F_49 ( V_11 -> V_63 ) ) ;
if ( V_11 -> V_63 == 1 )
return F_63 ( V_11 , V_102 ) ;
return F_65 ( V_11 , V_102 ) ;
}
static int F_66 ( struct V_10 * V_11 , V_76 V_102 ,
V_76 * V_114 )
{
F_17 ( F_49 ( V_11 -> V_63 ) ) ;
if ( V_102 == V_103 ) {
* V_114 = V_11 -> V_79 . V_93 ;
} else if ( V_11 -> V_63 == 1 ) {
T_4 V_105 ;
V_105 = F_62 ( V_11 , V_102 ) ;
if ( V_105 == V_112 )
return - V_23 ;
* V_114 = V_11 -> V_79 . V_84 [ V_105 ] ;
} else {
V_76 V_66 = 0 ;
int V_33 ;
V_33 = F_67 ( V_11 , V_102 , NULL , & V_66 ) ;
if ( V_33 )
return V_33 ;
* V_114 = V_66 ;
}
return 0 ;
}
static int F_68 ( struct V_10 * V_11 , V_76 V_102 ,
V_76 * V_115 )
{
F_17 ( F_49 ( V_11 -> V_63 ) ) ;
if ( V_102 == V_103 ) {
* V_115 = V_11 -> V_79 . V_100 ;
} else if ( V_11 -> V_63 == 1 ) {
* V_115 = 0 ;
} else {
V_76 V_100 = 0 ;
int V_33 ;
V_33 = F_69 ( V_11 , V_102 , & V_100 ) ;
if ( V_33 )
return V_33 ;
* V_115 = V_100 ;
}
return 0 ;
}
static int F_70 ( struct V_10 * V_11 )
{
V_76 V_102 = V_11 -> V_101 -> V_102 ;
V_76 V_66 = 0 ;
V_76 V_100 = 0 ;
int V_33 ;
V_33 = F_66 ( V_11 , V_102 , & V_66 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_68 ( V_11 , V_102 , & V_100 ) ;
if ( V_33 )
return V_33 ;
V_11 -> V_16 . V_66 = V_66 ;
V_11 -> V_16 . V_100 = V_100 ;
return 0 ;
}
static void F_71 ( struct V_10 * V_11 )
{
V_11 -> V_16 . V_66 = 0 ;
V_11 -> V_16 . V_100 = 0 ;
}
static const char * F_72 ( struct V_10 * V_11 , V_76 V_116 )
{
char * V_117 ;
V_76 V_118 ;
int V_33 ;
char * V_119 ;
V_117 = F_73 ( V_120 , V_121 ) ;
if ( ! V_117 )
return NULL ;
V_118 = V_116 >> V_11 -> V_79 . V_95 ;
V_119 = L_10 ;
if ( V_11 -> V_63 == 2 )
V_119 = L_11 ;
V_33 = snprintf ( V_117 , V_122 + 1 , V_119 ,
V_11 -> V_79 . V_81 , V_118 ) ;
if ( V_33 < 0 || V_33 > V_122 ) {
F_42 ( L_12 ,
V_118 , V_33 ) ;
F_31 ( V_117 ) ;
V_117 = NULL ;
}
return V_117 ;
}
static void F_74 ( const char * V_117 )
{
F_75 ( V_120 , ( void * ) V_117 ) ;
}
static V_76 F_76 ( struct V_10 * V_11 , V_76 V_116 )
{
V_76 V_123 = ( V_76 ) 1 << V_11 -> V_79 . V_95 ;
return V_116 & ( V_123 - 1 ) ;
}
static V_76 F_77 ( struct V_10 * V_11 ,
V_76 V_116 , V_76 V_124 )
{
V_76 V_123 = ( V_76 ) 1 << V_11 -> V_79 . V_95 ;
V_116 &= V_123 - 1 ;
F_17 ( V_124 <= V_125 - V_116 ) ;
if ( V_116 + V_124 > V_123 )
V_124 = V_123 - V_116 ;
return V_124 ;
}
static V_76 F_78 ( struct V_78 * V_79 )
{
return 1 << V_79 -> V_95 ;
}
static void F_79 ( struct V_126 * V_127 )
{
struct V_126 * V_128 ;
while ( V_127 ) {
V_128 = V_127 ;
V_127 = V_127 -> V_129 ;
F_80 ( V_128 ) ;
}
}
static void F_81 ( struct V_126 * V_127 , int V_130 )
{
struct V_131 * V_132 ;
unsigned long V_21 ;
void * V_133 ;
int V_85 ;
int V_134 = 0 ;
while ( V_127 ) {
F_82 (bv, chain, i) {
if ( V_134 + V_132 -> V_135 > V_130 ) {
int V_136 = F_83 ( V_130 - V_134 , 0 ) ;
V_133 = F_84 ( V_132 , & V_21 ) ;
memset ( V_133 + V_136 , 0 ,
V_132 -> V_135 - V_136 ) ;
F_85 ( V_133 , & V_21 ) ;
}
V_134 += V_132 -> V_135 ;
}
V_127 = V_127 -> V_129 ;
}
}
static void F_86 ( struct V_137 * * V_138 , V_76 V_116 , V_76 V_139 )
{
struct V_137 * * V_137 = & V_138 [ V_116 >> V_140 ] ;
F_17 ( V_139 > V_116 ) ;
F_17 ( V_139 - V_116 <= ( V_76 ) V_73 ) ;
while ( V_116 < V_139 ) {
T_5 V_141 ;
T_5 V_124 ;
unsigned long V_21 ;
void * V_142 ;
V_141 = ( T_5 ) ( V_116 & ~ V_143 ) ;
V_124 = F_87 ( V_144 - V_141 , ( T_5 ) ( V_139 - V_116 ) ) ;
F_88 ( V_21 ) ;
V_142 = F_89 ( * V_137 ) ;
memset ( V_142 + V_141 , 0 , V_124 ) ;
F_90 ( V_142 ) ;
F_91 ( V_21 ) ;
V_116 += V_124 ;
V_137 ++ ;
}
}
static struct V_126 * F_92 ( struct V_126 * V_145 ,
unsigned int V_116 ,
unsigned int V_86 ,
T_6 V_146 )
{
struct V_131 * V_132 ;
unsigned int V_147 ;
unsigned short V_148 ;
unsigned int V_149 ;
unsigned short V_150 ;
unsigned short V_151 ;
struct V_126 * V_126 ;
if ( ! V_116 && V_86 == V_145 -> V_152 )
return F_93 ( V_145 , V_146 ) ;
if ( F_94 ( ! V_86 ) )
return NULL ;
if ( F_94 ( V_86 > V_145 -> V_152 ) )
return NULL ;
if ( F_94 ( V_116 > V_145 -> V_152 - V_86 ) )
return NULL ;
V_147 = V_116 ;
F_82 (bv, bio_src, idx) {
if ( V_147 < V_132 -> V_135 )
break;
V_147 -= V_132 -> V_135 ;
}
V_149 = V_147 ;
V_147 += V_86 ;
F_95 (bv, bio_src, end_idx, idx) {
if ( V_147 <= V_132 -> V_135 )
break;
V_147 -= V_132 -> V_135 ;
}
V_151 = V_150 - V_148 + 1 ;
V_126 = F_96 ( V_146 , ( unsigned int ) V_151 ) ;
if ( ! V_126 )
return NULL ;
V_126 -> V_153 = V_145 -> V_153 ;
V_126 -> V_154 = V_145 -> V_154 + ( V_116 >> V_72 ) ;
V_126 -> V_155 = V_145 -> V_155 ;
V_126 -> V_156 |= 1 << V_157 ;
memcpy ( & V_126 -> V_158 [ 0 ] , & V_145 -> V_158 [ V_148 ] ,
V_151 * sizeof ( struct V_131 ) ) ;
V_126 -> V_158 [ 0 ] . V_159 += V_149 ;
if ( V_151 > 1 ) {
V_126 -> V_158 [ 0 ] . V_135 -= V_149 ;
V_126 -> V_158 [ V_151 - 1 ] . V_135 = V_147 ;
} else {
V_126 -> V_158 [ 0 ] . V_135 = V_86 ;
}
V_126 -> V_160 = V_151 ;
V_126 -> V_152 = V_86 ;
V_126 -> V_161 = 0 ;
return V_126 ;
}
static struct V_126 * F_97 ( struct V_126 * * V_145 ,
unsigned int * V_116 ,
unsigned int V_86 ,
T_6 V_146 )
{
struct V_126 * V_162 = * V_145 ;
unsigned int V_163 = * V_116 ;
struct V_126 * V_127 = NULL ;
struct V_126 * * V_139 ;
if ( ! V_162 || V_163 >= V_162 -> V_152 || ! V_86 )
return NULL ;
V_139 = & V_127 ;
while ( V_86 ) {
unsigned int V_152 ;
struct V_126 * V_126 ;
if ( ! V_162 ) {
F_98 ( NULL , L_13 , V_86 ) ;
goto V_42;
}
V_152 = F_99 (unsigned int, bi->bi_size - off, len) ;
V_126 = F_92 ( V_162 , V_163 , V_152 , V_146 ) ;
if ( ! V_126 )
goto V_42;
* V_139 = V_126 ;
V_139 = & V_126 -> V_129 ;
V_163 += V_152 ;
if ( V_163 == V_162 -> V_152 ) {
V_162 = V_162 -> V_129 ;
V_163 = 0 ;
}
V_86 -= V_152 ;
}
* V_145 = V_162 ;
* V_116 = V_163 ;
return V_127 ;
V_42:
F_79 ( V_127 ) ;
return NULL ;
}
static void F_100 ( struct V_164 * V_165 )
{
if ( F_101 ( V_166 , & V_165 -> V_21 ) ) {
struct V_10 * V_11 ;
V_11 = V_165 -> V_167 -> V_11 ;
F_98 ( V_11 , L_14 ,
V_165 ) ;
}
}
static bool F_102 ( struct V_164 * V_165 )
{
F_103 () ;
return F_10 ( V_166 , & V_165 -> V_21 ) != 0 ;
}
static void F_104 ( struct V_164 * V_165 )
{
if ( F_101 ( V_168 , & V_165 -> V_21 ) ) {
struct V_10 * V_11 = NULL ;
if ( F_102 ( V_165 ) )
V_11 = V_165 -> V_167 -> V_11 ;
F_98 ( V_11 , L_15 ,
V_165 ) ;
}
}
static bool F_105 ( struct V_164 * V_165 )
{
F_103 () ;
return F_10 ( V_168 , & V_165 -> V_21 ) != 0 ;
}
static void F_106 ( struct V_164 * V_165 ,
bool V_169 )
{
if ( V_169 )
F_107 ( V_170 , & V_165 -> V_21 ) ;
F_107 ( V_171 , & V_165 -> V_21 ) ;
F_103 () ;
}
static bool F_108 ( struct V_164 * V_165 )
{
F_103 () ;
return F_10 ( V_171 , & V_165 -> V_21 ) != 0 ;
}
static bool F_109 ( struct V_164 * V_165 )
{
F_103 () ;
return F_10 ( V_170 , & V_165 -> V_21 ) != 0 ;
}
static void F_110 ( struct V_164 * V_165 )
{
F_20 ( L_16 , V_35 , V_165 ,
F_111 ( & V_165 -> V_38 . V_172 ) ) ;
F_35 ( & V_165 -> V_38 ) ;
}
static void F_112 ( struct V_164 * V_165 )
{
F_17 ( V_165 != NULL ) ;
F_20 ( L_16 , V_35 , V_165 ,
F_111 ( & V_165 -> V_38 . V_172 ) ) ;
F_48 ( & V_165 -> V_38 , V_173 ) ;
}
static void F_113 ( struct V_174 * V_167 )
{
F_17 ( V_167 != NULL ) ;
F_20 ( L_17 , V_35 , V_167 ,
F_111 ( & V_167 -> V_38 . V_172 ) ) ;
if ( F_114 ( V_167 ) )
F_48 ( & V_167 -> V_38 , V_175 ) ;
else
F_48 ( & V_167 -> V_38 , V_176 ) ;
}
static inline void F_115 ( struct V_174 * V_167 ,
struct V_164 * V_165 )
{
F_17 ( V_165 -> V_167 == NULL ) ;
V_165 -> V_167 = V_167 ;
V_165 -> V_105 = V_167 -> V_177 ;
F_17 ( ! F_102 ( V_165 ) ) ;
F_100 ( V_165 ) ;
F_17 ( V_165 -> V_105 != V_178 ) ;
V_167 -> V_177 ++ ;
F_28 ( & V_165 -> V_179 , & V_167 -> V_180 ) ;
F_20 ( L_18 , V_35 , V_167 , V_165 ,
V_165 -> V_105 ) ;
}
static inline void F_116 ( struct V_174 * V_167 ,
struct V_164 * V_165 )
{
F_17 ( V_165 -> V_105 != V_178 ) ;
F_20 ( L_18 , V_35 , V_167 , V_165 ,
V_165 -> V_105 ) ;
F_46 ( & V_165 -> V_179 ) ;
F_17 ( V_167 -> V_177 > 0 ) ;
V_167 -> V_177 -- ;
F_17 ( V_165 -> V_105 == V_167 -> V_177 ) ;
V_165 -> V_105 = V_178 ;
F_17 ( F_102 ( V_165 ) ) ;
F_17 ( V_165 -> V_167 == V_167 ) ;
V_165 -> V_167 = NULL ;
V_165 -> V_181 = NULL ;
F_112 ( V_165 ) ;
}
static bool F_117 ( enum V_182 type )
{
switch ( type ) {
case V_183 :
case V_184 :
case V_185 :
return true ;
default:
return false ;
}
}
static int F_118 ( struct V_186 * V_187 ,
struct V_164 * V_165 )
{
F_20 ( L_19 , V_35 , V_187 , V_165 ) ;
return F_119 ( V_187 , V_165 -> V_188 , false ) ;
}
static void F_120 ( struct V_174 * V_167 )
{
F_20 ( L_20 , V_35 , V_167 ) ;
if ( ! V_167 -> V_189 ) {
struct V_164 * V_165 ;
V_76 V_190 = 0 ;
F_121 (img_request, obj_request)
V_190 += V_165 -> V_190 ;
V_167 -> V_190 = V_190 ;
}
if ( V_167 -> V_181 )
V_167 -> V_181 ( V_167 ) ;
else
F_113 ( V_167 ) ;
}
static int F_122 ( struct V_164 * V_165 )
{
F_20 ( L_21 , V_35 , V_165 ) ;
return F_123 ( & V_165 -> V_191 ) ;
}
static void F_124 ( struct V_174 * V_167 )
{
F_107 ( V_192 , & V_167 -> V_21 ) ;
F_103 () ;
}
static bool F_125 ( struct V_174 * V_167 )
{
F_103 () ;
return F_10 ( V_192 , & V_167 -> V_21 ) != 0 ;
}
static void F_126 ( struct V_174 * V_167 )
{
F_107 ( V_193 , & V_167 -> V_21 ) ;
F_103 () ;
}
static void F_127 ( struct V_174 * V_167 )
{
F_128 ( V_193 , & V_167 -> V_21 ) ;
F_103 () ;
}
static bool F_114 ( struct V_174 * V_167 )
{
F_103 () ;
return F_10 ( V_193 , & V_167 -> V_21 ) != 0 ;
}
static void F_129 ( struct V_174 * V_167 )
{
F_107 ( V_194 , & V_167 -> V_21 ) ;
F_103 () ;
}
static void F_130 ( struct V_174 * V_167 )
{
F_128 ( V_194 , & V_167 -> V_21 ) ;
F_103 () ;
}
static bool F_131 ( struct V_174 * V_167 )
{
F_103 () ;
return F_10 ( V_194 , & V_167 -> V_21 ) != 0 ;
}
static void
F_132 ( struct V_164 * V_165 )
{
V_76 V_190 = V_165 -> V_190 ;
V_76 V_124 = V_165 -> V_124 ;
F_20 ( L_22 , V_35 ,
V_165 , V_165 -> V_167 , V_165 -> V_189 ,
V_190 , V_124 ) ;
F_17 ( V_165 -> type != V_183 ) ;
if ( V_165 -> V_189 == - V_23 ) {
if ( V_165 -> type == V_184 )
F_81 ( V_165 -> V_195 , 0 ) ;
else
F_86 ( V_165 -> V_138 , 0 , V_124 ) ;
V_165 -> V_189 = 0 ;
V_165 -> V_190 = V_124 ;
} else if ( V_190 < V_124 && ! V_165 -> V_189 ) {
if ( V_165 -> type == V_184 )
F_81 ( V_165 -> V_195 , V_190 ) ;
else
F_86 ( V_165 -> V_138 , V_190 , V_124 ) ;
V_165 -> V_190 = V_124 ;
}
F_104 ( V_165 ) ;
}
static void F_133 ( struct V_164 * V_165 )
{
F_20 ( L_23 , V_35 , V_165 ,
V_165 -> V_181 ) ;
if ( V_165 -> V_181 )
V_165 -> V_181 ( V_165 ) ;
else
F_134 ( & V_165 -> V_191 ) ;
}
static void F_135 ( struct V_164 * V_165 )
{
F_20 ( L_21 , V_35 , V_165 ) ;
F_104 ( V_165 ) ;
}
static void F_136 ( struct V_164 * V_165 )
{
struct V_174 * V_167 = NULL ;
struct V_10 * V_11 = NULL ;
bool V_196 = false ;
if ( F_102 ( V_165 ) ) {
V_167 = V_165 -> V_167 ;
V_196 = V_167 && F_131 ( V_167 ) ;
V_11 = V_167 -> V_11 ;
}
F_20 ( L_22 , V_35 ,
V_165 , V_167 , V_165 -> V_189 ,
V_165 -> V_190 , V_165 -> V_124 ) ;
if ( V_196 && V_165 -> V_189 == - V_23 &&
V_165 -> V_197 < V_11 -> V_198 )
F_137 ( V_165 ) ;
else if ( V_167 )
F_132 ( V_165 ) ;
else
F_104 ( V_165 ) ;
}
static void F_138 ( struct V_164 * V_165 )
{
F_20 ( L_24 , V_35 , V_165 ,
V_165 -> V_189 , V_165 -> V_124 ) ;
V_165 -> V_190 = V_165 -> V_124 ;
F_104 ( V_165 ) ;
}
static void F_139 ( struct V_164 * V_165 )
{
F_20 ( L_21 , V_35 , V_165 ) ;
F_104 ( V_165 ) ;
}
static void F_140 ( struct V_199 * V_188 ,
struct V_200 * V_201 )
{
struct V_164 * V_165 = V_188 -> V_202 ;
T_7 V_203 ;
F_20 ( L_25 , V_35 , V_188 , V_201 ) ;
F_17 ( V_188 == V_165 -> V_188 ) ;
if ( F_102 ( V_165 ) ) {
F_17 ( V_165 -> V_167 ) ;
F_17 ( V_165 -> V_105 != V_178 ) ;
} else {
F_17 ( V_165 -> V_105 == V_178 ) ;
}
if ( V_188 -> V_204 < 0 )
V_165 -> V_189 = V_188 -> V_204 ;
F_141 ( V_188 -> V_205 > 2 ) ;
V_165 -> V_190 = V_188 -> V_206 [ 0 ] ;
F_17 ( V_165 -> V_190 < ( V_76 ) V_207 ) ;
V_203 = V_188 -> V_208 [ 0 ] . V_209 ;
switch ( V_203 ) {
case V_210 :
F_136 ( V_165 ) ;
break;
case V_211 :
F_138 ( V_165 ) ;
break;
case V_212 :
F_139 ( V_165 ) ;
break;
case V_213 :
case V_214 :
case V_215 :
F_135 ( V_165 ) ;
break;
default:
F_98 ( NULL , L_26 ,
V_165 -> V_216 , ( unsigned short ) V_203 ) ;
break;
}
if ( F_105 ( V_165 ) )
F_133 ( V_165 ) ;
}
static void F_142 ( struct V_164 * V_165 )
{
struct V_174 * V_167 = V_165 -> V_167 ;
struct V_199 * V_188 = V_165 -> V_188 ;
V_76 V_102 ;
F_17 ( V_188 != NULL ) ;
V_102 = V_167 ? V_167 -> V_102 : V_103 ;
F_143 ( V_188 , V_165 -> V_116 ,
NULL , V_102 , NULL ) ;
}
static void F_144 ( struct V_164 * V_165 )
{
struct V_174 * V_167 = V_165 -> V_167 ;
struct V_199 * V_188 = V_165 -> V_188 ;
struct V_74 * V_82 ;
struct V_217 V_218 = V_219 ;
F_17 ( V_188 != NULL ) ;
V_82 = V_167 ? V_167 -> V_82 : NULL ;
F_143 ( V_188 , V_165 -> V_116 ,
V_82 , V_103 , & V_218 ) ;
}
static struct V_199 * F_145 (
struct V_10 * V_11 ,
bool V_220 ,
struct V_164 * V_165 )
{
struct V_74 * V_82 = NULL ;
struct V_186 * V_187 ;
struct V_199 * V_188 ;
if ( F_102 ( V_165 ) ) {
struct V_174 * V_167 = V_165 -> V_167 ;
F_17 ( V_220 ==
F_125 ( V_167 ) ) ;
if ( V_220 )
V_82 = V_167 -> V_82 ;
}
V_187 = & V_11 -> V_29 -> V_40 -> V_187 ;
V_188 = F_146 ( V_187 , V_82 , 1 , false , V_221 ) ;
if ( ! V_188 )
return NULL ;
if ( V_220 )
V_188 -> V_222 = V_223 | V_224 ;
else
V_188 -> V_222 = V_225 ;
V_188 -> V_226 = F_140 ;
V_188 -> V_202 = V_165 ;
V_188 -> V_227 = strlen ( V_165 -> V_216 ) ;
F_17 ( V_188 -> V_227 < sizeof ( V_188 -> V_228 ) ) ;
memcpy ( V_188 -> V_228 , V_165 -> V_216 , V_188 -> V_227 ) ;
V_188 -> V_229 = V_11 -> V_230 ;
return V_188 ;
}
static struct V_199 *
F_147 ( struct V_164 * V_165 )
{
struct V_174 * V_167 ;
struct V_74 * V_82 ;
struct V_10 * V_11 ;
struct V_186 * V_187 ;
struct V_199 * V_188 ;
F_17 ( F_102 ( V_165 ) ) ;
V_167 = V_165 -> V_167 ;
F_17 ( V_167 ) ;
F_17 ( F_125 ( V_167 ) ) ;
V_82 = V_167 -> V_82 ;
V_11 = V_167 -> V_11 ;
V_187 = & V_11 -> V_29 -> V_40 -> V_187 ;
V_188 = F_146 ( V_187 , V_82 , 2 , false , V_221 ) ;
if ( ! V_188 )
return NULL ;
V_188 -> V_222 = V_223 | V_224 ;
V_188 -> V_226 = F_140 ;
V_188 -> V_202 = V_165 ;
V_188 -> V_227 = strlen ( V_165 -> V_216 ) ;
F_17 ( V_188 -> V_227 < sizeof ( V_188 -> V_228 ) ) ;
memcpy ( V_188 -> V_228 , V_165 -> V_216 , V_188 -> V_227 ) ;
V_188 -> V_229 = V_11 -> V_230 ;
return V_188 ;
}
static void F_148 ( struct V_199 * V_188 )
{
F_149 ( V_188 ) ;
}
static struct V_164 * F_150 ( const char * V_216 ,
V_76 V_116 , V_76 V_124 ,
enum V_182 type )
{
struct V_164 * V_165 ;
T_5 V_66 ;
char * V_117 ;
F_17 ( F_117 ( type ) ) ;
V_66 = strlen ( V_216 ) + 1 ;
V_117 = F_21 ( V_66 , V_36 ) ;
if ( ! V_117 )
return NULL ;
V_165 = F_151 ( V_231 , V_36 ) ;
if ( ! V_165 ) {
F_31 ( V_117 ) ;
return NULL ;
}
V_165 -> V_216 = memcpy ( V_117 , V_216 , V_66 ) ;
V_165 -> V_116 = V_116 ;
V_165 -> V_124 = V_124 ;
V_165 -> V_21 = 0 ;
V_165 -> V_105 = V_178 ;
V_165 -> type = type ;
F_23 ( & V_165 -> V_179 ) ;
F_152 ( & V_165 -> V_191 ) ;
F_22 ( & V_165 -> V_38 ) ;
F_20 ( L_27 , V_35 , V_216 ,
V_116 , V_124 , ( int ) type , V_165 ) ;
return V_165 ;
}
static void V_173 ( struct V_38 * V_38 )
{
struct V_164 * V_165 ;
V_165 = F_45 ( V_38 , struct V_164 , V_38 ) ;
F_20 ( L_21 , V_35 , V_165 ) ;
F_17 ( V_165 -> V_167 == NULL ) ;
F_17 ( V_165 -> V_105 == V_178 ) ;
if ( V_165 -> V_188 )
F_148 ( V_165 -> V_188 ) ;
F_17 ( F_117 ( V_165 -> type ) ) ;
switch ( V_165 -> type ) {
case V_183 :
break;
case V_184 :
if ( V_165 -> V_195 )
F_79 ( V_165 -> V_195 ) ;
break;
case V_185 :
if ( V_165 -> V_138 )
F_153 ( V_165 -> V_138 ,
V_165 -> V_232 ) ;
break;
}
F_31 ( V_165 -> V_216 ) ;
V_165 -> V_216 = NULL ;
F_75 ( V_231 , V_165 ) ;
}
static void F_154 ( struct V_10 * V_11 )
{
F_155 ( V_11 ) ;
F_156 ( V_11 -> V_233 ) ;
V_11 -> V_233 = NULL ;
V_11 -> V_198 = 0 ;
}
static void F_157 ( struct V_10 * V_11 )
{
int V_2 ;
if ( ! V_11 -> V_233 )
return;
V_2 = F_4 ( & V_11 -> V_234 ) ;
if ( V_2 > 0 )
return;
if ( ! V_2 )
F_154 ( V_11 ) ;
else
F_98 ( V_11 , L_28 ) ;
}
static bool F_158 ( struct V_10 * V_11 )
{
int V_2 ;
if ( ! V_11 -> V_233 )
return false ;
V_2 = F_1 ( & V_11 -> V_234 ) ;
if ( V_2 > 0 && V_11 -> V_198 )
return true ;
if ( V_2 < 0 )
F_98 ( V_11 , L_29 ) ;
return false ;
}
static struct V_174 * F_159 (
struct V_10 * V_11 ,
V_76 V_116 , V_76 V_124 ,
bool V_220 )
{
struct V_174 * V_167 ;
V_167 = F_73 ( V_235 , V_221 ) ;
if ( ! V_167 )
return NULL ;
if ( V_220 ) {
F_160 ( & V_11 -> V_94 ) ;
F_161 ( V_11 -> V_79 . V_82 ) ;
F_162 ( & V_11 -> V_94 ) ;
}
V_167 -> V_236 = NULL ;
V_167 -> V_11 = V_11 ;
V_167 -> V_116 = V_116 ;
V_167 -> V_124 = V_124 ;
V_167 -> V_21 = 0 ;
if ( V_220 ) {
F_124 ( V_167 ) ;
V_167 -> V_82 = V_11 -> V_79 . V_82 ;
} else {
V_167 -> V_102 = V_11 -> V_101 -> V_102 ;
}
if ( F_158 ( V_11 ) )
F_129 ( V_167 ) ;
F_163 ( & V_167 -> V_237 ) ;
V_167 -> V_238 = 0 ;
V_167 -> V_181 = NULL ;
V_167 -> V_189 = 0 ;
V_167 -> V_177 = 0 ;
F_23 ( & V_167 -> V_180 ) ;
F_22 ( & V_167 -> V_38 ) ;
F_20 ( L_30 , V_35 , V_11 ,
V_220 ? L_31 : L_32 , V_116 , V_124 ,
V_167 ) ;
return V_167 ;
}
static void V_176 ( struct V_38 * V_38 )
{
struct V_174 * V_167 ;
struct V_164 * V_165 ;
struct V_164 * V_239 ;
V_167 = F_45 ( V_38 , struct V_174 , V_38 ) ;
F_20 ( L_20 , V_35 , V_167 ) ;
F_164 (img_request, obj_request, next_obj_request)
F_116 ( V_167 , V_165 ) ;
F_17 ( V_167 -> V_177 == 0 ) ;
if ( F_131 ( V_167 ) ) {
F_130 ( V_167 ) ;
F_157 ( V_167 -> V_11 ) ;
}
if ( F_125 ( V_167 ) )
F_57 ( V_167 -> V_82 ) ;
F_75 ( V_235 , V_167 ) ;
}
static struct V_174 * F_165 (
struct V_164 * V_165 ,
V_76 V_197 , V_76 V_124 )
{
struct V_174 * V_240 ;
struct V_10 * V_11 ;
F_17 ( V_165 -> V_167 ) ;
V_11 = V_165 -> V_167 -> V_11 ;
V_240 = F_159 ( V_11 -> V_241 ,
V_197 , V_124 , false ) ;
if ( ! V_240 )
return NULL ;
F_126 ( V_240 ) ;
F_110 ( V_165 ) ;
V_240 -> V_165 = V_165 ;
return V_240 ;
}
static void V_175 ( struct V_38 * V_38 )
{
struct V_174 * V_240 ;
struct V_164 * V_242 ;
V_240 = F_45 ( V_38 , struct V_174 , V_38 ) ;
V_242 = V_240 -> V_165 ;
V_240 -> V_165 = NULL ;
F_112 ( V_242 ) ;
F_127 ( V_240 ) ;
V_176 ( V_38 ) ;
}
static bool F_166 ( struct V_164 * V_165 )
{
struct V_174 * V_167 ;
unsigned int V_190 ;
int V_189 ;
bool V_243 ;
F_17 ( F_102 ( V_165 ) ) ;
V_167 = V_165 -> V_167 ;
F_17 ( V_165 -> V_190 <= ( V_76 ) V_207 ) ;
V_190 = ( unsigned int ) V_165 -> V_190 ;
V_189 = V_165 -> V_189 ;
if ( V_189 ) {
struct V_10 * V_11 = V_167 -> V_11 ;
F_98 ( V_11 , L_33 ,
F_125 ( V_167 ) ? L_31 : L_32 ,
V_165 -> V_124 , V_165 -> V_197 ,
V_165 -> V_116 ) ;
F_98 ( V_11 , L_34 ,
V_189 , V_190 ) ;
if ( ! V_167 -> V_189 )
V_167 -> V_189 = V_189 ;
}
if ( V_165 -> type == V_185 ) {
V_165 -> V_138 = NULL ;
V_165 -> V_232 = 0 ;
}
if ( F_114 ( V_167 ) ) {
F_17 ( V_167 -> V_165 != NULL ) ;
V_243 = V_165 -> V_105 < V_167 -> V_177 - 1 ;
} else {
F_17 ( V_167 -> V_236 != NULL ) ;
V_243 = F_167 ( V_167 -> V_236 , V_189 , V_190 ) ;
}
return V_243 ;
}
static void F_168 ( struct V_164 * V_165 )
{
struct V_174 * V_167 ;
T_4 V_105 = V_165 -> V_105 ;
bool V_243 = true ;
F_17 ( F_102 ( V_165 ) ) ;
V_167 = V_165 -> V_167 ;
F_20 ( L_35 , V_35 , V_167 , V_165 ) ;
F_17 ( V_167 != NULL ) ;
F_17 ( V_167 -> V_177 > 0 ) ;
F_17 ( V_105 != V_178 ) ;
F_17 ( V_105 < V_167 -> V_177 ) ;
F_17 ( V_105 >= V_167 -> V_238 ) ;
F_9 ( & V_167 -> V_237 ) ;
if ( V_105 != V_167 -> V_238 )
goto V_244;
F_169 (img_request, obj_request) {
F_17 ( V_243 ) ;
F_17 ( V_105 < V_167 -> V_177 ) ;
if ( ! F_105 ( V_165 ) )
break;
V_243 = F_166 ( V_165 ) ;
V_105 ++ ;
}
F_17 ( V_243 ^ ( V_105 == V_167 -> V_177 ) ) ;
V_167 -> V_238 = V_105 ;
V_244:
F_11 ( & V_167 -> V_237 ) ;
if ( ! V_243 )
F_120 ( V_167 ) ;
}
static int F_170 ( struct V_174 * V_167 ,
enum V_182 type ,
void * V_245 )
{
struct V_10 * V_11 = V_167 -> V_11 ;
struct V_164 * V_165 = NULL ;
struct V_164 * V_239 ;
bool V_220 = F_125 ( V_167 ) ;
struct V_126 * V_195 ;
unsigned int V_246 = 0 ;
struct V_137 * * V_138 ;
V_76 V_197 ;
V_76 V_147 ;
T_7 V_203 ;
F_20 ( L_36 , V_35 , V_167 ,
( int ) type , V_245 ) ;
V_203 = V_220 ? V_211 : V_210 ;
V_197 = V_167 -> V_116 ;
V_147 = V_167 -> V_124 ;
F_17 ( V_147 > 0 ) ;
if ( type == V_184 ) {
V_195 = V_245 ;
F_17 ( V_197 == V_195 -> V_154 << V_72 ) ;
} else {
F_17 ( type == V_185 ) ;
V_138 = V_245 ;
}
while ( V_147 ) {
struct V_199 * V_188 ;
const char * V_216 ;
V_76 V_116 ;
V_76 V_124 ;
V_216 = F_72 ( V_11 , V_197 ) ;
if ( ! V_216 )
goto V_247;
V_116 = F_76 ( V_11 , V_197 ) ;
V_124 = F_77 ( V_11 , V_197 , V_147 ) ;
V_165 = F_150 ( V_216 ,
V_116 , V_124 , type ) ;
F_74 ( V_216 ) ;
if ( ! V_165 )
goto V_247;
if ( type == V_184 ) {
unsigned int V_248 ;
F_17 ( V_124 <= ( V_76 ) V_207 ) ;
V_248 = ( unsigned int ) V_124 ;
V_165 -> V_195 =
F_97 ( & V_195 ,
& V_246 ,
V_248 ,
V_221 ) ;
if ( ! V_165 -> V_195 )
goto V_249;
} else {
unsigned int V_232 ;
V_165 -> V_138 = V_138 ;
V_232 = ( T_4 ) F_171 ( V_116 , V_124 ) ;
V_165 -> V_232 = V_232 ;
if ( ( V_116 + V_124 ) & ~ V_143 )
V_232 -- ;
V_138 += V_232 ;
}
V_188 = F_145 ( V_11 , V_220 ,
V_165 ) ;
if ( ! V_188 )
goto V_249;
V_165 -> V_188 = V_188 ;
V_165 -> V_181 = F_168 ;
F_172 ( V_188 , 0 , V_203 , V_116 , V_124 ,
0 , 0 ) ;
if ( type == V_184 )
F_173 ( V_188 , 0 ,
V_165 -> V_195 , V_124 ) ;
else
F_174 ( V_188 , 0 ,
V_165 -> V_138 , V_124 ,
V_116 & ~ V_143 , false , false ) ;
F_115 ( V_167 , V_165 ) ;
if ( V_220 )
F_144 ( V_165 ) ;
else
F_142 ( V_165 ) ;
V_165 -> V_197 = V_197 ;
V_197 += V_124 ;
V_147 -= V_124 ;
}
return 0 ;
V_249:
F_112 ( V_165 ) ;
V_247:
F_164 (img_request, obj_request, next_obj_request)
F_112 ( V_165 ) ;
return - V_34 ;
}
static void
F_175 ( struct V_164 * V_165 )
{
struct V_174 * V_167 ;
struct V_10 * V_11 ;
struct V_137 * * V_138 ;
T_4 V_232 ;
F_17 ( V_165 -> type == V_184 ) ;
F_17 ( F_102 ( V_165 ) ) ;
V_167 = V_165 -> V_167 ;
F_17 ( V_167 ) ;
V_11 = V_167 -> V_11 ;
F_17 ( V_11 ) ;
V_138 = V_165 -> V_250 ;
F_17 ( V_138 != NULL ) ;
V_165 -> V_250 = NULL ;
V_232 = V_165 -> V_251 ;
F_17 ( V_232 ) ;
V_165 -> V_251 = 0 ;
F_153 ( V_138 , V_232 ) ;
if ( ! V_165 -> V_189 )
V_165 -> V_190 = V_165 -> V_124 ;
F_168 ( V_165 ) ;
}
static void
F_176 ( struct V_174 * V_167 )
{
struct V_164 * V_242 ;
struct V_199 * V_188 ;
struct V_186 * V_187 ;
struct V_10 * V_11 ;
struct V_137 * * V_138 ;
T_4 V_232 ;
int V_252 ;
V_76 V_253 ;
V_76 V_116 ;
V_76 V_124 ;
F_17 ( F_114 ( V_167 ) ) ;
V_138 = V_167 -> V_250 ;
F_17 ( V_138 != NULL ) ;
V_167 -> V_250 = NULL ;
V_232 = V_167 -> V_251 ;
F_17 ( V_232 ) ;
V_167 -> V_251 = 0 ;
V_242 = V_167 -> V_165 ;
F_17 ( V_242 != NULL ) ;
F_17 ( F_117 ( V_242 -> type ) ) ;
V_252 = V_167 -> V_189 ;
V_253 = V_167 -> V_124 ;
F_17 ( V_253 == V_167 -> V_190 ) ;
F_113 ( V_167 ) ;
F_17 ( V_242 -> V_167 ) ;
V_11 = V_242 -> V_167 -> V_11 ;
F_17 ( V_11 ) ;
if ( ! V_11 -> V_198 ) {
struct V_186 * V_187 ;
F_153 ( V_138 , V_232 ) ;
V_187 = & V_11 -> V_29 -> V_40 -> V_187 ;
V_252 = F_118 ( V_187 , V_242 ) ;
if ( ! V_252 )
return;
}
if ( V_252 )
goto V_42;
V_252 = - V_34 ;
V_188 = F_147 ( V_242 ) ;
if ( ! V_188 )
goto V_42;
F_148 ( V_242 -> V_188 ) ;
V_242 -> V_188 = V_188 ;
V_242 -> V_250 = V_138 ;
V_242 -> V_251 = V_232 ;
F_177 ( V_188 , 0 , V_213 , L_37 , L_38 ) ;
F_178 ( V_188 , 0 , V_138 , V_253 , 0 ,
false , false ) ;
V_116 = V_242 -> V_116 ;
V_124 = V_242 -> V_124 ;
F_172 ( V_188 , 1 , V_211 ,
V_116 , V_124 , 0 , 0 ) ;
if ( V_242 -> type == V_184 )
F_173 ( V_188 , 1 ,
V_242 -> V_195 , V_124 ) ;
else
F_174 ( V_188 , 1 ,
V_242 -> V_138 , V_124 ,
V_116 & ~ V_143 , false , false ) ;
F_144 ( V_242 ) ;
V_242 -> V_181 = F_175 ;
V_187 = & V_11 -> V_29 -> V_40 -> V_187 ;
V_252 = F_118 ( V_187 , V_242 ) ;
if ( ! V_252 )
return;
V_42:
V_242 -> V_189 = V_252 ;
V_242 -> V_190 = 0 ;
F_104 ( V_242 ) ;
F_133 ( V_242 ) ;
}
static int F_179 ( struct V_164 * V_165 )
{
struct V_174 * V_167 = NULL ;
struct V_174 * V_240 = NULL ;
struct V_10 * V_11 ;
V_76 V_197 ;
V_76 V_124 ;
struct V_137 * * V_138 = NULL ;
T_4 V_232 ;
int V_189 ;
F_17 ( F_102 ( V_165 ) ) ;
F_17 ( F_117 ( V_165 -> type ) ) ;
V_167 = V_165 -> V_167 ;
F_17 ( V_167 != NULL ) ;
V_11 = V_167 -> V_11 ;
F_17 ( V_11 -> V_241 != NULL ) ;
V_197 = V_165 -> V_197 - V_165 -> V_116 ;
V_124 = ( V_76 ) 1 << V_11 -> V_79 . V_95 ;
if ( V_197 + V_124 > V_11 -> V_198 ) {
F_17 ( V_197 < V_11 -> V_198 ) ;
V_124 = V_11 -> V_198 - V_197 ;
}
V_232 = ( T_4 ) F_171 ( 0 , V_124 ) ;
V_138 = F_180 ( V_232 , V_36 ) ;
if ( F_25 ( V_138 ) ) {
V_189 = F_181 ( V_138 ) ;
V_138 = NULL ;
goto V_42;
}
V_189 = - V_34 ;
V_240 = F_165 ( V_165 ,
V_197 , V_124 ) ;
if ( ! V_240 )
goto V_42;
V_189 = F_170 ( V_240 , V_185 , V_138 ) ;
if ( V_189 )
goto V_42;
V_240 -> V_250 = V_138 ;
V_240 -> V_251 = V_232 ;
V_240 -> V_181 = F_176 ;
V_189 = F_182 ( V_240 ) ;
if ( ! V_189 )
return 0 ;
V_240 -> V_250 = NULL ;
V_240 -> V_251 = 0 ;
V_240 -> V_165 = NULL ;
F_112 ( V_165 ) ;
V_42:
if ( V_138 )
F_153 ( V_138 , V_232 ) ;
if ( V_240 )
F_113 ( V_240 ) ;
V_165 -> V_189 = V_189 ;
V_165 -> V_190 = 0 ;
F_104 ( V_165 ) ;
return V_189 ;
}
static void F_183 ( struct V_164 * V_165 )
{
struct V_164 * V_242 ;
struct V_10 * V_11 ;
int V_189 ;
F_17 ( ! F_102 ( V_165 ) ) ;
V_242 = V_165 -> V_165 ;
V_165 -> V_165 = NULL ;
F_17 ( V_242 ) ;
F_17 ( V_242 -> V_167 ) ;
V_189 = V_165 -> V_189 ;
V_165 -> V_189 = 0 ;
F_20 ( L_39 , V_35 ,
V_165 , V_242 , V_189 ,
V_165 -> V_190 , V_165 -> V_124 ) ;
F_112 ( V_165 ) ;
V_11 = V_242 -> V_167 -> V_11 ;
if ( ! V_11 -> V_198 ) {
struct V_186 * V_187 ;
F_112 ( V_242 ) ;
V_187 = & V_11 -> V_29 -> V_40 -> V_187 ;
V_189 = F_118 ( V_187 , V_242 ) ;
if ( ! V_189 )
return;
}
if ( ! V_189 ) {
F_106 ( V_242 , true ) ;
} else if ( V_189 == - V_23 ) {
F_106 ( V_242 , false ) ;
} else if ( V_189 ) {
V_242 -> V_189 = V_189 ;
goto V_244;
}
V_242 -> V_189 = F_184 ( V_242 ) ;
V_244:
if ( V_242 -> V_189 )
F_133 ( V_242 ) ;
F_112 ( V_242 ) ;
}
static int F_185 ( struct V_164 * V_165 )
{
struct V_164 * V_254 ;
struct V_10 * V_11 ;
struct V_186 * V_187 ;
struct V_137 * * V_138 = NULL ;
T_4 V_232 ;
T_5 V_66 ;
int V_33 ;
V_66 = sizeof ( V_75 ) + sizeof ( V_255 ) + sizeof ( V_255 ) ;
V_232 = ( T_4 ) F_171 ( 0 , V_66 ) ;
V_138 = F_180 ( V_232 , V_36 ) ;
if ( F_25 ( V_138 ) )
return F_181 ( V_138 ) ;
V_33 = - V_34 ;
V_254 = F_150 ( V_165 -> V_216 , 0 , 0 ,
V_185 ) ;
if ( ! V_254 )
goto V_244;
F_110 ( V_165 ) ;
V_254 -> V_165 = V_165 ;
V_254 -> V_138 = V_138 ;
V_254 -> V_232 = V_232 ;
F_17 ( V_165 -> V_167 ) ;
V_11 = V_165 -> V_167 -> V_11 ;
V_254 -> V_188 = F_145 ( V_11 , false ,
V_254 ) ;
if ( ! V_254 -> V_188 )
goto V_244;
V_254 -> V_181 = F_183 ;
F_186 ( V_254 -> V_188 , 0 , V_212 ) ;
F_187 ( V_254 -> V_188 , 0 , V_138 , V_66 , 0 ,
false , false ) ;
F_142 ( V_254 ) ;
V_187 = & V_11 -> V_29 -> V_40 -> V_187 ;
V_33 = F_118 ( V_187 , V_254 ) ;
V_244:
if ( V_33 )
F_112 ( V_165 ) ;
return V_33 ;
}
static int F_184 ( struct V_164 * V_165 )
{
struct V_174 * V_167 ;
struct V_10 * V_11 ;
bool V_256 ;
F_17 ( F_102 ( V_165 ) ) ;
V_167 = V_165 -> V_167 ;
F_17 ( V_167 ) ;
V_11 = V_167 -> V_11 ;
if ( ! F_125 ( V_167 ) ||
! F_131 ( V_167 ) ||
V_11 -> V_198 <= V_165 -> V_197 ||
( ( V_256 = F_108 ( V_165 ) ) &&
F_109 ( V_165 ) ) ) {
struct V_10 * V_11 ;
struct V_186 * V_187 ;
V_11 = V_165 -> V_167 -> V_11 ;
V_187 = & V_11 -> V_29 -> V_40 -> V_187 ;
return F_118 ( V_187 , V_165 ) ;
}
if ( V_256 )
return F_179 ( V_165 ) ;
return F_185 ( V_165 ) ;
}
static int F_182 ( struct V_174 * V_167 )
{
struct V_164 * V_165 ;
struct V_164 * V_239 ;
F_20 ( L_20 , V_35 , V_167 ) ;
F_164 (img_request, obj_request, next_obj_request) {
int V_33 ;
V_33 = F_184 ( V_165 ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static void F_188 ( struct V_174 * V_167 )
{
struct V_164 * V_165 ;
struct V_10 * V_11 ;
V_76 V_257 ;
V_76 V_258 ;
int V_252 ;
F_17 ( F_114 ( V_167 ) ) ;
V_165 = V_167 -> V_165 ;
V_258 = V_167 -> V_190 ;
V_252 = V_167 -> V_189 ;
F_113 ( V_167 ) ;
F_17 ( V_165 ) ;
F_17 ( V_165 -> V_167 ) ;
V_11 = V_165 -> V_167 -> V_11 ;
if ( ! V_11 -> V_198 ) {
struct V_186 * V_187 ;
V_187 = & V_11 -> V_29 -> V_40 -> V_187 ;
V_252 = F_118 ( V_187 , V_165 ) ;
if ( ! V_252 )
return;
}
V_165 -> V_189 = V_252 ;
if ( V_165 -> V_189 )
goto V_244;
F_17 ( V_165 -> V_197 < V_125 - V_165 -> V_124 ) ;
V_257 = V_165 -> V_197 + V_165 -> V_124 ;
if ( V_257 > V_11 -> V_198 ) {
V_76 V_190 = 0 ;
if ( V_165 -> V_197 < V_11 -> V_198 )
V_190 = V_11 -> V_198 -
V_165 -> V_197 ;
V_165 -> V_190 = F_87 ( V_258 , V_190 ) ;
} else {
V_165 -> V_190 = V_258 ;
}
V_244:
F_132 ( V_165 ) ;
F_133 ( V_165 ) ;
}
static void F_137 ( struct V_164 * V_165 )
{
struct V_174 * V_167 ;
int V_189 ;
F_17 ( F_102 ( V_165 ) ) ;
F_17 ( V_165 -> V_167 != NULL ) ;
F_17 ( V_165 -> V_189 == ( V_259 ) - V_23 ) ;
F_17 ( F_117 ( V_165 -> type ) ) ;
V_167 = F_165 ( V_165 ,
V_165 -> V_197 ,
V_165 -> V_124 ) ;
V_189 = - V_34 ;
if ( ! V_167 )
goto V_42;
if ( V_165 -> type == V_184 )
V_189 = F_170 ( V_167 , V_184 ,
V_165 -> V_195 ) ;
else
V_189 = F_170 ( V_167 , V_185 ,
V_165 -> V_138 ) ;
if ( V_189 )
goto V_42;
V_167 -> V_181 = F_188 ;
V_189 = F_182 ( V_167 ) ;
if ( V_189 )
goto V_42;
return;
V_42:
if ( V_167 )
F_113 ( V_167 ) ;
V_165 -> V_189 = V_189 ;
V_165 -> V_190 = 0 ;
F_104 ( V_165 ) ;
}
static int F_189 ( struct V_10 * V_11 , V_76 V_260 )
{
struct V_164 * V_165 ;
struct V_186 * V_187 = & V_11 -> V_29 -> V_40 -> V_187 ;
int V_33 ;
V_165 = F_150 ( V_11 -> V_261 , 0 , 0 ,
V_183 ) ;
if ( ! V_165 )
return - V_34 ;
V_33 = - V_34 ;
V_165 -> V_188 = F_145 ( V_11 , false , V_165 ) ;
if ( ! V_165 -> V_188 )
goto V_244;
V_165 -> V_181 = F_112 ;
F_190 ( V_165 -> V_188 , 0 , V_214 ,
V_260 , 0 , 0 ) ;
F_142 ( V_165 ) ;
V_33 = F_118 ( V_187 , V_165 ) ;
V_244:
if ( V_33 )
F_112 ( V_165 ) ;
return V_33 ;
}
static void F_191 ( V_76 V_262 , V_76 V_260 , T_8 V_203 , void * V_263 )
{
struct V_10 * V_11 = (struct V_10 * ) V_263 ;
int V_33 ;
if ( ! V_11 )
return;
F_20 ( L_40 , V_35 ,
V_11 -> V_261 , ( unsigned long long ) V_260 ,
( unsigned int ) V_203 ) ;
V_33 = F_192 ( V_11 ) ;
if ( V_33 )
F_98 ( V_11 , L_41 , V_33 ) ;
F_189 ( V_11 , V_260 ) ;
}
static int F_193 ( struct V_10 * V_11 , bool V_264 )
{
struct V_186 * V_187 = & V_11 -> V_29 -> V_40 -> V_187 ;
struct V_164 * V_165 ;
int V_33 ;
F_17 ( V_264 ^ ! ! V_11 -> V_265 ) ;
F_17 ( V_264 ^ ! ! V_11 -> V_266 ) ;
if ( V_264 ) {
V_33 = F_194 ( V_187 , F_191 , V_11 ,
& V_11 -> V_265 ) ;
if ( V_33 < 0 )
return V_33 ;
F_17 ( V_11 -> V_265 != NULL ) ;
}
V_33 = - V_34 ;
V_165 = F_150 ( V_11 -> V_261 , 0 , 0 ,
V_183 ) ;
if ( ! V_165 )
goto V_267;
V_165 -> V_188 = F_145 ( V_11 , true , V_165 ) ;
if ( ! V_165 -> V_188 )
goto V_267;
if ( V_264 )
F_195 ( V_187 , V_165 -> V_188 ) ;
else
F_196 ( V_187 ,
V_11 -> V_266 -> V_188 ) ;
F_190 ( V_165 -> V_188 , 0 , V_215 ,
V_11 -> V_265 -> V_268 , 0 , V_264 ? 1 : 0 ) ;
F_144 ( V_165 ) ;
V_33 = F_118 ( V_187 , V_165 ) ;
if ( V_33 )
goto V_267;
V_33 = F_122 ( V_165 ) ;
if ( V_33 )
goto V_267;
V_33 = V_165 -> V_189 ;
if ( V_33 )
goto V_267;
if ( V_264 ) {
V_11 -> V_266 = V_165 ;
return 0 ;
}
F_112 ( V_11 -> V_266 ) ;
V_11 -> V_266 = NULL ;
V_267:
F_197 ( V_11 -> V_265 ) ;
V_11 -> V_265 = NULL ;
if ( V_165 )
F_112 ( V_165 ) ;
return V_33 ;
}
static int F_198 ( struct V_10 * V_11 ,
const char * V_216 ,
const char * V_269 ,
const char * V_270 ,
const void * V_271 ,
T_5 V_272 ,
void * V_273 ,
T_5 V_274 )
{
struct V_186 * V_187 = & V_11 -> V_29 -> V_40 -> V_187 ;
struct V_164 * V_165 ;
struct V_137 * * V_138 ;
T_4 V_232 ;
int V_33 ;
V_232 = ( T_4 ) F_171 ( 0 , V_274 ) ;
V_138 = F_180 ( V_232 , V_36 ) ;
if ( F_25 ( V_138 ) )
return F_181 ( V_138 ) ;
V_33 = - V_34 ;
V_165 = F_150 ( V_216 , 0 , V_274 ,
V_185 ) ;
if ( ! V_165 )
goto V_244;
V_165 -> V_138 = V_138 ;
V_165 -> V_232 = V_232 ;
V_165 -> V_188 = F_145 ( V_11 , false , V_165 ) ;
if ( ! V_165 -> V_188 )
goto V_244;
F_177 ( V_165 -> V_188 , 0 , V_213 ,
V_269 , V_270 ) ;
if ( V_272 ) {
struct V_275 * V_276 ;
V_276 = F_21 ( sizeof ( * V_276 ) , V_277 ) ;
if ( ! V_276 )
goto V_244;
F_199 ( V_276 ) ;
F_200 ( V_276 , V_271 , V_272 ) ;
F_201 ( V_165 -> V_188 , 0 ,
V_276 ) ;
}
F_202 ( V_165 -> V_188 , 0 ,
V_165 -> V_138 , V_274 ,
0 , false , false ) ;
F_142 ( V_165 ) ;
V_33 = F_118 ( V_187 , V_165 ) ;
if ( V_33 )
goto V_244;
V_33 = F_122 ( V_165 ) ;
if ( V_33 )
goto V_244;
V_33 = V_165 -> V_189 ;
if ( V_33 < 0 )
goto V_244;
F_17 ( V_165 -> V_190 < ( V_76 ) V_3 ) ;
V_33 = ( int ) V_165 -> V_190 ;
F_203 ( V_138 , V_273 , 0 , V_165 -> V_190 ) ;
V_244:
if ( V_165 )
F_112 ( V_165 ) ;
else
F_153 ( V_138 , V_232 ) ;
return V_33 ;
}
static void F_204 ( struct V_278 * V_279 )
__releases( V_279 -> V_280 ) __acquires( V_279 -> V_280 )
{
struct V_10 * V_11 = V_279 -> V_281 ;
bool V_17 = V_11 -> V_16 . V_17 ;
struct V_282 * V_236 ;
int V_189 ;
while ( ( V_236 = F_205 ( V_279 ) ) ) {
bool V_220 = F_206 ( V_236 ) == V_283 ;
struct V_174 * V_167 ;
V_76 V_116 ;
V_76 V_124 ;
if ( V_236 -> V_284 != V_285 ) {
F_20 ( L_42 , V_35 ,
( int ) V_236 -> V_284 ) ;
F_207 ( V_236 , 0 ) ;
continue;
}
V_116 = ( V_76 ) F_208 ( V_236 ) << V_72 ;
V_124 = ( V_76 ) F_209 ( V_236 ) ;
if ( ! V_124 ) {
F_20 ( L_43 , V_35 ) ;
F_207 ( V_236 , 0 ) ;
continue;
}
F_11 ( V_279 -> V_280 ) ;
if ( V_220 ) {
V_189 = - V_18 ;
if ( V_17 )
goto V_286;
F_17 ( V_11 -> V_101 -> V_102 == V_103 ) ;
}
if ( ! F_10 ( V_287 , & V_11 -> V_21 ) ) {
F_20 ( L_44 ) ;
F_17 ( V_11 -> V_101 -> V_102 != V_103 ) ;
V_189 = - V_288 ;
goto V_286;
}
V_189 = - V_4 ;
if ( V_116 && V_124 > V_125 - V_116 + 1 ) {
F_98 ( V_11 , L_45 ,
V_116 , V_124 ) ;
goto V_286;
}
V_189 = - V_104 ;
if ( V_116 + V_124 > V_11 -> V_16 . V_66 ) {
F_98 ( V_11 , L_46 ,
V_116 , V_124 , V_11 -> V_16 . V_66 ) ;
goto V_286;
}
V_189 = - V_34 ;
V_167 = F_159 ( V_11 , V_116 , V_124 ,
V_220 ) ;
if ( ! V_167 )
goto V_286;
V_167 -> V_236 = V_236 ;
V_189 = F_170 ( V_167 , V_184 ,
V_236 -> V_126 ) ;
if ( ! V_189 )
V_189 = F_182 ( V_167 ) ;
if ( V_189 )
F_113 ( V_167 ) ;
V_286:
F_9 ( V_279 -> V_280 ) ;
if ( V_189 < 0 ) {
F_98 ( V_11 , L_47 ,
V_220 ? L_31 : L_32 ,
V_124 , V_116 , V_189 ) ;
F_207 ( V_236 , V_189 ) ;
}
}
}
static int F_210 ( struct V_278 * V_279 , struct V_289 * V_290 ,
struct V_131 * V_291 )
{
struct V_10 * V_11 = V_279 -> V_281 ;
T_9 V_292 ;
T_9 V_293 ;
T_9 V_294 ;
int V_33 ;
V_292 = F_211 ( V_290 -> V_153 ) + V_290 -> V_154 ;
V_293 = 1 << ( V_11 -> V_79 . V_95 - V_72 ) ;
V_294 = V_292 & ( V_293 - 1 ) ;
V_33 = ( int ) ( V_293 - V_294 ) << V_72 ;
if ( V_33 > V_290 -> V_152 )
V_33 -= V_290 -> V_152 ;
else
V_33 = 0 ;
F_17 ( V_291 -> V_135 <= V_144 ) ;
if ( V_33 > ( int ) V_291 -> V_135 || ! V_290 -> V_152 )
V_33 = ( int ) V_291 -> V_135 ;
return V_33 ;
}
static void F_212 ( struct V_10 * V_11 )
{
struct V_26 * V_27 = V_11 -> V_27 ;
if ( ! V_27 )
return;
V_11 -> V_27 = NULL ;
if ( V_27 -> V_21 & V_295 ) {
F_213 ( V_27 ) ;
if ( V_27 -> V_296 )
F_214 ( V_27 -> V_296 ) ;
}
F_215 ( V_27 ) ;
}
static int F_216 ( struct V_10 * V_11 ,
const char * V_216 ,
V_76 V_116 , V_76 V_124 , void * V_133 )
{
struct V_186 * V_187 = & V_11 -> V_29 -> V_40 -> V_187 ;
struct V_164 * V_165 ;
struct V_137 * * V_138 = NULL ;
T_4 V_232 ;
T_5 V_66 ;
int V_33 ;
V_232 = ( T_4 ) F_171 ( V_116 , V_124 ) ;
V_138 = F_180 ( V_232 , V_36 ) ;
if ( F_25 ( V_138 ) )
V_33 = F_181 ( V_138 ) ;
V_33 = - V_34 ;
V_165 = F_150 ( V_216 , V_116 , V_124 ,
V_185 ) ;
if ( ! V_165 )
goto V_244;
V_165 -> V_138 = V_138 ;
V_165 -> V_232 = V_232 ;
V_165 -> V_188 = F_145 ( V_11 , false , V_165 ) ;
if ( ! V_165 -> V_188 )
goto V_244;
F_172 ( V_165 -> V_188 , 0 , V_210 ,
V_116 , V_124 , 0 , 0 ) ;
F_174 ( V_165 -> V_188 , 0 ,
V_165 -> V_138 ,
V_165 -> V_124 ,
V_165 -> V_116 & ~ V_143 ,
false , false ) ;
F_142 ( V_165 ) ;
V_33 = F_118 ( V_187 , V_165 ) ;
if ( V_33 )
goto V_244;
V_33 = F_122 ( V_165 ) ;
if ( V_33 )
goto V_244;
V_33 = V_165 -> V_189 ;
if ( V_33 < 0 )
goto V_244;
F_17 ( V_165 -> V_190 <= ( V_76 ) V_73 ) ;
V_66 = ( T_5 ) V_165 -> V_190 ;
F_203 ( V_138 , V_133 , 0 , V_66 ) ;
F_17 ( V_66 <= ( T_5 ) V_3 ) ;
V_33 = ( int ) V_66 ;
V_244:
if ( V_165 )
F_112 ( V_165 ) ;
else
F_153 ( V_138 , V_232 ) ;
return V_33 ;
}
static int F_217 ( struct V_10 * V_11 )
{
struct V_64 * V_65 = NULL ;
T_4 V_67 = 0 ;
V_76 V_297 = 0 ;
T_4 V_298 ;
int V_33 ;
do {
T_5 V_66 ;
F_31 ( V_65 ) ;
V_66 = sizeof ( * V_65 ) ;
V_66 += V_67 * sizeof ( struct V_89 ) ;
V_66 += V_297 ;
V_65 = F_21 ( V_66 , V_36 ) ;
if ( ! V_65 )
return - V_34 ;
V_33 = F_216 ( V_11 , V_11 -> V_261 ,
0 , V_66 , V_65 ) ;
if ( V_33 < 0 )
goto V_244;
if ( ( T_5 ) V_33 < V_66 ) {
V_33 = - V_288 ;
F_98 ( V_11 , L_48 ,
V_66 , V_33 ) ;
goto V_244;
}
if ( ! F_50 ( V_65 ) ) {
V_33 = - V_288 ;
F_98 ( V_11 , L_49 ) ;
goto V_244;
}
V_297 = F_52 ( V_65 -> V_77 ) ;
V_298 = V_67 ;
V_67 = F_51 ( V_65 -> V_67 ) ;
} while ( V_67 != V_298 );
V_33 = F_53 ( V_11 , V_65 ) ;
V_244:
F_31 ( V_65 ) ;
return V_33 ;
}
static void F_218 ( struct V_10 * V_11 )
{
V_76 V_102 ;
if ( ! F_10 ( V_287 , & V_11 -> V_21 ) )
return;
V_102 = V_11 -> V_101 -> V_102 ;
if ( V_102 == V_103 )
return;
if ( F_62 ( V_11 , V_102 ) == V_112 )
F_128 ( V_287 , & V_11 -> V_21 ) ;
}
static int F_192 ( struct V_10 * V_11 )
{
V_76 V_299 ;
int V_33 ;
F_17 ( F_49 ( V_11 -> V_63 ) ) ;
V_299 = V_11 -> V_16 . V_66 ;
F_12 ( & V_24 , V_25 ) ;
if ( V_11 -> V_63 == 1 )
V_33 = F_217 ( V_11 ) ;
else
V_33 = F_219 ( V_11 ) ;
F_218 ( V_11 ) ;
F_15 ( & V_24 ) ;
if ( V_299 != V_11 -> V_16 . V_66 ) {
T_9 V_66 ;
V_66 = ( T_9 ) V_11 -> V_16 . V_66 / V_300 ;
F_20 ( L_50 , ( unsigned long long ) V_66 ) ;
F_220 ( V_11 -> V_27 , V_66 ) ;
F_221 ( V_11 -> V_27 ) ;
}
return V_33 ;
}
static int F_222 ( struct V_10 * V_11 )
{
struct V_26 * V_27 ;
struct V_278 * V_279 ;
V_76 V_123 ;
V_27 = F_223 ( V_301 ) ;
if ( ! V_27 )
return - V_34 ;
snprintf ( V_27 -> V_302 , sizeof( V_27 -> V_302 ) , V_303 L_51 ,
V_11 -> V_304 ) ;
V_27 -> V_305 = V_11 -> V_305 ;
V_27 -> V_306 = 0 ;
V_27 -> V_307 = & V_308 ;
V_27 -> V_13 = V_11 ;
V_279 = F_224 ( F_204 , & V_11 -> V_19 ) ;
if ( ! V_279 )
goto V_309;
F_225 ( V_279 , V_300 ) ;
V_123 = F_78 ( & V_11 -> V_79 ) ;
F_226 ( V_279 , V_123 / V_300 ) ;
F_227 ( V_279 , V_123 ) ;
F_228 ( V_279 , V_123 ) ;
F_229 ( V_279 , V_123 ) ;
F_230 ( V_279 , F_210 ) ;
V_27 -> V_296 = V_279 ;
V_279 -> V_281 = V_11 ;
V_11 -> V_27 = V_27 ;
return 0 ;
V_309:
F_215 ( V_27 ) ;
return - V_34 ;
}
static struct V_10 * F_231 ( struct V_5 * V_6 )
{
return F_45 ( V_6 , struct V_10 , V_6 ) ;
}
static T_10 F_232 ( struct V_5 * V_6 ,
struct V_310 * V_311 , char * V_133 )
{
struct V_10 * V_11 = F_231 ( V_6 ) ;
return sprintf ( V_133 , L_52 ,
( unsigned long long ) V_11 -> V_16 . V_66 ) ;
}
static T_10 F_233 ( struct V_5 * V_6 ,
struct V_310 * V_311 , char * V_133 )
{
struct V_10 * V_11 = F_231 ( V_6 ) ;
return sprintf ( V_133 , L_53 ,
( unsigned long long ) V_11 -> V_16 . V_100 ) ;
}
static T_10 F_234 ( struct V_5 * V_6 ,
struct V_310 * V_311 , char * V_133 )
{
struct V_10 * V_11 = F_231 ( V_6 ) ;
if ( V_11 -> V_305 )
return sprintf ( V_133 , L_54 , V_11 -> V_305 ) ;
return sprintf ( V_133 , L_55 ) ;
}
static T_10 F_235 ( struct V_5 * V_6 ,
struct V_310 * V_311 , char * V_133 )
{
struct V_10 * V_11 = F_231 ( V_6 ) ;
return sprintf ( V_133 , L_56 ,
F_236 ( V_11 -> V_29 -> V_40 ) ) ;
}
static T_10 F_237 ( struct V_5 * V_6 ,
struct V_310 * V_311 , char * V_133 )
{
struct V_10 * V_11 = F_231 ( V_6 ) ;
return sprintf ( V_133 , L_57 , V_11 -> V_101 -> V_312 ) ;
}
static T_10 F_238 ( struct V_5 * V_6 ,
struct V_310 * V_311 , char * V_133 )
{
struct V_10 * V_11 = F_231 ( V_6 ) ;
return sprintf ( V_133 , L_52 ,
( unsigned long long ) V_11 -> V_101 -> V_313 ) ;
}
static T_10 F_239 ( struct V_5 * V_6 ,
struct V_310 * V_311 , char * V_133 )
{
struct V_10 * V_11 = F_231 ( V_6 ) ;
if ( V_11 -> V_101 -> V_314 )
return sprintf ( V_133 , L_57 , V_11 -> V_101 -> V_314 ) ;
return sprintf ( V_133 , L_58 ) ;
}
static T_10 F_240 ( struct V_5 * V_6 ,
struct V_310 * V_311 , char * V_133 )
{
struct V_10 * V_11 = F_231 ( V_6 ) ;
return sprintf ( V_133 , L_57 , V_11 -> V_101 -> V_315 ) ;
}
static T_10 F_241 ( struct V_5 * V_6 ,
struct V_310 * V_311 ,
char * V_133 )
{
struct V_10 * V_11 = F_231 ( V_6 ) ;
return sprintf ( V_133 , L_57 , V_11 -> V_101 -> V_106 ) ;
}
static T_10 F_242 ( struct V_5 * V_6 ,
struct V_310 * V_311 ,
char * V_133 )
{
struct V_10 * V_11 = F_231 ( V_6 ) ;
struct V_316 * V_101 = V_11 -> V_233 ;
int V_317 ;
char * V_318 = V_133 ;
if ( ! V_101 )
return sprintf ( V_133 , L_59 ) ;
V_317 = sprintf ( V_318 , L_60 ,
( unsigned long long ) V_101 -> V_313 , V_101 -> V_312 ) ;
if ( V_317 < 0 )
return V_317 ;
V_318 += V_317 ;
V_317 = sprintf ( V_318 , L_61 , V_101 -> V_315 ,
V_101 -> V_314 ? V_101 -> V_314 : L_62 ) ;
if ( V_317 < 0 )
return V_317 ;
V_318 += V_317 ;
V_317 = sprintf ( V_318 , L_63 ,
( unsigned long long ) V_101 -> V_102 , V_101 -> V_106 ) ;
if ( V_317 < 0 )
return V_317 ;
V_318 += V_317 ;
V_317 = sprintf ( V_318 , L_64 , V_11 -> V_198 ) ;
if ( V_317 < 0 )
return V_317 ;
V_318 += V_317 ;
return ( T_10 ) ( V_318 - V_133 ) ;
}
static T_10 F_243 ( struct V_5 * V_6 ,
struct V_310 * V_311 ,
const char * V_133 ,
T_5 V_66 )
{
struct V_10 * V_11 = F_231 ( V_6 ) ;
int V_33 ;
V_33 = F_192 ( V_11 ) ;
if ( V_33 )
F_98 ( V_11 , L_65 , V_33 ) ;
return V_33 < 0 ? V_33 : V_66 ;
}
static void F_244 ( struct V_5 * V_6 )
{
}
static struct V_316 * F_245 ( struct V_316 * V_101 )
{
F_35 ( & V_101 -> V_38 ) ;
return V_101 ;
}
static void F_156 ( struct V_316 * V_101 )
{
if ( V_101 )
F_48 ( & V_101 -> V_38 , V_319 ) ;
}
static struct V_316 * F_246 ( void )
{
struct V_316 * V_101 ;
V_101 = F_247 ( sizeof ( * V_101 ) , V_36 ) ;
if ( ! V_101 )
return NULL ;
F_22 ( & V_101 -> V_38 ) ;
return V_101 ;
}
static void V_319 ( struct V_38 * V_38 )
{
struct V_316 * V_101 = F_45 ( V_38 , struct V_316 , V_38 ) ;
F_31 ( V_101 -> V_312 ) ;
F_31 ( V_101 -> V_315 ) ;
F_31 ( V_101 -> V_314 ) ;
F_31 ( V_101 -> V_106 ) ;
F_31 ( V_101 ) ;
}
static struct V_10 * F_248 ( struct V_29 * V_32 ,
struct V_316 * V_101 )
{
struct V_10 * V_11 ;
V_11 = F_247 ( sizeof ( * V_11 ) , V_36 ) ;
if ( ! V_11 )
return NULL ;
F_163 ( & V_11 -> V_19 ) ;
V_11 -> V_21 = 0 ;
F_249 ( & V_11 -> V_234 , 0 ) ;
F_23 ( & V_11 -> V_39 ) ;
F_250 ( & V_11 -> V_94 ) ;
V_11 -> V_101 = V_101 ;
V_11 -> V_29 = V_32 ;
V_11 -> V_230 . V_320 = F_251 ( 1 << V_321 ) ;
V_11 -> V_230 . V_322 = F_251 ( 1 ) ;
V_11 -> V_230 . V_323 = F_251 ( 1 << V_321 ) ;
V_11 -> V_230 . V_324 = F_251 ( ( T_4 ) V_101 -> V_313 ) ;
return V_11 ;
}
static void F_252 ( struct V_10 * V_11 )
{
F_47 ( V_11 -> V_29 ) ;
F_156 ( V_11 -> V_101 ) ;
F_31 ( V_11 ) ;
}
static int F_67 ( struct V_10 * V_11 , V_76 V_102 ,
T_8 * V_71 , V_76 * V_114 )
{
V_75 V_325 = F_253 ( V_102 ) ;
int V_33 ;
struct {
T_8 V_71 ;
V_75 V_66 ;
} V_326 ( ( V_327 ) ) V_328 = { 0 } ;
V_33 = F_198 ( V_11 , V_11 -> V_261 ,
L_37 , L_66 ,
& V_325 , sizeof ( V_325 ) ,
& V_328 , sizeof ( V_328 ) ) ;
F_20 ( L_67 , V_35 , V_33 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_33 < sizeof ( V_328 ) )
return - V_329 ;
if ( V_71 )
* V_71 = V_328 . V_71 ;
* V_114 = F_52 ( V_328 . V_66 ) ;
F_20 ( L_68 ,
( unsigned long long ) V_102 , ( unsigned int ) * V_71 ,
( unsigned long long ) * V_114 ) ;
return 0 ;
}
static int F_254 ( struct V_10 * V_11 )
{
return F_67 ( V_11 , V_103 ,
& V_11 -> V_79 . V_95 ,
& V_11 -> V_79 . V_93 ) ;
}
static int F_255 ( struct V_10 * V_11 )
{
void * V_330 ;
int V_33 ;
void * V_331 ;
V_330 = F_247 ( V_332 , V_36 ) ;
if ( ! V_330 )
return - V_34 ;
V_33 = F_198 ( V_11 , V_11 -> V_261 ,
L_37 , L_69 , NULL , 0 ,
V_330 , V_332 ) ;
F_20 ( L_67 , V_35 , V_33 ) ;
if ( V_33 < 0 )
goto V_244;
V_331 = V_330 ;
V_11 -> V_79 . V_81 = F_256 ( & V_331 ,
V_331 + V_33 , NULL , V_121 ) ;
V_33 = 0 ;
if ( F_25 ( V_11 -> V_79 . V_81 ) ) {
V_33 = F_181 ( V_11 -> V_79 . V_81 ) ;
V_11 -> V_79 . V_81 = NULL ;
} else {
F_20 ( L_70 , V_11 -> V_79 . V_81 ) ;
}
V_244:
F_31 ( V_330 ) ;
return V_33 ;
}
static int F_69 ( struct V_10 * V_11 , V_76 V_102 ,
V_76 * V_115 )
{
V_75 V_325 = F_253 ( V_102 ) ;
struct {
V_75 V_100 ;
V_75 V_333 ;
} V_326 ( ( V_327 ) ) V_334 = { 0 } ;
V_76 V_333 ;
int V_33 ;
V_33 = F_198 ( V_11 , V_11 -> V_261 ,
L_37 , L_71 ,
& V_325 , sizeof ( V_325 ) ,
& V_334 , sizeof ( V_334 ) ) ;
F_20 ( L_67 , V_35 , V_33 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_33 < sizeof ( V_334 ) )
return - V_329 ;
V_333 = F_52 ( V_334 . V_333 ) ;
if ( V_333 & ~ V_335 )
return - V_288 ;
* V_115 = F_52 ( V_334 . V_100 ) ;
F_20 ( L_72 ,
( unsigned long long ) V_102 ,
( unsigned long long ) * V_115 ,
( unsigned long long ) F_52 ( V_334 . V_333 ) ) ;
return 0 ;
}
static int F_257 ( struct V_10 * V_11 )
{
return F_69 ( V_11 , V_103 ,
& V_11 -> V_79 . V_100 ) ;
}
static int F_258 ( struct V_10 * V_11 )
{
struct V_316 * V_233 ;
T_5 V_66 ;
void * V_330 = NULL ;
V_75 V_325 ;
void * V_331 ;
void * V_139 ;
V_76 V_313 ;
char * V_315 ;
V_76 V_336 ;
int V_33 ;
V_233 = F_246 () ;
if ( ! V_233 )
return - V_34 ;
V_66 = sizeof ( V_75 ) +
sizeof ( V_255 ) + V_337 +
sizeof ( V_75 ) +
sizeof ( V_75 ) ;
V_330 = F_21 ( V_66 , V_36 ) ;
if ( ! V_330 ) {
V_33 = - V_34 ;
goto V_42;
}
V_325 = F_253 ( V_103 ) ;
V_33 = F_198 ( V_11 , V_11 -> V_261 ,
L_37 , L_73 ,
& V_325 , sizeof ( V_325 ) ,
V_330 , V_66 ) ;
F_20 ( L_67 , V_35 , V_33 ) ;
if ( V_33 < 0 )
goto V_42;
V_331 = V_330 ;
V_139 = V_330 + V_33 ;
V_33 = - V_329 ;
F_259 ( & V_331 , V_139 , V_313 , V_42 ) ;
if ( V_313 == V_338 ) {
if ( V_11 -> V_198 ) {
V_11 -> V_198 = 0 ;
F_103 () ;
F_157 ( V_11 ) ;
F_260 ( L_74 ,
V_11 -> V_27 -> V_302 ) ;
}
goto V_244;
}
V_33 = - V_104 ;
if ( V_313 > ( V_76 ) V_339 ) {
F_98 ( NULL , L_75 ,
( unsigned long long ) V_313 , V_339 ) ;
goto V_42;
}
V_233 -> V_313 = V_313 ;
V_315 = F_256 ( & V_331 , V_139 , NULL , V_36 ) ;
if ( F_25 ( V_315 ) ) {
V_33 = F_181 ( V_315 ) ;
goto V_42;
}
V_233 -> V_315 = V_315 ;
F_259 ( & V_331 , V_139 , V_233 -> V_102 , V_42 ) ;
F_259 ( & V_331 , V_139 , V_336 , V_42 ) ;
if ( V_336 ) {
F_156 ( V_11 -> V_233 ) ;
V_11 -> V_233 = V_233 ;
V_233 = NULL ;
V_11 -> V_198 = V_336 ;
} else {
F_98 ( V_11 , L_76 ) ;
}
V_244:
V_33 = 0 ;
V_42:
F_31 ( V_330 ) ;
F_156 ( V_233 ) ;
return V_33 ;
}
static int F_261 ( struct V_10 * V_11 )
{
struct {
V_75 V_98 ;
V_75 V_99 ;
} V_326 ( ( V_327 ) ) V_340 = { 0 } ;
T_5 V_66 = sizeof ( V_340 ) ;
void * V_331 ;
V_76 V_341 ;
V_76 V_98 ;
V_76 V_99 ;
int V_33 ;
V_33 = F_198 ( V_11 , V_11 -> V_261 ,
L_37 , L_77 , NULL , 0 ,
( char * ) & V_340 , V_66 ) ;
F_20 ( L_67 , V_35 , V_33 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_33 < V_66 )
return - V_329 ;
V_33 = - V_4 ;
V_341 = ( V_76 ) 1 << V_11 -> V_79 . V_95 ;
V_331 = & V_340 ;
V_98 = F_262 ( & V_331 ) ;
if ( V_98 != V_341 ) {
F_98 ( V_11 , L_78
L_79 ,
V_98 , V_341 ) ;
return - V_4 ;
}
V_99 = F_262 ( & V_331 ) ;
if ( V_99 != 1 ) {
F_98 ( V_11 , L_80
L_81 , V_99 ) ;
return - V_4 ;
}
V_11 -> V_79 . V_98 = V_98 ;
V_11 -> V_79 . V_99 = V_99 ;
return 0 ;
}
static char * F_263 ( struct V_10 * V_11 )
{
T_5 V_342 ;
char * V_315 ;
void * V_331 ;
void * V_139 ;
T_5 V_66 ;
void * V_330 = NULL ;
T_5 V_86 = 0 ;
char * V_314 = NULL ;
int V_33 ;
F_17 ( ! V_11 -> V_101 -> V_314 ) ;
V_86 = strlen ( V_11 -> V_101 -> V_315 ) ;
V_342 = sizeof ( V_255 ) + V_86 ;
V_315 = F_21 ( V_342 , V_36 ) ;
if ( ! V_315 )
return NULL ;
V_331 = V_315 ;
V_139 = V_315 + V_342 ;
F_264 ( & V_331 , V_139 , V_11 -> V_101 -> V_315 , ( T_4 ) V_86 ) ;
V_66 = sizeof ( V_255 ) + V_343 ;
V_330 = F_21 ( V_66 , V_36 ) ;
if ( ! V_330 )
goto V_244;
V_33 = F_198 ( V_11 , V_344 ,
L_37 , L_82 ,
V_315 , V_342 ,
V_330 , V_66 ) ;
if ( V_33 < 0 )
goto V_244;
V_331 = V_330 ;
V_139 = V_330 + V_33 ;
V_314 = F_256 ( & V_331 , V_139 , & V_86 , V_36 ) ;
if ( F_25 ( V_314 ) )
V_314 = NULL ;
else
F_20 ( L_83 , V_35 , V_314 , V_86 ) ;
V_244:
F_31 ( V_330 ) ;
F_31 ( V_315 ) ;
return V_314 ;
}
static V_76 F_265 ( struct V_10 * V_11 , const char * V_117 )
{
struct V_74 * V_82 = V_11 -> V_79 . V_82 ;
const char * V_106 ;
T_4 V_105 = 0 ;
V_106 = V_11 -> V_79 . V_83 ;
while ( V_105 < V_82 -> V_107 ) {
if ( ! strcmp ( V_117 , V_106 ) )
return V_82 -> V_90 [ V_105 ] ;
V_106 += strlen ( V_106 ) + 1 ;
V_105 ++ ;
}
return V_103 ;
}
static V_76 F_266 ( struct V_10 * V_11 , const char * V_117 )
{
struct V_74 * V_82 = V_11 -> V_79 . V_82 ;
T_4 V_105 ;
bool V_46 = false ;
V_76 V_102 ;
for ( V_105 = 0 ; ! V_46 && V_105 < V_82 -> V_107 ; V_105 ++ ) {
const char * V_106 ;
V_102 = V_82 -> V_90 [ V_105 ] ;
V_106 = F_65 ( V_11 , V_102 ) ;
if ( F_25 ( V_106 ) )
break;
V_46 = ! strcmp ( V_117 , V_106 ) ;
F_31 ( V_106 ) ;
}
return V_46 ? V_102 : V_103 ;
}
static V_76 F_267 ( struct V_10 * V_11 , const char * V_117 )
{
if ( V_11 -> V_63 == 1 )
return F_265 ( V_11 , V_117 ) ;
return F_266 ( V_11 , V_117 ) ;
}
static int F_268 ( struct V_10 * V_11 )
{
struct V_186 * V_187 = & V_11 -> V_29 -> V_40 -> V_187 ;
struct V_316 * V_101 = V_11 -> V_101 ;
const char * V_312 ;
const char * V_314 ;
const char * V_106 ;
int V_33 ;
if ( V_101 -> V_312 ) {
if ( strcmp ( V_101 -> V_106 , V_113 ) ) {
V_76 V_102 ;
V_102 = F_267 ( V_11 , V_101 -> V_106 ) ;
if ( V_102 == V_103 )
return - V_23 ;
V_101 -> V_102 = V_102 ;
} else {
V_101 -> V_102 = V_103 ;
}
return 0 ;
}
V_312 = F_269 ( V_187 -> V_345 , V_101 -> V_313 ) ;
if ( ! V_312 ) {
F_98 ( V_11 , L_84 , V_101 -> V_313 ) ;
return - V_104 ;
}
V_312 = F_60 ( V_312 , V_36 ) ;
if ( ! V_312 )
return - V_34 ;
V_314 = F_263 ( V_11 ) ;
if ( ! V_314 )
F_98 ( V_11 , L_85 ) ;
V_106 = F_64 ( V_11 , V_101 -> V_102 ) ;
if ( ! V_106 ) {
V_33 = - V_34 ;
goto V_42;
}
V_101 -> V_312 = V_312 ;
V_101 -> V_314 = V_314 ;
V_101 -> V_106 = V_106 ;
return 0 ;
V_42:
F_31 ( V_314 ) ;
F_31 ( V_312 ) ;
return V_33 ;
}
static int F_270 ( struct V_10 * V_11 )
{
T_5 V_66 ;
int V_33 ;
void * V_330 ;
void * V_331 ;
void * V_139 ;
V_76 V_87 ;
T_4 V_67 ;
struct V_74 * V_82 ;
T_4 V_85 ;
V_66 = sizeof ( V_75 ) + sizeof ( V_255 ) +
V_346 * sizeof ( V_75 ) ;
V_330 = F_247 ( V_66 , V_36 ) ;
if ( ! V_330 )
return - V_34 ;
V_33 = F_198 ( V_11 , V_11 -> V_261 ,
L_37 , L_86 , NULL , 0 ,
V_330 , V_66 ) ;
F_20 ( L_67 , V_35 , V_33 ) ;
if ( V_33 < 0 )
goto V_244;
V_331 = V_330 ;
V_139 = V_330 + V_33 ;
V_33 = - V_329 ;
F_259 ( & V_331 , V_139 , V_87 , V_244 ) ;
F_271 ( & V_331 , V_139 , V_67 , V_244 ) ;
if ( V_67 > ( V_73 - sizeof ( struct V_74 ) )
/ sizeof ( V_76 ) ) {
V_33 = - V_4 ;
goto V_244;
}
if ( ! F_272 ( & V_331 , V_139 , V_67 * sizeof ( V_75 ) ) )
goto V_244;
V_33 = 0 ;
V_82 = F_55 ( V_67 , V_36 ) ;
if ( ! V_82 ) {
V_33 = - V_34 ;
goto V_244;
}
V_82 -> V_87 = V_87 ;
for ( V_85 = 0 ; V_85 < V_67 ; V_85 ++ )
V_82 -> V_90 [ V_85 ] = F_262 ( & V_331 ) ;
F_57 ( V_11 -> V_79 . V_82 ) ;
V_11 -> V_79 . V_82 = V_82 ;
F_20 ( L_87 ,
( unsigned long long ) V_87 , ( unsigned int ) V_67 ) ;
V_244:
F_31 ( V_330 ) ;
return V_33 ;
}
static const char * F_65 ( struct V_10 * V_11 ,
V_76 V_102 )
{
T_5 V_66 ;
void * V_330 ;
V_75 V_325 ;
int V_33 ;
void * V_331 ;
void * V_139 ;
char * V_106 ;
V_66 = sizeof ( V_255 ) + V_347 ;
V_330 = F_21 ( V_66 , V_36 ) ;
if ( ! V_330 )
return F_33 ( - V_34 ) ;
V_325 = F_253 ( V_102 ) ;
V_33 = F_198 ( V_11 , V_11 -> V_261 ,
L_37 , L_88 ,
& V_325 , sizeof ( V_325 ) ,
V_330 , V_66 ) ;
F_20 ( L_67 , V_35 , V_33 ) ;
if ( V_33 < 0 ) {
V_106 = F_33 ( V_33 ) ;
goto V_244;
}
V_331 = V_330 ;
V_139 = V_330 + V_33 ;
V_106 = F_256 ( & V_331 , V_139 , NULL , V_36 ) ;
if ( F_25 ( V_106 ) )
goto V_244;
F_20 ( L_89 ,
( unsigned long long ) V_102 , V_106 ) ;
V_244:
F_31 ( V_330 ) ;
return V_106 ;
}
static int F_219 ( struct V_10 * V_11 )
{
bool V_80 = V_11 -> V_79 . V_81 == NULL ;
int V_33 ;
F_56 ( & V_11 -> V_94 ) ;
V_33 = F_254 ( V_11 ) ;
if ( V_33 )
goto V_244;
if ( V_80 ) {
V_33 = F_273 ( V_11 ) ;
if ( V_33 )
goto V_244;
}
if ( V_11 -> V_79 . V_100 & V_348 &&
( V_80 || V_11 -> V_233 ) ) {
bool V_349 ;
V_33 = F_258 ( V_11 ) ;
if ( V_33 )
goto V_244;
V_349 = V_11 -> V_233 && V_11 -> V_101 -> V_312 ;
if ( V_80 && V_349 )
F_98 ( V_11 , L_90
L_91 ) ;
}
if ( V_11 -> V_101 -> V_102 == V_103 )
if ( V_11 -> V_16 . V_66 != V_11 -> V_79 . V_93 )
V_11 -> V_16 . V_66 = V_11 -> V_79 . V_93 ;
V_33 = F_270 ( V_11 ) ;
F_20 ( L_92 , V_33 ) ;
V_244:
F_58 ( & V_11 -> V_94 ) ;
return V_33 ;
}
static int F_274 ( struct V_10 * V_11 )
{
struct V_5 * V_6 ;
int V_33 ;
F_12 ( & V_24 , V_25 ) ;
V_6 = & V_11 -> V_6 ;
V_6 -> V_350 = & V_351 ;
V_6 -> type = & V_352 ;
V_6 -> V_241 = & V_353 ;
V_6 -> V_354 = V_355 ;
F_275 ( V_6 , L_51 , V_11 -> V_304 ) ;
V_33 = F_276 ( V_6 ) ;
F_15 ( & V_24 ) ;
return V_33 ;
}
static void F_277 ( struct V_10 * V_11 )
{
F_278 ( & V_11 -> V_6 ) ;
}
static void F_279 ( struct V_10 * V_11 )
{
V_11 -> V_304 = F_280 ( & V_356 ) ;
F_27 ( & V_357 ) ;
F_28 ( & V_11 -> V_39 , & V_358 ) ;
F_29 ( & V_357 ) ;
F_20 ( L_93 , V_11 ,
( unsigned long long ) V_11 -> V_304 ) ;
}
static void F_281 ( struct V_10 * V_11 )
{
struct V_359 * V_128 ;
int V_360 = V_11 -> V_304 ;
int V_361 ;
F_17 ( V_360 > 0 ) ;
F_20 ( L_94 , V_11 ,
( unsigned long long ) V_11 -> V_304 ) ;
F_27 ( & V_357 ) ;
F_282 ( & V_11 -> V_39 ) ;
if ( V_360 != F_283 ( & V_356 ) ) {
F_29 ( & V_357 ) ;
return;
}
V_361 = 0 ;
F_284 (tmp, &rbd_dev_list) {
struct V_10 * V_11 ;
V_11 = F_285 ( V_128 , struct V_10 , V_39 ) ;
if ( V_11 -> V_304 > V_361 )
V_361 = V_11 -> V_304 ;
}
F_29 ( & V_357 ) ;
F_286 ( & V_356 , V_360 , V_361 ) ;
F_20 ( L_95 ) ;
}
static inline T_5 F_287 ( const char * * V_133 )
{
const char * V_362 = L_96 ;
* V_133 += strspn ( * V_133 , V_362 ) ;
return strcspn ( * V_133 , V_362 ) ;
}
static inline T_5 F_288 ( const char * * V_133 ,
char * V_54 ,
T_5 V_363 )
{
T_5 V_86 ;
V_86 = F_287 ( V_133 ) ;
if ( V_86 < V_363 ) {
memcpy ( V_54 , * V_133 , V_86 ) ;
* ( V_54 + V_86 ) = '\0' ;
}
* V_133 += V_86 ;
return V_86 ;
}
static inline char * F_289 ( const char * * V_133 , T_5 * V_364 )
{
char * V_365 ;
T_5 V_86 ;
V_86 = F_287 ( V_133 ) ;
V_365 = F_290 ( * V_133 , V_86 + 1 , V_36 ) ;
if ( ! V_365 )
return NULL ;
* ( V_365 + V_86 ) = '\0' ;
* V_133 += V_86 ;
if ( V_364 )
* V_364 = V_86 ;
return V_365 ;
}
static int F_291 ( const char * V_133 ,
struct V_30 * * V_31 ,
struct V_50 * * V_366 ,
struct V_316 * * V_316 )
{
T_5 V_86 ;
char * V_70 ;
const char * V_367 ;
char * V_106 ;
T_5 V_368 ;
struct V_316 * V_101 = NULL ;
struct V_50 * V_51 = NULL ;
struct V_30 * V_369 ;
int V_33 ;
V_86 = F_287 ( & V_133 ) ;
if ( ! V_86 ) {
F_98 ( NULL , L_97 ) ;
return - V_4 ;
}
V_367 = V_133 ;
V_368 = V_86 + 1 ;
V_133 += V_86 ;
V_33 = - V_4 ;
V_70 = F_289 ( & V_133 , NULL ) ;
if ( ! V_70 )
return - V_34 ;
if ( ! * V_70 ) {
F_98 ( NULL , L_98 ) ;
goto V_42;
}
V_101 = F_246 () ;
if ( ! V_101 )
goto V_370;
V_101 -> V_312 = F_289 ( & V_133 , NULL ) ;
if ( ! V_101 -> V_312 )
goto V_370;
if ( ! * V_101 -> V_312 ) {
F_98 ( NULL , L_99 ) ;
goto V_42;
}
V_101 -> V_314 = F_289 ( & V_133 , NULL ) ;
if ( ! V_101 -> V_314 )
goto V_370;
if ( ! * V_101 -> V_314 ) {
F_98 ( NULL , L_100 ) ;
goto V_42;
}
V_86 = F_287 ( & V_133 ) ;
if ( ! V_86 ) {
V_133 = V_113 ;
V_86 = sizeof ( V_113 ) - 1 ;
} else if ( V_86 > V_347 ) {
V_33 = - V_371 ;
goto V_42;
}
V_106 = F_290 ( V_133 , V_86 + 1 , V_36 ) ;
if ( ! V_106 )
goto V_370;
* ( V_106 + V_86 ) = '\0' ;
V_101 -> V_106 = V_106 ;
V_51 = F_247 ( sizeof ( * V_51 ) , V_36 ) ;
if ( ! V_51 )
goto V_370;
V_51 -> V_17 = V_372 ;
V_369 = F_292 ( V_70 , V_367 ,
V_367 + V_368 - 1 ,
F_39 , V_51 ) ;
if ( F_25 ( V_369 ) ) {
V_33 = F_181 ( V_369 ) ;
goto V_42;
}
F_31 ( V_70 ) ;
* V_31 = V_369 ;
* V_366 = V_51 ;
* V_316 = V_101 ;
return 0 ;
V_370:
V_33 = - V_34 ;
V_42:
F_31 ( V_51 ) ;
F_156 ( V_101 ) ;
F_31 ( V_70 ) ;
return V_33 ;
}
static int F_293 ( struct V_10 * V_11 )
{
int V_33 ;
T_5 V_66 ;
char * V_216 ;
void * V_373 ;
char * V_315 ;
if ( V_11 -> V_101 -> V_315 ) {
V_11 -> V_63 = * V_11 -> V_101 -> V_315 ? 2 : 1 ;
return 0 ;
}
V_66 = sizeof ( V_374 ) + strlen ( V_11 -> V_101 -> V_314 ) ;
V_216 = F_21 ( V_66 , V_121 ) ;
if ( ! V_216 )
return - V_34 ;
sprintf ( V_216 , L_101 , V_374 , V_11 -> V_101 -> V_314 ) ;
F_20 ( L_102 , V_216 ) ;
V_66 = sizeof ( V_255 ) + V_337 ;
V_373 = F_247 ( V_66 , V_121 ) ;
if ( ! V_373 ) {
V_33 = - V_34 ;
goto V_244;
}
V_33 = F_198 ( V_11 , V_216 ,
L_37 , L_103 , NULL , 0 ,
V_373 , V_337 ) ;
F_20 ( L_67 , V_35 , V_33 ) ;
if ( V_33 == - V_23 ) {
V_315 = F_60 ( L_104 , V_36 ) ;
V_33 = V_315 ? 0 : - V_34 ;
if ( ! V_33 )
V_11 -> V_63 = 1 ;
} else if ( V_33 > sizeof ( V_255 ) ) {
void * V_331 = V_373 ;
V_315 = F_256 ( & V_331 , V_331 + V_33 ,
NULL , V_121 ) ;
V_33 = F_25 ( V_315 ) ? F_181 ( V_315 ) : 0 ;
if ( ! V_33 )
V_11 -> V_63 = 2 ;
} else {
V_33 = - V_4 ;
}
if ( ! V_33 ) {
V_11 -> V_101 -> V_315 = V_315 ;
F_20 ( L_105 , V_315 ) ;
}
V_244:
F_31 ( V_373 ) ;
F_31 ( V_216 ) ;
return V_33 ;
}
static void F_294 ( struct V_10 * V_11 )
{
struct V_78 * V_79 ;
if ( V_11 -> V_198 )
F_157 ( V_11 ) ;
V_79 = & V_11 -> V_79 ;
F_57 ( V_79 -> V_82 ) ;
F_31 ( V_79 -> V_84 ) ;
F_31 ( V_79 -> V_83 ) ;
F_31 ( V_79 -> V_81 ) ;
memset ( V_79 , 0 , sizeof ( * V_79 ) ) ;
}
static int F_273 ( struct V_10 * V_11 )
{
int V_33 ;
V_33 = F_255 ( V_11 ) ;
if ( V_33 )
goto V_42;
V_33 = F_257 ( V_11 ) ;
if ( V_33 )
goto V_42;
if ( V_11 -> V_79 . V_100 & V_375 ) {
V_33 = F_261 ( V_11 ) ;
if ( V_33 < 0 )
goto V_42;
}
return 0 ;
V_42:
V_11 -> V_79 . V_100 = 0 ;
F_31 ( V_11 -> V_79 . V_81 ) ;
V_11 -> V_79 . V_81 = NULL ;
return V_33 ;
}
static int F_295 ( struct V_10 * V_11 )
{
struct V_10 * V_241 = NULL ;
struct V_316 * V_233 ;
struct V_29 * V_32 ;
int V_33 ;
if ( ! V_11 -> V_233 )
return 0 ;
V_233 = F_245 ( V_11 -> V_233 ) ;
V_32 = F_34 ( V_11 -> V_29 ) ;
V_33 = - V_34 ;
V_241 = F_248 ( V_32 , V_233 ) ;
if ( ! V_241 )
goto V_42;
V_33 = F_296 ( V_241 , false ) ;
if ( V_33 < 0 )
goto V_42;
V_11 -> V_241 = V_241 ;
F_249 ( & V_11 -> V_234 , 1 ) ;
return 0 ;
V_42:
if ( V_241 ) {
F_154 ( V_11 ) ;
F_31 ( V_11 -> V_261 ) ;
F_252 ( V_241 ) ;
} else {
F_47 ( V_32 ) ;
F_156 ( V_233 ) ;
}
return V_33 ;
}
static int F_297 ( struct V_10 * V_11 )
{
int V_33 ;
F_279 ( V_11 ) ;
F_298 ( V_376
< sizeof ( V_303 ) + V_377 ) ;
sprintf ( V_11 -> V_117 , L_106 , V_303 , V_11 -> V_304 ) ;
V_33 = F_299 ( 0 , V_11 -> V_117 ) ;
if ( V_33 < 0 )
goto V_378;
V_11 -> V_305 = V_33 ;
V_33 = F_222 ( V_11 ) ;
if ( V_33 )
goto V_379;
V_33 = F_70 ( V_11 ) ;
if ( V_33 )
goto V_380;
F_220 ( V_11 -> V_27 , V_11 -> V_16 . V_66 / V_300 ) ;
V_33 = F_274 ( V_11 ) ;
if ( V_33 )
goto V_381;
F_107 ( V_287 , & V_11 -> V_21 ) ;
F_300 ( V_11 -> V_27 ) ;
F_260 ( L_107 , V_11 -> V_27 -> V_302 ,
( unsigned long long ) V_11 -> V_16 . V_66 ) ;
return V_33 ;
V_381:
F_71 ( V_11 ) ;
V_380:
F_212 ( V_11 ) ;
V_379:
F_301 ( V_11 -> V_305 , V_11 -> V_117 ) ;
V_378:
F_281 ( V_11 ) ;
F_71 ( V_11 ) ;
return V_33 ;
}
static int F_302 ( struct V_10 * V_11 )
{
struct V_316 * V_101 = V_11 -> V_101 ;
T_5 V_66 ;
F_17 ( F_49 ( V_11 -> V_63 ) ) ;
if ( V_11 -> V_63 == 1 )
V_66 = strlen ( V_101 -> V_314 ) + sizeof ( V_382 ) ;
else
V_66 = sizeof ( V_383 ) + strlen ( V_101 -> V_315 ) ;
V_11 -> V_261 = F_21 ( V_66 , V_36 ) ;
if ( ! V_11 -> V_261 )
return - V_34 ;
if ( V_11 -> V_63 == 1 )
sprintf ( V_11 -> V_261 , L_101 ,
V_101 -> V_314 , V_382 ) ;
else
sprintf ( V_11 -> V_261 , L_101 ,
V_383 , V_101 -> V_315 ) ;
return 0 ;
}
static void F_303 ( struct V_10 * V_11 )
{
F_294 ( V_11 ) ;
F_31 ( V_11 -> V_261 ) ;
V_11 -> V_261 = NULL ;
V_11 -> V_63 = 0 ;
F_31 ( V_11 -> V_101 -> V_315 ) ;
V_11 -> V_101 -> V_315 = NULL ;
F_252 ( V_11 ) ;
}
static int F_296 ( struct V_10 * V_11 , bool V_16 )
{
int V_33 ;
int V_128 ;
V_33 = F_293 ( V_11 ) ;
if ( V_33 )
return V_33 ;
F_17 ( V_11 -> V_101 -> V_315 ) ;
F_17 ( F_49 ( V_11 -> V_63 ) ) ;
V_33 = F_302 ( V_11 ) ;
if ( V_33 )
goto V_384;
if ( V_16 ) {
V_33 = F_193 ( V_11 , true ) ;
if ( V_33 )
goto V_385;
}
if ( V_11 -> V_63 == 1 )
V_33 = F_217 ( V_11 ) ;
else
V_33 = F_219 ( V_11 ) ;
if ( V_33 )
goto V_386;
V_33 = F_268 ( V_11 ) ;
if ( V_33 )
goto V_387;
V_33 = F_295 ( V_11 ) ;
if ( V_33 )
goto V_387;
F_20 ( L_108 ,
V_11 -> V_63 , V_11 -> V_261 ) ;
return 0 ;
V_387:
F_294 ( V_11 ) ;
V_386:
if ( V_16 ) {
V_128 = F_193 ( V_11 , false ) ;
if ( V_128 )
F_98 ( V_11 , L_109
L_110 , V_128 ) ;
}
V_385:
F_31 ( V_11 -> V_261 ) ;
V_11 -> V_261 = NULL ;
V_384:
V_11 -> V_63 = 0 ;
F_31 ( V_11 -> V_101 -> V_315 ) ;
V_11 -> V_101 -> V_315 = NULL ;
F_20 ( L_111 , V_33 ) ;
return V_33 ;
}
static T_10 F_304 ( struct V_388 * V_350 ,
const char * V_133 ,
T_5 V_317 )
{
struct V_10 * V_11 = NULL ;
struct V_30 * V_31 = NULL ;
struct V_50 * V_51 = NULL ;
struct V_316 * V_101 = NULL ;
struct V_29 * V_32 ;
struct V_186 * V_187 ;
bool V_17 ;
int V_389 = - V_34 ;
if ( ! F_305 ( V_390 ) )
return - V_391 ;
V_389 = F_291 ( V_133 , & V_31 , & V_51 , & V_101 ) ;
if ( V_389 < 0 )
goto V_392;
V_17 = V_51 -> V_17 ;
F_31 ( V_51 ) ;
V_51 = NULL ;
V_32 = F_43 ( V_31 ) ;
if ( F_25 ( V_32 ) ) {
V_389 = F_181 ( V_32 ) ;
goto V_393;
}
V_187 = & V_32 -> V_40 -> V_187 ;
V_389 = F_306 ( V_187 -> V_345 , V_101 -> V_312 ) ;
if ( V_389 < 0 )
goto V_394;
V_101 -> V_313 = ( V_76 ) V_389 ;
if ( V_101 -> V_313 > ( V_76 ) V_339 ) {
F_98 ( NULL , L_112 ,
( unsigned long long ) V_101 -> V_313 , V_339 ) ;
V_389 = - V_104 ;
goto V_394;
}
V_11 = F_248 ( V_32 , V_101 ) ;
if ( ! V_11 )
goto V_394;
V_32 = NULL ;
V_101 = NULL ;
V_389 = F_296 ( V_11 , true ) ;
if ( V_389 < 0 )
goto V_395;
if ( V_11 -> V_101 -> V_102 != V_103 )
V_17 = true ;
V_11 -> V_16 . V_17 = V_17 ;
V_389 = F_297 ( V_11 ) ;
if ( V_389 ) {
F_303 ( V_11 ) ;
goto V_392;
}
return V_317 ;
V_395:
F_252 ( V_11 ) ;
V_394:
F_47 ( V_32 ) ;
V_393:
F_156 ( V_101 ) ;
V_392:
F_307 ( V_390 ) ;
F_20 ( L_113 , V_133 ) ;
return ( T_10 ) V_389 ;
}
static struct V_10 * F_308 ( unsigned long V_304 )
{
struct V_359 * V_128 ;
struct V_10 * V_11 ;
F_27 ( & V_357 ) ;
F_309 (tmp, &rbd_dev_list) {
V_11 = F_285 ( V_128 , struct V_10 , V_39 ) ;
if ( V_11 -> V_304 == V_304 ) {
F_29 ( & V_357 ) ;
return V_11 ;
}
}
F_29 ( & V_357 ) ;
return NULL ;
}
static void V_355 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = F_231 ( V_6 ) ;
F_212 ( V_11 ) ;
F_128 ( V_287 , & V_11 -> V_21 ) ;
F_71 ( V_11 ) ;
F_301 ( V_11 -> V_305 , V_11 -> V_117 ) ;
V_11 -> V_305 = 0 ;
F_281 ( V_11 ) ;
F_71 ( V_11 ) ;
}
static void F_155 ( struct V_10 * V_11 )
{
while ( V_11 -> V_241 ) {
struct V_10 * V_396 = V_11 ;
struct V_10 * V_397 = V_396 -> V_241 ;
struct V_10 * V_398 ;
while ( V_397 && ( V_398 = V_397 -> V_241 ) ) {
V_396 = V_397 ;
V_397 = V_398 ;
}
F_17 ( V_397 ) ;
F_303 ( V_397 ) ;
V_396 -> V_241 = NULL ;
V_396 -> V_198 = 0 ;
F_17 ( V_396 -> V_233 ) ;
F_156 ( V_396 -> V_233 ) ;
V_396 -> V_233 = NULL ;
}
}
static T_10 F_310 ( struct V_388 * V_350 ,
const char * V_133 ,
T_5 V_317 )
{
struct V_10 * V_11 = NULL ;
int V_399 ;
unsigned long V_400 ;
int V_33 ;
V_33 = F_311 ( V_133 , 10 , & V_400 ) ;
if ( V_33 )
return V_33 ;
V_399 = ( int ) V_400 ;
if ( V_399 != V_400 )
return - V_4 ;
F_12 ( & V_24 , V_25 ) ;
V_11 = F_308 ( V_399 ) ;
if ( ! V_11 ) {
V_33 = - V_23 ;
goto V_401;
}
F_9 ( & V_11 -> V_19 ) ;
if ( V_11 -> V_22 )
V_33 = - V_402 ;
else
F_107 ( V_20 , & V_11 -> V_21 ) ;
F_11 ( & V_11 -> V_19 ) ;
if ( V_33 < 0 )
goto V_401;
F_277 ( V_11 ) ;
V_33 = F_193 ( V_11 , false ) ;
if ( V_33 )
F_98 ( V_11 , L_114 , V_33 ) ;
F_303 ( V_11 ) ;
F_307 ( V_390 ) ;
V_33 = V_317 ;
V_401:
F_15 ( & V_24 ) ;
return V_33 ;
}
static int F_312 ( void )
{
int V_33 ;
V_33 = F_276 ( & V_353 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_313 ( & V_351 ) ;
if ( V_33 < 0 )
F_278 ( & V_353 ) ;
return V_33 ;
}
static void F_314 ( void )
{
F_315 ( & V_351 ) ;
F_278 ( & V_353 ) ;
}
static int F_316 ( void )
{
F_17 ( ! V_235 ) ;
V_235 = F_317 ( L_115 ,
sizeof ( struct V_174 ) ,
F_318 ( struct V_174 ) ,
0 , NULL ) ;
if ( ! V_235 )
return - V_34 ;
F_17 ( ! V_231 ) ;
V_231 = F_317 ( L_116 ,
sizeof ( struct V_164 ) ,
F_318 ( struct V_164 ) ,
0 , NULL ) ;
if ( ! V_231 )
goto V_42;
F_17 ( ! V_120 ) ;
V_120 = F_317 ( L_117 ,
V_122 + 1 , 1 , 0 , NULL ) ;
if ( V_120 )
return 0 ;
V_42:
if ( V_231 ) {
F_319 ( V_231 ) ;
V_231 = NULL ;
}
F_319 ( V_235 ) ;
V_235 = NULL ;
return - V_34 ;
}
static void F_320 ( void )
{
F_17 ( V_120 ) ;
F_319 ( V_120 ) ;
V_120 = NULL ;
F_17 ( V_231 ) ;
F_319 ( V_231 ) ;
V_231 = NULL ;
F_17 ( V_235 ) ;
F_319 ( V_235 ) ;
V_235 = NULL ;
}
static int T_11 F_321 ( void )
{
int V_389 ;
if ( ! F_322 ( NULL ) ) {
F_98 ( NULL , L_118 ) ;
return - V_4 ;
}
V_389 = F_316 () ;
if ( V_389 )
return V_389 ;
V_389 = F_312 () ;
if ( V_389 )
F_320 () ;
else
F_260 ( L_119 V_403 L_120 ) ;
return V_389 ;
}
static void T_12 F_323 ( void )
{
F_314 () ;
F_320 () ;
}
