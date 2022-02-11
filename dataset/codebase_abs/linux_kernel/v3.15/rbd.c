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
static int F_7 ( int V_5 )
{
return V_5 << V_6 ;
}
static int F_8 ( int V_7 )
{
return V_7 >> V_6 ;
}
static T_2 F_9 ( struct V_8 * V_9 ,
struct V_10 * V_11 , int V_12 )
{
if ( ! V_13 &&
( V_11 == & V_14 . V_11 ||
V_11 == & V_15 . V_11 ) )
return 0 ;
return V_11 -> V_16 ;
}
static void F_10 ( struct V_17 * V_18 )
{
}
static int F_11 ( struct V_19 * V_20 , T_3 V_16 )
{
struct V_21 * V_22 = V_20 -> V_23 -> V_24 ;
bool V_25 = false ;
if ( ( V_16 & V_26 ) && V_22 -> V_27 . V_28 )
return - V_29 ;
F_12 ( & V_22 -> V_30 ) ;
if ( F_13 ( V_31 , & V_22 -> V_32 ) )
V_25 = true ;
else
V_22 -> V_33 ++ ;
F_14 ( & V_22 -> V_30 ) ;
if ( V_25 )
return - V_34 ;
( void ) F_15 ( & V_22 -> V_18 ) ;
F_16 ( V_20 , V_22 -> V_27 . V_28 ) ;
return 0 ;
}
static void F_17 ( struct V_35 * V_36 , T_3 V_16 )
{
struct V_21 * V_22 = V_36 -> V_24 ;
unsigned long V_37 ;
F_12 ( & V_22 -> V_30 ) ;
V_37 = V_22 -> V_33 -- ;
F_14 ( & V_22 -> V_30 ) ;
F_18 ( V_37 > 0 ) ;
F_19 ( & V_22 -> V_18 ) ;
}
static struct V_38 * F_20 ( struct V_39 * V_40 )
{
struct V_38 * V_41 ;
int V_42 = - V_43 ;
F_21 ( L_1 , V_44 ) ;
V_41 = F_22 ( sizeof( struct V_38 ) , V_45 ) ;
if ( ! V_41 )
goto V_46;
F_23 ( & V_41 -> V_47 ) ;
F_24 ( & V_41 -> V_48 ) ;
V_41 -> V_49 = F_25 ( V_40 , V_41 , 0 , 0 ) ;
if ( F_26 ( V_41 -> V_49 ) )
goto V_50;
V_40 = NULL ;
V_42 = F_27 ( V_41 -> V_49 ) ;
if ( V_42 < 0 )
goto V_51;
F_28 ( & V_52 ) ;
F_29 ( & V_41 -> V_48 , & V_53 ) ;
F_30 ( & V_52 ) ;
F_21 ( L_2 , V_44 , V_41 ) ;
return V_41 ;
V_51:
F_31 ( V_41 -> V_49 ) ;
V_50:
F_32 ( V_41 ) ;
V_46:
if ( V_40 )
F_33 ( V_40 ) ;
F_21 ( L_3 , V_44 , V_42 ) ;
return F_34 ( V_42 ) ;
}
static struct V_38 * F_35 ( struct V_38 * V_41 )
{
F_36 ( & V_41 -> V_47 ) ;
return V_41 ;
}
static struct V_38 * F_37 ( struct V_39 * V_40 )
{
struct V_38 * V_54 ;
bool V_55 = false ;
if ( V_40 -> V_32 & V_56 )
return NULL ;
F_28 ( & V_52 ) ;
F_38 (client_node, &rbd_client_list, node) {
if ( ! F_39 ( V_40 , V_54 -> V_49 ) ) {
F_35 ( V_54 ) ;
V_55 = true ;
break;
}
}
F_30 ( & V_52 ) ;
return V_55 ? V_54 : NULL ;
}
static int F_40 ( char * V_57 , void * V_58 )
{
struct V_59 * V_60 = V_58 ;
T_4 V_61 [ V_62 ] ;
int V_63 , V_64 , V_42 ;
V_63 = F_41 ( V_57 , V_65 , V_61 ) ;
if ( V_63 < 0 )
return - V_4 ;
if ( V_63 < V_66 ) {
V_42 = F_42 ( & V_61 [ 0 ] , & V_64 ) ;
if ( V_42 < 0 ) {
F_43 ( L_4
L_5 , V_57 ) ;
return V_42 ;
}
F_21 ( L_6 , V_63 , V_64 ) ;
} else if ( V_63 > V_66 && V_63 < V_67 ) {
F_21 ( L_7 , V_63 ,
V_61 [ 0 ] . V_68 ) ;
} else if ( V_63 > V_67 && V_63 < V_69 ) {
F_21 ( L_8 , V_63 ) ;
} else {
F_21 ( L_9 , V_63 ) ;
}
switch ( V_63 ) {
case V_70 :
V_60 -> V_28 = true ;
break;
case V_71 :
V_60 -> V_28 = false ;
break;
default:
F_18 ( false ) ;
break;
}
return 0 ;
}
static struct V_38 * F_44 ( struct V_39 * V_40 )
{
struct V_38 * V_41 ;
F_45 ( & V_72 , V_73 ) ;
V_41 = F_37 ( V_40 ) ;
if ( V_41 )
F_33 ( V_40 ) ;
else
V_41 = F_20 ( V_40 ) ;
F_46 ( & V_72 ) ;
return V_41 ;
}
static void F_47 ( struct V_47 * V_47 )
{
struct V_38 * V_41 = F_48 ( V_47 , struct V_38 , V_47 ) ;
F_21 ( L_2 , V_44 , V_41 ) ;
F_28 ( & V_52 ) ;
F_49 ( & V_41 -> V_48 ) ;
F_30 ( & V_52 ) ;
F_31 ( V_41 -> V_49 ) ;
F_32 ( V_41 ) ;
}
static void F_50 ( struct V_38 * V_41 )
{
if ( V_41 )
F_51 ( & V_41 -> V_47 , F_47 ) ;
}
static bool F_52 ( T_5 V_74 )
{
return V_74 == 1 || V_74 == 2 ;
}
static bool F_53 ( struct V_75 * V_76 )
{
T_6 V_77 ;
T_5 V_78 ;
if ( memcmp ( & V_76 -> V_79 , V_80 , sizeof ( V_80 ) ) )
return false ;
if ( V_76 -> V_81 . V_82 < V_83 )
return false ;
if ( V_76 -> V_81 . V_82 > 8 * sizeof ( int ) - 1 )
return false ;
V_78 = F_54 ( V_76 -> V_78 ) ;
V_77 = V_84 - sizeof ( struct V_85 ) ;
if ( V_78 > V_77 / sizeof ( V_86 ) )
return false ;
V_77 -= V_78 * sizeof ( V_86 ) ;
if ( ( V_87 ) V_77 < F_55 ( V_76 -> V_88 ) )
return false ;
return true ;
}
static int F_56 ( struct V_21 * V_22 ,
struct V_75 * V_76 )
{
struct V_89 * V_90 = & V_22 -> V_90 ;
bool V_91 = V_90 -> V_92 == NULL ;
struct V_85 * V_93 ;
char * V_92 = NULL ;
char * V_94 = NULL ;
V_87 * V_95 = NULL ;
T_5 V_78 ;
T_6 V_77 ;
int V_42 = - V_43 ;
T_5 V_96 ;
if ( V_91 ) {
T_6 V_97 ;
V_97 = F_57 ( V_76 -> V_92 ,
sizeof ( V_76 -> V_92 ) ) ;
V_92 = F_22 ( V_97 + 1 , V_45 ) ;
if ( ! V_92 )
return - V_43 ;
memcpy ( V_92 , V_76 -> V_92 , V_97 ) ;
V_92 [ V_97 ] = '\0' ;
}
V_78 = F_54 ( V_76 -> V_78 ) ;
V_93 = F_58 ( V_78 , V_45 ) ;
if ( ! V_93 )
goto V_98;
V_93 -> V_99 = F_55 ( V_76 -> V_100 ) ;
if ( V_78 ) {
struct V_101 * V_102 ;
V_87 V_88 = F_55 ( V_76 -> V_88 ) ;
if ( V_88 > ( V_87 ) V_84 )
goto V_103;
V_94 = F_22 ( V_88 , V_45 ) ;
if ( ! V_94 )
goto V_98;
V_77 = V_78 * sizeof ( * V_90 -> V_95 ) ;
V_95 = F_22 ( V_77 , V_45 ) ;
if ( ! V_95 )
goto V_98;
memcpy ( V_94 , & V_76 -> V_102 [ V_78 ] , V_88 ) ;
V_102 = V_76 -> V_102 ;
for ( V_96 = 0 ; V_96 < V_78 ; V_96 ++ ) {
V_93 -> V_102 [ V_96 ] = F_55 ( V_102 [ V_96 ] . V_104 ) ;
V_95 [ V_96 ] = F_55 ( V_102 [ V_96 ] . V_105 ) ;
}
}
if ( V_91 ) {
V_90 -> V_92 = V_92 ;
V_90 -> V_106 = V_76 -> V_81 . V_82 ;
V_90 -> V_107 = V_76 -> V_81 . V_107 ;
V_90 -> V_108 = V_76 -> V_81 . V_108 ;
V_90 -> V_109 = 0 ;
V_90 -> V_110 = 0 ;
V_90 -> V_111 = 0 ;
} else {
F_59 ( V_90 -> V_93 ) ;
F_32 ( V_90 -> V_94 ) ;
F_32 ( V_90 -> V_95 ) ;
}
V_90 -> V_105 = F_55 ( V_76 -> V_105 ) ;
V_90 -> V_93 = V_93 ;
V_90 -> V_94 = V_94 ;
V_90 -> V_95 = V_95 ;
if ( V_22 -> V_112 -> V_113 == V_114 || V_91 )
if ( V_22 -> V_27 . V_77 != V_90 -> V_105 )
V_22 -> V_27 . V_77 = V_90 -> V_105 ;
return 0 ;
V_103:
V_42 = - V_115 ;
V_98:
F_32 ( V_95 ) ;
F_32 ( V_94 ) ;
F_59 ( V_93 ) ;
F_32 ( V_92 ) ;
return V_42 ;
}
static const char * F_60 ( struct V_21 * V_22 , T_5 V_116 )
{
const char * V_117 ;
F_18 ( V_116 < V_22 -> V_90 . V_93 -> V_118 ) ;
V_117 = V_22 -> V_90 . V_94 ;
while ( V_116 -- )
V_117 += strlen ( V_117 ) + 1 ;
return F_61 ( V_117 , V_45 ) ;
}
static int F_62 ( const void * V_119 , const void * V_120 )
{
V_87 V_121 = * ( V_87 * ) V_119 ;
V_87 V_122 = * ( V_87 * ) V_120 ;
if ( V_121 < V_122 )
return 1 ;
return V_121 == V_122 ? 0 : - 1 ;
}
static T_5 F_63 ( struct V_21 * V_22 , V_87 V_113 )
{
struct V_85 * V_93 = V_22 -> V_90 . V_93 ;
V_87 * V_55 ;
V_55 = bsearch ( & V_113 , & V_93 -> V_102 , V_93 -> V_118 ,
sizeof ( V_113 ) , F_62 ) ;
return V_55 ? ( T_5 ) ( V_55 - & V_93 -> V_102 [ 0 ] ) : V_123 ;
}
static const char * F_64 ( struct V_21 * V_22 ,
V_87 V_113 )
{
T_5 V_116 ;
const char * V_117 ;
V_116 = F_63 ( V_22 , V_113 ) ;
if ( V_116 == V_123 )
return F_34 ( - V_34 ) ;
V_117 = F_60 ( V_22 , V_116 ) ;
return V_117 ? V_117 : F_34 ( - V_43 ) ;
}
static const char * F_65 ( struct V_21 * V_22 , V_87 V_113 )
{
if ( V_113 == V_114 )
return V_124 ;
F_18 ( F_52 ( V_22 -> V_74 ) ) ;
if ( V_22 -> V_74 == 1 )
return F_64 ( V_22 , V_113 ) ;
return F_66 ( V_22 , V_113 ) ;
}
static int F_67 ( struct V_21 * V_22 , V_87 V_113 ,
V_87 * V_125 )
{
F_18 ( F_52 ( V_22 -> V_74 ) ) ;
if ( V_113 == V_114 ) {
* V_125 = V_22 -> V_90 . V_105 ;
} else if ( V_22 -> V_74 == 1 ) {
T_5 V_116 ;
V_116 = F_63 ( V_22 , V_113 ) ;
if ( V_116 == V_123 )
return - V_34 ;
* V_125 = V_22 -> V_90 . V_95 [ V_116 ] ;
} else {
V_87 V_77 = 0 ;
int V_42 ;
V_42 = F_68 ( V_22 , V_113 , NULL , & V_77 ) ;
if ( V_42 )
return V_42 ;
* V_125 = V_77 ;
}
return 0 ;
}
static int F_69 ( struct V_21 * V_22 , V_87 V_113 ,
V_87 * V_126 )
{
F_18 ( F_52 ( V_22 -> V_74 ) ) ;
if ( V_113 == V_114 ) {
* V_126 = V_22 -> V_90 . V_111 ;
} else if ( V_22 -> V_74 == 1 ) {
* V_126 = 0 ;
} else {
V_87 V_111 = 0 ;
int V_42 ;
V_42 = F_70 ( V_22 , V_113 , & V_111 ) ;
if ( V_42 )
return V_42 ;
* V_126 = V_111 ;
}
return 0 ;
}
static int F_71 ( struct V_21 * V_22 )
{
V_87 V_113 = V_22 -> V_112 -> V_113 ;
V_87 V_77 = 0 ;
V_87 V_111 = 0 ;
int V_42 ;
V_42 = F_67 ( V_22 , V_113 , & V_77 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_69 ( V_22 , V_113 , & V_111 ) ;
if ( V_42 )
return V_42 ;
V_22 -> V_27 . V_77 = V_77 ;
V_22 -> V_27 . V_111 = V_111 ;
return 0 ;
}
static void F_72 ( struct V_21 * V_22 )
{
V_22 -> V_27 . V_77 = 0 ;
V_22 -> V_27 . V_111 = 0 ;
}
static const char * F_73 ( struct V_21 * V_22 , V_87 V_127 )
{
char * V_128 ;
V_87 V_129 ;
int V_42 ;
char * V_130 ;
V_128 = F_74 ( V_131 , V_132 ) ;
if ( ! V_128 )
return NULL ;
V_129 = V_127 >> V_22 -> V_90 . V_106 ;
V_130 = L_10 ;
if ( V_22 -> V_74 == 2 )
V_130 = L_11 ;
V_42 = snprintf ( V_128 , V_133 + 1 , V_130 ,
V_22 -> V_90 . V_92 , V_129 ) ;
if ( V_42 < 0 || V_42 > V_133 ) {
F_43 ( L_12 ,
V_129 , V_42 ) ;
F_32 ( V_128 ) ;
V_128 = NULL ;
}
return V_128 ;
}
static void F_75 ( const char * V_128 )
{
F_76 ( V_131 , ( void * ) V_128 ) ;
}
static V_87 F_77 ( struct V_21 * V_22 , V_87 V_127 )
{
V_87 V_134 = ( V_87 ) 1 << V_22 -> V_90 . V_106 ;
return V_127 & ( V_134 - 1 ) ;
}
static V_87 F_78 ( struct V_21 * V_22 ,
V_87 V_127 , V_87 V_135 )
{
V_87 V_134 = ( V_87 ) 1 << V_22 -> V_90 . V_106 ;
V_127 &= V_134 - 1 ;
F_18 ( V_135 <= V_136 - V_127 ) ;
if ( V_127 + V_135 > V_134 )
V_135 = V_134 - V_127 ;
return V_135 ;
}
static V_87 F_79 ( struct V_89 * V_90 )
{
return 1 << V_90 -> V_106 ;
}
static void F_80 ( struct V_137 * V_138 )
{
struct V_137 * V_139 ;
while ( V_138 ) {
V_139 = V_138 ;
V_138 = V_138 -> V_140 ;
F_81 ( V_139 ) ;
}
}
static void F_82 ( struct V_137 * V_138 , int V_141 )
{
struct V_142 V_143 ;
struct V_144 V_145 ;
unsigned long V_32 ;
void * V_146 ;
int V_147 = 0 ;
while ( V_138 ) {
F_83 (bv, chain, iter) {
if ( V_147 + V_143 . V_148 > V_141 ) {
int V_149 = F_84 ( V_141 - V_147 , 0 ) ;
V_146 = F_85 ( & V_143 , & V_32 ) ;
memset ( V_146 + V_149 , 0 ,
V_143 . V_148 - V_149 ) ;
F_86 ( V_143 . V_150 ) ;
F_87 ( V_146 , & V_32 ) ;
}
V_147 += V_143 . V_148 ;
}
V_138 = V_138 -> V_140 ;
}
}
static void F_88 ( struct V_151 * * V_152 , V_87 V_127 , V_87 V_153 )
{
struct V_151 * * V_151 = & V_152 [ V_127 >> V_154 ] ;
F_18 ( V_153 > V_127 ) ;
F_18 ( V_153 - V_127 <= ( V_87 ) V_84 ) ;
while ( V_127 < V_153 ) {
T_6 V_155 ;
T_6 V_135 ;
unsigned long V_32 ;
void * V_156 ;
V_155 = V_127 & ~ V_157 ;
V_135 = F_89 ( T_6 , V_158 - V_155 , V_153 - V_127 ) ;
F_90 ( V_32 ) ;
V_156 = F_91 ( * V_151 ) ;
memset ( V_156 + V_155 , 0 , V_135 ) ;
F_86 ( * V_151 ) ;
F_92 ( V_156 ) ;
F_93 ( V_32 ) ;
V_127 += V_135 ;
V_151 ++ ;
}
}
static struct V_137 * F_94 ( struct V_137 * V_159 ,
unsigned int V_127 ,
unsigned int V_97 ,
T_7 V_160 )
{
struct V_137 * V_137 ;
V_137 = F_95 ( V_159 , V_160 ) ;
if ( ! V_137 )
return NULL ;
F_96 ( V_137 , V_127 ) ;
V_137 -> V_161 . V_162 = V_97 ;
return V_137 ;
}
static struct V_137 * F_97 ( struct V_137 * * V_159 ,
unsigned int * V_127 ,
unsigned int V_97 ,
T_7 V_160 )
{
struct V_137 * V_163 = * V_159 ;
unsigned int V_164 = * V_127 ;
struct V_137 * V_138 = NULL ;
struct V_137 * * V_153 ;
if ( ! V_163 || V_164 >= V_163 -> V_161 . V_162 || ! V_97 )
return NULL ;
V_153 = & V_138 ;
while ( V_97 ) {
unsigned int V_162 ;
struct V_137 * V_137 ;
if ( ! V_163 ) {
F_98 ( NULL , L_13 , V_97 ) ;
goto V_98;
}
V_162 = F_89 (unsigned int, bi->bi_iter.bi_size - off, len) ;
V_137 = F_94 ( V_163 , V_164 , V_162 , V_160 ) ;
if ( ! V_137 )
goto V_98;
* V_153 = V_137 ;
V_153 = & V_137 -> V_140 ;
V_164 += V_162 ;
if ( V_164 == V_163 -> V_161 . V_162 ) {
V_163 = V_163 -> V_140 ;
V_164 = 0 ;
}
V_97 -= V_162 ;
}
* V_159 = V_163 ;
* V_127 = V_164 ;
return V_138 ;
V_98:
F_80 ( V_138 ) ;
return NULL ;
}
static void F_99 ( struct V_165 * V_166 )
{
if ( F_100 ( V_167 , & V_166 -> V_32 ) ) {
struct V_21 * V_22 ;
V_22 = V_166 -> V_168 -> V_22 ;
F_98 ( V_22 , L_14 ,
V_166 ) ;
}
}
static bool F_101 ( struct V_165 * V_166 )
{
F_102 () ;
return F_13 ( V_167 , & V_166 -> V_32 ) != 0 ;
}
static void F_103 ( struct V_165 * V_166 )
{
if ( F_100 ( V_169 , & V_166 -> V_32 ) ) {
struct V_21 * V_22 = NULL ;
if ( F_101 ( V_166 ) )
V_22 = V_166 -> V_168 -> V_22 ;
F_98 ( V_22 , L_15 ,
V_166 ) ;
}
}
static bool F_104 ( struct V_165 * V_166 )
{
F_102 () ;
return F_13 ( V_169 , & V_166 -> V_32 ) != 0 ;
}
static void F_105 ( struct V_165 * V_166 ,
bool V_170 )
{
if ( V_170 )
F_106 ( V_171 , & V_166 -> V_32 ) ;
F_106 ( V_172 , & V_166 -> V_32 ) ;
F_102 () ;
}
static bool F_107 ( struct V_165 * V_166 )
{
F_102 () ;
return F_13 ( V_172 , & V_166 -> V_32 ) != 0 ;
}
static bool F_108 ( struct V_165 * V_166 )
{
F_102 () ;
return F_13 ( V_171 , & V_166 -> V_32 ) != 0 ;
}
static void F_109 ( struct V_165 * V_166 )
{
F_21 ( L_16 , V_44 , V_166 ,
F_110 ( & V_166 -> V_47 . V_173 ) ) ;
F_36 ( & V_166 -> V_47 ) ;
}
static void F_111 ( struct V_165 * V_166 )
{
F_18 ( V_166 != NULL ) ;
F_21 ( L_16 , V_44 , V_166 ,
F_110 ( & V_166 -> V_47 . V_173 ) ) ;
F_51 ( & V_166 -> V_47 , V_174 ) ;
}
static void F_112 ( struct V_175 * V_168 )
{
F_18 ( V_168 != NULL ) ;
F_21 ( L_17 , V_44 , V_168 ,
F_110 ( & V_168 -> V_47 . V_173 ) ) ;
if ( F_113 ( V_168 ) )
F_51 ( & V_168 -> V_47 , V_176 ) ;
else
F_51 ( & V_168 -> V_47 , V_177 ) ;
}
static inline void F_114 ( struct V_175 * V_168 ,
struct V_165 * V_166 )
{
F_18 ( V_166 -> V_168 == NULL ) ;
V_166 -> V_168 = V_168 ;
V_166 -> V_116 = V_168 -> V_178 ;
F_18 ( ! F_101 ( V_166 ) ) ;
F_99 ( V_166 ) ;
F_18 ( V_166 -> V_116 != V_179 ) ;
V_168 -> V_178 ++ ;
F_29 ( & V_166 -> V_180 , & V_168 -> V_181 ) ;
F_21 ( L_18 , V_44 , V_168 , V_166 ,
V_166 -> V_116 ) ;
}
static inline void F_115 ( struct V_175 * V_168 ,
struct V_165 * V_166 )
{
F_18 ( V_166 -> V_116 != V_179 ) ;
F_21 ( L_18 , V_44 , V_168 , V_166 ,
V_166 -> V_116 ) ;
F_49 ( & V_166 -> V_180 ) ;
F_18 ( V_168 -> V_178 > 0 ) ;
V_168 -> V_178 -- ;
F_18 ( V_166 -> V_116 == V_168 -> V_178 ) ;
V_166 -> V_116 = V_179 ;
F_18 ( F_101 ( V_166 ) ) ;
F_18 ( V_166 -> V_168 == V_168 ) ;
V_166 -> V_168 = NULL ;
V_166 -> V_182 = NULL ;
F_111 ( V_166 ) ;
}
static bool F_116 ( enum V_183 type )
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
static int F_117 ( struct V_187 * V_188 ,
struct V_165 * V_166 )
{
F_21 ( L_19 , V_44 , V_188 , V_166 ) ;
return F_118 ( V_188 , V_166 -> V_189 , false ) ;
}
static void F_119 ( struct V_175 * V_168 )
{
F_21 ( L_20 , V_44 , V_168 ) ;
if ( ! V_168 -> V_190 ) {
struct V_165 * V_166 ;
V_87 V_191 = 0 ;
F_120 (img_request, obj_request)
V_191 += V_166 -> V_191 ;
V_168 -> V_191 = V_191 ;
}
if ( V_168 -> V_182 )
V_168 -> V_182 ( V_168 ) ;
else
F_112 ( V_168 ) ;
}
static int F_121 ( struct V_165 * V_166 )
{
F_21 ( L_21 , V_44 , V_166 ) ;
return F_122 ( & V_166 -> V_192 ) ;
}
static void F_123 ( struct V_175 * V_168 )
{
F_106 ( V_193 , & V_168 -> V_32 ) ;
F_102 () ;
}
static bool F_124 ( struct V_175 * V_168 )
{
F_102 () ;
return F_13 ( V_193 , & V_168 -> V_32 ) != 0 ;
}
static void F_125 ( struct V_175 * V_168 )
{
F_106 ( V_194 , & V_168 -> V_32 ) ;
F_102 () ;
}
static void F_126 ( struct V_175 * V_168 )
{
F_127 ( V_194 , & V_168 -> V_32 ) ;
F_102 () ;
}
static bool F_113 ( struct V_175 * V_168 )
{
F_102 () ;
return F_13 ( V_194 , & V_168 -> V_32 ) != 0 ;
}
static void F_128 ( struct V_175 * V_168 )
{
F_106 ( V_195 , & V_168 -> V_32 ) ;
F_102 () ;
}
static void F_129 ( struct V_175 * V_168 )
{
F_127 ( V_195 , & V_168 -> V_32 ) ;
F_102 () ;
}
static bool F_130 ( struct V_175 * V_168 )
{
F_102 () ;
return F_13 ( V_195 , & V_168 -> V_32 ) != 0 ;
}
static void
F_131 ( struct V_165 * V_166 )
{
V_87 V_191 = V_166 -> V_191 ;
V_87 V_135 = V_166 -> V_135 ;
F_21 ( L_22 , V_44 ,
V_166 , V_166 -> V_168 , V_166 -> V_190 ,
V_191 , V_135 ) ;
F_18 ( V_166 -> type != V_184 ) ;
if ( V_166 -> V_190 == - V_34 ) {
if ( V_166 -> type == V_185 )
F_82 ( V_166 -> V_196 , 0 ) ;
else
F_88 ( V_166 -> V_152 , 0 , V_135 ) ;
V_166 -> V_190 = 0 ;
} else if ( V_191 < V_135 && ! V_166 -> V_190 ) {
if ( V_166 -> type == V_185 )
F_82 ( V_166 -> V_196 , V_191 ) ;
else
F_88 ( V_166 -> V_152 , V_191 , V_135 ) ;
}
V_166 -> V_191 = V_135 ;
F_103 ( V_166 ) ;
}
static void F_132 ( struct V_165 * V_166 )
{
F_21 ( L_23 , V_44 , V_166 ,
V_166 -> V_182 ) ;
if ( V_166 -> V_182 )
V_166 -> V_182 ( V_166 ) ;
else
F_133 ( & V_166 -> V_192 ) ;
}
static void F_134 ( struct V_165 * V_166 )
{
F_21 ( L_21 , V_44 , V_166 ) ;
F_103 ( V_166 ) ;
}
static void F_135 ( struct V_165 * V_166 )
{
struct V_175 * V_168 = NULL ;
struct V_21 * V_22 = NULL ;
bool V_197 = false ;
if ( F_101 ( V_166 ) ) {
V_168 = V_166 -> V_168 ;
V_197 = V_168 && F_130 ( V_168 ) ;
V_22 = V_168 -> V_22 ;
}
F_21 ( L_22 , V_44 ,
V_166 , V_168 , V_166 -> V_190 ,
V_166 -> V_191 , V_166 -> V_135 ) ;
if ( V_197 && V_166 -> V_190 == - V_34 &&
V_166 -> V_198 < V_22 -> V_199 )
F_136 ( V_166 ) ;
else if ( V_168 )
F_131 ( V_166 ) ;
else
F_103 ( V_166 ) ;
}
static void F_137 ( struct V_165 * V_166 )
{
F_21 ( L_24 , V_44 , V_166 ,
V_166 -> V_190 , V_166 -> V_135 ) ;
V_166 -> V_191 = V_166 -> V_135 ;
F_103 ( V_166 ) ;
}
static void F_138 ( struct V_165 * V_166 )
{
F_21 ( L_21 , V_44 , V_166 ) ;
F_103 ( V_166 ) ;
}
static void F_139 ( struct V_200 * V_189 ,
struct V_201 * V_202 )
{
struct V_165 * V_166 = V_189 -> V_203 ;
T_8 V_204 ;
F_21 ( L_25 , V_44 , V_189 , V_202 ) ;
F_18 ( V_189 == V_166 -> V_189 ) ;
if ( F_101 ( V_166 ) ) {
F_18 ( V_166 -> V_168 ) ;
F_18 ( V_166 -> V_116 != V_179 ) ;
} else {
F_18 ( V_166 -> V_116 == V_179 ) ;
}
if ( V_189 -> V_205 < 0 )
V_166 -> V_190 = V_189 -> V_205 ;
F_18 ( V_189 -> V_206 <= V_207 ) ;
V_166 -> V_191 = V_189 -> V_208 [ 0 ] ;
F_18 ( V_166 -> V_191 < ( V_87 ) V_209 ) ;
V_204 = V_189 -> V_210 [ 0 ] . V_211 ;
switch ( V_204 ) {
case V_212 :
F_135 ( V_166 ) ;
break;
case V_213 :
F_18 ( V_189 -> V_210 [ 1 ] . V_211 == V_214 ) ;
case V_214 :
F_137 ( V_166 ) ;
break;
case V_215 :
F_138 ( V_166 ) ;
break;
case V_216 :
case V_217 :
case V_218 :
F_134 ( V_166 ) ;
break;
default:
F_98 ( NULL , L_26 ,
V_166 -> V_219 , ( unsigned short ) V_204 ) ;
break;
}
if ( F_104 ( V_166 ) )
F_132 ( V_166 ) ;
}
static void F_140 ( struct V_165 * V_166 )
{
struct V_175 * V_168 = V_166 -> V_168 ;
struct V_200 * V_189 = V_166 -> V_189 ;
V_87 V_113 ;
F_18 ( V_189 != NULL ) ;
V_113 = V_168 ? V_168 -> V_113 : V_114 ;
F_141 ( V_189 , V_166 -> V_127 ,
NULL , V_113 , NULL ) ;
}
static void F_142 ( struct V_165 * V_166 )
{
struct V_175 * V_168 = V_166 -> V_168 ;
struct V_200 * V_189 = V_166 -> V_189 ;
struct V_85 * V_93 ;
struct V_220 V_221 = V_222 ;
F_18 ( V_189 != NULL ) ;
V_93 = V_168 ? V_168 -> V_93 : NULL ;
F_141 ( V_189 , V_166 -> V_127 ,
V_93 , V_114 , & V_221 ) ;
}
static struct V_200 * F_143 (
struct V_21 * V_22 ,
bool V_223 ,
unsigned int V_224 ,
struct V_165 * V_166 )
{
struct V_85 * V_93 = NULL ;
struct V_187 * V_188 ;
struct V_200 * V_189 ;
if ( F_101 ( V_166 ) ) {
struct V_175 * V_168 = V_166 -> V_168 ;
F_18 ( V_223 ==
F_124 ( V_168 ) ) ;
if ( V_223 )
V_93 = V_168 -> V_93 ;
}
F_18 ( V_224 == 1 || ( V_223 && V_224 == 2 ) ) ;
V_188 = & V_22 -> V_38 -> V_49 -> V_188 ;
V_189 = F_144 ( V_188 , V_93 , V_224 , false ,
V_225 ) ;
if ( ! V_189 )
return NULL ;
if ( V_223 )
V_189 -> V_226 = V_227 | V_228 ;
else
V_189 -> V_226 = V_229 ;
V_189 -> V_230 = F_139 ;
V_189 -> V_203 = V_166 ;
V_189 -> V_231 . V_232 = F_145 ( V_22 -> V_233 ) ;
F_146 ( & V_189 -> V_234 , V_166 -> V_219 ) ;
return V_189 ;
}
static struct V_200 *
F_147 ( struct V_165 * V_166 )
{
struct V_175 * V_168 ;
struct V_85 * V_93 ;
struct V_21 * V_22 ;
struct V_187 * V_188 ;
struct V_200 * V_189 ;
F_18 ( F_101 ( V_166 ) ) ;
V_168 = V_166 -> V_168 ;
F_18 ( V_168 ) ;
F_18 ( F_124 ( V_168 ) ) ;
V_93 = V_168 -> V_93 ;
V_22 = V_168 -> V_22 ;
V_188 = & V_22 -> V_38 -> V_49 -> V_188 ;
V_189 = F_144 ( V_188 , V_93 , 3 , false , V_225 ) ;
if ( ! V_189 )
return NULL ;
V_189 -> V_226 = V_227 | V_228 ;
V_189 -> V_230 = F_139 ;
V_189 -> V_203 = V_166 ;
V_189 -> V_231 . V_232 = F_145 ( V_22 -> V_233 ) ;
F_146 ( & V_189 -> V_234 , V_166 -> V_219 ) ;
return V_189 ;
}
static void F_148 ( struct V_200 * V_189 )
{
F_149 ( V_189 ) ;
}
static struct V_165 * F_150 ( const char * V_219 ,
V_87 V_127 , V_87 V_135 ,
enum V_183 type )
{
struct V_165 * V_166 ;
T_6 V_77 ;
char * V_128 ;
F_18 ( F_116 ( type ) ) ;
V_77 = strlen ( V_219 ) + 1 ;
V_128 = F_22 ( V_77 , V_45 ) ;
if ( ! V_128 )
return NULL ;
V_166 = F_151 ( V_235 , V_45 ) ;
if ( ! V_166 ) {
F_32 ( V_128 ) ;
return NULL ;
}
V_166 -> V_219 = memcpy ( V_128 , V_219 , V_77 ) ;
V_166 -> V_127 = V_127 ;
V_166 -> V_135 = V_135 ;
V_166 -> V_32 = 0 ;
V_166 -> V_116 = V_179 ;
V_166 -> type = type ;
F_24 ( & V_166 -> V_180 ) ;
F_152 ( & V_166 -> V_192 ) ;
F_23 ( & V_166 -> V_47 ) ;
F_21 ( L_27 , V_44 , V_219 ,
V_127 , V_135 , ( int ) type , V_166 ) ;
return V_166 ;
}
static void V_174 ( struct V_47 * V_47 )
{
struct V_165 * V_166 ;
V_166 = F_48 ( V_47 , struct V_165 , V_47 ) ;
F_21 ( L_21 , V_44 , V_166 ) ;
F_18 ( V_166 -> V_168 == NULL ) ;
F_18 ( V_166 -> V_116 == V_179 ) ;
if ( V_166 -> V_189 )
F_148 ( V_166 -> V_189 ) ;
F_18 ( F_116 ( V_166 -> type ) ) ;
switch ( V_166 -> type ) {
case V_184 :
break;
case V_185 :
if ( V_166 -> V_196 )
F_80 ( V_166 -> V_196 ) ;
break;
case V_186 :
if ( V_166 -> V_152 )
F_153 ( V_166 -> V_152 ,
V_166 -> V_236 ) ;
break;
}
F_32 ( V_166 -> V_219 ) ;
V_166 -> V_219 = NULL ;
F_76 ( V_235 , V_166 ) ;
}
static void F_154 ( struct V_21 * V_22 )
{
F_155 ( V_22 ) ;
F_156 ( V_22 -> V_237 ) ;
V_22 -> V_237 = NULL ;
V_22 -> V_199 = 0 ;
}
static void F_157 ( struct V_21 * V_22 )
{
int V_2 ;
if ( ! V_22 -> V_237 )
return;
V_2 = F_4 ( & V_22 -> V_238 ) ;
if ( V_2 > 0 )
return;
if ( ! V_2 )
F_154 ( V_22 ) ;
else
F_98 ( V_22 , L_28 ) ;
}
static bool F_158 ( struct V_21 * V_22 )
{
int V_2 ;
if ( ! V_22 -> V_237 )
return false ;
V_2 = F_1 ( & V_22 -> V_238 ) ;
if ( V_2 > 0 && V_22 -> V_199 )
return true ;
if ( V_2 < 0 )
F_98 ( V_22 , L_29 ) ;
return false ;
}
static struct V_175 * F_159 (
struct V_21 * V_22 ,
V_87 V_127 , V_87 V_135 ,
bool V_223 )
{
struct V_175 * V_168 ;
V_168 = F_74 ( V_239 , V_225 ) ;
if ( ! V_168 )
return NULL ;
if ( V_223 ) {
F_160 ( & V_22 -> V_240 ) ;
F_161 ( V_22 -> V_90 . V_93 ) ;
F_162 ( & V_22 -> V_240 ) ;
}
V_168 -> V_241 = NULL ;
V_168 -> V_22 = V_22 ;
V_168 -> V_127 = V_127 ;
V_168 -> V_135 = V_135 ;
V_168 -> V_32 = 0 ;
if ( V_223 ) {
F_123 ( V_168 ) ;
V_168 -> V_93 = V_22 -> V_90 . V_93 ;
} else {
V_168 -> V_113 = V_22 -> V_112 -> V_113 ;
}
if ( F_158 ( V_22 ) )
F_128 ( V_168 ) ;
F_163 ( & V_168 -> V_242 ) ;
V_168 -> V_243 = 0 ;
V_168 -> V_182 = NULL ;
V_168 -> V_190 = 0 ;
V_168 -> V_178 = 0 ;
F_24 ( & V_168 -> V_181 ) ;
F_23 ( & V_168 -> V_47 ) ;
F_21 ( L_30 , V_44 , V_22 ,
V_223 ? L_31 : L_32 , V_127 , V_135 ,
V_168 ) ;
return V_168 ;
}
static void V_177 ( struct V_47 * V_47 )
{
struct V_175 * V_168 ;
struct V_165 * V_166 ;
struct V_165 * V_244 ;
V_168 = F_48 ( V_47 , struct V_175 , V_47 ) ;
F_21 ( L_20 , V_44 , V_168 ) ;
F_164 (img_request, obj_request, next_obj_request)
F_115 ( V_168 , V_166 ) ;
F_18 ( V_168 -> V_178 == 0 ) ;
if ( F_130 ( V_168 ) ) {
F_129 ( V_168 ) ;
F_157 ( V_168 -> V_22 ) ;
}
if ( F_124 ( V_168 ) )
F_59 ( V_168 -> V_93 ) ;
F_76 ( V_239 , V_168 ) ;
}
static struct V_175 * F_165 (
struct V_165 * V_166 ,
V_87 V_198 , V_87 V_135 )
{
struct V_175 * V_245 ;
struct V_21 * V_22 ;
F_18 ( V_166 -> V_168 ) ;
V_22 = V_166 -> V_168 -> V_22 ;
V_245 = F_159 ( V_22 -> V_246 ,
V_198 , V_135 , false ) ;
if ( ! V_245 )
return NULL ;
F_125 ( V_245 ) ;
F_109 ( V_166 ) ;
V_245 -> V_166 = V_166 ;
return V_245 ;
}
static void V_176 ( struct V_47 * V_47 )
{
struct V_175 * V_245 ;
struct V_165 * V_247 ;
V_245 = F_48 ( V_47 , struct V_175 , V_47 ) ;
V_247 = V_245 -> V_166 ;
V_245 -> V_166 = NULL ;
F_111 ( V_247 ) ;
F_126 ( V_245 ) ;
V_177 ( V_47 ) ;
}
static bool F_166 ( struct V_165 * V_166 )
{
struct V_175 * V_168 ;
unsigned int V_191 ;
int V_190 ;
bool V_248 ;
F_18 ( F_101 ( V_166 ) ) ;
V_168 = V_166 -> V_168 ;
F_18 ( V_166 -> V_191 <= ( V_87 ) V_209 ) ;
V_191 = ( unsigned int ) V_166 -> V_191 ;
V_190 = V_166 -> V_190 ;
if ( V_190 ) {
struct V_21 * V_22 = V_168 -> V_22 ;
F_98 ( V_22 , L_33 ,
F_124 ( V_168 ) ? L_31 : L_32 ,
V_166 -> V_135 , V_166 -> V_198 ,
V_166 -> V_127 ) ;
F_98 ( V_22 , L_34 ,
V_190 , V_191 ) ;
if ( ! V_168 -> V_190 )
V_168 -> V_190 = V_190 ;
}
if ( V_166 -> type == V_186 ) {
V_166 -> V_152 = NULL ;
V_166 -> V_236 = 0 ;
}
if ( F_113 ( V_168 ) ) {
F_18 ( V_168 -> V_166 != NULL ) ;
V_248 = V_166 -> V_116 < V_168 -> V_178 - 1 ;
} else {
F_18 ( V_168 -> V_241 != NULL ) ;
V_248 = F_167 ( V_168 -> V_241 , V_190 , V_191 ) ;
}
return V_248 ;
}
static void F_168 ( struct V_165 * V_166 )
{
struct V_175 * V_168 ;
T_5 V_116 = V_166 -> V_116 ;
bool V_248 = true ;
F_18 ( F_101 ( V_166 ) ) ;
V_168 = V_166 -> V_168 ;
F_21 ( L_35 , V_44 , V_168 , V_166 ) ;
F_18 ( V_168 != NULL ) ;
F_18 ( V_168 -> V_178 > 0 ) ;
F_18 ( V_116 != V_179 ) ;
F_18 ( V_116 < V_168 -> V_178 ) ;
F_12 ( & V_168 -> V_242 ) ;
if ( V_116 != V_168 -> V_243 )
goto V_249;
F_169 (img_request, obj_request) {
F_18 ( V_248 ) ;
F_18 ( V_116 < V_168 -> V_178 ) ;
if ( ! F_104 ( V_166 ) )
break;
V_248 = F_166 ( V_166 ) ;
V_116 ++ ;
}
F_18 ( V_248 ^ ( V_116 == V_168 -> V_178 ) ) ;
V_168 -> V_243 = V_116 ;
V_249:
F_14 ( & V_168 -> V_242 ) ;
if ( ! V_248 )
F_119 ( V_168 ) ;
}
static int F_170 ( struct V_175 * V_168 ,
enum V_183 type ,
void * V_250 )
{
struct V_21 * V_22 = V_168 -> V_22 ;
struct V_165 * V_166 = NULL ;
struct V_165 * V_244 ;
bool V_223 = F_124 ( V_168 ) ;
struct V_137 * V_196 = NULL ;
unsigned int V_251 = 0 ;
struct V_151 * * V_152 = NULL ;
V_87 V_198 ;
V_87 V_252 ;
T_8 V_204 ;
F_21 ( L_36 , V_44 , V_168 ,
( int ) type , V_250 ) ;
V_204 = V_223 ? V_214 : V_212 ;
V_198 = V_168 -> V_127 ;
V_252 = V_168 -> V_135 ;
F_18 ( V_252 > 0 ) ;
if ( type == V_185 ) {
V_196 = V_250 ;
F_18 ( V_198 ==
V_196 -> V_161 . V_253 << V_83 ) ;
} else {
F_18 ( type == V_186 ) ;
V_152 = V_250 ;
}
while ( V_252 ) {
struct V_200 * V_189 ;
const char * V_219 ;
V_87 V_127 ;
V_87 V_135 ;
unsigned int V_116 = 0 ;
V_219 = F_73 ( V_22 , V_198 ) ;
if ( ! V_219 )
goto V_254;
V_127 = F_77 ( V_22 , V_198 ) ;
V_135 = F_78 ( V_22 , V_198 , V_252 ) ;
V_166 = F_150 ( V_219 ,
V_127 , V_135 , type ) ;
F_75 ( V_219 ) ;
if ( ! V_166 )
goto V_254;
F_114 ( V_168 , V_166 ) ;
if ( type == V_185 ) {
unsigned int V_255 ;
F_18 ( V_135 <= ( V_87 ) V_209 ) ;
V_255 = ( unsigned int ) V_135 ;
V_166 -> V_196 =
F_97 ( & V_196 ,
& V_251 ,
V_255 ,
V_225 ) ;
if ( ! V_166 -> V_196 )
goto V_254;
} else {
unsigned int V_236 ;
V_166 -> V_152 = V_152 ;
V_236 = ( T_5 ) F_171 ( V_127 , V_135 ) ;
V_166 -> V_236 = V_236 ;
if ( ( V_127 + V_135 ) & ~ V_157 )
V_236 -- ;
V_152 += V_236 ;
}
V_189 = F_143 ( V_22 , V_223 ,
( V_223 ? 2 : 1 ) ,
V_166 ) ;
if ( ! V_189 )
goto V_254;
V_166 -> V_189 = V_189 ;
V_166 -> V_182 = F_168 ;
if ( V_223 ) {
F_172 ( V_189 , V_116 ,
F_79 ( & V_22 -> V_90 ) ,
F_79 ( & V_22 -> V_90 ) ) ;
V_116 ++ ;
}
F_173 ( V_189 , V_116 , V_204 , V_127 , V_135 ,
0 , 0 ) ;
if ( type == V_185 )
F_174 ( V_189 , V_116 ,
V_166 -> V_196 , V_135 ) ;
else
F_175 ( V_189 , V_116 ,
V_166 -> V_152 , V_135 ,
V_127 & ~ V_157 , false , false ) ;
if ( V_223 )
F_142 ( V_166 ) ;
else
F_140 ( V_166 ) ;
V_166 -> V_198 = V_198 ;
V_198 += V_135 ;
V_252 -= V_135 ;
}
return 0 ;
V_254:
F_164 (img_request, obj_request, next_obj_request)
F_115 ( V_168 , V_166 ) ;
return - V_43 ;
}
static void
F_176 ( struct V_165 * V_166 )
{
struct V_175 * V_168 ;
struct V_21 * V_22 ;
struct V_151 * * V_152 ;
T_5 V_236 ;
F_18 ( V_166 -> type == V_185 ) ;
F_18 ( F_101 ( V_166 ) ) ;
V_168 = V_166 -> V_168 ;
F_18 ( V_168 ) ;
V_22 = V_168 -> V_22 ;
F_18 ( V_22 ) ;
V_152 = V_166 -> V_256 ;
F_18 ( V_152 != NULL ) ;
V_166 -> V_256 = NULL ;
V_236 = V_166 -> V_257 ;
F_18 ( V_236 ) ;
V_166 -> V_257 = 0 ;
F_153 ( V_152 , V_236 ) ;
if ( ! V_166 -> V_190 )
V_166 -> V_191 = V_166 -> V_135 ;
F_168 ( V_166 ) ;
}
static void
F_177 ( struct V_175 * V_168 )
{
struct V_165 * V_247 ;
struct V_200 * V_189 ;
struct V_187 * V_188 ;
struct V_21 * V_22 ;
struct V_151 * * V_152 ;
T_5 V_236 ;
int V_258 ;
V_87 V_259 ;
V_87 V_127 ;
V_87 V_135 ;
F_18 ( F_113 ( V_168 ) ) ;
V_152 = V_168 -> V_256 ;
F_18 ( V_152 != NULL ) ;
V_168 -> V_256 = NULL ;
V_236 = V_168 -> V_257 ;
F_18 ( V_236 ) ;
V_168 -> V_257 = 0 ;
V_247 = V_168 -> V_166 ;
F_18 ( V_247 != NULL ) ;
F_18 ( F_116 ( V_247 -> type ) ) ;
V_258 = V_168 -> V_190 ;
V_259 = V_168 -> V_135 ;
F_18 ( V_259 == V_168 -> V_191 ) ;
F_112 ( V_168 ) ;
F_18 ( V_247 -> V_168 ) ;
V_22 = V_247 -> V_168 -> V_22 ;
F_18 ( V_22 ) ;
if ( ! V_22 -> V_199 ) {
struct V_187 * V_188 ;
F_153 ( V_152 , V_236 ) ;
V_188 = & V_22 -> V_38 -> V_49 -> V_188 ;
V_258 = F_117 ( V_188 , V_247 ) ;
if ( ! V_258 )
return;
}
if ( V_258 )
goto V_98;
V_258 = - V_43 ;
V_189 = F_147 ( V_247 ) ;
if ( ! V_189 )
goto V_98;
F_148 ( V_247 -> V_189 ) ;
V_247 -> V_189 = V_189 ;
V_247 -> V_256 = V_152 ;
V_247 -> V_257 = V_236 ;
F_178 ( V_189 , 0 , V_216 , L_37 , L_38 ) ;
F_179 ( V_189 , 0 , V_152 , V_259 , 0 ,
false , false ) ;
F_172 ( V_189 , 1 , F_79 ( & V_22 -> V_90 ) ,
F_79 ( & V_22 -> V_90 ) ) ;
V_127 = V_247 -> V_127 ;
V_135 = V_247 -> V_135 ;
F_173 ( V_189 , 2 , V_214 ,
V_127 , V_135 , 0 , 0 ) ;
if ( V_247 -> type == V_185 )
F_174 ( V_189 , 2 ,
V_247 -> V_196 , V_135 ) ;
else
F_175 ( V_189 , 2 ,
V_247 -> V_152 , V_135 ,
V_127 & ~ V_157 , false , false ) ;
F_142 ( V_247 ) ;
V_247 -> V_182 = F_176 ;
V_188 = & V_22 -> V_38 -> V_49 -> V_188 ;
V_258 = F_117 ( V_188 , V_247 ) ;
if ( ! V_258 )
return;
V_98:
V_247 -> V_190 = V_258 ;
V_247 -> V_191 = 0 ;
F_103 ( V_247 ) ;
F_132 ( V_247 ) ;
}
static int F_180 ( struct V_165 * V_166 )
{
struct V_175 * V_168 = NULL ;
struct V_175 * V_245 = NULL ;
struct V_21 * V_22 ;
V_87 V_198 ;
V_87 V_135 ;
struct V_151 * * V_152 = NULL ;
T_5 V_236 ;
int V_190 ;
F_18 ( F_101 ( V_166 ) ) ;
F_18 ( F_116 ( V_166 -> type ) ) ;
V_168 = V_166 -> V_168 ;
F_18 ( V_168 != NULL ) ;
V_22 = V_168 -> V_22 ;
F_18 ( V_22 -> V_246 != NULL ) ;
V_198 = V_166 -> V_198 - V_166 -> V_127 ;
V_135 = ( V_87 ) 1 << V_22 -> V_90 . V_106 ;
if ( V_198 + V_135 > V_22 -> V_199 ) {
F_18 ( V_198 < V_22 -> V_199 ) ;
V_135 = V_22 -> V_199 - V_198 ;
}
V_236 = ( T_5 ) F_171 ( 0 , V_135 ) ;
V_152 = F_181 ( V_236 , V_45 ) ;
if ( F_26 ( V_152 ) ) {
V_190 = F_182 ( V_152 ) ;
V_152 = NULL ;
goto V_98;
}
V_190 = - V_43 ;
V_245 = F_165 ( V_166 ,
V_198 , V_135 ) ;
if ( ! V_245 )
goto V_98;
V_190 = F_170 ( V_245 , V_186 , V_152 ) ;
if ( V_190 )
goto V_98;
V_245 -> V_256 = V_152 ;
V_245 -> V_257 = V_236 ;
V_245 -> V_182 = F_177 ;
V_190 = F_183 ( V_245 ) ;
if ( ! V_190 )
return 0 ;
V_245 -> V_256 = NULL ;
V_245 -> V_257 = 0 ;
V_245 -> V_166 = NULL ;
F_111 ( V_166 ) ;
V_98:
if ( V_152 )
F_153 ( V_152 , V_236 ) ;
if ( V_245 )
F_112 ( V_245 ) ;
V_166 -> V_190 = V_190 ;
V_166 -> V_191 = 0 ;
F_103 ( V_166 ) ;
return V_190 ;
}
static void F_184 ( struct V_165 * V_166 )
{
struct V_165 * V_247 ;
struct V_21 * V_22 ;
int V_190 ;
F_18 ( ! F_101 ( V_166 ) ) ;
V_247 = V_166 -> V_166 ;
V_166 -> V_166 = NULL ;
F_111 ( V_247 ) ;
F_18 ( V_247 ) ;
F_18 ( V_247 -> V_168 ) ;
V_190 = V_166 -> V_190 ;
V_166 -> V_190 = 0 ;
F_21 ( L_39 , V_44 ,
V_166 , V_247 , V_190 ,
V_166 -> V_191 , V_166 -> V_135 ) ;
F_111 ( V_166 ) ;
V_22 = V_247 -> V_168 -> V_22 ;
if ( ! V_22 -> V_199 ) {
struct V_187 * V_188 ;
V_188 = & V_22 -> V_38 -> V_49 -> V_188 ;
V_190 = F_117 ( V_188 , V_247 ) ;
if ( ! V_190 )
return;
}
if ( ! V_190 ) {
F_105 ( V_247 , true ) ;
} else if ( V_190 == - V_34 ) {
F_105 ( V_247 , false ) ;
} else if ( V_190 ) {
V_247 -> V_190 = V_190 ;
goto V_249;
}
V_247 -> V_190 = F_185 ( V_247 ) ;
V_249:
if ( V_247 -> V_190 )
F_132 ( V_247 ) ;
}
static int F_186 ( struct V_165 * V_166 )
{
struct V_165 * V_260 ;
struct V_21 * V_22 ;
struct V_187 * V_188 ;
struct V_151 * * V_152 = NULL ;
T_5 V_236 ;
T_6 V_77 ;
int V_42 ;
V_77 = sizeof ( V_86 ) + sizeof ( V_261 ) + sizeof ( V_261 ) ;
V_236 = ( T_5 ) F_171 ( 0 , V_77 ) ;
V_152 = F_181 ( V_236 , V_45 ) ;
if ( F_26 ( V_152 ) )
return F_182 ( V_152 ) ;
V_42 = - V_43 ;
V_260 = F_150 ( V_166 -> V_219 , 0 , 0 ,
V_186 ) ;
if ( ! V_260 )
goto V_249;
F_109 ( V_166 ) ;
V_260 -> V_166 = V_166 ;
V_260 -> V_152 = V_152 ;
V_260 -> V_236 = V_236 ;
F_18 ( V_166 -> V_168 ) ;
V_22 = V_166 -> V_168 -> V_22 ;
V_260 -> V_189 = F_143 ( V_22 , false , 1 ,
V_260 ) ;
if ( ! V_260 -> V_189 )
goto V_249;
V_260 -> V_182 = F_184 ;
F_187 ( V_260 -> V_189 , 0 , V_215 ) ;
F_188 ( V_260 -> V_189 , 0 , V_152 , V_77 , 0 ,
false , false ) ;
F_140 ( V_260 ) ;
V_188 = & V_22 -> V_38 -> V_49 -> V_188 ;
V_42 = F_117 ( V_188 , V_260 ) ;
V_249:
if ( V_42 )
F_111 ( V_166 ) ;
return V_42 ;
}
static int F_185 ( struct V_165 * V_166 )
{
struct V_175 * V_168 ;
struct V_21 * V_22 ;
bool V_262 ;
F_18 ( F_101 ( V_166 ) ) ;
V_168 = V_166 -> V_168 ;
F_18 ( V_168 ) ;
V_22 = V_168 -> V_22 ;
if ( ! F_124 ( V_168 ) ||
! F_130 ( V_168 ) ||
V_22 -> V_199 <= V_166 -> V_198 ||
( ( V_262 = F_107 ( V_166 ) ) &&
F_108 ( V_166 ) ) ) {
struct V_21 * V_22 ;
struct V_187 * V_188 ;
V_22 = V_166 -> V_168 -> V_22 ;
V_188 = & V_22 -> V_38 -> V_49 -> V_188 ;
return F_117 ( V_188 , V_166 ) ;
}
if ( V_262 )
return F_180 ( V_166 ) ;
return F_186 ( V_166 ) ;
}
static int F_183 ( struct V_175 * V_168 )
{
struct V_165 * V_166 ;
struct V_165 * V_244 ;
F_21 ( L_20 , V_44 , V_168 ) ;
F_164 (img_request, obj_request, next_obj_request) {
int V_42 ;
V_42 = F_185 ( V_166 ) ;
if ( V_42 )
return V_42 ;
}
return 0 ;
}
static void F_189 ( struct V_175 * V_168 )
{
struct V_165 * V_166 ;
struct V_21 * V_22 ;
V_87 V_263 ;
V_87 V_264 ;
int V_258 ;
F_18 ( F_113 ( V_168 ) ) ;
V_166 = V_168 -> V_166 ;
V_264 = V_168 -> V_191 ;
V_258 = V_168 -> V_190 ;
F_112 ( V_168 ) ;
F_18 ( V_166 ) ;
F_18 ( V_166 -> V_168 ) ;
V_22 = V_166 -> V_168 -> V_22 ;
if ( ! V_22 -> V_199 ) {
struct V_187 * V_188 ;
V_188 = & V_22 -> V_38 -> V_49 -> V_188 ;
V_258 = F_117 ( V_188 , V_166 ) ;
if ( ! V_258 )
return;
}
V_166 -> V_190 = V_258 ;
if ( V_166 -> V_190 )
goto V_249;
F_18 ( V_166 -> V_198 < V_136 - V_166 -> V_135 ) ;
V_263 = V_166 -> V_198 + V_166 -> V_135 ;
if ( V_263 > V_22 -> V_199 ) {
V_87 V_191 = 0 ;
if ( V_166 -> V_198 < V_22 -> V_199 )
V_191 = V_22 -> V_199 -
V_166 -> V_198 ;
V_166 -> V_191 = F_190 ( V_264 , V_191 ) ;
} else {
V_166 -> V_191 = V_264 ;
}
V_249:
F_131 ( V_166 ) ;
F_132 ( V_166 ) ;
}
static void F_136 ( struct V_165 * V_166 )
{
struct V_175 * V_168 ;
int V_190 ;
F_18 ( F_101 ( V_166 ) ) ;
F_18 ( V_166 -> V_168 != NULL ) ;
F_18 ( V_166 -> V_190 == ( V_265 ) - V_34 ) ;
F_18 ( F_116 ( V_166 -> type ) ) ;
V_168 = F_165 ( V_166 ,
V_166 -> V_198 ,
V_166 -> V_135 ) ;
V_190 = - V_43 ;
if ( ! V_168 )
goto V_98;
if ( V_166 -> type == V_185 )
V_190 = F_170 ( V_168 , V_185 ,
V_166 -> V_196 ) ;
else
V_190 = F_170 ( V_168 , V_186 ,
V_166 -> V_152 ) ;
if ( V_190 )
goto V_98;
V_168 -> V_182 = F_189 ;
V_190 = F_183 ( V_168 ) ;
if ( V_190 )
goto V_98;
return;
V_98:
if ( V_168 )
F_112 ( V_168 ) ;
V_166 -> V_190 = V_190 ;
V_166 -> V_191 = 0 ;
F_103 ( V_166 ) ;
}
static int F_191 ( struct V_21 * V_22 , V_87 V_266 )
{
struct V_165 * V_166 ;
struct V_187 * V_188 = & V_22 -> V_38 -> V_49 -> V_188 ;
int V_42 ;
V_166 = F_150 ( V_22 -> V_267 , 0 , 0 ,
V_184 ) ;
if ( ! V_166 )
return - V_43 ;
V_42 = - V_43 ;
V_166 -> V_189 = F_143 ( V_22 , false , 1 ,
V_166 ) ;
if ( ! V_166 -> V_189 )
goto V_249;
F_192 ( V_166 -> V_189 , 0 , V_217 ,
V_266 , 0 , 0 ) ;
F_140 ( V_166 ) ;
V_42 = F_117 ( V_188 , V_166 ) ;
if ( V_42 )
goto V_249;
V_42 = F_121 ( V_166 ) ;
V_249:
F_111 ( V_166 ) ;
return V_42 ;
}
static void F_193 ( V_87 V_268 , V_87 V_266 , T_9 V_204 , void * V_269 )
{
struct V_21 * V_22 = (struct V_21 * ) V_269 ;
int V_42 ;
if ( ! V_22 )
return;
F_21 ( L_40 , V_44 ,
V_22 -> V_267 , ( unsigned long long ) V_266 ,
( unsigned int ) V_204 ) ;
V_42 = F_194 ( V_22 ) ;
if ( V_42 )
F_98 ( V_22 , L_41 , V_42 ) ;
F_191 ( V_22 , V_266 ) ;
}
static int F_195 ( struct V_21 * V_22 , bool V_270 )
{
struct V_187 * V_188 = & V_22 -> V_38 -> V_49 -> V_188 ;
struct V_165 * V_166 ;
int V_42 ;
F_18 ( V_270 ^ ! ! V_22 -> V_271 ) ;
F_18 ( V_270 ^ ! ! V_22 -> V_272 ) ;
if ( V_270 ) {
V_42 = F_196 ( V_188 , F_193 , V_22 ,
& V_22 -> V_271 ) ;
if ( V_42 < 0 )
return V_42 ;
F_18 ( V_22 -> V_271 != NULL ) ;
}
V_42 = - V_43 ;
V_166 = F_150 ( V_22 -> V_267 , 0 , 0 ,
V_184 ) ;
if ( ! V_166 )
goto V_273;
V_166 -> V_189 = F_143 ( V_22 , true , 1 ,
V_166 ) ;
if ( ! V_166 -> V_189 )
goto V_273;
if ( V_270 )
F_197 ( V_188 , V_166 -> V_189 ) ;
else
F_198 ( V_188 ,
V_22 -> V_272 -> V_189 ) ;
F_192 ( V_166 -> V_189 , 0 , V_218 ,
V_22 -> V_271 -> V_274 , 0 , V_270 ? 1 : 0 ) ;
F_142 ( V_166 ) ;
V_42 = F_117 ( V_188 , V_166 ) ;
if ( V_42 )
goto V_273;
V_42 = F_121 ( V_166 ) ;
if ( V_42 )
goto V_273;
V_42 = V_166 -> V_190 ;
if ( V_42 )
goto V_273;
if ( V_270 ) {
V_22 -> V_272 = V_166 ;
return 0 ;
}
F_111 ( V_22 -> V_272 ) ;
V_22 -> V_272 = NULL ;
V_273:
F_199 ( V_22 -> V_271 ) ;
V_22 -> V_271 = NULL ;
if ( V_166 )
F_111 ( V_166 ) ;
return V_42 ;
}
static int F_200 ( struct V_21 * V_22 )
{
return F_195 ( V_22 , true ) ;
}
static void F_201 ( struct V_21 * V_22 )
{
int V_42 ;
V_42 = F_195 ( V_22 , false ) ;
if ( V_42 ) {
F_98 ( V_22 , L_42 ,
V_42 ) ;
}
}
static int F_202 ( struct V_21 * V_22 ,
const char * V_219 ,
const char * V_275 ,
const char * V_276 ,
const void * V_277 ,
T_6 V_278 ,
void * V_279 ,
T_6 V_280 )
{
struct V_187 * V_188 = & V_22 -> V_38 -> V_49 -> V_188 ;
struct V_165 * V_166 ;
struct V_151 * * V_152 ;
T_5 V_236 ;
int V_42 ;
V_236 = ( T_5 ) F_171 ( 0 , V_280 ) ;
V_152 = F_181 ( V_236 , V_45 ) ;
if ( F_26 ( V_152 ) )
return F_182 ( V_152 ) ;
V_42 = - V_43 ;
V_166 = F_150 ( V_219 , 0 , V_280 ,
V_186 ) ;
if ( ! V_166 )
goto V_249;
V_166 -> V_152 = V_152 ;
V_166 -> V_236 = V_236 ;
V_166 -> V_189 = F_143 ( V_22 , false , 1 ,
V_166 ) ;
if ( ! V_166 -> V_189 )
goto V_249;
F_178 ( V_166 -> V_189 , 0 , V_216 ,
V_275 , V_276 ) ;
if ( V_278 ) {
struct V_281 * V_282 ;
V_282 = F_22 ( sizeof ( * V_282 ) , V_283 ) ;
if ( ! V_282 )
goto V_249;
F_203 ( V_282 ) ;
F_204 ( V_282 , V_277 , V_278 ) ;
F_205 ( V_166 -> V_189 , 0 ,
V_282 ) ;
}
F_206 ( V_166 -> V_189 , 0 ,
V_166 -> V_152 , V_280 ,
0 , false , false ) ;
F_140 ( V_166 ) ;
V_42 = F_117 ( V_188 , V_166 ) ;
if ( V_42 )
goto V_249;
V_42 = F_121 ( V_166 ) ;
if ( V_42 )
goto V_249;
V_42 = V_166 -> V_190 ;
if ( V_42 < 0 )
goto V_249;
F_18 ( V_166 -> V_191 < ( V_87 ) V_3 ) ;
V_42 = ( int ) V_166 -> V_191 ;
F_207 ( V_152 , V_279 , 0 , V_166 -> V_191 ) ;
V_249:
if ( V_166 )
F_111 ( V_166 ) ;
else
F_153 ( V_152 , V_236 ) ;
return V_42 ;
}
static void F_208 ( struct V_284 * V_285 )
__releases( V_285 -> V_286 ) __acquires( V_285 -> V_286 )
{
struct V_21 * V_22 = V_285 -> V_287 ;
bool V_28 = V_22 -> V_27 . V_28 ;
struct V_288 * V_241 ;
int V_190 ;
while ( ( V_241 = F_209 ( V_285 ) ) ) {
bool V_223 = F_210 ( V_241 ) == V_289 ;
struct V_175 * V_168 ;
V_87 V_127 ;
V_87 V_135 ;
if ( V_241 -> V_290 != V_291 ) {
F_21 ( L_43 , V_44 ,
( int ) V_241 -> V_290 ) ;
F_211 ( V_241 , 0 ) ;
continue;
}
V_127 = ( V_87 ) F_212 ( V_241 ) << V_83 ;
V_135 = ( V_87 ) F_213 ( V_241 ) ;
if ( ! V_135 ) {
F_21 ( L_44 , V_44 ) ;
F_211 ( V_241 , 0 ) ;
continue;
}
F_14 ( V_285 -> V_286 ) ;
if ( V_223 ) {
V_190 = - V_29 ;
if ( V_28 )
goto V_292;
F_18 ( V_22 -> V_112 -> V_113 == V_114 ) ;
}
if ( ! F_13 ( V_293 , & V_22 -> V_32 ) ) {
F_21 ( L_45 ) ;
F_18 ( V_22 -> V_112 -> V_113 != V_114 ) ;
V_190 = - V_294 ;
goto V_292;
}
V_190 = - V_4 ;
if ( V_127 && V_135 > V_136 - V_127 + 1 ) {
F_98 ( V_22 , L_46 ,
V_127 , V_135 ) ;
goto V_292;
}
V_190 = - V_115 ;
if ( V_127 + V_135 > V_22 -> V_27 . V_77 ) {
F_98 ( V_22 , L_47 ,
V_127 , V_135 , V_22 -> V_27 . V_77 ) ;
goto V_292;
}
V_190 = - V_43 ;
V_168 = F_159 ( V_22 , V_127 , V_135 ,
V_223 ) ;
if ( ! V_168 )
goto V_292;
V_168 -> V_241 = V_241 ;
V_190 = F_170 ( V_168 , V_185 ,
V_241 -> V_137 ) ;
if ( ! V_190 )
V_190 = F_183 ( V_168 ) ;
if ( V_190 )
F_112 ( V_168 ) ;
V_292:
F_12 ( V_285 -> V_286 ) ;
if ( V_190 < 0 ) {
F_98 ( V_22 , L_48 ,
V_223 ? L_31 : L_32 ,
V_135 , V_127 , V_190 ) ;
F_211 ( V_241 , V_190 ) ;
}
}
}
static int F_214 ( struct V_284 * V_285 , struct V_295 * V_296 ,
struct V_142 * V_297 )
{
struct V_21 * V_22 = V_285 -> V_287 ;
T_10 V_298 ;
T_10 V_299 ;
T_10 V_300 ;
int V_42 ;
V_298 = F_215 ( V_296 -> V_301 ) + V_296 -> V_253 ;
V_299 = 1 << ( V_22 -> V_90 . V_106 - V_83 ) ;
V_300 = V_298 & ( V_299 - 1 ) ;
V_42 = ( int ) ( V_299 - V_300 ) << V_83 ;
if ( V_42 > V_296 -> V_162 )
V_42 -= V_296 -> V_162 ;
else
V_42 = 0 ;
F_18 ( V_297 -> V_148 <= V_158 ) ;
if ( V_42 > ( int ) V_297 -> V_148 || ! V_296 -> V_162 )
V_42 = ( int ) V_297 -> V_148 ;
return V_42 ;
}
static void F_216 ( struct V_21 * V_22 )
{
struct V_35 * V_36 = V_22 -> V_36 ;
if ( ! V_36 )
return;
V_22 -> V_36 = NULL ;
if ( V_36 -> V_32 & V_302 ) {
F_217 ( V_36 ) ;
if ( V_36 -> V_303 )
F_218 ( V_36 -> V_303 ) ;
}
F_219 ( V_36 ) ;
}
static int F_220 ( struct V_21 * V_22 ,
const char * V_219 ,
V_87 V_127 , V_87 V_135 , void * V_146 )
{
struct V_187 * V_188 = & V_22 -> V_38 -> V_49 -> V_188 ;
struct V_165 * V_166 ;
struct V_151 * * V_152 = NULL ;
T_5 V_236 ;
T_6 V_77 ;
int V_42 ;
V_236 = ( T_5 ) F_171 ( V_127 , V_135 ) ;
V_152 = F_181 ( V_236 , V_45 ) ;
if ( F_26 ( V_152 ) )
V_42 = F_182 ( V_152 ) ;
V_42 = - V_43 ;
V_166 = F_150 ( V_219 , V_127 , V_135 ,
V_186 ) ;
if ( ! V_166 )
goto V_249;
V_166 -> V_152 = V_152 ;
V_166 -> V_236 = V_236 ;
V_166 -> V_189 = F_143 ( V_22 , false , 1 ,
V_166 ) ;
if ( ! V_166 -> V_189 )
goto V_249;
F_173 ( V_166 -> V_189 , 0 , V_212 ,
V_127 , V_135 , 0 , 0 ) ;
F_175 ( V_166 -> V_189 , 0 ,
V_166 -> V_152 ,
V_166 -> V_135 ,
V_166 -> V_127 & ~ V_157 ,
false , false ) ;
F_140 ( V_166 ) ;
V_42 = F_117 ( V_188 , V_166 ) ;
if ( V_42 )
goto V_249;
V_42 = F_121 ( V_166 ) ;
if ( V_42 )
goto V_249;
V_42 = V_166 -> V_190 ;
if ( V_42 < 0 )
goto V_249;
F_18 ( V_166 -> V_191 <= ( V_87 ) V_84 ) ;
V_77 = ( T_6 ) V_166 -> V_191 ;
F_207 ( V_152 , V_146 , 0 , V_77 ) ;
F_18 ( V_77 <= ( T_6 ) V_3 ) ;
V_42 = ( int ) V_77 ;
V_249:
if ( V_166 )
F_111 ( V_166 ) ;
else
F_153 ( V_152 , V_236 ) ;
return V_42 ;
}
static int F_221 ( struct V_21 * V_22 )
{
struct V_75 * V_76 = NULL ;
T_5 V_78 = 0 ;
V_87 V_304 = 0 ;
T_5 V_305 ;
int V_42 ;
do {
T_6 V_77 ;
F_32 ( V_76 ) ;
V_77 = sizeof ( * V_76 ) ;
V_77 += V_78 * sizeof ( struct V_101 ) ;
V_77 += V_304 ;
V_76 = F_22 ( V_77 , V_45 ) ;
if ( ! V_76 )
return - V_43 ;
V_42 = F_220 ( V_22 , V_22 -> V_267 ,
0 , V_77 , V_76 ) ;
if ( V_42 < 0 )
goto V_249;
if ( ( T_6 ) V_42 < V_77 ) {
V_42 = - V_294 ;
F_98 ( V_22 , L_49 ,
V_77 , V_42 ) ;
goto V_249;
}
if ( ! F_53 ( V_76 ) ) {
V_42 = - V_294 ;
F_98 ( V_22 , L_50 ) ;
goto V_249;
}
V_304 = F_55 ( V_76 -> V_88 ) ;
V_305 = V_78 ;
V_78 = F_54 ( V_76 -> V_78 ) ;
} while ( V_78 != V_305 );
V_42 = F_56 ( V_22 , V_76 ) ;
V_249:
F_32 ( V_76 ) ;
return V_42 ;
}
static void F_222 ( struct V_21 * V_22 )
{
V_87 V_113 ;
if ( ! F_13 ( V_293 , & V_22 -> V_32 ) )
return;
V_113 = V_22 -> V_112 -> V_113 ;
if ( V_113 == V_114 )
return;
if ( F_63 ( V_22 , V_113 ) == V_123 )
F_127 ( V_293 , & V_22 -> V_32 ) ;
}
static void F_223 ( struct V_21 * V_22 )
{
T_10 V_77 ;
bool V_25 ;
F_12 ( & V_22 -> V_30 ) ;
V_25 = F_13 ( V_31 , & V_22 -> V_32 ) ;
F_14 ( & V_22 -> V_30 ) ;
if ( ! V_25 ) {
V_77 = ( T_10 ) V_22 -> V_27 . V_77 / V_306 ;
F_21 ( L_51 , ( unsigned long long ) V_77 ) ;
F_224 ( V_22 -> V_36 , V_77 ) ;
F_225 ( V_22 -> V_36 ) ;
}
}
static int F_194 ( struct V_21 * V_22 )
{
V_87 V_307 ;
int V_42 ;
F_18 ( F_52 ( V_22 -> V_74 ) ) ;
F_226 ( & V_22 -> V_240 ) ;
V_307 = V_22 -> V_27 . V_77 ;
if ( V_22 -> V_74 == 1 )
V_42 = F_221 ( V_22 ) ;
else
V_42 = F_227 ( V_22 ) ;
F_222 ( V_22 ) ;
F_228 ( & V_22 -> V_240 ) ;
if ( V_307 != V_22 -> V_27 . V_77 ) {
F_223 ( V_22 ) ;
}
return V_42 ;
}
static int F_229 ( struct V_21 * V_22 )
{
struct V_35 * V_36 ;
struct V_284 * V_285 ;
V_87 V_134 ;
V_36 = F_230 ( V_13 ?
( 1 << V_6 ) :
V_308 ) ;
if ( ! V_36 )
return - V_43 ;
snprintf ( V_36 -> V_309 , sizeof( V_36 -> V_309 ) , V_310 L_52 ,
V_22 -> V_5 ) ;
V_36 -> V_311 = V_22 -> V_311 ;
V_36 -> V_312 = V_22 -> V_7 ;
if ( V_13 )
V_36 -> V_32 |= V_313 ;
V_36 -> V_314 = & V_315 ;
V_36 -> V_24 = V_22 ;
V_285 = F_231 ( F_208 , & V_22 -> V_30 ) ;
if ( ! V_285 )
goto V_316;
F_232 ( V_285 , V_306 ) ;
V_134 = F_79 ( & V_22 -> V_90 ) ;
F_233 ( V_285 , V_134 / V_306 ) ;
F_234 ( V_285 , V_134 ) ;
F_235 ( V_285 , V_134 ) ;
F_236 ( V_285 , V_134 ) ;
F_237 ( V_285 , F_214 ) ;
V_36 -> V_303 = V_285 ;
V_285 -> V_287 = V_22 ;
V_22 -> V_36 = V_36 ;
return 0 ;
V_316:
F_219 ( V_36 ) ;
return - V_43 ;
}
static struct V_21 * F_238 ( struct V_17 * V_18 )
{
return F_48 ( V_18 , struct V_21 , V_18 ) ;
}
static T_11 F_239 ( struct V_17 * V_18 ,
struct V_317 * V_11 , char * V_146 )
{
struct V_21 * V_22 = F_238 ( V_18 ) ;
return sprintf ( V_146 , L_53 ,
( unsigned long long ) V_22 -> V_27 . V_77 ) ;
}
static T_11 F_240 ( struct V_17 * V_18 ,
struct V_317 * V_11 , char * V_146 )
{
struct V_21 * V_22 = F_238 ( V_18 ) ;
return sprintf ( V_146 , L_54 ,
( unsigned long long ) V_22 -> V_27 . V_111 ) ;
}
static T_11 F_241 ( struct V_17 * V_18 ,
struct V_317 * V_11 , char * V_146 )
{
struct V_21 * V_22 = F_238 ( V_18 ) ;
if ( V_22 -> V_311 )
return sprintf ( V_146 , L_55 , V_22 -> V_311 ) ;
return sprintf ( V_146 , L_56 ) ;
}
static T_11 F_242 ( struct V_17 * V_18 ,
struct V_317 * V_11 , char * V_146 )
{
struct V_21 * V_22 = F_238 ( V_18 ) ;
return sprintf ( V_146 , L_55 , V_22 -> V_7 ) ;
}
static T_11 F_243 ( struct V_17 * V_18 ,
struct V_317 * V_11 , char * V_146 )
{
struct V_21 * V_22 = F_238 ( V_18 ) ;
return sprintf ( V_146 , L_57 ,
F_244 ( V_22 -> V_38 -> V_49 ) ) ;
}
static T_11 F_245 ( struct V_17 * V_18 ,
struct V_317 * V_11 , char * V_146 )
{
struct V_21 * V_22 = F_238 ( V_18 ) ;
return sprintf ( V_146 , L_58 , V_22 -> V_112 -> V_318 ) ;
}
static T_11 F_246 ( struct V_17 * V_18 ,
struct V_317 * V_11 , char * V_146 )
{
struct V_21 * V_22 = F_238 ( V_18 ) ;
return sprintf ( V_146 , L_53 ,
( unsigned long long ) V_22 -> V_112 -> V_319 ) ;
}
static T_11 F_247 ( struct V_17 * V_18 ,
struct V_317 * V_11 , char * V_146 )
{
struct V_21 * V_22 = F_238 ( V_18 ) ;
if ( V_22 -> V_112 -> V_320 )
return sprintf ( V_146 , L_58 , V_22 -> V_112 -> V_320 ) ;
return sprintf ( V_146 , L_59 ) ;
}
static T_11 F_248 ( struct V_17 * V_18 ,
struct V_317 * V_11 , char * V_146 )
{
struct V_21 * V_22 = F_238 ( V_18 ) ;
return sprintf ( V_146 , L_58 , V_22 -> V_112 -> V_321 ) ;
}
static T_11 F_249 ( struct V_17 * V_18 ,
struct V_317 * V_11 ,
char * V_146 )
{
struct V_21 * V_22 = F_238 ( V_18 ) ;
return sprintf ( V_146 , L_58 , V_22 -> V_112 -> V_117 ) ;
}
static T_11 F_250 ( struct V_17 * V_18 ,
struct V_317 * V_11 ,
char * V_146 )
{
struct V_21 * V_22 = F_238 ( V_18 ) ;
struct V_322 * V_112 = V_22 -> V_237 ;
int V_323 ;
char * V_324 = V_146 ;
if ( ! V_112 )
return sprintf ( V_146 , L_60 ) ;
V_323 = sprintf ( V_324 , L_61 ,
( unsigned long long ) V_112 -> V_319 , V_112 -> V_318 ) ;
if ( V_323 < 0 )
return V_323 ;
V_324 += V_323 ;
V_323 = sprintf ( V_324 , L_62 , V_112 -> V_321 ,
V_112 -> V_320 ? V_112 -> V_320 : L_63 ) ;
if ( V_323 < 0 )
return V_323 ;
V_324 += V_323 ;
V_323 = sprintf ( V_324 , L_64 ,
( unsigned long long ) V_112 -> V_113 , V_112 -> V_117 ) ;
if ( V_323 < 0 )
return V_323 ;
V_324 += V_323 ;
V_323 = sprintf ( V_324 , L_65 , V_22 -> V_199 ) ;
if ( V_323 < 0 )
return V_323 ;
V_324 += V_323 ;
return ( T_11 ) ( V_324 - V_146 ) ;
}
static T_11 F_251 ( struct V_17 * V_18 ,
struct V_317 * V_11 ,
const char * V_146 ,
T_6 V_77 )
{
struct V_21 * V_22 = F_238 ( V_18 ) ;
int V_42 ;
V_42 = F_194 ( V_22 ) ;
if ( V_42 )
F_98 ( V_22 , L_66 , V_42 ) ;
return V_42 < 0 ? V_42 : V_77 ;
}
static void F_252 ( struct V_17 * V_18 )
{
}
static struct V_322 * F_253 ( struct V_322 * V_112 )
{
F_36 ( & V_112 -> V_47 ) ;
return V_112 ;
}
static void F_156 ( struct V_322 * V_112 )
{
if ( V_112 )
F_51 ( & V_112 -> V_47 , V_325 ) ;
}
static struct V_322 * F_254 ( void )
{
struct V_322 * V_112 ;
V_112 = F_255 ( sizeof ( * V_112 ) , V_45 ) ;
if ( ! V_112 )
return NULL ;
F_23 ( & V_112 -> V_47 ) ;
return V_112 ;
}
static void V_325 ( struct V_47 * V_47 )
{
struct V_322 * V_112 = F_48 ( V_47 , struct V_322 , V_47 ) ;
F_32 ( V_112 -> V_318 ) ;
F_32 ( V_112 -> V_321 ) ;
F_32 ( V_112 -> V_320 ) ;
F_32 ( V_112 -> V_117 ) ;
F_32 ( V_112 ) ;
}
static struct V_21 * F_256 ( struct V_38 * V_41 ,
struct V_322 * V_112 )
{
struct V_21 * V_22 ;
V_22 = F_255 ( sizeof ( * V_22 ) , V_45 ) ;
if ( ! V_22 )
return NULL ;
F_163 ( & V_22 -> V_30 ) ;
V_22 -> V_32 = 0 ;
F_257 ( & V_22 -> V_238 , 0 ) ;
F_24 ( & V_22 -> V_48 ) ;
F_258 ( & V_22 -> V_240 ) ;
V_22 -> V_112 = V_112 ;
V_22 -> V_38 = V_41 ;
V_22 -> V_233 . V_326 = F_259 ( 1 << V_327 ) ;
V_22 -> V_233 . V_328 = F_259 ( 1 ) ;
V_22 -> V_233 . V_329 = F_259 ( 1 << V_327 ) ;
V_22 -> V_233 . V_330 = F_259 ( ( T_5 ) V_112 -> V_319 ) ;
return V_22 ;
}
static void F_260 ( struct V_21 * V_22 )
{
F_50 ( V_22 -> V_38 ) ;
F_156 ( V_22 -> V_112 ) ;
F_32 ( V_22 ) ;
}
static int F_68 ( struct V_21 * V_22 , V_87 V_113 ,
T_9 * V_82 , V_87 * V_125 )
{
V_86 V_331 = F_261 ( V_113 ) ;
int V_42 ;
struct {
T_9 V_82 ;
V_86 V_77 ;
} V_332 ( ( V_333 ) ) V_334 = { 0 } ;
V_42 = F_202 ( V_22 , V_22 -> V_267 ,
L_37 , L_67 ,
& V_331 , sizeof ( V_331 ) ,
& V_334 , sizeof ( V_334 ) ) ;
F_21 ( L_68 , V_44 , V_42 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_42 < sizeof ( V_334 ) )
return - V_335 ;
if ( V_82 ) {
* V_82 = V_334 . V_82 ;
F_21 ( L_69 , ( unsigned int ) * V_82 ) ;
}
* V_125 = F_55 ( V_334 . V_77 ) ;
F_21 ( L_70 ,
( unsigned long long ) V_113 ,
( unsigned long long ) * V_125 ) ;
return 0 ;
}
static int F_262 ( struct V_21 * V_22 )
{
return F_68 ( V_22 , V_114 ,
& V_22 -> V_90 . V_106 ,
& V_22 -> V_90 . V_105 ) ;
}
static int F_263 ( struct V_21 * V_22 )
{
void * V_336 ;
int V_42 ;
void * V_337 ;
V_336 = F_255 ( V_338 , V_45 ) ;
if ( ! V_336 )
return - V_43 ;
V_42 = F_202 ( V_22 , V_22 -> V_267 ,
L_37 , L_71 , NULL , 0 ,
V_336 , V_338 ) ;
F_21 ( L_68 , V_44 , V_42 ) ;
if ( V_42 < 0 )
goto V_249;
V_337 = V_336 ;
V_22 -> V_90 . V_92 = F_264 ( & V_337 ,
V_337 + V_42 , NULL , V_132 ) ;
V_42 = 0 ;
if ( F_26 ( V_22 -> V_90 . V_92 ) ) {
V_42 = F_182 ( V_22 -> V_90 . V_92 ) ;
V_22 -> V_90 . V_92 = NULL ;
} else {
F_21 ( L_72 , V_22 -> V_90 . V_92 ) ;
}
V_249:
F_32 ( V_336 ) ;
return V_42 ;
}
static int F_70 ( struct V_21 * V_22 , V_87 V_113 ,
V_87 * V_126 )
{
V_86 V_331 = F_261 ( V_113 ) ;
struct {
V_86 V_111 ;
V_86 V_339 ;
} V_332 ( ( V_333 ) ) V_340 = { 0 } ;
V_87 V_339 ;
int V_42 ;
V_42 = F_202 ( V_22 , V_22 -> V_267 ,
L_37 , L_73 ,
& V_331 , sizeof ( V_331 ) ,
& V_340 , sizeof ( V_340 ) ) ;
F_21 ( L_68 , V_44 , V_42 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_42 < sizeof ( V_340 ) )
return - V_335 ;
V_339 = F_55 ( V_340 . V_339 ) ;
if ( V_339 & ~ V_341 )
return - V_294 ;
* V_126 = F_55 ( V_340 . V_111 ) ;
F_21 ( L_74 ,
( unsigned long long ) V_113 ,
( unsigned long long ) * V_126 ,
( unsigned long long ) F_55 ( V_340 . V_339 ) ) ;
return 0 ;
}
static int F_265 ( struct V_21 * V_22 )
{
return F_70 ( V_22 , V_114 ,
& V_22 -> V_90 . V_111 ) ;
}
static int F_266 ( struct V_21 * V_22 )
{
struct V_322 * V_237 ;
T_6 V_77 ;
void * V_336 = NULL ;
V_86 V_331 ;
void * V_337 ;
void * V_153 ;
V_87 V_319 ;
char * V_321 ;
V_87 V_113 ;
V_87 V_342 ;
int V_42 ;
V_237 = F_254 () ;
if ( ! V_237 )
return - V_43 ;
V_77 = sizeof ( V_86 ) +
sizeof ( V_261 ) + V_343 +
sizeof ( V_86 ) +
sizeof ( V_86 ) ;
V_336 = F_22 ( V_77 , V_45 ) ;
if ( ! V_336 ) {
V_42 = - V_43 ;
goto V_98;
}
V_331 = F_261 ( V_114 ) ;
V_42 = F_202 ( V_22 , V_22 -> V_267 ,
L_37 , L_75 ,
& V_331 , sizeof ( V_331 ) ,
V_336 , V_77 ) ;
F_21 ( L_68 , V_44 , V_42 ) ;
if ( V_42 < 0 )
goto V_98;
V_337 = V_336 ;
V_153 = V_336 + V_42 ;
V_42 = - V_335 ;
F_267 ( & V_337 , V_153 , V_319 , V_98 ) ;
if ( V_319 == V_344 ) {
if ( V_22 -> V_199 ) {
V_22 -> V_199 = 0 ;
F_102 () ;
F_157 ( V_22 ) ;
F_268 ( L_76 ,
V_22 -> V_36 -> V_309 ) ;
}
goto V_249;
}
V_42 = - V_115 ;
if ( V_319 > ( V_87 ) V_345 ) {
F_98 ( NULL , L_77 ,
( unsigned long long ) V_319 , V_345 ) ;
goto V_98;
}
V_321 = F_264 ( & V_337 , V_153 , NULL , V_45 ) ;
if ( F_26 ( V_321 ) ) {
V_42 = F_182 ( V_321 ) ;
goto V_98;
}
F_267 ( & V_337 , V_153 , V_113 , V_98 ) ;
F_267 ( & V_337 , V_153 , V_342 , V_98 ) ;
if ( ! V_22 -> V_237 ) {
V_237 -> V_319 = V_319 ;
V_237 -> V_321 = V_321 ;
V_237 -> V_113 = V_113 ;
V_22 -> V_237 = V_237 ;
V_237 = NULL ;
}
V_22 -> V_199 = V_342 ;
F_102 () ;
if ( ! V_342 ) {
if ( V_237 ) {
F_157 ( V_22 ) ;
F_268 ( L_78 ,
V_22 -> V_36 -> V_309 ) ;
} else {
F_98 ( V_22 , L_79
L_80 ) ;
}
}
V_249:
V_42 = 0 ;
V_98:
F_32 ( V_336 ) ;
F_156 ( V_237 ) ;
return V_42 ;
}
static int F_269 ( struct V_21 * V_22 )
{
struct {
V_86 V_109 ;
V_86 V_110 ;
} V_332 ( ( V_333 ) ) V_346 = { 0 } ;
T_6 V_77 = sizeof ( V_346 ) ;
void * V_337 ;
V_87 V_347 ;
V_87 V_109 ;
V_87 V_110 ;
int V_42 ;
V_42 = F_202 ( V_22 , V_22 -> V_267 ,
L_37 , L_81 , NULL , 0 ,
( char * ) & V_346 , V_77 ) ;
F_21 ( L_68 , V_44 , V_42 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_42 < V_77 )
return - V_335 ;
V_42 = - V_4 ;
V_347 = ( V_87 ) 1 << V_22 -> V_90 . V_106 ;
V_337 = & V_346 ;
V_109 = F_270 ( & V_337 ) ;
if ( V_109 != V_347 ) {
F_98 ( V_22 , L_82
L_83 ,
V_109 , V_347 ) ;
return - V_4 ;
}
V_110 = F_270 ( & V_337 ) ;
if ( V_110 != 1 ) {
F_98 ( V_22 , L_84
L_85 , V_110 ) ;
return - V_4 ;
}
V_22 -> V_90 . V_109 = V_109 ;
V_22 -> V_90 . V_110 = V_110 ;
return 0 ;
}
static char * F_271 ( struct V_21 * V_22 )
{
T_6 V_348 ;
char * V_321 ;
void * V_337 ;
void * V_153 ;
T_6 V_77 ;
void * V_336 = NULL ;
T_6 V_97 = 0 ;
char * V_320 = NULL ;
int V_42 ;
F_18 ( ! V_22 -> V_112 -> V_320 ) ;
V_97 = strlen ( V_22 -> V_112 -> V_321 ) ;
V_348 = sizeof ( V_261 ) + V_97 ;
V_321 = F_22 ( V_348 , V_45 ) ;
if ( ! V_321 )
return NULL ;
V_337 = V_321 ;
V_153 = V_321 + V_348 ;
F_272 ( & V_337 , V_153 , V_22 -> V_112 -> V_321 , ( T_5 ) V_97 ) ;
V_77 = sizeof ( V_261 ) + V_349 ;
V_336 = F_22 ( V_77 , V_45 ) ;
if ( ! V_336 )
goto V_249;
V_42 = F_202 ( V_22 , V_350 ,
L_37 , L_86 ,
V_321 , V_348 ,
V_336 , V_77 ) ;
if ( V_42 < 0 )
goto V_249;
V_337 = V_336 ;
V_153 = V_336 + V_42 ;
V_320 = F_264 ( & V_337 , V_153 , & V_97 , V_45 ) ;
if ( F_26 ( V_320 ) )
V_320 = NULL ;
else
F_21 ( L_87 , V_44 , V_320 , V_97 ) ;
V_249:
F_32 ( V_336 ) ;
F_32 ( V_321 ) ;
return V_320 ;
}
static V_87 F_273 ( struct V_21 * V_22 , const char * V_128 )
{
struct V_85 * V_93 = V_22 -> V_90 . V_93 ;
const char * V_117 ;
T_5 V_116 = 0 ;
V_117 = V_22 -> V_90 . V_94 ;
while ( V_116 < V_93 -> V_118 ) {
if ( ! strcmp ( V_128 , V_117 ) )
return V_93 -> V_102 [ V_116 ] ;
V_117 += strlen ( V_117 ) + 1 ;
V_116 ++ ;
}
return V_114 ;
}
static V_87 F_274 ( struct V_21 * V_22 , const char * V_128 )
{
struct V_85 * V_93 = V_22 -> V_90 . V_93 ;
T_5 V_116 ;
bool V_55 = false ;
V_87 V_113 ;
for ( V_116 = 0 ; ! V_55 && V_116 < V_93 -> V_118 ; V_116 ++ ) {
const char * V_117 ;
V_113 = V_93 -> V_102 [ V_116 ] ;
V_117 = F_66 ( V_22 , V_113 ) ;
if ( F_26 ( V_117 ) ) {
if ( F_182 ( V_117 ) == - V_34 )
continue;
else
break;
}
V_55 = ! strcmp ( V_128 , V_117 ) ;
F_32 ( V_117 ) ;
}
return V_55 ? V_113 : V_114 ;
}
static V_87 F_275 ( struct V_21 * V_22 , const char * V_128 )
{
if ( V_22 -> V_74 == 1 )
return F_273 ( V_22 , V_128 ) ;
return F_274 ( V_22 , V_128 ) ;
}
static int F_276 ( struct V_21 * V_22 )
{
struct V_187 * V_188 = & V_22 -> V_38 -> V_49 -> V_188 ;
struct V_322 * V_112 = V_22 -> V_112 ;
const char * V_318 ;
const char * V_320 ;
const char * V_117 ;
int V_42 ;
if ( V_112 -> V_318 ) {
if ( strcmp ( V_112 -> V_117 , V_124 ) ) {
V_87 V_113 ;
V_113 = F_275 ( V_22 , V_112 -> V_117 ) ;
if ( V_113 == V_114 )
return - V_34 ;
V_112 -> V_113 = V_113 ;
} else {
V_112 -> V_113 = V_114 ;
}
return 0 ;
}
V_318 = F_277 ( V_188 -> V_351 , V_112 -> V_319 ) ;
if ( ! V_318 ) {
F_98 ( V_22 , L_88 , V_112 -> V_319 ) ;
return - V_115 ;
}
V_318 = F_61 ( V_318 , V_45 ) ;
if ( ! V_318 )
return - V_43 ;
V_320 = F_271 ( V_22 ) ;
if ( ! V_320 )
F_98 ( V_22 , L_89 ) ;
V_117 = F_65 ( V_22 , V_112 -> V_113 ) ;
if ( F_26 ( V_117 ) ) {
V_42 = F_182 ( V_117 ) ;
goto V_98;
}
V_112 -> V_318 = V_318 ;
V_112 -> V_320 = V_320 ;
V_112 -> V_117 = V_117 ;
return 0 ;
V_98:
F_32 ( V_320 ) ;
F_32 ( V_318 ) ;
return V_42 ;
}
static int F_278 ( struct V_21 * V_22 )
{
T_6 V_77 ;
int V_42 ;
void * V_336 ;
void * V_337 ;
void * V_153 ;
V_87 V_99 ;
T_5 V_78 ;
struct V_85 * V_93 ;
T_5 V_96 ;
V_77 = sizeof ( V_86 ) + sizeof ( V_261 ) +
V_352 * sizeof ( V_86 ) ;
V_336 = F_255 ( V_77 , V_45 ) ;
if ( ! V_336 )
return - V_43 ;
V_42 = F_202 ( V_22 , V_22 -> V_267 ,
L_37 , L_90 , NULL , 0 ,
V_336 , V_77 ) ;
F_21 ( L_68 , V_44 , V_42 ) ;
if ( V_42 < 0 )
goto V_249;
V_337 = V_336 ;
V_153 = V_336 + V_42 ;
V_42 = - V_335 ;
F_267 ( & V_337 , V_153 , V_99 , V_249 ) ;
F_279 ( & V_337 , V_153 , V_78 , V_249 ) ;
if ( V_78 > ( V_84 - sizeof ( struct V_85 ) )
/ sizeof ( V_87 ) ) {
V_42 = - V_4 ;
goto V_249;
}
if ( ! F_280 ( & V_337 , V_153 , V_78 * sizeof ( V_86 ) ) )
goto V_249;
V_42 = 0 ;
V_93 = F_58 ( V_78 , V_45 ) ;
if ( ! V_93 ) {
V_42 = - V_43 ;
goto V_249;
}
V_93 -> V_99 = V_99 ;
for ( V_96 = 0 ; V_96 < V_78 ; V_96 ++ )
V_93 -> V_102 [ V_96 ] = F_270 ( & V_337 ) ;
F_59 ( V_22 -> V_90 . V_93 ) ;
V_22 -> V_90 . V_93 = V_93 ;
F_21 ( L_91 ,
( unsigned long long ) V_99 , ( unsigned int ) V_78 ) ;
V_249:
F_32 ( V_336 ) ;
return V_42 ;
}
static const char * F_66 ( struct V_21 * V_22 ,
V_87 V_113 )
{
T_6 V_77 ;
void * V_336 ;
V_86 V_331 ;
int V_42 ;
void * V_337 ;
void * V_153 ;
char * V_117 ;
V_77 = sizeof ( V_261 ) + V_353 ;
V_336 = F_22 ( V_77 , V_45 ) ;
if ( ! V_336 )
return F_34 ( - V_43 ) ;
V_331 = F_261 ( V_113 ) ;
V_42 = F_202 ( V_22 , V_22 -> V_267 ,
L_37 , L_92 ,
& V_331 , sizeof ( V_331 ) ,
V_336 , V_77 ) ;
F_21 ( L_68 , V_44 , V_42 ) ;
if ( V_42 < 0 ) {
V_117 = F_34 ( V_42 ) ;
goto V_249;
}
V_337 = V_336 ;
V_153 = V_336 + V_42 ;
V_117 = F_264 ( & V_337 , V_153 , NULL , V_45 ) ;
if ( F_26 ( V_117 ) )
goto V_249;
F_21 ( L_93 ,
( unsigned long long ) V_113 , V_117 ) ;
V_249:
F_32 ( V_336 ) ;
return V_117 ;
}
static int F_227 ( struct V_21 * V_22 )
{
bool V_91 = V_22 -> V_90 . V_92 == NULL ;
int V_42 ;
V_42 = F_262 ( V_22 ) ;
if ( V_42 )
return V_42 ;
if ( V_91 ) {
V_42 = F_281 ( V_22 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_22 -> V_90 . V_111 & V_354 &&
( V_91 || V_22 -> V_237 ) ) {
bool V_355 ;
V_42 = F_266 ( V_22 ) ;
if ( V_42 )
return V_42 ;
V_355 = V_22 -> V_237 && V_22 -> V_112 -> V_318 ;
if ( V_91 && V_355 )
F_98 ( V_22 , L_94
L_95 ) ;
}
if ( V_22 -> V_112 -> V_113 == V_114 )
if ( V_22 -> V_27 . V_77 != V_22 -> V_90 . V_105 )
V_22 -> V_27 . V_77 = V_22 -> V_90 . V_105 ;
V_42 = F_278 ( V_22 ) ;
F_21 ( L_96 , V_42 ) ;
return V_42 ;
}
static int F_282 ( struct V_21 * V_22 )
{
struct V_17 * V_18 ;
int V_42 ;
V_18 = & V_22 -> V_18 ;
V_18 -> V_356 = & V_357 ;
V_18 -> type = & V_358 ;
V_18 -> V_246 = & V_359 ;
V_18 -> V_360 = V_361 ;
F_283 ( V_18 , L_52 , V_22 -> V_5 ) ;
V_42 = F_284 ( V_18 ) ;
return V_42 ;
}
static void F_285 ( struct V_21 * V_22 )
{
F_286 ( & V_22 -> V_18 ) ;
}
static int F_287 ( struct V_21 * V_22 )
{
int V_362 ;
V_362 = F_288 ( & V_363 ,
0 , F_8 ( 1 << V_364 ) ,
V_45 ) ;
if ( V_362 < 0 )
return V_362 ;
V_22 -> V_5 = V_362 ;
F_28 ( & V_365 ) ;
F_29 ( & V_22 -> V_48 , & V_366 ) ;
F_30 ( & V_365 ) ;
F_21 ( L_97 , V_22 , V_22 -> V_5 ) ;
return 0 ;
}
static void F_289 ( struct V_21 * V_22 )
{
F_28 ( & V_365 ) ;
F_290 ( & V_22 -> V_48 ) ;
F_30 ( & V_365 ) ;
F_291 ( & V_363 , V_22 -> V_5 ) ;
F_21 ( L_98 , V_22 , V_22 -> V_5 ) ;
}
static inline T_6 F_292 ( const char * * V_146 )
{
const char * V_367 = L_99 ;
* V_146 += strspn ( * V_146 , V_367 ) ;
return strcspn ( * V_146 , V_367 ) ;
}
static inline T_6 F_293 ( const char * * V_146 ,
char * V_63 ,
T_6 V_368 )
{
T_6 V_97 ;
V_97 = F_292 ( V_146 ) ;
if ( V_97 < V_368 ) {
memcpy ( V_63 , * V_146 , V_97 ) ;
* ( V_63 + V_97 ) = '\0' ;
}
* V_146 += V_97 ;
return V_97 ;
}
static inline char * F_294 ( const char * * V_146 , T_6 * V_369 )
{
char * V_370 ;
T_6 V_97 ;
V_97 = F_292 ( V_146 ) ;
V_370 = F_295 ( * V_146 , V_97 + 1 , V_45 ) ;
if ( ! V_370 )
return NULL ;
* ( V_370 + V_97 ) = '\0' ;
* V_146 += V_97 ;
if ( V_369 )
* V_369 = V_97 ;
return V_370 ;
}
static int F_296 ( const char * V_146 ,
struct V_39 * * V_40 ,
struct V_59 * * V_371 ,
struct V_322 * * V_322 )
{
T_6 V_97 ;
char * V_81 ;
const char * V_372 ;
char * V_117 ;
T_6 V_373 ;
struct V_322 * V_112 = NULL ;
struct V_59 * V_60 = NULL ;
struct V_39 * V_374 ;
int V_42 ;
V_97 = F_292 ( & V_146 ) ;
if ( ! V_97 ) {
F_98 ( NULL , L_100 ) ;
return - V_4 ;
}
V_372 = V_146 ;
V_373 = V_97 + 1 ;
V_146 += V_97 ;
V_42 = - V_4 ;
V_81 = F_294 ( & V_146 , NULL ) ;
if ( ! V_81 )
return - V_43 ;
if ( ! * V_81 ) {
F_98 ( NULL , L_101 ) ;
goto V_98;
}
V_112 = F_254 () ;
if ( ! V_112 )
goto V_375;
V_112 -> V_318 = F_294 ( & V_146 , NULL ) ;
if ( ! V_112 -> V_318 )
goto V_375;
if ( ! * V_112 -> V_318 ) {
F_98 ( NULL , L_102 ) ;
goto V_98;
}
V_112 -> V_320 = F_294 ( & V_146 , NULL ) ;
if ( ! V_112 -> V_320 )
goto V_375;
if ( ! * V_112 -> V_320 ) {
F_98 ( NULL , L_103 ) ;
goto V_98;
}
V_97 = F_292 ( & V_146 ) ;
if ( ! V_97 ) {
V_146 = V_124 ;
V_97 = sizeof ( V_124 ) - 1 ;
} else if ( V_97 > V_353 ) {
V_42 = - V_376 ;
goto V_98;
}
V_117 = F_295 ( V_146 , V_97 + 1 , V_45 ) ;
if ( ! V_117 )
goto V_375;
* ( V_117 + V_97 ) = '\0' ;
V_112 -> V_117 = V_117 ;
V_60 = F_255 ( sizeof ( * V_60 ) , V_45 ) ;
if ( ! V_60 )
goto V_375;
V_60 -> V_28 = V_377 ;
V_374 = F_297 ( V_81 , V_372 ,
V_372 + V_373 - 1 ,
F_40 , V_60 ) ;
if ( F_26 ( V_374 ) ) {
V_42 = F_182 ( V_374 ) ;
goto V_98;
}
F_32 ( V_81 ) ;
* V_40 = V_374 ;
* V_371 = V_60 ;
* V_322 = V_112 ;
return 0 ;
V_375:
V_42 = - V_43 ;
V_98:
F_32 ( V_60 ) ;
F_156 ( V_112 ) ;
F_32 ( V_81 ) ;
return V_42 ;
}
static int F_298 ( struct V_21 * V_22 )
{
int V_42 ;
T_6 V_77 ;
char * V_219 ;
void * V_378 ;
char * V_321 ;
if ( V_22 -> V_112 -> V_321 ) {
V_22 -> V_74 = * V_22 -> V_112 -> V_321 ? 2 : 1 ;
return 0 ;
}
V_77 = sizeof ( V_379 ) + strlen ( V_22 -> V_112 -> V_320 ) ;
V_219 = F_22 ( V_77 , V_132 ) ;
if ( ! V_219 )
return - V_43 ;
sprintf ( V_219 , L_104 , V_379 , V_22 -> V_112 -> V_320 ) ;
F_21 ( L_105 , V_219 ) ;
V_77 = sizeof ( V_261 ) + V_343 ;
V_378 = F_255 ( V_77 , V_132 ) ;
if ( ! V_378 ) {
V_42 = - V_43 ;
goto V_249;
}
V_42 = F_202 ( V_22 , V_219 ,
L_37 , L_106 , NULL , 0 ,
V_378 , V_343 ) ;
F_21 ( L_68 , V_44 , V_42 ) ;
if ( V_42 == - V_34 ) {
V_321 = F_61 ( L_107 , V_45 ) ;
V_42 = V_321 ? 0 : - V_43 ;
if ( ! V_42 )
V_22 -> V_74 = 1 ;
} else if ( V_42 > sizeof ( V_261 ) ) {
void * V_337 = V_378 ;
V_321 = F_264 ( & V_337 , V_337 + V_42 ,
NULL , V_132 ) ;
V_42 = F_26 ( V_321 ) ? F_182 ( V_321 ) : 0 ;
if ( ! V_42 )
V_22 -> V_74 = 2 ;
} else {
V_42 = - V_4 ;
}
if ( ! V_42 ) {
V_22 -> V_112 -> V_321 = V_321 ;
F_21 ( L_108 , V_321 ) ;
}
V_249:
F_32 ( V_378 ) ;
F_32 ( V_219 ) ;
return V_42 ;
}
static void F_299 ( struct V_21 * V_22 )
{
struct V_89 * V_90 ;
if ( V_22 -> V_199 )
F_157 ( V_22 ) ;
V_90 = & V_22 -> V_90 ;
F_59 ( V_90 -> V_93 ) ;
F_32 ( V_90 -> V_95 ) ;
F_32 ( V_90 -> V_94 ) ;
F_32 ( V_90 -> V_92 ) ;
memset ( V_90 , 0 , sizeof ( * V_90 ) ) ;
}
static int F_281 ( struct V_21 * V_22 )
{
int V_42 ;
V_42 = F_263 ( V_22 ) ;
if ( V_42 )
goto V_98;
V_42 = F_265 ( V_22 ) ;
if ( V_42 )
goto V_98;
if ( V_22 -> V_90 . V_111 & V_380 ) {
V_42 = F_269 ( V_22 ) ;
if ( V_42 < 0 )
goto V_98;
}
return 0 ;
V_98:
V_22 -> V_90 . V_111 = 0 ;
F_32 ( V_22 -> V_90 . V_92 ) ;
V_22 -> V_90 . V_92 = NULL ;
return V_42 ;
}
static int F_300 ( struct V_21 * V_22 )
{
struct V_21 * V_246 = NULL ;
struct V_322 * V_237 ;
struct V_38 * V_41 ;
int V_42 ;
if ( ! V_22 -> V_237 )
return 0 ;
V_237 = F_253 ( V_22 -> V_237 ) ;
V_41 = F_35 ( V_22 -> V_38 ) ;
V_42 = - V_43 ;
V_246 = F_256 ( V_41 , V_237 ) ;
if ( ! V_246 )
goto V_98;
V_42 = F_301 ( V_246 , false ) ;
if ( V_42 < 0 )
goto V_98;
V_22 -> V_246 = V_246 ;
F_257 ( & V_22 -> V_238 , 1 ) ;
return 0 ;
V_98:
if ( V_246 ) {
F_154 ( V_22 ) ;
F_32 ( V_22 -> V_267 ) ;
F_260 ( V_246 ) ;
} else {
F_50 ( V_41 ) ;
F_156 ( V_237 ) ;
}
return V_42 ;
}
static int F_302 ( struct V_21 * V_22 )
{
int V_42 ;
V_42 = F_287 ( V_22 ) ;
if ( V_42 )
return V_42 ;
F_303 ( V_381
< sizeof ( V_310 ) + V_382 ) ;
sprintf ( V_22 -> V_128 , L_109 , V_310 , V_22 -> V_5 ) ;
if ( ! V_13 ) {
V_42 = F_304 ( 0 , V_22 -> V_128 ) ;
if ( V_42 < 0 )
goto V_383;
V_22 -> V_311 = V_42 ;
V_22 -> V_7 = 0 ;
} else {
V_22 -> V_311 = V_384 ;
V_22 -> V_7 = F_7 ( V_22 -> V_5 ) ;
}
V_42 = F_229 ( V_22 ) ;
if ( V_42 )
goto V_385;
V_42 = F_71 ( V_22 ) ;
if ( V_42 )
goto V_386;
F_224 ( V_22 -> V_36 , V_22 -> V_27 . V_77 / V_306 ) ;
V_42 = F_282 ( V_22 ) ;
if ( V_42 )
goto V_387;
F_106 ( V_293 , & V_22 -> V_32 ) ;
F_305 ( V_22 -> V_36 ) ;
F_268 ( L_110 , V_22 -> V_36 -> V_309 ,
( unsigned long long ) V_22 -> V_27 . V_77 ) ;
return V_42 ;
V_387:
F_72 ( V_22 ) ;
V_386:
F_216 ( V_22 ) ;
V_385:
if ( ! V_13 )
F_306 ( V_22 -> V_311 , V_22 -> V_128 ) ;
V_383:
F_289 ( V_22 ) ;
F_72 ( V_22 ) ;
return V_42 ;
}
static int F_307 ( struct V_21 * V_22 )
{
struct V_322 * V_112 = V_22 -> V_112 ;
T_6 V_77 ;
F_18 ( F_52 ( V_22 -> V_74 ) ) ;
if ( V_22 -> V_74 == 1 )
V_77 = strlen ( V_112 -> V_320 ) + sizeof ( V_388 ) ;
else
V_77 = sizeof ( V_389 ) + strlen ( V_112 -> V_321 ) ;
V_22 -> V_267 = F_22 ( V_77 , V_45 ) ;
if ( ! V_22 -> V_267 )
return - V_43 ;
if ( V_22 -> V_74 == 1 )
sprintf ( V_22 -> V_267 , L_104 ,
V_112 -> V_320 , V_388 ) ;
else
sprintf ( V_22 -> V_267 , L_104 ,
V_389 , V_112 -> V_321 ) ;
return 0 ;
}
static void F_308 ( struct V_21 * V_22 )
{
F_299 ( V_22 ) ;
F_32 ( V_22 -> V_267 ) ;
V_22 -> V_267 = NULL ;
V_22 -> V_74 = 0 ;
F_32 ( V_22 -> V_112 -> V_321 ) ;
V_22 -> V_112 -> V_321 = NULL ;
F_260 ( V_22 ) ;
}
static int F_301 ( struct V_21 * V_22 , bool V_27 )
{
int V_42 ;
V_42 = F_298 ( V_22 ) ;
if ( V_42 )
return V_42 ;
F_18 ( V_22 -> V_112 -> V_321 ) ;
F_18 ( F_52 ( V_22 -> V_74 ) ) ;
V_42 = F_307 ( V_22 ) ;
if ( V_42 )
goto V_390;
if ( V_27 ) {
V_42 = F_200 ( V_22 ) ;
if ( V_42 )
goto V_391;
}
if ( V_22 -> V_74 == 1 )
V_42 = F_221 ( V_22 ) ;
else
V_42 = F_227 ( V_22 ) ;
if ( V_42 )
goto V_392;
V_42 = F_276 ( V_22 ) ;
if ( V_42 )
goto V_393;
V_42 = F_300 ( V_22 ) ;
if ( V_42 )
goto V_393;
F_21 ( L_111 ,
V_22 -> V_74 , V_22 -> V_267 ) ;
return 0 ;
V_393:
F_299 ( V_22 ) ;
V_392:
if ( V_27 )
F_201 ( V_22 ) ;
V_391:
F_32 ( V_22 -> V_267 ) ;
V_22 -> V_267 = NULL ;
V_390:
V_22 -> V_74 = 0 ;
F_32 ( V_22 -> V_112 -> V_321 ) ;
V_22 -> V_112 -> V_321 = NULL ;
F_21 ( L_112 , V_42 ) ;
return V_42 ;
}
static T_11 F_309 ( struct V_394 * V_356 ,
const char * V_146 ,
T_6 V_323 )
{
struct V_21 * V_22 = NULL ;
struct V_39 * V_40 = NULL ;
struct V_59 * V_60 = NULL ;
struct V_322 * V_112 = NULL ;
struct V_38 * V_41 ;
struct V_187 * V_188 ;
bool V_28 ;
int V_395 = - V_43 ;
if ( ! F_310 ( V_396 ) )
return - V_397 ;
V_395 = F_296 ( V_146 , & V_40 , & V_60 , & V_112 ) ;
if ( V_395 < 0 )
goto V_398;
V_28 = V_60 -> V_28 ;
F_32 ( V_60 ) ;
V_60 = NULL ;
V_41 = F_44 ( V_40 ) ;
if ( F_26 ( V_41 ) ) {
V_395 = F_182 ( V_41 ) ;
goto V_399;
}
V_188 = & V_41 -> V_49 -> V_188 ;
V_395 = F_311 ( V_188 -> V_351 , V_112 -> V_318 ) ;
if ( V_395 < 0 )
goto V_400;
V_112 -> V_319 = ( V_87 ) V_395 ;
if ( V_112 -> V_319 > ( V_87 ) V_345 ) {
F_98 ( NULL , L_113 ,
( unsigned long long ) V_112 -> V_319 , V_345 ) ;
V_395 = - V_115 ;
goto V_400;
}
V_22 = F_256 ( V_41 , V_112 ) ;
if ( ! V_22 )
goto V_400;
V_41 = NULL ;
V_112 = NULL ;
V_395 = F_301 ( V_22 , true ) ;
if ( V_395 < 0 )
goto V_401;
if ( V_22 -> V_112 -> V_113 != V_114 )
V_28 = true ;
V_22 -> V_27 . V_28 = V_28 ;
V_395 = F_302 ( V_22 ) ;
if ( V_395 ) {
F_201 ( V_22 ) ;
F_308 ( V_22 ) ;
goto V_398;
}
return V_323 ;
V_401:
F_260 ( V_22 ) ;
V_400:
F_50 ( V_41 ) ;
V_399:
F_156 ( V_112 ) ;
V_398:
F_312 ( V_396 ) ;
F_21 ( L_114 , V_146 ) ;
return ( T_11 ) V_395 ;
}
static T_11 F_313 ( struct V_394 * V_356 ,
const char * V_146 ,
T_6 V_323 )
{
if ( V_13 )
return - V_4 ;
return F_309 ( V_356 , V_146 , V_323 ) ;
}
static T_11 F_314 ( struct V_394 * V_356 ,
const char * V_146 ,
T_6 V_323 )
{
return F_309 ( V_356 , V_146 , V_323 ) ;
}
static void V_361 ( struct V_17 * V_18 )
{
struct V_21 * V_22 = F_238 ( V_18 ) ;
F_216 ( V_22 ) ;
F_127 ( V_293 , & V_22 -> V_32 ) ;
F_72 ( V_22 ) ;
if ( ! V_13 )
F_306 ( V_22 -> V_311 , V_22 -> V_128 ) ;
F_289 ( V_22 ) ;
F_72 ( V_22 ) ;
}
static void F_155 ( struct V_21 * V_22 )
{
while ( V_22 -> V_246 ) {
struct V_21 * V_402 = V_22 ;
struct V_21 * V_403 = V_402 -> V_246 ;
struct V_21 * V_404 ;
while ( V_403 && ( V_404 = V_403 -> V_246 ) ) {
V_402 = V_403 ;
V_403 = V_404 ;
}
F_18 ( V_403 ) ;
F_308 ( V_403 ) ;
V_402 -> V_246 = NULL ;
V_402 -> V_199 = 0 ;
F_18 ( V_402 -> V_237 ) ;
F_156 ( V_402 -> V_237 ) ;
V_402 -> V_237 = NULL ;
}
}
static T_11 F_315 ( struct V_394 * V_356 ,
const char * V_146 ,
T_6 V_323 )
{
struct V_21 * V_22 = NULL ;
struct V_405 * V_139 ;
int V_5 ;
unsigned long V_406 ;
bool V_407 = false ;
int V_42 ;
V_42 = F_316 ( V_146 , 10 , & V_406 ) ;
if ( V_42 )
return V_42 ;
V_5 = ( int ) V_406 ;
if ( V_5 != V_406 )
return - V_4 ;
V_42 = - V_34 ;
F_28 ( & V_365 ) ;
F_317 (tmp, &rbd_dev_list) {
V_22 = F_318 ( V_139 , struct V_21 , V_48 ) ;
if ( V_22 -> V_5 == V_5 ) {
V_42 = 0 ;
break;
}
}
if ( ! V_42 ) {
F_12 ( & V_22 -> V_30 ) ;
if ( V_22 -> V_33 )
V_42 = - V_408 ;
else
V_407 = F_100 ( V_31 ,
& V_22 -> V_32 ) ;
F_14 ( & V_22 -> V_30 ) ;
}
F_30 ( & V_365 ) ;
if ( V_42 < 0 || V_407 )
return V_42 ;
F_201 ( V_22 ) ;
F_21 ( L_115 , V_44 ) ;
F_319 ( & V_22 -> V_38 -> V_49 -> V_188 ) ;
F_285 ( V_22 ) ;
F_308 ( V_22 ) ;
F_312 ( V_396 ) ;
return V_323 ;
}
static T_11 F_320 ( struct V_394 * V_356 ,
const char * V_146 ,
T_6 V_323 )
{
if ( V_13 )
return - V_4 ;
return F_315 ( V_356 , V_146 , V_323 ) ;
}
static T_11 F_321 ( struct V_394 * V_356 ,
const char * V_146 ,
T_6 V_323 )
{
return F_315 ( V_356 , V_146 , V_323 ) ;
}
static int F_322 ( void )
{
int V_42 ;
V_42 = F_284 ( & V_359 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_323 ( & V_357 ) ;
if ( V_42 < 0 )
F_286 ( & V_359 ) ;
return V_42 ;
}
static void F_324 ( void )
{
F_325 ( & V_357 ) ;
F_286 ( & V_359 ) ;
}
static int F_326 ( void )
{
F_18 ( ! V_239 ) ;
V_239 = F_327 ( L_116 ,
sizeof ( struct V_175 ) ,
F_328 ( struct V_175 ) ,
0 , NULL ) ;
if ( ! V_239 )
return - V_43 ;
F_18 ( ! V_235 ) ;
V_235 = F_327 ( L_117 ,
sizeof ( struct V_165 ) ,
F_328 ( struct V_165 ) ,
0 , NULL ) ;
if ( ! V_235 )
goto V_98;
F_18 ( ! V_131 ) ;
V_131 = F_327 ( L_118 ,
V_133 + 1 , 1 , 0 , NULL ) ;
if ( V_131 )
return 0 ;
V_98:
if ( V_235 ) {
F_329 ( V_235 ) ;
V_235 = NULL ;
}
F_329 ( V_239 ) ;
V_239 = NULL ;
return - V_43 ;
}
static void F_330 ( void )
{
F_18 ( V_131 ) ;
F_329 ( V_131 ) ;
V_131 = NULL ;
F_18 ( V_235 ) ;
F_329 ( V_235 ) ;
V_235 = NULL ;
F_18 ( V_239 ) ;
F_329 ( V_239 ) ;
V_239 = NULL ;
}
static int T_12 F_331 ( void )
{
int V_395 ;
if ( ! F_332 ( NULL ) ) {
F_98 ( NULL , L_119 ) ;
return - V_4 ;
}
V_395 = F_326 () ;
if ( V_395 )
return V_395 ;
if ( V_13 ) {
V_384 = F_304 ( 0 , V_310 ) ;
if ( V_384 < 0 ) {
V_395 = V_384 ;
goto V_409;
}
}
V_395 = F_322 () ;
if ( V_395 )
goto V_385;
if ( V_13 )
F_268 ( L_120 , V_384 ) ;
else
F_268 ( L_121 ) ;
return 0 ;
V_385:
if ( V_13 )
F_306 ( V_384 , V_310 ) ;
V_409:
F_330 () ;
return V_395 ;
}
static void T_13 F_333 ( void )
{
F_324 () ;
if ( V_13 )
F_306 ( V_384 , V_310 ) ;
F_330 () ;
}
