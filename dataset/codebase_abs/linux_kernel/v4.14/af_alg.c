static const struct V_1 * F_1 ( const char * V_2 )
{
const struct V_1 * type = F_2 ( - V_3 ) ;
struct V_4 * V_5 ;
F_3 ( & V_6 ) ;
F_4 (node, &alg_types, list) {
if ( strcmp ( V_5 -> type -> V_2 , V_2 ) )
continue;
if ( F_5 ( V_5 -> type -> V_7 ) )
type = V_5 -> type ;
break;
}
F_6 ( & V_6 ) ;
return type ;
}
int F_7 ( const struct V_1 * type )
{
struct V_4 * V_5 ;
int V_8 = - V_9 ;
F_8 ( & V_6 ) ;
F_4 (node, &alg_types, list) {
if ( ! strcmp ( V_5 -> type -> V_2 , type -> V_2 ) )
goto V_10;
}
V_5 = F_9 ( sizeof( * V_5 ) , V_11 ) ;
V_8 = - V_12 ;
if ( ! V_5 )
goto V_10;
type -> V_13 -> V_7 = V_14 ;
if ( type -> V_15 )
type -> V_15 -> V_7 = V_14 ;
V_5 -> type = type ;
F_10 ( & V_5 -> V_16 , & V_17 ) ;
V_8 = 0 ;
V_10:
F_11 ( & V_6 ) ;
return V_8 ;
}
int F_12 ( const struct V_1 * type )
{
struct V_4 * V_5 ;
int V_8 = - V_3 ;
F_8 ( & V_6 ) ;
F_4 (node, &alg_types, list) {
if ( strcmp ( V_5 -> type -> V_2 , type -> V_2 ) )
continue;
F_13 ( & V_5 -> V_16 ) ;
F_14 ( V_5 ) ;
V_8 = 0 ;
break;
}
F_11 ( & V_6 ) ;
return V_8 ;
}
static void F_15 ( const struct V_1 * type , void * V_18 )
{
if ( ! type )
return;
type -> V_19 ( V_18 ) ;
F_16 ( type -> V_7 ) ;
}
int F_17 ( struct V_20 * V_21 )
{
if ( V_21 -> V_22 )
F_18 ( V_21 -> V_22 ) ;
return 0 ;
}
void F_19 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_20 ( V_22 ) ;
unsigned int V_25 = V_24 -> V_26 ;
bool V_27 = V_25 && ! V_24 -> V_28 ;
V_22 = V_24 -> V_29 ;
V_24 = F_20 ( V_22 ) ;
F_21 ( V_22 ) ;
V_24 -> V_26 -= V_25 ;
if ( ! V_27 )
V_27 = ! -- V_24 -> V_28 ;
F_22 ( V_22 ) ;
if ( V_27 )
F_18 ( V_22 ) ;
}
static int F_23 ( struct V_20 * V_21 , struct V_30 * V_31 , int V_32 )
{
const T_1 V_33 = V_34 ;
struct V_21 * V_22 = V_21 -> V_22 ;
struct V_23 * V_24 = F_20 ( V_22 ) ;
struct V_35 * V_36 = ( void * ) V_31 ;
const struct V_1 * type ;
void * V_18 ;
int V_8 ;
if ( V_21 -> V_37 == V_38 )
return - V_39 ;
if ( V_32 < sizeof( * V_36 ) )
return - V_39 ;
V_36 -> V_40 [ sizeof( V_36 -> V_40 ) - 1 ] = 0 ;
V_36 -> V_41 [ sizeof( V_36 -> V_41 ) + V_32 - sizeof( * V_36 ) - 1 ] = 0 ;
type = F_1 ( V_36 -> V_40 ) ;
if ( F_24 ( type ) && F_25 ( type ) == - V_3 ) {
F_26 ( L_1 , V_36 -> V_40 ) ;
type = F_1 ( V_36 -> V_40 ) ;
}
if ( F_24 ( type ) )
return F_25 ( type ) ;
V_18 = type -> V_42 ( V_36 -> V_41 ,
V_36 -> V_43 & ~ V_33 ,
V_36 -> V_44 & ~ V_33 ) ;
if ( F_24 ( V_18 ) ) {
F_16 ( type -> V_7 ) ;
return F_25 ( V_18 ) ;
}
V_8 = - V_45 ;
F_21 ( V_22 ) ;
if ( V_24 -> V_28 | V_24 -> V_26 )
goto V_10;
F_27 ( V_24 -> type , type ) ;
F_27 ( V_24 -> V_18 , V_18 ) ;
V_8 = 0 ;
V_10:
F_22 ( V_22 ) ;
F_15 ( type , V_18 ) ;
return V_8 ;
}
static int F_28 ( struct V_21 * V_22 , char T_2 * V_46 ,
unsigned int V_47 )
{
struct V_23 * V_24 = F_20 ( V_22 ) ;
const struct V_1 * type = V_24 -> type ;
T_3 * V_48 ;
int V_8 ;
V_48 = F_29 ( V_22 , V_47 , V_11 ) ;
if ( ! V_48 )
return - V_12 ;
V_8 = - V_49 ;
if ( F_30 ( V_48 , V_46 , V_47 ) )
goto V_50;
V_8 = type -> V_51 ( V_24 -> V_18 , V_48 , V_47 ) ;
V_50:
F_31 ( V_22 , V_48 , V_47 ) ;
return V_8 ;
}
static int F_32 ( struct V_20 * V_21 , int V_52 , int V_53 ,
char T_2 * V_54 , unsigned int V_55 )
{
struct V_21 * V_22 = V_21 -> V_22 ;
struct V_23 * V_24 = F_20 ( V_22 ) ;
const struct V_1 * type ;
int V_8 = - V_45 ;
F_21 ( V_22 ) ;
if ( V_24 -> V_28 )
goto V_10;
type = V_24 -> type ;
V_8 = - V_56 ;
if ( V_52 != V_57 || ! type )
goto V_10;
switch ( V_53 ) {
case V_58 :
if ( V_21 -> V_37 == V_38 )
goto V_10;
if ( ! type -> V_51 )
goto V_10;
V_8 = F_28 ( V_22 , V_54 , V_55 ) ;
break;
case V_59 :
if ( V_21 -> V_37 == V_38 )
goto V_10;
if ( ! type -> V_60 )
goto V_10;
V_8 = type -> V_60 ( V_24 -> V_18 , V_55 ) ;
}
V_10:
F_22 ( V_22 ) ;
return V_8 ;
}
int F_33 ( struct V_21 * V_22 , struct V_20 * V_61 , bool V_62 )
{
struct V_23 * V_24 = F_20 ( V_22 ) ;
const struct V_1 * type ;
struct V_21 * V_63 ;
unsigned int V_25 ;
int V_8 ;
F_21 ( V_22 ) ;
type = V_24 -> type ;
V_8 = - V_39 ;
if ( ! type )
goto V_10;
V_63 = F_34 ( F_35 ( V_22 ) , V_64 , V_11 , & V_65 , V_62 ) ;
V_8 = - V_12 ;
if ( ! V_63 )
goto V_10;
F_36 ( V_61 , V_63 ) ;
F_37 ( V_63 , V_61 ) ;
F_38 ( V_22 , V_63 ) ;
V_8 = type -> V_66 ( V_24 -> V_18 , V_63 ) ;
V_25 = V_8 == - V_67 ;
if ( V_25 && type -> V_68 )
V_8 = type -> V_68 ( V_24 -> V_18 , V_63 ) ;
if ( V_8 )
goto V_10;
V_63 -> V_69 = V_64 ;
if ( V_25 || ! V_24 -> V_28 ++ )
F_39 ( V_22 ) ;
V_24 -> V_26 += V_25 ;
F_20 ( V_63 ) -> V_29 = V_22 ;
F_20 ( V_63 ) -> type = type ;
F_20 ( V_63 ) -> V_26 = V_25 ;
V_61 -> V_13 = type -> V_13 ;
V_61 -> V_37 = V_38 ;
if ( V_25 )
V_61 -> V_13 = type -> V_15 ;
V_8 = 0 ;
V_10:
F_22 ( V_22 ) ;
return V_8 ;
}
static int F_40 ( struct V_20 * V_21 , struct V_20 * V_61 , int V_70 ,
bool V_62 )
{
return F_33 ( V_21 -> V_22 , V_61 , V_62 ) ;
}
static void F_41 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_20 ( V_22 ) ;
F_15 ( V_24 -> type , V_24 -> V_18 ) ;
}
static int F_42 ( struct V_71 * V_71 , struct V_20 * V_21 , int V_72 ,
int V_62 )
{
struct V_21 * V_22 ;
int V_8 ;
if ( V_21 -> type != V_73 )
return - V_74 ;
if ( V_72 != 0 )
return - V_75 ;
V_8 = - V_12 ;
V_22 = F_34 ( V_71 , V_64 , V_11 , & V_65 , V_62 ) ;
if ( ! V_22 )
goto V_50;
V_21 -> V_13 = & V_76 ;
F_36 ( V_21 , V_22 ) ;
V_22 -> V_69 = V_64 ;
V_22 -> V_77 = F_41 ;
return 0 ;
V_50:
return V_8 ;
}
int F_43 ( struct V_78 * V_79 , struct V_80 * V_81 , int V_82 )
{
T_4 V_83 ;
T_5 V_84 ;
int V_85 , V_86 ;
V_84 = F_44 ( V_81 , V_79 -> V_87 , V_82 , V_88 , & V_83 ) ;
if ( V_84 < 0 )
return V_84 ;
V_85 = ( V_83 + V_84 + V_89 - 1 ) >> V_90 ;
if ( F_45 ( V_85 == 0 ) )
return - V_39 ;
F_46 ( V_79 -> V_91 , V_85 + 1 ) ;
for ( V_86 = 0 , V_82 = V_84 ; V_86 < V_85 ; V_86 ++ ) {
int V_92 = F_47 ( int , V_82 , V_89 - V_83 ) ;
F_48 ( V_79 -> V_91 + V_86 , V_79 -> V_87 [ V_86 ] , V_92 , V_83 ) ;
V_83 = 0 ;
V_82 -= V_92 ;
}
F_49 ( V_79 -> V_91 + V_85 - 1 ) ;
V_79 -> V_85 = V_85 ;
return V_84 ;
}
void F_50 ( struct V_78 * V_93 , struct V_78 * V_94 )
{
F_51 ( V_93 -> V_91 + V_93 -> V_85 - 1 ) ;
F_52 ( V_93 -> V_91 , V_93 -> V_85 + 1 , V_94 -> V_91 ) ;
}
void F_53 ( struct V_78 * V_79 )
{
int V_86 ;
for ( V_86 = 0 ; V_86 < V_79 -> V_85 ; V_86 ++ )
F_54 ( V_79 -> V_87 [ V_86 ] ) ;
}
int F_55 ( struct V_95 * V_96 , struct V_97 * V_98 )
{
struct V_99 * V_100 ;
F_56 (cmsg, msg) {
if ( ! F_57 ( V_96 , V_100 ) )
return - V_39 ;
if ( V_100 -> V_101 != V_57 )
continue;
switch ( V_100 -> V_102 ) {
case V_103 :
if ( V_100 -> V_104 < F_58 ( sizeof( * V_98 -> V_105 ) ) )
return - V_39 ;
V_98 -> V_105 = ( void * ) F_59 ( V_100 ) ;
if ( V_100 -> V_104 < F_58 ( V_98 -> V_105 -> V_106 +
sizeof( * V_98 -> V_105 ) ) )
return - V_39 ;
break;
case V_107 :
if ( V_100 -> V_104 < F_58 ( sizeof( T_1 ) ) )
return - V_39 ;
V_98 -> V_108 = * ( T_1 * ) F_59 ( V_100 ) ;
break;
case V_109 :
if ( V_100 -> V_104 < F_58 ( sizeof( T_1 ) ) )
return - V_39 ;
V_98 -> V_110 = * ( T_1 * ) F_59 ( V_100 ) ;
break;
default:
return - V_39 ;
}
}
return 0 ;
}
int F_60 ( int V_8 , struct V_111 * V_112 )
{
switch ( V_8 ) {
case - V_113 :
case - V_45 :
F_61 ( & V_112 -> V_112 ) ;
F_62 ( & V_112 -> V_112 ) ;
V_8 = V_112 -> V_8 ;
break;
} ;
return V_8 ;
}
void F_63 ( struct V_114 * V_115 , int V_8 )
{
struct V_111 * V_112 = V_115 -> V_116 ;
if ( V_8 == - V_113 )
return;
V_112 -> V_8 = V_8 ;
F_64 ( & V_112 -> V_112 ) ;
}
int F_65 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_20 ( V_22 ) ;
struct V_117 * V_118 = V_24 -> V_18 ;
struct V_119 * V_79 ;
struct V_120 * V_91 = NULL ;
V_79 = F_66 ( V_118 -> V_121 . V_122 , struct V_119 , V_16 ) ;
if ( ! F_67 ( & V_118 -> V_121 ) )
V_91 = V_79 -> V_91 ;
if ( ! V_91 || V_79 -> V_123 >= V_124 ) {
V_79 = F_29 ( V_22 , sizeof( * V_79 ) +
sizeof( V_79 -> V_91 [ 0 ] ) * ( V_124 + 1 ) ,
V_11 ) ;
if ( ! V_79 )
return - V_12 ;
F_46 ( V_79 -> V_91 , V_124 + 1 ) ;
V_79 -> V_123 = 0 ;
if ( V_91 )
F_52 ( V_91 , V_124 + 1 , V_79 -> V_91 ) ;
F_68 ( & V_79 -> V_16 , & V_118 -> V_121 ) ;
}
return 0 ;
}
unsigned int F_69 ( struct V_21 * V_22 , T_4 V_125 , T_4 V_126 )
{
struct V_23 * V_24 = F_20 ( V_22 ) ;
struct V_117 * V_118 = V_24 -> V_18 ;
struct V_119 * V_79 , * V_127 ;
unsigned int V_86 ;
unsigned int V_128 = 0 ;
if ( ! V_125 )
return 0 ;
F_70 (sgl, tmp, &ctx->tsgl_list, list) {
struct V_120 * V_91 = V_79 -> V_91 ;
for ( V_86 = 0 ; V_86 < V_79 -> V_123 ; V_86 ++ ) {
T_4 V_129 ;
if ( V_126 >= V_91 [ V_86 ] . V_130 ) {
V_126 -= V_91 [ V_86 ] . V_130 ;
V_125 -= V_91 [ V_86 ] . V_130 ;
continue;
}
V_129 = V_91 [ V_86 ] . V_130 - V_126 ;
V_126 = 0 ;
V_128 ++ ;
if ( V_129 >= V_125 )
return V_128 ;
V_125 -= V_129 ;
}
}
return V_128 ;
}
void F_71 ( struct V_21 * V_22 , T_4 V_131 , struct V_120 * V_132 ,
T_4 V_133 )
{
struct V_23 * V_24 = F_20 ( V_22 ) ;
struct V_117 * V_118 = V_24 -> V_18 ;
struct V_119 * V_79 ;
struct V_120 * V_91 ;
unsigned int V_86 , V_134 = 0 ;
while ( ! F_67 ( & V_118 -> V_121 ) ) {
V_79 = F_72 ( & V_118 -> V_121 , struct V_119 ,
V_16 ) ;
V_91 = V_79 -> V_91 ;
for ( V_86 = 0 ; V_86 < V_79 -> V_123 ; V_86 ++ ) {
T_4 V_92 = F_47 ( T_4 , V_131 , V_91 [ V_86 ] . V_130 ) ;
struct V_135 * V_135 = F_73 ( V_91 + V_86 ) ;
if ( ! V_135 )
continue;
if ( V_132 ) {
if ( V_133 >= V_92 ) {
V_133 -= V_92 ;
} else {
F_74 ( V_135 ) ;
F_48 ( V_132 + V_134 , V_135 ,
V_92 - V_133 ,
V_91 [ V_86 ] . V_126 + V_133 ) ;
V_133 = 0 ;
V_134 ++ ;
}
}
V_91 [ V_86 ] . V_130 -= V_92 ;
V_91 [ V_86 ] . V_126 += V_92 ;
V_131 -= V_92 ;
V_118 -> V_131 -= V_92 ;
if ( V_91 [ V_86 ] . V_130 )
return;
F_54 ( V_135 ) ;
F_75 ( V_91 + V_86 , NULL ) ;
}
F_13 ( & V_79 -> V_16 ) ;
F_76 ( V_22 , V_79 , sizeof( * V_79 ) + sizeof( V_79 -> V_91 [ 0 ] ) *
( V_124 + 1 ) ) ;
}
if ( ! V_118 -> V_131 )
V_118 -> V_136 = 0 ;
}
void F_77 ( struct V_137 * V_138 )
{
struct V_21 * V_22 = V_138 -> V_22 ;
struct V_23 * V_24 = F_20 ( V_22 ) ;
struct V_117 * V_118 = V_24 -> V_18 ;
struct V_139 * V_140 , * V_127 ;
struct V_120 * V_141 ;
struct V_120 * V_91 ;
unsigned int V_86 ;
F_70 (rsgl, tmp, &areq->rsgl_list, list) {
V_118 -> V_142 -= V_140 -> V_143 ;
F_53 ( & V_140 -> V_79 ) ;
F_13 ( & V_140 -> V_16 ) ;
if ( V_140 != & V_138 -> V_144 )
F_76 ( V_22 , V_140 , sizeof( * V_140 ) ) ;
}
V_141 = V_138 -> V_141 ;
F_78 (tsgl, sg, areq->tsgl_entries, i) {
if ( ! F_73 ( V_91 ) )
continue;
F_54 ( F_73 ( V_91 ) ) ;
}
if ( V_138 -> V_141 && V_138 -> V_145 )
F_76 ( V_22 , V_141 , V_138 -> V_145 * sizeof( * V_141 ) ) ;
}
int F_79 ( struct V_21 * V_22 , unsigned int V_70 )
{
F_80 ( V_146 , V_147 ) ;
int V_8 = - V_148 ;
long V_149 ;
if ( V_70 & V_150 )
return - V_151 ;
F_81 ( V_152 , V_22 ) ;
F_82 ( F_83 ( V_22 ) , & V_146 ) ;
for (; ; ) {
if ( F_84 ( V_153 ) )
break;
V_149 = V_154 ;
if ( F_85 ( V_22 , & V_149 , F_86 ( V_22 ) , & V_146 ) ) {
V_8 = 0 ;
break;
}
}
F_87 ( F_83 ( V_22 ) , & V_146 ) ;
return V_8 ;
}
void F_88 ( struct V_21 * V_22 )
{
struct V_155 * V_156 ;
if ( ! F_86 ( V_22 ) )
return;
F_89 () ;
V_156 = F_90 ( V_22 -> V_157 ) ;
if ( F_91 ( V_156 ) )
F_92 ( & V_156 -> V_146 , V_158 |
V_159 |
V_160 ) ;
F_93 ( V_22 , V_161 , V_162 ) ;
F_94 () ;
}
int F_95 ( struct V_21 * V_22 , unsigned V_70 )
{
F_80 ( V_146 , V_147 ) ;
struct V_23 * V_24 = F_20 ( V_22 ) ;
struct V_117 * V_118 = V_24 -> V_18 ;
long V_149 ;
int V_8 = - V_148 ;
if ( V_70 & V_150 )
return - V_151 ;
F_81 ( V_163 , V_22 ) ;
F_82 ( F_83 ( V_22 ) , & V_146 ) ;
for (; ; ) {
if ( F_84 ( V_153 ) )
break;
V_149 = V_154 ;
if ( F_85 ( V_22 , & V_149 , ( V_118 -> V_131 || ! V_118 -> V_164 ) ,
& V_146 ) ) {
V_8 = 0 ;
break;
}
}
F_87 ( F_83 ( V_22 ) , & V_146 ) ;
F_96 ( V_163 , V_22 ) ;
return V_8 ;
}
void F_97 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_20 ( V_22 ) ;
struct V_117 * V_118 = V_24 -> V_18 ;
struct V_155 * V_156 ;
if ( ! V_118 -> V_131 )
return;
F_89 () ;
V_156 = F_90 ( V_22 -> V_157 ) ;
if ( F_91 ( V_156 ) )
F_92 ( & V_156 -> V_146 , V_165 |
V_159 |
V_160 ) ;
F_93 ( V_22 , V_166 , V_167 ) ;
F_94 () ;
}
int F_98 ( struct V_20 * V_21 , struct V_95 * V_96 , T_4 V_168 ,
unsigned int V_169 )
{
struct V_21 * V_22 = V_21 -> V_22 ;
struct V_23 * V_24 = F_20 ( V_22 ) ;
struct V_117 * V_118 = V_24 -> V_18 ;
struct V_119 * V_79 ;
struct V_97 V_98 = {} ;
long V_170 = 0 ;
bool V_171 = 0 ;
bool V_172 = 0 ;
int V_8 = 0 ;
if ( V_96 -> V_173 ) {
V_8 = F_55 ( V_96 , & V_98 ) ;
if ( V_8 )
return V_8 ;
V_172 = 1 ;
switch ( V_98 . V_108 ) {
case V_174 :
V_171 = 1 ;
break;
case V_175 :
V_171 = 0 ;
break;
default:
return - V_39 ;
}
if ( V_98 . V_105 && V_98 . V_105 -> V_106 != V_169 )
return - V_39 ;
}
F_21 ( V_22 ) ;
if ( ! V_118 -> V_164 && V_118 -> V_131 ) {
V_8 = - V_39 ;
goto V_10;
}
if ( V_172 ) {
V_118 -> V_171 = V_171 ;
if ( V_98 . V_105 )
memcpy ( V_118 -> V_105 , V_98 . V_105 -> V_105 , V_169 ) ;
V_118 -> V_110 = V_98 . V_110 ;
}
while ( V_168 ) {
struct V_120 * V_91 ;
T_4 V_82 = V_168 ;
T_4 V_92 ;
if ( V_118 -> V_136 ) {
V_79 = F_66 ( V_118 -> V_121 . V_122 ,
struct V_119 , V_16 ) ;
V_91 = V_79 -> V_91 + V_79 -> V_123 - 1 ;
V_82 = F_47 ( T_4 , V_82 ,
V_89 - V_91 -> V_126 - V_91 -> V_130 ) ;
V_8 = F_99 ( F_100 ( F_73 ( V_91 ) ) +
V_91 -> V_126 + V_91 -> V_130 ,
V_96 , V_82 ) ;
if ( V_8 )
goto V_10;
V_91 -> V_130 += V_82 ;
V_118 -> V_136 = ( V_91 -> V_126 + V_91 -> V_130 ) &
( V_89 - 1 ) ;
V_118 -> V_131 += V_82 ;
V_170 += V_82 ;
V_168 -= V_82 ;
continue;
}
if ( ! F_86 ( V_22 ) ) {
V_8 = F_79 ( V_22 , V_96 -> V_176 ) ;
if ( V_8 )
goto V_10;
}
V_82 = F_47 (unsigned long, len, af_alg_sndbuf(sk)) ;
V_8 = F_65 ( V_22 ) ;
if ( V_8 )
goto V_10;
V_79 = F_66 ( V_118 -> V_121 . V_122 , struct V_119 ,
V_16 ) ;
V_91 = V_79 -> V_91 ;
if ( V_79 -> V_123 )
F_51 ( V_91 + V_79 -> V_123 - 1 ) ;
do {
unsigned int V_86 = V_79 -> V_123 ;
V_92 = F_47 ( T_4 , V_82 , V_89 ) ;
F_75 ( V_91 + V_86 , F_101 ( V_11 ) ) ;
if ( ! F_73 ( V_91 + V_86 ) ) {
V_8 = - V_12 ;
goto V_10;
}
V_8 = F_99 ( F_100 ( F_73 ( V_91 + V_86 ) ) ,
V_96 , V_92 ) ;
if ( V_8 ) {
F_102 ( F_73 ( V_91 + V_86 ) ) ;
F_75 ( V_91 + V_86 , NULL ) ;
goto V_10;
}
V_91 [ V_86 ] . V_130 = V_92 ;
V_82 -= V_92 ;
V_118 -> V_131 += V_92 ;
V_170 += V_92 ;
V_168 -= V_92 ;
V_79 -> V_123 ++ ;
} while ( V_82 && V_79 -> V_123 < V_124 );
if ( ! V_168 )
F_49 ( V_91 + V_79 -> V_123 - 1 ) ;
V_118 -> V_136 = V_92 & ( V_89 - 1 ) ;
}
V_8 = 0 ;
V_118 -> V_164 = V_96 -> V_176 & V_177 ;
V_10:
F_97 ( V_22 ) ;
F_22 ( V_22 ) ;
return V_170 ? : V_8 ;
}
T_5 F_103 ( struct V_20 * V_21 , struct V_135 * V_135 ,
int V_126 , T_4 V_168 , int V_70 )
{
struct V_21 * V_22 = V_21 -> V_22 ;
struct V_23 * V_24 = F_20 ( V_22 ) ;
struct V_117 * V_118 = V_24 -> V_18 ;
struct V_119 * V_79 ;
int V_8 = - V_39 ;
if ( V_70 & V_178 )
V_70 |= V_177 ;
F_21 ( V_22 ) ;
if ( ! V_118 -> V_164 && V_118 -> V_131 )
goto V_10;
if ( ! V_168 )
goto V_179;
if ( ! F_86 ( V_22 ) ) {
V_8 = F_79 ( V_22 , V_70 ) ;
if ( V_8 )
goto V_10;
}
V_8 = F_65 ( V_22 ) ;
if ( V_8 )
goto V_10;
V_118 -> V_136 = 0 ;
V_79 = F_66 ( V_118 -> V_121 . V_122 , struct V_119 , V_16 ) ;
if ( V_79 -> V_123 )
F_51 ( V_79 -> V_91 + V_79 -> V_123 - 1 ) ;
F_49 ( V_79 -> V_91 + V_79 -> V_123 ) ;
F_74 ( V_135 ) ;
F_48 ( V_79 -> V_91 + V_79 -> V_123 , V_135 , V_168 , V_126 ) ;
V_79 -> V_123 ++ ;
V_118 -> V_131 += V_168 ;
V_179:
V_118 -> V_164 = V_70 & V_177 ;
V_10:
F_97 ( V_22 ) ;
F_22 ( V_22 ) ;
return V_8 ? : V_168 ;
}
void F_104 ( struct V_114 * V_180 , int V_8 )
{
struct V_137 * V_138 = V_180 -> V_116 ;
struct V_21 * V_22 = V_138 -> V_22 ;
struct V_181 * V_182 = V_138 -> V_182 ;
unsigned int V_183 ;
F_21 ( V_22 ) ;
V_183 = V_138 -> V_184 ;
F_77 ( V_138 ) ;
F_76 ( V_22 , V_138 , V_138 -> V_185 ) ;
F_105 ( V_22 ) ;
V_182 -> V_186 ( V_182 , V_8 ? V_8 : V_183 , 0 ) ;
F_22 ( V_22 ) ;
}
unsigned int F_106 ( struct V_187 * V_187 , struct V_20 * V_21 ,
T_6 * V_146 )
{
struct V_21 * V_22 = V_21 -> V_22 ;
struct V_23 * V_24 = F_20 ( V_22 ) ;
struct V_117 * V_118 = V_24 -> V_18 ;
unsigned int V_188 ;
F_107 ( V_187 , F_83 ( V_22 ) , V_146 ) ;
V_188 = 0 ;
if ( ! V_118 -> V_164 || V_118 -> V_131 )
V_188 |= V_158 | V_159 ;
if ( F_86 ( V_22 ) )
V_188 |= V_165 | V_189 | V_190 ;
return V_188 ;
}
struct V_137 * F_108 ( struct V_21 * V_22 ,
unsigned int V_185 )
{
struct V_137 * V_138 = F_29 ( V_22 , V_185 , V_11 ) ;
if ( F_109 ( ! V_138 ) )
return F_2 ( - V_12 ) ;
V_138 -> V_185 = V_185 ;
V_138 -> V_22 = V_22 ;
V_138 -> V_191 = NULL ;
F_110 ( & V_138 -> V_192 ) ;
V_138 -> V_141 = NULL ;
V_138 -> V_145 = 0 ;
return V_138 ;
}
int F_111 ( struct V_21 * V_22 , struct V_95 * V_96 , int V_70 ,
struct V_137 * V_138 , T_4 V_193 ,
T_4 * V_184 )
{
struct V_23 * V_24 = F_20 ( V_22 ) ;
struct V_117 * V_118 = V_24 -> V_18 ;
T_4 V_82 = 0 ;
while ( V_193 > V_82 && F_112 ( V_96 ) ) {
struct V_139 * V_140 ;
T_4 V_194 ;
int V_8 ;
if ( ! F_113 ( V_22 ) )
break;
if ( ! V_118 -> V_131 ) {
V_8 = F_95 ( V_22 , V_70 ) ;
if ( V_8 )
return V_8 ;
}
V_194 = F_47 ( T_4 , ( V_193 - V_82 ) ,
F_112 ( V_96 ) ) ;
if ( F_67 ( & V_138 -> V_192 ) ) {
V_140 = & V_138 -> V_144 ;
} else {
V_140 = F_29 ( V_22 , sizeof( * V_140 ) , V_11 ) ;
if ( F_109 ( ! V_140 ) )
return - V_12 ;
}
V_140 -> V_79 . V_85 = 0 ;
F_68 ( & V_140 -> V_16 , & V_138 -> V_192 ) ;
V_8 = F_43 ( & V_140 -> V_79 , & V_96 -> V_195 , V_194 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_138 -> V_191 )
F_50 ( & V_138 -> V_191 -> V_79 , & V_140 -> V_79 ) ;
V_138 -> V_191 = V_140 ;
V_82 += V_8 ;
V_118 -> V_142 += V_8 ;
V_140 -> V_143 = V_8 ;
F_114 ( & V_96 -> V_195 , V_8 ) ;
}
* V_184 = V_82 ;
return 0 ;
}
static int T_7 F_115 ( void )
{
int V_8 = F_116 ( & V_65 , 0 ) ;
if ( V_8 )
goto V_50;
V_8 = F_117 ( & V_196 ) ;
if ( V_8 != 0 )
goto V_197;
V_50:
return V_8 ;
V_197:
F_118 ( & V_65 ) ;
goto V_50;
}
static void T_8 F_119 ( void )
{
F_120 ( V_64 ) ;
F_118 ( & V_65 ) ;
}
