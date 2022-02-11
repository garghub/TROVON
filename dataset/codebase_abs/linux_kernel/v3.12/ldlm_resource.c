static T_1 F_1 ( struct V_1 * V_1 , const char * V_2 ,
T_2 V_3 , T_3 * V_4 )
{
F_2 ( V_5 , V_6 ) ;
F_2 ( V_7 , V_6 ) ;
return V_3 ;
}
int F_3 ( void )
{
int V_8 ;
struct V_9 V_10 [] = {
{ L_1 , & V_11 , 0 , 0222 } ,
{ L_2 , & V_12 ,
& V_13 } ,
{ L_3 , & V_12 ,
& V_14 } ,
{ NULL } } ;
F_4 ( V_15 == NULL ) ;
V_16 = F_5 ( V_17 ,
V_18 ,
NULL , NULL ) ;
if ( F_6 ( V_16 ) ) {
F_7 ( L_4 ) ;
V_8 = F_8 ( V_16 ) ;
GOTO ( V_19 , V_8 ) ;
}
V_15 = F_5 ( L_5 ,
V_16 ,
NULL , NULL ) ;
if ( F_6 ( V_15 ) ) {
F_7 ( L_4 ) ;
V_8 = F_8 ( V_15 ) ;
GOTO ( V_20 , V_8 ) ;
}
V_21 = F_5 ( L_6 ,
V_16 ,
NULL , NULL ) ;
if ( F_6 ( V_21 ) ) {
F_7 ( L_4 ) ;
V_8 = F_8 ( V_21 ) ;
GOTO ( V_22 , V_8 ) ;
}
V_8 = F_9 ( V_16 , V_10 , NULL ) ;
return 0 ;
V_22:
F_10 ( & V_15 ) ;
V_20:
F_10 ( & V_16 ) ;
V_19:
V_21 = NULL ;
V_16 = NULL ;
V_15 = NULL ;
return V_8 ;
}
void F_11 ( void )
{
if ( V_21 )
F_10 ( & V_21 ) ;
if ( V_15 )
F_10 ( & V_15 ) ;
if ( V_16 )
F_10 ( & V_16 ) ;
V_21 = NULL ;
V_16 = NULL ;
V_15 = NULL ;
}
static int F_12 ( struct V_23 * V_24 , void * V_25 )
{
struct V_26 * V_27 = V_24 -> V_28 ;
T_4 V_29 = 0 ;
T_5 V_30 ;
int V_31 ;
F_13 (ns->ns_rs_hash, &bd, i)
V_29 += F_14 ( & V_30 ) ;
return F_15 ( V_24 , & V_29 ) ;
}
static int F_16 ( struct V_23 * V_24 , void * V_25 )
{
struct V_26 * V_27 = V_24 -> V_28 ;
T_4 V_32 ;
V_32 = F_17 ( V_27 -> V_33 , V_34 ,
V_35 ) ;
return F_15 ( V_24 , & V_32 ) ;
}
static int F_18 ( struct V_23 * V_24 , void * V_25 )
{
struct V_26 * V_27 = V_24 -> V_28 ;
T_6 * V_36 = & V_27 -> V_37 ;
if ( F_19 ( V_27 ) )
V_36 = & V_27 -> V_38 ;
return F_20 ( V_24 , V_36 ) ;
}
static T_1 F_21 ( struct V_1 * V_1 , const char * V_2 ,
T_2 V_3 , T_3 * V_4 )
{
struct V_26 * V_27 = ( (struct V_23 * ) V_1 -> V_39 ) -> V_28 ;
char V_40 [ V_41 + 1 ] , * V_42 ;
unsigned long V_43 ;
int V_44 ;
V_40 [ V_41 ] = '\0' ;
if ( F_22 ( V_40 , V_2 , V_41 ) )
return - V_45 ;
if ( strncmp ( V_40 , L_7 , 5 ) == 0 ) {
F_23 ( V_6 ,
L_8 ,
F_24 ( V_27 ) ) ;
if ( F_19 ( V_27 ) ) {
int V_46 , V_47 = V_27 -> V_38 ;
V_46 = F_25 ( V_27 , V_47 , 0 ,
V_48 ) ;
if ( V_46 < V_47 ) {
F_23 ( V_6 ,
L_9
L_10 , V_47 ,
V_46 ) ;
return - V_49 ;
}
} else {
V_43 = V_27 -> V_37 ;
V_27 -> V_37 = 0 ;
F_25 ( V_27 , 0 , 0 , V_48 ) ;
V_27 -> V_37 = V_43 ;
}
return V_3 ;
}
V_43 = F_26 ( V_40 , & V_42 , 0 ) ;
if ( V_40 == V_42 ) {
F_7 ( L_11 ) ;
return - V_49 ;
}
V_44 = ( V_43 == 0 ) ;
if ( F_19 ( V_27 ) ) {
if ( ! V_44 )
V_27 -> V_37 = ( unsigned int ) V_43 ;
if ( V_43 > V_27 -> V_38 )
V_43 = V_27 -> V_38 ;
V_43 = V_27 -> V_38 - V_43 ;
F_23 ( V_6 ,
L_12 ,
F_24 ( V_27 ) , V_27 -> V_38 ,
( unsigned int ) V_43 ) ;
F_25 ( V_27 , V_43 , V_50 , V_48 ) ;
if ( ! V_44 ) {
F_23 ( V_6 ,
L_13 ,
F_24 ( V_27 ) ) ;
V_27 -> V_51 &= ~ V_52 ;
}
} else {
F_23 ( V_6 ,
L_14 ,
F_24 ( V_27 ) , V_27 -> V_37 ,
( unsigned int ) V_43 ) ;
V_27 -> V_37 = ( unsigned int ) V_43 ;
F_25 ( V_27 , 0 , V_50 , V_48 ) ;
if ( V_44 &&
( V_27 -> V_53 & V_52 ) ) {
F_23 ( V_6 ,
L_15 ,
F_24 ( V_27 ) ) ;
V_27 -> V_51 |= V_52 ;
}
}
return V_3 ;
}
static int F_27 ( struct V_23 * V_24 , void * V_25 )
{
struct V_26 * V_27 = V_24 -> V_28 ;
unsigned int V_54 = F_28 ( V_27 ) ;
return F_20 ( V_24 , & V_54 ) ;
}
static T_1 F_29 ( struct V_1 * V_1 , const char * V_2 ,
T_2 V_3 , T_3 * V_4 )
{
struct V_26 * V_27 = ( (struct V_23 * ) V_1 -> V_39 ) -> V_28 ;
unsigned int V_54 = - 1 ;
int V_8 ;
V_8 = F_30 ( V_1 , V_2 , V_3 , & V_54 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_54 == 0 )
V_27 -> V_51 &= ~ V_55 ;
else if ( V_27 -> V_53 & V_55 )
V_27 -> V_51 |= V_55 ;
return V_3 ;
}
void F_31 ( struct V_26 * V_27 )
{
if ( V_27 -> V_56 == NULL )
F_7 ( L_16 ,
F_24 ( V_27 ) ) ;
else
F_10 ( & V_27 -> V_56 ) ;
if ( V_27 -> V_33 != NULL )
F_32 ( & V_27 -> V_33 ) ;
}
int F_33 ( struct V_26 * V_27 )
{
struct V_9 V_57 [ 2 ] ;
char V_58 [ V_41 + 1 ] ;
struct V_59 * V_60 ;
F_4 ( V_27 != NULL ) ;
F_4 ( V_27 -> V_61 != NULL ) ;
if ( V_27 -> V_56 != NULL ) {
V_60 = V_27 -> V_56 ;
} else {
V_60 = F_34 ( F_24 ( V_27 ) , V_15 ) ;
if ( V_60 == NULL )
return - V_62 ;
V_27 -> V_56 = V_60 ;
}
V_27 -> V_33 = F_35 ( V_63 , 0 ) ;
if ( V_27 -> V_33 == NULL )
return - V_62 ;
F_36 ( V_27 -> V_33 , V_34 ,
V_64 , L_17 , L_17 ) ;
V_58 [ V_41 ] = '\0' ;
memset ( V_57 , 0 , sizeof( V_57 ) ) ;
V_57 [ 0 ] . V_65 = V_58 ;
F_37 ( L_18 , V_27 , & V_66 ) ;
F_37 ( L_19 , V_27 , & V_67 ) ;
if ( F_38 ( V_27 ) ) {
F_37 ( L_20 , & V_27 -> V_38 ,
& V_68 ) ;
F_37 ( L_21 , V_27 , & V_69 ) ;
F_37 ( L_22 , & V_27 -> V_70 ,
& V_12 ) ;
F_37 ( L_23 , V_27 , & V_71 ) ;
} else {
F_37 ( L_24 , & V_27 -> V_72 ,
& V_12 ) ;
F_37 ( L_25 , & V_27 -> V_73 ,
& V_68 ) ;
F_37 ( L_26 , & V_27 -> V_74 ,
& V_12 ) ;
F_37 ( L_27 , & V_27 -> V_75 ,
& V_12 ) ;
F_37 ( L_28 , & V_27 -> V_76 ,
& V_12 ) ;
F_37 ( L_29 , & V_27 -> V_77 ,
& V_12 ) ;
}
return 0 ;
}
static unsigned F_39 ( T_7 * V_78 ,
const void * V_79 , unsigned V_80 )
{
const struct V_81 * V_82 = V_79 ;
unsigned V_83 = 0 ;
unsigned V_31 ;
for ( V_31 = 0 ; V_31 < V_84 ; V_31 ++ )
V_83 += V_82 -> V_65 [ V_31 ] ;
return V_83 & V_80 ;
}
static unsigned F_40 ( T_7 * V_78 ,
const void * V_79 , unsigned V_80 )
{
const struct V_81 * V_82 = V_79 ;
struct V_85 V_86 ;
T_6 V_87 ;
T_6 V_83 ;
V_86 . V_88 = V_82 -> V_65 [ V_89 ] ;
V_86 . V_90 = ( T_6 ) V_82 -> V_65 [ V_91 ] ;
V_86 . V_92 = ( T_6 ) ( V_82 -> V_65 [ V_91 ] >> 32 ) ;
V_87 = F_41 ( & V_86 ) ;
V_87 += ( V_87 >> 4 ) + ( V_87 << 12 ) ;
if ( V_82 -> V_65 [ V_93 ] != 0 ) {
V_83 = V_82 -> V_65 [ V_93 ] ;
V_87 += ( V_83 >> 5 ) + ( V_83 << 11 ) ;
} else {
V_83 = F_42 ( & V_86 ) ;
}
V_87 = F_43 ( V_87 , V_78 -> V_94 ) ;
V_87 -= F_43 ( ( unsigned long ) V_78 , V_83 % 11 + 3 ) ;
V_87 <<= V_78 -> V_95 - V_78 -> V_94 ;
V_87 |= F_39 ( V_78 , V_79 , F_44 ( V_78 ) - 1 ) ;
return V_87 & V_80 ;
}
static void * F_45 ( struct V_96 * V_97 )
{
struct V_98 * V_29 ;
V_29 = F_46 ( V_97 , struct V_98 , V_99 ) ;
return & V_29 -> V_100 ;
}
static int F_47 ( const void * V_79 , struct V_96 * V_97 )
{
struct V_98 * V_29 ;
V_29 = F_46 ( V_97 , struct V_98 , V_99 ) ;
return F_48 ( ( const struct V_81 * ) V_79 ,
( const struct V_81 * ) & V_29 -> V_100 ) ;
}
static void * F_49 ( struct V_96 * V_97 )
{
return F_46 ( V_97 , struct V_98 , V_99 ) ;
}
static void F_50 ( T_7 * V_78 , struct V_96 * V_97 )
{
struct V_98 * V_29 ;
V_29 = F_46 ( V_97 , struct V_98 , V_99 ) ;
F_51 ( V_29 ) ;
}
static void F_52 ( T_7 * V_78 , struct V_96 * V_97 )
{
struct V_98 * V_29 ;
V_29 = F_46 ( V_97 , struct V_98 , V_99 ) ;
F_53 ( V_29 ) ;
}
static void F_54 ( T_7 * V_78 , struct V_96 * V_97 )
{
struct V_98 * V_29 ;
V_29 = F_46 ( V_97 , struct V_98 , V_99 ) ;
F_55 ( V_29 ) ;
}
struct V_26 * F_56 ( struct V_101 * V_102 , char * V_65 ,
T_8 V_103 ,
T_9 V_104 ,
T_10 V_105 )
{
struct V_26 * V_27 = NULL ;
struct V_106 * V_107 ;
T_11 * V_108 ;
T_5 V_30 ;
int V_109 ;
int V_8 ;
F_4 ( V_102 != NULL ) ;
V_8 = F_57 () ;
if ( V_8 ) {
F_7 ( L_30 , V_8 ) ;
return NULL ;
}
for ( V_109 = 0 ; ; V_109 ++ ) {
V_108 = & V_110 [ V_109 ] ;
if ( V_108 -> V_111 == V_112 ) {
F_7 ( L_31 , V_105 , V_65 ) ;
GOTO ( V_113 , NULL ) ;
}
if ( V_108 -> V_111 == V_105 )
break;
}
F_58 ( V_27 ) ;
if ( ! V_27 )
GOTO ( V_113 , NULL ) ;
V_27 -> V_61 = F_59 ( V_65 ,
V_108 -> V_114 , V_108 -> V_114 ,
V_108 -> V_115 , sizeof( * V_107 ) ,
V_116 ,
V_117 ,
V_108 -> V_118 ,
V_119 |
V_120 |
V_121 |
V_122 ) ;
if ( V_27 -> V_61 == NULL )
GOTO ( V_123 , NULL ) ;
F_13 (ns->ns_rs_hash, &bd, idx) {
V_107 = F_60 ( V_27 -> V_61 , & V_30 ) ;
F_61 ( & V_107 -> V_124 , V_125 , 0 ) ;
V_107 -> V_126 = V_27 ;
}
V_27 -> V_127 = V_102 ;
V_27 -> V_128 = V_104 ;
V_27 -> V_129 = V_103 ;
F_62 ( & V_27 -> V_130 ) ;
F_62 ( & V_27 -> V_131 ) ;
F_63 ( & V_27 -> V_132 ) ;
F_64 ( & V_27 -> V_133 , 0 ) ;
F_65 ( & V_27 -> V_134 ) ;
V_27 -> V_74 = V_135 ;
V_27 -> V_75 = V_136 ;
V_27 -> V_76 = V_137 ;
V_27 -> V_77 = V_138 ;
V_27 -> V_38 = 0 ;
V_27 -> V_37 = V_139 ;
V_27 -> V_70 = V_140 ;
V_27 -> V_72 = V_141 ;
V_27 -> V_73 = 0 ;
V_27 -> V_53 = 0 ;
V_27 -> V_51 = 0 ;
V_27 -> V_142 = 0 ;
V_8 = F_33 ( V_27 ) ;
if ( V_8 != 0 ) {
F_7 ( L_32 , V_8 ) ;
GOTO ( V_143 , V_8 ) ;
}
V_109 = F_66 ( V_103 ) ;
V_8 = F_67 ( & V_27 -> V_144 , V_27 , V_109 , V_103 ) ;
if ( V_8 ) {
F_7 ( L_33 , V_8 ) ;
GOTO ( V_145 , V_8 ) ;
}
F_68 ( V_27 , V_103 ) ;
return V_27 ;
V_145:
F_31 ( V_27 ) ;
F_69 ( V_27 , 0 ) ;
V_143:
F_70 ( V_27 -> V_61 ) ;
V_123:
F_71 ( V_27 ) ;
V_113:
F_72 () ;
return NULL ;
}
static void F_73 ( struct V_98 * V_29 , struct V_146 * V_147 ,
T_4 V_148 )
{
struct V_146 * V_43 ;
int V_8 = 0 , V_103 = F_38 ( F_74 ( V_29 ) ) ;
bool V_149 = ! ! ( V_148 & V_150 ) ;
do {
struct V_151 * V_152 = NULL ;
F_75 ( V_29 ) ;
F_76 (tmp, q) {
V_152 = F_77 ( V_43 , struct V_151 ,
V_153 ) ;
if ( V_152 -> V_154 & V_155 ) {
V_152 = NULL ;
continue;
}
F_78 ( V_152 ) ;
V_152 -> V_154 |= V_155 ;
break;
}
if ( V_152 == NULL ) {
F_79 ( V_29 ) ;
break;
}
V_152 -> V_154 |= V_156 ;
V_152 -> V_154 |= V_157 ;
V_152 -> V_154 |= V_148 ;
if ( V_149 )
V_152 -> V_154 |= V_150 ;
if ( V_149 && ( V_152 -> V_158 || V_152 -> V_159 ) ) {
F_79 ( V_29 ) ;
F_80 ( V_152 , L_34 ) ;
if ( V_152 -> V_160 )
V_152 -> V_160 ( V_152 , 0 , NULL ) ;
F_81 ( V_152 ) ;
continue;
}
if ( V_103 ) {
struct V_161 V_162 ;
F_79 ( V_29 ) ;
F_82 ( V_152 , & V_162 ) ;
V_8 = F_83 ( & V_162 , V_50 ) ;
if ( V_8 )
F_7 ( L_35 , V_8 ) ;
} else {
F_84 ( V_152 ) ;
F_79 ( V_29 ) ;
F_80 ( V_152 , L_36
L_37 ) ;
F_85 ( V_152 ) ;
}
F_81 ( V_152 ) ;
} while ( 1 );
}
static int F_86 ( T_7 * V_78 , T_5 * V_30 ,
struct V_96 * V_97 , void * V_163 )
{
struct V_98 * V_29 = F_87 ( V_78 , V_97 ) ;
T_4 V_148 = * ( T_4 * ) V_163 ;
F_73 ( V_29 , & V_29 -> V_164 , V_148 ) ;
F_73 ( V_29 , & V_29 -> V_165 , V_148 ) ;
F_73 ( V_29 , & V_29 -> V_166 , V_148 ) ;
return 0 ;
}
static int F_88 ( T_7 * V_78 , T_5 * V_30 ,
struct V_96 * V_97 , void * V_163 )
{
struct V_98 * V_29 = F_87 ( V_78 , V_97 ) ;
F_75 ( V_29 ) ;
F_7 ( L_38
L_39
L_40 ,
F_24 ( F_74 ( V_29 ) ) ,
F_89 ( & V_29 -> V_167 ) - 1 ) ;
F_7 ( L_41 V_168 L_42 V_168 L_42 V_168 L_42
V_168 L_43 , V_29 ,
V_29 -> V_100 . V_65 [ 0 ] , V_29 -> V_100 . V_65 [ 1 ] ,
V_29 -> V_100 . V_65 [ 2 ] , V_29 -> V_100 . V_65 [ 3 ] ,
F_89 ( & V_29 -> V_167 ) - 1 ) ;
F_90 ( V_169 , V_29 ) ;
F_79 ( V_29 ) ;
return 0 ;
}
int F_69 ( struct V_26 * V_27 , T_4 V_148 )
{
if ( V_27 == NULL ) {
F_23 ( V_170 , L_44 ) ;
return V_171 ;
}
F_91 ( V_27 -> V_61 , F_86 , & V_148 ) ;
F_91 ( V_27 -> V_61 , F_88 , NULL ) ;
return V_171 ;
}
static int F_92 ( struct V_26 * V_27 , int V_172 )
{
F_69 ( V_27 , V_172 ? V_150 : 0 ) ;
if ( F_89 ( & V_27 -> V_133 ) > 0 ) {
struct V_173 V_174 = F_93 ( V_175 , NULL ) ;
int V_8 ;
F_23 ( V_6 ,
L_45 ,
F_24 ( V_27 ) , F_89 ( & V_27 -> V_133 ) ) ;
V_176:
if ( V_172 )
V_174 = F_94 ( V_177 * V_178 / 4 , NULL , NULL ) ;
V_8 = F_95 ( V_27 -> V_134 ,
F_89 ( & V_27 -> V_133 ) == 0 , & V_174 ) ;
if ( V_172 && V_8 == - V_179 ) {
F_96 ( L_46
L_47
L_48 , F_24 ( V_27 ) ,
F_89 ( & V_27 -> V_133 ) , V_8 ) ;
GOTO ( V_176 , V_8 ) ;
}
if ( F_89 ( & V_27 -> V_133 ) ) {
F_96 ( L_49
L_50 ,
F_24 ( V_27 ) ,
F_89 ( & V_27 -> V_133 ) , V_8 ) ;
return V_180 ;
}
F_23 ( V_6 , L_51 ,
F_24 ( V_27 ) ) ;
}
return V_171 ;
}
void F_97 ( struct V_26 * V_27 ,
struct V_181 * V_182 ,
int V_172 )
{
int V_8 ;
if ( ! V_27 ) {
return;
}
F_98 ( & V_27 -> V_132 ) ;
V_27 -> V_142 = 1 ;
F_99 ( & V_27 -> V_132 ) ;
V_8 = F_92 ( V_27 , V_172 ) ;
if ( V_8 != V_171 ) {
if ( V_182 ) {
F_100 ( V_182 , 0 ) ;
F_101 ( V_182 ) ;
}
V_8 = F_92 ( V_27 , 1 ) ;
F_4 ( V_8 == 0 ) ;
}
}
void F_102 ( struct V_26 * V_27 )
{
if ( ! V_27 ) {
return;
}
F_103 ( V_27 , V_27 -> V_129 ) ;
F_104 ( & V_27 -> V_144 ) ;
F_31 ( V_27 ) ;
F_70 ( V_27 -> V_61 ) ;
F_4 ( F_105 ( & V_27 -> V_130 ) ) ;
F_71 ( V_27 ) ;
F_72 () ;
}
void F_106 ( struct V_26 * V_27 ,
struct V_181 * V_182 ,
int V_172 )
{
F_97 ( V_27 , V_182 , V_172 ) ;
F_102 ( V_27 ) ;
}
void F_107 ( struct V_26 * V_27 )
{
F_108 ( & V_27 -> V_133 ) ;
}
int F_109 ( struct V_26 * V_27 )
{
return F_110 ( & V_27 -> V_133 ) ;
}
void F_111 ( struct V_26 * V_27 )
{
if ( F_112 ( & V_27 -> V_133 , & V_27 -> V_132 ) ) {
F_113 ( & V_27 -> V_134 ) ;
F_99 ( & V_27 -> V_132 ) ;
}
}
void F_68 ( struct V_26 * V_27 , T_8 V_103 )
{
F_114 ( F_115 ( V_103 ) ) ;
F_4 ( F_105 ( & V_27 -> V_130 ) ) ;
F_116 ( & V_27 -> V_130 , F_117 ( V_103 ) ) ;
F_118 ( V_103 ) ;
F_119 ( F_115 ( V_103 ) ) ;
}
void F_103 ( struct V_26 * V_27 , T_8 V_103 )
{
F_114 ( F_115 ( V_103 ) ) ;
F_4 ( ! F_105 ( & V_27 -> V_130 ) ) ;
F_120 ( & V_27 -> V_130 ) ;
F_121 ( V_103 ) ;
F_119 ( F_115 ( V_103 ) ) ;
}
void F_122 ( struct V_26 * V_27 ,
T_8 V_103 )
{
F_4 ( ! F_105 ( & V_27 -> V_130 ) ) ;
F_4 ( F_123 ( F_115 ( V_103 ) ) ) ;
F_124 ( & V_27 -> V_130 , F_125 ( V_103 ) ) ;
}
void F_126 ( struct V_26 * V_27 ,
T_8 V_103 )
{
F_4 ( ! F_105 ( & V_27 -> V_130 ) ) ;
F_4 ( F_123 ( F_115 ( V_103 ) ) ) ;
F_124 ( & V_27 -> V_130 ,
F_117 ( V_103 ) ) ;
}
struct V_26 * F_127 ( T_8 V_103 )
{
F_4 ( F_123 ( F_115 ( V_103 ) ) ) ;
F_4 ( ! F_105 ( F_125 ( V_103 ) ) ) ;
return F_128 ( F_125 ( V_103 ) -> V_183 ,
struct V_26 , V_130 ) ;
}
static struct V_98 * F_129 ( void )
{
struct V_98 * V_29 ;
int V_109 ;
F_130 ( V_29 , V_184 , V_185 ) ;
if ( V_29 == NULL )
return NULL ;
F_62 ( & V_29 -> V_164 ) ;
F_62 ( & V_29 -> V_165 ) ;
F_62 ( & V_29 -> V_166 ) ;
for ( V_109 = 0 ; V_109 < V_186 ; V_109 ++ ) {
V_29 -> V_187 [ V_109 ] . V_188 = 0 ;
V_29 -> V_187 [ V_109 ] . V_189 = 1 << V_109 ;
V_29 -> V_187 [ V_109 ] . V_190 = NULL ;
}
F_64 ( & V_29 -> V_167 , 1 ) ;
F_63 ( & V_29 -> V_191 ) ;
F_131 ( & V_29 -> V_192 ) ;
F_132 ( & V_29 -> V_193 ) ;
F_114 ( & V_29 -> V_193 ) ;
return V_29 ;
}
struct V_98 *
F_133 ( struct V_26 * V_27 , struct V_98 * V_194 ,
const struct V_81 * V_65 , T_12 type , int V_195 )
{
struct V_96 * V_97 ;
struct V_98 * V_29 ;
T_5 V_30 ;
T_4 V_196 ;
int V_197 = 0 ;
F_4 ( V_27 != NULL ) ;
F_4 ( V_194 == NULL ) ;
F_4 ( V_27 -> V_61 != NULL ) ;
F_4 ( V_65 -> V_65 [ 0 ] != 0 ) ;
F_134 ( V_27 -> V_61 , ( void * ) V_65 , & V_30 , 0 ) ;
V_97 = F_135 ( V_27 -> V_61 , & V_30 , ( void * ) V_65 ) ;
if ( V_97 != NULL ) {
F_136 ( V_27 -> V_61 , & V_30 , 0 ) ;
V_29 = F_46 ( V_97 , struct V_98 , V_99 ) ;
if ( V_27 -> V_198 && V_27 -> V_198 -> V_199 ) {
F_114 ( & V_29 -> V_193 ) ;
F_119 ( & V_29 -> V_193 ) ;
}
if ( F_137 ( V_29 -> V_200 < 0 ) ) {
F_55 ( V_29 ) ;
V_29 = NULL ;
}
return V_29 ;
}
V_196 = F_138 ( & V_30 ) ;
F_136 ( V_27 -> V_61 , & V_30 , 0 ) ;
if ( V_195 == 0 )
return NULL ;
F_139 ( type >= V_201 && type < V_202 ,
L_52 , type ) ;
V_29 = F_129 () ;
if ( ! V_29 )
return NULL ;
V_29 -> V_203 = F_60 ( V_27 -> V_61 , & V_30 ) ;
V_29 -> V_100 = * V_65 ;
V_29 -> V_204 = type ;
V_29 -> V_205 = V_206 ;
F_140 ( V_27 -> V_61 , & V_30 , 1 ) ;
V_97 = ( V_196 == F_138 ( & V_30 ) ) ? NULL :
F_135 ( V_27 -> V_61 , & V_30 , ( void * ) V_65 ) ;
if ( V_97 != NULL ) {
F_136 ( V_27 -> V_61 , & V_30 , 1 ) ;
F_141 ( & V_29 -> V_192 ) ;
F_119 ( & V_29 -> V_193 ) ;
F_142 ( V_29 , V_184 , sizeof *V_29 ) ;
V_29 = F_46 ( V_97 , struct V_98 , V_99 ) ;
if ( V_27 -> V_198 && V_27 -> V_198 -> V_199 ) {
F_114 ( & V_29 -> V_193 ) ;
F_119 ( & V_29 -> V_193 ) ;
}
if ( F_137 ( V_29 -> V_200 < 0 ) ) {
F_55 ( V_29 ) ;
V_29 = NULL ;
}
return V_29 ;
}
F_143 ( V_27 -> V_61 , & V_30 , & V_29 -> V_99 ) ;
if ( F_14 ( & V_30 ) == 1 )
V_197 = F_109 ( V_27 ) ;
F_136 ( V_27 -> V_61 , & V_30 , 1 ) ;
if ( V_27 -> V_198 && V_27 -> V_198 -> V_199 ) {
int V_8 ;
F_144 ( V_207 , 2 ) ;
V_8 = V_27 -> V_198 -> V_199 ( V_29 ) ;
if ( V_8 < 0 ) {
F_7 ( L_53 V_208 L_54
V_208 L_55 , V_27 -> V_127 -> V_209 ,
V_65 -> V_65 [ 0 ] , V_65 -> V_65 [ 1 ] , V_8 ) ;
if ( V_29 -> V_210 ) {
F_145 ( V_29 -> V_210 , V_29 -> V_200 ) ;
V_29 -> V_210 = NULL ;
}
V_29 -> V_200 = V_8 ;
F_119 ( & V_29 -> V_193 ) ;
F_55 ( V_29 ) ;
return NULL ;
}
}
F_119 ( & V_29 -> V_193 ) ;
if ( F_38 ( V_27 ) && V_197 == 1 ) {
F_114 ( F_115 ( V_7 ) ) ;
F_122 ( V_27 , V_7 ) ;
F_119 ( F_115 ( V_7 ) ) ;
}
return V_29 ;
}
struct V_98 * F_51 ( struct V_98 * V_29 )
{
F_4 ( V_29 != NULL ) ;
F_4 ( V_29 != V_211 ) ;
F_108 ( & V_29 -> V_167 ) ;
F_23 ( V_170 , L_56 , V_29 ,
F_89 ( & V_29 -> V_167 ) ) ;
return V_29 ;
}
static void F_146 ( T_5 * V_30 ,
struct V_98 * V_29 )
{
struct V_106 * V_107 = V_29 -> V_203 ;
if ( ! F_105 ( & V_29 -> V_164 ) ) {
F_90 ( V_169 , V_29 ) ;
F_147 () ;
}
if ( ! F_105 ( & V_29 -> V_165 ) ) {
F_90 ( V_169 , V_29 ) ;
F_147 () ;
}
if ( ! F_105 ( & V_29 -> V_166 ) ) {
F_90 ( V_169 , V_29 ) ;
F_147 () ;
}
F_148 ( V_107 -> V_126 -> V_61 ,
V_30 , & V_29 -> V_99 ) ;
F_141 ( & V_29 -> V_192 ) ;
if ( F_14 ( V_30 ) == 0 )
F_111 ( V_107 -> V_126 ) ;
}
int F_55 ( struct V_98 * V_29 )
{
struct V_26 * V_27 = F_74 ( V_29 ) ;
T_5 V_30 ;
F_149 ( & V_29 -> V_167 , 0 , V_212 ) ;
F_23 ( V_170 , L_57 ,
V_29 , F_89 ( & V_29 -> V_167 ) - 1 ) ;
F_150 ( V_27 -> V_61 , & V_29 -> V_100 , & V_30 ) ;
if ( F_151 ( V_27 -> V_61 , & V_30 , & V_29 -> V_167 ) ) {
F_146 ( & V_30 , V_29 ) ;
F_136 ( V_27 -> V_61 , & V_30 , 1 ) ;
if ( V_27 -> V_198 && V_27 -> V_198 -> V_213 )
V_27 -> V_198 -> V_213 ( V_29 ) ;
F_142 ( V_29 , V_184 , sizeof *V_29 ) ;
return 1 ;
}
return 0 ;
}
int F_53 ( struct V_98 * V_29 )
{
struct V_26 * V_27 = F_74 ( V_29 ) ;
F_149 ( & V_29 -> V_167 , 0 , V_212 ) ;
F_23 ( V_170 , L_57 ,
V_29 , F_89 ( & V_29 -> V_167 ) - 1 ) ;
if ( F_152 ( & V_29 -> V_167 ) ) {
T_5 V_30 ;
F_150 ( F_74 ( V_29 ) -> V_61 ,
& V_29 -> V_100 , & V_30 ) ;
F_146 ( & V_30 , V_29 ) ;
F_136 ( V_27 -> V_61 , & V_30 , 1 ) ;
if ( V_27 -> V_198 && V_27 -> V_198 -> V_213 )
V_27 -> V_198 -> V_213 ( V_29 ) ;
F_142 ( V_29 , V_184 , sizeof *V_29 ) ;
F_140 ( V_27 -> V_61 , & V_30 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_153 ( struct V_98 * V_29 , struct V_146 * V_214 ,
struct V_151 * V_152 )
{
F_154 ( V_29 ) ;
F_80 ( V_152 , L_58 ) ;
if ( V_152 -> V_154 & V_215 ) {
F_23 ( V_216 , L_59 ) ;
return;
}
F_4 ( F_105 ( & V_152 -> V_153 ) ) ;
F_155 ( & V_152 -> V_153 , V_214 ) ;
}
void F_156 ( struct V_151 * V_217 ,
struct V_151 * V_218 )
{
struct V_98 * V_29 = V_217 -> V_219 ;
F_154 ( V_29 ) ;
F_90 ( V_170 , V_29 ) ;
F_80 ( V_218 , L_60 , V_217 ) ;
if ( V_218 -> V_154 & V_215 ) {
F_23 ( V_216 , L_59 ) ;
goto V_220;
}
F_4 ( F_105 ( & V_218 -> V_153 ) ) ;
F_116 ( & V_218 -> V_153 , & V_217 -> V_153 ) ;
V_220: ;
}
void F_84 ( struct V_151 * V_152 )
{
int type = V_152 -> V_219 -> V_204 ;
F_154 ( V_152 -> V_219 ) ;
if ( type == V_221 || type == V_222 )
F_157 ( V_152 ) ;
else if ( type == V_223 )
F_158 ( V_152 ) ;
F_120 ( & V_152 -> V_153 ) ;
}
void F_159 ( struct V_98 * V_29 , struct V_224 * V_225 )
{
V_225 -> V_204 = V_29 -> V_204 ;
V_225 -> V_100 = V_29 -> V_100 ;
}
void F_2 ( T_8 V_103 , int V_226 )
{
struct V_146 * V_43 ;
if ( ! ( ( V_227 | V_169 ) & V_226 ) )
return;
F_114 ( F_115 ( V_103 ) ) ;
F_76 (tmp, ldlm_namespace_list(client)) {
struct V_26 * V_27 ;
V_27 = F_77 ( V_43 , struct V_26 , V_130 ) ;
F_160 ( V_226 , V_27 ) ;
}
F_119 ( F_115 ( V_103 ) ) ;
}
static int F_161 ( T_7 * V_78 , T_5 * V_30 ,
struct V_96 * V_97 , void * V_163 )
{
struct V_98 * V_29 = F_87 ( V_78 , V_97 ) ;
int V_226 = ( int ) ( unsigned long ) V_163 ;
F_75 ( V_29 ) ;
F_90 ( V_226 , V_29 ) ;
F_79 ( V_29 ) ;
return 0 ;
}
void F_160 ( int V_226 , struct V_26 * V_27 )
{
if ( ! ( ( V_227 | V_169 ) & V_226 ) )
return;
F_23 ( V_226 , L_61 ,
F_24 ( V_27 ) , F_89 ( & V_27 -> V_133 ) ,
F_38 ( V_27 ) ? L_62 : L_63 ) ;
if ( F_162 ( F_163 () , V_27 -> V_228 ) )
return;
F_91 ( V_27 -> V_61 ,
F_161 ,
( void * ) ( unsigned long ) V_226 ) ;
F_98 ( & V_27 -> V_132 ) ;
V_27 -> V_228 = F_164 ( 10 ) ;
F_99 ( & V_27 -> V_132 ) ;
}
void F_90 ( int V_226 , struct V_98 * V_29 )
{
struct V_151 * V_152 ;
unsigned int V_229 = 0 ;
F_165 ( V_84 == 4 ) ;
if ( ! ( ( V_227 | V_169 ) & V_226 ) )
return;
F_23 ( V_226 , L_64 V_168 L_42 V_168 L_42 V_168 L_42 V_168
L_43 , V_29 , V_29 -> V_100 . V_65 [ 0 ] , V_29 -> V_100 . V_65 [ 1 ] ,
V_29 -> V_100 . V_65 [ 2 ] , V_29 -> V_100 . V_65 [ 3 ] ,
F_89 ( & V_29 -> V_167 ) ) ;
if ( ! F_105 ( & V_29 -> V_164 ) ) {
F_23 ( V_226 , L_65 ) ;
F_166 (lock, &res->lr_granted,
l_res_link) {
F_167 ( V_226 , V_152 , L_66 ) ;
if ( ! ( V_226 & V_230 ) &&
++ V_229 > V_13 ) {
F_23 ( V_226 , L_67
L_68 , V_229 ) ;
break;
}
}
}
if ( ! F_105 ( & V_29 -> V_165 ) ) {
F_23 ( V_226 , L_69 ) ;
F_168 (lock, &res->lr_converting, l_res_link)
F_167 ( V_226 , V_152 , L_66 ) ;
}
if ( ! F_105 ( & V_29 -> V_166 ) ) {
F_23 ( V_226 , L_70 ) ;
F_168 (lock, &res->lr_waiting, l_res_link)
F_167 ( V_226 , V_152 , L_66 ) ;
}
}
