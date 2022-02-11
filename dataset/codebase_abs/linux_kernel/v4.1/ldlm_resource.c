static T_1 F_1 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
F_2 ( V_5 , V_6 ) ;
F_2 ( V_7 , V_6 ) ;
return V_3 ;
}
int F_3 ( void )
{
int V_8 ;
struct V_9 V_10 [] = {
{ L_1 , & V_11 , NULL , 0222 } ,
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
goto V_19;
}
V_15 = F_5 ( L_5 ,
V_16 ,
NULL , NULL ) ;
if ( F_6 ( V_15 ) ) {
F_7 ( L_4 ) ;
V_8 = F_8 ( V_15 ) ;
goto V_20;
}
V_21 = F_5 ( L_6 ,
V_16 ,
NULL , NULL ) ;
if ( F_6 ( V_21 ) ) {
F_7 ( L_4 ) ;
V_8 = F_8 ( V_21 ) ;
goto V_22;
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
T_5 V_29 = 0 ;
struct V_30 V_31 ;
int V_32 ;
F_13 (ns->ns_rs_hash, &bd, i)
V_29 += F_14 ( & V_31 ) ;
return F_15 ( V_24 , & V_29 ) ;
}
static int F_16 ( struct V_23 * V_24 , void * V_25 )
{
struct V_26 * V_27 = V_24 -> V_28 ;
T_5 V_33 ;
V_33 = F_17 ( V_27 -> V_34 , V_35 ,
V_36 ) ;
return F_15 ( V_24 , & V_33 ) ;
}
static int F_18 ( struct V_23 * V_24 , void * V_25 )
{
struct V_26 * V_27 = V_24 -> V_28 ;
T_6 * V_37 = & V_27 -> V_38 ;
if ( F_19 ( V_27 ) )
V_37 = & V_27 -> V_39 ;
return F_20 ( V_24 , V_37 ) ;
}
static T_1 F_21 ( struct V_1 * V_1 ,
const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_26 * V_27 = ( (struct V_23 * ) V_1 -> V_40 ) -> V_28 ;
char V_41 [ V_42 + 1 ] ;
unsigned long V_43 ;
int V_44 ;
int V_19 ;
V_41 [ V_42 ] = '\0' ;
if ( F_22 ( V_41 , V_2 , V_42 ) )
return - V_45 ;
if ( strncmp ( V_41 , L_7 , 5 ) == 0 ) {
F_23 ( V_6 ,
L_8 ,
F_24 ( V_27 ) ) ;
if ( F_19 ( V_27 ) ) {
int V_46 , V_47 = V_27 -> V_39 ;
V_46 = F_25 ( V_27 , V_47 , 0 ,
V_48 ) ;
if ( V_46 < V_47 ) {
F_23 ( V_6 ,
L_9 ,
V_47 ,
V_46 ) ;
return - V_49 ;
}
} else {
V_43 = V_27 -> V_38 ;
V_27 -> V_38 = 0 ;
F_25 ( V_27 , 0 , 0 , V_48 ) ;
V_27 -> V_38 = V_43 ;
}
return V_3 ;
}
V_19 = F_26 ( V_41 , 10 , & V_43 ) ;
if ( V_19 != 0 ) {
F_7 ( L_10 ) ;
return - V_49 ;
}
V_44 = ( V_43 == 0 ) ;
if ( F_19 ( V_27 ) ) {
if ( ! V_44 )
V_27 -> V_38 = ( unsigned int ) V_43 ;
if ( V_43 > V_27 -> V_39 )
V_43 = V_27 -> V_39 ;
V_43 = V_27 -> V_39 - V_43 ;
F_23 ( V_6 ,
L_11 ,
F_24 ( V_27 ) , V_27 -> V_39 ,
( unsigned int ) V_43 ) ;
F_25 ( V_27 , V_43 , V_50 , V_48 ) ;
if ( ! V_44 ) {
F_23 ( V_6 ,
L_12 ,
F_24 ( V_27 ) ) ;
V_27 -> V_51 &= ~ V_52 ;
}
} else {
F_23 ( V_6 ,
L_13 ,
F_24 ( V_27 ) , V_27 -> V_38 ,
( unsigned int ) V_43 ) ;
V_27 -> V_38 = ( unsigned int ) V_43 ;
F_25 ( V_27 , 0 , V_50 , V_48 ) ;
if ( V_44 &&
( V_27 -> V_53 & V_52 ) ) {
F_23 ( V_6 ,
L_14 ,
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
static T_1 F_29 ( struct V_1 * V_1 ,
const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_26 * V_27 = ( (struct V_23 * ) V_1 -> V_40 ) -> V_28 ;
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
F_7 ( L_15 ,
F_24 ( V_27 ) ) ;
else
F_10 ( & V_27 -> V_56 ) ;
if ( V_27 -> V_34 != NULL )
F_32 ( & V_27 -> V_34 ) ;
}
int F_33 ( struct V_26 * V_27 )
{
struct V_9 V_57 [ 2 ] ;
char V_58 [ V_42 + 1 ] ;
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
V_27 -> V_34 = F_35 ( V_63 , 0 ) ;
if ( V_27 -> V_34 == NULL )
return - V_62 ;
F_36 ( V_27 -> V_34 , V_35 ,
V_64 , L_16 , L_16 ) ;
V_58 [ V_42 ] = '\0' ;
memset ( V_57 , 0 , sizeof( V_57 ) ) ;
V_57 [ 0 ] . V_65 = V_58 ;
F_37 ( L_17 , V_27 , & V_66 ) ;
F_37 ( L_18 , V_27 , & V_67 ) ;
if ( F_38 ( V_27 ) ) {
F_37 ( L_19 , & V_27 -> V_39 ,
& V_68 ) ;
F_37 ( L_20 , V_27 , & V_69 ) ;
F_37 ( L_21 , & V_27 -> V_70 ,
& V_12 ) ;
F_37 ( L_22 , V_27 , & V_71 ) ;
} else {
F_37 ( L_23 , & V_27 -> V_72 ,
& V_12 ) ;
F_37 ( L_24 , & V_27 -> V_73 ,
& V_68 ) ;
F_37 ( L_25 , & V_27 -> V_74 ,
& V_12 ) ;
F_37 ( L_26 , & V_27 -> V_75 ,
& V_12 ) ;
F_37 ( L_27 , & V_27 -> V_76 ,
& V_12 ) ;
F_37 ( L_28 , & V_27 -> V_77 ,
& V_12 ) ;
}
return 0 ;
}
static unsigned F_39 ( struct V_78 * V_79 ,
const void * V_80 , unsigned V_81 )
{
const struct V_82 * V_83 = V_80 ;
unsigned V_84 = 0 ;
unsigned V_32 ;
for ( V_32 = 0 ; V_32 < V_85 ; V_32 ++ )
V_84 += V_83 -> V_65 [ V_32 ] ;
return V_84 & V_81 ;
}
static unsigned F_40 ( struct V_78 * V_79 ,
const void * V_80 , unsigned V_81 )
{
const struct V_82 * V_83 = V_80 ;
struct V_86 V_87 ;
T_6 V_88 ;
T_6 V_84 ;
V_87 . V_89 = V_83 -> V_65 [ V_90 ] ;
V_87 . V_91 = ( T_6 ) V_83 -> V_65 [ V_92 ] ;
V_87 . V_93 = ( T_6 ) ( V_83 -> V_65 [ V_92 ] >> 32 ) ;
V_88 = F_41 ( & V_87 ) ;
V_88 += ( V_88 >> 4 ) + ( V_88 << 12 ) ;
if ( V_83 -> V_65 [ V_94 ] != 0 ) {
V_84 = V_83 -> V_65 [ V_94 ] ;
V_88 += ( V_84 >> 5 ) + ( V_84 << 11 ) ;
} else {
V_84 = F_42 ( & V_87 ) ;
}
V_88 = F_43 ( V_88 , V_79 -> V_95 ) ;
V_88 -= F_43 ( ( unsigned long ) V_79 , V_84 % 11 + 3 ) ;
V_88 <<= V_79 -> V_96 - V_79 -> V_95 ;
V_88 |= F_39 ( V_79 , V_80 , F_44 ( V_79 ) - 1 ) ;
return V_88 & V_81 ;
}
static void * F_45 ( struct V_97 * V_98 )
{
struct V_99 * V_29 ;
V_29 = F_46 ( V_98 , struct V_99 , V_100 ) ;
return & V_29 -> V_101 ;
}
static int F_47 ( const void * V_80 , struct V_97 * V_98 )
{
struct V_99 * V_29 ;
V_29 = F_46 ( V_98 , struct V_99 , V_100 ) ;
return F_48 ( ( const struct V_82 * ) V_80 ,
( const struct V_82 * ) & V_29 -> V_101 ) ;
}
static void * F_49 ( struct V_97 * V_98 )
{
return F_46 ( V_98 , struct V_99 , V_100 ) ;
}
static void F_50 ( struct V_78 * V_79 ,
struct V_97 * V_98 )
{
struct V_99 * V_29 ;
V_29 = F_46 ( V_98 , struct V_99 , V_100 ) ;
F_51 ( V_29 ) ;
}
static void F_52 ( struct V_78 * V_79 ,
struct V_97 * V_98 )
{
struct V_99 * V_29 ;
V_29 = F_46 ( V_98 , struct V_99 , V_100 ) ;
F_53 ( V_29 ) ;
}
static void F_54 ( struct V_78 * V_79 , struct V_97 * V_98 )
{
struct V_99 * V_29 ;
V_29 = F_46 ( V_98 , struct V_99 , V_100 ) ;
F_55 ( V_29 ) ;
}
struct V_26 * F_56 ( struct V_102 * V_103 , char * V_65 ,
T_7 V_104 ,
T_8 V_105 ,
T_9 V_106 )
{
struct V_26 * V_27 = NULL ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_30 V_31 ;
int V_111 ;
int V_8 ;
F_4 ( V_103 != NULL ) ;
V_8 = F_57 () ;
if ( V_8 ) {
F_7 ( L_29 , V_8 ) ;
return NULL ;
}
for ( V_111 = 0 ; ; V_111 ++ ) {
V_110 = & V_112 [ V_111 ] ;
if ( V_110 -> V_113 == V_114 ) {
F_7 ( L_30 , V_106 , V_65 ) ;
goto V_115;
}
if ( V_110 -> V_113 == V_106 )
break;
}
F_58 ( V_27 ) ;
if ( ! V_27 )
goto V_115;
V_27 -> V_61 = F_59 ( V_65 ,
V_110 -> V_116 , V_110 -> V_116 ,
V_110 -> V_117 , sizeof( * V_108 ) ,
V_118 ,
V_119 ,
V_110 -> V_120 ,
V_121 |
V_122 |
V_123 |
V_124 ) ;
if ( V_27 -> V_61 == NULL )
goto V_125;
F_13 (ns->ns_rs_hash, &bd, idx) {
V_108 = F_60 ( V_27 -> V_61 , & V_31 ) ;
F_61 ( & V_108 -> V_126 , V_127 , 0 ) ;
V_108 -> V_128 = V_27 ;
}
V_27 -> V_129 = V_103 ;
V_27 -> V_130 = V_105 ;
V_27 -> V_131 = V_104 ;
F_62 ( & V_27 -> V_132 ) ;
F_62 ( & V_27 -> V_133 ) ;
F_63 ( & V_27 -> V_134 ) ;
F_64 ( & V_27 -> V_135 , 0 ) ;
F_65 ( & V_27 -> V_136 ) ;
V_27 -> V_74 = V_137 ;
V_27 -> V_75 = V_138 ;
V_27 -> V_76 = V_139 ;
V_27 -> V_77 = V_140 ;
V_27 -> V_39 = 0 ;
V_27 -> V_38 = V_141 ;
V_27 -> V_70 = V_142 ;
V_27 -> V_72 = V_143 ;
V_27 -> V_73 = 0 ;
V_27 -> V_53 = 0 ;
V_27 -> V_51 = 0 ;
V_27 -> V_144 = 0 ;
V_8 = F_33 ( V_27 ) ;
if ( V_8 != 0 ) {
F_7 ( L_31 , V_8 ) ;
goto V_145;
}
V_111 = F_66 ( V_104 ) ;
V_8 = F_67 ( & V_27 -> V_146 , V_27 , V_111 , V_104 ) ;
if ( V_8 ) {
F_7 ( L_32 , V_8 ) ;
goto V_147;
}
F_68 ( V_27 , V_104 ) ;
return V_27 ;
V_147:
F_31 ( V_27 ) ;
F_69 ( V_27 , 0 ) ;
V_145:
F_70 ( V_27 -> V_61 ) ;
V_125:
F_71 ( V_27 ) ;
V_115:
F_72 () ;
return NULL ;
}
static void F_73 ( struct V_99 * V_29 , struct V_148 * V_149 ,
T_5 V_150 )
{
struct V_148 * V_43 ;
int V_8 = 0 , V_104 = F_38 ( F_74 ( V_29 ) ) ;
bool V_151 = ! ! ( V_150 & V_152 ) ;
do {
struct V_153 * V_154 = NULL ;
F_75 ( V_29 ) ;
F_76 (tmp, q) {
V_154 = F_77 ( V_43 , struct V_153 ,
V_155 ) ;
if ( V_154 -> V_156 & V_157 ) {
V_154 = NULL ;
continue;
}
F_78 ( V_154 ) ;
V_154 -> V_156 |= V_157 ;
break;
}
if ( V_154 == NULL ) {
F_79 ( V_29 ) ;
break;
}
V_154 -> V_156 |= V_158 ;
V_154 -> V_156 |= V_159 ;
V_154 -> V_156 |= V_150 ;
if ( V_151 )
V_154 -> V_156 |= V_152 ;
if ( V_151 && ( V_154 -> V_160 || V_154 -> V_161 ) ) {
F_79 ( V_29 ) ;
F_80 ( V_154 , L_33 ) ;
if ( V_154 -> V_162 )
V_154 -> V_162 ( V_154 , 0 , NULL ) ;
F_81 ( V_154 ) ;
continue;
}
if ( V_104 ) {
struct V_163 V_164 ;
F_79 ( V_29 ) ;
F_82 ( V_154 , & V_164 ) ;
V_8 = F_83 ( & V_164 , V_50 ) ;
if ( V_8 )
F_7 ( L_34 , V_8 ) ;
} else {
F_84 ( V_154 ) ;
F_79 ( V_29 ) ;
F_80 ( V_154 , L_35 ) ;
F_85 ( V_154 ) ;
}
F_81 ( V_154 ) ;
} while ( 1 );
}
static int F_86 ( struct V_78 * V_79 , struct V_30 * V_31 ,
struct V_97 * V_98 , void * V_165 )
{
struct V_99 * V_29 = F_87 ( V_79 , V_98 ) ;
T_5 V_150 = * ( T_5 * ) V_165 ;
F_73 ( V_29 , & V_29 -> V_166 , V_150 ) ;
F_73 ( V_29 , & V_29 -> V_167 , V_150 ) ;
F_73 ( V_29 , & V_29 -> V_168 , V_150 ) ;
return 0 ;
}
static int F_88 ( struct V_78 * V_79 , struct V_30 * V_31 ,
struct V_97 * V_98 , void * V_165 )
{
struct V_99 * V_29 = F_87 ( V_79 , V_98 ) ;
F_75 ( V_29 ) ;
F_7 ( L_36 V_169
L_37 ,
F_24 ( F_74 ( V_29 ) ) , F_89 ( V_29 ) , V_29 ,
F_90 ( & V_29 -> V_170 ) - 1 ) ;
F_91 ( V_171 , V_29 ) ;
F_79 ( V_29 ) ;
return 0 ;
}
int F_69 ( struct V_26 * V_27 , T_5 V_150 )
{
if ( V_27 == NULL ) {
F_23 ( V_172 , L_38 ) ;
return V_173 ;
}
F_92 ( V_27 -> V_61 , F_86 , & V_150 ) ;
F_92 ( V_27 -> V_61 , F_88 , NULL ) ;
return V_173 ;
}
static int F_93 ( struct V_26 * V_27 , int V_174 )
{
F_69 ( V_27 , V_174 ? V_152 : 0 ) ;
if ( F_90 ( & V_27 -> V_135 ) > 0 ) {
struct V_175 V_176 = F_94 ( V_177 , NULL ) ;
int V_8 ;
F_23 ( V_6 ,
L_39 ,
F_24 ( V_27 ) , F_90 ( & V_27 -> V_135 ) ) ;
V_178:
if ( V_174 )
V_176 = F_95 ( V_179 * V_180 / 4 , NULL , NULL ) ;
V_8 = F_96 ( V_27 -> V_136 ,
F_90 ( & V_27 -> V_135 ) == 0 , & V_176 ) ;
if ( V_174 && V_8 == - V_181 ) {
F_97 ( L_40 ,
F_24 ( V_27 ) ,
F_90 ( & V_27 -> V_135 ) , V_8 ) ;
goto V_178;
}
if ( F_90 ( & V_27 -> V_135 ) ) {
F_97 ( L_41 ,
F_24 ( V_27 ) ,
F_90 ( & V_27 -> V_135 ) , V_8 ) ;
return V_182 ;
}
F_23 ( V_6 , L_42 ,
F_24 ( V_27 ) ) ;
}
return V_173 ;
}
void F_98 ( struct V_26 * V_27 ,
struct V_183 * V_184 ,
int V_174 )
{
int V_8 ;
if ( ! V_27 )
return;
F_99 ( & V_27 -> V_134 ) ;
V_27 -> V_144 = 1 ;
F_100 ( & V_27 -> V_134 ) ;
V_8 = F_93 ( V_27 , V_174 ) ;
if ( V_8 != V_173 ) {
if ( V_184 ) {
F_101 ( V_184 , 0 ) ;
F_102 ( V_184 ) ;
}
V_8 = F_93 ( V_27 , 1 ) ;
F_4 ( V_8 == 0 ) ;
}
}
void F_103 ( struct V_26 * V_27 )
{
if ( ! V_27 )
return;
F_104 ( V_27 , V_27 -> V_131 ) ;
F_105 ( & V_27 -> V_146 ) ;
F_31 ( V_27 ) ;
F_70 ( V_27 -> V_61 ) ;
F_4 ( F_106 ( & V_27 -> V_132 ) ) ;
F_71 ( V_27 ) ;
F_72 () ;
}
void F_107 ( struct V_26 * V_27 ,
struct V_183 * V_184 ,
int V_174 )
{
F_98 ( V_27 , V_184 , V_174 ) ;
F_103 ( V_27 ) ;
}
void F_108 ( struct V_26 * V_27 )
{
F_109 ( & V_27 -> V_135 ) ;
}
int F_110 ( struct V_26 * V_27 )
{
return F_111 ( & V_27 -> V_135 ) ;
}
void F_112 ( struct V_26 * V_27 )
{
if ( F_113 ( & V_27 -> V_135 , & V_27 -> V_134 ) ) {
F_114 ( & V_27 -> V_136 ) ;
F_100 ( & V_27 -> V_134 ) ;
}
}
void F_68 ( struct V_26 * V_27 , T_7 V_104 )
{
F_115 ( F_116 ( V_104 ) ) ;
F_4 ( F_106 ( & V_27 -> V_132 ) ) ;
F_117 ( & V_27 -> V_132 , F_118 ( V_104 ) ) ;
F_119 ( V_104 ) ;
F_120 ( F_116 ( V_104 ) ) ;
}
void F_104 ( struct V_26 * V_27 , T_7 V_104 )
{
F_115 ( F_116 ( V_104 ) ) ;
F_4 ( ! F_106 ( & V_27 -> V_132 ) ) ;
F_121 ( & V_27 -> V_132 ) ;
F_122 ( V_104 ) ;
F_120 ( F_116 ( V_104 ) ) ;
}
void F_123 ( struct V_26 * V_27 ,
T_7 V_104 )
{
F_4 ( ! F_106 ( & V_27 -> V_132 ) ) ;
F_4 ( F_124 ( F_116 ( V_104 ) ) ) ;
F_125 ( & V_27 -> V_132 , F_126 ( V_104 ) ) ;
}
void F_127 ( struct V_26 * V_27 ,
T_7 V_104 )
{
F_4 ( ! F_106 ( & V_27 -> V_132 ) ) ;
F_4 ( F_124 ( F_116 ( V_104 ) ) ) ;
F_125 ( & V_27 -> V_132 ,
F_118 ( V_104 ) ) ;
}
struct V_26 * F_128 ( T_7 V_104 )
{
F_4 ( F_124 ( F_116 ( V_104 ) ) ) ;
F_4 ( ! F_106 ( F_126 ( V_104 ) ) ) ;
return F_129 ( F_126 ( V_104 ) -> V_185 ,
struct V_26 , V_132 ) ;
}
static struct V_99 * F_130 ( void )
{
struct V_99 * V_29 ;
int V_111 ;
F_131 ( V_29 , V_186 , V_187 ) ;
if ( V_29 == NULL )
return NULL ;
F_62 ( & V_29 -> V_166 ) ;
F_62 ( & V_29 -> V_167 ) ;
F_62 ( & V_29 -> V_168 ) ;
for ( V_111 = 0 ; V_111 < V_188 ; V_111 ++ ) {
V_29 -> V_189 [ V_111 ] . V_190 = 0 ;
V_29 -> V_189 [ V_111 ] . V_191 = 1 << V_111 ;
V_29 -> V_189 [ V_111 ] . V_192 = NULL ;
}
F_64 ( & V_29 -> V_170 , 1 ) ;
F_63 ( & V_29 -> V_193 ) ;
F_132 ( & V_29 -> V_194 ) ;
F_133 ( & V_29 -> V_195 ) ;
F_115 ( & V_29 -> V_195 ) ;
return V_29 ;
}
struct V_99 *
F_134 ( struct V_26 * V_27 , struct V_99 * V_196 ,
const struct V_82 * V_65 , T_10 type , int V_197 )
{
struct V_97 * V_98 ;
struct V_99 * V_29 ;
struct V_30 V_31 ;
T_5 V_198 ;
int V_199 = 0 ;
F_4 ( V_27 != NULL ) ;
F_4 ( V_196 == NULL ) ;
F_4 ( V_27 -> V_61 != NULL ) ;
F_4 ( V_65 -> V_65 [ 0 ] != 0 ) ;
F_135 ( V_27 -> V_61 , ( void * ) V_65 , & V_31 , 0 ) ;
V_98 = F_136 ( V_27 -> V_61 , & V_31 , ( void * ) V_65 ) ;
if ( V_98 != NULL ) {
F_137 ( V_27 -> V_61 , & V_31 , 0 ) ;
V_29 = F_46 ( V_98 , struct V_99 , V_100 ) ;
if ( V_27 -> V_200 && V_27 -> V_200 -> V_201 ) {
F_115 ( & V_29 -> V_195 ) ;
F_120 ( & V_29 -> V_195 ) ;
}
if ( F_138 ( V_29 -> V_202 < 0 ) ) {
F_55 ( V_29 ) ;
V_29 = NULL ;
}
return V_29 ;
}
V_198 = F_139 ( & V_31 ) ;
F_137 ( V_27 -> V_61 , & V_31 , 0 ) ;
if ( V_197 == 0 )
return NULL ;
F_140 ( type >= V_203 && type < V_204 ,
L_43 , type ) ;
V_29 = F_130 () ;
if ( ! V_29 )
return NULL ;
V_29 -> V_205 = F_60 ( V_27 -> V_61 , & V_31 ) ;
V_29 -> V_101 = * V_65 ;
V_29 -> V_206 = type ;
V_29 -> V_207 = V_208 ;
F_141 ( V_27 -> V_61 , & V_31 , 1 ) ;
V_98 = ( V_198 == F_139 ( & V_31 ) ) ? NULL :
F_136 ( V_27 -> V_61 , & V_31 , ( void * ) V_65 ) ;
if ( V_98 != NULL ) {
F_137 ( V_27 -> V_61 , & V_31 , 1 ) ;
F_142 ( & V_29 -> V_194 ) ;
F_120 ( & V_29 -> V_195 ) ;
F_143 ( V_29 , V_186 , sizeof( * V_29 ) ) ;
V_29 = F_46 ( V_98 , struct V_99 , V_100 ) ;
if ( V_27 -> V_200 && V_27 -> V_200 -> V_201 ) {
F_115 ( & V_29 -> V_195 ) ;
F_120 ( & V_29 -> V_195 ) ;
}
if ( F_138 ( V_29 -> V_202 < 0 ) ) {
F_55 ( V_29 ) ;
V_29 = NULL ;
}
return V_29 ;
}
F_144 ( V_27 -> V_61 , & V_31 , & V_29 -> V_100 ) ;
if ( F_14 ( & V_31 ) == 1 )
V_199 = F_110 ( V_27 ) ;
F_137 ( V_27 -> V_61 , & V_31 , 1 ) ;
if ( V_27 -> V_200 && V_27 -> V_200 -> V_201 ) {
int V_8 ;
F_145 ( V_209 , 2 ) ;
V_8 = V_27 -> V_200 -> V_201 ( V_29 ) ;
if ( V_8 < 0 ) {
F_7 ( L_44 ,
V_27 -> V_129 -> V_210 , V_65 -> V_65 [ 0 ] ,
V_65 -> V_65 [ 1 ] , V_8 ) ;
if ( V_29 -> V_211 ) {
F_146 ( V_29 -> V_211 , V_29 -> V_202 ) ;
V_29 -> V_211 = NULL ;
}
V_29 -> V_202 = V_8 ;
F_120 ( & V_29 -> V_195 ) ;
F_55 ( V_29 ) ;
return NULL ;
}
}
F_120 ( & V_29 -> V_195 ) ;
if ( F_38 ( V_27 ) && V_199 == 1 ) {
F_115 ( F_116 ( V_7 ) ) ;
F_123 ( V_27 , V_7 ) ;
F_120 ( F_116 ( V_7 ) ) ;
}
return V_29 ;
}
struct V_99 * F_51 ( struct V_99 * V_29 )
{
F_4 ( V_29 != NULL ) ;
F_4 ( V_29 != V_212 ) ;
F_109 ( & V_29 -> V_170 ) ;
F_23 ( V_172 , L_45 , V_29 ,
F_90 ( & V_29 -> V_170 ) ) ;
return V_29 ;
}
static void F_147 ( struct V_30 * V_31 ,
struct V_99 * V_29 )
{
struct V_107 * V_108 = V_29 -> V_205 ;
if ( ! F_106 ( & V_29 -> V_166 ) ) {
F_91 ( V_171 , V_29 ) ;
F_148 () ;
}
if ( ! F_106 ( & V_29 -> V_167 ) ) {
F_91 ( V_171 , V_29 ) ;
F_148 () ;
}
if ( ! F_106 ( & V_29 -> V_168 ) ) {
F_91 ( V_171 , V_29 ) ;
F_148 () ;
}
F_149 ( V_108 -> V_128 -> V_61 ,
V_31 , & V_29 -> V_100 ) ;
F_142 ( & V_29 -> V_194 ) ;
if ( F_14 ( V_31 ) == 0 )
F_112 ( V_108 -> V_128 ) ;
}
int F_55 ( struct V_99 * V_29 )
{
struct V_26 * V_27 = F_74 ( V_29 ) ;
struct V_30 V_31 ;
F_150 ( & V_29 -> V_170 , 0 , V_213 ) ;
F_23 ( V_172 , L_46 ,
V_29 , F_90 ( & V_29 -> V_170 ) - 1 ) ;
F_151 ( V_27 -> V_61 , & V_29 -> V_101 , & V_31 ) ;
if ( F_152 ( V_27 -> V_61 , & V_31 , & V_29 -> V_170 ) ) {
F_147 ( & V_31 , V_29 ) ;
F_137 ( V_27 -> V_61 , & V_31 , 1 ) ;
if ( V_27 -> V_200 && V_27 -> V_200 -> V_214 )
V_27 -> V_200 -> V_214 ( V_29 ) ;
F_143 ( V_29 , V_186 , sizeof( * V_29 ) ) ;
return 1 ;
}
return 0 ;
}
int F_53 ( struct V_99 * V_29 )
{
struct V_26 * V_27 = F_74 ( V_29 ) ;
F_150 ( & V_29 -> V_170 , 0 , V_213 ) ;
F_23 ( V_172 , L_46 ,
V_29 , F_90 ( & V_29 -> V_170 ) - 1 ) ;
if ( F_153 ( & V_29 -> V_170 ) ) {
struct V_30 V_31 ;
F_151 ( F_74 ( V_29 ) -> V_61 ,
& V_29 -> V_101 , & V_31 ) ;
F_147 ( & V_31 , V_29 ) ;
F_137 ( V_27 -> V_61 , & V_31 , 1 ) ;
if ( V_27 -> V_200 && V_27 -> V_200 -> V_214 )
V_27 -> V_200 -> V_214 ( V_29 ) ;
F_143 ( V_29 , V_186 , sizeof( * V_29 ) ) ;
F_141 ( V_27 -> V_61 , & V_31 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_154 ( struct V_99 * V_29 , struct V_148 * V_215 ,
struct V_153 * V_154 )
{
F_155 ( V_29 ) ;
F_80 ( V_154 , L_47 ) ;
if ( V_154 -> V_156 & V_216 ) {
F_23 ( V_217 , L_48 ) ;
return;
}
F_4 ( F_106 ( & V_154 -> V_155 ) ) ;
F_156 ( & V_154 -> V_155 , V_215 ) ;
}
void F_157 ( struct V_153 * V_218 ,
struct V_153 * V_219 )
{
struct V_99 * V_29 = V_218 -> V_220 ;
F_155 ( V_29 ) ;
F_91 ( V_172 , V_29 ) ;
F_80 ( V_219 , L_49 , V_218 ) ;
if ( V_219 -> V_156 & V_216 ) {
F_23 ( V_217 , L_48 ) ;
goto V_221;
}
F_4 ( F_106 ( & V_219 -> V_155 ) ) ;
F_117 ( & V_219 -> V_155 , & V_218 -> V_155 ) ;
V_221: ;
}
void F_84 ( struct V_153 * V_154 )
{
int type = V_154 -> V_220 -> V_206 ;
F_155 ( V_154 -> V_220 ) ;
if ( type == V_222 || type == V_223 )
F_158 ( V_154 ) ;
else if ( type == V_224 )
F_159 ( V_154 ) ;
F_121 ( & V_154 -> V_155 ) ;
}
void F_160 ( struct V_99 * V_29 , struct V_225 * V_226 )
{
V_226 -> V_206 = V_29 -> V_206 ;
V_226 -> V_101 = V_29 -> V_101 ;
}
void F_2 ( T_7 V_104 , int V_227 )
{
struct V_148 * V_43 ;
if ( ! ( ( V_228 | V_171 ) & V_227 ) )
return;
F_115 ( F_116 ( V_104 ) ) ;
F_76 (tmp, ldlm_namespace_list(client)) {
struct V_26 * V_27 ;
V_27 = F_77 ( V_43 , struct V_26 , V_132 ) ;
F_161 ( V_227 , V_27 ) ;
}
F_120 ( F_116 ( V_104 ) ) ;
}
static int F_162 ( struct V_78 * V_79 , struct V_30 * V_31 ,
struct V_97 * V_98 , void * V_165 )
{
struct V_99 * V_29 = F_87 ( V_79 , V_98 ) ;
int V_227 = ( int ) ( unsigned long ) V_165 ;
F_75 ( V_29 ) ;
F_91 ( V_227 , V_29 ) ;
F_79 ( V_29 ) ;
return 0 ;
}
void F_161 ( int V_227 , struct V_26 * V_27 )
{
if ( ! ( ( V_228 | V_171 ) & V_227 ) )
return;
F_23 ( V_227 , L_50 ,
F_24 ( V_27 ) , F_90 ( & V_27 -> V_135 ) ,
F_38 ( V_27 ) ? L_51 : L_52 ) ;
if ( F_163 ( F_164 () , V_27 -> V_229 ) )
return;
F_92 ( V_27 -> V_61 ,
F_162 ,
( void * ) ( unsigned long ) V_227 ) ;
F_99 ( & V_27 -> V_134 ) ;
V_27 -> V_229 = F_165 ( 10 ) ;
F_100 ( & V_27 -> V_134 ) ;
}
void F_91 ( int V_227 , struct V_99 * V_29 )
{
struct V_153 * V_154 ;
unsigned int V_230 = 0 ;
F_166 ( V_85 == 4 ) ;
if ( ! ( ( V_228 | V_171 ) & V_227 ) )
return;
F_23 ( V_227 , L_53 V_169 L_54 ,
F_89 ( V_29 ) , V_29 , F_90 ( & V_29 -> V_170 ) ) ;
if ( ! F_106 ( & V_29 -> V_166 ) ) {
F_23 ( V_227 , L_55 ) ;
F_167 (lock, &res->lr_granted,
l_res_link) {
F_168 ( V_227 , V_154 , L_56 ) ;
if ( ! ( V_227 & V_231 ) &&
++ V_230 > V_13 ) {
F_23 ( V_227 , L_57 ,
V_230 ) ;
break;
}
}
}
if ( ! F_106 ( & V_29 -> V_167 ) ) {
F_23 ( V_227 , L_58 ) ;
F_169 (lock, &res->lr_converting, l_res_link)
F_168 ( V_227 , V_154 , L_56 ) ;
}
if ( ! F_106 ( & V_29 -> V_168 ) ) {
F_23 ( V_227 , L_59 ) ;
F_169 (lock, &res->lr_waiting, l_res_link)
F_168 ( V_227 , V_154 , L_56 ) ;
}
}
