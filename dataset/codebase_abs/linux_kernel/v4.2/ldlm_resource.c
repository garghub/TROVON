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
return 0 ;
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
static T_1 F_11 ( struct V_19 * V_20 , struct V_21 * V_22 ,
char * V_23 )
{
struct V_24 * V_25 = F_12 ( V_20 , struct V_24 ,
V_26 ) ;
T_5 V_27 = 0 ;
struct V_28 V_29 ;
int V_30 ;
F_13 (ns->ns_rs_hash, &bd, i)
V_27 += F_14 ( & V_29 ) ;
return sprintf ( V_23 , L_4 , V_27 ) ;
}
static T_1 F_15 ( struct V_19 * V_20 , struct V_21 * V_22 ,
char * V_23 )
{
struct V_24 * V_25 = F_12 ( V_20 , struct V_24 ,
V_26 ) ;
T_5 V_31 ;
V_31 = F_16 ( V_25 -> V_32 , V_33 ,
V_34 ) ;
return sprintf ( V_23 , L_4 , V_31 ) ;
}
static T_1 F_17 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
char * V_23 )
{
struct V_24 * V_25 = F_12 ( V_20 , struct V_24 ,
V_26 ) ;
return sprintf ( V_23 , L_5 , V_25 -> V_35 ) ;
}
static T_1 F_18 ( struct V_19 * V_20 , struct V_21 * V_22 ,
char * V_23 )
{
struct V_24 * V_25 = F_12 ( V_20 , struct V_24 ,
V_26 ) ;
T_6 * V_36 = & V_25 -> V_37 ;
if ( F_19 ( V_25 ) )
V_36 = & V_25 -> V_35 ;
return sprintf ( V_23 , L_6 , * V_36 ) ;
}
static T_1 F_20 ( struct V_19 * V_20 , struct V_21 * V_22 ,
const char * V_2 , T_3 V_3 )
{
struct V_24 * V_25 = F_12 ( V_20 , struct V_24 ,
V_26 ) ;
unsigned long V_38 ;
int V_39 ;
int V_13 ;
if ( strncmp ( V_2 , L_7 , 5 ) == 0 ) {
F_21 ( V_6 ,
L_8 ,
F_22 ( V_25 ) ) ;
if ( F_19 ( V_25 ) ) {
int V_40 , V_41 = V_25 -> V_35 ;
V_40 = F_23 ( V_25 , V_41 , 0 ,
V_42 ) ;
if ( V_40 < V_41 ) {
F_21 ( V_6 ,
L_9 ,
V_41 ,
V_40 ) ;
return - V_43 ;
}
} else {
V_38 = V_25 -> V_37 ;
V_25 -> V_37 = 0 ;
F_23 ( V_25 , 0 , 0 , V_42 ) ;
V_25 -> V_37 = V_38 ;
}
return V_3 ;
}
V_13 = F_24 ( V_2 , 10 , & V_38 ) ;
if ( V_13 != 0 ) {
F_6 ( L_10 ) ;
return - V_43 ;
}
V_39 = ( V_38 == 0 ) ;
if ( F_19 ( V_25 ) ) {
if ( ! V_39 )
V_25 -> V_37 = ( unsigned int ) V_38 ;
if ( V_38 > V_25 -> V_35 )
V_38 = V_25 -> V_35 ;
V_38 = V_25 -> V_35 - V_38 ;
F_21 ( V_6 ,
L_11 ,
F_22 ( V_25 ) , V_25 -> V_35 ,
( unsigned int ) V_38 ) ;
F_23 ( V_25 , V_38 , V_44 , V_42 ) ;
if ( ! V_39 ) {
F_21 ( V_6 ,
L_12 ,
F_22 ( V_25 ) ) ;
V_25 -> V_45 &= ~ V_46 ;
}
} else {
F_21 ( V_6 ,
L_13 ,
F_22 ( V_25 ) , V_25 -> V_37 ,
( unsigned int ) V_38 ) ;
V_25 -> V_37 = ( unsigned int ) V_38 ;
F_23 ( V_25 , 0 , V_44 , V_42 ) ;
if ( V_39 &&
( V_25 -> V_47 & V_46 ) ) {
F_21 ( V_6 ,
L_14 ,
F_22 ( V_25 ) ) ;
V_25 -> V_45 |= V_46 ;
}
}
return V_3 ;
}
static T_1 F_25 ( struct V_19 * V_20 , struct V_21 * V_22 ,
char * V_23 )
{
struct V_24 * V_25 = F_12 ( V_20 , struct V_24 ,
V_26 ) ;
return sprintf ( V_23 , L_6 , V_25 -> V_48 ) ;
}
static T_1 F_26 ( struct V_19 * V_20 , struct V_21 * V_22 ,
const char * V_2 , T_3 V_3 )
{
struct V_24 * V_25 = F_12 ( V_20 , struct V_24 ,
V_26 ) ;
unsigned long V_38 ;
int V_13 ;
V_13 = F_24 ( V_2 , 10 , & V_38 ) ;
if ( V_13 != 0 )
return - V_43 ;
V_25 -> V_48 = V_38 ;
return V_3 ;
}
static T_1 F_27 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
char * V_23 )
{
struct V_24 * V_25 = F_12 ( V_20 , struct V_24 ,
V_26 ) ;
return sprintf ( V_23 , L_5 , F_28 ( V_25 ) ) ;
}
static T_1 F_29 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
const char * V_2 ,
T_3 V_3 )
{
struct V_24 * V_25 = F_12 ( V_20 , struct V_24 ,
V_26 ) ;
unsigned long V_49 = - 1 ;
int V_8 ;
V_8 = F_24 ( V_2 , 10 , & V_49 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_49 == 0 )
V_25 -> V_45 &= ~ V_50 ;
else if ( V_25 -> V_47 & V_50 )
V_25 -> V_45 |= V_50 ;
return V_3 ;
}
static void F_30 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_12 ( V_20 , struct V_24 ,
V_26 ) ;
F_31 ( & V_25 -> V_51 ) ;
}
static void F_32 ( struct V_24 * V_25 )
{
if ( F_5 ( V_25 -> V_52 ) )
F_6 ( L_15 ,
F_22 ( V_25 ) ) ;
else
F_9 ( & V_25 -> V_52 ) ;
if ( V_25 -> V_32 != NULL )
F_33 ( & V_25 -> V_32 ) ;
}
void F_34 ( struct V_24 * V_25 )
{
F_35 ( & V_25 -> V_26 ) ;
F_36 ( & V_25 -> V_51 ) ;
}
int F_37 ( struct V_24 * V_25 )
{
int V_13 ;
V_25 -> V_26 . V_53 = V_54 ;
F_38 ( & V_25 -> V_51 ) ;
V_13 = F_39 ( & V_25 -> V_26 , & V_55 , NULL ,
L_16 , F_22 ( V_25 ) ) ;
V_25 -> V_32 = F_40 ( V_56 , 0 ) ;
if ( V_25 -> V_32 == NULL ) {
F_35 ( & V_25 -> V_26 ) ;
return - V_12 ;
}
F_41 ( V_25 -> V_32 , V_33 ,
V_57 , L_17 , L_17 ) ;
return V_13 ;
}
static int F_42 ( struct V_24 * V_25 )
{
struct V_58 * V_59 ;
if ( ! F_5 ( V_25 -> V_52 ) ) {
V_59 = V_25 -> V_52 ;
} else {
V_59 = F_43 ( F_22 ( V_25 ) ,
V_14 ) ;
if ( V_59 == NULL )
return - V_12 ;
V_25 -> V_52 = V_59 ;
}
return 0 ;
}
static unsigned F_44 ( struct V_60 * V_61 ,
const void * V_62 , unsigned V_63 )
{
const struct V_64 * V_65 = V_62 ;
unsigned V_66 = 0 ;
unsigned V_30 ;
for ( V_30 = 0 ; V_30 < V_67 ; V_30 ++ )
V_66 += V_65 -> V_68 [ V_30 ] ;
return V_66 & V_63 ;
}
static unsigned F_45 ( struct V_60 * V_61 ,
const void * V_62 , unsigned V_63 )
{
const struct V_64 * V_65 = V_62 ;
struct V_69 V_70 ;
T_6 V_71 ;
T_6 V_66 ;
V_70 . V_72 = V_65 -> V_68 [ V_73 ] ;
V_70 . V_74 = ( T_6 ) V_65 -> V_68 [ V_75 ] ;
V_70 . V_76 = ( T_6 ) ( V_65 -> V_68 [ V_75 ] >> 32 ) ;
V_71 = F_46 ( & V_70 ) ;
V_71 += ( V_71 >> 4 ) + ( V_71 << 12 ) ;
if ( V_65 -> V_68 [ V_77 ] != 0 ) {
V_66 = V_65 -> V_68 [ V_77 ] ;
V_71 += ( V_66 >> 5 ) + ( V_66 << 11 ) ;
} else {
V_66 = F_47 ( & V_70 ) ;
}
V_71 = F_48 ( V_71 , V_61 -> V_78 ) ;
V_71 -= F_48 ( ( unsigned long ) V_61 , V_66 % 11 + 3 ) ;
V_71 <<= V_61 -> V_79 - V_61 -> V_78 ;
V_71 |= F_44 ( V_61 , V_62 , F_49 ( V_61 ) - 1 ) ;
return V_71 & V_63 ;
}
static void * F_50 ( struct V_80 * V_81 )
{
struct V_82 * V_27 ;
V_27 = F_51 ( V_81 , struct V_82 , V_83 ) ;
return & V_27 -> V_84 ;
}
static int F_52 ( const void * V_62 , struct V_80 * V_81 )
{
struct V_82 * V_27 ;
V_27 = F_51 ( V_81 , struct V_82 , V_83 ) ;
return F_53 ( ( const struct V_64 * ) V_62 ,
( const struct V_64 * ) & V_27 -> V_84 ) ;
}
static void * F_54 ( struct V_80 * V_81 )
{
return F_51 ( V_81 , struct V_82 , V_83 ) ;
}
static void F_55 ( struct V_60 * V_61 ,
struct V_80 * V_81 )
{
struct V_82 * V_27 ;
V_27 = F_51 ( V_81 , struct V_82 , V_83 ) ;
F_56 ( V_27 ) ;
}
static void F_57 ( struct V_60 * V_61 ,
struct V_80 * V_81 )
{
struct V_82 * V_27 ;
V_27 = F_51 ( V_81 , struct V_82 , V_83 ) ;
F_58 ( V_27 ) ;
}
static void F_59 ( struct V_60 * V_61 , struct V_80 * V_81 )
{
struct V_82 * V_27 ;
V_27 = F_51 ( V_81 , struct V_82 , V_83 ) ;
F_60 ( V_27 ) ;
}
struct V_24 * F_61 ( struct V_85 * V_86 , char * V_68 ,
T_7 V_87 ,
T_8 V_88 ,
T_9 V_89 )
{
struct V_24 * V_25 = NULL ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_28 V_29 ;
int V_94 ;
int V_8 ;
F_62 ( V_86 != NULL ) ;
V_8 = F_63 () ;
if ( V_8 ) {
F_6 ( L_18 , V_8 ) ;
return NULL ;
}
for ( V_94 = 0 ; ; V_94 ++ ) {
V_93 = & V_95 [ V_94 ] ;
if ( V_93 -> V_96 == V_97 ) {
F_6 ( L_19 , V_89 , V_68 ) ;
goto V_98;
}
if ( V_93 -> V_96 == V_89 )
break;
}
V_25 = F_64 ( sizeof( * V_25 ) , V_99 ) ;
if ( ! V_25 )
goto V_98;
V_25 -> V_100 = F_65 ( V_68 ,
V_93 -> V_101 , V_93 -> V_101 ,
V_93 -> V_102 , sizeof( * V_91 ) ,
V_103 ,
V_104 ,
V_93 -> V_105 ,
V_106 |
V_107 |
V_108 |
V_109 ) ;
if ( V_25 -> V_100 == NULL )
goto V_110;
F_13 (ns->ns_rs_hash, &bd, idx) {
V_91 = F_66 ( V_25 -> V_100 , & V_29 ) ;
F_67 ( & V_91 -> V_111 , V_112 , 0 ) ;
V_91 -> V_113 = V_25 ;
}
V_25 -> V_114 = V_86 ;
V_25 -> V_115 = V_88 ;
V_25 -> V_116 = V_87 ;
F_68 ( & V_25 -> V_117 ) ;
F_68 ( & V_25 -> V_118 ) ;
F_69 ( & V_25 -> V_119 ) ;
F_70 ( & V_25 -> V_120 , 0 ) ;
F_71 ( & V_25 -> V_121 ) ;
V_25 -> V_122 = V_123 ;
V_25 -> V_35 = 0 ;
V_25 -> V_37 = V_124 ;
V_25 -> V_48 = V_125 ;
V_25 -> V_47 = 0 ;
V_25 -> V_45 = 0 ;
V_25 -> V_126 = 0 ;
V_8 = F_37 ( V_25 ) ;
if ( V_8 != 0 ) {
F_6 ( L_20 , V_8 ) ;
goto V_127;
}
V_8 = F_42 ( V_25 ) ;
if ( V_8 != 0 ) {
F_6 ( L_21 , V_8 ) ;
goto V_128;
}
V_94 = F_72 ( V_87 ) ;
V_8 = F_73 ( & V_25 -> V_129 , V_25 , V_94 , V_87 ) ;
if ( V_8 ) {
F_6 ( L_22 , V_8 ) ;
goto V_130;
}
F_74 ( V_25 , V_87 ) ;
return V_25 ;
V_130:
F_32 ( V_25 ) ;
V_128:
F_34 ( V_25 ) ;
F_75 ( V_25 , 0 ) ;
V_127:
F_76 ( V_25 -> V_100 ) ;
V_110:
F_77 ( V_25 ) ;
V_98:
F_78 () ;
return NULL ;
}
static void F_79 ( struct V_82 * V_27 , struct V_131 * V_132 ,
T_5 V_133 )
{
struct V_131 * V_38 ;
int V_8 = 0 , V_87 = F_80 ( F_81 ( V_27 ) ) ;
bool V_134 = ! ! ( V_133 & V_135 ) ;
do {
struct V_136 * V_137 = NULL ;
F_82 ( V_27 ) ;
F_83 (tmp, q) {
V_137 = F_84 ( V_38 , struct V_136 ,
V_138 ) ;
if ( V_137 -> V_139 & V_140 ) {
V_137 = NULL ;
continue;
}
F_85 ( V_137 ) ;
V_137 -> V_139 |= V_140 ;
break;
}
if ( V_137 == NULL ) {
F_86 ( V_27 ) ;
break;
}
V_137 -> V_139 |= V_141 ;
V_137 -> V_139 |= V_142 ;
V_137 -> V_139 |= V_133 ;
if ( V_134 )
V_137 -> V_139 |= V_135 ;
if ( V_134 && ( V_137 -> V_143 || V_137 -> V_144 ) ) {
F_86 ( V_27 ) ;
F_87 ( V_137 , L_23 ) ;
if ( V_137 -> V_145 )
V_137 -> V_145 ( V_137 , 0 , NULL ) ;
F_88 ( V_137 ) ;
continue;
}
if ( V_87 ) {
struct V_146 V_147 ;
F_86 ( V_27 ) ;
F_89 ( V_137 , & V_147 ) ;
V_8 = F_90 ( & V_147 , V_44 ) ;
if ( V_8 )
F_6 ( L_24 , V_8 ) ;
} else {
F_91 ( V_137 ) ;
F_86 ( V_27 ) ;
F_87 ( V_137 , L_25 ) ;
F_92 ( V_137 ) ;
}
F_88 ( V_137 ) ;
} while ( 1 );
}
static int F_93 ( struct V_60 * V_61 , struct V_28 * V_29 ,
struct V_80 * V_81 , void * V_148 )
{
struct V_82 * V_27 = F_94 ( V_61 , V_81 ) ;
T_5 V_133 = * ( T_5 * ) V_148 ;
F_79 ( V_27 , & V_27 -> V_149 , V_133 ) ;
F_79 ( V_27 , & V_27 -> V_150 , V_133 ) ;
F_79 ( V_27 , & V_27 -> V_151 , V_133 ) ;
return 0 ;
}
static int F_95 ( struct V_60 * V_61 , struct V_28 * V_29 ,
struct V_80 * V_81 , void * V_148 )
{
struct V_82 * V_27 = F_94 ( V_61 , V_81 ) ;
F_82 ( V_27 ) ;
F_6 ( L_26 V_152
L_27 ,
F_22 ( F_81 ( V_27 ) ) , F_96 ( V_27 ) , V_27 ,
F_97 ( & V_27 -> V_153 ) - 1 ) ;
F_98 ( V_154 , V_27 ) ;
F_86 ( V_27 ) ;
return 0 ;
}
int F_75 ( struct V_24 * V_25 , T_5 V_133 )
{
if ( V_25 == NULL ) {
F_21 ( V_155 , L_28 ) ;
return V_156 ;
}
F_99 ( V_25 -> V_100 , F_93 , & V_133 ) ;
F_99 ( V_25 -> V_100 , F_95 , NULL ) ;
return V_156 ;
}
static int F_100 ( struct V_24 * V_25 , int V_157 )
{
F_75 ( V_25 , V_157 ? V_135 : 0 ) ;
if ( F_97 ( & V_25 -> V_120 ) > 0 ) {
struct V_158 V_159 = F_101 ( V_160 , NULL ) ;
int V_8 ;
F_21 ( V_6 ,
L_29 ,
F_22 ( V_25 ) , F_97 ( & V_25 -> V_120 ) ) ;
V_161:
if ( V_157 )
V_159 = F_102 ( V_162 * V_163 / 4 , NULL , NULL ) ;
V_8 = F_103 ( V_25 -> V_121 ,
F_97 ( & V_25 -> V_120 ) == 0 , & V_159 ) ;
if ( V_157 && V_8 == - V_164 ) {
F_104 ( L_30 ,
F_22 ( V_25 ) ,
F_97 ( & V_25 -> V_120 ) , V_8 ) ;
goto V_161;
}
if ( F_97 ( & V_25 -> V_120 ) ) {
F_104 ( L_31 ,
F_22 ( V_25 ) ,
F_97 ( & V_25 -> V_120 ) , V_8 ) ;
return V_165 ;
}
F_21 ( V_6 , L_32 ,
F_22 ( V_25 ) ) ;
}
return V_156 ;
}
void F_105 ( struct V_24 * V_25 ,
struct V_166 * V_167 ,
int V_157 )
{
int V_8 ;
if ( ! V_25 )
return;
F_106 ( & V_25 -> V_119 ) ;
V_25 -> V_126 = 1 ;
F_107 ( & V_25 -> V_119 ) ;
V_8 = F_100 ( V_25 , V_157 ) ;
if ( V_8 != V_156 ) {
if ( V_167 ) {
F_108 ( V_167 , 0 ) ;
F_109 ( V_167 ) ;
}
V_8 = F_100 ( V_25 , 1 ) ;
F_62 ( V_8 == 0 ) ;
}
}
void F_110 ( struct V_24 * V_25 )
{
if ( ! V_25 )
return;
F_111 ( V_25 , V_25 -> V_116 ) ;
F_112 ( & V_25 -> V_129 ) ;
F_32 ( V_25 ) ;
F_76 ( V_25 -> V_100 ) ;
F_62 ( F_113 ( & V_25 -> V_117 ) ) ;
F_77 ( V_25 ) ;
F_78 () ;
}
void F_114 ( struct V_24 * V_25 ,
struct V_166 * V_167 ,
int V_157 )
{
F_105 ( V_25 , V_167 , V_157 ) ;
F_110 ( V_25 ) ;
}
void F_115 ( struct V_24 * V_25 )
{
F_116 ( & V_25 -> V_120 ) ;
}
int F_117 ( struct V_24 * V_25 )
{
return F_118 ( & V_25 -> V_120 ) ;
}
void F_119 ( struct V_24 * V_25 )
{
if ( F_120 ( & V_25 -> V_120 , & V_25 -> V_119 ) ) {
F_121 ( & V_25 -> V_121 ) ;
F_107 ( & V_25 -> V_119 ) ;
}
}
void F_74 ( struct V_24 * V_25 , T_7 V_87 )
{
F_122 ( F_123 ( V_87 ) ) ;
F_62 ( F_113 ( & V_25 -> V_117 ) ) ;
F_124 ( & V_25 -> V_117 , F_125 ( V_87 ) ) ;
F_126 ( V_87 ) ;
F_127 ( F_123 ( V_87 ) ) ;
}
void F_111 ( struct V_24 * V_25 , T_7 V_87 )
{
F_122 ( F_123 ( V_87 ) ) ;
F_62 ( ! F_113 ( & V_25 -> V_117 ) ) ;
F_128 ( & V_25 -> V_117 ) ;
F_129 ( V_87 ) ;
F_127 ( F_123 ( V_87 ) ) ;
}
void F_130 ( struct V_24 * V_25 ,
T_7 V_87 )
{
F_62 ( ! F_113 ( & V_25 -> V_117 ) ) ;
F_62 ( F_131 ( F_123 ( V_87 ) ) ) ;
F_132 ( & V_25 -> V_117 , F_133 ( V_87 ) ) ;
}
void F_134 ( struct V_24 * V_25 ,
T_7 V_87 )
{
F_62 ( ! F_113 ( & V_25 -> V_117 ) ) ;
F_62 ( F_131 ( F_123 ( V_87 ) ) ) ;
F_132 ( & V_25 -> V_117 ,
F_125 ( V_87 ) ) ;
}
struct V_24 * F_135 ( T_7 V_87 )
{
F_62 ( F_131 ( F_123 ( V_87 ) ) ) ;
F_62 ( ! F_113 ( F_133 ( V_87 ) ) ) ;
return F_12 ( F_133 ( V_87 ) -> V_168 ,
struct V_24 , V_117 ) ;
}
static struct V_82 * F_136 ( void )
{
struct V_82 * V_27 ;
int V_94 ;
F_137 ( V_27 , V_169 , V_99 ) ;
if ( V_27 == NULL )
return NULL ;
F_68 ( & V_27 -> V_149 ) ;
F_68 ( & V_27 -> V_150 ) ;
F_68 ( & V_27 -> V_151 ) ;
for ( V_94 = 0 ; V_94 < V_170 ; V_94 ++ ) {
V_27 -> V_171 [ V_94 ] . V_172 = 0 ;
V_27 -> V_171 [ V_94 ] . V_173 = 1 << V_94 ;
V_27 -> V_171 [ V_94 ] . V_174 = NULL ;
}
F_70 ( & V_27 -> V_153 , 1 ) ;
F_69 ( & V_27 -> V_175 ) ;
F_138 ( & V_27 -> V_176 ) ;
F_139 ( & V_27 -> V_177 ) ;
F_122 ( & V_27 -> V_177 ) ;
return V_27 ;
}
struct V_82 *
F_140 ( struct V_24 * V_25 , struct V_82 * V_178 ,
const struct V_64 * V_68 , T_10 type , int V_179 )
{
struct V_80 * V_81 ;
struct V_82 * V_27 ;
struct V_28 V_29 ;
T_5 V_180 ;
int V_181 = 0 ;
F_62 ( V_25 != NULL ) ;
F_62 ( V_178 == NULL ) ;
F_62 ( V_25 -> V_100 != NULL ) ;
F_62 ( V_68 -> V_68 [ 0 ] != 0 ) ;
F_141 ( V_25 -> V_100 , ( void * ) V_68 , & V_29 , 0 ) ;
V_81 = F_142 ( V_25 -> V_100 , & V_29 , ( void * ) V_68 ) ;
if ( V_81 != NULL ) {
F_143 ( V_25 -> V_100 , & V_29 , 0 ) ;
V_27 = F_51 ( V_81 , struct V_82 , V_83 ) ;
if ( V_25 -> V_182 && V_25 -> V_182 -> V_183 ) {
F_122 ( & V_27 -> V_177 ) ;
F_127 ( & V_27 -> V_177 ) ;
}
if ( F_144 ( V_27 -> V_184 < 0 ) ) {
F_60 ( V_27 ) ;
V_27 = NULL ;
}
return V_27 ;
}
V_180 = F_145 ( & V_29 ) ;
F_143 ( V_25 -> V_100 , & V_29 , 0 ) ;
if ( V_179 == 0 )
return NULL ;
F_146 ( type >= V_185 && type < V_186 ,
L_33 , type ) ;
V_27 = F_136 () ;
if ( ! V_27 )
return NULL ;
V_27 -> V_187 = F_66 ( V_25 -> V_100 , & V_29 ) ;
V_27 -> V_84 = * V_68 ;
V_27 -> V_188 = type ;
V_27 -> V_189 = V_190 ;
F_147 ( V_25 -> V_100 , & V_29 , 1 ) ;
V_81 = ( V_180 == F_145 ( & V_29 ) ) ? NULL :
F_142 ( V_25 -> V_100 , & V_29 , ( void * ) V_68 ) ;
if ( V_81 != NULL ) {
F_143 ( V_25 -> V_100 , & V_29 , 1 ) ;
F_148 ( & V_27 -> V_176 ) ;
F_127 ( & V_27 -> V_177 ) ;
F_149 ( V_27 , V_169 , sizeof( * V_27 ) ) ;
V_27 = F_51 ( V_81 , struct V_82 , V_83 ) ;
if ( V_25 -> V_182 && V_25 -> V_182 -> V_183 ) {
F_122 ( & V_27 -> V_177 ) ;
F_127 ( & V_27 -> V_177 ) ;
}
if ( F_144 ( V_27 -> V_184 < 0 ) ) {
F_60 ( V_27 ) ;
V_27 = NULL ;
}
return V_27 ;
}
F_150 ( V_25 -> V_100 , & V_29 , & V_27 -> V_83 ) ;
if ( F_14 ( & V_29 ) == 1 )
V_181 = F_117 ( V_25 ) ;
F_143 ( V_25 -> V_100 , & V_29 , 1 ) ;
if ( V_25 -> V_182 && V_25 -> V_182 -> V_183 ) {
int V_8 ;
F_151 ( V_191 , 2 ) ;
V_8 = V_25 -> V_182 -> V_183 ( V_27 ) ;
if ( V_8 < 0 ) {
F_6 ( L_34 ,
V_25 -> V_114 -> V_192 , V_68 -> V_68 [ 0 ] ,
V_68 -> V_68 [ 1 ] , V_8 ) ;
F_77 ( V_27 -> V_193 ) ;
V_27 -> V_193 = NULL ;
V_27 -> V_184 = V_8 ;
F_127 ( & V_27 -> V_177 ) ;
F_60 ( V_27 ) ;
return NULL ;
}
}
F_127 ( & V_27 -> V_177 ) ;
if ( F_80 ( V_25 ) && V_181 == 1 ) {
F_122 ( F_123 ( V_7 ) ) ;
F_130 ( V_25 , V_7 ) ;
F_127 ( F_123 ( V_7 ) ) ;
}
return V_27 ;
}
struct V_82 * F_56 ( struct V_82 * V_27 )
{
F_62 ( V_27 != NULL ) ;
F_62 ( V_27 != V_194 ) ;
F_116 ( & V_27 -> V_153 ) ;
F_21 ( V_155 , L_35 , V_27 ,
F_97 ( & V_27 -> V_153 ) ) ;
return V_27 ;
}
static void F_152 ( struct V_28 * V_29 ,
struct V_82 * V_27 )
{
struct V_90 * V_91 = V_27 -> V_187 ;
if ( ! F_113 ( & V_27 -> V_149 ) ) {
F_98 ( V_154 , V_27 ) ;
F_153 () ;
}
if ( ! F_113 ( & V_27 -> V_150 ) ) {
F_98 ( V_154 , V_27 ) ;
F_153 () ;
}
if ( ! F_113 ( & V_27 -> V_151 ) ) {
F_98 ( V_154 , V_27 ) ;
F_153 () ;
}
F_154 ( V_91 -> V_113 -> V_100 ,
V_29 , & V_27 -> V_83 ) ;
F_148 ( & V_27 -> V_176 ) ;
if ( F_14 ( V_29 ) == 0 )
F_119 ( V_91 -> V_113 ) ;
}
int F_60 ( struct V_82 * V_27 )
{
struct V_24 * V_25 = F_81 ( V_27 ) ;
struct V_28 V_29 ;
F_155 ( & V_27 -> V_153 , 0 , V_195 ) ;
F_21 ( V_155 , L_36 ,
V_27 , F_97 ( & V_27 -> V_153 ) - 1 ) ;
F_156 ( V_25 -> V_100 , & V_27 -> V_84 , & V_29 ) ;
if ( F_157 ( V_25 -> V_100 , & V_29 , & V_27 -> V_153 ) ) {
F_152 ( & V_29 , V_27 ) ;
F_143 ( V_25 -> V_100 , & V_29 , 1 ) ;
if ( V_25 -> V_182 && V_25 -> V_182 -> V_196 )
V_25 -> V_182 -> V_196 ( V_27 ) ;
F_149 ( V_27 , V_169 , sizeof( * V_27 ) ) ;
return 1 ;
}
return 0 ;
}
int F_58 ( struct V_82 * V_27 )
{
struct V_24 * V_25 = F_81 ( V_27 ) ;
F_155 ( & V_27 -> V_153 , 0 , V_195 ) ;
F_21 ( V_155 , L_36 ,
V_27 , F_97 ( & V_27 -> V_153 ) - 1 ) ;
if ( F_158 ( & V_27 -> V_153 ) ) {
struct V_28 V_29 ;
F_156 ( F_81 ( V_27 ) -> V_100 ,
& V_27 -> V_84 , & V_29 ) ;
F_152 ( & V_29 , V_27 ) ;
F_143 ( V_25 -> V_100 , & V_29 , 1 ) ;
if ( V_25 -> V_182 && V_25 -> V_182 -> V_196 )
V_25 -> V_182 -> V_196 ( V_27 ) ;
F_149 ( V_27 , V_169 , sizeof( * V_27 ) ) ;
F_147 ( V_25 -> V_100 , & V_29 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_159 ( struct V_82 * V_27 , struct V_131 * V_197 ,
struct V_136 * V_137 )
{
F_160 ( V_27 ) ;
F_87 ( V_137 , L_37 ) ;
if ( V_137 -> V_139 & V_198 ) {
F_21 ( V_199 , L_38 ) ;
return;
}
F_62 ( F_113 ( & V_137 -> V_138 ) ) ;
F_161 ( & V_137 -> V_138 , V_197 ) ;
}
void F_162 ( struct V_136 * V_200 ,
struct V_136 * V_201 )
{
struct V_82 * V_27 = V_200 -> V_202 ;
F_160 ( V_27 ) ;
F_98 ( V_155 , V_27 ) ;
F_87 ( V_201 , L_39 , V_200 ) ;
if ( V_201 -> V_139 & V_198 ) {
F_21 ( V_199 , L_38 ) ;
goto V_203;
}
F_62 ( F_113 ( & V_201 -> V_138 ) ) ;
F_124 ( & V_201 -> V_138 , & V_200 -> V_138 ) ;
V_203: ;
}
void F_91 ( struct V_136 * V_137 )
{
int type = V_137 -> V_202 -> V_188 ;
F_160 ( V_137 -> V_202 ) ;
if ( type == V_204 || type == V_205 )
F_163 ( V_137 ) ;
else if ( type == V_206 )
F_164 ( V_137 ) ;
F_128 ( & V_137 -> V_138 ) ;
}
void F_165 ( struct V_82 * V_27 , struct V_207 * V_208 )
{
V_208 -> V_188 = V_27 -> V_188 ;
V_208 -> V_84 = V_27 -> V_84 ;
}
void F_2 ( T_7 V_87 , int V_209 )
{
struct V_131 * V_38 ;
if ( ! ( ( V_210 | V_154 ) & V_209 ) )
return;
F_122 ( F_123 ( V_87 ) ) ;
F_83 (tmp, ldlm_namespace_list(client)) {
struct V_24 * V_25 ;
V_25 = F_84 ( V_38 , struct V_24 , V_117 ) ;
F_166 ( V_209 , V_25 ) ;
}
F_127 ( F_123 ( V_87 ) ) ;
}
static int F_167 ( struct V_60 * V_61 , struct V_28 * V_29 ,
struct V_80 * V_81 , void * V_148 )
{
struct V_82 * V_27 = F_94 ( V_61 , V_81 ) ;
int V_209 = ( int ) ( unsigned long ) V_148 ;
F_82 ( V_27 ) ;
F_98 ( V_209 , V_27 ) ;
F_86 ( V_27 ) ;
return 0 ;
}
void F_166 ( int V_209 , struct V_24 * V_25 )
{
if ( ! ( ( V_210 | V_154 ) & V_209 ) )
return;
F_21 ( V_209 , L_40 ,
F_22 ( V_25 ) , F_97 ( & V_25 -> V_120 ) ,
F_80 ( V_25 ) ? L_41 : L_42 ) ;
if ( F_168 ( F_169 () , V_25 -> V_211 ) )
return;
F_99 ( V_25 -> V_100 ,
F_167 ,
( void * ) ( unsigned long ) V_209 ) ;
F_106 ( & V_25 -> V_119 ) ;
V_25 -> V_211 = F_170 ( 10 ) ;
F_107 ( & V_25 -> V_119 ) ;
}
void F_98 ( int V_209 , struct V_82 * V_27 )
{
struct V_136 * V_137 ;
unsigned int V_212 = 0 ;
F_171 ( V_67 == 4 ) ;
if ( ! ( ( V_210 | V_154 ) & V_209 ) )
return;
F_21 ( V_209 , L_43 V_152 L_44 ,
F_96 ( V_27 ) , V_27 , F_97 ( & V_27 -> V_153 ) ) ;
if ( ! F_113 ( & V_27 -> V_149 ) ) {
F_21 ( V_209 , L_45 ) ;
F_172 (lock, &res->lr_granted,
l_res_link) {
F_173 ( V_209 , V_137 , L_46 ) ;
if ( ! ( V_209 & V_213 ) &&
++ V_212 > V_214 ) {
F_21 ( V_209 , L_47 ,
V_212 ) ;
break;
}
}
}
if ( ! F_113 ( & V_27 -> V_150 ) ) {
F_21 ( V_209 , L_48 ) ;
F_174 (lock, &res->lr_converting, l_res_link)
F_173 ( V_209 , V_137 , L_46 ) ;
}
if ( ! F_113 ( & V_27 -> V_151 ) ) {
F_21 ( V_209 , L_49 ) ;
F_174 (lock, &res->lr_waiting, l_res_link)
F_173 ( V_209 , V_137 , L_46 ) ;
}
}
