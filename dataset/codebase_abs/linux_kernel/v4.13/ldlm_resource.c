static T_1
F_1 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
F_2 ( V_5 , V_6 ) ;
F_2 ( V_7 , V_6 ) ;
return V_3 ;
}
static int F_3 ( struct V_8 * V_9 , void * V_10 )
{
F_4 ( V_9 , L_1 , * ( unsigned int * ) V_9 -> V_11 ) ;
return 0 ;
}
static T_1
F_5 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_8 * V_12 = V_1 -> V_13 ;
if ( V_3 == 0 )
return 0 ;
return F_6 ( V_2 , V_3 , 0 ,
( unsigned int * ) V_12 -> V_11 ) ;
}
int F_7 ( void )
{
int V_14 ;
V_15 = F_8 ( V_16 ,
V_17 ,
NULL , NULL ) ;
if ( F_9 ( V_15 ) ) {
F_10 ( L_2 ) ;
V_14 = V_15 ? F_11 ( V_15 ) : - V_18 ;
goto V_19;
}
V_20 = F_8 ( L_3 ,
V_15 ,
NULL , NULL ) ;
if ( F_9 ( V_20 ) ) {
F_10 ( L_2 ) ;
V_14 = V_20 ? F_11 ( V_20 )
: - V_18 ;
goto V_21;
}
V_22 = F_8 ( L_4 ,
V_15 ,
NULL , NULL ) ;
if ( F_9 ( V_22 ) ) {
F_10 ( L_2 ) ;
V_14 = V_22 ? F_11 ( V_22 )
: - V_18 ;
goto V_23;
}
V_14 = F_12 ( V_15 , V_24 , NULL ) ;
if ( V_14 ) {
F_10 ( L_2 ) ;
goto V_25;
}
return 0 ;
V_25:
F_13 ( & V_22 ) ;
V_23:
F_13 ( & V_20 ) ;
V_21:
F_13 ( & V_15 ) ;
V_19:
V_22 = NULL ;
V_20 = NULL ;
V_15 = NULL ;
return V_14 ;
}
void F_14 ( void )
{
if ( ! F_9 ( V_22 ) )
F_13 ( & V_22 ) ;
if ( ! F_9 ( V_20 ) )
F_13 ( & V_20 ) ;
if ( ! F_9 ( V_15 ) )
F_13 ( & V_15 ) ;
V_22 = NULL ;
V_20 = NULL ;
V_15 = NULL ;
}
static T_1 F_15 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_16 ( V_27 , struct V_31 ,
V_33 ) ;
T_5 V_34 = 0 ;
struct V_35 V_36 ;
int V_37 ;
F_17 (ns->ns_rs_hash, &bd, i)
V_34 += F_18 ( & V_36 ) ;
return sprintf ( V_30 , L_5 , V_34 ) ;
}
static T_1 F_19 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_16 ( V_27 , struct V_31 ,
V_33 ) ;
T_5 V_38 ;
V_38 = F_20 ( V_32 -> V_39 , V_40 ,
V_41 ) ;
return sprintf ( V_30 , L_5 , V_38 ) ;
}
static T_1 F_21 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_16 ( V_27 , struct V_31 ,
V_33 ) ;
return sprintf ( V_30 , L_6 , V_32 -> V_42 ) ;
}
static T_1 F_22 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_16 ( V_27 , struct V_31 ,
V_33 ) ;
T_6 * V_43 = & V_32 -> V_44 ;
if ( F_23 ( V_32 ) )
V_43 = & V_32 -> V_42 ;
return sprintf ( V_30 , L_7 , * V_43 ) ;
}
static T_1 F_24 ( struct V_26 * V_27 , struct V_28 * V_29 ,
const char * V_2 , T_3 V_3 )
{
struct V_31 * V_32 = F_16 ( V_27 , struct V_31 ,
V_33 ) ;
unsigned long V_45 ;
int V_46 ;
int V_19 ;
if ( strncmp ( V_2 , L_8 , 5 ) == 0 ) {
F_25 ( V_6 ,
L_9 ,
F_26 ( V_32 ) ) ;
if ( F_23 ( V_32 ) ) {
int V_47 , V_48 = V_32 -> V_42 ;
V_47 = F_27 ( V_32 , V_48 , 0 ,
V_49 ) ;
if ( V_47 < V_48 ) {
F_25 ( V_6 ,
L_10 ,
V_48 ,
V_47 ) ;
return - V_50 ;
}
} else {
V_45 = V_32 -> V_44 ;
V_32 -> V_44 = 0 ;
F_27 ( V_32 , 0 , 0 , V_49 ) ;
V_32 -> V_44 = V_45 ;
}
return V_3 ;
}
V_19 = F_28 ( V_2 , 10 , & V_45 ) ;
if ( V_19 != 0 ) {
F_10 ( L_11 ) ;
return - V_50 ;
}
V_46 = ( V_45 == 0 ) ;
if ( F_23 ( V_32 ) ) {
if ( ! V_46 )
V_32 -> V_44 = ( unsigned int ) V_45 ;
if ( V_45 > V_32 -> V_42 )
V_45 = V_32 -> V_42 ;
V_45 = V_32 -> V_42 - V_45 ;
F_25 ( V_6 ,
L_12 ,
F_26 ( V_32 ) , V_32 -> V_42 ,
( unsigned int ) V_45 ) ;
F_27 ( V_32 , V_45 , V_51 , V_49 ) ;
if ( ! V_46 ) {
F_25 ( V_6 ,
L_13 ,
F_26 ( V_32 ) ) ;
V_32 -> V_52 &= ~ V_53 ;
}
} else {
F_25 ( V_6 ,
L_14 ,
F_26 ( V_32 ) , V_32 -> V_44 ,
( unsigned int ) V_45 ) ;
V_32 -> V_44 = ( unsigned int ) V_45 ;
F_27 ( V_32 , 0 , V_51 , V_49 ) ;
if ( V_46 &&
( V_32 -> V_54 & V_53 ) ) {
F_25 ( V_6 ,
L_15 ,
F_26 ( V_32 ) ) ;
V_32 -> V_52 |= V_53 ;
}
}
return V_3 ;
}
static T_1 F_29 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_16 ( V_27 , struct V_31 ,
V_33 ) ;
return sprintf ( V_30 , L_7 , V_32 -> V_55 ) ;
}
static T_1 F_30 ( struct V_26 * V_27 , struct V_28 * V_29 ,
const char * V_2 , T_3 V_3 )
{
struct V_31 * V_32 = F_16 ( V_27 , struct V_31 ,
V_33 ) ;
unsigned long V_45 ;
int V_19 ;
V_19 = F_28 ( V_2 , 10 , & V_45 ) ;
if ( V_19 != 0 )
return - V_50 ;
V_32 -> V_55 = V_45 ;
return V_3 ;
}
static T_1 F_31 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_16 ( V_27 , struct V_31 ,
V_33 ) ;
return sprintf ( V_30 , L_6 , F_32 ( V_32 ) ) ;
}
static T_1 F_33 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
const char * V_2 ,
T_3 V_3 )
{
struct V_31 * V_32 = F_16 ( V_27 , struct V_31 ,
V_33 ) ;
unsigned long V_56 = - 1 ;
int V_14 ;
V_14 = F_28 ( V_2 , 10 , & V_56 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_56 == 0 )
V_32 -> V_52 &= ~ V_57 ;
else if ( V_32 -> V_54 & V_57 )
V_32 -> V_52 |= V_57 ;
return V_3 ;
}
static void F_34 ( struct V_26 * V_27 )
{
struct V_31 * V_32 = F_16 ( V_27 , struct V_31 ,
V_33 ) ;
F_35 ( & V_32 -> V_58 ) ;
}
static void F_36 ( struct V_31 * V_32 )
{
if ( F_9 ( V_32 -> V_59 ) )
F_10 ( L_16 ,
F_26 ( V_32 ) ) ;
else
F_13 ( & V_32 -> V_59 ) ;
if ( V_32 -> V_39 )
F_37 ( & V_32 -> V_39 ) ;
}
static void F_38 ( struct V_31 * V_32 )
{
F_39 ( & V_32 -> V_33 ) ;
F_40 ( & V_32 -> V_58 ) ;
}
static int F_41 ( struct V_31 * V_32 )
{
int V_19 ;
V_32 -> V_33 . V_60 = V_61 ;
F_42 ( & V_32 -> V_58 ) ;
V_19 = F_43 ( & V_32 -> V_33 , & V_62 , NULL ,
L_17 , F_26 ( V_32 ) ) ;
V_32 -> V_39 = F_44 ( V_63 , 0 ) ;
if ( ! V_32 -> V_39 ) {
F_39 ( & V_32 -> V_33 ) ;
return - V_18 ;
}
F_45 ( V_32 -> V_39 , V_40 ,
V_64 , L_18 , L_18 ) ;
return V_19 ;
}
static int F_46 ( struct V_31 * V_32 )
{
struct V_65 * V_66 ;
if ( ! F_9 ( V_32 -> V_59 ) ) {
V_66 = V_32 -> V_59 ;
} else {
V_66 = F_47 ( F_26 ( V_32 ) ,
V_20 ) ;
if ( ! V_66 )
return - V_18 ;
V_32 -> V_59 = V_66 ;
}
return 0 ;
}
static struct V_67 * F_48 ( struct V_67 * V_34 )
{
F_49 ( V_34 ) ;
F_49 ( V_34 != V_68 ) ;
F_50 ( & V_34 -> V_69 ) ;
F_25 ( V_70 , L_19 , V_34 ,
F_51 ( & V_34 -> V_69 ) ) ;
return V_34 ;
}
static unsigned int F_52 ( struct V_71 * V_72 ,
const void * V_73 , unsigned int V_74 )
{
const struct V_75 * V_76 = V_73 ;
unsigned int V_77 = 0 ;
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_78 ; V_37 ++ )
V_77 += V_76 -> V_79 [ V_37 ] ;
return V_77 & V_74 ;
}
static unsigned int F_53 ( struct V_71 * V_72 ,
const void * V_73 , unsigned int V_74 )
{
const struct V_75 * V_76 = V_73 ;
struct V_80 V_81 ;
T_6 V_82 ;
T_6 V_77 ;
V_81 . V_83 = V_76 -> V_79 [ V_84 ] ;
V_81 . V_85 = ( T_6 ) V_76 -> V_79 [ V_86 ] ;
V_81 . V_87 = ( T_6 ) ( V_76 -> V_79 [ V_86 ] >> 32 ) ;
V_82 = F_54 ( & V_81 ) ;
V_82 += ( V_82 >> 4 ) + ( V_82 << 12 ) ;
if ( V_76 -> V_79 [ V_88 ] != 0 ) {
V_77 = V_76 -> V_79 [ V_88 ] ;
V_82 += ( V_77 >> 5 ) + ( V_77 << 11 ) ;
} else {
V_77 = F_55 ( & V_81 ) ;
}
V_82 = F_56 ( V_82 , V_72 -> V_89 ) ;
V_82 -= F_56 ( ( unsigned long ) V_72 , V_77 % 11 + 3 ) ;
V_82 <<= V_72 -> V_90 - V_72 -> V_89 ;
V_82 |= F_52 ( V_72 , V_73 , F_57 ( V_72 ) - 1 ) ;
return V_82 & V_74 ;
}
static void * F_58 ( struct V_91 * V_92 )
{
struct V_67 * V_34 ;
V_34 = F_59 ( V_92 , struct V_67 , V_93 ) ;
return & V_34 -> V_94 ;
}
static int F_60 ( const void * V_73 , struct V_91 * V_92 )
{
struct V_67 * V_34 ;
V_34 = F_59 ( V_92 , struct V_67 , V_93 ) ;
return F_61 ( ( const struct V_75 * ) V_73 ,
( const struct V_75 * ) & V_34 -> V_94 ) ;
}
static void * F_62 ( struct V_91 * V_92 )
{
return F_59 ( V_92 , struct V_67 , V_93 ) ;
}
static void F_63 ( struct V_71 * V_72 ,
struct V_91 * V_92 )
{
struct V_67 * V_34 ;
V_34 = F_59 ( V_92 , struct V_67 , V_93 ) ;
F_48 ( V_34 ) ;
}
static void F_64 ( struct V_71 * V_72 ,
struct V_91 * V_92 )
{
struct V_67 * V_34 ;
V_34 = F_59 ( V_92 , struct V_67 , V_93 ) ;
F_65 ( V_34 ) ;
}
static void F_66 ( struct V_71 * V_72 , struct V_91 * V_92 )
{
struct V_67 * V_34 ;
V_34 = F_59 ( V_92 , struct V_67 , V_93 ) ;
F_67 ( V_34 ) ;
}
static void F_68 ( struct V_31 * V_32 ,
enum V_95 V_96 )
{
F_69 ( F_70 ( V_96 ) ) ;
F_49 ( F_71 ( & V_32 -> V_97 ) ) ;
F_72 ( & V_32 -> V_97 , & V_98 ) ;
F_73 ( V_96 ) ;
F_74 ( F_70 ( V_96 ) ) ;
}
struct V_31 * F_75 ( struct V_99 * V_100 , char * V_79 ,
enum V_95 V_96 ,
enum V_101 V_102 ,
enum V_103 V_104 )
{
struct V_31 * V_32 = NULL ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
struct V_35 V_36 ;
int V_109 ;
int V_14 ;
F_49 ( V_100 ) ;
V_14 = F_76 () ;
if ( V_14 ) {
F_10 ( L_20 , V_14 ) ;
return NULL ;
}
for ( V_109 = 0 ; ; V_109 ++ ) {
V_108 = & V_110 [ V_109 ] ;
if ( V_108 -> V_111 == V_112 ) {
F_10 ( L_21 , V_104 , V_79 ) ;
goto V_113;
}
if ( V_108 -> V_111 == V_104 )
break;
}
V_32 = F_77 ( sizeof( * V_32 ) , V_114 ) ;
if ( ! V_32 )
goto V_113;
V_32 -> V_115 = F_78 ( V_79 ,
V_108 -> V_116 , V_108 -> V_116 ,
V_108 -> V_117 , sizeof( * V_106 ) ,
V_118 ,
V_119 ,
V_108 -> V_120 ,
V_121 |
V_122 |
V_123 |
V_124 ) ;
if ( ! V_32 -> V_115 )
goto V_125;
F_17 (ns->ns_rs_hash, &bd, idx) {
V_106 = F_79 ( V_32 -> V_115 , & V_36 ) ;
F_80 ( & V_106 -> V_126 , V_127 , 0 ) ;
V_106 -> V_128 = V_32 ;
}
V_32 -> V_129 = V_100 ;
V_32 -> V_130 = V_102 ;
V_32 -> V_131 = V_96 ;
F_81 ( & V_32 -> V_97 ) ;
F_81 ( & V_32 -> V_132 ) ;
F_82 ( & V_32 -> V_133 ) ;
F_83 ( & V_32 -> V_134 , 0 ) ;
F_84 ( & V_32 -> V_135 ) ;
V_32 -> V_136 = V_137 ;
V_32 -> V_42 = 0 ;
V_32 -> V_44 = V_138 ;
V_32 -> V_55 = V_139 ;
V_32 -> V_54 = 0 ;
V_32 -> V_52 = 0 ;
V_32 -> V_140 = 0 ;
V_14 = F_41 ( V_32 ) ;
if ( V_14 != 0 ) {
F_10 ( L_22 , V_14 ) ;
goto V_141;
}
V_14 = F_46 ( V_32 ) ;
if ( V_14 != 0 ) {
F_10 ( L_23 , V_14 ) ;
goto V_142;
}
V_109 = F_85 ( V_96 ) ;
V_14 = F_86 ( & V_32 -> V_143 , V_32 , V_109 , V_96 ) ;
if ( V_14 ) {
F_10 ( L_24 , V_14 ) ;
goto V_144;
}
F_68 ( V_32 , V_96 ) ;
return V_32 ;
V_144:
F_36 ( V_32 ) ;
V_142:
F_38 ( V_32 ) ;
F_87 ( V_32 , 0 ) ;
V_141:
F_88 ( V_32 -> V_115 ) ;
V_125:
F_89 ( V_32 ) ;
V_113:
F_90 () ;
return NULL ;
}
static void F_91 ( struct V_67 * V_34 , struct V_145 * V_146 ,
T_5 V_147 )
{
struct V_145 * V_45 ;
int V_14 = 0 ;
bool V_148 = ! ! ( V_147 & V_149 ) ;
do {
struct V_150 * V_151 = NULL ;
struct V_152 V_153 ;
F_92 ( V_34 ) ;
F_93 (tmp, q) {
V_151 = F_94 ( V_45 , struct V_150 , V_154 ) ;
if ( F_95 ( V_151 ) ) {
V_151 = NULL ;
continue;
}
F_96 ( V_151 ) ;
F_97 ( V_151 ) ;
break;
}
if ( ! V_151 ) {
F_98 ( V_34 ) ;
break;
}
F_99 ( V_151 ) ;
F_100 ( V_151 ) ;
V_151 -> V_155 |= V_147 ;
if ( V_148 )
F_101 ( V_151 ) ;
if ( V_148 && ( V_151 -> V_156 || V_151 -> V_157 ) ) {
F_98 ( V_34 ) ;
F_102 ( V_151 , L_25 ) ;
if ( V_151 -> V_155 & V_158 ) {
F_103 ( V_159 ) ;
F_104 ( F_105 ( 4 ) ) ;
F_103 ( V_160 ) ;
}
if ( V_151 -> V_161 )
V_151 -> V_161 ( V_151 , V_162 ,
NULL ) ;
F_106 ( V_151 ) ;
continue;
}
F_98 ( V_34 ) ;
F_107 ( V_151 , & V_153 ) ;
V_14 = F_108 ( & V_153 , V_163 ) ;
if ( V_14 )
F_10 ( L_26 , V_14 ) ;
F_106 ( V_151 ) ;
} while ( 1 );
}
static int F_109 ( struct V_71 * V_72 , struct V_35 * V_36 ,
struct V_91 * V_92 , void * V_164 )
{
struct V_67 * V_34 = F_110 ( V_72 , V_92 ) ;
T_5 V_147 = * ( T_5 * ) V_164 ;
F_91 ( V_34 , & V_34 -> V_165 , V_147 ) ;
F_91 ( V_34 , & V_34 -> V_166 , V_147 ) ;
return 0 ;
}
static int F_111 ( struct V_71 * V_72 , struct V_35 * V_36 ,
struct V_91 * V_92 , void * V_164 )
{
struct V_67 * V_34 = F_110 ( V_72 , V_92 ) ;
F_92 ( V_34 ) ;
F_10 ( L_27 V_167
L_28 ,
F_26 ( F_112 ( V_34 ) ) , F_113 ( V_34 ) , V_34 ,
F_51 ( & V_34 -> V_69 ) - 1 ) ;
F_114 ( V_168 , V_34 ) ;
F_98 ( V_34 ) ;
return 0 ;
}
int F_87 ( struct V_31 * V_32 , T_5 V_147 )
{
if ( ! V_32 ) {
F_25 ( V_70 , L_29 ) ;
return V_169 ;
}
F_115 ( V_32 -> V_115 , F_109 ,
& V_147 , 0 ) ;
F_115 ( V_32 -> V_115 , F_111 ,
NULL , 0 ) ;
return V_169 ;
}
static int F_116 ( struct V_31 * V_32 , int V_170 )
{
F_87 ( V_32 , V_170 ? V_149 : 0 ) ;
if ( F_51 ( & V_32 -> V_134 ) > 0 ) {
struct V_171 V_172 = F_117 ( V_173 , NULL ) ;
int V_14 ;
F_25 ( V_6 ,
L_30 ,
F_26 ( V_32 ) , F_51 ( & V_32 -> V_134 ) ) ;
V_174:
if ( V_170 )
V_172 = F_118 ( F_119 ( V_175 *
V_176 ) / 4 , NULL , NULL ) ;
V_14 = F_120 ( V_32 -> V_135 ,
F_51 ( & V_32 -> V_134 ) == 0 , & V_172 ) ;
if ( V_170 && V_14 == - V_177 ) {
F_121 ( L_31 ,
F_26 ( V_32 ) ,
F_51 ( & V_32 -> V_134 ) , V_14 ) ;
goto V_174;
}
if ( F_51 ( & V_32 -> V_134 ) ) {
F_121 ( L_32 ,
F_26 ( V_32 ) ,
F_51 ( & V_32 -> V_134 ) , V_14 ) ;
return V_178 ;
}
F_25 ( V_6 , L_33 ,
F_26 ( V_32 ) ) ;
}
return V_169 ;
}
void F_122 ( struct V_31 * V_32 ,
struct V_179 * V_180 ,
int V_170 )
{
int V_14 ;
if ( ! V_32 )
return;
F_123 ( & V_32 -> V_133 ) ;
V_32 -> V_140 = 1 ;
F_124 ( & V_32 -> V_133 ) ;
V_14 = F_116 ( V_32 , V_170 ) ;
if ( V_14 != V_169 ) {
if ( V_180 ) {
F_125 ( V_180 , 0 ) ;
F_126 ( V_180 ) ;
}
V_14 = F_116 ( V_32 , 1 ) ;
F_49 ( V_14 == 0 ) ;
}
}
static void F_127 ( struct V_31 * V_32 ,
enum V_95 V_96 )
{
F_69 ( F_70 ( V_96 ) ) ;
F_49 ( ! F_71 ( & V_32 -> V_97 ) ) ;
F_128 ( & V_32 -> V_97 ) ;
F_129 ( V_96 ) ;
F_74 ( F_70 ( V_96 ) ) ;
}
void F_130 ( struct V_31 * V_32 )
{
if ( ! V_32 )
return;
F_127 ( V_32 , V_32 -> V_131 ) ;
F_131 ( & V_32 -> V_143 ) ;
F_36 ( V_32 ) ;
F_38 ( V_32 ) ;
F_88 ( V_32 -> V_115 ) ;
F_49 ( F_71 ( & V_32 -> V_97 ) ) ;
F_89 ( V_32 ) ;
F_90 () ;
}
void F_132 ( struct V_31 * V_32 )
{
F_50 ( & V_32 -> V_134 ) ;
}
static int F_133 ( struct V_31 * V_32 )
{
return F_134 ( & V_32 -> V_134 ) ;
}
void F_135 ( struct V_31 * V_32 )
{
if ( F_136 ( & V_32 -> V_134 , & V_32 -> V_133 ) ) {
F_137 ( & V_32 -> V_135 ) ;
F_124 ( & V_32 -> V_133 ) ;
}
}
void F_138 ( struct V_31 * V_32 ,
enum V_95 V_96 )
{
F_49 ( ! F_71 ( & V_32 -> V_97 ) ) ;
F_49 ( F_139 ( F_70 ( V_96 ) ) ) ;
F_140 ( & V_32 -> V_97 , F_141 ( V_96 ) ) ;
}
void F_142 ( struct V_31 * V_32 ,
enum V_95 V_96 )
{
F_49 ( ! F_71 ( & V_32 -> V_97 ) ) ;
F_49 ( F_139 ( F_70 ( V_96 ) ) ) ;
F_140 ( & V_32 -> V_97 , & V_98 ) ;
}
struct V_31 * F_143 ( enum V_95 V_96 )
{
F_49 ( F_139 ( F_70 ( V_96 ) ) ) ;
F_49 ( ! F_71 ( F_141 ( V_96 ) ) ) ;
return F_16 ( F_141 ( V_96 ) -> V_181 ,
struct V_31 , V_97 ) ;
}
static struct V_67 * F_144 ( void )
{
struct V_67 * V_34 ;
int V_109 ;
V_34 = F_145 ( V_182 , V_114 ) ;
if ( ! V_34 )
return NULL ;
F_81 ( & V_34 -> V_165 ) ;
F_81 ( & V_34 -> V_166 ) ;
for ( V_109 = 0 ; V_109 < V_183 ; V_109 ++ ) {
V_34 -> V_184 [ V_109 ] . V_185 = 0 ;
V_34 -> V_184 [ V_109 ] . V_186 = 1 << V_109 ;
V_34 -> V_184 [ V_109 ] . V_187 = NULL ;
}
F_83 ( & V_34 -> V_69 , 1 ) ;
F_82 ( & V_34 -> V_188 ) ;
F_146 ( & V_34 -> V_189 ) ;
F_147 ( & V_34 -> V_190 ) ;
F_69 ( & V_34 -> V_190 ) ;
return V_34 ;
}
struct V_67 *
F_148 ( struct V_31 * V_32 , struct V_67 * V_191 ,
const struct V_75 * V_79 , enum V_192 type ,
int V_193 )
{
struct V_91 * V_92 ;
struct V_67 * V_34 = NULL ;
struct V_35 V_36 ;
T_5 V_194 ;
int V_195 = 0 ;
int V_14 ;
F_49 ( ! V_191 ) ;
F_49 ( V_32 -> V_115 ) ;
F_49 ( V_79 -> V_79 [ 0 ] != 0 ) ;
F_149 ( V_32 -> V_115 , ( void * ) V_79 , & V_36 , 0 ) ;
V_92 = F_150 ( V_32 -> V_115 , & V_36 , ( void * ) V_79 ) ;
if ( V_92 ) {
F_151 ( V_32 -> V_115 , & V_36 , 0 ) ;
goto V_196;
}
V_194 = F_152 ( & V_36 ) ;
F_151 ( V_32 -> V_115 , & V_36 , 0 ) ;
if ( V_193 == 0 )
return F_153 ( - V_197 ) ;
F_154 ( type >= V_198 && type < V_199 ,
L_34 , type ) ;
V_34 = F_144 () ;
if ( ! V_34 )
return F_153 ( - V_18 ) ;
V_34 -> V_200 = F_79 ( V_32 -> V_115 , & V_36 ) ;
V_34 -> V_94 = * V_79 ;
V_34 -> V_201 = type ;
F_155 ( V_32 -> V_115 , & V_36 , 1 ) ;
V_92 = ( V_194 == F_152 ( & V_36 ) ) ? NULL :
F_150 ( V_32 -> V_115 , & V_36 , ( void * ) V_79 ) ;
if ( V_92 ) {
F_151 ( V_32 -> V_115 , & V_36 , 1 ) ;
F_156 ( & V_34 -> V_189 ) ;
F_74 ( & V_34 -> V_190 ) ;
F_157 ( V_182 , V_34 ) ;
V_196:
V_34 = F_59 ( V_92 , struct V_67 , V_93 ) ;
if ( V_32 -> V_202 && V_32 -> V_202 -> V_196 ) {
F_69 ( & V_34 -> V_190 ) ;
F_74 ( & V_34 -> V_190 ) ;
}
if ( F_158 ( V_34 -> V_203 < 0 ) ) {
V_14 = V_34 -> V_203 ;
F_67 ( V_34 ) ;
V_34 = F_153 ( V_14 ) ;
}
return V_34 ;
}
F_159 ( V_32 -> V_115 , & V_36 , & V_34 -> V_93 ) ;
if ( F_18 ( & V_36 ) == 1 )
V_195 = F_133 ( V_32 ) ;
F_151 ( V_32 -> V_115 , & V_36 , 1 ) ;
if ( V_32 -> V_202 && V_32 -> V_202 -> V_196 ) {
F_160 ( V_204 , 2 ) ;
V_14 = V_32 -> V_202 -> V_196 ( V_34 ) ;
if ( V_14 < 0 ) {
F_10 ( L_35 ,
V_32 -> V_129 -> V_205 , V_79 -> V_79 [ 0 ] ,
V_79 -> V_79 [ 1 ] , V_14 ) ;
V_34 -> V_203 = V_14 ;
F_74 ( & V_34 -> V_190 ) ;
F_67 ( V_34 ) ;
return F_153 ( V_14 ) ;
}
}
F_74 ( & V_34 -> V_190 ) ;
if ( V_195 == 1 ) {
F_69 ( F_70 ( V_7 ) ) ;
F_138 ( V_32 , V_7 ) ;
F_74 ( F_70 ( V_7 ) ) ;
}
return V_34 ;
}
static void F_161 ( struct V_35 * V_36 ,
struct V_67 * V_34 )
{
struct V_105 * V_106 = V_34 -> V_200 ;
if ( ! F_71 ( & V_34 -> V_165 ) ) {
F_114 ( V_168 , V_34 ) ;
F_162 () ;
}
if ( ! F_71 ( & V_34 -> V_166 ) ) {
F_114 ( V_168 , V_34 ) ;
F_162 () ;
}
F_163 ( V_106 -> V_128 -> V_115 ,
V_36 , & V_34 -> V_93 ) ;
F_156 ( & V_34 -> V_189 ) ;
if ( F_18 ( V_36 ) == 0 )
F_135 ( V_106 -> V_128 ) ;
}
int F_67 ( struct V_67 * V_34 )
{
struct V_31 * V_32 = F_112 ( V_34 ) ;
struct V_35 V_36 ;
F_164 ( & V_34 -> V_69 , 0 , V_206 ) ;
F_25 ( V_70 , L_36 ,
V_34 , F_51 ( & V_34 -> V_69 ) - 1 ) ;
F_165 ( V_32 -> V_115 , & V_34 -> V_94 , & V_36 ) ;
if ( F_166 ( V_32 -> V_115 , & V_36 , & V_34 -> V_69 ) ) {
F_161 ( & V_36 , V_34 ) ;
F_151 ( V_32 -> V_115 , & V_36 , 1 ) ;
if ( V_32 -> V_202 && V_32 -> V_202 -> V_207 )
V_32 -> V_202 -> V_207 ( V_34 ) ;
F_157 ( V_182 , V_34 ) ;
return 1 ;
}
return 0 ;
}
int F_65 ( struct V_67 * V_34 )
{
struct V_31 * V_32 = F_112 ( V_34 ) ;
F_164 ( & V_34 -> V_69 , 0 , V_206 ) ;
F_25 ( V_70 , L_36 ,
V_34 , F_51 ( & V_34 -> V_69 ) - 1 ) ;
if ( F_167 ( & V_34 -> V_69 ) ) {
struct V_35 V_36 ;
F_165 ( F_112 ( V_34 ) -> V_115 ,
& V_34 -> V_94 , & V_36 ) ;
F_161 ( & V_36 , V_34 ) ;
F_151 ( V_32 -> V_115 , & V_36 , 1 ) ;
if ( V_32 -> V_202 && V_32 -> V_202 -> V_207 )
V_32 -> V_202 -> V_207 ( V_34 ) ;
F_157 ( V_182 , V_34 ) ;
F_155 ( V_32 -> V_115 , & V_36 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_168 ( struct V_67 * V_34 , struct V_145 * V_208 ,
struct V_150 * V_151 )
{
F_169 ( V_34 ) ;
F_102 ( V_151 , L_37 ) ;
if ( F_170 ( V_151 ) ) {
F_25 ( V_209 , L_38 ) ;
return;
}
F_49 ( F_71 ( & V_151 -> V_154 ) ) ;
F_171 ( & V_151 -> V_154 , V_208 ) ;
}
void F_172 ( struct V_150 * V_151 )
{
int type = V_151 -> V_210 -> V_201 ;
F_169 ( V_151 -> V_210 ) ;
if ( type == V_211 || type == V_212 )
F_173 ( V_151 ) ;
else if ( type == V_213 )
F_174 ( V_151 ) ;
F_128 ( & V_151 -> V_154 ) ;
}
void F_175 ( struct V_67 * V_34 , struct V_214 * V_215 )
{
V_215 -> V_201 = V_34 -> V_201 ;
V_215 -> V_94 = V_34 -> V_94 ;
}
void F_2 ( enum V_95 V_96 , int V_216 )
{
struct V_145 * V_45 ;
if ( ! ( ( V_217 | V_168 ) & V_216 ) )
return;
F_69 ( F_70 ( V_96 ) ) ;
F_93 (tmp, ldlm_namespace_list(client)) {
struct V_31 * V_32 ;
V_32 = F_94 ( V_45 , struct V_31 , V_97 ) ;
F_176 ( V_216 , V_32 ) ;
}
F_74 ( F_70 ( V_96 ) ) ;
}
static int F_177 ( struct V_71 * V_72 , struct V_35 * V_36 ,
struct V_91 * V_92 , void * V_164 )
{
struct V_67 * V_34 = F_110 ( V_72 , V_92 ) ;
int V_216 = ( int ) ( unsigned long ) V_164 ;
F_92 ( V_34 ) ;
F_114 ( V_216 , V_34 ) ;
F_98 ( V_34 ) ;
return 0 ;
}
void F_176 ( int V_216 , struct V_31 * V_32 )
{
if ( ! ( ( V_217 | V_168 ) & V_216 ) )
return;
F_25 ( V_216 , L_39 ,
F_26 ( V_32 ) , F_51 ( & V_32 -> V_134 ) ) ;
if ( F_178 ( F_179 () , V_32 -> V_218 ) )
return;
F_115 ( V_32 -> V_115 ,
F_177 ,
( void * ) ( unsigned long ) V_216 , 0 ) ;
F_123 ( & V_32 -> V_133 ) ;
V_32 -> V_218 = F_180 ( 10 ) ;
F_124 ( & V_32 -> V_133 ) ;
}
void F_114 ( int V_216 , struct V_67 * V_34 )
{
struct V_150 * V_151 ;
unsigned int V_219 = 0 ;
F_181 ( V_78 != 4 ) ;
if ( ! ( ( V_217 | V_168 ) & V_216 ) )
return;
F_25 ( V_216 , L_40 V_167 L_41 ,
F_113 ( V_34 ) , V_34 , F_51 ( & V_34 -> V_69 ) ) ;
if ( ! F_71 ( & V_34 -> V_165 ) ) {
F_25 ( V_216 , L_42 ) ;
F_182 (lock, &res->lr_granted,
l_res_link) {
F_183 ( V_216 , V_151 , L_43 ) ;
if ( ! ( V_216 & V_220 ) &&
++ V_219 > V_221 ) {
F_25 ( V_216 , L_44 ,
V_219 ) ;
break;
}
}
}
if ( ! F_71 ( & V_34 -> V_166 ) ) {
F_25 ( V_216 , L_45 ) ;
F_184 (lock, &res->lr_waiting, l_res_link)
F_183 ( V_216 , V_151 , L_43 ) ;
}
}
