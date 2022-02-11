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
return 0 ;
}
static void F_16 ( struct V_35 * V_36 , T_3 V_16 )
{
struct V_21 * V_22 = V_36 -> V_24 ;
unsigned long V_37 ;
F_12 ( & V_22 -> V_30 ) ;
V_37 = V_22 -> V_33 -- ;
F_14 ( & V_22 -> V_30 ) ;
F_17 ( V_37 > 0 ) ;
F_18 ( & V_22 -> V_18 ) ;
}
static int F_19 ( struct V_21 * V_22 , unsigned long V_38 )
{
int V_39 = 0 ;
int V_40 ;
bool V_41 ;
bool V_42 = false ;
if ( F_20 ( V_40 , ( int V_43 * ) ( V_38 ) ) )
return - V_44 ;
V_41 = V_40 ? true : false ;
if ( V_22 -> V_45 -> V_46 != V_47 && ! V_41 )
return - V_29 ;
F_12 ( & V_22 -> V_30 ) ;
if ( V_22 -> V_33 > 1 ) {
V_39 = - V_48 ;
goto V_49;
}
if ( V_22 -> V_27 . V_28 != V_41 ) {
V_22 -> V_27 . V_28 = V_41 ;
V_42 = true ;
}
V_49:
F_14 ( & V_22 -> V_30 ) ;
if ( V_39 == 0 && V_42 )
F_21 ( V_22 -> V_36 , V_41 ? 1 : 0 ) ;
return V_39 ;
}
static int F_22 ( struct V_19 * V_20 , T_3 V_16 ,
unsigned int V_50 , unsigned long V_38 )
{
struct V_21 * V_22 = V_20 -> V_23 -> V_24 ;
int V_39 = 0 ;
switch ( V_50 ) {
case V_51 :
V_39 = F_19 ( V_22 , V_38 ) ;
break;
default:
V_39 = - V_52 ;
}
return V_39 ;
}
static int F_23 ( struct V_19 * V_20 , T_3 V_16 ,
unsigned int V_50 , unsigned long V_38 )
{
return F_22 ( V_20 , V_16 , V_50 , V_38 ) ;
}
static struct V_53 * F_24 ( struct V_54 * V_55 )
{
struct V_53 * V_56 ;
int V_39 = - V_57 ;
F_25 ( L_1 , V_58 ) ;
V_56 = F_26 ( sizeof( struct V_53 ) , V_59 ) ;
if ( ! V_56 )
goto V_60;
F_27 ( & V_56 -> V_61 ) ;
F_28 ( & V_56 -> V_62 ) ;
V_56 -> V_63 = F_29 ( V_55 , V_56 , 0 , 0 ) ;
if ( F_30 ( V_56 -> V_63 ) )
goto V_64;
V_55 = NULL ;
V_39 = F_31 ( V_56 -> V_63 ) ;
if ( V_39 < 0 )
goto V_65;
F_32 ( & V_66 ) ;
F_33 ( & V_56 -> V_62 , & V_67 ) ;
F_34 ( & V_66 ) ;
F_25 ( L_2 , V_58 , V_56 ) ;
return V_56 ;
V_65:
F_35 ( V_56 -> V_63 ) ;
V_64:
F_36 ( V_56 ) ;
V_60:
if ( V_55 )
F_37 ( V_55 ) ;
F_25 ( L_3 , V_58 , V_39 ) ;
return F_38 ( V_39 ) ;
}
static struct V_53 * F_39 ( struct V_53 * V_56 )
{
F_40 ( & V_56 -> V_61 ) ;
return V_56 ;
}
static struct V_53 * F_41 ( struct V_54 * V_55 )
{
struct V_53 * V_68 ;
bool V_69 = false ;
if ( V_55 -> V_32 & V_70 )
return NULL ;
F_32 ( & V_66 ) ;
F_42 (client_node, &rbd_client_list, node) {
if ( ! F_43 ( V_55 , V_68 -> V_63 ) ) {
F_39 ( V_68 ) ;
V_69 = true ;
break;
}
}
F_34 ( & V_66 ) ;
return V_69 ? V_68 : NULL ;
}
static int F_44 ( char * V_71 , void * V_72 )
{
struct V_73 * V_74 = V_72 ;
T_4 V_75 [ V_76 ] ;
int V_77 , V_78 , V_39 ;
V_77 = F_45 ( V_71 , V_79 , V_75 ) ;
if ( V_77 < 0 )
return - V_4 ;
if ( V_77 < V_80 ) {
V_39 = F_46 ( & V_75 [ 0 ] , & V_78 ) ;
if ( V_39 < 0 ) {
F_47 ( L_4
L_5 , V_71 ) ;
return V_39 ;
}
F_25 ( L_6 , V_77 , V_78 ) ;
} else if ( V_77 > V_80 && V_77 < V_81 ) {
F_25 ( L_7 , V_77 ,
V_75 [ 0 ] . V_82 ) ;
} else if ( V_77 > V_81 && V_77 < V_83 ) {
F_25 ( L_8 , V_77 ) ;
} else {
F_25 ( L_9 , V_77 ) ;
}
switch ( V_77 ) {
case V_84 :
V_74 -> V_28 = true ;
break;
case V_85 :
V_74 -> V_28 = false ;
break;
default:
F_17 ( false ) ;
break;
}
return 0 ;
}
static char * F_48 ( enum V_86 V_87 )
{
switch ( V_87 ) {
case V_88 :
return L_10 ;
case V_89 :
return L_11 ;
case V_90 :
return L_12 ;
default:
return L_13 ;
}
}
static struct V_53 * F_49 ( struct V_54 * V_55 )
{
struct V_53 * V_56 ;
F_50 ( & V_91 , V_92 ) ;
V_56 = F_41 ( V_55 ) ;
if ( V_56 )
F_37 ( V_55 ) ;
else
V_56 = F_24 ( V_55 ) ;
F_51 ( & V_91 ) ;
return V_56 ;
}
static void F_52 ( struct V_61 * V_61 )
{
struct V_53 * V_56 = F_53 ( V_61 , struct V_53 , V_61 ) ;
F_25 ( L_2 , V_58 , V_56 ) ;
F_32 ( & V_66 ) ;
F_54 ( & V_56 -> V_62 ) ;
F_34 ( & V_66 ) ;
F_35 ( V_56 -> V_63 ) ;
F_36 ( V_56 ) ;
}
static void F_55 ( struct V_53 * V_56 )
{
if ( V_56 )
F_56 ( & V_56 -> V_61 , F_52 ) ;
}
static bool F_57 ( T_5 V_93 )
{
return V_93 == 1 || V_93 == 2 ;
}
static bool F_58 ( struct V_94 * V_95 )
{
T_6 V_96 ;
T_5 V_97 ;
if ( memcmp ( & V_95 -> V_98 , V_99 , sizeof ( V_99 ) ) )
return false ;
if ( V_95 -> V_100 . V_101 < V_102 )
return false ;
if ( V_95 -> V_100 . V_101 > 8 * sizeof ( int ) - 1 )
return false ;
V_97 = F_59 ( V_95 -> V_97 ) ;
V_96 = V_103 - sizeof ( struct V_104 ) ;
if ( V_97 > V_96 / sizeof ( V_105 ) )
return false ;
V_96 -= V_97 * sizeof ( V_105 ) ;
if ( ( V_106 ) V_96 < F_60 ( V_95 -> V_107 ) )
return false ;
return true ;
}
static int F_61 ( struct V_21 * V_22 ,
struct V_94 * V_95 )
{
struct V_108 * V_109 = & V_22 -> V_109 ;
bool V_110 = V_109 -> V_111 == NULL ;
struct V_104 * V_112 ;
char * V_111 = NULL ;
char * V_113 = NULL ;
V_106 * V_114 = NULL ;
T_5 V_97 ;
T_6 V_96 ;
int V_39 = - V_57 ;
T_5 V_115 ;
if ( V_110 ) {
T_6 V_116 ;
V_116 = F_62 ( V_95 -> V_111 ,
sizeof ( V_95 -> V_111 ) ) ;
V_111 = F_26 ( V_116 + 1 , V_59 ) ;
if ( ! V_111 )
return - V_57 ;
memcpy ( V_111 , V_95 -> V_111 , V_116 ) ;
V_111 [ V_116 ] = '\0' ;
}
V_97 = F_59 ( V_95 -> V_97 ) ;
V_112 = F_63 ( V_97 , V_59 ) ;
if ( ! V_112 )
goto V_117;
V_112 -> V_118 = F_60 ( V_95 -> V_119 ) ;
if ( V_97 ) {
struct V_120 * V_121 ;
V_106 V_107 = F_60 ( V_95 -> V_107 ) ;
if ( V_107 > ( V_106 ) V_103 )
goto V_122;
V_113 = F_26 ( V_107 , V_59 ) ;
if ( ! V_113 )
goto V_117;
V_96 = V_97 * sizeof ( * V_109 -> V_114 ) ;
V_114 = F_26 ( V_96 , V_59 ) ;
if ( ! V_114 )
goto V_117;
memcpy ( V_113 , & V_95 -> V_121 [ V_97 ] , V_107 ) ;
V_121 = V_95 -> V_121 ;
for ( V_115 = 0 ; V_115 < V_97 ; V_115 ++ ) {
V_112 -> V_121 [ V_115 ] = F_60 ( V_121 [ V_115 ] . V_123 ) ;
V_114 [ V_115 ] = F_60 ( V_121 [ V_115 ] . V_124 ) ;
}
}
if ( V_110 ) {
V_109 -> V_111 = V_111 ;
V_109 -> V_125 = V_95 -> V_100 . V_101 ;
V_109 -> V_126 = V_95 -> V_100 . V_126 ;
V_109 -> V_127 = V_95 -> V_100 . V_127 ;
V_109 -> V_128 = 0 ;
V_109 -> V_129 = 0 ;
V_109 -> V_130 = 0 ;
} else {
F_64 ( V_109 -> V_112 ) ;
F_36 ( V_109 -> V_113 ) ;
F_36 ( V_109 -> V_114 ) ;
}
V_109 -> V_124 = F_60 ( V_95 -> V_124 ) ;
V_109 -> V_112 = V_112 ;
V_109 -> V_113 = V_113 ;
V_109 -> V_114 = V_114 ;
return 0 ;
V_122:
V_39 = - V_131 ;
V_117:
F_36 ( V_114 ) ;
F_36 ( V_113 ) ;
F_64 ( V_112 ) ;
F_36 ( V_111 ) ;
return V_39 ;
}
static const char * F_65 ( struct V_21 * V_22 , T_5 V_132 )
{
const char * V_133 ;
F_17 ( V_132 < V_22 -> V_109 . V_112 -> V_134 ) ;
V_133 = V_22 -> V_109 . V_113 ;
while ( V_132 -- )
V_133 += strlen ( V_133 ) + 1 ;
return F_66 ( V_133 , V_59 ) ;
}
static int F_67 ( const void * V_135 , const void * V_136 )
{
V_106 V_137 = * ( V_106 * ) V_135 ;
V_106 V_138 = * ( V_106 * ) V_136 ;
if ( V_137 < V_138 )
return 1 ;
return V_137 == V_138 ? 0 : - 1 ;
}
static T_5 F_68 ( struct V_21 * V_22 , V_106 V_46 )
{
struct V_104 * V_112 = V_22 -> V_109 . V_112 ;
V_106 * V_69 ;
V_69 = bsearch ( & V_46 , & V_112 -> V_121 , V_112 -> V_134 ,
sizeof ( V_46 ) , F_67 ) ;
return V_69 ? ( T_5 ) ( V_69 - & V_112 -> V_121 [ 0 ] ) : V_139 ;
}
static const char * F_69 ( struct V_21 * V_22 ,
V_106 V_46 )
{
T_5 V_132 ;
const char * V_133 ;
V_132 = F_68 ( V_22 , V_46 ) ;
if ( V_132 == V_139 )
return F_38 ( - V_34 ) ;
V_133 = F_65 ( V_22 , V_132 ) ;
return V_133 ? V_133 : F_38 ( - V_57 ) ;
}
static const char * F_70 ( struct V_21 * V_22 , V_106 V_46 )
{
if ( V_46 == V_47 )
return V_140 ;
F_17 ( F_57 ( V_22 -> V_93 ) ) ;
if ( V_22 -> V_93 == 1 )
return F_69 ( V_22 , V_46 ) ;
return F_71 ( V_22 , V_46 ) ;
}
static int F_72 ( struct V_21 * V_22 , V_106 V_46 ,
V_106 * V_141 )
{
F_17 ( F_57 ( V_22 -> V_93 ) ) ;
if ( V_46 == V_47 ) {
* V_141 = V_22 -> V_109 . V_124 ;
} else if ( V_22 -> V_93 == 1 ) {
T_5 V_132 ;
V_132 = F_68 ( V_22 , V_46 ) ;
if ( V_132 == V_139 )
return - V_34 ;
* V_141 = V_22 -> V_109 . V_114 [ V_132 ] ;
} else {
V_106 V_96 = 0 ;
int V_39 ;
V_39 = F_73 ( V_22 , V_46 , NULL , & V_96 ) ;
if ( V_39 )
return V_39 ;
* V_141 = V_96 ;
}
return 0 ;
}
static int F_74 ( struct V_21 * V_22 , V_106 V_46 ,
V_106 * V_142 )
{
F_17 ( F_57 ( V_22 -> V_93 ) ) ;
if ( V_46 == V_47 ) {
* V_142 = V_22 -> V_109 . V_130 ;
} else if ( V_22 -> V_93 == 1 ) {
* V_142 = 0 ;
} else {
V_106 V_130 = 0 ;
int V_39 ;
V_39 = F_75 ( V_22 , V_46 , & V_130 ) ;
if ( V_39 )
return V_39 ;
* V_142 = V_130 ;
}
return 0 ;
}
static int F_76 ( struct V_21 * V_22 )
{
V_106 V_46 = V_22 -> V_45 -> V_46 ;
V_106 V_96 = 0 ;
V_106 V_130 = 0 ;
int V_39 ;
V_39 = F_72 ( V_22 , V_46 , & V_96 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_74 ( V_22 , V_46 , & V_130 ) ;
if ( V_39 )
return V_39 ;
V_22 -> V_27 . V_96 = V_96 ;
V_22 -> V_27 . V_130 = V_130 ;
return 0 ;
}
static void F_77 ( struct V_21 * V_22 )
{
V_22 -> V_27 . V_96 = 0 ;
V_22 -> V_27 . V_130 = 0 ;
}
static void F_78 ( const char * V_143 )
{
F_79 ( V_144 , ( void * ) V_143 ) ;
}
static const char * F_80 ( struct V_21 * V_22 , V_106 V_145 )
{
char * V_143 ;
V_106 V_146 ;
int V_39 ;
char * V_147 ;
V_143 = F_81 ( V_144 , V_148 ) ;
if ( ! V_143 )
return NULL ;
V_146 = V_145 >> V_22 -> V_109 . V_125 ;
V_147 = L_14 ;
if ( V_22 -> V_93 == 2 )
V_147 = L_15 ;
V_39 = snprintf ( V_143 , V_149 + 1 , V_147 ,
V_22 -> V_109 . V_111 , V_146 ) ;
if ( V_39 < 0 || V_39 > V_149 ) {
F_47 ( L_16 ,
V_146 , V_39 ) ;
F_78 ( V_143 ) ;
V_143 = NULL ;
}
return V_143 ;
}
static V_106 F_82 ( struct V_21 * V_22 , V_106 V_145 )
{
V_106 V_150 = ( V_106 ) 1 << V_22 -> V_109 . V_125 ;
return V_145 & ( V_150 - 1 ) ;
}
static V_106 F_83 ( struct V_21 * V_22 ,
V_106 V_145 , V_106 V_151 )
{
V_106 V_150 = ( V_106 ) 1 << V_22 -> V_109 . V_125 ;
V_145 &= V_150 - 1 ;
F_17 ( V_151 <= V_152 - V_145 ) ;
if ( V_145 + V_151 > V_150 )
V_151 = V_150 - V_145 ;
return V_151 ;
}
static V_106 F_84 ( struct V_108 * V_109 )
{
return 1 << V_109 -> V_125 ;
}
static void F_85 ( struct V_153 * V_154 )
{
struct V_153 * V_155 ;
while ( V_154 ) {
V_155 = V_154 ;
V_154 = V_154 -> V_156 ;
F_86 ( V_155 ) ;
}
}
static void F_87 ( struct V_153 * V_154 , int V_157 )
{
struct V_158 V_159 ;
struct V_160 V_161 ;
unsigned long V_32 ;
void * V_162 ;
int V_163 = 0 ;
while ( V_154 ) {
F_88 (bv, chain, iter) {
if ( V_163 + V_159 . V_164 > V_157 ) {
int V_165 = F_89 ( V_157 - V_163 , 0 ) ;
V_162 = F_90 ( & V_159 , & V_32 ) ;
memset ( V_162 + V_165 , 0 ,
V_159 . V_164 - V_165 ) ;
F_91 ( V_159 . V_166 ) ;
F_92 ( V_162 , & V_32 ) ;
}
V_163 += V_159 . V_164 ;
}
V_154 = V_154 -> V_156 ;
}
}
static void F_93 ( struct V_167 * * V_168 , V_106 V_145 , V_106 V_169 )
{
struct V_167 * * V_167 = & V_168 [ V_145 >> V_170 ] ;
F_17 ( V_169 > V_145 ) ;
F_17 ( V_169 - V_145 <= ( V_106 ) V_103 ) ;
while ( V_145 < V_169 ) {
T_6 V_171 ;
T_6 V_151 ;
unsigned long V_32 ;
void * V_172 ;
V_171 = V_145 & ~ V_173 ;
V_151 = F_94 ( T_6 , V_174 - V_171 , V_169 - V_145 ) ;
F_95 ( V_32 ) ;
V_172 = F_96 ( * V_167 ) ;
memset ( V_172 + V_171 , 0 , V_151 ) ;
F_91 ( * V_167 ) ;
F_97 ( V_172 ) ;
F_98 ( V_32 ) ;
V_145 += V_151 ;
V_167 ++ ;
}
}
static struct V_153 * F_99 ( struct V_153 * V_175 ,
unsigned int V_145 ,
unsigned int V_116 ,
T_7 V_176 )
{
struct V_153 * V_153 ;
V_153 = F_100 ( V_175 , V_176 ) ;
if ( ! V_153 )
return NULL ;
F_101 ( V_153 , V_145 ) ;
V_153 -> V_177 . V_178 = V_116 ;
return V_153 ;
}
static struct V_153 * F_102 ( struct V_153 * * V_175 ,
unsigned int * V_145 ,
unsigned int V_116 ,
T_7 V_176 )
{
struct V_153 * V_179 = * V_175 ;
unsigned int V_180 = * V_145 ;
struct V_153 * V_154 = NULL ;
struct V_153 * * V_169 ;
if ( ! V_179 || V_180 >= V_179 -> V_177 . V_178 || ! V_116 )
return NULL ;
V_169 = & V_154 ;
while ( V_116 ) {
unsigned int V_178 ;
struct V_153 * V_153 ;
if ( ! V_179 ) {
F_103 ( NULL , L_17 , V_116 ) ;
goto V_117;
}
V_178 = F_94 (unsigned int, bi->bi_iter.bi_size - off, len) ;
V_153 = F_99 ( V_179 , V_180 , V_178 , V_176 ) ;
if ( ! V_153 )
goto V_117;
* V_169 = V_153 ;
V_169 = & V_153 -> V_156 ;
V_180 += V_178 ;
if ( V_180 == V_179 -> V_177 . V_178 ) {
V_179 = V_179 -> V_156 ;
V_180 = 0 ;
}
V_116 -= V_178 ;
}
* V_175 = V_179 ;
* V_145 = V_180 ;
return V_154 ;
V_117:
F_85 ( V_154 ) ;
return NULL ;
}
static void F_104 ( struct V_181 * V_182 )
{
if ( F_105 ( V_183 , & V_182 -> V_32 ) ) {
struct V_21 * V_22 ;
V_22 = V_182 -> V_184 -> V_22 ;
F_103 ( V_22 , L_18 ,
V_182 ) ;
}
}
static bool F_106 ( struct V_181 * V_182 )
{
F_107 () ;
return F_13 ( V_183 , & V_182 -> V_32 ) != 0 ;
}
static void F_108 ( struct V_181 * V_182 )
{
if ( F_105 ( V_185 , & V_182 -> V_32 ) ) {
struct V_21 * V_22 = NULL ;
if ( F_106 ( V_182 ) )
V_22 = V_182 -> V_184 -> V_22 ;
F_103 ( V_22 , L_19 ,
V_182 ) ;
}
}
static bool F_109 ( struct V_181 * V_182 )
{
F_107 () ;
return F_13 ( V_185 , & V_182 -> V_32 ) != 0 ;
}
static void F_110 ( struct V_181 * V_182 ,
bool V_186 )
{
if ( V_186 )
F_111 ( V_187 , & V_182 -> V_32 ) ;
F_111 ( V_188 , & V_182 -> V_32 ) ;
F_107 () ;
}
static bool F_112 ( struct V_181 * V_182 )
{
F_107 () ;
return F_13 ( V_188 , & V_182 -> V_32 ) != 0 ;
}
static bool F_113 ( struct V_181 * V_182 )
{
F_107 () ;
return F_13 ( V_187 , & V_182 -> V_32 ) != 0 ;
}
static bool F_114 ( struct V_181 * V_182 )
{
struct V_21 * V_22 = V_182 -> V_184 -> V_22 ;
return V_182 -> V_189 <
F_115 ( V_22 -> V_190 , F_84 ( & V_22 -> V_109 ) ) ;
}
static void F_116 ( struct V_181 * V_182 )
{
F_25 ( L_20 , V_58 , V_182 ,
F_117 ( & V_182 -> V_61 . V_191 ) ) ;
F_40 ( & V_182 -> V_61 ) ;
}
static void F_118 ( struct V_181 * V_182 )
{
F_17 ( V_182 != NULL ) ;
F_25 ( L_20 , V_58 , V_182 ,
F_117 ( & V_182 -> V_61 . V_191 ) ) ;
F_56 ( & V_182 -> V_61 , V_192 ) ;
}
static void F_119 ( struct V_193 * V_184 )
{
F_25 ( L_21 , V_58 , V_184 ,
F_117 ( & V_184 -> V_61 . V_191 ) ) ;
F_40 ( & V_184 -> V_61 ) ;
}
static void F_120 ( struct V_193 * V_184 )
{
F_17 ( V_184 != NULL ) ;
F_25 ( L_21 , V_58 , V_184 ,
F_117 ( & V_184 -> V_61 . V_191 ) ) ;
if ( F_121 ( V_184 ) )
F_56 ( & V_184 -> V_61 , V_194 ) ;
else
F_56 ( & V_184 -> V_61 , V_195 ) ;
}
static inline void F_122 ( struct V_193 * V_184 ,
struct V_181 * V_182 )
{
F_17 ( V_182 -> V_184 == NULL ) ;
V_182 -> V_184 = V_184 ;
V_182 -> V_132 = V_184 -> V_196 ;
F_17 ( ! F_106 ( V_182 ) ) ;
F_104 ( V_182 ) ;
F_17 ( V_182 -> V_132 != V_197 ) ;
V_184 -> V_196 ++ ;
F_33 ( & V_182 -> V_198 , & V_184 -> V_199 ) ;
F_25 ( L_22 , V_58 , V_184 , V_182 ,
V_182 -> V_132 ) ;
}
static inline void F_123 ( struct V_193 * V_184 ,
struct V_181 * V_182 )
{
F_17 ( V_182 -> V_132 != V_197 ) ;
F_25 ( L_22 , V_58 , V_184 , V_182 ,
V_182 -> V_132 ) ;
F_54 ( & V_182 -> V_198 ) ;
F_17 ( V_184 -> V_196 > 0 ) ;
V_184 -> V_196 -- ;
F_17 ( V_182 -> V_132 == V_184 -> V_196 ) ;
V_182 -> V_132 = V_197 ;
F_17 ( F_106 ( V_182 ) ) ;
F_17 ( V_182 -> V_184 == V_184 ) ;
V_182 -> V_184 = NULL ;
V_182 -> V_200 = NULL ;
F_118 ( V_182 ) ;
}
static bool F_124 ( enum V_201 type )
{
switch ( type ) {
case V_202 :
case V_203 :
case V_204 :
return true ;
default:
return false ;
}
}
static int F_125 ( struct V_205 * V_206 ,
struct V_181 * V_182 )
{
F_25 ( L_23 , V_58 , V_182 ) ;
return F_126 ( V_206 , V_182 -> V_207 , false ) ;
}
static void F_127 ( struct V_181 * V_182 )
{
F_25 ( L_23 , V_58 , V_182 ) ;
F_128 ( V_182 -> V_207 ) ;
}
static int F_129 ( struct V_181 * V_182 )
{
int V_39 ;
F_25 ( L_23 , V_58 , V_182 ) ;
V_39 = F_130 ( & V_182 -> V_208 ) ;
if ( V_39 < 0 ) {
F_25 ( L_24 , V_58 , V_182 ) ;
F_127 ( V_182 ) ;
return V_39 ;
}
F_25 ( L_25 , V_58 , V_182 ) ;
return 0 ;
}
static void F_131 ( struct V_193 * V_184 )
{
F_25 ( L_26 , V_58 , V_184 ) ;
if ( ! V_184 -> V_209 ) {
struct V_181 * V_182 ;
V_106 V_210 = 0 ;
F_132 (img_request, obj_request)
V_210 += V_182 -> V_210 ;
V_184 -> V_210 = V_210 ;
}
if ( V_184 -> V_200 )
V_184 -> V_200 ( V_184 ) ;
else
F_120 ( V_184 ) ;
}
static void F_133 ( struct V_193 * V_184 )
{
F_111 ( V_211 , & V_184 -> V_32 ) ;
F_107 () ;
}
static bool F_134 ( struct V_193 * V_184 )
{
F_107 () ;
return F_13 ( V_211 , & V_184 -> V_32 ) != 0 ;
}
static void F_135 ( struct V_193 * V_184 )
{
F_111 ( V_212 , & V_184 -> V_32 ) ;
F_107 () ;
}
static bool F_136 ( struct V_193 * V_184 )
{
F_107 () ;
return F_13 ( V_212 , & V_184 -> V_32 ) != 0 ;
}
static void F_137 ( struct V_193 * V_184 )
{
F_111 ( V_213 , & V_184 -> V_32 ) ;
F_107 () ;
}
static void F_138 ( struct V_193 * V_184 )
{
F_139 ( V_213 , & V_184 -> V_32 ) ;
F_107 () ;
}
static bool F_121 ( struct V_193 * V_184 )
{
F_107 () ;
return F_13 ( V_213 , & V_184 -> V_32 ) != 0 ;
}
static void F_140 ( struct V_193 * V_184 )
{
F_111 ( V_214 , & V_184 -> V_32 ) ;
F_107 () ;
}
static void F_141 ( struct V_193 * V_184 )
{
F_139 ( V_214 , & V_184 -> V_32 ) ;
F_107 () ;
}
static bool F_142 ( struct V_193 * V_184 )
{
F_107 () ;
return F_13 ( V_214 , & V_184 -> V_32 ) != 0 ;
}
static enum V_86
F_143 ( struct V_193 * V_184 )
{
if ( F_134 ( V_184 ) )
return V_89 ;
else if ( F_136 ( V_184 ) )
return V_90 ;
else
return V_88 ;
}
static void
F_144 ( struct V_181 * V_182 )
{
V_106 V_210 = V_182 -> V_210 ;
V_106 V_151 = V_182 -> V_151 ;
F_25 ( L_27 , V_58 ,
V_182 , V_182 -> V_184 , V_182 -> V_209 ,
V_210 , V_151 ) ;
F_17 ( V_182 -> type != V_202 ) ;
if ( V_182 -> V_209 == - V_34 ) {
if ( V_182 -> type == V_203 )
F_87 ( V_182 -> V_215 , 0 ) ;
else
F_93 ( V_182 -> V_168 , 0 , V_151 ) ;
V_182 -> V_209 = 0 ;
} else if ( V_210 < V_151 && ! V_182 -> V_209 ) {
if ( V_182 -> type == V_203 )
F_87 ( V_182 -> V_215 , V_210 ) ;
else
F_93 ( V_182 -> V_168 , V_210 , V_151 ) ;
}
V_182 -> V_210 = V_151 ;
F_108 ( V_182 ) ;
}
static void F_145 ( struct V_181 * V_182 )
{
F_25 ( L_28 , V_58 , V_182 ,
V_182 -> V_200 ) ;
if ( V_182 -> V_200 )
V_182 -> V_200 ( V_182 ) ;
else
F_146 ( & V_182 -> V_208 ) ;
}
static void F_147 ( struct V_181 * V_182 )
{
F_25 ( L_29 , V_58 , V_182 ) ;
F_108 ( V_182 ) ;
}
static void F_148 ( struct V_181 * V_182 )
{
struct V_193 * V_184 = NULL ;
struct V_21 * V_22 = NULL ;
bool V_216 = false ;
if ( F_106 ( V_182 ) ) {
V_184 = V_182 -> V_184 ;
V_216 = V_184 && F_142 ( V_184 ) ;
V_22 = V_184 -> V_22 ;
}
F_25 ( L_27 , V_58 ,
V_182 , V_184 , V_182 -> V_209 ,
V_182 -> V_210 , V_182 -> V_151 ) ;
if ( V_216 && V_182 -> V_209 == - V_34 &&
V_182 -> V_189 < V_22 -> V_190 )
F_149 ( V_182 ) ;
else if ( V_184 )
F_144 ( V_182 ) ;
else
F_108 ( V_182 ) ;
}
static void F_150 ( struct V_181 * V_182 )
{
F_25 ( L_30 , V_58 , V_182 ,
V_182 -> V_209 , V_182 -> V_151 ) ;
V_182 -> V_210 = V_182 -> V_151 ;
F_108 ( V_182 ) ;
}
static void F_151 ( struct V_181 * V_182 )
{
F_25 ( L_30 , V_58 , V_182 ,
V_182 -> V_209 , V_182 -> V_151 ) ;
V_182 -> V_210 = V_182 -> V_151 ;
if ( V_182 -> V_209 == - V_34 )
V_182 -> V_209 = 0 ;
F_108 ( V_182 ) ;
}
static void F_152 ( struct V_181 * V_182 )
{
F_25 ( L_29 , V_58 , V_182 ) ;
F_108 ( V_182 ) ;
}
static void F_153 ( struct V_217 * V_207 ,
struct V_218 * V_219 )
{
struct V_181 * V_182 = V_207 -> V_220 ;
T_8 V_221 ;
F_25 ( L_31 , V_58 , V_207 , V_219 ) ;
F_17 ( V_207 == V_182 -> V_207 ) ;
if ( F_106 ( V_182 ) ) {
F_17 ( V_182 -> V_184 ) ;
F_17 ( V_182 -> V_132 != V_197 ) ;
} else {
F_17 ( V_182 -> V_132 == V_197 ) ;
}
if ( V_207 -> V_222 < 0 )
V_182 -> V_209 = V_207 -> V_222 ;
F_17 ( V_207 -> V_223 <= V_224 ) ;
V_182 -> V_210 = V_207 -> V_225 [ 0 ] ;
F_17 ( V_182 -> V_210 < ( V_106 ) V_226 ) ;
V_221 = V_207 -> V_227 [ 0 ] . V_228 ;
switch ( V_221 ) {
case V_229 :
F_148 ( V_182 ) ;
break;
case V_230 :
F_17 ( V_207 -> V_227 [ 1 ] . V_228 == V_231 ) ;
case V_231 :
F_150 ( V_182 ) ;
break;
case V_232 :
F_152 ( V_182 ) ;
break;
case V_233 :
case V_234 :
case V_235 :
F_151 ( V_182 ) ;
break;
case V_236 :
case V_237 :
case V_238 :
F_147 ( V_182 ) ;
break;
default:
F_103 ( NULL , L_32 ,
V_182 -> V_239 , ( unsigned short ) V_221 ) ;
break;
}
if ( F_109 ( V_182 ) )
F_145 ( V_182 ) ;
}
static void F_154 ( struct V_181 * V_182 )
{
struct V_193 * V_184 = V_182 -> V_184 ;
struct V_217 * V_207 = V_182 -> V_207 ;
V_106 V_46 ;
F_17 ( V_207 != NULL ) ;
V_46 = V_184 ? V_184 -> V_46 : V_47 ;
F_155 ( V_207 , V_182 -> V_145 ,
NULL , V_46 , NULL ) ;
}
static void F_156 ( struct V_181 * V_182 )
{
struct V_193 * V_184 = V_182 -> V_184 ;
struct V_217 * V_207 = V_182 -> V_207 ;
struct V_104 * V_112 ;
struct V_240 V_241 = V_242 ;
F_17 ( V_207 != NULL ) ;
V_112 = V_184 ? V_184 -> V_112 : NULL ;
F_155 ( V_207 , V_182 -> V_145 ,
V_112 , V_47 , & V_241 ) ;
}
static struct V_217 * F_157 (
struct V_21 * V_22 ,
enum V_86 V_87 ,
unsigned int V_243 ,
struct V_181 * V_182 )
{
struct V_104 * V_112 = NULL ;
struct V_205 * V_206 ;
struct V_217 * V_207 ;
if ( F_106 ( V_182 ) &&
( V_87 == V_90 || V_87 == V_89 ) ) {
struct V_193 * V_184 = V_182 -> V_184 ;
if ( V_87 == V_89 ) {
F_17 ( F_134 ( V_184 ) ) ;
} else {
F_17 ( F_136 ( V_184 ) ) ;
}
V_112 = V_184 -> V_112 ;
}
F_17 ( V_243 == 1 || ( ( V_87 == V_89 ) && V_243 == 2 ) ) ;
V_206 = & V_22 -> V_53 -> V_63 -> V_206 ;
V_207 = F_158 ( V_206 , V_112 , V_243 , false ,
V_244 ) ;
if ( ! V_207 )
return NULL ;
if ( V_87 == V_89 || V_87 == V_90 )
V_207 -> V_245 = V_246 | V_247 ;
else
V_207 -> V_245 = V_248 ;
V_207 -> V_249 = F_153 ;
V_207 -> V_220 = V_182 ;
V_207 -> V_250 . V_251 = F_159 ( V_22 -> V_252 ) ;
F_160 ( & V_207 -> V_253 , V_182 -> V_239 ) ;
return V_207 ;
}
static struct V_217 *
F_161 ( struct V_181 * V_182 )
{
struct V_193 * V_184 ;
struct V_104 * V_112 ;
struct V_21 * V_22 ;
struct V_205 * V_206 ;
struct V_217 * V_207 ;
int V_254 = 3 ;
F_17 ( F_106 ( V_182 ) ) ;
V_184 = V_182 -> V_184 ;
F_17 ( V_184 ) ;
F_17 ( F_134 ( V_184 ) ||
F_136 ( V_184 ) ) ;
if ( F_136 ( V_184 ) )
V_254 = 2 ;
V_112 = V_184 -> V_112 ;
V_22 = V_184 -> V_22 ;
V_206 = & V_22 -> V_53 -> V_63 -> V_206 ;
V_207 = F_158 ( V_206 , V_112 , V_254 ,
false , V_244 ) ;
if ( ! V_207 )
return NULL ;
V_207 -> V_245 = V_246 | V_247 ;
V_207 -> V_249 = F_153 ;
V_207 -> V_220 = V_182 ;
V_207 -> V_250 . V_251 = F_159 ( V_22 -> V_252 ) ;
F_160 ( & V_207 -> V_253 , V_182 -> V_239 ) ;
return V_207 ;
}
static void F_162 ( struct V_217 * V_207 )
{
F_163 ( V_207 ) ;
}
static struct V_181 * F_164 ( const char * V_239 ,
V_106 V_145 , V_106 V_151 ,
enum V_201 type )
{
struct V_181 * V_182 ;
T_6 V_96 ;
char * V_143 ;
F_17 ( F_124 ( type ) ) ;
V_96 = strlen ( V_239 ) + 1 ;
V_143 = F_26 ( V_96 , V_59 ) ;
if ( ! V_143 )
return NULL ;
V_182 = F_165 ( V_255 , V_59 ) ;
if ( ! V_182 ) {
F_36 ( V_143 ) ;
return NULL ;
}
V_182 -> V_239 = memcpy ( V_143 , V_239 , V_96 ) ;
V_182 -> V_145 = V_145 ;
V_182 -> V_151 = V_151 ;
V_182 -> V_32 = 0 ;
V_182 -> V_132 = V_197 ;
V_182 -> type = type ;
F_28 ( & V_182 -> V_198 ) ;
F_166 ( & V_182 -> V_208 ) ;
F_27 ( & V_182 -> V_61 ) ;
F_25 ( L_33 , V_58 , V_239 ,
V_145 , V_151 , ( int ) type , V_182 ) ;
return V_182 ;
}
static void V_192 ( struct V_61 * V_61 )
{
struct V_181 * V_182 ;
V_182 = F_53 ( V_61 , struct V_181 , V_61 ) ;
F_25 ( L_29 , V_58 , V_182 ) ;
F_17 ( V_182 -> V_184 == NULL ) ;
F_17 ( V_182 -> V_132 == V_197 ) ;
if ( V_182 -> V_207 )
F_162 ( V_182 -> V_207 ) ;
F_17 ( F_124 ( V_182 -> type ) ) ;
switch ( V_182 -> type ) {
case V_202 :
break;
case V_203 :
if ( V_182 -> V_215 )
F_85 ( V_182 -> V_215 ) ;
break;
case V_204 :
if ( V_182 -> V_168 )
F_167 ( V_182 -> V_168 ,
V_182 -> V_256 ) ;
break;
}
F_36 ( V_182 -> V_239 ) ;
V_182 -> V_239 = NULL ;
F_79 ( V_255 , V_182 ) ;
}
static void F_168 ( struct V_21 * V_22 )
{
F_169 ( V_22 ) ;
F_170 ( V_22 -> V_257 ) ;
V_22 -> V_257 = NULL ;
V_22 -> V_190 = 0 ;
}
static void F_171 ( struct V_21 * V_22 )
{
int V_2 ;
if ( ! V_22 -> V_257 )
return;
V_2 = F_4 ( & V_22 -> V_258 ) ;
if ( V_2 > 0 )
return;
if ( ! V_2 )
F_168 ( V_22 ) ;
else
F_103 ( V_22 , L_34 ) ;
}
static bool F_172 ( struct V_21 * V_22 )
{
int V_2 = 0 ;
if ( ! V_22 -> V_257 )
return false ;
F_173 ( & V_22 -> V_259 ) ;
if ( V_22 -> V_190 )
V_2 = F_1 ( & V_22 -> V_258 ) ;
F_174 ( & V_22 -> V_259 ) ;
if ( V_2 < 0 )
F_103 ( V_22 , L_35 ) ;
return V_2 > 0 ;
}
static struct V_193 * F_175 (
struct V_21 * V_22 ,
V_106 V_145 , V_106 V_151 ,
enum V_86 V_87 ,
struct V_104 * V_112 )
{
struct V_193 * V_184 ;
V_184 = F_81 ( V_260 , V_148 ) ;
if ( ! V_184 )
return NULL ;
V_184 -> V_261 = NULL ;
V_184 -> V_22 = V_22 ;
V_184 -> V_145 = V_145 ;
V_184 -> V_151 = V_151 ;
V_184 -> V_32 = 0 ;
if ( V_87 == V_90 ) {
F_135 ( V_184 ) ;
V_184 -> V_112 = V_112 ;
} else if ( V_87 == V_89 ) {
F_133 ( V_184 ) ;
V_184 -> V_112 = V_112 ;
} else {
V_184 -> V_46 = V_22 -> V_45 -> V_46 ;
}
if ( F_172 ( V_22 ) )
F_140 ( V_184 ) ;
F_176 ( & V_184 -> V_262 ) ;
V_184 -> V_263 = 0 ;
V_184 -> V_200 = NULL ;
V_184 -> V_209 = 0 ;
V_184 -> V_196 = 0 ;
F_28 ( & V_184 -> V_199 ) ;
F_27 ( & V_184 -> V_61 ) ;
F_25 ( L_36 , V_58 , V_22 ,
F_48 ( V_87 ) , V_145 , V_151 , V_184 ) ;
return V_184 ;
}
static void V_195 ( struct V_61 * V_61 )
{
struct V_193 * V_184 ;
struct V_181 * V_182 ;
struct V_181 * V_264 ;
V_184 = F_53 ( V_61 , struct V_193 , V_61 ) ;
F_25 ( L_26 , V_58 , V_184 ) ;
F_177 (img_request, obj_request, next_obj_request)
F_123 ( V_184 , V_182 ) ;
F_17 ( V_184 -> V_196 == 0 ) ;
if ( F_142 ( V_184 ) ) {
F_141 ( V_184 ) ;
F_171 ( V_184 -> V_22 ) ;
}
if ( F_134 ( V_184 ) ||
F_136 ( V_184 ) )
F_64 ( V_184 -> V_112 ) ;
F_79 ( V_260 , V_184 ) ;
}
static struct V_193 * F_178 (
struct V_181 * V_182 ,
V_106 V_189 , V_106 V_151 )
{
struct V_193 * V_265 ;
struct V_21 * V_22 ;
F_17 ( V_182 -> V_184 ) ;
V_22 = V_182 -> V_184 -> V_22 ;
V_265 = F_175 ( V_22 -> V_266 , V_189 ,
V_151 , V_88 , NULL ) ;
if ( ! V_265 )
return NULL ;
F_137 ( V_265 ) ;
F_116 ( V_182 ) ;
V_265 -> V_182 = V_182 ;
return V_265 ;
}
static void V_194 ( struct V_61 * V_61 )
{
struct V_193 * V_265 ;
struct V_181 * V_267 ;
V_265 = F_53 ( V_61 , struct V_193 , V_61 ) ;
V_267 = V_265 -> V_182 ;
V_265 -> V_182 = NULL ;
F_118 ( V_267 ) ;
F_138 ( V_265 ) ;
V_195 ( V_61 ) ;
}
static bool F_179 ( struct V_181 * V_182 )
{
struct V_193 * V_184 ;
unsigned int V_210 ;
int V_209 ;
bool V_268 ;
F_17 ( F_106 ( V_182 ) ) ;
V_184 = V_182 -> V_184 ;
F_17 ( V_182 -> V_210 <= ( V_106 ) V_226 ) ;
V_210 = ( unsigned int ) V_182 -> V_210 ;
V_209 = V_182 -> V_209 ;
if ( V_209 ) {
struct V_21 * V_22 = V_184 -> V_22 ;
enum V_86 V_87 ;
if ( F_136 ( V_184 ) )
V_87 = V_90 ;
else if ( F_134 ( V_184 ) )
V_87 = V_89 ;
else
V_87 = V_88 ;
F_103 ( V_22 , L_37 ,
F_48 ( V_87 ) , V_182 -> V_151 ,
V_182 -> V_189 , V_182 -> V_145 ) ;
F_103 ( V_22 , L_38 ,
V_209 , V_210 ) ;
if ( ! V_184 -> V_209 )
V_184 -> V_209 = V_209 ;
}
if ( V_182 -> type == V_204 ) {
V_182 -> V_168 = NULL ;
V_182 -> V_256 = 0 ;
}
if ( F_121 ( V_184 ) ) {
F_17 ( V_184 -> V_182 != NULL ) ;
V_268 = V_182 -> V_132 < V_184 -> V_196 - 1 ;
} else {
F_17 ( V_184 -> V_261 != NULL ) ;
V_268 = F_180 ( V_184 -> V_261 , V_209 , V_210 ) ;
}
return V_268 ;
}
static void F_181 ( struct V_181 * V_182 )
{
struct V_193 * V_184 ;
T_5 V_132 = V_182 -> V_132 ;
bool V_268 = true ;
F_17 ( F_106 ( V_182 ) ) ;
V_184 = V_182 -> V_184 ;
F_25 ( L_39 , V_58 , V_184 , V_182 ) ;
F_17 ( V_184 != NULL ) ;
F_17 ( V_184 -> V_196 > 0 ) ;
F_17 ( V_132 != V_197 ) ;
F_17 ( V_132 < V_184 -> V_196 ) ;
F_12 ( & V_184 -> V_262 ) ;
if ( V_132 != V_184 -> V_263 )
goto V_49;
F_182 (img_request, obj_request) {
F_17 ( V_268 ) ;
F_17 ( V_132 < V_184 -> V_196 ) ;
if ( ! F_109 ( V_182 ) )
break;
V_268 = F_179 ( V_182 ) ;
V_132 ++ ;
}
F_17 ( V_268 ^ ( V_132 == V_184 -> V_196 ) ) ;
V_184 -> V_263 = V_132 ;
V_49:
F_14 ( & V_184 -> V_262 ) ;
F_120 ( V_184 ) ;
if ( ! V_268 )
F_131 ( V_184 ) ;
}
static void F_183 ( struct V_181 * V_182 ,
struct V_217 * V_269 ,
enum V_86 V_87 ,
unsigned int V_243 )
{
struct V_193 * V_184 = V_182 -> V_184 ;
struct V_21 * V_22 = V_184 -> V_22 ;
V_106 V_270 = F_84 ( & V_22 -> V_109 ) ;
V_106 V_145 = V_182 -> V_145 ;
V_106 V_151 = V_182 -> V_151 ;
V_106 V_271 ;
T_8 V_221 ;
if ( V_87 == V_90 ) {
if ( ! V_145 && V_151 == V_270 &&
( ! F_142 ( V_184 ) ||
! F_114 ( V_182 ) ) ) {
V_221 = V_233 ;
} else if ( ( V_145 + V_151 == V_270 ) ) {
V_221 = V_234 ;
} else {
F_173 ( & V_22 -> V_259 ) ;
V_271 = V_22 -> V_109 . V_124 ;
F_174 ( & V_22 -> V_259 ) ;
if ( V_182 -> V_189 + V_151 == V_271 )
V_221 = V_234 ;
else
V_221 = V_235 ;
}
} else if ( V_87 == V_89 ) {
V_221 = V_231 ;
F_184 ( V_269 , V_243 ,
V_270 , V_270 ) ;
V_243 ++ ;
} else {
V_221 = V_229 ;
}
if ( V_221 == V_233 )
F_185 ( V_269 , V_243 , V_221 ) ;
else
F_186 ( V_269 , V_243 , V_221 ,
V_145 , V_151 , 0 , 0 ) ;
if ( V_182 -> type == V_203 )
F_187 ( V_269 , V_243 ,
V_182 -> V_215 , V_151 ) ;
else if ( V_182 -> type == V_204 )
F_188 ( V_269 , V_243 ,
V_182 -> V_168 , V_151 ,
V_145 & ~ V_173 , false , false ) ;
if ( V_87 == V_89 || V_87 == V_90 )
F_156 ( V_182 ) ;
else
F_154 ( V_182 ) ;
}
static int F_189 ( struct V_193 * V_184 ,
enum V_201 type ,
void * V_272 )
{
struct V_21 * V_22 = V_184 -> V_22 ;
struct V_181 * V_182 = NULL ;
struct V_181 * V_264 ;
struct V_153 * V_215 = NULL ;
unsigned int V_273 = 0 ;
struct V_167 * * V_168 = NULL ;
enum V_86 V_87 ;
V_106 V_189 ;
V_106 V_274 ;
F_25 ( L_40 , V_58 , V_184 ,
( int ) type , V_272 ) ;
V_189 = V_184 -> V_145 ;
V_274 = V_184 -> V_151 ;
F_17 ( V_274 > 0 ) ;
V_87 = F_143 ( V_184 ) ;
if ( type == V_203 ) {
V_215 = V_272 ;
F_17 ( V_189 ==
V_215 -> V_177 . V_275 << V_102 ) ;
} else if ( type == V_204 ) {
V_168 = V_272 ;
}
while ( V_274 ) {
struct V_217 * V_207 ;
const char * V_239 ;
V_106 V_145 ;
V_106 V_151 ;
V_239 = F_80 ( V_22 , V_189 ) ;
if ( ! V_239 )
goto V_276;
V_145 = F_82 ( V_22 , V_189 ) ;
V_151 = F_83 ( V_22 , V_189 , V_274 ) ;
V_182 = F_164 ( V_239 ,
V_145 , V_151 , type ) ;
F_78 ( V_239 ) ;
if ( ! V_182 )
goto V_276;
F_122 ( V_184 , V_182 ) ;
if ( type == V_203 ) {
unsigned int V_277 ;
F_17 ( V_151 <= ( V_106 ) V_226 ) ;
V_277 = ( unsigned int ) V_151 ;
V_182 -> V_215 =
F_102 ( & V_215 ,
& V_273 ,
V_277 ,
V_244 ) ;
if ( ! V_182 -> V_215 )
goto V_276;
} else if ( type == V_204 ) {
unsigned int V_256 ;
V_182 -> V_168 = V_168 ;
V_256 = ( T_5 ) F_190 ( V_145 , V_151 ) ;
V_182 -> V_256 = V_256 ;
if ( ( V_145 + V_151 ) & ~ V_173 )
V_256 -- ;
V_168 += V_256 ;
}
V_207 = F_157 ( V_22 , V_87 ,
( V_87 == V_89 ) ? 2 : 1 ,
V_182 ) ;
if ( ! V_207 )
goto V_276;
V_182 -> V_207 = V_207 ;
V_182 -> V_200 = F_181 ;
V_182 -> V_189 = V_189 ;
F_183 ( V_182 , V_207 , V_87 , 0 ) ;
F_119 ( V_184 ) ;
V_189 += V_151 ;
V_274 -= V_151 ;
}
return 0 ;
V_276:
F_177 (img_request, obj_request, next_obj_request)
F_123 ( V_184 , V_182 ) ;
return - V_57 ;
}
static void
F_191 ( struct V_181 * V_182 )
{
struct V_193 * V_184 ;
struct V_21 * V_22 ;
struct V_167 * * V_168 ;
T_5 V_256 ;
F_17 ( V_182 -> type == V_203 ||
V_182 -> type == V_202 ) ;
F_17 ( F_106 ( V_182 ) ) ;
V_184 = V_182 -> V_184 ;
F_17 ( V_184 ) ;
V_22 = V_184 -> V_22 ;
F_17 ( V_22 ) ;
V_168 = V_182 -> V_278 ;
F_17 ( V_168 != NULL ) ;
V_182 -> V_278 = NULL ;
V_256 = V_182 -> V_279 ;
F_17 ( V_256 ) ;
V_182 -> V_279 = 0 ;
F_167 ( V_168 , V_256 ) ;
if ( ! V_182 -> V_209 )
V_182 -> V_210 = V_182 -> V_151 ;
F_181 ( V_182 ) ;
}
static void
F_192 ( struct V_193 * V_184 )
{
struct V_181 * V_267 ;
struct V_217 * V_207 ;
struct V_205 * V_206 ;
struct V_21 * V_22 ;
struct V_167 * * V_168 ;
enum V_86 V_87 ;
T_5 V_256 ;
int V_280 ;
V_106 V_281 ;
F_17 ( F_121 ( V_184 ) ) ;
V_168 = V_184 -> V_278 ;
F_17 ( V_168 != NULL ) ;
V_184 -> V_278 = NULL ;
V_256 = V_184 -> V_279 ;
F_17 ( V_256 ) ;
V_184 -> V_279 = 0 ;
V_267 = V_184 -> V_182 ;
F_17 ( V_267 != NULL ) ;
F_17 ( F_124 ( V_267 -> type ) ) ;
V_280 = V_184 -> V_209 ;
V_281 = V_184 -> V_151 ;
F_17 ( V_281 == V_184 -> V_210 ) ;
F_120 ( V_184 ) ;
F_17 ( V_267 -> V_184 ) ;
V_22 = V_267 -> V_184 -> V_22 ;
F_17 ( V_22 ) ;
if ( ! V_22 -> V_190 ) {
struct V_205 * V_206 ;
F_167 ( V_168 , V_256 ) ;
V_206 = & V_22 -> V_53 -> V_63 -> V_206 ;
V_280 = F_125 ( V_206 , V_267 ) ;
if ( ! V_280 )
return;
}
if ( V_280 )
goto V_117;
V_280 = - V_57 ;
V_207 = F_161 ( V_267 ) ;
if ( ! V_207 )
goto V_117;
F_162 ( V_267 -> V_207 ) ;
V_267 -> V_207 = V_207 ;
V_267 -> V_278 = V_168 ;
V_267 -> V_279 = V_256 ;
F_193 ( V_207 , 0 , V_236 , L_41 , L_42 ) ;
F_194 ( V_207 , 0 , V_168 , V_281 , 0 ,
false , false ) ;
V_87 = F_143 ( V_267 -> V_184 ) ;
F_183 ( V_267 , V_207 , V_87 , 1 ) ;
V_267 -> V_200 = F_191 ;
V_206 = & V_22 -> V_53 -> V_63 -> V_206 ;
V_280 = F_125 ( V_206 , V_267 ) ;
if ( ! V_280 )
return;
V_117:
V_267 -> V_209 = V_280 ;
V_267 -> V_210 = 0 ;
F_108 ( V_267 ) ;
F_145 ( V_267 ) ;
}
static int F_195 ( struct V_181 * V_182 )
{
struct V_193 * V_184 = NULL ;
struct V_193 * V_265 = NULL ;
struct V_21 * V_22 ;
V_106 V_189 ;
V_106 V_151 ;
struct V_167 * * V_168 = NULL ;
T_5 V_256 ;
int V_209 ;
F_17 ( F_106 ( V_182 ) ) ;
F_17 ( F_124 ( V_182 -> type ) ) ;
V_184 = V_182 -> V_184 ;
F_17 ( V_184 != NULL ) ;
V_22 = V_184 -> V_22 ;
F_17 ( V_22 -> V_266 != NULL ) ;
V_189 = V_182 -> V_189 - V_182 -> V_145 ;
V_151 = ( V_106 ) 1 << V_22 -> V_109 . V_125 ;
if ( V_189 + V_151 > V_22 -> V_190 ) {
F_17 ( V_189 < V_22 -> V_190 ) ;
V_151 = V_22 -> V_190 - V_189 ;
}
V_256 = ( T_5 ) F_190 ( 0 , V_151 ) ;
V_168 = F_196 ( V_256 , V_59 ) ;
if ( F_30 ( V_168 ) ) {
V_209 = F_197 ( V_168 ) ;
V_168 = NULL ;
goto V_117;
}
V_209 = - V_57 ;
V_265 = F_178 ( V_182 ,
V_189 , V_151 ) ;
if ( ! V_265 )
goto V_117;
V_209 = F_189 ( V_265 , V_204 , V_168 ) ;
if ( V_209 )
goto V_117;
V_265 -> V_278 = V_168 ;
V_265 -> V_279 = V_256 ;
V_265 -> V_200 = F_192 ;
V_209 = F_198 ( V_265 ) ;
if ( ! V_209 )
return 0 ;
V_265 -> V_278 = NULL ;
V_265 -> V_279 = 0 ;
V_265 -> V_182 = NULL ;
F_118 ( V_182 ) ;
V_117:
if ( V_168 )
F_167 ( V_168 , V_256 ) ;
if ( V_265 )
F_120 ( V_265 ) ;
V_182 -> V_209 = V_209 ;
V_182 -> V_210 = 0 ;
F_108 ( V_182 ) ;
return V_209 ;
}
static void F_199 ( struct V_181 * V_182 )
{
struct V_181 * V_267 ;
struct V_21 * V_22 ;
int V_209 ;
F_17 ( ! F_106 ( V_182 ) ) ;
V_267 = V_182 -> V_182 ;
V_182 -> V_182 = NULL ;
F_118 ( V_267 ) ;
F_17 ( V_267 ) ;
F_17 ( V_267 -> V_184 ) ;
V_209 = V_182 -> V_209 ;
V_182 -> V_209 = 0 ;
F_25 ( L_43 , V_58 ,
V_182 , V_267 , V_209 ,
V_182 -> V_210 , V_182 -> V_151 ) ;
F_118 ( V_182 ) ;
V_22 = V_267 -> V_184 -> V_22 ;
if ( ! V_22 -> V_190 ) {
struct V_205 * V_206 ;
V_206 = & V_22 -> V_53 -> V_63 -> V_206 ;
V_209 = F_125 ( V_206 , V_267 ) ;
if ( ! V_209 )
return;
}
if ( ! V_209 ) {
F_110 ( V_267 , true ) ;
} else if ( V_209 == - V_34 ) {
F_110 ( V_267 , false ) ;
} else if ( V_209 ) {
V_267 -> V_209 = V_209 ;
goto V_49;
}
V_267 -> V_209 = F_200 ( V_267 ) ;
V_49:
if ( V_267 -> V_209 )
F_145 ( V_267 ) ;
}
static int F_201 ( struct V_181 * V_182 )
{
struct V_181 * V_282 ;
struct V_21 * V_22 ;
struct V_205 * V_206 ;
struct V_167 * * V_168 = NULL ;
T_5 V_256 ;
T_6 V_96 ;
int V_39 ;
V_96 = sizeof ( V_105 ) + sizeof ( V_283 ) + sizeof ( V_283 ) ;
V_256 = ( T_5 ) F_190 ( 0 , V_96 ) ;
V_168 = F_196 ( V_256 , V_59 ) ;
if ( F_30 ( V_168 ) )
return F_197 ( V_168 ) ;
V_39 = - V_57 ;
V_282 = F_164 ( V_182 -> V_239 , 0 , 0 ,
V_204 ) ;
if ( ! V_282 )
goto V_49;
F_116 ( V_182 ) ;
V_282 -> V_182 = V_182 ;
V_282 -> V_168 = V_168 ;
V_282 -> V_256 = V_256 ;
F_17 ( V_182 -> V_184 ) ;
V_22 = V_182 -> V_184 -> V_22 ;
V_282 -> V_207 = F_157 ( V_22 , V_88 , 1 ,
V_282 ) ;
if ( ! V_282 -> V_207 )
goto V_49;
V_282 -> V_200 = F_199 ;
F_185 ( V_282 -> V_207 , 0 , V_232 ) ;
F_202 ( V_282 -> V_207 , 0 , V_168 , V_96 , 0 ,
false , false ) ;
F_154 ( V_282 ) ;
V_206 = & V_22 -> V_53 -> V_63 -> V_206 ;
V_39 = F_125 ( V_206 , V_282 ) ;
V_49:
if ( V_39 )
F_118 ( V_182 ) ;
return V_39 ;
}
static bool F_203 ( struct V_181 * V_182 )
{
struct V_193 * V_184 ;
struct V_21 * V_22 ;
F_17 ( F_106 ( V_182 ) ) ;
V_184 = V_182 -> V_184 ;
F_17 ( V_184 ) ;
V_22 = V_184 -> V_22 ;
if ( ! F_134 ( V_184 ) &&
! F_136 ( V_184 ) )
return true ;
if ( ! F_142 ( V_184 ) )
return true ;
if ( ! F_114 ( V_182 ) )
return true ;
if ( ! V_182 -> V_145 &&
V_182 -> V_151 == F_84 ( & V_22 -> V_109 ) )
return true ;
if ( F_112 ( V_182 ) &&
F_113 ( V_182 ) )
return true ;
return false ;
}
static int F_200 ( struct V_181 * V_182 )
{
if ( F_203 ( V_182 ) ) {
struct V_21 * V_22 ;
struct V_205 * V_206 ;
V_22 = V_182 -> V_184 -> V_22 ;
V_206 = & V_22 -> V_53 -> V_63 -> V_206 ;
return F_125 ( V_206 , V_182 ) ;
}
if ( F_112 ( V_182 ) )
return F_195 ( V_182 ) ;
return F_201 ( V_182 ) ;
}
static int F_198 ( struct V_193 * V_184 )
{
struct V_181 * V_182 ;
struct V_181 * V_264 ;
F_25 ( L_26 , V_58 , V_184 ) ;
F_177 (img_request, obj_request, next_obj_request) {
int V_39 ;
V_39 = F_200 ( V_182 ) ;
if ( V_39 )
return V_39 ;
}
return 0 ;
}
static void F_204 ( struct V_193 * V_184 )
{
struct V_181 * V_182 ;
struct V_21 * V_22 ;
V_106 V_284 ;
V_106 V_285 ;
int V_280 ;
F_17 ( F_121 ( V_184 ) ) ;
V_182 = V_184 -> V_182 ;
V_285 = V_184 -> V_210 ;
V_280 = V_184 -> V_209 ;
F_120 ( V_184 ) ;
F_17 ( V_182 ) ;
F_17 ( V_182 -> V_184 ) ;
V_22 = V_182 -> V_184 -> V_22 ;
if ( ! V_22 -> V_190 ) {
struct V_205 * V_206 ;
V_206 = & V_22 -> V_53 -> V_63 -> V_206 ;
V_280 = F_125 ( V_206 , V_182 ) ;
if ( ! V_280 )
return;
}
V_182 -> V_209 = V_280 ;
if ( V_182 -> V_209 )
goto V_49;
F_17 ( V_182 -> V_189 < V_152 - V_182 -> V_151 ) ;
V_284 = V_182 -> V_189 + V_182 -> V_151 ;
if ( V_284 > V_22 -> V_190 ) {
V_106 V_210 = 0 ;
if ( V_182 -> V_189 < V_22 -> V_190 )
V_210 = V_22 -> V_190 -
V_182 -> V_189 ;
V_182 -> V_210 = F_205 ( V_285 , V_210 ) ;
} else {
V_182 -> V_210 = V_285 ;
}
V_49:
F_144 ( V_182 ) ;
F_145 ( V_182 ) ;
}
static void F_149 ( struct V_181 * V_182 )
{
struct V_193 * V_184 ;
int V_209 ;
F_17 ( F_106 ( V_182 ) ) ;
F_17 ( V_182 -> V_184 != NULL ) ;
F_17 ( V_182 -> V_209 == ( V_286 ) - V_34 ) ;
F_17 ( F_124 ( V_182 -> type ) ) ;
V_184 = F_178 ( V_182 ,
V_182 -> V_189 ,
V_182 -> V_151 ) ;
V_209 = - V_57 ;
if ( ! V_184 )
goto V_117;
if ( V_182 -> type == V_203 )
V_209 = F_189 ( V_184 , V_203 ,
V_182 -> V_215 ) ;
else
V_209 = F_189 ( V_184 , V_204 ,
V_182 -> V_168 ) ;
if ( V_209 )
goto V_117;
V_184 -> V_200 = F_204 ;
V_209 = F_198 ( V_184 ) ;
if ( V_209 )
goto V_117;
return;
V_117:
if ( V_184 )
F_120 ( V_184 ) ;
V_182 -> V_209 = V_209 ;
V_182 -> V_210 = 0 ;
F_108 ( V_182 ) ;
}
static int F_206 ( struct V_21 * V_22 , V_106 V_287 )
{
struct V_181 * V_182 ;
struct V_205 * V_206 = & V_22 -> V_53 -> V_63 -> V_206 ;
int V_39 ;
V_182 = F_164 ( V_22 -> V_288 , 0 , 0 ,
V_202 ) ;
if ( ! V_182 )
return - V_57 ;
V_39 = - V_57 ;
V_182 -> V_207 = F_157 ( V_22 , V_88 , 1 ,
V_182 ) ;
if ( ! V_182 -> V_207 )
goto V_49;
F_207 ( V_182 -> V_207 , 0 , V_237 ,
V_287 , 0 , 0 ) ;
F_154 ( V_182 ) ;
V_39 = F_125 ( V_206 , V_182 ) ;
if ( V_39 )
goto V_49;
V_39 = F_129 ( V_182 ) ;
V_49:
F_118 ( V_182 ) ;
return V_39 ;
}
static void F_208 ( V_106 V_289 , V_106 V_287 , T_9 V_221 , void * V_290 )
{
struct V_21 * V_22 = (struct V_21 * ) V_290 ;
int V_39 ;
if ( ! V_22 )
return;
F_25 ( L_44 , V_58 ,
V_22 -> V_288 , ( unsigned long long ) V_287 ,
( unsigned int ) V_221 ) ;
V_39 = F_209 ( V_22 ) ;
if ( V_39 )
F_103 ( V_22 , L_45 , V_39 ) ;
V_39 = F_206 ( V_22 , V_287 ) ;
if ( V_39 )
F_103 ( V_22 , L_46 , V_39 ) ;
}
static struct V_181 * F_210 (
struct V_21 * V_22 ,
bool V_291 )
{
struct V_205 * V_206 = & V_22 -> V_53 -> V_63 -> V_206 ;
struct V_181 * V_182 ;
int V_39 ;
V_182 = F_164 ( V_22 -> V_288 , 0 , 0 ,
V_202 ) ;
if ( ! V_182 )
return F_38 ( - V_57 ) ;
V_182 -> V_207 = F_157 ( V_22 , V_89 , 1 ,
V_182 ) ;
if ( ! V_182 -> V_207 ) {
V_39 = - V_57 ;
goto V_49;
}
F_207 ( V_182 -> V_207 , 0 , V_238 ,
V_22 -> V_292 -> V_293 , 0 , V_291 ) ;
F_156 ( V_182 ) ;
if ( V_291 )
F_211 ( V_206 , V_182 -> V_207 ) ;
V_39 = F_125 ( V_206 , V_182 ) ;
if ( V_39 )
goto V_49;
V_39 = F_129 ( V_182 ) ;
if ( V_39 )
goto V_49;
V_39 = V_182 -> V_209 ;
if ( V_39 ) {
if ( V_291 )
F_127 ( V_182 ) ;
goto V_49;
}
return V_182 ;
V_49:
F_118 ( V_182 ) ;
return F_38 ( V_39 ) ;
}
static int F_212 ( struct V_21 * V_22 )
{
struct V_205 * V_206 = & V_22 -> V_53 -> V_63 -> V_206 ;
struct V_181 * V_182 ;
int V_39 ;
F_17 ( ! V_22 -> V_292 ) ;
F_17 ( ! V_22 -> V_294 ) ;
V_39 = F_213 ( V_206 , F_208 , V_22 ,
& V_22 -> V_292 ) ;
if ( V_39 < 0 )
return V_39 ;
V_182 = F_210 ( V_22 , true ) ;
if ( F_30 ( V_182 ) ) {
F_214 ( V_22 -> V_292 ) ;
V_22 -> V_292 = NULL ;
return F_197 ( V_182 ) ;
}
V_22 -> V_294 = V_182 ;
return 0 ;
}
static void F_215 ( struct V_21 * V_22 )
{
struct V_181 * V_182 ;
F_17 ( V_22 -> V_292 ) ;
F_17 ( V_22 -> V_294 ) ;
F_127 ( V_22 -> V_294 ) ;
F_118 ( V_22 -> V_294 ) ;
V_22 -> V_294 = NULL ;
V_182 = F_210 ( V_22 , false ) ;
if ( ! F_30 ( V_182 ) )
F_118 ( V_182 ) ;
else
F_103 ( V_22 , L_47 ,
F_197 ( V_182 ) ) ;
F_214 ( V_22 -> V_292 ) ;
V_22 -> V_292 = NULL ;
}
static int F_216 ( struct V_21 * V_22 ,
const char * V_239 ,
const char * V_295 ,
const char * V_296 ,
const void * V_297 ,
T_6 V_298 ,
void * V_299 ,
T_6 V_300 )
{
struct V_205 * V_206 = & V_22 -> V_53 -> V_63 -> V_206 ;
struct V_181 * V_182 ;
struct V_167 * * V_168 ;
T_5 V_256 ;
int V_39 ;
V_256 = ( T_5 ) F_190 ( 0 , V_300 ) ;
V_168 = F_196 ( V_256 , V_59 ) ;
if ( F_30 ( V_168 ) )
return F_197 ( V_168 ) ;
V_39 = - V_57 ;
V_182 = F_164 ( V_239 , 0 , V_300 ,
V_204 ) ;
if ( ! V_182 )
goto V_49;
V_182 -> V_168 = V_168 ;
V_182 -> V_256 = V_256 ;
V_182 -> V_207 = F_157 ( V_22 , V_88 , 1 ,
V_182 ) ;
if ( ! V_182 -> V_207 )
goto V_49;
F_193 ( V_182 -> V_207 , 0 , V_236 ,
V_295 , V_296 ) ;
if ( V_298 ) {
struct V_301 * V_302 ;
V_302 = F_26 ( sizeof ( * V_302 ) , V_303 ) ;
if ( ! V_302 )
goto V_49;
F_217 ( V_302 ) ;
F_218 ( V_302 , V_297 , V_298 ) ;
F_219 ( V_182 -> V_207 , 0 ,
V_302 ) ;
}
F_220 ( V_182 -> V_207 , 0 ,
V_182 -> V_168 , V_300 ,
0 , false , false ) ;
F_154 ( V_182 ) ;
V_39 = F_125 ( V_206 , V_182 ) ;
if ( V_39 )
goto V_49;
V_39 = F_129 ( V_182 ) ;
if ( V_39 )
goto V_49;
V_39 = V_182 -> V_209 ;
if ( V_39 < 0 )
goto V_49;
F_17 ( V_182 -> V_210 < ( V_106 ) V_3 ) ;
V_39 = ( int ) V_182 -> V_210 ;
F_221 ( V_168 , V_299 , 0 , V_182 -> V_210 ) ;
V_49:
if ( V_182 )
F_118 ( V_182 ) ;
else
F_167 ( V_168 , V_256 ) ;
return V_39 ;
}
static void F_222 ( struct V_21 * V_22 , struct V_304 * V_261 )
{
struct V_193 * V_184 ;
struct V_104 * V_112 = NULL ;
V_106 V_145 = ( V_106 ) F_223 ( V_261 ) << V_102 ;
V_106 V_151 = F_224 ( V_261 ) ;
enum V_86 V_87 ;
V_106 V_305 ;
int V_209 ;
if ( V_261 -> V_306 & V_307 )
V_87 = V_90 ;
else if ( V_261 -> V_306 & V_308 )
V_87 = V_89 ;
else
V_87 = V_88 ;
if ( ! V_151 ) {
F_25 ( L_48 , V_58 ) ;
V_209 = 0 ;
goto V_309;
}
if ( V_87 != V_88 ) {
if ( V_22 -> V_27 . V_28 ) {
V_209 = - V_29 ;
goto V_309;
}
F_17 ( V_22 -> V_45 -> V_46 == V_47 ) ;
}
if ( ! F_13 ( V_310 , & V_22 -> V_32 ) ) {
F_25 ( L_49 ) ;
F_17 ( V_22 -> V_45 -> V_46 != V_47 ) ;
V_209 = - V_311 ;
goto V_309;
}
if ( V_145 && V_151 > V_152 - V_145 + 1 ) {
F_103 ( V_22 , L_50 , V_145 ,
V_151 ) ;
V_209 = - V_4 ;
goto V_309;
}
F_173 ( & V_22 -> V_259 ) ;
V_305 = V_22 -> V_27 . V_96 ;
if ( V_87 != V_88 ) {
V_112 = V_22 -> V_109 . V_112 ;
F_225 ( V_112 ) ;
}
F_174 ( & V_22 -> V_259 ) ;
if ( V_145 + V_151 > V_305 ) {
F_103 ( V_22 , L_51 , V_145 ,
V_151 , V_305 ) ;
V_209 = - V_131 ;
goto V_309;
}
V_184 = F_175 ( V_22 , V_145 , V_151 , V_87 ,
V_112 ) ;
if ( ! V_184 ) {
V_209 = - V_57 ;
goto V_309;
}
V_184 -> V_261 = V_261 ;
if ( V_87 == V_90 )
V_209 = F_189 ( V_184 , V_202 ,
NULL ) ;
else
V_209 = F_189 ( V_184 , V_203 ,
V_261 -> V_153 ) ;
if ( V_209 )
goto V_312;
V_209 = F_198 ( V_184 ) ;
if ( V_209 )
goto V_312;
return;
V_312:
F_120 ( V_184 ) ;
V_309:
if ( V_209 )
F_103 ( V_22 , L_52 ,
F_48 ( V_87 ) , V_151 , V_145 , V_209 ) ;
F_64 ( V_112 ) ;
F_226 ( V_261 , V_209 ) ;
}
static void F_227 ( struct V_313 * V_314 )
{
struct V_21 * V_22 =
F_53 ( V_314 , struct V_21 , V_315 ) ;
struct V_304 * V_261 , * V_316 ;
F_228 ( V_317 ) ;
F_12 ( & V_22 -> V_30 ) ;
F_229 ( & V_22 -> V_318 , & V_317 ) ;
F_14 ( & V_22 -> V_30 ) ;
F_230 (rq, next, &requests, queuelist) {
F_231 ( & V_261 -> V_319 ) ;
F_222 ( V_22 , V_261 ) ;
}
}
static void F_232 ( struct V_320 * V_321 )
{
struct V_21 * V_22 = V_321 -> V_322 ;
struct V_304 * V_261 ;
int V_323 = 0 ;
F_17 ( V_22 ) ;
while ( ( V_261 = F_233 ( V_321 ) ) ) {
if ( V_261 -> V_324 != V_325 ) {
F_25 ( L_53 , V_58 ,
( int ) V_261 -> V_324 ) ;
F_234 ( V_261 , 0 ) ;
continue;
}
F_33 ( & V_261 -> V_319 , & V_22 -> V_318 ) ;
V_323 ++ ;
}
if ( V_323 )
F_235 ( V_326 , & V_22 -> V_315 ) ;
}
static int F_236 ( struct V_320 * V_321 , struct V_327 * V_328 ,
struct V_158 * V_329 )
{
struct V_21 * V_22 = V_321 -> V_322 ;
T_10 V_330 ;
T_10 V_331 ;
T_10 V_332 ;
int V_39 ;
V_330 = F_237 ( V_328 -> V_333 ) + V_328 -> V_275 ;
V_331 = 1 << ( V_22 -> V_109 . V_125 - V_102 ) ;
V_332 = V_330 & ( V_331 - 1 ) ;
V_39 = ( int ) ( V_331 - V_332 ) << V_102 ;
if ( V_39 > V_328 -> V_178 )
V_39 -= V_328 -> V_178 ;
else
V_39 = 0 ;
F_17 ( V_329 -> V_164 <= V_174 ) ;
if ( V_39 > ( int ) V_329 -> V_164 || ! V_328 -> V_178 )
V_39 = ( int ) V_329 -> V_164 ;
return V_39 ;
}
static void F_238 ( struct V_21 * V_22 )
{
struct V_35 * V_36 = V_22 -> V_36 ;
if ( ! V_36 )
return;
V_22 -> V_36 = NULL ;
if ( V_36 -> V_32 & V_334 ) {
F_239 ( V_36 ) ;
if ( V_36 -> V_335 )
F_240 ( V_36 -> V_335 ) ;
}
F_241 ( V_36 ) ;
}
static int F_242 ( struct V_21 * V_22 ,
const char * V_239 ,
V_106 V_145 , V_106 V_151 , void * V_162 )
{
struct V_205 * V_206 = & V_22 -> V_53 -> V_63 -> V_206 ;
struct V_181 * V_182 ;
struct V_167 * * V_168 = NULL ;
T_5 V_256 ;
T_6 V_96 ;
int V_39 ;
V_256 = ( T_5 ) F_190 ( V_145 , V_151 ) ;
V_168 = F_196 ( V_256 , V_59 ) ;
if ( F_30 ( V_168 ) )
return F_197 ( V_168 ) ;
V_39 = - V_57 ;
V_182 = F_164 ( V_239 , V_145 , V_151 ,
V_204 ) ;
if ( ! V_182 )
goto V_49;
V_182 -> V_168 = V_168 ;
V_182 -> V_256 = V_256 ;
V_182 -> V_207 = F_157 ( V_22 , V_88 , 1 ,
V_182 ) ;
if ( ! V_182 -> V_207 )
goto V_49;
F_186 ( V_182 -> V_207 , 0 , V_229 ,
V_145 , V_151 , 0 , 0 ) ;
F_188 ( V_182 -> V_207 , 0 ,
V_182 -> V_168 ,
V_182 -> V_151 ,
V_182 -> V_145 & ~ V_173 ,
false , false ) ;
F_154 ( V_182 ) ;
V_39 = F_125 ( V_206 , V_182 ) ;
if ( V_39 )
goto V_49;
V_39 = F_129 ( V_182 ) ;
if ( V_39 )
goto V_49;
V_39 = V_182 -> V_209 ;
if ( V_39 < 0 )
goto V_49;
F_17 ( V_182 -> V_210 <= ( V_106 ) V_103 ) ;
V_96 = ( T_6 ) V_182 -> V_210 ;
F_221 ( V_168 , V_162 , 0 , V_96 ) ;
F_17 ( V_96 <= ( T_6 ) V_3 ) ;
V_39 = ( int ) V_96 ;
V_49:
if ( V_182 )
F_118 ( V_182 ) ;
else
F_167 ( V_168 , V_256 ) ;
return V_39 ;
}
static int F_243 ( struct V_21 * V_22 )
{
struct V_94 * V_95 = NULL ;
T_5 V_97 = 0 ;
V_106 V_336 = 0 ;
T_5 V_337 ;
int V_39 ;
do {
T_6 V_96 ;
F_36 ( V_95 ) ;
V_96 = sizeof ( * V_95 ) ;
V_96 += V_97 * sizeof ( struct V_120 ) ;
V_96 += V_336 ;
V_95 = F_26 ( V_96 , V_59 ) ;
if ( ! V_95 )
return - V_57 ;
V_39 = F_242 ( V_22 , V_22 -> V_288 ,
0 , V_96 , V_95 ) ;
if ( V_39 < 0 )
goto V_49;
if ( ( T_6 ) V_39 < V_96 ) {
V_39 = - V_311 ;
F_103 ( V_22 , L_54 ,
V_96 , V_39 ) ;
goto V_49;
}
if ( ! F_58 ( V_95 ) ) {
V_39 = - V_311 ;
F_103 ( V_22 , L_55 ) ;
goto V_49;
}
V_336 = F_60 ( V_95 -> V_107 ) ;
V_337 = V_97 ;
V_97 = F_59 ( V_95 -> V_97 ) ;
} while ( V_97 != V_337 );
V_39 = F_61 ( V_22 , V_95 ) ;
V_49:
F_36 ( V_95 ) ;
return V_39 ;
}
static void F_244 ( struct V_21 * V_22 )
{
V_106 V_46 ;
if ( ! F_13 ( V_310 , & V_22 -> V_32 ) )
return;
V_46 = V_22 -> V_45 -> V_46 ;
if ( V_46 == V_47 )
return;
if ( F_68 ( V_22 , V_46 ) == V_139 )
F_139 ( V_310 , & V_22 -> V_32 ) ;
}
static void F_245 ( struct V_21 * V_22 )
{
T_10 V_96 ;
bool V_25 ;
F_12 ( & V_22 -> V_30 ) ;
V_25 = F_13 ( V_31 , & V_22 -> V_32 ) ;
F_14 ( & V_22 -> V_30 ) ;
if ( ! V_25 ) {
V_96 = ( T_10 ) V_22 -> V_27 . V_96 / V_338 ;
F_25 ( L_56 , ( unsigned long long ) V_96 ) ;
F_246 ( V_22 -> V_36 , V_96 ) ;
F_247 ( V_22 -> V_36 ) ;
}
}
static int F_209 ( struct V_21 * V_22 )
{
V_106 V_305 ;
int V_39 ;
F_248 ( & V_22 -> V_259 ) ;
V_305 = V_22 -> V_27 . V_96 ;
V_39 = F_249 ( V_22 ) ;
if ( V_39 )
return V_39 ;
if ( V_22 -> V_266 ) {
V_39 = F_250 ( V_22 ) ;
if ( V_39 )
return V_39 ;
}
if ( V_22 -> V_45 -> V_46 == V_47 ) {
if ( V_22 -> V_27 . V_96 != V_22 -> V_109 . V_124 )
V_22 -> V_27 . V_96 = V_22 -> V_109 . V_124 ;
} else {
F_244 ( V_22 ) ;
}
F_251 ( & V_22 -> V_259 ) ;
if ( V_305 != V_22 -> V_27 . V_96 )
F_245 ( V_22 ) ;
return 0 ;
}
static int F_252 ( struct V_21 * V_22 )
{
struct V_35 * V_36 ;
struct V_320 * V_321 ;
V_106 V_150 ;
V_36 = F_253 ( V_13 ?
( 1 << V_6 ) :
V_339 ) ;
if ( ! V_36 )
return - V_57 ;
snprintf ( V_36 -> V_340 , sizeof( V_36 -> V_340 ) , V_341 L_57 ,
V_22 -> V_5 ) ;
V_36 -> V_342 = V_22 -> V_342 ;
V_36 -> V_343 = V_22 -> V_7 ;
if ( V_13 )
V_36 -> V_32 |= V_344 ;
V_36 -> V_345 = & V_346 ;
V_36 -> V_24 = V_22 ;
V_321 = F_254 ( F_232 , & V_22 -> V_30 ) ;
if ( ! V_321 )
goto V_347;
F_255 ( V_321 , V_338 ) ;
V_150 = F_84 ( & V_22 -> V_109 ) ;
F_256 ( V_321 , V_150 / V_338 ) ;
F_257 ( V_321 , V_150 ) ;
F_258 ( V_321 , V_150 ) ;
F_259 ( V_321 , V_150 ) ;
F_260 ( V_348 , V_321 ) ;
V_321 -> V_349 . V_350 = V_150 ;
V_321 -> V_349 . V_351 = V_150 ;
V_321 -> V_349 . V_352 = V_150 / V_338 ;
V_321 -> V_349 . V_353 = 1 ;
F_261 ( V_321 , F_236 ) ;
V_36 -> V_335 = V_321 ;
V_321 -> V_322 = V_22 ;
V_22 -> V_36 = V_36 ;
return 0 ;
V_347:
F_241 ( V_36 ) ;
return - V_57 ;
}
static struct V_21 * F_262 ( struct V_17 * V_18 )
{
return F_53 ( V_18 , struct V_21 , V_18 ) ;
}
static T_11 F_263 ( struct V_17 * V_18 ,
struct V_354 * V_11 , char * V_162 )
{
struct V_21 * V_22 = F_262 ( V_18 ) ;
return sprintf ( V_162 , L_58 ,
( unsigned long long ) V_22 -> V_27 . V_96 ) ;
}
static T_11 F_264 ( struct V_17 * V_18 ,
struct V_354 * V_11 , char * V_162 )
{
struct V_21 * V_22 = F_262 ( V_18 ) ;
return sprintf ( V_162 , L_59 ,
( unsigned long long ) V_22 -> V_27 . V_130 ) ;
}
static T_11 F_265 ( struct V_17 * V_18 ,
struct V_354 * V_11 , char * V_162 )
{
struct V_21 * V_22 = F_262 ( V_18 ) ;
if ( V_22 -> V_342 )
return sprintf ( V_162 , L_60 , V_22 -> V_342 ) ;
return sprintf ( V_162 , L_61 ) ;
}
static T_11 F_266 ( struct V_17 * V_18 ,
struct V_354 * V_11 , char * V_162 )
{
struct V_21 * V_22 = F_262 ( V_18 ) ;
return sprintf ( V_162 , L_60 , V_22 -> V_7 ) ;
}
static T_11 F_267 ( struct V_17 * V_18 ,
struct V_354 * V_11 , char * V_162 )
{
struct V_21 * V_22 = F_262 ( V_18 ) ;
return sprintf ( V_162 , L_62 ,
F_268 ( V_22 -> V_53 -> V_63 ) ) ;
}
static T_11 F_269 ( struct V_17 * V_18 ,
struct V_354 * V_11 , char * V_162 )
{
struct V_21 * V_22 = F_262 ( V_18 ) ;
return sprintf ( V_162 , L_63 , V_22 -> V_45 -> V_355 ) ;
}
static T_11 F_270 ( struct V_17 * V_18 ,
struct V_354 * V_11 , char * V_162 )
{
struct V_21 * V_22 = F_262 ( V_18 ) ;
return sprintf ( V_162 , L_58 ,
( unsigned long long ) V_22 -> V_45 -> V_356 ) ;
}
static T_11 F_271 ( struct V_17 * V_18 ,
struct V_354 * V_11 , char * V_162 )
{
struct V_21 * V_22 = F_262 ( V_18 ) ;
if ( V_22 -> V_45 -> V_357 )
return sprintf ( V_162 , L_63 , V_22 -> V_45 -> V_357 ) ;
return sprintf ( V_162 , L_64 ) ;
}
static T_11 F_272 ( struct V_17 * V_18 ,
struct V_354 * V_11 , char * V_162 )
{
struct V_21 * V_22 = F_262 ( V_18 ) ;
return sprintf ( V_162 , L_63 , V_22 -> V_45 -> V_358 ) ;
}
static T_11 F_273 ( struct V_17 * V_18 ,
struct V_354 * V_11 ,
char * V_162 )
{
struct V_21 * V_22 = F_262 ( V_18 ) ;
return sprintf ( V_162 , L_63 , V_22 -> V_45 -> V_133 ) ;
}
static T_11 F_274 ( struct V_17 * V_18 ,
struct V_354 * V_11 ,
char * V_162 )
{
struct V_21 * V_22 = F_262 ( V_18 ) ;
T_11 V_359 = 0 ;
if ( ! V_22 -> V_266 )
return sprintf ( V_162 , L_65 ) ;
for ( ; V_22 -> V_266 ; V_22 = V_22 -> V_266 ) {
struct V_360 * V_45 = V_22 -> V_257 ;
V_359 += sprintf ( & V_162 [ V_359 ] , L_66
L_67
L_68
L_69
L_70 ,
! V_359 ? L_71 : L_72 ,
V_45 -> V_356 , V_45 -> V_355 ,
V_45 -> V_358 , V_45 -> V_357 ? : L_73 ,
V_45 -> V_46 , V_45 -> V_133 ,
V_22 -> V_190 ) ;
}
return V_359 ;
}
static T_11 F_275 ( struct V_17 * V_18 ,
struct V_354 * V_11 ,
const char * V_162 ,
T_6 V_96 )
{
struct V_21 * V_22 = F_262 ( V_18 ) ;
int V_39 ;
V_39 = F_209 ( V_22 ) ;
if ( V_39 )
return V_39 ;
return V_96 ;
}
static void F_276 ( struct V_17 * V_18 )
{
}
static struct V_360 * F_277 ( struct V_360 * V_45 )
{
F_40 ( & V_45 -> V_61 ) ;
return V_45 ;
}
static void F_170 ( struct V_360 * V_45 )
{
if ( V_45 )
F_56 ( & V_45 -> V_61 , V_361 ) ;
}
static struct V_360 * F_278 ( void )
{
struct V_360 * V_45 ;
V_45 = F_279 ( sizeof ( * V_45 ) , V_59 ) ;
if ( ! V_45 )
return NULL ;
V_45 -> V_356 = V_362 ;
V_45 -> V_46 = V_47 ;
F_27 ( & V_45 -> V_61 ) ;
return V_45 ;
}
static void V_361 ( struct V_61 * V_61 )
{
struct V_360 * V_45 = F_53 ( V_61 , struct V_360 , V_61 ) ;
F_36 ( V_45 -> V_355 ) ;
F_36 ( V_45 -> V_358 ) ;
F_36 ( V_45 -> V_357 ) ;
F_36 ( V_45 -> V_133 ) ;
F_36 ( V_45 ) ;
}
static struct V_21 * F_280 ( struct V_53 * V_56 ,
struct V_360 * V_45 )
{
struct V_21 * V_22 ;
V_22 = F_279 ( sizeof ( * V_22 ) , V_59 ) ;
if ( ! V_22 )
return NULL ;
F_176 ( & V_22 -> V_30 ) ;
F_28 ( & V_22 -> V_318 ) ;
F_281 ( & V_22 -> V_315 , F_227 ) ;
V_22 -> V_32 = 0 ;
F_282 ( & V_22 -> V_258 , 0 ) ;
F_28 ( & V_22 -> V_62 ) ;
F_283 ( & V_22 -> V_259 ) ;
V_22 -> V_45 = V_45 ;
V_22 -> V_53 = V_56 ;
V_22 -> V_252 . V_363 = F_284 ( 1 << V_364 ) ;
V_22 -> V_252 . V_365 = F_284 ( 1 ) ;
V_22 -> V_252 . V_366 = F_284 ( 1 << V_364 ) ;
V_22 -> V_252 . V_367 = F_284 ( ( T_5 ) V_45 -> V_356 ) ;
return V_22 ;
}
static void F_285 ( struct V_21 * V_22 )
{
F_55 ( V_22 -> V_53 ) ;
F_170 ( V_22 -> V_45 ) ;
F_36 ( V_22 ) ;
}
static int F_73 ( struct V_21 * V_22 , V_106 V_46 ,
T_9 * V_101 , V_106 * V_141 )
{
V_105 V_368 = F_286 ( V_46 ) ;
int V_39 ;
struct {
T_9 V_101 ;
V_105 V_96 ;
} V_369 ( ( V_370 ) ) V_371 = { 0 } ;
V_39 = F_216 ( V_22 , V_22 -> V_288 ,
L_41 , L_74 ,
& V_368 , sizeof ( V_368 ) ,
& V_371 , sizeof ( V_371 ) ) ;
F_25 ( L_75 , V_58 , V_39 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 < sizeof ( V_371 ) )
return - V_372 ;
if ( V_101 ) {
* V_101 = V_371 . V_101 ;
F_25 ( L_76 , ( unsigned int ) * V_101 ) ;
}
* V_141 = F_60 ( V_371 . V_96 ) ;
F_25 ( L_77 ,
( unsigned long long ) V_46 ,
( unsigned long long ) * V_141 ) ;
return 0 ;
}
static int F_287 ( struct V_21 * V_22 )
{
return F_73 ( V_22 , V_47 ,
& V_22 -> V_109 . V_125 ,
& V_22 -> V_109 . V_124 ) ;
}
static int F_288 ( struct V_21 * V_22 )
{
void * V_373 ;
int V_39 ;
void * V_374 ;
V_373 = F_279 ( V_375 , V_59 ) ;
if ( ! V_373 )
return - V_57 ;
V_39 = F_216 ( V_22 , V_22 -> V_288 ,
L_41 , L_78 , NULL , 0 ,
V_373 , V_375 ) ;
F_25 ( L_75 , V_58 , V_39 ) ;
if ( V_39 < 0 )
goto V_49;
V_374 = V_373 ;
V_22 -> V_109 . V_111 = F_289 ( & V_374 ,
V_374 + V_39 , NULL , V_148 ) ;
V_39 = 0 ;
if ( F_30 ( V_22 -> V_109 . V_111 ) ) {
V_39 = F_197 ( V_22 -> V_109 . V_111 ) ;
V_22 -> V_109 . V_111 = NULL ;
} else {
F_25 ( L_79 , V_22 -> V_109 . V_111 ) ;
}
V_49:
F_36 ( V_373 ) ;
return V_39 ;
}
static int F_75 ( struct V_21 * V_22 , V_106 V_46 ,
V_106 * V_142 )
{
V_105 V_368 = F_286 ( V_46 ) ;
struct {
V_105 V_130 ;
V_105 V_376 ;
} V_369 ( ( V_370 ) ) V_377 = { 0 } ;
V_106 V_376 ;
int V_39 ;
V_39 = F_216 ( V_22 , V_22 -> V_288 ,
L_41 , L_80 ,
& V_368 , sizeof ( V_368 ) ,
& V_377 , sizeof ( V_377 ) ) ;
F_25 ( L_75 , V_58 , V_39 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 < sizeof ( V_377 ) )
return - V_372 ;
V_376 = F_60 ( V_377 . V_376 ) ;
if ( V_376 & ~ V_378 )
return - V_311 ;
* V_142 = F_60 ( V_377 . V_130 ) ;
F_25 ( L_81 ,
( unsigned long long ) V_46 ,
( unsigned long long ) * V_142 ,
( unsigned long long ) F_60 ( V_377 . V_376 ) ) ;
return 0 ;
}
static int F_290 ( struct V_21 * V_22 )
{
return F_75 ( V_22 , V_47 ,
& V_22 -> V_109 . V_130 ) ;
}
static int F_250 ( struct V_21 * V_22 )
{
struct V_360 * V_257 ;
T_6 V_96 ;
void * V_373 = NULL ;
V_105 V_368 ;
void * V_374 ;
void * V_169 ;
V_106 V_356 ;
char * V_358 ;
V_106 V_46 ;
V_106 V_379 ;
int V_39 ;
V_257 = F_278 () ;
if ( ! V_257 )
return - V_57 ;
V_96 = sizeof ( V_105 ) +
sizeof ( V_283 ) + V_380 +
sizeof ( V_105 ) +
sizeof ( V_105 ) ;
V_373 = F_26 ( V_96 , V_59 ) ;
if ( ! V_373 ) {
V_39 = - V_57 ;
goto V_117;
}
V_368 = F_286 ( V_22 -> V_45 -> V_46 ) ;
V_39 = F_216 ( V_22 , V_22 -> V_288 ,
L_41 , L_82 ,
& V_368 , sizeof ( V_368 ) ,
V_373 , V_96 ) ;
F_25 ( L_75 , V_58 , V_39 ) ;
if ( V_39 < 0 )
goto V_117;
V_374 = V_373 ;
V_169 = V_373 + V_39 ;
V_39 = - V_372 ;
F_291 ( & V_374 , V_169 , V_356 , V_117 ) ;
if ( V_356 == V_362 ) {
if ( V_22 -> V_190 ) {
V_22 -> V_190 = 0 ;
F_171 ( V_22 ) ;
F_292 ( L_83 ,
V_22 -> V_36 -> V_340 ) ;
}
goto V_49;
}
V_39 = - V_131 ;
if ( V_356 > ( V_106 ) V_381 ) {
F_103 ( NULL , L_84 ,
( unsigned long long ) V_356 , V_381 ) ;
goto V_117;
}
V_358 = F_289 ( & V_374 , V_169 , NULL , V_59 ) ;
if ( F_30 ( V_358 ) ) {
V_39 = F_197 ( V_358 ) ;
goto V_117;
}
F_291 ( & V_374 , V_169 , V_46 , V_117 ) ;
F_291 ( & V_374 , V_169 , V_379 , V_117 ) ;
if ( ! V_22 -> V_257 ) {
V_257 -> V_356 = V_356 ;
V_257 -> V_358 = V_358 ;
V_257 -> V_46 = V_46 ;
V_22 -> V_257 = V_257 ;
V_257 = NULL ;
} else {
F_36 ( V_358 ) ;
}
V_22 -> V_190 = V_379 ;
if ( ! V_379 ) {
if ( V_257 ) {
F_171 ( V_22 ) ;
F_292 ( L_85 ,
V_22 -> V_36 -> V_340 ) ;
} else {
F_103 ( V_22 , L_86 ) ;
}
}
V_49:
V_39 = 0 ;
V_117:
F_36 ( V_373 ) ;
F_170 ( V_257 ) ;
return V_39 ;
}
static int F_293 ( struct V_21 * V_22 )
{
struct {
V_105 V_128 ;
V_105 V_129 ;
} V_369 ( ( V_370 ) ) V_382 = { 0 } ;
T_6 V_96 = sizeof ( V_382 ) ;
void * V_374 ;
V_106 V_383 ;
V_106 V_128 ;
V_106 V_129 ;
int V_39 ;
V_39 = F_216 ( V_22 , V_22 -> V_288 ,
L_41 , L_87 , NULL , 0 ,
( char * ) & V_382 , V_96 ) ;
F_25 ( L_75 , V_58 , V_39 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 < V_96 )
return - V_372 ;
V_39 = - V_4 ;
V_383 = ( V_106 ) 1 << V_22 -> V_109 . V_125 ;
V_374 = & V_382 ;
V_128 = F_294 ( & V_374 ) ;
if ( V_128 != V_383 ) {
F_103 ( V_22 , L_88
L_89 ,
V_128 , V_383 ) ;
return - V_4 ;
}
V_129 = F_294 ( & V_374 ) ;
if ( V_129 != 1 ) {
F_103 ( V_22 , L_90
L_91 , V_129 ) ;
return - V_4 ;
}
V_22 -> V_109 . V_128 = V_128 ;
V_22 -> V_109 . V_129 = V_129 ;
return 0 ;
}
static char * F_295 ( struct V_21 * V_22 )
{
T_6 V_384 ;
char * V_358 ;
void * V_374 ;
void * V_169 ;
T_6 V_96 ;
void * V_373 = NULL ;
T_6 V_116 = 0 ;
char * V_357 = NULL ;
int V_39 ;
F_17 ( ! V_22 -> V_45 -> V_357 ) ;
V_116 = strlen ( V_22 -> V_45 -> V_358 ) ;
V_384 = sizeof ( V_283 ) + V_116 ;
V_358 = F_26 ( V_384 , V_59 ) ;
if ( ! V_358 )
return NULL ;
V_374 = V_358 ;
V_169 = V_358 + V_384 ;
F_296 ( & V_374 , V_169 , V_22 -> V_45 -> V_358 , ( T_5 ) V_116 ) ;
V_96 = sizeof ( V_283 ) + V_385 ;
V_373 = F_26 ( V_96 , V_59 ) ;
if ( ! V_373 )
goto V_49;
V_39 = F_216 ( V_22 , V_386 ,
L_41 , L_92 ,
V_358 , V_384 ,
V_373 , V_96 ) ;
if ( V_39 < 0 )
goto V_49;
V_374 = V_373 ;
V_169 = V_373 + V_39 ;
V_357 = F_289 ( & V_374 , V_169 , & V_116 , V_59 ) ;
if ( F_30 ( V_357 ) )
V_357 = NULL ;
else
F_25 ( L_93 , V_58 , V_357 , V_116 ) ;
V_49:
F_36 ( V_373 ) ;
F_36 ( V_358 ) ;
return V_357 ;
}
static V_106 F_297 ( struct V_21 * V_22 , const char * V_143 )
{
struct V_104 * V_112 = V_22 -> V_109 . V_112 ;
const char * V_133 ;
T_5 V_132 = 0 ;
V_133 = V_22 -> V_109 . V_113 ;
while ( V_132 < V_112 -> V_134 ) {
if ( ! strcmp ( V_143 , V_133 ) )
return V_112 -> V_121 [ V_132 ] ;
V_133 += strlen ( V_133 ) + 1 ;
V_132 ++ ;
}
return V_47 ;
}
static V_106 F_298 ( struct V_21 * V_22 , const char * V_143 )
{
struct V_104 * V_112 = V_22 -> V_109 . V_112 ;
T_5 V_132 ;
bool V_69 = false ;
V_106 V_46 ;
for ( V_132 = 0 ; ! V_69 && V_132 < V_112 -> V_134 ; V_132 ++ ) {
const char * V_133 ;
V_46 = V_112 -> V_121 [ V_132 ] ;
V_133 = F_71 ( V_22 , V_46 ) ;
if ( F_30 ( V_133 ) ) {
if ( F_197 ( V_133 ) == - V_34 )
continue;
else
break;
}
V_69 = ! strcmp ( V_143 , V_133 ) ;
F_36 ( V_133 ) ;
}
return V_69 ? V_46 : V_47 ;
}
static V_106 F_299 ( struct V_21 * V_22 , const char * V_143 )
{
if ( V_22 -> V_93 == 1 )
return F_297 ( V_22 , V_143 ) ;
return F_298 ( V_22 , V_143 ) ;
}
static int F_300 ( struct V_21 * V_22 )
{
struct V_360 * V_45 = V_22 -> V_45 ;
F_17 ( V_45 -> V_356 != V_362 && V_45 -> V_355 ) ;
F_17 ( V_45 -> V_358 && V_45 -> V_357 ) ;
F_17 ( V_45 -> V_133 ) ;
if ( strcmp ( V_45 -> V_133 , V_140 ) ) {
V_106 V_46 ;
V_46 = F_299 ( V_22 , V_45 -> V_133 ) ;
if ( V_46 == V_47 )
return - V_34 ;
V_45 -> V_46 = V_46 ;
} else {
V_45 -> V_46 = V_47 ;
}
return 0 ;
}
static int F_301 ( struct V_21 * V_22 )
{
struct V_205 * V_206 = & V_22 -> V_53 -> V_63 -> V_206 ;
struct V_360 * V_45 = V_22 -> V_45 ;
const char * V_355 ;
const char * V_357 ;
const char * V_133 ;
int V_39 ;
F_17 ( V_45 -> V_356 != V_362 ) ;
F_17 ( V_45 -> V_358 ) ;
F_17 ( V_45 -> V_46 != V_47 ) ;
V_355 = F_302 ( V_206 -> V_387 , V_45 -> V_356 ) ;
if ( ! V_355 ) {
F_103 ( V_22 , L_94 , V_45 -> V_356 ) ;
return - V_131 ;
}
V_355 = F_66 ( V_355 , V_59 ) ;
if ( ! V_355 )
return - V_57 ;
V_357 = F_295 ( V_22 ) ;
if ( ! V_357 )
F_103 ( V_22 , L_95 ) ;
V_133 = F_70 ( V_22 , V_45 -> V_46 ) ;
if ( F_30 ( V_133 ) ) {
V_39 = F_197 ( V_133 ) ;
goto V_117;
}
V_45 -> V_355 = V_355 ;
V_45 -> V_357 = V_357 ;
V_45 -> V_133 = V_133 ;
return 0 ;
V_117:
F_36 ( V_357 ) ;
F_36 ( V_355 ) ;
return V_39 ;
}
static int F_303 ( struct V_21 * V_22 )
{
T_6 V_96 ;
int V_39 ;
void * V_373 ;
void * V_374 ;
void * V_169 ;
V_106 V_118 ;
T_5 V_97 ;
struct V_104 * V_112 ;
T_5 V_115 ;
V_96 = sizeof ( V_105 ) + sizeof ( V_283 ) +
V_388 * sizeof ( V_105 ) ;
V_373 = F_279 ( V_96 , V_59 ) ;
if ( ! V_373 )
return - V_57 ;
V_39 = F_216 ( V_22 , V_22 -> V_288 ,
L_41 , L_96 , NULL , 0 ,
V_373 , V_96 ) ;
F_25 ( L_75 , V_58 , V_39 ) ;
if ( V_39 < 0 )
goto V_49;
V_374 = V_373 ;
V_169 = V_373 + V_39 ;
V_39 = - V_372 ;
F_291 ( & V_374 , V_169 , V_118 , V_49 ) ;
F_304 ( & V_374 , V_169 , V_97 , V_49 ) ;
if ( V_97 > ( V_103 - sizeof ( struct V_104 ) )
/ sizeof ( V_106 ) ) {
V_39 = - V_4 ;
goto V_49;
}
if ( ! F_305 ( & V_374 , V_169 , V_97 * sizeof ( V_105 ) ) )
goto V_49;
V_39 = 0 ;
V_112 = F_63 ( V_97 , V_59 ) ;
if ( ! V_112 ) {
V_39 = - V_57 ;
goto V_49;
}
V_112 -> V_118 = V_118 ;
for ( V_115 = 0 ; V_115 < V_97 ; V_115 ++ )
V_112 -> V_121 [ V_115 ] = F_294 ( & V_374 ) ;
F_64 ( V_22 -> V_109 . V_112 ) ;
V_22 -> V_109 . V_112 = V_112 ;
F_25 ( L_97 ,
( unsigned long long ) V_118 , ( unsigned int ) V_97 ) ;
V_49:
F_36 ( V_373 ) ;
return V_39 ;
}
static const char * F_71 ( struct V_21 * V_22 ,
V_106 V_46 )
{
T_6 V_96 ;
void * V_373 ;
V_105 V_368 ;
int V_39 ;
void * V_374 ;
void * V_169 ;
char * V_133 ;
V_96 = sizeof ( V_283 ) + V_389 ;
V_373 = F_26 ( V_96 , V_59 ) ;
if ( ! V_373 )
return F_38 ( - V_57 ) ;
V_368 = F_286 ( V_46 ) ;
V_39 = F_216 ( V_22 , V_22 -> V_288 ,
L_41 , L_98 ,
& V_368 , sizeof ( V_368 ) ,
V_373 , V_96 ) ;
F_25 ( L_75 , V_58 , V_39 ) ;
if ( V_39 < 0 ) {
V_133 = F_38 ( V_39 ) ;
goto V_49;
}
V_374 = V_373 ;
V_169 = V_373 + V_39 ;
V_133 = F_289 ( & V_374 , V_169 , NULL , V_59 ) ;
if ( F_30 ( V_133 ) )
goto V_49;
F_25 ( L_99 ,
( unsigned long long ) V_46 , V_133 ) ;
V_49:
F_36 ( V_373 ) ;
return V_133 ;
}
static int F_306 ( struct V_21 * V_22 )
{
bool V_110 = V_22 -> V_109 . V_111 == NULL ;
int V_39 ;
V_39 = F_287 ( V_22 ) ;
if ( V_39 )
return V_39 ;
if ( V_110 ) {
V_39 = F_307 ( V_22 ) ;
if ( V_39 )
return V_39 ;
}
V_39 = F_303 ( V_22 ) ;
F_25 ( L_100 , V_39 ) ;
return V_39 ;
}
static int F_249 ( struct V_21 * V_22 )
{
F_17 ( F_57 ( V_22 -> V_93 ) ) ;
if ( V_22 -> V_93 == 1 )
return F_243 ( V_22 ) ;
return F_306 ( V_22 ) ;
}
static int F_308 ( struct V_21 * V_22 )
{
struct V_17 * V_18 ;
int V_39 ;
V_18 = & V_22 -> V_18 ;
V_18 -> V_390 = & V_391 ;
V_18 -> type = & V_392 ;
V_18 -> V_266 = & V_393 ;
V_18 -> V_394 = V_395 ;
F_309 ( V_18 , L_57 , V_22 -> V_5 ) ;
V_39 = F_310 ( V_18 ) ;
return V_39 ;
}
static void F_311 ( struct V_21 * V_22 )
{
F_312 ( & V_22 -> V_18 ) ;
}
static int F_313 ( struct V_21 * V_22 )
{
int V_396 ;
V_396 = F_314 ( & V_397 ,
0 , F_8 ( 1 << V_398 ) ,
V_59 ) ;
if ( V_396 < 0 )
return V_396 ;
V_22 -> V_5 = V_396 ;
F_32 ( & V_399 ) ;
F_33 ( & V_22 -> V_62 , & V_400 ) ;
F_34 ( & V_399 ) ;
F_25 ( L_101 , V_22 , V_22 -> V_5 ) ;
return 0 ;
}
static void F_315 ( struct V_21 * V_22 )
{
F_32 ( & V_399 ) ;
F_231 ( & V_22 -> V_62 ) ;
F_34 ( & V_399 ) ;
F_316 ( & V_397 , V_22 -> V_5 ) ;
F_25 ( L_102 , V_22 , V_22 -> V_5 ) ;
}
static inline T_6 F_317 ( const char * * V_162 )
{
const char * V_401 = L_103 ;
* V_162 += strspn ( * V_162 , V_401 ) ;
return strcspn ( * V_162 , V_401 ) ;
}
static inline T_6 F_318 ( const char * * V_162 ,
char * V_77 ,
T_6 V_402 )
{
T_6 V_116 ;
V_116 = F_317 ( V_162 ) ;
if ( V_116 < V_402 ) {
memcpy ( V_77 , * V_162 , V_116 ) ;
* ( V_77 + V_116 ) = '\0' ;
}
* V_162 += V_116 ;
return V_116 ;
}
static inline char * F_319 ( const char * * V_162 , T_6 * V_403 )
{
char * V_404 ;
T_6 V_116 ;
V_116 = F_317 ( V_162 ) ;
V_404 = F_320 ( * V_162 , V_116 + 1 , V_59 ) ;
if ( ! V_404 )
return NULL ;
* ( V_404 + V_116 ) = '\0' ;
* V_162 += V_116 ;
if ( V_403 )
* V_403 = V_116 ;
return V_404 ;
}
static int F_321 ( const char * V_162 ,
struct V_54 * * V_55 ,
struct V_73 * * V_405 ,
struct V_360 * * V_360 )
{
T_6 V_116 ;
char * V_100 ;
const char * V_406 ;
char * V_133 ;
T_6 V_407 ;
struct V_360 * V_45 = NULL ;
struct V_73 * V_74 = NULL ;
struct V_54 * V_408 ;
int V_39 ;
V_116 = F_317 ( & V_162 ) ;
if ( ! V_116 ) {
F_103 ( NULL , L_104 ) ;
return - V_4 ;
}
V_406 = V_162 ;
V_407 = V_116 + 1 ;
V_162 += V_116 ;
V_39 = - V_4 ;
V_100 = F_319 ( & V_162 , NULL ) ;
if ( ! V_100 )
return - V_57 ;
if ( ! * V_100 ) {
F_103 ( NULL , L_105 ) ;
goto V_117;
}
V_45 = F_278 () ;
if ( ! V_45 )
goto V_409;
V_45 -> V_355 = F_319 ( & V_162 , NULL ) ;
if ( ! V_45 -> V_355 )
goto V_409;
if ( ! * V_45 -> V_355 ) {
F_103 ( NULL , L_106 ) ;
goto V_117;
}
V_45 -> V_357 = F_319 ( & V_162 , NULL ) ;
if ( ! V_45 -> V_357 )
goto V_409;
if ( ! * V_45 -> V_357 ) {
F_103 ( NULL , L_107 ) ;
goto V_117;
}
V_116 = F_317 ( & V_162 ) ;
if ( ! V_116 ) {
V_162 = V_140 ;
V_116 = sizeof ( V_140 ) - 1 ;
} else if ( V_116 > V_389 ) {
V_39 = - V_410 ;
goto V_117;
}
V_133 = F_320 ( V_162 , V_116 + 1 , V_59 ) ;
if ( ! V_133 )
goto V_409;
* ( V_133 + V_116 ) = '\0' ;
V_45 -> V_133 = V_133 ;
V_74 = F_279 ( sizeof ( * V_74 ) , V_59 ) ;
if ( ! V_74 )
goto V_409;
V_74 -> V_28 = V_411 ;
V_408 = F_322 ( V_100 , V_406 ,
V_406 + V_407 - 1 ,
F_44 , V_74 ) ;
if ( F_30 ( V_408 ) ) {
V_39 = F_197 ( V_408 ) ;
goto V_117;
}
F_36 ( V_100 ) ;
* V_55 = V_408 ;
* V_405 = V_74 ;
* V_360 = V_45 ;
return 0 ;
V_409:
V_39 = - V_57 ;
V_117:
F_36 ( V_74 ) ;
F_170 ( V_45 ) ;
F_36 ( V_100 ) ;
return V_39 ;
}
static int F_323 ( struct V_53 * V_56 , const char * V_355 )
{
V_106 V_412 ;
unsigned long V_413 = V_56 -> V_63 -> V_100 -> V_414 * V_415 ;
int V_416 = 0 ;
int V_39 ;
V_417:
V_39 = F_324 ( V_56 -> V_63 -> V_206 . V_387 , V_355 ) ;
if ( V_39 == - V_34 && V_416 ++ < 1 ) {
V_39 = F_325 ( & V_56 -> V_63 -> V_418 , L_108 ,
& V_412 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_56 -> V_63 -> V_206 . V_387 -> V_419 < V_412 ) {
F_326 ( & V_56 -> V_63 -> V_418 ) ;
( void ) F_327 ( & V_56 -> V_63 -> V_418 ,
V_412 , V_413 ) ;
goto V_417;
} else {
return - V_34 ;
}
}
return V_39 ;
}
static int F_328 ( struct V_21 * V_22 )
{
int V_39 ;
T_6 V_96 ;
char * V_239 ;
void * V_420 ;
char * V_358 ;
if ( V_22 -> V_45 -> V_358 ) {
V_22 -> V_93 = * V_22 -> V_45 -> V_358 ? 2 : 1 ;
return 0 ;
}
V_96 = sizeof ( V_421 ) + strlen ( V_22 -> V_45 -> V_357 ) ;
V_239 = F_26 ( V_96 , V_148 ) ;
if ( ! V_239 )
return - V_57 ;
sprintf ( V_239 , L_109 , V_421 , V_22 -> V_45 -> V_357 ) ;
F_25 ( L_110 , V_239 ) ;
V_96 = sizeof ( V_283 ) + V_380 ;
V_420 = F_279 ( V_96 , V_148 ) ;
if ( ! V_420 ) {
V_39 = - V_57 ;
goto V_49;
}
V_39 = F_216 ( V_22 , V_239 ,
L_41 , L_111 , NULL , 0 ,
V_420 , V_380 ) ;
F_25 ( L_75 , V_58 , V_39 ) ;
if ( V_39 == - V_34 ) {
V_358 = F_66 ( L_71 , V_59 ) ;
V_39 = V_358 ? 0 : - V_57 ;
if ( ! V_39 )
V_22 -> V_93 = 1 ;
} else if ( V_39 >= 0 ) {
void * V_374 = V_420 ;
V_358 = F_289 ( & V_374 , V_374 + V_39 ,
NULL , V_148 ) ;
V_39 = F_329 ( V_358 ) ;
if ( ! V_39 )
V_22 -> V_93 = 2 ;
}
if ( ! V_39 ) {
V_22 -> V_45 -> V_358 = V_358 ;
F_25 ( L_112 , V_358 ) ;
}
V_49:
F_36 ( V_420 ) ;
F_36 ( V_239 ) ;
return V_39 ;
}
static void F_330 ( struct V_21 * V_22 )
{
struct V_108 * V_109 ;
F_171 ( V_22 ) ;
V_109 = & V_22 -> V_109 ;
F_64 ( V_109 -> V_112 ) ;
F_36 ( V_109 -> V_114 ) ;
F_36 ( V_109 -> V_113 ) ;
F_36 ( V_109 -> V_111 ) ;
memset ( V_109 , 0 , sizeof ( * V_109 ) ) ;
}
static int F_307 ( struct V_21 * V_22 )
{
int V_39 ;
V_39 = F_288 ( V_22 ) ;
if ( V_39 )
goto V_117;
V_39 = F_290 ( V_22 ) ;
if ( V_39 )
goto V_117;
if ( V_22 -> V_109 . V_130 & V_422 ) {
V_39 = F_293 ( V_22 ) ;
if ( V_39 < 0 )
goto V_117;
}
return 0 ;
V_117:
V_22 -> V_109 . V_130 = 0 ;
F_36 ( V_22 -> V_109 . V_111 ) ;
V_22 -> V_109 . V_111 = NULL ;
return V_39 ;
}
static int F_331 ( struct V_21 * V_22 )
{
struct V_21 * V_266 = NULL ;
struct V_360 * V_257 ;
struct V_53 * V_56 ;
int V_39 ;
if ( ! V_22 -> V_257 )
return 0 ;
V_257 = F_277 ( V_22 -> V_257 ) ;
V_56 = F_39 ( V_22 -> V_53 ) ;
V_39 = - V_57 ;
V_266 = F_280 ( V_56 , V_257 ) ;
if ( ! V_266 )
goto V_117;
V_39 = F_332 ( V_266 , false ) ;
if ( V_39 < 0 )
goto V_117;
V_22 -> V_266 = V_266 ;
F_282 ( & V_22 -> V_258 , 1 ) ;
return 0 ;
V_117:
if ( V_266 ) {
F_168 ( V_22 ) ;
F_36 ( V_22 -> V_288 ) ;
F_285 ( V_266 ) ;
} else {
F_55 ( V_56 ) ;
F_170 ( V_257 ) ;
}
return V_39 ;
}
static int F_333 ( struct V_21 * V_22 )
{
int V_39 ;
V_39 = F_313 ( V_22 ) ;
if ( V_39 )
return V_39 ;
F_334 ( V_423
< sizeof ( V_341 ) + V_424 ) ;
sprintf ( V_22 -> V_143 , L_113 , V_341 , V_22 -> V_5 ) ;
if ( ! V_13 ) {
V_39 = F_335 ( 0 , V_22 -> V_143 ) ;
if ( V_39 < 0 )
goto V_425;
V_22 -> V_342 = V_39 ;
V_22 -> V_7 = 0 ;
} else {
V_22 -> V_342 = V_426 ;
V_22 -> V_7 = F_7 ( V_22 -> V_5 ) ;
}
V_39 = F_252 ( V_22 ) ;
if ( V_39 )
goto V_427;
V_39 = F_76 ( V_22 ) ;
if ( V_39 )
goto V_428;
F_246 ( V_22 -> V_36 , V_22 -> V_27 . V_96 / V_338 ) ;
F_21 ( V_22 -> V_36 , V_22 -> V_27 . V_28 ) ;
V_39 = F_308 ( V_22 ) ;
if ( V_39 )
goto V_429;
F_111 ( V_310 , & V_22 -> V_32 ) ;
F_336 ( V_22 -> V_36 ) ;
F_292 ( L_114 , V_22 -> V_36 -> V_340 ,
( unsigned long long ) V_22 -> V_27 . V_96 ) ;
return V_39 ;
V_429:
F_77 ( V_22 ) ;
V_428:
F_238 ( V_22 ) ;
V_427:
if ( ! V_13 )
F_337 ( V_22 -> V_342 , V_22 -> V_143 ) ;
V_425:
F_315 ( V_22 ) ;
F_77 ( V_22 ) ;
return V_39 ;
}
static int F_338 ( struct V_21 * V_22 )
{
struct V_360 * V_45 = V_22 -> V_45 ;
T_6 V_96 ;
F_17 ( F_57 ( V_22 -> V_93 ) ) ;
if ( V_22 -> V_93 == 1 )
V_96 = strlen ( V_45 -> V_357 ) + sizeof ( V_430 ) ;
else
V_96 = sizeof ( V_431 ) + strlen ( V_45 -> V_358 ) ;
V_22 -> V_288 = F_26 ( V_96 , V_59 ) ;
if ( ! V_22 -> V_288 )
return - V_57 ;
if ( V_22 -> V_93 == 1 )
sprintf ( V_22 -> V_288 , L_109 ,
V_45 -> V_357 , V_430 ) ;
else
sprintf ( V_22 -> V_288 , L_109 ,
V_431 , V_45 -> V_358 ) ;
return 0 ;
}
static void F_339 ( struct V_21 * V_22 )
{
F_330 ( V_22 ) ;
F_36 ( V_22 -> V_288 ) ;
V_22 -> V_288 = NULL ;
V_22 -> V_93 = 0 ;
F_36 ( V_22 -> V_45 -> V_358 ) ;
V_22 -> V_45 -> V_358 = NULL ;
F_285 ( V_22 ) ;
}
static int F_332 ( struct V_21 * V_22 , bool V_27 )
{
int V_39 ;
V_39 = F_328 ( V_22 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_338 ( V_22 ) ;
if ( V_39 )
goto V_432;
if ( V_27 ) {
V_39 = F_212 ( V_22 ) ;
if ( V_39 )
goto V_433;
}
V_39 = F_249 ( V_22 ) ;
if ( V_39 )
goto V_434;
if ( V_27 )
V_39 = F_300 ( V_22 ) ;
else
V_39 = F_301 ( V_22 ) ;
if ( V_39 )
goto V_435;
if ( V_22 -> V_109 . V_130 & V_436 ) {
V_39 = F_250 ( V_22 ) ;
if ( V_39 )
goto V_435;
if ( V_27 && V_22 -> V_257 )
F_103 ( V_22 ,
L_115 ) ;
}
V_39 = F_331 ( V_22 ) ;
if ( V_39 )
goto V_435;
F_25 ( L_116 ,
V_22 -> V_93 , V_22 -> V_288 ) ;
return 0 ;
V_435:
F_330 ( V_22 ) ;
V_434:
if ( V_27 )
F_215 ( V_22 ) ;
V_433:
F_36 ( V_22 -> V_288 ) ;
V_22 -> V_288 = NULL ;
V_432:
V_22 -> V_93 = 0 ;
F_36 ( V_22 -> V_45 -> V_358 ) ;
V_22 -> V_45 -> V_358 = NULL ;
return V_39 ;
}
static T_11 F_340 ( struct V_437 * V_390 ,
const char * V_162 ,
T_6 V_359 )
{
struct V_21 * V_22 = NULL ;
struct V_54 * V_55 = NULL ;
struct V_73 * V_74 = NULL ;
struct V_360 * V_45 = NULL ;
struct V_53 * V_56 ;
bool V_28 ;
int V_438 = - V_57 ;
if ( ! F_341 ( V_439 ) )
return - V_440 ;
V_438 = F_321 ( V_162 , & V_55 , & V_74 , & V_45 ) ;
if ( V_438 < 0 )
goto V_441;
V_28 = V_74 -> V_28 ;
F_36 ( V_74 ) ;
V_74 = NULL ;
V_56 = F_49 ( V_55 ) ;
if ( F_30 ( V_56 ) ) {
V_438 = F_197 ( V_56 ) ;
goto V_442;
}
V_438 = F_323 ( V_56 , V_45 -> V_355 ) ;
if ( V_438 < 0 )
goto V_443;
V_45 -> V_356 = ( V_106 ) V_438 ;
if ( V_45 -> V_356 > ( V_106 ) V_381 ) {
F_103 ( NULL , L_117 ,
( unsigned long long ) V_45 -> V_356 , V_381 ) ;
V_438 = - V_131 ;
goto V_443;
}
V_22 = F_280 ( V_56 , V_45 ) ;
if ( ! V_22 )
goto V_443;
V_56 = NULL ;
V_45 = NULL ;
V_438 = F_332 ( V_22 , true ) ;
if ( V_438 < 0 )
goto V_444;
if ( V_22 -> V_45 -> V_46 != V_47 )
V_28 = true ;
V_22 -> V_27 . V_28 = V_28 ;
V_438 = F_333 ( V_22 ) ;
if ( V_438 ) {
F_215 ( V_22 ) ;
F_339 ( V_22 ) ;
goto V_441;
}
return V_359 ;
V_444:
F_285 ( V_22 ) ;
V_443:
F_55 ( V_56 ) ;
V_442:
F_170 ( V_45 ) ;
V_441:
F_342 ( V_439 ) ;
F_25 ( L_118 , V_162 ) ;
return ( T_11 ) V_438 ;
}
static T_11 F_343 ( struct V_437 * V_390 ,
const char * V_162 ,
T_6 V_359 )
{
if ( V_13 )
return - V_4 ;
return F_340 ( V_390 , V_162 , V_359 ) ;
}
static T_11 F_344 ( struct V_437 * V_390 ,
const char * V_162 ,
T_6 V_359 )
{
return F_340 ( V_390 , V_162 , V_359 ) ;
}
static void V_395 ( struct V_17 * V_18 )
{
struct V_21 * V_22 = F_262 ( V_18 ) ;
F_238 ( V_22 ) ;
F_139 ( V_310 , & V_22 -> V_32 ) ;
F_77 ( V_22 ) ;
if ( ! V_13 )
F_337 ( V_22 -> V_342 , V_22 -> V_143 ) ;
F_315 ( V_22 ) ;
F_77 ( V_22 ) ;
}
static void F_169 ( struct V_21 * V_22 )
{
while ( V_22 -> V_266 ) {
struct V_21 * V_445 = V_22 ;
struct V_21 * V_446 = V_445 -> V_266 ;
struct V_21 * V_447 ;
while ( V_446 && ( V_447 = V_446 -> V_266 ) ) {
V_445 = V_446 ;
V_446 = V_447 ;
}
F_17 ( V_446 ) ;
F_339 ( V_446 ) ;
V_445 -> V_266 = NULL ;
V_445 -> V_190 = 0 ;
F_17 ( V_445 -> V_257 ) ;
F_170 ( V_445 -> V_257 ) ;
V_445 -> V_257 = NULL ;
}
}
static T_11 F_345 ( struct V_437 * V_390 ,
const char * V_162 ,
T_6 V_359 )
{
struct V_21 * V_22 = NULL ;
struct V_448 * V_155 ;
int V_5 ;
unsigned long V_449 ;
bool V_450 = false ;
int V_39 ;
V_39 = F_346 ( V_162 , 10 , & V_449 ) ;
if ( V_39 )
return V_39 ;
V_5 = ( int ) V_449 ;
if ( V_5 != V_449 )
return - V_4 ;
V_39 = - V_34 ;
F_32 ( & V_399 ) ;
F_347 (tmp, &rbd_dev_list) {
V_22 = F_348 ( V_155 , struct V_21 , V_62 ) ;
if ( V_22 -> V_5 == V_5 ) {
V_39 = 0 ;
break;
}
}
if ( ! V_39 ) {
F_12 ( & V_22 -> V_30 ) ;
if ( V_22 -> V_33 )
V_39 = - V_48 ;
else
V_450 = F_105 ( V_31 ,
& V_22 -> V_32 ) ;
F_14 ( & V_22 -> V_30 ) ;
}
F_34 ( & V_399 ) ;
if ( V_39 < 0 || V_450 )
return V_39 ;
F_215 ( V_22 ) ;
F_25 ( L_119 , V_58 ) ;
F_349 ( & V_22 -> V_53 -> V_63 -> V_206 ) ;
F_311 ( V_22 ) ;
F_339 ( V_22 ) ;
F_342 ( V_439 ) ;
return V_359 ;
}
static T_11 F_350 ( struct V_437 * V_390 ,
const char * V_162 ,
T_6 V_359 )
{
if ( V_13 )
return - V_4 ;
return F_345 ( V_390 , V_162 , V_359 ) ;
}
static T_11 F_351 ( struct V_437 * V_390 ,
const char * V_162 ,
T_6 V_359 )
{
return F_345 ( V_390 , V_162 , V_359 ) ;
}
static int F_352 ( void )
{
int V_39 ;
V_39 = F_310 ( & V_393 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_353 ( & V_391 ) ;
if ( V_39 < 0 )
F_312 ( & V_393 ) ;
return V_39 ;
}
static void F_354 ( void )
{
F_355 ( & V_391 ) ;
F_312 ( & V_393 ) ;
}
static int F_356 ( void )
{
F_17 ( ! V_260 ) ;
V_260 = F_357 ( L_120 ,
sizeof ( struct V_193 ) ,
F_358 ( struct V_193 ) ,
0 , NULL ) ;
if ( ! V_260 )
return - V_57 ;
F_17 ( ! V_255 ) ;
V_255 = F_357 ( L_121 ,
sizeof ( struct V_181 ) ,
F_358 ( struct V_181 ) ,
0 , NULL ) ;
if ( ! V_255 )
goto V_117;
F_17 ( ! V_144 ) ;
V_144 = F_357 ( L_122 ,
V_149 + 1 , 1 , 0 , NULL ) ;
if ( V_144 )
return 0 ;
V_117:
if ( V_255 ) {
F_359 ( V_255 ) ;
V_255 = NULL ;
}
F_359 ( V_260 ) ;
V_260 = NULL ;
return - V_57 ;
}
static void F_360 ( void )
{
F_17 ( V_144 ) ;
F_359 ( V_144 ) ;
V_144 = NULL ;
F_17 ( V_255 ) ;
F_359 ( V_255 ) ;
V_255 = NULL ;
F_17 ( V_260 ) ;
F_359 ( V_260 ) ;
V_260 = NULL ;
}
static int T_12 F_361 ( void )
{
int V_438 ;
if ( ! F_362 ( NULL ) ) {
F_103 ( NULL , L_123 ) ;
return - V_4 ;
}
V_438 = F_356 () ;
if ( V_438 )
return V_438 ;
V_326 = F_363 ( V_341 , V_451 , 0 ) ;
if ( ! V_326 ) {
V_438 = - V_57 ;
goto V_452;
}
if ( V_13 ) {
V_426 = F_335 ( 0 , V_341 ) ;
if ( V_426 < 0 ) {
V_438 = V_426 ;
goto V_453;
}
}
V_438 = F_352 () ;
if ( V_438 )
goto V_427;
if ( V_13 )
F_292 ( L_124 , V_426 ) ;
else
F_292 ( L_125 ) ;
return 0 ;
V_427:
if ( V_13 )
F_337 ( V_426 , V_341 ) ;
V_453:
F_364 ( V_326 ) ;
V_452:
F_360 () ;
return V_438 ;
}
static void T_13 F_365 ( void )
{
F_366 ( & V_397 ) ;
F_354 () ;
if ( V_13 )
F_337 ( V_426 , V_341 ) ;
F_364 ( V_326 ) ;
F_360 () ;
}
