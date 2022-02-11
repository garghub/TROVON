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
if ( V_77 < V_80 ) {
V_39 = F_46 ( & V_75 [ 0 ] , & V_78 ) ;
if ( V_39 < 0 ) {
F_47 ( L_4 , V_71 ) ;
return V_39 ;
}
F_25 ( L_5 , V_77 , V_78 ) ;
} else if ( V_77 > V_80 && V_77 < V_81 ) {
F_25 ( L_6 , V_77 , V_75 [ 0 ] . V_82 ) ;
} else {
F_25 ( L_7 , V_77 ) ;
}
switch ( V_77 ) {
case V_83 :
if ( V_78 < 1 ) {
F_47 ( L_8 ) ;
return - V_4 ;
}
V_74 -> V_84 = V_78 ;
break;
case V_85 :
V_74 -> V_28 = true ;
break;
case V_86 :
V_74 -> V_28 = false ;
break;
default:
return - V_4 ;
}
return 0 ;
}
static char * F_48 ( enum V_87 V_88 )
{
switch ( V_88 ) {
case V_89 :
return L_9 ;
case V_90 :
return L_10 ;
case V_91 :
return L_11 ;
default:
return L_12 ;
}
}
static struct V_53 * F_49 ( struct V_54 * V_55 )
{
struct V_53 * V_56 ;
F_50 ( & V_92 , V_93 ) ;
V_56 = F_41 ( V_55 ) ;
if ( V_56 )
F_37 ( V_55 ) ;
else
V_56 = F_24 ( V_55 ) ;
F_51 ( & V_92 ) ;
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
static bool F_57 ( T_5 V_94 )
{
return V_94 == 1 || V_94 == 2 ;
}
static bool F_58 ( struct V_95 * V_96 )
{
T_6 V_97 ;
T_5 V_98 ;
if ( memcmp ( & V_96 -> V_99 , V_100 , sizeof ( V_100 ) ) )
return false ;
if ( V_96 -> V_101 . V_102 < V_103 )
return false ;
if ( V_96 -> V_101 . V_102 > 8 * sizeof ( int ) - 1 )
return false ;
V_98 = F_59 ( V_96 -> V_98 ) ;
V_97 = V_104 - sizeof ( struct V_105 ) ;
if ( V_98 > V_97 / sizeof ( V_106 ) )
return false ;
V_97 -= V_98 * sizeof ( V_106 ) ;
if ( ( V_107 ) V_97 < F_60 ( V_96 -> V_108 ) )
return false ;
return true ;
}
static int F_61 ( struct V_21 * V_22 ,
struct V_95 * V_96 )
{
struct V_109 * V_110 = & V_22 -> V_110 ;
bool V_111 = V_110 -> V_112 == NULL ;
struct V_105 * V_113 ;
char * V_112 = NULL ;
char * V_114 = NULL ;
V_107 * V_115 = NULL ;
T_5 V_98 ;
T_6 V_97 ;
int V_39 = - V_57 ;
T_5 V_116 ;
if ( V_111 ) {
T_6 V_117 ;
V_117 = F_62 ( V_96 -> V_112 ,
sizeof ( V_96 -> V_112 ) ) ;
V_112 = F_26 ( V_117 + 1 , V_59 ) ;
if ( ! V_112 )
return - V_57 ;
memcpy ( V_112 , V_96 -> V_112 , V_117 ) ;
V_112 [ V_117 ] = '\0' ;
}
V_98 = F_59 ( V_96 -> V_98 ) ;
V_113 = F_63 ( V_98 , V_59 ) ;
if ( ! V_113 )
goto V_118;
V_113 -> V_119 = F_60 ( V_96 -> V_120 ) ;
if ( V_98 ) {
struct V_121 * V_122 ;
V_107 V_108 = F_60 ( V_96 -> V_108 ) ;
if ( V_108 > ( V_107 ) V_104 )
goto V_123;
V_114 = F_26 ( V_108 , V_59 ) ;
if ( ! V_114 )
goto V_118;
V_97 = V_98 * sizeof ( * V_110 -> V_115 ) ;
V_115 = F_26 ( V_97 , V_59 ) ;
if ( ! V_115 )
goto V_118;
memcpy ( V_114 , & V_96 -> V_122 [ V_98 ] , V_108 ) ;
V_122 = V_96 -> V_122 ;
for ( V_116 = 0 ; V_116 < V_98 ; V_116 ++ ) {
V_113 -> V_122 [ V_116 ] = F_60 ( V_122 [ V_116 ] . V_124 ) ;
V_115 [ V_116 ] = F_60 ( V_122 [ V_116 ] . V_125 ) ;
}
}
if ( V_111 ) {
V_110 -> V_112 = V_112 ;
V_110 -> V_126 = V_96 -> V_101 . V_102 ;
V_110 -> V_127 = V_96 -> V_101 . V_127 ;
V_110 -> V_128 = V_96 -> V_101 . V_128 ;
V_110 -> V_129 = 0 ;
V_110 -> V_130 = 0 ;
V_110 -> V_131 = 0 ;
} else {
F_64 ( V_110 -> V_113 ) ;
F_36 ( V_110 -> V_114 ) ;
F_36 ( V_110 -> V_115 ) ;
}
V_110 -> V_125 = F_60 ( V_96 -> V_125 ) ;
V_110 -> V_113 = V_113 ;
V_110 -> V_114 = V_114 ;
V_110 -> V_115 = V_115 ;
return 0 ;
V_123:
V_39 = - V_132 ;
V_118:
F_36 ( V_115 ) ;
F_36 ( V_114 ) ;
F_64 ( V_113 ) ;
F_36 ( V_112 ) ;
return V_39 ;
}
static const char * F_65 ( struct V_21 * V_22 , T_5 V_133 )
{
const char * V_134 ;
F_17 ( V_133 < V_22 -> V_110 . V_113 -> V_135 ) ;
V_134 = V_22 -> V_110 . V_114 ;
while ( V_133 -- )
V_134 += strlen ( V_134 ) + 1 ;
return F_66 ( V_134 , V_59 ) ;
}
static int F_67 ( const void * V_136 , const void * V_137 )
{
V_107 V_138 = * ( V_107 * ) V_136 ;
V_107 V_139 = * ( V_107 * ) V_137 ;
if ( V_138 < V_139 )
return 1 ;
return V_138 == V_139 ? 0 : - 1 ;
}
static T_5 F_68 ( struct V_21 * V_22 , V_107 V_46 )
{
struct V_105 * V_113 = V_22 -> V_110 . V_113 ;
V_107 * V_69 ;
V_69 = bsearch ( & V_46 , & V_113 -> V_122 , V_113 -> V_135 ,
sizeof ( V_46 ) , F_67 ) ;
return V_69 ? ( T_5 ) ( V_69 - & V_113 -> V_122 [ 0 ] ) : V_140 ;
}
static const char * F_69 ( struct V_21 * V_22 ,
V_107 V_46 )
{
T_5 V_133 ;
const char * V_134 ;
V_133 = F_68 ( V_22 , V_46 ) ;
if ( V_133 == V_140 )
return F_38 ( - V_34 ) ;
V_134 = F_65 ( V_22 , V_133 ) ;
return V_134 ? V_134 : F_38 ( - V_57 ) ;
}
static const char * F_70 ( struct V_21 * V_22 , V_107 V_46 )
{
if ( V_46 == V_47 )
return V_141 ;
F_17 ( F_57 ( V_22 -> V_94 ) ) ;
if ( V_22 -> V_94 == 1 )
return F_69 ( V_22 , V_46 ) ;
return F_71 ( V_22 , V_46 ) ;
}
static int F_72 ( struct V_21 * V_22 , V_107 V_46 ,
V_107 * V_142 )
{
F_17 ( F_57 ( V_22 -> V_94 ) ) ;
if ( V_46 == V_47 ) {
* V_142 = V_22 -> V_110 . V_125 ;
} else if ( V_22 -> V_94 == 1 ) {
T_5 V_133 ;
V_133 = F_68 ( V_22 , V_46 ) ;
if ( V_133 == V_140 )
return - V_34 ;
* V_142 = V_22 -> V_110 . V_115 [ V_133 ] ;
} else {
V_107 V_97 = 0 ;
int V_39 ;
V_39 = F_73 ( V_22 , V_46 , NULL , & V_97 ) ;
if ( V_39 )
return V_39 ;
* V_142 = V_97 ;
}
return 0 ;
}
static int F_74 ( struct V_21 * V_22 , V_107 V_46 ,
V_107 * V_143 )
{
F_17 ( F_57 ( V_22 -> V_94 ) ) ;
if ( V_46 == V_47 ) {
* V_143 = V_22 -> V_110 . V_131 ;
} else if ( V_22 -> V_94 == 1 ) {
* V_143 = 0 ;
} else {
V_107 V_131 = 0 ;
int V_39 ;
V_39 = F_75 ( V_22 , V_46 , & V_131 ) ;
if ( V_39 )
return V_39 ;
* V_143 = V_131 ;
}
return 0 ;
}
static int F_76 ( struct V_21 * V_22 )
{
V_107 V_46 = V_22 -> V_45 -> V_46 ;
V_107 V_97 = 0 ;
V_107 V_131 = 0 ;
int V_39 ;
V_39 = F_72 ( V_22 , V_46 , & V_97 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_74 ( V_22 , V_46 , & V_131 ) ;
if ( V_39 )
return V_39 ;
V_22 -> V_27 . V_97 = V_97 ;
V_22 -> V_27 . V_131 = V_131 ;
return 0 ;
}
static void F_77 ( struct V_21 * V_22 )
{
V_22 -> V_27 . V_97 = 0 ;
V_22 -> V_27 . V_131 = 0 ;
}
static void F_78 ( const char * V_144 )
{
F_79 ( V_145 , ( void * ) V_144 ) ;
}
static const char * F_80 ( struct V_21 * V_22 , V_107 V_146 )
{
char * V_144 ;
V_107 V_147 ;
int V_39 ;
char * V_148 ;
V_144 = F_81 ( V_145 , V_149 ) ;
if ( ! V_144 )
return NULL ;
V_147 = V_146 >> V_22 -> V_110 . V_126 ;
V_148 = L_13 ;
if ( V_22 -> V_94 == 2 )
V_148 = L_14 ;
V_39 = snprintf ( V_144 , V_150 + 1 , V_148 ,
V_22 -> V_110 . V_112 , V_147 ) ;
if ( V_39 < 0 || V_39 > V_150 ) {
F_47 ( L_15 ,
V_147 , V_39 ) ;
F_78 ( V_144 ) ;
V_144 = NULL ;
}
return V_144 ;
}
static V_107 F_82 ( struct V_21 * V_22 , V_107 V_146 )
{
V_107 V_151 = ( V_107 ) 1 << V_22 -> V_110 . V_126 ;
return V_146 & ( V_151 - 1 ) ;
}
static V_107 F_83 ( struct V_21 * V_22 ,
V_107 V_146 , V_107 V_152 )
{
V_107 V_151 = ( V_107 ) 1 << V_22 -> V_110 . V_126 ;
V_146 &= V_151 - 1 ;
F_17 ( V_152 <= V_153 - V_146 ) ;
if ( V_146 + V_152 > V_151 )
V_152 = V_151 - V_146 ;
return V_152 ;
}
static V_107 F_84 ( struct V_109 * V_110 )
{
return 1 << V_110 -> V_126 ;
}
static void F_85 ( struct V_154 * V_155 )
{
struct V_154 * V_156 ;
while ( V_155 ) {
V_156 = V_155 ;
V_155 = V_155 -> V_157 ;
F_86 ( V_156 ) ;
}
}
static void F_87 ( struct V_154 * V_155 , int V_158 )
{
struct V_159 V_160 ;
struct V_161 V_162 ;
unsigned long V_32 ;
void * V_163 ;
int V_164 = 0 ;
while ( V_155 ) {
F_88 (bv, chain, iter) {
if ( V_164 + V_160 . V_165 > V_158 ) {
int V_166 = F_89 ( V_158 - V_164 , 0 ) ;
V_163 = F_90 ( & V_160 , & V_32 ) ;
memset ( V_163 + V_166 , 0 ,
V_160 . V_165 - V_166 ) ;
F_91 ( V_160 . V_167 ) ;
F_92 ( V_163 , & V_32 ) ;
}
V_164 += V_160 . V_165 ;
}
V_155 = V_155 -> V_157 ;
}
}
static void F_93 ( struct V_168 * * V_169 , V_107 V_146 , V_107 V_170 )
{
struct V_168 * * V_168 = & V_169 [ V_146 >> V_171 ] ;
F_17 ( V_170 > V_146 ) ;
F_17 ( V_170 - V_146 <= ( V_107 ) V_104 ) ;
while ( V_146 < V_170 ) {
T_6 V_172 ;
T_6 V_152 ;
unsigned long V_32 ;
void * V_173 ;
V_172 = V_146 & ~ V_174 ;
V_152 = F_94 ( T_6 , V_175 - V_172 , V_170 - V_146 ) ;
F_95 ( V_32 ) ;
V_173 = F_96 ( * V_168 ) ;
memset ( V_173 + V_172 , 0 , V_152 ) ;
F_91 ( * V_168 ) ;
F_97 ( V_173 ) ;
F_98 ( V_32 ) ;
V_146 += V_152 ;
V_168 ++ ;
}
}
static struct V_154 * F_99 ( struct V_154 * V_176 ,
unsigned int V_146 ,
unsigned int V_117 ,
T_7 V_177 )
{
struct V_154 * V_154 ;
V_154 = F_100 ( V_176 , V_177 ) ;
if ( ! V_154 )
return NULL ;
F_101 ( V_154 , V_146 ) ;
V_154 -> V_178 . V_179 = V_117 ;
return V_154 ;
}
static struct V_154 * F_102 ( struct V_154 * * V_176 ,
unsigned int * V_146 ,
unsigned int V_117 ,
T_7 V_177 )
{
struct V_154 * V_180 = * V_176 ;
unsigned int V_181 = * V_146 ;
struct V_154 * V_155 = NULL ;
struct V_154 * * V_170 ;
if ( ! V_180 || V_181 >= V_180 -> V_178 . V_179 || ! V_117 )
return NULL ;
V_170 = & V_155 ;
while ( V_117 ) {
unsigned int V_179 ;
struct V_154 * V_154 ;
if ( ! V_180 ) {
F_103 ( NULL , L_16 , V_117 ) ;
goto V_118;
}
V_179 = F_94 (unsigned int, bi->bi_iter.bi_size - off, len) ;
V_154 = F_99 ( V_180 , V_181 , V_179 , V_177 ) ;
if ( ! V_154 )
goto V_118;
* V_170 = V_154 ;
V_170 = & V_154 -> V_157 ;
V_181 += V_179 ;
if ( V_181 == V_180 -> V_178 . V_179 ) {
V_180 = V_180 -> V_157 ;
V_181 = 0 ;
}
V_117 -= V_179 ;
}
* V_176 = V_180 ;
* V_146 = V_181 ;
return V_155 ;
V_118:
F_85 ( V_155 ) ;
return NULL ;
}
static void F_104 ( struct V_182 * V_183 )
{
if ( F_105 ( V_184 , & V_183 -> V_32 ) ) {
struct V_21 * V_22 ;
V_22 = V_183 -> V_185 -> V_22 ;
F_103 ( V_22 , L_17 ,
V_183 ) ;
}
}
static bool F_106 ( struct V_182 * V_183 )
{
F_107 () ;
return F_13 ( V_184 , & V_183 -> V_32 ) != 0 ;
}
static void F_108 ( struct V_182 * V_183 )
{
if ( F_105 ( V_186 , & V_183 -> V_32 ) ) {
struct V_21 * V_22 = NULL ;
if ( F_106 ( V_183 ) )
V_22 = V_183 -> V_185 -> V_22 ;
F_103 ( V_22 , L_18 ,
V_183 ) ;
}
}
static bool F_109 ( struct V_182 * V_183 )
{
F_107 () ;
return F_13 ( V_186 , & V_183 -> V_32 ) != 0 ;
}
static void F_110 ( struct V_182 * V_183 ,
bool V_187 )
{
if ( V_187 )
F_111 ( V_188 , & V_183 -> V_32 ) ;
F_111 ( V_189 , & V_183 -> V_32 ) ;
F_107 () ;
}
static bool F_112 ( struct V_182 * V_183 )
{
F_107 () ;
return F_13 ( V_189 , & V_183 -> V_32 ) != 0 ;
}
static bool F_113 ( struct V_182 * V_183 )
{
F_107 () ;
return F_13 ( V_188 , & V_183 -> V_32 ) != 0 ;
}
static bool F_114 ( struct V_182 * V_183 )
{
struct V_21 * V_22 = V_183 -> V_185 -> V_22 ;
return V_183 -> V_190 <
F_115 ( V_22 -> V_191 , F_84 ( & V_22 -> V_110 ) ) ;
}
static void F_116 ( struct V_182 * V_183 )
{
F_25 ( L_19 , V_58 , V_183 ,
F_117 ( & V_183 -> V_61 . V_192 ) ) ;
F_40 ( & V_183 -> V_61 ) ;
}
static void F_118 ( struct V_182 * V_183 )
{
F_17 ( V_183 != NULL ) ;
F_25 ( L_19 , V_58 , V_183 ,
F_117 ( & V_183 -> V_61 . V_192 ) ) ;
F_56 ( & V_183 -> V_61 , V_193 ) ;
}
static void F_119 ( struct V_194 * V_185 )
{
F_25 ( L_20 , V_58 , V_185 ,
F_117 ( & V_185 -> V_61 . V_192 ) ) ;
F_40 ( & V_185 -> V_61 ) ;
}
static void F_120 ( struct V_194 * V_185 )
{
F_17 ( V_185 != NULL ) ;
F_25 ( L_20 , V_58 , V_185 ,
F_117 ( & V_185 -> V_61 . V_192 ) ) ;
if ( F_121 ( V_185 ) )
F_56 ( & V_185 -> V_61 , V_195 ) ;
else
F_56 ( & V_185 -> V_61 , V_196 ) ;
}
static inline void F_122 ( struct V_194 * V_185 ,
struct V_182 * V_183 )
{
F_17 ( V_183 -> V_185 == NULL ) ;
V_183 -> V_185 = V_185 ;
V_183 -> V_133 = V_185 -> V_197 ;
F_17 ( ! F_106 ( V_183 ) ) ;
F_104 ( V_183 ) ;
F_17 ( V_183 -> V_133 != V_198 ) ;
V_185 -> V_197 ++ ;
F_33 ( & V_183 -> V_199 , & V_185 -> V_200 ) ;
F_25 ( L_21 , V_58 , V_185 , V_183 ,
V_183 -> V_133 ) ;
}
static inline void F_123 ( struct V_194 * V_185 ,
struct V_182 * V_183 )
{
F_17 ( V_183 -> V_133 != V_198 ) ;
F_25 ( L_21 , V_58 , V_185 , V_183 ,
V_183 -> V_133 ) ;
F_54 ( & V_183 -> V_199 ) ;
F_17 ( V_185 -> V_197 > 0 ) ;
V_185 -> V_197 -- ;
F_17 ( V_183 -> V_133 == V_185 -> V_197 ) ;
V_183 -> V_133 = V_198 ;
F_17 ( F_106 ( V_183 ) ) ;
F_17 ( V_183 -> V_185 == V_185 ) ;
V_183 -> V_185 = NULL ;
V_183 -> V_201 = NULL ;
F_118 ( V_183 ) ;
}
static bool F_124 ( enum V_202 type )
{
switch ( type ) {
case V_203 :
case V_204 :
case V_205 :
return true ;
default:
return false ;
}
}
static int F_125 ( struct V_206 * V_207 ,
struct V_182 * V_183 )
{
F_25 ( L_22 , V_58 , V_183 ) ;
return F_126 ( V_207 , V_183 -> V_208 , false ) ;
}
static void F_127 ( struct V_182 * V_183 )
{
F_25 ( L_22 , V_58 , V_183 ) ;
F_128 ( V_183 -> V_208 ) ;
}
static int F_129 ( struct V_182 * V_183 ,
unsigned long V_209 )
{
long V_39 ;
F_25 ( L_22 , V_58 , V_183 ) ;
V_39 = F_130 (
& V_183 -> V_210 ,
F_131 ( V_209 ) ) ;
if ( V_39 <= 0 ) {
if ( V_39 == 0 )
V_39 = - V_211 ;
F_127 ( V_183 ) ;
} else {
V_39 = 0 ;
}
F_25 ( L_23 , V_58 , V_183 , ( int ) V_39 ) ;
return V_39 ;
}
static int F_132 ( struct V_182 * V_183 )
{
return F_129 ( V_183 , 0 ) ;
}
static void F_133 ( struct V_194 * V_185 )
{
F_25 ( L_24 , V_58 , V_185 ) ;
if ( ! V_185 -> V_212 ) {
struct V_182 * V_183 ;
V_107 V_213 = 0 ;
F_134 (img_request, obj_request)
V_213 += V_183 -> V_213 ;
V_185 -> V_213 = V_213 ;
}
if ( V_185 -> V_201 )
V_185 -> V_201 ( V_185 ) ;
else
F_120 ( V_185 ) ;
}
static void F_135 ( struct V_194 * V_185 )
{
F_111 ( V_214 , & V_185 -> V_32 ) ;
F_107 () ;
}
static bool F_136 ( struct V_194 * V_185 )
{
F_107 () ;
return F_13 ( V_214 , & V_185 -> V_32 ) != 0 ;
}
static void F_137 ( struct V_194 * V_185 )
{
F_111 ( V_215 , & V_185 -> V_32 ) ;
F_107 () ;
}
static bool F_138 ( struct V_194 * V_185 )
{
F_107 () ;
return F_13 ( V_215 , & V_185 -> V_32 ) != 0 ;
}
static void F_139 ( struct V_194 * V_185 )
{
F_111 ( V_216 , & V_185 -> V_32 ) ;
F_107 () ;
}
static void F_140 ( struct V_194 * V_185 )
{
F_141 ( V_216 , & V_185 -> V_32 ) ;
F_107 () ;
}
static bool F_121 ( struct V_194 * V_185 )
{
F_107 () ;
return F_13 ( V_216 , & V_185 -> V_32 ) != 0 ;
}
static void F_142 ( struct V_194 * V_185 )
{
F_111 ( V_217 , & V_185 -> V_32 ) ;
F_107 () ;
}
static void F_143 ( struct V_194 * V_185 )
{
F_141 ( V_217 , & V_185 -> V_32 ) ;
F_107 () ;
}
static bool F_144 ( struct V_194 * V_185 )
{
F_107 () ;
return F_13 ( V_217 , & V_185 -> V_32 ) != 0 ;
}
static enum V_87
F_145 ( struct V_194 * V_185 )
{
if ( F_136 ( V_185 ) )
return V_90 ;
else if ( F_138 ( V_185 ) )
return V_91 ;
else
return V_89 ;
}
static void
F_146 ( struct V_182 * V_183 )
{
V_107 V_213 = V_183 -> V_213 ;
V_107 V_152 = V_183 -> V_152 ;
F_25 ( L_25 , V_58 ,
V_183 , V_183 -> V_185 , V_183 -> V_212 ,
V_213 , V_152 ) ;
F_17 ( V_183 -> type != V_203 ) ;
if ( V_183 -> V_212 == - V_34 ) {
if ( V_183 -> type == V_204 )
F_87 ( V_183 -> V_218 , 0 ) ;
else
F_93 ( V_183 -> V_169 , 0 , V_152 ) ;
V_183 -> V_212 = 0 ;
} else if ( V_213 < V_152 && ! V_183 -> V_212 ) {
if ( V_183 -> type == V_204 )
F_87 ( V_183 -> V_218 , V_213 ) ;
else
F_93 ( V_183 -> V_169 , V_213 , V_152 ) ;
}
V_183 -> V_213 = V_152 ;
F_108 ( V_183 ) ;
}
static void F_147 ( struct V_182 * V_183 )
{
F_25 ( L_26 , V_58 , V_183 ,
V_183 -> V_201 ) ;
if ( V_183 -> V_201 )
V_183 -> V_201 ( V_183 ) ;
else
F_148 ( & V_183 -> V_210 ) ;
}
static void F_149 ( struct V_182 * V_183 )
{
struct V_194 * V_185 = NULL ;
struct V_21 * V_22 = NULL ;
bool V_219 = false ;
if ( F_106 ( V_183 ) ) {
V_185 = V_183 -> V_185 ;
V_219 = V_185 && F_144 ( V_185 ) ;
V_22 = V_185 -> V_22 ;
}
F_25 ( L_25 , V_58 ,
V_183 , V_185 , V_183 -> V_212 ,
V_183 -> V_213 , V_183 -> V_152 ) ;
if ( V_219 && V_183 -> V_212 == - V_34 &&
V_183 -> V_190 < V_22 -> V_191 )
F_150 ( V_183 ) ;
else if ( V_185 )
F_146 ( V_183 ) ;
else
F_108 ( V_183 ) ;
}
static void F_151 ( struct V_182 * V_183 )
{
F_25 ( L_27 , V_58 , V_183 ,
V_183 -> V_212 , V_183 -> V_152 ) ;
V_183 -> V_213 = V_183 -> V_152 ;
F_108 ( V_183 ) ;
}
static void F_152 ( struct V_182 * V_183 )
{
F_25 ( L_27 , V_58 , V_183 ,
V_183 -> V_212 , V_183 -> V_152 ) ;
V_183 -> V_213 = V_183 -> V_152 ;
if ( V_183 -> V_212 == - V_34 )
V_183 -> V_212 = 0 ;
F_108 ( V_183 ) ;
}
static void F_153 ( struct V_182 * V_183 )
{
F_25 ( L_28 , V_58 , V_183 ) ;
F_108 ( V_183 ) ;
}
static void F_154 ( struct V_182 * V_183 )
{
F_25 ( L_28 , V_58 , V_183 ) ;
if ( F_106 ( V_183 ) )
F_155 ( V_183 ) ;
else
F_108 ( V_183 ) ;
}
static void F_156 ( struct V_220 * V_208 )
{
struct V_182 * V_183 = V_208 -> V_221 ;
T_8 V_222 ;
F_25 ( L_29 , V_58 , V_208 ) ;
F_17 ( V_208 == V_183 -> V_208 ) ;
if ( F_106 ( V_183 ) ) {
F_17 ( V_183 -> V_185 ) ;
F_17 ( V_183 -> V_133 != V_198 ) ;
} else {
F_17 ( V_183 -> V_133 == V_198 ) ;
}
if ( V_208 -> V_223 < 0 )
V_183 -> V_212 = V_208 -> V_223 ;
V_183 -> V_213 = V_208 -> V_224 [ 0 ] . V_225 ;
F_17 ( V_183 -> V_213 < ( V_107 ) V_226 ) ;
V_222 = V_208 -> V_224 [ 0 ] . V_227 ;
switch ( V_222 ) {
case V_228 :
F_149 ( V_183 ) ;
break;
case V_229 :
F_17 ( V_208 -> V_224 [ 1 ] . V_227 == V_230 ||
V_208 -> V_224 [ 1 ] . V_227 == V_231 ) ;
case V_230 :
case V_231 :
F_151 ( V_183 ) ;
break;
case V_232 :
F_153 ( V_183 ) ;
break;
case V_233 :
case V_234 :
case V_235 :
F_152 ( V_183 ) ;
break;
case V_236 :
F_154 ( V_183 ) ;
break;
default:
F_103 ( NULL , L_30 ,
V_183 -> V_237 , ( unsigned short ) V_222 ) ;
break;
}
if ( F_109 ( V_183 ) )
F_147 ( V_183 ) ;
}
static void F_157 ( struct V_182 * V_183 )
{
struct V_194 * V_185 = V_183 -> V_185 ;
struct V_220 * V_208 = V_183 -> V_208 ;
if ( V_185 )
V_208 -> V_238 = V_185 -> V_46 ;
}
static void F_158 ( struct V_182 * V_183 )
{
struct V_220 * V_208 = V_183 -> V_208 ;
V_208 -> V_239 = V_240 ;
V_208 -> V_241 = V_183 -> V_146 ;
}
static struct V_220 * F_159 (
struct V_21 * V_22 ,
enum V_87 V_88 ,
unsigned int V_242 ,
struct V_182 * V_183 )
{
struct V_105 * V_113 = NULL ;
struct V_206 * V_207 ;
struct V_220 * V_208 ;
if ( F_106 ( V_183 ) &&
( V_88 == V_91 || V_88 == V_90 ) ) {
struct V_194 * V_185 = V_183 -> V_185 ;
if ( V_88 == V_90 ) {
F_17 ( F_136 ( V_185 ) ) ;
} else {
F_17 ( F_138 ( V_185 ) ) ;
}
V_113 = V_185 -> V_113 ;
}
F_17 ( V_242 == 1 || ( ( V_88 == V_90 ) && V_242 == 2 ) ) ;
V_207 = & V_22 -> V_53 -> V_63 -> V_207 ;
V_208 = F_160 ( V_207 , V_113 , V_242 , false ,
V_149 ) ;
if ( ! V_208 )
goto V_243;
if ( V_88 == V_90 || V_88 == V_91 )
V_208 -> V_244 = V_245 | V_246 ;
else
V_208 -> V_244 = V_247 ;
V_208 -> V_248 = F_156 ;
V_208 -> V_221 = V_183 ;
V_208 -> V_249 . V_250 = F_161 ( V_22 -> V_251 ) ;
if ( F_162 ( & V_208 -> V_252 , V_149 , L_31 ,
V_183 -> V_237 ) )
goto V_243;
if ( F_163 ( V_208 , V_149 ) )
goto V_243;
return V_208 ;
V_243:
F_164 ( V_208 ) ;
return NULL ;
}
static struct V_220 *
F_165 ( struct V_182 * V_183 )
{
struct V_194 * V_185 ;
struct V_105 * V_113 ;
struct V_21 * V_22 ;
struct V_206 * V_207 ;
struct V_220 * V_208 ;
int V_253 = 3 ;
F_17 ( F_106 ( V_183 ) ) ;
V_185 = V_183 -> V_185 ;
F_17 ( V_185 ) ;
F_17 ( F_136 ( V_185 ) ||
F_138 ( V_185 ) ) ;
if ( F_138 ( V_185 ) )
V_253 = 2 ;
V_113 = V_185 -> V_113 ;
V_22 = V_185 -> V_22 ;
V_207 = & V_22 -> V_53 -> V_63 -> V_207 ;
V_208 = F_160 ( V_207 , V_113 , V_253 ,
false , V_149 ) ;
if ( ! V_208 )
goto V_243;
V_208 -> V_244 = V_245 | V_246 ;
V_208 -> V_248 = F_156 ;
V_208 -> V_221 = V_183 ;
V_208 -> V_249 . V_250 = F_161 ( V_22 -> V_251 ) ;
if ( F_162 ( & V_208 -> V_252 , V_149 , L_31 ,
V_183 -> V_237 ) )
goto V_243;
if ( F_163 ( V_208 , V_149 ) )
goto V_243;
return V_208 ;
V_243:
F_164 ( V_208 ) ;
return NULL ;
}
static void F_166 ( struct V_220 * V_208 )
{
F_164 ( V_208 ) ;
}
static struct V_182 * F_167 ( const char * V_237 ,
V_107 V_146 , V_107 V_152 ,
enum V_202 type )
{
struct V_182 * V_183 ;
T_6 V_97 ;
char * V_144 ;
F_17 ( F_124 ( type ) ) ;
V_97 = strlen ( V_237 ) + 1 ;
V_144 = F_26 ( V_97 , V_149 ) ;
if ( ! V_144 )
return NULL ;
V_183 = F_168 ( V_254 , V_149 ) ;
if ( ! V_183 ) {
F_36 ( V_144 ) ;
return NULL ;
}
V_183 -> V_237 = memcpy ( V_144 , V_237 , V_97 ) ;
V_183 -> V_146 = V_146 ;
V_183 -> V_152 = V_152 ;
V_183 -> V_32 = 0 ;
V_183 -> V_133 = V_198 ;
V_183 -> type = type ;
F_28 ( & V_183 -> V_199 ) ;
F_169 ( & V_183 -> V_210 ) ;
F_27 ( & V_183 -> V_61 ) ;
F_25 ( L_32 , V_58 , V_237 ,
V_146 , V_152 , ( int ) type , V_183 ) ;
return V_183 ;
}
static void V_193 ( struct V_61 * V_61 )
{
struct V_182 * V_183 ;
V_183 = F_53 ( V_61 , struct V_182 , V_61 ) ;
F_25 ( L_28 , V_58 , V_183 ) ;
F_17 ( V_183 -> V_185 == NULL ) ;
F_17 ( V_183 -> V_133 == V_198 ) ;
if ( V_183 -> V_208 )
F_166 ( V_183 -> V_208 ) ;
F_17 ( F_124 ( V_183 -> type ) ) ;
switch ( V_183 -> type ) {
case V_203 :
break;
case V_204 :
if ( V_183 -> V_218 )
F_85 ( V_183 -> V_218 ) ;
break;
case V_205 :
if ( V_183 -> V_169 )
F_170 ( V_183 -> V_169 ,
V_183 -> V_255 ) ;
break;
}
F_36 ( V_183 -> V_237 ) ;
V_183 -> V_237 = NULL ;
F_79 ( V_254 , V_183 ) ;
}
static void F_171 ( struct V_21 * V_22 )
{
F_172 ( V_22 ) ;
F_173 ( V_22 -> V_256 ) ;
V_22 -> V_256 = NULL ;
V_22 -> V_191 = 0 ;
}
static void F_174 ( struct V_21 * V_22 )
{
int V_2 ;
if ( ! V_22 -> V_256 )
return;
V_2 = F_4 ( & V_22 -> V_257 ) ;
if ( V_2 > 0 )
return;
if ( ! V_2 )
F_171 ( V_22 ) ;
else
F_103 ( V_22 , L_33 ) ;
}
static bool F_175 ( struct V_21 * V_22 )
{
int V_2 = 0 ;
if ( ! V_22 -> V_256 )
return false ;
F_176 ( & V_22 -> V_258 ) ;
if ( V_22 -> V_191 )
V_2 = F_1 ( & V_22 -> V_257 ) ;
F_177 ( & V_22 -> V_258 ) ;
if ( V_2 < 0 )
F_103 ( V_22 , L_34 ) ;
return V_2 > 0 ;
}
static struct V_194 * F_178 (
struct V_21 * V_22 ,
V_107 V_146 , V_107 V_152 ,
enum V_87 V_88 ,
struct V_105 * V_113 )
{
struct V_194 * V_185 ;
V_185 = F_81 ( V_259 , V_149 ) ;
if ( ! V_185 )
return NULL ;
V_185 -> V_260 = NULL ;
V_185 -> V_22 = V_22 ;
V_185 -> V_146 = V_146 ;
V_185 -> V_152 = V_152 ;
V_185 -> V_32 = 0 ;
if ( V_88 == V_91 ) {
F_137 ( V_185 ) ;
V_185 -> V_113 = V_113 ;
} else if ( V_88 == V_90 ) {
F_135 ( V_185 ) ;
V_185 -> V_113 = V_113 ;
} else {
V_185 -> V_46 = V_22 -> V_45 -> V_46 ;
}
if ( F_175 ( V_22 ) )
F_142 ( V_185 ) ;
F_179 ( & V_185 -> V_261 ) ;
V_185 -> V_262 = 0 ;
V_185 -> V_201 = NULL ;
V_185 -> V_212 = 0 ;
V_185 -> V_197 = 0 ;
F_28 ( & V_185 -> V_200 ) ;
F_27 ( & V_185 -> V_61 ) ;
F_25 ( L_35 , V_58 , V_22 ,
F_48 ( V_88 ) , V_146 , V_152 , V_185 ) ;
return V_185 ;
}
static void V_196 ( struct V_61 * V_61 )
{
struct V_194 * V_185 ;
struct V_182 * V_183 ;
struct V_182 * V_263 ;
V_185 = F_53 ( V_61 , struct V_194 , V_61 ) ;
F_25 ( L_24 , V_58 , V_185 ) ;
F_180 (img_request, obj_request, next_obj_request)
F_123 ( V_185 , V_183 ) ;
F_17 ( V_185 -> V_197 == 0 ) ;
if ( F_144 ( V_185 ) ) {
F_143 ( V_185 ) ;
F_174 ( V_185 -> V_22 ) ;
}
if ( F_136 ( V_185 ) ||
F_138 ( V_185 ) )
F_64 ( V_185 -> V_113 ) ;
F_79 ( V_259 , V_185 ) ;
}
static struct V_194 * F_181 (
struct V_182 * V_183 ,
V_107 V_190 , V_107 V_152 )
{
struct V_194 * V_264 ;
struct V_21 * V_22 ;
F_17 ( V_183 -> V_185 ) ;
V_22 = V_183 -> V_185 -> V_22 ;
V_264 = F_178 ( V_22 -> V_265 , V_190 ,
V_152 , V_89 , NULL ) ;
if ( ! V_264 )
return NULL ;
F_139 ( V_264 ) ;
F_116 ( V_183 ) ;
V_264 -> V_183 = V_183 ;
return V_264 ;
}
static void V_195 ( struct V_61 * V_61 )
{
struct V_194 * V_264 ;
struct V_182 * V_266 ;
V_264 = F_53 ( V_61 , struct V_194 , V_61 ) ;
V_266 = V_264 -> V_183 ;
V_264 -> V_183 = NULL ;
F_118 ( V_266 ) ;
F_140 ( V_264 ) ;
V_196 ( V_61 ) ;
}
static bool F_182 ( struct V_182 * V_183 )
{
struct V_194 * V_185 ;
unsigned int V_213 ;
int V_212 ;
bool V_267 ;
F_17 ( F_106 ( V_183 ) ) ;
V_185 = V_183 -> V_185 ;
F_17 ( V_183 -> V_213 <= ( V_107 ) V_226 ) ;
V_213 = ( unsigned int ) V_183 -> V_213 ;
V_212 = V_183 -> V_212 ;
if ( V_212 ) {
struct V_21 * V_22 = V_185 -> V_22 ;
enum V_87 V_88 ;
if ( F_138 ( V_185 ) )
V_88 = V_91 ;
else if ( F_136 ( V_185 ) )
V_88 = V_90 ;
else
V_88 = V_89 ;
F_103 ( V_22 , L_36 ,
F_48 ( V_88 ) , V_183 -> V_152 ,
V_183 -> V_190 , V_183 -> V_146 ) ;
F_103 ( V_22 , L_37 ,
V_212 , V_213 ) ;
if ( ! V_185 -> V_212 )
V_185 -> V_212 = V_212 ;
V_213 = V_183 -> V_152 ;
}
if ( V_183 -> type == V_205 ) {
V_183 -> V_169 = NULL ;
V_183 -> V_255 = 0 ;
}
if ( F_121 ( V_185 ) ) {
F_17 ( V_185 -> V_183 != NULL ) ;
V_267 = V_183 -> V_133 < V_185 -> V_197 - 1 ;
} else {
F_17 ( V_185 -> V_260 != NULL ) ;
V_267 = F_183 ( V_185 -> V_260 , V_212 , V_213 ) ;
if ( ! V_267 )
F_184 ( V_185 -> V_260 , V_212 ) ;
}
return V_267 ;
}
static void F_185 ( struct V_182 * V_183 )
{
struct V_194 * V_185 ;
T_5 V_133 = V_183 -> V_133 ;
bool V_267 = true ;
F_17 ( F_106 ( V_183 ) ) ;
V_185 = V_183 -> V_185 ;
F_25 ( L_38 , V_58 , V_185 , V_183 ) ;
F_17 ( V_185 != NULL ) ;
F_17 ( V_185 -> V_197 > 0 ) ;
F_17 ( V_133 != V_198 ) ;
F_17 ( V_133 < V_185 -> V_197 ) ;
F_12 ( & V_185 -> V_261 ) ;
if ( V_133 != V_185 -> V_262 )
goto V_49;
F_186 (img_request, obj_request) {
F_17 ( V_267 ) ;
F_17 ( V_133 < V_185 -> V_197 ) ;
if ( ! F_109 ( V_183 ) )
break;
V_267 = F_182 ( V_183 ) ;
V_133 ++ ;
}
F_17 ( V_267 ^ ( V_133 == V_185 -> V_197 ) ) ;
V_185 -> V_262 = V_133 ;
V_49:
F_14 ( & V_185 -> V_261 ) ;
F_120 ( V_185 ) ;
if ( ! V_267 )
F_133 ( V_185 ) ;
}
static void F_187 ( struct V_182 * V_183 ,
struct V_220 * V_268 ,
enum V_87 V_88 ,
unsigned int V_242 )
{
struct V_194 * V_185 = V_183 -> V_185 ;
struct V_21 * V_22 = V_185 -> V_22 ;
V_107 V_269 = F_84 ( & V_22 -> V_110 ) ;
V_107 V_146 = V_183 -> V_146 ;
V_107 V_152 = V_183 -> V_152 ;
V_107 V_270 ;
T_8 V_222 ;
if ( V_88 == V_91 ) {
if ( ! V_146 && V_152 == V_269 &&
( ! F_144 ( V_185 ) ||
! F_114 ( V_183 ) ) ) {
V_222 = V_233 ;
} else if ( ( V_146 + V_152 == V_269 ) ) {
V_222 = V_234 ;
} else {
F_176 ( & V_22 -> V_258 ) ;
V_270 = V_22 -> V_110 . V_125 ;
F_177 ( & V_22 -> V_258 ) ;
if ( V_183 -> V_190 + V_152 == V_270 )
V_222 = V_234 ;
else
V_222 = V_235 ;
}
} else if ( V_88 == V_90 ) {
if ( ! V_146 && V_152 == V_269 )
V_222 = V_231 ;
else
V_222 = V_230 ;
F_188 ( V_268 , V_242 ,
V_269 , V_269 ) ;
V_242 ++ ;
} else {
V_222 = V_228 ;
}
if ( V_222 == V_233 )
F_189 ( V_268 , V_242 , V_222 , 0 ) ;
else
F_190 ( V_268 , V_242 , V_222 ,
V_146 , V_152 , 0 , 0 ) ;
if ( V_183 -> type == V_204 )
F_191 ( V_268 , V_242 ,
V_183 -> V_218 , V_152 ) ;
else if ( V_183 -> type == V_205 )
F_192 ( V_268 , V_242 ,
V_183 -> V_169 , V_152 ,
V_146 & ~ V_174 , false , false ) ;
if ( V_88 == V_90 || V_88 == V_91 )
F_158 ( V_183 ) ;
else
F_157 ( V_183 ) ;
}
static int F_193 ( struct V_194 * V_185 ,
enum V_202 type ,
void * V_271 )
{
struct V_21 * V_22 = V_185 -> V_22 ;
struct V_182 * V_183 = NULL ;
struct V_182 * V_263 ;
struct V_154 * V_218 = NULL ;
unsigned int V_272 = 0 ;
struct V_168 * * V_169 = NULL ;
enum V_87 V_88 ;
V_107 V_190 ;
V_107 V_273 ;
F_25 ( L_39 , V_58 , V_185 ,
( int ) type , V_271 ) ;
V_190 = V_185 -> V_146 ;
V_273 = V_185 -> V_152 ;
F_17 ( V_273 > 0 ) ;
V_88 = F_145 ( V_185 ) ;
if ( type == V_204 ) {
V_218 = V_271 ;
F_17 ( V_190 ==
V_218 -> V_178 . V_274 << V_103 ) ;
} else if ( type == V_205 ) {
V_169 = V_271 ;
}
while ( V_273 ) {
struct V_220 * V_208 ;
const char * V_237 ;
V_107 V_146 ;
V_107 V_152 ;
V_237 = F_80 ( V_22 , V_190 ) ;
if ( ! V_237 )
goto V_275;
V_146 = F_82 ( V_22 , V_190 ) ;
V_152 = F_83 ( V_22 , V_190 , V_273 ) ;
V_183 = F_167 ( V_237 ,
V_146 , V_152 , type ) ;
F_78 ( V_237 ) ;
if ( ! V_183 )
goto V_275;
F_122 ( V_185 , V_183 ) ;
if ( type == V_204 ) {
unsigned int V_276 ;
F_17 ( V_152 <= ( V_107 ) V_226 ) ;
V_276 = ( unsigned int ) V_152 ;
V_183 -> V_218 =
F_102 ( & V_218 ,
& V_272 ,
V_276 ,
V_149 ) ;
if ( ! V_183 -> V_218 )
goto V_275;
} else if ( type == V_205 ) {
unsigned int V_255 ;
V_183 -> V_169 = V_169 ;
V_255 = ( T_5 ) F_194 ( V_146 , V_152 ) ;
V_183 -> V_255 = V_255 ;
if ( ( V_146 + V_152 ) & ~ V_174 )
V_255 -- ;
V_169 += V_255 ;
}
V_208 = F_159 ( V_22 , V_88 ,
( V_88 == V_90 ) ? 2 : 1 ,
V_183 ) ;
if ( ! V_208 )
goto V_275;
V_183 -> V_208 = V_208 ;
V_183 -> V_201 = F_185 ;
V_183 -> V_190 = V_190 ;
F_187 ( V_183 , V_208 , V_88 , 0 ) ;
F_119 ( V_185 ) ;
V_190 += V_152 ;
V_273 -= V_152 ;
}
return 0 ;
V_275:
F_180 (img_request, obj_request, next_obj_request)
F_123 ( V_185 , V_183 ) ;
return - V_57 ;
}
static void
F_155 ( struct V_182 * V_183 )
{
struct V_194 * V_185 ;
struct V_21 * V_22 ;
struct V_168 * * V_169 ;
T_5 V_255 ;
F_25 ( L_28 , V_58 , V_183 ) ;
F_17 ( V_183 -> type == V_204 ||
V_183 -> type == V_203 ) ;
F_17 ( F_106 ( V_183 ) ) ;
V_185 = V_183 -> V_185 ;
F_17 ( V_185 ) ;
V_22 = V_185 -> V_22 ;
F_17 ( V_22 ) ;
V_169 = V_183 -> V_277 ;
F_17 ( V_169 != NULL ) ;
V_183 -> V_277 = NULL ;
V_255 = V_183 -> V_278 ;
F_17 ( V_255 ) ;
V_183 -> V_278 = 0 ;
F_170 ( V_169 , V_255 ) ;
if ( ! V_183 -> V_212 )
V_183 -> V_213 = V_183 -> V_152 ;
F_108 ( V_183 ) ;
}
static void
F_195 ( struct V_194 * V_185 )
{
struct V_182 * V_266 ;
struct V_220 * V_208 ;
struct V_206 * V_207 ;
struct V_21 * V_22 ;
struct V_168 * * V_169 ;
enum V_87 V_88 ;
T_5 V_255 ;
int V_279 ;
V_107 V_280 ;
F_17 ( F_121 ( V_185 ) ) ;
V_169 = V_185 -> V_277 ;
F_17 ( V_169 != NULL ) ;
V_185 -> V_277 = NULL ;
V_255 = V_185 -> V_278 ;
F_17 ( V_255 ) ;
V_185 -> V_278 = 0 ;
V_266 = V_185 -> V_183 ;
F_17 ( V_266 != NULL ) ;
F_17 ( F_124 ( V_266 -> type ) ) ;
V_279 = V_185 -> V_212 ;
V_280 = V_185 -> V_152 ;
F_17 ( V_280 == V_185 -> V_213 ) ;
F_120 ( V_185 ) ;
F_17 ( V_266 -> V_185 ) ;
V_22 = V_266 -> V_185 -> V_22 ;
F_17 ( V_22 ) ;
if ( ! V_22 -> V_191 ) {
struct V_206 * V_207 ;
F_170 ( V_169 , V_255 ) ;
V_207 = & V_22 -> V_53 -> V_63 -> V_207 ;
V_279 = F_125 ( V_207 , V_266 ) ;
if ( ! V_279 )
return;
}
if ( V_279 )
goto V_118;
V_279 = - V_57 ;
V_208 = F_165 ( V_266 ) ;
if ( ! V_208 )
goto V_118;
F_166 ( V_266 -> V_208 ) ;
V_266 -> V_208 = V_208 ;
V_266 -> V_277 = V_169 ;
V_266 -> V_278 = V_255 ;
F_196 ( V_208 , 0 , V_236 , L_40 , L_41 ) ;
F_197 ( V_208 , 0 , V_169 , V_280 , 0 ,
false , false ) ;
V_88 = F_145 ( V_266 -> V_185 ) ;
F_187 ( V_266 , V_208 , V_88 , 1 ) ;
V_207 = & V_22 -> V_53 -> V_63 -> V_207 ;
V_279 = F_125 ( V_207 , V_266 ) ;
if ( ! V_279 )
return;
V_118:
V_266 -> V_212 = V_279 ;
V_266 -> V_213 = 0 ;
F_108 ( V_266 ) ;
F_147 ( V_266 ) ;
}
static int F_198 ( struct V_182 * V_183 )
{
struct V_194 * V_185 = NULL ;
struct V_194 * V_264 = NULL ;
struct V_21 * V_22 ;
V_107 V_190 ;
V_107 V_152 ;
struct V_168 * * V_169 = NULL ;
T_5 V_255 ;
int V_212 ;
F_17 ( F_106 ( V_183 ) ) ;
F_17 ( F_124 ( V_183 -> type ) ) ;
V_185 = V_183 -> V_185 ;
F_17 ( V_185 != NULL ) ;
V_22 = V_185 -> V_22 ;
F_17 ( V_22 -> V_265 != NULL ) ;
V_190 = V_183 -> V_190 - V_183 -> V_146 ;
V_152 = ( V_107 ) 1 << V_22 -> V_110 . V_126 ;
if ( V_190 + V_152 > V_22 -> V_191 ) {
F_17 ( V_190 < V_22 -> V_191 ) ;
V_152 = V_22 -> V_191 - V_190 ;
}
V_255 = ( T_5 ) F_194 ( 0 , V_152 ) ;
V_169 = F_199 ( V_255 , V_59 ) ;
if ( F_30 ( V_169 ) ) {
V_212 = F_200 ( V_169 ) ;
V_169 = NULL ;
goto V_118;
}
V_212 = - V_57 ;
V_264 = F_181 ( V_183 ,
V_190 , V_152 ) ;
if ( ! V_264 )
goto V_118;
V_212 = F_193 ( V_264 , V_205 , V_169 ) ;
if ( V_212 )
goto V_118;
V_264 -> V_277 = V_169 ;
V_264 -> V_278 = V_255 ;
V_264 -> V_201 = F_195 ;
V_212 = F_201 ( V_264 ) ;
if ( ! V_212 )
return 0 ;
V_264 -> V_277 = NULL ;
V_264 -> V_278 = 0 ;
V_264 -> V_183 = NULL ;
F_118 ( V_183 ) ;
V_118:
if ( V_169 )
F_170 ( V_169 , V_255 ) ;
if ( V_264 )
F_120 ( V_264 ) ;
V_183 -> V_212 = V_212 ;
V_183 -> V_213 = 0 ;
F_108 ( V_183 ) ;
return V_212 ;
}
static void F_202 ( struct V_182 * V_183 )
{
struct V_182 * V_266 ;
struct V_21 * V_22 ;
int V_212 ;
F_17 ( ! F_106 ( V_183 ) ) ;
V_266 = V_183 -> V_183 ;
V_183 -> V_183 = NULL ;
F_118 ( V_266 ) ;
F_17 ( V_266 ) ;
F_17 ( V_266 -> V_185 ) ;
V_212 = V_183 -> V_212 ;
V_183 -> V_212 = 0 ;
F_25 ( L_42 , V_58 ,
V_183 , V_266 , V_212 ,
V_183 -> V_213 , V_183 -> V_152 ) ;
F_118 ( V_183 ) ;
V_22 = V_266 -> V_185 -> V_22 ;
if ( ! V_22 -> V_191 ) {
struct V_206 * V_207 ;
V_207 = & V_22 -> V_53 -> V_63 -> V_207 ;
V_212 = F_125 ( V_207 , V_266 ) ;
if ( ! V_212 )
return;
}
if ( ! V_212 ) {
F_110 ( V_266 , true ) ;
} else if ( V_212 == - V_34 ) {
F_110 ( V_266 , false ) ;
} else if ( V_212 ) {
V_266 -> V_212 = V_212 ;
goto V_49;
}
V_266 -> V_212 = F_203 ( V_266 ) ;
V_49:
if ( V_266 -> V_212 )
F_147 ( V_266 ) ;
}
static int F_204 ( struct V_182 * V_183 )
{
struct V_182 * V_281 ;
struct V_21 * V_22 ;
struct V_206 * V_207 ;
struct V_168 * * V_169 = NULL ;
T_5 V_255 ;
T_6 V_97 ;
int V_39 ;
V_97 = sizeof ( V_106 ) + sizeof ( V_282 ) + sizeof ( V_282 ) ;
V_255 = ( T_5 ) F_194 ( 0 , V_97 ) ;
V_169 = F_199 ( V_255 , V_59 ) ;
if ( F_30 ( V_169 ) )
return F_200 ( V_169 ) ;
V_39 = - V_57 ;
V_281 = F_167 ( V_183 -> V_237 , 0 , 0 ,
V_205 ) ;
if ( ! V_281 )
goto V_49;
F_116 ( V_183 ) ;
V_281 -> V_183 = V_183 ;
V_281 -> V_169 = V_169 ;
V_281 -> V_255 = V_255 ;
F_17 ( V_183 -> V_185 ) ;
V_22 = V_183 -> V_185 -> V_22 ;
V_281 -> V_208 = F_159 ( V_22 , V_89 , 1 ,
V_281 ) ;
if ( ! V_281 -> V_208 )
goto V_49;
V_281 -> V_201 = F_202 ;
F_189 ( V_281 -> V_208 , 0 , V_232 , 0 ) ;
F_205 ( V_281 -> V_208 , 0 , V_169 , V_97 , 0 ,
false , false ) ;
F_157 ( V_281 ) ;
V_207 = & V_22 -> V_53 -> V_63 -> V_207 ;
V_39 = F_125 ( V_207 , V_281 ) ;
V_49:
if ( V_39 )
F_118 ( V_183 ) ;
return V_39 ;
}
static bool F_206 ( struct V_182 * V_183 )
{
struct V_194 * V_185 ;
struct V_21 * V_22 ;
F_17 ( F_106 ( V_183 ) ) ;
V_185 = V_183 -> V_185 ;
F_17 ( V_185 ) ;
V_22 = V_185 -> V_22 ;
if ( ! F_136 ( V_185 ) &&
! F_138 ( V_185 ) )
return true ;
if ( ! F_144 ( V_185 ) )
return true ;
if ( ! F_114 ( V_183 ) )
return true ;
if ( ! V_183 -> V_146 &&
V_183 -> V_152 == F_84 ( & V_22 -> V_110 ) )
return true ;
if ( F_112 ( V_183 ) &&
F_113 ( V_183 ) )
return true ;
return false ;
}
static int F_203 ( struct V_182 * V_183 )
{
if ( F_206 ( V_183 ) ) {
struct V_21 * V_22 ;
struct V_206 * V_207 ;
V_22 = V_183 -> V_185 -> V_22 ;
V_207 = & V_22 -> V_53 -> V_63 -> V_207 ;
return F_125 ( V_207 , V_183 ) ;
}
if ( F_112 ( V_183 ) )
return F_198 ( V_183 ) ;
return F_204 ( V_183 ) ;
}
static int F_201 ( struct V_194 * V_185 )
{
struct V_182 * V_183 ;
struct V_182 * V_263 ;
int V_39 = 0 ;
F_25 ( L_24 , V_58 , V_185 ) ;
F_119 ( V_185 ) ;
F_180 (img_request, obj_request, next_obj_request) {
V_39 = F_203 ( V_183 ) ;
if ( V_39 )
goto V_283;
}
V_283:
F_120 ( V_185 ) ;
return V_39 ;
}
static void F_207 ( struct V_194 * V_185 )
{
struct V_182 * V_183 ;
struct V_21 * V_22 ;
V_107 V_284 ;
V_107 V_285 ;
int V_279 ;
F_17 ( F_121 ( V_185 ) ) ;
V_183 = V_185 -> V_183 ;
V_285 = V_185 -> V_213 ;
V_279 = V_185 -> V_212 ;
F_120 ( V_185 ) ;
F_17 ( V_183 ) ;
F_17 ( V_183 -> V_185 ) ;
V_22 = V_183 -> V_185 -> V_22 ;
if ( ! V_22 -> V_191 ) {
struct V_206 * V_207 ;
V_207 = & V_22 -> V_53 -> V_63 -> V_207 ;
V_279 = F_125 ( V_207 , V_183 ) ;
if ( ! V_279 )
return;
}
V_183 -> V_212 = V_279 ;
if ( V_183 -> V_212 )
goto V_49;
F_17 ( V_183 -> V_190 < V_153 - V_183 -> V_152 ) ;
V_284 = V_183 -> V_190 + V_183 -> V_152 ;
if ( V_284 > V_22 -> V_191 ) {
V_107 V_213 = 0 ;
if ( V_183 -> V_190 < V_22 -> V_191 )
V_213 = V_22 -> V_191 -
V_183 -> V_190 ;
V_183 -> V_213 = F_208 ( V_285 , V_213 ) ;
} else {
V_183 -> V_213 = V_285 ;
}
V_49:
F_146 ( V_183 ) ;
F_147 ( V_183 ) ;
}
static void F_150 ( struct V_182 * V_183 )
{
struct V_194 * V_185 ;
int V_212 ;
F_17 ( F_106 ( V_183 ) ) ;
F_17 ( V_183 -> V_185 != NULL ) ;
F_17 ( V_183 -> V_212 == ( V_286 ) - V_34 ) ;
F_17 ( F_124 ( V_183 -> type ) ) ;
V_185 = F_181 ( V_183 ,
V_183 -> V_190 ,
V_183 -> V_152 ) ;
V_212 = - V_57 ;
if ( ! V_185 )
goto V_118;
if ( V_183 -> type == V_204 )
V_212 = F_193 ( V_185 , V_204 ,
V_183 -> V_218 ) ;
else
V_212 = F_193 ( V_185 , V_205 ,
V_183 -> V_169 ) ;
if ( V_212 )
goto V_118;
V_185 -> V_201 = F_207 ;
V_212 = F_201 ( V_185 ) ;
if ( V_212 )
goto V_118;
return;
V_118:
if ( V_185 )
F_120 ( V_185 ) ;
V_183 -> V_212 = V_212 ;
V_183 -> V_213 = 0 ;
F_108 ( V_183 ) ;
}
static void F_209 ( void * V_38 , V_107 V_287 , V_107 V_288 ,
V_107 V_289 , void * V_290 , T_6 V_291 )
{
struct V_21 * V_22 = V_38 ;
struct V_206 * V_207 = & V_22 -> V_53 -> V_63 -> V_207 ;
int V_39 ;
F_25 ( L_43 , V_58 , V_22 ,
V_288 , V_287 ) ;
V_39 = F_210 ( V_22 ) ;
if ( V_39 )
F_103 ( V_22 , L_44 , V_39 ) ;
V_39 = F_211 ( V_207 , & V_22 -> V_292 ,
& V_22 -> V_293 , V_287 , V_288 ,
NULL , 0 ) ;
if ( V_39 )
F_103 ( V_22 , L_45 , V_39 ) ;
}
static void F_212 ( void * V_38 , V_107 V_288 , int V_294 )
{
struct V_21 * V_22 = V_38 ;
int V_39 ;
F_103 ( V_22 , L_46 , V_294 ) ;
F_213 ( V_22 ) ;
V_39 = F_214 ( V_22 ) ;
if ( V_39 ) {
F_103 ( V_22 , L_47 , V_39 ) ;
return;
}
V_39 = F_210 ( V_22 ) ;
if ( V_39 )
F_103 ( V_22 , L_48 , V_39 ) ;
}
static int F_214 ( struct V_21 * V_22 )
{
struct V_206 * V_207 = & V_22 -> V_53 -> V_63 -> V_207 ;
struct V_295 * V_296 ;
F_17 ( ! V_22 -> V_297 ) ;
V_296 = F_215 ( V_207 , & V_22 -> V_292 ,
& V_22 -> V_293 , F_209 ,
F_212 , V_22 ) ;
if ( F_30 ( V_296 ) )
return F_200 ( V_296 ) ;
V_22 -> V_297 = V_296 ;
return 0 ;
}
static void F_213 ( struct V_21 * V_22 )
{
struct V_206 * V_207 = & V_22 -> V_53 -> V_63 -> V_207 ;
int V_39 ;
if ( ! V_22 -> V_297 )
return;
V_39 = F_216 ( V_207 , V_22 -> V_297 ) ;
if ( V_39 )
F_103 ( V_22 , L_49 , V_39 ) ;
V_22 -> V_297 = NULL ;
}
static void F_217 ( struct V_21 * V_22 )
{
F_213 ( V_22 ) ;
F_25 ( L_50 , V_58 ) ;
F_218 ( & V_22 -> V_53 -> V_63 -> V_207 ) ;
}
static int F_219 ( struct V_21 * V_22 ,
const char * V_237 ,
const char * V_298 ,
const char * V_299 ,
const void * V_300 ,
T_6 V_301 ,
void * V_302 ,
T_6 V_303 )
{
struct V_206 * V_207 = & V_22 -> V_53 -> V_63 -> V_207 ;
struct V_182 * V_183 ;
struct V_168 * * V_169 ;
T_5 V_255 ;
int V_39 ;
V_255 = ( T_5 ) F_194 ( 0 , V_303 ) ;
V_169 = F_199 ( V_255 , V_59 ) ;
if ( F_30 ( V_169 ) )
return F_200 ( V_169 ) ;
V_39 = - V_57 ;
V_183 = F_167 ( V_237 , 0 , V_303 ,
V_205 ) ;
if ( ! V_183 )
goto V_49;
V_183 -> V_169 = V_169 ;
V_183 -> V_255 = V_255 ;
V_183 -> V_208 = F_159 ( V_22 , V_89 , 1 ,
V_183 ) ;
if ( ! V_183 -> V_208 )
goto V_49;
F_196 ( V_183 -> V_208 , 0 , V_236 ,
V_298 , V_299 ) ;
if ( V_301 ) {
struct V_304 * V_305 ;
V_305 = F_26 ( sizeof ( * V_305 ) , V_306 ) ;
if ( ! V_305 )
goto V_49;
F_220 ( V_305 ) ;
F_221 ( V_305 , V_300 , V_301 ) ;
F_222 ( V_183 -> V_208 , 0 ,
V_305 ) ;
}
F_223 ( V_183 -> V_208 , 0 ,
V_183 -> V_169 , V_303 ,
0 , false , false ) ;
F_157 ( V_183 ) ;
V_39 = F_125 ( V_207 , V_183 ) ;
if ( V_39 )
goto V_49;
V_39 = F_132 ( V_183 ) ;
if ( V_39 )
goto V_49;
V_39 = V_183 -> V_212 ;
if ( V_39 < 0 )
goto V_49;
F_17 ( V_183 -> V_213 < ( V_107 ) V_3 ) ;
V_39 = ( int ) V_183 -> V_213 ;
F_224 ( V_169 , V_302 , 0 , V_183 -> V_213 ) ;
V_49:
if ( V_183 )
F_118 ( V_183 ) ;
else
F_170 ( V_169 , V_255 ) ;
return V_39 ;
}
static void F_225 ( struct V_307 * V_308 )
{
struct V_309 * V_260 = F_226 ( V_308 ) ;
struct V_21 * V_22 = V_260 -> V_310 -> V_311 ;
struct V_194 * V_185 ;
struct V_105 * V_113 = NULL ;
V_107 V_146 = ( V_107 ) F_227 ( V_260 ) << V_103 ;
V_107 V_152 = F_228 ( V_260 ) ;
enum V_87 V_88 ;
V_107 V_312 ;
int V_212 ;
if ( V_260 -> V_313 != V_314 ) {
F_25 ( L_51 , V_58 ,
( int ) V_260 -> V_313 ) ;
V_212 = - V_132 ;
goto V_294;
}
if ( V_260 -> V_315 & V_316 )
V_88 = V_91 ;
else if ( V_260 -> V_315 & V_317 )
V_88 = V_90 ;
else
V_88 = V_89 ;
if ( ! V_152 ) {
F_25 ( L_52 , V_58 ) ;
V_212 = 0 ;
goto V_318;
}
if ( V_88 != V_89 ) {
if ( V_22 -> V_27 . V_28 ) {
V_212 = - V_29 ;
goto V_318;
}
F_17 ( V_22 -> V_45 -> V_46 == V_47 ) ;
}
if ( ! F_13 ( V_319 , & V_22 -> V_32 ) ) {
F_25 ( L_53 ) ;
F_17 ( V_22 -> V_45 -> V_46 != V_47 ) ;
V_212 = - V_320 ;
goto V_318;
}
if ( V_146 && V_152 > V_153 - V_146 + 1 ) {
F_103 ( V_22 , L_54 , V_146 ,
V_152 ) ;
V_212 = - V_4 ;
goto V_318;
}
F_229 ( V_260 ) ;
F_176 ( & V_22 -> V_258 ) ;
V_312 = V_22 -> V_27 . V_97 ;
if ( V_88 != V_89 ) {
V_113 = V_22 -> V_110 . V_113 ;
F_230 ( V_113 ) ;
}
F_177 ( & V_22 -> V_258 ) ;
if ( V_146 + V_152 > V_312 ) {
F_103 ( V_22 , L_55 , V_146 ,
V_152 , V_312 ) ;
V_212 = - V_132 ;
goto V_318;
}
V_185 = F_178 ( V_22 , V_146 , V_152 , V_88 ,
V_113 ) ;
if ( ! V_185 ) {
V_212 = - V_57 ;
goto V_318;
}
V_185 -> V_260 = V_260 ;
V_113 = NULL ;
if ( V_88 == V_91 )
V_212 = F_193 ( V_185 , V_203 ,
NULL ) ;
else
V_212 = F_193 ( V_185 , V_204 ,
V_260 -> V_154 ) ;
if ( V_212 )
goto V_321;
V_212 = F_201 ( V_185 ) ;
if ( V_212 )
goto V_321;
return;
V_321:
F_120 ( V_185 ) ;
V_318:
if ( V_212 )
F_103 ( V_22 , L_56 ,
F_48 ( V_88 ) , V_152 , V_146 , V_212 ) ;
F_64 ( V_113 ) ;
V_294:
F_231 ( V_260 , V_212 ) ;
}
static int F_232 ( struct V_322 * V_323 ,
const struct V_324 * V_325 )
{
struct V_309 * V_260 = V_325 -> V_260 ;
struct V_307 * V_308 = F_233 ( V_260 ) ;
F_234 ( V_326 , V_308 ) ;
return V_327 ;
}
static void F_235 ( struct V_21 * V_22 )
{
struct V_35 * V_36 = V_22 -> V_36 ;
if ( ! V_36 )
return;
V_22 -> V_36 = NULL ;
if ( V_36 -> V_32 & V_328 ) {
F_236 ( V_36 ) ;
if ( V_36 -> V_329 )
F_237 ( V_36 -> V_329 ) ;
F_238 ( & V_22 -> V_330 ) ;
}
F_239 ( V_36 ) ;
}
static int F_240 ( struct V_21 * V_22 ,
const char * V_237 ,
V_107 V_146 , V_107 V_152 , void * V_163 )
{
struct V_206 * V_207 = & V_22 -> V_53 -> V_63 -> V_207 ;
struct V_182 * V_183 ;
struct V_168 * * V_169 = NULL ;
T_5 V_255 ;
T_6 V_97 ;
int V_39 ;
V_255 = ( T_5 ) F_194 ( V_146 , V_152 ) ;
V_169 = F_199 ( V_255 , V_59 ) ;
if ( F_30 ( V_169 ) )
return F_200 ( V_169 ) ;
V_39 = - V_57 ;
V_183 = F_167 ( V_237 , V_146 , V_152 ,
V_205 ) ;
if ( ! V_183 )
goto V_49;
V_183 -> V_169 = V_169 ;
V_183 -> V_255 = V_255 ;
V_183 -> V_208 = F_159 ( V_22 , V_89 , 1 ,
V_183 ) ;
if ( ! V_183 -> V_208 )
goto V_49;
F_190 ( V_183 -> V_208 , 0 , V_228 ,
V_146 , V_152 , 0 , 0 ) ;
F_192 ( V_183 -> V_208 , 0 ,
V_183 -> V_169 ,
V_183 -> V_152 ,
V_183 -> V_146 & ~ V_174 ,
false , false ) ;
F_157 ( V_183 ) ;
V_39 = F_125 ( V_207 , V_183 ) ;
if ( V_39 )
goto V_49;
V_39 = F_132 ( V_183 ) ;
if ( V_39 )
goto V_49;
V_39 = V_183 -> V_212 ;
if ( V_39 < 0 )
goto V_49;
F_17 ( V_183 -> V_213 <= ( V_107 ) V_104 ) ;
V_97 = ( T_6 ) V_183 -> V_213 ;
F_224 ( V_169 , V_163 , 0 , V_97 ) ;
F_17 ( V_97 <= ( T_6 ) V_3 ) ;
V_39 = ( int ) V_97 ;
V_49:
if ( V_183 )
F_118 ( V_183 ) ;
else
F_170 ( V_169 , V_255 ) ;
return V_39 ;
}
static int F_241 ( struct V_21 * V_22 )
{
struct V_95 * V_96 = NULL ;
T_5 V_98 = 0 ;
V_107 V_331 = 0 ;
T_5 V_332 ;
int V_39 ;
do {
T_6 V_97 ;
F_36 ( V_96 ) ;
V_97 = sizeof ( * V_96 ) ;
V_97 += V_98 * sizeof ( struct V_121 ) ;
V_97 += V_331 ;
V_96 = F_26 ( V_97 , V_59 ) ;
if ( ! V_96 )
return - V_57 ;
V_39 = F_240 ( V_22 , V_22 -> V_292 . V_144 ,
0 , V_97 , V_96 ) ;
if ( V_39 < 0 )
goto V_49;
if ( ( T_6 ) V_39 < V_97 ) {
V_39 = - V_320 ;
F_103 ( V_22 , L_57 ,
V_97 , V_39 ) ;
goto V_49;
}
if ( ! F_58 ( V_96 ) ) {
V_39 = - V_320 ;
F_103 ( V_22 , L_58 ) ;
goto V_49;
}
V_331 = F_60 ( V_96 -> V_108 ) ;
V_332 = V_98 ;
V_98 = F_59 ( V_96 -> V_98 ) ;
} while ( V_98 != V_332 );
V_39 = F_61 ( V_22 , V_96 ) ;
V_49:
F_36 ( V_96 ) ;
return V_39 ;
}
static void F_242 ( struct V_21 * V_22 )
{
V_107 V_46 ;
if ( ! F_13 ( V_319 , & V_22 -> V_32 ) )
return;
V_46 = V_22 -> V_45 -> V_46 ;
if ( V_46 == V_47 )
return;
if ( F_68 ( V_22 , V_46 ) == V_140 )
F_141 ( V_319 , & V_22 -> V_32 ) ;
}
static void F_243 ( struct V_21 * V_22 )
{
T_9 V_97 ;
if ( F_13 ( V_319 , & V_22 -> V_32 ) &&
! F_13 ( V_31 , & V_22 -> V_32 ) ) {
V_97 = ( T_9 ) V_22 -> V_27 . V_97 / V_333 ;
F_25 ( L_59 , ( unsigned long long ) V_97 ) ;
F_244 ( V_22 -> V_36 , V_97 ) ;
F_245 ( V_22 -> V_36 ) ;
}
}
static int F_210 ( struct V_21 * V_22 )
{
V_107 V_312 ;
int V_39 ;
F_246 ( & V_22 -> V_258 ) ;
V_312 = V_22 -> V_27 . V_97 ;
V_39 = F_247 ( V_22 ) ;
if ( V_39 )
goto V_49;
if ( V_22 -> V_265 ) {
V_39 = F_248 ( V_22 ) ;
if ( V_39 )
goto V_49;
}
if ( V_22 -> V_45 -> V_46 == V_47 ) {
V_22 -> V_27 . V_97 = V_22 -> V_110 . V_125 ;
} else {
F_242 ( V_22 ) ;
}
V_49:
F_249 ( & V_22 -> V_258 ) ;
if ( ! V_39 && V_312 != V_22 -> V_27 . V_97 )
F_243 ( V_22 ) ;
return V_39 ;
}
static int F_250 ( void * V_290 , struct V_309 * V_260 ,
unsigned int V_334 , unsigned int V_335 ,
unsigned int V_336 )
{
struct V_307 * V_308 = F_233 ( V_260 ) ;
F_251 ( V_308 , F_225 ) ;
return 0 ;
}
static int F_252 ( struct V_21 * V_22 )
{
struct V_35 * V_36 ;
struct V_337 * V_310 ;
V_107 V_151 ;
int V_294 ;
V_36 = F_253 ( V_13 ?
( 1 << V_6 ) :
V_338 ) ;
if ( ! V_36 )
return - V_57 ;
snprintf ( V_36 -> V_339 , sizeof( V_36 -> V_339 ) , V_340 L_60 ,
V_22 -> V_5 ) ;
V_36 -> V_341 = V_22 -> V_341 ;
V_36 -> V_342 = V_22 -> V_7 ;
if ( V_13 )
V_36 -> V_32 |= V_343 ;
V_36 -> V_344 = & V_345 ;
V_36 -> V_24 = V_22 ;
memset ( & V_22 -> V_330 , 0 , sizeof( V_22 -> V_330 ) ) ;
V_22 -> V_330 . V_346 = & V_347 ;
V_22 -> V_330 . V_84 = V_22 -> V_348 -> V_84 ;
V_22 -> V_330 . V_336 = V_349 ;
V_22 -> V_330 . V_32 = V_350 | V_351 ;
V_22 -> V_330 . V_352 = 1 ;
V_22 -> V_330 . V_353 = sizeof( struct V_307 ) ;
V_294 = F_254 ( & V_22 -> V_330 ) ;
if ( V_294 )
goto V_354;
V_310 = F_255 ( & V_22 -> V_330 ) ;
if ( F_30 ( V_310 ) ) {
V_294 = F_200 ( V_310 ) ;
goto V_355;
}
F_256 ( V_356 , V_310 ) ;
V_151 = F_84 ( & V_22 -> V_110 ) ;
F_257 ( V_310 , V_151 / V_333 ) ;
V_310 -> V_357 . V_358 = F_258 ( V_310 ) ;
F_259 ( V_310 , V_151 / V_333 ) ;
F_260 ( V_310 , V_151 ) ;
F_261 ( V_310 , V_151 ) ;
F_262 ( V_310 , V_151 ) ;
F_256 ( V_359 , V_310 ) ;
V_310 -> V_357 . V_360 = V_151 ;
V_310 -> V_357 . V_361 = V_151 ;
F_263 ( V_310 , V_151 / V_333 ) ;
V_310 -> V_357 . V_362 = 1 ;
if ( ! F_264 ( V_22 -> V_53 -> V_63 , V_363 ) )
V_310 -> V_364 . V_365 |= V_366 ;
V_36 -> V_329 = V_310 ;
V_310 -> V_311 = V_22 ;
V_22 -> V_36 = V_36 ;
return 0 ;
V_355:
F_238 ( & V_22 -> V_330 ) ;
V_354:
F_239 ( V_36 ) ;
return V_294 ;
}
static struct V_21 * F_265 ( struct V_17 * V_18 )
{
return F_53 ( V_18 , struct V_21 , V_18 ) ;
}
static T_10 F_266 ( struct V_17 * V_18 ,
struct V_367 * V_11 , char * V_163 )
{
struct V_21 * V_22 = F_265 ( V_18 ) ;
return sprintf ( V_163 , L_61 ,
( unsigned long long ) V_22 -> V_27 . V_97 ) ;
}
static T_10 F_267 ( struct V_17 * V_18 ,
struct V_367 * V_11 , char * V_163 )
{
struct V_21 * V_22 = F_265 ( V_18 ) ;
return sprintf ( V_163 , L_62 ,
( unsigned long long ) V_22 -> V_27 . V_131 ) ;
}
static T_10 F_268 ( struct V_17 * V_18 ,
struct V_367 * V_11 , char * V_163 )
{
struct V_21 * V_22 = F_265 ( V_18 ) ;
if ( V_22 -> V_341 )
return sprintf ( V_163 , L_63 , V_22 -> V_341 ) ;
return sprintf ( V_163 , L_64 ) ;
}
static T_10 F_269 ( struct V_17 * V_18 ,
struct V_367 * V_11 , char * V_163 )
{
struct V_21 * V_22 = F_265 ( V_18 ) ;
return sprintf ( V_163 , L_63 , V_22 -> V_7 ) ;
}
static T_10 F_270 ( struct V_17 * V_18 ,
struct V_367 * V_11 , char * V_163 )
{
struct V_21 * V_22 = F_265 ( V_18 ) ;
return sprintf ( V_163 , L_65 ,
F_271 ( V_22 -> V_53 -> V_63 ) ) ;
}
static T_10 F_272 ( struct V_17 * V_18 ,
struct V_367 * V_11 , char * V_163 )
{
struct V_21 * V_22 = F_265 ( V_18 ) ;
return sprintf ( V_163 , L_66 , V_22 -> V_45 -> V_368 ) ;
}
static T_10 F_273 ( struct V_17 * V_18 ,
struct V_367 * V_11 , char * V_163 )
{
struct V_21 * V_22 = F_265 ( V_18 ) ;
return sprintf ( V_163 , L_61 ,
( unsigned long long ) V_22 -> V_45 -> V_369 ) ;
}
static T_10 F_274 ( struct V_17 * V_18 ,
struct V_367 * V_11 , char * V_163 )
{
struct V_21 * V_22 = F_265 ( V_18 ) ;
if ( V_22 -> V_45 -> V_370 )
return sprintf ( V_163 , L_66 , V_22 -> V_45 -> V_370 ) ;
return sprintf ( V_163 , L_67 ) ;
}
static T_10 F_275 ( struct V_17 * V_18 ,
struct V_367 * V_11 , char * V_163 )
{
struct V_21 * V_22 = F_265 ( V_18 ) ;
return sprintf ( V_163 , L_66 , V_22 -> V_45 -> V_371 ) ;
}
static T_10 F_276 ( struct V_17 * V_18 ,
struct V_367 * V_11 ,
char * V_163 )
{
struct V_21 * V_22 = F_265 ( V_18 ) ;
return sprintf ( V_163 , L_66 , V_22 -> V_45 -> V_134 ) ;
}
static T_10 F_277 ( struct V_17 * V_18 ,
struct V_367 * V_11 ,
char * V_163 )
{
struct V_21 * V_22 = F_265 ( V_18 ) ;
T_10 V_372 = 0 ;
if ( ! V_22 -> V_265 )
return sprintf ( V_163 , L_68 ) ;
for ( ; V_22 -> V_265 ; V_22 = V_22 -> V_265 ) {
struct V_373 * V_45 = V_22 -> V_256 ;
V_372 += sprintf ( & V_163 [ V_372 ] , L_31
L_69
L_70
L_71
L_72 ,
! V_372 ? L_73 : L_74 ,
V_45 -> V_369 , V_45 -> V_368 ,
V_45 -> V_371 , V_45 -> V_370 ? : L_75 ,
V_45 -> V_46 , V_45 -> V_134 ,
V_22 -> V_191 ) ;
}
return V_372 ;
}
static T_10 F_278 ( struct V_17 * V_18 ,
struct V_367 * V_11 ,
const char * V_163 ,
T_6 V_97 )
{
struct V_21 * V_22 = F_265 ( V_18 ) ;
int V_39 ;
V_39 = F_210 ( V_22 ) ;
if ( V_39 )
return V_39 ;
return V_97 ;
}
static struct V_373 * F_279 ( struct V_373 * V_45 )
{
F_40 ( & V_45 -> V_61 ) ;
return V_45 ;
}
static void F_173 ( struct V_373 * V_45 )
{
if ( V_45 )
F_56 ( & V_45 -> V_61 , V_374 ) ;
}
static struct V_373 * F_280 ( void )
{
struct V_373 * V_45 ;
V_45 = F_281 ( sizeof ( * V_45 ) , V_59 ) ;
if ( ! V_45 )
return NULL ;
V_45 -> V_369 = V_375 ;
V_45 -> V_46 = V_47 ;
F_27 ( & V_45 -> V_61 ) ;
return V_45 ;
}
static void V_374 ( struct V_61 * V_61 )
{
struct V_373 * V_45 = F_53 ( V_61 , struct V_373 , V_61 ) ;
F_36 ( V_45 -> V_368 ) ;
F_36 ( V_45 -> V_371 ) ;
F_36 ( V_45 -> V_370 ) ;
F_36 ( V_45 -> V_134 ) ;
F_36 ( V_45 ) ;
}
static void F_282 ( struct V_17 * V_18 )
{
struct V_21 * V_22 = F_265 ( V_18 ) ;
bool V_376 = ! ! V_22 -> V_348 ;
F_283 ( & V_22 -> V_292 ) ;
F_55 ( V_22 -> V_53 ) ;
F_173 ( V_22 -> V_45 ) ;
F_36 ( V_22 -> V_348 ) ;
F_36 ( V_22 ) ;
if ( V_376 )
F_284 ( V_377 ) ;
}
static struct V_21 * F_285 ( struct V_53 * V_56 ,
struct V_373 * V_45 ,
struct V_73 * V_348 )
{
struct V_21 * V_22 ;
V_22 = F_281 ( sizeof ( * V_22 ) , V_59 ) ;
if ( ! V_22 )
return NULL ;
F_179 ( & V_22 -> V_30 ) ;
V_22 -> V_32 = 0 ;
F_286 ( & V_22 -> V_257 , 0 ) ;
F_28 ( & V_22 -> V_62 ) ;
F_287 ( & V_22 -> V_258 ) ;
F_288 ( & V_22 -> V_292 ) ;
F_289 ( & V_22 -> V_293 ) ;
V_22 -> V_18 . V_378 = & V_379 ;
V_22 -> V_18 . type = & V_380 ;
V_22 -> V_18 . V_265 = & V_381 ;
F_290 ( & V_22 -> V_18 ) ;
V_22 -> V_53 = V_56 ;
V_22 -> V_45 = V_45 ;
V_22 -> V_348 = V_348 ;
V_22 -> V_251 . V_382 = F_291 ( 1 << V_383 ) ;
V_22 -> V_251 . V_384 = F_291 ( 1 ) ;
V_22 -> V_251 . V_385 = F_291 ( 1 << V_383 ) ;
V_22 -> V_251 . V_386 = F_291 ( ( T_5 ) V_45 -> V_369 ) ;
if ( V_22 -> V_348 )
F_292 ( V_377 ) ;
return V_22 ;
}
static void F_293 ( struct V_21 * V_22 )
{
if ( V_22 )
F_18 ( & V_22 -> V_18 ) ;
}
static int F_73 ( struct V_21 * V_22 , V_107 V_46 ,
T_11 * V_102 , V_107 * V_142 )
{
V_106 V_387 = F_294 ( V_46 ) ;
int V_39 ;
struct {
T_11 V_102 ;
V_106 V_97 ;
} V_388 ( ( V_389 ) ) V_390 = { 0 } ;
V_39 = F_219 ( V_22 , V_22 -> V_292 . V_144 ,
L_40 , L_76 ,
& V_387 , sizeof ( V_387 ) ,
& V_390 , sizeof ( V_390 ) ) ;
F_25 ( L_77 , V_58 , V_39 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 < sizeof ( V_390 ) )
return - V_391 ;
if ( V_102 ) {
* V_102 = V_390 . V_102 ;
F_25 ( L_78 , ( unsigned int ) * V_102 ) ;
}
* V_142 = F_60 ( V_390 . V_97 ) ;
F_25 ( L_79 ,
( unsigned long long ) V_46 ,
( unsigned long long ) * V_142 ) ;
return 0 ;
}
static int F_295 ( struct V_21 * V_22 )
{
return F_73 ( V_22 , V_47 ,
& V_22 -> V_110 . V_126 ,
& V_22 -> V_110 . V_125 ) ;
}
static int F_296 ( struct V_21 * V_22 )
{
void * V_392 ;
int V_39 ;
void * V_393 ;
V_392 = F_281 ( V_394 , V_59 ) ;
if ( ! V_392 )
return - V_57 ;
V_39 = F_219 ( V_22 , V_22 -> V_292 . V_144 ,
L_40 , L_80 , NULL , 0 ,
V_392 , V_394 ) ;
F_25 ( L_77 , V_58 , V_39 ) ;
if ( V_39 < 0 )
goto V_49;
V_393 = V_392 ;
V_22 -> V_110 . V_112 = F_297 ( & V_393 ,
V_393 + V_39 , NULL , V_149 ) ;
V_39 = 0 ;
if ( F_30 ( V_22 -> V_110 . V_112 ) ) {
V_39 = F_200 ( V_22 -> V_110 . V_112 ) ;
V_22 -> V_110 . V_112 = NULL ;
} else {
F_25 ( L_81 , V_22 -> V_110 . V_112 ) ;
}
V_49:
F_36 ( V_392 ) ;
return V_39 ;
}
static int F_75 ( struct V_21 * V_22 , V_107 V_46 ,
V_107 * V_143 )
{
V_106 V_387 = F_294 ( V_46 ) ;
struct {
V_106 V_131 ;
V_106 V_395 ;
} V_388 ( ( V_389 ) ) V_396 = { 0 } ;
V_107 V_397 ;
int V_39 ;
V_39 = F_219 ( V_22 , V_22 -> V_292 . V_144 ,
L_40 , L_82 ,
& V_387 , sizeof ( V_387 ) ,
& V_396 , sizeof ( V_396 ) ) ;
F_25 ( L_77 , V_58 , V_39 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 < sizeof ( V_396 ) )
return - V_391 ;
V_397 = F_60 ( V_396 . V_395 ) & ~ V_398 ;
if ( V_397 ) {
F_103 ( V_22 , L_83 ,
V_397 ) ;
return - V_320 ;
}
* V_143 = F_60 ( V_396 . V_131 ) ;
F_25 ( L_84 ,
( unsigned long long ) V_46 ,
( unsigned long long ) * V_143 ,
( unsigned long long ) F_60 ( V_396 . V_395 ) ) ;
return 0 ;
}
static int F_298 ( struct V_21 * V_22 )
{
return F_75 ( V_22 , V_47 ,
& V_22 -> V_110 . V_131 ) ;
}
static int F_248 ( struct V_21 * V_22 )
{
struct V_373 * V_256 ;
T_6 V_97 ;
void * V_392 = NULL ;
V_106 V_387 ;
void * V_393 ;
void * V_170 ;
V_107 V_369 ;
char * V_371 ;
V_107 V_46 ;
V_107 V_399 ;
int V_39 ;
V_256 = F_280 () ;
if ( ! V_256 )
return - V_57 ;
V_97 = sizeof ( V_106 ) +
sizeof ( V_282 ) + V_400 +
sizeof ( V_106 ) +
sizeof ( V_106 ) ;
V_392 = F_26 ( V_97 , V_59 ) ;
if ( ! V_392 ) {
V_39 = - V_57 ;
goto V_118;
}
V_387 = F_294 ( V_22 -> V_45 -> V_46 ) ;
V_39 = F_219 ( V_22 , V_22 -> V_292 . V_144 ,
L_40 , L_85 ,
& V_387 , sizeof ( V_387 ) ,
V_392 , V_97 ) ;
F_25 ( L_77 , V_58 , V_39 ) ;
if ( V_39 < 0 )
goto V_118;
V_393 = V_392 ;
V_170 = V_392 + V_39 ;
V_39 = - V_391 ;
F_299 ( & V_393 , V_170 , V_369 , V_118 ) ;
if ( V_369 == V_375 ) {
if ( V_22 -> V_191 ) {
V_22 -> V_191 = 0 ;
F_174 ( V_22 ) ;
F_300 ( L_86 ,
V_22 -> V_36 -> V_339 ) ;
}
goto V_49;
}
V_39 = - V_132 ;
if ( V_369 > ( V_107 ) V_401 ) {
F_103 ( NULL , L_87 ,
( unsigned long long ) V_369 , V_401 ) ;
goto V_118;
}
V_371 = F_297 ( & V_393 , V_170 , NULL , V_59 ) ;
if ( F_30 ( V_371 ) ) {
V_39 = F_200 ( V_371 ) ;
goto V_118;
}
F_299 ( & V_393 , V_170 , V_46 , V_118 ) ;
F_299 ( & V_393 , V_170 , V_399 , V_118 ) ;
if ( ! V_22 -> V_256 ) {
V_256 -> V_369 = V_369 ;
V_256 -> V_371 = V_371 ;
V_256 -> V_46 = V_46 ;
V_22 -> V_256 = V_256 ;
V_256 = NULL ;
} else {
F_36 ( V_371 ) ;
}
if ( ! V_399 ) {
if ( V_256 ) {
if ( V_22 -> V_191 )
F_103 ( V_22 ,
L_88 ) ;
} else {
F_103 ( V_22 , L_89 ) ;
}
}
V_22 -> V_191 = V_399 ;
V_49:
V_39 = 0 ;
V_118:
F_36 ( V_392 ) ;
F_173 ( V_256 ) ;
return V_39 ;
}
static int F_301 ( struct V_21 * V_22 )
{
struct {
V_106 V_129 ;
V_106 V_130 ;
} V_388 ( ( V_389 ) ) V_402 = { 0 } ;
T_6 V_97 = sizeof ( V_402 ) ;
void * V_393 ;
V_107 V_403 ;
V_107 V_129 ;
V_107 V_130 ;
int V_39 ;
V_39 = F_219 ( V_22 , V_22 -> V_292 . V_144 ,
L_40 , L_90 , NULL , 0 ,
( char * ) & V_402 , V_97 ) ;
F_25 ( L_77 , V_58 , V_39 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 < V_97 )
return - V_391 ;
V_39 = - V_4 ;
V_403 = ( V_107 ) 1 << V_22 -> V_110 . V_126 ;
V_393 = & V_402 ;
V_129 = F_302 ( & V_393 ) ;
if ( V_129 != V_403 ) {
F_103 ( V_22 , L_91
L_92 ,
V_129 , V_403 ) ;
return - V_4 ;
}
V_130 = F_302 ( & V_393 ) ;
if ( V_130 != 1 ) {
F_103 ( V_22 , L_93
L_94 , V_130 ) ;
return - V_4 ;
}
V_22 -> V_110 . V_129 = V_129 ;
V_22 -> V_110 . V_130 = V_130 ;
return 0 ;
}
static char * F_303 ( struct V_21 * V_22 )
{
T_6 V_404 ;
char * V_371 ;
void * V_393 ;
void * V_170 ;
T_6 V_97 ;
void * V_392 = NULL ;
T_6 V_117 = 0 ;
char * V_370 = NULL ;
int V_39 ;
F_17 ( ! V_22 -> V_45 -> V_370 ) ;
V_117 = strlen ( V_22 -> V_45 -> V_371 ) ;
V_404 = sizeof ( V_282 ) + V_117 ;
V_371 = F_26 ( V_404 , V_59 ) ;
if ( ! V_371 )
return NULL ;
V_393 = V_371 ;
V_170 = V_371 + V_404 ;
F_304 ( & V_393 , V_170 , V_22 -> V_45 -> V_371 , ( T_5 ) V_117 ) ;
V_97 = sizeof ( V_282 ) + V_405 ;
V_392 = F_26 ( V_97 , V_59 ) ;
if ( ! V_392 )
goto V_49;
V_39 = F_219 ( V_22 , V_406 ,
L_40 , L_95 ,
V_371 , V_404 ,
V_392 , V_97 ) ;
if ( V_39 < 0 )
goto V_49;
V_393 = V_392 ;
V_170 = V_392 + V_39 ;
V_370 = F_297 ( & V_393 , V_170 , & V_117 , V_59 ) ;
if ( F_30 ( V_370 ) )
V_370 = NULL ;
else
F_25 ( L_96 , V_58 , V_370 , V_117 ) ;
V_49:
F_36 ( V_392 ) ;
F_36 ( V_371 ) ;
return V_370 ;
}
static V_107 F_305 ( struct V_21 * V_22 , const char * V_144 )
{
struct V_105 * V_113 = V_22 -> V_110 . V_113 ;
const char * V_134 ;
T_5 V_133 = 0 ;
V_134 = V_22 -> V_110 . V_114 ;
while ( V_133 < V_113 -> V_135 ) {
if ( ! strcmp ( V_144 , V_134 ) )
return V_113 -> V_122 [ V_133 ] ;
V_134 += strlen ( V_134 ) + 1 ;
V_133 ++ ;
}
return V_47 ;
}
static V_107 F_306 ( struct V_21 * V_22 , const char * V_144 )
{
struct V_105 * V_113 = V_22 -> V_110 . V_113 ;
T_5 V_133 ;
bool V_69 = false ;
V_107 V_46 ;
for ( V_133 = 0 ; ! V_69 && V_133 < V_113 -> V_135 ; V_133 ++ ) {
const char * V_134 ;
V_46 = V_113 -> V_122 [ V_133 ] ;
V_134 = F_71 ( V_22 , V_46 ) ;
if ( F_30 ( V_134 ) ) {
if ( F_200 ( V_134 ) == - V_34 )
continue;
else
break;
}
V_69 = ! strcmp ( V_144 , V_134 ) ;
F_36 ( V_134 ) ;
}
return V_69 ? V_46 : V_47 ;
}
static V_107 F_307 ( struct V_21 * V_22 , const char * V_144 )
{
if ( V_22 -> V_94 == 1 )
return F_305 ( V_22 , V_144 ) ;
return F_306 ( V_22 , V_144 ) ;
}
static int F_308 ( struct V_21 * V_22 )
{
struct V_373 * V_45 = V_22 -> V_45 ;
F_17 ( V_45 -> V_369 != V_375 && V_45 -> V_368 ) ;
F_17 ( V_45 -> V_371 && V_45 -> V_370 ) ;
F_17 ( V_45 -> V_134 ) ;
if ( strcmp ( V_45 -> V_134 , V_141 ) ) {
V_107 V_46 ;
V_46 = F_307 ( V_22 , V_45 -> V_134 ) ;
if ( V_46 == V_47 )
return - V_34 ;
V_45 -> V_46 = V_46 ;
} else {
V_45 -> V_46 = V_47 ;
}
return 0 ;
}
static int F_309 ( struct V_21 * V_22 )
{
struct V_206 * V_207 = & V_22 -> V_53 -> V_63 -> V_207 ;
struct V_373 * V_45 = V_22 -> V_45 ;
const char * V_368 ;
const char * V_370 ;
const char * V_134 ;
int V_39 ;
F_17 ( V_45 -> V_369 != V_375 ) ;
F_17 ( V_45 -> V_371 ) ;
F_17 ( V_45 -> V_46 != V_47 ) ;
V_368 = F_310 ( V_207 -> V_407 , V_45 -> V_369 ) ;
if ( ! V_368 ) {
F_103 ( V_22 , L_97 , V_45 -> V_369 ) ;
return - V_132 ;
}
V_368 = F_66 ( V_368 , V_59 ) ;
if ( ! V_368 )
return - V_57 ;
V_370 = F_303 ( V_22 ) ;
if ( ! V_370 )
F_103 ( V_22 , L_98 ) ;
V_134 = F_70 ( V_22 , V_45 -> V_46 ) ;
if ( F_30 ( V_134 ) ) {
V_39 = F_200 ( V_134 ) ;
goto V_118;
}
V_45 -> V_368 = V_368 ;
V_45 -> V_370 = V_370 ;
V_45 -> V_134 = V_134 ;
return 0 ;
V_118:
F_36 ( V_370 ) ;
F_36 ( V_368 ) ;
return V_39 ;
}
static int F_311 ( struct V_21 * V_22 )
{
T_6 V_97 ;
int V_39 ;
void * V_392 ;
void * V_393 ;
void * V_170 ;
V_107 V_119 ;
T_5 V_98 ;
struct V_105 * V_113 ;
T_5 V_116 ;
V_97 = sizeof ( V_106 ) + sizeof ( V_282 ) +
V_408 * sizeof ( V_106 ) ;
V_392 = F_281 ( V_97 , V_59 ) ;
if ( ! V_392 )
return - V_57 ;
V_39 = F_219 ( V_22 , V_22 -> V_292 . V_144 ,
L_40 , L_99 , NULL , 0 ,
V_392 , V_97 ) ;
F_25 ( L_77 , V_58 , V_39 ) ;
if ( V_39 < 0 )
goto V_49;
V_393 = V_392 ;
V_170 = V_392 + V_39 ;
V_39 = - V_391 ;
F_299 ( & V_393 , V_170 , V_119 , V_49 ) ;
F_312 ( & V_393 , V_170 , V_98 , V_49 ) ;
if ( V_98 > ( V_104 - sizeof ( struct V_105 ) )
/ sizeof ( V_107 ) ) {
V_39 = - V_4 ;
goto V_49;
}
if ( ! F_313 ( & V_393 , V_170 , V_98 * sizeof ( V_106 ) ) )
goto V_49;
V_39 = 0 ;
V_113 = F_63 ( V_98 , V_59 ) ;
if ( ! V_113 ) {
V_39 = - V_57 ;
goto V_49;
}
V_113 -> V_119 = V_119 ;
for ( V_116 = 0 ; V_116 < V_98 ; V_116 ++ )
V_113 -> V_122 [ V_116 ] = F_302 ( & V_393 ) ;
F_64 ( V_22 -> V_110 . V_113 ) ;
V_22 -> V_110 . V_113 = V_113 ;
F_25 ( L_100 ,
( unsigned long long ) V_119 , ( unsigned int ) V_98 ) ;
V_49:
F_36 ( V_392 ) ;
return V_39 ;
}
static const char * F_71 ( struct V_21 * V_22 ,
V_107 V_46 )
{
T_6 V_97 ;
void * V_392 ;
V_106 V_387 ;
int V_39 ;
void * V_393 ;
void * V_170 ;
char * V_134 ;
V_97 = sizeof ( V_282 ) + V_409 ;
V_392 = F_26 ( V_97 , V_59 ) ;
if ( ! V_392 )
return F_38 ( - V_57 ) ;
V_387 = F_294 ( V_46 ) ;
V_39 = F_219 ( V_22 , V_22 -> V_292 . V_144 ,
L_40 , L_101 ,
& V_387 , sizeof ( V_387 ) ,
V_392 , V_97 ) ;
F_25 ( L_77 , V_58 , V_39 ) ;
if ( V_39 < 0 ) {
V_134 = F_38 ( V_39 ) ;
goto V_49;
}
V_393 = V_392 ;
V_170 = V_392 + V_39 ;
V_134 = F_297 ( & V_393 , V_170 , NULL , V_59 ) ;
if ( F_30 ( V_134 ) )
goto V_49;
F_25 ( L_102 ,
( unsigned long long ) V_46 , V_134 ) ;
V_49:
F_36 ( V_392 ) ;
return V_134 ;
}
static int F_314 ( struct V_21 * V_22 )
{
bool V_111 = V_22 -> V_110 . V_112 == NULL ;
int V_39 ;
V_39 = F_295 ( V_22 ) ;
if ( V_39 )
return V_39 ;
if ( V_111 ) {
V_39 = F_315 ( V_22 ) ;
if ( V_39 )
return V_39 ;
}
V_39 = F_311 ( V_22 ) ;
if ( V_39 && V_111 ) {
F_36 ( V_22 -> V_110 . V_112 ) ;
V_22 -> V_110 . V_112 = NULL ;
}
return V_39 ;
}
static int F_247 ( struct V_21 * V_22 )
{
F_17 ( F_57 ( V_22 -> V_94 ) ) ;
if ( V_22 -> V_94 == 1 )
return F_241 ( V_22 ) ;
return F_314 ( V_22 ) ;
}
static int F_316 ( struct V_21 * V_22 )
{
int V_410 ;
V_410 = F_317 ( & V_411 ,
0 , F_8 ( 1 << V_412 ) ,
V_59 ) ;
if ( V_410 < 0 )
return V_410 ;
V_22 -> V_5 = V_410 ;
F_32 ( & V_413 ) ;
F_33 ( & V_22 -> V_62 , & V_414 ) ;
F_34 ( & V_413 ) ;
F_25 ( L_103 , V_22 , V_22 -> V_5 ) ;
return 0 ;
}
static void F_318 ( struct V_21 * V_22 )
{
F_32 ( & V_413 ) ;
F_319 ( & V_22 -> V_62 ) ;
F_34 ( & V_413 ) ;
F_320 ( & V_411 , V_22 -> V_5 ) ;
F_25 ( L_104 , V_22 , V_22 -> V_5 ) ;
}
static inline T_6 F_321 ( const char * * V_163 )
{
const char * V_415 = L_105 ;
* V_163 += strspn ( * V_163 , V_415 ) ;
return strcspn ( * V_163 , V_415 ) ;
}
static inline char * F_322 ( const char * * V_163 , T_6 * V_416 )
{
char * V_417 ;
T_6 V_117 ;
V_117 = F_321 ( V_163 ) ;
V_417 = F_323 ( * V_163 , V_117 + 1 , V_59 ) ;
if ( ! V_417 )
return NULL ;
* ( V_417 + V_117 ) = '\0' ;
* V_163 += V_117 ;
if ( V_416 )
* V_416 = V_117 ;
return V_417 ;
}
static int F_324 ( const char * V_163 ,
struct V_54 * * V_55 ,
struct V_73 * * V_348 ,
struct V_373 * * V_373 )
{
T_6 V_117 ;
char * V_101 ;
const char * V_418 ;
char * V_134 ;
T_6 V_419 ;
struct V_373 * V_45 = NULL ;
struct V_73 * V_74 = NULL ;
struct V_54 * V_420 ;
int V_39 ;
V_117 = F_321 ( & V_163 ) ;
if ( ! V_117 ) {
F_103 ( NULL , L_106 ) ;
return - V_4 ;
}
V_418 = V_163 ;
V_419 = V_117 + 1 ;
V_163 += V_117 ;
V_39 = - V_4 ;
V_101 = F_322 ( & V_163 , NULL ) ;
if ( ! V_101 )
return - V_57 ;
if ( ! * V_101 ) {
F_103 ( NULL , L_107 ) ;
goto V_118;
}
V_45 = F_280 () ;
if ( ! V_45 )
goto V_421;
V_45 -> V_368 = F_322 ( & V_163 , NULL ) ;
if ( ! V_45 -> V_368 )
goto V_421;
if ( ! * V_45 -> V_368 ) {
F_103 ( NULL , L_108 ) ;
goto V_118;
}
V_45 -> V_370 = F_322 ( & V_163 , NULL ) ;
if ( ! V_45 -> V_370 )
goto V_421;
if ( ! * V_45 -> V_370 ) {
F_103 ( NULL , L_109 ) ;
goto V_118;
}
V_117 = F_321 ( & V_163 ) ;
if ( ! V_117 ) {
V_163 = V_141 ;
V_117 = sizeof ( V_141 ) - 1 ;
} else if ( V_117 > V_409 ) {
V_39 = - V_422 ;
goto V_118;
}
V_134 = F_323 ( V_163 , V_117 + 1 , V_59 ) ;
if ( ! V_134 )
goto V_421;
* ( V_134 + V_117 ) = '\0' ;
V_45 -> V_134 = V_134 ;
V_74 = F_281 ( sizeof ( * V_74 ) , V_59 ) ;
if ( ! V_74 )
goto V_421;
V_74 -> V_28 = V_423 ;
V_74 -> V_84 = V_424 ;
V_420 = F_325 ( V_101 , V_418 ,
V_418 + V_419 - 1 ,
F_44 , V_74 ) ;
if ( F_30 ( V_420 ) ) {
V_39 = F_200 ( V_420 ) ;
goto V_118;
}
F_36 ( V_101 ) ;
* V_55 = V_420 ;
* V_348 = V_74 ;
* V_373 = V_45 ;
return 0 ;
V_421:
V_39 = - V_57 ;
V_118:
F_36 ( V_74 ) ;
F_173 ( V_45 ) ;
F_36 ( V_101 ) ;
return V_39 ;
}
static int F_326 ( struct V_53 * V_56 , const char * V_368 )
{
struct V_54 * V_348 = V_56 -> V_63 -> V_101 ;
V_107 V_425 ;
int V_426 = 0 ;
int V_39 ;
V_427:
V_39 = F_327 ( V_56 -> V_63 -> V_207 . V_407 , V_368 ) ;
if ( V_39 == - V_34 && V_426 ++ < 1 ) {
V_39 = F_328 ( & V_56 -> V_63 -> V_428 , L_110 ,
& V_425 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_56 -> V_63 -> V_207 . V_407 -> V_429 < V_425 ) {
F_329 ( & V_56 -> V_63 -> V_207 ) ;
( void ) F_330 ( & V_56 -> V_63 -> V_428 ,
V_425 ,
V_348 -> V_430 ) ;
goto V_427;
} else {
return - V_34 ;
}
}
return V_39 ;
}
static int F_331 ( struct V_21 * V_22 )
{
int V_39 ;
T_6 V_97 ;
char * V_237 ;
void * V_431 ;
char * V_371 ;
if ( V_22 -> V_45 -> V_371 ) {
V_22 -> V_94 = * V_22 -> V_45 -> V_371 ? 2 : 1 ;
return 0 ;
}
V_97 = sizeof ( V_432 ) + strlen ( V_22 -> V_45 -> V_370 ) ;
V_237 = F_26 ( V_97 , V_149 ) ;
if ( ! V_237 )
return - V_57 ;
sprintf ( V_237 , L_111 , V_432 , V_22 -> V_45 -> V_370 ) ;
F_25 ( L_112 , V_237 ) ;
V_97 = sizeof ( V_282 ) + V_400 ;
V_431 = F_281 ( V_97 , V_149 ) ;
if ( ! V_431 ) {
V_39 = - V_57 ;
goto V_49;
}
V_39 = F_219 ( V_22 , V_237 ,
L_40 , L_113 , NULL , 0 ,
V_431 , V_400 ) ;
F_25 ( L_77 , V_58 , V_39 ) ;
if ( V_39 == - V_34 ) {
V_371 = F_66 ( L_73 , V_59 ) ;
V_39 = V_371 ? 0 : - V_57 ;
if ( ! V_39 )
V_22 -> V_94 = 1 ;
} else if ( V_39 >= 0 ) {
void * V_393 = V_431 ;
V_371 = F_297 ( & V_393 , V_393 + V_39 ,
NULL , V_149 ) ;
V_39 = F_332 ( V_371 ) ;
if ( ! V_39 )
V_22 -> V_94 = 2 ;
}
if ( ! V_39 ) {
V_22 -> V_45 -> V_371 = V_371 ;
F_25 ( L_114 , V_371 ) ;
}
V_49:
F_36 ( V_431 ) ;
F_36 ( V_237 ) ;
return V_39 ;
}
static void F_333 ( struct V_21 * V_22 )
{
struct V_109 * V_110 ;
F_174 ( V_22 ) ;
V_110 = & V_22 -> V_110 ;
F_64 ( V_110 -> V_113 ) ;
F_36 ( V_110 -> V_115 ) ;
F_36 ( V_110 -> V_114 ) ;
F_36 ( V_110 -> V_112 ) ;
memset ( V_110 , 0 , sizeof ( * V_110 ) ) ;
}
static int F_315 ( struct V_21 * V_22 )
{
int V_39 ;
V_39 = F_296 ( V_22 ) ;
if ( V_39 )
goto V_118;
V_39 = F_298 ( V_22 ) ;
if ( V_39 )
goto V_118;
if ( V_22 -> V_110 . V_131 & V_433 ) {
V_39 = F_301 ( V_22 ) ;
if ( V_39 < 0 )
goto V_118;
}
return 0 ;
V_118:
V_22 -> V_110 . V_131 = 0 ;
F_36 ( V_22 -> V_110 . V_112 ) ;
V_22 -> V_110 . V_112 = NULL ;
return V_39 ;
}
static int F_334 ( struct V_21 * V_22 , int V_434 )
{
struct V_21 * V_265 = NULL ;
int V_39 ;
if ( ! V_22 -> V_256 )
return 0 ;
if ( ++ V_434 > V_435 ) {
F_300 ( L_115 , V_434 ) ;
V_39 = - V_4 ;
goto V_118;
}
V_265 = F_285 ( V_22 -> V_53 , V_22 -> V_256 ,
NULL ) ;
if ( ! V_265 ) {
V_39 = - V_57 ;
goto V_118;
}
F_39 ( V_22 -> V_53 ) ;
F_279 ( V_22 -> V_256 ) ;
V_39 = F_335 ( V_265 , V_434 ) ;
if ( V_39 < 0 )
goto V_118;
V_22 -> V_265 = V_265 ;
F_286 ( & V_22 -> V_257 , 1 ) ;
return 0 ;
V_118:
F_171 ( V_22 ) ;
F_293 ( V_265 ) ;
return V_39 ;
}
static int F_336 ( struct V_21 * V_22 )
{
int V_39 ;
V_39 = F_316 ( V_22 ) ;
if ( V_39 )
goto V_436;
F_337 ( V_437
< sizeof ( V_340 ) + V_438 ) ;
sprintf ( V_22 -> V_144 , L_116 , V_340 , V_22 -> V_5 ) ;
if ( ! V_13 ) {
V_39 = F_338 ( 0 , V_22 -> V_144 ) ;
if ( V_39 < 0 )
goto V_439;
V_22 -> V_341 = V_39 ;
V_22 -> V_7 = 0 ;
} else {
V_22 -> V_341 = V_440 ;
V_22 -> V_7 = F_7 ( V_22 -> V_5 ) ;
}
V_39 = F_252 ( V_22 ) ;
if ( V_39 )
goto V_441;
V_39 = F_76 ( V_22 ) ;
if ( V_39 )
goto V_442;
F_244 ( V_22 -> V_36 , V_22 -> V_27 . V_97 / V_333 ) ;
F_21 ( V_22 -> V_36 , V_22 -> V_27 . V_28 ) ;
F_339 ( & V_22 -> V_18 , L_60 , V_22 -> V_5 ) ;
V_39 = F_340 ( & V_22 -> V_18 ) ;
if ( V_39 )
goto V_443;
F_111 ( V_319 , & V_22 -> V_32 ) ;
F_249 ( & V_22 -> V_258 ) ;
F_341 ( V_22 -> V_36 ) ;
F_300 ( L_117 , V_22 -> V_36 -> V_339 ,
( unsigned long long ) V_22 -> V_27 . V_97 ) ;
return V_39 ;
V_443:
F_77 ( V_22 ) ;
V_442:
F_235 ( V_22 ) ;
V_441:
if ( ! V_13 )
F_342 ( V_22 -> V_341 , V_22 -> V_144 ) ;
V_439:
F_318 ( V_22 ) ;
V_436:
F_249 ( & V_22 -> V_258 ) ;
return V_39 ;
}
static int F_343 ( struct V_21 * V_22 )
{
struct V_373 * V_45 = V_22 -> V_45 ;
int V_39 ;
F_17 ( F_57 ( V_22 -> V_94 ) ) ;
V_22 -> V_293 . V_250 = F_161 ( V_22 -> V_251 ) ;
if ( V_22 -> V_94 == 1 )
V_39 = F_162 ( & V_22 -> V_292 , V_59 , L_111 ,
V_45 -> V_370 , V_444 ) ;
else
V_39 = F_162 ( & V_22 -> V_292 , V_59 , L_111 ,
V_445 , V_45 -> V_371 ) ;
return V_39 ;
}
static void F_344 ( struct V_21 * V_22 )
{
F_333 ( V_22 ) ;
V_22 -> V_94 = 0 ;
F_36 ( V_22 -> V_45 -> V_371 ) ;
V_22 -> V_45 -> V_371 = NULL ;
F_293 ( V_22 ) ;
}
static int F_335 ( struct V_21 * V_22 , int V_434 )
{
int V_39 ;
V_39 = F_331 ( V_22 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_343 ( V_22 ) ;
if ( V_39 )
goto V_446;
if ( ! V_434 ) {
V_39 = F_214 ( V_22 ) ;
if ( V_39 ) {
if ( V_39 == - V_34 )
F_300 ( L_118 ,
V_22 -> V_45 -> V_368 ,
V_22 -> V_45 -> V_370 ) ;
goto V_446;
}
}
V_39 = F_247 ( V_22 ) ;
if ( V_39 )
goto V_447;
if ( ! V_434 )
V_39 = F_308 ( V_22 ) ;
else
V_39 = F_309 ( V_22 ) ;
if ( V_39 ) {
if ( V_39 == - V_34 )
F_300 ( L_119 ,
V_22 -> V_45 -> V_368 ,
V_22 -> V_45 -> V_370 ,
V_22 -> V_45 -> V_134 ) ;
goto V_448;
}
if ( V_22 -> V_110 . V_131 & V_449 ) {
V_39 = F_248 ( V_22 ) ;
if ( V_39 )
goto V_448;
if ( ! V_434 && V_22 -> V_256 )
F_103 ( V_22 ,
L_120 ) ;
}
V_39 = F_334 ( V_22 , V_434 ) ;
if ( V_39 )
goto V_448;
F_25 ( L_121 ,
V_22 -> V_94 , V_22 -> V_292 . V_144 ) ;
return 0 ;
V_448:
F_333 ( V_22 ) ;
V_447:
if ( ! V_434 )
F_217 ( V_22 ) ;
V_446:
V_22 -> V_94 = 0 ;
F_36 ( V_22 -> V_45 -> V_371 ) ;
V_22 -> V_45 -> V_371 = NULL ;
return V_39 ;
}
static T_10 F_345 ( struct V_450 * V_378 ,
const char * V_163 ,
T_6 V_372 )
{
struct V_21 * V_22 = NULL ;
struct V_54 * V_55 = NULL ;
struct V_73 * V_74 = NULL ;
struct V_373 * V_45 = NULL ;
struct V_53 * V_56 ;
bool V_28 ;
int V_451 ;
if ( ! F_346 ( V_377 ) )
return - V_452 ;
V_451 = F_324 ( V_163 , & V_55 , & V_74 , & V_45 ) ;
if ( V_451 < 0 )
goto V_49;
V_56 = F_49 ( V_55 ) ;
if ( F_30 ( V_56 ) ) {
V_451 = F_200 ( V_56 ) ;
goto V_453;
}
V_451 = F_326 ( V_56 , V_45 -> V_368 ) ;
if ( V_451 < 0 ) {
if ( V_451 == - V_34 )
F_300 ( L_122 , V_45 -> V_368 ) ;
goto V_454;
}
V_45 -> V_369 = ( V_107 ) V_451 ;
if ( V_45 -> V_369 > ( V_107 ) V_401 ) {
F_103 ( NULL , L_123 ,
( unsigned long long ) V_45 -> V_369 , V_401 ) ;
V_451 = - V_132 ;
goto V_454;
}
V_22 = F_285 ( V_56 , V_45 , V_74 ) ;
if ( ! V_22 ) {
V_451 = - V_57 ;
goto V_454;
}
V_56 = NULL ;
V_45 = NULL ;
V_74 = NULL ;
F_246 ( & V_22 -> V_258 ) ;
V_451 = F_335 ( V_22 , 0 ) ;
if ( V_451 < 0 )
goto V_455;
V_28 = V_22 -> V_348 -> V_28 ;
if ( V_22 -> V_45 -> V_46 != V_47 )
V_28 = true ;
V_22 -> V_27 . V_28 = V_28 ;
V_451 = F_336 ( V_22 ) ;
if ( V_451 ) {
F_217 ( V_22 ) ;
F_344 ( V_22 ) ;
goto V_49;
}
V_451 = V_372 ;
V_49:
F_284 ( V_377 ) ;
return V_451 ;
V_455:
F_249 ( & V_22 -> V_258 ) ;
F_293 ( V_22 ) ;
V_454:
F_55 ( V_56 ) ;
V_453:
F_173 ( V_45 ) ;
F_36 ( V_74 ) ;
goto V_49;
}
static T_10 F_347 ( struct V_450 * V_378 ,
const char * V_163 ,
T_6 V_372 )
{
if ( V_13 )
return - V_4 ;
return F_345 ( V_378 , V_163 , V_372 ) ;
}
static T_10 F_348 ( struct V_450 * V_378 ,
const char * V_163 ,
T_6 V_372 )
{
return F_345 ( V_378 , V_163 , V_372 ) ;
}
static void F_349 ( struct V_21 * V_22 )
{
F_235 ( V_22 ) ;
F_141 ( V_319 , & V_22 -> V_32 ) ;
F_350 ( & V_22 -> V_18 ) ;
F_77 ( V_22 ) ;
if ( ! V_13 )
F_342 ( V_22 -> V_341 , V_22 -> V_144 ) ;
F_318 ( V_22 ) ;
}
static void F_172 ( struct V_21 * V_22 )
{
while ( V_22 -> V_265 ) {
struct V_21 * V_456 = V_22 ;
struct V_21 * V_457 = V_456 -> V_265 ;
struct V_21 * V_458 ;
while ( V_457 && ( V_458 = V_457 -> V_265 ) ) {
V_456 = V_457 ;
V_457 = V_458 ;
}
F_17 ( V_457 ) ;
F_344 ( V_457 ) ;
V_456 -> V_265 = NULL ;
V_456 -> V_191 = 0 ;
F_17 ( V_456 -> V_256 ) ;
F_173 ( V_456 -> V_256 ) ;
V_456 -> V_256 = NULL ;
}
}
static T_10 F_351 ( struct V_450 * V_378 ,
const char * V_163 ,
T_6 V_372 )
{
struct V_21 * V_22 = NULL ;
struct V_459 * V_156 ;
int V_5 ;
unsigned long V_460 ;
bool V_461 = false ;
int V_39 ;
V_39 = F_352 ( V_163 , 10 , & V_460 ) ;
if ( V_39 )
return V_39 ;
V_5 = ( int ) V_460 ;
if ( V_5 != V_460 )
return - V_4 ;
V_39 = - V_34 ;
F_32 ( & V_413 ) ;
F_353 (tmp, &rbd_dev_list) {
V_22 = F_354 ( V_156 , struct V_21 , V_62 ) ;
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
V_461 = F_105 ( V_31 ,
& V_22 -> V_32 ) ;
F_14 ( & V_22 -> V_30 ) ;
}
F_34 ( & V_413 ) ;
if ( V_39 < 0 || V_461 )
return V_39 ;
F_217 ( V_22 ) ;
F_349 ( V_22 ) ;
F_344 ( V_22 ) ;
return V_372 ;
}
static T_10 F_355 ( struct V_450 * V_378 ,
const char * V_163 ,
T_6 V_372 )
{
if ( V_13 )
return - V_4 ;
return F_351 ( V_378 , V_163 , V_372 ) ;
}
static T_10 F_356 ( struct V_450 * V_378 ,
const char * V_163 ,
T_6 V_372 )
{
return F_351 ( V_378 , V_163 , V_372 ) ;
}
static int F_357 ( void )
{
int V_39 ;
V_39 = F_358 ( & V_381 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_359 ( & V_379 ) ;
if ( V_39 < 0 )
F_360 ( & V_381 ) ;
return V_39 ;
}
static void F_361 ( void )
{
F_362 ( & V_379 ) ;
F_360 ( & V_381 ) ;
}
static int F_363 ( void )
{
F_17 ( ! V_259 ) ;
V_259 = F_364 ( V_194 , 0 ) ;
if ( ! V_259 )
return - V_57 ;
F_17 ( ! V_254 ) ;
V_254 = F_364 ( V_182 , 0 ) ;
if ( ! V_254 )
goto V_118;
F_17 ( ! V_145 ) ;
V_145 = F_365 ( L_124 ,
V_150 + 1 , 1 , 0 , NULL ) ;
if ( V_145 )
return 0 ;
V_118:
F_366 ( V_254 ) ;
V_254 = NULL ;
F_366 ( V_259 ) ;
V_259 = NULL ;
return - V_57 ;
}
static void F_367 ( void )
{
F_17 ( V_145 ) ;
F_366 ( V_145 ) ;
V_145 = NULL ;
F_17 ( V_254 ) ;
F_366 ( V_254 ) ;
V_254 = NULL ;
F_17 ( V_259 ) ;
F_366 ( V_259 ) ;
V_259 = NULL ;
}
static int T_12 F_368 ( void )
{
int V_451 ;
if ( ! F_369 ( NULL ) ) {
F_103 ( NULL , L_125 ) ;
return - V_4 ;
}
V_451 = F_363 () ;
if ( V_451 )
return V_451 ;
V_326 = F_370 ( V_340 , V_462 , 0 ) ;
if ( ! V_326 ) {
V_451 = - V_57 ;
goto V_463;
}
if ( V_13 ) {
V_440 = F_338 ( 0 , V_340 ) ;
if ( V_440 < 0 ) {
V_451 = V_440 ;
goto V_464;
}
}
V_451 = F_357 () ;
if ( V_451 )
goto V_441;
if ( V_13 )
F_300 ( L_126 , V_440 ) ;
else
F_300 ( L_127 ) ;
return 0 ;
V_441:
if ( V_13 )
F_342 ( V_440 , V_340 ) ;
V_464:
F_371 ( V_326 ) ;
V_463:
F_367 () ;
return V_451 ;
}
static void T_13 F_372 ( void )
{
F_373 ( & V_411 ) ;
F_361 () ;
if ( V_13 )
F_342 ( V_440 , V_340 ) ;
F_371 ( V_326 ) ;
F_367 () ;
}
