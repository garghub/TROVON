static int F_1 ( T_1 V_1 )
{
int V_2 = 0 ;
for (; V_2 < V_3 ; V_2 ++ ) {
if ( V_1 & V_4 [ V_2 ] . V_5 )
return V_4 [ V_2 ] . V_6 ;
}
return V_7 ;
}
static int F_2 ( struct V_8 * V_8 , void * V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_8 ) ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
strcpy ( V_11 -> V_16 , L_1 ) ;
strcpy ( V_11 -> V_17 , L_2 ) ;
F_5 ( V_15 -> V_18 , V_11 -> V_19 , sizeof( V_11 -> V_19 ) ) ;
V_11 -> V_20 = V_21 | V_22 |
V_23 | V_24 ;
if ( V_13 -> V_25 == V_26 )
V_11 -> V_20 |= V_27 ;
else
V_11 -> V_20 |= V_28 ;
V_11 -> V_29 = V_11 -> V_20 | V_30 |
V_31 | V_27 | V_28 ;
return 0 ;
}
static void F_6 ( struct V_32 * V_33 , bool V_34 )
{
struct V_35 * V_36 = V_33 -> V_36 ;
V_33 -> V_37 = V_34 ;
V_33 -> V_38 = 0 ;
V_33 -> V_39 = 0 ;
V_33 -> V_40 = ( char * ) F_7 ( V_36 -> V_41 )
+ V_34 * V_33 -> V_42 ;
V_33 -> V_43 -> V_44 = 0 ;
}
static bool F_8 ( struct V_35 * V_36 , int * V_45 )
{
struct V_46 * V_47 = V_36 -> V_41 ;
if ( V_47 )
return true ;
F_9 ( & V_36 -> V_48 ) ;
if ( ! F_10 ( & V_36 -> V_49 ) ) {
V_47 = F_11 ( V_36 -> V_49 . V_50 ,
struct V_46 , V_51 ) ;
if ( V_45 )
* V_45 = 1 ;
V_36 -> V_41 = V_47 ;
F_12 ( & V_47 -> V_51 ) ;
}
F_13 ( & V_36 -> V_48 ) ;
return ! ! V_47 ;
}
static bool F_14 ( struct V_35 * V_36 , struct V_32 * V_33 )
{
int V_45 = 0 ;
bool V_52 = true ;
V_52 = F_8 ( V_36 , & V_45 ) ;
if ( V_52 && V_45 )
F_6 ( V_33 , 0 ) ;
return V_52 ;
}
static void F_15 ( struct V_35 * V_36 )
{
struct V_46 * V_47 = V_36 -> V_41 ;
if ( V_47 == NULL )
return;
V_36 -> V_41 = NULL ;
V_47 -> V_53 = V_54 ;
V_47 -> V_37 ++ ;
F_16 ( & V_47 -> V_55 ) ;
F_17 ( & V_47 -> V_56 ) ;
}
static void F_18 ( struct V_32 * V_33 )
{
if ( 1 == V_33 -> V_37 )
F_15 ( V_33 -> V_36 ) ;
else
F_6 ( V_33 , 1 ) ;
}
static void F_19 ( struct V_32 * V_33 , char * V_57 ,
unsigned int V_58 )
{
#define F_20 ( T_2 ) \
do { \
if (++video->lines_copied > video->lines_per_field) \
goto overflow; \
memcpy(video->dst, src, len);\
video->dst += len + video->lines_size; \
src += len; \
count -= len; \
} while (0)
while ( V_58 && V_58 >= V_33 -> V_42 ) {
if ( V_33 -> V_39 ) {
F_20 ( V_33 -> V_39 ) ;
V_33 -> V_39 = 0 ;
continue;
}
F_20 ( V_33 -> V_42 ) ;
}
if ( V_58 && V_58 < V_33 -> V_42 ) {
memcpy ( V_33 -> V_40 , V_57 , V_58 ) ;
V_33 -> V_39 = V_33 -> V_42 - V_58 ;
V_33 -> V_40 += V_58 ;
}
return;
V_59:
F_18 ( V_33 ) ;
}
static void F_21 ( struct V_32 * V_33 , char * V_57 , int V_58 )
{
struct V_60 * V_43 = V_33 -> V_43 ;
int V_61 ;
char * V_62 ;
V_61 = ( V_33 -> V_63 . V_64 . V_65 / 2 + V_43 -> V_66 / 2 )
- ( V_43 -> V_44 + V_33 -> V_42 * V_33 -> V_38 ) ;
if ( V_33 -> V_39 )
V_61 -= ( V_33 -> V_42 - V_33 -> V_39 ) ;
if ( V_61 > V_58 || V_61 <= 0 )
goto V_67;
V_62 = V_57 + V_61 ;
if ( ! strncmp ( V_62 , L_3 , 4 ) ) {
int V_68 = * ( ( V_69 * ) ( V_62 + 12 ) ) ;
if ( ( V_68 & 1 ) ^ V_33 -> V_37 ) {
F_6 ( V_33 , V_33 -> V_37 ) ;
return;
}
F_19 ( V_33 , V_57 , V_61 ) ;
}
V_67:
F_18 ( V_33 ) ;
}
static inline void F_22 ( struct V_60 * V_43 ,
char * V_57 , unsigned int V_58 )
{
struct V_35 * V_36 = V_43 -> V_36 ;
if ( V_36 && F_8 ( V_36 , NULL ) ) {
char * V_62 = F_7 ( V_36 -> V_41 ) ;
if ( V_43 -> V_33 -> V_37 )
V_62 += ( V_43 -> V_66 / 2 ) ;
memcpy ( V_62 + V_43 -> V_44 , V_57 , V_58 ) ;
}
V_43 -> V_44 += V_58 ;
}
static inline void F_23 ( struct V_32 * V_33 ,
char * V_57 , unsigned int V_58 )
{
struct V_60 * V_43 = V_33 -> V_43 ;
unsigned int V_70 = ( V_43 -> V_66 / 2 ) - V_43 -> V_44 ;
if ( V_70 >= V_58 ) {
F_22 ( V_43 , V_57 , V_58 ) ;
} else {
if ( V_70 ) {
F_22 ( V_43 , V_57 , V_70 ) ;
if ( V_43 -> V_36 && V_33 -> V_37 )
F_15 ( V_43 -> V_36 ) ;
}
F_19 ( V_33 , V_57 + V_70 , V_58 - V_70 ) ;
}
}
static void F_24 ( struct V_71 * V_71 )
{
struct V_35 * V_36 = V_71 -> V_63 ;
struct V_32 * V_33 = & V_36 -> V_72 -> V_32 ;
char * V_57 = ( char * ) V_71 -> V_73 ;
int V_58 = V_71 -> V_74 ;
int V_52 = 0 ;
if ( ! V_33 -> V_75 || V_71 -> V_76 ) {
if ( V_71 -> V_76 == - V_77 )
goto V_78;
return;
}
if ( ! F_14 ( V_36 , V_33 ) )
goto V_78;
if ( V_58 == V_71 -> V_79 )
F_23 ( V_33 , V_57 , V_58 ) ;
else
F_21 ( V_33 , V_57 , V_58 ) ;
V_78:
V_52 = F_25 ( V_71 , V_80 ) ;
if ( V_52 )
log ( L_4 , V_52 ) ;
}
static int F_26 ( int V_81 , struct V_71 * V_71 ,
int * V_82 , int * V_83 , int * V_84 )
{
struct V_85 * V_86 = NULL ;
int V_52 = V_87 ;
for ( * V_82 = * V_83 = - 1 ; V_81 < V_71 -> V_88 ; V_81 ++ ) {
V_86 = & V_71 -> V_89 [ V_81 ] ;
if ( - V_90 == V_86 -> V_76 ) {
if ( ++ * V_84 > V_71 -> V_88 / 3 )
return V_91 ;
continue;
}
if ( V_86 -> V_76 || V_86 -> V_74 <= 0
|| V_86 -> V_74 > V_92 ) {
if ( * V_82 != - 1 )
break;
continue;
}
if ( V_86 -> V_74 == V_92 ) {
if ( * V_82 == - 1 )
* V_82 = V_81 ;
* V_83 = V_81 ;
continue;
}
if ( V_86 -> V_74 < V_92 ) {
if ( * V_82 == - 1 ) {
* V_82 = V_81 ;
* V_83 = V_81 ;
return V_93 ;
}
break;
}
}
if ( * V_82 == - 1 && * V_83 == - 1 )
V_52 = V_94 ;
return V_52 ;
}
static void F_27 ( struct V_71 * V_71 )
{
struct V_35 * V_36 = V_71 -> V_63 ;
struct V_32 * V_33 = & V_36 -> V_72 -> V_32 ;
int V_84 = 0 , V_82 = 0 , V_83 = 0 ;
char * V_57 = ( char * ) V_71 -> V_73 ;
int V_52 = 0 ;
if ( ! V_33 -> V_75 )
return;
do {
if ( ! F_14 ( V_36 , V_33 ) )
goto V_95;
switch ( F_26 ( V_82 , V_71 , & V_82 , & V_83 , & V_84 ) ) {
case V_87 :
F_23 ( V_33 , V_57 + ( V_82 * V_92 ) ,
( V_83 - V_82 + 1 ) * V_92 ) ;
break;
case V_93 :
F_21 ( V_33 , V_57 + ( V_82 * V_92 ) ,
V_92 ) ;
break;
case V_94 :
goto V_95;
case V_91 :
log ( L_5 ) ;
F_28 ( & V_33 -> V_96 ) ;
return;
}
} while ( V_82 = V_83 + 1 , V_82 < V_71 -> V_88 );
V_95:
V_52 = F_25 ( V_71 , V_80 ) ;
if ( V_52 )
log ( L_6 , V_52 ) ;
}
static int F_29 ( struct V_32 * V_33 )
{
struct V_97 * V_18 = V_33 -> V_72 -> V_18 ;
int V_2 ;
if ( V_33 -> V_98 [ 0 ] )
return 0 ;
for ( V_2 = 0 ; V_2 < V_99 ; V_2 ++ ) {
struct V_71 * V_71 ;
void * V_100 ;
int V_101 ;
V_71 = F_30 ( V_102 , V_103 ) ;
if ( V_71 == NULL )
goto V_95;
V_33 -> V_98 [ V_2 ] = V_71 ;
V_100 = F_31 ( V_18 ,
V_92 * V_102 ,
V_103 ,
& V_71 -> V_104 ) ;
V_71 -> V_105 = F_27 ;
V_71 -> V_106 = V_18 ;
V_71 -> V_63 = V_33 -> V_36 ;
V_71 -> V_107 = F_32 ( V_18 ,
V_33 -> V_108 ) ;
V_71 -> V_109 = 1 ;
V_71 -> V_110 = V_111 | V_112 ;
V_71 -> V_88 = V_102 ;
V_71 -> V_73 = V_100 ;
V_71 -> V_79 = V_102 * V_92 ;
for ( V_101 = 0 ; V_101 < V_102 ; V_101 ++ ) {
V_71 -> V_89 [ V_101 ] . V_61 = V_92 * V_101 ;
V_71 -> V_89 [ V_101 ] . V_113 = V_92 ;
}
}
return 0 ;
V_95:
for (; V_2 > 0 ; V_2 -- )
;
return - V_114 ;
}
int F_33 ( struct V_71 * * V_98 , int V_115 ,
struct V_97 * V_18 , T_3 V_116 ,
int V_117 , T_4 V_118 ,
T_5 V_119 , void * V_63 )
{
int V_2 = 0 ;
for (; V_2 < V_115 ; V_2 ++ ) {
void * V_100 ;
struct V_71 * V_71 = F_30 ( 0 , V_118 ) ;
if ( V_71 == NULL )
return V_2 ;
V_100 = F_31 ( V_18 , V_117 , V_118 ,
& V_71 -> V_104 ) ;
if ( V_100 == NULL ) {
F_34 ( V_71 ) ;
return V_2 ;
}
F_35 ( V_71 , V_18 , F_36 ( V_18 , V_116 ) ,
V_100 , V_117 , V_119 , V_63 ) ;
V_71 -> V_110 |= V_112 ;
V_98 [ V_2 ] = V_71 ;
}
return V_2 ;
}
void F_37 ( struct V_71 * * V_98 , int V_115 )
{
int V_2 ;
struct V_71 * V_71 ;
for ( V_2 = 0 ; V_2 < V_115 ; V_2 ++ ) {
V_71 = V_98 [ V_2 ] ;
if ( V_71 ) {
F_38 ( V_71 -> V_106 ,
V_71 -> V_79 ,
V_71 -> V_73 ,
V_71 -> V_104 ) ;
F_34 ( V_71 ) ;
V_98 [ V_2 ] = NULL ;
}
}
}
static int F_39 ( struct V_32 * V_33 )
{
if ( V_33 -> V_98 [ 0 ] )
return 0 ;
F_33 ( V_33 -> V_98 , V_99 ,
V_33 -> V_72 -> V_18 , V_33 -> V_108 ,
0x2000 , V_103 ,
F_24 , V_33 -> V_36 ) ;
return 0 ;
}
static void F_40 ( struct V_32 * V_33 )
{
F_37 ( V_33 -> V_98 , V_99 ) ;
}
static void F_41 ( struct V_120 * V_121 , struct V_46 * V_47 )
{
F_42 ( V_47 ) ;
V_47 -> V_53 = V_122 ;
}
static void F_43 ( struct V_120 * V_121 , struct V_46 * V_47 )
{
struct V_35 * V_36 = V_121 -> V_123 ;
V_47 -> V_53 = V_124 ;
F_44 ( & V_47 -> V_51 , & V_36 -> V_49 ) ;
}
static int F_45 ( struct V_120 * V_121 , struct V_46 * V_47 ,
enum V_125 V_126 )
{
struct V_35 * V_36 = V_121 -> V_123 ;
int V_127 ;
switch ( V_36 -> type ) {
case V_128 :
if ( V_122 == V_47 -> V_53 ) {
struct V_129 * V_64 ;
V_64 = & V_36 -> V_72 -> V_32 . V_63 . V_64 ;
V_47 -> V_130 = V_64 -> V_65 ;
V_47 -> V_131 = V_64 -> V_131 ;
V_47 -> V_132 = V_64 -> V_132 ;
V_127 = F_46 ( V_121 , V_47 , NULL ) ;
if ( V_127 < 0 )
return V_127 ;
}
break;
case V_133 :
if ( V_122 == V_47 -> V_53 ) {
V_47 -> V_130 = V_36 -> V_72 -> V_60 . V_66 ;
V_127 = F_46 ( V_121 , V_47 , NULL ) ;
if ( V_127 < 0 )
return V_127 ;
}
break;
default:
return - V_134 ;
}
V_47 -> V_126 = V_126 ;
V_47 -> V_53 = V_135 ;
return 0 ;
}
static int F_47 ( struct V_32 * V_33 )
{
int V_2 , V_52 ;
V_33 -> V_75 = 1 ;
for ( V_2 = 0 ; V_2 < V_99 ; V_2 ++ ) {
V_52 = F_25 ( V_33 -> V_98 [ V_2 ] , V_103 ) ;
if ( V_52 )
log ( L_7 , V_2 , V_52 ) ;
}
return V_52 ;
}
static int F_48 ( struct V_14 * V_72 )
{
struct V_32 * V_33 = & V_72 -> V_32 ;
T_6 V_136 ;
F_49 ( V_72 , V_137 , 0 , & V_136 ) ;
F_49 ( V_72 , V_138 , V_139 , & V_136 ) ;
if ( V_72 -> V_140 ) {
F_29 ( V_33 ) ;
F_50 ( & V_33 -> V_96 , V_141 ) ;
} else {
F_39 ( V_33 ) ;
}
F_47 ( V_33 ) ;
return 0 ;
}
static int F_51 ( struct V_120 * V_121 , unsigned int * V_58 ,
unsigned int * V_130 )
{
struct V_35 * V_36 = V_121 -> V_123 ;
struct V_14 * V_72 = V_36 -> V_72 ;
switch ( V_36 -> type ) {
default:
return - V_134 ;
case V_128 : {
struct V_32 * V_33 = & V_72 -> V_32 ;
struct V_129 * V_64 = & V_33 -> V_63 . V_64 ;
* V_130 = F_52 ( V_64 -> V_65 ) ;
if ( * V_58 < 4 )
* V_58 = 4 ;
if ( 1 ) {
V_33 -> V_108 = 0x82 ;
V_33 -> V_43 = & V_72 -> V_60 ;
V_33 -> V_43 -> V_33 = V_33 ;
V_33 -> V_72 = V_72 ;
V_33 -> V_142 = V_64 -> V_132 / 2 ;
V_33 -> V_42 = V_64 -> V_131 * 2 ;
V_33 -> V_36 = V_36 ;
}
return F_48 ( V_72 ) ;
}
case V_133 : {
struct V_60 * V_43 = & V_72 -> V_60 ;
* V_130 = F_52 ( V_43 -> V_66 ) ;
log ( L_8 , * V_130 ) ;
if ( * V_58 == 0 )
* V_58 = 4 ;
}
break;
}
return 0 ;
}
static int F_53 ( struct V_8 * V_8 , void * V_9 ,
struct V_143 * V_144 )
{
if ( F_54 ( V_145 ) <= V_144 -> V_34 )
return - V_134 ;
V_144 -> type = V_128 ;
V_144 -> V_146 = 0 ;
V_144 -> V_147 = V_145 [ V_144 -> V_34 ] . V_148 ;
strcpy ( V_144 -> V_149 , V_145 [ V_144 -> V_34 ] . V_150 ) ;
return 0 ;
}
static int F_55 ( struct V_8 * V_8 , void * V_9 , struct V_151 * V_144 )
{
struct V_35 * V_36 = V_9 ;
struct V_14 * V_72 = V_36 -> V_72 ;
V_144 -> V_152 . V_64 = V_72 -> V_32 . V_63 . V_64 ;
return 0 ;
}
static int F_56 ( struct V_14 * V_72 , struct V_129 * V_64 )
{
struct V_32 * V_33 = & V_72 -> V_32 ;
struct V_153 * V_63 = & V_33 -> V_63 ;
struct V_129 * V_154 = & V_63 -> V_64 ;
T_6 V_52 = 0 , V_136 = 0 , V_155 ;
if ( V_64 -> V_147 == V_156 ) {
V_155 = V_157 ;
} else {
V_64 -> V_147 = V_158 ;
V_155 = V_159 ;
}
V_52 = F_49 ( V_72 , V_160 ,
V_155 , & V_136 ) ;
V_155 = V_161 ;
switch ( V_64 -> V_131 ) {
case 704 :
V_155 = V_162 ;
break;
default:
V_64 -> V_131 = 720 ;
case 720 :
break;
}
V_52 |= F_49 ( V_72 , V_163 ,
V_155 , & V_136 ) ;
if ( V_52 || V_136 )
return - V_164 ;
V_154 -> V_147 = V_64 -> V_147 ;
V_64 -> V_132 = ( V_63 -> V_165 & V_166 ) ? 480 : 576 ;
if ( ( V_154 -> V_131 != V_64 -> V_131 )
|| ( V_154 -> V_132 != V_64 -> V_132 ) ) {
V_154 -> V_131 = V_64 -> V_131 ;
V_154 -> V_132 = V_64 -> V_132 ;
V_154 -> V_167 = V_64 -> V_131 * 2 ;
V_154 -> V_65 = V_64 -> V_131 * V_64 -> V_132 * 2 ;
}
* V_64 = * V_154 ;
return 0 ;
}
static int F_57 ( struct V_8 * V_8 , void * V_9 , struct V_151 * V_144 )
{
struct V_35 * V_36 = V_9 ;
struct V_14 * V_72 = V_36 -> V_72 ;
if ( V_128 != V_144 -> type )
return - V_134 ;
F_58 ( & V_72 -> V_168 ) ;
if ( V_72 -> V_169 == NULL )
V_72 -> V_169 = V_8 ;
else if ( V_8 != V_72 -> V_169 ) {
F_59 ( & V_72 -> V_168 ) ;
return - V_134 ;
}
F_56 ( V_72 , & V_144 -> V_152 . V_64 ) ;
F_59 ( & V_72 -> V_168 ) ;
return 0 ;
}
static int F_60 ( struct V_8 * V_8 , void * V_9 ,
struct V_151 * V_170 )
{
struct V_35 * V_36 = V_9 ;
struct V_14 * V_72 = V_36 -> V_72 ;
struct V_171 * V_172 = & V_170 -> V_152 . V_43 ;
V_172 -> V_173 = 720 * 2 ;
V_172 -> V_174 = 6750000 * 4 ;
V_172 -> V_175 = V_176 ;
V_172 -> V_61 = 64 * 4 ;
if ( V_72 -> V_32 . V_63 . V_165 & V_166 ) {
V_172 -> V_81 [ 0 ] = 10 ;
V_172 -> V_81 [ 1 ] = 264 ;
V_172 -> V_58 [ 0 ] = V_177 ;
V_172 -> V_58 [ 1 ] = V_177 ;
} else {
V_172 -> V_81 [ 0 ] = 6 ;
V_172 -> V_81 [ 1 ] = 314 ;
V_172 -> V_58 [ 0 ] = V_178 ;
V_172 -> V_58 [ 1 ] = V_178 ;
}
V_172 -> V_146 = V_179 ;
return 0 ;
}
static int F_61 ( struct V_14 * V_72 , T_1 V_180 )
{
struct V_32 * V_33 = & V_72 -> V_32 ;
struct V_60 * V_43 = & V_72 -> V_60 ;
struct V_153 * V_63 ;
struct V_129 * V_64 ;
T_6 V_2 , V_52 = 0 , V_136 , V_181 ;
int V_132 ;
for ( V_2 = 0 ; V_2 < V_182 ; V_2 ++ ) {
if ( V_180 & V_183 [ V_2 ] . V_184 ) {
V_181 = V_183 [ V_2 ] . V_185 ;
log ( L_9 , V_183 [ V_2 ] . V_150 ) ;
goto V_186;
}
}
return - V_134 ;
V_186:
F_58 ( & V_72 -> V_168 ) ;
V_52 = F_49 ( V_72 , V_187 , V_181 , & V_136 ) ;
if ( V_52 || V_136 )
goto V_95;
V_63 = & V_33 -> V_63 ;
V_63 -> V_165 = V_183 [ V_2 ] . V_184 ;
if ( V_63 -> V_165 & V_166 ) {
V_43 -> V_66 = V_188 ;
V_132 = 480 ;
} else {
V_43 -> V_66 = V_189 ;
V_132 = 576 ;
}
V_64 = & V_63 -> V_64 ;
if ( V_64 -> V_132 != V_132 ) {
V_64 -> V_132 = V_132 ;
V_64 -> V_65 = V_64 -> V_131 * V_64 -> V_132 * 2 ;
}
V_95:
F_59 ( & V_72 -> V_168 ) ;
return V_52 ;
}
static int F_62 ( struct V_8 * V_8 , void * V_9 , T_1 V_180 )
{
struct V_35 * V_36 = V_9 ;
return F_61 ( V_36 -> V_72 , V_180 ) ;
}
static int F_63 ( struct V_8 * V_8 , void * V_9 , T_1 * V_180 )
{
struct V_35 * V_36 = V_9 ;
* V_180 = V_36 -> V_72 -> V_32 . V_63 . V_165 ;
return 0 ;
}
static int F_64 ( struct V_8 * V_8 , void * V_9 , struct V_190 * V_191 )
{
if ( V_191 -> V_34 >= V_192 )
return - V_134 ;
strcpy ( V_191 -> V_150 , V_193 [ V_191 -> V_34 ] . V_150 ) ;
V_191 -> type = V_194 ;
V_191 -> V_195 = 1 ;
V_191 -> V_196 = 0 ;
V_191 -> V_197 = V_198 ;
V_191 -> V_76 = 0 ;
return 0 ;
}
static int F_65 ( struct V_8 * V_8 , void * V_9 , unsigned int * V_2 )
{
struct V_35 * V_36 = V_9 ;
struct V_14 * V_72 = V_36 -> V_72 ;
struct V_153 * V_63 = & V_72 -> V_32 . V_63 ;
* V_2 = V_63 -> V_199 ;
return 0 ;
}
static int F_66 ( struct V_8 * V_8 , void * V_9 , unsigned int V_2 )
{
struct V_35 * V_36 = V_9 ;
struct V_14 * V_72 = V_36 -> V_72 ;
T_6 V_52 , V_136 ;
if ( V_2 >= V_192 )
return - V_134 ;
V_52 = F_49 ( V_72 , V_200 ,
V_193 [ V_2 ] . V_201 , & V_136 ) ;
if ( V_52 )
return V_52 ;
V_72 -> V_32 . V_63 . V_199 = V_2 ;
return 0 ;
}
static int F_67 ( struct V_202 * V_203 )
{
struct V_14 * V_72 = F_68 ( V_203 -> V_204 , struct V_14 ,
V_32 . V_205 ) ;
struct V_206 V_181 = { 0 } ;
T_6 V_52 = 0 , V_136 , V_207 ;
switch ( V_203 -> V_208 ) {
case V_209 :
V_181 . V_210 = V_211 ;
break;
case V_212 :
V_181 . V_210 = V_213 ;
break;
case V_214 :
V_181 . V_210 = V_215 ;
break;
case V_216 :
V_181 . V_210 = V_217 ;
break;
}
V_181 . V_218 = V_203 -> V_219 ;
V_207 = * ( T_6 * ) & V_181 ;
F_58 ( & V_72 -> V_168 ) ;
V_52 = F_49 ( V_72 , V_220 , V_207 , & V_136 ) ;
V_52 = F_49 ( V_72 , V_137 , 0 , & V_136 ) ;
F_59 ( & V_72 -> V_168 ) ;
F_69 ( V_221 ) ;
F_70 ( V_222 / 4 ) ;
return V_52 ;
}
static int F_71 ( struct V_8 * V_8 , void * V_9 , struct V_223 * V_224 )
{
if ( 0 != V_224 -> V_34 )
return - V_134 ;
V_224 -> V_225 = V_226 ;
strcpy ( V_224 -> V_150 , L_10 ) ;
V_224 -> V_227 = 0 ;
return 0 ;
}
static int F_72 ( struct V_8 * V_8 , void * V_9 , struct V_223 * V_224 )
{
V_224 -> V_34 = 0 ;
V_224 -> V_225 = V_226 ;
strcpy ( V_224 -> V_150 , L_10 ) ;
V_224 -> V_227 = 0 ;
return 0 ;
}
static int F_73 ( struct V_8 * V_8 , void * V_9 , const struct V_223 * V_224 )
{
return ( 0 == V_224 -> V_34 ) ? 0 : - V_134 ;
}
static int F_74 ( struct V_8 * V_8 , void * V_9 , struct V_228 * V_196 )
{
struct V_35 * V_36 = V_9 ;
struct V_14 * V_72 = V_36 -> V_72 ;
struct V_229 V_230 ;
T_6 V_58 = 5 , V_52 , V_136 ;
int V_34 ;
if ( 0 != V_196 -> V_34 )
return - V_134 ;
F_58 ( & V_72 -> V_168 ) ;
V_52 = F_75 ( V_72 , V_231 , V_232 ,
& V_230 , & V_136 , sizeof( V_230 ) ) ;
while ( V_230 . V_233 && V_58 -- && ! V_52 ) {
F_69 ( V_221 ) ;
F_70 ( V_222 ) ;
V_52 = F_75 ( V_72 , V_231 , V_232 ,
& V_230 , & V_136 , sizeof( V_230 ) ) ;
}
F_59 ( & V_72 -> V_168 ) ;
if ( V_234 )
log ( L_11 , V_230 . V_235 , V_230 . V_236 ) ;
if ( V_52 || V_136 )
V_196 -> signal = 0 ;
else if ( V_230 . V_235 && ! V_230 . V_236 )
V_196 -> signal = 0xFFFF ;
else
V_196 -> signal = ( V_230 . V_236 * 255 / 10 ) << 8 ;
strcpy ( V_196 -> V_150 , L_12 ) ;
V_196 -> type = V_237 ;
V_196 -> V_238 = V_239 / 62500 ;
V_196 -> V_240 = V_241 / 62500 ;
V_196 -> V_225 = V_242 | V_243 |
V_244 | V_245 ;
V_34 = V_72 -> V_32 . V_63 . V_246 ;
V_196 -> V_247 = V_248 [ V_34 ] . V_249 ;
V_196 -> V_250 = V_248 [ V_34 ] . V_251 ;
V_196 -> V_252 = 0 ;
return 0 ;
}
static int F_76 ( struct V_14 * V_72 , int V_34 )
{
T_6 V_52 = 0 , V_136 , V_181 , V_253 ;
F_58 ( & V_72 -> V_168 ) ;
V_181 = V_248 [ V_34 ] . V_254 ;
V_52 = F_49 ( V_72 , V_255 , V_181 , & V_136 ) ;
V_253 = F_1 ( V_72 -> V_32 . V_63 . V_165 ) ;
V_52 |= F_49 ( V_72 , V_256 , V_253 ,
& V_136 ) ;
if ( ! V_52 )
V_72 -> V_32 . V_63 . V_246 = V_34 ;
F_59 ( & V_72 -> V_168 ) ;
return V_52 ;
}
static int F_77 ( struct V_8 * V_8 , void * V_9 , const struct V_228 * V_224 )
{
struct V_35 * V_36 = V_9 ;
struct V_14 * V_72 = V_36 -> V_72 ;
int V_34 ;
if ( 0 != V_224 -> V_34 )
return - V_134 ;
for ( V_34 = 0 ; V_34 < V_257 ; V_34 ++ )
if ( V_224 -> V_250 == V_248 [ V_34 ] . V_251 )
return F_76 ( V_72 , V_34 ) ;
return - V_134 ;
}
static int F_78 ( struct V_8 * V_8 , void * V_9 ,
struct V_258 * V_259 )
{
struct V_35 * V_36 = V_9 ;
struct V_14 * V_72 = V_36 -> V_72 ;
struct V_153 * V_63 = & V_72 -> V_32 . V_63 ;
if ( 0 != V_259 -> V_196 )
return - V_134 ;
V_259 -> V_260 = V_63 -> V_259 ;
V_259 -> type = V_237 ;
return 0 ;
}
static int F_79 ( struct V_14 * V_72 , V_69 * V_260 )
{
T_6 V_52 = 0 , V_181 , V_136 ;
struct V_153 * V_63 = & V_72 -> V_32 . V_63 ;
* V_260 = F_80 ( * V_260 ,
V_239 / 62500 , V_241 / 62500 ) ;
V_181 = ( * V_260 ) * 62500 / 1000 ;
F_58 ( & V_72 -> V_168 ) ;
V_52 = F_49 ( V_72 , V_261 , V_181 , & V_136 ) ;
V_52 = F_49 ( V_72 , V_137 , 0 , & V_136 ) ;
F_81 ( 250 ) ;
V_63 -> V_259 = * V_260 ;
F_59 ( & V_72 -> V_168 ) ;
return V_52 ;
}
static int F_82 ( struct V_8 * V_8 , void * V_9 ,
const struct V_258 * V_259 )
{
struct V_35 * V_36 = V_9 ;
struct V_14 * V_72 = V_36 -> V_72 ;
V_69 V_260 = V_259 -> V_260 ;
if ( V_259 -> V_196 )
return - V_134 ;
#ifdef F_83
V_72 -> V_262 = V_263 ;
V_72 -> V_264 = V_265 ;
#endif
return F_79 ( V_72 , & V_260 ) ;
}
static int F_84 ( struct V_8 * V_8 , void * V_9 ,
struct V_266 * V_267 )
{
struct V_35 * V_36 = V_8 -> V_268 ;
return F_85 ( & V_36 -> V_121 , V_267 ) ;
}
static int F_86 ( struct V_8 * V_8 , void * V_9 , struct V_269 * V_267 )
{
struct V_35 * V_36 = V_8 -> V_268 ;
return F_87 ( & V_36 -> V_121 , V_267 ) ;
}
static int F_88 ( struct V_8 * V_8 , void * V_9 , struct V_269 * V_267 )
{
struct V_35 * V_36 = V_8 -> V_268 ;
return F_89 ( & V_36 -> V_121 , V_267 ) ;
}
static int F_90 ( struct V_8 * V_8 , void * V_9 , struct V_269 * V_267 )
{
struct V_35 * V_36 = V_8 -> V_268 ;
return F_91 ( & V_36 -> V_121 , V_267 , V_8 -> V_270 & V_271 ) ;
}
static int F_92 ( struct V_32 * V_33 )
{
if ( V_33 -> V_75 ) {
int V_2 ;
T_6 V_136 ;
struct V_14 * V_72 = V_33 -> V_72 ;
V_33 -> V_75 = 0 ;
for ( V_2 = 0 ; V_2 < V_99 ; ++ V_2 ) {
if ( V_33 -> V_98 [ V_2 ] )
F_93 ( V_33 -> V_98 [ V_2 ] ) ;
}
F_49 ( V_72 , V_138 , V_272 ,
& V_136 ) ;
}
return 0 ;
}
int F_94 ( struct V_14 * V_72 )
{
struct V_32 * V_33 = & V_72 -> V_32 ;
struct V_60 * V_43 = & V_72 -> V_60 ;
F_58 ( & V_72 -> V_168 ) ;
if ( V_33 -> V_75 ) {
struct V_35 * V_36 = V_33 -> V_36 ;
F_92 ( V_33 ) ;
F_40 ( V_33 ) ;
F_95 ( & V_36 -> V_121 ) ;
F_96 ( & V_36 -> V_121 ) ;
V_36 = V_43 -> V_36 ;
if ( V_36 ) {
F_95 ( & V_36 -> V_121 ) ;
F_96 ( & V_36 -> V_121 ) ;
}
}
F_59 ( & V_72 -> V_168 ) ;
return 0 ;
}
static void V_141 ( struct V_273 * V_274 )
{
struct V_32 * V_33 ;
struct V_14 * V_72 ;
V_33 = F_68 ( V_274 , struct V_32 , V_96 ) ;
V_72 = V_33 -> V_72 ;
F_58 ( & V_72 -> V_168 ) ;
F_92 ( V_33 ) ;
F_81 ( 500 ) ;
F_48 ( V_72 ) ;
F_59 ( & V_72 -> V_168 ) ;
}
static int F_97 ( struct V_8 * V_8 , void * V_9 ,
enum V_275 type )
{
struct V_35 * V_36 = V_9 ;
if ( F_98 ( type != V_36 -> type ) )
return - V_134 ;
return F_99 ( & V_36 -> V_121 ) ;
}
static int F_100 ( struct V_8 * V_8 , void * V_9 ,
enum V_275 type )
{
struct V_35 * V_36 = V_8 -> V_268 ;
if ( F_98 ( type != V_36 -> type ) )
return - V_134 ;
return F_101 ( & V_36 -> V_121 ) ;
}
static int F_102 ( struct V_14 * V_72 )
{
T_6 V_52 = 0 , V_136 , V_253 ;
F_69 ( V_221 ) ;
F_70 ( V_222 / 2 ) ;
V_52 = F_103 ( V_72 -> V_18 , 0 ,
( V_72 -> V_140 ?
V_276 :
V_277 ) ) ;
if ( V_52 < 0 )
goto error;
V_52 = F_104 ( V_72 , V_232 ) ;
V_52 |= F_49 ( V_72 , V_200 ,
V_278 , & V_136 ) ;
V_52 |= F_49 ( V_72 , V_187 ,
V_279 , & V_136 ) ;
V_52 |= F_49 ( V_72 , V_160 ,
V_159 , & V_136 ) ;
V_52 |= F_49 ( V_72 , V_163 ,
V_161 , & V_136 ) ;
V_52 |= F_49 ( V_72 , V_261 , V_239 , & V_136 ) ;
V_52 |= F_49 ( V_72 , V_280 , 1 , & V_136 ) ;
V_253 = F_1 ( V_72 -> V_32 . V_63 . V_165 ) ;
V_52 |= F_49 ( V_72 , V_256 , V_253 , & V_136 ) ;
V_52 |= F_49 ( V_72 , V_255 ,
V_281 , & V_136 ) ;
V_52 |= F_49 ( V_72 , V_282 ,
V_283 , & V_136 ) ;
error:
return V_52 ;
}
static int V_263 ( struct V_14 * V_72 )
{
F_105 ( V_72 ) ;
F_92 ( & V_72 -> V_32 ) ;
F_40 ( & V_72 -> V_32 ) ;
F_103 ( V_72 -> V_18 , 0 , 0 ) ;
F_81 ( 300 ) ;
return 0 ;
}
static int F_106 ( struct V_14 * V_72 ,
struct V_153 * V_63 )
{
struct V_35 * V_36 = V_72 -> V_32 . V_36 ;
F_102 ( V_72 ) ;
F_61 ( V_72 , V_63 -> V_165 ) ;
F_66 ( NULL , V_36 , V_63 -> V_199 ) ;
F_76 ( V_72 , V_63 -> V_246 ) ;
F_56 ( V_72 , & V_63 -> V_64 ) ;
F_79 ( V_72 , & V_63 -> V_259 ) ;
return 0 ;
}
static int V_265 ( struct V_14 * V_72 )
{
struct V_32 * V_33 = & V_72 -> V_32 ;
F_106 ( V_72 , & V_33 -> V_63 ) ;
if ( V_33 -> V_36 -> V_41 )
F_6 ( V_33 , 0 ) ;
F_48 ( V_72 ) ;
F_107 ( V_72 ) ;
return 0 ;
}
void F_108 ( struct V_12 * V_284 , int V_234 )
{
V_284 -> V_285 = 0 ;
if ( V_234 & 0x1 )
V_284 -> V_285 = V_286 ;
if ( V_234 & 0x2 )
V_284 -> V_285 = V_286 | V_287 ;
}
static void F_109 ( struct V_153 * V_63 )
{
V_63 -> V_199 = 0 ;
V_63 -> V_246 = 1 ;
V_63 -> V_165 = V_288 ;
V_63 -> V_64 = (struct V_129 ) {
. V_131 = 720 ,
. V_132 = 576 ,
. V_147 = V_158 ,
. V_126 = V_289 ,
. V_167 = 720 * 2 ,
. V_65 = 720 * 576 * 2 ,
. V_290 = V_291 ,
. V_292 = 0
} ;
}
static int F_110 ( struct V_8 * V_8 )
{
struct V_12 * V_284 = F_3 ( V_8 ) ;
struct V_14 * V_72 = F_4 ( V_284 ) ;
struct V_35 * V_36 = NULL ;
int V_52 = - V_114 ;
F_58 ( & V_72 -> V_168 ) ;
F_111 ( V_72 -> V_293 ) ;
if ( V_72 -> V_53 && ! ( V_72 -> V_53 & V_294 ) ) {
V_52 = - V_164 ;
goto V_95;
}
V_36 = F_112 ( sizeof( struct V_35 ) , V_103 ) ;
if ( ! V_36 )
goto V_95;
if ( V_284 -> V_25 == V_295 ) {
V_72 -> V_140 = V_296 ;
F_109 ( & V_72 -> V_32 . V_63 ) ;
V_52 = F_102 ( V_72 ) ;
if ( V_52 < 0 ) {
F_113 ( V_36 ) ;
V_52 = - 1 ;
goto V_95;
}
V_36 -> type = V_128 ;
V_72 -> V_32 . V_297 ++ ;
F_108 ( V_284 , V_234 ) ;
F_114 ( & V_36 -> V_121 , & V_298 ,
NULL , & V_36 -> V_48 ,
V_128 ,
V_289 ,
sizeof( struct V_46 ) ,
V_36 , NULL ) ;
} else {
V_36 -> type = V_133 ;
V_72 -> V_60 . V_36 = V_36 ;
V_72 -> V_60 . V_297 ++ ;
F_114 ( & V_36 -> V_121 , & V_298 ,
NULL , & V_36 -> V_48 ,
V_133 ,
V_299 ,
sizeof( struct V_46 ) ,
V_36 , NULL ) ;
}
V_72 -> V_53 |= V_294 ;
V_36 -> V_72 = V_72 ;
V_36 -> V_41 = NULL ;
F_115 ( & V_36 -> V_49 ) ;
F_116 ( & V_36 -> V_48 ) ;
V_8 -> V_268 = V_36 ;
F_117 ( & V_72 -> V_300 ) ;
F_59 ( & V_72 -> V_168 ) ;
return 0 ;
V_95:
F_118 ( V_72 -> V_293 ) ;
F_59 ( & V_72 -> V_168 ) ;
return V_52 ;
}
static int F_119 ( struct V_8 * V_8 )
{
struct V_35 * V_36 = V_8 -> V_268 ;
struct V_14 * V_72 = V_36 -> V_72 ;
T_6 V_136 = 0 ;
F_58 ( & V_72 -> V_168 ) ;
if ( V_36 -> type == V_128 ) {
F_92 ( & V_72 -> V_32 ) ;
F_40 ( & V_72 -> V_32 ) ;
F_49 ( V_72 , V_138 , V_272 ,
& V_136 ) ;
V_72 -> V_169 = NULL ;
V_72 -> V_32 . V_297 -- ;
} else if ( V_36 -> type == V_133 ) {
V_72 -> V_60 . V_36 = NULL ;
V_72 -> V_60 . V_297 -- ;
}
if ( ! V_72 -> V_60 . V_297 && ! V_72 -> V_32 . V_297 )
V_72 -> V_53 &= ~ V_294 ;
F_95 ( & V_36 -> V_121 ) ;
F_96 ( & V_36 -> V_121 ) ;
F_118 ( V_72 -> V_293 ) ;
F_59 ( & V_72 -> V_168 ) ;
F_113 ( V_36 ) ;
V_8 -> V_268 = NULL ;
F_120 ( & V_72 -> V_300 , V_301 ) ;
return 0 ;
}
static int F_121 ( struct V_8 * V_8 , struct V_302 * V_303 )
{
struct V_35 * V_36 = V_8 -> V_268 ;
return F_122 ( & V_36 -> V_121 , V_303 ) ;
}
static unsigned int F_123 ( struct V_8 * V_8 , T_7 * V_304 )
{
struct V_35 * V_36 = V_8 -> V_268 ;
return F_124 ( V_8 , & V_36 -> V_121 , V_304 ) ;
}
static T_8 F_125 ( struct V_8 * V_8 , char T_9 * V_305 ,
T_10 V_58 , T_11 * V_306 )
{
struct V_35 * V_36 = V_8 -> V_268 ;
return F_126 ( & V_36 -> V_121 , V_305 , V_58 , V_306 ,
0 , V_8 -> V_270 & V_271 ) ;
}
void F_127 ( struct V_14 * V_72 )
{
struct V_32 * V_33 = & V_72 -> V_32 ;
struct V_60 * V_43 = & V_72 -> V_60 ;
F_128 ( & V_33 -> V_307 ) ;
F_128 ( & V_43 -> V_307 ) ;
F_129 ( & V_33 -> V_205 ) ;
log () ;
}
int F_130 ( struct V_14 * V_72 )
{
struct V_32 * V_33 = & V_72 -> V_32 ;
struct V_60 * V_43 = & V_72 -> V_60 ;
struct V_308 * V_309 = & V_33 -> V_205 ;
V_69 V_259 = V_239 / 62500 ;
int V_52 = - V_114 ;
F_131 ( V_309 , 4 ) ;
F_132 ( V_309 , & V_310 , V_209 ,
0 , 10000 , 1 , 100 ) ;
F_132 ( V_309 , & V_310 , V_212 ,
0 , 10000 , 1 , 100 ) ;
F_132 ( V_309 , & V_310 , V_214 ,
0 , 10000 , 1 , 100 ) ;
F_132 ( V_309 , & V_310 , V_216 ,
0 , 10000 , 1 , 100 ) ;
if ( V_309 -> error ) {
F_129 ( V_309 ) ;
return V_309 -> error ;
}
F_79 ( V_72 , & V_259 ) ;
V_33 -> V_307 = V_311 ;
V_33 -> V_307 . V_312 = & V_72 -> V_312 ;
V_33 -> V_307 . V_205 = V_309 ;
F_133 ( & V_33 -> V_307 , V_72 ) ;
V_52 = F_134 ( & V_33 -> V_307 , V_295 , - 1 ) ;
if ( V_52 != 0 )
goto V_95;
V_43 -> V_307 = V_311 ;
V_43 -> V_307 . V_312 = & V_72 -> V_312 ;
V_43 -> V_307 . V_205 = V_309 ;
F_133 ( & V_43 -> V_307 , V_72 ) ;
V_52 = F_134 ( & V_43 -> V_307 , V_26 , - 1 ) ;
if ( V_52 != 0 )
goto V_95;
log ( L_13 ) ;
return 0 ;
V_95:
log ( L_14 , V_52 ) ;
F_127 ( V_72 ) ;
return V_52 ;
}
