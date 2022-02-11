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
static bool F_9 ( struct V_8 * V_9 )
{
return ( V_9 -> V_10 . V_11 & V_12 ) &&
V_9 -> V_13 -> V_14 == V_15 &&
! V_9 -> V_16 . V_17 ;
}
static bool F_10 ( struct V_8 * V_9 )
{
return V_9 -> V_18 == V_19 ||
V_9 -> V_18 == V_20 ;
}
static bool F_11 ( struct V_8 * V_9 )
{
bool V_21 ;
F_12 ( & V_9 -> V_22 ) ;
V_21 = F_10 ( V_9 ) ;
F_13 ( & V_9 -> V_22 ) ;
return V_21 ;
}
static T_2 F_14 ( struct V_23 * V_24 ,
struct V_25 * V_26 , int V_27 )
{
if ( ! V_28 &&
( V_26 == & V_29 . V_26 ||
V_26 == & V_30 . V_26 ) )
return 0 ;
return V_26 -> V_31 ;
}
static void F_15 ( struct V_32 * V_33 )
{
}
static int F_16 ( struct V_34 * V_35 , T_3 V_31 )
{
struct V_8 * V_9 = V_35 -> V_36 -> V_37 ;
bool V_38 = false ;
if ( ( V_31 & V_39 ) && V_9 -> V_16 . V_17 )
return - V_40 ;
F_17 ( & V_9 -> V_41 ) ;
if ( F_18 ( V_42 , & V_9 -> V_43 ) )
V_38 = true ;
else
V_9 -> V_44 ++ ;
F_19 ( & V_9 -> V_41 ) ;
if ( V_38 )
return - V_45 ;
( void ) F_20 ( & V_9 -> V_33 ) ;
return 0 ;
}
static void F_21 ( struct V_46 * V_47 , T_3 V_31 )
{
struct V_8 * V_9 = V_47 -> V_37 ;
unsigned long V_48 ;
F_17 ( & V_9 -> V_41 ) ;
V_48 = V_9 -> V_44 -- ;
F_19 ( & V_9 -> V_41 ) ;
F_22 ( V_48 > 0 ) ;
F_23 ( & V_9 -> V_33 ) ;
}
static int F_24 ( struct V_8 * V_9 , unsigned long V_49 )
{
int V_50 = 0 ;
int V_51 ;
bool V_52 ;
bool V_53 = false ;
if ( F_25 ( V_51 , ( int V_54 * ) ( V_49 ) ) )
return - V_55 ;
V_52 = V_51 ? true : false ;
if ( V_9 -> V_13 -> V_14 != V_15 && ! V_52 )
return - V_40 ;
F_17 ( & V_9 -> V_41 ) ;
if ( V_9 -> V_44 > 1 ) {
V_50 = - V_56 ;
goto V_57;
}
if ( V_9 -> V_16 . V_17 != V_52 ) {
V_9 -> V_16 . V_17 = V_52 ;
V_53 = true ;
}
V_57:
F_19 ( & V_9 -> V_41 ) ;
if ( V_50 == 0 && V_53 )
F_26 ( V_9 -> V_47 , V_52 ? 1 : 0 ) ;
return V_50 ;
}
static int F_27 ( struct V_34 * V_35 , T_3 V_31 ,
unsigned int V_58 , unsigned long V_49 )
{
struct V_8 * V_9 = V_35 -> V_36 -> V_37 ;
int V_50 = 0 ;
switch ( V_58 ) {
case V_59 :
V_50 = F_24 ( V_9 , V_49 ) ;
break;
default:
V_50 = - V_60 ;
}
return V_50 ;
}
static int F_28 ( struct V_34 * V_35 , T_3 V_31 ,
unsigned int V_58 , unsigned long V_49 )
{
return F_27 ( V_35 , V_31 , V_58 , V_49 ) ;
}
static struct V_61 * F_29 ( struct V_62 * V_63 )
{
struct V_61 * V_64 ;
int V_50 = - V_65 ;
F_30 ( L_1 , V_66 ) ;
V_64 = F_31 ( sizeof( struct V_61 ) , V_67 ) ;
if ( ! V_64 )
goto V_68;
F_32 ( & V_64 -> V_69 ) ;
F_33 ( & V_64 -> V_70 ) ;
V_64 -> V_71 = F_34 ( V_63 , V_64 , 0 , 0 ) ;
if ( F_35 ( V_64 -> V_71 ) )
goto V_72;
V_63 = NULL ;
V_50 = F_36 ( V_64 -> V_71 ) ;
if ( V_50 < 0 )
goto V_73;
F_37 ( & V_74 ) ;
F_38 ( & V_64 -> V_70 , & V_75 ) ;
F_39 ( & V_74 ) ;
F_30 ( L_2 , V_66 , V_64 ) ;
return V_64 ;
V_73:
F_40 ( V_64 -> V_71 ) ;
V_72:
F_41 ( V_64 ) ;
V_68:
if ( V_63 )
F_42 ( V_63 ) ;
F_30 ( L_3 , V_66 , V_50 ) ;
return F_43 ( V_50 ) ;
}
static struct V_61 * F_44 ( struct V_61 * V_64 )
{
F_45 ( & V_64 -> V_69 ) ;
return V_64 ;
}
static struct V_61 * F_46 ( struct V_62 * V_63 )
{
struct V_61 * V_76 ;
bool V_77 = false ;
if ( V_63 -> V_43 & V_78 )
return NULL ;
F_37 ( & V_74 ) ;
F_47 (client_node, &rbd_client_list, node) {
if ( ! F_48 ( V_63 , V_76 -> V_71 ) ) {
F_44 ( V_76 ) ;
V_77 = true ;
break;
}
}
F_39 ( & V_74 ) ;
return V_77 ? V_76 : NULL ;
}
static int F_49 ( char * V_79 , void * V_80 )
{
struct V_81 * V_82 = V_80 ;
T_4 V_83 [ V_84 ] ;
int V_85 , V_86 , V_50 ;
V_85 = F_50 ( V_79 , V_87 , V_83 ) ;
if ( V_85 < V_88 ) {
V_50 = F_51 ( & V_83 [ 0 ] , & V_86 ) ;
if ( V_50 < 0 ) {
F_52 ( L_4 , V_79 ) ;
return V_50 ;
}
F_30 ( L_5 , V_85 , V_86 ) ;
} else if ( V_85 > V_88 && V_85 < V_89 ) {
F_30 ( L_6 , V_85 , V_83 [ 0 ] . V_90 ) ;
} else {
F_30 ( L_7 , V_85 ) ;
}
switch ( V_85 ) {
case V_91 :
if ( V_86 < 1 ) {
F_52 ( L_8 ) ;
return - V_4 ;
}
V_82 -> V_92 = V_86 ;
break;
case V_93 :
V_82 -> V_17 = true ;
break;
case V_94 :
V_82 -> V_17 = false ;
break;
case V_95 :
V_82 -> V_96 = true ;
break;
default:
return - V_4 ;
}
return 0 ;
}
static char * F_53 ( enum V_97 V_98 )
{
switch ( V_98 ) {
case V_99 :
return L_9 ;
case V_100 :
return L_10 ;
case V_101 :
return L_11 ;
default:
return L_12 ;
}
}
static struct V_61 * F_54 ( struct V_62 * V_63 )
{
struct V_61 * V_64 ;
F_55 ( & V_102 , V_103 ) ;
V_64 = F_46 ( V_63 ) ;
if ( V_64 )
F_42 ( V_63 ) ;
else
V_64 = F_29 ( V_63 ) ;
F_56 ( & V_102 ) ;
return V_64 ;
}
static void F_57 ( struct V_69 * V_69 )
{
struct V_61 * V_64 = F_58 ( V_69 , struct V_61 , V_69 ) ;
F_30 ( L_2 , V_66 , V_64 ) ;
F_37 ( & V_74 ) ;
F_59 ( & V_64 -> V_70 ) ;
F_39 ( & V_74 ) ;
F_40 ( V_64 -> V_71 ) ;
F_41 ( V_64 ) ;
}
static void F_60 ( struct V_61 * V_64 )
{
if ( V_64 )
F_61 ( & V_64 -> V_69 , F_57 ) ;
}
static bool F_62 ( T_5 V_104 )
{
return V_104 == 1 || V_104 == 2 ;
}
static bool F_63 ( struct V_105 * V_106 )
{
T_6 V_107 ;
T_5 V_108 ;
if ( memcmp ( & V_106 -> V_109 , V_110 , sizeof ( V_110 ) ) )
return false ;
if ( V_106 -> V_111 . V_112 < V_113 )
return false ;
if ( V_106 -> V_111 . V_112 > 8 * sizeof ( int ) - 1 )
return false ;
V_108 = F_64 ( V_106 -> V_108 ) ;
V_107 = V_114 - sizeof ( struct V_115 ) ;
if ( V_108 > V_107 / sizeof ( V_116 ) )
return false ;
V_107 -= V_108 * sizeof ( V_116 ) ;
if ( ( V_117 ) V_107 < F_65 ( V_106 -> V_118 ) )
return false ;
return true ;
}
static int F_66 ( struct V_8 * V_9 ,
struct V_105 * V_106 )
{
struct V_119 * V_10 = & V_9 -> V_10 ;
bool V_120 = V_10 -> V_121 == NULL ;
struct V_115 * V_122 ;
char * V_121 = NULL ;
char * V_123 = NULL ;
V_117 * V_124 = NULL ;
T_5 V_108 ;
int V_50 = - V_65 ;
T_5 V_125 ;
if ( V_120 ) {
T_6 V_126 ;
V_126 = F_67 ( V_106 -> V_121 ,
sizeof ( V_106 -> V_121 ) ) ;
V_121 = F_31 ( V_126 + 1 , V_67 ) ;
if ( ! V_121 )
return - V_65 ;
memcpy ( V_121 , V_106 -> V_121 , V_126 ) ;
V_121 [ V_126 ] = '\0' ;
}
V_108 = F_64 ( V_106 -> V_108 ) ;
V_122 = F_68 ( V_108 , V_67 ) ;
if ( ! V_122 )
goto V_127;
V_122 -> V_128 = F_65 ( V_106 -> V_129 ) ;
if ( V_108 ) {
struct V_130 * V_131 ;
V_117 V_118 = F_65 ( V_106 -> V_118 ) ;
if ( V_118 > ( V_117 ) V_114 )
goto V_132;
V_123 = F_31 ( V_118 , V_67 ) ;
if ( ! V_123 )
goto V_127;
V_124 = F_69 ( V_108 ,
sizeof( * V_10 -> V_124 ) ,
V_67 ) ;
if ( ! V_124 )
goto V_127;
memcpy ( V_123 , & V_106 -> V_131 [ V_108 ] , V_118 ) ;
V_131 = V_106 -> V_131 ;
for ( V_125 = 0 ; V_125 < V_108 ; V_125 ++ ) {
V_122 -> V_131 [ V_125 ] = F_65 ( V_131 [ V_125 ] . V_133 ) ;
V_124 [ V_125 ] = F_65 ( V_131 [ V_125 ] . V_134 ) ;
}
}
if ( V_120 ) {
V_10 -> V_121 = V_121 ;
V_10 -> V_135 = V_106 -> V_111 . V_112 ;
V_10 -> V_136 = V_106 -> V_111 . V_136 ;
V_10 -> V_137 = V_106 -> V_111 . V_137 ;
V_10 -> V_138 = 0 ;
V_10 -> V_139 = 0 ;
V_10 -> V_11 = 0 ;
} else {
F_70 ( V_10 -> V_122 ) ;
F_41 ( V_10 -> V_123 ) ;
F_41 ( V_10 -> V_124 ) ;
}
V_10 -> V_134 = F_65 ( V_106 -> V_134 ) ;
V_10 -> V_122 = V_122 ;
V_10 -> V_123 = V_123 ;
V_10 -> V_124 = V_124 ;
return 0 ;
V_132:
V_50 = - V_140 ;
V_127:
F_41 ( V_124 ) ;
F_41 ( V_123 ) ;
F_70 ( V_122 ) ;
F_41 ( V_121 ) ;
return V_50 ;
}
static const char * F_71 ( struct V_8 * V_9 , T_5 V_141 )
{
const char * V_142 ;
F_22 ( V_141 < V_9 -> V_10 . V_122 -> V_143 ) ;
V_142 = V_9 -> V_10 . V_123 ;
while ( V_141 -- )
V_142 += strlen ( V_142 ) + 1 ;
return F_72 ( V_142 , V_67 ) ;
}
static int F_73 ( const void * V_144 , const void * V_145 )
{
V_117 V_146 = * ( V_117 * ) V_144 ;
V_117 V_147 = * ( V_117 * ) V_145 ;
if ( V_146 < V_147 )
return 1 ;
return V_146 == V_147 ? 0 : - 1 ;
}
static T_5 F_74 ( struct V_8 * V_9 , V_117 V_14 )
{
struct V_115 * V_122 = V_9 -> V_10 . V_122 ;
V_117 * V_77 ;
V_77 = bsearch ( & V_14 , & V_122 -> V_131 , V_122 -> V_143 ,
sizeof ( V_14 ) , F_73 ) ;
return V_77 ? ( T_5 ) ( V_77 - & V_122 -> V_131 [ 0 ] ) : V_148 ;
}
static const char * F_75 ( struct V_8 * V_9 ,
V_117 V_14 )
{
T_5 V_141 ;
const char * V_142 ;
V_141 = F_74 ( V_9 , V_14 ) ;
if ( V_141 == V_148 )
return F_43 ( - V_45 ) ;
V_142 = F_71 ( V_9 , V_141 ) ;
return V_142 ? V_142 : F_43 ( - V_65 ) ;
}
static const char * F_76 ( struct V_8 * V_9 , V_117 V_14 )
{
if ( V_14 == V_15 )
return V_149 ;
F_22 ( F_62 ( V_9 -> V_104 ) ) ;
if ( V_9 -> V_104 == 1 )
return F_75 ( V_9 , V_14 ) ;
return F_77 ( V_9 , V_14 ) ;
}
static int F_78 ( struct V_8 * V_9 , V_117 V_14 ,
V_117 * V_150 )
{
F_22 ( F_62 ( V_9 -> V_104 ) ) ;
if ( V_14 == V_15 ) {
* V_150 = V_9 -> V_10 . V_134 ;
} else if ( V_9 -> V_104 == 1 ) {
T_5 V_141 ;
V_141 = F_74 ( V_9 , V_14 ) ;
if ( V_141 == V_148 )
return - V_45 ;
* V_150 = V_9 -> V_10 . V_124 [ V_141 ] ;
} else {
V_117 V_107 = 0 ;
int V_50 ;
V_50 = F_79 ( V_9 , V_14 , NULL , & V_107 ) ;
if ( V_50 )
return V_50 ;
* V_150 = V_107 ;
}
return 0 ;
}
static int F_80 ( struct V_8 * V_9 , V_117 V_14 ,
V_117 * V_151 )
{
F_22 ( F_62 ( V_9 -> V_104 ) ) ;
if ( V_14 == V_15 ) {
* V_151 = V_9 -> V_10 . V_11 ;
} else if ( V_9 -> V_104 == 1 ) {
* V_151 = 0 ;
} else {
V_117 V_11 = 0 ;
int V_50 ;
V_50 = F_81 ( V_9 , V_14 , & V_11 ) ;
if ( V_50 )
return V_50 ;
* V_151 = V_11 ;
}
return 0 ;
}
static int F_82 ( struct V_8 * V_9 )
{
V_117 V_14 = V_9 -> V_13 -> V_14 ;
V_117 V_107 = 0 ;
V_117 V_11 = 0 ;
int V_50 ;
V_50 = F_78 ( V_9 , V_14 , & V_107 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_80 ( V_9 , V_14 , & V_11 ) ;
if ( V_50 )
return V_50 ;
V_9 -> V_16 . V_107 = V_107 ;
V_9 -> V_16 . V_11 = V_11 ;
return 0 ;
}
static void F_83 ( struct V_8 * V_9 )
{
V_9 -> V_16 . V_107 = 0 ;
V_9 -> V_16 . V_11 = 0 ;
}
static void F_84 ( const char * V_152 )
{
F_85 ( V_153 , ( void * ) V_152 ) ;
}
static const char * F_86 ( struct V_8 * V_9 , V_117 V_154 )
{
char * V_152 ;
V_117 V_155 ;
int V_50 ;
char * V_156 ;
V_152 = F_87 ( V_153 , V_157 ) ;
if ( ! V_152 )
return NULL ;
V_155 = V_154 >> V_9 -> V_10 . V_135 ;
V_156 = L_13 ;
if ( V_9 -> V_104 == 2 )
V_156 = L_14 ;
V_50 = snprintf ( V_152 , V_158 + 1 , V_156 ,
V_9 -> V_10 . V_121 , V_155 ) ;
if ( V_50 < 0 || V_50 > V_158 ) {
F_52 ( L_15 ,
V_155 , V_50 ) ;
F_84 ( V_152 ) ;
V_152 = NULL ;
}
return V_152 ;
}
static V_117 F_88 ( struct V_8 * V_9 , V_117 V_154 )
{
V_117 V_159 = ( V_117 ) 1 << V_9 -> V_10 . V_135 ;
return V_154 & ( V_159 - 1 ) ;
}
static V_117 F_89 ( struct V_8 * V_9 ,
V_117 V_154 , V_117 V_160 )
{
V_117 V_159 = ( V_117 ) 1 << V_9 -> V_10 . V_135 ;
V_154 &= V_159 - 1 ;
F_22 ( V_160 <= V_161 - V_154 ) ;
if ( V_154 + V_160 > V_159 )
V_160 = V_159 - V_154 ;
return V_160 ;
}
static V_117 F_90 ( struct V_119 * V_10 )
{
return 1 << V_10 -> V_135 ;
}
static void F_91 ( struct V_162 * V_163 )
{
struct V_162 * V_164 ;
while ( V_163 ) {
V_164 = V_163 ;
V_163 = V_163 -> V_165 ;
F_92 ( V_164 ) ;
}
}
static void F_93 ( struct V_162 * V_163 , int V_166 )
{
struct V_167 V_168 ;
struct V_169 V_170 ;
unsigned long V_43 ;
void * V_171 ;
int V_172 = 0 ;
while ( V_163 ) {
F_94 (bv, chain, iter) {
if ( V_172 + V_168 . V_173 > V_166 ) {
int V_174 = F_95 ( V_166 - V_172 , 0 ) ;
V_171 = F_96 ( & V_168 , & V_43 ) ;
memset ( V_171 + V_174 , 0 ,
V_168 . V_173 - V_174 ) ;
F_97 ( V_168 . V_175 ) ;
F_98 ( V_171 , & V_43 ) ;
}
V_172 += V_168 . V_173 ;
}
V_163 = V_163 -> V_165 ;
}
}
static void F_99 ( struct V_176 * * V_177 , V_117 V_154 , V_117 V_178 )
{
struct V_176 * * V_176 = & V_177 [ V_154 >> V_179 ] ;
F_22 ( V_178 > V_154 ) ;
F_22 ( V_178 - V_154 <= ( V_117 ) V_114 ) ;
while ( V_154 < V_178 ) {
T_6 V_180 ;
T_6 V_160 ;
unsigned long V_43 ;
void * V_181 ;
V_180 = V_154 & ~ V_182 ;
V_160 = F_100 ( T_6 , V_183 - V_180 , V_178 - V_154 ) ;
F_101 ( V_43 ) ;
V_181 = F_102 ( * V_176 ) ;
memset ( V_181 + V_180 , 0 , V_160 ) ;
F_97 ( * V_176 ) ;
F_103 ( V_181 ) ;
F_104 ( V_43 ) ;
V_154 += V_160 ;
V_176 ++ ;
}
}
static struct V_162 * F_105 ( struct V_162 * V_184 ,
unsigned int V_154 ,
unsigned int V_126 ,
T_7 V_185 )
{
struct V_162 * V_162 ;
V_162 = F_106 ( V_184 , V_185 ) ;
if ( ! V_162 )
return NULL ;
F_107 ( V_162 , V_154 ) ;
V_162 -> V_186 . V_187 = V_126 ;
return V_162 ;
}
static struct V_162 * F_108 ( struct V_162 * * V_184 ,
unsigned int * V_154 ,
unsigned int V_126 ,
T_7 V_185 )
{
struct V_162 * V_188 = * V_184 ;
unsigned int V_189 = * V_154 ;
struct V_162 * V_163 = NULL ;
struct V_162 * * V_178 ;
if ( ! V_188 || V_189 >= V_188 -> V_186 . V_187 || ! V_126 )
return NULL ;
V_178 = & V_163 ;
while ( V_126 ) {
unsigned int V_187 ;
struct V_162 * V_162 ;
if ( ! V_188 ) {
F_109 ( NULL , L_16 , V_126 ) ;
goto V_127;
}
V_187 = F_100 (unsigned int, bi->bi_iter.bi_size - off, len) ;
V_162 = F_105 ( V_188 , V_189 , V_187 , V_185 ) ;
if ( ! V_162 )
goto V_127;
* V_178 = V_162 ;
V_178 = & V_162 -> V_165 ;
V_189 += V_187 ;
if ( V_189 == V_188 -> V_186 . V_187 ) {
V_188 = V_188 -> V_165 ;
V_189 = 0 ;
}
V_126 -= V_187 ;
}
* V_184 = V_188 ;
* V_154 = V_189 ;
return V_163 ;
V_127:
F_91 ( V_163 ) ;
return NULL ;
}
static void F_110 ( struct V_190 * V_191 )
{
if ( F_111 ( V_192 , & V_191 -> V_43 ) ) {
struct V_8 * V_9 ;
V_9 = V_191 -> V_193 -> V_9 ;
F_109 ( V_9 , L_17 ,
V_191 ) ;
}
}
static bool F_112 ( struct V_190 * V_191 )
{
F_113 () ;
return F_18 ( V_192 , & V_191 -> V_43 ) != 0 ;
}
static void F_114 ( struct V_190 * V_191 )
{
if ( F_111 ( V_194 , & V_191 -> V_43 ) ) {
struct V_8 * V_9 = NULL ;
if ( F_112 ( V_191 ) )
V_9 = V_191 -> V_193 -> V_9 ;
F_109 ( V_9 , L_18 ,
V_191 ) ;
}
}
static bool F_115 ( struct V_190 * V_191 )
{
F_113 () ;
return F_18 ( V_194 , & V_191 -> V_43 ) != 0 ;
}
static void F_116 ( struct V_190 * V_191 ,
bool V_195 )
{
if ( V_195 )
F_117 ( V_196 , & V_191 -> V_43 ) ;
F_117 ( V_197 , & V_191 -> V_43 ) ;
F_113 () ;
}
static bool F_118 ( struct V_190 * V_191 )
{
F_113 () ;
return F_18 ( V_197 , & V_191 -> V_43 ) != 0 ;
}
static bool F_119 ( struct V_190 * V_191 )
{
F_113 () ;
return F_18 ( V_196 , & V_191 -> V_43 ) != 0 ;
}
static bool F_120 ( struct V_190 * V_191 )
{
struct V_8 * V_9 = V_191 -> V_193 -> V_9 ;
return V_191 -> V_198 <
F_121 ( V_9 -> V_199 , F_90 ( & V_9 -> V_10 ) ) ;
}
static void F_122 ( struct V_190 * V_191 )
{
F_30 ( L_19 , V_66 , V_191 ,
F_123 ( & V_191 -> V_69 . V_200 ) ) ;
F_45 ( & V_191 -> V_69 ) ;
}
static void F_124 ( struct V_190 * V_191 )
{
F_22 ( V_191 != NULL ) ;
F_30 ( L_19 , V_66 , V_191 ,
F_123 ( & V_191 -> V_69 . V_200 ) ) ;
F_61 ( & V_191 -> V_69 , V_201 ) ;
}
static void F_125 ( struct V_202 * V_193 )
{
F_30 ( L_20 , V_66 , V_193 ,
F_123 ( & V_193 -> V_69 . V_200 ) ) ;
F_45 ( & V_193 -> V_69 ) ;
}
static void F_126 ( struct V_202 * V_193 )
{
F_22 ( V_193 != NULL ) ;
F_30 ( L_20 , V_66 , V_193 ,
F_123 ( & V_193 -> V_69 . V_200 ) ) ;
if ( F_127 ( V_193 ) )
F_61 ( & V_193 -> V_69 , V_203 ) ;
else
F_61 ( & V_193 -> V_69 , V_204 ) ;
}
static inline void F_128 ( struct V_202 * V_193 ,
struct V_190 * V_191 )
{
F_22 ( V_191 -> V_193 == NULL ) ;
V_191 -> V_193 = V_193 ;
V_191 -> V_141 = V_193 -> V_205 ;
F_22 ( ! F_112 ( V_191 ) ) ;
F_110 ( V_191 ) ;
F_22 ( V_191 -> V_141 != V_206 ) ;
V_193 -> V_205 ++ ;
F_38 ( & V_191 -> V_207 , & V_193 -> V_208 ) ;
F_30 ( L_21 , V_66 , V_193 , V_191 ,
V_191 -> V_141 ) ;
}
static inline void F_129 ( struct V_202 * V_193 ,
struct V_190 * V_191 )
{
F_22 ( V_191 -> V_141 != V_206 ) ;
F_30 ( L_21 , V_66 , V_193 , V_191 ,
V_191 -> V_141 ) ;
F_59 ( & V_191 -> V_207 ) ;
F_22 ( V_193 -> V_205 > 0 ) ;
V_193 -> V_205 -- ;
F_22 ( V_191 -> V_141 == V_193 -> V_205 ) ;
V_191 -> V_141 = V_206 ;
F_22 ( F_112 ( V_191 ) ) ;
F_22 ( V_191 -> V_193 == V_193 ) ;
V_191 -> V_193 = NULL ;
V_191 -> V_209 = NULL ;
F_124 ( V_191 ) ;
}
static bool F_130 ( enum V_210 type )
{
switch ( type ) {
case V_211 :
case V_212 :
case V_213 :
return true ;
default:
return false ;
}
}
static void F_131 ( struct V_190 * V_191 )
{
struct V_214 * V_215 = V_191 -> V_215 ;
F_30 ( L_22 , V_66 , V_191 , V_215 ) ;
if ( F_112 ( V_191 ) ) {
F_132 ( V_191 -> V_209 != V_216 ) ;
F_125 ( V_191 -> V_193 ) ;
}
F_133 ( V_215 -> V_217 , V_215 , false ) ;
}
static void F_134 ( struct V_190 * V_191 )
{
F_30 ( L_23 , V_66 , V_191 ) ;
F_135 ( V_191 -> V_215 ) ;
}
static int F_136 ( struct V_190 * V_191 ,
unsigned long V_218 )
{
long V_50 ;
F_30 ( L_23 , V_66 , V_191 ) ;
V_50 = F_137 (
& V_191 -> V_219 ,
F_138 ( V_218 ) ) ;
if ( V_50 <= 0 ) {
if ( V_50 == 0 )
V_50 = - V_220 ;
F_134 ( V_191 ) ;
} else {
V_50 = 0 ;
}
F_30 ( L_24 , V_66 , V_191 , ( int ) V_50 ) ;
return V_50 ;
}
static int F_139 ( struct V_190 * V_191 )
{
return F_136 ( V_191 , 0 ) ;
}
static void F_140 ( struct V_202 * V_193 )
{
F_30 ( L_25 , V_66 , V_193 ) ;
if ( ! V_193 -> V_221 ) {
struct V_190 * V_191 ;
V_117 V_222 = 0 ;
F_141 (img_request, obj_request)
V_222 += V_191 -> V_222 ;
V_193 -> V_222 = V_222 ;
}
if ( V_193 -> V_209 )
V_193 -> V_209 ( V_193 ) ;
else
F_126 ( V_193 ) ;
}
static void F_142 ( struct V_202 * V_193 )
{
F_117 ( V_223 , & V_193 -> V_43 ) ;
F_113 () ;
}
static bool F_143 ( struct V_202 * V_193 )
{
F_113 () ;
return F_18 ( V_223 , & V_193 -> V_43 ) != 0 ;
}
static void F_144 ( struct V_202 * V_193 )
{
F_117 ( V_224 , & V_193 -> V_43 ) ;
F_113 () ;
}
static bool F_145 ( struct V_202 * V_193 )
{
F_113 () ;
return F_18 ( V_224 , & V_193 -> V_43 ) != 0 ;
}
static void F_146 ( struct V_202 * V_193 )
{
F_117 ( V_225 , & V_193 -> V_43 ) ;
F_113 () ;
}
static void F_147 ( struct V_202 * V_193 )
{
F_148 ( V_225 , & V_193 -> V_43 ) ;
F_113 () ;
}
static bool F_127 ( struct V_202 * V_193 )
{
F_113 () ;
return F_18 ( V_225 , & V_193 -> V_43 ) != 0 ;
}
static void F_149 ( struct V_202 * V_193 )
{
F_117 ( V_226 , & V_193 -> V_43 ) ;
F_113 () ;
}
static void F_150 ( struct V_202 * V_193 )
{
F_148 ( V_226 , & V_193 -> V_43 ) ;
F_113 () ;
}
static bool F_151 ( struct V_202 * V_193 )
{
F_113 () ;
return F_18 ( V_226 , & V_193 -> V_43 ) != 0 ;
}
static enum V_97
F_152 ( struct V_202 * V_193 )
{
if ( F_143 ( V_193 ) )
return V_100 ;
else if ( F_145 ( V_193 ) )
return V_101 ;
else
return V_99 ;
}
static void
F_153 ( struct V_190 * V_191 )
{
V_117 V_222 = V_191 -> V_222 ;
V_117 V_160 = V_191 -> V_160 ;
F_30 ( L_26 , V_66 ,
V_191 , V_191 -> V_193 , V_191 -> V_221 ,
V_222 , V_160 ) ;
F_22 ( V_191 -> type != V_211 ) ;
if ( V_191 -> V_221 == - V_45 ) {
if ( V_191 -> type == V_212 )
F_93 ( V_191 -> V_227 , 0 ) ;
else
F_99 ( V_191 -> V_177 , 0 , V_160 ) ;
V_191 -> V_221 = 0 ;
} else if ( V_222 < V_160 && ! V_191 -> V_221 ) {
if ( V_191 -> type == V_212 )
F_93 ( V_191 -> V_227 , V_222 ) ;
else
F_99 ( V_191 -> V_177 , V_222 , V_160 ) ;
}
V_191 -> V_222 = V_160 ;
F_114 ( V_191 ) ;
}
static void F_154 ( struct V_190 * V_191 )
{
F_30 ( L_27 , V_66 , V_191 ,
V_191 -> V_209 ) ;
if ( V_191 -> V_209 )
V_191 -> V_209 ( V_191 ) ;
else
F_155 ( & V_191 -> V_219 ) ;
}
static void F_156 ( struct V_190 * V_191 , int V_228 )
{
V_191 -> V_221 = V_228 ;
V_191 -> V_222 = 0 ;
if ( F_112 ( V_191 ) ) {
F_132 ( V_191 -> V_209 != V_216 ) ;
F_125 ( V_191 -> V_193 ) ;
}
F_114 ( V_191 ) ;
F_154 ( V_191 ) ;
}
static void F_157 ( struct V_190 * V_191 )
{
struct V_202 * V_193 = NULL ;
struct V_8 * V_9 = NULL ;
bool V_229 = false ;
if ( F_112 ( V_191 ) ) {
V_193 = V_191 -> V_193 ;
V_229 = V_193 && F_151 ( V_193 ) ;
V_9 = V_193 -> V_9 ;
}
F_30 ( L_26 , V_66 ,
V_191 , V_193 , V_191 -> V_221 ,
V_191 -> V_222 , V_191 -> V_160 ) ;
if ( V_229 && V_191 -> V_221 == - V_45 &&
V_191 -> V_198 < V_9 -> V_199 )
F_158 ( V_191 ) ;
else if ( V_193 )
F_153 ( V_191 ) ;
else
F_114 ( V_191 ) ;
}
static void F_159 ( struct V_190 * V_191 )
{
F_30 ( L_28 , V_66 , V_191 ,
V_191 -> V_221 , V_191 -> V_160 ) ;
V_191 -> V_222 = V_191 -> V_160 ;
F_114 ( V_191 ) ;
}
static void F_160 ( struct V_190 * V_191 )
{
F_30 ( L_28 , V_66 , V_191 ,
V_191 -> V_221 , V_191 -> V_160 ) ;
V_191 -> V_222 = V_191 -> V_160 ;
if ( V_191 -> V_221 == - V_45 )
V_191 -> V_221 = 0 ;
F_114 ( V_191 ) ;
}
static void F_161 ( struct V_190 * V_191 )
{
F_30 ( L_29 , V_66 , V_191 ) ;
F_114 ( V_191 ) ;
}
static void F_162 ( struct V_190 * V_191 )
{
F_30 ( L_29 , V_66 , V_191 ) ;
if ( F_112 ( V_191 ) )
F_163 ( V_191 ) ;
else
F_114 ( V_191 ) ;
}
static void F_164 ( struct V_214 * V_215 )
{
struct V_190 * V_191 = V_215 -> V_230 ;
T_8 V_231 ;
F_30 ( L_30 , V_66 , V_215 ) ;
F_22 ( V_215 == V_191 -> V_215 ) ;
if ( F_112 ( V_191 ) ) {
F_22 ( V_191 -> V_193 ) ;
F_22 ( V_191 -> V_141 != V_206 ) ;
} else {
F_22 ( V_191 -> V_141 == V_206 ) ;
}
if ( V_215 -> V_232 < 0 )
V_191 -> V_221 = V_215 -> V_232 ;
V_191 -> V_222 = V_215 -> V_233 [ 0 ] . V_234 ;
F_22 ( V_191 -> V_222 < ( V_117 ) V_235 ) ;
V_231 = V_215 -> V_233 [ 0 ] . V_236 ;
switch ( V_231 ) {
case V_237 :
F_157 ( V_191 ) ;
break;
case V_238 :
F_22 ( V_215 -> V_233 [ 1 ] . V_236 == V_239 ||
V_215 -> V_233 [ 1 ] . V_236 == V_240 ) ;
case V_239 :
case V_240 :
F_159 ( V_191 ) ;
break;
case V_241 :
F_161 ( V_191 ) ;
break;
case V_242 :
case V_243 :
case V_244 :
F_160 ( V_191 ) ;
break;
case V_245 :
F_162 ( V_191 ) ;
break;
default:
F_109 ( NULL , L_31 ,
V_191 -> V_246 , ( unsigned short ) V_231 ) ;
break;
}
if ( F_115 ( V_191 ) )
F_154 ( V_191 ) ;
}
static void F_165 ( struct V_190 * V_191 )
{
struct V_214 * V_215 = V_191 -> V_215 ;
F_22 ( F_112 ( V_191 ) ) ;
V_215 -> V_247 = V_191 -> V_193 -> V_14 ;
}
static void F_166 ( struct V_190 * V_191 )
{
struct V_214 * V_215 = V_191 -> V_215 ;
V_215 -> V_248 = V_249 ;
V_215 -> V_250 = V_191 -> V_154 ;
}
static struct V_214 * F_167 (
struct V_8 * V_9 ,
enum V_97 V_98 ,
unsigned int V_251 ,
struct V_190 * V_191 )
{
struct V_115 * V_122 = NULL ;
struct V_252 * V_253 ;
struct V_214 * V_215 ;
if ( F_112 ( V_191 ) &&
( V_98 == V_101 || V_98 == V_100 ) ) {
struct V_202 * V_193 = V_191 -> V_193 ;
if ( V_98 == V_100 ) {
F_22 ( F_143 ( V_193 ) ) ;
} else {
F_22 ( F_145 ( V_193 ) ) ;
}
V_122 = V_193 -> V_122 ;
}
F_22 ( V_251 == 1 || ( ( V_98 == V_100 ) && V_251 == 2 ) ) ;
V_253 = & V_9 -> V_61 -> V_71 -> V_253 ;
V_215 = F_168 ( V_253 , V_122 , V_251 , false ,
V_157 ) ;
if ( ! V_215 )
goto V_254;
if ( V_98 == V_100 || V_98 == V_101 )
V_215 -> V_255 = V_256 | V_257 ;
else
V_215 -> V_255 = V_258 ;
V_215 -> V_259 = F_164 ;
V_215 -> V_230 = V_191 ;
V_215 -> V_260 . V_261 = V_9 -> V_262 . V_263 ;
if ( F_169 ( & V_215 -> V_264 , V_157 , L_32 ,
V_191 -> V_246 ) )
goto V_254;
if ( F_170 ( V_215 , V_157 ) )
goto V_254;
return V_215 ;
V_254:
F_171 ( V_215 ) ;
return NULL ;
}
static struct V_214 *
F_172 ( struct V_190 * V_191 )
{
struct V_202 * V_193 ;
struct V_115 * V_122 ;
struct V_8 * V_9 ;
struct V_252 * V_253 ;
struct V_214 * V_215 ;
int V_265 = 3 ;
F_22 ( F_112 ( V_191 ) ) ;
V_193 = V_191 -> V_193 ;
F_22 ( V_193 ) ;
F_22 ( F_143 ( V_193 ) ||
F_145 ( V_193 ) ) ;
if ( F_145 ( V_193 ) )
V_265 = 2 ;
V_122 = V_193 -> V_122 ;
V_9 = V_193 -> V_9 ;
V_253 = & V_9 -> V_61 -> V_71 -> V_253 ;
V_215 = F_168 ( V_253 , V_122 , V_265 ,
false , V_157 ) ;
if ( ! V_215 )
goto V_254;
V_215 -> V_255 = V_256 | V_257 ;
V_215 -> V_259 = F_164 ;
V_215 -> V_230 = V_191 ;
V_215 -> V_260 . V_261 = V_9 -> V_262 . V_263 ;
if ( F_169 ( & V_215 -> V_264 , V_157 , L_32 ,
V_191 -> V_246 ) )
goto V_254;
if ( F_170 ( V_215 , V_157 ) )
goto V_254;
return V_215 ;
V_254:
F_171 ( V_215 ) ;
return NULL ;
}
static void F_173 ( struct V_214 * V_215 )
{
F_171 ( V_215 ) ;
}
static struct V_190 * F_174 ( const char * V_246 ,
V_117 V_154 , V_117 V_160 ,
enum V_210 type )
{
struct V_190 * V_191 ;
T_6 V_107 ;
char * V_152 ;
F_22 ( F_130 ( type ) ) ;
V_107 = strlen ( V_246 ) + 1 ;
V_152 = F_31 ( V_107 , V_157 ) ;
if ( ! V_152 )
return NULL ;
V_191 = F_175 ( V_266 , V_157 ) ;
if ( ! V_191 ) {
F_41 ( V_152 ) ;
return NULL ;
}
V_191 -> V_246 = memcpy ( V_152 , V_246 , V_107 ) ;
V_191 -> V_154 = V_154 ;
V_191 -> V_160 = V_160 ;
V_191 -> V_43 = 0 ;
V_191 -> V_141 = V_206 ;
V_191 -> type = type ;
F_33 ( & V_191 -> V_207 ) ;
F_176 ( & V_191 -> V_219 ) ;
F_32 ( & V_191 -> V_69 ) ;
F_30 ( L_33 , V_66 , V_246 ,
V_154 , V_160 , ( int ) type , V_191 ) ;
return V_191 ;
}
static void V_201 ( struct V_69 * V_69 )
{
struct V_190 * V_191 ;
V_191 = F_58 ( V_69 , struct V_190 , V_69 ) ;
F_30 ( L_29 , V_66 , V_191 ) ;
F_22 ( V_191 -> V_193 == NULL ) ;
F_22 ( V_191 -> V_141 == V_206 ) ;
if ( V_191 -> V_215 )
F_173 ( V_191 -> V_215 ) ;
F_22 ( F_130 ( V_191 -> type ) ) ;
switch ( V_191 -> type ) {
case V_211 :
break;
case V_212 :
if ( V_191 -> V_227 )
F_91 ( V_191 -> V_227 ) ;
break;
case V_213 :
if ( V_191 -> V_177 &&
! F_112 ( V_191 ) )
F_177 ( V_191 -> V_177 ,
V_191 -> V_267 ) ;
break;
}
F_41 ( V_191 -> V_246 ) ;
V_191 -> V_246 = NULL ;
F_85 ( V_266 , V_191 ) ;
}
static void F_178 ( struct V_8 * V_9 )
{
F_179 ( V_9 ) ;
F_180 ( V_9 -> V_268 ) ;
V_9 -> V_268 = NULL ;
V_9 -> V_199 = 0 ;
}
static void F_181 ( struct V_8 * V_9 )
{
int V_2 ;
if ( ! V_9 -> V_268 )
return;
V_2 = F_4 ( & V_9 -> V_269 ) ;
if ( V_2 > 0 )
return;
if ( ! V_2 )
F_178 ( V_9 ) ;
else
F_109 ( V_9 , L_34 ) ;
}
static bool F_182 ( struct V_8 * V_9 )
{
int V_2 = 0 ;
if ( ! V_9 -> V_268 )
return false ;
F_12 ( & V_9 -> V_270 ) ;
if ( V_9 -> V_199 )
V_2 = F_1 ( & V_9 -> V_269 ) ;
F_13 ( & V_9 -> V_270 ) ;
if ( V_2 < 0 )
F_109 ( V_9 , L_35 ) ;
return V_2 > 0 ;
}
static struct V_202 * F_183 (
struct V_8 * V_9 ,
V_117 V_154 , V_117 V_160 ,
enum V_97 V_98 ,
struct V_115 * V_122 )
{
struct V_202 * V_193 ;
V_193 = F_87 ( V_271 , V_157 ) ;
if ( ! V_193 )
return NULL ;
V_193 -> V_272 = NULL ;
V_193 -> V_9 = V_9 ;
V_193 -> V_154 = V_154 ;
V_193 -> V_160 = V_160 ;
V_193 -> V_43 = 0 ;
if ( V_98 == V_101 ) {
F_144 ( V_193 ) ;
V_193 -> V_122 = V_122 ;
} else if ( V_98 == V_100 ) {
F_142 ( V_193 ) ;
V_193 -> V_122 = V_122 ;
} else {
V_193 -> V_14 = V_9 -> V_13 -> V_14 ;
}
if ( F_182 ( V_9 ) )
F_149 ( V_193 ) ;
F_184 ( & V_193 -> V_273 ) ;
V_193 -> V_274 = 0 ;
V_193 -> V_209 = NULL ;
V_193 -> V_221 = 0 ;
V_193 -> V_205 = 0 ;
F_33 ( & V_193 -> V_208 ) ;
F_32 ( & V_193 -> V_69 ) ;
F_30 ( L_36 , V_66 , V_9 ,
F_53 ( V_98 ) , V_154 , V_160 , V_193 ) ;
return V_193 ;
}
static void V_204 ( struct V_69 * V_69 )
{
struct V_202 * V_193 ;
struct V_190 * V_191 ;
struct V_190 * V_275 ;
V_193 = F_58 ( V_69 , struct V_202 , V_69 ) ;
F_30 ( L_25 , V_66 , V_193 ) ;
F_185 (img_request, obj_request, next_obj_request)
F_129 ( V_193 , V_191 ) ;
F_22 ( V_193 -> V_205 == 0 ) ;
if ( F_151 ( V_193 ) ) {
F_150 ( V_193 ) ;
F_181 ( V_193 -> V_9 ) ;
}
if ( F_143 ( V_193 ) ||
F_145 ( V_193 ) )
F_70 ( V_193 -> V_122 ) ;
F_85 ( V_271 , V_193 ) ;
}
static struct V_202 * F_186 (
struct V_190 * V_191 ,
V_117 V_198 , V_117 V_160 )
{
struct V_202 * V_276 ;
struct V_8 * V_9 ;
F_22 ( V_191 -> V_193 ) ;
V_9 = V_191 -> V_193 -> V_9 ;
V_276 = F_183 ( V_9 -> V_277 , V_198 ,
V_160 , V_99 , NULL ) ;
if ( ! V_276 )
return NULL ;
F_146 ( V_276 ) ;
F_122 ( V_191 ) ;
V_276 -> V_191 = V_191 ;
return V_276 ;
}
static void V_203 ( struct V_69 * V_69 )
{
struct V_202 * V_276 ;
struct V_190 * V_278 ;
V_276 = F_58 ( V_69 , struct V_202 , V_69 ) ;
V_278 = V_276 -> V_191 ;
V_276 -> V_191 = NULL ;
F_124 ( V_278 ) ;
F_147 ( V_276 ) ;
V_204 ( V_69 ) ;
}
static bool F_187 ( struct V_190 * V_191 )
{
struct V_202 * V_193 ;
unsigned int V_222 ;
int V_221 ;
bool V_279 ;
F_22 ( F_112 ( V_191 ) ) ;
V_193 = V_191 -> V_193 ;
F_22 ( V_191 -> V_222 <= ( V_117 ) V_235 ) ;
V_222 = ( unsigned int ) V_191 -> V_222 ;
V_221 = V_191 -> V_221 ;
if ( V_221 ) {
struct V_8 * V_9 = V_193 -> V_9 ;
enum V_97 V_98 ;
if ( F_145 ( V_193 ) )
V_98 = V_101 ;
else if ( F_143 ( V_193 ) )
V_98 = V_100 ;
else
V_98 = V_99 ;
F_109 ( V_9 , L_37 ,
F_53 ( V_98 ) , V_191 -> V_160 ,
V_191 -> V_198 , V_191 -> V_154 ) ;
F_109 ( V_9 , L_38 ,
V_221 , V_222 ) ;
if ( ! V_193 -> V_221 )
V_193 -> V_221 = V_221 ;
V_222 = V_191 -> V_160 ;
}
if ( F_127 ( V_193 ) ) {
F_22 ( V_193 -> V_191 != NULL ) ;
V_279 = V_191 -> V_141 < V_193 -> V_205 - 1 ;
} else {
F_22 ( V_193 -> V_272 != NULL ) ;
V_279 = F_188 ( V_193 -> V_272 , V_221 , V_222 ) ;
if ( ! V_279 )
F_189 ( V_193 -> V_272 , V_221 ) ;
}
return V_279 ;
}
static void V_216 ( struct V_190 * V_191 )
{
struct V_202 * V_193 ;
T_5 V_141 = V_191 -> V_141 ;
bool V_279 = true ;
F_22 ( F_112 ( V_191 ) ) ;
V_193 = V_191 -> V_193 ;
F_30 ( L_39 , V_66 , V_193 , V_191 ) ;
F_22 ( V_193 != NULL ) ;
F_22 ( V_193 -> V_205 > 0 ) ;
F_22 ( V_141 != V_206 ) ;
F_22 ( V_141 < V_193 -> V_205 ) ;
F_17 ( & V_193 -> V_273 ) ;
if ( V_141 != V_193 -> V_274 )
goto V_57;
F_190 (img_request, obj_request) {
F_22 ( V_279 ) ;
F_22 ( V_141 < V_193 -> V_205 ) ;
if ( ! F_115 ( V_191 ) )
break;
V_279 = F_187 ( V_191 ) ;
V_141 ++ ;
}
F_22 ( V_279 ^ ( V_141 == V_193 -> V_205 ) ) ;
V_193 -> V_274 = V_141 ;
V_57:
F_19 ( & V_193 -> V_273 ) ;
F_126 ( V_193 ) ;
if ( ! V_279 )
F_140 ( V_193 ) ;
}
static void F_191 ( struct V_190 * V_191 ,
struct V_214 * V_280 ,
enum V_97 V_98 ,
unsigned int V_251 )
{
struct V_202 * V_193 = V_191 -> V_193 ;
struct V_8 * V_9 = V_193 -> V_9 ;
V_117 V_281 = F_90 ( & V_9 -> V_10 ) ;
V_117 V_154 = V_191 -> V_154 ;
V_117 V_160 = V_191 -> V_160 ;
V_117 V_282 ;
T_8 V_231 ;
if ( V_98 == V_101 ) {
if ( ! V_154 && V_160 == V_281 &&
( ! F_151 ( V_193 ) ||
! F_120 ( V_191 ) ) ) {
V_231 = V_242 ;
} else if ( ( V_154 + V_160 == V_281 ) ) {
V_231 = V_243 ;
} else {
F_12 ( & V_9 -> V_270 ) ;
V_282 = V_9 -> V_10 . V_134 ;
F_13 ( & V_9 -> V_270 ) ;
if ( V_191 -> V_198 + V_160 == V_282 )
V_231 = V_243 ;
else
V_231 = V_244 ;
}
} else if ( V_98 == V_100 ) {
if ( ! V_154 && V_160 == V_281 )
V_231 = V_240 ;
else
V_231 = V_239 ;
F_192 ( V_280 , V_251 ,
V_281 , V_281 ) ;
V_251 ++ ;
} else {
V_231 = V_237 ;
}
if ( V_231 == V_242 )
F_193 ( V_280 , V_251 , V_231 , 0 ) ;
else
F_194 ( V_280 , V_251 , V_231 ,
V_154 , V_160 , 0 , 0 ) ;
if ( V_191 -> type == V_212 )
F_195 ( V_280 , V_251 ,
V_191 -> V_227 , V_160 ) ;
else if ( V_191 -> type == V_213 )
F_196 ( V_280 , V_251 ,
V_191 -> V_177 , V_160 ,
V_154 & ~ V_182 , false , false ) ;
if ( V_98 == V_100 || V_98 == V_101 )
F_166 ( V_191 ) ;
else
F_165 ( V_191 ) ;
}
static int F_197 ( struct V_202 * V_193 ,
enum V_210 type ,
void * V_283 )
{
struct V_8 * V_9 = V_193 -> V_9 ;
struct V_190 * V_191 = NULL ;
struct V_190 * V_275 ;
struct V_162 * V_227 = NULL ;
unsigned int V_284 = 0 ;
struct V_176 * * V_177 = NULL ;
enum V_97 V_98 ;
V_117 V_198 ;
V_117 V_285 ;
F_30 ( L_40 , V_66 , V_193 ,
( int ) type , V_283 ) ;
V_198 = V_193 -> V_154 ;
V_285 = V_193 -> V_160 ;
F_22 ( V_285 > 0 ) ;
V_98 = F_152 ( V_193 ) ;
if ( type == V_212 ) {
V_227 = V_283 ;
F_22 ( V_198 ==
V_227 -> V_186 . V_286 << V_113 ) ;
} else if ( type == V_213 ) {
V_177 = V_283 ;
}
while ( V_285 ) {
struct V_214 * V_215 ;
const char * V_246 ;
V_117 V_154 ;
V_117 V_160 ;
V_246 = F_86 ( V_9 , V_198 ) ;
if ( ! V_246 )
goto V_287;
V_154 = F_88 ( V_9 , V_198 ) ;
V_160 = F_89 ( V_9 , V_198 , V_285 ) ;
V_191 = F_174 ( V_246 ,
V_154 , V_160 , type ) ;
F_84 ( V_246 ) ;
if ( ! V_191 )
goto V_287;
F_128 ( V_193 , V_191 ) ;
if ( type == V_212 ) {
unsigned int V_288 ;
F_22 ( V_160 <= ( V_117 ) V_235 ) ;
V_288 = ( unsigned int ) V_160 ;
V_191 -> V_227 =
F_108 ( & V_227 ,
& V_284 ,
V_288 ,
V_157 ) ;
if ( ! V_191 -> V_227 )
goto V_287;
} else if ( type == V_213 ) {
unsigned int V_267 ;
V_191 -> V_177 = V_177 ;
V_267 = ( T_5 ) F_198 ( V_154 , V_160 ) ;
V_191 -> V_267 = V_267 ;
if ( ( V_154 + V_160 ) & ~ V_182 )
V_267 -- ;
V_177 += V_267 ;
}
V_215 = F_167 ( V_9 , V_98 ,
( V_98 == V_100 ) ? 2 : 1 ,
V_191 ) ;
if ( ! V_215 )
goto V_287;
V_191 -> V_215 = V_215 ;
V_191 -> V_209 = V_216 ;
V_191 -> V_198 = V_198 ;
F_191 ( V_191 , V_215 , V_98 , 0 ) ;
V_198 += V_160 ;
V_285 -= V_160 ;
}
return 0 ;
V_287:
F_185 (img_request, obj_request, next_obj_request)
F_129 ( V_193 , V_191 ) ;
return - V_65 ;
}
static void
F_163 ( struct V_190 * V_191 )
{
struct V_202 * V_193 ;
struct V_8 * V_9 ;
struct V_176 * * V_177 ;
T_5 V_267 ;
F_30 ( L_29 , V_66 , V_191 ) ;
F_22 ( V_191 -> type == V_212 ||
V_191 -> type == V_211 ) ;
F_22 ( F_112 ( V_191 ) ) ;
V_193 = V_191 -> V_193 ;
F_22 ( V_193 ) ;
V_9 = V_193 -> V_9 ;
F_22 ( V_9 ) ;
V_177 = V_191 -> V_289 ;
F_22 ( V_177 != NULL ) ;
V_191 -> V_289 = NULL ;
V_267 = V_191 -> V_290 ;
F_22 ( V_267 ) ;
V_191 -> V_290 = 0 ;
F_177 ( V_177 , V_267 ) ;
if ( ! V_191 -> V_221 )
V_191 -> V_222 = V_191 -> V_160 ;
F_114 ( V_191 ) ;
}
static void
F_199 ( struct V_202 * V_193 )
{
struct V_190 * V_278 ;
struct V_214 * V_215 ;
struct V_8 * V_9 ;
struct V_176 * * V_177 ;
enum V_97 V_98 ;
T_5 V_267 ;
int V_291 ;
V_117 V_292 ;
F_22 ( F_127 ( V_193 ) ) ;
V_177 = V_193 -> V_289 ;
F_22 ( V_177 != NULL ) ;
V_193 -> V_289 = NULL ;
V_267 = V_193 -> V_290 ;
F_22 ( V_267 ) ;
V_193 -> V_290 = 0 ;
V_278 = V_193 -> V_191 ;
F_22 ( V_278 != NULL ) ;
F_22 ( F_130 ( V_278 -> type ) ) ;
V_291 = V_193 -> V_221 ;
V_292 = V_193 -> V_160 ;
F_22 ( V_291 || V_292 == V_193 -> V_222 ) ;
F_126 ( V_193 ) ;
F_22 ( V_278 -> V_193 ) ;
V_9 = V_278 -> V_193 -> V_9 ;
F_22 ( V_9 ) ;
if ( ! V_9 -> V_199 ) {
F_177 ( V_177 , V_267 ) ;
F_131 ( V_278 ) ;
return;
}
if ( V_291 )
goto V_127;
V_291 = - V_65 ;
V_215 = F_172 ( V_278 ) ;
if ( ! V_215 )
goto V_127;
F_173 ( V_278 -> V_215 ) ;
V_278 -> V_215 = V_215 ;
V_278 -> V_289 = V_177 ;
V_278 -> V_290 = V_267 ;
F_200 ( V_215 , 0 , V_245 , L_41 , L_42 ) ;
F_201 ( V_215 , 0 , V_177 , V_292 , 0 ,
false , false ) ;
V_98 = F_152 ( V_278 -> V_193 ) ;
F_191 ( V_278 , V_215 , V_98 , 1 ) ;
F_131 ( V_278 ) ;
return;
V_127:
F_177 ( V_177 , V_267 ) ;
F_156 ( V_278 , V_291 ) ;
}
static int F_202 ( struct V_190 * V_191 )
{
struct V_8 * V_9 = V_191 -> V_193 -> V_9 ;
struct V_202 * V_276 = NULL ;
V_117 V_198 ;
V_117 V_160 ;
struct V_176 * * V_177 = NULL ;
T_5 V_267 ;
int V_221 ;
F_22 ( V_9 -> V_277 != NULL ) ;
V_198 = V_191 -> V_198 - V_191 -> V_154 ;
V_160 = ( V_117 ) 1 << V_9 -> V_10 . V_135 ;
if ( V_198 + V_160 > V_9 -> V_199 ) {
F_22 ( V_198 < V_9 -> V_199 ) ;
V_160 = V_9 -> V_199 - V_198 ;
}
V_267 = ( T_5 ) F_198 ( 0 , V_160 ) ;
V_177 = F_203 ( V_267 , V_67 ) ;
if ( F_35 ( V_177 ) ) {
V_221 = F_204 ( V_177 ) ;
V_177 = NULL ;
goto V_127;
}
V_221 = - V_65 ;
V_276 = F_186 ( V_191 ,
V_198 , V_160 ) ;
if ( ! V_276 )
goto V_127;
V_221 = F_197 ( V_276 , V_213 , V_177 ) ;
if ( V_221 )
goto V_127;
V_276 -> V_289 = V_177 ;
V_276 -> V_290 = V_267 ;
V_276 -> V_209 = F_199 ;
V_221 = F_205 ( V_276 ) ;
if ( ! V_221 )
return 0 ;
V_276 -> V_289 = NULL ;
V_276 -> V_290 = 0 ;
V_276 -> V_191 = NULL ;
F_124 ( V_191 ) ;
V_127:
if ( V_177 )
F_177 ( V_177 , V_267 ) ;
if ( V_276 )
F_126 ( V_276 ) ;
return V_221 ;
}
static void F_206 ( struct V_190 * V_191 )
{
struct V_190 * V_278 ;
struct V_8 * V_9 ;
int V_221 ;
F_22 ( ! F_112 ( V_191 ) ) ;
V_278 = V_191 -> V_191 ;
V_191 -> V_191 = NULL ;
F_124 ( V_278 ) ;
F_22 ( V_278 ) ;
F_22 ( V_278 -> V_193 ) ;
V_221 = V_191 -> V_221 ;
V_191 -> V_221 = 0 ;
F_30 ( L_43 , V_66 ,
V_191 , V_278 , V_221 ,
V_191 -> V_222 , V_191 -> V_160 ) ;
F_124 ( V_191 ) ;
V_9 = V_278 -> V_193 -> V_9 ;
if ( ! V_9 -> V_199 ) {
F_131 ( V_278 ) ;
return;
}
if ( ! V_221 ) {
F_116 ( V_278 , true ) ;
} else if ( V_221 == - V_45 ) {
F_116 ( V_278 , false ) ;
} else {
goto V_293;
}
V_221 = F_207 ( V_278 ) ;
if ( V_221 )
goto V_293;
return;
V_293:
F_156 ( V_278 , V_221 ) ;
}
static int F_208 ( struct V_190 * V_191 )
{
struct V_8 * V_9 = V_191 -> V_193 -> V_9 ;
struct V_190 * V_294 ;
struct V_176 * * V_177 ;
T_5 V_267 ;
T_6 V_107 ;
int V_50 ;
V_294 = F_174 ( V_191 -> V_246 , 0 , 0 ,
V_213 ) ;
if ( ! V_294 )
return - V_65 ;
V_294 -> V_215 = F_167 ( V_9 , V_99 , 1 ,
V_294 ) ;
if ( ! V_294 -> V_215 ) {
V_50 = - V_65 ;
goto V_295;
}
V_107 = sizeof ( V_116 ) + sizeof ( V_296 ) + sizeof ( V_296 ) ;
V_267 = ( T_5 ) F_198 ( 0 , V_107 ) ;
V_177 = F_203 ( V_267 , V_67 ) ;
if ( F_35 ( V_177 ) ) {
V_50 = F_204 ( V_177 ) ;
goto V_295;
}
F_193 ( V_294 -> V_215 , 0 , V_241 , 0 ) ;
F_209 ( V_294 -> V_215 , 0 , V_177 , V_107 , 0 ,
false , false ) ;
F_122 ( V_191 ) ;
V_294 -> V_191 = V_191 ;
V_294 -> V_177 = V_177 ;
V_294 -> V_267 = V_267 ;
V_294 -> V_209 = F_206 ;
F_131 ( V_294 ) ;
return 0 ;
V_295:
F_124 ( V_294 ) ;
return V_50 ;
}
static bool F_210 ( struct V_190 * V_191 )
{
struct V_202 * V_193 = V_191 -> V_193 ;
struct V_8 * V_9 = V_193 -> V_9 ;
if ( ! F_143 ( V_193 ) &&
! F_145 ( V_193 ) )
return true ;
if ( ! F_151 ( V_193 ) )
return true ;
if ( ! F_120 ( V_191 ) )
return true ;
if ( ! V_191 -> V_154 &&
V_191 -> V_160 == F_90 ( & V_9 -> V_10 ) )
return true ;
if ( F_118 ( V_191 ) &&
F_119 ( V_191 ) )
return true ;
return false ;
}
static int F_207 ( struct V_190 * V_191 )
{
F_22 ( F_112 ( V_191 ) ) ;
F_22 ( F_130 ( V_191 -> type ) ) ;
F_22 ( V_191 -> V_193 ) ;
if ( F_210 ( V_191 ) ) {
F_131 ( V_191 ) ;
return 0 ;
}
if ( F_118 ( V_191 ) )
return F_202 ( V_191 ) ;
return F_208 ( V_191 ) ;
}
static int F_205 ( struct V_202 * V_193 )
{
struct V_190 * V_191 ;
struct V_190 * V_275 ;
int V_50 = 0 ;
F_30 ( L_25 , V_66 , V_193 ) ;
F_125 ( V_193 ) ;
F_185 (img_request, obj_request, next_obj_request) {
V_50 = F_207 ( V_191 ) ;
if ( V_50 )
goto V_297;
}
V_297:
F_126 ( V_193 ) ;
return V_50 ;
}
static void F_211 ( struct V_202 * V_193 )
{
struct V_190 * V_191 ;
struct V_8 * V_9 ;
V_117 V_298 ;
V_117 V_299 ;
int V_291 ;
F_22 ( F_127 ( V_193 ) ) ;
V_191 = V_193 -> V_191 ;
V_299 = V_193 -> V_222 ;
V_291 = V_193 -> V_221 ;
F_126 ( V_193 ) ;
F_22 ( V_191 ) ;
F_22 ( V_191 -> V_193 ) ;
V_9 = V_191 -> V_193 -> V_9 ;
if ( ! V_9 -> V_199 ) {
F_131 ( V_191 ) ;
return;
}
V_191 -> V_221 = V_291 ;
if ( V_191 -> V_221 )
goto V_57;
F_22 ( V_191 -> V_198 < V_161 - V_191 -> V_160 ) ;
V_298 = V_191 -> V_198 + V_191 -> V_160 ;
if ( V_298 > V_9 -> V_199 ) {
V_117 V_222 = 0 ;
if ( V_191 -> V_198 < V_9 -> V_199 )
V_222 = V_9 -> V_199 -
V_191 -> V_198 ;
V_191 -> V_222 = F_212 ( V_299 , V_222 ) ;
} else {
V_191 -> V_222 = V_299 ;
}
V_57:
F_153 ( V_191 ) ;
F_154 ( V_191 ) ;
}
static void F_158 ( struct V_190 * V_191 )
{
struct V_202 * V_193 ;
int V_221 ;
F_22 ( F_112 ( V_191 ) ) ;
F_22 ( V_191 -> V_193 != NULL ) ;
F_22 ( V_191 -> V_221 == ( V_300 ) - V_45 ) ;
F_22 ( F_130 ( V_191 -> type ) ) ;
V_193 = F_186 ( V_191 ,
V_191 -> V_198 ,
V_191 -> V_160 ) ;
V_221 = - V_65 ;
if ( ! V_193 )
goto V_127;
if ( V_191 -> type == V_212 )
V_221 = F_197 ( V_193 , V_212 ,
V_191 -> V_227 ) ;
else
V_221 = F_197 ( V_193 , V_213 ,
V_191 -> V_177 ) ;
if ( V_221 )
goto V_127;
V_193 -> V_209 = F_211 ;
V_221 = F_205 ( V_193 ) ;
if ( V_221 )
goto V_127;
return;
V_127:
if ( V_193 )
F_126 ( V_193 ) ;
V_191 -> V_221 = V_221 ;
V_191 -> V_222 = 0 ;
F_114 ( V_191 ) ;
}
static bool F_213 ( const struct V_301 * V_302 ,
const struct V_301 * V_303 )
{
return V_302 -> V_304 == V_303 -> V_304 && V_302 -> V_305 == V_303 -> V_305 ;
}
static struct V_301 F_214 ( struct V_8 * V_9 )
{
struct V_301 V_306 ;
F_215 ( & V_9 -> V_307 ) ;
V_306 . V_304 = F_216 ( V_9 -> V_61 -> V_71 ) ;
V_306 . V_305 = V_9 -> V_308 ;
F_56 ( & V_9 -> V_307 ) ;
return V_306 ;
}
static void F_217 ( struct V_8 * V_9 ,
const struct V_301 * V_306 )
{
F_30 ( L_44 , V_66 , V_9 ,
V_9 -> V_309 . V_304 , V_9 -> V_309 . V_305 ,
V_306 -> V_304 , V_306 -> V_305 ) ;
V_9 -> V_309 = * V_306 ;
}
static void F_218 ( struct V_8 * V_9 , char * V_171 )
{
F_215 ( & V_9 -> V_307 ) ;
sprintf ( V_171 , L_45 , V_310 , V_9 -> V_308 ) ;
F_56 ( & V_9 -> V_307 ) ;
}
static int F_219 ( struct V_8 * V_9 )
{
struct V_252 * V_253 = & V_9 -> V_61 -> V_71 -> V_253 ;
struct V_301 V_306 = F_214 ( V_9 ) ;
char V_311 [ 32 ] ;
int V_50 ;
F_132 ( F_10 ( V_9 ) ) ;
F_218 ( V_9 , V_311 ) ;
V_50 = F_220 ( V_253 , & V_9 -> V_312 , & V_9 -> V_313 ,
V_314 , V_315 , V_311 ,
V_316 , L_46 , 0 ) ;
if ( V_50 )
return V_50 ;
V_9 -> V_18 = V_19 ;
F_217 ( V_9 , & V_306 ) ;
F_221 ( V_9 -> V_317 , & V_9 -> V_318 ) ;
return 0 ;
}
static int F_222 ( struct V_8 * V_9 )
{
struct V_252 * V_253 = & V_9 -> V_61 -> V_71 -> V_253 ;
char V_311 [ 32 ] ;
int V_50 ;
F_132 ( ! F_10 ( V_9 ) ) ;
V_9 -> V_18 = V_319 ;
F_218 ( V_9 , V_311 ) ;
V_50 = F_223 ( V_253 , & V_9 -> V_312 , & V_9 -> V_313 ,
V_314 , V_311 ) ;
if ( V_50 && V_50 != - V_45 ) {
F_109 ( V_9 , L_47 , V_50 ) ;
return V_50 ;
}
F_217 ( V_9 , & V_320 ) ;
F_221 ( V_9 -> V_317 , & V_9 -> V_321 ) ;
return 0 ;
}
static int F_224 ( struct V_8 * V_9 ,
enum V_322 V_323 ,
struct V_176 * * * V_324 ,
T_6 * V_325 )
{
struct V_252 * V_253 = & V_9 -> V_61 -> V_71 -> V_253 ;
struct V_301 V_306 = F_214 ( V_9 ) ;
int V_326 = 4 + 8 + 8 + V_327 ;
char V_171 [ V_326 ] ;
void * V_328 = V_171 ;
F_30 ( L_48 , V_66 , V_9 , V_323 ) ;
F_225 ( & V_328 , 2 , 1 , V_326 - V_327 ) ;
F_226 ( & V_328 , V_323 ) ;
F_227 ( & V_328 , V_306 . V_304 ) ;
F_227 ( & V_328 , V_306 . V_305 ) ;
return F_228 ( V_253 , & V_9 -> V_312 ,
& V_9 -> V_313 , V_171 , V_326 ,
V_329 , V_324 , V_325 ) ;
}
static void F_229 ( struct V_8 * V_9 ,
enum V_322 V_323 )
{
struct V_176 * * V_330 ;
T_6 V_331 ;
F_224 ( V_9 , V_323 , & V_330 , & V_331 ) ;
F_177 ( V_330 , F_198 ( 0 , V_331 ) ) ;
}
static void F_230 ( struct V_332 * V_333 )
{
struct V_8 * V_9 = F_58 ( V_333 , struct V_8 ,
V_318 ) ;
F_229 ( V_9 , V_334 ) ;
}
static void F_231 ( struct V_332 * V_333 )
{
struct V_8 * V_9 = F_58 ( V_333 , struct V_8 ,
V_321 ) ;
F_229 ( V_9 , V_335 ) ;
}
static int F_232 ( struct V_8 * V_9 )
{
struct V_176 * * V_330 ;
T_6 V_331 ;
bool V_336 = false ;
int V_50 ;
F_30 ( L_49 , V_66 , V_9 ) ;
V_50 = F_224 ( V_9 , V_337 ,
& V_330 , & V_331 ) ;
if ( V_50 && V_50 != - V_220 ) {
F_109 ( V_9 , L_50 , V_50 ) ;
goto V_57;
}
if ( V_331 > 0 && V_331 <= V_183 ) {
void * V_328 = F_233 ( V_330 [ 0 ] ) ;
void * const V_178 = V_328 + V_331 ;
T_5 V_338 ;
F_234 ( & V_328 , V_178 , V_338 , V_339 ) ;
while ( V_338 -- ) {
T_9 V_340 ;
T_5 V_126 ;
F_235 ( & V_328 , V_178 , 8 + 8 , V_339 ) ;
V_328 += 8 + 8 ;
F_234 ( & V_328 , V_178 , V_126 , V_339 ) ;
if ( ! V_126 )
continue;
if ( V_336 ) {
F_109 ( V_9 ,
L_51 ) ;
V_50 = - V_140 ;
goto V_57;
}
V_336 = true ;
V_50 = F_236 ( & V_328 , V_178 , 1 , L_52 ,
& V_340 , & V_126 ) ;
if ( V_50 ) {
F_109 ( V_9 ,
L_53 ,
V_50 ) ;
goto V_339;
}
V_50 = F_237 ( & V_328 ) ;
}
}
if ( ! V_336 ) {
F_109 ( V_9 , L_54 ) ;
V_50 = - V_220 ;
}
V_57:
F_177 ( V_330 , F_198 ( 0 , V_331 ) ) ;
return V_50 ;
V_339:
V_50 = - V_4 ;
goto V_57;
}
static void F_238 ( struct V_8 * V_9 , bool V_341 )
{
F_30 ( L_55 , V_66 , V_9 , V_341 ) ;
F_239 ( & V_9 -> V_342 ) ;
if ( V_341 )
F_240 ( & V_9 -> V_343 ) ;
else
F_241 ( & V_9 -> V_343 ) ;
}
static int F_242 ( struct V_8 * V_9 ,
struct V_344 * * V_345 , T_5 * V_346 )
{
struct V_252 * V_253 = & V_9 -> V_61 -> V_71 -> V_253 ;
T_9 V_347 ;
char * V_348 ;
int V_50 ;
F_30 ( L_49 , V_66 , V_9 ) ;
V_50 = F_243 ( V_253 , & V_9 -> V_312 ,
& V_9 -> V_313 , V_314 ,
& V_347 , & V_348 , V_345 , V_346 ) ;
if ( V_50 )
return V_50 ;
if ( * V_346 == 0 ) {
F_30 ( L_56 , V_66 , V_9 ) ;
goto V_57;
}
if ( strcmp ( V_348 , V_316 ) ) {
F_109 ( V_9 , L_57 ,
V_348 ) ;
V_50 = - V_56 ;
goto V_57;
}
if ( V_347 == V_349 ) {
F_109 ( V_9 , L_58 ) ;
V_50 = - V_56 ;
goto V_57;
}
if ( strncmp ( ( * V_345 ) [ 0 ] . V_133 . V_311 , V_310 ,
strlen ( V_310 ) ) ) {
F_109 ( V_9 , L_59 ,
( * V_345 ) [ 0 ] . V_133 . V_311 ) ;
V_50 = - V_56 ;
goto V_57;
}
V_57:
F_41 ( V_348 ) ;
return V_50 ;
}
static int F_244 ( struct V_8 * V_9 ,
const struct V_344 * V_350 )
{
struct V_252 * V_253 = & V_9 -> V_61 -> V_71 -> V_253 ;
struct V_351 * V_352 ;
T_5 V_353 ;
V_117 V_311 ;
int V_125 ;
int V_50 ;
V_50 = F_245 ( V_253 , & V_9 -> V_312 ,
& V_9 -> V_313 , & V_352 ,
& V_353 ) ;
if ( V_50 )
return V_50 ;
sscanf ( V_350 -> V_133 . V_311 , V_310 L_60 , & V_311 ) ;
for ( V_125 = 0 ; V_125 < V_353 ; V_125 ++ ) {
if ( ! memcmp ( & V_352 [ V_125 ] . V_354 , & V_350 -> V_355 . V_354 ,
sizeof( V_350 -> V_355 . V_354 ) ) &&
V_352 [ V_125 ] . V_311 == V_311 ) {
struct V_301 V_306 = {
. V_304 = F_65 ( V_352 [ V_125 ] . V_152 . V_356 ) ,
. V_305 = V_311 ,
} ;
F_30 ( L_61 , V_66 ,
V_9 , V_306 . V_304 , V_306 . V_305 ) ;
F_217 ( V_9 , & V_306 ) ;
V_50 = 1 ;
goto V_57;
}
}
F_30 ( L_62 , V_66 , V_9 ) ;
V_50 = 0 ;
V_57:
F_41 ( V_352 ) ;
return V_50 ;
}
static int F_246 ( struct V_8 * V_9 )
{
struct V_357 * V_71 = V_9 -> V_61 -> V_71 ;
struct V_344 * V_345 ;
T_5 V_346 ;
int V_50 ;
for (; ; ) {
V_50 = F_219 ( V_9 ) ;
if ( V_50 != - V_56 )
return V_50 ;
V_50 = F_242 ( V_9 , & V_345 , & V_346 ) ;
if ( V_50 )
return V_50 ;
if ( V_346 == 0 )
goto V_358;
V_50 = F_244 ( V_9 , V_345 ) ;
if ( V_50 ) {
if ( V_50 > 0 )
V_50 = 0 ;
goto V_57;
}
F_109 ( V_9 , L_63 ,
F_247 ( V_345 [ 0 ] . V_133 . V_152 ) ) ;
V_50 = F_248 ( & V_71 -> V_359 ,
& V_345 [ 0 ] . V_355 . V_354 ) ;
if ( V_50 ) {
F_109 ( V_9 , L_64 ,
F_247 ( V_345 [ 0 ] . V_133 . V_152 ) , V_50 ) ;
goto V_57;
}
V_50 = F_249 ( & V_71 -> V_253 , & V_9 -> V_312 ,
& V_9 -> V_313 , V_314 ,
V_345 [ 0 ] . V_133 . V_311 ,
& V_345 [ 0 ] . V_133 . V_152 ) ;
if ( V_50 && V_50 != - V_45 )
goto V_57;
V_358:
F_250 ( V_345 , V_346 ) ;
}
V_57:
F_250 ( V_345 , V_346 ) ;
return V_50 ;
}
static enum V_360 F_251 ( struct V_8 * V_9 ,
int * V_361 )
{
enum V_360 V_18 ;
F_12 ( & V_9 -> V_22 ) ;
F_30 ( L_65 , V_66 , V_9 ,
V_9 -> V_18 ) ;
if ( F_10 ( V_9 ) ) {
V_18 = V_9 -> V_18 ;
F_13 ( & V_9 -> V_22 ) ;
return V_18 ;
}
F_13 ( & V_9 -> V_22 ) ;
F_252 ( & V_9 -> V_22 ) ;
F_30 ( L_66 , V_66 , V_9 ,
V_9 -> V_18 ) ;
if ( ! F_10 ( V_9 ) ) {
* V_361 = F_246 ( V_9 ) ;
if ( * V_361 )
F_109 ( V_9 , L_67 , * V_361 ) ;
}
V_18 = V_9 -> V_18 ;
F_253 ( & V_9 -> V_22 ) ;
return V_18 ;
}
static void F_254 ( struct V_332 * V_333 )
{
struct V_8 * V_9 = F_58 ( F_255 ( V_333 ) ,
struct V_8 , V_342 ) ;
enum V_360 V_18 ;
int V_50 ;
F_30 ( L_49 , V_66 , V_9 ) ;
V_358:
V_18 = F_251 ( V_9 , & V_50 ) ;
if ( V_18 != V_319 || V_50 == - V_362 ) {
if ( V_18 == V_19 )
F_238 ( V_9 , true ) ;
F_30 ( L_68 , V_66 ,
V_9 , V_18 , V_50 ) ;
return;
}
V_50 = F_232 ( V_9 ) ;
if ( V_50 == - V_220 ) {
goto V_358;
} else if ( V_50 < 0 ) {
F_109 ( V_9 , L_69 , V_50 ) ;
F_256 ( V_9 -> V_317 , & V_9 -> V_342 ,
V_363 ) ;
} else {
F_30 ( L_70 , V_66 ,
V_9 ) ;
F_256 ( V_9 -> V_317 , & V_9 -> V_342 ,
F_257 ( 2 * V_329 * V_364 ) ) ;
}
}
static bool F_258 ( struct V_8 * V_9 )
{
F_30 ( L_65 , V_66 , V_9 ,
V_9 -> V_18 ) ;
if ( V_9 -> V_18 != V_19 )
return false ;
V_9 -> V_18 = V_20 ;
F_259 ( & V_9 -> V_22 ) ;
F_260 ( & V_9 -> V_61 -> V_71 -> V_253 ) ;
F_13 ( & V_9 -> V_22 ) ;
F_252 ( & V_9 -> V_22 ) ;
F_30 ( L_66 , V_66 , V_9 ,
V_9 -> V_18 ) ;
if ( V_9 -> V_18 != V_20 )
return false ;
if ( ! F_222 ( V_9 ) )
F_239 ( & V_9 -> V_342 ) ;
return true ;
}
static void F_261 ( struct V_332 * V_333 )
{
struct V_8 * V_9 = F_58 ( V_333 , struct V_8 ,
V_365 ) ;
F_252 ( & V_9 -> V_22 ) ;
F_258 ( V_9 ) ;
F_253 ( & V_9 -> V_22 ) ;
}
static void F_262 ( struct V_8 * V_9 , T_9 V_340 ,
void * * V_328 )
{
struct V_301 V_306 = { 0 } ;
if ( V_340 >= 2 ) {
V_306 . V_304 = F_263 ( V_328 ) ;
V_306 . V_305 = F_263 ( V_328 ) ;
}
F_30 ( L_71 , V_66 , V_9 , V_306 . V_304 ,
V_306 . V_305 ) ;
if ( ! F_213 ( & V_306 , & V_320 ) ) {
F_252 ( & V_9 -> V_22 ) ;
if ( F_213 ( & V_306 , & V_9 -> V_309 ) ) {
F_253 ( & V_9 -> V_22 ) ;
return;
}
F_217 ( V_9 , & V_306 ) ;
F_259 ( & V_9 -> V_22 ) ;
} else {
F_12 ( & V_9 -> V_22 ) ;
}
if ( ! F_10 ( V_9 ) )
F_238 ( V_9 , false ) ;
F_13 ( & V_9 -> V_22 ) ;
}
static void F_264 ( struct V_8 * V_9 , T_9 V_340 ,
void * * V_328 )
{
struct V_301 V_306 = { 0 } ;
if ( V_340 >= 2 ) {
V_306 . V_304 = F_263 ( V_328 ) ;
V_306 . V_305 = F_263 ( V_328 ) ;
}
F_30 ( L_71 , V_66 , V_9 , V_306 . V_304 ,
V_306 . V_305 ) ;
if ( ! F_213 ( & V_306 , & V_320 ) ) {
F_252 ( & V_9 -> V_22 ) ;
if ( ! F_213 ( & V_306 , & V_9 -> V_309 ) ) {
F_30 ( L_72 ,
V_66 , V_9 , V_306 . V_304 , V_306 . V_305 ,
V_9 -> V_309 . V_304 , V_9 -> V_309 . V_305 ) ;
F_253 ( & V_9 -> V_22 ) ;
return;
}
F_217 ( V_9 , & V_320 ) ;
F_259 ( & V_9 -> V_22 ) ;
} else {
F_12 ( & V_9 -> V_22 ) ;
}
if ( ! F_10 ( V_9 ) )
F_238 ( V_9 , false ) ;
F_13 ( & V_9 -> V_22 ) ;
}
static bool F_265 ( struct V_8 * V_9 , T_9 V_340 ,
void * * V_328 )
{
struct V_301 V_366 = F_214 ( V_9 ) ;
struct V_301 V_306 = { 0 } ;
bool V_367 ;
if ( V_340 >= 2 ) {
V_306 . V_304 = F_263 ( V_328 ) ;
V_306 . V_305 = F_263 ( V_328 ) ;
}
F_30 ( L_71 , V_66 , V_9 , V_306 . V_304 ,
V_306 . V_305 ) ;
if ( F_213 ( & V_306 , & V_366 ) )
return false ;
F_12 ( & V_9 -> V_22 ) ;
V_367 = F_10 ( V_9 ) ;
if ( V_9 -> V_18 == V_19 ) {
if ( ! F_213 ( & V_9 -> V_309 , & V_320 ) ) {
F_30 ( L_73 , V_66 ,
V_9 ) ;
F_221 ( V_9 -> V_317 , & V_9 -> V_365 ) ;
}
}
F_13 ( & V_9 -> V_22 ) ;
return V_367 ;
}
static void F_266 ( struct V_8 * V_9 ,
V_117 V_368 , V_117 V_311 , V_300 * V_221 )
{
struct V_252 * V_253 = & V_9 -> V_61 -> V_71 -> V_253 ;
int V_326 = 4 + V_327 ;
char V_171 [ V_326 ] ;
int V_50 ;
if ( V_221 ) {
void * V_328 = V_171 ;
F_225 ( & V_328 , 1 , 1 ,
V_326 - V_327 ) ;
F_226 ( & V_328 , * V_221 ) ;
} else {
V_326 = 0 ;
}
V_50 = F_267 ( V_253 , & V_9 -> V_312 ,
& V_9 -> V_313 , V_368 , V_311 ,
V_171 , V_326 ) ;
if ( V_50 )
F_109 ( V_9 , L_74 , V_50 ) ;
}
static void F_268 ( struct V_8 * V_9 , V_117 V_368 ,
V_117 V_311 )
{
F_30 ( L_49 , V_66 , V_9 ) ;
F_266 ( V_9 , V_368 , V_311 , NULL ) ;
}
static void F_269 ( struct V_8 * V_9 ,
V_117 V_368 , V_117 V_311 , V_300 V_221 )
{
F_30 ( L_75 , V_66 , V_9 , V_221 ) ;
F_266 ( V_9 , V_368 , V_311 , & V_221 ) ;
}
static void F_270 ( void * V_49 , V_117 V_368 , V_117 V_311 ,
V_117 V_369 , void * V_370 , T_6 V_371 )
{
struct V_8 * V_9 = V_49 ;
void * V_328 = V_370 ;
void * const V_178 = V_328 + V_371 ;
T_9 V_340 ;
T_5 V_126 ;
T_5 V_323 ;
int V_50 ;
F_30 ( L_76 ,
V_66 , V_9 , V_311 , V_368 , V_371 ) ;
if ( V_371 ) {
V_50 = F_236 ( & V_328 , V_178 , 1 , L_77 ,
& V_340 , & V_126 ) ;
if ( V_50 ) {
F_109 ( V_9 , L_78 ,
V_50 ) ;
return;
}
V_323 = F_237 ( & V_328 ) ;
} else {
V_323 = V_372 ;
V_126 = 0 ;
}
F_30 ( L_79 , V_66 , V_9 , V_323 ) ;
switch ( V_323 ) {
case V_334 :
F_262 ( V_9 , V_340 , & V_328 ) ;
F_268 ( V_9 , V_368 , V_311 ) ;
break;
case V_335 :
F_264 ( V_9 , V_340 , & V_328 ) ;
F_268 ( V_9 , V_368 , V_311 ) ;
break;
case V_337 :
if ( F_265 ( V_9 , V_340 , & V_328 ) )
F_269 ( V_9 , V_368 ,
V_311 , 0 ) ;
else
F_268 ( V_9 , V_368 , V_311 ) ;
break;
case V_372 :
V_50 = F_271 ( V_9 ) ;
if ( V_50 )
F_109 ( V_9 , L_80 , V_50 ) ;
F_268 ( V_9 , V_368 , V_311 ) ;
break;
default:
if ( F_11 ( V_9 ) )
F_269 ( V_9 , V_368 ,
V_311 , - V_373 ) ;
else
F_268 ( V_9 , V_368 , V_311 ) ;
break;
}
}
static void F_272 ( void * V_49 , V_117 V_311 , int V_228 )
{
struct V_8 * V_9 = V_49 ;
F_109 ( V_9 , L_81 , V_228 ) ;
F_252 ( & V_9 -> V_22 ) ;
F_217 ( V_9 , & V_320 ) ;
F_253 ( & V_9 -> V_22 ) ;
F_215 ( & V_9 -> V_307 ) ;
if ( V_9 -> V_374 == V_375 ) {
F_273 ( V_9 ) ;
V_9 -> V_374 = V_376 ;
F_274 ( V_9 -> V_317 , & V_9 -> V_377 , 0 ) ;
}
F_56 ( & V_9 -> V_307 ) ;
}
static int F_275 ( struct V_8 * V_9 )
{
struct V_252 * V_253 = & V_9 -> V_61 -> V_71 -> V_253 ;
struct V_378 * V_305 ;
F_22 ( ! V_9 -> V_379 ) ;
F_30 ( L_49 , V_66 , V_9 ) ;
V_305 = F_276 ( V_253 , & V_9 -> V_312 ,
& V_9 -> V_313 , F_270 ,
F_272 , V_9 ) ;
if ( F_35 ( V_305 ) )
return F_204 ( V_305 ) ;
V_9 -> V_379 = V_305 ;
return 0 ;
}
static void F_273 ( struct V_8 * V_9 )
{
struct V_252 * V_253 = & V_9 -> V_61 -> V_71 -> V_253 ;
int V_50 ;
F_22 ( V_9 -> V_379 ) ;
F_30 ( L_49 , V_66 , V_9 ) ;
V_50 = F_277 ( V_253 , V_9 -> V_379 ) ;
if ( V_50 )
F_109 ( V_9 , L_82 , V_50 ) ;
V_9 -> V_379 = NULL ;
}
static int F_278 ( struct V_8 * V_9 )
{
int V_50 ;
F_215 ( & V_9 -> V_307 ) ;
F_22 ( V_9 -> V_374 == V_380 ) ;
V_50 = F_275 ( V_9 ) ;
if ( V_50 )
goto V_57;
V_9 -> V_374 = V_375 ;
V_9 -> V_308 = V_9 -> V_379 -> V_381 ;
V_57:
F_56 ( & V_9 -> V_307 ) ;
return V_50 ;
}
static void F_279 ( struct V_8 * V_9 )
{
F_30 ( L_49 , V_66 , V_9 ) ;
F_280 ( & V_9 -> V_377 ) ;
F_281 ( & V_9 -> V_318 ) ;
F_281 ( & V_9 -> V_321 ) ;
F_280 ( & V_9 -> V_342 ) ;
F_281 ( & V_9 -> V_365 ) ;
}
static void F_282 ( struct V_8 * V_9 )
{
F_132 ( F_283 ( & V_9 -> V_343 ) ) ;
F_279 ( V_9 ) ;
F_215 ( & V_9 -> V_307 ) ;
if ( V_9 -> V_374 == V_375 )
F_273 ( V_9 ) ;
V_9 -> V_374 = V_380 ;
F_56 ( & V_9 -> V_307 ) ;
F_284 ( & V_9 -> V_61 -> V_71 -> V_253 ) ;
}
static void F_285 ( struct V_332 * V_333 )
{
struct V_8 * V_9 = F_58 ( F_255 ( V_333 ) ,
struct V_8 , V_377 ) ;
bool V_382 = false ;
bool V_383 = false ;
int V_50 ;
F_30 ( L_49 , V_66 , V_9 ) ;
F_252 ( & V_9 -> V_22 ) ;
if ( V_9 -> V_18 == V_19 )
V_382 = F_258 ( V_9 ) ;
F_215 ( & V_9 -> V_307 ) ;
if ( V_9 -> V_374 != V_376 ) {
F_56 ( & V_9 -> V_307 ) ;
goto V_57;
}
V_50 = F_275 ( V_9 ) ;
if ( V_50 ) {
F_109 ( V_9 , L_83 , V_50 ) ;
if ( V_50 == - V_362 || V_50 == - V_45 ) {
F_117 ( V_384 , & V_9 -> V_43 ) ;
V_383 = true ;
} else {
F_274 ( V_9 -> V_317 ,
& V_9 -> V_377 ,
V_363 ) ;
}
F_56 ( & V_9 -> V_307 ) ;
goto V_57;
}
V_383 = true ;
V_9 -> V_374 = V_375 ;
V_9 -> V_308 = V_9 -> V_379 -> V_381 ;
F_56 ( & V_9 -> V_307 ) ;
V_50 = F_271 ( V_9 ) ;
if ( V_50 )
F_109 ( V_9 , L_84 , V_50 ) ;
if ( V_382 ) {
V_50 = F_246 ( V_9 ) ;
if ( V_50 )
F_109 ( V_9 , L_85 ,
V_50 ) ;
}
V_57:
F_253 ( & V_9 -> V_22 ) ;
if ( V_383 )
F_238 ( V_9 , true ) ;
}
static int F_286 ( struct V_8 * V_9 ,
const char * V_246 ,
const char * V_385 ,
const char * V_386 ,
const void * V_387 ,
T_6 V_388 ,
void * V_389 ,
T_6 V_390 )
{
struct V_190 * V_191 ;
struct V_176 * * V_177 ;
T_5 V_267 ;
int V_50 ;
V_267 = ( T_5 ) F_198 ( 0 , V_390 ) ;
V_177 = F_203 ( V_267 , V_67 ) ;
if ( F_35 ( V_177 ) )
return F_204 ( V_177 ) ;
V_50 = - V_65 ;
V_191 = F_174 ( V_246 , 0 , V_390 ,
V_213 ) ;
if ( ! V_191 )
goto V_57;
V_191 -> V_177 = V_177 ;
V_191 -> V_267 = V_267 ;
V_191 -> V_215 = F_167 ( V_9 , V_99 , 1 ,
V_191 ) ;
if ( ! V_191 -> V_215 )
goto V_57;
F_200 ( V_191 -> V_215 , 0 , V_245 ,
V_385 , V_386 ) ;
if ( V_388 ) {
struct V_391 * V_392 ;
V_392 = F_31 ( sizeof ( * V_392 ) , V_393 ) ;
if ( ! V_392 )
goto V_57;
F_287 ( V_392 ) ;
F_288 ( V_392 , V_387 , V_388 ) ;
F_289 ( V_191 -> V_215 , 0 ,
V_392 ) ;
}
F_290 ( V_191 -> V_215 , 0 ,
V_191 -> V_177 , V_390 ,
0 , false , false ) ;
F_131 ( V_191 ) ;
V_50 = F_139 ( V_191 ) ;
if ( V_50 )
goto V_57;
V_50 = V_191 -> V_221 ;
if ( V_50 < 0 )
goto V_57;
F_22 ( V_191 -> V_222 < ( V_117 ) V_3 ) ;
V_50 = ( int ) V_191 -> V_222 ;
F_291 ( V_177 , V_389 , 0 , V_191 -> V_222 ) ;
V_57:
if ( V_191 )
F_124 ( V_191 ) ;
else
F_177 ( V_177 , V_267 ) ;
return V_50 ;
}
static void F_292 ( struct V_8 * V_9 )
{
F_293 ( V_394 ) ;
do {
F_30 ( L_86 , V_66 , V_9 ) ;
F_274 ( V_9 -> V_317 , & V_9 -> V_342 , 0 ) ;
F_294 ( & V_9 -> V_343 , & V_394 ,
V_395 ) ;
F_13 ( & V_9 -> V_22 ) ;
F_295 () ;
F_12 ( & V_9 -> V_22 ) ;
} while ( V_9 -> V_18 != V_19 &&
! F_18 ( V_384 , & V_9 -> V_43 ) );
F_296 ( & V_9 -> V_343 , & V_394 ) ;
}
static void F_297 ( struct V_332 * V_333 )
{
struct V_396 * V_272 = F_298 ( V_333 ) ;
struct V_8 * V_9 = V_272 -> V_397 -> V_398 ;
struct V_202 * V_193 ;
struct V_115 * V_122 = NULL ;
V_117 V_154 = ( V_117 ) F_299 ( V_272 ) << V_113 ;
V_117 V_160 = F_300 ( V_272 ) ;
enum V_97 V_98 ;
V_117 V_399 ;
bool V_400 ;
int V_221 ;
if ( V_272 -> V_401 != V_402 ) {
F_30 ( L_87 , V_66 ,
( int ) V_272 -> V_401 ) ;
V_221 = - V_140 ;
goto V_228;
}
if ( F_301 ( V_272 ) == V_403 )
V_98 = V_101 ;
else if ( F_301 ( V_272 ) == V_404 )
V_98 = V_100 ;
else
V_98 = V_99 ;
if ( ! V_160 ) {
F_30 ( L_88 , V_66 ) ;
V_221 = 0 ;
goto V_405;
}
if ( V_98 != V_99 ) {
if ( V_9 -> V_16 . V_17 ) {
V_221 = - V_40 ;
goto V_405;
}
F_22 ( V_9 -> V_13 -> V_14 == V_15 ) ;
}
if ( ! F_18 ( V_406 , & V_9 -> V_43 ) ) {
F_30 ( L_89 ) ;
F_22 ( V_9 -> V_13 -> V_14 != V_15 ) ;
V_221 = - V_407 ;
goto V_405;
}
if ( V_154 && V_160 > V_161 - V_154 + 1 ) {
F_109 ( V_9 , L_90 , V_154 ,
V_160 ) ;
V_221 = - V_4 ;
goto V_405;
}
F_302 ( V_272 ) ;
F_12 ( & V_9 -> V_270 ) ;
V_399 = V_9 -> V_16 . V_107 ;
if ( V_98 != V_99 ) {
V_122 = V_9 -> V_10 . V_122 ;
F_303 ( V_122 ) ;
V_400 = F_9 ( V_9 ) ;
} else {
V_400 = V_9 -> V_408 -> V_96 &&
F_9 ( V_9 ) ;
}
F_13 ( & V_9 -> V_270 ) ;
if ( V_154 + V_160 > V_399 ) {
F_109 ( V_9 , L_91 , V_154 ,
V_160 , V_399 ) ;
V_221 = - V_140 ;
goto V_405;
}
if ( V_400 ) {
F_12 ( & V_9 -> V_22 ) ;
if ( V_9 -> V_18 != V_19 &&
! F_18 ( V_384 , & V_9 -> V_43 ) )
F_292 ( V_9 ) ;
F_132 ( ( V_9 -> V_18 == V_19 ) ^
! F_18 ( V_384 , & V_9 -> V_43 ) ) ;
if ( F_18 ( V_384 , & V_9 -> V_43 ) ) {
V_221 = - V_362 ;
goto V_409;
}
}
V_193 = F_183 ( V_9 , V_154 , V_160 , V_98 ,
V_122 ) ;
if ( ! V_193 ) {
V_221 = - V_65 ;
goto V_409;
}
V_193 -> V_272 = V_272 ;
V_122 = NULL ;
if ( V_98 == V_101 )
V_221 = F_197 ( V_193 , V_211 ,
NULL ) ;
else
V_221 = F_197 ( V_193 , V_212 ,
V_272 -> V_162 ) ;
if ( V_221 )
goto V_410;
V_221 = F_205 ( V_193 ) ;
if ( V_221 )
goto V_410;
if ( V_400 )
F_13 ( & V_9 -> V_22 ) ;
return;
V_410:
F_126 ( V_193 ) ;
V_409:
if ( V_400 )
F_13 ( & V_9 -> V_22 ) ;
V_405:
if ( V_221 )
F_109 ( V_9 , L_92 ,
F_53 ( V_98 ) , V_160 , V_154 , V_221 ) ;
F_70 ( V_122 ) ;
V_228:
F_304 ( V_272 , V_221 ) ;
}
static int F_305 ( struct V_411 * V_412 ,
const struct V_413 * V_414 )
{
struct V_396 * V_272 = V_414 -> V_272 ;
struct V_332 * V_333 = F_306 ( V_272 ) ;
F_221 ( V_415 , V_333 ) ;
return V_416 ;
}
static void F_307 ( struct V_8 * V_9 )
{
struct V_46 * V_47 = V_9 -> V_47 ;
if ( ! V_47 )
return;
V_9 -> V_47 = NULL ;
if ( V_47 -> V_43 & V_417 ) {
F_308 ( V_47 ) ;
if ( V_47 -> V_418 )
F_309 ( V_47 -> V_418 ) ;
F_310 ( & V_9 -> V_419 ) ;
}
F_311 ( V_47 ) ;
}
static int F_312 ( struct V_8 * V_9 ,
const char * V_246 ,
V_117 V_154 , V_117 V_160 , void * V_171 )
{
struct V_190 * V_191 ;
struct V_176 * * V_177 = NULL ;
T_5 V_267 ;
T_6 V_107 ;
int V_50 ;
V_267 = ( T_5 ) F_198 ( V_154 , V_160 ) ;
V_177 = F_203 ( V_267 , V_67 ) ;
if ( F_35 ( V_177 ) )
return F_204 ( V_177 ) ;
V_50 = - V_65 ;
V_191 = F_174 ( V_246 , V_154 , V_160 ,
V_213 ) ;
if ( ! V_191 )
goto V_57;
V_191 -> V_177 = V_177 ;
V_191 -> V_267 = V_267 ;
V_191 -> V_215 = F_167 ( V_9 , V_99 , 1 ,
V_191 ) ;
if ( ! V_191 -> V_215 )
goto V_57;
F_194 ( V_191 -> V_215 , 0 , V_237 ,
V_154 , V_160 , 0 , 0 ) ;
F_196 ( V_191 -> V_215 , 0 ,
V_191 -> V_177 ,
V_191 -> V_160 ,
V_191 -> V_154 & ~ V_182 ,
false , false ) ;
F_131 ( V_191 ) ;
V_50 = F_139 ( V_191 ) ;
if ( V_50 )
goto V_57;
V_50 = V_191 -> V_221 ;
if ( V_50 < 0 )
goto V_57;
F_22 ( V_191 -> V_222 <= ( V_117 ) V_114 ) ;
V_107 = ( T_6 ) V_191 -> V_222 ;
F_291 ( V_177 , V_171 , 0 , V_107 ) ;
F_22 ( V_107 <= ( T_6 ) V_3 ) ;
V_50 = ( int ) V_107 ;
V_57:
if ( V_191 )
F_124 ( V_191 ) ;
else
F_177 ( V_177 , V_267 ) ;
return V_50 ;
}
static int F_313 ( struct V_8 * V_9 )
{
struct V_105 * V_106 = NULL ;
T_5 V_108 = 0 ;
V_117 V_420 = 0 ;
T_5 V_421 ;
int V_50 ;
do {
T_6 V_107 ;
F_41 ( V_106 ) ;
V_107 = sizeof ( * V_106 ) ;
V_107 += V_108 * sizeof ( struct V_130 ) ;
V_107 += V_420 ;
V_106 = F_31 ( V_107 , V_67 ) ;
if ( ! V_106 )
return - V_65 ;
V_50 = F_312 ( V_9 , V_9 -> V_312 . V_152 ,
0 , V_107 , V_106 ) ;
if ( V_50 < 0 )
goto V_57;
if ( ( T_6 ) V_50 < V_107 ) {
V_50 = - V_407 ;
F_109 ( V_9 , L_93 ,
V_107 , V_50 ) ;
goto V_57;
}
if ( ! F_63 ( V_106 ) ) {
V_50 = - V_407 ;
F_109 ( V_9 , L_94 ) ;
goto V_57;
}
V_420 = F_65 ( V_106 -> V_118 ) ;
V_421 = V_108 ;
V_108 = F_64 ( V_106 -> V_108 ) ;
} while ( V_108 != V_421 );
V_50 = F_66 ( V_9 , V_106 ) ;
V_57:
F_41 ( V_106 ) ;
return V_50 ;
}
static void F_314 ( struct V_8 * V_9 )
{
V_117 V_14 ;
if ( ! F_18 ( V_406 , & V_9 -> V_43 ) )
return;
V_14 = V_9 -> V_13 -> V_14 ;
if ( V_14 == V_15 )
return;
if ( F_74 ( V_9 , V_14 ) == V_148 )
F_148 ( V_406 , & V_9 -> V_43 ) ;
}
static void F_315 ( struct V_8 * V_9 )
{
T_10 V_107 ;
if ( F_18 ( V_406 , & V_9 -> V_43 ) &&
! F_18 ( V_42 , & V_9 -> V_43 ) ) {
V_107 = ( T_10 ) V_9 -> V_16 . V_107 / V_422 ;
F_30 ( L_95 , ( unsigned long long ) V_107 ) ;
F_316 ( V_9 -> V_47 , V_107 ) ;
F_317 ( V_9 -> V_47 ) ;
}
}
static int F_271 ( struct V_8 * V_9 )
{
V_117 V_399 ;
int V_50 ;
F_252 ( & V_9 -> V_270 ) ;
V_399 = V_9 -> V_16 . V_107 ;
V_50 = F_318 ( V_9 ) ;
if ( V_50 )
goto V_57;
if ( V_9 -> V_277 ) {
V_50 = F_319 ( V_9 ) ;
if ( V_50 )
goto V_57;
}
if ( V_9 -> V_13 -> V_14 == V_15 ) {
V_9 -> V_16 . V_107 = V_9 -> V_10 . V_134 ;
} else {
F_314 ( V_9 ) ;
}
V_57:
F_253 ( & V_9 -> V_270 ) ;
if ( ! V_50 && V_399 != V_9 -> V_16 . V_107 )
F_315 ( V_9 ) ;
return V_50 ;
}
static int F_320 ( void * V_370 , struct V_396 * V_272 ,
unsigned int V_423 , unsigned int V_424 ,
unsigned int V_425 )
{
struct V_332 * V_333 = F_306 ( V_272 ) ;
F_321 ( V_333 , F_297 ) ;
return 0 ;
}
static int F_322 ( struct V_8 * V_9 )
{
struct V_46 * V_47 ;
struct V_426 * V_397 ;
V_117 V_159 ;
int V_228 ;
V_47 = F_323 ( V_28 ?
( 1 << V_6 ) :
V_427 ) ;
if ( ! V_47 )
return - V_65 ;
snprintf ( V_47 -> V_428 , sizeof( V_47 -> V_428 ) , V_429 L_96 ,
V_9 -> V_5 ) ;
V_47 -> V_430 = V_9 -> V_430 ;
V_47 -> V_431 = V_9 -> V_7 ;
if ( V_28 )
V_47 -> V_43 |= V_432 ;
V_47 -> V_433 = & V_434 ;
V_47 -> V_37 = V_9 ;
memset ( & V_9 -> V_419 , 0 , sizeof( V_9 -> V_419 ) ) ;
V_9 -> V_419 . V_435 = & V_436 ;
V_9 -> V_419 . V_92 = V_9 -> V_408 -> V_92 ;
V_9 -> V_419 . V_425 = V_437 ;
V_9 -> V_419 . V_43 = V_438 | V_439 ;
V_9 -> V_419 . V_440 = 1 ;
V_9 -> V_419 . V_441 = sizeof( struct V_332 ) ;
V_228 = F_324 ( & V_9 -> V_419 ) ;
if ( V_228 )
goto V_442;
V_397 = F_325 ( & V_9 -> V_419 ) ;
if ( F_35 ( V_397 ) ) {
V_228 = F_204 ( V_397 ) ;
goto V_443;
}
F_326 ( V_444 , V_397 ) ;
V_159 = F_90 ( & V_9 -> V_10 ) ;
F_327 ( V_397 , V_159 / V_422 ) ;
V_397 -> V_445 . V_446 = F_328 ( V_397 ) ;
F_329 ( V_397 , V_159 / V_422 ) ;
F_330 ( V_397 , V_159 ) ;
F_331 ( V_397 , V_159 ) ;
F_332 ( V_397 , V_159 ) ;
F_326 ( V_447 , V_397 ) ;
V_397 -> V_445 . V_448 = V_159 ;
V_397 -> V_445 . V_449 = V_159 ;
F_333 ( V_397 , V_159 / V_422 ) ;
V_397 -> V_445 . V_450 = 1 ;
if ( ! F_334 ( V_9 -> V_61 -> V_71 , V_451 ) )
V_397 -> V_452 . V_453 |= V_454 ;
V_47 -> V_418 = V_397 ;
V_397 -> V_398 = V_9 ;
V_9 -> V_47 = V_47 ;
return 0 ;
V_443:
F_310 ( & V_9 -> V_419 ) ;
V_442:
F_311 ( V_47 ) ;
return V_228 ;
}
static struct V_8 * F_335 ( struct V_32 * V_33 )
{
return F_58 ( V_33 , struct V_8 , V_33 ) ;
}
static T_11 F_336 ( struct V_32 * V_33 ,
struct V_455 * V_26 , char * V_171 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
return sprintf ( V_171 , L_97 ,
( unsigned long long ) V_9 -> V_16 . V_107 ) ;
}
static T_11 F_337 ( struct V_32 * V_33 ,
struct V_455 * V_26 , char * V_171 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
return sprintf ( V_171 , L_98 ,
( unsigned long long ) V_9 -> V_16 . V_11 ) ;
}
static T_11 F_338 ( struct V_32 * V_33 ,
struct V_455 * V_26 , char * V_171 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
if ( V_9 -> V_430 )
return sprintf ( V_171 , L_99 , V_9 -> V_430 ) ;
return sprintf ( V_171 , L_100 ) ;
}
static T_11 F_339 ( struct V_32 * V_33 ,
struct V_455 * V_26 , char * V_171 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
return sprintf ( V_171 , L_99 , V_9 -> V_7 ) ;
}
static T_11 F_340 ( struct V_32 * V_33 ,
struct V_455 * V_26 , char * V_171 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
struct V_456 * V_457 =
F_341 ( V_9 -> V_61 -> V_71 ) ;
return sprintf ( V_171 , L_101 , & V_457 -> V_458 ,
F_64 ( V_457 -> V_459 ) ) ;
}
static T_11 F_342 ( struct V_32 * V_33 ,
struct V_455 * V_26 , char * V_171 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
return sprintf ( V_171 , L_102 ,
F_216 ( V_9 -> V_61 -> V_71 ) ) ;
}
static T_11 F_343 ( struct V_32 * V_33 ,
struct V_455 * V_26 , char * V_171 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
return sprintf ( V_171 , L_103 , & V_9 -> V_61 -> V_71 -> V_460 ) ;
}
static T_11 F_344 ( struct V_32 * V_33 ,
struct V_455 * V_26 , char * V_171 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
return sprintf ( V_171 , L_104 , V_9 -> V_461 ) ;
}
static T_11 F_345 ( struct V_32 * V_33 ,
struct V_455 * V_26 , char * V_171 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
return sprintf ( V_171 , L_104 , V_9 -> V_13 -> V_462 ) ;
}
static T_11 F_346 ( struct V_32 * V_33 ,
struct V_455 * V_26 , char * V_171 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
return sprintf ( V_171 , L_97 ,
( unsigned long long ) V_9 -> V_13 -> V_263 ) ;
}
static T_11 F_347 ( struct V_32 * V_33 ,
struct V_455 * V_26 , char * V_171 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
if ( V_9 -> V_13 -> V_463 )
return sprintf ( V_171 , L_104 , V_9 -> V_13 -> V_463 ) ;
return sprintf ( V_171 , L_105 ) ;
}
static T_11 F_348 ( struct V_32 * V_33 ,
struct V_455 * V_26 , char * V_171 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
return sprintf ( V_171 , L_104 , V_9 -> V_13 -> V_464 ) ;
}
static T_11 F_349 ( struct V_32 * V_33 ,
struct V_455 * V_26 ,
char * V_171 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
return sprintf ( V_171 , L_104 , V_9 -> V_13 -> V_142 ) ;
}
static T_11 F_350 ( struct V_32 * V_33 ,
struct V_455 * V_26 , char * V_171 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
return sprintf ( V_171 , L_97 , V_9 -> V_13 -> V_14 ) ;
}
static T_11 F_351 ( struct V_32 * V_33 ,
struct V_455 * V_26 ,
char * V_171 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
T_11 V_465 = 0 ;
if ( ! V_9 -> V_277 )
return sprintf ( V_171 , L_106 ) ;
for ( ; V_9 -> V_277 ; V_9 = V_9 -> V_277 ) {
struct V_466 * V_13 = V_9 -> V_268 ;
V_465 += sprintf ( & V_171 [ V_465 ] , L_32
L_107
L_108
L_109
L_110 ,
! V_465 ? L_46 : L_111 ,
V_13 -> V_263 , V_13 -> V_462 ,
V_13 -> V_464 , V_13 -> V_463 ? : L_112 ,
V_13 -> V_14 , V_13 -> V_142 ,
V_9 -> V_199 ) ;
}
return V_465 ;
}
static T_11 F_352 ( struct V_32 * V_33 ,
struct V_455 * V_26 ,
const char * V_171 ,
T_6 V_107 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
int V_50 ;
V_50 = F_271 ( V_9 ) ;
if ( V_50 )
return V_50 ;
return V_107 ;
}
static struct V_466 * F_353 ( struct V_466 * V_13 )
{
F_45 ( & V_13 -> V_69 ) ;
return V_13 ;
}
static void F_180 ( struct V_466 * V_13 )
{
if ( V_13 )
F_61 ( & V_13 -> V_69 , V_467 ) ;
}
static struct V_466 * F_354 ( void )
{
struct V_466 * V_13 ;
V_13 = F_355 ( sizeof ( * V_13 ) , V_67 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_263 = V_468 ;
V_13 -> V_14 = V_15 ;
F_32 ( & V_13 -> V_69 ) ;
return V_13 ;
}
static void V_467 ( struct V_69 * V_69 )
{
struct V_466 * V_13 = F_58 ( V_69 , struct V_466 , V_69 ) ;
F_41 ( V_13 -> V_462 ) ;
F_41 ( V_13 -> V_464 ) ;
F_41 ( V_13 -> V_463 ) ;
F_41 ( V_13 -> V_142 ) ;
F_41 ( V_13 ) ;
}
static void F_356 ( struct V_8 * V_9 )
{
F_132 ( V_9 -> V_374 != V_380 ) ;
F_132 ( V_9 -> V_18 != V_319 ) ;
F_357 ( & V_9 -> V_312 ) ;
F_358 ( & V_9 -> V_313 ) ;
F_41 ( V_9 -> V_461 ) ;
F_60 ( V_9 -> V_61 ) ;
F_180 ( V_9 -> V_13 ) ;
F_41 ( V_9 -> V_408 ) ;
F_41 ( V_9 ) ;
}
static void F_359 ( struct V_32 * V_33 )
{
struct V_8 * V_9 = F_335 ( V_33 ) ;
bool V_469 = ! ! V_9 -> V_408 ;
if ( V_469 ) {
F_360 ( V_9 -> V_317 ) ;
F_361 ( & V_470 , V_9 -> V_5 ) ;
}
F_356 ( V_9 ) ;
if ( V_469 )
F_362 ( V_471 ) ;
}
static struct V_8 * F_363 ( struct V_61 * V_64 ,
struct V_466 * V_13 )
{
struct V_8 * V_9 ;
V_9 = F_355 ( sizeof( * V_9 ) , V_67 ) ;
if ( ! V_9 )
return NULL ;
F_184 ( & V_9 -> V_41 ) ;
F_33 ( & V_9 -> V_70 ) ;
F_364 ( & V_9 -> V_270 ) ;
F_365 ( & V_9 -> V_312 ) ;
F_366 ( & V_9 -> V_313 ) ;
F_367 ( & V_9 -> V_307 ) ;
V_9 -> V_374 = V_380 ;
F_368 ( & V_9 -> V_377 , F_285 ) ;
F_364 ( & V_9 -> V_22 ) ;
V_9 -> V_18 = V_319 ;
F_321 ( & V_9 -> V_318 , F_230 ) ;
F_321 ( & V_9 -> V_321 , F_231 ) ;
F_368 ( & V_9 -> V_342 , F_254 ) ;
F_321 ( & V_9 -> V_365 , F_261 ) ;
F_369 ( & V_9 -> V_343 ) ;
V_9 -> V_33 . V_472 = & V_473 ;
V_9 -> V_33 . type = & V_474 ;
V_9 -> V_33 . V_277 = & V_475 ;
F_370 ( & V_9 -> V_33 ) ;
V_9 -> V_61 = V_64 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_262 . V_138 = 1 << V_476 ;
V_9 -> V_262 . V_139 = 1 ;
V_9 -> V_262 . V_281 = 1 << V_476 ;
V_9 -> V_262 . V_263 = V_13 -> V_263 ;
F_371 ( V_9 -> V_262 . V_477 , NULL ) ;
return V_9 ;
}
static struct V_8 * F_372 ( struct V_61 * V_64 ,
struct V_466 * V_13 ,
struct V_81 * V_408 )
{
struct V_8 * V_9 ;
V_9 = F_363 ( V_64 , V_13 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_408 = V_408 ;
V_9 -> V_5 = F_373 ( & V_470 , 0 ,
F_8 ( 1 << V_478 ) ,
V_67 ) ;
if ( V_9 -> V_5 < 0 )
goto V_479;
sprintf ( V_9 -> V_152 , V_429 L_96 , V_9 -> V_5 ) ;
V_9 -> V_317 = F_374 ( L_113 , V_480 ,
V_9 -> V_152 ) ;
if ( ! V_9 -> V_317 )
goto V_481;
F_375 ( V_471 ) ;
F_30 ( L_114 , V_66 , V_9 , V_9 -> V_5 ) ;
return V_9 ;
V_481:
F_361 ( & V_470 , V_9 -> V_5 ) ;
V_479:
F_356 ( V_9 ) ;
return NULL ;
}
static void F_376 ( struct V_8 * V_9 )
{
if ( V_9 )
F_23 ( & V_9 -> V_33 ) ;
}
static int F_79 ( struct V_8 * V_9 , V_117 V_14 ,
T_9 * V_112 , V_117 * V_150 )
{
V_116 V_482 = F_377 ( V_14 ) ;
int V_50 ;
struct {
T_9 V_112 ;
V_116 V_107 ;
} V_483 ( ( V_484 ) ) V_485 = { 0 } ;
V_50 = F_286 ( V_9 , V_9 -> V_312 . V_152 ,
L_41 , L_115 ,
& V_482 , sizeof ( V_482 ) ,
& V_485 , sizeof ( V_485 ) ) ;
F_30 ( L_116 , V_66 , V_50 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( V_50 < sizeof ( V_485 ) )
return - V_486 ;
if ( V_112 ) {
* V_112 = V_485 . V_112 ;
F_30 ( L_117 , ( unsigned int ) * V_112 ) ;
}
* V_150 = F_65 ( V_485 . V_107 ) ;
F_30 ( L_118 ,
( unsigned long long ) V_14 ,
( unsigned long long ) * V_150 ) ;
return 0 ;
}
static int F_378 ( struct V_8 * V_9 )
{
return F_79 ( V_9 , V_15 ,
& V_9 -> V_10 . V_135 ,
& V_9 -> V_10 . V_134 ) ;
}
static int F_379 ( struct V_8 * V_9 )
{
void * V_487 ;
int V_50 ;
void * V_328 ;
V_487 = F_355 ( V_488 , V_67 ) ;
if ( ! V_487 )
return - V_65 ;
V_50 = F_286 ( V_9 , V_9 -> V_312 . V_152 ,
L_41 , L_119 , NULL , 0 ,
V_487 , V_488 ) ;
F_30 ( L_116 , V_66 , V_50 ) ;
if ( V_50 < 0 )
goto V_57;
V_328 = V_487 ;
V_9 -> V_10 . V_121 = F_380 ( & V_328 ,
V_328 + V_50 , NULL , V_157 ) ;
V_50 = 0 ;
if ( F_35 ( V_9 -> V_10 . V_121 ) ) {
V_50 = F_204 ( V_9 -> V_10 . V_121 ) ;
V_9 -> V_10 . V_121 = NULL ;
} else {
F_30 ( L_120 , V_9 -> V_10 . V_121 ) ;
}
V_57:
F_41 ( V_487 ) ;
return V_50 ;
}
static int F_81 ( struct V_8 * V_9 , V_117 V_14 ,
V_117 * V_151 )
{
V_116 V_482 = F_377 ( V_14 ) ;
struct {
V_116 V_11 ;
V_116 V_489 ;
} V_483 ( ( V_484 ) ) V_490 = { 0 } ;
V_117 V_491 ;
int V_50 ;
V_50 = F_286 ( V_9 , V_9 -> V_312 . V_152 ,
L_41 , L_121 ,
& V_482 , sizeof ( V_482 ) ,
& V_490 , sizeof ( V_490 ) ) ;
F_30 ( L_116 , V_66 , V_50 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( V_50 < sizeof ( V_490 ) )
return - V_486 ;
V_491 = F_65 ( V_490 . V_489 ) & ~ V_492 ;
if ( V_491 ) {
F_109 ( V_9 , L_122 ,
V_491 ) ;
return - V_407 ;
}
* V_151 = F_65 ( V_490 . V_11 ) ;
F_30 ( L_123 ,
( unsigned long long ) V_14 ,
( unsigned long long ) * V_151 ,
( unsigned long long ) F_65 ( V_490 . V_489 ) ) ;
return 0 ;
}
static int F_381 ( struct V_8 * V_9 )
{
return F_81 ( V_9 , V_15 ,
& V_9 -> V_10 . V_11 ) ;
}
static int F_319 ( struct V_8 * V_9 )
{
struct V_466 * V_268 ;
T_6 V_107 ;
void * V_487 = NULL ;
V_116 V_482 ;
void * V_328 ;
void * V_178 ;
V_117 V_263 ;
char * V_464 ;
V_117 V_14 ;
V_117 V_493 ;
int V_50 ;
V_268 = F_354 () ;
if ( ! V_268 )
return - V_65 ;
V_107 = sizeof ( V_116 ) +
sizeof ( V_296 ) + V_494 +
sizeof ( V_116 ) +
sizeof ( V_116 ) ;
V_487 = F_31 ( V_107 , V_67 ) ;
if ( ! V_487 ) {
V_50 = - V_65 ;
goto V_127;
}
V_482 = F_377 ( V_9 -> V_13 -> V_14 ) ;
V_50 = F_286 ( V_9 , V_9 -> V_312 . V_152 ,
L_41 , L_124 ,
& V_482 , sizeof ( V_482 ) ,
V_487 , V_107 ) ;
F_30 ( L_116 , V_66 , V_50 ) ;
if ( V_50 < 0 )
goto V_127;
V_328 = V_487 ;
V_178 = V_487 + V_50 ;
V_50 = - V_486 ;
F_382 ( & V_328 , V_178 , V_263 , V_127 ) ;
if ( V_263 == V_468 ) {
if ( V_9 -> V_199 ) {
V_9 -> V_199 = 0 ;
F_181 ( V_9 ) ;
F_383 ( L_125 ,
V_9 -> V_47 -> V_428 ) ;
}
goto V_57;
}
V_50 = - V_140 ;
if ( V_263 > ( V_117 ) V_495 ) {
F_109 ( NULL , L_126 ,
( unsigned long long ) V_263 , V_495 ) ;
goto V_127;
}
V_464 = F_380 ( & V_328 , V_178 , NULL , V_67 ) ;
if ( F_35 ( V_464 ) ) {
V_50 = F_204 ( V_464 ) ;
goto V_127;
}
F_382 ( & V_328 , V_178 , V_14 , V_127 ) ;
F_382 ( & V_328 , V_178 , V_493 , V_127 ) ;
if ( ! V_9 -> V_268 ) {
V_268 -> V_263 = V_263 ;
V_268 -> V_464 = V_464 ;
V_268 -> V_14 = V_14 ;
V_9 -> V_268 = V_268 ;
V_268 = NULL ;
} else {
F_41 ( V_464 ) ;
}
if ( ! V_493 ) {
if ( V_268 ) {
if ( V_9 -> V_199 )
F_109 ( V_9 ,
L_127 ) ;
} else {
F_109 ( V_9 , L_128 ) ;
}
}
V_9 -> V_199 = V_493 ;
V_57:
V_50 = 0 ;
V_127:
F_41 ( V_487 ) ;
F_180 ( V_268 ) ;
return V_50 ;
}
static int F_384 ( struct V_8 * V_9 )
{
struct {
V_116 V_138 ;
V_116 V_139 ;
} V_483 ( ( V_484 ) ) V_496 = { 0 } ;
T_6 V_107 = sizeof ( V_496 ) ;
void * V_328 ;
V_117 V_497 ;
V_117 V_138 ;
V_117 V_139 ;
int V_50 ;
V_50 = F_286 ( V_9 , V_9 -> V_312 . V_152 ,
L_41 , L_129 , NULL , 0 ,
( char * ) & V_496 , V_107 ) ;
F_30 ( L_116 , V_66 , V_50 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( V_50 < V_107 )
return - V_486 ;
V_50 = - V_4 ;
V_497 = ( V_117 ) 1 << V_9 -> V_10 . V_135 ;
V_328 = & V_496 ;
V_138 = F_263 ( & V_328 ) ;
if ( V_138 != V_497 ) {
F_109 ( V_9 , L_130
L_131 ,
V_138 , V_497 ) ;
return - V_4 ;
}
V_139 = F_263 ( & V_328 ) ;
if ( V_139 != 1 ) {
F_109 ( V_9 , L_132
L_133 , V_139 ) ;
return - V_4 ;
}
V_9 -> V_10 . V_138 = V_138 ;
V_9 -> V_10 . V_139 = V_139 ;
return 0 ;
}
static char * F_385 ( struct V_8 * V_9 )
{
T_6 V_498 ;
char * V_464 ;
void * V_328 ;
void * V_178 ;
T_6 V_107 ;
void * V_487 = NULL ;
T_6 V_126 = 0 ;
char * V_463 = NULL ;
int V_50 ;
F_22 ( ! V_9 -> V_13 -> V_463 ) ;
V_126 = strlen ( V_9 -> V_13 -> V_464 ) ;
V_498 = sizeof ( V_296 ) + V_126 ;
V_464 = F_31 ( V_498 , V_67 ) ;
if ( ! V_464 )
return NULL ;
V_328 = V_464 ;
V_178 = V_464 + V_498 ;
F_386 ( & V_328 , V_178 , V_9 -> V_13 -> V_464 , ( T_5 ) V_126 ) ;
V_107 = sizeof ( V_296 ) + V_499 ;
V_487 = F_31 ( V_107 , V_67 ) ;
if ( ! V_487 )
goto V_57;
V_50 = F_286 ( V_9 , V_500 ,
L_41 , L_134 ,
V_464 , V_498 ,
V_487 , V_107 ) ;
if ( V_50 < 0 )
goto V_57;
V_328 = V_487 ;
V_178 = V_487 + V_50 ;
V_463 = F_380 ( & V_328 , V_178 , & V_126 , V_67 ) ;
if ( F_35 ( V_463 ) )
V_463 = NULL ;
else
F_30 ( L_135 , V_66 , V_463 , V_126 ) ;
V_57:
F_41 ( V_487 ) ;
F_41 ( V_464 ) ;
return V_463 ;
}
static V_117 F_387 ( struct V_8 * V_9 , const char * V_152 )
{
struct V_115 * V_122 = V_9 -> V_10 . V_122 ;
const char * V_142 ;
T_5 V_141 = 0 ;
V_142 = V_9 -> V_10 . V_123 ;
while ( V_141 < V_122 -> V_143 ) {
if ( ! strcmp ( V_152 , V_142 ) )
return V_122 -> V_131 [ V_141 ] ;
V_142 += strlen ( V_142 ) + 1 ;
V_141 ++ ;
}
return V_15 ;
}
static V_117 F_388 ( struct V_8 * V_9 , const char * V_152 )
{
struct V_115 * V_122 = V_9 -> V_10 . V_122 ;
T_5 V_141 ;
bool V_77 = false ;
V_117 V_14 ;
for ( V_141 = 0 ; ! V_77 && V_141 < V_122 -> V_143 ; V_141 ++ ) {
const char * V_142 ;
V_14 = V_122 -> V_131 [ V_141 ] ;
V_142 = F_77 ( V_9 , V_14 ) ;
if ( F_35 ( V_142 ) ) {
if ( F_204 ( V_142 ) == - V_45 )
continue;
else
break;
}
V_77 = ! strcmp ( V_152 , V_142 ) ;
F_41 ( V_142 ) ;
}
return V_77 ? V_14 : V_15 ;
}
static V_117 F_389 ( struct V_8 * V_9 , const char * V_152 )
{
if ( V_9 -> V_104 == 1 )
return F_387 ( V_9 , V_152 ) ;
return F_388 ( V_9 , V_152 ) ;
}
static int F_390 ( struct V_8 * V_9 )
{
struct V_466 * V_13 = V_9 -> V_13 ;
F_22 ( V_13 -> V_263 != V_468 && V_13 -> V_462 ) ;
F_22 ( V_13 -> V_464 && V_13 -> V_463 ) ;
F_22 ( V_13 -> V_142 ) ;
if ( strcmp ( V_13 -> V_142 , V_149 ) ) {
V_117 V_14 ;
V_14 = F_389 ( V_9 , V_13 -> V_142 ) ;
if ( V_14 == V_15 )
return - V_45 ;
V_13 -> V_14 = V_14 ;
} else {
V_13 -> V_14 = V_15 ;
}
return 0 ;
}
static int F_391 ( struct V_8 * V_9 )
{
struct V_252 * V_253 = & V_9 -> V_61 -> V_71 -> V_253 ;
struct V_466 * V_13 = V_9 -> V_13 ;
const char * V_462 ;
const char * V_463 ;
const char * V_142 ;
int V_50 ;
F_22 ( V_13 -> V_263 != V_468 ) ;
F_22 ( V_13 -> V_464 ) ;
F_22 ( V_13 -> V_14 != V_15 ) ;
V_462 = F_392 ( V_253 -> V_501 , V_13 -> V_263 ) ;
if ( ! V_462 ) {
F_109 ( V_9 , L_136 , V_13 -> V_263 ) ;
return - V_140 ;
}
V_462 = F_72 ( V_462 , V_67 ) ;
if ( ! V_462 )
return - V_65 ;
V_463 = F_385 ( V_9 ) ;
if ( ! V_463 )
F_109 ( V_9 , L_137 ) ;
V_142 = F_76 ( V_9 , V_13 -> V_14 ) ;
if ( F_35 ( V_142 ) ) {
V_50 = F_204 ( V_142 ) ;
goto V_127;
}
V_13 -> V_462 = V_462 ;
V_13 -> V_463 = V_463 ;
V_13 -> V_142 = V_142 ;
return 0 ;
V_127:
F_41 ( V_463 ) ;
F_41 ( V_462 ) ;
return V_50 ;
}
static int F_393 ( struct V_8 * V_9 )
{
T_6 V_107 ;
int V_50 ;
void * V_487 ;
void * V_328 ;
void * V_178 ;
V_117 V_128 ;
T_5 V_108 ;
struct V_115 * V_122 ;
T_5 V_125 ;
V_107 = sizeof ( V_116 ) + sizeof ( V_296 ) +
V_502 * sizeof ( V_116 ) ;
V_487 = F_355 ( V_107 , V_67 ) ;
if ( ! V_487 )
return - V_65 ;
V_50 = F_286 ( V_9 , V_9 -> V_312 . V_152 ,
L_41 , L_138 , NULL , 0 ,
V_487 , V_107 ) ;
F_30 ( L_116 , V_66 , V_50 ) ;
if ( V_50 < 0 )
goto V_57;
V_328 = V_487 ;
V_178 = V_487 + V_50 ;
V_50 = - V_486 ;
F_382 ( & V_328 , V_178 , V_128 , V_57 ) ;
F_234 ( & V_328 , V_178 , V_108 , V_57 ) ;
if ( V_108 > ( V_114 - sizeof ( struct V_115 ) )
/ sizeof ( V_117 ) ) {
V_50 = - V_4 ;
goto V_57;
}
if ( ! F_394 ( & V_328 , V_178 , V_108 * sizeof ( V_116 ) ) )
goto V_57;
V_50 = 0 ;
V_122 = F_68 ( V_108 , V_67 ) ;
if ( ! V_122 ) {
V_50 = - V_65 ;
goto V_57;
}
V_122 -> V_128 = V_128 ;
for ( V_125 = 0 ; V_125 < V_108 ; V_125 ++ )
V_122 -> V_131 [ V_125 ] = F_263 ( & V_328 ) ;
F_70 ( V_9 -> V_10 . V_122 ) ;
V_9 -> V_10 . V_122 = V_122 ;
F_30 ( L_139 ,
( unsigned long long ) V_128 , ( unsigned int ) V_108 ) ;
V_57:
F_41 ( V_487 ) ;
return V_50 ;
}
static const char * F_77 ( struct V_8 * V_9 ,
V_117 V_14 )
{
T_6 V_107 ;
void * V_487 ;
V_116 V_482 ;
int V_50 ;
void * V_328 ;
void * V_178 ;
char * V_142 ;
V_107 = sizeof ( V_296 ) + V_503 ;
V_487 = F_31 ( V_107 , V_67 ) ;
if ( ! V_487 )
return F_43 ( - V_65 ) ;
V_482 = F_377 ( V_14 ) ;
V_50 = F_286 ( V_9 , V_9 -> V_312 . V_152 ,
L_41 , L_140 ,
& V_482 , sizeof ( V_482 ) ,
V_487 , V_107 ) ;
F_30 ( L_116 , V_66 , V_50 ) ;
if ( V_50 < 0 ) {
V_142 = F_43 ( V_50 ) ;
goto V_57;
}
V_328 = V_487 ;
V_178 = V_487 + V_50 ;
V_142 = F_380 ( & V_328 , V_178 , NULL , V_67 ) ;
if ( F_35 ( V_142 ) )
goto V_57;
F_30 ( L_141 ,
( unsigned long long ) V_14 , V_142 ) ;
V_57:
F_41 ( V_487 ) ;
return V_142 ;
}
static int F_395 ( struct V_8 * V_9 )
{
bool V_120 = V_9 -> V_10 . V_121 == NULL ;
int V_50 ;
V_50 = F_378 ( V_9 ) ;
if ( V_50 )
return V_50 ;
if ( V_120 ) {
V_50 = F_396 ( V_9 ) ;
if ( V_50 )
return V_50 ;
}
V_50 = F_393 ( V_9 ) ;
if ( V_50 && V_120 ) {
F_41 ( V_9 -> V_10 . V_121 ) ;
V_9 -> V_10 . V_121 = NULL ;
}
return V_50 ;
}
static int F_318 ( struct V_8 * V_9 )
{
F_22 ( F_62 ( V_9 -> V_104 ) ) ;
if ( V_9 -> V_104 == 1 )
return F_313 ( V_9 ) ;
return F_395 ( V_9 ) ;
}
static inline T_6 F_397 ( const char * * V_171 )
{
const char * V_504 = L_142 ;
* V_171 += strspn ( * V_171 , V_504 ) ;
return strcspn ( * V_171 , V_504 ) ;
}
static inline char * F_398 ( const char * * V_171 , T_6 * V_505 )
{
char * V_506 ;
T_6 V_126 ;
V_126 = F_397 ( V_171 ) ;
V_506 = F_399 ( * V_171 , V_126 + 1 , V_67 ) ;
if ( ! V_506 )
return NULL ;
* ( V_506 + V_126 ) = '\0' ;
* V_171 += V_126 ;
if ( V_505 )
* V_505 = V_126 ;
return V_506 ;
}
static int F_400 ( const char * V_171 ,
struct V_62 * * V_63 ,
struct V_81 * * V_408 ,
struct V_466 * * V_466 )
{
T_6 V_126 ;
char * V_111 ;
const char * V_507 ;
char * V_142 ;
T_6 V_508 ;
struct V_466 * V_13 = NULL ;
struct V_81 * V_82 = NULL ;
struct V_62 * V_509 ;
int V_50 ;
V_126 = F_397 ( & V_171 ) ;
if ( ! V_126 ) {
F_109 ( NULL , L_143 ) ;
return - V_4 ;
}
V_507 = V_171 ;
V_508 = V_126 + 1 ;
V_171 += V_126 ;
V_50 = - V_4 ;
V_111 = F_398 ( & V_171 , NULL ) ;
if ( ! V_111 )
return - V_65 ;
if ( ! * V_111 ) {
F_109 ( NULL , L_144 ) ;
goto V_127;
}
V_13 = F_354 () ;
if ( ! V_13 )
goto V_510;
V_13 -> V_462 = F_398 ( & V_171 , NULL ) ;
if ( ! V_13 -> V_462 )
goto V_510;
if ( ! * V_13 -> V_462 ) {
F_109 ( NULL , L_145 ) ;
goto V_127;
}
V_13 -> V_463 = F_398 ( & V_171 , NULL ) ;
if ( ! V_13 -> V_463 )
goto V_510;
if ( ! * V_13 -> V_463 ) {
F_109 ( NULL , L_146 ) ;
goto V_127;
}
V_126 = F_397 ( & V_171 ) ;
if ( ! V_126 ) {
V_171 = V_149 ;
V_126 = sizeof ( V_149 ) - 1 ;
} else if ( V_126 > V_503 ) {
V_50 = - V_511 ;
goto V_127;
}
V_142 = F_399 ( V_171 , V_126 + 1 , V_67 ) ;
if ( ! V_142 )
goto V_510;
* ( V_142 + V_126 ) = '\0' ;
V_13 -> V_142 = V_142 ;
V_82 = F_355 ( sizeof ( * V_82 ) , V_67 ) ;
if ( ! V_82 )
goto V_510;
V_82 -> V_17 = V_512 ;
V_82 -> V_92 = V_513 ;
V_82 -> V_96 = V_514 ;
V_509 = F_401 ( V_111 , V_507 ,
V_507 + V_508 - 1 ,
F_49 , V_82 ) ;
if ( F_35 ( V_509 ) ) {
V_50 = F_204 ( V_509 ) ;
goto V_127;
}
F_41 ( V_111 ) ;
* V_63 = V_509 ;
* V_408 = V_82 ;
* V_466 = V_13 ;
return 0 ;
V_510:
V_50 = - V_65 ;
V_127:
F_41 ( V_82 ) ;
F_180 ( V_13 ) ;
F_41 ( V_111 ) ;
return V_50 ;
}
static int F_402 ( struct V_61 * V_64 , const char * V_462 )
{
struct V_62 * V_408 = V_64 -> V_71 -> V_111 ;
V_117 V_515 ;
int V_516 = 0 ;
int V_50 ;
V_358:
V_50 = F_403 ( V_64 -> V_71 -> V_253 . V_501 , V_462 ) ;
if ( V_50 == - V_45 && V_516 ++ < 1 ) {
V_50 = F_404 ( & V_64 -> V_71 -> V_359 , L_147 ,
& V_515 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( V_64 -> V_71 -> V_253 . V_501 -> V_517 < V_515 ) {
F_405 ( & V_64 -> V_71 -> V_253 ) ;
( void ) F_406 ( & V_64 -> V_71 -> V_359 ,
V_515 ,
V_408 -> V_518 ) ;
goto V_358;
} else {
return - V_45 ;
}
}
return V_50 ;
}
static int F_407 ( struct V_8 * V_9 )
{
int V_50 ;
T_6 V_107 ;
char * V_246 ;
void * V_519 ;
char * V_464 ;
if ( V_9 -> V_13 -> V_464 ) {
V_9 -> V_104 = * V_9 -> V_13 -> V_464 ? 2 : 1 ;
return 0 ;
}
V_107 = sizeof ( V_520 ) + strlen ( V_9 -> V_13 -> V_463 ) ;
V_246 = F_31 ( V_107 , V_157 ) ;
if ( ! V_246 )
return - V_65 ;
sprintf ( V_246 , L_148 , V_520 , V_9 -> V_13 -> V_463 ) ;
F_30 ( L_149 , V_246 ) ;
V_107 = sizeof ( V_296 ) + V_494 ;
V_519 = F_355 ( V_107 , V_157 ) ;
if ( ! V_519 ) {
V_50 = - V_65 ;
goto V_57;
}
V_50 = F_286 ( V_9 , V_246 ,
L_41 , L_150 , NULL , 0 ,
V_519 , V_494 ) ;
F_30 ( L_116 , V_66 , V_50 ) ;
if ( V_50 == - V_45 ) {
V_464 = F_72 ( L_46 , V_67 ) ;
V_50 = V_464 ? 0 : - V_65 ;
if ( ! V_50 )
V_9 -> V_104 = 1 ;
} else if ( V_50 >= 0 ) {
void * V_328 = V_519 ;
V_464 = F_380 ( & V_328 , V_328 + V_50 ,
NULL , V_157 ) ;
V_50 = F_408 ( V_464 ) ;
if ( ! V_50 )
V_9 -> V_104 = 2 ;
}
if ( ! V_50 ) {
V_9 -> V_13 -> V_464 = V_464 ;
F_30 ( L_151 , V_464 ) ;
}
V_57:
F_41 ( V_519 ) ;
F_41 ( V_246 ) ;
return V_50 ;
}
static void F_409 ( struct V_8 * V_9 )
{
struct V_119 * V_10 ;
F_181 ( V_9 ) ;
V_10 = & V_9 -> V_10 ;
F_70 ( V_10 -> V_122 ) ;
F_41 ( V_10 -> V_124 ) ;
F_41 ( V_10 -> V_123 ) ;
F_41 ( V_10 -> V_121 ) ;
memset ( V_10 , 0 , sizeof ( * V_10 ) ) ;
}
static int F_396 ( struct V_8 * V_9 )
{
int V_50 ;
V_50 = F_379 ( V_9 ) ;
if ( V_50 )
goto V_127;
V_50 = F_381 ( V_9 ) ;
if ( V_50 )
goto V_127;
if ( V_9 -> V_10 . V_11 & V_521 ) {
V_50 = F_384 ( V_9 ) ;
if ( V_50 < 0 )
goto V_127;
}
return 0 ;
V_127:
V_9 -> V_10 . V_11 = 0 ;
F_41 ( V_9 -> V_10 . V_121 ) ;
V_9 -> V_10 . V_121 = NULL ;
return V_50 ;
}
static int F_410 ( struct V_8 * V_9 , int V_522 )
{
struct V_8 * V_277 = NULL ;
int V_50 ;
if ( ! V_9 -> V_268 )
return 0 ;
if ( ++ V_522 > V_523 ) {
F_383 ( L_152 , V_522 ) ;
V_50 = - V_4 ;
goto V_127;
}
V_277 = F_363 ( V_9 -> V_61 , V_9 -> V_268 ) ;
if ( ! V_277 ) {
V_50 = - V_65 ;
goto V_127;
}
F_44 ( V_9 -> V_61 ) ;
F_353 ( V_9 -> V_268 ) ;
V_50 = F_411 ( V_277 , V_522 ) ;
if ( V_50 < 0 )
goto V_127;
V_9 -> V_277 = V_277 ;
F_412 ( & V_9 -> V_269 , 1 ) ;
return 0 ;
V_127:
F_178 ( V_9 ) ;
F_376 ( V_277 ) ;
return V_50 ;
}
static int F_413 ( struct V_8 * V_9 )
{
int V_50 ;
if ( ! V_28 ) {
V_50 = F_414 ( 0 , V_9 -> V_152 ) ;
if ( V_50 < 0 )
goto V_524;
V_9 -> V_430 = V_50 ;
V_9 -> V_7 = 0 ;
} else {
V_9 -> V_430 = V_525 ;
V_9 -> V_7 = F_7 ( V_9 -> V_5 ) ;
}
V_50 = F_322 ( V_9 ) ;
if ( V_50 )
goto V_526;
V_50 = F_82 ( V_9 ) ;
if ( V_50 )
goto V_527;
F_316 ( V_9 -> V_47 , V_9 -> V_16 . V_107 / V_422 ) ;
F_26 ( V_9 -> V_47 , V_9 -> V_16 . V_17 ) ;
F_415 ( & V_9 -> V_33 , L_96 , V_9 -> V_5 ) ;
V_50 = F_416 ( & V_9 -> V_33 ) ;
if ( V_50 )
goto V_528;
F_117 ( V_406 , & V_9 -> V_43 ) ;
F_253 ( & V_9 -> V_270 ) ;
F_37 ( & V_529 ) ;
F_38 ( & V_9 -> V_70 , & V_530 ) ;
F_39 ( & V_529 ) ;
F_417 ( V_9 -> V_47 ) ;
F_383 ( L_153 , V_9 -> V_47 -> V_428 ,
( unsigned long long ) F_418 ( V_9 -> V_47 ) << V_113 ,
V_9 -> V_10 . V_11 ) ;
return V_50 ;
V_528:
F_83 ( V_9 ) ;
V_527:
F_307 ( V_9 ) ;
V_526:
if ( ! V_28 )
F_419 ( V_9 -> V_430 , V_9 -> V_152 ) ;
V_524:
F_253 ( & V_9 -> V_270 ) ;
return V_50 ;
}
static int F_420 ( struct V_8 * V_9 )
{
struct V_466 * V_13 = V_9 -> V_13 ;
int V_50 ;
F_22 ( F_62 ( V_9 -> V_104 ) ) ;
V_9 -> V_313 . V_261 = V_9 -> V_262 . V_263 ;
if ( V_9 -> V_104 == 1 )
V_50 = F_169 ( & V_9 -> V_312 , V_67 , L_148 ,
V_13 -> V_463 , V_531 ) ;
else
V_50 = F_169 ( & V_9 -> V_312 , V_67 , L_148 ,
V_532 , V_13 -> V_464 ) ;
return V_50 ;
}
static void F_421 ( struct V_8 * V_9 )
{
F_409 ( V_9 ) ;
V_9 -> V_104 = 0 ;
F_41 ( V_9 -> V_13 -> V_464 ) ;
V_9 -> V_13 -> V_464 = NULL ;
F_376 ( V_9 ) ;
}
static int F_411 ( struct V_8 * V_9 , int V_522 )
{
int V_50 ;
V_50 = F_407 ( V_9 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_420 ( V_9 ) ;
if ( V_50 )
goto V_533;
if ( ! V_522 ) {
V_50 = F_278 ( V_9 ) ;
if ( V_50 ) {
if ( V_50 == - V_45 )
F_383 ( L_154 ,
V_9 -> V_13 -> V_462 ,
V_9 -> V_13 -> V_463 ) ;
goto V_533;
}
}
V_50 = F_318 ( V_9 ) ;
if ( V_50 )
goto V_534;
if ( ! V_522 )
V_50 = F_390 ( V_9 ) ;
else
V_50 = F_391 ( V_9 ) ;
if ( V_50 ) {
if ( V_50 == - V_45 )
F_383 ( L_155 ,
V_9 -> V_13 -> V_462 ,
V_9 -> V_13 -> V_463 ,
V_9 -> V_13 -> V_142 ) ;
goto V_535;
}
if ( V_9 -> V_10 . V_11 & V_536 ) {
V_50 = F_319 ( V_9 ) ;
if ( V_50 )
goto V_535;
if ( ! V_522 && V_9 -> V_268 )
F_109 ( V_9 ,
L_156 ) ;
}
V_50 = F_410 ( V_9 , V_522 ) ;
if ( V_50 )
goto V_535;
F_30 ( L_157 ,
V_9 -> V_104 , V_9 -> V_312 . V_152 ) ;
return 0 ;
V_535:
F_409 ( V_9 ) ;
V_534:
if ( ! V_522 )
F_282 ( V_9 ) ;
V_533:
V_9 -> V_104 = 0 ;
F_41 ( V_9 -> V_13 -> V_464 ) ;
V_9 -> V_13 -> V_464 = NULL ;
return V_50 ;
}
static T_11 F_422 ( struct V_537 * V_472 ,
const char * V_171 ,
T_6 V_465 )
{
struct V_8 * V_9 = NULL ;
struct V_62 * V_63 = NULL ;
struct V_81 * V_82 = NULL ;
struct V_466 * V_13 = NULL ;
struct V_61 * V_64 ;
bool V_17 ;
int V_538 ;
if ( ! F_423 ( V_471 ) )
return - V_539 ;
V_538 = F_400 ( V_171 , & V_63 , & V_82 , & V_13 ) ;
if ( V_538 < 0 )
goto V_57;
V_64 = F_54 ( V_63 ) ;
if ( F_35 ( V_64 ) ) {
V_538 = F_204 ( V_64 ) ;
goto V_540;
}
V_538 = F_402 ( V_64 , V_13 -> V_462 ) ;
if ( V_538 < 0 ) {
if ( V_538 == - V_45 )
F_383 ( L_158 , V_13 -> V_462 ) ;
goto V_541;
}
V_13 -> V_263 = ( V_117 ) V_538 ;
V_9 = F_372 ( V_64 , V_13 , V_82 ) ;
if ( ! V_9 ) {
V_538 = - V_65 ;
goto V_541;
}
V_64 = NULL ;
V_13 = NULL ;
V_82 = NULL ;
V_9 -> V_461 = F_72 ( V_171 , V_67 ) ;
if ( ! V_9 -> V_461 ) {
V_538 = - V_65 ;
goto V_542;
}
F_252 ( & V_9 -> V_270 ) ;
V_538 = F_411 ( V_9 , 0 ) ;
if ( V_538 < 0 ) {
F_253 ( & V_9 -> V_270 ) ;
goto V_542;
}
V_17 = V_9 -> V_408 -> V_17 ;
if ( V_9 -> V_13 -> V_14 != V_15 )
V_17 = true ;
V_9 -> V_16 . V_17 = V_17 ;
V_538 = F_413 ( V_9 ) ;
if ( V_538 ) {
F_282 ( V_9 ) ;
F_421 ( V_9 ) ;
goto V_57;
}
V_538 = V_465 ;
V_57:
F_362 ( V_471 ) ;
return V_538 ;
V_542:
F_376 ( V_9 ) ;
V_541:
F_60 ( V_64 ) ;
V_540:
F_180 ( V_13 ) ;
F_41 ( V_82 ) ;
goto V_57;
}
static T_11 F_424 ( struct V_537 * V_472 ,
const char * V_171 ,
T_6 V_465 )
{
if ( V_28 )
return - V_4 ;
return F_422 ( V_472 , V_171 , V_465 ) ;
}
static T_11 F_425 ( struct V_537 * V_472 ,
const char * V_171 ,
T_6 V_465 )
{
return F_422 ( V_472 , V_171 , V_465 ) ;
}
static void F_426 ( struct V_8 * V_9 )
{
F_307 ( V_9 ) ;
F_37 ( & V_529 ) ;
F_427 ( & V_9 -> V_70 ) ;
F_39 ( & V_529 ) ;
F_148 ( V_406 , & V_9 -> V_43 ) ;
F_428 ( & V_9 -> V_33 ) ;
F_83 ( V_9 ) ;
if ( ! V_28 )
F_419 ( V_9 -> V_430 , V_9 -> V_152 ) ;
}
static void F_179 ( struct V_8 * V_9 )
{
while ( V_9 -> V_277 ) {
struct V_8 * V_543 = V_9 ;
struct V_8 * V_544 = V_543 -> V_277 ;
struct V_8 * V_545 ;
while ( V_544 && ( V_545 = V_544 -> V_277 ) ) {
V_543 = V_544 ;
V_544 = V_545 ;
}
F_22 ( V_544 ) ;
F_421 ( V_544 ) ;
V_543 -> V_277 = NULL ;
V_543 -> V_199 = 0 ;
F_22 ( V_543 -> V_268 ) ;
F_180 ( V_543 -> V_268 ) ;
V_543 -> V_268 = NULL ;
}
}
static T_11 F_429 ( struct V_537 * V_472 ,
const char * V_171 ,
T_6 V_465 )
{
struct V_8 * V_9 = NULL ;
struct V_546 * V_164 ;
int V_5 ;
char V_547 [ 6 ] ;
bool V_548 = false ;
bool V_549 = false ;
int V_50 ;
V_5 = - 1 ;
V_547 [ 0 ] = '\0' ;
sscanf ( V_171 , L_159 , & V_5 , V_547 ) ;
if ( V_5 < 0 ) {
F_52 ( L_160 ) ;
return - V_4 ;
}
if ( V_547 [ 0 ] != '\0' ) {
if ( ! strcmp ( V_547 , L_161 ) ) {
V_549 = true ;
} else {
F_52 ( L_162 , V_547 ) ;
return - V_4 ;
}
}
V_50 = - V_45 ;
F_37 ( & V_529 ) ;
F_430 (tmp, &rbd_dev_list) {
V_9 = F_431 ( V_164 , struct V_8 , V_70 ) ;
if ( V_9 -> V_5 == V_5 ) {
V_50 = 0 ;
break;
}
}
if ( ! V_50 ) {
F_17 ( & V_9 -> V_41 ) ;
if ( V_9 -> V_44 && ! V_549 )
V_50 = - V_56 ;
else
V_548 = F_111 ( V_42 ,
& V_9 -> V_43 ) ;
F_19 ( & V_9 -> V_41 ) ;
}
F_39 ( & V_529 ) ;
if ( V_50 < 0 || V_548 )
return V_50 ;
if ( V_549 ) {
F_432 ( V_9 -> V_47 -> V_418 ) ;
F_433 ( V_9 -> V_47 -> V_418 ) ;
}
F_252 ( & V_9 -> V_22 ) ;
if ( F_10 ( V_9 ) )
F_222 ( V_9 ) ;
F_253 ( & V_9 -> V_22 ) ;
F_282 ( V_9 ) ;
F_426 ( V_9 ) ;
F_421 ( V_9 ) ;
return V_465 ;
}
static T_11 F_434 ( struct V_537 * V_472 ,
const char * V_171 ,
T_6 V_465 )
{
if ( V_28 )
return - V_4 ;
return F_429 ( V_472 , V_171 , V_465 ) ;
}
static T_11 F_435 ( struct V_537 * V_472 ,
const char * V_171 ,
T_6 V_465 )
{
return F_429 ( V_472 , V_171 , V_465 ) ;
}
static int F_436 ( void )
{
int V_50 ;
V_50 = F_437 ( & V_475 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 = F_438 ( & V_473 ) ;
if ( V_50 < 0 )
F_439 ( & V_475 ) ;
return V_50 ;
}
static void F_440 ( void )
{
F_441 ( & V_473 ) ;
F_439 ( & V_475 ) ;
}
static int F_442 ( void )
{
F_22 ( ! V_271 ) ;
V_271 = F_443 ( V_202 , 0 ) ;
if ( ! V_271 )
return - V_65 ;
F_22 ( ! V_266 ) ;
V_266 = F_443 ( V_190 , 0 ) ;
if ( ! V_266 )
goto V_127;
F_22 ( ! V_153 ) ;
V_153 = F_444 ( L_163 ,
V_158 + 1 , 1 , 0 , NULL ) ;
if ( V_153 )
return 0 ;
V_127:
F_445 ( V_266 ) ;
V_266 = NULL ;
F_445 ( V_271 ) ;
V_271 = NULL ;
return - V_65 ;
}
static void F_446 ( void )
{
F_22 ( V_153 ) ;
F_445 ( V_153 ) ;
V_153 = NULL ;
F_22 ( V_266 ) ;
F_445 ( V_266 ) ;
V_266 = NULL ;
F_22 ( V_271 ) ;
F_445 ( V_271 ) ;
V_271 = NULL ;
}
static int T_12 F_447 ( void )
{
int V_538 ;
if ( ! F_448 ( NULL ) ) {
F_109 ( NULL , L_164 ) ;
return - V_4 ;
}
V_538 = F_442 () ;
if ( V_538 )
return V_538 ;
V_415 = F_449 ( V_429 , V_480 , 0 ) ;
if ( ! V_415 ) {
V_538 = - V_65 ;
goto V_550;
}
if ( V_28 ) {
V_525 = F_414 ( 0 , V_429 ) ;
if ( V_525 < 0 ) {
V_538 = V_525 ;
goto V_551;
}
}
V_538 = F_436 () ;
if ( V_538 )
goto V_526;
if ( V_28 )
F_383 ( L_165 , V_525 ) ;
else
F_383 ( L_166 ) ;
return 0 ;
V_526:
if ( V_28 )
F_419 ( V_525 , V_429 ) ;
V_551:
F_360 ( V_415 ) ;
V_550:
F_446 () ;
return V_538 ;
}
static void T_13 F_450 ( void )
{
F_451 ( & V_470 ) ;
F_440 () ;
if ( V_28 )
F_419 ( V_525 , V_429 ) ;
F_360 ( V_415 ) ;
F_446 () ;
}
