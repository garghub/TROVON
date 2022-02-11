static T_1 F_1 ( struct V_1 * V_1 , const char * V_2 ,
T_2 V_3 , T_3 * V_4 )
{
F_2 ( V_5 , V_6 ) ;
F_2 ( V_7 , V_6 ) ;
RETURN ( V_3 ) ;
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
V_15 ;
F_4 ( V_16 == NULL ) ;
V_17 = F_5 ( V_18 ,
V_19 ,
NULL , NULL ) ;
if ( F_6 ( V_17 ) ) {
F_7 ( L_4 ) ;
V_8 = F_8 ( V_17 ) ;
GOTO ( V_20 , V_8 ) ;
}
V_16 = F_5 ( L_5 ,
V_17 ,
NULL , NULL ) ;
if ( F_6 ( V_16 ) ) {
F_7 ( L_4 ) ;
V_8 = F_8 ( V_16 ) ;
GOTO ( V_21 , V_8 ) ;
}
V_22 = F_5 ( L_6 ,
V_17 ,
NULL , NULL ) ;
if ( F_6 ( V_22 ) ) {
F_7 ( L_4 ) ;
V_8 = F_8 ( V_22 ) ;
GOTO ( V_23 , V_8 ) ;
}
V_8 = F_9 ( V_17 , V_10 , NULL ) ;
RETURN ( 0 ) ;
V_23:
F_10 ( & V_16 ) ;
V_21:
F_10 ( & V_17 ) ;
V_20:
V_22 = NULL ;
V_17 = NULL ;
V_16 = NULL ;
RETURN ( V_8 ) ;
}
void F_11 ( void )
{
if ( V_22 )
F_10 ( & V_22 ) ;
if ( V_16 )
F_10 ( & V_16 ) ;
if ( V_17 )
F_10 ( & V_17 ) ;
V_22 = NULL ;
V_17 = NULL ;
V_16 = NULL ;
}
static int F_12 ( struct V_24 * V_25 , void * V_26 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
T_4 V_30 = 0 ;
T_5 V_31 ;
int V_32 ;
F_13 (ns->ns_rs_hash, &bd, i)
V_30 += F_14 ( & V_31 ) ;
return F_15 ( V_25 , & V_30 ) ;
}
static int F_16 ( struct V_24 * V_25 , void * V_26 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
T_4 V_33 ;
V_33 = F_17 ( V_28 -> V_34 , V_35 ,
V_36 ) ;
return F_15 ( V_25 , & V_33 ) ;
}
static int F_18 ( struct V_24 * V_25 , void * V_26 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
T_6 * V_37 = & V_28 -> V_38 ;
if ( F_19 ( V_28 ) )
V_37 = & V_28 -> V_39 ;
return F_20 ( V_25 , V_37 ) ;
}
static T_1 F_21 ( struct V_1 * V_1 , const char * V_2 ,
T_2 V_3 , T_3 * V_4 )
{
struct V_27 * V_28 = ( (struct V_24 * ) V_1 -> V_40 ) -> V_29 ;
char V_41 [ V_42 + 1 ] , * V_43 ;
unsigned long V_44 ;
int V_45 ;
V_41 [ V_42 ] = '\0' ;
if ( F_22 ( V_41 , V_2 , V_42 ) )
return - V_46 ;
if ( strncmp ( V_41 , L_7 , 5 ) == 0 ) {
F_23 ( V_6 ,
L_8 ,
F_24 ( V_28 ) ) ;
if ( F_19 ( V_28 ) ) {
int V_47 , V_48 = V_28 -> V_39 ;
V_47 = F_25 ( V_28 , V_48 , 0 ,
V_49 ) ;
if ( V_47 < V_48 ) {
F_23 ( V_6 ,
L_9
L_10 , V_48 ,
V_47 ) ;
return - V_50 ;
}
} else {
V_44 = V_28 -> V_38 ;
V_28 -> V_38 = 0 ;
F_25 ( V_28 , 0 , 0 , V_49 ) ;
V_28 -> V_38 = V_44 ;
}
return V_3 ;
}
V_44 = F_26 ( V_41 , & V_43 , 0 ) ;
if ( V_41 == V_43 ) {
F_7 ( L_11 ) ;
return - V_50 ;
}
V_45 = ( V_44 == 0 ) ;
if ( F_19 ( V_28 ) ) {
if ( ! V_45 )
V_28 -> V_38 = ( unsigned int ) V_44 ;
if ( V_44 > V_28 -> V_39 )
V_44 = V_28 -> V_39 ;
V_44 = V_28 -> V_39 - V_44 ;
F_23 ( V_6 ,
L_12 ,
F_24 ( V_28 ) , V_28 -> V_39 ,
( unsigned int ) V_44 ) ;
F_25 ( V_28 , V_44 , V_51 , V_49 ) ;
if ( ! V_45 ) {
F_23 ( V_6 ,
L_13 ,
F_24 ( V_28 ) ) ;
V_28 -> V_52 &= ~ V_53 ;
}
} else {
F_23 ( V_6 ,
L_14 ,
F_24 ( V_28 ) , V_28 -> V_38 ,
( unsigned int ) V_44 ) ;
V_28 -> V_38 = ( unsigned int ) V_44 ;
F_25 ( V_28 , 0 , V_51 , V_49 ) ;
if ( V_45 &&
( V_28 -> V_54 & V_53 ) ) {
F_23 ( V_6 ,
L_15 ,
F_24 ( V_28 ) ) ;
V_28 -> V_52 |= V_53 ;
}
}
return V_3 ;
}
static int F_27 ( struct V_24 * V_25 , void * V_26 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_55 = F_28 ( V_28 ) ;
return F_20 ( V_25 , & V_55 ) ;
}
static T_1 F_29 ( struct V_1 * V_1 , const char * V_2 ,
T_2 V_3 , T_3 * V_4 )
{
struct V_27 * V_28 = ( (struct V_24 * ) V_1 -> V_40 ) -> V_29 ;
unsigned int V_55 = - 1 ;
int V_8 ;
V_8 = F_30 ( V_1 , V_2 , V_3 , & V_55 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_55 == 0 )
V_28 -> V_52 &= ~ V_56 ;
else if ( V_28 -> V_54 & V_56 )
V_28 -> V_52 |= V_56 ;
return V_3 ;
}
void F_31 ( struct V_27 * V_28 )
{
if ( V_28 -> V_57 == NULL )
F_7 ( L_16 ,
F_24 ( V_28 ) ) ;
else
F_10 ( & V_28 -> V_57 ) ;
if ( V_28 -> V_34 != NULL )
F_32 ( & V_28 -> V_34 ) ;
}
int F_33 ( struct V_27 * V_28 )
{
struct V_9 V_58 [ 2 ] ;
char V_59 [ V_42 + 1 ] ;
T_7 * V_60 ;
F_4 ( V_28 != NULL ) ;
F_4 ( V_28 -> V_61 != NULL ) ;
if ( V_28 -> V_57 != NULL ) {
V_60 = V_28 -> V_57 ;
} else {
V_60 = F_34 ( F_24 ( V_28 ) , V_16 ) ;
if ( V_60 == NULL )
return - V_62 ;
V_28 -> V_57 = V_60 ;
}
V_28 -> V_34 = F_35 ( V_63 , 0 ) ;
if ( V_28 -> V_34 == NULL )
return - V_62 ;
F_36 ( V_28 -> V_34 , V_35 ,
V_64 , L_17 , L_17 ) ;
V_59 [ V_42 ] = '\0' ;
memset ( V_58 , 0 , sizeof( V_58 ) ) ;
V_58 [ 0 ] . V_65 = V_59 ;
F_37 ( L_18 , V_28 , & V_66 ) ;
F_37 ( L_19 , V_28 , & V_67 ) ;
if ( F_38 ( V_28 ) ) {
F_37 ( L_20 , & V_28 -> V_39 ,
& V_68 ) ;
F_37 ( L_21 , V_28 , & V_69 ) ;
F_37 ( L_22 , & V_28 -> V_70 ,
& V_12 ) ;
F_37 ( L_23 , V_28 , & V_71 ) ;
} else {
F_37 ( L_24 , & V_28 -> V_72 ,
& V_12 ) ;
F_37 ( L_25 , & V_28 -> V_73 ,
& V_68 ) ;
F_37 ( L_26 , & V_28 -> V_74 ,
& V_12 ) ;
F_37 ( L_27 , & V_28 -> V_75 ,
& V_12 ) ;
F_37 ( L_28 , & V_28 -> V_76 ,
& V_12 ) ;
F_37 ( L_29 , & V_28 -> V_77 ,
& V_12 ) ;
}
return 0 ;
}
static unsigned F_39 ( T_8 * V_78 ,
const void * V_79 , unsigned V_80 )
{
const struct V_81 * V_82 = V_79 ;
unsigned V_83 = 0 ;
unsigned V_32 ;
for ( V_32 = 0 ; V_32 < V_84 ; V_32 ++ )
V_83 += V_82 -> V_65 [ V_32 ] ;
return V_83 & V_80 ;
}
static unsigned F_40 ( T_8 * V_78 ,
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
struct V_98 * V_30 ;
V_30 = F_46 ( V_97 , struct V_98 , V_99 ) ;
return & V_30 -> V_100 ;
}
static int F_47 ( const void * V_79 , struct V_96 * V_97 )
{
struct V_98 * V_30 ;
V_30 = F_46 ( V_97 , struct V_98 , V_99 ) ;
return F_48 ( ( const struct V_81 * ) V_79 ,
( const struct V_81 * ) & V_30 -> V_100 ) ;
}
static void * F_49 ( struct V_96 * V_97 )
{
return F_46 ( V_97 , struct V_98 , V_99 ) ;
}
static void F_50 ( T_8 * V_78 , struct V_96 * V_97 )
{
struct V_98 * V_30 ;
V_30 = F_46 ( V_97 , struct V_98 , V_99 ) ;
F_51 ( V_30 ) ;
}
static void F_52 ( T_8 * V_78 , struct V_96 * V_97 )
{
struct V_98 * V_30 ;
V_30 = F_46 ( V_97 , struct V_98 , V_99 ) ;
F_53 ( V_30 ) ;
}
static void F_54 ( T_8 * V_78 , struct V_96 * V_97 )
{
struct V_98 * V_30 ;
V_30 = F_46 ( V_97 , struct V_98 , V_99 ) ;
F_55 ( V_30 ) ;
}
struct V_27 * F_56 ( struct V_101 * V_102 , char * V_65 ,
T_9 V_103 ,
T_10 V_104 ,
T_11 V_105 )
{
struct V_27 * V_28 = NULL ;
struct V_106 * V_107 ;
T_12 * V_108 ;
T_5 V_31 ;
int V_109 ;
int V_8 ;
V_15 ;
F_4 ( V_102 != NULL ) ;
V_8 = F_57 () ;
if ( V_8 ) {
F_7 ( L_30 , V_8 ) ;
RETURN ( NULL ) ;
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
F_58 ( V_28 ) ;
if ( ! V_28 )
GOTO ( V_113 , NULL ) ;
V_28 -> V_61 = F_59 ( V_65 ,
V_108 -> V_114 , V_108 -> V_114 ,
V_108 -> V_115 , sizeof( * V_107 ) ,
V_116 ,
V_117 ,
V_108 -> V_118 ,
V_119 |
V_120 |
V_121 |
V_122 ) ;
if ( V_28 -> V_61 == NULL )
GOTO ( V_123 , NULL ) ;
F_13 (ns->ns_rs_hash, &bd, idx) {
V_107 = F_60 ( V_28 -> V_61 , & V_31 ) ;
F_61 ( & V_107 -> V_124 , V_125 , 0 ) ;
V_107 -> V_126 = V_28 ;
}
V_28 -> V_127 = V_102 ;
V_28 -> V_128 = V_104 ;
V_28 -> V_129 = V_103 ;
F_62 ( & V_28 -> V_130 ) ;
F_62 ( & V_28 -> V_131 ) ;
F_63 ( & V_28 -> V_132 ) ;
F_64 ( & V_28 -> V_133 , 0 ) ;
F_65 ( & V_28 -> V_134 ) ;
V_28 -> V_74 = V_135 ;
V_28 -> V_75 = V_136 ;
V_28 -> V_76 = V_137 ;
V_28 -> V_77 = V_138 ;
V_28 -> V_39 = 0 ;
V_28 -> V_38 = V_139 ;
V_28 -> V_70 = V_140 ;
V_28 -> V_72 = V_141 ;
V_28 -> V_73 = 0 ;
V_28 -> V_54 = 0 ;
V_28 -> V_52 = 0 ;
V_28 -> V_142 = 0 ;
V_8 = F_33 ( V_28 ) ;
if ( V_8 != 0 ) {
F_7 ( L_32 , V_8 ) ;
GOTO ( V_143 , V_8 ) ;
}
V_109 = F_66 ( F_67 ( V_103 ) ) ;
V_8 = F_68 ( & V_28 -> V_144 , V_28 , V_109 , V_103 ) ;
if ( V_8 ) {
F_7 ( L_33 , V_8 ) ;
GOTO ( V_145 , V_8 ) ;
}
F_69 ( V_28 , V_103 ) ;
RETURN ( V_28 ) ;
V_145:
F_31 ( V_28 ) ;
F_70 ( V_28 , 0 ) ;
V_143:
F_71 ( V_28 -> V_61 ) ;
V_123:
F_72 ( V_28 ) ;
V_113:
F_73 () ;
RETURN ( NULL ) ;
}
static void F_74 ( struct V_98 * V_30 , struct V_146 * V_147 ,
T_4 V_148 )
{
struct V_146 * V_44 ;
int V_8 = 0 , V_103 = F_38 ( F_75 ( V_30 ) ) ;
bool V_149 = ! ! ( V_148 & V_150 ) ;
do {
struct V_151 * V_152 = NULL ;
F_76 ( V_30 ) ;
F_77 (tmp, q) {
V_152 = F_78 ( V_44 , struct V_151 ,
V_153 ) ;
if ( V_152 -> V_154 & V_155 ) {
V_152 = NULL ;
continue;
}
F_79 ( V_152 ) ;
V_152 -> V_154 |= V_155 ;
break;
}
if ( V_152 == NULL ) {
F_80 ( V_30 ) ;
break;
}
V_152 -> V_154 |= V_156 ;
V_152 -> V_154 |= V_157 ;
V_152 -> V_154 |= V_148 ;
if ( V_149 )
V_152 -> V_154 |= V_150 ;
if ( V_149 && ( V_152 -> V_158 || V_152 -> V_159 ) ) {
F_80 ( V_30 ) ;
F_81 ( V_152 , L_34 ) ;
if ( V_152 -> V_160 )
V_152 -> V_160 ( V_152 , 0 , NULL ) ;
F_82 ( V_152 ) ;
continue;
}
if ( V_103 ) {
struct V_161 V_162 ;
F_80 ( V_30 ) ;
F_83 ( V_152 , & V_162 ) ;
V_8 = F_84 ( & V_162 , V_51 ) ;
if ( V_8 )
F_7 ( L_35 , V_8 ) ;
} else {
F_85 ( V_152 ) ;
F_80 ( V_30 ) ;
F_81 ( V_152 , L_36
L_37 ) ;
F_86 ( V_152 ) ;
}
F_82 ( V_152 ) ;
} while ( 1 );
}
static int F_87 ( T_8 * V_78 , T_5 * V_31 ,
struct V_96 * V_97 , void * V_163 )
{
struct V_98 * V_30 = F_88 ( V_78 , V_97 ) ;
T_4 V_148 = * ( T_4 * ) V_163 ;
F_74 ( V_30 , & V_30 -> V_164 , V_148 ) ;
F_74 ( V_30 , & V_30 -> V_165 , V_148 ) ;
F_74 ( V_30 , & V_30 -> V_166 , V_148 ) ;
return 0 ;
}
static int F_89 ( T_8 * V_78 , T_5 * V_31 ,
struct V_96 * V_97 , void * V_163 )
{
struct V_98 * V_30 = F_88 ( V_78 , V_97 ) ;
F_76 ( V_30 ) ;
F_7 ( L_38
L_39
L_40 ,
F_24 ( F_75 ( V_30 ) ) ,
F_66 ( & V_30 -> V_167 ) - 1 ) ;
F_7 ( L_41 V_168 L_42 V_168 L_42 V_168 L_42
V_168 L_43 , V_30 ,
V_30 -> V_100 . V_65 [ 0 ] , V_30 -> V_100 . V_65 [ 1 ] ,
V_30 -> V_100 . V_65 [ 2 ] , V_30 -> V_100 . V_65 [ 3 ] ,
F_66 ( & V_30 -> V_167 ) - 1 ) ;
F_90 ( V_169 , V_30 ) ;
F_80 ( V_30 ) ;
return 0 ;
}
int F_70 ( struct V_27 * V_28 , T_4 V_148 )
{
if ( V_28 == NULL ) {
F_23 ( V_170 , L_44 ) ;
return V_171 ;
}
F_91 ( V_28 -> V_61 , F_87 , & V_148 ) ;
F_91 ( V_28 -> V_61 , F_89 , NULL ) ;
return V_171 ;
}
static int F_92 ( struct V_27 * V_28 , int V_172 )
{
V_15 ;
F_70 ( V_28 , V_172 ? V_150 : 0 ) ;
if ( F_66 ( & V_28 -> V_133 ) > 0 ) {
struct V_173 V_174 = F_93 ( V_175 , NULL ) ;
int V_8 ;
F_23 ( V_6 ,
L_45 ,
F_24 ( V_28 ) , F_66 ( & V_28 -> V_133 ) ) ;
V_176:
if ( V_172 )
V_174 = F_94 ( V_177 * V_178 / 4 , NULL , NULL ) ;
V_8 = F_95 ( V_28 -> V_134 ,
F_66 ( & V_28 -> V_133 ) == 0 , & V_174 ) ;
if ( V_172 && V_8 == - V_179 ) {
F_96 ( L_46
L_47
L_48 , F_24 ( V_28 ) ,
F_66 ( & V_28 -> V_133 ) , V_8 ) ;
GOTO ( V_176 , V_8 ) ;
}
if ( F_66 ( & V_28 -> V_133 ) ) {
F_96 ( L_49
L_50 ,
F_24 ( V_28 ) ,
F_66 ( & V_28 -> V_133 ) , V_8 ) ;
RETURN ( V_180 ) ;
}
F_23 ( V_6 , L_51 ,
F_24 ( V_28 ) ) ;
}
RETURN ( V_171 ) ;
}
void F_97 ( struct V_27 * V_28 ,
struct V_181 * V_182 ,
int V_172 )
{
int V_8 ;
V_15 ;
if ( ! V_28 ) {
EXIT ;
return;
}
F_98 ( & V_28 -> V_132 ) ;
V_28 -> V_142 = 1 ;
F_99 ( & V_28 -> V_132 ) ;
V_8 = F_92 ( V_28 , V_172 ) ;
if ( V_8 != V_171 ) {
if ( V_182 ) {
F_100 ( V_182 , 0 ) ;
F_101 ( V_182 ) ;
}
V_8 = F_92 ( V_28 , 1 ) ;
F_4 ( V_8 == 0 ) ;
}
EXIT ;
}
void F_102 ( struct V_27 * V_28 )
{
V_15 ;
if ( ! V_28 ) {
EXIT ;
return;
}
F_103 ( V_28 , V_28 -> V_129 ) ;
F_104 ( & V_28 -> V_144 ) ;
F_31 ( V_28 ) ;
F_71 ( V_28 -> V_61 ) ;
F_4 ( F_105 ( & V_28 -> V_130 ) ) ;
F_72 ( V_28 ) ;
F_73 () ;
EXIT ;
}
void F_106 ( struct V_27 * V_28 ,
struct V_181 * V_182 ,
int V_172 )
{
F_97 ( V_28 , V_182 , V_172 ) ;
F_102 ( V_28 ) ;
}
void F_107 ( struct V_27 * V_28 )
{
F_108 ( & V_28 -> V_133 ) ;
}
void F_109 ( struct V_27 * V_28 )
{
if ( F_110 ( & V_28 -> V_133 , & V_28 -> V_132 ) ) {
F_111 ( & V_28 -> V_134 ) ;
F_99 ( & V_28 -> V_132 ) ;
}
}
void F_69 ( struct V_27 * V_28 , T_9 V_103 )
{
F_112 ( F_113 ( V_103 ) ) ;
F_4 ( F_105 ( & V_28 -> V_130 ) ) ;
F_114 ( & V_28 -> V_130 , F_115 ( V_103 ) ) ;
F_108 ( F_67 ( V_103 ) ) ;
F_116 ( F_113 ( V_103 ) ) ;
}
void F_103 ( struct V_27 * V_28 , T_9 V_103 )
{
F_112 ( F_113 ( V_103 ) ) ;
F_4 ( ! F_105 ( & V_28 -> V_130 ) ) ;
F_117 ( & V_28 -> V_130 ) ;
F_118 ( F_67 ( V_103 ) ) ;
F_116 ( F_113 ( V_103 ) ) ;
}
void F_119 ( struct V_27 * V_28 , T_9 V_103 )
{
F_4 ( ! F_105 ( & V_28 -> V_130 ) ) ;
F_4 ( F_120 ( F_113 ( V_103 ) ) ) ;
F_121 ( & V_28 -> V_130 , F_115 ( V_103 ) ) ;
}
struct V_27 * F_122 ( T_9 V_103 )
{
F_4 ( F_120 ( F_113 ( V_103 ) ) ) ;
F_4 ( ! F_105 ( F_115 ( V_103 ) ) ) ;
return F_123 ( F_115 ( V_103 ) -> V_183 ,
struct V_27 , V_130 ) ;
}
static struct V_98 * F_124 ( void )
{
struct V_98 * V_30 ;
int V_109 ;
F_125 ( V_30 , V_184 , V_185 ) ;
if ( V_30 == NULL )
return NULL ;
F_62 ( & V_30 -> V_164 ) ;
F_62 ( & V_30 -> V_165 ) ;
F_62 ( & V_30 -> V_166 ) ;
for ( V_109 = 0 ; V_109 < V_186 ; V_109 ++ ) {
V_30 -> V_187 [ V_109 ] . V_188 = 0 ;
V_30 -> V_187 [ V_109 ] . V_189 = 1 << V_109 ;
V_30 -> V_187 [ V_109 ] . V_190 = NULL ;
}
F_64 ( & V_30 -> V_167 , 1 ) ;
F_63 ( & V_30 -> V_191 ) ;
F_126 ( & V_30 -> V_192 ) ;
F_127 ( & V_30 -> V_193 ) ;
F_112 ( & V_30 -> V_193 ) ;
return V_30 ;
}
struct V_98 *
F_128 ( struct V_27 * V_28 , struct V_98 * V_194 ,
const struct V_81 * V_65 , T_13 type , int V_195 )
{
struct V_96 * V_97 ;
struct V_98 * V_30 ;
T_5 V_31 ;
T_4 V_196 ;
F_4 ( V_28 != NULL ) ;
F_4 ( V_194 == NULL ) ;
F_4 ( V_28 -> V_61 != NULL ) ;
F_4 ( V_65 -> V_65 [ 0 ] != 0 ) ;
F_129 ( V_28 -> V_61 , ( void * ) V_65 , & V_31 , 0 ) ;
V_97 = F_130 ( V_28 -> V_61 , & V_31 , ( void * ) V_65 ) ;
if ( V_97 != NULL ) {
F_131 ( V_28 -> V_61 , & V_31 , 0 ) ;
V_30 = F_46 ( V_97 , struct V_98 , V_99 ) ;
if ( V_28 -> V_197 && V_28 -> V_197 -> V_198 ) {
F_112 ( & V_30 -> V_193 ) ;
F_116 ( & V_30 -> V_193 ) ;
}
if ( F_132 ( V_30 -> V_199 < 0 ) ) {
F_55 ( V_30 ) ;
V_30 = NULL ;
}
return V_30 ;
}
V_196 = F_133 ( & V_31 ) ;
F_131 ( V_28 -> V_61 , & V_31 , 0 ) ;
if ( V_195 == 0 )
return NULL ;
F_134 ( type >= V_200 && type < V_201 ,
L_52 , type ) ;
V_30 = F_124 () ;
if ( ! V_30 )
return NULL ;
V_30 -> V_202 = F_60 ( V_28 -> V_61 , & V_31 ) ;
V_30 -> V_100 = * V_65 ;
V_30 -> V_203 = type ;
V_30 -> V_204 = V_205 ;
F_135 ( V_28 -> V_61 , & V_31 , 1 ) ;
V_97 = ( V_196 == F_133 ( & V_31 ) ) ? NULL :
F_130 ( V_28 -> V_61 , & V_31 , ( void * ) V_65 ) ;
if ( V_97 != NULL ) {
F_131 ( V_28 -> V_61 , & V_31 , 1 ) ;
F_136 ( & V_30 -> V_192 ) ;
F_116 ( & V_30 -> V_193 ) ;
F_137 ( V_30 , V_184 , sizeof *V_30 ) ;
V_30 = F_46 ( V_97 , struct V_98 , V_99 ) ;
if ( V_28 -> V_197 && V_28 -> V_197 -> V_198 ) {
F_112 ( & V_30 -> V_193 ) ;
F_116 ( & V_30 -> V_193 ) ;
}
if ( F_132 ( V_30 -> V_199 < 0 ) ) {
F_55 ( V_30 ) ;
V_30 = NULL ;
}
return V_30 ;
}
F_138 ( V_28 -> V_61 , & V_31 , & V_30 -> V_99 ) ;
if ( F_14 ( & V_31 ) == 1 )
F_107 ( V_28 ) ;
F_131 ( V_28 -> V_61 , & V_31 , 1 ) ;
if ( V_28 -> V_197 && V_28 -> V_197 -> V_198 ) {
int V_8 ;
F_139 ( V_206 , 2 ) ;
V_8 = V_28 -> V_197 -> V_198 ( V_30 ) ;
if ( V_8 < 0 ) {
F_7 ( L_53
V_168 L_54 , V_65 -> V_65 [ 0 ] , V_8 ) ;
if ( V_30 -> V_207 ) {
F_140 ( V_30 -> V_207 , V_30 -> V_199 ) ;
V_30 -> V_207 = NULL ;
}
V_30 -> V_199 = V_8 ;
F_116 ( & V_30 -> V_193 ) ;
F_55 ( V_30 ) ;
return NULL ;
}
}
F_116 ( & V_30 -> V_193 ) ;
return V_30 ;
}
struct V_98 * F_51 ( struct V_98 * V_30 )
{
F_4 ( V_30 != NULL ) ;
F_4 ( V_30 != V_208 ) ;
F_108 ( & V_30 -> V_167 ) ;
F_23 ( V_170 , L_55 , V_30 ,
F_66 ( & V_30 -> V_167 ) ) ;
return V_30 ;
}
static void F_141 ( T_5 * V_31 ,
struct V_98 * V_30 )
{
struct V_106 * V_107 = V_30 -> V_202 ;
if ( ! F_105 ( & V_30 -> V_164 ) ) {
F_90 ( V_169 , V_30 ) ;
F_142 () ;
}
if ( ! F_105 ( & V_30 -> V_165 ) ) {
F_90 ( V_169 , V_30 ) ;
F_142 () ;
}
if ( ! F_105 ( & V_30 -> V_166 ) ) {
F_90 ( V_169 , V_30 ) ;
F_142 () ;
}
F_143 ( V_107 -> V_126 -> V_61 ,
V_31 , & V_30 -> V_99 ) ;
F_136 ( & V_30 -> V_192 ) ;
if ( F_14 ( V_31 ) == 0 )
F_109 ( V_107 -> V_126 ) ;
}
int F_55 ( struct V_98 * V_30 )
{
struct V_27 * V_28 = F_75 ( V_30 ) ;
T_5 V_31 ;
F_144 ( & V_30 -> V_167 , 0 , V_209 ) ;
F_23 ( V_170 , L_56 ,
V_30 , F_66 ( & V_30 -> V_167 ) - 1 ) ;
F_145 ( V_28 -> V_61 , & V_30 -> V_100 , & V_31 ) ;
if ( F_146 ( V_28 -> V_61 , & V_31 , & V_30 -> V_167 ) ) {
F_141 ( & V_31 , V_30 ) ;
F_131 ( V_28 -> V_61 , & V_31 , 1 ) ;
if ( V_28 -> V_197 && V_28 -> V_197 -> V_210 )
V_28 -> V_197 -> V_210 ( V_30 ) ;
F_137 ( V_30 , V_184 , sizeof *V_30 ) ;
return 1 ;
}
return 0 ;
}
int F_53 ( struct V_98 * V_30 )
{
struct V_27 * V_28 = F_75 ( V_30 ) ;
F_144 ( & V_30 -> V_167 , 0 , V_209 ) ;
F_23 ( V_170 , L_56 ,
V_30 , F_66 ( & V_30 -> V_167 ) - 1 ) ;
if ( F_147 ( & V_30 -> V_167 ) ) {
T_5 V_31 ;
F_145 ( F_75 ( V_30 ) -> V_61 ,
& V_30 -> V_100 , & V_31 ) ;
F_141 ( & V_31 , V_30 ) ;
F_131 ( V_28 -> V_61 , & V_31 , 1 ) ;
if ( V_28 -> V_197 && V_28 -> V_197 -> V_210 )
V_28 -> V_197 -> V_210 ( V_30 ) ;
F_137 ( V_30 , V_184 , sizeof *V_30 ) ;
F_135 ( V_28 -> V_61 , & V_31 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_148 ( struct V_98 * V_30 , struct V_146 * V_211 ,
struct V_151 * V_152 )
{
F_149 ( V_30 ) ;
F_81 ( V_152 , L_57 ) ;
if ( V_152 -> V_212 ) {
F_23 ( V_213 , L_58 ) ;
return;
}
F_4 ( F_105 ( & V_152 -> V_153 ) ) ;
F_150 ( & V_152 -> V_153 , V_211 ) ;
}
void F_151 ( struct V_151 * V_214 ,
struct V_151 * V_215 )
{
struct V_98 * V_30 = V_214 -> V_216 ;
F_149 ( V_30 ) ;
F_90 ( V_170 , V_30 ) ;
F_81 ( V_215 , L_59 , V_214 ) ;
if ( V_215 -> V_212 ) {
F_23 ( V_213 , L_58 ) ;
goto V_217;
}
F_4 ( F_105 ( & V_215 -> V_153 ) ) ;
F_114 ( & V_215 -> V_153 , & V_214 -> V_153 ) ;
V_217: ;
}
void F_85 ( struct V_151 * V_152 )
{
int type = V_152 -> V_216 -> V_203 ;
F_149 ( V_152 -> V_216 ) ;
if ( type == V_218 || type == V_219 )
F_152 ( V_152 ) ;
else if ( type == V_220 )
F_153 ( V_152 ) ;
F_117 ( & V_152 -> V_153 ) ;
}
void F_154 ( struct V_98 * V_30 , struct V_221 * V_222 )
{
V_222 -> V_203 = V_30 -> V_203 ;
V_222 -> V_100 = V_30 -> V_100 ;
}
void F_2 ( T_9 V_103 , int V_223 )
{
struct V_146 * V_44 ;
if ( ! ( ( V_224 | V_169 ) & V_223 ) )
return;
F_112 ( F_113 ( V_103 ) ) ;
F_77 (tmp, ldlm_namespace_list(client)) {
struct V_27 * V_28 ;
V_28 = F_78 ( V_44 , struct V_27 , V_130 ) ;
F_155 ( V_223 , V_28 ) ;
}
F_116 ( F_113 ( V_103 ) ) ;
}
static int F_156 ( T_8 * V_78 , T_5 * V_31 ,
struct V_96 * V_97 , void * V_163 )
{
struct V_98 * V_30 = F_88 ( V_78 , V_97 ) ;
int V_223 = ( int ) ( unsigned long ) V_163 ;
F_76 ( V_30 ) ;
F_90 ( V_223 , V_30 ) ;
F_80 ( V_30 ) ;
return 0 ;
}
void F_155 ( int V_223 , struct V_27 * V_28 )
{
if ( ! ( ( V_224 | V_169 ) & V_223 ) )
return;
F_23 ( V_223 , L_60 ,
F_24 ( V_28 ) , F_66 ( & V_28 -> V_133 ) ,
F_38 ( V_28 ) ? L_61 : L_62 ) ;
if ( F_157 ( F_158 () , V_28 -> V_225 ) )
return;
F_91 ( V_28 -> V_61 ,
F_156 ,
( void * ) ( unsigned long ) V_223 ) ;
F_98 ( & V_28 -> V_132 ) ;
V_28 -> V_225 = F_159 ( 10 ) ;
F_99 ( & V_28 -> V_132 ) ;
}
void F_90 ( int V_223 , struct V_98 * V_30 )
{
struct V_151 * V_152 ;
unsigned int V_226 = 0 ;
F_160 ( V_84 == 4 ) ;
if ( ! ( ( V_224 | V_169 ) & V_223 ) )
return;
F_23 ( V_223 , L_63 V_168 L_42 V_168 L_42 V_168 L_42 V_168
L_43 , V_30 , V_30 -> V_100 . V_65 [ 0 ] , V_30 -> V_100 . V_65 [ 1 ] ,
V_30 -> V_100 . V_65 [ 2 ] , V_30 -> V_100 . V_65 [ 3 ] ,
F_66 ( & V_30 -> V_167 ) ) ;
if ( ! F_105 ( & V_30 -> V_164 ) ) {
F_23 ( V_223 , L_64 ) ;
F_161 (lock, &res->lr_granted,
l_res_link) {
F_162 ( V_223 , V_152 , L_65 ) ;
if ( ! ( V_223 & V_227 ) &&
++ V_226 > V_13 ) {
F_23 ( V_223 , L_66
L_67 , V_226 ) ;
break;
}
}
}
if ( ! F_105 ( & V_30 -> V_165 ) ) {
F_23 ( V_223 , L_68 ) ;
F_163 (lock, &res->lr_converting, l_res_link)
F_162 ( V_223 , V_152 , L_65 ) ;
}
if ( ! F_105 ( & V_30 -> V_166 ) ) {
F_23 ( V_223 , L_69 ) ;
F_163 (lock, &res->lr_waiting, l_res_link)
F_162 ( V_223 , V_152 , L_65 ) ;
}
}
