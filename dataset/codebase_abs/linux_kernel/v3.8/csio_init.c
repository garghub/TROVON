static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
V_2 -> V_3 = V_1 -> V_4 ;
return 0 ;
}
static T_1
F_2 ( struct V_2 * V_2 , char T_2 * V_5 , T_3 V_6 , T_4 * V_7 )
{
T_4 V_8 = * V_7 ;
T_4 V_9 = V_2 -> V_10 . V_11 -> V_12 -> V_13 ;
unsigned int V_14 = ( V_15 ) V_2 -> V_3 & 3 ;
struct V_16 * V_17 = V_2 -> V_3 - V_14 ;
if ( V_8 < 0 )
return - V_18 ;
if ( V_8 >= V_9 )
return 0 ;
if ( V_6 > V_9 - V_8 )
V_6 = V_9 - V_8 ;
while ( V_6 ) {
T_3 V_19 ;
int V_20 , V_21 ;
T_5 V_22 [ 16 ] ;
if ( V_14 == V_23 )
V_20 = F_3 ( V_17 , V_8 , V_22 , NULL ) ;
else
V_20 = F_4 ( V_17 , V_14 , V_8 , V_22 , NULL ) ;
if ( V_20 )
return V_20 ;
V_21 = V_8 % sizeof( V_22 ) ;
V_19 = F_5 ( V_6 , sizeof( V_22 ) - V_21 ) ;
if ( F_6 ( V_5 , ( V_24 * ) V_22 + V_21 , V_19 ) )
return - V_25 ;
V_5 += V_19 ;
V_8 += V_19 ;
V_6 -= V_19 ;
}
V_6 = V_8 - * V_7 ;
* V_7 = V_8 ;
return V_6 ;
}
static void F_7 ( struct V_16 * V_17 , const char * V_26 ,
unsigned int V_27 , unsigned int V_28 )
{
struct V_11 * V_29 ;
V_29 = F_8 ( V_26 , V_30 , V_17 -> V_31 ,
( void * ) V_17 + V_27 , & V_32 ) ;
if ( V_29 && V_29 -> V_12 )
V_29 -> V_12 -> V_13 = V_28 << 20 ;
}
static int F_9 ( struct V_16 * V_17 )
{
int V_33 ;
if ( F_10 ( V_17 -> V_31 ) )
return - 1 ;
V_33 = F_11 ( V_17 , V_34 ) ;
if ( V_33 & V_35 )
F_7 ( V_17 , L_1 , V_36 , 5 ) ;
if ( V_33 & V_37 )
F_7 ( V_17 , L_2 , V_38 , 5 ) ;
if ( V_33 & V_39 )
F_7 ( V_17 , L_3 , V_23 ,
F_12 ( F_11 ( V_17 , V_40 ) ) ) ;
return 0 ;
}
static int
F_13 ( struct V_16 * V_17 )
{
if ( V_41 ) {
V_17 -> V_31 = F_14 ( F_15 ( V_17 -> V_42 ) ,
V_41 ) ;
F_9 ( V_17 ) ;
}
return 0 ;
}
static int
F_16 ( struct V_16 * V_17 )
{
if ( V_17 -> V_31 )
F_17 ( V_17 -> V_31 ) ;
return 0 ;
}
static int
F_18 ( void )
{
V_41 = F_14 ( V_43 , NULL ) ;
if ( ! V_41 )
F_19 ( L_4 ) ;
return 0 ;
}
static void
F_20 ( void )
{
F_21 ( V_41 ) ;
}
static int
F_22 ( struct V_44 * V_42 , int * V_45 )
{
int V_46 = - V_47 ;
* V_45 = F_23 ( V_42 , V_48 ) ;
if ( F_24 ( V_42 ) )
goto V_49;
if ( F_25 ( V_42 , * V_45 , V_43 ) )
goto V_50;
F_26 ( V_42 ) ;
F_27 ( V_42 ) ;
if ( ! F_28 ( V_42 , F_29 ( 64 ) ) ) {
F_30 ( V_42 , F_29 ( 64 ) ) ;
} else if ( ! F_28 ( V_42 , F_29 ( 32 ) ) ) {
F_30 ( V_42 , F_29 ( 32 ) ) ;
} else {
F_31 ( & V_42 -> V_51 , L_5 ) ;
goto V_52;
}
return 0 ;
V_52:
F_32 ( V_42 , * V_45 ) ;
V_50:
F_33 ( V_42 ) ;
V_49:
return V_46 ;
}
static void
F_34 ( struct V_44 * V_42 , int * V_45 )
{
F_32 ( V_42 , * V_45 ) ;
F_33 ( V_42 ) ;
}
static void
F_35 ( struct V_16 * V_17 )
{
F_36 ( & V_17 -> V_53 , V_54 ) ;
}
static void
F_37 ( struct V_16 * V_17 )
{
F_38 ( & V_17 -> V_53 ) ;
F_39 () ;
}
static int
F_40 ( struct V_16 * V_17 )
{
int V_33 , V_55 ;
struct V_56 * V_57 = F_41 ( V_17 ) ;
int V_46 ;
struct V_58 * V_59 ;
if ( V_17 -> V_60 & V_61 )
return 0 ;
if ( V_17 -> V_62 != V_63 ) {
V_46 = F_42 ( V_17 , NULL , V_17 -> V_64 ,
0 , V_17 -> V_65 [ 0 ] . V_66 , false , NULL ) ;
if ( V_46 != 0 ) {
F_43 ( V_17 , L_6 , V_46 ) ;
return V_46 ;
}
}
V_46 = F_42 ( V_17 , NULL , V_17 -> V_67 ,
F_44 ( V_17 ) ,
V_17 -> V_65 [ 0 ] . V_66 , true , NULL ) ;
if ( V_46 != 0 ) {
F_43 ( V_17 , L_7 , V_46 ) ;
return V_46 ;
}
V_46 = F_45 ( V_17 , NULL , V_57 -> V_68 ,
V_57 -> V_69 , V_17 -> V_65 [ 0 ] . V_66 , NULL ) ;
if ( V_46 != 0 ) {
F_43 ( V_17 , L_8 , V_46 ) ;
goto V_49;
}
for ( V_33 = 0 ; V_33 < V_17 -> V_70 ; V_33 ++ ) {
V_59 = & V_17 -> V_71 [ V_33 ] ;
for ( V_55 = 0 ; V_55 < V_59 -> V_72 ; V_55 ++ ) {
struct V_73 * V_74 = & V_17 -> V_74 [ V_33 ] [ V_55 ] ;
V_46 = F_42 ( V_17 , NULL , V_74 -> V_69 ,
V_74 -> V_75 , V_33 , false , NULL ) ;
if ( V_46 != 0 ) {
F_43 ( V_17 ,
L_9 ,
V_33 , V_55 , V_46 ) ;
goto V_49;
}
V_46 = F_45 ( V_17 , NULL , V_74 -> V_68 ,
V_74 -> V_69 , V_33 , NULL ) ;
if ( V_46 != 0 ) {
F_43 ( V_17 ,
L_10 ,
V_33 , V_55 , V_46 ) ;
goto V_49;
}
}
}
V_17 -> V_60 |= V_61 ;
return 0 ;
V_49:
F_46 ( V_17 , true ) ;
return - V_18 ;
}
int
F_47 ( struct V_16 * V_17 )
{
int V_33 , V_55 , V_27 , V_76 = 0 ;
int V_46 ;
struct V_73 * V_74 ;
struct V_56 * V_57 = F_41 ( V_17 ) ;
struct V_73 * V_77 ;
struct V_58 * V_59 ;
if ( V_17 -> V_60 & V_78 )
return F_40 ( V_17 ) ;
V_17 -> V_79 = F_48 () ;
V_17 -> V_80 = F_48 () * V_17 -> V_70 ;
if ( V_17 -> V_80 > V_81 ) {
V_17 -> V_80 = V_81 ;
V_17 -> V_79 = V_82 ;
}
for ( V_33 = 0 ; V_33 < V_17 -> V_70 ; V_33 ++ )
V_17 -> V_71 [ V_33 ] . V_72 = V_17 -> V_79 ;
F_49 ( V_17 , L_11 ,
V_17 -> V_80 , V_17 -> V_79 ) ;
F_50 ( V_17 ) ;
if ( V_17 -> V_62 != V_63 ) {
V_17 -> V_64 = F_51 ( V_17 , V_83 ,
V_84 , V_85 ,
( void * ) V_17 , 0 , 0 , NULL ) ;
if ( V_17 -> V_64 == - 1 ) {
F_43 ( V_17 ,
L_12 ) ;
goto V_86;
}
}
V_17 -> V_67 = F_51 ( V_17 , V_87 ,
V_88 ,
V_85 , ( void * ) V_17 ,
V_89 , 0 ,
V_90 ) ;
if ( V_17 -> V_67 == - 1 ) {
F_43 ( V_17 , L_13 ) ;
goto V_86;
}
V_57 -> V_68 = F_51 ( V_17 , V_91 ,
V_92 ,
V_93 , ( void * ) V_17 , 0 , 0 , NULL ) ;
if ( V_57 -> V_68 == - 1 ) {
F_43 ( V_17 , L_14 ) ;
goto V_86;
}
V_57 -> V_69 = V_17 -> V_67 ;
for ( V_33 = 0 ; V_33 < V_17 -> V_70 ; V_33 ++ ) {
V_59 = & V_17 -> V_71 [ V_33 ] ;
for ( V_55 = 0 ; V_55 < V_17 -> V_79 ; V_55 ++ ) {
V_74 = & V_17 -> V_74 [ V_33 ] [ V_55 ] ;
if ( V_55 >= V_59 -> V_72 ) {
V_76 = V_55 % V_59 -> V_72 ;
V_77 = & V_17 -> V_74 [ V_33 ] [ V_76 ] ;
V_74 -> V_68 = V_77 -> V_68 ;
V_74 -> V_69 = V_77 -> V_69 ;
continue;
}
V_27 = F_51 ( V_17 , V_94 , 0 ,
V_93 , ( void * ) V_17 , 0 , 0 ,
NULL ) ;
if ( V_27 == - 1 ) {
F_43 ( V_17 , L_15 ,
V_27 ) ;
goto V_86;
}
V_74 -> V_68 = V_27 ;
V_27 = F_51 ( V_17 , V_95 ,
V_96 , V_85 ,
( void * ) V_17 , 0 , 0 ,
V_97 ) ;
if ( V_27 == - 1 ) {
F_43 ( V_17 , L_16 ,
V_27 ) ;
goto V_86;
}
V_74 -> V_69 = V_27 ;
}
}
V_17 -> V_60 |= V_78 ;
V_46 = F_40 ( V_17 ) ;
if ( V_46 != 0 )
goto V_86;
V_46 = F_52 ( V_17 ) ;
if ( V_46 != 0 )
return - V_18 ;
return 0 ;
V_86:
F_53 ( V_17 , false ) ;
return - V_18 ;
}
static int
F_54 ( struct V_16 * V_17 )
{
struct V_98 * V_99 = F_55 ( V_17 ) ;
int V_46 = - V_100 ;
V_99 -> V_101 = ( ( V_81 * 2 ) + V_102 +
V_103 + V_104 + V_105 ) ;
V_17 -> V_106 = F_56 ( V_107 ,
sizeof( struct V_108 ) ) ;
if ( ! V_17 -> V_106 )
goto V_49;
V_17 -> V_109 = F_56 ( V_107 ,
sizeof( struct V_110 ) ) ;
if ( ! V_17 -> V_109 )
goto V_111;
V_17 -> V_112 = F_57 ( L_17 , V_17 -> V_42 ,
V_113 , 8 , 0 ) ;
if ( ! V_17 -> V_112 )
goto V_114;
return 0 ;
V_114:
F_58 ( V_17 -> V_109 ) ;
V_17 -> V_109 = NULL ;
V_111:
F_58 ( V_17 -> V_106 ) ;
V_17 -> V_106 = NULL ;
V_49:
return V_46 ;
}
static void
F_59 ( struct V_16 * V_17 )
{
F_60 ( V_17 -> V_112 ) ;
V_17 -> V_112 = NULL ;
F_58 ( V_17 -> V_109 ) ;
V_17 -> V_109 = NULL ;
F_58 ( V_17 -> V_106 ) ;
V_17 -> V_106 = NULL ;
}
static struct V_16 * F_61 ( struct V_44 * V_42 )
{
struct V_16 * V_17 ;
V_17 = F_62 ( sizeof( struct V_16 ) , V_115 ) ;
if ( ! V_17 )
goto V_49;
V_17 -> V_42 = V_42 ;
strncpy ( V_17 -> V_116 , V_117 , 32 ) ;
if ( F_54 ( V_17 ) )
goto V_118;
V_17 -> V_119 = F_63 ( F_64 ( V_42 , 0 ) ,
F_65 ( V_42 , 0 ) ) ;
if ( ! V_17 -> V_119 ) {
F_43 ( V_17 , L_18 ,
V_17 -> V_119 ) ;
goto V_120;
}
F_35 ( V_17 ) ;
if ( F_66 ( V_17 ) )
goto V_121;
F_13 ( V_17 ) ;
F_49 ( V_17 , L_19 , V_17 ) ;
return V_17 ;
V_121:
F_37 ( V_17 ) ;
F_67 ( V_17 -> V_119 ) ;
V_120:
F_59 ( V_17 ) ;
V_118:
F_68 ( V_17 ) ;
V_49:
return NULL ;
}
static void
F_69 ( struct V_16 * V_17 )
{
F_53 ( V_17 , true ) ;
F_37 ( V_17 ) ;
F_70 ( V_17 ) ;
F_67 ( V_17 -> V_119 ) ;
F_16 ( V_17 ) ;
F_59 ( V_17 ) ;
F_68 ( V_17 ) ;
}
struct V_122 *
F_71 ( struct V_16 * V_17 , struct V_123 * V_51 ,
bool V_124 , struct V_122 * V_125 )
{
struct V_126 * V_127 = NULL ;
struct V_122 * V_128 ;
V_129 . V_130 = V_131 ;
V_132 . V_130 = V_131 ;
if ( V_51 == & V_17 -> V_42 -> V_51 )
V_127 = F_72 (
& V_129 ,
sizeof( struct V_122 ) ) ;
else
V_127 = F_72 (
& V_132 ,
sizeof( struct V_122 ) ) ;
if ( ! V_127 )
goto V_49;
V_128 = F_73 ( V_127 ) ;
memset ( V_128 , 0 , sizeof( struct V_122 ) ) ;
V_128 -> V_133 = ( V_127 -> V_134 << 16 ) ;
V_127 -> V_135 = V_136 ;
V_127 -> V_137 = - 1 ;
V_127 -> V_138 = V_127 -> V_134 ;
V_127 -> V_139 = 16 ;
V_127 -> V_140 = F_74 ( V_141 , V_142 ,
V_17 -> V_143 . V_144 ) ;
V_127 -> V_145 = V_146 ;
if ( V_51 == & V_17 -> V_42 -> V_51 )
V_127 -> V_147 = V_148 ;
else
V_127 -> V_147 = V_149 ;
if ( ! V_17 -> V_150 )
V_17 -> V_150 = V_128 ;
if ( F_75 ( V_128 , V_17 , V_125 ) )
goto V_151;
if ( F_76 ( V_127 , V_51 ) )
goto V_152;
return V_128 ;
V_152:
F_77 ( V_128 ) ;
V_151:
F_78 ( V_127 ) ;
V_49:
return NULL ;
}
void
F_79 ( struct V_122 * V_128 )
{
struct V_126 * V_127 = F_80 ( V_128 ) ;
struct V_16 * V_17 = F_81 ( V_128 ) ;
F_82 ( V_127 ) ;
F_83 ( V_127 ) ;
F_84 ( & V_17 -> V_153 ) ;
F_85 ( V_17 ) ;
F_86 ( & V_17 -> V_153 ) ;
F_77 ( V_128 ) ;
F_78 ( V_127 ) ;
}
struct V_122 *
F_87 ( struct V_16 * V_17 )
{
return F_71 ( V_17 , & V_17 -> V_42 -> V_51 , false , NULL ) ;
}
void
F_88 ( struct V_16 * V_17 )
{
struct V_126 * V_127 ;
struct V_122 * V_154 ;
struct V_122 * V_128 ;
struct V_155 * V_156 , * V_157 ;
struct V_122 * * V_158 ;
int V_159 = 0 , V_160 ;
V_158 = F_62 ( ( sizeof( struct V_122 * ) * V_17 -> V_161 ) ,
V_115 ) ;
if ( ! V_158 ) {
F_43 ( V_17 , L_20 ) ;
return;
}
F_84 ( & V_17 -> V_153 ) ;
F_89 (cur_ln, &hw->sln_head) {
V_154 = (struct V_122 * ) V_156 ;
V_158 [ V_159 ++ ] = V_154 ;
F_89 (cur_cln, &sln->cln_head)
V_158 [ V_159 ++ ] = (struct V_122 * ) V_157 ;
}
F_86 ( & V_17 -> V_153 ) ;
for ( V_160 = 0 ; V_160 < V_159 ; V_160 ++ ) {
F_49 ( V_17 , L_21 , V_158 [ V_160 ] ) ;
V_128 = V_158 [ V_160 ] ;
V_127 = F_80 ( V_128 ) ;
F_90 ( V_127 ) ;
}
F_68 ( V_158 ) ;
}
void
F_91 ( struct V_16 * V_17 )
{
struct V_122 * V_128 ;
struct V_126 * V_127 ;
struct V_122 * V_154 ;
struct V_155 * V_156 , * V_157 ;
struct V_122 * * V_158 ;
int V_159 = 0 , V_160 ;
V_158 = F_62 ( ( sizeof( struct V_122 * ) * V_17 -> V_161 ) ,
V_115 ) ;
if ( ! V_158 ) {
F_43 ( V_17 , L_20 ) ;
return;
}
F_84 ( & V_17 -> V_153 ) ;
F_89 (cur_ln, &hw->sln_head) {
V_154 = (struct V_122 * ) V_156 ;
V_158 [ V_159 ++ ] = V_154 ;
F_89 (cur_cln, &sln->cln_head)
V_158 [ V_159 ++ ] = (struct V_122 * ) V_157 ;
}
F_86 ( & V_17 -> V_153 ) ;
for ( V_160 = 0 ; V_160 < V_159 ; V_160 ++ ) {
F_49 ( V_17 , L_22 , V_158 [ V_160 ] ) ;
V_128 = V_158 [ V_160 ] ;
V_127 = F_80 ( V_128 ) ;
F_92 ( V_127 ) ;
}
F_68 ( V_158 ) ;
}
void
F_93 ( struct V_16 * V_17 , T_6 V_66 )
{
struct V_122 * V_128 ;
struct V_126 * V_127 ;
struct V_122 * V_154 ;
struct V_155 * V_156 , * V_157 ;
struct V_122 * * V_158 ;
int V_159 = 0 , V_160 ;
V_158 = F_62 ( ( sizeof( struct V_122 * ) * V_17 -> V_161 ) ,
V_115 ) ;
if ( ! V_158 ) {
F_43 ( V_17 , L_20 ) ;
return;
}
F_84 ( & V_17 -> V_153 ) ;
F_89 (cur_ln, &hw->sln_head) {
V_154 = (struct V_122 * ) V_156 ;
if ( V_154 -> V_66 != V_66 )
continue;
V_158 [ V_159 ++ ] = V_154 ;
F_89 (cur_cln, &sln->cln_head)
V_158 [ V_159 ++ ] = (struct V_122 * ) V_157 ;
}
F_86 ( & V_17 -> V_153 ) ;
for ( V_160 = 0 ; V_160 < V_159 ; V_160 ++ ) {
F_49 ( V_17 , L_21 , V_158 [ V_160 ] ) ;
V_128 = V_158 [ V_160 ] ;
V_127 = F_80 ( V_128 ) ;
F_90 ( V_127 ) ;
}
F_68 ( V_158 ) ;
}
void
F_94 ( struct V_16 * V_17 , T_6 V_66 )
{
struct V_122 * V_128 ;
struct V_126 * V_127 ;
struct V_122 * V_154 ;
struct V_155 * V_156 , * V_157 ;
struct V_122 * * V_158 ;
int V_159 = 0 , V_160 ;
V_158 = F_62 ( ( sizeof( struct V_122 * ) * V_17 -> V_161 ) ,
V_115 ) ;
if ( ! V_158 ) {
F_43 ( V_17 , L_20 ) ;
return;
}
F_84 ( & V_17 -> V_153 ) ;
F_89 (cur_ln, &hw->sln_head) {
V_154 = (struct V_122 * ) V_156 ;
if ( V_154 -> V_66 != V_66 )
continue;
V_158 [ V_159 ++ ] = V_154 ;
F_89 (cur_cln, &sln->cln_head)
V_158 [ V_159 ++ ] = (struct V_122 * ) V_157 ;
}
F_86 ( & V_17 -> V_153 ) ;
for ( V_160 = 0 ; V_160 < V_159 ; V_160 ++ ) {
F_49 ( V_17 , L_22 , V_158 [ V_160 ] ) ;
V_128 = V_158 [ V_160 ] ;
V_127 = F_80 ( V_128 ) ;
F_92 ( V_127 ) ;
}
F_68 ( V_158 ) ;
}
void
F_95 ( struct V_16 * V_17 , bool V_162 )
{
struct V_122 * V_154 ;
struct V_122 * V_128 ;
struct V_155 * V_156 , * V_157 ;
struct V_122 * * V_158 ;
int V_159 = 0 , V_160 ;
V_158 = F_62 ( ( sizeof( struct V_122 * ) * V_17 -> V_161 ) ,
V_115 ) ;
if ( ! V_158 ) {
F_43 ( V_17 , L_23 ) ;
return;
}
F_84 ( & V_17 -> V_153 ) ;
F_89 (cur_ln, &hw->sln_head) {
V_154 = (struct V_122 * ) V_156 ;
F_89 (cur_cln, &sln->cln_head)
V_158 [ V_159 ++ ] = (struct V_122 * ) V_157 ;
}
F_86 ( & V_17 -> V_153 ) ;
for ( V_160 = 0 ; V_160 < V_159 ; V_160 ++ ) {
F_49 ( V_17 , L_24 , V_158 [ V_160 ] ) ;
V_128 = V_158 [ V_160 ] ;
F_96 ( V_128 -> V_163 ) ;
}
if ( V_162 )
goto V_164;
V_159 = 0 ;
F_84 ( & V_17 -> V_153 ) ;
F_89 (cur_ln, &hw->sln_head) {
V_154 = (struct V_122 * ) V_156 ;
V_158 [ V_159 ++ ] = V_154 ;
}
F_86 ( & V_17 -> V_153 ) ;
for ( V_160 = 0 ; V_160 < V_159 ; V_160 ++ ) {
F_49 ( V_17 , L_25 , V_158 [ V_160 ] ) ;
F_79 ( V_158 [ V_160 ] ) ;
}
V_164:
F_68 ( V_158 ) ;
}
static void
F_97 ( struct V_122 * V_128 )
{
struct V_126 * V_127 = F_80 ( V_128 ) ;
F_98 ( V_128 ) ;
F_99 ( V_127 ) ;
}
static int F_100 ( struct V_44 * V_42 , const struct V_165 * V_166 )
{
int V_46 ;
int V_45 ;
int V_33 ;
struct V_16 * V_17 ;
struct V_122 * V_128 ;
V_46 = F_22 ( V_42 , & V_45 ) ;
if ( V_46 )
goto V_49;
V_17 = F_61 ( V_42 ) ;
if ( ! V_17 ) {
V_46 = - V_47 ;
goto V_167;
}
F_101 ( V_42 , V_17 ) ;
if ( F_102 ( V_17 ) != 0 ) {
F_31 ( & V_42 -> V_51 ,
L_26 ) ;
return 0 ;
}
sprintf ( V_17 -> V_168 , L_27 ,
F_103 ( V_17 -> V_169 ) ,
F_104 ( V_17 -> V_169 ) ,
F_105 ( V_17 -> V_169 ) ,
F_106 ( V_17 -> V_169 ) ) ;
for ( V_33 = 0 ; V_33 < V_17 -> V_70 ; V_33 ++ ) {
V_128 = F_71 ( V_17 , & V_42 -> V_51 , true , NULL ) ;
if ( ! V_128 ) {
V_46 = - V_47 ;
break;
}
V_128 -> V_66 = V_17 -> V_65 [ V_33 ] . V_66 ;
F_84 ( & V_17 -> V_153 ) ;
if ( F_107 ( V_128 ) != 0 )
V_46 = - V_47 ;
F_86 ( & V_17 -> V_153 ) ;
if ( V_46 )
break;
F_97 ( V_128 ) ;
}
if ( V_46 )
goto V_152;
return 0 ;
V_152:
F_88 ( V_17 ) ;
F_84 ( & V_17 -> V_153 ) ;
F_108 ( V_17 ) ;
F_86 ( & V_17 -> V_153 ) ;
F_91 ( V_17 ) ;
F_101 ( V_17 -> V_42 , NULL ) ;
F_95 ( V_17 , 0 ) ;
F_69 ( V_17 ) ;
V_167:
F_34 ( V_42 , & V_45 ) ;
V_49:
F_31 ( & V_42 -> V_51 , L_28 , V_46 ) ;
return V_46 ;
}
static void F_109 ( struct V_44 * V_42 )
{
struct V_16 * V_17 = F_110 ( V_42 ) ;
int V_45 = F_23 ( V_42 , V_48 ) ;
F_88 ( V_17 ) ;
F_84 ( & V_17 -> V_153 ) ;
F_108 ( V_17 ) ;
F_86 ( & V_17 -> V_153 ) ;
F_91 ( V_17 ) ;
F_95 ( V_17 , 0 ) ;
F_69 ( V_17 ) ;
F_101 ( V_42 , NULL ) ;
F_34 ( V_42 , & V_45 ) ;
}
static T_7
F_111 ( struct V_44 * V_42 , T_8 V_170 )
{
struct V_16 * V_17 = F_110 ( V_42 ) ;
F_88 ( V_17 ) ;
F_84 ( & V_17 -> V_153 ) ;
F_112 ( & V_17 -> V_171 , V_172 ) ;
F_86 ( & V_17 -> V_153 ) ;
F_91 ( V_17 ) ;
F_95 ( V_17 , 0 ) ;
F_53 ( V_17 , true ) ;
F_33 ( V_42 ) ;
return V_170 == V_173 ?
V_174 : V_175 ;
}
static T_7
F_113 ( struct V_44 * V_42 )
{
struct V_16 * V_17 = F_110 ( V_42 ) ;
int V_176 ;
if ( F_114 ( V_42 ) ) {
F_31 ( & V_42 -> V_51 , L_29 ) ;
return V_174 ;
}
F_26 ( V_42 ) ;
F_115 ( V_42 ) ;
F_116 ( V_42 ) ;
F_117 ( V_42 ) ;
F_84 ( & V_17 -> V_153 ) ;
F_112 ( & V_17 -> V_171 , V_177 ) ;
V_176 = F_118 ( V_17 ) ;
F_86 ( & V_17 -> V_153 ) ;
if ( V_176 ) {
return V_178 ;
} else {
F_31 ( & V_42 -> V_51 , L_30 ) ;
return V_174 ;
}
}
static void
F_119 ( struct V_44 * V_42 )
{
struct V_16 * V_17 = F_110 ( V_42 ) ;
struct V_122 * V_128 ;
int V_46 = 0 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_17 -> V_70 ; V_33 ++ ) {
V_128 = F_71 ( V_17 , & V_42 -> V_51 , true , NULL ) ;
if ( ! V_128 ) {
V_46 = - V_47 ;
break;
}
V_128 -> V_66 = V_17 -> V_65 [ V_33 ] . V_66 ;
F_84 ( & V_17 -> V_153 ) ;
if ( F_107 ( V_128 ) != 0 )
V_46 = - V_47 ;
F_86 ( & V_17 -> V_153 ) ;
if ( V_46 )
break;
F_97 ( V_128 ) ;
}
if ( V_46 )
goto V_179;
return;
V_179:
F_88 ( V_17 ) ;
F_84 ( & V_17 -> V_153 ) ;
F_108 ( V_17 ) ;
F_86 ( & V_17 -> V_153 ) ;
F_91 ( V_17 ) ;
F_95 ( V_17 , 0 ) ;
F_69 ( V_17 ) ;
F_31 ( & V_42 -> V_51 , L_31 , V_46 ) ;
}
static int T_9
F_120 ( void )
{
int V_46 = - V_100 ;
F_121 ( L_32 , V_180 , V_117 ) ;
F_18 () ;
V_148 = F_122 ( & V_181 ) ;
if ( ! V_148 )
goto V_49;
V_149 =
F_122 ( & V_182 ) ;
if ( ! V_149 )
goto V_183;
V_46 = F_123 ( & V_184 ) ;
if ( V_46 )
goto V_185;
return 0 ;
V_185:
F_124 ( V_149 ) ;
V_183:
F_124 ( V_148 ) ;
V_49:
F_20 () ;
return V_46 ;
}
static void T_10
F_125 ( void )
{
F_126 ( & V_184 ) ;
F_20 () ;
F_124 ( V_149 ) ;
F_124 ( V_148 ) ;
}
