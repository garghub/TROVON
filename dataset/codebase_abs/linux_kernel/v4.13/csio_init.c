static T_1
F_1 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
T_4 V_5 = * V_4 ;
T_4 V_6 = F_2 ( V_1 ) -> V_7 ;
unsigned int V_8 = ( V_9 ) V_1 -> V_10 & 3 ;
struct V_11 * V_12 = V_1 -> V_10 - V_8 ;
if ( V_5 < 0 )
return - V_13 ;
if ( V_5 >= V_6 )
return 0 ;
if ( V_3 > V_6 - V_5 )
V_3 = V_6 - V_5 ;
while ( V_3 ) {
T_3 V_14 ;
int V_15 , V_16 ;
T_5 V_17 [ 16 ] ;
if ( V_8 == V_18 )
V_15 = V_12 -> V_19 -> V_20 ( V_12 , 0 , V_5 ,
V_17 , NULL ) ;
else
V_15 = V_12 -> V_19 -> V_21 ( V_12 , V_8 , V_5 ,
V_17 , NULL ) ;
if ( V_15 )
return V_15 ;
V_16 = V_5 % sizeof( V_17 ) ;
V_14 = F_3 ( V_3 , sizeof( V_17 ) - V_16 ) ;
if ( F_4 ( V_2 , ( V_22 * ) V_17 + V_16 , V_14 ) )
return - V_23 ;
V_2 += V_14 ;
V_5 += V_14 ;
V_3 -= V_14 ;
}
V_3 = V_5 - * V_4 ;
* V_4 = V_5 ;
return V_3 ;
}
void F_5 ( struct V_11 * V_12 , const char * V_24 ,
unsigned int V_25 , unsigned int V_26 )
{
F_6 ( V_24 , V_27 , V_12 -> V_28 ,
( void * ) V_12 + V_25 , & V_29 ,
V_26 << 20 ) ;
}
static int F_7 ( struct V_11 * V_12 )
{
int V_30 ;
if ( F_8 ( V_12 -> V_28 ) )
return - 1 ;
V_30 = F_9 ( V_12 , V_31 ) ;
if ( V_30 & V_32 )
F_5 ( V_12 , L_1 , V_33 , 5 ) ;
if ( V_30 & V_34 )
F_5 ( V_12 , L_2 , V_35 , 5 ) ;
V_12 -> V_19 -> V_36 ( V_12 ) ;
return 0 ;
}
static int
F_10 ( struct V_11 * V_12 )
{
if ( V_37 ) {
V_12 -> V_28 = F_11 ( F_12 ( V_12 -> V_38 ) ,
V_37 ) ;
F_7 ( V_12 ) ;
}
return 0 ;
}
static int
F_13 ( struct V_11 * V_12 )
{
if ( V_12 -> V_28 )
F_14 ( V_12 -> V_28 ) ;
return 0 ;
}
static int
F_15 ( void )
{
V_37 = F_11 ( V_39 , NULL ) ;
if ( ! V_37 )
F_16 ( L_3 ) ;
return 0 ;
}
static void
F_17 ( void )
{
F_18 ( V_37 ) ;
}
static int
F_19 ( struct V_40 * V_38 , int * V_41 )
{
int V_42 = - V_43 ;
* V_41 = F_20 ( V_38 , V_44 ) ;
if ( F_21 ( V_38 ) )
goto V_45;
if ( F_22 ( V_38 , * V_41 , V_39 ) )
goto V_46;
F_23 ( V_38 ) ;
F_24 ( V_38 ) ;
if ( ! F_25 ( V_38 , F_26 ( 64 ) ) ) {
F_27 ( V_38 , F_26 ( 64 ) ) ;
} else if ( ! F_25 ( V_38 , F_26 ( 32 ) ) ) {
F_27 ( V_38 , F_26 ( 32 ) ) ;
} else {
F_28 ( & V_38 -> V_47 , L_4 ) ;
goto V_48;
}
return 0 ;
V_48:
F_29 ( V_38 , * V_41 ) ;
V_46:
F_30 ( V_38 ) ;
V_45:
return V_42 ;
}
static void
F_31 ( struct V_40 * V_38 , int * V_41 )
{
F_29 ( V_38 , * V_41 ) ;
F_30 ( V_38 ) ;
}
static void
F_32 ( struct V_11 * V_12 )
{
F_33 ( & V_12 -> V_49 , V_50 ) ;
}
static void
F_34 ( struct V_11 * V_12 )
{
F_35 ( & V_12 -> V_49 ) ;
F_36 () ;
}
static int
F_37 ( struct V_11 * V_12 )
{
int V_30 , V_51 ;
struct V_52 * V_53 = F_38 ( V_12 ) ;
int V_42 ;
struct V_54 * V_55 ;
if ( V_12 -> V_56 & V_57 )
return 0 ;
if ( V_12 -> V_58 != V_59 ) {
V_42 = F_39 ( V_12 , NULL , V_12 -> V_60 ,
0 , V_12 -> V_61 [ 0 ] . V_62 , false , NULL ) ;
if ( V_42 != 0 ) {
F_40 ( V_12 , L_5 , V_42 ) ;
return V_42 ;
}
}
V_42 = F_39 ( V_12 , NULL , V_12 -> V_63 ,
F_41 ( V_12 ) ,
V_12 -> V_61 [ 0 ] . V_62 , true , NULL ) ;
if ( V_42 != 0 ) {
F_40 ( V_12 , L_6 , V_42 ) ;
return V_42 ;
}
V_42 = F_42 ( V_12 , NULL , V_53 -> V_64 ,
V_53 -> V_65 , V_12 -> V_61 [ 0 ] . V_62 , NULL ) ;
if ( V_42 != 0 ) {
F_40 ( V_12 , L_7 , V_42 ) ;
goto V_45;
}
for ( V_30 = 0 ; V_30 < V_12 -> V_66 ; V_30 ++ ) {
V_55 = & V_12 -> V_67 [ V_30 ] ;
for ( V_51 = 0 ; V_51 < V_55 -> V_68 ; V_51 ++ ) {
struct V_69 * V_70 = & V_12 -> V_70 [ V_30 ] [ V_51 ] ;
V_42 = F_39 ( V_12 , NULL , V_70 -> V_65 ,
V_70 -> V_71 , V_30 , false , NULL ) ;
if ( V_42 != 0 ) {
F_40 ( V_12 ,
L_8 ,
V_30 , V_51 , V_42 ) ;
goto V_45;
}
V_42 = F_42 ( V_12 , NULL , V_70 -> V_64 ,
V_70 -> V_65 , V_30 , NULL ) ;
if ( V_42 != 0 ) {
F_40 ( V_12 ,
L_9 ,
V_30 , V_51 , V_42 ) ;
goto V_45;
}
}
}
V_12 -> V_56 |= V_57 ;
return 0 ;
V_45:
F_43 ( V_12 , true ) ;
return - V_13 ;
}
int
F_44 ( struct V_11 * V_12 )
{
int V_30 , V_51 , V_25 , V_72 = 0 ;
int V_42 ;
struct V_69 * V_70 ;
struct V_52 * V_53 = F_38 ( V_12 ) ;
struct V_69 * V_73 ;
struct V_54 * V_55 ;
if ( V_12 -> V_56 & V_74 )
return F_37 ( V_12 ) ;
V_12 -> V_75 = F_45 () ;
V_12 -> V_76 = F_45 () * V_12 -> V_66 ;
if ( V_12 -> V_76 > V_77 ) {
V_12 -> V_76 = V_77 ;
V_12 -> V_75 = V_78 ;
}
for ( V_30 = 0 ; V_30 < V_12 -> V_66 ; V_30 ++ )
V_12 -> V_67 [ V_30 ] . V_68 = V_12 -> V_75 ;
F_46 ( V_12 , L_10 ,
V_12 -> V_76 , V_12 -> V_75 ) ;
F_47 ( V_12 ) ;
if ( V_12 -> V_58 != V_59 ) {
V_12 -> V_60 = F_48 ( V_12 , V_79 ,
V_80 , V_81 ,
( void * ) V_12 , 0 , 0 , NULL ) ;
if ( V_12 -> V_60 == - 1 ) {
F_40 ( V_12 ,
L_11 ) ;
goto V_82;
}
}
V_12 -> V_63 = F_48 ( V_12 , V_83 ,
V_84 ,
V_81 , ( void * ) V_12 ,
V_85 , 0 ,
V_86 ) ;
if ( V_12 -> V_63 == - 1 ) {
F_40 ( V_12 , L_12 ) ;
goto V_82;
}
V_53 -> V_64 = F_48 ( V_12 , V_87 ,
V_88 ,
V_89 , ( void * ) V_12 , 0 , 0 , NULL ) ;
if ( V_53 -> V_64 == - 1 ) {
F_40 ( V_12 , L_13 ) ;
goto V_82;
}
V_53 -> V_65 = V_12 -> V_63 ;
for ( V_30 = 0 ; V_30 < V_12 -> V_66 ; V_30 ++ ) {
V_55 = & V_12 -> V_67 [ V_30 ] ;
for ( V_51 = 0 ; V_51 < V_12 -> V_75 ; V_51 ++ ) {
V_70 = & V_12 -> V_70 [ V_30 ] [ V_51 ] ;
if ( V_51 >= V_55 -> V_68 ) {
V_72 = V_51 % V_55 -> V_68 ;
V_73 = & V_12 -> V_70 [ V_30 ] [ V_72 ] ;
V_70 -> V_64 = V_73 -> V_64 ;
V_70 -> V_65 = V_73 -> V_65 ;
continue;
}
V_25 = F_48 ( V_12 , V_90 , 0 ,
V_89 , ( void * ) V_12 , 0 , 0 ,
NULL ) ;
if ( V_25 == - 1 ) {
F_40 ( V_12 , L_14 ,
V_25 ) ;
goto V_82;
}
V_70 -> V_64 = V_25 ;
V_25 = F_48 ( V_12 , V_91 ,
V_92 , V_81 ,
( void * ) V_12 , 0 , 0 ,
V_93 ) ;
if ( V_25 == - 1 ) {
F_40 ( V_12 , L_15 ,
V_25 ) ;
goto V_82;
}
V_70 -> V_65 = V_25 ;
}
}
V_12 -> V_56 |= V_74 ;
V_42 = F_37 ( V_12 ) ;
if ( V_42 != 0 )
goto V_82;
V_42 = F_49 ( V_12 ) ;
if ( V_42 != 0 )
return - V_13 ;
return 0 ;
V_82:
F_50 ( V_12 , false ) ;
return - V_13 ;
}
static int
F_51 ( struct V_11 * V_12 )
{
struct V_94 * V_95 = F_52 ( V_12 ) ;
int V_42 = - V_96 ;
V_95 -> V_97 = ( ( V_77 * 2 ) + V_98 +
V_99 + V_100 + V_101 ) ;
V_12 -> V_102 = F_53 ( V_103 ,
sizeof( struct V_104 ) ) ;
if ( ! V_12 -> V_102 )
goto V_45;
V_12 -> V_105 = F_53 ( V_103 ,
sizeof( struct V_106 ) ) ;
if ( ! V_12 -> V_105 )
goto V_107;
V_12 -> V_108 = F_54 ( L_16 , V_12 -> V_38 ,
V_109 , 8 , 0 ) ;
if ( ! V_12 -> V_108 )
goto V_110;
return 0 ;
V_110:
F_55 ( V_12 -> V_105 ) ;
V_12 -> V_105 = NULL ;
V_107:
F_55 ( V_12 -> V_102 ) ;
V_12 -> V_102 = NULL ;
V_45:
return V_42 ;
}
static void
F_56 ( struct V_11 * V_12 )
{
F_57 ( V_12 -> V_108 ) ;
V_12 -> V_108 = NULL ;
F_55 ( V_12 -> V_105 ) ;
V_12 -> V_105 = NULL ;
F_55 ( V_12 -> V_102 ) ;
V_12 -> V_102 = NULL ;
}
static struct V_11 * F_58 ( struct V_40 * V_38 )
{
struct V_11 * V_12 ;
V_12 = F_59 ( sizeof( struct V_11 ) , V_111 ) ;
if ( ! V_12 )
goto V_45;
V_12 -> V_38 = V_38 ;
strncpy ( V_12 -> V_112 , V_113 , 32 ) ;
if ( F_51 ( V_12 ) )
goto V_114;
V_12 -> V_115 = F_60 ( F_61 ( V_38 , 0 ) ,
F_62 ( V_38 , 0 ) ) ;
if ( ! V_12 -> V_115 ) {
F_40 ( V_12 , L_17 ,
V_12 -> V_115 ) ;
goto V_116;
}
F_32 ( V_12 ) ;
if ( F_63 ( V_12 ) )
goto V_117;
F_10 ( V_12 ) ;
F_46 ( V_12 , L_18 , V_12 ) ;
return V_12 ;
V_117:
F_34 ( V_12 ) ;
F_64 ( V_12 -> V_115 ) ;
V_116:
F_56 ( V_12 ) ;
V_114:
F_65 ( V_12 ) ;
V_45:
return NULL ;
}
static void
F_66 ( struct V_11 * V_12 )
{
F_50 ( V_12 , true ) ;
F_34 ( V_12 ) ;
F_67 ( V_12 ) ;
F_64 ( V_12 -> V_115 ) ;
F_13 ( V_12 ) ;
F_56 ( V_12 ) ;
F_65 ( V_12 ) ;
}
struct V_118 *
F_68 ( struct V_11 * V_12 , struct V_119 * V_47 ,
bool V_120 , struct V_118 * V_121 )
{
struct V_122 * V_123 = NULL ;
struct V_118 * V_124 ;
V_125 . V_126 = V_127 ;
V_128 . V_126 = V_127 ;
if ( V_47 == & V_12 -> V_38 -> V_47 )
V_123 = F_69 (
& V_125 ,
sizeof( struct V_118 ) ) ;
else
V_123 = F_69 (
& V_128 ,
sizeof( struct V_118 ) ) ;
if ( ! V_123 )
goto V_45;
V_124 = F_70 ( V_123 ) ;
memset ( V_124 , 0 , sizeof( struct V_118 ) ) ;
V_124 -> V_129 = ( V_123 -> V_130 << 16 ) ;
V_123 -> V_131 = V_132 ;
V_123 -> V_133 = - 1 ;
V_123 -> V_134 = V_123 -> V_130 ;
V_123 -> V_135 = 16 ;
V_123 -> V_136 = F_71 ( V_137 , V_138 ,
V_12 -> V_139 . V_140 ) ;
V_123 -> V_141 = V_142 ;
if ( V_47 == & V_12 -> V_38 -> V_47 )
V_123 -> V_143 = V_144 ;
else
V_123 -> V_143 = V_145 ;
if ( ! V_12 -> V_146 )
V_12 -> V_146 = V_124 ;
if ( F_72 ( V_124 , V_12 , V_121 ) )
goto V_147;
if ( F_73 ( V_123 , V_47 ) )
goto V_148;
return V_124 ;
V_148:
F_74 ( V_124 ) ;
V_147:
F_75 ( V_123 ) ;
V_45:
return NULL ;
}
void
F_76 ( struct V_118 * V_124 )
{
struct V_122 * V_123 = F_77 ( V_124 ) ;
struct V_11 * V_12 = F_78 ( V_124 ) ;
F_79 ( V_123 ) ;
F_80 ( V_123 ) ;
F_81 ( & V_12 -> V_149 ) ;
F_82 ( V_12 ) ;
F_83 ( & V_12 -> V_149 ) ;
F_74 ( V_124 ) ;
F_75 ( V_123 ) ;
}
struct V_118 *
F_84 ( struct V_11 * V_12 )
{
return F_68 ( V_12 , & V_12 -> V_38 -> V_47 , false , NULL ) ;
}
void
F_85 ( struct V_11 * V_12 )
{
struct V_122 * V_123 ;
struct V_118 * V_150 ;
struct V_118 * V_124 ;
struct V_151 * V_152 , * V_153 ;
struct V_118 * * V_154 ;
int V_155 = 0 , V_156 ;
V_154 = F_59 ( ( sizeof( struct V_118 * ) * V_12 -> V_157 ) ,
V_111 ) ;
if ( ! V_154 ) {
F_40 ( V_12 , L_19 ) ;
return;
}
F_81 ( & V_12 -> V_149 ) ;
F_86 (cur_ln, &hw->sln_head) {
V_150 = (struct V_118 * ) V_152 ;
V_154 [ V_155 ++ ] = V_150 ;
F_86 (cur_cln, &sln->cln_head)
V_154 [ V_155 ++ ] = (struct V_118 * ) V_153 ;
}
F_83 ( & V_12 -> V_149 ) ;
for ( V_156 = 0 ; V_156 < V_155 ; V_156 ++ ) {
F_46 ( V_12 , L_20 , V_154 [ V_156 ] ) ;
V_124 = V_154 [ V_156 ] ;
V_123 = F_77 ( V_124 ) ;
F_87 ( V_123 ) ;
}
F_65 ( V_154 ) ;
}
void
F_88 ( struct V_11 * V_12 )
{
struct V_118 * V_124 ;
struct V_122 * V_123 ;
struct V_118 * V_150 ;
struct V_151 * V_152 , * V_153 ;
struct V_118 * * V_154 ;
int V_155 = 0 , V_156 ;
V_154 = F_59 ( ( sizeof( struct V_118 * ) * V_12 -> V_157 ) ,
V_111 ) ;
if ( ! V_154 ) {
F_40 ( V_12 , L_19 ) ;
return;
}
F_81 ( & V_12 -> V_149 ) ;
F_86 (cur_ln, &hw->sln_head) {
V_150 = (struct V_118 * ) V_152 ;
V_154 [ V_155 ++ ] = V_150 ;
F_86 (cur_cln, &sln->cln_head)
V_154 [ V_155 ++ ] = (struct V_118 * ) V_153 ;
}
F_83 ( & V_12 -> V_149 ) ;
for ( V_156 = 0 ; V_156 < V_155 ; V_156 ++ ) {
F_46 ( V_12 , L_21 , V_154 [ V_156 ] ) ;
V_124 = V_154 [ V_156 ] ;
V_123 = F_77 ( V_124 ) ;
F_89 ( V_123 ) ;
}
F_65 ( V_154 ) ;
}
void
F_90 ( struct V_11 * V_12 , T_6 V_62 )
{
struct V_118 * V_124 ;
struct V_122 * V_123 ;
struct V_118 * V_150 ;
struct V_151 * V_152 , * V_153 ;
struct V_118 * * V_154 ;
int V_155 = 0 , V_156 ;
V_154 = F_59 ( ( sizeof( struct V_118 * ) * V_12 -> V_157 ) ,
V_111 ) ;
if ( ! V_154 ) {
F_40 ( V_12 , L_19 ) ;
return;
}
F_81 ( & V_12 -> V_149 ) ;
F_86 (cur_ln, &hw->sln_head) {
V_150 = (struct V_118 * ) V_152 ;
if ( V_150 -> V_62 != V_62 )
continue;
V_154 [ V_155 ++ ] = V_150 ;
F_86 (cur_cln, &sln->cln_head)
V_154 [ V_155 ++ ] = (struct V_118 * ) V_153 ;
}
F_83 ( & V_12 -> V_149 ) ;
for ( V_156 = 0 ; V_156 < V_155 ; V_156 ++ ) {
F_46 ( V_12 , L_20 , V_154 [ V_156 ] ) ;
V_124 = V_154 [ V_156 ] ;
V_123 = F_77 ( V_124 ) ;
F_87 ( V_123 ) ;
}
F_65 ( V_154 ) ;
}
void
F_91 ( struct V_11 * V_12 , T_6 V_62 )
{
struct V_118 * V_124 ;
struct V_122 * V_123 ;
struct V_118 * V_150 ;
struct V_151 * V_152 , * V_153 ;
struct V_118 * * V_154 ;
int V_155 = 0 , V_156 ;
V_154 = F_59 ( ( sizeof( struct V_118 * ) * V_12 -> V_157 ) ,
V_111 ) ;
if ( ! V_154 ) {
F_40 ( V_12 , L_19 ) ;
return;
}
F_81 ( & V_12 -> V_149 ) ;
F_86 (cur_ln, &hw->sln_head) {
V_150 = (struct V_118 * ) V_152 ;
if ( V_150 -> V_62 != V_62 )
continue;
V_154 [ V_155 ++ ] = V_150 ;
F_86 (cur_cln, &sln->cln_head)
V_154 [ V_155 ++ ] = (struct V_118 * ) V_153 ;
}
F_83 ( & V_12 -> V_149 ) ;
for ( V_156 = 0 ; V_156 < V_155 ; V_156 ++ ) {
F_46 ( V_12 , L_21 , V_154 [ V_156 ] ) ;
V_124 = V_154 [ V_156 ] ;
V_123 = F_77 ( V_124 ) ;
F_89 ( V_123 ) ;
}
F_65 ( V_154 ) ;
}
void
F_92 ( struct V_11 * V_12 , bool V_158 )
{
struct V_118 * V_150 ;
struct V_118 * V_124 ;
struct V_151 * V_152 , * V_153 ;
struct V_118 * * V_154 ;
int V_155 = 0 , V_156 ;
V_154 = F_59 ( ( sizeof( struct V_118 * ) * V_12 -> V_157 ) ,
V_111 ) ;
if ( ! V_154 ) {
F_40 ( V_12 , L_22 ) ;
return;
}
F_81 ( & V_12 -> V_149 ) ;
F_86 (cur_ln, &hw->sln_head) {
V_150 = (struct V_118 * ) V_152 ;
F_86 (cur_cln, &sln->cln_head)
V_154 [ V_155 ++ ] = (struct V_118 * ) V_153 ;
}
F_83 ( & V_12 -> V_149 ) ;
for ( V_156 = 0 ; V_156 < V_155 ; V_156 ++ ) {
F_46 ( V_12 , L_23 , V_154 [ V_156 ] ) ;
V_124 = V_154 [ V_156 ] ;
F_93 ( V_124 -> V_159 ) ;
}
if ( V_158 )
goto V_160;
V_155 = 0 ;
F_81 ( & V_12 -> V_149 ) ;
F_86 (cur_ln, &hw->sln_head) {
V_150 = (struct V_118 * ) V_152 ;
V_154 [ V_155 ++ ] = V_150 ;
}
F_83 ( & V_12 -> V_149 ) ;
for ( V_156 = 0 ; V_156 < V_155 ; V_156 ++ ) {
F_46 ( V_12 , L_24 , V_154 [ V_156 ] ) ;
F_76 ( V_154 [ V_156 ] ) ;
}
V_160:
F_65 ( V_154 ) ;
}
static void
F_94 ( struct V_118 * V_124 )
{
struct V_122 * V_123 = F_77 ( V_124 ) ;
F_95 ( V_124 ) ;
F_96 ( V_123 ) ;
}
static int F_97 ( struct V_40 * V_38 , const struct V_161 * V_162 )
{
int V_42 ;
int V_41 ;
int V_30 ;
struct V_11 * V_12 ;
struct V_118 * V_124 ;
if ( ! F_98 ( ( V_38 -> V_119 & V_163 ) ) &&
! F_99 ( ( V_38 -> V_119 & V_163 ) ) )
return - V_43 ;
V_42 = F_19 ( V_38 , & V_41 ) ;
if ( V_42 )
goto V_45;
V_12 = F_58 ( V_38 ) ;
if ( ! V_12 ) {
V_42 = - V_43 ;
goto V_164;
}
F_100 ( V_38 , V_12 ) ;
V_42 = F_101 ( V_12 ) ;
if ( V_42 ) {
if ( V_42 == - V_13 ) {
F_28 ( & V_38 -> V_47 ,
L_25 ) ;
return 0 ;
}
goto V_148;
}
sprintf ( V_12 -> V_165 , L_26 ,
F_102 ( V_12 -> V_166 ) ,
F_103 ( V_12 -> V_166 ) ,
F_104 ( V_12 -> V_166 ) ,
F_105 ( V_12 -> V_166 ) ) ;
for ( V_30 = 0 ; V_30 < V_12 -> V_66 ; V_30 ++ ) {
V_124 = F_68 ( V_12 , & V_38 -> V_47 , true , NULL ) ;
if ( ! V_124 ) {
V_42 = - V_43 ;
break;
}
V_124 -> V_62 = V_12 -> V_61 [ V_30 ] . V_62 ;
F_81 ( & V_12 -> V_149 ) ;
if ( F_106 ( V_124 ) != 0 )
V_42 = - V_43 ;
F_83 ( & V_12 -> V_149 ) ;
if ( V_42 )
break;
F_94 ( V_124 ) ;
}
if ( V_42 )
goto V_148;
return 0 ;
V_148:
F_85 ( V_12 ) ;
F_81 ( & V_12 -> V_149 ) ;
F_107 ( V_12 ) ;
F_83 ( & V_12 -> V_149 ) ;
F_88 ( V_12 ) ;
F_92 ( V_12 , 0 ) ;
F_66 ( V_12 ) ;
V_164:
F_31 ( V_38 , & V_41 ) ;
V_45:
F_28 ( & V_38 -> V_47 , L_27 , V_42 ) ;
return V_42 ;
}
static void F_108 ( struct V_40 * V_38 )
{
struct V_11 * V_12 = F_109 ( V_38 ) ;
int V_41 = F_20 ( V_38 , V_44 ) ;
F_85 ( V_12 ) ;
F_81 ( & V_12 -> V_149 ) ;
F_107 ( V_12 ) ;
F_83 ( & V_12 -> V_149 ) ;
F_88 ( V_12 ) ;
F_92 ( V_12 , 0 ) ;
F_66 ( V_12 ) ;
F_31 ( V_38 , & V_41 ) ;
}
static T_7
F_110 ( struct V_40 * V_38 , T_8 V_167 )
{
struct V_11 * V_12 = F_109 ( V_38 ) ;
F_85 ( V_12 ) ;
F_81 ( & V_12 -> V_149 ) ;
F_111 ( & V_12 -> V_168 , V_169 ) ;
F_83 ( & V_12 -> V_149 ) ;
F_88 ( V_12 ) ;
F_92 ( V_12 , 0 ) ;
F_50 ( V_12 , true ) ;
F_30 ( V_38 ) ;
return V_167 == V_170 ?
V_171 : V_172 ;
}
static T_7
F_112 ( struct V_40 * V_38 )
{
struct V_11 * V_12 = F_109 ( V_38 ) ;
int V_173 ;
if ( F_113 ( V_38 ) ) {
F_28 ( & V_38 -> V_47 , L_28 ) ;
return V_171 ;
}
F_23 ( V_38 ) ;
F_114 ( V_38 ) ;
F_115 ( V_38 ) ;
F_116 ( V_38 ) ;
F_81 ( & V_12 -> V_149 ) ;
F_111 ( & V_12 -> V_168 , V_174 ) ;
V_173 = F_117 ( V_12 ) ;
F_83 ( & V_12 -> V_149 ) ;
if ( V_173 ) {
return V_175 ;
} else {
F_28 ( & V_38 -> V_47 , L_29 ) ;
return V_171 ;
}
}
static void
F_118 ( struct V_40 * V_38 )
{
struct V_11 * V_12 = F_109 ( V_38 ) ;
struct V_118 * V_124 ;
int V_42 = 0 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_12 -> V_66 ; V_30 ++ ) {
V_124 = F_68 ( V_12 , & V_38 -> V_47 , true , NULL ) ;
if ( ! V_124 ) {
V_42 = - V_43 ;
break;
}
V_124 -> V_62 = V_12 -> V_61 [ V_30 ] . V_62 ;
F_81 ( & V_12 -> V_149 ) ;
if ( F_106 ( V_124 ) != 0 )
V_42 = - V_43 ;
F_83 ( & V_12 -> V_149 ) ;
if ( V_42 )
break;
F_94 ( V_124 ) ;
}
if ( V_42 )
goto V_176;
return;
V_176:
F_85 ( V_12 ) ;
F_81 ( & V_12 -> V_149 ) ;
F_107 ( V_12 ) ;
F_83 ( & V_12 -> V_149 ) ;
F_88 ( V_12 ) ;
F_92 ( V_12 , 0 ) ;
F_66 ( V_12 ) ;
F_28 ( & V_38 -> V_47 , L_30 , V_42 ) ;
}
static int T_9
F_119 ( void )
{
int V_42 = - V_96 ;
F_120 ( L_31 , V_177 , V_113 ) ;
F_15 () ;
V_144 = F_121 ( & V_178 ) ;
if ( ! V_144 )
goto V_45;
V_145 =
F_121 ( & V_179 ) ;
if ( ! V_145 )
goto V_180;
V_42 = F_122 ( & V_181 ) ;
if ( V_42 )
goto V_182;
return 0 ;
V_182:
F_123 ( V_145 ) ;
V_180:
F_123 ( V_144 ) ;
V_45:
F_17 () ;
return V_42 ;
}
static void T_10
F_124 ( void )
{
F_125 ( & V_181 ) ;
F_17 () ;
F_123 ( V_145 ) ;
F_123 ( V_144 ) ;
}
