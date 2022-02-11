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
static void F_34 ( struct V_24 * V_25 )
{
F_35 ( & V_25 -> V_26 ) ;
F_36 ( & V_25 -> V_51 ) ;
}
static int F_37 ( struct V_24 * V_25 )
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
static struct V_60 * F_44 ( struct V_60 * V_27 )
{
F_45 ( V_27 ) ;
F_45 ( V_27 != V_61 ) ;
F_46 ( & V_27 -> V_62 ) ;
F_21 ( V_63 , L_18 , V_27 ,
F_47 ( & V_27 -> V_62 ) ) ;
return V_27 ;
}
static unsigned F_48 ( struct V_64 * V_65 ,
const void * V_66 , unsigned V_67 )
{
const struct V_68 * V_69 = V_66 ;
unsigned V_70 = 0 ;
unsigned V_30 ;
for ( V_30 = 0 ; V_30 < V_71 ; V_30 ++ )
V_70 += V_69 -> V_72 [ V_30 ] ;
return V_70 & V_67 ;
}
static unsigned F_49 ( struct V_64 * V_65 ,
const void * V_66 , unsigned V_67 )
{
const struct V_68 * V_69 = V_66 ;
struct V_73 V_74 ;
T_6 V_75 ;
T_6 V_70 ;
V_74 . V_76 = V_69 -> V_72 [ V_77 ] ;
V_74 . V_78 = ( T_6 ) V_69 -> V_72 [ V_79 ] ;
V_74 . V_80 = ( T_6 ) ( V_69 -> V_72 [ V_79 ] >> 32 ) ;
V_75 = F_50 ( & V_74 ) ;
V_75 += ( V_75 >> 4 ) + ( V_75 << 12 ) ;
if ( V_69 -> V_72 [ V_81 ] != 0 ) {
V_70 = V_69 -> V_72 [ V_81 ] ;
V_75 += ( V_70 >> 5 ) + ( V_70 << 11 ) ;
} else {
V_70 = F_51 ( & V_74 ) ;
}
V_75 = F_52 ( V_75 , V_65 -> V_82 ) ;
V_75 -= F_52 ( ( unsigned long ) V_65 , V_70 % 11 + 3 ) ;
V_75 <<= V_65 -> V_83 - V_65 -> V_82 ;
V_75 |= F_48 ( V_65 , V_66 , F_53 ( V_65 ) - 1 ) ;
return V_75 & V_67 ;
}
static void * F_54 ( struct V_84 * V_85 )
{
struct V_60 * V_27 ;
V_27 = F_55 ( V_85 , struct V_60 , V_86 ) ;
return & V_27 -> V_87 ;
}
static int F_56 ( const void * V_66 , struct V_84 * V_85 )
{
struct V_60 * V_27 ;
V_27 = F_55 ( V_85 , struct V_60 , V_86 ) ;
return F_57 ( ( const struct V_68 * ) V_66 ,
( const struct V_68 * ) & V_27 -> V_87 ) ;
}
static void * F_58 ( struct V_84 * V_85 )
{
return F_55 ( V_85 , struct V_60 , V_86 ) ;
}
static void F_59 ( struct V_64 * V_65 ,
struct V_84 * V_85 )
{
struct V_60 * V_27 ;
V_27 = F_55 ( V_85 , struct V_60 , V_86 ) ;
F_44 ( V_27 ) ;
}
static void F_60 ( struct V_64 * V_65 ,
struct V_84 * V_85 )
{
struct V_60 * V_27 ;
V_27 = F_55 ( V_85 , struct V_60 , V_86 ) ;
F_61 ( V_27 ) ;
}
static void F_62 ( struct V_64 * V_65 , struct V_84 * V_85 )
{
struct V_60 * V_27 ;
V_27 = F_55 ( V_85 , struct V_60 , V_86 ) ;
F_63 ( V_27 ) ;
}
static void F_64 ( struct V_24 * V_25 ,
T_7 V_88 )
{
F_65 ( F_66 ( V_88 ) ) ;
F_45 ( F_67 ( & V_25 -> V_89 ) ) ;
F_68 ( & V_25 -> V_89 , & V_90 ) ;
F_69 ( V_88 ) ;
F_70 ( F_66 ( V_88 ) ) ;
}
struct V_24 * F_71 ( struct V_91 * V_92 , char * V_72 ,
T_7 V_88 ,
T_8 V_93 ,
T_9 V_94 )
{
struct V_24 * V_25 = NULL ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_28 V_29 ;
int V_99 ;
int V_8 ;
F_45 ( V_92 != NULL ) ;
V_8 = F_72 () ;
if ( V_8 ) {
F_6 ( L_19 , V_8 ) ;
return NULL ;
}
for ( V_99 = 0 ; ; V_99 ++ ) {
V_98 = & V_100 [ V_99 ] ;
if ( V_98 -> V_101 == V_102 ) {
F_6 ( L_20 , V_94 , V_72 ) ;
goto V_103;
}
if ( V_98 -> V_101 == V_94 )
break;
}
V_25 = F_73 ( sizeof( * V_25 ) , V_104 ) ;
if ( ! V_25 )
goto V_103;
V_25 -> V_105 = F_74 ( V_72 ,
V_98 -> V_106 , V_98 -> V_106 ,
V_98 -> V_107 , sizeof( * V_96 ) ,
V_108 ,
V_109 ,
V_98 -> V_110 ,
V_111 |
V_112 |
V_113 |
V_114 ) ;
if ( V_25 -> V_105 == NULL )
goto V_115;
F_13 (ns->ns_rs_hash, &bd, idx) {
V_96 = F_75 ( V_25 -> V_105 , & V_29 ) ;
F_76 ( & V_96 -> V_116 , V_117 , 0 ) ;
V_96 -> V_118 = V_25 ;
}
V_25 -> V_119 = V_92 ;
V_25 -> V_120 = V_93 ;
V_25 -> V_121 = V_88 ;
F_77 ( & V_25 -> V_89 ) ;
F_77 ( & V_25 -> V_122 ) ;
F_78 ( & V_25 -> V_123 ) ;
F_79 ( & V_25 -> V_124 , 0 ) ;
F_80 ( & V_25 -> V_125 ) ;
V_25 -> V_126 = V_127 ;
V_25 -> V_35 = 0 ;
V_25 -> V_37 = V_128 ;
V_25 -> V_48 = V_129 ;
V_25 -> V_47 = 0 ;
V_25 -> V_45 = 0 ;
V_25 -> V_130 = 0 ;
V_8 = F_37 ( V_25 ) ;
if ( V_8 != 0 ) {
F_6 ( L_21 , V_8 ) ;
goto V_131;
}
V_8 = F_42 ( V_25 ) ;
if ( V_8 != 0 ) {
F_6 ( L_22 , V_8 ) ;
goto V_132;
}
V_99 = F_81 ( V_88 ) ;
V_8 = F_82 ( & V_25 -> V_133 , V_25 , V_99 , V_88 ) ;
if ( V_8 ) {
F_6 ( L_23 , V_8 ) ;
goto V_134;
}
F_64 ( V_25 , V_88 ) ;
return V_25 ;
V_134:
F_32 ( V_25 ) ;
V_132:
F_34 ( V_25 ) ;
F_83 ( V_25 , 0 ) ;
V_131:
F_84 ( V_25 -> V_105 ) ;
V_115:
F_85 ( V_25 ) ;
V_103:
F_86 () ;
return NULL ;
}
static void F_87 ( struct V_60 * V_27 , struct V_135 * V_136 ,
T_5 V_137 )
{
struct V_135 * V_38 ;
int V_8 = 0 ;
bool V_138 = ! ! ( V_137 & V_139 ) ;
do {
struct V_140 * V_141 = NULL ;
struct V_142 V_143 ;
F_88 ( V_27 ) ;
F_89 (tmp, q) {
V_141 = F_90 ( V_38 , struct V_140 ,
V_144 ) ;
if ( V_141 -> V_145 & V_146 ) {
V_141 = NULL ;
continue;
}
F_91 ( V_141 ) ;
V_141 -> V_145 |= V_146 ;
break;
}
if ( V_141 == NULL ) {
F_92 ( V_27 ) ;
break;
}
V_141 -> V_145 |= V_147 ;
V_141 -> V_145 |= V_148 ;
V_141 -> V_145 |= V_137 ;
if ( V_138 )
V_141 -> V_145 |= V_139 ;
if ( V_138 && ( V_141 -> V_149 || V_141 -> V_150 ) ) {
F_92 ( V_27 ) ;
F_93 ( V_141 , L_24 ) ;
if ( V_141 -> V_151 )
V_141 -> V_151 ( V_141 , 0 , NULL ) ;
F_94 ( V_141 ) ;
continue;
}
F_92 ( V_27 ) ;
F_95 ( V_141 , & V_143 ) ;
V_8 = F_96 ( & V_143 , V_44 ) ;
if ( V_8 )
F_6 ( L_25 , V_8 ) ;
F_94 ( V_141 ) ;
} while ( 1 );
}
static int F_97 ( struct V_64 * V_65 , struct V_28 * V_29 ,
struct V_84 * V_85 , void * V_152 )
{
struct V_60 * V_27 = F_98 ( V_65 , V_85 ) ;
T_5 V_137 = * ( T_5 * ) V_152 ;
F_87 ( V_27 , & V_27 -> V_153 , V_137 ) ;
F_87 ( V_27 , & V_27 -> V_154 , V_137 ) ;
return 0 ;
}
static int F_99 ( struct V_64 * V_65 , struct V_28 * V_29 ,
struct V_84 * V_85 , void * V_152 )
{
struct V_60 * V_27 = F_98 ( V_65 , V_85 ) ;
F_88 ( V_27 ) ;
F_6 ( L_26 V_155
L_27 ,
F_22 ( F_100 ( V_27 ) ) , F_101 ( V_27 ) , V_27 ,
F_47 ( & V_27 -> V_62 ) - 1 ) ;
F_102 ( V_156 , V_27 ) ;
F_92 ( V_27 ) ;
return 0 ;
}
int F_83 ( struct V_24 * V_25 , T_5 V_137 )
{
if ( V_25 == NULL ) {
F_21 ( V_63 , L_28 ) ;
return V_157 ;
}
F_103 ( V_25 -> V_105 , F_97 , & V_137 ) ;
F_103 ( V_25 -> V_105 , F_99 , NULL ) ;
return V_157 ;
}
static int F_104 ( struct V_24 * V_25 , int V_158 )
{
F_83 ( V_25 , V_158 ? V_139 : 0 ) ;
if ( F_47 ( & V_25 -> V_124 ) > 0 ) {
struct V_159 V_160 = F_105 ( V_161 , NULL ) ;
int V_8 ;
F_21 ( V_6 ,
L_29 ,
F_22 ( V_25 ) , F_47 ( & V_25 -> V_124 ) ) ;
V_162:
if ( V_158 )
V_160 = F_106 ( V_163 * V_164 / 4 , NULL , NULL ) ;
V_8 = F_107 ( V_25 -> V_125 ,
F_47 ( & V_25 -> V_124 ) == 0 , & V_160 ) ;
if ( V_158 && V_8 == - V_165 ) {
F_108 ( L_30 ,
F_22 ( V_25 ) ,
F_47 ( & V_25 -> V_124 ) , V_8 ) ;
goto V_162;
}
if ( F_47 ( & V_25 -> V_124 ) ) {
F_108 ( L_31 ,
F_22 ( V_25 ) ,
F_47 ( & V_25 -> V_124 ) , V_8 ) ;
return V_166 ;
}
F_21 ( V_6 , L_32 ,
F_22 ( V_25 ) ) ;
}
return V_157 ;
}
void F_109 ( struct V_24 * V_25 ,
struct V_167 * V_168 ,
int V_158 )
{
int V_8 ;
if ( ! V_25 )
return;
F_110 ( & V_25 -> V_123 ) ;
V_25 -> V_130 = 1 ;
F_111 ( & V_25 -> V_123 ) ;
V_8 = F_104 ( V_25 , V_158 ) ;
if ( V_8 != V_157 ) {
if ( V_168 ) {
F_112 ( V_168 , 0 ) ;
F_113 ( V_168 ) ;
}
V_8 = F_104 ( V_25 , 1 ) ;
F_45 ( V_8 == 0 ) ;
}
}
static void F_114 ( struct V_24 * V_25 ,
T_7 V_88 )
{
F_65 ( F_66 ( V_88 ) ) ;
F_45 ( ! F_67 ( & V_25 -> V_89 ) ) ;
F_115 ( & V_25 -> V_89 ) ;
F_116 ( V_88 ) ;
F_70 ( F_66 ( V_88 ) ) ;
}
void F_117 ( struct V_24 * V_25 )
{
if ( ! V_25 )
return;
F_114 ( V_25 , V_25 -> V_121 ) ;
F_118 ( & V_25 -> V_133 ) ;
F_32 ( V_25 ) ;
F_34 ( V_25 ) ;
F_84 ( V_25 -> V_105 ) ;
F_45 ( F_67 ( & V_25 -> V_89 ) ) ;
F_85 ( V_25 ) ;
F_86 () ;
}
void F_119 ( struct V_24 * V_25 )
{
F_46 ( & V_25 -> V_124 ) ;
}
static int F_120 ( struct V_24 * V_25 )
{
return F_121 ( & V_25 -> V_124 ) ;
}
void F_122 ( struct V_24 * V_25 )
{
if ( F_123 ( & V_25 -> V_124 , & V_25 -> V_123 ) ) {
F_124 ( & V_25 -> V_125 ) ;
F_111 ( & V_25 -> V_123 ) ;
}
}
void F_125 ( struct V_24 * V_25 ,
T_7 V_88 )
{
F_45 ( ! F_67 ( & V_25 -> V_89 ) ) ;
F_45 ( F_126 ( F_66 ( V_88 ) ) ) ;
F_127 ( & V_25 -> V_89 , F_128 ( V_88 ) ) ;
}
void F_129 ( struct V_24 * V_25 ,
T_7 V_88 )
{
F_45 ( ! F_67 ( & V_25 -> V_89 ) ) ;
F_45 ( F_126 ( F_66 ( V_88 ) ) ) ;
F_127 ( & V_25 -> V_89 , & V_90 ) ;
}
struct V_24 * F_130 ( T_7 V_88 )
{
F_45 ( F_126 ( F_66 ( V_88 ) ) ) ;
F_45 ( ! F_67 ( F_128 ( V_88 ) ) ) ;
return F_12 ( F_128 ( V_88 ) -> V_169 ,
struct V_24 , V_89 ) ;
}
static struct V_60 * F_131 ( void )
{
struct V_60 * V_27 ;
int V_99 ;
V_27 = F_132 ( V_170 , V_104 | V_171 ) ;
if ( V_27 == NULL )
return NULL ;
F_77 ( & V_27 -> V_153 ) ;
F_77 ( & V_27 -> V_154 ) ;
for ( V_99 = 0 ; V_99 < V_172 ; V_99 ++ ) {
V_27 -> V_173 [ V_99 ] . V_174 = 0 ;
V_27 -> V_173 [ V_99 ] . V_175 = 1 << V_99 ;
V_27 -> V_173 [ V_99 ] . V_176 = NULL ;
}
F_79 ( & V_27 -> V_62 , 1 ) ;
F_78 ( & V_27 -> V_177 ) ;
F_133 ( & V_27 -> V_178 ) ;
F_134 ( & V_27 -> V_179 ) ;
F_65 ( & V_27 -> V_179 ) ;
return V_27 ;
}
struct V_60 *
F_135 ( struct V_24 * V_25 , struct V_60 * V_180 ,
const struct V_68 * V_72 , T_10 type , int V_181 )
{
struct V_84 * V_85 ;
struct V_60 * V_27 ;
struct V_28 V_29 ;
T_5 V_182 ;
int V_183 = 0 ;
F_45 ( V_25 != NULL ) ;
F_45 ( V_180 == NULL ) ;
F_45 ( V_25 -> V_105 != NULL ) ;
F_45 ( V_72 -> V_72 [ 0 ] != 0 ) ;
F_136 ( V_25 -> V_105 , ( void * ) V_72 , & V_29 , 0 ) ;
V_85 = F_137 ( V_25 -> V_105 , & V_29 , ( void * ) V_72 ) ;
if ( V_85 != NULL ) {
F_138 ( V_25 -> V_105 , & V_29 , 0 ) ;
V_27 = F_55 ( V_85 , struct V_60 , V_86 ) ;
if ( V_25 -> V_184 && V_25 -> V_184 -> V_185 ) {
F_65 ( & V_27 -> V_179 ) ;
F_70 ( & V_27 -> V_179 ) ;
}
if ( F_139 ( V_27 -> V_186 < 0 ) ) {
F_63 ( V_27 ) ;
V_27 = NULL ;
}
return V_27 ;
}
V_182 = F_140 ( & V_29 ) ;
F_138 ( V_25 -> V_105 , & V_29 , 0 ) ;
if ( V_181 == 0 )
return NULL ;
F_141 ( type >= V_187 && type < V_188 ,
L_33 , type ) ;
V_27 = F_131 () ;
if ( ! V_27 )
return NULL ;
V_27 -> V_189 = F_75 ( V_25 -> V_105 , & V_29 ) ;
V_27 -> V_87 = * V_72 ;
V_27 -> V_190 = type ;
V_27 -> V_191 = V_192 ;
F_142 ( V_25 -> V_105 , & V_29 , 1 ) ;
V_85 = ( V_182 == F_140 ( & V_29 ) ) ? NULL :
F_137 ( V_25 -> V_105 , & V_29 , ( void * ) V_72 ) ;
if ( V_85 != NULL ) {
F_138 ( V_25 -> V_105 , & V_29 , 1 ) ;
F_143 ( & V_27 -> V_178 ) ;
F_70 ( & V_27 -> V_179 ) ;
F_144 ( V_170 , V_27 ) ;
V_27 = F_55 ( V_85 , struct V_60 , V_86 ) ;
if ( V_25 -> V_184 && V_25 -> V_184 -> V_185 ) {
F_65 ( & V_27 -> V_179 ) ;
F_70 ( & V_27 -> V_179 ) ;
}
if ( F_139 ( V_27 -> V_186 < 0 ) ) {
F_63 ( V_27 ) ;
V_27 = NULL ;
}
return V_27 ;
}
F_145 ( V_25 -> V_105 , & V_29 , & V_27 -> V_86 ) ;
if ( F_14 ( & V_29 ) == 1 )
V_183 = F_120 ( V_25 ) ;
F_138 ( V_25 -> V_105 , & V_29 , 1 ) ;
if ( V_25 -> V_184 && V_25 -> V_184 -> V_185 ) {
int V_8 ;
F_146 ( V_193 , 2 ) ;
V_8 = V_25 -> V_184 -> V_185 ( V_27 ) ;
if ( V_8 < 0 ) {
F_6 ( L_34 ,
V_25 -> V_119 -> V_194 , V_72 -> V_72 [ 0 ] ,
V_72 -> V_72 [ 1 ] , V_8 ) ;
V_27 -> V_186 = V_8 ;
F_70 ( & V_27 -> V_179 ) ;
F_63 ( V_27 ) ;
return NULL ;
}
}
F_70 ( & V_27 -> V_179 ) ;
if ( V_183 == 1 ) {
F_65 ( F_66 ( V_7 ) ) ;
F_125 ( V_25 , V_7 ) ;
F_70 ( F_66 ( V_7 ) ) ;
}
return V_27 ;
}
static void F_147 ( struct V_28 * V_29 ,
struct V_60 * V_27 )
{
struct V_95 * V_96 = V_27 -> V_189 ;
if ( ! F_67 ( & V_27 -> V_153 ) ) {
F_102 ( V_156 , V_27 ) ;
F_148 () ;
}
if ( ! F_67 ( & V_27 -> V_154 ) ) {
F_102 ( V_156 , V_27 ) ;
F_148 () ;
}
F_149 ( V_96 -> V_118 -> V_105 ,
V_29 , & V_27 -> V_86 ) ;
F_143 ( & V_27 -> V_178 ) ;
if ( F_14 ( V_29 ) == 0 )
F_122 ( V_96 -> V_118 ) ;
}
int F_63 ( struct V_60 * V_27 )
{
struct V_24 * V_25 = F_100 ( V_27 ) ;
struct V_28 V_29 ;
F_150 ( & V_27 -> V_62 , 0 , V_195 ) ;
F_21 ( V_63 , L_35 ,
V_27 , F_47 ( & V_27 -> V_62 ) - 1 ) ;
F_151 ( V_25 -> V_105 , & V_27 -> V_87 , & V_29 ) ;
if ( F_152 ( V_25 -> V_105 , & V_29 , & V_27 -> V_62 ) ) {
F_147 ( & V_29 , V_27 ) ;
F_138 ( V_25 -> V_105 , & V_29 , 1 ) ;
if ( V_25 -> V_184 && V_25 -> V_184 -> V_196 )
V_25 -> V_184 -> V_196 ( V_27 ) ;
F_144 ( V_170 , V_27 ) ;
return 1 ;
}
return 0 ;
}
int F_61 ( struct V_60 * V_27 )
{
struct V_24 * V_25 = F_100 ( V_27 ) ;
F_150 ( & V_27 -> V_62 , 0 , V_195 ) ;
F_21 ( V_63 , L_35 ,
V_27 , F_47 ( & V_27 -> V_62 ) - 1 ) ;
if ( F_153 ( & V_27 -> V_62 ) ) {
struct V_28 V_29 ;
F_151 ( F_100 ( V_27 ) -> V_105 ,
& V_27 -> V_87 , & V_29 ) ;
F_147 ( & V_29 , V_27 ) ;
F_138 ( V_25 -> V_105 , & V_29 , 1 ) ;
if ( V_25 -> V_184 && V_25 -> V_184 -> V_196 )
V_25 -> V_184 -> V_196 ( V_27 ) ;
F_144 ( V_170 , V_27 ) ;
F_142 ( V_25 -> V_105 , & V_29 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_154 ( struct V_60 * V_27 , struct V_135 * V_197 ,
struct V_140 * V_141 )
{
F_155 ( V_27 ) ;
F_93 ( V_141 , L_36 ) ;
if ( V_141 -> V_145 & V_198 ) {
F_21 ( V_199 , L_37 ) ;
return;
}
F_45 ( F_67 ( & V_141 -> V_144 ) ) ;
F_156 ( & V_141 -> V_144 , V_197 ) ;
}
void F_157 ( struct V_140 * V_141 )
{
int type = V_141 -> V_200 -> V_190 ;
F_155 ( V_141 -> V_200 ) ;
if ( type == V_201 || type == V_202 )
F_158 ( V_141 ) ;
else if ( type == V_203 )
F_159 ( V_141 ) ;
F_115 ( & V_141 -> V_144 ) ;
}
void F_160 ( struct V_60 * V_27 , struct V_204 * V_205 )
{
V_205 -> V_190 = V_27 -> V_190 ;
V_205 -> V_87 = V_27 -> V_87 ;
}
void F_2 ( T_7 V_88 , int V_206 )
{
struct V_135 * V_38 ;
if ( ! ( ( V_207 | V_156 ) & V_206 ) )
return;
F_65 ( F_66 ( V_88 ) ) ;
F_89 (tmp, ldlm_namespace_list(client)) {
struct V_24 * V_25 ;
V_25 = F_90 ( V_38 , struct V_24 , V_89 ) ;
F_161 ( V_206 , V_25 ) ;
}
F_70 ( F_66 ( V_88 ) ) ;
}
static int F_162 ( struct V_64 * V_65 , struct V_28 * V_29 ,
struct V_84 * V_85 , void * V_152 )
{
struct V_60 * V_27 = F_98 ( V_65 , V_85 ) ;
int V_206 = ( int ) ( unsigned long ) V_152 ;
F_88 ( V_27 ) ;
F_102 ( V_206 , V_27 ) ;
F_92 ( V_27 ) ;
return 0 ;
}
void F_161 ( int V_206 , struct V_24 * V_25 )
{
if ( ! ( ( V_207 | V_156 ) & V_206 ) )
return;
F_21 ( V_206 , L_38 ,
F_22 ( V_25 ) , F_47 ( & V_25 -> V_124 ) ) ;
if ( F_163 ( F_164 () , V_25 -> V_208 ) )
return;
F_103 ( V_25 -> V_105 ,
F_162 ,
( void * ) ( unsigned long ) V_206 ) ;
F_110 ( & V_25 -> V_123 ) ;
V_25 -> V_208 = F_165 ( 10 ) ;
F_111 ( & V_25 -> V_123 ) ;
}
void F_102 ( int V_206 , struct V_60 * V_27 )
{
struct V_140 * V_141 ;
unsigned int V_209 = 0 ;
F_166 ( V_71 == 4 ) ;
if ( ! ( ( V_207 | V_156 ) & V_206 ) )
return;
F_21 ( V_206 , L_39 V_155 L_40 ,
F_101 ( V_27 ) , V_27 , F_47 ( & V_27 -> V_62 ) ) ;
if ( ! F_67 ( & V_27 -> V_153 ) ) {
F_21 ( V_206 , L_41 ) ;
F_167 (lock, &res->lr_granted,
l_res_link) {
F_168 ( V_206 , V_141 , L_42 ) ;
if ( ! ( V_206 & V_210 ) &&
++ V_209 > V_211 ) {
F_21 ( V_206 , L_43 ,
V_209 ) ;
break;
}
}
}
if ( ! F_67 ( & V_27 -> V_154 ) ) {
F_21 ( V_206 , L_44 ) ;
F_169 (lock, &res->lr_waiting, l_res_link)
F_168 ( V_206 , V_141 , L_42 ) ;
}
}
