static T_1
F_1 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
F_2 ( V_5 , V_6 ) ;
F_2 ( V_7 , V_6 ) ;
return V_3 ;
}
int F_3 ( void )
{
int V_8 ;
V_9 = F_4 ( V_10 ,
V_11 ,
NULL , NULL ) ;
if ( F_5 ( V_9 ) ) {
F_6 ( L_1 ) ;
V_8 = V_9 ? F_7 ( V_9 ) : - V_12 ;
goto V_13;
}
V_14 = F_4 ( L_2 ,
V_9 ,
NULL , NULL ) ;
if ( F_5 ( V_14 ) ) {
F_6 ( L_1 ) ;
V_8 = V_14 ? F_7 ( V_14 )
: - V_12 ;
goto V_15;
}
V_16 = F_4 ( L_3 ,
V_9 ,
NULL , NULL ) ;
if ( F_5 ( V_16 ) ) {
F_6 ( L_1 ) ;
V_8 = V_16 ? F_7 ( V_16 )
: - V_12 ;
goto V_17;
}
V_8 = F_8 ( V_9 , V_18 , NULL ) ;
if ( V_8 ) {
F_6 ( L_1 ) ;
goto V_19;
}
return 0 ;
V_19:
F_9 ( & V_16 ) ;
V_17:
F_9 ( & V_14 ) ;
V_15:
F_9 ( & V_9 ) ;
V_13:
V_16 = NULL ;
V_14 = NULL ;
V_9 = NULL ;
return V_8 ;
}
void F_10 ( void )
{
if ( ! F_5 ( V_16 ) )
F_9 ( & V_16 ) ;
if ( ! F_5 ( V_14 ) )
F_9 ( & V_14 ) ;
if ( ! F_5 ( V_9 ) )
F_9 ( & V_9 ) ;
V_16 = NULL ;
V_14 = NULL ;
V_9 = NULL ;
}
static T_1 F_11 ( struct V_20 * V_21 , struct V_22 * V_23 ,
char * V_24 )
{
struct V_25 * V_26 = F_12 ( V_21 , struct V_25 ,
V_27 ) ;
T_5 V_28 = 0 ;
struct V_29 V_30 ;
int V_31 ;
F_13 (ns->ns_rs_hash, &bd, i)
V_28 += F_14 ( & V_30 ) ;
return sprintf ( V_24 , L_4 , V_28 ) ;
}
static T_1 F_15 ( struct V_20 * V_21 , struct V_22 * V_23 ,
char * V_24 )
{
struct V_25 * V_26 = F_12 ( V_21 , struct V_25 ,
V_27 ) ;
T_5 V_32 ;
V_32 = F_16 ( V_26 -> V_33 , V_34 ,
V_35 ) ;
return sprintf ( V_24 , L_4 , V_32 ) ;
}
static T_1 F_17 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
char * V_24 )
{
struct V_25 * V_26 = F_12 ( V_21 , struct V_25 ,
V_27 ) ;
return sprintf ( V_24 , L_5 , V_26 -> V_36 ) ;
}
static T_1 F_18 ( struct V_20 * V_21 , struct V_22 * V_23 ,
char * V_24 )
{
struct V_25 * V_26 = F_12 ( V_21 , struct V_25 ,
V_27 ) ;
T_6 * V_37 = & V_26 -> V_38 ;
if ( F_19 ( V_26 ) )
V_37 = & V_26 -> V_36 ;
return sprintf ( V_24 , L_6 , * V_37 ) ;
}
static T_1 F_20 ( struct V_20 * V_21 , struct V_22 * V_23 ,
const char * V_2 , T_3 V_3 )
{
struct V_25 * V_26 = F_12 ( V_21 , struct V_25 ,
V_27 ) ;
unsigned long V_39 ;
int V_40 ;
int V_13 ;
if ( strncmp ( V_2 , L_7 , 5 ) == 0 ) {
F_21 ( V_6 ,
L_8 ,
F_22 ( V_26 ) ) ;
if ( F_19 ( V_26 ) ) {
int V_41 , V_42 = V_26 -> V_36 ;
V_41 = F_23 ( V_26 , V_42 , 0 ,
V_43 ) ;
if ( V_41 < V_42 ) {
F_21 ( V_6 ,
L_9 ,
V_42 ,
V_41 ) ;
return - V_44 ;
}
} else {
V_39 = V_26 -> V_38 ;
V_26 -> V_38 = 0 ;
F_23 ( V_26 , 0 , 0 , V_43 ) ;
V_26 -> V_38 = V_39 ;
}
return V_3 ;
}
V_13 = F_24 ( V_2 , 10 , & V_39 ) ;
if ( V_13 != 0 ) {
F_6 ( L_10 ) ;
return - V_44 ;
}
V_40 = ( V_39 == 0 ) ;
if ( F_19 ( V_26 ) ) {
if ( ! V_40 )
V_26 -> V_38 = ( unsigned int ) V_39 ;
if ( V_39 > V_26 -> V_36 )
V_39 = V_26 -> V_36 ;
V_39 = V_26 -> V_36 - V_39 ;
F_21 ( V_6 ,
L_11 ,
F_22 ( V_26 ) , V_26 -> V_36 ,
( unsigned int ) V_39 ) ;
F_23 ( V_26 , V_39 , V_45 , V_43 ) ;
if ( ! V_40 ) {
F_21 ( V_6 ,
L_12 ,
F_22 ( V_26 ) ) ;
V_26 -> V_46 &= ~ V_47 ;
}
} else {
F_21 ( V_6 ,
L_13 ,
F_22 ( V_26 ) , V_26 -> V_38 ,
( unsigned int ) V_39 ) ;
V_26 -> V_38 = ( unsigned int ) V_39 ;
F_23 ( V_26 , 0 , V_45 , V_43 ) ;
if ( V_40 &&
( V_26 -> V_48 & V_47 ) ) {
F_21 ( V_6 ,
L_14 ,
F_22 ( V_26 ) ) ;
V_26 -> V_46 |= V_47 ;
}
}
return V_3 ;
}
static T_1 F_25 ( struct V_20 * V_21 , struct V_22 * V_23 ,
char * V_24 )
{
struct V_25 * V_26 = F_12 ( V_21 , struct V_25 ,
V_27 ) ;
return sprintf ( V_24 , L_6 , V_26 -> V_49 ) ;
}
static T_1 F_26 ( struct V_20 * V_21 , struct V_22 * V_23 ,
const char * V_2 , T_3 V_3 )
{
struct V_25 * V_26 = F_12 ( V_21 , struct V_25 ,
V_27 ) ;
unsigned long V_39 ;
int V_13 ;
V_13 = F_24 ( V_2 , 10 , & V_39 ) ;
if ( V_13 != 0 )
return - V_44 ;
V_26 -> V_49 = V_39 ;
return V_3 ;
}
static T_1 F_27 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
char * V_24 )
{
struct V_25 * V_26 = F_12 ( V_21 , struct V_25 ,
V_27 ) ;
return sprintf ( V_24 , L_5 , F_28 ( V_26 ) ) ;
}
static T_1 F_29 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
const char * V_2 ,
T_3 V_3 )
{
struct V_25 * V_26 = F_12 ( V_21 , struct V_25 ,
V_27 ) ;
unsigned long V_50 = - 1 ;
int V_8 ;
V_8 = F_24 ( V_2 , 10 , & V_50 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_50 == 0 )
V_26 -> V_46 &= ~ V_51 ;
else if ( V_26 -> V_48 & V_51 )
V_26 -> V_46 |= V_51 ;
return V_3 ;
}
static void F_30 ( struct V_20 * V_21 )
{
struct V_25 * V_26 = F_12 ( V_21 , struct V_25 ,
V_27 ) ;
F_31 ( & V_26 -> V_52 ) ;
}
static void F_32 ( struct V_25 * V_26 )
{
if ( F_5 ( V_26 -> V_53 ) )
F_6 ( L_15 ,
F_22 ( V_26 ) ) ;
else
F_9 ( & V_26 -> V_53 ) ;
if ( V_26 -> V_33 )
F_33 ( & V_26 -> V_33 ) ;
}
static void F_34 ( struct V_25 * V_26 )
{
F_35 ( & V_26 -> V_27 ) ;
F_36 ( & V_26 -> V_52 ) ;
}
static int F_37 ( struct V_25 * V_26 )
{
int V_13 ;
V_26 -> V_27 . V_54 = V_55 ;
F_38 ( & V_26 -> V_52 ) ;
V_13 = F_39 ( & V_26 -> V_27 , & V_56 , NULL ,
L_16 , F_22 ( V_26 ) ) ;
V_26 -> V_33 = F_40 ( V_57 , 0 ) ;
if ( ! V_26 -> V_33 ) {
F_35 ( & V_26 -> V_27 ) ;
return - V_12 ;
}
F_41 ( V_26 -> V_33 , V_34 ,
V_58 , L_17 , L_17 ) ;
return V_13 ;
}
static int F_42 ( struct V_25 * V_26 )
{
struct V_59 * V_60 ;
if ( ! F_5 ( V_26 -> V_53 ) ) {
V_60 = V_26 -> V_53 ;
} else {
V_60 = F_43 ( F_22 ( V_26 ) ,
V_14 ) ;
if ( ! V_60 )
return - V_12 ;
V_26 -> V_53 = V_60 ;
}
return 0 ;
}
static struct V_61 * F_44 ( struct V_61 * V_28 )
{
F_45 ( V_28 ) ;
F_45 ( V_28 != V_62 ) ;
F_46 ( & V_28 -> V_63 ) ;
F_21 ( V_64 , L_18 , V_28 ,
F_47 ( & V_28 -> V_63 ) ) ;
return V_28 ;
}
static unsigned F_48 ( struct V_65 * V_66 ,
const void * V_67 , unsigned V_68 )
{
const struct V_69 * V_70 = V_67 ;
unsigned int V_71 = 0 ;
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_72 ; V_31 ++ )
V_71 += V_70 -> V_73 [ V_31 ] ;
return V_71 & V_68 ;
}
static unsigned F_49 ( struct V_65 * V_66 ,
const void * V_67 , unsigned V_68 )
{
const struct V_69 * V_70 = V_67 ;
struct V_74 V_75 ;
T_6 V_76 ;
T_6 V_71 ;
V_75 . V_77 = V_70 -> V_73 [ V_78 ] ;
V_75 . V_79 = ( T_6 ) V_70 -> V_73 [ V_80 ] ;
V_75 . V_81 = ( T_6 ) ( V_70 -> V_73 [ V_80 ] >> 32 ) ;
V_76 = F_50 ( & V_75 ) ;
V_76 += ( V_76 >> 4 ) + ( V_76 << 12 ) ;
if ( V_70 -> V_73 [ V_82 ] != 0 ) {
V_71 = V_70 -> V_73 [ V_82 ] ;
V_76 += ( V_71 >> 5 ) + ( V_71 << 11 ) ;
} else {
V_71 = F_51 ( & V_75 ) ;
}
V_76 = F_52 ( V_76 , V_66 -> V_83 ) ;
V_76 -= F_52 ( ( unsigned long ) V_66 , V_71 % 11 + 3 ) ;
V_76 <<= V_66 -> V_84 - V_66 -> V_83 ;
V_76 |= F_48 ( V_66 , V_67 , F_53 ( V_66 ) - 1 ) ;
return V_76 & V_68 ;
}
static void * F_54 ( struct V_85 * V_86 )
{
struct V_61 * V_28 ;
V_28 = F_55 ( V_86 , struct V_61 , V_87 ) ;
return & V_28 -> V_88 ;
}
static int F_56 ( const void * V_67 , struct V_85 * V_86 )
{
struct V_61 * V_28 ;
V_28 = F_55 ( V_86 , struct V_61 , V_87 ) ;
return F_57 ( ( const struct V_69 * ) V_67 ,
( const struct V_69 * ) & V_28 -> V_88 ) ;
}
static void * F_58 ( struct V_85 * V_86 )
{
return F_55 ( V_86 , struct V_61 , V_87 ) ;
}
static void F_59 ( struct V_65 * V_66 ,
struct V_85 * V_86 )
{
struct V_61 * V_28 ;
V_28 = F_55 ( V_86 , struct V_61 , V_87 ) ;
F_44 ( V_28 ) ;
}
static void F_60 ( struct V_65 * V_66 ,
struct V_85 * V_86 )
{
struct V_61 * V_28 ;
V_28 = F_55 ( V_86 , struct V_61 , V_87 ) ;
F_61 ( V_28 ) ;
}
static void F_62 ( struct V_65 * V_66 , struct V_85 * V_86 )
{
struct V_61 * V_28 ;
V_28 = F_55 ( V_86 , struct V_61 , V_87 ) ;
F_63 ( V_28 ) ;
}
static void F_64 ( struct V_25 * V_26 ,
T_7 V_89 )
{
F_65 ( F_66 ( V_89 ) ) ;
F_45 ( F_67 ( & V_26 -> V_90 ) ) ;
F_68 ( & V_26 -> V_90 , & V_91 ) ;
F_69 ( V_89 ) ;
F_70 ( F_66 ( V_89 ) ) ;
}
struct V_25 * F_71 ( struct V_92 * V_93 , char * V_73 ,
T_7 V_89 ,
enum V_94 V_95 ,
enum V_96 V_97 )
{
struct V_25 * V_26 = NULL ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_29 V_30 ;
int V_102 ;
int V_8 ;
F_45 ( V_93 ) ;
V_8 = F_72 () ;
if ( V_8 ) {
F_6 ( L_19 , V_8 ) ;
return NULL ;
}
for ( V_102 = 0 ; ; V_102 ++ ) {
V_101 = & V_103 [ V_102 ] ;
if ( V_101 -> V_104 == V_105 ) {
F_6 ( L_20 , V_97 , V_73 ) ;
goto V_106;
}
if ( V_101 -> V_104 == V_97 )
break;
}
V_26 = F_73 ( sizeof( * V_26 ) , V_107 ) ;
if ( ! V_26 )
goto V_106;
V_26 -> V_108 = F_74 ( V_73 ,
V_101 -> V_109 , V_101 -> V_109 ,
V_101 -> V_110 , sizeof( * V_99 ) ,
V_111 ,
V_112 ,
V_101 -> V_113 ,
V_114 |
V_115 |
V_116 |
V_117 ) ;
if ( ! V_26 -> V_108 )
goto V_118;
F_13 (ns->ns_rs_hash, &bd, idx) {
V_99 = F_75 ( V_26 -> V_108 , & V_30 ) ;
F_76 ( & V_99 -> V_119 , V_120 , 0 ) ;
V_99 -> V_121 = V_26 ;
}
V_26 -> V_122 = V_93 ;
V_26 -> V_123 = V_95 ;
V_26 -> V_124 = V_89 ;
F_77 ( & V_26 -> V_90 ) ;
F_77 ( & V_26 -> V_125 ) ;
F_78 ( & V_26 -> V_126 ) ;
F_79 ( & V_26 -> V_127 , 0 ) ;
F_80 ( & V_26 -> V_128 ) ;
V_26 -> V_129 = V_130 ;
V_26 -> V_36 = 0 ;
V_26 -> V_38 = V_131 ;
V_26 -> V_49 = V_132 ;
V_26 -> V_48 = 0 ;
V_26 -> V_46 = 0 ;
V_26 -> V_133 = 0 ;
V_8 = F_37 ( V_26 ) ;
if ( V_8 != 0 ) {
F_6 ( L_21 , V_8 ) ;
goto V_134;
}
V_8 = F_42 ( V_26 ) ;
if ( V_8 != 0 ) {
F_6 ( L_22 , V_8 ) ;
goto V_135;
}
V_102 = F_81 ( V_89 ) ;
V_8 = F_82 ( & V_26 -> V_136 , V_26 , V_102 , V_89 ) ;
if ( V_8 ) {
F_6 ( L_23 , V_8 ) ;
goto V_137;
}
F_64 ( V_26 , V_89 ) ;
return V_26 ;
V_137:
F_32 ( V_26 ) ;
V_135:
F_34 ( V_26 ) ;
F_83 ( V_26 , 0 ) ;
V_134:
F_84 ( V_26 -> V_108 ) ;
V_118:
F_85 ( V_26 ) ;
V_106:
F_86 () ;
return NULL ;
}
static void F_87 ( struct V_61 * V_28 , struct V_138 * V_139 ,
T_5 V_140 )
{
struct V_138 * V_39 ;
int V_8 = 0 ;
bool V_141 = ! ! ( V_140 & V_142 ) ;
do {
struct V_143 * V_144 = NULL ;
struct V_145 V_146 ;
F_88 ( V_28 ) ;
F_89 (tmp, q) {
V_144 = F_90 ( V_39 , struct V_143 , V_147 ) ;
if ( F_91 ( V_144 ) ) {
V_144 = NULL ;
continue;
}
F_92 ( V_144 ) ;
F_93 ( V_144 ) ;
break;
}
if ( ! V_144 ) {
F_94 ( V_28 ) ;
break;
}
F_95 ( V_144 ) ;
F_96 ( V_144 ) ;
V_144 -> V_148 |= V_140 ;
if ( V_141 )
F_97 ( V_144 ) ;
if ( V_141 && ( V_144 -> V_149 || V_144 -> V_150 ) ) {
F_94 ( V_28 ) ;
F_98 ( V_144 , L_24 ) ;
if ( V_144 -> V_148 & V_151 ) {
F_99 ( V_152 ) ;
F_100 ( F_101 ( 4 ) ) ;
F_99 ( V_153 ) ;
}
if ( V_144 -> V_154 )
V_144 -> V_154 ( V_144 , V_155 ,
NULL ) ;
F_102 ( V_144 ) ;
continue;
}
F_94 ( V_28 ) ;
F_103 ( V_144 , & V_146 ) ;
V_8 = F_104 ( & V_146 , V_45 ) ;
if ( V_8 )
F_6 ( L_25 , V_8 ) ;
F_102 ( V_144 ) ;
} while ( 1 );
}
static int F_105 ( struct V_65 * V_66 , struct V_29 * V_30 ,
struct V_85 * V_86 , void * V_156 )
{
struct V_61 * V_28 = F_106 ( V_66 , V_86 ) ;
T_5 V_140 = * ( T_5 * ) V_156 ;
F_87 ( V_28 , & V_28 -> V_157 , V_140 ) ;
F_87 ( V_28 , & V_28 -> V_158 , V_140 ) ;
return 0 ;
}
static int F_107 ( struct V_65 * V_66 , struct V_29 * V_30 ,
struct V_85 * V_86 , void * V_156 )
{
struct V_61 * V_28 = F_106 ( V_66 , V_86 ) ;
F_88 ( V_28 ) ;
F_6 ( L_26 V_159
L_27 ,
F_22 ( F_108 ( V_28 ) ) , F_109 ( V_28 ) , V_28 ,
F_47 ( & V_28 -> V_63 ) - 1 ) ;
F_110 ( V_160 , V_28 ) ;
F_94 ( V_28 ) ;
return 0 ;
}
int F_83 ( struct V_25 * V_26 , T_5 V_140 )
{
if ( ! V_26 ) {
F_21 ( V_64 , L_28 ) ;
return V_161 ;
}
F_111 ( V_26 -> V_108 , F_105 , & V_140 ) ;
F_111 ( V_26 -> V_108 , F_107 , NULL ) ;
return V_161 ;
}
static int F_112 ( struct V_25 * V_26 , int V_162 )
{
F_83 ( V_26 , V_162 ? V_142 : 0 ) ;
if ( F_47 ( & V_26 -> V_127 ) > 0 ) {
struct V_163 V_164 = F_113 ( V_165 , NULL ) ;
int V_8 ;
F_21 ( V_6 ,
L_29 ,
F_22 ( V_26 ) , F_47 ( & V_26 -> V_127 ) ) ;
V_166:
if ( V_162 )
V_164 = F_114 ( F_115 ( V_167 *
V_168 ) / 4 , NULL , NULL ) ;
V_8 = F_116 ( V_26 -> V_128 ,
F_47 ( & V_26 -> V_127 ) == 0 , & V_164 ) ;
if ( V_162 && V_8 == - V_169 ) {
F_117 ( L_30 ,
F_22 ( V_26 ) ,
F_47 ( & V_26 -> V_127 ) , V_8 ) ;
goto V_166;
}
if ( F_47 ( & V_26 -> V_127 ) ) {
F_117 ( L_31 ,
F_22 ( V_26 ) ,
F_47 ( & V_26 -> V_127 ) , V_8 ) ;
return V_170 ;
}
F_21 ( V_6 , L_32 ,
F_22 ( V_26 ) ) ;
}
return V_161 ;
}
void F_118 ( struct V_25 * V_26 ,
struct V_171 * V_172 ,
int V_162 )
{
int V_8 ;
if ( ! V_26 )
return;
F_119 ( & V_26 -> V_126 ) ;
V_26 -> V_133 = 1 ;
F_120 ( & V_26 -> V_126 ) ;
V_8 = F_112 ( V_26 , V_162 ) ;
if ( V_8 != V_161 ) {
if ( V_172 ) {
F_121 ( V_172 , 0 ) ;
F_122 ( V_172 ) ;
}
V_8 = F_112 ( V_26 , 1 ) ;
F_45 ( V_8 == 0 ) ;
}
}
static void F_123 ( struct V_25 * V_26 ,
T_7 V_89 )
{
F_65 ( F_66 ( V_89 ) ) ;
F_45 ( ! F_67 ( & V_26 -> V_90 ) ) ;
F_124 ( & V_26 -> V_90 ) ;
F_125 ( V_89 ) ;
F_70 ( F_66 ( V_89 ) ) ;
}
void F_126 ( struct V_25 * V_26 )
{
if ( ! V_26 )
return;
F_123 ( V_26 , V_26 -> V_124 ) ;
F_127 ( & V_26 -> V_136 ) ;
F_32 ( V_26 ) ;
F_34 ( V_26 ) ;
F_84 ( V_26 -> V_108 ) ;
F_45 ( F_67 ( & V_26 -> V_90 ) ) ;
F_85 ( V_26 ) ;
F_86 () ;
}
void F_128 ( struct V_25 * V_26 )
{
F_46 ( & V_26 -> V_127 ) ;
}
static int F_129 ( struct V_25 * V_26 )
{
return F_130 ( & V_26 -> V_127 ) ;
}
void F_131 ( struct V_25 * V_26 )
{
if ( F_132 ( & V_26 -> V_127 , & V_26 -> V_126 ) ) {
F_133 ( & V_26 -> V_128 ) ;
F_120 ( & V_26 -> V_126 ) ;
}
}
void F_134 ( struct V_25 * V_26 ,
T_7 V_89 )
{
F_45 ( ! F_67 ( & V_26 -> V_90 ) ) ;
F_45 ( F_135 ( F_66 ( V_89 ) ) ) ;
F_136 ( & V_26 -> V_90 , F_137 ( V_89 ) ) ;
}
void F_138 ( struct V_25 * V_26 ,
T_7 V_89 )
{
F_45 ( ! F_67 ( & V_26 -> V_90 ) ) ;
F_45 ( F_135 ( F_66 ( V_89 ) ) ) ;
F_136 ( & V_26 -> V_90 , & V_91 ) ;
}
struct V_25 * F_139 ( T_7 V_89 )
{
F_45 ( F_135 ( F_66 ( V_89 ) ) ) ;
F_45 ( ! F_67 ( F_137 ( V_89 ) ) ) ;
return F_12 ( F_137 ( V_89 ) -> V_173 ,
struct V_25 , V_90 ) ;
}
static struct V_61 * F_140 ( void )
{
struct V_61 * V_28 ;
int V_102 ;
V_28 = F_141 ( V_174 , V_107 ) ;
if ( ! V_28 )
return NULL ;
F_77 ( & V_28 -> V_157 ) ;
F_77 ( & V_28 -> V_158 ) ;
for ( V_102 = 0 ; V_102 < V_175 ; V_102 ++ ) {
V_28 -> V_176 [ V_102 ] . V_177 = 0 ;
V_28 -> V_176 [ V_102 ] . V_178 = 1 << V_102 ;
V_28 -> V_176 [ V_102 ] . V_179 = NULL ;
}
F_79 ( & V_28 -> V_63 , 1 ) ;
F_78 ( & V_28 -> V_180 ) ;
F_142 ( & V_28 -> V_181 ) ;
F_143 ( & V_28 -> V_182 ) ;
F_65 ( & V_28 -> V_182 ) ;
return V_28 ;
}
struct V_61 *
F_144 ( struct V_25 * V_26 , struct V_61 * V_183 ,
const struct V_69 * V_73 , enum V_184 type ,
int V_185 )
{
struct V_85 * V_86 ;
struct V_61 * V_28 = NULL ;
struct V_29 V_30 ;
T_5 V_186 ;
int V_187 = 0 ;
int V_8 ;
F_45 ( ! V_183 ) ;
F_45 ( V_26 -> V_108 ) ;
F_45 ( V_73 -> V_73 [ 0 ] != 0 ) ;
F_145 ( V_26 -> V_108 , ( void * ) V_73 , & V_30 , 0 ) ;
V_86 = F_146 ( V_26 -> V_108 , & V_30 , ( void * ) V_73 ) ;
if ( V_86 ) {
F_147 ( V_26 -> V_108 , & V_30 , 0 ) ;
goto V_188;
}
V_186 = F_148 ( & V_30 ) ;
F_147 ( V_26 -> V_108 , & V_30 , 0 ) ;
if ( V_185 == 0 )
return F_149 ( - V_189 ) ;
F_150 ( type >= V_190 && type < V_191 ,
L_33 , type ) ;
V_28 = F_140 () ;
if ( ! V_28 )
return F_149 ( - V_12 ) ;
V_28 -> V_192 = F_75 ( V_26 -> V_108 , & V_30 ) ;
V_28 -> V_88 = * V_73 ;
V_28 -> V_193 = type ;
F_151 ( V_26 -> V_108 , & V_30 , 1 ) ;
V_86 = ( V_186 == F_148 ( & V_30 ) ) ? NULL :
F_146 ( V_26 -> V_108 , & V_30 , ( void * ) V_73 ) ;
if ( V_86 ) {
F_147 ( V_26 -> V_108 , & V_30 , 1 ) ;
F_152 ( & V_28 -> V_181 ) ;
F_70 ( & V_28 -> V_182 ) ;
F_153 ( V_174 , V_28 ) ;
V_188:
V_28 = F_55 ( V_86 , struct V_61 , V_87 ) ;
if ( V_26 -> V_194 && V_26 -> V_194 -> V_188 ) {
F_65 ( & V_28 -> V_182 ) ;
F_70 ( & V_28 -> V_182 ) ;
}
if ( F_154 ( V_28 -> V_195 < 0 ) ) {
V_8 = V_28 -> V_195 ;
F_63 ( V_28 ) ;
V_28 = F_149 ( V_8 ) ;
}
return V_28 ;
}
F_155 ( V_26 -> V_108 , & V_30 , & V_28 -> V_87 ) ;
if ( F_14 ( & V_30 ) == 1 )
V_187 = F_129 ( V_26 ) ;
F_147 ( V_26 -> V_108 , & V_30 , 1 ) ;
if ( V_26 -> V_194 && V_26 -> V_194 -> V_188 ) {
F_156 ( V_196 , 2 ) ;
V_8 = V_26 -> V_194 -> V_188 ( V_28 ) ;
if ( V_8 < 0 ) {
F_6 ( L_34 ,
V_26 -> V_122 -> V_197 , V_73 -> V_73 [ 0 ] ,
V_73 -> V_73 [ 1 ] , V_8 ) ;
V_28 -> V_195 = V_8 ;
F_70 ( & V_28 -> V_182 ) ;
F_63 ( V_28 ) ;
return F_149 ( V_8 ) ;
}
}
F_70 ( & V_28 -> V_182 ) ;
if ( V_187 == 1 ) {
F_65 ( F_66 ( V_7 ) ) ;
F_134 ( V_26 , V_7 ) ;
F_70 ( F_66 ( V_7 ) ) ;
}
return V_28 ;
}
static void F_157 ( struct V_29 * V_30 ,
struct V_61 * V_28 )
{
struct V_98 * V_99 = V_28 -> V_192 ;
if ( ! F_67 ( & V_28 -> V_157 ) ) {
F_110 ( V_160 , V_28 ) ;
F_158 () ;
}
if ( ! F_67 ( & V_28 -> V_158 ) ) {
F_110 ( V_160 , V_28 ) ;
F_158 () ;
}
F_159 ( V_99 -> V_121 -> V_108 ,
V_30 , & V_28 -> V_87 ) ;
F_152 ( & V_28 -> V_181 ) ;
if ( F_14 ( V_30 ) == 0 )
F_131 ( V_99 -> V_121 ) ;
}
int F_63 ( struct V_61 * V_28 )
{
struct V_25 * V_26 = F_108 ( V_28 ) ;
struct V_29 V_30 ;
F_160 ( & V_28 -> V_63 , 0 , V_198 ) ;
F_21 ( V_64 , L_35 ,
V_28 , F_47 ( & V_28 -> V_63 ) - 1 ) ;
F_161 ( V_26 -> V_108 , & V_28 -> V_88 , & V_30 ) ;
if ( F_162 ( V_26 -> V_108 , & V_30 , & V_28 -> V_63 ) ) {
F_157 ( & V_30 , V_28 ) ;
F_147 ( V_26 -> V_108 , & V_30 , 1 ) ;
if ( V_26 -> V_194 && V_26 -> V_194 -> V_199 )
V_26 -> V_194 -> V_199 ( V_28 ) ;
F_153 ( V_174 , V_28 ) ;
return 1 ;
}
return 0 ;
}
int F_61 ( struct V_61 * V_28 )
{
struct V_25 * V_26 = F_108 ( V_28 ) ;
F_160 ( & V_28 -> V_63 , 0 , V_198 ) ;
F_21 ( V_64 , L_35 ,
V_28 , F_47 ( & V_28 -> V_63 ) - 1 ) ;
if ( F_163 ( & V_28 -> V_63 ) ) {
struct V_29 V_30 ;
F_161 ( F_108 ( V_28 ) -> V_108 ,
& V_28 -> V_88 , & V_30 ) ;
F_157 ( & V_30 , V_28 ) ;
F_147 ( V_26 -> V_108 , & V_30 , 1 ) ;
if ( V_26 -> V_194 && V_26 -> V_194 -> V_199 )
V_26 -> V_194 -> V_199 ( V_28 ) ;
F_153 ( V_174 , V_28 ) ;
F_151 ( V_26 -> V_108 , & V_30 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_164 ( struct V_61 * V_28 , struct V_138 * V_200 ,
struct V_143 * V_144 )
{
F_165 ( V_28 ) ;
F_98 ( V_144 , L_36 ) ;
if ( F_166 ( V_144 ) ) {
F_21 ( V_201 , L_37 ) ;
return;
}
F_45 ( F_67 ( & V_144 -> V_147 ) ) ;
F_167 ( & V_144 -> V_147 , V_200 ) ;
}
void F_168 ( struct V_143 * V_144 )
{
int type = V_144 -> V_202 -> V_193 ;
F_165 ( V_144 -> V_202 ) ;
if ( type == V_203 || type == V_204 )
F_169 ( V_144 ) ;
else if ( type == V_205 )
F_170 ( V_144 ) ;
F_124 ( & V_144 -> V_147 ) ;
}
void F_171 ( struct V_61 * V_28 , struct V_206 * V_207 )
{
V_207 -> V_193 = V_28 -> V_193 ;
V_207 -> V_88 = V_28 -> V_88 ;
}
void F_2 ( T_7 V_89 , int V_208 )
{
struct V_138 * V_39 ;
if ( ! ( ( V_209 | V_160 ) & V_208 ) )
return;
F_65 ( F_66 ( V_89 ) ) ;
F_89 (tmp, ldlm_namespace_list(client)) {
struct V_25 * V_26 ;
V_26 = F_90 ( V_39 , struct V_25 , V_90 ) ;
F_172 ( V_208 , V_26 ) ;
}
F_70 ( F_66 ( V_89 ) ) ;
}
static int F_173 ( struct V_65 * V_66 , struct V_29 * V_30 ,
struct V_85 * V_86 , void * V_156 )
{
struct V_61 * V_28 = F_106 ( V_66 , V_86 ) ;
int V_208 = ( int ) ( unsigned long ) V_156 ;
F_88 ( V_28 ) ;
F_110 ( V_208 , V_28 ) ;
F_94 ( V_28 ) ;
return 0 ;
}
void F_172 ( int V_208 , struct V_25 * V_26 )
{
if ( ! ( ( V_209 | V_160 ) & V_208 ) )
return;
F_21 ( V_208 , L_38 ,
F_22 ( V_26 ) , F_47 ( & V_26 -> V_127 ) ) ;
if ( F_174 ( F_175 () , V_26 -> V_210 ) )
return;
F_111 ( V_26 -> V_108 ,
F_173 ,
( void * ) ( unsigned long ) V_208 ) ;
F_119 ( & V_26 -> V_126 ) ;
V_26 -> V_210 = F_176 ( 10 ) ;
F_120 ( & V_26 -> V_126 ) ;
}
void F_110 ( int V_208 , struct V_61 * V_28 )
{
struct V_143 * V_144 ;
unsigned int V_211 = 0 ;
F_177 ( V_72 == 4 ) ;
if ( ! ( ( V_209 | V_160 ) & V_208 ) )
return;
F_21 ( V_208 , L_39 V_159 L_40 ,
F_109 ( V_28 ) , V_28 , F_47 ( & V_28 -> V_63 ) ) ;
if ( ! F_67 ( & V_28 -> V_157 ) ) {
F_21 ( V_208 , L_41 ) ;
F_178 (lock, &res->lr_granted,
l_res_link) {
F_179 ( V_208 , V_144 , L_42 ) ;
if ( ! ( V_208 & V_212 ) &&
++ V_211 > V_213 ) {
F_21 ( V_208 , L_43 ,
V_211 ) ;
break;
}
}
}
if ( ! F_67 ( & V_28 -> V_158 ) ) {
F_21 ( V_208 , L_44 ) ;
F_180 (lock, &res->lr_waiting, l_res_link)
F_179 ( V_208 , V_144 , L_42 ) ;
}
}
