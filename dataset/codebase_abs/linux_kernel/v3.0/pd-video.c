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
struct V_12 * V_13 = V_9 ;
struct V_14 * V_15 = V_13 -> V_16 ;
F_3 ( V_13 ) ;
strcpy ( V_11 -> V_17 , L_1 ) ;
strcpy ( V_11 -> V_18 , L_2 ) ;
F_4 ( V_15 -> V_19 , V_11 -> V_20 , sizeof( V_11 -> V_20 ) ) ;
V_11 -> V_21 = F_5 ( 0 , 0 , 1 ) ;
V_11 -> V_22 = V_23 | V_24 |
V_25 | V_26 |
V_27 | V_28 ;
return 0 ;
}
static void F_6 ( struct V_29 * V_30 , bool V_31 )
{
struct V_12 * V_13 = V_30 -> V_13 ;
V_30 -> V_32 = V_31 ;
V_30 -> V_33 = 0 ;
V_30 -> V_34 = 0 ;
V_30 -> V_35 = ( char * ) F_7 ( V_13 -> V_36 )
+ V_31 * V_30 -> V_37 ;
V_30 -> V_38 -> V_39 = 0 ;
}
static bool F_8 ( struct V_12 * V_13 , int * V_40 )
{
struct V_41 * V_42 = V_13 -> V_36 ;
if ( V_42 )
return true ;
F_9 ( & V_13 -> V_43 ) ;
if ( ! F_10 ( & V_13 -> V_44 ) ) {
V_42 = F_11 ( V_13 -> V_44 . V_45 ,
struct V_41 , V_46 ) ;
if ( V_40 )
* V_40 = 1 ;
V_13 -> V_36 = V_42 ;
F_12 ( & V_42 -> V_46 ) ;
}
F_13 ( & V_13 -> V_43 ) ;
return ! ! V_42 ;
}
static bool F_14 ( struct V_12 * V_13 , struct V_29 * V_30 )
{
int V_40 = 0 ;
bool V_47 = true ;
V_47 = F_8 ( V_13 , & V_40 ) ;
if ( V_47 && V_40 )
F_6 ( V_30 , 0 ) ;
return V_47 ;
}
static void F_15 ( struct V_12 * V_13 )
{
struct V_41 * V_42 = V_13 -> V_36 ;
if ( V_42 == NULL )
return;
V_13 -> V_36 = NULL ;
V_42 -> V_48 = V_49 ;
V_42 -> V_32 ++ ;
F_16 ( & V_42 -> V_50 ) ;
F_17 ( & V_42 -> V_51 ) ;
}
static void F_18 ( struct V_29 * V_30 )
{
if ( 1 == V_30 -> V_32 )
F_15 ( V_30 -> V_13 ) ;
else
F_6 ( V_30 , 1 ) ;
}
static void F_19 ( struct V_29 * V_30 , char * V_52 ,
unsigned int V_53 )
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
while ( V_53 && V_53 >= V_30 -> V_37 ) {
if ( V_30 -> V_34 ) {
F_20 ( V_30 -> V_34 ) ;
V_30 -> V_34 = 0 ;
continue;
}
F_20 ( V_30 -> V_37 ) ;
}
if ( V_53 && V_53 < V_30 -> V_37 ) {
memcpy ( V_30 -> V_35 , V_52 , V_53 ) ;
V_30 -> V_34 = V_30 -> V_37 - V_53 ;
V_30 -> V_35 += V_53 ;
}
return;
V_54:
F_18 ( V_30 ) ;
}
static void F_21 ( struct V_29 * V_30 , char * V_52 , int V_53 )
{
struct V_55 * V_38 = V_30 -> V_38 ;
int V_56 ;
char * V_57 ;
V_56 = ( V_30 -> V_58 . V_59 . V_60 / 2 + V_38 -> V_61 / 2 )
- ( V_38 -> V_39 + V_30 -> V_37 * V_30 -> V_33 ) ;
if ( V_30 -> V_34 )
V_56 -= ( V_30 -> V_37 - V_30 -> V_34 ) ;
if ( V_56 > V_53 || V_56 <= 0 )
goto V_62;
V_57 = V_52 + V_56 ;
if ( ! strncmp ( V_57 , L_3 , 4 ) ) {
int V_63 = * ( ( V_64 * ) ( V_57 + 12 ) ) ;
if ( ( V_63 & 1 ) ^ V_30 -> V_32 ) {
F_6 ( V_30 , V_30 -> V_32 ) ;
return;
}
F_19 ( V_30 , V_52 , V_56 ) ;
}
V_62:
F_18 ( V_30 ) ;
}
static inline void F_22 ( struct V_55 * V_38 ,
char * V_52 , unsigned int V_53 )
{
struct V_12 * V_13 = V_38 -> V_13 ;
if ( V_13 && F_8 ( V_13 , NULL ) ) {
char * V_57 = F_7 ( V_13 -> V_36 ) ;
if ( V_38 -> V_30 -> V_32 )
V_57 += ( V_38 -> V_61 / 2 ) ;
memcpy ( V_57 + V_38 -> V_39 , V_52 , V_53 ) ;
}
V_38 -> V_39 += V_53 ;
}
static inline void F_23 ( struct V_29 * V_30 ,
char * V_52 , unsigned int V_53 )
{
struct V_55 * V_38 = V_30 -> V_38 ;
unsigned int V_65 = ( V_38 -> V_61 / 2 ) - V_38 -> V_39 ;
if ( V_65 >= V_53 ) {
F_22 ( V_38 , V_52 , V_53 ) ;
} else {
if ( V_65 ) {
F_22 ( V_38 , V_52 , V_65 ) ;
if ( V_38 -> V_13 && V_30 -> V_32 )
F_15 ( V_38 -> V_13 ) ;
}
F_19 ( V_30 , V_52 + V_65 , V_53 - V_65 ) ;
}
}
static void F_24 ( struct V_66 * V_66 )
{
struct V_12 * V_13 = V_66 -> V_58 ;
struct V_29 * V_30 = & V_13 -> V_16 -> V_29 ;
char * V_52 = ( char * ) V_66 -> V_67 ;
int V_53 = V_66 -> V_68 ;
int V_47 = 0 ;
if ( ! V_30 -> V_69 || V_66 -> V_70 ) {
if ( V_66 -> V_70 == - V_71 )
goto V_72;
return;
}
if ( ! F_14 ( V_13 , V_30 ) )
goto V_72;
if ( V_53 == V_66 -> V_73 )
F_23 ( V_30 , V_52 , V_53 ) ;
else
F_21 ( V_30 , V_52 , V_53 ) ;
V_72:
V_47 = F_25 ( V_66 , V_74 ) ;
if ( V_47 )
log ( L_4 , V_47 ) ;
}
static int F_26 ( int V_75 , struct V_66 * V_66 ,
int * V_76 , int * V_77 , int * V_78 )
{
struct V_79 * V_80 = NULL ;
int V_47 = V_81 ;
for ( * V_76 = * V_77 = - 1 ; V_75 < V_66 -> V_82 ; V_75 ++ ) {
V_80 = & V_66 -> V_83 [ V_75 ] ;
if ( - V_84 == V_80 -> V_70 ) {
if ( ++ * V_78 > V_66 -> V_82 / 3 )
return V_85 ;
continue;
}
if ( V_80 -> V_70 || V_80 -> V_68 <= 0
|| V_80 -> V_68 > V_86 ) {
if ( * V_76 != - 1 )
break;
continue;
}
if ( V_80 -> V_68 == V_86 ) {
if ( * V_76 == - 1 )
* V_76 = V_75 ;
* V_77 = V_75 ;
continue;
}
if ( V_80 -> V_68 < V_86 ) {
if ( * V_76 == - 1 ) {
* V_76 = V_75 ;
* V_77 = V_75 ;
return V_87 ;
}
break;
}
}
if ( * V_76 == - 1 && * V_77 == - 1 )
V_47 = V_88 ;
return V_47 ;
}
static void F_27 ( struct V_66 * V_66 )
{
struct V_12 * V_13 = V_66 -> V_58 ;
struct V_29 * V_30 = & V_13 -> V_16 -> V_29 ;
int V_78 = 0 , V_76 = 0 , V_77 = 0 ;
char * V_52 = ( char * ) V_66 -> V_67 ;
int V_47 = 0 ;
if ( ! V_30 -> V_69 )
return;
do {
if ( ! F_14 ( V_13 , V_30 ) )
goto V_89;
switch ( F_26 ( V_76 , V_66 , & V_76 , & V_77 , & V_78 ) ) {
case V_81 :
F_23 ( V_30 , V_52 + ( V_76 * V_86 ) ,
( V_77 - V_76 + 1 ) * V_86 ) ;
break;
case V_87 :
F_21 ( V_30 , V_52 + ( V_76 * V_86 ) ,
V_86 ) ;
break;
case V_88 :
goto V_89;
case V_85 :
log ( L_5 ) ;
F_28 ( & V_30 -> V_90 ) ;
return;
}
} while ( V_76 = V_77 + 1 , V_76 < V_66 -> V_82 );
V_89:
V_47 = F_25 ( V_66 , V_74 ) ;
if ( V_47 )
log ( L_6 , V_47 ) ;
}
static int F_29 ( struct V_29 * V_30 )
{
struct V_91 * V_19 = V_30 -> V_16 -> V_19 ;
int V_2 ;
if ( V_30 -> V_92 [ 0 ] )
return 0 ;
for ( V_2 = 0 ; V_2 < V_93 ; V_2 ++ ) {
struct V_66 * V_66 ;
void * V_94 ;
int V_95 ;
V_66 = F_30 ( V_96 , V_97 ) ;
if ( V_66 == NULL )
goto V_89;
V_30 -> V_92 [ V_2 ] = V_66 ;
V_94 = F_31 ( V_19 ,
V_86 * V_96 ,
V_97 ,
& V_66 -> V_98 ) ;
V_66 -> V_99 = F_27 ;
V_66 -> V_100 = V_19 ;
V_66 -> V_58 = V_30 -> V_13 ;
V_66 -> V_101 = F_32 ( V_19 ,
V_30 -> V_102 ) ;
V_66 -> V_103 = 1 ;
V_66 -> V_104 = V_105 | V_106 ;
V_66 -> V_82 = V_96 ;
V_66 -> V_67 = V_94 ;
V_66 -> V_73 = V_96 * V_86 ;
for ( V_95 = 0 ; V_95 < V_96 ; V_95 ++ ) {
V_66 -> V_83 [ V_95 ] . V_56 = V_86 * V_95 ;
V_66 -> V_83 [ V_95 ] . V_107 = V_86 ;
}
}
return 0 ;
V_89:
for (; V_2 > 0 ; V_2 -- )
;
return - V_108 ;
}
int F_33 ( struct V_66 * * V_92 , int V_109 ,
struct V_91 * V_19 , T_3 V_110 ,
int V_111 , T_4 V_112 ,
T_5 V_113 , void * V_58 )
{
int V_2 = 0 ;
for (; V_2 < V_109 ; V_2 ++ ) {
void * V_94 ;
struct V_66 * V_66 = F_30 ( 0 , V_112 ) ;
if ( V_66 == NULL )
return V_2 ;
V_94 = F_31 ( V_19 , V_111 , V_112 ,
& V_66 -> V_98 ) ;
if ( V_94 == NULL ) {
F_34 ( V_66 ) ;
return V_2 ;
}
F_35 ( V_66 , V_19 , F_36 ( V_19 , V_110 ) ,
V_94 , V_111 , V_113 , V_58 ) ;
V_66 -> V_104 |= V_106 ;
V_92 [ V_2 ] = V_66 ;
}
return V_2 ;
}
void F_37 ( struct V_66 * * V_92 , int V_109 )
{
int V_2 ;
struct V_66 * V_66 ;
for ( V_2 = 0 ; V_2 < V_109 ; V_2 ++ ) {
V_66 = V_92 [ V_2 ] ;
if ( V_66 ) {
F_38 ( V_66 -> V_100 ,
V_66 -> V_73 ,
V_66 -> V_67 ,
V_66 -> V_98 ) ;
F_34 ( V_66 ) ;
V_92 [ V_2 ] = NULL ;
}
}
}
static int F_39 ( struct V_29 * V_30 )
{
if ( V_30 -> V_92 [ 0 ] )
return 0 ;
F_33 ( V_30 -> V_92 , V_93 ,
V_30 -> V_16 -> V_19 , V_30 -> V_102 ,
0x2000 , V_97 ,
F_24 , V_30 -> V_13 ) ;
return 0 ;
}
static void F_40 ( struct V_29 * V_30 )
{
F_37 ( V_30 -> V_92 , V_93 ) ;
}
static void F_41 ( struct V_114 * V_115 , struct V_41 * V_42 )
{
F_42 ( V_42 ) ;
V_42 -> V_48 = V_116 ;
}
static void F_43 ( struct V_114 * V_115 , struct V_41 * V_42 )
{
struct V_12 * V_13 = V_115 -> V_117 ;
V_42 -> V_48 = V_118 ;
F_44 ( & V_42 -> V_46 , & V_13 -> V_44 ) ;
}
static int F_45 ( struct V_114 * V_115 , struct V_41 * V_42 ,
enum V_119 V_120 )
{
struct V_12 * V_13 = V_115 -> V_117 ;
int V_121 ;
switch ( V_13 -> type ) {
case V_122 :
if ( V_116 == V_42 -> V_48 ) {
struct V_123 * V_59 ;
V_59 = & V_13 -> V_16 -> V_29 . V_58 . V_59 ;
V_42 -> V_124 = V_59 -> V_60 ;
V_42 -> V_125 = V_59 -> V_125 ;
V_42 -> V_126 = V_59 -> V_126 ;
V_121 = F_46 ( V_115 , V_42 , NULL ) ;
if ( V_121 < 0 )
return V_121 ;
}
break;
case V_127 :
if ( V_116 == V_42 -> V_48 ) {
V_42 -> V_124 = V_13 -> V_16 -> V_55 . V_61 ;
V_121 = F_46 ( V_115 , V_42 , NULL ) ;
if ( V_121 < 0 )
return V_121 ;
}
break;
default:
return - V_128 ;
}
V_42 -> V_120 = V_120 ;
V_42 -> V_48 = V_129 ;
return 0 ;
}
static int F_47 ( struct V_29 * V_30 )
{
int V_2 , V_47 ;
V_30 -> V_69 = 1 ;
for ( V_2 = 0 ; V_2 < V_93 ; V_2 ++ ) {
V_47 = F_25 ( V_30 -> V_92 [ V_2 ] , V_97 ) ;
if ( V_47 )
log ( L_7 , V_2 , V_47 ) ;
}
return V_47 ;
}
static int F_48 ( struct V_14 * V_16 )
{
struct V_29 * V_30 = & V_16 -> V_29 ;
T_6 V_130 ;
F_49 ( V_16 , V_131 , 0 , & V_130 ) ;
F_49 ( V_16 , V_132 , V_133 , & V_130 ) ;
if ( V_16 -> V_134 ) {
F_29 ( V_30 ) ;
F_50 ( & V_30 -> V_90 , V_135 ) ;
} else {
F_39 ( V_30 ) ;
}
F_47 ( V_30 ) ;
return 0 ;
}
static int F_51 ( struct V_114 * V_115 , unsigned int * V_53 ,
unsigned int * V_124 )
{
struct V_12 * V_13 = V_115 -> V_117 ;
struct V_14 * V_16 = V_13 -> V_16 ;
switch ( V_13 -> type ) {
default:
return - V_128 ;
case V_122 : {
struct V_29 * V_30 = & V_16 -> V_29 ;
struct V_123 * V_59 = & V_30 -> V_58 . V_59 ;
* V_124 = F_52 ( V_59 -> V_60 ) ;
if ( * V_53 < 4 )
* V_53 = 4 ;
if ( 1 ) {
V_30 -> V_102 = 0x82 ;
V_30 -> V_38 = & V_16 -> V_55 ;
V_30 -> V_38 -> V_30 = V_30 ;
V_30 -> V_16 = V_16 ;
V_30 -> V_136 = V_59 -> V_126 / 2 ;
V_30 -> V_37 = V_59 -> V_125 * 2 ;
V_30 -> V_13 = V_13 ;
}
return F_48 ( V_16 ) ;
}
case V_127 : {
struct V_55 * V_38 = & V_16 -> V_55 ;
* V_124 = F_52 ( V_38 -> V_61 ) ;
log ( L_8 , * V_124 ) ;
if ( * V_53 == 0 )
* V_53 = 4 ;
}
break;
}
return 0 ;
}
static int F_53 ( struct V_8 * V_8 , void * V_9 ,
struct V_137 * V_138 )
{
if ( F_54 ( V_139 ) <= V_138 -> V_31 )
return - V_128 ;
V_138 -> type = V_122 ;
V_138 -> V_140 = 0 ;
V_138 -> V_141 = V_139 [ V_138 -> V_31 ] . V_142 ;
strcpy ( V_138 -> V_143 , V_139 [ V_138 -> V_31 ] . V_144 ) ;
return 0 ;
}
static int F_55 ( struct V_8 * V_8 , void * V_9 , struct V_145 * V_138 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
F_3 ( V_13 ) ;
V_138 -> V_146 . V_59 = V_16 -> V_29 . V_58 . V_59 ;
return 0 ;
}
static int F_56 ( struct V_8 * V_8 , void * V_9 ,
struct V_145 * V_138 )
{
return 0 ;
}
static int F_57 ( struct V_14 * V_16 , struct V_123 * V_59 )
{
struct V_29 * V_30 = & V_16 -> V_29 ;
struct V_147 * V_58 = & V_30 -> V_58 ;
struct V_123 * V_148 = & V_58 -> V_59 ;
T_6 V_47 = 0 , V_130 = 0 , V_149 ;
if ( V_59 -> V_141 == V_150 ) {
V_149 = V_151 ;
} else {
V_59 -> V_141 = V_152 ;
V_149 = V_153 ;
}
V_47 = F_49 ( V_16 , V_154 ,
V_149 , & V_130 ) ;
V_149 = V_155 ;
switch ( V_59 -> V_125 ) {
case 704 :
V_149 = V_156 ;
break;
default:
V_59 -> V_125 = 720 ;
case 720 :
break;
}
V_47 |= F_49 ( V_16 , V_157 ,
V_149 , & V_130 ) ;
if ( V_47 || V_130 )
return - V_158 ;
V_148 -> V_141 = V_59 -> V_141 ;
V_59 -> V_126 = ( V_58 -> V_159 & V_160 ) ? 480 : 576 ;
if ( ( V_148 -> V_125 != V_59 -> V_125 )
|| ( V_148 -> V_126 != V_59 -> V_126 ) ) {
V_148 -> V_125 = V_59 -> V_125 ;
V_148 -> V_126 = V_59 -> V_126 ;
V_148 -> V_161 = V_59 -> V_125 * 2 ;
V_148 -> V_60 = V_59 -> V_125 * V_59 -> V_126 * 2 ;
}
* V_59 = * V_148 ;
return 0 ;
}
static int F_58 ( struct V_8 * V_8 , void * V_9 , struct V_145 * V_138 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
F_3 ( V_13 ) ;
if ( V_122 != V_138 -> type )
return - V_128 ;
F_59 ( & V_16 -> V_162 ) ;
if ( V_16 -> V_163 == NULL )
V_16 -> V_163 = V_8 ;
else if ( V_8 != V_16 -> V_163 ) {
F_60 ( & V_16 -> V_162 ) ;
return - V_128 ;
}
F_57 ( V_16 , & V_138 -> V_146 . V_59 ) ;
F_60 ( & V_16 -> V_162 ) ;
return 0 ;
}
static int F_61 ( struct V_8 * V_8 , void * V_9 ,
struct V_145 * V_164 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
struct V_165 * V_166 = & V_164 -> V_146 . V_38 ;
V_166 -> V_167 = 720 * 2 ;
V_166 -> V_168 = 6750000 * 4 ;
V_166 -> V_169 = V_170 ;
V_166 -> V_56 = 64 * 4 ;
if ( V_16 -> V_29 . V_58 . V_159 & V_160 ) {
V_166 -> V_75 [ 0 ] = 10 ;
V_166 -> V_75 [ 1 ] = 264 ;
V_166 -> V_53 [ 0 ] = V_171 ;
V_166 -> V_53 [ 1 ] = V_171 ;
} else {
V_166 -> V_75 [ 0 ] = 6 ;
V_166 -> V_75 [ 1 ] = 314 ;
V_166 -> V_53 [ 0 ] = V_172 ;
V_166 -> V_53 [ 1 ] = V_172 ;
}
V_166 -> V_140 = V_173 ;
F_3 ( V_13 ) ;
return 0 ;
}
static int F_62 ( struct V_14 * V_16 , T_1 * V_174 )
{
struct V_29 * V_30 = & V_16 -> V_29 ;
struct V_55 * V_38 = & V_16 -> V_55 ;
struct V_147 * V_58 ;
struct V_123 * V_59 ;
T_6 V_2 , V_47 = 0 , V_130 , V_175 ;
int V_126 ;
for ( V_2 = 0 ; V_2 < V_176 ; V_2 ++ ) {
if ( * V_174 & V_177 [ V_2 ] . V_178 ) {
V_175 = V_177 [ V_2 ] . V_179 ;
log ( L_9 , V_177 [ V_2 ] . V_144 ) ;
goto V_180;
}
}
return - V_128 ;
V_180:
F_59 ( & V_16 -> V_162 ) ;
V_47 = F_49 ( V_16 , V_181 , V_175 , & V_130 ) ;
if ( V_47 || V_130 )
goto V_89;
V_58 = & V_30 -> V_58 ;
V_58 -> V_159 = V_177 [ V_2 ] . V_178 ;
if ( V_58 -> V_159 & V_160 ) {
V_38 -> V_61 = V_182 ;
V_126 = 480 ;
} else {
V_38 -> V_61 = V_183 ;
V_126 = 576 ;
}
V_59 = & V_58 -> V_59 ;
if ( V_59 -> V_126 != V_126 ) {
V_59 -> V_126 = V_126 ;
V_59 -> V_60 = V_59 -> V_125 * V_59 -> V_126 * 2 ;
}
V_89:
F_60 ( & V_16 -> V_162 ) ;
return V_47 ;
}
static int F_63 ( struct V_8 * V_8 , void * V_9 , T_1 * V_174 )
{
struct V_12 * V_13 = V_9 ;
F_3 ( V_13 ) ;
return F_62 ( V_13 -> V_16 , V_174 ) ;
}
static int F_64 ( struct V_8 * V_8 , void * V_9 , struct V_184 * V_185 )
{
struct V_12 * V_13 = V_9 ;
if ( V_185 -> V_31 < 0 || V_185 -> V_31 >= V_186 )
return - V_128 ;
strcpy ( V_185 -> V_144 , V_187 [ V_185 -> V_31 ] . V_144 ) ;
V_185 -> type = V_188 ;
V_185 -> V_189 = 0 ;
V_185 -> V_190 = 0 ;
V_185 -> V_191 = V_192 ;
V_185 -> V_70 = 0 ;
F_3 ( V_13 ) ;
return 0 ;
}
static int F_65 ( struct V_8 * V_8 , void * V_9 , unsigned int * V_2 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
struct V_147 * V_58 = & V_16 -> V_29 . V_58 ;
F_3 ( V_13 ) ;
* V_2 = V_58 -> V_193 ;
return 0 ;
}
static int F_66 ( struct V_8 * V_8 , void * V_9 , unsigned int V_2 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
T_6 V_47 , V_130 ;
if ( V_2 < 0 || V_2 >= V_186 )
return - V_128 ;
V_47 = F_49 ( V_16 , V_194 ,
V_187 [ V_2 ] . V_195 , & V_130 ) ;
if ( V_47 )
return V_47 ;
V_16 -> V_29 . V_58 . V_193 = V_2 ;
return 0 ;
}
static struct V_196 * F_67 ( T_7 V_197 )
{
struct V_196 * V_198 = & V_199 [ 0 ] ;
int V_200 = F_54 ( V_199 ) ;
for (; V_198 < & V_199 [ V_200 ] ; V_198 ++ )
if ( V_198 -> V_201 . V_197 == V_197 )
return V_198 ;
return NULL ;
}
static int F_68 ( struct V_8 * V_8 , void * V_9 ,
struct V_202 * V_203 )
{
struct V_196 * V_198 = NULL ;
V_198 = F_67 ( V_203 -> V_197 ) ;
if ( ! V_198 )
return - V_128 ;
* V_203 = V_198 -> V_201 ;
return 0 ;
}
static int F_69 ( struct V_8 * V_8 , void * V_9 , struct V_204 * V_205 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
struct V_196 * V_198 = NULL ;
struct V_206 V_207 ;
T_6 V_47 = 0 , V_130 ;
V_198 = F_67 ( V_205 -> V_197 ) ;
if ( ! V_198 )
return - V_128 ;
F_59 ( & V_16 -> V_162 ) ;
V_47 = F_70 ( V_16 , V_208 , V_198 -> V_209 ,
& V_207 , & V_130 , sizeof( V_207 ) ) ;
F_60 ( & V_16 -> V_162 ) ;
if ( V_47 || V_130 )
return - 1 ;
V_205 -> V_210 = V_207 . V_211 ;
return 0 ;
}
static int F_71 ( struct V_8 * V_8 , void * V_9 , struct V_204 * V_203 )
{
struct V_206 V_175 = { 0 } ;
struct V_196 * V_198 = NULL ;
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
T_6 V_47 = 0 , V_130 , V_212 ;
V_198 = F_67 ( V_203 -> V_197 ) ;
if ( ! V_198 )
return - V_128 ;
V_175 . V_211 = V_203 -> V_210 ;
V_175 . V_213 = V_198 -> V_209 ;
V_212 = * ( T_6 * ) & V_175 ;
F_59 ( & V_16 -> V_162 ) ;
V_47 = F_49 ( V_16 , V_208 , V_212 , & V_130 ) ;
V_47 = F_49 ( V_16 , V_131 , 0 , & V_130 ) ;
F_60 ( & V_16 -> V_162 ) ;
F_72 ( V_214 ) ;
F_73 ( V_215 / 4 ) ;
return V_47 ;
}
static int F_74 ( struct V_8 * V_8 , void * V_9 , struct V_216 * V_203 )
{
if ( 0 != V_203 -> V_31 )
return - V_128 ;
V_203 -> V_217 = V_218 ;
strcpy ( V_203 -> V_144 , L_10 ) ;
V_203 -> V_219 = 0 ;
return 0 ;
}
static int F_75 ( struct V_8 * V_8 , void * V_9 , struct V_216 * V_203 )
{
V_203 -> V_31 = 0 ;
V_203 -> V_217 = V_218 ;
strcpy ( V_203 -> V_144 , L_10 ) ;
V_203 -> V_219 = 0 ;
return 0 ;
}
static int F_76 ( struct V_8 * V_8 , void * V_9 , struct V_216 * V_203 )
{
return ( 0 == V_203 -> V_31 ) ? 0 : - V_128 ;
}
static int F_77 ( struct V_8 * V_8 , void * V_9 , struct V_220 * V_190 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
struct V_221 V_222 ;
T_6 V_53 = 5 , V_47 , V_130 ;
int V_31 ;
if ( 0 != V_190 -> V_31 )
return - V_128 ;
F_59 ( & V_16 -> V_162 ) ;
V_47 = F_70 ( V_16 , V_223 , V_224 ,
& V_222 , & V_130 , sizeof( V_222 ) ) ;
while ( V_222 . V_225 && V_53 -- && ! V_47 ) {
F_72 ( V_214 ) ;
F_73 ( V_215 ) ;
V_47 = F_70 ( V_16 , V_223 , V_224 ,
& V_222 , & V_130 , sizeof( V_222 ) ) ;
}
F_60 ( & V_16 -> V_162 ) ;
if ( V_226 )
log ( L_11 , V_222 . V_227 , V_222 . V_228 ) ;
if ( V_47 || V_130 )
V_190 -> signal = 0 ;
else if ( V_222 . V_227 && ! V_222 . V_228 )
V_190 -> signal = 0xFFFF ;
else
V_190 -> signal = ( V_222 . V_228 * 255 / 10 ) << 8 ;
strcpy ( V_190 -> V_144 , L_12 ) ;
V_190 -> type = V_229 ;
V_190 -> V_230 = V_231 / 62500 ;
V_190 -> V_232 = V_233 / 62500 ;
V_190 -> V_217 = V_234 | V_235 |
V_236 | V_237 ;
V_31 = V_16 -> V_29 . V_58 . V_238 ;
V_190 -> V_239 = V_240 [ V_31 ] . V_241 ;
V_190 -> V_242 = V_240 [ V_31 ] . V_243 ;
V_190 -> V_244 = 0 ;
F_3 ( V_13 ) ;
return 0 ;
}
static int F_78 ( struct V_14 * V_16 , int V_31 )
{
T_6 V_47 = 0 , V_130 , V_175 , V_245 ;
F_59 ( & V_16 -> V_162 ) ;
V_175 = V_240 [ V_31 ] . V_246 ;
V_47 = F_49 ( V_16 , V_247 , V_175 , & V_130 ) ;
V_245 = F_1 ( V_16 -> V_29 . V_58 . V_159 ) ;
V_47 |= F_49 ( V_16 , V_248 , V_245 ,
& V_130 ) ;
if ( ! V_47 )
V_16 -> V_29 . V_58 . V_238 = V_31 ;
F_60 ( & V_16 -> V_162 ) ;
return V_47 ;
}
static int F_79 ( struct V_8 * V_8 , void * V_9 , struct V_220 * V_203 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
int V_31 ;
if ( 0 != V_203 -> V_31 )
return - V_128 ;
F_3 ( V_13 ) ;
for ( V_31 = 0 ; V_31 < V_249 ; V_31 ++ )
if ( V_203 -> V_242 == V_240 [ V_31 ] . V_243 )
return F_78 ( V_16 , V_31 ) ;
return - V_128 ;
}
static int F_80 ( struct V_8 * V_8 , void * V_9 ,
struct V_250 * V_251 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
struct V_147 * V_58 = & V_16 -> V_29 . V_58 ;
if ( 0 != V_251 -> V_190 )
return - V_128 ;
V_251 -> V_252 = V_58 -> V_251 ;
V_251 -> type = V_229 ;
return 0 ;
}
static int F_81 ( struct V_14 * V_16 , T_7 V_252 )
{
T_6 V_47 = 0 , V_175 , V_130 ;
struct V_147 * V_58 = & V_16 -> V_29 . V_58 ;
V_175 = V_252 * 62500 / 1000 ;
if ( V_175 < V_231 / 1000 || V_175 > V_233 / 1000 )
return - V_128 ;
F_59 ( & V_16 -> V_162 ) ;
V_47 = F_49 ( V_16 , V_253 , V_175 , & V_130 ) ;
V_47 = F_49 ( V_16 , V_131 , 0 , & V_130 ) ;
F_82 ( 250 ) ;
V_58 -> V_251 = V_252 ;
F_60 ( & V_16 -> V_162 ) ;
return V_47 ;
}
static int F_83 ( struct V_8 * V_8 , void * V_9 ,
struct V_250 * V_251 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
F_3 ( V_13 ) ;
#ifdef F_84
V_16 -> V_254 = V_255 ;
V_16 -> V_256 = V_257 ;
#endif
return F_81 ( V_16 , V_251 -> V_252 ) ;
}
static int F_85 ( struct V_8 * V_8 , void * V_9 ,
struct V_258 * V_259 )
{
struct V_12 * V_13 = V_8 -> V_260 ;
F_3 ( V_13 ) ;
return F_86 ( & V_13 -> V_115 , V_259 ) ;
}
static int F_87 ( struct V_8 * V_8 , void * V_9 , struct V_261 * V_259 )
{
struct V_12 * V_13 = V_8 -> V_260 ;
F_3 ( V_13 ) ;
return F_88 ( & V_13 -> V_115 , V_259 ) ;
}
static int F_89 ( struct V_8 * V_8 , void * V_9 , struct V_261 * V_259 )
{
struct V_12 * V_13 = V_8 -> V_260 ;
return F_90 ( & V_13 -> V_115 , V_259 ) ;
}
static int F_91 ( struct V_8 * V_8 , void * V_9 , struct V_261 * V_259 )
{
struct V_12 * V_13 = V_8 -> V_260 ;
return F_92 ( & V_13 -> V_115 , V_259 , V_8 -> V_262 & V_263 ) ;
}
static int F_93 ( struct V_29 * V_30 )
{
if ( V_30 -> V_69 ) {
int V_2 ;
T_6 V_130 ;
struct V_14 * V_16 = V_30 -> V_16 ;
V_30 -> V_69 = 0 ;
for ( V_2 = 0 ; V_2 < V_93 ; ++ V_2 ) {
if ( V_30 -> V_92 [ V_2 ] )
F_94 ( V_30 -> V_92 [ V_2 ] ) ;
}
F_49 ( V_16 , V_132 , V_264 ,
& V_130 ) ;
}
return 0 ;
}
int F_95 ( struct V_14 * V_16 )
{
struct V_29 * V_30 = & V_16 -> V_29 ;
struct V_55 * V_38 = & V_16 -> V_55 ;
F_59 ( & V_16 -> V_162 ) ;
if ( V_30 -> V_69 ) {
struct V_12 * V_13 = V_30 -> V_13 ;
F_93 ( V_30 ) ;
F_40 ( V_30 ) ;
F_96 ( & V_13 -> V_115 ) ;
F_97 ( & V_13 -> V_115 ) ;
V_13 = V_38 -> V_13 ;
if ( V_13 ) {
F_96 ( & V_13 -> V_115 ) ;
F_97 ( & V_13 -> V_115 ) ;
}
}
F_60 ( & V_16 -> V_162 ) ;
return 0 ;
}
static void V_135 ( struct V_265 * V_266 )
{
struct V_29 * V_30 ;
struct V_14 * V_16 ;
V_30 = F_98 ( V_266 , struct V_29 , V_90 ) ;
V_16 = V_30 -> V_16 ;
F_59 ( & V_16 -> V_162 ) ;
F_93 ( V_30 ) ;
F_82 ( 500 ) ;
F_48 ( V_16 ) ;
F_60 ( & V_16 -> V_162 ) ;
}
static int F_99 ( struct V_8 * V_8 , void * V_9 ,
enum V_267 type )
{
struct V_12 * V_13 = V_9 ;
F_3 ( V_13 ) ;
if ( F_100 ( type != V_13 -> type ) )
return - V_128 ;
return F_101 ( & V_13 -> V_115 ) ;
}
static int F_102 ( struct V_8 * V_8 , void * V_9 ,
enum V_267 type )
{
struct V_12 * V_13 = V_8 -> V_260 ;
F_3 ( V_13 ) ;
if ( F_100 ( type != V_13 -> type ) )
return - V_128 ;
return F_103 ( & V_13 -> V_115 ) ;
}
static int F_104 ( struct V_14 * V_16 )
{
T_6 V_47 = 0 , V_130 , V_245 ;
F_72 ( V_214 ) ;
F_73 ( V_215 / 2 ) ;
V_47 = F_105 ( V_16 -> V_19 , 0 ,
( V_16 -> V_134 ?
V_268 :
V_269 ) ) ;
if ( V_47 < 0 )
goto error;
V_47 = F_106 ( V_16 , V_224 ) ;
V_47 |= F_49 ( V_16 , V_194 ,
V_270 , & V_130 ) ;
V_47 |= F_49 ( V_16 , V_181 ,
V_271 , & V_130 ) ;
V_47 |= F_49 ( V_16 , V_154 ,
V_153 , & V_130 ) ;
V_47 |= F_49 ( V_16 , V_157 ,
V_155 , & V_130 ) ;
V_47 |= F_49 ( V_16 , V_253 , V_231 , & V_130 ) ;
V_47 |= F_49 ( V_16 , V_272 , 1 , & V_130 ) ;
V_245 = F_1 ( V_16 -> V_29 . V_58 . V_159 ) ;
V_47 |= F_49 ( V_16 , V_248 , V_245 , & V_130 ) ;
V_47 |= F_49 ( V_16 , V_247 ,
V_273 , & V_130 ) ;
V_47 |= F_49 ( V_16 , V_274 ,
V_275 , & V_130 ) ;
error:
return V_47 ;
}
static int V_255 ( struct V_14 * V_16 )
{
F_107 ( V_16 ) ;
F_93 ( & V_16 -> V_29 ) ;
F_40 ( & V_16 -> V_29 ) ;
F_105 ( V_16 -> V_19 , 0 , 0 ) ;
F_82 ( 300 ) ;
return 0 ;
}
static int F_108 ( struct V_14 * V_16 ,
struct V_147 * V_58 )
{
struct V_12 * V_13 = V_16 -> V_29 . V_13 ;
F_104 ( V_16 ) ;
F_62 ( V_16 , & V_58 -> V_159 ) ;
F_66 ( NULL , V_13 , V_58 -> V_193 ) ;
F_78 ( V_16 , V_58 -> V_238 ) ;
F_57 ( V_16 , & V_58 -> V_59 ) ;
F_81 ( V_16 , V_58 -> V_251 ) ;
return 0 ;
}
static int V_257 ( struct V_14 * V_16 )
{
struct V_29 * V_30 = & V_16 -> V_29 ;
F_108 ( V_16 , & V_30 -> V_58 ) ;
if ( V_30 -> V_13 -> V_36 )
F_6 ( V_30 , 0 ) ;
F_48 ( V_16 ) ;
F_109 ( V_16 ) ;
return 0 ;
}
void F_110 ( struct V_276 * V_277 , int V_226 )
{
V_277 -> V_278 = 0 ;
if ( V_226 & 0x1 )
V_277 -> V_278 = V_279 ;
if ( V_226 & 0x2 )
V_277 -> V_278 = V_279 | V_280 ;
}
static void F_111 ( struct V_147 * V_58 )
{
V_58 -> V_193 = 0 ;
V_58 -> V_238 = 1 ;
V_58 -> V_159 = V_281 ;
V_58 -> V_59 = (struct V_123 ) {
. V_125 = 720 ,
. V_126 = 576 ,
. V_141 = V_152 ,
. V_120 = V_282 ,
. V_161 = 720 * 2 ,
. V_60 = 720 * 576 * 2 ,
. V_283 = V_284 ,
. V_285 = 0
} ;
}
static int F_112 ( struct V_8 * V_8 )
{
struct V_276 * V_277 = F_113 ( V_8 ) ;
struct V_14 * V_16 = F_114 ( V_277 ) ;
struct V_12 * V_13 = NULL ;
int V_47 = - V_108 ;
F_59 ( & V_16 -> V_162 ) ;
F_115 ( V_16 -> V_286 ) ;
if ( V_277 -> V_287 == V_288
&& ! ( V_16 -> V_48 & V_289 ) ) {
V_13 = F_116 ( sizeof( struct V_12 ) , V_97 ) ;
if ( ! V_13 )
goto V_89;
V_16 -> V_134 = V_290 ;
F_111 ( & V_16 -> V_29 . V_58 ) ;
V_47 = F_104 ( V_16 ) ;
if ( V_47 < 0 ) {
F_117 ( V_13 ) ;
V_47 = - 1 ;
goto V_89;
}
V_16 -> V_48 |= V_289 ;
V_13 -> type = V_122 ;
V_16 -> V_29 . V_291 ++ ;
F_110 ( V_277 , V_226 ) ;
F_118 ( & V_13 -> V_115 , & V_292 ,
NULL , & V_13 -> V_43 ,
V_122 ,
V_282 ,
sizeof( struct V_41 ) ,
V_13 , NULL ) ;
} else if ( V_277 -> V_287 == V_293
&& ! ( V_16 -> V_48 & V_294 ) ) {
V_13 = F_116 ( sizeof( struct V_12 ) , V_97 ) ;
if ( ! V_13 )
goto V_89;
V_16 -> V_48 |= V_294 ;
V_13 -> type = V_127 ;
V_16 -> V_55 . V_13 = V_13 ;
V_16 -> V_55 . V_291 ++ ;
F_118 ( & V_13 -> V_115 , & V_292 ,
NULL , & V_13 -> V_43 ,
V_127 ,
V_295 ,
sizeof( struct V_41 ) ,
V_13 , NULL ) ;
} else {
log ( L_13 ) ;
V_47 = - V_128 ;
goto V_89;
}
V_13 -> V_16 = V_16 ;
V_13 -> V_36 = NULL ;
F_119 ( & V_13 -> V_44 ) ;
F_120 ( & V_13 -> V_43 ) ;
V_8 -> V_260 = V_13 ;
F_121 ( & V_16 -> V_296 ) ;
F_60 ( & V_16 -> V_162 ) ;
return 0 ;
V_89:
F_122 ( V_16 -> V_286 ) ;
F_60 ( & V_16 -> V_162 ) ;
return V_47 ;
}
static int F_123 ( struct V_8 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_260 ;
struct V_14 * V_16 = V_13 -> V_16 ;
T_6 V_130 = 0 ;
F_3 ( V_13 ) ;
F_59 ( & V_16 -> V_162 ) ;
if ( V_13 -> type == V_122 ) {
V_16 -> V_48 &= ~ V_289 ;
F_93 ( & V_16 -> V_29 ) ;
F_40 ( & V_16 -> V_29 ) ;
F_49 ( V_16 , V_132 , V_264 ,
& V_130 ) ;
V_16 -> V_163 = NULL ;
V_16 -> V_29 . V_291 -- ;
} else if ( V_13 -> type == V_127 ) {
V_16 -> V_48 &= ~ V_294 ;
V_16 -> V_55 . V_13 = NULL ;
V_16 -> V_55 . V_291 -- ;
}
F_96 ( & V_13 -> V_115 ) ;
F_97 ( & V_13 -> V_115 ) ;
F_122 ( V_16 -> V_286 ) ;
F_60 ( & V_16 -> V_162 ) ;
F_117 ( V_13 ) ;
V_8 -> V_260 = NULL ;
F_124 ( & V_16 -> V_296 , V_297 ) ;
return 0 ;
}
static int F_125 ( struct V_8 * V_8 , struct V_298 * V_299 )
{
struct V_12 * V_13 = V_8 -> V_260 ;
return F_126 ( & V_13 -> V_115 , V_299 ) ;
}
static unsigned int F_127 ( struct V_8 * V_8 , T_8 * V_300 )
{
struct V_12 * V_13 = V_8 -> V_260 ;
return F_128 ( V_8 , & V_13 -> V_115 , V_300 ) ;
}
static T_9 F_129 ( struct V_8 * V_8 , char T_10 * V_301 ,
T_11 V_53 , T_12 * V_302 )
{
struct V_12 * V_13 = V_8 -> V_260 ;
return F_130 ( & V_13 -> V_115 , V_301 , V_53 , V_302 ,
0 , V_8 -> V_262 & V_263 ) ;
}
struct V_276 * F_131 ( struct V_14 * V_16 , struct V_276 * V_303 )
{
struct V_276 * V_277 ;
V_277 = F_132 () ;
if ( V_277 == NULL )
return NULL ;
* V_277 = * V_303 ;
V_277 -> V_304 = - 1 ;
V_277 -> V_305 = & V_16 -> V_305 ;
V_277 -> V_306 = V_307 ;
F_133 ( V_277 , V_16 ) ;
return V_277 ;
}
void F_134 ( struct V_276 * * V_308 )
{
struct V_276 * V_100 = * V_308 ;
if ( V_100 == NULL )
return;
if ( F_135 ( V_100 ) )
F_136 ( V_100 ) ;
else
V_307 ( V_100 ) ;
* V_308 = NULL ;
}
void F_137 ( struct V_14 * V_16 )
{
struct V_29 * V_30 = & V_16 -> V_29 ;
struct V_55 * V_38 = & V_16 -> V_55 ;
F_134 ( & V_30 -> V_308 ) ;
F_134 ( & V_38 -> V_308 ) ;
log () ;
}
int F_138 ( struct V_14 * V_16 )
{
struct V_29 * V_30 = & V_16 -> V_29 ;
struct V_55 * V_38 = & V_16 -> V_55 ;
int V_47 = - V_108 ;
V_30 -> V_308 = F_131 ( V_16 , & V_309 ) ;
if ( V_30 -> V_308 == NULL )
goto V_89;
V_47 = F_139 ( V_30 -> V_308 , V_288 , - 1 ) ;
if ( V_47 != 0 )
goto V_89;
V_38 -> V_308 = F_131 ( V_16 , & V_309 ) ;
if ( V_38 -> V_308 == NULL ) {
V_47 = - V_108 ;
goto V_89;
}
V_47 = F_139 ( V_38 -> V_308 , V_293 , - 1 ) ;
if ( V_47 != 0 )
goto V_89;
log ( L_14 ) ;
return 0 ;
V_89:
log ( L_15 , V_47 ) ;
F_137 ( V_16 ) ;
return V_47 ;
}
