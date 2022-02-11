static unsigned int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = 0 ;
struct V_4 * V_5 ;
F_2 (tmp, dev) {
V_3 ++ ;
}
return V_3 ;
}
static inline T_1 *
F_3 ( struct V_6 * V_7 )
{
return ( T_1 * ) ( ( ( char * ) V_7 ) + V_7 -> V_8 ) ;
}
static inline struct V_9 *
F_4 ( struct V_6 * V_7 )
{
return (struct V_9 * ) ( ( ( char * ) V_7 ) + V_7 -> V_10 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_4 * V_11 )
{
const struct V_12 * V_13 = & V_2 -> V_14 ;
struct V_15 * V_7 ;
struct V_9 * V_16 ;
T_2 V_17 , V_18 , V_19 ;
struct V_6 * V_20 ;
unsigned int V_21 , V_22 ;
V_18 = sizeof( V_23 ) * V_11 -> V_24 ;
if ( F_6 ( ! V_18 ) ) {
return 0 ;
}
V_19 =
sizeof( struct V_9 ) * V_11 -> V_25 ;
V_17 = sizeof( struct V_6 ) ;
F_7 ( sizeof( struct V_6 ) % 8 ) ;
V_17 += F_8 ( V_18 , 8 ) ;
V_17 += V_19 ;
V_7 = F_9 ( V_2 , V_17 , NULL ) ;
if ( F_10 ( V_7 ) )
return - 1 ;
V_20 = (struct V_6 * ) V_7 -> V_26 ;
V_20 -> V_27 = V_28 ;
V_20 -> V_29 = V_11 -> V_24 ;
V_20 -> V_8 = sizeof( struct V_6 ) ;
V_20 -> V_30 = V_11 -> V_25 ;
V_20 -> V_10 =
F_8 ( V_20 -> V_8 + V_18 , 8 ) ;
memcpy ( F_3 ( V_20 ) , V_11 -> V_31 , V_18 ) ;
if ( ! V_11 -> V_32 -> V_33 )
goto V_34;
V_16 = F_4 ( V_20 ) ;
for ( V_21 = 0 ; V_21 < V_11 -> V_25 ; V_21 ++ ) {
for ( V_22 = 0 ; V_22 < V_11 -> V_24 ; V_22 ++ ) {
if ( V_11 -> V_32 -> V_33 ( V_11 ,
V_11 -> V_31 [ V_22 ] ,
V_11 -> V_35 [ V_21 ] ) ) {
V_16 -> V_36 |= 1ULL << V_22 ;
}
}
V_16 -> V_37 = V_11 -> V_35 [ V_21 ] ;
V_16 -> V_38 = 0 ;
V_16 -> V_39 = 0 ;
V_16 ++ ;
}
V_34:
F_11 ( & V_11 -> V_40 , V_13 -> V_41 ,
V_7 -> V_40 . V_42 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_4 * V_11 ,
T_3 V_43 ,
const struct V_44 * V_32 ,
const T_3 * V_36 , unsigned int V_24 ,
const T_4 * V_45 ,
enum V_46 type ,
const char * V_47 , ... )
{
struct V_12 * V_13 = & V_2 -> V_14 ;
unsigned int V_48 = 0 ;
int V_49 ;
V_49 = F_13 ( V_2 , & V_11 -> V_40 , V_50 ) ;
if ( V_49 )
return V_49 ;
F_14 ( & V_11 -> V_51 ) ;
V_11 -> V_40 . V_52 = & V_11 -> V_52 ;
V_11 -> V_2 = V_2 ;
V_11 -> V_32 = V_32 ;
V_11 -> V_31 = F_15 ( V_24 , sizeof( T_3 ) ,
V_53 ) ;
if ( ! V_11 -> V_31 ) {
F_16 ( L_1 ) ;
F_17 ( V_2 , & V_11 -> V_40 ) ;
return - V_54 ;
}
if ( F_6 ( V_24 > 64 ) )
return - V_55 ;
if ( V_45 ) {
const T_4 * V_56 = V_45 ;
while ( * V_56 ++ != V_57 )
V_48 ++ ;
}
V_11 -> V_25 = V_48 ;
V_11 -> V_35 = F_15 ( V_48 ,
sizeof( V_45 [ 0 ] ) ,
V_53 ) ;
if ( V_48 && ! V_11 -> V_35 ) {
F_16 ( L_1 ) ;
F_18 ( V_11 -> V_31 ) ;
F_17 ( V_2 , & V_11 -> V_40 ) ;
return - V_54 ;
}
if ( V_47 ) {
T_5 V_58 ;
va_start ( V_58 , V_47 ) ;
V_11 -> V_47 = F_19 ( V_53 , V_47 , V_58 ) ;
va_end ( V_58 ) ;
} else {
V_11 -> V_47 = F_20 ( V_53 , L_2 ,
F_1 ( V_2 ) ) ;
}
if ( ! V_11 -> V_47 ) {
F_18 ( V_11 -> V_31 ) ;
F_18 ( V_11 -> V_35 ) ;
F_17 ( V_2 , & V_11 -> V_40 ) ;
return - V_54 ;
}
memcpy ( V_11 -> V_31 , V_36 , V_24 * sizeof( T_3 ) ) ;
V_11 -> V_24 = V_24 ;
memcpy ( V_11 -> V_35 , V_45 ,
V_48 * sizeof( V_45 [ 0 ] ) ) ;
V_11 -> V_43 = V_43 ;
V_11 -> type = type ;
F_21 ( & V_11 -> V_59 , & V_13 -> V_60 ) ;
V_11 -> V_61 = V_13 -> V_62 ++ ;
if ( V_11 -> type == V_63 )
V_13 -> V_64 ++ ;
F_11 ( & V_11 -> V_40 ,
V_13 -> V_65 ,
V_11 -> type ) ;
if ( F_22 ( V_2 , V_66 ) ) {
F_11 ( & V_11 -> V_40 , V_13 -> V_67 , 0 ) ;
F_11 ( & V_11 -> V_40 , V_13 -> V_68 , - 1 ) ;
F_11 ( & V_11 -> V_40 , V_13 -> V_69 , 0 ) ;
F_11 ( & V_11 -> V_40 , V_13 -> V_70 , 0 ) ;
F_11 ( & V_11 -> V_40 , V_13 -> V_71 , 0 ) ;
F_11 ( & V_11 -> V_40 , V_13 -> V_72 , 0 ) ;
F_11 ( & V_11 -> V_40 , V_13 -> V_73 , 0 ) ;
F_11 ( & V_11 -> V_40 , V_13 -> V_74 , 0 ) ;
F_11 ( & V_11 -> V_40 , V_13 -> V_75 , 0 ) ;
F_11 ( & V_11 -> V_40 , V_13 -> V_76 , 0 ) ;
F_11 ( & V_11 -> V_40 , V_13 -> V_77 , 0 ) ;
}
if ( V_13 -> V_78 )
F_5 ( V_2 , V_11 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_4 * V_11 ;
int V_49 = 0 ;
F_2 (plane, dev) {
if ( V_11 -> V_32 -> V_79 )
V_49 = V_11 -> V_32 -> V_79 ( V_11 ) ;
if ( V_49 )
return V_49 ;
}
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_11 ;
F_2 (plane, dev) {
if ( V_11 -> V_32 -> V_80 )
V_11 -> V_32 -> V_80 ( V_11 ) ;
}
}
int F_25 ( struct V_1 * V_2 , struct V_4 * V_11 ,
T_3 V_43 ,
const struct V_44 * V_32 ,
const T_3 * V_36 , unsigned int V_24 ,
bool V_81 )
{
enum V_46 type ;
type = V_81 ? V_82 : V_63 ;
return F_12 ( V_2 , V_11 , V_43 , V_32 ,
V_36 , V_24 ,
NULL , type , NULL ) ;
}
void F_26 ( struct V_4 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
F_27 ( & V_11 -> V_51 ) ;
F_18 ( V_11 -> V_31 ) ;
F_18 ( V_11 -> V_35 ) ;
F_17 ( V_2 , & V_11 -> V_40 ) ;
F_28 ( F_29 ( & V_11 -> V_59 ) ) ;
F_30 ( & V_11 -> V_59 ) ;
V_2 -> V_14 . V_62 -- ;
if ( V_11 -> type == V_63 )
V_2 -> V_14 . V_64 -- ;
F_6 ( V_11 -> V_83 && ! V_11 -> V_32 -> V_84 ) ;
if ( V_11 -> V_83 && V_11 -> V_32 -> V_84 )
V_11 -> V_32 -> V_84 ( V_11 , V_11 -> V_83 ) ;
F_18 ( V_11 -> V_47 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
}
struct V_4 *
F_31 ( struct V_1 * V_2 , int V_85 )
{
struct V_4 * V_11 ;
F_2 (plane, dev)
if ( V_85 == V_11 -> V_61 )
return V_11 ;
return NULL ;
}
void F_32 ( struct V_4 * V_11 )
{
int V_49 ;
if ( ! V_11 -> V_86 )
return;
F_6 ( F_33 ( V_11 -> V_2 ) ) ;
V_11 -> V_87 = V_11 -> V_86 ;
V_49 = V_11 -> V_32 -> V_88 ( V_11 , NULL ) ;
if ( V_49 ) {
F_34 ( L_3 ) ;
V_11 -> V_87 = NULL ;
return;
}
F_35 ( V_11 -> V_87 ) ;
V_11 -> V_87 = NULL ;
V_11 -> V_86 = NULL ;
V_11 -> V_89 = NULL ;
}
int F_36 ( struct V_4 * V_11 ,
struct V_90 * V_91 ,
T_4 V_92 )
{
int V_49 = - V_55 ;
struct V_93 * V_94 = & V_11 -> V_40 ;
if ( V_11 -> V_32 -> V_95 )
V_49 = V_11 -> V_32 -> V_95 ( V_11 , V_91 , V_92 ) ;
if ( ! V_49 )
F_37 ( V_94 , V_91 , V_92 ) ;
return V_49 ;
}
int F_38 ( struct V_1 * V_2 , void * V_26 ,
struct V_96 * V_97 )
{
struct V_98 * V_99 = V_26 ;
struct V_12 * V_13 ;
struct V_4 * V_11 ;
T_3 T_6 * V_100 ;
int V_101 = 0 ;
unsigned V_102 ;
if ( ! F_22 ( V_2 , V_103 ) )
return - V_55 ;
V_13 = & V_2 -> V_14 ;
if ( V_97 -> V_104 )
V_102 = V_13 -> V_62 ;
else
V_102 = V_13 -> V_64 ;
if ( V_102 &&
( V_99 -> V_105 >= V_102 ) ) {
V_100 = ( T_3 T_6 * ) ( unsigned long ) V_99 -> V_106 ;
F_2 (plane, dev) {
if ( V_11 -> type != V_63 &&
! V_97 -> V_104 )
continue;
if ( F_39 ( V_11 -> V_40 . V_42 , V_100 + V_101 ) )
return - V_107 ;
V_101 ++ ;
}
}
V_99 -> V_105 = V_102 ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 , void * V_26 ,
struct V_96 * V_97 )
{
struct V_108 * V_99 = V_26 ;
struct V_4 * V_11 ;
T_3 T_6 * V_109 ;
if ( ! F_22 ( V_2 , V_103 ) )
return - V_55 ;
V_11 = F_41 ( V_2 , V_99 -> V_110 ) ;
if ( ! V_11 )
return - V_111 ;
F_42 ( & V_11 -> V_51 , NULL ) ;
if ( V_11 -> V_83 && V_11 -> V_83 -> V_89 )
V_99 -> V_112 = V_11 -> V_83 -> V_89 -> V_40 . V_42 ;
else if ( ! V_11 -> V_83 && V_11 -> V_89 )
V_99 -> V_112 = V_11 -> V_89 -> V_40 . V_42 ;
else
V_99 -> V_112 = 0 ;
if ( V_11 -> V_83 && V_11 -> V_83 -> V_86 )
V_99 -> V_113 = V_11 -> V_83 -> V_86 -> V_40 . V_42 ;
else if ( ! V_11 -> V_83 && V_11 -> V_86 )
V_99 -> V_113 = V_11 -> V_86 -> V_40 . V_42 ;
else
V_99 -> V_113 = 0 ;
F_43 ( & V_11 -> V_51 ) ;
V_99 -> V_110 = V_11 -> V_40 . V_42 ;
V_99 -> V_43 = V_11 -> V_43 ;
V_99 -> V_114 = 0 ;
if ( V_11 -> V_24 &&
( V_99 -> V_115 >= V_11 -> V_24 ) ) {
V_109 = ( T_3 T_6 * ) ( unsigned long ) V_99 -> V_116 ;
if ( F_44 ( V_109 ,
V_11 -> V_31 ,
sizeof( T_3 ) * V_11 -> V_24 ) ) {
return - V_107 ;
}
}
V_99 -> V_115 = V_11 -> V_24 ;
return 0 ;
}
int F_45 ( const struct V_4 * V_11 , T_1 V_117 )
{
unsigned int V_21 ;
for ( V_21 = 0 ; V_21 < V_11 -> V_24 ; V_21 ++ ) {
if ( V_117 == V_11 -> V_31 [ V_21 ] )
return 0 ;
}
return - V_55 ;
}
static int F_46 ( struct V_4 * V_11 ,
struct V_118 * V_89 ,
struct V_119 * V_86 ,
T_7 V_120 , T_7 V_121 ,
T_3 V_122 , T_3 V_123 ,
T_3 V_124 , T_3 V_125 ,
T_3 V_126 , T_3 V_127 ,
struct V_128 * V_129 )
{
int V_49 = 0 ;
if ( ! V_86 ) {
V_11 -> V_87 = V_11 -> V_86 ;
V_49 = V_11 -> V_32 -> V_88 ( V_11 , V_129 ) ;
if ( ! V_49 ) {
V_11 -> V_89 = NULL ;
V_11 -> V_86 = NULL ;
} else {
V_11 -> V_87 = NULL ;
}
goto V_130;
}
if ( ! ( V_11 -> V_43 & F_47 ( V_89 ) ) ) {
F_16 ( L_4 ) ;
V_49 = - V_55 ;
goto V_130;
}
V_49 = F_45 ( V_11 , V_86 -> V_117 -> V_117 ) ;
if ( V_49 ) {
struct V_131 V_132 ;
F_16 ( L_5 ,
F_48 ( V_86 -> V_117 -> V_117 ,
& V_132 ) ) ;
goto V_130;
}
if ( V_122 > V_133 ||
V_120 > V_133 - ( T_7 ) V_122 ||
V_123 > V_133 ||
V_121 > V_133 - ( T_7 ) V_123 ) {
F_16 ( L_6 ,
V_122 , V_123 , V_120 , V_121 ) ;
V_49 = - V_134 ;
goto V_130;
}
V_49 = F_49 ( V_124 , V_125 , V_126 , V_127 , V_86 ) ;
if ( V_49 )
goto V_130;
V_11 -> V_87 = V_11 -> V_86 ;
V_49 = V_11 -> V_32 -> V_135 ( V_11 , V_89 , V_86 ,
V_120 , V_121 , V_122 , V_123 ,
V_124 , V_125 , V_126 , V_127 , V_129 ) ;
if ( ! V_49 ) {
V_11 -> V_89 = V_89 ;
V_11 -> V_86 = V_86 ;
V_86 = NULL ;
} else {
V_11 -> V_87 = NULL ;
}
V_130:
if ( V_86 )
F_35 ( V_86 ) ;
if ( V_11 -> V_87 )
F_35 ( V_11 -> V_87 ) ;
V_11 -> V_87 = NULL ;
return V_49 ;
}
static int F_50 ( struct V_4 * V_11 ,
struct V_118 * V_89 ,
struct V_119 * V_86 ,
T_7 V_120 , T_7 V_121 ,
T_3 V_122 , T_3 V_123 ,
T_3 V_124 , T_3 V_125 ,
T_3 V_126 , T_3 V_127 )
{
struct V_128 V_129 ;
int V_49 ;
F_51 ( & V_129 , 0 ) ;
V_136:
V_49 = F_52 ( V_11 -> V_2 , & V_129 ) ;
if ( V_49 )
goto V_137;
V_49 = F_46 ( V_11 , V_89 , V_86 ,
V_120 , V_121 , V_122 , V_123 ,
V_124 , V_125 , V_126 , V_127 , & V_129 ) ;
V_137:
if ( V_49 == - V_138 ) {
F_53 ( & V_129 ) ;
goto V_136;
}
F_54 ( & V_129 ) ;
F_55 ( & V_129 ) ;
return V_49 ;
}
int F_56 ( struct V_1 * V_2 , void * V_26 ,
struct V_96 * V_97 )
{
struct V_139 * V_140 = V_26 ;
struct V_4 * V_11 ;
struct V_118 * V_89 = NULL ;
struct V_119 * V_86 = NULL ;
if ( ! F_22 ( V_2 , V_103 ) )
return - V_55 ;
V_11 = F_41 ( V_2 , V_140 -> V_110 ) ;
if ( ! V_11 ) {
F_16 ( L_7 ,
V_140 -> V_110 ) ;
return - V_111 ;
}
if ( V_140 -> V_113 ) {
V_86 = F_57 ( V_2 , V_140 -> V_113 ) ;
if ( ! V_86 ) {
F_16 ( L_8 ,
V_140 -> V_113 ) ;
return - V_111 ;
}
V_89 = F_58 ( V_2 , V_140 -> V_112 ) ;
if ( ! V_89 ) {
F_35 ( V_86 ) ;
F_16 ( L_9 ,
V_140 -> V_112 ) ;
return - V_111 ;
}
}
return F_50 ( V_11 , V_89 , V_86 ,
V_140 -> V_120 , V_140 -> V_121 ,
V_140 -> V_122 , V_140 -> V_123 ,
V_140 -> V_124 , V_140 -> V_125 ,
V_140 -> V_126 , V_140 -> V_127 ) ;
}
static int F_59 ( struct V_118 * V_89 ,
struct V_141 * V_142 ,
struct V_96 * V_97 ,
struct V_128 * V_129 )
{
struct V_1 * V_2 = V_89 -> V_2 ;
struct V_119 * V_86 = NULL ;
struct V_143 V_144 = {
. V_145 = V_142 -> V_145 ,
. V_146 = V_142 -> V_146 ,
. V_147 = V_148 ,
. V_149 = { V_142 -> V_145 * 4 } ,
. V_150 = { V_142 -> V_151 } ,
} ;
T_7 V_120 , V_121 ;
T_3 V_122 = 0 , V_123 = 0 ;
T_3 V_126 = 0 , V_127 = 0 ;
int V_49 = 0 ;
F_28 ( ! V_89 -> V_152 ) ;
F_6 ( V_89 -> V_152 -> V_89 != V_89 && V_89 -> V_152 -> V_89 != NULL ) ;
if ( V_142 -> V_153 & V_154 ) {
if ( V_142 -> V_151 ) {
V_86 = F_60 ( V_2 , & V_144 , V_97 ) ;
if ( F_10 ( V_86 ) ) {
F_16 ( L_10 ) ;
return F_61 ( V_86 ) ;
}
V_86 -> V_155 = V_142 -> V_155 ;
V_86 -> V_156 = V_142 -> V_156 ;
} else {
V_86 = NULL ;
}
} else {
V_86 = V_89 -> V_152 -> V_86 ;
if ( V_86 )
F_62 ( V_86 ) ;
}
if ( V_142 -> V_153 & V_157 ) {
V_120 = V_142 -> V_158 ;
V_121 = V_142 -> V_159 ;
} else {
V_120 = V_89 -> V_160 ;
V_121 = V_89 -> V_161 ;
}
if ( V_86 ) {
V_122 = V_86 -> V_145 ;
V_123 = V_86 -> V_146 ;
V_126 = V_86 -> V_145 << 16 ;
V_127 = V_86 -> V_146 << 16 ;
}
V_49 = F_46 ( V_89 -> V_152 , V_89 , V_86 ,
V_120 , V_121 , V_122 , V_123 ,
0 , 0 , V_126 , V_127 , V_129 ) ;
if ( V_49 == 0 && V_142 -> V_153 & V_157 ) {
V_89 -> V_160 = V_142 -> V_158 ;
V_89 -> V_161 = V_142 -> V_159 ;
}
return V_49 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
struct V_96 * V_97 )
{
struct V_118 * V_89 ;
struct V_128 V_129 ;
int V_49 = 0 ;
if ( ! F_22 ( V_2 , V_103 ) )
return - V_55 ;
if ( ! V_142 -> V_153 || ( ~ V_162 & V_142 -> V_153 ) )
return - V_55 ;
V_89 = F_58 ( V_2 , V_142 -> V_112 ) ;
if ( ! V_89 ) {
F_16 ( L_11 , V_142 -> V_112 ) ;
return - V_111 ;
}
F_51 ( & V_129 , 0 ) ;
V_136:
V_49 = F_42 ( & V_89 -> V_51 , & V_129 ) ;
if ( V_49 )
goto V_130;
if ( V_89 -> V_152 ) {
V_49 = F_42 ( & V_89 -> V_152 -> V_51 , & V_129 ) ;
if ( V_49 )
goto V_130;
V_49 = F_59 ( V_89 , V_142 , V_97 , & V_129 ) ;
goto V_130;
}
if ( V_142 -> V_153 & V_154 ) {
if ( ! V_89 -> V_32 -> V_163 && ! V_89 -> V_32 -> V_164 ) {
V_49 = - V_165 ;
goto V_130;
}
if ( V_89 -> V_32 -> V_164 )
V_49 = V_89 -> V_32 -> V_164 ( V_89 , V_97 , V_142 -> V_151 ,
V_142 -> V_145 , V_142 -> V_146 , V_142 -> V_155 , V_142 -> V_156 ) ;
else
V_49 = V_89 -> V_32 -> V_163 ( V_89 , V_97 , V_142 -> V_151 ,
V_142 -> V_145 , V_142 -> V_146 ) ;
}
if ( V_142 -> V_153 & V_157 ) {
if ( V_89 -> V_32 -> V_166 ) {
V_49 = V_89 -> V_32 -> V_166 ( V_89 , V_142 -> V_158 , V_142 -> V_159 ) ;
} else {
V_49 = - V_107 ;
goto V_130;
}
}
V_130:
if ( V_49 == - V_138 ) {
F_53 ( & V_129 ) ;
goto V_136;
}
F_54 ( & V_129 ) ;
F_55 ( & V_129 ) ;
return V_49 ;
}
int F_64 ( struct V_1 * V_2 ,
void * V_26 , struct V_96 * V_97 )
{
struct V_167 * V_142 = V_26 ;
struct V_141 V_168 ;
memcpy ( & V_168 , V_142 , sizeof( struct V_167 ) ) ;
V_168 . V_155 = V_168 . V_156 = 0 ;
return F_63 ( V_2 , & V_168 , V_97 ) ;
}
int F_65 ( struct V_1 * V_2 ,
void * V_26 , struct V_96 * V_97 )
{
struct V_141 * V_142 = V_26 ;
return F_63 ( V_2 , V_142 , V_97 ) ;
}
int F_66 ( struct V_1 * V_2 ,
void * V_26 , struct V_96 * V_97 )
{
struct V_169 * V_170 = V_26 ;
struct V_118 * V_89 ;
struct V_119 * V_86 = NULL ;
struct V_171 * V_172 = NULL ;
T_1 V_173 = V_170 -> V_174 ;
struct V_128 V_129 ;
int V_49 = - V_55 ;
if ( ! F_22 ( V_2 , V_103 ) )
return - V_55 ;
if ( V_170 -> V_153 & ~ V_175 )
return - V_55 ;
if ( V_170 -> V_174 != 0 && ! ( V_170 -> V_153 & V_176 ) )
return - V_55 ;
if ( ( V_170 -> V_153 & V_176 ) == V_176 )
return - V_55 ;
if ( ( V_170 -> V_153 & V_177 ) && ! V_2 -> V_14 . V_178 )
return - V_55 ;
V_89 = F_58 ( V_2 , V_170 -> V_112 ) ;
if ( ! V_89 )
return - V_111 ;
if ( V_89 -> V_32 -> V_179 ) {
T_1 V_180 ;
int V_181 ;
V_181 = F_67 ( V_89 ) ;
if ( V_181 )
return V_181 ;
V_180 = F_68 ( V_89 ) ;
switch ( V_170 -> V_153 & V_176 ) {
case V_182 :
if ( ( int ) ( V_173 - V_180 ) > 1 ) {
F_69 ( L_12
L_13 , V_173 ,
V_180 + 1 ) ;
F_70 ( V_89 ) ;
return - V_55 ;
}
break;
case V_183 :
if ( V_173 != 0 && V_173 != 1 ) {
F_69 ( L_14
L_15 , V_173 ) ;
F_70 ( V_89 ) ;
return - V_55 ;
}
V_173 += V_180 ;
break;
default:
V_173 = V_180 +
! ( V_170 -> V_153 & V_177 ) ;
break;
}
} else if ( V_89 -> V_32 -> V_170 == NULL ||
( V_170 -> V_153 & V_176 ) ) {
return - V_55 ;
}
F_51 ( & V_129 , 0 ) ;
V_136:
V_49 = F_42 ( & V_89 -> V_51 , & V_129 ) ;
if ( V_49 )
goto V_130;
V_49 = F_42 ( & V_89 -> V_184 -> V_51 , & V_129 ) ;
if ( V_49 )
goto V_130;
if ( V_89 -> V_184 -> V_86 == NULL ) {
V_49 = - V_185 ;
goto V_130;
}
V_86 = F_57 ( V_2 , V_170 -> V_113 ) ;
if ( ! V_86 ) {
V_49 = - V_111 ;
goto V_130;
}
if ( V_89 -> V_83 ) {
const struct V_186 * V_83 = V_89 -> V_184 -> V_83 ;
V_49 = F_49 ( V_83 -> V_124 ,
V_83 -> V_125 ,
V_83 -> V_126 ,
V_83 -> V_127 ,
V_86 ) ;
} else {
V_49 = F_71 ( V_89 , V_89 -> V_158 , V_89 -> V_159 , & V_89 -> V_187 , V_86 ) ;
}
if ( V_49 )
goto V_130;
if ( V_89 -> V_184 -> V_86 -> V_117 != V_86 -> V_117 ) {
F_16 ( L_16 ) ;
V_49 = - V_55 ;
goto V_130;
}
if ( V_170 -> V_153 & V_188 ) {
V_172 = F_72 ( sizeof *V_172 , V_53 ) ;
if ( ! V_172 ) {
V_49 = - V_54 ;
goto V_130;
}
V_172 -> V_189 . V_40 . type = V_190 ;
V_172 -> V_189 . V_40 . V_191 = sizeof( V_172 -> V_189 ) ;
V_172 -> V_189 . V_192 = V_170 -> V_192 ;
V_49 = F_73 ( V_2 , V_97 , & V_172 -> V_40 , & V_172 -> V_189 . V_40 ) ;
if ( V_49 ) {
F_18 ( V_172 ) ;
V_172 = NULL ;
goto V_130;
}
}
V_89 -> V_184 -> V_87 = V_89 -> V_184 -> V_86 ;
if ( V_89 -> V_32 -> V_179 )
V_49 = V_89 -> V_32 -> V_179 ( V_89 , V_86 , V_172 ,
V_170 -> V_153 ,
V_173 ,
& V_129 ) ;
else
V_49 = V_89 -> V_32 -> V_170 ( V_89 , V_86 , V_172 , V_170 -> V_153 ,
& V_129 ) ;
if ( V_49 ) {
if ( V_170 -> V_153 & V_188 )
F_74 ( V_2 , & V_172 -> V_40 ) ;
V_89 -> V_184 -> V_87 = NULL ;
} else {
V_89 -> V_184 -> V_86 = V_86 ;
V_86 = NULL ;
}
V_130:
if ( V_86 )
F_35 ( V_86 ) ;
if ( V_89 -> V_184 -> V_87 )
F_35 ( V_89 -> V_184 -> V_87 ) ;
V_89 -> V_184 -> V_87 = NULL ;
if ( V_49 == - V_138 ) {
F_53 ( & V_129 ) ;
goto V_136;
}
F_54 ( & V_129 ) ;
F_55 ( & V_129 ) ;
if ( V_49 && V_89 -> V_32 -> V_179 )
F_70 ( V_89 ) ;
return V_49 ;
}
