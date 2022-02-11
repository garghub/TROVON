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
static struct V_53 * F_48 ( struct V_54 * V_55 )
{
struct V_53 * V_56 ;
F_49 ( & V_86 , V_87 ) ;
V_56 = F_41 ( V_55 ) ;
if ( V_56 )
F_37 ( V_55 ) ;
else
V_56 = F_24 ( V_55 ) ;
F_50 ( & V_86 ) ;
return V_56 ;
}
static void F_51 ( struct V_61 * V_61 )
{
struct V_53 * V_56 = F_52 ( V_61 , struct V_53 , V_61 ) ;
F_25 ( L_2 , V_58 , V_56 ) ;
F_32 ( & V_66 ) ;
F_53 ( & V_56 -> V_62 ) ;
F_34 ( & V_66 ) ;
F_35 ( V_56 -> V_63 ) ;
F_36 ( V_56 ) ;
}
static void F_54 ( struct V_53 * V_56 )
{
if ( V_56 )
F_55 ( & V_56 -> V_61 , F_51 ) ;
}
static bool F_56 ( T_5 V_88 )
{
return V_88 == 1 || V_88 == 2 ;
}
static bool F_57 ( struct V_89 * V_90 )
{
T_6 V_91 ;
T_5 V_92 ;
if ( memcmp ( & V_90 -> V_93 , V_94 , sizeof ( V_94 ) ) )
return false ;
if ( V_90 -> V_95 . V_96 < V_97 )
return false ;
if ( V_90 -> V_95 . V_96 > 8 * sizeof ( int ) - 1 )
return false ;
V_92 = F_58 ( V_90 -> V_92 ) ;
V_91 = V_98 - sizeof ( struct V_99 ) ;
if ( V_92 > V_91 / sizeof ( V_100 ) )
return false ;
V_91 -= V_92 * sizeof ( V_100 ) ;
if ( ( V_101 ) V_91 < F_59 ( V_90 -> V_102 ) )
return false ;
return true ;
}
static int F_60 ( struct V_21 * V_22 ,
struct V_89 * V_90 )
{
struct V_103 * V_104 = & V_22 -> V_104 ;
bool V_105 = V_104 -> V_106 == NULL ;
struct V_99 * V_107 ;
char * V_106 = NULL ;
char * V_108 = NULL ;
V_101 * V_109 = NULL ;
T_5 V_92 ;
T_6 V_91 ;
int V_39 = - V_57 ;
T_5 V_110 ;
if ( V_105 ) {
T_6 V_111 ;
V_111 = F_61 ( V_90 -> V_106 ,
sizeof ( V_90 -> V_106 ) ) ;
V_106 = F_26 ( V_111 + 1 , V_59 ) ;
if ( ! V_106 )
return - V_57 ;
memcpy ( V_106 , V_90 -> V_106 , V_111 ) ;
V_106 [ V_111 ] = '\0' ;
}
V_92 = F_58 ( V_90 -> V_92 ) ;
V_107 = F_62 ( V_92 , V_59 ) ;
if ( ! V_107 )
goto V_112;
V_107 -> V_113 = F_59 ( V_90 -> V_114 ) ;
if ( V_92 ) {
struct V_115 * V_116 ;
V_101 V_102 = F_59 ( V_90 -> V_102 ) ;
if ( V_102 > ( V_101 ) V_98 )
goto V_117;
V_108 = F_26 ( V_102 , V_59 ) ;
if ( ! V_108 )
goto V_112;
V_91 = V_92 * sizeof ( * V_104 -> V_109 ) ;
V_109 = F_26 ( V_91 , V_59 ) ;
if ( ! V_109 )
goto V_112;
memcpy ( V_108 , & V_90 -> V_116 [ V_92 ] , V_102 ) ;
V_116 = V_90 -> V_116 ;
for ( V_110 = 0 ; V_110 < V_92 ; V_110 ++ ) {
V_107 -> V_116 [ V_110 ] = F_59 ( V_116 [ V_110 ] . V_118 ) ;
V_109 [ V_110 ] = F_59 ( V_116 [ V_110 ] . V_119 ) ;
}
}
if ( V_105 ) {
V_104 -> V_106 = V_106 ;
V_104 -> V_120 = V_90 -> V_95 . V_96 ;
V_104 -> V_121 = V_90 -> V_95 . V_121 ;
V_104 -> V_122 = V_90 -> V_95 . V_122 ;
V_104 -> V_123 = 0 ;
V_104 -> V_124 = 0 ;
V_104 -> V_125 = 0 ;
} else {
F_63 ( V_104 -> V_107 ) ;
F_36 ( V_104 -> V_108 ) ;
F_36 ( V_104 -> V_109 ) ;
}
V_104 -> V_119 = F_59 ( V_90 -> V_119 ) ;
V_104 -> V_107 = V_107 ;
V_104 -> V_108 = V_108 ;
V_104 -> V_109 = V_109 ;
return 0 ;
V_117:
V_39 = - V_126 ;
V_112:
F_36 ( V_109 ) ;
F_36 ( V_108 ) ;
F_63 ( V_107 ) ;
F_36 ( V_106 ) ;
return V_39 ;
}
static const char * F_64 ( struct V_21 * V_22 , T_5 V_127 )
{
const char * V_128 ;
F_17 ( V_127 < V_22 -> V_104 . V_107 -> V_129 ) ;
V_128 = V_22 -> V_104 . V_108 ;
while ( V_127 -- )
V_128 += strlen ( V_128 ) + 1 ;
return F_65 ( V_128 , V_59 ) ;
}
static int F_66 ( const void * V_130 , const void * V_131 )
{
V_101 V_132 = * ( V_101 * ) V_130 ;
V_101 V_133 = * ( V_101 * ) V_131 ;
if ( V_132 < V_133 )
return 1 ;
return V_132 == V_133 ? 0 : - 1 ;
}
static T_5 F_67 ( struct V_21 * V_22 , V_101 V_46 )
{
struct V_99 * V_107 = V_22 -> V_104 . V_107 ;
V_101 * V_69 ;
V_69 = bsearch ( & V_46 , & V_107 -> V_116 , V_107 -> V_129 ,
sizeof ( V_46 ) , F_66 ) ;
return V_69 ? ( T_5 ) ( V_69 - & V_107 -> V_116 [ 0 ] ) : V_134 ;
}
static const char * F_68 ( struct V_21 * V_22 ,
V_101 V_46 )
{
T_5 V_127 ;
const char * V_128 ;
V_127 = F_67 ( V_22 , V_46 ) ;
if ( V_127 == V_134 )
return F_38 ( - V_34 ) ;
V_128 = F_64 ( V_22 , V_127 ) ;
return V_128 ? V_128 : F_38 ( - V_57 ) ;
}
static const char * F_69 ( struct V_21 * V_22 , V_101 V_46 )
{
if ( V_46 == V_47 )
return V_135 ;
F_17 ( F_56 ( V_22 -> V_88 ) ) ;
if ( V_22 -> V_88 == 1 )
return F_68 ( V_22 , V_46 ) ;
return F_70 ( V_22 , V_46 ) ;
}
static int F_71 ( struct V_21 * V_22 , V_101 V_46 ,
V_101 * V_136 )
{
F_17 ( F_56 ( V_22 -> V_88 ) ) ;
if ( V_46 == V_47 ) {
* V_136 = V_22 -> V_104 . V_119 ;
} else if ( V_22 -> V_88 == 1 ) {
T_5 V_127 ;
V_127 = F_67 ( V_22 , V_46 ) ;
if ( V_127 == V_134 )
return - V_34 ;
* V_136 = V_22 -> V_104 . V_109 [ V_127 ] ;
} else {
V_101 V_91 = 0 ;
int V_39 ;
V_39 = F_72 ( V_22 , V_46 , NULL , & V_91 ) ;
if ( V_39 )
return V_39 ;
* V_136 = V_91 ;
}
return 0 ;
}
static int F_73 ( struct V_21 * V_22 , V_101 V_46 ,
V_101 * V_137 )
{
F_17 ( F_56 ( V_22 -> V_88 ) ) ;
if ( V_46 == V_47 ) {
* V_137 = V_22 -> V_104 . V_125 ;
} else if ( V_22 -> V_88 == 1 ) {
* V_137 = 0 ;
} else {
V_101 V_125 = 0 ;
int V_39 ;
V_39 = F_74 ( V_22 , V_46 , & V_125 ) ;
if ( V_39 )
return V_39 ;
* V_137 = V_125 ;
}
return 0 ;
}
static int F_75 ( struct V_21 * V_22 )
{
V_101 V_46 = V_22 -> V_45 -> V_46 ;
V_101 V_91 = 0 ;
V_101 V_125 = 0 ;
int V_39 ;
V_39 = F_71 ( V_22 , V_46 , & V_91 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_73 ( V_22 , V_46 , & V_125 ) ;
if ( V_39 )
return V_39 ;
V_22 -> V_27 . V_91 = V_91 ;
V_22 -> V_27 . V_125 = V_125 ;
return 0 ;
}
static void F_76 ( struct V_21 * V_22 )
{
V_22 -> V_27 . V_91 = 0 ;
V_22 -> V_27 . V_125 = 0 ;
}
static void F_77 ( const char * V_138 )
{
F_78 ( V_139 , ( void * ) V_138 ) ;
}
static const char * F_79 ( struct V_21 * V_22 , V_101 V_140 )
{
char * V_138 ;
V_101 V_141 ;
int V_39 ;
char * V_142 ;
V_138 = F_80 ( V_139 , V_143 ) ;
if ( ! V_138 )
return NULL ;
V_141 = V_140 >> V_22 -> V_104 . V_120 ;
V_142 = L_10 ;
if ( V_22 -> V_88 == 2 )
V_142 = L_11 ;
V_39 = snprintf ( V_138 , V_144 + 1 , V_142 ,
V_22 -> V_104 . V_106 , V_141 ) ;
if ( V_39 < 0 || V_39 > V_144 ) {
F_47 ( L_12 ,
V_141 , V_39 ) ;
F_77 ( V_138 ) ;
V_138 = NULL ;
}
return V_138 ;
}
static V_101 F_81 ( struct V_21 * V_22 , V_101 V_140 )
{
V_101 V_145 = ( V_101 ) 1 << V_22 -> V_104 . V_120 ;
return V_140 & ( V_145 - 1 ) ;
}
static V_101 F_82 ( struct V_21 * V_22 ,
V_101 V_140 , V_101 V_146 )
{
V_101 V_145 = ( V_101 ) 1 << V_22 -> V_104 . V_120 ;
V_140 &= V_145 - 1 ;
F_17 ( V_146 <= V_147 - V_140 ) ;
if ( V_140 + V_146 > V_145 )
V_146 = V_145 - V_140 ;
return V_146 ;
}
static V_101 F_83 ( struct V_103 * V_104 )
{
return 1 << V_104 -> V_120 ;
}
static void F_84 ( struct V_148 * V_149 )
{
struct V_148 * V_150 ;
while ( V_149 ) {
V_150 = V_149 ;
V_149 = V_149 -> V_151 ;
F_85 ( V_150 ) ;
}
}
static void F_86 ( struct V_148 * V_149 , int V_152 )
{
struct V_153 V_154 ;
struct V_155 V_156 ;
unsigned long V_32 ;
void * V_157 ;
int V_158 = 0 ;
while ( V_149 ) {
F_87 (bv, chain, iter) {
if ( V_158 + V_154 . V_159 > V_152 ) {
int V_160 = F_88 ( V_152 - V_158 , 0 ) ;
V_157 = F_89 ( & V_154 , & V_32 ) ;
memset ( V_157 + V_160 , 0 ,
V_154 . V_159 - V_160 ) ;
F_90 ( V_154 . V_161 ) ;
F_91 ( V_157 , & V_32 ) ;
}
V_158 += V_154 . V_159 ;
}
V_149 = V_149 -> V_151 ;
}
}
static void F_92 ( struct V_162 * * V_163 , V_101 V_140 , V_101 V_164 )
{
struct V_162 * * V_162 = & V_163 [ V_140 >> V_165 ] ;
F_17 ( V_164 > V_140 ) ;
F_17 ( V_164 - V_140 <= ( V_101 ) V_98 ) ;
while ( V_140 < V_164 ) {
T_6 V_166 ;
T_6 V_146 ;
unsigned long V_32 ;
void * V_167 ;
V_166 = V_140 & ~ V_168 ;
V_146 = F_93 ( T_6 , V_169 - V_166 , V_164 - V_140 ) ;
F_94 ( V_32 ) ;
V_167 = F_95 ( * V_162 ) ;
memset ( V_167 + V_166 , 0 , V_146 ) ;
F_90 ( * V_162 ) ;
F_96 ( V_167 ) ;
F_97 ( V_32 ) ;
V_140 += V_146 ;
V_162 ++ ;
}
}
static struct V_148 * F_98 ( struct V_148 * V_170 ,
unsigned int V_140 ,
unsigned int V_111 ,
T_7 V_171 )
{
struct V_148 * V_148 ;
V_148 = F_99 ( V_170 , V_171 ) ;
if ( ! V_148 )
return NULL ;
F_100 ( V_148 , V_140 ) ;
V_148 -> V_172 . V_173 = V_111 ;
return V_148 ;
}
static struct V_148 * F_101 ( struct V_148 * * V_170 ,
unsigned int * V_140 ,
unsigned int V_111 ,
T_7 V_171 )
{
struct V_148 * V_174 = * V_170 ;
unsigned int V_175 = * V_140 ;
struct V_148 * V_149 = NULL ;
struct V_148 * * V_164 ;
if ( ! V_174 || V_175 >= V_174 -> V_172 . V_173 || ! V_111 )
return NULL ;
V_164 = & V_149 ;
while ( V_111 ) {
unsigned int V_173 ;
struct V_148 * V_148 ;
if ( ! V_174 ) {
F_102 ( NULL , L_13 , V_111 ) ;
goto V_112;
}
V_173 = F_93 (unsigned int, bi->bi_iter.bi_size - off, len) ;
V_148 = F_98 ( V_174 , V_175 , V_173 , V_171 ) ;
if ( ! V_148 )
goto V_112;
* V_164 = V_148 ;
V_164 = & V_148 -> V_151 ;
V_175 += V_173 ;
if ( V_175 == V_174 -> V_172 . V_173 ) {
V_174 = V_174 -> V_151 ;
V_175 = 0 ;
}
V_111 -= V_173 ;
}
* V_170 = V_174 ;
* V_140 = V_175 ;
return V_149 ;
V_112:
F_84 ( V_149 ) ;
return NULL ;
}
static void F_103 ( struct V_176 * V_177 )
{
if ( F_104 ( V_178 , & V_177 -> V_32 ) ) {
struct V_21 * V_22 ;
V_22 = V_177 -> V_179 -> V_22 ;
F_102 ( V_22 , L_14 ,
V_177 ) ;
}
}
static bool F_105 ( struct V_176 * V_177 )
{
F_106 () ;
return F_13 ( V_178 , & V_177 -> V_32 ) != 0 ;
}
static void F_107 ( struct V_176 * V_177 )
{
if ( F_104 ( V_180 , & V_177 -> V_32 ) ) {
struct V_21 * V_22 = NULL ;
if ( F_105 ( V_177 ) )
V_22 = V_177 -> V_179 -> V_22 ;
F_102 ( V_22 , L_15 ,
V_177 ) ;
}
}
static bool F_108 ( struct V_176 * V_177 )
{
F_106 () ;
return F_13 ( V_180 , & V_177 -> V_32 ) != 0 ;
}
static void F_109 ( struct V_176 * V_177 ,
bool V_181 )
{
if ( V_181 )
F_110 ( V_182 , & V_177 -> V_32 ) ;
F_110 ( V_183 , & V_177 -> V_32 ) ;
F_106 () ;
}
static bool F_111 ( struct V_176 * V_177 )
{
F_106 () ;
return F_13 ( V_183 , & V_177 -> V_32 ) != 0 ;
}
static bool F_112 ( struct V_176 * V_177 )
{
F_106 () ;
return F_13 ( V_182 , & V_177 -> V_32 ) != 0 ;
}
static bool F_113 ( struct V_176 * V_177 )
{
struct V_21 * V_22 = V_177 -> V_179 -> V_22 ;
return V_177 -> V_184 <
F_114 ( V_22 -> V_185 , F_83 ( & V_22 -> V_104 ) ) ;
}
static void F_115 ( struct V_176 * V_177 )
{
F_25 ( L_16 , V_58 , V_177 ,
F_116 ( & V_177 -> V_61 . V_186 ) ) ;
F_40 ( & V_177 -> V_61 ) ;
}
static void F_117 ( struct V_176 * V_177 )
{
F_17 ( V_177 != NULL ) ;
F_25 ( L_16 , V_58 , V_177 ,
F_116 ( & V_177 -> V_61 . V_186 ) ) ;
F_55 ( & V_177 -> V_61 , V_187 ) ;
}
static void F_118 ( struct V_188 * V_179 )
{
F_25 ( L_17 , V_58 , V_179 ,
F_116 ( & V_179 -> V_61 . V_186 ) ) ;
F_40 ( & V_179 -> V_61 ) ;
}
static void F_119 ( struct V_188 * V_179 )
{
F_17 ( V_179 != NULL ) ;
F_25 ( L_17 , V_58 , V_179 ,
F_116 ( & V_179 -> V_61 . V_186 ) ) ;
if ( F_120 ( V_179 ) )
F_55 ( & V_179 -> V_61 , V_189 ) ;
else
F_55 ( & V_179 -> V_61 , V_190 ) ;
}
static inline void F_121 ( struct V_188 * V_179 ,
struct V_176 * V_177 )
{
F_17 ( V_177 -> V_179 == NULL ) ;
V_177 -> V_179 = V_179 ;
V_177 -> V_127 = V_179 -> V_191 ;
F_17 ( ! F_105 ( V_177 ) ) ;
F_103 ( V_177 ) ;
F_17 ( V_177 -> V_127 != V_192 ) ;
V_179 -> V_191 ++ ;
F_33 ( & V_177 -> V_193 , & V_179 -> V_194 ) ;
F_25 ( L_18 , V_58 , V_179 , V_177 ,
V_177 -> V_127 ) ;
}
static inline void F_122 ( struct V_188 * V_179 ,
struct V_176 * V_177 )
{
F_17 ( V_177 -> V_127 != V_192 ) ;
F_25 ( L_18 , V_58 , V_179 , V_177 ,
V_177 -> V_127 ) ;
F_53 ( & V_177 -> V_193 ) ;
F_17 ( V_179 -> V_191 > 0 ) ;
V_179 -> V_191 -- ;
F_17 ( V_177 -> V_127 == V_179 -> V_191 ) ;
V_177 -> V_127 = V_192 ;
F_17 ( F_105 ( V_177 ) ) ;
F_17 ( V_177 -> V_179 == V_179 ) ;
V_177 -> V_179 = NULL ;
V_177 -> V_195 = NULL ;
F_117 ( V_177 ) ;
}
static bool F_123 ( enum V_196 type )
{
switch ( type ) {
case V_197 :
case V_198 :
case V_199 :
return true ;
default:
return false ;
}
}
static int F_124 ( struct V_200 * V_201 ,
struct V_176 * V_177 )
{
F_25 ( L_19 , V_58 , V_177 ) ;
return F_125 ( V_201 , V_177 -> V_202 , false ) ;
}
static void F_126 ( struct V_176 * V_177 )
{
F_25 ( L_19 , V_58 , V_177 ) ;
F_127 ( V_177 -> V_202 ) ;
}
static int F_128 ( struct V_176 * V_177 )
{
int V_39 ;
F_25 ( L_19 , V_58 , V_177 ) ;
V_39 = F_129 ( & V_177 -> V_203 ) ;
if ( V_39 < 0 ) {
F_25 ( L_20 , V_58 , V_177 ) ;
F_126 ( V_177 ) ;
return V_39 ;
}
F_25 ( L_21 , V_58 , V_177 ) ;
return 0 ;
}
static void F_130 ( struct V_188 * V_179 )
{
F_25 ( L_22 , V_58 , V_179 ) ;
if ( ! V_179 -> V_204 ) {
struct V_176 * V_177 ;
V_101 V_205 = 0 ;
F_131 (img_request, obj_request)
V_205 += V_177 -> V_205 ;
V_179 -> V_205 = V_205 ;
}
if ( V_179 -> V_195 )
V_179 -> V_195 ( V_179 ) ;
else
F_119 ( V_179 ) ;
}
static void F_132 ( struct V_188 * V_179 )
{
F_110 ( V_206 , & V_179 -> V_32 ) ;
F_106 () ;
}
static bool F_133 ( struct V_188 * V_179 )
{
F_106 () ;
return F_13 ( V_206 , & V_179 -> V_32 ) != 0 ;
}
static void F_134 ( struct V_188 * V_179 )
{
F_110 ( V_207 , & V_179 -> V_32 ) ;
F_106 () ;
}
static void F_135 ( struct V_188 * V_179 )
{
F_136 ( V_207 , & V_179 -> V_32 ) ;
F_106 () ;
}
static bool F_120 ( struct V_188 * V_179 )
{
F_106 () ;
return F_13 ( V_207 , & V_179 -> V_32 ) != 0 ;
}
static void F_137 ( struct V_188 * V_179 )
{
F_110 ( V_208 , & V_179 -> V_32 ) ;
F_106 () ;
}
static void F_138 ( struct V_188 * V_179 )
{
F_136 ( V_208 , & V_179 -> V_32 ) ;
F_106 () ;
}
static bool F_139 ( struct V_188 * V_179 )
{
F_106 () ;
return F_13 ( V_208 , & V_179 -> V_32 ) != 0 ;
}
static void
F_140 ( struct V_176 * V_177 )
{
V_101 V_205 = V_177 -> V_205 ;
V_101 V_146 = V_177 -> V_146 ;
F_25 ( L_23 , V_58 ,
V_177 , V_177 -> V_179 , V_177 -> V_204 ,
V_205 , V_146 ) ;
F_17 ( V_177 -> type != V_197 ) ;
if ( V_177 -> V_204 == - V_34 ) {
if ( V_177 -> type == V_198 )
F_86 ( V_177 -> V_209 , 0 ) ;
else
F_92 ( V_177 -> V_163 , 0 , V_146 ) ;
V_177 -> V_204 = 0 ;
} else if ( V_205 < V_146 && ! V_177 -> V_204 ) {
if ( V_177 -> type == V_198 )
F_86 ( V_177 -> V_209 , V_205 ) ;
else
F_92 ( V_177 -> V_163 , V_205 , V_146 ) ;
}
V_177 -> V_205 = V_146 ;
F_107 ( V_177 ) ;
}
static void F_141 ( struct V_176 * V_177 )
{
F_25 ( L_24 , V_58 , V_177 ,
V_177 -> V_195 ) ;
if ( V_177 -> V_195 )
V_177 -> V_195 ( V_177 ) ;
else
F_142 ( & V_177 -> V_203 ) ;
}
static void F_143 ( struct V_176 * V_177 )
{
F_25 ( L_25 , V_58 , V_177 ) ;
F_107 ( V_177 ) ;
}
static void F_144 ( struct V_176 * V_177 )
{
struct V_188 * V_179 = NULL ;
struct V_21 * V_22 = NULL ;
bool V_210 = false ;
if ( F_105 ( V_177 ) ) {
V_179 = V_177 -> V_179 ;
V_210 = V_179 && F_139 ( V_179 ) ;
V_22 = V_179 -> V_22 ;
}
F_25 ( L_23 , V_58 ,
V_177 , V_179 , V_177 -> V_204 ,
V_177 -> V_205 , V_177 -> V_146 ) ;
if ( V_210 && V_177 -> V_204 == - V_34 &&
V_177 -> V_184 < V_22 -> V_185 )
F_145 ( V_177 ) ;
else if ( V_179 )
F_140 ( V_177 ) ;
else
F_107 ( V_177 ) ;
}
static void F_146 ( struct V_176 * V_177 )
{
F_25 ( L_26 , V_58 , V_177 ,
V_177 -> V_204 , V_177 -> V_146 ) ;
V_177 -> V_205 = V_177 -> V_146 ;
F_107 ( V_177 ) ;
}
static void F_147 ( struct V_176 * V_177 )
{
F_25 ( L_25 , V_58 , V_177 ) ;
F_107 ( V_177 ) ;
}
static void F_148 ( struct V_211 * V_202 ,
struct V_212 * V_213 )
{
struct V_176 * V_177 = V_202 -> V_214 ;
T_8 V_215 ;
F_25 ( L_27 , V_58 , V_202 , V_213 ) ;
F_17 ( V_202 == V_177 -> V_202 ) ;
if ( F_105 ( V_177 ) ) {
F_17 ( V_177 -> V_179 ) ;
F_17 ( V_177 -> V_127 != V_192 ) ;
} else {
F_17 ( V_177 -> V_127 == V_192 ) ;
}
if ( V_202 -> V_216 < 0 )
V_177 -> V_204 = V_202 -> V_216 ;
F_17 ( V_202 -> V_217 <= V_218 ) ;
V_177 -> V_205 = V_202 -> V_219 [ 0 ] ;
F_17 ( V_177 -> V_205 < ( V_101 ) V_220 ) ;
V_215 = V_202 -> V_221 [ 0 ] . V_222 ;
switch ( V_215 ) {
case V_223 :
F_144 ( V_177 ) ;
break;
case V_224 :
F_17 ( V_202 -> V_221 [ 1 ] . V_222 == V_225 ) ;
case V_225 :
F_146 ( V_177 ) ;
break;
case V_226 :
F_147 ( V_177 ) ;
break;
case V_227 :
case V_228 :
case V_229 :
F_143 ( V_177 ) ;
break;
default:
F_102 ( NULL , L_28 ,
V_177 -> V_230 , ( unsigned short ) V_215 ) ;
break;
}
if ( F_108 ( V_177 ) )
F_141 ( V_177 ) ;
}
static void F_149 ( struct V_176 * V_177 )
{
struct V_188 * V_179 = V_177 -> V_179 ;
struct V_211 * V_202 = V_177 -> V_202 ;
V_101 V_46 ;
F_17 ( V_202 != NULL ) ;
V_46 = V_179 ? V_179 -> V_46 : V_47 ;
F_150 ( V_202 , V_177 -> V_140 ,
NULL , V_46 , NULL ) ;
}
static void F_151 ( struct V_176 * V_177 )
{
struct V_188 * V_179 = V_177 -> V_179 ;
struct V_211 * V_202 = V_177 -> V_202 ;
struct V_99 * V_107 ;
struct V_231 V_232 = V_233 ;
F_17 ( V_202 != NULL ) ;
V_107 = V_179 ? V_179 -> V_107 : NULL ;
F_150 ( V_202 , V_177 -> V_140 ,
V_107 , V_47 , & V_232 ) ;
}
static struct V_211 * F_152 (
struct V_21 * V_22 ,
bool V_234 ,
unsigned int V_235 ,
struct V_176 * V_177 )
{
struct V_99 * V_107 = NULL ;
struct V_200 * V_201 ;
struct V_211 * V_202 ;
if ( F_105 ( V_177 ) ) {
struct V_188 * V_179 = V_177 -> V_179 ;
F_17 ( V_234 ==
F_133 ( V_179 ) ) ;
if ( V_234 )
V_107 = V_179 -> V_107 ;
}
F_17 ( V_235 == 1 || ( V_234 && V_235 == 2 ) ) ;
V_201 = & V_22 -> V_53 -> V_63 -> V_201 ;
V_202 = F_153 ( V_201 , V_107 , V_235 , false ,
V_236 ) ;
if ( ! V_202 )
return NULL ;
if ( V_234 )
V_202 -> V_237 = V_238 | V_239 ;
else
V_202 -> V_237 = V_240 ;
V_202 -> V_241 = F_148 ;
V_202 -> V_214 = V_177 ;
V_202 -> V_242 . V_243 = F_154 ( V_22 -> V_244 ) ;
F_155 ( & V_202 -> V_245 , V_177 -> V_230 ) ;
return V_202 ;
}
static struct V_211 *
F_156 ( struct V_176 * V_177 )
{
struct V_188 * V_179 ;
struct V_99 * V_107 ;
struct V_21 * V_22 ;
struct V_200 * V_201 ;
struct V_211 * V_202 ;
F_17 ( F_105 ( V_177 ) ) ;
V_179 = V_177 -> V_179 ;
F_17 ( V_179 ) ;
F_17 ( F_133 ( V_179 ) ) ;
V_107 = V_179 -> V_107 ;
V_22 = V_179 -> V_22 ;
V_201 = & V_22 -> V_53 -> V_63 -> V_201 ;
V_202 = F_153 ( V_201 , V_107 , 3 , false , V_236 ) ;
if ( ! V_202 )
return NULL ;
V_202 -> V_237 = V_238 | V_239 ;
V_202 -> V_241 = F_148 ;
V_202 -> V_214 = V_177 ;
V_202 -> V_242 . V_243 = F_154 ( V_22 -> V_244 ) ;
F_155 ( & V_202 -> V_245 , V_177 -> V_230 ) ;
return V_202 ;
}
static void F_157 ( struct V_211 * V_202 )
{
F_158 ( V_202 ) ;
}
static struct V_176 * F_159 ( const char * V_230 ,
V_101 V_140 , V_101 V_146 ,
enum V_196 type )
{
struct V_176 * V_177 ;
T_6 V_91 ;
char * V_138 ;
F_17 ( F_123 ( type ) ) ;
V_91 = strlen ( V_230 ) + 1 ;
V_138 = F_26 ( V_91 , V_59 ) ;
if ( ! V_138 )
return NULL ;
V_177 = F_160 ( V_246 , V_59 ) ;
if ( ! V_177 ) {
F_36 ( V_138 ) ;
return NULL ;
}
V_177 -> V_230 = memcpy ( V_138 , V_230 , V_91 ) ;
V_177 -> V_140 = V_140 ;
V_177 -> V_146 = V_146 ;
V_177 -> V_32 = 0 ;
V_177 -> V_127 = V_192 ;
V_177 -> type = type ;
F_28 ( & V_177 -> V_193 ) ;
F_161 ( & V_177 -> V_203 ) ;
F_27 ( & V_177 -> V_61 ) ;
F_25 ( L_29 , V_58 , V_230 ,
V_140 , V_146 , ( int ) type , V_177 ) ;
return V_177 ;
}
static void V_187 ( struct V_61 * V_61 )
{
struct V_176 * V_177 ;
V_177 = F_52 ( V_61 , struct V_176 , V_61 ) ;
F_25 ( L_25 , V_58 , V_177 ) ;
F_17 ( V_177 -> V_179 == NULL ) ;
F_17 ( V_177 -> V_127 == V_192 ) ;
if ( V_177 -> V_202 )
F_157 ( V_177 -> V_202 ) ;
F_17 ( F_123 ( V_177 -> type ) ) ;
switch ( V_177 -> type ) {
case V_197 :
break;
case V_198 :
if ( V_177 -> V_209 )
F_84 ( V_177 -> V_209 ) ;
break;
case V_199 :
if ( V_177 -> V_163 )
F_162 ( V_177 -> V_163 ,
V_177 -> V_247 ) ;
break;
}
F_36 ( V_177 -> V_230 ) ;
V_177 -> V_230 = NULL ;
F_78 ( V_246 , V_177 ) ;
}
static void F_163 ( struct V_21 * V_22 )
{
F_164 ( V_22 ) ;
F_165 ( V_22 -> V_248 ) ;
V_22 -> V_248 = NULL ;
V_22 -> V_185 = 0 ;
}
static void F_166 ( struct V_21 * V_22 )
{
int V_2 ;
if ( ! V_22 -> V_248 )
return;
V_2 = F_4 ( & V_22 -> V_249 ) ;
if ( V_2 > 0 )
return;
if ( ! V_2 )
F_163 ( V_22 ) ;
else
F_102 ( V_22 , L_30 ) ;
}
static bool F_167 ( struct V_21 * V_22 )
{
int V_2 ;
if ( ! V_22 -> V_248 )
return false ;
V_2 = F_1 ( & V_22 -> V_249 ) ;
if ( V_2 > 0 && V_22 -> V_185 )
return true ;
if ( V_2 < 0 )
F_102 ( V_22 , L_31 ) ;
return false ;
}
static struct V_188 * F_168 (
struct V_21 * V_22 ,
V_101 V_140 , V_101 V_146 ,
bool V_234 )
{
struct V_188 * V_179 ;
V_179 = F_80 ( V_250 , V_143 ) ;
if ( ! V_179 )
return NULL ;
if ( V_234 ) {
F_169 ( & V_22 -> V_251 ) ;
F_170 ( V_22 -> V_104 . V_107 ) ;
F_171 ( & V_22 -> V_251 ) ;
}
V_179 -> V_252 = NULL ;
V_179 -> V_22 = V_22 ;
V_179 -> V_140 = V_140 ;
V_179 -> V_146 = V_146 ;
V_179 -> V_32 = 0 ;
if ( V_234 ) {
F_132 ( V_179 ) ;
V_179 -> V_107 = V_22 -> V_104 . V_107 ;
} else {
V_179 -> V_46 = V_22 -> V_45 -> V_46 ;
}
if ( F_167 ( V_22 ) )
F_137 ( V_179 ) ;
F_172 ( & V_179 -> V_253 ) ;
V_179 -> V_254 = 0 ;
V_179 -> V_195 = NULL ;
V_179 -> V_204 = 0 ;
V_179 -> V_191 = 0 ;
F_28 ( & V_179 -> V_194 ) ;
F_27 ( & V_179 -> V_61 ) ;
F_25 ( L_32 , V_58 , V_22 ,
V_234 ? L_33 : L_34 , V_140 , V_146 ,
V_179 ) ;
return V_179 ;
}
static void V_190 ( struct V_61 * V_61 )
{
struct V_188 * V_179 ;
struct V_176 * V_177 ;
struct V_176 * V_255 ;
V_179 = F_52 ( V_61 , struct V_188 , V_61 ) ;
F_25 ( L_22 , V_58 , V_179 ) ;
F_173 (img_request, obj_request, next_obj_request)
F_122 ( V_179 , V_177 ) ;
F_17 ( V_179 -> V_191 == 0 ) ;
if ( F_139 ( V_179 ) ) {
F_138 ( V_179 ) ;
F_166 ( V_179 -> V_22 ) ;
}
if ( F_133 ( V_179 ) )
F_63 ( V_179 -> V_107 ) ;
F_78 ( V_250 , V_179 ) ;
}
static struct V_188 * F_174 (
struct V_176 * V_177 ,
V_101 V_184 , V_101 V_146 )
{
struct V_188 * V_256 ;
struct V_21 * V_22 ;
F_17 ( V_177 -> V_179 ) ;
V_22 = V_177 -> V_179 -> V_22 ;
V_256 = F_168 ( V_22 -> V_257 ,
V_184 , V_146 , false ) ;
if ( ! V_256 )
return NULL ;
F_134 ( V_256 ) ;
F_115 ( V_177 ) ;
V_256 -> V_177 = V_177 ;
return V_256 ;
}
static void V_189 ( struct V_61 * V_61 )
{
struct V_188 * V_256 ;
struct V_176 * V_258 ;
V_256 = F_52 ( V_61 , struct V_188 , V_61 ) ;
V_258 = V_256 -> V_177 ;
V_256 -> V_177 = NULL ;
F_117 ( V_258 ) ;
F_135 ( V_256 ) ;
V_190 ( V_61 ) ;
}
static bool F_175 ( struct V_176 * V_177 )
{
struct V_188 * V_179 ;
unsigned int V_205 ;
int V_204 ;
bool V_259 ;
F_17 ( F_105 ( V_177 ) ) ;
V_179 = V_177 -> V_179 ;
F_17 ( V_177 -> V_205 <= ( V_101 ) V_220 ) ;
V_205 = ( unsigned int ) V_177 -> V_205 ;
V_204 = V_177 -> V_204 ;
if ( V_204 ) {
struct V_21 * V_22 = V_179 -> V_22 ;
F_102 ( V_22 , L_35 ,
F_133 ( V_179 ) ? L_33 : L_34 ,
V_177 -> V_146 , V_177 -> V_184 ,
V_177 -> V_140 ) ;
F_102 ( V_22 , L_36 ,
V_204 , V_205 ) ;
if ( ! V_179 -> V_204 )
V_179 -> V_204 = V_204 ;
}
if ( V_177 -> type == V_199 ) {
V_177 -> V_163 = NULL ;
V_177 -> V_247 = 0 ;
}
if ( F_120 ( V_179 ) ) {
F_17 ( V_179 -> V_177 != NULL ) ;
V_259 = V_177 -> V_127 < V_179 -> V_191 - 1 ;
} else {
F_17 ( V_179 -> V_252 != NULL ) ;
V_259 = F_176 ( V_179 -> V_252 , V_204 , V_205 ) ;
}
return V_259 ;
}
static void F_177 ( struct V_176 * V_177 )
{
struct V_188 * V_179 ;
T_5 V_127 = V_177 -> V_127 ;
bool V_259 = true ;
F_17 ( F_105 ( V_177 ) ) ;
V_179 = V_177 -> V_179 ;
F_25 ( L_37 , V_58 , V_179 , V_177 ) ;
F_17 ( V_179 != NULL ) ;
F_17 ( V_179 -> V_191 > 0 ) ;
F_17 ( V_127 != V_192 ) ;
F_17 ( V_127 < V_179 -> V_191 ) ;
F_12 ( & V_179 -> V_253 ) ;
if ( V_127 != V_179 -> V_254 )
goto V_49;
F_178 (img_request, obj_request) {
F_17 ( V_259 ) ;
F_17 ( V_127 < V_179 -> V_191 ) ;
if ( ! F_108 ( V_177 ) )
break;
V_259 = F_175 ( V_177 ) ;
V_127 ++ ;
}
F_17 ( V_259 ^ ( V_127 == V_179 -> V_191 ) ) ;
V_179 -> V_254 = V_127 ;
V_49:
F_14 ( & V_179 -> V_253 ) ;
F_119 ( V_179 ) ;
if ( ! V_259 )
F_130 ( V_179 ) ;
}
static int F_179 ( struct V_188 * V_179 ,
enum V_196 type ,
void * V_260 )
{
struct V_21 * V_22 = V_179 -> V_22 ;
struct V_176 * V_177 = NULL ;
struct V_176 * V_255 ;
bool V_234 = F_133 ( V_179 ) ;
struct V_148 * V_209 = NULL ;
unsigned int V_261 = 0 ;
struct V_162 * * V_163 = NULL ;
V_101 V_184 ;
V_101 V_262 ;
T_8 V_215 ;
F_25 ( L_38 , V_58 , V_179 ,
( int ) type , V_260 ) ;
V_215 = V_234 ? V_225 : V_223 ;
V_184 = V_179 -> V_140 ;
V_262 = V_179 -> V_146 ;
F_17 ( V_262 > 0 ) ;
if ( type == V_198 ) {
V_209 = V_260 ;
F_17 ( V_184 ==
V_209 -> V_172 . V_263 << V_97 ) ;
} else {
F_17 ( type == V_199 ) ;
V_163 = V_260 ;
}
while ( V_262 ) {
struct V_211 * V_202 ;
const char * V_230 ;
V_101 V_140 ;
V_101 V_146 ;
unsigned int V_127 = 0 ;
V_230 = F_79 ( V_22 , V_184 ) ;
if ( ! V_230 )
goto V_264;
V_140 = F_81 ( V_22 , V_184 ) ;
V_146 = F_82 ( V_22 , V_184 , V_262 ) ;
V_177 = F_159 ( V_230 ,
V_140 , V_146 , type ) ;
F_77 ( V_230 ) ;
if ( ! V_177 )
goto V_264;
F_121 ( V_179 , V_177 ) ;
if ( type == V_198 ) {
unsigned int V_265 ;
F_17 ( V_146 <= ( V_101 ) V_220 ) ;
V_265 = ( unsigned int ) V_146 ;
V_177 -> V_209 =
F_101 ( & V_209 ,
& V_261 ,
V_265 ,
V_236 ) ;
if ( ! V_177 -> V_209 )
goto V_264;
} else {
unsigned int V_247 ;
V_177 -> V_163 = V_163 ;
V_247 = ( T_5 ) F_180 ( V_140 , V_146 ) ;
V_177 -> V_247 = V_247 ;
if ( ( V_140 + V_146 ) & ~ V_168 )
V_247 -- ;
V_163 += V_247 ;
}
V_202 = F_152 ( V_22 , V_234 ,
( V_234 ? 2 : 1 ) ,
V_177 ) ;
if ( ! V_202 )
goto V_264;
V_177 -> V_202 = V_202 ;
V_177 -> V_195 = F_177 ;
F_118 ( V_179 ) ;
if ( V_234 ) {
F_181 ( V_202 , V_127 ,
F_83 ( & V_22 -> V_104 ) ,
F_83 ( & V_22 -> V_104 ) ) ;
V_127 ++ ;
}
F_182 ( V_202 , V_127 , V_215 , V_140 , V_146 ,
0 , 0 ) ;
if ( type == V_198 )
F_183 ( V_202 , V_127 ,
V_177 -> V_209 , V_146 ) ;
else
F_184 ( V_202 , V_127 ,
V_177 -> V_163 , V_146 ,
V_140 & ~ V_168 , false , false ) ;
if ( V_234 )
F_151 ( V_177 ) ;
else
F_149 ( V_177 ) ;
V_177 -> V_184 = V_184 ;
V_184 += V_146 ;
V_262 -= V_146 ;
}
return 0 ;
V_264:
F_173 (img_request, obj_request, next_obj_request)
F_122 ( V_179 , V_177 ) ;
return - V_57 ;
}
static void
F_185 ( struct V_176 * V_177 )
{
struct V_188 * V_179 ;
struct V_21 * V_22 ;
struct V_162 * * V_163 ;
T_5 V_247 ;
F_17 ( V_177 -> type == V_198 ) ;
F_17 ( F_105 ( V_177 ) ) ;
V_179 = V_177 -> V_179 ;
F_17 ( V_179 ) ;
V_22 = V_179 -> V_22 ;
F_17 ( V_22 ) ;
V_163 = V_177 -> V_266 ;
F_17 ( V_163 != NULL ) ;
V_177 -> V_266 = NULL ;
V_247 = V_177 -> V_267 ;
F_17 ( V_247 ) ;
V_177 -> V_267 = 0 ;
F_162 ( V_163 , V_247 ) ;
if ( ! V_177 -> V_204 )
V_177 -> V_205 = V_177 -> V_146 ;
F_177 ( V_177 ) ;
}
static void
F_186 ( struct V_188 * V_179 )
{
struct V_176 * V_258 ;
struct V_211 * V_202 ;
struct V_200 * V_201 ;
struct V_21 * V_22 ;
struct V_162 * * V_163 ;
T_5 V_247 ;
int V_268 ;
V_101 V_269 ;
V_101 V_140 ;
V_101 V_146 ;
F_17 ( F_120 ( V_179 ) ) ;
V_163 = V_179 -> V_266 ;
F_17 ( V_163 != NULL ) ;
V_179 -> V_266 = NULL ;
V_247 = V_179 -> V_267 ;
F_17 ( V_247 ) ;
V_179 -> V_267 = 0 ;
V_258 = V_179 -> V_177 ;
F_17 ( V_258 != NULL ) ;
F_17 ( F_123 ( V_258 -> type ) ) ;
V_268 = V_179 -> V_204 ;
V_269 = V_179 -> V_146 ;
F_17 ( V_269 == V_179 -> V_205 ) ;
F_119 ( V_179 ) ;
F_17 ( V_258 -> V_179 ) ;
V_22 = V_258 -> V_179 -> V_22 ;
F_17 ( V_22 ) ;
if ( ! V_22 -> V_185 ) {
struct V_200 * V_201 ;
F_162 ( V_163 , V_247 ) ;
V_201 = & V_22 -> V_53 -> V_63 -> V_201 ;
V_268 = F_124 ( V_201 , V_258 ) ;
if ( ! V_268 )
return;
}
if ( V_268 )
goto V_112;
V_268 = - V_57 ;
V_202 = F_156 ( V_258 ) ;
if ( ! V_202 )
goto V_112;
F_157 ( V_258 -> V_202 ) ;
V_258 -> V_202 = V_202 ;
V_258 -> V_266 = V_163 ;
V_258 -> V_267 = V_247 ;
F_187 ( V_202 , 0 , V_227 , L_39 , L_40 ) ;
F_188 ( V_202 , 0 , V_163 , V_269 , 0 ,
false , false ) ;
F_181 ( V_202 , 1 , F_83 ( & V_22 -> V_104 ) ,
F_83 ( & V_22 -> V_104 ) ) ;
V_140 = V_258 -> V_140 ;
V_146 = V_258 -> V_146 ;
F_182 ( V_202 , 2 , V_225 ,
V_140 , V_146 , 0 , 0 ) ;
if ( V_258 -> type == V_198 )
F_183 ( V_202 , 2 ,
V_258 -> V_209 , V_146 ) ;
else
F_184 ( V_202 , 2 ,
V_258 -> V_163 , V_146 ,
V_140 & ~ V_168 , false , false ) ;
F_151 ( V_258 ) ;
V_258 -> V_195 = F_185 ;
V_201 = & V_22 -> V_53 -> V_63 -> V_201 ;
V_268 = F_124 ( V_201 , V_258 ) ;
if ( ! V_268 )
return;
V_112:
V_258 -> V_204 = V_268 ;
V_258 -> V_205 = 0 ;
F_107 ( V_258 ) ;
F_141 ( V_258 ) ;
}
static int F_189 ( struct V_176 * V_177 )
{
struct V_188 * V_179 = NULL ;
struct V_188 * V_256 = NULL ;
struct V_21 * V_22 ;
V_101 V_184 ;
V_101 V_146 ;
struct V_162 * * V_163 = NULL ;
T_5 V_247 ;
int V_204 ;
F_17 ( F_105 ( V_177 ) ) ;
F_17 ( F_123 ( V_177 -> type ) ) ;
V_179 = V_177 -> V_179 ;
F_17 ( V_179 != NULL ) ;
V_22 = V_179 -> V_22 ;
F_17 ( V_22 -> V_257 != NULL ) ;
V_184 = V_177 -> V_184 - V_177 -> V_140 ;
V_146 = ( V_101 ) 1 << V_22 -> V_104 . V_120 ;
if ( V_184 + V_146 > V_22 -> V_185 ) {
F_17 ( V_184 < V_22 -> V_185 ) ;
V_146 = V_22 -> V_185 - V_184 ;
}
V_247 = ( T_5 ) F_180 ( 0 , V_146 ) ;
V_163 = F_190 ( V_247 , V_59 ) ;
if ( F_30 ( V_163 ) ) {
V_204 = F_191 ( V_163 ) ;
V_163 = NULL ;
goto V_112;
}
V_204 = - V_57 ;
V_256 = F_174 ( V_177 ,
V_184 , V_146 ) ;
if ( ! V_256 )
goto V_112;
V_204 = F_179 ( V_256 , V_199 , V_163 ) ;
if ( V_204 )
goto V_112;
V_256 -> V_266 = V_163 ;
V_256 -> V_267 = V_247 ;
V_256 -> V_195 = F_186 ;
V_204 = F_192 ( V_256 ) ;
if ( ! V_204 )
return 0 ;
V_256 -> V_266 = NULL ;
V_256 -> V_267 = 0 ;
V_256 -> V_177 = NULL ;
F_117 ( V_177 ) ;
V_112:
if ( V_163 )
F_162 ( V_163 , V_247 ) ;
if ( V_256 )
F_119 ( V_256 ) ;
V_177 -> V_204 = V_204 ;
V_177 -> V_205 = 0 ;
F_107 ( V_177 ) ;
return V_204 ;
}
static void F_193 ( struct V_176 * V_177 )
{
struct V_176 * V_258 ;
struct V_21 * V_22 ;
int V_204 ;
F_17 ( ! F_105 ( V_177 ) ) ;
V_258 = V_177 -> V_177 ;
V_177 -> V_177 = NULL ;
F_117 ( V_258 ) ;
F_17 ( V_258 ) ;
F_17 ( V_258 -> V_179 ) ;
V_204 = V_177 -> V_204 ;
V_177 -> V_204 = 0 ;
F_25 ( L_41 , V_58 ,
V_177 , V_258 , V_204 ,
V_177 -> V_205 , V_177 -> V_146 ) ;
F_117 ( V_177 ) ;
V_22 = V_258 -> V_179 -> V_22 ;
if ( ! V_22 -> V_185 ) {
struct V_200 * V_201 ;
V_201 = & V_22 -> V_53 -> V_63 -> V_201 ;
V_204 = F_124 ( V_201 , V_258 ) ;
if ( ! V_204 )
return;
}
if ( ! V_204 ) {
F_109 ( V_258 , true ) ;
} else if ( V_204 == - V_34 ) {
F_109 ( V_258 , false ) ;
} else if ( V_204 ) {
V_258 -> V_204 = V_204 ;
goto V_49;
}
V_258 -> V_204 = F_194 ( V_258 ) ;
V_49:
if ( V_258 -> V_204 )
F_141 ( V_258 ) ;
}
static int F_195 ( struct V_176 * V_177 )
{
struct V_176 * V_270 ;
struct V_21 * V_22 ;
struct V_200 * V_201 ;
struct V_162 * * V_163 = NULL ;
T_5 V_247 ;
T_6 V_91 ;
int V_39 ;
V_91 = sizeof ( V_100 ) + sizeof ( V_271 ) + sizeof ( V_271 ) ;
V_247 = ( T_5 ) F_180 ( 0 , V_91 ) ;
V_163 = F_190 ( V_247 , V_59 ) ;
if ( F_30 ( V_163 ) )
return F_191 ( V_163 ) ;
V_39 = - V_57 ;
V_270 = F_159 ( V_177 -> V_230 , 0 , 0 ,
V_199 ) ;
if ( ! V_270 )
goto V_49;
F_115 ( V_177 ) ;
V_270 -> V_177 = V_177 ;
V_270 -> V_163 = V_163 ;
V_270 -> V_247 = V_247 ;
F_17 ( V_177 -> V_179 ) ;
V_22 = V_177 -> V_179 -> V_22 ;
V_270 -> V_202 = F_152 ( V_22 , false , 1 ,
V_270 ) ;
if ( ! V_270 -> V_202 )
goto V_49;
V_270 -> V_195 = F_193 ;
F_196 ( V_270 -> V_202 , 0 , V_226 ) ;
F_197 ( V_270 -> V_202 , 0 , V_163 , V_91 , 0 ,
false , false ) ;
F_149 ( V_270 ) ;
V_201 = & V_22 -> V_53 -> V_63 -> V_201 ;
V_39 = F_124 ( V_201 , V_270 ) ;
V_49:
if ( V_39 )
F_117 ( V_177 ) ;
return V_39 ;
}
static int F_194 ( struct V_176 * V_177 )
{
struct V_188 * V_179 ;
struct V_21 * V_22 ;
bool V_272 ;
F_17 ( F_105 ( V_177 ) ) ;
V_179 = V_177 -> V_179 ;
F_17 ( V_179 ) ;
V_22 = V_179 -> V_22 ;
if ( ! F_133 ( V_179 ) ||
! F_139 ( V_179 ) ||
! F_113 ( V_177 ) ||
( ( V_272 = F_111 ( V_177 ) ) &&
F_112 ( V_177 ) ) ) {
struct V_21 * V_22 ;
struct V_200 * V_201 ;
V_22 = V_177 -> V_179 -> V_22 ;
V_201 = & V_22 -> V_53 -> V_63 -> V_201 ;
return F_124 ( V_201 , V_177 ) ;
}
if ( V_272 )
return F_189 ( V_177 ) ;
return F_195 ( V_177 ) ;
}
static int F_192 ( struct V_188 * V_179 )
{
struct V_176 * V_177 ;
struct V_176 * V_255 ;
F_25 ( L_22 , V_58 , V_179 ) ;
F_173 (img_request, obj_request, next_obj_request) {
int V_39 ;
V_39 = F_194 ( V_177 ) ;
if ( V_39 )
return V_39 ;
}
return 0 ;
}
static void F_198 ( struct V_188 * V_179 )
{
struct V_176 * V_177 ;
struct V_21 * V_22 ;
V_101 V_273 ;
V_101 V_274 ;
int V_268 ;
F_17 ( F_120 ( V_179 ) ) ;
V_177 = V_179 -> V_177 ;
V_274 = V_179 -> V_205 ;
V_268 = V_179 -> V_204 ;
F_119 ( V_179 ) ;
F_17 ( V_177 ) ;
F_17 ( V_177 -> V_179 ) ;
V_22 = V_177 -> V_179 -> V_22 ;
if ( ! V_22 -> V_185 ) {
struct V_200 * V_201 ;
V_201 = & V_22 -> V_53 -> V_63 -> V_201 ;
V_268 = F_124 ( V_201 , V_177 ) ;
if ( ! V_268 )
return;
}
V_177 -> V_204 = V_268 ;
if ( V_177 -> V_204 )
goto V_49;
F_17 ( V_177 -> V_184 < V_147 - V_177 -> V_146 ) ;
V_273 = V_177 -> V_184 + V_177 -> V_146 ;
if ( V_273 > V_22 -> V_185 ) {
V_101 V_205 = 0 ;
if ( V_177 -> V_184 < V_22 -> V_185 )
V_205 = V_22 -> V_185 -
V_177 -> V_184 ;
V_177 -> V_205 = F_199 ( V_274 , V_205 ) ;
} else {
V_177 -> V_205 = V_274 ;
}
V_49:
F_140 ( V_177 ) ;
F_141 ( V_177 ) ;
}
static void F_145 ( struct V_176 * V_177 )
{
struct V_188 * V_179 ;
int V_204 ;
F_17 ( F_105 ( V_177 ) ) ;
F_17 ( V_177 -> V_179 != NULL ) ;
F_17 ( V_177 -> V_204 == ( V_275 ) - V_34 ) ;
F_17 ( F_123 ( V_177 -> type ) ) ;
V_179 = F_174 ( V_177 ,
V_177 -> V_184 ,
V_177 -> V_146 ) ;
V_204 = - V_57 ;
if ( ! V_179 )
goto V_112;
if ( V_177 -> type == V_198 )
V_204 = F_179 ( V_179 , V_198 ,
V_177 -> V_209 ) ;
else
V_204 = F_179 ( V_179 , V_199 ,
V_177 -> V_163 ) ;
if ( V_204 )
goto V_112;
V_179 -> V_195 = F_198 ;
V_204 = F_192 ( V_179 ) ;
if ( V_204 )
goto V_112;
return;
V_112:
if ( V_179 )
F_119 ( V_179 ) ;
V_177 -> V_204 = V_204 ;
V_177 -> V_205 = 0 ;
F_107 ( V_177 ) ;
}
static int F_200 ( struct V_21 * V_22 , V_101 V_276 )
{
struct V_176 * V_177 ;
struct V_200 * V_201 = & V_22 -> V_53 -> V_63 -> V_201 ;
int V_39 ;
V_177 = F_159 ( V_22 -> V_277 , 0 , 0 ,
V_197 ) ;
if ( ! V_177 )
return - V_57 ;
V_39 = - V_57 ;
V_177 -> V_202 = F_152 ( V_22 , false , 1 ,
V_177 ) ;
if ( ! V_177 -> V_202 )
goto V_49;
F_201 ( V_177 -> V_202 , 0 , V_228 ,
V_276 , 0 , 0 ) ;
F_149 ( V_177 ) ;
V_39 = F_124 ( V_201 , V_177 ) ;
if ( V_39 )
goto V_49;
V_39 = F_128 ( V_177 ) ;
V_49:
F_117 ( V_177 ) ;
return V_39 ;
}
static void F_202 ( V_101 V_278 , V_101 V_276 , T_9 V_215 , void * V_279 )
{
struct V_21 * V_22 = (struct V_21 * ) V_279 ;
int V_39 ;
if ( ! V_22 )
return;
F_25 ( L_42 , V_58 ,
V_22 -> V_277 , ( unsigned long long ) V_276 ,
( unsigned int ) V_215 ) ;
V_39 = F_203 ( V_22 ) ;
if ( V_39 )
F_102 ( V_22 , L_43 , V_39 ) ;
V_39 = F_200 ( V_22 , V_276 ) ;
if ( V_39 )
F_102 ( V_22 , L_44 , V_39 ) ;
}
static struct V_176 * F_204 (
struct V_21 * V_22 ,
bool V_280 )
{
struct V_200 * V_201 = & V_22 -> V_53 -> V_63 -> V_201 ;
struct V_176 * V_177 ;
int V_39 ;
V_177 = F_159 ( V_22 -> V_277 , 0 , 0 ,
V_197 ) ;
if ( ! V_177 )
return F_38 ( - V_57 ) ;
V_177 -> V_202 = F_152 ( V_22 , true , 1 ,
V_177 ) ;
if ( ! V_177 -> V_202 ) {
V_39 = - V_57 ;
goto V_49;
}
F_201 ( V_177 -> V_202 , 0 , V_229 ,
V_22 -> V_281 -> V_282 , 0 , V_280 ) ;
F_151 ( V_177 ) ;
if ( V_280 )
F_205 ( V_201 , V_177 -> V_202 ) ;
V_39 = F_124 ( V_201 , V_177 ) ;
if ( V_39 )
goto V_49;
V_39 = F_128 ( V_177 ) ;
if ( V_39 )
goto V_49;
V_39 = V_177 -> V_204 ;
if ( V_39 ) {
if ( V_280 )
F_126 ( V_177 ) ;
goto V_49;
}
return V_177 ;
V_49:
F_117 ( V_177 ) ;
return F_38 ( V_39 ) ;
}
static int F_206 ( struct V_21 * V_22 )
{
struct V_200 * V_201 = & V_22 -> V_53 -> V_63 -> V_201 ;
struct V_176 * V_177 ;
int V_39 ;
F_17 ( ! V_22 -> V_281 ) ;
F_17 ( ! V_22 -> V_283 ) ;
V_39 = F_207 ( V_201 , F_202 , V_22 ,
& V_22 -> V_281 ) ;
if ( V_39 < 0 )
return V_39 ;
V_177 = F_204 ( V_22 , true ) ;
if ( F_30 ( V_177 ) ) {
F_208 ( V_22 -> V_281 ) ;
V_22 -> V_281 = NULL ;
return F_191 ( V_177 ) ;
}
V_22 -> V_283 = V_177 ;
return 0 ;
}
static void F_209 ( struct V_21 * V_22 )
{
struct V_176 * V_177 ;
F_17 ( V_22 -> V_281 ) ;
F_17 ( V_22 -> V_283 ) ;
F_126 ( V_22 -> V_283 ) ;
F_117 ( V_22 -> V_283 ) ;
V_22 -> V_283 = NULL ;
V_177 = F_204 ( V_22 , false ) ;
if ( ! F_30 ( V_177 ) )
F_117 ( V_177 ) ;
else
F_102 ( V_22 , L_45 ,
F_191 ( V_177 ) ) ;
F_208 ( V_22 -> V_281 ) ;
V_22 -> V_281 = NULL ;
}
static int F_210 ( struct V_21 * V_22 ,
const char * V_230 ,
const char * V_284 ,
const char * V_285 ,
const void * V_286 ,
T_6 V_287 ,
void * V_288 ,
T_6 V_289 )
{
struct V_200 * V_201 = & V_22 -> V_53 -> V_63 -> V_201 ;
struct V_176 * V_177 ;
struct V_162 * * V_163 ;
T_5 V_247 ;
int V_39 ;
V_247 = ( T_5 ) F_180 ( 0 , V_289 ) ;
V_163 = F_190 ( V_247 , V_59 ) ;
if ( F_30 ( V_163 ) )
return F_191 ( V_163 ) ;
V_39 = - V_57 ;
V_177 = F_159 ( V_230 , 0 , V_289 ,
V_199 ) ;
if ( ! V_177 )
goto V_49;
V_177 -> V_163 = V_163 ;
V_177 -> V_247 = V_247 ;
V_177 -> V_202 = F_152 ( V_22 , false , 1 ,
V_177 ) ;
if ( ! V_177 -> V_202 )
goto V_49;
F_187 ( V_177 -> V_202 , 0 , V_227 ,
V_284 , V_285 ) ;
if ( V_287 ) {
struct V_290 * V_291 ;
V_291 = F_26 ( sizeof ( * V_291 ) , V_292 ) ;
if ( ! V_291 )
goto V_49;
F_211 ( V_291 ) ;
F_212 ( V_291 , V_286 , V_287 ) ;
F_213 ( V_177 -> V_202 , 0 ,
V_291 ) ;
}
F_214 ( V_177 -> V_202 , 0 ,
V_177 -> V_163 , V_289 ,
0 , false , false ) ;
F_149 ( V_177 ) ;
V_39 = F_124 ( V_201 , V_177 ) ;
if ( V_39 )
goto V_49;
V_39 = F_128 ( V_177 ) ;
if ( V_39 )
goto V_49;
V_39 = V_177 -> V_204 ;
if ( V_39 < 0 )
goto V_49;
F_17 ( V_177 -> V_205 < ( V_101 ) V_3 ) ;
V_39 = ( int ) V_177 -> V_205 ;
F_215 ( V_163 , V_288 , 0 , V_177 -> V_205 ) ;
V_49:
if ( V_177 )
F_117 ( V_177 ) ;
else
F_162 ( V_163 , V_247 ) ;
return V_39 ;
}
static void F_216 ( struct V_21 * V_22 , struct V_293 * V_252 )
{
struct V_188 * V_179 ;
V_101 V_140 = ( V_101 ) F_217 ( V_252 ) << V_97 ;
V_101 V_146 = F_218 ( V_252 ) ;
bool V_294 = F_219 ( V_252 ) == V_295 ;
int V_204 ;
if ( ! V_146 ) {
F_25 ( L_46 , V_58 ) ;
V_204 = 0 ;
goto V_296;
}
if ( V_294 ) {
if ( V_22 -> V_27 . V_28 ) {
V_204 = - V_29 ;
goto V_296;
}
F_17 ( V_22 -> V_45 -> V_46 == V_47 ) ;
}
if ( ! F_13 ( V_297 , & V_22 -> V_32 ) ) {
F_25 ( L_47 ) ;
F_17 ( V_22 -> V_45 -> V_46 != V_47 ) ;
V_204 = - V_298 ;
goto V_296;
}
if ( V_140 && V_146 > V_147 - V_140 + 1 ) {
F_102 ( V_22 , L_48 , V_140 ,
V_146 ) ;
V_204 = - V_4 ;
goto V_296;
}
if ( V_140 + V_146 > V_22 -> V_27 . V_91 ) {
F_102 ( V_22 , L_49 , V_140 ,
V_146 , V_22 -> V_27 . V_91 ) ;
V_204 = - V_126 ;
goto V_296;
}
V_179 = F_168 ( V_22 , V_140 , V_146 , V_294 ) ;
if ( ! V_179 ) {
V_204 = - V_57 ;
goto V_296;
}
V_179 -> V_252 = V_252 ;
V_204 = F_179 ( V_179 , V_198 , V_252 -> V_148 ) ;
if ( V_204 )
goto V_299;
V_204 = F_192 ( V_179 ) ;
if ( V_204 )
goto V_299;
return;
V_299:
F_119 ( V_179 ) ;
V_296:
if ( V_204 )
F_102 ( V_22 , L_50 ,
V_294 ? L_33 : L_34 , V_146 , V_140 , V_204 ) ;
F_220 ( V_252 , V_204 ) ;
}
static void F_221 ( struct V_300 * V_301 )
{
struct V_21 * V_22 =
F_52 ( V_301 , struct V_21 , V_302 ) ;
struct V_293 * V_252 , * V_303 ;
F_222 ( V_304 ) ;
F_12 ( & V_22 -> V_30 ) ;
F_223 ( & V_22 -> V_305 , & V_304 ) ;
F_14 ( & V_22 -> V_30 ) ;
F_224 (rq, next, &requests, queuelist) {
F_225 ( & V_252 -> V_306 ) ;
F_216 ( V_22 , V_252 ) ;
}
}
static void F_226 ( struct V_307 * V_308 )
{
struct V_21 * V_22 = V_308 -> V_309 ;
struct V_293 * V_252 ;
int V_310 = 0 ;
F_17 ( V_22 ) ;
while ( ( V_252 = F_227 ( V_308 ) ) ) {
if ( V_252 -> V_311 != V_312 ) {
F_25 ( L_51 , V_58 ,
( int ) V_252 -> V_311 ) ;
F_228 ( V_252 , 0 ) ;
continue;
}
F_33 ( & V_252 -> V_306 , & V_22 -> V_305 ) ;
V_310 ++ ;
}
if ( V_310 )
F_229 ( V_22 -> V_313 , & V_22 -> V_302 ) ;
}
static int F_230 ( struct V_307 * V_308 , struct V_314 * V_315 ,
struct V_153 * V_316 )
{
struct V_21 * V_22 = V_308 -> V_309 ;
T_10 V_317 ;
T_10 V_318 ;
T_10 V_319 ;
int V_39 ;
V_317 = F_231 ( V_315 -> V_320 ) + V_315 -> V_263 ;
V_318 = 1 << ( V_22 -> V_104 . V_120 - V_97 ) ;
V_319 = V_317 & ( V_318 - 1 ) ;
V_39 = ( int ) ( V_318 - V_319 ) << V_97 ;
if ( V_39 > V_315 -> V_173 )
V_39 -= V_315 -> V_173 ;
else
V_39 = 0 ;
F_17 ( V_316 -> V_159 <= V_169 ) ;
if ( V_39 > ( int ) V_316 -> V_159 || ! V_315 -> V_173 )
V_39 = ( int ) V_316 -> V_159 ;
return V_39 ;
}
static void F_232 ( struct V_21 * V_22 )
{
struct V_35 * V_36 = V_22 -> V_36 ;
if ( ! V_36 )
return;
V_22 -> V_36 = NULL ;
if ( V_36 -> V_32 & V_321 ) {
F_233 ( V_36 ) ;
if ( V_36 -> V_322 )
F_234 ( V_36 -> V_322 ) ;
}
F_235 ( V_36 ) ;
}
static int F_236 ( struct V_21 * V_22 ,
const char * V_230 ,
V_101 V_140 , V_101 V_146 , void * V_157 )
{
struct V_200 * V_201 = & V_22 -> V_53 -> V_63 -> V_201 ;
struct V_176 * V_177 ;
struct V_162 * * V_163 = NULL ;
T_5 V_247 ;
T_6 V_91 ;
int V_39 ;
V_247 = ( T_5 ) F_180 ( V_140 , V_146 ) ;
V_163 = F_190 ( V_247 , V_59 ) ;
if ( F_30 ( V_163 ) )
V_39 = F_191 ( V_163 ) ;
V_39 = - V_57 ;
V_177 = F_159 ( V_230 , V_140 , V_146 ,
V_199 ) ;
if ( ! V_177 )
goto V_49;
V_177 -> V_163 = V_163 ;
V_177 -> V_247 = V_247 ;
V_177 -> V_202 = F_152 ( V_22 , false , 1 ,
V_177 ) ;
if ( ! V_177 -> V_202 )
goto V_49;
F_182 ( V_177 -> V_202 , 0 , V_223 ,
V_140 , V_146 , 0 , 0 ) ;
F_184 ( V_177 -> V_202 , 0 ,
V_177 -> V_163 ,
V_177 -> V_146 ,
V_177 -> V_140 & ~ V_168 ,
false , false ) ;
F_149 ( V_177 ) ;
V_39 = F_124 ( V_201 , V_177 ) ;
if ( V_39 )
goto V_49;
V_39 = F_128 ( V_177 ) ;
if ( V_39 )
goto V_49;
V_39 = V_177 -> V_204 ;
if ( V_39 < 0 )
goto V_49;
F_17 ( V_177 -> V_205 <= ( V_101 ) V_98 ) ;
V_91 = ( T_6 ) V_177 -> V_205 ;
F_215 ( V_163 , V_157 , 0 , V_91 ) ;
F_17 ( V_91 <= ( T_6 ) V_3 ) ;
V_39 = ( int ) V_91 ;
V_49:
if ( V_177 )
F_117 ( V_177 ) ;
else
F_162 ( V_163 , V_247 ) ;
return V_39 ;
}
static int F_237 ( struct V_21 * V_22 )
{
struct V_89 * V_90 = NULL ;
T_5 V_92 = 0 ;
V_101 V_323 = 0 ;
T_5 V_324 ;
int V_39 ;
do {
T_6 V_91 ;
F_36 ( V_90 ) ;
V_91 = sizeof ( * V_90 ) ;
V_91 += V_92 * sizeof ( struct V_115 ) ;
V_91 += V_323 ;
V_90 = F_26 ( V_91 , V_59 ) ;
if ( ! V_90 )
return - V_57 ;
V_39 = F_236 ( V_22 , V_22 -> V_277 ,
0 , V_91 , V_90 ) ;
if ( V_39 < 0 )
goto V_49;
if ( ( T_6 ) V_39 < V_91 ) {
V_39 = - V_298 ;
F_102 ( V_22 , L_52 ,
V_91 , V_39 ) ;
goto V_49;
}
if ( ! F_57 ( V_90 ) ) {
V_39 = - V_298 ;
F_102 ( V_22 , L_53 ) ;
goto V_49;
}
V_323 = F_59 ( V_90 -> V_102 ) ;
V_324 = V_92 ;
V_92 = F_58 ( V_90 -> V_92 ) ;
} while ( V_92 != V_324 );
V_39 = F_60 ( V_22 , V_90 ) ;
V_49:
F_36 ( V_90 ) ;
return V_39 ;
}
static void F_238 ( struct V_21 * V_22 )
{
V_101 V_46 ;
if ( ! F_13 ( V_297 , & V_22 -> V_32 ) )
return;
V_46 = V_22 -> V_45 -> V_46 ;
if ( V_46 == V_47 )
return;
if ( F_67 ( V_22 , V_46 ) == V_134 )
F_136 ( V_297 , & V_22 -> V_32 ) ;
}
static void F_239 ( struct V_21 * V_22 )
{
T_10 V_91 ;
bool V_25 ;
F_12 ( & V_22 -> V_30 ) ;
V_25 = F_13 ( V_31 , & V_22 -> V_32 ) ;
F_14 ( & V_22 -> V_30 ) ;
if ( ! V_25 ) {
V_91 = ( T_10 ) V_22 -> V_27 . V_91 / V_325 ;
F_25 ( L_54 , ( unsigned long long ) V_91 ) ;
F_240 ( V_22 -> V_36 , V_91 ) ;
F_241 ( V_22 -> V_36 ) ;
}
}
static int F_203 ( struct V_21 * V_22 )
{
V_101 V_326 ;
int V_39 ;
F_242 ( & V_22 -> V_251 ) ;
V_326 = V_22 -> V_27 . V_91 ;
V_39 = F_243 ( V_22 ) ;
if ( V_39 )
return V_39 ;
if ( V_22 -> V_257 ) {
V_39 = F_244 ( V_22 ) ;
if ( V_39 )
return V_39 ;
}
if ( V_22 -> V_45 -> V_46 == V_47 ) {
if ( V_22 -> V_27 . V_91 != V_22 -> V_104 . V_119 )
V_22 -> V_27 . V_91 = V_22 -> V_104 . V_119 ;
} else {
F_238 ( V_22 ) ;
}
F_245 ( & V_22 -> V_251 ) ;
if ( V_326 != V_22 -> V_27 . V_91 )
F_239 ( V_22 ) ;
return 0 ;
}
static int F_246 ( struct V_21 * V_22 )
{
struct V_35 * V_36 ;
struct V_307 * V_308 ;
V_101 V_145 ;
V_36 = F_247 ( V_13 ?
( 1 << V_6 ) :
V_327 ) ;
if ( ! V_36 )
return - V_57 ;
snprintf ( V_36 -> V_328 , sizeof( V_36 -> V_328 ) , V_329 L_55 ,
V_22 -> V_5 ) ;
V_36 -> V_330 = V_22 -> V_330 ;
V_36 -> V_331 = V_22 -> V_7 ;
if ( V_13 )
V_36 -> V_32 |= V_332 ;
V_36 -> V_333 = & V_334 ;
V_36 -> V_24 = V_22 ;
V_308 = F_248 ( F_226 , & V_22 -> V_30 ) ;
if ( ! V_308 )
goto V_335;
F_249 ( V_308 , V_325 ) ;
V_145 = F_83 ( & V_22 -> V_104 ) ;
F_250 ( V_308 , V_145 / V_325 ) ;
F_251 ( V_308 , V_145 ) ;
F_252 ( V_308 , V_145 ) ;
F_253 ( V_308 , V_145 ) ;
F_254 ( V_308 , F_230 ) ;
V_36 -> V_322 = V_308 ;
V_308 -> V_309 = V_22 ;
V_22 -> V_36 = V_36 ;
return 0 ;
V_335:
F_235 ( V_36 ) ;
return - V_57 ;
}
static struct V_21 * F_255 ( struct V_17 * V_18 )
{
return F_52 ( V_18 , struct V_21 , V_18 ) ;
}
static T_11 F_256 ( struct V_17 * V_18 ,
struct V_336 * V_11 , char * V_157 )
{
struct V_21 * V_22 = F_255 ( V_18 ) ;
return sprintf ( V_157 , L_56 ,
( unsigned long long ) V_22 -> V_27 . V_91 ) ;
}
static T_11 F_257 ( struct V_17 * V_18 ,
struct V_336 * V_11 , char * V_157 )
{
struct V_21 * V_22 = F_255 ( V_18 ) ;
return sprintf ( V_157 , L_57 ,
( unsigned long long ) V_22 -> V_27 . V_125 ) ;
}
static T_11 F_258 ( struct V_17 * V_18 ,
struct V_336 * V_11 , char * V_157 )
{
struct V_21 * V_22 = F_255 ( V_18 ) ;
if ( V_22 -> V_330 )
return sprintf ( V_157 , L_58 , V_22 -> V_330 ) ;
return sprintf ( V_157 , L_59 ) ;
}
static T_11 F_259 ( struct V_17 * V_18 ,
struct V_336 * V_11 , char * V_157 )
{
struct V_21 * V_22 = F_255 ( V_18 ) ;
return sprintf ( V_157 , L_58 , V_22 -> V_7 ) ;
}
static T_11 F_260 ( struct V_17 * V_18 ,
struct V_336 * V_11 , char * V_157 )
{
struct V_21 * V_22 = F_255 ( V_18 ) ;
return sprintf ( V_157 , L_60 ,
F_261 ( V_22 -> V_53 -> V_63 ) ) ;
}
static T_11 F_262 ( struct V_17 * V_18 ,
struct V_336 * V_11 , char * V_157 )
{
struct V_21 * V_22 = F_255 ( V_18 ) ;
return sprintf ( V_157 , L_61 , V_22 -> V_45 -> V_337 ) ;
}
static T_11 F_263 ( struct V_17 * V_18 ,
struct V_336 * V_11 , char * V_157 )
{
struct V_21 * V_22 = F_255 ( V_18 ) ;
return sprintf ( V_157 , L_56 ,
( unsigned long long ) V_22 -> V_45 -> V_338 ) ;
}
static T_11 F_264 ( struct V_17 * V_18 ,
struct V_336 * V_11 , char * V_157 )
{
struct V_21 * V_22 = F_255 ( V_18 ) ;
if ( V_22 -> V_45 -> V_339 )
return sprintf ( V_157 , L_61 , V_22 -> V_45 -> V_339 ) ;
return sprintf ( V_157 , L_62 ) ;
}
static T_11 F_265 ( struct V_17 * V_18 ,
struct V_336 * V_11 , char * V_157 )
{
struct V_21 * V_22 = F_255 ( V_18 ) ;
return sprintf ( V_157 , L_61 , V_22 -> V_45 -> V_340 ) ;
}
static T_11 F_266 ( struct V_17 * V_18 ,
struct V_336 * V_11 ,
char * V_157 )
{
struct V_21 * V_22 = F_255 ( V_18 ) ;
return sprintf ( V_157 , L_61 , V_22 -> V_45 -> V_128 ) ;
}
static T_11 F_267 ( struct V_17 * V_18 ,
struct V_336 * V_11 ,
char * V_157 )
{
struct V_21 * V_22 = F_255 ( V_18 ) ;
T_11 V_341 = 0 ;
if ( ! V_22 -> V_257 )
return sprintf ( V_157 , L_63 ) ;
for ( ; V_22 -> V_257 ; V_22 = V_22 -> V_257 ) {
struct V_342 * V_45 = V_22 -> V_248 ;
V_341 += sprintf ( & V_157 [ V_341 ] , L_64
L_65
L_66
L_67
L_68 ,
! V_341 ? L_69 : L_70 ,
V_45 -> V_338 , V_45 -> V_337 ,
V_45 -> V_340 , V_45 -> V_339 ? : L_71 ,
V_45 -> V_46 , V_45 -> V_128 ,
V_22 -> V_185 ) ;
}
return V_341 ;
}
static T_11 F_268 ( struct V_17 * V_18 ,
struct V_336 * V_11 ,
const char * V_157 ,
T_6 V_91 )
{
struct V_21 * V_22 = F_255 ( V_18 ) ;
int V_39 ;
V_39 = F_203 ( V_22 ) ;
if ( V_39 )
return V_39 ;
return V_91 ;
}
static void F_269 ( struct V_17 * V_18 )
{
}
static struct V_342 * F_270 ( struct V_342 * V_45 )
{
F_40 ( & V_45 -> V_61 ) ;
return V_45 ;
}
static void F_165 ( struct V_342 * V_45 )
{
if ( V_45 )
F_55 ( & V_45 -> V_61 , V_343 ) ;
}
static struct V_342 * F_271 ( void )
{
struct V_342 * V_45 ;
V_45 = F_272 ( sizeof ( * V_45 ) , V_59 ) ;
if ( ! V_45 )
return NULL ;
V_45 -> V_338 = V_344 ;
V_45 -> V_46 = V_47 ;
F_27 ( & V_45 -> V_61 ) ;
return V_45 ;
}
static void V_343 ( struct V_61 * V_61 )
{
struct V_342 * V_45 = F_52 ( V_61 , struct V_342 , V_61 ) ;
F_36 ( V_45 -> V_337 ) ;
F_36 ( V_45 -> V_340 ) ;
F_36 ( V_45 -> V_339 ) ;
F_36 ( V_45 -> V_128 ) ;
F_36 ( V_45 ) ;
}
static struct V_21 * F_273 ( struct V_53 * V_56 ,
struct V_342 * V_45 )
{
struct V_21 * V_22 ;
V_22 = F_272 ( sizeof ( * V_22 ) , V_59 ) ;
if ( ! V_22 )
return NULL ;
F_172 ( & V_22 -> V_30 ) ;
F_28 ( & V_22 -> V_305 ) ;
F_274 ( & V_22 -> V_302 , F_221 ) ;
V_22 -> V_32 = 0 ;
F_275 ( & V_22 -> V_249 , 0 ) ;
F_28 ( & V_22 -> V_62 ) ;
F_276 ( & V_22 -> V_251 ) ;
V_22 -> V_45 = V_45 ;
V_22 -> V_53 = V_56 ;
V_22 -> V_244 . V_345 = F_277 ( 1 << V_346 ) ;
V_22 -> V_244 . V_347 = F_277 ( 1 ) ;
V_22 -> V_244 . V_348 = F_277 ( 1 << V_346 ) ;
V_22 -> V_244 . V_349 = F_277 ( ( T_5 ) V_45 -> V_338 ) ;
return V_22 ;
}
static void F_278 ( struct V_21 * V_22 )
{
F_54 ( V_22 -> V_53 ) ;
F_165 ( V_22 -> V_45 ) ;
F_36 ( V_22 ) ;
}
static int F_72 ( struct V_21 * V_22 , V_101 V_46 ,
T_9 * V_96 , V_101 * V_136 )
{
V_100 V_350 = F_279 ( V_46 ) ;
int V_39 ;
struct {
T_9 V_96 ;
V_100 V_91 ;
} V_351 ( ( V_352 ) ) V_353 = { 0 } ;
V_39 = F_210 ( V_22 , V_22 -> V_277 ,
L_39 , L_72 ,
& V_350 , sizeof ( V_350 ) ,
& V_353 , sizeof ( V_353 ) ) ;
F_25 ( L_73 , V_58 , V_39 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 < sizeof ( V_353 ) )
return - V_354 ;
if ( V_96 ) {
* V_96 = V_353 . V_96 ;
F_25 ( L_74 , ( unsigned int ) * V_96 ) ;
}
* V_136 = F_59 ( V_353 . V_91 ) ;
F_25 ( L_75 ,
( unsigned long long ) V_46 ,
( unsigned long long ) * V_136 ) ;
return 0 ;
}
static int F_280 ( struct V_21 * V_22 )
{
return F_72 ( V_22 , V_47 ,
& V_22 -> V_104 . V_120 ,
& V_22 -> V_104 . V_119 ) ;
}
static int F_281 ( struct V_21 * V_22 )
{
void * V_355 ;
int V_39 ;
void * V_356 ;
V_355 = F_272 ( V_357 , V_59 ) ;
if ( ! V_355 )
return - V_57 ;
V_39 = F_210 ( V_22 , V_22 -> V_277 ,
L_39 , L_76 , NULL , 0 ,
V_355 , V_357 ) ;
F_25 ( L_73 , V_58 , V_39 ) ;
if ( V_39 < 0 )
goto V_49;
V_356 = V_355 ;
V_22 -> V_104 . V_106 = F_282 ( & V_356 ,
V_356 + V_39 , NULL , V_143 ) ;
V_39 = 0 ;
if ( F_30 ( V_22 -> V_104 . V_106 ) ) {
V_39 = F_191 ( V_22 -> V_104 . V_106 ) ;
V_22 -> V_104 . V_106 = NULL ;
} else {
F_25 ( L_77 , V_22 -> V_104 . V_106 ) ;
}
V_49:
F_36 ( V_355 ) ;
return V_39 ;
}
static int F_74 ( struct V_21 * V_22 , V_101 V_46 ,
V_101 * V_137 )
{
V_100 V_350 = F_279 ( V_46 ) ;
struct {
V_100 V_125 ;
V_100 V_358 ;
} V_351 ( ( V_352 ) ) V_359 = { 0 } ;
V_101 V_358 ;
int V_39 ;
V_39 = F_210 ( V_22 , V_22 -> V_277 ,
L_39 , L_78 ,
& V_350 , sizeof ( V_350 ) ,
& V_359 , sizeof ( V_359 ) ) ;
F_25 ( L_73 , V_58 , V_39 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 < sizeof ( V_359 ) )
return - V_354 ;
V_358 = F_59 ( V_359 . V_358 ) ;
if ( V_358 & ~ V_360 )
return - V_298 ;
* V_137 = F_59 ( V_359 . V_125 ) ;
F_25 ( L_79 ,
( unsigned long long ) V_46 ,
( unsigned long long ) * V_137 ,
( unsigned long long ) F_59 ( V_359 . V_358 ) ) ;
return 0 ;
}
static int F_283 ( struct V_21 * V_22 )
{
return F_74 ( V_22 , V_47 ,
& V_22 -> V_104 . V_125 ) ;
}
static int F_244 ( struct V_21 * V_22 )
{
struct V_342 * V_248 ;
T_6 V_91 ;
void * V_355 = NULL ;
V_100 V_350 ;
void * V_356 ;
void * V_164 ;
V_101 V_338 ;
char * V_340 ;
V_101 V_46 ;
V_101 V_361 ;
int V_39 ;
V_248 = F_271 () ;
if ( ! V_248 )
return - V_57 ;
V_91 = sizeof ( V_100 ) +
sizeof ( V_271 ) + V_362 +
sizeof ( V_100 ) +
sizeof ( V_100 ) ;
V_355 = F_26 ( V_91 , V_59 ) ;
if ( ! V_355 ) {
V_39 = - V_57 ;
goto V_112;
}
V_350 = F_279 ( V_22 -> V_45 -> V_46 ) ;
V_39 = F_210 ( V_22 , V_22 -> V_277 ,
L_39 , L_80 ,
& V_350 , sizeof ( V_350 ) ,
V_355 , V_91 ) ;
F_25 ( L_73 , V_58 , V_39 ) ;
if ( V_39 < 0 )
goto V_112;
V_356 = V_355 ;
V_164 = V_355 + V_39 ;
V_39 = - V_354 ;
F_284 ( & V_356 , V_164 , V_338 , V_112 ) ;
if ( V_338 == V_344 ) {
if ( V_22 -> V_185 ) {
V_22 -> V_185 = 0 ;
F_106 () ;
F_166 ( V_22 ) ;
F_285 ( L_81 ,
V_22 -> V_36 -> V_328 ) ;
}
goto V_49;
}
V_39 = - V_126 ;
if ( V_338 > ( V_101 ) V_363 ) {
F_102 ( NULL , L_82 ,
( unsigned long long ) V_338 , V_363 ) ;
goto V_112;
}
V_340 = F_282 ( & V_356 , V_164 , NULL , V_59 ) ;
if ( F_30 ( V_340 ) ) {
V_39 = F_191 ( V_340 ) ;
goto V_112;
}
F_284 ( & V_356 , V_164 , V_46 , V_112 ) ;
F_284 ( & V_356 , V_164 , V_361 , V_112 ) ;
if ( ! V_22 -> V_248 ) {
V_248 -> V_338 = V_338 ;
V_248 -> V_340 = V_340 ;
V_248 -> V_46 = V_46 ;
V_22 -> V_248 = V_248 ;
V_248 = NULL ;
} else {
F_36 ( V_340 ) ;
}
V_22 -> V_185 = V_361 ;
F_106 () ;
if ( ! V_361 ) {
if ( V_248 ) {
F_166 ( V_22 ) ;
F_285 ( L_83 ,
V_22 -> V_36 -> V_328 ) ;
} else {
F_102 ( V_22 , L_84 ) ;
}
}
V_49:
V_39 = 0 ;
V_112:
F_36 ( V_355 ) ;
F_165 ( V_248 ) ;
return V_39 ;
}
static int F_286 ( struct V_21 * V_22 )
{
struct {
V_100 V_123 ;
V_100 V_124 ;
} V_351 ( ( V_352 ) ) V_364 = { 0 } ;
T_6 V_91 = sizeof ( V_364 ) ;
void * V_356 ;
V_101 V_365 ;
V_101 V_123 ;
V_101 V_124 ;
int V_39 ;
V_39 = F_210 ( V_22 , V_22 -> V_277 ,
L_39 , L_85 , NULL , 0 ,
( char * ) & V_364 , V_91 ) ;
F_25 ( L_73 , V_58 , V_39 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 < V_91 )
return - V_354 ;
V_39 = - V_4 ;
V_365 = ( V_101 ) 1 << V_22 -> V_104 . V_120 ;
V_356 = & V_364 ;
V_123 = F_287 ( & V_356 ) ;
if ( V_123 != V_365 ) {
F_102 ( V_22 , L_86
L_87 ,
V_123 , V_365 ) ;
return - V_4 ;
}
V_124 = F_287 ( & V_356 ) ;
if ( V_124 != 1 ) {
F_102 ( V_22 , L_88
L_89 , V_124 ) ;
return - V_4 ;
}
V_22 -> V_104 . V_123 = V_123 ;
V_22 -> V_104 . V_124 = V_124 ;
return 0 ;
}
static char * F_288 ( struct V_21 * V_22 )
{
T_6 V_366 ;
char * V_340 ;
void * V_356 ;
void * V_164 ;
T_6 V_91 ;
void * V_355 = NULL ;
T_6 V_111 = 0 ;
char * V_339 = NULL ;
int V_39 ;
F_17 ( ! V_22 -> V_45 -> V_339 ) ;
V_111 = strlen ( V_22 -> V_45 -> V_340 ) ;
V_366 = sizeof ( V_271 ) + V_111 ;
V_340 = F_26 ( V_366 , V_59 ) ;
if ( ! V_340 )
return NULL ;
V_356 = V_340 ;
V_164 = V_340 + V_366 ;
F_289 ( & V_356 , V_164 , V_22 -> V_45 -> V_340 , ( T_5 ) V_111 ) ;
V_91 = sizeof ( V_271 ) + V_367 ;
V_355 = F_26 ( V_91 , V_59 ) ;
if ( ! V_355 )
goto V_49;
V_39 = F_210 ( V_22 , V_368 ,
L_39 , L_90 ,
V_340 , V_366 ,
V_355 , V_91 ) ;
if ( V_39 < 0 )
goto V_49;
V_356 = V_355 ;
V_164 = V_355 + V_39 ;
V_339 = F_282 ( & V_356 , V_164 , & V_111 , V_59 ) ;
if ( F_30 ( V_339 ) )
V_339 = NULL ;
else
F_25 ( L_91 , V_58 , V_339 , V_111 ) ;
V_49:
F_36 ( V_355 ) ;
F_36 ( V_340 ) ;
return V_339 ;
}
static V_101 F_290 ( struct V_21 * V_22 , const char * V_138 )
{
struct V_99 * V_107 = V_22 -> V_104 . V_107 ;
const char * V_128 ;
T_5 V_127 = 0 ;
V_128 = V_22 -> V_104 . V_108 ;
while ( V_127 < V_107 -> V_129 ) {
if ( ! strcmp ( V_138 , V_128 ) )
return V_107 -> V_116 [ V_127 ] ;
V_128 += strlen ( V_128 ) + 1 ;
V_127 ++ ;
}
return V_47 ;
}
static V_101 F_291 ( struct V_21 * V_22 , const char * V_138 )
{
struct V_99 * V_107 = V_22 -> V_104 . V_107 ;
T_5 V_127 ;
bool V_69 = false ;
V_101 V_46 ;
for ( V_127 = 0 ; ! V_69 && V_127 < V_107 -> V_129 ; V_127 ++ ) {
const char * V_128 ;
V_46 = V_107 -> V_116 [ V_127 ] ;
V_128 = F_70 ( V_22 , V_46 ) ;
if ( F_30 ( V_128 ) ) {
if ( F_191 ( V_128 ) == - V_34 )
continue;
else
break;
}
V_69 = ! strcmp ( V_138 , V_128 ) ;
F_36 ( V_128 ) ;
}
return V_69 ? V_46 : V_47 ;
}
static V_101 F_292 ( struct V_21 * V_22 , const char * V_138 )
{
if ( V_22 -> V_88 == 1 )
return F_290 ( V_22 , V_138 ) ;
return F_291 ( V_22 , V_138 ) ;
}
static int F_293 ( struct V_21 * V_22 )
{
struct V_342 * V_45 = V_22 -> V_45 ;
F_17 ( V_45 -> V_338 != V_344 && V_45 -> V_337 ) ;
F_17 ( V_45 -> V_340 && V_45 -> V_339 ) ;
F_17 ( V_45 -> V_128 ) ;
if ( strcmp ( V_45 -> V_128 , V_135 ) ) {
V_101 V_46 ;
V_46 = F_292 ( V_22 , V_45 -> V_128 ) ;
if ( V_46 == V_47 )
return - V_34 ;
V_45 -> V_46 = V_46 ;
} else {
V_45 -> V_46 = V_47 ;
}
return 0 ;
}
static int F_294 ( struct V_21 * V_22 )
{
struct V_200 * V_201 = & V_22 -> V_53 -> V_63 -> V_201 ;
struct V_342 * V_45 = V_22 -> V_45 ;
const char * V_337 ;
const char * V_339 ;
const char * V_128 ;
int V_39 ;
F_17 ( V_45 -> V_338 != V_344 ) ;
F_17 ( V_45 -> V_340 ) ;
F_17 ( V_45 -> V_46 != V_47 ) ;
V_337 = F_295 ( V_201 -> V_369 , V_45 -> V_338 ) ;
if ( ! V_337 ) {
F_102 ( V_22 , L_92 , V_45 -> V_338 ) ;
return - V_126 ;
}
V_337 = F_65 ( V_337 , V_59 ) ;
if ( ! V_337 )
return - V_57 ;
V_339 = F_288 ( V_22 ) ;
if ( ! V_339 )
F_102 ( V_22 , L_93 ) ;
V_128 = F_69 ( V_22 , V_45 -> V_46 ) ;
if ( F_30 ( V_128 ) ) {
V_39 = F_191 ( V_128 ) ;
goto V_112;
}
V_45 -> V_337 = V_337 ;
V_45 -> V_339 = V_339 ;
V_45 -> V_128 = V_128 ;
return 0 ;
V_112:
F_36 ( V_339 ) ;
F_36 ( V_337 ) ;
return V_39 ;
}
static int F_296 ( struct V_21 * V_22 )
{
T_6 V_91 ;
int V_39 ;
void * V_355 ;
void * V_356 ;
void * V_164 ;
V_101 V_113 ;
T_5 V_92 ;
struct V_99 * V_107 ;
T_5 V_110 ;
V_91 = sizeof ( V_100 ) + sizeof ( V_271 ) +
V_370 * sizeof ( V_100 ) ;
V_355 = F_272 ( V_91 , V_59 ) ;
if ( ! V_355 )
return - V_57 ;
V_39 = F_210 ( V_22 , V_22 -> V_277 ,
L_39 , L_94 , NULL , 0 ,
V_355 , V_91 ) ;
F_25 ( L_73 , V_58 , V_39 ) ;
if ( V_39 < 0 )
goto V_49;
V_356 = V_355 ;
V_164 = V_355 + V_39 ;
V_39 = - V_354 ;
F_284 ( & V_356 , V_164 , V_113 , V_49 ) ;
F_297 ( & V_356 , V_164 , V_92 , V_49 ) ;
if ( V_92 > ( V_98 - sizeof ( struct V_99 ) )
/ sizeof ( V_101 ) ) {
V_39 = - V_4 ;
goto V_49;
}
if ( ! F_298 ( & V_356 , V_164 , V_92 * sizeof ( V_100 ) ) )
goto V_49;
V_39 = 0 ;
V_107 = F_62 ( V_92 , V_59 ) ;
if ( ! V_107 ) {
V_39 = - V_57 ;
goto V_49;
}
V_107 -> V_113 = V_113 ;
for ( V_110 = 0 ; V_110 < V_92 ; V_110 ++ )
V_107 -> V_116 [ V_110 ] = F_287 ( & V_356 ) ;
F_63 ( V_22 -> V_104 . V_107 ) ;
V_22 -> V_104 . V_107 = V_107 ;
F_25 ( L_95 ,
( unsigned long long ) V_113 , ( unsigned int ) V_92 ) ;
V_49:
F_36 ( V_355 ) ;
return V_39 ;
}
static const char * F_70 ( struct V_21 * V_22 ,
V_101 V_46 )
{
T_6 V_91 ;
void * V_355 ;
V_100 V_350 ;
int V_39 ;
void * V_356 ;
void * V_164 ;
char * V_128 ;
V_91 = sizeof ( V_271 ) + V_371 ;
V_355 = F_26 ( V_91 , V_59 ) ;
if ( ! V_355 )
return F_38 ( - V_57 ) ;
V_350 = F_279 ( V_46 ) ;
V_39 = F_210 ( V_22 , V_22 -> V_277 ,
L_39 , L_96 ,
& V_350 , sizeof ( V_350 ) ,
V_355 , V_91 ) ;
F_25 ( L_73 , V_58 , V_39 ) ;
if ( V_39 < 0 ) {
V_128 = F_38 ( V_39 ) ;
goto V_49;
}
V_356 = V_355 ;
V_164 = V_355 + V_39 ;
V_128 = F_282 ( & V_356 , V_164 , NULL , V_59 ) ;
if ( F_30 ( V_128 ) )
goto V_49;
F_25 ( L_97 ,
( unsigned long long ) V_46 , V_128 ) ;
V_49:
F_36 ( V_355 ) ;
return V_128 ;
}
static int F_299 ( struct V_21 * V_22 )
{
bool V_105 = V_22 -> V_104 . V_106 == NULL ;
int V_39 ;
V_39 = F_280 ( V_22 ) ;
if ( V_39 )
return V_39 ;
if ( V_105 ) {
V_39 = F_300 ( V_22 ) ;
if ( V_39 )
return V_39 ;
}
V_39 = F_296 ( V_22 ) ;
F_25 ( L_98 , V_39 ) ;
return V_39 ;
}
static int F_243 ( struct V_21 * V_22 )
{
F_17 ( F_56 ( V_22 -> V_88 ) ) ;
if ( V_22 -> V_88 == 1 )
return F_237 ( V_22 ) ;
return F_299 ( V_22 ) ;
}
static int F_301 ( struct V_21 * V_22 )
{
struct V_17 * V_18 ;
int V_39 ;
V_18 = & V_22 -> V_18 ;
V_18 -> V_372 = & V_373 ;
V_18 -> type = & V_374 ;
V_18 -> V_257 = & V_375 ;
V_18 -> V_376 = V_377 ;
F_302 ( V_18 , L_55 , V_22 -> V_5 ) ;
V_39 = F_303 ( V_18 ) ;
return V_39 ;
}
static void F_304 ( struct V_21 * V_22 )
{
F_305 ( & V_22 -> V_18 ) ;
}
static int F_306 ( struct V_21 * V_22 )
{
int V_378 ;
V_378 = F_307 ( & V_379 ,
0 , F_8 ( 1 << V_380 ) ,
V_59 ) ;
if ( V_378 < 0 )
return V_378 ;
V_22 -> V_5 = V_378 ;
F_32 ( & V_381 ) ;
F_33 ( & V_22 -> V_62 , & V_382 ) ;
F_34 ( & V_381 ) ;
F_25 ( L_99 , V_22 , V_22 -> V_5 ) ;
return 0 ;
}
static void F_308 ( struct V_21 * V_22 )
{
F_32 ( & V_381 ) ;
F_225 ( & V_22 -> V_62 ) ;
F_34 ( & V_381 ) ;
F_309 ( & V_379 , V_22 -> V_5 ) ;
F_25 ( L_100 , V_22 , V_22 -> V_5 ) ;
}
static inline T_6 F_310 ( const char * * V_157 )
{
const char * V_383 = L_101 ;
* V_157 += strspn ( * V_157 , V_383 ) ;
return strcspn ( * V_157 , V_383 ) ;
}
static inline T_6 F_311 ( const char * * V_157 ,
char * V_77 ,
T_6 V_384 )
{
T_6 V_111 ;
V_111 = F_310 ( V_157 ) ;
if ( V_111 < V_384 ) {
memcpy ( V_77 , * V_157 , V_111 ) ;
* ( V_77 + V_111 ) = '\0' ;
}
* V_157 += V_111 ;
return V_111 ;
}
static inline char * F_312 ( const char * * V_157 , T_6 * V_385 )
{
char * V_386 ;
T_6 V_111 ;
V_111 = F_310 ( V_157 ) ;
V_386 = F_313 ( * V_157 , V_111 + 1 , V_59 ) ;
if ( ! V_386 )
return NULL ;
* ( V_386 + V_111 ) = '\0' ;
* V_157 += V_111 ;
if ( V_385 )
* V_385 = V_111 ;
return V_386 ;
}
static int F_314 ( const char * V_157 ,
struct V_54 * * V_55 ,
struct V_73 * * V_387 ,
struct V_342 * * V_342 )
{
T_6 V_111 ;
char * V_95 ;
const char * V_388 ;
char * V_128 ;
T_6 V_389 ;
struct V_342 * V_45 = NULL ;
struct V_73 * V_74 = NULL ;
struct V_54 * V_390 ;
int V_39 ;
V_111 = F_310 ( & V_157 ) ;
if ( ! V_111 ) {
F_102 ( NULL , L_102 ) ;
return - V_4 ;
}
V_388 = V_157 ;
V_389 = V_111 + 1 ;
V_157 += V_111 ;
V_39 = - V_4 ;
V_95 = F_312 ( & V_157 , NULL ) ;
if ( ! V_95 )
return - V_57 ;
if ( ! * V_95 ) {
F_102 ( NULL , L_103 ) ;
goto V_112;
}
V_45 = F_271 () ;
if ( ! V_45 )
goto V_391;
V_45 -> V_337 = F_312 ( & V_157 , NULL ) ;
if ( ! V_45 -> V_337 )
goto V_391;
if ( ! * V_45 -> V_337 ) {
F_102 ( NULL , L_104 ) ;
goto V_112;
}
V_45 -> V_339 = F_312 ( & V_157 , NULL ) ;
if ( ! V_45 -> V_339 )
goto V_391;
if ( ! * V_45 -> V_339 ) {
F_102 ( NULL , L_105 ) ;
goto V_112;
}
V_111 = F_310 ( & V_157 ) ;
if ( ! V_111 ) {
V_157 = V_135 ;
V_111 = sizeof ( V_135 ) - 1 ;
} else if ( V_111 > V_371 ) {
V_39 = - V_392 ;
goto V_112;
}
V_128 = F_313 ( V_157 , V_111 + 1 , V_59 ) ;
if ( ! V_128 )
goto V_391;
* ( V_128 + V_111 ) = '\0' ;
V_45 -> V_128 = V_128 ;
V_74 = F_272 ( sizeof ( * V_74 ) , V_59 ) ;
if ( ! V_74 )
goto V_391;
V_74 -> V_28 = V_393 ;
V_390 = F_315 ( V_95 , V_388 ,
V_388 + V_389 - 1 ,
F_44 , V_74 ) ;
if ( F_30 ( V_390 ) ) {
V_39 = F_191 ( V_390 ) ;
goto V_112;
}
F_36 ( V_95 ) ;
* V_55 = V_390 ;
* V_387 = V_74 ;
* V_342 = V_45 ;
return 0 ;
V_391:
V_39 = - V_57 ;
V_112:
F_36 ( V_74 ) ;
F_165 ( V_45 ) ;
F_36 ( V_95 ) ;
return V_39 ;
}
static int F_316 ( struct V_53 * V_56 , const char * V_337 )
{
V_101 V_394 ;
unsigned long V_395 = V_56 -> V_63 -> V_95 -> V_396 * V_397 ;
int V_398 = 0 ;
int V_39 ;
V_399:
V_39 = F_317 ( V_56 -> V_63 -> V_201 . V_369 , V_337 ) ;
if ( V_39 == - V_34 && V_398 ++ < 1 ) {
V_39 = F_318 ( & V_56 -> V_63 -> V_400 , L_106 ,
& V_394 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_56 -> V_63 -> V_201 . V_369 -> V_401 < V_394 ) {
F_319 ( & V_56 -> V_63 -> V_400 ) ;
( void ) F_320 ( & V_56 -> V_63 -> V_400 ,
V_394 , V_395 ) ;
goto V_399;
} else {
return - V_34 ;
}
}
return V_39 ;
}
static int F_321 ( struct V_21 * V_22 )
{
int V_39 ;
T_6 V_91 ;
char * V_230 ;
void * V_402 ;
char * V_340 ;
if ( V_22 -> V_45 -> V_340 ) {
V_22 -> V_88 = * V_22 -> V_45 -> V_340 ? 2 : 1 ;
return 0 ;
}
V_91 = sizeof ( V_403 ) + strlen ( V_22 -> V_45 -> V_339 ) ;
V_230 = F_26 ( V_91 , V_143 ) ;
if ( ! V_230 )
return - V_57 ;
sprintf ( V_230 , L_107 , V_403 , V_22 -> V_45 -> V_339 ) ;
F_25 ( L_108 , V_230 ) ;
V_91 = sizeof ( V_271 ) + V_362 ;
V_402 = F_272 ( V_91 , V_143 ) ;
if ( ! V_402 ) {
V_39 = - V_57 ;
goto V_49;
}
V_39 = F_210 ( V_22 , V_230 ,
L_39 , L_109 , NULL , 0 ,
V_402 , V_362 ) ;
F_25 ( L_73 , V_58 , V_39 ) ;
if ( V_39 == - V_34 ) {
V_340 = F_65 ( L_69 , V_59 ) ;
V_39 = V_340 ? 0 : - V_57 ;
if ( ! V_39 )
V_22 -> V_88 = 1 ;
} else if ( V_39 > sizeof ( V_271 ) ) {
void * V_356 = V_402 ;
V_340 = F_282 ( & V_356 , V_356 + V_39 ,
NULL , V_143 ) ;
V_39 = F_322 ( V_340 ) ;
if ( ! V_39 )
V_22 -> V_88 = 2 ;
} else {
V_39 = - V_4 ;
}
if ( ! V_39 ) {
V_22 -> V_45 -> V_340 = V_340 ;
F_25 ( L_110 , V_340 ) ;
}
V_49:
F_36 ( V_402 ) ;
F_36 ( V_230 ) ;
return V_39 ;
}
static void F_323 ( struct V_21 * V_22 )
{
struct V_103 * V_104 ;
if ( V_22 -> V_185 )
F_166 ( V_22 ) ;
V_104 = & V_22 -> V_104 ;
F_63 ( V_104 -> V_107 ) ;
F_36 ( V_104 -> V_109 ) ;
F_36 ( V_104 -> V_108 ) ;
F_36 ( V_104 -> V_106 ) ;
memset ( V_104 , 0 , sizeof ( * V_104 ) ) ;
}
static int F_300 ( struct V_21 * V_22 )
{
int V_39 ;
V_39 = F_281 ( V_22 ) ;
if ( V_39 )
goto V_112;
V_39 = F_283 ( V_22 ) ;
if ( V_39 )
goto V_112;
if ( V_22 -> V_104 . V_125 & V_404 ) {
V_39 = F_286 ( V_22 ) ;
if ( V_39 < 0 )
goto V_112;
}
return 0 ;
V_112:
V_22 -> V_104 . V_125 = 0 ;
F_36 ( V_22 -> V_104 . V_106 ) ;
V_22 -> V_104 . V_106 = NULL ;
return V_39 ;
}
static int F_324 ( struct V_21 * V_22 )
{
struct V_21 * V_257 = NULL ;
struct V_342 * V_248 ;
struct V_53 * V_56 ;
int V_39 ;
if ( ! V_22 -> V_248 )
return 0 ;
V_248 = F_270 ( V_22 -> V_248 ) ;
V_56 = F_39 ( V_22 -> V_53 ) ;
V_39 = - V_57 ;
V_257 = F_273 ( V_56 , V_248 ) ;
if ( ! V_257 )
goto V_112;
V_39 = F_325 ( V_257 , false ) ;
if ( V_39 < 0 )
goto V_112;
V_22 -> V_257 = V_257 ;
F_275 ( & V_22 -> V_249 , 1 ) ;
return 0 ;
V_112:
if ( V_257 ) {
F_163 ( V_22 ) ;
F_36 ( V_22 -> V_277 ) ;
F_278 ( V_257 ) ;
} else {
F_54 ( V_56 ) ;
F_165 ( V_248 ) ;
}
return V_39 ;
}
static int F_326 ( struct V_21 * V_22 )
{
int V_39 ;
V_39 = F_306 ( V_22 ) ;
if ( V_39 )
return V_39 ;
F_327 ( V_405
< sizeof ( V_329 ) + V_406 ) ;
sprintf ( V_22 -> V_138 , L_111 , V_329 , V_22 -> V_5 ) ;
if ( ! V_13 ) {
V_39 = F_328 ( 0 , V_22 -> V_138 ) ;
if ( V_39 < 0 )
goto V_407;
V_22 -> V_330 = V_39 ;
V_22 -> V_7 = 0 ;
} else {
V_22 -> V_330 = V_408 ;
V_22 -> V_7 = F_7 ( V_22 -> V_5 ) ;
}
V_39 = F_246 ( V_22 ) ;
if ( V_39 )
goto V_409;
V_39 = F_75 ( V_22 ) ;
if ( V_39 )
goto V_410;
F_240 ( V_22 -> V_36 , V_22 -> V_27 . V_91 / V_325 ) ;
F_21 ( V_22 -> V_36 , V_22 -> V_27 . V_28 ) ;
V_22 -> V_313 = F_329 ( L_64 , 0 , 0 , V_22 -> V_36 -> V_328 ) ;
if ( ! V_22 -> V_313 ) {
V_39 = - V_57 ;
goto V_411;
}
V_39 = F_301 ( V_22 ) ;
if ( V_39 )
goto V_412;
F_110 ( V_297 , & V_22 -> V_32 ) ;
F_330 ( V_22 -> V_36 ) ;
F_285 ( L_112 , V_22 -> V_36 -> V_328 ,
( unsigned long long ) V_22 -> V_27 . V_91 ) ;
return V_39 ;
V_412:
F_331 ( V_22 -> V_313 ) ;
V_22 -> V_313 = NULL ;
V_411:
F_76 ( V_22 ) ;
V_410:
F_232 ( V_22 ) ;
V_409:
if ( ! V_13 )
F_332 ( V_22 -> V_330 , V_22 -> V_138 ) ;
V_407:
F_308 ( V_22 ) ;
F_76 ( V_22 ) ;
return V_39 ;
}
static int F_333 ( struct V_21 * V_22 )
{
struct V_342 * V_45 = V_22 -> V_45 ;
T_6 V_91 ;
F_17 ( F_56 ( V_22 -> V_88 ) ) ;
if ( V_22 -> V_88 == 1 )
V_91 = strlen ( V_45 -> V_339 ) + sizeof ( V_413 ) ;
else
V_91 = sizeof ( V_414 ) + strlen ( V_45 -> V_340 ) ;
V_22 -> V_277 = F_26 ( V_91 , V_59 ) ;
if ( ! V_22 -> V_277 )
return - V_57 ;
if ( V_22 -> V_88 == 1 )
sprintf ( V_22 -> V_277 , L_107 ,
V_45 -> V_339 , V_413 ) ;
else
sprintf ( V_22 -> V_277 , L_107 ,
V_414 , V_45 -> V_340 ) ;
return 0 ;
}
static void F_334 ( struct V_21 * V_22 )
{
F_323 ( V_22 ) ;
F_36 ( V_22 -> V_277 ) ;
V_22 -> V_277 = NULL ;
V_22 -> V_88 = 0 ;
F_36 ( V_22 -> V_45 -> V_340 ) ;
V_22 -> V_45 -> V_340 = NULL ;
F_278 ( V_22 ) ;
}
static int F_325 ( struct V_21 * V_22 , bool V_27 )
{
int V_39 ;
V_39 = F_321 ( V_22 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_333 ( V_22 ) ;
if ( V_39 )
goto V_415;
if ( V_27 ) {
V_39 = F_206 ( V_22 ) ;
if ( V_39 )
goto V_416;
}
V_39 = F_243 ( V_22 ) ;
if ( V_39 )
goto V_417;
if ( V_27 )
V_39 = F_293 ( V_22 ) ;
else
V_39 = F_294 ( V_22 ) ;
if ( V_39 )
goto V_418;
if ( V_22 -> V_104 . V_125 & V_419 ) {
V_39 = F_244 ( V_22 ) ;
if ( V_39 )
goto V_418;
if ( V_27 && V_22 -> V_248 )
F_102 ( V_22 ,
L_113 ) ;
}
V_39 = F_324 ( V_22 ) ;
if ( V_39 )
goto V_418;
F_25 ( L_114 ,
V_22 -> V_88 , V_22 -> V_277 ) ;
return 0 ;
V_418:
F_323 ( V_22 ) ;
V_417:
if ( V_27 )
F_209 ( V_22 ) ;
V_416:
F_36 ( V_22 -> V_277 ) ;
V_22 -> V_277 = NULL ;
V_415:
V_22 -> V_88 = 0 ;
F_36 ( V_22 -> V_45 -> V_340 ) ;
V_22 -> V_45 -> V_340 = NULL ;
return V_39 ;
}
static T_11 F_335 ( struct V_420 * V_372 ,
const char * V_157 ,
T_6 V_341 )
{
struct V_21 * V_22 = NULL ;
struct V_54 * V_55 = NULL ;
struct V_73 * V_74 = NULL ;
struct V_342 * V_45 = NULL ;
struct V_53 * V_56 ;
bool V_28 ;
int V_421 = - V_57 ;
if ( ! F_336 ( V_422 ) )
return - V_423 ;
V_421 = F_314 ( V_157 , & V_55 , & V_74 , & V_45 ) ;
if ( V_421 < 0 )
goto V_424;
V_28 = V_74 -> V_28 ;
F_36 ( V_74 ) ;
V_74 = NULL ;
V_56 = F_48 ( V_55 ) ;
if ( F_30 ( V_56 ) ) {
V_421 = F_191 ( V_56 ) ;
goto V_425;
}
V_421 = F_316 ( V_56 , V_45 -> V_337 ) ;
if ( V_421 < 0 )
goto V_426;
V_45 -> V_338 = ( V_101 ) V_421 ;
if ( V_45 -> V_338 > ( V_101 ) V_363 ) {
F_102 ( NULL , L_115 ,
( unsigned long long ) V_45 -> V_338 , V_363 ) ;
V_421 = - V_126 ;
goto V_426;
}
V_22 = F_273 ( V_56 , V_45 ) ;
if ( ! V_22 )
goto V_426;
V_56 = NULL ;
V_45 = NULL ;
V_421 = F_325 ( V_22 , true ) ;
if ( V_421 < 0 )
goto V_427;
if ( V_22 -> V_45 -> V_46 != V_47 )
V_28 = true ;
V_22 -> V_27 . V_28 = V_28 ;
V_421 = F_326 ( V_22 ) ;
if ( V_421 ) {
F_209 ( V_22 ) ;
F_334 ( V_22 ) ;
goto V_424;
}
return V_341 ;
V_427:
F_278 ( V_22 ) ;
V_426:
F_54 ( V_56 ) ;
V_425:
F_165 ( V_45 ) ;
V_424:
F_337 ( V_422 ) ;
F_25 ( L_116 , V_157 ) ;
return ( T_11 ) V_421 ;
}
static T_11 F_338 ( struct V_420 * V_372 ,
const char * V_157 ,
T_6 V_341 )
{
if ( V_13 )
return - V_4 ;
return F_335 ( V_372 , V_157 , V_341 ) ;
}
static T_11 F_339 ( struct V_420 * V_372 ,
const char * V_157 ,
T_6 V_341 )
{
return F_335 ( V_372 , V_157 , V_341 ) ;
}
static void V_377 ( struct V_17 * V_18 )
{
struct V_21 * V_22 = F_255 ( V_18 ) ;
F_331 ( V_22 -> V_313 ) ;
F_232 ( V_22 ) ;
F_136 ( V_297 , & V_22 -> V_32 ) ;
F_76 ( V_22 ) ;
if ( ! V_13 )
F_332 ( V_22 -> V_330 , V_22 -> V_138 ) ;
F_308 ( V_22 ) ;
F_76 ( V_22 ) ;
}
static void F_164 ( struct V_21 * V_22 )
{
while ( V_22 -> V_257 ) {
struct V_21 * V_428 = V_22 ;
struct V_21 * V_429 = V_428 -> V_257 ;
struct V_21 * V_430 ;
while ( V_429 && ( V_430 = V_429 -> V_257 ) ) {
V_428 = V_429 ;
V_429 = V_430 ;
}
F_17 ( V_429 ) ;
F_334 ( V_429 ) ;
V_428 -> V_257 = NULL ;
V_428 -> V_185 = 0 ;
F_17 ( V_428 -> V_248 ) ;
F_165 ( V_428 -> V_248 ) ;
V_428 -> V_248 = NULL ;
}
}
static T_11 F_340 ( struct V_420 * V_372 ,
const char * V_157 ,
T_6 V_341 )
{
struct V_21 * V_22 = NULL ;
struct V_431 * V_150 ;
int V_5 ;
unsigned long V_432 ;
bool V_433 = false ;
int V_39 ;
V_39 = F_341 ( V_157 , 10 , & V_432 ) ;
if ( V_39 )
return V_39 ;
V_5 = ( int ) V_432 ;
if ( V_5 != V_432 )
return - V_4 ;
V_39 = - V_34 ;
F_32 ( & V_381 ) ;
F_342 (tmp, &rbd_dev_list) {
V_22 = F_343 ( V_150 , struct V_21 , V_62 ) ;
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
V_433 = F_104 ( V_31 ,
& V_22 -> V_32 ) ;
F_14 ( & V_22 -> V_30 ) ;
}
F_34 ( & V_381 ) ;
if ( V_39 < 0 || V_433 )
return V_39 ;
F_209 ( V_22 ) ;
F_25 ( L_117 , V_58 ) ;
F_344 ( & V_22 -> V_53 -> V_63 -> V_201 ) ;
F_304 ( V_22 ) ;
F_334 ( V_22 ) ;
F_337 ( V_422 ) ;
return V_341 ;
}
static T_11 F_345 ( struct V_420 * V_372 ,
const char * V_157 ,
T_6 V_341 )
{
if ( V_13 )
return - V_4 ;
return F_340 ( V_372 , V_157 , V_341 ) ;
}
static T_11 F_346 ( struct V_420 * V_372 ,
const char * V_157 ,
T_6 V_341 )
{
return F_340 ( V_372 , V_157 , V_341 ) ;
}
static int F_347 ( void )
{
int V_39 ;
V_39 = F_303 ( & V_375 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_348 ( & V_373 ) ;
if ( V_39 < 0 )
F_305 ( & V_375 ) ;
return V_39 ;
}
static void F_349 ( void )
{
F_350 ( & V_373 ) ;
F_305 ( & V_375 ) ;
}
static int F_351 ( void )
{
F_17 ( ! V_250 ) ;
V_250 = F_352 ( L_118 ,
sizeof ( struct V_188 ) ,
F_353 ( struct V_188 ) ,
0 , NULL ) ;
if ( ! V_250 )
return - V_57 ;
F_17 ( ! V_246 ) ;
V_246 = F_352 ( L_119 ,
sizeof ( struct V_176 ) ,
F_353 ( struct V_176 ) ,
0 , NULL ) ;
if ( ! V_246 )
goto V_112;
F_17 ( ! V_139 ) ;
V_139 = F_352 ( L_120 ,
V_144 + 1 , 1 , 0 , NULL ) ;
if ( V_139 )
return 0 ;
V_112:
if ( V_246 ) {
F_354 ( V_246 ) ;
V_246 = NULL ;
}
F_354 ( V_250 ) ;
V_250 = NULL ;
return - V_57 ;
}
static void F_355 ( void )
{
F_17 ( V_139 ) ;
F_354 ( V_139 ) ;
V_139 = NULL ;
F_17 ( V_246 ) ;
F_354 ( V_246 ) ;
V_246 = NULL ;
F_17 ( V_250 ) ;
F_354 ( V_250 ) ;
V_250 = NULL ;
}
static int T_12 F_356 ( void )
{
int V_421 ;
if ( ! F_357 ( NULL ) ) {
F_102 ( NULL , L_121 ) ;
return - V_4 ;
}
V_421 = F_351 () ;
if ( V_421 )
return V_421 ;
if ( V_13 ) {
V_408 = F_328 ( 0 , V_329 ) ;
if ( V_408 < 0 ) {
V_421 = V_408 ;
goto V_434;
}
}
V_421 = F_347 () ;
if ( V_421 )
goto V_409;
if ( V_13 )
F_285 ( L_122 , V_408 ) ;
else
F_285 ( L_123 ) ;
return 0 ;
V_409:
if ( V_13 )
F_332 ( V_408 , V_329 ) ;
V_434:
F_355 () ;
return V_421 ;
}
static void T_13 F_358 ( void )
{
F_359 ( & V_379 ) ;
F_349 () ;
if ( V_13 )
F_332 ( V_408 , V_329 ) ;
F_355 () ;
}
