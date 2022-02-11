static void F_1 ( struct V_1 * V_2 )
{
}
static int F_2 ( struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 -> V_9 ;
bool V_10 = false ;
if ( ( V_5 & V_11 ) && V_7 -> V_12 . V_13 )
return - V_14 ;
F_3 ( & V_7 -> V_15 ) ;
if ( F_4 ( V_16 , & V_7 -> V_17 ) )
V_10 = true ;
else
V_7 -> V_18 ++ ;
F_5 ( & V_7 -> V_15 ) ;
if ( V_10 )
return - V_19 ;
F_6 ( & V_20 , V_21 ) ;
( void ) F_7 ( & V_7 -> V_2 ) ;
F_8 ( V_4 , V_7 -> V_12 . V_13 ) ;
F_9 ( & V_20 ) ;
return 0 ;
}
static int F_10 ( struct V_22 * V_23 , T_1 V_5 )
{
struct V_6 * V_7 = V_23 -> V_9 ;
unsigned long V_24 ;
F_3 ( & V_7 -> V_15 ) ;
V_24 = V_7 -> V_18 -- ;
F_5 ( & V_7 -> V_15 ) ;
F_11 ( V_24 > 0 ) ;
F_6 ( & V_20 , V_21 ) ;
F_12 ( & V_7 -> V_2 ) ;
F_9 ( & V_20 ) ;
return 0 ;
}
static struct V_25 * F_13 ( struct V_26 * V_27 )
{
struct V_25 * V_28 ;
int V_29 = - V_30 ;
F_14 ( L_1 , V_31 ) ;
V_28 = F_15 ( sizeof( struct V_25 ) , V_32 ) ;
if ( ! V_28 )
goto V_33;
F_16 ( & V_28 -> V_34 ) ;
F_17 ( & V_28 -> V_35 ) ;
F_6 ( & V_20 , V_21 ) ;
V_28 -> V_36 = F_18 ( V_27 , V_28 , 0 , 0 ) ;
if ( F_19 ( V_28 -> V_36 ) )
goto V_37;
V_27 = NULL ;
V_29 = F_20 ( V_28 -> V_36 ) ;
if ( V_29 < 0 )
goto V_38;
F_21 ( & V_39 ) ;
F_22 ( & V_28 -> V_35 , & V_40 ) ;
F_23 ( & V_39 ) ;
F_9 ( & V_20 ) ;
F_14 ( L_2 , V_31 , V_28 ) ;
return V_28 ;
V_38:
F_24 ( V_28 -> V_36 ) ;
V_37:
F_9 ( & V_20 ) ;
F_25 ( V_28 ) ;
V_33:
if ( V_27 )
F_26 ( V_27 ) ;
F_14 ( L_3 , V_31 , V_29 ) ;
return F_27 ( V_29 ) ;
}
static struct V_25 * F_28 ( struct V_26 * V_27 )
{
struct V_25 * V_41 ;
bool V_42 = false ;
if ( V_27 -> V_17 & V_43 )
return NULL ;
F_21 ( & V_39 ) ;
F_29 (client_node, &rbd_client_list, node) {
if ( ! F_30 ( V_27 , V_41 -> V_36 ) ) {
F_31 ( & V_41 -> V_34 ) ;
V_42 = true ;
break;
}
}
F_23 ( & V_39 ) ;
return V_42 ? V_41 : NULL ;
}
static int F_32 ( char * V_44 , void * V_45 )
{
struct V_46 * V_47 = V_45 ;
T_2 V_48 [ V_49 ] ;
int V_50 , V_51 , V_29 ;
V_50 = F_33 ( V_44 , V_52 , V_48 ) ;
if ( V_50 < 0 )
return - V_53 ;
if ( V_50 < V_54 ) {
V_29 = F_34 ( & V_48 [ 0 ] , & V_51 ) ;
if ( V_29 < 0 ) {
F_35 ( L_4
L_5 , V_44 ) ;
return V_29 ;
}
F_14 ( L_6 , V_50 , V_51 ) ;
} else if ( V_50 > V_54 && V_50 < V_55 ) {
F_14 ( L_7 , V_50 ,
V_48 [ 0 ] . V_56 ) ;
} else if ( V_50 > V_55 && V_50 < V_57 ) {
F_14 ( L_8 , V_50 ) ;
} else {
F_14 ( L_9 , V_50 ) ;
}
switch ( V_50 ) {
case V_58 :
V_47 -> V_13 = true ;
break;
case V_59 :
V_47 -> V_13 = false ;
break;
default:
F_11 ( false ) ;
break;
}
return 0 ;
}
static struct V_25 * F_36 ( struct V_26 * V_27 )
{
struct V_25 * V_28 ;
V_28 = F_28 ( V_27 ) ;
if ( V_28 )
F_26 ( V_27 ) ;
else
V_28 = F_13 ( V_27 ) ;
return V_28 ;
}
static void F_37 ( struct V_34 * V_34 )
{
struct V_25 * V_28 = F_38 ( V_34 , struct V_25 , V_34 ) ;
F_14 ( L_2 , V_31 , V_28 ) ;
F_21 ( & V_39 ) ;
F_39 ( & V_28 -> V_35 ) ;
F_23 ( & V_39 ) ;
F_24 ( V_28 -> V_36 ) ;
F_25 ( V_28 ) ;
}
static void F_40 ( struct V_25 * V_28 )
{
if ( V_28 )
F_41 ( & V_28 -> V_34 , F_37 ) ;
}
static bool F_42 ( T_3 V_60 )
{
return V_60 == 1 || V_60 == 2 ;
}
static bool F_43 ( struct V_61 * V_62 )
{
T_4 V_63 ;
T_3 V_64 ;
if ( memcmp ( & V_62 -> V_65 , V_66 , sizeof ( V_66 ) ) )
return false ;
if ( V_62 -> V_67 . V_68 < V_69 )
return false ;
if ( V_62 -> V_67 . V_68 > 8 * sizeof ( int ) - 1 )
return false ;
V_64 = F_44 ( V_62 -> V_64 ) ;
V_63 = V_70 - sizeof ( struct V_71 ) ;
if ( V_64 > V_63 / sizeof ( V_72 ) )
return false ;
V_63 -= V_64 * sizeof ( V_72 ) ;
if ( ( V_73 ) V_63 < F_45 ( V_62 -> V_74 ) )
return false ;
return true ;
}
static int F_46 ( struct V_75 * V_76 ,
struct V_61 * V_62 )
{
T_3 V_64 ;
T_4 V_77 ;
T_4 V_63 ;
T_3 V_78 ;
memset ( V_76 , 0 , sizeof ( * V_76 ) ) ;
V_64 = F_44 ( V_62 -> V_64 ) ;
V_77 = F_47 ( V_62 -> V_79 , sizeof ( V_62 -> V_79 ) ) ;
V_76 -> V_79 = F_15 ( V_77 + 1 , V_32 ) ;
if ( ! V_76 -> V_79 )
return - V_30 ;
memcpy ( V_76 -> V_79 , V_62 -> V_79 , V_77 ) ;
V_76 -> V_79 [ V_77 ] = '\0' ;
if ( V_64 ) {
V_73 V_74 = F_45 ( V_62 -> V_74 ) ;
if ( V_74 > ( V_73 ) V_70 )
return - V_80 ;
V_76 -> V_81 = F_15 ( V_74 , V_32 ) ;
if ( ! V_76 -> V_81 )
goto V_38;
memcpy ( V_76 -> V_81 , & V_62 -> V_82 [ V_64 ] ,
V_74 ) ;
V_63 = V_64 * sizeof ( * V_76 -> V_83 ) ;
V_76 -> V_83 = F_15 ( V_63 , V_32 ) ;
if ( ! V_76 -> V_83 )
goto V_38;
for ( V_78 = 0 ; V_78 < V_64 ; V_78 ++ )
V_76 -> V_83 [ V_78 ] =
F_45 ( V_62 -> V_82 [ V_78 ] . V_84 ) ;
} else {
F_48 ( V_62 -> V_74 ) ;
V_76 -> V_81 = NULL ;
V_76 -> V_83 = NULL ;
}
V_76 -> V_85 = 0 ;
V_76 -> V_86 = V_62 -> V_67 . V_68 ;
V_76 -> V_87 = V_62 -> V_67 . V_87 ;
V_76 -> V_88 = V_62 -> V_67 . V_88 ;
V_76 -> V_84 = F_45 ( V_62 -> V_84 ) ;
V_63 = sizeof ( struct V_71 ) ;
V_63 += V_64 * sizeof ( V_76 -> V_89 -> V_82 [ 0 ] ) ;
V_76 -> V_89 = F_49 ( V_63 , V_32 ) ;
if ( ! V_76 -> V_89 )
goto V_38;
F_50 ( & V_76 -> V_89 -> V_90 , 1 ) ;
V_76 -> V_89 -> V_91 = F_45 ( V_62 -> V_92 ) ;
V_76 -> V_89 -> V_93 = V_64 ;
for ( V_78 = 0 ; V_78 < V_64 ; V_78 ++ )
V_76 -> V_89 -> V_82 [ V_78 ] =
F_45 ( V_62 -> V_82 [ V_78 ] . V_94 ) ;
return 0 ;
V_38:
F_25 ( V_76 -> V_83 ) ;
V_76 -> V_83 = NULL ;
F_25 ( V_76 -> V_81 ) ;
V_76 -> V_81 = NULL ;
F_25 ( V_76 -> V_79 ) ;
V_76 -> V_79 = NULL ;
return - V_30 ;
}
static const char * F_51 ( struct V_6 * V_7 , V_73 V_95 )
{
struct V_96 * V_97 ;
if ( V_95 == V_98 )
return V_99 ;
F_29 (snap, &rbd_dev->snaps, node)
if ( V_95 == V_97 -> V_94 )
return V_97 -> V_100 ;
return NULL ;
}
static int F_52 ( struct V_6 * V_7 , const char * V_101 )
{
struct V_96 * V_97 ;
F_29 (snap, &rbd_dev->snaps, node) {
if ( ! strcmp ( V_101 , V_97 -> V_100 ) ) {
V_7 -> V_102 -> V_95 = V_97 -> V_94 ;
V_7 -> V_12 . V_63 = V_97 -> V_63 ;
V_7 -> V_12 . V_85 = V_97 -> V_85 ;
return 0 ;
}
}
return - V_19 ;
}
static int F_53 ( struct V_6 * V_7 )
{
int V_29 ;
if ( ! memcmp ( V_7 -> V_102 -> V_101 , V_99 ,
sizeof ( V_99 ) ) ) {
V_7 -> V_102 -> V_95 = V_98 ;
V_7 -> V_12 . V_63 = V_7 -> V_76 . V_84 ;
V_7 -> V_12 . V_85 = V_7 -> V_76 . V_85 ;
V_29 = 0 ;
} else {
V_29 = F_52 ( V_7 , V_7 -> V_102 -> V_101 ) ;
if ( V_29 < 0 )
goto V_103;
V_7 -> V_12 . V_13 = true ;
}
F_54 ( V_104 , & V_7 -> V_17 ) ;
V_103:
return V_29 ;
}
static void F_55 ( struct V_75 * V_76 )
{
F_25 ( V_76 -> V_79 ) ;
V_76 -> V_79 = NULL ;
F_25 ( V_76 -> V_83 ) ;
V_76 -> V_83 = NULL ;
F_25 ( V_76 -> V_81 ) ;
V_76 -> V_81 = NULL ;
F_56 ( V_76 -> V_89 ) ;
V_76 -> V_89 = NULL ;
}
static const char * F_57 ( struct V_6 * V_7 , V_73 V_105 )
{
char * V_100 ;
V_73 V_106 ;
int V_29 ;
V_100 = F_15 ( V_107 + 1 , V_108 ) ;
if ( ! V_100 )
return NULL ;
V_106 = V_105 >> V_7 -> V_76 . V_86 ;
V_29 = snprintf ( V_100 , V_107 + 1 , L_10 ,
V_7 -> V_76 . V_79 , V_106 ) ;
if ( V_29 < 0 || V_29 > V_107 ) {
F_35 ( L_11 ,
V_106 , V_29 ) ;
F_25 ( V_100 ) ;
V_100 = NULL ;
}
return V_100 ;
}
static V_73 F_58 ( struct V_6 * V_7 , V_73 V_105 )
{
V_73 V_109 = ( V_73 ) 1 << V_7 -> V_76 . V_86 ;
return V_105 & ( V_109 - 1 ) ;
}
static V_73 F_59 ( struct V_6 * V_7 ,
V_73 V_105 , V_73 V_110 )
{
V_73 V_109 = ( V_73 ) 1 << V_7 -> V_76 . V_86 ;
V_105 &= V_109 - 1 ;
F_11 ( V_110 <= V_111 - V_105 ) ;
if ( V_105 + V_110 > V_109 )
V_110 = V_109 - V_105 ;
return V_110 ;
}
static V_73 F_60 ( struct V_75 * V_76 )
{
return 1 << V_76 -> V_86 ;
}
static void F_61 ( struct V_112 * V_113 )
{
struct V_112 * V_114 ;
while ( V_113 ) {
V_114 = V_113 ;
V_113 = V_113 -> V_115 ;
F_62 ( V_114 ) ;
}
}
static void F_63 ( struct V_112 * V_113 , int V_116 )
{
struct V_117 * V_118 ;
unsigned long V_17 ;
void * V_119 ;
int V_78 ;
int V_120 = 0 ;
while ( V_113 ) {
F_64 (bv, chain, i) {
if ( V_120 + V_118 -> V_121 > V_116 ) {
int V_122 = F_65 ( V_116 - V_120 , 0 ) ;
V_119 = F_66 ( V_118 , & V_17 ) ;
memset ( V_119 + V_122 , 0 ,
V_118 -> V_121 - V_122 ) ;
F_67 ( V_119 , & V_17 ) ;
}
V_120 += V_118 -> V_121 ;
}
V_113 = V_113 -> V_115 ;
}
}
static struct V_112 * F_68 ( struct V_112 * V_123 ,
unsigned int V_105 ,
unsigned int V_77 ,
T_5 V_124 )
{
struct V_117 * V_118 ;
unsigned int V_125 ;
unsigned short V_126 ;
unsigned int V_127 ;
unsigned short V_128 ;
unsigned short V_129 ;
struct V_112 * V_112 ;
if ( ! V_105 && V_77 == V_123 -> V_130 )
return F_69 ( V_123 , V_124 ) ;
if ( F_70 ( ! V_77 ) )
return NULL ;
if ( F_70 ( V_77 > V_123 -> V_130 ) )
return NULL ;
if ( F_70 ( V_105 > V_123 -> V_130 - V_77 ) )
return NULL ;
V_125 = V_105 ;
F_71 (bv, bio_src, idx, 0 ) {
if ( V_125 < V_118 -> V_121 )
break;
V_125 -= V_118 -> V_121 ;
}
V_127 = V_125 ;
V_125 += V_77 ;
F_71 (bv, bio_src, end_idx, idx) {
if ( V_125 <= V_118 -> V_121 )
break;
V_125 -= V_118 -> V_121 ;
}
V_129 = V_128 - V_126 + 1 ;
V_112 = F_72 ( V_124 , ( unsigned int ) V_129 ) ;
if ( ! V_112 )
return NULL ;
V_112 -> V_131 = V_123 -> V_131 ;
V_112 -> V_132 = V_123 -> V_132 + ( V_105 >> V_69 ) ;
V_112 -> V_133 = V_123 -> V_133 ;
V_112 -> V_134 |= 1 << V_135 ;
memcpy ( & V_112 -> V_136 [ 0 ] , & V_123 -> V_136 [ V_126 ] ,
V_129 * sizeof ( struct V_117 ) ) ;
V_112 -> V_136 [ 0 ] . V_137 += V_127 ;
if ( V_129 > 1 ) {
V_112 -> V_136 [ 0 ] . V_121 -= V_127 ;
V_112 -> V_136 [ V_129 - 1 ] . V_121 = V_125 ;
} else {
V_112 -> V_136 [ 0 ] . V_121 = V_77 ;
}
V_112 -> V_138 = V_129 ;
V_112 -> V_130 = V_77 ;
V_112 -> V_139 = 0 ;
return V_112 ;
}
static struct V_112 * F_73 ( struct V_112 * * V_123 ,
unsigned int * V_105 ,
unsigned int V_77 ,
T_5 V_124 )
{
struct V_112 * V_140 = * V_123 ;
unsigned int V_141 = * V_105 ;
struct V_112 * V_113 = NULL ;
struct V_112 * * V_142 ;
if ( ! V_140 || V_141 >= V_140 -> V_130 || ! V_77 )
return NULL ;
V_142 = & V_113 ;
while ( V_77 ) {
unsigned int V_130 ;
struct V_112 * V_112 ;
if ( ! V_140 ) {
F_74 ( NULL , L_12 , V_77 ) ;
goto V_38;
}
V_130 = F_75 (unsigned int, bi->bi_size - off, len) ;
V_112 = F_68 ( V_140 , V_141 , V_130 , V_124 ) ;
if ( ! V_112 )
goto V_38;
* V_142 = V_112 ;
V_142 = & V_112 -> V_115 ;
V_141 += V_130 ;
if ( V_141 == V_140 -> V_130 ) {
V_140 = V_140 -> V_115 ;
V_141 = 0 ;
}
V_77 -= V_130 ;
}
* V_123 = V_140 ;
* V_105 = V_141 ;
return V_113 ;
V_38:
F_61 ( V_113 ) ;
return NULL ;
}
static void F_76 ( struct V_143 * V_144 )
{
F_14 ( L_13 , V_31 , V_144 ,
F_77 ( & V_144 -> V_34 . V_145 ) ) ;
F_31 ( & V_144 -> V_34 ) ;
}
static void F_78 ( struct V_143 * V_144 )
{
F_11 ( V_144 != NULL ) ;
F_14 ( L_13 , V_31 , V_144 ,
F_77 ( & V_144 -> V_34 . V_145 ) ) ;
F_41 ( & V_144 -> V_34 , V_146 ) ;
}
static void F_79 ( struct V_147 * V_148 )
{
F_14 ( L_14 , V_31 , V_148 ,
F_77 ( & V_148 -> V_34 . V_145 ) ) ;
F_31 ( & V_148 -> V_34 ) ;
}
static void F_80 ( struct V_147 * V_148 )
{
F_11 ( V_148 != NULL ) ;
F_14 ( L_14 , V_31 , V_148 ,
F_77 ( & V_148 -> V_34 . V_145 ) ) ;
F_41 ( & V_148 -> V_34 , V_149 ) ;
}
static inline void F_81 ( struct V_147 * V_148 ,
struct V_143 * V_144 )
{
F_11 ( V_144 -> V_148 == NULL ) ;
F_76 ( V_144 ) ;
V_144 -> V_148 = V_148 ;
V_144 -> V_150 = V_148 -> V_151 ;
F_11 ( V_144 -> V_150 != V_152 ) ;
V_148 -> V_151 ++ ;
F_22 ( & V_144 -> V_153 , & V_148 -> V_154 ) ;
F_14 ( L_15 , V_31 , V_148 , V_144 ,
V_144 -> V_150 ) ;
}
static inline void F_82 ( struct V_147 * V_148 ,
struct V_143 * V_144 )
{
F_11 ( V_144 -> V_150 != V_152 ) ;
F_14 ( L_15 , V_31 , V_148 , V_144 ,
V_144 -> V_150 ) ;
F_39 ( & V_144 -> V_153 ) ;
F_11 ( V_148 -> V_151 > 0 ) ;
V_148 -> V_151 -- ;
F_11 ( V_144 -> V_150 == V_148 -> V_151 ) ;
V_144 -> V_150 = V_152 ;
F_11 ( V_144 -> V_148 == V_148 ) ;
V_144 -> V_148 = NULL ;
V_144 -> V_155 = NULL ;
F_78 ( V_144 ) ;
}
static bool F_83 ( enum V_156 type )
{
switch ( type ) {
case V_157 :
case V_158 :
case V_159 :
return true ;
default:
return false ;
}
}
static struct V_160 * F_84 ( T_6 V_161 , ... )
{
struct V_160 * V_162 ;
T_7 args ;
T_4 V_63 ;
V_162 = F_49 ( sizeof ( * V_162 ) , V_108 ) ;
if ( ! V_162 )
return NULL ;
V_162 -> V_162 = V_161 ;
va_start ( args , V_161 ) ;
switch ( V_161 ) {
case V_163 :
case V_164 :
V_162 -> V_165 . V_105 = va_arg ( args , V_73 ) ;
V_162 -> V_165 . V_110 = va_arg ( args , V_73 ) ;
if ( V_161 == V_164 )
V_162 -> V_166 = V_162 -> V_165 . V_110 ;
break;
case V_167 :
break;
case V_168 :
V_162 -> V_169 . V_170 = va_arg ( args , char * ) ;
V_63 = strlen ( V_162 -> V_169 . V_170 ) ;
F_11 ( V_63 <= ( T_4 ) V_171 ) ;
V_162 -> V_169 . V_172 = V_63 ;
V_162 -> V_166 = V_63 ;
V_162 -> V_169 . V_173 = va_arg ( args , char * ) ;
V_63 = strlen ( V_162 -> V_169 . V_173 ) ;
F_11 ( V_63 <= ( T_4 ) V_171 ) ;
V_162 -> V_169 . V_174 = V_63 ;
V_162 -> V_166 += V_63 ;
V_162 -> V_169 . V_175 = 0 ;
V_162 -> V_169 . V_176 = va_arg ( args , void * ) ;
V_63 = va_arg ( args , T_4 ) ;
F_11 ( V_63 <= ( T_4 ) V_177 ) ;
V_162 -> V_169 . V_178 = ( T_3 ) V_63 ;
V_162 -> V_166 += V_63 ;
break;
case V_179 :
case V_180 :
V_162 -> V_181 . V_182 = va_arg ( args , V_73 ) ;
V_162 -> V_181 . V_183 = va_arg ( args , V_73 ) ;
V_162 -> V_181 . V_183 = F_85 ( V_162 -> V_181 . V_183 ) ;
if ( V_161 == V_180 && va_arg ( args , int ) )
V_162 -> V_181 . V_184 = ( V_185 ) 1 ;
break;
default:
F_74 ( NULL , L_16 , V_161 ) ;
F_25 ( V_162 ) ;
V_162 = NULL ;
break;
}
va_end ( args ) ;
return V_162 ;
}
static void F_86 ( struct V_160 * V_162 )
{
F_25 ( V_162 ) ;
}
static int F_87 ( struct V_186 * V_187 ,
struct V_143 * V_144 )
{
F_14 ( L_17 , V_31 , V_187 , V_144 ) ;
return F_88 ( V_187 , V_144 -> V_188 , false ) ;
}
static void F_89 ( struct V_147 * V_148 )
{
F_14 ( L_18 , V_31 , V_148 ) ;
if ( V_148 -> V_155 )
V_148 -> V_155 ( V_148 ) ;
else
F_80 ( V_148 ) ;
}
static int F_90 ( struct V_143 * V_144 )
{
F_14 ( L_19 , V_31 , V_144 ) ;
return F_91 ( & V_144 -> V_189 ) ;
}
static void F_92 ( struct V_143 * V_144 )
{
F_50 ( & V_144 -> V_103 , 0 ) ;
F_93 () ;
}
static void F_94 ( struct V_143 * V_144 )
{
int V_103 ;
V_103 = F_95 ( & V_144 -> V_103 ) ;
if ( V_103 > 1 ) {
struct V_147 * V_148 = V_144 -> V_148 ;
struct V_6 * V_7 ;
V_7 = V_148 ? V_148 -> V_7 : NULL ;
F_74 ( V_7 , L_20 ,
V_144 ) ;
}
}
static bool F_96 ( struct V_143 * V_144 )
{
F_97 () ;
return F_77 ( & V_144 -> V_103 ) != 0 ;
}
static void
F_98 ( struct V_143 * V_144 )
{
F_14 ( L_21 , V_31 ,
V_144 , V_144 -> V_148 , V_144 -> V_190 ,
V_144 -> V_191 , V_144 -> V_110 ) ;
F_99 ( V_144 -> type != V_158 ) ;
if ( V_144 -> V_190 == - V_19 ) {
F_63 ( V_144 -> V_192 , 0 ) ;
V_144 -> V_190 = 0 ;
V_144 -> V_191 = V_144 -> V_110 ;
} else if ( V_144 -> V_191 < V_144 -> V_110 &&
! V_144 -> V_190 ) {
F_63 ( V_144 -> V_192 , V_144 -> V_191 ) ;
V_144 -> V_191 = V_144 -> V_110 ;
}
F_94 ( V_144 ) ;
}
static void F_100 ( struct V_143 * V_144 )
{
F_14 ( L_22 , V_31 , V_144 ,
V_144 -> V_155 ) ;
if ( V_144 -> V_155 )
V_144 -> V_155 ( V_144 ) ;
else
F_101 ( & V_144 -> V_189 ) ;
}
static void F_102 ( struct V_143 * V_144 )
{
F_14 ( L_19 , V_31 , V_144 ) ;
F_94 ( V_144 ) ;
}
static void F_103 ( struct V_143 * V_144 )
{
F_14 ( L_23 , V_31 , V_144 ,
V_144 -> V_190 , V_144 -> V_191 , V_144 -> V_110 ) ;
if ( V_144 -> V_148 )
F_98 ( V_144 ) ;
else
F_94 ( V_144 ) ;
}
static void F_104 ( struct V_143 * V_144 )
{
F_14 ( L_24 , V_31 , V_144 ,
V_144 -> V_190 , V_144 -> V_110 ) ;
V_144 -> V_191 = V_144 -> V_110 ;
F_94 ( V_144 ) ;
}
static void F_105 ( struct V_143 * V_144 )
{
F_14 ( L_19 , V_31 , V_144 ) ;
F_94 ( V_144 ) ;
}
static void F_106 ( struct V_193 * V_188 ,
struct V_194 * V_195 )
{
struct V_143 * V_144 = V_188 -> V_196 ;
T_6 V_161 ;
F_14 ( L_25 , V_31 , V_188 , V_195 ) ;
F_11 ( V_188 == V_144 -> V_188 ) ;
F_11 ( ! ! V_144 -> V_148 ^
( V_144 -> V_150 == V_152 ) ) ;
if ( V_188 -> V_197 < 0 )
V_144 -> V_190 = V_188 -> V_197 ;
V_144 -> V_198 = F_45 ( V_188 -> V_199 . V_198 ) ;
F_48 ( V_188 -> V_200 != 1 ) ;
V_144 -> V_191 = V_188 -> V_201 [ 0 ] ;
F_11 ( V_144 -> V_191 < ( V_73 ) V_202 ) ;
V_161 = V_188 -> V_203 [ 0 ] . V_162 ;
switch ( V_161 ) {
case V_163 :
F_103 ( V_144 ) ;
break;
case V_164 :
F_104 ( V_144 ) ;
break;
case V_167 :
F_105 ( V_144 ) ;
break;
case V_168 :
case V_179 :
case V_180 :
F_102 ( V_144 ) ;
break;
default:
F_74 ( NULL , L_26 ,
V_144 -> V_204 , ( unsigned short ) V_161 ) ;
break;
}
if ( F_96 ( V_144 ) )
F_100 ( V_144 ) ;
}
static struct V_193 * F_107 (
struct V_6 * V_7 ,
bool V_205 ,
struct V_143 * V_144 ,
struct V_160 * V_162 )
{
struct V_147 * V_148 = V_144 -> V_148 ;
struct V_71 * V_89 = NULL ;
struct V_186 * V_187 ;
struct V_193 * V_188 ;
struct V_206 V_207 ;
struct V_206 * V_208 ;
V_73 V_95 = V_98 ;
V_73 V_105 = V_144 -> V_105 ;
V_73 V_110 = V_144 -> V_110 ;
if ( V_148 ) {
F_11 ( V_148 -> V_205 == V_205 ) ;
if ( V_148 -> V_205 )
V_89 = V_148 -> V_89 ;
else
V_95 = V_148 -> V_95 ;
}
V_187 = & V_7 -> V_25 -> V_36 -> V_187 ;
V_188 = F_108 ( V_187 , V_89 , 1 , false , V_209 ) ;
if ( ! V_188 )
return NULL ;
F_11 ( F_83 ( V_144 -> type ) ) ;
switch ( V_144 -> type ) {
case V_157 :
break;
case V_158 :
F_11 ( V_144 -> V_192 != NULL ) ;
V_188 -> V_210 = V_144 -> V_192 ;
break;
case V_159 :
V_188 -> V_211 = V_144 -> V_212 ;
V_188 -> V_213 = V_144 -> V_214 ;
V_188 -> V_215 = V_105 & ~ V_216 ;
break;
}
if ( V_205 ) {
V_188 -> V_217 = V_218 | V_219 ;
V_207 = V_220 ;
V_208 = & V_207 ;
} else {
V_188 -> V_217 = V_221 ;
V_208 = NULL ;
V_105 = 0 ;
V_110 = 0 ;
}
V_188 -> V_222 = F_106 ;
V_188 -> V_196 = V_144 ;
V_188 -> V_223 = strlen ( V_144 -> V_204 ) ;
F_11 ( V_188 -> V_223 < sizeof ( V_188 -> V_224 ) ) ;
memcpy ( V_188 -> V_224 , V_144 -> V_204 , V_188 -> V_223 ) ;
V_188 -> V_225 = V_7 -> V_226 ;
F_109 ( V_188 , V_105 , V_110 , 1 , V_162 ,
V_89 , V_95 , V_208 ) ;
return V_188 ;
}
static void F_110 ( struct V_193 * V_188 )
{
F_111 ( V_188 ) ;
}
static struct V_143 * F_112 ( const char * V_204 ,
V_73 V_105 , V_73 V_110 ,
enum V_156 type )
{
struct V_143 * V_144 ;
T_4 V_63 ;
char * V_100 ;
F_11 ( F_83 ( type ) ) ;
V_63 = strlen ( V_204 ) + 1 ;
V_144 = F_49 ( sizeof ( * V_144 ) + V_63 , V_32 ) ;
if ( ! V_144 )
return NULL ;
V_100 = ( char * ) ( V_144 + 1 ) ;
V_144 -> V_204 = memcpy ( V_100 , V_204 , V_63 ) ;
V_144 -> V_105 = V_105 ;
V_144 -> V_110 = V_110 ;
V_144 -> V_150 = V_152 ;
V_144 -> type = type ;
F_17 ( & V_144 -> V_153 ) ;
F_92 ( V_144 ) ;
F_113 ( & V_144 -> V_189 ) ;
F_16 ( & V_144 -> V_34 ) ;
F_14 ( L_27 , V_31 , V_204 ,
V_105 , V_110 , ( int ) type , V_144 ) ;
return V_144 ;
}
static void V_146 ( struct V_34 * V_34 )
{
struct V_143 * V_144 ;
V_144 = F_38 ( V_34 , struct V_143 , V_34 ) ;
F_14 ( L_19 , V_31 , V_144 ) ;
F_11 ( V_144 -> V_148 == NULL ) ;
F_11 ( V_144 -> V_150 == V_152 ) ;
if ( V_144 -> V_188 )
F_110 ( V_144 -> V_188 ) ;
F_11 ( F_83 ( V_144 -> type ) ) ;
switch ( V_144 -> type ) {
case V_157 :
break;
case V_158 :
if ( V_144 -> V_192 )
F_61 ( V_144 -> V_192 ) ;
break;
case V_159 :
if ( V_144 -> V_212 )
F_114 ( V_144 -> V_212 ,
V_144 -> V_214 ) ;
break;
}
F_25 ( V_144 ) ;
}
static struct V_147 * F_115 (
struct V_6 * V_7 ,
V_73 V_105 , V_73 V_110 ,
bool V_205 )
{
struct V_147 * V_148 ;
struct V_71 * V_89 = NULL ;
V_148 = F_15 ( sizeof ( * V_148 ) , V_209 ) ;
if ( ! V_148 )
return NULL ;
if ( V_205 ) {
F_116 ( & V_7 -> V_227 ) ;
V_89 = F_117 ( V_7 -> V_76 . V_89 ) ;
F_118 ( & V_7 -> V_227 ) ;
if ( F_48 ( ! V_89 ) ) {
F_25 ( V_148 ) ;
return NULL ;
}
}
V_148 -> V_228 = NULL ;
V_148 -> V_7 = V_7 ;
V_148 -> V_105 = V_105 ;
V_148 -> V_110 = V_110 ;
V_148 -> V_205 = V_205 ;
if ( V_205 )
V_148 -> V_89 = V_89 ;
else
V_148 -> V_95 = V_7 -> V_102 -> V_95 ;
F_119 ( & V_148 -> V_229 ) ;
V_148 -> V_230 = 0 ;
V_148 -> V_155 = NULL ;
V_148 -> V_151 = 0 ;
F_17 ( & V_148 -> V_154 ) ;
F_16 ( & V_148 -> V_34 ) ;
F_79 ( V_148 ) ;
F_80 ( V_148 ) ;
F_14 ( L_28 , V_31 , V_7 ,
V_205 ? L_29 : L_30 , V_105 , V_110 ,
V_148 ) ;
return V_148 ;
}
static void V_149 ( struct V_34 * V_34 )
{
struct V_147 * V_148 ;
struct V_143 * V_144 ;
struct V_143 * V_231 ;
V_148 = F_38 ( V_34 , struct V_147 , V_34 ) ;
F_14 ( L_18 , V_31 , V_148 ) ;
F_120 (img_request, obj_request, next_obj_request)
F_82 ( V_148 , V_144 ) ;
F_11 ( V_148 -> V_151 == 0 ) ;
if ( V_148 -> V_205 )
F_56 ( V_148 -> V_89 ) ;
F_25 ( V_148 ) ;
}
static int F_121 ( struct V_147 * V_148 ,
struct V_112 * V_192 )
{
struct V_6 * V_7 = V_148 -> V_7 ;
struct V_143 * V_144 = NULL ;
struct V_143 * V_231 ;
unsigned int V_232 ;
V_73 V_233 ;
V_73 V_125 ;
T_6 V_161 ;
F_14 ( L_31 , V_31 , V_148 , V_192 ) ;
V_161 = V_148 -> V_205 ? V_164
: V_163 ;
V_232 = 0 ;
V_233 = V_148 -> V_105 ;
F_11 ( V_233 == V_192 -> V_132 << V_69 ) ;
V_125 = V_148 -> V_110 ;
F_11 ( V_125 > 0 ) ;
while ( V_125 ) {
const char * V_204 ;
unsigned int V_234 ;
struct V_160 * V_162 ;
V_73 V_105 ;
V_73 V_110 ;
V_204 = F_57 ( V_7 , V_233 ) ;
if ( ! V_204 )
goto V_235;
V_105 = F_58 ( V_7 , V_233 ) ;
V_110 = F_59 ( V_7 , V_233 , V_125 ) ;
V_144 = F_112 ( V_204 ,
V_105 , V_110 ,
V_158 ) ;
F_25 ( V_204 ) ;
if ( ! V_144 )
goto V_235;
F_11 ( V_110 <= ( V_73 ) V_202 ) ;
V_234 = ( unsigned int ) V_110 ;
V_144 -> V_192 = F_73 ( & V_192 ,
& V_232 , V_234 ,
V_209 ) ;
if ( ! V_144 -> V_192 )
goto V_236;
V_162 = F_84 ( V_161 , V_105 , V_110 ) ;
if ( ! V_162 )
goto V_236;
V_144 -> V_188 = F_107 ( V_7 ,
V_148 -> V_205 ,
V_144 , V_162 ) ;
F_86 ( V_162 ) ;
if ( ! V_144 -> V_188 )
goto V_236;
F_81 ( V_148 , V_144 ) ;
V_233 += V_110 ;
V_125 -= V_110 ;
}
return 0 ;
V_236:
F_78 ( V_144 ) ;
V_235:
F_120 (img_request, obj_request, next_obj_request)
F_78 ( V_144 ) ;
return - V_30 ;
}
static void F_122 ( struct V_143 * V_144 )
{
struct V_147 * V_148 ;
T_3 V_150 = V_144 -> V_150 ;
bool V_237 = true ;
V_148 = V_144 -> V_148 ;
F_14 ( L_32 , V_31 , V_148 , V_144 ) ;
F_11 ( V_148 != NULL ) ;
F_11 ( V_148 -> V_228 != NULL ) ;
F_11 ( V_148 -> V_151 > 0 ) ;
F_11 ( V_150 != V_152 ) ;
F_11 ( V_150 < V_148 -> V_151 ) ;
F_11 ( V_150 >= V_148 -> V_230 ) ;
F_3 ( & V_148 -> V_229 ) ;
if ( V_150 != V_148 -> V_230 )
goto V_238;
F_123 (img_request, obj_request) {
unsigned int V_191 ;
int V_190 ;
F_11 ( V_237 ) ;
F_11 ( V_150 < V_148 -> V_151 ) ;
if ( ! F_96 ( V_144 ) )
break;
F_11 ( V_144 -> V_191 <= ( V_73 ) V_202 ) ;
V_191 = ( unsigned int ) V_144 -> V_191 ;
V_190 = ( int ) V_144 -> V_190 ;
if ( V_190 )
F_74 ( NULL , L_33 ,
V_148 -> V_205 ? L_29 : L_30 ,
V_190 , V_191 ) ;
V_237 = F_124 ( V_148 -> V_228 , V_190 , V_191 ) ;
V_150 ++ ;
}
F_11 ( V_237 ^ ( V_150 == V_148 -> V_151 ) ) ;
V_148 -> V_230 = V_150 ;
V_238:
F_5 ( & V_148 -> V_229 ) ;
if ( ! V_237 )
F_89 ( V_148 ) ;
}
static int F_125 ( struct V_147 * V_148 )
{
struct V_6 * V_7 = V_148 -> V_7 ;
struct V_186 * V_187 = & V_7 -> V_25 -> V_36 -> V_187 ;
struct V_143 * V_144 ;
struct V_143 * V_231 ;
F_14 ( L_18 , V_31 , V_148 ) ;
F_120 (img_request, obj_request, next_obj_request) {
int V_29 ;
V_144 -> V_155 = F_122 ;
V_29 = F_87 ( V_187 , V_144 ) ;
if ( V_29 )
return V_29 ;
F_78 ( V_144 ) ;
}
return 0 ;
}
static int F_126 ( struct V_6 * V_7 ,
V_73 V_183 , V_73 V_239 )
{
struct V_143 * V_144 ;
struct V_160 * V_162 ;
struct V_186 * V_187 ;
int V_29 ;
V_144 = F_112 ( V_7 -> V_240 , 0 , 0 ,
V_157 ) ;
if ( ! V_144 )
return - V_30 ;
V_29 = - V_30 ;
V_162 = F_84 ( V_179 , V_239 , V_183 ) ;
if ( ! V_162 )
goto V_238;
V_144 -> V_188 = F_107 ( V_7 , false ,
V_144 , V_162 ) ;
F_86 ( V_162 ) ;
if ( ! V_144 -> V_188 )
goto V_238;
V_187 = & V_7 -> V_25 -> V_36 -> V_187 ;
V_144 -> V_155 = F_78 ;
V_29 = F_87 ( V_187 , V_144 ) ;
V_238:
if ( V_29 )
F_78 ( V_144 ) ;
return V_29 ;
}
static void F_127 ( V_73 V_183 , V_73 V_239 , V_185 V_161 , void * V_241 )
{
struct V_6 * V_7 = (struct V_6 * ) V_241 ;
V_73 V_242 ;
int V_243 ;
if ( ! V_7 )
return;
F_14 ( L_34 , V_31 ,
V_7 -> V_240 , ( unsigned long long ) V_239 ,
( unsigned int ) V_161 ) ;
V_243 = F_128 ( V_7 , & V_242 ) ;
if ( V_243 )
F_74 ( V_7 , L_35
L_36 , V_243 ) ;
F_126 ( V_7 , V_242 , V_239 ) ;
}
static int F_129 ( struct V_6 * V_7 , int V_244 )
{
struct V_186 * V_187 = & V_7 -> V_25 -> V_36 -> V_187 ;
struct V_143 * V_144 ;
struct V_160 * V_162 ;
int V_29 ;
F_11 ( V_244 ^ ! ! V_7 -> V_245 ) ;
F_11 ( V_244 ^ ! ! V_7 -> V_246 ) ;
if ( V_244 ) {
V_29 = F_130 ( V_187 , F_127 , V_7 ,
& V_7 -> V_245 ) ;
if ( V_29 < 0 )
return V_29 ;
F_11 ( V_7 -> V_245 != NULL ) ;
}
V_29 = - V_30 ;
V_144 = F_112 ( V_7 -> V_240 , 0 , 0 ,
V_157 ) ;
if ( ! V_144 )
goto V_247;
V_162 = F_84 ( V_180 ,
V_7 -> V_245 -> V_182 ,
V_7 -> V_76 . V_248 , V_244 ) ;
if ( ! V_162 )
goto V_247;
V_144 -> V_188 = F_107 ( V_7 , true ,
V_144 , V_162 ) ;
F_86 ( V_162 ) ;
if ( ! V_144 -> V_188 )
goto V_247;
if ( V_244 )
F_131 ( V_187 , V_144 -> V_188 ) ;
else
F_132 ( V_187 ,
V_7 -> V_246 -> V_188 ) ;
V_29 = F_87 ( V_187 , V_144 ) ;
if ( V_29 )
goto V_247;
V_29 = F_90 ( V_144 ) ;
if ( V_29 )
goto V_247;
V_29 = V_144 -> V_190 ;
if ( V_29 )
goto V_247;
if ( V_244 ) {
V_7 -> V_246 = V_144 ;
return 0 ;
}
F_78 ( V_7 -> V_246 ) ;
V_7 -> V_246 = NULL ;
V_247:
F_133 ( V_7 -> V_245 ) ;
V_7 -> V_245 = NULL ;
if ( V_144 )
F_78 ( V_144 ) ;
return V_29 ;
}
static int F_134 ( struct V_6 * V_7 ,
const char * V_204 ,
const char * V_170 ,
const char * V_173 ,
const char * V_249 ,
T_4 V_250 ,
char * V_251 ,
T_4 V_252 ,
V_73 * V_198 )
{
struct V_143 * V_144 ;
struct V_186 * V_187 ;
struct V_160 * V_162 ;
struct V_253 * * V_212 ;
T_3 V_214 ;
int V_29 ;
V_214 = ( T_3 ) F_135 ( 0 , V_252 ) ;
V_212 = F_136 ( V_214 , V_32 ) ;
if ( F_19 ( V_212 ) )
return F_137 ( V_212 ) ;
V_29 = - V_30 ;
V_144 = F_112 ( V_204 , 0 , 0 ,
V_159 ) ;
if ( ! V_144 )
goto V_238;
V_144 -> V_212 = V_212 ;
V_144 -> V_214 = V_214 ;
V_162 = F_84 ( V_168 , V_170 ,
V_173 , V_249 , V_250 ) ;
if ( ! V_162 )
goto V_238;
V_144 -> V_188 = F_107 ( V_7 , false ,
V_144 , V_162 ) ;
F_86 ( V_162 ) ;
if ( ! V_144 -> V_188 )
goto V_238;
V_187 = & V_7 -> V_25 -> V_36 -> V_187 ;
V_29 = F_87 ( V_187 , V_144 ) ;
if ( V_29 )
goto V_238;
V_29 = F_90 ( V_144 ) ;
if ( V_29 )
goto V_238;
V_29 = V_144 -> V_190 ;
if ( V_29 < 0 )
goto V_238;
V_29 = 0 ;
F_138 ( V_212 , V_251 , 0 , V_144 -> V_191 ) ;
if ( V_198 )
* V_198 = V_144 -> V_198 ;
V_238:
if ( V_144 )
F_78 ( V_144 ) ;
else
F_114 ( V_212 , V_214 ) ;
return V_29 ;
}
static void F_139 ( struct V_254 * V_255 )
__releases( V_255 -> V_256 ) __acquires( V_255 -> V_256 )
{
struct V_6 * V_7 = V_255 -> V_257 ;
bool V_13 = V_7 -> V_12 . V_13 ;
struct V_258 * V_228 ;
int V_190 ;
while ( ( V_228 = F_140 ( V_255 ) ) ) {
bool V_205 = F_141 ( V_228 ) == V_259 ;
struct V_147 * V_148 ;
V_73 V_105 ;
V_73 V_110 ;
if ( V_228 -> V_260 != V_261 ) {
F_14 ( L_37 , V_31 ,
( int ) V_228 -> V_260 ) ;
F_142 ( V_228 , 0 ) ;
continue;
}
V_105 = ( V_73 ) F_143 ( V_228 ) << V_69 ;
V_110 = ( V_73 ) F_144 ( V_228 ) ;
if ( ! V_110 ) {
F_14 ( L_38 , V_31 ) ;
F_142 ( V_228 , 0 ) ;
continue;
}
F_5 ( V_255 -> V_256 ) ;
if ( V_205 ) {
V_190 = - V_14 ;
if ( V_13 )
goto V_262;
F_11 ( V_7 -> V_102 -> V_95 == V_98 ) ;
}
if ( ! F_4 ( V_104 , & V_7 -> V_17 ) ) {
F_14 ( L_39 ) ;
F_11 ( V_7 -> V_102 -> V_95 != V_98 ) ;
V_190 = - V_263 ;
goto V_262;
}
V_190 = - V_53 ;
if ( F_48 ( V_105 && V_110 > V_111 - V_105 + 1 ) )
goto V_262;
V_190 = - V_30 ;
V_148 = F_115 ( V_7 , V_105 , V_110 ,
V_205 ) ;
if ( ! V_148 )
goto V_262;
V_148 -> V_228 = V_228 ;
V_190 = F_121 ( V_148 , V_228 -> V_112 ) ;
if ( ! V_190 )
V_190 = F_125 ( V_148 ) ;
if ( V_190 )
F_80 ( V_148 ) ;
V_262:
F_3 ( V_255 -> V_256 ) ;
if ( V_190 < 0 ) {
F_74 ( V_7 , L_40 ,
V_205 ? L_29 : L_30 , V_190 ) ;
F_142 ( V_228 , V_190 ) ;
}
}
}
static int F_145 ( struct V_254 * V_255 , struct V_264 * V_265 ,
struct V_117 * V_266 )
{
struct V_6 * V_7 = V_255 -> V_257 ;
T_8 V_267 ;
T_8 V_268 ;
T_8 V_269 ;
int V_29 ;
V_267 = F_146 ( V_265 -> V_131 ) + V_265 -> V_132 ;
V_268 = 1 << ( V_7 -> V_76 . V_86 - V_69 ) ;
V_269 = V_267 & ( V_268 - 1 ) ;
V_29 = ( int ) ( V_268 - V_269 ) << V_69 ;
if ( V_29 > V_265 -> V_130 )
V_29 -= V_265 -> V_130 ;
else
V_29 = 0 ;
F_11 ( V_266 -> V_121 <= V_270 ) ;
if ( V_29 > ( int ) V_266 -> V_121 || ! V_265 -> V_130 )
V_29 = ( int ) V_266 -> V_121 ;
return V_29 ;
}
static void F_147 ( struct V_6 * V_7 )
{
struct V_22 * V_23 = V_7 -> V_23 ;
if ( ! V_23 )
return;
if ( V_23 -> V_17 & V_271 )
F_148 ( V_23 ) ;
if ( V_23 -> V_272 )
F_149 ( V_23 -> V_272 ) ;
F_150 ( V_23 ) ;
}
static int F_151 ( struct V_6 * V_7 ,
const char * V_204 ,
V_73 V_105 , V_73 V_110 ,
char * V_119 , V_73 * V_198 )
{
struct V_160 * V_162 ;
struct V_143 * V_144 ;
struct V_186 * V_187 ;
struct V_253 * * V_212 = NULL ;
T_3 V_214 ;
T_4 V_63 ;
int V_29 ;
V_214 = ( T_3 ) F_135 ( V_105 , V_110 ) ;
V_212 = F_136 ( V_214 , V_32 ) ;
if ( F_19 ( V_212 ) )
V_29 = F_137 ( V_212 ) ;
V_29 = - V_30 ;
V_144 = F_112 ( V_204 , V_105 , V_110 ,
V_159 ) ;
if ( ! V_144 )
goto V_238;
V_144 -> V_212 = V_212 ;
V_144 -> V_214 = V_214 ;
V_162 = F_84 ( V_163 , V_105 , V_110 ) ;
if ( ! V_162 )
goto V_238;
V_144 -> V_188 = F_107 ( V_7 , false ,
V_144 , V_162 ) ;
F_86 ( V_162 ) ;
if ( ! V_144 -> V_188 )
goto V_238;
V_187 = & V_7 -> V_25 -> V_36 -> V_187 ;
V_29 = F_87 ( V_187 , V_144 ) ;
if ( V_29 )
goto V_238;
V_29 = F_90 ( V_144 ) ;
if ( V_29 )
goto V_238;
V_29 = V_144 -> V_190 ;
if ( V_29 < 0 )
goto V_238;
F_11 ( V_144 -> V_191 <= ( V_73 ) V_70 ) ;
V_63 = ( T_4 ) V_144 -> V_191 ;
F_138 ( V_212 , V_119 , 0 , V_63 ) ;
F_11 ( V_63 <= ( T_4 ) V_273 ) ;
V_29 = ( int ) V_63 ;
if ( V_198 )
* V_198 = V_144 -> V_198 ;
V_238:
if ( V_144 )
F_78 ( V_144 ) ;
else
F_114 ( V_212 , V_214 ) ;
return V_29 ;
}
static struct V_61 *
F_152 ( struct V_6 * V_7 , V_73 * V_198 )
{
struct V_61 * V_62 = NULL ;
T_3 V_64 = 0 ;
V_73 V_274 = 0 ;
T_3 V_275 ;
int V_29 ;
do {
T_4 V_63 ;
F_25 ( V_62 ) ;
V_63 = sizeof ( * V_62 ) ;
V_63 += V_64 * sizeof ( struct V_276 ) ;
V_63 += V_274 ;
V_62 = F_15 ( V_63 , V_32 ) ;
if ( ! V_62 )
return F_27 ( - V_30 ) ;
V_29 = F_151 ( V_7 , V_7 -> V_240 ,
0 , V_63 ,
( char * ) V_62 , V_198 ) ;
if ( V_29 < 0 )
goto V_38;
if ( F_48 ( ( T_4 ) V_29 < V_63 ) ) {
V_29 = - V_263 ;
F_74 ( V_7 , L_41 ,
V_63 , V_29 ) ;
goto V_38;
}
if ( ! F_43 ( V_62 ) ) {
V_29 = - V_263 ;
F_74 ( V_7 , L_42 ) ;
goto V_38;
}
V_274 = F_45 ( V_62 -> V_74 ) ;
V_275 = V_64 ;
V_64 = F_44 ( V_62 -> V_64 ) ;
} while ( V_64 != V_275 );
return V_62 ;
V_38:
F_25 ( V_62 ) ;
return F_27 ( V_29 ) ;
}
static int F_153 ( struct V_6 * V_7 ,
struct V_75 * V_76 )
{
struct V_61 * V_62 ;
V_73 V_183 = 0 ;
int V_29 ;
V_62 = F_152 ( V_7 , & V_183 ) ;
if ( F_19 ( V_62 ) )
return F_137 ( V_62 ) ;
V_29 = F_46 ( V_76 , V_62 ) ;
if ( V_29 >= 0 )
V_76 -> V_248 = V_183 ;
F_25 ( V_62 ) ;
return V_29 ;
}
static void F_154 ( struct V_6 * V_7 )
{
struct V_96 * V_97 ;
struct V_96 * V_277 ;
F_155 (snap, next, &rbd_dev->snaps, node)
F_156 ( V_97 ) ;
}
static void F_157 ( struct V_6 * V_7 )
{
T_8 V_63 ;
if ( V_7 -> V_102 -> V_95 != V_98 )
return;
V_63 = ( T_8 ) V_7 -> V_76 . V_84 / V_278 ;
F_14 ( L_43 , ( unsigned long long ) V_63 ) ;
V_7 -> V_12 . V_63 = ( V_73 ) V_63 ;
F_158 ( V_7 -> V_23 , V_63 ) ;
}
static int F_159 ( struct V_6 * V_7 , V_73 * V_242 )
{
int V_29 ;
struct V_75 V_279 ;
V_29 = F_153 ( V_7 , & V_279 ) ;
if ( V_29 < 0 )
return V_29 ;
F_160 ( & V_7 -> V_227 ) ;
V_7 -> V_76 . V_84 = V_279 . V_84 ;
F_157 ( V_7 ) ;
F_25 ( V_7 -> V_76 . V_83 ) ;
F_25 ( V_7 -> V_76 . V_81 ) ;
F_56 ( V_7 -> V_76 . V_89 ) ;
if ( V_242 )
* V_242 = V_279 . V_248 ;
V_7 -> V_76 . V_248 = V_279 . V_248 ;
V_7 -> V_76 . V_84 = V_279 . V_84 ;
V_7 -> V_76 . V_89 = V_279 . V_89 ;
V_7 -> V_76 . V_81 = V_279 . V_81 ;
V_7 -> V_76 . V_83 = V_279 . V_83 ;
F_48 ( strcmp ( V_7 -> V_76 . V_79 , V_279 . V_79 ) ) ;
F_25 ( V_279 . V_79 ) ;
V_29 = F_161 ( V_7 ) ;
if ( ! V_29 )
V_29 = F_162 ( V_7 ) ;
F_163 ( & V_7 -> V_227 ) ;
return V_29 ;
}
static int F_128 ( struct V_6 * V_7 , V_73 * V_242 )
{
int V_29 ;
F_11 ( F_42 ( V_7 -> V_60 ) ) ;
F_6 ( & V_20 , V_21 ) ;
if ( V_7 -> V_60 == 1 )
V_29 = F_159 ( V_7 , V_242 ) ;
else
V_29 = F_164 ( V_7 , V_242 ) ;
F_9 ( & V_20 ) ;
return V_29 ;
}
static int F_165 ( struct V_6 * V_7 )
{
struct V_22 * V_23 ;
struct V_254 * V_255 ;
V_73 V_109 ;
V_23 = F_166 ( V_280 ) ;
if ( ! V_23 )
return - V_30 ;
snprintf ( V_23 -> V_281 , sizeof( V_23 -> V_281 ) , V_282 L_44 ,
V_7 -> V_283 ) ;
V_23 -> V_284 = V_7 -> V_284 ;
V_23 -> V_285 = 0 ;
V_23 -> V_286 = & V_287 ;
V_23 -> V_9 = V_7 ;
V_255 = F_167 ( F_139 , & V_7 -> V_15 ) ;
if ( ! V_255 )
goto V_288;
F_168 ( V_255 , V_278 ) ;
V_109 = F_60 ( & V_7 -> V_76 ) ;
F_169 ( V_255 , V_109 / V_278 ) ;
F_170 ( V_255 , V_109 ) ;
F_171 ( V_255 , V_109 ) ;
F_172 ( V_255 , V_109 ) ;
F_173 ( V_255 , F_145 ) ;
V_23 -> V_272 = V_255 ;
V_255 -> V_257 = V_7 ;
V_7 -> V_23 = V_23 ;
F_158 ( V_7 -> V_23 , V_7 -> V_12 . V_63 / V_278 ) ;
return 0 ;
V_288:
F_150 ( V_23 ) ;
return - V_30 ;
}
static struct V_6 * F_174 ( struct V_1 * V_2 )
{
return F_38 ( V_2 , struct V_6 , V_2 ) ;
}
static T_9 F_175 ( struct V_1 * V_2 ,
struct V_289 * V_290 , char * V_119 )
{
struct V_6 * V_7 = F_174 ( V_2 ) ;
T_8 V_63 ;
F_116 ( & V_7 -> V_227 ) ;
V_63 = F_176 ( V_7 -> V_23 ) ;
F_118 ( & V_7 -> V_227 ) ;
return sprintf ( V_119 , L_45 , ( unsigned long long ) V_63 * V_278 ) ;
}
static T_9 F_177 ( struct V_1 * V_2 ,
struct V_289 * V_290 , char * V_119 )
{
struct V_6 * V_7 = F_174 ( V_2 ) ;
return sprintf ( V_119 , L_46 ,
( unsigned long long ) V_7 -> V_12 . V_85 ) ;
}
static T_9 F_178 ( struct V_1 * V_2 ,
struct V_289 * V_290 , char * V_119 )
{
struct V_6 * V_7 = F_174 ( V_2 ) ;
return sprintf ( V_119 , L_47 , V_7 -> V_284 ) ;
}
static T_9 F_179 ( struct V_1 * V_2 ,
struct V_289 * V_290 , char * V_119 )
{
struct V_6 * V_7 = F_174 ( V_2 ) ;
return sprintf ( V_119 , L_48 ,
F_180 ( V_7 -> V_25 -> V_36 ) ) ;
}
static T_9 F_181 ( struct V_1 * V_2 ,
struct V_289 * V_290 , char * V_119 )
{
struct V_6 * V_7 = F_174 ( V_2 ) ;
return sprintf ( V_119 , L_49 , V_7 -> V_102 -> V_291 ) ;
}
static T_9 F_182 ( struct V_1 * V_2 ,
struct V_289 * V_290 , char * V_119 )
{
struct V_6 * V_7 = F_174 ( V_2 ) ;
return sprintf ( V_119 , L_45 ,
( unsigned long long ) V_7 -> V_102 -> V_292 ) ;
}
static T_9 F_183 ( struct V_1 * V_2 ,
struct V_289 * V_290 , char * V_119 )
{
struct V_6 * V_7 = F_174 ( V_2 ) ;
if ( V_7 -> V_102 -> V_293 )
return sprintf ( V_119 , L_49 , V_7 -> V_102 -> V_293 ) ;
return sprintf ( V_119 , L_50 ) ;
}
static T_9 F_184 ( struct V_1 * V_2 ,
struct V_289 * V_290 , char * V_119 )
{
struct V_6 * V_7 = F_174 ( V_2 ) ;
return sprintf ( V_119 , L_49 , V_7 -> V_102 -> V_294 ) ;
}
static T_9 F_185 ( struct V_1 * V_2 ,
struct V_289 * V_290 ,
char * V_119 )
{
struct V_6 * V_7 = F_174 ( V_2 ) ;
return sprintf ( V_119 , L_49 , V_7 -> V_102 -> V_101 ) ;
}
static T_9 F_186 ( struct V_1 * V_2 ,
struct V_289 * V_290 ,
char * V_119 )
{
struct V_6 * V_7 = F_174 ( V_2 ) ;
struct V_295 * V_102 = V_7 -> V_296 ;
int V_297 ;
char * V_298 = V_119 ;
if ( ! V_102 )
return sprintf ( V_119 , L_51 ) ;
V_297 = sprintf ( V_298 , L_52 ,
( unsigned long long ) V_102 -> V_292 , V_102 -> V_291 ) ;
if ( V_297 < 0 )
return V_297 ;
V_298 += V_297 ;
V_297 = sprintf ( V_298 , L_53 , V_102 -> V_294 ,
V_102 -> V_293 ? V_102 -> V_293 : L_54 ) ;
if ( V_297 < 0 )
return V_297 ;
V_298 += V_297 ;
V_297 = sprintf ( V_298 , L_55 ,
( unsigned long long ) V_102 -> V_95 , V_102 -> V_101 ) ;
if ( V_297 < 0 )
return V_297 ;
V_298 += V_297 ;
V_297 = sprintf ( V_298 , L_56 , V_7 -> V_299 ) ;
if ( V_297 < 0 )
return V_297 ;
V_298 += V_297 ;
return ( T_9 ) ( V_298 - V_119 ) ;
}
static T_9 F_187 ( struct V_1 * V_2 ,
struct V_289 * V_290 ,
const char * V_119 ,
T_4 V_63 )
{
struct V_6 * V_7 = F_174 ( V_2 ) ;
int V_29 ;
V_29 = F_128 ( V_7 , NULL ) ;
return V_29 < 0 ? V_29 : V_63 ;
}
static void F_188 ( struct V_1 * V_2 )
{
}
static T_9 F_189 ( struct V_1 * V_2 ,
struct V_289 * V_290 ,
char * V_119 )
{
struct V_96 * V_97 = F_38 ( V_2 , struct V_96 , V_2 ) ;
return sprintf ( V_119 , L_45 , ( unsigned long long ) V_97 -> V_63 ) ;
}
static T_9 F_190 ( struct V_1 * V_2 ,
struct V_289 * V_290 ,
char * V_119 )
{
struct V_96 * V_97 = F_38 ( V_2 , struct V_96 , V_2 ) ;
return sprintf ( V_119 , L_45 , ( unsigned long long ) V_97 -> V_94 ) ;
}
static T_9 F_191 ( struct V_1 * V_2 ,
struct V_289 * V_290 ,
char * V_119 )
{
struct V_96 * V_97 = F_38 ( V_2 , struct V_96 , V_2 ) ;
return sprintf ( V_119 , L_46 ,
( unsigned long long ) V_97 -> V_85 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = F_38 ( V_2 , struct V_96 , V_2 ) ;
F_25 ( V_97 -> V_100 ) ;
F_25 ( V_97 ) ;
}
static struct V_295 * F_193 ( struct V_295 * V_102 )
{
F_31 ( & V_102 -> V_34 ) ;
return V_102 ;
}
static void F_194 ( struct V_295 * V_102 )
{
if ( V_102 )
F_41 ( & V_102 -> V_34 , V_300 ) ;
}
static struct V_295 * F_195 ( void )
{
struct V_295 * V_102 ;
V_102 = F_49 ( sizeof ( * V_102 ) , V_32 ) ;
if ( ! V_102 )
return NULL ;
F_16 ( & V_102 -> V_34 ) ;
F_194 ( F_193 ( V_102 ) ) ;
return V_102 ;
}
static void V_300 ( struct V_34 * V_34 )
{
struct V_295 * V_102 = F_38 ( V_34 , struct V_295 , V_34 ) ;
F_25 ( V_102 -> V_291 ) ;
F_25 ( V_102 -> V_294 ) ;
F_25 ( V_102 -> V_293 ) ;
F_25 ( V_102 -> V_101 ) ;
F_25 ( V_102 ) ;
}
static struct V_6 * F_196 ( struct V_25 * V_28 ,
struct V_295 * V_102 )
{
struct V_6 * V_7 ;
V_7 = F_49 ( sizeof ( * V_7 ) , V_32 ) ;
if ( ! V_7 )
return NULL ;
F_119 ( & V_7 -> V_15 ) ;
V_7 -> V_17 = 0 ;
F_17 ( & V_7 -> V_35 ) ;
F_17 ( & V_7 -> V_82 ) ;
F_197 ( & V_7 -> V_227 ) ;
V_7 -> V_102 = V_102 ;
V_7 -> V_25 = V_28 ;
V_7 -> V_226 . V_301 = F_198 ( 1 << V_302 ) ;
V_7 -> V_226 . V_303 = F_198 ( 1 ) ;
V_7 -> V_226 . V_304 = F_198 ( 1 << V_302 ) ;
V_7 -> V_226 . V_305 = F_198 ( ( T_3 ) V_102 -> V_292 ) ;
return V_7 ;
}
static void F_199 ( struct V_6 * V_7 )
{
F_194 ( V_7 -> V_296 ) ;
F_25 ( V_7 -> V_240 ) ;
F_40 ( V_7 -> V_25 ) ;
F_194 ( V_7 -> V_102 ) ;
F_25 ( V_7 ) ;
}
static bool F_200 ( struct V_96 * V_97 )
{
bool V_29 = V_97 -> V_2 . type == & V_306 ;
bool V_307 = F_201 ( & V_97 -> V_2 ) ;
F_11 ( ! V_29 ^ V_307 ) ;
return V_29 ;
}
static void F_156 ( struct V_96 * V_97 )
{
F_39 ( & V_97 -> V_35 ) ;
if ( F_201 ( & V_97 -> V_2 ) )
F_202 ( & V_97 -> V_2 ) ;
}
static int F_203 ( struct V_96 * V_97 ,
struct V_1 * V_308 )
{
struct V_1 * V_2 = & V_97 -> V_2 ;
int V_29 ;
V_2 -> type = & V_306 ;
V_2 -> V_308 = V_308 ;
V_2 -> V_309 = F_192 ;
F_204 ( V_2 , L_57 , V_310 , V_97 -> V_100 ) ;
F_14 ( L_58 , V_31 , V_97 -> V_100 ) ;
V_29 = F_205 ( V_2 ) ;
return V_29 ;
}
static struct V_96 * F_206 ( struct V_6 * V_7 ,
const char * V_101 ,
V_73 V_95 , V_73 V_311 ,
V_73 V_312 )
{
struct V_96 * V_97 ;
int V_29 ;
V_97 = F_49 ( sizeof ( * V_97 ) , V_32 ) ;
if ( ! V_97 )
return F_27 ( - V_30 ) ;
V_29 = - V_30 ;
V_97 -> V_100 = F_207 ( V_101 , V_32 ) ;
if ( ! V_97 -> V_100 )
goto V_313;
V_97 -> V_94 = V_95 ;
V_97 -> V_63 = V_311 ;
V_97 -> V_85 = V_312 ;
return V_97 ;
V_313:
F_25 ( V_97 -> V_100 ) ;
F_25 ( V_97 ) ;
return F_27 ( V_29 ) ;
}
static char * F_208 ( struct V_6 * V_7 , T_3 V_150 ,
V_73 * V_311 , V_73 * V_312 )
{
char * V_101 ;
F_11 ( V_150 < V_7 -> V_76 . V_89 -> V_93 ) ;
* V_311 = V_7 -> V_76 . V_83 [ V_150 ] ;
* V_312 = 0 ;
V_101 = V_7 -> V_76 . V_81 ;
while ( V_150 -- )
V_101 += strlen ( V_101 ) + 1 ;
return V_101 ;
}
static int F_209 ( struct V_6 * V_7 , V_73 V_95 ,
V_185 * V_68 , V_73 * V_311 )
{
V_72 V_314 = F_85 ( V_95 ) ;
int V_29 ;
struct {
V_185 V_68 ;
V_72 V_63 ;
} V_315 ( ( V_316 ) ) V_317 = { 0 } ;
V_29 = F_134 ( V_7 , V_7 -> V_240 ,
L_59 , L_60 ,
( char * ) & V_314 , sizeof ( V_314 ) ,
( char * ) & V_317 , sizeof ( V_317 ) , NULL ) ;
F_14 ( L_61 , V_31 , V_29 ) ;
if ( V_29 < 0 )
return V_29 ;
* V_68 = V_317 . V_68 ;
* V_311 = F_45 ( V_317 . V_63 ) ;
F_14 ( L_62 ,
( unsigned long long ) V_95 , ( unsigned int ) * V_68 ,
( unsigned long long ) * V_311 ) ;
return 0 ;
}
static int F_210 ( struct V_6 * V_7 )
{
return F_209 ( V_7 , V_98 ,
& V_7 -> V_76 . V_86 ,
& V_7 -> V_76 . V_84 ) ;
}
static int F_211 ( struct V_6 * V_7 )
{
void * V_318 ;
int V_29 ;
void * V_319 ;
V_318 = F_49 ( V_320 , V_32 ) ;
if ( ! V_318 )
return - V_30 ;
V_29 = F_134 ( V_7 , V_7 -> V_240 ,
L_59 , L_63 ,
NULL , 0 ,
V_318 , V_320 , NULL ) ;
F_14 ( L_61 , V_31 , V_29 ) ;
if ( V_29 < 0 )
goto V_238;
V_319 = V_318 ;
V_7 -> V_76 . V_79 = F_212 ( & V_319 ,
V_319 + V_320 ,
NULL , V_108 ) ;
if ( F_19 ( V_7 -> V_76 . V_79 ) ) {
V_29 = F_137 ( V_7 -> V_76 . V_79 ) ;
V_7 -> V_76 . V_79 = NULL ;
} else {
F_14 ( L_64 , V_7 -> V_76 . V_79 ) ;
}
V_238:
F_25 ( V_318 ) ;
return V_29 ;
}
static int F_213 ( struct V_6 * V_7 , V_73 V_95 ,
V_73 * V_312 )
{
V_72 V_314 = F_85 ( V_95 ) ;
struct {
V_72 V_85 ;
V_72 V_321 ;
} V_322 = { 0 } ;
V_73 V_321 ;
int V_29 ;
V_29 = F_134 ( V_7 , V_7 -> V_240 ,
L_59 , L_65 ,
( char * ) & V_314 , sizeof ( V_314 ) ,
( char * ) & V_322 , sizeof ( V_322 ) ,
NULL ) ;
F_14 ( L_61 , V_31 , V_29 ) ;
if ( V_29 < 0 )
return V_29 ;
V_321 = F_45 ( V_322 . V_321 ) ;
if ( V_321 & ~ V_323 )
return - V_263 ;
* V_312 = F_45 ( V_322 . V_85 ) ;
F_14 ( L_66 ,
( unsigned long long ) V_95 ,
( unsigned long long ) * V_312 ,
( unsigned long long ) F_45 ( V_322 . V_321 ) ) ;
return 0 ;
}
static int F_214 ( struct V_6 * V_7 )
{
return F_213 ( V_7 , V_98 ,
& V_7 -> V_76 . V_85 ) ;
}
static int F_215 ( struct V_6 * V_7 )
{
struct V_295 * V_296 ;
T_4 V_63 ;
void * V_318 = NULL ;
V_72 V_314 ;
void * V_319 ;
void * V_142 ;
char * V_294 ;
V_73 V_324 ;
int V_29 ;
V_296 = F_195 () ;
if ( ! V_296 )
return - V_30 ;
V_63 = sizeof ( V_72 ) +
sizeof ( V_325 ) + V_326 +
sizeof ( V_72 ) +
sizeof ( V_72 ) ;
V_318 = F_15 ( V_63 , V_32 ) ;
if ( ! V_318 ) {
V_29 = - V_30 ;
goto V_38;
}
V_314 = F_85 ( V_98 ) ;
V_29 = F_134 ( V_7 , V_7 -> V_240 ,
L_59 , L_67 ,
( char * ) & V_314 , sizeof ( V_314 ) ,
( char * ) V_318 , V_63 , NULL ) ;
F_14 ( L_61 , V_31 , V_29 ) ;
if ( V_29 < 0 )
goto V_38;
V_29 = - V_327 ;
V_319 = V_318 ;
V_142 = ( char * ) V_318 + V_63 ;
F_216 ( & V_319 , V_142 , V_296 -> V_292 , V_38 ) ;
if ( V_296 -> V_292 == V_328 )
goto V_238;
V_29 = - V_80 ;
if ( F_48 ( V_296 -> V_292 > ( V_73 ) V_177 ) )
goto V_238;
V_294 = F_212 ( & V_319 , V_142 , NULL , V_32 ) ;
if ( F_19 ( V_294 ) ) {
V_29 = F_137 ( V_294 ) ;
goto V_38;
}
V_296 -> V_294 = V_294 ;
F_216 ( & V_319 , V_142 , V_296 -> V_95 , V_38 ) ;
F_216 ( & V_319 , V_142 , V_324 , V_38 ) ;
V_7 -> V_299 = V_324 ;
V_7 -> V_296 = V_296 ;
V_296 = NULL ;
V_238:
V_29 = 0 ;
V_38:
F_25 ( V_318 ) ;
F_194 ( V_296 ) ;
return V_29 ;
}
static char * F_217 ( struct V_6 * V_7 )
{
T_4 V_329 ;
char * V_294 ;
void * V_319 ;
void * V_142 ;
T_4 V_63 ;
void * V_318 = NULL ;
T_4 V_77 = 0 ;
char * V_293 = NULL ;
int V_29 ;
F_11 ( ! V_7 -> V_102 -> V_293 ) ;
V_77 = strlen ( V_7 -> V_102 -> V_294 ) ;
V_329 = sizeof ( V_325 ) + V_77 ;
V_294 = F_15 ( V_329 , V_32 ) ;
if ( ! V_294 )
return NULL ;
V_319 = V_294 ;
V_142 = ( char * ) V_294 + V_329 ;
F_218 ( & V_319 , V_142 , V_7 -> V_102 -> V_294 , ( T_3 ) V_77 ) ;
V_63 = sizeof ( V_325 ) + V_330 ;
V_318 = F_15 ( V_63 , V_32 ) ;
if ( ! V_318 )
goto V_238;
V_29 = F_134 ( V_7 , V_331 ,
L_59 , L_68 ,
V_294 , V_329 ,
( char * ) V_318 , V_63 , NULL ) ;
if ( V_29 < 0 )
goto V_238;
V_319 = V_318 ;
V_142 = ( char * ) V_318 + V_63 ;
V_293 = F_212 ( & V_319 , V_142 , & V_77 , V_32 ) ;
if ( F_19 ( V_293 ) )
V_293 = NULL ;
else
F_14 ( L_69 , V_31 , V_293 , V_77 ) ;
V_238:
F_25 ( V_318 ) ;
F_25 ( V_294 ) ;
return V_293 ;
}
static int F_219 ( struct V_6 * V_7 )
{
struct V_186 * V_187 ;
const char * V_100 ;
void * V_318 = NULL ;
int V_29 ;
if ( V_7 -> V_102 -> V_291 )
return 0 ;
V_187 = & V_7 -> V_25 -> V_36 -> V_187 ;
V_100 = F_220 ( V_187 -> V_332 , V_7 -> V_102 -> V_292 ) ;
if ( ! V_100 ) {
F_74 ( V_7 , L_70 ,
V_7 -> V_102 -> V_292 ) ;
return - V_80 ;
}
V_7 -> V_102 -> V_291 = F_207 ( V_100 , V_32 ) ;
if ( ! V_7 -> V_102 -> V_291 )
return - V_30 ;
V_100 = F_217 ( V_7 ) ;
if ( V_100 )
V_7 -> V_102 -> V_293 = ( char * ) V_100 ;
else
F_74 ( V_7 , L_71 ) ;
V_100 = F_51 ( V_7 , V_7 -> V_102 -> V_95 ) ;
if ( ! V_100 ) {
F_74 ( V_7 , L_72 ,
V_7 -> V_102 -> V_95 ) ;
V_29 = - V_80 ;
goto V_38;
}
V_7 -> V_102 -> V_101 = F_207 ( V_100 , V_32 ) ;
if( ! V_7 -> V_102 -> V_101 )
goto V_38;
return 0 ;
V_38:
F_25 ( V_318 ) ;
F_25 ( V_7 -> V_102 -> V_291 ) ;
V_7 -> V_102 -> V_291 = NULL ;
return V_29 ;
}
static int F_221 ( struct V_6 * V_7 , V_73 * V_183 )
{
T_4 V_63 ;
int V_29 ;
void * V_318 ;
void * V_319 ;
void * V_142 ;
V_73 V_91 ;
T_3 V_64 ;
struct V_71 * V_89 ;
T_3 V_78 ;
V_63 = sizeof ( V_72 ) + sizeof ( V_325 ) +
V_333 * sizeof ( V_72 ) ;
V_318 = F_49 ( V_63 , V_32 ) ;
if ( ! V_318 )
return - V_30 ;
V_29 = F_134 ( V_7 , V_7 -> V_240 ,
L_59 , L_73 ,
NULL , 0 ,
V_318 , V_63 , V_183 ) ;
F_14 ( L_61 , V_31 , V_29 ) ;
if ( V_29 < 0 )
goto V_238;
V_29 = - V_327 ;
V_319 = V_318 ;
V_142 = ( char * ) V_318 + V_63 ;
F_216 ( & V_319 , V_142 , V_91 , V_238 ) ;
F_222 ( & V_319 , V_142 , V_64 , V_238 ) ;
if ( V_64 > ( V_70 - sizeof ( struct V_71 ) )
/ sizeof ( V_73 ) ) {
V_29 = - V_53 ;
goto V_238;
}
if ( ! F_223 ( & V_319 , V_142 , V_64 * sizeof ( V_72 ) ) )
goto V_238;
V_63 = sizeof ( struct V_71 ) +
V_64 * sizeof ( V_89 -> V_82 [ 0 ] ) ;
V_89 = F_15 ( V_63 , V_32 ) ;
if ( ! V_89 ) {
V_29 = - V_30 ;
goto V_238;
}
F_50 ( & V_89 -> V_90 , 1 ) ;
V_89 -> V_91 = V_91 ;
V_89 -> V_93 = V_64 ;
for ( V_78 = 0 ; V_78 < V_64 ; V_78 ++ )
V_89 -> V_82 [ V_78 ] = F_224 ( & V_319 ) ;
V_7 -> V_76 . V_89 = V_89 ;
F_14 ( L_74 ,
( unsigned long long ) V_91 , ( unsigned int ) V_64 ) ;
V_238:
F_25 ( V_318 ) ;
return 0 ;
}
static char * F_225 ( struct V_6 * V_7 , T_3 V_150 )
{
T_4 V_63 ;
void * V_318 ;
V_72 V_95 ;
int V_29 ;
void * V_319 ;
void * V_142 ;
char * V_101 ;
V_63 = sizeof ( V_325 ) + V_334 ;
V_318 = F_15 ( V_63 , V_32 ) ;
if ( ! V_318 )
return F_27 ( - V_30 ) ;
V_95 = F_85 ( V_7 -> V_76 . V_89 -> V_82 [ V_150 ] ) ;
V_29 = F_134 ( V_7 , V_7 -> V_240 ,
L_59 , L_75 ,
( char * ) & V_95 , sizeof ( V_95 ) ,
V_318 , V_63 , NULL ) ;
F_14 ( L_61 , V_31 , V_29 ) ;
if ( V_29 < 0 )
goto V_238;
V_319 = V_318 ;
V_142 = ( char * ) V_318 + V_63 ;
V_101 = F_212 ( & V_319 , V_142 , NULL , V_32 ) ;
if ( F_19 ( V_101 ) ) {
V_29 = F_137 ( V_101 ) ;
goto V_238;
} else {
F_14 ( L_76 ,
( unsigned long long ) F_45 ( V_95 ) , V_101 ) ;
}
F_25 ( V_318 ) ;
return V_101 ;
V_238:
F_25 ( V_318 ) ;
return F_27 ( V_29 ) ;
}
static char * F_226 ( struct V_6 * V_7 , T_3 V_150 ,
V_73 * V_311 , V_73 * V_312 )
{
V_73 V_95 ;
V_185 V_68 ;
int V_29 ;
V_95 = V_7 -> V_76 . V_89 -> V_82 [ V_150 ] ;
V_29 = F_209 ( V_7 , V_95 , & V_68 , V_311 ) ;
if ( V_29 )
return F_27 ( V_29 ) ;
V_29 = F_213 ( V_7 , V_95 , V_312 ) ;
if ( V_29 )
return F_27 ( V_29 ) ;
return F_225 ( V_7 , V_150 ) ;
}
static char * F_227 ( struct V_6 * V_7 , T_3 V_150 ,
V_73 * V_311 , V_73 * V_312 )
{
if ( V_7 -> V_60 == 1 )
return F_208 ( V_7 , V_150 ,
V_311 , V_312 ) ;
if ( V_7 -> V_60 == 2 )
return F_226 ( V_7 , V_150 ,
V_311 , V_312 ) ;
return F_27 ( - V_53 ) ;
}
static int F_164 ( struct V_6 * V_7 , V_73 * V_242 )
{
int V_29 ;
T_10 V_86 ;
F_160 ( & V_7 -> V_227 ) ;
V_86 = V_7 -> V_76 . V_86 ,
V_29 = F_210 ( V_7 ) ;
if ( V_29 )
goto V_238;
if ( V_7 -> V_76 . V_86 != V_86 ) {
V_29 = - V_80 ;
goto V_238;
}
F_157 ( V_7 ) ;
V_29 = F_221 ( V_7 , V_242 ) ;
F_14 ( L_77 , V_29 ) ;
if ( V_29 )
goto V_238;
V_29 = F_161 ( V_7 ) ;
F_14 ( L_78 , V_29 ) ;
if ( V_29 )
goto V_238;
V_29 = F_162 ( V_7 ) ;
F_14 ( L_79 , V_29 ) ;
V_238:
F_163 ( & V_7 -> V_227 ) ;
return V_29 ;
}
static int F_161 ( struct V_6 * V_7 )
{
struct V_71 * V_89 = V_7 -> V_76 . V_89 ;
const T_3 V_64 = V_89 -> V_93 ;
struct V_335 * V_336 = & V_7 -> V_82 ;
struct V_335 * V_153 = V_336 -> V_277 ;
T_3 V_337 = 0 ;
F_14 ( L_80 , V_31 , ( unsigned int ) V_64 ) ;
while ( V_337 < V_64 || V_153 != V_336 ) {
V_73 V_95 ;
struct V_96 * V_97 ;
char * V_101 ;
V_73 V_311 = 0 ;
V_73 V_312 = 0 ;
V_95 = V_337 < V_64 ? V_89 -> V_82 [ V_337 ]
: V_98 ;
V_97 = V_153 != V_336 ? F_228 ( V_153 , struct V_96 , V_35 )
: NULL ;
F_11 ( ! V_97 || V_97 -> V_94 != V_98 ) ;
if ( V_95 == V_98 || ( V_97 && V_97 -> V_94 > V_95 ) ) {
struct V_335 * V_277 = V_153 -> V_277 ;
if ( V_7 -> V_102 -> V_95 == V_97 -> V_94 )
F_229 ( V_104 , & V_7 -> V_17 ) ;
F_156 ( V_97 ) ;
F_14 ( L_81 ,
V_7 -> V_102 -> V_95 == V_97 -> V_94 ?
L_82 : L_83 ,
( unsigned long long ) V_97 -> V_94 ) ;
V_153 = V_277 ;
continue;
}
V_101 = F_227 ( V_7 , V_337 ,
& V_311 , & V_312 ) ;
if ( F_19 ( V_101 ) )
return F_137 ( V_101 ) ;
F_14 ( L_84 , ( unsigned int ) V_64 ,
( unsigned long long ) V_95 ) ;
if ( ! V_97 || ( V_95 != V_98 && V_97 -> V_94 < V_95 ) ) {
struct V_96 * V_338 ;
V_338 = F_206 ( V_7 , V_101 ,
V_95 , V_311 , V_312 ) ;
if ( F_19 ( V_338 ) ) {
int V_313 = F_137 ( V_338 ) ;
F_14 ( L_85 , V_313 ) ;
return V_313 ;
}
F_14 ( L_86 , V_97 ? L_83 : L_87 ) ;
if ( V_97 )
F_22 ( & V_338 -> V_35 , & V_97 -> V_35 ) ;
else
F_22 ( & V_338 -> V_35 , V_336 ) ;
} else {
F_14 ( L_88 ) ;
F_11 ( V_97 -> V_63 == V_311 ) ;
F_11 ( ! strcmp ( V_97 -> V_100 , V_101 ) ) ;
F_11 ( V_97 -> V_85 == V_312 ) ;
V_153 = V_153 -> V_277 ;
}
V_337 ++ ;
}
F_14 ( L_89 , V_31 ) ;
return 0 ;
}
static int F_162 ( struct V_6 * V_7 )
{
struct V_96 * V_97 ;
int V_29 = 0 ;
F_14 ( L_1 , V_31 ) ;
if ( F_48 ( ! F_201 ( & V_7 -> V_2 ) ) )
return - V_80 ;
F_29 (snap, &rbd_dev->snaps, node) {
if ( ! F_200 ( V_97 ) ) {
V_29 = F_203 ( V_97 , & V_7 -> V_2 ) ;
if ( V_29 < 0 )
break;
}
}
F_14 ( L_90 , V_31 , V_29 ) ;
return V_29 ;
}
static int F_230 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
int V_29 ;
F_6 ( & V_20 , V_21 ) ;
V_2 = & V_7 -> V_2 ;
V_2 -> V_339 = & V_340 ;
V_2 -> type = & V_341 ;
V_2 -> V_308 = & V_342 ;
V_2 -> V_309 = V_343 ;
F_204 ( V_2 , L_44 , V_7 -> V_283 ) ;
V_29 = F_205 ( V_2 ) ;
F_9 ( & V_20 ) ;
return V_29 ;
}
static void F_231 ( struct V_6 * V_7 )
{
F_202 ( & V_7 -> V_2 ) ;
}
static void F_232 ( struct V_6 * V_7 )
{
V_7 -> V_283 = F_233 ( & V_344 ) ;
F_21 ( & V_345 ) ;
F_22 ( & V_7 -> V_35 , & V_346 ) ;
F_23 ( & V_345 ) ;
F_14 ( L_91 , V_7 ,
( unsigned long long ) V_7 -> V_283 ) ;
}
static void F_234 ( struct V_6 * V_7 )
{
struct V_335 * V_114 ;
int V_347 = V_7 -> V_283 ;
int V_348 ;
F_11 ( V_347 > 0 ) ;
F_14 ( L_92 , V_7 ,
( unsigned long long ) V_7 -> V_283 ) ;
F_21 ( & V_345 ) ;
F_235 ( & V_7 -> V_35 ) ;
if ( V_347 != F_236 ( & V_344 ) ) {
F_23 ( & V_345 ) ;
return;
}
V_348 = 0 ;
F_237 (tmp, &rbd_dev_list) {
struct V_6 * V_7 ;
V_7 = F_228 ( V_114 , struct V_6 , V_35 ) ;
if ( V_7 -> V_283 > V_348 )
V_348 = V_7 -> V_283 ;
}
F_23 ( & V_345 ) ;
F_238 ( & V_344 , V_347 , V_348 ) ;
F_14 ( L_93 ) ;
}
static inline T_4 F_239 ( const char * * V_119 )
{
const char * V_349 = L_94 ;
* V_119 += strspn ( * V_119 , V_349 ) ;
return strcspn ( * V_119 , V_349 ) ;
}
static inline T_4 F_240 ( const char * * V_119 ,
char * V_50 ,
T_4 V_350 )
{
T_4 V_77 ;
V_77 = F_239 ( V_119 ) ;
if ( V_77 < V_350 ) {
memcpy ( V_50 , * V_119 , V_77 ) ;
* ( V_50 + V_77 ) = '\0' ;
}
* V_119 += V_77 ;
return V_77 ;
}
static inline char * F_241 ( const char * * V_119 , T_4 * V_351 )
{
char * V_352 ;
T_4 V_77 ;
V_77 = F_239 ( V_119 ) ;
V_352 = F_242 ( * V_119 , V_77 + 1 , V_32 ) ;
if ( ! V_352 )
return NULL ;
* ( V_352 + V_77 ) = '\0' ;
* V_119 += V_77 ;
if ( V_351 )
* V_351 = V_77 ;
return V_352 ;
}
static int F_243 ( const char * V_119 ,
struct V_26 * * V_27 ,
struct V_46 * * V_353 ,
struct V_295 * * V_295 )
{
T_4 V_77 ;
char * V_67 ;
const char * V_354 ;
T_4 V_355 ;
struct V_295 * V_102 = NULL ;
struct V_46 * V_47 = NULL ;
struct V_26 * V_356 ;
int V_29 ;
V_77 = F_239 ( & V_119 ) ;
if ( ! V_77 ) {
F_74 ( NULL , L_95 ) ;
return - V_53 ;
}
V_354 = V_119 ;
V_355 = V_77 + 1 ;
V_119 += V_77 ;
V_29 = - V_53 ;
V_67 = F_241 ( & V_119 , NULL ) ;
if ( ! V_67 )
return - V_30 ;
if ( ! * V_67 ) {
F_74 ( NULL , L_96 ) ;
goto V_38;
}
V_102 = F_195 () ;
if ( ! V_102 )
goto V_357;
V_102 -> V_291 = F_241 ( & V_119 , NULL ) ;
if ( ! V_102 -> V_291 )
goto V_357;
if ( ! * V_102 -> V_291 ) {
F_74 ( NULL , L_97 ) ;
goto V_38;
}
V_102 -> V_293 = F_241 ( & V_119 , NULL ) ;
if ( ! V_102 -> V_293 )
goto V_357;
if ( ! * V_102 -> V_293 ) {
F_74 ( NULL , L_98 ) ;
goto V_38;
}
V_77 = F_239 ( & V_119 ) ;
if ( ! V_77 ) {
V_119 = V_99 ;
V_77 = sizeof ( V_99 ) - 1 ;
} else if ( V_77 > V_334 ) {
V_29 = - V_358 ;
goto V_38;
}
V_102 -> V_101 = F_242 ( V_119 , V_77 + 1 , V_32 ) ;
if ( ! V_102 -> V_101 )
goto V_357;
* ( V_102 -> V_101 + V_77 ) = '\0' ;
V_47 = F_49 ( sizeof ( * V_47 ) , V_32 ) ;
if ( ! V_47 )
goto V_357;
V_47 -> V_13 = V_359 ;
V_356 = F_244 ( V_67 , V_354 ,
V_354 + V_355 - 1 ,
F_32 , V_47 ) ;
if ( F_19 ( V_356 ) ) {
V_29 = F_137 ( V_356 ) ;
goto V_38;
}
F_25 ( V_67 ) ;
* V_27 = V_356 ;
* V_353 = V_47 ;
* V_295 = V_102 ;
return 0 ;
V_357:
V_29 = - V_30 ;
V_38:
F_25 ( V_47 ) ;
F_194 ( V_102 ) ;
F_25 ( V_67 ) ;
return V_29 ;
}
static int F_245 ( struct V_6 * V_7 )
{
int V_29 ;
T_4 V_63 ;
char * V_204 ;
void * V_360 ;
void * V_319 ;
if ( V_7 -> V_102 -> V_294 )
return 0 ;
V_63 = sizeof ( V_361 ) + strlen ( V_7 -> V_102 -> V_293 ) ;
V_204 = F_15 ( V_63 , V_108 ) ;
if ( ! V_204 )
return - V_30 ;
sprintf ( V_204 , L_57 , V_361 , V_7 -> V_102 -> V_293 ) ;
F_14 ( L_99 , V_204 ) ;
V_63 = sizeof ( V_325 ) + V_326 ;
V_360 = F_49 ( V_63 , V_108 ) ;
if ( ! V_360 ) {
V_29 = - V_30 ;
goto V_238;
}
V_29 = F_134 ( V_7 , V_204 ,
L_59 , L_100 ,
NULL , 0 ,
V_360 , V_326 , NULL ) ;
F_14 ( L_61 , V_31 , V_29 ) ;
if ( V_29 < 0 )
goto V_238;
V_319 = V_360 ;
V_7 -> V_102 -> V_294 = F_212 ( & V_319 ,
V_319 + V_326 ,
NULL , V_108 ) ;
if ( F_19 ( V_7 -> V_102 -> V_294 ) ) {
V_29 = F_137 ( V_7 -> V_102 -> V_294 ) ;
V_7 -> V_102 -> V_294 = NULL ;
} else {
F_14 ( L_101 , V_7 -> V_102 -> V_294 ) ;
}
V_238:
F_25 ( V_360 ) ;
F_25 ( V_204 ) ;
return V_29 ;
}
static int F_246 ( struct V_6 * V_7 )
{
int V_29 ;
T_4 V_63 ;
V_7 -> V_102 -> V_294 = F_207 ( L_83 , V_32 ) ;
if ( ! V_7 -> V_102 -> V_294 )
return - V_30 ;
V_63 = strlen ( V_7 -> V_102 -> V_293 ) + sizeof ( V_362 ) ;
V_7 -> V_240 = F_15 ( V_63 , V_32 ) ;
if ( ! V_7 -> V_240 ) {
V_29 = - V_30 ;
goto V_38;
}
sprintf ( V_7 -> V_240 , L_57 ,
V_7 -> V_102 -> V_293 , V_362 ) ;
V_29 = F_153 ( V_7 , & V_7 -> V_76 ) ;
if ( V_29 < 0 )
goto V_38;
V_7 -> V_296 = NULL ;
V_7 -> V_299 = 0 ;
V_7 -> V_60 = 1 ;
F_14 ( L_102 ,
V_7 -> V_240 ) ;
return 0 ;
V_38:
F_25 ( V_7 -> V_240 ) ;
V_7 -> V_240 = NULL ;
F_25 ( V_7 -> V_102 -> V_294 ) ;
V_7 -> V_102 -> V_294 = NULL ;
return V_29 ;
}
static int F_247 ( struct V_6 * V_7 )
{
T_4 V_63 ;
int V_29 ;
V_73 V_183 = 0 ;
V_63 = sizeof ( V_363 ) + strlen ( V_7 -> V_102 -> V_294 ) ;
V_7 -> V_240 = F_15 ( V_63 , V_32 ) ;
if ( ! V_7 -> V_240 )
return - V_30 ;
sprintf ( V_7 -> V_240 , L_57 ,
V_363 , V_7 -> V_102 -> V_294 ) ;
V_29 = F_210 ( V_7 ) ;
if ( V_29 < 0 )
goto V_38;
V_29 = F_211 ( V_7 ) ;
if ( V_29 < 0 )
goto V_38;
V_29 = F_214 ( V_7 ) ;
if ( V_29 < 0 )
goto V_38;
if ( V_7 -> V_76 . V_85 & V_364 ) {
V_29 = F_215 ( V_7 ) ;
if ( V_29 < 0 )
goto V_38;
}
V_7 -> V_76 . V_87 = 0 ;
V_7 -> V_76 . V_88 = 0 ;
V_29 = F_221 ( V_7 , & V_183 ) ;
if ( V_29 )
goto V_38;
V_7 -> V_76 . V_248 = V_183 ;
V_7 -> V_60 = 2 ;
F_14 ( L_103 ,
V_7 -> V_240 ) ;
return 0 ;
V_38:
V_7 -> V_299 = 0 ;
F_194 ( V_7 -> V_296 ) ;
V_7 -> V_296 = NULL ;
F_25 ( V_7 -> V_240 ) ;
V_7 -> V_240 = NULL ;
F_25 ( V_7 -> V_76 . V_79 ) ;
V_7 -> V_76 . V_79 = NULL ;
return V_29 ;
}
static int F_248 ( struct V_6 * V_7 )
{
int V_29 ;
V_29 = F_161 ( V_7 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_219 ( V_7 ) ;
if ( V_29 )
goto V_365;
V_29 = F_53 ( V_7 ) ;
if ( V_29 )
goto V_365;
F_232 ( V_7 ) ;
F_249 ( V_366
< sizeof ( V_282 ) + V_367 ) ;
sprintf ( V_7 -> V_100 , L_104 , V_282 , V_7 -> V_283 ) ;
V_29 = F_250 ( 0 , V_7 -> V_100 ) ;
if ( V_29 < 0 )
goto V_368;
V_7 -> V_284 = V_29 ;
V_29 = F_165 ( V_7 ) ;
if ( V_29 )
goto V_369;
V_29 = F_230 ( V_7 ) ;
if ( V_29 )
goto V_370;
F_160 ( & V_7 -> V_227 ) ;
V_29 = F_162 ( V_7 ) ;
F_163 ( & V_7 -> V_227 ) ;
if ( V_29 )
goto V_371;
V_29 = F_129 ( V_7 , 1 ) ;
if ( V_29 )
goto V_371;
F_251 ( V_7 -> V_23 ) ;
F_252 ( L_105 , V_7 -> V_23 -> V_281 ,
( unsigned long long ) V_7 -> V_12 . V_63 ) ;
return V_29 ;
V_371:
F_231 ( V_7 ) ;
return V_29 ;
V_370:
F_147 ( V_7 ) ;
V_369:
F_253 ( V_7 -> V_284 , V_7 -> V_100 ) ;
V_368:
F_234 ( V_7 ) ;
V_365:
F_154 ( V_7 ) ;
return V_29 ;
}
static int F_254 ( struct V_6 * V_7 )
{
int V_29 ;
V_29 = F_245 ( V_7 ) ;
if ( V_29 )
V_29 = F_246 ( V_7 ) ;
else
V_29 = F_247 ( V_7 ) ;
if ( V_29 ) {
F_14 ( L_106 , V_29 ) ;
return V_29 ;
}
V_29 = F_248 ( V_7 ) ;
if ( V_29 )
F_55 ( & V_7 -> V_76 ) ;
return V_29 ;
}
static T_9 F_255 ( struct V_372 * V_339 ,
const char * V_119 ,
T_4 V_297 )
{
struct V_6 * V_7 = NULL ;
struct V_26 * V_27 = NULL ;
struct V_46 * V_47 = NULL ;
struct V_295 * V_102 = NULL ;
struct V_25 * V_28 ;
struct V_186 * V_187 ;
int V_243 = - V_30 ;
if ( ! F_256 ( V_373 ) )
return - V_374 ;
V_243 = F_243 ( V_119 , & V_27 , & V_47 , & V_102 ) ;
if ( V_243 < 0 )
goto V_375;
V_28 = F_36 ( V_27 ) ;
if ( F_19 ( V_28 ) ) {
V_243 = F_137 ( V_28 ) ;
goto V_376;
}
V_27 = NULL ;
V_187 = & V_28 -> V_36 -> V_187 ;
V_243 = F_257 ( V_187 -> V_332 , V_102 -> V_291 ) ;
if ( V_243 < 0 )
goto V_377;
V_102 -> V_292 = ( V_73 ) V_243 ;
if ( F_48 ( V_102 -> V_292 > ( V_73 ) V_177 ) ) {
V_243 = - V_80 ;
goto V_377;
}
V_7 = F_196 ( V_28 , V_102 ) ;
if ( ! V_7 )
goto V_377;
V_28 = NULL ;
V_102 = NULL ;
V_7 -> V_12 . V_13 = V_47 -> V_13 ;
F_25 ( V_47 ) ;
V_47 = NULL ;
V_243 = F_254 ( V_7 ) ;
if ( V_243 < 0 )
goto V_378;
return V_297 ;
V_378:
F_199 ( V_7 ) ;
V_377:
F_40 ( V_28 ) ;
V_376:
if ( V_27 )
F_26 ( V_27 ) ;
F_25 ( V_47 ) ;
F_194 ( V_102 ) ;
V_375:
F_258 ( V_373 ) ;
F_14 ( L_107 , V_119 ) ;
return ( T_9 ) V_243 ;
}
static struct V_6 * F_259 ( unsigned long V_283 )
{
struct V_335 * V_114 ;
struct V_6 * V_7 ;
F_21 ( & V_345 ) ;
F_260 (tmp, &rbd_dev_list) {
V_7 = F_228 ( V_114 , struct V_6 , V_35 ) ;
if ( V_7 -> V_283 == V_283 ) {
F_23 ( & V_345 ) ;
return V_7 ;
}
}
F_23 ( & V_345 ) ;
return NULL ;
}
static void V_343 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_174 ( V_2 ) ;
if ( V_7 -> V_245 )
F_129 ( V_7 , 0 ) ;
F_147 ( V_7 ) ;
F_253 ( V_7 -> V_284 , V_7 -> V_100 ) ;
F_55 ( & V_7 -> V_76 ) ;
F_234 ( V_7 ) ;
F_11 ( V_7 -> V_25 != NULL ) ;
F_199 ( V_7 ) ;
F_258 ( V_373 ) ;
}
static T_9 F_261 ( struct V_372 * V_339 ,
const char * V_119 ,
T_4 V_297 )
{
struct V_6 * V_7 = NULL ;
int V_379 , V_243 ;
unsigned long V_380 ;
int V_29 = V_297 ;
V_243 = F_262 ( V_119 , 10 , & V_380 ) ;
if ( V_243 )
return V_243 ;
V_379 = ( int ) V_380 ;
if ( V_379 != V_380 )
return - V_53 ;
F_6 ( & V_20 , V_21 ) ;
V_7 = F_259 ( V_379 ) ;
if ( ! V_7 ) {
V_29 = - V_19 ;
goto V_103;
}
F_3 ( & V_7 -> V_15 ) ;
if ( V_7 -> V_18 )
V_29 = - V_381 ;
else
F_54 ( V_16 , & V_7 -> V_17 ) ;
F_5 ( & V_7 -> V_15 ) ;
if ( V_29 < 0 )
goto V_103;
F_154 ( V_7 ) ;
F_231 ( V_7 ) ;
V_103:
F_9 ( & V_20 ) ;
return V_29 ;
}
static int F_263 ( void )
{
int V_29 ;
V_29 = F_205 ( & V_342 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_264 ( & V_340 ) ;
if ( V_29 < 0 )
F_202 ( & V_342 ) ;
return V_29 ;
}
static void F_265 ( void )
{
F_266 ( & V_340 ) ;
F_202 ( & V_342 ) ;
}
static int T_11 F_267 ( void )
{
int V_243 ;
if ( ! F_268 ( NULL ) ) {
F_74 ( NULL , L_108 ) ;
return - V_53 ;
}
V_243 = F_263 () ;
if ( V_243 )
return V_243 ;
F_252 ( L_109 V_382 L_110 ) ;
return 0 ;
}
static void T_12 F_269 ( void )
{
F_265 () ;
}
