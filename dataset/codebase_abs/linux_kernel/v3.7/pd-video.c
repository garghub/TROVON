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
V_11 -> V_21 = V_22 | V_23 |
V_24 | V_25 |
V_26 | V_27 ;
return 0 ;
}
static void F_5 ( struct V_28 * V_29 , bool V_30 )
{
struct V_12 * V_13 = V_29 -> V_13 ;
V_29 -> V_31 = V_30 ;
V_29 -> V_32 = 0 ;
V_29 -> V_33 = 0 ;
V_29 -> V_34 = ( char * ) F_6 ( V_13 -> V_35 )
+ V_30 * V_29 -> V_36 ;
V_29 -> V_37 -> V_38 = 0 ;
}
static bool F_7 ( struct V_12 * V_13 , int * V_39 )
{
struct V_40 * V_41 = V_13 -> V_35 ;
if ( V_41 )
return true ;
F_8 ( & V_13 -> V_42 ) ;
if ( ! F_9 ( & V_13 -> V_43 ) ) {
V_41 = F_10 ( V_13 -> V_43 . V_44 ,
struct V_40 , V_45 ) ;
if ( V_39 )
* V_39 = 1 ;
V_13 -> V_35 = V_41 ;
F_11 ( & V_41 -> V_45 ) ;
}
F_12 ( & V_13 -> V_42 ) ;
return ! ! V_41 ;
}
static bool F_13 ( struct V_12 * V_13 , struct V_28 * V_29 )
{
int V_39 = 0 ;
bool V_46 = true ;
V_46 = F_7 ( V_13 , & V_39 ) ;
if ( V_46 && V_39 )
F_5 ( V_29 , 0 ) ;
return V_46 ;
}
static void F_14 ( struct V_12 * V_13 )
{
struct V_40 * V_41 = V_13 -> V_35 ;
if ( V_41 == NULL )
return;
V_13 -> V_35 = NULL ;
V_41 -> V_47 = V_48 ;
V_41 -> V_31 ++ ;
F_15 ( & V_41 -> V_49 ) ;
F_16 ( & V_41 -> V_50 ) ;
}
static void F_17 ( struct V_28 * V_29 )
{
if ( 1 == V_29 -> V_31 )
F_14 ( V_29 -> V_13 ) ;
else
F_5 ( V_29 , 1 ) ;
}
static void F_18 ( struct V_28 * V_29 , char * V_51 ,
unsigned int V_52 )
{
#define F_19 ( T_2 ) \
do { \
if (++video->lines_copied > video->lines_per_field) \
goto overflow; \
memcpy(video->dst, src, len);\
video->dst += len + video->lines_size; \
src += len; \
count -= len; \
} while (0)
while ( V_52 && V_52 >= V_29 -> V_36 ) {
if ( V_29 -> V_33 ) {
F_19 ( V_29 -> V_33 ) ;
V_29 -> V_33 = 0 ;
continue;
}
F_19 ( V_29 -> V_36 ) ;
}
if ( V_52 && V_52 < V_29 -> V_36 ) {
memcpy ( V_29 -> V_34 , V_51 , V_52 ) ;
V_29 -> V_33 = V_29 -> V_36 - V_52 ;
V_29 -> V_34 += V_52 ;
}
return;
V_53:
F_17 ( V_29 ) ;
}
static void F_20 ( struct V_28 * V_29 , char * V_51 , int V_52 )
{
struct V_54 * V_37 = V_29 -> V_37 ;
int V_55 ;
char * V_56 ;
V_55 = ( V_29 -> V_57 . V_58 . V_59 / 2 + V_37 -> V_60 / 2 )
- ( V_37 -> V_38 + V_29 -> V_36 * V_29 -> V_32 ) ;
if ( V_29 -> V_33 )
V_55 -= ( V_29 -> V_36 - V_29 -> V_33 ) ;
if ( V_55 > V_52 || V_55 <= 0 )
goto V_61;
V_56 = V_51 + V_55 ;
if ( ! strncmp ( V_56 , L_3 , 4 ) ) {
int V_62 = * ( ( V_63 * ) ( V_56 + 12 ) ) ;
if ( ( V_62 & 1 ) ^ V_29 -> V_31 ) {
F_5 ( V_29 , V_29 -> V_31 ) ;
return;
}
F_18 ( V_29 , V_51 , V_55 ) ;
}
V_61:
F_17 ( V_29 ) ;
}
static inline void F_21 ( struct V_54 * V_37 ,
char * V_51 , unsigned int V_52 )
{
struct V_12 * V_13 = V_37 -> V_13 ;
if ( V_13 && F_7 ( V_13 , NULL ) ) {
char * V_56 = F_6 ( V_13 -> V_35 ) ;
if ( V_37 -> V_29 -> V_31 )
V_56 += ( V_37 -> V_60 / 2 ) ;
memcpy ( V_56 + V_37 -> V_38 , V_51 , V_52 ) ;
}
V_37 -> V_38 += V_52 ;
}
static inline void F_22 ( struct V_28 * V_29 ,
char * V_51 , unsigned int V_52 )
{
struct V_54 * V_37 = V_29 -> V_37 ;
unsigned int V_64 = ( V_37 -> V_60 / 2 ) - V_37 -> V_38 ;
if ( V_64 >= V_52 ) {
F_21 ( V_37 , V_51 , V_52 ) ;
} else {
if ( V_64 ) {
F_21 ( V_37 , V_51 , V_64 ) ;
if ( V_37 -> V_13 && V_29 -> V_31 )
F_14 ( V_37 -> V_13 ) ;
}
F_18 ( V_29 , V_51 + V_64 , V_52 - V_64 ) ;
}
}
static void F_23 ( struct V_65 * V_65 )
{
struct V_12 * V_13 = V_65 -> V_57 ;
struct V_28 * V_29 = & V_13 -> V_16 -> V_28 ;
char * V_51 = ( char * ) V_65 -> V_66 ;
int V_52 = V_65 -> V_67 ;
int V_46 = 0 ;
if ( ! V_29 -> V_68 || V_65 -> V_69 ) {
if ( V_65 -> V_69 == - V_70 )
goto V_71;
return;
}
if ( ! F_13 ( V_13 , V_29 ) )
goto V_71;
if ( V_52 == V_65 -> V_72 )
F_22 ( V_29 , V_51 , V_52 ) ;
else
F_20 ( V_29 , V_51 , V_52 ) ;
V_71:
V_46 = F_24 ( V_65 , V_73 ) ;
if ( V_46 )
log ( L_4 , V_46 ) ;
}
static int F_25 ( int V_74 , struct V_65 * V_65 ,
int * V_75 , int * V_76 , int * V_77 )
{
struct V_78 * V_79 = NULL ;
int V_46 = V_80 ;
for ( * V_75 = * V_76 = - 1 ; V_74 < V_65 -> V_81 ; V_74 ++ ) {
V_79 = & V_65 -> V_82 [ V_74 ] ;
if ( - V_83 == V_79 -> V_69 ) {
if ( ++ * V_77 > V_65 -> V_81 / 3 )
return V_84 ;
continue;
}
if ( V_79 -> V_69 || V_79 -> V_67 <= 0
|| V_79 -> V_67 > V_85 ) {
if ( * V_75 != - 1 )
break;
continue;
}
if ( V_79 -> V_67 == V_85 ) {
if ( * V_75 == - 1 )
* V_75 = V_74 ;
* V_76 = V_74 ;
continue;
}
if ( V_79 -> V_67 < V_85 ) {
if ( * V_75 == - 1 ) {
* V_75 = V_74 ;
* V_76 = V_74 ;
return V_86 ;
}
break;
}
}
if ( * V_75 == - 1 && * V_76 == - 1 )
V_46 = V_87 ;
return V_46 ;
}
static void F_26 ( struct V_65 * V_65 )
{
struct V_12 * V_13 = V_65 -> V_57 ;
struct V_28 * V_29 = & V_13 -> V_16 -> V_28 ;
int V_77 = 0 , V_75 = 0 , V_76 = 0 ;
char * V_51 = ( char * ) V_65 -> V_66 ;
int V_46 = 0 ;
if ( ! V_29 -> V_68 )
return;
do {
if ( ! F_13 ( V_13 , V_29 ) )
goto V_88;
switch ( F_25 ( V_75 , V_65 , & V_75 , & V_76 , & V_77 ) ) {
case V_80 :
F_22 ( V_29 , V_51 + ( V_75 * V_85 ) ,
( V_76 - V_75 + 1 ) * V_85 ) ;
break;
case V_86 :
F_20 ( V_29 , V_51 + ( V_75 * V_85 ) ,
V_85 ) ;
break;
case V_87 :
goto V_88;
case V_84 :
log ( L_5 ) ;
F_27 ( & V_29 -> V_89 ) ;
return;
}
} while ( V_75 = V_76 + 1 , V_75 < V_65 -> V_81 );
V_88:
V_46 = F_24 ( V_65 , V_73 ) ;
if ( V_46 )
log ( L_6 , V_46 ) ;
}
static int F_28 ( struct V_28 * V_29 )
{
struct V_90 * V_19 = V_29 -> V_16 -> V_19 ;
int V_2 ;
if ( V_29 -> V_91 [ 0 ] )
return 0 ;
for ( V_2 = 0 ; V_2 < V_92 ; V_2 ++ ) {
struct V_65 * V_65 ;
void * V_93 ;
int V_94 ;
V_65 = F_29 ( V_95 , V_96 ) ;
if ( V_65 == NULL )
goto V_88;
V_29 -> V_91 [ V_2 ] = V_65 ;
V_93 = F_30 ( V_19 ,
V_85 * V_95 ,
V_96 ,
& V_65 -> V_97 ) ;
V_65 -> V_98 = F_26 ;
V_65 -> V_99 = V_19 ;
V_65 -> V_57 = V_29 -> V_13 ;
V_65 -> V_100 = F_31 ( V_19 ,
V_29 -> V_101 ) ;
V_65 -> V_102 = 1 ;
V_65 -> V_103 = V_104 | V_105 ;
V_65 -> V_81 = V_95 ;
V_65 -> V_66 = V_93 ;
V_65 -> V_72 = V_95 * V_85 ;
for ( V_94 = 0 ; V_94 < V_95 ; V_94 ++ ) {
V_65 -> V_82 [ V_94 ] . V_55 = V_85 * V_94 ;
V_65 -> V_82 [ V_94 ] . V_106 = V_85 ;
}
}
return 0 ;
V_88:
for (; V_2 > 0 ; V_2 -- )
;
return - V_107 ;
}
int F_32 ( struct V_65 * * V_91 , int V_108 ,
struct V_90 * V_19 , T_3 V_109 ,
int V_110 , T_4 V_111 ,
T_5 V_112 , void * V_57 )
{
int V_2 = 0 ;
for (; V_2 < V_108 ; V_2 ++ ) {
void * V_93 ;
struct V_65 * V_65 = F_29 ( 0 , V_111 ) ;
if ( V_65 == NULL )
return V_2 ;
V_93 = F_30 ( V_19 , V_110 , V_111 ,
& V_65 -> V_97 ) ;
if ( V_93 == NULL ) {
F_33 ( V_65 ) ;
return V_2 ;
}
F_34 ( V_65 , V_19 , F_35 ( V_19 , V_109 ) ,
V_93 , V_110 , V_112 , V_57 ) ;
V_65 -> V_103 |= V_105 ;
V_91 [ V_2 ] = V_65 ;
}
return V_2 ;
}
void F_36 ( struct V_65 * * V_91 , int V_108 )
{
int V_2 ;
struct V_65 * V_65 ;
for ( V_2 = 0 ; V_2 < V_108 ; V_2 ++ ) {
V_65 = V_91 [ V_2 ] ;
if ( V_65 ) {
F_37 ( V_65 -> V_99 ,
V_65 -> V_72 ,
V_65 -> V_66 ,
V_65 -> V_97 ) ;
F_33 ( V_65 ) ;
V_91 [ V_2 ] = NULL ;
}
}
}
static int F_38 ( struct V_28 * V_29 )
{
if ( V_29 -> V_91 [ 0 ] )
return 0 ;
F_32 ( V_29 -> V_91 , V_92 ,
V_29 -> V_16 -> V_19 , V_29 -> V_101 ,
0x2000 , V_96 ,
F_23 , V_29 -> V_13 ) ;
return 0 ;
}
static void F_39 ( struct V_28 * V_29 )
{
F_36 ( V_29 -> V_91 , V_92 ) ;
}
static void F_40 ( struct V_113 * V_114 , struct V_40 * V_41 )
{
F_41 ( V_41 ) ;
V_41 -> V_47 = V_115 ;
}
static void F_42 ( struct V_113 * V_114 , struct V_40 * V_41 )
{
struct V_12 * V_13 = V_114 -> V_116 ;
V_41 -> V_47 = V_117 ;
F_43 ( & V_41 -> V_45 , & V_13 -> V_43 ) ;
}
static int F_44 ( struct V_113 * V_114 , struct V_40 * V_41 ,
enum V_118 V_119 )
{
struct V_12 * V_13 = V_114 -> V_116 ;
int V_120 ;
switch ( V_13 -> type ) {
case V_121 :
if ( V_115 == V_41 -> V_47 ) {
struct V_122 * V_58 ;
V_58 = & V_13 -> V_16 -> V_28 . V_57 . V_58 ;
V_41 -> V_123 = V_58 -> V_59 ;
V_41 -> V_124 = V_58 -> V_124 ;
V_41 -> V_125 = V_58 -> V_125 ;
V_120 = F_45 ( V_114 , V_41 , NULL ) ;
if ( V_120 < 0 )
return V_120 ;
}
break;
case V_126 :
if ( V_115 == V_41 -> V_47 ) {
V_41 -> V_123 = V_13 -> V_16 -> V_54 . V_60 ;
V_120 = F_45 ( V_114 , V_41 , NULL ) ;
if ( V_120 < 0 )
return V_120 ;
}
break;
default:
return - V_127 ;
}
V_41 -> V_119 = V_119 ;
V_41 -> V_47 = V_128 ;
return 0 ;
}
static int F_46 ( struct V_28 * V_29 )
{
int V_2 , V_46 ;
V_29 -> V_68 = 1 ;
for ( V_2 = 0 ; V_2 < V_92 ; V_2 ++ ) {
V_46 = F_24 ( V_29 -> V_91 [ V_2 ] , V_96 ) ;
if ( V_46 )
log ( L_7 , V_2 , V_46 ) ;
}
return V_46 ;
}
static int F_47 ( struct V_14 * V_16 )
{
struct V_28 * V_29 = & V_16 -> V_28 ;
T_6 V_129 ;
F_48 ( V_16 , V_130 , 0 , & V_129 ) ;
F_48 ( V_16 , V_131 , V_132 , & V_129 ) ;
if ( V_16 -> V_133 ) {
F_28 ( V_29 ) ;
F_49 ( & V_29 -> V_89 , V_134 ) ;
} else {
F_38 ( V_29 ) ;
}
F_46 ( V_29 ) ;
return 0 ;
}
static int F_50 ( struct V_113 * V_114 , unsigned int * V_52 ,
unsigned int * V_123 )
{
struct V_12 * V_13 = V_114 -> V_116 ;
struct V_14 * V_16 = V_13 -> V_16 ;
switch ( V_13 -> type ) {
default:
return - V_127 ;
case V_121 : {
struct V_28 * V_29 = & V_16 -> V_28 ;
struct V_122 * V_58 = & V_29 -> V_57 . V_58 ;
* V_123 = F_51 ( V_58 -> V_59 ) ;
if ( * V_52 < 4 )
* V_52 = 4 ;
if ( 1 ) {
V_29 -> V_101 = 0x82 ;
V_29 -> V_37 = & V_16 -> V_54 ;
V_29 -> V_37 -> V_29 = V_29 ;
V_29 -> V_16 = V_16 ;
V_29 -> V_135 = V_58 -> V_125 / 2 ;
V_29 -> V_36 = V_58 -> V_124 * 2 ;
V_29 -> V_13 = V_13 ;
}
return F_47 ( V_16 ) ;
}
case V_126 : {
struct V_54 * V_37 = & V_16 -> V_54 ;
* V_123 = F_51 ( V_37 -> V_60 ) ;
log ( L_8 , * V_123 ) ;
if ( * V_52 == 0 )
* V_52 = 4 ;
}
break;
}
return 0 ;
}
static int F_52 ( struct V_8 * V_8 , void * V_9 ,
struct V_136 * V_137 )
{
if ( F_53 ( V_138 ) <= V_137 -> V_30 )
return - V_127 ;
V_137 -> type = V_121 ;
V_137 -> V_139 = 0 ;
V_137 -> V_140 = V_138 [ V_137 -> V_30 ] . V_141 ;
strcpy ( V_137 -> V_142 , V_138 [ V_137 -> V_30 ] . V_143 ) ;
return 0 ;
}
static int F_54 ( struct V_8 * V_8 , void * V_9 , struct V_144 * V_137 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
F_3 ( V_13 ) ;
V_137 -> V_145 . V_58 = V_16 -> V_28 . V_57 . V_58 ;
return 0 ;
}
static int F_55 ( struct V_8 * V_8 , void * V_9 ,
struct V_144 * V_137 )
{
return 0 ;
}
static int F_56 ( struct V_14 * V_16 , struct V_122 * V_58 )
{
struct V_28 * V_29 = & V_16 -> V_28 ;
struct V_146 * V_57 = & V_29 -> V_57 ;
struct V_122 * V_147 = & V_57 -> V_58 ;
T_6 V_46 = 0 , V_129 = 0 , V_148 ;
if ( V_58 -> V_140 == V_149 ) {
V_148 = V_150 ;
} else {
V_58 -> V_140 = V_151 ;
V_148 = V_152 ;
}
V_46 = F_48 ( V_16 , V_153 ,
V_148 , & V_129 ) ;
V_148 = V_154 ;
switch ( V_58 -> V_124 ) {
case 704 :
V_148 = V_155 ;
break;
default:
V_58 -> V_124 = 720 ;
case 720 :
break;
}
V_46 |= F_48 ( V_16 , V_156 ,
V_148 , & V_129 ) ;
if ( V_46 || V_129 )
return - V_157 ;
V_147 -> V_140 = V_58 -> V_140 ;
V_58 -> V_125 = ( V_57 -> V_158 & V_159 ) ? 480 : 576 ;
if ( ( V_147 -> V_124 != V_58 -> V_124 )
|| ( V_147 -> V_125 != V_58 -> V_125 ) ) {
V_147 -> V_124 = V_58 -> V_124 ;
V_147 -> V_125 = V_58 -> V_125 ;
V_147 -> V_160 = V_58 -> V_124 * 2 ;
V_147 -> V_59 = V_58 -> V_124 * V_58 -> V_125 * 2 ;
}
* V_58 = * V_147 ;
return 0 ;
}
static int F_57 ( struct V_8 * V_8 , void * V_9 , struct V_144 * V_137 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
F_3 ( V_13 ) ;
if ( V_121 != V_137 -> type )
return - V_127 ;
F_58 ( & V_16 -> V_161 ) ;
if ( V_16 -> V_162 == NULL )
V_16 -> V_162 = V_8 ;
else if ( V_8 != V_16 -> V_162 ) {
F_59 ( & V_16 -> V_161 ) ;
return - V_127 ;
}
F_56 ( V_16 , & V_137 -> V_145 . V_58 ) ;
F_59 ( & V_16 -> V_161 ) ;
return 0 ;
}
static int F_60 ( struct V_8 * V_8 , void * V_9 ,
struct V_144 * V_163 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
struct V_164 * V_165 = & V_163 -> V_145 . V_37 ;
V_165 -> V_166 = 720 * 2 ;
V_165 -> V_167 = 6750000 * 4 ;
V_165 -> V_168 = V_169 ;
V_165 -> V_55 = 64 * 4 ;
if ( V_16 -> V_28 . V_57 . V_158 & V_159 ) {
V_165 -> V_74 [ 0 ] = 10 ;
V_165 -> V_74 [ 1 ] = 264 ;
V_165 -> V_52 [ 0 ] = V_170 ;
V_165 -> V_52 [ 1 ] = V_170 ;
} else {
V_165 -> V_74 [ 0 ] = 6 ;
V_165 -> V_74 [ 1 ] = 314 ;
V_165 -> V_52 [ 0 ] = V_171 ;
V_165 -> V_52 [ 1 ] = V_171 ;
}
V_165 -> V_139 = V_172 ;
F_3 ( V_13 ) ;
return 0 ;
}
static int F_61 ( struct V_14 * V_16 , T_1 * V_173 )
{
struct V_28 * V_29 = & V_16 -> V_28 ;
struct V_54 * V_37 = & V_16 -> V_54 ;
struct V_146 * V_57 ;
struct V_122 * V_58 ;
T_6 V_2 , V_46 = 0 , V_129 , V_174 ;
int V_125 ;
for ( V_2 = 0 ; V_2 < V_175 ; V_2 ++ ) {
if ( * V_173 & V_176 [ V_2 ] . V_177 ) {
V_174 = V_176 [ V_2 ] . V_178 ;
log ( L_9 , V_176 [ V_2 ] . V_143 ) ;
goto V_179;
}
}
return - V_127 ;
V_179:
F_58 ( & V_16 -> V_161 ) ;
V_46 = F_48 ( V_16 , V_180 , V_174 , & V_129 ) ;
if ( V_46 || V_129 )
goto V_88;
V_57 = & V_29 -> V_57 ;
V_57 -> V_158 = V_176 [ V_2 ] . V_177 ;
if ( V_57 -> V_158 & V_159 ) {
V_37 -> V_60 = V_181 ;
V_125 = 480 ;
} else {
V_37 -> V_60 = V_182 ;
V_125 = 576 ;
}
V_58 = & V_57 -> V_58 ;
if ( V_58 -> V_125 != V_125 ) {
V_58 -> V_125 = V_125 ;
V_58 -> V_59 = V_58 -> V_124 * V_58 -> V_125 * 2 ;
}
V_88:
F_59 ( & V_16 -> V_161 ) ;
return V_46 ;
}
static int F_62 ( struct V_8 * V_8 , void * V_9 , T_1 * V_173 )
{
struct V_12 * V_13 = V_9 ;
F_3 ( V_13 ) ;
return F_61 ( V_13 -> V_16 , V_173 ) ;
}
static int F_63 ( struct V_8 * V_8 , void * V_9 , struct V_183 * V_184 )
{
struct V_12 * V_13 = V_9 ;
if ( V_184 -> V_30 < 0 || V_184 -> V_30 >= V_185 )
return - V_127 ;
strcpy ( V_184 -> V_143 , V_186 [ V_184 -> V_30 ] . V_143 ) ;
V_184 -> type = V_187 ;
V_184 -> V_188 = 0 ;
V_184 -> V_189 = 0 ;
V_184 -> V_190 = V_191 ;
V_184 -> V_69 = 0 ;
F_3 ( V_13 ) ;
return 0 ;
}
static int F_64 ( struct V_8 * V_8 , void * V_9 , unsigned int * V_2 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
struct V_146 * V_57 = & V_16 -> V_28 . V_57 ;
F_3 ( V_13 ) ;
* V_2 = V_57 -> V_192 ;
return 0 ;
}
static int F_65 ( struct V_8 * V_8 , void * V_9 , unsigned int V_2 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
T_6 V_46 , V_129 ;
if ( V_2 < 0 || V_2 >= V_185 )
return - V_127 ;
V_46 = F_48 ( V_16 , V_193 ,
V_186 [ V_2 ] . V_194 , & V_129 ) ;
if ( V_46 )
return V_46 ;
V_16 -> V_28 . V_57 . V_192 = V_2 ;
return 0 ;
}
static struct V_195 * F_66 ( T_7 V_196 )
{
struct V_195 * V_197 = & V_198 [ 0 ] ;
int V_199 = F_53 ( V_198 ) ;
for (; V_197 < & V_198 [ V_199 ] ; V_197 ++ )
if ( V_197 -> V_200 . V_196 == V_196 )
return V_197 ;
return NULL ;
}
static int F_67 ( struct V_8 * V_8 , void * V_9 ,
struct V_201 * V_202 )
{
struct V_195 * V_197 = NULL ;
V_197 = F_66 ( V_202 -> V_196 ) ;
if ( ! V_197 )
return - V_127 ;
* V_202 = V_197 -> V_200 ;
return 0 ;
}
static int F_68 ( struct V_8 * V_8 , void * V_9 , struct V_203 * V_204 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
struct V_195 * V_197 = NULL ;
struct V_205 V_206 ;
T_6 V_46 = 0 , V_129 ;
V_197 = F_66 ( V_204 -> V_196 ) ;
if ( ! V_197 )
return - V_127 ;
F_58 ( & V_16 -> V_161 ) ;
V_46 = F_69 ( V_16 , V_207 , V_197 -> V_208 ,
& V_206 , & V_129 , sizeof( V_206 ) ) ;
F_59 ( & V_16 -> V_161 ) ;
if ( V_46 || V_129 )
return - 1 ;
V_204 -> V_209 = V_206 . V_210 ;
return 0 ;
}
static int F_70 ( struct V_8 * V_8 , void * V_9 , struct V_203 * V_202 )
{
struct V_205 V_174 = { 0 } ;
struct V_195 * V_197 = NULL ;
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
T_6 V_46 = 0 , V_129 , V_211 ;
V_197 = F_66 ( V_202 -> V_196 ) ;
if ( ! V_197 )
return - V_127 ;
V_174 . V_210 = V_202 -> V_209 ;
V_174 . V_212 = V_197 -> V_208 ;
V_211 = * ( T_6 * ) & V_174 ;
F_58 ( & V_16 -> V_161 ) ;
V_46 = F_48 ( V_16 , V_207 , V_211 , & V_129 ) ;
V_46 = F_48 ( V_16 , V_130 , 0 , & V_129 ) ;
F_59 ( & V_16 -> V_161 ) ;
F_71 ( V_213 ) ;
F_72 ( V_214 / 4 ) ;
return V_46 ;
}
static int F_73 ( struct V_8 * V_8 , void * V_9 , struct V_215 * V_202 )
{
if ( 0 != V_202 -> V_30 )
return - V_127 ;
V_202 -> V_216 = V_217 ;
strcpy ( V_202 -> V_143 , L_10 ) ;
V_202 -> V_218 = 0 ;
return 0 ;
}
static int F_74 ( struct V_8 * V_8 , void * V_9 , struct V_215 * V_202 )
{
V_202 -> V_30 = 0 ;
V_202 -> V_216 = V_217 ;
strcpy ( V_202 -> V_143 , L_10 ) ;
V_202 -> V_218 = 0 ;
return 0 ;
}
static int F_75 ( struct V_8 * V_8 , void * V_9 , const struct V_215 * V_202 )
{
return ( 0 == V_202 -> V_30 ) ? 0 : - V_127 ;
}
static int F_76 ( struct V_8 * V_8 , void * V_9 , struct V_219 * V_189 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
struct V_220 V_221 ;
T_6 V_52 = 5 , V_46 , V_129 ;
int V_30 ;
if ( 0 != V_189 -> V_30 )
return - V_127 ;
F_58 ( & V_16 -> V_161 ) ;
V_46 = F_69 ( V_16 , V_222 , V_223 ,
& V_221 , & V_129 , sizeof( V_221 ) ) ;
while ( V_221 . V_224 && V_52 -- && ! V_46 ) {
F_71 ( V_213 ) ;
F_72 ( V_214 ) ;
V_46 = F_69 ( V_16 , V_222 , V_223 ,
& V_221 , & V_129 , sizeof( V_221 ) ) ;
}
F_59 ( & V_16 -> V_161 ) ;
if ( V_225 )
log ( L_11 , V_221 . V_226 , V_221 . V_227 ) ;
if ( V_46 || V_129 )
V_189 -> signal = 0 ;
else if ( V_221 . V_226 && ! V_221 . V_227 )
V_189 -> signal = 0xFFFF ;
else
V_189 -> signal = ( V_221 . V_227 * 255 / 10 ) << 8 ;
strcpy ( V_189 -> V_143 , L_12 ) ;
V_189 -> type = V_228 ;
V_189 -> V_229 = V_230 / 62500 ;
V_189 -> V_231 = V_232 / 62500 ;
V_189 -> V_216 = V_233 | V_234 |
V_235 | V_236 ;
V_30 = V_16 -> V_28 . V_57 . V_237 ;
V_189 -> V_238 = V_239 [ V_30 ] . V_240 ;
V_189 -> V_241 = V_239 [ V_30 ] . V_242 ;
V_189 -> V_243 = 0 ;
F_3 ( V_13 ) ;
return 0 ;
}
static int F_77 ( struct V_14 * V_16 , int V_30 )
{
T_6 V_46 = 0 , V_129 , V_174 , V_244 ;
F_58 ( & V_16 -> V_161 ) ;
V_174 = V_239 [ V_30 ] . V_245 ;
V_46 = F_48 ( V_16 , V_246 , V_174 , & V_129 ) ;
V_244 = F_1 ( V_16 -> V_28 . V_57 . V_158 ) ;
V_46 |= F_48 ( V_16 , V_247 , V_244 ,
& V_129 ) ;
if ( ! V_46 )
V_16 -> V_28 . V_57 . V_237 = V_30 ;
F_59 ( & V_16 -> V_161 ) ;
return V_46 ;
}
static int F_78 ( struct V_8 * V_8 , void * V_9 , struct V_219 * V_202 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
int V_30 ;
if ( 0 != V_202 -> V_30 )
return - V_127 ;
F_3 ( V_13 ) ;
for ( V_30 = 0 ; V_30 < V_248 ; V_30 ++ )
if ( V_202 -> V_241 == V_239 [ V_30 ] . V_242 )
return F_77 ( V_16 , V_30 ) ;
return - V_127 ;
}
static int F_79 ( struct V_8 * V_8 , void * V_9 ,
struct V_249 * V_250 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
struct V_146 * V_57 = & V_16 -> V_28 . V_57 ;
if ( 0 != V_250 -> V_189 )
return - V_127 ;
V_250 -> V_251 = V_57 -> V_250 ;
V_250 -> type = V_228 ;
return 0 ;
}
static int F_80 ( struct V_14 * V_16 , T_7 V_251 )
{
T_6 V_46 = 0 , V_174 , V_129 ;
struct V_146 * V_57 = & V_16 -> V_28 . V_57 ;
V_174 = V_251 * 62500 / 1000 ;
if ( V_174 < V_230 / 1000 || V_174 > V_232 / 1000 )
return - V_127 ;
F_58 ( & V_16 -> V_161 ) ;
V_46 = F_48 ( V_16 , V_252 , V_174 , & V_129 ) ;
V_46 = F_48 ( V_16 , V_130 , 0 , & V_129 ) ;
F_81 ( 250 ) ;
V_57 -> V_250 = V_251 ;
F_59 ( & V_16 -> V_161 ) ;
return V_46 ;
}
static int F_82 ( struct V_8 * V_8 , void * V_9 ,
struct V_249 * V_250 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_16 = V_13 -> V_16 ;
F_3 ( V_13 ) ;
#ifdef F_83
V_16 -> V_253 = V_254 ;
V_16 -> V_255 = V_256 ;
#endif
return F_80 ( V_16 , V_250 -> V_251 ) ;
}
static int F_84 ( struct V_8 * V_8 , void * V_9 ,
struct V_257 * V_258 )
{
struct V_12 * V_13 = V_8 -> V_259 ;
F_3 ( V_13 ) ;
return F_85 ( & V_13 -> V_114 , V_258 ) ;
}
static int F_86 ( struct V_8 * V_8 , void * V_9 , struct V_260 * V_258 )
{
struct V_12 * V_13 = V_8 -> V_259 ;
F_3 ( V_13 ) ;
return F_87 ( & V_13 -> V_114 , V_258 ) ;
}
static int F_88 ( struct V_8 * V_8 , void * V_9 , struct V_260 * V_258 )
{
struct V_12 * V_13 = V_8 -> V_259 ;
return F_89 ( & V_13 -> V_114 , V_258 ) ;
}
static int F_90 ( struct V_8 * V_8 , void * V_9 , struct V_260 * V_258 )
{
struct V_12 * V_13 = V_8 -> V_259 ;
return F_91 ( & V_13 -> V_114 , V_258 , V_8 -> V_261 & V_262 ) ;
}
static int F_92 ( struct V_28 * V_29 )
{
if ( V_29 -> V_68 ) {
int V_2 ;
T_6 V_129 ;
struct V_14 * V_16 = V_29 -> V_16 ;
V_29 -> V_68 = 0 ;
for ( V_2 = 0 ; V_2 < V_92 ; ++ V_2 ) {
if ( V_29 -> V_91 [ V_2 ] )
F_93 ( V_29 -> V_91 [ V_2 ] ) ;
}
F_48 ( V_16 , V_131 , V_263 ,
& V_129 ) ;
}
return 0 ;
}
int F_94 ( struct V_14 * V_16 )
{
struct V_28 * V_29 = & V_16 -> V_28 ;
struct V_54 * V_37 = & V_16 -> V_54 ;
F_58 ( & V_16 -> V_161 ) ;
if ( V_29 -> V_68 ) {
struct V_12 * V_13 = V_29 -> V_13 ;
F_92 ( V_29 ) ;
F_39 ( V_29 ) ;
F_95 ( & V_13 -> V_114 ) ;
F_96 ( & V_13 -> V_114 ) ;
V_13 = V_37 -> V_13 ;
if ( V_13 ) {
F_95 ( & V_13 -> V_114 ) ;
F_96 ( & V_13 -> V_114 ) ;
}
}
F_59 ( & V_16 -> V_161 ) ;
return 0 ;
}
static void V_134 ( struct V_264 * V_265 )
{
struct V_28 * V_29 ;
struct V_14 * V_16 ;
V_29 = F_97 ( V_265 , struct V_28 , V_89 ) ;
V_16 = V_29 -> V_16 ;
F_58 ( & V_16 -> V_161 ) ;
F_92 ( V_29 ) ;
F_81 ( 500 ) ;
F_47 ( V_16 ) ;
F_59 ( & V_16 -> V_161 ) ;
}
static int F_98 ( struct V_8 * V_8 , void * V_9 ,
enum V_266 type )
{
struct V_12 * V_13 = V_9 ;
F_3 ( V_13 ) ;
if ( F_99 ( type != V_13 -> type ) )
return - V_127 ;
return F_100 ( & V_13 -> V_114 ) ;
}
static int F_101 ( struct V_8 * V_8 , void * V_9 ,
enum V_266 type )
{
struct V_12 * V_13 = V_8 -> V_259 ;
F_3 ( V_13 ) ;
if ( F_99 ( type != V_13 -> type ) )
return - V_127 ;
return F_102 ( & V_13 -> V_114 ) ;
}
static int F_103 ( struct V_14 * V_16 )
{
T_6 V_46 = 0 , V_129 , V_244 ;
F_71 ( V_213 ) ;
F_72 ( V_214 / 2 ) ;
V_46 = F_104 ( V_16 -> V_19 , 0 ,
( V_16 -> V_133 ?
V_267 :
V_268 ) ) ;
if ( V_46 < 0 )
goto error;
V_46 = F_105 ( V_16 , V_223 ) ;
V_46 |= F_48 ( V_16 , V_193 ,
V_269 , & V_129 ) ;
V_46 |= F_48 ( V_16 , V_180 ,
V_270 , & V_129 ) ;
V_46 |= F_48 ( V_16 , V_153 ,
V_152 , & V_129 ) ;
V_46 |= F_48 ( V_16 , V_156 ,
V_154 , & V_129 ) ;
V_46 |= F_48 ( V_16 , V_252 , V_230 , & V_129 ) ;
V_46 |= F_48 ( V_16 , V_271 , 1 , & V_129 ) ;
V_244 = F_1 ( V_16 -> V_28 . V_57 . V_158 ) ;
V_46 |= F_48 ( V_16 , V_247 , V_244 , & V_129 ) ;
V_46 |= F_48 ( V_16 , V_246 ,
V_272 , & V_129 ) ;
V_46 |= F_48 ( V_16 , V_273 ,
V_274 , & V_129 ) ;
error:
return V_46 ;
}
static int V_254 ( struct V_14 * V_16 )
{
F_106 ( V_16 ) ;
F_92 ( & V_16 -> V_28 ) ;
F_39 ( & V_16 -> V_28 ) ;
F_104 ( V_16 -> V_19 , 0 , 0 ) ;
F_81 ( 300 ) ;
return 0 ;
}
static int F_107 ( struct V_14 * V_16 ,
struct V_146 * V_57 )
{
struct V_12 * V_13 = V_16 -> V_28 . V_13 ;
F_103 ( V_16 ) ;
F_61 ( V_16 , & V_57 -> V_158 ) ;
F_65 ( NULL , V_13 , V_57 -> V_192 ) ;
F_77 ( V_16 , V_57 -> V_237 ) ;
F_56 ( V_16 , & V_57 -> V_58 ) ;
F_80 ( V_16 , V_57 -> V_250 ) ;
return 0 ;
}
static int V_256 ( struct V_14 * V_16 )
{
struct V_28 * V_29 = & V_16 -> V_28 ;
F_107 ( V_16 , & V_29 -> V_57 ) ;
if ( V_29 -> V_13 -> V_35 )
F_5 ( V_29 , 0 ) ;
F_47 ( V_16 ) ;
F_108 ( V_16 ) ;
return 0 ;
}
void F_109 ( struct V_275 * V_276 , int V_225 )
{
V_276 -> V_277 = 0 ;
if ( V_225 & 0x1 )
V_276 -> V_277 = V_278 ;
if ( V_225 & 0x2 )
V_276 -> V_277 = V_278 | V_279 ;
}
static void F_110 ( struct V_146 * V_57 )
{
V_57 -> V_192 = 0 ;
V_57 -> V_237 = 1 ;
V_57 -> V_158 = V_280 ;
V_57 -> V_58 = (struct V_122 ) {
. V_124 = 720 ,
. V_125 = 576 ,
. V_140 = V_151 ,
. V_119 = V_281 ,
. V_160 = 720 * 2 ,
. V_59 = 720 * 576 * 2 ,
. V_282 = V_283 ,
. V_284 = 0
} ;
}
static int F_111 ( struct V_8 * V_8 )
{
struct V_275 * V_276 = F_112 ( V_8 ) ;
struct V_14 * V_16 = F_113 ( V_276 ) ;
struct V_12 * V_13 = NULL ;
int V_46 = - V_107 ;
F_58 ( & V_16 -> V_161 ) ;
F_114 ( V_16 -> V_285 ) ;
if ( V_276 -> V_286 == V_287
&& ! ( V_16 -> V_47 & V_288 ) ) {
V_13 = F_115 ( sizeof( struct V_12 ) , V_96 ) ;
if ( ! V_13 )
goto V_88;
V_16 -> V_133 = V_289 ;
F_110 ( & V_16 -> V_28 . V_57 ) ;
V_46 = F_103 ( V_16 ) ;
if ( V_46 < 0 ) {
F_116 ( V_13 ) ;
V_46 = - 1 ;
goto V_88;
}
V_16 -> V_47 |= V_288 ;
V_13 -> type = V_121 ;
V_16 -> V_28 . V_290 ++ ;
F_109 ( V_276 , V_225 ) ;
F_117 ( & V_13 -> V_114 , & V_291 ,
NULL , & V_13 -> V_42 ,
V_121 ,
V_281 ,
sizeof( struct V_40 ) ,
V_13 , NULL ) ;
} else if ( V_276 -> V_286 == V_292
&& ! ( V_16 -> V_47 & V_293 ) ) {
V_13 = F_115 ( sizeof( struct V_12 ) , V_96 ) ;
if ( ! V_13 )
goto V_88;
V_16 -> V_47 |= V_293 ;
V_13 -> type = V_126 ;
V_16 -> V_54 . V_13 = V_13 ;
V_16 -> V_54 . V_290 ++ ;
F_117 ( & V_13 -> V_114 , & V_291 ,
NULL , & V_13 -> V_42 ,
V_126 ,
V_294 ,
sizeof( struct V_40 ) ,
V_13 , NULL ) ;
} else {
log ( L_13 ) ;
V_46 = - V_127 ;
goto V_88;
}
V_13 -> V_16 = V_16 ;
V_13 -> V_35 = NULL ;
F_118 ( & V_13 -> V_43 ) ;
F_119 ( & V_13 -> V_42 ) ;
V_8 -> V_259 = V_13 ;
F_120 ( & V_16 -> V_295 ) ;
F_59 ( & V_16 -> V_161 ) ;
return 0 ;
V_88:
F_121 ( V_16 -> V_285 ) ;
F_59 ( & V_16 -> V_161 ) ;
return V_46 ;
}
static int F_122 ( struct V_8 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_259 ;
struct V_14 * V_16 = V_13 -> V_16 ;
T_6 V_129 = 0 ;
F_3 ( V_13 ) ;
F_58 ( & V_16 -> V_161 ) ;
if ( V_13 -> type == V_121 ) {
V_16 -> V_47 &= ~ V_288 ;
F_92 ( & V_16 -> V_28 ) ;
F_39 ( & V_16 -> V_28 ) ;
F_48 ( V_16 , V_131 , V_263 ,
& V_129 ) ;
V_16 -> V_162 = NULL ;
V_16 -> V_28 . V_290 -- ;
} else if ( V_13 -> type == V_126 ) {
V_16 -> V_47 &= ~ V_293 ;
V_16 -> V_54 . V_13 = NULL ;
V_16 -> V_54 . V_290 -- ;
}
F_95 ( & V_13 -> V_114 ) ;
F_96 ( & V_13 -> V_114 ) ;
F_121 ( V_16 -> V_285 ) ;
F_59 ( & V_16 -> V_161 ) ;
F_116 ( V_13 ) ;
V_8 -> V_259 = NULL ;
F_123 ( & V_16 -> V_295 , V_296 ) ;
return 0 ;
}
static int F_124 ( struct V_8 * V_8 , struct V_297 * V_298 )
{
struct V_12 * V_13 = V_8 -> V_259 ;
return F_125 ( & V_13 -> V_114 , V_298 ) ;
}
static unsigned int F_126 ( struct V_8 * V_8 , T_8 * V_299 )
{
struct V_12 * V_13 = V_8 -> V_259 ;
return F_127 ( V_8 , & V_13 -> V_114 , V_299 ) ;
}
static T_9 F_128 ( struct V_8 * V_8 , char T_10 * V_300 ,
T_11 V_52 , T_12 * V_301 )
{
struct V_12 * V_13 = V_8 -> V_259 ;
return F_129 ( & V_13 -> V_114 , V_300 , V_52 , V_301 ,
0 , V_8 -> V_261 & V_262 ) ;
}
struct V_275 * F_130 ( struct V_14 * V_16 , struct V_275 * V_302 )
{
struct V_275 * V_276 ;
V_276 = F_131 () ;
if ( V_276 == NULL )
return NULL ;
* V_276 = * V_302 ;
V_276 -> V_303 = - 1 ;
V_276 -> V_304 = & V_16 -> V_304 ;
V_276 -> V_305 = V_306 ;
F_132 ( V_276 , V_16 ) ;
return V_276 ;
}
void F_133 ( struct V_275 * * V_307 )
{
struct V_275 * V_99 = * V_307 ;
if ( V_99 == NULL )
return;
if ( F_134 ( V_99 ) )
F_135 ( V_99 ) ;
else
V_306 ( V_99 ) ;
* V_307 = NULL ;
}
void F_136 ( struct V_14 * V_16 )
{
struct V_28 * V_29 = & V_16 -> V_28 ;
struct V_54 * V_37 = & V_16 -> V_54 ;
F_133 ( & V_29 -> V_307 ) ;
F_133 ( & V_37 -> V_307 ) ;
log () ;
}
int F_137 ( struct V_14 * V_16 )
{
struct V_28 * V_29 = & V_16 -> V_28 ;
struct V_54 * V_37 = & V_16 -> V_54 ;
int V_46 = - V_107 ;
V_29 -> V_307 = F_130 ( V_16 , & V_308 ) ;
if ( V_29 -> V_307 == NULL )
goto V_88;
V_46 = F_138 ( V_29 -> V_307 , V_287 , - 1 ) ;
if ( V_46 != 0 )
goto V_88;
V_37 -> V_307 = F_130 ( V_16 , & V_308 ) ;
if ( V_37 -> V_307 == NULL ) {
V_46 = - V_107 ;
goto V_88;
}
V_46 = F_138 ( V_37 -> V_307 , V_292 , - 1 ) ;
if ( V_46 != 0 )
goto V_88;
log ( L_14 ) ;
return 0 ;
V_88:
log ( L_15 , V_46 ) ;
F_136 ( V_16 ) ;
return V_46 ;
}
