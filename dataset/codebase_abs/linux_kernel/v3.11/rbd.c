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
( void ) F_12 ( & V_11 -> V_6 ) ;
F_13 ( V_8 , V_11 -> V_16 . V_17 ) ;
return 0 ;
}
static void F_14 ( struct V_24 * V_25 , T_2 V_9 )
{
struct V_10 * V_11 = V_25 -> V_13 ;
unsigned long V_26 ;
F_9 ( & V_11 -> V_19 ) ;
V_26 = V_11 -> V_22 -- ;
F_11 ( & V_11 -> V_19 ) ;
F_15 ( V_26 > 0 ) ;
F_16 ( & V_11 -> V_6 ) ;
}
static struct V_27 * F_17 ( struct V_28 * V_29 )
{
struct V_27 * V_30 ;
int V_31 = - V_32 ;
F_18 ( L_1 , V_33 ) ;
V_30 = F_19 ( sizeof( struct V_27 ) , V_34 ) ;
if ( ! V_30 )
goto V_35;
F_20 ( & V_30 -> V_36 ) ;
F_21 ( & V_30 -> V_37 ) ;
V_30 -> V_38 = F_22 ( V_29 , V_30 , 0 , 0 ) ;
if ( F_23 ( V_30 -> V_38 ) )
goto V_39;
V_29 = NULL ;
V_31 = F_24 ( V_30 -> V_38 ) ;
if ( V_31 < 0 )
goto V_40;
F_25 ( & V_41 ) ;
F_26 ( & V_30 -> V_37 , & V_42 ) ;
F_27 ( & V_41 ) ;
F_18 ( L_2 , V_33 , V_30 ) ;
return V_30 ;
V_40:
F_28 ( V_30 -> V_38 ) ;
V_39:
F_29 ( V_30 ) ;
V_35:
if ( V_29 )
F_30 ( V_29 ) ;
F_18 ( L_3 , V_33 , V_31 ) ;
return F_31 ( V_31 ) ;
}
static struct V_27 * F_32 ( struct V_27 * V_30 )
{
F_33 ( & V_30 -> V_36 ) ;
return V_30 ;
}
static struct V_27 * F_34 ( struct V_28 * V_29 )
{
struct V_27 * V_43 ;
bool V_44 = false ;
if ( V_29 -> V_21 & V_45 )
return NULL ;
F_25 ( & V_41 ) ;
F_35 (client_node, &rbd_client_list, node) {
if ( ! F_36 ( V_29 , V_43 -> V_38 ) ) {
F_32 ( V_43 ) ;
V_44 = true ;
break;
}
}
F_27 ( & V_41 ) ;
return V_44 ? V_43 : NULL ;
}
static int F_37 ( char * V_46 , void * V_47 )
{
struct V_48 * V_49 = V_47 ;
T_3 V_50 [ V_51 ] ;
int V_52 , V_53 , V_31 ;
V_52 = F_38 ( V_46 , V_54 , V_50 ) ;
if ( V_52 < 0 )
return - V_4 ;
if ( V_52 < V_55 ) {
V_31 = F_39 ( & V_50 [ 0 ] , & V_53 ) ;
if ( V_31 < 0 ) {
F_40 ( L_4
L_5 , V_46 ) ;
return V_31 ;
}
F_18 ( L_6 , V_52 , V_53 ) ;
} else if ( V_52 > V_55 && V_52 < V_56 ) {
F_18 ( L_7 , V_52 ,
V_50 [ 0 ] . V_57 ) ;
} else if ( V_52 > V_56 && V_52 < V_58 ) {
F_18 ( L_8 , V_52 ) ;
} else {
F_18 ( L_9 , V_52 ) ;
}
switch ( V_52 ) {
case V_59 :
V_49 -> V_17 = true ;
break;
case V_60 :
V_49 -> V_17 = false ;
break;
default:
F_15 ( false ) ;
break;
}
return 0 ;
}
static struct V_27 * F_41 ( struct V_28 * V_29 )
{
struct V_27 * V_30 ;
F_42 ( & V_61 , V_62 ) ;
V_30 = F_34 ( V_29 ) ;
if ( V_30 )
F_30 ( V_29 ) ;
else
V_30 = F_17 ( V_29 ) ;
F_43 ( & V_61 ) ;
return V_30 ;
}
static void F_44 ( struct V_36 * V_36 )
{
struct V_27 * V_30 = F_45 ( V_36 , struct V_27 , V_36 ) ;
F_18 ( L_2 , V_33 , V_30 ) ;
F_25 ( & V_41 ) ;
F_46 ( & V_30 -> V_37 ) ;
F_27 ( & V_41 ) ;
F_28 ( V_30 -> V_38 ) ;
F_29 ( V_30 ) ;
}
static void F_47 ( struct V_27 * V_30 )
{
if ( V_30 )
F_48 ( & V_30 -> V_36 , F_44 ) ;
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
int V_31 = - V_32 ;
T_4 V_85 ;
if ( V_80 ) {
T_5 V_86 ;
V_86 = F_54 ( V_65 -> V_81 ,
sizeof ( V_65 -> V_81 ) ) ;
V_81 = F_19 ( V_86 + 1 , V_34 ) ;
if ( ! V_81 )
return - V_32 ;
memcpy ( V_81 , V_65 -> V_81 , V_86 ) ;
V_81 [ V_86 ] = '\0' ;
}
V_67 = F_51 ( V_65 -> V_67 ) ;
V_82 = F_55 ( V_67 , V_34 ) ;
if ( ! V_82 )
goto V_87;
V_82 -> V_88 = F_52 ( V_65 -> V_89 ) ;
if ( V_67 ) {
struct V_90 * V_91 ;
V_76 V_77 = F_52 ( V_65 -> V_77 ) ;
if ( V_77 > ( V_76 ) V_73 )
goto V_92;
V_83 = F_19 ( V_77 , V_34 ) ;
if ( ! V_83 )
goto V_87;
V_66 = V_67 * sizeof ( * V_79 -> V_84 ) ;
V_84 = F_19 ( V_66 , V_34 ) ;
if ( ! V_84 )
goto V_87;
memcpy ( V_83 , & V_65 -> V_91 [ V_67 ] , V_77 ) ;
V_91 = V_65 -> V_91 ;
for ( V_85 = 0 ; V_85 < V_67 ; V_85 ++ ) {
V_82 -> V_91 [ V_85 ] = F_52 ( V_91 [ V_85 ] . V_93 ) ;
V_84 [ V_85 ] = F_52 ( V_91 [ V_85 ] . V_94 ) ;
}
}
if ( V_80 ) {
V_79 -> V_81 = V_81 ;
V_79 -> V_95 = V_65 -> V_70 . V_71 ;
V_79 -> V_96 = V_65 -> V_70 . V_96 ;
V_79 -> V_97 = V_65 -> V_70 . V_97 ;
V_79 -> V_98 = 0 ;
V_79 -> V_99 = 0 ;
V_79 -> V_100 = 0 ;
} else {
F_56 ( V_79 -> V_82 ) ;
F_29 ( V_79 -> V_83 ) ;
F_29 ( V_79 -> V_84 ) ;
}
V_79 -> V_94 = F_52 ( V_65 -> V_94 ) ;
V_79 -> V_82 = V_82 ;
V_79 -> V_83 = V_83 ;
V_79 -> V_84 = V_84 ;
if ( V_11 -> V_101 -> V_102 == V_103 || V_80 )
if ( V_11 -> V_16 . V_66 != V_79 -> V_94 )
V_11 -> V_16 . V_66 = V_79 -> V_94 ;
return 0 ;
V_92:
V_31 = - V_104 ;
V_87:
F_29 ( V_84 ) ;
F_29 ( V_83 ) ;
F_56 ( V_82 ) ;
F_29 ( V_81 ) ;
return V_31 ;
}
static const char * F_57 ( struct V_10 * V_11 , T_4 V_105 )
{
const char * V_106 ;
F_15 ( V_105 < V_11 -> V_79 . V_82 -> V_107 ) ;
V_106 = V_11 -> V_79 . V_83 ;
while ( V_105 -- )
V_106 += strlen ( V_106 ) + 1 ;
return F_58 ( V_106 , V_34 ) ;
}
static int F_59 ( const void * V_108 , const void * V_109 )
{
V_76 V_110 = * ( V_76 * ) V_108 ;
V_76 V_111 = * ( V_76 * ) V_109 ;
if ( V_110 < V_111 )
return 1 ;
return V_110 == V_111 ? 0 : - 1 ;
}
static T_4 F_60 ( struct V_10 * V_11 , V_76 V_102 )
{
struct V_74 * V_82 = V_11 -> V_79 . V_82 ;
V_76 * V_44 ;
V_44 = bsearch ( & V_102 , & V_82 -> V_91 , V_82 -> V_107 ,
sizeof ( V_102 ) , F_59 ) ;
return V_44 ? ( T_4 ) ( V_44 - & V_82 -> V_91 [ 0 ] ) : V_112 ;
}
static const char * F_61 ( struct V_10 * V_11 ,
V_76 V_102 )
{
T_4 V_105 ;
V_105 = F_60 ( V_11 , V_102 ) ;
if ( V_105 == V_112 )
return NULL ;
return F_57 ( V_11 , V_105 ) ;
}
static const char * F_62 ( struct V_10 * V_11 , V_76 V_102 )
{
if ( V_102 == V_103 )
return V_113 ;
F_15 ( F_49 ( V_11 -> V_63 ) ) ;
if ( V_11 -> V_63 == 1 )
return F_61 ( V_11 , V_102 ) ;
return F_63 ( V_11 , V_102 ) ;
}
static int F_64 ( struct V_10 * V_11 , V_76 V_102 ,
V_76 * V_114 )
{
F_15 ( F_49 ( V_11 -> V_63 ) ) ;
if ( V_102 == V_103 ) {
* V_114 = V_11 -> V_79 . V_94 ;
} else if ( V_11 -> V_63 == 1 ) {
T_4 V_105 ;
V_105 = F_60 ( V_11 , V_102 ) ;
if ( V_105 == V_112 )
return - V_23 ;
* V_114 = V_11 -> V_79 . V_84 [ V_105 ] ;
} else {
V_76 V_66 = 0 ;
int V_31 ;
V_31 = F_65 ( V_11 , V_102 , NULL , & V_66 ) ;
if ( V_31 )
return V_31 ;
* V_114 = V_66 ;
}
return 0 ;
}
static int F_66 ( struct V_10 * V_11 , V_76 V_102 ,
V_76 * V_115 )
{
F_15 ( F_49 ( V_11 -> V_63 ) ) ;
if ( V_102 == V_103 ) {
* V_115 = V_11 -> V_79 . V_100 ;
} else if ( V_11 -> V_63 == 1 ) {
* V_115 = 0 ;
} else {
V_76 V_100 = 0 ;
int V_31 ;
V_31 = F_67 ( V_11 , V_102 , & V_100 ) ;
if ( V_31 )
return V_31 ;
* V_115 = V_100 ;
}
return 0 ;
}
static int F_68 ( struct V_10 * V_11 )
{
V_76 V_102 = V_11 -> V_101 -> V_102 ;
V_76 V_66 = 0 ;
V_76 V_100 = 0 ;
int V_31 ;
V_31 = F_64 ( V_11 , V_102 , & V_66 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_66 ( V_11 , V_102 , & V_100 ) ;
if ( V_31 )
return V_31 ;
V_11 -> V_16 . V_66 = V_66 ;
V_11 -> V_16 . V_100 = V_100 ;
return 0 ;
}
static void F_69 ( struct V_10 * V_11 )
{
V_11 -> V_16 . V_66 = 0 ;
V_11 -> V_16 . V_100 = 0 ;
}
static const char * F_70 ( struct V_10 * V_11 , V_76 V_116 )
{
char * V_117 ;
V_76 V_118 ;
int V_31 ;
char * V_119 ;
V_117 = F_71 ( V_120 , V_121 ) ;
if ( ! V_117 )
return NULL ;
V_118 = V_116 >> V_11 -> V_79 . V_95 ;
V_119 = L_10 ;
if ( V_11 -> V_63 == 2 )
V_119 = L_11 ;
V_31 = snprintf ( V_117 , V_122 + 1 , V_119 ,
V_11 -> V_79 . V_81 , V_118 ) ;
if ( V_31 < 0 || V_31 > V_122 ) {
F_40 ( L_12 ,
V_118 , V_31 ) ;
F_29 ( V_117 ) ;
V_117 = NULL ;
}
return V_117 ;
}
static void F_72 ( const char * V_117 )
{
F_73 ( V_120 , ( void * ) V_117 ) ;
}
static V_76 F_74 ( struct V_10 * V_11 , V_76 V_116 )
{
V_76 V_123 = ( V_76 ) 1 << V_11 -> V_79 . V_95 ;
return V_116 & ( V_123 - 1 ) ;
}
static V_76 F_75 ( struct V_10 * V_11 ,
V_76 V_116 , V_76 V_124 )
{
V_76 V_123 = ( V_76 ) 1 << V_11 -> V_79 . V_95 ;
V_116 &= V_123 - 1 ;
F_15 ( V_124 <= V_125 - V_116 ) ;
if ( V_116 + V_124 > V_123 )
V_124 = V_123 - V_116 ;
return V_124 ;
}
static V_76 F_76 ( struct V_78 * V_79 )
{
return 1 << V_79 -> V_95 ;
}
static void F_77 ( struct V_126 * V_127 )
{
struct V_126 * V_128 ;
while ( V_127 ) {
V_128 = V_127 ;
V_127 = V_127 -> V_129 ;
F_78 ( V_128 ) ;
}
}
static void F_79 ( struct V_126 * V_127 , int V_130 )
{
struct V_131 * V_132 ;
unsigned long V_21 ;
void * V_133 ;
int V_85 ;
int V_134 = 0 ;
while ( V_127 ) {
F_80 (bv, chain, i) {
if ( V_134 + V_132 -> V_135 > V_130 ) {
int V_136 = F_81 ( V_130 - V_134 , 0 ) ;
V_133 = F_82 ( V_132 , & V_21 ) ;
memset ( V_133 + V_136 , 0 ,
V_132 -> V_135 - V_136 ) ;
F_83 ( V_132 -> V_137 ) ;
F_84 ( V_133 , & V_21 ) ;
}
V_134 += V_132 -> V_135 ;
}
V_127 = V_127 -> V_129 ;
}
}
static void F_85 ( struct V_138 * * V_139 , V_76 V_116 , V_76 V_140 )
{
struct V_138 * * V_138 = & V_139 [ V_116 >> V_141 ] ;
F_15 ( V_140 > V_116 ) ;
F_15 ( V_140 - V_116 <= ( V_76 ) V_73 ) ;
while ( V_116 < V_140 ) {
T_5 V_142 ;
T_5 V_124 ;
unsigned long V_21 ;
void * V_143 ;
V_142 = V_116 & ~ V_144 ;
V_124 = F_86 ( T_5 , V_145 - V_142 , V_140 - V_116 ) ;
F_87 ( V_21 ) ;
V_143 = F_88 ( * V_138 ) ;
memset ( V_143 + V_142 , 0 , V_124 ) ;
F_83 ( * V_138 ) ;
F_89 ( V_143 ) ;
F_90 ( V_21 ) ;
V_116 += V_124 ;
V_138 ++ ;
}
}
static struct V_126 * F_91 ( struct V_126 * V_146 ,
unsigned int V_116 ,
unsigned int V_86 ,
T_6 V_147 )
{
struct V_131 * V_132 ;
unsigned int V_148 ;
unsigned short V_149 ;
unsigned int V_150 ;
unsigned short V_151 ;
unsigned short V_152 ;
struct V_126 * V_126 ;
if ( ! V_116 && V_86 == V_146 -> V_153 )
return F_92 ( V_146 , V_147 ) ;
if ( F_93 ( ! V_86 ) )
return NULL ;
if ( F_93 ( V_86 > V_146 -> V_153 ) )
return NULL ;
if ( F_93 ( V_116 > V_146 -> V_153 - V_86 ) )
return NULL ;
V_148 = V_116 ;
F_80 (bv, bio_src, idx) {
if ( V_148 < V_132 -> V_135 )
break;
V_148 -= V_132 -> V_135 ;
}
V_150 = V_148 ;
V_148 += V_86 ;
F_94 (bv, bio_src, end_idx, idx) {
if ( V_148 <= V_132 -> V_135 )
break;
V_148 -= V_132 -> V_135 ;
}
V_152 = V_151 - V_149 + 1 ;
V_126 = F_95 ( V_147 , ( unsigned int ) V_152 ) ;
if ( ! V_126 )
return NULL ;
V_126 -> V_154 = V_146 -> V_154 ;
V_126 -> V_155 = V_146 -> V_155 + ( V_116 >> V_72 ) ;
V_126 -> V_156 = V_146 -> V_156 ;
V_126 -> V_157 |= 1 << V_158 ;
memcpy ( & V_126 -> V_159 [ 0 ] , & V_146 -> V_159 [ V_149 ] ,
V_152 * sizeof ( struct V_131 ) ) ;
V_126 -> V_159 [ 0 ] . V_160 += V_150 ;
if ( V_152 > 1 ) {
V_126 -> V_159 [ 0 ] . V_135 -= V_150 ;
V_126 -> V_159 [ V_152 - 1 ] . V_135 = V_148 ;
} else {
V_126 -> V_159 [ 0 ] . V_135 = V_86 ;
}
V_126 -> V_161 = V_152 ;
V_126 -> V_153 = V_86 ;
V_126 -> V_162 = 0 ;
return V_126 ;
}
static struct V_126 * F_96 ( struct V_126 * * V_146 ,
unsigned int * V_116 ,
unsigned int V_86 ,
T_6 V_147 )
{
struct V_126 * V_163 = * V_146 ;
unsigned int V_164 = * V_116 ;
struct V_126 * V_127 = NULL ;
struct V_126 * * V_140 ;
if ( ! V_163 || V_164 >= V_163 -> V_153 || ! V_86 )
return NULL ;
V_140 = & V_127 ;
while ( V_86 ) {
unsigned int V_153 ;
struct V_126 * V_126 ;
if ( ! V_163 ) {
F_97 ( NULL , L_13 , V_86 ) ;
goto V_87;
}
V_153 = F_86 (unsigned int, bi->bi_size - off, len) ;
V_126 = F_91 ( V_163 , V_164 , V_153 , V_147 ) ;
if ( ! V_126 )
goto V_87;
* V_140 = V_126 ;
V_140 = & V_126 -> V_129 ;
V_164 += V_153 ;
if ( V_164 == V_163 -> V_153 ) {
V_163 = V_163 -> V_129 ;
V_164 = 0 ;
}
V_86 -= V_153 ;
}
* V_146 = V_163 ;
* V_116 = V_164 ;
return V_127 ;
V_87:
F_77 ( V_127 ) ;
return NULL ;
}
static void F_98 ( struct V_165 * V_166 )
{
if ( F_99 ( V_167 , & V_166 -> V_21 ) ) {
struct V_10 * V_11 ;
V_11 = V_166 -> V_168 -> V_11 ;
F_97 ( V_11 , L_14 ,
V_166 ) ;
}
}
static bool F_100 ( struct V_165 * V_166 )
{
F_101 () ;
return F_10 ( V_167 , & V_166 -> V_21 ) != 0 ;
}
static void F_102 ( struct V_165 * V_166 )
{
if ( F_99 ( V_169 , & V_166 -> V_21 ) ) {
struct V_10 * V_11 = NULL ;
if ( F_100 ( V_166 ) )
V_11 = V_166 -> V_168 -> V_11 ;
F_97 ( V_11 , L_15 ,
V_166 ) ;
}
}
static bool F_103 ( struct V_165 * V_166 )
{
F_101 () ;
return F_10 ( V_169 , & V_166 -> V_21 ) != 0 ;
}
static void F_104 ( struct V_165 * V_166 ,
bool V_170 )
{
if ( V_170 )
F_105 ( V_171 , & V_166 -> V_21 ) ;
F_105 ( V_172 , & V_166 -> V_21 ) ;
F_101 () ;
}
static bool F_106 ( struct V_165 * V_166 )
{
F_101 () ;
return F_10 ( V_172 , & V_166 -> V_21 ) != 0 ;
}
static bool F_107 ( struct V_165 * V_166 )
{
F_101 () ;
return F_10 ( V_171 , & V_166 -> V_21 ) != 0 ;
}
static void F_108 ( struct V_165 * V_166 )
{
F_18 ( L_16 , V_33 , V_166 ,
F_109 ( & V_166 -> V_36 . V_173 ) ) ;
F_33 ( & V_166 -> V_36 ) ;
}
static void F_110 ( struct V_165 * V_166 )
{
F_15 ( V_166 != NULL ) ;
F_18 ( L_16 , V_33 , V_166 ,
F_109 ( & V_166 -> V_36 . V_173 ) ) ;
F_48 ( & V_166 -> V_36 , V_174 ) ;
}
static void F_111 ( struct V_175 * V_168 )
{
F_15 ( V_168 != NULL ) ;
F_18 ( L_17 , V_33 , V_168 ,
F_109 ( & V_168 -> V_36 . V_173 ) ) ;
if ( F_112 ( V_168 ) )
F_48 ( & V_168 -> V_36 , V_176 ) ;
else
F_48 ( & V_168 -> V_36 , V_177 ) ;
}
static inline void F_113 ( struct V_175 * V_168 ,
struct V_165 * V_166 )
{
F_15 ( V_166 -> V_168 == NULL ) ;
V_166 -> V_168 = V_168 ;
V_166 -> V_105 = V_168 -> V_178 ;
F_15 ( ! F_100 ( V_166 ) ) ;
F_98 ( V_166 ) ;
F_15 ( V_166 -> V_105 != V_179 ) ;
V_168 -> V_178 ++ ;
F_26 ( & V_166 -> V_180 , & V_168 -> V_181 ) ;
F_18 ( L_18 , V_33 , V_168 , V_166 ,
V_166 -> V_105 ) ;
}
static inline void F_114 ( struct V_175 * V_168 ,
struct V_165 * V_166 )
{
F_15 ( V_166 -> V_105 != V_179 ) ;
F_18 ( L_18 , V_33 , V_168 , V_166 ,
V_166 -> V_105 ) ;
F_46 ( & V_166 -> V_180 ) ;
F_15 ( V_168 -> V_178 > 0 ) ;
V_168 -> V_178 -- ;
F_15 ( V_166 -> V_105 == V_168 -> V_178 ) ;
V_166 -> V_105 = V_179 ;
F_15 ( F_100 ( V_166 ) ) ;
F_15 ( V_166 -> V_168 == V_168 ) ;
V_166 -> V_168 = NULL ;
V_166 -> V_182 = NULL ;
F_110 ( V_166 ) ;
}
static bool F_115 ( enum V_183 type )
{
switch ( type ) {
case V_184 :
case V_185 :
case V_186 :
return true ;
default:
return false ;
}
}
static int F_116 ( struct V_187 * V_188 ,
struct V_165 * V_166 )
{
F_18 ( L_19 , V_33 , V_188 , V_166 ) ;
return F_117 ( V_188 , V_166 -> V_189 , false ) ;
}
static void F_118 ( struct V_175 * V_168 )
{
F_18 ( L_20 , V_33 , V_168 ) ;
if ( ! V_168 -> V_190 ) {
struct V_165 * V_166 ;
V_76 V_191 = 0 ;
F_119 (img_request, obj_request)
V_191 += V_166 -> V_191 ;
V_168 -> V_191 = V_191 ;
}
if ( V_168 -> V_182 )
V_168 -> V_182 ( V_168 ) ;
else
F_111 ( V_168 ) ;
}
static int F_120 ( struct V_165 * V_166 )
{
F_18 ( L_21 , V_33 , V_166 ) ;
return F_121 ( & V_166 -> V_192 ) ;
}
static void F_122 ( struct V_175 * V_168 )
{
F_105 ( V_193 , & V_168 -> V_21 ) ;
F_101 () ;
}
static bool F_123 ( struct V_175 * V_168 )
{
F_101 () ;
return F_10 ( V_193 , & V_168 -> V_21 ) != 0 ;
}
static void F_124 ( struct V_175 * V_168 )
{
F_105 ( V_194 , & V_168 -> V_21 ) ;
F_101 () ;
}
static void F_125 ( struct V_175 * V_168 )
{
F_126 ( V_194 , & V_168 -> V_21 ) ;
F_101 () ;
}
static bool F_112 ( struct V_175 * V_168 )
{
F_101 () ;
return F_10 ( V_194 , & V_168 -> V_21 ) != 0 ;
}
static void F_127 ( struct V_175 * V_168 )
{
F_105 ( V_195 , & V_168 -> V_21 ) ;
F_101 () ;
}
static void F_128 ( struct V_175 * V_168 )
{
F_126 ( V_195 , & V_168 -> V_21 ) ;
F_101 () ;
}
static bool F_129 ( struct V_175 * V_168 )
{
F_101 () ;
return F_10 ( V_195 , & V_168 -> V_21 ) != 0 ;
}
static void
F_130 ( struct V_165 * V_166 )
{
V_76 V_191 = V_166 -> V_191 ;
V_76 V_124 = V_166 -> V_124 ;
F_18 ( L_22 , V_33 ,
V_166 , V_166 -> V_168 , V_166 -> V_190 ,
V_191 , V_124 ) ;
F_15 ( V_166 -> type != V_184 ) ;
if ( V_166 -> V_190 == - V_23 ) {
if ( V_166 -> type == V_185 )
F_79 ( V_166 -> V_196 , 0 ) ;
else
F_85 ( V_166 -> V_139 , 0 , V_124 ) ;
V_166 -> V_190 = 0 ;
V_166 -> V_191 = V_124 ;
} else if ( V_191 < V_124 && ! V_166 -> V_190 ) {
if ( V_166 -> type == V_185 )
F_79 ( V_166 -> V_196 , V_191 ) ;
else
F_85 ( V_166 -> V_139 , V_191 , V_124 ) ;
V_166 -> V_191 = V_124 ;
}
F_102 ( V_166 ) ;
}
static void F_131 ( struct V_165 * V_166 )
{
F_18 ( L_23 , V_33 , V_166 ,
V_166 -> V_182 ) ;
if ( V_166 -> V_182 )
V_166 -> V_182 ( V_166 ) ;
else
F_132 ( & V_166 -> V_192 ) ;
}
static void F_133 ( struct V_165 * V_166 )
{
F_18 ( L_21 , V_33 , V_166 ) ;
F_102 ( V_166 ) ;
}
static void F_134 ( struct V_165 * V_166 )
{
struct V_175 * V_168 = NULL ;
struct V_10 * V_11 = NULL ;
bool V_197 = false ;
if ( F_100 ( V_166 ) ) {
V_168 = V_166 -> V_168 ;
V_197 = V_168 && F_129 ( V_168 ) ;
V_11 = V_168 -> V_11 ;
}
F_18 ( L_22 , V_33 ,
V_166 , V_168 , V_166 -> V_190 ,
V_166 -> V_191 , V_166 -> V_124 ) ;
if ( V_197 && V_166 -> V_190 == - V_23 &&
V_166 -> V_198 < V_11 -> V_199 )
F_135 ( V_166 ) ;
else if ( V_168 )
F_130 ( V_166 ) ;
else
F_102 ( V_166 ) ;
}
static void F_136 ( struct V_165 * V_166 )
{
F_18 ( L_24 , V_33 , V_166 ,
V_166 -> V_190 , V_166 -> V_124 ) ;
V_166 -> V_191 = V_166 -> V_124 ;
F_102 ( V_166 ) ;
}
static void F_137 ( struct V_165 * V_166 )
{
F_18 ( L_21 , V_33 , V_166 ) ;
F_102 ( V_166 ) ;
}
static void F_138 ( struct V_200 * V_189 ,
struct V_201 * V_202 )
{
struct V_165 * V_166 = V_189 -> V_203 ;
T_7 V_204 ;
F_18 ( L_25 , V_33 , V_189 , V_202 ) ;
F_15 ( V_189 == V_166 -> V_189 ) ;
if ( F_100 ( V_166 ) ) {
F_15 ( V_166 -> V_168 ) ;
F_15 ( V_166 -> V_105 != V_179 ) ;
} else {
F_15 ( V_166 -> V_105 == V_179 ) ;
}
if ( V_189 -> V_205 < 0 )
V_166 -> V_190 = V_189 -> V_205 ;
F_139 ( V_189 -> V_206 > 2 ) ;
V_166 -> V_191 = V_189 -> V_207 [ 0 ] ;
F_15 ( V_166 -> V_191 < ( V_76 ) V_208 ) ;
V_204 = V_189 -> V_209 [ 0 ] . V_210 ;
switch ( V_204 ) {
case V_211 :
F_134 ( V_166 ) ;
break;
case V_212 :
F_136 ( V_166 ) ;
break;
case V_213 :
F_137 ( V_166 ) ;
break;
case V_214 :
case V_215 :
case V_216 :
F_133 ( V_166 ) ;
break;
default:
F_97 ( NULL , L_26 ,
V_166 -> V_217 , ( unsigned short ) V_204 ) ;
break;
}
if ( F_103 ( V_166 ) )
F_131 ( V_166 ) ;
}
static void F_140 ( struct V_165 * V_166 )
{
struct V_175 * V_168 = V_166 -> V_168 ;
struct V_200 * V_189 = V_166 -> V_189 ;
V_76 V_102 ;
F_15 ( V_189 != NULL ) ;
V_102 = V_168 ? V_168 -> V_102 : V_103 ;
F_141 ( V_189 , V_166 -> V_116 ,
NULL , V_102 , NULL ) ;
}
static void F_142 ( struct V_165 * V_166 )
{
struct V_175 * V_168 = V_166 -> V_168 ;
struct V_200 * V_189 = V_166 -> V_189 ;
struct V_74 * V_82 ;
struct V_218 V_219 = V_220 ;
F_15 ( V_189 != NULL ) ;
V_82 = V_168 ? V_168 -> V_82 : NULL ;
F_141 ( V_189 , V_166 -> V_116 ,
V_82 , V_103 , & V_219 ) ;
}
static struct V_200 * F_143 (
struct V_10 * V_11 ,
bool V_221 ,
struct V_165 * V_166 )
{
struct V_74 * V_82 = NULL ;
struct V_187 * V_188 ;
struct V_200 * V_189 ;
if ( F_100 ( V_166 ) ) {
struct V_175 * V_168 = V_166 -> V_168 ;
F_15 ( V_221 ==
F_123 ( V_168 ) ) ;
if ( V_221 )
V_82 = V_168 -> V_82 ;
}
V_188 = & V_11 -> V_27 -> V_38 -> V_188 ;
V_189 = F_144 ( V_188 , V_82 , 1 , false , V_222 ) ;
if ( ! V_189 )
return NULL ;
if ( V_221 )
V_189 -> V_223 = V_224 | V_225 ;
else
V_189 -> V_223 = V_226 ;
V_189 -> V_227 = F_138 ;
V_189 -> V_203 = V_166 ;
V_189 -> V_228 = strlen ( V_166 -> V_217 ) ;
F_15 ( V_189 -> V_228 < sizeof ( V_189 -> V_229 ) ) ;
memcpy ( V_189 -> V_229 , V_166 -> V_217 , V_189 -> V_228 ) ;
V_189 -> V_230 = V_11 -> V_231 ;
return V_189 ;
}
static struct V_200 *
F_145 ( struct V_165 * V_166 )
{
struct V_175 * V_168 ;
struct V_74 * V_82 ;
struct V_10 * V_11 ;
struct V_187 * V_188 ;
struct V_200 * V_189 ;
F_15 ( F_100 ( V_166 ) ) ;
V_168 = V_166 -> V_168 ;
F_15 ( V_168 ) ;
F_15 ( F_123 ( V_168 ) ) ;
V_82 = V_168 -> V_82 ;
V_11 = V_168 -> V_11 ;
V_188 = & V_11 -> V_27 -> V_38 -> V_188 ;
V_189 = F_144 ( V_188 , V_82 , 2 , false , V_222 ) ;
if ( ! V_189 )
return NULL ;
V_189 -> V_223 = V_224 | V_225 ;
V_189 -> V_227 = F_138 ;
V_189 -> V_203 = V_166 ;
V_189 -> V_228 = strlen ( V_166 -> V_217 ) ;
F_15 ( V_189 -> V_228 < sizeof ( V_189 -> V_229 ) ) ;
memcpy ( V_189 -> V_229 , V_166 -> V_217 , V_189 -> V_228 ) ;
V_189 -> V_230 = V_11 -> V_231 ;
return V_189 ;
}
static void F_146 ( struct V_200 * V_189 )
{
F_147 ( V_189 ) ;
}
static struct V_165 * F_148 ( const char * V_217 ,
V_76 V_116 , V_76 V_124 ,
enum V_183 type )
{
struct V_165 * V_166 ;
T_5 V_66 ;
char * V_117 ;
F_15 ( F_115 ( type ) ) ;
V_66 = strlen ( V_217 ) + 1 ;
V_117 = F_19 ( V_66 , V_34 ) ;
if ( ! V_117 )
return NULL ;
V_166 = F_149 ( V_232 , V_34 ) ;
if ( ! V_166 ) {
F_29 ( V_117 ) ;
return NULL ;
}
V_166 -> V_217 = memcpy ( V_117 , V_217 , V_66 ) ;
V_166 -> V_116 = V_116 ;
V_166 -> V_124 = V_124 ;
V_166 -> V_21 = 0 ;
V_166 -> V_105 = V_179 ;
V_166 -> type = type ;
F_21 ( & V_166 -> V_180 ) ;
F_150 ( & V_166 -> V_192 ) ;
F_20 ( & V_166 -> V_36 ) ;
F_18 ( L_27 , V_33 , V_217 ,
V_116 , V_124 , ( int ) type , V_166 ) ;
return V_166 ;
}
static void V_174 ( struct V_36 * V_36 )
{
struct V_165 * V_166 ;
V_166 = F_45 ( V_36 , struct V_165 , V_36 ) ;
F_18 ( L_21 , V_33 , V_166 ) ;
F_15 ( V_166 -> V_168 == NULL ) ;
F_15 ( V_166 -> V_105 == V_179 ) ;
if ( V_166 -> V_189 )
F_146 ( V_166 -> V_189 ) ;
F_15 ( F_115 ( V_166 -> type ) ) ;
switch ( V_166 -> type ) {
case V_184 :
break;
case V_185 :
if ( V_166 -> V_196 )
F_77 ( V_166 -> V_196 ) ;
break;
case V_186 :
if ( V_166 -> V_139 )
F_151 ( V_166 -> V_139 ,
V_166 -> V_233 ) ;
break;
}
F_29 ( V_166 -> V_217 ) ;
V_166 -> V_217 = NULL ;
F_73 ( V_232 , V_166 ) ;
}
static void F_152 ( struct V_10 * V_11 )
{
F_153 ( V_11 ) ;
F_154 ( V_11 -> V_234 ) ;
V_11 -> V_234 = NULL ;
V_11 -> V_199 = 0 ;
}
static void F_155 ( struct V_10 * V_11 )
{
int V_2 ;
if ( ! V_11 -> V_234 )
return;
V_2 = F_4 ( & V_11 -> V_235 ) ;
if ( V_2 > 0 )
return;
if ( ! V_2 )
F_152 ( V_11 ) ;
else
F_97 ( V_11 , L_28 ) ;
}
static bool F_156 ( struct V_10 * V_11 )
{
int V_2 ;
if ( ! V_11 -> V_234 )
return false ;
V_2 = F_1 ( & V_11 -> V_235 ) ;
if ( V_2 > 0 && V_11 -> V_199 )
return true ;
if ( V_2 < 0 )
F_97 ( V_11 , L_29 ) ;
return false ;
}
static struct V_175 * F_157 (
struct V_10 * V_11 ,
V_76 V_116 , V_76 V_124 ,
bool V_221 )
{
struct V_175 * V_168 ;
V_168 = F_71 ( V_236 , V_222 ) ;
if ( ! V_168 )
return NULL ;
if ( V_221 ) {
F_158 ( & V_11 -> V_237 ) ;
F_159 ( V_11 -> V_79 . V_82 ) ;
F_160 ( & V_11 -> V_237 ) ;
}
V_168 -> V_238 = NULL ;
V_168 -> V_11 = V_11 ;
V_168 -> V_116 = V_116 ;
V_168 -> V_124 = V_124 ;
V_168 -> V_21 = 0 ;
if ( V_221 ) {
F_122 ( V_168 ) ;
V_168 -> V_82 = V_11 -> V_79 . V_82 ;
} else {
V_168 -> V_102 = V_11 -> V_101 -> V_102 ;
}
if ( F_156 ( V_11 ) )
F_127 ( V_168 ) ;
F_161 ( & V_168 -> V_239 ) ;
V_168 -> V_240 = 0 ;
V_168 -> V_182 = NULL ;
V_168 -> V_190 = 0 ;
V_168 -> V_178 = 0 ;
F_21 ( & V_168 -> V_181 ) ;
F_20 ( & V_168 -> V_36 ) ;
F_18 ( L_30 , V_33 , V_11 ,
V_221 ? L_31 : L_32 , V_116 , V_124 ,
V_168 ) ;
return V_168 ;
}
static void V_177 ( struct V_36 * V_36 )
{
struct V_175 * V_168 ;
struct V_165 * V_166 ;
struct V_165 * V_241 ;
V_168 = F_45 ( V_36 , struct V_175 , V_36 ) ;
F_18 ( L_20 , V_33 , V_168 ) ;
F_162 (img_request, obj_request, next_obj_request)
F_114 ( V_168 , V_166 ) ;
F_15 ( V_168 -> V_178 == 0 ) ;
if ( F_129 ( V_168 ) ) {
F_128 ( V_168 ) ;
F_155 ( V_168 -> V_11 ) ;
}
if ( F_123 ( V_168 ) )
F_56 ( V_168 -> V_82 ) ;
F_73 ( V_236 , V_168 ) ;
}
static struct V_175 * F_163 (
struct V_165 * V_166 ,
V_76 V_198 , V_76 V_124 )
{
struct V_175 * V_242 ;
struct V_10 * V_11 ;
F_15 ( V_166 -> V_168 ) ;
V_11 = V_166 -> V_168 -> V_11 ;
V_242 = F_157 ( V_11 -> V_243 ,
V_198 , V_124 , false ) ;
if ( ! V_242 )
return NULL ;
F_124 ( V_242 ) ;
F_108 ( V_166 ) ;
V_242 -> V_166 = V_166 ;
return V_242 ;
}
static void V_176 ( struct V_36 * V_36 )
{
struct V_175 * V_242 ;
struct V_165 * V_244 ;
V_242 = F_45 ( V_36 , struct V_175 , V_36 ) ;
V_244 = V_242 -> V_166 ;
V_242 -> V_166 = NULL ;
F_110 ( V_244 ) ;
F_125 ( V_242 ) ;
V_177 ( V_36 ) ;
}
static bool F_164 ( struct V_165 * V_166 )
{
struct V_175 * V_168 ;
unsigned int V_191 ;
int V_190 ;
bool V_245 ;
F_15 ( F_100 ( V_166 ) ) ;
V_168 = V_166 -> V_168 ;
F_15 ( V_166 -> V_191 <= ( V_76 ) V_208 ) ;
V_191 = ( unsigned int ) V_166 -> V_191 ;
V_190 = V_166 -> V_190 ;
if ( V_190 ) {
struct V_10 * V_11 = V_168 -> V_11 ;
F_97 ( V_11 , L_33 ,
F_123 ( V_168 ) ? L_31 : L_32 ,
V_166 -> V_124 , V_166 -> V_198 ,
V_166 -> V_116 ) ;
F_97 ( V_11 , L_34 ,
V_190 , V_191 ) ;
if ( ! V_168 -> V_190 )
V_168 -> V_190 = V_190 ;
}
if ( V_166 -> type == V_186 ) {
V_166 -> V_139 = NULL ;
V_166 -> V_233 = 0 ;
}
if ( F_112 ( V_168 ) ) {
F_15 ( V_168 -> V_166 != NULL ) ;
V_245 = V_166 -> V_105 < V_168 -> V_178 - 1 ;
} else {
F_15 ( V_168 -> V_238 != NULL ) ;
V_245 = F_165 ( V_168 -> V_238 , V_190 , V_191 ) ;
}
return V_245 ;
}
static void F_166 ( struct V_165 * V_166 )
{
struct V_175 * V_168 ;
T_4 V_105 = V_166 -> V_105 ;
bool V_245 = true ;
F_15 ( F_100 ( V_166 ) ) ;
V_168 = V_166 -> V_168 ;
F_18 ( L_35 , V_33 , V_168 , V_166 ) ;
F_15 ( V_168 != NULL ) ;
F_15 ( V_168 -> V_178 > 0 ) ;
F_15 ( V_105 != V_179 ) ;
F_15 ( V_105 < V_168 -> V_178 ) ;
F_15 ( V_105 >= V_168 -> V_240 ) ;
F_9 ( & V_168 -> V_239 ) ;
if ( V_105 != V_168 -> V_240 )
goto V_246;
F_167 (img_request, obj_request) {
F_15 ( V_245 ) ;
F_15 ( V_105 < V_168 -> V_178 ) ;
if ( ! F_103 ( V_166 ) )
break;
V_245 = F_164 ( V_166 ) ;
V_105 ++ ;
}
F_15 ( V_245 ^ ( V_105 == V_168 -> V_178 ) ) ;
V_168 -> V_240 = V_105 ;
V_246:
F_11 ( & V_168 -> V_239 ) ;
if ( ! V_245 )
F_118 ( V_168 ) ;
}
static int F_168 ( struct V_175 * V_168 ,
enum V_183 type ,
void * V_247 )
{
struct V_10 * V_11 = V_168 -> V_11 ;
struct V_165 * V_166 = NULL ;
struct V_165 * V_241 ;
bool V_221 = F_123 ( V_168 ) ;
struct V_126 * V_196 = 0 ;
unsigned int V_248 = 0 ;
struct V_138 * * V_139 = 0 ;
V_76 V_198 ;
V_76 V_148 ;
T_7 V_204 ;
F_18 ( L_36 , V_33 , V_168 ,
( int ) type , V_247 ) ;
V_204 = V_221 ? V_212 : V_211 ;
V_198 = V_168 -> V_116 ;
V_148 = V_168 -> V_124 ;
F_15 ( V_148 > 0 ) ;
if ( type == V_185 ) {
V_196 = V_247 ;
F_15 ( V_198 == V_196 -> V_155 << V_72 ) ;
} else {
F_15 ( type == V_186 ) ;
V_139 = V_247 ;
}
while ( V_148 ) {
struct V_200 * V_189 ;
const char * V_217 ;
V_76 V_116 ;
V_76 V_124 ;
V_217 = F_70 ( V_11 , V_198 ) ;
if ( ! V_217 )
goto V_249;
V_116 = F_74 ( V_11 , V_198 ) ;
V_124 = F_75 ( V_11 , V_198 , V_148 ) ;
V_166 = F_148 ( V_217 ,
V_116 , V_124 , type ) ;
F_72 ( V_217 ) ;
if ( ! V_166 )
goto V_249;
if ( type == V_185 ) {
unsigned int V_250 ;
F_15 ( V_124 <= ( V_76 ) V_208 ) ;
V_250 = ( unsigned int ) V_124 ;
V_166 -> V_196 =
F_96 ( & V_196 ,
& V_248 ,
V_250 ,
V_222 ) ;
if ( ! V_166 -> V_196 )
goto V_251;
} else {
unsigned int V_233 ;
V_166 -> V_139 = V_139 ;
V_233 = ( T_4 ) F_169 ( V_116 , V_124 ) ;
V_166 -> V_233 = V_233 ;
if ( ( V_116 + V_124 ) & ~ V_144 )
V_233 -- ;
V_139 += V_233 ;
}
V_189 = F_143 ( V_11 , V_221 ,
V_166 ) ;
if ( ! V_189 )
goto V_251;
V_166 -> V_189 = V_189 ;
V_166 -> V_182 = F_166 ;
F_170 ( V_189 , 0 , V_204 , V_116 , V_124 ,
0 , 0 ) ;
if ( type == V_185 )
F_171 ( V_189 , 0 ,
V_166 -> V_196 , V_124 ) ;
else
F_172 ( V_189 , 0 ,
V_166 -> V_139 , V_124 ,
V_116 & ~ V_144 , false , false ) ;
F_113 ( V_168 , V_166 ) ;
if ( V_221 )
F_142 ( V_166 ) ;
else
F_140 ( V_166 ) ;
V_166 -> V_198 = V_198 ;
V_198 += V_124 ;
V_148 -= V_124 ;
}
return 0 ;
V_251:
F_110 ( V_166 ) ;
V_249:
F_162 (img_request, obj_request, next_obj_request)
F_110 ( V_166 ) ;
return - V_32 ;
}
static void
F_173 ( struct V_165 * V_166 )
{
struct V_175 * V_168 ;
struct V_10 * V_11 ;
struct V_138 * * V_139 ;
T_4 V_233 ;
F_15 ( V_166 -> type == V_185 ) ;
F_15 ( F_100 ( V_166 ) ) ;
V_168 = V_166 -> V_168 ;
F_15 ( V_168 ) ;
V_11 = V_168 -> V_11 ;
F_15 ( V_11 ) ;
V_139 = V_166 -> V_252 ;
F_15 ( V_139 != NULL ) ;
V_166 -> V_252 = NULL ;
V_233 = V_166 -> V_253 ;
F_15 ( V_233 ) ;
V_166 -> V_253 = 0 ;
F_151 ( V_139 , V_233 ) ;
if ( ! V_166 -> V_190 )
V_166 -> V_191 = V_166 -> V_124 ;
F_166 ( V_166 ) ;
}
static void
F_174 ( struct V_175 * V_168 )
{
struct V_165 * V_244 ;
struct V_200 * V_189 ;
struct V_187 * V_188 ;
struct V_10 * V_11 ;
struct V_138 * * V_139 ;
T_4 V_233 ;
int V_254 ;
V_76 V_255 ;
V_76 V_116 ;
V_76 V_124 ;
F_15 ( F_112 ( V_168 ) ) ;
V_139 = V_168 -> V_252 ;
F_15 ( V_139 != NULL ) ;
V_168 -> V_252 = NULL ;
V_233 = V_168 -> V_253 ;
F_15 ( V_233 ) ;
V_168 -> V_253 = 0 ;
V_244 = V_168 -> V_166 ;
F_15 ( V_244 != NULL ) ;
F_15 ( F_115 ( V_244 -> type ) ) ;
V_254 = V_168 -> V_190 ;
V_255 = V_168 -> V_124 ;
F_15 ( V_255 == V_168 -> V_191 ) ;
F_111 ( V_168 ) ;
F_15 ( V_244 -> V_168 ) ;
V_11 = V_244 -> V_168 -> V_11 ;
F_15 ( V_11 ) ;
if ( ! V_11 -> V_199 ) {
struct V_187 * V_188 ;
F_151 ( V_139 , V_233 ) ;
V_188 = & V_11 -> V_27 -> V_38 -> V_188 ;
V_254 = F_116 ( V_188 , V_244 ) ;
if ( ! V_254 )
return;
}
if ( V_254 )
goto V_87;
V_254 = - V_32 ;
V_189 = F_145 ( V_244 ) ;
if ( ! V_189 )
goto V_87;
F_146 ( V_244 -> V_189 ) ;
V_244 -> V_189 = V_189 ;
V_244 -> V_252 = V_139 ;
V_244 -> V_253 = V_233 ;
F_175 ( V_189 , 0 , V_214 , L_37 , L_38 ) ;
F_176 ( V_189 , 0 , V_139 , V_255 , 0 ,
false , false ) ;
V_116 = V_244 -> V_116 ;
V_124 = V_244 -> V_124 ;
F_170 ( V_189 , 1 , V_212 ,
V_116 , V_124 , 0 , 0 ) ;
if ( V_244 -> type == V_185 )
F_171 ( V_189 , 1 ,
V_244 -> V_196 , V_124 ) ;
else
F_172 ( V_189 , 1 ,
V_244 -> V_139 , V_124 ,
V_116 & ~ V_144 , false , false ) ;
F_142 ( V_244 ) ;
V_244 -> V_182 = F_173 ;
V_188 = & V_11 -> V_27 -> V_38 -> V_188 ;
V_254 = F_116 ( V_188 , V_244 ) ;
if ( ! V_254 )
return;
V_87:
V_244 -> V_190 = V_254 ;
V_244 -> V_191 = 0 ;
F_102 ( V_244 ) ;
F_131 ( V_244 ) ;
}
static int F_177 ( struct V_165 * V_166 )
{
struct V_175 * V_168 = NULL ;
struct V_175 * V_242 = NULL ;
struct V_10 * V_11 ;
V_76 V_198 ;
V_76 V_124 ;
struct V_138 * * V_139 = NULL ;
T_4 V_233 ;
int V_190 ;
F_15 ( F_100 ( V_166 ) ) ;
F_15 ( F_115 ( V_166 -> type ) ) ;
V_168 = V_166 -> V_168 ;
F_15 ( V_168 != NULL ) ;
V_11 = V_168 -> V_11 ;
F_15 ( V_11 -> V_243 != NULL ) ;
V_198 = V_166 -> V_198 - V_166 -> V_116 ;
V_124 = ( V_76 ) 1 << V_11 -> V_79 . V_95 ;
if ( V_198 + V_124 > V_11 -> V_199 ) {
F_15 ( V_198 < V_11 -> V_199 ) ;
V_124 = V_11 -> V_199 - V_198 ;
}
V_233 = ( T_4 ) F_169 ( 0 , V_124 ) ;
V_139 = F_178 ( V_233 , V_34 ) ;
if ( F_23 ( V_139 ) ) {
V_190 = F_179 ( V_139 ) ;
V_139 = NULL ;
goto V_87;
}
V_190 = - V_32 ;
V_242 = F_163 ( V_166 ,
V_198 , V_124 ) ;
if ( ! V_242 )
goto V_87;
V_190 = F_168 ( V_242 , V_186 , V_139 ) ;
if ( V_190 )
goto V_87;
V_242 -> V_252 = V_139 ;
V_242 -> V_253 = V_233 ;
V_242 -> V_182 = F_174 ;
V_190 = F_180 ( V_242 ) ;
if ( ! V_190 )
return 0 ;
V_242 -> V_252 = NULL ;
V_242 -> V_253 = 0 ;
V_242 -> V_166 = NULL ;
F_110 ( V_166 ) ;
V_87:
if ( V_139 )
F_151 ( V_139 , V_233 ) ;
if ( V_242 )
F_111 ( V_242 ) ;
V_166 -> V_190 = V_190 ;
V_166 -> V_191 = 0 ;
F_102 ( V_166 ) ;
return V_190 ;
}
static void F_181 ( struct V_165 * V_166 )
{
struct V_165 * V_244 ;
struct V_10 * V_11 ;
int V_190 ;
F_15 ( ! F_100 ( V_166 ) ) ;
V_244 = V_166 -> V_166 ;
V_166 -> V_166 = NULL ;
F_110 ( V_244 ) ;
F_15 ( V_244 ) ;
F_15 ( V_244 -> V_168 ) ;
V_190 = V_166 -> V_190 ;
V_166 -> V_190 = 0 ;
F_18 ( L_39 , V_33 ,
V_166 , V_244 , V_190 ,
V_166 -> V_191 , V_166 -> V_124 ) ;
F_110 ( V_166 ) ;
V_11 = V_244 -> V_168 -> V_11 ;
if ( ! V_11 -> V_199 ) {
struct V_187 * V_188 ;
V_188 = & V_11 -> V_27 -> V_38 -> V_188 ;
V_190 = F_116 ( V_188 , V_244 ) ;
if ( ! V_190 )
return;
}
if ( ! V_190 ) {
F_104 ( V_244 , true ) ;
} else if ( V_190 == - V_23 ) {
F_104 ( V_244 , false ) ;
} else if ( V_190 ) {
V_244 -> V_190 = V_190 ;
goto V_246;
}
V_244 -> V_190 = F_182 ( V_244 ) ;
V_246:
if ( V_244 -> V_190 )
F_131 ( V_244 ) ;
}
static int F_183 ( struct V_165 * V_166 )
{
struct V_165 * V_256 ;
struct V_10 * V_11 ;
struct V_187 * V_188 ;
struct V_138 * * V_139 = NULL ;
T_4 V_233 ;
T_5 V_66 ;
int V_31 ;
V_66 = sizeof ( V_75 ) + sizeof ( V_257 ) + sizeof ( V_257 ) ;
V_233 = ( T_4 ) F_169 ( 0 , V_66 ) ;
V_139 = F_178 ( V_233 , V_34 ) ;
if ( F_23 ( V_139 ) )
return F_179 ( V_139 ) ;
V_31 = - V_32 ;
V_256 = F_148 ( V_166 -> V_217 , 0 , 0 ,
V_186 ) ;
if ( ! V_256 )
goto V_246;
F_108 ( V_166 ) ;
V_256 -> V_166 = V_166 ;
V_256 -> V_139 = V_139 ;
V_256 -> V_233 = V_233 ;
F_15 ( V_166 -> V_168 ) ;
V_11 = V_166 -> V_168 -> V_11 ;
V_256 -> V_189 = F_143 ( V_11 , false ,
V_256 ) ;
if ( ! V_256 -> V_189 )
goto V_246;
V_256 -> V_182 = F_181 ;
F_184 ( V_256 -> V_189 , 0 , V_213 ) ;
F_185 ( V_256 -> V_189 , 0 , V_139 , V_66 , 0 ,
false , false ) ;
F_140 ( V_256 ) ;
V_188 = & V_11 -> V_27 -> V_38 -> V_188 ;
V_31 = F_116 ( V_188 , V_256 ) ;
V_246:
if ( V_31 )
F_110 ( V_166 ) ;
return V_31 ;
}
static int F_182 ( struct V_165 * V_166 )
{
struct V_175 * V_168 ;
struct V_10 * V_11 ;
bool V_258 ;
F_15 ( F_100 ( V_166 ) ) ;
V_168 = V_166 -> V_168 ;
F_15 ( V_168 ) ;
V_11 = V_168 -> V_11 ;
if ( ! F_123 ( V_168 ) ||
! F_129 ( V_168 ) ||
V_11 -> V_199 <= V_166 -> V_198 ||
( ( V_258 = F_106 ( V_166 ) ) &&
F_107 ( V_166 ) ) ) {
struct V_10 * V_11 ;
struct V_187 * V_188 ;
V_11 = V_166 -> V_168 -> V_11 ;
V_188 = & V_11 -> V_27 -> V_38 -> V_188 ;
return F_116 ( V_188 , V_166 ) ;
}
if ( V_258 )
return F_177 ( V_166 ) ;
return F_183 ( V_166 ) ;
}
static int F_180 ( struct V_175 * V_168 )
{
struct V_165 * V_166 ;
struct V_165 * V_241 ;
F_18 ( L_20 , V_33 , V_168 ) ;
F_162 (img_request, obj_request, next_obj_request) {
int V_31 ;
V_31 = F_182 ( V_166 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static void F_186 ( struct V_175 * V_168 )
{
struct V_165 * V_166 ;
struct V_10 * V_11 ;
V_76 V_259 ;
V_76 V_260 ;
int V_254 ;
F_15 ( F_112 ( V_168 ) ) ;
V_166 = V_168 -> V_166 ;
V_260 = V_168 -> V_191 ;
V_254 = V_168 -> V_190 ;
F_111 ( V_168 ) ;
F_15 ( V_166 ) ;
F_15 ( V_166 -> V_168 ) ;
V_11 = V_166 -> V_168 -> V_11 ;
if ( ! V_11 -> V_199 ) {
struct V_187 * V_188 ;
V_188 = & V_11 -> V_27 -> V_38 -> V_188 ;
V_254 = F_116 ( V_188 , V_166 ) ;
if ( ! V_254 )
return;
}
V_166 -> V_190 = V_254 ;
if ( V_166 -> V_190 )
goto V_246;
F_15 ( V_166 -> V_198 < V_125 - V_166 -> V_124 ) ;
V_259 = V_166 -> V_198 + V_166 -> V_124 ;
if ( V_259 > V_11 -> V_199 ) {
V_76 V_191 = 0 ;
if ( V_166 -> V_198 < V_11 -> V_199 )
V_191 = V_11 -> V_199 -
V_166 -> V_198 ;
V_166 -> V_191 = F_187 ( V_260 , V_191 ) ;
} else {
V_166 -> V_191 = V_260 ;
}
V_246:
F_130 ( V_166 ) ;
F_131 ( V_166 ) ;
}
static void F_135 ( struct V_165 * V_166 )
{
struct V_175 * V_168 ;
int V_190 ;
F_15 ( F_100 ( V_166 ) ) ;
F_15 ( V_166 -> V_168 != NULL ) ;
F_15 ( V_166 -> V_190 == ( V_261 ) - V_23 ) ;
F_15 ( F_115 ( V_166 -> type ) ) ;
V_168 = F_163 ( V_166 ,
V_166 -> V_198 ,
V_166 -> V_124 ) ;
V_190 = - V_32 ;
if ( ! V_168 )
goto V_87;
if ( V_166 -> type == V_185 )
V_190 = F_168 ( V_168 , V_185 ,
V_166 -> V_196 ) ;
else
V_190 = F_168 ( V_168 , V_186 ,
V_166 -> V_139 ) ;
if ( V_190 )
goto V_87;
V_168 -> V_182 = F_186 ;
V_190 = F_180 ( V_168 ) ;
if ( V_190 )
goto V_87;
return;
V_87:
if ( V_168 )
F_111 ( V_168 ) ;
V_166 -> V_190 = V_190 ;
V_166 -> V_191 = 0 ;
F_102 ( V_166 ) ;
}
static int F_188 ( struct V_10 * V_11 , V_76 V_262 )
{
struct V_165 * V_166 ;
struct V_187 * V_188 = & V_11 -> V_27 -> V_38 -> V_188 ;
int V_31 ;
V_166 = F_148 ( V_11 -> V_263 , 0 , 0 ,
V_184 ) ;
if ( ! V_166 )
return - V_32 ;
V_31 = - V_32 ;
V_166 -> V_189 = F_143 ( V_11 , false , V_166 ) ;
if ( ! V_166 -> V_189 )
goto V_246;
V_166 -> V_182 = F_110 ;
F_189 ( V_166 -> V_189 , 0 , V_215 ,
V_262 , 0 , 0 ) ;
F_140 ( V_166 ) ;
V_31 = F_116 ( V_188 , V_166 ) ;
V_246:
if ( V_31 )
F_110 ( V_166 ) ;
return V_31 ;
}
static void F_190 ( V_76 V_264 , V_76 V_262 , T_8 V_204 , void * V_265 )
{
struct V_10 * V_11 = (struct V_10 * ) V_265 ;
int V_31 ;
if ( ! V_11 )
return;
F_18 ( L_40 , V_33 ,
V_11 -> V_263 , ( unsigned long long ) V_262 ,
( unsigned int ) V_204 ) ;
V_31 = F_191 ( V_11 ) ;
if ( V_31 )
F_97 ( V_11 , L_41 , V_31 ) ;
F_188 ( V_11 , V_262 ) ;
}
static int F_192 ( struct V_10 * V_11 , bool V_266 )
{
struct V_187 * V_188 = & V_11 -> V_27 -> V_38 -> V_188 ;
struct V_165 * V_166 ;
int V_31 ;
F_15 ( V_266 ^ ! ! V_11 -> V_267 ) ;
F_15 ( V_266 ^ ! ! V_11 -> V_268 ) ;
if ( V_266 ) {
V_31 = F_193 ( V_188 , F_190 , V_11 ,
& V_11 -> V_267 ) ;
if ( V_31 < 0 )
return V_31 ;
F_15 ( V_11 -> V_267 != NULL ) ;
}
V_31 = - V_32 ;
V_166 = F_148 ( V_11 -> V_263 , 0 , 0 ,
V_184 ) ;
if ( ! V_166 )
goto V_269;
V_166 -> V_189 = F_143 ( V_11 , true , V_166 ) ;
if ( ! V_166 -> V_189 )
goto V_269;
if ( V_266 )
F_194 ( V_188 , V_166 -> V_189 ) ;
else
F_195 ( V_188 ,
V_11 -> V_268 -> V_189 ) ;
F_189 ( V_166 -> V_189 , 0 , V_216 ,
V_11 -> V_267 -> V_270 , 0 , V_266 ? 1 : 0 ) ;
F_142 ( V_166 ) ;
V_31 = F_116 ( V_188 , V_166 ) ;
if ( V_31 )
goto V_269;
V_31 = F_120 ( V_166 ) ;
if ( V_31 )
goto V_269;
V_31 = V_166 -> V_190 ;
if ( V_31 )
goto V_269;
if ( V_266 ) {
V_11 -> V_268 = V_166 ;
return 0 ;
}
F_110 ( V_11 -> V_268 ) ;
V_11 -> V_268 = NULL ;
V_269:
F_196 ( V_11 -> V_267 ) ;
V_11 -> V_267 = NULL ;
if ( V_166 )
F_110 ( V_166 ) ;
return V_31 ;
}
static int F_197 ( struct V_10 * V_11 ,
const char * V_217 ,
const char * V_271 ,
const char * V_272 ,
const void * V_273 ,
T_5 V_274 ,
void * V_275 ,
T_5 V_276 )
{
struct V_187 * V_188 = & V_11 -> V_27 -> V_38 -> V_188 ;
struct V_165 * V_166 ;
struct V_138 * * V_139 ;
T_4 V_233 ;
int V_31 ;
V_233 = ( T_4 ) F_169 ( 0 , V_276 ) ;
V_139 = F_178 ( V_233 , V_34 ) ;
if ( F_23 ( V_139 ) )
return F_179 ( V_139 ) ;
V_31 = - V_32 ;
V_166 = F_148 ( V_217 , 0 , V_276 ,
V_186 ) ;
if ( ! V_166 )
goto V_246;
V_166 -> V_139 = V_139 ;
V_166 -> V_233 = V_233 ;
V_166 -> V_189 = F_143 ( V_11 , false , V_166 ) ;
if ( ! V_166 -> V_189 )
goto V_246;
F_175 ( V_166 -> V_189 , 0 , V_214 ,
V_271 , V_272 ) ;
if ( V_274 ) {
struct V_277 * V_278 ;
V_278 = F_19 ( sizeof ( * V_278 ) , V_279 ) ;
if ( ! V_278 )
goto V_246;
F_198 ( V_278 ) ;
F_199 ( V_278 , V_273 , V_274 ) ;
F_200 ( V_166 -> V_189 , 0 ,
V_278 ) ;
}
F_201 ( V_166 -> V_189 , 0 ,
V_166 -> V_139 , V_276 ,
0 , false , false ) ;
F_140 ( V_166 ) ;
V_31 = F_116 ( V_188 , V_166 ) ;
if ( V_31 )
goto V_246;
V_31 = F_120 ( V_166 ) ;
if ( V_31 )
goto V_246;
V_31 = V_166 -> V_190 ;
if ( V_31 < 0 )
goto V_246;
F_15 ( V_166 -> V_191 < ( V_76 ) V_3 ) ;
V_31 = ( int ) V_166 -> V_191 ;
F_202 ( V_139 , V_275 , 0 , V_166 -> V_191 ) ;
V_246:
if ( V_166 )
F_110 ( V_166 ) ;
else
F_151 ( V_139 , V_233 ) ;
return V_31 ;
}
static void F_203 ( struct V_280 * V_281 )
__releases( V_281 -> V_282 ) __acquires( V_281 -> V_282 )
{
struct V_10 * V_11 = V_281 -> V_283 ;
bool V_17 = V_11 -> V_16 . V_17 ;
struct V_284 * V_238 ;
int V_190 ;
while ( ( V_238 = F_204 ( V_281 ) ) ) {
bool V_221 = F_205 ( V_238 ) == V_285 ;
struct V_175 * V_168 ;
V_76 V_116 ;
V_76 V_124 ;
if ( V_238 -> V_286 != V_287 ) {
F_18 ( L_42 , V_33 ,
( int ) V_238 -> V_286 ) ;
F_206 ( V_238 , 0 ) ;
continue;
}
V_116 = ( V_76 ) F_207 ( V_238 ) << V_72 ;
V_124 = ( V_76 ) F_208 ( V_238 ) ;
if ( ! V_124 ) {
F_18 ( L_43 , V_33 ) ;
F_206 ( V_238 , 0 ) ;
continue;
}
F_11 ( V_281 -> V_282 ) ;
if ( V_221 ) {
V_190 = - V_18 ;
if ( V_17 )
goto V_288;
F_15 ( V_11 -> V_101 -> V_102 == V_103 ) ;
}
if ( ! F_10 ( V_289 , & V_11 -> V_21 ) ) {
F_18 ( L_44 ) ;
F_15 ( V_11 -> V_101 -> V_102 != V_103 ) ;
V_190 = - V_290 ;
goto V_288;
}
V_190 = - V_4 ;
if ( V_116 && V_124 > V_125 - V_116 + 1 ) {
F_97 ( V_11 , L_45 ,
V_116 , V_124 ) ;
goto V_288;
}
V_190 = - V_104 ;
if ( V_116 + V_124 > V_11 -> V_16 . V_66 ) {
F_97 ( V_11 , L_46 ,
V_116 , V_124 , V_11 -> V_16 . V_66 ) ;
goto V_288;
}
V_190 = - V_32 ;
V_168 = F_157 ( V_11 , V_116 , V_124 ,
V_221 ) ;
if ( ! V_168 )
goto V_288;
V_168 -> V_238 = V_238 ;
V_190 = F_168 ( V_168 , V_185 ,
V_238 -> V_126 ) ;
if ( ! V_190 )
V_190 = F_180 ( V_168 ) ;
if ( V_190 )
F_111 ( V_168 ) ;
V_288:
F_9 ( V_281 -> V_282 ) ;
if ( V_190 < 0 ) {
F_97 ( V_11 , L_47 ,
V_221 ? L_31 : L_32 ,
V_124 , V_116 , V_190 ) ;
F_206 ( V_238 , V_190 ) ;
}
}
}
static int F_209 ( struct V_280 * V_281 , struct V_291 * V_292 ,
struct V_131 * V_293 )
{
struct V_10 * V_11 = V_281 -> V_283 ;
T_9 V_294 ;
T_9 V_295 ;
T_9 V_296 ;
int V_31 ;
V_294 = F_210 ( V_292 -> V_154 ) + V_292 -> V_155 ;
V_295 = 1 << ( V_11 -> V_79 . V_95 - V_72 ) ;
V_296 = V_294 & ( V_295 - 1 ) ;
V_31 = ( int ) ( V_295 - V_296 ) << V_72 ;
if ( V_31 > V_292 -> V_153 )
V_31 -= V_292 -> V_153 ;
else
V_31 = 0 ;
F_15 ( V_293 -> V_135 <= V_145 ) ;
if ( V_31 > ( int ) V_293 -> V_135 || ! V_292 -> V_153 )
V_31 = ( int ) V_293 -> V_135 ;
return V_31 ;
}
static void F_211 ( struct V_10 * V_11 )
{
struct V_24 * V_25 = V_11 -> V_25 ;
if ( ! V_25 )
return;
V_11 -> V_25 = NULL ;
if ( V_25 -> V_21 & V_297 ) {
F_212 ( V_25 ) ;
if ( V_25 -> V_298 )
F_213 ( V_25 -> V_298 ) ;
}
F_214 ( V_25 ) ;
}
static int F_215 ( struct V_10 * V_11 ,
const char * V_217 ,
V_76 V_116 , V_76 V_124 , void * V_133 )
{
struct V_187 * V_188 = & V_11 -> V_27 -> V_38 -> V_188 ;
struct V_165 * V_166 ;
struct V_138 * * V_139 = NULL ;
T_4 V_233 ;
T_5 V_66 ;
int V_31 ;
V_233 = ( T_4 ) F_169 ( V_116 , V_124 ) ;
V_139 = F_178 ( V_233 , V_34 ) ;
if ( F_23 ( V_139 ) )
V_31 = F_179 ( V_139 ) ;
V_31 = - V_32 ;
V_166 = F_148 ( V_217 , V_116 , V_124 ,
V_186 ) ;
if ( ! V_166 )
goto V_246;
V_166 -> V_139 = V_139 ;
V_166 -> V_233 = V_233 ;
V_166 -> V_189 = F_143 ( V_11 , false , V_166 ) ;
if ( ! V_166 -> V_189 )
goto V_246;
F_170 ( V_166 -> V_189 , 0 , V_211 ,
V_116 , V_124 , 0 , 0 ) ;
F_172 ( V_166 -> V_189 , 0 ,
V_166 -> V_139 ,
V_166 -> V_124 ,
V_166 -> V_116 & ~ V_144 ,
false , false ) ;
F_140 ( V_166 ) ;
V_31 = F_116 ( V_188 , V_166 ) ;
if ( V_31 )
goto V_246;
V_31 = F_120 ( V_166 ) ;
if ( V_31 )
goto V_246;
V_31 = V_166 -> V_190 ;
if ( V_31 < 0 )
goto V_246;
F_15 ( V_166 -> V_191 <= ( V_76 ) V_73 ) ;
V_66 = ( T_5 ) V_166 -> V_191 ;
F_202 ( V_139 , V_133 , 0 , V_66 ) ;
F_15 ( V_66 <= ( T_5 ) V_3 ) ;
V_31 = ( int ) V_66 ;
V_246:
if ( V_166 )
F_110 ( V_166 ) ;
else
F_151 ( V_139 , V_233 ) ;
return V_31 ;
}
static int F_216 ( struct V_10 * V_11 )
{
struct V_64 * V_65 = NULL ;
T_4 V_67 = 0 ;
V_76 V_299 = 0 ;
T_4 V_300 ;
int V_31 ;
do {
T_5 V_66 ;
F_29 ( V_65 ) ;
V_66 = sizeof ( * V_65 ) ;
V_66 += V_67 * sizeof ( struct V_90 ) ;
V_66 += V_299 ;
V_65 = F_19 ( V_66 , V_34 ) ;
if ( ! V_65 )
return - V_32 ;
V_31 = F_215 ( V_11 , V_11 -> V_263 ,
0 , V_66 , V_65 ) ;
if ( V_31 < 0 )
goto V_246;
if ( ( T_5 ) V_31 < V_66 ) {
V_31 = - V_290 ;
F_97 ( V_11 , L_48 ,
V_66 , V_31 ) ;
goto V_246;
}
if ( ! F_50 ( V_65 ) ) {
V_31 = - V_290 ;
F_97 ( V_11 , L_49 ) ;
goto V_246;
}
V_299 = F_52 ( V_65 -> V_77 ) ;
V_300 = V_67 ;
V_67 = F_51 ( V_65 -> V_67 ) ;
} while ( V_67 != V_300 );
V_31 = F_53 ( V_11 , V_65 ) ;
V_246:
F_29 ( V_65 ) ;
return V_31 ;
}
static void F_217 ( struct V_10 * V_11 )
{
V_76 V_102 ;
if ( ! F_10 ( V_289 , & V_11 -> V_21 ) )
return;
V_102 = V_11 -> V_101 -> V_102 ;
if ( V_102 == V_103 )
return;
if ( F_60 ( V_11 , V_102 ) == V_112 )
F_126 ( V_289 , & V_11 -> V_21 ) ;
}
static int F_191 ( struct V_10 * V_11 )
{
V_76 V_301 ;
int V_31 ;
F_15 ( F_49 ( V_11 -> V_63 ) ) ;
F_218 ( & V_11 -> V_237 ) ;
V_301 = V_11 -> V_16 . V_66 ;
if ( V_11 -> V_63 == 1 )
V_31 = F_216 ( V_11 ) ;
else
V_31 = F_219 ( V_11 ) ;
F_217 ( V_11 ) ;
F_220 ( & V_11 -> V_237 ) ;
if ( V_301 != V_11 -> V_16 . V_66 ) {
T_9 V_66 ;
V_66 = ( T_9 ) V_11 -> V_16 . V_66 / V_302 ;
F_18 ( L_50 , ( unsigned long long ) V_66 ) ;
F_221 ( V_11 -> V_25 , V_66 ) ;
F_222 ( V_11 -> V_25 ) ;
}
return V_31 ;
}
static int F_223 ( struct V_10 * V_11 )
{
struct V_24 * V_25 ;
struct V_280 * V_281 ;
V_76 V_123 ;
V_25 = F_224 ( V_303 ) ;
if ( ! V_25 )
return - V_32 ;
snprintf ( V_25 -> V_304 , sizeof( V_25 -> V_304 ) , V_305 L_51 ,
V_11 -> V_306 ) ;
V_25 -> V_307 = V_11 -> V_307 ;
V_25 -> V_308 = 0 ;
V_25 -> V_309 = & V_310 ;
V_25 -> V_13 = V_11 ;
V_281 = F_225 ( F_203 , & V_11 -> V_19 ) ;
if ( ! V_281 )
goto V_311;
F_226 ( V_281 , V_302 ) ;
V_123 = F_76 ( & V_11 -> V_79 ) ;
F_227 ( V_281 , V_123 / V_302 ) ;
F_228 ( V_281 , V_123 ) ;
F_229 ( V_281 , V_123 ) ;
F_230 ( V_281 , V_123 ) ;
F_231 ( V_281 , F_209 ) ;
V_25 -> V_298 = V_281 ;
V_281 -> V_283 = V_11 ;
V_11 -> V_25 = V_25 ;
return 0 ;
V_311:
F_214 ( V_25 ) ;
return - V_32 ;
}
static struct V_10 * F_232 ( struct V_5 * V_6 )
{
return F_45 ( V_6 , struct V_10 , V_6 ) ;
}
static T_10 F_233 ( struct V_5 * V_6 ,
struct V_312 * V_313 , char * V_133 )
{
struct V_10 * V_11 = F_232 ( V_6 ) ;
return sprintf ( V_133 , L_52 ,
( unsigned long long ) V_11 -> V_16 . V_66 ) ;
}
static T_10 F_234 ( struct V_5 * V_6 ,
struct V_312 * V_313 , char * V_133 )
{
struct V_10 * V_11 = F_232 ( V_6 ) ;
return sprintf ( V_133 , L_53 ,
( unsigned long long ) V_11 -> V_16 . V_100 ) ;
}
static T_10 F_235 ( struct V_5 * V_6 ,
struct V_312 * V_313 , char * V_133 )
{
struct V_10 * V_11 = F_232 ( V_6 ) ;
if ( V_11 -> V_307 )
return sprintf ( V_133 , L_54 , V_11 -> V_307 ) ;
return sprintf ( V_133 , L_55 ) ;
}
static T_10 F_236 ( struct V_5 * V_6 ,
struct V_312 * V_313 , char * V_133 )
{
struct V_10 * V_11 = F_232 ( V_6 ) ;
return sprintf ( V_133 , L_56 ,
F_237 ( V_11 -> V_27 -> V_38 ) ) ;
}
static T_10 F_238 ( struct V_5 * V_6 ,
struct V_312 * V_313 , char * V_133 )
{
struct V_10 * V_11 = F_232 ( V_6 ) ;
return sprintf ( V_133 , L_57 , V_11 -> V_101 -> V_314 ) ;
}
static T_10 F_239 ( struct V_5 * V_6 ,
struct V_312 * V_313 , char * V_133 )
{
struct V_10 * V_11 = F_232 ( V_6 ) ;
return sprintf ( V_133 , L_52 ,
( unsigned long long ) V_11 -> V_101 -> V_315 ) ;
}
static T_10 F_240 ( struct V_5 * V_6 ,
struct V_312 * V_313 , char * V_133 )
{
struct V_10 * V_11 = F_232 ( V_6 ) ;
if ( V_11 -> V_101 -> V_316 )
return sprintf ( V_133 , L_57 , V_11 -> V_101 -> V_316 ) ;
return sprintf ( V_133 , L_58 ) ;
}
static T_10 F_241 ( struct V_5 * V_6 ,
struct V_312 * V_313 , char * V_133 )
{
struct V_10 * V_11 = F_232 ( V_6 ) ;
return sprintf ( V_133 , L_57 , V_11 -> V_101 -> V_317 ) ;
}
static T_10 F_242 ( struct V_5 * V_6 ,
struct V_312 * V_313 ,
char * V_133 )
{
struct V_10 * V_11 = F_232 ( V_6 ) ;
return sprintf ( V_133 , L_57 , V_11 -> V_101 -> V_106 ) ;
}
static T_10 F_243 ( struct V_5 * V_6 ,
struct V_312 * V_313 ,
char * V_133 )
{
struct V_10 * V_11 = F_232 ( V_6 ) ;
struct V_318 * V_101 = V_11 -> V_234 ;
int V_319 ;
char * V_320 = V_133 ;
if ( ! V_101 )
return sprintf ( V_133 , L_59 ) ;
V_319 = sprintf ( V_320 , L_60 ,
( unsigned long long ) V_101 -> V_315 , V_101 -> V_314 ) ;
if ( V_319 < 0 )
return V_319 ;
V_320 += V_319 ;
V_319 = sprintf ( V_320 , L_61 , V_101 -> V_317 ,
V_101 -> V_316 ? V_101 -> V_316 : L_62 ) ;
if ( V_319 < 0 )
return V_319 ;
V_320 += V_319 ;
V_319 = sprintf ( V_320 , L_63 ,
( unsigned long long ) V_101 -> V_102 , V_101 -> V_106 ) ;
if ( V_319 < 0 )
return V_319 ;
V_320 += V_319 ;
V_319 = sprintf ( V_320 , L_64 , V_11 -> V_199 ) ;
if ( V_319 < 0 )
return V_319 ;
V_320 += V_319 ;
return ( T_10 ) ( V_320 - V_133 ) ;
}
static T_10 F_244 ( struct V_5 * V_6 ,
struct V_312 * V_313 ,
const char * V_133 ,
T_5 V_66 )
{
struct V_10 * V_11 = F_232 ( V_6 ) ;
int V_31 ;
V_31 = F_191 ( V_11 ) ;
if ( V_31 )
F_97 ( V_11 , L_65 , V_31 ) ;
return V_31 < 0 ? V_31 : V_66 ;
}
static void F_245 ( struct V_5 * V_6 )
{
}
static struct V_318 * F_246 ( struct V_318 * V_101 )
{
F_33 ( & V_101 -> V_36 ) ;
return V_101 ;
}
static void F_154 ( struct V_318 * V_101 )
{
if ( V_101 )
F_48 ( & V_101 -> V_36 , V_321 ) ;
}
static struct V_318 * F_247 ( void )
{
struct V_318 * V_101 ;
V_101 = F_248 ( sizeof ( * V_101 ) , V_34 ) ;
if ( ! V_101 )
return NULL ;
F_20 ( & V_101 -> V_36 ) ;
return V_101 ;
}
static void V_321 ( struct V_36 * V_36 )
{
struct V_318 * V_101 = F_45 ( V_36 , struct V_318 , V_36 ) ;
F_29 ( V_101 -> V_314 ) ;
F_29 ( V_101 -> V_317 ) ;
F_29 ( V_101 -> V_316 ) ;
F_29 ( V_101 -> V_106 ) ;
F_29 ( V_101 ) ;
}
static struct V_10 * F_249 ( struct V_27 * V_30 ,
struct V_318 * V_101 )
{
struct V_10 * V_11 ;
V_11 = F_248 ( sizeof ( * V_11 ) , V_34 ) ;
if ( ! V_11 )
return NULL ;
F_161 ( & V_11 -> V_19 ) ;
V_11 -> V_21 = 0 ;
F_250 ( & V_11 -> V_235 , 0 ) ;
F_21 ( & V_11 -> V_37 ) ;
F_251 ( & V_11 -> V_237 ) ;
V_11 -> V_101 = V_101 ;
V_11 -> V_27 = V_30 ;
V_11 -> V_231 . V_322 = F_252 ( 1 << V_323 ) ;
V_11 -> V_231 . V_324 = F_252 ( 1 ) ;
V_11 -> V_231 . V_325 = F_252 ( 1 << V_323 ) ;
V_11 -> V_231 . V_326 = F_252 ( ( T_4 ) V_101 -> V_315 ) ;
return V_11 ;
}
static void F_253 ( struct V_10 * V_11 )
{
F_47 ( V_11 -> V_27 ) ;
F_154 ( V_11 -> V_101 ) ;
F_29 ( V_11 ) ;
}
static int F_65 ( struct V_10 * V_11 , V_76 V_102 ,
T_8 * V_71 , V_76 * V_114 )
{
V_75 V_327 = F_254 ( V_102 ) ;
int V_31 ;
struct {
T_8 V_71 ;
V_75 V_66 ;
} V_328 ( ( V_329 ) ) V_330 = { 0 } ;
V_31 = F_197 ( V_11 , V_11 -> V_263 ,
L_37 , L_66 ,
& V_327 , sizeof ( V_327 ) ,
& V_330 , sizeof ( V_330 ) ) ;
F_18 ( L_67 , V_33 , V_31 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_31 < sizeof ( V_330 ) )
return - V_331 ;
if ( V_71 )
* V_71 = V_330 . V_71 ;
* V_114 = F_52 ( V_330 . V_66 ) ;
F_18 ( L_68 ,
( unsigned long long ) V_102 , ( unsigned int ) * V_71 ,
( unsigned long long ) * V_114 ) ;
return 0 ;
}
static int F_255 ( struct V_10 * V_11 )
{
return F_65 ( V_11 , V_103 ,
& V_11 -> V_79 . V_95 ,
& V_11 -> V_79 . V_94 ) ;
}
static int F_256 ( struct V_10 * V_11 )
{
void * V_332 ;
int V_31 ;
void * V_333 ;
V_332 = F_248 ( V_334 , V_34 ) ;
if ( ! V_332 )
return - V_32 ;
V_31 = F_197 ( V_11 , V_11 -> V_263 ,
L_37 , L_69 , NULL , 0 ,
V_332 , V_334 ) ;
F_18 ( L_67 , V_33 , V_31 ) ;
if ( V_31 < 0 )
goto V_246;
V_333 = V_332 ;
V_11 -> V_79 . V_81 = F_257 ( & V_333 ,
V_333 + V_31 , NULL , V_121 ) ;
V_31 = 0 ;
if ( F_23 ( V_11 -> V_79 . V_81 ) ) {
V_31 = F_179 ( V_11 -> V_79 . V_81 ) ;
V_11 -> V_79 . V_81 = NULL ;
} else {
F_18 ( L_70 , V_11 -> V_79 . V_81 ) ;
}
V_246:
F_29 ( V_332 ) ;
return V_31 ;
}
static int F_67 ( struct V_10 * V_11 , V_76 V_102 ,
V_76 * V_115 )
{
V_75 V_327 = F_254 ( V_102 ) ;
struct {
V_75 V_100 ;
V_75 V_335 ;
} V_328 ( ( V_329 ) ) V_336 = { 0 } ;
V_76 V_335 ;
int V_31 ;
V_31 = F_197 ( V_11 , V_11 -> V_263 ,
L_37 , L_71 ,
& V_327 , sizeof ( V_327 ) ,
& V_336 , sizeof ( V_336 ) ) ;
F_18 ( L_67 , V_33 , V_31 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_31 < sizeof ( V_336 ) )
return - V_331 ;
V_335 = F_52 ( V_336 . V_335 ) ;
if ( V_335 & ~ V_337 )
return - V_290 ;
* V_115 = F_52 ( V_336 . V_100 ) ;
F_18 ( L_72 ,
( unsigned long long ) V_102 ,
( unsigned long long ) * V_115 ,
( unsigned long long ) F_52 ( V_336 . V_335 ) ) ;
return 0 ;
}
static int F_258 ( struct V_10 * V_11 )
{
return F_67 ( V_11 , V_103 ,
& V_11 -> V_79 . V_100 ) ;
}
static int F_259 ( struct V_10 * V_11 )
{
struct V_318 * V_234 ;
T_5 V_66 ;
void * V_332 = NULL ;
V_75 V_327 ;
void * V_333 ;
void * V_140 ;
V_76 V_315 ;
char * V_317 ;
V_76 V_102 ;
V_76 V_338 ;
int V_31 ;
V_234 = F_247 () ;
if ( ! V_234 )
return - V_32 ;
V_66 = sizeof ( V_75 ) +
sizeof ( V_257 ) + V_339 +
sizeof ( V_75 ) +
sizeof ( V_75 ) ;
V_332 = F_19 ( V_66 , V_34 ) ;
if ( ! V_332 ) {
V_31 = - V_32 ;
goto V_87;
}
V_327 = F_254 ( V_103 ) ;
V_31 = F_197 ( V_11 , V_11 -> V_263 ,
L_37 , L_73 ,
& V_327 , sizeof ( V_327 ) ,
V_332 , V_66 ) ;
F_18 ( L_67 , V_33 , V_31 ) ;
if ( V_31 < 0 )
goto V_87;
V_333 = V_332 ;
V_140 = V_332 + V_31 ;
V_31 = - V_331 ;
F_260 ( & V_333 , V_140 , V_315 , V_87 ) ;
if ( V_315 == V_340 ) {
if ( V_11 -> V_199 ) {
V_11 -> V_199 = 0 ;
F_101 () ;
F_155 ( V_11 ) ;
F_261 ( L_74 ,
V_11 -> V_25 -> V_304 ) ;
}
goto V_246;
}
V_31 = - V_104 ;
if ( V_315 > ( V_76 ) V_341 ) {
F_97 ( NULL , L_75 ,
( unsigned long long ) V_315 , V_341 ) ;
goto V_87;
}
V_317 = F_257 ( & V_333 , V_140 , NULL , V_34 ) ;
if ( F_23 ( V_317 ) ) {
V_31 = F_179 ( V_317 ) ;
goto V_87;
}
F_260 ( & V_333 , V_140 , V_102 , V_87 ) ;
F_260 ( & V_333 , V_140 , V_338 , V_87 ) ;
if ( ! V_11 -> V_234 ) {
V_234 -> V_315 = V_315 ;
V_234 -> V_317 = V_317 ;
V_234 -> V_102 = V_102 ;
V_11 -> V_234 = V_234 ;
V_234 = NULL ;
}
V_11 -> V_199 = V_338 ;
F_101 () ;
if ( ! V_338 ) {
if ( V_234 ) {
F_155 ( V_11 ) ;
F_261 ( L_76 ,
V_11 -> V_25 -> V_304 ) ;
} else {
F_97 ( V_11 , L_77
L_78 ) ;
}
}
V_246:
V_31 = 0 ;
V_87:
F_29 ( V_332 ) ;
F_154 ( V_234 ) ;
return V_31 ;
}
static int F_262 ( struct V_10 * V_11 )
{
struct {
V_75 V_98 ;
V_75 V_99 ;
} V_328 ( ( V_329 ) ) V_342 = { 0 } ;
T_5 V_66 = sizeof ( V_342 ) ;
void * V_333 ;
V_76 V_343 ;
V_76 V_98 ;
V_76 V_99 ;
int V_31 ;
V_31 = F_197 ( V_11 , V_11 -> V_263 ,
L_37 , L_79 , NULL , 0 ,
( char * ) & V_342 , V_66 ) ;
F_18 ( L_67 , V_33 , V_31 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_31 < V_66 )
return - V_331 ;
V_31 = - V_4 ;
V_343 = ( V_76 ) 1 << V_11 -> V_79 . V_95 ;
V_333 = & V_342 ;
V_98 = F_263 ( & V_333 ) ;
if ( V_98 != V_343 ) {
F_97 ( V_11 , L_80
L_81 ,
V_98 , V_343 ) ;
return - V_4 ;
}
V_99 = F_263 ( & V_333 ) ;
if ( V_99 != 1 ) {
F_97 ( V_11 , L_82
L_83 , V_99 ) ;
return - V_4 ;
}
V_11 -> V_79 . V_98 = V_98 ;
V_11 -> V_79 . V_99 = V_99 ;
return 0 ;
}
static char * F_264 ( struct V_10 * V_11 )
{
T_5 V_344 ;
char * V_317 ;
void * V_333 ;
void * V_140 ;
T_5 V_66 ;
void * V_332 = NULL ;
T_5 V_86 = 0 ;
char * V_316 = NULL ;
int V_31 ;
F_15 ( ! V_11 -> V_101 -> V_316 ) ;
V_86 = strlen ( V_11 -> V_101 -> V_317 ) ;
V_344 = sizeof ( V_257 ) + V_86 ;
V_317 = F_19 ( V_344 , V_34 ) ;
if ( ! V_317 )
return NULL ;
V_333 = V_317 ;
V_140 = V_317 + V_344 ;
F_265 ( & V_333 , V_140 , V_11 -> V_101 -> V_317 , ( T_4 ) V_86 ) ;
V_66 = sizeof ( V_257 ) + V_345 ;
V_332 = F_19 ( V_66 , V_34 ) ;
if ( ! V_332 )
goto V_246;
V_31 = F_197 ( V_11 , V_346 ,
L_37 , L_84 ,
V_317 , V_344 ,
V_332 , V_66 ) ;
if ( V_31 < 0 )
goto V_246;
V_333 = V_332 ;
V_140 = V_332 + V_31 ;
V_316 = F_257 ( & V_333 , V_140 , & V_86 , V_34 ) ;
if ( F_23 ( V_316 ) )
V_316 = NULL ;
else
F_18 ( L_85 , V_33 , V_316 , V_86 ) ;
V_246:
F_29 ( V_332 ) ;
F_29 ( V_317 ) ;
return V_316 ;
}
static V_76 F_266 ( struct V_10 * V_11 , const char * V_117 )
{
struct V_74 * V_82 = V_11 -> V_79 . V_82 ;
const char * V_106 ;
T_4 V_105 = 0 ;
V_106 = V_11 -> V_79 . V_83 ;
while ( V_105 < V_82 -> V_107 ) {
if ( ! strcmp ( V_117 , V_106 ) )
return V_82 -> V_91 [ V_105 ] ;
V_106 += strlen ( V_106 ) + 1 ;
V_105 ++ ;
}
return V_103 ;
}
static V_76 F_267 ( struct V_10 * V_11 , const char * V_117 )
{
struct V_74 * V_82 = V_11 -> V_79 . V_82 ;
T_4 V_105 ;
bool V_44 = false ;
V_76 V_102 ;
for ( V_105 = 0 ; ! V_44 && V_105 < V_82 -> V_107 ; V_105 ++ ) {
const char * V_106 ;
V_102 = V_82 -> V_91 [ V_105 ] ;
V_106 = F_63 ( V_11 , V_102 ) ;
if ( F_23 ( V_106 ) )
break;
V_44 = ! strcmp ( V_117 , V_106 ) ;
F_29 ( V_106 ) ;
}
return V_44 ? V_102 : V_103 ;
}
static V_76 F_268 ( struct V_10 * V_11 , const char * V_117 )
{
if ( V_11 -> V_63 == 1 )
return F_266 ( V_11 , V_117 ) ;
return F_267 ( V_11 , V_117 ) ;
}
static int F_269 ( struct V_10 * V_11 )
{
struct V_187 * V_188 = & V_11 -> V_27 -> V_38 -> V_188 ;
struct V_318 * V_101 = V_11 -> V_101 ;
const char * V_314 ;
const char * V_316 ;
const char * V_106 ;
int V_31 ;
if ( V_101 -> V_314 ) {
if ( strcmp ( V_101 -> V_106 , V_113 ) ) {
V_76 V_102 ;
V_102 = F_268 ( V_11 , V_101 -> V_106 ) ;
if ( V_102 == V_103 )
return - V_23 ;
V_101 -> V_102 = V_102 ;
} else {
V_101 -> V_102 = V_103 ;
}
return 0 ;
}
V_314 = F_270 ( V_188 -> V_347 , V_101 -> V_315 ) ;
if ( ! V_314 ) {
F_97 ( V_11 , L_86 , V_101 -> V_315 ) ;
return - V_104 ;
}
V_314 = F_58 ( V_314 , V_34 ) ;
if ( ! V_314 )
return - V_32 ;
V_316 = F_264 ( V_11 ) ;
if ( ! V_316 )
F_97 ( V_11 , L_87 ) ;
V_106 = F_62 ( V_11 , V_101 -> V_102 ) ;
if ( ! V_106 ) {
V_31 = - V_32 ;
goto V_87;
}
V_101 -> V_314 = V_314 ;
V_101 -> V_316 = V_316 ;
V_101 -> V_106 = V_106 ;
return 0 ;
V_87:
F_29 ( V_316 ) ;
F_29 ( V_314 ) ;
return V_31 ;
}
static int F_271 ( struct V_10 * V_11 )
{
T_5 V_66 ;
int V_31 ;
void * V_332 ;
void * V_333 ;
void * V_140 ;
V_76 V_88 ;
T_4 V_67 ;
struct V_74 * V_82 ;
T_4 V_85 ;
V_66 = sizeof ( V_75 ) + sizeof ( V_257 ) +
V_348 * sizeof ( V_75 ) ;
V_332 = F_248 ( V_66 , V_34 ) ;
if ( ! V_332 )
return - V_32 ;
V_31 = F_197 ( V_11 , V_11 -> V_263 ,
L_37 , L_88 , NULL , 0 ,
V_332 , V_66 ) ;
F_18 ( L_67 , V_33 , V_31 ) ;
if ( V_31 < 0 )
goto V_246;
V_333 = V_332 ;
V_140 = V_332 + V_31 ;
V_31 = - V_331 ;
F_260 ( & V_333 , V_140 , V_88 , V_246 ) ;
F_272 ( & V_333 , V_140 , V_67 , V_246 ) ;
if ( V_67 > ( V_73 - sizeof ( struct V_74 ) )
/ sizeof ( V_76 ) ) {
V_31 = - V_4 ;
goto V_246;
}
if ( ! F_273 ( & V_333 , V_140 , V_67 * sizeof ( V_75 ) ) )
goto V_246;
V_31 = 0 ;
V_82 = F_55 ( V_67 , V_34 ) ;
if ( ! V_82 ) {
V_31 = - V_32 ;
goto V_246;
}
V_82 -> V_88 = V_88 ;
for ( V_85 = 0 ; V_85 < V_67 ; V_85 ++ )
V_82 -> V_91 [ V_85 ] = F_263 ( & V_333 ) ;
F_56 ( V_11 -> V_79 . V_82 ) ;
V_11 -> V_79 . V_82 = V_82 ;
F_18 ( L_89 ,
( unsigned long long ) V_88 , ( unsigned int ) V_67 ) ;
V_246:
F_29 ( V_332 ) ;
return V_31 ;
}
static const char * F_63 ( struct V_10 * V_11 ,
V_76 V_102 )
{
T_5 V_66 ;
void * V_332 ;
V_75 V_327 ;
int V_31 ;
void * V_333 ;
void * V_140 ;
char * V_106 ;
V_66 = sizeof ( V_257 ) + V_349 ;
V_332 = F_19 ( V_66 , V_34 ) ;
if ( ! V_332 )
return F_31 ( - V_32 ) ;
V_327 = F_254 ( V_102 ) ;
V_31 = F_197 ( V_11 , V_11 -> V_263 ,
L_37 , L_90 ,
& V_327 , sizeof ( V_327 ) ,
V_332 , V_66 ) ;
F_18 ( L_67 , V_33 , V_31 ) ;
if ( V_31 < 0 ) {
V_106 = F_31 ( V_31 ) ;
goto V_246;
}
V_333 = V_332 ;
V_140 = V_332 + V_31 ;
V_106 = F_257 ( & V_333 , V_140 , NULL , V_34 ) ;
if ( F_23 ( V_106 ) )
goto V_246;
F_18 ( L_91 ,
( unsigned long long ) V_102 , V_106 ) ;
V_246:
F_29 ( V_332 ) ;
return V_106 ;
}
static int F_219 ( struct V_10 * V_11 )
{
bool V_80 = V_11 -> V_79 . V_81 == NULL ;
int V_31 ;
V_31 = F_255 ( V_11 ) ;
if ( V_31 )
return V_31 ;
if ( V_80 ) {
V_31 = F_274 ( V_11 ) ;
if ( V_31 )
return V_31 ;
}
if ( V_11 -> V_79 . V_100 & V_350 &&
( V_80 || V_11 -> V_234 ) ) {
bool V_351 ;
V_31 = F_259 ( V_11 ) ;
if ( V_31 )
return V_31 ;
V_351 = V_11 -> V_234 && V_11 -> V_101 -> V_314 ;
if ( V_80 && V_351 )
F_97 ( V_11 , L_92
L_93 ) ;
}
if ( V_11 -> V_101 -> V_102 == V_103 )
if ( V_11 -> V_16 . V_66 != V_11 -> V_79 . V_94 )
V_11 -> V_16 . V_66 = V_11 -> V_79 . V_94 ;
V_31 = F_271 ( V_11 ) ;
F_18 ( L_94 , V_31 ) ;
return V_31 ;
}
static int F_275 ( struct V_10 * V_11 )
{
struct V_5 * V_6 ;
int V_31 ;
V_6 = & V_11 -> V_6 ;
V_6 -> V_352 = & V_353 ;
V_6 -> type = & V_354 ;
V_6 -> V_243 = & V_355 ;
V_6 -> V_356 = V_357 ;
F_276 ( V_6 , L_51 , V_11 -> V_306 ) ;
V_31 = F_277 ( V_6 ) ;
return V_31 ;
}
static void F_278 ( struct V_10 * V_11 )
{
F_279 ( & V_11 -> V_6 ) ;
}
static void F_280 ( struct V_10 * V_11 )
{
V_11 -> V_306 = F_281 ( & V_358 ) ;
F_25 ( & V_359 ) ;
F_26 ( & V_11 -> V_37 , & V_360 ) ;
F_27 ( & V_359 ) ;
F_18 ( L_95 , V_11 ,
( unsigned long long ) V_11 -> V_306 ) ;
}
static void F_282 ( struct V_10 * V_11 )
{
struct V_361 * V_128 ;
int V_362 = V_11 -> V_306 ;
int V_363 ;
F_15 ( V_362 > 0 ) ;
F_18 ( L_96 , V_11 ,
( unsigned long long ) V_11 -> V_306 ) ;
F_25 ( & V_359 ) ;
F_283 ( & V_11 -> V_37 ) ;
if ( V_362 != F_284 ( & V_358 ) ) {
F_27 ( & V_359 ) ;
return;
}
V_363 = 0 ;
F_285 (tmp, &rbd_dev_list) {
struct V_10 * V_11 ;
V_11 = F_286 ( V_128 , struct V_10 , V_37 ) ;
if ( V_11 -> V_306 > V_363 )
V_363 = V_11 -> V_306 ;
}
F_27 ( & V_359 ) ;
F_287 ( & V_358 , V_362 , V_363 ) ;
F_18 ( L_97 ) ;
}
static inline T_5 F_288 ( const char * * V_133 )
{
const char * V_364 = L_98 ;
* V_133 += strspn ( * V_133 , V_364 ) ;
return strcspn ( * V_133 , V_364 ) ;
}
static inline T_5 F_289 ( const char * * V_133 ,
char * V_52 ,
T_5 V_365 )
{
T_5 V_86 ;
V_86 = F_288 ( V_133 ) ;
if ( V_86 < V_365 ) {
memcpy ( V_52 , * V_133 , V_86 ) ;
* ( V_52 + V_86 ) = '\0' ;
}
* V_133 += V_86 ;
return V_86 ;
}
static inline char * F_290 ( const char * * V_133 , T_5 * V_366 )
{
char * V_367 ;
T_5 V_86 ;
V_86 = F_288 ( V_133 ) ;
V_367 = F_291 ( * V_133 , V_86 + 1 , V_34 ) ;
if ( ! V_367 )
return NULL ;
* ( V_367 + V_86 ) = '\0' ;
* V_133 += V_86 ;
if ( V_366 )
* V_366 = V_86 ;
return V_367 ;
}
static int F_292 ( const char * V_133 ,
struct V_28 * * V_29 ,
struct V_48 * * V_368 ,
struct V_318 * * V_318 )
{
T_5 V_86 ;
char * V_70 ;
const char * V_369 ;
char * V_106 ;
T_5 V_370 ;
struct V_318 * V_101 = NULL ;
struct V_48 * V_49 = NULL ;
struct V_28 * V_371 ;
int V_31 ;
V_86 = F_288 ( & V_133 ) ;
if ( ! V_86 ) {
F_97 ( NULL , L_99 ) ;
return - V_4 ;
}
V_369 = V_133 ;
V_370 = V_86 + 1 ;
V_133 += V_86 ;
V_31 = - V_4 ;
V_70 = F_290 ( & V_133 , NULL ) ;
if ( ! V_70 )
return - V_32 ;
if ( ! * V_70 ) {
F_97 ( NULL , L_100 ) ;
goto V_87;
}
V_101 = F_247 () ;
if ( ! V_101 )
goto V_372;
V_101 -> V_314 = F_290 ( & V_133 , NULL ) ;
if ( ! V_101 -> V_314 )
goto V_372;
if ( ! * V_101 -> V_314 ) {
F_97 ( NULL , L_101 ) ;
goto V_87;
}
V_101 -> V_316 = F_290 ( & V_133 , NULL ) ;
if ( ! V_101 -> V_316 )
goto V_372;
if ( ! * V_101 -> V_316 ) {
F_97 ( NULL , L_102 ) ;
goto V_87;
}
V_86 = F_288 ( & V_133 ) ;
if ( ! V_86 ) {
V_133 = V_113 ;
V_86 = sizeof ( V_113 ) - 1 ;
} else if ( V_86 > V_349 ) {
V_31 = - V_373 ;
goto V_87;
}
V_106 = F_291 ( V_133 , V_86 + 1 , V_34 ) ;
if ( ! V_106 )
goto V_372;
* ( V_106 + V_86 ) = '\0' ;
V_101 -> V_106 = V_106 ;
V_49 = F_248 ( sizeof ( * V_49 ) , V_34 ) ;
if ( ! V_49 )
goto V_372;
V_49 -> V_17 = V_374 ;
V_371 = F_293 ( V_70 , V_369 ,
V_369 + V_370 - 1 ,
F_37 , V_49 ) ;
if ( F_23 ( V_371 ) ) {
V_31 = F_179 ( V_371 ) ;
goto V_87;
}
F_29 ( V_70 ) ;
* V_29 = V_371 ;
* V_368 = V_49 ;
* V_318 = V_101 ;
return 0 ;
V_372:
V_31 = - V_32 ;
V_87:
F_29 ( V_49 ) ;
F_154 ( V_101 ) ;
F_29 ( V_70 ) ;
return V_31 ;
}
static int F_294 ( struct V_10 * V_11 )
{
int V_31 ;
T_5 V_66 ;
char * V_217 ;
void * V_375 ;
char * V_317 ;
if ( V_11 -> V_101 -> V_317 ) {
V_11 -> V_63 = * V_11 -> V_101 -> V_317 ? 2 : 1 ;
return 0 ;
}
V_66 = sizeof ( V_376 ) + strlen ( V_11 -> V_101 -> V_316 ) ;
V_217 = F_19 ( V_66 , V_121 ) ;
if ( ! V_217 )
return - V_32 ;
sprintf ( V_217 , L_103 , V_376 , V_11 -> V_101 -> V_316 ) ;
F_18 ( L_104 , V_217 ) ;
V_66 = sizeof ( V_257 ) + V_339 ;
V_375 = F_248 ( V_66 , V_121 ) ;
if ( ! V_375 ) {
V_31 = - V_32 ;
goto V_246;
}
V_31 = F_197 ( V_11 , V_217 ,
L_37 , L_105 , NULL , 0 ,
V_375 , V_339 ) ;
F_18 ( L_67 , V_33 , V_31 ) ;
if ( V_31 == - V_23 ) {
V_317 = F_58 ( L_106 , V_34 ) ;
V_31 = V_317 ? 0 : - V_32 ;
if ( ! V_31 )
V_11 -> V_63 = 1 ;
} else if ( V_31 > sizeof ( V_257 ) ) {
void * V_333 = V_375 ;
V_317 = F_257 ( & V_333 , V_333 + V_31 ,
NULL , V_121 ) ;
V_31 = F_23 ( V_317 ) ? F_179 ( V_317 ) : 0 ;
if ( ! V_31 )
V_11 -> V_63 = 2 ;
} else {
V_31 = - V_4 ;
}
if ( ! V_31 ) {
V_11 -> V_101 -> V_317 = V_317 ;
F_18 ( L_107 , V_317 ) ;
}
V_246:
F_29 ( V_375 ) ;
F_29 ( V_217 ) ;
return V_31 ;
}
static void F_295 ( struct V_10 * V_11 )
{
struct V_78 * V_79 ;
if ( V_11 -> V_199 )
F_155 ( V_11 ) ;
V_79 = & V_11 -> V_79 ;
F_56 ( V_79 -> V_82 ) ;
F_29 ( V_79 -> V_84 ) ;
F_29 ( V_79 -> V_83 ) ;
F_29 ( V_79 -> V_81 ) ;
memset ( V_79 , 0 , sizeof ( * V_79 ) ) ;
}
static int F_274 ( struct V_10 * V_11 )
{
int V_31 ;
V_31 = F_256 ( V_11 ) ;
if ( V_31 )
goto V_87;
V_31 = F_258 ( V_11 ) ;
if ( V_31 )
goto V_87;
if ( V_11 -> V_79 . V_100 & V_377 ) {
V_31 = F_262 ( V_11 ) ;
if ( V_31 < 0 )
goto V_87;
}
return 0 ;
V_87:
V_11 -> V_79 . V_100 = 0 ;
F_29 ( V_11 -> V_79 . V_81 ) ;
V_11 -> V_79 . V_81 = NULL ;
return V_31 ;
}
static int F_296 ( struct V_10 * V_11 )
{
struct V_10 * V_243 = NULL ;
struct V_318 * V_234 ;
struct V_27 * V_30 ;
int V_31 ;
if ( ! V_11 -> V_234 )
return 0 ;
V_234 = F_246 ( V_11 -> V_234 ) ;
V_30 = F_32 ( V_11 -> V_27 ) ;
V_31 = - V_32 ;
V_243 = F_249 ( V_30 , V_234 ) ;
if ( ! V_243 )
goto V_87;
V_31 = F_297 ( V_243 , false ) ;
if ( V_31 < 0 )
goto V_87;
V_11 -> V_243 = V_243 ;
F_250 ( & V_11 -> V_235 , 1 ) ;
return 0 ;
V_87:
if ( V_243 ) {
F_152 ( V_11 ) ;
F_29 ( V_11 -> V_263 ) ;
F_253 ( V_243 ) ;
} else {
F_47 ( V_30 ) ;
F_154 ( V_234 ) ;
}
return V_31 ;
}
static int F_298 ( struct V_10 * V_11 )
{
int V_31 ;
F_280 ( V_11 ) ;
F_299 ( V_378
< sizeof ( V_305 ) + V_379 ) ;
sprintf ( V_11 -> V_117 , L_108 , V_305 , V_11 -> V_306 ) ;
V_31 = F_300 ( 0 , V_11 -> V_117 ) ;
if ( V_31 < 0 )
goto V_380;
V_11 -> V_307 = V_31 ;
V_31 = F_223 ( V_11 ) ;
if ( V_31 )
goto V_381;
V_31 = F_68 ( V_11 ) ;
if ( V_31 )
goto V_382;
F_221 ( V_11 -> V_25 , V_11 -> V_16 . V_66 / V_302 ) ;
V_31 = F_275 ( V_11 ) ;
if ( V_31 )
goto V_383;
F_105 ( V_289 , & V_11 -> V_21 ) ;
F_301 ( V_11 -> V_25 ) ;
F_261 ( L_109 , V_11 -> V_25 -> V_304 ,
( unsigned long long ) V_11 -> V_16 . V_66 ) ;
return V_31 ;
V_383:
F_69 ( V_11 ) ;
V_382:
F_211 ( V_11 ) ;
V_381:
F_302 ( V_11 -> V_307 , V_11 -> V_117 ) ;
V_380:
F_282 ( V_11 ) ;
F_69 ( V_11 ) ;
return V_31 ;
}
static int F_303 ( struct V_10 * V_11 )
{
struct V_318 * V_101 = V_11 -> V_101 ;
T_5 V_66 ;
F_15 ( F_49 ( V_11 -> V_63 ) ) ;
if ( V_11 -> V_63 == 1 )
V_66 = strlen ( V_101 -> V_316 ) + sizeof ( V_384 ) ;
else
V_66 = sizeof ( V_385 ) + strlen ( V_101 -> V_317 ) ;
V_11 -> V_263 = F_19 ( V_66 , V_34 ) ;
if ( ! V_11 -> V_263 )
return - V_32 ;
if ( V_11 -> V_63 == 1 )
sprintf ( V_11 -> V_263 , L_103 ,
V_101 -> V_316 , V_384 ) ;
else
sprintf ( V_11 -> V_263 , L_103 ,
V_385 , V_101 -> V_317 ) ;
return 0 ;
}
static void F_304 ( struct V_10 * V_11 )
{
F_295 ( V_11 ) ;
F_29 ( V_11 -> V_263 ) ;
V_11 -> V_263 = NULL ;
V_11 -> V_63 = 0 ;
F_29 ( V_11 -> V_101 -> V_317 ) ;
V_11 -> V_101 -> V_317 = NULL ;
F_253 ( V_11 ) ;
}
static int F_297 ( struct V_10 * V_11 , bool V_16 )
{
int V_31 ;
int V_128 ;
V_31 = F_294 ( V_11 ) ;
if ( V_31 )
return V_31 ;
F_15 ( V_11 -> V_101 -> V_317 ) ;
F_15 ( F_49 ( V_11 -> V_63 ) ) ;
V_31 = F_303 ( V_11 ) ;
if ( V_31 )
goto V_386;
if ( V_16 ) {
V_31 = F_192 ( V_11 , true ) ;
if ( V_31 )
goto V_387;
}
if ( V_11 -> V_63 == 1 )
V_31 = F_216 ( V_11 ) ;
else
V_31 = F_219 ( V_11 ) ;
if ( V_31 )
goto V_388;
V_31 = F_269 ( V_11 ) ;
if ( V_31 )
goto V_389;
V_31 = F_296 ( V_11 ) ;
if ( V_31 )
goto V_389;
F_18 ( L_110 ,
V_11 -> V_63 , V_11 -> V_263 ) ;
return 0 ;
V_389:
F_295 ( V_11 ) ;
V_388:
if ( V_16 ) {
V_128 = F_192 ( V_11 , false ) ;
if ( V_128 )
F_97 ( V_11 , L_111
L_112 , V_128 ) ;
}
V_387:
F_29 ( V_11 -> V_263 ) ;
V_11 -> V_263 = NULL ;
V_386:
V_11 -> V_63 = 0 ;
F_29 ( V_11 -> V_101 -> V_317 ) ;
V_11 -> V_101 -> V_317 = NULL ;
F_18 ( L_113 , V_31 ) ;
return V_31 ;
}
static T_10 F_305 ( struct V_390 * V_352 ,
const char * V_133 ,
T_5 V_319 )
{
struct V_10 * V_11 = NULL ;
struct V_28 * V_29 = NULL ;
struct V_48 * V_49 = NULL ;
struct V_318 * V_101 = NULL ;
struct V_27 * V_30 ;
struct V_187 * V_188 ;
bool V_17 ;
int V_391 = - V_32 ;
if ( ! F_306 ( V_392 ) )
return - V_393 ;
V_391 = F_292 ( V_133 , & V_29 , & V_49 , & V_101 ) ;
if ( V_391 < 0 )
goto V_394;
V_17 = V_49 -> V_17 ;
F_29 ( V_49 ) ;
V_49 = NULL ;
V_30 = F_41 ( V_29 ) ;
if ( F_23 ( V_30 ) ) {
V_391 = F_179 ( V_30 ) ;
goto V_395;
}
V_188 = & V_30 -> V_38 -> V_188 ;
V_391 = F_307 ( V_188 -> V_347 , V_101 -> V_314 ) ;
if ( V_391 < 0 )
goto V_396;
V_101 -> V_315 = ( V_76 ) V_391 ;
if ( V_101 -> V_315 > ( V_76 ) V_341 ) {
F_97 ( NULL , L_114 ,
( unsigned long long ) V_101 -> V_315 , V_341 ) ;
V_391 = - V_104 ;
goto V_396;
}
V_11 = F_249 ( V_30 , V_101 ) ;
if ( ! V_11 )
goto V_396;
V_30 = NULL ;
V_101 = NULL ;
V_391 = F_297 ( V_11 , true ) ;
if ( V_391 < 0 )
goto V_397;
if ( V_11 -> V_101 -> V_102 != V_103 )
V_17 = true ;
V_11 -> V_16 . V_17 = V_17 ;
V_391 = F_298 ( V_11 ) ;
if ( V_391 ) {
F_304 ( V_11 ) ;
goto V_394;
}
return V_319 ;
V_397:
F_253 ( V_11 ) ;
V_396:
F_47 ( V_30 ) ;
V_395:
F_154 ( V_101 ) ;
V_394:
F_308 ( V_392 ) ;
F_18 ( L_115 , V_133 ) ;
return ( T_10 ) V_391 ;
}
static void V_357 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = F_232 ( V_6 ) ;
F_211 ( V_11 ) ;
F_126 ( V_289 , & V_11 -> V_21 ) ;
F_69 ( V_11 ) ;
F_302 ( V_11 -> V_307 , V_11 -> V_117 ) ;
V_11 -> V_307 = 0 ;
F_282 ( V_11 ) ;
F_69 ( V_11 ) ;
}
static void F_153 ( struct V_10 * V_11 )
{
while ( V_11 -> V_243 ) {
struct V_10 * V_398 = V_11 ;
struct V_10 * V_399 = V_398 -> V_243 ;
struct V_10 * V_400 ;
while ( V_399 && ( V_400 = V_399 -> V_243 ) ) {
V_398 = V_399 ;
V_399 = V_400 ;
}
F_15 ( V_399 ) ;
F_304 ( V_399 ) ;
V_398 -> V_243 = NULL ;
V_398 -> V_199 = 0 ;
F_15 ( V_398 -> V_234 ) ;
F_154 ( V_398 -> V_234 ) ;
V_398 -> V_234 = NULL ;
}
}
static T_10 F_309 ( struct V_390 * V_352 ,
const char * V_133 ,
T_5 V_319 )
{
struct V_10 * V_11 = NULL ;
struct V_361 * V_128 ;
int V_306 ;
unsigned long V_401 ;
bool V_402 = false ;
int V_31 ;
V_31 = F_310 ( V_133 , 10 , & V_401 ) ;
if ( V_31 )
return V_31 ;
V_306 = ( int ) V_401 ;
if ( V_306 != V_401 )
return - V_4 ;
V_31 = - V_23 ;
F_25 ( & V_359 ) ;
F_311 (tmp, &rbd_dev_list) {
V_11 = F_286 ( V_128 , struct V_10 , V_37 ) ;
if ( V_11 -> V_306 == V_306 ) {
V_31 = 0 ;
break;
}
}
if ( ! V_31 ) {
F_9 ( & V_11 -> V_19 ) ;
if ( V_11 -> V_22 )
V_31 = - V_403 ;
else
V_402 = F_99 ( V_20 ,
& V_11 -> V_21 ) ;
F_11 ( & V_11 -> V_19 ) ;
}
F_27 ( & V_359 ) ;
if ( V_31 < 0 || V_402 )
return V_31 ;
F_278 ( V_11 ) ;
V_31 = F_192 ( V_11 , false ) ;
if ( V_31 )
F_97 ( V_11 , L_116 , V_31 ) ;
F_304 ( V_11 ) ;
F_308 ( V_392 ) ;
return V_319 ;
}
static int F_312 ( void )
{
int V_31 ;
V_31 = F_277 ( & V_355 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_313 ( & V_353 ) ;
if ( V_31 < 0 )
F_279 ( & V_355 ) ;
return V_31 ;
}
static void F_314 ( void )
{
F_315 ( & V_353 ) ;
F_279 ( & V_355 ) ;
}
static int F_316 ( void )
{
F_15 ( ! V_236 ) ;
V_236 = F_317 ( L_117 ,
sizeof ( struct V_175 ) ,
F_318 ( struct V_175 ) ,
0 , NULL ) ;
if ( ! V_236 )
return - V_32 ;
F_15 ( ! V_232 ) ;
V_232 = F_317 ( L_118 ,
sizeof ( struct V_165 ) ,
F_318 ( struct V_165 ) ,
0 , NULL ) ;
if ( ! V_232 )
goto V_87;
F_15 ( ! V_120 ) ;
V_120 = F_317 ( L_119 ,
V_122 + 1 , 1 , 0 , NULL ) ;
if ( V_120 )
return 0 ;
V_87:
if ( V_232 ) {
F_319 ( V_232 ) ;
V_232 = NULL ;
}
F_319 ( V_236 ) ;
V_236 = NULL ;
return - V_32 ;
}
static void F_320 ( void )
{
F_15 ( V_120 ) ;
F_319 ( V_120 ) ;
V_120 = NULL ;
F_15 ( V_232 ) ;
F_319 ( V_232 ) ;
V_232 = NULL ;
F_15 ( V_236 ) ;
F_319 ( V_236 ) ;
V_236 = NULL ;
}
static int T_11 F_321 ( void )
{
int V_391 ;
if ( ! F_322 ( NULL ) ) {
F_97 ( NULL , L_120 ) ;
return - V_4 ;
}
V_391 = F_316 () ;
if ( V_391 )
return V_391 ;
V_391 = F_312 () ;
if ( V_391 )
F_320 () ;
else
F_261 ( L_121 V_404 L_122 ) ;
return V_391 ;
}
static void T_12 F_323 ( void )
{
F_314 () ;
F_320 () ;
}
